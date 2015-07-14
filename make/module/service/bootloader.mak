##############################################################
# Define mini bootloader internal configuration
##############################################################
CRYPTO_SHARED_DRV_PLATFORM = MT6255 MT6922 MT6250
NFI_SHARED_DRV_PLATFORM    = MT6255 MT6922

ifneq ($(filter __EMMC_BOOTING__, $(strip $(MODULE_DEFS))),)
CRYPTO_SHARED_DRV_PLATFORM += MT6276
endif

##############################################################
# Define source file lists to SRC_LIST
##############################################################

ifeq ($(strip $(COMPILER)),GCC)
SRC_LIST = service/sys_svc/bootloader/src/bl_BOOTARM_GCC.S \
            service/sys_svc/bootloader/src/bl_regioninit_gcc.S \
            driver/sys_drv/cache/src/cp15_gcc.S
            
else
SRC_LIST = service/sys_svc/bootloader/src/bl_BOOTARM_RVCT.S \
            service/sys_svc/bootloader/src/bl_regioninit_RVCT.S \
            driver/sys_drv/cache/src/cp15_RVCT.S
endif

SRC_LIST +=  \
            service/sys_svc/bootloader/src/bl_Cache.c \
            service/sys_svc/bootloader/src/bl_DBGPRINT.c \
            service/sys_svc/bootloader/src/bl_FTL.c \
            service/sys_svc/bootloader/src/bl_GFH_body.c \
            service/sys_svc/bootloader/src/bl_ImageLoaderCommon.c \
            service/sys_svc/bootloader/src/bl_ImageLoader_v5.c \
            service/sys_svc/bootloader/src/bl_Init.c \
            service/sys_svc/bootloader/src/bl_Main.c \
            service/sys_svc/bootloader/src/bl_portingfunc.c \
            service/sys_svc/bootloader/src/bl_UART.c \
           $(strip $(BUILDBTLDVERNODIR))/bl_verno.c \
            service/sys_svc/bootloader/src/drv_comm_bl.c \
            service/sys_svc/bootloader/src/bl_NFI_V31.c


SRC_LIST += driver/md_drv/interface/l1_interface.c \
            $(strip $(BUILD_SYSDIR))/custom_blconfig.c \
            custom/driver/common/custom_flash.c \
            $(call AUTO_MERGE_FILE_CHECK,custom/driver/drv/misc_drv,custom_hw_default.c) \
            driver/sys_drv/init/src/init_comm.c \
            driver/sys_drv/pll/src/pll.c \
            driver/sys_drv/cache/src/mpu.c \
            service/sys_svc/gfh/public/br_GFH_parser.c \
            service/sys_svc/gfh/public/br_GFH_file_info.c

SRC_LIST    += driver/sys_drv/pdn/src/pdn.c \
            driver/peripheral/src/lpwr.c \
            driver/peripheral/src/f32k_clk.c \
            driver/peripheral/src/dcl_f32k_clk.c

# For 6280's Vm 
ifneq ($(filter MT6280, $(strip $(MODULE_DEFS))),)
SRC_LIST    += service/sys_svc/bootloader/src/pmic_adpt_bl.c \
            driver/peripheral/src/i2c_pmic.c
endif

ifneq ($(filter MT6256, $(strip $(MODULE_DEFS))),)
    SRC_LIST += custom/driver/common/custom_EMI_MT6256.c
else
    ifneq ($(filter MT6255, $(strip $(MODULE_DEFS))),)
        SRC_LIST += custom/driver/common/custom_EMI_MT6255.c  
    else
        ifneq ($(filter MT6280, $(strip $(MODULE_DEFS))),)
            SRC_LIST += custom/driver/common/custom_EMI_MT6280.c  
        else
            SRC_LIST += $(strip $(BUILD_SYSDIR))/custom_EMI.c
        endif    
    endif
endif



FILE_EXIST = $(wildcard custom/driver/common/custom_SFI.c)
ifneq ($(words $(strip $(FILE_EXIST))),0)
  SRC_LIST += custom/driver/common/custom_SFI.c
endif

ifneq ($(filter __SV5_ENABLED__,$(strip $(MODULE_DEFS))),)
  SRC_LIST    += service/sys_svc/bootloader/src/bl_GFH_body.c \
              service/sys_svc/bootloader/src/bl_ImageLoader_v5.c
endif

# NAND driver
ifeq ($(filter $(strip $(PLATFORM)), $(strip $(NFI_SHARED_DRV_PLATFORM))),)
  # For MT6235/MT6236
  ifneq ($(filter __NFI_VERSION2__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += \
                service/sys_svc/bootloader/src/bl_NFI.c
  endif
  # For MT6516
  ifneq ($(filter __NFI_VERSION3__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += \
    service/sys_svc/bootloader/src/bl_NFI_V3.c
  endif    
endif

# NOR/SF driver
ifeq ($(filter _NAND_FLASH_BOOTING_, $(strip $(MODULE_DEFS))),)
ifeq ($(filter __EMMC_BOOTING__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += \
              driver/storage/flash/mtd/src/flash_cfi.c \
              driver/storage/flash/mtd/src/flash_disk.c \
              driver/storage/flash/mtd/src/flash_mtd.c \
              driver/storage/flash/mtd/src/flash_mtd_pf_dal.c \
              driver/storage/flash/mtd/src/flash_mtd.amd.c \
              driver/storage/flash/mtd/src/flash_mtd.intel.c \
              driver/sys_drv/emi/src/emi.c
  ifneq ($(filter __SERIAL_FLASH_EN__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += \
                driver/storage/flash/mtd/src/flash_mtd_sf_common.c \
                driver/storage/flash/mtd/src/flash_mtd_sf_dal.c
  endif
endif
endif
# Combo memory flash relative inital 
ifneq ($(filter __SERIAL_FLASH_EN__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += \
              custom/driver/common/combo_flash_nor.c \
              custom/driver/common/combo_flash_init.c
else
  #flash common for combo inital
  ifneq ($(filter __COMBO_MEMORY_SUPPORT__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += \
                custom/driver/common/combo_flash_init.c
    #NOR flash combo inital                
    ifeq ($(filter _NAND_FLASH_BOOTING_, $(strip $(MODULE_DEFS))),)
      ifeq ($(filter __EMMC_BOOTING__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += \
                    custom/driver/common/combo_flash_nor.c
      endif
    endif
  endif              
endif
# eMMC driver
ifneq ($(filter __EMMC_BOOTING__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += $(call AUTO_MERGE_FILE_CHECK,custom/driver/drv/misc_drv,msdc_custom.c) \
              driver/storage/mc/src/msdc.c \
              driver/storage/mc/src/sd.c \
              driver/storage/mc/src/msdc_fake_kal.c \
              driver/storage/mc/src/dcl_memory_card.c \
              driver/storage/mc/src/sd_drv.c \
              driver/storage/mc/src/sd_adap.c \
              service/sys_svc/bootloader/src/msdc_dma_bl.c \
              service/sys_svc/bootloader/src/usbdl_upll.c
endif

# X-Booting driver
ifneq ($(filter __X_BOOTING__, $(strip $(MODULE_DEFS))),)
  SRC_LIST    += service/sys_svc/bootloader/src/bl_SDIO_drv.c
endif

##############################################################
#  Define include path lists to INC_DIR
##############################################################
INC_DIR = service/sys_svc/bootloader/inc \
          driver/sys_drv/pll/inc \
          driver/sys_drv/cache/inc \
          driver/drv/include \
          driver/storage/flash/mtd/inc \
          driver/storage/flash/fdm/inc \
          driver/storage/mc/inc \
          $(strip $(BUILD_CODEGENDIR)) \
          $(strip $(BUILD_SYSDIR)) \
          service/ssf/inc \
          service/sst/include \
          service/fs/Efs/include \
          service/fs/fat/include \
          interface/service/fs \
          interface/driver/hwdrv \
          service/sss/interface/inc \
          service/sys_svc/cbr/inc \
          service/sys_svc/gfh/public \
          service/sys_svc/profile/inc \
          driver/peripheral/inc \
          driver/storage/mc/inc \
          service/security/sds \
          driver/connectivity/usb_class/include \
          service/sys_svc/dp/inc \
          driver/connectivity/sdio_device_boot/inc

##############################################################
# Define the specified compile options to COMP_DEFS
##############################################################
COMP_DEFS = BL_ECC_ENABLE \
            __UBL__ \
            __MINI_BOOTLOADER__ \
            USBACM_TX_WITHOUT_DMA \
            BL_ENABLE \
            __CP_DEFINED_ALL_CONTEXT__ \
            __CP_DEFINED_WORKING_BUF__ \
            __CRYPTO_LIB__ \
            __CRYPTO_SCHEME__

ifneq ($(strip $(SMART_PHONE_CORE)),NONE)
  COMP_DEFS += __MD_BOOTLOADER__
endif

ifneq ($(strip $(PLATFORM)),MT6251)
ifneq ($(strip $(PACKAGE_SEG)),32_32_SEG)
  COMP_DEFS += BL_DEBUG
endif
endif

ifneq ($(filter $(strip $(PLATFORM)),$(SV5_PLATFORM)),)
  COMP_DEFS += __SV5_ENABLED__
endif

COMP_DEFS += $(strip $(PLATFORM))

ifneq ($(filter $(strip $(PLATFORM)),$(ARM9_PLATFORM)),)
  COMP_DEFS += ARM9_MMU
endif

ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
  COMP_DEFS  += _NAND_FLASH_BOOTING_
endif
    
ifdef EMMC_BOOTING
  ifneq ($(strip $(EMMC_BOOTING)),NONE)
    COMP_DEFS  += __EMMC_BOOTING__
  endif
endif

ifeq ($(strip $(FLASH_DRV_IN_BL)),NAND)
  COMP_DEFS  += __NAND_DRV_IN_BL__
  COMP_DEFS  += _NAND_FLASH_BOOTING_
  COMP_DEFS  += NAND_SUPPORT
endif
ifeq ($(strip $(FLASH_DRV_IN_BL)),SF)
  COMP_DEFS  += __SF_DRV_IN_BL__
endif
ifeq ($(strip $(FLASH_DRV_IN_BL)),EMMC)
  COMP_DEFS  += __EMMC_DRV_IN_BL__
  COMP_DEFS  += __EMMC_BOOTING__
endif
ifeq ($(strip $(FLASH_DRV_IN_BL)),NOR)
  COMP_DEFS  += __NOR_DRV_IN_BL__
endif

ifdef USB_DOWNLOAD_IN_BL
  ifneq ($(strip $(USB_DOWNLOAD_IN_BL)),NONE)
    COMP_DEFS += __USB_DOWNLOAD__
    ifeq ($(strip $(USB_DOWNLOAD_IN_BL)),SECURE)
      COMP_DEFS += __SECURE_USB_DOWNLOAD__
    endif
  endif
endif

ifdef IC_TEST_TYPE
  ifneq ($(strip $(IC_TEST_TYPE)),NONE)
    COMP_DEFS += __SKIP_VERSION_CHECK_FOR_BTMT__
  endif
endif

ifdef CRYPTO_SHARED_DRV_PLATFORM
  ifneq ($(filter $(strip $(PLATFORM)), $(strip $(CRYPTO_SHARED_DRV_PLATFORM))),)
    COMP_DEFS += __CRYPTO_SHARED_DRV__
  endif
endif

ifdef NFI_SHARED_DRV_PLATFORM
  ifneq ($(filter $(strip $(PLATFORM)), $(strip $(NFI_SHARED_DRV_PLATFORM))),)
    COMP_DEFS += __NFI_SHARED_DRV__
  endif
endif

# TS_PROFILING := TRUE
ifeq ($(TS_PROFILING),TRUE)

COMP_DEFS += \
             __TIME_STAMP__ \
             __TIME_STAMP_UTIL__ \
             __TIME_STAMP_TDMA_TIMER__ \
             __TIME_STAMP_FORCE_ENABLE__

COMP_DEFS += BL_DEBUG

SRC_LIST    += service/sys_svc/bootloader/src/bl_time_stamp_util.c \
            service/sys_svc/profile/src/br_time_stamp.c \
            service/sys_svc/profile/src/time_stamp_timer.c

endif