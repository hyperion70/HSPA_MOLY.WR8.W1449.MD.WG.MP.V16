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
 *    usb_host_ms_state.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements host mass storage class state machine
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

#ifdef __OTG_ENABLE__

#include "drv_comm.h"
//#include "stack_common.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "kal_public_api.h" //#include "stack_ltlcom.h" //MSBB change #include "app_ltlcom.h"       /* Task message communiction */
#include "intrCtrl.h"
#include "drvsignals.h"
//#include "usb_drv.h"
#include "usb_hcd.h"
#include "otg_if.h"
//#include "otg_drv.h"
//#include "usb_hcd_pri.h"
#include "otg.h"
#include "dcl.h"
//#include "usbms_state.h"
#include "usb_host_ms_drv.h"
#include "usb_host_ms_if.h"
//#include "usb_host_ms_state.h"
#include "usb_debug_tool.h"
#include "usb_trc.h"
//#include "kal_non_specific_general_types.h"
#include "kal_trace.h"
//#include "kal_release.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "kal_public_api.h" //#include "stack_ltlcom.h"
#include "kal_general_types.h"
#include "kal_public_api.h"

static void USB_Host_Ms_State_Timeout(void *parameter);
static void USB_Host_MS_Query_Media(kal_uint8 lun);
static void USB_Host_MS_Check_Media(kal_uint8 lun);
static kal_bool USB_Host_Ms_Error_Check(kal_uint8 ms_index);
static void USB_Host_Ms_Error_Handler(kal_uint8 ms_index);
static kal_bool USB_Host_Ms_Comp_Get_LUN(kal_uint8 ms_index);
static kal_bool USB_Host_Ms_Query_All_Media(kal_uint8 ms_index);
static kal_bool USB_Host_Ms_Check_All_Media(kal_uint8 ms_index);

extern const kal_uint8  USB_IRQ_MAP[USB_IP_NUM];
/************************************************************
	ms class state functions. Matintain the state of each LUN
*************************************************************/

/* Query media info for lun parameter */
/* This query function should be called when first detect the lun plug in */
static void USB_Host_MS_Query_Media(kal_uint8 lun)
{
	USB_HOST_MS_RESULT result;
	kal_uint8  ms_index = USB_MS_IP_Query(lun);

	USB_Dbg_Trace(USB_HOST_MS_QUERY_MEDIA, lun, 0);
	g_UsbHostMs[ms_index].dev_state = USB_HOST_MS_DEV_STATE_READY;

	/* Send INQUIRY request to device */
	/* Inquiry cmd's CSW is fail but request we get "NOT ready", then we still see result as OK */
	result = USB_Host_Ms_Inquiry(lun);

	if(result != USB_HOST_MS_RESULT_OK)
	{
		/* result not OK means CBW, DATA, CSW transfer is error after its internal error handling */
		/* Or request sense but fail */
		if(result == USB_HOST_MS_RESULT_TIMEOUT)
			g_UsbHostMs[ms_index].dev_state = USB_HOST_MS_DEV_STATE_FATAL_ERROR;
		else
			g_UsbHostMs[ms_index].dev_state = USB_HOST_MS_DEV_STATE_ERROR;
		return;
	}

	/* Send READ FORMAT CAPACITY request to device */
/*    some device always return STALL in this command
	result = USB_Host_Ms_Read_Format_Capacity(lun);

	if(result != USB_HOST_MS_RESULT_OK)
	{
		// result not OK means CBW, DATA, CSW transfer is error after its internal error handling 
		if(result == USB_HOST_MS_RESULT_TIMEOUT)
			g_UsbHostMs[ms_index].dev_state = USB_HOST_MS_DEV_STATE_FATAL_ERROR;
		else
			g_UsbHostMs[ms_index].dev_state = USB_HOST_MS_DEV_STATE_ERROR;
		return;
	}
*/

	/* Send READ CAPACITY request to device */
	result = USB_Host_Ms_Read_Capacity(lun);

	if(result != USB_HOST_MS_RESULT_OK)
	{
		/* result not OK means CBW, DATA, CSW transfer is error after its internal error handling */
		if(result == USB_HOST_MS_RESULT_TIMEOUT)
			g_UsbHostMs[ms_index].dev_state = USB_HOST_MS_DEV_STATE_FATAL_ERROR;
		else
			g_UsbHostMs[ms_index].dev_state = USB_HOST_MS_DEV_STATE_ERROR;
		return;
	}
}


/* Check media info for lun parameter */
/* This check function should be called periodically when slot is still attched */
static void USB_Host_MS_Check_Media(kal_uint8 lun)
{
	USB_HOST_MS_RESULT result;
	kal_bool b_state_change = KAL_FALSE;
	kal_uint8  ms_index = USB_MS_IP_Query(lun);
	USB_HOST_MS_MEDIA_STATE media_state = g_UsbHostMs[ms_index].media_info[lun].state;


	USB_Dbg_Trace(USB_HOST_MS_CHECK_MEDIA, lun, 0);
	g_UsbHostMs[ms_index].dev_state = USB_HOST_MS_DEV_STATE_READY;

	/* Send TEST UNIT READY request to device */
	result = USB_Host_Ms_Test_Unit_Ready(lun);

	if(result != USB_HOST_MS_RESULT_OK)
	{
		/* result not OK means CBW, DATA, CSW transfer is error after its internal error handling */
		if(result == USB_HOST_MS_RESULT_TIMEOUT)
			g_UsbHostMs[ms_index].dev_state = USB_HOST_MS_DEV_STATE_FATAL_ERROR;
		else
			g_UsbHostMs[ms_index].dev_state = USB_HOST_MS_DEV_STATE_ERROR;
		return;
	}

	/* state may change from READY->CHANGED at this step, and CHANGED->READY at next step  */
	if(media_state != g_UsbHostMs[ms_index].media_info[lun].state)
		b_state_change = KAL_TRUE;

	if(g_UsbHostMs[ms_index].media_info[lun].state == USB_HOST_MS_MEDIA_STATE_CHANGED)
	{
		/* If card is plugged in to card reader, the previous state would be state changed, so query state again */
		/* If this request finds media state cahnge to READY, then capacity can be queried in the following step directly */
		result = USB_Host_Ms_Test_Unit_Ready(lun);

		if(result != USB_HOST_MS_RESULT_OK)
		{
			/* result not OK means CBW, DATA, CSW transfer is error after its internal error handling */
			if(result == USB_HOST_MS_RESULT_TIMEOUT)
				g_UsbHostMs[ms_index].dev_state = USB_HOST_MS_DEV_STATE_FATAL_ERROR;
			else
				g_UsbHostMs[ms_index].dev_state = USB_HOST_MS_DEV_STATE_ERROR;
			return;
		}
	}

	if(media_state != g_UsbHostMs[ms_index].media_info[lun].state)
		b_state_change = KAL_TRUE;

	if((b_state_change == KAL_TRUE)&&(g_UsbHostMs[ms_index].media_info[lun].state == USB_HOST_MS_MEDIA_STATE_READY))
	{
		/* state change from NOT_READY to READY*/
		/* Send READ CAPACITY request to device */
		result = USB_Host_Ms_Read_Capacity(lun);

		if(result != USB_HOST_MS_RESULT_OK)
		{
			/* result not OK means CBW, DATA, CSW transfer is error after its internal error handling */
			if(result != USB_HOST_MS_RESULT_FORMAT_ERROR)
			{
				/* FORMAT_ERROR means that we receive a large size because card reader is not plugged in card yet */
				if(result == USB_HOST_MS_RESULT_TIMEOUT)
					g_UsbHostMs[ms_index].dev_state = USB_HOST_MS_DEV_STATE_FATAL_ERROR;
				else
					g_UsbHostMs[ms_index].dev_state = USB_HOST_MS_DEV_STATE_ERROR;
			}
			return;
		}

		/* Send MODE SENSE6 request to device. Query whether the device is write protected or not */
		result = USB_Host_Ms_Mode_Sense6(lun);

		if(result != USB_HOST_MS_RESULT_OK)
		{
			/* result not OK means CBW, DATA, CSW transfer is error after its internal error handling */
			if(result == USB_HOST_MS_RESULT_TIMEOUT)
				g_UsbHostMs[ms_index].dev_state = USB_HOST_MS_DEV_STATE_FATAL_ERROR;
			else
				g_UsbHostMs[ms_index].dev_state = USB_HOST_MS_DEV_STATE_ERROR;
			return;
		}

		if(g_UsbHostMs[ms_index].media_info[lun].state == USB_HOST_MS_MEDIA_STATE_ERROR)
		{
			/* Send READ CAPACITY request to device */
			result = USB_Host_Ms_Read_Capacity(lun);

			if(result != USB_HOST_MS_RESULT_OK)
			{
				/* result not OK means CBW, DATA, CSW transfer is error after its internal error handling */
				if(result != USB_HOST_MS_RESULT_FORMAT_ERROR)
				{
					if(result == USB_HOST_MS_RESULT_TIMEOUT)
						g_UsbHostMs[ms_index].dev_state = USB_HOST_MS_DEV_STATE_FATAL_ERROR;
					else
						g_UsbHostMs[ms_index].dev_state = USB_HOST_MS_DEV_STATE_ERROR;
				}
				return;
			}

			/* Try all mode again */
			result = USB_Host_Ms_Mode_Sense6_All_Mode(lun);

			if(result != USB_HOST_MS_RESULT_OK)
			{
				/* result not OK means CBW, DATA, CSW transfer is error after its internal error handling */
				if(result == USB_HOST_MS_RESULT_TIMEOUT)
					g_UsbHostMs[ms_index].dev_state = USB_HOST_MS_DEV_STATE_FATAL_ERROR;
				else
					g_UsbHostMs[ms_index].dev_state = USB_HOST_MS_DEV_STATE_ERROR;
				return;
			}
		}

		if(g_UsbHostMs[ms_index].media_info[lun].state == USB_HOST_MS_MEDIA_STATE_ERROR)
		{
			/* Try mode sense 10 again */
			result = USB_Host_Ms_Mode_Sense10_All_Mode(lun);

			if(result != USB_HOST_MS_RESULT_OK)
			{
				/* result not OK means CBW, DATA, CSW transfer is error after its internal error handling */
				if(result == USB_HOST_MS_RESULT_TIMEOUT)
					g_UsbHostMs[ms_index].dev_state = USB_HOST_MS_DEV_STATE_FATAL_ERROR;
				else
					g_UsbHostMs[ms_index].dev_state = USB_HOST_MS_DEV_STATE_ERROR;
				return;
			}
		}
	}
}


/* Return true means error happens*/
/* In this function, try to issue ms class specific reset command and see if error count exceed limit */
static kal_bool USB_Host_Ms_Error_Check(kal_uint8 ms_index)
{
/*	
	while(g_UsbHostMs[ms_index].dev_error_count < USB_HOST_MS_ERROR_COUNT)
	{
		USB_Dbg_Trace(USB_HOST_MS_RESET, 0, 0);

		// At most reset 3 times
		USB_Host_Ms_Reset(ms_index);

		// Clear TX and RX endpoints' data01 
		USBD_Clear_Data01(g_UsbHostMs[ms_index].common_info,g_UsbHostMs[ms_index].ep_tx_info);
		USBD_Clear_Data01(g_UsbHostMs[ms_index].common_info,g_UsbHostMs[ms_index].ep_rx_info);

		if(g_UsbHostMs[ms_index].dev_state == USB_HOST_MS_DEV_STATE_ERROR)
			g_UsbHostMs[ms_index].dev_error_count++;
		else
			break;
	}
*/
//	if((g_UsbHostMs[ms_index].dev_error_count >= USB_HOST_MS_ERROR_COUNT)||(g_UsbHostMs[ms_index].dev_attatch == KAL_FALSE))
		return KAL_TRUE;
//	else
//		return KAL_FALSE;
}


/* Serious error happens and it can not be recovered from error handling mechanism in ms class */
/* Stop the MS action and turn off OTG  power */
/* USB task run */
static void USB_Host_Ms_Error_Handler(kal_uint8 ms_index)
{
	OTG_DRV_CTRL_GET_PLUG_TYPE_T  dcl_data;
	OTG_PLUG_TYPE plug_type;


	//DclSGPT_Control((DCL_HANDLE)(g_UsbHostMs[ms_index].gpt_handle), SGPT_CMD_STOP, 0);	
	USB_GPTI_StopItem(g_UsbHostMs[ms_index].gpt_handle);
	//DclSGPT_Control((DCL_HANDLE)(g_UsbHostMs[ms_index].sleep_timer_handle), SGPT_CMD_STOP, 0);	
	USB_GPTI_StopItem(g_UsbHostMs[ms_index].sleep_timer_handle);

	DclOTG_DRV_Control(g_OTG_Dcl_Handle, OTG_DRV_CMD_GET_PLUG_TYPE, (DCL_CTRL_DATA_T  *)&dcl_data);
	plug_type = (OTG_PLUG_TYPE)dcl_data.type;

	USB_Dbg_Trace(USB_HOST_MS_ERROR_HLDR, (kal_uint32)plug_type, (kal_uint32)g_UsbHostMs[ms_index].dev_attatch);

	if(g_UsbHostMs[ms_index].dev_attatch == KAL_TRUE)
	{
		/* If cable is plugged out then error, do not turn off Vbus */
		/* Stop OTG action */
//		if(OTG_Get_Plug_Type() == OTG_PLUG_A)
		if(plug_type == OTG_PLUG_A)
		{
			DclOTG_DRV_Control(g_OTG_Dcl_Handle, OTG_DRV_CMD_A_STOP_HOST, NULL);
//			OTG_A_Stop_Host();
		}
		else
		{
			DclOTG_DRV_Control(g_OTG_Dcl_Handle, OTG_DRV_CMD_B_STOP_HOST, NULL);
//			OTG_B_Stop_Host();
		}

		OTG_Display_Message(OTG_DISPLAY_MSG_UN_SUPPORT);

		drv_trace1(TRACE_FUNC, (kal_uint32)USB_HOST_MS_CHECK_MEDIA_STATE, g_UsbHostMs[ms_index].media_state_change);
		USB_Dbg_Trace(USB_HOST_MS_REPORT_MEDIA_STATE,  g_UsbHostMs[ms_index].media_state_change, (kal_uint32)g_UsbHostMs[ms_index].b_sending_change_ilm);

		if((g_UsbHostMs[ms_index].media_state_change != 0) && (g_UsbHostMs[ms_index].b_sending_change_ilm == KAL_FALSE))
		{
			USB_Host_Ms_Check_Media_State(ms_index);
		}
	}
}


/************************************************************
	ms class state functions. Matintain the state of all LUN
*************************************************************/

/* Get device LUN. It contains the total error handling */
static kal_bool USB_Host_Ms_Comp_Get_LUN(kal_uint8 ms_index)
{
	/* Send MS class specific GET_LUN EP0 command to device*/
	USB_Host_Ms_Get_LUN(ms_index);

	if(g_UsbHostMs[ms_index].dev_state == USB_HOST_MS_DEV_STATE_ERROR)
	{
		if(g_UsbHostMs[ms_index].result == USB_HOST_MS_RESULT_STALL)
		{
			g_UsbHostMs[ms_index].dev_error_count = 0;
			return KAL_FALSE;
		}
		else
		{
			g_UsbHostMs[ms_index].dev_error_count++;

			if(USB_Host_Ms_Error_Check(ms_index) == KAL_TRUE)
			{
				/* It means reset is no use or error count exceed limit */
				/* some device may not implement this command, but PC can detect it */
			}
			else
			{
				/* reset is complete, so GET_LUN again */
				/* Error handling is in the recursive function */
				USB_Host_Ms_Comp_Get_LUN(ms_index);
			}
		}
	}

	if((g_UsbHostMs[ms_index].dev_error_count >= 3) ||(g_UsbHostMs[ms_index].dev_attatch == KAL_FALSE))
	{
		/* Error count exceed limit, host function has been turned off in error handler */
		return KAL_FALSE;
	}
	else
	{
		/* Reset error count. Avoid error count propagete */
		g_UsbHostMs[ms_index].dev_error_count = 0;
		return KAL_TRUE;
	}
}


/* Query all LUN media. It contains the total error handling.
     If result is fail, the host function is turned off in this function */
static kal_bool USB_Host_Ms_Query_All_Media(kal_uint8 ms_index)
{
	kal_uint32 index;
	kal_uint32 index2;


	for(index = 0; index < g_UsbHostMs[ms_index].total_lun; index++)
	{
		/* Query the dedicated LUN */
		USB_Host_MS_Query_Media(index);

		if(g_UsbHostMs[ms_index].dev_state != USB_HOST_MS_DEV_STATE_READY)
		{
			/* Reset all media state */
			for(index2 = 0; index2 < g_UsbHostMs[ms_index].total_lun; index2++)
			{
				/* If original state is READY, set state change as true */
				if(((g_UsbHostMs[ms_index].media_info[index2].state == USB_HOST_MS_MEDIA_STATE_WR_PROTECT)
					||(g_UsbHostMs[ms_index].media_info[index2].state == USB_HOST_MS_MEDIA_STATE_READY))
					&& (g_UsbHostMs[ms_index].media_info[index2].sec_size != 0))
				{
					g_UsbHostMs[ms_index].media_state_change |= (1<<index2);
				}

				/* Set all the media state to error */
				g_UsbHostMs[ms_index].media_info[index2].state = USB_HOST_MS_MEDIA_STATE_ERROR;
			}

			if(g_UsbHostMs[ms_index].dev_state == USB_HOST_MS_DEV_STATE_FATAL_ERROR)
			{
				/* It means reset is no use or error count exceed limit */
				g_UsbHostMs[ms_index].dev_error_count = 8;
				USB_Host_Ms_Error_Handler(ms_index);
				break;
			}
			else
			{
				g_UsbHostMs[ms_index].dev_error_count++;

				if(g_UsbHostMs[ms_index].dev_error_count == 8)
				{
					USB_Host_Ms_Error_Handler(ms_index);
					break;
				}

			}
/*			
			else  //a pecific card reader cannot be USB MS reset  --> PC error handler : continue send command
			{
				g_UsbHostMs[ms_index].dev_error_count++;

				if(USB_Host_Ms_Error_Check(ms_index) == KAL_TRUE)
				{
					// It means reset is no use or error count exceed limit 
					USB_Host_Ms_Error_Handler(ms_index);
					break;
				}
				else
				{
					// reset is complete, so Query all media again 
					// Error handling is in the recursive function 
					USB_Host_Ms_Query_All_Media(ms_index);
					break;
				}
			}
*/

		}
	}

	if((g_UsbHostMs[ms_index].dev_error_count >= 3)||(g_UsbHostMs[ms_index].dev_attatch == KAL_FALSE))
	{
		/* Error count exceed limit, host function has been turned off in error handler */
		return KAL_FALSE;
	}
	else
	{
		/* Reset error count. Avoid error count propagete */
		g_UsbHostMs[ms_index].dev_error_count = 0;
		return KAL_TRUE;
	}
}


/* Query all LUN media. It contains the total error handling.
     If result is fail, the host function is turned off in this function */
static kal_bool USB_Host_Ms_Check_All_Media(kal_uint8 ms_index)
{
	kal_uint32 index;
	kal_uint32 index2;


	for(index = 0; index < g_UsbHostMs[ms_index].total_lun; index++)
	{
		/* Note that take and give the mutex in lun level. To reduce the latency in application read and write */
		kal_take_mutex(g_UsbHostMs[ms_index].mutex_id);

		/* check the dedicated LUN */
		USB_Host_MS_Check_Media(index);

		if(g_UsbHostMs[ms_index].dev_state != USB_HOST_MS_DEV_STATE_READY)
		{
			/* Reset all media state */
			for(index2 = 0; index2 < g_UsbHostMs[ms_index].total_lun; index2++)
			{
				/* If original state is READY, set state change as true */
				if(((g_UsbHostMs[ms_index].media_info[index2].state == USB_HOST_MS_MEDIA_STATE_WR_PROTECT)
					||(g_UsbHostMs[ms_index].media_info[index2].state == USB_HOST_MS_MEDIA_STATE_READY))
					&& (g_UsbHostMs[ms_index].media_info[index2].sec_size != 0))
				{
					g_UsbHostMs[ms_index].media_state_change |= (1<<index2);
				}

				/* Set all the media state to error */
				g_UsbHostMs[ms_index].media_info[index2].state = USB_HOST_MS_MEDIA_STATE_ERROR;
			}

			if(g_UsbHostMs[ms_index].dev_state == USB_HOST_MS_DEV_STATE_FATAL_ERROR)
			{
				/* It means reset is no use or error count exceed limit */
				g_UsbHostMs[ms_index].dev_error_count = 8;
				USB_Host_Ms_Error_Handler(ms_index);
				kal_give_mutex(g_UsbHostMs[ms_index].mutex_id);
				break;
			}
			else
			{
				g_UsbHostMs[ms_index].dev_error_count++;

				/* Should modify to dev error, reset device */
				if(USB_Host_Ms_Error_Check(ms_index) == KAL_TRUE)
				{
					/* It means reset is no use or error count exceed limit */
					USB_Host_Ms_Error_Handler(ms_index);
					kal_give_mutex(g_UsbHostMs[ms_index].mutex_id);
					break;
				}
				else
				{
					/* reset is complete, so check all media again */
					/* Error handling is in the recursive function */
					kal_give_mutex(g_UsbHostMs[ms_index].mutex_id);
					USB_Host_Ms_Check_All_Media(ms_index);
					break;
				}
			}
		}
		else
		{
			kal_give_mutex(g_UsbHostMs[ms_index].mutex_id);
		}
	}

	if((g_UsbHostMs[ms_index].dev_error_count >= 3) ||(g_UsbHostMs[ms_index].dev_attatch == KAL_FALSE) )
	{
		/* Error count exceed limit, host function has been turned off in error handler */
		return KAL_FALSE;
	}
	else
	{
		/* Reset error count. Avoid error count propagete */
		g_UsbHostMs[ms_index].dev_error_count = 0;
		return KAL_TRUE;
	}
}

/************************************************************
	state machine entry functions
*************************************************************/

/* GPT timeout function*/
/* This GPT timer is used to periodically checking media status*/
static void USB_Host_Ms_State_Timeout(void *parameter)
{
//	ilm_struct *usb_ilm = NULL;
	usb_host_usbattach_ind_struct *usb_host_attach;

	USB_Host_Ms_Struct  *ms_temp = (USB_Host_Ms_Struct *)parameter;
	kal_uint8 usb_ip_port = ms_temp->common_info.usb_ip_port ;	
	kal_uint8 ms_index = USB_MS_Check_index(usb_ip_port);


	//DclSGPT_Control((DCL_HANDLE)(g_UsbHostMs[ms_index].gpt_handle), SGPT_CMD_STOP, 0);	
	USB_GPTI_StopItem(g_UsbHostMs[ms_index].gpt_handle);

	/* If device is plugged out, do not send this message */
	if(g_UsbHostMs[ms_index].dev_attatch == KAL_TRUE)
	{

		/* Send message to USB task */
		usb_host_attach = (usb_host_usbattach_ind_struct*)construct_local_para(sizeof(usb_host_usbattach_ind_struct), TD_CTRL);
//		usb_host_attach->usb_ip_port = usb_ip_port;
		usb_host_attach->feature_index = ms_index;
	
	
		USB_Send_Msg_Ext_Queue(MOD_USB, MSG_ID_USB_MSHOST_QUERY_IND, usb_host_attach);
//		DRV_BuildPrimitive(usb_ilm, stack_get_active_module_id(),MOD_USB, MSG_ID_USB_MSHOST_QUERY_IND, usb_host_attach);
//		msg_send_ext_queue(usb_ilm);
	}
}

/* Start ms state. Initialize state info and query each slot info */
/* Note that this function should be called when first detect ms device*/
void USB_Host_Ms_State_Start(kal_uint8 ms_index)
{
	kal_uint32 index;
	kal_bool result;
//	SGPT_CTRL_START_T start;

	/* Initailize the information */
	if(g_UsbHostMs[ms_index].event_id == 0)
		g_UsbHostMs[ms_index].event_id = kal_create_event_group("USB_MS_EVEVT");

	if(g_UsbHostMs[ms_index].mutex_id == 0)
		g_UsbHostMs[ms_index].mutex_id = kal_create_mutex("USB_MS_MUTEX");

	USB_GPTI_GetHandle(&(g_UsbHostMs[ms_index].gpt_handle));//DclSGPT_Open(DCL_GPT_CB, 0);//GPTI_GetHandle(&g_UsbHostMs.gpt_handle);

//	if (g_UsbHostMs[ms_index].gpt_handle == 0)
//		g_UsbHostMs[ms_index].gpt_handle = USB_GPTI_GetHandle();//DclSGPT_Open(DCL_GPT_CB, 0);//GPTI_GetHandle(&g_UsbHostMs.gpt_handle);

	USB_GPTI_GetHandle(&(g_UsbHostMs[ms_index].sleep_timer_handle));//DclSGPT_Open(DCL_GPT_CB, 0);//GPTI_GetHandle(&g_UsbHostMs.gpt_handle);

//	if (g_UsbHostMs[ms_index].sleep_timer_handle== 0)
//		g_UsbHostMs[ms_index].sleep_timer_handle = USB_GPTI_GetHandle();//DclSGPT_Open(DCL_GPT_CB, 0);//GPTI_GetHandle(&g_UsbHostMs.gpt_handle);


	/* Get LUN, it contains the error handling */
	result = USB_Host_Ms_Comp_Get_LUN(ms_index);

	if(result == KAL_TRUE)
	{
		/* The got LUN is total lun - 1 */
		g_UsbHostMs[ms_index].total_lun++;

		/* If LUN number is larger than we can support, onlt the first N can be detected */
		if(g_UsbHostMs[ms_index].total_lun > USB_HOST_MS_SUPPORT_LUN)
			g_UsbHostMs[ms_index].total_lun = USB_HOST_MS_SUPPORT_LUN;
	}
	else
	{
		/* when device not implement this command, it is only one LUN */
		g_UsbHostMs[ms_index].dev_error_count = 0;
		g_UsbHostMs[ms_index].total_lun = 1;
	}

	/* Reset all the LUN state to absent state */
	for(index = 0; index < g_UsbHostMs[ms_index].total_lun; index++)
	{
		g_UsbHostMs[ms_index].media_info[index].state = USB_HOST_MS_MEDIA_STATE_ABSENT;
	}

	/* Get LUN is success, continue to query each LUN info */
	result = USB_Host_Ms_Query_All_Media(ms_index);
	/* If result is fail, ms has been detached */

	if(result == KAL_TRUE)
	{
		/* Query each LUN is success, continue to check whether each LUN is in card slot or not */
		result = USB_Host_Ms_Check_All_Media(ms_index);
		/* If result is fail, ms has been detached */
	}

	drv_trace1(TRACE_FUNC, (kal_uint32)USB_HOST_MS_CHECK_MEDIA_STATE, g_UsbHostMs[ms_index].media_state_change);
	USB_Dbg_Trace(USB_HOST_MS_REPORT_MEDIA_STATE,  g_UsbHostMs[ms_index].media_state_change, (kal_uint32)g_UsbHostMs[ms_index].b_sending_change_ilm);

	if(result == KAL_TRUE)
	{
		/* To prevent USB disconn intr coming during this moment */
		IRQMask(USB_IRQ_MAP[g_UsbHostMs[ms_index].common_info.usb_ip_port]);

		if((g_UsbHostMs[ms_index].media_state_change != 0)&&(g_UsbHostMs[ms_index].b_sending_change_ilm == KAL_FALSE))
		{
			USB_Host_Ms_Check_Media_State(ms_index);
		}

		/* If device is plugged out, do not send this message */
		if(g_UsbHostMs[ms_index].dev_attatch == KAL_TRUE)
		{
			/* Start timer to query device state */
			USB_GPTI_StartItem(g_UsbHostMs[ms_index].gpt_handle, USB_HOST_MS_QUERY_PERIOD,USB_Host_Ms_State_Timeout, &g_UsbHostMs);
//			start.u2Tick =USB_HOST_MS_QUERY_PERIOD;
//			start.pfCallback = USB_Host_Ms_State_Timeout;
//			start.vPara = &g_UsbHostMs[ms_index];
//			DclSGPT_Control((DCL_HANDLE)(g_UsbHostMs[ms_index].gpt_handle), SGPT_CMD_START, (DCL_CTRL_DATA_T*)&start);				
		}

		if(USBD_Get_UnMask_Irq(g_UsbHostMs[ms_index].common_info) == KAL_TRUE)
			IRQUnmask(USB_IRQ_MAP[g_UsbHostMs[ms_index].common_info.usb_ip_port]);
	}
	else
	{
		drv_trace0(TRACE_FUNC, (kal_uint32)USB_HOST_MS_STATE_START_FAIL);
	}


}


/* ms class main state machine of each LUN */
/* Note that this is called periodically when ms is active */
void USB_Host_Ms_State_Main(kal_uint8 ms_index)
{
	kal_bool result;
//	SGPT_CTRL_START_T start;

	if(g_UsbHostMs[ms_index].dev_attatch == KAL_TRUE)
	{
		result = USB_Host_Ms_Check_All_Media(ms_index);	
	}
	else
	{
		result = KAL_FALSE;
		USB_Dbg_Trace(USB_HOST_MS_STATE_MAIN_FALSE, 0, 0);
	}

	drv_trace1(TRACE_FUNC, (kal_uint32)USB_HOST_MS_CHECK_MEDIA_STATE, g_UsbHostMs[ms_index].media_state_change);
	USB_Dbg_Trace(USB_HOST_MS_REPORT_MEDIA_STATE,  g_UsbHostMs[ms_index].media_state_change, (kal_uint32)g_UsbHostMs[ms_index].b_sending_change_ilm);

	if(result == KAL_TRUE)
	{
		if((g_UsbHostMs[ms_index].media_state_change != 0)&&(g_UsbHostMs[ms_index].b_sending_change_ilm == KAL_FALSE))
		{
			/* Send message to FMT task about card state change */
			USB_Host_Ms_Check_Media_State(ms_index);
		}

		/* start timer to start query device state */
		USB_GPTI_StartItem(g_UsbHostMs[ms_index].gpt_handle, USB_HOST_MS_QUERY_PERIOD,USB_Host_Ms_State_Timeout, &g_UsbHostMs[ms_index]);
//		start.u2Tick =USB_HOST_MS_QUERY_PERIOD;
//		start.pfCallback = USB_Host_Ms_State_Timeout;
//		start.vPara = &g_UsbHostMs[ms_index];
//		DclSGPT_Control((DCL_HANDLE)(g_UsbHostMs[ms_index].gpt_handle), SGPT_CMD_START, (DCL_CTRL_DATA_T*)&start);			
	}
	else
	{
		drv_trace0(TRACE_FUNC, (kal_uint32)USB_HOST_MS_STATE_MAIN_FAIL);
	}
}


#endif  /* __OTG_ENABLE__ */

