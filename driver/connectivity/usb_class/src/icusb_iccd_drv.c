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
 *    iccd_iccd_drv.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements host iccd class driver
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#include "drv_comm.h"
#include "gpt_sw.h"
//MSBB remove #include "app_buff_alloc.h"
#include "usb_comm.h"
#include "usb.h"
#include "usb_custom.h"
#include "usb.h"
#include "usbd.h"
//#include "otg_drv.h"
#include "intrCtrl.h"

//#include "stack_common.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "kal_public_api.h" //#include "stack_ltlcom.h" //MSBB change #include "app_ltlcom.h"       /* Task message communiction */

#include "usbms_state.h"
#include "icusb_iccd_drv.h"
#include "icusb_iccd_adap.h"
//#include "icusb_pri.h"
#include "icusb_debug_tool.h"
#include "usb_trc.h"
#include "dcl.h"

/* for debug only*/
//#include "usb_hcd_pri.h"
//extern USB_HCD_Struct g_UsbHcdInfo;

#ifdef __IC_USB_ENABLE__

#ifdef __IC_USB_ICCD_SUPPORT__

USB_Host_ICCD_Struct g_UsbHostIccd[USB_MAX_ICCD_NUM];


static kal_uint8 usb_host_iccd_support_num = 0;
static kal_uint8 usb_host_iccd_config_num = 0xFF;
static kal_uint8 usb_host_iccd_support_real_num = 0;


static void USB_Host_ICCD_Ctrl_EP_Hdlr(kal_uint8 usb_ip_port,USB_HCD_STATUS result, kal_uint32 param);
static void USB_Host_ICCD_Hdlr(kal_uint8 usb_ip_port,USB_HCD_STATUS result, kal_uint32 param);
static kal_bool	 USB_Host_Iccd_Match(kal_uint8 usb_ip_port,USBD_Desc_Info *p_desc_info, kal_uint32 cfg_num, kal_uint32 if_num);
static void USB_Host_Iccd_Startup(kal_uint8 usb_ip_port, USBD_Desc_Info *p_desc_info, kal_uint32 cfg_num, kal_uint32 if_num);
static void USB_Host_Iccd_Detach(kal_uint8 usb_ip_port);
static void USB_Host_Iccd_Suspend(kal_uint8 usb_ip_port);
static void USB_Host_Iccd_Resume(kal_uint8 usb_ip_port);
static kal_uint8 USB_ICCD_Check_index(kal_uint8 usb_ip_port);



static kal_uint8 USB_ICCD_Check_index(kal_uint8 usb_ip_port)
{
	kal_uint8 index;
	for (index = 0; index< USB_MAX_ICCD_NUM; index++)
	{
		if (usb_ip_port == g_UsbHostIccd[index].common_info.usb_ip_port)
			return index;
	}

	 // no matching 
	 ASSERT(0);
}


/************************************************************
	iccd class handler. Note that it is executed in HISR context
*************************************************************/

/* handler for control endpoint */
/* It handles both standard and class specific EP0 command*/
static void USB_Host_ICCD_Ctrl_EP_Hdlr(kal_uint8 iccd_index,USB_HCD_STATUS result, kal_uint32 param)
{		
	/* Store the command because it will be change immediatly*/
	USB_HOST_ICCD_EP0_CMD ep0_cmd = g_UsbHostIccd[iccd_index].ep0_cmd;


	ICUSB_Dbg_Trace(IC_USB_ICCD_CTRL_EP_HDLR,  (kal_uint32)result, (kal_uint32)ep0_cmd);

	/* Unless another EP0 command is issued, the command should be set to NONE*/
	g_UsbHostIccd[iccd_index].ep0_cmd = USB_HOST_ICCD_EP0_CMD_NONE;

	if(result != USB_HCD_OK)
	{
		/* translate the result */
		/* for EP0 error, the handler dose not do error handling,
		    the error handling is done in the upper layer state */
		if(result == USB_HCD_STALL)
			g_UsbHostIccd[iccd_index].ep0_result = USB_HOST_ICCD_RESULT_STALL;
		else if(result == USB_HCD_TIMEOUT)
			g_UsbHostIccd[iccd_index].ep0_result = USB_HOST_ICCD_RESULT_TIMEOUT;
		else
			g_UsbHostIccd[iccd_index].ep0_result = USB_HOST_ICCD_RESULT_NO_RESPONSE;

		g_UsbHostIccd[iccd_index].rx_real_length = 0;
		ICUSB_Dbg_Trace(IC_USB_SET_EVENT,  0, 0);
		kal_set_eg_events(g_UsbHostIccd[iccd_index].event_id, EVENT_USB_ICCD_DONE, KAL_OR);		
	}
	else
	{
		/* result is OK */			
			g_UsbHostIccd[iccd_index].ep0_result = USB_HOST_ICCD_RESULT_OK;
			g_UsbHostIccd[iccd_index].rx_real_length = param;
			ICUSB_Dbg_Trace(IC_USB_SET_EVENT,  0, 0);
			kal_set_eg_events(g_UsbHostIccd[iccd_index].event_id, EVENT_USB_ICCD_DONE, KAL_OR);		
	}
}

//EP0 Response  1. on status stage  2.receive STALL or timeout 
static void USB_Host_ICCD_Hdlr(kal_uint8 usb_ip_port,USB_HCD_STATUS result, kal_uint32 param)
{
	kal_uint8 iccd_index = USB_ICCD_Check_index(usb_ip_port);
		
	ICUSB_Dbg_Trace(IC_USB_ICCD_HDLR,  (kal_uint32)result, (kal_uint32)g_UsbHostIccd[iccd_index].ep0_cmd);

	if(g_UsbHostIccd[iccd_index].ep0_cmd != USB_HOST_ICCD_EP0_CMD_NONE)
	{
		USB_Host_ICCD_Ctrl_EP_Hdlr(iccd_index,result, param);
	}
	else
	{
		ASSERT(0);
	}
}

// SIM Drive will set USB Reset for error recovery
void USB_Host_ICCD_Reset_Card(kal_uint8 iccd_index)
{
		if(g_UsbHostIccd[iccd_index].config == KAL_FALSE)
			ASSERT(0);

		ICUSB_Dbg_Trace(IC_USB_ICC_RESET_DEVICE, 0,0);
			
		USBD_Reset_Req(g_UsbHostIccd[iccd_index].common_info);							
}	

void USB_Host_ICCD_Enumeration_Fail(kal_uint8 usb_ip_port)
{
	kal_uint8 iccd_index = USB_ICCD_Check_index(usb_ip_port);

	ICUSB_Dbg_Trace(IC_USB_ICC_ENUMERATION_FAIL, 0,0);
	
	/* notify SIM Driver to start Enumeration Fail */
	kal_set_eg_events(g_UsbHostIccd[iccd_index].start_event_id, EVENT_ICUSB_ENUMERATION_FAIL, KAL_OR);	
}

 /************************************************************
	iccd class ep0 class specific functions (Control endpoint functions)
*************************************************************/

USB_HOST_ICCD_RESULT USB_Host_ICCD_POWER_ON(kal_uint8 iccd_index)
{ 
	kal_uint32 event_group;
	Usb_Command usbd_cmd;

	usbd_cmd.bmRequestType = USB_CMD_CLASSIFOUT;
	usbd_cmd.bRequest = USB_ICCD_POWER_ON;
	usbd_cmd.wValue = 1;
	usbd_cmd.wIndex = 0; //bInterfaceNumber
	usbd_cmd.wLength = 0;
	
	g_UsbHostIccd[iccd_index].ep0_cmd = USB_HOST_ICCD_EP0_CMD_POWER_ON;

	ICUSB_Dbg_Trace(IC_USB_ICC_Power_ON_CMD, 0,0);	

	USBD_Start_Setup_Cmd(g_UsbHostIccd[iccd_index].common_info, &usbd_cmd, NULL, USBD_EP0_DATA_SEND, 0, KAL_TRUE,USB_Host_ICCD_Hdlr);

	if(g_UsbHostIccd[iccd_index].config == KAL_TRUE)
	{
		/* wait for transfer complete */
		kal_retrieve_eg_events(g_UsbHostIccd[iccd_index].event_id, EVENT_USB_ICCD_DONE, 
						KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
		ICUSB_Dbg_Trace(IC_USB_RETRIEVE_EVENT,  0, 0);

		return  g_UsbHostIccd[iccd_index].ep0_result;		
	}
	else
	{
		return  USB_HOST_ICCD_RESULT_NOT_CONFIG;
	}
}

USB_HOST_ICCD_RESULT USB_Host_ICCD_POWER_OFF(kal_uint8 iccd_index)
{ 
	kal_uint32 event_group;
	Usb_Command usbd_cmd;

	usbd_cmd.bmRequestType = USB_CMD_CLASSIFOUT;
	usbd_cmd.bRequest = USB_ICCD_POWER_OFF;
	usbd_cmd.wValue = 0;
	usbd_cmd.wIndex = 0; //bInterfaceNumber
	usbd_cmd.wLength = 0;

	g_UsbHostIccd[iccd_index].ep0_cmd = USB_HOST_ICCD_EP0_CMD_POWER_OFF;

	ICUSB_Dbg_Trace(IC_USB_ICC_Power_OFF_CMD, 0,0);
		
	USBD_Start_Setup_Cmd(g_UsbHostIccd[iccd_index].common_info, &usbd_cmd, NULL, USBD_EP0_DATA_SEND, 0, KAL_TRUE,USB_Host_ICCD_Hdlr);

	if(g_UsbHostIccd[iccd_index].config == KAL_TRUE)
	{
		/* wait for transfer complete */
		kal_retrieve_eg_events(g_UsbHostIccd[iccd_index].event_id, EVENT_USB_ICCD_DONE, 
						KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
						
		ICUSB_Dbg_Trace(IC_USB_RETRIEVE_EVENT,  0, 0);

		return  g_UsbHostIccd[iccd_index].ep0_result;		
	}
	else
	{
		return  USB_HOST_ICCD_RESULT_NOT_CONFIG;
	}
}

USB_HOST_ICCD_RESULT USB_Host_ICCD_XFR_BLOCK(kal_uint8 iccd_index,kal_uint16 buflen, kal_uint8 *buffer)
{ 
	kal_uint32 event_group;
	Usb_Command usbd_cmd;

	usbd_cmd.bmRequestType = USB_CMD_CLASSIFOUT;
	usbd_cmd.bRequest = USB_ICCD_XFR_BLOCK;
	usbd_cmd.wValue = 0;
	usbd_cmd.wIndex = 0; //bInterfaceNumber
	usbd_cmd.wLength = buflen;
	
	g_UsbHostIccd[iccd_index].ep0_cmd = USB_HOST_ICCD_EP0_CMD_XFR_BLOCK;
	
	ICUSB_Dbg_Trace(IC_USB_ICC_XFR_CMD, 0, 0);

	USBD_Start_Setup_Cmd(g_UsbHostIccd[iccd_index].common_info, &usbd_cmd, buffer, USBD_EP0_DATA_SEND, buflen, KAL_TRUE,USB_Host_ICCD_Hdlr);

	
	if(g_UsbHostIccd[iccd_index].config == KAL_TRUE)
	{
		/* wait for transfer complete */		
		kal_retrieve_eg_events(g_UsbHostIccd[iccd_index].event_id, EVENT_USB_ICCD_DONE, 
						KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
						
		ICUSB_Dbg_Trace(IC_USB_RETRIEVE_EVENT,  0, 0);
		
		return  g_UsbHostIccd[iccd_index].ep0_result;		
	}
	else
	{
		return  USB_HOST_ICCD_RESULT_NOT_CONFIG;
	}
}

USB_HOST_ICCD_CMD_STATE USB_Host_ICCD_DATA_BLOCK(kal_uint8 iccd_index,kal_uint16 *rx_size, kal_uint8 *buffer)
{ 
	kal_uint32 event_group;
	kal_uint16 delay_time;//rx_length;
	Usb_Command usbd_cmd;

	if ((*rx_size  < 2)||(rx_size == NULL))
		ASSERT(0); //illegal length

	  if (*rx_size  < 4)  //ICCD spec: length cannot shorter than 4
    		*rx_size = 4;

	usbd_cmd.bmRequestType = USB_CMD_CLASSIFIN;
	usbd_cmd.bRequest = USB_ICCD_DATA_BLOCK;
	usbd_cmd.wValue = 0;
	usbd_cmd.wIndex = 0; //bInterfaceNumber
	usbd_cmd.wLength =  (*rx_size +1);  // header 

	g_UsbHostIccd[iccd_index].ep0_cmd = USB_HOST_ICCD_EP0_CMD_DATA_BLOCK;

	ICUSB_Dbg_Trace(IC_USB_ICC_DATA_CMD, 0, 0);

	USBD_Start_Setup_Cmd(g_UsbHostIccd[iccd_index].common_info, &usbd_cmd, buffer, USBD_EP0_DATA_RECV, *rx_size, KAL_TRUE, USB_Host_ICCD_Hdlr);

	if(g_UsbHostIccd[iccd_index].config == KAL_TRUE)
	{
		/* wait for transfer complete */
		kal_retrieve_eg_events(g_UsbHostIccd[iccd_index].event_id, EVENT_USB_ICCD_DONE, 
						KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
		ICUSB_Dbg_Trace(IC_USB_RETRIEVE_EVENT,  0, 0);

		g_UsbHostIccd[iccd_index].rx_real_length = USBD_EP0_Data_Length(g_UsbHostIccd[iccd_index].common_info);
		ICUSB_Dbg_Trace(IC_USB_ICC_DATA_CMD,  g_UsbHostIccd[iccd_index].rx_real_length, *rx_size);


		if(g_UsbHostIccd[iccd_index].ep0_result == USB_HOST_ICCD_RESULT_STALL)
		{
			ICUSB_Dbg_Trace(IC_USB_ICC_STALL, 0, 0); 
			g_UsbHostIccd[iccd_index].ep0_result  = USB_HOST_ICCD_RESULT_OK;  //QQ Test  --> HW cannot recognize ACK, re send OUT packet , Device return STALL
		}

		
		/* Device status is error if result not OK in EP0 command */
		if(g_UsbHostIccd[iccd_index].ep0_result == USB_HOST_ICCD_RESULT_OK)
		{				
			ICUSB_Dbg_Trace(IC_USB_ICC_DATA_CMD,   buffer[0],1);			
			switch (buffer[0])
			{			
			case USB_DATA_bResponse_APDU_DONE:
			// parse Data stage Request Type
				g_UsbHostIccd[iccd_index].apdu_response = USB_HOST_ICCD_APDU_RESPONSE;
				break;
		
			case USB_DATA_bResponse_APDU_START_PACKET:		
				 //Request data < actual data
				g_UsbHostIccd[iccd_index].apdu_response = USB_HOST_ICCD_APDU_RESPONSE;					 
				break;
				
			case USB_DATA_bResponse_APDU_MIDDLE_PACKET:		
				//Request data : middle packet
				g_UsbHostIccd[iccd_index].apdu_response = USB_HOST_ICCD_APDU_RESPONSE;
				break;
				
			case USB_DATA_bResponse_APDU_LAST_PACKET:		
				 //Request data last packet
				g_UsbHostIccd[iccd_index].apdu_response = USB_HOST_ICCD_APDU_RESPONSE;					 
				break;
						
			case USB_DATA_bResponse_Polling:		
				g_UsbHostIccd[iccd_index].apdu_response = USB_HOST_ICCD_APDU_POLLING;														
				delay_time = ((buffer[1]<<8)|buffer[2]); // buffer1 = [01]; buffer2 = [00]
				delay_time = ((delay_time)/4);
				ICUSB_Dbg_Trace(IC_USB_ICCD_BUSY_WAIT,  0, delay_time);
				kal_sleep_task(delay_time);								
				break;
								
			case USB_DATA_bResponse_Status_Info:		
				g_UsbHostIccd[iccd_index].apdu_response = USB_HOST_ICCD_CMD_FAIL;																
				ICUSB_Dbg_Trace(IC_USB_ICC_DATA_CMD, buffer[1], 2);							
				if((buffer[1] & USB_bmIccStatus)== USB_bmIccStatus_Active)
				{	
					if ((buffer[1] & USB_bmCommandStatus)== USB_bmCommandStatus_Ready)
						g_UsbHostIccd[iccd_index].dev_state = USB_ICCD_DEVICE_Active;
					else
					{
						ICUSB_Dbg_Trace(IC_USB_ICC_DATA_CMD, buffer[2], 3);

						if (buffer[2] == USB_ICC_MUTE)
							g_UsbHostIccd[iccd_index].dev_state = USB_ICCD_DEVICE_Cannot_Response;	
//						else if(buffer[2] == USB_XFR_OVERRUN)		
//							ASSERT(0);//Host send data length error (more than wLength)
						else if(buffer[2] == USB_HW_ERROR)
							g_UsbHostIccd[iccd_index].dev_state = USB_ICCD_DEVICE_HW_ERROR;	
						else
							EXT_ASSERT(0,buffer[2],0,0);																	
					}		
				}	
				else if((buffer[1]& USB_bmIccStatus)== USB_bmIccStatus_Not_Active)
				{
					g_UsbHostIccd[iccd_index].dev_state = USB_ICCD_DEVICE_Not_Active;
				}	
				else
				{	
					ASSERT(0);	
				}		
				break;								

			case USB_DATA_bResponse_NEXT_XFR:	
				ICUSB_Dbg_Trace(IC_USB_ICC_DATA_CMD, buffer[1], 4);					
				g_UsbHostIccd[iccd_index].apdu_response = USB_HOST_ICCD_APDU_DONE;
				break;
				
			default:
				ASSERT(0);
			}	
						
		}	
		else  //ep0_result is not OK
		{	
			ICUSB_Dbg_Trace(IC_USB_ICC_DATA_CMD, 0, 5);				
			g_UsbHostIccd[iccd_index].apdu_response = USB_HOST_ICCD_ERROR;
		}

		if ((g_UsbHostIccd[iccd_index].apdu_response == USB_HOST_ICCD_APDU_DONE)
			||(g_UsbHostIccd[iccd_index].apdu_response == USB_HOST_ICCD_APDU_RESPONSE))
		{

			if (g_UsbHostIccd[iccd_index].rx_real_length == 0)
			{
				    // Power on / Power off may cause zero length data
				    ICUSB_Dbg_Trace(IC_USB_ICC_DATA_CMD,  0xFF,0);
			}
			else
			{
				if (g_UsbHostIccd[iccd_index].rx_real_length > *rx_size)
				{	
					ASSERT(0);
				}
				else	
				{	
					*rx_size = g_UsbHostIccd[iccd_index].rx_real_length;
				}	
			}
		}
		
		return  g_UsbHostIccd[iccd_index].apdu_response;
	}
	else
	{
		return USB_HOST_ICCD_NOT_CONFIG;	
	}
}

USB_HOST_ICCD_DEV_STATE USB_Host_ICCD_SLOT_STATUS(kal_uint8 iccd_index)
{ 
	kal_uint32 event_group;
	USB_Host_ICCD_Status_Struct	dev_status;
	Usb_Command usbd_cmd;

	usbd_cmd.bmRequestType = USB_CMD_CLASSIFIN;
	usbd_cmd.bRequest = USB_ICCD_SLOT_STATUS;
	usbd_cmd.wValue = 0;
	usbd_cmd.wIndex = 0; //bInterfaceNumber
	usbd_cmd.wLength = 3;

	g_UsbHostIccd[iccd_index].ep0_cmd = USB_HOST_ICCD_EP0_CMD_SLOT_STATUS;

	ICUSB_Dbg_Trace(IC_USB_ICC_SLOT_CMD, 0, 0);

	USBD_Start_Setup_Cmd(g_UsbHostIccd[iccd_index].common_info, &usbd_cmd, (kal_uint8*)&dev_status, USBD_EP0_DATA_RECV, 3, KAL_TRUE,USB_Host_ICCD_Hdlr);

	if(g_UsbHostIccd[iccd_index].config == KAL_TRUE)
	{
		/* wait for transfer complete */
		kal_retrieve_eg_events(g_UsbHostIccd[iccd_index].event_id, EVENT_USB_ICCD_DONE, 
						KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
		ICUSB_Dbg_Trace(IC_USB_RETRIEVE_EVENT,  0, 0);

		if(g_UsbHostIccd[iccd_index].ep0_result == USB_HOST_ICCD_RESULT_STALL)
		{
			ICUSB_Dbg_Trace(IC_USB_ICC_STALL, 0, 0);
			g_UsbHostIccd[iccd_index].ep0_result = USB_HOST_ICCD_RESULT_OK;   //QQ Test  --> HW cannot recognize ACK, re send OUT packet , Device return STALL
		}
			
		/* Device status is error if result not OK in EP0 command */
		if(g_UsbHostIccd[iccd_index].ep0_result == USB_HOST_ICCD_RESULT_OK)
		{
			ICUSB_Dbg_Trace(IC_USB_ICC_SLOT_CMD, 1, dev_status.bStatus);			
				
			if((dev_status.bStatus & USB_bmIccStatus)== USB_bmIccStatus_Active)
			{	
				if ((dev_status.bStatus & USB_bmCommandStatus)== USB_bmCommandStatus_Ready)
				{	
					g_UsbHostIccd[iccd_index].dev_state = USB_ICCD_DEVICE_Active;
				}
				else
				{
					ICUSB_Dbg_Trace(IC_USB_ICC_SLOT_CMD, 2, dev_status.bError);	

					if (dev_status.bError == USB_ICC_MUTE)
						g_UsbHostIccd[iccd_index].dev_state = USB_ICCD_DEVICE_Cannot_Response;	
//					else if(dev_status.bError == USB_XFR_OVERRUN)		
//						ASSERT(0);//Host send data length error (more than wLength)
					else if(dev_status.bError == USB_HW_ERROR)
						g_UsbHostIccd[iccd_index].dev_state = USB_ICCD_DEVICE_HW_ERROR;	
					else
						EXT_ASSERT(0,dev_status.bError,0,0);																	
				}		
			}	
			else if((dev_status.bStatus & USB_bmIccStatus)== USB_bmIccStatus_Not_Active)
			{
					g_UsbHostIccd[iccd_index].dev_state = USB_ICCD_DEVICE_Not_Active;
			}	
			else if((dev_status.bStatus & USB_bmIccStatus)== USB_bmIccStatus_Not_Present)
			{   // before SMART SIM receives  power on command, status is Not Present 
					g_UsbHostIccd[iccd_index].dev_state = USB_ICCD_DEVICE_Not_Active;
			}
			else
			{	
				ICUSB_Dbg_Trace(IC_USB_ICC_SLOT_CMD, 3, dev_status.bStatus);	
				ASSERT(0);
			}				
		}		
		else
		{	
			g_UsbHostIccd[iccd_index].dev_state = USB_ICCD_DEVICE_Fail;
		}
		
		return 	g_UsbHostIccd[iccd_index].dev_state;	
	}
	else
	{
		return USB_ICCD_DEVICE_NOT_CONFIG;
	}
}



/***********************************************************
Restry ICCD HOST Driver
***********************************************************/

// GPT timer : HISR
 void USB_Host_ICCD_Sleep_Timeout(void *parameter)
{
	USB_Host_ICCD_Struct  *temp = (USB_Host_ICCD_Struct *)parameter;
	kal_uint8 usb_ip_port = temp -> common_info.usb_ip_port ;	
	kal_uint8 iccd_index = USB_ICCD_Check_index(usb_ip_port);

//	DclSGPT_Control((DCL_HANDLE)(g_UsbHostIccd[iccd_index].sleep_timer_handle), SGPT_CMD_STOP, 0);		
	USB_GPTI_StopItem(g_UsbHostIccd[iccd_index].sleep_timer_handle);

	ICUSB_Dbg_Trace(IC_USB_ICC_SUSPEND, 0,0);
		
	/* If device is plugged out, do not send this message */
	if(g_UsbHostIccd[iccd_index].dev_attatch == KAL_TRUE)
	{
		USBD_Suspend_Req(g_UsbHostIccd[iccd_index].common_info);
	}
}

/* If current we can support, we choose the largest one we can support, or we choose the smallest one */
static kal_bool	USB_Host_Iccd_Match(kal_uint8 usb_ip_port,USBD_Desc_Info *p_desc_info, kal_uint32 cfg_num, kal_uint32 if_num)
{
	kal_bool b_match = KAL_FALSE;


	if(p_desc_info->dev_desc.bDeviceClass == USB_ICCD_DEVICE_CODE)
	{
		if((p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_interface_desc->bInterfaceClass == USB_ICCD_INTERFACE_CLASS_CODE)
			&& (p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_interface_desc->bInterfaceSubClass == USB_ICCD_INTERFACE_SUBCLASS_CODE)
			&& (p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_interface_desc->bInterfaceProtocol == USB_ICCD_INTERFACE_PROTOCOL_CODE))
		{
			b_match = KAL_TRUE;
		}
	}

	if (b_match == KAL_TRUE)
	{
		if (usb_host_iccd_config_num != cfg_num)
		{
			usb_host_iccd_config_num = cfg_num;
			usb_host_iccd_support_num = 1;
		}
		else
		{
			usb_host_iccd_support_num  ++;
		}
		
		if (usb_host_iccd_support_num  > USB_MAX_ICCD_NUM)
			b_match = KAL_FALSE;
	}
	
	return b_match;
}


static void USB_Host_Iccd_Startup(kal_uint8 usb_ip_port, USBD_Desc_Info *p_desc_info, kal_uint32 cfg_num, kal_uint32 if_num)
{
//	ilm_struct *usb_ilm;
	kal_uint32 event_group;
	kal_uint8 iccd_index;
	SGPT_CTRL_START_T start;

	usb_host_iccd_support_real_num ++;

	if (usb_host_iccd_support_real_num  > USB_MAX_ICCD_NUM)
		ASSERT(0);

	iccd_index = usb_host_iccd_support_real_num-1; //start from 0
		
	if(g_UsbHostIccd[iccd_index].event_id != 0)
	{
		/* Receive all events that may exist after previous detatch */
		kal_retrieve_eg_events(g_UsbHostIccd[iccd_index].event_id, EVENT_USB_ICCD_DONE|EVENT_USB_ICCD_DETATCH, 
							KAL_OR_CONSUME, &event_group, KAL_NO_SUSPEND);
	}
			
	g_UsbHostIccd[iccd_index].dev_error_count = 0;
	g_UsbHostIccd[iccd_index].config = KAL_TRUE;
	g_UsbHostIccd[iccd_index].dev_attatch = KAL_TRUE;
	g_UsbHostIccd[iccd_index].common_info.usb_ip_port = usb_ip_port;
	g_UsbHostIccd[iccd_index].common_info.if_num = if_num;
	g_UsbHostIccd[iccd_index].sleep_time = USB_HOST_ICCD_SLEEP_TIME;

	/* start timer to check app status */
	start.u2Tick = g_UsbHostIccd[iccd_index].sleep_time;					
  start.pfCallback = USB_Host_ICCD_Sleep_Timeout;			
  start.vPara = &g_UsbHostIccd[iccd_index];							
  DclSGPT_Control((DCL_HANDLE)(g_UsbHostIccd[iccd_index].sleep_timer_handle), SGPT_CMD_START, (DCL_CTRL_DATA_T*)&start);		
//	GPTI_StartItem(g_UsbHostIccd[iccd_index].sleep_timer_handle, g_UsbHostIccd[iccd_index].sleep_time,USB_Host_ICCD_Sleep_Timeout, &g_UsbHostIccd[iccd_index]);

	
	/* notify SIM Driver to start ICCD state machine*/
	kal_set_eg_events(g_UsbHostIccd[iccd_index].start_event_id, EVENT_ICUSB_ENUMERATION_DONE, KAL_OR);		

//1.  Remove PHY Pull up resistor   2. Disable Connect / Disconnect interrupt
//=======================  UT  =============
	/* notify SIM Driver to start ICCD state machine*/
//	DRV_BuildPrimitive(usb_ilm, MOD_DRV_HISR,MOD_USB, MSG_ID_USB_ICCD_UT_IND, NULL);
//	msg_send_ext_queue(usb_ilm);
}



static void USB_Host_Iccd_Detach(kal_uint8 usb_ip_port)
{
	kal_uint8 iccd_index = USB_ICCD_Check_index(usb_ip_port);
	DCL_HANDLE handle;
	
	if((g_UsbHostIccd[iccd_index].sleep_timer_handle != 0)&&(g_UsbHostIccd[iccd_index].sleep_timer_handle!= 0x7F))
	{	
		USB_GPTI_ReleaseHandle(&(g_UsbHostIccd[iccd_index].sleep_timer_handle));
//		 	handle = (DCL_HANDLE)g_UsbHostIccd[iccd_index].sleep_timer_handle;
//			g_UsbHostIccd[iccd_index].sleep_timer_handle = DclSGPT_Close(&handle);	
//		GPTI_ReleaseHandle(&g_UsbHostIccd[iccd_index].sleep_timer_handle);
	}
	
	g_UsbHostIccd[iccd_index].dev_attatch = KAL_FALSE;

	/* Wake up waiting task */
	g_UsbHostIccd[iccd_index].ep0_result = USB_HOST_ICCD_RESULT_NO_RESPONSE;
	ICUSB_Dbg_Trace(IC_USB_SET_EVENT,  0, 0);
	kal_set_eg_events(g_UsbHostIccd[iccd_index].event_id, EVENT_USB_ICCD_DETATCH, KAL_OR);


	usb_host_iccd_support_num = 0;
	usb_host_iccd_config_num = 0xFF;
	usb_host_iccd_support_real_num = 0;
	
//	USB_Host_Iccd_Dis_Device(); //QQ

}

static void USB_Host_Iccd_Suspend(kal_uint8 usb_ip_port)
{
	kal_uint8 iccd_index = USB_ICCD_Check_index(usb_ip_port);
}

static void USB_Host_Iccd_Resume(kal_uint8 usb_ip_port)
{
	kal_uint8 iccd_index = USB_ICCD_Check_index(usb_ip_port);
}

USBD_ClassDriver_Struct USB_Host_Iccd_Drv = 
{
	USB_Host_Iccd_Match,
	USB_Host_Iccd_Startup,
	USB_Host_Iccd_Detach,
	USB_Host_Iccd_Suspend,
	USB_Host_Iccd_Resume
};

	

#endif /* __IC_USB_ICCD_SUPPORT__ */

#endif  /* __IC_USB_ENABLE__ */

 
