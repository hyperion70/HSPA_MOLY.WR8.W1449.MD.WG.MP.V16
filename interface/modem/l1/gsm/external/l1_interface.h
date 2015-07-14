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
 *   l1_interface.h
 *
 * Project:
 * --------
 *
 *
 * Description:
 * ------------
 *   Interface for system service.
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Revision:     $
 * $Modtime:      $
 * $Log:   //mtkvs01/vmdata/Maui_sw/archives/mcu/interface/l1interface/l1_interface.h-arc  $
 *
 * 12 12 2013 hosen.chen
 * [MOLY00049896] [MT6571V1_PHONE][Power management] auto suspend resume test while video playback and loop, Externel (EE),0,0,99,/data/core/,1,modem,md1
 * 	.
 *
 * 12 11 2013 hsin-chun.chen
 * [MOLY00049896] [MT6571V1_PHONE][Power management] auto suspend resume test while video playback and loop, Externel (EE),0,0,99,/data/core/,1,modem,md1
 * 	.
 *
 * 10 17 2013 hsin-chun.chen
 * [MOLY00022472] [Volunteer Patch] TDMA Interrupt Timing Profile Test Code
 * 	Update 6571 L1C margin.
 *
 * 10 09 2013 hsin-chun.chen
 * [MOLY00022472] [Volunteer Patch] TDMA Interrupt Timing Profile Test Code
 * 	Update L1C wakeup margin for 71.
 * 	.
 *
 * 08 22 2013 vend_cuthbert.kao
 * [MOLY00034524] [MT6592][MT6571][L1D][Modify] MT6592 BB Driver + MT6571 BB Driver + MT6165 RF Driver integration
 * .
 *
 * 08 20 2013 hsin-chun.chen
 * [MOLY00030895] [MT6592] Chip Option Porting [MOLY NOT NEED]
 * 	.
 *
 * 05 14 2013 hsin-chun.chen
 * [MOLY00022472] [Volunteer Patch] TDMA Interrupt Timing Profile Test Code
 * .
 *
 * 05 14 2013 sean.yang
 * [MOLY00022263] [Volunteer Patch] [MT6572/6582] Common Modem Image feature patch
 * .
 *
 * 05 14 2013 hsin-chun.chen
 * [MOLY00022472] [Volunteer Patch] TDMA Interrupt Timing Profile Test Code
 * .
 *
 * 03 11 2013 hsin-chun.chen
 * [MOLY00009022] [L1D][Modify] Modify MT6589 TDMA interrupt wake up timing setting
 * .
 *
 * 01 29 2013 sean.yang
 * [MOLY00009515] [L1D][Modify] Check-in MT6572/MT6582 codes
 * .
 *
 * 01 18 2013 hosen.chen
 * [MOLY00009022] [L1D][Modify] Modify MT6589 TDMA interrupt wake up timing setting
 * .
 *
 * 09 07 2012 samuel.yang
 * [MOLY00002639] [L1D][Modify] Separate l1d_reg.h into two parts of "for l1 internal use" and "for other module use"
 * .
 *
 * 06 22 2012 samuel.yang
 * removed!
 * .
 *
 * 05 25 2012 yi-ying.lin
 * removed!
 * .
 *
 * 05 10 2012 hosen.chen
 * removed!
 * .
 *
 * 05 08 2012 samuel.yang
 * removed!
 * .
 *
 * 03 30 2012 terence.chen
 * removed!
 * .
 *
 * 03 19 2012 weining.chien
 * removed!
 * .
 *
 * 03 16 2012 weining.chien
 * removed!
 * .
 *
 * 03 13 2012 weining.chien
 * removed!
 * .
 *
 * 11 08 2011 jason.lai
 * removed!
 * .
 *
 * 11 02 2011 sean.yang
 * removed!
 * .
 *
 * 11 01 2011 sean.yang
 * removed!
 * .
 *
 * 09 09 2011 duncan.cheng
 * removed!
 * .
 *
 * 08 11 2011 sean.yang
 * removed!
 * .
 *
 * 02 01 2011 jason.lai
 * removed!
 * .
 *
 * 12 15 2010 chang-kuan.lin
 * removed!
 * .
 *
 * 12 06 2010 jason.lai
 * removed!
 * .
 *
 * 12 01 2010 yr.chiang
 * removed!
 * .
 *
 * 07 31 2010 samuel.yang
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
 * Let L1D_FH_FM_TurnOn()/L1D_FH_FM_SetFreq() always as function
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * Update HW_tdma_auxev_time_setup() as macro
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
 * Add declaration of HW_wait_32k_start
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *******************************************************************************/

#ifndef  _L1_INTERFACE_H_
#define  _L1_INTERFACE_H_
/* ------------------------------------------------------------------------- */

#include "kal_general_types.h"

#if (defined L1_SIM) || (defined MT6268T) || (defined __UE_SIMULATOR__)
#include "tool.h"
#else
#define  HW_WRITE(ptr,data)         (*(ptr) = (data))
#define  HW_READ(ptr)               (*(ptr))
#define  LET_SIM_TIME_RUN_A_BIT()
#endif

extern kal_uint16 L1_ASSERT_BYPASS;
extern kal_uint16 L1D_MD2G_SLEEP_STATUS( void );
extern void       L1D_INFORM_DSP_WAKEUP( void );
extern void       L1D_INFORM_DSP_REENTER_SLEEP( void );
extern void       L1D_HW_TDMA_AUX_TIME_SETUP( kal_uint16 event0, kal_uint16 event1 );
extern kal_uint16 L1D_TDMA_GET_TQCNT( void );
extern kal_uint16 L1D_HW_TDMA_GET_TQWRAP( void );
extern kal_uint32 L1D_HW_TDMA_GET_32KCNT( void );
extern void       L1D_INFORM_DCXO_WAKEUP( void );
extern void       L1D_PMU_FIX_VRF1828SETTING( unsigned char is_fixed ); /* workaround for BT EVM performace due to VRF18/28 change */
extern kal_bool   L1D_REPORT_CALDATA_DOWNLOAD_STATUS( void );
extern char L1D_INFORM_WIFI_DEGRADE_POWER( void ); /* workaround for low GSM RX performace due to large wifi TX power. */
extern void       L1D_UeBandCapability( kal_uint8 *ue_cap );

/*************************************************************************
 * API provided for other modules
 *************************************************************************/

#if (defined L1_NOT_PRESENT)
#define  L1_CHECK_ASSERT_BYPASS()           (0)
#define  MD2G_SLEEP_STATUS()                (1)
#define  INFORM_DSP_WAKEUP()                {}
#define  INFORM_DSP_REENTER_SLEEP()         {}
#define  L1D_DCXO_WAKEUP()                  {}
#define  L1D_FIX_VRF1828SETTING( is_fixed ) {}
#define  INFORM_WIFI_DEGRADE_POWER()        (0)
#else
#define  L1_CHECK_ASSERT_BYPASS()           (L1_ASSERT_BYPASS & 0x3)
#define  MD2G_SLEEP_STATUS()                L1D_MD2G_SLEEP_STATUS()
#define  INFORM_DSP_WAKEUP()                L1D_INFORM_DSP_WAKEUP()
#define  INFORM_DSP_REENTER_SLEEP()         L1D_INFORM_DSP_REENTER_SLEEP()
#define  L1D_DCXO_WAKEUP()                  L1D_INFORM_DCXO_WAKEUP()
#define  L1D_FIX_VRF1828SETTING( is_fixed ) L1D_PMU_FIX_VRF1828SETTING( is_fixed )
#define  INFORM_WIFI_DEGRADE_POWER()        L1D_INFORM_WIFI_DEGRADE_POWER()
#endif

void  HW_TDMA_Start(void);         /* power on TDMA module               */
void  HW_TDMA_Enable_CTIRQ1(void); /* enable TDMA module CTIRQ1          */
void  HW_wait_32k_start(void);     /* use 13M/26M to calibrate 32k clock */

#define  HW_tdma_auxev_time_setup(event0,event1)  L1D_HW_TDMA_AUX_TIME_SETUP(event0, event1)

#define  HW_TDMA_GET_TQCNT()        L1D_TDMA_GET_TQCNT()
#define  HW_TDMA_GET_TQWRAP()       L1D_HW_TDMA_GET_TQWRAP()
#define  HW_TDMA_GET_32KCNT()       L1D_HW_TDMA_GET_32KCNT()

extern unsigned char L1D_IS_MT6162_DCXO( void );

/* APIs for audio */
extern kal_uint16 L1D_Get_Win_TQ_WRAP( void );
extern kal_int8   L1D_GetT2( void );
extern void       L1D_ENABLE_DTIRQ( void );
extern void       L1D_CCCDReset( void );
extern kal_bool   L1D_Get_Speech_Re_Sync_Flag( void );
/* ------------------------------------------------------------------------- */

extern void MD_DRV_L1D_Exit( void );
/* ------------------------------------------------------------------------- */

#if MD_DRV_IS_CHIP_MT6571
#define L1D_WAKEUP_MARGIN                   (1350)
#elif MD_DRV_IS_CHIP_MT6583_MD1 || MD_DRV_IS_CHIP_MT6583_MD2 || MD_DRV_IS_CHIP_MT6572
#define L1D_WAKEUP_MARGIN                   (1050)
#endif

#if MD_DRV_IS_CHIP_MT6582 || MD_DRV_IS_CHIP_MT6592
    #define L1C_WAKEUP_MARGIN                   (350)
#elif MD_DRV_IS_CHIP_MT6583_MD1 || MD_DRV_IS_CHIP_MT6583_MD2 || MD_DRV_IS_CHIP_MT6572 || MD_DRV_IS_CHIP_MT6571
    #define L1C_WAKEUP_MARGIN                   (660)
#else
    #define L1C_WAKEUP_MARGIN                   (660)
#endif

/* ------------------------------------------------------------------------- */

#endif

