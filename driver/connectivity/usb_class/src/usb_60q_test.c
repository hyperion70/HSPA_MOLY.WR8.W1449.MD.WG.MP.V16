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
 *   usb_60q_test.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements 60Q timing test
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

 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*******************************************************************************
 * Include files
 *******************************************************************************/
#ifdef __USB_COM_PORT_ENABLE__

//#include "kal_release.h"      /* Basic data type */
#include "kal_public_api.h"
//#include "stack_common.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "kal_public_api.h" //#include "stack_ltlcom.h" //MSBB change #include "app_ltlcom.h"       /* Task message communiction */
#include "kal_public_api.h" //#include "kal_public_api.h" //#include "stack_ltlcom.h" //MSBB change #include "tst_ltlcom.h"
#include "syscomp_config.h"
#include "task_config.h"      /* Task creation */
#include "stacklib.h"         /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h"       /* Event scheduler */
#include "stack_timer.h"      /* Stack timer */
#include "stdio.h"
#include "uart_sw.h"
#include "cache_sw.h"
#include "cache_hw.h"

#include "usb.h"
#include "usb_adap.h"
//#include "usb_hcd.h" ///< where include usb_drv.h
#include "dcl.h"
#include "usbacm_drv.h"
#include "usb_custom.h"

#if defined(__RTL_SIMULATION_FOR_60QBIT__)

#include "emi_monitor.h"
#include "ebm_if.h"

/*******************************************************************************
 * Define global data.
 *******************************************************************************/

static EBM_LOG_T usb_ibus_log, usb_dbus_log;


/*******************************************************************************
 * Internal structure definition
 *******************************************************************************/
#undef __L1_STANDALONE__


/*******************************************************************************
 * Function declaration
 *******************************************************************************/


/*******************************************************************************
 * Global vairables
 *******************************************************************************/
//UARTStruct USB2UARTPort;
//UsbAcm_Struct g_UsbACM;
//Usb_Device gUsbDevice;

static USBTRX_MEM_TYPE USB2Uart_MemType;

/*************************************************************************
* FUNCTION
*  XXX
*
* DESCRIPTION
*  This function implements sysdebug entity's create handler.
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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


void usb_irq_disable_duration_test2(void)
{
   /// input parameters
   kal_uint32* addr;
   kal_bool b_check;

   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   kal_uint32 length = 0;
	kal_uint32 savedMask;


	/// initialize variables: addr, b_check, USB2UARTPort[uart_port_usb], g_UsbACM[uart_port_usb]
	kal_uint32 actual_addr;

	addr = &actual_addr;
	b_check = KAL_TRUE;

	USB2UARTPort[uart_port_usb].Tx_Buffer_ISR.Write = 5;
	USB2UARTPort[uart_port_usb].Tx_Buffer_ISR.Read = 4;
	USB2UARTPort[uart_port_usb].Tx_Buffer_ISR.CharBuffer = (kal_uint8 *)0x12345678;

	g_UsbACM_Comm.acm_param = USB_GetCustomFunc()->get_acm_param_func();
//  g_UsbACM[uart_port_usb].acm_param->txisr_ringbuff_size = 4;

	USB2UARTPort[uart_port_usb].Tx_Buffer.Write = 5;
	USB2UARTPort[uart_port_usb].Tx_Buffer.Read = 4;
	USB2UARTPort[uart_port_usb].Tx_Buffer.CharBuffer = (kal_uint8 *)0x12345678;
//   g_UsbACM[uart_port_usb].acm_param->tx_ringbuff_size = 4;

do
{
   /// profiling starts ---------------------------------------------------------------------------

//   MTKL1CACHE_InvalidAllCacheLines();
//   EM_BEGIN_LOG_ALL();

    EBM_INIT();

    EBM_START();

	savedMask = SaveAndSetIRQMask();
	if (USB2UARTPort[uart_port_usb].Tx_Buffer_ISR.Write != USB2UARTPort[uart_port_usb].Tx_Buffer_ISR.Read)
	{
		/* used for callback function to know sent source */
		USB2Uart_MemType = USBTRX_MEM_ISR;
		*addr = (kal_uint32)USB2UARTPort[uart_port_usb].Tx_Buffer_ISR.CharBuffer+USB2UARTPort[uart_port_usb].Tx_Buffer_ISR.Read;

		if (USB2UARTPort[uart_port_usb].Tx_Buffer_ISR.Write >= USB2UARTPort[uart_port_usb].Tx_Buffer_ISR.Read)
		{
			length = USB2UARTPort[uart_port_usb].Tx_Buffer_ISR.Write - USB2UARTPort[uart_port_usb].Tx_Buffer_ISR.Read;

			if(b_check == KAL_TRUE)
			{
				if(length <= (g_UsbACM_Comm.acm_param->txisr_ringbuff_size/2))
				{
					length = 0;
					g_UsbACM[uart_port_usb].ring_buffer_timer_counting = KAL_TRUE;
				}
			}
		}
		else
		{
			/* ISR TX buffer must have data to send out */
			length = USB2UARTPort[uart_port_usb].Tx_Buffer_ISR.Length - USB2UARTPort[uart_port_usb].Tx_Buffer_ISR.Read;
		}
	}

	/* check if TX buffer has enough data to send out */
	if((USB2UARTPort[uart_port_usb].Tx_Buffer.Write != USB2UARTPort[uart_port_usb].Tx_Buffer.Read) && (length == 0))
	{
		g_UsbACM[uart_port_usb].ring_buffer_timer_counting = KAL_FALSE;
		/* used for callback function to know sent source */
		USB2Uart_MemType = USBTRX_MEM_TASK;
		*addr = (kal_uint32)USB2UARTPort[uart_port_usb].Tx_Buffer.CharBuffer+USB2UARTPort[uart_port_usb].Tx_Buffer.Read;

		if(USB2UARTPort[uart_port_usb].Tx_Buffer.Write >= USB2UARTPort[uart_port_usb].Tx_Buffer.Read)
		{
			length = USB2UARTPort[uart_port_usb].Tx_Buffer.Write - USB2UARTPort[uart_port_usb].Tx_Buffer.Read;
#ifndef __L1_STANDALONE__
/// will enter
			if(b_check == KAL_TRUE)
			{
				if(length <= (g_UsbACM_Comm.acm_param->tx_ringbuff_size/2))
				{
					length = 0;
					g_UsbACM[uart_port_usb].ring_buffer_timer_counting = KAL_TRUE;
				}
			}
#endif
		}
		else
		{
			length = USB2UARTPort[uart_port_usb].Tx_Buffer.Length - USB2UARTPort[uart_port_usb].Tx_Buffer.Read;
		}
	}
	RestoreIRQMask(savedMask);

    EBM_PAUSE();
    EBM_GET_MCU_IBUS_LOG(&usb_ibus_log);
    EBM_GET_MCU_DBUS_LOG(&usb_dbus_log);

    EBM_STOP();

//   EM_END_LOG_ALL();
//   EM_GET_LOG(&em_test_log[log_idx]);
//   INC_LOG_IDX(log_idx);

   /// profiling stops ------------------------------------------------------------------------
} while(0);

}

#endif  /* __RTL_SIMULATION_FOR_60QBIT__ */
#endif  /*__USB_COM_PORT_ENABLE__*/


