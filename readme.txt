**************************************************
###           modem source mt6592 LP           ###
**************************************************


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

	#   run => perl ALPS/device/mediatek/build/build/tools/modemRenameCopy.pl ~/HSPA_MOLY.WR8.W1449.MD.WG.MP.V16 "RATECH92_RGK_L_HSPA"

