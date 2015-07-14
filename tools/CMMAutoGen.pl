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
#*   CMMAutoGen.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script generates the CMM files for debugging
#*
#* Author:
#* -------
#*   Claudia Lo  (mtk01876)
#*
#****************************************************************************/

#****************************************************************************
# Included Modules
#****************************************************************************
use strict;
BEGIN { push @INC, './tools/' }  # add additional library path
use sysGenUtility;                 #pm file name without case sensitivity
use FileInfoParser;
use LISInfo;
use File::Copy;
use File::Basename;
use CommonUtility;
#****************************************************************************
# Constants
#****************************************************************************
my $CMMGEN_VERNO     = " m0.30";
                      #  m0.30, Support Build Info
                      #  m0.29, Support Debug Assistant
                      #  m0.24, Support CodeIntegrity Check with new template
                      #  m0.23, Support MT6572 and MT6582
                      #  m0.22, Set ResBreak Off on MT6280 for connecting to T32
                      #  m0.21, Remove Modem_Only.cmm's rule, add Info.cmm support
                      #  m0.20, Support Modem_Only.cmm
                      #  m0.19, Rename MT6583 to MT6589
                      #  m0.18, Fix CheckIntegrity based on ROM due to the change of region naming
                      #  m0.17, Support MT6583 in the same reg_base_mt6583.h
                      #  m0.16, Support get chip
                      #  m0.15, Move Dec2Hex from sysGenUtility to CommonUtility
                      #  m0.14, Support version check
                      #  m0.13, Support Check Code integrity for MT6280
                      #  m0.12, Support Platform in SwitchToClonedChip()
                      #  m0.11, Modify cmm to make dcm driver force on ARM clock (only for MT6280E1) 
                      #  m0.10, Change relative source path to be in DATA.LOAD.ELF
                      #  m0.09, Add relative source path and modify dbgsuite path for the one folder structure
                      #  v1.43, Remove winclear in BL/EXT_BL cmm and InTargetReset.cmm 
                      #  m0.08, Support precompile in GCC
                      #  m0.07, Support path and filename case sensitive on Linux
                      #  m0.06, Support GCC
                      #  m0.05, Support the one new architecture
                      #  m0.04 , Modify cmm for unstable MT6280 SIP connection
                      #  m0.03 , Skip GCC temporarily
                      #  v1.41 , Reset workaround for MT6250
                      #  v1.40 , support ALICE
                      #  v1.38 , Support Memory dump synced with sysgen2
                      #  m0.02 , Correct command for CR4
                      #  v1.37 , Support MT6922
                      #  m0.01 , Support MT6280
                      #  v1.36 , Parse LIS only when generatinig MAUI cmm files to prevent false alarm of parsing LIS error when generating BL/FOTA cmm files; correct MT6235B/MT6236B/MT6921 reg_base file name
                      #  v1.30 , Modify TK6280 CMM to support CR4 template
                      #  v1.21 , Support TK6280 CMM Gen
                      #  v1.35 , Generate MAUI/BL/EXT_BL/FOTA nocode.cmm and utility cmm from CMMAutoGen.pl
                      #  v1.34 , Skip EXTSRAM_TMP_PAGE_TABLE to sync MTK_Only.cmm with memory dump
                      #  v1.33 , Remove mmv2_offline_restore.cmm because it is merged to BasicAnalysis.cmm
                      #  v1.32 , Modify MT6575 nocode.cmm for Device APC
                      #  v1.31 , Fix MT6252 CMM not sync with dump issue for DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI and CACHED_EXTSRAM_NVRAM_LTABLE
                      #          Restore ZIMAGE dump
                      #          Make OS configurations independent of makefile
                      #  v1.29 , Correct MTK_Only.cmm to follow new continuous regions and rule after adding MMIPOOL and VIDEOPOOL
                      #  v1.28 , Modify MT6255 CMM file to work-around and set PC at boot-rom due to invalid boot code
                      #  v1.27 , Load SINGLE_BANK_CODE region for MT6252 to restore single-bank symbols
                      #  v1.26 , Skip NVRAM_LTABLE because it'll append on other regions
                      #  v1.25 , Clear only 128KB RAM disk and clear RAM disk only when RAM disk exists
                      #  v1.24 , Load FLMM_STACKSPACE to support Stack Isolation
                      #  v1.23 , Remove flash_opt.h input parameter and flash_opt.h part for this file is no longer used in CMM Gen and is removed
                      #  v1.22 , Skip FLMM EXTSRAM region because it is continuous with DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI
                      #  v1.20 , Modify MT6256 MTK_Only.cmm to correct Sys RAM base by retrieving from LIS file, and to add vector table dump
                      #  v1.19 , Correct MMv2_offline_restore.cmm path for MMv2
                      #  v1.18 , Support MMv2
                      #  v1.17 , Change MT6256 CPU to ARM1176JZF
                      #  v1.16 , Get EXTSRAM_FS information from lis file and then embed these information in nocode.cmm to adapt to EXTSRAM_FS location change for memory reduction
                      #  v1.14 , Modify MT6575 nocode.cmm to enable system reset and to add EMI BW limiter
                      #  v1.10 , Support MT6575 CMM Gen
                      #  v1.15 , Transform reg_base_mt6921.h into reg_base_mt6236.h to fix MT6921 RGU base missing issue
                      #  v1.12 , Support MT6921
                      #  v1.13 , Fix CMM file abort off missing issue due to eMMC booting side effect
                      #  v1.11 , Support eMMC Booting
                      #  v1.09 , Add MAUI_BIN input parameter and add this information to MAUI bin and DSP_ROM loading path; Correct MT6573 DPLL settings
                      #  v1.08 , Use NUCLEUS configuration instead of NUCLEUS_V2 to fix CVD unable to display Nucleus task information issue on MT6276
                      #  v1.07 , Remove redefinition check to prevent false alarm warnings
                      #  v1.06 , Copy ZIMAGE from load view to exec view so that the decompressed codes can be seen
                      #  v1.05 , To support makefile option USB_DOWNLOAD renamed as USB_DOWNLOAD_IN_BL
                      #  v1.04 , Generate l1assertbypass button under all platforms
                      #  v1.03 , Dump 0x0 on MT6252 to fix vector table corruption false alarm
                      #  v1.02 , Remove "Go" button on MT6251/MT6252/MT6252H because RTCK bug has been fixed on E2/E3
                      #  v1.01 , Set MT6251/MT6252/MT6252H JtagClock to RTCK because RTCK bug has been fixed on E2/E3
                      #  v1.00 , initial version after SS take over
my $CMMGEN_AUTHOR    = "Qmei Yang";

#****************************************************************************
# Input Parameters and Global Variables
#****************************************************************************
my $ACTION        = $ARGV[0];  # 0: MAUI nocode.cmm; 1: HQ_Only.cmm; 2: BL nocode.cmm; 3: EXT_BL nocode.cmm; 4: FOTA nocode.cmm
my $CMMFILE       = $ARGV[1];
my $ELFFILE       = $ARGV[2];
my $MAKEFILE      = $ARGV[3];
my $MAUI_BIN      = $ARGV[4];
my $LISFILE       = $ARGV[5];
my $CC_CMD        = $ARGV[6];
my $VIA_CMD       = $ARGV[7];
my $OPTION_TMP    = $ARGV[8];
my $TMP_FOLDER    = $ARGV[9];

my $DebugPrint = 0;
my $CMMDIR  = dirname($CMMFILE);
my $BUILDDIR  = dirname($ELFFILE);
my $g_strCOMPILER = undef;
print "ACTION: $ACTION,\nCMMFILE: $CMMFILE,\nCMMDIR:  $CMMDIR,\n
ELFFILE: $ELFFILE, \nMAKEFILE: $MAKEFILE,\n
MAUI_BIN: $MAUI_BIN, \nLISFILE: $LISFILE, \n
CC_CMD: $CC_CMD, \nVIA_CMD: $VIA_CMD, \nOPTION_TMP: $OPTION_TMP\n
TMP_FOLDER: $TMP_FOLDER\n";

#****************************************************************************
# 1 >>> Parse makefile
#****************************************************************************
my %MAKEFILE_OPTIONS;
my $PLATFORM;

if(1!=&FileInfo::Parse_MAKEFILE($MAKEFILE, \%MAKEFILE_OPTIONS))
{
    &error_handler("$MAKEFILE: Parse MakeFile failed", __FILE__, __LINE__);
}

$PLATFORM = &FileInfo::GetChip();
$PLATFORM = &sysUtil::SwitchToClonedChip($PLATFORM) if($PLATFORM ne "MT6582");
$g_strCOMPILER = &FileInfo::GetCompiler();


#****************************************************************************
# 2 >>> Parse reg_base.h
#****************************************************************************
my $REG_BASE_TMP_AFTER_TRANSFORM = "$TMP_FOLDER/~reg_base_after_transform.h";
my $REG_BASE_TMP_AFTER_PRECOMPILE = "$TMP_FOLDER/~reg_base_after_precompile.h";
my $REG_BASE_H = "./driver/sys_drv/regbase/inc/";
my %REG_BASE_DEFS;

### Determine reg_base.h by platform
my $platform_lc = lc(&DefineRegBaseChipName($PLATFORM));
my $reg_base_h_file = "reg_base_" . $platform_lc . "\.h";
$REG_BASE_H .= $reg_base_h_file;
copy ($REG_BASE_H, "$TMP_FOLDER/$reg_base_h_file");

### Change reg_base definitions to data structure for pre-compile
&reg_base_define_to_struct($TMP_FOLDER, $reg_base_h_file, $REG_BASE_TMP_AFTER_TRANSFORM);

### Pre-compile reg_base.h to get the correct register base addresses
my $status = system("$CC_CMD $VIA_CMD $OPTION_TMP -E $REG_BASE_TMP_AFTER_TRANSFORM > $REG_BASE_TMP_AFTER_PRECOMPILE") if($g_strCOMPILER eq "RVCT");
my $status = system("$CC_CMD $VIA_CMD$OPTION_TMP -E $REG_BASE_TMP_AFTER_TRANSFORM > $REG_BASE_TMP_AFTER_PRECOMPILE") if($g_strCOMPILER eq "GCC");
&error_handler("tools/CMMAutoGen.pl: pre-compile $REG_BASE_TMP_AFTER_TRANSFORM error!", __FILE__, __LINE__) if ($status != 0);

### Parse pre-compiled results and get the correct base address for each address
&parse_reg_base($REG_BASE_TMP_AFTER_PRECOMPILE, \%REG_BASE_DEFS);
if ($DebugPrint == 1)
{
    foreach (keys %REG_BASE_DEFS)
    {
        my $key = $_;
        my $value = $REG_BASE_DEFS{$_};
        print "#define $key $value\n";
    }
}


#****************************************************************************
# 3 >>> Generate MAUI nocode.cmm and utility cmm files
#****************************************************************************
if ($ACTION == 0)
{
    ### Parse LIS file first (do not parse LIS file outside to prevent unnecessary errors when LIS does not exist)
    &LISInfo::Parse($LISFILE);
    
    ### Generate MAUI nocode.cmm
    {
        my $maui_nocode_template;
    
        ### Copyright Statement
        $maui_nocode_template .= &template_copyright_file_header();
        
        ### verno string
        $maui_nocode_template .= &template_verno();
        ### Smart phone nocode.cmm is different from feature phone
        if ($PLATFORM eq 'MT6573')
        {
            ### set-up ICE connection; set default value for JTAG single processor mode; 
            ### set-up environmental variables; start ICE connection; 
            ### disable WDT; finish BROM and BL execution; break AP core; 
            ### enable daisy-chain to control MD; initialize TCM; initialize PLL; initialize EMI
            $maui_nocode_template .= &template_mt6573_nocode_preconfiguration();

            ### specify load binaries
            $maui_nocode_template .= &template_specify_load_binary_for_sp();
        }
        elsif ($PLATFORM eq 'MT6575')
        {
            ### set-up ICE connection; start ICE connection; disable WDT; 
            ### finish BROM and BL execution; initialize TCM; initialize PLL; initialize EMI
            $maui_nocode_template .= &template_mt6575_nocode_preconfiguration();

            ### specify load binaries
            $maui_nocode_template .= &template_specify_load_binary_for_sp();
        }
        else  # feature phone
        {
            ### CPU-related information and commands (chip-dependent)
            $maui_nocode_template .= &template_cpu_info_command($PLATFORM);
            
            ### disable watchdog (chip-dependent)
            $maui_nocode_template .= &template_disable_watchdog($PLATFORM, \%REG_BASE_DEFS);
            
            ### bypass CTIRQ1 precision check
            $maui_nocode_template .= &template_bypass_ctirq1_check(\%REG_BASE_DEFS);
            
            ### set MCU debugging notification to MDIF share memory to let DSP know mcu is in debugging (chip-dependent)
            $maui_nocode_template .= &template_set_mcu_debug_notice($PLATFORM, \%MAKEFILE_OPTIONS);
        
            ### disable DABORT and PABORT breakpoint (chip-dependent)
            $maui_nocode_template .= &template_disable_dabort_pabort_bkpt($PLATFORM, \%MAKEFILE_OPTIONS);
        }
   
        ### specify load elf
        $maui_nocode_template .= &template_specify_load_elf();
    
        ### add utilities for debugging
        $maui_nocode_template .= &template_add_utility_for_debug();
        
        ### add buttons for debugging
        $maui_nocode_template .= &template_add_button_for_debug($PLATFORM, \%MAKEFILE_OPTIONS);
        
        ### Smart phone nocode.cmm is different from feature phone
        if ($PLATFORM eq 'MT6573')
        {
            ### Load FS binary and add FS button
            $maui_nocode_template .= &template_load_fs_and_button_for_sp();
            
            ### add button for Meta; configure Trace/Codevisor; set PC to 0x0
            $maui_nocode_template .= &template_mt6573_nocode_postconfiguration();

            ### set attribute for breakpoints
            $maui_nocode_template .= &template_set_bkpt_attr_for_sp();
        }
        elsif ($PLATFORM eq 'MT6575')
        {
            ### Load FS binary and add FS button
            $maui_nocode_template .= &template_load_fs_and_button_for_sp();

            ### add button for Meta; set boot-jump address; configure MD UART
            $maui_nocode_template .= &template_mt6575_nocode_postconfiguration();

            ### set attribute for breakpoints
            $maui_nocode_template .= &template_set_bkpt_attr_for_sp();
        }
        else 
        {
            ### work-around on MT6280 E1 for dcm driver to force ARM clock on
            $maui_nocode_template .= &template_mt6280E1_DCM_workaround();
            ### set attribute for breakpoints
            $maui_nocode_template .= &template_set_bkpt_attr();
        
            ### work-around on MT6255 E1 to set PC to 0x48000000 (chip-dependent)
            $maui_nocode_template .= &template_mt6255_bootcode_workaround($PLATFORM);
        }
    
        ### clean win and endup
        $maui_nocode_template .= &template_clean_win_and_endup(1);
        
        open (CMM_FILE, ">$CMMFILE") or &error_handler("$CMMFILE: Unable to open $CMMFILE!\n", __FILE__, __LINE__);
        print CMM_FILE $maui_nocode_template;
        close CMM_FILE;
    }
    
    ### Generate InTargetReset.cmm
    {
        my $InTargetReset_cmm_file = "$CMMDIR/InTargetReset.cmm";
        my $InTargetReset_cmm_template;
        
        ### Copyright Statement
        $InTargetReset_cmm_template .= &template_copyright_file_header();
        
        ### verno string
        $InTargetReset_cmm_template .= &template_verno();
        
        ### utility purpose
        $InTargetReset_cmm_template .= &template_utility_description("InTargetReset.cmm", "Perform reset action");

        ### CPU-related information and commands (chip-dependent)
        $InTargetReset_cmm_template .= &template_cpu_info_command($PLATFORM);
        
        ### disable watchdog (chip-dependent)
        $InTargetReset_cmm_template .= &template_disable_watchdog($PLATFORM, \%REG_BASE_DEFS);
        
        ### set MCU debugging notification to MDIF share memory to let DSP know mcu is in debugging (chip-dependent)
        $InTargetReset_cmm_template .= &template_set_mcu_debug_notice($PLATFORM, \%MAKEFILE_OPTIONS);
    
        ### work-around on MT6255 E1 to set PC to 0x48000000 (chip-dependent)
        $InTargetReset_cmm_template .= &template_mt6255_bootcode_workaround($PLATFORM);
        ### work-around on MT6280 E1 for dcm driver to force ARM clock on
        $InTargetReset_cmm_template .= &template_mt6280E1_DCM_workaround();
    
        ### clean win and endup
        $InTargetReset_cmm_template .= &template_clean_win_and_endup(0);
        
        open (CMM_FILE, ">$InTargetReset_cmm_file") or &error_handler("$InTargetReset_cmm_file: Unable to open $InTargetReset_cmm_file!\n", __FILE__, __LINE__);
        print CMM_FILE $InTargetReset_cmm_template;
        close CMM_FILE;
    }

    ### Generate auto_reset.cmm [MAUI_00796491]
    {
        my $auto_reset_cmm_file = "$CMMDIR/auto_reset.cmm";
        my $auto_reset_cmm_template;
        
        ### Copyright Statement
        $auto_reset_cmm_template .= &template_copyright_file_header();
        
        ### verno string
        $auto_reset_cmm_template .= &template_verno();
        
        ### utility purpose
        $auto_reset_cmm_template .= &template_utility_description("auto_reset.cmm", "Auto Reset target with L1d assert disable");

        ### in-target reset
        $auto_reset_cmm_template .= &template_in_target_reset();

        ### bypass CTIRQ1 precision check
        $auto_reset_cmm_template .= &template_bypass_ctirq1_check(\%REG_BASE_DEFS);
        
        ### work-around on MT6280 E1 for dcm driver to force ARM clock on
        $auto_reset_cmm_template .= &template_mt6280E1_DCM_workaround();
        ### GO
        $auto_reset_cmm_template .= &template_go();
        
        open (CMM_FILE, ">$auto_reset_cmm_file") or &error_handler("$auto_reset_cmm_file: Unable to open $auto_reset_cmm_file!\n", __FILE__, __LINE__);
        print CMM_FILE $auto_reset_cmm_template;
        close CMM_FILE;
    }
    ### Generate Info.cmm
    {
        my $BuildFolder = dirname($LISFILE);
        &gen_info_cmm_from_template($PLATFORM, $BuildFolder, $ELFFILE, $MAUI_BIN, $CMMDIR);
    }
    

    ### Generate Debug_Go.cmm (under certain conditions)
    if (($MAKEFILE_OPTIONS{'CUST_CODE'} eq 'TC01') and ($MAKEFILE_OPTIONS{'DEMO_PROJECT'} eq 'TRUE'))
    {
        my $DebugGo_cmm_file = "./Debug_Go.cmm";
        my $DebugGo_cmm_template;
        
        ### Copyright Statement
        $DebugGo_cmm_template .= &template_copyright_file_header();
        
        ### verno string
        $DebugGo_cmm_template .= &template_verno();

        ### utility purpose
        $DebugGo_cmm_template .= &template_utility_description("Debug_Go.cmm", "Break at scheduler, perform some task and then resume");
        
        ### set breakpoint at scheduler
        $DebugGo_cmm_template .= &template_set_bkpt_at_scheduler(\%MAKEFILE_OPTIONS);
        
        open (CMM_FILE, ">$DebugGo_cmm_file") or &error_handler("$DebugGo_cmm_file: Unable to open $DebugGo_cmm_file!\n", __FILE__, __LINE__);
        print CMM_FILE $DebugGo_cmm_template;
        close CMM_FILE;
    }
}

#****************************************************************************
# 4 >>> Generate MAUI HQ_Only.cmm
#****************************************************************************
if ($ACTION == 1)
{
    my $hq_only_template;
    
    ### Parse LIS file first (do not parse LIS file outside to prevent unnecessary errors when LIS does not exist)
    &LISInfo::Parse($LISFILE);
    
    ### Generate BuildInfo.cmm
    {
        my $BuildInfoCMM = "$CMMDIR/BuildInfo.cmm";
        my $TemplateFolder = "./tools/DebuggingSuite/Misc/";
        my $template = &CommonUtil::GetFileContent($TemplateFolder."BuildInfoTemplate.cmm");
        $template = &Gen_Info_CMMContent($PLATFORM, $template, $ELFFILE, $MAUI_BIN);
        my $bbreg = &Gen_bb_reg_content(\%REG_BASE_DEFS);
        $template =~ s/\[CMMAUTOGEN_BBREG\]/$bbreg/g;
        open (OUTPUT_FILE, ">$BuildInfoCMM") or &error_handler("Unable to open $BuildInfoCMM!\n", __FILE__, __LINE__);
        print OUTPUT_FILE $template;
        close OUTPUT_FILE;
        print "Generate $BuildInfoCMM from ./tools/DebuggingSuite/Misc/BuildInfoTemplate.cmm\n";        
    }
    
    ### Read Template.cmm
    my $Template_cmm_file = "./tools/DebuggingSuite/Misc/Template.cmm";
    open (TEMPLATE_CMM_FILE, "<$Template_cmm_file") or &error_handler("$Template_cmm_file: Unable to open $Template_cmm_file!\n", __FILE__, __LINE__);
    {
        local $/;
        my $template_cmm_content = <TEMPLATE_CMM_FILE>;
        $hq_only_template .= &gen_hq_only_cmm_from_template_cmm($template_cmm_content);
    }
    close TEMPLATE_CMM_FILE;
    
    ### Write HQ_Only.cmm
    open (CMM_FILE, ">$CMMFILE") or &error_handler("$CMMFILE: Unable to open $CMMFILE!\n", __FILE__, __LINE__);
    print CMM_FILE $hq_only_template;
    close CMM_FILE;
}

#****************************************************************************
# 5 >>> Generate BL/EXT_BL/FOTA nocode.cmm with the same templates and different ELF files
#****************************************************************************
if (($ACTION == 2) or ($ACTION == 3) or ($ACTION == 4))
{
    my $bl_nocode_template;

    ### Copyright Statement
    $bl_nocode_template .= &template_copyright_file_header();
    
    ### verno string
    $bl_nocode_template .= &template_verno();
    
    ### CPU-related information and commands (chip-dependent)
    $bl_nocode_template .= &template_cpu_info_command($PLATFORM);
    
    ### disable watchdog (chip-dependent)
    $bl_nocode_template .= &template_disable_watchdog($PLATFORM, \%REG_BASE_DEFS);
    
    ### specify load elf
    $bl_nocode_template .= &template_specify_load_elf();

    ### set attribute for breakpoints
    $bl_nocode_template .= &template_set_bkpt_attr();

    ### work-around on MT6255 E1 to set PC to 0x48000000 (chip-dependent)
    $bl_nocode_template .= &template_mt6255_bootcode_workaround($PLATFORM);

    ### clean win and endup
    $bl_nocode_template .= &template_clean_win_and_endup(0);
    
    open (BLCMM_FILE, ">$CMMFILE") or &error_handler("$CMMFILE: Unable to open $CMMFILE!\n", __FILE__, __LINE__);
    print BLCMM_FILE $bl_nocode_template;
    close BLCMM_FILE;
}

exit;


#****************************************************************************
# subroutine:  reg_base_define_to_struct
# input:       $strInputFileFolder : folder of input reg_base.h
#              $strInputFile:  reg_base.h
#              $strOutputFilePath: path of output file for definitions of reg_base
#****************************************************************************
sub reg_base_define_to_struct
{
    my ($strInputFileFolder, $strInputFile, $strOutputFilePath) = @_;

    open (INPUT_FILE, "<$strInputFileFolder/$strInputFile") or &error_handler("$strInputFileFolder/$strInputFile: Unable to open $strInputFile!\n", __FILE__, __LINE__);
    open (OUTPUT_FILE, ">$strOutputFilePath") or &error_handler("$strOutputFilePath: Unable to open $strOutputFilePath!\n", __FILE__, __LINE__);

    print OUTPUT_FILE "\#include \"$strInputFile\"\n\n";
    print OUTPUT_FILE "typedef struct dummy_reg\n{\n";
    while (<INPUT_FILE>)
    {
        my ($reg);

        if (/^#define\s+(\w+)\s+\(*\w+\)*/)
        {
            $reg = $1;
            print OUTPUT_FILE "\tint $reg\_decl = $reg;\n";
        }
    }
    print OUTPUT_FILE "}\n";

    close INPUT_FILE;
    close OUTPUT_FILE;
    
    return;
}

#****************************************************************************
# subroutine:  parse_reg_base
# input:       $strInputFilePath: pre-compiled reg_base.h
#              $hrefRegBase:      hash reference to reg_base
#****************************************************************************
sub parse_reg_base
{
    my ($strInputFilePath, $hrefRegBase) = @_;

    open (INPUT_FILE, "<$strInputFilePath") or &error_handler("$strInputFilePath: Unable to open $strInputFilePath!\n", __FILE__, __LINE__);

    while (<INPUT_FILE>)
    {
        if (/\s*int\s+(\w+)\_decl\s+\=\s+\(*(\w+)\)*;/)
        {
            my $reg = uc($1);
            $hrefRegBase->{$reg} = $2;
        }
    }

    close INPUT_FILE;
    
    return;
}

#****************************************************************************
# subroutine:  get_cpu_type
# input:       $bb: platform
# output:      CPU type string
#****************************************************************************
sub get_cpu_type
{
    my ($bb) = @_;
    
    ### Determine CPU type
    my $strCPUType;
    if (&sysUtil::is_arm7($bb))
    {
        $strCPUType = "ARM7EJS";
    }
    elsif ((&sysUtil::is_arm9($bb)) or ($bb eq 'MT6270A'))
    {
        $strCPUType = "ARM926EJ";
    }
    elsif (&sysUtil::is_arm11($bb))
    {
        if ($bb eq 'MT6256')  # MT6256 contains VFP
        {
            $strCPUType = "ARM1176JZF";
        }
        else
        {
            $strCPUType = "ARM1176JZ";
        }
    }
    elsif (&sysUtil::is_CR4($bb))
    {
        $strCPUType = "CortexR4";
    }
    else
    {
        &error_handler("$MAKEFILE: Unsupported platform $bb!\n", __FILE__, __LINE__);
    }
    
    return $strCPUType;
}
#****************************************************************************
# subroutine:  gen_info_cmm_from_template
# input:       
# output:      
#****************************************************************************
sub gen_info_cmm_from_template
{
    my ($org_bb, $strBuildFolder, $strELFPathInCMM, $strBinName, $CMMDIR) = @_;
    my $bb = &DefineRegBaseChipName($org_bb);
    if(&FileInfo::is("SMART_PHONE_CORE", "MODEM_ONLY"))
    {#modem only load, do copy bin
        &CopyBLBin($bb, $strBuildFolder);
    }
    &GenInfoTemplate($org_bb, $CMMDIR, $strELFPathInCMM, $strBinName); # always generate it if needed
}

sub CopyBLBin  #called by gen_info_cmm_from_template
{ # get bin path, copy bin
    my ($bb, $strDestBinFolder) = @_; # $bb= e.g. MT6589, not MT6589_MD2
    $strDestBinFolder .= "/";
    my $strBinFolder = "./service/bootloader_bin/";
    my $Bins_aref = &FindBBRelatedFile($strBinFolder, $bb, "\.elf\$|\.bin\$");
    foreach my $bin (@$Bins_aref)
    {
        print "copy ".$strBinFolder.$bin." -> ". $strDestBinFolder.$bin."\n";
        copy($strBinFolder.$bin, $strDestBinFolder.$bin);
    }
}

sub GenInfoTemplate #called by gen_info_cmm_from_template
{
    my ($org_bb, $CMMDIR, $strELFPathInCMM, $strBinName) = @_; # bb=e.g.MT6589_MD1, not MT6589
    my $TemplateFolder = "./tools/DebuggingSuite/Misc/";
    my $Files_aref = &FindBBRelatedFile($TemplateFolder, $org_bb, "\.cmm\$");
    foreach my $file(@$Files_aref)
    {
        my $strDestPath = "$CMMDIR/$file";
        my $template = &CommonUtil::GetFileContent($TemplateFolder.$file);
        $template = &Gen_Info_CMMContent($org_bb, $template, $strELFPathInCMM, $strBinName);
        open (OUTPUT_FILE, ">$strDestPath") or &error_handler("Unable to open $strDestPath!\n", __FILE__, __LINE__);
        print OUTPUT_FILE $template;
        close OUTPUT_FILE;
        print "Generate $strDestPath from ./tools/DebuggingSuite/Misc/$file\n";
    }
}
sub FindBBRelatedFile 
{
    my ($Folder, $bb, $FileExtension) = @_;
    opendir( my $DIR, $Folder) || &sysUtil::sysgen_die("Can't open $Folder!", __FILE__, __LINE__);
    my @Files = grep { /$bb/i and /$FileExtension/i} readdir( $DIR );
    closedir $DIR; 
    return \@Files;
}

sub Gen_Info_CMMContent #called by gen_info_cmm_from_template
{
    my ($org_bb, $template, $strELFPath, $strBinName) = @_;
    my $strBinPath = dirname($strELFPath)."/".$strBinName;
    my $nChipSelect = "";
    $nChipSelect = ($org_bb =~ /MD1/i) ? 1 : 2 if($org_bb =~ /MT6589/i );

    $template =~ s/\[CMMAUTOGEN_ChipSelect\]/$nChipSelect/g;
    $template =~ s/\[CMMAUTOGEN_ELFPath\]/$strELFPath/g;
    $template =~ s/\[CMMAUTOGEN_SrcPath\]/..\/..\/..\/../g;
    $template =~ s/\[CMMAUTOGEN_BINPath\]/$strBinPath/g;
    
    return $template;
}
sub Gen_bb_reg_content
{
    my ($reg_base_href) = @_;
    my $template;
    foreach my $key (keys %$reg_base_href)
    {
        my $value = $reg_base_href->{$key};
        $template .= "GLOBAL &$key\n&$key=($value)\n";    
    }
    return $template;    
}

#****************************************************************************
# subroutine:  gen_hq_only_cmm_from_template_cmm
# input:       $strInputContent: one line from Template.cmm to be replaced into HQ_Only.cmm
# output:      replaced HQ_Only.cmm line
#****************************************************************************
sub gen_hq_only_cmm_from_template_cmm
{
    my ($strInputContent) = @_;

    my $strReplacedContent = $strInputContent;

    ### Replace [CMMGEN_VERNO] with template_verno
    my $cmmgen_verno = &template_verno();
    $strReplacedContent =~ s/\[CMMGEN_VERNO\]/$cmmgen_verno/g;
    
    ### Replace [ARM] with the correct CPU
    my $strCPUType = &get_cpu_type($PLATFORM);
    $strReplacedContent =~ s/\[ARM\]/$strCPUType/g;

    ### Replace [ELF] with ELF path
    $strReplacedContent =~ s/\[ELF\]/$ELFFILE/g;

    ### Replace [PATH] with .
    $strReplacedContent =~ s/\[PATH\]/..\/..\/..\/../g;

    ### Replace [ELFPARA] with empty 
    $strReplacedContent =~ s/\[ELFPARA\]/\/ZeroSym/g;

    ### Replace [BIN_PATH] with T:
    $strReplacedContent =~ s/\[BIN_PATH\]/T:/g;

    ### Replace [DBGSUITE_PATH] with tools\\DebuggingSuite
    $strReplacedContent =~ s/\[DBGSUITE_PATH\]/..\\..\\..\\..\\tools\\DebuggingSuite/g;

    ### Replace [DBG_BUTTON] with GPRS/UAS buttons
    my $DBG_BUTTON= <<"__TEMPLATE";
menu.reprogram &DBGSUITE_PATH\\Misc\\Assistant
menu.reprogram gprs
menu.reprogram uas
__TEMPLATE
    $strReplacedContent =~ s/\[DBG_BUTTON\]/$DBG_BUTTON/g;
    
    ### before using all dump information, parse lis/sym first:
    &LISInfo::ClassifyRegionType(\%MAKEFILE_OPTIONS);
    
    ### Replace [DATA_COPY_TO_VM] with CODE region list
    my $strDATA_COPY_TO_VM = &gen_DATA_COPY_TO_VM();
    $strReplacedContent =~ s/\[DATA_COPY_TO_VM\]/$strDATA_COPY_TO_VM/g;

    ### Replace [ASSIGN_VERNO_INFO] with verno info assignment
    my $strASSIGN_VERNO_INFO = &get_version_from_elf_template();
    $strReplacedContent =~ s/\[ASSIGN_VERNO_INFO\]/$strASSIGN_VERNO_INFO/g;
    ### Replace [BINARY] with loading memory dump regions
    my $strBinary = &gen_dump_regions_template();
    $strReplacedContent =~ s/\[BINARY\]/$strBinary/g;
    
    ### Replace [CHECK_CODE]
    my $strSAVE_CHECK_CODE_CMD = &gen_SAVE_CHECK_CODE_CMD();
    $strReplacedContent =~ s/\[CHECK_CODE\]/$strSAVE_CHECK_CODE_CMD/g;
    
    print "strReplacedContent=$strReplacedContent" if ($DebugPrint == 1);
    return $strReplacedContent;
}
sub gen_DATA_COPY_TO_VM
{
    my $template;
    my $Region_aref = LISInfo::GetDumpCodeRegions(\%MAKEFILE_OPTIONS);
    foreach my $RegionName (@$Region_aref)
    {
        if($RegionName =~ /0x/)
        {#workaround for VECTOR_TABLE dump region
            $template .= "data.copy $RegionName--($RegionName+0x200) VM:$RegionName\n";
        }
        else
        {
            $template .= "data.copy Load\$\$$RegionName\$\$Base--(Load\$\$$RegionName\$\$Base+Image\$\$$RegionName\$\$Length) VM:Image\$\$$RegionName\$\$Base\n";
        }
    }
    return $template;
}

sub gen_SAVE_CHECK_CODE_CMD
{
    my $template;
    my $Region_aref = LISInfo::GetDumpCodeRegions(\%MAKEFILE_OPTIONS);
    my $i = 0;
    foreach my $RegionName (@$Region_aref)
    {
        $template .= '&command_count=&command_count+1'."\n" if($i!=0);
        my ($strBase, $strLength, $strHintName) = (undef, undef, "ROM_CODE");
        if($RegionName =~ /0x/)
        {#workaround for VECTOR_TABLE dump region
            ($strBase, $strLength) = ($RegionName, "0x200");
        }
        else
        {
            ($strBase, $strLength) = ("Image\$\$$RegionName\$\$Base", "Image\$\$$RegionName\$\$Length");
            $strHintName = "INT_CODE" if($RegionName =~/INTSRAM/i);
        }

        my $strDataSet = <<"__TEMPLATE";
DATA.SET VM:(&pool_addr+&command_size*&command_count) %LONG 0x1 ; op code
DATA.SET VM:(&pool_addr+&command_size*&command_count+0x4) %LONG $strBase ; start address
DATA.SET VM:(&pool_addr+&command_size*&command_count+0x8) %LONG $strLength ; length
DATA.SET VM:(&pool_addr+&command_size*&command_count+0xC) "$strHintName" 0x0 ; name
__TEMPLATE
        $template .= $strDataSet;
        $i++;
    }
    
    if(FileInfo::isnot("SW_BINDING_SUPPORT", "NONE"))
    {
        my $strDataSet = <<"__TEMPLATE";
&command_count=&command_count+1
; bypass INT_IntializeSystemMemory in ROM_CODE
DATA.SET VM:(&pool_addr+&command_size*&command_count) %LONG 0xFFFFFFFF ; op code
DATA.SET VM:(&pool_addr+&command_size*&command_count+0x4) %LONG INT_IntializeSystemMemory ; start address
DATA.SET VM:(&pool_addr+&command_size*&command_count+0x8) %LONG Y.SIZEOF(INT_IntializeSystemMemory) ; length
DATA.SET VM:(&pool_addr+&command_size*&command_count+0xC) "BYPASS" 0x0 ; name
__TEMPLATE
        $template .= $strDataSet;
    }
    
    if(FileInfo::is("BOOT_CERT_SUPPORT", "BOOT_CERT_V2"))
    {
        my $strDataSet = <<"__TEMPLATE";
&command_count=&command_count+1
; bypass g_SRD_INFO in ROM_CODE
DATA.SET VM:(&pool_addr+&command_size*&command_count) %LONG 0xFFFFFFFF ; op code
DATA.SET VM:(&pool_addr+&command_size*&command_count+0x4) %LONG g_SRD_INFO ; start address
DATA.SET VM:(&pool_addr+&command_size*&command_count+0x8) %LONG Y.SIZEOF(g_SRD_INFO) ; length
DATA.SET VM:(&pool_addr+&command_size*&command_count+0xC) "BYPASS" 0x0 ; name
__TEMPLATE
        $template .= $strDataSet;
    }
    return $template;
}

sub get_version_from_elf_template
{
    my $template;
    my $strRegionName = "PRIMARY_CACHED_EXTSRAM";
    if(!&LISInfo::IsRegionExistent($strRegionName) and &LISInfo::IsRegionExistent("CACHED_EXTSRAM"))
    {
        $strRegionName = "CACHED_EXTSRAM";
    }
    elsif(!&LISInfo::IsRegionExistent("CACHED_EXTSRAM") and &LISInfo::IsRegionExistent("EXTSRAM"))
    {
        $strRegionName = "EXTSRAM";
    }
    elsif(!&LISInfo::IsRegionExistent("EXTSRAM") and &LISInfo::IsRegionExistent("INTSRAM_DATA"))
    {
        $strRegionName = "INTSRAM_DATA";
    }
    else
    {
        &error_handler("Can't judge verno in which section", __FILE__, __LINE__);            
    }
    
    $template = <<"__TEMPLATE";
&ELF_VERNO_ADDR=V.VALUE((int)&RELEASE_VERNO_RW\$\$Base - (int)&Image\$\$$strRegionName\$\$Base + (int)&Load\$\$$strRegionName\$\$Base)
&ELF_BRANCH_ADDR=V.VALUE((int)&RELEASE_BRANCH_RW\$\$Base - (int)&Image\$\$$strRegionName\$\$Base + (int)&Load\$\$$strRegionName\$\$Base)
&ELF_BTIME_ADDR=V.VALUE((int)&BUILD_TIME_RW\$\$Base - (int)&Image\$\$$strRegionName\$\$Base + (int)&Load\$\$$strRegionName\$\$Base)
__TEMPLATE
    return $template;
}

sub gen_dump_regions_template
{
    my $template;
    my $DumpRegions_ref = &LISInfo::GetDumpExeRegions(\%MAKEFILE_OPTIONS);
    my $BIN_PATH = $BUILDDIR ."\\". $MAUI_BIN;
    print "-----------------DUMP Regions-----------------\n";
    foreach my $strGroupName (keys %$DumpRegions_ref)
    {
        my $array_ref = $DumpRegions_ref->{$strGroupName};
        foreach my $RegionItem (@$array_ref)
        {
            my $RegionName = $RegionItem->[0];
            my $strBase = &LISInfo::GetDumpRegionBase($strGroupName, $RegionName, $BIN_PATH, $PLATFORM);
            print "[$strGroupName]$RegionName: $strBase\n";
            $template .= "D.LOAD.BINARY &BIN_PATH\\sys_mem_$strBase.bin $strBase /byte /nosymbol\n";
        }
    }
    print "----------------------------------------------\n";
    return $template;
}
sub get_dump_code_regions
{
    my @DumpCodeRegions;
    
    return \@DumpCodeRegions;    
}

#****************************************************************************
# subroutine:  template_copyright_file_header
#              (this template will be used by MAUI nocode.cmm, BL nocode.cmm, EXT_BL nocode.cmm, and FOTA nocode.cmm)
# output:      template of copyright file header
#****************************************************************************
sub template_copyright_file_header
{
    my $template = <<"__TEMPLATE";
; Copyright Statement:
; --------------------
; This software is protected by Copyright and the information contained
; herein is confidential. The software may not be copied and the information
; contained herein may not be used or disclosed except with the written
; permission of MediaTek Inc. (C) 2005
; 
; BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
; THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
; RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
; AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
; EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
; MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
; NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
; SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
; SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
; THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
; NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
; SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
; 
; BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
; LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
; AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
; OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
; MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
; 
; THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
; WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
; LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
; RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
; THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  template_verno
#              (this template will be used by MAUI nocode.cmm, BL nocode.cmm, EXT_BL nocode.cmm, and FOTA nocode.cmm)
# output:      template of verno and author information
#****************************************************************************
sub template_verno
{
    my $template = <<"__TEMPLATE";
; CMMAutoGen$CMMGEN_VERNO by $CMMGEN_AUTHOR

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  template_cpu_info_command
#              (this template will be used by MAUI nocode.cmm, BL nocode.cmm, EXT_BL nocode.cmm, and FOTA nocode.cmm)
# input:       $bb: platform
# output:      template of CPU-related information and commands
#****************************************************************************
sub template_cpu_info_command
{
    my ($bb) = @_;
    
    ### Determine CPU type
    my $strCPUType = &get_cpu_type($bb);
    
    my $template = "; CPU_info_command\n";
    if (&sysUtil::is_arm11($bb))
    {
        $template .= <<"__TEMPLATE_ARM11";
SYStem.RESet
SYStem.CPU $strCPUType
SYStem.JtagClock Rtck
System.Option Cflush on     ;flush the cache to avoid data consistency
System.Option ResBreak off  ;Dont hold the ARM11 core after reset
SYStem.Up
R.S PC 0x00000000

setup.IMASKHLL ON
setup.IMASKASM ON

__TEMPLATE_ARM11
    }
    elsif (&sysUtil::is_CR4($bb))
    {
        my %COREBASE_tbl = 
        (
            "TK6280" => "0x80090000",
            "MT6280" => "0xA0093000",
        );
        my $COREBASE = $COREBASE_tbl{$bb};
        $template .= <<"__TEMPLATE_CR4";
SYStem.RESet
SYStem.CPU $strCPUType
System.Option Cflush on                    ; flush the cache to avoid data consistency
SYStem.JtagClock 1MHz                      ; For DAP-lite Jtag connection
SYStem.MultiCore COREBASE APB:$COREBASE    ; For CoreSight
SYStem.MultiCore DEBUGACCESSPORT 0         ; Specify which port of DAP is used for access ARM Debug Registers (0~255)
SYStem.MultiCore MEMORYACCESSPORT 0        ; Specify which port of DAP is used for access Memory (0~255)
System.Option EnReset on
SYStem.Up

setup.IMASKHLL ON
setup.IMASKASM ON

__TEMPLATE_CR4
    }
    else
    {
        my $MT6250_ResetWorkaround = &template_mt6250_reset_workaround($bb);
        $template .= <<"__TEMPLATE_OTHER";
SYStem.RESet
SYStem.CPU $strCPUType
SYStem.JtagClock RTCK.
sys.o cflush on
SYStem.Up
$MT6250_ResetWorkaround
setup.IMASKHLL ON
setup.IMASKASM ON

__TEMPLATE_OTHER
    }

    return $template;
}

#****************************************************************************
# subroutine:  template_disable_watchdog
#              (this template will be used by MAUI nocode.cmm, BL nocode.cmm, EXT_BL nocode.cmm, and FOTA nocode.cmm)
# input:       $bb: platform
#              $hrefRegBase: hash reference of reg_base
# output:      template of disabling watchdog commands
#****************************************************************************
sub template_disable_watchdog
{
    my ($bb, $hrefRegBase) = @_;
    
    ### Get RGU_Base
    my $strRGUBaseAddr = $hrefRegBase->{'RGU_BASE'};

    my $template = <<"__TEMPLATE";
; disable_watchdog
D.S SD:$strRGUBaseAddr %LE %WORD 0x2200

__TEMPLATE

    my %AP_WDT_tbl = 
    (
        "TK6280" => "0x61050000",
        "MT6280" => "0xA0030000",
    );
    my $AP_WDT = $AP_WDT_tbl{$bb};
    my $template_AP_WDT = <<"__TEMPLATE_AP_WDT";
; MD WDT
D.S SD:$strRGUBaseAddr %LE %WORD 0x2220

; AP WDT
D.S SD:$AP_WDT %LE %WORD 0x2220

__TEMPLATE_AP_WDT

    if (exists $AP_WDT_tbl{$bb})
    {
        return $template_AP_WDT;
    }
    else
    {
        return $template;
    }
}

#****************************************************************************
# subroutine:  template_bypass_ctirq1_check
#              (this template will be used by MAUI nocode.cmm)
# input:       $hrefRegBase: hash reference of reg_base
# output:      template of bypass CTIRQ1 precision check
#****************************************************************************
sub template_bypass_ctirq1_check
{
    my ($hrefRegBase) = @_;
    
    ### Get BSI_Base
    my $nBSIBaseAddr = hex($hrefRegBase->{'BSI_BASE'});
    my $strBSIBaseAddr1 = sprintf("0x%08X", $nBSIBaseAddr+8);
    my $strBSIBaseAddr2 = sprintf("0x%08X", $nBSIBaseAddr+16);

    my $template = <<"__TEMPLATE";
; bypass_CTIRQ1_precision_check
; Avoiding assert at CTIRQ1/2
D.S SD:$strBSIBaseAddr1 %LE %WORD 0xABCD
D.S SD:$strBSIBaseAddr2 %LE %WORD 0x0003     ; bit0: disable CTIRQ1/2 timing check

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  template_set_mcu_debug_notice
#              (this template will be used by MAUI nocode.cmm)
# input:       $bb:              platform
#              $hrefMakefileOpt: hash reference of makefile options
# output:      template of setting MCU debugging notification to MDIF share memory
#****************************************************************************
sub template_set_mcu_debug_notice
{
    my ($bb, $hrefMakefileOpt) = @_;
    
    if ((defined $hrefMakefileOpt->{'DSP_SOLUTION'}) and ($hrefMakefileOpt->{'DSP_SOLUTION'} eq 'DUALMACDSP'))
    {
        ### Determine base address to send to MDIF
        my $strMCUDSPChkAddr;
        if ($bb eq 'MT6276')
        {
            $strMCUDSPChkAddr = "0x650008FC";
        }
        elsif ($bb eq 'MT6270A')
        {
            $strMCUDSPChkAddr = "0x420008FC";
        }
        elsif (($bb eq 'MT6573') or ($bb eq 'MT6575'))
        {
            $strMCUDSPChkAddr = "0x614008FC";
        }
        else
        {
            &error_handler("$MAKEFILE: Unsupported platform $bb with DSP_SOLUTION set as DUALMACDSP!\n", __FILE__, __LINE__);
        }
        
        my $template = <<"__TEMPLATE";
; Set MCU debugging notification to MDIF share memory to let DSP know mcu is in debugging
D.S SD:$strMCUDSPChkAddr \%LE \%LONG 0x4455434D          ; MCUD

__TEMPLATE

        return $template;
    }

    return;
}

#****************************************************************************
# subroutine:  template_disable_dabort_pabort_bkpt
#              (this template will be used by MAUI nocode.cmm)
# input:       $bb:              platform
#              $hrefMakefileOpt: hash reference of makefile options
# output:      template of disabling DABORT and PABORT breakpoint
#****************************************************************************
sub template_disable_dabort_pabort_bkpt
{
    my ($bb, $hrefMakefileOpt) = @_;
    
    if ($bb eq 'TK6280' and $bb eq 'MT6280')
    {
        my $template = <<"__TEMPLATE";
; disable DABORT and PABORT breakpoint
tronchip.set dabort off
tronchip.set pabort off
tronchip.set reset off

__TEMPLATE

        return $template;
    }
    elsif (((defined $hrefMakefileOpt->{'NAND_FLASH_BOOTING'}) and ($hrefMakefileOpt->{'NAND_FLASH_BOOTING'} ne 'NONE')) or ((defined $hrefMakefileOpt->{'EMMC_BOOTING'}) and ($hrefMakefileOpt->{'EMMC_BOOTING'} ne 'NONE')))
    {
        if ((&sysUtil::is_arm9($bb)==1) or (&sysUtil::is_arm11($bb)==1) or ($bb eq 'MT6270A'))
        {
            my $template = <<"__TEMPLATE";
; disable DABORT and PABORT breakpoint
tronchip.set dabort off
tronchip.set pabort off

__TEMPLATE

            return $template;
        }
    }
    
    return;
}

#****************************************************************************
# subroutine:  template_specify_load_elf
#              (this template will be used by MAUI nocode.cmm, BL nocode.cmm, EXT_BL nocode.cmm, and FOTA nocode.cmm)
# input:       
# output:      template of loading ELF
#****************************************************************************
sub template_specify_load_elf
{
    my $template = <<"__TEMPLATE";
; specify_load_elf
D.LOAD.ELF $ELFFILE \/RELPATH \/PATH "..\/..\/..\/.." \/nocode
__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  template_add_utility_for_debug
#              (this template will be used by MAUI nocode.cmm)
# input:
# output:      template of debugging utilities
#****************************************************************************
sub template_add_utility_for_debug
{
    my $template = <<"__TEMPLATE";
; add_utility_for_debugging
GLOBAL &DBGSUITE_PATH
&DBGSUITE_PATH=\"..\\..\\..\\..\\tools\\DebuggingSuite\"

if version.build()==0x100000 
(
    task.config &DBGSUITE_PATH\\Misc\\NUCLEUS
)
else
(
    if y.exist(TCT_Schedule)
    (
        task.config &DBGSUITE_PATH\\Misc\\NUCLEUS
        menu.reprogram &DBGSUITE_PATH\\Misc\\NUCLEUS
    )
    else
    (
        task.config &DBGSUITE_PATH\\Misc\\NUCLEUS_V2
        menu.reprogram &DBGSUITE_PATH\\Misc\\NUCLEUS_V2
    )
)

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  template_add_button_for_debug
#              (this template will be used by MAUI nocode.cmm)
# input:       $hrefMakefileOpt: hash reference of makefile options
# output:      template of debugging buttons
#****************************************************************************
sub template_add_button_for_debug
{
    my ($bb, $hrefMakefileOpt) = @_;
    
    ### Determine whether to load Debug button
    my $debug_button_template;
    if (($hrefMakefileOpt->{'CUST_CODE'} eq 'TC01') and ($hrefMakefileOpt->{'DEMO_PROJECT'} eq 'TRUE'))
    {        
        $debug_button_template = <<"__TEMPLATE_DEBUG_BUTTON";
menu.reprogram Debug
__TEMPLATE_DEBUG_BUTTON
    }
    $debug_button_template .= "menu.reprogram Cortex-R_MPU_View\n" if(&sysUtil::is_CR4($bb));
    
    ### Determine whether to load GPRS/UAS buttons
    my $ps_button_template;
    if ($hrefMakefileOpt->{'MODE'} eq 'GPRS')
    {
        $ps_button_template = <<"__TEMPLATE_PS_BUTTON";
menu.reprogram gprs
__TEMPLATE_PS_BUTTON
    }
    elsif ($hrefMakefileOpt->{'MODE'} eq 'UMTS')
    {
        $ps_button_template = <<"__TEMPLATE_PS_BUTTON";
menu.reprogram gprs
menu.reprogram uas
__TEMPLATE_PS_BUTTON
    }
    
    my $template = <<"__TEMPLATE";
menu.reprogram InTargetReset
menu.reprogram l1assertbypass
$debug_button_template
$ps_button_template

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  template_set_bkpt_attr
#              (this template will be used by MAUI nocode.cmm, BL nocode.cmm, EXT_BL nocode.cmm, and FOTA nocode.cmm)
# input:       
# output:      template of setting breakpoints attribute
#****************************************************************************
sub template_set_bkpt_attr
{
    my $template = <<"__TEMPLATE";
; setting attribute of breakpoints
Break.Select Program OnChip
Break.Select Hll OnChip
Break.Select Spot OnChip
Break.Select Read OnChip
Break.Select Write OnChip

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  template_mt6255_bootcode_workaround
#              (this template will be used by MAUI nocode.cmm, BL nocode.cmm, EXT_BL nocode.cmm, and FOTA nocode.cmm)
# input:       $bb: platform
# output:      template of MT6255 work-around for bootcode
#****************************************************************************
sub template_mt6255_bootcode_workaround
{
    my ($bb) = @_;
    
    ### work-around only required for MT6255
    return if ($bb ne 'MT6255' and $bb ne 'MT6922');
    
    my $template = <<"__TEMPLATE";
;work-around on MT6255 E1 to set PC to 0x48000000 because boot code returns different values under different transactions
&HW_VER=DATA.LONG(D:0x80000000)
var.if &HW_VER==0xCA00
(
  R.S PC 0x48000000
)

__TEMPLATE

    return $template;
}
#****************************************************************************
# subroutine:  template_mt6250_reset_workaround
# input:       $bb: platform
# output:      template of MT6250 work-around for reset
#****************************************************************************
sub template_mt6250_reset_workaround
{
    my ($bb) = @_;
    ### work-around only required for MT6250
    return if ($bb ne 'MT6250');
    
    my $template = <<"__TEMPLATE";
    
&SW_CODE=DATA.LONG(D:0xA0000004)
&HW_CODE=DATA.LONG(D:0xA0000008)
var.if &SW_CODE!=0&&HW_CODE==625A 
(
D.S SD:0xA0730038 %LE %WORD 0x0601
D.S SD:0xA0730034 %LE %WORD 0x21FF
SYStem.Up
)
__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  template_clean_win_and_endup
#              (this template will be used by MAUI nocode.cmm, BL nocode.cmm, EXT_BL nocode.cmm, and FOTA nocode.cmm)
# input:       $bWinClear = 1: gen winclear, 0 or undef: not to generate winclear
# output:      template of clean win and endup
#****************************************************************************
sub template_clean_win_and_endup
{
    my ($bWinClear) = @_;
    my $winclear = undef;
    if($bWinClear == 1){
    $winclear = <<"__TEMPLATE";
; clean_win
winclear
__TEMPLATE
    }
    my $template = <<"__TEMPLATE";
$winclear
; endup
d.l
enddo

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  template_utility_description
#              (this template will be used by auto_reset.cmm and InTargetReset.cmm)
# input:       $strFileName: string of cmm file name
#              $strDesc:     string of descriptions
# output:      template of utility cmm header description string
#****************************************************************************
sub template_utility_description
{
    my ($strFileName, $strDesc) = @_;
    
    my $template = <<"__TEMPLATE";
; $strFileName
; $strDesc

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  template_in_target_reset
#              (this template will be used by auto_reset.cmm)
# input:
# output:      template of in-target reset
#****************************************************************************
sub template_in_target_reset
{
    my $template = <<"__TEMPLATE";
; In Target reset
SYStem.Mode EmulExt
Register.RESet

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  template_go
#              (this template will be used by auto_reset.cmm)
# input:
# output:      template of GO
#****************************************************************************
sub template_go
{
    my $template = <<"__TEMPLATE";
GO

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  template_set_bkpt_at_scheduler
#              (this template will be used by Debug_Go.cmm)
# input:       $hrefMakefileOpt: hash reference of makefile options
# output:      template of setting breakpoint at scheduler and go until break at scheduler
#****************************************************************************
sub template_set_bkpt_at_scheduler
{
    my ($hrefMakefileOpt) = @_;
    
    ### Determine scheduler symbol
    my $strScheduler;
    if ($hrefMakefileOpt->{'RTOS'} eq 'NUCLEUS')
    {
        $strScheduler = "TCT_Schedule";
    }
    elsif ($hrefMakefileOpt->{'RTOS'} eq 'NUCLEUS_V2')
    {
        $strScheduler = "TCCT_Schedule";
    }
    else
    {
        &error_handler("$MAKEFILE: Unsupported RTOS in makefile!\n", __FILE__, __LINE__);
    }
    
    ### Determine actions to be done during break at scheduler
    my $action_template;
    if (($hrefMakefileOpt->{'CUST_CODE'} eq 'TC01') and ($hrefMakefileOpt->{'DEMO_PROJECT'} eq 'TRUE'))
    {
        $action_template = &template_debug_go_disable_dcm_sm_l1_wdt(\%REG_BASE_DEFS);
    }
    
    my $template = <<"__TEMPLATE";
b.s $strScheduler
go

wait !run()

if r(pc)==address.offset($strScheduler)
(
    ; print "stop at $strScheduler"

$action_template

    b.d $strScheduler
    go
    ; d.l
)

enddo

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  template_debug_go_disable_dcm_sm_l1_wdt
#              (this template will be used by Debug_Go.cmm and will be called by template_set_bkpt_at_scheduler)
# input:       $hrefRegBase: hash reference of reg_base
# output:      template of disabling DCM, SM, L1_ASSERT_BYPASS, and WDT
#****************************************************************************
sub template_debug_go_disable_dcm_sm_l1_wdt
{
    my ($hrefRegBase) = @_;
    
    ### Get RGU_Base
    my $strRGUBaseAddr = $hrefRegBase->{'RGU_BASE'};

    my $template = <<"__TEMPLATE";
    ; disable DCM
    if Y.EXIST(dcm)
    (
        d.s address.offset(dcm) %LE %LONG 0x1
    )
    
    ; disable SleepMode
    if Y.EXIST(sm)
    (
        d.s address.offset(sm) %LE %LONG 0x1
    )
    
    ; disable L1 timing check
    d.s address.offset(L1_ASSERT_BYPASS) %LE %WORD 0x3
    
    ; disable WatchDog
    d.s SD:$strRGUBaseAddr %LE %WORD 0x2200
__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  template_specify_load_binary_for_sp
#              (this template will be used by MAUI nocode.cmm for smart phone)
# input:       
# output:      template of loading binaries for smart phone
#****************************************************************************
sub template_specify_load_binary_for_sp
{
    ### get build folder
    my $strBinPath = $ELFFILE;
    $strBinPath =~ s/\\[^\\]+\.elf$/\\/;
    my $strROMBin = $MAUI_BIN;
    
    ### check if binary lies under build folder or under bin folder
    my $strBinPath_tmp = $strBinPath . "\\" . $MAUI_BIN;
    if (opendir(TMP_DIR, $strBinPath_tmp))
    {
        $strBinPath = $strBinPath_tmp;
        $strROMBin = "ROM";
    }
    close(TMP_DIR);
    
    ### get ROM base
    my ($strROMBase, $strROMSize, $strROMMax, $strROMAttr) = &LISInfo::GetLoadRegionInfo("ROM", 1);
    
    ### get DSP_ROM base
    my ($strDSPROMBase, $strDSPROMSize, $strDSPROMMax, $strDSPROMAttr) = &LISInfo::GetLoadRegionInfo("DSP_ROM", 1); 
    
    my $template = <<"__TEMPLATE";
; load corresponding binaries
d.load.binary $strBinPath\\$strROMBin $strROMBase /long
d.load.binary $strBinPath\\DSP_ROM $strDSPROMBase /long

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  template_load_fs_and_button_for_sp
#              (this template will be used by MAUI nocode.cmm for smart phone)
# input:       
# output:      template of loading FS and adding button for FS
#****************************************************************************
sub template_load_fs_and_button_for_sp
{
    ### get EXTSRAM_FS base
    my ($nFSBase, $nFSSize, $nFSMax, $strFSAttr) = &LISInfo::GetExeRegionInfo("EXTSRAM_FS", 0);
    my $bFSExist = ($nFSSize == 0) ? 'TRUE' : 'FALSE';
    
    if ($bFSExist == 'TRUE')
    {
        ### clear 128KB RAM disk at most
        my $strFSClearEnd = ($nFSMax > (128*1024)) ? &CommonUtil::Dec2Hex($nFSBase+(128*1024)-1) : &CommonUtil::Dec2Hex($nFSBase+$nFSMax-1);
        
        my $strFSBase = &CommonUtil::Dec2Hex($nFSBase);
        my $strFSEnd = &CommonUtil::Dec2Hex($nFSBase+$nFSMax-1);
        
        my $template = <<"__TEMPLATE";
; clear the file system image by default
D.S SD:$strFSBase--$strFSClearEnd %LE %LONG 0x0

; add buttom for file system
menu.addmenu "CLEAR.FILESYSTEM" "D.S SD:$strFSBase--$strFSClearEnd %LE %LONG 0x0"
menu.addmenu "SAVE.FILESYSTEM" "d.save.binary .\\filesystem.bin $strFSBase--$strFSEnd"
menu.addmenu "LOAD.FILESYSTEM" "d.load.binary .\\filesystem.bin $strFSBase--$strFSEnd /LONG /noclear"

__TEMPLATE

        return $template;
    }

    return;
}

#****************************************************************************
# subroutine:  template_set_bkpt_attr_for_sp
#              (this template will be used by MAUI nocode.cmm for smart phone)
# input:       
# output:      template of setting breakpoint attributes
#****************************************************************************
sub template_set_bkpt_attr_for_sp
{
    my $template = <<"__TEMPLATE";
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;------- Break point configuration  ------- 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

&DEBUG_TARGET=0
; 0 = TARGET.
; 1 = SIMULATOR.

IF &DEBUG_TARGET==0
(
    Break.Select Program OnChip
    Break.Select Hll OnChip
    Break.Select Spot OnChip
    Break.Select Read OnChip
    Break.Select Write OnChip
)
IF &DEBUG_TARGET==1
(
    Break.Select Program SOFT
    Break.Select Hll SOFT
    Break.Select Spot SOFT
    Break.Select Read SOFT
    Break.Select Write SOFT
)

__TEMPLATE

    return;
}

#****************************************************************************
# subroutine:  template_mt6573_nocode_preconfiguration
#              (this template will be used by MAUI nocode.cmm for MT6573 only)
# output:      template of MT6573 nocode.cmm to perform the following:
#              set-up ICE connection
#              set default value for JTAG single processor mode
#              set-up environmental variables
#              start ICE connection
#              disable WDT
#              finish BROM and BL execution
#              break AP core
#              enable daisy-chain to control MD
#              initialize TCM
#              initialize PLL
#              initialize EMI
#****************************************************************************
sub template_mt6573_nocode_preconfiguration
{
    my $template = <<"__TEMPLATE";
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; ------- Setup ICE connection for AP-side ------- 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

SYStem.RESet
SYStem.CPU ARM1176JZ
System.Option Cflush on     
SYStem.JtagClock Rtck
System.Option ResBreak off  
System.Option EnReset on


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; ------- Set default value for JTAG for single processor mode ------- 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

; JTAG serial scan HW defaults to non-daisychain mode
; i.e. AP & MD are NOT both connected in the serial scan path
; Only 1 core (AP or MD) is in the JTAG scan path
; Which one is in depends on how the following two locations are set
;    D.S. SD:0x700FA034 %LE %LONG 0x00000001    ; AP MCU
;    D.S. SD:0x700FA038 %LE %LONG 0x00000000    ; MD MCU
; AP JTAG is connected by default    (i.e. *0x700FA034 = 0x1 at reset)
; MD JTAG is disconnected by default (i.e. *0x700FA038 = 0x0 at reset)
System.MultiCore IRPRE 0.
System.MultiCore DRPRE 0.
System.MultiCore IRPOST 0.
System.MultiCore DRPOST 0.


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; ------- Setup environmental variables ------- 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;------- Multicore Debug Setting -------
; Assumes that a dual-window environment is being used
; This is currently started using the 'T32Start' application
; This environment sets up and uses INTERCOM commands
&MULTICORE_DEBUG_ENABLED=0
&MULTICORE_AP_ONLY=0
&MULTICORE_MD_ONLY=0

;------- Daisychain Setting -------
&DAISYCHAINING_ENABLED=1

;------- AP/MD Master Setting ------- 
; AP_MASTER = 1 => AP is Master
; AP_MASTER = 0 => MD is Master
&AP_MASTER=0

;------- CodeVisor/Trace32 Setting ------- 
; Set to 0 for TRACE32 ICE
; Set to 1 for CodeViser ICE
GLOBAL &CODEVISER
&CODEVISER=1


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; ------- Start the ICE connection ------- 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

SYStem.Up
setup.IMASKHLL ON
setup.IMASKASM ON

IF &CODEVISER==1
(
    // TRACE32 does not need these commands
    //
    // Without these commands, if the AP or MD code is running when the script is run, 
    // CodeViser reports that the target is already running and leaves debug mode (reported 
    // when trying to execute 'B::R.S M 0x13' below.  If the AP or MD is NOT running when the script is run,
    // these instructions are not needed
    Wait 2000.ms
    system.mode.attach
    // TRACE32 stops executing the script when it sees a break command and the processor is not running
    break
    SYStem.Up
)


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;------- Disable Watch Dog Timer ------- 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;Disable AP watchdog
D.S SD:0x70025000 %LE %WORD 0x2200
;Disable DSP watchdog
D.S SD:0x70025020 %LE %WORD 0x2200
;Disable MD watchdog
D.S SD:0x70025030 %LE %WORD 0x2200

wait 100.ms


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; ------- Let BootRom and Boot-loader execution finished ------- 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

go
wait 1000.ms


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; ------- Break the AP-core ------- 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

; Break the AP ICE.
BREAK


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; ------- Enable Daisy-Chain to control MD ------- 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;--------------------------------------------------------------------------------------------------------------------------
; Singlecore debug is available with Daisy-chaininig enabled and Daisychaining disabled
; Although the underlying chip-level configuration is different, from a user perspective the environments are the same
;
; For singlecore debug (1 x TRACE32 window), this TRACE32 window can be be used to talk to either the AP MCU or the MD MCU
; For singlecore debug (1 x TRACE32 window), this parameter is used to configure JTAG for AP MCU or MD MCU
;
; For multicore debug (2 x TRACE32 windows), this parameter is forced to be 1
; For multicore debug (2 x TRACE32 windows), this TRACE32 window is always used to communicate with the AP MCU
;--------------------------------------------------------------------------------------------------------------------------
IF &MULTICORE_DEBUG_ENABLED==1
(
    ;Override the previous setting of &AP_MASTER
    ;For multicore debug, this TRACE32 window will always be used to talk to the AP MCU
    &AP_MASTER=1
    ; Daisychaining is required
    &DAISYCHAINING_ENABLED=1

    ; Wait for the MD MCU TRACE32 environment to open and listen to INTERCOM
    INTERCOM.WAIT Localhost:10001

    ;---------------------------------------------------------------------------------------------------------------------------
    ; Configure the amount of control the master window (AP) has over the slave window (MD) when starting, stopping and setpping
    ;---------------------------------------------------------------------------------------------------------------------------

    ; Setup SYNCH commands for AP MCU
    SYNCH.RESet
    SYNCH.Connect Localhost:10001
    SYNCH.MasterGo ON
    SYNCH.MasterBRK ON
    SYNCH.MasterStep ON

    ; Setup SYNCH commands for MD MCU
    INTERCOM.execute Localhost:10001 SYNCH.RESet
    INTERCOM.execute Localhost:10001 SYNCH.Connect Localhost:10000
    INTERCOM.execute Localhost:10001 SYNCH.SlaveGo OFF
    INTERCOM.execute Localhost:10001 SYNCH.SlaveBRK OFF
    INTERCOM.execute Localhost:10001 SYNCH.SlaveStep OFF

    ;------------
    ; Flag check
    ;------------
    ; &MULTICORE_AP_ONLY and &MULTICORE_MD_ONLY must never both be set to 1
    ; The commands below will detect this a generate an error
    IF &MULTICORE_AP_ONLY==1
    (
        IF &MULTICORE_MD_ONLY==1
        (
              INTERCOM.execute Localhost:10001 STOP "ILLEGAL PARAMETER SETTINGS, &MULTICORE_AP_ONLY and &MULTICORE_MD_ONLY CANNOT BOTH BE SET TO 1"
            STOP "ILLEGAL PARAMETER SETTINGS, &MULTICORE_AP_ONLY and &MULTICORE_MD_ONLY CANNOT BOTH BE SET TO 1"
        )
    )
)


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; ------- Initialize ITCM/DTCM ------- 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

&init_tcm=0  ; 0: not init 
                     ; 1: init 
                     
IF &init_tcm==1
(
    PER.S C15:0x29  %LONG 0x0               ; select TCM0
    PER.S C15:0x319 %LONG 0x0               ; set ITCM0 to secure access
    PER.S C15:0x219 %LONG 0x0               ; set DTCM0 to secure access
    PER.S C15:0x119 %LONG 0x50000019        ; set ITCM0
    PER.S C15:0x19  %LONG 0x50100019        ; set DTCM0

    PER.S C15:0x29  %LONG 0x1               ; select TCM1
    PER.S C15:0x319 %LONG 0x0               ; set ITCM1 to secure access
    PER.S C15:0x219 %LONG 0x0               ; set DTCM1 to secure access
    PER.S C15:0x119 %LONG 0x50008019        ; set ITCM1
    PER.S C15:0x19  %LONG 0x50108019        ; set DTCM1
)


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;------- PLL Initialization ------- 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

&PLL_Init=1

IF &PLL_Init==1
(
    ; MD side only need to use WPLL, MPLL, DPLL, EPLL.

    ; Set BOOTROM divider to DIV4 and L3 AXI clock to DIV2
    D.S SD:0x70026040 %LE %LONG 0x00001031 

    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ; Set all PLL to 26MHz crystal clock source.
    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

    ; Set clock source for APMCU, WMA(3G), GSM(2G), MSDC to be 26MHz crystal clock.
    ;DRV_WriteReg(PLL_CON5, *PLL_CON5&0xF000);
    D.S SD:0x7002E114 %LE %WORD 0x0000

    ; Set clock source for CAMERA, FCORE, EMI, MDMCU to be 26MHz crystal clock.
    ;DRV_WriteReg(PLL_CON4, *PLL_CON4&0x00FF);
    D.S SD:0x7002E110 %LE %WORD 0x0000

    ; Set clock source for 3D, FG, SYS(AUD), TV, and USB to be 26MHz crystal clock.
    ;DRV_WriteReg(PLL_CON4, *PLL_CON4&0x00FF);
    D.S SD:0x7002E118 %LE %WORD 0x0000


    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ; Set all PLL is controlled by related PLL_EN instead of reset signal.
    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

    ; Set MCU PLL enable source to be from MPLL_CON0: MOD_MCU_PLL_EN register    
    ;DRV_WriteReg(MPLL_CON1, 0x0100);
    D.S SD:0x7002E144 %LE %WORD 0x0100
    ; Set MD MCU to 520MHz, but do not enable PLL yet.
    ;DRV_WriteReg(MPLL_CON0, 0x0000); 
    D.S SD:0x7002E140 %LE %WORD 0x0000

    ; Set DSP PLL enable source to be from DPLL_CON0: DSP_PLL_EN register    
    ;DRV_WriteReg(DPLL_CON1_REG, 0x0100);
    D.S SD:0x7002E184 %LE %WORD 0x0100
    ; Set DSP to 312MHz, but do not enable PLL yet.
    ;DRV_WriteReg(DPLL_CON0_REG, 0x3400);
    D.S SD:0x7002E180 %LE %WORD 0x3400

    ; Set MSDC (fixed 98.304MHz) and 3G PLL (fixed 491.52MHz) enable source to be from MSDC_CLK_EN and 3G_PLL_EN register.
    ;DRV_WriteReg(WPLL_CON0, 0x0300);
    D.S SD:0x7002E240 %LE %WORD 0x0300

    ; Set USB and 2G PLL enable source to be from USB_CLK_EN and 2G_PLL_EN register.
    ;DRV_WriteReg(GPLL_CON0, 0x0300);
    D.S SD:0x7002E280 %LE %WORD 0x0300

    ; Set EMI PLL enable source to be from EMI_PLL_EN register.
    ;*EPLL_CON1 = 0x00000100;
    D.S SD:0x7002E1C4 %LE %WORD 0x0100
    ; Set EMI (2X) to 390MHz, but do not enable PLL yet.
    ;*EPLL_CON0 = 0x00000000;
    D.S SD:0x7002E1C0 %LE %WORD 0x0000

    ; Set APMCU PLL enable source to be from AMPLL_CON0: APPS_MCU_PLL_EN register.
    ;AMPLL_CON1_REG = 0x0100;
    D.S SD:0x7002E164 %LE %WORD 0x0100
    ; Set APMCU to 650MHz, but do not enable PLL yet.
    ;AMPLL_CON0_REG = 0x0000;
    D.S SD:0x7002E160 %LE %WORD 0x0000

    ; Set CAMERA PLL to 143MHz, but do not enable PLL yet.
    ;CPLL_CON0_REG = 0x0000;
    D.S SD:0x7002E200 %LE %WORD 0x0000

    ; Set 3D PLL to 195MHz, but do not enable PLL yet.
    ;THREED_CON0_REG = 0x0000;
    D.S SD:0x7002E2C0 %LE %WORD 0x0000

    ; TV PLL, do not enable PLL yet.
    ;TV_CON0_REG = 0x0000;
    D.S SD:0x7002E300 %LE %WORD 0x0000

    ; FG PLL, do not enable PLL yet.
    ;FG_CON0_REG = 0x0000;
    D.S SD:0x7002E340 %LE %WORD 0x0000

    ; Set AUX PLL to be Main=104MHz, CLK_104 = 104MHz, CK_48=48MHz, but do not enable PLL yet.
    ;AUX_CON0_REG = 0x0000;
    D.S SD:0x7002E380 %LE %WORD 0x0000


    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ; Initialize PLL.
    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

    ; MD MCU PLL:
    ; 1. Set lock timer to 9uS
    ; 2. Enable synchronous shutdown/transition
    ; 3. Enable reference clock outside of lock -> MT6276 does not enable this.
    ;MPLL_CON0_REG |= 0x006C;
    D.S SD:0x7002E140 %LE %WORD 0x006C
    ; Enable MPLL
    ;MPLL_CON0_REG |= 0x0001;
    D.S SD:0x7002E140 %LE %WORD 0x006D

    ; FCORE PLL:
    ; 1. Set lock timer to 9uS
    ; 2. Enable synchronous shutdown/transition
    ; 3. Enable reference clock outside of lock -> MT6276 does not enable this.
    ;DPLL_CON0_REG |= 0x346C;
    D.S SD:0x7002E180 %LE %WORD 0x346C
    ; Enable DPLL
    ;DPLL_CON0_REG |= 0x0001;
    D.S SD:0x7002E180 %LE %WORD 0x346D

    ; 3G PLL:
    ; 1. Set lock timer to 24uS
    ; 2. Enable synchronous shutdown/transition
    ; 3. Enable reference clock outside of lock -> MT6276 does not enable this.
    ; 4. Disable MSDC_CLK_EN.
    ;WPLL_CON0_REG |= 0x006C;
    D.S SD:0x7002E240 %LE %WORD 0x036C
    ; Enable 3G PLL
    ;WPLL_CON0_REG |= 0x0001;
    D.S SD:0x7002E240 %LE %WORD 0x036D

    ; 2G PLL:
    ; 1. Set lock timer to 10.5uS
    ; 2. Enable synchronous shutdown/transition
    ; 3. Enable reference clock outside of lock -> MT6276 does not enable this.
    ;GPLL_CON0_REG |= 0x006C;
    D.S SD:0x7002E280 %LE %WORD 0x036C
    ; Enable 2GPLL and USB clock.
    ;GPLL_CON0_REG |= 0x0081;
    D.S SD:0x7002E280 %LE %WORD 0x03ED

    ; AP MCU PLL: 
    ; 1. Set lock timer to 9uS
    ; 2. Enable synchronous shutdown/transition
    ; 3. Enable reference clock outside of lock -> MT6276 does not enable this.
    ; AMPLL_CON0_REG |= 0x006C;
    D.S SD:0x7002E160 %LE %WORD 0x006C
    ; Enable AMPLL
    ;AMPLL_CON0_REG |= 0x0001;
    D.S SD:0x7002E160 %LE %WORD 0x006D

    ; CAMERA PLL:
    ; 1. Set lock timer to 12uS
    ; 2. Enable synchronous shutdown/transition
    ; 3. Enable reference clock outside of lock -> MT6276 does not enable this.
    ;CPLL_CON0_REG |= 0x006C;
    D.S SD:0x7002E200 %LE %WORD 0x006C
    ; Enable CPLL
    ;CPLL_CON0_REG |= 0x0001;
    D.S SD:0x7002E200 %LE %WORD 0x006D

    ; 3D PLL
    ; 1. Set lock timer to 12uS
    ; 2. Enable synchronous shutdown/transition
    ; 3. Enable reference clock outside of lock -> MT6276 does not enable this.
    ;THREED_CON0_REG |= 0x006C;
    D.S SD:0x7002E2C0 %LE %WORD 0x006C
    ; Enable THREED PLL
    ; THREED_CON0_REG |= 0x0001;
    D.S SD:0x7002E2C0 %LE %WORD 0x006D

    ; TV PLL
    ; 1. Set lock timer to 9uS
    ; 2. Enable synchronous shutdown/transition
    ; 3. Enable reference clock outside of lock -> MT6276 does not enable this.
    ;TV_CON0_REG |= 0x006C;
    D.S SD:0x7002E300 %LE %WORD 0x006C
    ; Enable TV PLL
    ; TV_CON0_REG |= 0x0001;
    D.S SD:0x7002E300 %LE %WORD 0x006D

    ; FG PLL
    ; 1. Set lock timer to 4mS
    ; 2. Enable synchronous shutdown/transition
    ; 3. Enable reference clock outside of lock -> MT6276 does not enable this.
    ; 4. Select FG PLL o/p (not driven by AUX_PLL or SYS_CLK)
    ;FG_CON0_REG |= 0x0260;
    D.S SD:0x7002E340 %LE %WORD 0x0260
    ; Enable FG PLL
    ;FG_CON0_REG |= 0x0001;
    D.S SD:0x7002E340 %LE %WORD 0x0261

    ; AUX PLL
    ; 1. Set lock timer to 14mS
    ; 2. Enable synchronous shutdown/transition
    ; 3. Enable reference clock outside of lock -> MT6276 does not enable this.
    ; Main clock = 104MHz, others clocks generated are 104MHz (alt BUS), 48MHz (alt USB) and 26MHz (alt AUDIOCLK/PMUCLK/SYSCLK)
    ;AUX_CON0_REG |= 0x036C;
    D.S SD:0x7002E380 %LE %WORD 0x036C
    ;AUX_CON0_REG |= 0x0001;
    D.S SD:0x7002E380 %LE %WORD 0x036D


    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ; Select EMI frequency and enable EMI PLL.
    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

    ; Select EMI frequency.
    ; EMI defaults to 403.0MHz/2 = 201.5MHz
    ; EPLL_CON0_REG |= (0x006C | EMI_201_5_MHz);        
    ;D.S SD:0x7002E1C0 %LE %WORD 0x706C
    ; EMI defaults to 390.0MHz/2 = 195.0MHz   
    ; EPLL_CON0_REG |= (0x006C | EMI_195_0_MHz);      
    D.S SD:0x7002E1C0 %LE %WORD 0x6F6C
    ; EMI defaults to 331.5MHz/2 = 165.75MHz
    ; EPLL_CON0_REG |= (0x006C | EMI_165_75_MHZ);    
    ;D.S SD:0x7002E1C0 %LE %WORD 0x006C
    ; EMI defaults to 305.5MHz/2 = 152.75MHz
    ; EPLL_CON0_REG |= (0x006C | EMI_152_75_MHZ);     
    ;D.S SD:0x7002E1C0 %LE %WORD 0x656C
    ; EMI defaults to 203.7MHz/2 = 101.85MHz
    ; EPLL_CON0_REG |= (0x006C | EMI_101_85_MHZ);     
    ;D.S SD:0x7002E1C0 %LE %WORD 0x536C
    ; EMI defaults to  26.0MHz/2 = 13.0MHz 
    ; EPLL_CON0_REG |= (0x006C | EMI_13_MHZ);         
    ;D.S SD:0x7002E1C0 %LE %WORD 0x026C
    ;  [!!! NOTE, since it is not read-modify-write, so we must change this when changing the clock rate] Enable EPLL
    ;EPLL_CON0_REG |= 0x0001;
    D.S SD:0x7002E1C0 %LE %WORD 0x6F6D

    ; wait > 20us for PLL lock
    wait 1.ms


    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ; Switch PLL back to HW control.
    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

    ; MPLL enable source = system power-down/reset control (not MOD_MCU_PLL_EN bit in MPLL_CON0_REG)
    ; MPLL_CON1_REG &= 0xFEFF;
    D.S SD:0x7002E144 %LE %WORD 0x0000
    ; DPLL enable source = system power-down/reset control (not DSP_PLL_EN bit in DPLL_CON0_REG)
    ; DPLL_CON1_REG &= 0xFEFF;    
    D.S SD:0x7002E184 %LE %WORD 0x0000
    ; Enable source of gating 98.304 MSDC clock (from 3G PLL) = system MSDC clock enable control (not MSDC_CLK_EN bit in DPLL_CON0_REG).
    ; Enable source of 3G PLL = system power-down/reset control (not THREEG_PLL_EN bit in WPLL_CON0_REG)
    ;WPLL_CON0_REG &= 0xFCFF;    
    D.S SD:0x7002E240 %LE %WORD 0x006D
    ; Enable source of gating 48.304 USB clock (from 2G PLL) = system USB clock enable control (not USB_CLK_EN bit in GPLL_CON0_REG)
    ; Enable source of 2G PLL = system power-down/reset control (not TWOG_PLL_EN bit in GPLL_CON0_REG)
    ;GPLL_CON0_REG &= 0xFCFF;     
    D.S SD:0x7002E280 %LE %WORD 0x00ED
    ; EPLL enable source = system power-down/reset control (not EMI_PLL_EN bit in EPLL_CON0_REG)
    ; EPLL_CON1_REG &= 0xFEFF;     
    D.S SD:0x7002E1C4 %LE %WORD 0x0000
    ; AMPLL enable source = system power-down/reset control (not APPS_MCU_PLL_EN bit in AMPLL_CON0_REG)
    ; AMPLL_CON1_REG &= 0xFEFF;    
    D.S SD:0x7002E164 %LE %WORD 0x0000


    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ; Select to target PLL source.
    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

    ; Select PLL o/p as clock source for CAMERA, FCORE, EMI & MDMCU
    ; PLL_CON4_REG = 0x1111;    
    ; D.S SD:0x7002E110 %LE %WORD 0x1101      ; Do not touch EMI.
    D.S SD:0x7002E110 %LE %WORD 0x1111        ; MT6276 use this.

    ; Select PLL o/p as clock source for APMCU, 3G, 2G & MSDC
    ; PLL_CON5_REG = 0x1111;  
    ; APMCU PLL is divided by APMPLL_DIGDIV1 (which defaults to /1)
    D.S SD:0x7002E114 %LE %WORD 0x1111

    ; Select PLL o/p as clock source for THREED, FG, AUX, TV & USB
    ; PLL_CON6_REG = 0x0155;  
    ;D.S SD:0x7002E118 %LE %WORD 0x0155
    D.S SD:0x7002E118 %LE %WORD 0x0145
    ; Replace SYS_CLK (26MHz) with the 26MHz clock from the AUX_PLL
    ; PLL_CON2_REG |= RG_OVRD_SYS_CLK;  
    ;D.S SD:0x7002E108 %LE %WORD 0x2300     
    ; Enable Audio clock.
    ;D.S SD:0x7002E108 %LE %WORD 0x2320
    D.S SD:0x7002E108 %LE %WORD 0x0320               
)

; Enable bus clock gating enable control register
; D.S SD:0x610D0558 %LE %WORD 0x01FF   -> Do MT6573 has this register?



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;------- EMI Initialization ------- 
; For DDR32-4Gb (512MB) (ELPIDA EHD013151MA-50-F) x16 4G Nand + x32 4G LP-DDR1 200MHz.
; DRAM Die ECK220ACACN
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

&EMI_Init=1
&EMI_FREQUENCY=200
&RD_DEL_SEL=5
&EMI_PDN_EN=0
&EMI_DUMMY_RD_FIXCLK_EN=1

IF &EMI_Init==1
(
    ; Program EMI_CONI - DRAM mode (and extended mode) register values
    D.S SD:0x70000040 %LE %LONG 0x00324000 

    ; Program Output Driving
    ; EMI_DRVA 
    D.S SD:0x700002A8 %LE %LONG 0x88888888
    ; EMI_DRVB 
    D.S SD:0x700002B0 %LE %LONG 0x00880000 

    ; Program AC Timing Parameters for Elpida EHD013151MA device
    IF &EMI_FREQUENCY==100 
    (
        ; Program EMI_CONJ
        D.S SD:0x70000048 %LE %LONG 0x00050002

        ; Program EMI_CONK
        D.S SD:0x70000050 %LE %LONG 0x000C0000

        ; Program EMI_CONL
        D.S SD:0x70000058 %LE %LONG 0x00011005
    )
    IF &EMI_FREQUENCY==152
    (
        ; Program EMI_CONJ
        D.S SD:0x70000048 %LE %LONG 0x000B1147

        ; Program EMI_CONK
        D.S SD:0x70000050 %LE %LONG 0x000C1000

        ; Program EMI_CONL
        D.S SD:0x70000058 %LE %LONG 0x00013005
    )
    IF &EMI_FREQUENCY==166
    (
        ; Program EMI_CONJ
        D.S SD:0x70000048 %LE %LONG 0x000D1249

        ; Program EMI_CONK
        D.S SD:0x70000050 %LE %LONG 0x000C1000

        ; Program EMI_CONL
        D.S SD:0x70000058 %LE %LONG 0x00013005
    )
    IF &EMI_FREQUENCY==200
    (
        ; Program EMI_CONJ
        D.S SD:0x70000048 %LE %LONG 0x4011248C

        ; Program EMI_CONK
        ; What is the fixed clock rate of MT6573?
        D.S SD:0x70000050 %LE %LONG 0x000C2000

        ; Program EMI_CONL
        ; RD_DEL_SEL Selector
        IF &RD_DEL_SEL==4
        (
            D.S SD:0x70000058 %LE %LONG 0x00415004
        )
        IF &RD_DEL_SEL==5
        (
            D.S SD:0x70000058 %LE %LONG 0x00415005
        )
        IF &RD_DEL_SEL==6
        (
            D.S SD:0x70000058 %LE %LONG 0x00415006
        )
        IF &RD_DEL_SEL==7
        (
            D.S SD:0x70000058 %LE %LONG 0x00415007
        )
    )

    ; Program EMI_IOCL - Setup swap function for LPDDR EVB
    D.S SD:0x700002B8 %LE %LONG 0x03000000
    
    ; Program EMI_GENA - Enable clocks, pause-start signal, external boot
    D.S SD:0x70000070 %LE %LONG 0x0000030A

    ; Program EMI_GEND (enable DDR CS0 and CS1)
    D.S SD:0x70000088 %LE %LONG 0x000F0000

    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ; Initialization of DDR devices (steps followed per DDR device datasheet)
    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    
    ; Single Pre-charge All
    D.S SD:0x70000068 %LE %LONG 0x108B0001
    wait 1.ms
    ; Single Auto-refresh 1 Enable
    D.S SD:0x70000068 %LE %LONG 0x088B0001
    wait 1.ms
    ; Single Auto-refresh 2 Enable
    D.S SD:0x70000068 %LE %LONG 0x048B0001
    wait 1.ms
    ; Single Load Mode Register
    D.S SD:0x70000068 %LE %LONG 0x028B0001
    wait 1.ms
    ; Single Extended Mode Register Enable
    D.S SD:0x70000068 %LE %LONG 0x018B0001
    wait 1.ms

    ; Update EMI_CONN to enable PDN_EN, CAL_EN (data auto-tracking disabled), AP, and Concurrent AP
    IF &EMI_PDN_EN==0
    (
        D.S SD:0x70000068 %LE %LONG 0x008B3107
    )
    IF &EMI_PDN_EN==1
    (
        D.S SD:0x70000068 %LE %LONG 0x008B3117
    )
   
    wait 1.ms

    ; Enable Dummy Read
    IF &EMI_DUMMY_RD_FIXCLK_EN==0
    (
        D.S SD:0x70000078 %LE %LONG 0x00000003
    )
    IF &EMI_DUMMY_RD_FIXCLK_EN==1
    (
        D.S SD:0x70000078 %LE %LONG 0x8000F003
    )
    
    ; Enable HW DQS auto-tracking
    ; Set delay function for EMI_DQSA (CS0) and EMI_DQSB (CS1) auto-tracking 
    D.S SD:0x70000300 %LE %LONG 0x28282828
    D.S SD:0x70000308 %LE %LONG 0x28282828
    ; Set EMI_DQSE to enable auto-tracking function for inputs DQS[3:0] of CS0 and CS1
    D.S SD:0x70000320 %LE %LONG 0x000000FF

    ; Enable EMI_PPCT performance and power control
    D.S SD:0x70000090 %LE %LONG 0xFFFF0000

    ; EMI_SLCT - Enable HI Prio for MM1 and MM2 and R/W command favor for all masters
    D.S SD:0x70000150 %LE %LONG 0x0000007F

    ; EMI_ABCT - Enable 1/32 freq for HWDCM mode (slow clock =6.25MHz) and enable arbitration controls (lower_rw, higher_ph, lower_rc)
    D.S SD:0x70000158 %LE %LONG 0x00070020

    wait 1.ms 
)

wait 100.ms


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; ------- Enable Daisy-Chain to control MD ------- 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

; Switching to daisychain mode will cause the TRACE32 tool to lose connectivity with the core
; The TRACE32 will beep (annoying) unless you mask it
SETUP.SOUND OFF

IF &DAISYCHAINING_ENABLED!=0
(
    ;---- Serial JTAG specific AP ARM11 ----
    ; JTAG serial scan HW defaults to non-daisychain mode
    ; i.e. AP & MD are NOT both connected in the serial scan path
    ; AP JTAG is connected by default    (i.e. *0x700FA034 = 0x1 at reset)
    ; MD JTAG is disconnected by default (i.e. *0x700FA038 = 0x0 at reset)
    ;

    ;------------------------------------
    ; Enable the debug system (from the AP MCU)
    D.S. SD:0x70026320 %LE %LONG 0x00000000
    ;------------------------------------

    ;------------------------------------
    ; Unlock the address range 0x700FA0xx (from the AP MCU)
    D.S. SD:0x700FAFB0 %LE %LONG 0xC5ACCE55
    ;------------------------------------

    ;------- Write MD MCU instruction 'Branch 0' to address 0x00000000
    D.A SD:0x00000000 B 0x0

    IF &AP_MASTER==0
    (
        ; Release MD MCU from reset
          ; Only the MD MCU is being run
          ; The MD MCU must be out of reset in order for TRACE32 to be able to communicate with it via JTAG
          ; On releasing the MD MCU from reset, it will start executing the 'BR 0x0' command at address 0x0
        D.S SD:0x60140010 %LE %LONG 0x00011111
    )

    IF &MULTICORE_DEBUG_ENABLED==1
    (
        ;Release MD MCU from reset
        ; Both the AP MCU & the MD MCU are being run
          ; The MD MCU must be out of reset in order for TRACE32 to be able to communicate with it via JTAG
          ; On releasing the MD MCU from reset, it will start executing the 'BR 0x0' command at address 0x0
        D.S SD:0x60140010 %LE %LONG 0x00011111
    )

    ; Needed by Codeviser
    system.option TURBO OFF

    ;------------------------------------
    ; Enable H/W Daisy Chaining
    ; Causes an 'emulation debug port fail' error on TRACE32 tool
    ; As a result, the TRACE32 tool loses it's connection with the AP MCU core
    ; We must re-attach to re-establish connectivity with the selected core
    D.S. SD:0x700FA034 %LE %LONG 0x00000001    ; AP MCU
    D.S. SD:0x700FA038 %LE %LONG 0x00000001    ; MD MCU
    ;------------------------------------

    ;system.option TURBO ON

    ; Needed by Codeviser
    system.down

    IF &AP_MASTER==1
    (
        ; Connect to AP with daisychain mode enabled (both cores in the JTAG scan path)
        System.MultiCore IRPRE 5.
        System.MultiCore DRPRE 1.
        System.MultiCore IRPOST 0.
        System.MultiCore DRPOST 0.
        ; Core 1 in Chip 1
        System.MultiCore CORE 1 1
    )

    IF &AP_MASTER==0
    (
        ; Connect to MD with daisychain mode enabled (both cores in the JTAG scan path)
        System.MultiCore IRPRE 0.
        System.MultiCore DRPRE 0.
        System.MultiCore IRPOST 5.
        System.MultiCore DRPOST 1.
        ; Core 2 in Chip 1
        System.MultiCore CORE 2 1
    )

    SYStem.mode.attach

    // TRACE32 does not need this command
    // For the MD, without this command, when CodeViser trys to set the PC to 0x0 it
    // reports that the MD is already running and the script stops
    // Not needed when controlling the AP but does no harm
    IF &CODEVISER==1
    (
        // TRACE32 stops executing the script when it sees a break command and the processor is not running
        break
    )

    IF &AP_MASTER==0
    (
        ;------------------------------------
        ; Enable the debug system (from the MD MCU)
        ;;;;;;;;D.S. SD:0x70026320 %LE %LONG 0x00000000
        ;------------------------------------

        ;------------------------------------
        ; Unlock the address range 0x700FA0xx (from the MD MCU)
        ;;;;;;;;D.S. SD:0x700FAFB0 %LE %LONG 0xC5ACCE55
        ;------------------------------------

        ; 0x700FA034 should be 1 (APMCU switched into the JTAG path)
    ; 0x700FA038 should be 1 (MDMCU switched into the JTAG path)
    )
)
ELSE
(
    IF &PLATFORM_TYPE>0
    (
        ;------------------------------------
        ; Enable the debug system (from the APMCU)
        D.S. SD:0x70026320 %LE %LONG 0x00000000
        ;------------------------------------

        ;------------------------------------
        ; Unlock the address range 0x700FA0xx (from the APMCU)
        D.S. SD:0x700FAFB0 %LE %LONG 0xC5ACCE55
        ;------------------------------------

        ; Platform is not FPGA (so it must be E1, E2 etc etc
        IF &AP_MASTER==1
        (
            ; Connect to AP with daisychain mode disabled (only AP MCU core in the JTAG scan path)
            ; These are actually the default values so there is no net change here
            ; The JTAG path is therefore NOT disturbed
            D.S. SD:0x700FA034 %LE %LONG 0x00000001    ; AP MCU
            D.S. SD:0x700FA038 %LE %LONG 0x00000000    ; MD MCU
        )

        IF &AP_MASTER==0
        (
            ;------- Write MD MCU instruction 'Branch 0' to address 0x00000000
            D.A SD:0x00000000 B 0x0

            ;Release MD MCU from reset
            ;The MD MCU must be out of reset in order for TRACE32 to be able to communicate with it via JTAG
            ; On releasing the MD MCU from reset, it will start executing the 'BR 0x0' command at address 0x0
            D.S SD:0x60140010 %LE %LONG 0x00011111

            ; Connect to the MDMCU with daisychain mode disabled (only MD MCU core in the JTAG scan path)

            ; To do this we must follow the sequence below
              ; a) Using the APMCU, bring the MD MCU into the JTAG path with the APMCU, thus enabling daisychaining
            ;    This causes an 'emulation debug port fail' error on TRACE32 tool
            ;    As a result, the TRACE32 tool loses it's connection with the APMCU core
            ; b) Select the MDMCU via the PRE/POST parameters
              ; c) 'Re-attach' to re-establish connectivity with the MDMCU core
              ; d) Now we can use the MDMCU to switch the APMCU out of the JTAG path
            ;    This causes an 'emulation debug port fail' error on TRACE32 tool
            ;    As a result, the TRACE32 tool loses it's connection with the MDMCU core
            ; e) Now that there is only 1 core in the JTAG path (the MDMCU), return PRE/POST parameters to their default values of all 0s
              ; f) 'Re-attach' to re-establish connectivity with the MDMCU core
            ; Now we are connected to the MD MCU only

            ; Needed by Codeviser
            system.option TURBO OFF

            ;a)
            D.S. SD:0x700FA038 %LE %LONG 0x00000001    ; MD MCU

            ; Needed by Codeviser
            system.down

            ;b)
            ; Connect to MD with daisychain mode enabled (both cores in the JTAG scan path)
            System.MultiCore IRPRE 0.
            System.MultiCore DRPRE 0.
            System.MultiCore IRPOST 5.
            System.MultiCore DRPOST 1.

            ;c)
            SYStem.mode.attach
            // TRACE32 does not need this command
            // For the MD, without this command, when CodeViser trys to set the PC to 0x0 it
            // reports that the MD is already running and the script stops
            // Not needed when controlling the AP but does no harm
            IF &CODEVISER==1
            (
                // TRACE32 stops executing the script when it sees a break command and the processor is not running
                break
            )

            ;d)
            D.S. SD:0x700FA034 %LE %LONG 0x00000000    ; AP MCU

            ; Needed by Codeviser
            system.down

            ;e)
            System.MultiCore IRPRE 0.
            System.MultiCore DRPRE 0.
            System.MultiCore IRPOST 0.
            System.MultiCore DRPOST 0.

            ;f)
            SYStem.mode.attach

            // TRACE32 does not need this command
            // For the MD, without this command, when CodeViser trys to set the PC to 0x0 it
            // reports that the MD is already running and the script stops
            // Not needed when controlling the AP but does no harm
            IF &CODEVISER==1
            (
                // TRACE32 stops executing the script when it sees a break command and the processor is not running
                break
            )

            ;------------------------------------
            ; Enable the debug system from the MD MCU
            ;D.S. SD:0x70026320 %LE %LONG 0x00000000
            ;------------------------------------

            ;------------------------------------
            ; Unlock the address range 0x700FA0xx from the MD MCU
            ;D.S. SD:0x700FAFB0 %LE %LONG 0xC5ACCE55
            ;------------------------------------

            ; 0x700FA034 should be 0 (APMCU switched out of the JTAG path)
        ; 0x700FA038 should be 1 (MDMCU switched into the JTAG path)
        )
    )
)

; Re-enable TRACE32 sounds
SETUP.SOUND ERROR

;GOTO END

IF &MULTICORE_DEBUG_ENABLED==1
(
    INTERCOM.execute Localhost:10001 DO MD_DUAL_JTAG_MT6573.cmm
)

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  template_mt6573_nocode_postconfiguration
#              (this template will be used by MAUI nocode.cmm for MT6573 only)
# output:      template of MT6573 nocode.cmm to perform the following:
#              add button for Meta
#              configure Trace/Codevisor
#              set PC to 0x0
#****************************************************************************
sub template_mt6573_nocode_postconfiguration
{
    my $template = <<"__TEMPLATE";
; CodeVisor might need to set Config->Source Path if c-level mapping is not there.

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;------- Add buttom for META ------- 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
menu.addmenu "NORMAL.MODE" "D.S. SD:0x70026160 %LE %WORD 0x0000"
menu.addmenu "META.MODE" "D.S. SD:0x70026160 %LE %WORD 0x0001"


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;------- Trace32/CodeVisor configuration  ------- 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

IF &MULTICORE_DEBUG_ENABLED==1
(
    GLOBAL &mdmcu_load_done
    &mdmcu_load_done=0

    ; Wait for the MD MCU TRACE32 environment to open and listen to INTERCOM
    INTERCOM.WAIT Localhost:10001

    IF &CODEVISER==0
    (
        // For CodeViser, the EVAL() function does not appear to work and returns something that makes CodeViser evaluate the WHILE as (WHILE (==0)
          // This is currently being debugged by JnDTech (7/19/10)
          // In the CodeViser multi-core environment, the slave (MD) window is open before we start
          // CodeViser executes the MD ELF load in the slave window immediately and fast.  There is no delay.
          // Therefore, the ELF load is guranteed to have been completed already at this point. So, no need to check for completion.
          // Things are slower in the TRACE32 environment because it appears to take a longer time for 't32start' to open the slave (MD) window in the first place
          // Therefore a check is necessary.
          //
        WHILE (&mdmcu_load_done==0)
        (
            ; Check to make sure that the MD MCU TRACE32 environment has finished loading the MD symbols
            INTERCOM.evaluate Localhost:10001 Register(R0)
            &mdmcu_load_done=EVAL()
            PRINT &mdmcu_load_done
        )
    )
)


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;------- Scatter layout configuration  ------- 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

R.S PC 0x00000000 

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  template_mt6575_nocode_preconfiguration
#              (this template will be used by MAUI nocode.cmm for MT6575 only)
# output:      template of MT6575 nocode.cmm to perform the following:
#              set-up ICE connection
#              start ICE connection
#              disable WDT
#              finish BROM and BL execution
#              initialize TCM
#              initialize PLL
#              initialize EMI
#****************************************************************************
sub template_mt6575_nocode_preconfiguration
{
    my $template = <<"__TEMPLATE";
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; ------- Setup ICE connection ------- 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

; JTAG is switched to legacy mode (but not CoreSight/DAP mode) by TinyBL or Dummy AP
; Note: MT6575 does not support daisy-chain mode JTAG

;RESET
;SYStem.RESet

;SYSTEM.OPTION ENRESET OFF
SYSTEM.OPTION ENRESET ON    ;reset system
SYSTEM.OPTION TRST OFF
SYSTEM.OPTION Cflush on     ;flush the cache to avoid data consistency
SYSTEM.OPTION ResBreak off  ;Don't hold the ARM11 core after reset
SYSTEM.OPTION WaitReset ON
SYSTEM.JtagClock Rtck
SYSTEM.CPU ARM1176JZ

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; ------- Start the ICE connection ------- 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

SYStem.Up
setup.IMASKHLL ON
setup.IMASKASM ON


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;------- Disable Watch Dog Timer ------- 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;Disable AP watchdog
;D.S SD:0x70025000 %LE %WORD 0x2200
;Disable DSP watchdog
;D.S SD:0x70025020 %LE %WORD 0x2200
;Disable MD watchdog
;D.S SD:0x70025030 %LE %WORD 0x2200

;wait 100.ms


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; ------- Let BootRom and Boot-loader execution finished ------- 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;go
;wait 1000.ms


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; ------- Initialize ITCM/DTCM ------- 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

&init_tcm=0  ; 0: not init 
             ; 1: init 
                     
IF &init_tcm==1
(
    PER.S C15:0x29  %LONG 0x0               ; select TCM0
    PER.S C15:0x319 %LONG 0x0               ; set ITCM0 to secure access
    PER.S C15:0x219 %LONG 0x0               ; set DTCM0 to secure access
    PER.S C15:0x119 %LONG 0x50000019        ; set ITCM0
    PER.S C15:0x19  %LONG 0x50100019        ; set DTCM0

    PER.S C15:0x29  %LONG 0x1               ; select TCM1
    PER.S C15:0x319 %LONG 0x0               ; set ITCM1 to secure access
    PER.S C15:0x219 %LONG 0x0               ; set DTCM1 to secure access
    PER.S C15:0x119 %LONG 0x50008019        ; set ITCM1
    PER.S C15:0x19  %LONG 0x50108019        ; set DTCM1
)


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;------- PLL Initialization ------- 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

&PLL_Init=1

IF &PLL_Init==1
(

    ;*MAINPLL_CON0 = 0x2560; // MAINPLL 988Mhz
    ;*MAINPLL_CON0 = 0x1E60; // MAINPLL 806Mhz
    ;*MAINPLL_CON0 = 0x1D60; // MAINPLL 780Mhz
    D.S SD:0xC0007120 %LE %WORD 0x2560

    ;gpt4_busy_wait_us(120); // wait 120us (min delay is 30us)
    wait 1.ms

    ;*IPLL_CON0 = 0x2B40;    // ISPLL 143MHz
    D.S SD:0xC0007140 %LE %WORD 0x2B40

    ;gpt4_busy_wait_us(80);  // wait 80 (min delay is 20us)
    wait 1.ms
    
    ;*UPLL_CON0 = 0x1710;    // USBPLL 624MHz (for USB 2.0 and 1.0 Phy)
    D.S SD:0xC0007140 %LE %WORD 0x1710

    ;gpt4_busy_wait_us(80);  // wait 80us (min delay is 20us)
    wait 1.ms
        
    ;*UPLL_CON0 = 0x1712;    // Set USBPLL to 48Mhz output enable
    D.S SD:0xC0007160 %LE %WORD 0x1712
    
    ;*MDPLL_CON0 = 0x1310;   // MDPLL 1024MHz
    D.S SD:0xC0007180 %LE %WORD 0x1310

    ;gpt4_busy_wait_us(80);  // wait 80us (min delay is 20us)
    wait 1.ms
    
    ;*MDPLL_CON0 = 0x1312;   // Set MDPLL to 297.14Mhz output enable
    D.S SD:0xC0007180 %LE %WORD 0x1312
    
    ;*WPLL_CON0 = 0x403B;    // 3GPLL 197Mhz, 492Mhz, 61Mhz enable
    D.S SD:0xC00071C0 %LE %WORD 0x403B

    ;gpt4_busy_wait_us(120); // wait 120us (min delay is 30us)
    wait 1.ms
    
    ;*WPLL_CON0 = 0x403F;    // 3GPLL 197Mhz, 281Mhz, 492Mhz, 61Mhz enable
    D.S SD:0xC00071C0 %LE %WORD 0x403F
    
    ;/* do not need to turn on AUDPLL */
    ;//*AUDPLL_CON0 = 0x5B01;  // AUDPLL 208.0113Mhz
    ;D.S SD:0xC00071E0 %LE %WORD 0x5B01

    ;//gpt4_busy_wait_ms(40);  // wait 120us (min delay is 10ms)
    wait 1.ms
    
    ;*PLL_CON1 = 0x4113;     // Reference clock is from ANA 26Mhz (Clock to MEMPLL enable)
    D.S SD:0xC0007044 %LE %WORD 0x4113
    
    ;*MEMPLL_CON0 = 0x0900;  // 780Mhz
    D.S SD:0xC0007200 %LE %WORD 0x0900
    
    ;*MEMPLL_CON1 = 0x0026;  // MEMPLL = 780Mhz/4 = 195Mhz
    D.S SD:0xC0007204 %LE %WORD 0x0026

    ;gpt4_busy_wait_us(80);  // wait 80us (min delay is 20us)
    wait 1.ms
    
    ;*TOP_DCMDBC = *TOP_DCMDBC | 0x100;  // Set clock divider and turn on enable generator
    ; default value of *TOP_DCMDBC = 0x0000
    D.S SD:0xC0001014 %LE %WORD 0x0100

    ;*TOP_CKDIV0 = *TOP_CKDIV0 | 0x10;   // BUS clock will divide by 5 (10) but ARMPLL will divide by 1 (000)
    ; default value of TOP_CKDIV = 0x0000;
    D.S SD:0xC0001004 %LE %WORD 0x0010

    ;*TOP_CKMUXSEL = 0x1;                // Mux3 From Mux0, Mux1 using CLKSQ, Mux0 using MAINPLL
    D.S SD:0xC0001000 %LE %WORD 0x0001
           
)

wait 1.ms

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;------- EMI Initialization ------- 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

&EMI_Init=1

IF &EMI_Init==1
(
    ;wait 200.us
    wait 1.ms

    D.S SD:0xC00040D4 %LE %LONG 0x00000008          //jitter calibration default value

    ;wait 200.us
    wait 1.ms
    
    D.S SD:0xC00040B8 %LE %LONG 0xCC00CC00          //Tx IO driving
    D.S SD:0xC00040BC %LE %LONG 0xCC00CC00          //Tx IO driving
    D.S SD:0xC0003000 %LE %LONG 0x00022022  ; 1 channel, dual rank, row 14b, bank 2b, column 10b, x32, total 512MB
    D.S SD:0xC0004000 %LE %LONG 0x22824154
    D.S SD:0xC0004048 %LE %LONG 0x0000110D;
    D.S SD:0xC00040D8 %LE %LONG 0x40500900;
    D.S SD:0xC000408C %LE %LONG 0x00000001;
    D.S SD:0xC0004090 %LE %LONG 0x80000000;
    D.S SD:0xC0004094 %LE %LONG 0xC0404040;
    D.S SD:0xC00040DC %LE %LONG 0x83002002;
    D.S SD:0xC00040E0 %LE %LONG 0x00002002;
    D.S SD:0xC00040F0 %LE %LONG 0x00000000;
    D.S SD:0xC00040F4 %LE %LONG 0x10000000; //PHYSYNM
    D.S SD:0xC0004168 %LE %LONG 0x00000010;
    D.S SD:0xC00040D8 %LE %LONG 0x40700900;
    D.S SD:0xC0004004 %LE %LONG 0xF0040560;
    D.S SD:0xC000407C %LE %LONG 0x8283405C; //DLE
    D.S SD:0xC0004028 %LE %LONG 0xF1200F01;
    D.S SD:0xC00041E0 %LE %LONG 0x64000000;
    D.S SD:0xC0004158 %LE %LONG 0x00000000;
    D.S SD:0xC00040e4 %LE %LONG 0x00000000;
    D.S SD:0xC00041e4 %LE %LONG 0x00000010;    //NOP enable
    D.S SD:0xC00041e4 %LE %LONG 0x00000000;    //disable
    D.S SD:0xC00041e4 %LE %LONG 0x00000004;    //PREA enable
    D.S SD:0xC00041e4 %LE %LONG 0x00000000;    //disable
    D.S SD:0xC00041e4 %LE %LONG 0x00000008;    //1st REF enable
    D.S SD:0xC00041e4 %LE %LONG 0x00000000;    //disable
    D.S SD:0xC00041e4 %LE %LONG 0x00000008;    //2nd REF enable
    D.S SD:0xC00041e4 %LE %LONG 0x00000000;    //disable
    D.S SD:0xC0004080 %LE %LONG 0x00000000;    //Select Mode Register
    D.S SD:0xC0004088 %LE %LONG 0x00000032;    //BL=4,CAS Latency=3
    D.S SD:0xC00041e4 %LE %LONG 0x00000001;    //MRS write enable
    D.S SD:0xC00041e4 %LE %LONG 0x00000000;    //disable
    D.S SD:0xC0004080 %LE %LONG 0x00800000;    //Select Extended Mode Register
    D.S SD:0xC0004088 %LE %LONG 0x00000080;    //Extended Mode Register uses default values
    D.S SD:0xC00041e4 %LE %LONG 0x00000001;    //MRS write enable
    D.S SD:0xC00041e4 %LE %LONG 0x00001100;    //disable
    D.S SD:0xC000400C %LE %LONG 0x00000000;
    D.S SD:0xC0004044 %LE %LONG 0x9F060401;
    D.S SD:0xC0004008 %LE %LONG 0x00403330;
    D.S SD:0xC0004010 %LE %LONG 0x00000000;
    D.S SD:0xC00040F8 %LE %LONG 0xEDCB000F;
    D.S SD:0xC00040FC %LE %LONG 0x00000000;     //async mode
    D.S SD:0xC0004018 %LE %LONG 0x60606060;
    
    D.S SD:0xC0003060 %LE %LONG 0x00000400; //ungate dram
    
    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ;;;;;;;; EMI BW limiter & arbiter ;;;;;;;;
    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

    ; Overhead
    D.S SD:0xC0003000 %LE %LONG 0x00022022; // EMI_CONA
    D.S SD:0xC0003008 %LE %LONG 0x090B0B10; // EMI_CONB
    D.S SD:0xC0003010 %LE %LONG 0x09090909; // EMI_CONC
    D.S SD:0xC0003018 %LE %LONG 0x0B0E1013; // EMI_COND
    D.S SD:0xC0003020 %LE %LONG 0x0909090A; // EMI_CONE

    ;D.S SD:0xC00030F8 %LE %LONG 0x0000FEF0; // EMI_TESTD

    ; BW Limiter
    ; 
    D.S SD:0xC0003100 %LE %LONG 0x8008590A; // EMI ARBA, 
    D.S SD:0xC0003108 %LE %LONG 0x00000000; // EMI ARBB
    D.S SD:0xC0003110 %LE %LONG 0x80801005; // EMI ARBC
    D.S SD:0xC0003118 %LE %LONG 0x40401010; // EMI ARBD, 16/64 = 25.00% (MDMCU), hard
    D.S SD:0xC0003120 %LE %LONG 0x40401004; // EMI ARBE,  4/64 =  6.25% (Fcore), hard
    D.S SD:0xC0003128 %LE %LONG 0x40401003; // EMI ARBF,  3/64 =  4.69% (2G/3G), hard
    D.S SD:0xC0003130 %LE %LONG 0x40401011; // EMI ARBG

    ; Priority
    D.S SD:0xC0003140 %LE %LONG 0x00112480; // EMI ARBI
    ;D.S SD:0xC0003148 %LE %LONG 0x00684848; // EMI ARBJ (default)
    ;D.S SD:0xC0003150 %LE %LONG 0x00000C7C; // EMI ARBK (default)

    ; change DeviceAPC MD2G access right to Fcore domain
    D.S SD:0x81160090 %LE %LONG 0x00000000;
    D.S SD:0x811600A0 %LE %LONG 0x00000001;

    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

    ; turn-off EMI Re-ordering & Lock
    D.S SD:0xC00030F8 %LE %LONG 0x30000000
)


wait 100.ms

;Set MD CLK select. Although MAUI will do this by itslef, we raise clock here to speed up download flow

;*AP_MD_CONFG_CLKSW_CON0 = 0x1457;    // clock divider
D.S SD:0x810D0910 %LE %LONG 0x00001457

;*AP_MD_CONFG_CLKSW_CON2 = 0x0555;    // switch all MD clock from 52M to higher clock
D.S SD:0x810D0918 %LE %LONG 0x00000555

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  template_mt6575_nocode_postconfiguration
#              (this template will be used by MAUI nocode.cmm for MT6575 only)
# output:      template of MT6575 nocode.cmm to perform the following:
#              add button for Meta
#              set boot-jump address
#              configure MD UART
#****************************************************************************
sub template_mt6575_nocode_postconfiguration
{
    my $template = <<"__TEMPLATE";
; CodeVisor might need to set Config->Source Path if c-level mapping is not there.

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;------- Add buttom for META ------- 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

menu.addmenu "NORMAL.MODE" "D.S. SD:0x810D0010 %LE %WORD 0x0000"
menu.addmenu "META.MODE" "D.S. SD:0x810D0010 %LE %WORD 0x0001"

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;------- Set boot jump address ------- 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;*AP_MD_RGU_SW_MDMCU_RSTN = 0x0037;   // Un-gate md_arm; MD is un-gated in BootROM
;D.S SD:0x810C0040 %LE %WORD 0x0037

;*AP_MD_CONFG_BOOT_JUMP_ADDR = 0x0;   // Let md_arm leave loop and jump to 0x0
D.S SD:0x810D0980 %LE %LONG 0x00000000

; No need to set PC to 0x0, since the boot-jump will re-direct PC
;R.S PC 0x00000000 


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;------- MD UART configuration  ------- 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

// Modem UART1
;SET_GPIO_MODE(162,3); (reg default: 0x1249)
;SET_GPIO_MODE(161,3);
D.S SD:0xC0005E00 %LE %WORD 0x12C9
D.S SD:0xC0005E00 %LE %WORD 0x12D9

// Modem UART2
;SET_GPIO_MODE(80,3);
;SET_GPIO_MODE(82,3);
D.S SD:0xC0005D00 %LE %WORD 0x124B
D.S SD:0xC0005D00 %LE %WORD 0x12CB

__TEMPLATE

    return $template;
}
#****************************************************************************
# subroutine:  template_mt6280E1_DCM_workaround
#              work-around on MT6280 E1 for dcm driver to force ARM clock on
# output:      template of MT6280 nocode.cmm, intargetreset.cmm, auto_reset.cmm
#****************************************************************************
sub template_mt6280E1_DCM_workaround
{
    my $template;
    if( $PLATFORM eq 'MT6280')
    {
    $template = <<"__TEMPLATE";

;work-around on MT6280 E1 to set 0x8000001c[13]=1, because WFI breaks ICE connection
&HW_VER=DATA.LONG(D:0x80000000)
var.if &HW_VER==0xCA00
(
    d.s d:0x8000001c %long DATA.LONG(D:0x8000001c)|(1<<0xd)
)

__TEMPLATE
    }
    return $template;
}

sub DefineRegBaseChipName
{
    my ($strChipName) = @_;
    if($strChipName =~ /MT6589/i)
    {
        $strChipName = "MT6589";
    }
    return $strChipName;
}

#****************************************************************************
# subroutine:  error_handler
# input:       $error_msg:     error message
#****************************************************************************
sub error_handler
{
    my ($strErrorMsg, $strFile, $strLine) = @_;
    
    my $strFinalErrorMsg = "CMMGEN ERROR: $strErrorMsg at $strFile line $strLine\n";
    print $strFinalErrorMsg;
    die $strFinalErrorMsg;
}
