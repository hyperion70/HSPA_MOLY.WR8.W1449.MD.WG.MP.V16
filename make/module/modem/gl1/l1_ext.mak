# Define source file lists to SRC_LIST

SRC_LIST = $(strip $(MODEM_FOLDER))/gl1/l1_dm/l1d_ext/l1d_data.c \
           $(strip $(MODEM_FOLDER))/gl1/l1_dm/l1d_ext/m12190.c \
           $(strip $(MODEM_FOLDER))/gl1/l1_dm/l1d_ext/m12191.c \
           $(strip $(MODEM_FOLDER))/gl1/l1_dm/l1d_ext/m12192.c \
           $(strip $(MODEM_FOLDER))/gl1/l1_dm/l1d_ext/m12194.c \
           $(strip $(MODEM_FOLDER))/gl1/l1_dm/l1d_ext/m12195.c \
           $(strip $(MODEM_FOLDER))/gl1/l1_dm/l1d_ext/m12196.c

ifneq ($(filter __2G_RF_CUSTOM_TOOL_SUPPORT__, $(strip $(MODULE_DEFS))),)
   SRC_LIST += $(strip $(MODEM_FOLDER))/gl1/l1_dm/l1d_ext/m12197.c
endif

#  Define include path lists to INC_DIR
INC_DIR = $(strip $(MODEM_FOLDER))/gl1/l1_dm/l1d_ext

ifneq ($(filter __UE_SIMULATOR__, $(strip $(MODULE_DEFS))),)
  INC_DIR += l1_dm/common
endif

# Define the specified compile options to COMP_DEFS
COMP_DEFS = __CATEGORY_MODEM__

ifneq ($(filter __UE_SIMULATOR__, $(strip $(MODULE_DEFS))),)
  COMP_DEFS += L1_SIM L1D_SIM __HYPER_SLEEP_MODE_CHIP__ AFC_13bit
endif

# Define the source file search paths to SRC_PATH
SRC_PATH = $(strip $(MODEM_FOLDER))/gl1/l1_dm/l1d_ext

NOT_USE_CATEGORY_INCLUDE = TRUE
