### intermediate make file for XGC

# *************************************************************************
# Set PHONY
# *************************************************************************
.PHONY : ALL 

# *************************************************************************
# Common macro definitions
# *************************************************************************
#$(call Upper,$(1)) ...... reference $(1) in upper-case letters
Upper = $(subst z,Z,$(subst y,Y,$(subst x,X,$(subst w,W,$(subst v,V,$(subst u,U,$(subst t,T,$(subst s,S,$(subst r,R,$(subst q,Q,$(subst p,P,$(subst o,O,$(subst n,N,$(subst m,M,$(subst l,L,$(subst k,K,$(subst j,J,$(subst i,I,$(subst h,H,$(subst g,G,$(subst f,F,$(subst e,E,$(subst d,D,$(subst c,C,$(subst b,B,$(subst a,A,$(1)))))))))))))))))))))))))))

# *************************************************************************
#  Include scripts
# *************************************************************************
include make\buildConfig.mak
include $(strip $(TMPDIR))\~compbld.tmp            # Temporary build script created by build.mak
include $(strip $(TMPDIR))\complib.txt
-include $(strip $(TMPDIR))\app_cfg.mak
include $(strip $(TMPDIR))\~buildinfo.tmp


ALL: $(COMPLIBLIST)

%.lib:
	@perl tools\time.pl
	@echo  LOG: $(strip $(COMPLOGDIR))\$*.log
	@if not exist $(strip $(OBJSDIR))\$* md $(strip $(OBJSDIR))\$*
	@if not exist $(strip $(TARGDIR))\log\$* md $(strip $(TARGDIR))\log\$*
	@if $(ACTION)==new if exist $(strip $(RULESDIR))\$*.dep del /q /f $(strip $(RULESDIR))\$*.dep
	@if $(ACTION)==bm_new if exist $(strip $(RULESDIR))\$*.dep del /q /f $(strip $(RULESDIR))\$*.dep
	@if not $(ACTION)==remake if not exist $(strip $(RULESDIR))\$*_dep md $(strip $(RULESDIR))\$*_dep
	@if $(ACTION)==new if exist $(strip $(RULESDIR))\$*_dep\*.det del /f /q $(strip $(RULESDIR))\$*_dep\*.det
	@if $(ACTION)==bm_new if exist $(strip $(RULESDIR))\$*_dep\*.det del /f /q $(strip $(RULESDIR))\$*_dep\*.det
	
	@(tools\make.exe -fmake\comp.mak -k -r -R $(strip $(CMD_ARGU)) TMPDIR=$(strip $(TMPDIR)) COMPONENT=$* setup_env > $(strip $(COMPLOGDIR))\$*_setEnv.log 2>&1)
	
ifneq ($(strip $(BM_NEW)),TRUE)
ifeq ($(call Upper,$(strip $(OS))),WINDOWS_NT)
	@(tools\make.exe  -fmake\comp.mak  -r -R $(strip $(CMD_ARGU)) TMPDIR=$(strip $(TMPDIR)) COMPONENT=$* update_lib > $(strip $(COMPLOGDIR))\$*.log 2>&1) & \
			(if ERRORLEVEL 1 \
			  (perl tools\get_log.pl $(strip $(COMPLOGDIR))\$*.log $(strip $(COMPLOGDIR))\$* tools\copy_mmi_include_h.bat) & \
			  (if exist $(strip $(COMPLOGDIR))\$* rd /S /Q $(strip $(COMPLOGDIR))\$*) & \
			  (exit 1) \
			else \
			  (perl tools\get_log.pl $(strip $(COMPLOGDIR))\$*.log $(strip $(COMPLOGDIR))\$*) & \
			  (if exist $(strip $(COMPLOGDIR))\$* rd /S /Q $(strip $(COMPLOGDIR))\$*) \
			) 
else
	@echo OS NOT EQ WINDOWS_NT
	tools\make.exe  -fmake\comp.mak  -r -R $(strip $(CMD_ARGU)) TMPDIR=$(strip $(TMPDIR)) COMPONENT=$* update_lib > $(strip $(COMPLOGDIR))\$*.log 2>&1
endif	
else
ifeq ($(call Upper,$(strip $(OS))),WINDOWS_NT)
	@(tools\make.exe  -fmake\comp.mak  -k -r -R $(strip $(CMD_ARGU)) TMPDIR=$(strip $(TMPDIR)) COMPONENT=$* update_lib > $(strip $(COMPLOGDIR))\$*.log 2>&1) & \
			(if ERRORLEVEL 1 \
			  (perl tools\get_log.pl $(strip $(COMPLOGDIR))\$*.log $(strip $(COMPLOGDIR))\$* tools\copy_mmi_include_h.bat) & \
			  (if exist $(strip $(COMPLOGDIR))\$* rd /S /Q $(strip $(COMPLOGDIR))\$*) & \
			  (exit 1) \
			else \
			  (perl tools\get_log.pl $(strip $(COMPLOGDIR))\$*.log $(strip $(COMPLOGDIR))\$*) & \
			  (if exist $(strip $(COMPLOGDIR))\$*  rd /S /Q $(strip $(COMPLOGDIR))\$*) \
			) 	
else
	tools\make.exe  -fmake\comp.mak  -k -r -R $(strip $(CMD_ARGU)) TMPDIR=$(strip $(TMPDIR)) COMPONENT=$* update_lib > $(strip $(COMPLOGDIR))\$*.log 2>&1
endif	
endif	
