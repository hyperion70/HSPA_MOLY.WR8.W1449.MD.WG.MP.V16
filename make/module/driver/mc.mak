# Define source file\ lists to SRC_LIST
    SRC_LIST = driver/storage/mc/src/dcl_memory_card.c \
    		   driver/storage/mc/src/msdc.c \
    		   driver/storage/mc/src/usbms_msdc.c
    ifeq ($(filter __MSDC2_SD_MMC__, $(strip $(COM_DEFS))),)
        SRC_LIST    += driver/storage/mc/src/msdc_fake_kal.c \
    		    driver/storage/mc/src/msdc2.c \
    		    driver/storage/mc/src/sdio_drv.c \
        	    driver/storage/mc/src/msdc_test.c
    endif
## SD/MMC memory card select.
    ifneq ($(filter __MSDC_SD_MMC__, $(strip $(MODULE_DEFS))),)
        SRC_LIST    += driver/storage/mc/src/sd.c \
                    driver/storage/mc/src/sd_drv.c
        ifeq ($(filter __MSDC2_SD_MMC__, $(strip $(COM_DEFS))),)
            SRC_LIST    += driver/storage/mc/src/sd2.c \
                        driver/storage/mc/src/sd_drv2.c \
                        driver/storage/mc/src/sd_adap.c
        endif
    endif



#  Define include path lists to INC_DIR
INC_DIR = driver/drv/include \
          driver/drv_def \
          driver/storage/mc/inc \
          service/sst/include \
          driver/sys_drv/regbase/inc \
          driver/sys_drv/dma/inc \
          driver/sys_drv/counter/inc \
          service/sys_svc/dp/inc \
          service/fs/common/include


# Define the specified compile options to COMP_DEFS
COMP_DEFS =

# Define the source file search paths to SRC_PATH
SRC_PATH = driver/storage/mc/src

