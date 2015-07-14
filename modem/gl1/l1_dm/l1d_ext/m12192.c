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
 *   m12192.c
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   Setup Gain
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Revision:   1.49  $
 * $Modtime:   Jul 29 2005 13:45:34  $
 * $Log:   //mtkvs01/vmdata/Maui_sw/archives/mcu/l1/l1d/m12192.c-arc  $
 *
 * 03 26 2015 hosen.chen
 * [MOLY00104456] [L1D][Modify] Check in Rainier RF driver before E2
 * 	.
 *
 * 03 03 2015 hosen.chen
 * [MOLY00094981] [L1D][Modify] Check in MT6580/Rainier RF driver
 * 	Rainier RF driver merge back to WR8 MP branch.
 *
 * 01 14 2014 yi-ying.lin
 * [MOLY00053618] [Volunteer Patch][L1D][Modify] Add coband gain table for daul talk project
 * 	.
 *
 * 09 16 2013 ola.lee
 * [MOLY00037846] [MT6571][MOLY NOT NEED][Volunteer Patch] Update MT6571 Bring Up Setting and W Cancellation.
 *
 * 08 22 2013 vend_cuthbert.kao
 * [MOLY00034524] [MT6592][MT6571][L1D][Modify] MT6592 BB Driver + MT6571 BB Driver + MT6165 RF Driver integration
 * .
 *
 * 04 25 2013 yi-ying.lin
 * [MOLY00020777] [L1D][Modify] Fix build warning for MT6166
 * .
 *
 * 03 05 2013 yi-ying.lin
 * [MOLY00011266] [L1D][Modify] MT6166 RF driver development
 * .
 *
 * 02 21 2013 yi-ying.lin
 * [MOLY00010384] [L1D][Modify][MT6572 Bring-up] MT6166 RF driver development
 * .
 *
 * 02 20 2013 yi-ying.lin
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
 * 11 02 2012 hosen.chen
 * [MOLY00005695] [L1D][Modify] Modify the gain searching procedure of OT
 * .
 *
 * 08 30 2012 yuyang.hsiao
 * [MOLY00002880] [L1D][Modify] Correct the index of runtime DCOC table
 * .
 *
 * 08 23 2012 ola.lee
 * [MOLY00002567] [L1D][Modify] Check-in MT6583/MT6167 Codes
 * .
 *
 * 07 02 2012 ola.lee
 * [MOLY00000200] [L1D][Modify]Improve RF_RX_DCOC precision.
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
 * 12 02 2011 th.yeh
 * removed!
 * .
 *
 * 11 17 2011 chang-kuan.lin
 * removed!
 * .
 *
 * 11 11 2011 victo.chen
 * removed!
 * .
 *
 * 10 27 2011 victo.chen
 * removed!
 * .
 *
 * 10 21 2011 th.yeh
 * removed!
 * .
 *
 * 07 19 2011 victo.chen
 * removed!
 * .
 *
 * 06 18 2011 victo.chen
 * removed!
 * .
 *
 * 03 11 2011 sean.yang
 * removed!
 * .
 *
 * 01 25 2011 victo.chen
 * removed!
 * .
 *
 * 01 04 2011 sean.yang
 * removed!
 * .
 *
 * 12 20 2010 sean.yang
 * removed!
 * .
 *
 * 12 08 2010 chuwei.lo
 * removed!
 * .
 *
 * 11 24 2010 sean.yang
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
 * 08 25 2010 max.weng
 * removed!
 * .
 *
 * 08 07 2010 samuel.yang
 * removed!
 * .
 *
 * 07 27 2010 yr.chiang
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
 * [L1D][Modify] Check in AD6546 RF Driver #if IS_RF_AD6546
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
 * Modify the SKY74137 driver that we do not use short mode on the interslot
 *
 * removed!
 * removed!
 * < Triple850>
 * RF chip gets GSM900 signal from GSm850 input pins  to avoid getting GSM900 signal
 *
 * removed!
 * removed!
 * Add code to support GSM850 signal received through GSM900 path
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
 * Modify the SKY74137 gain table
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
 *    Rev 1.49   Jul 29 2005 14:01:38   mtk00773
 * [L1D][Enhence] Support RF SKY74117
 * Resolution for 12111: [L1D][Enhence] Support RF SKY74117
 *
 *    Rev 1.48   Jul 08 2005 16:53:04   mtk00939
 * [L1D][Modify]L1D add code for MT6139C and META related code
 *
 *    Rev 1.47   May 17 2005 00:34:38   BM_Trunk
 * Karlos:
 * add copyright and disclaimer statement
 *
 *    Rev 1.46   May 16 2005 11:46:24   mtk00240
 * Support 22 BPI setting & current sense PA
 * Resolution for 11091: [L1D][New Feature] Support 22 BPI setting & current sense PA
 *
 *    Rev 1.45   Jan 18 2005 00:38:08   BM
 * append new line in W05.04
 *
 *    Rev 1.44   Jan 10 2005 12:18:52   mtk00939
 * Do some modify for MT6129D driver to support GSM850
 * Resolution for 9426: [L1D][modify] modified for MT6129D driver to support GSM850
 *
 *    Rev 1.43   Jan 10 2005 10:38:16   mtk00939
 * Do some modify for MT6129D driver to support GSM850
 * Resolution for 9426: [L1D][modify] modified for MT6129D driver to support GSM850
 *
 *    Rev 1.42   Oct 01 2004 21:25:36   mtk00703
 * use const declaration on AGC_TABLE to lower cost of GSM project.
 * Resolution for 7997: [L1D][Modify]Reduce RAM Size for LOW cost GSM project
 *
 *    Rev 1.41   Sep 16 2004 15:56:30   mtk00773
 * To clear warning message
 * Resolution for 7712: [L1D][Modify] Modify POLARIS1 setting
 *
 *    Rev 1.40   Aug 19 2004 15:31:04   mtk00240
 * Update Aero1Plus latest setting
 * Resolution for 6925: [L1D][Enhance] L1D add code to support AERO1Plus RF chip
 *
 *    Rev 1.39   Jul 30 2004 17:37:06   mtk00240
 * L1D add code to support AERO1Plus RF chip
 * Resolution for 6925: [L1D][Enhance] L1D add code to support AERO1Plus RF chip
 *
 *    Rev 1.38   Jul 05 2004 15:50:40   mtk00773
 * Add RF POLARIS1 setting
 *
 *    Rev 1.37   May 21 2004 19:01:58   mtk00240
 * Add code to support MT6129D
 * Resolution for 5565: [L1D][Add Feature] Add code to support MT6129D
 *
 *    Rev 1.36   Jan 27 2004 15:33:12   mtk00585
 * [L1D][Add] L1D Add code for MT6129C RF Driver.
 *
 *    Rev 1.35   Jan 12 2004 14:26:20   mtk00489
 * [L1D][Enhanced]L1D modify code to sync with FT load. 1.Delay 400QB of CTIRQ1/2 and DSP_GPRS_DFB_ON for mt6218A/B 2.separate CSD and GPRS's DSP_TCH_BFI_THRESHOLD 3.adjust set-point and gain table for Mt6119C
 * Resolution for 3714: [L1D][Enhanced]L1D modify code to sync with FT load. 1.Delay 400QB of CTIRQ1/2 and DSP_GPRS_DFB_ON for mt6218A/B 2.separate CSD and GPRS's DSP_TCH_BFI_THRESHOLD 3.adjust set-point and gain table for Mt6119C
 *
 *    Rev 1.34   Oct 23 2003 14:22:18   mtk00585
 * [L1D][Add] L1D Add code for MT6129B RF Driver.
 * Resolution for 3177: [L1D][Add] L1D Add code for MT6129B RF Driver.
 *
 *    Rev 1.33   Jul 11 2003 17:41:30   mtk00489
 * [L1D][Enhanced]L1D supports MT6129A
 * Resolution for 2241: [L1D][Enhanced]L1D supports MT6129A
 *
 *    Rev 1.32   May 16 2003 13:09:24   mtk00489
 * [L1D][New Feature]L1D supports MT6119C
 * Resolution for 1794: [L1D][New Feature]L1D supports MT6119C
 *
 *    Rev 1.31   May 12 2003 21:36:54   mtk00489
 * [L1D][Enhanced]L1D modify L1D_RecordHwRegisters() / m12192.c(aero) / l1d_reg.h to make compiler happy.
 * Resolution for 1770: [L1D][Enhanced]L1D modify L1D_RecordHwRegisters() / m12192.c(aero) / l1d_reg.h to make compiler happy.
 *
 *    Rev 1.30   Apr 11 2003 16:44:16   mtk00489
 * [L1D][FixBug] L1D adjust SR2(from 40 to 100) for MT6119 by SA's request. In order to lower the ring of I/Q when channel filter switching
 * Resolution for 1522: [L1D][FixBug] L1D adjust SR2(from 40 to 100) for MT6119 by SA's request. In order to lower the ring of I/Q when channel filter switching
 *
 *    Rev 1.29   Apr 11 2003 16:43:30   mtk00489
 * [L1D][FixBug] L1D fix bug about gain setting small than ¡V11dBm(Aero), DSP will measure very high power even there is no input.
 * Resolution for 1521: [L1D][FixBug] L1D fix bug about gain setting small than ¡V11dBm(Aero), DSP will measure very high power even there is no input.
 *
 *    Rev 1.28   06 Jan 2003 16:43:40   mtk00240
 * type of agcptr shall be declared to const.
 * Resolution for 617: L1D fix the compile error in MAUI project when using AERO option
 *
 *    Rev 1.27   Jan 03 2003 16:26:22   mtk00474
 * MT6119 modifies PGA setting time and LNA gain boundary
 * Resolution for 615: MT6119 gain setting modify
 *
 *    Rev 1.25   16 Nov 2002 08:54:02   mtk00240
 * L1D add code to support AERO gain setting in GPRS mode
 * Resolution for 562: L1D add code to support AERO gain setting in GPRS mode
 *
 *    Rev 1.24   11 Sep 2002 12:05:48   mtk00240
 * (1) modified some MT6119 constant suggestted by SA
 * (2) modified some AERO constant suggestted by SA
 * Resolution for 439: L1D add code to support MT6119 RF Module
 * Resolution for 464:  L1D add code to support AERO RF Module
 *
 *    Rev 1.23   27 Aug 2002 12:04:22   admin
 * change file header
 *
 *    Rev 1.22   26 Aug 2002 14:34:14   admin
 * remove modification notice
 * add copyright statement.
 *
 *    Rev 1.21   24 Aug 2002 14:10:46   mtk00240
 *  L1D add code to support AERO RF Module
 * Resolution for 464:  L1D add code to support AERO RF Module
 *
 *    Rev 1.20   22 Aug 2002 10:37:00   mtk00240
 * Using macro to define the constants for evaluating gain setting.
 * Resolution for 455: L1D modified m12192.c to eavluate gain setting more easily
 *
 *    Rev 1.19   15 Aug 2002 08:28:00   mtk00240
 * L1D fix the minimum Gain of BRIGHT4
 * Resolution for 418: L1D extrract RF setting code to let customer setup new RF module more easily
 *
 *    Rev 1.18   23 Jul 2002 15:49:12   mtk00240
 * L1D add code to support MT6119 RF Module
 * Resolution for 439: L1D add code to support MT6119 RF Module
 *
 *    Rev 1.17   03 Jul 2002 21:43:48   mtk00240
 * L1D extrract RF setting code to let customer setup new RF module more easily
 * Resolution for 418: L1D extrract RF setting code to let customer setup new RF module more easily
 *
 *    Rev 1.16   08 May 2002 22:19:30   mtk00240
 * L1D add functions to support RF Test Tool
 * Resolution for 387: L1D add functions to support RF Test Tool
 *
 *    Rev 1.15   01 May 2002 22:45:58   mtk00240
 * Extract GSM code from L1D
 * Resolution for 384: Extract GSM code from L1D
 *
 *    Rev 1.14   23 Apr 2002 14:40:34   mtk00240
 * L1D integrate all RF calibration data into m12193.c
 *
 *    Rev 1.13   12 Apr 2002 21:27:10   mtk00240
 * L1D add new initialized value for RF
 * Resolution for 359: L1D add new initialized value for RF
 *
 *    Rev 1.12   03 Apr 2002 19:30:32   mtk00240
 * Fix some code to support Bright4 properly
 * Resolution for 341: Modify L1D code to support both Bright2 & Bright4 RF board
 *
 *    Rev 1.11   01 Apr 2002 12:24:14   mtk00240
 * L1D modified register's definition for DSP main v10
 * Resolution for 347: L1D modified register's definition for DSP F/W main v10
 *
 *    Rev 1.10   30 Mar 2002 13:04:16   mtk00240
 * 1) Modify L1D code to support both Bright2 & Bright4 RF board
 * 2) L1D add Audio interface to support Voice Memo & Melody
 * 3) Add L1D code to support RAM-based chip
 * Resolution for 341: Modify L1D code to support both Bright2 & Bright4 RF board
 * Resolution for 342: L1D add Audio interface to support Voice Memo & Melody
 * Resolution for 343: Add L1D code to support RAM-based chip
 *
 *    Rev 1.9   11 Mar 2002 19:46:58   mtk00240
 * Remove unused variables
 * Resolution for 310: L1D changed the gain setting methode
 *
 *    Rev 1.7   11 Mar 2002 13:36:24   mtk00240
 * instead TAB characters of Space characters in L1D code .
 * Resolution for 318: Shine change TAB character to Space charter
 *
 *    Rev 1.6   06 Mar 2002 19:28:18   mtk00240
 * L1D reset TSC value while CC reset
 * Resolution for 310: L1D changed the gain setting methode
 *
 *    Rev 1.5   17 Feb 2002 20:15:42   mtk00240
 * Update L1D code for solving HandOver test item
 * Resolution for 275: Update L1D code for solving HandOver test item
 *
 *    Rev 1.4   30 Jan 2002 13:12:48   mtk00240
 * support changing resolution by defined constance
 * Resolution for 253: RSSI resolution
 *
 *    Rev 1.3   03 Jan 2002 12:19:50   mtk00240
 * Merge B.L1.20011225 to Main V1.XX
 *
 *    Rev 1.2.1.0   Dec 25 2001 14:32:58   mtk00210
 * Update for High resolution RSSI, multiband AFC,
 * update L1C/L1D interface for CSD
 *
 *    Rev 1.1   Dec 10 2001 16:43:56   mtk00240
 * Add copyright header of MediaTek
 *
 *******************************************************************************/


/*===============================================================================*/
/*                                                                               */
/* int L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain,          */
/*                            long *gain_setting )                               */
/*                                                                               */
/*===============================================================================*/
/*                                                                               */
/* rf_band      : RF Band. the value is 0 (GSM) or 1 (DCS)                       */
/* arfcn        : ARFCN number                                                   */
/* request_gain : Request Gain. the unit is 0.125 dBm                            */
/* *gain_setting: the Setting Value for tranceiver gain.                         */
/* return       : returned Actually Setting Gain. the unit is 0.125 dBm.         */
/*                                                                               */
/* ----------------------------------------------------------------------------- */
/*                                                                               */
/* This program evaluates the AGC setting value by the request gain for Bright2. */
/* If the AGC component is changed, this file shall be modified by vendor        */
/*                                                                               */
/* ----------------------------------------------------------------------------- */

#include "l1d_cid.h"
#include "m12190.h"

/*================================================================================================*/

#define  ROUNDINT( n )                    ((int)(((n)>=0)?((n)+0.5):((n)-0.5)))
#define  GC_B                             ((GAIN_STEP)*(PWRRES))
#define  GC_A( bitno, gain  )             (short)ROUNDINT(((1+2*(bitno))*GC_B/2-(gain)*(PWRRES)))
#define  GBOUND( gain1, gain2 )           (short)ROUNDINT((((gain1)+(gain2))/2.0*(PWRRES)))
#define  BIT_NO( reqgain, A, B )          (((reqgain)+(A))/(B))
#define  REAL_GAIN( bitno, A, B )         ((bitno)*(B)-(A)+(B)/2)

/*================================================================================================*/

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

#if IS_RF_AERO
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*AERO*/ #if IS_GPRS
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*AERO*/ #else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*AERO*/ #endif
/* under construction !*/
/*AERO*/ #if IS_GPRS
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*AERO*/ #else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*AERO*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*AERO*/ #if IS_GPRS
/* under construction !*/
/*AERO*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*AERO*/ #if IS_GPRS
/* under construction !*/
/* under construction !*/
/*AERO*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*AERO*/ #if IS_GSM
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*AERO*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*AERO*/ #if IS_GPRS
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*AERO*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if IS_RF_AERO1PLUS
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*AERO1+*/ #if IS_GPRS
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*AERO1+*/ #else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*AERO1+*/ #endif
/* under construction !*/
/*AERO1+*/ #if IS_GPRS
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*AERO1+*/ #else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*AERO1+*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*AERO1+*/ #if IS_GPRS
/* under construction !*/
/*AERO1+*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*AERO1+*/ #if IS_GPRS
/* under construction !*/
/* under construction !*/
/*AERO1+*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*AERO1+*/ #if IS_GSM
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*AERO1+*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*AERO1+*/ #if IS_GPRS
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*AERO1+*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

#if  0 /* AMR use */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*SKY74117*/ #if IS_GPRS
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*SKY74117*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if IS_RF_SKY74117 /* GPRS use */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*SKY74117*/ #if IS_GPRS
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*SKY74117*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*SKY74400*/ #if IS_GPRS
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*SKY74400*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

#if  (IS_RF_MT6129C)||(IS_RF_MT6129D)
/*MT6129C,D*/
/*MT6129C,D*/ #define  GAIN_STEP               2
/*MT6129C,D*/
/*MT6129C,D*/ #define  RF_GSM850_MAXGAIN      (  72.0*(PWRRES))
/*MT6129C,D*/ #define  RF_GSM850_MINGAIN      ( -26.0*(PWRRES))
/*MT6129C,D*/ #define  RF_GSM_MAXGAIN         (  72.0*(PWRRES))
/*MT6129C,D*/ #define  RF_GSM_MINGAIN         ( -26.0*(PWRRES))
/*MT6129C,D*/ #define  RF_DCS_MAXGAIN         (  70.0*(PWRRES))
/*MT6129C,D*/ #define  RF_DCS_MINGAIN         ( -28.0*(PWRRES))
/*MT6129C,D*/ #define  RF_PCS_MAXGAIN         (  70.0*(PWRRES))
/*MT6129C,D*/ #define  RF_PCS_MINGAIN         ( -28.0*(PWRRES))
/*MT6129C,D*/
/*MT6129C,D*/ /* GSM850....................................................................*/

/*MT6129C,D*/ const  sL1DAGCDATA  AGC_TABLE_GSM850[3] =
/*MT6129C,D*/ {  {  GBOUND( 34.0, 32.0 ), GC_A( 11, 34.0 ), 0x126012 },
/*MT6129C,D*/    {  GBOUND( -6.0, -8.0 ), GC_A( 32, -6.0 ), 0x006012 },
/*MT6129C,D*/    {  GBOUND(-26.0,-26.0 ), GC_A(  0,-26.0 ), 0x006002 },
/*MT6129C,D*/ };

/*MT6129C,D*/ /* GSM900....................................................................*/
/*MT6129C,D*/
/*MT6129C,D*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[3] =
/*MT6129C,D*/ {  {  GBOUND( 34.0, 32.0 ), GC_A( 11, 34.0 ), 0x126812 },
/*MT6129C,D*/    {  GBOUND( -6.0, -8.0 ), GC_A( 32, -6.0 ), 0x006812 },
/*MT6129C,D*/    {  GBOUND(-26.0,-26.0 ), GC_A(  0,-26.0 ), 0x006802 },
/*MT6129C,D*/ };
/*MT6129C,D*/
/*MT6129C,D*/ /* DCS1800...................................................................*/
/*MT6129C,D*/
/*MT6129C,D*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[3] =
/*MT6129C,D*/ {  {  GBOUND( 32.0, 30.0 ), GC_A( 11, 32.0 ), 0x127012 },
/*MT6129C,D*/    {  GBOUND( -8.0,-10.0 ), GC_A( 32, -8.0 ), 0x007012 },
/*MT6129C,D*/    {  GBOUND(-28.0,-28.0 ), GC_A(  0,-28.0 ), 0x007002 },
/*MT6129C,D*/ };
/*MT6129C,D*/
/*MT6129C,D*/ /* PCS1900...................................................................*/
/*MT6129C,D*/
/*MT6129C,D*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[3] =
/*MT6129C,D*/ {  {  GBOUND( 32.0, 30.0 ), GC_A( 11, 32.0 ), 0x127812 },
/*MT6129C,D*/    {  GBOUND( -8.0,-10.0 ), GC_A( 32, -8.0 ), 0x007812 },
/*MT6129C,D*/    {  GBOUND(-28.0,-28.0 ), GC_A(  0,-28.0 ), 0x007802 },
/*MT6129C,D*/ };
/*MT6129C,D*/
/*MT6129C,D*/ /*...........................................................................*/
/*MT6129C,D*/
/*MT6129C,D*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*MT6129C,D*/ {  {                   0,                      0    }, /*#FrequencyBand400  */
/*MT6129C,D*/    { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN }, /* FrequencyBand850  */
/*MT6129C,D*/    { (int)RF_GSM_MAXGAIN,    (int)RF_GSM_MINGAIN    }, /* FrequencyBand900  */
/*MT6129C,D*/    { (int)RF_DCS_MAXGAIN,    (int)RF_DCS_MINGAIN    }, /* FrequencyBand1800 */
/*MT6129C,D*/    { (int)RF_PCS_MAXGAIN,    (int)RF_PCS_MINGAIN    }, /* FrequencyBand1900 */
/*MT6129C,D*/ };
/*MT6129C,D*/
/*MT6129C,D*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*MT6129C,D*/ {  0,                                              /*#FrequencyBand400  */
/*MT6129C,D*/    AGC_TABLE_GSM850,                               /* FrequencyBand850  */
/*MT6129C,D*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*MT6129C,D*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*MT6129C,D*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*MT6129C,D*/ };
/*MT6129C,D*/
/*MT6129C,D*/ const  sL1DAGCDATA *const  AGC_TABLE_GSM800in900PATH[] =
/*MT6129C,D*/ {  0,                                              /*#FrequencyBand400 (not support)  */
/*MT6129C,D*/    AGC_TABLE_GSM900,                               /* FrequencyBand900 (Get GSM850 signal from GSM900 input pins) */
/*MT6129C,D*/    AGC_TABLE_GSM850,                               /* FrequencyBand850 (Get GSM900 signal from GSM850 input pins, just avoid to camp on GSM900 network, not swap*/
/*MT6129C,D*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800               */
/*MT6129C,D*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900               */
/*MT6129C,D*/ };
/*MT6129C,D*/
/*MT6129C,D*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*MT6129C,D*/
/*MT6129C,D*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*MT6129C,D*/ {  int   max_gain, min_gain, real_gain;
/*MT6129C,D*/    const int*    d32ptr;
/*MT6129C,D*/    const sL1DAGCDATA*  agcptr;
/*MT6129C,D*/    long  setting;
/*MT6129C,D*/    int   bit_no;
/*MT6129C,D*/
/*MT6129C,D*/    /* evaluate the range of available gain */
/*MT6129C,D*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*MT6129C,D*/    max_gain = *d32ptr++;
/*MT6129C,D*/    min_gain = *d32ptr;
/*MT6129C,D*/
/*MT6129C,D*/    /* clipping the request gain to the avialable gain */
/*MT6129C,D*/    if( request_gain>=max_gain )
/*MT6129C,D*/    {  request_gain = max_gain;  }
/*MT6129C,D*/    else  if( request_gain<=min_gain )
/*MT6129C,D*/    {  request_gain = min_gain;  }
/*MT6129C,D*/
/*MT6129C,D*/    /* evaluate the real gain setting */
/*MT6129C,D*/    if(  BBTXParameters.bbrx_gsm850_gsm900_swap )
/*MT6129C,D*/    {   agcptr = AGC_TABLE_GSM800in900PATH[rf_band];  }
/*MT6129C,D*/    else
/*MT6129C,D*/    {   agcptr = AGC_TABLE[rf_band];           }
/*MT6129C,D*/
/*MT6129C,D*/    if( request_gain < agcptr->pos_gain )
/*MT6129C,D*/    {  agcptr++;
/*MT6129C,D*/       if( request_gain < agcptr->pos_gain )
/*MT6129C,D*/       {  agcptr++;  }
/*MT6129C,D*/    }
/*MT6129C,D*/    {  bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*MT6129C,D*/       real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B );
/*MT6129C,D*/       setting   = agcptr->setting + (bit_no<<5);
/*MT6129C,D*/    }
/*MT6129C,D*/
/*MT6129C,D*/    *gain_setting = setting;
/*MT6129C,D*/    return( real_gain );
/*MT6129C,D*/ }
/*MT6129C,D*/
#endif

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

#if IS_RF_MT6139E
/*MT6139E*/
/*MT6139E*/ #define  GAIN_STEP               2
/*MT6139E*/
/*MT6139E*/ #define  RF_GSM850_MAXGAIN      (  56.0*(PWRRES))
/*MT6139E*/ #define  RF_GSM850_MINGAIN      ( -28.0*(PWRRES))
/*MT6139E*/ #define  RF_GSM_MAXGAIN         (  56.0*(PWRRES))
/*MT6139E*/ #define  RF_GSM_MINGAIN         ( -28.0*(PWRRES))
/*MT6139E*/ #define  RF_DCS_MAXGAIN         (  56.0*(PWRRES))
/*MT6139E*/ #define  RF_DCS_MINGAIN         ( -28.0*(PWRRES))
/*MT6139E*/ #define  RF_PCS_MAXGAIN         (  56.0*(PWRRES))
/*MT6139E*/ #define  RF_PCS_MINGAIN         ( -28.0*(PWRRES))
/*MT6139E*/
/*MT6139E*/ /* GSM850....................................................................*/
/*MT6139E*/
/*MT6139E*/ const  sL1DAGCDATA  AGC_TABLE_GSM850[2] =
/*MT6139E*/ {  {  GBOUND( -4.0, -6.0 ), GC_A(  0, -4.0 ), 0x000E02 },
/*MT6139E*/    {  GBOUND(-32.0,-32.0 ), GC_A(  4,-32.0 ), 0x000C02 },
/*MT6139E*/ };
/*MT6139E*/
/*MT6139E*/ /* GSM900....................................................................*/
/*MT6139E*/
/*MT6139E*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[2] =
/*MT6139E*/ {  {  GBOUND( -4.0, -6.0 ), GC_A(  0, -4.0 ), 0x000E02 },
/*MT6139E*/    {  GBOUND(-32.0,-32.0 ), GC_A(  4,-32.0 ), 0x000C02 },
/*MT6139E*/ };
/*MT6139E*/
/*MT6139E*/ /* DCS1800...................................................................*/
/*MT6139E*/
/*MT6139E*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[2] =
/*MT6139E*/ {  {  GBOUND( -4.0, -6.0 ), GC_A(  0, -4.0 ), 0x000E02 },
/*MT6139E*/    {  GBOUND(-32.0,-32.0 ), GC_A(  4,-32.0 ), 0x000C02 },
/*MT6139E*/ };
/*MT6139E*/
/*MT6139E*/ /* PCS1900...................................................................*/
/*MT6139E*/
/*MT6139E*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[2] =
/*MT6139E*/ {  {  GBOUND( -4.0, -6.0 ), GC_A(  0, -4.0 ), 0x000E02 },
/*MT6139E*/    {  GBOUND(-32.0,-32.0 ), GC_A(  4,-32.0 ), 0x000C02 },
/*MT6139E*/ };
/*MT6139E*/
/*MT6139E*/ /*...........................................................................*/
/*MT6139E*/
/*MT6139E*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*MT6139E*/ {  {                   0,                      0    }, /*#FrequencyBand400  */
/*MT6139E*/    { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN }, /* FrequencyBand850  */
/*MT6139E*/    { (int)RF_GSM_MAXGAIN,    (int)RF_GSM_MINGAIN    }, /* FrequencyBand900  */
/*MT6139E*/    { (int)RF_DCS_MAXGAIN,    (int)RF_DCS_MINGAIN    }, /* FrequencyBand1800 */
/*MT6139E*/    { (int)RF_PCS_MAXGAIN,    (int)RF_PCS_MINGAIN    }, /* FrequencyBand1900 */
/*MT6139E*/ };
/*MT6139E*/
/*MT6139E*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*MT6139E*/ {  0,                                              /*#FrequencyBand400  */
/*MT6139E*/    AGC_TABLE_GSM850,                               /* FrequencyBand850  */
/*MT6139E*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*MT6139E*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*MT6139E*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*MT6139E*/ };
/*MT6139E*/
/*MT6139E*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*MT6139E*/
/*MT6139E*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*MT6139E*/ {  int   max_gain, min_gain, real_gain;
/*MT6139E*/    const int*    d32ptr;
/*MT6139E*/    const sL1DAGCDATA*  agcptr;
/*MT6139E*/    long  setting;
/*MT6139E*/    int   bit_no;
/*MT6139E*/
/*MT6139E*/    /* evaluate the range of available gain */
/*MT6139E*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*MT6139E*/    max_gain = *d32ptr++;
/*MT6139E*/    min_gain = *d32ptr;
/*MT6139E*/
/*MT6139E*/    /* clipping the request gain to the avialable gain */
/*MT6139E*/    if( request_gain>=max_gain )
/*MT6139E*/    {  request_gain = max_gain;  }
/*MT6139E*/    else  if( request_gain<=min_gain )
/*MT6139E*/    {  request_gain = min_gain;  }
/*MT6139E*/
/*MT6139E*/    /* evaluate the real gain setting */
/*MT6139E*/    agcptr = AGC_TABLE[rf_band];
/*MT6139E*/    if( request_gain < agcptr->pos_gain )
/*MT6139E*/    {  agcptr++;
/*MT6139E*/    }
/*MT6139E*/    {  bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*MT6139E*/       real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B );
/*MT6139E*/       setting   = agcptr->setting + (bit_no<<4);
/*MT6139E*/    }
/*MT6139E*/
/*MT6139E*/    *gain_setting = setting;
/*MT6139E*/    return( real_gain );
/*MT6139E*/ }
/*MT6139E*/
#endif

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

#if IS_RF_MT6140D
/*MT6140D*/
/*MT6140D*/ #define  GAIN_STEP               2
/*MT6140D*/ #define  PVOFSL                 34
/*MT6140D*/ #define  PVOFSH                 34
/*MT6140D*/ #define  RF_GSM850_MAXGAIN      (( 90-PVOFSL )*(PWRRES))
/*MT6140D*/ #define  RF_GSM850_MINGAIN      ((  6-PVOFSL )*(PWRRES))
/*MT6140D*/ #define  RF_GSM_MAXGAIN         (( 90-PVOFSL )*(PWRRES))
/*MT6140D*/ #define  RF_GSM_MINGAIN         ((  6-PVOFSL )*(PWRRES))
/*MT6140D*/ #define  RF_DCS_MAXGAIN         (( 88-PVOFSH )*(PWRRES))
/*MT6140D*/ #define  RF_DCS_MINGAIN         ((  2-PVOFSH )*(PWRRES))
/*MT6140D*/ #define  RF_PCS_MAXGAIN         (( 88-PVOFSH )*(PWRRES))
/*MT6140D*/ #define  RF_PCS_MINGAIN         ((  2-PVOFSH )*(PWRRES))
/*MT6140D*/
/*MT6140D*/ /* GSM850....................................................................*/
/*MT6140D*/
/*MT6140D*/ const  sL1DAGCDATA  AGC_TABLE_GSM850[2] =
/*MT6140D*/ {  {  GBOUND(( 30-PVOFSL ),( 28-PVOFSL ) ), GC_A( 0,( 30-PVOFSL ) ), 0x000202 },
/*MT6140D*/    {  GBOUND((  4-PVOFSL ),(  4-PVOFSL ) ), GC_A( 5,(  4-PVOFSL ) ), 0x000002 },
/*MT6140D*/ };
/*MT6140D*/
/*MT6140D*/ /* GSM900....................................................................*/
/*MT6140D*/
/*MT6140D*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[2] =
/*MT6140D*/ {  {  GBOUND(( 30-PVOFSL ),( 28-PVOFSL ) ), GC_A( 0,( 30-PVOFSL ) ), 0x000202 },
/*MT6140D*/    {  GBOUND((  4-PVOFSL ),(  4-PVOFSL ) ), GC_A( 5,(  4-PVOFSL ) ), 0x000002 },
/*MT6140D*/ };
/*MT6140D*/
/*MT6140D*/ /* DCS1800...................................................................*/
/*MT6140D*/
/*MT6140D*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[2] =
/*MT6140D*/ {  {  GBOUND(( 28-PVOFSH ),( 26-PVOFSH ) ), GC_A( 0,( 28-PVOFSH ) ), 0x000202 },
/*MT6140D*/    {  GBOUND((  2-PVOFSH ),(  2-PVOFSH ) ), GC_A( 6,(  2-PVOFSH ) ), 0x000002 },
/*MT6140D*/ };
/*MT6140D*/
/*MT6140D*/ /* PCS1900...................................................................*/
/*MT6140D*/
/*MT6140D*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[2] =
/*MT6140D*/ {  {  GBOUND(( 28-PVOFSH ),( 26-PVOFSH ) ), GC_A( 0,( 28-PVOFSH ) ), 0x000202 },
/*MT6140D*/    {  GBOUND((  2-PVOFSH ),(  2-PVOFSH ) ), GC_A( 6,(  2-PVOFSH ) ), 0x000002 },
/*MT6140D*/ };
/*MT6140D*/
/*MT6140D*/ /*...........................................................................*/
/*MT6140D*/
/*MT6140D*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*MT6140D*/ {  {                   0,                      0    }, /*#FrequencyBand400  */
/*MT6140D*/    { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN }, /* FrequencyBand850  */
/*MT6140D*/    { (int)RF_GSM_MAXGAIN,    (int)RF_GSM_MINGAIN    }, /* FrequencyBand900  */
/*MT6140D*/    { (int)RF_DCS_MAXGAIN,    (int)RF_DCS_MINGAIN    }, /* FrequencyBand1800 */
/*MT6140D*/    { (int)RF_PCS_MAXGAIN,    (int)RF_PCS_MINGAIN    }, /* FrequencyBand1900 */
/*MT6140D*/ };
/*MT6140D*/
/*MT6140D*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*MT6140D*/ {  0,                                              /*#FrequencyBand400  */
/*MT6140D*/    AGC_TABLE_GSM850,                               /* FrequencyBand850  */
/*MT6140D*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*MT6140D*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*MT6140D*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*MT6140D*/ };
/*MT6140D*/
/*MT6140D*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*MT6140D*/
/*MT6140D*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*MT6140D*/ {  int   max_gain, min_gain, real_gain;
/*MT6140D*/    const int*    d32ptr;
/*MT6140D*/    const sL1DAGCDATA*  agcptr;
/*MT6140D*/    long  setting;
/*MT6140D*/    int   bit_no;
/*MT6140D*/
/*MT6140D*/    /* evaluate the range of available gain */
/*MT6140D*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*MT6140D*/    max_gain = *d32ptr++;
/*MT6140D*/    min_gain = *d32ptr;
/*MT6140D*/
/*MT6140D*/    /* clipping the request gain to the avialable gain */
/*MT6140D*/    if( request_gain>=max_gain )
/*MT6140D*/    {  request_gain = max_gain;  }
/*MT6140D*/    else  if( request_gain<=min_gain )
/*MT6140D*/    {  request_gain = min_gain;  }
/*MT6140D*/
/*MT6140D*/    /* evaluate the real gain setting */
/*MT6140D*/    agcptr = AGC_TABLE[rf_band];
/*MT6140D*/    if( request_gain < agcptr->pos_gain )
/*MT6140D*/    {  agcptr++;
/*MT6140D*/    }
/*MT6140D*/    {  bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*MT6140D*/       real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B );
/*MT6140D*/       setting   = agcptr->setting + (bit_no<<4);
/*MT6140D*/    }
/*MT6140D*/
/*MT6140D*/    *gain_setting = setting;
/*MT6140D*/    return( real_gain );
/*MT6140D*/ }
/*MT6140D*/
#endif

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

#if IS_RF_MTKSOC1T
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

#if IS_RF_MTKSOC1
/*MTKSOC1*/
/*MTKSOC1*/ #define  GAIN_STEP               2
/*MTKSOC1*/ #define  PVOFSL                  39
/*MTKSOC1*/ #define  PVOFSH                  39
/*MTKSOC1*/ #define  RF_GSM850_MAXGAIN      (( 94-PVOFSL )*(PWRRES))
/*MTKSOC1*/ #define  RF_GSM850_MINGAIN      (( 14-PVOFSL )*(PWRRES))
/*MTKSOC1*/ #define  RF_GSM_MAXGAIN         (( 94-PVOFSL )*(PWRRES))
/*MTKSOC1*/ #define  RF_GSM_MINGAIN         (( 14-PVOFSL )*(PWRRES))
/*MTKSOC1*/ #define  RF_DCS_MAXGAIN         (( 94-PVOFSH )*(PWRRES))
/*MTKSOC1*/ #define  RF_DCS_MINGAIN         (( 14-PVOFSH )*(PWRRES))
/*MTKSOC1*/ #define  RF_PCS_MAXGAIN         (( 94-PVOFSH )*(PWRRES))
/*MTKSOC1*/ #define  RF_PCS_MINGAIN         (( 14-PVOFSH )*(PWRRES))
/*MTKSOC1*/
/*MTKSOC1*/ /* GSM850....................................................................*/
/*MTKSOC1*/
/*MTKSOC1*/ const  sL1DAGCDATA  AGC_TABLE_GSM850[2] =
/*MTKSOC1*/ {  {  GBOUND(( 40-PVOFSL ),( 38-PVOFSL ) ), GC_A(  0,( 40-PVOFSL ) ), 0x0400020 },
/*MTKSOC1*/    {  GBOUND(( 14-PVOFSL ),( 14-PVOFSL ) ), GC_A(  0,( 14-PVOFSL ) ), 0x0400000 },
/*MTKSOC1*/ };
/*MTKSOC1*/
/*MTKSOC1*/ /* GSM900....................................................................*/
/*MTKSOC1*/
/*MTKSOC1*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[2] =
/*MTKSOC1*/ {  {  GBOUND(( 40-PVOFSL ),( 38-PVOFSL ) ), GC_A(  0,( 40-PVOFSL ) ), 0x0400020 },
/*MTKSOC1*/    {  GBOUND(( 14-PVOFSL ),( 14-PVOFSL ) ), GC_A(  0,( 14-PVOFSL ) ), 0x0400000 },
/*MTKSOC1*/ };
/*MTKSOC1*/
/*MTKSOC1*/ /* DCS1800...................................................................*/
/*MTKSOC1*/
/*MTKSOC1*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[2] =
/*MTKSOC1*/ {  {  GBOUND(( 40-PVOFSL ),( 38-PVOFSL ) ), GC_A(  0,( 40-PVOFSL ) ), 0x0400020 },
/*MTKSOC1*/    {  GBOUND(( 14-PVOFSL ),( 14-PVOFSL ) ), GC_A(  0,( 14-PVOFSL ) ), 0x0400000 },
/*MTKSOC1*/ };
/*MTKSOC1*/
/*MTKSOC1*/ /* PCS1900...................................................................*/
/*MTKSOC1*/
/*MTKSOC1*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[2] =
/*MTKSOC1*/ {  {  GBOUND(( 40-PVOFSL ),( 38-PVOFSL ) ), GC_A(  0,( 40-PVOFSL ) ), 0x0400020 },
/*MTKSOC1*/    {  GBOUND(( 14-PVOFSL ),( 14-PVOFSL ) ), GC_A(  0,( 14-PVOFSL ) ), 0x0400000 },
/*MTKSOC1*/ };
/*MTKSOC1*/
/*MTKSOC1*/ /*...........................................................................*/
/*MTKSOC1*/
/*MTKSOC1*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*MTKSOC1*/ {  {                   0,                      0    }, /*#FrequencyBand400  */
/*MTKSOC1*/    { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN }, /* FrequencyBand850  */
/*MTKSOC1*/    { (int)RF_GSM_MAXGAIN,    (int)RF_GSM_MINGAIN    }, /* FrequencyBand900  */
/*MTKSOC1*/    { (int)RF_DCS_MAXGAIN,    (int)RF_DCS_MINGAIN    }, /* FrequencyBand1800 */
/*MTKSOC1*/    { (int)RF_PCS_MAXGAIN,    (int)RF_PCS_MINGAIN    }, /* FrequencyBand1900 */
/*MTKSOC1*/ };
/*MTKSOC1*/
/*MTKSOC1*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*MTKSOC1*/ {  0,                                              /*#FrequencyBand400  */
/*MTKSOC1*/    AGC_TABLE_GSM850,                               /* FrequencyBand850  */
/*MTKSOC1*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*MTKSOC1*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*MTKSOC1*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*MTKSOC1*/ };
/*MTKSOC1*/
/*MTKSOC1*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*MTKSOC1*/
/*MTKSOC1*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*MTKSOC1*/ {  int   max_gain, min_gain, real_gain;
/*MTKSOC1*/    const int*    d32ptr;
/*MTKSOC1*/    const sL1DAGCDATA*  agcptr;
/*MTKSOC1*/    long  setting;
/*MTKSOC1*/    int   bit_no;
/*MTKSOC1*/
/*MTKSOC1*/    /* evaluate the range of available gain */
/*MTKSOC1*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*MTKSOC1*/    max_gain = *d32ptr++;
/*MTKSOC1*/    min_gain = *d32ptr;
/*MTKSOC1*/
/*MTKSOC1*/    /* clipping the request gain to the avialable gain */
/*MTKSOC1*/    if( request_gain>=max_gain )
/*MTKSOC1*/    {  request_gain = max_gain;  }
/*MTKSOC1*/    else  if( request_gain<=min_gain )
/*MTKSOC1*/    {  request_gain = min_gain;  }
/*MTKSOC1*/
/*MTKSOC1*/    /* evaluate the real gain setting */
/*MTKSOC1*/    agcptr = AGC_TABLE[rf_band];
/*MTKSOC1*/    if( request_gain < agcptr->pos_gain )
/*MTKSOC1*/    {  agcptr++;
/*MTKSOC1*/    }
/*MTKSOC1*/    {  bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*MTKSOC1*/       real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B );
/*MTKSOC1*/       setting   = agcptr->setting + bit_no;
/*MTKSOC1*/    }
/*MTKSOC1*/
/*MTKSOC1*/    *gain_setting = setting;
/*MTKSOC1*/    return( real_gain );
/*MTKSOC1*/ }
/*MTKSOC1*/
#endif

#if IS_RF_MT6252RF
/*MT6252RF*/
/*MT6252RF*/ #define  GAIN_STEP               2
/*MT6252RF*/ #define  PVOFSL                  39
/*MT6252RF*/ #define  PVOFSH                  39
/*MT6252RF*/ #define  RF_GSM850_MAXGAIN      (( 96-PVOFSL )*(PWRRES))
/*MT6252RF*/ #define  RF_GSM850_MINGAIN      (( 16-PVOFSL )*(PWRRES))
/*MT6252RF*/ #define  RF_GSM_MAXGAIN         (( 96-PVOFSL )*(PWRRES))
/*MT6252RF*/ #define  RF_GSM_MINGAIN         (( 16-PVOFSL )*(PWRRES))
/*MT6252RF*/ #define  RF_DCS_MAXGAIN         (( 96-PVOFSH )*(PWRRES))
/*MT6252RF*/ #define  RF_DCS_MINGAIN         (( 16-PVOFSH )*(PWRRES))
/*MT6252RF*/ #define  RF_PCS_MAXGAIN         (( 96-PVOFSH )*(PWRRES))
/*MT6252RF*/ #define  RF_PCS_MINGAIN         (( 16-PVOFSH )*(PWRRES))
/*MT6252RF*/
/*MT6252RF*/ /* GSM850....................................................................*/
/*MT6252RF*/
/*MT6252RF*/ const  sL1DAGCDATA  AGC_TABLE_GSM850[2] =
/*MT6252RF*/ {  {  GBOUND(( 42-PVOFSL ),( 40-PVOFSL ) ), GC_A( 0, ( 42-PVOFSL ) ), 0x6000020 },
/*MT6252RF*/    {  GBOUND(( 16-PVOFSL ),( 16-PVOFSL ) ), GC_A( 0, ( 16-PVOFSL ) ), 0x6000000 },
/*MT6252RF*/ };
/*MT6252RF*/
/*MT6252RF*/ /* GSM900....................................................................*/
/*MT6252RF*/
/*MT6252RF*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[2] =
/*MT6252RF*/ {  {  GBOUND(( 42-PVOFSL ),( 40-PVOFSL ) ), GC_A( 0, ( 42-PVOFSL ) ), 0x6000020 },
/*MT6252RF*/    {  GBOUND(( 16-PVOFSL ),( 16-PVOFSL ) ), GC_A( 0, ( 16-PVOFSL ) ), 0x6000000 },
/*MT6252RF*/ };
/*MT6252RF*/
/*MT6252RF*/ /* DCS1800...................................................................*/
/*MT6252RF*/
/*MT6252RF*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[2] =
/*MT6252RF*/ {  {  GBOUND(( 42-PVOFSL ),( 40-PVOFSL ) ), GC_A( 0, ( 42-PVOFSL ) ), 0x6000020 },
/*MT6252RF*/    {  GBOUND(( 16-PVOFSL ),( 16-PVOFSL ) ), GC_A( 0, ( 16-PVOFSL ) ), 0x6000000 },
/*MT6252RF*/ };
/*MT6252RF*/
/*MT6252RF*/ /* PCS1900...................................................................*/
/*MT6252RF*/
/*MT6252RF*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[2] =
/*MT6252RF*/ {  {  GBOUND(( 42-PVOFSL ),( 40-PVOFSL ) ), GC_A( 0, ( 42-PVOFSL ) ), 0x6000020 },
/*MT6252RF*/    {  GBOUND(( 16-PVOFSL ),( 16-PVOFSL ) ), GC_A( 0, ( 16-PVOFSL ) ), 0x6000000 },
/*MT6252RF*/ };
/*MT6252RF*/
/*MT6252RF*/ /*...........................................................................*/
/*MT6252RF*/
/*MT6252RF*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*MT6252RF*/ {  {                   0,                      0    }, /* FrequencyBand400  */
/*MT6252RF*/    { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN }, /* FrequencyBand850  */
/*MT6252RF*/    { (int)RF_GSM_MAXGAIN,    (int)RF_GSM_MINGAIN    }, /* FrequencyBand900  */
/*MT6252RF*/    { (int)RF_DCS_MAXGAIN,    (int)RF_DCS_MINGAIN    }, /* FrequencyBand1800 */
/*MT6252RF*/    { (int)RF_PCS_MAXGAIN,    (int)RF_PCS_MINGAIN    }, /* FrequencyBand1900 */
/*MT6252RF*/ };
/*MT6252RF*/
/*MT6252RF*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*MT6252RF*/ {  0,                                                  /* FrequencyBand400  */
/*MT6252RF*/    AGC_TABLE_GSM850,                                   /* FrequencyBand850  */
/*MT6252RF*/    AGC_TABLE_GSM900,                                   /* FrequencyBand900  */
/*MT6252RF*/    AGC_TABLE_DCS1800,                                  /* FrequencyBand1800 */
/*MT6252RF*/    AGC_TABLE_PCS1900,                                  /* FrequencyBand1900 */
/*MT6252RF*/ };
/*MT6252RF*/
/*MT6252RF*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*MT6252RF*/
/*MT6252RF*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*MT6252RF*/ {  int   max_gain, min_gain, real_gain;
/*MT6252RF*/    const int*    d32ptr;
/*MT6252RF*/    const sL1DAGCDATA*  agcptr;
/*MT6252RF*/    long  setting;
/*MT6252RF*/    int   bit_no;
/*MT6252RF*/
/*MT6252RF*/    /* evaluate the range of available gain */
/*MT6252RF*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*MT6252RF*/    max_gain = *d32ptr++;
/*MT6252RF*/    min_gain = *d32ptr;
/*MT6252RF*/
/*MT6252RF*/    /* clipping the request gain to the avialable gain */
/*MT6252RF*/    if( request_gain>=max_gain )
/*MT6252RF*/    {  request_gain = max_gain;  }
/*MT6252RF*/    else  if( request_gain<=min_gain )
/*MT6252RF*/    {  request_gain = min_gain;  }
/*MT6252RF*/
/*MT6252RF*/    /* evaluate the real gain setting */
/*MT6252RF*/    agcptr = AGC_TABLE[rf_band];
/*MT6252RF*/    if( request_gain < agcptr->pos_gain )
/*MT6252RF*/    {  agcptr++;
/*MT6252RF*/    }
/*MT6252RF*/    {  bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*MT6252RF*/       real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B );
/*MT6252RF*/       setting   = agcptr->setting + bit_no;
/*MT6252RF*/    }
/*MT6252RF*/
/*MT6252RF*/    *gain_setting = setting;
/*MT6252RF*/    return( real_gain );
/*MT6252RF*/ }
/*MT6252RF*/
#endif

#if IS_RF_MT6256RF
/*MT6256RF*/
/*MT6256RF*/ #define  GAIN_STEP               6
/*MT6256RF*/ #define  PVOFSL                  34
/*MT6256RF*/ #define  PVOFSH                  34
/*MT6256RF*/ #define  INSERTION_LOSS         (3*(PWRRES))  //Insertion loss is 3dB
/*MT6256RF*/ #define  RF_GSM850_MAXGAIN      (( 62-PVOFSL )*(PWRRES))
/*MT6256RF*/ #define  RF_GSM850_MINGAIN      ((  2-PVOFSL )*(PWRRES))
/*MT6256RF*/ #define  RF_GSM_MAXGAIN         (( 62-PVOFSL )*(PWRRES))
/*MT6256RF*/ #define  RF_GSM_MINGAIN         ((  2-PVOFSL )*(PWRRES))
/*MT6256RF*/ #define  RF_DCS_MAXGAIN         (( 62-PVOFSH )*(PWRRES))
/*MT6256RF*/ #define  RF_DCS_MINGAIN         ((  0-PVOFSH )*(PWRRES))
/*MT6256RF*/ #define  RF_PCS_MAXGAIN         (( 62-PVOFSH )*(PWRRES))
/*MT6256RF*/ #define  RF_PCS_MINGAIN         ((  0-PVOFSH )*(PWRRES))
/*MT6256RF*/
/*MT6256RF*/ /* GSM850....................................................................*/
/*MT6256RF*/
/*MT6256RF*/ const  sL1DAGCDATA  AGC_TABLE_GSM850[2] =
/*MT6256RF*/ {  {  GBOUND(( 32-PVOFSL ),( 26-PVOFSL ) ), GC_A( 0,( 32-PVOFSL ) ), BSI_CW(0x60, 0x40) },
/*MT6256RF*/    {  GBOUND((  0-PVOFSL ),(  0-PVOFSL ) ), GC_A( 0,(  2-PVOFSL ) ), BSI_CW(0x60, 0x00) },
/*MT6256RF*/ };
/*MT6256RF*/
/*MT6256RF*/ /* GSM900....................................................................*/
/*MT6256RF*/
/*MT6256RF*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[2] =
/*MT6256RF*/ {  {  GBOUND(( 32-PVOFSL ),( 26-PVOFSL ) ), GC_A( 0,( 32-PVOFSL ) ), BSI_CW(0x60, 0x40) },
/*MT6256RF*/    {  GBOUND((  0-PVOFSL ),(  0-PVOFSL ) ), GC_A( 0,(  2-PVOFSL ) ), BSI_CW(0x60, 0x00) },
/*MT6256RF*/ };
/*MT6256RF*/
/*MT6256RF*/ /* DCS1800...................................................................*/
/*MT6256RF*/
/*MT6256RF*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[2] =
/*MT6256RF*/ {  {  GBOUND(( 32-PVOFSL ),( 22-PVOFSL ) ), GC_A( 0,( 32-PVOFSL ) ), BSI_CW(0x60, 0x40) },
/*MT6256RF*/    {  GBOUND((  0-PVOFSL ),(  0-PVOFSL ) ), GC_A( 0,(  0-PVOFSL ) ), BSI_CW(0x60, 0x00) },
/*MT6256RF*/ };
/*MT6256RF*/
/*MT6256RF*/ /* PCS1900...................................................................*/
/*MT6256RF*/
/*MT6256RF*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[2] =
/*MT6256RF*/ {  {  GBOUND(( 32-PVOFSL ),( 22-PVOFSL ) ), GC_A( 0,( 32-PVOFSL ) ), BSI_CW(0x60, 0x40) },
/*MT6256RF*/    {  GBOUND((  0-PVOFSL ),(  0-PVOFSL ) ), GC_A( 0,(  0-PVOFSL ) ), BSI_CW(0x60, 0x00) },
/*MT6256RF*/ };
/*MT6256RF*/
/*MT6256RF*/ /*...........................................................................*/
/*MT6256RF*/
/*MT6256RF*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*MT6256RF*/ {  {                   0,                      0    }, /*#FrequencyBand400  */
/*MT6256RF*/    { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN }, /* FrequencyBand850  */
/*MT6256RF*/    { (int)RF_GSM_MAXGAIN,    (int)RF_GSM_MINGAIN    }, /* FrequencyBand900  */
/*MT6256RF*/    { (int)RF_DCS_MAXGAIN,    (int)RF_DCS_MINGAIN    }, /* FrequencyBand1800 */
/*MT6256RF*/    { (int)RF_PCS_MAXGAIN,    (int)RF_PCS_MINGAIN    }, /* FrequencyBand1900 */
/*MT6256RF*/ };
/*MT6256RF*/
/*MT6256RF*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*MT6256RF*/ {  0,                                              /*#FrequencyBand400  */
/*MT6256RF*/    AGC_TABLE_GSM850,                               /* FrequencyBand850  */
/*MT6256RF*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*MT6256RF*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*MT6256RF*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*MT6256RF*/ };
/*MT6256RF*/
/*MT6256RF*/ const  int  GAIN_STEP_TABLE[] =
/*MT6256RF*/ { 10, 18, 26, 34, 42, 45, 53 };   /* gain step for high/low LNA gain                */
/*MT6256RF*/                                   /* Low LNA gain  : { 10, 18, 26, 34, 42         } */
/*MT6256RF*/                                   /* High LNA gain : {     18, 26, 34, 42, 45, 53 } */
/*MT6256RF*/
/*MT6256RF*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*MT6256RF*/
/*MT6256RF*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*MT6256RF*/ {  int   max_gain, min_gain, real_gain;
/*MT6256RF*/    const int*    d32ptr;
/*MT6256RF*/    const sL1DAGCDATA*  agcptr;
/*MT6256RF*/    long  setting;
/*MT6256RF*/    int   bit_no, gain_step, idx_shift_value;
/*MT6256RF*/
/*MT6256RF*/    /* evaluate the range of available gain */
/*MT6256RF*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*MT6256RF*/    max_gain = *d32ptr++;
/*MT6256RF*/    min_gain = *d32ptr;
/*MT6256RF*/
/*MT6256RF*/    /* clipping the request gain to the avialable gain */
/*MT6256RF*/    if( request_gain>=max_gain )
/*MT6256RF*/    {  request_gain = max_gain;  }
/*MT6256RF*/    else  if( request_gain<=min_gain )
/*MT6256RF*/    {  request_gain = min_gain;  }
/*MT6256RF*/
/*MT6256RF*/    /* evaluate the real gain setting */
/*MT6256RF*/    agcptr = AGC_TABLE[rf_band];
/*MT6256RF*/    idx_shift_value = 1;  //Since the lowest gain step of high LNA gain case is 18
/*MT6256RF*/    if( request_gain < agcptr->pos_gain )
/*MT6256RF*/    {  agcptr++;
/*MT6256RF*/       idx_shift_value = 0;
/*MT6256RF*/    }
/*MT6256RF*/    {
/*MT6256RF*/       bit_no = BIT_NO( request_gain, agcptr->A, GC_B );
/*MT6256RF*/       gain_step = GAIN_STEP_TABLE[bit_no+idx_shift_value];  //Use bit_no to choose gain step
/*MT6256RF*/       real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B ) - INSERTION_LOSS;
/*MT6256RF*/       setting   = agcptr->setting + gain_step;
/*MT6256RF*/    }
/*MT6256RF*/
/*MT6256RF*/    *gain_setting = setting;
/*MT6256RF*/    return( real_gain );
/*MT6256RF*/ }
/*MT6256RF*/
   #if IS_W_CANCELLATION_SUPPORT
/*MT6256RF*/ unsigned short   L1D_RF_FindGainStep( unsigned long gain_setting, FrequencyBand rf_band )
/*MT6256RF*/ {
/*MT6256RF*/    int bit_value, shift_value;
/*MT6256RF*/    unsigned short left_idx, right_idx, mid_idx, idx;
/*MT6256RF*/
/*MT6256RF*/    shift_value = (gain_setting>>6) & 0x1;
/*MT6256RF*/    bit_value = gain_setting & 0x3F;
/*MT6256RF*/    left_idx = 0;
/*MT6256RF*/    right_idx = sizeof(GAIN_STEP_TABLE)/sizeof(int)-1;
/*MT6256RF*/
/*MT6256RF*/    while( left_idx < right_idx )
/*MT6256RF*/    {
/*MT6256RF*/       mid_idx = (left_idx + right_idx) >> 1;
/*MT6256RF*/
/*MT6256RF*/       if( bit_value <= GAIN_STEP_TABLE[mid_idx])
/*MT6256RF*/          right_idx = mid_idx;
/*MT6256RF*/       else
/*MT6256RF*/          left_idx = mid_idx + 1;
/*MT6256RF*/    }
/*MT6256RF*/
/*MT6256RF*/    idx = right_idx;
/*MT6256RF*/
/*MT6256RF*/    if( shift_value == 1 )
/*MT6256RF*/       return (idx + 4);
/*MT6256RF*/    else
/*MT6256RF*/       return (idx);
/*MT6256RF*/ }
/*MT6256RF*/
   #endif
#endif

#if IS_RF_MT6251RF || IS_RF_MT6255RF
/*MT6251RF*/
/*MT6251RF*/ #define  GAIN_STEP               6
/*MT6251RF*/ #define  PVOFSL                  34
/*MT6251RF*/ #define  PVOFSH                  34
   #if IS_RF_MT6255RF
/*MT6251RF*/ #define  INSERTION_LOSS         (2*(PWRRES))  //Insertion loss is 2dB
   #else
/*MT6251RF*/ #define  INSERTION_LOSS         (0*(PWRRES))  //Insertion loss is 0dB
   #endif
/*MT6251RF*/ #define  RF_GSM850_MAXGAIN      (( 62-PVOFSL )*(PWRRES))
/*MT6251RF*/ #define  RF_GSM850_MINGAIN      ((  0-PVOFSL )*(PWRRES))
/*MT6251RF*/ #define  RF_GSM_MAXGAIN         (( 62-PVOFSL )*(PWRRES))
/*MT6251RF*/ #define  RF_GSM_MINGAIN         ((  0-PVOFSL )*(PWRRES))
/*MT6251RF*/ #define  RF_DCS_MAXGAIN         (( 62-PVOFSH )*(PWRRES))
/*MT6251RF*/ #define  RF_DCS_MINGAIN         ((  0-PVOFSH )*(PWRRES))
/*MT6251RF*/ #define  RF_PCS_MAXGAIN         (( 62-PVOFSH )*(PWRRES))
/*MT6251RF*/ #define  RF_PCS_MINGAIN         ((  0-PVOFSH )*(PWRRES))
/*MT6251RF*/
/*MT6251RF*/ /* GSM850....................................................................*/
/*MT6251RF*/
/*MT6251RF*/ const  sL1DAGCDATA  AGC_TABLE_GSM850[2] =
/*MT6251RF*/ {  {  GBOUND(( 32-PVOFSL ),( 22-PVOFSL ) ), GC_A( 0,( 32-PVOFSL ) ), 0x6000040 },
/*MT6251RF*/    {  GBOUND((  0-PVOFSL ),(  0-PVOFSL ) ), GC_A( 0,(  0-PVOFSL ) ), 0x6000000 },
/*MT6251RF*/ };
/*MT6251RF*/
/*MT6251RF*/ /* GSM900....................................................................*/
/*MT6251RF*/
/*MT6251RF*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[2] =
/*MT6251RF*/ {  {  GBOUND(( 32-PVOFSL ),( 22-PVOFSL ) ), GC_A( 0,( 32-PVOFSL ) ), 0x6000040 },
/*MT6251RF*/    {  GBOUND((  0-PVOFSL ),(  0-PVOFSL ) ), GC_A( 0,(  0-PVOFSL ) ), 0x6000000 },
/*MT6251RF*/ };
/*MT6251RF*/
/*MT6251RF*/ /* DCS1800...................................................................*/
/*MT6251RF*/
/*MT6251RF*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[2] =
/*MT6251RF*/ {  {  GBOUND(( 32-PVOFSL ),( 22-PVOFSL ) ), GC_A( 0,( 32-PVOFSL ) ), 0x6000040 },
/*MT6251RF*/    {  GBOUND((  0-PVOFSL ),(  0-PVOFSL ) ), GC_A( 0,(  0-PVOFSL ) ), 0x6000000 },
/*MT6251RF*/ };
/*MT6251RF*/
/*MT6251RF*/ /* PCS1900...................................................................*/
/*MT6251RF*/
/*MT6251RF*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[2] =
/*MT6251RF*/ {  {  GBOUND(( 32-PVOFSL ),( 22-PVOFSL ) ), GC_A( 0,( 32-PVOFSL ) ), 0x6000040 },
/*MT6251RF*/    {  GBOUND((  0-PVOFSL ),(  0-PVOFSL ) ), GC_A( 0,(  0-PVOFSL ) ), 0x6000000 },
/*MT6251RF*/ };
/*MT6251RF*/
/*MT6251RF*/ /*...........................................................................*/
/*MT6251RF*/
/*MT6251RF*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*MT6251RF*/ {  {                   0,                      0    }, /*#FrequencyBand400  */
/*MT6251RF*/    { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN }, /* FrequencyBand850  */
/*MT6251RF*/    { (int)RF_GSM_MAXGAIN,    (int)RF_GSM_MINGAIN    }, /* FrequencyBand900  */
/*MT6251RF*/    { (int)RF_DCS_MAXGAIN,    (int)RF_DCS_MINGAIN    }, /* FrequencyBand1800 */
/*MT6251RF*/    { (int)RF_PCS_MAXGAIN,    (int)RF_PCS_MINGAIN    }, /* FrequencyBand1900 */
/*MT6251RF*/ };
/*MT6251RF*/
/*MT6251RF*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*MT6251RF*/ {  0,                                              /*#FrequencyBand400  */
/*MT6251RF*/    AGC_TABLE_GSM850,                               /* FrequencyBand850  */
/*MT6251RF*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*MT6251RF*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*MT6251RF*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*MT6251RF*/ };
/*MT6251RF*/
/*MT6251RF*/ const  int  GAIN_STEP_TABLE[] =
/*MT6251RF*/ { 10, 18, 26, 34, 42, 45, 53 };   //gain step for high/low LNA gain
/*MT6251RF*/                                   //Low LNA gain  : { 10, 18, 26, 34, 42         }
/*MT6251RF*/                                   //High LNA gain : {     18, 26, 34, 42, 45, 53 }
/*MT6251RF*/
/*MT6251RF*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*MT6251RF*/
/*MT6251RF*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*MT6251RF*/ {  int   max_gain, min_gain, real_gain;
/*MT6251RF*/    const int*    d32ptr;
/*MT6251RF*/    const sL1DAGCDATA*  agcptr;
/*MT6251RF*/    long  setting;
/*MT6251RF*/    int   bit_no, gain_step, idx_shift_value;
/*MT6251RF*/
/*MT6251RF*/    /* evaluate the range of available gain */
/*MT6251RF*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*MT6251RF*/    max_gain = *d32ptr++;
/*MT6251RF*/    min_gain = *d32ptr;
/*MT6251RF*/
/*MT6251RF*/    /* clipping the request gain to the avialable gain */
/*MT6251RF*/    if( request_gain>=max_gain )
/*MT6251RF*/    {  request_gain = max_gain;  }
/*MT6251RF*/    else  if( request_gain<=min_gain )
/*MT6251RF*/    {  request_gain = min_gain;  }
/*MT6251RF*/
/*MT6251RF*/    /* evaluate the real gain setting */
/*MT6251RF*/    agcptr = AGC_TABLE[rf_band];
/*MT6251RF*/    idx_shift_value = 1;  //the lowest gain step of high LNA gain case is 18
/*MT6251RF*/    if( request_gain < agcptr->pos_gain )
/*MT6251RF*/    {  agcptr++;
/*MT6251RF*/       idx_shift_value = 0;
/*MT6251RF*/    }
/*MT6251RF*/    {
/*MT6251RF*/       bit_no = BIT_NO( request_gain, agcptr->A, GC_B );
/*MT6251RF*/       gain_step = GAIN_STEP_TABLE[bit_no+idx_shift_value];  //Use bit_no to choose gain step
/*MT6251RF*/       real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B ) - INSERTION_LOSS;
/*MT6251RF*/       setting   = agcptr->setting + gain_step;
/*MT6251RF*/       if( gain_step == 10 )
/*MT6251RF*/       {
/*MT6251RF*/          setting += 128;              // The LNA setting of the lowest gain is 10, not 00
/*MT6251RF*/          real_gain = -259;            // The real gain of lowest gain has 1.6dB offset, (-34+1.6)*8=-259
/*MT6251RF*/       }
/*MT6251RF*/    }
/*MT6251RF*/
/*MT6251RF*/    *gain_setting = setting;
/*MT6251RF*/    return( real_gain );
/*MT6251RF*/ }
/*MT6251RF*/
   #if IS_W_CANCELLATION_SUPPORT
/*MT6251RF*/ unsigned short   L1D_RF_FindGainStep( unsigned long gain_setting, FrequencyBand rf_band )
/*MT6251RF*/ {
/*MT6251RF*/    int bit_value, shift_value;
/*MT6251RF*/    unsigned short left_idx, right_idx, mid_idx, idx;
/*MT6251RF*/
/*MT6251RF*/    shift_value = (gain_setting>>6) & 0x1;
/*MT6251RF*/    bit_value = gain_setting & 0x3F;
/*MT6251RF*/    left_idx = 0;
/*MT6251RF*/    right_idx = sizeof(GAIN_STEP_TABLE)/sizeof(int)-1;
/*MT6251RF*/
/*MT6251RF*/    while( left_idx < right_idx )
/*MT6251RF*/    {
/*MT6251RF*/       mid_idx = (left_idx + right_idx) >> 1;
/*MT6251RF*/
/*MT6251RF*/       if( bit_value <= GAIN_STEP_TABLE[mid_idx])
/*MT6251RF*/          right_idx = mid_idx;
/*MT6251RF*/       else
/*MT6251RF*/          left_idx = mid_idx + 1;
/*MT6251RF*/    }
/*MT6251RF*/
/*MT6251RF*/    idx = right_idx;
/*MT6251RF*/
/*MT6251RF*/    if( shift_value == 1 )
/*MT6251RF*/       return (idx + 4);
/*MT6251RF*/    else
/*MT6251RF*/       return (idx);
/*MT6251RF*/ }
/*MT6251RF*/
   #endif
#endif

#if IS_RF_SKY74045
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

#if IS_RF_IRFS3001
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

#if IS_RF_AD6548
/*AD6548*/ #define  GAIN_STEP              3
/*AD6548*/
/*AD6548*/ #define  PVOFSL                 (-33)
/*AD6548*/ #define  PVOFSH                 (-34)
/*AD6548*/
/*AD6548*/ #define  RF_GSM850_MAXGAIN      ((80+PVOFSL)*(PWRRES))
/*AD6548*/ #define  RF_GSM850_MINGAIN      (( 3+PVOFSL)*(PWRRES))
/*AD6548*/ #define  RF_GSM_MAXGAIN         RF_GSM850_MAXGAIN
/*AD6548*/ #define  RF_GSM_MINGAIN         RF_GSM850_MINGAIN
/*AD6548*/ #define  RF_DCS_MAXGAIN         ((80+PVOFSH)*(PWRRES))
/*AD6548*/ #define  RF_DCS_MINGAIN         (( 3+PVOFSH)*(PWRRES))
/*AD6548*/ #define  RF_PCS_MAXGAIN         RF_DCS_MAXGAIN
/*AD6548*/ #define  RF_PCS_MINGAIN         RF_DCS_MINGAIN
/*AD6548*/
/*AD6548*/ const  sL1DAGCDATA  AGC_TABLE_GSM850[2] =
/*AD6548*/ { {GBOUND( (23+PVOFSL),(21+PVOFSL) ), GC_A(2,23+PVOFSL), 0x000005 },
/*AD6548*/   {GBOUND( ( 3+PVOFSL),( 3+PVOFSL) ), GC_A(2, 3+PVOFSL), 0x001005 },
/*AD6548*/ };
/*AD6548*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[2] =
/*AD6548*/ { {GBOUND( (23+PVOFSL),(21+PVOFSL) ), GC_A(2,23+PVOFSL), 0x000005 },
/*AD6548*/   {GBOUND( ( 3+PVOFSL),( 3+PVOFSL) ), GC_A(2, 3+PVOFSL), 0x001005 },
/*AD6548*/ };
/*AD6548*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[2]=
/*AD6548*/ { {GBOUND( (23+PVOFSH),(21+PVOFSH) ), GC_A(2,23+PVOFSH), 0x000005 },
/*AD6548*/   {GBOUND( ( 3+PVOFSH),( 3+PVOFSH) ), GC_A(2, 3+PVOFSH), 0x001005 },
/*AD6548*/ };
/*AD6548*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[2]=
/*AD6548*/ { {GBOUND( (23+PVOFSH),(21+PVOFSH) ), GC_A(2,23+PVOFSH), 0x000005 },
/*AD6548*/   {GBOUND( ( 3+PVOFSH),( 3+PVOFSH) ), GC_A(2, 3+PVOFSH), 0x001005 },
/*AD6548*/ };
/*AD6548*/
/*AD6548*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*AD6548*/ { {                   0,                      0    }, /*#FrequencyBand400  */
/*AD6548*/   { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN }, /* FrequencyBand850  */
/*AD6548*/   { (int)RF_GSM_MAXGAIN,    (int)RF_GSM_MINGAIN    }, /* FrequencyBand900  */
/*AD6548*/   { (int)RF_DCS_MAXGAIN,    (int)RF_DCS_MINGAIN    }, /* FrequencyBand1800 */
/*AD6548*/   { (int)RF_PCS_MAXGAIN,    (int)RF_PCS_MINGAIN    }, /* FrequencyBand1900 */
/*AD6548*/ };
/*AD6548*/
/*AD6548*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*AD6548*/ {  0,                                              /*#FrequencyBand400  */
/*AD6548*/    AGC_TABLE_GSM850,                               /* FrequencyBand850  */
/*AD6548*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*AD6548*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*AD6548*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*AD6548*/ };
/*AD6548*/
/*AD6548*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*AD6548*/ {  int   max_gain, min_gain, real_gain;
/*AD6548*/    const int*    d32ptr;
/*AD6548*/    const sL1DAGCDATA*  agcptr;
/*AD6548*/    long  setting;
/*AD6548*/    int   bit_no;
/*AD6548*/
/*AD6548*/    /* evaluate the range of available gain */
/*AD6548*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*AD6548*/    max_gain = *d32ptr++;
/*AD6548*/    min_gain = *d32ptr;
/*AD6548*/
/*AD6548*/    /* clipping the request gain to the avialable gain */
/*AD6548*/    if( request_gain>=max_gain )
/*AD6548*/    {  request_gain = max_gain;  }
/*AD6548*/    else  if( request_gain<=min_gain )
/*AD6548*/    {  request_gain = min_gain;  }
/*AD6548*/
/*AD6548*/    /* evaluate the real gain setting */
/*AD6548*/    agcptr = AGC_TABLE[rf_band];
/*AD6548*/    if( request_gain < agcptr->pos_gain )
/*AD6548*/    {  agcptr++;
/*AD6548*/    }
/*AD6548*/    {  bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*AD6548*/       real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B );
/*AD6548*/       setting   = agcptr->setting | (bit_no<<7);
/*AD6548*/    }
/*AD6548*/
/*AD6548*/    *gain_setting = setting;
/*AD6548*/    return( real_gain );
/*AD6548*/ }
/*AD6548*/
#endif

#if IS_RF_AD6546
/*AD6546*/ #define  GAIN_STEP              3
/*AD6546*/
/*AD6546*/ #define  PVOFSL                 (-33)
/*AD6546*/ #define  PVOFSH                 (-33)
/*AD6546*/
/*AD6546*/ #define  RF_GSM850_MAXGAIN      ((74+PVOFSL)*(PWRRES))
/*AD6546*/ #define  RF_GSM850_MINGAIN      (( 3+PVOFSL)*(PWRRES))
/*AD6546*/ #define  RF_GSM_MAXGAIN         RF_GSM850_MAXGAIN
/*AD6546*/ #define  RF_GSM_MINGAIN         RF_GSM850_MINGAIN
/*AD6546*/ #define  RF_DCS_MAXGAIN         ((74+PVOFSH)*(PWRRES))
/*AD6546*/ #define  RF_DCS_MINGAIN         (( 3+PVOFSH)*(PWRRES))
/*AD6546*/ #define  RF_PCS_MAXGAIN         RF_DCS_MAXGAIN
/*AD6546*/ #define  RF_PCS_MINGAIN         RF_DCS_MINGAIN
/*AD6546*/
/*AD6546*/ const  sL1DAGCDATA  AGC_TABLE_GSM850[2] =
/*AD6546*/ { {GBOUND( (23+PVOFSL),(21+PVOFSL) ), GC_A(2,23+PVOFSL), 0x000005 },
/*AD6546*/   {GBOUND( ( 3+PVOFSL),( 3+PVOFSL) ), GC_A(2, 3+PVOFSL), 0x001005 },
/*AD6546*/ };
/*AD6546*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[2] =
/*AD6546*/ { {GBOUND( (23+PVOFSL),(21+PVOFSL) ), GC_A(2,23+PVOFSL), 0x000005 },
/*AD6546*/   {GBOUND( ( 3+PVOFSL),( 3+PVOFSL) ), GC_A(2, 3+PVOFSL), 0x001005 },
/*AD6546*/ };
/*AD6546*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[2]=
/*AD6546*/ { {GBOUND( (23+PVOFSH),(21+PVOFSH) ), GC_A(2,23+PVOFSH), 0x000005 },
/*AD6546*/   {GBOUND( ( 3+PVOFSH),( 3+PVOFSH) ), GC_A(2, 3+PVOFSH), 0x001005 },
/*AD6546*/ };
/*AD6546*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[2]=
/*AD6546*/ { {GBOUND( (23+PVOFSH),(21+PVOFSH) ), GC_A(2,23+PVOFSH), 0x000005 },
/*AD6546*/   {GBOUND( ( 3+PVOFSH),( 3+PVOFSH) ), GC_A(2, 3+PVOFSH), 0x001005 },
/*AD6546*/ };
/*AD6546*/
/*AD6546*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*AD6546*/ { {                   0,                      0    }, /*#FrequencyBand400  */
/*AD6546*/   { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN }, /* FrequencyBand850  */
/*AD6546*/   { (int)RF_GSM_MAXGAIN,    (int)RF_GSM_MINGAIN    }, /* FrequencyBand900  */
/*AD6546*/   { (int)RF_DCS_MAXGAIN,    (int)RF_DCS_MINGAIN    }, /* FrequencyBand1800 */
/*AD6546*/   { (int)RF_PCS_MAXGAIN,    (int)RF_PCS_MINGAIN    }, /* FrequencyBand1900 */
/*AD6546*/ };
/*AD6546*/
/*AD6546*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*AD6546*/ {  0,                                              /*#FrequencyBand400  */
/*AD6546*/    AGC_TABLE_GSM850,                               /* FrequencyBand850  */
/*AD6546*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*AD6546*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*AD6546*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*AD6546*/ };
/*AD6546*/
/*AD6546*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*AD6546*/ {
/*AD6546*/    int   max_gain, min_gain, real_gain;
/*AD6546*/    const int*    d32ptr;
/*AD6546*/    const sL1DAGCDATA*  agcptr;
/*AD6546*/    long  setting;
/*AD6546*/    int   bit_no;
/*AD6546*/
/*AD6546*/    /* evaluate the range of available gain */
/*AD6546*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*AD6546*/    max_gain = *d32ptr++;
/*AD6546*/    min_gain = *d32ptr;
/*AD6546*/
/*AD6546*/    /* clipping the request gain to the avialable gain */
/*AD6546*/    if( request_gain>=max_gain )
/*AD6546*/    {  request_gain = max_gain;  }
/*AD6546*/    else  if( request_gain<=min_gain )
/*AD6546*/    {  request_gain = min_gain;  }
/*AD6546*/
/*AD6546*/    /* evaluate the real gain setting */
/*AD6546*/    agcptr = AGC_TABLE[rf_band];
/*AD6546*/    if( request_gain < agcptr->pos_gain )
/*AD6546*/    {  agcptr++;
/*AD6546*/    }
/*AD6546*/    {  bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*AD6546*/       real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B );
/*AD6546*/       setting   = agcptr->setting | (bit_no<<7);
/*AD6546*/    }
/*AD6546*/
/*AD6546*/    *gain_setting = setting;
/*AD6546*/    return( real_gain );
/*AD6546*/ }
/*AD6546*/
#endif

#if IS_RF_MT6162 || IS_RF_MT6163
/*MT6162*/ #define  GAIN_STEP              3
/*MT6162*/
/*MT6162*/ #define  PVOFSL                 (34)
/*MT6162*/ #define  PVOFSH                 (34)
/*MT6162*/
/*MT6162*/ #define  RF_GSM850_MAXGAIN      ((66-PVOFSL)*(PWRRES))
/*MT6162*/ #define  RF_GSM850_MINGAIN      (( 9-PVOFSL)*(PWRRES))
/*MT6162*/ #define  RF_GSM_MAXGAIN         RF_GSM850_MAXGAIN
/*MT6162*/ #define  RF_GSM_MINGAIN         RF_GSM850_MINGAIN
/*MT6162*/ #define  RF_DCS_MAXGAIN         ((66-PVOFSH)*(PWRRES))
/*MT6162*/ #define  RF_DCS_MINGAIN         (( 9-PVOFSH)*(PWRRES))
/*MT6162*/ #define  RF_PCS_MAXGAIN         RF_DCS_MAXGAIN
/*MT6162*/ #define  RF_PCS_MINGAIN         RF_DCS_MINGAIN
/*MT6162*/
/*MT6162*/ const  sL1DAGCDATA  AGC_TABLE_GSM850[3] =
/*MT6162*/ { {GBOUND( (54-PVOFSL),(51-PVOFSL) ), GC_A(8,54-PVOFSL), 0x00300 },
/*MT6162*/   {GBOUND( (36-PVOFSL),(33-PVOFSL) ), GC_A(5,36-PVOFSL), 0x00200 },
/*MT6162*/   {GBOUND( ( 9-PVOFSL),( 9-PVOFSL) ), GC_A(0, 9-PVOFSL), 0x00100 },
/*MT6162*/ };
/*MT6162*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[3] =
/*MT6162*/ { {GBOUND( (54-PVOFSL),(51-PVOFSL) ), GC_A(8,54-PVOFSL), 0x00300 },
/*MT6162*/   {GBOUND( (36-PVOFSL),(33-PVOFSL) ), GC_A(5,36-PVOFSL), 0x00200 },
/*MT6162*/   {GBOUND( ( 9-PVOFSL),( 9-PVOFSL) ), GC_A(0, 9-PVOFSL), 0x00100 },
/*MT6162*/ };
/*MT6162*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[3]=
/*MT6162*/ { {GBOUND( (54-PVOFSH),(51-PVOFSH) ), GC_A(8,54-PVOFSH), 0x00300 },
/*MT6162*/   {GBOUND( (36-PVOFSH),(33-PVOFSH) ), GC_A(5,36-PVOFSH), 0x00200 },
/*MT6162*/   {GBOUND( ( 9-PVOFSH),( 9-PVOFSH) ), GC_A(0, 9-PVOFSH), 0x00100 },
/*MT6162*/ };
/*MT6162*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[3]=
/*MT6162*/ { {GBOUND( (54-PVOFSH),(51-PVOFSH) ), GC_A(8,54-PVOFSH), 0x00300 },
/*MT6162*/   {GBOUND( (36-PVOFSH),(33-PVOFSH) ), GC_A(5,36-PVOFSH), 0x00200 },
/*MT6162*/   {GBOUND( ( 9-PVOFSH),( 9-PVOFSH) ), GC_A(0, 9-PVOFSH), 0x00100 },
/*MT6162*/ };
/*MT6162*/
/*MT6162*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*MT6162*/ { {                   0,                      0    }, /* FrequencyBand400  */
/*MT6162*/   { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN }, /* FrequencyBand850  */
/*MT6162*/   { (int)RF_GSM_MAXGAIN,    (int)RF_GSM_MINGAIN    }, /* FrequencyBand900  */
/*MT6162*/   { (int)RF_DCS_MAXGAIN,    (int)RF_DCS_MINGAIN    }, /* FrequencyBand1800 */
/*MT6162*/   { (int)RF_PCS_MAXGAIN,    (int)RF_PCS_MINGAIN    }, /* FrequencyBand1900 */
/*MT6162*/ };
/*MT6162*/
/*MT6162*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*MT6162*/ {  0,                                                 /* FrequencyBand400  */
/*MT6162*/    AGC_TABLE_GSM850,                                  /* FrequencyBand850  */
/*MT6162*/    AGC_TABLE_GSM900,                                  /* FrequencyBand900  */
/*MT6162*/    AGC_TABLE_DCS1800,                                 /* FrequencyBand1800 */
/*MT6162*/    AGC_TABLE_PCS1900,                                 /* FrequencyBand1900 */
/*MT6162*/ };
/*MT6162*/
/*MT6162*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*MT6162*/ {
/*MT6162*/    int   max_gain, min_gain, real_gain;
/*MT6162*/    const int*    d32ptr;
/*MT6162*/    const sL1DAGCDATA*  agcptr;
/*MT6162*/    sLNAGAINOFFSET* lnaptr;
/*MT6162*/    sAGCGAINOFFSET* ofsptr;
/*MT6162*/    long  setting;
/*MT6162*/    int   bit_no, idx, lna_path_loss;
/*MT6162*/ #if IS_RF_RX_DCOC_SUPPORT
/*MT6162*/    int   biquad_gain;
/*MT6162*/    signed short  dc_offset_i, dc_offset_q;
/*MT6162*/ #endif
/*MT6162*/
/*MT6162*/    /* evaluate the range of available gain */
/*MT6162*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*MT6162*/    max_gain = *d32ptr++;
/*MT6162*/    min_gain = *d32ptr;
/*MT6162*/
/*MT6162*/
/*MT6162*/    /* choose the LNA path loss */
/*MT6162*/    lnaptr = LNA_PATHLOSS_TABLE[rf_band];
/*MT6162*/    /* get the arfcn section */
/*MT6162*/    ofsptr = AGC_PATHLOSS_TABLE[rf_band];
/*MT6162*/    while( ofsptr->max_arfcn>=0 )
/*MT6162*/    {  if( arfcn <= ofsptr->max_arfcn )
/*MT6162*/       {  break;  }
/*MT6162*/       ofsptr++;
/*MT6162*/       lnaptr++;
/*MT6162*/    }
/*MT6162*/
/*MT6162*/    /* evaluate the real gain setting */
/*MT6162*/    agcptr = AGC_TABLE[rf_band];
/*MT6162*/    while( request_gain < agcptr->pos_gain )
/*MT6162*/    {  agcptr++;
/*MT6162*/       if(agcptr->pos_gain == GBOUND( ( 9-PVOFSL),( 9-PVOFSL) ))
/*MT6162*/       {
/*MT6162*/          break;
/*MT6162*/       }
/*MT6162*/    }
/*MT6162*/    {  idx       = (int)(((agcptr->setting)>>8)&0x3);
/*MT6162*/       if( idx==3 )      /* LNA_High */
/*MT6162*/       {  lna_path_loss = 0;  }
/*MT6162*/       else if( idx==2 ) /* LNA_Middle */
/*MT6162*/       {  lna_path_loss = (l1d_rf2.is_fhc) ? (0) : ((int)(lnaptr->gain_offset_middle-ofsptr->gain_offset));  }
/*MT6162*/       else              /* LNA_Low */
/*MT6162*/       {  lna_path_loss = (l1d_rf2.is_fhc) ? (0) : ((int)(lnaptr->gain_offset_low-ofsptr->gain_offset));     }
/*MT6162*/
/*MT6162*/       request_gain+=lna_path_loss;
/*MT6162*/
/*MT6162*/       /* clipping the request gain to the avialable gain */
/*MT6162*/       if( request_gain>=max_gain )
/*MT6162*/       {  request_gain = max_gain;  }
/*MT6162*/       else  if( request_gain<=min_gain )
/*MT6162*/       {  request_gain = min_gain;  }
/*MT6162*/
/*MT6162*/       bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*MT6162*/       real_gain = -lna_path_loss+REAL_GAIN( bit_no, agcptr->A, GC_B );
/*MT6162*/       setting   = agcptr->setting | (bit_no&0xF);
/*MT6162*/    }
/*MT6162*/
/*MT6162*/    *gain_setting = setting;
/*MT6162*/
/*MT6162*/    l1d_rf2.rx_dc_offset = 0;
/*MT6162*/ #if IS_RF_RX_DCOC_SUPPORT
/*MT6162*/    biquad_gain = BBGAIN_DECODE_TABLE[(setting&0xF)][0];
/*MT6162*/    dc_offset_i = l1d_rf2.rx_dc_offset_i[rf_band-1][biquad_gain/6];
/*MT6162*/    dc_offset_q = l1d_rf2.rx_dc_offset_q[rf_band-1][biquad_gain/6];
/*MT6162*/    #if IS_RF_RX_DCOC_WITH_PRECISION_IMPROVEMENT
/*MT6162*/    if( dc_offset_i>0 )
/*MT6162*/       dc_offset_i = (  ( dc_offset_i+(1<<(ALPHA_FILTER_SCALE-1)))>>ALPHA_FILTER_SCALE  );
/*MT6162*/    else
/*MT6162*/       dc_offset_i = (-((-dc_offset_i+(1<<(ALPHA_FILTER_SCALE-1)))>>ALPHA_FILTER_SCALE));
/*MT6162*/    if( dc_offset_q>0 )
/*MT6162*/       dc_offset_q = (  ( dc_offset_q+(1<<(ALPHA_FILTER_SCALE-1)))>>ALPHA_FILTER_SCALE  );
/*MT6162*/    else
/*MT6162*/       dc_offset_q = (-((-dc_offset_q+(1<<(ALPHA_FILTER_SCALE-1)))>>ALPHA_FILTER_SCALE));
/*MT6162*/    #endif /* IS_RF_RX_DCOC_WITH_PRECISION_IMPROVEMENT */
/*MT6162*/    l1d_rf2.rx_dc_offset = (unsigned long)(((dc_offset_q&0xFF)<<8)|(dc_offset_i&0xFF) );
/*MT6162*/ #endif
/*MT6162*/
/*MT6162*/    return( real_gain );
/*MT6162*/ }
/*MT6162*/
#endif

#if IS_RF_MT6280RF
/*MT6280RF*/
/*MT6280RF*/ #define  GAIN_STEP               3
/*MT6280RF*/ #define  PVOFSL                  34
/*MT6280RF*/ #define  PVOFSH                  34
/*MT6280RF*/ #define  MIXER_GAIN             (9*(PWRRES))
/*MT6280RF*/ #define  RF_GSM850_MAXGAIN      (( 51-PVOFSL )*(PWRRES))
/*MT6280RF*/ #define  RF_GSM850_MINGAIN      (( -3-PVOFSL )*(PWRRES))
/*MT6280RF*/ #define  RF_GSM_MAXGAIN         (( 51-PVOFSL )*(PWRRES))
/*MT6280RF*/ #define  RF_GSM_MINGAIN         (( -3-PVOFSL )*(PWRRES))
/*MT6280RF*/ #define  RF_DCS_MAXGAIN         (( 51-PVOFSH )*(PWRRES))
/*MT6280RF*/ #define  RF_DCS_MINGAIN         (( -3-PVOFSH )*(PWRRES))
/*MT6280RF*/ #define  RF_PCS_MAXGAIN         (( 51-PVOFSH )*(PWRRES))
/*MT6280RF*/ #define  RF_PCS_MINGAIN         (( -3-PVOFSH )*(PWRRES))
/*MT6280RF*/
/*MT6280RF*/ /* if no rx cal. DCOC_DACI/DCOC_DACQ in CW12 use the default value */
/*MT6280RF*/ #define  RXIF_DCOC_DACI_M       0x90000
/*MT6280RF*/ #define  RXIF_DCOC_DACQ_M       0x00000
/*MT6280RF*/
/*MT6280RF*/ /* GSM850....................................................................*/
/*MT6280RF*/
/*MT6280RF*/ const  sL1DAGCDATA  AGC_TABLE_GSM850[3] =
/*MT6280RF*/ {  {  GBOUND(( 39-PVOFSL ),( 36-PVOFSL ) ), GC_A( 4,( 39-PVOFSL ) ), BSI_CW(0x0C, 0x00080) },
/*MT6280RF*/    {  GBOUND(( 21-PVOFSL ),( 18-PVOFSL ) ), GC_A( 2,( 21-PVOFSL ) ), BSI_CW(0x0C, 0x00020) },
/*MT6280RF*/    {  GBOUND(( -3-PVOFSL ),( -3-PVOFSL ) ), GC_A( 0,( -3-PVOFSL ) ), BSI_CW(0x0C, 0x00000) },
/*MT6280RF*/ };
/*MT6280RF*/
/*MT6280RF*/ /* GSM900....................................................................*/
/*MT6280RF*/
/*MT6280RF*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[3] =
/*MT6280RF*/ {  {  GBOUND(( 39-PVOFSL ),( 36-PVOFSL ) ), GC_A( 4,( 39-PVOFSL ) ), BSI_CW(0x0C, 0x00080) },
/*MT6280RF*/    {  GBOUND(( 21-PVOFSL ),( 18-PVOFSL ) ), GC_A( 2,( 21-PVOFSL ) ), BSI_CW(0x0C, 0x00020) },
/*MT6280RF*/    {  GBOUND(( -3-PVOFSL ),( -3-PVOFSL ) ), GC_A( 0,( -3-PVOFSL ) ), BSI_CW(0x0C, 0x00000) },
/*MT6280RF*/ };
/*MT6280RF*/
/*MT6280RF*/ /* DCS1800...................................................................*/
/*MT6280RF*/
/*MT6280RF*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[3] =
/*MT6280RF*/ {  {  GBOUND(( 39-PVOFSH ),( 36-PVOFSH ) ), GC_A( 4,( 39-PVOFSH ) ), BSI_CW(0x0C, 0x00080) },
/*MT6280RF*/    {  GBOUND(( 21-PVOFSH ),( 18-PVOFSH ) ), GC_A( 2,( 21-PVOFSH ) ), BSI_CW(0x0C, 0x00020) },
/*MT6280RF*/    {  GBOUND(( -3-PVOFSH ),( -3-PVOFSH ) ), GC_A( 0,( -3-PVOFSH ) ), BSI_CW(0x0C, 0x00000) },
/*MT6280RF*/ };
/*MT6280RF*/
/*MT6280RF*/ /* PCS1900...................................................................*/
/*MT6280RF*/
/*MT6280RF*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[3] =
/*MT6280RF*/ {  {  GBOUND(( 39-PVOFSH ),( 36-PVOFSH ) ), GC_A( 4,( 39-PVOFSH ) ), BSI_CW(0x0C, 0x00080) },
/*MT6280RF*/    {  GBOUND(( 21-PVOFSH ),( 18-PVOFSH ) ), GC_A( 2,( 21-PVOFSH ) ), BSI_CW(0x0C, 0x00020) },
/*MT6280RF*/    {  GBOUND(( -3-PVOFSH ),( -3-PVOFSH ) ), GC_A( 0,( -3-PVOFSH ) ), BSI_CW(0x0C, 0x00000) },
/*MT6280RF*/ };
/*MT6280RF*/
/*MT6280RF*/ /*...........................................................................*/
/*MT6280RF*/
/*MT6280RF*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*MT6280RF*/ {  {                   0,                      0    }, /*#FrequencyBand400  */
/*MT6280RF*/    { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN }, /* FrequencyBand850  */
/*MT6280RF*/    { (int)RF_GSM_MAXGAIN,    (int)RF_GSM_MINGAIN    }, /* FrequencyBand900  */
/*MT6280RF*/    { (int)RF_DCS_MAXGAIN,    (int)RF_DCS_MINGAIN    }, /* FrequencyBand1800 */
/*MT6280RF*/    { (int)RF_PCS_MAXGAIN,    (int)RF_PCS_MINGAIN    }, /* FrequencyBand1900 */
/*MT6280RF*/ };
/*MT6280RF*/
/*MT6280RF*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*MT6280RF*/ {  0,                                              /*#FrequencyBand400  */
/*MT6280RF*/    AGC_TABLE_GSM850,                               /* FrequencyBand850  */
/*MT6280RF*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*MT6280RF*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*MT6280RF*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*MT6280RF*/ };
/*MT6280RF*/
/*MT6280RF*/
/*MT6280RF*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*MT6280RF*/
/*MT6280RF*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*MT6280RF*/ {  int   max_gain, min_gain, real_gain;
/*MT6280RF*/    const int*    d32ptr;
/*MT6280RF*/    const sL1DAGCDATA*  agcptr;
/*MT6280RF*/    sLNAGAINOFFSET*     lnaptr;
/*MT6280RF*/    sAGCGAINOFFSET*     ofsptr;
/*MT6280RF*/    long  setting;
/*MT6280RF*/    int   bit_no, idx, lna_path_loss;
/*MT6280RF*/
/*MT6280RF*/    /* evaluate the range of available gain */
/*MT6280RF*/    d32ptr   = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*MT6280RF*/    max_gain = *d32ptr++;
/*MT6280RF*/    min_gain = *d32ptr;
/*MT6280RF*/
/*MT6280RF*/    /* clipping the request gain to the avialable gain */
/*MT6280RF*/    if( request_gain>=max_gain )
/*MT6280RF*/    {  request_gain = max_gain;
/*MT6280RF*/    }
/*MT6280RF*/    else if( request_gain<=min_gain )
/*MT6280RF*/    {  request_gain = min_gain;
/*MT6280RF*/    }
/*MT6280RF*/
/*MT6280RF*/    /* choose the LNA path loss */
/*MT6280RF*/    lnaptr = LNA_PATHLOSS_TABLE[rf_band];
/*MT6280RF*/    /* get the arfcn section */
/*MT6280RF*/    ofsptr = AGC_PATHLOSS_TABLE[rf_band];
/*MT6280RF*/    while( ofsptr->max_arfcn>=0 )
/*MT6280RF*/    {  if( arfcn <= ofsptr->max_arfcn )
/*MT6280RF*/       {  break;  }
/*MT6280RF*/       ofsptr++;
/*MT6280RF*/       lnaptr++;
/*MT6280RF*/    }
/*MT6280RF*/
/*MT6280RF*/    /* evaluate the real gain setting */
/*MT6280RF*/    agcptr = AGC_TABLE[rf_band];
/*MT6280RF*/    while( request_gain < agcptr->pos_gain )
/*MT6280RF*/    {  agcptr++;
/*MT6280RF*/    }
/*MT6280RF*/    {
/*MT6280RF*/       idx = (int)(((agcptr->setting)>>5)&0x7);
/*MT6280RF*/       if( idx==4 )      /* LNA_High */
/*MT6280RF*/       {  lna_path_loss = 0;  }
/*MT6280RF*/       else if( idx==1 ) /* LNA_Middle */
/*MT6280RF*/       {  lna_path_loss = (l1d_rf2.is_fhc) ? (0) : ((int)(lnaptr->gain_offset_middle-ofsptr->gain_offset));  }
/*MT6280RF*/       else              /* LNA_Low */
/*MT6280RF*/       {  lna_path_loss = (l1d_rf2.is_fhc) ? (0) : ((int)(lnaptr->gain_offset_low-ofsptr->gain_offset));     }
/*MT6280RF*/
/*MT6280RF*/       bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*MT6280RF*/       real_gain = -lna_path_loss+REAL_GAIN( bit_no, agcptr->A, GC_B );
/*MT6280RF*/    #if IS_HEADROOM_DETECTION_SUPPORT || IS_INBAND_BLOCKER_DETECTION_SUPPORT
/*MT6280RF*/       if( ( ((l1d_rf.blk_flag)&(HRD_FOUND)) && (request_gain >= -4*PWRRES) ) || ( ((l1d_rf.blk_flag)&(IBB_FOUND)) && (request_gain >= 8*PWRRES) ) )
/*MT6280RF*/       {        /* CW12: LNA GAIN     |MIXER GAIN| IF GAIN */
/*MT6280RF*/          setting   = agcptr->setting | (0x1<<4) | (bit_no&0xF);
/*MT6280RF*/          real_gain -= MIXER_GAIN;
/*MT6280RF*/       }
/*MT6280RF*/       else
/*MT6280RF*/    #endif
/*MT6280RF*/       {  setting   = agcptr->setting | (bit_no&0xF);
/*MT6280RF*/       }
/*MT6280RF*/    }
/*MT6280RF*/
/*MT6280RF*/    /* if cal. DCOC_DACI/DCOC_DACQ in CW12 use the calibrated data */
/*MT6280RF*/    if( (l1d_rf2.is_power_on_cal)&(RXRC_DCOC_CAL_DONE) )
/*MT6280RF*/    {  setting |= ((l1d_rf2.rxif_dcoc_daci_m[rf_band-FrequencyBand850][bit_no]&0x3F)<<14) | ((l1d_rf2.rxif_dcoc_dacq_m[rf_band-FrequencyBand850][bit_no]&0x3F)<<8);
/*MT6280RF*/    }
/*MT6280RF*/    else
/*MT6280RF*/    {  setting |= RXIF_DCOC_DACI_M | RXIF_DCOC_DACQ_M;
/*MT6280RF*/    }
/*MT6280RF*/
/*MT6280RF*/    *gain_setting = setting;
/*MT6280RF*/    return( real_gain );
/*MT6280RF*/ }
/*MT6280RF*/
   #if IS_W_CANCELLATION_SUPPORT
/*MT6280RF*/ unsigned short   L1D_RF_FindGainStep( unsigned long gain_setting, FrequencyBand rf_band  )
/*MT6280RF*/ {
/*MT6280RF*/    int lna_gain_setting;
/*MT6280RF*/    int tz_gain_setting;
/*MT6280RF*/    int if_gain_setting;
/*MT6280RF*/
/*MT6280RF*/    lna_gain_setting = (gain_setting>>5) & 0x7;
/*MT6280RF*/    tz_gain_setting  = (gain_setting>>4) & 0x1;
/*MT6280RF*/    if_gain_setting  = (gain_setting>>0) & 0xF; /* bit_no */
/*MT6280RF*/
/*MT6280RF*/    #if IS_HEADROOM_DETECTION_SUPPORT || IS_INBAND_BLOCKER_DETECTION_SUPPORT
/*MT6280RF*/    if( tz_gain_setting == 0x1 )               /*        ACI2   Gain Table      */
/*MT6280RF*/    {                                          /* ----------------------------- */
/*MT6280RF*/       if( lna_gain_setting == 0x4 )           /* gain| bit | tz_gain |lna_gain */
/*MT6280RF*/       {                                       /*  idx|  no | setting | setting */
/*MT6280RF*/          return ( if_gain_setting+8 );        /* ----+-----+---------+-------- */
/*MT6280RF*/       }                                       /*  16 |  8  |  (tz=1) |         */
/*MT6280RF*/       else if( lna_gain_setting == 0x1 )      /*  15 |  7  |         |  LNA    */
/*MT6280RF*/       {                                       /*  14 |  6  |  ACI2   |  High   */
/*MT6280RF*/          if( if_gain_setting>=5 )             /*  13 |  5  |         |  Gain   */
/*MT6280RF*/             return ( if_gain_setting-4+8);    /*  12 |  4  |  Gain   |         */
/*MT6280RF*/          else                                 /* ----+-----|         |-------- */
/*MT6280RF*/             return 0;                         /*  11 |  7  |  Table  |  LNA    */
/*MT6280RF*/       }                                       /*  10 |  6  |         |  Mid    */
/*MT6280RF*/       else                                    /*   9 |  5  |         |  Gain   */
/*MT6280RF*/       {                                       /* ----+-----+---------+-------- */
/*MT6280RF*/          return 0;                            /*   0 | 0~4 |       other       */
/*MT6280RF*/       }                                       /* ----------------------------- */
/*MT6280RF*/    }
/*MT6280RF*/    else
/*MT6280RF*/    #endif
/*MT6280RF*/    {                                          /*        Normal Gain Table      */
/*MT6280RF*/       if( lna_gain_setting == 0x4 )           /* ----------------------------- */
/*MT6280RF*/       {                                       /* gain| bit | tz_gain |lna_gain */
/*MT6280RF*/          return ( if_gain_setting   );        /*  idx|  no | setting | setting */
/*MT6280RF*/       }                                       /* ----+-----+---------+-------- */
/*MT6280RF*/       else if( lna_gain_setting == 0x1 )      /*   8 |  8  |  (tz=0) |         */
/*MT6280RF*/       {                                       /*   7 |  7  |         |  LNA    */
/*MT6280RF*/          if( if_gain_setting>=5 )             /*   6 |  6  |  Normal |  High   */
/*MT6280RF*/             return ( if_gain_setting-4 );     /*   5 |  5  |         |  Gain   */
/*MT6280RF*/          else                                 /*   4 |  4  |  Gain   |         */
/*MT6280RF*/             return 0;                         /* ----+-----|         |-------- */
/*MT6280RF*/       }                                       /*   3 |  7  |  Table  |  LNA    */
/*MT6280RF*/       else                                    /*   2 |  6  |         |  Mid    */
/*MT6280RF*/       {                                       /*   1 |  5  |         |  Gain   */
/*MT6280RF*/          return 0;                            /* ----+-----+------------------ */
/*MT6280RF*/       }                                       /*   0 | 0~4 |       other       */
/*MT6280RF*/    }                                          /* ----------------------------- */
/*MT6280RF*/ }
/*MT6280RF*/
   #endif
#endif

#if IS_RF_MT6167
/*MT6167*/
/*MT6167*/ #define  GAIN_STEP               3
/*MT6167*/ #define  PVOFSL                  34
/*MT6167*/ #define  PVOFSH                  34
/*MT6167*/ #define  MIXER_GAIN             (9*(PWRRES))
/*MT6167*/ #define  RF_GSM850_MAXGAIN      (( 51-PVOFSL )*(PWRRES))
/*MT6167*/ #define  RF_GSM850_MINGAIN      (( -3-PVOFSL )*(PWRRES))
/*MT6167*/ #define  RF_GSM_MAXGAIN         (( 51-PVOFSL )*(PWRRES))
/*MT6167*/ #define  RF_GSM_MINGAIN         (( -3-PVOFSL )*(PWRRES))
/*MT6167*/ #define  RF_DCS_MAXGAIN         (( 51-PVOFSH )*(PWRRES))
/*MT6167*/ #define  RF_DCS_MINGAIN         (( -3-PVOFSH )*(PWRRES))
/*MT6167*/ #define  RF_PCS_MAXGAIN         (( 51-PVOFSH )*(PWRRES))
/*MT6167*/ #define  RF_PCS_MINGAIN         (( -3-PVOFSH )*(PWRRES))
/*MT6167*/
/*MT6167*/ /* GSM850....................................................................*/
/*MT6167*/
/*MT6167*/ const  sL1DAGCDATA  AGC_TABLE_GSM850[3] =
/*MT6167*/ {  {  GBOUND(( 39-PVOFSL ),( 36-PVOFSL ) ), GC_A( 4,( 39-PVOFSL ) ), BSI_CW(0x0C, 0x00080) },
/*MT6167*/    {  GBOUND(( 21-PVOFSL ),( 18-PVOFSL ) ), GC_A( 2,( 21-PVOFSL ) ), BSI_CW(0x0C, 0x00020) },
/*MT6167*/    {  GBOUND(( -3-PVOFSL ),( -3-PVOFSL ) ), GC_A( 0,( -3-PVOFSL ) ), BSI_CW(0x0C, 0x00000) },
/*MT6167*/ };
/*MT6167*/
/*MT6167*/ /* GSM900....................................................................*/
/*MT6167*/
/*MT6167*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[3] =
/*MT6167*/ {  {  GBOUND(( 39-PVOFSL ),( 36-PVOFSL ) ), GC_A( 4,( 39-PVOFSL ) ), BSI_CW(0x0C, 0x00080) },
/*MT6167*/    {  GBOUND(( 21-PVOFSL ),( 18-PVOFSL ) ), GC_A( 2,( 21-PVOFSL ) ), BSI_CW(0x0C, 0x00020) },
/*MT6167*/    {  GBOUND(( -3-PVOFSL ),( -3-PVOFSL ) ), GC_A( 0,( -3-PVOFSL ) ), BSI_CW(0x0C, 0x00000) },
/*MT6167*/ };
/*MT6167*/
/*MT6167*/ /* DCS1800...................................................................*/
/*MT6167*/
/*MT6167*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[3] =
/*MT6167*/ {  {  GBOUND(( 39-PVOFSH ),( 36-PVOFSH ) ), GC_A( 4,( 39-PVOFSH ) ), BSI_CW(0x0C, 0x00080) },
/*MT6167*/    {  GBOUND(( 21-PVOFSH ),( 18-PVOFSH ) ), GC_A( 2,( 21-PVOFSH ) ), BSI_CW(0x0C, 0x00020) },
/*MT6167*/    {  GBOUND(( -3-PVOFSH ),( -3-PVOFSH ) ), GC_A( 0,( -3-PVOFSH ) ), BSI_CW(0x0C, 0x00000) },
/*MT6167*/ };
/*MT6167*/
/*MT6167*/ /* PCS1900...................................................................*/
/*MT6167*/
/*MT6167*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[3] =
/*MT6167*/ {  {  GBOUND(( 39-PVOFSH ),( 36-PVOFSH ) ), GC_A( 4,( 39-PVOFSH ) ), BSI_CW(0x0C, 0x00080) },
/*MT6167*/    {  GBOUND(( 21-PVOFSH ),( 18-PVOFSH ) ), GC_A( 2,( 21-PVOFSH ) ), BSI_CW(0x0C, 0x00020) },
/*MT6167*/    {  GBOUND(( -3-PVOFSH ),( -3-PVOFSH ) ), GC_A( 0,( -3-PVOFSH ) ), BSI_CW(0x0C, 0x00000) },
/*MT6167*/ };
/*MT6167*/
/*MT6167*/ /*...........................................................................*/
/*MT6167*/
/*MT6167*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*MT6167*/ {  {                   0,                      0    }, /*#FrequencyBand400  */
/*MT6167*/    { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN }, /* FrequencyBand850  */
/*MT6167*/    { (int)RF_GSM_MAXGAIN,    (int)RF_GSM_MINGAIN    }, /* FrequencyBand900  */
/*MT6167*/    { (int)RF_DCS_MAXGAIN,    (int)RF_DCS_MINGAIN    }, /* FrequencyBand1800 */
/*MT6167*/    { (int)RF_PCS_MAXGAIN,    (int)RF_PCS_MINGAIN    }, /* FrequencyBand1900 */
/*MT6167*/ };
/*MT6167*/
/*MT6167*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*MT6167*/ {  0,                                              /*#FrequencyBand400  */
/*MT6167*/    AGC_TABLE_GSM850,                               /* FrequencyBand850  */
/*MT6167*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*MT6167*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*MT6167*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*MT6167*/ };
/*MT6167*/
/*MT6167*/
/*MT6167*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*MT6167*/
/*MT6167*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*MT6167*/ {  int   max_gain, min_gain, real_gain;
/*MT6167*/    const int*    d32ptr;
/*MT6167*/    const sL1DAGCDATA*  agcptr;
/*MT6167*/    sLNAGAINOFFSET*     lnaptr;
/*MT6167*/    sAGCGAINOFFSET*     ofsptr;
/*MT6167*/    long  setting;
/*MT6167*/    int   bit_no, idx, lna_path_loss;
/*MT6167*/
/*MT6167*/    /* evaluate the range of available gain */
/*MT6167*/    d32ptr   = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*MT6167*/    max_gain = *d32ptr++;
/*MT6167*/    min_gain = *d32ptr;
/*MT6167*/
/*MT6167*/    /* clipping the request gain to the avialable gain */
/*MT6167*/    if( request_gain>=max_gain )
/*MT6167*/    {  request_gain = max_gain;
/*MT6167*/    }
/*MT6167*/    else if( request_gain<=min_gain )
/*MT6167*/    {  request_gain = min_gain;
/*MT6167*/    }
/*MT6167*/
/*MT6167*/    /* choose the LNA path loss */
/*MT6167*/    lnaptr = LNA_PATHLOSS_TABLE[rf_band];
/*MT6167*/    /* get the arfcn section */
/*MT6167*/    ofsptr = AGC_PATHLOSS_TABLE[rf_band];
/*MT6167*/    while( ofsptr->max_arfcn>=0 )
/*MT6167*/    {  if( arfcn <= ofsptr->max_arfcn )
/*MT6167*/       {  break;  }
/*MT6167*/       ofsptr++;
/*MT6167*/       lnaptr++;
/*MT6167*/    }
/*MT6167*/
/*MT6167*/    /* evaluate the real gain setting */
/*MT6167*/    agcptr = AGC_TABLE[rf_band];
/*MT6167*/    while( request_gain < agcptr->pos_gain )
/*MT6167*/    {  agcptr++;
/*MT6167*/    }
/*MT6167*/    {
/*MT6167*/       idx = (int)(((agcptr->setting)>>5)&0x7);
/*MT6167*/       if( idx==4 )      /* LNA_High */
/*MT6167*/       {  lna_path_loss = 0;  }
/*MT6167*/       else if( idx==1 ) /* LNA_Middle */
/*MT6167*/       {  lna_path_loss = (l1d_rf2.is_fhc) ? (0) : ((int)(lnaptr->gain_offset_middle-ofsptr->gain_offset));  }
/*MT6167*/       else              /* LNA_Low */
/*MT6167*/       {  lna_path_loss = (l1d_rf2.is_fhc) ? (0) : ((int)(lnaptr->gain_offset_low-ofsptr->gain_offset));     }
/*MT6167*/
/*MT6167*/       bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*MT6167*/       real_gain = -lna_path_loss+REAL_GAIN( bit_no, agcptr->A, GC_B );
/*MT6167*/    #if IS_HEADROOM_DETECTION_SUPPORT || IS_INBAND_BLOCKER_DETECTION_SUPPORT
/*MT6167*/       if( ( ((l1d_rf.blk_flag)&(HRD_FOUND)) && (request_gain >= -4*PWRRES) ) || ( ((l1d_rf.blk_flag)&(IBB_FOUND)) && (request_gain >= 8*PWRRES) ) )
/*MT6167*/       {        /* CW12: LNA GAIN     |MIXER GAIN| IF GAIN */
/*MT6167*/          setting   = agcptr->setting | (0x1<<4) | (bit_no&0xF);
/*MT6167*/          real_gain -= MIXER_GAIN;
/*MT6167*/       }
/*MT6167*/       else
/*MT6167*/    #endif
/*MT6167*/       {  setting   = agcptr->setting | (bit_no&0xF);
/*MT6167*/       }
/*MT6167*/    }
/*MT6167*/
/*MT6167*/    *gain_setting = setting;
/*MT6167*/    return( real_gain );
/*MT6167*/ }
/*MT6167*/
   #if IS_W_CANCELLATION_SUPPORT
/*MT6167*/ unsigned short   L1D_RF_FindGainStep( unsigned long gain_setting, FrequencyBand rf_band  )
/*MT6167*/ {
/*MT6167*/    int lna_gain_setting;
/*MT6167*/    int tz_gain_setting;
/*MT6167*/    int if_gain_setting;
/*MT6167*/
/*MT6167*/    lna_gain_setting = (gain_setting>>5) & 0x7;
/*MT6167*/    tz_gain_setting  = (gain_setting>>4) & 0x1;
/*MT6167*/    if_gain_setting  = (gain_setting>>0) & 0xF; /* bit_no */
/*MT6167*/
/*MT6167*/    #if IS_HEADROOM_DETECTION_SUPPORT || IS_INBAND_BLOCKER_DETECTION_SUPPORT
/*MT6167*/    if( tz_gain_setting == 0x1 )               /*        ACI2   Gain Table      */
/*MT6167*/    {                                          /* ----------------------------- */
/*MT6167*/       if( lna_gain_setting == 0x4 )           /* gain| bit | tz_gain |lna_gain */
/*MT6167*/       {                                       /*  idx|  no | setting | setting */
/*MT6167*/          return ( if_gain_setting+8 );        /* ----+-----+---------+-------- */
/*MT6167*/       }                                       /*  16 |  8  |  (tz=1) |         */
/*MT6167*/       else if( lna_gain_setting == 0x1 )      /*  15 |  7  |         |  LNA    */
/*MT6167*/       {                                       /*  14 |  6  |  ACI2   |  High   */
/*MT6167*/          if( if_gain_setting>=5 )             /*  13 |  5  |         |  Gain   */
/*MT6167*/             return ( if_gain_setting-4+8);    /*  12 |  4  |  Gain   |         */
/*MT6167*/          else                                 /* ----+-----|         |-------- */
/*MT6167*/             return 0;                         /*  11 |  7  |  Table  |  LNA    */
/*MT6167*/       }                                       /*  10 |  6  |         |  Mid    */
/*MT6167*/       else                                    /*   9 |  5  |         |  Gain   */
/*MT6167*/       {                                       /* ----+-----+---------+-------- */
/*MT6167*/          return 0;                            /*   0 | 0~4 |       other       */
/*MT6167*/       }                                       /* ----------------------------- */
/*MT6167*/    }
/*MT6167*/    else
/*MT6167*/    #endif
/*MT6167*/    {                                          /*        Normal Gain Table      */
/*MT6167*/       if( lna_gain_setting == 0x4 )           /* ----------------------------- */
/*MT6167*/       {                                       /* gain| bit | tz_gain |lna_gain */
/*MT6167*/          return ( if_gain_setting   );        /*  idx|  no | setting | setting */
/*MT6167*/       }                                       /* ----+-----+---------+-------- */
/*MT6167*/       else if( lna_gain_setting == 0x1 )      /*   8 |  8  |  (tz=0) |         */
/*MT6167*/       {                                       /*   7 |  7  |         |  LNA    */
/*MT6167*/          if( if_gain_setting>=5 )             /*   6 |  6  |  Normal |  High   */
/*MT6167*/             return ( if_gain_setting-4 );     /*   5 |  5  |         |  Gain   */
/*MT6167*/          else                                 /*   4 |  4  |  Gain   |         */
/*MT6167*/             return 0;                         /* ----+-----|         |-------- */
/*MT6167*/       }                                       /*   3 |  7  |  Table  |  LNA    */
/*MT6167*/       else                                    /*   2 |  6  |         |  Mid    */
/*MT6167*/       {                                       /*   1 |  5  |         |  Gain   */
/*MT6167*/          return 0;                            /* ----+-----+------------------ */
/*MT6167*/       }                                       /*   0 | 0~4 |       other       */
/*MT6167*/    }                                          /* ----------------------------- */
/*MT6167*/ }
/*MT6167*/
   #endif
#endif

#if IS_RF_MT6166
/*MT6166*/
/*MT6166*/ #define  GAIN_STEP               3
/*MT6166*/ #define  PVOFSL                  34
/*MT6166*/ #define  PVOFSH                  34
/*MT6166*/ #define  NORMAL_GAIN_TABLE_FLAG  0
/*MT6166*/ #define  OBB_GAIN_TABLE_FLAG     1
/*MT6166*/ #define  IBB_GAIN_TABLE_FLAG     2
/*MT6166*/ #define  ACI_GAIN_TABLE_FLAG     3
/*MT6166*/ #define  MIXER_GAIN             (9*(PWRRES))
/*MT6166*/ #define  LNA_GAIN_LB            (5*(PWRRES))
/*MT6166*/ #define  LNA_GAIN_HB            (6*(PWRRES))
/*MT6166*/ #define  LNA_GAIN_LB_M          (3.5*(PWRRES))
/*MT6166*/ #define  LNA_GAIN_HB_M          (2.5*(PWRRES))
/*MT6166*/ #define  IF_GAIN                (6*(PWRRES))
/*MT6166*/ #define  IF_GAIN_OBB            (9*(PWRRES))
/*MT6166*/ #if IS_DUAL_TALK_RX_GAIN_TABLE_CO_BAND_SUPPORT
/*MT6166*/ #define  RF_GSM850_MAXGAIN_H    (( 56.5-PVOFSL )*(PWRRES))
/*MT6166*/ #define  RF_GSM850_MINGAIN_H    ((    1-PVOFSL )*(PWRRES))
/*MT6166*/ #define  RF_GSM850_MAXGAIN_L    (( 56.5-PVOFSL )*(PWRRES))
/*MT6166*/ #define  RF_GSM850_MINGAIN_L    ((  2.5-PVOFSL )*(PWRRES))
/*MT6166*/ #define  RF_GSM_MAXGAIN_H       (( 56.5-PVOFSL )*(PWRRES))
/*MT6166*/ #define  RF_GSM_MINGAIN_H       ((    1-PVOFSL )*(PWRRES))
/*MT6166*/ #define  RF_GSM_MAXGAIN_L       (( 56.5-PVOFSL )*(PWRRES))
/*MT6166*/ #define  RF_GSM_MINGAIN_L       ((  2.5-PVOFSL )*(PWRRES))
/*MT6166*/ #define  RF_DCS_MAXGAIN_H       (( 55.5-PVOFSH )*(PWRRES))
/*MT6166*/ #define  RF_DCS_MINGAIN_H       ((  0.5-PVOFSH )*(PWRRES))
/*MT6166*/ #define  RF_DCS_MAXGAIN_L       (( 55.5-PVOFSH )*(PWRRES))
/*MT6166*/ #define  RF_DCS_MINGAIN_L       ((  1.5-PVOFSH )*(PWRRES))
/*MT6166*/ #define  RF_PCS_MAXGAIN_H       (( 55.5-PVOFSH )*(PWRRES))
/*MT6166*/ #define  RF_PCS_MINGAIN_H       ((  0.5-PVOFSH )*(PWRRES))
/*MT6166*/ #define  RF_PCS_MAXGAIN_L       (( 55.5-PVOFSH )*(PWRRES))
/*MT6166*/ #define  RF_PCS_MINGAIN_L       ((  1.5-PVOFSH )*(PWRRES))
/*MT6166*/
/*MT6166*/ /* GSM850....................................................................*/
/*MT6166*/
/*MT6166*/ const  sL1DAGCDATA  AGC_TABLE_GSM850_H[4] =
/*MT6166*/ {  {  GBOUND(( 38.5-PVOFSL ),( 28  -PVOFSL ) ), GC_A( 2,( 38.5-PVOFSL ) ), BSI_CW(0x83, 0x50188) },
/*MT6166*/    {  GBOUND(( 28  -PVOFSL ),( 22  -PVOFSL ) ), GC_A( 2,( 28  -PVOFSL ) ), BSI_CW(0x83, 0x50088) },
/*MT6166*/    {  GBOUND(( 10  -PVOFSL ),(  1  -PVOFSL ) ), GC_A( 2,( 10  -PVOFSL ) ), BSI_CW(0x83, 0x50008) },
/*MT6166*/    {  GBOUND((  1  -PVOFSL ),(  1  -PVOFSL ) ), GC_A( 2,(  1  -PVOFSL ) ), BSI_CW(0x83, 0x50028) },
/*MT6166*/ };
/*MT6166*/ const  sL1DAGCDATA  AGC_TABLE_GSM850_L[4] =
/*MT6166*/ {  {  GBOUND(( 38.5-PVOFSL ),( 30  -PVOFSL ) ), GC_A( 2,( 38.5-PVOFSL ) ), BSI_CW(0x83, 0x50188) },
/*MT6166*/    {  GBOUND(( 30  -PVOFSL ),( 23.5-PVOFSL ) ), GC_A( 2,( 30  -PVOFSL ) ), BSI_CW(0x83, 0x50088) },
/*MT6166*/    {  GBOUND(( 11.5-PVOFSL ),(  2.5-PVOFSL ) ), GC_A( 2,( 11.5-PVOFSL ) ), BSI_CW(0x83, 0x50008) },
/*MT6166*/    {  GBOUND((  2.5-PVOFSL ),(  2.5-PVOFSL ) ), GC_A( 2,(  2.5-PVOFSL ) ), BSI_CW(0x83, 0x50028) },
/*MT6166*/ };
/*MT6166*/
/*MT6166*/ /* GSM900....................................................................*/
/*MT6166*/
/*MT6166*/ const  sL1DAGCDATA  AGC_TABLE_GSM900_H[4] =
/*MT6166*/ {  {  GBOUND(( 38.5-PVOFSL ),( 28  -PVOFSL ) ), GC_A( 2,( 38.5-PVOFSL ) ), BSI_CW(0x83, 0x50188) },
/*MT6166*/    {  GBOUND(( 28  -PVOFSL ),( 22  -PVOFSL ) ), GC_A( 2,( 28  -PVOFSL ) ), BSI_CW(0x83, 0x50088) },
/*MT6166*/    {  GBOUND(( 10  -PVOFSL ),(  1  -PVOFSL ) ), GC_A( 2,( 10  -PVOFSL ) ), BSI_CW(0x83, 0x50008) },
/*MT6166*/    {  GBOUND((  1  -PVOFSL ),(  1  -PVOFSL ) ), GC_A( 2,(  1  -PVOFSL ) ), BSI_CW(0x83, 0x50028) },
/*MT6166*/ };
/*MT6166*/ const  sL1DAGCDATA  AGC_TABLE_GSM900_L[4] =
/*MT6166*/ {  {  GBOUND(( 38.5-PVOFSL ),( 30  -PVOFSL ) ), GC_A( 2,( 38.5-PVOFSL ) ), BSI_CW(0x83, 0x50188) },
/*MT6166*/    {  GBOUND(( 30  -PVOFSL ),( 23.5-PVOFSL ) ), GC_A( 2,( 30  -PVOFSL ) ), BSI_CW(0x83, 0x50088) },
/*MT6166*/    {  GBOUND(( 11.5-PVOFSL ),(  2.5-PVOFSL ) ), GC_A( 2,( 11.5-PVOFSL ) ), BSI_CW(0x83, 0x50008) },
/*MT6166*/    {  GBOUND((  2.5-PVOFSL ),(  2.5-PVOFSL ) ), GC_A( 2,(  2.5-PVOFSL ) ), BSI_CW(0x83, 0x50028) },
/*MT6166*/ };
/*MT6166*/
/*MT6166*/ /* DCS1800...................................................................*/
/*MT6166*/
/*MT6166*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800_H[4] =
/*MT6166*/ {  {  GBOUND(( 37.5-PVOFSL ),( 27.5-PVOFSL ) ), GC_A( 2,( 37.5-PVOFSL ) ), BSI_CW(0x83, 0x50188) },
/*MT6166*/    {  GBOUND(( 27.5-PVOFSL ),( 21.5-PVOFSL ) ), GC_A( 2,( 27.5-PVOFSL ) ), BSI_CW(0x83, 0x50088) },
/*MT6166*/    {  GBOUND((  9.5-PVOFSL ),(  0.5-PVOFSL ) ), GC_A( 2,(  9.5-PVOFSL ) ), BSI_CW(0x83, 0x50008) },
/*MT6166*/    {  GBOUND((  0.5-PVOFSL ),(  0.5-PVOFSL ) ), GC_A( 2,(  0.5-PVOFSL ) ), BSI_CW(0x83, 0x50028) },
/*MT6166*/ };
/*MT6166*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800_L[4] =
/*MT6166*/ {  {  GBOUND(( 37.5-PVOFSL ),( 29  -PVOFSL ) ), GC_A( 2,( 37.5-PVOFSL ) ), BSI_CW(0x83, 0x50188) },
/*MT6166*/    {  GBOUND(( 29  -PVOFSL ),( 22.5-PVOFSL ) ), GC_A( 2,( 29  -PVOFSL ) ), BSI_CW(0x83, 0x50088) },
/*MT6166*/    {  GBOUND(( 10.5-PVOFSL ),(  1.5-PVOFSL ) ), GC_A( 2,( 10.5-PVOFSL ) ), BSI_CW(0x83, 0x50008) },
/*MT6166*/    {  GBOUND((  1.5-PVOFSL ),(  1.5-PVOFSL ) ), GC_A( 2,(  1.5-PVOFSL ) ), BSI_CW(0x83, 0x50028) },
/*MT6166*/ };
/*MT6166*/
/*MT6166*/ /* PCS1900...................................................................*/
/*MT6166*/
/*MT6166*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900_H[4] =
/*MT6166*/ {  {  GBOUND(( 37.5-PVOFSL ),( 27.5-PVOFSL ) ), GC_A( 2,( 37.5-PVOFSL ) ), BSI_CW(0x83, 0x50188) },
/*MT6166*/    {  GBOUND(( 27.5-PVOFSL ),( 21.5-PVOFSL ) ), GC_A( 2,( 27.5-PVOFSL ) ), BSI_CW(0x83, 0x50088) },
/*MT6166*/    {  GBOUND((  9.5-PVOFSL ),(  0.5-PVOFSL ) ), GC_A( 2,(  9.5-PVOFSL ) ), BSI_CW(0x83, 0x50008) },
/*MT6166*/    {  GBOUND((  0.5-PVOFSL ),(  0.5-PVOFSL ) ), GC_A( 2,(  0.5-PVOFSL ) ), BSI_CW(0x83, 0x50028) },
/*MT6166*/ };
/*MT6166*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900_L[4] =
/*MT6166*/ {  {  GBOUND(( 37.5-PVOFSL ),( 29  -PVOFSL ) ), GC_A( 2,( 37.5-PVOFSL ) ), BSI_CW(0x83, 0x50188) },
/*MT6166*/    {  GBOUND(( 29  -PVOFSL ),( 22.5-PVOFSL ) ), GC_A( 2,( 29  -PVOFSL ) ), BSI_CW(0x83, 0x50088) },
/*MT6166*/    {  GBOUND(( 10.5-PVOFSL ),(  1.5-PVOFSL ) ), GC_A( 2,( 10.5-PVOFSL ) ), BSI_CW(0x83, 0x50008) },
/*MT6166*/    {  GBOUND((  1.5-PVOFSL ),(  1.5-PVOFSL ) ), GC_A( 2,(  1.5-PVOFSL ) ), BSI_CW(0x83, 0x50028) },
/*MT6166*/ };
/*MT6166*/
/*MT6166*/ /*...........................................................................*/
/*MT6166*/
/*MT6166*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE_H[] =
/*MT6166*/ {  {                     0,                    0        }, /*#FrequencyBand400  */
/*MT6166*/    { (int)RF_GSM850_MAXGAIN_H, (int)RF_GSM850_MINGAIN_H }, /* FrequencyBand850  */
/*MT6166*/    { (int)RF_GSM_MAXGAIN_H,    (int)RF_GSM_MINGAIN_H    }, /* FrequencyBand900  */
/*MT6166*/    { (int)RF_DCS_MAXGAIN_H,    (int)RF_DCS_MINGAIN_H    }, /* FrequencyBand1800 */
/*MT6166*/    { (int)RF_PCS_MAXGAIN_H,    (int)RF_PCS_MINGAIN_H    }, /* FrequencyBand1900 */
/*MT6166*/ };
/*MT6166*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE_L[] =
/*MT6166*/ {  {                     0,                    0        }, /*#FrequencyBand400  */
/*MT6166*/    { (int)RF_GSM850_MAXGAIN_L, (int)RF_GSM850_MINGAIN_L }, /* FrequencyBand850  */
/*MT6166*/    { (int)RF_GSM_MAXGAIN_L,    (int)RF_GSM_MINGAIN_L    }, /* FrequencyBand900  */
/*MT6166*/    { (int)RF_DCS_MAXGAIN_L,    (int)RF_DCS_MINGAIN_L    }, /* FrequencyBand1800 */
/*MT6166*/    { (int)RF_PCS_MAXGAIN_L,    (int)RF_PCS_MINGAIN_L    }, /* FrequencyBand1900 */
/*MT6166*/ };
/*MT6166*/ const  sL1DGAINRANGE * GAIN_RANGE_TABLE[] =
/*MT6166*/ {  GAIN_RANGE_TABLE_L,
/*MT6166*/    GAIN_RANGE_TABLE_H,
/*MT6166*/ };
/*MT6166*/
/*MT6166*/ const  sL1DAGCDATA* AGC_TABLE_H[] =
/*MT6166*/ {  0,                                              /*#FrequencyBand400  */
/*MT6166*/	  AGC_TABLE_GSM850_H,                             /* FrequencyBand850  */
/*MT6166*/	  AGC_TABLE_GSM900_H,                             /* FrequencyBand900  */
/*MT6166*/	  AGC_TABLE_DCS1800_H,                            /* FrequencyBand1800 */
/*MT6166*/	  AGC_TABLE_PCS1900_H,                            /* FrequencyBand1900 */
/*MT6166*/ };
/*MT6166*/ const  sL1DAGCDATA* AGC_TABLE_L[] =
/*MT6166*/ {  0,                                              /*#FrequencyBand400  */
/*MT6166*/	  AGC_TABLE_GSM850_L,                             /* FrequencyBand850  */
/*MT6166*/	  AGC_TABLE_GSM900_L,                             /* FrequencyBand900  */
/*MT6166*/	  AGC_TABLE_DCS1800_L,                            /* FrequencyBand1800 */
/*MT6166*/	  AGC_TABLE_PCS1900_L,                            /* FrequencyBand1900 */
/*MT6166*/ };
/*MT6166*/ const  sL1DAGCDATA **const  AGC_TABLE[] =
/*MT6166*/ {  AGC_TABLE_L,
/*MT6166*/    AGC_TABLE_H,
/*MT6166*/ };
/*MT6166*/ #else
/*MT6166*/ #define  RF_GSM850_MAXGAIN      (( 56.5-PVOFSL )*(PWRRES))
/*MT6166*/ #define  RF_GSM850_MINGAIN      ((  2.5-PVOFSL )*(PWRRES))
/*MT6166*/ #define  RF_GSM_MAXGAIN         (( 56.5-PVOFSL )*(PWRRES))
/*MT6166*/ #define  RF_GSM_MINGAIN         ((  2.5-PVOFSL )*(PWRRES))
/*MT6166*/ #define  RF_DCS_MAXGAIN         (( 55.5-PVOFSH )*(PWRRES))
/*MT6166*/ #define  RF_DCS_MINGAIN         ((  1.5-PVOFSH )*(PWRRES))
/*MT6166*/ #define  RF_PCS_MAXGAIN         (( 55.5-PVOFSH )*(PWRRES))
/*MT6166*/ #define  RF_PCS_MINGAIN         ((  1.5-PVOFSH )*(PWRRES))
/*MT6166*/
/*MT6166*/ /* GSM850....................................................................*/
/*MT6166*/
/*MT6166*/ const  sL1DAGCDATA  AGC_TABLE_GSM850[4] =
/*MT6166*/ {  {  GBOUND(( 38.5-PVOFSL ),( 30  -PVOFSL ) ), GC_A( 2,( 38.5-PVOFSL ) ), BSI_CW(0x83, 0x50188) },
/*MT6166*/    {  GBOUND(( 30  -PVOFSL ),( 23.5-PVOFSL ) ), GC_A( 2,( 30  -PVOFSL ) ), BSI_CW(0x83, 0x50088) },
/*MT6166*/    {  GBOUND(( 11.5-PVOFSL ),(  2.5-PVOFSL ) ), GC_A( 2,( 11.5-PVOFSL ) ), BSI_CW(0x83, 0x50008) },
/*MT6166*/    {  GBOUND((  2.5-PVOFSL ),(  2.5-PVOFSL ) ), GC_A( 2,(  2.5-PVOFSL ) ), BSI_CW(0x83, 0x50028) },
/*MT6166*/ };
/*MT6166*/
/*MT6166*/ /* GSM900....................................................................*/
/*MT6166*/
/*MT6166*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[4] =
/*MT6166*/ {  {  GBOUND(( 38.5-PVOFSL ),( 30  -PVOFSL ) ), GC_A( 2,( 38.5-PVOFSL ) ), BSI_CW(0x83, 0x50188) },
/*MT6166*/    {  GBOUND(( 30  -PVOFSL ),( 23.5-PVOFSL ) ), GC_A( 2,( 30  -PVOFSL ) ), BSI_CW(0x83, 0x50088) },
/*MT6166*/    {  GBOUND(( 11.5-PVOFSL ),(  2.5-PVOFSL ) ), GC_A( 2,( 11.5-PVOFSL ) ), BSI_CW(0x83, 0x50008) },
/*MT6166*/    {  GBOUND((  2.5-PVOFSL ),(  2.5-PVOFSL ) ), GC_A( 2,(  2.5-PVOFSL ) ), BSI_CW(0x83, 0x50028) },
/*MT6166*/ };
/*MT6166*/
/*MT6166*/ /* DCS1800...................................................................*/
/*MT6166*/
/*MT6166*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[4] =
/*MT6166*/ {  {  GBOUND(( 37.5-PVOFSL ),( 29  -PVOFSL ) ), GC_A( 2,( 37.5-PVOFSL ) ), BSI_CW(0x83, 0x50188) },
/*MT6166*/    {  GBOUND(( 29  -PVOFSL ),( 22.5-PVOFSL ) ), GC_A( 2,( 29  -PVOFSL ) ), BSI_CW(0x83, 0x50088) },
/*MT6166*/    {  GBOUND(( 10.5-PVOFSL ),(  1.5-PVOFSL ) ), GC_A( 2,( 10.5-PVOFSL ) ), BSI_CW(0x83, 0x50008) },
/*MT6166*/    {  GBOUND((  1.5-PVOFSL ),(  1.5-PVOFSL ) ), GC_A( 2,(  1.5-PVOFSL ) ), BSI_CW(0x83, 0x50028) },
/*MT6166*/ };
/*MT6166*/
/*MT6166*/ /* PCS1900...................................................................*/
/*MT6166*/
/*MT6166*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[4] =
/*MT6166*/ {  {  GBOUND(( 37.5-PVOFSL ),( 29  -PVOFSL ) ), GC_A( 2,( 37.5-PVOFSL ) ), BSI_CW(0x83, 0x50188) },
/*MT6166*/    {  GBOUND(( 29  -PVOFSL ),( 22.5-PVOFSL ) ), GC_A( 2,( 29  -PVOFSL ) ), BSI_CW(0x83, 0x50088) },
/*MT6166*/    {  GBOUND(( 10.5-PVOFSL ),(  1.5-PVOFSL ) ), GC_A( 2,( 10.5-PVOFSL ) ), BSI_CW(0x83, 0x50008) },
/*MT6166*/    {  GBOUND((  1.5-PVOFSL ),(  1.5-PVOFSL ) ), GC_A( 2,(  1.5-PVOFSL ) ), BSI_CW(0x83, 0x50028) },
/*MT6166*/ };
/*MT6166*/
/*MT6166*/ /*...........................................................................*/
/*MT6166*/
/*MT6166*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*MT6166*/ {  {                   0,                      0    }, /*#FrequencyBand400  */
/*MT6166*/    { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN }, /* FrequencyBand850  */
/*MT6166*/    { (int)RF_GSM_MAXGAIN,    (int)RF_GSM_MINGAIN    }, /* FrequencyBand900  */
/*MT6166*/    { (int)RF_DCS_MAXGAIN,    (int)RF_DCS_MINGAIN    }, /* FrequencyBand1800 */
/*MT6166*/    { (int)RF_PCS_MAXGAIN,    (int)RF_PCS_MINGAIN    }, /* FrequencyBand1900 */
/*MT6166*/ };
/*MT6166*/
/*MT6166*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*MT6166*/ {  0,                                              /*#FrequencyBand400  */
/*MT6166*/    AGC_TABLE_GSM850,                               /* FrequencyBand850  */
/*MT6166*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*MT6166*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*MT6166*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*MT6166*/ };
/*MT6166*/ #endif
/*MT6166*/
/*MT6166*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*MT6166*/
/*MT6166*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*MT6166*/ {  int   max_gain, min_gain, real_gain, band_mode, gain_table;
/*MT6166*/    const int*    d32ptr;
/*MT6166*/    const sL1DAGCDATA*  agcptr;
/*MT6166*/ #if IS_MULTI_LNA_MODE_CALIBRATION_SUPPORT
/*MT6166*/    sLNAGAINOFFSET*     lnaptr;
/*MT6166*/ #endif
/*MT6166*/    sAGCGAINOFFSET*     ofsptr;
/*MT6166*/    long  setting;
/*MT6166*/    int   bit_no, lna_path_loss;
/*MT6166*/    int   thres_IBB, thres_HRD, thres_OBB, dividing_OBB1, dividing_OBB2, LNA_GAIN, LNA_GAIN_M;
/*MT6166*/ #if IS_DUAL_TALK_RX_GAIN_TABLE_CO_BAND_SUPPORT
/*MT6166*/    unsigned char  coband_gaintable_en;
/*MT6166*/    unsigned short coband_en_bitmap;
/*MT6166*/ #endif
/*MT6166*/
/*MT6166*/    band_mode      = (rf_band < FrequencyBand1800) ? 0 /* LowBand */ : 1 /* HighBand */;
/*MT6166*/
/*MT6166*/    thres_IBB      = band_mode ?            28 :              36;   //( 37.5-PVOFSL )*PWRRES : ( 38.5-PVOFSL )*PWRRES
/*MT6166*/    thres_HRD      = band_mode ?            76 :              84;   //( 43.5-PVOFSL )*PWRRES : ( 44.5-PVOFSL )*PWRRES
/*MT6166*/    thres_OBB      = band_mode ?           -40 :             -32;   //(   29-PVOFSL )*PWRRES : (   30-PVOFSL )*PWRRES
/*MT6166*/    dividing_OBB1  = band_mode ?           172 :             180;   //( 55.5-PVOFSL )*PWRRES : ( 56.5-PVOFSL )*PWRRES
/*MT6166*/    dividing_OBB2  = band_mode ?            28 :              36;   //( 37.5-PVOFSL )*PWRRES : ( 38.5-PVOFSL )*PWRRES
/*MT6166*/    LNA_GAIN       = band_mode ?   LNA_GAIN_HB :     LNA_GAIN_LB;
/*MT6166*/    LNA_GAIN_M     = band_mode ? LNA_GAIN_HB_M :   LNA_GAIN_LB_M;
/*MT6166*/
/*MT6166*/    /* evaluate the range of available gain */
/*MT6166*/ #if IS_DUAL_TALK_RX_GAIN_TABLE_CO_BAND_SUPPORT
/*MT6166*/    coband_en_bitmap    = L1D_Rx_Gain_Table_CoBand_Enable();
/*MT6166*/    coband_gaintable_en = (coband_en_bitmap & (0x1<<(rf_band-1))) ? 1 : 0;
/*MT6166*/    d32ptr   = (int*)(GAIN_RANGE_TABLE[coband_gaintable_en]+rf_band);
/*MT6166*/ #else
/*MT6166*/    d32ptr   = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*MT6166*/ #endif
/*MT6166*/    max_gain = *d32ptr++;
/*MT6166*/    min_gain = *d32ptr;
/*MT6166*/
/*MT6166*/    /* clipping the request gain to the avialable gain */
/*MT6166*/    if( request_gain>=max_gain )
/*MT6166*/    {  request_gain = max_gain;
/*MT6166*/    }
/*MT6166*/    else if( request_gain<=min_gain )
/*MT6166*/    {  request_gain = min_gain;
/*MT6166*/    }
/*MT6166*/
/*MT6166*/ #if IS_MULTI_LNA_MODE_CALIBRATION_SUPPORT
/*MT6166*/    /* choose the LNA path loss */
/*MT6166*/    lnaptr = LNA_PATHLOSS_TABLE[rf_band];
/*MT6166*/ #endif
/*MT6166*/    /* get the arfcn section */
/*MT6166*/    ofsptr = AGC_PATHLOSS_TABLE[rf_band];
/*MT6166*/    while( ofsptr->max_arfcn>=0 )
/*MT6166*/    {  if( arfcn <= ofsptr->max_arfcn )
/*MT6166*/       {  break;  }
/*MT6166*/       ofsptr++;
/*MT6166*/ #if IS_MULTI_LNA_MODE_CALIBRATION_SUPPORT
/*MT6166*/       lnaptr++;
/*MT6166*/ #endif
/*MT6166*/    }
/*MT6166*/
/*MT6166*/    /* evaluate the real gain setting */
/*MT6166*/ #if IS_DUAL_TALK_RX_GAIN_TABLE_CO_BAND_SUPPORT
/*MT6166*/    agcptr = *(AGC_TABLE[coband_gaintable_en]+rf_band);
/*MT6166*/ #else
/*MT6166*/    agcptr = AGC_TABLE[rf_band];
/*MT6166*/ #endif
/*MT6166*/    while( request_gain < agcptr->pos_gain )
/*MT6166*/    {  agcptr++;
/*MT6166*/    }
/*MT6166*/    {
/*MT6166*/ #if IS_MULTI_LNA_MODE_CALIBRATION_SUPPORT
/*MT6166*/       int idx;
/*MT6166*/       idx = (int)(((agcptr->setting)>>7)&0x7);
/*MT6166*/       if( idx==3 )      /* LNA_High */
/*MT6166*/       {
/*MT6166*/    #if IS_OUTBAND_BLOCKER_DETECTION_SUPPORT
/*MT6166*/          if( ( (l1d_rf.blk_flag & LB_OBB_FOUND) && (band_mode == 0) && request_gain>= thres_OBB ) ||
/*MT6166*/              ( (l1d_rf.blk_flag & HB_OBB_FOUND) && (band_mode == 1) && request_gain>= thres_OBB )  )
/*MT6166*/          {   lna_path_loss = (l1d_rf2.is_fhc) ? (0) : ((int)(lnaptr->gain_offset_middle-ofsptr->gain_offset));   }
/*MT6166*/          else
/*MT6166*/    #endif
/*MT6166*/          {   lna_path_loss = 0;   }
/*MT6166*/       }
/*MT6166*/       else if( idx==1 ) /* LNA_Middle */
/*MT6166*/       {  lna_path_loss = (l1d_rf2.is_fhc) ? (0) : ((int)(lnaptr->gain_offset_middle-ofsptr->gain_offset));  }
/*MT6166*/       else              /* LNA_Low */
/*MT6166*/       {  lna_path_loss = (l1d_rf2.is_fhc) ? (0) : ((int)(lnaptr->gain_offset_low-ofsptr->gain_offset));     }
/*MT6166*/ #else
/*MT6166*/       lna_path_loss = 0;
/*MT6166*/ #endif
/*MT6166*/
/*MT6166*/       bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*MT6166*/       real_gain = -lna_path_loss+REAL_GAIN( bit_no, agcptr->A, GC_B );
/*MT6166*/
/*MT6166*/       /* Evaluate the real gain setting. */
/*MT6166*/       if( 0 )
/*MT6166*/       { /* do nothing */ }
/*MT6166*/ #if IS_OUTBAND_BLOCKER_DETECTION_SUPPORT
/*MT6166*/       else if( ( (l1d_rf.blk_flag & LB_OBB_FOUND) && (band_mode == 0) && request_gain>= thres_OBB ) ||
/*MT6166*/                ( (l1d_rf.blk_flag & HB_OBB_FOUND) && (band_mode == 1) && request_gain>= thres_OBB )  )
/*MT6166*/       {
/*MT6166*/          gain_table = OBB_GAIN_TABLE_FLAG;
/*MT6166*/          if( request_gain >= dividing_OBB1 )
/*MT6166*/          {
/*MT6166*/             agcptr++; // decrease LNA gain
/*MT6166*/                        /* CW131: IF GAIN  | LNA GAIN        |MIXER GAIN */
/*MT6166*/             setting    = (bit_no&0xF)<<10 | agcptr->setting | (0x0<<5);
/*MT6166*/             real_gain -= LNA_GAIN;
/*MT6166*/          }
/*MT6166*/          else if( request_gain >= dividing_OBB2 )
/*MT6166*/          {
/*MT6166*/             agcptr++; // decrease LNA gain
/*MT6166*/                        /* CW131: IF GAIN       | LNA GAIN        |MIXER GAIN */
/*MT6166*/             setting    = ( (bit_no+3)&0xF)<<10 | agcptr->setting | (0x0<<5);
/*MT6166*/             real_gain -= (LNA_GAIN - IF_GAIN_OBB);
/*MT6166*/          }
/*MT6166*/          else
/*MT6166*/          {             /* CW131: IF GAIN  | LNA GAIN        |MIXER GAIN */
/*MT6166*/             setting    = (bit_no&0xF)<<10 | agcptr->setting | (0x0<<5);
/*MT6166*/             real_gain += LNA_GAIN_M;
/*MT6166*/          }
/*MT6166*/       }
/*MT6166*/ #endif
/*MT6166*/ #if IS_INBAND_BLOCKER_DETECTION_SUPPORT
/*MT6166*/       else if( (l1d_rf.blk_flag & IBB_FOUND) && (request_gain>= thres_IBB ) )
/*MT6166*/       {
/*MT6166*/          gain_table = IBB_GAIN_TABLE_FLAG;
/*MT6166*/                     /* CW131: IF GAIN     | LNA GAIN             |MIXER GAIN */
/*MT6166*/          setting    = (bit_no&0xF)<<10 | agcptr->setting | (0x1<<5);
/*MT6166*/          real_gain -= MIXER_GAIN;
/*MT6166*/       }
/*MT6166*/ #endif
/*MT6166*/ #if IS_HEADROOM_DETECTION_SUPPORT
/*MT6166*/       else if( ( l1d_rf.blk_flag & HRD_FOUND ) && (request_gain >= thres_HRD ) )
/*MT6166*/       {
/*MT6166*/          gain_table = ACI_GAIN_TABLE_FLAG;
/*MT6166*/                     /* CW131: IF GAIN       | LNA GAIN        |MIXER GAIN */
/*MT6166*/          setting    = ( (bit_no-2)&0xF)<<10 | agcptr->setting | (0x0<<5);
/*MT6166*/          real_gain -= IF_GAIN;
/*MT6166*/       }
/*MT6166*/ #endif
/*MT6166*/       else
/*MT6166*/       {
/*MT6166*/          gain_table = NORMAL_GAIN_TABLE_FLAG;
/*MT6166*/          setting    = (bit_no&0xF)<<10 | agcptr->setting;
/*MT6166*/       }
/*MT6166*/    }
/*MT6166*/
/*MT6166*/    *gain_setting = ((gain_table&0xFF)<<28) | setting;
/*MT6166*/    return( real_gain );
/*MT6166*/ }
/*MT6166*/
   #if IS_W_CANCELLATION_SUPPORT
/*MT6166*/ unsigned short   L1D_RF_FindGainStep( unsigned long gain_setting, FrequencyBand rf_band  )
/*MT6166*/ {
/*MT6166*/    int lna_gain_setting;
/*MT6166*/    int if_gain_setting;
/*MT6166*/    int band_mode, gain_step, gain_table;
/*MT6166*/    band_mode    = (rf_band < FrequencyBand1800) ? 0 /* LowBand */ : 1 /* HighBand */;
/*MT6166*/
/*MT6166*/    gain_table       = (unsigned int)(gain_setting&0xFF0000000L)>>28;
/*MT6166*/    lna_gain_setting = (gain_setting>>7 ) & 0x7;
/*MT6166*/    if_gain_setting  = (gain_setting>>10) & 0xF; /* bit_no */
/*MT6166*/
/*MT6166*/    if( ( gain_table == IBB_GAIN_TABLE_FLAG ) || ( gain_table == OBB_GAIN_TABLE_FLAG ) )
/*MT6166*/    {
/*MT6166*/       gain_step = 0;
/*MT6166*/    }
/*MT6166*/    else
/*MT6166*/    {
/*MT6166*/       if( lna_gain_setting == 0x3 )
/*MT6166*/       {
/*MT6166*/          if( if_gain_setting== 0x3)
/*MT6166*/             gain_step = 5;
/*MT6166*/          else if( if_gain_setting== 0x6)
/*MT6166*/             gain_step = 6;
/*MT6166*/          else
/*MT6166*/             gain_step = ROUNDINT(if_gain_setting/2.0);
/*MT6166*/       }
/*MT6166*/       else
/*MT6166*/       {
/*MT6166*/          gain_step = 0;
/*MT6166*/       }
/*MT6166*/    }
/*MT6166*/
/*MT6166*/    /* LB step: 0,2,4,6,8 */
/*MT6166*/    /* HB step: 1,3,5,7,9 */
/*MT6166*/    gain_step = gain_step * 2 + band_mode;
/*MT6166*/
/*MT6166*/    return gain_step;
/*MT6166*/ }
/*MT6166*/
   #endif
#endif

#if IS_RF_MT6165
/*MT6165*/
/*MT6165*/ #define  MAX_GAIN_STEP           7
/*MT6165*/ #define  PVOFSL                  34
/*MT6165*/ #define  PVOFSH                  34
/*MT6165*/ #define  NORMAL_GAIN_TABLE_FLAG  0
/*MT6165*/ #define  OBB_GAIN_TABLE_FLAG     1
/*MT6165*/ #define  IBB_GAIN_TABLE_FLAG     2
/*MT6165*/ #define  ACI_GAIN_TABLE_FLAG     3
/*MT6165*/ #define  RF_GSM850_MAXGAIN      ( 176)
/*MT6165*/ #define  RF_GSM850_MINGAIN      (-168)
/*MT6165*/ #define  RF_GSM_MAXGAIN         ( 176)
/*MT6165*/ #define  RF_GSM_MINGAIN         (-168)
/*MT6165*/ #define  RF_DCS_MAXGAIN         ( 176)
/*MT6165*/ #define  RF_DCS_MINGAIN         (-168)
/*MT6165*/ #define  RF_PCS_MAXGAIN         ( 176)
/*MT6165*/ #define  RF_PCS_MINGAIN         (-168)
/*MT6165*/
/*MT6165*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*MT6165*/ {  {                   0,                      0    }, /*#FrequencyBand400  */
/*MT6165*/    { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN }, /* FrequencyBand850  */
/*MT6165*/    { (int)RF_GSM_MAXGAIN,    (int)RF_GSM_MINGAIN    }, /* FrequencyBand900  */
/*MT6165*/    { (int)RF_DCS_MAXGAIN,    (int)RF_DCS_MINGAIN    }, /* FrequencyBand1800 */
/*MT6165*/    { (int)RF_PCS_MAXGAIN,    (int)RF_PCS_MINGAIN    }, /* FrequencyBand1900 */
/*MT6165*/ };
/*MT6165*/ /* { RFLNA gain step, RFIF gain step } */
/*MT6165*/ const  unsigned char  NORMAL_GAIN_TABLE[][2] =
/*MT6165*/ {  { 3, 5 }, /* gain_step = 0 */
/*MT6165*/    { 2, 4 }, /* gain_step = 1 */
/*MT6165*/    { 2, 2 }, /* gain_step = 2 */
/*MT6165*/    { 2, 0 }, /* gain_step = 3 */
/*MT6165*/    { 0, 4 }, /* gain_step = 4 */
/*MT6165*/    { 0, 2 }, /* gain_step = 5 */
/*MT6165*/    { 0, 0 }, /* gain_step = 6 */
/*MT6165*/ };
/*MT6165*/ const  unsigned char  RXLNA_GAIN[2][4] =
/*MT6165*/ {  /*  0    1    2    3    :RFLNA gain_step */
/*MT6165*/    { 0x4, 0x5, 0x6, 0x7 }, /* LowBand    */ /*3bits*/
/*MT6165*/    { 0x2, 0x5, 0x6, 0x7 }, /* HighBand   */ /*3bits*/
/*MT6165*/ };
/*MT6165*/
/*MT6165*/ const  unsigned char  RXIF_GAIN[2][6] =
/*MT6165*/ {  /*  0    1    2    3    4,   5    :RFIF gain_step */
/*MT6165*/    { 0x1, 0x2, 0x3, 0x4, 0x5, 0x6 }, /* LowBand    */ /*3bits*/
/*MT6165*/    { 0x1, 0x2, 0x3, 0x4, 0x5, 0x6 }, /* HighBand   */ /*3bits*/
/*MT6165*/ };
/*MT6165*/
/*MT6165*/ /* GAIN_TABLE: voltage gain (total gain) */
/*MT6165*/ const  signed short  GAIN_TABLE_NORMAL[2][MAX_GAIN_STEP] =
/*MT6165*/ {  /*  0    1   2   3   4   5   6  :gain_step    */
/*MT6165*/    { 176, 128, 80, 32, -72, -120, -168 }, /* LowBand  */
/*MT6165*/    { 176, 132, 84, 36, -72, -120, -168 }, /* HighBand */
/*MT6165*/ };
/*MT6165*/ const  signed short  GAIN_TABLE_OBB[2][MAX_GAIN_STEP] =
/*MT6165*/ {  /*  0    1   2   3   4   5   6  :gain_step    */
/*MT6165*/    { 144, 96, 48,  -0, -72, -120, -168  }, /* LowBand  */
/*MT6165*/    { 124, 72, 24, -24, -72, -120, -168 }, /* HighBand */
/*MT6165*/ };
/*MT6165*/ const  signed short  GAIN_TABLE_IBB[2][MAX_GAIN_STEP] =
/*MT6165*/ {  /*  0    1   2   3   4   5   6  :gain_step    */
/*MT6165*/    { 152, 88, 40,  -8, -72, -120, -168 }, /* LowBand  */
/*MT6165*/    { 156, 92, 44,  -4, -72, -120, -168 }, /* HighBand */
/*MT6165*/ };
/*MT6165*/ const  signed short  GAIN_TABLE_HEADROOM[2][MAX_GAIN_STEP] =
/*MT6165*/ {  /*  0   1   2   3   4   5   6  :gain_step    */
/*MT6165*/    { 128, 80, 32, 32, -72, -120, -168 }, /* LowBand  */
/*MT6165*/    { 128, 84, 36, 36, -72, -120, -168 }, /* HighBand */
/*MT6165*/ };
/*MT6165*/ const  unsigned short  RXIF_BP_EN_NORMAL[2][MAX_GAIN_STEP] =
/*MT6165*/ {  /* 0  1  2  3  4  5  6    :gain_step    */
/*MT6165*/    {  0, 0, 1, 1, 1, 1, 1 }, /* LowBand  */
/*MT6165*/    {  0, 0, 1, 1, 1, 1, 1 }, /* HighBand */
/*MT6165*/ };
/*MT6165*/ const  signed short  RXIF_BP_EN_HEADROOM[2][MAX_GAIN_STEP] =
/*MT6165*/ {  /* 0  1  2  3  4  5  6    :gain_step    */
/*MT6165*/    {  1, 1, 1, 1, 1, 1, 1 }, /* LowBand  */
/*MT6165*/    {  1, 1, 1, 1, 1, 1, 1 }, /* HighBand */
/*MT6165*/ };
/*MT6165*/
/*MT6165*/
/*MT6165*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*MT6165*/
/*MT6165*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*MT6165*/ {  int   max_gain, min_gain, real_gain, band_mode, gain_table;
/*MT6165*/    const int*    d32ptr;
/*MT6165*/ #if IS_MULTI_LNA_MODE_CALIBRATION_SUPPORT
/*MT6165*/    sLNAGAINOFFSET*     lnaptr;
/*MT6165*/ #endif
/*MT6165*/    sAGCGAINOFFSET*     ofsptr;
/*MT6165*/    long  setting;
/*MT6165*/    int   rx_gain_step, rx_lna_setting, rx_if_setting, lna_path_loss;
/*MT6165*/    int   thres_OBB, thres_IBB, thres_HRD;
/*MT6165*/
/*MT6165*/    band_mode      = (rf_band < FrequencyBand1800) ? 0 /* LowBand */ : 1 /* HighBand */;
/*MT6165*/
/*MT6165*/    thres_OBB      = band_mode ?            32 :              36;   //( 38-PVOFSL )*PWRRES : ( 38.5-PVOFSH )*PWRRES
/*MT6165*/    thres_IBB      = band_mode ?            32 :              36;   //( 38-PVOFSL )*PWRRES : ( 38.5-PVOFSH )*PWRRES
/*MT6165*/    thres_HRD      = band_mode ?            80 :              84;   //( 44-PVOFSL )*PWRRES : ( 44.5-PVOFSH )*PWRRES
/*MT6165*/
/*MT6165*/    /* evaluate the range of available gain */
/*MT6165*/    d32ptr   = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*MT6165*/    max_gain = *d32ptr++;
/*MT6165*/    min_gain = *d32ptr;
/*MT6165*/
/*MT6165*/    /* clipping the request gain to the avialable gain */
/*MT6165*/    if( request_gain>=max_gain )
/*MT6165*/    {  request_gain = max_gain;
/*MT6165*/    }
/*MT6165*/    else if( request_gain<=min_gain )
/*MT6165*/    {  request_gain = min_gain;
/*MT6165*/    }
/*MT6165*/
/*MT6165*/    for ( rx_gain_step = 0; rx_gain_step < MAX_GAIN_STEP; rx_gain_step++ )
/*MT6165*/    {
/*MT6165*/       if( request_gain >= GAIN_TABLE_NORMAL[band_mode][rx_gain_step] )
/*MT6165*/       {  break;  }
/*MT6165*/    }
/*MT6165*/    if( rx_gain_step >= MAX_GAIN_STEP )
/*MT6165*/    {  rx_gain_step = (MAX_GAIN_STEP-1);
/*MT6165*/    }
/*MT6165*/
/*MT6165*/    rx_lna_setting = RXLNA_GAIN[band_mode][(NORMAL_GAIN_TABLE[rx_gain_step][0])];
/*MT6165*/    rx_if_setting  = RXIF_GAIN[band_mode][(NORMAL_GAIN_TABLE[rx_gain_step][1])];
/*MT6165*/
/*MT6165*/ #if IS_MULTI_LNA_MODE_CALIBRATION_SUPPORT
/*MT6165*/       /* choose the LNA path loss */
/*MT6165*/       lnaptr = LNA_PATHLOSS_TABLE[rf_band];
/*MT6165*/ #endif
/*MT6165*/       /* get the arfcn section */
/*MT6165*/       ofsptr = AGC_PATHLOSS_TABLE[rf_band];
/*MT6165*/       while( ofsptr->max_arfcn>=0 )
/*MT6165*/       {  if( arfcn <= ofsptr->max_arfcn )
/*MT6165*/          {  break;  }
/*MT6165*/          ofsptr++;
/*MT6165*/ #if IS_MULTI_LNA_MODE_CALIBRATION_SUPPORT
/*MT6165*/          lnaptr++;
/*MT6165*/ #endif
/*MT6165*/       }
/*MT6165*/
/*MT6165*/       /* Evaluate the real gain setting. */
/*MT6165*/    {
/*MT6165*/ #if IS_MULTI_LNA_MODE_CALIBRATION_SUPPORT
/*MT6165*/       if( rx_lna_setting==0x7 )      /* LNA_High */
/*MT6165*/       {
/*MT6165*/    #if IS_OUTBAND_BLOCKER_DETECTION_SUPPORT
/*MT6165*/          if( ( (l1d_rf.blk_flag & LB_OBB_FOUND) && (band_mode == 0) && request_gain>= thres_OBB ) ||
/*MT6165*/              ( (l1d_rf.blk_flag & HB_OBB_FOUND) && (band_mode == 1) && request_gain>= thres_OBB )  )
/*MT6165*/          {   lna_path_loss = (l1d_rf2.is_fhc) ? (0) : ((int)(lnaptr->gain_offset_low-ofsptr->gain_offset));   }
/*MT6165*/          else
/*MT6165*/    #endif
/*MT6165*/          {   lna_path_loss = 0;   }
/*MT6165*/       }
/*MT6165*/       else if( rx_lna_setting==0x6 ) /* LNA_Middle */
/*MT6165*/       {  lna_path_loss = (l1d_rf2.is_fhc) ? (0) : ((int)(lnaptr->gain_offset_middle-ofsptr->gain_offset));  }
/*MT6165*/       else              /* LNA_Low */
/*MT6165*/       {  lna_path_loss = (l1d_rf2.is_fhc) ? (0) : ((int)(lnaptr->gain_offset_low-ofsptr->gain_offset));     }
/*MT6165*/ #else
/*MT6165*/       lna_path_loss = 0;
/*MT6165*/ #endif
/*MT6165*/
/*MT6165*/       real_gain = -lna_path_loss;
/*MT6165*/       if( 0 )
/*MT6165*/       { /* do nothing */ }
/*MT6165*/ #if IS_OUTBAND_BLOCKER_DETECTION_SUPPORT
/*MT6165*/       else if( ( (l1d_rf.blk_flag & LB_OBB_FOUND) && (band_mode == 0) && request_gain>= thres_OBB ) ||
/*MT6165*/                ( (l1d_rf.blk_flag & HB_OBB_FOUND) && (band_mode == 1) && request_gain>= thres_OBB )  )
/*MT6165*/       {  /* CW66: LNA Gain | IF GAIN | RXIF_BP_EN */
/*MT6165*/          setting = ((rx_lna_setting-1)<<17) | (rx_if_setting<<13) | (RXIF_BP_EN_NORMAL[band_mode][rx_gain_step]<<10);  // OBB: decrease RX_LNA_Gain by 1 step
/*MT6165*/          gain_table = OBB_GAIN_TABLE_FLAG;
/*MT6165*/          real_gain += GAIN_TABLE_OBB[band_mode][rx_gain_step];
/*MT6165*/       }
/*MT6165*/ #endif
/*MT6165*/ #if IS_INBAND_BLOCKER_DETECTION_SUPPORT
/*MT6165*/       else if( (l1d_rf.blk_flag & IBB_FOUND) && (request_gain>= thres_IBB ) )
/*MT6165*/       {  /* CW66: LNA Gain | IF GAIN | RXIF_BP_EN */
/*MT6165*/          setting    = ((rx_lna_setting-1)<<17) | (rx_if_setting<<13) | (RXIF_BP_EN_NORMAL[band_mode][rx_gain_step]<<10);  // IBB: decrease RX_LNA_Gain by 1 step
/*MT6165*/          gain_table = IBB_GAIN_TABLE_FLAG;
/*MT6165*/          real_gain += GAIN_TABLE_IBB[band_mode][rx_gain_step];
/*MT6165*/       }
/*MT6165*/ #endif
/*MT6165*/ #if IS_HEADROOM_DETECTION_SUPPORT
/*MT6165*/       else if( ( l1d_rf.blk_flag & HRD_FOUND ) && (request_gain >= thres_HRD ) )
/*MT6165*/       {  /* CW66: LNA Gain | IF GAIN | RXIF_BP_EN */
/*MT6165*/          setting    = (rx_lna_setting<<17) | ((rx_if_setting-2)<<13) | (RXIF_BP_EN_HEADROOM[band_mode][rx_gain_step]<<10);  // HRD: decrease RX_IF_Gain by 2 step
/*MT6165*/          gain_table = ACI_GAIN_TABLE_FLAG;
/*MT6165*/          real_gain += GAIN_TABLE_HEADROOM[band_mode][rx_gain_step];
/*MT6165*/       }
/*MT6165*/ #endif
/*MT6165*/       else
/*MT6165*/       {  /* CW66: LNA Gain | IF GAIN | RXIF_BP_EN */
/*MT6165*/          setting    = (rx_lna_setting<<17) | (rx_if_setting<<13) | (RXIF_BP_EN_NORMAL[band_mode][rx_gain_step]<<10);
/*MT6165*/          gain_table = NORMAL_GAIN_TABLE_FLAG;
/*MT6165*/          real_gain += GAIN_TABLE_NORMAL[band_mode][rx_gain_step];
/*MT6165*/       }
/*MT6165*/    }
/*MT6165*/
/*MT6165*/    *gain_setting = ((gain_table&0xFF)<<28) | BSI_CW(0x42, setting);  //CW66: RX Gain
/*MT6165*/    return( real_gain );
/*MT6165*/ }
/*MT6165*/
   #if IS_W_CANCELLATION_SUPPORT
/*MT6165*/ unsigned short   L1D_RF_FindGainStep( unsigned long gain_setting, FrequencyBand rf_band )
/*MT6165*/ {
/*MT6165*/    int band_mode, gain_step, gain_table, rx_lna_setting, rx_if_setting;
/*MT6165*/    
/*MT6165*/    gain_table     = (unsigned int)(gain_setting&0xFF0000000L)>>28;
/*MT6165*/    rx_lna_setting = (gain_setting&0xE0000)>>17;
/*MT6165*/    rx_if_setting  = (gain_setting&0x0E000)>>13;
/*MT6165*/    band_mode      = (rf_band < FrequencyBand1800) ? 0 /* LowBand */ : 1 /* HighBand */;
/*MT6165*/ 
/*MT6165*/    if( gain_table == NORMAL_GAIN_TABLE_FLAG )
/*MT6165*/    {  
/*MT6165*/       /* Normal condition: gain_step: 0,1,2,3,4 */
/*MT6165*/       for(gain_step = 0; gain_step <= 3; gain_step++ )
/*MT6165*/       {  if( ( rx_lna_setting == RXLNA_GAIN[band_mode][ NORMAL_GAIN_TABLE[gain_step][0] ] ) &&
/*MT6165*/              ( rx_if_setting  == RXIF_GAIN [band_mode][ NORMAL_GAIN_TABLE[gain_step][1] ] ) )
/*MT6165*/          {  break;  }
/*MT6165*/       }
/*MT6165*/       
/*MT6165*/       if( gain_step > 3 )  gain_step = 4;
/*MT6165*/    }
/*MT6165*/    #if IS_HEADROOM_DETECTION_SUPPORT
/*MT6165*/    else if( gain_table == ACI_GAIN_TABLE_FLAG )
/*MT6165*/    {  
/*MT6165*/       /* Headroom condition: gain_step: 2,3,4,5 */
/*MT6165*/       if( ( rx_lna_setting == RXLNA_GAIN[band_mode][ NORMAL_GAIN_TABLE[0][0] ] ) &&
/*MT6165*/           ( rx_if_setting  == RXIF_GAIN [band_mode][ NORMAL_GAIN_TABLE[0][1] ]-2 ) )
/*MT6165*/       {  gain_step=5;  }
/*MT6165*/       else
/*MT6165*/       {
/*MT6165*/          for(gain_step = 2; gain_step <= 3; gain_step++ )
/*MT6165*/          {  if( ( rx_lna_setting == RXLNA_GAIN[band_mode][ NORMAL_GAIN_TABLE[gain_step][0] ] ) &&
/*MT6165*/                 ( rx_if_setting  == RXIF_GAIN [band_mode][ NORMAL_GAIN_TABLE[gain_step][1] ] ) )
/*MT6165*/             {  break;  }
/*MT6165*/          }
/*MT6165*/          if( gain_step > 3 )  gain_step = 4;           
/*MT6165*/       }
/*MT6165*/    }
/*MT6165*/    #endif
/*MT6165*/    else /* Others: gain_step: 4 */
/*MT6165*/    {  gain_step = 4;  }
/*MT6165*/    
/*MT6165*/    /* LB step: 0,2,4,6,8,10 */
/*MT6165*/    /* HB step: 1,3,5,7,9,11 */
/*MT6165*/    gain_step = gain_step * 2 + band_mode;
/*MT6165*/    
/*MT6165*/    return gain_step;
/*MT6165*/ }
/*MT6165*/
   #endif
#endif

#if IS_RF_MT6580RF
/*MT6580RF*/
/*MT6580RF*/ #define  MAX_GAIN_STEP           9
/*MT6580RF*/ #define  PVOFSL                  34
/*MT6580RF*/ #define  PVOFSH                  34
/*MT6580RF*/ #define  NORMAL_GAIN_TABLE_FLAG  0
/*MT6580RF*/ #define  OBB_GAIN_TABLE_FLAG     1
/*MT6580RF*/ #define  IBB_GAIN_TABLE_FLAG     2
/*MT6580RF*/ #define  ACI_GAIN_TABLE_FLAG     3
/*MT6580RF*/ #define  RF_GSM850_MAXGAIN      ( 168)
/*MT6580RF*/ #define  RF_GSM850_MINGAIN      (-260)
/*MT6580RF*/ #define  RF_GSM_MAXGAIN         ( 168)
/*MT6580RF*/ #define  RF_GSM_MINGAIN         (-260)
/*MT6580RF*/ #define  RF_DCS_MAXGAIN         ( 168)
/*MT6580RF*/ #define  RF_DCS_MINGAIN         (-260)
/*MT6580RF*/ #define  RF_PCS_MAXGAIN         ( 168)
/*MT6580RF*/ #define  RF_PCS_MINGAIN         (-260)
/*MT6580RF*/
/*MT6580RF*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*MT6580RF*/ {  {                   0,                      0    }, /*#FrequencyBand400  */
/*MT6580RF*/    { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN }, /* FrequencyBand850  */
/*MT6580RF*/    { (int)RF_GSM_MAXGAIN,    (int)RF_GSM_MINGAIN    }, /* FrequencyBand900  */
/*MT6580RF*/    { (int)RF_DCS_MAXGAIN,    (int)RF_DCS_MINGAIN    }, /* FrequencyBand1800 */
/*MT6580RF*/    { (int)RF_PCS_MAXGAIN,    (int)RF_PCS_MINGAIN    }, /* FrequencyBand1900 */
/*MT6580RF*/ };
/*MT6580RF*/ /* { RF LNA gain_step, RF Mixer gain_step, RF LPF gain_step } */
/*MT6580RF*/ const  unsigned char  NORMAL_GAIN_SETTING_TABLE_LB[][3] =
/*MT6580RF*/ {  { 3, 1, 8 }, /* gain_step = 0 */
/*MT6580RF*/    { 3, 1, 5 }, /* gain_step = 1 */
/*MT6580RF*/    { 2, 1, 6 }, /* gain_step = 2 */
/*MT6580RF*/    { 2, 1, 4 }, /* gain_step = 3 */
/*MT6580RF*/    { 0, 1, 8 }, /* gain_step = 4 */
/*MT6580RF*/    { 0, 1, 6 }, /* gain_step = 5 */
/*MT6580RF*/    { 0, 1, 4 }, /* gain_step = 6 */
/*MT6580RF*/    { 0, 1, 2 }, /* gain_step = 7 */
/*MT6580RF*/    { 0, 0, 2 }, /* gain_step = 8 */
/*MT6580RF*/ };
/*MT6580RF*/ const  unsigned char  OBB_GAIN_SETTING_TABLE_LB[][3] =
/*MT6580RF*/ {  { 2, 1, 8 }, /* gain_step = 0 */
/*MT6580RF*/    { 2, 1, 6 }, /* gain_step = 1 */
/*MT6580RF*/    { 2, 1, 6 }, /* gain_step = 2 */
/*MT6580RF*/    { 2, 1, 4 }, /* gain_step = 3 */
/*MT6580RF*/    { 0, 1, 8 }, /* gain_step = 4 */
/*MT6580RF*/    { 0, 1, 6 }, /* gain_step = 5 */
/*MT6580RF*/    { 0, 1, 4 }, /* gain_step = 6 */
/*MT6580RF*/    { 0, 1, 2 }, /* gain_step = 7 */
/*MT6580RF*/    { 0, 0, 2 }, /* gain_step = 8 */
/*MT6580RF*/ };
/*MT6580RF*/ const  unsigned char  IBB_GAIN_SETTING_TABLE_LB[][3] =
/*MT6580RF*/ {  { 3, 0, 8 }, /* gain_step = 0 */
/*MT6580RF*/    { 2, 0, 6 }, /* gain_step = 1 */
/*MT6580RF*/    { 2, 0, 6 }, /* gain_step = 2 */
/*MT6580RF*/    { 2, 0, 4 }, /* gain_step = 3 */
/*MT6580RF*/    { 0, 1, 8 }, /* gain_step = 4 */
/*MT6580RF*/    { 0, 1, 6 }, /* gain_step = 5 */
/*MT6580RF*/    { 0, 1, 4 }, /* gain_step = 6 */
/*MT6580RF*/    { 0, 1, 2 }, /* gain_step = 7 */
/*MT6580RF*/    { 0, 0, 2 }, /* gain_step = 8 */
/*MT6580RF*/ };
/*MT6580RF*/ const  unsigned char  ACI_GAIN_SETTING_TABLE_LB[][3] =
/*MT6580RF*/ {  { 3, 1, 6 }, /* gain_step = 0 */
/*MT6580RF*/    { 3, 1, 3 }, /* gain_step = 1 */
/*MT6580RF*/    { 2, 1, 4 }, /* gain_step = 2 */
/*MT6580RF*/    { 2, 1, 4 }, /* gain_step = 3 */
/*MT6580RF*/    { 0, 1, 8 }, /* gain_step = 4 */
/*MT6580RF*/    { 0, 1, 6 }, /* gain_step = 5 */
/*MT6580RF*/    { 0, 1, 4 }, /* gain_step = 6 */
/*MT6580RF*/    { 0, 1, 2 }, /* gain_step = 7 */
/*MT6580RF*/    { 0, 0, 2 }, /* gain_step = 8 */
/*MT6580RF*/ };
/*MT6580RF*/ const  unsigned char  NORMAL_GAIN_SETTING_TABLE_HB[][3] =
/*MT6580RF*/ {  { 3, 1, 8 }, /* gain_step = 0 */
/*MT6580RF*/    { 3, 1, 5 }, /* gain_step = 1 */
/*MT6580RF*/    { 2, 1, 6 }, /* gain_step = 2 */
/*MT6580RF*/    { 2, 1, 4 }, /* gain_step = 3 */
/*MT6580RF*/    { 0, 1, 8 }, /* gain_step = 4 */
/*MT6580RF*/    { 0, 1, 6 }, /* gain_step = 5 */
/*MT6580RF*/    { 0, 1, 4 }, /* gain_step = 6 */
/*MT6580RF*/    { 0, 1, 2 }, /* gain_step = 7 */
/*MT6580RF*/    { 0, 0, 2 }, /* gain_step = 8 */
/*MT6580RF*/ };
/*MT6580RF*/ const  unsigned char  OBB_GAIN_SETTING_TABLE_HB[][3] =
/*MT6580RF*/ {  { 2, 1, 8 }, /* gain_step = 0 */
/*MT6580RF*/    { 2, 1, 6 }, /* gain_step = 1 */
/*MT6580RF*/    { 2, 1, 6 }, /* gain_step = 2 */
/*MT6580RF*/    { 2, 1, 4 }, /* gain_step = 3 */
/*MT6580RF*/    { 0, 1, 8 }, /* gain_step = 4 */
/*MT6580RF*/    { 0, 1, 6 }, /* gain_step = 5 */
/*MT6580RF*/    { 0, 1, 4 }, /* gain_step = 6 */
/*MT6580RF*/    { 0, 1, 2 }, /* gain_step = 7 */
/*MT6580RF*/    { 0, 0, 2 }, /* gain_step = 8 */
/*MT6580RF*/ };
/*MT6580RF*/ const  unsigned char  IBB_GAIN_SETTING_TABLE_HB[][3] =
/*MT6580RF*/ {  { 3, 0, 8 }, /* gain_step = 0 */
/*MT6580RF*/    { 2, 0, 6 }, /* gain_step = 1 */
/*MT6580RF*/    { 2, 0, 6 }, /* gain_step = 2 */
/*MT6580RF*/    { 2, 0, 4 }, /* gain_step = 3 */
/*MT6580RF*/    { 0, 1, 8 }, /* gain_step = 4 */
/*MT6580RF*/    { 0, 1, 6 }, /* gain_step = 5 */
/*MT6580RF*/    { 0, 1, 4 }, /* gain_step = 6 */
/*MT6580RF*/    { 0, 1, 2 }, /* gain_step = 7 */
/*MT6580RF*/    { 0, 0, 2 }, /* gain_step = 8 */
/*MT6580RF*/ };
/*MT6580RF*/ const  unsigned char  ACI_GAIN_SETTING_TABLE_HB[][3] =
/*MT6580RF*/ {  { 3, 1, 6 }, /* gain_step = 0 */
/*MT6580RF*/    { 3, 1, 3 }, /* gain_step = 1 */
/*MT6580RF*/    { 2, 1, 4 }, /* gain_step = 2 */
/*MT6580RF*/    { 2, 1, 4 }, /* gain_step = 3 */
/*MT6580RF*/    { 0, 1, 8 }, /* gain_step = 4 */
/*MT6580RF*/    { 0, 1, 6 }, /* gain_step = 5 */
/*MT6580RF*/    { 0, 1, 4 }, /* gain_step = 6 */
/*MT6580RF*/    { 0, 1, 2 }, /* gain_step = 7 */
/*MT6580RF*/    { 0, 0, 2 }, /* gain_step = 8 */
/*MT6580RF*/ };
/*MT6580RF*/ const  unsigned char  RXLNA_GAIN[2][4] =
/*MT6580RF*/ {  /*  0    1    2    3    :RF LNA gain_step */
/*MT6580RF*/    { 0x0, 0x1, 0x2, 0x3 }, /* LowBand    */ /*3bits*/
/*MT6580RF*/    { 0x0, 0x1, 0x2, 0x3 }, /* HighBand   */ /*3bits*/
/*MT6580RF*/ };
/*MT6580RF*/ const  unsigned char  RXTZ_GAIN[2][2] =
/*MT6580RF*/ {  /*  0    1    :RF Mixer gain_step */
/*MT6580RF*/    { 0x2, 0x1 }, /* LowBand    */ /*2bits*/
/*MT6580RF*/    { 0x2, 0x1 }, /* HighBand   */ /*2bits*/
/*MT6580RF*/ };
/*MT6580RF*/ const  unsigned char  RXIF_GAIN[2][12] =
/*MT6580RF*/ {  /*  0    1    2    3    4,   5,   6,   7,   8,   9,  10,  11    :RF LPF gain_step */
/*MT6580RF*/    { 0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xA, 0xB }, /* LowBand    */ /*4bits*/
/*MT6580RF*/    { 0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xA, 0xB }, /* HighBand   */ /*4bits*/
/*MT6580RF*/ };
/*MT6580RF*/
/*MT6580RF*/ /* GAIN_TABLE: voltage gain (total gain) */
/*MT6580RF*/ const  signed short  GAIN_TABLE_NORMAL[2][MAX_GAIN_STEP] =
/*MT6580RF*/ {  /*  0   1   2   3    4     5     6     7     8    :gain_step    */
/*MT6580RF*/    { 168, 96, 76, 28, -68, -116, -164, -212, -260 }, /* LowBand  */
/*MT6580RF*/    { 168, 96, 76, 28, -68, -116, -164, -212, -260 }, /* HighBand */
/*MT6580RF*/ };
/*MT6580RF*/ const  signed short  GAIN_TABLE_OBB[2][MAX_GAIN_STEP] =
/*MT6580RF*/ {  /*  0   1   2   3    4     5     6     7     8    :gain_step    */
/*MT6580RF*/    { 144, 96, 96, 48, -68, -116, -164, -212, -260 }, /* LowBand  */
/*MT6580RF*/    { 136, 88, 88, 40, -68, -116, -164, -212, -260 }, /* HighBand */
/*MT6580RF*/ };
/*MT6580RF*/ const  signed short  GAIN_TABLE_IBB[2][MAX_GAIN_STEP] =
/*MT6580RF*/ {  /*  0   1   2    3    4     5     6     7     8    :gain_step    */
/*MT6580RF*/    { 120, 28, 28, -20, -68, -116, -164, -212, -260 }, /* LowBand  */
/*MT6580RF*/    { 120, 28, 28, -20, -68, -116, -164, -212, -260 }, /* HighBand */
/*MT6580RF*/ };
/*MT6580RF*/ const  signed short  GAIN_TABLE_HEADROOM[2][MAX_GAIN_STEP] =
/*MT6580RF*/ {  /*  0   1   2   3    4     5     6     7     8    :gain_step    */
/*MT6580RF*/    { 120, 48, 28, 28, -68, -116, -164, -212, -260 }, /* LowBand  */
/*MT6580RF*/    { 120, 48, 28, 28, -68, -116, -164, -212, -260 }, /* HighBand */
/*MT6580RF*/ };
/*MT6580RF*/
/*MT6580RF*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*MT6580RF*/
/*MT6580RF*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*MT6580RF*/ {  int   max_gain, min_gain, real_gain, band_mode, gain_table;
/*MT6580RF*/    const unsigned char*   GAIN_SETTING_TABLE;
/*MT6580RF*/    const int*    d32ptr;
/*MT6580RF*/ #if IS_MULTI_LNA_MODE_CALIBRATION_SUPPORT
/*MT6580RF*/    sLNAGAINOFFSET*     lnaptr;
/*MT6580RF*/ #endif
/*MT6580RF*/    sAGCGAINOFFSET*     ofsptr;
/*MT6580RF*/    long  setting;
/*MT6580RF*/    int   thres_IBB, thres_HRD;
/*MT6580RF*/    int   rx_gain_step, rx_lna_setting, rx_tz_setting, rx_if_setting, lna_path_loss;
/*MT6580RF*/
/*MT6580RF*/    band_mode      = (rf_band < FrequencyBand1800) ? 0 /* LowBand */ : 1 /* HighBand */;
/*MT6580RF*/
/*MT6580RF*/    /* evaluate the range of available gain */
/*MT6580RF*/    d32ptr   = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*MT6580RF*/    max_gain = *d32ptr++;
/*MT6580RF*/    min_gain = *d32ptr;
/*MT6580RF*/
/*MT6580RF*/    /* clipping the request gain to the avialable gain */
/*MT6580RF*/    if( request_gain>=max_gain )
/*MT6580RF*/    {  request_gain = max_gain;
/*MT6580RF*/    }
/*MT6580RF*/    else if( request_gain<=min_gain )
/*MT6580RF*/    {  request_gain = min_gain;
/*MT6580RF*/    }
/*MT6580RF*/
/*MT6580RF*/    for ( rx_gain_step = 0; rx_gain_step < MAX_GAIN_STEP; rx_gain_step++ )
/*MT6580RF*/    {
/*MT6580RF*/       if( request_gain >= GAIN_TABLE_NORMAL[band_mode][rx_gain_step] )
/*MT6580RF*/       {  break;  }
/*MT6580RF*/    }
/*MT6580RF*/    if( rx_gain_step >= MAX_GAIN_STEP )
/*MT6580RF*/    {  rx_gain_step = (MAX_GAIN_STEP-1);
/*MT6580RF*/    }
/*MT6580RF*/
/*MT6580RF*/    thres_IBB      = band_mode ?            24 :              24;   //( 37-PVOFSL )*PWRRES : ( 37-PVOFSH )*PWRRES
/*MT6580RF*/    thres_HRD      = band_mode ?            72 :              72;   //( 43-PVOFSL )*PWRRES : ( 43-PVOFSH )*PWRRES
/*MT6580RF*/
/*MT6580RF*/    /* Evaluate the real gain setting. */
/*MT6580RF*/    {
/*MT6580RF*/       if( 0 )
/*MT6580RF*/       { /* do nothing */ }
/*MT6580RF*/ #if IS_OUTBAND_BLOCKER_DETECTION_SUPPORT
/*MT6580RF*/       else if( ( (l1d_rf.blk_flag & LB_OBB_FOUND) && (band_mode == 0) ) || ( (l1d_rf.blk_flag & HB_OBB_FOUND) && (band_mode == 1) ) )
/*MT6580RF*/       {  GAIN_SETTING_TABLE = band_mode ? OBB_GAIN_SETTING_TABLE_HB[rx_gain_step] /* HighBand */: OBB_GAIN_SETTING_TABLE_LB[rx_gain_step] /* LowBand */;
/*MT6580RF*/          gain_table = OBB_GAIN_TABLE_FLAG;
/*MT6580RF*/          real_gain = GAIN_TABLE_OBB[band_mode][rx_gain_step];
/*MT6580RF*/       }
/*MT6580RF*/ #endif
/*MT6580RF*/ #if IS_INBAND_BLOCKER_DETECTION_SUPPORT
/*MT6580RF*/       else if( (l1d_rf.blk_flag & IBB_FOUND) && (request_gain>= thres_IBB ) )
/*MT6580RF*/       {  GAIN_SETTING_TABLE = band_mode ? IBB_GAIN_SETTING_TABLE_HB[rx_gain_step] /* HighBand */: IBB_GAIN_SETTING_TABLE_LB[rx_gain_step] /* LowBand */;
/*MT6580RF*/          gain_table = IBB_GAIN_TABLE_FLAG;
/*MT6580RF*/          real_gain = GAIN_TABLE_IBB[band_mode][rx_gain_step];
/*MT6580RF*/       }
/*MT6580RF*/ #endif
/*MT6580RF*/ #if IS_HEADROOM_DETECTION_SUPPORT
/*MT6580RF*/       else if( ( l1d_rf.blk_flag & HRD_FOUND ) && (request_gain >= thres_HRD ) )
/*MT6580RF*/       {  GAIN_SETTING_TABLE = band_mode ? ACI_GAIN_SETTING_TABLE_HB[rx_gain_step] /* HighBand */: ACI_GAIN_SETTING_TABLE_LB[rx_gain_step] /* LowBand */;
/*MT6580RF*/          gain_table = ACI_GAIN_TABLE_FLAG;
/*MT6580RF*/          real_gain = GAIN_TABLE_HEADROOM[band_mode][rx_gain_step];
/*MT6580RF*/       }
/*MT6580RF*/ #endif
/*MT6580RF*/       else
/*MT6580RF*/       {  GAIN_SETTING_TABLE = band_mode ? NORMAL_GAIN_SETTING_TABLE_HB[rx_gain_step] /* HighBand */: NORMAL_GAIN_SETTING_TABLE_LB[rx_gain_step] /* LowBand */;
/*MT6580RF*/          gain_table = NORMAL_GAIN_TABLE_FLAG;
/*MT6580RF*/          real_gain = GAIN_TABLE_NORMAL[band_mode][rx_gain_step];
/*MT6580RF*/       }
/*MT6580RF*/       rx_lna_setting = RXLNA_GAIN[band_mode][GAIN_SETTING_TABLE[0]];
/*MT6580RF*/       rx_tz_setting  = RXTZ_GAIN[band_mode][GAIN_SETTING_TABLE[1]];
/*MT6580RF*/       rx_if_setting  = RXIF_GAIN[band_mode][GAIN_SETTING_TABLE[2]];
/*MT6580RF*/       /* CW131: RXIF_GAIN | RXLNA_GAIN | RXTZ_GAIN */
/*MT6580RF*/       setting = ( POR_CW131 &(~(GAIN_SETTING_MASK)) )|(((rx_if_setting)<<10) | (rx_lna_setting<<7) | (rx_tz_setting<<5));
/*MT6580RF*/
/*MT6580RF*/ #if IS_MULTI_LNA_MODE_CALIBRATION_SUPPORT
/*MT6580RF*/       /* choose the LNA path loss */
/*MT6580RF*/       lnaptr = LNA_PATHLOSS_TABLE[rf_band];
/*MT6580RF*/ #endif
/*MT6580RF*/       /* get the arfcn section */
/*MT6580RF*/       ofsptr = AGC_PATHLOSS_TABLE[rf_band];
/*MT6580RF*/       while( ofsptr->max_arfcn>=0 )
/*MT6580RF*/       {  if( arfcn <= ofsptr->max_arfcn )
/*MT6580RF*/          {  break;  }
/*MT6580RF*/          ofsptr++;
/*MT6580RF*/ #if IS_MULTI_LNA_MODE_CALIBRATION_SUPPORT
/*MT6580RF*/          lnaptr++;
/*MT6580RF*/ #endif
/*MT6580RF*/       }
/*MT6580RF*/
/*MT6580RF*/ #if IS_MULTI_LNA_MODE_CALIBRATION_SUPPORT
/*MT6580RF*/       if( rx_lna_setting==0x3 )      /* LNA_High */
/*MT6580RF*/       {  lna_path_loss = 0;  }
/*MT6580RF*/       else if( rx_lna_setting==0x2 ) /* LNA_Middle */
/*MT6580RF*/       {  lna_path_loss = (l1d_rf2.is_fhc) ? (0) : ((int)(lnaptr->gain_offset_middle-ofsptr->gain_offset));  }
/*MT6580RF*/       else                           /* LNA_Low */
/*MT6580RF*/       {  lna_path_loss = (l1d_rf2.is_fhc) ? (0) : ((int)(lnaptr->gain_offset_low-ofsptr->gain_offset));     }
/*MT6580RF*/ #else
/*MT6580RF*/       lna_path_loss = 0;
/*MT6580RF*/ #endif
/*MT6580RF*/
/*MT6580RF*/       real_gain -= lna_path_loss;
/*MT6580RF*/    }
/*MT6580RF*/
/*MT6580RF*/    *gain_setting = ((gain_table&0xF)<<28) | BSI_CW(0x83, setting);  //CW131: RX Gain
/*MT6580RF*/    return( real_gain );
/*MT6580RF*/ }
/*MT6580RF*/
   #if IS_W_CANCELLATION_SUPPORT
/*MT6580RF*/ unsigned short   L1D_RF_FindGainStep( unsigned long gain_setting, FrequencyBand rf_band  )
/*MT6580RF*/ {
/*MT6580RF*/    int band_mode, gain_step, gain_table, rx_lna_setting, rx_if_setting;
/*MT6580RF*/    
/*MT6580RF*/    gain_table     = (unsigned int)(gain_setting&0xF0000000L)>>28;
/*MT6580RF*/    //rx_tz_setting is not used to judge gain step in L1D_RF_FindGainStep now
/*MT6580RF*/    //int rx_tz_setting;
/*MT6580RF*/    //rx_tz_setting  = (gain_setting&0x00060)>>5;
/*MT6580RF*/    rx_lna_setting = (gain_setting&0x00380)>>7;
/*MT6580RF*/    rx_if_setting  = (gain_setting&0x03C00)>>10;
/*MT6580RF*/    band_mode      = (rf_band < FrequencyBand1800) ? 0 /* LowBand */ : 1 /* HighBand */;
/*MT6580RF*/
/*MT6580RF*/    if( gain_table == NORMAL_GAIN_TABLE_FLAG )
/*MT6580RF*/    {
/*MT6580RF*/       if( rx_lna_setting >= 0x2 )      //G2 or G3
/*MT6580RF*/       {
/*MT6580RF*/          if( rx_if_setting== 0x4)      //6
/*MT6580RF*/             gain_step = 1;
/*MT6580RF*/          else if( rx_if_setting== 0x6) //12
/*MT6580RF*/             gain_step = 3;
/*MT6580RF*/          else if( rx_if_setting== 0x5) //9
/*MT6580RF*/             gain_step = 4;
/*MT6580RF*/          else                          //18
/*MT6580RF*/             gain_step = 6;
/*MT6580RF*/       }
/*MT6580RF*/       else
/*MT6580RF*/       {
/*MT6580RF*/          gain_step = 0;
/*MT6580RF*/       }
/*MT6580RF*/    }
/*MT6580RF*/    #if IS_HEADROOM_DETECTION_SUPPORT
/*MT6580RF*/    else if( gain_table == ACI_GAIN_TABLE_FLAG )
/*MT6580RF*/    {
/*MT6580RF*/       if( rx_lna_setting >= 0x2 )      //G2 or G3
/*MT6580RF*/       {
/*MT6580RF*/          if( rx_if_setting== 0x4)      //6
/*MT6580RF*/             gain_step = 1;
/*MT6580RF*/          else if( rx_if_setting== 0x3) //3
/*MT6580RF*/             gain_step = 2;
/*MT6580RF*/          else                          //12
/*MT6580RF*/             gain_step = 5;
/*MT6580RF*/       }
/*MT6580RF*/       else
/*MT6580RF*/       {
/*MT6580RF*/          gain_step = 0;
/*MT6580RF*/       }
/*MT6580RF*/    }
/*MT6580RF*/    #endif
/*MT6580RF*/    else
/*MT6580RF*/    {
/*MT6580RF*/       gain_step = 0;
/*MT6580RF*/    }
/*MT6580RF*/
/*MT6580RF*/    /* LB step: 0,2,4,6,8,10,12 */
/*MT6580RF*/    /* HB step: 1,3,5,7,9,11,13 */
/*MT6580RF*/    gain_step = gain_step * 2 + band_mode;
/*MT6580RF*/
/*MT6580RF*/    return gain_step;
/*MT6580RF*/ }
/*MT6580RF*/
   #endif
#endif
