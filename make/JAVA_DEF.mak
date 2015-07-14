Upper = $(subst z,Z,$(subst y,Y,$(subst x,X,$(subst w,W,$(subst v,V,$(subst u,U,$(subst t,T,$(subst s,S,$(subst r,R,$(subst q,Q,$(subst p,P,$(subst o,O,$(subst n,N,$(subst m,M,$(subst l,L,$(subst k,K,$(subst j,J,$(subst i,I,$(subst h,H,$(subst g,G,$(subst f,F,$(subst e,E,$(subst d,D,$(subst c,C,$(subst b,B,$(subst a,A,$(1)))))))))))))))))))))))))))

# *************************************************************************
# JAVA Value Check
# *************************************************************************
ifdef J2ME_SUPPORT
    ifeq ($(strip $(J2ME_SUPPORT)),IJET)
        $(warning ERROR: J2ME_SUPPORT cannot be set as $(strip $(J2ME_SUPPORT)) in MAUI)
        DEPENDENCY_CONFLICT = TRUE
    endif
endif

ifeq ($(strip $(J2ME_SLIM_MEMORY_SUPPORT)),TRUE)
  ifdef J2ME_SUPPORT
    ifeq ($(strip $(J2ME_SUPPORT)),NONE)
      $(warning ERROR: when J2ME_SUPPORT is not enabled,please turn off J2ME_SLIM_MEMORY_SUPPORT.)
      DEPENDENCY_CONFLICT = TRUE
    endif
  else
    $(warning ERROR: when J2ME_SUPPORT is not enabled,please turn off J2ME_SLIM_MEMORY_SUPPORT.)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(SUPPORT_JSR_177)),TRUE)
  ifneq ($(strip $(J2ME_SUPPORT)),NEMO)
    $(call DEP_ERR_SETA_OR_OFFB,J2ME_SUPPORT,NEMO,SUPPORT_JSR_177)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifneq ($(strip $(J2ME_FEATURE_SET)),JTWI)
    $(call DEP_ERR_SETA_OR_OFFB,J2ME_FEATURE_SET,JTWI,SUPPORT_JSR_177)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS  += SUPPORT_JSR_177
  COM_DEFS  += __SIM_JSR177_APDU__
endif
ifeq ($(strip $(SUPPORT_JSR_257)),TRUE)
  ifneq ($(strip $(SUPPORT_JSR_177)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,SUPPORT_JSR_177,SUPPORT_JSR_257)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifneq ($(strip $(J2ME_SUPPORT)),NEMO)
    $(call DEP_ERR_SETA_OR_OFFB,J2ME_SUPPORT,NEMO,SUPPORT_JSR_257)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifneq ($(strip $(J2ME_FEATURE_SET)),JTWI)
    $(call DEP_ERR_SETA_OR_OFFB,J2ME_FEATURE_SET,JTWI,SUPPORT_JSR_257)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS  += SUPPORT_JSR_257
endif
# *************************************************************************
# Java Feature Setting
# *************************************************************************

J2ME_FEATURE_SET = JTWI

ifdef J2ME_SUPPORT
    ifneq ($(strip $(J2ME_SUPPORT)),NONE)
        ifneq ($(filter MT6223%,$(PLATFORM)),)
            ifdef SUPPORT_JSR_82
                ifeq ($(strip $(call Upper,$(SUPPORT_JSR_82))),TRUE)
                    $(warning ERROR: Please turn off SUPPORT_JSR_82 when PLATFORM is $(strip $(PLATFORM)))
                    DEPENDENCY_CONFLICT = TRUE
                endif
            endif
        endif

        COM_DEFS += SUPPORT_HTTP_OVER_WSP
        
        ifdef J2ME_FEATURE_SET
            ifeq ($(strip $(call Upper,$(J2ME_FEATURE_SET))),BASIC)
                ifdef J2ME_SHARE_MED_EXT_MEM
                    ifeq ($(strip $(call Upper,$(J2ME_SHARE_MED_EXT_MEM))),TRUE)
                        COM_DEFS += J2ME_SHARE_MED_EXT_MEM
                    endif
                endif
            endif

            ifeq ($(strip $(call Upper,$(J2ME_FEATURE_SET))),JTWI)
                COM_DEFS += SUPPORT_WMA
                COM_DEFS += SUPPORT_JSR_120
                COM_DEFS += SUPPORT_MMAPI
                COM_DEFS += SUPPORT_JSR_135
                COM_DEFS += SUPPORT_JSR_75_FILE
        
                ifdef SUPPORT_JSR_75_PIM
                    ifeq ($(strip $(call Upper,$(SUPPORT_JSR_75_PIM))),TRUE)
                        COM_DEFS += SUPPORT_JSR_75_PIM
                    endif
                endif
            
                ifdef SUPPORT_JSR_75_PIM_MSA
                    ifeq ($(strip $(call Upper,$(SUPPORT_JSR_75_PIM_MSA))),TRUE)
                        ifneq ($(strip $(call Upper,$(SUPPORT_JSR_75_PIM))),TRUE)
                            $(call DEP_ERR_ONA_OR_OFFB,SUPPORT_JSR_75_PIM,SUPPORT_JSR_75_PIM_MSA)
                            DEPENDENCY_CONFLICT = TRUE
                        endif
                        ifeq ($(strip $(call Upper,$(J2ME_SUPPORT))),JBLENDIA)
                            $(call DEP_ERR_SETA_OR_OFFB,J2ME_SUPPORT,non JBLENDIA,SUPPORT_JSR_75_PIM_MSA)
                            DEPENDENCY_CONFLICT = TRUE
                        endif
                        ifeq ($(strip $(call Upper,$(J2ME_SUPPORT))),JBLENDIA_MVM)
                            $(call DEP_ERR_SETA_OR_OFFB,J2ME_SUPPORT,non JBLENDIA_MVM,SUPPORT_JSR_75_PIM_MSA)
                            DEPENDENCY_CONFLICT = TRUE
                        endif
                        COM_DEFS += SUPPORT_JSR_75_PIM_MSA
                    endif
                endif
        
        
                ifdef SUPPORT_JSR_205
                    ifeq ($(strip $(call Upper,$(SUPPORT_JSR_205))),TRUE)
                        COM_DEFS += SUPPORT_WMA_MMS
                        COM_DEFS += SUPPORT_JSR_205
                    endif
                endif
            
                ifdef SUPPORT_JSR_82
                    ifeq ($(strip $(call Upper,$(SUPPORT_JSR_82))),TRUE)
                        ifneq ($(strip $(call Upper,$(SUPPORT_JSR_75_PIM))),TRUE)
                            $(call DEP_ERR_ONA_OR_OFFB,SUPPORT_JSR_75_PIM,SUPPORT_JSR_82)
                            DEPENDENCY_CONFLICT = TRUE
                        endif
                        ifneq ($(strip $(SUPPORT_JAVA_NOKIA_UI)),TRUE)
                            $(call DEP_ERR_ONA_OR_OFFB,SUPPORT_JAVA_NOKIA_UI,SUPPORT_JSR_82)
                            DEPENDENCY_CONFLICT = TRUE
                        endif
                        ifneq ($(strip $(J2ME_FEATURE_SET)),JTWI)
                            $(call DEP_ERR_SETA_OR_OFFB,J2ME_FEATURE_SET,JTWI,SUPPORT_JSR_82)
                            DEPENDENCY_CONFLICT = TRUE
                        endif
                        ifneq ($(strip $(J2ME_VM)),HI_VM)
                            $(call DEP_ERR_SETA_OR_OFFB,J2ME_VM,HI_VM,SUPPORT_JSR_82)
                            DEPENDENCY_CONFLICT = TRUE
                        endif
                        COM_DEFS += __SUPPORT_JBT__
                    endif
                endif

                ifdef J2ME_SHARE_MED_EXT_MEM
                    ifeq ($(strip $(call Upper,$(J2ME_SHARE_MED_EXT_MEM))),TRUE)
                        COM_DEFS += J2ME_SHARE_MED_EXT_MEM
                    endif
                endif
            endif
        endif
                
        ifdef SUPPORT_JAVA_NOKIA_UI
            ifeq ($(strip $(SUPPORT_JAVA_NOKIA_UI)),TRUE)
                COM_DEFS += SUPPORT_JAVA_NOKIA_UI
            endif
        endif

        ifdef SUPPORT_JSR_179
            ifeq ($(strip $(call Upper,$(SUPPORT_JSR_179))),TRUE)
                ifeq ($(strip $(call Upper,$(GPS_SUPPORT))),NONE)
                    $(call DEP_ERR_ONA_OR_OFFB,GPS_SUPPORT,SUPPORT_JSR_179)
                    DEPENDENCY_CONFLICT = TRUE
                endif
                ifndef GPS_SUPPORT
                    $(call DEP_ERR_ONA_OR_OFFB,GPS_SUPPORT,SUPPORT_JSR_179)
                    DEPENDENCY_CONFLICT = TRUE
                endif
                COM_DEFS += SUPPORT_LOCATION
                COM_DEFS += SUPPORT_JSR_179
            endif
        endif    
    endif
endif

# *************************************************************************
# J2ME OTHER COMPILE OPTION
# *************************************************************************

ifdef J2ME_SUPPORT
    ifneq ($(strip $(J2ME_SUPPORT)),NONE)
        ifeq ($(strip $(J2ME_VM)),KVM)
            COM_DEFS    += __KVM__
        endif
        ifeq ($(strip $(J2ME_VM)),HI_VM)
            COM_DEFS    += __HI_VM__
        endif
        ifeq ($(strip $(J2ME_VM)),KVM_SOURCE)
            COM_DEFS    += __KVM__
        endif
        ifeq ($(strip $(J2ME_VM)),HI_VM_SOURCE)
            COM_DEFS    += __HI_VM__
        endif
        ifeq ($(strip $(J2ME_VM)),JAZELLE)
            COM_DEFS    += __JAZELLE__
        endif
        ifeq ($(strip $(J2ME_VM)),NEMO_VM)
            COM_DEFS    += __HI_VM__
        endif
        ifeq ($(strip $(J2ME_VM)),NEMO_VM_SOURCE_NORMAL)
            COM_DEFS    += __HI_VM__
        endif
        ifeq ($(strip $(J2ME_VM)),NEMO_VM_SOURCE_FULL)
            COM_DEFS    += __HI_VM__
        endif        
    endif
endif

ifdef J2ME_SUPPORT
    ifneq ($(strip $(J2ME_SUPPORT)),NONE)
        COM_DEFS += __J2ME__
    endif
    COM_DEFS    += MAX_VM_INSTANCE_NUM=1
    
    ifeq ($(strip $(J2ME_SUPPORT)),IJET)
        ifeq ($(strip $(J2ME_VM)),KVM)
            COM_DEFS    += CLDC11 __IJET_VM__
        endif
        
        ifeq ($(strip $(J2ME_VM)),KVM_SOURCE)
            COM_DEFS    += CLDC11 __IJET_VM__
        endif
        
        ifeq ($(strip $(J2ME_VM)),HI_VM)
            COM_DEFS    += CLDCHI __IJET_VM__
        endif
        
        ifeq ($(strip $(J2ME_VM)),HI_VM_SOURCE)
            COM_DEFS    += CLDCHI __IJET_VM__
        endif
        COM_DEFS    += MAX_VM_INSTANCE_NUM=1
    endif
    
    ifeq ($(strip $(J2ME_SUPPORT)),JBLENDIA)
        COM_DEFS    += __JBLENDIA__ AJ_LITTLE_ENDIAN __UCS2_ENCODING APLIX_JAVA AJ_PLATFORM_ARM
        COM_DEFS    += MAX_VM_INSTANCE_NUM=1
    endif

    ifeq ($(strip $(J2ME_SUPPORT)),JBLENDIA_MVM)
        COM_DEFS    += __JBLENDIA__ __MVM__
        ifdef J2ME_MAX_LAUNCH_NUM
            COM_DEFS    += MAX_VM_INSTANCE_NUM=$(strip $(J2ME_MAX_LAUNCH_NUM))
        else
            COM_DEFS    += MAX_VM_INSTANCE_NUM=1
        endif
    endif
    
    ifeq ($(strip $(J2ME_SUPPORT)),JBED)
        COM_DEFS    += __JBED__
        COM_DEFS    += MAX_VM_INSTANCE_NUM=1
    endif
    
    ifeq ($(strip $(J2ME_SUPPORT)),NEMO)
        ifeq ($(filter NEMO_VM_SOURCE_FULL NEMO_VM_SOURCE_NORMAL NEMO_VM,$(strip $(J2ME_VM))),)
            $(warning ERROR: Please set J2ME_VM=NEMO_VM/NEMO_VM_SOURCE_NORMAL/NEMO_VM_SOURCE_FULL when J2ME_SUPPORT=NEMO)
            DEPENDENCY_CONFLICT = TRUE
        endif
        
        ifeq ($(strip $(J2ME_VM)),NEMO_VM_SOURCE_FULL)
            COM_DEFS    += CLDCHI __NEMO_VM__ __MVM__
        endif
  
        ifeq ($(strip $(J2ME_VM)),NEMO_VM_SOURCE_NORMAL)
            COM_DEFS    += CLDCHI __NEMO_VM__ __MVM__
        endif

        ifeq ($(strip $(J2ME_VM)),NEMO_VM)
            COM_DEFS    += CLDCHI __NEMO_VM__ __MVM__
        endif
        
        ifdef J2ME_MAX_LAUNCH_NUM
            COM_DEFS    += MAX_VM_INSTANCE_NUM=$(strip $(J2ME_MAX_LAUNCH_NUM))
        else
            COM_DEFS    += MAX_VM_INSTANCE_NUM=1
        endif        
    endif
    ifeq ($(strip $(J2ME_SUPPORT)),MTK_DUMMY_MVM)
        COM_DEFS += __J2ME__ __MVM__  
        ifdef J2ME_MAX_LAUNCH_NUM
            COM_DEFS    += MAX_VM_INSTANCE_NUM=$(strip $(J2ME_MAX_LAUNCH_NUM))
        else
            COM_DEFS    += MAX_VM_INSTANCE_NUM=1
        endif
    endif    
else
    COM_DEFS    += MAX_VM_INSTANCE_NUM=0   
endif


# *************************************************************************
# J2ME LIBRARY CONFIG
# *************************************************************************
ifdef J2ME_SUPPORT
    ifeq ($(strip $(J2ME_SUPPORT)),IJET)
        ifeq ($(strip $(J2ME_VM)),HI_VM)
            COMPOBJS    += j2me\vm\ijet\j2me_hi.lib
        endif
            
        ifeq ($(strip $(J2ME_VM)),KVM)
            COMPOBJS    += j2me\vm\ijet\j2me_11.lib
        endif
        ifeq ($(strip $(J2ME_VM)),KVM_KDWP)
            COMPOBJS    += j2me\vm\ijet\j2me_11_KDWP.lib
        endif
    endif

    ifeq ($(strip $(J2ME_SUPPORT)),NEMO)
    	  ifeq ($(strip $(J2ME_VM)),NEMO_VM)
    	      ifeq ($(strip $(J2ME_SLIM_MEMORY_SUPPORT)),TRUE)
    	          COMPOBJS    += j2me\vm\NEMO\j2me_nemo_cldc_slim.lib
    	      else
                  COMPOBJS    += j2me\vm\NEMO\j2me_nemo_cldc.lib
    	      endif
  	        COMPOBJS    += j2me\vm\NEMO\j2me_nemo_fdlibm.lib

    	      COMPOBJS    += j2me\vm\NEMO\j2me_nemo.lib
    	  endif
    	      
    	  ifeq ($(strip $(J2ME_VM)),NEMO_VM_SOURCE_NORMAL)
    	      ifeq ($(strip $(J2ME_SLIM_MEMORY_SUPPORT)),TRUE)
    	          COMPOBJS    += j2me\vm\NEMO\j2me_nemo_cldc_slim.lib
    	      else
                  COMPOBJS    += j2me\vm\NEMO\j2me_nemo_cldc.lib
    	      endif
   	        COMPOBJS    += j2me\vm\NEMO\j2me_nemo_fdlibm.lib

    	  endif
    endif
  
    ifeq ($(strip $(J2ME_SUPPORT)),JBLENDIA)
        ifeq ($(strip $(J2ME_VM)),KVM)
            JBLENDIA_LIB = CLDC11
        else
            JBLENDIA_LIB = CLDCHI
        endif
           
        ifeq ($(strip $(J2ME_FEATURE_SET)),JTWI)
            JBLENDIA_LIB := $(strip $(JBLENDIA_LIB))_JTWI10
        endif
        # alway with FC
        JBLENDIA_LIB := $(strip $(JBLENDIA_LIB))_FC
           
        ifeq ($(strip $(call Upper,$(SUPPORT_JSR_75_PIM))),TRUE)
            JBLENDIA_LIB := $(strip $(JBLENDIA_LIB))_PIM
        endif
        
        ifeq ($(strip $(call Upper,$(SUPPORT_JSR_205))),TRUE)
            JBLENDIA_LIB := $(strip $(JBLENDIA_LIB))_WMA20
        endif
           
        ifeq ($(strip $(call Upper,$(SUPPORT_JAVA_NOKIA_UI))),TRUE)
            JBLENDIA_LIB := $(strip $(JBLENDIA_LIB))_NUI
        endif
           
        ifeq ($(strip $(call Upper,$(SUPPORT_BACKGROUND_JAVA))),TRUE)
            JBLENDIA_LIB := $(strip $(JBLENDIA_LIB))_BGE
            COM_DEFS += J2ME_SUPPORT_BACKGROUND
        endif
           
        ifeq ($(strip $(call Upper,$(SUPPORT_JSR_82))),TRUE)
            JBLENDIA_LIB := $(strip $(JBLENDIA_LIB))_BT
        endif

        #check follow path exisit? 
        JBLENDIA_LIB_DIR = $(shell dir j2me\vm\JBlendia\lib\$(strip $(JBLENDIA_LIB)) /b 2>nul)
        ifeq ($(words $(strip $(JBLENDIA_LIB_DIR))),0)
            $(warning Aplix JAVA feature set ($(strip $(JBLENDIA_LIB))) does not exist.)
            DEPENDENCY_CONFLICT = TRUE
        endif
        
        COMPOBJS += j2me\vm\JBlendia\lib\$(strip $(JBLENDIA_LIB))\ajsc_arm_rvct.a \
                    j2me\vm\JBlendia\lib\$(strip $(JBLENDIA_LIB))\libmjb2.a \
                    j2me\vm\JBlendia\lib\$(strip $(JBLENDIA_LIB))\libaicrypto.a
            
        CUS_REL_OBJ_LIST += j2me\vm\JBlendia\lib\$(strip $(JBLENDIA_LIB))\ajsc_arm_rvct.a  \
                            j2me\vm\JBlendia\lib\$(strip $(JBLENDIA_LIB))\libmjb2.a  \
                            j2me\vm\JBlendia\lib\$(strip $(JBLENDIA_LIB))\libaicrypto.a \
                            j2me\vm\jblendia\lib\$(strip $(JBLENDIA_LIB))\ajsc_win32_msvc.lib \
                            j2me\vm\jblendia\lib\$(strip $(JBLENDIA_LIB))\libmjb2.lib \
                            j2me\vm\jblendia\lib\$(strip $(JBLENDIA_LIB))\libaicrypto.lib
    endif

    ifeq ($(strip $(J2ME_SUPPORT)),JBLENDIA_MVM)
        ifeq ($(strip $(J2ME_VM)),KVM)
            $(warning Aplix JBLENDIA_MVM can not base on KVM. Set J2ME_VM to HI_VM instead.)
        else
            JBLENDIA_LIB = CLDCHI
        endif

        ifeq ($(strip $(J2ME_FEATURE_SET)),JTWI)
            JBLENDIA_LIB := $(strip $(JBLENDIA_LIB))_JTWI10
        endif

        JBLENDIA_LIB := $(strip $(JBLENDIA_LIB))_FC
         
        ifeq ($(strip $(call Upper,$(SUPPORT_JSR_75_PIM))),TRUE)
            JBLENDIA_LIB := $(strip $(JBLENDIA_LIB))_PIM
        endif

        ifeq ($(strip $(call Upper,$(SUPPORT_JSR_205))),TRUE)
           JBLENDIA_LIB := $(strip $(JBLENDIA_LIB))_WMA20
        endif

        ifeq ($(strip $(call Upper,$(SUPPORT_JAVA_NOKIA_UI))),TRUE)
            JBLENDIA_LIB := $(strip $(JBLENDIA_LIB))_NUI
        endif

        # The term BGE for JBLENDIA_MVM means CMCC BGE.
        ifeq ($(strip $(call Upper,$(SUPPORT_BACKGROUND_JAVA))),TRUE)
            JBLENDIA_LIB := $(strip $(JBLENDIA_LIB))_BGE
            COM_DEFS += J2ME_SUPPORT_BACKGROUND
        endif

        ifeq ($(strip $(call Upper,$(SUPPORT_JSR_82))),TRUE)
            JBLENDIA_LIB := $(strip $(JBLENDIA_LIB))_BT
        endif

        # check if following path exisits
        JBLENDIA_LIB_DIR = $(shell dir j2me\vm\jblendia_mvm\lib\$(strip $(JBLENDIA_LIB)) /b 2>nul)
        ifeq ($(words $(strip $(JBLENDIA_LIB_DIR))),0)
            $(warning Aplix JAVA feature set ($(strip $(JBLENDIA_LIB))) does not exist.)
            DEPENDENCY_CONFLICT = TRUE
        endif
     
        COMPOBJS += j2me\vm\jblendia_mvm\lib\$(strip $(JBLENDIA_LIB))\ajsc_arm_ads.a \
                    j2me\vm\jblendia_mvm\lib\$(strip $(JBLENDIA_LIB))\libmjb2.a \
                    j2me\vm\jblendia_mvm\lib\$(strip $(JBLENDIA_LIB))\libaicrypto.a
            
        CUS_REL_OBJ_LIST += j2me\vm\jblendia_mvm\lib\$(strip $(JBLENDIA_LIB))\ajsc_arm_ads.a  \
                            j2me\vm\jblendia_mvm\lib\$(strip $(JBLENDIA_LIB))\libmjb2.a  \
                            j2me\vm\jblendia_mvm\lib\$(strip $(JBLENDIA_LIB))\libaicrypto.a \
                            j2me\vm\jblendia_mvm\lib\$(strip $(JBLENDIA_LIB))\ajsc_win32_msvc.lib \
                            j2me\vm\jblendia_mvm\lib\$(strip $(JBLENDIA_LIB))\libmjb2.lib \
                            j2me\vm\jblendia_mvm\lib\$(strip $(JBLENDIA_LIB))\libaicrypto.lib
    endif

    ifeq ($(strip $(J2ME_SUPPORT)),JBED)
        COMPOBJS += j2me\vm\jbed\lib\libjbedfbcc.lib
        CUS_REL_OBJ_LIST += j2me\vm\jbed\lib\libjbedfbcc.lib
    endif
endif

# *************************************************************************
# J2ME PATH SETTING
# *************************************************************************

ifdef J2ME_SUPPORT
    MMI_INCDIRS += j2me\interface
    
    ifneq ($(strip $(J2ME_SUPPORT)),NONE)
        ifeq ($(strip $(J2ME_SUPPORT)),JBLENDIA)
            MMI_INCDIRS    +=    custom\j2me\JBLENDIA\$(strip $(BOARD_VER))
        endif

        ifeq ($(strip $(J2ME_SUPPORT)),JBLENDIA_MVM)
            MMI_INCDIRS    +=    custom\j2me\JBLENDIA_MVM\$(strip $(BOARD_VER))
        endif
        
        ifeq ($(strip $(J2ME_SUPPORT)),IJET)
            ifndef FLAVOR
                MMI_INCDIRS    +=    custom\j2me\IJET\$(strip $(BOARD_VER))
            else
                ifneq ($(strip $(FLAVOR)),NONE)
                    MMI_INCDIRS    +=    custom\j2me\IJET\$(strip $(BOARD_VER))($(strip $(FLAVOR)))
                else
                    MMI_INCDIRS    +=    custom\j2me\IJET\$(strip $(BOARD_VER))
                endif
            endif
        endif
    
        ifeq ($(strip $(J2ME_SUPPORT)),JBED)
            MMI_INCDIRS    +=    custom\j2me\JBED\$(strip $(BOARD_VER))
        endif

        ifeq ($(strip $(J2ME_SUPPORT)),NEMO)
            ifndef FLAVOR
            MMI_INCDIRS    +=    custom\j2me\NEMO\$(strip $(BOARD_VER))
            else
                ifneq ($(strip $(FLAVOR)),NONE)
                    MMI_INCDIRS    +=    custom\j2me\NEMO\$(strip $(BOARD_VER))($(strip $(FLAVOR)))
                else
                    MMI_INCDIRS    +=    custom\j2me\NEMO\$(strip $(BOARD_VER))
                endif
            endif
        endif
        
        ifeq ($(strip $(J2ME_SUPPORT)),MTK_DUMMYVM)
            MMI_INCDIRS    +=    custom\j2me\DUMMY\_DEFAULT_BB
        endif
        
        ifeq ($(strip $(J2ME_SUPPORT)),MTK_DUMMY_MVM)
            MMI_INCDIRS    +=    custom\j2me\DUMMY\_DEFAULT_BB
        endif
        
    endif
endif

ifdef J2ME_SUPPORT
    ifneq ($(strip $(J2ME_SUPPORT)),NONE)
        MMI_INCDIRS += plutommi\mmi\Organizer\OrganizerInc
        MMI_INCDIRS += j2me\jal\include

        ifeq ($(strip $(J2ME_SUPPORT)),IJET)
            CUS_REL_BASE_COMP += custom\j2me\IJET\_DEFAULT_BB\builtin_game_generator \
                                 j2me\vm\IJET\adaptation
            MMI_INCDIRS += custom\j2me\IJET\_DEFAULT_BB
        endif 

        ifeq ($(strip $(J2ME_SUPPORT)),JBLENDIA)
            CUS_REL_BASE_COMP += custom\j2me\JBLENDIA\_DEFAULT_BB\jblend_preinstall
            MMI_INCDIRS += custom\j2me\JBLENDIA\_DEFAULT_BB
            MMI_INCDIRS += j2me\vm\JBlendia\include\aci j2me\vm\JBlendia\include\ksi
        endif

        ifeq ($(strip $(J2ME_SUPPORT)),JBLENDIA_MVM)
            CUS_REL_BASE_COMP += custom\j2me\JBLENDIA_MVM\_DEFAULT_BB\jblend_preinstall
            MMI_INCDIRS += custom\j2me\JBLENDIA_MVM\_DEFAULT_BB
            MMI_INCDIRS += j2me\vm\jblendia_mvm\include\aci j2me\vm\jblendia_mvm\include\ksi
        endif

        ifeq ($(strip $(J2ME_SUPPORT)),JBED)
            MMI_INCDIRS += custom\j2me\JBED\_DEFAULT_BB
        endif

        ifeq ($(strip $(J2ME_SUPPORT)),NEMO)
            CUS_REL_BASE_COMP += custom\j2me\NEMO\_DEFAULT_BB\builtin_game_generator \
                                 j2me\vm\NEMO\adaptation
            MMI_INCDIRS += custom\j2me\NEMO\_DEFAULT_BB
        endif

        ifeq ($(strip $(J2ME_SUPPORT)),MTK_DUMMYVM)
            MMI_INCDIRS += custom\j2me\DUMMY\_DEFAULT_BB
        endif
        
        ifeq ($(strip $(J2ME_SUPPORT)),MTK_DUMMY_MVM)
            MMI_INCDIRS += custom\j2me\DUMMY\_DEFAULT_BB
        endif
             
    endif
endif

# *************************************************************************
# J2ME COMPLIST AND CUS_REL CONFIG
# *************************************************************************

ifdef J2ME_SUPPORT
    ifneq ($(strip $(J2ME_SUPPORT)),NONE)
        COMPLIST    += jal
        CUS_REL_SRC_COMP += jal
        
        ifeq ($(strip $(J2ME_SUPPORT)),IJET)
            ifeq ($(strip $(J2ME_VM)),HI_VM_SOURCE)
                COMPLIST    += j2me_hi
                CUS_REL_SRC_COMP += j2me_hi
            endif
            ifeq ($(strip $(J2ME_VM)),KVM_SOURCE)
                COMPLIST    += j2me_11
                CUS_REL_SRC_COMP += j2me_11
            endif
            ifeq ($(strip $(J2ME_VM)),KVM_KDWP_SOURCE)
                COMPLIST    += j2me_11_KDWP
                CUS_REL_SRC_COMP += j2me_11_KDWP
                COM_DEFS += KDWP_DEBUG
            endif

            ifeq ($(strip $(J2ME_VM)),KVM)
              CUS_REL_OBJ_LIST  +=   j2me\vm\IJET\j2me_11.lib
            endif
        
            ifeq ($(strip $(J2ME_VM)),HI_VM)
              CUS_REL_OBJ_LIST  +=   j2me\vm\IJET\j2me_hi.lib
            endif
            
            ifeq ($(strip $(J2ME_VM)),KVM_KDWP)
              CUS_REL_OBJ_LIST  +=   j2me\vm\IJET\j2me_11_KDWP.lib
              COM_DEFS += KDWP_DEBUG
            endif
        endif
    
    
        ifeq ($(strip $(J2ME_SUPPORT)),IJET)
            COMPLIST    += ijet_adp
            CUS_REL_SRC_COMP += ijet_adp
        endif

        ifeq ($(strip $(J2ME_SUPPORT)),JBLENDIA)
            COMPLIST    += jblendia
            CUS_REL_SRC_COMP    += jblendia
        endif

        ifeq ($(strip $(J2ME_SUPPORT)),JBLENDIA_MVM)
            COMPLIST    += jblendia_mvm
            CUS_REL_SRC_COMP    += jblendia_mvm
        endif
        
        ifeq ($(strip $(J2ME_SUPPORT)),JBED)
            COMPLIST += jbed
            CUS_REL_SRC_COMP += jbed
        endif    

        ifeq ($(strip $(J2ME_SUPPORT)),NEMO)
            COMPLIST    += nemo_adp
            CUS_REL_SRC_COMP += nemo_adp        
            ifeq ($(strip $(J2ME_VM)),NEMO_VM_SOURCE_FULL)
                ifeq ($(strip $(J2ME_SLIM_MEMORY_SUPPORT)),TRUE)
                    COMPLIST    += j2me_nemo_cldc_slim j2me_nemo
                    CUS_REL_SRC_COMP += j2me_nemo_cldc_slim j2me_nemo
                else
                    COMPLIST    += j2me_nemo_cldc j2me_nemo
                    CUS_REL_SRC_COMP += j2me_nemo_cldc j2me_nemo
                endif
                COMPLIST    += j2me_nemo_fdlibm
                CUS_REL_SRC_COMP += j2me_nemo_fdlibm

            endif
            ifeq ($(strip $(J2ME_VM)),NEMO_VM_SOURCE_NORMAL)
                COMPLIST    += j2me_nemo
                CUS_REL_SRC_COMP += j2me_nemo
                ifeq ($(strip $(J2ME_SLIM_MEMORY_SUPPORT)),TRUE)
                    CUS_REL_OBJ_LIST  +=   j2me\vm\NEMO\j2me_nemo_cldc_slim.lib
                else
                    CUS_REL_OBJ_LIST  +=   j2me\vm\NEMO\j2me_nemo_cldc.lib
                endif
                CUS_REL_OBJ_LIST  +=   j2me\vm\NEMO\j2me_nemo_fdlibm.lib

            endif
            ifeq ($(strip $(J2ME_VM)),NEMO_VM)
                ifeq ($(strip $(J2ME_SLIM_MEMORY_SUPPORT)),TRUE)
                    CUS_REL_OBJ_LIST  +=   j2me\vm\NEMO\j2me_nemo_cldc_slim.lib
                else
                    CUS_REL_OBJ_LIST  +=   j2me\vm\NEMO\j2me_nemo_cldc.lib
                endif
                CUS_REL_OBJ_LIST  +=   j2me\vm\NEMO\j2me_nemo.lib
                CUS_REL_OBJ_LIST  +=   j2me\vm\NEMO\j2me_nemo_fdlibm.lib

            endif
        endif
       
        ifeq ($(strip $(J2ME_SUPPORT)),MTK_DUMMYVM)
            COMPLIST    += jdummy
            CUS_REL_SRC_COMP += jdummy
        endif

        ifeq ($(strip $(J2ME_SUPPORT)),MTK_DUMMY_MVM)
            COMPLIST    += jdummy
            CUS_REL_SRC_COMP += jdummy
        endif

        ifneq ($(filter MT6223P MT6223, $(PLATFORM)),)
          COMPLIST         += jal_sec
          CUS_REL_MTK_COMP += jal_sec
        endif
    endif 
endif

# *************************************************************************
# J2ME Dependency rules
# *************************************************************************
ifdef J2ME_SUPPORT
    ifeq ($(strip $(J2ME_SUPPORT)),IJET)
        J2ME_VM_SUPPORT_ITEM = KVM KVM_SOURCE HI_VM HI_VM_SOURCE 
        ifeq ($(filter $(strip $(J2ME_VM)),$(J2ME_VM_SUPPORT_ITEM)),)
            $(call DEP_ERR_SETA_OR_SETB,J2ME_VM,non $(strip $(J2ME_VM)),J2ME_SUPPORT,non $(strip $(J2ME_SUPPORT)))
            DEPENDENCY_CONFLICT = TRUE
        endif
    endif
    ifeq ($(strip $(J2ME_SUPPORT)),NEMO)
        J2ME_VM_SUPPORT_ITEM = NEMO_VM NEMO_VM_SOURCE_NORMAL NEMO_VM_SOURCE_FULL
        ifeq ($(filter $(strip $(J2ME_VM)),$(J2ME_VM_SUPPORT_ITEM)),)
            $(call DEP_ERR_SETA_OR_SETB,J2ME_VM,non $(strip $(J2ME_VM)),J2ME_SUPPORT,non $(strip $(J2ME_SUPPORT)))
        endif
    endif    
    ifeq ($(strip $(J2ME_SUPPORT)),JBLENDIA)
        J2ME_VM_SUPPORT_ITEM = KVM HI_VM 
        ifeq ($(filter $(strip $(J2ME_VM)),$(J2ME_VM_SUPPORT_ITEM)),)
            $(call DEP_ERR_SETA_OR_SETB,J2ME_VM,non $(strip $(J2ME_VM)),J2ME_SUPPORT,non $(strip $(J2ME_SUPPORT)))
            DEPENDENCY_CONFLICT = TRUE
        endif
        ifneq ($(strip $(J2ME_FEATURE_SET)),JTWI)
            $(call DEP_ERR_SETA_OR_SETB,J2ME_FEATURE_SET,JTWI,J2ME_SUPPORT,non $(strip $(J2ME_SUPPORT)))
            DEPENDENCY_CONFLICT = TRUE
        endif
        ifeq ($(strip $(DRM_SUPPORT)),BSCI)
            $(call DEP_ERR_SETA_OR_SETB,DRM_SUPPORT,non $(strip $(DRM_SUPPORT)),J2ME_SUPPORT,non $(strip $(J2ME_SUPPORT)))
            DEPENDENCY_CONFLICT = TRUE
        endif
    endif
    ifeq ($(strip $(J2ME_SUPPORT)),JBLENDIA_MVM)
        J2ME_VM_SUPPORT_ITEM = KVM HI_VM 
        ifeq ($(filter $(strip $(J2ME_VM)) ,$(J2ME_VM_SUPPORT_ITEM)),)
            $(call DEP_ERR_SETA_OR_SETB,J2ME_VM,non $(strip $(J2ME_VM)),J2ME_SUPPORT,non $(strip $(J2ME_SUPPORT)))
            DEPENDENCY_CONFLICT = TRUE
        endif
        ifneq ($(strip $(J2ME_FEATURE_SET)),JTWI)
            $(call DEP_ERR_SETA_OR_SETB,J2ME_FEATURE_SET,JTWI,J2ME_SUPPORT,non $(strip $(J2ME_SUPPORT)))
            DEPENDENCY_CONFLICT = TRUE
        endif
        ifeq ($(strip $(DRM_SUPPORT)),BSCI)
            $(call DEP_ERR_SETA_OR_SETB,DRM_SUPPORT,non $(strip $(DRM_SUPPORT)),J2ME_SUPPORT,non $(strip $(J2ME_SUPPORT)))
            DEPENDENCY_CONFLICT = TRUE
        endif
    endif
    ifeq ($(strip $(J2ME_SUPPORT)),JBED)
        J2ME_VM_SUPPORT_ITEM = KVM  
        ifeq ($(filter $(strip $(J2ME_VM)) ,$(J2ME_VM_SUPPORT_ITEM)),)
            $(call DEP_ERR_SETA_OR_SETB,J2ME_VM,non $(strip $(J2ME_VM)),J2ME_SUPPORT,non $(strip $(J2ME_SUPPORT)))
            DEPENDENCY_CONFLICT = TRUE
        endif
    endif
    ifneq ($(strip $(J2ME_SUPPORT)),NONE)
        ifdef J2ME_FEATURE_SET
            ifeq ($(strip $(J2ME_FEATURE_SET)),NONE)
                $(call DEP_ERR_ONA_OR_OFFB,J2ME_FEATURE_SET,J2ME_SUPPORT)
                DEPENDENCY_CONFLICT = TRUE
            endif
        endif
    endif
endif

ifdef SUPPORT_JAVA_NOKIA_UI
    ifeq ($(strip $(SUPPORT_JAVA_NOKIA_UI)),TRUE)
        ifeq ($(strip $(J2ME_SUPPORT)),JBLENDIA)
            ifneq ($(strip $(SUPPORT_JSR_75_PIM)),TRUE)
                $(call DEP_ERR_ONA_OR_OFFB,SUPPORT_JSR_75_PIM,SUPPORT_JAVA_NOKIA_UI)
                DEPENDENCY_CONFLICT = TRUE
            endif
            ifneq ($(strip $(J2ME_FEATURE_SET)),JTWI)
                $(call DEP_ERR_SETA_OR_OFFB,J2ME_FEATURE_SET,JTWI,SUPPORT_JAVA_NOKIA_UI)
                DEPENDENCY_CONFLICT = TRUE
            endif
        endif
        ifeq ($(strip $(J2ME_SUPPORT)),JBLENDIA_MVM)
            ifneq ($(strip $(SUPPORT_JSR_75_PIM)),TRUE)
                $(call DEP_ERR_ONA_OR_OFFB,SUPPORT_JSR_75_PIM,SUPPORT_JAVA_NOKIA_UI)
                DEPENDENCY_CONFLICT = TRUE
            endif
            ifneq ($(strip $(J2ME_FEATURE_SET)),JTWI)
                $(call DEP_ERR_SETA_OR_OFFB,J2ME_FEATURE_SET,JTWI,SUPPORT_JAVA_NOKIA_UI)
                DEPENDENCY_CONFLICT = TRUE
            endif
        endif       
        ifeq ($(strip $(J2ME_SUPPORT)),NONE)
            $(call DEP_ERR_ONA_OR_OFFB,J2ME_SUPPORT,SUPPORT_JAVA_NOKIA_UI)
            DEPENDENCY_CONFLICT = TRUE
        endif
    endif
endif

ifdef SUPPORT_JSR_179
    ifeq ($(strip $(call Upper,$(SUPPORT_JSR_179))),TRUE)
        ifneq ($(strip $(J2ME_SUPPORT)),IJET)
            $(call DEP_ERR_SETA_OR_OFFB,J2ME_SUPPORT,IJET,SUPPORT_JSR_179)
            DEPENDENCY_CONFLICT = TRUE
        endif
        ifneq ($(strip $(J2ME_FEATURE_SET)),JTWI)
            $(call DEP_ERR_SETA_OR_OFFB,J2ME_FEATURE_SET,JTWI,SUPPORT_JSR_179)
            DEPENDENCY_CONFLICT = TRUE
        endif
        ifeq ($(strip $(J2ME_SUPPORT)),NONE)
            $(call DEP_ERR_ONA_OR_OFFB,J2ME_SUPPORT,SUPPORT_JSR_179)
            DEPENDENCY_CONFLICT = TRUE
        endif
        ifndef J2ME_SUPPORT
            $(call DEP_ERR_ONA_OR_OFFB,J2ME_SUPPORT,SUPPORT_JSR_179)
            DEPENDENCY_CONFLICT = TRUE
        endif
    endif
endif

ifdef J2ME_MAX_LAUNCH_NUM
  ifeq ($(call gt,$(strip $(J2ME_MAX_LAUNCH_NUM)),1),T)
    ifdef SUPPORT_BACKGROUND_JAVA
      ifneq ($(strip $(SUPPORT_BACKGROUND_JAVA)),TRUE)
        $(warning ERROR: Please set SUPPORT_BACKGROUND_JAVA as TRUE when J2ME_MAX_LAUNCH_NUM is greater than 1!)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

ifdef J2ME_SLIM_MEMORY_SUPPORT
  ifeq ($(strip $(J2ME_SLIM_MEMORY_SUPPORT)),TRUE)

    ifneq ($(strip $(IMAGE_VIEWER_VER)),SLIM)
      $(call DEP_ERR_SETA_OR_OFFB,IMAGE_VIEWER_VER,SLIM,J2ME_SLIM_MEMORY_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif

    ifeq ($(strip $(J2ME_SUPPORT)),JBLENDIA)
      $(call DEP_ERR_SETA_OR_OFFB,J2ME_SUPPORT,non JBLENDIA,J2ME_SLIM_MEMORY_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif


    COM_DEFS += J2ME_SLIM_MEMORY_SUPPORT J2ME_SHARE_MED_EXT_MEM J2ME_SLIM_SCREEN_MEMORY_SUPPORT

  endif
endif

ifdef J2ME_SUPPORT
  ifneq ($(strip $(J2ME_SUPPORT)),NONE)
    ifeq ($(strip $(call Upper,$(SUPPORT_BACKGROUND_JAVA))),TRUE)
      COM_DEFS += J2ME_SUPPORT_BACKGROUND
    endif
  endif
endif