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
 *    icusb_iccd_adap.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements host iccd adaptaion layer (file system API)
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#include "drv_comm.h"
//#include "kal_release.h"
#include "kal_public_api.h"
//MSBB remove #include "app_buff_alloc.h"
#include "init.h"
#include "cache_sw.h"
#include "icusb_debug_tool.h"
#include "usb_trc.h"
#include "usb_comm.h"
#include "usb.h"
#include "usbd.h"
#include "gpt_sw.h"
#include "icusb_iccd_drv.h"
#include "icusb_iccd_adap.h"
#include "dcl.h"



#ifdef __IC_USB_ENABLE__

#ifdef __IC_USB_ICCD_SUPPORT__

/************************************************************
	Interface with SIM Driver
*************************************************************/
USB_ICCD_STATE ICUSB_ICCD_POWER_ON(kal_uint8 iccd_index)
{
	USB_HOST_ICCD_RESULT 	command_result;
//	USB_HOST_ICCD_CMD_STATE  apdu_status;
	USB_HOST_ICCD_DEV_STATE		SIMCard_state;
	USB_ICCD_STATE			return_value = ATR_RESPONSE_FAIL;
	kal_uint16   temp_length = ICCD_ATR_REQ_LENGTH;
	SGPT_CTRL_START_T start;
//	kal_uint16 delay_time;
	kal_uint8		busy_count = 0;
	 
	if(g_UsbHostIccd[iccd_index].mutex_id == 0)
		ASSERT(0);
	
	if(g_UsbHostIccd[iccd_index].config == KAL_FALSE)
			ASSERT(0);

//	DclSGPT_Control((DCL_HANDLE)(g_UsbHostIccd[iccd_index].sleep_timer_handle), SGPT_CMD_STOP, 0);
	USB_GPTI_StopItem(g_UsbHostIccd[iccd_index].sleep_timer_handle);	

//	kal_take_mutex(g_UsbHostIccd[iccd_index].mutex_id);
	ICUSB_Dbg_Trace(IC_USB_ICCD_POWER_ON,  0, 0);

		
	/* This is a block function. It returns when the whole Setup,Data,Status Stage is complete */
	SIMCard_state = USB_Host_ICCD_SLOT_STATUS(iccd_index);
	
	if (SIMCard_state != USB_ICCD_DEVICE_Not_Active)
		ASSERT(0);
	
	command_result = USB_Host_ICCD_POWER_ON(iccd_index);
	
	if(command_result == USB_HOST_ICCD_RESULT_OK)
	{
		while ((USB_Host_ICCD_DATA_BLOCK(iccd_index,&temp_length,g_UsbHostIccd[iccd_index].atr_data) == USB_HOST_ICCD_APDU_POLLING)&&(busy_count < 10))
		{
	//			temp_length = 50;
	//			delay_time = ((g_UsbHostIccd[iccd_index].atr_data[2]<<8) |g_UsbHostIccd[iccd_index].atr_data[1]);
	//			delay_time = ((delay_time *10)/4);
	//			kal_sleep_task(delay_time);					
				busy_count ++;	
		}
		
		if (busy_count == USB_HOST_ICCD_BUSY_COUNT)
		{
			/* start timer to check app status */
//			start.u2Tick = g_UsbHostIccd[iccd_index].sleep_time;					
//   	 		start.pfCallback = USB_Host_ICCD_Sleep_Timeout;			
// 	   		start.vPara = &g_UsbHostIccd[iccd_index];							
//	   		DclSGPT_Control((DCL_HANDLE)(g_UsbHostIccd[iccd_index].sleep_timer_handle), SGPT_CMD_START, (DCL_CTRL_DATA_T*)&start);	
			USB_GPTI_StartItem(g_UsbHostIccd[iccd_index].sleep_timer_handle, g_UsbHostIccd[iccd_index].sleep_time,USB_Host_ICCD_Sleep_Timeout, &g_UsbHostIccd[iccd_index]);
	
//			kal_give_mutex(g_UsbHostIccd[iccd_index].mutex_id);
			return DEVICE_Is_Always_Busy;
		}	

		if (g_UsbHostIccd[iccd_index].atr_data[0] == USB_DATA_bResponse_APDU_DONE) 
		{
				ICUSB_Dbg_Trace(IC_USB_ICCD_POWER_ON,  0, 0);
				drv_trace0(TRACE_FUNC, (kal_uint32)USB_HOST_ICCD_POWER_ON_OK);
				g_UsbHostIccd[iccd_index].atr_length = g_UsbHostIccd[iccd_index].rx_real_length;
				return_value = DEVICE_Is_Ready;
		}
		else 
		{	
				return_value = ATR_RESPONSE_FAIL;
		}								
	}
	else if (command_result == USB_HOST_ICCD_RESULT_STALL)  
	{
		//Stall case :  1.illegal parameter on Setup stage 2 Target is not in initial state
		ASSERT(0); //check Device Status at the beginning of this API			
	}
	else
		ASSERT(0);

	ICUSB_Dbg_Trace(IC_USB_ICCD_POWER_ON,  g_UsbHostIccd[iccd_index].atr_data[0], 1);				

	/* start timer to check app status */
//		start.u2Tick = g_UsbHostIccd[iccd_index].sleep_time;					
//   		start.pfCallback = USB_Host_ICCD_Sleep_Timeout;			
// 		start.vPara = &g_UsbHostIccd[iccd_index];							
// 		DclSGPT_Control((DCL_HANDLE)(g_UsbHostIccd[iccd_index].sleep_timer_handle), SGPT_CMD_START, (DCL_CTRL_DATA_T*)&start);	
	USB_GPTI_StartItem(g_UsbHostIccd[iccd_index].sleep_timer_handle, g_UsbHostIccd[iccd_index].sleep_time,USB_Host_ICCD_Sleep_Timeout, &g_UsbHostIccd[iccd_index]);
//	kal_give_mutex(g_UsbHostIccd[iccd_index].mutex_id);
	return	return_value;	


/*	
	SIMCard_state = USB_Host_ICCD_SLOT_STATUS(iccd_index);
		
	if ((SIMCard_state == USB_ICCD_DEVICE_Cannot_Response)||(SIMCard_state == USB_ICCD_DEVICE_HW_ERROR))
	{
			ICUSB_Dbg_Trace(IC_USB_ICCD_ERROR,  0, 0);
			drv_trace0(TRACE_FUNC, (kal_uint32)USB_HOST_ICCD_POWER_ON_Fail);
			GPTI_StartItem(g_UsbHostIccd[iccd_index].sleep_timer_handle, g_UsbHostIccd[iccd_index].sleep_time,USB_Host_ICCD_Sleep_Timeout, &g_UsbHostIccd[iccd_index]);

			kal_give_mutex(g_UsbHostIccd[iccd_index].mutex_id);
		
			return DEVICE_HW_FAIL;
	}	
	else
		ASSERT(0);
*/	
}


USB_ICCD_STATE ICUSB_ICCD_POWER_RESET(kal_uint8 iccd_index)
{
	USB_HOST_ICCD_RESULT command_result;
//	USB_HOST_ICCD_CMD_STATE  apdu_status;	
	USB_HOST_ICCD_DEV_STATE		SIMCard_state;	
	kal_uint16   	temp_length = ICCD_ATR_REQ_LENGTH;
	USB_ICCD_STATE  return_value = ATR_RESPONSE_FAIL;
//	kal_uint32 delay_time;
	kal_uint8		busy_count = 0;
	SGPT_CTRL_START_T start;
		
//	USB_ICCD_STATE status;

	if(g_UsbHostIccd[iccd_index].mutex_id == 0)
		ASSERT(0);
	
	if(g_UsbHostIccd[iccd_index].config == KAL_FALSE)
	{
			ASSERT(0);
	}

//	DclSGPT_Control((DCL_HANDLE)(g_UsbHostIccd[iccd_index].sleep_timer_handle), SGPT_CMD_STOP, 0);
	USB_GPTI_StopItem(g_UsbHostIccd[iccd_index].sleep_timer_handle);	
	
//	kal_take_mutex(g_UsbHostIccd[iccd_index].mutex_id);
	ICUSB_Dbg_Trace(IC_USB_ICCD_POWER_OFF,  0, 0);
		
	SIMCard_state = USB_Host_ICCD_SLOT_STATUS(iccd_index);

//	if (SIMCard_state != USB_ICCD_DEVICE_Active)
//		ASSERT(0);
			
	/* This is a block function. It returns when the whole Setup,Data,Status Stage is complete */
	command_result = USB_Host_ICCD_POWER_OFF(iccd_index);
	
	if(command_result == USB_HOST_ICCD_RESULT_OK)
	{
		SIMCard_state = USB_Host_ICCD_SLOT_STATUS(iccd_index);
		
		if ((SIMCard_state == USB_ICCD_DEVICE_Cannot_Response)||(SIMCard_state == USB_ICCD_DEVICE_HW_ERROR))
		{
			ICUSB_Dbg_Trace(IC_USB_ICCD_ERROR,  0, 0);
				
			drv_trace0(TRACE_FUNC, (kal_uint32)USB_HOST_ICCD_POWER_ON_Fail);

//			start.u2Tick = g_UsbHostIccd[iccd_index].sleep_time;					
//   	 		start.pfCallback = USB_Host_ICCD_Sleep_Timeout;			
// 	   		start.vPara = &g_UsbHostIccd[iccd_index];							
// 	   		DclSGPT_Control((DCL_HANDLE)(g_UsbHostIccd[iccd_index].sleep_timer_handle), SGPT_CMD_START, (DCL_CTRL_DATA_T*)&start);	
    
			USB_GPTI_StartItem(g_UsbHostIccd[iccd_index].sleep_timer_handle, g_UsbHostIccd[iccd_index].sleep_time,USB_Host_ICCD_Sleep_Timeout, &g_UsbHostIccd[iccd_index]);
				
	//		kal_give_mutex(g_UsbHostIccd[iccd_index].mutex_id);		
				
			 return DEVICE_HW_FAIL;
		}
		else if (SIMCard_state == USB_ICCD_DEVICE_Not_Active)
		{
				ICUSB_Dbg_Trace(IC_USB_ICCD_POWER_OFF,  0, 1);
				drv_trace0(TRACE_FUNC, (kal_uint32)USB_HOST_ICCD_POWER_OFF_OK);
		}
		else
			ASSERT(0);	
									
	}
	else if (command_result == USB_HOST_ICCD_RESULT_STALL)  
	{
		//Stall case :  1.illegal parameter on Setup stage 2 Target is not in initial state
			ASSERT(0); //check Device Status at the beginning of this API
	}
	else
		ASSERT(0);
		
  //Re-Power On
	ICUSB_Dbg_Trace(IC_USB_ICCD_POWER_OFF,  0, 2);
			
	command_result = USB_Host_ICCD_POWER_ON(iccd_index);
		
	if(command_result == USB_HOST_ICCD_RESULT_OK)
	{
		while ((USB_Host_ICCD_DATA_BLOCK(iccd_index,&temp_length,g_UsbHostIccd[iccd_index].atr_data) == USB_HOST_ICCD_APDU_POLLING)&&(busy_count < 10))
		{
//				temp_length = 50;
//				delay_time = ((g_UsbHostIccd[iccd_index].atr_data[2]<<8) |g_UsbHostIccd[iccd_index].atr_data[1]);
//				delay_time = ((delay_time *10)/4);
//				kal_sleep_task(delay_time);					
				busy_count ++;	
		}
		
		if (busy_count == USB_HOST_ICCD_BUSY_COUNT)
		{	
			ICUSB_Dbg_Trace(IC_USB_ICCD_POWER_OFF,  0, g_UsbHostIccd[iccd_index].atr_data[1]);

			/* start timer to check app status */
//			start.u2Tick = g_UsbHostIccd[iccd_index].sleep_time;					
//   	 		start.pfCallback = USB_Host_ICCD_Sleep_Timeout;			
// 	   		start.vPara = &g_UsbHostIccd[iccd_index];							
// 	   		DclSGPT_Control((DCL_HANDLE)(g_UsbHostIccd[iccd_index].sleep_timer_handle), SGPT_CMD_START, (DCL_CTRL_DATA_T*)&start);	
 	   	
			USB_GPTI_StartItem(g_UsbHostIccd[iccd_index].sleep_timer_handle, g_UsbHostIccd[iccd_index].sleep_time,USB_Host_ICCD_Sleep_Timeout, &g_UsbHostIccd[iccd_index]);

//			kal_give_mutex(g_UsbHostIccd[iccd_index].mutex_id);
			return DEVICE_Is_Always_Busy;
		}	
		
		if (g_UsbHostIccd[iccd_index].atr_data[0] == USB_DATA_bResponse_APDU_DONE) 
		{
				ICUSB_Dbg_Trace(IC_USB_ICCD_POWER_ON,  0, 0);
				drv_trace0(TRACE_FUNC, (kal_uint32)USB_HOST_ICCD_POWER_ON_OK);
				g_UsbHostIccd[iccd_index].atr_length = g_UsbHostIccd[iccd_index].rx_real_length;
				return_value = DEVICE_Is_Ready;
		}
		else
		{
				return_value = ATR_RESPONSE_FAIL;
		}
	}
	else if (command_result == USB_HOST_ICCD_RESULT_STALL)  
	{
		//Stall case :  1.illegal parameter on Setup stage 2 Target is not in initial state
			ASSERT(0); //check Device Status at the beginning of this API
	}
	else
		ASSERT(0);

	/* start timer to check app status */
//		start.u2Tick = g_UsbHostIccd[iccd_index].sleep_time;					
//   		start.pfCallback = USB_Host_ICCD_Sleep_Timeout;			
// 	 	 start.vPara = &g_UsbHostIccd[iccd_index];							
// 	 	 DclSGPT_Control((DCL_HANDLE)(g_UsbHostIccd[iccd_index].sleep_timer_handle), SGPT_CMD_START, (DCL_CTRL_DATA_T*)&start);	
	USB_GPTI_StartItem(g_UsbHostIccd[iccd_index].sleep_timer_handle, g_UsbHostIccd[iccd_index].sleep_time,USB_Host_ICCD_Sleep_Timeout, &g_UsbHostIccd[iccd_index]);			
//	kal_give_mutex(g_UsbHostIccd[iccd_index].mutex_id);
	
	return return_value;

}



USB_ICCD_STATE ICUSB_ICCD_DATA_Transfer(kal_uint8 iccd_index,kal_uint16 tx_length,kal_uint8 *tx_buffer, kal_uint8 *rx_buffer, kal_uint16 *rx_size)
{
	USB_HOST_ICCD_RESULT command_result;
//	USB_HOST_ICCD_CMD_STATE  apdu_status;	
	USB_HOST_ICCD_DEV_STATE		SIMCard_state;	
//	kal_uint32 	delay_time;
	USB_ICCD_STATE  return_value = APDU_FAIL;
	kal_uint8		busy_count = 0;
	SGPT_CTRL_START_T start;

	if(g_UsbHostIccd[iccd_index].mutex_id == 0)
	{
		ASSERT(0);
	}
	
	if(g_UsbHostIccd[iccd_index].config == KAL_FALSE)
	{
		ASSERT(0);
	}

//	DclSGPT_Control((DCL_HANDLE)(g_UsbHostIccd[iccd_index].sleep_timer_handle), SGPT_CMD_STOP, 0);
	USB_GPTI_StopItem(g_UsbHostIccd[iccd_index].sleep_timer_handle);
	
//	kal_take_mutex(g_UsbHostIccd[iccd_index].mutex_id);
	ICUSB_Dbg_Trace(IC_USB_ICCD_DATA_TRANSFER,  0, 0);
	
	ICUSB_Dbg_Trace(IC_USB_ICCD_DATA_TRANSFER,  1, tx_length);		

	/* This is a block function. It returns when the whole Setup,Data,Status Stage is complete */
	command_result = USB_Host_ICCD_XFR_BLOCK(iccd_index,tx_length,tx_buffer);

// QQ Test : NAK Timeout --> re-try
//	if (command_result == USB_HOST_ICCD_RESULT_TIMEOUT)
//	{
//		SIMCard_state = USB_Host_ICCD_SLOT_STATUS(iccd_index);
//		if (SIMCard_state == USB_ICCD_DEVICE_Active)
//			command_result = USB_Host_ICCD_XFR_BLOCK(iccd_index,tx_length,tx_buffer);
//	}
		
	
	if(command_result == USB_HOST_ICCD_RESULT_OK)
	{
		while ((USB_Host_ICCD_DATA_BLOCK(iccd_index,rx_size,rx_buffer) == USB_HOST_ICCD_APDU_POLLING)&&(busy_count < 10))
		{
			SIMCard_state = USB_Host_ICCD_SLOT_STATUS(iccd_index);
			
			if (SIMCard_state == USB_ICCD_DEVICE_Active)
			{
				busy_count ++;	
			}
			else
				ASSERT(0);				
		}
	
		if (busy_count == USB_HOST_ICCD_BUSY_COUNT)
		{	
			ICUSB_Dbg_Trace(IC_USB_ICCD_DATA_TRANSFER,  2, busy_count);				

			/* start timer to check app status */
//			start.u2Tick = g_UsbHostIccd[iccd_index].sleep_time;					
//   	 		start.pfCallback = USB_Host_ICCD_Sleep_Timeout;			
// 	   		start.vPara = &g_UsbHostIccd[iccd_index];							
// 	   		DclSGPT_Control((DCL_HANDLE)(g_UsbHostIccd[iccd_index].sleep_timer_handle), SGPT_CMD_START, (DCL_CTRL_DATA_T*)&start);	
			USB_GPTI_StartItem(g_UsbHostIccd[iccd_index].sleep_timer_handle, g_UsbHostIccd[iccd_index].sleep_time,USB_Host_ICCD_Sleep_Timeout, &g_UsbHostIccd[iccd_index]);
//			kal_give_mutex(g_UsbHostIccd[iccd_index].mutex_id);
			return DEVICE_Is_Always_Busy;
		}	
		
		if (g_UsbHostIccd[iccd_index].apdu_response == USB_HOST_ICCD_CMD_FAIL)
		{
			if((g_UsbHostIccd[iccd_index].dev_state == USB_ICCD_DEVICE_Cannot_Response)||(g_UsbHostIccd[iccd_index].dev_state == USB_ICCD_DEVICE_HW_ERROR))
			{
				ICUSB_Dbg_Trace(IC_USB_ICCD_ERROR,  0, 0);
				drv_trace0(TRACE_FUNC, (kal_uint32)USB_HOST_ICCD_POWER_ON_Fail);		
				return_value = DEVICE_HW_FAIL;
			}
			else
			{
				return_value = APDU_FAIL;
			}
		}
		else if (g_UsbHostIccd[iccd_index].apdu_response == USB_HOST_ICCD_ERROR)
		{    // QQ Test : NAK Timeout  --> re-try command 
//			SIMCard_state = USB_Host_ICCD_SLOT_STATUS(iccd_index);
//			if (SIMCard_state == USB_ICCD_DEVICE_Active)
//			{
//				USB_Host_ICCD_DATA_BLOCK(iccd_index,rx_size,rx_buffer);
	//			if (g_UsbHostIccd[iccd_index].apdu_response == USB_HOST_ICCD_APDU_DONE)
	//				return_value = APDU_SUCCESS; 
	//			else
					return_value = APDU_FAIL;
	//		}
		}
		else
		{	
			return_value = APDU_SUCCESS; //Blue, 6/1 : added for IT, it is suggested to add one more state, APDU sucess
		}
	}
	else if (command_result == USB_HOST_ICCD_RESULT_STALL)  
	{
		//Stall case :  1.illegal parameter on Setup stage 2 Target is not in initial state
		ASSERT(0); //check Device Status at the beginning of this API
	}
	else
		ASSERT(0);


	ICUSB_Dbg_Trace(IC_USB_ICCD_DATA_TRANSFER,  3, return_value);	
	ICUSB_Dbg_Trace(IC_USB_ICCD_DATA_TRANSFER,  3, g_UsbHostIccd[iccd_index].dev_state);	

	/* start timer to check app status */
//	start.u2Tick = g_UsbHostIccd[iccd_index].sleep_time;					
//  	start.pfCallback = USB_Host_ICCD_Sleep_Timeout;			
// 	start.vPara = &g_UsbHostIccd[iccd_index];							
// 	DclSGPT_Control((DCL_HANDLE)(g_UsbHostIccd[iccd_index].sleep_timer_handle), SGPT_CMD_START, (DCL_CTRL_DATA_T*)&start);	
	USB_GPTI_StartItem(g_UsbHostIccd[iccd_index].sleep_timer_handle, g_UsbHostIccd[iccd_index].sleep_time,USB_Host_ICCD_Sleep_Timeout, &g_UsbHostIccd[iccd_index]);			
//	kal_give_mutex(g_UsbHostIccd[iccd_index].mutex_id);
	
	return return_value;	
}

void ICUSB_ICCD_Init(kal_uint8 iccd_index)
{
	/* Initailize the information, Cannot create Event on HISR */
	
	if(g_UsbHostIccd[iccd_index].event_id == 0)
		g_UsbHostIccd[iccd_index].event_id = kal_create_event_group("USB_ICCD_EVEVT");

	if(g_UsbHostIccd[iccd_index].mutex_id == 0)
		g_UsbHostIccd[iccd_index].mutex_id = kal_create_mutex("USB_ICCD_MUTEX");

	USB_GPTI_GetHandle(&(g_UsbHostIccd[iccd_index].sleep_timer_handle));// DclSGPT_Open(DCL_GPT_CB, 0);

//	if (g_UsbHostIccd[iccd_index].sleep_timer_handle == 0)
//		g_UsbHostIccd[iccd_index].sleep_timer_handle = USB_GPTI_GetHandle();// DclSGPT_Open(DCL_GPT_CB, 0);
//		GPTI_GetHandle(&g_UsbHostIccd[iccd_index].sleep_timer_handle);
}

void ICUSB_ICCD_Parameter_Setting(kal_uint8 iccd_index,USB_HOST_ICCD_PARAMETER parameter, kal_uint16 data)
{
		if (parameter == ICUSB_ICCD_P_DELAY)
		{
			g_UsbHostIccd[iccd_index].sleep_time = data;
		}
		else
		{
			ASSERT(0);
		}
}



void ICUSB_ICCD_Parameter_Querry(kal_uint8 iccd_index, ICUSB_ICCD_INFO *pInfo)
{
#if 0 //Blue, 5/28 : should not use this kind of implementation, or SIM driver will call the function for many times.
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
	pInfo->pATR = g_UsbHostIccd[iccd_index].atr_data + 1; // since there is one byte information of USB
	pInfo->atrLen = g_UsbHostIccd[iccd_index].atr_length-1;

}



kal_bool IC_USB_POWER_ON(kal_uint8 iccd_index,kal_bool blocking)
{
	kal_uint8 index;	
	kal_uint32 event_group;
	

	if(g_UsbHostIccd[iccd_index].start_event_id == 0)
	{
		g_UsbHostIccd[iccd_index].start_event_id = kal_create_event_group("ICUSB_ENUMERATION"); 
	}
	else
	{
		/* Receive all events that may exist after previous detatch */
		kal_retrieve_eg_events(g_UsbHostIccd[iccd_index].start_event_id, EVENT_ICUSB_ENUMERATION_DONE|EVENT_ICUSB_ENUMERATION_FAIL, 
							KAL_OR_CONSUME, &event_group, KAL_NO_SUSPEND);
	}

//	for (index = USB_EXT_IP_NUM; index< USB_IP_NUM; index++)  // only enable ICUSB Drive
	for (index = 0; index< USB_IP_NUM; index++)
		USBD_Init(index);

	ICUSB_Drv_Init();
			
	if (blocking == KAL_TRUE)
	{
		kal_retrieve_eg_events(g_UsbHostIccd[iccd_index].start_event_id, EVENT_ICUSB_ENUMERATION_DONE|EVENT_ICUSB_ENUMERATION_FAIL, 
						KAL_OR_CONSUME, &event_group, KAL_SUSPEND);	
		if (event_group & EVENT_ICUSB_ENUMERATION_FAIL)
			return KAL_FALSE;
		else
			return KAL_TRUE;
	}
	else
	{
		return KAL_TRUE;
	}
}


kal_bool IC_USB_Reset_Card(kal_uint8 iccd_index)
{
	kal_uint32 event_group;
	
// SIM Driver reset level :  1. ICCD Reset   2. USB Reset
	USB_Host_ICCD_Reset_Card(iccd_index);

	kal_retrieve_eg_events(g_UsbHostIccd[iccd_index].start_event_id, EVENT_ICUSB_ENUMERATION_DONE|EVENT_ICUSB_ENUMERATION_FAIL, 
						KAL_OR_CONSUME, &event_group, KAL_SUSPEND);	

	if (event_group & EVENT_ICUSB_ENUMERATION_FAIL)
		return KAL_FALSE;
	else
		return KAL_TRUE;
}

#endif /* __IC_USB_ICCD_SUPPORT__ */

#endif /* __IC_USB_ENABLE__*/
 
