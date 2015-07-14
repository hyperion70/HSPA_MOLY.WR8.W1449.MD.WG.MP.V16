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
# Custom Release Component Configuration
# *************************************************************************
# Be sure the following:
#    1. COMPLIST(for CUSTOM_RELEASE)      = CUS_REL_SRC_COMP + CUS_REL_PAR_SRC_COMP
#    2. CUS_REL_SRC_COMP + CUS_REL_PAR_SRC_COMP + CUS_REL_MTK_COMP = COMPLIST(CUSTOM_RELEASE = False)

CUS_REL_OPTION_FILTER   = TRUE
CUS_REL_HISTORY_FILTER  = TRUE
REL_PACKAGE_LEVEL = CR_BASIC

CUS_REL_BASE_COMP       =
CUS_REL_HDR_COMP        =
CUS_REL_FILES_LIST      =
CUS_REL_OBJ_LIST        =
NON_REL_FILES_LIST      =
NON_REL_DIRS_LIST       =

# Forbidden feature
#ifdef CHIP_VERSION_CHECK
#  ifneq ($(strip $(CHIP_VERSION_CHECK)),TRUE)
#    $(error Please set CHIP_VERSION_CHECK as TRUE !!)
#  endif
#endif

ifndef LEVEL
  LEVEL = LEVEL2_SRC
endif

include make/rel/REL_COMP_CR_MMI.mak

# reset for UCR
CUS_REL_BASE_COMP :=
CUS_REL_BASE_COMP += custom/driver/audio/_Default_BB/MT6572
CUS_REL_BASE_COMP += custom/driver/audio/_Default_BB/MT6580
CUS_REL_BASE_COMP += custom/driver/audio/_Default_BB/MT6582
CUS_REL_BASE_COMP += custom/driver/audio/_Default_BB/MT6592
CUS_REL_BASE_COMP += custom/driver/audio/_Default_BB/MT6571
CUS_REL_BASE_COMP += custom/driver/common
CUS_REL_BASE_COMP += custom/driver/drv/Drv_Tool
CUS_REL_BASE_COMP += custom/driver/drv/ast
CUS_REL_BASE_COMP += custom/driver/drv/misc_drv/_Default_BB/MT6572
CUS_REL_BASE_COMP += custom/driver/drv/misc_drv/_Default_BB/MT6580
CUS_REL_BASE_COMP += custom/driver/drv/misc_drv/_Default_BB/MT6582
CUS_REL_BASE_COMP += custom/driver/drv/misc_drv/_Default_BB/MT6592
CUS_REL_BASE_COMP += custom/driver/drv/misc_drv/_Default_BB/MT6571
CUS_REL_BASE_COMP += custom/middleware/common
CUS_REL_BASE_COMP += custom/modem/common
CUS_REL_BASE_COMP += custom/modem/common/atci/include
CUS_REL_BASE_COMP += custom/modem/common/atci/src
CUS_REL_BASE_COMP += custom/modem/common/ps
CUS_REL_BASE_COMP += custom/service/flc2
CUS_REL_BASE_COMP += custom/service/fs
CUS_REL_BASE_COMP += custom/service/nvram
CUS_REL_BASE_COMP += custom/service/tst
CUS_REL_BASE_COMP += custom/system/Template
CUS_REL_BASE_COMP += driver/audio/src
CUS_REL_BASE_COMP += driver/audio/src/v1
CUS_REL_BASE_COMP += driver/audio/src/v1/afes
CUS_REL_BASE_COMP += driver/audio/src/v1/inc
CUS_REL_BASE_COMP += driver/audio/src32_inc
CUS_REL_BASE_COMP += driver/audio/lib/MTKINC
CUS_REL_BASE_COMP += driver/audio/lib/MTKGCC
CUS_REL_BASE_COMP += driver/cipher/include
CUS_REL_BASE_COMP += driver/connectivity/usb_class/include
CUS_REL_BASE_COMP += driver/connectivity/usb_class/src
CUS_REL_BASE_COMP += driver/connectivity/usb_driver/inc
CUS_REL_BASE_COMP += driver/connectivity/usb_driver/src
CUS_REL_BASE_COMP += driver/dp_engine/che/include
CUS_REL_BASE_COMP += driver/drv/include
CUS_REL_BASE_COMP += driver/drv/src
CUS_REL_BASE_COMP += driver/drv_def
CUS_REL_BASE_COMP += driver/peripheral/inc
CUS_REL_BASE_COMP += driver/peripheral/src
CUS_REL_BASE_COMP += driver/sleep_drv/public/inc
CUS_REL_BASE_COMP += driver/storage/flash/fdm/inc
CUS_REL_BASE_COMP += driver/storage/flash/mtd/inc
CUS_REL_BASE_COMP += driver/storage/flash/mtd/src
CUS_REL_BASE_COMP += driver/storage/mc/inc
CUS_REL_BASE_COMP += driver/storage/mc/src
CUS_REL_BASE_COMP += driver/storage/sim/inc
CUS_REL_BASE_COMP += driver/storage/sim/src
CUS_REL_BASE_COMP += driver/sys_drv/bus/inc
CUS_REL_BASE_COMP += driver/sys_drv/bus/src
CUS_REL_BASE_COMP += driver/sys_drv/cache/inc
CUS_REL_BASE_COMP += driver/sys_drv/cache/src
CUS_REL_BASE_COMP += driver/sys_drv/cirq/inc
CUS_REL_BASE_COMP += driver/sys_drv/cirq/src
CUS_REL_BASE_COMP += driver/sys_drv/counter/inc
CUS_REL_BASE_COMP += driver/sys_drv/counter/src
CUS_REL_BASE_COMP += driver/sys_drv/dcm/inc
CUS_REL_BASE_COMP += driver/sys_drv/dcm/src
CUS_REL_BASE_COMP += driver/sys_drv/dma/inc
CUS_REL_BASE_COMP += driver/sys_drv/dma/src
CUS_REL_BASE_COMP += driver/sys_drv/dormant/inc
CUS_REL_BASE_COMP += driver/sys_drv/dormant/src
CUS_REL_BASE_COMP += driver/sys_drv/emi/inc
CUS_REL_BASE_COMP += driver/sys_drv/emi/src
CUS_REL_BASE_COMP += driver/sys_drv/init/inc
CUS_REL_BASE_COMP += driver/sys_drv/init/src
CUS_REL_BASE_COMP += driver/sys_drv/ipc/inc
CUS_REL_BASE_COMP += driver/sys_drv/ipc/src
CUS_REL_BASE_COMP += driver/sys_drv/pdn/inc
CUS_REL_BASE_COMP += driver/sys_drv/pdn/src
CUS_REL_BASE_COMP += driver/sys_drv/pll/inc
CUS_REL_BASE_COMP += driver/sys_drv/pll/src
CUS_REL_BASE_COMP += driver/sys_drv/pmu/inc
CUS_REL_BASE_COMP += driver/sys_drv/pmu/src
CUS_REL_BASE_COMP += driver/sys_drv/regbase/inc
CUS_REL_BASE_COMP += driver/sys_drv/timer/src
CUS_REL_BASE_COMP += interface/common
CUS_REL_BASE_COMP += interface/driver/audio
CUS_REL_BASE_COMP += interface/driver/cipher/include
CUS_REL_BASE_COMP += interface/driver/cmux
CUS_REL_BASE_COMP += interface/driver/connectivity/usb_driver
CUS_REL_BASE_COMP += interface/driver/connectivity/sdio_device
CUS_REL_BASE_COMP += interface/driver/drv_sw_def
CUS_REL_BASE_COMP += interface/driver/hwdrv
CUS_REL_BASE_COMP += interface/driver/peripheral
CUS_REL_BASE_COMP += interface/driver/sleep_drv
CUS_REL_BASE_COMP += interface/driver/storage
CUS_REL_BASE_COMP += interface/driver/storage/mc
CUS_REL_BASE_COMP += interface/driver/storage/sim
CUS_REL_BASE_COMP += interface/driver/sys_drv
CUS_REL_BASE_COMP += interface/middleware/general
CUS_REL_BASE_COMP += interface/middleware/media
CUS_REL_BASE_COMP += interface/middleware/meta
CUS_REL_BASE_COMP += interface/modem/general
CUS_REL_BASE_COMP += interface/modem/l1/fdd/external
CUS_REL_BASE_COMP += interface/modem/l1/gsm
CUS_REL_BASE_COMP += interface/modem/l1/tdd
CUS_REL_BASE_COMP += interface/modem/mcd
CUS_REL_BASE_COMP += interface/modem/tl1interface
CUS_REL_BASE_COMP += interface/sap
CUS_REL_BASE_COMP += interface/sap/drv
CUS_REL_BASE_COMP += interface/sap/md
CUS_REL_BASE_COMP += interface/sap/mw
CUS_REL_BASE_COMP += interface/sap/svc
CUS_REL_BASE_COMP += interface/service/asn1_common
CUS_REL_BASE_COMP += interface/service/config
CUS_REL_BASE_COMP += interface/service/event_info
CUS_REL_BASE_COMP += interface/service/fota
CUS_REL_BASE_COMP += interface/service/fs
CUS_REL_BASE_COMP += interface/service/fsm
CUS_REL_BASE_COMP += interface/service/kal
CUS_REL_BASE_COMP += interface/service/nvram
CUS_REL_BASE_COMP += interface/service/sst
CUS_REL_BASE_COMP += interface/service/stacklib
CUS_REL_BASE_COMP += interface/service/sys_svc
CUS_REL_BASE_COMP += interface/service/tst
CUS_REL_BASE_COMP += make/modem_spec
CUS_REL_BASE_COMP += make/module/driver/driver_config.mak
CUS_REL_BASE_COMP += make/module/middleware/middleware_config.mak
CUS_REL_BASE_COMP += make/module/modem/modem_config.mak
CUS_REL_BASE_COMP += make/module/service/service_config.mak
CUS_REL_BASE_COMP += make/xgen
CUS_REL_BASE_COMP += middleware/media/audio/include
CUS_REL_BASE_COMP += middleware/media/audio/src
CUS_REL_BASE_COMP += middleware/media/common/include
CUS_REL_BASE_COMP += middleware/media/common/src
CUS_REL_BASE_COMP += middleware/meta/ft/inc
CUS_REL_BASE_COMP += middleware/meta/ft/src
CUS_REL_BASE_COMP += middleware/meta/ftc
CUS_REL_BASE_COMP += modem/gl1/l1_dm/l1d_ext
CUS_REL_BASE_COMP += modem/interface/general
CUS_REL_BASE_COMP += modem/interface/l4
CUS_REL_BASE_COMP += modem/interface/l4misc
CUS_REL_BASE_COMP += modem/l4/include
CUS_REL_BASE_COMP += modem/l4/l4c/include/proc
CUS_REL_BASE_COMP += modem/l4/phb/include
CUS_REL_BASE_COMP += modem/l4/phb/src
CUS_REL_BASE_COMP += modem/l4/smsal/include
CUS_REL_BASE_COMP += modem/l4/smu/include
CUS_REL_BASE_COMP += modem/l4/uem/include
CUS_REL_BASE_COMP += modem/l4/uem/src
CUS_REL_BASE_COMP += modem/ul1/ul1_hs_plus/ul1d_ext
CUS_REL_BASE_COMP += service/config/src/hal
CUS_REL_BASE_COMP += service/fs/common/include
CUS_REL_BASE_COMP += service/fs/common/src
CUS_REL_BASE_COMP += service/fs/Efs/include
CUS_REL_BASE_COMP += service/fs/Efs/src
CUS_REL_BASE_COMP += service/fs/fat/include
CUS_REL_BASE_COMP += service/fs/fat/src
CUS_REL_BASE_COMP += service/fs/fsal/src
CUS_REL_BASE_COMP += service/kal/adaptation/include
CUS_REL_BASE_COMP += service/kal/common/include
CUS_REL_BASE_COMP += service/kal/mlib/include
CUS_REL_BASE_COMP += service/kal/nucleus/include
CUS_REL_BASE_COMP += service/nucleus/inc
CUS_REL_BASE_COMP += service/nucleus_v2/inc
CUS_REL_BASE_COMP += service/nvram/include
CUS_REL_BASE_COMP += service/nvram/src
CUS_REL_BASE_COMP += service/security/sds
CUS_REL_BASE_COMP += service/ssf/inc
CUS_REL_BASE_COMP += service/sss/interface/inc
CUS_REL_BASE_COMP += service/sss/lib
CUS_REL_BASE_COMP += service/sst/include
CUS_REL_BASE_COMP += service/sys_svc/bootloader/inc
CUS_REL_BASE_COMP += service/sys_svc/bootloader/src
CUS_REL_BASE_COMP += service/sys_svc/cbr/inc
CUS_REL_BASE_COMP += service/sys_svc/cbr/src
CUS_REL_BASE_COMP += service/sys_svc/compression/inc
CUS_REL_BASE_COMP += service/sys_svc/compression/src
CUS_REL_BASE_COMP += service/sys_svc/dcmgr/inc
CUS_REL_BASE_COMP += service/sys_svc/dcmgr/src
CUS_REL_BASE_COMP += service/sys_svc/dp/inc
CUS_REL_BASE_COMP += service/sys_svc/dp/src
CUS_REL_BASE_COMP += service/sys_svc/excep_hdlr/inc
CUS_REL_BASE_COMP += service/sys_svc/excep_hdlr/src
CUS_REL_BASE_COMP += service/sys_svc/ftl/src
CUS_REL_BASE_COMP += service/sys_svc/gfh/public
CUS_REL_BASE_COMP += service/sys_svc/profile/inc
CUS_REL_BASE_COMP += service/sys_svc/region/inc
CUS_REL_BASE_COMP += service/sys_svc/region/src
CUS_REL_BASE_COMP += service/tst/database/msglog_db
CUS_REL_BASE_COMP += service/tst/database/XDD
CUS_REL_BASE_COMP += service/tst/local_inc
CUS_REL_BASE_COMP += tools

# to be confirmed
CUS_REL_BASE_COMP += interface/middleware/gps
CUS_REL_BASE_COMP += modem/l4/atci/include
CUS_REL_BASE_COMP += modem/l4/l4c/include/common

CUS_REL_FILES_LIST :=
CUS_REL_FILES_LIST += BuildMMAA.pl
CUS_REL_FILES_LIST += M.bat
CUS_REL_FILES_LIST += Make.bat
CUS_REL_FILES_LIST += m
CUS_REL_FILES_LIST += make.pl
CUS_REL_FILES_LIST += make.sh
CUS_REL_FILES_LIST += make/Codegen.mak
CUS_REL_FILES_LIST += make/Comp.mak
CUS_REL_FILES_LIST += make/Custom.bld
CUS_REL_FILES_LIST += make/DSP.mak
CUS_REL_FILES_LIST += make/Extra_dep.mak
CUS_REL_FILES_LIST += make/JAVA_DEF.mak
CUS_REL_FILES_LIST += make/MODEM.mak
CUS_REL_FILES_LIST += make/OLD_FEATURES.mak
CUS_REL_FILES_LIST += make/Option.mak
CUS_REL_FILES_LIST += make/USER_SPECIFIC.mak
CUS_REL_FILES_LIST += make/build.mak
CUS_REL_FILES_LIST += make/buildConfig.mak
CUS_REL_FILES_LIST += make/checkvalue.mak
CUS_REL_FILES_LIST += make/cmd_cfg.mak
CUS_REL_FILES_LIST += make/compiler.mak
CUS_REL_FILES_LIST += make/compiler_cfg.mak
CUS_REL_FILES_LIST += make/intermed.mak
CUS_REL_FILES_LIST += make/rel/REL_COMP_COMMON.mak
CUS_REL_FILES_LIST += make/rel/REL_COMP_CR_COMMON.mak
CUS_REL_FILES_LIST += make/rel/REL_COMP_CR_MMI.mak
CUS_REL_FILES_LIST += make/rel/REL_CR_BASIC.mak
CUS_REL_FILES_LIST += make/rel/REL_CR_COMMON.mak
CUS_REL_FILES_LIST += make/smart_phone_option.mak
CUS_REL_FILES_LIST += make/standalone_action.mak
CUS_REL_FILES_LIST += service/tst/database/*.*
CUS_REL_FILES_LIST += service/tst/database/*_Cnf*

# special case
CUS_REL_CUSTOM_FEATURE := BOARD_VER_FLAVOR RF_MODULE UMTS_RF_MODULE UMTS_TDD128_RF_MODULE
CUS_REL_CUSTOM_BOARD_VER_FLAVOR := custom/driver/audio
CUS_REL_CUSTOM_BOARD_VER_FLAVOR += custom/driver/drv/gps
CUS_REL_CUSTOM_BOARD_VER_FLAVOR += custom/driver/drv/misc_drv
CUS_REL_CUSTOM_BOARD_VER_FLAVOR += custom/driver/drv_gen
CUS_REL_CUSTOM_BOARD_VER_FLAVOR += custom/middleware/meta
CUS_REL_CUSTOM_BOARD_VER_FLAVOR += custom/modem/ps
CUS_REL_CUSTOM_BOARD_VER_FLAVOR += custom/system
CUS_REL_CUSTOM_RF_MODULE        := custom/modem/l1_rf
CUS_REL_CUSTOM_UMTS_RF_MODULE   := custom/modem/ul1_rf
CUS_REL_CUSTOM_UMTS_TDD128_RF_MODULE := custom/modem/tl1_rf

NON_REL_DIRS_LIST :=
NON_REL_DIRS_LIST += tools/GCC
NON_REL_DIRS_LIST += tools/MinGW
NON_REL_DIRS_LIST += tools/MSYS
NON_REL_DIRS_LIST += tools/DwarfUtility
NON_REL_DIRS_LIST += interface/modem/secured

NON_REL_FILES_LIST :=
NON_REL_FILES_LIST += tools/MemoryDeviceList/MemoryDeviceList_*Internal.xls

