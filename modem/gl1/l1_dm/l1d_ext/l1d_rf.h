/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 *
 * Filename:
 * ---------
 *   l1d_rf.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   RF constance defintion
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Revision:   1.65  $
 * $Modtime:   Jul 29 2005 13:42:20  $
 * $Log:   //mtkvs01/vmdata/Maui_sw/archives/mcu/l1/l1d/l1d_rf.h-arc  $
 *
 * 04 21 2015 hosen.chen
 * [MOLY00108553] [L1D][Modify] Rainier E2 initail EVM issue solution
 * 	.
 *
 * 03 19 2015 hosen.chen
 * [MOLY00099724] [L1D][Modify]Check in Rainier RF driver SW workaround for EPSK TX EVM issue
 * 	.
 *
 * 03 03 2015 hosen.chen
 * [MOLY00094981] [L1D][Modify] Check in MT6580/Rainier RF driver
 * 	Rainier RF driver merge back to WR8 MP branch.
 *
 * 03 03 2015 sherman.chung
 * [MOLY00088188] [MT6580][L1D] MT6580 BringUp L1D L1D_RF Driver Check In
 * .
 *
 * 09 16 2013 ola.lee
 * [MOLY00037846] [MT6571][MOLY NOT NEED][Volunteer Patch] Update MT6571 Bring Up Setting and W Cancellation.
 *
 * 08 22 2013 vend_cuthbert.kao
 * [MOLY00034524] [MT6592][MT6571][L1D][Modify] MT6592 BB Driver + MT6571 BB Driver + MT6165 RF Driver integration
 * .
 *
 * 06 21 2013 ola.lee
 * [MOLY00026973] [Volunteer Patch][Fix AFC] Enable Clock buffer 2 when GPS Co-Clock
 * .
 *
 * 05 16 2013 ola.lee
 * [MOLY00022914] [Volunteer Patch][MT6572/MT6582] Improve MT6572/MT6582 Timing Advance Margin
 * .
 *
 * 05 14 2013 sean.yang
 * [MOLY00022263] [Volunteer Patch] [MT6572/6582] Common Modem Image feature patch
 * .
 *
 * 05 02 2013 ola.lee
 * [MOLY00021313] [MT6572/MT6582] Enable IS_DYNAMIC_G_E_TXWIN_POSITION_SUPPORT_V2 for MT6572/MT6582
 * .
 *
 * 04 01 2013 yi-ying.lin
 * [MOLY00013319] [L1D][Modify] Fix 2G/TDD RF conflict and change TDD/2G RF power check flow
 * .
 *
 * 02 27 2013 yi-ying.lin
 * [MOLY00010384] [L1D][Modify][MT6572 Bring-up] MT6166 RF driver development
 * .
 *
 * 02 19 2013 yi-ying.lin
 * [MOLY00010384] [L1D][Modify][MT6572 Bring-up] MT6166 RF driver development
 * .
 *
 * 01 29 2013 yi-ying.lin
 * [MOLY00009540] [L1D][Modify] MT6166 RF driver development
 * .
 *
 * 01 29 2013 sean.yang
 * [MOLY00009515] [L1D][Modify] Check-in MT6572/MT6582 codes
 * .
 *
 * 01 22 2013 ola.lee
 * [MOLY00009108] Allow MT6168 VRF switching between VRF28_1 & VRF28_2
 * .
 *
 * 12 27 2012 yi-ying.lin
 * [MOLY00007941] [MT6280][check-in request] Set STX_DEM_Chunk[6:0] to 1111_1110 prevent overflow during settling
 * .
 *
 * 12 25 2012 yuyang.hsiao
 * [MOLY00007957] [L1D][Modify] custom folder update APC compensate parameter on MBC tool
 * .
 *
 * 11 02 2012 yi-ying.lin
 * [MOLY00005700] [L1D][Modify] MT6280 E2 RF driver development
 * .
 *
 * 11 01 2012 ola.lee
 * [MOLY00005004] [L1D][Modify] Modify MT6589/MT6167 Codes.
 * .
 *
 * 10 26 2012 sean.yang
 * [MOLY00005394] [L1D][Modify] Turn on GCMachine on OthelloT
 * .
 *
 * 10 25 2012 ola.lee
 * [MOLY00005004] [L1D][Modify] Modify MT6589/MT6167 Codes.
 * .
 *
 * 10 18 2012 ola.lee
 * [MOLY00005004] [L1D][Modify] Modify MT6589/MT6167 Codes.
 * .
 *
 * 09 27 2012 sean.yang
 * [MOLY00003719] [L1D][Modify] Update the MT6583 codes
 * .
 *
 * 09 25 2012 ola.lee
 * [MOLY00004094] [L1D][Modify] Check-in MT6583/MT6167 Codes
 * [L1D][Modify] Check-in MT6583/MT6167 Codes.
 *
 * 09 22 2012 yi-ying.lin
 * [MOLY00003788] [L1D][Modify] MT6280 E2 RF driver development
 * .
 *
 * 09 20 2012 yi-ying.lin
 * [MOLY00003788] [L1D][Modify] MT6280 E2 RF driver development
 * .
 *
 * 09 18 2012 sean.yang
 * [MOLY00003719] [L1D][Modify] Update the MT6583 codes
 * .
 *
 * 09 17 2012 ola.lee
 * [MOLY00002567] [L1D][Modify] Check-in MT6583/MT6167 Codes
 * .
 *
 * 09 06 2012 yuyang.hsiao
 * [MOLY00003161] [L1D][Modify] Change the DCXO CLK_SETTLE_DEFAULT value
 * .
 *
 * 09 04 2012 sean.yang
 * [MOLY00002460] [L1D][Modify] Check-in MT6583 codes
 * .
 *
 * 08 27 2012 yuyang.hsiao
 * [MOLY00002684] [L1D][Modify] MT6280 E2 RF driver development
 * .
 *
 * 08 23 2012 ola.lee
 * [MOLY00002567] [L1D][Modify] Check-in MT6583/MT6167 Codes
 * .
 *
 * 08 21 2012 sean.yang
 * [MOLY00002460] [L1D][Modify] Check-in MT6583 codes
 * .
 *
 * 07 02 2012 samuel.yang
 * [MOLY00000210] [L1D][Modify] Remove the include path of "m12197.h include l1_rf.h" for MSBB2 modification
 * .
 *
 * 06 22 2012 samuel.yang
 * removed!
 * .
 *
 * 06 19 2012 yi-ying.lin
 * removed!
 * .
 *
 * 06 19 2012 yuyang.hsiao
 * removed!
 * .
 *
 * 06 14 2012 samuel.yang
 * removed!
 * .
 *
 * 05 14 2012 weining.chien
 * removed!
 * .
 *
 * 05 11 2012 chang-kuan.lin
 * removed!
 * .
 *
 * 05 10 2012 yuyang.hsiao
 * removed!
 * .
 *
 * 03 29 2012 samuel.yang
 * removed!
 * .
 *
 * 03 15 2012 yuyang.hsiao
 * removed!
 * .
 *
 * 12 09 2011 weining.chien
 * removed!
 * .
 *
 * 11 17 2011 chang-kuan.lin
 * removed!
 * .
 *
 * 11 08 2011 jason.lai
 * removed!
 * .
 *
 * 10 21 2011 th.yeh
 * removed!
 * .
 *
 * 09 22 2011 th.yeh
 * removed!
 * .
 *
 * 08 18 2011 chang-kuan.lin
 * removed!
 * .
 *
 * 08 10 2011 sean.yang
 * removed!
 * .
 *
 * 08 02 2011 samuel.yang
 * removed!
 * .
 *
 * 07 08 2011 weining.chien
 * removed!
 * .
 *
 * 06 18 2011 victo.chen
 * removed!
 * .
 *
 * 05 10 2011 sean.yang
 * removed!
 * .
 *
 * 04 20 2011 cs.wu
 * removed!
 * .
 *
 * 04 15 2011 weining.chien
 * removed!
 * .
 *
 * 04 15 2011 victo.chen
 * removed!
 * .
 *
 * 04 14 2011 sean.yang
 * removed!
 * .
 *
 * 03 28 2011 sean.yang
 * removed!
 * .
 *
 * 03 22 2011 jason.lai
 * removed!
 * .
 *
 * 03 16 2011 sean.yang
 * removed!
 * .
 *
 * 03 11 2011 sean.yang
 * removed!
 * .
 *
 * 03 08 2011 jason.lai
 * removed!
 * Check in PLL reset.
 *
 * 01 26 2011 sean.yang
 * removed!
 * .
 *
 * 01 19 2011 chuwei.lo
 * removed!
 * .
 *
 * 01 16 2011 chuwei.lo
 * removed!
 * .
 *
 * 01 05 2011 chuwei.lo
 * removed!
 * .
 *
 * 01 04 2011 sean.yang
 * removed!
 * .
 *
 * 01 04 2011 sean.yang
 * removed!
 * .
 *
 * 12 14 2010 jason.lai
 * removed!
 * .
 *
 * 12 08 2010 chuwei.lo
 * removed!
 * .
 *
 * 12 03 2010 sean.yang
 * removed!
 * .
 *
 * 12 01 2010 yr.chiang
 * removed!
 * .
 *
 * 11 24 2010 sean.yang
 * removed!
 * .
 *
 * 11 19 2010 yr.chiang
 * removed!
 * .
 *
 * 11 10 2010 yr.chiang
 * removed!
 * .
 *
 * 11 09 2010 max.weng
 * removed!
 * .
 *
 * 11 03 2010 samuel.yang
 * removed!
 * .
 *
 * 10 22 2010 jason.lai
 * removed!
 * .
 *
 * 09 21 2010 yr.chiang
 * removed!
 * .
 *
 * 09 15 2010 chang-kuan.lin
 * removed!
 * .
 *
 * 09 09 2010 samuel.yang
 * removed!
 * .
 *
 * 08 21 2010 yr.chiang
 * removed!
 * .
 *
 * 08 20 2010 samuel.yang
 * removed!
 * .
 *
 * 08 10 2010 jason.lai
 * removed!
 * .
 *
 * 08 07 2010 samuel.yang
 * removed!
 * .
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * Merge MT6251 DVT branch back to MAUI
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * Revise code
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * Modify for AD6546 RF Driver
 *
 * removed!
 * removed!
 * Sync l1_dm & l1 code for non-WCDMA part
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * PR2M will automatically copy the last BPI event (PR2 or PR2B) before RX window if it is not defined
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * BSI clock setting:
 *
 * The external clock is changed from 52MHz to 26MHz.
 * Add new compile option BSI_CLK_SPD to configure BSI_CON"
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * Add RF driver of IRFS3001
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * Add the compile option for MT6230
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * deliver MAUI_00174200 on 2006/2/27 ¤U¤È 05:12:46.
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *    Rev 1.65   Jul 29 2005 14:00:34   mtk00773
 * [L1D][Enhence] Support RF SKY74117
 * Resolution for 12111: [L1D][Enhence] Support RF SKY74117
 *
 *    Rev 1.64   Jul 08 2005 16:53:02   mtk00939
 * [L1D][Modify]L1D add code for MT6139C and META related code
 *
 *    Rev 1.63   May 17 2005 00:34:20   BM_Trunk
 * Karlos:
 * add copyright and disclaimer statement
 *
 *    Rev 1.62   May 16 2005 11:46:24   mtk00240
 * Support 22 BPI setting & current sense PA
 * Resolution for 11091: [L1D][New Feature] Support 22 BPI setting & current sense PA
 *
 *    Rev 1.61   Jan 18 2005 00:37:58   BM
 * append new line in W05.04
 *
 *    Rev 1.60   Oct 29 2004 12:44:56   mtk00240
 * Open interface to get battery voltage & temperature in m12190
 * Resolution for 7034: [L1D][Add feature] Open PCL & PathLoss compensation function for customer.
 *
 *    Rev 1.59   Jul 30 2004 17:37:06   mtk00240
 * L1D add code to support AERO1Plus RF chip
 * Resolution for 6925: [L1D][Enhance] L1D add code to support AERO1Plus RF chip
 *
 *    Rev 1.58   Jul 05 2004 15:48:20   mtk00773
 * Add RF POLARIS1 setting
 *
 *    Rev 1.57   May 31 2004 11:52:12   mtk00585
 * [L1D][Modify] Add TX Swing Auto Calibration.
 * Resolution for 5743: [L1D][Modify] Add TX Swing Auto Calibration.
 *
 *    Rev 1.56   May 21 2004 19:01:58   mtk00240
 * Add code to support MT6129D
 * Resolution for 5565: [L1D][Add Feature] Add code to support MT6129D
 *
 *    Rev 1.55   May 21 2004 14:53:30   mtk00240
 * Support mt6218B_FN & mt6129_BV chip (Also remove BFE seting from customer config)
 * Resolution for 5550: [L1D][Enahnce] Support mt6218B_FN & mt6129_BV chip (Also remove BFE seting from customer config)
 *
 *    Rev 1.54   Feb 13 2004 23:53:10   mtk00489
 * [L1D][Enhanced]1.adjust L1D DL DTX threshold to improve DTX detection rate 2.enhanced Dummy burst detection rate 3.change RX ADC to 2.24V for MT61xx 4.modify LP2 code to pass MT6218BECO3 validation 5.modify new interface for dll(CHIP_VER)
 * Resolution for 3912: [L1D][Enhanced]1.adjust L1D DL DTX threshold to improve DTX detection rate 2.enhanced Dummy burst detection rate 3.change RX ADC to 2.24V for MT61xx 4.modify LP2 code to pass MT6218BECO3 validation 5.modify new interface for dll(CHIP_VER)
 *
 *    Rev 1.53   Jan 27 2004 15:33:12   mtk00585
 * [L1D][Add] L1D Add code for MT6129C RF Driver.
 *
 *    Rev 1.52   Jan 12 2004 17:31:56   mtk00585
 * [L1D][Modify] In order of solving MT6119 synthesizer out of lock problem, we send Warm Up command before Set PLL command.
 * Resolution for 3724: [L1D][Modify] In order of solving MT6119 synthesizer out of lock problem, we send Warm Up command before Set PLL command.
 *
 *    Rev 1.51   Oct 23 2003 14:20:54   mtk00585
 * [L1D][Add] L1D Add code for MT6129B RF Driver.
 * Resolution for 3177: [L1D][Add] L1D Add code for MT6129B RF Driver.
 *
 *    Rev 1.50   Jul 11 2003 17:41:30   mtk00489
 * [L1D][Enhanced]L1D supports MT6129A
 * Resolution for 2241: [L1D][Enhanced]L1D supports MT6129A
 *
 *    Rev 1.49   Jun 06 2003 18:42:46   mtk00489
 * [L1D][Enhanced]L1D modify for custom folder/files. from now on, L1D only knows the RF chip name(not board name) 1.add l1d_custom_rf.h(from l1d_rf.h) 2.add 12196.c(from 12190.c) 3.move m12193.c to custom directory 4.modify l1s.lis 5.files include l1d_rf.h should also include l1d_custom_rf.h 6.change l1d_cid.h
 * Resolution for 1961: [L1D][Enhanced]L1D modify for custom folder/files. from now on, L1D only knows the RF chip name(not board name) 1.add l1d_custom_rf.h(from l1d_rf.h) 2.add 12196.c(from 12190.c) 3.move m12193.c to custom directory 4.modify l1s.lis 5.files
 *
 *    Rev 1.48   May 16 2003 13:09:22   mtk00489
 * [L1D][New Feature]L1D supports MT6119C
 * Resolution for 1794: [L1D][New Feature]L1D supports MT6119C
 *
 *    Rev 1.47   May 13 2003 11:26:46   mtk00489
 * [L1D][Enhanced]L1D shorten BRIGHT4's QB_PT1 timing to 149 (from 233) because QB_PT1 should not before QB_ST1 in l1 simulation.
 * Resolution for 1785: [L1D][Enhanced]L1D shorten BRIGHT4's QB_PT1 timing to 149 (from 233) because QB_PT1 should not before QB_ST1 in l1 simulation.
 *
 *    Rev 1.46   May 08 2003 10:21:10   mtk00489
 * [L1D][FixBug]After setting gain(SR2), MT6119 needs RF input for gain settling. For GSM/DCS band, there always exist RF input. But for PCS band, we have to pull PCS_RCTL before or the same as SR2, to let RF signal in. Otherwise, I/Q will ring when higher gain. So QB_PR2(100) set the same value as QB_SR2(100).
 * Resolution for 1734: [L1D][FixBug]After setting gain(SR2), MT6119 needs RF input for gain settling. For GSM/DCS band, there always exist RF input. But for PCS band, we have to pull PCS_RCTL before or the same as SR2, to let RF signal in. Otherwise, I/Q will r
 *
 *    Rev 1.45   Apr 30 2003 20:41:08   mtk00489
 * [L1D][Enhanced]L1D fills chip specific registers to support MT6205B - a.RX_CON / AFC_CALIBIAS b.RXADC_NoiseFlow c.BBTX_GAIN
 * Resolution for 1693: [L1D][Enhanced]L1D fills chip specific registers to support MT6205B.
 *
 *    Rev 1.44   Apr 11 2003 16:44:42   mtk00489
 * [L1D][FixBug] L1D adjust SR2(from 40 to 100) for MT6119 by SA's request. In order to lower the ring of I/Q when channel filter switching
 * Resolution for 1522: [L1D][FixBug] L1D adjust SR2(from 40 to 100) for MT6119 by SA's request. In order to lower the ring of I/Q when channel filter switching
 *
 *    Rev 1.43   Mar 05 2003 09:09:46   mtk00474
 * modify the ST1(400->450) and the PDATA of PT2 for MT6119
 * Resolution for 660: modify the ST1 and the PDATA of PT2 for MT6119
 *
 *    Rev 1.42   Feb 10 2003 12:19:04   mtk00474
 * change ST1 266 to 400 for MT6119
 * Resolution for 638: change ST1 266 to 400 for MT6119
 *
 *    Rev 1.41   Jan 17 2003 16:31:50   mtk00474
 * Update SR1 and SR3 for MT6119,
 * min time duration between two consecutive bsi events: 6*N + 4 (in quarter bit unit)
 * N: the number of bsi data words will be sent by the earlier bsi event.
 * Resolution for 630: Update SR1 and SR3 for MT6119
 *
 *    Rev 1.40   Dec 27 2002 21:15:50   mtk00489
 * L1D change QB_RX_FENA_2_FSYNC back to 33(4N+1) ONLY in Loopback mode
 * Resolution for 603: L1D change QB_RX_FENA_2_FSYNC back to 33(4N+1) ONLY in Loopback mode
 *
 *    Rev 1.39   Dec 20 2002 20:23:20   mtk00474
 * Modify PT2 data
 * Resolution for 599: Modify MT6119 PT2
 *
 *    Rev 1.38   17 Dec 2002 09:19:52   mtk00240
 * L1D change the defintion of QB_APC_DCOFFSET_2_RAMPUP to QB_APCDACON
 * Resolution for 594: L1D change the defintion of QB_APC_DCOFFSET_2_RAMPUP to QB_APCDACON
 *
 *    Rev 1.37   10 Dec 2002 08:12:24   mtk00240
 * modify some code to support MT6218 simulation
 * Resolution for 581: L1D add code to support MT6218
 *
 *    Rev 1.36   Dec 05 2002 22:22:04   mtk00474
 * Modify MT6119 QB_SR2/QB_PR2
 * Resolution for 582: Modify MT6119 QB_SR2/QB_PR2
 *
 *    Rev 1.35   05 Dec 2002 10:50:28   mtk00240
 * L1D add code to support MT6218
 * Resolution for 581: L1D add code to support MT6218
 *
 *    Rev 1.34   02 Dec 2002 13:36:08   mtk00240
 * L1D add  2QB to RX frame sync to frame enable to avoid receiving bad quality of slot2
 * Resolution for 576: L1D add  2QB to RX frame sync to frame enable to avoid receiving bad quality of slot2
 *
 *    Rev 1.33   Nov 29 2002 15:42:08   mtk00474
 * Add ST1 event data for MT6119. So that the BSI will send two data when ST1 happens to improve the side band suppression
 * Resolution for 575: Add ST1 event data for MT6119
 *
 *    Rev 1.32   22 Nov 2002 17:32:48   mtk00240
 * CLK_SETTLE_DEFAULT of all RF modules are 100
 * Resolution for 605: Adjust CLK_Settle time to around 3ms
 *
 *    Rev 1.31   12 Nov 2002 12:28:36   mtk00240
 * L1D add APC enable register setting for MT6218
 * Resolution for 558: L1D add APC enable register setting for MT6218
 *
 *    Rev 1.30   Nov 11 2002 18:04:58   mtk00474
 * Update MT6119 and AERO RF parameters
 * Resolution for 557: Update MT6119 and AERO RF parameters
 *
 *    Rev 1.29   07 Nov 2002 14:28:34   mtk00240
 * L1D modify the timing of setting gain during multi-RX slots
 * Resolution for 555: L1D modify the timing of setting gain during multi-RX slots
 *
 *    Rev 1.28   06 Nov 2002 10:30:42   mtk00240
 * (1) Remove SM clk defintion from l1d_data.h to l1d_rf.h
 * (2) CLK_SETTLE_DEFAULT is 200 except Bright4+MT6206 is 100
 * Resolution for 599: CLK_Settle time setting
 *
 *    Rev 1.27   01 Nov 2002 11:11:24   mtk00240
 * L1D modify TX PLL evaulation for new MT6119 chip
 * Resolution for 547: L1D modify TX PLL evaulation for new MT6119 chip
 *
 *    Rev 1.26   28 Oct 2002 09:19:42   mtk00240
 * Add Tx CALRCSEL CALBIAS setting for SA
 * Resolution for 524: L1D add TX_I/Q_OFFSET definition for SA
 *
 *    Rev 1.25   22 Oct 2002 08:18:00   mtk00240
 * L1D modified some control data of mt6119
 * Resolution for 439: L1D add code to support MT6119 RF Module
 *
 *    Rev 1.24   08 Oct 2002 17:24:12   mtk00240
 * L1D add TX_I/Q_OFFSET definition for SA
 * Resolution for 524: L1D add TX_I/Q_OFFSET definition for SA
 *
 *    Rev 1.23   01 Oct 2002 09:40:38   mtk00240
 * L1D add TX_TRIM_I/Q definition for SA
 * Resolution for 514: L1D add TX_TRIM_I/Q definition for SA
 *
 *    Rev 1.22   11 Sep 2002 12:08:00   mtk00240
 * (1) All NB RX window is 156 bit
 * (2) All NB TX window is 148 bit
 * (3) change all slot boundary to 157/156/156/156
 * Resolution for 457: L1D change slot length to 157bit,156bit,156bit,156bit
 *
 *    Rev 1.21   03 Sep 2002 21:34:36   mtk00240
 * Add BSI Long/Short Enable Positive/Negative Enable
 * Resolution for 464:  L1D add code to support AERO RF Module
 *
 *    Rev 1.20   02 Sep 2002 17:10:14   mtk00240
 * Add BSI device CS polarity selection
 * Resolution for 464:  L1D add code to support AERO RF Module
 *
 *    Rev 1.19   24 Aug 2002 14:10:46   mtk00240
 *  L1D add code to support AERO RF Module
 * Resolution for 464:  L1D add code to support AERO RF Module
 *
 *    Rev 1.18   02 Aug 2002 08:40:48   mtk00240
 * Change the timing definition
 * Resolution for 439: L1D add code to support MT6119 RF Module
 *
 *    Rev 1.17   23 Jul 2002 15:49:10   mtk00240
 * L1D add code to support MT6119 RF Module
 * Resolution for 439: L1D add code to support MT6119 RF Module
 *
 *    Rev 1.16   18 Jul 2002 16:36:24   mtk00240
 * L1D modified code for MT6205
 * (1) change BPI setting (l1d_rf.h)
 * (2) Fix APC Scale factor (m12170.c)
 * (3) disable IDN_SEL and GPIO mode setting (m12190.c)
 * Resolution for 437: L1D modified code for MT6205
 *
 *    Rev 1.15   04 Jul 2002 12:05:20   mtk00240
 * add new definition
 * Resolution for 418: L1D extrract RF setting code to let customer setup new RF module more easily
 *
 *    Rev 1.14   04 Jul 2002 12:00:02   mtk00240
 * rename some aliases and add reference table
 * Resolution for 418: L1D extrract RF setting code to let customer setup new RF module more easily
 *
 *    Rev 1.13   03 Jul 2002 21:43:46   mtk00240
 * L1D extrract RF setting code to let customer setup new RF module more easily
 * Resolution for 418: L1D extrract RF setting code to let customer setup new RF module more easily
 *
 *    Rev 1.12   28 May 2002 23:40:08   mtk00240
 * Set TX_CMV value for Bright4
 * Resolution for 356: L1D add some code to operate Bright4 RF propertly
 *
 *    Rev 1.11   21 May 2002 13:26:16   mtk00240
 * Let Bright4 lock the frequency at the right time
 * Resolution for 356: L1D add some code to operate Bright4 RF propertly
 *
 *    Rev 1.10   16 May 2002 15:03:44   mtk00240
 * Modified some calibration data for Broght4
 * Resolution for 356: L1D add some code to operate Bright4 RF propertly
 *
 *    Rev 1.9   01 May 2002 22:45:54   mtk00240
 * Extract GSM code from L1D
 * Resolution for 384: Extract GSM code from L1D
 *
 *    Rev 1.8   23 Apr 2002 14:38:42   mtk00240
 * Changed R/TXSWAP form (0/1) to (1/0) and modified M flag in IF registers
 * Resolution for 356: L1D add some code to operate Bright4 RF propertly
 *
 *    Rev 1.7   12 Apr 2002 21:27:10   mtk00240
 * L1D add new initialized value for RF
 * Resolution for 359: L1D add new initialized value for RF
 *
 *    Rev 1.6   03 Apr 2002 19:30:30   mtk00240
 * Fix some code to support Bright4 properly
 * Resolution for 341: Modify L1D code to support both Bright2 & Bright4 RF board
 *
 *    Rev 1.5   30 Mar 2002 13:04:10   mtk00240
 * 1) Modify L1D code to support both Bright2 & Bright4 RF board
 * 2) L1D add Audio interface to support Voice Memo & Melody
 * 3) Add L1D code to support RAM-based chip
 * Resolution for 341: Modify L1D code to support both Bright2 & Bright4 RF board
 * Resolution for 342: L1D add Audio interface to support Voice Memo & Melody
 * Resolution for 343: Add L1D code to support RAM-based chip
 *
 *    Rev 1.4   11 Mar 2002 13:35:40   mtk00240
 * instead TAB characters of Space characters in L1D code .
 * Resolution for 318: Shine change TAB character to Space charter
 *
 *    Rev 1.3   03 Mar 2002 23:06:30   mtk00240
 * L1D add code to setup APC DC offset
 * Resolution for 305: L1D add code to setup APC DC offset
 *
 *    Rev 1.2   08 Jan 2002 17:10:54   mtk00240
 * Change TQ_BULON, TQ_BULOFF, TQ_BDLON.
 * Let IQ Swap can be change on running time.
 * Resolution for 203: Modify some RF parameters in L1D
 *
 *    Rev 1.1   03 Jan 2002 12:19:46   mtk00240
 * Merge B.L1.20011225 to Main V1.XX
 *
 *    Rev 1.0   Dec 25 2001 14:40:22   admin
 * Initial revision.
 *
 *******************************************************************************/

#ifndef  _L1D_RF_H_
#define  _L1D_RF_H_
/* ------------------------------------------------------------------------- */
/*==========================*/  /*========================*/
/* BBRX_GAIN_DOUBLE         */  /* BBTX_CALBIAS           */
/*--------------------------*/  /*------------------------*/
/* 0: mapping range = 2.24V */  /* N= 0..+15 : 1.038^N    */
/* 1: mapping range = 1.12V */  /* N=-1..-16 : 0.918^(-N) */
/*==========================*/  /*========================*/
/*==========================*/  /*========================*/
/* BBTX_COMMON_MODE_VOLTAGE */  /* BBTX_CALRCSEL          */
/*--------------------------*/  /*------------------------*/
/* Set | Volt || Set | Volt */  /* Set | BW  || Set | BW  */
/*-----+------||-----+------*/  /*-----+-----||-----+-----*/
/*  3  | 1.75 || -1  | 1.29 */  /*  3  | 213 || -1  | 394 */
/*  2  | 1.62 || -2  | 1.18 */  /*  2  | 245 || -2  | 450 */
/*  1  | 1.51 || -3  | 1.06 */  /*  1  | 289 || -3  | 520 */
/*  0  | 1.40 || -4  | 0.95 */  /*  0  | 350 || -4  | 620 */
/*==========================*/  /*========================*/
/*==========================*/  /*========================*/
/* BBTX_TRIM_I              */  /* BBTX_OFFSET_I          */
/* BBTX_TRIM_Q              */  /* BBTX_OFFSET_Q          */
/*--------------------------*/  /*------------------------*/
/* N= -8...+7 : 0.16N dB    */  /* N=-32...+31: 2.737N mV */
/*==========================*/  /*========================*/
/*========================================================*/
/* BBTX_GAIN                                              */
/* --+---------+---------------+------------+-------------*/
/* S | FPGA    |               |            |             */
/* e | MT6208  | MT6205B       | MT6218B_EN | MT6218B_FN~ */
/* t | MT6205A | MT6218B_AN~DN | MT6219AV   | MT6219_BV   */
/*   | MT6218A |               |            |             */
/*---+---------+---------------+------------+-------------*/
/* 3 |  2.52V  |     1.48V     |   0.93V    |   1.50V     */
/* 2 |  2.01V  |     1.37V     |   0.87V    |   1.42V     */
/* 1 |  1.62V  |     1.29V     |   0.81V    |   1.36V     */
/* 0 |  1.26V  |     1.15V     |   0.76V    |   1.19V     */
/*-1 |  1.00V  |     1.06V     |   0.71V    |   1.12V     */
/*-2 |  0.81V  |     1.00V     |   0.66V    |   1.05V     */
/*-3 |  0.64V  |     0.92V     |   0.62V    |   1.00V     */
/*-4 |  0.50V  |     0.87V     |   0.58V    |   0.93V     */
/*========================================================*/
/* ------------------------------------------------------------------------- */
#define  CLK32K_MICRO_SECOND(n)       ((int)(n*32.0/1000))
/* ------------------------------------------------------------------------- */

#if IS_RF_BRIGHT2
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*BRIGHT2*/ #if IS_FPGA_TARGET
/* under construction !*/
/* under construction !*/
/*BRIGHT2*/ #endif
/*BRIGHT2*/ #if IS_CHIP_TARGET
/* under construction !*/
/* under construction !*/
/*BRIGHT2*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*BRIGHT2*/ #if IS_FPGA_TARGET || IS_CHIP_MT6208 || IS_CHIP_MT6205A || IS_CHIP_MT6218A
/* under construction !*/
/*BRIGHT2*/ #elif IS_CHIP_MT6205B || IS_CHIP_MT6218B_AN2DN
/* under construction !*/
/*BRIGHT2*/ #elif IS_CHIP_MT6218B_EN || IS_CHIP_MT6219_AV
/* under construction !*/
/*BRIGHT2*/ #else  /*MT6218BFN~ || MT6219BV~*/
/* under construction !*/
/*BRIGHT2*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*============================================================================== */

#if IS_RF_BRIGHT4
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*BRIGHT4*/ #if IS_FPGA_TARGET || IS_CHIP_MT6208 || IS_CHIP_MT6205A || IS_CHIP_MT6218A
/* under construction !*/
/*BRIGHT4*/ #elif IS_CHIP_MT6205B || IS_CHIP_MT6218B_AN2DN
/* under construction !*/
/*BRIGHT4*/ #elif IS_CHIP_MT6218B_EN || IS_CHIP_MT6219_AV
/* under construction !*/
/*BRIGHT4*/ #else  /*MT6218BFN~ || MT6219BV~*/
/* under construction !*/
/*BRIGHT4*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*============================================================================== */

#if IS_RF_BRIGHT5P
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*BRIGHT5P*/ #if IS_FPGA_TARGET || IS_CHIP_MT6208 || IS_CHIP_MT6205A || IS_CHIP_MT6218A
/* under construction !*/
/*BRIGHT5P*/ #elif IS_CHIP_MT6205B || IS_CHIP_MT6218B_AN2DN
/* under construction !*/
/*BRIGHT5P*/ #elif IS_CHIP_MT6218B_EN || IS_CHIP_MT6219_AV
/* under construction !*/
/*BRIGHT5P*/ #else  /*MT6218BFN~ || MT6219BV~*/
/* under construction !*/
/*BRIGHT5P*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*============================================================================== */

#if IS_RF_AERO
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*AERO*/ #if IS_FPGA_TARGET || IS_CHIP_MT6208 || IS_CHIP_MT6205A || IS_CHIP_MT6218A
/* under construction !*/
/*AERO*/ #elif IS_CHIP_MT6205B || IS_CHIP_MT6218B_AN2DN
/* under construction !*/
/*AERO*/ #elif IS_CHIP_MT6218B_EN || IS_CHIP_MT6219_AV
/* under construction !*/
/*AERO*/ #else  /*MT6218BFN~ || MT6219BV~*/
/* under construction !*/
/*AERO*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*============================================================================== */

#if IS_RF_AERO1PLUS
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*AERO1+*/ #if IS_FPGA_TARGET || IS_CHIP_MT6208 || IS_CHIP_MT6205A || IS_CHIP_MT6218A
/* under construction !*/
/*AERO1+*/ #elif IS_CHIP_MT6205B || IS_CHIP_MT6218B_AN2DN
/* under construction !*/
/*AERO1+*/ #elif IS_CHIP_MT6218B_EN || IS_CHIP_MT6219_AV
/* under construction !*/
/*AERO1+*/ #else  /*MT6218BFN~ || MT6219BV~*/
/* under construction !*/
/*AERO1+*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*============================================================================== */

#if IS_RF_POLARIS1
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*RFMD*/ #if IS_FPGA_TARGET || IS_CHIP_MT6208 || IS_CHIP_MT6205A || IS_CHIP_MT6218A
/* under construction !*/
/*RFMD*/ #elif IS_CHIP_MT6205B || IS_CHIP_MT6218B_AN2DN
/* under construction !*/
/*RFMD*/ #elif IS_CHIP_MT6218B_EN || IS_CHIP_MT6219_AV
/* under construction !*/
/*RFMD*/ #else  /*MT6218BFN~ || MT6219BV~*/
/* under construction !*/
/*RFMD*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*============================================================================== */

#if IS_RF_SKY74117
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*SKY74117*/ #if IS_FPGA_TARGET || IS_CHIP_MT6208 || IS_CHIP_MT6205A || IS_CHIP_MT6218A
/* under construction !*/
/*SKY74117*/ #elif IS_CHIP_MT6205B || IS_CHIP_MT6218B_AN2DN
/* under construction !*/
/*SKY74117*/ #elif IS_CHIP_MT6218B_EN || IS_CHIP_MT6219_AV
/* under construction !*/
/*SKY74117*/ #else  /*MT6218BFN~ || MT6219BV~*/
/* under construction !*/
/*SKY74117*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*SKY74117*/ #if IS_CHIP_MT6227
/* under construction !*/
/*SKY74117*/ #elif IS_CHIP_MT6218_AND_LATTER_VERSION
/*SKY74117*/    #if defined(MT6228_S00) || defined(MT6228_S01)
/* under construction !*/
/*SKY74117*/    #else
/* under construction !*/
/*SKY74117*/    #endif
/*SKY74117*/ #elif IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*SKY74117*/    #if IS_CHIP_MT6229_S00
/* under construction !*/
/*SKY74117*/    #else
/* under construction !*/
/*SKY74117*/    #endif
/*SKY74117*/ #else
/* under construction !*/
/*SKY74117*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*============================================================================== */

#if IS_RF_SKY74400
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*SKY74400*/ #if IS_FPGA_TARGET || IS_CHIP_MT6208 || IS_CHIP_MT6205A || IS_CHIP_MT6218A
/* under construction !*/
/*SKY74400*/ #elif IS_CHIP_MT6205B || IS_CHIP_MT6218B_AN2DN
/* under construction !*/
/*SKY74400*/ #elif IS_CHIP_MT6218B_EN || IS_CHIP_MT6219_AV
/* under construction !*/
/*SKY74400*/ #else  /*MT6218BFN~ || MT6219BV~*/
/* under construction !*/
/*SKY74400*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*SKY74400*/ #if IS_CHIP_MT6227
/* under construction !*/
/*SKY74400*/ #else
/* under construction !*/
/*SKY74400*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*============================================================================== */

#if IS_RF_MT6119
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6119*/ #if IS_FPGA_TARGET || IS_CHIP_MT6208 || IS_CHIP_MT6205A || IS_CHIP_MT6218A
/* under construction !*/
/*MT6119*/ #elif IS_CHIP_MT6205B || IS_CHIP_MT6218B_AN2DN
/* under construction !*/
/*MT6119*/ #elif IS_CHIP_MT6218B_EN || IS_CHIP_MT6219_AV
/* under construction !*/
/*MT6119*/ #else  /*MT6218BFN~ || MT6219BV~*/
/* under construction !*/
/*MT6119*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*============================================================================== */

#if IS_RF_MT6119C
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6119C*/ #if IS_FPGA_TARGET || IS_CHIP_MT6208 || IS_CHIP_MT6205A || IS_CHIP_MT6218A
/* under construction !*/
/*MT6119C*/ #elif IS_CHIP_MT6205B || IS_CHIP_MT6218B_AN2DN
/* under construction !*/
/*MT6119C*/ #elif IS_CHIP_MT6218B_EN || IS_CHIP_MT6219_AV
/* under construction !*/
/*MT6119C*/ #else  /*MT6218BFN~ || MT6219BV~*/
/* under construction !*/
/*MT6119C*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*============================================================================== */

#if IS_RF_MT6129A
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6129A*/ #if IS_FPGA_TARGET || IS_CHIP_MT6208 || IS_CHIP_MT6205A || IS_CHIP_MT6218A
/* under construction !*/
/*MT6129A*/ #elif IS_CHIP_MT6205B || IS_CHIP_MT6218B_AN2DN
/* under construction !*/
/*MT6129A*/ #elif IS_CHIP_MT6218B_EN || IS_CHIP_MT6219_AV
/* under construction !*/
/*MT6129A*/ #else  /*MT6218BFN~ || MT6219BV~*/
/* under construction !*/
/*MT6129A*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*============================================================================== */

#if IS_RF_MT6129B
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6129B*/ #if IS_FPGA_TARGET || IS_CHIP_MT6208 || IS_CHIP_MT6205A || IS_CHIP_MT6218A
/* under construction !*/
/*MT6129B*/ #elif IS_CHIP_MT6205B || IS_CHIP_MT6218B_AN2DN
/* under construction !*/
/*MT6129B*/ #elif IS_CHIP_MT6218B_EN || IS_CHIP_MT6219_AV
/* under construction !*/
/*MT6129B*/ #else  /*MT6218BFN~ || MT6219BV~*/
/* under construction !*/
/*MT6129B*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*============================================================================== */

#if IS_RF_MT6129C
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6129C*/ #if IS_FPGA_TARGET || IS_CHIP_MT6208 || IS_CHIP_MT6205A || IS_CHIP_MT6218A
/* under construction !*/
/*MT6129C*/ #elif IS_CHIP_MT6205B || IS_CHIP_MT6218B_AN2DN
/* under construction !*/
/*MT6129C*/ #elif IS_CHIP_MT6218B_EN || IS_CHIP_MT6219_AV
/* under construction !*/
/*MT6129C*/ #else  /*MT6218BFN~ || MT6219BV~*/
/* under construction !*/
/*MT6129C*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*============================================================================== */

#if IS_RF_MT6129D
/*MT6129D*/
/*MT6129D*/ /*--------------------------------------------------------*/
/*MT6129D*/ /*   define SRCB data (shall be modified by real case)    */
/*MT6129D*/ /*--------------------------------------------------------*/
/*MT6129D*/
/*MT6129D*/ #define  SX1_DATA_COUNT               3
/*MT6129D*/ #define  SX2_DATA_COUNT               1
/*MT6129D*/ #define  SX3_DATA_COUNT               1
/*MT6129D*/
/*MT6129D*/ #define  SCTRL_IDLE                   SCTRL_WORD(0,24)
/*MT6129D*/ #define  SDATA_IDLE                   0x124982
/*MT6129D*/
/*MT6129D*/ /* polarity:  0: long  enable positive pulse */
/*MT6129D*/ /*            1: short enable positive pulse */
/*MT6129D*/ /*            2: long  enable negative pulse */
/*MT6129D*/ /*            3: short enable negative pulse */
/*MT6129D*/ #define  BSI_DEVICE_0_CS_POLARITY     1
/*MT6129D*/ #define  BSI_DEVICE_1_CS_POLARITY     1
/*MT6129D*/
/*MT6129D*/ /*--------------------------------------------------------*/
/*MT6129D*/ /*   Sleep Mode Setting                                   */
/*MT6129D*/ /*--------------------------------------------------------*/
/*MT6129D*/
/*MT6129D*/ #define  FM_DURATION_DEFAULT          8191
/*MT6129D*/ #ifdef  AFC_VCXO
/*MT6129D*/ #define  CLK_SETTLE_DEFAULT           CLK32K_MICRO_SECOND(5000)
/*MT6129D*/ #define  PLL_RESET_DEFAULT            CLK32K_MICRO_SECOND(3500)
/*MT6129D*/ #else
/*MT6129D*/ #define  CLK_SETTLE_DEFAULT           CLK32K_MICRO_SECOND(4000)//3125
/*MT6129D*/ #define  PLL_RESET_DEFAULT            CLK32K_MICRO_SECOND(3000)
/*MT6129D*/ #endif
/*MT6129D*/
/*MT6129D*/ /*--------------------------------------------------------*/
/*MT6129D*/ /*   BFE Setting                                          */
/*MT6129D*/ /*--------------------------------------------------------*/
/*MT6129D*/ #define  BBRX_IQ_SWAP                 1
/*MT6129D*/ #define  BBRX_GAIN_DOUBLE             0
/*MT6129D*/
/*MT6129D*/ #define  BBTX_IQ_SWAP                 1
/*MT6129D*/ #define  BBTX_CALRCSEL               -2
/*MT6129D*/ #define  BBTX_CALBIAS                 0
/*MT6129D*/ #define  BBTX_COMMON_MODE_VOLTAGE    -3
/*MT6129D*/ #define  BBTX_TRIM_I                  0
/*MT6129D*/ #define  BBTX_TRIM_Q                  0
/*MT6129D*/ #define  BBTX_OFFSET_I                0
/*MT6129D*/ #define  BBTX_OFFSET_Q                0
/*MT6129D*/
/*MT6129D*/ #if IS_FPGA_TARGET || IS_CHIP_MT6208 || IS_CHIP_MT6205A || IS_CHIP_MT6218A
/*MT6129D*/ #define  BBTX_GAIN                   -1
/*MT6129D*/ #elif IS_CHIP_MT6205B || IS_CHIP_MT6218B_AN2DN
/*MT6129D*/ #define  BBTX_GAIN                   -2
/*MT6129D*/ #elif IS_CHIP_MT6218B_EN || IS_CHIP_MT6219_AV
/*MT6129D*/ #define  BBTX_GAIN                    3
/*MT6129D*/ #else  /*MT6218BFN~ || MT6219BV~*/
/*MT6129D*/ #define  BBTX_GAIN                   -3
/*MT6129D*/ #endif
/*MT6129D*/
/*MT6129D*/ #define  BBTX_GAIN_SWING              1000  /* mV */
/*MT6129D*/
#endif

/*============================================================================== */

#if IS_RF_MT6139B
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6139B*/ #ifdef  AFC_VCXO
/* under construction !*/
/* under construction !*/
/*MT6139B*/ #else
/* under construction !*/
/* under construction !*/
/*MT6139B*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6139B*/ #if IS_FPGA_TARGET || IS_CHIP_MT6208 || IS_CHIP_MT6205A || IS_CHIP_MT6218A
/* under construction !*/
/*MT6139B*/ #elif IS_CHIP_MT6205B || IS_CHIP_MT6218B_AN2DN
/* under construction !*/
/*MT6139B*/ #elif IS_CHIP_MT6218B_EN || IS_CHIP_MT6219_AV
/* under construction !*/
/*MT6139B*/ #else  /*MT6218BFN~ || MT6219BV~*/
/* under construction !*/
/*MT6139B*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*============================================================================== */

#if IS_RF_MT6139C
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6139C*/ #ifdef  AFC_VCXO
/* under construction !*/
/* under construction !*/
/*MT6139C*/ #else
/* under construction !*/
/* under construction !*/
/*MT6139C*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6139C*/ #if IS_FPGA_TARGET || IS_CHIP_MT6208 || IS_CHIP_MT6205A || IS_CHIP_MT6218A
/* under construction !*/
/*MT6139C*/ #elif IS_CHIP_MT6205B || IS_CHIP_MT6218B_AN2DN
/* under construction !*/
/*MT6139C*/ #elif IS_CHIP_MT6218B_EN || IS_CHIP_MT6219_AV
/* under construction !*/
/*MT6139C*/ #else  /*MT6218BFN~ || MT6219BV~*/
/* under construction !*/
/*MT6139C*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*============================================================================== */

#if IS_RF_MT6139E
/*MT6139E*/
/*MT6139E*/ /*--------------------------------------------------------*/
/*MT6139E*/ /*   define SRCB data (shall be modified by real case)    */
/*MT6139E*/ /*--------------------------------------------------------*/
/*MT6139E*/
/*MT6139E*/ #define  SX1_DATA_COUNT               3
/*MT6139E*/ #define  SX2_DATA_COUNT               1
/*MT6139E*/ #define  SX3_DATA_COUNT               1
/*MT6139E*/
/*MT6139E*/ #define  SCTRL_IDLE                   SCTRL_WORD(0,26)
/*MT6139E*/ #define  SDATA_IDLE                   0x0002002 //CW2: Enter Sleep mode
/*MT6139E*/
/*MT6139E*/ /* polarity:  0: long  enable positive pulse */
/*MT6139E*/ /*            1: short enable positive pulse */
/*MT6139E*/ /*            2: long  enable negative pulse */
/*MT6139E*/ /*            3: short enable negative pulse */
/*MT6139E*/ #define  BSI_DEVICE_0_CS_POLARITY     1
/*MT6139E*/ #define  BSI_DEVICE_1_CS_POLARITY     1
/*MT6139E*/
/*MT6139E*/ /*--------------------------------------------------------*/
/*MT6139E*/ /*   Sleep Mode Setting                                   */
/*MT6139E*/ /*--------------------------------------------------------*/
/*MT6139E*/
/*MT6139E*/ #define  FM_DURATION_DEFAULT          8191
/*MT6139E*/ #ifdef  AFC_VCXO
/*MT6139E*/ #define  CLK_SETTLE_DEFAULT           CLK32K_MICRO_SECOND(5000)
/*MT6139E*/ #define  PLL_RESET_DEFAULT            CLK32K_MICRO_SECOND(3500)
/*MT6139E*/ #else
/*MT6139E*/ #define  CLK_SETTLE_DEFAULT           CLK32K_MICRO_SECOND(4000)//3125
/*MT6139E*/ #define  PLL_RESET_DEFAULT            CLK32K_MICRO_SECOND(3000)
/*MT6139E*/ #endif
/*MT6139E*/
/*MT6139E*/ /*--------------------------------------------------------*/
/*MT6139E*/ /*   BFE Setting                                          */
/*MT6139E*/ /*--------------------------------------------------------*/
/*MT6139E*/ #define  BBRX_IQ_SWAP                 0
/*MT6139E*/ #define  BBRX_GAIN_DOUBLE             0
/*MT6139E*/
/*MT6139E*/ #define  BBTX_IQ_SWAP                 1
/*MT6139E*/ #define  BBTX_CALRCSEL               -2
/*MT6139E*/ #define  BBTX_CALBIAS                 0
/*MT6139E*/ #define  BBTX_COMMON_MODE_VOLTAGE    -1
/*MT6139E*/ #define  BBTX_TRIM_I                  0
/*MT6139E*/ #define  BBTX_TRIM_Q                  0
/*MT6139E*/ #define  BBTX_OFFSET_I                0
/*MT6139E*/ #define  BBTX_OFFSET_Q                0
/*MT6139E*/ #define  BBTX_RPSEL                   1
/*MT6139E*/ #define  BBTX_INTEN                   1
/*MT6139E*/ #define  BBTX_SW_QBCNT               28
/*MT6139E*/
/*MT6139E*/ #if IS_FPGA_TARGET || IS_CHIP_MT6208 || IS_CHIP_MT6205A || IS_CHIP_MT6218A
/*MT6139E*/ #define  BBTX_GAIN                   -1
/*MT6139E*/ #elif IS_CHIP_MT6205B || IS_CHIP_MT6218B_AN2DN
/*MT6139E*/ #define  BBTX_GAIN                   -2
/*MT6139E*/ #elif IS_CHIP_MT6218B_EN || IS_CHIP_MT6219_AV
/*MT6139E*/ #define  BBTX_GAIN                    3
/*MT6139E*/ #else  /*MT6218BFN~ || MT6219BV~*/
/*MT6139E*/ #define  BBTX_GAIN                   -3
/*MT6139E*/ #endif
/*MT6139E*/
/*MT6139E*/
/*MT6139E*/ #define  BBTX_GAIN_SWING              900  /* mV */ //request by JP
/*MT6139E*/
/*MT6139E*/ /* default value */
/*MT6139E*/ #define  ACODE850                     0x0820
/*MT6139E*/ #define  AMCODE850                    0x2040
/*MT6139E*/ #define  ACODE900                     0x0820
/*MT6139E*/ #define  AMCODE900                    0x2040
/*MT6139E*/ #define  ACODE1800                    0x0820
/*MT6139E*/ #define  AMCODE1800                   0x2040
/*MT6139E*/ #define  ACODE1900                    0x0820
/*MT6139E*/ #define  AMCODE1900                   0x2040
/*MT6139E*/
/*MT6139E*/ /*--------------------------------------------------------*/
/*MT6139E*/ /*   Define the CapID range                               */
/*MT6139E*/ /*--------------------------------------------------------*/
/*MT6139E*/ #define  CRYSTAL_CAPID_RANGE          63
/*MT6139E*/
#endif

/*============================================================================== */

#if IS_RF_MT6140A
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6140A*/ #ifdef  AFC_VCXO
/* under construction !*/
/* under construction !*/
/*MT6140A*/ #else
/* under construction !*/
/* under construction !*/
/*MT6140A*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6140A*/ #if IS_FPGA_TARGET || IS_CHIP_MT6208 || IS_CHIP_MT6205A || IS_CHIP_MT6218A
/* under construction !*/
/*MT6140A*/ #elif IS_CHIP_MT6205B || IS_CHIP_MT6218B_AN2DN
/* under construction !*/
/*MT6140A*/ #elif IS_CHIP_MT6218B_EN || IS_CHIP_MT6219_AV
/* under construction !*/
/*MT6140A*/ #else  /*MT6218BFN~ || MT6219BV~*/
/* under construction !*/
/*MT6140A*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*============================================================================== */

#if IS_RF_MT6140B
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6140B*/ #ifdef  AFC_VCXO
/* under construction !*/
/* under construction !*/
/*MT6140B*/ #else
/* under construction !*/
/* under construction !*/
/*MT6140B*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6140B*/ #if IS_FPGA_TARGET || IS_CHIP_MT6208 || IS_CHIP_MT6205A || IS_CHIP_MT6218A
/* under construction !*/
/* under construction !*/
/*MT6140B*/ #elif IS_CHIP_MT6205B || IS_CHIP_MT6218B_AN2DN
/* under construction !*/
/* under construction !*/
/*MT6140B*/ #elif IS_CHIP_MT6218B_EN || IS_CHIP_MT6219_AV
/* under construction !*/
/* under construction !*/
/*MT6140B*/ #else  /*MT6218BFN~ || MT6219BV~*/
/* under construction !*/
/* under construction !*/
/*MT6140B*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*============================================================================== */

#if IS_RF_MT6140C
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6140C*/ #ifdef  AFC_VCXO
/* under construction !*/
/* under construction !*/
/*MT6140C*/ #else
/* under construction !*/
/* under construction !*/
/*MT6140C*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6140C*/ #if IS_FPGA_TARGET || IS_CHIP_MT6208 || IS_CHIP_MT6205A || IS_CHIP_MT6218A
/* under construction !*/
/* under construction !*/
/*MT6140C*/ #elif IS_CHIP_MT6205B || IS_CHIP_MT6218B_AN2DN
/* under construction !*/
/* under construction !*/
/*MT6140C*/ #elif IS_CHIP_MT6218B_EN || IS_CHIP_MT6219_AV
/* under construction !*/
/* under construction !*/
/*MT6140C*/ #else  /*MT6218BFN~ || MT6219BV~*/
/* under construction !*/
/* under construction !*/
/*MT6140C*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*============================================================================== */

#if IS_RF_MT6140D
/*MT6140D*/
/*MT6140D*/ /*--------------------------------------------------------*/
/*MT6140D*/ /*   define SRCB data (shall be modified by real case)    */
/*MT6140D*/ /*--------------------------------------------------------*/
/*MT6140D*/
/*MT6140D*/ #define  SX1_DATA_COUNT               3
/*MT6140D*/ #define  SX2_DATA_COUNT               1
/*MT6140D*/ #define  SX3_DATA_COUNT               1
/*MT6140D*/ #define  ST2B_ST2M_DATA_COUNT         1
/*MT6140D*/ #define  SCTRL_IDLE                   SCTRL_WORD(0,26)
/*MT6140D*/ #define  SDATA_IDLE                   0x0000002
/*MT6140D*/
/*MT6140D*/ /* polarity:  0: long  enable positive pulse */
/*MT6140D*/ /*            1: short enable positive pulse */
/*MT6140D*/ /*            2: long  enable negative pulse */
/*MT6140D*/ /*            3: short enable negative pulse */
/*MT6140D*/ #define  BSI_DEVICE_0_CS_POLARITY     1
/*MT6140D*/ #define  BSI_DEVICE_1_CS_POLARITY     1
/*MT6140D*/
/*MT6140D*/ /*--------------------------------------------------------*/
/*MT6140D*/ /*   Sleep Mode Setting                                   */
/*MT6140D*/ /*--------------------------------------------------------*/
/*MT6140D*/
/*MT6140D*/ #define  FM_DURATION_DEFAULT          8191
/*MT6140D*/ #ifdef  AFC_VCXO
/*MT6140D*/ #define  CLK_SETTLE_DEFAULT           CLK32K_MICRO_SECOND(5000)
/*MT6140D*/ #define  PLL_RESET_DEFAULT            CLK32K_MICRO_SECOND(3500)
/*MT6140D*/ #else
/*MT6140D*/ #define  CLK_SETTLE_DEFAULT           CLK32K_MICRO_SECOND(4000)//3125
/*MT6140D*/ #define  PLL_RESET_DEFAULT            CLK32K_MICRO_SECOND(3000)
/*MT6140D*/ #endif
/*MT6140D*/
/*MT6140D*/ /*--------------------------------------------------------*/
/*MT6140D*/ /*   BFE Setting                                          */
/*MT6140D*/ /*--------------------------------------------------------*/
/*MT6140D*/ #define  BBRX_IQ_SWAP                 0
/*MT6140D*/ #define  BBRX_GAIN_DOUBLE             0
/*MT6140D*/
/*MT6140D*/ #define  BBTX_IQ_SWAP                 1
/*MT6140D*/ #define  BBTX_CALBIAS                 0
/*MT6140D*/
/*MT6140D*/ #define  BBTX_CALRCSEL                0
/*MT6140D*/ #define  BBTX_CALRCSEL_H              0
/*MT6140D*/ #if IS_BBTXRX_CHIP_DESIGN_VER_2
/*MT6140D*/ #define  BBTX_COMMON_MODE_VOLTAGE     1 /* 0: 1.1V, 1: 1.2V */
/*MT6140D*/ #else
/*MT6140D*/ #define  BBTX_COMMON_MODE_VOLTAGE    -1
/*MT6140D*/ #endif
/*MT6140D*/ #define  BBTX_COMMON_MODE_VOLTAGE_H  -1
/*MT6140D*/ #define  BBTX_TRIM_I                  0
/*MT6140D*/ #define  BBTX_TRIM_I_H                0
/*MT6140D*/ #define  BBTX_TRIM_Q                  0
/*MT6140D*/ #define  BBTX_TRIM_Q_H                0
/*MT6140D*/ #define  BBTX_OFFSET_I                0
/*MT6140D*/ #define  BBTX_OFFSET_I_H              0
/*MT6140D*/ #define  BBTX_OFFSET_Q                0
/*MT6140D*/ #define  BBTX_OFFSET_Q_H              0
/*MT6140D*/ #define  BBTX_PHSEL                   0
/*MT6140D*/ #define  BBTX_PHSEL_H                 0
/*MT6140D*/
/*MT6140D*/ #define  BBTX_RPSEL                   1
/*MT6140D*/ #define  BBTX_INTEN                   0
/*MT6140D*/ #define  BBTX_SW_QBCNT               28
/*MT6140D*/ #define  BBTX_COARSGAIN               1
/*MT6140D*/
/*MT6140D*/ #if IS_FPGA_TARGET || IS_CHIP_MT6208 || IS_CHIP_MT6205A || IS_CHIP_MT6218A
/*MT6140D*/ #define  BBTX_GAIN                   -1
/*MT6140D*/ #define  BBTX_GAIN_H                 -1
/*MT6140D*/ #elif IS_CHIP_MT6205B || IS_CHIP_MT6218B_AN2DN
/*MT6140D*/ #define  BBTX_GAIN                   -2
/*MT6140D*/ #define  BBTX_GAIN_H                 -2
/*MT6140D*/ #elif IS_CHIP_MT6218B_EN || IS_CHIP_MT6219_AV
/*MT6140D*/ #define  BBTX_GAIN                    3
/*MT6140D*/ #define  BBTX_GAIN_H                  3
/*MT6140D*/ #else  /*MT6218BFN~ || MT6219BV~*/
/*MT6140D*/ #define  BBTX_GAIN                    0
/*MT6140D*/ #define  BBTX_GAIN_H                  0
/*MT6140D*/ #endif
/*MT6140D*/
/*MT6140D*/ #define  BBTX_GAIN_SWING              900  /* mV */
/*MT6140D*/
/*MT6140D*/ /*--------------------------------------------------------*/
/*MT6140D*/ /*   Define the CapID range                               */
/*MT6140D*/ /*--------------------------------------------------------*/
/*MT6140D*/ #define  CRYSTAL_CAPID_RANGE          63
/*MT6140D*/
#endif

/*============================================================================== */

#if IS_RF_CMOSEDGE
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*CMOSEDGE*/ #ifdef  AFC_VCXO
/* under construction !*/
/* under construction !*/
/*CMOSEDGE*/ #else
/* under construction !*/
/* under construction !*/
/*CMOSEDGE*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*CMOSEDGE*/ #if IS_FPGA_TARGET || IS_CHIP_MT6208 || IS_CHIP_MT6205A || IS_CHIP_MT6218A
/* under construction !*/
/* under construction !*/
/*CMOSEDGE*/ #elif IS_CHIP_MT6205B || IS_CHIP_MT6218B_AN2DN
/* under construction !*/
/* under construction !*/
/*CMOSEDGE*/ #elif IS_CHIP_MT6218B_EN || IS_CHIP_MT6219_AV
/* under construction !*/
/* under construction !*/
/*CMOSEDGE*/ #else  /*MT6218BFN~ || MT6219BV~*/
/* under construction !*/
/* under construction !*/
/*CMOSEDGE*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*============================================================================== */

#if IS_RF_MTKSOC1 || IS_RF_MTKSOC1T
/*MTKSOC1*/
/*MTKSOC1*/ /*--------------------------------------------------------*/
/*MTKSOC1*/ /*   define SRCB data (shall be modified by real case)    */
/*MTKSOC1*/ /*--------------------------------------------------------*/
/*MTKSOC1*/
/*MTKSOC1*/ #define  SX1_DATA_COUNT               5
/*MTKSOC1*/ #define  SX2_DATA_COUNT               1
/*MTKSOC1*/ #define  SX3_DATA_COUNT               1
/*MTKSOC1*/ //#define  ST2B_ST2M_DATA_COUNT         0 //XXXXX
/*MTKSOC1*/ #define  SCTRL_IDLE                   SCTRL_WORD(0,26)
/*MTKSOC1*/ #define  SDATA_IDLE                   0x0200000
/*MTKSOC1*/
/*MTKSOC1*/ /* polarity:  0: long  enable positive pulse */
/*MTKSOC1*/ /*            1: short enable positive pulse */
/*MTKSOC1*/ /*            2: long  enable negative pulse */
/*MTKSOC1*/ /*            3: short enable negative pulse */
/*MTKSOC1*/ #define  BSI_DEVICE_0_CS_POLARITY     0
/*MTKSOC1*/ #define  BSI_DEVICE_1_CS_POLARITY     0
/*MTKSOC1*/
/*MTKSOC1*/ /*--------------------------------------------------------*/
/*MTKSOC1*/ /*   Sleep Mode Setting                                   */
/*MTKSOC1*/ /*-------------------------------------------------------*/
/*MTKSOC1*/
/*MTKSOC1*/ #define  FM_DURATION_DEFAULT          8191
/*MTKSOC1*/ #ifdef  AFC_VCXO
/*MTKSOC1*/ #define  CLK_SETTLE_DEFAULT           CLK32K_MICRO_SECOND(5000)
/*MTKSOC1*/ #define  PLL_RESET_DEFAULT            CLK32K_MICRO_SECOND(3500)
/*MTKSOC1*/ #else
/*MTKSOC1*/ #define  CLK_SETTLE_DEFAULT           CLK32K_MICRO_SECOND(4000)//3125
/*MTKSOC1*/ #define  PLL_RESET_DEFAULT            CLK32K_MICRO_SECOND(3000)
/*MTKSOC1*/ #endif
/*MTKSOC1*/
/*MTKSOC1*/ /*--------------------------------------------------------*/
/*MTKSOC1*/ /*   BFE Setting                                          */
/*MTKSOC1*/ /*--------------------------------------------------------*/
/*MTKSOC1*/ #define  BBRX_IQ_SWAP                 0
/*MTKSOC1*/ #define  BBRX_GAIN_DOUBLE             0
/*MTKSOC1*/
/*MTKSOC1*/ #define  BBTX_IQ_SWAP                 1 //SWAP(do not swap at high side mixing 1900, swap at low side 850 900 1800)
/*MTKSOC1*/ #define  BBTX_CALBIAS                 0
/*MTKSOC1*/
/*MTKSOC1*/ #define  BBTX_CALRCSEL                0
/*MTKSOC1*/ #define  BBTX_CALRCSEL_H              0
/*MTKSOC1*/ #define  BBTX_COMMON_MODE_VOLTAGE     1//COMMON MODE VOLTAGE: 1.5v
/*MTKSOC1*/ #define  BBTX_COMMON_MODE_VOLTAGE_H   1//COMMON MODE VOLTAGE: 1.5v
/*MTKSOC1*/ #define  BBTX_TRIM_I                  0// wait calibration
/*MTKSOC1*/ #define  BBTX_TRIM_I_H                0// wait calibration
/*MTKSOC1*/ #define  BBTX_TRIM_Q                  0// wait calibration
/*MTKSOC1*/ #define  BBTX_TRIM_Q_H                0// wait calibration
/*MTKSOC1*/ #define  BBTX_OFFSET_I                0// wait calibration
/*MTKSOC1*/ #define  BBTX_OFFSET_I_H              0// wait calibration
/*MTKSOC1*/ #define  BBTX_OFFSET_Q                0// wait calibration
/*MTKSOC1*/ #define  BBTX_OFFSET_Q_H              0// wait calibration
/*MTKSOC1*/ #define  BBTX_PHSEL                   0// wait calibration
/*MTKSOC1*/ #define  BBTX_PHSEL_H                 0// wait calibration
/*MTKSOC1*/
/*MTKSOC1*/ #define  BBTX_COARSGAIN               1 //XXXXX no use?
/*MTKSOC1*/
/*MTKSOC1*/ #if IS_FPGA_TARGET || IS_CHIP_MT6208 || IS_CHIP_MT6205A || IS_CHIP_MT6218A
/*MTKSOC1*/ #define  BBTX_GAIN                   -1
/*MTKSOC1*/ #define  BBTX_GAIN_H                 -1
/*MTKSOC1*/ #elif IS_CHIP_MT6205B || IS_CHIP_MT6218B_AN2DN
/*MTKSOC1*/ #define  BBTX_GAIN                   -2
/*MTKSOC1*/ #define  BBTX_GAIN_H                 -2
/*MTKSOC1*/ #elif IS_CHIP_MT6218B_EN || IS_CHIP_MT6219_AV
/*MTKSOC1*/ #define  BBTX_GAIN                    3
/*MTKSOC1*/ #define  BBTX_GAIN_H                  3
/*MTKSOC1*/ #else  /*MT6218BFN~ || MT6219BV~*/
/*MTKSOC1*/ #define  BBTX_GAIN                    2 // get from experiment
/*MTKSOC1*/ #define  BBTX_GAIN_H                  2 // get from experiment
/*MTKSOC1*/ #endif
/*MTKSOC1*/
/*MTKSOC1*/ #define  BBTX_GAIN_SWING              900  /* mV */
/*MTKSOC1*/
/*MTKSOC1*/ /*--------------------------------------------------------*/
/*MTKSOC1*/ /*   Define the CapID range                               */
/*MTKSOC1*/ /*--------------------------------------------------------*/
/*MTKSOC1*/ #define  CRYSTAL_CAPID_RANGE          127
/*MTKSOC1*/
#endif

/*============================================================================== */

#if IS_RF_MT6252RF
/*MT6252RF*/
/*MT6252RF*/ /*--------------------------------------------------------*/
/*MT6252RF*/ /*   define SRCB data (shall be modified by real case)    */
/*MT6252RF*/ /*--------------------------------------------------------*/
/*MT6252RF*/
/*MT6252RF*/ #define  SX0_DATA_COUNT               3
/*MT6252RF*/ #define  SX1_DATA_COUNT               1
/*MT6252RF*/ #define  SX2_DATA_COUNT               1
/*MT6252RF*/ #define  SX3_DATA_COUNT               1
/*MT6252RF*/ #define  ST2B_ST2M_DATA_COUNT         1
/*MT6252RF*/ #define  SCTRL_IDLE                   SCTRL_WORD(0,29)
/*MT6252RF*/ #define  SDATA_IDLE                   0x0200000
/*MT6252RF*/
/*MT6252RF*/ /* polarity:  0: long  enable positive pulse */
/*MT6252RF*/ /*            1: short enable positive pulse */
/*MT6252RF*/ /*            2: long  enable negative pulse */
/*MT6252RF*/ /*            3: short enable negative pulse */
/*MT6252RF*/ #define  BSI_DEVICE_0_CS_POLARITY     0
/*MT6252RF*/ #define  BSI_DEVICE_1_CS_POLARITY     0
/*MT6252RF*/
/*MT6252RF*/ /*--------------------------------------------------------*/
/*MT6252RF*/ /*   Sleep Mode Setting                                   */
/*MT6252RF*/ /*-------------------------------------------------------*/
/*MT6252RF*/
/*MT6252RF*/ #define  FM_DURATION_DEFAULT          8191
/*MT6252RF*/ #ifdef  AFC_VCXO
/*MT6252RF*/ #define  CLK_SETTLE_DEFAULT           CLK32K_MICRO_SECOND(5000)
/*MT6252RF*/ #define  PLL_RESET_DEFAULT            CLK32K_MICRO_SECOND(3500)
/*MT6252RF*/ #else
/*MT6252RF*/ #define  CLK_SETTLE_DEFAULT           CLK32K_MICRO_SECOND(4000)//3125
/*MT6252RF*/ #define  PLL_RESET_DEFAULT            CLK32K_MICRO_SECOND(3000)
/*MT6252RF*/ #endif
/*MT6252RF*/
/*MT6252RF*/ /*--------------------------------------------------------*/
/*MT6252RF*/ /*   BFE Setting                                          */
/*MT6252RF*/ /*--------------------------------------------------------*/
/*MT6252RF*/ #define  BBRX_IQ_SWAP                 0
/*MT6252RF*/ #define  BBRX_GAIN_DOUBLE             0
/*MT6252RF*/
/*MT6252RF*/ #define  BBTX_IQ_SWAP                 0 // Not Used, due to Direct Frequency Modulator (DFM) architecture.
/*MT6252RF*/ #define  BBTX_CALBIAS                 0 // Not Used, due to Direct Frequency Modulator (DFM) architecture.
/*MT6252RF*/ #define  BBTX_CALRCSEL                0 // Not Used, due to Direct Frequency Modulator (DFM) architecture.
/*MT6252RF*/ #define  BBTX_CALRCSEL_H              0 // Not Used, due to Direct Frequency Modulator (DFM) architecture.
/*MT6252RF*/ #define  BBTX_COMMON_MODE_VOLTAGE     0 // Not Used, due to Direct Frequency Modulator (DFM) architecture.
/*MT6252RF*/ #define  BBTX_COMMON_MODE_VOLTAGE_H   0 // Not Used, due to Direct Frequency Modulator (DFM) architecture.
/*MT6252RF*/ #define  BBTX_TRIM_I                  0 // Not Used, due to Direct Frequency Modulator (DFM) architecture.
/*MT6252RF*/ #define  BBTX_TRIM_I_H                0 // Not Used, due to Direct Frequency Modulator (DFM) architecture.
/*MT6252RF*/ #define  BBTX_TRIM_Q                  0 // Not Used, due to Direct Frequency Modulator (DFM) architecture.
/*MT6252RF*/ #define  BBTX_TRIM_Q_H                0 // Not Used, due to Direct Frequency Modulator (DFM) architecture.
/*MT6252RF*/ #define  BBTX_OFFSET_I                0 // Not Used, due to Direct Frequency Modulator (DFM) architecture.
/*MT6252RF*/ #define  BBTX_OFFSET_I_H              0 // Not Used, due to Direct Frequency Modulator (DFM) architecture.
/*MT6252RF*/ #define  BBTX_OFFSET_Q                0 // Not Used, due to Direct Frequency Modulator (DFM) architecture.
/*MT6252RF*/ #define  BBTX_OFFSET_Q_H              0 // Not Used, due to Direct Frequency Modulator (DFM) architecture.
/*MT6252RF*/ #define  BBTX_PHSEL                   0 // Not Used, due to Direct Frequency Modulator (DFM) architecture.
/*MT6252RF*/ #define  BBTX_PHSEL_H                 0 // Not Used, due to Direct Frequency Modulator (DFM) architecture.
/*MT6252RF*/ #define  BBTX_COARSGAIN               1 // Not Used, due to Direct Frequency Modulator (DFM) architecture.
/*MT6252RF*/ #define  BBTX_GAIN                    0 // Not Used, due to Direct Frequency Modulator (DFM) architecture.
/*MT6252RF*/ #define  BBTX_GAIN_H                  0 // Not Used, due to Direct Frequency Modulator (DFM) architecture.
/*MT6252RF*/ #define  BBTX_GAIN_SWING              900  /* mV */
/*MT6252RF*/
/*MT6252RF*/ /*--------------------------------------------------------*/
/*MT6252RF*/ /*   Define the CapID range                               */
/*MT6252RF*/ /*--------------------------------------------------------*/
/*MT6252RF*/ #define  CRYSTAL_CAPID_RANGE          127
/*MT6252RF*/
#endif
/*============================================================================== */

#if IS_RF_MT6256RF
/*MT6256RF*/
/*MT6256RF*/ /*--------------------------------------------------------*/
/*MT6256RF*/ /*   define SRCB data (shall be modified by real case)    */
/*MT6256RF*/ /*--------------------------------------------------------*/
/*MT6256RF*/
/*MT6256RF*/ #if IS_CHIP_MT6256_S00
/*MT6256RF*/ #define  SX0_DATA_COUNT               3
/*MT6256RF*/ #define  SX1_DATA_COUNT               1
/*MT6256RF*/ #define  SX2_DATA_COUNT               1
/*MT6256RF*/ #define  SX3_DATA_COUNT               1
/*MT6256RF*/ #define  ST2B_ST2M_DATA_COUNT         1
/*MT6256RF*/ #else
/*MT6256RF*/ #define  SX0_DATA_COUNT               3
/*MT6256RF*/ #define  SX1_DATA_COUNT               1
/*MT6256RF*/ #define  SX2_DATA_COUNT               2
/*MT6256RF*/ #define  SX3_DATA_COUNT               1
/*MT6256RF*/ #define  ST2B_ST2M_DATA_COUNT         2
/*MT6256RF*/ #endif
/*MT6256RF*/ #define  SCTRL_IDLE                   SCTRL_WORD(0,29)
/*MT6256RF*/ #define  SDATA_IDLE                   BSI_CW(0x02, 0x10000)
/*MT6256RF*/
/*MT6256RF*/ /* polarity:  0: long  enable positive pulse */
/*MT6256RF*/ /*            1: short enable positive pulse */
/*MT6256RF*/ /*            2: long  enable negative pulse */
/*MT6256RF*/ /*            3: short enable negative pulse */
/*MT6256RF*/ #define  BSI_DEVICE_0_CS_POLARITY     0
/*MT6256RF*/ #define  BSI_DEVICE_1_CS_POLARITY     0
/*MT6256RF*/
/*MT6256RF*/ /*--------------------------------------------------------*/
/*MT6256RF*/ /*   Sleep Mode Setting                                   */
/*MT6256RF*/ /*-------------------------------------------------------*/
/*MT6256RF*/
/*MT6256RF*/ #define  FM_DURATION_DEFAULT          8191
/*MT6256RF*/ #ifdef  AFC_VCXO
/*MT6256RF*/ #define  CLK_SETTLE_DEFAULT           CLK32K_MICRO_SECOND(5000)
/*MT6256RF*/ #define  PLL_RESET_DEFAULT            CLK32K_MICRO_SECOND(3500)
/*MT6256RF*/ #else
/*MT6256RF*/ #define  CLK_SETTLE_DEFAULT           CLK32K_MICRO_SECOND(4000)//3125
/*MT6256RF*/ #define  PLL_RESET_DEFAULT            CLK32K_MICRO_SECOND(3000)
/*MT6256RF*/ #endif
/*MT6256RF*/
/*MT6256RF*/ /*--------------------------------------------------------*/
/*MT6256RF*/ /*   BFE Legacy Setting (no use)                          */
/*MT6256RF*/ /*--------------------------------------------------------*/
/*MT6256RF*/ #define  BBRX_GAIN_DOUBLE             0
/*MT6256RF*/ #define  BBTX_IQ_SWAP                 0
/*MT6256RF*/ #define  BBTX_CALBIAS                 0
/*MT6256RF*/ #define  BBTX_CALRCSEL                0
/*MT6256RF*/ #define  BBTX_CALRCSEL_H              0
/*MT6256RF*/ #define  BBTX_COMMON_MODE_VOLTAGE     0 //COMMON MODE VOLTAGE: 1.5v
/*MT6256RF*/ #define  BBTX_COMMON_MODE_VOLTAGE_H   0 //COMMON MODE VOLTAGE: 1.5v
/*MT6256RF*/ #define  BBTX_TRIM_I                  0 // wait calibration
/*MT6256RF*/ #define  BBTX_TRIM_I_H                0 // wait calibration
/*MT6256RF*/ #define  BBTX_TRIM_Q                  0 // wait calibration
/*MT6256RF*/ #define  BBTX_TRIM_Q_H                0 // wait calibration
/*MT6256RF*/ #define  BBTX_OFFSET_I                0 // wait calibration
/*MT6256RF*/ #define  BBTX_OFFSET_I_H              0 // wait calibration
/*MT6256RF*/ #define  BBTX_OFFSET_Q                0 // wait calibration
/*MT6256RF*/ #define  BBTX_OFFSET_Q_H              0 // wait calibration
/*MT6256RF*/ #define  BBTX_PHSEL                   0 // wait calibration
/*MT6256RF*/ #define  BBTX_PHSEL_H                 0 // wait calibration
/*MT6256RF*/ #define  BBTX_COARSGAIN               0
/*MT6256RF*/ #define  BBTX_GAIN                    0 // get from experiment
/*MT6256RF*/ #define  BBTX_GAIN_H                  0 // get from experiment
/*MT6256RF*/ #define  BBTX_GAIN_SWING              900  /* mV */
/*MT6256RF*/
/*MT6256RF*/ /*--------------------------------------------------------*/
/*MT6256RF*/ /*   BFE Setting                                          */
/*MT6256RF*/ /*--------------------------------------------------------*/
/*MT6256RF*/ #define  BBRX_IQ_SWAP                 1
/*MT6256RF*/ #if IS_DYNAMIC_G_E_TXWIN_POSITION_SUPPORT_V2
/*MT6256RF*/ #define  TQ_EPSK_TX_DELAY             2
/*MT6256RF*/ #endif
/*MT6256RF*/
/*MT6256RF*/ /*--------------------------------------------------------*/
/*MT6256RF*/ /*   Define the CapID range                               */
/*MT6256RF*/ /*--------------------------------------------------------*/
/*MT6256RF*/ #define  CRYSTAL_CAPID_RANGE          255
/*MT6256RF*/
#endif

/*============================================================================== */

#if IS_RF_MT6255RF
/*MT6255RF*/
/*MT6255RF*/ /*--------------------------------------------------------*/
/*MT6255RF*/ /*   define SRCB data (shall be modified by real case)    */
/*MT6255RF*/ /*--------------------------------------------------------*/
/*MT6255RF*/
/*MT6255RF*/ #define  SX0_DATA_COUNT               3
/*MT6255RF*/ #define  SX1_DATA_COUNT               1
/*MT6255RF*/ #define  SX2_DATA_COUNT               2
/*MT6255RF*/ #define  SX3_DATA_COUNT               1
/*MT6255RF*/ #define  ST2B_ST2M_DATA_COUNT         2
/*MT6255RF*/ #define  SCTRL_IDLE                   SCTRL_WORD(0,29)
/*MT6255RF*/ #define  SDATA_IDLE                   BSI_CW(0x02, 0x10000)
/*MT6255RF*/
/*MT6255RF*/ /* polarity:  0: long  enable positive pulse */
/*MT6255RF*/ /*            1: short enable positive pulse */
/*MT6255RF*/ /*            2: long  enable negative pulse */
/*MT6255RF*/ /*            3: short enable negative pulse */
/*MT6255RF*/ #define  BSI_DEVICE_0_CS_POLARITY     0
/*MT6255RF*/ #define  BSI_DEVICE_1_CS_POLARITY     0
/*MT6255RF*/
/*MT6255RF*/ /*--------------------------------------------------------*/
/*MT6255RF*/ /*   Sleep Mode Setting                                   */
/*MT6255RF*/ /*--------------------------------------------------------*/
/*MT6255RF*/
/*MT6255RF*/ #define  FM_DURATION_DEFAULT          8191
/*MT6255RF*/ #ifdef  AFC_VCXO
/*MT6255RF*/ #define  CLK_SETTLE_DEFAULT           CLK32K_MICRO_SECOND(5000)
/*MT6255RF*/ #define  PLL_RESET_DEFAULT            CLK32K_MICRO_SECOND(3500)
/*MT6255RF*/ #else
/*MT6255RF*/ #define  CLK_SETTLE_DEFAULT           CLK32K_MICRO_SECOND(4000)//3125
/*MT6255RF*/ #define  PLL_RESET_DEFAULT            CLK32K_MICRO_SECOND(3000)
/*MT6255RF*/ #endif
/*MT6255RF*/
/*MT6255RF*/ /*--------------------------------------------------------*/
/*MT6255RF*/ /*   BFE Legacy Setting (no use)                          */
/*MT6255RF*/ /*--------------------------------------------------------*/
/*MT6255RF*/ #define  BBRX_GAIN_DOUBLE             0
/*MT6255RF*/ #define  BBTX_IQ_SWAP                 0
/*MT6255RF*/ #define  BBTX_CALBIAS                 0
/*MT6255RF*/ #define  BBTX_CALRCSEL                0
/*MT6255RF*/ #define  BBTX_CALRCSEL_H              0
/*MT6255RF*/ #define  BBTX_COMMON_MODE_VOLTAGE     0 //COMMON MODE VOLTAGE: 1.5v
/*MT6255RF*/ #define  BBTX_COMMON_MODE_VOLTAGE_H   0 //COMMON MODE VOLTAGE: 1.5v
/*MT6255RF*/ #define  BBTX_TRIM_I                  0 // wait calibration
/*MT6255RF*/ #define  BBTX_TRIM_I_H                0 // wait calibration
/*MT6255RF*/ #define  BBTX_TRIM_Q                  0 // wait calibration
/*MT6255RF*/ #define  BBTX_TRIM_Q_H                0 // wait calibration
/*MT6255RF*/ #define  BBTX_OFFSET_I                0 // wait calibration
/*MT6255RF*/ #define  BBTX_OFFSET_I_H              0 // wait calibration
/*MT6255RF*/ #define  BBTX_OFFSET_Q                0 // wait calibration
/*MT6255RF*/ #define  BBTX_OFFSET_Q_H              0 // wait calibration
/*MT6255RF*/ #define  BBTX_PHSEL                   0 // wait calibration
/*MT6255RF*/ #define  BBTX_PHSEL_H                 0 // wait calibration
/*MT6255RF*/ #define  BBTX_COARSGAIN               0
/*MT6255RF*/ #define  BBTX_GAIN                    0 // get from experiment
/*MT6255RF*/ #define  BBTX_GAIN_H                  0 // get from experiment
/*MT6255RF*/ #define  BBTX_GAIN_SWING              900  /* mV */
/*MT6255RF*/
/*MT6255RF*/ /*--------------------------------------------------------*/
/*MT6255RF*/ /*   BFE Setting                                          */
/*MT6255RF*/ /*--------------------------------------------------------*/
/*MT6255RF*/ #define  BBRX_IQ_SWAP                 1
/*MT6255RF*/
/*MT6255RF*/ /*--------------------------------------------------------*/
/*MT6255RF*/ /*   Define the CapID range                               */
/*MT6255RF*/ /*--------------------------------------------------------*/
/*MT6255RF*/ #define  CRYSTAL_CAPID_RANGE          255
/*MT6255RF*/
#endif

/*============================================================================== */

#if IS_RF_MT6251RF
/*MT6251RF*/
/*MT6251RF*/ /*--------------------------------------------------------*/
/*MT6251RF*/ /*   define SRCB data (shall be modified by real case)    */
/*MT6251RF*/ /*--------------------------------------------------------*/
/*MT6251RF*/
/*MT6251RF*/ #define  SX0_DATA_COUNT               2
/*MT6251RF*/ #define  SX1_DATA_COUNT               1
/*MT6251RF*/ #define  SX2_DATA_COUNT               1
/*MT6251RF*/ #define  SX3_DATA_COUNT               2
/*MT6251RF*/ #define  ST2B_ST2M_DATA_COUNT         1
/*MT6251RF*/ #define  SCTRL_IDLE                   SCTRL_WORD(0,29)
/*MT6251RF*/ #define  SDATA_IDLE                   0x0210000
/*MT6251RF*/
/*MT6251RF*/ /* polarity:  0: long  enable positive pulse */
/*MT6251RF*/ /*            1: short enable positive pulse */
/*MT6251RF*/ /*            2: long  enable negative pulse */
/*MT6251RF*/ /*            3: short enable negative pulse */
/*MT6251RF*/ #define  BSI_DEVICE_0_CS_POLARITY     0
/*MT6251RF*/ #define  BSI_DEVICE_1_CS_POLARITY     0
/*MT6251RF*/
/*MT6251RF*/ /*--------------------------------------------------------*/
/*MT6251RF*/ /*   Sleep Mode Setting                                   */
/*MT6251RF*/ /*-------------------------------------------------------*/
/*MT6251RF*/
/*MT6251RF*/ #define  FM_DURATION_DEFAULT          8191
/*MT6251RF*/ #ifdef  AFC_VCXO
/*MT6251RF*/ #define  CLK_SETTLE_DEFAULT           CLK32K_MICRO_SECOND(5000)
/*MT6251RF*/ #define  PLL_RESET_DEFAULT            CLK32K_MICRO_SECOND(3500)
/*MT6251RF*/ #else
/*MT6251RF*/ #define  CLK_SETTLE_DEFAULT           CLK32K_MICRO_SECOND(4000)//3125
/*MT6251RF*/ #define  PLL_RESET_DEFAULT            CLK32K_MICRO_SECOND(3000)
/*MT6251RF*/ #endif
/*MT6251RF*/
/*MT6251RF*/ /*--------------------------------------------------------*/
/*MT6251RF*/ /*   BFE Legacy Setting (no use)                          */
/*MT6251RF*/ /*--------------------------------------------------------*/
/*MT6251RF*/ #define  BBRX_GAIN_DOUBLE             0
/*MT6251RF*/
/*MT6251RF*/ #define  BBTX_IQ_SWAP                 0 // SWAP(do not swap at high side mixing 1900, swap at low side 850 900 1800)
/*MT6251RF*/ #define  BBTX_CALBIAS                 0
/*MT6251RF*/
/*MT6251RF*/ #define  BBTX_CALRCSEL                0
/*MT6251RF*/ #define  BBTX_CALRCSEL_H              0
/*MT6251RF*/ #define  BBTX_COMMON_MODE_VOLTAGE     0 // COMMON MODE VOLTAGE: 1.5v
/*MT6251RF*/ #define  BBTX_COMMON_MODE_VOLTAGE_H   0 // COMMON MODE VOLTAGE: 1.5v
/*MT6251RF*/ #define  BBTX_TRIM_I                  0 // wait calibration
/*MT6251RF*/ #define  BBTX_TRIM_I_H                0 // wait calibration
/*MT6251RF*/ #define  BBTX_TRIM_Q                  0 // wait calibration
/*MT6251RF*/ #define  BBTX_TRIM_Q_H                0 // wait calibration
/*MT6251RF*/ #define  BBTX_OFFSET_I                0 // wait calibration
/*MT6251RF*/ #define  BBTX_OFFSET_I_H              0 // wait calibration
/*MT6251RF*/ #define  BBTX_OFFSET_Q                0 // wait calibration
/*MT6251RF*/ #define  BBTX_OFFSET_Q_H              0 // wait calibration
/*MT6251RF*/ #define  BBTX_PHSEL                   0 // wait calibration
/*MT6251RF*/ #define  BBTX_PHSEL_H                 0 // wait calibration
/*MT6251RF*/ #define  BBTX_COARSGAIN               0 // no use?
/*MT6251RF*/ #define  BBTX_GAIN                    0 // get from experiment
/*MT6251RF*/ #define  BBTX_GAIN_H                  0 // get from experiment
/*MT6251RF*/ #define  BBTX_GAIN_SWING              900  /* mV */
/*MT6251RF*/
/*MT6251RF*/ /*--------------------------------------------------------*/
/*MT6251RF*/ /*   BFE Setting                                          */
/*MT6251RF*/ /*--------------------------------------------------------*/
/*MT6251RF*/ #define  BBRX_IQ_SWAP                 1
/*MT6251RF*/
/*MT6251RF*/ /*--------------------------------------------------------*/
/*MT6251RF*/ /*   Define the CapID range                               */
/*MT6251RF*/ /*--------------------------------------------------------*/
/*MT6251RF*/ #define  CRYSTAL_CAPID_RANGE          255
/*MT6251RF*/
#endif

/*============================================================================== */

#if IS_RF_SKY74045
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*SKY74045*/ #if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/* under construction !*/
/*SKY74045*/ #else
/* under construction !*/
/*SKY74045*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*SKY74045*/ #if IS_FPGA_TARGET || IS_CHIP_MT6208 || IS_CHIP_MT6205A || IS_CHIP_MT6218A
/* under construction !*/
/*SKY74045*/ #elif IS_CHIP_MT6205B || IS_CHIP_MT6218B_AN2DN
/* under construction !*/
/*SKY74045*/ #elif IS_CHIP_MT6218B_EN || IS_CHIP_MT6219_AV
/* under construction !*/
/*SKY74045*/ #else  /*MT6218BFN~ || MT6219BV~*/
/* under construction !*/
/*SKY74045*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*============================================================================== */

#if IS_RF_AERO2
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*AERO2*/ #if IS_FPGA_TARGET || IS_CHIP_MT6208 || IS_CHIP_MT6205A || IS_CHIP_MT6218A
/* under construction !*/
/*AERO2*/ #elif IS_CHIP_MT6205B || IS_CHIP_MT6218B_AN2DN
/* under construction !*/
/*AERO2*/ #elif IS_CHIP_MT6218B_EN || IS_CHIP_MT6219_AV
/* under construction !*/
/*AERO2*/ #else  /*MT6218BFN~ || MT6219BV~*/
/* under construction !*/
/*AERO2*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*============================================================================== */

#if IS_RF_SKY74137
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*SKY74137*/ #if IS_FPGA_TARGET || IS_CHIP_MT6208 || IS_CHIP_MT6205A || IS_CHIP_MT6218A
/* under construction !*/
/*SKY74137*/ #elif IS_CHIP_MT6205B || IS_CHIP_MT6218B_AN2DN || IS_CHIP_MT6229 || IS_CHIP_MT6268T
/* under construction !*/
/*SKY74137*/ #elif IS_CHIP_MT6218B_EN || IS_CHIP_MT6219_AV
/* under construction !*/
/*SKY74137*/ #else  /*MT6218BFN~ || MT6219BV~*/
/* under construction !*/
/*SKY74137*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*============================================================================== */

#if IS_RF_GRF6201
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*GRF6201*/ #ifdef  AFC_VCXO
/* under construction !*/
/* under construction !*/
/*GRF6201*/ #else
/* under construction !*/
/* under construction !*/
/*GRF6201*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*GRF6201*/ #if IS_FPGA_TARGET || IS_CHIP_MT6208 || IS_CHIP_MT6205A || IS_CHIP_MT6218A
/* under construction !*/
/*GRF6201*/ #elif IS_CHIP_MT6205B || IS_CHIP_MT6218B_AN2DN
/* under construction !*/
/*GRF6201*/ #elif IS_CHIP_MT6218B_EN || IS_CHIP_MT6219_AV
/* under construction !*/
/*GRF6201*/ #else  /*MT6218BFN~ || MT6219BV~*/
/* under construction !*/
/*GRF6201*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*============================================================================== */

#if IS_RF_IRFS3001
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*IRFS3001*/ #if defined(EXT_13M)
/* under construction !*/
/*IRFS3001*/ #elif defined(EXT_26M)
/* under construction !*/
/*IRFS3001*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*IRFS3001*/ #ifdef  AFC_VCXO
/* under construction !*/
/* under construction !*/
/*IRFS3001*/ #else
/* under construction !*/
/* under construction !*/
/*IRFS3001*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*IRFS3001*/ #if IS_CHIP_MT6227
/* under construction !*/
/*IRFS3001*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif // end of "#if IS_RF_IRFS3001"

/*============================================================================== */

#if IS_RF_AD6548
/*AD6548*/
/*AD6548*/ /*--------------------------------------------------------*/
/*AD6548*/ /*   define SRCB data (shall be modified by real case)    */
/*AD6548*/ /*--------------------------------------------------------*/
/*AD6548*/
/*AD6548*/ #define  SX1_DATA_COUNT               2
/*AD6548*/ #define  SX2_DATA_COUNT               2
/*AD6548*/ #define  SX3_DATA_COUNT               1
/*AD6548*/
/*AD6548*/ #define  SCTRL_IDLE                   SCTRL_WORD(0,18)
/*AD6548*/ #define  SDATA_IDLE                   0x000184 /* or 0x006624:Clear Mask operation */
/*AD6548*/
/*AD6548*/ /* polarity:  0: long  enable positive pulse */
/*AD6548*/ /*            1: short enable positive pulse */
/*AD6548*/ /*            2: long  enable negative pulse */
/*AD6548*/ /*            3: short enable negative pulse */
/*AD6548*/
/*AD6548*/ #if IS_BT_CO_CLOCK_HW_SUPPORT && IS_BT_COCLOCK_SUPPORT
/*AD6548*/ #define  BSI_DEVICE_0_CS_POLARITY     0
/*AD6548*/ #define  BSI_DEVICE_1_CS_POLARITY     0
/*AD6548*/ #else
/*AD6548*/ #define  BSI_DEVICE_0_CS_POLARITY     2
/*AD6548*/ #define  BSI_DEVICE_1_CS_POLARITY     2
/*AD6548*/ #endif
/*AD6548*/ /*--------------------------------------------------------*/
/*AD6548*/ /*   Sleep Mode Setting                                   */
/*AD6548*/ /*--------------------------------------------------------*/
/*AD6548*/
/*AD6548*/ #define  FM_DURATION_DEFAULT          8191
/*AD6548*/ #ifdef  AFC_VCXO
/*AD6548*/ #define  CLK_SETTLE_DEFAULT           CLK32K_MICRO_SECOND(5000)
/*AD6548*/ #define  PLL_RESET_DEFAULT            CLK32K_MICRO_SECOND(3500)
/*AD6548*/ #else
/*AD6548*/ #define  CLK_SETTLE_DEFAULT           CLK32K_MICRO_SECOND(4000)//3125
/*AD6548*/ #define  PLL_RESET_DEFAULT            CLK32K_MICRO_SECOND(3000)
/*AD6548*/ #endif
/*AD6548*/
/*AD6548*/ /*--------------------------------------------------------*/
/*AD6548*/ /*   BFE Setting                                          */
/*AD6548*/ /*--------------------------------------------------------*/
/*AD6548*/ #define  BBRX_IQ_SWAP                 1
/*AD6548*/ #define  BBRX_GAIN_DOUBLE             0 //AVDD*0.8 = 2.24v
/*AD6548*/
/*AD6548*/ #define  BBTX_IQ_SWAP                 1
/*AD6548*/ #define  BBTX_CALBIAS                 0
/*AD6548*/
/*AD6548*/ #define  BBTX_CALRCSEL               -2 //Cut-off frequency of TX filter
/*AD6548*/ #if IS_BBTXRX_CHIP_DESIGN_VER_2 && IS_CHIP_MT6575
/*AD6548*/ #define  BBTX_COMMON_MODE_VOLTAGE     1 //0: 1.1V, 1: 1.2V
/*AD6548*/ #else
/*AD6548*/ #define  BBTX_COMMON_MODE_VOLTAGE    -2 //AVDD*0.42=2.8*0.42=1.18V
/*AD6548*/ #endif
/*AD6548*/ #define  BBTX_TRIM_I                  0
/*AD6548*/ #define  BBTX_TRIM_Q                  0
/*AD6548*/ #define  BBTX_OFFSET_I                0
/*AD6548*/ #define  BBTX_OFFSET_Q                0
/*AD6548*/ #define  BBTX_PHSEL                   0 //-4
/*AD6548*/
/*AD6548*/ #define  BBTX_RPSEL                   1 //EDGE: Interpolation mode
/*AD6548*/ #define  BBTX_INTEN                   1
/*AD6548*/ #define  BBTX_SW_QBCNT               28
/*AD6548*/ #define  BBTX_COARSGAIN               1
/*AD6548*/
/*AD6548*/
/*AD6548*/ #if IS_FPGA_TARGET || IS_CHIP_MT6208 || IS_CHIP_MT6205A || IS_CHIP_MT6218A
/*AD6548*/ #define  BBTX_GAIN                   -1
/*AD6548*/ #elif IS_CHIP_MT6205B || IS_CHIP_MT6218B_AN2DN
/*AD6548*/ #define  BBTX_GAIN                   -2
/*AD6548*/ #elif IS_CHIP_MT6218B_EN || IS_CHIP_MT6219_AV
/*AD6548*/ #define  BBTX_GAIN                    3
/*AD6548*/ #else  /*MT6218BFN~ || MT6219BV~*/
/*AD6548*/ #define  BBTX_GAIN                   -3
/*AD6548*/ #endif
/*AD6548*/
/*AD6548*/ #define  BBTX_GAIN_SWING              1000  /* mV */
/*AD6548*/
/*AD6548*/ /*--------------------------------------------------------*/
/*AD6548*/ /*   Define the CapID range                               */
/*AD6548*/ /*--------------------------------------------------------*/
/*AD6548*/ #define  CRYSTAL_CAPID_RANGE          63
/*AD6548*/
#endif

/*============================================================================== */

#if IS_RF_AD6546
/*AD6546*/
/*AD6546*/ /*--------------------------------------------------------*/
/*AD6546*/ /*   define SRCB data (shall be modified by real case)    */
/*AD6546*/ /*--------------------------------------------------------*/
/*AD6546*/
/*AD6546*/ #define  SX0_DATA_COUNT              0
/*AD6546*/ #define  SX1_DATA_COUNT              2
   #if IS_BSI_V2_SUPPORT
/*AD6546*/ #define  SX2_DATA_COUNT              3
   #else
/*AD6546*/ #define  SX2_DATA_COUNT              2
   #endif
/*AD6546*/ #define  SX3_DATA_COUNT              1
/*AD6546*/ #define  ST2B_ST2M_DATA_COUNT        3
/*AD6546*/
/*AD6546*/ #define  SCTRL_IDLE                  SCTRL_WORD(0,18)
/*AD6546*/ #define  SDATA_IDLE                  0x000184 /* or 0x006624:Clear Mask operation */
/*AD6546*/
/*AD6546*/ /* polarity:  0: long  enable positive pulse */
/*AD6546*/ /*            1: short enable positive pulse */
/*AD6546*/ /*            2: long  enable negative pulse */
/*AD6546*/ /*            3: short enable negative pulse */
/*AD6546*/
/*AD6546*/ #if IS_BT_CO_CLOCK_HW_SUPPORT && IS_BT_COCLOCK_SUPPORT
/*AD6546*/ #define  BSI_DEVICE_0_CS_POLARITY    0
/*AD6546*/ #define  BSI_DEVICE_1_CS_POLARITY    0
/*AD6546*/ #else
/*AD6546*/ #define  BSI_DEVICE_0_CS_POLARITY    2
/*AD6546*/ #define  BSI_DEVICE_1_CS_POLARITY    2
/*AD6546*/ #endif
/*AD6546*/
/*AD6546*/ #define  IS_BSI_DATA_TABLE_Y_SHIFT   1
/*AD6546*/ /*--------------------------------------------------------*/
/*AD6546*/ /*   Sleep Mode Setting                                   */
/*AD6546*/ /*-------------------------------------------------------*/
/*AD6546*/
/*AD6546*/ #define  FM_DURATION_DEFAULT         8191
/*AD6546*/ #ifdef  AFC_VCXO
/*AD6546*/ #define  CLK_SETTLE_DEFAULT          CLK32K_MICRO_SECOND(5000)
/*AD6546*/ #define  PLL_RESET_DEFAULT           CLK32K_MICRO_SECOND(3500)
/*AD6546*/ #else
/*AD6546*/ #define  CLK_SETTLE_DEFAULT          CLK32K_MICRO_SECOND(4000)//3125
/*AD6546*/ #define  PLL_RESET_DEFAULT           CLK32K_MICRO_SECOND(3000)
/*AD6546*/ #endif
/*AD6546*/
/*AD6546*/ /*--------------------------------------------------------*/
/*AD6546*/ /*   BFE Setting                                          */
/*AD6546*/ /*--------------------------------------------------------*/
/*AD6546*/ #define  BBRX_IQ_SWAP                1
/*AD6546*/ #define  BBRX_GAIN_DOUBLE            0 //AVDD*0.8 = 2.24v
/*AD6546*/
/*AD6546*/ #define  BBTX_IQ_SWAP                1
/*AD6546*/ #define  BBTX_CALBIAS                0 // min current 0.5mA 0 // set to 7 for max driven current for OE (2 mA but OE need 3mA)0
/*AD6546*/
/*AD6546*/ #define  BBTX_CALRCSEL              -2 //Cut-off frequency of TX filter
/*AD6546*/ #if IS_BBTXRX_CHIP_DESIGN_VER_2
/*AD6546*/ #define  BBTX_COMMON_MODE_VOLTAGE    1 //0: 1.1V, 1: 1.2V
/*AD6546*/ #else
/*AD6546*/ #define  BBTX_COMMON_MODE_VOLTAGE   -2 //AVDD*0.42=2.8*0.42=1.18V
/*AD6546*/ #endif
/*AD6546*/ #define  BBTX_TRIM_I                 0
/*AD6546*/ #define  BBTX_TRIM_Q                 0
/*AD6546*/ #define  BBTX_OFFSET_I               0
/*AD6546*/ #define  BBTX_OFFSET_Q               0
/*AD6546*/ #define  BBTX_PHSEL                  0 //-4
/*AD6546*/
/*AD6546*/ #define  BBTX_RPSEL                  0 //EDGE: Interpolation mode
/*AD6546*/ #define  BBTX_INTEN                  1 //EDGE: Interpolation ON/OFF
/*AD6546*/ #define  BBTX_SW_QBCNT              28
/*AD6546*/ #define  BBTX_COARSGAIN              1
/*AD6546*/ #if IS_BBTXRX_CHIP_DESIGN_VER_2
/*AD6546*/ #define  BBTX_GAIN_COMP              0
/*AD6546*/ #define  BBTX_PHSEL_I                0
/*AD6546*/ #define  BBTX_PHSEL_Q                0
/*AD6546*/ #define  BBTX_IQGAIN_SEL             0 // gain compensation on I
/*AD6546*/ #endif
/*AD6546*/
/*AD6546*/ #if IS_FPGA_TARGET || IS_CHIP_MT6208 || IS_CHIP_MT6205A || IS_CHIP_MT6218A
/*AD6546*/ #define  BBTX_GAIN                  -1
/*AD6546*/ #elif IS_CHIP_MT6205B || IS_CHIP_MT6218B_AN2DN
/*AD6546*/ #define  BBTX_GAIN                  -2
/*AD6546*/ #elif IS_CHIP_MT6218B_EN || IS_CHIP_MT6219_AV
/*AD6546*/ #define  BBTX_GAIN                   3
/*AD6546*/ #else  /*MT6218BFN~ || MT6219BV~*/
/*AD6546*/ #define  BBTX_GAIN                  -3
/*AD6546*/ #endif
/*AD6546*/
/*AD6546*/ #define  BBTX_GAIN_SWING             1000  /* mV */
/*AD6546*/
/*AD6546*/ /*--------------------------------------------------------*/
/*AD6546*/ /*   Define the CapID range                               */
/*AD6546*/ /*--------------------------------------------------------*/
/*AD6546*/ #define  CRYSTAL_CAPID_RANGE         63
/*AD6546*/
#endif

/*============================================================================== */

#if IS_RF_MT6162
/*MT6162*/
/*MT6162*/ /*--------------------------------------------------------*/
/*MT6162*/ /*   define SRCB data (shall be modified by real case)    */
/*MT6162*/ /*--------------------------------------------------------*/
/*MT6162*/ #if IS_DCXO_ENABLE
/*MT6162*/ #define  SX0_DATA_COUNT              5
/*MT6162*/ #else
/*MT6162*/ #define  SX0_DATA_COUNT              4
/*MT6162*/ #endif
/*MT6162*/ #define  SX1_DATA_COUNT              3
/*MT6162*/ #define  SX2_DATA_COUNT              4
/*MT6162*/ #define  ST2B_ST2M_DATA_COUNT        4
/*MT6162*/ #define  SX3_DATA_COUNT              3
/*MT6162*/
/*MT6162*/ #define  SCTRL_IDLE                  SCTRL_WORD(0,30)
/*MT6162*/ #define  SDATA_IDLE                  0x08100000L
/*MT6162*/ #define  SDATA_IDLE_1                0x0D120001L
/*MT6162*/
/*MT6162*/ /* ENX_POL + ENX_LEN */
/*MT6162*/ /*       0 + 00 (0) : long  enable true     polarity pulse */
/*MT6162*/ /*       0 + 01 (1) : short enable true     polarity pulse */
/*MT6162*/ /*       0 + 10 (2) : long  enable true     polarity pulse aligned with data output */
/*MT6162*/ /*       1 + 00 (4) : long  enable inverted polarity pulse */
/*MT6162*/ /*       1 + 01 (5) : short enable inverted polarity pulse */
/*MT6162*/ /*       1 + 10 (6) : long  enable inverted polarity pulse aligned with data output */
/*MT6162*/ #define  BSI_DEVICE_0_CS_POLARITY    4
/*MT6162*/ #define  BSI_DEVICE_1_CS_POLARITY    4
/*MT6162*/
/*MT6162*/ /*--------------------------------------------------------*/
/*MT6162*/ /*   Sleep Mode Setting                                   */
/*MT6162*/ /*--------------------------------------------------------*/
/*MT6162*/
/*MT6162*/ #define  FM_DURATION_DEFAULT         8191
/*MT6162*/ #ifdef  AFC_VCXO
/*MT6162*/ #define  CLK_SETTLE_DEFAULT          CLK32K_MICRO_SECOND(5000)
/*MT6162*/ #define  PLL_RESET_DEFAULT           CLK32K_MICRO_SECOND(3500)
/*MT6162*/ #else
/*MT6162*/ #define  CLK_SETTLE_DEFAULT          CLK32K_MICRO_SECOND(4000)//3125
/*MT6162*/ #define  PLL_RESET_DEFAULT           CLK32K_MICRO_SECOND(3000)
/*MT6162*/ #endif
/*MT6162*/
/*MT6162*/ /*--------------------------------------------------------*/
/*MT6162*/ /*   BFE Setting                                          */
/*MT6162*/ /*--------------------------------------------------------*/
/*MT6162*/ #define  BBRX_IQ_SWAP                0 /* no IQSWAP in OH */
/*MT6162*/ #define  BBRX_GAIN_DOUBLE            0 /* AVDD*0.8 = 2.24v */
/*MT6162*/
/*MT6162*/ #define  BBTX_IQ_SWAP                0 /* no IQSWAP in DFM */
/*MT6162*/ #define  BBTX_CALBIAS                0 /* min current 0.5mA */
/*MT6162*/
/*MT6162*/ #define  BBTX_CALRCSEL              -2 /* Cut-off frequency of TX filter */
/*MT6162*/ #if IS_BBTXRX_CHIP_DESIGN_VER_2
/*MT6162*/ #define  BBTX_COMMON_MODE_VOLTAGE    0 /* 0: 1.1V, 1: 1.2V */
/*MT6162*/ #else
/*MT6162*/ #define  BBTX_COMMON_MODE_VOLTAGE   -2 /* AVDD*0.42=2.8*0.42=1.18V */
/*MT6162*/ #endif
/*MT6162*/ #define  BBTX_TRIM_I                 0
/*MT6162*/ #define  BBTX_TRIM_Q                 0
/*MT6162*/ #define  BBTX_OFFSET_I               0
/*MT6162*/ #define  BBTX_OFFSET_Q               0
/*MT6162*/ #define  BBTX_PHSEL                  0
/*MT6162*/
/*MT6162*/ #define  BBTX_RPSEL                  1 /* EDGE: Interpolation mode */
/*MT6162*/ #define  BBTX_INTEN                  1 /* EDGE: Interpolation ON/OFF */
/*MT6162*/ #define  BBTX_SW_QBCNT              28
/*MT6162*/ #define  BBTX_COARSGAIN              1
/*MT6162*/
/*MT6162*/ #define  BBTX_GAIN_COMP              0
/*MT6162*/ #define  BBTX_PHSEL_I                0
/*MT6162*/ #define  BBTX_PHSEL_Q                0
/*MT6162*/ #define  BBTX_IQGAIN_SEL             0 /* gain compensation on I */
/*MT6162*/
/*MT6162*/ #define  BBTX_EPSK_DTAP_SYM          0 /* set 2 to match the output latency offset between GMSK(DFM)/EPSK(DCT) modulator */
/*MT6162*/
/*MT6162*/ #define  BBTX_GAIN                  -3
/*MT6162*/ #define  BBTX_GAIN_SWING           990 /* mV */
/*MT6162*/
/*MT6162*/ #if IS_DYNAMIC_G_E_TXWIN_POSITION_SUPPORT
/*MT6162*/ #define  TQ_EPSK_TX_DELAY            7 /* Qb, The EPSK signal is 7Qb behind the GMSK signal due to the different path */
/*MT6162*/                                        /* GMSK (DFM) is on the BSI path, and EPSK (DCT) is on the I/Q path            */
/*MT6162*/ #else
/*MT6162*/ #define  TQ_EPSK_TX_DELAY            0
/*MT6162*/ #endif
/*MT6162*/
/*MT6162*/ /*--------------------------------------------------------*/
/*MT6162*/ /*   Define band mode mapped receiver type                */
/*MT6162*/ /*   DO NOT MODIFY the definitions here.                  */
/*MT6162*/ /*--------------------------------------------------------*/
/*MT6162*/ #define  LNA_1                       0x0
/*MT6162*/ #define  LNA_2                       0x1
/*MT6162*/ #define  LNA_3                       0x2
/*MT6162*/ #define  LNA_4                       0x3
/*MT6162*/ #define  LNA_5                       0x4
/*MT6162*/ #define  LNA_6                       0x5
/*MT6162*/ #define  LNA_7                       0x6
/*MT6162*/ #define  LNA_8                       0x7
/*MT6162*/ #define  NO_USE_BAND                 0xF
/*MT6162*/
/*MT6162*/ /*--------------------------------------------------------*/
/*MT6162*/ /*   Define the CapID range                               */
/*MT6162*/ /*--------------------------------------------------------*/
/*MT6162*/ #define  CRYSTAL_CAPID_RANGE         255
/*MT6162*/
#endif

/*============================================================================== */

#if IS_RF_MT6163
/*MT6163*/
/*MT6163*/ /*--------------------------------------------------------*/
/*MT6163*/ /*   define SRCB data (shall be modified by real case)    */
/*MT6163*/ /*--------------------------------------------------------*/
/*MT6163*/ #if IS_DCXO_ENABLE
/*MT6163*/ #define  SX0_DATA_COUNT_DCXO         1
/*MT6163*/ #else
/*MT6163*/ #define  SX0_DATA_COUNT_DCXO         0
/*MT6163*/ #endif
/*MT6163*/
/*MT6163*/ #if IS_BSI_TRIG_OFFCHIP_BPI_SUPPORT || IS_BSI_TRIG_OFFCHIP_BSI_SWITCH_SUPPORT
/*MT6163*/ #define  SX0_DATA_COUNT_BPI          1
/*MT6163*/ #define  SX3_DATA_COUNT_BPI          1
/*MT6163*/ #else
/*MT6163*/ #define  SX0_DATA_COUNT_BPI          0
/*MT6163*/ #define  SX3_DATA_COUNT_BPI          0
/*MT6163*/ #endif
/*MT6163*/
/*MT6163*/ #define  SX0_DATA_COUNT              (4 + SX0_DATA_COUNT_DCXO + SX0_DATA_COUNT_BPI)
/*MT6163*/ #define  SX1_DATA_COUNT              3
/*MT6163*/ #define  SX2_DATA_COUNT              4
/*MT6163*/ #define  ST2B_ST2M_DATA_COUNT        4
/*MT6163*/ #define  SX3_DATA_COUNT              (3 + SX3_DATA_COUNT_BPI)
/*MT6163*/
/*MT6163*/ #define  SCTRL_IDLE                  SCTRL_WORD(0,30)
/*MT6163*/ #define  SDATA_IDLE                  0x00203000L
/*MT6163*/ #define  SDATA_IDLE_1                0x0D100508L
/*MT6163*/
/*MT6163*/ /* ENX_POL + ENX_LEN */
/*MT6163*/ /*       0 + 00 (0) : long  enable true     polarity pulse */
/*MT6163*/ /*       0 + 01 (1) : short enable true     polarity pulse */
/*MT6163*/ /*       0 + 10 (2) : long  enable true     polarity pulse aligned with data output */
/*MT6163*/ /*       1 + 00 (4) : long  enable inverted polarity pulse */
/*MT6163*/ /*       1 + 01 (5) : short enable inverted polarity pulse */
/*MT6163*/ /*       1 + 10 (6) : long  enable inverted polarity pulse aligned with data output */
/*MT6163*/ #define  BSI_DEVICE_0_CS_POLARITY    4
/*MT6163*/ #define  BSI_DEVICE_1_CS_POLARITY    4
/*MT6163*/
/*MT6163*/ /*--------------------------------------------------------*/
/*MT6163*/ /*   Sleep Mode Setting                                   */
/*MT6163*/ /*--------------------------------------------------------*/
/*MT6163*/
/*MT6163*/ #define  FM_DURATION_DEFAULT         8191
/*MT6163*/ #ifdef  AFC_VCXO
/*MT6163*/    #if IS_CHIP_MT6583_MD2
/*MT6163*/ #define  CLK_SETTLE_DEFAULT          CLK32K_MICRO_SECOND(3094)//3ms
/*MT6163*/    #else
/*MT6163*/ #define  CLK_SETTLE_DEFAULT          CLK32K_MICRO_SECOND(5000)
/*MT6163*/    #endif
/*MT6163*/ #define  PLL_RESET_DEFAULT           CLK32K_MICRO_SECOND(3500)
/*MT6163*/ #else
/*MT6163*/    #if IS_CHIP_MT6583_MD2
/*MT6163*/ #define  CLK_SETTLE_DEFAULT          CLK32K_MICRO_SECOND(3094)//3ms
/*MT6163*/    #else
/*MT6163*/ #define  CLK_SETTLE_DEFAULT          CLK32K_MICRO_SECOND(4000)//3125
/*MT6163*/    #endif
/*MT6163*/ #define  PLL_RESET_DEFAULT           CLK32K_MICRO_SECOND(3000)
/*MT6163*/ #endif
/*MT6163*/
/*MT6163*/ /*--------------------------------------------------------*/
/*MT6163*/ /*   BFE Setting                                          */
/*MT6163*/ /*--------------------------------------------------------*/
/*MT6163*/ #define  BBRX_IQ_SWAP                0 /* No IQSWAP on OT */
/*MT6163*/ #define  BBRX_GAIN_DOUBLE            0 /* AVDD*0.8 = 2.24v */
/*MT6163*/
/*MT6163*/ #define  BBTX_IQ_SWAP                0 /* no IQSWAP in DFM */
/*MT6163*/ #define  BBTX_CALBIAS                0 /* min current 0.5mA */
/*MT6163*/
/*MT6163*/ #define  BBTX_CALRCSEL              -2 /* Cut-off frequency of TX filter */
/*MT6163*/ #if IS_BBTXRX_CHIP_DESIGN_VER_2 || IS_BBTXRX_CHIP_DESIGN_VER_3
/*MT6163*/ #define  BBTX_COMMON_MODE_VOLTAGE    0 /* 0: 1.1V, 1: 1.2V */
/*MT6163*/ #else
/*MT6163*/ #define  BBTX_COMMON_MODE_VOLTAGE   -2 /* AVDD*0.42=2.8*0.42=1.18V */
/*MT6163*/ #endif
/*MT6163*/ #define  BBTX_TRIM_I                 0
/*MT6163*/ #define  BBTX_TRIM_Q                 0
/*MT6163*/ #define  BBTX_OFFSET_I               0
/*MT6163*/ #define  BBTX_OFFSET_Q               0
/*MT6163*/ #define  BBTX_PHSEL                  0
/*MT6163*/
/*MT6163*/ #define  BBTX_RPSEL                  1 /* EDGE: Interpolation mode */
/*MT6163*/ #define  BBTX_INTEN                  1 /* EDGE: Interpolation ON/OFF */
/*MT6163*/ #define  BBTX_SW_QBCNT              28
/*MT6163*/ #define  BBTX_COARSGAIN              1
/*MT6163*/
/*MT6163*/ #define  BBTX_GAIN_COMP              0
/*MT6163*/ #define  BBTX_PHSEL_I                0
/*MT6163*/ #define  BBTX_PHSEL_Q                0
/*MT6163*/ #define  BBTX_IQGAIN_SEL             0 /* gain compensation on I */
/*MT6163*/
/*MT6163*/ #define  BBTX_EPSK_DTAP_SYM          0 /* set 2 to match the output latency offset between GMSK(DFM)/EPSK(DCT) modulator */
/*MT6163*/
/*MT6163*/ #define  BBTX_GAIN                  -3
/*MT6163*/ #define  BBTX_GAIN_SWING           990 /* mV */
/*MT6163*/
/*MT6163*/ #if IS_DYNAMIC_G_E_TXWIN_POSITION_SUPPORT
/*MT6163*/ #define  TQ_EPSK_TX_DELAY            8 /* EPSK TX signal propagation delay is 8 Qb less than GMSK signal           */
/*MT6163*/                                        /* due to path difference: GMSK (DFM) on BSI path, EPSK (DCT) on I/Q path.  */
/*MT6163*/ #else
/*MT6163*/ #define  TQ_EPSK_TX_DELAY            0
/*MT6163*/ #endif
/*MT6163*/
/*MT6163*/ /*--------------------------------------------------------*/
/*MT6163*/ /*   Define band mode mapped receiver type                */
/*MT6163*/ /*   DO NOT MODIFY the definitions here.                  */
/*MT6163*/ /*--------------------------------------------------------*/
/*MT6163*/ #define  LNA_1                       0x0
/*MT6163*/ #define  LNA_2                       0x1
/*MT6163*/ #define  LNA_3                       0x2
/*MT6163*/ #define  LNA_4                       0x3
/*MT6163*/ #define  LNA_5                       0x4
/*MT6163*/ #define  LNA_6                       0x5
/*MT6163*/ #define  LNA_7                       0x6
/*MT6163*/ #define  NO_USE_BAND                 0xF
/*MT6163*/
/*MT6163*/ /*--------------------------------------------------------*/
/*MT6163*/ /*   Define the CapID range                               */
/*MT6163*/ /*--------------------------------------------------------*/
/*MT6163*/ #define  CRYSTAL_CAPID_RANGE         255
/*MT6163*/
#endif

/*============================================================================== */

#if IS_RF_MT6280RF
/*MT6280RF*/
/*MT6280RF*/ /*--------------------------------------------------------*/
/*MT6280RF*/ /*   define SRCB data (shall be modified by real case)    */
/*MT6280RF*/ /*--------------------------------------------------------*/
/*MT6280RF*/
/*MT6280RF*/ #if IS_CHIP_MT6280_S00
/*MT6280RF*/ #define  SX0_DATA_COUNT               0
/*MT6280RF*/ #define  SX1_DATA_COUNT              11
/*MT6280RF*/ #define  SX2_DATA_COUNT               4
/*MT6280RF*/ #define  SX3_DATA_COUNT               3
/*MT6280RF*/ #define  ST2B_ST2M_DATA_COUNT         4
/*MT6280RF*/ #else
/*MT6280RF*/ #define  SX0_DATA_COUNT               0
/*MT6280RF*/ #define  SX1_DATA_COUNT              11
/*MT6280RF*/ #define  SX2_DATA_COUNT               4
/*MT6280RF*/ #define  SX3_DATA_COUNT               3
/*MT6280RF*/ #define  ST2B_ST2M_DATA_COUNT         4
/*MT6280RF*/ #endif
/*MT6280RF*/ #define  SCTRL_IDLE                   SCTRL_WORD(0,29)
/*MT6280RF*/ #define  SDATA_IDLE                   BSI_CW(0x01, 0x00200)
/*MT6280RF*/
/*MT6280RF*/ /* polarity:  0: long  enable positive pulse */
/*MT6280RF*/ /*            1: short enable positive pulse */
/*MT6280RF*/ /*            2: long  enable negative pulse */
/*MT6280RF*/ /*            3: short enable negative pulse */
/*MT6280RF*/ #define  BSI_DEVICE_0_CS_POLARITY     0
/*MT6280RF*/ #define  BSI_DEVICE_1_CS_POLARITY     0
/*MT6280RF*/
/*MT6280RF*/ /*--------------------------------------------------------*/
/*MT6280RF*/ /*   Sleep Mode Setting                                   */
/*MT6280RF*/ /*-------------------------------------------------------*/
/*MT6280RF*/
/*MT6280RF*/ #define  FM_DURATION_DEFAULT          8191
/*MT6280RF*/ #ifdef  AFC_VCXO
/*MT6280RF*/ #define  CLK_SETTLE_DEFAULT           CLK32K_MICRO_SECOND(2000)
/*MT6280RF*/ #define  PLL_RESET_DEFAULT            CLK32K_MICRO_SECOND(3500)
/*MT6280RF*/ #else
/*MT6280RF*/ #define  CLK_SETTLE_DEFAULT           CLK32K_MICRO_SECOND(4000)//3125
/*MT6280RF*/ #define  PLL_RESET_DEFAULT            CLK32K_MICRO_SECOND(3000)
/*MT6280RF*/ #endif
/*MT6280RF*/
/*MT6280RF*/ /*--------------------------------------------------------*/
/*MT6280RF*/ /*   BFE Legacy Setting (no use)                          */
/*MT6280RF*/ /*--------------------------------------------------------*/
/*MT6280RF*/ #define  BBRX_GAIN_DOUBLE             0
/*MT6280RF*/ #define  BBTX_IQ_SWAP                 0
/*MT6280RF*/ #define  BBTX_CALBIAS                 0
/*MT6280RF*/ #define  BBTX_CALRCSEL                0
/*MT6280RF*/ #define  BBTX_CALRCSEL_H              0
/*MT6280RF*/ #define  BBTX_COMMON_MODE_VOLTAGE     0 //COMMON MODE VOLTAGE: 1.5v
/*MT6280RF*/ #define  BBTX_COMMON_MODE_VOLTAGE_H   0 //COMMON MODE VOLTAGE: 1.5v
/*MT6280RF*/ #define  BBTX_TRIM_I                  0 // wait calibration
/*MT6280RF*/ #define  BBTX_TRIM_I_H                0 // wait calibration
/*MT6280RF*/ #define  BBTX_TRIM_Q                  0 // wait calibration
/*MT6280RF*/ #define  BBTX_TRIM_Q_H                0 // wait calibration
/*MT6280RF*/ #define  BBTX_OFFSET_I                0 // wait calibration
/*MT6280RF*/ #define  BBTX_OFFSET_I_H              0 // wait calibration
/*MT6280RF*/ #define  BBTX_OFFSET_Q                0 // wait calibration
/*MT6280RF*/ #define  BBTX_OFFSET_Q_H              0 // wait calibration
/*MT6280RF*/ #define  BBTX_PHSEL                   0 // wait calibration
/*MT6280RF*/ #define  BBTX_PHSEL_H                 0 // wait calibration
/*MT6280RF*/ #define  BBTX_COARSGAIN               0
/*MT6280RF*/ #define  BBTX_GAIN                    0 // get from experiment
/*MT6280RF*/ #define  BBTX_GAIN_H                  0 // get from experiment
/*MT6280RF*/ #define  BBTX_GAIN_SWING              900  /* mV */
/*MT6280RF*/
/*MT6280RF*/ /*--------------------------------------------------------*/
/*MT6280RF*/ /*   BFE Setting                                          */
/*MT6280RF*/ /*--------------------------------------------------------*/
/*MT6280RF*/ #define  BBRX_IQ_SWAP                 0
/*MT6280RF*/
/*MT6280RF*/ /*--------------------------------------------------------*/
/*MT6280RF*/ /*   Define band mode mapped receiver type                */
/*MT6280RF*/ /*   DO NOT MODIFY the definitions here.                  */
/*MT6280RF*/ /*--------------------------------------------------------*/
/*MT6280RF*/ #define  RX_MAIN_PATH_OFF            0x0
/*MT6280RF*/ #define  LNA_1                       0x1
/*MT6280RF*/ #define  LNA_2                       0x2
/*MT6280RF*/ #define  LNA_3                       0x3
/*MT6280RF*/ #define  LNA_4                       0x4
/*MT6280RF*/ #define  LNA_5                       0x5
/*MT6280RF*/
/*MT6280RF*/ /*--------------------------------------------------------*/
/*MT6280RF*/ /*   Define the CapID range                               */
/*MT6280RF*/ /*--------------------------------------------------------*/
/*MT6280RF*/ #define  CRYSTAL_CAPID_RANGE          255
/*MT6280RF*/
/*MT6280RF*/ /*----------------------------------------------*/
/*MT6280RF*/ /*   Define Q-path on/off                       */
/*MT6280RF*/ /*----------------------------------------------*/
/*MT6280RF*/ #ifndef IS_Q_PATH_ON
/*MT6280RF*/ #define IS_Q_PATH_ON                    0
/*MT6280RF*/ #endif
#endif

/*============================================================================== */

#if IS_RF_MT6167
/*MT6167*/
/*MT6167*/ /*--------------------------------------------------------*/
/*MT6167*/ /*   define SRCB data (shall be modified by real case)    */
/*MT6167*/ /*--------------------------------------------------------*/
/*MT6167*/
/*MT6167*/ #define  SX0_DATA_COUNT               9
/*MT6167*/ #define  SX1_DATA_COUNT               1
/*MT6167*/ #define  SX2_DATA_COUNT               3
/*MT6167*/ #define  SX3_DATA_COUNT               2
/*MT6167*/ #define  ST2B_ST2M_DATA_COUNT         3
/*MT6167*/ #define  SCTRL_IDLE                   SCTRL_WORD(0,30)
/*MT6167*/ #define  SDATA_IDLE                   BSI_CW(0x01, 0x00200)
/*MT6167*/
/*MT6167*/ /* polarity:  0: long  enable positive pulse */
/*MT6167*/ /*            1: short enable positive pulse */
/*MT6167*/ /*            2: long  enable negative pulse */
/*MT6167*/ /*            3: short enable negative pulse */
/*MT6167*/ #define  BSI_DEVICE_0_CS_POLARITY     0
/*MT6167*/ #define  BSI_DEVICE_1_CS_POLARITY     0
/*MT6167*/
/*MT6167*/ /*--------------------------------------------------------*/
/*MT6167*/ /*   Sleep Mode Setting                                   */
/*MT6167*/ /*-------------------------------------------------------*/
/*MT6167*/
/*MT6167*/ #define  FM_DURATION_DEFAULT          8191
/*MT6167*/ #ifdef  AFC_VCXO
/*MT6167*/ #define  CLK_SETTLE_DEFAULT           CLK32K_MICRO_SECOND(2063)//2ms
/*MT6167*/ #define  PLL_RESET_DEFAULT            CLK32K_MICRO_SECOND(3500)
/*MT6167*/ #else
/*MT6167*/ #define  CLK_SETTLE_DEFAULT           CLK32K_MICRO_SECOND(3094)//3ms
/*MT6167*/ #define  PLL_RESET_DEFAULT            CLK32K_MICRO_SECOND(3000)
/*MT6167*/ #endif
/*MT6167*/
/*MT6167*/ /*--------------------------------------------------------*/
/*MT6167*/ /*   BFE Legacy Setting (no use)                          */
/*MT6167*/ /*--------------------------------------------------------*/
/*MT6167*/ #define  BBRX_GAIN_DOUBLE             0
/*MT6167*/ #define  BBTX_IQ_SWAP                 0
/*MT6167*/ #define  BBTX_CALBIAS                 0
/*MT6167*/ #define  BBTX_CALRCSEL                0
/*MT6167*/ #define  BBTX_CALRCSEL_H              0
/*MT6167*/ #define  BBTX_COMMON_MODE_VOLTAGE     0 //COMMON MODE VOLTAGE: 1.5v
/*MT6167*/ #define  BBTX_COMMON_MODE_VOLTAGE_H   0 //COMMON MODE VOLTAGE: 1.5v
/*MT6167*/ #define  BBTX_TRIM_I                  0 // wait calibration
/*MT6167*/ #define  BBTX_TRIM_I_H                0 // wait calibration
/*MT6167*/ #define  BBTX_TRIM_Q                  0 // wait calibration
/*MT6167*/ #define  BBTX_TRIM_Q_H                0 // wait calibration
/*MT6167*/ #define  BBTX_OFFSET_I                0 // wait calibration
/*MT6167*/ #define  BBTX_OFFSET_I_H              0 // wait calibration
/*MT6167*/ #define  BBTX_OFFSET_Q                0 // wait calibration
/*MT6167*/ #define  BBTX_OFFSET_Q_H              0 // wait calibration
/*MT6167*/ #define  BBTX_PHSEL                   0 // wait calibration
/*MT6167*/ #define  BBTX_PHSEL_H                 0 // wait calibration
/*MT6167*/ #define  BBTX_COARSGAIN               0
/*MT6167*/ #define  BBTX_GAIN                    0 // get from experiment
/*MT6167*/ #define  BBTX_GAIN_H                  0 // get from experiment
/*MT6167*/ #define  BBTX_GAIN_SWING              900  /* mV */
/*MT6167*/
/*MT6167*/ /*--------------------------------------------------------*/
/*MT6167*/ /*   BFE Setting                                          */
/*MT6167*/ /*--------------------------------------------------------*/
/*MT6167*/ #define  BBRX_IQ_SWAP                 0
/*MT6167*/
/*MT6167*/ /*--------------------------------------------------------*/
/*MT6167*/ /*   Define band mode mapped receiver type                */
/*MT6167*/ /*   DO NOT MODIFY the definitions here.                  */
/*MT6167*/ /*--------------------------------------------------------*/
/*MT6167*/ #define  RX_MAIN_PATH_OFF            0x0
/*MT6167*/ #define  LNA_1                       0x1
/*MT6167*/ #define  LNA_2                       0x2
/*MT6167*/ #define  LNA_3                       0x3
/*MT6167*/ #define  LNA_4                       0x4
/*MT6167*/ #define  LNA_5                       0x5
/*MT6167*/
/*MT6167*/ /*--------------------------------------------------------*/
/*MT6167*/ /*   Define the CapID range                               */
/*MT6167*/ /*--------------------------------------------------------*/
/*MT6167*/ #define  CRYSTAL_CAPID_RANGE          255
/*MT6167*/
#endif

#if IS_RF_MT6166
/*MT6166*/
/*MT6166*/ /*--------------------------------------------------------*/
/*MT6166*/ /*   define SRCB data (shall be modified by real case)    */
/*MT6166*/ /*--------------------------------------------------------*/
/*MT6166*/
/*MT6166*/ #define  SX0_DATA_COUNT               0
/*MT6166*/ #define  SX1_DATA_COUNT               9
/*MT6166*/ #define  SX2_DATA_COUNT               4
/*MT6166*/ #define  SX3_DATA_COUNT               1
/*MT6166*/ #define  ST2B_ST2M_DATA_COUNT         4
/*MT6166*/ #define  SCTRL_IDLE                   SCTRL_WORD(0,30)
/*MT6166*/ #define  SDATA_IDLE                   BSI_CW(0xC9, 0x00200)
/*MT6166*/
/*MT6166*/ /* polarity:  0: long  enable positive pulse */
/*MT6166*/ /*            1: short enable positive pulse */
/*MT6166*/ /*            2: long  enable negative pulse */
/*MT6166*/ /*            3: short enable negative pulse */
/*MT6166*/ #define  BSI_DEVICE_0_CS_POLARITY     0
/*MT6166*/ #define  BSI_DEVICE_1_CS_POLARITY     0
/*MT6166*/
/*MT6166*/ /*--------------------------------------------------------*/
/*MT6166*/ /*   Sleep Mode Setting                                   */
/*MT6166*/ /*-------------------------------------------------------*/
/*MT6166*/
/*MT6166*/ #define  FM_DURATION_DEFAULT          8191
/*MT6166*/ #ifdef  AFC_VCXO
/*MT6166*/ #define  CLK_SETTLE_DEFAULT           CLK32K_MICRO_SECOND(2063)//2ms
/*MT6166*/ #define  PLL_RESET_DEFAULT            CLK32K_MICRO_SECOND(3500)
/*MT6166*/ #else
/*MT6166*/ #define  CLK_SETTLE_DEFAULT           CLK32K_MICRO_SECOND(3094)//3ms
/*MT6166*/ #define  PLL_RESET_DEFAULT            CLK32K_MICRO_SECOND(3000)
/*MT6166*/ #endif
/*MT6166*/
/*MT6166*/ /*--------------------------------------------------------*/
/*MT6166*/ /*   BFE Legacy Setting (no use)                          */
/*MT6166*/ /*--------------------------------------------------------*/
/*MT6166*/ #define  BBRX_GAIN_DOUBLE             0
/*MT6166*/ #define  BBTX_IQ_SWAP                 0
/*MT6166*/ #define  BBTX_CALBIAS                 0
/*MT6166*/ #define  BBTX_CALRCSEL                0
/*MT6166*/ #define  BBTX_CALRCSEL_H              0
/*MT6166*/ #define  BBTX_COMMON_MODE_VOLTAGE     0 //COMMON MODE VOLTAGE: 1.5v
/*MT6166*/ #define  BBTX_COMMON_MODE_VOLTAGE_H   0 //COMMON MODE VOLTAGE: 1.5v
/*MT6166*/ #define  BBTX_TRIM_I                  0 // wait calibration
/*MT6166*/ #define  BBTX_TRIM_I_H                0 // wait calibration
/*MT6166*/ #define  BBTX_TRIM_Q                  0 // wait calibration
/*MT6166*/ #define  BBTX_TRIM_Q_H                0 // wait calibration
/*MT6166*/ #define  BBTX_OFFSET_I                0 // wait calibration
/*MT6166*/ #define  BBTX_OFFSET_I_H              0 // wait calibration
/*MT6166*/ #define  BBTX_OFFSET_Q                0 // wait calibration
/*MT6166*/ #define  BBTX_OFFSET_Q_H              0 // wait calibration
/*MT6166*/ #define  BBTX_PHSEL                   0 // wait calibration
/*MT6166*/ #define  BBTX_PHSEL_H                 0 // wait calibration
/*MT6166*/ #define  BBTX_COARSGAIN               0
/*MT6166*/ #define  BBTX_GAIN                    0 // get from experiment
/*MT6166*/ #define  BBTX_GAIN_H                  0 // get from experiment
/*MT6166*/ #define  BBTX_GAIN_SWING              900  /* mV */
/*MT6166*/
/*MT6166*/ /*--------------------------------------------------------*/
/*MT6166*/ /*   BFE Setting                                          */
/*MT6166*/ /*--------------------------------------------------------*/
/*MT6166*/ #define  BBRX_IQ_SWAP                 0
/*MT6166*/
/*MT6166*/ #if IS_DYNAMIC_G_E_TXWIN_POSITION_SUPPORT_V2
/*MT6166*/ #define  TQ_EPSK_TX_DELAY             1
/*MT6166*/ #endif
/*MT6166*/
/*MT6166*/ /*--------------------------------------------------------*/
/*MT6166*/ /*   Define band mode mapped receiver type                */
/*MT6166*/ /*   DO NOT MODIFY the definitions here.                  */
/*MT6166*/ /*--------------------------------------------------------*/
/*MT6166*/ #define  RX_MAIN_PATH_OFF            0x0
/*MT6166*/ #define  LNA_1                       0x1
/*MT6166*/ #define  LNA_2                       0x2
/*MT6166*/ #define  LNA_3                       0x3
/*MT6166*/ #define  LNA_4                       0x4
/*MT6166*/ #define  LNA_5                       0x5
/*MT6166*/ #define  LNA_6                       0x6
/*MT6166*/ #define  LNA_7                       0x7
/*MT6166*/
/*MT6166*/ /*--------------------------------------------------------*/
/*MT6166*/ /*   Define the CapID range                               */
/*MT6166*/ /*--------------------------------------------------------*/
/*MT6166*/ #define  CRYSTAL_CAPID_RANGE          255
/*MT6166*/
/*MT6166*/ /*-------------------------------------------------------------*/
/*MT6166*/ /*   Define GPS Co-Clock Related Clock Buffer Setting          */
/*MT6166*/ /*-------------------------------------------------------------*/
/*MT6166*/ #if IS_DUAL_LOOP_AFC_CONTROL_SUPPORT
/*MT6166*/ /*-------------------------------------------------------------*/
/*MT6166*/ /*   For GPS Co-Clock platform, the related Clock Buffer       */
/*MT6166*/ /*   must be turned ON. Default Clock Buffer is CLK2_EN        */
/*MT6166*/ /*                                                             */
/*MT6166*/ /*   GPS_CO_CLOCK_BUF_IDX: Related Clock Buffer will be        */
/*MT6166*/ /*                         enabled when GPS Co-Clock           */
/*MT6166*/ /*   0 : No Clock Buffer will be enable when GPS Co-Clock      */
/*MT6166*/ /*   1 : CLK1_EN for GPS Co-Clock                              */
/*MT6166*/ /*   2 : CLK2_EN for GPS Co-Clock                              */
/*MT6166*/ /*   3 : CLK3_EN for GPS Co-Clock                              */
/*MT6166*/ /*   4 : CLK4_EN for GPS Co-Clock                              */
/*MT6166*/ /*-------------------------------------------------------------*/
/*MT6166*/ /*  IS_LOCK_AFCDAC_AT_STARTUP_SUPPORT=TRUE when GPS Co-Clock   */
/*MT6166*/ /*  For GPS Co-Clock, please set related Clock Buffeer enabled */
/*MT6166*/ /*-------------------------------------------------------------*/
/*MT6166*/    #if IS_CHIP_MT6572_ONLY || IS_CHIP_MT6582
/*MT6166*/ #define GPS_CO_CLOCK_BUF_IDX          2
/*MT6166*/       #if IS_LOCK_AFCDAC_AT_STARTUP_SUPPORT
/*MT6166*/ #undef   CLK2_EN
/*MT6166*/ #define  CLK2_EN                      1
/*MT6166*/       #endif
/*MT6166*/    #endif
/*MT6166*/ #endif
#endif

/*============================================================================== */

#if IS_RF_MT6165
/*MT6165*/
/*MT6165*/ /*--------------------------------------------------------*/
/*MT6165*/ /*   define SRCB data (shall be modified by real case)    */
/*MT6165*/ /*--------------------------------------------------------*/
/*MT6165*/
/*MT6165*/ #define  SX0_DATA_COUNT               0
/*MT6165*/ #define  SX1_DATA_COUNT               13
/*MT6165*/ #define  SX2_DATA_COUNT               3
/*MT6165*/ #define  SX3_DATA_COUNT               1
/*MT6165*/ #define  ST2B_ST2M_DATA_COUNT         3
/*MT6165*/ #define  SCTRL_IDLE                   SCTRL_WORD(0,30)
/*MT6165*/ #define  SDATA_IDLE                   BSI_CW(0x01, 0x04000)
/*MT6165*/
/*MT6165*/ /* polarity:  0: long  enable positive pulse */
/*MT6165*/ /*            1: short enable positive pulse */
/*MT6165*/ /*            2: long  enable negative pulse */
/*MT6165*/ /*            3: short enable negative pulse */
/*MT6165*/ #define  BSI_DEVICE_0_CS_POLARITY     0
/*MT6165*/ #define  BSI_DEVICE_1_CS_POLARITY     0
/*MT6165*/
/*MT6165*/ /*--------------------------------------------------------*/
/*MT6165*/ /*   Sleep Mode Setting                                   */
/*MT6165*/ /*-------------------------------------------------------*/
/*MT6165*/
/*MT6165*/ #define  FM_DURATION_DEFAULT          8191
/*MT6165*/ #ifdef  AFC_VCXO
/*MT6165*/ #define  CLK_SETTLE_DEFAULT           CLK32K_MICRO_SECOND(2063)//2ms
/*MT6165*/ #define  PLL_RESET_DEFAULT            CLK32K_MICRO_SECOND(3500)
/*MT6165*/ #else
/*MT6165*/ #define  CLK_SETTLE_DEFAULT           CLK32K_MICRO_SECOND(3094)//3ms
/*MT6165*/ #define  PLL_RESET_DEFAULT            CLK32K_MICRO_SECOND(3000)
/*MT6165*/ #endif
/*MT6165*/
/*MT6165*/ /*--------------------------------------------------------*/
/*MT6165*/ /*   BFE Legacy Setting (no use)                          */
/*MT6165*/ /*--------------------------------------------------------*/
/*MT6165*/ #define  BBRX_GAIN_DOUBLE             0
/*MT6165*/ #define  BBTX_IQ_SWAP                 0
/*MT6165*/ #define  BBTX_CALBIAS                 0
/*MT6165*/ #define  BBTX_CALRCSEL                0
/*MT6165*/ #define  BBTX_CALRCSEL_H              0
/*MT6165*/ #define  BBTX_COMMON_MODE_VOLTAGE     0 //COMMON MODE VOLTAGE: 1.5v
/*MT6165*/ #define  BBTX_COMMON_MODE_VOLTAGE_H   0 //COMMON MODE VOLTAGE: 1.5v
/*MT6165*/ #define  BBTX_TRIM_I                  0 // wait calibration
/*MT6165*/ #define  BBTX_TRIM_I_H                0 // wait calibration
/*MT6165*/ #define  BBTX_TRIM_Q                  0 // wait calibration
/*MT6165*/ #define  BBTX_TRIM_Q_H                0 // wait calibration
/*MT6165*/ #define  BBTX_OFFSET_I                0 // wait calibration
/*MT6165*/ #define  BBTX_OFFSET_I_H              0 // wait calibration
/*MT6165*/ #define  BBTX_OFFSET_Q                0 // wait calibration
/*MT6165*/ #define  BBTX_OFFSET_Q_H              0 // wait calibration
/*MT6165*/ #define  BBTX_PHSEL                   0 // wait calibration
/*MT6165*/ #define  BBTX_PHSEL_H                 0 // wait calibration
/*MT6165*/ #define  BBTX_COARSGAIN               0
/*MT6165*/ #define  BBTX_GAIN                    0 // get from experiment
/*MT6165*/ #define  BBTX_GAIN_H                  0 // get from experiment
/*MT6165*/ #define  BBTX_GAIN_SWING              900  /* mV */
/*MT6165*/
/*MT6165*/ /*--------------------------------------------------------*/
/*MT6165*/ /*   BFE Setting                                          */
/*MT6165*/ /*--------------------------------------------------------*/
/*MT6165*/ #define  BBRX_IQ_SWAP                 0
/*MT6165*/
/*MT6165*/ #if IS_DYNAMIC_G_E_TXWIN_POSITION_SUPPORT_V2
/*MT6165*/ #define  TQ_EPSK_TX_DELAY             1
/*MT6165*/ #endif
/*MT6165*/
/*MT6165*/ /*--------------------------------------------------------*/
/*MT6165*/ /*   Define band mode mapped receiver type                */
/*MT6165*/ /*   DO NOT MODIFY the definitions here.                  */
/*MT6165*/ /*--------------------------------------------------------*/
/*MT6165*/ #define  LNA_0                       0x0
/*MT6165*/ #define  LNA_1                       0x1
/*MT6165*/ #define  LNA_2                       0x2
/*MT6165*/ #define  LNA_3                       0x3
/*MT6165*/ #define  LNA_4                       0x4
/*MT6165*/ #define  LNA_5                       0x5
/*MT6165*/ #define  LNA_6                       0x6
/*MT6165*/
/*MT6165*/ /*--------------------------------------------------------*/
/*MT6165*/ /*   Define the CapID range                               */
/*MT6165*/ /*--------------------------------------------------------*/
/*MT6165*/ #define  CRYSTAL_CAPID_RANGE          255
/*MT6165*/
#endif

/*============================================================================== */

#if IS_RF_MT6580RF
/*MT6580RF*/
/*MT6580RF*/ /*--------------------------------------------------------*/
/*MT6580RF*/ /*   define SRCB data (shall be modified by real case)    */
/*MT6580RF*/ /*--------------------------------------------------------*/
/*MT6580RF*/
/*MT6580RF*/ #define  SX0_DATA_COUNT               0
/*MT6580RF*/ #define  SX1_DATA_COUNT              14
/*MT6580RF*/ #define  SX2_DATA_COUNT               4
/*MT6580RF*/ #define  SX3_DATA_COUNT               2
/*MT6580RF*/ #define  ST2B_ST2M_DATA_COUNT         4
/*MT6580RF*/ #define  SCTRL_IDLE                   SCTRL_WORD(0,30)
/*MT6580RF*/ #define  SDATA_IDLE                   BSI_CW(0xC9, 0x00200)
/*MT6580RF*/
/*MT6580RF*/ /* polarity:  0: long  enable positive pulse */
/*MT6580RF*/ /*            1: short enable positive pulse */
/*MT6580RF*/ /*            2: long  enable negative pulse */
/*MT6580RF*/ /*            3: short enable negative pulse */
/*MT6580RF*/ #define  BSI_DEVICE_0_CS_POLARITY     0
/*MT6580RF*/ #define  BSI_DEVICE_1_CS_POLARITY     0
/*MT6580RF*/
/*MT6580RF*/ /*--------------------------------------------------------*/
/*MT6580RF*/ /*   Sleep Mode Setting                                   */
/*MT6580RF*/ /*-------------------------------------------------------*/
/*MT6580RF*/
/*MT6580RF*/ #define  FM_DURATION_DEFAULT          8191
/*MT6580RF*/ #ifdef  AFC_VCXO
/*MT6580RF*/ #define  CLK_SETTLE_DEFAULT           CLK32K_MICRO_SECOND(2063)//2ms
/*MT6580RF*/ #define  PLL_RESET_DEFAULT            CLK32K_MICRO_SECOND(3500)
/*MT6580RF*/ #else
/*MT6580RF*/ #define  CLK_SETTLE_DEFAULT           CLK32K_MICRO_SECOND(3094)//3ms
/*MT6580RF*/ #define  PLL_RESET_DEFAULT            CLK32K_MICRO_SECOND(3000)
/*MT6580RF*/ #endif
/*MT6580RF*/
/*MT6580RF*/ /*--------------------------------------------------------*/
/*MT6580RF*/ /*   BFE Legacy Setting (no use)                          */
/*MT6580RF*/ /*--------------------------------------------------------*/
/*MT6580RF*/ #define  BBRX_GAIN_DOUBLE             0
/*MT6580RF*/ #define  BBTX_IQ_SWAP                 0
/*MT6580RF*/ #define  BBTX_CALBIAS                 0
/*MT6580RF*/ #define  BBTX_CALRCSEL                0
/*MT6580RF*/ #define  BBTX_CALRCSEL_H              0
/*MT6580RF*/ #define  BBTX_COMMON_MODE_VOLTAGE     0 //COMMON MODE VOLTAGE: 1.5v
/*MT6580RF*/ #define  BBTX_COMMON_MODE_VOLTAGE_H   0 //COMMON MODE VOLTAGE: 1.5v
/*MT6580RF*/ #define  BBTX_TRIM_I                  0 // wait calibration
/*MT6580RF*/ #define  BBTX_TRIM_I_H                0 // wait calibration
/*MT6580RF*/ #define  BBTX_TRIM_Q                  0 // wait calibration
/*MT6580RF*/ #define  BBTX_TRIM_Q_H                0 // wait calibration
/*MT6580RF*/ #define  BBTX_OFFSET_I                0 // wait calibration
/*MT6580RF*/ #define  BBTX_OFFSET_I_H              0 // wait calibration
/*MT6580RF*/ #define  BBTX_OFFSET_Q                0 // wait calibration
/*MT6580RF*/ #define  BBTX_OFFSET_Q_H              0 // wait calibration
/*MT6580RF*/ #define  BBTX_PHSEL                   0 // wait calibration
/*MT6580RF*/ #define  BBTX_PHSEL_H                 0 // wait calibration
/*MT6580RF*/ #define  BBTX_COARSGAIN               0
/*MT6580RF*/ #define  BBTX_GAIN                    0 // get from experiment
/*MT6580RF*/ #define  BBTX_GAIN_H                  0 // get from experiment
/*MT6580RF*/ #define  BBTX_GAIN_SWING              900  /* mV */
/*MT6580RF*/
/*MT6580RF*/ /*--------------------------------------------------------*/
/*MT6580RF*/ /*   BFE Setting                                          */
/*MT6580RF*/ /*--------------------------------------------------------*/
/*MT6580RF*/ #define  BBRX_IQ_SWAP                 0
/*MT6580RF*/
/*MT6580RF*/ #if IS_DYNAMIC_G_E_TXWIN_POSITION_SUPPORT_V2
/*MT6580RF*/ #define  TQ_EPSK_TX_DELAY             1
/*MT6580RF*/ #endif
/*MT6580RF*/
/*MT6580RF*/ /*--------------------------------------------------------*/
/*MT6580RF*/ /*   Define band mode mapped receiver type                */
/*MT6580RF*/ /*   DO NOT MODIFY the definitions here.                  */
/*MT6580RF*/ /*--------------------------------------------------------*/
/*MT6580RF*/ #define  RX_MAIN_PATH_OFF            0x0
/*MT6580RF*/ #define  LNA_1                       0x1
/*MT6580RF*/ #define  LNA_2                       0x2
/*MT6580RF*/ #define  LNA_3                       0x3
/*MT6580RF*/ #define  LNA_4                       0x4
/*MT6580RF*/ #define  LNA_5                       0x5
/*MT6580RF*/ #define  LNA_6                       0x6
/*MT6580RF*/ #define  LNA_7                       0x7
/*MT6580RF*/
/*MT6580RF*/ /*--------------------------------------------------------*/
/*MT6580RF*/ /*   Define the CapID range                               */
/*MT6580RF*/ /*--------------------------------------------------------*/
/*MT6580RF*/ #define  CRYSTAL_CAPID_RANGE          255
/*MT6580RF*/
#endif

/*============================================================================== */

#ifdef L1_SIM
#undef   CLK_SETTLE_DEFAULT
#undef   PLL_RESET_DEFAULT
#define  CLK_SETTLE_DEFAULT            CLK32K_MICRO_SECOND(3125)
#define  PLL_RESET_DEFAULT             CLK32K_MICRO_SECOND(3000)
#endif

#if defined(FPGA) || defined(MT6208) || defined(MT6205) || defined(MT6205B)
   #if   BBRX_GAIN_DOUBLE==1
#define  DSP_MAGIC_VALUE               -83.25
   #elif BBRX_GAIN_DOUBLE==0
#define  DSP_MAGIC_VALUE               -77.25
   #endif
#elif defined(MT6218)
   #if   BBRX_GAIN_DOUBLE==1
#define  DSP_MAGIC_VALUE               -99.75
   #elif BBRX_GAIN_DOUBLE==0
#define  DSP_MAGIC_VALUE               -93.75
   #endif
#elif IS_CHIP_MT6229_FPGA2
   #if   BBRX_GAIN_DOUBLE==1
#define  DSP_MAGIC_VALUE               -97.25
   #elif BBRX_GAIN_DOUBLE==0
#define  DSP_MAGIC_VALUE               -91.25
   #endif
#elif IS_BBTXRX_CHIP_DESIGN_VER_2
#define  DSP_MAGIC_VALUE               -94.25
#elif IS_BBTXRX_CHIP_DESIGN_VER_3
#define  DSP_MAGIC_VALUE               -114.75
#elif IS_CHIP_MT6256 || IS_CHIP_MT6255 || IS_CHIP_MT6280
   #if   BBRX_GAIN_DOUBLE==1
#define  DSP_MAGIC_VALUE               -118.75
   #elif BBRX_GAIN_DOUBLE==0
#define  DSP_MAGIC_VALUE               -118.75
   #endif
#elif IS_CHIP_MT6572
#define  DSP_MAGIC_VALUE               -120.79
#elif IS_CHIP_MT6583_MD1
   #if   BBRX_GAIN_DOUBLE==1
#define  DSP_MAGIC_VALUE               -120.79
   #elif BBRX_GAIN_DOUBLE==0
#define  DSP_MAGIC_VALUE               -120.79
   #endif
#elif IS_CHIP_MT6251
   #if   BBRX_GAIN_DOUBLE==1
#define  DSP_MAGIC_VALUE               -118.75
   #elif BBRX_GAIN_DOUBLE==0
#define  DSP_MAGIC_VALUE               -118.75
   #endif
#elif IS_CHIP_MT6250
   #if   BBRX_GAIN_DOUBLE==1
#define  DSP_MAGIC_VALUE               -117.75
   #elif BBRX_GAIN_DOUBLE==0
#define  DSP_MAGIC_VALUE               -117.75
   #endif
#elif IS_EDGE_SAIC_CHIP_MT6238_AND_LATTER_VERSION
   #if   BBRX_GAIN_DOUBLE==1
#define  DSP_MAGIC_VALUE               -97.75
   #elif BBRX_GAIN_DOUBLE==0
#define  DSP_MAGIC_VALUE               -91.75
   #endif
#elif IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION || IS_CHIP_MT6225_AND_LATTER_VERSION
   #if   BBRX_GAIN_DOUBLE==1
#define  DSP_MAGIC_VALUE               -99.75
   #elif BBRX_GAIN_DOUBLE==0
#define  DSP_MAGIC_VALUE               -93.75
   #endif
#else
   #if   BBRX_GAIN_DOUBLE==1
#define  DSP_MAGIC_VALUE               -97.25
   #elif BBRX_GAIN_DOUBLE==0
#define  DSP_MAGIC_VALUE               -91.25
   #endif
#endif

/*============================================================================== */
// remove from l1d_data.c to here
// if GSM850 is not support
#ifndef  PDATA_GSM850_PR1
#define  PDATA_GSM850_PR1              0x00
#endif

#ifndef  PDATA_GSM850_PR2
#define  PDATA_GSM850_PR2              0x00
#endif

#ifndef  PDATA_GSM850_PR3
#define  PDATA_GSM850_PR3              0x00
#endif

#ifndef  PDATA_GSM850_PT1
#define  PDATA_GSM850_PT1              0x00
#endif

#ifndef  PDATA_GSM850_PT2
#define  PDATA_GSM850_PT2              0x00
#endif

#ifndef  PDATA_GSM850_PT3
#define  PDATA_GSM850_PT3              0x00
#endif

#ifndef  BBTX_IQSWAP_ONFLY
#define  BBTX_IQSWAP_ONFLY             0
#endif

//BBTX_PHSEL
#ifndef  BBTX_PHSEL
#define  BBTX_PHSEL                    0
#endif
//BBTX_RPSEL
#ifndef  BBTX_RPSEL
#define  BBTX_RPSEL                    0
#endif
//BBTX_INTEN
#ifndef  BBTX_INTEN
#define  BBTX_INTEN                    0
#endif
//BBTX_SW_QBCNT
#ifndef  BBTX_SW_QBCNT
#define  BBTX_SW_QBCNT                 0
#endif
//8g switch
#ifndef  PDATA_GMSK
#define  PDATA_GMSK                    0
#endif
#ifndef  PDATA_8PSK
#define  PDATA_8PSK                    0
#endif

//GSM850
#ifndef  PDATA_GSM850_PR3A
#define  PDATA_GSM850_PR3A             PDATA_GSM850_PR3
#endif
#ifndef  PDATA_GSM850_PT3A
#define  PDATA_GSM850_PT3A             PDATA_GSM850_PT3
#endif
#ifndef  PDATA_GSM850_PR2B
#define  PDATA_GSM850_PR2B             PDATA_GSM850_PR2
#endif
#ifndef  PDATA_GSM850_PR2M1
   #if defined(QB_PR2B) && QB_PR2B<QB_PR2
#define  PDATA_GSM850_PR2M1            PDATA_GSM850_PR2B
   #else
#define  PDATA_GSM850_PR2M1            PDATA_GSM850_PR2
   #endif
#endif
#ifndef  PDATA_GSM850_PR2M2
#define  PDATA_GSM850_PR2M2            PDATA_GSM850_PR2M1
#endif
#ifndef  PDATA_GSM850_PR2M3
#define  PDATA_GSM850_PR2M3            PDATA_GSM850_PR2M2
#endif
#ifndef  PDATA_GSM850_PT2B
#define  PDATA_GSM850_PT2B             PDATA_GSM850_PT2
#endif
#ifndef  PDATA_GSM850_PT2M1_8G
   #if defined(QB_PT2B) && QB_PT2B<QB_PT2
#define  PDATA_GSM850_PT2M1_8G         PDATA_GSM850_PT2B
   #else
#define  PDATA_GSM850_PT2M1_8G         PDATA_GSM850_PT2
   #endif
#endif
#ifndef  PDATA_GSM850_PT2M1_G8
   #if defined(QB_PT2B) && QB_PT2B<QB_PT2
#define  PDATA_GSM850_PT2M1_G8         PDATA_GSM850_PT2B
   #else
#define  PDATA_GSM850_PT2M1_G8         PDATA_GSM850_PT2
   #endif
#endif
#ifndef  PDATA_GSM850_PT2M2_8G
#define  PDATA_GSM850_PT2M2_8G         PDATA_GSM850_PT2M1_8G
#endif
#ifndef  PDATA_GSM850_PT2M2_G8
#define  PDATA_GSM850_PT2M2_G8         PDATA_GSM850_PT2M1_G8
#endif
#ifndef  PDATA_GSM850_PT2M3_8G
#define  PDATA_GSM850_PT2M3_8G         PDATA_GSM850_PT2M2_8G
#endif
#ifndef  PDATA_GSM850_PT2M3_G8
#define  PDATA_GSM850_PT2M3_G8         PDATA_GSM850_PT2M2_G8
#endif


//GSM
#ifndef  PDATA_GSM_PR3A
#define  PDATA_GSM_PR3A                PDATA_GSM_PR3
#endif
#ifndef  PDATA_GSM_PT3A
#define  PDATA_GSM_PT3A                PDATA_GSM_PT3
#endif
#ifndef  PDATA_GSM_PR2B
#define  PDATA_GSM_PR2B                PDATA_GSM_PR2
#endif
#ifndef  PDATA_GSM_PR2M1
   #if defined(QB_PR2B) && QB_PR2B<QB_PR2
#define  PDATA_GSM_PR2M1               PDATA_GSM_PR2B
   #else
#define  PDATA_GSM_PR2M1               PDATA_GSM_PR2
   #endif
#endif
#ifndef  PDATA_GSM_PR2M2
#define  PDATA_GSM_PR2M2               PDATA_GSM_PR2M1
#endif
#ifndef  PDATA_GSM_PR2M3
#define  PDATA_GSM_PR2M3               PDATA_GSM_PR2M2
#endif
#ifndef  PDATA_GSM_PT2B
#define  PDATA_GSM_PT2B                PDATA_GSM_PT2
#endif
#ifndef  PDATA_GSM_PT2M1_8G
   #if defined(QB_PT2B) && QB_PT2B<QB_PT2
#define  PDATA_GSM_PT2M1_8G            PDATA_GSM_PT2B
   #else
#define  PDATA_GSM_PT2M1_8G            PDATA_GSM_PT2
   #endif
#endif
#ifndef  PDATA_GSM_PT2M1_G8
   #if defined(QB_PT2B) && QB_PT2B<QB_PT2
#define  PDATA_GSM_PT2M1_G8            PDATA_GSM_PT2B
   #else
#define  PDATA_GSM_PT2M1_G8            PDATA_GSM_PT2
   #endif
#endif
#ifndef  PDATA_GSM_PT2M2_8G
#define  PDATA_GSM_PT2M2_8G            PDATA_GSM_PT2M1_8G
#endif
#ifndef  PDATA_GSM_PT2M2_G8
#define  PDATA_GSM_PT2M2_G8            PDATA_GSM_PT2M1_G8
#endif
#ifndef  PDATA_GSM_PT2M3_8G
#define  PDATA_GSM_PT2M3_8G            PDATA_GSM_PT2M2_8G
#endif
#ifndef  PDATA_GSM_PT2M3_G8
#define  PDATA_GSM_PT2M3_G8            PDATA_GSM_PT2M2_G8
#endif


//DCS
#ifndef  PDATA_DCS_PR3A
#define  PDATA_DCS_PR3A                PDATA_DCS_PR3
#endif
#ifndef  PDATA_DCS_PT3A
#define  PDATA_DCS_PT3A                PDATA_DCS_PT3
#endif
#ifndef  PDATA_DCS_PR2B
#define  PDATA_DCS_PR2B                PDATA_DCS_PR2
#endif
#ifndef  PDATA_DCS_PR2M1
   #if defined(QB_PR2B) && QB_PR2B<QB_PR2
#define  PDATA_DCS_PR2M1               PDATA_DCS_PR2B
   #else
#define  PDATA_DCS_PR2M1               PDATA_DCS_PR2
   #endif
#endif
#ifndef  PDATA_DCS_PR2M2
#define  PDATA_DCS_PR2M2               PDATA_DCS_PR2M1
#endif
#ifndef  PDATA_DCS_PR2M3
#define  PDATA_DCS_PR2M3               PDATA_DCS_PR2M2
#endif
#ifndef  PDATA_DCS_PT2B
#define  PDATA_DCS_PT2B                PDATA_DCS_PT2
#endif
#ifndef  PDATA_DCS_PT2M1_8G
   #if defined(QB_PT2B) && QB_PT2B<QB_PT2
#define  PDATA_DCS_PT2M1_8G            PDATA_DCS_PT2B
   #else
#define  PDATA_DCS_PT2M1_8G            PDATA_DCS_PT2
   #endif
#endif
#ifndef  PDATA_DCS_PT2M1_G8
   #if defined(QB_PT2B) && QB_PT2B<QB_PT2
#define  PDATA_DCS_PT2M1_G8            PDATA_DCS_PT2B
   #else
#define  PDATA_DCS_PT2M1_G8            PDATA_DCS_PT2
   #endif
#endif
#ifndef  PDATA_DCS_PT2M2_8G
#define  PDATA_DCS_PT2M2_8G            PDATA_DCS_PT2M1_8G
#endif
#ifndef  PDATA_DCS_PT2M2_G8
#define  PDATA_DCS_PT2M2_G8            PDATA_DCS_PT2M1_G8
#endif
#ifndef  PDATA_DCS_PT2M3_8G
#define  PDATA_DCS_PT2M3_8G            PDATA_DCS_PT2M2_8G
#endif
#ifndef  PDATA_DCS_PT2M3_G8
#define  PDATA_DCS_PT2M3_G8            PDATA_DCS_PT2M2_G8
#endif


//PCS
#ifndef  PDATA_PCS_PR3A
#define  PDATA_PCS_PR3A                PDATA_PCS_PR3
#endif
#ifndef  PDATA_PCS_PT3A
#define  PDATA_PCS_PT3A                PDATA_PCS_PT3
#endif
#ifndef  PDATA_PCS_PR2B
#define  PDATA_PCS_PR2B                PDATA_PCS_PR2
#endif
#ifndef  PDATA_PCS_PR2M1
   #if defined(QB_PR2B) && QB_PR2B<QB_PR2
#define  PDATA_PCS_PR2M1               PDATA_PCS_PR2B
   #else
#define  PDATA_PCS_PR2M1               PDATA_PCS_PR2
   #endif
#endif
#ifndef  PDATA_PCS_PR2M2
#define  PDATA_PCS_PR2M2               PDATA_PCS_PR2M1
#endif
#ifndef  PDATA_PCS_PR2M3
#define  PDATA_PCS_PR2M3               PDATA_PCS_PR2M2
#endif
#ifndef  PDATA_PCS_PT2B
#define  PDATA_PCS_PT2B                PDATA_PCS_PT2
#endif
#ifndef  PDATA_PCS_PT2M1_8G
   #if defined(QB_PT2B) && QB_PT2B<QB_PT2
#define  PDATA_PCS_PT2M1_8G            PDATA_PCS_PT2B
   #else
#define  PDATA_PCS_PT2M1_8G            PDATA_PCS_PT2
   #endif
#endif
#ifndef  PDATA_PCS_PT2M1_G8
   #if defined(QB_PT2B) && QB_PT2B<QB_PT2
#define  PDATA_PCS_PT2M1_G8            PDATA_PCS_PT2B
   #else
#define  PDATA_PCS_PT2M1_G8            PDATA_PCS_PT2
   #endif
#endif
#ifndef  PDATA_PCS_PT2M2_8G
#define  PDATA_PCS_PT2M2_8G            PDATA_PCS_PT2M1_8G
#endif
#ifndef  PDATA_PCS_PT2M2_G8
#define  PDATA_PCS_PT2M2_G8            PDATA_PCS_PT2M1_G8
#endif
#ifndef  PDATA_PCS_PT2M3_8G
#define  PDATA_PCS_PT2M3_8G            PDATA_PCS_PT2M2_8G
#endif
#ifndef  PDATA_PCS_PT2M3_G8
#define  PDATA_PCS_PT2M3_G8            PDATA_PCS_PT2M2_G8
#endif


#ifndef  QB_PR3A
#define  QB_PR3A                       ( QB_PR3+2 )
#endif
#ifndef  QB_PT3A
#define  QB_PT3A                       ( QB_PT3+2 )
#endif
#ifndef  QB_PR2B
#define  QB_PR2B                       0 //(16000)
#endif
#ifndef  QB_PR2M1
#define  QB_PR2M1                      0 //(16000)
#endif
#ifndef  QB_PR2M2
#define  QB_PR2M2                      0 //(16000)
#endif
#ifndef  QB_PT2B
#define  QB_PT2B                       0 //(16000)
#endif
#ifndef  QB_SR0
#define  QB_SR0                        (-10000)
#endif
#ifndef  QB_ST0
#define  QB_ST0                        (-10000)
#endif
#ifndef  QB_ST2
#define  QB_ST2                        (-10000)
#endif
#ifndef  QB_ST2B
#define  QB_ST2B                       (-10000)
#endif
#ifndef  QB_ST2M_G8
#define  QB_ST2M_G8                    (-10000)
#endif
#ifndef  QB_ST2M_8G
#define  QB_ST2M_8G                    (-10000)
#endif
#ifndef  QB_PT2M1_8G
#define  QB_PT2M1_8G                   0
#endif
#ifndef  QB_PT2M1_G8
#define  QB_PT2M1_G8                   0
#endif
#ifndef  QB_PT2M2_8G
#define  QB_PT2M2_8G                   ( QB_PT2M1_8G-2 )
#endif
#ifndef  QB_PT2M2_G8
#define  QB_PT2M2_G8                   ( QB_PT2M1_G8-2 )
#endif
#ifndef  QB_PT2M3_8G
#define  QB_PT2M3_8G                   ( QB_PT2M2_8G-2 )
#endif
#ifndef  QB_PT2M3_G8
#define  QB_PT2M3_G8                   ( QB_PT2M2_G8-2 )
#endif

#ifndef  SX0_DATA_COUNT
#define  SX0_DATA_COUNT                0
#endif
#ifndef  ST2B_ST2M_DATA_COUNT
   #if IS_BSI_V2_SUPPORT
#define  ST2B_ST2M_DATA_COUNT          SX2_DATA_COUNT
   #else
#define  ST2B_ST2M_DATA_COUNT          0
   #endif
#endif

#ifndef  IS_BSI_DATA_TABLE_Y_SHIFT
#define  IS_BSI_DATA_TABLE_Y_SHIFT     0
#endif

#ifndef  BBTX_CALRCSEL_H
#define  BBTX_CALRCSEL_H               0
#endif
#ifndef  BBTX_COMMON_MODE_VOLTAGE_H
#define  BBTX_COMMON_MODE_VOLTAGE_H    0
#endif
#ifndef  BBTX_TRIM_I_H
#define  BBTX_TRIM_I_H                 0
#endif
#ifndef  BBTX_TRIM_Q_H
#define  BBTX_TRIM_Q_H                 0
#endif
#ifndef  BBTX_DCCOARSE_I
#define  BBTX_DCCOARSE_I               0
#endif
#ifndef  BBTX_DCCOARSE_Q
#define  BBTX_DCCOARSE_Q               0
#endif
#ifndef  BBTX_DCCOARSE_I_H
#define  BBTX_DCCOARSE_I_H             0
#endif
#ifndef  BBTX_DCCOARSE_Q_H
#define  BBTX_DCCOARSE_Q_H             0
#endif
#ifndef  BBTX_OFFSET_I_H
#define  BBTX_OFFSET_I_H               0
#endif
#ifndef  BBTX_OFFSET_Q_H
#define  BBTX_OFFSET_Q_H               0
#endif
#ifndef  BBTX_GAIN_H
#define  BBTX_GAIN_H                   0
#endif
#ifndef  BBTX_PHSEL_H
#define  BBTX_PHSEL_H                  0
#endif
#ifndef  BBTX_GAIN_COMP
#define  BBTX_GAIN_COMP                0
#endif
#ifndef  BBTX_IQGAIN_SEL
#define  BBTX_IQGAIN_SEL               0
#endif
#ifndef  BBTX_GAIN_COMP_H
#define  BBTX_GAIN_COMP_H              0
#endif
#ifndef  BBTX_IQGAIN_SEL_H
#define  BBTX_IQGAIN_SEL_H             0
#endif
#ifndef  BBTX_PHSEL_I
#define  BBTX_PHSEL_I                  0
#endif
#ifndef  BBTX_PHSEL_Q
#define  BBTX_PHSEL_Q                  0
#endif
#ifndef  BBTX_PHSEL_I_H
#define  BBTX_PHSEL_I_H                0
#endif
#ifndef  BBTX_PHSEL_Q_H
#define  BBTX_PHSEL_Q_H                0
#endif
#ifndef  BBTX_EPSK_DTAP_SYM
#define  BBTX_EPSK_DTAP_SYM            0
#endif

#ifndef  IS_BT_COCLOCK_SUPPORT
#define  IS_BT_COCLOCK_SUPPORT         0
#endif

#ifndef  IS_HW_DISABLE_EPSK_TX_SUPPORT
#define  IS_HW_DISABLE_EPSK_TX_SUPPORT 0
#endif

#ifndef  IS_AUXADC_CLOSED_LOOP_TXPC_ON
#define  IS_AUXADC_CLOSED_LOOP_TXPC_ON 0
#endif

#ifndef  IS_BSI_CLOSED_LOOP_TXPC_ON
#define  IS_BSI_CLOSED_LOOP_TXPC_ON    0
#endif

#ifndef  QB_TX_SAMPLE_OFFSET_GMSK
#define  QB_TX_SAMPLE_OFFSET_GMSK      0
#endif

#ifndef  QB_TX_SAMPLE_OFFSET_EPSK
#define  QB_TX_SAMPLE_OFFSET_EPSK      0
#endif

#ifndef  TXPC_EPSK_TP_SLOPE_LB
#define  TXPC_EPSK_TP_SLOPE_LB         25
#endif

#ifndef  TXPC_EPSK_TP_SLOPE_HB
#define  TXPC_EPSK_TP_SLOPE_HB         25
#endif

#ifndef  IS_EGSM900_DISABLE
#define  IS_EGSM900_DISABLE            0
#endif

#ifndef  BAT_VOLTAGE_SAMPLE_PERIOD_SECOND
#define  BAT_VOLTAGE_SAMPLE_PERIOD_SECOND     180
#endif

#ifndef  BAT_VOLTAGE_AVERAGE_COUNT
#define  BAT_VOLTAGE_AVERAGE_COUNT            1
#endif

#ifndef  BAT_TEMPERATURE_SAMPLE_PERIOD_SECOND
#define  BAT_TEMPERATURE_SAMPLE_PERIOD_SECOND 180
#endif

#ifndef  BAT_TEMPERATURE_AVERAGE_COUNT
#define  BAT_TEMPERATURE_AVERAGE_COUNT        1
#endif

#ifndef  BAT_LOW_VOLTAGE_TRHESHOLD
#define  BAT_LOW_VOLTAGE_TRHESHOLD            (3.5)
#endif

#ifndef  BAT_HIGH_VOLTAGE_TRHESHOLD
#define  BAT_HIGH_VOLTAGE_TRHESHOLD           (4.0)
#endif

#ifndef  BAT_LOW_TEMPERATURE_TRHESHOLD
#define  BAT_LOW_TEMPERATURE_TRHESHOLD        (0)
#endif

#ifndef  BAT_HIGH_TEMPERATURE_TRHESHOLD
#define  BAT_HIGH_TEMPERATURE_TRHESHOLD       (50)
#endif

#ifndef  RF_TEMPERATURE_SAMPLE_PERIOD_SECOND
#define  RF_TEMPERATURE_SAMPLE_PERIOD_SECOND  1
#endif

#ifndef  RF_TEMPERATURE_AVERAGE_COUNT
#define  RF_TEMPERATURE_AVERAGE_COUNT         1
#endif

#ifndef  CLK1_EN
#define  CLK1_EN                       1
#endif

#ifndef  CLK2_EN
#define  CLK2_EN                       0
#endif

#ifndef  CLK3_EN
#define  CLK3_EN                       0
#endif

#ifndef  CLK4_EN
#define  CLK4_EN                       0
#endif

#ifndef  GPS_CO_CLOCK_BUF_IDX
#define  GPS_CO_CLOCK_BUF_IDX          0
#endif

#ifndef  GSM850_PATH_SEL
#define  GSM850_PATH_SEL               0x7
#endif

#ifndef  GSM_PATH_SEL
#define  GSM_PATH_SEL                  0x6
#endif

#ifndef  DCS_PATH_SEL
#define  DCS_PATH_SEL                  0x5
#endif

#ifndef  PCS_PATH_SEL
#define  PCS_PATH_SEL                  0x4
#endif

#ifndef  TQ_EPSK_TX_DELAY
#define  TQ_EPSK_TX_DELAY              0
#endif

#ifndef  CRYSTAL_CAPID_RANGE
#define  CRYSTAL_CAPID_RANGE           63
#endif

#ifndef  GSM_ERR_DET_ID
#define  GSM_ERR_DET_ID                9
#endif

#if IS_TDMA_AD_DA_WINDOW_SUPPORT
   #if IS_CHIP_MT6580
#define  QB_RX_ADEN_2_FENA             115 /* > 100us for MT6580 */
#define  QB_RX_FENA_2_ADEN             0
#define  QB_TX_DAEN_2_FENA             25  /* > 20us for MT6580 */
#define  QB_TX_FENA_2_DAEN             0
   #elif IS_CHIP_MT6572
#define  QB_RX_ADEN_2_FENA             72  /* > 66us for MT6572 */
#define  QB_RX_FENA_2_ADEN             0
#define  QB_TX_DAEN_2_FENA             13  /* > 12us for MT6572 */
#define  QB_TX_FENA_2_DAEN             0
   #elif IS_CHIP_MT6583_MD1 || IS_CHIP_MT6583_MD2
#define  QB_RX_ADEN_2_FENA             135 /* >120us for MT6583 */
#define  QB_RX_FENA_2_ADEN             0
#define  QB_TX_DAEN_2_FENA             25  /* > 20us for MT6583 */
#define  QB_TX_FENA_2_DAEN             0
   #else
#error "please check the AD/DA window settings"
   #endif
#else
#define  QB_RX_ADEN_2_FENA             0
#define  QB_RX_FENA_2_ADEN             0
#define  QB_TX_DAEN_2_FENA             0
#define  QB_TX_FENA_2_DAEN             0
#endif

#if IS_CHIP_MT6583_MD1
/* for MT6167 */
#define  QB_RX_FENA_2_FSYNC            48   /* this value shall be 4N+0 */
#define  QB_RX_FSYNC_2_FENA            0
#define  QB_TX_FENA_2_FSYNC            20
#define  QB_TX_FSYNC_2_FENA            30
#endif

#if IS_CHIP_MT6583_MD2
/* for MT6168 */
#undef   QB_RX_FENA_2_FSYNC
#undef   QB_RX_FSYNC_2_FENA
#undef   QB_TX_FENA_2_FSYNC
#undef   QB_TX_FSYNC_2_FENA
#define  QB_RX_FENA_2_FSYNC            48   /* this value shall be 4N+0 */
#define  QB_RX_FSYNC_2_FENA            0
#define  QB_TX_FENA_2_FSYNC            20
#define  QB_TX_FSYNC_2_FENA            26

/* for MT6168 VRF28 Setting */
   #ifndef VRF28_SOURCE
#define VRF28_SOURCE                   1    /* VRF28_SOURCE: 0(VRF28_1) or 1(VRF28_2) */
   #endif
#endif

#if IS_CHIP_MT6572
/* for MT6166 */
#define  QB_RX_FENA_2_FSYNC            48   /* this value shall be 4N+0 */
#define  QB_RX_FSYNC_2_FENA            0
#define  QB_TX_FENA_2_FSYNC            20
#define  QB_TX_FSYNC_2_FENA            30
#endif

#ifndef  L1D_CUSTOM_DYNAMIC_SUPPORT
#define  L1D_CUSTOM_DYNAMIC_SUPPORT    0
#endif

#ifndef  L1D_CUSTOM_GPIO_ENABLE
#define  L1D_CUSTOM_GPIO_ENABLE        0
#endif

#ifndef  L1D_CUSTOM_ADC_ENABLE
#define  L1D_CUSTOM_ADC_ENABLE         0
#endif

#ifndef  L1D_CUSTOM_BARCODE_ENABLE
#define  L1D_CUSTOM_BARCODE_ENABLE     0
#endif

/* for the DCS-TD co-existence support */
#ifndef  IS_DCS_NB_WB_SWITCH_ON
#define  IS_DCS_NB_WB_SWITCH_ON        0
#endif

#ifndef  DCS_NB_PATH_SEL
#define  DCS_NB_PATH_SEL               DCS_PATH_SEL
#endif

#ifndef  PDATA_DCS_NB_PR1
#define  PDATA_DCS_NB_PR1              PDATA_DCS_PR1
#endif

#ifndef  PDATA_DCS_NB_PR2
#define  PDATA_DCS_NB_PR2              PDATA_DCS_PR2
#endif

#ifndef  PDATA_DCS_NB_PR3
#define  PDATA_DCS_NB_PR3              PDATA_DCS_PR3
#endif

#ifndef  PDATA_DCS_NB_PR3A
#define  PDATA_DCS_NB_PR3A             PDATA_DCS_NB_PR3
#endif

#ifndef  PDATA_DCS_NB_PR2B
#define  PDATA_DCS_NB_PR2B             PDATA_DCS_NB_PR2
#endif

#ifndef  PDATA_DCS_NB_PR2M1
   #if defined(QB_PR2B) && QB_PR2B<QB_PR2
#define  PDATA_DCS_NB_PR2M1            PDATA_DCS_NB_PR2B
   #else
#define  PDATA_DCS_NB_PR2M1            PDATA_DCS_NB_PR2
   #endif
#endif

#ifndef  PDATA_DCS_NB_PR2M2
#define  PDATA_DCS_NB_PR2M2            PDATA_DCS_NB_PR2M1
#endif

#ifndef  PDATA_DCS_NB_PR2M3
#define  PDATA_DCS_NB_PR2M3            PDATA_DCS_NB_PR2M2
#endif

/*============================================================================== */

#ifdef L1D_TEST
#undef   QB_RX_FENA_2_FSYNC
   #if IS_CHIP_MT6225_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
#define  QB_RX_FENA_2_FSYNC            32
#undef   QB_TX_FENA_2_FSYNC
#define  QB_TX_FENA_2_FSYNC            152
   #else
#define  QB_RX_FENA_2_FSYNC            33   /* this value shall be 4N+1 */
   #endif
   #if IS_EDGE_SAIC_CHIP_MT6256_AND_LATTER_VERSION
#undef   QB_TX_FSYNC_2_FENA
#define  QB_TX_FSYNC_2_FENA            38   /* BFE additional loopback reset delay, tx_off only */
   #endif
#undef   BBTX_IQ_SWAP
#undef   BBRX_IQ_SWAP
#define  BBTX_IQ_SWAP                  0
#define  BBRX_IQ_SWAP                  0
#endif

#if IS_COSIM_ON_L1SIM_SUPPORT
   #if IS_CHIP_MT6583_MD1 || IS_CHIP_MT6583_MD2 || IS_CHIP_MT6572 || IS_CHIP_MT6290
/* since we will advance the BULON timing, we should change the ST1 to make the RF event happened */
#undef   QB_ST1
#define  QB_ST1                        180
   #endif

#undef   QB_RX_ADEN_2_FENA
#undef   QB_RX_FENA_2_ADEN
#undef   QB_TX_DAEN_2_FENA
#undef   QB_TX_FENA_2_DAEN
#define  QB_RX_ADEN_2_FENA             1
#define  QB_RX_FENA_2_ADEN             0
#define  QB_TX_DAEN_2_FENA             1
#define  QB_TX_FENA_2_DAEN             0

#undef   QB_RX_FSYNC_2_FENA
#define  QB_RX_FSYNC_2_FENA            3
#endif

#define  QB_RON_2_FSYNC                0
#define  QB_FSYNC_2_ROFF               0
#define  QB_TON_2_FSYNC                16
#define  QB_FSYNC_2_TOFF               16

#define  TQ_SR0                        (QB_SR0-QB_RON_2_FSYNC)
#define  TQ_SR1                        (QB_SR1-QB_RON_2_FSYNC)
#define  TQ_SR2                        (QB_SR2-QB_RON_2_FSYNC)
#define  TQ_SR2M                       (QB_SR2M-QB_RON_2_FSYNC)
#define  TQ_SR3                        (QB_SR3-QB_FSYNC_2_ROFF)
#define  TQ_PR1                        (QB_PR1-QB_RON_2_FSYNC)
#define  TQ_PR2                        (QB_PR2-QB_RON_2_FSYNC)
#define  TQ_PR2M1                      (QB_PR2M1-QB_RON_2_FSYNC)
#define  TQ_PR2M2                      (QB_PR2M2-QB_RON_2_FSYNC)
#define  TQ_PR3                        (QB_PR3-QB_FSYNC_2_ROFF)
#define  TQ_PR3A                       (QB_PR3A-QB_FSYNC_2_ROFF)

#define  TQ_ST0                        (QB_ST0-QB_TON_2_FSYNC)
#define  TQ_ST1                        (QB_ST1-QB_TON_2_FSYNC)
#define  TQ_ST2                        (QB_ST2-QB_TON_2_FSYNC)
#define  TQ_ST3                        (QB_ST3-QB_FSYNC_2_TOFF)
#define  TQ_PT1                        (QB_PT1-QB_TON_2_FSYNC)
#define  TQ_PT2                        (QB_PT2-QB_TON_2_FSYNC)
#define  TQ_PT2B                       (QB_PT2B-QB_TON_2_FSYNC)
#define  TQ_PT3                        (QB_PT3-QB_FSYNC_2_TOFF)
#define  TQ_PT3A                       (QB_PT3A-QB_FSYNC_2_TOFF)
#define  TQ_APCON                      (QB_APCON-QB_TON_2_FSYNC)
#define  TQ_APCMID                     (QB_APCMID-QB_TON_2_FSYNC)
#define  TQ_APCOFF                     (QB_APCOFF-QB_FSYNC_2_TOFF)
#define  TQ_BDLON                      (QB_RX_FENA_2_FSYNC-QB_RON_2_FSYNC+QB_RX_ADEN_2_FENA)
#define  TQ_BDLOFF                     (-QB_FSYNC_2_ROFF)
#define  TQ_BULON                      (QB_TX_FENA_2_FSYNC-QB_TON_2_FSYNC+QB_TX_DAEN_2_FENA)
#define  TQ_BULOFF                     (-QB_FSYNC_2_TOFF)
#define  TQ_AFC2_2_BOFF                (TQ_BULOFF+QB_TX_FSYNC_2_FENA)

#define  TQ_PR2B                       (QB_PR2B-QB_RON_2_FSYNC)
#define  TQ_PT2M1_G8                   (QB_PT2M1_G8-QB_TON_2_FSYNC)
#define  TQ_PT2M2_G8                   (QB_PT2M2_G8-QB_TON_2_FSYNC)
#define  TQ_PT2M3_G8                   (QB_PT2M3_G8-QB_TON_2_FSYNC)
#define  TQ_PT2M1_8G                   (QB_PT2M1_8G-QB_TON_2_FSYNC)
#define  TQ_PT2M2_8G                   (QB_PT2M2_8G-QB_TON_2_FSYNC)
#define  TQ_PT2M3_8G                   (QB_PT2M3_8G-QB_TON_2_FSYNC)
#define  TQ_ST2B                       (QB_ST2B-QB_TON_2_FSYNC)
#define  TQ_ST2M_G8                    (QB_ST2M_G8-QB_TON_2_FSYNC)
#define  TQ_ST2M_8G                    (QB_ST2M_8G-QB_TON_2_FSYNC)

#if    !defined(QB_PR3) || !defined(QB_SR3)
// no compare QB_PR3 & QB_SR3 in macro
#elif  IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   #if   TQ_PR3A>TQ_SR3 && TQ_PR3A>TQ_PR3
#define  QR_BOFF_2_IDLE                TQ_PR3A
   #elif TQ_PR3 >TQ_SR3 && TQ_PR3>TQ_PR3A
#define  QR_BOFF_2_IDLE                TQ_PR3
   #else
#define  QR_BOFF_2_IDLE                TQ_SR3
   #endif
#else
   #if   TQ_SR3>TQ_PR3
#define  QR_BOFF_2_IDLE                TQ_SR3
   #else
#define  QR_BOFF_2_IDLE                TQ_PR3
   #endif
#endif

#if IS_BBTXRX_CHIP_DESIGN_VER_2 || IS_BBTXRX_CHIP_DESIGN_VER_3
#define QB_BFE_TXCOMP_HYS              1 // BFE TX compensation hysteresis
#else
#define QB_BFE_TXCOMP_HYS              0
#endif

/*--------------------------------------------------------*/
/*   define BDL/BUL data (shall be modified by real case) */
/*--------------------------------------------------------*/

#if IS_TDMA_AD_DA_WINDOW_SUPPORT
#define  BDLCON_DATA                   ( ((QB_RX_ADEN_2_FENA+QB_RX_FENA_2_FSYNC-1)<<8) | ((QB_RX_FSYNC_2_FENA+QB_RX_FENA_2_ADEN)<<0) )
#define  BDLCON2_DATA                  ( ((QB_RX_ADEN_2_FENA                   -1)<<8) | ((QB_RX_FSYNC_2_FENA                  )<<0) )
#define  BULCON1_DATA                  ( ((QB_TX_DAEN_2_FENA+QB_TX_FENA_2_FSYNC-1)<<8) | ((QB_TX_FSYNC_2_FENA+QB_TX_FENA_2_DAEN)<<0) )
   #if IS_BBTXRX_CHIP_DESIGN_VER_3
/* BFE_TXCOMP_HYS[15:8] in BULCON2 is moved to TX_CNT_TGT[7:0] in TX_CON1 */
#define  BULCON2_DATA                  (                                                 ((QB_TX_DAEN_2_FENA+QB_TX_FENA_2_FSYNC-QB_APCDACON)&0x0FF) )
   #else
#define  BULCON2_DATA                  ( ((QB_BFE_TXCOMP_HYS                     )<<8) | ((QB_TX_DAEN_2_FENA+QB_TX_FENA_2_FSYNC-QB_APCDACON)&0x0FF) )
   #endif
#define  BULCON3_DATA                  ( ((QB_TX_DAEN_2_FENA                   -1)<<8) | ((QB_TX_FSYNC_2_FENA                  )<<0) )
#else
#define  BDLCON_DATA                   ( ((                  QB_RX_FENA_2_FSYNC-1)<<8) | ((QB_RX_FSYNC_2_FENA                  )<<0) )
#define  BULCON1_DATA                  ( ((                  QB_TX_FENA_2_FSYNC-1)<<8) | ((QB_TX_FSYNC_2_FENA                  )<<0) )
#define  BULCON2_DATA                  ( ((QB_BFE_TXCOMP_HYS                     )<<8) | ((QB_TX_FENA_2_FSYNC-QB_APCDACON)&0x0FF) )
#endif

/*---------------------------------------------------------------------------*/
#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   #if IS_CHIP_MT6580
   /*  0 -->61.44/ 1=61.44  MHz   */
   /*  1 -->61.44/ 2=30.72  MHz   */
   /*  2 -->61.44/ 3=20.48  MHz   */
   /*  3 -->61.44/ 4=15.36  MHz   */
   /*  4 -->61.44/ 6=10.24  MHz   */
   /*  5 -->61.44/ 8= 7.68  MHz   */
   /*  6 -->61.44/12= 5.12  MHz   */
   /*  7 -->61.44/16= 3.84  MHz   */
      #if IS_RF_MT6580RF || IS_COSIM_ON_L1SIM_SUPPORT
#define BSI_CLK_SPD                    0
      #else
#error
      #endif
   #elif IS_CHIP_MT6571
   /*  0 -->61.44/ 1=61.44  MHz   */
   /*  1 -->61.44/ 2=30.72  MHz   */
   /*  2 -->61.44/ 3=20.48  MHz   */
   /*  3 -->61.44/ 4=15.36  MHz   */
   /*  4 -->61.44/ 6=10.24  MHz   */
   /*  5 -->61.44/ 8= 7.68  MHz   */
   /*  6 -->61.44/12= 5.12  MHz   */
   /*  7 -->61.44/16= 3.84  MHz   */
#define BSI_CLK_SPD                    0
   #elif IS_CHIP_MT6572
   /*  0 -->61.44/ 1=61.44  MHz   */
   /*  1 -->61.44/ 2=30.72  MHz   */
   /*  2 -->61.44/ 3=20.48  MHz   */
   /*  3 -->61.44/ 4=15.36  MHz   */
   /*  4 -->61.44/ 6=10.24  MHz   */
   /*  5 -->61.44/ 8= 7.68  MHz   */
   /*  6 -->61.44/12= 5.12  MHz   */
   /*  7 -->61.44/16= 3.84  MHz   */
      #if IS_RF_MT6166 || IS_COSIM_ON_L1SIM_SUPPORT
#define BSI_CLK_SPD                    0
      #else
#error
      #endif
   #elif IS_CHIP_MT6583_MD1 || IS_CHIP_MT6583_MD2
   /*  0 -->122.88/ 2=61.44  MHz   */
   /*  1 -->122.88/ 4=30.72  MHz   */
   /*  2 -->122.88/ 6=20.48  MHz   */
   /*  3 -->122.88/ 8=15.36  MHz   */
   /*  4 -->122.88/12=10.24  MHz   */
   /*  5 -->122.88/16= 7.68  MHz   */
   /*  6 -->122.88/24= 5.12  MHz   */
   /*  7 -->122.88/32= 3.84  MHz   */
      #if IS_RF_MT6167
#define BSI_CLK_SPD                    0
      #elif IS_RF_MT6163
#define BSI_CLK_SPD                    0
      #elif IS_COSIM_ON_L1SIM_SUPPORT
#define BSI_CLK_SPD                    0
      #else
#error
      #endif
   #elif IS_EDGE_SAIC_CHIP_MT6270A_AND_LATTER_VERSION || IS_CHIP_MT6268H || IS_CHIP_MT6280
      #if IS_CHIP_MT6268T_DMAC
   /*  0 --> 30.72/ 2=15.36  MHz   */
   /*  1 --> 30.72/ 4= 7.68  MHz   */
   /*  2 --> 30.72/ 6= 5.12  MHz   */
   /*  3 --> 30.72/ 8= 3.84  MHz   */
   /*  4 --> 30.72/12= 2.56  MHz   */
   /*  5 --> 30.72/16= 1.92  MHz   */
   /*  6 --> 30.72/24= 1.28  MHz   */
   /*  7 --> 30.72/32= 0.96  MHz   */
#define BSI_CLK_SPD                    1
      #else
   /*  0 -->122.88/ 2=61.44  MHz   */
   /*  1 -->122.88/ 4=30.72  MHz   */
   /*  2 -->122.88/ 6=20.48  MHz   */
   /*  3 -->122.88/ 8=15.36  MHz   */
   /*  4 -->122.88/12=10.24  MHz   */
   /*  5 -->122.88/16= 7.68  MHz   */
   /*  6 -->122.88/24= 5.12  MHz   */
   /*  7 -->122.88/32= 3.84  MHz   */
         #if IS_RF_MT6162 || IS_RF_MT6163 || IS_RF_MT6280RF
#define BSI_CLK_SPD                    0
         #else
#define BSI_CLK_SPD                    5
         #endif
      #endif
   #elif IS_CHIP_MT6268
      #if IS_CHIP_MT6268A// MT6268A DCM hardware bug, raise the BSI clock
   /*  0 --> 30.72/2 =15.36  MHz   */
   /*  1 --> 30.72/4 = 7.68  MHz   */
   /*  2 --> 30.72/6 = 5.12  MHz   */
   /*  3 --> 30.72/8 = 3.84  MHz   */
#define BSI_CLK_SPD                    0
      #else
   /*  0 --> 30.72/2 =15.36  MHz   */
   /*  1 --> 30.72/4 = 7.68  MHz   */
   /*  2 --> 30.72/6 = 5.12  MHz   */
   /*  3 --> 30.72/8 = 3.84  MHz   */
#define BSI_CLK_SPD                    1
      #endif
   #elif IS_CHIP_MT6268T
   /*  0 --> 30.72/2 =15.36  MHz   */
   /*  1 --> 30.72/4 = 7.68  MHz   */
   /*  2 --> 30.72/6 = 5.12  MHz   */
   /*  3 --> 30.72/8 = 3.84  MHz   */
#define BSI_CLK_SPD                    1
   #elif IS_CHIP_MT6256 || IS_CHIP_MT6255
   /*  0 --> 52/2    =26     MHz   */
   /*  1 --> 52/4    =13     MHz   */
   /*  2 --> 52/6    = 8.67  MHz   */
   /*  3 --> 52/8    = 6.5   MHz   */
#define BSI_CLK_SPD                    0
   #elif IS_CHIP_MT6250
   /*  0 --> 130/ 2  =65     MHz   */
   /*  1 --> 130/ 4  =32.5   MHz   */
   /*  2 --> 130/ 6  =21.67  MHz   */
   /*  3 --> 130/ 8  =16.25  MHz   */
   /*  4 --> 130/12  =10.83  MHz   */
   /*  5 --> 130/16  = 8.13  MHz   */
   /*  6 --> 130/24  = 5.42  MHz   */
   /*  7 --> 130/32  = 4.06  MHz   */
#define BSI_CLK_SPD                    0
   #elif IS_CHIP_MT6251
   /*  0 --> 52/2    =26     MHz   */
   /*  1 --> 52/4    =13     MHz   */
   /*  2 --> 52/6    = 8.67  MHz   */
   /*  3 --> 52/8    = 6.5   MHz   */
#define BSI_CLK_SPD                    1
   #elif IS_CHIP_MT6252_S00
   /*  0 --> 52/2    =26     MHz   */
   /*  1 --> 52/4    =13     MHz   */
   /*  2 --> 52/6    = 8.67  MHz   */
   /*  3 --> 52/8    = 6.5   MHz   */
#define BSI_CLK_SPD                    3
   #elif IS_CHIP_MT6252
   /*  0 --> 52/2    =26     MHz   */
   /*  1 --> 52/4    =13     MHz   */
   /*  2 --> 52/6    = 8.67  MHz   */
   /*  3 --> 52/8    = 6.5   MHz   */
#define BSI_CLK_SPD                    0
   #elif IS_CHIP_MT6229_S01 || IS_CHIP_MT6229_S00 || IS_SAIC_CHIP_MT6223_AND_LATTER_VERSION
   /*  0 --> 52/2    =26     MHz   */
   /*  1 --> 52/4    =13     MHz   */
   /*  2 --> 52/6    = 8.67  MHz   */
   /*  3 --> 52/8    = 6.5   MHz   */
#define BSI_CLK_SPD                    3
   #else
   /*  0 --> 26/2    =13     MHz   */
   /*  1 --> 26/4    = 6.5   MHz   */
   /*  2 --> 26/6    = 4.33  MHz   */
   /*  3 --> 26/8    = 3.25  MHz   */
#define BSI_CLK_SPD                    1
   #endif
#else
   /*  0 --> 13/2    = 6.5   MHz   */
   /*  1 --> 13/4    = 3.25  MHz   */
   /*  2 --> 13/6    = 2.167 MHz   */
   /*  3 --> 13/8    = 1.625 MHz   */
#define BSI_CLK_SPD                    0
#endif

#if IS_CHIP_MT6250
#define  BSI_ENA_LEN       0
#define  BSI_ENA_POL       0
#define  SCTRL_IMOD_MAIN   (0x0001| ((BSI_CLK_SPD&0x7)<<2)|(BSI_ENA_LEN<<16)|(BSI_ENA_POL<<18)) /* SRCB main control:SRCB TSU event trigger */
#define  SCTRL_IMOD_SEND   (0x0401| ((BSI_CLK_SPD&0x7)<<2)|(BSI_ENA_LEN<<16)|(BSI_ENA_POL<<18)) /* trigger to send SDATA in IMODE           */
#define  SCTRL_MAIN        SCTRL_IMOD_MAIN
#elif IS_CHIP_MT6583_MD2
/* only one port is in MT6583 MD2 */
#define  BSI_PORTA_SELECT  (BSI_PORT_SELECT==0)
#define  BSI_CS0_SELECT    (BSI_CS_SELECT  ==0)
#define  BSI_CS1_SELECT    (BSI_CS_SELECT  ==1)
#define  BSI_DEVICE_A_0_CS (((BSI_PORTA_SELECT&BSI_CS0_SELECT)<<3)|((BSI_DEVICE_0_CS_POLARITY&0x2)<<1)|(BSI_DEVICE_0_CS_POLARITY&0x1))
#define  BSI_DEVICE_A_1_CS (((BSI_PORTA_SELECT&BSI_CS1_SELECT)<<3)|((BSI_DEVICE_1_CS_POLARITY&0x2)<<1)|(BSI_DEVICE_1_CS_POLARITY&0x1))
#define  SCTRL_IMOD_MAIN   ((BSI_CLK_POL)|((BSI_CLK_SPD&0x7)<<2)|(0x0<<10)|(BSI_DEVICE_A_0_CS<<16)|(BSI_DEVICE_A_1_CS<<20))               /* SRCB main control:SRCB TSU event trigger */
#define  SCTRL_IMOD_SEND   ((BSI_CLK_POL)|((BSI_CLK_SPD&0x7)<<2)|(0x1<<10)|(BSI_DEVICE_A_0_CS<<16)|(BSI_DEVICE_A_1_CS<<20))               /* trigger to send SDATA in IMODE           */
#define  SCTRL_MAIN        SCTRL_IMOD_MAIN
#elif IS_CHIP_MT6280 || IS_CHIP_MT6583_MD1 || IS_CHIP_MT6572
#define  BSI_PORTA_SELECT  (BSI_PORT_SELECT==0)
#define  BSI_PORTB_SELECT  (BSI_PORT_SELECT==1)
#define  BSI_PORTC_SELECT  (BSI_PORT_SELECT==2)
#define  BSI_CS0_SELECT    (BSI_CS_SELECT  ==0)
#define  BSI_CS1_SELECT    (BSI_CS_SELECT  ==1)
#define  BSI_DEVICE_A_0_CS (((BSI_PORTA_SELECT&BSI_CS0_SELECT)<<3)|(BSI_DEVICE_0_CS_POLARITY&0x7))
#define  BSI_DEVICE_A_1_CS (((BSI_PORTA_SELECT&BSI_CS1_SELECT)<<3)|(BSI_DEVICE_1_CS_POLARITY&0x7))
#define  BSI_DEVICE_B_0_CS (((BSI_PORTB_SELECT&BSI_CS0_SELECT)<<3)|(BSI_DEVICE_0_CS_POLARITY&0x7))
#define  BSI_DEVICE_B_1_CS (((BSI_PORTB_SELECT&BSI_CS1_SELECT)<<3)|(BSI_DEVICE_1_CS_POLARITY&0x7))
#define  SCTRL_IMOD_MAIN   ((BSI_CLK_POL)|((BSI_CLK_SPD&0x7)<<2)|(0x0<<10)|(BSI_DEVICE_A_0_CS<<16)|(BSI_DEVICE_A_1_CS<<20)|(BSI_DEVICE_B_0_CS<<24)|(BSI_DEVICE_B_1_CS<<28))               /* SRCB main control:SRCB TSU event trigger */
#define  SCTRL_IMOD_SEND   ((BSI_CLK_POL)|((BSI_CLK_SPD&0x7)<<2)|(0x1<<10)|(BSI_DEVICE_A_0_CS<<16)|(BSI_DEVICE_A_1_CS<<20)|(BSI_DEVICE_B_0_CS<<24)|(BSI_DEVICE_B_1_CS<<28))               /* trigger to send SDATA in IMODE           */
#define  SCTRL_MAIN        SCTRL_IMOD_MAIN
#elif IS_EDGE_SAIC_CHIP_MT6270A_AND_LATTER_VERSION || IS_CHIP_MT6268H
#define  BSI_PORTA_SELECT  ((~BSI_PORT_SELECT&0x1))
#define  BSI_PORTB_SELECT  (( BSI_PORT_SELECT&0x1))
#define  BSI_DEVICE_A_0_CS ((0x8*BSI_PORTA_SELECT)|((BSI_DEVICE_0_CS_POLARITY&0x2)<<1)|(BSI_DEVICE_0_CS_POLARITY&0x1))
#define  BSI_DEVICE_A_1_CS ((0x0*BSI_PORTA_SELECT)|((BSI_DEVICE_1_CS_POLARITY&0x2)<<1)|(BSI_DEVICE_1_CS_POLARITY&0x1))
#define  BSI_DEVICE_B_0_CS ((0x8*BSI_PORTB_SELECT)|((BSI_DEVICE_0_CS_POLARITY&0x2)<<1)|(BSI_DEVICE_0_CS_POLARITY&0x1))
#define  BSI_DEVICE_B_1_CS ((0x0*BSI_PORTB_SELECT)|((BSI_DEVICE_1_CS_POLARITY&0x2)<<1)|(BSI_DEVICE_1_CS_POLARITY&0x1))
#define  SCTRL_IMOD_MAIN   (0x0001| ((BSI_CLK_SPD&0x7)<<2)|(BSI_DEVICE_A_0_CS<<16)|(BSI_DEVICE_A_1_CS<<20)|(BSI_DEVICE_B_0_CS<<24)|(BSI_DEVICE_B_1_CS<<28))                                /* SRCB main control:SRCB TSU event trigger */
#define  SCTRL_IMOD_SEND   (0x0401| ((BSI_CLK_SPD&0x7)<<2)|(BSI_DEVICE_A_0_CS<<16)|(BSI_DEVICE_A_1_CS<<20)|(BSI_DEVICE_B_0_CS<<24)|(BSI_DEVICE_B_1_CS<<28))                                /* trigger to send SDATA in IMODE           */
#define  SCTRL_MAIN        SCTRL_IMOD_MAIN
#elif IS_CHIP_MT6268T || IS_CHIP_MT6268
#define  SCTRL_IMOD_MAIN   (0x0101| ((BSI_CLK_SPD&0x3)<<1) |(BSI_DEVICE_0_CS_POLARITY<<4)|(BSI_DEVICE_1_CS_POLARITY<<6) |(BSI_DEVICE_0_CS_POLARITY<<12)|(BSI_DEVICE_1_CS_POLARITY<<14))    /* Wirte SDATA to active buffer for IMODE   */
#define  SCTRL_IMOD_SEND   (0x0009| ((BSI_CLK_SPD&0x3)<<1) |(BSI_DEVICE_0_CS_POLARITY<<4)|(BSI_DEVICE_1_CS_POLARITY<<6) |(BSI_DEVICE_0_CS_POLARITY<<12)|(BSI_DEVICE_1_CS_POLARITY<<14))    /* trigger to send SDATA in IMODE           */
#define  SCTRL_MAIN        (0x0001| ((BSI_CLK_SPD&0x3)<<1) |(BSI_DEVICE_0_CS_POLARITY<<4)|(BSI_DEVICE_1_CS_POLARITY<<6) |(BSI_DEVICE_0_CS_POLARITY<<12)|(BSI_DEVICE_1_CS_POLARITY<<14))    /* SRCB main control:SRCB TSU event trigger */
#else
#define  SCTRL_IMOD_MAIN   (0x0101| ((BSI_CLK_SPD&0x3)<<1) |(BSI_DEVICE_0_CS_POLARITY<<4)|(BSI_DEVICE_1_CS_POLARITY<<6))    /* Wirte SDATA to active buffer for IMODE   */
#define  SCTRL_IMOD_SEND   (0x0009| ((BSI_CLK_SPD&0x3)<<1) |(BSI_DEVICE_0_CS_POLARITY<<4)|(BSI_DEVICE_1_CS_POLARITY<<6))    /* trigger to send SDATA in IMODE           */
#define  SCTRL_MAIN        (0x0001| ((BSI_CLK_SPD&0x3)<<1) |(BSI_DEVICE_0_CS_POLARITY<<4)|(BSI_DEVICE_1_CS_POLARITY<<6))    /* SRCB main control:SRCB TSU event trigger */
#endif

#if IS_EDGE_SAIC_CHIP_MT6256_AND_LATTER_VERSION
   #if IS_CHIP_MT6256_S00
#define  SCTRL_RESERVED                0x0024
   #elif IS_CHIP_MT6256 || IS_CHIP_MT6255 || IS_CHIP_MT6250
#define  SCTRL_RESERVED                0x0015
   #elif IS_CHIP_MT6572
#define  SCTRL_RESERVED                0x0036 // the number of event is 54
   #elif IS_CHIP_MT6280 || IS_CHIP_MT6583_MD1 || IS_CHIP_MT6583_MD2
#define  SCTRL_RESERVED                0x002A // MT6270A E2, MT6276E2 is 42
   #else
#define  SCTRL_RESERVED                0x0024
   #endif
#elif IS_CHIP_MT6268H || IS_CHIP_MT6268T_DMAC
#define  SCTRL_RESERVED                0x0024
#elif IS_EDGE_SAIC_CHIP_MT6270A_AND_LATTER_VERSION
   #if IS_CHIP_MT6270A_E1 || IS_CHIP_MT6276_S00 || IS_CHIP_MT6573
#define  SCTRL_RESERVED                0x0024 // MT6270A E1, MT6276E1, MT6573E1 and MT6573E2 is 36
   #else
#define  SCTRL_RESERVED                0x002A // MT6270A E2, MT6276E2 is 42
   #endif
#elif IS_CHIP_MT6252
#define  SCTRL_RESERVED                0x0015
#elif IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
#define  SCTRL_RESERVED                0x0014
#else
#define  SCTRL_RESERVED                0x0010
#endif

#if IS_CHIP_MT6252_S00
#define  IMM_BSI_WAIT_TIME_QB          16
#elif IS_CHIP_MT6280 || IS_RF_MT6167 || IS_RF_MT6166 || IS_RF_MT6165
#define  IMM_BSI_WAIT_TIME_QB          2
#elif IS_CHIP_MT6256 || IS_CHIP_MT6251 || IS_CHIP_MT6252 || IS_RF_MT6162 || IS_CHIP_MT6255 || IS_RF_MT6163 || IS_CHIP_MT6250
#define  IMM_BSI_WAIT_TIME_QB          6
#else
/*Maximum Safe Time: eg. 1 QB = 13/12, BSI_CLK = 13/6 => 1 QB = 2 BSI bit, 16 QB = 32 BSI bit */
#define  IMM_BSI_WAIT_TIME_QB          16
#endif

#if IS_CHIP_MT6572
#define  BSI_ACTUPT_ALL                0xC0FF
#elif IS_EDGE_SAIC_CHIP_MT6270A_AND_LATTER_VERSION || IS_CHIP_MT6268H || IS_CHIP_MT6280 || IS_CHIP_MT6583_MD1 || IS_CHIP_MT6583_MD2
#define  BSI_ACTUPT_ALL                0xC07F
#elif IS_CHIP_MT6250
#define  BSI_ACTUPT_ALL                0xC03F
#endif

/*---------------------------------------------------------------------------*/

#if !IS_RTX_5CWIN_SUPPORT // IS_GSM
/*GSM*/  #define  CWIN_COUNT           4
/*GSM*/  #define  RIDX_COUNT           5 // X0~3 for RX, X4 for TX
/*GSM*/  #define  YIDX_COUNT           0
#endif

#if IS_RTX_5CWIN_SUPPORT // IS_GPRS
/*GPRS*/ #define  CWIN_COUNT           5
   #if IS_BSI_V2_SUPPORT
/*GPRS*/ #define  RIDX_COUNT           6
/*GPRS*/ #define  YIDX_COUNT           0
   #else
/*GPRS*/ #define  RIDX_COUNT           6
/*GPRS*/ #define  YIDX_COUNT           4
   #endif

   #if IS_BSI_V2_ST2_SUPPORT
/*GPRS*/ #undef   RIDX_COUNT
/*GPRS*/ #define  RIDX_COUNT           7
   #endif
#endif

#if IS_BSI_SX0_SUPPORT
#define  CWIN_BSI_EVENT_COUNT          3
#define  SR1_EVENT_OFFSET              1
#else
#define  CWIN_BSI_EVENT_COUNT          2
#define  SR1_EVENT_OFFSET              0
#endif

#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
#define  ST2B_ST2M_EV0                 (CWIN_BSI_EVENT_COUNT*CWIN_COUNT+RIDX_COUNT)
#define  ST2B_2M_EV(n)                 (ST2B_ST2M_EV0+(n))
#endif

#if IS_BSI_V2_SUPPORT
#define  BSI_DATA_OFFSET               (SX2_DATA_COUNT*RIDX_COUNT)
#elif IS_BSI_DATA_TABLE_Y_SHIFT
#define  BSI_DATA_OFFSET               (ST2B_ST2M_DATA_COUNT*YIDX_COUNT)
#else
#define  BSI_DATA_OFFSET               0
#endif

#if IS_BSI_V2_SUPPORT
#define  AGCDT0                        0
#else
#define  AGCDT0                        ((SX0_DATA_COUNT+SX1_DATA_COUNT+SX3_DATA_COUNT)*CWIN_COUNT+BSI_DATA_OFFSET)
#endif
#define  AGCDTIDX(n)                   (AGCDT0+(n)*SX2_DATA_COUNT)

#if IS_BSI_DATA_TABLE_Y_SHIFT || IS_BSI_V2_SUPPORT
#define  ST2B_ST2M_0                   0
#else
#define  ST2B_ST2M_0                   (AGCDT0+SX2_DATA_COUNT*RIDX_COUNT)
#endif
#define  ST2B_ST2M_IDX(n)              (ST2B_ST2M_0+(n)*ST2B_ST2M_DATA_COUNT)

#if IS_CHIP_MT6580
#define  BSI_PORT_SELECT_MASK        0x3  /* Support three ports            */
   #if IS_RF_MT6580RF || IS_COSIM_ON_L1SIM_SUPPORT
#define  BSI_PORT_SELECT               0  /* MT6580 uses port A             */
#define  BSI_CS_SELECT                 0  /* MT6580 uses CS0                */
#define  BSI_CLK_POL                   1  /* Inverted enable pulse polarity */
#define  IDLE_CNT                      0
   #else
#error
   #endif
#elif IS_CHIP_MT6571
#define  BSI_PORT_SELECT_MASK        0x3  /* Support three ports            */
   #if IS_RF_MT6165 || IS_COSIM_ON_L1SIM_SUPPORT
#define  BSI_PORT_SELECT               0  /* MT6165 uses port A             */
#define  BSI_CS_SELECT                 0  /* MT6165 uses CS0                */
#define  BSI_CLK_POL                   1  /* Inverted enable pulse polarity */
#define  IDLE_CNT                      0
   #else
#error
   #endif
#elif IS_CHIP_MT6572
#define  BSI_PORT_SELECT_MASK        0x3  /* Support three ports            */
   #if IS_RF_MT6166 || IS_COSIM_ON_L1SIM_SUPPORT
#define  BSI_PORT_SELECT               0  /* MT6166 uses port A             */
#define  BSI_CS_SELECT                 0  /* MT6166 uses CS0                */
#define  BSI_CLK_POL                   1  /* Inverted enable pulse polarity */
#define  IDLE_CNT                      0
   #else
#error
   #endif
#elif IS_CHIP_MT6583_MD2
#define  BSI_PORT_SELECT_MASK        0x1  /* Support one port               */
   #if IS_RF_MT6163 || IS_COSIM_ON_L1SIM_SUPPORT
#define  BSI_PORT_SELECT               0  /* OT RF uses port A on MT6583    */
#define  BSI_CS_SELECT                 0  /* OT RF uses CS0                 */
#define  BSI_CLK_POL                   1  /* Inverted enable pulse polarity */
#define  IDLE_CNT                      0
   #else
#error
   #endif
#elif IS_CHIP_MT6583_MD1
#define  BSI_PORT_SELECT_MASK        0x3  /* Support three ports            */
   #if IS_RF_MT6167 || IS_COSIM_ON_L1SIM_SUPPORT
#define  BSI_PORT_SELECT               0  /* MT6167 uses port A             */
#define  BSI_CS_SELECT                 0  /* MT6167 uses CS0                */
#define  BSI_CLK_POL                   1  /* Inverted enable pulse polarity */
#define  IDLE_CNT                      0
   #else
#error
   #endif
#elif IS_CHIP_MT6280
#define  BSI_PORT_SELECT_MASK        0x3  /* Support three ports            */
#define  BSI_PORT_SELECT               0  /* MT6280 RF uses port A          */
#define  BSI_CS_SELECT                 0  /* MT6280 RF uses CS0             */
#define  BSI_CLK_POL                   1  /* Inverted enable pulse polarity */
#define  IDLE_CNT                      0
#elif IS_CHIP_MT6250
#define  IDLE_CNT                      0
#elif IS_EDGE_SAIC_CHIP_MT6270A_AND_LATTER_VERSION || IS_CHIP_MT6268H
#define  BSI_PORT_SELECT_MASK        0x1  /* Support two ports              */
   #if IS_RF_MT6162 || IS_RF_MT6163
#define  BSI_PORT_SELECT               1  /* OH RF uses port B              */
#define  IDLE_CNT                      0
   #else
#define  BSI_PORT_SELECT               0  /* OE RF uses port A              */
#define  IDLE_CNT                      2
   #endif
#endif


#if IS_RF_MT6280RF
#define  AFC_SHIFT_PART                7
#define  AFC_MASK_PART                 (0x1FFF<<AFC_SHIFT_PART)
      #ifdef AFC_VCXO
#define  AFC_VALUE_PART                0x0F70003C // CW247
      #else
#define  AFC_VALUE_PART                0x0FE00008 // CW254
      #endif
#define  AFC_CON_PART                  ((BSI_CS_SELECT<<15)|((29-1)<<8)|(BSI_PORT_SELECT<<6)|(BSI_CLK_SPD<<3)|(BSI_CLK_POL<<1)|(1))
#elif IS_RF_MT6167
#define  AFC_SHIFT_PART                7
#define  AFC_MASK_PART                 (0x1FFF<<AFC_SHIFT_PART)
      #ifdef AFC_VCXO
#define  AFC_VALUE_PART                0x0F70003C // CW247
      #else
#define  AFC_VALUE_PART                0x0FE00000 // CW254
      #endif
#define  AFC_CON_PART                  ((BSI_CS_SELECT<<15)|((30-1)<<8)|(BSI_PORT_SELECT<<6)|(BSI_CLK_SPD<<3)|(BSI_CLK_POL<<1)|(1)) //BSI Data for MT6167 is 30bit
#elif IS_RF_MT6166
#define  AFC_SHIFT_PART                7
#define  AFC_MASK_PART                 (0x1FFF<<AFC_SHIFT_PART)
      #ifdef AFC_VCXO
#define  AFC_VALUE_PART                (POR_CW247 & 0x0F70007F) // CW247
      #else
#define  AFC_VALUE_PART                0x0FE00000 // CW254
      #endif
#define  AFC_CON_PART                  ((BSI_CS_SELECT<<15)|((30-1)<<8)|(BSI_PORT_SELECT<<6)|(BSI_CLK_SPD<<3)|(BSI_CLK_POL<<1)|(1)) //BSI Data for MT6167 is 30bit
#elif IS_RF_MT6580RF
#define  AFC_SHIFT_PART                7
#define  AFC_MASK_PART                 (0x1FFF<<AFC_SHIFT_PART)
      #ifdef AFC_VCXO
#define  AFC_VALUE_PART                (POR_CW247 & 0x0F70007F) // CW247
      #else
#error "MT6580RF doesn't support AFC_VCXO_TYPE = VCTCXO"
      #endif
#define  AFC_CON_PART                  ((BSI_CS_SELECT<<15)|((30-1)<<8)|(BSI_PORT_SELECT<<6)|(BSI_CLK_SPD<<3)|(BSI_CLK_POL<<1)|(1)) //BSI Data for MT6167 is 30bit
#elif IS_RF_MT6165
#define  AFC_SHIFT_PART                7
#define  AFC_MASK_PART                 (0x1FFF<<AFC_SHIFT_PART)
      #ifdef AFC_VCXO
#define  AFC_VALUE_PART                (POR_CW247 & 0x0F70007F) // CW247
      #else
#error "MT6165 doesn't support AFC_VCXO_TYPE = VCTCXO"
      #endif
#define  AFC_CON_PART                  ((BSI_CS_SELECT<<15)|((30-1)<<8)|(BSI_PORT_SELECT<<6)|(BSI_CLK_SPD<<3)|(BSI_CLK_POL<<1)|(1)) //BSI Data for MT6167 is 30bit
#elif IS_RF_MT6162
#define  AFC_SHIFT_PART                0x0
#define  AFC_MASK_PART                 0x1FFF
#define  AFC_VALUE_PART                0xE100000
#define  AFC_CON_PART                  ((0<<15)|((30-1)<<8)|(BSI_PORT_SELECT<<7)|(BSI_CLK_SPD<<3)|(1<<1)|(1))
#endif

#if IS_GSM_BPI_MASK_NEEDED
   #if IS_CHIP_MT6572
#define  BPI_MASK_VALUE                (1<<19) // bit[19] should be masked for 3G
   #else
#error "please check the mask bit for the other RAT!"
   #endif
#endif

/*---------------------------------------------------------------------------*/
#endif

