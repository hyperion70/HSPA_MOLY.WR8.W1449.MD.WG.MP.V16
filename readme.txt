***********************************************
###           modem source mt6592           ###
***********************************************


###	recommended Build Environment
***********************************************
* [OS]        : Linux
* [PERL]      : v5.10.1 or v5.14.2
* [MAKE]      : GNU Make v3.81
* [SHELL]     : GNU bash v4.1.5
* [COMPILER]  : v4.6.2 or above
***********************************************


###	Building modem.img

cd HSPA_MOLY.WR8.W1449.MD.WG.MP.V16
./make.sh RATECH92_RGK_L_HSPA.mak new


###	Rename

build/[project]/DEFAULT/tst/database/catcher_filter.bin ==>>  catcher_filter_1_wg_n.bin
build/[project]/DEFAULT/tst/database/BPLGUInfoXXXXXX ==>>  BPLGUInfoXXXXXX_1_wg_n

build/[project]/DEFAULT/bin/XXX_PCB01_XXX.elf ==>> [project]_PCB01_XXX_1_wg_n.elf
build/[project]/DEFAULT/bin/DbgInfoXXXX ==>>  DbgInfoXXXX_1_wg_n
build/[project]/DEFAULT/bin/[project]_PCB01_XXX.bin ==>>  modem_1_wg_n.img
build/[project]/DEFAULT/bin/[project].mak ==>>  modem_1_wg_n.mak





