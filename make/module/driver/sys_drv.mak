# Define source file lists to SRC_LIST
SRC_LIST =          driver/sys_drv/cache/src/cache.c \
                    driver/sys_drv/dma/src/dma.c \
                    driver/sys_drv/pll/src/pll.c \
                    driver/sys_drv/counter/src/uscounter.c \
                    driver/sys_drv/pmu/src/arm11_pmu_montr.c \
                    driver/sys_drv/init/src/nfb_loader.c \
                    driver/sys_drv/init/src/idle_task.c \
                    driver/sys_drv/init/src/info.c \
                    driver/sys_drv/dcm/src/dcm_service.c 

ifneq ($(filter __EVENT_BASED_TIMER__, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=   driver/sys_drv/timer/src/event_timer.c
endif

ifneq ($(filter __DSP_FCORE4__, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=   driver/sys_drv/init/src/dmdsp_init.c
endif


ifneq ($(filter __MTK_TARGET__ , $(strip $(MODULE_DEFS))),)
    ifneq ($(filter  __MODEM_CCCI_EXIST__, $(strip $(MODULE_DEFS))),)	      
      ifneq ($(filter __SMART_PHONE_MODEM__, $(strip $(MODULE_DEFS))),)
      	ifneq ($(filter __SDIO_DEVICE_CONNECTIVITY__, $(strip $(MODULE_DEFS))),)
          SRC_LIST +=   driver/sys_drv/ipc/src/fs_ccci_sdio.c 
          SRC_LIST +=   driver/sys_drv/ipc/src/ccci_sdio.c 
          SRC_LIST +=   driver/sys_drv/ipc/src/ccci_uart_drv_sdio.c 
          SRC_LIST +=   driver/sys_drv/ipc/src/ipc_msgsvc_sdio.c 
          SRC_LIST +=   driver/sys_drv/ipc/src/ipc_rpc_sdio.c 
          SRC_LIST +=   driver/sys_drv/ipc/src/ipc_rpc_cpsvc_sdio.c	
      	else
          SRC_LIST +=   driver/sys_drv/ipc/src/fs_ccci.c
          SRC_LIST +=   driver/sys_drv/ipc/src/ccci.c
          SRC_LIST +=   driver/sys_drv/ipc/src/ccci_uart_drv.c 
          SRC_LIST +=   driver/sys_drv/ipc/src/ipc_msgsvc.c 
          SRC_LIST +=   driver/sys_drv/ipc/src/ipc_rpc.c 
          SRC_LIST +=   driver/sys_drv/ipc/src/ipc_rpc_cpsvc.c
          SRC_LIST +=   driver/sys_drv/ipc/src/ccci_fssvc.c
          SRC_LIST +=   driver/sys_drv/ipc/src/ccci_misc_info.c
        endif
      else
          SRC_LIST +=   driver/sys_drv/ipc/src/fs_ccci.c
          SRC_LIST +=   driver/sys_drv/ipc/src/ccci.c
          SRC_LIST +=   driver/sys_drv/ipc/src/ccci_uart_drv.c 
          SRC_LIST +=   driver/sys_drv/ipc/src/ipc_msgsvc.c 
          SRC_LIST +=   driver/sys_drv/ipc/src/ipc_rpc.c 
          SRC_LIST +=   driver/sys_drv/ipc/src/ipc_rpc_cpsvc.c
          SRC_LIST +=   driver/sys_drv/ipc/src/ccci_fssvc.c 
          SRC_LIST +=   driver/sys_drv/ipc/src/ccci_misc_info.c
      endif
    else
          SRC_LIST +=   driver/sys_drv/ipc/src/ccci.c	
    endif
endif

ifneq ($(filter __SMART_PHONE_MODEM__ , $(strip $(MODULE_DEFS))),)
      SRC_LIST +=   driver/sys_drv/emi/src/emimpu.c
endif

ifeq ($(filter __SMART_PHONE_MODEM__, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=   driver/sys_drv/emi/src/emi.c
else
      SRC_LIST +=   driver/sys_drv/emi/src/emi.c
endif

ifneq ($(filter __MTK_TARGET__, $(strip $(MODULE_DEFS))),)
  ifneq ($(filter __DSP_FCORE4__, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=   driver/sys_drv/ipc/src/mdci.c
  endif
endif

ifneq ($(filter DCM_ENABLE, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=   driver/sys_drv/dcm/src/dcm.c
else
  ifneq ($(filter __KTEST__, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=   driver/sys_drv/dcm/src/dcm.c
  else
    ifeq ($(filter L1_NOT_PRESENT, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=   driver/sys_drv/dcm/src/dcm.c
    endif
  endif
endif

ifneq ($(filter __MCU_DORMANT_MODE__, $(strip $(MODULE_DEFS))),)
      SRC_LIST += driver/sys_drv/dormant/src/dormant_service.c
endif

ifneq ($(filter __MTK_TARGET__, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=   driver/sys_drv/init/src/init.c 
      SRC_LIST +=   driver/sys_drv/init/src/init_comm.c 
      SRC_LIST +=   driver/sys_drv/init/src/init_trc.c 
      SRC_LIST +=   driver/sys_drv/init/src/boot_cert_pattern.c 
      SRC_LIST +=   driver/sys_drv/cirq/src/eint.c 
      SRC_LIST +=   driver/sys_drv/cirq/src/intrCtrl.c 
      SRC_LIST +=   driver/sys_drv/cirq/src/isrentry.c 
      SRC_LIST +=   driver/sys_drv/bus/src/bus_drv.c
      SRC_LIST +=   driver/sys_drv/pdn/src/pdn.c 
endif

ifeq ($(strip $(COMPILER)), GCC)
      SRC_LIST +=   driver/sys_drv/cache/src/cp15_gcc.S
   ifneq ($(filter __ARM_FPUV2__, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=   driver/sys_drv/vfp/src/vfp_gcc.S
   endif
   ifneq ($(filter __MTK_TARGET__, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=   driver/sys_drv/init/src/bootarm_gcc.S 
      SRC_LIST +=   driver/sys_drv/cirq/src/irq_gcc.S 
   endif
 ifneq ($(filter __MCU_DORMANT_MODE__, $(strip $(MODULE_DEFS))),)
   ifneq ($(filter __ARM1176__, $(strip $(MODULE_DEFS))),)
      SRC_LIST += driver/sys_drv/dormant/src/arm1176-dormantMode_gcc.S 
   endif
   ifneq ($(filter __CR4__, $(strip $(MODULE_DEFS))),)
      SRC_LIST += driver/sys_drv/dormant/src/cortexr4-dormantMode_gcc.S 
   endif
 endif
else  # RVCT
      SRC_LIST +=   driver/sys_drv/cache/src/cp15_rvct.S
   ifneq ($(filter __ARM_FPUV2__, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=   driver/sys_drv/vfp/src/vfp_rvct.S
   endif         
   ifneq ($(filter __MTK_TARGET__, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=   driver/sys_drv/init/src/bootarm_rvct.S 
      SRC_LIST +=   driver/sys_drv/cirq/src/irq_rvct.S 
   endif
 ifneq ($(filter __MCU_DORMANT_MODE__, $(strip $(MODULE_DEFS))),)
   ifneq ($(filter __ARM1176__, $(strip $(MODULE_DEFS))),)
      SRC_LIST += driver/sys_drv/dormant/src/arm1176-dormantMode_rvct.s 
   endif
   ifneq ($(filter __CR4__, $(strip $(MODULE_DEFS))),)
      SRC_LIST += driver/sys_drv/dormant/src/cortexr4-dormantMode_rvct.s 
   endif
 endif
endif

ifneq ($(filter __ARM9_MMU__, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=   driver/sys_drv/cache/src/mmu.c
endif

ifneq ($(filter __ARM11_MMU__, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=   driver/sys_drv/cache/src/mmu.c
endif

ifneq ($(filter __CR4__, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=   driver/sys_drv/cache/src/mpu.c
      SRC_LIST +=   driver/sys_drv/pmu/src/cr4_pmu_montr.c
endif


###################################################################
# Define include path lists to INC_DIR
INC_DIR = service/sst/include \
          $(strip $(PROJDIR))/verno \
          service/sss/interface/inc \
          service/security/sds \
          service/tst/local_inc \
          driver/drv/include \
          driver/peripheral/inc \
          driver/storage/flash/fdm/inc \
          driver/sys_drv/cache/inc \
          driver/sys_drv/bus/inc \
          driver/sys_drv/cirq/inc \
          driver/sys_drv/counter/inc \
          driver/sys_drv/dcm/inc \
          driver/sys_drv/dma/inc \
          driver/sys_drv/emi/inc \
          driver/sys_drv/init/inc \
          driver/sys_drv/ipc/inc \
          driver/sys_drv/pdn/inc \
          driver/sys_drv/pll/inc \
          driver/sys_drv/regbase/inc \
          driver/sys_drv/pmu/inc \
          service/sys_svc/region/inc \
          service/sys_svc/bootloader/inc \
          service/sys_svc/dp/inc \
          service/sys_svc/dcmgr/inc \
          service/sys_svc/excep_hdlr/inc \
          service/sys_svc/cbr/inc \
          service/sys_svc/gfh/public \
          service/sys_svc/compression/inc \
          service/sys_svc/profile/inc \
          driver/sys_drv/dormant/inc \
          driver/sys_drv/dormant/src 

###################################################################
# Define the specified compile options to COMP_DEFS
COMP_DEFS = APCS_INTWORK

COMP_DEFS += $(strip $(PLATFORM))


ifeq ($(strip $(NEED_BUILD_BOOTLOADER)),TRUE)
  ifeq ($(strip $(NAND_FLASH_BOOTING)),NONE)
    ifdef EMMC_BOOTING
      ifeq ($(strip $(EMMC_BOOTING)),NONE)  
        COMP_DEFS += __BL_ENABLE__
      endif
    else
      COMP_DEFS += __BL_ENABLE__
    endif
  endif
endif

ifdef NAND_FLASH_BOOTING
  ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
    COMP_DEFS  += _NAND_FLASH_BOOTING_
  endif
endif

ifdef EMMC_BOOTING
  ifneq ($(strip $(EMMC_BOOTING)),NONE)
    COMP_DEFS  += __EMMC_BOOTING__
  endif
endif

ifeq ($(strip $(MCU_DCM)),DCM_ENABLE)
  COMP_DEFS += DCM_ENABLE
endif

ifeq ($(strip $(ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT)),TRUE)
  COMP_DEFS += SINGLE_BANK_SUPPORT
endif

ifeq ($(TS_PROFILING),TRUE)
    COMP_DEFS   +=  __TIME_STAMP__\
                    __TIME_STAMP_UTIL__\
                    __TIME_STAMP_TDMA_TIMER__\
                    __TIME_STAMP_FORCE_ENABLE__
endif

