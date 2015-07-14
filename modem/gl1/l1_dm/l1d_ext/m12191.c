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
 *   m12191.c
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   Setup Synthesizer
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Revision:   1.30  $
 * $Modtime:   Jul 29 2005 13:44:06  $
 * $Log:   //mtkvs01/vmdata/Maui_sw/archives/mcu/l1/l1d/m12191.c-arc  $
 *
 * 03 03 2015 hosen.chen
 * [MOLY00094981] [L1D][Modify] Check in MT6580/Rainier RF driver
 * 	Rainier RF driver merge back to WR8 MP branch.
 *
 * 08 22 2013 vend_cuthbert.kao
 * [MOLY00034524] [MT6592][MT6571][L1D][Modify] MT6592 BB Driver + MT6571 BB Driver + MT6165 RF Driver integration
 * .
 *
 * 05 09 2013 yi-ying.lin
 * [MOLY00022023] [Volunteer Patch][L1D][Modify] Fixed the offset between +/- IF for W coefficient
 * .
 *
 * 04 18 2013 yi-ying.lin
 * [MOLY00020187] [L1D][Modify] Turn on IS_OBB_DETECTION_SUPPORT
 * .
 *
 * 03 19 2013 ola.lee
 * [MOLY00012185] [Fix-AFC] Check-in Fix-AFC related modification(L1D/UL1D/SM) into WR8 & MOLY
 * .
 *
 * 03 18 2013 ola.lee
 * [MOLY00011484] RF STX unlocking at 3G high band
 * .
 *
 * 03 15 2013 yi-ying.lin
 * [MOLY00012047] [L1D][Modify] Turn on MT6166 feature option
 * .
 *
 * 02 06 2013 yi-ying.lin
 * [MOLY00009540] [L1D][Modify] MT6166 RF driver development
 * .
 *
 * 01 29 2013 yi-ying.lin
 * [MOLY00009540] [L1D][Modify] MT6166 RF driver development
 * .
 *
 * 12 06 2012 sean.yang
 * [MOLY00007140] [L1D][Modify] Modify the flow to set the RX settings for integer and non-integer channels on OthelloT
 * .
 *
 * 10 18 2012 ola.lee
 * [MOLY00005004] [L1D][Modify] Modify MT6589/MT6167 Codes.
 * .
 *
 * 10 16 2012 ola.lee
 * [MOLY00004577] [L1D][Modify] Roll back MT6589 phone call patch
 * Enable W Coeff/IBBD/HRD for MT6589.
 *
 * 10 08 2012 ola.lee
 * [MOLY00004577] [L1D][Modify] Roll back MT6589 phone call patch
 *
 * 09 28 2012 ola.lee
 * [MOLY00004302] [L1D][Modify] Update MT6167 POR Setting
 * [L1D][Modify] Update MT6167 POR Setting.
 *
 * 09 17 2012 ola.lee
 * [MOLY00002567] [L1D][Modify] Check-in MT6583/MT6167 Codes
 * .
 *
 * 08 23 2012 ola.lee
 * [MOLY00002567] [L1D][Modify] Check-in MT6583/MT6167 Codes
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
 * 11 17 2011 chang-kuan.lin
 * removed!
 * .
 *
 * 10 21 2011 th.yeh
 * removed!
 * .
 *
 * 08 24 2011 victo.chen
 * removed!
 * .
 *
 * 07 21 2011 weining.chien
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
 * 04 15 2011 weining.chien
 * removed!
 * .
 *
 * 04 14 2011 sean.yang
 * removed!
 * .
 *
 * 03 16 2011 victo.chen
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
 * 12 20 2010 sean.yang
 * removed!
 * .
 *
 * 12 15 2010 chang-kuan.lin
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
 * 11 18 2010 max.weng
 * removed!
 * .
 *
 * 11 16 2010 victo.chen
 * removed!
 * .
 *
 * 11 12 2010 max.weng
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
 * 09 05 2010 victo.chen
 * removed!
 * .
 *
 * 08 12 2010 victo.chen
 * removed!
 * .
 *
 * 08 07 2010 samuel.yang
 * removed!
 * .
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
 * [L1D][Modify]Check in AD6546 RF Driver #if IS_RF_AD6546
 *
 * removed!
 * removed!
 * Remove compile warning of may be used before being set
 *
 * removed!
 * removed!
 * local variable f_vco is not used
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
 *    Rev 1.30   Jul 29 2005 14:01:24   mtk00773
 * [L1D][Enhence] Support RF SKY74117
 * Resolution for 12111: [L1D][Enhence] Support RF SKY74117
 *
 *    Rev 1.29   Jul 08 2005 16:53:04   mtk00939
 * [L1D][Modify]L1D add code for MT6139C and META related code
 *
 *    Rev 1.28   May 17 2005 00:34:36   BM_Trunk
 * Karlos:
 * add copyright and disclaimer statement
 *
 *    Rev 1.27   Jan 18 2005 00:38:08   BM
 * append new line in W05.04
 *
 *    Rev 1.26   Jul 30 2004 17:37:06   mtk00240
 * L1D add code to support AERO1Plus RF chip
 * Resolution for 6925: [L1D][Enhance] L1D add code to support AERO1Plus RF chip
 *
 *    Rev 1.25   Jul 05 2004 15:49:42   mtk00773
 * Add RF POLARIS1 setting
 *
 *    Rev 1.24   May 21 2004 19:01:58   mtk00240
 * Add code to support MT6129D
 * Resolution for 5565: [L1D][Add Feature] Add code to support MT6129D
 *
 *    Rev 1.23   Jan 27 2004 15:33:12   mtk00585
 * [L1D][Add] L1D Add code for MT6129C RF Driver.
 *
 *    Rev 1.22   Oct 23 2003 14:22:18   mtk00585
 * [L1D][Add] L1D Add code for MT6129B RF Driver.
 * Resolution for 3177: [L1D][Add] L1D Add code for MT6129B RF Driver.
 *
 *    Rev 1.21   Jul 11 2003 17:41:30   mtk00489
 * [L1D][Enhanced]L1D supports MT6129A
 * Resolution for 2241: [L1D][Enhanced]L1D supports MT6129A
 *
 *    Rev 1.20   May 16 2003 13:09:24   mtk00489
 * [L1D][New Feature]L1D supports MT6119C
 * Resolution for 1794: [L1D][New Feature]L1D supports MT6119C
 *
 *    Rev 1.19   Mar 07 2003 18:47:32   mtk00474
 * modify the coding error for decision tx arfcn value of MT6119
 * Resolution for 1182: modify the coding error for decision tx arfcn value of MT6119
 *
 *    Rev 1.18   14 Feb 2003 11:42:54   mtk00240
 * L1D modify the synthesizer setting of Bright4 to support PCS band
 * Resolution for 652: L1D modify the synthesizer setting of Bright4 to support PCS band
 *
 *    Rev 1.17   Nov 11 2002 18:04:58   mtk00474
 * Update MT6119 and AERO RF parameters
 * Resolution for 557: Update MT6119 and AERO RF parameters
 *
 *    Rev 1.16   01 Nov 2002 11:11:24   mtk00240
 * L1D modify TX PLL evaulation for new MT6119 chip
 * Resolution for 547: L1D modify TX PLL evaulation for new MT6119 chip
 *
 *    Rev 1.15   22 Oct 2002 08:18:00   mtk00240
 * L1D modified some control data of mt6119
 * Resolution for 439: L1D add code to support MT6119 RF Module
 *
 *    Rev 1.14   01 Oct 2002 09:41:12   mtk00240
 * L1D modified GSM RX frequency evaluation of MT6119
 * Resolution for 515: L1D modified GSM RX frequency evaluation of MT6119
 *
 *    Rev 1.13   01 Sep 2002 15:35:30   mtk00240
 * L1D fix the bug that  max ARFCN of GSM is 1023 not 1024
 * Resolution for 473: L1D fix the bug that  max ARFCN of GSM is 1023 not 1024
 *
 *    Rev 1.12   27 Aug 2002 12:04:22   admin
 * change file header
 *
 *    Rev 1.11   26 Aug 2002 14:34:14   admin
 * remove modification notice
 * add copyright statement.
 *
 *    Rev 1.10   24 Aug 2002 14:10:46   mtk00240
 *  L1D add code to support AERO RF Module
 * Resolution for 464:  L1D add code to support AERO RF Module
 *
 *    Rev 1.9   23 Jul 2002 15:49:12   mtk00240
 * L1D add code to support MT6119 RF Module
 * Resolution for 439: L1D add code to support MT6119 RF Module
 *
 *    Rev 1.8   03 Jul 2002 21:43:48   mtk00240
 * L1D extrract RF setting code to let customer setup new RF module more easily
 * Resolution for 418: L1D extrract RF setting code to let customer setup new RF module more easily
 *
 *    Rev 1.7   01 May 2002 22:45:58   mtk00240
 * Extract GSM code from L1D
 * Resolution for 384: Extract GSM code from L1D
 *
 *    Rev 1.6   30 Mar 2002 13:04:16   mtk00240
 * 1) Modify L1D code to support both Bright2 & Bright4 RF board
 * 2) L1D add Audio interface to support Voice Memo & Melody
 * 3) Add L1D code to support RAM-based chip
 * Resolution for 341: Modify L1D code to support both Bright2 & Bright4 RF board
 * Resolution for 342: L1D add Audio interface to support Voice Memo & Melody
 * Resolution for 343: Add L1D code to support RAM-based chip
 *
 *    Rev 1.5   03 Mar 2002 23:07:10   mtk00240
 * L1D modified Tx synthesizer setting of DCS band
 * Resolution for 306: L1D modified Tx synthesizer setting of DCS band
 *
 *    Rev 1.4   17 Feb 2002 20:15:42   mtk00240
 * Update L1D code for solving HandOver test item
 * Resolution for 275: Update L1D code for solving HandOver test item
 *
 *    Rev 1.3   03 Jan 2002 12:19:50   mtk00240
 * Merge B.L1.20011225 to Main V1.XX
 *
 *    Rev 1.2.1.0   Dec 25 2001 14:32:56   mtk00210
 * Update for High resolution RSSI, multiband AFC,
 * update L1C/L1D interface for CSD
 *
 *    Rev 1.1   Dec 10 2001 16:43:56   mtk00240
 * Add copyright header of MediaTek
 *
 *******************************************************************************/


/*===============================================================================*/
/*                                                                               */
/* void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )  */
/* void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )  */
/*                                                                               */
/*===============================================================================*/
/*                                                                               */
/* arfcn  : the request ARFCN number.                                            */
/* *rfN   : returned RF N counter setting                                        */
/* *ifN   : returned IF N counter setting                                        */
/*                                                                               */
/* ----------------------------------------------------------------------------- */
/*                                                                               */
/* This program evaluates the PLL setting value by the request arfcn for Si4133. */
/* If the PLL component is changed, this file shall be modified by vendor        */
/*                                                                               */
/* ----------------------------------------------------------------------------- */

#include "l1d_cid.h"
#include "m12190.h"

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
#endif

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/*MT6129C,D*/void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6129C,D*/{  int   Nfrac;
/*MT6129C,D*/
/*MT6129C,D*/   switch(rf_band)
/*MT6129C,D*/   {
/*MT6129C,D*/      case  FrequencyBand850 :
/*MT6129C,D*/      {
/*MT6129C,D*/         if(arfcn<=202)
/*MT6129C,D*/         {  if(arfcn<=137)                              /*  ARFCN :  128~137    */
/*MT6129C,D*/            {  Nfrac = 80*(arfcn-128)+4440;
/*MT6129C,D*/               *rfN = (2L<<17) | (Nfrac<<4) | 1;
/*MT6129C,D*/            }
/*MT6129C,D*/            else                                        /*  ARFCN :  138~202    */
/*MT6129C,D*/            {  Nfrac = 80*(arfcn-138)+40;
/*MT6129C,D*/               *rfN = (3L<<17) | (Nfrac<<4) | 1;
/*MT6129C,D*/            }
/*MT6129C,D*/         }
/*MT6129C,D*/         else
/*MT6129C,D*/         {                                             /*  ARFCN :  203~251   */
/*MT6129C,D*/               Nfrac = 80*(arfcn-203)+40;
/*MT6129C,D*/               *rfN = (4L<<17) | (Nfrac<<4) | 1;
/*MT6129C,D*/         }
/*MT6129C,D*/         break;
/*MT6129C,D*/      }
/*MT6129C,D*/      case  FrequencyBand900 :
/*MT6129C,D*/      {
/*MT6129C,D*/         if(arfcn<=70)
/*MT6129C,D*/         {  if(arfcn<=5)                                /*  ARFCN :   0~5    */
/*MT6129C,D*/            {  Nfrac = 80*(arfcn-0)+4760;
/*MT6129C,D*/               *rfN = (7L<<17) | (Nfrac<<4) | 1;
/*MT6129C,D*/            }
/*MT6129C,D*/            else                                        /*  ARFCN :  6~70    */
/*MT6129C,D*/            {  Nfrac = 80*(arfcn-6)+40;
/*MT6129C,D*/               *rfN = (8L<<17) | (Nfrac<<4) | 1;
/*MT6129C,D*/            }
/*MT6129C,D*/         }
/*MT6129C,D*/         else
/*MT6129C,D*/         {  if(arfcn<=124)                              /*  ARFCN : 71~124   */
/*MT6129C,D*/            {  Nfrac = 80*(arfcn-71)+40;
/*MT6129C,D*/               *rfN = (9L<<17) | (Nfrac<<4) | 1;
/*MT6129C,D*/            }
/*MT6129C,D*/            else
/*MT6129C,D*/            {  Nfrac = 80*(arfcn-975)+840;              /*  ARFCN : 975~1023 */
/*MT6129C,D*/               *rfN = (7L<<17) | (Nfrac<<4) | 1;
/*MT6129C,D*/            }
/*MT6129C,D*/         }
/*MT6129C,D*/         break;
/*MT6129C,D*/      }
/*MT6129C,D*/      case  FrequencyBand1800 :
/*MT6129C,D*/      {
/*MT6129C,D*/         if(arfcn<=716)
/*MT6129C,D*/         {  if(arfcn<=586)                              /*  ARFCN : 512~586  */
/*MT6129C,D*/            {  Nfrac = 40*(arfcn-512)+2220;
/*MT6129C,D*/               *rfN = (5L<<17) | (Nfrac<<4) | 1;
/*MT6129C,D*/            }
/*MT6129C,D*/            else                                        /*  ARFCN : 587~716  */
/*MT6129C,D*/            {  Nfrac = 40*(arfcn-587)+20;
/*MT6129C,D*/               *rfN = (6L<<17) | (Nfrac<<4) | 1;
/*MT6129C,D*/            }
/*MT6129C,D*/         }
/*MT6129C,D*/         else
/*MT6129C,D*/         {  if(arfcn<=846)                              /*  ARFCN : 717~846  */
/*MT6129C,D*/            {  Nfrac = 40*(arfcn-717)+20;
/*MT6129C,D*/               *rfN = (7L<<17) | (Nfrac<<4) | 1;
/*MT6129C,D*/            }
/*MT6129C,D*/            else                                        /*  ARFCN : 847~885  */
/*MT6129C,D*/            {  Nfrac = 40*(arfcn-847)+20;
/*MT6129C,D*/               *rfN = (8L<<17) | (Nfrac<<4) | 1;
/*MT6129C,D*/            }
/*MT6129C,D*/         }
/*MT6129C,D*/         break;
/*MT6129C,D*/      }
/*MT6129C,D*/      case  FrequencyBand1900 :
/*MT6129C,D*/      {
/*MT6129C,D*/         if(arfcn<=741)
/*MT6129C,D*/         {  if(arfcn<=611)                              /*  ARFCN : 512~611  */
/*MT6129C,D*/            {  Nfrac = 40*(arfcn-512)+1220;
/*MT6129C,D*/               *rfN = (10L<<17) | (Nfrac<<4) | 1;
/*MT6129C,D*/            }
/*MT6129C,D*/            else                                        /*  ARFCN : 612~741  */
/*MT6129C,D*/            {  Nfrac = 40*(arfcn-612)+20;
/*MT6129C,D*/               *rfN = (11L<<17) | (Nfrac<<4) | 1;
/*MT6129C,D*/            }
/*MT6129C,D*/         }
/*MT6129C,D*/         else
/*MT6129C,D*/         {  Nfrac = 40*(arfcn-742)+20;                  /*  ARFCN : 742~810  */
/*MT6129C,D*/            *rfN = (12L<<17) | (Nfrac<<4) | 1;
/*MT6129C,D*/         }
/*MT6129C,D*/         break;
/*MT6129C,D*/      }
/*MT6129C,D*/      default :
/*MT6129C,D*/      {
/*MT6129C,D*/         break;
/*MT6129C,D*/      }
/*MT6129C,D*/   }
/*MT6129C,D*/   *ifN = 0;
/*MT6129C,D*/}
/*MT6129C,D*//* =========================================================================== */
/*MT6129C,D*/
/*MT6129C,D*/char mt6119_d_flag = 0;
/*MT6129C,D*/
/*MT6129C,D*/void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6129C,D*/{  int   Nfrac;
/*MT6129C,D*/
/*MT6129C,D*/   switch(rf_band)
/*MT6129C,D*/   {
/*MT6129C,D*/      case  FrequencyBand850 :
/*MT6129C,D*/      {
/*MT6129C,D*/         if(arfcn<=197)
/*MT6129C,D*/         {  if(arfcn<=147)
/*MT6129C,D*/            {  if(arfcn<=138)
/*MT6129C,D*/               {                                /* ARFCN : 128~138     */
/*MT6129C,D*/                  Nfrac = 88*(arfcn-128)+3848;
/*MT6129C,D*/                  *rfN = (5L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 1;
/*MT6129C,D*/               }
/*MT6129C,D*/               else
/*MT6129C,D*/               {                                /* ARFCN : 139~147     */
/*MT6129C,D*/                  Nfrac = 90*(arfcn-139)+2680;
/*MT6129C,D*/                  *rfN = (7L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 0;
/*MT6129C,D*/               }
/*MT6129C,D*/            }
/*MT6129C,D*/            else
/*MT6129C,D*/            {                                   /* ARFCN : 148~197     */
/*MT6129C,D*/                  Nfrac = 88*(arfcn-148)+408;
/*MT6129C,D*/                  *rfN = (6L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 1;
/*MT6129C,D*/            }
/*MT6129C,D*/         }
/*MT6129C,D*/         else
/*MT6129C,D*/         {  if(arfcn<=206)
/*MT6129C,D*/            {                                   /* ARFCN : 198~206   */
/*MT6129C,D*/                  Nfrac = 90*(arfcn-198)+2790;
/*MT6129C,D*/                  *rfN = (8L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 0;
/*MT6129C,D*/            }
/*MT6129C,D*/            else
/*MT6129C,D*/            {                                   /* ARFCN : 207~251 */
/*MT6129C,D*/                  Nfrac = 88*(arfcn-207)+400;
/*MT6129C,D*/                  *rfN = (7L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 1;
/*MT6129C,D*/            }
/*MT6129C,D*/         }
/*MT6129C,D*/         break;
/*MT6129C,D*/      }
/*MT6129C,D*/      case  FrequencyBand900 :
/*MT6129C,D*/      {
/*MT6129C,D*/         if(arfcn<=104)
/*MT6129C,D*/         {  if(arfcn<=45)
/*MT6129C,D*/            {  if(arfcn<=36)                     /* ARFCN : 0~36       */
/*MT6129C,D*/               {  Nfrac = 88*(arfcn-0)+1600;
/*MT6129C,D*/                  *rfN = (11L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 1;
/*MT6129C,D*/               }
/*MT6129C,D*/               else                             /* ARFCN : 37~45     */
/*MT6129C,D*/               {  Nfrac = 90*(arfcn-37)+3430;
/*MT6129C,D*/                  *rfN = (13L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 0;
/*MT6129C,D*/               }
/*MT6129C,D*/            }
/*MT6129C,D*/            else
/*MT6129C,D*/            {  if(arfcn<=95)                    /* ARFCN : 46~95     */
/*MT6129C,D*/               {  Nfrac = 88*(arfcn-46)+448;
/*MT6129C,D*/                  *rfN = (12L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 1;
/*MT6129C,D*/               }
/*MT6129C,D*/               else                             /* ARFCN : 96~104    */
/*MT6129C,D*/               {  Nfrac = 90*(arfcn-96)+3540;
/*MT6129C,D*/                  *rfN = (14L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 0;
/*MT6129C,D*/               }
/*MT6129C,D*/            }
/*MT6129C,D*/         }
/*MT6129C,D*/         else
/*MT6129C,D*/         {  if(arfcn<=1001)
/*MT6129C,D*/            {  if(arfcn<=124)                   /* ARFCN : 105~124   */
/*MT6129C,D*/               {  Nfrac = 88*(arfcn-105)+440;
/*MT6129C,D*/                  *rfN = (13L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 1;
/*MT6129C,D*/               }
/*MT6129C,D*/               else                             /* ARFCN : 975~1001  */
/*MT6129C,D*/               {  Nfrac = 88*(arfcn-975)+2488;
/*MT6129C,D*/                  *rfN = (10L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 1;
/*MT6129C,D*/               }
/*MT6129C,D*/            }
/*MT6129C,D*/            else
/*MT6129C,D*/            {  if(arfcn<=1010)                  /* ARFCN : 1002~1010 */
/*MT6129C,D*/               {  Nfrac = 90*(arfcn-1002)+3320;
/*MT6129C,D*/                  *rfN = (12L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 0;
/*MT6129C,D*/               }
/*MT6129C,D*/               else                             /* ARFCN : 1011~1023 */
/*MT6129C,D*/               {  Nfrac = 88*(arfcn-1011)+456;
/*MT6129C,D*/                  *rfN = (11L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 1;
/*MT6129C,D*/               }
/*MT6129C,D*/            }
/*MT6129C,D*/         }
/*MT6129C,D*/         break;
/*MT6129C,D*/      }
/*MT6129C,D*/      case  FrequencyBand1800 :
/*MT6129C,D*/      {
/*MT6129C,D*/         if(arfcn<=715)
/*MT6129C,D*/         {  if(arfcn<=597)
/*MT6129C,D*/            {  if(arfcn<=579)                   /* ARFCN : 512~579   */
/*MT6129C,D*/               {  Nfrac = 44*(arfcn-512)+1844;
/*MT6129C,D*/                  *rfN = (8L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 1;
/*MT6129C,D*/               }
/*MT6129C,D*/               else                             /* ARFCN : 580~597   */
/*MT6129C,D*/               {  Nfrac = 45*(arfcn-580)+3055;
/*MT6129C,D*/                  *rfN = (10L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 0;
/*MT6129C,D*/               }
/*MT6129C,D*/            }
/*MT6129C,D*/            else
/*MT6129C,D*/            {  if(arfcn<=697)                   /* ARFCN : 598~697   */
/*MT6129C,D*/               {  Nfrac = 44*(arfcn-598)+428;
/*MT6129C,D*/                  *rfN = (9L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 1;
/*MT6129C,D*/               }
/*MT6129C,D*/               else                             /* ARFCN : 698~715   */
/*MT6129C,D*/               {  Nfrac = 45*(arfcn-698)+3165;
/*MT6129C,D*/                  *rfN = (11L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 0;
/*MT6129C,D*/               }
/*MT6129C,D*/            }
/*MT6129C,D*/         }
/*MT6129C,D*/         else
/*MT6129C,D*/         {  if(arfcn<=833)
/*MT6129C,D*/            {  if(arfcn<=815)                   /* ARFCN : 716~815   */
/*MT6129C,D*/               {  Nfrac = 44*(arfcn-716)+420;
/*MT6129C,D*/                  *rfN = (10L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 1;
/*MT6129C,D*/               }
/*MT6129C,D*/               else                             /* ARFCN : 816~833   */
/*MT6129C,D*/               {  Nfrac = 45*(arfcn-816)+3275;
/*MT6129C,D*/                  *rfN = (12L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 0;
/*MT6129C,D*/               }
/*MT6129C,D*/            }
/*MT6129C,D*/            else                                /* ARFCN : 834~885   */
/*MT6129C,D*/            {  Nfrac = 44*(arfcn-834)+412;
/*MT6129C,D*/               *rfN = (11L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/               mt6119_d_flag = 1;
/*MT6129C,D*/            }
/*MT6129C,D*/         }
/*MT6129C,D*/         break;
/*MT6129C,D*/      }
/*MT6129C,D*/      case  FrequencyBand1900 :
/*MT6129C,D*/      {
/*MT6129C,D*/         if(arfcn<=706)
/*MT6129C,D*/         {  if(arfcn<=606)
/*MT6129C,D*/            {  if(arfcn<=588)                /* ARFCN : 512~588   */
/*MT6129C,D*/               {  Nfrac = 44*(arfcn-512)+1444;
/*MT6129C,D*/                  *rfN = (14L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 1;
/*MT6129C,D*/              }
/*MT6129C,D*/              else
/*MT6129C,D*/              {  Nfrac = 45*(arfcn-589)+3760;  /* ARFCN : 589~606   */
/*MT6129C,D*/                  *rfN = (16L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 0;
/*MT6129C,D*/               }
/*MT6129C,D*/            }
/*MT6129C,D*/            else                                /* ARFCN : 607~706   */
/*MT6129C,D*/            {  Nfrac = 44*(arfcn-607)+424;
/*MT6129C,D*/               *rfN = (15L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/               mt6119_d_flag = 1;
/*MT6129C,D*/            }
/*MT6129C,D*/         }
/*MT6129C,D*/         else
/*MT6129C,D*/         {  if(arfcn<=724)                      /* ARFCN : 707~724   */
/*MT6129C,D*/              {  Nfrac = 45*(arfcn-707)+3870;
/*MT6129C,D*/               *rfN = (17L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/               mt6119_d_flag = 0;
/*MT6129C,D*/            }
/*MT6129C,D*/            else                                /* ARFCN : 725~810   */
/*MT6129C,D*/            {  Nfrac = 44*(arfcn-725)+416;
/*MT6129C,D*/               *rfN = (16L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/               mt6119_d_flag = 1;
/*MT6129C,D*/            }
/*MT6129C,D*/         }
/*MT6129C,D*/         break;
/*MT6129C,D*/      }
/*MT6129C,D*/      default :
/*MT6129C,D*/      {
/*MT6129C,D*/         break;
/*MT6129C,D*/      }
/*MT6129C,D*/   }
/*MT6129C,D*/   *ifN = 0;
/*MT6129C,D*/}
/*MT6129C,D*//* =========================================================================== */
#endif

#if  (IS_RF_MT6139B)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/*MT6139E*/void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6139E*/{
/*MT6139E*/   switch(rf_band)
/*MT6139E*/   {
/*MT6139E*/      case  FrequencyBand850 :
/*MT6139E*/      {
/*MT6139E*/         if(arfcn<=201)
/*MT6139E*/         {  if(arfcn<=136)
/*MT6139E*/            {                                /* ARFCN : 128~136     */
/*MT6139E*/                *rfN = (66L<<12) | ((arfcn-72)<<5) | 0x400001L;
/*MT6139E*/            }
/*MT6139E*/            else
/*MT6139E*/            {                              /* ARFCN : 137~201     */
/*MT6139E*/                *rfN = (67L<<12) | ((arfcn-137)<<5) | 0x400001L;
/*MT6139E*/            }
/*MT6139E*/         }
/*MT6139E*/         else
/*MT6139E*/         {                                 /* ARFCN : 202~251     */
/*MT6139E*/                *rfN = (68L<<12) | ((arfcn-202)<<5) | 0x400001L;
/*MT6139E*/         }
/*MT6139E*/
/*MT6139E*/         // Get GSM850 signal from GSM900 input pins if flag=1
/*MT6139E*/         if( BBTXParameters.bbrx_gsm850_gsm900_swap ) *rfN |= 0x100000L;
/*MT6139E*/         break;
/*MT6139E*/      }
/*MT6139E*/      case  FrequencyBand900 :
/*MT6139E*/      {
/*MT6139E*/         if(arfcn<=69)
/*MT6139E*/         {  if(arfcn<=4)
/*MT6139E*/            {                                /* ARFCN : 0~4     */
/*MT6139E*/                *rfN = (71L<<12) | ((arfcn+60)<<5) | 0x100001L;
/*MT6139E*/            }
/*MT6139E*/            else
/*MT6139E*/            {                              /* ARFCN : 5~69     */
/*MT6139E*/                *rfN = (72L<<12) | ((arfcn-5)<<5) | 0x100001L;
/*MT6139E*/            }
/*MT6139E*/         }
/*MT6139E*/         else
/*MT6139E*/         {  if(arfcn<=124)
/*MT6139E*/            {                                /* ARFCN : 70~124     */
/*MT6139E*/                *rfN = (73L<<12) | ((arfcn-70)<<5) | 0x100001L;
/*MT6139E*/            }
/*MT6139E*/            else
/*MT6139E*/            {                              /* ARFCN : 975~1023     */
/*MT6139E*/                *rfN = (71L<<12) | ((arfcn-964)<<5) | 0x100001L;
/*MT6139E*/            }
/*MT6139E*/         }
/*MT6139E*/
/*MT6139E*/         // Get GSM900 signal from GSM850 input pins if flag=1
/*MT6139E*/         if( BBTXParameters.bbrx_gsm850_gsm900_swap )  *rfN &= (~(0x100000L));
/*MT6139E*/
/*MT6139E*/         break;
/*MT6139E*/      }
/*MT6139E*/      case  FrequencyBand1800 :
/*MT6139E*/      {
/*MT6139E*/         if(arfcn<=715)
/*MT6139E*/         {  if(arfcn<=585)
/*MT6139E*/            {                                /* ARFCN : 512~585     */
/*MT6139E*/                *rfN = (69L<<12) | ((arfcn-456)<<4) | 0x200001L;
/*MT6139E*/            }
/*MT6139E*/            else
/*MT6139E*/            {                              /* ARFCN : 586~715     */
/*MT6139E*/                *rfN = (70L<<12) | ((arfcn-586)<<4) | 0x200001L;
/*MT6139E*/            }
/*MT6139E*/         }
/*MT6139E*/         else
/*MT6139E*/         {  if(arfcn<=845)
/*MT6139E*/            {                                /* ARFCN : 716~845     */
/*MT6139E*/                *rfN = (71L<<12) | ((arfcn-716)<<4) | 0x200001L;
/*MT6139E*/            }
/*MT6139E*/            else
/*MT6139E*/            {                              /* ARFCN : 846~885     */
/*MT6139E*/                *rfN = (72L<<12) | ((arfcn-846)<<4) | 0x200001L;
/*MT6139E*/            }
/*MT6139E*/         }
/*MT6139E*/
/*MT6139E*/         // Get PCS1900 signal from DCS1800 input pins if flag=1
/*MT6139E*/         if( BBTXParameters.bbrx_dcs1800_pcs1900_swap ) *rfN |= 0x100000L;
/*MT6139E*/         break;
/*MT6139E*/      }
/*MT6139E*/      case  FrequencyBand1900 :
/*MT6139E*/      {
/*MT6139E*/         if(arfcn<=740)
/*MT6139E*/         {  if(arfcn<=610)
/*MT6139E*/            {                                /* ARFCN : 512~610     */
/*MT6139E*/                *rfN = (74L<<12) | ((arfcn-481)<<4) | 0x300001L;
/*MT6139E*/            }
/*MT6139E*/            else
/*MT6139E*/            {                               /* ARFCN : 611~740     */
/*MT6139E*/                *rfN = (75L<<12) | ((arfcn-611)<<4) | 0x300001L;
/*MT6139E*/            }
/*MT6139E*/         }
/*MT6139E*/         else
/*MT6139E*/         {
/*MT6139E*/                                            /* ARFCN : 741~810     */
/*MT6139E*/            *rfN = (76L<<12) | ((arfcn-741)<<4) | 0x300001L;
/*MT6139E*/
/*MT6139E*/         }
/*MT6139E*/
/*MT6139E*/         // Get DCS1800 signal from PCS1900 input pins if flag=1
/*MT6139E*/         if( BBTXParameters.bbrx_dcs1800_pcs1900_swap)  *rfN &= (~(0x100000L));
/*MT6139E*/         break;
/*MT6139E*/      }
/*MT6139E*/      default :
/*MT6139E*/      {
/*MT6139E*/         break;
/*MT6139E*/      }
/*MT6139E*/   }
/*MT6139E*/   *ifN = 0;
/*MT6139E*/}
/*MT6139E*//* =========================================================================== */
/*MT6139E*/
/*MT6139E*/void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6139E*/{
/*MT6139E*/   switch(rf_band)
/*MT6139E*/   {
/*MT6139E*/      case  FrequencyBand850 :
/*MT6139E*/      {
/*MT6139E*/         if(arfcn<=231)
/*MT6139E*/         {  if(arfcn<=166)
/*MT6139E*/            {                                /* ARFCN : 128~166     */
/*MT6139E*/                *rfN = (63L<<12) | ((arfcn-102)<<5) | 0x080001L; /* 0x080001L; */
/*MT6139E*/            }
/*MT6139E*/            else
/*MT6139E*/            {                              /* ARFCN : 167~231     */
/*MT6139E*/                *rfN = (64L<<12) | ((arfcn-167)<<5) | 0x080001L; /* 0x080001L; */
/*MT6139E*/            }
/*MT6139E*/         }
/*MT6139E*/         else
/*MT6139E*/         {                                 /* ARFCN : 232~251     */
/*MT6139E*/                *rfN = (65L<<12) | ((arfcn-232)<<5) | 0x080001L; /* 0x080001L; */
/*MT6139E*/         }
/*MT6139E*/
/*MT6139E*/         break;
/*MT6139E*/      }
/*MT6139E*/      case  FrequencyBand900 :
/*MT6139E*/      {
/*MT6139E*/         if(arfcn<=124)
/*MT6139E*/         {  if(arfcn<=99)
/*MT6139E*/            {  if(arfcn<=34)
/*MT6139E*/               {                                /* ARFCN : 0~34     */
/*MT6139E*/                   *rfN = (68L<<12) | ((arfcn+30)<<5) | 0x180001L; /* 0x180001L; */
/*MT6139E*/               }
/*MT6139E*/               else
/*MT6139E*/               {                                /* ARFCN : 35~99     */
/*MT6139E*/                   *rfN = (69L<<12) | ((arfcn-35)<<5) | 0x180001L; /* 0x180001L; */
/*MT6139E*/               }
/*MT6139E*/            }
/*MT6139E*/            else
/*MT6139E*/            {                              /* ARFCN : 100~124     */
/*MT6139E*/                *rfN = (70L<<12) | ((arfcn-100)<<5) | 0x180001L; /* 0x180001L; */
/*MT6139E*/            }
/*MT6139E*/         }
/*MT6139E*/         else
/*MT6139E*/         {  if(arfcn<=993)
/*MT6139E*/            {                                /* ARFCN : 975~993     */
/*MT6139E*/                *rfN = (67L<<12) | ((arfcn-929)<<5) | 0x180001L; /* 0x180001L; */
/*MT6139E*/            }
/*MT6139E*/            else
/*MT6139E*/            {                              /* ARFCN : 994~1023     */
/*MT6139E*/                *rfN = (68L<<12) | ((arfcn-994)<<5) | 0x180001L; /* 0x080001L; */
/*MT6139E*/            }
/*MT6139E*/         }
/*MT6139E*/
/*MT6139E*/         break;
/*MT6139E*/      }
/*MT6139E*/      case  FrequencyBand1800 :
/*MT6139E*/      {
/*MT6139E*/         if(arfcn<=670)
/*MT6139E*/         {  if(arfcn<=540)
/*MT6139E*/            {                                /* ARFCN : 512~540     */
/*MT6139E*/                *rfN = (65L<<12) | ((arfcn-411)<<4) | 0x680001L; /* 0x280001L; */
/*MT6139E*/            }
/*MT6139E*/            else
/*MT6139E*/            {                              /* ARFCN : 541~670     */
/*MT6139E*/                *rfN = (66L<<12) | ((arfcn-541)<<4) | 0x680001L; /* 0x280001L; */
/*MT6139E*/            }
/*MT6139E*/         }
/*MT6139E*/         else
/*MT6139E*/         {  if(arfcn<=800)
/*MT6139E*/            {                                /* ARFCN : 671~800     */
/*MT6139E*/                *rfN = (67L<<12) | ((arfcn-671)<<4) | 0x680001L; /* 0x280001L; */
/*MT6139E*/            }
/*MT6139E*/            else
/*MT6139E*/            {                              /* ARFCN : 801~885     */
/*MT6139E*/                *rfN = (68L<<12) | ((arfcn-801)<<4) | 0x680001L; /* 0x280001L; */
/*MT6139E*/            }
/*MT6139E*/         }
/*MT6139E*/
/*MT6139E*/         break;
/*MT6139E*/      }
/*MT6139E*/      case  FrequencyBand1900 :
/*MT6139E*/      {
/*MT6139E*/         if(arfcn<=750)
/*MT6139E*/         {  if(arfcn<=620)
/*MT6139E*/            {                                /* ARFCN : 512~620     */
/*MT6139E*/                *rfN = (71L<<12) | ((arfcn-491)<<4) | 0x780001L; /* 0x380001L; */
/*MT6139E*/            }
/*MT6139E*/            else
/*MT6139E*/            {                               /* ARFCN : 621~750     */
/*MT6139E*/                *rfN = (72L<<12) | ((arfcn-621)<<4) | 0x780001L; /* 0x380001L; */
/*MT6139E*/            }
/*MT6139E*/         }
/*MT6139E*/         else
/*MT6139E*/         {
/*MT6139E*/                                            /* ARFCN : 751~810     */
/*MT6139E*/            *rfN = (73L<<12) | ((arfcn-751)<<4) | 0x780001L; /* 0x380001L; */
/*MT6139E*/
/*MT6139E*/         }
/*MT6139E*/
/*MT6139E*/         break;
/*MT6139E*/      }
/*MT6139E*/      default :
/*MT6139E*/      {
/*MT6139E*/         break;
/*MT6139E*/      }
/*MT6139E*/   }
/*MT6139E*/   *ifN = 0;
/*MT6139E*/}
/*MT6139E*//* =========================================================================== */
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/*MT6140D*/void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6140D*/{
/*MT6140D*/   switch(rf_band)
/*MT6140D*/   {
/*MT6140D*/      case  FrequencyBand850 :
/*MT6140D*/      {
/*MT6140D*/         if(arfcn<=201)
/*MT6140D*/         {  if(arfcn<=136)
/*MT6140D*/            {                                /* ARFCN : 128~136     */
/*MT6140D*/                *rfN = (66L<<12) | ((arfcn-72)<<5) | 0x000001L;
/*MT6140D*/            }
/*MT6140D*/            else
/*MT6140D*/            {                              /* ARFCN : 137~201     */
/*MT6140D*/                *rfN = (67L<<12) | ((arfcn-137)<<5) | 0x000001L;
/*MT6140D*/            }
/*MT6140D*/         }
/*MT6140D*/         else
/*MT6140D*/         {                                 /* ARFCN : 202~251     */
/*MT6140D*/                *rfN = (68L<<12) | ((arfcn-202)<<5) | 0x000001L;
/*MT6140D*/         }
/*MT6140D*/
/*MT6140D*/         // Get GSM850 signal from GSM900 input pins if flag=1
/*MT6140D*/         if( BBTXParameters.bbrx_gsm850_gsm900_swap ) *rfN |= 0x100000L;
/*MT6140D*/         break;
/*MT6140D*/      }
/*MT6140D*/      case  FrequencyBand900 :
/*MT6140D*/      {
/*MT6140D*/         if(arfcn<=69)
/*MT6140D*/         {  if(arfcn<=4)
/*MT6140D*/            {                                /* ARFCN : 0~4     */
/*MT6140D*/                *rfN = (71L<<12) | ((arfcn+60)<<5) | 0x100001L;
/*MT6140D*/            }
/*MT6140D*/            else
/*MT6140D*/            {                              /* ARFCN : 5~69     */
/*MT6140D*/                *rfN = (72L<<12) | ((arfcn-5)<<5) | 0x100001L;
/*MT6140D*/            }
/*MT6140D*/         }
/*MT6140D*/         else
/*MT6140D*/         {  if(arfcn<=124)
/*MT6140D*/            {                                /* ARFCN : 70~124     */
/*MT6140D*/                *rfN = (73L<<12) | ((arfcn-70)<<5) | 0x100001L;
/*MT6140D*/            }
/*MT6140D*/            else
/*MT6140D*/            {                              /* ARFCN : 975~1023     */
/*MT6140D*/                *rfN = (71L<<12) | ((arfcn-964)<<5) | 0x100001L;
/*MT6140D*/            }
/*MT6140D*/         }
/*MT6140D*/
/*MT6140D*/         // Get GSM900 signal from GSM850 input pins if flag=1
/*MT6140D*/         if( BBTXParameters.bbrx_gsm850_gsm900_swap )  *rfN &= (~(0x100000L));
/*MT6140D*/         break;
/*MT6140D*/      }
/*MT6140D*/      case  FrequencyBand1800 :
/*MT6140D*/      {
/*MT6140D*/         if(arfcn<=715)
/*MT6140D*/         {  if(arfcn<=585)
/*MT6140D*/            {                                /* ARFCN : 512~585     */
/*MT6140D*/                *rfN = (69L<<12) | ((arfcn-456)<<4) | 0x200001L;
/*MT6140D*/            }
/*MT6140D*/            else
/*MT6140D*/            {                              /* ARFCN : 586~715     */
/*MT6140D*/                *rfN = (70L<<12) | ((arfcn-586)<<4) | 0x200001L;
/*MT6140D*/            }
/*MT6140D*/         }
/*MT6140D*/         else
/*MT6140D*/         {  if(arfcn<=845)
/*MT6140D*/            {                                /* ARFCN : 716~845     */
/*MT6140D*/                *rfN = (71L<<12) | ((arfcn-716)<<4) | 0x200001L;
/*MT6140D*/            }
/*MT6140D*/            else
/*MT6140D*/            {                              /* ARFCN : 846~885     */
/*MT6140D*/                *rfN = (72L<<12) | ((arfcn-846)<<4) | 0x200001L;
/*MT6140D*/            }
/*MT6140D*/         }
/*MT6140D*/
/*MT6140D*/         // Get PCS1900 signal from DCS1800 input pins if flag=1
/*MT6140D*/         if( BBTXParameters.bbrx_dcs1800_pcs1900_swap ) *rfN |= 0x100000L;
/*MT6140D*/         break;
/*MT6140D*/      }
/*MT6140D*/      case  FrequencyBand1900 :
/*MT6140D*/      {
/*MT6140D*/         if(arfcn<=740)
/*MT6140D*/         {  if(arfcn<=610)
/*MT6140D*/            {                                /* ARFCN : 512~610     */
/*MT6140D*/                *rfN = (74L<<12) | ((arfcn-481)<<4) | 0x300001L;
/*MT6140D*/            }
/*MT6140D*/            else
/*MT6140D*/            {                               /* ARFCN : 611~740     */
/*MT6140D*/                *rfN = (75L<<12) | ((arfcn-611)<<4) | 0x300001L;
/*MT6140D*/            }
/*MT6140D*/         }
/*MT6140D*/         else
/*MT6140D*/         {
/*MT6140D*/                                            /* ARFCN : 741~810     */
/*MT6140D*/            *rfN = (76L<<12) | ((arfcn-741)<<4) | 0x300001L;
/*MT6140D*/
/*MT6140D*/         }
/*MT6140D*/
/*MT6140D*/         // Get DCS1800 signal from PCS1900 input pins if flag=1
/*MT6140D*/         if( BBTXParameters.bbrx_dcs1800_pcs1900_swap)  *rfN &= (~(0x100000L));
/*MT6140D*/         break;
/*MT6140D*/      }
/*MT6140D*/      default :
/*MT6140D*/      {
/*MT6140D*/         break;
/*MT6140D*/      }
/*MT6140D*/   }
/*MT6140D*/   *ifN = 0;
/*MT6140D*/}
/*MT6140D*//* =========================================================================== */
/*MT6140D*/
/*MT6140D*/void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6140D*/{
/*MT6140D*/   switch(rf_band)
/*MT6140D*/   {
/*MT6140D*/      case  FrequencyBand850 :
/*MT6140D*/      {
/*MT6140D*/         if(arfcn<=231)
/*MT6140D*/         {  if(arfcn<=166)
/*MT6140D*/            {                                /* ARFCN : 128~166     */
/*MT6140D*/                *rfN = (63L<<12) | ((arfcn-102)<<5) | 0x480001L; /* 0x080001L; */
/*MT6140D*/            }
/*MT6140D*/            else
/*MT6140D*/            {                              /* ARFCN : 167~231     */
/*MT6140D*/                *rfN = (64L<<12) | ((arfcn-167)<<5) | 0x480001L; /* 0x080001L; */
/*MT6140D*/            }
/*MT6140D*/         }
/*MT6140D*/         else
/*MT6140D*/         {                                 /* ARFCN : 232~251     */
/*MT6140D*/                *rfN = (65L<<12) | ((arfcn-232)<<5) | 0x480001L; /* 0x080001L; */
/*MT6140D*/         }
/*MT6140D*/
/*MT6140D*/         break;
/*MT6140D*/      }
/*MT6140D*/      case  FrequencyBand900 :
/*MT6140D*/      {
/*MT6140D*/         if(arfcn<=124)
/*MT6140D*/         {  if(arfcn<=99)
/*MT6140D*/            {  if(arfcn<=34)
/*MT6140D*/               {                                /* ARFCN : 0~34     */
/*MT6140D*/                   *rfN = (68L<<12) | ((arfcn+30)<<5) | 0x580001L; /* 0x180001L; */
/*MT6140D*/               }
/*MT6140D*/               else
/*MT6140D*/               {                                /* ARFCN : 35~99     */
/*MT6140D*/                   *rfN = (69L<<12) | ((arfcn-35)<<5) | 0x580001L; /* 0x180001L; */
/*MT6140D*/               }
/*MT6140D*/            }
/*MT6140D*/            else
/*MT6140D*/            {                              /* ARFCN : 100~124     */
/*MT6140D*/                *rfN = (70L<<12) | ((arfcn-100)<<5) | 0x580001L; /* 0x180001L; */
/*MT6140D*/            }
/*MT6140D*/         }
/*MT6140D*/         else
/*MT6140D*/         {  if(arfcn<=993)
/*MT6140D*/            {                                /* ARFCN : 975~993     */
/*MT6140D*/                *rfN = (67L<<12) | ((arfcn-929)<<5) | 0x580001L; /* 0x180001L; */
/*MT6140D*/            }
/*MT6140D*/            else
/*MT6140D*/            {                              /* ARFCN : 994~1023     */
/*MT6140D*/                *rfN = (68L<<12) | ((arfcn-994)<<5) | 0x580001L; /* 0x080001L; */
/*MT6140D*/            }
/*MT6140D*/         }
/*MT6140D*/
/*MT6140D*/         break;
/*MT6140D*/      }
/*MT6140D*/      case  FrequencyBand1800 :
/*MT6140D*/      {
/*MT6140D*/         if(arfcn<=670)
/*MT6140D*/         {  if(arfcn<=540)
/*MT6140D*/            {                                /* ARFCN : 512~540     */
/*MT6140D*/                *rfN = (65L<<12) | ((arfcn-411)<<4) | 0x680001L; /* 0x280001L; */
/*MT6140D*/            }
/*MT6140D*/            else
/*MT6140D*/            {                              /* ARFCN : 541~670     */
/*MT6140D*/                *rfN = (66L<<12) | ((arfcn-541)<<4) | 0x680001L; /* 0x280001L; */
/*MT6140D*/            }
/*MT6140D*/         }
/*MT6140D*/         else
/*MT6140D*/         {  if(arfcn<=800)
/*MT6140D*/            {                                /* ARFCN : 671~800     */
/*MT6140D*/                *rfN = (67L<<12) | ((arfcn-671)<<4) | 0x680001L; /* 0x280001L; */
/*MT6140D*/            }
/*MT6140D*/            else
/*MT6140D*/            {                              /* ARFCN : 801~885     */
/*MT6140D*/                *rfN = (68L<<12) | ((arfcn-801)<<4) | 0x680001L; /* 0x280001L; */
/*MT6140D*/            }
/*MT6140D*/         }
/*MT6140D*/
/*MT6140D*/         break;
/*MT6140D*/      }
/*MT6140D*/      case  FrequencyBand1900 :
/*MT6140D*/      {
/*MT6140D*/         if(arfcn<=750)
/*MT6140D*/         {  if(arfcn<=620)
/*MT6140D*/            {                                /* ARFCN : 512~620     */
/*MT6140D*/                *rfN = (71L<<12) | ((arfcn-491)<<4) | 0x780001L; /* 0x380001L; */
/*MT6140D*/            }
/*MT6140D*/            else
/*MT6140D*/            {                               /* ARFCN : 621~750     */
/*MT6140D*/                *rfN = (72L<<12) | ((arfcn-621)<<4) | 0x780001L; /* 0x380001L; */
/*MT6140D*/            }
/*MT6140D*/         }
/*MT6140D*/         else
/*MT6140D*/         {
/*MT6140D*/                                            /* ARFCN : 751~810     */
/*MT6140D*/            *rfN = (73L<<12) | ((arfcn-751)<<4) | 0x780001L; /* 0x380001L; */
/*MT6140D*/
/*MT6140D*/         }
/*MT6140D*/
/*MT6140D*/         break;
/*MT6140D*/      }
/*MT6140D*/      default :
/*MT6140D*/      {
/*MT6140D*/         break;
/*MT6140D*/      }
/*MT6140D*/   }
/*MT6140D*/   *ifN = 0;
/*MT6140D*/}
/*MT6140D*//* =========================================================================== */
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/*MTKSOC1*/void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MTKSOC1*/{
/*MTKSOC1*/ int Nfrac, SDM_IFM = 1, OPLL_DIV4O5_DIV4 = 0;
/*MTKSOC1*/ switch(rf_band)
/*MTKSOC1*/ {
/*MTKSOC1*/ case  FrequencyBand850 :
/*MTKSOC1*/    {
/*MTKSOC1*/       if(arfcn<=189)
/*MTKSOC1*/       {
/*MTKSOC1*/          if(arfcn<=160)
/*MTKSOC1*/          {
/*MTKSOC1*/             if(arfcn<=131)
/*MTKSOC1*/             {                                /* ARFCN : 128~131     */
/*MTKSOC1*/                Nfrac = (arfcn-128)*286790 + 7456540;
/*MTKSOC1*/                *rfN = (140L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/             }
/*MTKSOC1*/             else
/*MTKSOC1*/             {                                /* ARFCN : 132~160     */
/*MTKSOC1*/                Nfrac = (arfcn-132)*286790 + 215093;
/*MTKSOC1*/                *rfN = (141L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/             }
/*MTKSOC1*/          }
/*MTKSOC1*/          else
/*MTKSOC1*/          {                              /* ARFCN : 161~189     */
/*MTKSOC1*/             Nfrac = (arfcn-161)*286790 + 143395;
/*MTKSOC1*/             *rfN = (142L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/          }
/*MTKSOC1*/       }
/*MTKSOC1*/       else
/*MTKSOC1*/       {
/*MTKSOC1*/          if(arfcn<=218)
/*MTKSOC1*/          {                              /* ARFCN : 190~218     */
/*MTKSOC1*/             Nfrac = (arfcn-190)*286790 + 71698;
/*MTKSOC1*/             *rfN = (143L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/          }
/*MTKSOC1*/          else
/*MTKSOC1*/          {
/*MTKSOC1*/             if(arfcn<=248)
/*MTKSOC1*/             {                                /* ARFCN : 219~248     */
/*MTKSOC1*/                Nfrac = (arfcn-219)*286790;
/*MTKSOC1*/                *rfN = (144L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/
/*MTKSOC1*/                if(arfcn == 219)
/*MTKSOC1*/                   SDM_IFM = 0;
/*MTKSOC1*/             }
/*MTKSOC1*/             else
/*MTKSOC1*/             {                                /* ARFCN : 249~251     */
/*MTKSOC1*/                Nfrac = (arfcn-249)*286790 + 215093;
/*MTKSOC1*/                *rfN = (145L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/             }
/*MTKSOC1*/          }
/*MTKSOC1*/       }
/*MTKSOC1*/
/*MTKSOC1*/       *ifN = (Nfrac>>10) | 0x0242000L;                       /* N_FRAC[22:10] | (CW2|OPLL_DIV4O5_DIV4|TRX|BAND|MODE(warm_up mode))*/
/*MTKSOC1*/       *rfN |= ((Nfrac&0x3FF) | 0x0180000L | (SDM_IFM<<18) ); /* N_INT[7:0] | N_FRAC[9:0] | (CW1|OPLL_HLSIDE)| SDM_IFM)*/
/*MTKSOC1*/
/*MTKSOC1*/       break;
/*MTKSOC1*/    }
/*MTKSOC1*/ case  FrequencyBand900 :
/*MTKSOC1*/    {
/*MTKSOC1*/       if(arfcn<=112)
/*MTKSOC1*/       {
/*MTKSOC1*/          if(arfcn<=54)
/*MTKSOC1*/          {
/*MTKSOC1*/             if(arfcn<=25)
/*MTKSOC1*/             {                                /* ARFCN : 0~25     */
/*MTKSOC1*/                Nfrac = (arfcn)*286790 + 1147160;
/*MTKSOC1*/                *rfN = (152L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/             }
/*MTKSOC1*/             else
/*MTKSOC1*/             {                                /* ARFCN : 26~54     */
/*MTKSOC1*/                Nfrac = (arfcn-26)*286790 + 215093;
/*MTKSOC1*/                *rfN = (153L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/             }
/*MTKSOC1*/          }
/*MTKSOC1*/          else
/*MTKSOC1*/          {
/*MTKSOC1*/             if(arfcn<=83)
/*MTKSOC1*/             {                                /* ARFCN : 55~83     */
/*MTKSOC1*/                Nfrac = (arfcn-55)*286790 + 143395;
/*MTKSOC1*/                *rfN = (154L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/             }
/*MTKSOC1*/             else
/*MTKSOC1*/             {                                /* ARFCN : 84~112     */
/*MTKSOC1*/                Nfrac = (arfcn-84)*286790 + 71698;
/*MTKSOC1*/                *rfN = (155L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/             }
/*MTKSOC1*/          }
/*MTKSOC1*/       }
/*MTKSOC1*/       else
/*MTKSOC1*/       {
/*MTKSOC1*/          if(arfcn<=990)
/*MTKSOC1*/          {
/*MTKSOC1*/             if(arfcn<=124)
/*MTKSOC1*/             {                                /* ARFCN : 113~124     */
/*MTKSOC1*/                Nfrac = (arfcn-113)*286790;
/*MTKSOC1*/                *rfN = (156L<<10);
/*MTKSOC1*/
/*MTKSOC1*/                if(arfcn == 113)
/*MTKSOC1*/                   SDM_IFM = 0;
/*MTKSOC1*/
/*MTKSOC1*/             }
/*MTKSOC1*/             else
/*MTKSOC1*/             {                              /* ARFCN : 975~990     */
/*MTKSOC1*/                Nfrac = (arfcn-975)*286790 + 3871665;
/*MTKSOC1*/                *rfN = (150L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/             }
/*MTKSOC1*/          }
/*MTKSOC1*/          else
/*MTKSOC1*/          {
/*MTKSOC1*/             if(arfcn<=1019)
/*MTKSOC1*/             {                                /* ARFCN : 991~1019     */
/*MTKSOC1*/                Nfrac = (arfcn-991)*286790 + 71698;
/*MTKSOC1*/                *rfN = (151L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/             }
/*MTKSOC1*/             else
/*MTKSOC1*/             {                                /* ARFCN : 1020~1023     */
/*MTKSOC1*/                Nfrac = (arfcn-1020)*286790;
/*MTKSOC1*/                *rfN = (152L<<10);
/*MTKSOC1*/
/*MTKSOC1*/                if(arfcn == 1020)
/*MTKSOC1*/                   SDM_IFM = 0;
/*MTKSOC1*/             }
/*MTKSOC1*/          }
/*MTKSOC1*/       }
/*MTKSOC1*/       *ifN = (Nfrac>>10) | 0x0252000L;                       /* N_FRAC[22:10] | (CW2|OPLL_DIV4O5_DIV4|TRX|BAND|MODE(warm_up mode))*/
/*MTKSOC1*/       *rfN |= ((Nfrac&0x3FF) | 0x0180000L | (SDM_IFM<<18) ); /* N_INT[7:0] | N_FRAC[9:0] | (CW1|OPLL_HLSIDE)| SDM_IFM)*/
/*MTKSOC1*/
/*MTKSOC1*/       break;
/*MTKSOC1*/    }
/*MTKSOC1*/ case  FrequencyBand1800 :
/*MTKSOC1*/    {
/*MTKSOC1*/       if(arfcn<=670)
/*MTKSOC1*/       {
/*MTKSOC1*/          if(arfcn<=603)
/*MTKSOC1*/          {
/*MTKSOC1*/             if(arfcn<=547)
/*MTKSOC1*/             {
/*MTKSOC1*/                if(arfcn<=541)
/*MTKSOC1*/                { /* ARFCN : 512~541 */
/*MTKSOC1*/                   Nfrac = (arfcn-529)*135848 + 6316927;
/*MTKSOC1*/                   *rfN = (138L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/
/*MTKSOC1*/                   /*error compensation*/
/*MTKSOC1*/                    L1D_RF_Band1800_FrequecyFractionPartCompensation(arfcn, &Nfrac, 0, 0, 519, 529, 540, 542);
/*MTKSOC1*/                   /*End: error compensation*/
/*MTKSOC1*/
/*MTKSOC1*/                }
/*MTKSOC1*/                else
/*MTKSOC1*/                { /* ARFCN : 542~547 */
/*MTKSOC1*/                   Nfrac = (arfcn-542)*137659 + 6848546;
/*MTKSOC1*/                   *rfN = (140L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/                   OPLL_DIV4O5_DIV4 = 1;
/*MTKSOC1*/
/*MTKSOC1*/                   /*error compensation*/
/*MTKSOC1*/                   if(arfcn>=547)
/*MTKSOC1*/                      Nfrac++;
/*MTKSOC1*/                   /*End: error compensation*/
/*MTKSOC1*/
/*MTKSOC1*/                }
/*MTKSOC1*/
/*MTKSOC1*/             }
/*MTKSOC1*/             else
/*MTKSOC1*/             { /* ARFCN : 548~603 */
/*MTKSOC1*/                Nfrac = (arfcn-581)*135848 + 4992410;
/*MTKSOC1*/                *rfN = (139L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/
/*MTKSOC1*/                /*error compensation*/
/*MTKSOC1*/                L1D_RF_Band1800_FrequecyFractionPartCompensation(arfcn, &Nfrac, 550, 560, 570, 581, 591, 601);
/*MTKSOC1*/                /*End: error compensation*/
/*MTKSOC1*/
/*MTKSOC1*/             }
/*MTKSOC1*/          }
/*MTKSOC1*/          else
/*MTKSOC1*/          {
/*MTKSOC1*/             if(arfcn<=665)
/*MTKSOC1*/             {
/*MTKSOC1*/                if(arfcn<=608)
/*MTKSOC1*/                { /* ARFCN : 604~608 */
/*MTKSOC1*/                   Nfrac = (arfcn-604)*137659 + 6994809;
/*MTKSOC1*/                   *rfN = (141L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/                   OPLL_DIV4O5_DIV4 = 1;
/*MTKSOC1*/
/*MTKSOC1*/                   /*error compensation*/
/*MTKSOC1*/                   /*End: error compensation*/
/*MTKSOC1*/                }
/*MTKSOC1*/                else
/*MTKSOC1*/                { /* ARFCN : 609~665 */
/*MTKSOC1*/                   Nfrac = (arfcn-643)*135848 + 5026372;
/*MTKSOC1*/                   *rfN = (140L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/
/*MTKSOC1*/                   /*error compensation*/
/*MTKSOC1*/                   L1D_RF_Band1800_FrequecyFractionPartCompensation(arfcn, &Nfrac, 612, 622, 632, 643, 653, 663);
/*MTKSOC1*/                   /*End: error compensation*/
/*MTKSOC1*/                }
/*MTKSOC1*/             }
/*MTKSOC1*/             else
/*MTKSOC1*/             { /* ARFCN : 666~670 */
/*MTKSOC1*/                Nfrac = (arfcn-666)*137659 + 7141071;
/*MTKSOC1*/                *rfN = (142L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/                OPLL_DIV4O5_DIV4 = 1;
/*MTKSOC1*/
/*MTKSOC1*/                /*error compensation*/
/*MTKSOC1*/                if(arfcn>=667)
/*MTKSOC1*/                   Nfrac++;
/*MTKSOC1*/                /*End: error compensation*/
/*MTKSOC1*/             }
/*MTKSOC1*/          }
/*MTKSOC1*/       }
/*MTKSOC1*/       else
/*MTKSOC1*/       {
/*MTKSOC1*/          if(arfcn<=788)
/*MTKSOC1*/          {
/*MTKSOC1*/             if(arfcn<=732)
/*MTKSOC1*/             {
/*MTKSOC1*/                if(arfcn<=726)
/*MTKSOC1*/                {/* ARFCN : 671~726 */
/*MTKSOC1*/                   Nfrac = (arfcn-704)*135848 + 4924486;
/*MTKSOC1*/                   *rfN = (141L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/
/*MTKSOC1*/                   /*error compensation*/
/*MTKSOC1*/                   L1D_RF_Band1800_FrequecyFractionPartCompensation(arfcn, &Nfrac, 673, 684, 694, 704, 715, 725);
/*MTKSOC1*/                   /*End: error compensation*/
/*MTKSOC1*/                }
/*MTKSOC1*/                else
/*MTKSOC1*/                {/*ARFCN:727~732*/
/*MTKSOC1*/                   Nfrac = (arfcn-727)*137659 + 7149675;
/*MTKSOC1*/                   *rfN = (143L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/                   OPLL_DIV4O5_DIV4 = 1;
/*MTKSOC1*/
/*MTKSOC1*/                   /*error compensation*/
/*MTKSOC1*/                   if(arfcn>=729)
/*MTKSOC1*/                      Nfrac++;
/*MTKSOC1*/                   /*End: error compensation*/
/*MTKSOC1*/
/*MTKSOC1*/                }
/*MTKSOC1*/             }
/*MTKSOC1*/             else
/*MTKSOC1*/             {/*ARFCN:733~788*/
/*MTKSOC1*/                Nfrac = (arfcn-766)*135848 + 4958448;
/*MTKSOC1*/                *rfN = (142L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/
/*MTKSOC1*/                /*error compensation*/
/*MTKSOC1*/                L1D_RF_Band1800_FrequecyFractionPartCompensation(arfcn, &Nfrac, 735, 745, 756, 766, 776, 786);
/*MTKSOC1*/                /*End: error compensation*/
/*MTKSOC1*/             }
/*MTKSOC1*/          }
/*MTKSOC1*/          else
/*MTKSOC1*/          {
/*MTKSOC1*/             if(arfcn<=850)
/*MTKSOC1*/             {
/*MTKSOC1*/                if(arfcn<=794)
/*MTKSOC1*/                {/*ARFCN:789~794*/
/*MTKSOC1*/                   Nfrac = (arfcn-789)*137659 + 7295938;
/*MTKSOC1*/                   *rfN = (144L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/                   OPLL_DIV4O5_DIV4 = 1;
/*MTKSOC1*/
/*MTKSOC1*/                   /*error compensation*/
/*MTKSOC1*/                   if(arfcn>=792)
/*MTKSOC1*/                      Nfrac++;
/*MTKSOC1*/                   /*End: error compensation*/
/*MTKSOC1*/                }
/*MTKSOC1*/                else
/*MTKSOC1*/                {/*ARFCN:795~850*/
/*MTKSOC1*/                   Nfrac = (arfcn-828)*135848 + 4992410;
/*MTKSOC1*/                   *rfN = (143L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/                   /*error compensation*/
/*MTKSOC1*/                   L1D_RF_Band1800_FrequecyFractionPartCompensation(arfcn, &Nfrac, 797, 806, 817, 828, 838, 848);
/*MTKSOC1*/                   /*End:*error compensation*/
/*MTKSOC1*/                }
/*MTKSOC1*/             }
/*MTKSOC1*/             else
/*MTKSOC1*/             {
/*MTKSOC1*/                if(arfcn<=855)
/*MTKSOC1*/                {/*ARFCN:851~855*/
/*MTKSOC1*/                   Nfrac = (arfcn-851)*137659 + 7442201;
/*MTKSOC1*/                   *rfN = (145L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/                   OPLL_DIV4O5_DIV4 = 1;
/*MTKSOC1*/
/*MTKSOC1*/                   /*error compensation*/
/*MTKSOC1*/                   if(arfcn>=854)
/*MTKSOC1*/                      Nfrac++;
/*MTKSOC1*/                   /*End: error compensation*/
/*MTKSOC1*/                }
/*MTKSOC1*/                else
/*MTKSOC1*/                {/*ARFCN:856~885*/
/*MTKSOC1*/                   Nfrac = (arfcn-869)*135848 + 2173566;
/*MTKSOC1*/                   *rfN = (144L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/
/*MTKSOC1*/                   /*error compensation*/
/*MTKSOC1*/                   L1D_RF_Band1800_FrequecyFractionPartCompensation(arfcn, &Nfrac, 0, 0, 859, 869, 879, 885);
/*MTKSOC1*/                   /*End: error compensation*/
/*MTKSOC1*/                }
/*MTKSOC1*/             }
/*MTKSOC1*/          }
/*MTKSOC1*/       }
/*MTKSOC1*/       *ifN = (Nfrac>>10) | 0x0262000L | (OPLL_DIV4O5_DIV4<<19);                       /* N_FRAC[22:10] | (CW2|OPLL_DIV4O5_DIV4|TRX|BAND|MODE(warm_up mode))*/
/*MTKSOC1*/       *rfN |= ((Nfrac&0x3FF) | 0x01C0000L); /* N_INT[7:0] | N_FRAC[9:0] | (CW1|OPLL_HLSIDE)| SDM_IFM)*/
/*MTKSOC1*/       break;
/*MTKSOC1*/      }
/*MTKSOC1*/      case  FrequencyBand1900 :
/*MTKSOC1*/      {
/*MTKSOC1*/         if(arfcn<=676)
/*MTKSOC1*/         {
/*MTKSOC1*/            if(arfcn<=546)
/*MTKSOC1*/            {
/*MTKSOC1*/               if(arfcn<=540)
/*MTKSOC1*/               { /*ARFCN:512~540*/
/*MTKSOC1*/                  Nfrac = (arfcn-512)*122910 + 4578398;
/*MTKSOC1*/                  *rfN = (135L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/               }
/*MTKSOC1*/               else
/*MTKSOC1*/               { /*ARFCN:541~546*/
/*MTKSOC1*/                  Nfrac = (arfcn-541)*121464 + 3112515;
/*MTKSOC1*/                  *rfN = (134L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/                  OPLL_DIV4O5_DIV4 = 1;
/*MTKSOC1*/               }
/*MTKSOC1*/            }
/*MTKSOC1*/            else
/*MTKSOC1*/            {
/*MTKSOC1*/               if(arfcn<=614)
/*MTKSOC1*/               {
/*MTKSOC1*/                  if(arfcn<=608)
/*MTKSOC1*/                  { /*ARFCN:547~608*/
/*MTKSOC1*/                     Nfrac = (arfcn-547)*122910 + 491640;
/*MTKSOC1*/                     *rfN = (136L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/                  }
/*MTKSOC1*/                  else
/*MTKSOC1*/                  { /*ARFCN:609~614*/
/*MTKSOC1*/                     Nfrac = (arfcn-609)*121464 + 2983460;
/*MTKSOC1*/                     *rfN = (135L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/                     OPLL_DIV4O5_DIV4 = 1;
/*MTKSOC1*/                  }
/*MTKSOC1*/               }
/*MTKSOC1*/               else
/*MTKSOC1*/               { /*ARFCN:615~676*/
/*MTKSOC1*/                  Nfrac = (arfcn-615)*122910 + 460913;
/*MTKSOC1*/                  *rfN = (137L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/               }
/*MTKSOC1*/            }
/*MTKSOC1*/         }
/*MTKSOC1*/         else
/*MTKSOC1*/         {
/*MTKSOC1*/            if(arfcn<=744)
/*MTKSOC1*/            {
/*MTKSOC1*/               if(arfcn<=682)
/*MTKSOC1*/               {/*ARFCN:677~682*/
/*MTKSOC1*/                  Nfrac = (arfcn-677)*121464 + 2854404;
/*MTKSOC1*/                  *rfN = (136L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/                  OPLL_DIV4O5_DIV4 = 1;
/*MTKSOC1*/               }
/*MTKSOC1*/               else
/*MTKSOC1*/               { /*ARFCN:683~744*/
/*MTKSOC1*/                  Nfrac = (arfcn-683)*122910 + 430185;
/*MTKSOC1*/                  *rfN = (138L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/               }
/*MTKSOC1*/            }
/*MTKSOC1*/            else
/*MTKSOC1*/            {
/*MTKSOC1*/               if(arfcn<=750)
/*MTKSOC1*/               {/*ARFCN:745~750*/
/*MTKSOC1*/                  Nfrac = (arfcn-745)*121464 + 2725349;
/*MTKSOC1*/                  *rfN = (137L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/                  OPLL_DIV4O5_DIV4 = 1;
/*MTKSOC1*/               }
/*MTKSOC1*/               else
/*MTKSOC1*/               { /*ARFCN:751~810*/
/*MTKSOC1*/                  Nfrac = (arfcn-751)*122910 + 399458;
/*MTKSOC1*/                  *rfN = (139L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/               }
/*MTKSOC1*/            }
/*MTKSOC1*/         }
/*MTKSOC1*/
/*MTKSOC1*/         *ifN = (Nfrac>>10) | 0x0272000L | (OPLL_DIV4O5_DIV4<<19);                       /* N_FRAC[22:10] | (CW2|OPLL_DIV4O5_DIV4|TRX|BAND|MODE(warm_up mode))*/
/*MTKSOC1*/         *rfN |= ((Nfrac&0x3FF) | 0x0140000L); /* N_INT[7:0] | N_FRAC[9:0] | (CW1|OPLL_HLSIDE)| SDM_IFM)*/
/*MTKSOC1*/         break;
/*MTKSOC1*/      }
/*MTKSOC1*/      default :
/*MTKSOC1*/      {
/*MTKSOC1*/         break;
/*MTKSOC1*/      }
/*MTKSOC1*/   }
/*MTKSOC1*/}
/*MTKSOC1*//* =============================================================== */
/*MTKSOC1*/
/*MTKSOC1*/void L1D_RF_Band1800_FrequecyFractionPartCompensation(int arfcn, int *Nfrac, short arfcn1, short arfcn2, short arfcn3, short arfcn4, short arfcn5, short arfcn6)
/*MTKSOC1*/{
/*MTKSOC1*/ if(arfcn<arfcn4)
/*MTKSOC1*/ {
/*MTKSOC1*/    if(arfcn<arfcn2)
/*MTKSOC1*/    {
/*MTKSOC1*/       if(arfcn<arfcn1)
/*MTKSOC1*/          *Nfrac+=4;
/*MTKSOC1*/       else
/*MTKSOC1*/          *Nfrac+=3;
/*MTKSOC1*/    }
/*MTKSOC1*/    else
/*MTKSOC1*/    {
/*MTKSOC1*/       if(arfcn<arfcn3)
/*MTKSOC1*/          *Nfrac+=2;
/*MTKSOC1*/       else
/*MTKSOC1*/          *Nfrac+=1;
/*MTKSOC1*/    }
/*MTKSOC1*/ }
/*MTKSOC1*/ else if (arfcn>=arfcn5)
/*MTKSOC1*/ {
/*MTKSOC1*/    if(arfcn<arfcn6)
/*MTKSOC1*/    {
/*MTKSOC1*/       *Nfrac-=1;
/*MTKSOC1*/    }
/*MTKSOC1*/    else
/*MTKSOC1*/    {
/*MTKSOC1*/       *Nfrac-=2;
/*MTKSOC1*/    }
/*MTKSOC1*/ }
/*MTKSOC1*/}
/*MTKSOC1*/
/*MTKSOC1*/void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MTKSOC1*/{
/*MTKSOC1*/   int Nfrac, SDM_IFM = 1;
/*MTKSOC1*/   switch(rf_band)
/*MTKSOC1*/   {
/*MTKSOC1*/   case  FrequencyBand850 :
/*MTKSOC1*/      {
/*MTKSOC1*/         if(arfcn<=201)
/*MTKSOC1*/         {
/*MTKSOC1*/            if(arfcn<=169)
/*MTKSOC1*/            {
/*MTKSOC1*/               if(arfcn<=136)
/*MTKSOC1*/               {/*arfcn:128~136*/
/*MTKSOC1*/                  Nfrac = (arfcn-128)*258111 + 6065609;
/*MTKSOC1*/                  *rfN = (133L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/               }
/*MTKSOC1*/               else
/*MTKSOC1*/               {/*arfcn:137~169*/
/*MTKSOC1*/                  Nfrac = (arfcn-137)*258111;
/*MTKSOC1*/                  *rfN = (134L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/
/*MTKSOC1*/               }
/*MTKSOC1*/            }
/*MTKSOC1*/            else
/*MTKSOC1*/            {/*arfcn:170~201*/
/*MTKSOC1*/               Nfrac = (arfcn-170)*258111+129056;
/*MTKSOC1*/               *rfN = (135L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/            }
/*MTKSOC1*/         }
/*MTKSOC1*/         else
/*MTKSOC1*/         {
/*MTKSOC1*/            if(arfcn<=234)
/*MTKSOC1*/            {/*arfcn:202~234*/
/*MTKSOC1*/               Nfrac = (arfcn-202)*258111;
/*MTKSOC1*/               *rfN = (136L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/            }
/*MTKSOC1*/            else
/*MTKSOC1*/            {/*arfcn:235~251*/
/*MTKSOC1*/               Nfrac = (arfcn-235)*258111+129056;
/*MTKSOC1*/               *rfN = (137L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/            }
/*MTKSOC1*/         }
/*MTKSOC1*/         *ifN = (Nfrac>>10)|0x0202000;  /* CW2, TRX:0, BAND:0, MODE:1, N_RFC[22:10]*/
/*MTKSOC1*/         if(Nfrac==0) SDM_IFM = 0;
/*MTKSOC1*/         *rfN |= ((Nfrac&0x3FF) | 0x0180000L | (SDM_IFM<<18) ); /* N_INT[7:0] | N_FRAC[9:0] | (CW1|OPLL_HLSIDE)| SDM_IFM)*/
/*MTKSOC1*/
/*MTKSOC1*/         // Get GSM850 signal from GSM900 input pins if flag=1
/*MTKSOC1*/         if( BBTXParameters.bbrx_gsm850_gsm900_swap ) *ifN |=0x0010000L ;
/*MTKSOC1*/         break;
/*MTKSOC1*/      }
/*MTKSOC1*/   case  FrequencyBand900 :
/*MTKSOC1*/      {
/*MTKSOC1*/         if(arfcn<=102)
/*MTKSOC1*/         {
/*MTKSOC1*/            if(arfcn<=37)
/*MTKSOC1*/            {
/*MTKSOC1*/               if(arfcn<=4)
/*MTKSOC1*/               {/*arfcn:0~4*/
/*MTKSOC1*/                  Nfrac = (arfcn)*258111+7098053;
/*MTKSOC1*/                  *rfN = (143L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/               }
/*MTKSOC1*/               else
/*MTKSOC1*/               {/*arfcn:5~37*/
/*MTKSOC1*/                  Nfrac = (arfcn-5)*258111;
/*MTKSOC1*/                  *rfN = (144L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/               }
/*MTKSOC1*/            }
/*MTKSOC1*/            else
/*MTKSOC1*/            {
/*MTKSOC1*/               if(arfcn<=69)
/*MTKSOC1*/               {/*arfcn:38~69*/
/*MTKSOC1*/                  Nfrac = (arfcn-38)*258111+129056;
/*MTKSOC1*/                  *rfN = (145L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/               }
/*MTKSOC1*/               else
/*MTKSOC1*/               {/*arfcn:70~102*/
/*MTKSOC1*/                  Nfrac = (arfcn-70)*258111;
/*MTKSOC1*/                  *rfN = (146L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/               }
/*MTKSOC1*/            }
/*MTKSOC1*/         }
/*MTKSOC1*/         else
/*MTKSOC1*/         {
/*MTKSOC1*/            if(arfcn<=996)
/*MTKSOC1*/            {
/*MTKSOC1*/               if(arfcn<=124)
/*MTKSOC1*/               {/*arfcn:103~124*/
/*MTKSOC1*/                  Nfrac = (arfcn-103)*258111+129056;
/*MTKSOC1*/                  *rfN = (147L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/               }
/*MTKSOC1*/               else
/*MTKSOC1*/               {/*arfcn:975~996*/
/*MTKSOC1*/                  Nfrac = (arfcn-975)*258111+2839221;
/*MTKSOC1*/                  *rfN = (142L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/               }
/*MTKSOC1*/            }
/*MTKSOC1*/            else
/*MTKSOC1*/            {/*arfcn:997~1023*/
/*MTKSOC1*/               Nfrac = (arfcn-997)*258111+129056;
/*MTKSOC1*/               *rfN = (143L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/            }
/*MTKSOC1*/         }
/*MTKSOC1*/
/*MTKSOC1*/         *ifN = (Nfrac>>10)|0x0212000;  /* CW2, TRX:0, BAND:1, MODE:1, N_RFC[22:10]*/
/*MTKSOC1*/
/*MTKSOC1*/         if(Nfrac==0) SDM_IFM = 0;
/*MTKSOC1*/         *rfN |= ((Nfrac&0x3FF) | 0x0180000L | (SDM_IFM<<18) ); /* N_INT[7:0] | N_FRAC[9:0] | (CW1|OPLL_HLSIDE)| SDM_IFM)*/
/*MTKSOC1*/
/*MTKSOC1*/         // Get GSM900 signal from GSM850 input pins if flag=1
/*MTKSOC1*/         if( BBTXParameters.bbrx_gsm850_gsm900_swap )  *ifN &= (~(0x0010000L));
/*MTKSOC1*/         break;
/*MTKSOC1*/      }
/*MTKSOC1*/   case  FrequencyBand1800 :
/*MTKSOC1*/      {
/*MTKSOC1*/         if(arfcn<=715)
/*MTKSOC1*/         {
/*MTKSOC1*/            if(arfcn<=585)
/*MTKSOC1*/            {
/*MTKSOC1*/               if(arfcn<=520)
/*MTKSOC1*/               {/*arfcn:512~520*/
/*MTKSOC1*/                  L1D_RF_GetRxPLL_HB_FractionPart(&Nfrac, arfcn, 456);
/*MTKSOC1*/                  *rfN = (138L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/               }
/*MTKSOC1*/               else
/*MTKSOC1*/               {/*arfcn:521~585*/
/*MTKSOC1*/                  L1D_RF_GetRxPLL_HB_FractionPart(&Nfrac, arfcn, 521);
/*MTKSOC1*/                  *rfN = (139L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/               }
/*MTKSOC1*/            }
/*MTKSOC1*/            else
/*MTKSOC1*/            {
/*MTKSOC1*/               if(arfcn<=650)
/*MTKSOC1*/               {/*arfcn:586~650*/
/*MTKSOC1*/                  L1D_RF_GetRxPLL_HB_FractionPart(&Nfrac, arfcn, 586);
/*MTKSOC1*/                  *rfN = (140L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/               }
/*MTKSOC1*/               else
/*MTKSOC1*/               {/*arfcn:651~715*/
/*MTKSOC1*/                  L1D_RF_GetRxPLL_HB_FractionPart(&Nfrac, arfcn, 651);
/*MTKSOC1*/                  *rfN = (141L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/               }
/*MTKSOC1*/            }
/*MTKSOC1*/         }
/*MTKSOC1*/         else
/*MTKSOC1*/         {
/*MTKSOC1*/            if(arfcn<=845)
/*MTKSOC1*/            {
/*MTKSOC1*/               if(arfcn<=780)
/*MTKSOC1*/               {/*arfcn:716~780*/
/*MTKSOC1*/                  L1D_RF_GetRxPLL_HB_FractionPart(&Nfrac, arfcn, 716);
/*MTKSOC1*/                  *rfN = (142L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/               }
/*MTKSOC1*/               else
/*MTKSOC1*/               {/*arfcn:781~845*/
/*MTKSOC1*/                  L1D_RF_GetRxPLL_HB_FractionPart(&Nfrac, arfcn, 781);
/*MTKSOC1*/                  *rfN = (143L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/               }
/*MTKSOC1*/            }
/*MTKSOC1*/            else
/*MTKSOC1*/            {/*arfcn:846~885*/
/*MTKSOC1*/               L1D_RF_GetRxPLL_HB_FractionPart(&Nfrac, arfcn, 846);
/*MTKSOC1*/               *rfN = (144L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/            }
/*MTKSOC1*/         }
/*MTKSOC1*/
/*MTKSOC1*/
/*MTKSOC1*/         *ifN = (Nfrac>>10)|0x0222000;  /* CW2, TRX:0, BAND:2, MODE:1, N_RFC[22:10]*/
/*MTKSOC1*/
/*MTKSOC1*/         if(Nfrac==0) SDM_IFM = 0;
/*MTKSOC1*/         *rfN |= ((Nfrac&0x3FF) | 0x0180000L | (SDM_IFM<<18) ); /* N_INT[7:0] | N_FRAC[9:0] | (CW1|OPLL_HLSIDE)| SDM_IFM)*/
/*MTKSOC1*/
/*MTKSOC1*/         // Get PCS1900 signal from DCS1800 input pins if flag=1
/*MTKSOC1*/         if( BBTXParameters.bbrx_dcs1800_pcs1900_swap ) *ifN |=0x0010000L ;
/*MTKSOC1*/         break;
/*MTKSOC1*/      }
/*MTKSOC1*/   case  FrequencyBand1900 :
/*MTKSOC1*/      {
/*MTKSOC1*/         if(arfcn<=675)
/*MTKSOC1*/         {
/*MTKSOC1*/            if(arfcn<=610)
/*MTKSOC1*/            {
/*MTKSOC1*/               if(arfcn<=545)
/*MTKSOC1*/               {/*arfcn:512~545*/
/*MTKSOC1*/                  L1D_RF_GetRxPLL_HB_FractionPart(&Nfrac, arfcn, 481);
/*MTKSOC1*/                  *rfN = (148L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/               }
/*MTKSOC1*/               else
/*MTKSOC1*/               {/*arfcn:546~610*/
/*MTKSOC1*/                  L1D_RF_GetRxPLL_HB_FractionPart(&Nfrac, arfcn, 546);
/*MTKSOC1*/                  *rfN = (149L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/               }
/*MTKSOC1*/            }
/*MTKSOC1*/            else
/*MTKSOC1*/            {/*arfcn:611~675*/
/*MTKSOC1*/               L1D_RF_GetRxPLL_HB_FractionPart(&Nfrac, arfcn, 611);
/*MTKSOC1*/               *rfN = (150L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/            }
/*MTKSOC1*/         }
/*MTKSOC1*/         else
/*MTKSOC1*/         {
/*MTKSOC1*/            if(arfcn<=805)
/*MTKSOC1*/            {
/*MTKSOC1*/               if(arfcn<=740)
/*MTKSOC1*/               {/*arfcn:676~740*/
/*MTKSOC1*/                  L1D_RF_GetRxPLL_HB_FractionPart(&Nfrac, arfcn, 676);
/*MTKSOC1*/                  *rfN = (151L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/               }
/*MTKSOC1*/               else
/*MTKSOC1*/               {/*arfcn:741~805*/
/*MTKSOC1*/                  L1D_RF_GetRxPLL_HB_FractionPart(&Nfrac, arfcn, 741);
/*MTKSOC1*/                  *rfN = (152L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/               }
/*MTKSOC1*/            }
/*MTKSOC1*/            else
/*MTKSOC1*/            {/*arfcn:806~810*/
/*MTKSOC1*/               L1D_RF_GetRxPLL_HB_FractionPart(&Nfrac, arfcn, 806);
/*MTKSOC1*/               *rfN = (153L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/            }
/*MTKSOC1*/         }
/*MTKSOC1*/
/*MTKSOC1*/         *ifN = (Nfrac>>10)|0x0232000;  /* CW2, TRX:0, BAND:2, MODE:1, N_RFC[22:10]*/
/*MTKSOC1*/
/*MTKSOC1*/         if(Nfrac==0) SDM_IFM = 0;
/*MTKSOC1*/         *rfN |= ((Nfrac&0x3FF) | 0x0180000L | (SDM_IFM<<18) ); /* N_INT[7:0] | N_FRAC[9:0] | (CW1|OPLL_HLSIDE)| SDM_IFM)*/
/*MTKSOC1*/         // Get DCS1800 signal from PCS1900 input pins if flag=1
/*MTKSOC1*/         if( BBTXParameters.bbrx_dcs1800_pcs1900_swap)  *ifN &= (~(0x0010000L));
/*MTKSOC1*/         break;
/*MTKSOC1*/      }
/*MTKSOC1*/   default :
/*MTKSOC1*/      {
/*MTKSOC1*/         break;
/*MTKSOC1*/      }
/*MTKSOC1*/   }
/*MTKSOC1*/}
/*MTKSOC1*//* =============================================================== */
/*MTKSOC1*/
/*MTKSOC1*/void L1D_RF_GetRxPLL_HB_FractionPart(int *Nfrac, int arfcn, int arfcn_base)
/*MTKSOC1*/{
/*MTKSOC1*/   int Diff_arfcn;
/*MTKSOC1*/
/*MTKSOC1*/   Diff_arfcn = arfcn - arfcn_base;
/*MTKSOC1*/   *Nfrac = (Diff_arfcn >>1) * 258111;
/*MTKSOC1*/   if(Diff_arfcn & 0x1) *Nfrac += 129056;
/*MTKSOC1*/}
/*MTKSOC1*//* =============================================================== */
#endif

#if IS_RF_MT6252RF
/*MT6252RF*/
/*MT6252RF*/ static void  L1D_RF_GetRxPLLifNrfN( int rf_band, short K, long *ifN, long *rfN )
/*MT6252RF*/ {
/*MT6252RF*/    int Nfrac = 64527*K + ( ( 3*K + 2 ) >> 2 );
/*MT6252RF*/
/*MT6252RF*/    /* CW2, TRX:0, BAND:0, MODE:010, N_RFC[22:10]*/
/*MT6252RF*/    *ifN = ( Nfrac >> 10) | 0x0204000L | ( ( rf_band - 1 ) << 16 );
/*MT6252RF*/
/*MT6252RF*/    *rfN |= ( ( Nfrac&0x3FF ) | 0x0100000L );
/*MT6252RF*/ }
/*MT6252RF*/ /* ============================================================================= */
/*MT6252RF*/
/*MT6252RF*/ void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6252RF*/ {
/*MT6252RF*/    short D = 0, K = 0;
/*MT6252RF*/    int Nfrac, DFM_LGCP_IOSTPOL;
/*MT6252RF*/    switch(rf_band)
/*MT6252RF*/    {
/*MT6252RF*/       case  FrequencyBand850 :
/*MT6252RF*/       {
/*MT6252RF*/          D = arfcn - 128;
/*MT6252RF*/          K = 104 + 4*D - 130*( ( 1653 + 63*D ) >> 11 );
/*MT6252RF*/
/*MT6252RF*/          // Nint = 126 + ( ( 1653 + 63*D ) >> 11 ); *rfN = Nint << 10;
/*MT6252RF*/          *rfN = ( 126 << 10 ) + (long)( ( ( 1653 + 63*D ) >> 1 ) & 0xFC00 );
/*MT6252RF*/          break;
/*MT6252RF*/       }
/*MT6252RF*/       case  FrequencyBand900 :
/*MT6252RF*/       {
/*MT6252RF*/	         D = ( arfcn > 974 ) ? ( arfcn - 1024 ) : arfcn;
/*MT6252RF*/	         K = 250 + 4*D - 130*( ( 3953 + 63*D ) >> 11 );
/*MT6252RF*/
/*MT6252RF*/	         // Nint = 135 + ( ( 3953 + 63 D ) >> 11 ); *rfN = Nint << 10;
/*MT6252RF*/          *rfN = ( 135 << 10 ) + (long)( ( ( 3953 + 63*D ) >> 1 ) & 0xFC00 );
/*MT6252RF*/          break;
/*MT6252RF*/       }
/*MT6252RF*/       case  FrequencyBand1800 :
/*MT6252RF*/       {
/*MT6252RF*/          D = arfcn - 512;
/*MT6252RF*/          K = 72 + 2*D - 130*( ( 2300 + 63*D ) >> 12 );
/*MT6252RF*/
/*MT6252RF*/          // Nint = 131 + ( ( 2300 + 63*D ) >> 12 ); *rfN = Nint << 10;
/*MT6252RF*/          *rfN = ( 131 << 10 ) + (long)( ( ( 2300 + 63*D ) >> 2 ) & 0xFC00 );
/*MT6252RF*/          break;
/*MT6252RF*/       }
/*MT6252RF*/       case  FrequencyBand1900 :
/*MT6252RF*/       {
/*MT6252RF*/          D = arfcn - 512;
/*MT6252RF*/          K = 42 + 2*D - 130*( ( 1355 + 63*D ) >> 12 );
/*MT6252RF*/
/*MT6252RF*/          // Nint = 142 + ( ( 1355 + 63*D ) >> 12 ); *rfN = Nint << 10;
/*MT6252RF*/          *rfN = ( 142 << 10 ) + (long)( ( ( 1355 + 63*D ) >> 2 ) & 0xFC00 );
/*MT6252RF*/          break;
/*MT6252RF*/       }
/*MT6252RF*/       default :
/*MT6252RF*/       {
/*MT6252RF*/          break;
/*MT6252RF*/       }
/*MT6252RF*/    }
/*MT6252RF*/    DFM_LGCP_IOSTPOL = (27 < K && K < 37) || (49 < K && K < 59) || (113 < K && K < 129) ? 1 : 0;
/*MT6252RF*/    Nfrac = 64527*K + ( ( 3*K + 2 ) >> 2 );
/*MT6252RF*/
/*MT6252RF*/    /* CW2:      [27:20] |  [19:18] |   [17:16] |   [15:13]               |        [12:0] */
/*MT6252RF*/    /*      Address[7:0] | TRX[1:0] | BAND[1:0] | MODE[2:0](warm_up mode) | N_FRAC[22:10] */
/*MT6252RF*/    *ifN = ( Nfrac >> 10 ) | 0x0244000L | ( ( rf_band - 1 ) << 16 );
/*MT6252RF*/
/*MT6252RF*/    /* CW1:      [27:20] |          [19] |             [18] |    [17:10] |       [9:0]    */
/*MT6252RF*/    /*      Address[7:0] | DFM_SDM_DI_EN | DFM_LGCP_IOSTPOL | N_INT[7:0] | N_FRAC[9:0]    */
/*MT6252RF*/    *rfN |= ( ( Nfrac & 0x3FF ) | 0x0180000L | DFM_LGCP_IOSTPOL << 18 );
/*MT6252RF*/ }
/*MT6252RF*/ /* ============================================================================= */
/*MT6252RF*/
/*MT6252RF*/ void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6252RF*/ {
/*MT6252RF*/    short D = 0, K = 0;
/*MT6252RF*/    switch(rf_band)
/*MT6252RF*/    {
/*MT6252RF*/       case  FrequencyBand850 :
/*MT6252RF*/       {
/*MT6252RF*/          D = arfcn - 128;
/*MT6252RF*/          K = 94 + 4*D - 130*( ( 1496 + 63*D ) >> 11 );
/*MT6252RF*/
/*MT6252RF*/          // Nint = 133 + ( ( 1496 + 63*D ) >> 11); *rfN = Nint << 10;
/*MT6252RF*/          *rfN = ( 133 << 10 ) + (long)( ( ( 1496 + 63*D ) >> 1 ) & 0xFC00 );
/*MT6252RF*/          L1D_RF_GetRxPLLifNrfN( rf_band, K, ifN, rfN );
/*MT6252RF*/
/*MT6252RF*/          // Get GSM850 signal from GSM900 input pins if flag = 1
/*MT6252RF*/          if( BBTXParameters.bbrx_gsm850_gsm900_swap ) *ifN |=0x0010000L ;
/*MT6252RF*/          break;
/*MT6252RF*/       }
/*MT6252RF*/       case  FrequencyBand900 :
/*MT6252RF*/       {
/*MT6252RF*/          D = ( arfcn > 974 ) ? ( arfcn - 1024 ) : arfcn;
/*MT6252RF*/          K = 240 + 4*D - 130*( ( 3796 + 63*D ) >> 11 );
/*MT6252RF*/
/*MT6252RF*/          // Nint = 142 + ( ( 3796 + 63 D ) >> 11); *rfN = Nint << 10;
/*MT6252RF*/          *rfN = ( 142 << 10 ) + (long)( ( ( 3796 + 63*D ) >> 1 ) & 0xFC00 );
/*MT6252RF*/          L1D_RF_GetRxPLLifNrfN( rf_band, K, ifN, rfN );
/*MT6252RF*/
/*MT6252RF*/          // Get GSM900 signal from GSM850 input pins if flag = 1
/*MT6252RF*/          if( BBTXParameters.bbrx_gsm850_gsm900_swap )  *ifN &= (~(0x0010000L));
/*MT6252RF*/          break;
/*MT6252RF*/       }
/*MT6252RF*/       case  FrequencyBand1800 :
/*MT6252RF*/       {
/*MT6252RF*/          D = arfcn - 512;
/*MT6252RF*/          K = 112 + 2*D - 130*( ( 3560 + 63*D ) >> 12 );
/*MT6252RF*/
/*MT6252RF*/          // Nint = 138 + ( (3560 + 63 D) >> 12); *rfN = Nint << 10;
/*MT6252RF*/          *rfN = ( 138 << 10 ) + (long)( ( ( 3560 + 63*D ) >> 2 ) & 0xFC00 );
/*MT6252RF*/          L1D_RF_GetRxPLLifNrfN( rf_band, K, ifN, rfN );
/*MT6252RF*/
/*MT6252RF*/          // Get PCS1900 signal from DCS1800 input pins if flag = 1
/*MT6252RF*/          if( BBTXParameters.bbrx_dcs1800_pcs1900_swap ) *ifN |=0x0010000L ;
/*MT6252RF*/          break;
/*MT6252RF*/       }
/*MT6252RF*/       case  FrequencyBand1900 :
/*MT6252RF*/       {
/*MT6252RF*/          D = arfcn - 512;
/*MT6252RF*/          K = 62 + 2*D - 130*( ( 1985 + 63*D ) >> 12 );
/*MT6252RF*/
/*MT6252RF*/          // Nint = 148 + ( ( 1985 + 63*D ) >> 12); *rfN = Nint << 10;
/*MT6252RF*/          *rfN = ( 148 << 10 ) + (long)( ( ( 1985 + 63*D ) >> 2 ) & 0xFC00 );
/*MT6252RF*/          L1D_RF_GetRxPLLifNrfN( rf_band, K, ifN, rfN );
/*MT6252RF*/
/*MT6252RF*/          // Get DCS1800 signal from PCS1900 input pins if flag = 1
/*MT6252RF*/          if( BBTXParameters.bbrx_dcs1800_pcs1900_swap)  *ifN &= (~(0x0010000L));
/*MT6252RF*/          break;
/*MT6252RF*/       }
/*MT6252RF*/    }
/*MT6252RF*/ }
/*MT6252RF*/ /* ============================================================================= */
#endif

#if IS_RF_MT6256RF || IS_RF_MT6251RF || IS_RF_MT6255RF
   #if IS_MT6256_DCR_MODE || IS_MT6251_DCR_MODE
/*MT6256RF*/ //For DCR backup mode
/*MT6256RF*/ void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6256RF*/ {  long *if_sel = ifN+1;
/*MT6256RF*/    unsigned short Nint =0, CH_freq =0;
/*MT6256RF*/    unsigned long  Nfrac=0, VCO_freq=0;
/*MT6256RF*/
/*MT6256RF*/    *if_sel = 2;
/*MT6256RF*/    CH_freq = L1D_RF_ARFCN_CH_to_RxFreq( rf_band, arfcn );
/*MT6256RF*/
/*MT6256RF*/    if( rf_band < FrequencyBand1800 )
/*MT6256RF*/    {  VCO_freq = 4*CH_freq;  }
/*MT6256RF*/    else
/*MT6256RF*/    {  VCO_freq = 2*CH_freq;  }
/*MT6256RF*/
/*MT6256RF*/    Nint  = VCO_freq/DCXO_FREQ;
/*MT6256RF*/    Nfrac = ( ( (VCO_freq - Nint*DCXO_FREQ)<<23 ) + DCXO_FREQ/2 )/DCXO_FREQ;
/*MT6256RF*/
/*MT6256RF*/    // CW2, TRX:0, BAND, MODE: standby, N_RFC[22:10]
/*MT6256RF*/    *ifN = BSI_CW( 0x02, 0x04000|(Nfrac>>10)|((rf_band-1)<<16) );
/*MT6256RF*/    // CW1, DFM_LG_COE, N_INT[7:0], N_FRAC[9:0]
/*MT6256RF*/    *rfN = BSI_CW( 0x01, 0xC0000|(Nfrac&0x3FF)|(Nint<<10) );
/*MT6256RF*/
/*MT6256RF*/    if( BBTXParameters.bbrx_gsm850_gsm900_swap || BBTXParameters.bbrx_dcs1800_pcs1900_swap )
/*MT6256RF*/    {
/*MT6256RF*/       switch( rf_band )
/*MT6256RF*/       {
/*MT6256RF*/          case FrequencyBand850 :
/*MT6256RF*/          case FrequencyBand1800 :
/*MT6256RF*/          {  *ifN |= 0x0010000L;
/*MT6256RF*/             break;
/*MT6256RF*/          }
/*MT6256RF*/          case FrequencyBand900 :
/*MT6256RF*/          case FrequencyBand1900 :
/*MT6256RF*/          {  *ifN &= (~(0x0010000L));
/*MT6256RF*/             break;
/*MT6256RF*/          }
/*MT6256RF*/          default:
/*MT6256RF*/          {  break;
/*MT6256RF*/          }
/*MT6256RF*/       }
/*MT6256RF*/    }
/*MT6256RF*/ }
/*MT6256RF*/ /* =========================================================================== */
   #else
/*MT6256RF*/ //For DLIF mode
/*MT6256RF*/ void  L1D_RF_Cal_Synthesizer_Params( unsigned short* Nint, unsigned long* Nfrac, unsigned long  VCO_freq )
/*MT6256RF*/ {
/*MT6256RF*/    *Nint  = VCO_freq/(DCXO_FREQ*DLIF_SCALE);
/*MT6256RF*/    //+195/2 is for rounding, 195=13*3*5, 5 is SYNTH_SCALE, 13 and 3 are related to DLIF
/*MT6256RF*/    *Nfrac = ( ( (VCO_freq - *Nint*DCXO_FREQ*DLIF_SCALE)<<15 ) + 195/2 )/195;
/*MT6256RF*/ }
/*MT6256RF*/ /* =========================================================================== */
/*MT6256RF*/
/*MT6256RF*/ char  L1D_RF_Cal_IF_Synth_State( void )
/*MT6256RF*/ {
      #if IS_W_CANCELLATION_SUPPORT
/*MT6256RF*/    if( L1D_CheckIfMetaMode() )
/*MT6256RF*/    {  return l1d_rf.if_state;  }
/*MT6256RF*/    else
/*MT6256RF*/    {  return 0;  }
      #else
/*MT6256RF*/    return 0;
      #endif
/*MT6256RF*/ }
/*MT6256RF*/ /* =========================================================================== */
/*MT6256RF*/
/*MT6256RF*/ void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6256RF*/ {  long *if_sel = ifN+1;
/*MT6256RF*/    unsigned short Nint =0, CH_freq =0;
/*MT6256RF*/    unsigned long  Nfrac=0, VCO_freq=0;
/*MT6256RF*/    unsigned long  frac_spurs_thd0=0, frac_spurs_thd1=0;
/*MT6256RF*/    unsigned char  IF_state=0;   //IF_state=0:default, IF_state=1:+IF, IF_state=2:-IF
/*MT6256RF*/
/*MT6256RF*/    IF_state = L1D_RF_Cal_IF_Synth_State();
/*MT6256RF*/
/*MT6256RF*/    CH_freq = L1D_RF_ARFCN_CH_to_RxFreq( rf_band, arfcn );
/*MT6256RF*/
/*MT6256RF*/    if( IF_state != 2 )
/*MT6256RF*/    {
/*MT6256RF*/       *if_sel = 0;
/*MT6256RF*/       if( rf_band < FrequencyBand1800 )
/*MT6256RF*/       {
/*MT6256RF*/          VCO_freq = 4*(CH_freq*DLIF_SCALE - DLIF);  //High-side mixing
/*MT6256RF*/          frac_spurs_thd0 = 193584;
/*MT6256RF*/          frac_spurs_thd1 = 8195024;
/*MT6256RF*/       }
/*MT6256RF*/       else
/*MT6256RF*/       {
/*MT6256RF*/          VCO_freq = 2*(CH_freq*DLIF_SCALE - DLIF);  //High-side mixing
/*MT6256RF*/          frac_spurs_thd0 = 96792;
/*MT6256RF*/          frac_spurs_thd1 = 8291816;
/*MT6256RF*/       }
/*MT6256RF*/       L1D_RF_Cal_Synthesizer_Params( &Nint, &Nfrac, VCO_freq );
/*MT6256RF*/    }
/*MT6256RF*/
/*MT6256RF*/    if( IF_state != 1 )
/*MT6256RF*/    {
/*MT6256RF*/       // check fractional spurs criterion (for run-time) or IRR state (for IRR calibration)
/*MT6256RF*/       if( ( Nfrac < frac_spurs_thd0 ) || ( Nfrac > frac_spurs_thd1) || ( Nfrac < 4258832 && Nfrac > 4129776 ) || ( IF_state == 2 ) )
/*MT6256RF*/       {
/*MT6256RF*/          *if_sel = 1;  //-170k
/*MT6256RF*/          if( rf_band < FrequencyBand1800 )
/*MT6256RF*/          {  VCO_freq = 4*(CH_freq*DLIF_SCALE + DLIF);  }  //Low-side mixing
/*MT6256RF*/          else
/*MT6256RF*/          {  VCO_freq = 2*(CH_freq*DLIF_SCALE + DLIF);  }  //Low-side mixing
/*MT6256RF*/
/*MT6256RF*/          L1D_RF_Cal_Synthesizer_Params( &Nint, &Nfrac, VCO_freq );
/*MT6256RF*/       }
/*MT6256RF*/    }
/*MT6256RF*/
      #if IS_OBB_DETECTION_SUPPORT
/*MT6256RF*/    if( !L1D_CheckIfMetaMode() )
/*MT6256RF*/    {
/*MT6256RF*/       if( l1d_rf.if_change == -1 && arfcn == l1d_rf.obb_arfcn )
/*MT6256RF*/       {
/*MT6256RF*/          signed short if_sign = l1d_rf.if_change*(*if_sel*2-1);
/*MT6256RF*/
/*MT6256RF*/          *if_sel = if_sign > 0 ? 1 : 0;
/*MT6256RF*/          if( rf_band < FrequencyBand1800 )
/*MT6256RF*/          {  VCO_freq = 4*(CH_freq*DLIF_SCALE + if_sign*DLIF);  }
/*MT6256RF*/          else
/*MT6256RF*/          {  VCO_freq = 2*(CH_freq*DLIF_SCALE + if_sign*DLIF);  }
/*MT6256RF*/
/*MT6256RF*/          L1D_RF_Cal_Synthesizer_Params( &Nint, &Nfrac, VCO_freq );
/*MT6256RF*/       }
/*MT6256RF*/    }
      #endif
/*MT6256RF*/    // CW2, TRX:0, BAND, MODE: standby, N_RFC[22:10]
/*MT6256RF*/    *ifN = BSI_CW( 0x02, 0x04000|(Nfrac>>10)|((rf_band-1)<<16) );
/*MT6256RF*/    // CW1, DFM_LG_COE, N_INT[7:0], N_FRAC[9:0]
/*MT6256RF*/    *rfN = BSI_CW( 0x01, 0xC0000|(Nfrac&0x3FF)|(Nint<<10) );
/*MT6256RF*/
/*MT6256RF*/    if( BBTXParameters.bbrx_gsm850_gsm900_swap || BBTXParameters.bbrx_dcs1800_pcs1900_swap )
/*MT6256RF*/    {
/*MT6256RF*/       switch( rf_band )
/*MT6256RF*/       {
/*MT6256RF*/          case FrequencyBand850 :
/*MT6256RF*/          case FrequencyBand1800 :
/*MT6256RF*/          {  *ifN |= 0x0010000L;
/*MT6256RF*/             break;
/*MT6256RF*/          }
/*MT6256RF*/          case FrequencyBand900 :
/*MT6256RF*/          case FrequencyBand1900 :
/*MT6256RF*/          {  *ifN &= (~(0x0010000L));
/*MT6256RF*/             break;
/*MT6256RF*/          }
/*MT6256RF*/          default:
/*MT6256RF*/          {  break;
/*MT6256RF*/          }
/*MT6256RF*/       }
/*MT6256RF*/    }
/*MT6256RF*/ }
/*MT6256RF*/ /* =========================================================================== */
   #endif
/*MT6256RF*/ void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6256RF*/ {
/*MT6256RF*/    unsigned short Nint =0, CH_freq =0;
/*MT6256RF*/    unsigned long  Nfrac=0, VCO_freq=0;
/*MT6256RF*/
/*MT6256RF*/    l1d_rf2.arfcn = arfcn;  //for L1D_RF_GetSData_ST2()
/*MT6256RF*/    CH_freq = L1D_RF_ARFCN_CH_to_TxFreq( rf_band, arfcn );
/*MT6256RF*/
/*MT6256RF*/    if( rf_band < FrequencyBand1800 )
/*MT6256RF*/    {  VCO_freq = 4*CH_freq;  }
/*MT6256RF*/    else
/*MT6256RF*/    {  VCO_freq = 2*CH_freq;  }
/*MT6256RF*/
/*MT6256RF*/    Nint  = VCO_freq/DCXO_FREQ;
/*MT6256RF*/    Nfrac = ( ((VCO_freq-Nint*DCXO_FREQ)<<23) + DCXO_FREQ/2 )/DCXO_FREQ;  //+DCXO_freq/2 is for rounding
/*MT6256RF*/
/*MT6256RF*/    // CW2, TRX:1, BAND, MODE: standby, N_RFC[22:10]
/*MT6256RF*/    *ifN = BSI_CW( 0x02, 0x44000|(Nfrac>>10)|((rf_band-1)<<16) );
/*MT6256RF*/    // CW1, DFM_LG_COE, N_INT[7:0], N_FRAC[9:0]
/*MT6256RF*/    *rfN = BSI_CW( 0x01, 0xC0000|(Nfrac&0x3FF)|(Nint<<10) );
   #if IS_CHIP_MT6256_S00 || IS_CHIP_MT6251_S00
   /* Do nothing */
   #elif IS_CHIP_MT6256 || IS_CHIP_MT6255
/*MT6256RF*/    if( ( Nfrac>=225847  && Nfrac<=419430  ) || ( Nfrac>=1000180 && Nfrac<=1193763 ) ||
/*MT6256RF*/        ( Nfrac>=1903568 && Nfrac<=2097152 ) || ( Nfrac>=3452234 && Nfrac<=3645818 ) ||
/*MT6256RF*/        ( Nfrac>=4484678 && Nfrac<=4678262 ) || ( Nfrac>=5000900 && Nfrac<=5065428 ) ||
/*MT6256RF*/        ( Nfrac>=5517122 && Nfrac<=5581650 ) || ( Nfrac>=7452955 && Nfrac<=7904649 )
/*MT6256RF*/      )
/*MT6256RF*/    {  /*CW1, DFM_LG_COE = 0*/
/*MT6256RF*/       *rfN &= ~(1<<19);
/*MT6256RF*/    }
   #elif IS_CHIP_MT6251
/*MT6251RF*/    if( ( Nfrac>=1774513 && Nfrac<=2355264 ) || ( Nfrac>=2936012 && Nfrac<=3129597 ) ||
/*MT6251RF*/        ( Nfrac>=3452235 && Nfrac<=3516763 ) || ( Nfrac>=3968457 && Nfrac<=4162041 ) ||
/*MT6251RF*/        ( Nfrac>=6162401 && Nfrac<=6355983 ) || ( Nfrac>=6807678 && Nfrac<=7130316 ) ||
/*MT6251RF*/        ( Nfrac>=7711067 && Nfrac<=8033705 ) )
/*MT6251RF*/    {  /*CW1, DFM_LG_COE = 0*/
/*MT6251RF*/       *rfN &= ~(1<<19);
/*MT6251RF*/    }
   #endif
/*MT6256RF*/ }
/*MT6256RF*/ /* =========================================================================== */
/*MT6256RF*/
/*MT6256RF*/ unsigned short L1D_RF_ARFCN_CH_to_RxFreq( int rf_band, int arfcn )
/*MT6256RF*/ {
/*MT6256RF*/    unsigned short freq=4450+225;
/*MT6256RF*/    switch( rf_band )
/*MT6256RF*/    {
/*MT6256RF*/       case  FrequencyBand850 :
/*MT6256RF*/       {
/*MT6256RF*/          freq=4121+(arfcn-128)+225;     //freq = f_ch*SYNTH_SCALE
/*MT6256RF*/          break;
/*MT6256RF*/       }
/*MT6256RF*/       case  FrequencyBand900 :
/*MT6256RF*/       {
/*MT6256RF*/          if( arfcn<=124 )
/*MT6256RF*/          {  freq=4450+arfcn+225;  }
/*MT6256RF*/          else
/*MT6256RF*/          {  freq=4450+(arfcn-1024)+225;  }
/*MT6256RF*/          break;
/*MT6256RF*/       }
/*MT6256RF*/       case  FrequencyBand1800 :
/*MT6256RF*/       {
/*MT6256RF*/          freq=8551+(arfcn-512)+475;
/*MT6256RF*/          break;
/*MT6256RF*/       }
/*MT6256RF*/       case  FrequencyBand1900 :
/*MT6256RF*/       {
/*MT6256RF*/          freq=9251+(arfcn-512)+400;
/*MT6256RF*/          break;
/*MT6256RF*/       }
/*MT6256RF*/       default :
/*MT6256RF*/       {
/*MT6256RF*/          break;
/*MT6256RF*/       }
/*MT6256RF*/    }
/*MT6256RF*/
/*MT6256RF*/    return freq;
/*MT6256RF*/ }
/*MT6256RF*/ /* =========================================================================== */
/*MT6256RF*/
/*MT6256RF*/ unsigned short L1D_RF_ARFCN_CH_to_TxFreq( int rf_band, int arfcn )
/*MT6256RF*/ {
/*MT6256RF*/    unsigned short freq=4450;
/*MT6256RF*/    switch( rf_band )
/*MT6256RF*/    {
/*MT6256RF*/       case  FrequencyBand850 :
/*MT6256RF*/       {
/*MT6256RF*/          freq=4121+(arfcn-128);     //freq = f_ch*SYNTH_SCALE
/*MT6256RF*/          break;
/*MT6256RF*/       }
/*MT6256RF*/       case  FrequencyBand900 :
/*MT6256RF*/       {
/*MT6256RF*/          if( arfcn<=124 )
/*MT6256RF*/          {  freq=4450+arfcn;  }
/*MT6256RF*/          else
/*MT6256RF*/          {  freq=4450+(arfcn-1024);  }
/*MT6256RF*/          break;
/*MT6256RF*/       }
/*MT6256RF*/       case  FrequencyBand1800 :
/*MT6256RF*/       {
/*MT6256RF*/          freq=8551+(arfcn-512);
/*MT6256RF*/          break;
/*MT6256RF*/       }
/*MT6256RF*/       case  FrequencyBand1900 :
/*MT6256RF*/       {
/*MT6256RF*/          freq=9251+(arfcn-512);
/*MT6256RF*/          break;
/*MT6256RF*/       }
/*MT6256RF*/       default :
/*MT6256RF*/       {
/*MT6256RF*/          break;
/*MT6256RF*/       }
/*MT6256RF*/    }
/*MT6256RF*/
/*MT6256RF*/    return freq;
/*MT6256RF*/ }
/*MT6256RF*/ /* =========================================================================== */
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/*AD6548*/void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*AD6548*/{
/*AD6548*/   switch(rf_band)
/*AD6548*/   {
/*AD6548*/      case  FrequencyBand850 :
/*AD6548*/      {
/*AD6548*/         if(arfcn<=201)
/*AD6548*/         {  if(arfcn<=158)
/*AD6548*/            {                                /* ARFCN : 128~158     */
/*AD6548*/                *rfN = (((arfcn-128)*24 + 304)<<13) | 0x1206L /*(36L<<7|0x06L)*/;
/*AD6548*/            }
/*AD6548*/            else
/*AD6548*/            {                              /* ARFCN : 159~201     */
/*AD6548*/                *rfN = (((arfcn-159)*24 + 8)<<13) | 0x1286L /*(37L<<7|0x06L)*/;
/*AD6548*/            }
/*AD6548*/         }
/*AD6548*/         else
/*AD6548*/         {  if(arfcn<=245)
/*AD6548*/            {                                /* ARFCN : 202~245     */
/*AD6548*/                *rfN = (((arfcn-202)*24 )<<13) | 0x1306L /*(38L<<7|0x06L)*/;
/*AD6548*/            }
/*AD6548*/            else
/*AD6548*/            {                              /* ARFCN : 246~251     */
/*AD6548*/                *rfN = (((arfcn-246)*24+16)<<13) | 0x1386L /*(39L<<7|0x06L)*/;
/*AD6548*/            }
/*AD6548*/         }
/*AD6548*/         break;
/*AD6548*/      }
/*AD6548*/      case  FrequencyBand900 :
/*AD6548*/      {
/*AD6548*/         if(arfcn<=48)
/*AD6548*/         {  if(arfcn<=4)
/*AD6548*/            {                                /* ARFCN : 0~4     */
/*AD6548*/                *rfN = (((arfcn)*24+920 )<<13) | 0x1586L /*(43L<<7|0x06L)*/;
/*AD6548*/            }
/*AD6548*/            else
/*AD6548*/            {                              /* ARFCN : 5~48     */
/*AD6548*/                *rfN = (((arfcn-5)*24 )<<13) | 0x1606L /*(44L<<7|0x06L)*/;
/*AD6548*/            }
/*AD6548*/         }
/*AD6548*/         else
/*AD6548*/         {  if(arfcn<=124)
/*AD6548*/            {   if(arfcn<=91)
/*AD6548*/                {                                /* ARFCN : 49~91     */
/*AD6548*/                   *rfN = (((arfcn-49)*24+16)<<13) | 0x1686L /*(45L<<7|0x06L)*/;
/*AD6548*/                }
/*AD6548*/                else
/*AD6548*/                {                                /* ARFCN : 92~124     */
/*AD6548*/                   *rfN = (((arfcn-92)*24+8 )<<13) | 0x1706L /*(46L<<7|0x06L)*/;
/*AD6548*/                }
/*AD6548*/            }
/*AD6548*/            else
/*AD6548*/            {  if(arfcn<=985)
/*AD6548*/                {                                /* ARFCN : 975~985     */
/*AD6548*/                   *rfN = (((arfcn-975)*24+784)<<13) | 0x1506L /*(42L<<7|0x06L)*/;
/*AD6548*/                }
/*AD6548*/                else
/*AD6548*/                {                                /* ARFCN : 986~1023     */
/*AD6548*/                   *rfN = (((arfcn-986)*24+8 )<<13) | 0x1586L /*(43L<<7|0x06L)*/;
/*AD6548*/                }
/*AD6548*/            }
/*AD6548*/         }
/*AD6548*/         break;
/*AD6548*/      }
/*AD6548*/      case  FrequencyBand1800 :
/*AD6548*/      {
/*AD6548*/         if(arfcn<=672)
/*AD6548*/         {  if(arfcn<=585)
/*AD6548*/            {                                /* ARFCN : 512~585     */
/*AD6548*/                *rfN = (((arfcn-512)*12+152)<<13) | 0x1406L /*(40L<<7|0x06L)*/;
/*AD6548*/            }
/*AD6548*/            else
/*AD6548*/            {                                /* ARFCN : 586~672     */
/*AD6548*/                *rfN = (((arfcn-586)*12)<<13) | 0x1486L /*(41L<<7|0x06L)*/;
/*AD6548*/            }
/*AD6548*/         }
/*AD6548*/         else
/*AD6548*/         {  if(arfcn<=759)
/*AD6548*/            {                                 /* ARFCN : 673~759     */
/*AD6548*/               *rfN = (((arfcn-673)*12+4)<<13) | 0x1506L /*(42L<<7|0x06L)*/;
/*AD6548*/            }
/*AD6548*/            else
/*AD6548*/            { if(arfcn<=845)
/*AD6548*/              {                               /* ARFCN : 760~845     */
/*AD6548*/                *rfN = (((arfcn-760)*12+8)<<13) | 0x1586L /*(43L<<7|0x06L)*/;
/*AD6548*/              }
/*AD6548*/              else
/*AD6548*/              {                                /* ARFCN : 846~885     */
/*AD6548*/                *rfN = (((arfcn-846)*12)<<13) | 0x1606L /*(44L<<7|0x06L)*/;
/*AD6548*/              }
/*AD6548*/            }
/*AD6548*/         }
/*AD6548*/         break;
/*AD6548*/      }
/*AD6548*/      case  FrequencyBand1900 :
/*AD6548*/      {
/*AD6548*/         if(arfcn<=654)
/*AD6548*/         {  if(arfcn<=567)
/*AD6548*/            {                                /* ARFCN : 512~567     */
/*AD6548*/                *rfN = (((arfcn-512)*12+372)<<13) | 0x1786L /*(47L<<7|0x06L)*/;
/*AD6548*/            }
/*AD6548*/            else
/*AD6548*/            {                                /* ARFCN : 568~654     */
/*AD6548*/                *rfN = (((arfcn-568)*12+4)<<13) | 0x1806L /*(48L<<7|0x06L)*/;
/*AD6548*/            }
/*AD6548*/         }
/*AD6548*/         else
/*AD6548*/         {  if(arfcn<=740)
/*AD6548*/            {                                /* ARFCN : 655~740     */
/*AD6548*/                *rfN = (((arfcn-655)*12+8)<<13) | 0x1886L /*(49L<<7|0x06L)*/;
/*AD6548*/            }
/*AD6548*/            else
/*AD6548*/            {                                /* ARFCN : 741~810     */
/*AD6548*/                *rfN = (((arfcn-741)*12)<<13) | 0x1906L /*(50L<<7|0x06L)*/;
/*AD6548*/            }
/*AD6548*/         }
/*AD6548*/         break;
/*AD6548*/      }
/*AD6548*/      default :
/*AD6548*/      {
/*AD6548*/         break;
/*AD6548*/      }
/*AD6548*/   }
/*AD6548*/   *ifN = 0;
/*AD6548*/}
/*AD6548*//* ========================================================================== */
/*AD6548*/
/*AD6548*/void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*AD6548*/{
/*AD6548*/   switch(rf_band)
/*AD6548*/   {
/*AD6548*/      case  FrequencyBand850 :
/*AD6548*/      {
/*AD6548*/         if(arfcn<=185)
/*AD6548*/         {  if(arfcn<=143)
/*AD6548*/            {                                /* ARFCN : 128~143     */
/*AD6548*/                *rfN = (((arfcn-128)*28+728)<<13) | 0x1106L /*(34L<<7|0x06L)*/;
/*AD6548*/            }
/*AD6548*/            else
/*AD6548*/            {                                /* ARFCN : 144~185     */
/*AD6548*/                *rfN = (((arfcn-144)*28+6)<<13) | 0x1186L /*(35L<<7|0x06L)*/;
/*AD6548*/            }
/*AD6548*/         }
/*AD6548*/         else
/*AD6548*/         {  if(arfcn<=227)
/*AD6548*/            {                                /* ARFCN : 186~227     */
/*AD6548*/                *rfN = (((arfcn-186)*28+12)<<13) | 0x1206L /*(36L<<7|0x06L)*/;
/*AD6548*/            }
/*AD6548*/            else
/*AD6548*/            {                              /* ARFCN : 228~251     */
/*AD6548*/                *rfN = (((arfcn-228)*28+18)<<13) | 0x1286L /*(37L<<7|0x06L)*/;
/*AD6548*/            }
/*AD6548*/         }
/*AD6548*/         break;
/*AD6548*/      }
/*AD6548*/      case  FrequencyBand900 :
/*AD6548*/      {
/*AD6548*/         if(arfcn<=62)
/*AD6548*/         {  if(arfcn<=21)
/*AD6548*/            {                                /* ARFCN : 0~21     */
/*AD6548*/                *rfN = (((arfcn)*28+580)<<13) | 0x1506L /*(42L<<7|0x06L)*/;
/*AD6548*/            }
/*AD6548*/            else
/*AD6548*/            {                              /* ARFCN : 22~62     */
/*AD6548*/                *rfN = (((arfcn-22)*28+26)<<13) | 0x1586L /*(43L<<7|0x06L)*/;
/*AD6548*/            }
/*AD6548*/         }
/*AD6548*/         else
/*AD6548*/         {  if(arfcn<=124)
/*AD6548*/            {   if(arfcn<=104)
/*AD6548*/                {                                /* ARFCN : 63~104     */
/*AD6548*/                   *rfN = (((arfcn-63)*28+4)<<13) | 0x1606L /*(44L<<7|0x06L)*/;
/*AD6548*/                }
/*AD6548*/                else
/*AD6548*/                {                                /* ARFCN : 105~124     */
/*AD6548*/                   *rfN = (((arfcn-105)*28+10)<<13) | 0x1686L /*(45L<<7|0x06L)*/;
/*AD6548*/                }
/*AD6548*/            }
/*AD6548*/            else
/*AD6548*/            {  if(arfcn<=1003)
/*AD6548*/                {                                /* ARFCN : 975~1003     */
/*AD6548*/                   *rfN = (((arfcn-975)*28+378)<<13) | 0x1486L /*(41L<<7|0x06L)*/;
/*AD6548*/                }
/*AD6548*/                else
/*AD6548*/                {                                /* ARFCN : 1004~1023     */
/*AD6548*/                   *rfN = (((arfcn-1004)*28+20)<<13) | 0x1506L /*(42L<<7|0x06L)*/;
/*AD6548*/                }
/*AD6548*/            }
/*AD6548*/         }
/*AD6548*/         break;
/*AD6548*/      }
/*AD6548*/      case  FrequencyBand1800 :
/*AD6548*/      {
/*AD6548*/         if(arfcn<=694)
/*AD6548*/         {  if(arfcn<=605)
/*AD6548*/            { if(arfcn<=517)
/*AD6548*/              {                                /* ARFCN : 512~517     */
/*AD6548*/                *rfN = (((arfcn-512)*14+1154)<<13) | 0x1006L /*(32L<<7|0x06L)*/;
/*AD6548*/              }
/*AD6548*/              else
/*AD6548*/              {                                /* ARFCN : 518~605     */
/*AD6548*/                *rfN = (((arfcn-518)*14+3)<<13) | 0x1086L /*(33L<<7|0x06L)*/;
/*AD6548*/              }
/*AD6548*/            }
/*AD6548*/            else
/*AD6548*/            {                                  /* ARFCN : 606~694     */
/*AD6548*/                *rfN = (((arfcn-606)*14)<<13) | 0x1106L /*(34L<<7|0x06L)*/;
/*AD6548*/            }
/*AD6548*/         }
/*AD6548*/         else
/*AD6548*/         {  if(arfcn<=782)
/*AD6548*/            {                                  /* ARFCN : 695~782     */
/*AD6548*/               *rfN = (((arfcn-695)*14+11)<<13) | 0x1186L /*(35L<<7|0x06L)*/;
/*AD6548*/            }
/*AD6548*/            else
/*AD6548*/            { if(arfcn<=870)
/*AD6548*/              {                               /* ARFCN : 783~870     */
/*AD6548*/                *rfN = (((arfcn-783)*14+8)<<13) | 0x1206L /*(36L<<7|0x06L)*/;
/*AD6548*/              }
/*AD6548*/              else
/*AD6548*/              {                                /* ARFCN : 871~885     */
/*AD6548*/                *rfN = (((arfcn-871)*14+5)<<13) | 0x1286L /*(37L<<7|0x06L)*/;
/*AD6548*/              }
/*AD6548*/            }
/*AD6548*/         }
/*AD6548*/         break;
/*AD6548*/      }
/*AD6548*/      case  FrequencyBand1900 :
/*AD6548*/      {
/*AD6548*/         if(arfcn<=699)
/*AD6548*/         {  if(arfcn<=611)
/*AD6548*/            { if(arfcn<=523)
/*AD6548*/              {                                /* ARFCN : 512~523     */
/*AD6548*/                *rfN = (((arfcn-512)*14+1074)<<13) | 0x1406L /*(40L<<7|0x06L)*/;
/*AD6548*/              }
/*AD6548*/              else
/*AD6548*/              {                                /* ARFCN : 524~611     */
/*AD6548*/                *rfN = (((arfcn-524)*14+7)<<13) | 0x1486L /*(41L<<7|0x06L)*/;
/*AD6548*/              }
/*AD6548*/            }
/*AD6548*/            else
/*AD6548*/            {                                  /* ARFCN : 612~699     */
/*AD6548*/                *rfN = (((arfcn-612)*14+4)<<13) | 0x1506L /*(42L<<7|0x06L)*/;
/*AD6548*/            }
/*AD6548*/         }
/*AD6548*/         else
/*AD6548*/         {  if(arfcn<=788)
/*AD6548*/            {                                  /* ARFCN : 700~788     */
/*AD6548*/                *rfN = (((arfcn-700)*14+1)<<13) | 0x1586L /*(43L<<7|0x06L)*/;
/*AD6548*/            }
/*AD6548*/            else
/*AD6548*/            {                                  /* ARFCN : 789~810     */
/*AD6548*/                *rfN = (((arfcn-789)*14+12)<<13) | 0x1606L /*(44L<<7|0x06L)*/;
/*AD6548*/            }
/*AD6548*/         }
/*AD6548*/         break;
/*AD6548*/      }
/*AD6548*/      default :
/*AD6548*/      {
/*AD6548*/         break;
/*AD6548*/      }
/*AD6548*/   }
/*AD6548*/   *ifN = 0;
/*AD6548*/}
/*AD6548*//* ========================================================================== */
#endif

#if IS_RF_AD6546
/*AD6546*/void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*AD6546*/{
/*AD6546*/   switch(rf_band)
/*AD6546*/   {
/*AD6546*/      case  FrequencyBand850 :
/*AD6546*/      {
/*AD6546*/         if(arfcn<=201)
/*AD6546*/         {  if(arfcn<=158)
/*AD6546*/            {                                /* ARFCN : 128~158     */
/*AD6546*/                *rfN = (((arfcn-128)*24 + 304)<<13) | 0x1206L /*(36L<<7|0x06L)*/;
/*AD6546*/            }
/*AD6546*/            else
/*AD6546*/            {                              /* ARFCN : 159~201     */
/*AD6546*/                *rfN = (((arfcn-159)*24 + 8)<<13) | 0x1286L /*(37L<<7|0x06L)*/;
/*AD6546*/            }
/*AD6546*/         }
/*AD6546*/         else
/*AD6546*/         {  if(arfcn<=245)
/*AD6546*/            {                                /* ARFCN : 202~245     */
/*AD6546*/                *rfN = (((arfcn-202)*24 )<<13) | 0x1306L /*(38L<<7|0x06L)*/;
/*AD6546*/            }
/*AD6546*/            else
/*AD6546*/            {                              /* ARFCN : 246~251     */
/*AD6546*/                *rfN = (((arfcn-246)*24+16)<<13) | 0x1386L /*(39L<<7|0x06L)*/;
/*AD6546*/            }
/*AD6546*/         }
/*AD6546*/         break;
/*AD6546*/      }
/*AD6546*/      case  FrequencyBand900 :
/*AD6546*/      {
/*AD6546*/         if(arfcn<=48)
/*AD6546*/         {  if(arfcn<=4)
/*AD6546*/            {                                /* ARFCN : 0~4     */
/*AD6546*/                *rfN = (((arfcn)*24+920 )<<13) | 0x1586L /*(43L<<7|0x06L)*/;
/*AD6546*/            }
/*AD6546*/            else
/*AD6546*/            {                              /* ARFCN : 5~48     */
/*AD6546*/                *rfN = (((arfcn-5)*24 )<<13) | 0x1606L /*(44L<<7|0x06L)*/;
/*AD6546*/            }
/*AD6546*/         }
/*AD6546*/         else
/*AD6546*/         {  if(arfcn<=124)
/*AD6546*/            {   if(arfcn<=91)
/*AD6546*/                {                                /* ARFCN : 49~91     */
/*AD6546*/                   *rfN = (((arfcn-49)*24+16)<<13) | 0x1686L /*(45L<<7|0x06L)*/;
/*AD6546*/                }
/*AD6546*/                else
/*AD6546*/                {                                /* ARFCN : 92~124     */
/*AD6546*/                   *rfN = (((arfcn-92)*24+8 )<<13) | 0x1706L /*(46L<<7|0x06L)*/;
/*AD6546*/                }
/*AD6546*/            }
/*AD6546*/            else
/*AD6546*/            {  if(arfcn<=985)
/*AD6546*/                {                                /* ARFCN : 975~985     */
/*AD6546*/                   *rfN = (((arfcn-975)*24+784)<<13) | 0x1506L /*(42L<<7|0x06L)*/;
/*AD6546*/                }
/*AD6546*/                else
/*AD6546*/                {                                /* ARFCN : 986~1023     */
/*AD6546*/                   *rfN = (((arfcn-986)*24+8 )<<13) | 0x1586L /*(43L<<7|0x06L)*/;
/*AD6546*/                }
/*AD6546*/            }
/*AD6546*/         }
/*AD6546*/         break;
/*AD6546*/      }
/*AD6546*/      case  FrequencyBand1800 :
/*AD6546*/      {
/*AD6546*/         if(arfcn<=672)
/*AD6546*/         {  if(arfcn<=585)
/*AD6546*/            {                                /* ARFCN : 512~585     */
/*AD6546*/                *rfN = (((arfcn-512)*12+152)<<13) | 0x1406L /*(40L<<7|0x06L)*/;
/*AD6546*/            }
/*AD6546*/            else
/*AD6546*/            {                                /* ARFCN : 586~672     */
/*AD6546*/                *rfN = (((arfcn-586)*12)<<13) | 0x1486L /*(41L<<7|0x06L)*/;
/*AD6546*/            }
/*AD6546*/         }
/*AD6546*/         else
/*AD6546*/         {  if(arfcn<=759)
/*AD6546*/            {                                 /* ARFCN : 673~759     */
/*AD6546*/               *rfN = (((arfcn-673)*12+4)<<13) | 0x1506L /*(42L<<7|0x06L)*/;
/*AD6546*/            }
/*AD6546*/            else
/*AD6546*/            { if(arfcn<=845)
/*AD6546*/              {                               /* ARFCN : 760~845     */
/*AD6546*/                *rfN = (((arfcn-760)*12+8)<<13) | 0x1586L /*(43L<<7|0x06L)*/;
/*AD6546*/              }
/*AD6546*/              else
/*AD6546*/              {                                /* ARFCN : 846~885     */
/*AD6546*/                *rfN = (((arfcn-846)*12)<<13) | 0x1606L /*(44L<<7|0x06L)*/;
/*AD6546*/              }
/*AD6546*/            }
/*AD6546*/         }
/*AD6546*/         break;
/*AD6546*/      }
/*AD6546*/      case  FrequencyBand1900 :
/*AD6546*/      {
/*AD6546*/         if(arfcn<=654)
/*AD6546*/         {  if(arfcn<=567)
/*AD6546*/            {                                /* ARFCN : 512~567     */
/*AD6546*/                *rfN = (((arfcn-512)*12+372)<<13) | 0x1786L /*(47L<<7|0x06L)*/;
/*AD6546*/            }
/*AD6546*/            else
/*AD6546*/            {                                /* ARFCN : 568~654     */
/*AD6546*/                *rfN = (((arfcn-568)*12+4)<<13) | 0x1806L /*(48L<<7|0x06L)*/;
/*AD6546*/            }
/*AD6546*/         }
/*AD6546*/         else
/*AD6546*/         {  if(arfcn<=740)
/*AD6546*/            {                                /* ARFCN : 655~740     */
/*AD6546*/                *rfN = (((arfcn-655)*12+8)<<13) | 0x1886L /*(49L<<7|0x06L)*/;
/*AD6546*/            }
/*AD6546*/            else
/*AD6546*/            {                                /* ARFCN : 741~810     */
/*AD6546*/                *rfN = (((arfcn-741)*12)<<13) | 0x1906L /*(50L<<7|0x06L)*/;
/*AD6546*/            }
/*AD6546*/         }
/*AD6546*/         break;
/*AD6546*/      }
/*AD6546*/      default :
/*AD6546*/      {
/*AD6546*/         break;
/*AD6546*/      }
/*AD6546*/   }
/*AD6546*/   *ifN = 0;
/*AD6546*/}
/*AD6546*//* ========================================================================== */
/*AD6546*/
/*AD6546*/void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*AD6546*/{
/*AD6546*/   switch(rf_band)
/*AD6546*/   {
/*AD6546*/      case  FrequencyBand850 :
/*AD6546*/      {
/*AD6546*/         if(arfcn<=185)
/*AD6546*/         {  if(arfcn<=143)
/*AD6546*/            {                                /* ARFCN : 128~143     */
/*AD6546*/                *rfN = (((arfcn-128)*28+728)<<13) | 0x1106L /*(34L<<7|0x06L)*/;
/*AD6546*/            }
/*AD6546*/            else
/*AD6546*/            {                                /* ARFCN : 144~185     */
/*AD6546*/                *rfN = (((arfcn-144)*28+6)<<13) | 0x1186L /*(35L<<7|0x06L)*/;
/*AD6546*/            }
/*AD6546*/         }
/*AD6546*/         else
/*AD6546*/         {  if(arfcn<=227)
/*AD6546*/            {                                /* ARFCN : 186~227     */
/*AD6546*/                *rfN = (((arfcn-186)*28+12)<<13) | 0x1206L /*(36L<<7|0x06L)*/;
/*AD6546*/            }
/*AD6546*/            else
/*AD6546*/            {                              /* ARFCN : 228~251     */
/*AD6546*/                *rfN = (((arfcn-228)*28+18)<<13) | 0x1286L /*(37L<<7|0x06L)*/;
/*AD6546*/            }
/*AD6546*/         }
/*AD6546*/         break;
/*AD6546*/      }
/*AD6546*/      case  FrequencyBand900 :
/*AD6546*/      {
/*AD6546*/         if(arfcn<=62)
/*AD6546*/         {  if(arfcn<=21)
/*AD6546*/            {                                /* ARFCN : 0~21     */
/*AD6546*/                *rfN = (((arfcn)*28+580)<<13) | 0x1506L /*(42L<<7|0x06L)*/;
/*AD6546*/            }
/*AD6546*/            else
/*AD6546*/            {                              /* ARFCN : 22~62     */
/*AD6546*/                *rfN = (((arfcn-22)*28+26)<<13) | 0x1586L /*(43L<<7|0x06L)*/;
/*AD6546*/            }
/*AD6546*/         }
/*AD6546*/         else
/*AD6546*/         {  if(arfcn<=124)
/*AD6546*/            {   if(arfcn<=104)
/*AD6546*/                {                                /* ARFCN : 63~104     */
/*AD6546*/                   *rfN = (((arfcn-63)*28+4)<<13) | 0x1606L /*(44L<<7|0x06L)*/;
/*AD6546*/                }
/*AD6546*/                else
/*AD6546*/                {                                /* ARFCN : 105~124     */
/*AD6546*/                   *rfN = (((arfcn-105)*28+10)<<13) | 0x1686L /*(45L<<7|0x06L)*/;
/*AD6546*/                }
/*AD6546*/            }
/*AD6546*/            else
/*AD6546*/            {  if(arfcn<=1003)
/*AD6546*/                {                                /* ARFCN : 975~1003     */
/*AD6546*/                   *rfN = (((arfcn-975)*28+378)<<13) | 0x1486L /*(41L<<7|0x06L)*/;
/*AD6546*/                }
/*AD6546*/                else
/*AD6546*/                {                                /* ARFCN : 1004~1023     */
/*AD6546*/                   *rfN = (((arfcn-1004)*28+20)<<13) | 0x1506L /*(42L<<7|0x06L)*/;
/*AD6546*/                }
/*AD6546*/            }
/*AD6546*/         }
/*AD6546*/         break;
/*AD6546*/      }
/*AD6546*/      case  FrequencyBand1800 :
/*AD6546*/      {
/*AD6546*/         if(arfcn<=694)
/*AD6546*/         {  if(arfcn<=605)
/*AD6546*/            { if(arfcn<=517)
/*AD6546*/              {                                /* ARFCN : 512~517     */
/*AD6546*/                *rfN = (((arfcn-512)*14+1154)<<13) | 0x1006L /*(32L<<7|0x06L)*/;
/*AD6546*/              }
/*AD6546*/              else
/*AD6546*/              {                                /* ARFCN : 518~605     */
/*AD6546*/                *rfN = (((arfcn-518)*14+3)<<13) | 0x1086L /*(33L<<7|0x06L)*/;
/*AD6546*/              }
/*AD6546*/            }
/*AD6546*/            else
/*AD6546*/            {                                  /* ARFCN : 606~694     */
/*AD6546*/                *rfN = (((arfcn-606)*14)<<13) | 0x1106L /*(34L<<7|0x06L)*/;
/*AD6546*/            }
/*AD6546*/         }
/*AD6546*/         else
/*AD6546*/         {  if(arfcn<=782)
/*AD6546*/            {                                  /* ARFCN : 695~782     */
/*AD6546*/               *rfN = (((arfcn-695)*14+11)<<13) | 0x1186L /*(35L<<7|0x06L)*/;
/*AD6546*/            }
/*AD6546*/            else
/*AD6546*/            { if(arfcn<=870)
/*AD6546*/              {                               /* ARFCN : 783~870     */
/*AD6546*/                *rfN = (((arfcn-783)*14+8)<<13) | 0x1206L /*(36L<<7|0x06L)*/;
/*AD6546*/              }
/*AD6546*/              else
/*AD6546*/              {                                /* ARFCN : 871~885     */
/*AD6546*/                *rfN = (((arfcn-871)*14+5)<<13) | 0x1286L /*(37L<<7|0x06L)*/;
/*AD6546*/              }
/*AD6546*/            }
/*AD6546*/         }
/*AD6546*/         break;
/*AD6546*/      }
/*AD6546*/      case  FrequencyBand1900 :
/*AD6546*/      {
/*AD6546*/         if(arfcn<=699)
/*AD6546*/         {  if(arfcn<=611)
/*AD6546*/            { if(arfcn<=523)
/*AD6546*/              {                                /* ARFCN : 512~523     */
/*AD6546*/                *rfN = (((arfcn-512)*14+1074)<<13) | 0x1406L /*(40L<<7|0x06L)*/;
/*AD6546*/              }
/*AD6546*/              else
/*AD6546*/              {                                /* ARFCN : 524~611     */
/*AD6546*/                *rfN = (((arfcn-524)*14+7)<<13) | 0x1486L /*(41L<<7|0x06L)*/;
/*AD6546*/              }
/*AD6546*/            }
/*AD6546*/            else
/*AD6546*/            {                                  /* ARFCN : 612~699     */
/*AD6546*/                *rfN = (((arfcn-612)*14+4)<<13) | 0x1506L /*(42L<<7|0x06L)*/;
/*AD6546*/            }
/*AD6546*/         }
/*AD6546*/         else
/*AD6546*/         {  if(arfcn<=788)
/*AD6546*/            {                                  /* ARFCN : 700~788     */
/*AD6546*/                *rfN = (((arfcn-700)*14+1)<<13) | 0x1586L /*(43L<<7|0x06L)*/;
/*AD6546*/            }
/*AD6546*/            else
/*AD6546*/            {                                  /* ARFCN : 789~810     */
/*AD6546*/                *rfN = (((arfcn-789)*14+12)<<13) | 0x1606L /*(44L<<7|0x06L)*/;
/*AD6546*/            }
/*AD6546*/         }
/*AD6546*/         break;
/*AD6546*/      }
/*AD6546*/      default :
/*AD6546*/      {
/*AD6546*/         break;
/*AD6546*/      }
/*AD6546*/   }
/*AD6546*/   *ifN = 0;
/*AD6546*/}
/*AD6546*//* ========================================================================== */
#endif

#if IS_RF_MT6162
/*MT6162*/unsigned long  TX_N_FRAC_THRESHOLD_LB = 7356163; /* 7356163/2^23 = 0.876922965 */
/*MT6162*/unsigned long  TX_N_FRAC_THRESHOLD_HB = 7485219; /* 7485219/2^23 = 0.892307639 */
/*MT6162*/         short AFC_TRx_Offset_Threshold_LB = 30; /* the offset range in LB is -30Hz ~ +30Hz*/
/*MT6162*/         short AFC_TRx_Offset_Threshold_HB = 60; /* the offset range in HB is -60Hz ~ +60Hz*/
/*MT6162*/extern   short AFC_TRx_Offset[5];
/*MT6162*/
/*MT6162*//* rfN : 0x61, SRX_FREQ=>SRX_B[5:0],SRX_A[0] and SRX_FRAC[11:0] */
/*MT6162*/void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6162*/{
/*MT6162*/   int channelFrequency = 0;
/*MT6162*/   int synthesizerFrequency = 0;
/*MT6162*/   int N_INT;
/*MT6162*/   int N_FRAC;
/*MT6162*/
/*MT6162*/   switch(rf_band)
/*MT6162*/   {
/*MT6162*/      case  FrequencyBand850 :
/*MT6162*/      {  channelFrequency = 8242+2*(arfcn-128)+450; /* 824.2+0.2*(arfcn-128)+45 */
/*MT6162*/         synthesizerFrequency = 4*channelFrequency;
/*MT6162*/
/*MT6162*/         if(arfcn<=201)
/*MT6162*/         {  if(arfcn<=136)
/*MT6162*/            {  /* ARFCN : 128~136 */
/*MT6162*/               *rfN = ((arfcn-128)*32+1792) | (66<<12);
/*MT6162*/            }
/*MT6162*/            else
/*MT6162*/            {  /* ARFCN : 137~201 */
/*MT6162*/               *rfN = ((arfcn-137)*32) | (67<<12);
/*MT6162*/            }
/*MT6162*/         }
/*MT6162*/         else
/*MT6162*/         {  /* ARFCN : 202~251 */
/*MT6162*/            *rfN = ((arfcn-202)*32) | (68<<12);
/*MT6162*/         }
/*MT6162*/         break;
/*MT6162*/      }
/*MT6162*/      case  FrequencyBand900 :
/*MT6162*/      {
/*MT6162*/		   if(arfcn<=124)
/*MT6162*/		   {  channelFrequency = 8900+2*(arfcn)+450; /* 890+0.2*(arfcn)+45 */
/*MT6162*/         }
/*MT6162*/         else
/*MT6162*/         {  channelFrequency = 8900+2*(arfcn-1024)+450; /* 890+0.2*(arfcn-1024)+45 */
/*MT6162*/         }
/*MT6162*/         synthesizerFrequency = 4*channelFrequency;
/*MT6162*/
/*MT6162*/         if(arfcn<=124)
/*MT6162*/         {  if(arfcn<=69)
/*MT6162*/            {  if(arfcn<=4)
/*MT6162*/               {  /* ARFCN : 0~4 */
/*MT6162*/                  *rfN = ((arfcn)*32+1920) | (71<<12);
/*MT6162*/               }
/*MT6162*/               else
/*MT6162*/               {  /* ARFCN : 5~69 */
/*MT6162*/                  *rfN = ((arfcn-5)*32) | (72<<12);
/*MT6162*/               }
/*MT6162*/            }
/*MT6162*/            else
/*MT6162*/            {  /* ARFCN : 70~124 */
/*MT6162*/               *rfN = ((arfcn-70)*32) | (73<<12);
/*MT6162*/            }
/*MT6162*/         }
/*MT6162*/         else
/*MT6162*/         {  /* ARFCN : 975~1023 */
/*MT6162*/            *rfN = ((arfcn-975)*32+352) | (71<<12);
/*MT6162*/         }
/*MT6162*/         break;
/*MT6162*/      }
/*MT6162*/      case  FrequencyBand1800 :
/*MT6162*/      {
/*MT6162*/         channelFrequency = 17102+2*(arfcn-512)+950; /* 1710.2+0.2*(arfcn-512)+95 */
/*MT6162*/         synthesizerFrequency = 2*channelFrequency;
/*MT6162*/
/*MT6162*/         if(arfcn<=715)
/*MT6162*/         {  if(arfcn<=585)
/*MT6162*/            {  /* ARFCN : 512~585 */
/*MT6162*/               *rfN = ((arfcn-512)*16+896) | (69<<12);
/*MT6162*/            }
/*MT6162*/            else
/*MT6162*/            {  /* ARFCN : 586~715 */
/*MT6162*/               *rfN = ((arfcn-586)*16) | (70<<12);
/*MT6162*/            }
/*MT6162*/         }
/*MT6162*/         else
/*MT6162*/         {  if(arfcn<=845)
/*MT6162*/            {  /* ARFCN : 716~845 */
/*MT6162*/               *rfN = ((arfcn-716)*16) | (71<<12);
/*MT6162*/            }
/*MT6162*/            else
/*MT6162*/            {  /* ARFCN : 846~885 */
/*MT6162*/               *rfN = ((arfcn-846)*16) | (72<<12);
/*MT6162*/            }
/*MT6162*/         }
/*MT6162*/         break;
/*MT6162*/      }
/*MT6162*/      case  FrequencyBand1900 :
/*MT6162*/      {
/*MT6162*/         channelFrequency = 18502+2*(arfcn-512)+800; /* 1850.2+0.2*(arfcn-512)+80 */
/*MT6162*/         synthesizerFrequency = 2*channelFrequency;
/*MT6162*/
/*MT6162*/         if(arfcn<=740)
/*MT6162*/         {  if(arfcn<=610)
/*MT6162*/            {  /* ARFCN : 512~610 */
/*MT6162*/               *rfN = ((arfcn-512)*16+496) | (74<<12);
/*MT6162*/            }
/*MT6162*/            else
/*MT6162*/            {  /* ARFCN : 611~740 */
/*MT6162*/               *rfN = ((arfcn-611)*16) | (75<<12);
/*MT6162*/            }
/*MT6162*/         }
/*MT6162*/         else
/*MT6162*/         {  /* ARFCN : 741~810 */
/*MT6162*/            *rfN = ((arfcn-741)*16) | (76<<12);
/*MT6162*/         }
/*MT6162*/         break;
/*MT6162*/      }
/*MT6162*/   }
/*MT6162*/   N_INT = synthesizerFrequency/520;
/*MT6162*/   N_FRAC = ((synthesizerFrequency-520*N_INT)*2080) / 520;
/*MT6162*/   *rfN = (N_FRAC&0xFFF) | ((N_INT&0x7F)<<12);
/*MT6162*/}
/*MT6162*//* ========================================================================== */
/*MT6162*/
/*MT6162*//* rfN : 0x01, CW1=>N_INT[7:0] and N_FRAC[ 9: 0] */
/*MT6162*//* irN : 0x02, CW2=>               N_FRAC[22:10] */
/*MT6162*/void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6162*/{
/*MT6162*/   int channelFrequency = 0;
/*MT6162*/   int synthesizerFrequency = 0;
/*MT6162*/   int N_INT;
/*MT6162*/   int N_FRAC;
/*MT6162*/   int TRx_Offset_value;
/*MT6162*/
/*MT6162*/   l1d_rf2.arfcn = arfcn;  //for L1D_RF_SetTxGainWrite()
/*MT6162*/
/*MT6162*/   switch(rf_band)
/*MT6162*/   {
/*MT6162*/      case  FrequencyBand850 :
/*MT6162*/      {
/*MT6162*/         channelFrequency = 8242+2*(arfcn-128); /* 824.2+0.2*(arfcn-128) */
/*MT6162*/         synthesizerFrequency = 4*channelFrequency;
/*MT6162*/
/*MT6162*/         if(arfcn<=199)
/*MT6162*/         {  if(arfcn<=166)
/*MT6162*/            {  if(arfcn<=134)
/*MT6162*/               {  /* ARFCN : 128~134 */
/*MT6162*/                  *rfN = (((arfcn-128)*258111+6710886)&0x3FF) | (126<<10);
/*MT6162*/                  *ifN = (((arfcn-128)*258111+6710886)>>10)&0x1FFF;
/*MT6162*/               }
/*MT6162*/               else
/*MT6162*/               {  /* ARFCN : 135~166 */
/*MT6162*/                  *rfN = (((arfcn-135)*258111+129055)&0x3FF) | (127<<10);
/*MT6162*/                  *ifN = (((arfcn-135)*258111+129055)>>10)&0x1FFF;
/*MT6162*/               }
/*MT6162*/            }
/*MT6162*/            else
/*MT6162*/            {  /* ARFCN : 167~199 */
/*MT6162*/               *rfN = (((arfcn-167)*258111)&0x3FF) | (128<<10);
/*MT6162*/               *ifN = (((arfcn-167)*258111)>>10)&0x1FFF;
/*MT6162*/            }
/*MT6162*/         }
/*MT6162*/         else
/*MT6162*/         {  if(arfcn<=231)
/*MT6162*/            {  /* ARFCN : 200~231 */
/*MT6162*/               *rfN = (((arfcn-200)*258111+129055)&0x3FF) | (129<<10);
/*MT6162*/               *ifN = (((arfcn-200)*258111+129055)>>10)&0x1FFF;
/*MT6162*/            }
/*MT6162*/            else
/*MT6162*/            {  /* ARFCN : 232~251 */
/*MT6162*/               *rfN = (((arfcn-232)*258111)&0x3FF) | (130<<10);
/*MT6162*/               *ifN = (((arfcn-232)*258111)>>10)&0x1FFF;
/*MT6162*/            }
/*MT6162*/         }
/*MT6162*/         break;
/*MT6162*/      }
/*MT6162*/      case  FrequencyBand900 :
/*MT6162*/      {  if(arfcn<=124)
/*MT6162*/		   {  channelFrequency = 8900+2*(arfcn); /* 890+0.2*(arfcn) */
/*MT6162*/         }
/*MT6162*/         else
/*MT6162*/         {  channelFrequency = 8900+2*(arfcn-1024); /* 890+0.2*(arfcn-1024) */
/*MT6162*/         }
/*MT6162*/         synthesizerFrequency = 4*channelFrequency;
/*MT6162*/
/*MT6162*/         if(arfcn<=124)
/*MT6162*/         {  if(arfcn<=67)
/*MT6162*/            {  if(arfcn<=34)
/*MT6162*/               {  if(arfcn<=2)
/*MT6162*/                  {  /* ARFCN : 0~2 */
/*MT6162*/                     *rfN = (((arfcn-0)*258111+7743330)&0x3FF) | (136<<10);
/*MT6162*/                     *ifN = (((arfcn-0)*258111+7743330)>>10)&0x1FFF;
/*MT6162*/                  }
/*MT6162*/                  else
/*MT6162*/                  {  /* ARFCN : 3~34 */
/*MT6162*/                     *rfN = (((arfcn-3)*258111+129055)&0x3FF) | (137<<10);
/*MT6162*/                     *ifN = (((arfcn-3)*258111+129055)>>10)&0x1FFF;
/*MT6162*/                  }
/*MT6162*/               }
/*MT6162*/               else
/*MT6162*/               {  /* ARFCN : 35~67 */
/*MT6162*/                  *rfN = (((arfcn-35)*258111)&0x3FF) | (138<<10);
/*MT6162*/                  *ifN = (((arfcn-35)*258111)>>10)&0x1FFF;
/*MT6162*/               }
/*MT6162*/            }
/*MT6162*/            else
/*MT6162*/            {	 if(arfcn<=99)
/*MT6162*/               {  /* ARFCN : 68~99 */
/*MT6162*/                  *rfN = (((arfcn-68)*258111+129055)&0x3FF) | (139<<10);
/*MT6162*/                  *ifN = (((arfcn-68)*258111+129055)>>10)&0x1FFF;
/*MT6162*/               }
/*MT6162*/               else
/*MT6162*/               {  /* ARFCN : 100~124 */
/*MT6162*/                  *rfN = (((arfcn-100)*258111)&0x3FF) | (140<<10);
/*MT6162*/                  *ifN = (((arfcn-100)*258111)>>10)&0x1FFF;
/*MT6162*/               }
/*MT6162*/            }
/*MT6162*/         }
/*MT6162*/         else
/*MT6162*/         {  if(arfcn<=993)
/*MT6162*/            {   /* ARFCN : 975~993 */
/*MT6162*/                *rfN = (((arfcn-975)*258111+3484498)&0x3FF) | (135<<10);
/*MT6162*/                *ifN = (((arfcn-975)*258111+3484498)>>10)&0x1FFF;
/*MT6162*/            }
/*MT6162*/            else
/*MT6162*/            {   /* ARFCN : 994~1023 */
/*MT6162*/                *rfN = (((arfcn-994)*258111)&0x3FF) | (136<<10);
/*MT6162*/                *ifN = (((arfcn-994)*258111)>>10)&0x1FFF;
/*MT6162*/            }
/*MT6162*/         }
/*MT6162*/         break;
/*MT6162*/      }
/*MT6162*/      case  FrequencyBand1800 :
/*MT6162*/      {
/*MT6162*/         channelFrequency = 17102+2*(arfcn-512); /* 1710.2+0.2*(arfcn-512) */
/*MT6162*/         synthesizerFrequency = 2*channelFrequency;
/*MT6162*/
/*MT6162*/         if(arfcn<=735)
/*MT6162*/         {  if(arfcn<=670)
/*MT6162*/            {  if(arfcn<=605)
/*MT6162*/               {  if(arfcn<=540)
/*MT6162*/                  {  /* ARFCN : 512~540 */
/*MT6162*/                     *rfN = (((arfcn-512)*129055+4645998+(arfcn-512)/2)&0x3FF) | (131<<10);
/*MT6162*/                     *ifN = (((arfcn-512)*129055+4645998+(arfcn-512)/2)>>10)&0x1FFF;
/*MT6162*/                  }
/*MT6162*/                  else
/*MT6162*/                  {  /* ARFCN : 541~605 */
/*MT6162*/                     *rfN = (((arfcn-541)*129055+(arfcn-541)/2)&0x3FF) | (132<<10);
/*MT6162*/                     *ifN = (((arfcn-541)*129055+(arfcn-541)/2)>>10)&0x1FFF;
/*MT6162*/                  }
/*MT6162*/               }
/*MT6162*/               else
/*MT6162*/               {  /* ARFCN : 606~670 */
/*MT6162*/                  *rfN = (((arfcn-606)*129055+(arfcn-606)/2)&0x3FF) | (133<<10);
/*MT6162*/                  *ifN = (((arfcn-606)*129055+(arfcn-606)/2)>>10)&0x1FFF;
/*MT6162*/               }
/*MT6162*/            }
/*MT6162*/            else
/*MT6162*/            {   /* ARFCN : 671~735 */
/*MT6162*/                *rfN = (((arfcn-671)*129055+(arfcn-671)/2)&0x3FF) | (134<<10);
/*MT6162*/                *ifN = (((arfcn-671)*129055+(arfcn-671)/2)>>10)&0x1FFF;
/*MT6162*/            }
/*MT6162*/         }
/*MT6162*/         else
/*MT6162*/         {  if(arfcn<=865)
/*MT6162*/            {  if(arfcn<=800)
/*MT6162*/               {  /* ARFCN : 736~800 */
/*MT6162*/                  *rfN = (((arfcn-736)*129055+(arfcn-736)/2)&0x3FF) | (135<<10);
/*MT6162*/                  *ifN = (((arfcn-736)*129055+(arfcn-736)/2)>>10)&0x1FFF;
/*MT6162*/               }
/*MT6162*/               else
/*MT6162*/               {  /* ARFCN : 801~865 */
/*MT6162*/                  *rfN = (((arfcn-801)*129055+(arfcn-801)/2)&0x3FF) | (136<<10);
/*MT6162*/                  *ifN = (((arfcn-801)*129055+(arfcn-801)/2)>>10)&0x1FFF;
/*MT6162*/               }
/*MT6162*/            }
/*MT6162*/            else
/*MT6162*/            {  /* ARFCN : 866~885 */
/*MT6162*/               *rfN = (((arfcn-866)*129055+(arfcn-866)/2)&0x3FF) | (137<<10);
/*MT6162*/               *ifN = (((arfcn-866)*129055+(arfcn-866)/2)>>10)&0x1FFF;
/*MT6162*/            }
/*MT6162*/         }
/*MT6162*/         break;
/*MT6162*/      }
/*MT6162*/      case  FrequencyBand1900 :
/*MT6162*/      {
/*MT6162*/         channelFrequency = 18502+2*(arfcn-512); /* 1850.2+0.2*(arfcn-512) */
/*MT6162*/         synthesizerFrequency = 2*channelFrequency;
/*MT6162*/
/*MT6162*/         if(arfcn<=685)
/*MT6162*/         {  if(arfcn<=620)
/*MT6162*/            {  if(arfcn<=555)
/*MT6162*/               {  /* ARFCN : 512~555 */
/*MT6162*/                  *rfN = (((arfcn-512)*129056+2710165-(arfcn-512)/2)&0x3FF) | (142<<10);
/*MT6162*/                  *ifN = (((arfcn-512)*129056+2710165-(arfcn-512)/2)>>10)&0x1FFF;
/*MT6162*/               }
/*MT6162*/               else
/*MT6162*/               {  /* ARFCN : 556~620 */
/*MT6162*/                  *rfN = (((arfcn-556)*129055+(arfcn-556)/2)&0x3FF) | (143<<10);
/*MT6162*/                  *ifN = (((arfcn-556)*129055+(arfcn-556)/2)>>10)&0x1FFF;
/*MT6162*/               }
/*MT6162*/            }
/*MT6162*/            else
/*MT6162*/            {   /* ARFCN : 621~685 */
/*MT6162*/                *rfN = (((arfcn-621)*129055+(arfcn-621)/2)&0x3FF) | (144<<10);
/*MT6162*/                *ifN = (((arfcn-621)*129055+(arfcn-621)/2)>>10)&0x1FFF;
/*MT6162*/            }
/*MT6162*/         }
/*MT6162*/         else
/*MT6162*/         {  if(arfcn<=750)
/*MT6162*/            {  /* ARFCN : 686~750 */
/*MT6162*/               *rfN = (((arfcn-686)*129055+(arfcn-686)/2)&0x3FF) | (145<<10);
/*MT6162*/               *ifN = (((arfcn-686)*129055+(arfcn-686)/2)>>10)&0x1FFF;
/*MT6162*/            }
/*MT6162*/            else
/*MT6162*/            {  /* ARFCN : 751~810 */
/*MT6162*/               *rfN = (((arfcn-751)*129055+(arfcn-751)/2)&0x3FF) | (146<<10);
/*MT6162*/               *ifN = (((arfcn-751)*129055+(arfcn-751)/2)>>10)&0x1FFF;
/*MT6162*/            }
/*MT6162*/         }
/*MT6162*/         break;
/*MT6162*/      }
/*MT6162*/   }
/*MT6162*/   N_INT = synthesizerFrequency/260;
/*MT6162*/   N_FRAC = ((synthesizerFrequency-260*N_INT)<<21) / 65; /* ((synthesizerFrequency-260*N_INT)<<23) / 260 */
/*MT6162*/
/*MT6162*/   if( L1D_RF_Get6162Version() == 1 )
/*MT6162*/   {  /* for OH E1, do nothing */  }
/*MT6162*/   else
/*MT6162*/   {  /* for OH E2 */
/*MT6162*/      l1d_rf2.is_integer = (N_FRAC == 0) ? 1 : 0;
/*MT6162*/      if( rf_band <= FrequencyBand900 )
/*MT6162*/      {  l1d_rf2.is_isotpol = (N_FRAC > TX_N_FRAC_THRESHOLD_LB) ? 1 : 0;  }
/*MT6162*/      else
/*MT6162*/      {  l1d_rf2.is_isotpol = (N_FRAC > TX_N_FRAC_THRESHOLD_HB) ? 1 : 0;  }
/*MT6162*/   }
/*MT6162*/
/*MT6162*/   if( rf_band <= FrequencyBand900 )
/*MT6162*/   {
/*MT6162*/      if( AFC_TRx_Offset[rf_band] > AFC_TRx_Offset_Threshold_LB )
/*MT6162*/      {  TRx_Offset_value = (int)((AFC_TRx_Offset_Threshold_LB*258111)/200000);  }
/*MT6162*/      else if( AFC_TRx_Offset[rf_band] < (-AFC_TRx_Offset_Threshold_LB) )
/*MT6162*/      {  TRx_Offset_value = (int)(((-AFC_TRx_Offset_Threshold_LB)*258111)/200000);  }
/*MT6162*/      else
/*MT6162*/      {  TRx_Offset_value = (int)((AFC_TRx_Offset[rf_band]*258111)/200000);  }
/*MT6162*/   }
/*MT6162*/   else
/*MT6162*/   {
/*MT6162*/      if( AFC_TRx_Offset[rf_band] > AFC_TRx_Offset_Threshold_HB )
/*MT6162*/      {  TRx_Offset_value = (int)((AFC_TRx_Offset_Threshold_HB*129055)/200000);  }
/*MT6162*/      else if( AFC_TRx_Offset[rf_band] < (-AFC_TRx_Offset_Threshold_HB) )
/*MT6162*/      {  TRx_Offset_value = (int)(((-AFC_TRx_Offset_Threshold_HB)*129055)/200000);  }
/*MT6162*/      else
/*MT6162*/      {  TRx_Offset_value = (int)((AFC_TRx_Offset[rf_band]*129055)/200000);  }
/*MT6162*/   }
/*MT6162*/
/*MT6162*/   if( N_FRAC == 0 )
/*MT6162*/   {
/*MT6162*/      if( TRx_Offset_value >= 0 )
/*MT6162*/      {  N_FRAC += TRx_Offset_value;  }
/*MT6162*/      else
/*MT6162*/      {
/*MT6162*/         N_INT  -= 1;
/*MT6162*/         N_FRAC  = 8388608+TRx_Offset_value; /* 2^23 = 8388608 */
/*MT6162*/      }
/*MT6162*/   }
/*MT6162*/   else
/*MT6162*/   {  N_FRAC += TRx_Offset_value;  }
/*MT6162*/
/*MT6162*/   *rfN = (N_FRAC&0x3FF) | ((N_INT&0xFF)<<10);
/*MT6162*/   *ifN = (N_FRAC>>10)&0x1FFF;
/*MT6162*/}
/*MT6162*//* ========================================================================== */
#endif

#if IS_RF_MT6163
/*MT6163*/  /* rfN : 0x01, CW1=>N_INT[7:0] and N_FRAC[ 9: 0] */
/*MT6163*/  /* irN : 0x02, CW2=>               N_FRAC[22:10] */
/*MT6163*/
/*MT6163*/  #define TX_NEAR_INT_N_FRAC_MIN  167772
/*MT6163*/  #define TX_NEAR_INT_N_FRAC_MAX  754974
/*MT6163*/  #define N_FRAC_DIFF_200KHZ_LB   258111    /* LB N_FRAC difference of neighboring ARFCN (200KHz) */
/*MT6163*/  #define N_FRAC_DIFF_200KHZ_HB   129055    /* HB N_FRAC difference of neighboring ARFCN (200KHz) */
/*MT6163*/  #define N_FRAC_MIN              0
/*MT6163*/  #define N_FRAC_MAX              8388608   /* 2^23 */
/*MT6163*/  #define AFC_TRX_OFFSET_BOUND_LB 30        /* offset range in LB is -30Hz ~ +30Hz */
/*MT6163*/  #define AFC_TRX_OFFSET_BOUND_HB 60        /* offset range in HB is -60Hz ~ +60Hz */
/*MT6163*/  #define CW2_DFM_SDM_IFM_ON_SET  (0x1<<13)
/*MT6163*/
/*MT6163*/  extern short AFC_TRx_Offset[FrequencyBandCount];
/*MT6163*/
/*MT6163*/  static void L1D_RF_ComputeTxPLLFreq( char is_Rx, int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6163*/  {
/*MT6163*/     int   channelFrequency     = 0;
/*MT6163*/     int   synthesizerFrequency = 0;
/*MT6163*/     int   N_INT, N_FRAC, frac_diff;
/*MT6163*/     short trx_offset_bound;
/*MT6163*/     char  int_mask             = 0x1<<is_Rx;   /* bit1: RX, bit0: TX */
/*MT6163*/     unsigned long sdm          = 0;
/*MT6163*/
/*MT6163*/     if( is_Rx )
/*MT6163*/     {  /* Add freq offset of RX/TX at the same ARFCN */
/*MT6163*/        switch( rf_band )
/*MT6163*/        {
/*MT6163*/           case FrequencyBand850:
/*MT6163*/           case FrequencyBand900:
/*MT6163*/           {
/*MT6163*/              channelFrequency = 450;  /* 45 MHz */
/*MT6163*/              break;
/*MT6163*/           }
/*MT6163*/           case FrequencyBand1800:
/*MT6163*/           {
/*MT6163*/              channelFrequency = 950;  /* 95 MHz */
/*MT6163*/              break;
/*MT6163*/           }
/*MT6163*/           case FrequencyBand1900:
/*MT6163*/           {
/*MT6163*/              channelFrequency = 800;  /* 80 MHz */
/*MT6163*/              break;
/*MT6163*/           }
/*MT6163*/        }
/*MT6163*/     }
/*MT6163*/
/*MT6163*/     switch( rf_band )
/*MT6163*/     {
/*MT6163*/        case FrequencyBand850:
/*MT6163*/        {
/*MT6163*/           channelFrequency += (8242 + 2*(arfcn-128));        /*  824.2 + 0.2*(arfcn-128)   */
/*MT6163*/           synthesizerFrequency = 4*channelFrequency;
/*MT6163*/           break;
/*MT6163*/        }
/*MT6163*/        case FrequencyBand900:
/*MT6163*/        {
/*MT6163*/           if(arfcn<=124)
/*MT6163*/           {  channelFrequency += (8900 + 2*(arfcn));      }  /*  890.0 + 0.2*(arfcn)       */
/*MT6163*/           else
/*MT6163*/           {  channelFrequency += (8900 + 2*(arfcn-1024)); }  /*  890.0 + 0.2*(arfcn-1024)  */
/*MT6163*/           synthesizerFrequency = 4*channelFrequency;
/*MT6163*/           break;
/*MT6163*/        }
/*MT6163*/        case FrequencyBand1800:
/*MT6163*/        {
/*MT6163*/           channelFrequency += (17102 + 2*(arfcn-512));       /* 1710.2 + 0.2*(arfcn-512)   */
/*MT6163*/           synthesizerFrequency = 2*channelFrequency;
/*MT6163*/           break;
/*MT6163*/        }
/*MT6163*/        case FrequencyBand1900:
/*MT6163*/        {
/*MT6163*/           channelFrequency += (18502 + 2*(arfcn-512));       /* 1850.2 + 0.2*(arfcn-512)   */
/*MT6163*/           synthesizerFrequency = 2*channelFrequency;
/*MT6163*/           break;
/*MT6163*/        }
/*MT6163*/     }
/*MT6163*/
/*MT6163*/     N_INT = synthesizerFrequency/260;
/*MT6163*/     N_FRAC = ((synthesizerFrequency - 260*N_INT)<<21) / 65;  /* ((synthesizerFrequency-260*N_INT)<<23) / 260 */
/*MT6163*/
/*MT6163*/     /* add TRX offset */
/*MT6163*/     if( is_Rx )
/*MT6163*/     {  /* do nothing for RX */ }
/*MT6163*/     else
/*MT6163*/     {
/*MT6163*/        if( rf_band <= FrequencyBand900 )
/*MT6163*/        {
/*MT6163*/           trx_offset_bound = AFC_TRX_OFFSET_BOUND_LB;
/*MT6163*/           frac_diff        = N_FRAC_DIFF_200KHZ_LB;
/*MT6163*/        }
/*MT6163*/        else
/*MT6163*/        {
/*MT6163*/           trx_offset_bound = AFC_TRX_OFFSET_BOUND_HB;
/*MT6163*/           frac_diff        = N_FRAC_DIFF_200KHZ_HB;
/*MT6163*/        }
/*MT6163*/
/*MT6163*/        if( AFC_TRx_Offset[rf_band] > trx_offset_bound )
/*MT6163*/        {  AFC_TRx_Offset[rf_band] = trx_offset_bound;  }
/*MT6163*/        else if( AFC_TRx_Offset[rf_band] < (-1)*trx_offset_bound )
/*MT6163*/        {  AFC_TRx_Offset[rf_band] = (-1)*trx_offset_bound;  }
/*MT6163*/
/*MT6163*/        N_FRAC += (int)(AFC_TRx_Offset[rf_band]*frac_diff/200000);
/*MT6163*/
/*MT6163*/        if( N_FRAC >= N_FRAC_MAX )
/*MT6163*/        {
/*MT6163*/           N_FRAC -= N_FRAC_MAX;
/*MT6163*/           N_INT++;
/*MT6163*/        }
/*MT6163*/        else if( N_FRAC < N_FRAC_MIN )
/*MT6163*/        {
/*MT6163*/           N_FRAC += N_FRAC_MAX;
/*MT6163*/           N_INT--;
/*MT6163*/        }
/*MT6163*/     }
/*MT6163*/
/*MT6163*/     /* integer channel check */
/*MT6163*/     if( N_FRAC == 0 )
/*MT6163*/     {  l1d_rf2.is_integer |=  int_mask;  }  /* integer */
/*MT6163*/     else
/*MT6163*/     {  l1d_rf2.is_integer &= ~int_mask;  }  /* not integer */
/*MT6163*/
/*MT6163*/     /* near-integer channel check */
/*MT6163*/     if( is_Rx )
/*MT6163*/     {  sdm = (l1d_rf2.is_integer&0x2) ? 0 : CW2_DFM_SDM_IFM_ON_SET;                                    }  /* turn off for integer channels */
/*MT6163*/     else
/*MT6163*/     {  l1d_rf2.is_isotpol = (N_FRAC>TX_NEAR_INT_N_FRAC_MIN && N_FRAC<TX_NEAR_INT_N_FRAC_MAX) ? 1 : 0;  }
/*MT6163*/
/*MT6163*/     *rfN = (N_FRAC&0x3FF) | ((N_INT&0xFF)<<10);
/*MT6163*/     *ifN = (sdm)|((N_FRAC>>10)&0x1FFF);
/*MT6163*/  }
/*MT6163*/  /* ========================================================================== */
/*MT6163*/
/*MT6163*/  void L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6163*/  {
/*MT6163*/     L1D_RF_ComputeTxPLLFreq( 1/*RX*/, rf_band, arfcn, rfN, ifN );
/*MT6163*/  }
/*MT6163*/  /* ========================================================================== */
/*MT6163*/
/*MT6163*/  void L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6163*/  {
/*MT6163*/     l1d_rf2.arfcn = arfcn;  //for L1D_RF_SetTxGainWrite()
/*MT6163*/     L1D_RF_ComputeTxPLLFreq( 0/*TX*/, rf_band, arfcn, rfN, ifN );
/*MT6163*/  }
/*MT6163*/  /* ========================================================================== */
#endif

#if IS_RF_MT6280RF
/*MT6280RF*/ void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6280RF*/ {  long *if_sel = ifN+1;
/*MT6280RF*/    unsigned short Nint =0, CH_freq =0;
/*MT6280RF*/    unsigned long  Nfrac=0, VCO_freq=0;
/*MT6280RF*/
/*MT6280RF*/    CH_freq = L1D_RF_ARFCN_CH_to_RxFreq( rf_band, arfcn );
/*MT6280RF*/
/*MT6280RF*/    *if_sel = 0;
/*MT6280RF*/    if( rf_band < FrequencyBand1800 )
/*MT6280RF*/       VCO_freq = 4*(CH_freq*DLIF_SCALE - DLIF);
/*MT6280RF*/    else
/*MT6280RF*/       VCO_freq = 2*(CH_freq*DLIF_SCALE - DLIF);
/*MT6280RF*/
/*MT6280RF*/    Nint  = VCO_freq/(RX_DCXO_FREQ*DLIF_SCALE);
/*MT6280RF*/    //+195/2 is for rounding, 195=13*3*5, 5 is SYNTH_SCALE, 13 and 3 are related to DLIF
/*MT6280RF*/    Nfrac = ( (((VCO_freq-Nint*RX_DCXO_FREQ*DLIF_SCALE)*2080)<<3) + (195)/2 )/195;
/*MT6280RF*/
/*MT6280RF*/    /* CW99,  N_INT[6:0], N_RFC[23:11] */
/*MT6280RF*/    *rfN = BSI_CW( 0x63, ((Nint &0x7F)<<13) | (Nfrac>>11) );
/*MT6280RF*/    /* CW100, N_FRAC[10:0], DITHER_MASK[4:0] */
/*MT6280RF*/    *ifN = BSI_CW( 0x64, ((Nfrac&0x7FF)<<9) | 0x10 );
/*MT6280RF*/
/*MT6280RF*/ }
/*MT6280RF*/ /* =========================================================================== */
/*MT6280RF*/
/*MT6280RF*/ void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6280RF*/ {
/*MT6280RF*/    unsigned short Nint =0, CH_freq =0;
/*MT6280RF*/    unsigned long  Nfrac=0, VCO_freq=0;
/*MT6280RF*/    unsigned short DAoffset=0;
/*MT6280RF*/
/*MT6280RF*/
/*MT6280RF*/    l1d_rf2.arfcn = arfcn;  //for L1D_RF_TxGainSetting
/*MT6280RF*/    CH_freq = L1D_RF_ARFCN_CH_to_TxFreq( rf_band, arfcn );
/*MT6280RF*/
/*MT6280RF*/    if( rf_band < FrequencyBand1800 )
/*MT6280RF*/       VCO_freq = 4*CH_freq;
/*MT6280RF*/    else
/*MT6280RF*/       VCO_freq = 2*CH_freq;
/*MT6280RF*/
/*MT6280RF*/    Nint  = VCO_freq/TX_DCXO_FREQ;
/*MT6280RF*/    Nfrac = ( ((VCO_freq-Nint*TX_DCXO_FREQ)<<23) + TX_DCXO_FREQ/2 )/TX_DCXO_FREQ;  //+TX_DCXO_FREQ/2 is for rounding
/*MT6280RF*/
/*MT6280RF*/    DAoffset = L1D_RF_GetTxDAoffsetSetting( Nint );
/*MT6280RF*/
/*MT6280RF*/    /* CW95, N_INT[7:0], N_RFC[22:11] */
/*MT6280RF*/    *rfN = BSI_CW( 0x5F, ((Nint &0xFF)<<12) | (Nfrac>>11) );
/*MT6280RF*/    /* CW96, N_FRAC[10:0], DA_OFFSET[7:0], DI_EN */
/*MT6280RF*/    *ifN = BSI_CW( 0x60, ((Nfrac&0x7FF)<<9) | ((DAoffset&0xFF)<<1) | 0x1);
/*MT6280RF*/
/*MT6280RF*/ }
/*MT6280RF*/ /* =========================================================================== */
/*MT6280RF*/
/*MT6280RF*/ unsigned short L1D_RF_ARFCN_CH_to_RxFreq( int rf_band, int arfcn )
/*MT6280RF*/ {
/*MT6280RF*/    unsigned short freq=4450+225;
/*MT6280RF*/    switch( rf_band )
/*MT6280RF*/    {
/*MT6280RF*/       case  FrequencyBand850 :
/*MT6280RF*/       {
/*MT6280RF*/          freq=4121+(arfcn-128)+225;     //freq = f_ch*SYNTH_SCALE
/*MT6280RF*/          break;
/*MT6280RF*/       }
/*MT6280RF*/       case  FrequencyBand900 :
/*MT6280RF*/       {
/*MT6280RF*/          if( arfcn<=124 )
/*MT6280RF*/          {  freq=4450+arfcn+225;  }
/*MT6280RF*/          else
/*MT6280RF*/          {  freq=4450+(arfcn-1024)+225;  }
/*MT6280RF*/          break;
/*MT6280RF*/       }
/*MT6280RF*/       case  FrequencyBand1800 :
/*MT6280RF*/       {
/*MT6280RF*/          freq=8551+(arfcn-512)+475;
/*MT6280RF*/          break;
/*MT6280RF*/       }
/*MT6280RF*/       case  FrequencyBand1900 :
/*MT6280RF*/       {
/*MT6280RF*/          freq=9251+(arfcn-512)+400;
/*MT6280RF*/          break;
/*MT6280RF*/       }
/*MT6280RF*/       default :
/*MT6280RF*/       {
/*MT6280RF*/          break;
/*MT6280RF*/       }
/*MT6280RF*/    }
/*MT6280RF*/
/*MT6280RF*/    return freq;
/*MT6280RF*/ }
/*MT6280RF*/ /* =========================================================================== */
/*MT6280RF*/
/*MT6280RF*/ unsigned short L1D_RF_ARFCN_CH_to_TxFreq( int rf_band, int arfcn )
/*MT6280RF*/ {
/*MT6280RF*/    unsigned short freq=4450;
/*MT6280RF*/    switch( rf_band )
/*MT6280RF*/    {
/*MT6280RF*/       case  FrequencyBand850 :
/*MT6280RF*/       {
/*MT6280RF*/          freq=4121+(arfcn-128);     //freq = f_ch*SYNTH_SCALE
/*MT6280RF*/          break;
/*MT6280RF*/       }
/*MT6280RF*/       case  FrequencyBand900 :
/*MT6280RF*/       {
/*MT6280RF*/          if( arfcn<=124 )
/*MT6280RF*/          {  freq=4450+arfcn;  }
/*MT6280RF*/          else
/*MT6280RF*/          {  freq=4450+(arfcn-1024);  }
/*MT6280RF*/          break;
/*MT6280RF*/       }
/*MT6280RF*/       case  FrequencyBand1800 :
/*MT6280RF*/       {
/*MT6280RF*/          freq=8551+(arfcn-512);
/*MT6280RF*/          break;
/*MT6280RF*/       }
/*MT6280RF*/       case  FrequencyBand1900 :
/*MT6280RF*/       {
/*MT6280RF*/          freq=9251+(arfcn-512);
/*MT6280RF*/          break;
/*MT6280RF*/       }
/*MT6280RF*/       default :
/*MT6280RF*/       {
/*MT6280RF*/          break;
/*MT6280RF*/       }
/*MT6280RF*/    }
/*MT6280RF*/
/*MT6280RF*/    return freq;
/*MT6280RF*/ }
/*MT6280RF*/ /* =========================================================================== */
/*MT6280RF*/
/*MT6280RF*/ unsigned short L1D_RF_GetTxDCOSCACodeTypeSetting(unsigned short Nint, unsigned long  Nfrac)
/*MT6280RF*/ {
/*MT6280RF*/    char segment_tx=3, LUT_num_tx=8, offset_tx=13; // LUT method related parameters
/*MT6280RF*/    unsigned short TXDCO_LUT[8]={1865, 1424, 1067, 774, 534, 331, 160, 13};  // TXDCO LUT
/*MT6280RF*/    short idx, x_axis, code_type;  // code_type value for SCA calibration (code_type > 0)
/*MT6280RF*/
/*MT6280RF*/    /* STX DCO SCA Typical Code LUT */
/*MT6280RF*/	idx = (Nint>>segment_tx)-((short)offset_tx);
/*MT6280RF*/    if(idx<0)
/*MT6280RF*/       idx = 0;
/*MT6280RF*/    else if(idx>(LUT_num_tx-2))
/*MT6280RF*/       idx = LUT_num_tx-2;
/*MT6280RF*/
/*MT6280RF*/    x_axis      = ((Nint-((Nint>>segment_tx)<<segment_tx))<<3)+((short)(Nfrac>>20));
/*MT6280RF*/    code_type   = TXDCO_LUT[idx]+ ((x_axis*(TXDCO_LUT[idx+1]-TXDCO_LUT[idx]))>>(segment_tx+3));
/*MT6280RF*/    code_type <<= 1;
/*MT6280RF*/
/*MT6280RF*/    return code_type;
/*MT6280RF*/ }
/*MT6280RF*/ /* =========================================================================== */
/*MT6280RF*/
/*MT6280RF*/ unsigned short L1D_RF_GetTxDEMChunkSetting(int rf_band, unsigned short Nint)
/*MT6280RF*/ {
/*MT6280RF*/    unsigned short DEM_Chunk_L1;
/*MT6280RF*/    unsigned short OUT_G, OUT_E;
/*MT6280RF*/    char segment_dem=4, LUT_num_dem=4, offset_dem=7;     // LUT method related parameters
/*MT6280RF*/    unsigned short DEM_chunk_G_LUT[4]={15, 10,  7,  5};  // DEM chunk GMSK LUT
/*MT6280RF*/    unsigned short DEM_chunk_E_LUT[4]={69, 46, 33, 24};  // DEM chunk EPSK LUT
/*MT6280RF*/    short idx;
/*MT6280RF*/
/*MT6280RF*/    /* STX DEM CHUNK LUT */
/*MT6280RF*/	idx = (Nint>>segment_dem)-((short)offset_dem);
/*MT6280RF*/    if(idx<0)
/*MT6280RF*/       idx = 0;
/*MT6280RF*/    else if(idx>(LUT_num_dem-2))
/*MT6280RF*/       idx = LUT_num_dem-2;
/*MT6280RF*/
/*MT6280RF*/    OUT_G = DEM_chunk_G_LUT[idx]+(((Nint-((Nint>>segment_dem)<<segment_dem))*(DEM_chunk_G_LUT[idx+1]-DEM_chunk_G_LUT[idx]))>>(segment_dem));
/*MT6280RF*/    OUT_E = DEM_chunk_E_LUT[idx]+(((Nint-((Nint>>segment_dem)<<segment_dem))*(DEM_chunk_E_LUT[idx+1]-DEM_chunk_E_LUT[idx]))>>(segment_dem));
/*MT6280RF*/
/*MT6280RF*/    if( ( (l1d_rf.tx_mod_type2)^(l1d_rf.tx_mod_type2<<1) ) & 0xE )   // IS_MIXED_MULTISLOT
/*MT6280RF*/    {
/*MT6280RF*/       if( rf_band < FrequencyBand1800 )
/*MT6280RF*/          DEM_Chunk_L1 = ((OUT_E+OUT_G+5)>40) ? (OUT_E+OUT_G+5) : 40;
/*MT6280RF*/       else
/*MT6280RF*/          DEM_Chunk_L1 = 40;
/*MT6280RF*/    }
/*MT6280RF*/    else
/*MT6280RF*/    {
/*MT6280RF*/       if( (l1d_rf.tx_mod_type2 != 0) && (rf_band < FrequencyBand1800) )
/*MT6280RF*/          DEM_Chunk_L1 = ((2*OUT_E+6)>40) ? (2*OUT_E+6) : 40;
/*MT6280RF*/       else
/*MT6280RF*/          DEM_Chunk_L1 = 40;
/*MT6280RF*/    }
/*MT6280RF*/    return DEM_Chunk_L1;
/*MT6280RF*/ }
/*MT6280RF*/ /* =========================================================================== */
/*MT6280RF*/
/*MT6280RF*/ void L1D_RF_GetTxKDCOCAL2ndSetting(int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6280RF*/ {
/*MT6280RF*/    unsigned short Nint =0, CH_freq =0;
/*MT6280RF*/    unsigned long  Nfrac=0, DCO4G_freq=0;
/*MT6280RF*/
/*MT6280RF*/    CH_freq = L1D_RF_ARFCN_CH_to_TxFreq( rf_band, arfcn );
/*MT6280RF*/
/*MT6280RF*/    if( rf_band < FrequencyBand1800 )
/*MT6280RF*/       DCO4G_freq = 4*CH_freq;
/*MT6280RF*/    else
/*MT6280RF*/       DCO4G_freq = 2*CH_freq;
/*MT6280RF*/
/*MT6280RF*/    Nint  = ( (DCO4G_freq<<15) - 64*DCO4G_freq + 64*TX_DCXO_FREQ*92 ) / (TX_DCXO_FREQ<<15);
/*MT6280RF*/    Nfrac = ( ( ( (DCO4G_freq<<15) - 64*DCO4G_freq + 64*TX_DCXO_FREQ*92 - ((Nint*TX_DCXO_FREQ)<<15) )<<8 ) + TX_DCXO_FREQ/2 )/TX_DCXO_FREQ;  //+TX_DCXO_FREQ/2 is for rounding
/*MT6280RF*/
/*MT6280RF*/    /* CW97, N_INT1[7:0], N_RFC1[22:11] */
/*MT6280RF*/    *rfN = BSI_CW( 0x61, ((Nint &0xFF)<<12) | (Nfrac>>11) );
/*MT6280RF*/    /* CW98, N_FRAC1[10:0], NOFFSET_REV[3:0], STX_DCO_SCAK_NOFFSET[2:0], STX_MMD_SDM_DI_LS[1:0] */
/*MT6280RF*/    *ifN = BSI_CW( 0x62, ((Nfrac&0x7FF)<<9) | 0x00);
/*MT6280RF*/
/*MT6280RF*/ }
/*MT6280RF*/ /* =========================================================================== */
/*MT6280RF*/
/*MT6280RF*/ unsigned short L1D_RF_GetTxDAoffsetSetting(unsigned short Nint)
/*MT6280RF*/ {
/*MT6280RF*/    return (Nint - 10);
/*MT6280RF*/ }
#endif

#if IS_RF_MT6167
/*MT6167*/ void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6167*/ {  long *if_sel = ifN+1;
/*MT6167*/    unsigned long *FBX = (unsigned long*)ifN+2;
/*MT6167*/    unsigned short Nint =0, CH_freq =0;
/*MT6167*/    unsigned long  Nfrac=0, VCO_freq=0;
/*MT6167*/
/*MT6167*/    CH_freq = L1D_RF_ARFCN_CH_to_RxFreq( rf_band, arfcn );
/*MT6167*/
/*MT6167*/    *if_sel = 0;
/*MT6167*/    if( rf_band < FrequencyBand1800 )
/*MT6167*/       VCO_freq = 4*(CH_freq*DLIF_SCALE - DLIF);
/*MT6167*/    else
/*MT6167*/       VCO_freq = 2*(CH_freq*DLIF_SCALE - DLIF);
/*MT6167*/
/*MT6167*/    Nint  = VCO_freq/(RX_DCXO_FREQ*DLIF_SCALE);
/*MT6167*/    //+195/2 is for rounding, 195=13*3*5, 5 is SYNTH_SCALE, 13 and 3 are related to DLIF
/*MT6167*/    Nfrac = ( ((VCO_freq-Nint*RX_DCXO_FREQ*DLIF_SCALE)<<11) + (195)/2 )/195;
/*MT6167*/
/*MT6167*/    /* CW99,  N_INT[6:0], N_RFC[19:7] */
/*MT6167*/    *rfN = BSI_CW( 0x63, ((Nint &0x7F)<<13) | ((Nfrac>>7)&0x1FFF) );
/*MT6167*/    /* CW100, N_FRAC[6:0], N_INT[9:7], SRX_RSV3[0], SRX_SDM_DITH_EN[0], SRX_SDM_ENB[0], SRX_DITHER_MASK[4:0] */
/*MT6167*/    *ifN = BSI_CW( 0x64, ((Nfrac&0x7F)<<13) | (((Nint >>7)&0x3)<<10) | (POR_CW100&0x7F) );
/*MT6167*/    *FBX = L1D_RF_GetRxFBXSetting( rf_band, arfcn );
/*MT6167*/ }
/*MT6167*/ /* =========================================================================== */
/*MT6167*/
/*MT6167*/ unsigned long L1D_RF_GetRxFBXSetting(int rf_band, int arfcn)
/*MT6167*/ {
/*MT6167*/    unsigned short CH_freq =0;
/*MT6167*/    unsigned long  FBX =0, VCO_freq=0, CNT_WIN=0;
/*MT6167*/    unsigned short CNT_WIN_Table[4]={1, 2, 3, 8}; // CW223[6:5]=TMEAS_SBCAL: decide Counting_Window
/*MT6167*/
/*MT6167*/    CH_freq = L1D_RF_ARFCN_CH_to_RxFreq(rf_band, arfcn);
/*MT6167*/
/*MT6167*/    if( rf_band < FrequencyBand1800 )
/*MT6167*/       VCO_freq = 4*(CH_freq*DLIF_SCALE - DLIF);
/*MT6167*/    else
/*MT6167*/       VCO_freq = 2*(CH_freq*DLIF_SCALE - DLIF);
/*MT6167*/
/*MT6167*/    CNT_WIN     = CNT_WIN_Table[l1d_rf2.tmeas_sbcal];
/*MT6167*/
/*MT6167*/    FBX         = ((VCO_freq*CNT_WIN)+((SYNTH_SCALE*DLIF_SCALE)>>1))/(SYNTH_SCALE*DLIF_SCALE);  /* FBX=VCO_freq*Counting_Window */
/*MT6167*/
/*MT6167*/    return FBX;
/*MT6167*/ }
/*MT6167*/ /* =========================================================================== */
/*MT6167*/
/*MT6167*/ void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6167*/ {
/*MT6167*/    unsigned short Nint =0, CH_freq =0;
/*MT6167*/    unsigned long  Nfrac=0, VCO_freq=0;
/*MT6167*/    unsigned short DAoffset=0;
/*MT6167*/
/*MT6167*/
/*MT6167*/    l1d_rf2.arfcn = arfcn;  //for L1D_RF_TxGainSetting
/*MT6167*/    CH_freq = L1D_RF_ARFCN_CH_to_TxFreq( rf_band, arfcn );
/*MT6167*/
/*MT6167*/    if( rf_band < FrequencyBand1800 )
/*MT6167*/       VCO_freq = 4*CH_freq;
/*MT6167*/    else
/*MT6167*/       VCO_freq = 2*CH_freq;
/*MT6167*/
/*MT6167*/    Nint  = VCO_freq/TX_DCXO_FREQ;
/*MT6167*/    Nfrac = ( ((VCO_freq-Nint*TX_DCXO_FREQ)<<23) + TX_DCXO_FREQ/2 )/TX_DCXO_FREQ;  //+TX_DCXO_FREQ/2 is for rounding
/*MT6167*/
/*MT6167*/    DAoffset = L1D_RF_GetTxDAoffsetSetting( Nint );
/*MT6167*/
/*MT6167*/    /* CW95, N_INT[7:0], N_RFC[22:11] */
/*MT6167*/    *rfN = BSI_CW( 0x5F, ((Nint &0xFF)<<12) | (Nfrac>>11) );
/*MT6167*/    /* CW96, N_FRAC[10:0], DA_OFFSET[7:0], DI_EN */
/*MT6167*/    *ifN = BSI_CW( 0x60, ((Nfrac&0x7FF)<<9) | ((DAoffset&0xFF)<<1) | 0x1);
/*MT6167*/
/*MT6167*/ }
/*MT6167*/ /* =========================================================================== */
/*MT6167*/
/*MT6167*/ unsigned short L1D_RF_ARFCN_CH_to_RxFreq( int rf_band, int arfcn )
/*MT6167*/ {
/*MT6167*/    unsigned short freq=4450+225;
/*MT6167*/    switch( rf_band )
/*MT6167*/    {
/*MT6167*/       case  FrequencyBand850 :
/*MT6167*/       {
/*MT6167*/          freq=4121+(arfcn-128)+225;     //freq = f_ch*SYNTH_SCALE
/*MT6167*/          break;
/*MT6167*/       }
/*MT6167*/       case  FrequencyBand900 :
/*MT6167*/       {
/*MT6167*/          if( arfcn<=124 )
/*MT6167*/          {  freq=4450+arfcn+225;  }
/*MT6167*/          else
/*MT6167*/          {  freq=4450+(arfcn-1024)+225;  }
/*MT6167*/          break;
/*MT6167*/       }
/*MT6167*/       case  FrequencyBand1800 :
/*MT6167*/       {
/*MT6167*/          freq=8551+(arfcn-512)+475;
/*MT6167*/          break;
/*MT6167*/       }
/*MT6167*/       case  FrequencyBand1900 :
/*MT6167*/       {
/*MT6167*/          freq=9251+(arfcn-512)+400;
/*MT6167*/          break;
/*MT6167*/       }
/*MT6167*/       default :
/*MT6167*/       {
/*MT6167*/          break;
/*MT6167*/       }
/*MT6167*/    }
/*MT6167*/
/*MT6167*/    return freq;
/*MT6167*/ }
/*MT6167*/ /* =========================================================================== */
/*MT6167*/
/*MT6167*/ unsigned short L1D_RF_ARFCN_CH_to_TxFreq( int rf_band, int arfcn )
/*MT6167*/ {
/*MT6167*/    unsigned short freq=4450;
/*MT6167*/    switch( rf_band )
/*MT6167*/    {
/*MT6167*/       case  FrequencyBand850 :
/*MT6167*/       {
/*MT6167*/          freq=4121+(arfcn-128);     //freq = f_ch*SYNTH_SCALE
/*MT6167*/          break;
/*MT6167*/       }
/*MT6167*/       case  FrequencyBand900 :
/*MT6167*/       {
/*MT6167*/          if( arfcn<=124 )
/*MT6167*/          {  freq=4450+arfcn;  }
/*MT6167*/          else
/*MT6167*/          {  freq=4450+(arfcn-1024);  }
/*MT6167*/          break;
/*MT6167*/       }
/*MT6167*/       case  FrequencyBand1800 :
/*MT6167*/       {
/*MT6167*/          freq=8551+(arfcn-512);
/*MT6167*/          break;
/*MT6167*/       }
/*MT6167*/       case  FrequencyBand1900 :
/*MT6167*/       {
/*MT6167*/          freq=9251+(arfcn-512);
/*MT6167*/          break;
/*MT6167*/       }
/*MT6167*/       default :
/*MT6167*/       {
/*MT6167*/          break;
/*MT6167*/       }
/*MT6167*/    }
/*MT6167*/
/*MT6167*/    return freq;
/*MT6167*/ }
/*MT6167*/ /* =========================================================================== */
/*MT6167*/
/*MT6167*/ unsigned short L1D_RF_GetTxDCOSCACodeTypeSetting(unsigned short Nint, unsigned long  Nfrac)
/*MT6167*/ {
/*MT6167*/    char segment_tx=3, LUT_num_tx=8, offset_tx=13; // LUT method related parameters
/*MT6167*/    unsigned short TXDCO_LUT[8]={1422, 1082, 808, 584, 400, 244, 112, -1};  // TXDCO LUT
/*MT6167*/    short idx, x_axis, code_type;  // code_type value for SCA calibration (code_type > 0)
/*MT6167*/
/*MT6167*/    /* STX DCO SCA Typical Code LUT */
/*MT6167*/    idx = (Nint>>segment_tx)-((short)offset_tx);
/*MT6167*/    if(idx<0)
/*MT6167*/       idx = 0;
/*MT6167*/    else if(idx>(LUT_num_tx-2))
/*MT6167*/       idx = LUT_num_tx-2;
/*MT6167*/
/*MT6167*/    x_axis      = ((Nint-((Nint>>segment_tx)<<segment_tx))<<3)+((short)(Nfrac>>20));
/*MT6167*/    code_type   = TXDCO_LUT[idx]+ ((x_axis*(TXDCO_LUT[idx+1]-TXDCO_LUT[idx]))>>(segment_tx+3));
/*MT6167*/    code_type <<= 1;
/*MT6167*/
/*MT6167*/    return code_type;
/*MT6167*/ }
/*MT6167*/ /* =========================================================================== */
/*MT6167*/
/*MT6167*/ unsigned short L1D_RF_GetTxDEMChunkSetting(int rf_band, unsigned short Nint)
/*MT6167*/ {
/*MT6167*/    unsigned short DEM_Chunk_L1;
/*MT6167*/    unsigned short OUT_G, OUT_E;
/*MT6167*/    char segment_dem=4, LUT_num_dem=4, offset_dem=7;     // LUT method related parameters
/*MT6167*/    unsigned short DEM_chunk_G_LUT[4]={15, 10,  7,  5};  // DEM chunk GMSK LUT
/*MT6167*/    unsigned short DEM_chunk_E_LUT[4]={69, 46, 33, 24};  // DEM chunk EPSK LUT
/*MT6167*/    short idx;
/*MT6167*/
/*MT6167*/    /* STX DEM CHUNK LUT */
/*MT6167*/	idx = (Nint>>segment_dem)-((short)offset_dem);
/*MT6167*/    if(idx<0)
/*MT6167*/       idx = 0;
/*MT6167*/    else if(idx>(LUT_num_dem-2))
/*MT6167*/       idx = LUT_num_dem-2;
/*MT6167*/
/*MT6167*/    OUT_G = DEM_chunk_G_LUT[idx]+(((Nint-((Nint>>segment_dem)<<segment_dem))*(DEM_chunk_G_LUT[idx+1]-DEM_chunk_G_LUT[idx]))>>(segment_dem));
/*MT6167*/    OUT_E = DEM_chunk_E_LUT[idx]+(((Nint-((Nint>>segment_dem)<<segment_dem))*(DEM_chunk_E_LUT[idx+1]-DEM_chunk_E_LUT[idx]))>>(segment_dem));
/*MT6167*/
/*MT6167*/    if( ( (l1d_rf.tx_mod_type2)^(l1d_rf.tx_mod_type2<<1) ) & 0xE )   // IS_MIXED_MULTISLOT
/*MT6167*/    {
/*MT6167*/       if( rf_band < FrequencyBand1800 )
/*MT6167*/          DEM_Chunk_L1 = ((OUT_E+OUT_G+5)>40) ? (OUT_E+OUT_G+5) : 40;
/*MT6167*/       else
/*MT6167*/          DEM_Chunk_L1 = 40;
/*MT6167*/    }
/*MT6167*/    else
/*MT6167*/    {
/*MT6167*/       if( (l1d_rf.tx_mod_type2 != 0) && (rf_band < FrequencyBand1800) )
/*MT6167*/          DEM_Chunk_L1 = ((2*OUT_E+6)>40) ? (2*OUT_E+6) : 40;
/*MT6167*/       else
/*MT6167*/          DEM_Chunk_L1 = 40;
/*MT6167*/    }
/*MT6167*/    return DEM_Chunk_L1;
/*MT6167*/ }
/*MT6167*/ /* =========================================================================== */
/*MT6167*/
/*MT6167*/ void L1D_RF_GetTxKDCOCAL2ndSetting(int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6167*/ {
/*MT6167*/    unsigned short Nint =0, CH_freq =0;
/*MT6167*/    unsigned long  Nfrac=0, DCO4G_freq=0;
/*MT6167*/
/*MT6167*/    CH_freq = L1D_RF_ARFCN_CH_to_TxFreq( rf_band, arfcn );
/*MT6167*/
/*MT6167*/    if( rf_band < FrequencyBand1800 )
/*MT6167*/       DCO4G_freq = 4*CH_freq;
/*MT6167*/    else
/*MT6167*/       DCO4G_freq = 2*CH_freq;
/*MT6167*/
/*MT6167*/    Nint  = ( (DCO4G_freq<<15) - 64*DCO4G_freq + 64*TX_DCXO_FREQ*92 ) / (TX_DCXO_FREQ<<15);
/*MT6167*/    Nfrac = ( ( ( (DCO4G_freq<<15) - 64*DCO4G_freq + 64*TX_DCXO_FREQ*92 - ((Nint*TX_DCXO_FREQ)<<15) )<<8 ) + TX_DCXO_FREQ/2 )/TX_DCXO_FREQ;  //+TX_DCXO_FREQ/2 is for rounding
/*MT6167*/
/*MT6167*/    /* CW97, N_INT1[7:0], N_RFC1[22:11] */
/*MT6167*/    *rfN = BSI_CW( 0x61, ((Nint &0xFF)<<12) | (Nfrac>>11) );
/*MT6167*/    /* CW98, N_FRAC1[10:0], NOFFSET_REV[3:0], STX_DCO_SCAK_NOFFSET[2:0], STX_MMD_SDM_DI_LS[1:0] */
/*MT6167*/    *ifN = BSI_CW( 0x62, ((Nfrac&0x7FF)<<9) | 0x00);
/*MT6167*/
/*MT6167*/ }
/*MT6167*/ /* =========================================================================== */
/*MT6167*/
/*MT6167*/ unsigned short L1D_RF_GetTxDAoffsetSetting(unsigned short Nint)
/*MT6167*/ {
/*MT6167*/    return (Nint - 10);
/*MT6167*/ }
#endif

#if IS_RF_MT6166
/*MT6166*/ //For DLIF mode
/*MT6166*/ void  L1D_RF_Cal_Synthesizer_Params( unsigned short* Nint, unsigned long* Nfrac, unsigned long  VCO_freq )
/*MT6166*/ {
/*MT6166*/    *Nint  = VCO_freq/(RX_DCXO_FREQ*DLIF_SCALE);
/*MT6166*/    //+195/2 is for rounding, 195=13*3*5, 5 is SYNTH_SCALE, 13 and 3 are related to DLIF
/*MT6166*/    *Nfrac = ( ((VCO_freq-*Nint*RX_DCXO_FREQ*DLIF_SCALE)<<15) + (195)/2 )/195;
/*MT6166*/ }
/*MT6166*/ /* =========================================================================== */
/*MT6166*/
/*MT6166*/ char  L1D_RF_Cal_IF_Synth_State( void )
/*MT6166*/ {
/*MT6166*/ #if IS_W_CANCELLATION_SUPPORT
/*MT6166*/    if( L1D_CheckIfMetaMode() )
/*MT6166*/    {  return l1d_rf.if_state;  }
/*MT6166*/    else
/*MT6166*/    {  return 0;  }
/*MT6166*/ #else
/*MT6166*/    return 0;
/*MT6166*/ #endif
/*MT6166*/ }
/*MT6166*/ /* =========================================================================== */
/*MT6166*/
/*MT6166*/ void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6166*/ {  long *if_sel = ifN+1;
/*MT6166*/    unsigned short Nint =0, CH_freq =0;
/*MT6166*/    unsigned long  Nfrac=0, VCO_freq=0;
/*MT6166*/    unsigned long  frac_spurs_thd0=0, frac_spurs_thd1=0;
/*MT6166*/    unsigned char  IF_state=0;   //IF_state=0:default, IF_state=1:+IF, IF_state=2:-IF
/*MT6166*/
/*MT6166*/    IF_state = L1D_RF_Cal_IF_Synth_State();
/*MT6166*/
/*MT6166*/    CH_freq = L1D_RF_ARFCN_CH_to_RxFreq( rf_band, arfcn );
/*MT6166*/
/*MT6166*/    if( IF_state != 2 )
/*MT6166*/    {
/*MT6166*/       *if_sel = 0;
/*MT6166*/       l1d_rf.if_sel_Nif_wc = 0;
/*MT6166*/       if( rf_band < FrequencyBand1800 )
/*MT6166*/       {
/*MT6166*/          VCO_freq = 4*(CH_freq*DLIF_SCALE - DLIF);  //High-side mixing
/*MT6166*/          frac_spurs_thd0 = 193584;
/*MT6166*/          frac_spurs_thd1 = 8195024;
/*MT6166*/       }
/*MT6166*/       else
/*MT6166*/       {
/*MT6166*/          VCO_freq = 2*(CH_freq*DLIF_SCALE - DLIF);  //High-side mixing
/*MT6166*/          frac_spurs_thd0 = 96792;
/*MT6166*/          frac_spurs_thd1 = 8291816;
/*MT6166*/       }
/*MT6166*/       L1D_RF_Cal_Synthesizer_Params( &Nint, &Nfrac, VCO_freq );
/*MT6166*/    }
/*MT6166*/
/*MT6166*/    if( IF_state != 1 )
/*MT6166*/    {
/*MT6166*/       // use +IF channel instead of -IF for IRR calibration
/*MT6166*/       if( ( Nfrac < frac_spurs_thd0 ) || ( Nfrac > frac_spurs_thd1) || ( Nfrac < 4258832 && Nfrac > 4129776 ) || ( IF_state == 2 ) )
/*MT6166*/       {
/*MT6166*/          *if_sel = 0;
/*MT6166*/          l1d_rf.if_sel_Nif_wc = 1;
/*MT6166*/          if( rf_band < FrequencyBand1800 )
/*MT6166*/          {  VCO_freq = 4*(CH_freq*DLIF_SCALE - DLIF);  }  //Low-side mixing
/*MT6166*/          else
/*MT6166*/          {  VCO_freq = 2*(CH_freq*DLIF_SCALE - DLIF);  }  //Low-side mixing
/*MT6166*/
/*MT6166*/          L1D_RF_Cal_Synthesizer_Params( &Nint, &Nfrac, VCO_freq );
/*MT6166*/       }
/*MT6166*/
/*MT6166*/    }
/*MT6166*/
/*MT6166*/ #if IS_OBB_DETECTION_SUPPORT
/*MT6166*/    if( !L1D_CheckIfMetaMode() )
/*MT6166*/    {
/*MT6166*/       if( l1d_rf.if_change == -1 && arfcn == l1d_rf.obb_arfcn )
/*MT6166*/       {
/*MT6166*/          signed short if_sign = l1d_rf.if_change*(*if_sel*2-1);
/*MT6166*/
/*MT6166*/          *if_sel = if_sign > 0 ? 1 : 0;
/*MT6166*/          if( rf_band < FrequencyBand1800 )
/*MT6166*/          {  VCO_freq = 4*(CH_freq*DLIF_SCALE + if_sign*DLIF);  }
/*MT6166*/          else
/*MT6166*/          {  VCO_freq = 2*(CH_freq*DLIF_SCALE + if_sign*DLIF);  }
/*MT6166*/
/*MT6166*/          L1D_RF_Cal_Synthesizer_Params( &Nint, &Nfrac, VCO_freq );
/*MT6166*/       }
/*MT6166*/    }
/*MT6166*/ #endif
/*MT6166*/
/*MT6166*/    /* CW223, SRX_NINT[8:0], SRX_NRFC[22:12] */
/*MT6166*/    *rfN = BSI_CW( 0xDF, ((Nint &0x1FF)<<11) | ((Nfrac>>12)&0x7FF) );
/*MT6166*/    /* CW224, SRX_NFRAC[11:0],SRX_REF_DOUBLER_EN,SRX_CAL_DISABLE,SRX_VCO_CFG[2:0],TALL_TRG_M,SRX_SDM_FRAC_MODE,SRX_RELOCK */
/*MT6166*/    *ifN = BSI_CW( 0xE0, ((Nfrac&0xFFF)<<8) | SRX_REF_DOUBLER_EN | SRX_VCO_CFG | (POR_CW224&0x47) );
/*MT6166*/
/*MT6166*/ }
/*MT6166*/ /* =========================================================================== */
/*MT6166*/
/*MT6166*/ void L1D_RF_SplitRxPLLSetting(unsigned long rfN, unsigned long ifN, unsigned short *Nint, unsigned long *Nfrac)
/*MT6166*/ {
/*MT6166*/    *Nint  = (rfN&(0x1FF<<11))>>11;
/*MT6166*/    *Nfrac = ( (rfN&0x7FF)<<12 ) | ( (ifN&(0xFFF<<8))>>8 );
/*MT6166*/ }
/*MT6166*/ /* =========================================================================== */
/*MT6166*/
/*MT6166*/ void L1D_RF_AdjustRxPLLSetting(unsigned short Nint, unsigned long Nfrac, signed long NfracOffset, unsigned long *rfN, unsigned long *ifN )
/*MT6166*/ {
/*MT6166*/    L1D_RF_CompensateSXSetting( &Nint, &Nfrac, NfracOffset, 0 );
/*MT6166*/
/*MT6166*/    /* CW223, SRX_NINT[8:0], SRX_NRFC[22:12] */
/*MT6166*/    *rfN = BSI_CW( 0xDF, ((Nint &0x1FF)<<11) | ((Nfrac>>12)&0x7FF) );
/*MT6166*/    /* CW224, SRX_NFRAC[11:0],SRX_REF_DOUBLER_EN,SRX_CAL_DISABLE,SRX_VCO_CFG[2:0],TALL_TRG_M,SRX_SDM_FRAC_MODE,SRX_RELOCK */
/*MT6166*/    *ifN = BSI_CW( 0xE0, ((Nfrac&0xFFF)<<8)  | ((*ifN)&0xFF));
/*MT6166*/ }
/*MT6166*/ /* =========================================================================== */
/*MT6166*/
/*MT6166*/ //void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6166*/ //{  long *if_sel = ifN+1;
/*MT6166*/ //   unsigned short Nint =0, CH_freq =0;
/*MT6166*/ //   unsigned long  Nfrac=0, VCO_freq=0;
/*MT6166*/
/*MT6166*/ //   CH_freq = L1D_RF_ARFCN_CH_to_RxFreq( rf_band, arfcn );
/*MT6166*/
/*MT6166*/ //   *if_sel = 0;
/*MT6166*/ //   if( rf_band < FrequencyBand1800 )
/*MT6166*/ //      VCO_freq = 4*(CH_freq*DLIF_SCALE - DLIF);
/*MT6166*/ //   else
/*MT6166*/ //      VCO_freq = 2*(CH_freq*DLIF_SCALE - DLIF);
/*MT6166*/
/*MT6166*/ //   Nint  = VCO_freq/(RX_DCXO_FREQ*DLIF_SCALE);
/*MT6166*/    //+195/2 is for rounding, 195=13*3*5, 5 is SYNTH_SCALE, 13 and 3 are related to DLIF
/*MT6166*/ //   Nfrac = ( ((VCO_freq-Nint*RX_DCXO_FREQ*DLIF_SCALE)<<14) + (195)/2 )/195;
/*MT6166*/
/*MT6166*/    /* CW223, SRX_NINT[8:0], SRX_NRFC[22:12] */
/*MT6166*/ //   *rfN = BSI_CW( 0xDF, ((Nint &0x1FF)<<11) | ((Nfrac>>12)&0x7FF) );
/*MT6166*/    /* CW224, SRX_NFRAC[11:0],SRX_REF_DOUBLER_EN,SRX_CAL_DISABLE,SRX_VCO_CFG[2:0],TALL_TRG_M,SRX_SDM_FRAC_MODE,SRX_RELOCK */
/*MT6166*/ //   *ifN = BSI_CW( 0xE0, ((Nfrac&0xFFF)<<8) | SRX_REF_DOUBLER_EN | SRX_VCO_CFG | (POR_CW224&0x47) );
/*MT6166*/ //}
/*MT6166*/ /* =========================================================================== */
/*MT6166*/
/*MT6166*/ void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6166*/ {
/*MT6166*/    unsigned short Nint =0, CH_freq =0;
/*MT6166*/    unsigned long  Nfrac=0, VCO_freq=0;
/*MT6166*/    unsigned short DAoffset=0;
/*MT6166*/
/*MT6166*/
/*MT6166*/    l1d_rf2.arfcn = arfcn;  //for L1D_RF_TxGainSetting
/*MT6166*/    CH_freq = L1D_RF_ARFCN_CH_to_TxFreq( rf_band, arfcn );
/*MT6166*/
/*MT6166*/    if( rf_band < FrequencyBand1800 )
/*MT6166*/       VCO_freq = 4*CH_freq;
/*MT6166*/    else
/*MT6166*/       VCO_freq = 2*CH_freq;
/*MT6166*/
/*MT6166*/    Nint  = VCO_freq/TX_DCXO_FREQ;
/*MT6166*/    Nfrac = ( ((VCO_freq-Nint*TX_DCXO_FREQ)<<23) + TX_DCXO_FREQ/2 )/TX_DCXO_FREQ;  //+TX_DCXO_FREQ/2 is for rounding
/*MT6166*/
/*MT6166*/    DAoffset = 10;//L1D_RF_GetTxDAoffsetSetting( Nint );
/*MT6166*/
/*MT6166*/    /* CW96, N_INT[7:0], N_RFC[22:11] */
/*MT6166*/    *rfN = BSI_CW( 0x60, ((Nint &0xFF)<<12) | (Nfrac>>11) );
/*MT6166*/    /* CW97, N_FRAC[10:0], DA_OFFSET[4:0], DI_EN */
/*MT6166*/    *ifN = BSI_CW( 0x61, ((Nfrac&0x7FF)<<9) | ((DAoffset&0x1F)<<4) | 0x1);
/*MT6166*/
/*MT6166*/ }
/*MT6166*/ /* =========================================================================== */
/*MT6166*/
/*MT6166*/ void L1D_RF_SplitTxPLLSetting(unsigned long rfN, unsigned long ifN, unsigned short *Nint, unsigned long *Nfrac)
/*MT6166*/ {
/*MT6166*/    *Nint  = (rfN&(0xFF<<12))>>12;
/*MT6166*/    *Nfrac = ( (rfN&0xFFF)<<11 ) | ( (ifN&(0x7FF<<9))>>9 );
/*MT6166*/ }
/*MT6166*/ /* =========================================================================== */
/*MT6166*/
/*MT6166*/ void L1D_RF_AdjustTxPLLSetting(unsigned short Nint, unsigned long Nfrac, signed long NfracOffset, unsigned long *rfN, unsigned long *ifN )
/*MT6166*/ {
/*MT6166*/    L1D_RF_CompensateSXSetting( &Nint, &Nfrac, NfracOffset, 1 );
/*MT6166*/
/*MT6166*/    /* CW96, N_INT[7:0], N_RFC[22:11] */
/*MT6166*/    *rfN = BSI_CW( 0x60, ((Nint &0xFF)<<12) | (Nfrac>>11) );
/*MT6166*/    /* CW97, N_FRAC[10:0], DA_OFFSET[4:0], DI_EN */
/*MT6166*/    *ifN = BSI_CW( 0x61, ((Nfrac&0x7FF)<<9) |((*ifN)&0x1FF));
/*MT6166*/ }
/*MT6166*/ /* =========================================================================== */
/*MT6166*/
/*MT6166*/ void L1D_RF_CompensateSXSetting( unsigned short *Nint, unsigned long *Nfrac, signed long NfracOffset, unsigned char is_TX)
/*MT6166*/ {
/*MT6166*/    signed long Max_Nfrac=0;
/*MT6166*/    if( is_TX )
/*MT6166*/    {  Max_Nfrac = STX_MAX_NFRAC;  }
/*MT6166*/    else
/*MT6166*/    {  Max_Nfrac = SRX_MAX_NFRAC;  }
/*MT6166*/
/*MT6166*/    //Calculate new Nfrac and Nint
/*MT6166*/    *Nfrac  += (NfracOffset + Max_Nfrac);
/*MT6166*/    if( *Nfrac < Max_Nfrac )
/*MT6166*/    {  (*Nint)--;
/*MT6166*/    }
/*MT6166*/    else if( *Nfrac >= (Max_Nfrac<<1) )
/*MT6166*/    {  (*Nint)++;
/*MT6166*/       *Nfrac = *Nfrac - (Max_Nfrac<<1);
/*MT6166*/    }
/*MT6166*/    else
/*MT6166*/    {  *Nfrac-= Max_Nfrac;
/*MT6166*/    }
/*MT6166*/ }
/*MT6166*/ /* =========================================================================== */
/*MT6166*/
/*MT6166*/ unsigned short L1D_RF_ARFCN_CH_to_RxFreq( int rf_band, int arfcn )
/*MT6166*/ {
/*MT6166*/    unsigned short freq=4450+225;
/*MT6166*/    switch( rf_band )
/*MT6166*/    {
/*MT6166*/       case  FrequencyBand850 :
/*MT6166*/       {
/*MT6166*/          freq=4121+(arfcn-128)+225;     //freq = f_ch*SYNTH_SCALE
/*MT6166*/          break;
/*MT6166*/       }
/*MT6166*/       case  FrequencyBand900 :
/*MT6166*/       {
/*MT6166*/          if( arfcn<=124 )
/*MT6166*/          {  freq=4450+arfcn+225;  }
/*MT6166*/          else
/*MT6166*/          {  freq=4450+(arfcn-1024)+225;  }
/*MT6166*/          break;
/*MT6166*/       }
/*MT6166*/       case  FrequencyBand1800 :
/*MT6166*/       {
/*MT6166*/          freq=8551+(arfcn-512)+475;
/*MT6166*/          break;
/*MT6166*/       }
/*MT6166*/       case  FrequencyBand1900 :
/*MT6166*/       {
/*MT6166*/          freq=9251+(arfcn-512)+400;
/*MT6166*/          break;
/*MT6166*/       }
/*MT6166*/       default :
/*MT6166*/       {
/*MT6166*/          break;
/*MT6166*/       }
/*MT6166*/    }
/*MT6166*/
/*MT6166*/    return freq;
/*MT6166*/ }
/*MT6166*/ /* =========================================================================== */
/*MT6166*/
/*MT6166*/ unsigned short L1D_RF_ARFCN_CH_to_TxFreq( int rf_band, int arfcn )
/*MT6166*/ {
/*MT6166*/    unsigned short freq=4450;
/*MT6166*/    switch( rf_band )
/*MT6166*/    {
/*MT6166*/       case  FrequencyBand850 :
/*MT6166*/       {
/*MT6166*/          freq=4121+(arfcn-128);     //freq = f_ch*SYNTH_SCALE
/*MT6166*/          break;
/*MT6166*/       }
/*MT6166*/       case  FrequencyBand900 :
/*MT6166*/       {
/*MT6166*/          if( arfcn<=124 )
/*MT6166*/          {  freq=4450+arfcn;  }
/*MT6166*/          else
/*MT6166*/          {  freq=4450+(arfcn-1024);  }
/*MT6166*/          break;
/*MT6166*/       }
/*MT6166*/       case  FrequencyBand1800 :
/*MT6166*/       {
/*MT6166*/          freq=8551+(arfcn-512);
/*MT6166*/          break;
/*MT6166*/       }
/*MT6166*/       case  FrequencyBand1900 :
/*MT6166*/       {
/*MT6166*/          freq=9251+(arfcn-512);
/*MT6166*/          break;
/*MT6166*/       }
/*MT6166*/       default :
/*MT6166*/       {
/*MT6166*/          break;
/*MT6166*/       }
/*MT6166*/    }
/*MT6166*/
/*MT6166*/    return freq;
/*MT6166*/ }
/*MT6166*/ /* =========================================================================== */
/*MT6166*/
/*MT6166*/ unsigned short L1D_RF_GetTxDCOSCACodeTypeSetting(unsigned short Nint, unsigned long  Nfrac)
/*MT6166*/ {
/*MT6166*/    char segment_tx=3, LUT_num_tx=6, offset_tx=15; // LUT method related parameters
/*MT6166*/    signed short TXDCO_LUT[6]={1566, 1169, 840, 565, 331, -40};  // TXDCO LUT
/*MT6166*/    short idx, x_axis, code_type;  // code_type value for SCA calibration (code_type > 0)
/*MT6166*/
/*MT6166*/ #if IS_DUAL_LOOP_AFC_CONTROL_SUPPORT
/*MT6166*/    if( l1d_rf.is_lock_dcxo )
/*MT6166*/    {  L1D_RF_CompensateSXSetting( &Nint, &Nfrac, -l1d_rf.tx_nfracoffset, 1 );  }
/*MT6166*/ #endif
/*MT6166*/
/*MT6166*/    /* STX DCO SCA Typical Code LUT */
/*MT6166*/    idx = (Nint>>segment_tx)-((short)offset_tx);
/*MT6166*/    if(idx<0)
/*MT6166*/       idx = 0;
/*MT6166*/    else if(idx>(LUT_num_tx-2))
/*MT6166*/       idx = LUT_num_tx-2;
/*MT6166*/
/*MT6166*/    x_axis      = ((Nint-((Nint>>segment_tx)<<segment_tx))<<3)+((short)(Nfrac>>20));
/*MT6166*/    code_type   = TXDCO_LUT[idx]+ ((x_axis*(TXDCO_LUT[idx+1]-TXDCO_LUT[idx]))>>(segment_tx+3));
/*MT6166*/    code_type <<= 1;
/*MT6166*/
/*MT6166*/    return code_type;
/*MT6166*/ }
/*MT6166*/ /* =========================================================================== */
/*MT6166*/
/*MT6166*/ unsigned short L1D_RF_GetTxDEMChunkSetting(int rf_band, unsigned short Nint)
/*MT6166*/ {
/*MT6166*/    unsigned short DEM_Chunk_L1;
/*MT6166*/    unsigned short OUT_G, OUT_E;
/*MT6166*/    char segment_dem=4, LUT_num_dem=4, offset_dem=7;     // LUT method related parameters
/*MT6166*/    signed short DEM_chunk_G_LUT[4]={15, 10,  7,  5};  // DEM chunk GMSK LUT
/*MT6166*/    signed short DEM_chunk_E_LUT[4]={69, 46, 33, 24};  // DEM chunk EPSK LUT
/*MT6166*/    short idx;
/*MT6166*/
/*MT6166*/    /* STX DEM CHUNK LUT */
/*MT6166*/	  idx = (Nint>>segment_dem)-((short)offset_dem);
/*MT6166*/    if(idx<0)
/*MT6166*/       idx = 0;
/*MT6166*/    else if(idx>(LUT_num_dem-2))
/*MT6166*/       idx = LUT_num_dem-2;
/*MT6166*/
/*MT6166*/    OUT_G = DEM_chunk_G_LUT[idx]+(((Nint-((Nint>>segment_dem)<<segment_dem))*(DEM_chunk_G_LUT[idx+1]-DEM_chunk_G_LUT[idx]))>>(segment_dem));
/*MT6166*/    OUT_E = DEM_chunk_E_LUT[idx]+(((Nint-((Nint>>segment_dem)<<segment_dem))*(DEM_chunk_E_LUT[idx+1]-DEM_chunk_E_LUT[idx]))>>(segment_dem));
/*MT6166*/
/*MT6166*/    if( ( (l1d_rf.tx_mod_type2)^(l1d_rf.tx_mod_type2<<1) ) & 0xE )   // IS_MIXED_MULTISLOT
/*MT6166*/    {
/*MT6166*/       if( rf_band < FrequencyBand1800 )
/*MT6166*/          DEM_Chunk_L1 = ((OUT_E+OUT_G+5)>40) ? (OUT_E+OUT_G+5) : 40;
/*MT6166*/       else
/*MT6166*/          DEM_Chunk_L1 = 40;
/*MT6166*/    }
/*MT6166*/    else
/*MT6166*/    {
/*MT6166*/       if( (l1d_rf.tx_mod_type2 != 0) && (rf_band < FrequencyBand1800) )
/*MT6166*/          DEM_Chunk_L1 = ((2*OUT_E+6)>40) ? (2*OUT_E+6) : 40;
/*MT6166*/       else
/*MT6166*/          DEM_Chunk_L1 = 40;
/*MT6166*/    }
/*MT6166*/    return DEM_Chunk_L1;
/*MT6166*/ }
/*MT6166*/ /* =========================================================================== */
/*MT6166*/
/*MT6166*/ void L1D_RF_GetTxKDCOCAL2ndSetting(int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6166*/ {
/*MT6166*/    unsigned short Nint =0, CH_freq =0;
/*MT6166*/    unsigned long  Nfrac=0, DCO4G_freq=0;
/*MT6166*/
/*MT6166*/    CH_freq = L1D_RF_ARFCN_CH_to_TxFreq( rf_band, arfcn );
/*MT6166*/
/*MT6166*/    if( rf_band < FrequencyBand1800 )
/*MT6166*/       DCO4G_freq = 4*CH_freq;
/*MT6166*/    else
/*MT6166*/       DCO4G_freq = 2*CH_freq;
/*MT6166*/
/*MT6166*/    Nint  = ( (DCO4G_freq<<15) - 64*DCO4G_freq + 64*TX_DCXO_FREQ*92 ) / (TX_DCXO_FREQ<<15);
/*MT6166*/    Nfrac = ( ( ( (DCO4G_freq<<15) - 64*DCO4G_freq + 64*TX_DCXO_FREQ*92 - ((Nint*TX_DCXO_FREQ)<<15) )<<8 ) + TX_DCXO_FREQ/2 )/TX_DCXO_FREQ;  //+TX_DCXO_FREQ/2 is for rounding
/*MT6166*/
/*MT6166*/ #if IS_DUAL_LOOP_AFC_CONTROL_SUPPORT
/*MT6166*/    if( l1d_rf.is_lock_dcxo )
/*MT6166*/    {  L1D_RF_CompensateSXSetting( &Nint, &Nfrac, l1d_rf.tx_nfracoffset, 1 );  }
/*MT6166*/ #endif
/*MT6166*/
/*MT6166*/    /* CW98, N_INT1[7:0], N_RFC1[22:11] */
/*MT6166*/    *rfN = BSI_CW( 0x62, ((Nint &0xFF)<<12) | (Nfrac>>11) );
/*MT6166*/    /* CW99, N_FRAC1[10:0], NOFFSET_REV[3:0], STX_DCO_SCAK_NOFFSET[2:0], STX_MMD_SDM_DI_LS[1:0] */
/*MT6166*/    *ifN = BSI_CW( 0x63, ((Nfrac&0x7FF)<<9) | (POR_CW99&0x1FF) );
/*MT6166*/
/*MT6166*/ }
/*MT6166*/ /* =========================================================================== */
/*MT6166*/
#endif

#if IS_RF_MT6165
/*MT6165*/ //For DLIF mode
/*MT6165*/ void  L1D_RF_Cal_Synthesizer_Params( unsigned short* Nint, unsigned long* Nfrac, unsigned long  VCO_freq )
/*MT6165*/ {
/*MT6165*/    *Nint  = VCO_freq/(RX_DCXO_FREQ*DLIF_SCALE);
/*MT6165*/    //+195/2 is for rounding, 195=13*3*5, 5 is SYNTH_SCALE, 13 and 3 are related to DLIF
/*MT6165*/    *Nfrac = ( ((VCO_freq-*Nint*RX_DCXO_FREQ*DLIF_SCALE)<<15) + (195)/2 )/195;
/*MT6165*/ }
/*MT6165*/ /* =========================================================================== */
/*MT6165*/
/*MT6165*/ char  L1D_RF_Cal_IF_Synth_State( void )
/*MT6165*/ {
/*MT6165*/ #if IS_W_CANCELLATION_SUPPORT
/*MT6165*/    if( L1D_CheckIfMetaMode() )
/*MT6165*/    {  return l1d_rf.if_state;  }
/*MT6165*/    else
/*MT6165*/    {  return 0;  }
/*MT6165*/ #else
/*MT6165*/    return 0;
/*MT6165*/ #endif
/*MT6165*/ }
/*MT6165*/ /* =========================================================================== */
/*MT6165*/
/*MT6165*/ void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6165*/ {  long *if_sel = ifN+1;
/*MT6165*/    unsigned short Nint =0, CH_freq =0;
/*MT6165*/    unsigned long  Nfrac=0, VCO_freq=0;
/*MT6165*/    unsigned long  frac_spurs_thd0=0, frac_spurs_thd1=0;
/*MT6165*/    unsigned char  IF_state=0;   //IF_state=0:default, IF_state=1:+IF, IF_state=2:-IF
/*MT6165*/
/*MT6165*/    IF_state = L1D_RF_Cal_IF_Synth_State();
/*MT6165*/
/*MT6165*/    CH_freq = L1D_RF_ARFCN_CH_to_RxFreq( rf_band, arfcn );
/*MT6165*/
/*MT6165*/    if( IF_state != 2 )
/*MT6165*/    {
/*MT6165*/       *if_sel = 0;
/*MT6165*/ #if IS_W_CANCELLATION_SUPPORT
/*MT6165*/       l1d_rf.if_sel_Nif_wc = 0;
/*MT6165*/ #endif
/*MT6165*/       if( rf_band < FrequencyBand1800 )
/*MT6165*/       {
/*MT6165*/          VCO_freq = 4*(CH_freq*DLIF_SCALE - DLIF);  //High-side mixing
/*MT6165*/          frac_spurs_thd0 = 193584;
/*MT6165*/          frac_spurs_thd1 = 8195024;
/*MT6165*/       }
/*MT6165*/       else
/*MT6165*/       {
/*MT6165*/          VCO_freq = 2*(CH_freq*DLIF_SCALE - DLIF);  //High-side mixing
/*MT6165*/          frac_spurs_thd0 = 96792;
/*MT6165*/          frac_spurs_thd1 = 8291816;
/*MT6165*/       }
/*MT6165*/       L1D_RF_Cal_Synthesizer_Params( &Nint, &Nfrac, VCO_freq );
/*MT6165*/    }
/*MT6165*/
/*MT6165*/    if( IF_state != 1 )
/*MT6165*/    {
/*MT6165*/       // use +IF channel instead of -IF for IRR calibration
/*MT6165*/       if( ( Nfrac < frac_spurs_thd0 ) || ( Nfrac > frac_spurs_thd1) || ( Nfrac < 4258832 && Nfrac > 4129776 ) || ( IF_state == 2 ) )
/*MT6165*/       {
/*MT6165*/          *if_sel = 0;
/*MT6165*/ #if IS_W_CANCELLATION_SUPPORT
/*MT6165*/          l1d_rf.if_sel_Nif_wc = 1;
/*MT6165*/ #endif
/*MT6165*/          if( rf_band < FrequencyBand1800 )
/*MT6165*/          {  VCO_freq = 4*(CH_freq*DLIF_SCALE - DLIF);  }  //use High-side mixing instead of Low-side for MT6165
/*MT6165*/          else
/*MT6165*/          {  VCO_freq = 2*(CH_freq*DLIF_SCALE - DLIF);  }  //use High-side mixing instead of Low-side for MT6165
/*MT6165*/
/*MT6165*/          L1D_RF_Cal_Synthesizer_Params( &Nint, &Nfrac, VCO_freq );
/*MT6165*/       }
/*MT6165*/
/*MT6165*/    }
/*MT6165*/
/*MT6165*/ #if IS_OBB_DETECTION_SUPPORT
/*MT6165*/    if( !L1D_CheckIfMetaMode() )
/*MT6165*/    {
/*MT6165*/       if( l1d_rf.if_change == -1 && arfcn == l1d_rf.obb_arfcn )
/*MT6165*/       {
/*MT6165*/          signed short if_sign = l1d_rf.if_change*(*if_sel*2-1);
/*MT6165*/
/*MT6165*/          *if_sel = if_sign > 0 ? 1 : 0;
/*MT6165*/          if( rf_band < FrequencyBand1800 )
/*MT6165*/          {  VCO_freq = 4*(CH_freq*DLIF_SCALE + if_sign*DLIF);  }
/*MT6165*/          else
/*MT6165*/          {  VCO_freq = 2*(CH_freq*DLIF_SCALE + if_sign*DLIF);  }
/*MT6165*/
/*MT6165*/          L1D_RF_Cal_Synthesizer_Params( &Nint, &Nfrac, VCO_freq );
/*MT6165*/       }
/*MT6165*/    }
/*MT6165*/ #endif
/*MT6165*/
/*MT6165*/    /* CW181, SRX_NINT[7:0], SRX_NRFC[22:11] */
/*MT6165*/    *rfN = BSI_CW( 0xB5, ((Nint &0xFF)<<12) | ((Nfrac>>11)&0xFFF) );
/*MT6165*/    /* CW182, SRX_NFRAC[10:0], DA_OFFSET[7:0], DI_EN */
/*MT6165*/    *ifN = BSI_CW( 0xB6, ((Nfrac&0x7FF)<<9) | (POR_CW182&0x1) ); // Keep DA_OFFSET=0x0 and setup at L1D_RF_SetSData_SR1()
/*MT6165*/
/*MT6165*/ }
/*MT6165*/ /* =========================================================================== */
/*MT6165*/
/*MT6165*/ void L1D_RF_SplitRxPLLSetting(unsigned long rfN, unsigned long ifN, unsigned short *Nint, unsigned long *Nfrac)
/*MT6165*/ {
/*MT6165*/    *Nint  = (rfN&(0xFF<<12))>>12;
/*MT6165*/    *Nfrac = ( (rfN&0xFFF)<<11 ) | ( (ifN&(0x7FF<<9))>>9 );
/*MT6165*/ }
/*MT6165*/ /* =========================================================================== */
/*MT6165*/
/*MT6165*/ void L1D_RF_AdjustRxPLLSetting(unsigned short Nint, unsigned long Nfrac, signed long NfracOffset, unsigned long *rfN, unsigned long *ifN )
/*MT6165*/ {
/*MT6165*/    L1D_RF_CompensateSXSetting( &Nint, &Nfrac, NfracOffset, 0 );
/*MT6165*/
/*MT6165*/    /* CW181, SRX_NINT[7:0], SRX_NRFC[22:11] */
/*MT6165*/    *rfN = BSI_CW( 0xB5, ((Nint &0xFF)<<12) | ((Nfrac>>11)&0xFFF) );
/*MT6165*/    /* CW182, SRX_NFRAC[10:0], DA_OFFSET[7:0], DI_EN */
/*MT6165*/    *ifN = BSI_CW( 0xB6, ((Nfrac&0x7FF)<<9) | ((*ifN)&0x1FF) );
/*MT6165*/ }
/*MT6165*/ /* =========================================================================== */
/*MT6165*/
/*MT6165*/ void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6165*/ {
/*MT6165*/    unsigned short Nint =0, CH_freq =0;
/*MT6165*/    unsigned long  Nfrac=0, VCO_freq=0;
/*MT6165*/
/*MT6165*/
/*MT6165*/    l1d_rf2.arfcn = arfcn;  //for L1D_RF_TxGainSetting
/*MT6165*/    CH_freq = L1D_RF_ARFCN_CH_to_TxFreq( rf_band, arfcn );
/*MT6165*/
/*MT6165*/    if( rf_band < FrequencyBand1800 )
/*MT6165*/       VCO_freq = 4*CH_freq;
/*MT6165*/    else
/*MT6165*/       VCO_freq = 2*CH_freq;
/*MT6165*/
/*MT6165*/    Nint  = VCO_freq/TX_DCXO_FREQ;
/*MT6165*/    Nfrac = ( ((VCO_freq-Nint*TX_DCXO_FREQ)<<23) + TX_DCXO_FREQ/2 )/TX_DCXO_FREQ;  //+TX_DCXO_FREQ/2 is for rounding
/*MT6165*/
/*MT6165*/    /* CW181, SRX_NINT[7:0], SRX_NRFC[22:11] */
/*MT6165*/    *rfN = BSI_CW( 0xB5, ((Nint &0xFF)<<12) | ((Nfrac>>11)&0xFFF) );
/*MT6165*/    /* CW182, SRX_NFRAC[10:0], DA_OFFSET[7:0], DI_EN */
/*MT6165*/    *ifN = BSI_CW( 0xB6, ((Nfrac&0x7FF)<<9) | (POR_CW182&0x1) ); // Keep DA_OFFSET=0x0 and setup at L1D_RF_SetSData_ST1()
/*MT6165*/
/*MT6165*/ }
/*MT6165*/ /* =========================================================================== */
/*MT6165*/
/*MT6165*/ void L1D_RF_SplitTxPLLSetting(unsigned long rfN, unsigned long ifN, unsigned short *Nint, unsigned long *Nfrac)
/*MT6165*/ {
/*MT6165*/    *Nint  = (rfN&(0xFF<<12))>>12;
/*MT6165*/    *Nfrac = ( (rfN&0xFFF)<<11 ) | ( (ifN&(0x7FF<<9))>>9 );
/*MT6165*/ }
/*MT6165*/ /* =========================================================================== */
/*MT6165*/
/*MT6165*/ void L1D_RF_AdjustTxPLLSetting(unsigned short Nint, unsigned long Nfrac, signed long NfracOffset, unsigned long *rfN, unsigned long *ifN )
/*MT6165*/ {
/*MT6165*/    L1D_RF_CompensateSXSetting( &Nint, &Nfrac, NfracOffset, 1 );
/*MT6165*/
/*MT6165*/    /* CW181, SRX_NINT[7:0], SRX_NRFC[22:11] */
/*MT6165*/    *rfN = BSI_CW( 0xB5, ((Nint &0xFF)<<12) | ((Nfrac>>11)&0xFFF) );
/*MT6165*/    /* CW182, SRX_NFRAC[10:0], DA_OFFSET[7:0], DI_EN */
/*MT6165*/    *ifN = BSI_CW( 0xB6, ((Nfrac&0x7FF)<<9) | ((*ifN)&0x1FF) );
/*MT6165*/ }
/*MT6165*/ /* =========================================================================== */
/*MT6165*/
/*MT6165*/ void L1D_RF_CompensateSXSetting( unsigned short *Nint, unsigned long *Nfrac, signed long NfracOffset, unsigned char is_TX)
/*MT6165*/ {
/*MT6165*/    signed long Max_Nfrac=0;
/*MT6165*/    if( is_TX )
/*MT6165*/    {  Max_Nfrac = STX_MAX_NFRAC;  }
/*MT6165*/    else
/*MT6165*/    {  Max_Nfrac = SRX_MAX_NFRAC;  }
/*MT6165*/
/*MT6165*/    //Calculate new Nfrac and Nint
/*MT6165*/    *Nfrac  += (NfracOffset + Max_Nfrac);
/*MT6165*/    if( *Nfrac < Max_Nfrac )
/*MT6165*/    {  (*Nint)--;
/*MT6165*/    }
/*MT6165*/    else if( *Nfrac >= (Max_Nfrac<<1) )
/*MT6165*/    {  (*Nint)++;
/*MT6165*/       *Nfrac = *Nfrac - (Max_Nfrac<<1);
/*MT6165*/    }
/*MT6165*/    else
/*MT6165*/    {  *Nfrac-= Max_Nfrac;
/*MT6165*/    }
/*MT6165*/ }
/*MT6165*/ /* =========================================================================== */
/*MT6165*/
/*MT6165*/ unsigned short L1D_RF_ARFCN_CH_to_RxFreq( int rf_band, int arfcn )
/*MT6165*/ {
/*MT6165*/    unsigned short freq=4450+225;
/*MT6165*/    switch( rf_band )
/*MT6165*/    {
/*MT6165*/       case  FrequencyBand850 :
/*MT6165*/       {
/*MT6165*/          freq=4121+(arfcn-128)+225;     //freq = f_ch*SYNTH_SCALE
/*MT6165*/          break;
/*MT6165*/       }
/*MT6165*/       case  FrequencyBand900 :
/*MT6165*/       {
/*MT6165*/          if( arfcn<=124 )
/*MT6165*/          {  freq=4450+arfcn+225;  }
/*MT6165*/          else
/*MT6165*/          {  freq=4450+(arfcn-1024)+225;  }
/*MT6165*/          break;
/*MT6165*/       }
/*MT6165*/       case  FrequencyBand1800 :
/*MT6165*/       {
/*MT6165*/          freq=8551+(arfcn-512)+475;
/*MT6165*/          break;
/*MT6165*/       }
/*MT6165*/       case  FrequencyBand1900 :
/*MT6165*/       {
/*MT6165*/          freq=9251+(arfcn-512)+400;
/*MT6165*/          break;
/*MT6165*/       }
/*MT6165*/       default :
/*MT6165*/       {
/*MT6165*/          break;
/*MT6165*/       }
/*MT6165*/    }
/*MT6165*/
/*MT6165*/    return freq;
/*MT6165*/ }
/*MT6165*/ /* =========================================================================== */
/*MT6165*/
/*MT6165*/ unsigned short L1D_RF_ARFCN_CH_to_TxFreq( int rf_band, int arfcn )
/*MT6165*/ {
/*MT6165*/    unsigned short freq=4450;
/*MT6165*/    switch( rf_band )
/*MT6165*/    {
/*MT6165*/       case  FrequencyBand850 :
/*MT6165*/       {
/*MT6165*/          freq=4121+(arfcn-128);     //freq = f_ch*SYNTH_SCALE
/*MT6165*/          break;
/*MT6165*/       }
/*MT6165*/       case  FrequencyBand900 :
/*MT6165*/       {
/*MT6165*/          if( arfcn<=124 )
/*MT6165*/          {  freq=4450+arfcn;  }
/*MT6165*/          else
/*MT6165*/          {  freq=4450+(arfcn-1024);  }
/*MT6165*/          break;
/*MT6165*/       }
/*MT6165*/       case  FrequencyBand1800 :
/*MT6165*/       {
/*MT6165*/          freq=8551+(arfcn-512);
/*MT6165*/          break;
/*MT6165*/       }
/*MT6165*/       case  FrequencyBand1900 :
/*MT6165*/       {
/*MT6165*/          freq=9251+(arfcn-512);
/*MT6165*/          break;
/*MT6165*/       }
/*MT6165*/       default :
/*MT6165*/       {
/*MT6165*/          break;
/*MT6165*/       }
/*MT6165*/    }
/*MT6165*/
/*MT6165*/    return freq;
/*MT6165*/ }
/*MT6165*/ /* =========================================================================== */
/*MT6165*/
/*MT6165*/ unsigned short L1D_RF_GetSxDCOSCACodeTypeSetting(unsigned short Nint, unsigned long  Nfrac)
/*MT6165*/ {
/*MT6165*/    char segment=3, LUT_num=11, offset=15; // LUT method related parameters
/*MT6165*/    signed short TXDCO_LUT[11]={1625, 1307, 1040, 818, 628, 467, 328, 208, 102, 11, -30};  // SXDCO LUT
/*MT6165*/    short idx, x_axis, code_type;  // code_type value for SCA calibration (code_type > 0)
/*MT6165*/
/*MT6165*/ #if IS_DUAL_LOOP_AFC_CONTROL_SUPPORT
/*MT6165*/    if( l1d_rf.is_lock_dcxo )
/*MT6165*/    {  L1D_RF_CompensateSXSetting( &Nint, &Nfrac, -l1d_rf.tx_nfracoffset, 1 );  }
/*MT6165*/ #endif
/*MT6165*/
/*MT6165*/    /* STX DCO SCA Typical Code LUT */
/*MT6165*/    idx = (Nint>>segment)-((short)offset);
/*MT6165*/    if(idx<0)
/*MT6165*/       idx = 0;
/*MT6165*/    else if(idx>(LUT_num-2))
/*MT6165*/       idx = LUT_num-2;
/*MT6165*/
/*MT6165*/    x_axis      = ((Nint-((Nint>>segment)<<segment))<<3)+((short)(Nfrac>>20));
/*MT6165*/    code_type   = TXDCO_LUT[idx]+ ((x_axis*(TXDCO_LUT[idx+1]-TXDCO_LUT[idx]))>>(segment+3));
/*MT6165*/    code_type <<= 1;
/*MT6165*/
/*MT6165*/    return code_type;
/*MT6165*/ }
/*MT6165*/ /* =========================================================================== */
/*MT6165*/
/*MT6165*/ unsigned short L1D_RF_GetTxDEMChunkSetting(int rf_band, unsigned short Nint)
/*MT6165*/ {
/*MT6165*/    unsigned short DEM_Chunk_L1;
/*MT6165*/    unsigned short OUT_G, OUT_E;
/*MT6165*/    char segment_dem=4, LUT_num_dem=4, offset_dem=7;     // LUT method related parameters
/*MT6165*/    signed short DEM_chunk_G_LUT[4]={15, 10,  7,  5};  // DEM chunk GMSK LUT
/*MT6165*/    signed short DEM_chunk_E_LUT[4]={69, 46, 33, 24};  // DEM chunk EPSK LUT
/*MT6165*/    short idx;
/*MT6165*/
/*MT6165*/    /* STX DEM CHUNK LUT */
/*MT6165*/    idx = (Nint>>segment_dem)-((short)offset_dem);
/*MT6165*/    if(idx<0)
/*MT6165*/       idx = 0;
/*MT6165*/    else if(idx>(LUT_num_dem-2))
/*MT6165*/       idx = LUT_num_dem-2;
/*MT6165*/
/*MT6165*/    OUT_G = DEM_chunk_G_LUT[idx]+(((Nint-((Nint>>segment_dem)<<segment_dem))*(DEM_chunk_G_LUT[idx+1]-DEM_chunk_G_LUT[idx]))>>(segment_dem));
/*MT6165*/    OUT_E = DEM_chunk_E_LUT[idx]+(((Nint-((Nint>>segment_dem)<<segment_dem))*(DEM_chunk_E_LUT[idx+1]-DEM_chunk_E_LUT[idx]))>>(segment_dem));
/*MT6165*/
/*MT6165*/    if( ( (l1d_rf.tx_mod_type2)^(l1d_rf.tx_mod_type2<<1) ) & 0xE )   // IS_MIXED_MULTISLOT
/*MT6165*/    {
/*MT6165*/       if( rf_band < FrequencyBand1800 )
/*MT6165*/          DEM_Chunk_L1 = ((OUT_E+OUT_G+5)>40) ? (OUT_E+OUT_G+5) : 40;
/*MT6165*/       else
/*MT6165*/          DEM_Chunk_L1 = 40;
/*MT6165*/    }
/*MT6165*/    else
/*MT6165*/    {
/*MT6165*/       if( (l1d_rf.tx_mod_type2 != 0) && (rf_band < FrequencyBand1800) )
/*MT6165*/          DEM_Chunk_L1 = ((2*OUT_E+6)>40) ? (2*OUT_E+6) : 40;
/*MT6165*/       else
/*MT6165*/          DEM_Chunk_L1 = 40;
/*MT6165*/    }
/*MT6165*/    return DEM_Chunk_L1;
/*MT6165*/ }
/*MT6165*/ /* =========================================================================== */
/*MT6165*/
/*MT6165*/ void L1D_RF_GetTxKDCOCAL2ndSetting(int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6165*/ {
/*MT6165*/    unsigned short Nint =0, CH_freq =0;
/*MT6165*/    unsigned long  Nfrac=0, DCO4G_freq=0, NCal=64;
/*MT6165*/    signed   long  Nfrac1Offset=0;
/*MT6165*/    unsigned short KDCO_NCAL_LUT[4]={64, 96, 16, 32};
/*MT6165*/
/*MT6165*/    CH_freq = L1D_RF_ARFCN_CH_to_TxFreq( rf_band, arfcn );
/*MT6165*/    NCal    = KDCO_NCAL_LUT[((POR_CW188>>6)&0x3)];
/*MT6165*/
/*MT6165*/    if( rf_band < FrequencyBand1800 )
/*MT6165*/       DCO4G_freq = 4*CH_freq;
/*MT6165*/    else
/*MT6165*/       DCO4G_freq = 2*CH_freq;
/*MT6165*/
/*MT6165*/    Nint  = ( (DCO4G_freq<<15) - NCal*DCO4G_freq + NCal*TX_DCXO_FREQ*92 ) / (TX_DCXO_FREQ<<15);
/*MT6165*/    Nfrac = ( ( ( (DCO4G_freq<<15) - NCal*DCO4G_freq + NCal*TX_DCXO_FREQ*92 - ((Nint*TX_DCXO_FREQ)<<15) )<<8 ) + TX_DCXO_FREQ/2 )/TX_DCXO_FREQ;  //+TX_DCXO_FREQ/2 is for rounding
/*MT6165*/
/*MT6165*/ #if IS_DUAL_LOOP_AFC_CONTROL_SUPPORT
/*MT6165*/    if( l1d_rf.is_lock_dcxo )
/*MT6165*/    {  Nfrac1Offset = l1d_rf.tx_nfracoffset - ((((signed long)NCal)*l1d_rf.tx_nfracoffset)>>15);
/*MT6165*/       L1D_RF_CompensateSXSetting( &Nint, &Nfrac, Nfrac1Offset, 1 );
/*MT6165*/    }
/*MT6165*/ #endif
/*MT6165*/
/*MT6165*/    /* CW183, N_INT1[7:0], N_FRFC1[22:11] */
/*MT6165*/    *rfN = BSI_CW( 0xB7, ((Nint &0xFF)<<12) | (Nfrac>>11) );
/*MT6165*/    /* CW184, N_FRAC1[10:0], NOFFSET_REV[2:0], STX_DCO_SCAK_NOFFSET[3:0], STX_MMD_SDM_DI_LS[1:0] */
/*MT6165*/    *ifN = BSI_CW( 0xB8, ((Nfrac&0x7FF)<<9) | (POR_CW184&0x1FF) );
/*MT6165*/
/*MT6165*/ }
/*MT6165*/ /* =========================================================================== */
/*MT6165*/
/*MT6165*/ unsigned short L1D_RF_GetSxDAoffsetSetting(unsigned long rfn)
/*MT6165*/ {
/*MT6165*/    unsigned short Nint        = ((rfn>>12)&0xFF);
/*MT6165*/    unsigned long  Nfrac_round = ((rfn>>11)&0x1);  // Check if (Nfrac*2^23)>0.5 by Nfrac[22]
/*MT6165*/    return (Nint+Nfrac_round-10);
/*MT6165*/ }
/*MT6165*/ /* =========================================================================== */
/*MT6165*/
/*MT6165*/ unsigned short L1D_RF_GetSCAKNoffsetSetting(unsigned short Nint)
/*MT6165*/ {
/*MT6165*/    unsigned short SCAK_NOFFSET;
/*MT6165*/    if( Nint<100 )
/*MT6165*/    {  SCAK_NOFFSET = 0;   }
/*MT6165*/    else if( Nint>227)
/*MT6165*/    {  SCAK_NOFFSET = 127; }
/*MT6165*/    else
/*MT6165*/    {  SCAK_NOFFSET = Nint-100;  }
/*MT6165*/
/*MT6165*/    return (SCAK_NOFFSET>>3);
/*MT6165*/ }
/*MT6165*/ /* =========================================================================== */
/*MT6165*/
#endif

#if IS_RF_MT6580RF
/*MT6580RF*/ //For DLIF mode
/*MT6580RF*/ void  L1D_RF_Cal_Synthesizer_Params( unsigned short* Nint, unsigned long* Nfrac, unsigned long  VCO_freq )
/*MT6580RF*/ {
/*MT6580RF*/    *Nint  = VCO_freq/(RX_DCXO_FREQ*DLIF_SCALE);
/*MT6580RF*/    //+195/2 is for rounding, 195=13*3*5, 5 is SYNTH_SCALE, 13 and 3 are related to DLIF
/*MT6580RF*/    *Nfrac = ( ((VCO_freq-*Nint*RX_DCXO_FREQ*DLIF_SCALE)<<15) + (195)/2 )/195;
/*MT6580RF*/ }
/*MT6580RF*/ /* =========================================================================== */
/*MT6580RF*/
/*MT6580RF*/ char  L1D_RF_Cal_IF_Synth_State( void )
/*MT6580RF*/ {
/*MT6580RF*/ #if IS_W_CANCELLATION_SUPPORT
/*MT6580RF*/    if( L1D_CheckIfMetaMode() )
/*MT6580RF*/    {  return l1d_rf.if_state;  }
/*MT6580RF*/    else
/*MT6580RF*/    {  return 0;  }
/*MT6580RF*/ #else
/*MT6580RF*/    return 0;
/*MT6580RF*/ #endif
/*MT6580RF*/ }
/*MT6580RF*/ /* =========================================================================== */
/*MT6580RF*/
/*MT6580RF*/ void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6580RF*/ {  long *if_sel = ifN+1;
/*MT6580RF*/    unsigned short Nint =0, CH_freq =0;
/*MT6580RF*/    unsigned long  Nfrac=0, VCO_freq=0;
/*MT6580RF*/    unsigned long  frac_spurs_thd0=0, frac_spurs_thd1=0;
/*MT6580RF*/    unsigned char  IF_state=0;   //IF_state=0:default, IF_state=1:+IF, IF_state=2:-IF
/*MT6580RF*/
/*MT6580RF*/    IF_state = L1D_RF_Cal_IF_Synth_State();
/*MT6580RF*/
/*MT6580RF*/    CH_freq = L1D_RF_ARFCN_CH_to_RxFreq( rf_band, arfcn );
/*MT6580RF*/
/*MT6580RF*/    if( IF_state != 2 )
/*MT6580RF*/    {
/*MT6580RF*/       *if_sel = 0;
/*MT6580RF*/ #if IS_W_CANCELLATION_SUPPORT
/*MT6580RF*/       l1d_rf.if_sel_Nif_wc = 0;
/*MT6580RF*/ #endif
/*MT6580RF*/       if( rf_band < FrequencyBand1800 )
/*MT6580RF*/       {
/*MT6580RF*/          VCO_freq = 4*(CH_freq*DLIF_SCALE - DLIF);  //High-side mixing
/*MT6580RF*/          frac_spurs_thd0 = 193584;
/*MT6580RF*/          frac_spurs_thd1 = 8195024;
/*MT6580RF*/       }
/*MT6580RF*/       else
/*MT6580RF*/       {
/*MT6580RF*/          VCO_freq = 2*(CH_freq*DLIF_SCALE - DLIF);  //High-side mixing
/*MT6580RF*/          frac_spurs_thd0 = 96792;
/*MT6580RF*/          frac_spurs_thd1 = 8291816;
/*MT6580RF*/       }
/*MT6580RF*/       L1D_RF_Cal_Synthesizer_Params( &Nint, &Nfrac, VCO_freq );
/*MT6580RF*/    }
/*MT6580RF*/
/*MT6580RF*/    if( IF_state != 1 )
/*MT6580RF*/    {
/*MT6580RF*/       // use +IF channel instead of -IF for IRR calibration
/*MT6580RF*/       if( ( Nfrac < frac_spurs_thd0 ) || ( Nfrac > frac_spurs_thd1) || ( Nfrac < 4258832 && Nfrac > 4129776 ) || ( IF_state == 2 ) )
/*MT6580RF*/       {
/*MT6580RF*/          *if_sel = 0;
/*MT6580RF*/ #if IS_W_CANCELLATION_SUPPORT
/*MT6580RF*/          l1d_rf.if_sel_Nif_wc = 1;
/*MT6580RF*/ #endif
/*MT6580RF*/          if( rf_band < FrequencyBand1800 )
/*MT6580RF*/          {  VCO_freq = 4*(CH_freq*DLIF_SCALE - DLIF);  }  //Low-side mixing
/*MT6580RF*/          else
/*MT6580RF*/          {  VCO_freq = 2*(CH_freq*DLIF_SCALE - DLIF);  }  //Low-side mixing
/*MT6580RF*/
/*MT6580RF*/          L1D_RF_Cal_Synthesizer_Params( &Nint, &Nfrac, VCO_freq );
/*MT6580RF*/       }
/*MT6580RF*/
/*MT6580RF*/    }
/*MT6580RF*/
/*MT6580RF*/ #if IS_OBB_DETECTION_SUPPORT
/*MT6580RF*/    if( !L1D_CheckIfMetaMode() )
/*MT6580RF*/    {
/*MT6580RF*/       if( l1d_rf.if_change == -1 && arfcn == l1d_rf.obb_arfcn )
/*MT6580RF*/       {
/*MT6580RF*/          signed short if_sign = l1d_rf.if_change*(*if_sel*2-1);
/*MT6580RF*/
/*MT6580RF*/          *if_sel = if_sign > 0 ? 1 : 0;
/*MT6580RF*/          if( rf_band < FrequencyBand1800 )
/*MT6580RF*/          {  VCO_freq = 4*(CH_freq*DLIF_SCALE + if_sign*DLIF);  }
/*MT6580RF*/          else
/*MT6580RF*/          {  VCO_freq = 2*(CH_freq*DLIF_SCALE + if_sign*DLIF);  }
/*MT6580RF*/
/*MT6580RF*/          L1D_RF_Cal_Synthesizer_Params( &Nint, &Nfrac, VCO_freq );
/*MT6580RF*/       }
/*MT6580RF*/    }
/*MT6580RF*/ #endif
/*MT6580RF*/
/*MT6580RF*/    /* CW223, SRX_NINT[8:0], SRX_NRFC[22:12] */
/*MT6580RF*/    *rfN = BSI_CW( 0xDF, ((Nint &0x1FF)<<11) | ((Nfrac>>12)&0x7FF) );
/*MT6580RF*/    /* CW224, SRX_NFRAC[11:0],SRX_REF_DOUBLER_EN,SRX_CAL_DISABLE,SRX_VCO_CFG[2:0],TALL_TRG_M,SRX_SDM_FRAC_MODE,SRX_RELOCK */
/*MT6580RF*/    *ifN = BSI_CW( 0xE0, ((Nfrac&0xFFF)<<8) | SRX_REF_DOUBLER_EN | SRX_VCO_CFG | (POR_CW224&0x47) );
/*MT6580RF*/
/*MT6580RF*/ }
/*MT6580RF*/ /* =========================================================================== */
/*MT6580RF*/
/*MT6580RF*/ void L1D_RF_SplitRxPLLSetting(unsigned long rfN, unsigned long ifN, unsigned short *Nint, unsigned long *Nfrac)
/*MT6580RF*/ {
/*MT6580RF*/    *Nint  = (rfN&(0x1FF<<11))>>11;
/*MT6580RF*/    *Nfrac = ( (rfN&0x7FF)<<12 ) | ( (ifN&(0xFFF<<8))>>8 );
/*MT6580RF*/ }
/*MT6580RF*/ /* =========================================================================== */
/*MT6580RF*/
/*MT6580RF*/ void L1D_RF_AdjustRxPLLSetting(unsigned short Nint, unsigned long Nfrac, signed long NfracOffset, unsigned long *rfN, unsigned long *ifN )
/*MT6580RF*/ {
/*MT6580RF*/    L1D_RF_CompensateSXSetting( &Nint, &Nfrac, NfracOffset, 0 );
/*MT6580RF*/
/*MT6580RF*/    /* CW223, SRX_NINT[8:0], SRX_NRFC[22:12] */
/*MT6580RF*/    *rfN = BSI_CW( 0xDF, ((Nint &0x1FF)<<11) | ((Nfrac>>12)&0x7FF) );
/*MT6580RF*/    /* CW224, SRX_NFRAC[11:0],SRX_REF_DOUBLER_EN,SRX_CAL_DISABLE,SRX_VCO_CFG[2:0],TALL_TRG_M,SRX_SDM_FRAC_MODE,SRX_RELOCK */
/*MT6580RF*/    *ifN = BSI_CW( 0xE0, ((Nfrac&0xFFF)<<8)  | ((*ifN)&0xFF));
/*MT6580RF*/ }
/*MT6580RF*/ /* =========================================================================== */
/*MT6580RF*/
/*MT6580RF*/ //void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6580RF*/ //{  long *if_sel = ifN+1;
/*MT6580RF*/ //   unsigned short Nint =0, CH_freq =0;
/*MT6580RF*/ //   unsigned long  Nfrac=0, VCO_freq=0;
/*MT6580RF*/
/*MT6580RF*/ //   CH_freq = L1D_RF_ARFCN_CH_to_RxFreq( rf_band, arfcn );
/*MT6580RF*/
/*MT6580RF*/ //   *if_sel = 0;
/*MT6580RF*/ //   if( rf_band < FrequencyBand1800 )
/*MT6580RF*/ //      VCO_freq = 4*(CH_freq*DLIF_SCALE - DLIF);
/*MT6580RF*/ //   else
/*MT6580RF*/ //      VCO_freq = 2*(CH_freq*DLIF_SCALE - DLIF);
/*MT6580RF*/
/*MT6580RF*/ //   Nint  = VCO_freq/(RX_DCXO_FREQ*DLIF_SCALE);
/*MT6580RF*/    //+195/2 is for rounding, 195=13*3*5, 5 is SYNTH_SCALE, 13 and 3 are related to DLIF
/*MT6580RF*/ //   Nfrac = ( ((VCO_freq-Nint*RX_DCXO_FREQ*DLIF_SCALE)<<14) + (195)/2 )/195;
/*MT6580RF*/
/*MT6580RF*/    /* CW223, SRX_NINT[8:0], SRX_NRFC[22:12] */
/*MT6580RF*/ //   *rfN = BSI_CW( 0xDF, ((Nint &0x1FF)<<11) | ((Nfrac>>12)&0x7FF) );
/*MT6580RF*/    /* CW224, SRX_NFRAC[11:0],SRX_REF_DOUBLER_EN,SRX_CAL_DISABLE,SRX_VCO_CFG[2:0],TALL_TRG_M,SRX_SDM_FRAC_MODE,SRX_RELOCK */
/*MT6580RF*/ //   *ifN = BSI_CW( 0xE0, ((Nfrac&0xFFF)<<8) | SRX_REF_DOUBLER_EN | SRX_VCO_CFG | (POR_CW224&0x47) );
/*MT6580RF*/ //}
/*MT6580RF*/ /* =========================================================================== */
/*MT6580RF*/
/*MT6580RF*/ void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6580RF*/ {
/*MT6580RF*/    unsigned short Nint =0, CH_freq =0;
/*MT6580RF*/    unsigned long  Nfrac=0, VCO_freq=0;
/*MT6580RF*/    unsigned short DAoffset=0;
/*MT6580RF*/
/*MT6580RF*/
/*MT6580RF*/    l1d_rf2.arfcn = arfcn;  //for L1D_RF_TxGainSetting
/*MT6580RF*/    CH_freq = L1D_RF_ARFCN_CH_to_TxFreq( rf_band, arfcn );
/*MT6580RF*/
/*MT6580RF*/    if( rf_band < FrequencyBand1800 )
/*MT6580RF*/       VCO_freq = 4*CH_freq;
/*MT6580RF*/    else
/*MT6580RF*/       VCO_freq = 2*CH_freq;
/*MT6580RF*/
/*MT6580RF*/    Nint  = VCO_freq/TX_DCXO_FREQ;
/*MT6580RF*/    Nfrac = ( ((VCO_freq-Nint*TX_DCXO_FREQ)<<23) + TX_DCXO_FREQ/2 )/TX_DCXO_FREQ;  //+TX_DCXO_FREQ/2 is for rounding
/*MT6580RF*/
/*MT6580RF*/    DAoffset = 10;//L1D_RF_GetTxDAoffsetSetting( Nint );
/*MT6580RF*/
/*MT6580RF*/    /* CW96, N_INT[7:0], N_RFC[22:11] */
/*MT6580RF*/    *rfN = BSI_CW( 0x60, ((Nint &0xFF)<<12) | (Nfrac>>11) );
/*MT6580RF*/    /* CW97, N_FRAC[10:0], DA_OFFSET[4:0], DI_EN */
/*MT6580RF*/    *ifN = BSI_CW( 0x61, ((Nfrac&0x7FF)<<9) | ((DAoffset&0x1F)<<4) | 0x1);
/*MT6580RF*/
/*MT6580RF*/ }
/*MT6580RF*/ /* =========================================================================== */
/*MT6580RF*/
/*MT6580RF*/ void L1D_RF_SplitTxPLLSetting(unsigned long rfN, unsigned long ifN, unsigned short *Nint, unsigned long *Nfrac)
/*MT6580RF*/ {
/*MT6580RF*/    *Nint  = (rfN&(0xFF<<12))>>12;
/*MT6580RF*/    *Nfrac = ( (rfN&0xFFF)<<11 ) | ( (ifN&(0x7FF<<9))>>9 );
/*MT6580RF*/ }
/*MT6580RF*/ /* =========================================================================== */
/*MT6580RF*/
/*MT6580RF*/ void L1D_RF_AdjustTxPLLSetting(unsigned short Nint, unsigned long Nfrac, signed long NfracOffset, unsigned long *rfN, unsigned long *ifN )
/*MT6580RF*/ {
/*MT6580RF*/    L1D_RF_CompensateSXSetting( &Nint, &Nfrac, NfracOffset, 1 );
/*MT6580RF*/
/*MT6580RF*/    /* CW96, N_INT[7:0], N_RFC[22:11] */
/*MT6580RF*/    *rfN = BSI_CW( 0x60, ((Nint &0xFF)<<12) | (Nfrac>>11) );
/*MT6580RF*/    /* CW97, N_FRAC[10:0], DA_OFFSET[4:0], DI_EN */
/*MT6580RF*/    *ifN = BSI_CW( 0x61, ((Nfrac&0x7FF)<<9) |((*ifN)&0x1FF));
/*MT6580RF*/ }
/*MT6580RF*/ /* =========================================================================== */
/*MT6580RF*/
/*MT6580RF*/ void L1D_RF_CompensateSXSetting( unsigned short *Nint, unsigned long *Nfrac, signed long NfracOffset, unsigned char is_TX)
/*MT6580RF*/ {
/*MT6580RF*/    signed long Max_Nfrac=0;
/*MT6580RF*/    if( is_TX )
/*MT6580RF*/    {  Max_Nfrac = STX_MAX_NFRAC;  }
/*MT6580RF*/    else
/*MT6580RF*/    {  Max_Nfrac = SRX_MAX_NFRAC;  }
/*MT6580RF*/
/*MT6580RF*/    //Calculate new Nfrac and Nint
/*MT6580RF*/    *Nfrac  += (NfracOffset + Max_Nfrac);
/*MT6580RF*/    if( *Nfrac < Max_Nfrac )
/*MT6580RF*/    {  (*Nint)--;
/*MT6580RF*/    }
/*MT6580RF*/    else if( *Nfrac >= (Max_Nfrac<<1) )
/*MT6580RF*/    {  (*Nint)++;
/*MT6580RF*/       *Nfrac = *Nfrac - (Max_Nfrac<<1);
/*MT6580RF*/    }
/*MT6580RF*/    else
/*MT6580RF*/    {  *Nfrac-= Max_Nfrac;
/*MT6580RF*/    }
/*MT6580RF*/ }
/*MT6580RF*/ /* =========================================================================== */
/*MT6580RF*/
/*MT6580RF*/ unsigned short L1D_RF_ARFCN_CH_to_RxFreq( int rf_band, int arfcn )
/*MT6580RF*/ {
/*MT6580RF*/    unsigned short freq=4450+225;
/*MT6580RF*/    switch( rf_band )
/*MT6580RF*/    {
/*MT6580RF*/       case  FrequencyBand850 :
/*MT6580RF*/       {
/*MT6580RF*/          freq=4121+(arfcn-128)+225;     //freq = f_ch*SYNTH_SCALE
/*MT6580RF*/          break;
/*MT6580RF*/       }
/*MT6580RF*/       case  FrequencyBand900 :
/*MT6580RF*/       {
/*MT6580RF*/          if( arfcn<=124 )
/*MT6580RF*/          {  freq=4450+arfcn+225;  }
/*MT6580RF*/          else
/*MT6580RF*/          {  freq=4450+(arfcn-1024)+225;  }
/*MT6580RF*/          break;
/*MT6580RF*/       }
/*MT6580RF*/       case  FrequencyBand1800 :
/*MT6580RF*/       {
/*MT6580RF*/          freq=8551+(arfcn-512)+475;
/*MT6580RF*/          break;
/*MT6580RF*/       }
/*MT6580RF*/       case  FrequencyBand1900 :
/*MT6580RF*/       {
/*MT6580RF*/          freq=9251+(arfcn-512)+400;
/*MT6580RF*/          break;
/*MT6580RF*/       }
/*MT6580RF*/       default :
/*MT6580RF*/       {
/*MT6580RF*/          break;
/*MT6580RF*/       }
/*MT6580RF*/    }
/*MT6580RF*/
/*MT6580RF*/    return freq;
/*MT6580RF*/ }
/*MT6580RF*/ /* =========================================================================== */
/*MT6580RF*/
/*MT6580RF*/ unsigned short L1D_RF_ARFCN_CH_to_TxFreq( int rf_band, int arfcn )
/*MT6580RF*/ {
/*MT6580RF*/    unsigned short freq=4450;
/*MT6580RF*/    switch( rf_band )
/*MT6580RF*/    {
/*MT6580RF*/       case  FrequencyBand850 :
/*MT6580RF*/       {
/*MT6580RF*/          freq=4121+(arfcn-128);     //freq = f_ch*SYNTH_SCALE
/*MT6580RF*/          break;
/*MT6580RF*/       }
/*MT6580RF*/       case  FrequencyBand900 :
/*MT6580RF*/       {
/*MT6580RF*/          if( arfcn<=124 )
/*MT6580RF*/          {  freq=4450+arfcn;  }
/*MT6580RF*/          else
/*MT6580RF*/          {  freq=4450+(arfcn-1024);  }
/*MT6580RF*/          break;
/*MT6580RF*/       }
/*MT6580RF*/       case  FrequencyBand1800 :
/*MT6580RF*/       {
/*MT6580RF*/          freq=8551+(arfcn-512);
/*MT6580RF*/          break;
/*MT6580RF*/       }
/*MT6580RF*/       case  FrequencyBand1900 :
/*MT6580RF*/       {
/*MT6580RF*/          freq=9251+(arfcn-512);
/*MT6580RF*/          break;
/*MT6580RF*/       }
/*MT6580RF*/       default :
/*MT6580RF*/       {
/*MT6580RF*/          break;
/*MT6580RF*/       }
/*MT6580RF*/    }
/*MT6580RF*/
/*MT6580RF*/    return freq;
/*MT6580RF*/ }
/*MT6580RF*/ /* =========================================================================== */
/*MT6580RF*/
/*MT6580RF*/ unsigned short L1D_RF_GetTxDCOSCACodeTypeSetting(unsigned short Nint, unsigned long  Nfrac)
/*MT6580RF*/ {
/*MT6580RF*/    char segment_tx=3, LUT_num_tx=6, offset_tx=15; // LUT method related parameters
/*MT6580RF*/    signed short TXDCO_LUT[6]={1566, 1169, 840, 565, 331, -40};  // TXDCO LUT
/*MT6580RF*/    short idx, x_axis, code_type;  // code_type value for SCA calibration (code_type > 0)
/*MT6580RF*/
/*MT6580RF*/ #if IS_DUAL_LOOP_AFC_CONTROL_SUPPORT
/*MT6580RF*/    if( l1d_rf.is_lock_dcxo )
/*MT6580RF*/    {  L1D_RF_CompensateSXSetting( &Nint, &Nfrac, -l1d_rf.tx_nfracoffset, 1 );  }
/*MT6580RF*/ #endif
/*MT6580RF*/
/*MT6580RF*/    /* STX DCO SCA Typical Code LUT */
/*MT6580RF*/    idx = (Nint>>segment_tx)-((short)offset_tx);
/*MT6580RF*/    if(idx<0)
/*MT6580RF*/       idx = 0;
/*MT6580RF*/    else if(idx>(LUT_num_tx-2))
/*MT6580RF*/       idx = LUT_num_tx-2;
/*MT6580RF*/
/*MT6580RF*/    x_axis      = ((Nint-((Nint>>segment_tx)<<segment_tx))<<3)+((short)(Nfrac>>20));
/*MT6580RF*/    code_type   = TXDCO_LUT[idx]+ ((x_axis*(TXDCO_LUT[idx+1]-TXDCO_LUT[idx]))>>(segment_tx+3));
/*MT6580RF*/    code_type <<= 1;
/*MT6580RF*/
/*MT6580RF*/    return code_type;
/*MT6580RF*/ }
/*MT6580RF*/ /* =========================================================================== */
/*MT6580RF*/
/*MT6580RF*/ unsigned short L1D_RF_GetTxDEMChunkSetting(int rf_band, unsigned short Nint)
/*MT6580RF*/ {
/*MT6580RF*/    unsigned short DEM_Chunk_L1;
/*MT6580RF*/    unsigned short OUT_G, OUT_E;
/*MT6580RF*/    char segment_dem=4, LUT_num_dem=4, offset_dem=7;     // LUT method related parameters
/*MT6580RF*/    signed short DEM_chunk_G_LUT[4]={15, 10,  7,  5};  // DEM chunk GMSK LUT
/*MT6580RF*/    signed short DEM_chunk_E_LUT[4]={69, 46, 33, 24};  // DEM chunk EPSK LUT
/*MT6580RF*/    short idx;
/*MT6580RF*/
/*MT6580RF*/    /* STX DEM CHUNK LUT */
/*MT6580RF*/	  idx = (Nint>>segment_dem)-((short)offset_dem);
/*MT6580RF*/    if(idx<0)
/*MT6580RF*/       idx = 0;
/*MT6580RF*/    else if(idx>(LUT_num_dem-2))
/*MT6580RF*/       idx = LUT_num_dem-2;
/*MT6580RF*/
/*MT6580RF*/    OUT_G = DEM_chunk_G_LUT[idx]+(((Nint-((Nint>>segment_dem)<<segment_dem))*(DEM_chunk_G_LUT[idx+1]-DEM_chunk_G_LUT[idx]))>>(segment_dem));
/*MT6580RF*/    OUT_E = DEM_chunk_E_LUT[idx]+(((Nint-((Nint>>segment_dem)<<segment_dem))*(DEM_chunk_E_LUT[idx+1]-DEM_chunk_E_LUT[idx]))>>(segment_dem));
/*MT6580RF*/
/*MT6580RF*/    if( ( (l1d_rf.tx_mod_type2)^(l1d_rf.tx_mod_type2<<1) ) & 0xE )   // IS_MIXED_MULTISLOT
/*MT6580RF*/    {
/*MT6580RF*/       if( rf_band < FrequencyBand1800 )
/*MT6580RF*/          DEM_Chunk_L1 = ((OUT_E+OUT_G+5)>40) ? (OUT_E+OUT_G+5) : 40;
/*MT6580RF*/       else
/*MT6580RF*/          DEM_Chunk_L1 = 40;
/*MT6580RF*/    }
/*MT6580RF*/    else
/*MT6580RF*/    {
/*MT6580RF*/       if( (l1d_rf.tx_mod_type2 != 0) && (rf_band < FrequencyBand1800) )
/*MT6580RF*/          DEM_Chunk_L1 = ((2*OUT_E+6)>40) ? (2*OUT_E+6) : 40;
/*MT6580RF*/       else
/*MT6580RF*/          DEM_Chunk_L1 = 40;
/*MT6580RF*/    }
/*MT6580RF*/    return DEM_Chunk_L1;
/*MT6580RF*/ }
/*MT6580RF*/ /* =========================================================================== */
/*MT6580RF*/
/*MT6580RF*/ void L1D_RF_GetTxKDCOCAL2ndSetting(int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6580RF*/ {
/*MT6580RF*/    unsigned short Nint =0, CH_freq =0;
/*MT6580RF*/    unsigned long  Nfrac=0, DCO4G_freq=0;
/*MT6580RF*/
/*MT6580RF*/    CH_freq = L1D_RF_ARFCN_CH_to_TxFreq( rf_band, arfcn );
/*MT6580RF*/
/*MT6580RF*/    if( rf_band < FrequencyBand1800 )
/*MT6580RF*/       DCO4G_freq = 4*CH_freq;
/*MT6580RF*/    else
/*MT6580RF*/       DCO4G_freq = 2*CH_freq;
/*MT6580RF*/
/*MT6580RF*/    Nint  = ( (DCO4G_freq<<15) - 64*DCO4G_freq + 64*TX_DCXO_FREQ*92 ) / (TX_DCXO_FREQ<<15);
/*MT6580RF*/    Nfrac = ( ( ( (DCO4G_freq<<15) - 64*DCO4G_freq + 64*TX_DCXO_FREQ*92 - ((Nint*TX_DCXO_FREQ)<<15) )<<8 ) + TX_DCXO_FREQ/2 )/TX_DCXO_FREQ;  //+TX_DCXO_FREQ/2 is for rounding
/*MT6580RF*/
/*MT6580RF*/ #if IS_DUAL_LOOP_AFC_CONTROL_SUPPORT
/*MT6580RF*/    if( l1d_rf.is_lock_dcxo )
/*MT6580RF*/    {  L1D_RF_CompensateSXSetting( &Nint, &Nfrac, l1d_rf.tx_nfracoffset, 1 );  }
/*MT6580RF*/ #endif
/*MT6580RF*/
/*MT6580RF*/    /* CW98, N_INT1[7:0], N_RFC1[22:11] */
/*MT6580RF*/    *rfN = BSI_CW( 0x62, ((Nint &0xFF)<<12) | (Nfrac>>11) );
/*MT6580RF*/    /* CW99, N_FRAC1[10:0], NOFFSET_REV[3:0], STX_DCO_SCAK_NOFFSET[2:0], STX_MMD_SDM_DI_LS[1:0] */
/*MT6580RF*/    *ifN = BSI_CW( 0x63, ((Nfrac&0x7FF)<<9) | (POR_CW99&0x1FF) );
/*MT6580RF*/
/*MT6580RF*/ }
/*MT6580RF*/ /* =========================================================================== */
/*MT6580RF*/
#endif

