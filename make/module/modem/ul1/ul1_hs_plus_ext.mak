# Define source file lists to SRC_LIST
ifeq ($(strip $(UMTS_RELEASE_SUPPORT)),UMTS_R8_SUPPORT)
SRC_LIST = $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_ext/wdata.c
else
   ifeq ($(strip $(UMTS_RELEASE_SUPPORT)),UMTS_R7_SUPPORT)
   SRC_LIST = $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_ext/wdata.c                         
   else
   SRC_LIST = $(strip $(MODEM_FOLDER))/ul1/ul1_hs/ul1d_ext/wdata.c   
   endif
endif
                   
# Define include path lists to INC_DIR
ifeq ($(strip $(UMTS_RELEASE_SUPPORT)),UMTS_R8_SUPPORT)
INC_DIR = $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_ext
else
   ifeq ($(strip $(UMTS_RELEASE_SUPPORT)),UMTS_R7_SUPPORT)
   INC_DIR = $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_ext                       
   else
   INC_DIR = $(strip $(MODEM_FOLDER))/ul1/ul1_hs/ul1d_ext
   endif
endif


# Define the specified compile options to COMP_DEFS
COMP_DEFS = __FS_FILTER__ \
            __CATEGORY_MODEM__

# Define the source file search paths to SRC_PATH
ifeq ($(strip $(UMTS_RELEASE_SUPPORT)),UMTS_R8_SUPPORT)
SRC_PATH = $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_ext
else
   ifeq ($(strip $(UMTS_RELEASE_SUPPORT)),UMTS_R7_SUPPORT)
   SRC_PATH = $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_ext                     
   else
   SRC_PATH = $(strip $(MODEM_FOLDER))/ul1/ul1_hs/ul1d_ext
   endif
endif

ifeq ($(strip $(PLATFORM)), MT6280)
  SRC_RULE_AUTOTCM := ALL  
  TARGET_AUTOTCM_LIST := NO_LIST modem/ul1/ul1_hs_plus/ul1d_ext/auto_tcm_variable_list_mt6280_ul1_hs_plus_ext.txt
else ifeq ($(strip $(PLATFORM)), MT6589)
  SRC_RULE_AUTOTCM := ALL
  TARGET_AUTOTCM_LIST := NO_LIST modem/ul1/ul1_hs_plus/ul1d_ext/auto_tcm_variable_list_mt6589_ul1_hs_plus_ext.txt
else ifeq ($(strip $(PLATFORM)), MT6572)
  SRC_RULE_AUTOTCM := ALL
  TARGET_AUTOTCM_LIST := NO_LIST modem/ul1/ul1_hs_plus/ul1d_ext/auto_tcm_variable_list_mt6589_ul1_hs_plus_ext.txt
else ifeq ($(strip $(PLATFORM)), MT6582)
  SRC_RULE_AUTOTCM := ALL
  TARGET_AUTOTCM_LIST := NO_LIST modem/ul1/ul1_hs_plus/ul1d_ext/auto_tcm_variable_list_mt6589_ul1_hs_plus_ext.txt
else ifeq ($(strip $(PLATFORM)), MT6592)
  SRC_RULE_AUTOTCM := ALL
  TARGET_AUTOTCM_LIST := NO_LIST modem/ul1/ul1_hs_plus/ul1d_ext/auto_tcm_variable_list_mt6589_ul1_hs_plus_ext.txt
else ifeq ($(strip $(PLATFORM)), MT6580)
  SRC_RULE_AUTOTCM := ALL
  TARGET_AUTOTCM_LIST := NO_LIST modem/ul1/ul1_hs_plus/ul1d_ext/auto_tcm_variable_list_mt6589_ul1_hs_plus_ext.txt
else
  $(warning ERROR: No AutoTCM Placement List for This Platform!)
endif

NOT_USE_CATEGORY_INCLUDE = TRUE
