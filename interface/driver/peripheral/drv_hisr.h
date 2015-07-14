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
 * Filename:
 * ---------
 *	drv_hisr.h
 *
 * Project:
 * --------
 *   ALL
 *
 * Description:
 * ------------
 *   This file is intends for central driver HISR.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _DRV_HISR_H
#define _DRV_HISR_H

#include "drv_comm.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"

typedef enum {
   DRV_CCIF_HISR_ID = 0,
   DRV_MDIF_HISR_ID,
   DRV_RT_MDIF_HISR_ID,
   DRV_BTIF_HISR_ID,
   DRV_PFC_HISR_ID,
   DRV_PFC_DECODE_HISR_ID,
   DRV_PFC_ENCODE_HISR_ID,
   DRV_USIM_HSIR_ID,
   DRV_USIM2_HSIR_ID,
   DRV_FMIF_HISR_ID,
   DRV_EINT_HISR_ID,
   DRV_WDT_HISR_ID,
   DRV_USB_HISR_ID,
   DRV_USBDMA_HISR_ID,
   DRV_USB_LOGGING_3G_HISR_ID,
   DRV_USB_LOGGING_DSP1_HISR_ID,
   DRV_USB_LOGGING_DSP2_HISR_ID,
   DRV_NFI_HISR_ID,
   DRV_MSDC_HISR_ID,
   DRV_MSDC2_HISR_ID,
   DRV_SIM_HISR_ID,
   DRV_SIM2_HISR_ID,
   DRV_UART1_HISR_ID,
   DRV_UART2_HISR_ID,
   DRV_UART3_HISR_ID,
   DRV_DMA_HISR_ID,
   DRV_GPT_HISR_ID,
   DRV_PWM_HISR_ID,
   DRV_LCD_WFC_HISR_ID,
   DRV_LCD_HISR_ID,
   DRV_GOVL_HISR_ID,
   DRV_HIF0_HISR_ID,
   DRV_HIF1_HISR_ID,
   DRV_BTIF_SLEEP_WAKEUP_OUT_HISR_ID,
   DRV_ACCDET_HISR_ID,
   DRV_KP_HISR_ID,
   DRV_AUXADC_HISR_ID,
   DRV_RTC_HISR_ID,
   DRV_FPGA_DMA_HISR_ID,
   DRV_IRDA_HISR_ID,
   DRV_CHE_HISR_ID,
   DRV_SPI_HISR_ID,
   DRV_NIRQ_HISR_ID,
   DRV_NFIQ_HISR_ID,
   DRV_DMA2_HISR_ID,
   DRV_GROT_HISR_ID,
   DRV_LZMA_HISR_ID,
   MAX_DRV_HISR_DEVICE,
   DRV_UNKNOWN_HISR_ID = 0xfe
} DRV_HISR_ID;

#if MAX_DRV_HISR_DEVICE > (32*2)
#error DRV HISR ID out of range!!
#endif


typedef struct {
   VOID_FUNC   hisr_func;
   kal_uint16  hisr_count;
} DRV_HISR_STRUCT;

#if !defined(__FUE__) && !defined(__UBL__)
extern void drv_active_hisr(DRV_HISR_ID id);
#else /* __FUE__ */
#define drv_active_hisr(_id)  
#endif /* __FUE__ */


typedef void (* VOID_FUNCTION)(void);
extern kal_hisrid drv_hisr;
extern kal_uint32 drv_hisr_status1;
extern kal_uint32 drv_hisr_status2;
extern DRV_HISR_STRUCT DRV_HISR_TABLE[MAX_DRV_HISR_DEVICE];

// MoDIS parser skip start
extern void DRV_Register_HISR(DRV_HISR_ID hisr_id, VOID_FUNCTION hisr_func);
extern void DRV_HISR(void);
extern void drv_hisr_init(void);
// MoDIS parser skip end
#endif   /*_DRV_HISR_H*/

