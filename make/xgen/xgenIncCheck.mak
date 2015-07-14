Upper = $(subst z,Z,$(subst y,Y,$(subst x,X,$(subst w,W,$(subst v,V,$(subst u,U,$(subst t,T,$(subst s,S,$(subst r,R,$(subst q,Q,$(subst p,P,$(subst o,O,$(subst n,N,$(subst m,M,$(subst l,L,$(subst k,K,$(subst j,J,$(subst i,I,$(subst h,H,$(subst g,G,$(subst f,F,$(subst e,E,$(subst d,D,$(subst c,C,$(subst b,B,$(subst a,A,$(1)))))))))))))))))))))))))))

-include make/folderlist.bld
include make/cmd_cfg.mak

CheckPCIBT = \
$(strip \
  $(foreach \
    inc,\
    $(filter-out $(call Upper,custom/%) $(call Upper,$(strip $(BUILDDIR))/%) $(call Upper,build/%),$(call Upper,$(subst \,/,$(1)))),\
    $(if \
      $(filter $(patsubst %/,%,$(dir $(subst \,/,$(inc)))),$(call Upper,$(subst \,/,$(FOLDERLIST)))),\
      ,\
      $(subst \,/,$(inc))\
    )\
  )\
)

.PHONY: $(DEP_FILE)

include $(DEP_FILE)
$(DEP_FILE):
	@$(IF_NOT) $(words $(call CheckPCIBT,$^)) == 0 $(THEN) \
	( \
		(echo Error: The following file in $(DEP_FILE) cannot be found in subsidiary perforce: $(call CheckPCIBT,$^) >> $(LOG)) $(AND) \
		(echo It will let subsidiary get build errors. Please do not use these source files or not include these header files, or move these files to permission-opened folders >> $(LOG)) $(AND) \
		(echo Please check $(LOG) for xgen include path permission check in build time [PCIBT]) $(AND) \
		(exit 1)\
	) \
	$(ELSE) \
	( \
		echo [PCIBT] pass! \
	) $(CMD_END)
