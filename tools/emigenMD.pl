#!/usr/bin/perl
#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2006
#
#  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
#  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
#  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
#  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
#  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
#  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
#  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
#  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
#  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
#  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
#  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
#  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
#
#  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
#  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
#  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
#  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
#  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
#
#  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
#  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
#  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
#  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
#  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
#
#*****************************************************************************
#*
#* Filename:
#* ---------
#*   emiGenV7.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script will
#*       1. parse custom_MemoryDevice.h to get memory device type and part number
#*       2. read a excel file to get appropriate emi setting based on the part number
#*       3. based on the emi settings, generate flash_opt.h if not exist
#*       4. based on the emi settings, generate custom_EMI.c if not exist
#*       5. based on the emi settings, generate custom_EMI.h if not exist
#*       6. based on the emi settings, generate custom_flash.c if not exist
#*       7. based on the emi settings, generate custom_flash_norfdm5.c if not exist
#*
#* Author:
#* -------
#*   Claudia Lo    (mtk01876)
#*   JI Huang      (mtk01077)
#*   Sherman Wang  (mtk00590)
#*
#*============================================================================
#*             HISTORY
#* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*------------------------------------------------------------------------------
#* $Revision$
#* $Modtime$
#* $Log$
#* 
#* 10 18 2012 marvin.lin
#* [MOLY00004964] [MemoryStorage][Auto-Gen][EMI Gen/CFG Gen][Request For Design Change] support wifi-router load boot flow on WR8
#* .
#* 
#* 08 21 2012 marvin.lin
#* [MOLY00002372] [Need Patch][Build Error] WR8 build error for MT6280_E2_R7R8_HSPA(MP_VERSION)
#* .
#* 
#* 08 16 2012 marvin.lin
#* [MOLY00002196] [MemoryStorage][Auto-Gen][EMI Gen/CFG Gen][Request For Design Change] support MT6583 smart phone
#* .
#* 
#* 07 24 2012 marvin.lin
#* [MOLY00001098] [MemoryStorage][Auto-Gen][EMI Gen/CFG Gen][Request For Design Change] autogen support nand flash 8-bit ecc on MT6280
#* .
#*
#*
#*------------------------------------------------------------------------------
#* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*============================================================================
#****************************************************************************/
#****************************************************************************
# Included Modules
#****************************************************************************
print "os environment : $^O\n";
use strict;
if($^O eq "MSWin32")
{
require Win32::OLE;# qw(in with);
#require Win32::OLE::Const 'Microsoft Excel';
$Win32::OLE::Warn = 3;       
}
else
{
push @INC, "tools/perl";
require Spreadsheet::ParseExcel;
 # use Spreadsheet::ParseExcel;
}                         # die on errors...

my $EMIGEN_VERNO  = " V8.262";
                    # V8.262 , by Marvin  at 2012/10/18 , for MT6280 wifi router nfi driver change
                    # V8.260 , by Marvin  at 2012/08/16 , autogen support MT6583 
                    # V8.259 , by Marvin  at 2012/07/24 , autogen support nand flash 8-bit ecc
                    # V8.258 , by Marvin  at 2012/07/05 , Autogen support MT6280
                    # V8.254 , by Marvin  at 2012/06/08 , modify open MDL method for autogen on linux
                    # V8.249 , by Marvin  at 2012/04/30 , modify combo memory hw list data structure name
                    # V8.234 , by Marvin  at 2012/01/09 , check in MT6280 DVT
                    # V8.231 , by Marvin  at 2011/12/26 , EMIGEN support MT6255 combo memory
                    # V8.229 , by Marvin  at 2011/12/06 , modify emigen bug in emigensf.pl variable makefile_options define error
                    # V8.228 , by Marvin  at 2011/12/02 , EMIGEN support MT6255 on MAUI, 11B, 11AW1112SP2, 11BW1144SP
                    # V8.226 , by Marvin  at 2011/11/17 , add emi 156Mhz setting to work around for 6256 ORFS 600KHz fail 
                    # V8.227 , by Marvin  at 2011/11/24 , to fix the sanity fail that init_eco_version corrupt the EMI region code for 6921 on 11B
                    # V8.225 , by Marvin  at 2011/11/16 , to fix the emigen error for 6252D sip serialflash 
                    # V8.224 , by Marvin  at 2011/11/10 , supprot MT6276 L1 downgrade for memory device 32 or 16 bit
                    # V8.223 , by Marvin  at 2011/11/04 , remove the card DL + combo memory flash layout
                    # V8.222 , by Marvin  at 2011/11/02 , support new version perl rule
                    # V8.221 , by Marvin  at 2011/11/01 , modify custom_emi.c to fix the build error for 6921 on 11B 
                    # V8.220 , by Marvin  at 2011/10/31 , remove check demo project policy to avoid production release load build error
                    # V8.219 , by Marvin  at 2011/10/24 , modify custom_emi.c and custom_emi.h to support combo memory for 6921 on 11B & maui
                    # V8.218 , by Marvin  at 2011/10/13, modify custom_emi.c to match 11B hal rule
                    # V8.217 , by Marvin  at 2011/10/10 , to fix emigen re-sructure error
                    # V8.216 , by Marvin  at 2011/10/07 , emi sw work-around for 6236 BT issue.
                    # V8.215 , by Marvin  at 2011/10/05 , emigen support 6256 combo memory
                    # V8.214 , by Marvin  at 2011/09/22 , support 6252E sip serial flash size 32Mbit
                    # V8.213 , by Marvin  at 2011/09/20 , modify emi dynamicclockswitch return value
                    # V8.210 , by Marvin  at 2011/09/05 , add the dependency of the custom_featureconfig.h
                    # V8.209 , by Marvin  at 2011/09/02 , support to parse custom_featureconfig.h
                    # V8.208 , by Marvin  at 2011/08/31 , EMI GEN Re-structure and EMI GEN version update 
                    # V7.207 , by Marvin  at 2011/08/29 , to support the feature of psuedo sized block.
                    # V7.206 , by Claudia at 2011/08/15 , Modify SP custom_EMI_release.h EMI_EXTSRAM_SIZE template to sync with feature phones
                    # V7.205 , by Marvin at  2011/08/08 , modify custom_emi.c for supporting WQVGA of 6252
                    # V7.204 , by Marvin at  2011/08/01 , modify the custom_flash.c for FOTA + Card DL + combo memory feature support
                    # V7.203 , by Marvin at  2011/07/15 , modify the custom_flash.c for NOR FDM slim
                    # V7.202 , by Marvin at  2011/07/13 , modify the custom_sfi.c to fix build error for compile option UBL
                    # V7.201 , by Claudia at 2011/07/11 , Fix Combo Memory error for error-detecting EMMC_BOOTING
                    # V7.200 , by Marvin at  2011/07/11 , modify the FS address for FOTA backup storage
                    # V7.199 , by Marvin at  2011/07/11 , Modify custom_EMI.c to fix build error for compile option EMMC_BOOTING
                    # V7.198 , by Claudia at 2011/07/08 , Modify custom_EMI.c to fix build error when _EMI_NOR_CMD_NUM is 0
                    # V7.197 , by Claudia at 2011/07/08 , Remove __NOR_FULL_DRIVER__ option for BL re-structure
                    # V7.196 , by Claudia at 2011/07/07 , Support Combo Memory on all platforms
                    # V7.184 , by Claudia at 2011/05/17 , Support MT6921 Auto-Gen
                    # V7.183 , by Claudia at 2011/05/16 , Correct MT6236 DRAM init flow
                    # V7.150 , by Claudia at 2011/03/04 , To support Card DL
                    # V7.159 , by Claudia at 2011/02/21 , Modify custom_EMI.c template to fix MT6235E5 DCM conflict with sw-workaround issue
                    # V7.149 , by Claudia at 2011/01/21 , To generate the entire NOR flash geometry for SDS (Secure Data Storage) feature
                    # V7.195 , by Marvin  at 2011/07/06 , modify custom_flash.c template for bootloader re-organize
                    # V7.194 , by Marvin  at 2011/06/15 , modify custom_flash.c
                    # V7.193 , by Marvin  at 2011/06/15 , add pid to copy MDL file name, flash_opt.h template
                    # V7.192 , by Marvin  at 2011/06/14 , add output file owner name for BM to find correct file owner quickly
                    # V7.191 , by Marvin  at 2011/06/13 , Modify custom_SFI.c to remove include pwic.h to fix build error
                    # V7.190 , by Claudia at 2011/05/30 , Modify custom_EMI_release.h to include kal_general_types.h to fix build error
                    # V7.189 , by Claudia at 2011/05/30 , Support MT6252D SIP_SERIAL_FLASH_SIZE selection
                    # V7.188 , by Claudia at 2011/05/29 , Modify MT6276 custom_EMI.c for data training result and fix auto-tracking coding error
                    # V7.187 , by Claudia at 2011/05/29 , Remove 64Mb serial flash upper limit for MT6252 and MT6251
                    # V7.186 , by Claudia at 2011/05/26 , Modify custom_EMI.c to fix build error for EMMC_BOOTING
                    # V7.185 , by Claudia at 2011/05/26 , Modify custom_flash.c to fix build warnings
                    # V7.182 , by Claudia at 2011/05/13 , Modify custom_flash.c and flash_opt.h templates and add EMMC_BOOTING options to support eMMC Booting
                    # V7.181 , by Claudia at 2011/05/11 , Modify custom_EMI.c, custom_SFI.c, combo_sfi_config.h, and combo_sfi_defs.h templates to support MT6252 porting IC;  Modify MDL version from 10AW1108MP to 10AW1124MP
                    # V7.180 , by Claudia at 2011/05/10 , Modify MT6252 custom_EMI.c to correct pragma wrapping
                    # V7.179 , by Claudia at 2011/05/05 , Retrieve MTKSIP information from internal MDL as well, and skip internal MDL operation for customer release
                    # V7.178 , by Claudia at 2011/04/22 , Support EMI Gen for MT6573 (and future smart phone projects)
                    # V7.177 , by Claudia at 2011/04/18 , Support MT6276M MDL split with MT6276
                    # V7.176 , by Claudia at 2011/04/16 , Support MT6252 SIP PSRAM selection by makefile option SIP_RAM_SIZE
                    # V7.175 , by Claudia at 2011/04/11 , Auto-select highest EMI clock by available EMI settings in MDL on MT6276 when EMI_CLK is set as DEFAULT
                    # V7.173 , by Claudia at 2011/04/01 , Fix the issue that MDL copy will fail when load path contains '+'
                    # V7.172 , by Claudia at 2011/03/24 , Modify flash_opt.h template to tune FS size for SDS
                    # V7.171 , by Claudia at 2011/03/18 , Modify Lookup_SFI_setting_by_IDX_CLK_BB_REG to retrieve MT6252 SFI setting with old MDL format (with chip information in the field)
                    # V7.170 , by Claudia at 2011/03/18 , Remove dependency check for SFI files on platforms which do not support SFI
                    # V7.169 , by Claudia at 2011/03/15 , Refine MT6251 MDL to remove chip information and to move MT6251 from common internal MDL to a separate internal MDL for MT6251
                    # V7.168 , by Claudia at 2011/03/12 , Modify custom_EMI.c and custom_EMI.h template to fix MT6252 build error
                    # V7.167 , by Claudia at 2011/03/11 , Fix custom_MemoryDevice.h unable to recognize "#define option" format issue
                    # V7.166 , by Claudia at 2011/03/10 , Modify custom_EMI.c template to set EPLL by or operation to prevent DSS configurations set by BL from being overwritten
                    # V7.165 , by Claudia at 2011/03/08 , Modify custom_EMI.c and custom_EMI.h templates to rename MT6270 as MT6276M
                    # V7.164 , by Claudia at 2011/03/07 , Modify custom_SFI.c to support MT6251 Meta, and modify custom_EMI.h to fix MT6251 build error when no COMBO_MEMORY_ENTRY_COUNT is defined
                    # V7.163 , by Claudia at 2011/03/04 , Support EMI Gen for MT6276 (including Combo Memory)
                    # V7.162 , by Claudia at 2011/03/01 , Forbid MT6251 with serial flash larger than 64Mb
                    # V7.161 , by Claudia at 2011/02/25 , Change MDL to 10AW1108 and report error directly when MDL does not exist
                    # V7.160 , by Claudia at 2011/02/21 , Fix custom_SFI.c GFH declaration invalid format error
                    # V7.158 , by Claudia at 2011/02/18 , Fix incorrect EXTSRAM_SIZE issue when RAM size is larger than 128Mb in MDL
                    # V7.157 , by Claudia at 2011/02/18 , Support EMI Gen for MT6251 (including Combo Memory)
                    # V7.156 , by Claudia at 2011/02/17 , Correct MT6252 compile option and fix SFI DCM issue; correct custom_flash.c Card DL template
                    # V7.155 , by Claudia at 2011/02/15 , Change MDL to 10AW1108 version; generate entire flash to support Card DL; generate 0 instead of x to fix SFI build error; remove redundant codes; add extra checking and bug fix to support MT6252 MP
                    # V7.152 , by Claudia at 2011/02/07 , Generate flash ID under all cases to support Card DL ini gen
                    # V7.151 , by Claudia at 2011/01/27 , Allow RegionInfo to be compiled for COMBO_MEMORY_SUPPORT and SERIAL_FLASH to prevent cksydrv error
                    # V7.148 , by Claudia at 2011/01/20 , To support NOR Idle Sweep
                    # V7.147 , by Claudia at 2011/01/20 , Support Combo Memory and refine emiclean and emigen behavior in Gsm2.mak
                    # V6.146 , by Claudia at 2011/01/14 , Put emiclean control in EMI Gen script instead of Gsm2.mak and to support MANUAL-CHECKIN for custom release
                    # V6.145 , by Claudia at 2011/01/04 , Modify custom_EMI.c template to skip Enhanced SW DCM
                    # V6.144 , by Claudia at 2010/12/23 , Modify custom_EMI.c template to remove the include of pwic.h to prevent build error caused by HAL
                    # V6.143 , by Claudia at 2010/12/17 , Modfiy MT6236/MT6268 custom_EMI.c to extend delay after CAL_EN (1/5T DLL Enable)
                    # V6.142 , by Claudia at 2010/12/17 , Support RHR (Merge MAUIW1043OF_RHR to MAUI)
                    # V6.141 , by Claudia at 2010/12/10 , Support PROJECT_EXPECTED_RAM_LIMIT_NFB for NAND+DRAM projects to set RAM boundary
                    # V6.140 , by Claudia at 2010/12/10 , Remove MT6253D, and rename for chip ID
                    # V6.132 , by Claudia at 2010/12/02 , Modify custom_flash.c and flash_opt.h to add new compile options for Spansion VSR
                    # V6.129 , by Claudia at 2010/12/02 , Enhance NOR FDM 4.0 to support Spansion VSR flipping problem.
                    # V6.138 , by Claudia at 2010/11/26 , Modify custom_flash.c template to replace DWORD with kal_uint32 to prevent build error
                    # V6.137 , by Claudia at 2010/11/19 , Modify flash_opt.h template to force build error if the public drive size is not enough
                    # V6.136 , by Claudia at 2010/11/14 , Rename MT6253E/L as MT6252H/MT6252
                    # V6.135 , by Claudia at 2010/11/11 , Support EMI Gen for MT6516
                    # V6.134 , by Claudia at 2010/11/05 , Support EMI clock configurable to enable force MCP at 52MHz
                    # V6.133 , by Claudia at 2010/10/27 , Modify MT6253(D) ASYNC setting retrieval to support 52MHz-only MCP on MT6253(DV)
                    # V6.131 , by Claudia at 2010/10/18 , Modify MT6253E/L custom_EMI.c template to enable DMA soft mode grant count
                    # V6.130 , by Claudia at 2010/10/18 , Support RHR Add and add header files include on custom_EMI.c, custom_EMI.h, and custom_flash.c
                    # V6.128 , by Claudia at 2010/10/01 , Modify custom_flash.c template to add NAND init check to support X-DL for TotalBBM
                    # V6.127 , by Claudia at 2010/09/13 , Support MT6253E/L
                    # V6.126 , by Claudia at 2010/09/05 , Support Spansion VSR flash
                    # V6.125 , by Claudia at 2010/08/16 , Support MT6253DV MCP clock rate selection
                    # V6.124 , by Claudia at 2010/08/06 , Correct compile option ARM9_MMU to __ARM9_MMU__
                    # V6.122 , by Claudia at 2010/07/29 , Support MT6236(ADMUX)
                    # V6.121 , by Claudia at 2010/07/12 , Modify custom_flash.c and flash_opt.h templates to support Intel SIBLEY M18 ESB
                    # V6.120 , by Claudia at 2010/07/11 , Rename the MDL before opening it to prevent WIN32 error due to opening MDL with the same name at the same time
                    # V6.119 , by Claudia at 2010/07/09 , Modify custom_EMI_release.h template to remove #define on platforms other than MT6236(B) to prevent compile error in ADS
                    # V6.118 , by Claudia at 2010/07/07 , Modify custom_EMI.c template to include custom_EMI_release.h to prevent custom release EMI Gen error due to the opening of excel files
                    # V6.117 , by Claudia at 2010/06/18 , Modify custom_EMI.c template to include pll.h instead of init.h for init.h file split
                    # V6.116 , by Claudia at 2010/06/17 , Create dummy custom_flash_norfdm5.c and custom_EMI_release.h when NOR_FDM5 not defined and when platform is not MT6236
                    # V6.115 , by Claudia at 2010/06/17 , Modify flash_opt.h template to add __FS_PHOE_DRIVE_AVAILABLE__ options
                    # V6.114 , by Claudia at 2010/06/11 , Create custom_EMI_release.h to define memory device type compile option
                    # V6.113 , by Claudia at 2010/05/23 , Modify MT6236 DCM flow to improve power-saving
                    # V6.111 , by Claudia at 2010/04/14 , Modify flash_opt.h template to support Spansion NS_P series flash
                    # V6.110 , by Claudia at 2010/04/09 , Search for missing part numbers in the internal MDL for unsupported MCPs
                    # V6.109 , by Claudia at 2010/03/20 , Modify custom_EMI.h template for MT6253(D) RF Desense
                    # V6.108 , by Claudia at 2010/03/19 , Modify custom_flash.c template to support NOR raw disk
                    # V6.107 , by Claudia at 2010/03/17 , Modify custom_flash.c template to support totalBBM
                    # V6.106 , by Claudia at 2010/03/16 , Modify custom_flash.c and flash_opt.h template to support customized reserve block
                    # V6.105 , by Claudia at 2010/03/07 , Modify MEM Info EMI setting retrieval to get the setting by the EMI fast clock of each chip
                    # V6.104 , by Claudia at 2010/03/06 , Modify EMI Gen part number comparison rule to be exactly match as one single line of the Part Number field of MDL
                    # V6.103 , by Claudia at 2010/03/06 , Fix side effect of EMI Init flow change
                    # V6.102 , by Claudia at 2010/03/06 , Modify EMI Init flow to support different MCPs
                    # V6.101 , by Claudia at 2010/02/09 , Work around to tune FAT size for Toshiba MCP bad small blocks issue 
                    # V6.100 , by Claudia at 2010/01/25 , Add MEM_Info for MT6253
                    # V6.99 , by Claudia at 2010/01/23 , Support MT6236 and MT6253D Auto-Gen
                    # V6.98 , by Claudia at 2010/01/21 , Re-calculate NOR flash size and FAT base address for Toshiba MCP bad small blocks issue
                    # V6.97 , by Claudia at 2010/01/19 , Modify custom_flash.c template to allow FDM in BL
                    # V6.96 , by Claudia at 2010/01/05 , Support ARM11 Phase-in
                    # V6.95 , by Claudia at 2009/12/27 , EMI Initialization flow change on platfoms later than MT6253
                    # V6.94 , by Claudia at 2009/12/24 , Support MMAA
                    # V6.93 , by Claudia at 2009/12/20 , Add MT6253D
                    # V6.92 , by Claudia at 2009/12/01 , Modify custom_flash.c template to support NAND FDM5.0 Replace Block Count
                    # V6.91 , by Claudia at 2009/11/23 , Add NFB=BASIC case when calculating FAT offset for FOTA
                    # V6.90 , by Claudia at 2009/11/05 , Modify custom_flash.c template to avoid multi-instance compile error
                    # V6.89 , by JI at 2009/11/04 , MT6268 disable dqs enlarge feature 
                    # V6.88 , by JI at 2009/10/20 , Support MT6253 SYNC_ACCESS Pseudo RAM CRE 
                    # V6.87 , by Claudia at 2009/10/14 , Support NAND multi-instance
                    # V6.86 , by JI at 2009/08/05 , MT6235 BURST MODE Device Definition Missed Bug Fix
                    # V6.85 , by JI at 2009/08/04 , MT6253 add SAMSUNG SERIES SYNC type NOR_RAM_MCP support
                    # V6.84 , by JI at 2009/07/08 , MT6253 and INTEL_SIBLEY custom_EMI.c template
                    # V6.83 , by Claudia at 2009/06/16 , Modify MT6268 custom_EMI.c template
                    # V6.82 , by Claudia at 2009/06/05 , Retrieve MT6229/MT6230 information with platform as "MT6229 MT6230".
                    # V6.81 , by Claudia at 2009/06/05 , Modify flash_opt.h to remove NOR_BOOTING_NAND_BLOCK_SIZE and to set NAND_PARTITION_SECTORS as 0 when FOTA UPDATE_PACKAGE_ON_NAND
                    # V6.80 , by Claudia at 2009/05/27 , Modify custom_setEMI() in custom_EMI.c to forbid ultra-high requests
                    # V6.79 , by Claudia at 2009/05/22 , Modify custom_flash.c and flash_opt.h templates for FOTA Update Package on NAND
                    # V6.78 , by Claudia at 2009/05/20 , Modify DRAM initialization flow on MT6235/MT6238 to set PDN bit according to database
                    # V6.77 , by Claudia at 2009/05/19 , Modify custom_MemoryDevice.h, custom_flash.c, custom_flash_norfdm5.c, flash_opt.h, custom_fota.c to re-organize flash-related configurations
                    # V6.76 , by Claudia at 2009/05/07 , Modify DRAM initialization flow to remove power-down and auto-refresh
                    # V6.75 , by Claudia at 2009/04/08 , Remove FAT tuning for FOTA when FAT is already valid
                    # V6.74 , by Claudia at 2009/04/07 , Roll back temp solution to turn on FOTA for CMCC projects
                    # V6.73 , by Claudia at 2009/04/03 , Remove MCU Data prefetch buffer related codes on MT6268
                    # V6.72 , by Claudia at 2009/04/02 , Turn on FOTA when OPTR_SPEC is set to CMCC_0202_SEGA(_TECH) or CMCC_0202_SEGC(_TECH)
                    # V6.71 , by Claudia at 2009/03/25 , Tune FAT and Partition Sector settings automatically when FOTA is turned on
                    # V6.70 , by Claudia at 2009/03/25 , Modify EMI Gen V5 to support MT6230 for part number change
                    # V6.69 , by Claudia at 2009/03/19 , Use split_addr instead of split_emi for EMI Address and add MT6268 check for MT6268-specific registers
                    # V6.68 , by Claudia at 2009/03/16 , Support MT6223+INTEL_SIBLEY device templates
                    # V6.67 , by Claudia at 2009/03/13 , EMI Gen script Enhancement due to Device Excel data base extended for MT6253/MT6268
                    # V5.66 , by Claudia at 2009/03/06 , Add a new API custom_get_NORFLASH_Size in custom_flash.c for boot-loader
                    # V5.65 , by Claudia at 2009/01/14 , Modify FAT offset calculation when FOTA is turned on
                    # V5.64 , by Claudia at 2008/12/31 , Remove MT6205B
                    # V5.63 , by Claudia at 2008/12/30 , Remove LCSB
                    # V5.62 , by Claudia at 2008/12/25 , Remove FOTA_PROPRIETARY
                    # V5.61 , by Claudia at 2008/12/10 , Refine compile error messages.
                    # V5.60 , by Claudia at 2008/12/10 , Modify flash_opt.h template for new NOR flash devices
                    # V5.59 , by Claudia at 2008/12/02 , Modify flash_opt.h template to fix Spansion tESL and tERS issue
                    # V5.58 , by Claudia at 2008/11/14 , Add a new category in flash_opt.h for Spansion WSP
                    # V5.57 , by Claudia at 2008/10/28 , Fix NOR RDM5.0 FAT and small block judgement error
                    # V5.56 , by Claudia at 2008/10/22 , Revise MEMORY_DEVICE_TYPE and NAND_FLASH_BOOTING consistency check notification
                    # V5.55 , by Claudia at 2008/10/15 , Support FOTA+NFB Auto-Gen
                    # V5.54 , by Claudia at 2008/10/09 , Check MEMORY_DEVICE_TYPE and NAND_FLASH_BOOTING consistency in EMI Gen
                    # V5.53 , by Claudia at 2008/09/12 , Add file name and fline number information and unify all auto-gen error messages
                    # V5.52 , by Claudia at 2008/09/11 , To support ESB on MT6235
                    # V5.51 , by Claudia at 2008/08/28 , Modify custom_flash.c temlate to support FOTA on ARM9
                    # V5.50 , by Claudia at 2008/08/22 , To support FOTA on ARM9
                    # V5.49 , by Claudia at 2008/08/22 , Modify custom_EMI.c template for MT6235 NOR+PSRAM BURST MODE to remove EMI_CONE/EMI_CONF
                    # V5.48 , by Claudia at 2008/08/21 , Unify Auto-Gen error messages and modify EMI Gen part number parsing rules
                    # V5.47 , by Claudia at 2008/08/14 , Support FOTA Auto-Gen
                    # V5.46 , by Claudia at 2008/07/30 , Modify custom_EMI.c template to fix EMI_GENA and EMI_GEND issue on MT6235/MT6238 NFB
                    # V5.45 , by Claudia at 2008/07/24 , Align MT6238 info retrieval behavior with memory device database excel columns
                    # V5.44 , by Claudia at 2008/07/16 , Modify MT6235 DCM flow to fix UART data error issue
                    # V5.43 , by Claudia at 2008/07/16 , Modify custom_flash.c template for FOTA bug fix
                    # V5.42 , by Claudia at 2008/07/16 , Modify custom_flash.c template for FOTA bug fix on boot-loader
                    # V5.41 , by Claudia at 2008/07/15 , Modify custom_flash.c template for FOTA bug fix on boot-loader
                    # V5.40 , by Claudia at 2008/07/11 , Modify custom_flash.c template for FOTA
                    # V5.39 , by Claudia at 2008/07/10 , Modify custom_EMI.c template for EMI_GENA bit-clear issue
                    # V5.38 , by Claudia at 2008/06/13 , Modify custom_flash.c template to support NFB MBA
                    # V5.37 , by Claudia at 2008/06/11 , Set PARTITION_SIZE to 0 when NAND_FLASH_BOOTING and SYSTEM_DRIVE_ON_NAND are not defined
                    # V5.36 , by Claudia at 2008/06/10 , Remove page mode settings when ASYNC_ACCESS is selected
                    # V5.35 , by Claudia at 2008/06/02 , Modify custom_EMI.c template to adjust PMU output voltage by calling pmic_adpt_init() on MT6235/MT6238
                    # V5.34 , by Claudia at 2008/05/29 , Modify EMI Gen to change #if 0 patterns to comments so that they will not be removed from custom release
                    # V5.33 , by Claudia at 2008/05/23 , Modify flash_opt.h template so that when unsupported flash is used for ESB, compile error will occur
                    # V5.32 , by Claudia at 2008/05/22 , Modify DCM templates for MT6235/MT6238
                    # V5.31 , by Claudia at 2008/05/22 , Modify NOR_BLOCK_SIZE to be the largest block size in FAT
                    # V5.30 , by Claudia at 2008/05/22 , Modify MT6235 custom_setEMI template for E4
                    # V5.29 , by Claudia at 2008/05/19 , Modify MT6235/MT6238 DCM templates
                    # V5.28 , by Claudia at 2008/05/14 , Add MT6235B/MT6239 for EMI Info
                    # V5.27 , by Claudia at 2008/05/12 , Modify RegionInfo/BankInfo/BlockInfo patterh to { , } (spaces before and after , allowed)
                    # V5.26 , by Claudia at 2008/05/12 , Modify EMI Gen so that RegionInfo starts from FAT base address.
                    # V5.25 , by Claudia at 2008/04/23 , Generate part number and flash geometry information in custom_EMI.h and flash_opt.h for Scatter Gen
                    # V5.24 , by Claudia at 2008/04/02 , Erase queue size is either 5 (default) or according to user-setting
                    # V5.23 , by Claudia at 2008/03/28 , Add EMI Info for custom_EMI.c and custom_EMI.h
                    # V5.22 , by Claudia at 2008/03/24 , Fix PROJECT_EXPECTED_CODE_LIMIT errors and force erase queue size to be 3 when ALLOCATED_FAT_SPACE is set
                    # V5.21 , by Claudia at 2008/03/19 , Modify custom_flash.c template for ESB RAM shrink
                    # V5.20 , by Claudia at 2008/03/19 , FLASH_BASE_ADDRESS/ALLOCATED_FAT_SIZE should be defined when __FS_SYSDRV_ON_NAND__
                    # V5.19 , by Claudia at 2008/03/18 , region_info should align with FAT size setting by customer
                    # V5.18 , by Claudia at 2008/03/12 , Modify EMI Gen to split EMI/flash
                    # V5.17 , by Claudia at 2008/03/12 , Modify check mechanism when both EXPECTED_CODE_SIZE and EXPECTED_FAT_SIZE are set
                    # V5.16 , by Claudia at 2008/02/22 , Device Excel data base extended for MT6235/MT6238
my $DebugPrint    = 0; # 1 for debug; 0 for non-debug

my $BOOL_EMI_CLEAN            = $ARGV[0];
my $CUSTOM_MEMORY_DEVICE_HDR  = $ARGV[1];
my $THEMF                     = $ARGV[2];
my $BOOL_MD_INFO              = $ARGV[3];
my $INSIDE_MTK                = $ARGV[4];
my $MDL_BACKUP_LOAD_PATH      = $ARGV[5];
print "ori load path:$MDL_BACKUP_LOAD_PATH\n";
my $CUSTOM_FEATURE_CONFIG_HDR = $CUSTOM_MEMORY_DEVICE_HDR;
$CUSTOM_FEATURE_CONFIG_HDR =~ s/custom_MemoryDevice/custom_FeatureConfig/;

print "custom memory device:$CUSTOM_MEMORY_DEVICE_HDR  makefile:$THEMF inside_mtk : $INSIDE_MTK\n";

# to align error message file name format
$CUSTOM_MEMORY_DEVICE_HDR =~ s/^.\\|^\\//;
$THEMF                    =~ s/^.\\|^\\//;
#print "$BOOL_EMI_CLEAN  $CUSTOM_MEMORY_DEVICE_HDR  $THEMF\n";
# the following parameters come from $CUSTOM_MEMORY_DEVICE_HDR
my $IDX_COUNT = 3;  # default index count is 3
my %PART_NUMBER;
my $MEMORY_DEVICE_TYPE;
my $MAX_COMBO_MEM_ENTRY_COUNT = 20;  # this needs to be defined because EMI Gen needs to know how many data structures need to be allocated
my $COMBO_SIP_ENTRY_COUNT = 0;  # work-around for MT6252 SIP
my $FLASH_ACCESS_TYPE;
my $RAM_ACCESS_TYPE;
my $EMI_CLK;
my $SFI_CLK;
my $NOR_FLASH_BASE_ADDRESS_VAL;
my $NOR_ALLOCATED_FAT_SPACE_VAL;
my $LPSDRAM_CHIP_SELECT = 0xFF;
my $PROJECT_EXPECTED_RAM_LIMIT;
my $PROJECT_EXPECTED_CODE_LIMIT;
my $PROJECT_EXPECTED_RAM_LIMIT_NFB;
my $SNOR_ERASE_QUEUE_SIZE;
my $NOR_SYSTEM_DRIVE_RESERVED_BLOCK;
my %MEM_DEV_LIST_INFO;
my %MEM_DEV_LIST_INDEX;
my @MCP_LIST;  # list of PART_NUMBER hash references
my @MDL_INFO_LIST;  # list of MEM_DEV_LIST_INFO has references
my %COMM_MDL_INFO;  # common MDL info, obtained from MDL_INFO_LIST.
my @REGION_INFO_LIST;  # extracted list of Region Info of all memory devices
my @BANK_INFO_LIST;  # extracted list of Bank Info of all memory devices
my @BLOCK_INFO_LIST;  # extracted list of Block Info of all memory devices
my %MAKEFILE_OPTIONS; #list of makefile option
my %CUSTOM_MEM_DEV_OPTIONS;  #list of custom_memory_device option
my $MEMORY_DEVICE_LIST_XLS;  #CORRECT MDL FILE 
my $MEMORY_DEVICE_LIST_INT_XLS; #INTERNAL MDL FILE
my $MEMORY_DEVICE_LIST_XLS_E;
my $nor_block_size;
my %CUSTOM_FEATURE_CFG_OPTIONS;
my $OS_ENV = $^O;

# locations of output EMI settings
my $CUSTOM_EMI_H           = $CUSTOM_MEMORY_DEVICE_HDR;
my $CUSTOM_EMI_INFO_H      = $CUSTOM_MEMORY_DEVICE_HDR;
my $CUSTOM_EMI_RELEASE_H   = $CUSTOM_MEMORY_DEVICE_HDR;
my $CUSTOM_EMI_C           = $CUSTOM_MEMORY_DEVICE_HDR;
my $CUSTOM_SFI_H           = $CUSTOM_MEMORY_DEVICE_HDR;
my $CUSTOM_FLASH_H         = $CUSTOM_MEMORY_DEVICE_HDR;
my $FLASH_OPT_GEN_H        = $CUSTOM_MEMORY_DEVICE_HDR;
my $CUSTOM_FLASH_NORFDM5_H = $CUSTOM_MEMORY_DEVICE_HDR;
my $COMBO_FLASH_CONFIG_H   = $CUSTOM_MEMORY_DEVICE_HDR;
my $COMBO_FLASH_ID_H       = $CUSTOM_MEMORY_DEVICE_HDR;
my $COMBO_SFI_CONFIG_H     = $CUSTOM_MEMORY_DEVICE_HDR;
my $COMBO_SFI_DEFS_H       = $CUSTOM_MEMORY_DEVICE_HDR;
my $CUSTOM_SFI_CLOCK_DEFS_H       = $CUSTOM_MEMORY_DEVICE_HDR;

#if($^O eq "MSWin32")
#{
#	  $CUSTOM_EMI_H              =~ s/\\custom_MemoryDevice\.h$/\\custom_EMI\.h/i;
#    $CUSTOM_EMI_INFO_H         =~ s/\\custom_MemoryDevice\.h$/\\custom_EMI_INFO\.h/i;
#    $CUSTOM_EMI_RELEASE_H      =~ s/\\custom_MemoryDevice\.h$/\\custom_EMI_release\.h/i;
#    $CUSTOM_EMI_C              =~ s/\\custom_MemoryDevice\.h$/\\custom_EMI\.c/i;
#    $CUSTOM_SFI_H              =~ s/\\custom_MemoryDevice\.h$/\\custom_SFI\.h/i;
#    $CUSTOM_FLASH_H            =~ s/\\custom_MemoryDevice\.h$/\\custom_flash\.h/i;
#    $FLASH_OPT_GEN_H           =~ s/\\custom_MemoryDevice\.h$/\\flash_opt_gen\.h/i;
#    $CUSTOM_FLASH_NORFDM5_H    =~ s/\\custom_MemoryDevice\.h$/\\custom_flash_norfdm5\.h/i;
#    $COMBO_FLASH_CONFIG_H      =~ s/\\custom_MemoryDevice\.h$/\\combo_flash_config\.h/i;
#    $COMBO_FLASH_ID_H          =~ s/\\custom_MemoryDevice\.h$/\\combo_flash_id\.h/i;
#    $COMBO_SFI_CONFIG_H        =~ s/\\custom_MemoryDevice\.h$/\\combo_sfi_config\.h/i;
#    $COMBO_SFI_DEFS_H          =~ s/\\custom_MemoryDevice\.h$/\\combo_sfi_defs\.h/i;
#    $CUSTOM_SFI_CLOCK_DEFS_H   =~ s/\\custom_MemoryDevice\.h$/\\custom_sfi_clock\.h/i;
#}
#else
#{
	  $CUSTOM_EMI_H           =~ s/\/custom_MemoryDevice\.h$/\/custom_EMI\.h/i;
    $CUSTOM_EMI_INFO_H         =~ s/\/custom_MemoryDevice\.h$/\/custom_EMI_INFO\.h/i;
    $CUSTOM_EMI_RELEASE_H   =~ s/\/custom_MemoryDevice\.h$/\/custom_EMI_release\.h/i;
    $CUSTOM_EMI_C           =~ s/\/custom_MemoryDevice\.h$/\/custom_EMI\.c/i;
    $CUSTOM_SFI_H           =~ s/\/custom_MemoryDevice\.h$/\/custom_SFI\.h/i;
    $CUSTOM_FLASH_H         =~ s/\/custom_MemoryDevice\.h$/\/custom_flash\.h/i;
    $FLASH_OPT_GEN_H            =~ s/\/custom_MemoryDevice\.h$/\/flash_opt_gen\.h/i;
    $CUSTOM_FLASH_NORFDM5_H =~ s/\/custom_MemoryDevice\.h$/\/custom_flash_norfdm5\.h/i;
    $COMBO_FLASH_CONFIG_H   =~ s/\/custom_MemoryDevice\.h$/\/combo_flash_config\.h/i;
    $COMBO_FLASH_ID_H       =~ s/\/custom_MemoryDevice\.h$/\/combo_flash_id\.h/i;
    $COMBO_SFI_CONFIG_H     =~ s/\/custom_MemoryDevice\.h$/\/combo_sfi_config\.h/i;
    $COMBO_SFI_DEFS_H       =~ s/\/custom_MemoryDevice\.h$/\/combo_sfi_defs\.h/i;
    $CUSTOM_SFI_CLOCK_DEFS_H   =~ s/\/custom_MemoryDevice\.h$/\/custom_sfi_clock\.h/i;
#}

print "test : $CUSTOM_EMI_H, $CUSTOM_EMI_INFO_H, $CUSTOM_EMI_RELEASE_H, $CUSTOM_EMI_C, $CUSTOM_SFI_H, $CUSTOM_FLASH_H, $FLASH_OPT_GEN_H, $CUSTOM_FLASH_NORFDM5_H, $COMBO_FLASH_CONFIG_H, $COMBO_FLASH_ID_H, $COMBO_SFI_CONFIG_H, $COMBO_SFI_DEFS_H\n";
# output file owner
my $CUSTOM_EMI_H_OWNER           = "CM Huang(mtk00582)   ";
my $CUSTOM_EMI_INFO_H_OWNER      = "CM Huang(mtk00582)   ";
my $CUSTOM_EMI_RELEASE_H_OWNER   = "CM Huang(mtk00582)   ";
my $CUSTOM_EMI_C_OWNER           = "CM Huang(mtk00582)   ";
my $CUSTOM_SFI_H_OWNER           = "Chun-Hung Wu(mtk03818)   ";
my $CUSTOM_FLASH_H_OWNER         = "Chia-Ling Ko(mtk02711)   ";
my $FLASH_OPT_GEN_H_OWNER        = "Chia-Ling Ko(mtk02711)   ";
my $CUSTOM_FLASH_NORFDM5_H_OWNER = "Chia-Ling Ko(mtk02711)   ";
my $COMBO_FLASH_CONFIG_H_OWNER   = "Chun-Hung Wu(mtk03818)   ";
my $COMBO_FLASH_ID_H_OWNER       = "Chun-Hung Wu(mtk03818)   ";
my $COMBO_SFI_CONFIG_H_OWNER     = "Chun-Hung Wu(mtk03818)   ";
my $COMBO_SFI_DEFS_H_OWNER       = "Chun-Hung Wu(mtk03818)   ";

require "tools/emigenemi.pl";
require "tools/emigenflash.pl";
require "tools/emigenSF.pl";

#****************************************************************************
# PLATFORM EMI support matrix
#****************************************************************************
my %BBtbl_EMI_NEW_DESIGN =
   (
        'MT6256'  => 1,
        'MT6255'  => 1,
        'MT6280'  => 1,
   );
#****************************************************************************
# parse makefile
#****************************************************************************
&Parse_Makefile($THEMF,\%MAKEFILE_OPTIONS);
#****************************************************************************
# find the correct EMI database
#****************************************************************************
&Find_MDL(\%MAKEFILE_OPTIONS, \$MEMORY_DEVICE_LIST_XLS, \$MEMORY_DEVICE_LIST_INT_XLS);
#****************************************************************************
# emiclean
#****************************************************************************
if ($BOOL_EMI_CLEAN eq 'TRUE')
{
	  
    &dependency_check($CUSTOM_EMI_H, "TRUE", "tools/emiGenMD.pl", "tools/emiGenSP.pl", "tools/emigenemi.pl", "tools/emigenflash.pl", "tools/emigenSF.pl", $THEMF, $CUSTOM_MEMORY_DEVICE_HDR, $MEMORY_DEVICE_LIST_XLS, $MEMORY_DEVICE_LIST_INT_XLS, $CUSTOM_FEATURE_CONFIG_HDR);
    &dependency_check($CUSTOM_EMI_RELEASE_H, "TRUE", "tools/emiGenMD.pl", "tools/emiGenSP.pl", "tools/emigenemi.pl", "tools/emigenflash.pl", "tools/emigenSF.pl", $THEMF, $CUSTOM_MEMORY_DEVICE_HDR, $MEMORY_DEVICE_LIST_XLS, $MEMORY_DEVICE_LIST_INT_XLS, $CUSTOM_FEATURE_CONFIG_HDR);
    if($BBtbl_EMI_NEW_DESIGN{$MAKEFILE_OPTIONS{'platform'}} == 1){
    	   &dependency_check($CUSTOM_EMI_INFO_H, "TRUE", "tools/emiGenMD.pl", "tools/emiGenSP.pl", "tools/emigenemi.pl", "tools/emigenflash.pl", "tools/emigenSF.pl", $THEMF, $CUSTOM_MEMORY_DEVICE_HDR, $MEMORY_DEVICE_LIST_XLS, $MEMORY_DEVICE_LIST_INT_XLS, $CUSTOM_FEATURE_CONFIG_HDR);
    	  }
    else{
    		 &dependency_check($CUSTOM_EMI_C, "TRUE", "tools/emiGenMD.pl", "tools/emiGenSP.pl", "tools/emigenemi.pl", "tools/emigenflash.pl", "tools/emigenSF.pl", $THEMF, $CUSTOM_MEMORY_DEVICE_HDR, $MEMORY_DEVICE_LIST_XLS, $MEMORY_DEVICE_LIST_INT_XLS, $CUSTOM_FEATURE_CONFIG_HDR);
    		}
    &dependency_check($CUSTOM_SFI_H, "TRUE", "tools/emiGenMD.pl", "tools/emiGenSP.pl", "tools/emigenemi.pl", "tools/emigen_flash.pl", "tools/emigenSF.pl", $THEMF, $CUSTOM_MEMORY_DEVICE_HDR, $MEMORY_DEVICE_LIST_XLS, $MEMORY_DEVICE_LIST_INT_XLS, $CUSTOM_FEATURE_CONFIG_HDR);
    &dependency_check($CUSTOM_FLASH_H, "TRUE", "tools/emiGenMD.pl", "tools/emiGenSP.pl", "tools/emigenemi.pl", "tools/emigenflash.pl", "tools/emigenSF.pl", $THEMF, $CUSTOM_MEMORY_DEVICE_HDR, $MEMORY_DEVICE_LIST_XLS, $MEMORY_DEVICE_LIST_INT_XLS, $CUSTOM_FEATURE_CONFIG_HDR);
    &dependency_check($FLASH_OPT_GEN_H, "TRUE", "tools/emiGenMD.pl", "tools/emiGenSP.pl", "tools/emigenemi.pl", "tools/emigenflash.pl", "tools/emigenSF.pl", $THEMF, $CUSTOM_MEMORY_DEVICE_HDR, $MEMORY_DEVICE_LIST_XLS, $MEMORY_DEVICE_LIST_INT_XLS, $CUSTOM_FEATURE_CONFIG_HDR);
    &dependency_check($CUSTOM_FLASH_NORFDM5_H, "TRUE", "tools/emiGenMD.pl", "tools/emiGenSP.pl", "tools/emigenemi.pl", "tools/emigenflash.pl", "tools/emigenSF.pl", $THEMF, $CUSTOM_MEMORY_DEVICE_HDR, $MEMORY_DEVICE_LIST_XLS, $MEMORY_DEVICE_LIST_INT_XLS, $CUSTOM_FEATURE_CONFIG_HDR);
    &dependency_check($COMBO_FLASH_CONFIG_H, "TRUE", "tools/emiGenMD.pl", "tools/emiGenSP.pl", "tools/emigenemi.pl", "tools/emigenflash.pl", "tools/emigenSF.pl", $THEMF, $CUSTOM_MEMORY_DEVICE_HDR, $MEMORY_DEVICE_LIST_XLS, $MEMORY_DEVICE_LIST_INT_XLS, $CUSTOM_FEATURE_CONFIG_HDR);
    &dependency_check($COMBO_FLASH_ID_H, "TRUE", "tools/emiGenMD.pl", "tools/emiGenSP.pl", "tools/emigenemi.pl", "tools/emigenflash.pl", "tools/emigenSF.pl", $THEMF, $CUSTOM_MEMORY_DEVICE_HDR, $MEMORY_DEVICE_LIST_XLS, $MEMORY_DEVICE_LIST_INT_XLS, $CUSTOM_FEATURE_CONFIG_HDR);
    &dependency_check($COMBO_SFI_CONFIG_H, "TRUE", "tools/emiGenMD.pl", "tools/emiGenSP.pl", "tools/emigenemi.pl", "tools/emigenflash.pl", "tools/emigenSF.pl", $THEMF, $CUSTOM_MEMORY_DEVICE_HDR, $MEMORY_DEVICE_LIST_XLS, $MEMORY_DEVICE_LIST_INT_XLS, $CUSTOM_FEATURE_CONFIG_HDR);
    &dependency_check($COMBO_SFI_DEFS_H, "TRUE", "tools/emiGenMD.pl", "tools/emiGenSP.pl", "tools/emigenemi.pl", "tools/emigenflash.pl", "tools/emigenSF.pl", $THEMF, $CUSTOM_MEMORY_DEVICE_HDR, $MEMORY_DEVICE_LIST_XLS, $MEMORY_DEVICE_LIST_INT_XLS, $CUSTOM_FEATURE_CONFIG_HDR);
    exit;
}

#****************************************************************************
# PLATFORM EMI support matrix
#****************************************************************************
my %BBtbl_SYNC_ACCESS = 
    (       
        'MT6268T' => 1,
        'MT6223'  => 1,
        'MT6223P' => 1,
        'MT6223D' => 1,
        'MT6227D' => 1,
        'MT6226D' => 1,
        'MT6235'  => 1,
        'MT6235B' => 1,
        'MT6253'  => 1,
        'MT6236'  => 1,
        'MT6236B' => 1,
        'MT6921'  => 1,
        'MT6252H' => 1,
        'MT6252'  => 1,
        'MT6255'  => 1,
    );
my %BBtbl_LPSDRAM = 
    (       
        'MT6225'  => 1,
        'MT6235'  => 1,
        'MT6235B' => 1,
        'MT6238'  => 1,
        'MT6239'  => 1,
        'MT6268'  => 1,
        'MT6236'  => 1,
        'MT6236B' => 1,
        'MT6276'  => 1,
        'MT6256'  => 1,
        'MT6255'  => 1,
        'MT6280'  => 1,
    );
my %BBtbl_SERIALFLASH = 
    (       
        'MT6252'  => 1,
        'MT6251'  => 1,
        'MT6255'  => 1,
        'MT6280'  => 1,
    );
my %BBtbl_EMI_FAST_CLK = 
    (       
        'MT6229'  => 104,
        'MT6268T' => 104,
        'MT6223'  => 52,
        'MT6223P' => 52,
        'MT6223D' => 52,
        'MT6235'  => 104,
        'MT6235B' => 104,
        'MT6238'  => 104,
        'MT6239'  => 104,
        'MT6253'  => 104,
        'MT6236'  => 104,
        'MT6236B' => 104,
        'MT6921'  => 104,
        'MT6268'  => 122.88,
        'MT6252H' => 104,
        'MT6252'  => 104,
        'MT6276'  => 200,
        'MT6256'  => 200,
        'MT6255'  => 200,
        'MT6280'  => 200,
    );
my %BBtbl_EMI_SLOW_CLK = 
    (       
        'MT6229'  => 13,
        'MT6268T' => 13,
        'MT6223'  => 13,
        'MT6223P' => 13,
        'MT6223D' => 13,
        'MT6235'  => 13,
        'MT6235B' => 13,
        'MT6238'  => 13,
        'MT6239'  => 13,
        'MT6253'  => 13,
        'MT6236'  => 13,
        'MT6236B' => 13,
        'MT6921'  => 13,
        'MT6268'  => 15.36,
        'MT6252H' => 13,
        'MT6252'  => 13,
        'MT6276'  => 166,
        'MT6256'  => 166,
        'MT6255'  => 166,
        'MT6280'  => 166,
    );
my %BBtbl_SFI_FAST_CLK = 
    (       
        'MT6251'  => 78,
        'MT6252'  => 104,
        'MT6255'  => 78,
    );
my %BBtbl_SFI_SLOW_CLK = 
    (       
        'MT6251'  => 13,
        'MT6252'  => 13,
        'MT6255'  => 13,
    );

if($BOOL_MD_INFO  eq 'TRUE')
{
	print "emigen should not enter this routine\n";
&Parse_Memory_Device(\%MAKEFILE_OPTIONS,\%PART_NUMBER,\$LPSDRAM_CHIP_SELECT,\%CUSTOM_MEM_DEV_OPTIONS, \@MCP_LIST);
&Parse_MDL(\%MAKEFILE_OPTIONS,\%CUSTOM_MEM_DEV_OPTIONS,\@MDL_INFO_LIST,\$MEMORY_DEVICE_LIST_XLS, \$MEMORY_DEVICE_LIST_INT_XLS);
	 #****************************************************************************
# check consistency among FEATURE, MEMORY_DEVICE_TYPE, PLATFORM, MCU_CLOCK and MemoryDeviceList data
#****************************************************************************
my $emi_clk_config = $BBtbl_EMI_FAST_CLK{$MAKEFILE_OPTIONS{'platform'}};
my $sfi_clk_config = $BBtbl_SFI_FAST_CLK{$MAKEFILE_OPTIONS{'platform'}};
&Decide_MDClock(\%MAKEFILE_OPTIONS,\%CUSTOM_MEM_DEV_OPTIONS, $LPSDRAM_CHIP_SELECT);


#****************************************************************************
# get common MDL information from a list of MDL information for Combo Memory
#****************************************************************************
&get_common_MDL_info(\@MDL_INFO_LIST, \%CUSTOM_MEM_DEV_OPTIONS, \%COMM_MDL_INFO,\%MAKEFILE_OPTIONS, $LPSDRAM_CHIP_SELECT, $CUSTOM_MEMORY_DEVICE_HDR);
&query_MD_INFO(\%MAKEFILE_OPTIONS,\%CUSTOM_MEM_DEV_OPTIONS,\%COMM_MDL_INFO);
   if ($DebugPrint == 1)
  {
    print "COMM_MDL_INFO: Flash Size = $COMM_MDL_INFO{0}->{'Flash Size'}, NAND Block Size(KB) = $COMM_MDL_INFO{0}->{'NAND Block Size(KB)'}, Small Block Start = $COMM_MDL_INFO{0}->{'Small Block Start'}, Default FAT Base = $COMM_MDL_INFO{0}->{'Default FAT Base'}, Default FAT Size = $COMM_MDL_INFO{0}->{'Default FAT Size'}, RAM \"Size (Mb)\" = $COMM_MDL_INFO{1}->{'Size (Mb)'}, \"CS0 ADMUX\" = $COMM_MDL_INFO{0}->{'ADMUX'}, \"CS1 ADMUX\" = $COMM_MDL_INFO{1}->{'ADMUX'}, \"DRAM\" = $COMM_MDL_INFO{1}->{'DRAM'}, \"CS0 Comm. Series\" = $COMM_MDL_INFO{0}->{'Comm. Series'}, \"CS1 Comm. Series\" = $COMM_MDL_INFO{1}->{'Comm. Series'}, \"Bank\" = $COMM_MDL_INFO{0}->{'Bank'}, \"PBP->Y / N\" = $COMM_MDL_INFO{0}->{'PBP'}->{'Y / N'}, \"PBP->Size(W)\" = $COMM_MDL_INFO{0}->{'PBP'}->{'Size(W)'}\n";
  }
  exit;
}

#****************************************************************************
# dependency check
#****************************************************************************
&dependency_check($CUSTOM_EMI_H, "FALSE", "tools/emiGenMD.pl", "tools/emiGenSP.pl", "tools/emigenemi.pl", "tools/emigenflash.pl", "tools/emigenSF.pl", $THEMF, $CUSTOM_MEMORY_DEVICE_HDR, $MEMORY_DEVICE_LIST_XLS, $MEMORY_DEVICE_LIST_INT_XLS, $CUSTOM_FEATURE_CONFIG_HDR);
&dependency_check($CUSTOM_EMI_RELEASE_H, "FALSE", "tools/emiGenMD.pl", "tools/emiGenSP.pl", "tools/emigenemi.pl", "tools/emigenflash.pl", "tools/emigenSF.pl", $THEMF, $CUSTOM_MEMORY_DEVICE_HDR, $MEMORY_DEVICE_LIST_XLS, $MEMORY_DEVICE_LIST_INT_XLS, $CUSTOM_FEATURE_CONFIG_HDR);
if($BBtbl_EMI_NEW_DESIGN{$MAKEFILE_OPTIONS{'platform'}} == 1){
    	&dependency_check($CUSTOM_EMI_INFO_H, "FALSE", "tools/emiGenMD.pl", "tools/emiGenSP.pl", "tools/emigenemi.pl", "tools/emigenflash.pl", "tools/emigenSF.pl", $THEMF, $CUSTOM_MEMORY_DEVICE_HDR, $MEMORY_DEVICE_LIST_XLS, $MEMORY_DEVICE_LIST_INT_XLS, $CUSTOM_FEATURE_CONFIG_HDR);
    }
else{
    	&dependency_check($CUSTOM_EMI_C, "FALSE", "tools/emiGenMD.pl", "tools/emiGenSP.pl", "tools/emigenemi.pl", "tools/emigenflash.pl", "tools/emigenSF.pl", $THEMF, $CUSTOM_MEMORY_DEVICE_HDR, $MEMORY_DEVICE_LIST_XLS, $MEMORY_DEVICE_LIST_INT_XLS, $CUSTOM_FEATURE_CONFIG_HDR);
    }
&dependency_check($CUSTOM_SFI_H, "FALSE", "tools/emiGenMD.pl", "tools/emiGenSP.pl", "tools/emigenemi.pl", "tools/emigen_flash.pl", "tools/emigenSF.pl", $THEMF, $CUSTOM_MEMORY_DEVICE_HDR, $MEMORY_DEVICE_LIST_XLS, $MEMORY_DEVICE_LIST_INT_XLS, $CUSTOM_FEATURE_CONFIG_HDR);
&dependency_check($CUSTOM_FLASH_H, "FALSE", "tools/emiGenMD.pl", "tools/emiGenSP.pl", "tools/emigenemi.pl", "tools/emigenflash.pl", "tools/emigenSF.pl", $THEMF, $CUSTOM_MEMORY_DEVICE_HDR, $MEMORY_DEVICE_LIST_XLS, $MEMORY_DEVICE_LIST_INT_XLS, $CUSTOM_FEATURE_CONFIG_HDR);
&dependency_check($FLASH_OPT_GEN_H, "FALSE", "tools/emiGenMD.pl", "tools/emiGenSP.pl", "tools/emigenemi.pl", "tools/emigenflash.pl", "tools/emigenSF.pl", $THEMF, $CUSTOM_MEMORY_DEVICE_HDR, $MEMORY_DEVICE_LIST_XLS, $MEMORY_DEVICE_LIST_INT_XLS, $CUSTOM_FEATURE_CONFIG_HDR);
&dependency_check($CUSTOM_FLASH_NORFDM5_H, "TRUE", "tools/emiGenMD.pl", "tools/emiGenSP.pl", "tools/emigenemi.pl", "tools/emigenflash.pl", "tools/emigenSF.pl", $THEMF, $CUSTOM_MEMORY_DEVICE_HDR, $MEMORY_DEVICE_LIST_XLS, $MEMORY_DEVICE_LIST_INT_XLS, $CUSTOM_FEATURE_CONFIG_HDR);
&dependency_check($COMBO_FLASH_CONFIG_H, "FALSE", "tools/emiGenMD.pl", "tools/emiGenSP.pl", "tools/emigenemi.pl", "tools/emigenflash.pl", "tools/emigenSF.pl", $THEMF, $CUSTOM_MEMORY_DEVICE_HDR, $MEMORY_DEVICE_LIST_XLS, $MEMORY_DEVICE_LIST_INT_XLS, $CUSTOM_FEATURE_CONFIG_HDR);
&dependency_check($COMBO_FLASH_ID_H, "FALSE", "tools/emiGenMD.pl", "tools/emiGenSP.pl", "tools/emigenemi.pl", "tools/emigenflash.pl", "tools/emigenSF.pl", $THEMF, $CUSTOM_MEMORY_DEVICE_HDR, $MEMORY_DEVICE_LIST_XLS, $MEMORY_DEVICE_LIST_INT_XLS, $CUSTOM_FEATURE_CONFIG_HDR);
&dependency_check($COMBO_SFI_CONFIG_H, "FALSE", "tools/emiGenMD.pl", "tools/emiGenSP.pl", "tools/emigenemi.pl", "tools/emigenflash.pl", "tools/emigenSF.pl", $THEMF, $CUSTOM_MEMORY_DEVICE_HDR, $MEMORY_DEVICE_LIST_XLS, $MEMORY_DEVICE_LIST_INT_XLS, $CUSTOM_FEATURE_CONFIG_HDR);
&dependency_check($COMBO_SFI_DEFS_H, "FALSE", "tools/emiGenMD.pl", "tools/emiGenSP.pl", "tools/emigenemi.pl", "tools/emigenflash.pl", "tools/emigenSF.pl", $THEMF, $CUSTOM_MEMORY_DEVICE_HDR, $MEMORY_DEVICE_LIST_XLS, $MEMORY_DEVICE_LIST_INT_XLS, $CUSTOM_FEATURE_CONFIG_HDR);
my $is_existed_h                 = (-e $CUSTOM_EMI_H)?           1 : 0;
my $is_existed_release_h         = (-e $CUSTOM_EMI_RELEASE_H)?   1 : 0;
my $is_existed_info_h;
my $is_existed_c;
if($BBtbl_EMI_NEW_DESIGN{$MAKEFILE_OPTIONS{'platform'}} == 1){
	      $is_existed_info_h       = (-e $CUSTOM_EMI_INFO_H)?      1 : 0;
    }
else{
	      $is_existed_c            = (-e $CUSTOM_EMI_C)?           1 : 0;
	  }

my $is_existed_sfi_h             = (-e $CUSTOM_SFI_H)?           1 : 0;
my $is_existed_flash_h           = (-e $CUSTOM_FLASH_H)?         1 : 0;
my $is_existed_flash_opt_gen     = (-e $FLASH_OPT_GEN_H)?        1 : 0;
my $is_existed_flash_norfdm5     = (-e $CUSTOM_FLASH_NORFDM5_H)? 1 : 0;
my $is_existed_combo_flash_cfg_h = (-e $COMBO_FLASH_CONFIG_H)?   1 : 0;
my $is_existed_combo_flash_id_h  = (-e $COMBO_FLASH_ID_H)?       1 : 0;
my $is_existed_combo_sfi_cfg_h   = (-e $COMBO_SFI_CONFIG_H)?     1 : 0;
my $is_existed_combo_sfi_defs_h  = (-e $COMBO_SFI_DEFS_H)?       1 : 0;
#****************************************************************************
# Check for Serial Flash Platform file
#****************************************************************************
if ($BBtbl_SERIALFLASH{$MAKEFILE_OPTIONS{'platform'}} == 1)
{
	if($MAKEFILE_OPTIONS{'platform'} eq 'MT6255')
	{
		  if($MAKEFILE_OPTIONS{'SERIAL_FLASH_SUPPORT'} eq 'TRUE')
     {
     		if ( ($is_existed_h == 1) && ($is_existed_release_h == 1) && ($is_existed_c == 1) && ($is_existed_sfi_h == 1) && ($is_existed_flash_h == 1) && ($is_existed_flash_opt_gen == 1) && ($is_existed_flash_norfdm5 == 1) && ($is_existed_combo_flash_cfg_h == 1) && ($is_existed_combo_flash_id_h == 1) && ($is_existed_combo_sfi_cfg_h == 1) && ($is_existed_combo_sfi_defs_h == 1) )
        {
     	   print "\n\nALL flash_opt\.h, custom_EMI\.h, custom_EMI_release\.h, custom_EMI_INFO\.h, custom_SFI\.h, custom_SFI\.c, custom_flash\.c, custom_flash_norfdm5\.c, combo_flash_config\.h, combo_flash_id\.h, combo_sfi_config\.h, and combo_sfi_defs\.h are existed!!!\n\n\n";
     	   exit;
        }
     }
     else
     {
     	     if ( ($is_existed_h == 1) && ($is_existed_release_h == 1) && ($is_existed_info_h == 1) && ($is_existed_flash_h == 1) && ($is_existed_flash_opt_gen == 1) && ($is_existed_flash_norfdm5 == 1) && ($is_existed_combo_flash_cfg_h == 1) && ($is_existed_combo_flash_id_h == 1) )
	      {
		        print "\n\nALL flash_opt_gen\.h, custom_EMI\.h, custom_EMI_release\.h, custom_EMI_INFO\.h, custom_flash\.h, combo_flash_config\.h, and combo_flash_id\.h are existed!!!\n\n\n";
		        exit;
	      }
     }
  }
  elsif($MAKEFILE_OPTIONS{'platform'} eq 'MT6280')
  {
       if($MAKEFILE_OPTIONS{'SERIAL_FLASH_SUPPORT'} eq 'TRUE')
     {
     		if ( ($is_existed_h == 1) && ($is_existed_release_h == 1) && ($is_existed_info_h == 1) && ($is_existed_sfi_h == 1) && ($is_existed_flash_h == 1) && ($is_existed_flash_opt_gen == 1) && ($is_existed_flash_norfdm5 == 1) && ($is_existed_combo_flash_cfg_h == 1) && ($is_existed_combo_flash_id_h == 1) && ($is_existed_combo_sfi_cfg_h == 1) && ($is_existed_combo_sfi_defs_h == 1) )
        {
     	   print "\n\nALL flash_opt\.h, custom_EMI\.h, custom_EMI_release\.h, custom_EMI\.c, custom_SFI\.h, custom_SFI\.c, custom_flash\.c, custom_flash_norfdm5\.c, combo_flash_config\.h, combo_flash_id\.h, combo_sfi_config\.h, and combo_sfi_defs\.h are existed!!!\n\n\n";
     	   exit;
        }
     }
     else
     {
     	     if ( ($is_existed_h == 1) && ($is_existed_release_h == 1) && ($is_existed_info_h == 1) && ($is_existed_flash_h == 1) && ($is_existed_flash_opt_gen == 1) && ($is_existed_flash_norfdm5 == 1) && ($is_existed_combo_flash_cfg_h == 1) && ($is_existed_combo_flash_id_h == 1) )
	      {
		        print "\n\nALL flash_opt_gen\.h, custom_EMI\.h, custom_EMI_release\.h, custom_EMI_INFO\.h, custom_flash\.h, combo_flash_config\.h, and combo_flash_id\.h are existed!!!\n\n\n";
		        exit;
	      }
     }
  }
  else
  {
	if ( ($is_existed_h == 1) && ($is_existed_release_h == 1) && ($is_existed_c == 1) && ($is_existed_sfi_h == 1) && ($is_existed_flash_h == 1) && ($is_existed_flash_opt_gen == 1) && ($is_existed_flash_norfdm5 == 1) && ($is_existed_combo_flash_cfg_h == 1) && ($is_existed_combo_flash_id_h == 1) && ($is_existed_combo_sfi_cfg_h == 1) && ($is_existed_combo_sfi_defs_h == 1) )
	{
		print "\n\nALL flash_opt\.h, custom_EMI\.h, custom_EMI_release\.h, custom_EMI\.c, custom_SFI\.h, custom_SFI\.c, custom_flash\.c, custom_flash_norfdm5\.c, combo_flash_config\.h, combo_flash_id\.h, combo_sfi_config\.h, and combo_sfi_defs\.h are existed!!!\n\n\n";
		exit;
	}
}
	
	#if ( ($is_existed_h == 1) && ($is_existed_release_h == 1) && ($is_existed_c == 1) && ($is_existed_sfi_h == 1) && ($is_existed_sfi_c == 1) && ($is_existed_flash_c == 1) && ($is_existed_flash_opt == 1) && ($is_existed_flash_norfdm5 == 1) && ($is_existed_combo_flash_cfg_h == 1) && ($is_existed_combo_flash_id_h == 1) && ($is_existed_combo_sfi_cfg_h == 1) && ($is_existed_combo_sfi_defs_h == 1) )

}
else
{
	if($BBtbl_EMI_NEW_DESIGN{$MAKEFILE_OPTIONS{'platform'}} == 1){
		     if ( ($is_existed_h == 1) && ($is_existed_release_h == 1) && ($is_existed_info_h == 1) && ($is_existed_flash_h == 1) && ($is_existed_flash_opt_gen == 1) && ($is_existed_flash_norfdm5 == 1) && ($is_existed_combo_flash_cfg_h == 1) && ($is_existed_combo_flash_id_h == 1) )
	      {
		        print "\n\nALL flash_opt_gen\.h, custom_EMI\.h, custom_EMI_release\.h, custom_EMI_INFO\.h, custom_flash\.h, combo_flash_config\.h, and combo_flash_id\.h are existed!!!\n\n\n";
		        exit;
	      }
	}
	else{
		     if ( ($is_existed_h == 1) && ($is_existed_release_h == 1) && ($is_existed_c == 1) && ($is_existed_flash_h == 1) && ($is_existed_flash_opt_gen == 1) && ($is_existed_flash_norfdm5 == 1) && ($is_existed_combo_flash_cfg_h == 1) && ($is_existed_combo_flash_id_h == 1) )
	      {
		        print "\n\nALL flash_opt_gen\.h, custom_EMI\.h, custom_EMI_release\.h, custom_EMI\.c, custom_flash\.h, combo_flash_config\.h, and combo_flash_id\.h are existed!!!\n\n\n";
		        exit;
	      }
	}
}
#****************************************************************************
# parse custom_MemoryDevice.h to extract MEMORY_DEVICE_TYPE & PART_NUMBER
#****************************************************************************
&Parse_Memory_Device(\%MAKEFILE_OPTIONS,\%PART_NUMBER,\$LPSDRAM_CHIP_SELECT,\%CUSTOM_MEM_DEV_OPTIONS, \@MCP_LIST);

#****************************************************************************
# parse custom_FeatureConfig.h to extract feature-related configurations
#****************************************************************************
&Parse_custom_FeatureConfig(\%CUSTOM_FEATURE_CFG_OPTIONS);
#****************************************************************************
# Check EMI Gen V7 availability
#****************************************************************************
&error_handler("EMI Gen V7 does not support MT6235+NOR booting! Please manually check-in EMI/flash files!", __FILE__, __LINE__)
    if (($MAKEFILE_OPTIONS{'PLATFORM'} eq 'MT6235') and (!exists $MAKEFILE_OPTIONS{'nand_flash_booting'} or $MAKEFILE_OPTIONS{'nand_flash_booting'} eq 'NONE'));
&error_handler("EMI Gen V7 does not support NOR_LPSDRAM_MCP device type! Please manually check-in EMI/flash files!", __FILE__, __LINE__)
    if ($CUSTOM_MEM_DEV_OPTIONS{MEMORY_DEVICE_TYPE} eq 'NOR_LPSDRAM_MCP');
# generate default template for smart phone platforms
my %BBtbl_SMART_PHONE = 
(
        'MT6516'  => 1,
        'MT6573'  => 1,
        'MT6575'  => 1,
        'MT6577'  => 1,
        'MT6517'  => 1,
        'MT6585'  => 1, 
        'MT6582'  => 1,
);
if (($BBtbl_SMART_PHONE{$MAKEFILE_OPTIONS{'platform'}}) || ($MAKEFILE_OPTIONS{'smart_phone_core'} ne "NONE"))
#if($MAKEFILE_OPTIONS{'smart_phone_core'} ne 'NONE')
{
	  if($MAKEFILE_OPTIONS{'platform'} eq 'MT6280')
	  {
	      	
	  }
	  else
	  {
    require "tools/emiGenSP.pl";
    if ($is_existed_h == 0)
    {
        open (CUSTOM_EMI_H, ">$CUSTOM_EMI_H") or &error_handler("$CUSTOM_EMI_H: file error!", __FILE__, __LINE__);

        print CUSTOM_EMI_H &copyright_file_header();
        print CUSTOM_EMI_H &description_file_header("custom_EMI.h",
                                                    "This Module defines the EMI (external memory interface) related setting.",
                                                    $CUSTOM_EMI_H_OWNER . "EMI auto generator" . $EMIGEN_VERNO);
        print CUSTOM_EMI_H &custom_EMI_h_file_body_for_sp($MAKEFILE_OPTIONS{'platform'});
        close CUSTOM_EMI_H or &error_handler("$CUSTOM_EMI_H: file error!", __FILE__, __LINE__);
        print "test smart \n";
        print "\n$CUSTOM_EMI_H is generated\n";
        $is_existed_h = 1;
    }
    if ($is_existed_release_h == 0)
    {
        open (CUSTOM_EMI_RELEASE_H, ">$CUSTOM_EMI_RELEASE_H") or &error_handler("$CUSTOM_EMI_RELEASE_H: file error!", __FILE__, __LINE__);

        print CUSTOM_EMI_RELEASE_H &copyright_file_header();
        print CUSTOM_EMI_RELEASE_H &description_file_header("custom_EMI_release.h",
                                                            "This Module defines the EMI (external memory interface) related setting.",
                                                            $CUSTOM_EMI_RELEASE_H_OWNER . "EMI auto generator" . $EMIGEN_VERNO);
        print CUSTOM_EMI_RELEASE_H &custom_EMI_release_h_file_body_for_sp($MAKEFILE_OPTIONS{'platform'});
        close CUSTOM_EMI_RELEASE_H or &error_handler("$CUSTOM_EMI_RELEASE_H: file error!", __FILE__, __LINE__);

        print "\n$CUSTOM_EMI_RELEASE_H is generated\n";
        $is_existed_release_h = 1;
    }
     if ($is_existed_c == 0)
    {
        open (CUSTOM_EMI_C, ">$CUSTOM_EMI_C") or &error_handler("$CUSTOM_EMI_C: file error!", __FILE__, __LINE__);

        print CUSTOM_EMI_C &copyright_file_header();
        print CUSTOM_EMI_C &description_file_header("custom_EMI.c",
                                                    "This Module defines the EMI (external memory interface) related setting.",
                                                    "EMI auto generator" . $EMIGEN_VERNO);
        print CUSTOM_EMI_C &custom_EMI_c_file_body_for_sp($MAKEFILE_OPTIONS{'platform'});
        close CUSTOM_EMI_C or &error_handler("$CUSTOM_EMI_C: file error!", __FILE__, __LINE__);

        print "\n$CUSTOM_EMI_C is generated\n";
        $is_existed_c = 1;
    }
    if ($is_existed_flash_h == 0)
    {
        open (CUSTOM_FLASH_H, ">$CUSTOM_FLASH_H") or &error_handler("$CUSTOM_FLASH_H: file error!", __FILE__, __LINE__);

        print CUSTOM_FLASH_H &copyright_file_header();
        print CUSTOM_FLASH_H &description_file_header("custom_flash.h",
                                                      "This Module defines flash related settings.",
                                                      $CUSTOM_FLASH_H_OWNER . "EMI auto generator" . $EMIGEN_VERNO);
        print CUSTOM_FLASH_H &custom_flash_h_file_body_for_sp($MAKEFILE_OPTIONS{'platform'});
        close CUSTOM_FLASH_H or &error_handler("$CUSTOM_FLASH_H: file error!", __FILE__, __LINE__);

        print "\n$CUSTOM_FLASH_H is generated\n";
        $is_existed_flash_h = 1;
    }
    if ($is_existed_flash_opt_gen == 0)
    {
        open (FLASH_OPT_GEN_H, ">$FLASH_OPT_GEN_H") or &error_handler("$FLASH_OPT_GEN_H: file error!", __FILE__, __LINE__);

        print FLASH_OPT_GEN_H &copyright_file_header();
        print FLASH_OPT_GEN_H &description_file_header("flash_opt_gen.h",
                                                   "NOR flash related options",
                                                   $FLASH_OPT_GEN_H_OWNER . "EMI auto generator" . $EMIGEN_VERNO);
        print FLASH_OPT_GEN_H &flash_opt_gen_h_file_body_for_sp($MAKEFILE_OPTIONS{'platform'});
        close FLASH_OPT_GEN_H or &error_handler("$FLASH_OPT_GEN_H: file error!", __FILE__, __LINE__);

        print "\n$FLASH_OPT_GEN_H is generated\n";
        $is_existed_flash_opt_gen = 1;
    }
    exit;
}
}


if (($MAKEFILE_OPTIONS{'nand_flash_booting'} eq 'NONE') and (!exists $MAKEFILE_OPTIONS{'emmc_booting'} or $MAKEFILE_OPTIONS{'emmc_booting'} eq 'NONE'))
{
	  if(($MAKEFILE_OPTIONS{'platform'} eq 'MT6280') && ($MAKEFILE_OPTIONS{'smart_phone_core'} ne "NONE"))
	  {
	       
	  }
	  else
	  {
    &error_handler("$THEMF: MEMORY_DEVICE_TYPE cannot be LPSDRAM/LPDDR/LPDDR2 when NAND_FLASH_BOOTING is turned off! Please contact the BB owner to modify custom_MemoryDevice.h!", __FILE__, __LINE__) if ($CUSTOM_MEM_DEV_OPTIONS{MEMORY_DEVICE_TYPE} eq 'LPSDRAM');
}
}
else
{
    &error_handler("$THEMF: MEMORY_DEVICE_TYPE cannot be NOR_RAM_MCP when NAND_FLASH_BOOTING is turned on! Please contact the BB owner to modify custom_MemoryDevice.h!", __FILE__, __LINE__) if ($CUSTOM_MEM_DEV_OPTIONS{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP');
}

#for (1..$CUSTOM_MEM_DEV_OPTIONS{COMBO_MEM_ENTRY_COUNT})
#{
#    if ((defined $MCP_LIST[$_]->{0}) and (defined $MCP_LIST[$_]->{1}))
#    {
        ### SERIAL_FLASH allow different part numbers for Serial flash and RAM
#        if ($CUSTOM_MEM_DEV_OPTIONS{MEMORY_DEVICE_TYPE} ne 'SERIAL_FLASH')
#        {
#            &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: CS0 Part Number $MCP_LIST[$_]->{0} not sync with CS1 Part Number $MCP_LIST[$_]->{1}!", __FILE__, __LINE__) if ($MCP_LIST[$_]->{0} ne $MCP_LIST[$_]->{1});
#        }
#    }
#}

if ($DebugPrint == 1)
{
   print "Device Type : $CUSTOM_MEM_DEV_OPTIONS{MEMORY_DEVICE_TYPE}  , ";
   for (1..$CUSTOM_MEM_DEV_OPTIONS{COMBO_MEM_ENTRY_COUNT})
   {
       print "$_: $MCP_LIST[$_]->{0}, $MCP_LIST[$_]->{1}\n";
   }
   print "Manual Configure ( $CUSTOM_FEATURE_CFG_OPTIONS{PROJECT_EXPECTED_RAM_LIMIT} , $CUSTOM_FEATURE_CFG_OPTIONS{PROJECT_EXPECTED_CODE_LIMIT}, $CUSTOM_FEATURE_CFG_OPTIONS{PROJECT_EXPECTED_RAM_LIMIT_NFB} )\n";
}
#****************************************************************************
# parse EMI database to get EMI settings
#****************************************************************************
&Parse_MDL(\%MAKEFILE_OPTIONS,\%CUSTOM_MEM_DEV_OPTIONS,\@MDL_INFO_LIST,\$MEMORY_DEVICE_LIST_XLS, \$MEMORY_DEVICE_LIST_INT_XLS);

#****************************************************************************
# Check Combo Memory configuration validity
#****************************************************************************
my $nor_size_Mb;
my $blk_info_first = ($CUSTOM_MEM_DEV_OPTIONS{'MEMORY_DEVICE_TYPE'} eq 'NOR_RAM_MCP') ? ($MDL_INFO_LIST[1]->{0}->{'NOR Flash Geometry'}->{'Block Info.'}) : ($MDL_INFO_LIST[1]->{0}->{'Device Geometry'}->{'Block Info.'});
$blk_info_first =~ s/\s+//g;  # remove spaces
$blk_info_first =~ s/},/}/g;  # remove , after }
for (1..$CUSTOM_MEM_DEV_OPTIONS{COMBO_MEM_ENTRY_COUNT})
{
    ### NOR flash size should be the same among all devices when Combo Memory is enabled
    ### NAND flash size is not considered because we don't have to use NAND flash size information
    my $cur_nor_size_Mb;
    if (($CUSTOM_MEM_DEV_OPTIONS{'MEMORY_DEVICE_TYPE'} ne 'LPSDRAM') and ($CUSTOM_MEM_DEV_OPTIONS{'MEMORY_DEVICE_TYPE'} ne 'LPDDR') and ($CUSTOM_MEM_DEV_OPTIONS{'MEMORY_DEVICE_TYPE'} ne 'LPDDR2'))
    {
        $cur_nor_size_Mb = $MDL_INFO_LIST[$_]->{0}->{'Size (Mb)'};
        if (!defined $nor_size_Mb)
        {
            $nor_size_Mb = $cur_nor_size_Mb;
        }
        else
        {
            &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Please select flash with the same size when COMBO_MEMORY_SUPPORT is enabled!", __FILE__, __LINE__) if ($nor_size_Mb != $cur_nor_size_Mb);
        }
    }
    
}
#****************************************************************************
# check consistency among FEATURE, MEMORY_DEVICE_TYPE, PLATFORM, MCU_CLOCK and MemoryDeviceList data
#****************************************************************************
my $emi_clk_config = $BBtbl_EMI_FAST_CLK{$MAKEFILE_OPTIONS{'platform'}};
my $sfi_clk_config = $BBtbl_SFI_FAST_CLK{$MAKEFILE_OPTIONS{'platform'}};
&Decide_MDClock(\%MAKEFILE_OPTIONS,\%CUSTOM_MEM_DEV_OPTIONS, $LPSDRAM_CHIP_SELECT);

#****************************************************************************
# calculate the maximum number of command sets
#****************************************************************************
my $emi_nor_cmd_num_max = 0;
my $emi_psram_cmd_num_max = 0;
my $combo_emi_count;
if ($MAKEFILE_OPTIONS{'platform'} eq 'MT6252')
{
    $combo_emi_count = $CUSTOM_MEM_DEV_OPTIONS{COMBO_SIP_ENTRY_COUNT};
}
elsif (&config_query_no_EMI($MAKEFILE_OPTIONS{'platform'}) == 1)
{
    $combo_emi_count = 0;
}
elsif (defined $CUSTOM_MEM_DEV_OPTIONS{COMBO_MEM_ENTRY_COUNT})
{
    $combo_emi_count = $CUSTOM_MEM_DEV_OPTIONS{COMBO_MEM_ENTRY_COUNT};
}
if (($CUSTOM_MEM_DEV_OPTIONS{'MEMORY_DEVICE_TYPE'} eq 'NOR_RAM_MCP') || ($CUSTOM_MEM_DEV_OPTIONS{'MEMORY_DEVICE_TYPE'} eq 'SERIAL_FLASH'))
{
	if((($MAKEFILE_OPTIONS{'platform'} eq 'MT6255') || ($MAKEFILE_OPTIONS{'platform'} eq 'MT6280')) and ($CUSTOM_MEM_DEV_OPTIONS{'MEMORY_DEVICE_TYPE'} eq 'SERIAL_FLASH'))
	{
		
	}
	else
	{
    for (1..$combo_emi_count)
    {
        my @addr_list_nor   = &split_addr(&Lookup_SYNC_EMI_address_by_IDX_CS_CLK_BB($_, 0, $emi_clk_config, $MAKEFILE_OPTIONS{'platform'}));
        my @addr_list_psram = &split_addr(&Lookup_SYNC_EMI_address_by_IDX_CS_CLK_BB($_, 1, $emi_clk_config, $MAKEFILE_OPTIONS{'platform'}));
        if (($#addr_list_nor+1) > $emi_nor_cmd_num_max)
        {
            $emi_nor_cmd_num_max = $#addr_list_nor + 1;
        }
        if (($#addr_list_psram+1)> $emi_psram_cmd_num_max)
        {
            $emi_psram_cmd_num_max = $#addr_list_psram + 1;
        }
    }
}
   
}
print "emi_nor_cmd_num_max=$emi_nor_cmd_num_max, emi_psram_cmd_num_max=$emi_psram_cmd_num_max\n" if ($DebugPrint == 1);

#****************************************************************************
# get common MDL information from a list of MDL information for Combo Memory
#****************************************************************************
#&get_common_MDL_info(\@MDL_INFO_LIST, $CUSTOM_MEM_DEV_OPTIONS{COMBO_MEM_ENTRY_COUNT}, $COMBO_SIP_ENTRY_COUNT, $CUSTOM_MEM_DEV_OPTIONS{MEMORY_DEVICE_TYPE}, \%COMM_MDL_INFO, $LPSDRAM_CHIP_SELECT, \%MAKEFILE_OPTIONS, \%CUSTOM_MEM_DEV_OPTIONS, $CUSTOM_MEMORY_DEVICE_HDR);
&get_common_MDL_info(\@MDL_INFO_LIST, \%CUSTOM_MEM_DEV_OPTIONS, \%COMM_MDL_INFO,\%MAKEFILE_OPTIONS, $LPSDRAM_CHIP_SELECT, $CUSTOM_MEMORY_DEVICE_HDR);
if ($DebugPrint == 1)
{
    print "COMM_MDL_INFO: Flash Size = $COMM_MDL_INFO{0}->{'Flash Size'}, NAND Block Size(KB) = $COMM_MDL_INFO{0}->{'NAND Block Size(KB)'}, Small Block Start = $COMM_MDL_INFO{0}->{'Small Block Start'}, Default FAT Base = $COMM_MDL_INFO{0}->{'Default FAT Base'}, Default FAT Size = $COMM_MDL_INFO{0}->{'Default FAT Size'}, RAM \"Size (Mb)\" = $COMM_MDL_INFO{1}->{'Size (Mb)'}, \"CS0 ADMUX\" = $COMM_MDL_INFO{0}->{'ADMUX'}, \"CS1 ADMUX\" = $COMM_MDL_INFO{1}->{'ADMUX'}, \"DRAM\" = $COMM_MDL_INFO{1}->{'DRAM'}, \"CS0 Comm. Series\" = $COMM_MDL_INFO{0}->{'Comm. Series'}, \"CS1 Comm. Series\" = $COMM_MDL_INFO{1}->{'Comm. Series'}, \"Bank\" = $COMM_MDL_INFO{0}->{'Bank'}, \"PBP->Y / N\" = $COMM_MDL_INFO{0}->{'PBP'}->{'Y / N'}, \"PBP->Size(W)\" = $COMM_MDL_INFO{0}->{'PBP'}->{'Size(W)'}\n";
}

#****************************************************************************
# PROJECT EXPECTED CONFIGURE
#****************************************************************************
my $physical_ram_density;
my $project_expected_ram_limit_common = (exists $MAKEFILE_OPTIONS{'nand_flash_booting'} and $MAKEFILE_OPTIONS{'nand_flash_booting'} ne 'NONE') ? $CUSTOM_FEATURE_CFG_OPTIONS{PROJECT_EXPECTED_RAM_LIMIT_NFB} : $CUSTOM_FEATURE_CFG_OPTIONS{PROJECT_EXPECTED_RAM_LIMIT};
if (defined $project_expected_ram_limit_common)
{
    #ensure practical
    &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Cannot configure expected RAMSIZE larger than physical RAM size!", __FILE__, __LINE__)
        if ( hex($project_expected_ram_limit_common) > ($COMM_MDL_INFO{1}->{'Size (Mb)'} * 1024 * 1024 / 8) );

    #ensure 2^n
    my $i;
    for( $i = 1 ; $i < hex($project_expected_ram_limit_common) ; $i *= 2 ){1;}
    if ( $i < ($COMM_MDL_INFO{1}->{'Size (Mb)'} * 1024 * 1024 / 8) )
    {
        $physical_ram_density = "// PHYSICAL RAM DENSITY $COMM_MDL_INFO{1}->{'Size (Mb)'} Mb\n";
        $COMM_MDL_INFO{1}->{'Size (Mb)'} = $i * 8 / ( 1024 * 1024);
    }
}
chomp $physical_ram_density;

#****************************************************************************
# get common entire geometry information for Combo Memory
#****************************************************************************
my (@entire_region_info_size_list, @entire_region_info_count_list, @entire_bank_info_size_list, @entire_bank_info_count_list);
my (@entire_block_info_start_list, @entire_block_info_size_list);
if (($CUSTOM_MEM_DEV_OPTIONS{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP') or ($CUSTOM_MEM_DEV_OPTIONS{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH'))
{
	&get_common_MDL_Geo_info(\@MDL_INFO_LIST, $CUSTOM_MEM_DEV_OPTIONS{COMBO_MEM_ENTRY_COUNT}, $CUSTOM_MEM_DEV_OPTIONS{MEMORY_DEVICE_TYPE}, 0, $COMM_MDL_INFO{0}->{'Flash Size'}, \@entire_region_info_size_list, \@entire_region_info_count_list, \@entire_bank_info_size_list, \@entire_bank_info_count_list);
	&convert_regions_to_blocks(0, \@entire_region_info_size_list, \@entire_region_info_count_list, \@entire_block_info_start_list, \@entire_block_info_size_list);
}
&Calculate_FAT_Info(\%MAKEFILE_OPTIONS, \%CUSTOM_MEM_DEV_OPTIONS, \%COMM_MDL_INFO, \@MDL_INFO_LIST, \$NOR_FLASH_BASE_ADDRESS_VAL, \$NOR_ALLOCATED_FAT_SPACE_VAL, $nor_size_Mb, \%CUSTOM_FEATURE_CFG_OPTIONS, \@entire_block_info_start_list, \@entire_block_info_size_list);
#****************************************************************************
# get common FS geometry information for Combo Memory
#****************************************************************************
my (@fs_region_info_size_list, @fs_region_info_count_list, @fs_bank_info_size_list, @fs_bank_info_count_list);
my (@fs_block_info_start_list, @fs_block_info_size_list);
if (($CUSTOM_MEM_DEV_OPTIONS{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP') or ($CUSTOM_MEM_DEV_OPTIONS{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH'))
{
	&get_common_MDL_Geo_info(\@MDL_INFO_LIST, $CUSTOM_MEM_DEV_OPTIONS{COMBO_MEM_ENTRY_COUNT}, $CUSTOM_MEM_DEV_OPTIONS{MEMORY_DEVICE_TYPE}, $NOR_FLASH_BASE_ADDRESS_VAL, $NOR_FLASH_BASE_ADDRESS_VAL+$NOR_ALLOCATED_FAT_SPACE_VAL, \@fs_region_info_size_list, \@fs_region_info_count_list, \@fs_bank_info_size_list, \@fs_bank_info_count_list);
	&convert_regions_to_blocks($NOR_FLASH_BASE_ADDRESS_VAL, \@fs_region_info_size_list, \@fs_region_info_count_list, \@fs_block_info_start_list, \@fs_block_info_size_list);
	if ($DebugPrint == 1)
	{
	    print "Entire RegionInfo: ";
	    for (0..$#entire_region_info_size_list)
	    {
	        print "\{$entire_region_info_size_list[$_], $entire_region_info_count_list[$_]\}, ";
	    }
	    print "\nEntire BankInfo: ";
	    for (0..$#entire_bank_info_size_list)
	    {
	        print "\{$entire_bank_info_size_list[$_], $entire_bank_info_count_list[$_]\}, ";
	    }
	    print "\nEntire BlockInfo: ";
	    for (0..$#entire_block_info_start_list)
	    {
	        print "\{$entire_block_info_start_list[$_], $entire_block_info_size_list[$_]\}, ";
	    }
	    print "\nFS RegionInfo: ";
	    for (0..$#fs_region_info_size_list)
	    {
	        print "\{$fs_region_info_size_list[$_], $fs_region_info_count_list[$_]\}, ";
	    }
	    print "\nFS BankInfo: ";
	    for (0..$#fs_bank_info_size_list)
	    {
	        print "\{$fs_bank_info_size_list[$_], $fs_bank_info_count_list[$_]\}, ";
	    }
	    print "\nFS BlockInfo: ";
	    for (0..$#fs_block_info_start_list)
	    {
	        print "\{$fs_block_info_start_list[$_], $fs_block_info_size_list[$_]\}, ";
	    }
	    print "\n";
	}
}

### Validate FAT and NOR Raw disk overlapping case
&Validate_FAT_NORRAWDISK_OVERLAP(\%CUSTOM_MEM_DEV_OPTIONS, \%COMM_MDL_INFO, \$NOR_FLASH_BASE_ADDRESS_VAL, \$NOR_ALLOCATED_FAT_SPACE_VAL, $CUSTOM_MEMORY_DEVICE_HDR);
### Calculate NOR Raw disk Region Info
&Calculate_NORRAWDISK_Region_Info(\%CUSTOM_MEM_DEV_OPTIONS);

### Check CODE setting validity
my $expected_code_limit;
if (defined $CUSTOM_FEATURE_CFG_OPTIONS{PROJECT_EXPECTED_CODE_LIMIT})
{
    #ensure practical
    &error_handler("$CUSTOM_FEATURE_CONFIG_HDR: Cannot configure expected CODESIZE larger than (physical NOR flash size - FAT space)!", __FILE__, __LINE__)
        if ( hex($CUSTOM_FEATURE_CFG_OPTIONS{PROJECT_EXPECTED_CODE_LIMIT}) > $NOR_FLASH_BASE_ADDRESS_VAL );
}

#****************************************************************************
# generate flash_opt_gen.h
#****************************************************************************
if ($is_existed_flash_opt_gen == 0)
{
    open (FLASH_OPT_GEN_H, ">$FLASH_OPT_GEN_H") or &error_handler("$FLASH_OPT_GEN_H: file error!", __FILE__, __LINE__);

    print FLASH_OPT_GEN_H &copyright_file_header();
    print FLASH_OPT_GEN_H &description_file_header("flash_opt_gen.h",
                                               "NOR flash related options",
                                               $FLASH_OPT_GEN_H_OWNER . "EMI auto generator" . $EMIGEN_VERNO);
    print FLASH_OPT_GEN_H &flash_opt_gen_h_file_body(\%MAKEFILE_OPTIONS,\%CUSTOM_MEM_DEV_OPTIONS,\@MDL_INFO_LIST, \%COMM_MDL_INFO, $CUSTOM_MEMORY_DEVICE_HDR, $THEMF, \@entire_bank_info_size_list, \@entire_bank_info_count_list, \@entire_block_info_start_list, \@entire_block_info_size_list, \@entire_region_info_size_list, \@entire_region_info_count_list);
    close FLASH_OPT_GEN_H or &error_handler("$FLASH_OPT_GEN_H: file error!", __FILE__, __LINE__);

    print "\n$FLASH_OPT_GEN_H is generated\n";
}

#****************************************************************************
# generate custom_EMI.c
#****************************************************************************
if ($is_existed_c == 0)
{
	  if ($BBtbl_EMI_NEW_DESIGN{$MAKEFILE_OPTIONS{'platform'}} != 1)
	  {
	  				open (CUSTOM_EMI_C, ">$CUSTOM_EMI_C") or &error_handler("$CUSTOM_EMI_C: file error!", __FILE__, __LINE__);

    				print CUSTOM_EMI_C &copyright_file_header();
    				print CUSTOM_EMI_C &description_file_header("custom_EMI.c",
                                                "This Module defines the EMI (external memory interface) related setting.",
                                                $CUSTOM_EMI_C_OWNER . "EMI auto generator" . $EMIGEN_VERNO);
    				print CUSTOM_EMI_C &custom_EMI_c_file_body(\%MAKEFILE_OPTIONS,\%CUSTOM_MEM_DEV_OPTIONS,\@MDL_INFO_LIST, \%COMM_MDL_INFO, $LPSDRAM_CHIP_SELECT, \%BBtbl_LPSDRAM, $emi_clk_config, $emi_nor_cmd_num_max, $emi_psram_cmd_num_max);
    				close CUSTOM_EMI_C or &error_handler("$CUSTOM_EMI_C: file error!", __FILE__, __LINE__);

    				print "\n$CUSTOM_EMI_C is generated\n";
	  }
    
}

#****************************************************************************
# generate custom_EMI.h
#****************************************************************************
if ($is_existed_h == 0)
{
	  if ($MAKEFILE_OPTIONS{'platform'} eq 'MT6256'){
	  	    open (CUSTOM_EMI_H, ">$CUSTOM_EMI_H") or &error_handler("CUSTOM_EMI_H: file error!", __FILE__, __LINE__);

          print CUSTOM_EMI_H &copyright_file_header();
          print CUSTOM_EMI_H &description_file_header("custom_EMI.h",
                                                "This Module defines the EMI (external memory interface) related setting.",
                                                $CUSTOM_EMI_H_OWNER . "EMI auto generator" . $EMIGEN_VERNO);
          print CUSTOM_EMI_H &custom_EMI_h_56_file_body(\%MAKEFILE_OPTIONS,\%CUSTOM_MEM_DEV_OPTIONS,\@MDL_INFO_LIST, \%COMM_MDL_INFO, \%PART_NUMBER, $CUSTOM_MEMORY_DEVICE_HDR, $LPSDRAM_CHIP_SELECT, $emi_clk_config, $emi_nor_cmd_num_max, $emi_psram_cmd_num_max);
          close CUSTOM_EMI_H or &error_handler("$CUSTOM_EMI_H: file error!", __FILE__, __LINE__);

          print "\n$CUSTOM_EMI_H is generated\n";
	  }
	  elsif ($MAKEFILE_OPTIONS{'platform'} eq 'MT6255')
	  {
	  	    open (CUSTOM_EMI_H, ">$CUSTOM_EMI_H") or &error_handler("CUSTOM_EMI_H: file error!", __FILE__, __LINE__);

          print CUSTOM_EMI_H &copyright_file_header();
          print CUSTOM_EMI_H &description_file_header("custom_EMI.h",
                                                "This Module defines the EMI (external memory interface) related setting.",
                                                $CUSTOM_EMI_H_OWNER . "EMI auto generator" . $EMIGEN_VERNO);
          print CUSTOM_EMI_H &custom_EMI_h_55_file_body(\%MAKEFILE_OPTIONS,\%CUSTOM_MEM_DEV_OPTIONS,\@MDL_INFO_LIST, \%COMM_MDL_INFO, \%PART_NUMBER, $CUSTOM_MEMORY_DEVICE_HDR, $LPSDRAM_CHIP_SELECT, $emi_clk_config, $emi_nor_cmd_num_max, $emi_psram_cmd_num_max);
          close CUSTOM_EMI_H or &error_handler("$CUSTOM_EMI_H: file error!", __FILE__, __LINE__);

          print "\n$CUSTOM_EMI_H is generated\n";
	  }
	   elsif ($MAKEFILE_OPTIONS{'platform'} eq 'MT6280')
	  {
	  	    open (CUSTOM_EMI_H, ">$CUSTOM_EMI_H") or &error_handler("CUSTOM_EMI_H: file error!", __FILE__, __LINE__);

          print CUSTOM_EMI_H &copyright_file_header();
          print CUSTOM_EMI_H &description_file_header("custom_EMI.h",
                                                "This Module defines the EMI (external memory interface) related setting.",
                                                $CUSTOM_EMI_H_OWNER . "EMI auto generator" . $EMIGEN_VERNO);
          print CUSTOM_EMI_H &custom_EMI_h_80_file_body(\%MAKEFILE_OPTIONS,\%CUSTOM_MEM_DEV_OPTIONS,\@MDL_INFO_LIST, \%COMM_MDL_INFO, \%PART_NUMBER, $CUSTOM_MEMORY_DEVICE_HDR, $LPSDRAM_CHIP_SELECT, $emi_clk_config, $emi_nor_cmd_num_max, $emi_psram_cmd_num_max);
          close CUSTOM_EMI_H or &error_handler("$CUSTOM_EMI_H: file error!", __FILE__, __LINE__);

          print "\n$CUSTOM_EMI_H is generated\n";
	  }
	  else{
	  	    open (CUSTOM_EMI_H, ">$CUSTOM_EMI_H") or &error_handler("CUSTOM_EMI_H: file error!", __FILE__, __LINE__);

          print CUSTOM_EMI_H &copyright_file_header();
          print CUSTOM_EMI_H &description_file_header("custom_EMI.h",
                                                "This Module defines the EMI (external memory interface) related setting.",
                                                $CUSTOM_EMI_H_OWNER . "EMI auto generator" . $EMIGEN_VERNO);
          print CUSTOM_EMI_H &custom_EMI_h_file_body(\%MAKEFILE_OPTIONS,\%CUSTOM_MEM_DEV_OPTIONS,\@MDL_INFO_LIST, \%COMM_MDL_INFO, \%PART_NUMBER, $CUSTOM_MEMORY_DEVICE_HDR, $LPSDRAM_CHIP_SELECT, $emi_clk_config, $emi_nor_cmd_num_max, $emi_psram_cmd_num_max);
          close CUSTOM_EMI_H or &error_handler("$CUSTOM_EMI_H: file error!", __FILE__, __LINE__);

          print "\n$CUSTOM_EMI_H is generated\n";
          print "others\n";
	  }
    
}

#****************************************************************************
# generate custom_EMI_INFO.h
#****************************************************************************
if ($is_existed_info_h == 0)
{
	  if ($MAKEFILE_OPTIONS{'platform'} eq 'MT6256'){
    open (CUSTOM_EMI_INFO_H, ">$CUSTOM_EMI_INFO_H") or &error_handler("CUSTOM_EMI_INFO_H: file error!", __FILE__, __LINE__);

    print CUSTOM_EMI_INFO_H &copyright_file_header();
    print CUSTOM_EMI_INFO_H &description_file_header("custom_EMI_INFO.h",
                                                "This Module defines the EMI (external memory interface) related setting.",
                                                $CUSTOM_EMI_INFO_H_OWNER . "EMI auto generator" . $EMIGEN_VERNO);
    print CUSTOM_EMI_INFO_H &custom_EMI_info_h_56_file_body(\%MAKEFILE_OPTIONS,\%CUSTOM_MEM_DEV_OPTIONS,\@MDL_INFO_LIST, \%COMM_MDL_INFO, \%PART_NUMBER, $CUSTOM_MEMORY_DEVICE_HDR, $LPSDRAM_CHIP_SELECT, $emi_clk_config, $emi_nor_cmd_num_max, $emi_psram_cmd_num_max);
    close CUSTOM_EMI_INFO_H or &error_handler("$CUSTOM_EMI_INFO_H: file error!", __FILE__, __LINE__);

    print "\n$CUSTOM_EMI_INFO_H is generated\n";
  }
  elsif($MAKEFILE_OPTIONS{'platform'} eq 'MT6255'){
  	open (CUSTOM_EMI_INFO_H, ">$CUSTOM_EMI_INFO_H") or &error_handler("CUSTOM_EMI_INFO_H: file error!", __FILE__, __LINE__);

    print CUSTOM_EMI_INFO_H &copyright_file_header();
    print CUSTOM_EMI_INFO_H &description_file_header("custom_EMI_INFO.h",
                                                "This Module defines the EMI (external memory interface) related setting.",
                                                $CUSTOM_EMI_INFO_H_OWNER . "EMI auto generator" . $EMIGEN_VERNO);
    print CUSTOM_EMI_INFO_H &custom_EMI_info_h_55_file_body(\%MAKEFILE_OPTIONS,\%CUSTOM_MEM_DEV_OPTIONS,\@MDL_INFO_LIST, \%COMM_MDL_INFO, \%PART_NUMBER, $CUSTOM_MEMORY_DEVICE_HDR, $LPSDRAM_CHIP_SELECT, $emi_clk_config, $emi_nor_cmd_num_max, $emi_psram_cmd_num_max);
    close CUSTOM_EMI_INFO_H or &error_handler("$CUSTOM_EMI_INFO_H: file error!", __FILE__, __LINE__);

    print "\n$CUSTOM_EMI_INFO_H is generated\n";
  }
  elsif($MAKEFILE_OPTIONS{'platform'} eq 'MT6280'){
  	open (CUSTOM_EMI_INFO_H, ">$CUSTOM_EMI_INFO_H") or &error_handler("CUSTOM_EMI_INFO_H: file error!", __FILE__, __LINE__);

    print CUSTOM_EMI_INFO_H &copyright_file_header();
    print CUSTOM_EMI_INFO_H &description_file_header("custom_EMI_INFO.h",
                                                "This Module defines the EMI (external memory interface) related setting.",
                                                $CUSTOM_EMI_INFO_H_OWNER . "EMI auto generator" . $EMIGEN_VERNO);
    print CUSTOM_EMI_INFO_H &custom_EMI_info_h_80_file_body(\%MAKEFILE_OPTIONS,\%CUSTOM_MEM_DEV_OPTIONS,\@MDL_INFO_LIST, \%COMM_MDL_INFO, \%PART_NUMBER, $CUSTOM_MEMORY_DEVICE_HDR, $LPSDRAM_CHIP_SELECT, $emi_clk_config, $emi_nor_cmd_num_max, $emi_psram_cmd_num_max);
    close CUSTOM_EMI_INFO_H or &error_handler("$CUSTOM_EMI_INFO_H: file error!", __FILE__, __LINE__);

    print "\n$CUSTOM_EMI_INFO_H is generated\n";
  }
}
#****************************************************************************
# generate custom_EMI_release.h
#****************************************************************************
if ($is_existed_release_h == 0)
{
    open (CUSTOM_EMI_RELEASE_H, ">$CUSTOM_EMI_RELEASE_H") or &error_handler("CUSTOM_EMI_RELEASE_H: file error!", __FILE__, __LINE__);

    print CUSTOM_EMI_RELEASE_H &copyright_file_header();
    print CUSTOM_EMI_RELEASE_H &description_file_header("custom_EMI_release.h",
                                                "This Module defines the EMI (external memory interface) related setting.",
                                                $CUSTOM_EMI_RELEASE_H_OWNER . "EMI auto generator" . $EMIGEN_VERNO);
    print CUSTOM_EMI_RELEASE_H &custom_EMI_release_h_file_body(\%MAKEFILE_OPTIONS,\%CUSTOM_MEM_DEV_OPTIONS,\@MDL_INFO_LIST, \%COMM_MDL_INFO, $LPSDRAM_CHIP_SELECT, $emi_clk_config);
    close CUSTOM_EMI_RELEASE_H or &error_handler("$CUSTOM_EMI_RELEASE_H: file error!", __FILE__, __LINE__);

    print "\n$CUSTOM_EMI_RELEASE_H is generated\n";
}

#****************************************************************************
# generate custom_flash.h
#****************************************************************************
if ($is_existed_flash_h == 0)
{
    open (CUSTOM_FLASH_H, ">$CUSTOM_FLASH_H") or &error_handler("$CUSTOM_FLASH_H: file error!", __FILE__, __LINE__);

    print CUSTOM_FLASH_H &copyright_file_header();
    print "custom_flash.h $CUSTOM_MEMORY_DEVICE_HDR\n";
    print CUSTOM_FLASH_H &description_file_header("custom_flash.h",
                                                  "This Module defines flash related settings.",
                                                  $CUSTOM_FLASH_H_OWNER . "EMI auto generator" . $EMIGEN_VERNO);
    print CUSTOM_FLASH_H &custom_flash_h_file_body(\%MAKEFILE_OPTIONS,\%CUSTOM_MEM_DEV_OPTIONS,\@MDL_INFO_LIST, \%COMM_MDL_INFO, \@MCP_LIST, $NOR_FLASH_BASE_ADDRESS_VAL, $NOR_ALLOCATED_FAT_SPACE_VAL, $LPSDRAM_CHIP_SELECT, $CUSTOM_MEMORY_DEVICE_HDR, $nor_size_Mb, \@entire_bank_info_size_list, \@entire_bank_info_count_list, \@entire_block_info_start_list, \@entire_block_info_size_list,\@fs_region_info_size_list, \@fs_region_info_count_list, \@entire_region_info_size_list, \@entire_region_info_count_list);
    close CUSTOM_FLASH_H or &error_handler("$CUSTOM_FLASH_H: file error!", __FILE__, __LINE__);

    print "\n$CUSTOM_FLASH_H is generated\n";
}

#****************************************************************************
# generate custom_flash_norfdm5.c
#****************************************************************************
if ($is_existed_flash_norfdm5 == 0)
{
    open (CUSTOM_FLASH_NORFDM5_H, ">$CUSTOM_FLASH_NORFDM5_H") or &error_handler("$CUSTOM_FLASH_NORFDM5_H: file error!", __FILE__, __LINE__);

    print CUSTOM_FLASH_NORFDM5_H &copyright_file_header();
    print CUSTOM_FLASH_NORFDM5_H &description_file_header("custom_flash_norfdm5.h",
                                                          "defines prototypes and data structure which will be used in NOR FDM 5.0",
                                                          $CUSTOM_FLASH_NORFDM5_H_OWNER . "EMI auto generator" . $EMIGEN_VERNO);
    print CUSTOM_FLASH_NORFDM5_H &custom_flash_norfdm5_h_file_body(\%MAKEFILE_OPTIONS,\%CUSTOM_MEM_DEV_OPTIONS,\@MDL_INFO_LIST, \%COMM_MDL_INFO, $NOR_FLASH_BASE_ADDRESS_VAL, $NOR_ALLOCATED_FAT_SPACE_VAL,\@entire_bank_info_size_list, \@entire_bank_info_count_list);
    close CUSTOM_FLASH_NORFDM5_H or &error_handler("$CUSTOM_FLASH_NORFDM5_H: file error!", __FILE__, __LINE__);

    print "\n$CUSTOM_FLASH_NORFDM5_H is generated\n";
}

#****************************************************************************
# generate combo_flash_config.h
#****************************************************************************
if ($is_existed_combo_flash_cfg_h == 0)
{
    open (COMBO_FLASH_CONFIG_H, ">$COMBO_FLASH_CONFIG_H") or &error_handler("$COMBO_FLASH_CONFIG_H: file error!", __FILE__, __LINE__);

    print COMBO_FLASH_CONFIG_H &copyright_file_header();
    print COMBO_FLASH_CONFIG_H &description_file_header("combo_flash_config.h",
                                                        "This Module defines the Flash configurations for Combo Memory.",
                                                        $COMBO_FLASH_CONFIG_H_OWNER . "EMI auto generator" . $EMIGEN_VERNO);
    print COMBO_FLASH_CONFIG_H &combo_flash_config_h_file_body(\%MAKEFILE_OPTIONS,\%CUSTOM_MEM_DEV_OPTIONS,\@MDL_INFO_LIST, \%COMM_MDL_INFO);
    close COMBO_FLASH_CONFIG_H or &error_handler("$COMBO_FLASH_CONFIG_H: file error!", __FILE__, __LINE__);

    print "\n$COMBO_FLASH_CONFIG_H is generated\n";
}

#****************************************************************************
# generate combo_flash_id.h
#****************************************************************************
if ($is_existed_combo_flash_id_h == 0)
{
    open (COMBO_FLASH_ID_H, ">$COMBO_FLASH_ID_H") or &error_handler("$COMBO_FLASH_ID_H: file error!", __FILE__, __LINE__);

    print COMBO_FLASH_ID_H &copyright_file_header();
    print COMBO_FLASH_ID_H &description_file_header("combo_flash_id.h",
                                                    "This Module defines the Flash ID table for Combo Memory.",
                                                    $COMBO_FLASH_ID_H_OWNER . "EMI auto generator" . $EMIGEN_VERNO);
    print COMBO_FLASH_ID_H &combo_flash_id_h_file_body(\%MAKEFILE_OPTIONS,\%CUSTOM_MEM_DEV_OPTIONS,\@MDL_INFO_LIST, \%COMM_MDL_INFO);
    close COMBO_FLASH_ID_H or &error_handler("$COMBO_FLASH_ID_H: file error!", __FILE__, __LINE__);

    print "\n$COMBO_FLASH_ID_H is generated\n";
}

if ($BBtbl_SERIALFLASH{$MAKEFILE_OPTIONS{'platform'}} == 1)
{
	if(($MAKEFILE_OPTIONS{'platform'} eq'MT6255') || ($MAKEFILE_OPTIONS{'platform'} eq'MT6280'))
	{
		print "makefile : $MAKEFILE_OPTIONS{'serial_flash_support'}";
		 if($MAKEFILE_OPTIONS{'serial_flash_support'} eq 'TRUE')
		 {
		 	print "test SF\n";
		 	    if ($is_existed_sfi_h == 0)
	     {
	         open (CUSTOM_SFI_H, ">$CUSTOM_SFI_H") or &error_handler("CUSTOM_SFI_H: file error!", __FILE__, __LINE__);
	      
	         print CUSTOM_SFI_H &copyright_file_header();
	         print CUSTOM_SFI_H &description_file_header("custom_SFI.h",
	                                                     "This Module defines the SFI (serial flash interface) related setting.",
	                                                     $CUSTOM_SFI_H_OWNER . "EMI auto generator" . $EMIGEN_VERNO);
	         print CUSTOM_SFI_H &custom_SFI_h_file_body(\%MAKEFILE_OPTIONS,\%CUSTOM_MEM_DEV_OPTIONS,\@MDL_INFO_LIST, \%COMM_MDL_INFO, $sfi_clk_config);
	         close CUSTOM_SFI_H or &error_handler("$CUSTOM_SFI_H: file error!", __FILE__, __LINE__);
	      
	         print "\n$CUSTOM_SFI_H is generated\n";
	     }
	      
	#****************************************************************************
	     # generate combo_sfi_config.h
	#****************************************************************************
	     if ($is_existed_combo_sfi_cfg_h == 0)
	     {
	         open (COMBO_SFI_CONFIG_H, ">$COMBO_SFI_CONFIG_H") or &error_handler("$COMBO_SFI_CONFIG_H: file error!", __FILE__, __LINE__);
	      
	         print COMBO_SFI_CONFIG_H &copyright_file_header();
	         print COMBO_SFI_CONFIG_H &description_file_header("combo_sfi_config.h",
	                                                           "defines flash configurations",
	                                                           $COMBO_SFI_CONFIG_H_OWNER . "EMI auto generator" . $EMIGEN_VERNO);
	         print COMBO_SFI_CONFIG_H &combo_sfi_config_h_file_body(\%MAKEFILE_OPTIONS,\%CUSTOM_MEM_DEV_OPTIONS,\@MDL_INFO_LIST, \%COMM_MDL_INFO);
	         close COMBO_SFI_CONFIG_H or &error_handler("$COMBO_SFI_CONFIG_H: file error!", __FILE__, __LINE__);
	      
	         print "\n$COMBO_SFI_CONFIG_H is generated\n";
	     }
	
	#****************************************************************************
	     # generate combo_sfi_defs.h
	#****************************************************************************
	     if ($is_existed_combo_sfi_defs_h == 0)
	     {
	         open (COMBO_SFI_DEFS_H, ">$COMBO_SFI_DEFS_H") or &error_handler("$COMBO_SFI_DEFS_H: file error!", __FILE__, __LINE__);
	      
	         print COMBO_SFI_DEFS_H &copyright_file_header();
	         print COMBO_SFI_DEFS_H &description_file_header("combo_sfi_defs.h",
	                                                         "defines flash ID table",
	                                                         $COMBO_SFI_DEFS_H_OWNER . "EMI auto generator" . $EMIGEN_VERNO);
	         print COMBO_SFI_DEFS_H &combo_sfi_defs_h_file_body(\%MAKEFILE_OPTIONS,\%CUSTOM_MEM_DEV_OPTIONS,\@MDL_INFO_LIST, \%COMM_MDL_INFO);
	         close COMBO_SFI_DEFS_H or &error_handler("$COMBO_SFI_DEFS_H: file error!", __FILE__, __LINE__);
	     
	         print "\n$COMBO_SFI_DEFS_H is generated\n";
	     }
		 }
  }     
	else  
	{     
	if ($is_existed_sfi_h == 0)
	{
	    open (CUSTOM_SFI_H, ">$CUSTOM_SFI_H") or &error_handler("CUSTOM_SFI_H: file error!", __FILE__, __LINE__);
	
	    print CUSTOM_SFI_H &copyright_file_header();
	    print CUSTOM_SFI_H &description_file_header("custom_SFI.h",
	                                                "This Module defines the SFI (serial flash interface) related setting.",
	                                                $CUSTOM_SFI_H_OWNER . "EMI auto generator" . $EMIGEN_VERNO);
	    print CUSTOM_SFI_H &custom_SFI_h_file_body(\%MAKEFILE_OPTIONS,\%CUSTOM_MEM_DEV_OPTIONS,\@MDL_INFO_LIST, \%COMM_MDL_INFO, $sfi_clk_config);
	    close CUSTOM_SFI_H or &error_handler("$CUSTOM_SFI_H: file error!", __FILE__, __LINE__);
	
	    print "\n$CUSTOM_SFI_H is generated\n";
	}
	
	#****************************************************************************
	# generate combo_sfi_config.h
	#****************************************************************************
	if ($is_existed_combo_sfi_cfg_h == 0)
	{
	    open (COMBO_SFI_CONFIG_H, ">$COMBO_SFI_CONFIG_H") or &error_handler("$COMBO_SFI_CONFIG_H: file error!", __FILE__, __LINE__);
	
	    print COMBO_SFI_CONFIG_H &copyright_file_header();
	    print COMBO_SFI_CONFIG_H &description_file_header("combo_sfi_config.h",
	                                                      "defines flash configurations",
	                                                      $COMBO_SFI_CONFIG_H_OWNER . "EMI auto generator" . $EMIGEN_VERNO);
	    print COMBO_SFI_CONFIG_H &combo_sfi_config_h_file_body(\%MAKEFILE_OPTIONS,\%CUSTOM_MEM_DEV_OPTIONS,\@MDL_INFO_LIST, \%COMM_MDL_INFO);
	    close COMBO_SFI_CONFIG_H or &error_handler("$COMBO_SFI_CONFIG_H: file error!", __FILE__, __LINE__);
	
	    print "\n$COMBO_SFI_CONFIG_H is generated\n";
	}
	
	#****************************************************************************
	# generate combo_sfi_defs.h
	#****************************************************************************
	if ($is_existed_combo_sfi_defs_h == 0)
	{
	    open (COMBO_SFI_DEFS_H, ">$COMBO_SFI_DEFS_H") or &error_handler("$COMBO_SFI_DEFS_H: file error!", __FILE__, __LINE__);
	
	    print COMBO_SFI_DEFS_H &copyright_file_header();
	    print COMBO_SFI_DEFS_H &description_file_header("combo_sfi_defs.h",
	                                                    "defines flash ID table",
	                                                    $COMBO_SFI_DEFS_H_OWNER . "EMI auto generator" . $EMIGEN_VERNO);
	    print COMBO_SFI_DEFS_H &combo_sfi_defs_h_file_body(\%MAKEFILE_OPTIONS,\%CUSTOM_MEM_DEV_OPTIONS,\@MDL_INFO_LIST, \%COMM_MDL_INFO);
	    close COMBO_SFI_DEFS_H or &error_handler("$COMBO_SFI_DEFS_H: file error!", __FILE__, __LINE__);
	
	    print "\n$COMBO_SFI_DEFS_H is generated\n";
	}
}

}

exit;

#****************************************************************************
# find the correct EMI database
#****************************************************************************
sub Find_MDL
{
	my ($MAKEFILE_OPTIONS_LOCAL,$MEMORY_DEVICE_LIST_XLS_LOCAL,$MEMORY_DEVICE_LIST_INT_XLS_LOCAL) = @_;
	
	my $MEMORY_DEVICE_LST = "MemoryDeviceList_Since10AW1124.xls";
  my $MEMORY_DEVICE_LST_INT = "MemoryDeviceList_Internal.xls";
  
  if ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6251')  # MT6251 uses separate MDL
  {
      $MEMORY_DEVICE_LST = "MemoryDeviceList_MT6251_Since11AW1112.xls";
      $MEMORY_DEVICE_LST_INT = "MemoryDeviceList_MT6251_Internal.xls";
      $IDX_COUNT = 2;
  }
  elsif (($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6276') and ((defined $MAKEFILE_OPTIONS_LOCAL->{'modem_card'}) and ($MAKEFILE_OPTIONS_LOCAL->{'modem_card'} ne 'NONE' and $MAKEFILE_OPTIONS_LOCAL->{'modem_card'} ne 'FALSE')))  # MT6276M uses separate MDL
  {
      $MEMORY_DEVICE_LST = "MemoryDeviceList_MT6276M_Since11AW1120.xls";
      $MEMORY_DEVICE_LST_INT = "MemoryDeviceList_MT6276M_Internal.xls";
      $IDX_COUNT = 2;
  }
  elsif ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6276')  # MT6276 uses separate MDL
  {
      $MEMORY_DEVICE_LST = "MemoryDeviceList_MT6276_Since11AW1112.xls";
      $MEMORY_DEVICE_LST_INT = "MemoryDeviceList_MT6276_Internal.xls";
      $IDX_COUNT = 2;
  }
  elsif ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6921')  # MT6921 uses separate MDL
  {
      $MEMORY_DEVICE_LST = "MemoryDeviceList_MT6921_Since10AW1032.xls";
      $MEMORY_DEVICE_LST_INT = "MemoryDeviceList_MT6921_Internal.xls";
      $IDX_COUNT = 3;
  }
  elsif ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6256')  # MT6256 uses separate MDL
  {
      $MEMORY_DEVICE_LST = "MemoryDeviceList_MT6256_Since11BW1140.xls";
      $MEMORY_DEVICE_LST_INT = "MemoryDeviceList_MT6256_Internal.xls";
      $IDX_COUNT = 2;
  }
  elsif ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6255')  # MT6256 uses separate MDL
  {
      $MEMORY_DEVICE_LST = "MemoryDeviceList_MT6255_Since11BW1152.xls";
      $MEMORY_DEVICE_LST_INT = "MemoryDeviceList_MT6255_Internal.xls";
      $IDX_COUNT = 2;
  }
  elsif ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6280')  # MT6256 uses separate MDL
  {
      $MEMORY_DEVICE_LST = "MemoryDeviceList_MT6280_Since11BW1232.xls";
      $MEMORY_DEVICE_LST_INT = "MemoryDeviceList_MT6280_Internal.xls";
      $IDX_COUNT = 2;
  }
  #$$MEMORY_DEVICE_LIST_XLS_LOCAL     = Win32::GetCwd() . "\\tools\\MemoryDeviceList\\" . $MEMORY_DEVICE_LST;
  #$$MEMORY_DEVICE_LIST_INT_XLS_LOCAL = Win32::GetCwd()."\\tools\\MemoryDeviceList\\" . $MEMORY_DEVICE_LST_INT;
  if($^O eq "MSWin32")
  {
  $MEMORY_DEVICE_LIST_XLS     = Win32::GetCwd() . "\\tools\\MemoryDeviceList\\" . $MEMORY_DEVICE_LST;
  $MEMORY_DEVICE_LIST_INT_XLS = Win32::GetCwd()."\\tools\\MemoryDeviceList\\" . $MEMORY_DEVICE_LST_INT;
  $MEMORY_DEVICE_LIST_XLS_E  = $MEMORY_DEVICE_LST;
  $MEMORY_DEVICE_LIST_XLS_E =~ s/^.\\|^\\//;
  }
  else
  {
  	  $MEMORY_DEVICE_LIST_XLS     = "tools/MemoryDeviceList/" . $MEMORY_DEVICE_LST;
      $MEMORY_DEVICE_LIST_INT_XLS = "tools/MemoryDeviceList/" . $MEMORY_DEVICE_LST_INT;
  }

  print "$CUSTOM_MEMORY_DEVICE_HDR\n$$MEMORY_DEVICE_LIST_XLS_LOCAL\n$THEMF\n" if ($DebugPrint == 1);
}

#****************************************************************************
# parse Project Make File
#****************************************************************************
sub Parse_Makefile
{
	#my %MAKEFILE_OPTIONS_LOCAL;
  my $keyname;
  my ($THEMF_LOCAL, $MAKEFILE_OPTIONS_LOCAL) = @_;
  
  &error_handler("$THEMF_LOCAL: NOT exist!", __FILE__, __LINE__) if (!-e $THEMF_LOCAL);

if ($THEMF_LOCAL =~ /make\\(\w+)_(\w+).mak/i) {
  $MAKEFILE_OPTIONS_LOCAL->{'MODE'} = uc($2);
}

open (FILE_HANDLE, "<$THEMF_LOCAL") or &error_handler("$THEMF_LOCAL: file error!", __FILE__, __LINE__);
while (<FILE_HANDLE>) {
  if (/^(\S+)\s*=\s*(\S+)/) {
    $keyname = lc($1);
    #print "keyname : $keyname\n";
    defined($MAKEFILE_OPTIONS_LOCAL->{$keyname}) && warn "$1 redefined in $THEMF_LOCAL!\n";
    $MAKEFILE_OPTIONS_LOCAL->{$keyname} = uc($2);
    #print "$keyname : $MAKEFILE_OPTIONS_LOCAL->{$keyname}\n";
  }
}
close (FILE_HANDLE);
#my $PLATFORM  = $MAKEFILE_OPTIONS{'platform'};
#my $MCU_CLOCK = $MAKEFILE_OPTIONS{'mcu_clock'};
#my $COMBO_MEM = $MAKEFILE_OPTIONS{'combo_memory_support'};
#print "PLATFORM=$PLATFORM, MCU_CLOCK=$MCU_CLOCK\n";
print "PLATFORM=$MAKEFILE_OPTIONS_LOCAL->{'platform'}, MCU_CLOCK=$MAKEFILE_OPTIONS_LOCAL->{'mcu_clock'}\n";
#return %MAKEFILE_OPTIONS_LOCAL;
}

sub Parse_Memory_Device
{
	open CUSTOM_MEMORY_DEVICE_HDR, "<$CUSTOM_MEMORY_DEVICE_HDR" or &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: file error!", __FILE__, __LINE__);

my ($MAKEFILE_OPTIONS_LOCAL, $PART_NUMBER_LOCAL, $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $MCP_LIST_LOCAL) = @_;
my $cs;
$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_SIP_ENTRY_COUNT} = 0;
while (<CUSTOM_MEMORY_DEVICE_HDR>)
{
   # matching the following lines
   # "#define MEMORY_DEVICE_TYPE          NOR_RAM_MCP"
   # "#define FLASH_ACCESS_TYPE           ASYNC_ACCESS"
   # "#define RAM_ACCESS_TYPE             ASYNC_ACCESS"
   # "#define CS0_PART_NUMBER             RD38F3040L0ZBQ0"
   # "#define PROJECT_EXCEPTED_RAM_LIMIT  0x001C0000"
   # "#define PROJECT_EXCEPTED_CODE_LIMIT 0x00040000"

   # error-checking
   if (/^#if|^#ifdef|^#ifndef|^#elif|^#else/)
   {
      &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Not allowed to set conditional keywords $_ in custom_MemoryDevice.h!", __FILE__, __LINE__)
          unless (/^#ifndef\s+__CUSTOM_MEMORYDEVICE__/);
   }

   if (/^#define\s+(\w+)\s+\(([\w|\-]*)\)/ || /^#define\s+(\w+)\s+([\w|\-]*)/)
   {
      &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: $1 redefined in custom_MemoryDevice.h!", __FILE__, __LINE__) if defined($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{$1});
      if ((!defined $2) or ($2 eq ''))
      {
          $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{$1} = 'TRUE';
      }
      else
      {
          $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{$1} = $2;
          #print "$1 => $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{$1}\n";
      }
      
      my $option = $1;
      my $content = $2;
      if ($option =~ /COMBO_MEM(\d+)_CS(\d+)_PART_NUMBER/)
      {
         next if ((!defined $MAKEFILE_OPTIONS_LOCAL->{'combo_memory_support'}) or ($MAKEFILE_OPTIONS_LOCAL->{'combo_memory_support'} eq 'FALSE'));
         &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: COMBO_MEM_ENTRY_COUNT needs to be defined when COMBO_MEMORY_SUPPORT is turned on!", __FILE__, __LINE__) if (!defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT});
         my %TMP_PART_NUMBER;
         my $mcp_idx = $1;
         $cs = $2;
         if(($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6255') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6280'))
         {
         	      if (($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPSDRAM') or ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR') or ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR2')or ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'DISCRETE_NAND') or ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH'))
               {
                  &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: All MCPs should use the same CS for COMBO_MEMORY_SUPPORT!", __FILE__, __LINE__) if (($$LPSDRAM_CHIP_SELECT_LOCAL != 0xFF) and ($$LPSDRAM_CHIP_SELECT_LOCAL != $cs));
                  $$LPSDRAM_CHIP_SELECT_LOCAL = $cs;
                  &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Only CS0 or CS1 is allowed for LPSDRAM/LPDDR/LPDDR2!", __FILE__, __LINE__) if (($$LPSDRAM_CHIP_SELECT_LOCAL != 0) && ($$LPSDRAM_CHIP_SELECT_LOCAL != 1));
                  if ($content =~ /([\w|\-]+)_([A-Za-z0-9]+EVB)/ or $content =~ /([\w|\-]+)_(Sapphire28)/i)
                  {
                     $TMP_PART_NUMBER{$cs} = $1;
                  }
                  else
                  {
                     $TMP_PART_NUMBER{$cs} = $content;
                  }
               }
               else
               {
                  $TMP_PART_NUMBER{$cs} = $content;
               }
         }
         else
         {
         if (($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPSDRAM') or ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR') or ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR2'))
         {
            &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: All MCPs should use the same CS for COMBO_MEMORY_SUPPORT!", __FILE__, __LINE__) if (($$LPSDRAM_CHIP_SELECT_LOCAL != 0xFF) and ($$LPSDRAM_CHIP_SELECT_LOCAL != $cs));
            $$LPSDRAM_CHIP_SELECT_LOCAL = $cs;
            &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Only CS0 or CS1 is allowed for LPSDRAM/LPDDR/LPDDR2!", __FILE__, __LINE__) if (($$LPSDRAM_CHIP_SELECT_LOCAL != 0) && ($$LPSDRAM_CHIP_SELECT_LOCAL != 1));
            if ($content =~ /([\w|\-]+)_([A-Za-z0-9]+EVB)/ or $content =~ /([\w|\-]+)_(Sapphire28)/i)
            {
               $TMP_PART_NUMBER{$cs} = $1;
            }
            else
            {
               $TMP_PART_NUMBER{$cs} = $content;
            }
         }
         else
         {
            $TMP_PART_NUMBER{$cs} = $content;
         }
         }
         if (defined $MCP_LIST_LOCAL->[$mcp_idx])
         {
            if (defined $MCP_LIST_LOCAL->[$mcp_idx]->{$cs})
            {
               &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: COMBO_MEM$mcp_idx\_CS$cs\_PART_NUMBER multiply defined!", __FILE__, __LINE__);
            }
            else
            {
               $MCP_LIST_LOCAL->[$mcp_idx]->{$cs} = $TMP_PART_NUMBER{$cs};
            }
         }
         else
         {
            $MCP_LIST_LOCAL->[$mcp_idx] = \%TMP_PART_NUMBER;
         }
      }
      elsif ($option =~ /CS(\d+)_PART_NUMBER/)
      {
         next if ($MAKEFILE_OPTIONS_LOCAL->{'combo_memory_support'} eq 'TRUE');  # when COMBO_MEMORY_SUPPORT is turned on, CSx_PART_NUMBER is ignored
         my $cs = $1;
         if(($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6255') || ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6280'))
         {
         	   if (($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPSDRAM') or ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR') or ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR2') or ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'DISCRETE_NAND') or ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH'))
             {
                $$LPSDRAM_CHIP_SELECT_LOCAL = $cs;
                &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Only CS0 or CS1 is allowed for LPSDRAM/LPDDR/LPDDR2!", __FILE__, __LINE__) if (($$LPSDRAM_CHIP_SELECT_LOCAL != 0) && ($$LPSDRAM_CHIP_SELECT_LOCAL != 1));
                if ($content =~ /([\w|\-]+)_([A-Za-z0-9]+EVB)/ or $content =~ /([\w|\-]+)_(Sapphire28)/i)
                {
                   $PART_NUMBER_LOCAL->{$cs} = $1;
                }
                else
                {
                   $PART_NUMBER_LOCAL->{$cs} = $content;
                }
             }
             else
             {
                $PART_NUMBER_LOCAL->{$cs} = $content;
             }
         }
         else
         {
         if (($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPSDRAM') or ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR') or ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR2'))
         {
            $$LPSDRAM_CHIP_SELECT_LOCAL = $cs;
            &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Only CS0 or CS1 is allowed for LPSDRAM/LPDDR/LPDDR2!", __FILE__, __LINE__) if (($$LPSDRAM_CHIP_SELECT_LOCAL != 0) && ($$LPSDRAM_CHIP_SELECT_LOCAL != 1));
            if ($content =~ /([\w|\-]+)_([A-Za-z0-9]+EVB)/ or $content =~ /([\w|\-]+)_(Sapphire28)/i)
            {
               $PART_NUMBER_LOCAL->{$cs} = $1;
            }
            else
            {
               $PART_NUMBER_LOCAL->{$cs} = $content;
            }
         }
         else
         {
            $PART_NUMBER_LOCAL->{$cs} = $content;
         }
      }
   }
}
}

$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_FDM4_ESB_PARAMETER_ERASE_QUEUE_SIZE}   = (defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_FDM4_ESB_PARAMETER_ERASE_QUEUE_SIZE}) ? $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_FDM4_ESB_PARAMETER_ERASE_QUEUE_SIZE} : 5;
$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_PARAMETER_SYSTEM_DRIVE_RESERVED_BLOCK} = (defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_PARAMETER_SYSTEM_DRIVE_RESERVED_BLOCK}) ? $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{NOR_PARAMETER_SYSTEM_DRIVE_RESERVED_BLOCK} : 3;



# No Combo MCP case
if (defined %$PART_NUMBER_LOCAL)
{
    $MCP_LIST_LOCAL->[1] = $PART_NUMBER_LOCAL;
    $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT} = 1;
}

# COMBO_MEM_ENTRY_COUNT cannot exceed the upper limit MAX_COMBO_MEM_ENTRY_COUNT
if ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT} > $MAX_COMBO_MEM_ENTRY_COUNT)
{
    &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: COMBO_MEM_ENTRY_COUNT has exceeded its upper limit $MAX_COMBO_MEM_ENTRY_COUNT! Please reduce COMBO_MEM_ENTRY_COUNT!", __FILE__, __LINE__);
}

# COMBO_MEM_ENTRY_COUNT and the number of COMBO_MEMxx_CSx_PART_NUMBER does not match
if ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT} != $#{$MCP_LIST_LOCAL})
{
    &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: COMBO_MEM_ENTRY_COUNT and the number of COMBO_MEMxx_CSx_PART_NUMBER does not match!", __FILE__, __LINE__);
}

close CUSTOM_MEMORY_DEVICE_HDR;

}

#****************************************************************************
# parse EMI database to get EMI settings
#****************************************************************************
sub Parse_MDL
{
	my ($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $MDL_INFO_LIST_LOCAL, $MEMORY_DEVICE_LIST_XLS_LOCAL, $MEMORY_DEVICE_LIST_INT_XLS_LOCAL) = @_;
  my ($result, $result0, $result1);
if ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH')
{
    my (%TMP_PART_NUMBER_CS0, %TMP_PART_NUMBER_CS1);
    
    if ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6252')
    {
      ### for MT6252D SIP serial flash
      if ((exists $MAKEFILE_OPTIONS_LOCAL->{'sip_serial_flash_size'}) and ($MAKEFILE_OPTIONS_LOCAL->{'sip_serial_flash_size'} ne 'NONE'))
      {
          my $final_sip_count = 0;
          my $final_sip_count_int = 0;
          my $sip_pattern;
          if ($MAKEFILE_OPTIONS_LOCAL->{'sip_serial_flash_size'} eq '16M_BITS')
          {
              $sip_pattern = "MTKSIP_6252_SF_16_\\d+";
          }
          elsif ($MAKEFILE_OPTIONS{'sip_serial_flash_size'} eq '32M_BITS')
          {
              $sip_pattern = "MTKSIP_6252_SF_32_\\d+";
          }
          else
          {
              &error_handler("$THEMF: Invalid SIP_SERIAL_FLASH_SIZE configuration in makefile!", __FILE__, __LINE__);
          }
          my (%sip_hash, %sip_hash_int);
          $result0 = &get_sip_info($$MEMORY_DEVICE_LIST_XLS_LOCAL, 'SERIAL_FLASH', $IDX_COUNT, 2, $sip_pattern, 0, \%sip_hash, \%MEM_DEV_LIST_INDEX, \$final_sip_count);
          for (1..$final_sip_count)
          {
              $MDL_INFO_LIST_LOCAL->[$_]->{0} = $sip_hash{$_};
          }
          if ($MAKEFILE_OPTIONS_LOCAL->{'demo_project'} eq 'TRUE')
          {
              $result1 = &get_sip_info($$MEMORY_DEVICE_LIST_INT_XLS_LOCAL, 'SERIAL_FLASH', $IDX_COUNT, 2, $sip_pattern, 0, \%sip_hash_int, \%MEM_DEV_LIST_INDEX, \$final_sip_count_int);
              for (1..$final_sip_count_int)
              {
                my $tmp_sip_idx = $_+$final_sip_count;
                  $MDL_INFO_LIST_LOCAL->[$tmp_sip_idx]->{0} = $sip_hash_int{$_};
              }
          }
          $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT } = $final_sip_count + $final_sip_count_int;
          &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: SIP not found!", __FILE__, __LINE__) if ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT} == 0);
          print "COMBO_MEM_ENTRY_COUNT=$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT}\n" if ($DebugPrint == 1);
      }
      else
      {
        for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
          {
              $TMP_PART_NUMBER_CS0{0} = $MCP_LIST[$_]->{0};
              $result0 = &get_info($MEMORY_DEVICE_LIST_XLS, 'SERIAL_FLASH', $IDX_COUNT, 2, \%TMP_PART_NUMBER_CS0, &ret_tmp_hash_ref($_), \%MEM_DEV_LIST_INDEX);
              if (($result0 ne 'TRUE'))# and ($MAKEFILE_OPTIONS_LOCAL->{'demo_project'} eq 'TRUE'))
              {
                  $result0 = &get_info($MEMORY_DEVICE_LIST_INT_XLS, 'SERIAL_FLASH', $IDX_COUNT, 2, \%TMP_PART_NUMBER_CS0, &ret_tmp_hash_ref($_), \%MEM_DEV_LIST_INDEX);
              }
              &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Part Number $TMP_PART_NUMBER_CS0{0} not found!", __FILE__, __LINE__) if ($result0 ne 'TRUE');
              &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Device not allowed to set NOR_RAM_MCP type!", __FILE__, __LINE__)     if (($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP') && ($MDL_INFO_LIST_LOCAL->[$_]->{1}->{'DRAM'} eq 'YES'));
              $MDL_INFO_LIST_LOCAL->[$_] = &ret_tmp_hash_ref($_);
          }
      }
        
        ### MT6252 pSRAM SIP
        my $final_sip_count = 0;
        my $final_sip_count_int = 0;
        my $sip_pattern = "MTKSIP\\d+";
        if (defined $MAKEFILE_OPTIONS_LOCAL->{'sip_ram_size'})
        {
            if ($MAKEFILE_OPTIONS_LOCAL->{'sip_ram_size'} eq '32M_BITS')
            {
                $sip_pattern = "MTKSIP\\d+";
            }
            elsif ($MAKEFILE_OPTIONS_LOCAL->{'sip_ram_size'} eq '64M_BITS')
            {
                $sip_pattern = "MTKSIP_6252_PSRAM_64_\\d+";
            }
            else
            {
                &error_handler("$THEMF: Invalid SIP_RAM_SIZE configuration in makefile!", __FILE__, __LINE__);
            }
        }
        my (%sip_hash, %sip_hash_int);
        $result1 = &get_sip_info($MEMORY_DEVICE_LIST_XLS, 'NOR_RAM_MCP', $IDX_COUNT, 2, $sip_pattern, 1, \%sip_hash, \%MEM_DEV_LIST_INDEX, \$final_sip_count);
        for (1..$final_sip_count)
        {
            $MDL_INFO_LIST_LOCAL->[$_]->{1} = $sip_hash{$_};
        }
        
        if ($MAKEFILE_OPTIONS_LOCAL->{'demo_project'} eq 'TRUE')
        {
        	  
            $result1 = &get_sip_info($MEMORY_DEVICE_LIST_INT_XLS, 'NOR_RAM_MCP', $IDX_COUNT, 2, $sip_pattern, 1, \%sip_hash_int, \%MEM_DEV_LIST_INDEX, \$final_sip_count_int);
            
            for (1..$final_sip_count_int)
            {
            	my $tmp_sip_idx = $_+$final_sip_count;
                $MDL_INFO_LIST_LOCAL->[$tmp_sip_idx]->{1} = $sip_hash_int{$_};
            }
        }
        $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_SIP_ENTRY_COUNT} = $final_sip_count + $final_sip_count_int;
        &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: SIP not found!", __FILE__, __LINE__) if ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_SIP_ENTRY_COUNT} == 0);
        print "COMBO_SIP_ENTRY_COUNT=$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_SIP_ENTRY_COUNT}\n" if ($DebugPrint == 1);
    }
    elsif ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6251')
    {
        for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
        {
            $TMP_PART_NUMBER_CS0{0} = $MCP_LIST[$_]->{0};
            $result0 = &get_info($$MEMORY_DEVICE_LIST_XLS_LOCAL, 'SERIAL_FLASH', $IDX_COUNT, 2, \%TMP_PART_NUMBER_CS0, &ret_tmp_hash_ref($_), \%MEM_DEV_LIST_INDEX);
            if (($result0 ne 'TRUE'))# and ($MAKEFILE_OPTIONS_LOCAL->{'demo_project'} eq 'TRUE'))
            {
                $result0 = &get_info($$MEMORY_DEVICE_LIST_INT_XLS_LOCAL, 'SERIAL_FLASH', $IDX_COUNT, 2, \%TMP_PART_NUMBER_CS0, &ret_tmp_hash_ref($_), \%MEM_DEV_LIST_INDEX);
            }
            &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Part Number $TMP_PART_NUMBER_CS0{0} not found!", __FILE__, __LINE__) if ($result0 ne 'TRUE');
            &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Device not allowed to set NOR_RAM_MCP type!", __FILE__, __LINE__)     if (($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP') && ($MDL_INFO_LIST_LOCAL->[$_]->{1}->{'DRAM'} eq 'YES'));
            $MDL_INFO_LIST_LOCAL->[$_] = &ret_tmp_hash_ref($_);
        }
        print "COMBO_SIP_ENTRY_COUNT=$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_SIP_ENTRY_COUNT}\n" if ($DebugPrint == 1);
    }
    elsif ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6255')
    {
    	  for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
        {
              $TMP_PART_NUMBER_CS0{0} = $MCP_LIST[$_]->{0};
              $result0 = &get_info($MEMORY_DEVICE_LIST_XLS, 'SERIAL_FLASH', 3, 2, \%TMP_PART_NUMBER_CS0, &ret_tmp_hash_ref($_), \%MEM_DEV_LIST_INDEX);
              if (($result0 ne 'TRUE'))
              {
                  $result0 = &get_info($MEMORY_DEVICE_LIST_INT_XLS, 'SERIAL_FLASH', 3, 2, \%TMP_PART_NUMBER_CS0, &ret_tmp_hash_ref($_), \%MEM_DEV_LIST_INDEX);
              }
              &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Part Number $TMP_PART_NUMBER_CS0{0} not found!", __FILE__, __LINE__) if ($result0 ne 'TRUE');
              &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Device not allowed to set LPDDR type!", __FILE__, __LINE__)     if ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR');
              $MDL_INFO_LIST_LOCAL->[$_] = &ret_tmp_hash_ref($_);
        }
        
         ### MT6255 DDR SIP
        my $final_sip_count = 0;
        my $final_sip_count_int = 0;
        my $sip_pattern = "MTKSIP\\d+";
        if (defined $MAKEFILE_OPTIONS_LOCAL->{'sip_ram_size'})
        {
            if ($MAKEFILE_OPTIONS_LOCAL->{'sip_ram_size'} eq '256M_BITS')
            {
                $sip_pattern = "MTKSIP_6255_LPDDR_256_\\d+";
            }
            else
            {
                &error_handler("$THEMF: Invalid SIP_RAM_SIZE configuration in makefile!", __FILE__, __LINE__);
            }
        }
        my (%sip_hash, %sip_hash_int);
        $result1 = &get_sip_info($MEMORY_DEVICE_LIST_XLS, 'LPDDR', $IDX_COUNT, 2, $sip_pattern, 0, \%sip_hash, \%MEM_DEV_LIST_INDEX, \$final_sip_count);
        for (1..$final_sip_count)
        {
            $MDL_INFO_LIST_LOCAL->[$_]->{1} = $sip_hash{$_};
        }
        if ($MAKEFILE_OPTIONS_LOCAL->{'demo_project'} eq 'TRUE')
        { 
            $result1 = &get_sip_info($MEMORY_DEVICE_LIST_INT_XLS, 'LPDDR', $IDX_COUNT, 2, $sip_pattern, 0, \%sip_hash_int, \%MEM_DEV_LIST_INDEX, \$final_sip_count_int);
                
            for (1..$final_sip_count_int)
            {
               my $tmp_sip_idx = $_+$final_sip_count;
               $MDL_INFO_LIST_LOCAL->[$tmp_sip_idx]->{1} = $sip_hash_int{$_};
            }
        }
        $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_SIP_ENTRY_COUNT} = $final_sip_count + $final_sip_count_int;
        &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: SIP not found!", __FILE__, __LINE__) if ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_SIP_ENTRY_COUNT} == 0);
        print "COMBO_SIP_ENTRY_COUNT=$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_SIP_ENTRY_COUNT}\n" if ($DebugPrint == 1);
    }
    else
    {
        for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
        {
            $TMP_PART_NUMBER_CS0{0} = $MCP_LIST[$_]->{0};
            $TMP_PART_NUMBER_CS1{1} = $MCP_LIST[$_]->{1};
            $result0 = &get_info($$MEMORY_DEVICE_LIST_XLS_LOCAL, 'SERIAL_FLASH', $IDX_COUNT, 2, \%TMP_PART_NUMBER_CS0, &ret_tmp_hash_ref($_), \%MEM_DEV_LIST_INDEX);
            $result1 = &get_info($$MEMORY_DEVICE_LIST_XLS_LOCAL, 'NOR_RAM_MCP', $IDX_COUNT, 2, \%TMP_PART_NUMBER_CS1, &ret_tmp_hash_ref($_), \%MEM_DEV_LIST_INDEX);
            if (($result0 ne 'TRUE'))# and ($MAKEFILE_OPTIONS_LOCAL->{'demo_project'} eq 'TRUE'))
            {
                $result0 = &get_info($$MEMORY_DEVICE_LIST_INT_XLS_LOCAL, 'SERIAL_FLASH', $IDX_COUNT, 2, \%TMP_PART_NUMBER_CS0, &ret_tmp_hash_ref($_), \%MEM_DEV_LIST_INDEX);
            }
            if (($result1 ne 'TRUE'))# and ($MAKEFILE_OPTIONS_LOCAL->{'demo_project'} eq 'TRUE'))
            {
                $result1 = &get_info($$MEMORY_DEVICE_LIST_INT_XLS_LOCAL, 'NOR_RAM_MCP', $IDX_COUNT, 2, \%TMP_PART_NUMBER_CS1, &ret_tmp_hash_ref($_), \%MEM_DEV_LIST_INDEX);
            }
            if (($result0 ne 'TRUE') or ($result1 ne 'TRUE'))
            {
                my $p_number = ($result0 ne 'TRUE')
                                ? $TMP_PART_NUMBER_CS0{0}
                                : $TMP_PART_NUMBER_CS0{1};
                &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Part Number $p_number not found!", __FILE__, __LINE__);
            }
            &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Device not allowed to set NOR_RAM_MCP type!", __FILE__, __LINE__)     if (($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP') && ($MDL_INFO_LIST_LOCAL->[$_]->{1}->{'DRAM'} eq 'YES'));
            $MDL_INFO_LIST_LOCAL->[$_] = &ret_tmp_hash_ref($_);
        }
    }
}
elsif ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP')
{
    for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
    {
        $result = &get_info($$MEMORY_DEVICE_LIST_XLS_LOCAL, 'NOR_RAM_MCP', $IDX_COUNT, 2, $MCP_LIST[$_], &ret_tmp_hash_ref($_), \%MEM_DEV_LIST_INDEX);
        if (($result ne 'TRUE'))# and ($MAKEFILE_OPTIONS_LOCAL->{'demo_project'} eq 'TRUE'))
        {
            $result = &get_info($$MEMORY_DEVICE_LIST_INT_XLS_LOCAL, 'NOR_RAM_MCP', $IDX_COUNT, 2, $MCP_LIST[$_], &ret_tmp_hash_ref($_), \%MEM_DEV_LIST_INDEX);
        }
        if ($result ne 'TRUE')
        {
            my $p_number;
            if (defined $MCP_LIST[$_]->{0})
            {
                $p_number = $MCP_LIST[$_]->{0};
            }
            else
            {
                $p_number = $MCP_LIST[$_]->{1};
            }
            &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Part Number $p_number not found!", __FILE__, __LINE__);
        }
        &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Device not allowed to set NOR_RAM_MCP type!", __FILE__, __LINE__)     if (($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP') && ($MDL_INFO_LIST_LOCAL->[$_]->{1}->{'DRAM'} eq 'YES'));
        $MDL_INFO_LIST_LOCAL->[$_] = &ret_tmp_hash_ref($_);
    }
} 
elsif ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPSDRAM')
{
    for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
    {
        $result = &get_info($$MEMORY_DEVICE_LIST_XLS_LOCAL, 'LPSDRAM', $IDX_COUNT, 2, $MCP_LIST[$_], &ret_tmp_hash_ref($_), \%MEM_DEV_LIST_INDEX);
        if (($result ne 'TRUE'))# and ($MAKEFILE_OPTIONS_LOCAL->{'demo_project'} eq 'TRUE'))
        {
            $result = &get_info($$MEMORY_DEVICE_LIST_INT_XLS_LOCAL, 'LPSDRAM', $IDX_COUNT, 2, $MCP_LIST[$_], &ret_tmp_hash_ref($_), \%MEM_DEV_LIST_INDEX);
        }
        if ($result ne 'TRUE')
        {
            my $p_number;
            if (defined $MCP_LIST[$_]->{0})
            {
                $p_number = $MCP_LIST[$_]->{0};
            }
            else
            {
                $p_number = $MCP_LIST[$_]->{1};
            }
            &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Part Number $p_number not found!", __FILE__, __LINE__);
        }
        &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Device not allowed to set NOR_RAM_MCP type!", __FILE__, __LINE__)     if (($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP') && ($MDL_INFO_LIST_LOCAL->[$_]->{1}->{'DRAM'} eq 'YES'));
        $MDL_INFO_LIST_LOCAL->[$_] = &ret_tmp_hash_ref($_);
    }
}
elsif ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR')
{
	  if($OS_ENV eq "MSWin32")
	  {
    for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
    {
        $result = &get_info($$MEMORY_DEVICE_LIST_XLS_LOCAL, 'LPDDR', $IDX_COUNT, 2, $MCP_LIST[$_], &ret_tmp_hash_ref($_), \%MEM_DEV_LIST_INDEX);
        if (($result ne 'TRUE'))
        {
            $result = &get_info($$MEMORY_DEVICE_LIST_INT_XLS_LOCAL, 'LPDDR', $IDX_COUNT, 2, $MCP_LIST[$_], &ret_tmp_hash_ref($_), \%MEM_DEV_LIST_INDEX);
        }
        if ($result ne 'TRUE')
        {
            my $p_number;
            if (defined $MCP_LIST[$_]->{0})
            {
                $p_number = $MCP_LIST[$_]->{0};
            }
            else
            {
                $p_number = $MCP_LIST[$_]->{1};
            }
            &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Part Number $p_number not found!", __FILE__, __LINE__);
        }
        $MDL_INFO_LIST_LOCAL->[$_] = &ret_tmp_hash_ref($_);
    }
}
	  else
	  {
	  	    for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
         {
             $result = &get_info($$MEMORY_DEVICE_LIST_XLS_LOCAL, 'LPDDR', $IDX_COUNT, 1, $MCP_LIST[$_], &ret_tmp_hash_ref($_), \%MEM_DEV_LIST_INDEX);
             if (($result ne 'TRUE'))
             {
             	   print "result : $result\n";
                 $result = &get_info($$MEMORY_DEVICE_LIST_INT_XLS_LOCAL, 'LPDDR', $IDX_COUNT, 1, $MCP_LIST[$_], &ret_tmp_hash_ref($_), \%MEM_DEV_LIST_INDEX);
             }
             if ($result ne 'TRUE')
             {
                 my $p_number;
                 if (defined $MCP_LIST[$_]->{0})
                 {
                     $p_number = $MCP_LIST[$_]->{0};
                 }
                 else
                 {
                     $p_number = $MCP_LIST[$_]->{1};
                 }
                 &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Part Number $p_number not found!", __FILE__, __LINE__);
             }
             $MDL_INFO_LIST_LOCAL->[$_] = &ret_tmp_hash_ref($_);
         }
	  }
    
}
elsif ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR2')
{
    if($OS_ENV eq "MSWin32")
	  {
    for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
    {
        $result = &get_info($$MEMORY_DEVICE_LIST_XLS_LOCAL, 'LPDDR2', $IDX_COUNT, 2, $MCP_LIST[$_], &ret_tmp_hash_ref($_), \%MEM_DEV_LIST_INDEX);
        if (($result ne 'TRUE'))
        {
            $result = &get_info($$MEMORY_DEVICE_LIST_INT_XLS_LOCAL, 'LPDDR2', $IDX_COUNT, 2, $MCP_LIST[$_], &ret_tmp_hash_ref($_), \%MEM_DEV_LIST_INDEX);
        }
        if ($result ne 'TRUE')
        {
            my $p_number;
            if (defined $MCP_LIST[$_]->{0})
            {
                $p_number = $MCP_LIST[$_]->{0};
            }
            else
            {
                $p_number = $MCP_LIST[$_]->{1};
            }
            &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Part Number $p_number not found!", __FILE__, __LINE__);
        }
        $MDL_INFO_LIST_LOCAL->[$_] = &ret_tmp_hash_ref($_);
    }
}
	  else
	  {
	  	    for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
         {
             $result = &get_info($$MEMORY_DEVICE_LIST_XLS_LOCAL, 'LPDDR2', $IDX_COUNT, 1, $MCP_LIST[$_], &ret_tmp_hash_ref($_), \%MEM_DEV_LIST_INDEX);
             if (($result ne 'TRUE'))
             {
             	   print "result : $result\n";
                 $result = &get_info($$MEMORY_DEVICE_LIST_INT_XLS_LOCAL, 'LPDDR2', $IDX_COUNT, 1, $MCP_LIST[$_], &ret_tmp_hash_ref($_), \%MEM_DEV_LIST_INDEX);
             }
             if ($result ne 'TRUE')
             {
                 my $p_number;
                 if (defined $MCP_LIST[$_]->{0})
                 {
                     $p_number = $MCP_LIST[$_]->{0};
                 }
                 else
                 {
                     $p_number = $MCP_LIST[$_]->{1};
                 }
                 &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Part Number $p_number not found!", __FILE__, __LINE__);
             }
             $MDL_INFO_LIST_LOCAL->[$_] = &ret_tmp_hash_ref($_);
         }
	  }
}
elsif ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'DISCRETE_NAND')
{
	  for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
    {
        $result = &get_info($$MEMORY_DEVICE_LIST_XLS_LOCAL, 'DISCRETE_NAND', $IDX_COUNT, 2, $MCP_LIST[$_], &ret_tmp_hash_ref($_), \%MEM_DEV_LIST_INDEX);
        if (($result ne 'TRUE'))
        {
            $result = &get_info($$MEMORY_DEVICE_LIST_INT_XLS_LOCAL, 'DISCRETE_NAND', $IDX_COUNT, 2, $MCP_LIST[$_], &ret_tmp_hash_ref($_), \%MEM_DEV_LIST_INDEX);
        }
        if ($result ne 'TRUE')
        {
            my $p_number;
            if (defined $MCP_LIST[$_]->{0})
            {
                $p_number = $MCP_LIST[$_]->{0};
            }
            else
            {
                $p_number = $MCP_LIST[$_]->{1};
            }
            &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Part Number $p_number not found!", __FILE__, __LINE__);
        }
        $MDL_INFO_LIST_LOCAL->[$_] = &ret_tmp_hash_ref($_);
        print "$_-> $MDL_INFO_LIST_LOCAL->[$_]->{0}->{'NAND Size(MB)'}\n";
    }
    
         ### MT6255 DDR SIP
        my $final_sip_count = 0;
        my $final_sip_count_int = 0;
        my $sip_pattern = "MTKSIP\\d+";
        if (defined $MAKEFILE_OPTIONS_LOCAL->{'sip_ram_size'})
        {
            if ($MAKEFILE_OPTIONS_LOCAL->{'sip_ram_size'} eq '256M_BITS')
            {
                $sip_pattern = "MTKSIP_6255_LPDDR_256_\\d+";
            }
            else
            {
                &error_handler("$THEMF: Invalid SIP_RAM_SIZE configuration in makefile!", __FILE__, __LINE__);
            }
        }
        my (%sip_hash, %sip_hash_int);
        
        $result1 = &get_sip_info($MEMORY_DEVICE_LIST_XLS, 'LPDDR', $IDX_COUNT, 2, $sip_pattern, 0, \%sip_hash, \%MEM_DEV_LIST_INDEX, \$final_sip_count);
        for (1..$final_sip_count)
        {
            $MDL_INFO_LIST_LOCAL->[$_]->{1} = $sip_hash{$_};
        }
        if ($MAKEFILE_OPTIONS_LOCAL->{'demo_project'} eq 'TRUE')
        { 
           $result1 = &get_sip_info($MEMORY_DEVICE_LIST_INT_XLS, 'LPDDR', $IDX_COUNT, 2, $sip_pattern, 0, \%sip_hash_int, \%MEM_DEV_LIST_INDEX, \$final_sip_count_int);
               
           for (1..$final_sip_count_int)
           {
              my $tmp_sip_idx = $_+$final_sip_count;
              $MDL_INFO_LIST_LOCAL->[$tmp_sip_idx]->{1} = $sip_hash_int{$_};
           }
        }
        $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_SIP_ENTRY_COUNT} = $final_sip_count + $final_sip_count_int;
        &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: SIP not found!", __FILE__, __LINE__) if ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_SIP_ENTRY_COUNT} == 0);
        print "COMBO_SIP_ENTRY_COUNT=$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_SIP_ENTRY_COUNT}\n" if ($DebugPrint == 1);
}
else
{
    undef $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE};
}
&error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Incorrect memory device type!", __FILE__, __LINE__) unless $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE};
}

#****************************************************************************
# check consistency among FEATURE, MEMORY_DEVICE_TYPE, PLATFORM, MCU_CLOCK and MemoryDeviceList data
#****************************************************************************
sub Decide_MDClock
{
	my ($MAKEFILE_OPTIONS_LOCAL,$CUSTOM_MEM_DEV_OPTIONS_LOCAL, $LPSDRAM_CHIP_SELECT_LOCAL) = @_;
	
my $emi_force_clk  = 0;
my $sfi_force_clk  = 0;
if ((defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{EMI_CLK}) and $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{EMI_CLK} ne 'DEFAULT')
{
    if (($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{EMI_CLK} eq '104M') or ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{EMI_CLK} eq '52M'))
    {
        #&error_handler("$CUSTOM_MEMORY_DEVICE_HDR: EMI_CLK can only be configured as 104M or 52M on MT6253D. Please configure EMI_CLK as DEFAULT on platforms other than MT6253D!", __FILE__, __LINE__) if ($MAKEFILE_OPTIONS_LOCAL->{'platform'} ne 'MT6253');
        $emi_clk_config = $emi_force_clk = ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{EMI_CLK} eq '104M') ? 104 : 52;
    }
    elsif (($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{EMI_CLK} eq '166M') or ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{EMI_CLK} eq '200M'))
    {
        #&error_handler("$CUSTOM_MEMORY_DEVICE_HDR: EMI_CLK can only be configured as 166M or 200M on MT6276. Please configure EMI_CLK as DEFAULT on platforms other than MT6276!", __FILE__, __LINE__) if (($MAKEFILE_OPTIONS_LOCAL->{'platform'} ne 'MT6276') and ($MAKEFILE_OPTIONS_LOCAL->{'platform'} ne 'MT6256'));
        $emi_clk_config = $emi_force_clk = ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{EMI_CLK} eq '166M') ? 166 : 200;
    }
    else
    {
        &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Please configure EMI_CLK as 104M, 52M, or DEFAULT!", __FILE__, __LINE__) if ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6253');
        &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Please configure EMI_CLK as 166M, 200M, or DEFAULT!", __FILE__, __LINE__) if ($MAKEFILE_OPTIONS_LOCAL->{'platform'} eq 'MT6276');
        &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Please configure EMI_CLK as DEFAULT on platforms other than MT6253D or MT6276!", __FILE__, __LINE__);
    }
}
if ((defined $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{SFI_CLK}) and $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{SFI_CLK}ne 'DEFAULT')
{
    if ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{SFI_CLK} eq '104M')
    {
        &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: $MAKEFILE_OPTIONS_LOCAL->{'platform'} does not support SFI clock as 104MHz! Please configure SFI_CLK as DEFAULT!", __FILE__, __LINE__) if ($BBtbl_SFI_FAST_CLK{$MAKEFILE_OPTIONS_LOCAL->{'platform'}} != 104);
        $sfi_clk_config = $sfi_force_clk = 104;
    }
    elsif ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{SFI_CLK} eq '78M')
    {
        $sfi_clk_config = $sfi_force_clk = 78;
    }
    else
    {
        &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Please configure SFI_CLK as 104M, 78M, or DEFAULT!", __FILE__, __LINE__);
    }
}

if ( $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'NOR_RAM_MCP'
  && ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{FLASH_ACCESS_TYPE} eq 'SYNC_ACCESS') && ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{RAM_ACCESS_TYPE} eq 'SYNC_ACCESS') )
{
    if ($BBtbl_SYNC_ACCESS{$MAKEFILE_OPTIONS_LOCAL->{'platform'}})
    {
        my $emi_104_support = 1;  # assume all devices can support 104; set as 0 if found not support
        my $emi_52_support  = 1;  # assume all devices can support 52; set as 0 if found not support
        
        ### Check if all devices can support the required clock
        if ($emi_force_clk != 0)  # force specific clock
        {
            for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
            {
                if ((!defined &Lookup_SYNC_EMI_address_by_IDX_CS_CLK_BB($_, 0, $emi_clk_config, $MAKEFILE_OPTIONS_LOCAL->{'platform'})) or (&Lookup_SYNC_EMI_address_by_IDX_CS_CLK_BB($_, 0, $emi_clk_config, $MAKEFILE_OPTIONS_LOCAL->{'platform'}) eq 'x') or (&Lookup_SYNC_EMI_address_by_IDX_CS_CLK_BB($_, 0, $emi_clk_config, $MAKEFILE_OPTIONS_LOCAL->{'platform'}) eq ' '))  # unable to find the specified clock setting
                {
                    &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Device $_ not support $sfi_clk_config MHz settings!", __FILE__, __LINE__);
                }
            }
        }
        else
        {
            for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
            {
                if ((!defined &Lookup_SYNC_EMI_address_by_IDX_CS_CLK_BB($_, 0, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'})) or (&Lookup_SYNC_EMI_address_by_IDX_CS_CLK_BB($_, 0, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}) eq 'x') or (&Lookup_SYNC_EMI_address_by_IDX_CS_CLK_BB($_, 0, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}) eq ' '))  # unable to find 104MHz clock setting
                {
                    &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Device not support $emi_clk_config MHz Burst Access!", __FILE__, __LINE__) if (($MAKEFILE_OPTIONS_LOCAL->{'platform'} ne 'MT6253') and ($emi_clk_config == 104));
                    $emi_104_support = 0;
                }
                if ((!defined &Lookup_SYNC_EMI_address_by_IDX_CS_CLK_BB($_, 0, 52, $MAKEFILE_OPTIONS_LOCAL->{'platform'})) or (&Lookup_SYNC_EMI_address_by_IDX_CS_CLK_BB($_, 0, 52, $MAKEFILE_OPTIONS_LOCAL->{'platform'}) eq 'x') or (&Lookup_SYNC_EMI_address_by_IDX_CS_CLK_BB($_, 0, 52, $MAKEFILE_OPTIONS_LOCAL->{'platform'}) eq ' '))  # unable to find 52MHz clock setting
                {
                    &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Device not support $emi_clk_config MHz Burst Access!", __FILE__, __LINE__) if (($MAKEFILE_OPTIONS_LOCAL->{'platform'} ne 'MT6253') and ($emi_clk_config == 52));
                    $emi_52_support = 0;
                }
                if (($emi_104_support == 0) and ($emi_52_support == 0))
                {
                    &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Unable to find valid EMI settings!", __FILE__, __LINE__);
                }
                elsif ($emi_104_support != 0)
                {
                    $emi_clk_config = 104;
                }
                else  # emi_104_support == 0 and emi_52_support != 0
                {
                    $emi_clk_config = 52;
                }
            }
        }
        print "EMI_CLK configured as $emi_clk_config\n" if ($DebugPrint == 1);
    }
    else
    {
        &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Device not support Burst Access!", __FILE__, __LINE__);
    }
}
elsif ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH')
{
    my $sfi_104_support = 1;  # assume all devices can support 104; set as 0 if found not support
    my $sfi_78_support  = 1;  # assume all devices can support 78; set as 0 if found not support
    #print "test $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE}\n";
    ### Check if all devices can support the required clock
    if ($sfi_force_clk != 0)  # force specific clock
    {
        for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
        {
            if ((!defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, $sfi_clk_config, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', \@MDL_INFO_LIST)) or (&Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, $sfi_clk_config, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', \@MDL_INFO_LIST) eq 'x') or (&Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, $sfi_clk_config, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'DRIVING', \@MDL_INFO_LIST) eq ' '))  # unable to find the specified clock setting
            {
                &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Device $_ not support $sfi_clk_config MHz settings!", __FILE__, __LINE__);
            }
        }
    }
    else
    {
        for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
        {
            if ((!defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', \@MDL_INFO_LIST)) or (&Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', \@MDL_INFO_LIST) eq 'x') or (&Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 104, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', \@MDL_INFO_LIST) eq ' '))  # unable to find 104MHz clock setting
            {
                $sfi_104_support = 0;
            }
            if ((!defined &Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', \@MDL_INFO_LIST)) or (&Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', \@MDL_INFO_LIST) eq 'x') or (&Lookup_SFI_setting_by_IDX_CLK_BB_REG($_, 78, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'SFI_MAC_CTL', \@MDL_INFO_LIST) eq ' '))  # unable to find 104MHz clock setting
            {
                $sfi_78_support = 0;
            }
            if (($sfi_104_support == 0) and ($sfi_78_support == 0))
            {
                &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Unable to find valid SFI settings!", __FILE__, __LINE__);
            }
            elsif ($sfi_104_support != 0)
            {
                $sfi_clk_config = 104;
            }
            else  # sfi_104_support == 0 and sfi_78_support != 0
            {
                $sfi_clk_config = 78;
            }
        }
    }
    print "SFI_CLK configured as $sfi_clk_config\n" if ($DebugPrint == 1);
}
elsif (($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR') or ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR2'))
{
    my $emi_200_support = 1;  # assume all devices can support 200; set as 0 if found not support
    my $emi_166_support = 1;  # assume all devices can support 166; set as 0 if found not support
    
    ### Check if all devices can support the required clock
    if ($emi_force_clk != 0)  # force specific clock
    {
        for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
        {
            if ((!defined &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, $emi_clk_config, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DRV_A_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL)) or (&Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, $emi_clk_config, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DRV_A_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL) eq 'x') or (&Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, $emi_clk_config, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DRV_A_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL) eq ' '))  # unable to find the specified clock setting
            {
                &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Device $_ not support $emi_clk_config MHz settings!", __FILE__, __LINE__);
            }
        }
    }
    else
    {
        for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
        {
            if ((!defined &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DRV_A_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL)) or (&Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DRV_A_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL) eq 'x') or (&Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 200, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DRV_A_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL) eq ' '))  # unable to find 200MHz clock setting
            {
                $emi_200_support = 0;
            }
            if ((!defined &Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DRV_A_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL)) or (&Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DRV_A_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL) eq 'x') or (&Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG($_, 166, $MAKEFILE_OPTIONS_LOCAL->{'platform'}, 'EMI_DRV_A_VAL', $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL) eq ' '))  # unable to find 166MHz clock setting
            {
                $emi_166_support = 0;
            }
            if (($emi_200_support == 0) and ($emi_166_support == 0))
            {
                &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Unable to find valid EMI settings!", __FILE__, __LINE__);
            }
            elsif ($emi_200_support != 0)
            {
                $emi_clk_config = 200;
            }
            else  # sfi_104_support == 0 and sfi_78_support != 0
            {
                $emi_clk_config = 166;
            }
        }
    }
    print "EMI_CLK configured as $emi_clk_config\n" if ($DebugPrint == 1);
}

if (($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPSDRAM') || ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR') || ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR2'))
{
    &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: $MAKEFILE_OPTIONS_LOCAL->{'platform'} not support $CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE}!", __FILE__, __LINE__) if (not exists $BBtbl_LPSDRAM{$MAKEFILE_OPTIONS_LOCAL->{'platform'}});
}
}

#****************************************************************************
# subroutine:  fs_read_excel
# return:      hash of matching rows and indexing rows
# input:       $file:        excel file to be read
#              $sheet:       sheet to open
#              $idx_count:   the number of rows that are index rows
#              $search_col:  the column to be searched for the targets
#              $target_href: the target patterns to be searched
#****************************************************************************
sub fs_read_excel
{
    my ($file, $sheet, $idx_count, $search_col, $target_href, $MDL_BACKUP_LOAD_PATH_Local) = @_;
    my %rows;

    ### report error directly if MDL does not exist
    unless (-e $file)
    {
        &error_handler("$file: File does not exist! Please check with MVG or EMI Gen owner!", __FILE__, __LINE__);
    }
    
    ### copy and rename the current excel file to prevent concurrency build problem
    $MDL_BACKUP_LOAD_PATH_Local =~ s/^.\/|^\///;
    my $copied_file = $MDL_BACKUP_LOAD_PATH_Local;
    my $copied_file_temp = '';
    my $orifile = '';
    my $orifile_temp = '';
    my $curr_time_str = &get_CurrTime_str();
    if($file =~ /^(\w+.*?)\.xls$/)
    {
        $orifile_temp = $1;
        if($orifile_temp =~ /^(\w*.*?)tools(\w*.*?)MemoryDeviceList_(\w+)$/)
        {
        	    print "1:$1,2:$2,3:$3\n";
            	$orifile = $1 . $MDL_BACKUP_LOAD_PATH_Local . "\\". "MemodeDeviceList_" . $3;
            	print "file:$orifile\n";
        } 
    }
    $copied_file = $orifile . "_" . $curr_time_str . $$ . ".xls";
    
    system("copy /y \"$file\" \"$copied_file\"");
    $file = $copied_file;

    ### get already active Excel application or open new
    my $Excel = Win32::OLE->GetActiveObject('Excel.Application') || Win32::OLE->new('Excel.Application', 'Quit');

    ### copy the Excel file to a temp file and open it;
    ### this will prevent error due to simultaneous Excel access
    my $Book = $Excel->Workbooks->Open($file);
    
    ### 
    my $WorkSheet = $Book->Worksheets($sheet);
    
    ### fill in index rows
    ### $rows{'index'}->{1}->{1} = 'Vendor'
    ### $rows{'index'}->{2}->{12} = 'Region'
    for (1..$idx_count)
    {
          my $col = 1;
          while (defined &xls_cell_value($WorkSheet, $_, $col))
          {
                $rows{'index'}->{$_}->{$col} = &xls_cell_value($WorkSheet, $_, $col);
                $col++;
          }
    }

    ### find rows where the target exists
    ### $rows{'target'}->{0}->{1} = 'Intel'
    ### $rows{'target'}->{0}->{12} = '*'
    ### $rows{'target'}->{1}->{113} = 'x'
    my $row = $idx_count + 1;
    my $empty_flag = 0;  # exit if two consecutive empty lines are encountered
    foreach (sort keys %$target_href)
    {
        my $tgt = $_;
        while (1)
        {
            if (!defined &xls_cell_value($WorkSheet, $row, $search_col))
            {
                if ($empty_flag == 0)
                {
                    $empty_flag = 1;
                }
                else
                {
                    last;
                }
            }
            else
            {
                $empty_flag = 0;
            }
            
            my $target_found = 0;  
            my $content = &xls_cell_value($WorkSheet, $row, $search_col);
            my @xls_content = split /\s/, $content;
            foreach (0..$#xls_content)
            {
                if ($xls_content[$_] eq $target_href->{$tgt})
                {
#                    $row += $tgt;  # each row represents one target even when targets share the same search content (PART NUMBER)
                    my $col = 1;
                    while (defined &xls_cell_value($WorkSheet, 1, $col))
                    {
                        $rows{'target'}->{$tgt}->{$col} = &xls_cell_value($WorkSheet, $row, $col);
                        $col++;
                    }
                    $row++;  # start the next target searching from the next row, assuming that the excel sequence is the same as expected
                    $target_found = 1;
                    last;
                }
            }
            last if ($target_found == 1);
            $row++;
        }
        last if ($empty_flag == 1);
#        &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Part Number $target_href->{$tgt} not found!", __FILE__, __LINE__) if ($empty_flag == 1);
    }

    ### close the temp Excel file
    $Book->Close(1);
    undef $Excel;
    
    system("del /Q $file");
    
    return %rows;
}

#****************************************************************************
# subroutine:  fs_read_excel_findall_by_pattern
# return:      hash of matching rows and indexing rows
# input:       $file:       excel file to be read
#              $sheet:      sheet to open
#              $idx_count:  the number of rows that are index rows
#              $search_col: the column to be searched for the targets
#              $pattern:    the target pattern to be searched
#              $row_offset: row offset when the target is found
#              $count_href: the number of matching targets
#****************************************************************************
sub fs_read_excel_findall_by_pattern
{
    my ($file, $sheet, $idx_count, $search_col, $pattern, $row_offset, $count_href, $MDL_BACKUP_LOAD_PATH_Local) = @_;
    my %rows;
    $$count_href = 0;
    ### report error directly if MDL does not exist
    unless (-e $file)
    {
        &error_handler("$file: File does not exist! Please check with MVG or EMI Gen owner!", __FILE__, __LINE__);
    }
    
    ### copy and rename the current excel file to prevent concurrency build problem
    $MDL_BACKUP_LOAD_PATH_Local =~ s/^.\\|^\\//;
    my $copied_file = $MDL_BACKUP_LOAD_PATH_Local;
    my $copied_file_temp = '';
    my $orifile = '';
    my $orifile_temp = '';
    my $curr_time_str = &get_CurrTime_str();
    print "load path:$MDL_BACKUP_LOAD_PATH_Local\n";
    if($file =~ /^(\w+.*?)\.xls$/)
    {
        $orifile_temp = $1;
        if($orifile_temp =~ /^(\w*.*?)tools(\w*.*?)MemoryDeviceList_(\w+)$/)
        {
        	    print "1:$1,2:$2,3:$3\n";
            	$orifile = $1 . $MDL_BACKUP_LOAD_PATH_Local . "\\". "MemodeDeviceList_" . $3;
            	print "file:$orifile\n";
    }
    }
    ##=~ s/\\custom_MemoryDevice\.h$/\\custom_EMI\.h/i;
    $copied_file = $orifile . "_" . $curr_time_str . $$ . ".xls";
    my $WorkSheet;
    my $Excel;
    my $Book;
    if($^O eq "MSWin32")
    {
    system("copy /y \"$file\" \"$copied_file\"");
    $file = $copied_file;

    ### get already active Excel application or open new
        $Excel = Win32::OLE->GetActiveObject('Excel.Application') || Win32::OLE->new('Excel.Application', 'Quit');
    ### copy the Excel file to a temp file and open it;
    ### this will prevent error due to simultaneous Excel access
        $Book = $Excel->Workbooks->Open($file);
    ### 
        $WorkSheet = $Book->Worksheets($sheet);
    }
    else
    {
    	
    }
    ### fill in index rows
    ### $rows{'index'}->{1}->{1} = 'Vendor'
    ### $rows{'index'}->{2}->{12} = 'Region'
    for (1..$idx_count)
    {
          my $col = 1;
          while (defined &xls_cell_value($WorkSheet, $_, $col))
          {
                $rows{'index'}->{$_}->{$col} = &xls_cell_value($WorkSheet, $_, $col);
                $col++;
          }
    }
    ### find rows where the target exists
    ### $rows{'target'}->{0}->{1} = 'Intel'
    ### $rows{'target'}->{0}->{12} = '*'
    ### $rows{'target'}->{1}->{113} = 'x'
    my $row = $idx_count + 1;
    my $empty_flag = 0;  # exit if two consecutive empty lines are encountered
    while (1)
    {
        if (!defined &xls_cell_value($WorkSheet, $row, $search_col))
        {
            if ($empty_flag == 0)
            {
                $empty_flag = 1;
            }
            else
            {
                last;
            }
        }
        else
        {
            $empty_flag = 0;
        }
        
        my $content = &xls_cell_value($WorkSheet, $row, $search_col);
        my @xls_content = split /\s/, $content;
        foreach (0..$#xls_content)
        {
            if ($xls_content[$_] =~ /$pattern/)
            {
                $$count_href++;
                $row += $row_offset;  # each row represents one target even when targets share the same search content (PART NUMBER)
                my $col = 1;
                while (defined &xls_cell_value($WorkSheet, 1, $col))
                {
                    $rows{'target'}->{$$count_href}->{$col} = &xls_cell_value($WorkSheet, $row, $col);
                    $col++;
                    #print "col : $rows{'target'}->{$$count_href}->{$col}\n";
                }
                last;
            }
        }
        $row++;  # start the next target searching from the next row, assuming that the excel sequence is the same as expected
    }
    
    ### close the temp Excel file
    $Book->Close(1);
    undef $Excel;
    
    system("del /Q $file");
   
    return %rows;
}

#****************************************************************************
# subroutine:  fs_read_excel_linux
# return:      hash of matching rows and indexing rows
# input:       $file:       excel file to be read
#              $sheet:      sheet to open
#              $idx_count:  the number of rows that are index rows
#              $search_col: the column to be searched for the targets
#              $pattern:    the target pattern to be searched
#              $row_offset: row offset when the target is found
#              $count_href: the number of matching targets
#****************************************************************************
sub fs_read_excel_linux
{
    my ($file, $sheet, $idx_count, $search_col, $target_href, $MDL_BACKUP_LOAD_PATH_Local) = @_;
    my %rows;

    ### report error directly if MDL does not exist
   # unless (-e $file)
   # {
   #     &error_handler("$file: File does not exist! Please check with MVG or EMI Gen owner!", __FILE__, __LINE__);
   # }
    
    ### copy and rename the current excel file to prevent concurrency build problem
    $MDL_BACKUP_LOAD_PATH_Local =~ s/^.\\|^\\//;
    my $copied_file = $MDL_BACKUP_LOAD_PATH_Local;
    my $copied_file_temp = '';
    my $orifile = '';
    my $orifile_temp = '';
    my $curr_time_str = &get_CurrTime_str();
    if($MDL_BACKUP_LOAD_PATH_Local =~ /build/)
    {
    	 $MDL_BACKUP_LOAD_PATH_Local = $& . $'; #'
       print "MDL 1:$`,2:$&,3:$'\n";	
    }
    if($file =~ /^(\w+.*?)\.xls$/)
    {
        $orifile_temp = $1;
        if($orifile_temp =~ /^(\w*.*?)tools(\w*.*?)MemoryDeviceList_(\w+)$/)
        {
        	    print "1:$1,2:$2,3:$3\n";
            	$orifile = $1 . $MDL_BACKUP_LOAD_PATH_Local . "\/". "MemodeDeviceList_" . $3;
            	print "file:$orifile\n";
        } 
    }
    $copied_file = $orifile . "_" . $curr_time_str . $$ . ".xls";
    system("cp \"$file\" \"$copied_file\"");
    $file = $copied_file;
    my $WorkSheet;
    my $Excel;
    my $Book;
    my $parser;
    my $workbook;
    my ($row_min, $row_max); 
    my ($col_min, $col_max); 
   
    	 $parser   = Spreadsheet::ParseExcel->new();
       $workbook = $parser->parse($file) or die "cannot open MDL $!\n";#$parser->parse('tools/MemoryDeviceList/MemoryDeviceList_MT6280_Since11BW1224.xls') or die "cannot open MDL $!\n";
       #print "sheet : $sheet\n";
       # get the worksheet
       #my $sheet = $workbook->worksheet('SERIAL_FLASH');
       $WorkSheet = $workbook->worksheet($sheet);
       ($row_min, $row_max) = $WorkSheet->row_range();
	     ($col_min, $col_max) = $WorkSheet->col_range();
       
       # get the sheet name
       my $name = $WorkSheet->get_name();
       print "[sheetname]: $name, $row_min, $row_max, $col_min, $col_max\n";
  
    ### fill in index rows
    ### $rows{'index'}->{1}->{1} = 'Vendor'
    ### $rows{'index'}->{2}->{12} = 'Region'
    for (0..$idx_count)
    {
          my $col = 0;
          while (defined &xls_cell_value($WorkSheet, $_, $col))
          {
                $rows{'index'}->{$_}->{$col} = &xls_cell_value($WorkSheet, $_, $col);
                print "[$_][$col]: " . $rows{'index'}->{$_}->{$col} . "\n" ;
                $col++;
          }
     

    }

    ### find rows where the target exists
    ### $rows{'target'}->{0}->{1} = 'Intel'
    ### $rows{'target'}->{0}->{12} = '*'
    ### $rows{'target'}->{1}->{113} = 'x'
    my $row = $idx_count - 1;
    my $empty_flag = 0;  # exit if two consecutive empty lines are encountered
    foreach (sort keys %$target_href)
    {
        my $tgt = $_;
        while (1)
        {
            if (!defined &xls_cell_value($WorkSheet, $row, $search_col))
            {
                if ($empty_flag == 0)
                {
                    $empty_flag = 1;
                }
                else
                {
                    last;
                }
            }
            else
            {
                $empty_flag = 0;
            }
            
            my $target_found = 0;  
            my $content = &xls_cell_value($WorkSheet, $row, $search_col);
            print "content : $content,$search_col, $row\n";
            my @xls_content = split /\s/, $content;
            foreach (0..$#xls_content)
            {
                if ($xls_content[$_] eq $target_href->{$tgt})
                {
#                    $row += $tgt;  # each row represents one target even when targets share the same search content (PART NUMBER)
                    my $col = 1;
                    while (defined &xls_cell_value($WorkSheet, 1, $col))
                    {
                        $rows{'target'}->{$tgt}->{$col} = &xls_cell_value($WorkSheet, $row, $col);
                        print "target:$rows{'target'}->{$tgt}->{$col}, $tgt, $col\n";
                        $col++;
                    }
                   
                    $row++;  # start the next target searching from the next row, assuming that the excel sequence is the same as expected
                    $target_found = 1;
                    last;
                }
            }
            last if ($target_found == 1);
            $row++;
        }
        last if ($empty_flag == 1);
#        &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Part Number $target_href->{$tgt} not found!", __FILE__, __LINE__) if ($empty_flag == 1);
    }

   
    
    return %rows;
}

#****************************************************************************
# subroutine:  fs_read_excel_findall_by_pattern_linux
# return:      hash of matching rows and indexing rows
# input:       $file:       excel file to be read
#              $sheet:      sheet to open
#              $idx_count:  the number of rows that are index rows
#              $search_col: the column to be searched for the targets
#              $pattern:    the target pattern to be searched
#              $row_offset: row offset when the target is found
#              $count_href: the number of matching targets
#****************************************************************************
sub fs_read_excel_findall_by_pattern_linux
{
    my ($file, $sheet, $idx_count, $search_col, $pattern, $row_offset, $count_href, $MDL_BACKUP_LOAD_PATH_Local) = @_;
    my %rows;
    $$count_href = 0;
    ### report error directly if MDL does not exist
    unless (-e $file)
    {
        &error_handler("$file: File does not exist! Please check with MVG or EMI Gen owner!", __FILE__, __LINE__);
    }
    
    ### copy and rename the current excel file to prevent concurrency build problem
    $MDL_BACKUP_LOAD_PATH_Local =~ s/^.\\|^\\//;
    my $copied_file = $MDL_BACKUP_LOAD_PATH_Local;
    my $copied_file_temp = '';
    my $orifile = '';
    my $orifile_temp = '';
    my $curr_time_str = &get_CurrTime_str();
    print "load path:$MDL_BACKUP_LOAD_PATH_Local\n";
    if($file =~ /^(\w+.*?)\.xls$/)
    {
        $orifile_temp = $1;
        if($orifile_temp =~ /^(\w*.*?)tools(\w*.*?)MemoryDeviceList_(\w+)$/)
        {
        	    print "1:$1,2:$2,3:$3\n";
            	$orifile = $1 . $MDL_BACKUP_LOAD_PATH_Local . "\\". "MemodeDeviceList_" . $3;
            	print "file:$orifile\n";
        } 
    }
    ##=~ s/\\custom_MemoryDevice\.h$/\\custom_EMI\.h/i;
    $copied_file = $orifile . "_" . $curr_time_str . $$ . ".xls";
    my $WorkSheet;
    my $Excel;
    my $Book;
    my $parser;
    my $workbook;
    my ($row_min, $row_max); 
    my ($col_min, $col_max); 
   
    	 $parser   = Spreadsheet::ParseExcel->new();
       $workbook = $parser->parse('tools/MemoryDeviceList/MemoryDeviceList_MT6280_Since11BW1224.xls') or die "cannot open MDL $!\n";
       #print "sheet : $sheet\n";
       # get the worksheet
       #my $sheet = $workbook->worksheet('SERIAL_FLASH');
       $WorkSheet = $workbook->worksheet($sheet);
       ($row_min, $row_max) = $WorkSheet->row_range();
	     ($col_min, $col_max) = $WorkSheet->col_range();
       
       # get the sheet name
       my $name = $WorkSheet->get_name();
       print "[sheetname]: $name, $row_min, $row_max, $col_min, $col_max\n";
    
   
    ### fill in index rows
    ### $rows{'index'}->{1}->{1} = 'Vendor'
    ### $rows{'index'}->{2}->{12} = 'Region'
    for (1..$idx_count)
    {
          my $col = 1;
          while (defined &xls_cell_value($WorkSheet, $_, $col))
          {
                $rows{'index'}->{$_}->{$col} = &xls_cell_value($WorkSheet, $_, $col);
                $col++;
          }
    }
    ### find rows where the target exists
    ### $rows{'target'}->{0}->{1} = 'Intel'
    ### $rows{'target'}->{0}->{12} = '*'
    ### $rows{'target'}->{1}->{113} = 'x'
    my $row = $idx_count + 1;
    my $empty_flag = 0;  # exit if two consecutive empty lines are encountered
    #my $tgt = $_;
        #while (1)
        {
            if (!defined &xls_cell_value($WorkSheet, $row, $search_col))
            {
                if ($empty_flag == 0)
                {
                    $empty_flag = 1;
                }
                else
                {
                    last;
                }
            }
            else
            {
                $empty_flag = 0;
            }
            
            my $target_found = 0;  
            my $content = &xls_cell_value($WorkSheet, $row, $search_col);
            print "content : $content,$search_col, $row\n";
            my @xls_content = split /\s/, $content;
            foreach (0..$#xls_content)
            {
                $$count_href++;
                $row += $row_offset;  # each row represents one target even when targets share the same search content (PART NUMBER)
                my $col = 1;
                while (defined &xls_cell_value($WorkSheet, 1, $col))
                {
                    $rows{'target'}->{$$count_href}->{$col} = &xls_cell_value($WorkSheet, $row, $col);
                    $col++;
                    #print "col : $rows{'target'}->{$$count_href}->{$col}\n";
                }
                last;
            }
            #last if ($target_found == 1);
            $row++;
        }
        last if ($empty_flag == 1);
#        &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: Part Number $target_href->{$tgt} not found!", __FILE__, __LINE__) if ($empty_flag == 1);
    
   
    return %rows;
}
#****************************************************************************
# subroutine:  get_info
# input:       $file:        file path
#              $sheet:       sheet to open
#              $idx_count:   the number of rows that are index rows
#              $sesarch_col: the column to be searched for the targets
#              $target_href: the target patterns to be searched
#              $href:        output matching hash reference
#              $index_href:  output index hash reference
#****************************************************************************
sub get_info
{
    my ($file, $sheet, $idx_count, $search_col, $target_href, $href, $index_href) = @_;
    my $ret_str;
    my %rows;

    if($OS_ENV eq "MSWin32")
    {
    	%rows = &fs_read_excel($file, $sheet, $idx_count, $search_col, $target_href, $MDL_BACKUP_LOAD_PATH);
    }
    else
    {
    	
    	%rows = &fs_read_excel_linux($file, $sheet, $idx_count, $search_col, $target_href, $MDL_BACKUP_LOAD_PATH);
    }
    #my %rows = &fs_read_excel($file, $sheet, $idx_count, $search_col, $target_href, $MDL_BACKUP_LOAD_PATH);
    if (!defined $rows{'target'})
    {
    	  print "test reulst\n";
        $ret_str = "FALSE";
        return $ret_str;
    }
    
    ### fill in index_href
    foreach (1..$idx_count)
    {
       $index_href->{$_} = $rows{'index'}->{$_};
    }

    ### fill in output href
    ### $href->{0}->{'Vendor'} = 'Intel'
    ### $href->{0}->{'Last Bank'}->{'Region'} = '*'
    ### $href->{1}->{'General DRAM Settings'}->{'MT6229'}->{'EMI_DRAM_MODE'} = 'x'
    foreach (sort keys %$target_href)
    {
          my $tgt = $_;
          my $col = 1;

          while (defined $rows{'index'}->{1}->{$col})
          {
                my $content;
                if (defined $rows{'target'}->{$tgt}->{$col})
                {
                      $content = $rows{'target'}->{$tgt}->{$col};
                }
                else
                {
                      $content = " ";
                }
                if($OS_ENV eq "MSWin32")
                {
                if ($rows{'index'}->{1}->{$col} eq $rows{'index'}->{2}->{$col})
                {
                      $href->{$tgt}->{$rows{'index'}->{1}->{$col}} = $content;
                      print "href->{$tgt}->{$rows{'index'}->{1}->{$col}} = $href->{$tgt}->{$rows{'index'}->{1}->{$col}}\n" if ($DebugPrint == 1);
                }
                elsif (($idx_count == 2) or ($rows{'index'}->{2}->{$col} eq $rows{'index'}->{3}->{$col}))
                {
                      $href->{$tgt}->{$rows{'index'}->{1}->{$col}}->{$rows{'index'}->{2}->{$col}} = $content;
                      print "href->{$tgt}->{$rows{'index'}->{1}->{$col}}->{$rows{'index'}->{2}->{$col}} = $href->{$tgt}->{$rows{'index'}->{1}->{$col}}->{$rows{'index'}->{2}->{$col}}\n" if ($DebugPrint == 1);
                }
                else
                {
                      $href->{$tgt}->{$rows{'index'}->{1}->{$col}}->{$rows{'index'}->{2}->{$col}}->{$rows{'index'}->{3}->{$col}} = $content;
                      print "href->{$tgt}->{$rows{'index'}->{1}->{$col}}->{$rows{'index'}->{2}->{$col}}->{$rows{'index'}->{3}->{$col}} = $href->{$tgt}->{$rows{'index'}->{1}->{$col}}->{$rows{'index'}->{2}->{$col}}->{$rows{'index'}->{3}->{$col}}\n" if ($DebugPrint == 1);
                }
                $col++;
          }
                else
                {
                     	    #if ($rows{'index'}->{0}->{$col} eq $rows{'index'}->{1}->{$col})
                     if ($rows{'index'}->{1}->{$col} eq "pattern")
                     {
                           $href->{$tgt}->{$rows{'index'}->{0}->{$col}} = $content;
                           print "1 href->{$tgt}->{$rows{'index'}->{0}->{$col}} = $href->{$tgt}->{$rows{'index'}->{0}->{$col}}\n" if ($DebugPrint == 1);
                     }
                     elsif (($idx_count == 2) or ($rows{'index'}->{2}->{$col} eq $rows{'index'}->{3}->{$col}))
                     {
                     	    if($col >=1 && $col <=7)
                     	    {
                     	    	$href->{$tgt}->{$rows{'index'}->{0}->{$col}} = $content;
                     	    	 print "1 href->{$tgt}->{$rows{'index'}->{0}->{$col}} = $href->{$tgt}->{$rows{'index'}->{0}->{$col}}\n"
                     	    }
                     	    else
                     	    {
                              $href->{$tgt}->{$rows{'index'}->{0}->{$col}}->{$rows{'index'}->{1}->{$col}} = $content;
                              print "2 href->{$tgt}->{$rows{'index'}->{0}->{$col}}->{$rows{'index'}->{1}->{$col}} = $href->{$tgt}->{$rows{'index'}->{0}->{$col}}->{$rows{'index'}->{1}->{$col}}\n" if ($DebugPrint == 1);
                           }
                     }
                     else
                     {
                           $href->{$tgt}->{$rows{'index'}->{1}->{$col}}->{$rows{'index'}->{2}->{$col}}->{$rows{'index'}->{3}->{$col}} = $content;
                           print "3 href->{$tgt}->{$rows{'index'}->{1}->{$col}}->{$rows{'index'}->{2}->{$col}}->{$rows{'index'}->{3}->{$col}} = $href->{$tgt}->{$rows{'index'}->{1}->{$col}}->{$rows{'index'}->{2}->{$col}}->{$rows{'index'}->{3}->{$col}}\n" if ($DebugPrint == 1);
                     }
                     $col++;
                } 
               
          }
    }

    $ret_str = "TRUE";
    return $ret_str;
}

#****************************************************************************
# subroutine:  get_sip_info
# input:       $file:        file path
#              $sheet:       sheet to open
#              $idx_count:   the number of rows that are index rows
#              $search_col:  the column to be searched for the targets
#              $sip_pattern: the target pattern to be searched
#              $cs_offset:   chip select offset when the target part number is found
#              $href:        output matching hash reference
#              $index_href:  output index hash reference
#              $count_href:  number of matching sips found
#****************************************************************************
sub get_sip_info
{
    my ($file, $sheet, $idx_count, $search_col, $sip_pattern, $cs_offset, $href, $index_href, $count_href) = @_;
    my $ret_str;
    my $ret_count = 0;
    my %rows;
    if($OS_ENV eq "MSWIN32")
    {
       %rows = &fs_read_excel_findall_by_pattern($file, $sheet, $idx_count, $search_col, $sip_pattern, $cs_offset, $count_href, $MDL_BACKUP_LOAD_PATH);
    }
    else
    {
    	%rows = &fs_read_excel_findall_by_pattern_linux($file, $sheet, $idx_count, $search_col, $sip_pattern, $cs_offset, $count_href, $MDL_BACKUP_LOAD_PATH);
    }
    if (!defined $rows{'target'})
    {
        $ret_str = "FALSE";
        return $ret_str;
    }
    
    ### fill in index_href
    foreach (1..$idx_count)
    {
       $index_href->{$_} = $rows{'index'}->{$_};
       #print "row index : $rows{'index'}->{$_}\n";
    }

    ### fill in output href
    ### $href->{0}->{'Vendor'} = 'Intel'
    ### $href->{0}->{'Last Bank'}->{'Region'} = '*'
    ### $href->{1}->{'General DRAM Settings'}->{'MT6229'}->{'EMI_DRAM_MODE'} = 'x'
    foreach (1..$$count_href)
    {
          my $count = $_;
          my $col = 1;

          while (defined $rows{'index'}->{1}->{$col})
          {
                my $content;
                if (defined $rows{'target'}->{$count}->{$col})
                {
                      $content = $rows{'target'}->{$count}->{$col};
                      #print "row content : $rows{'target'}->{$count}->{$col}\n";
                }
                else
                {
                      $content = " ";
                }
                if ($rows{'index'}->{1}->{$col} eq $rows{'index'}->{2}->{$col})
                {
                      $href->{$count}->{$rows{'index'}->{1}->{$col}} = $content;
                      print "href->{$count}->{$rows{'index'}->{1}->{$col}} = $href->{$count}->{$rows{'index'}->{1}->{$col}}\n" if ($DebugPrint == 1);
                }
                elsif (($idx_count == 2) or ($rows{'index'}->{2}->{$col} eq $rows{'index'}->{3}->{$col}))
                {
                      $href->{$count}->{$rows{'index'}->{1}->{$col}}->{$rows{'index'}->{2}->{$col}} = $content;
                      print "href->{$count}->{$rows{'index'}->{1}->{$col}}->{$rows{'index'}->{2}->{$col}} = $href->{$count}->{$rows{'index'}->{1}->{$col}}->{$rows{'index'}->{2}->{$col}}\n" if ($DebugPrint == 1);
                }
                else
                {
                      $href->{$count}->{$rows{'index'}->{1}->{$col}}->{$rows{'index'}->{2}->{$col}}->{$rows{'index'}->{3}->{$col}} = $content;
                      print "href->{$count}->{$rows{'index'}->{1}->{$col}}->{$rows{'index'}->{2}->{$col}}->{$rows{'index'}->{3}->{$col}} = $href->{$count}->{$rows{'index'}->{1}->{$col}}->{$rows{'index'}->{2}->{$col}}->{$rows{'index'}->{3}->{$col}}\n" if ($DebugPrint == 1);
                }
                $col++;
          }
    }

    $ret_str = "TRUE";
    return $ret_str;
}

#****************************************************************************
# subroutine:  SCHEME Configure Routines :: Query :: no EMI Family
# input:       BB chip
# Output:      whether this chip belongs to no EMI Family
#****************************************************************************
sub config_query_no_EMI
{
    my ($bb) = @_;

    my %BBtbl_no_EMI_Family =
       (        
                'MT6251'  => 1,
       );
       
    return $BBtbl_no_EMI_Family{$bb};
}


#****************************************************************************
# subroutine:  xls_cell_value
# return:      excel cell value no matter it's in merge area or not
# input:       $sheet:  specified Excel Sheet
#              $row:    specified row number
#              $col:    specified column number
#****************************************************************************
sub xls_cell_value
{
    my ($sheet, $row, $col) = @_;

    if($^O eq "MSWin32")
    {    
    if ($sheet->Cells($row, $col)->{'MergeCells'})
    {
        my $ma = $sheet->Cells($row, $col)->{'MergeArea'};
        return ($ma->Cells(1, 1)->{'Value'});
    }
    else
    {
        return ($sheet->Cells($row, $col)->{'Value'})
    }
}
    else
    {
        my $cell = $sheet->get_cell($row, $col);
        my $mareas =$sheet->get_merged_areas();
        if(($row == 0))
        {
        	   my $value;
        	   for(0..$#$mareas)
        	   {
        	      if($col >= $mareas->[$_]->[1] && $col <= $mareas->[$_]->[3])
        	      {
        	          	$value = $sheet->get_cell(0,$mareas->[$_]->[1])->value();
        	            #print "value : $value\n";
        	            return $value;
        	      }	
        	   }
        	
        }
        if($cell){
        	my $value = $cell->value();
        	return $value;
        }
        else
        {
        	#print "cell is undef\n";
        	my $value;
        	return $value;
        }
	
    }
}

#****************************************************************************
# subroutine:  Lookup_SYNC_EMI_address_by_CS_CLK_BB
# input:       MEM_IDX, CHIP SECLECT , CLK , PLATFORM
# return:      Synchronous EMI address of the input MEM_IDX/CS/MCU_CLOCK/PLATFORM
#****************************************************************************
sub Lookup_SYNC_EMI_address_by_IDX_CS_CLK_BB
{
    my ($idx, $cs, $clk, $bb) = @_;
    my $clk_str = sprintf("%sMHz Synchronous EMI Setting", $clk);
    
    if (($bb eq 'MT6228') or ($bb eq 'MT6229') or ($bb eq 'MT6225') or ($bb eq 'MT6230'))
    {
          return $MDL_INFO_LIST[$idx]->{$cs}->{$clk_str}->{'Address (MT6228 MT6229 MT6225 MT6230)'};
    }
    elsif (($bb eq 'MT6235') or ($bb eq 'MT6235B'))
    {
          return $MDL_INFO_LIST[$idx]->{$cs}->{$clk_str}->{'Address (MT6235 MT6235B)'};
    }
    elsif (($bb eq 'MT6238') or ($bb eq 'MT6239'))
    {
          return $MDL_INFO_LIST[$idx]->{$cs}->{$clk_str}->{'Address (MT6238 MT6239)'};
    }
    elsif (($bb eq 'MT6236') or ($bb eq 'MT6236B'))
    {
        return $MDL_INFO_LIST[$idx]->{$cs}->{$clk_str}->{'Address (MT6236 MT6236B)'};
    }
    elsif ($bb eq 'MT6921')
    {
        return $MDL_INFO_LIST[$idx]->{$cs}->{$clk_str}->{'Address'};
    }
    elsif ($bb eq 'MT6253')
    {
        if ($clk == 104)
        {
            return $MDL_INFO_LIST[$idx]->{$cs}->{$clk_str}->{'Address (MT6253)'};
        }
        return $MDL_INFO_LIST[$idx]->{$cs}->{$clk_str}->{'Address (MT6253 MT6253D)'};
    }
    elsif (($bb eq 'MT6252H') or ($bb eq 'MT6252'))
    {
        ### MT6252H not MP yet
        if (defined $MDL_INFO_LIST[$idx]->{$cs}->{$clk_str}->{'Address (MT6252)'})
        {
            return $MDL_INFO_LIST[$idx]->{$cs}->{$clk_str}->{'Address (MT6252)'};
        }
        else
        {
            return $MDL_INFO_LIST[$idx]->{$cs}->{$clk_str}->{'Address (MT6252 MT6252H)'};
        }
    }
    elsif (($bb eq 'MT6223') or ($bb eq 'MT6227D') or ($bb eq 'MT6226D') or ($bb eq 'MT6223P') or ($bb eq 'MT6223D'))
    {
          &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: EMI setting of $bb at $clk MHz is not supported!", __FILE__, __LINE__) if ($clk == 104);
          return $MDL_INFO_LIST[$idx]->{$cs}->{$clk_str}->{'Address (MT6223 MT6227D MT6226D MT6223P MT6223D)'};
    }
    elsif ($bb eq 'MT6255')
    {
        return $MDL_INFO_LIST[$idx]->{$cs}->{$clk_str}->{'Address'};
    }
    &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: EMI setting of $bb at $clk MHz is not supported!", __FILE__, __LINE__);
}

#****************************************************************************
# subroutine:  Lookup_SYNC_EMI_setting_by_IDX_CS_CLK_BB
# input:       MEM_IDX, CHIP SECLECT , CLK , PLATFORM
# return:      Synchronous EMI setting of the input MEM_IDX/CS/MCU_CLOCK/PLATFORM
#****************************************************************************
sub Lookup_SYNC_EMI_setting_by_IDX_CS_CLK_BB
{
    my ($idx, $cs, $clk, $bb) = @_;
    my $clk_str = sprintf("%sMHz Synchronous EMI Setting", $clk);
    
    if (($bb eq 'MT6228') or ($bb eq 'MT6229') or ($bb eq 'MT6225') or ($bb eq 'MT6230'))
    {
          return $MDL_INFO_LIST[$idx]->{$cs}->{$clk_str}->{'MT6228 MT6229 MT6225 MT6230'};
    }
    elsif (($bb eq 'MT6235') or ($bb eq 'MT6235B'))
    {
          return $MDL_INFO_LIST[$idx]->{$cs}->{$clk_str}->{'MT6235 MT6235B'};
    }
    elsif (($bb eq 'MT6238') or ($bb eq 'MT6239'))
    {
          return $MDL_INFO_LIST[$idx]->{$cs}->{$clk_str}->{'MT6238 MT6239'};
    }
    elsif (($bb eq 'MT6236') or ($bb eq 'MT6236B'))
    {
        return $MDL_INFO_LIST[$idx]->{$cs}->{$clk_str}->{'MT6236 MT6236B'};
    }
    elsif ($bb eq 'MT6921')
    {
        return $MDL_INFO_LIST[$idx]->{$cs}->{$clk_str}->{'MT6921'};
    }
    elsif ($bb eq 'MT6253')
    {
        if ($clk == 104)
        {
            return $MDL_INFO_LIST[$idx]->{$cs}->{$clk_str}->{'MT6253'};
        }
        return $MDL_INFO_LIST[$idx]->{$cs}->{$clk_str}->{'MT6253 MT6253D'};
    }
    elsif (($bb eq 'MT6252H') or ($bb eq 'MT6252'))
    {
        ### MT6252H not MP yet
        if (defined $MDL_INFO_LIST[$idx]->{$cs}->{$clk_str}->{'MT6252'})
        {
            return $MDL_INFO_LIST[$idx]->{$cs}->{$clk_str}->{'MT6252'};
        }
        else
        {
            return $MDL_INFO_LIST[$idx]->{$cs}->{$clk_str}->{'MT6252 MT6252H'};
        }
    }
    elsif ($bb eq 'MT6255')
    {
        return $MDL_INFO_LIST[$idx]->{$cs}->{$clk_str}->{'MT6255'};
    }
    elsif (($bb eq 'MT6223') or ($bb eq 'MT6227D') or ($bb eq 'MT6226D') or ($bb eq 'MT6223P') or ($bb eq 'MT6223D'))
    {
          &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: EMI setting of $bb at $clk MHz is not supported!", __FILE__, __LINE__) if ($clk == 104);
          return $MDL_INFO_LIST[$idx]->{$cs}->{$clk_str}->{'MT6223 MT6227D MT6226D MT6223P MT6223D'};
    }
    &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: EMI setting of $bb at $clk MHz is not supported!", __FILE__, __LINE__);
}

#****************************************************************************
# subroutine:  Lookup_SYNC_EMI_driving_by_IDX_CS_CLK_BB
# input:       MEM_IDX, CHIP SECLECT , CLK , PLATFORM
# return:      Synchronous EMI driving of the input MEM_IDX/CS/MCU_CLOCK/PLATFORM
#****************************************************************************
sub Lookup_SYNC_EMI_driving_by_IDX_CS_CLK_BB
{
    my ($idx, $cs, $clk, $bb) = @_;
    my $clk_str = sprintf("%sMHz Synchronous Driving Setting", $clk);

    if (($bb eq 'MT6228') or ($bb eq 'MT6225'))
    {
          return $MDL_INFO_LIST[$idx]->{$cs}->{$clk_str}->{$bb};
    }
    elsif (($bb eq 'MT6229') or ($bb eq 'MT6230'))
    {
          return $MDL_INFO_LIST[$idx]->{$cs}->{$clk_str}->{'MT6229 MT6230'};
    }
    elsif (($bb eq 'MT6235') or ($bb eq 'MT6235B'))
    {
          return $MDL_INFO_LIST[$idx]->{$cs}->{$clk_str}->{'MT6235 MT6235B'};
    }
    elsif (($bb eq 'MT6238') or ($bb eq 'MT6239'))
    {
          return $MDL_INFO_LIST[$idx]->{$cs}->{$clk_str}->{'MT6238 MT6239'};
    }
    elsif (($bb eq 'MT6236') or ($bb eq 'MT6236B'))
    {
        return $MDL_INFO_LIST[$idx]->{$cs}->{$clk_str}->{'MT6236 MT6236B'};
    }
    elsif ($bb eq 'MT6921')
    {
        return $MDL_INFO_LIST[$idx]->{$cs}->{$clk_str}->{'MT6921'};
    }
    elsif ($bb eq 'MT6253')
    {
        if ($clk == 104)
        {
            return $MDL_INFO_LIST[$idx]->{$cs}->{$clk_str}->{'MT6253'};
        }
        return $MDL_INFO_LIST[$idx]->{$cs}->{$clk_str}->{'MT6253 MT6253D'};
    }
    elsif (($bb eq 'MT6252H') or ($bb eq 'MT6252'))
    {
        ### MT6252H not MP yet
        if (defined $MDL_INFO_LIST[$idx]->{$cs}->{$clk_str}->{'MT6252'})
        {
            return $MDL_INFO_LIST[$idx]->{$cs}->{$clk_str}->{'MT6252'};
        }
        else
        {
            return $MDL_INFO_LIST[$idx]->{$cs}->{$clk_str}->{'MT6252 MT6252H'};
        }
    }
    elsif ($bb eq 'MT6255')
    {
        return $MDL_INFO_LIST[$idx]->{$cs}->{$clk_str}->{'MT6255'};
    }
    elsif (($bb eq 'MT6223') or ($bb eq 'MT6227D') or ($bb eq 'MT6226D') or ($bb eq 'MT6223P') or ($bb eq 'MT6223D'))
    {
          &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: EMI driving of $bb at $clk MHz is not supported!", __FILE__, __LINE__) if ($clk == 104);
          return $MDL_INFO_LIST[$idx]->{$cs}->{$clk_str}->{'MT6223 MT6227D MT6226D MT6223P MT6223D'};
    }
    &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: EMI driving of $bb at $clk MHz is not supported!", __FILE__, __LINE__);
}

#****************************************************************************
# subroutine:  Lookup_ASYNC_EMI_setting_by_IDX_CS_BB
# input:       MEM_IDX, CHIP SECLECT , PLATFORM
# return:      Synchronous EMI setting of the input MEM_IDX/CS/PLATFORM
#****************************************************************************
sub Lookup_ASYNC_EMI_setting_by_IDX_CS_BB
{
    my ($idx, $cs, $bb) = @_;
    
    if (($bb eq 'MT6227') or ($bb eq 'MT6226') or ($bb eq 'MT6226M'))
    {
          return $MDL_INFO_LIST[$idx]->{$cs}->{'Asynchrnous EMI Setting (Maximal MPLL)'}->{'MT6227 MT6226 MT6226M'};
    }
    elsif (($bb eq 'MT6228') or ($bb eq 'MT6229') or ($bb eq 'MT6230') or ($bb eq 'MT6225'))
    {
          return $MDL_INFO_LIST[$idx]->{$cs}->{'Asynchrnous EMI Setting (Maximal MPLL)'}->{'MT6228 MT6229 MT6230 MT6225'};
    }
    elsif (($bb eq 'MT6223') or ($bb eq 'MT6227D') or ($bb eq 'MT6226D') or ($bb eq 'MT6223P') or ($bb eq 'MT6223D'))
    {
          return $MDL_INFO_LIST[$idx]->{$cs}->{'Asynchrnous EMI Setting (Maximal MPLL)'}->{'MT6223 MT6227D MT6226D MT6223P MT6223D'};
    }
    elsif (($bb eq 'MT6235') or ($bb eq 'MT6235B'))
    {
          return $MDL_INFO_LIST[$idx]->{$cs}->{'Asynchrnous EMI Setting (Maximal MPLL)'}->{'MT6235 MT6235B'};
    }
    elsif (($bb eq 'MT6238') or ($bb eq 'MT6239'))
    {
          return $MDL_INFO_LIST[$idx]->{$cs}->{'Asynchrnous EMI Setting (Maximal MPLL)'}->{'MT6238 MT6239'};
    }
    elsif ($bb eq 'MT6253')
    {
        if ($emi_clk_config == 104)
        {
            return $MDL_INFO_LIST[$idx]->{$cs}->{'Asynchrnous EMI Setting (Maximal MPLL)'}->{'MT6253'};
        }
        elsif ($emi_clk_config == 52)
        {
            return $MDL_INFO_LIST[$idx]->{$cs}->{'Asynchrnous EMI Setting (Maximal MPLL)'}->{'MT6253D'};
        }
        else
        {
            &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: EMI setting of $bb at $emi_clk_config MHz is not supported!", __FILE__, __LINE__);
        }
    }
    elsif (($bb eq 'MT6252H') or ($bb eq 'MT6252'))
    {
        ### MT6252H not MP yet
        if (defined $MDL_INFO_LIST[$idx]->{$cs}->{'Asynchrnous EMI Setting (Maximal MPLL)'}->{'MT6252'})
        {
            return $MDL_INFO_LIST[$idx]->{$cs}->{'Asynchrnous EMI Setting (Maximal MPLL)'}->{'MT6252'};
        }
        else
        {
            return $MDL_INFO_LIST[$idx]->{$cs}->{'Asynchrnous EMI Setting (Maximal MPLL)'}->{'MT6252 MT6252H'};
        }
    }
    elsif (($bb eq 'MT6236') or ($bb eq 'MT6236B'))
    {
          return $MDL_INFO_LIST[$idx]->{$cs}->{'Asynchrnous EMI Setting (Maximal MPLL)'}->{'MT6236 MT6236B'};
    }
    elsif ($bb eq 'MT6921')
    {
          return $MDL_INFO_LIST[$idx]->{$cs}->{'Asynchrnous EMI Setting (Maximal MPLL)'}->{'MT6921'};
    }
    elsif ($bb eq 'MT6255')
    {
          return $MDL_INFO_LIST[$idx]->{$cs}->{'Asynchrnous EMI Setting (Maximal MPLL)'}->{'MT6255'};
    }
    &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: EMI setting of $bb is not supported!", __FILE__, __LINE__);
}

#****************************************************************************
# subroutine:  Lookup_ASYNC_EMI_driving_by_IDX_CS_BB
# input:       MEM_IDX, CHIP SECLECT , PLATFORM
# return:      Synchronous EMI setting of the input MEM_IDX/CS/PLATFORM
#****************************************************************************
sub Lookup_ASYNC_EMI_driving_by_IDX_CS_BB
{
    my ($idx, $cs, $bb) = @_;
    
    if (($bb eq 'MT6227') or ($bb eq 'MT6226') or ($bb eq 'MT6226M'))
    {
          return $MDL_INFO_LIST[$idx]->{$cs}->{'Asynchrnous Driving Setting'}->{'MT6227 MT6226 MT6226M'};
    }
    elsif ($bb eq 'MT6228')
    {
          return $MDL_INFO_LIST[$idx]->{$cs}->{'Asynchrnous Driving Setting'}->{'MT6228'};
    }
    elsif ($bb eq 'MT6225')
    {
          return $MDL_INFO_LIST[$idx]->{$cs}->{'Asynchrnous Driving Setting'}->{'MT6225'};
    }
    elsif (($bb eq 'MT6229') or ($bb eq 'MT6230'))
    {
          return $MDL_INFO_LIST[$idx]->{$cs}->{'Asynchrnous Driving Setting'}->{'MT6229 MT6230'};
    }
    elsif (($bb eq 'MT6223') or ($bb eq 'MT6227D') or ($bb eq 'MT6226D') or ($bb eq 'MT6223P') or ($bb eq 'MT6223D'))
    {
          return $MDL_INFO_LIST[$idx]->{$cs}->{'Asynchrnous Driving Setting'}->{'MT6223 MT6227D MT6226D MT6223P MT6223D'};
    }
    elsif (($bb eq 'MT6235') or ($bb eq 'MT6235B'))
    {
          return $MDL_INFO_LIST[$idx]->{$cs}->{'Asynchrnous Driving Setting'}->{'MT6235 MT6235B'};
    }
    elsif (($bb eq 'MT6236') or ($bb eq 'MT6236B'))
    {
          return $MDL_INFO_LIST[$idx]->{$cs}->{'Asynchrnous Driving Setting'}->{'MT6236 MT6236B'};
    }
    elsif ($bb eq 'MT6921')
    {
          return $MDL_INFO_LIST[$idx]->{$cs}->{'Asynchrnous Driving Setting'}->{'MT6921'};
    }
    elsif (($bb eq 'MT6238') or ($bb eq 'MT6239'))
    {
          return $MDL_INFO_LIST[$idx]->{$cs}->{'Asynchrnous Driving Setting'}->{'MT6238 MT6239'};
    }
    elsif ($bb eq 'MT6253')
    {
        if ($emi_clk_config == 104)
        {
            return $MDL_INFO_LIST[$idx]->{$cs}->{'Asynchrnous Driving Setting'}->{'MT6253'};
        }
        elsif ($emi_clk_config == 52)
        {
            return $MDL_INFO_LIST[$idx]->{$cs}->{'Asynchrnous Driving Setting'}->{'MT6253D'};
        }
        else
        {
            &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: EMI setting of $bb at $emi_clk_config MHz is not supported!", __FILE__, __LINE__);
        }
    }
    elsif (($bb eq 'MT6252H') or ($bb eq 'MT6252'))
    {
        ### MT6252H not MP yet
        if (defined $MDL_INFO_LIST[$idx]->{$cs}->{'Asynchrnous Driving Setting'}->{'MT6252'})
        {
            return $MDL_INFO_LIST[$idx]->{$cs}->{'Asynchrnous Driving Setting'}->{'MT6252'};
        }
        else
        {
            return $MDL_INFO_LIST[$idx]->{$cs}->{'Asynchrnous Driving Setting'}->{'MT6252 MT6252H'};
        }
    }
    elsif ($bb eq 'MT6255')
    {
          return $MDL_INFO_LIST[$idx]->{$cs}->{'Asynchrnous Driving Setting'}->{'MT6255'};
    }
    &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: EMI setting of $bb is not supported!", __FILE__, __LINE__);
}

#****************************************************************************
# subroutine:  Lookup_LPDDR_EMI_setting_by_CLK_BB_REG
# input:       MEM_IDX, CLK , PLATFORM , REGISTER
# return:      LPDDR/LPDDR2 EMI setting of the input MEM_IDX/MCU_CLOCK/PLATFORM/REGISTER
#****************************************************************************
sub Lookup_LPDDR_EMI_setting_by_IDX_CLK_BB_REG
{
    my ($idx, $clk, $bb, $reg, $LPSDRAM_CHIP_SELECT_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL) = @_;
    my $clk_str = sprintf("%sMHZ", $clk);
    
    if (($bb eq 'MT6276') || ($bb eq 'MT6256'))
    {
        return $MDL_INFO_LIST[$idx]->{$LPSDRAM_CHIP_SELECT_LOCAL}->{$clk_str}->{$reg};
    }
    elsif(($bb eq 'MT6255') || ($bb eq 'MT6280'))
    {
    	 if(($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR') || ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} eq 'LPDDR2'))
    	 {
    	 	   return $MDL_INFO_LIST[$idx]->{$LPSDRAM_CHIP_SELECT_LOCAL}->{$clk_str}->{$reg};
    	 }
    	 else
    	 {
    	 	   return $MDL_INFO_LIST[$idx]->{1}->{$clk_str}->{$reg};
    	 }
    }
    &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: EMI setting of $bb is not supported!", __FILE__, __LINE__);
}

#****************************************************************************
# subroutine:  Lookup_LPSDRAM_EMI_setting_by_CLK_BB_REG
# input:       MEM_IDX, CLK , PLATFORM , REGISTER
# return:      LPSDRAM EMI setting of the input MEM_IDX/MCU_CLOCK/PLATFORM/REGISTER
#****************************************************************************
sub Lookup_LPSDRAM_EMI_setting_by_IDX_CLK_BB_REG
{
    my ($idx, $clk, $bb, $reg, $LPSDRAM_CHIP_SELECT_LOCAL) = @_;
    my $clk_str = sprintf("%sMHZ EMI Driving", $clk);
    
    if (($bb eq 'MT6229') or ($bb eq 'MT6230'))
    {
          if ($clk == 0)
          {
              return $MDL_INFO_LIST[$idx]->{$LPSDRAM_CHIP_SELECT_LOCAL}->{'MT6229 MT6230'}->{$reg};
          }
          else
          {
              return $MDL_INFO_LIST[$idx]->{$LPSDRAM_CHIP_SELECT_LOCAL}->{'MT6229 MT6230'}->{$clk_str}->{$reg};
          }
    }
    elsif (($bb eq 'MT6235') or ($bb eq 'MT6235B'))
    {
          if ($clk == 0)
          {
              return $MDL_INFO_LIST[$idx]->{$LPSDRAM_CHIP_SELECT_LOCAL}->{'MT6235 MT6235B'}->{$reg};
          }
          else
          {
              return $MDL_INFO_LIST[$idx]->{$LPSDRAM_CHIP_SELECT_LOCAL}->{'MT6235 MT6235B'}->{$clk_str}->{$reg};
          }
    }
    elsif (($bb eq 'MT6238') or ($bb eq 'MT6239'))
    {
          if ($clk == 0)
          {
              return $MDL_INFO_LIST[$idx]->{$LPSDRAM_CHIP_SELECT_LOCAL}->{'MT6238 MT6239'}->{$reg};
          }
          else
          {
              return $MDL_INFO_LIST[$idx]->{$LPSDRAM_CHIP_SELECT_LOCAL}->{'MT6238 MT6239'}->{$clk_str}->{$reg};
          }
    }
    elsif (($bb eq 'MT6236') or ($bb eq 'MT6236B'))
    {
          if ($clk == 0)
          {
          	  print "LPSDRAM_CHIP_SELECT_LOCAL: $MDL_INFO_LIST[$idx]->{$LPSDRAM_CHIP_SELECT_LOCAL}->{'MT6236 MT6236B'}->{$reg}\n";
              return $MDL_INFO_LIST[$idx]->{$LPSDRAM_CHIP_SELECT_LOCAL}->{'MT6236 MT6236B'}->{$reg};
          }
          else
          {
              return $MDL_INFO_LIST[$idx]->{$LPSDRAM_CHIP_SELECT_LOCAL}->{'MT6236 MT6236B'}->{$clk_str}->{$reg};
          }
    }
    else
    {
          if ($clk == 0)
          {
              return $MDL_INFO_LIST[$idx]->{$LPSDRAM_CHIP_SELECT_LOCAL}->{$bb}->{$reg};
          }
          else
          {
              return $MDL_INFO_LIST[$idx]->{$LPSDRAM_CHIP_SELECT_LOCAL}->{$bb}->{$clk_str}->{$reg};
          }
    }
}

#****************************************************************************
# subroutine:  Lookup_SYNC_EMI_data_by_CS_CLK_BB
# input:       MEM_IDX, CLK , PLATFORM , REGISTER
# return:      Synchronous EMI data of the input MEM_IDX/CS/MCU_CLOCK/PLATFORM
#****************************************************************************
sub Lookup_SYNC_EMI_data_by_IDX_CS_CLK_BB
{
    my ($idx, $cs, $clk, $bb) = @_;
    my $clk_str = sprintf("%sMHz Synchronous EMI Setting", $clk);

    if (($bb eq 'MT6252H') or ($bb eq 'MT6252'))
    {
        ### MT6252H not MP yet
        if (defined $MDL_INFO_LIST[$idx]->{$cs}->{$clk_str}->{'Data (MT6252)'})
        {
            return $MDL_INFO_LIST[$idx]->{$cs}->{$clk_str}->{'Data (MT6252)'};
        }
        else
        {
            return $MDL_INFO_LIST[$idx]->{$cs}->{$clk_str}->{'Data (MT6252 MT6252H)'};
        }
    }
    elsif (($bb eq 'MT6236') or ($bb eq 'MT6236B'))
    {
        if ($clk == 104)
        {
             return $MDL_INFO_LIST[$idx]->{$cs}->{$clk_str}->{'Data (MT6236 MT6236B)'};
        }
        else
        {
             return $MDL_INFO_LIST[$idx]->{$cs}->{$clk_str}->{'Data (Others)'};
        }
    }
    elsif ($bb eq 'MT6921')
    {
        return $MDL_INFO_LIST[$idx]->{$cs}->{$clk_str}->{'Data'};
    }
     elsif ($bb eq 'MT6255')
    {
        return $MDL_INFO_LIST[$idx]->{$cs}->{$clk_str}->{'Data'};
    }
    else
    {
         return $MDL_INFO_LIST[$idx]->{$cs}->{$clk_str}->{'Data (Others)'};
    }
    &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: EMI setting of $bb at $clk MHz is not supported!", __FILE__, __LINE__);
}

#****************************************************************************
# subroutine:  ret_tmp_hash_ref
# input:       $idx: The index of the current tmp hash
# return:      the hash reference of the input index
#****************************************************************************
my (%tmp_hash1, %tmp_hash2, %tmp_hash3, %tmp_hash4, %tmp_hash5, %tmp_hash6, %tmp_hash7, %tmp_hash8, %tmp_hash9, %tmp_hash10, %tmp_hash11, %tmp_hash12, %tmp_hash13, %tmp_hash14, %tmp_hash15, %tmp_hash16, %tmp_hash17, %tmp_hash18, %tmp_hash19, %tmp_hash20);
sub ret_tmp_hash_ref
{
    my ($idx) = @_;

    if ($idx == 1)
    {
        return \%tmp_hash1;
    }
    elsif ($idx == 2)
    {
        return \%tmp_hash2;
    }
    elsif ($idx == 3)
    {
        return \%tmp_hash3;
    }
    elsif ($idx == 4)
    {
        return \%tmp_hash4;
    }
    elsif ($idx == 5)
    {
        return \%tmp_hash5;
    }
    elsif ($idx == 6)
    {
        return \%tmp_hash6;
    }
    elsif ($idx == 7)
    {
        return \%tmp_hash7;
    }
    elsif ($idx == 8)
    {
        return \%tmp_hash8;
    }
    elsif ($idx == 9)
    {
        return \%tmp_hash9;
    }
    elsif ($idx == 10)
    {
        return \%tmp_hash10;
    }
    elsif ($idx == 11)
    {
        return \%tmp_hash11;
    }
    elsif ($idx == 12)
    {
        return \%tmp_hash12;
    }
    elsif ($idx == 13)
    {
        return \%tmp_hash13;
    }
    elsif ($idx == 14)
    {
        return \%tmp_hash14;
    }
    elsif ($idx == 15)
    {
        return \%tmp_hash15;
    }
    elsif ($idx == 16)
    {
        return \%tmp_hash16;
    }
    elsif ($idx == 17)
    {
        return \%tmp_hash17;
    }
    elsif ($idx == 18)
    {
        return \%tmp_hash18;
    }
    elsif ($idx == 19)
    {
        return \%tmp_hash19;
    }
    elsif ($idx == 20)
    {
        return \%tmp_hash20;
    }
    
    &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: COMBO_MEM_ENTRY_COUNT has exceeded its upper limit $MAX_COMBO_MEM_ENTRY_COUNT! Please reduce COMBO_MEM_ENTRY_COUNT!", __FILE__, __LINE__);
}


#****************************************************************************
# subroutine:  dependency check
# return:      None
#****************************************************************************
sub dependency_check
{
    my ($target, $force_del_new_file, @depends) = (@_);
    
    return unless (-e $target);

    ## Now check if the $target file check-in or auto-gen
    ## Read whole file ##
    open SRC_FILE_R , "<$target" or &error_handler("$target: file error!", __FILE__, __LINE__);
    my $saved_sep = $/;
    undef $/;
    my $reading = <SRC_FILE_R>; 
    close SRC_FILE_R;
    $/ = $saved_sep;

    ## Look for check-in pattern ##
    if (($reading =~ /\[MAUI_\d{8}\]/) or ($reading =~ /MANUAL-CHECKIN/i))
    {
        print "$target: Check-in message is found. No need to update.\n";
        return;
    }

    ## for emiclean to force delete new files
    if ($force_del_new_file eq 'TRUE')
    {
        unlink $target if (-e $target);
        return;
    }

    unlink $target if (-e $target);
        return;
    #my @stat_target = stat $target;

    #foreach my $dep (@depends)
    #{
    #    next unless (-e $dep);
    #    my @stat_dep = stat $dep;

    #    next if ($stat_dep[9] < $stat_target[9]);

    #    print "$target is older than $dep, force delete and update\n";
    #    unlink $target;

    #    return;
    #}
}


#****************************************************************************
# subroutine:  error_handler
# input:       $error_msg:     error message
#****************************************************************************
sub error_handler
{
      my ($error_msg, $file, $line_no) = @_;
      
      my $final_error_msg = "EMIGEN ERROR: $error_msg at $file line $line_no\n";
      print $final_error_msg;
      die $final_error_msg;
}


#****************************************************************************
# subroutine:  copyright_file_header
# return:      file header -- copyright
#****************************************************************************
sub copyright_file_header
{
    my $template = <<"__TEMPLATE";
/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

__TEMPLATE

   return $template;
}

#****************************************************************************
# subroutine:  description_file_header
# return:      file header -- description 
# input:       $filename:     filename
# input:       $description:  one line description
# input:       $author:       optional
#****************************************************************************
sub description_file_header
{
    my ($filename, $description, $author) = @_;
    my @stat_ar = stat $MEMORY_DEVICE_LIST_XLS;
    my ($day, $month, $year) = (localtime($stat_ar[9]))[3,4,5]; $month++; $year+=1900;
    my $template = <<"__TEMPLATE";
/*****************************************************************************
 *
 * Filename:
 * ---------
 *   $filename
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   $description
 *
 * Author:
 * -------
 *  $author
 *
 *   Memory Device database last modified on $year/$month/$day
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * \$Revision\$
 * \$Modtime\$
 * \$Log\$
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

__TEMPLATE

   return $template;
}

#****************************************************************************
# subroutine:  SCHEME Configure Routines :: Query :: CS1 base address
# input:       BB chip
# Output:      CS1 default base address
#****************************************************************************
sub config_query_cs1_addr
{
    my ($bb) = @_;

    if ((&config_query_arm9($bb) == 1) or (&config_query_arm11($bb) == 1))
    {
        return 0x10000000;
    }
    else
    {
        return 0x08000000;
    }
} 

#******************************************************************************
# subroutine:  get_CurrTime_str
# return:      string of the current time
# input:       None
#******************************************************************************
sub get_CurrTime_str
{
    my($sec, $min, $hour, $mday, $mon, $year) = localtime(time);
    return (sprintf "%04d_%02d_%02d_%02d_%02d_%02d", $year+1900, $mon+1, $mday, $hour, $min, $sec);
}

#****************************************************************************
# subroutine:  SCHEME Configure Routines :: Query :: ARM9 Family
# input:       BB chip
# Output:      whether this chip belongs to ARM9 Family
#****************************************************************************
sub config_query_arm9
{
    my ($bb) = @_;

    my %BBtbl_ARM9_Family =
       (        
                'MT6235'  => 1,
                'MT6235B' => 1,
                'MT6238'  => 1,
                'MT6239'  => 1,
                'MT6268'  => 1,
                'MT6236'  => 1,
                'MT6236B' => 1,
                'MT6921'  => 1,
                'MT6255'  => 1,
                'MT6280'  => 1,
       );
       
    return $BBtbl_ARM9_Family{$bb};
}

#****************************************************************************
# subroutine:  SCHEME Configure Routines :: Query :: ARM11 Family
# input:       BB chip
# Output:      whether this chip belongs to ARM11 Family
#****************************************************************************
sub config_query_arm11
{
    my ($bb) = @_;

    my %BBtbl_ARM11_Family =
       (        
                'MT6276'  => 1,
                'MT6256'  => 1,
       );
       
    return $BBtbl_ARM11_Family{$bb};
}


sub query_MD_INFO
{
   my ($MAKEFILE_OPTIONS_LOCAL,$CUSTOM_MEM_DEV_OPTIONS_LOCAL,$COMM_MDL_INFO_LOCAL) = @_;
   open(write_file,">MD_INFO.txt") or "open file error";
   #if(($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{'MEMORY_DEVICE_TYPE'} = 'LPDDR') || ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{'MEMORY_DEVICE_TYPE'} = 'LPDDR2') || ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{'MEMORY_DEVICE_TYPE'} = 'LPSDRAM'))
   #{
   #	  if(defined $MAKEFILE_OPTIONS_LOCAL->{'sip_ram_size'})
   #	  {
   #	  	print write_file "Memory device type:$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{'MEMORY_DEVICE_TYPE'}";
   #	  	print write_file "size:$COMM_MDL_INFO_LOCAL->{1}->{'Size (Mb)'}"
   #	  }
   #	  else
   #	  {
   #	  	print write_file "Memory device type:$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{'MEMORY_DEVICE_TYPE'}";
   #	  	print write_file "size:$COMM_MDL_INFO_LOCAL->{1}->{'Size (Mb)'}"
   #	  }
   	  
   #}
   #else
   #{
   #	   if(defined $MAKEFILE_OPTIONS_LOCAL->{'sip_ram_size'})
   #	  {
   #	  	print write_file "Memory device type:$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{'MEMORY_DEVICE_TYPE'}";
   #	  	print write_file "size:$COMM_MDL_INFO_LOCAL->{1}->{'Size (Mb)'}"
   #	  }
   #	  else
   #	  {
   #	  	print write_file "Memory device type:$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{'MEMORY_DEVICE_TYPE'}";
   #	  	print write_file "size:$COMM_MDL_INFO_LOCAL->{1}->{'Size (Mb)'}"
   #	  }
   #	  
   #}
   		
   		print write_file "Memory device type:$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{'MEMORY_DEVICE_TYPE'}\n";
	  	print write_file "size:$COMM_MDL_INFO_LOCAL->{1}->{'Size (Mb)'}\n";
	  	close(write_file);
}

sub Parse_custom_FeatureConfig
{
	my ($CUSTOM_FEATURE_CFG_OPTIONS_LOCAL) = @_;
   open CUSTOM_FEATURE_CONFIG_HDR, "<$CUSTOM_FEATURE_CONFIG_HDR" or &error_handler("$CUSTOM_FEATURE_CONFIG_HDR: file error!", __FILE__, __LINE__);

while (<CUSTOM_FEATURE_CONFIG_HDR>)
{
   # error-checking
   if (/^#if|^#ifdef|^#ifndef|^#elif|^#else/)
   {
      &error_handler("$CUSTOM_FEATURE_CONFIG_HDR: Not allowed to set conditional keywords $_ in custom_FeatureConfig.h!", __FILE__, __LINE__)
          unless (/^#ifndef\s+__CUSTOM_FEATURECONFIG_H__/);
   }

   if (/^#define\s+(\w+)\s+\(([\w|\-]*)\)/ || /^#define\s+(\w+)\s+([\w|\-]*)/)
   {
      &error_handler("$CUSTOM_FEATURE_CONFIG_HDR: $1 redefined in custom_FeatureConfig.h!", __FILE__, __LINE__) if defined($CUSTOM_FEATURE_CFG_OPTIONS_LOCAL->{$1});
      if ((!defined $2) or ($2 eq ''))
      {
          $CUSTOM_FEATURE_CFG_OPTIONS_LOCAL->{$1} = 'TRUE';
      }
      else
      {
          $CUSTOM_FEATURE_CFG_OPTIONS_LOCAL->{$1} = $2;
      }
   }
}

close CUSTOM_FEATURE_CONFIG_HDR;
my $clean_setting;
if($INSIDE_MTK eq '0')
{
	$CUSTOM_FEATURE_CFG_OPTIONS{PROJECT_EXPECTED_RAM_LIMIT} = $clean_setting;
	$CUSTOM_FEATURE_CFG_OPTIONS{PROJECT_EXPECTED_CODE_LIMIT} = $clean_setting;
	$CUSTOM_FEATURE_CFG_OPTIONS{PROJECT_EXPECTED_RAM_LIMIT_NFB} = $clean_setting;
}
#$PROJECT_EXPECTED_RAM_LIMIT      = $CUSTOM_FEATURE_CFG_OPTIONS{PROJECT_EXPECTED_RAM_LIMIT};
#$PROJECT_EXPECTED_CODE_LIMIT     = $CUSTOM_FEATURE_CFG_OPTIONS{PROJECT_EXPECTED_CODE_LIMIT};
#$PROJECT_EXPECTED_RAM_LIMIT_NFB  = $CUSTOM_FEATURE_CFG_OPTIONS{PROJECT_EXPECTED_RAM_LIMIT_NFB};	
}



