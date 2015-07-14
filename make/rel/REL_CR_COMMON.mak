#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2005
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

# *************************************************************************
# Custom Release Common Configuration
# *************************************************************************

CUS_REL_BASE_COMP  += $(call CUSTOM_FLD_MAPPING,custom/codegen)
CUS_REL_BASE_COMP  += $(call CUSTOM_FLD_MAPPING,custom/system)
CUS_REL_BASE_COMP  += $(call CUSTOM_FLD_MAPPING,custom/driver/drv_gen)
CUS_REL_BASE_COMP  += custom/driver/drv/Drv_Tool
CUS_REL_BASE_COMP  += custom/system/Template
CUS_REL_BASE_COMP  += service/sys_svc/bootloader
CUS_REL_BASE_COMP  += make/xgen
CUS_REL_BASE_COMP  += service/tst/database/XDD
CUS_REL_BASE_COMP  += tools
CUS_REL_BASE_COMP  += service/sss/lib
CUS_REL_BASE_COMP  += driver/storage/mc
CUS_REL_BASE_COMP  += custom/modem/l1_rf/MT6167_2G_CUSTOM
CUS_REL_BASE_COMP  += driver/audio/lib/MTKGCC

#Not release DwarfUtility for Customer
ifneq ($(strip $(MTK_SUBSIDIARY)),TRUE)
  NON_REL_DIRS_LIST += tools/DwarfUtility
endif
#Not release MemoryDeviceList_*Internal.xls for Customer
ifneq ($(strip $(MTK_SUBSIDIARY)),TRUE)
  ifeq ($(call Upper ,$(strip $(VENDOR))),NONE)
    NON_REL_FILES_LIST += $(wildcard tools/MemoryDeviceList/MemoryDeviceList_*Internal.xls)
  endif
endif
NON_REL_DIRS_LIST += tools/GCC
NON_REL_DIRS_LIST += tools/MinGW
NON_REL_DIRS_LIST += tools/MSYS


CUS_REL_FILES_LIST += service/tst/database/msglog_db/custom_parse_db.c
CUS_REL_FILES_LIST += service/tst/database/TrcGen.lst
ifeq ($(strip $(PLATFORM)), MT6280)
  CUS_REL_FILES_LIST += modem/ul1/ul1_hs_plus/ul1d_ext/auto_tcm_variable_list_mt6280_ul1_hs_plus_ext.txt
else ifeq ($(strip $(PLATFORM)), MT6589)
  CUS_REL_FILES_LIST += modem/ul1/ul1_hs_plus/ul1d_ext/auto_tcm_variable_list_mt6589_ul1_hs_plus_ext.txt
else ifeq ($(strip $(PLATFORM)), MT6572)
  CUS_REL_FILES_LIST += modem/ul1/ul1_hs_plus/ul1d_ext/auto_tcm_variable_list_mt6589_ul1_hs_plus_ext.txt
endif

CUS_REL_FILES_LIST += make.sh
CUS_REL_FILES_LIST += Make.bat
CUS_REL_FILES_LIST += m
CUS_REL_FILES_LIST += M.bat
CUS_REL_FILES_LIST += make.pl
CUS_REL_FILES_LIST += BuildMMAA.pl
CUS_REL_FILES_LIST += m_cp2lsf.pl
CUS_REL_FILES_LIST += make/build.mak
CUS_REL_FILES_LIST += make/Comp.mak
CUS_REL_FILES_LIST += make/cmd_cfg.mak
CUS_REL_FILES_LIST += make/Option.mak
CUS_REL_FILES_LIST += make/buildConfig.mak
CUS_REL_FILES_LIST += make/compiler.mak
CUS_REL_FILES_LIST += make/JAVA_DEF.mak
CUS_REL_FILES_LIST += make/checkvalue.mak
CUS_REL_FILES_LIST += make/standalone_action.mak
CUS_REL_FILES_LIST += make/OLD_FEATURES.mak
CUS_REL_FILES_LIST += make/MODEM.mak
CUS_REL_FILES_LIST += make/intermed.mak
CUS_REL_FILES_LIST += make/Codegen.mak
CUS_REL_FILES_LIST += make/Custom_Release.mak
CUS_REL_FILES_LIST += make/USER_SPECIFIC.mak
CUS_REL_FILES_LIST += make/rel/REL_CR_COMMON.mak
CUS_REL_FILES_LIST += make/$(subst ~,,$(notdir $(strip $(PROJECT_MAKEFILE))))
CUS_REL_FILES_LIST += make/custom_config/$(PROJECT_MAKEFILE_EXT).mak
CUS_REL_FILES_LIST += make/modem_spec/$(strip $(MODEM_SPEC)).mak
#ifdef SMART_PHONE_CORE
#  ifneq ($(strip $(SMART_PHONE_CORE)),NONE)
    CUS_REL_FILES_LIST += make/smart_phone_option.mak
#  endif
#endif
ifdef DSP_SOLUTION
  ifeq ($(strip $(DSP_SOLUTION)),DUALMACDSP)
    CUS_REL_FILES_LIST += make/DSP.mak
  endif
endif
ifdef NEED_DSP_FD_BIN
  ifeq ($(strip $(NEED_DSP_FD_BIN)),TRUE)
    CUS_REL_FILES_LIST += make/DSP.mak
  endif
endif
CUS_REL_FILES_LIST += make/module/driver/driver_config.mak
CUS_REL_FILES_LIST += make/module/middleware/middleware_config.mak
CUS_REL_FILES_LIST += make/module/modem/modem_config.mak
CUS_REL_FILES_LIST += make/module/service/service_config.mak

# release MT6280 E2 bootloader bin
ifeq ($(strip $(PLATFORM)),MT6280)
CUS_REL_FILES_LIST += service/bootloader_bin/MT6280_E2_BL_UTIL.bin
endif

