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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   usbacm_echo.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements USB DVT or Throughput test
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

 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __USB_COM_PORT_ENABLE__

//#include "stack_common.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "drv_comm.h"
#include "syscomp_config.h"
#include "usb_comm.h"
#include "usb_task.h"
//#include "usb_drv.h"
#include "usb_adap.h"
#include "usb.h"
#include "usb_resource.h"
#include "usbacm_drv.h"
#include "usbacm_adap.h"
#include "usb_custom.h"
#include "usb_debug_tool.h"
#include "usb_trc.h"


#ifdef __USB_STRESS_TEST__


/* global variables */

#pragma arm section zidata = "NONCACHEDZI",  rwdata = "NONCACHEDRW"
__align(4) kal_uint8  USB_ECHO_Test_Buffer[1024*8];
#pragma arm section zidata, rwdata


static kal_uint32 usb_echo_count;


static void USB_ECHO_EP_SETUP(void);
static void USB_ECHO_Build_RX(kal_uint32 length);
static void USB_ECHO_Build_TX(kal_uint32 length);
static void USB_ECHO_RX_DMA_Callback(void);
static void USB_ECHO_TX_DMA_Callback(void);

//============================================================//
/*  USB ECHO Test
1. PC send 1 B
2. Target DMA RX -> RX Callback
3. DMA TX   -> TX Callback
4. PC Receive Data
5. PC Compare Data
7. PC Send data
*/

void USB_ECHO_TEST(void)
{
	usb_echo_count = 1;
//	USB_EPFIFORead(g_UsbACM.rxpipe->byEP, usb_echo_count, (kal_uint32)USB_ECHO_Test_Buffer);

	if((USB_Get_Device_Type() == USB_CDC_ACM)&&(USB_Get_Device_State() == DEVSTATE_CONFIG))
	{
	 	USB_ECHO_EP_SETUP();
	 	USB_ECHO_Build_RX(usb_echo_count);
	}
}


static void USB_ECHO_EP_SETUP(void)
{
	//DMA TX ,DMA RX//
	USB_TxEPEn(g_UsbACM[0].txpipe->byEP, USB_ENDPT_BULK, KAL_TRUE, KAL_TRUE, KAL_FALSE);
	USB_RxEPEn(g_UsbACM[0].rxpipe->byEP, USB_ENDPT_BULK, KAL_TRUE, KAL_TRUE, KAL_FALSE);
}


static void USB_ECHO_Build_RX(kal_uint32 length)
{
	USB_Stop_DMA_Channel(g_UsbACM[0].rxpipe->byEP, USB_EP_RX_DIR);
	USB_Dbg_Trace(DBG_USB_ECHO_Build_RX, length, 0);
	USB_DMA_Setup(g_UsbACM[0].rxpipe->byEP,USB_EP_RX_DIR,USB_ENDPT_BULK,(kal_uint32)USB_ECHO_Test_Buffer,length, USB_ECHO_RX_DMA_Callback, KAL_TRUE, KAL_TRUE, USB_DMA1_TYPE);
}


static void USB_ECHO_Build_TX(kal_uint32 length)
{
	USB_Stop_DMA_Channel(g_UsbACM[0].txpipe->byEP, USB_EP_TX_DIR);
	USB_Dbg_Trace(DBG_USB_ECHO_Build_TX, length, 0);
	USB_DMA_Setup(g_UsbACM[0].txpipe->byEP,USB_EP_TX_DIR,USB_ENDPT_BULK,(kal_uint32)USB_ECHO_Test_Buffer,length, USB_ECHO_TX_DMA_Callback, KAL_TRUE, KAL_TRUE, USB_DMA1_TYPE);
}


static void USB_ECHO_RX_DMA_Callback(void)
{
	USB_Dbg_Trace(DBG_USB_ECHO_RX_DMA_Callback, 0, 0);

#if (defined(__USB_ECHO_TEST__)||defined(__USB_TX_TEST__))
	USB_ECHO_Build_TX(usb_echo_count);
#endif

#if defined(__USB_RX_TEST__)
	usb_echo_count = 1024*8;
	USB_ECHO_Build_RX(usb_echo_count);
#endif

}

static void USB_ECHO_TX_DMA_Callback(void)
{
#if defined(__USB_TX_TEST__)
	usb_echo_count = 1024*8;
	USB_Dbg_Trace(DBG_USB_ECHO_TX_DMA_Callback, 0, 0);
	USB_ECHO_Build_TX(usb_echo_count);
#endif

#if defined(__USB_ECHO_TEST__)

	usb_echo_count ++;

	if (usb_echo_count %8 == 0)
		usb_echo_count ++;

	if (usb_echo_count >  1024*8)
		usb_echo_count = 1;

	USB_Dbg_Trace(DBG_USB_ECHO_TX_DMA_Callback, 0, 0);
	USB_ECHO_Build_RX(usb_echo_count);
#endif
}

#endif
#endif /*__USB_COM_PORT_ENABLE__*/


