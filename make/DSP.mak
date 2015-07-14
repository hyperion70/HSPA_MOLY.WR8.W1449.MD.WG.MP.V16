# *************************************************************************
# Setting for DSP
# *************************************************************************
ifndef SUPPORT_FOR_SMARTPHONE_GPRS
  SUPPORT_FOR_SMARTPHONE_GPRS = FALSE
endif

ifndef UMTS_MODE_SUPPORT
  UMTS_MODE_SUPPORT = NONE
endif

DSP_FC_PLATFORM = MT6276 MT6573 MT6575 MT6577
ifneq ($(filter $(strip $(PLATFORM)),$(DSP_FC_PLATFORM)),)
  DSP_SOLUTION = DUALMACDSP
  ifndef DUALMACDSP_BIN
    DUALMACDSP_BIN  =  $(strip $(PLATFORM))_$(strip $(CHIP_VER))_GPRS_REL_ROM
  endif
  ifndef DUALMACDSP_BL_BIN
    DUALMACDSP_BL_BIN = $(strip $(PLATFORM))_$(strip $(CHIP_VER))_REL_BL
  endif
endif

# -----------------------------
# DSP_ROM and DSP_BL Setting
# -----------------------------
ifdef DSP_SOLUTION
  ifeq ($(strip $(DSP_SOLUTION)),DUALMACDSP)
    ifneq ($(filter __SMARTPHONE_GPRS_ONLY__,$(strip $(COM_DEFS))),)
      SUPPORT_FOR_SMARTPHONE_GPRS = TRUE
      DUALMACDSP_BIN	=  $(strip $(PLATFORM))_$(strip $(CHIP_VER))_GPRS(SMARTPHONE_GPRS_ONLY)_REL_ROM
      DUALMACDSP_BL_BIN	=  $(strip $(PLATFORM))_$(strip $(CHIP_VER))(SMARTPHONE_GPRS_ONLY)_REL_BL
    endif
    ifeq ($(strip $(PLATFORM)),MT6573)
      ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_TDD128_MODE_SUPPORT)
        DUALMACDSP_BIN	=  $(strip $(PLATFORM))_$(strip $(CHIP_VER))_GPRS(UMTS_TDD128_MODE)_REL_ROM
        DUALMACDSP_BL_BIN	=  $(strip $(PLATFORM))_$(strip $(CHIP_VER))(UMTS_TDD128_MODE)_REL_BL
      endif
    endif
  endif
endif

# -----------------------------
# Custom Release Setting 
# -----------------------------
DSP_DB_FILE_PREFIX = service\tst\database\viti_db\BPLGUInfo_DUALMACDSP_$(subst _REL_ROM,,$(strip $(DUALMACDSP_BIN)))
ifdef DSP_SOLUTION
  ifeq ($(strip $(DSP_SOLUTION)),DUALMACDSP)
    CUS_REL_FILES_LIST += modem\dsp_bin\$(strip $(DUALMACDSP_BIN)).bin
    CUS_REL_FILES_LIST += modem\dsp_bin\$(strip $(DUALMACDSP_BL_BIN)).bin
    DSP_DB_FILE = $(shell dir $(DSP_DB_FILE_PREFIX)* /b 2>nul)
    ifneq ($(words $(DSP_DB_FILE)),0)
      CUS_REL_FILES_LIST += $(foreach file,$(DSP_DB_FILE),tst\database\viti_db\$(file))
    endif
  endif
endif

# -----------------------------
# DSP FD Setting
# -----------------------------
DSP_FD_PLATFORM = MT6256
ifneq ($(filter $(strip $(PLATFORM)),$(strip $(DSP_FD_PLATFORM))),)
  DSP_HW_FILE = $(shell dir .\modem\dsp_bin\$(strip $(PLATFORM))_$(strip $(CHIP_VER))_ROM.bin /b 2>nul)
  ifeq ($(strip $(call Upper,$(PLATFORM))),MT6256)
    ifeq ($(strip $(call Upper,$(CHIP_VER))),S01)
      ifeq ($(words $(strip $(DSP_HW_FILE))),0)
        $(warning ERROR: .\modem\dsp_bin\$(strip $(PLATFORM))_$(strip $(CHIP_VER))_ROM.bin should exist when PLATFORM=$(strip $(PLATFORM)) and CHIP_VER=$(strip $(CHIP_VER))) 
        DEPENDENCY_CONFLICT = TRUE
      else
        NEED_DSP_FD_BIN = TRUE
        CUS_REL_FILES_LIST += modem\dsp_bin\$(strip $(PLATFORM))_$(strip $(CHIP_VER))_ROM.bin
      endif
    endif  
  endif
endif