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
 *    usb_host_ms_drv.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements host mass storage class driver
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
#include "drvsignals.h"
//#include "app_buff_alloc.h"
#include "usb_custom.h"
#include "usbd.h"
#include "intrCtrl.h"
#include "dcl.h"
//#include "stack_common.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "kal_public_api.h" //#include "stack_ltlcom.h" //MSBB change #include "app_ltlcom.h"       /* Task message communiction */
//#include "usb_hcd.h"
#include "dcl.h"
#include "usbms_drv.h"
//#include "usb_drv.h"
#include "usbms_state.h"
#include "usb_host_ms_drv.h"
#include "usb_host_ms_if.h"
//#include "usb_host_ms_custom.h"
#include "usb_host_ms_adap.h"
#include "usb_debug_tool.h"
#include "usb_trc.h"
//#include "kal_non_specific_general_types.h"
//#include "kal_release.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "kal_public_api.h" //#include "stack_ltlcom.h"
#include "kal_trace.h"
#include "kal_public_defs.h"
#include "kal_general_types.h"
#include "usb.h"
#include "kal_public_api.h"
#include "kal_public_defs.h"
/* for debug only*/
//#include "usb_hcd_pri.h"
//extern USB_HCD_Struct g_UsbHcdInfo;



/* The command and data (except read and write use this shared buffer) */
/* Only one command and one data will be executed at one time */
#pragma arm section zidata = "NONCACHEDZI",  rwdata = "NONCACHEDRW"
__align(4) static kal_uint8 g_usb_ms_cmd[USBMS_MAX_CMD_LEN];
__align(4) static kal_uint8 g_usb_ms_data[USBMS_MAX_DATA_LEN];
#pragma arm section zidata, rwdata

kal_uint8 USBHost_Media_Handle[USB_HOST_MS_SUPPORT_LUN];
static kal_bool g_usb_send_card_plug_in = KAL_FALSE;

static kal_uint8 usb_host_ms_support_num = 0;
static kal_uint8 usb_host_ms_config_num = 0xFF;
static kal_uint8 usb_host_ms_support_real_num = 0;

static void USB_Host_Ms_Detach(kal_uint8 usb_ip_port);

static kal_bool USB_Host_Ms_Send_Cmd(kal_uint8 ms_index,USBH_Ms_Cmd_Struct *ms_cmd);
static void USB_Host_Ms_Hdlr(kal_uint8 usb_ip_port, USB_HCD_STATUS result, kal_uint32 param);
static void USB_Host_Ms_State_Hdlr(kal_uint8 usb_ip_port, USB_HCD_STATUS result, kal_uint32 param);
static void USB_Host_Ms_Ctrl_EP_Hdlr(kal_uint8 ms_index,USB_HCD_STATUS result, kal_uint32 param);
static void USB_Host_Ms_Bulk_EP_Hdlr(kal_uint8 ms_index,USB_HCD_STATUS result, kal_uint32 param);
static void USB_Host_Ms_CBW_Hdler(kal_uint8 ms_index,USB_HCD_STATUS result, kal_uint32 param);
static void USB_Host_Ms_DATA_Hdler(kal_uint8 ms_index,USB_HCD_STATUS result, kal_uint32 param);
static void USB_Host_Ms_CSW_Hdler(kal_uint8 ms_index,USB_HCD_STATUS result, kal_uint32 param);


#pragma arm section zidata = "NONCACHEDZI",  rwdata = "NONCACHEDRW"
__align(4) USB_Host_Ms_Struct g_UsbHostMs[USB_MAX_MS_NUM];
#pragma arm section zidata, rwdata

extern const kal_uint8  USB_IRQ_MAP[USB_IP_NUM];

/************************************************************
	MS class register functions (match, startup, detatch)
*************************************************************/

kal_uint8 USB_MS_Check_index(kal_uint8 usb_ip_port)
{
	kal_uint8 index;
	for (index = 0; index< USB_MAX_MS_NUM; index++)
	{
		if (usb_ip_port == g_UsbHostMs[index].common_info.usb_ip_port)
			return index;
	}

	 // no matching 
	 ASSERT(0);
	 
	 return 0;
}

 void USB_Host_Ms_Sleep_Timeout(void *parameter)
{
	USB_Host_Ms_Struct  *ms_temp = (USB_Host_Ms_Struct *)parameter;
	kal_uint8 usb_ip_port = ms_temp->common_info.usb_ip_port ;	
	kal_uint8 ms_index = USB_MS_Check_index(usb_ip_port);

//	DclSGPT_Control((DCL_HANDLE)(g_UsbHostMs[ms_index].sleep_timer_handle), SGPT_CMD_STOP, 0);	
	USB_GPTI_StopItem(g_UsbHostMs[ms_index].sleep_timer_handle);

	/* If device is plugged out, do not send this message */
	if(g_UsbHostMs[ms_index].dev_attatch == KAL_TRUE)
	{
		USBD_Suspend_Req(g_UsbHostMs[ms_index].common_info);
	}
}

/* If current we can support, we choose the largest one we can support, or we choose the smallest one */

static kal_bool	USB_Host_Ms_Match(kal_uint8 usb_ip_port,USBD_Desc_Info *p_desc_info, kal_uint32 cfg_num, kal_uint32 if_num)
{	
	kal_bool b_match = KAL_FALSE;
	kal_uint32 index;
	kal_uint8 temp_ep;
//	kal_uint16 temp_packet;



	if((p_desc_info->dev_desc.bDeviceClass == USB_MS_DEVICE_CODE)||(p_desc_info->dev_desc.bDeviceClass == USB_COMPOSITE_NO_IAD_DEVICE_CODE))
	{
		if((p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_interface_desc->bInterfaceClass == USB_MS_INTERFACE_CLASS_CODE)
			&& ((p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_interface_desc->bInterfaceSubClass == USB_MS_INTERFACE_SUBCLASS_CODE)
			|| (p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_interface_desc->bInterfaceSubClass == USB_MS_INTERFACE_SUBCLASS_CODE_2))
			&& (p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_interface_desc->bInterfaceProtocol == USB_MS_INTERFACE_PROTOCOL_CODE))
		{
		
			b_match = KAL_TRUE;

			/* Check endpoint */
			for(index = 0; index < p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->ep_number; index++)
			{
				if(((p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_ep_info[index]->p_stdep->bEndpointAddress&USB_EP_DIR) == USB_EP_DIR_IN)
					&& (p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_ep_info[index]->p_stdep->bmAttributes == USB_EP_BULK))
				{
					temp_ep = p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_ep_info[index]->p_stdep->bEndpointAddress&(~USB_EP_DIR);
//						temp_packet = p_desc_info->cfg_info[index].p_interface_info[index3]->p_ep_info[index2]->p_stdep->wMaxPacketSize[0]
//										+ (p_desc_info->cfg_info[index].p_interface_info[index3]->p_ep_info[index2]->p_stdep->wMaxPacketSize[1]<<8);

					/* endpoint initialize check FIFO size and endpont number */
					if(temp_ep > MAX_RX_EP_NUM)
						b_match  = KAL_FALSE;
				}
				else if(((p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_ep_info[index]->p_stdep->bEndpointAddress & USB_EP_DIR) == USB_EP_DIR_OUT)
					&& (p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_ep_info[index]->p_stdep->bmAttributes == USB_EP_BULK))
				{
					temp_ep = p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_ep_info[index]->p_stdep->bEndpointAddress&(~USB_EP_DIR);
//						temp_packet  = p_desc_info->cfg_info[index].p_interface_info[index3]->p_ep_info[index2]->p_stdep->wMaxPacketSize[0]
//										+ (p_desc_info->cfg_info[index].p_interface_info[index3]->p_ep_info[index2]->p_stdep->wMaxPacketSize[1]<<8);

					if(temp_ep  > MAX_TX_EP_NUM)
						b_match = KAL_FALSE;
				}
			}
		}
	}

// check SW resource

	if(b_match == KAL_TRUE)
	{
		if (usb_host_ms_config_num != cfg_num)
		{
			usb_host_ms_config_num = cfg_num;
			usb_host_ms_support_num = 1;
	}
	else
	{
			usb_host_ms_support_num  ++;
	}
		
		if (usb_host_ms_support_num  > USB_MAX_MS_NUM)
			b_match = KAL_FALSE;
}

	return b_match;
}




static void USB_Host_Ms_Startup(kal_uint8 usb_ip_port, USBD_Desc_Info *p_desc_info, kal_uint32 cfg_num, kal_uint32 if_num)
{
	kal_uint8 index;
	kal_uint8 ms_index;
//	ilm_struct *usb_ilm = NULL;
	kal_uint32 event_group;
	usb_host_usbattach_ind_struct *usb_host_attach;

	usb_host_ms_support_real_num ++;
	if (usb_host_ms_support_real_num  > USB_MAX_MS_NUM)
		ASSERT(0);
	
	ms_index = usb_host_ms_support_real_num-1;

	/* Check endpoint */	
	for(index = 0; index < p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->ep_number; index++)
	{
		if(((p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_ep_info[index]->p_stdep->bEndpointAddress&USB_EP_DIR) == USB_EP_DIR_IN)
			&& (p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_ep_info[index]->p_stdep->bmAttributes == USB_EP_BULK))
		{
			g_UsbHostMs[ms_index].ep_rx_info.ep_real_num  = p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_ep_info[index]->p_stdep->bEndpointAddress&(~USB_EP_DIR);
			g_UsbHostMs[ms_index].ep_rx_info.ep_max_pkt_size = p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_ep_info[index]->p_stdep->wMaxPacketSize[0]
							+ (p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_ep_info[index]->p_stdep->wMaxPacketSize[1]<<8);
		}
		else if(((p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_ep_info[index]->p_stdep->bEndpointAddress & USB_EP_DIR) == USB_EP_DIR_OUT)
			&& (p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_ep_info[index]->p_stdep->bmAttributes == USB_EP_BULK))
		{
			g_UsbHostMs[ms_index].ep_tx_info.ep_real_num= p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_ep_info[index]->p_stdep->bEndpointAddress&(~USB_EP_DIR);
			g_UsbHostMs[ms_index].ep_tx_info.ep_max_pkt_size = p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_ep_info[index]->p_stdep->wMaxPacketSize[0]
							+ (p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_ep_info[index]->p_stdep->wMaxPacketSize[1]<<8);
		}
	}


	if(((USBD_Is_High_Speed(g_UsbHostMs[ms_index].common_info) == KAL_TRUE)&&(g_UsbHostMs[ms_index].ep_rx_info.ep_max_pkt_size > USB_EP_BULK_MAXP_HS))
		||((USBD_Is_High_Speed(g_UsbHostMs[ms_index].common_info) == KAL_FALSE)&&(g_UsbHostMs[ms_index].ep_rx_info.ep_max_pkt_size > USB_EP_BULK_MAXP_FS)))
	{
		EXT_ASSERT(0, USBD_Is_High_Speed(g_UsbHostMs[ms_index].common_info), g_UsbHostMs[ms_index].ep_rx_info.ep_max_pkt_size, 0);
	}
	
	if(((USBD_Is_High_Speed(g_UsbHostMs[ms_index].common_info) == KAL_TRUE)&&(g_UsbHostMs[ms_index].ep_tx_info.ep_max_pkt_size > USB_EP_BULK_MAXP_HS))
		||((USBD_Is_High_Speed(g_UsbHostMs[ms_index].common_info) == KAL_FALSE)&&(g_UsbHostMs[ms_index].ep_tx_info.ep_max_pkt_size > USB_EP_BULK_MAXP_FS)))
	{
		EXT_ASSERT(0, USBD_Is_High_Speed(g_UsbHostMs[ms_index].common_info), g_UsbHostMs[ms_index].ep_tx_info.ep_max_pkt_size, 0);
	}

	g_UsbHostMs[ms_index].common_info.usb_ip_port = usb_ip_port;
	g_UsbHostMs[ms_index].common_info.if_num = if_num;
		
	g_UsbHostMs[ms_index].ep_rx_info.ep_num= USBD_HW_Mapping_EP(g_UsbHostMs[ms_index].common_info,USB_EP_RX_DIR);
	g_UsbHostMs[ms_index].ep_rx_info.direction = USB_EP_RX_DIR;
	g_UsbHostMs[ms_index].ep_rx_info.ep_type= USB_ENDPT_BULK;

	g_UsbHostMs[ms_index].ep_tx_info.ep_num= USBD_HW_Mapping_EP(g_UsbHostMs[ms_index].common_info,USB_EP_TX_DIR);	
	g_UsbHostMs[ms_index].ep_tx_info.direction = USB_EP_TX_DIR;
	g_UsbHostMs[ms_index].ep_tx_info.ep_type= USB_ENDPT_BULK;

	g_UsbHostMs[ms_index].total_lun = 0;
	g_UsbHostMs[ms_index].media_handle = USBHost_Media_Handle;
	g_UsbHostMs[ms_index].sleep_time = USB_HOST_MS_SLEEP_TIME;

	g_UsbHostMs[ms_index].dev_error_count = 0;
	g_UsbHostMs[ms_index].dev_state = USB_HOST_MS_DEV_STATE_READY;
	g_UsbHostMs[ms_index].dev_attatch = KAL_TRUE;

	USB_Host_Ms_Get_Media_Resource(ms_index);

	for(index = 0; index < USB_HOST_MS_SUPPORT_LUN; index++)
	{
		/* Initailize media handle */
		g_UsbHostMs[ms_index].media_handle[index] = index;
		g_UsbHostMs[ms_index].media_msg_array[index] = NULL;
		g_UsbHostMs[ms_index].media_info[index].pre_state = USB_HOST_MS_MEDIA_STATE_ABSENT;
	}

	USBD_RxEPInit(g_UsbHostMs[ms_index].common_info,g_UsbHostMs[ms_index].ep_rx_info);
	USBD_TxEPInit(g_UsbHostMs[ms_index].common_info,g_UsbHostMs[ms_index].ep_tx_info);

	USBD_Set_EP_Max_Pkt(g_UsbHostMs[ms_index].common_info,g_UsbHostMs[ms_index].ep_rx_info);
	USBD_Set_EP_Max_Pkt(g_UsbHostMs[ms_index].common_info,g_UsbHostMs[ms_index].ep_tx_info);

	USBD_Register_Drv_Info(g_UsbHostMs[ms_index].common_info,USB_HCD_HDLR_EP_RX, g_UsbHostMs[ms_index].ep_rx_info, USB_Host_Ms_State_Hdlr);
	USBD_Register_Drv_Info(g_UsbHostMs[ms_index].common_info,USB_HCD_HDLR_EP_TX, g_UsbHostMs[ms_index].ep_tx_info, USB_Host_Ms_State_Hdlr);

	/* 4 seconds */
	USBD_RxEPEn(g_UsbHostMs[ms_index].common_info,g_UsbHostMs[ms_index].ep_rx_info,16, KAL_TRUE); 

	/* 4 seconds */
	USBD_TxEPEn(g_UsbHostMs[ms_index].common_info,g_UsbHostMs[ms_index].ep_tx_info,16, KAL_TRUE); 

	USBD_Get_DMA_Channel(g_UsbHostMs[ms_index].common_info,g_UsbHostMs[ms_index].ep_tx_info, g_UsbHostMs[ms_index].ep_rx_info, USB_EP_TX_DIR, KAL_TRUE);

	if(g_UsbHostMs[ms_index].event_id != 0)
	{
		/* Receive all events that may exist after previous detatch */
		kal_retrieve_eg_events(g_UsbHostMs[ms_index].event_id, EVENT_USB_MS_DONE|EVENT_USB_MS_DETATCH, 
							KAL_OR_CONSUME, &event_group, KAL_NO_SUSPEND);
	}

	/* Send message to USB task */
	usb_host_attach = (usb_host_usbattach_ind_struct*)construct_local_para(sizeof(usb_host_usbattach_ind_struct), TD_CTRL);
	usb_host_attach->feature_index = ms_index;
	
	/* send msg to USB task, start ms state machine */
	
	USB_Send_Msg_Ext_Queue(MOD_USB, MSG_ID_USB_MSHOST_START_IND, usb_host_attach);
//	DRV_BuildPrimitive(usb_ilm, stack_get_active_module_id(),MOD_USB, MSG_ID_USB_MSHOST_START_IND, usb_host_attach);
//	msg_send_ext_queue(usb_ilm);

	/* Send to FMT */
	USB_Host_Ms_SendInd(ms_index,USB_HOST_MS_MSG_PLUG_IN);
	
	g_usb_send_card_plug_in = KAL_TRUE;
	
}


static void USB_Host_Ms_Detach(kal_uint8 usb_ip_port)
{
	kal_uint32 index;
	kal_uint8 ms_index = USB_MS_Check_index(usb_ip_port);

	//DclSGPT_Control((DCL_HANDLE)(g_UsbHostMs[ms_index].gpt_handle), SGPT_CMD_STOP, 0);	
	USB_GPTI_StopItem(g_UsbHostMs[ms_index].gpt_handle);	
	//DclSGPT_Control((DCL_HANDLE)(g_UsbHostMs[ms_index].sleep_timer_handle), SGPT_CMD_STOP, 0);	
	USB_GPTI_StopItem(g_UsbHostMs[ms_index].sleep_timer_handle);	
	

	USBD_Free_DMA_Channel(g_UsbHostMs[ms_index].common_info,g_UsbHostMs[ms_index].ep_tx_info, g_UsbHostMs[ms_index].ep_rx_info, USB_EP_TX_DIR, KAL_TRUE);
	USBD_TxEPDis(g_UsbHostMs[ms_index].common_info,g_UsbHostMs[ms_index].ep_tx_info, KAL_FALSE);
	USBD_RxEPDis(g_UsbHostMs[ms_index].common_info,g_UsbHostMs[ms_index].ep_rx_info, KAL_FALSE);

	if(g_UsbHostMs[ms_index].media_info != NULL)
	{
		for(index = 0; index < g_UsbHostMs[ms_index].total_lun; index++)
		{
			/* If original state is READY, set state change as true */
			if(((g_UsbHostMs[ms_index].media_info[index].state == USB_HOST_MS_MEDIA_STATE_WR_PROTECT)
				||(g_UsbHostMs[ms_index].media_info[index].state == USB_HOST_MS_MEDIA_STATE_READY))
				&& (g_UsbHostMs[ms_index].media_info[index].sec_size != 0))
			{
				g_UsbHostMs[ms_index].media_state_change |= (1<<index);
			}

			/* Set all the media state to absent */
			g_UsbHostMs[ms_index].media_info[index].state = USB_HOST_MS_MEDIA_STATE_ABSENT;
		}
	}

	g_UsbHostMs[ms_index].dev_attatch = KAL_FALSE;

	/* Wake up waiting task */
	g_UsbHostMs[ms_index].result = USB_HOST_MS_RESULT_NO_RESPONSE;
	USB_Dbg_Trace(USB_HOST_SET_EVENT, 0, 0);
	kal_set_eg_events(g_UsbHostMs[ms_index].event_id, EVENT_USB_MS_DETATCH, KAL_OR);

	USBD_Dis_Attach(g_UsbHostMs[ms_index].common_info);

	drv_trace1(TRACE_FUNC, (kal_uint32)USB_HOST_MS_CHECK_MEDIA_STATE, g_UsbHostMs[ms_index].media_state_change);
	USB_Dbg_Trace(USB_HOST_MS_REPORT_MEDIA_STATE,
		g_UsbHostMs[ms_index].media_state_change, (kal_uint32)g_UsbHostMs[ms_index].b_sending_change_ilm);

	if(g_usb_send_card_plug_in == KAL_TRUE)
	{
		g_usb_send_card_plug_in = KAL_FALSE;

		if(g_UsbHostMs[ms_index].b_sending_change_ilm == KAL_FALSE)
		{
			/* Notify FMT about media change */
			if(g_UsbHostMs[ms_index].media_state_change != 0)
			{
				USB_Host_Ms_Check_Media_State(ms_index);
			}
		}

		USB_Host_Ms_SendInd(ms_index,USB_HOST_MS_MSG_PLUG_OUT);
	}

	usb_host_ms_support_num = 0;
	usb_host_ms_config_num = 0xFF;
	usb_host_ms_support_real_num = 0;
	
}


static void USB_Host_Ms_Suspend(kal_uint8 usb_ip_port)
{
//	kal_uint8 ms_index = USB_MS_Check_index(usb_ip_port);
//	if (g_UsbHostMs[ms_index].suspend_state == KAL_TRUE)
//		ASSERT(0);
}


static void USB_Host_Ms_Resume(kal_uint8 usb_ip_port)
{
//	kal_uint8 ms_index = USB_MS_Check_index(usb_ip_port);
//	g_UsbHostMs[ms_index].suspend_state = KAL_FALSE;
}



USBD_ClassDriver_Struct USB_Host_Ms_Drv =
{
	USB_Host_Ms_Match,
	USB_Host_Ms_Startup,
	USB_Host_Ms_Detach,
	USB_Host_Ms_Suspend,
	USB_Host_Ms_Resume
};

/************************************************************
	ms utilities (send msg to FMT task. Indicate card status change)
*************************************************************/

/* Send card change indication to FMT task */
void USB_Host_Ms_SendInd(kal_uint8 ms_index,USB_HOST_MS_MSG_TYPE msg)
{
#ifndef __MEUT__
//	ilm_struct *usb_ilm = NULL;
	usb_host_ms_media_struct *change_ind;
	usb_host_ms_drive_struct *drive_ind;
//	module_type 	src_mod;

//	PW_CTRL_IS_USB_BOOT CtrlVal;
//	DCL_HANDLE handle;

// 	handle=DclPW_Open(DCL_PW, FLAGS_NONE);
//	DclPW_Control(handle, PW_CMD_IS_USB_BOOT,(DCL_CTRL_DATA_T *)&CtrlVal);
//	DclPW_Close(handle);

//	if(CtrlVal.val == KAL_TRUE)  // USB Bootup mode doesn't have FMT 
//		return;

	if(USBD_Bootup_Mode() == KAL_TRUE)  // USB Bootup mode doesn't have FMT 
		return;

//	if(kal_if_hisr() == KAL_TRUE)
//		src_mod = MOD_DRV_HISR;
//	else
//		src_mod = MOD_USB;

//	src_mod = stack_get_active_module_id();

	switch(msg)
	{
	case USB_HOST_MS_MSG_MEDIA_CHANGE:
		if(g_UsbHostMs[ms_index].b_sending_change_ilm == KAL_TRUE)
			ASSERT(0);
		g_UsbHostMs[ms_index].b_sending_change_ilm = KAL_TRUE;

		change_ind = (usb_host_ms_media_struct*)construct_local_para(
						sizeof(usb_host_ms_media_struct) + (sizeof(kal_uint32*)*g_UsbHostMs[ms_index].total_lun-1), TD_CTRL);

		change_ind->media_size = g_UsbHostMs[ms_index].total_lun;
		kal_mem_cpy(&change_ind->media_array, g_UsbHostMs[ms_index].media_msg_array, sizeof(kal_uint32*)*g_UsbHostMs[ms_index].total_lun);


		USB_Send_Msg_Ext_Queue(MOD_FMT,MSG_ID_OTG_CARD_DETECT_IND,change_ind);

//		DRV_BuildPrimitive(usb_ilm,src_mod,MOD_FMT,MSG_ID_OTG_CARD_DETECT_IND,change_ind);
//		msg_send_ext_queue(usb_ilm);
		break;

		/* sent only when device connect */
	case USB_HOST_MS_MSG_PLUG_IN:
		drive_ind = (usb_host_ms_drive_struct*)construct_local_para(
							sizeof(usb_host_ms_drive_struct), TD_CTRL);
		drive_ind->drive = (void*)&FS_OTGDrv;
		drive_ind->media_size = g_UsbHostMs[ms_index].total_lun;

		USB_Send_Msg_Ext_Queue(MOD_FMT,MSG_ID_OTG_MS_INSERT_IND,drive_ind);

//		DRV_BuildPrimitive(usb_ilm,MOD_DRV_HISR,MOD_FMT,MSG_ID_OTG_MS_INSERT_IND,drive_ind);
//		msg_send_ext_queue(usb_ilm);
		break;

	case USB_HOST_MS_MSG_PLUG_OUT:
		if(g_UsbHostMs[ms_index].b_sending_plugout_ilm == KAL_TRUE)
			ASSERT(0);
		g_UsbHostMs[ms_index].b_sending_plugout_ilm = KAL_TRUE;

		drive_ind = (usb_host_ms_drive_struct*)construct_local_para(
							sizeof(usb_host_ms_drive_struct), TD_CTRL);
		drive_ind->drive = (void*)&FS_OTGDrv;
		drive_ind->media_size = g_UsbHostMs[ms_index].total_lun;

		USB_Send_Msg_Ext_Queue(MOD_FMT,MSG_ID_OTG_MS_REMOVE_IND,drive_ind);

//		DRV_BuildPrimitive(usb_ilm,src_mod,MOD_FMT,MSG_ID_OTG_MS_REMOVE_IND,drive_ind);
//		msg_send_ext_queue(usb_ilm);
		break;

	default:
		EXT_ASSERT(0, (kal_uint32)msg, (kal_uint32)g_UsbHostMs[ms_index].dev_state, 0);
		break;
	}
#endif /* __MEUT__ */
}


void USB_Host_Ms_Get_Media_Resource(kal_uint8 ms_index)
{
	if(g_UsbHostMs[ms_index].media_info == NULL)
		g_UsbHostMs[ms_index].media_info =(USBH_Ms_Media_Struct*)USB_Get_Memory(sizeof(USBH_Ms_Media_Struct)*USB_HOST_MS_SUPPORT_LUN);//(USBH_Ms_Media_Struct*)get_ctrl_buffer(sizeof(USBH_Ms_Media_Struct)*USB_HOST_MS_SUPPORT_LUN);

	if(g_UsbHostMs[ms_index].media_msg_array == NULL)
		g_UsbHostMs[ms_index].media_msg_array = (kal_uint32*)USB_Get_Memory(sizeof(kal_uint32)*USB_HOST_MS_SUPPORT_LUN);//get_ctrl_buffer(sizeof(kal_uint32)*USB_HOST_MS_SUPPORT_LUN);

	if(g_UsbHostMs[ms_index].buffer_address == NULL)
		g_UsbHostMs[ms_index].buffer_address = (kal_uint8*)USB_Get_Memory(sizeof(kal_uint8)*USB_HOST_MS_RW_MAX_DCACHE_SEC_LEN*512);
}


void USB_Host_Ms_Free_Media_Resource(kal_uint8 ms_index)
{

//	free_ctrl_buffer((USBH_Ms_Media_Struct*)g_UsbHostMs[ms_index].media_info);
	g_UsbHostMs[ms_index].media_info = NULL;

//	free_ctrl_buffer((kal_uint32*)g_UsbHostMs[ms_index].media_msg_array);
	g_UsbHostMs[ms_index].media_msg_array = NULL;

	g_UsbHostMs[ms_index].buffer_address = NULL;

}





void USB_Host_Ms_En_Device(USBH_Common_Struct common_str)
{
	USBD_En_Attach(common_str);
}



void USB_Host_Ms_Check_Media_State(kal_uint8 ms_index)
{
	kal_uint32 index;
	kal_bool b_send_msg = KAL_FALSE;


	for(index = 0; index < g_UsbHostMs[ms_index].total_lun; index++)
	{
		if((g_UsbHostMs[ms_index].media_state_change&(1<<index)) != 0)
		{
			if(g_UsbHostMs[ms_index].media_info[index].state != g_UsbHostMs[ms_index].media_info[index].pre_state)
			{
				drv_trace1(TRACE_FUNC, (kal_uint32)USB_HOST_MS_MEDIA_STATE_CHANGE, index);
				g_UsbHostMs[ms_index].media_info[index].pre_state = g_UsbHostMs[ms_index].media_info[index].state;
				g_UsbHostMs[ms_index].media_msg_array[index] = (kal_uint32)&g_UsbHostMs[ms_index].media_handle[index];
				b_send_msg = KAL_TRUE;
			}
			else
			{
				g_UsbHostMs[ms_index].media_msg_array[index] = NULL;
			}
		}
		else
		{
			g_UsbHostMs[ms_index].media_msg_array[index] = NULL;
		}
	}

	g_UsbHostMs[ms_index].media_state_change = 0;

	if(b_send_msg == KAL_TRUE)
	{
		/* Send message to FMT task about card state change */
		USB_Host_Ms_SendInd(ms_index,USB_HOST_MS_MSG_MEDIA_CHANGE);
	}
}


static void USB_Host_Ms_Update_Media_State(USB_HOST_MS_MEDIA_STATE media_state, kal_uint8 lun)
{
	/*
	If state changes from :
	1. absent to state change,
	2. absent to error,
	3. error to absent
	4. change to absent since state from ready to change had report it
	do no notify FMT.
	Otherwise some mass storage may first mount fail, and then success,
	user may see plug out and then plug in or plug out twice
	*/
	kal_uint8  ms_index = USB_MS_IP_Query(lun);

	if(media_state != g_UsbHostMs[ms_index].media_info[lun].state)
	{
		if(((media_state == USB_HOST_MS_MEDIA_STATE_ABSENT)&&
			((g_UsbHostMs[ms_index].media_info[lun].state == USB_HOST_MS_MEDIA_STATE_CHANGED)||
			(g_UsbHostMs[ms_index].media_info[lun].state == USB_HOST_MS_MEDIA_STATE_ERROR)))
			||
			(((media_state == USB_HOST_MS_MEDIA_STATE_ERROR)||(media_state == USB_HOST_MS_MEDIA_STATE_CHANGED))
			&&(g_UsbHostMs[ms_index].media_info[lun].state == USB_HOST_MS_MEDIA_STATE_ABSENT)))
		{

		}
		else
		{
			g_UsbHostMs[ms_index].media_state_change |= (1<<lun);
		}
	}
}

kal_uint8 USB_MS_IP_Query(kal_uint8 lun)
{
	kal_uint8 ms_index;

	for (ms_index=0 ; ms_index < USB_MAX_MS_NUM ; ms_index++)
	{
		if (lun < g_UsbHostMs[ms_index].total_lun)
			break;
		else
			lun = lun - g_UsbHostMs[ms_index].total_lun; 
	}
	
	return  0;//ms_index;
	
}

 /************************************************************
	ms class ep0 class specific functions (Control endpoint functions)
*************************************************************/
/* class specific Get LUN request.
     It is a block function, the transfer is completed when return
     Note that this function must be used in task context */
void USB_Host_Ms_Get_LUN(kal_uint8 ms_index)
{
	kal_uint32 event_group;
	Usb_Command usbd_cmd;


	USB_Dbg_Trace(USB_HOST_MS_EP0_GET_LUN,  0, 0);

	usbd_cmd.bmRequestType = USB_CMD_CLASSIFIN;
	usbd_cmd.bRequest = USB_MS_GETMAXLUN;
	usbd_cmd.wValue = 0;
	usbd_cmd.wIndex = 0;
	usbd_cmd.wLength = 1;

	g_UsbHostMs[ms_index].ms_cmd = USB_HOST_MS_EP0_CMD_GET_LUN;

	USBD_Start_Setup_Cmd(g_UsbHostMs[ms_index].common_info, &usbd_cmd, &g_UsbHostMs[ms_index].total_lun, USBD_EP0_DATA_RECV, 1, KAL_TRUE,USB_Host_Ms_Hdlr);

	if(g_UsbHostMs[ms_index].dev_attatch == KAL_TRUE)
	{
		/* wait for transfer complete */
		/* LUN number information is stored in g_UsbHostMs[ms_index] when event is retrieved*/
		kal_retrieve_eg_events(g_UsbHostMs[ms_index].event_id, EVENT_USB_MS_DONE|EVENT_USB_MS_DETATCH, 
						KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
		USB_Dbg_Trace(USB_HOST_RETRIEVE_EVENT, 0, 0);

		/* Device status is error if result not OK in EP0 command */
		if(g_UsbHostMs[ms_index].result == USB_HOST_MS_RESULT_OK)
			g_UsbHostMs[ms_index].dev_state = USB_HOST_MS_DEV_STATE_READY;
		else
			g_UsbHostMs[ms_index].dev_state = USB_HOST_MS_DEV_STATE_ERROR;
	}
}


/* class specific reset request, not the whole device reset */
void USB_Host_Ms_Reset(kal_uint8 ms_index)
{
	kal_uint32 event_group;
	Usb_Command usbd_cmd;

	USB_Dbg_Trace(USB_HOST_MS_EP0_RESET,  0, 0);

	usbd_cmd.bmRequestType = USB_CMD_CLASSIFOUT;
	usbd_cmd.bRequest = USB_MS_RESET;
	usbd_cmd.wValue = 0;
	usbd_cmd.wIndex = 0;
	usbd_cmd.wLength = 0;

	g_UsbHostMs[ms_index].ms_cmd = USB_HOST_MS_EP0_CMD_RESET;

	USBD_Start_Setup_Cmd(g_UsbHostMs[ms_index].common_info, &usbd_cmd, &g_UsbHostMs[ms_index].total_lun, USBD_EP0_DATA_NULL, 0, KAL_TRUE,USB_Host_Ms_Hdlr);

	if(g_UsbHostMs[ms_index].dev_attatch == KAL_TRUE)
	{
		/* wait for transfer complete */
		kal_retrieve_eg_events(g_UsbHostMs[ms_index].event_id, EVENT_USB_MS_DONE|EVENT_USB_MS_DETATCH, 
						KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
		USB_Dbg_Trace(USB_HOST_RETRIEVE_EVENT, 0, 0);

		/* Device status is error if result not OK in EP0 command */
		if(g_UsbHostMs[ms_index].result == USB_HOST_MS_RESULT_OK)
			g_UsbHostMs[ms_index].dev_state = USB_HOST_MS_DEV_STATE_READY;
		else
			g_UsbHostMs[ms_index].dev_state = USB_HOST_MS_DEV_STATE_ERROR;
	}
}


/************************************************************
	ms class state functions (Bulk endpoint functions)
*************************************************************/

/* REQUEST SENSE command (03h)*/
USB_HOST_MS_RESULT USB_Host_Ms_Request_Sense(kal_uint8 lun)
{
	kal_bool b_send_result;
	kal_uint32 event_group;
	kal_uint8  ms_index = USB_MS_IP_Query(lun);
	USB_HOST_MS_MEDIA_STATE media_state = g_UsbHostMs[ms_index].media_info[lun].state;


	USB_Dbg_Trace(USB_HOST_MS_REQUEST_SENSE_1, lun, 0);
	kal_mem_set(g_usb_ms_cmd, 0, USBMS_MAX_CMD_LEN);
	g_usb_ms_cmd[0] = USBMS_REQUESTSENSE;
	g_usb_ms_cmd[4] = USBMS_REQUESTSENSE_DATA_LEN;

	g_UsbHostMs[ms_index].ms_cmd_data.lun = lun;
	g_UsbHostMs[ms_index].ms_cmd_data.cmd_len = USBMS_REQUESTSENSE_CMD_LEN;
	g_UsbHostMs[ms_index].ms_cmd_data.cmd_buff = g_usb_ms_cmd;
	g_UsbHostMs[ms_index].ms_cmd_data.data_len = USBMS_REQUESTSENSE_DATA_LEN;
	g_UsbHostMs[ms_index].ms_cmd_data.data_buff = g_usb_ms_data;
	g_UsbHostMs[ms_index].ms_cmd_data.data_dir = USB_HOST_MS_DATA_RECV;

	b_send_result = USB_Host_Ms_Send_Cmd(ms_index,&g_UsbHostMs[ms_index].ms_cmd_data);

	if((b_send_result == KAL_TRUE) && (g_UsbHostMs[ms_index].dev_attatch == KAL_TRUE))
	{
		/* when event is retrived, result has been got in data buffer  */
		kal_retrieve_eg_events(g_UsbHostMs[ms_index].event_id, EVENT_USB_MS_DONE|EVENT_USB_MS_DETATCH, 
						KAL_OR_CONSUME, &event_group, KAL_SUSPEND);

		USB_Dbg_Trace(USB_HOST_MS_REQUEST_SENSE_2,  (kal_uint32)g_UsbHostMs[ms_index].result, 0);

		if(g_UsbHostMs[ms_index].result == USB_HOST_MS_RESULT_OK)
		{
			/* translate sense data to media state */
			if(g_usb_ms_data[2] == 0x00)
			{
				drv_trace1(TRACE_FUNC, (kal_uint32)USB_HOST_MS_REQUEST_SENSE_OK, lun);

				/* USB_STORAGE_DEV_STATUS_OK or USB_STORAGE_DEV_STATUS_WP */
				if(g_UsbHostMs[ms_index].media_info[lun].state!=USB_HOST_MS_MEDIA_STATE_WR_PROTECT)
					g_UsbHostMs[ms_index].media_info[lun].state = USB_HOST_MS_MEDIA_STATE_READY;
			}
			else if(g_usb_ms_data[2] == 0x06)
			{
				drv_trace1(TRACE_FUNC, (kal_uint32)USB_HOST_MS_REQUEST_SENSE_MEDIA_CHANGE, lun);

				/* USB_STORAGE_DEV_STATUS_MEDIA_CHANGE */
				g_UsbHostMs[ms_index].media_info[lun].state = USB_HOST_MS_MEDIA_STATE_CHANGED;
				/* update sector size to 0, it should be set in next read capacify command */
				/* it is used in case test unit ready change state to USB_HOST_MS_MEDIA_STATE_READY,
				    but read capacity is not yet issued */
				g_UsbHostMs[ms_index].media_info[lun].sec_size = 0;
			}
			else if(g_usb_ms_data[2] ==0x02)
			{
				drv_trace1(TRACE_FUNC, (kal_uint32)USB_HOST_MS_REQUEST_SENSE_ABSENT, lun);

				/* USB_STORAGE_DEV_STATUS_NOMEDIA */
				g_UsbHostMs[ms_index].media_info[lun].state = USB_HOST_MS_MEDIA_STATE_ABSENT;
				/* update sector size to 0, it should be set in next read capacify command */
				g_UsbHostMs[ms_index].media_info[lun].sec_size = 0;
			}
			else
			{
				drv_trace1(TRACE_FUNC, (kal_uint32)USB_HOST_MS_REQUEST_SENSE_ERROR, lun);

				g_UsbHostMs[ms_index].media_info[lun].state = USB_HOST_MS_MEDIA_STATE_ERROR;
				/* update sector size to 0, it should be set in next read capacify command */
				g_UsbHostMs[ms_index].media_info[lun].sec_size = 0;
			}
		}
		else if(g_UsbHostMs[ms_index].result == USB_HOST_MS_RESULT_CSW_FAIL)
		{
			/* Do not request sense again to avoid looping */
		}

		USB_Host_Ms_Update_Media_State(media_state, lun);
	}
	else
	{
		USB_Dbg_Trace(USB_HOST_MS_REQUEST_SENSE_3,  (kal_uint32)g_UsbHostMs[ms_index].result, 0);
		g_UsbHostMs[ms_index].result = USB_HOST_MS_RESULT_NO_RESPONSE;
	}

	return g_UsbHostMs[ms_index].result;
}


/* INQUIRY command (12h) */
USB_HOST_MS_RESULT USB_Host_Ms_Inquiry(kal_uint8 lun)
{
	kal_bool b_send_result;
	kal_uint32 event_group;
	kal_uint8  ms_index = USB_MS_IP_Query(lun);

	USB_Dbg_Trace(USB_HOST_MS_INQUIRY_1, lun, 0);
	kal_mem_set(g_usb_ms_cmd, 0, USBMS_MAX_CMD_LEN);
	g_usb_ms_cmd[0] = USBMS_INQUIRY;
	g_usb_ms_cmd[4] = USBMS_INQUIRY_DATA_LEN;

	g_UsbHostMs[ms_index].ms_cmd_data.lun = lun;
	g_UsbHostMs[ms_index].ms_cmd_data.cmd_len = USBMS_INQUIRY_CMD_LEN;
	g_UsbHostMs[ms_index].ms_cmd_data.cmd_buff = g_usb_ms_cmd;
	g_UsbHostMs[ms_index].ms_cmd_data.data_len = USBMS_INQUIRY_DATA_LEN;
	g_UsbHostMs[ms_index].ms_cmd_data.data_buff = g_usb_ms_data;
	g_UsbHostMs[ms_index].ms_cmd_data.data_dir = USB_HOST_MS_DATA_RECV;

	b_send_result = USB_Host_Ms_Send_Cmd(ms_index,&g_UsbHostMs[ms_index].ms_cmd_data);

#ifdef __USB_OTG_RX_TEST__
  g_UsbHostMs[ms_index].host_ms_rx_test_flag = KAL_TRUE;
#endif

	if((b_send_result == KAL_TRUE)&&(g_UsbHostMs[ms_index].dev_attatch == KAL_TRUE))
	{
		/* when event is retrived, result has been got in data buffer  */
		kal_retrieve_eg_events(g_UsbHostMs[ms_index].event_id, EVENT_USB_MS_DONE|EVENT_USB_MS_DETATCH, 
						KAL_OR_CONSUME, &event_group, KAL_SUSPEND);

		USB_Dbg_Trace(USB_HOST_MS_INQUIRY_2,  (kal_uint32)g_UsbHostMs[ms_index].result, 0);

		if(g_UsbHostMs[ms_index].result == USB_HOST_MS_RESULT_OK)
		{
			kal_mem_cpy(g_UsbHostMs[ms_index].media_info[lun].vendor_info, &g_usb_ms_data[8], USBMS_INQUIRY_VENDOR_INFO_LEN);
			kal_mem_cpy(g_UsbHostMs[ms_index].media_info[lun].product_iden, &g_usb_ms_data[16], USBMS_INQUIRY_PRODUCT_IDEN_LEN);
			kal_mem_cpy(g_UsbHostMs[ms_index].media_info[lun].product_rev, &g_usb_ms_data[32], USBMS_INQUIRY_PRODUCT_REV_LEN);		
		}
		else if(g_UsbHostMs[ms_index].result == USB_HOST_MS_RESULT_CSW_FAIL)
		{
			/* reset venfor and product string info as 0*/
			kal_mem_set(g_UsbHostMs[ms_index].media_info[lun].vendor_info, 0, USBMS_INQUIRY_VENDOR_INFO_LEN);
			kal_mem_set(g_UsbHostMs[ms_index].media_info[lun].product_iden, 0, USBMS_INQUIRY_PRODUCT_IDEN_LEN);
			kal_mem_set(g_UsbHostMs[ms_index].media_info[lun].product_rev, 0, USBMS_INQUIRY_PRODUCT_REV_LEN);	

			/* translate result to request sense result */
			/* application can treat it as result OK is request sense reault is OK */
			g_UsbHostMs[ms_index].result = USB_Host_Ms_Request_Sense(lun);
		}
	}
	else
	{
		USB_Dbg_Trace(USB_HOST_MS_INQUIRY_3,  (kal_uint32)g_UsbHostMs[ms_index].result, 0);
		g_UsbHostMs[ms_index].result = USB_HOST_MS_RESULT_NO_RESPONSE;
	}

	return g_UsbHostMs[ms_index].result;
}


/* READ FORMAT CAPACITY command (23h)*/
USB_HOST_MS_RESULT USB_Host_Ms_Read_Format_Capacity(kal_uint8 lun)
{
	kal_bool b_send_result;
	kal_uint32 event_group;
	kal_uint8  ms_index = USB_MS_IP_Query(lun);

	USB_Dbg_Trace(USB_HOST_MS_READ_FORMAT_CAPACITY_1, lun, 0);
	kal_mem_set(g_usb_ms_cmd, 0, USBMS_MAX_CMD_LEN);
	g_usb_ms_cmd[0] = USBMS_READ_FORMATCAPACITY;
	g_usb_ms_cmd[8] = USBMS_READ_FORMATCAPACITY_DATA_LEN;

	g_UsbHostMs[ms_index].ms_cmd_data.lun = lun;
	g_UsbHostMs[ms_index].ms_cmd_data.cmd_len = USBMS_READ_FORMATCAPACITY_CMD_LEN;
	g_UsbHostMs[ms_index].ms_cmd_data.cmd_buff = g_usb_ms_cmd;
	g_UsbHostMs[ms_index].ms_cmd_data.data_len = USBMS_READ_FORMATCAPACITY_DATA_LEN;
	g_UsbHostMs[ms_index].ms_cmd_data.data_buff = g_usb_ms_data;
	g_UsbHostMs[ms_index].ms_cmd_data.data_dir = USB_HOST_MS_DATA_RECV;

	b_send_result = USB_Host_Ms_Send_Cmd(ms_index,&g_UsbHostMs[ms_index].ms_cmd_data);

	if((b_send_result == KAL_TRUE)&&(g_UsbHostMs[ms_index].dev_attatch == KAL_TRUE))
	{
		/* when event is retrived, result has been got in data buffer  */
		kal_retrieve_eg_events(g_UsbHostMs[ms_index].event_id, EVENT_USB_MS_DONE|EVENT_USB_MS_DETATCH, 
						KAL_OR_CONSUME, &event_group, KAL_SUSPEND);

		USB_Dbg_Trace(USB_HOST_MS_READ_FORMAT_CAPACITY_2,  (kal_uint32)g_UsbHostMs[ms_index].result, 0);

		if(g_UsbHostMs[ms_index].result == USB_HOST_MS_RESULT_CSW_FAIL) 
		{
			/* translate result to request sense result */
			/* application can treat it as result OK is request sense reault is OK */
			g_UsbHostMs[ms_index].result = USB_Host_Ms_Request_Sense(lun);
		}
	}
	else
	{
		USB_Dbg_Trace(USB_HOST_MS_READ_FORMAT_CAPACITY_3,  (kal_uint32)g_UsbHostMs[ms_index].result, 0);
		g_UsbHostMs[ms_index].result = USB_HOST_MS_RESULT_NO_RESPONSE;
	}

	return g_UsbHostMs[ms_index].result;
}


/* READ CAPACITY command (25h)*/
USB_HOST_MS_RESULT USB_Host_Ms_Read_Capacity(kal_uint8 lun)
{
	kal_bool b_send_result;
	kal_uint32 event_group;
	kal_uint8  ms_index = USB_MS_IP_Query(lun);

	USB_Dbg_Trace(USB_HOST_MS_READ_CAPACITY_1, lun, 0);
	kal_mem_set(g_usb_ms_cmd, 0, USBMS_MAX_CMD_LEN);
	g_usb_ms_cmd[0] = USBMS_READ_CAPACITY;

	g_UsbHostMs[ms_index].ms_cmd_data.lun = lun;
	g_UsbHostMs[ms_index].ms_cmd_data.cmd_len = USBMS_READ_CAPACITY_CMD_LEN;
	g_UsbHostMs[ms_index].ms_cmd_data.cmd_buff = g_usb_ms_cmd;
	g_UsbHostMs[ms_index].ms_cmd_data.data_len = USBMS_READ_CAPACITY_DATA_LEN;
	g_UsbHostMs[ms_index].ms_cmd_data.data_buff = g_usb_ms_data;
	g_UsbHostMs[ms_index].ms_cmd_data.data_dir = USB_HOST_MS_DATA_RECV;

	b_send_result = USB_Host_Ms_Send_Cmd(ms_index,&g_UsbHostMs[ms_index].ms_cmd_data);

	if((b_send_result == KAL_TRUE)&&(g_UsbHostMs[ms_index].dev_attatch == KAL_TRUE))
	{
		/* when event is retrived, result has been got in data buffer  */
		kal_retrieve_eg_events(g_UsbHostMs[ms_index].event_id, EVENT_USB_MS_DONE|EVENT_USB_MS_DETATCH, 
						KAL_OR_CONSUME, &event_group, KAL_SUSPEND);

		USB_Dbg_Trace(USB_HOST_MS_READ_CAPACITY_2,  (kal_uint32)g_UsbHostMs[ms_index].result, 0);

		if(g_UsbHostMs[ms_index].result == USB_HOST_MS_RESULT_OK)
		{
			/* store sector size and sector number info */
			g_UsbHostMs[ms_index].media_info[lun].sec_num = (g_usb_ms_data[0]<<24) + (g_usb_ms_data[1]<<16)
												+ (g_usb_ms_data[2]<<8) + (g_usb_ms_data[3]<<0) + 1;

			g_UsbHostMs[ms_index].media_info[lun].sec_size = (g_usb_ms_data[4]<<24) + (g_usb_ms_data[5]<<16)
												+ (g_usb_ms_data[6]<<8) + (g_usb_ms_data[7]<<0);

			drv_trace4(TRACE_FUNC, (kal_uint32)USB_HOST_MS_READ_CAPACITY_OK, lun, g_UsbHostMs[ms_index].media_info[lun].sec_num, g_UsbHostMs[ms_index].media_info[lun].sec_size, 0);

			/* Add error check, limit to 32G card */
			if((g_UsbHostMs[ms_index].media_info[lun].sec_num >= 0x4000000)||(g_UsbHostMs[ms_index].media_info[lun].sec_size != 512))
			{
				USB_Dbg_Trace(USB_HOST_MS_READ_CAPACITY_ERROR,  g_UsbHostMs[ms_index].media_info[lun].sec_num, g_UsbHostMs[ms_index].media_info[lun].sec_size);
				drv_trace4(TRACE_FUNC, (kal_uint32)USB_HOST_MS_READ_CAPACITY_FAIL, lun, g_UsbHostMs[ms_index].media_info[lun].sec_num, g_UsbHostMs[ms_index].media_info[lun].sec_size, 0);

				g_UsbHostMs[ms_index].media_info[lun].sec_num = 0;
				g_UsbHostMs[ms_index].media_info[lun].sec_size = 0;	
				g_UsbHostMs[ms_index].media_info[lun].state = USB_HOST_MS_MEDIA_STATE_ABSENT;
				g_UsbHostMs[ms_index].result = USB_HOST_MS_RESULT_FORMAT_ERROR;
			}
		}
		else if(g_UsbHostMs[ms_index].result == USB_HOST_MS_RESULT_CSW_FAIL)
		{
			g_UsbHostMs[ms_index].media_info[lun].sec_num = 0;
			g_UsbHostMs[ms_index].media_info[lun].sec_size = 0;
			/* translate result to request sense result */
			/* application can treat it as result OK is request sense reault is OK */
			g_UsbHostMs[ms_index].result = USB_Host_Ms_Request_Sense(lun);
		}
	}
	else
	{
		USB_Dbg_Trace(USB_HOST_MS_READ_CAPACITY_3,  (kal_uint32)g_UsbHostMs[ms_index].result, 0);
		g_UsbHostMs[ms_index].result = USB_HOST_MS_RESULT_NO_RESPONSE;
	}

	return g_UsbHostMs[ms_index].result;
}


/* TEST UNIT READY command (00h)*/
USB_HOST_MS_RESULT USB_Host_Ms_Test_Unit_Ready(kal_uint8 lun)
{
	kal_bool b_send_result;
	kal_uint32 event_group;
	kal_uint8  ms_index = USB_MS_IP_Query(lun);
	USB_HOST_MS_MEDIA_STATE media_state = g_UsbHostMs[ms_index].media_info[lun].state;


	USB_Dbg_Trace(USB_HOST_MS_TEST_UNIT_READY_1, lun, 0);
	kal_mem_set(g_usb_ms_cmd, 0, USBMS_MAX_CMD_LEN);
	g_usb_ms_cmd[0] = USBMS_TEST_UNIT_READY;

	g_UsbHostMs[ms_index].ms_cmd_data.lun = lun;
	g_UsbHostMs[ms_index].ms_cmd_data.cmd_len = USBMS_TEST_UNIT_READY_CMD_LEN;
	g_UsbHostMs[ms_index].ms_cmd_data.cmd_buff = g_usb_ms_cmd;
	g_UsbHostMs[ms_index].ms_cmd_data.data_len = USBMS_TEST_UNIT_READY_DATA_LEN;
	g_UsbHostMs[ms_index].ms_cmd_data.data_buff = g_usb_ms_data;
	g_UsbHostMs[ms_index].ms_cmd_data.data_dir = USB_HOST_MS_DATA_NONE;

	b_send_result = USB_Host_Ms_Send_Cmd(ms_index,&g_UsbHostMs[ms_index].ms_cmd_data);

	if((b_send_result == KAL_TRUE)&&(g_UsbHostMs[ms_index].dev_attatch == KAL_TRUE))
	{
		/* when event is retrived, result has been got in data buffer */
		kal_retrieve_eg_events(g_UsbHostMs[ms_index].event_id, EVENT_USB_MS_DONE|EVENT_USB_MS_DETATCH, 
						KAL_OR_CONSUME, &event_group, KAL_SUSPEND);

		USB_Dbg_Trace(USB_HOST_MS_TEST_UNIT_READY_2,  (kal_uint32)g_UsbHostMs[ms_index].result, 0);

		if(g_UsbHostMs[ms_index].result == USB_HOST_MS_RESULT_OK)
		{
			/* If data state is USB_HOST_MS_MEDIA_STATE_WR_PROTECT, it means data state is not changed,
			    do not change it to ready state */
			if(g_UsbHostMs[ms_index].media_info[lun].state!=USB_HOST_MS_MEDIA_STATE_WR_PROTECT)
				g_UsbHostMs[ms_index].media_info[lun].state = USB_HOST_MS_MEDIA_STATE_READY;
		}
		else if(g_UsbHostMs[ms_index].result == USB_HOST_MS_RESULT_CSW_FAIL)
		{
			/* translate result to request sense result */
			/* application can treat it as result OK is request sense reault is OK */
			/* media state will be changed in request sense handler */
			g_UsbHostMs[ms_index].result = USB_Host_Ms_Request_Sense(lun);
		}

		USB_Host_Ms_Update_Media_State(media_state, lun);
	}
	else
	{
		USB_Dbg_Trace(USB_HOST_MS_TEST_UNIT_READY_3,  (kal_uint32)g_UsbHostMs[ms_index].result, 0);
		g_UsbHostMs[ms_index].result = 	USB_HOST_MS_RESULT_NO_RESPONSE;
	}

	return g_UsbHostMs[ms_index].result;
}


/* MODE SENSE6 command (1ah)*/
USB_HOST_MS_RESULT USB_Host_Ms_Mode_Sense6(kal_uint8 lun)
{
	kal_bool b_send_result;
	kal_uint32 event_group;
	kal_uint8  ms_index = USB_MS_IP_Query(lun);
	USB_HOST_MS_MEDIA_STATE media_state = g_UsbHostMs[ms_index].media_info[lun].state;


	USB_Dbg_Trace(USB_HOST_MS_MODE_SENSE6_1, lun, 0);
	kal_mem_set(g_usb_ms_cmd, 0, USBMS_MAX_CMD_LEN);
	g_usb_ms_cmd[0] = USBMS_MODE_SENSE6;
	g_usb_ms_cmd[2] = 0x1c;
	g_usb_ms_cmd[4] = USBMS_MODE_SENSE6_DATA_LEN;

	g_UsbHostMs[ms_index].ms_cmd_data.lun = lun;
	g_UsbHostMs[ms_index].ms_cmd_data.cmd_len = USBMS_MODE_SENSE6_CMD_LEN;
	g_UsbHostMs[ms_index].ms_cmd_data.cmd_buff = g_usb_ms_cmd;
	g_UsbHostMs[ms_index].ms_cmd_data.data_len = USBMS_MODE_SENSE6_DATA_LEN;
	g_UsbHostMs[ms_index].ms_cmd_data.data_buff = g_usb_ms_data;
	g_UsbHostMs[ms_index].ms_cmd_data.data_dir = USB_HOST_MS_DATA_RECV;

	b_send_result = USB_Host_Ms_Send_Cmd(ms_index,&g_UsbHostMs[ms_index].ms_cmd_data);

	if((b_send_result == KAL_TRUE)&&(g_UsbHostMs[ms_index].dev_attatch == KAL_TRUE))
	{
		/* when event is retrived, result has been got in data buffer */
		kal_retrieve_eg_events(g_UsbHostMs[ms_index].event_id, EVENT_USB_MS_DONE|EVENT_USB_MS_DETATCH, 
						KAL_OR_CONSUME, &event_group, KAL_SUSPEND);

		USB_Dbg_Trace(USB_HOST_MS_MODE_SENSE6_2,  (kal_uint32)g_UsbHostMs[ms_index].result, 0);

		if(g_UsbHostMs[ms_index].result == USB_HOST_MS_RESULT_OK)
		{
			/* determine it is write protect or not */
			if((g_usb_ms_data[2]&0x80)!=0)
				g_UsbHostMs[ms_index].media_info[lun].state = USB_HOST_MS_MEDIA_STATE_WR_PROTECT;
			else
				g_UsbHostMs[ms_index].media_info[lun].state = USB_HOST_MS_MEDIA_STATE_READY;
		}
		else if(g_UsbHostMs[ms_index].result == USB_HOST_MS_RESULT_CSW_FAIL) 
		{
			/* translate result to request sense result */
			/* application can treat it as result OK is request sense reault is OK */
			g_UsbHostMs[ms_index].result = USB_Host_Ms_Request_Sense(lun);
		}

		USB_Host_Ms_Update_Media_State(media_state, lun);
	}
	else
	{
		USB_Dbg_Trace(USB_HOST_MS_MODE_SENSE6_3,  (kal_uint32)g_UsbHostMs[ms_index].result, 0);
		g_UsbHostMs[ms_index].result = USB_HOST_MS_RESULT_NO_RESPONSE;
	}

	return g_UsbHostMs[ms_index].result;
}


/* MODE SENSE6 All mode command (1ah)*/
USB_HOST_MS_RESULT USB_Host_Ms_Mode_Sense6_All_Mode(kal_uint8 lun)
{
	kal_bool b_send_result;
	kal_uint32 event_group;
	kal_uint8  ms_index = USB_MS_IP_Query(lun);
	USB_HOST_MS_MEDIA_STATE media_state = g_UsbHostMs[ms_index].media_info[lun].state;


	USB_Dbg_Trace(USB_HOST_MS_MODE_SENSE6_ALL_1, lun, 0);
	kal_mem_set(g_usb_ms_cmd, 0, USBMS_MAX_CMD_LEN);
	g_usb_ms_cmd[0] = USBMS_MODE_SENSE6;
	g_usb_ms_cmd[2] = 0x3f;
	g_usb_ms_cmd[4] = USBMS_MODE_SENSE6_DATA_LEN;

	g_UsbHostMs[ms_index].ms_cmd_data.lun = lun;
	g_UsbHostMs[ms_index].ms_cmd_data.cmd_len = USBMS_MODE_SENSE6_CMD_LEN;
	g_UsbHostMs[ms_index].ms_cmd_data.cmd_buff = g_usb_ms_cmd;
	g_UsbHostMs[ms_index].ms_cmd_data.data_len = USBMS_MODE_SENSE6_DATA_LEN;
	g_UsbHostMs[ms_index].ms_cmd_data.data_buff = g_usb_ms_data;
	g_UsbHostMs[ms_index].ms_cmd_data.data_dir = USB_HOST_MS_DATA_RECV;

	b_send_result = USB_Host_Ms_Send_Cmd(ms_index,&g_UsbHostMs[ms_index].ms_cmd_data);

	if((b_send_result == KAL_TRUE)&&(g_UsbHostMs[ms_index].dev_attatch == KAL_TRUE))
	{
		/* when event is retrived, result has been got in data buffer */
		kal_retrieve_eg_events(g_UsbHostMs[ms_index].event_id, EVENT_USB_MS_DONE|EVENT_USB_MS_DETATCH, 
						KAL_OR_CONSUME, &event_group, KAL_SUSPEND);

		USB_Dbg_Trace(USB_HOST_MS_MODE_SENSE6_ALL_2,  (kal_uint32)g_UsbHostMs[ms_index].result, 0);

		if(g_UsbHostMs[ms_index].result == USB_HOST_MS_RESULT_OK)
		{
			/* determine it is write protect or not */
			if((g_usb_ms_data[2]&0x80)!=0)
				g_UsbHostMs[ms_index].media_info[lun].state = USB_HOST_MS_MEDIA_STATE_WR_PROTECT;
			else
				g_UsbHostMs[ms_index].media_info[lun].state = USB_HOST_MS_MEDIA_STATE_READY;
		}
		else if(g_UsbHostMs[ms_index].result == USB_HOST_MS_RESULT_CSW_FAIL)
		{
			/* translate result to request sense result */
			/* application can treat it as result OK is request sense reault is OK */
			g_UsbHostMs[ms_index].result = USB_Host_Ms_Request_Sense(lun);
		}

		USB_Host_Ms_Update_Media_State(media_state, lun);
	}
	else
	{
		USB_Dbg_Trace(USB_HOST_MS_MODE_SENSE6_ALL_3,  (kal_uint32)g_UsbHostMs[ms_index].result, 0);
		g_UsbHostMs[ms_index].result = USB_HOST_MS_RESULT_NO_RESPONSE;
	}

	return g_UsbHostMs[ms_index].result;
}


/* MODE SENSE6 All mode command (5ah)*/
USB_HOST_MS_RESULT USB_Host_Ms_Mode_Sense10_All_Mode(kal_uint8 lun)
{
	kal_bool b_send_result;
	kal_uint32 event_group;
	kal_uint8  ms_index = USB_MS_IP_Query(lun);
	USB_HOST_MS_MEDIA_STATE media_state = g_UsbHostMs[ms_index].media_info[lun].state;


	USB_Dbg_Trace(USB_HOST_MS_MODE_SENSE10_ALL_1, lun, 0);
	kal_mem_set(g_usb_ms_cmd, 0, USBMS_MAX_CMD_LEN);
	g_usb_ms_cmd[0] = USBMS_MODE_SENSE;
	g_usb_ms_cmd[2] = 0x3f;
	g_usb_ms_cmd[4] = USBMS_MODE_SENSE_DATA_LEN;

	g_UsbHostMs[ms_index].ms_cmd_data.lun = lun;
	g_UsbHostMs[ms_index].ms_cmd_data.cmd_len = USBMS_MODE_SENSE_CMD_LEN;
	g_UsbHostMs[ms_index].ms_cmd_data.cmd_buff = g_usb_ms_cmd;
	g_UsbHostMs[ms_index].ms_cmd_data.data_len = USBMS_MODE_SENSE_DATA_LEN;
	g_UsbHostMs[ms_index].ms_cmd_data.data_buff = g_usb_ms_data;
	g_UsbHostMs[ms_index].ms_cmd_data.data_dir = USB_HOST_MS_DATA_RECV;

	b_send_result = USB_Host_Ms_Send_Cmd(ms_index,&g_UsbHostMs[ms_index].ms_cmd_data);

	if((b_send_result == KAL_TRUE)&&(g_UsbHostMs[ms_index].dev_attatch == KAL_TRUE))
	{
		/* when event is retrived, result has been got in data buffer */
		kal_retrieve_eg_events(g_UsbHostMs[ms_index].event_id, EVENT_USB_MS_DONE|EVENT_USB_MS_DETATCH, 
						KAL_OR_CONSUME, &event_group, KAL_SUSPEND);

		USB_Dbg_Trace(USB_HOST_MS_MODE_SENSE10_ALL_2,  (kal_uint32)g_UsbHostMs[ms_index].result, 0);

		if(g_UsbHostMs[ms_index].result == USB_HOST_MS_RESULT_OK)
		{
			/* determine it is write protect or not */
			if((g_usb_ms_data[2]&0x80)!=0)
				g_UsbHostMs[ms_index].media_info[lun].state = USB_HOST_MS_MEDIA_STATE_WR_PROTECT;
			else
				g_UsbHostMs[ms_index].media_info[lun].state = USB_HOST_MS_MEDIA_STATE_READY;
		}
		else if(g_UsbHostMs[ms_index].result == USB_HOST_MS_RESULT_CSW_FAIL)
		{
			/* translate result to request sense result */
			/* application can treat it as result OK is request sense reault is OK */
			g_UsbHostMs[ms_index].result = USB_Host_Ms_Request_Sense(lun);
		}

		USB_Host_Ms_Update_Media_State(media_state, lun);
	}
	else
	{
		USB_Dbg_Trace(USB_HOST_MS_MODE_SENSE10_ALL_3,  (kal_uint32)g_UsbHostMs[ms_index].result, 0);
		g_UsbHostMs[ms_index].result = USB_HOST_MS_RESULT_NO_RESPONSE;
	}

	return g_UsbHostMs[ms_index].result;
}

/* READ command (28h)*/
/* The received data will be stored in data parameter */
USB_HOST_MS_RESULT USB_Host_Ms_Read(kal_uint8 lun, kal_uint32 sec_start, kal_uint16 sec_num, kal_uint8* data)
{
	kal_bool b_send_result;
	kal_uint32 event_group;
	kal_uint8  ms_index = USB_MS_IP_Query(lun);

	USB_Dbg_Trace(USB_HOST_MS_READ_1, lun, 0);
	kal_mem_set(g_usb_ms_cmd, 0, USBMS_MAX_CMD_LEN);
	g_usb_ms_cmd[0] = USBMS_READ10;
	g_usb_ms_cmd[2] = (sec_start>>24)&0xff;
	g_usb_ms_cmd[3] = (sec_start>>16)&0xff;
	g_usb_ms_cmd[4] = (sec_start>>8)&0xff;
	g_usb_ms_cmd[5] = sec_start&0xff;

	g_usb_ms_cmd[7] = (sec_num>>8)&0xff;
	g_usb_ms_cmd[8] = sec_num&0xff;

	g_UsbHostMs[ms_index].ms_cmd_data.lun = lun;
	g_UsbHostMs[ms_index].ms_cmd_data.cmd_len = USBMS_READ_CMD_LEN;
	g_UsbHostMs[ms_index].ms_cmd_data.cmd_buff = g_usb_ms_cmd;
	g_UsbHostMs[ms_index].ms_cmd_data.data_len = sec_num*g_UsbHostMs[ms_index].media_info[lun].sec_size; 
	g_UsbHostMs[ms_index].ms_cmd_data.data_buff = data;
	g_UsbHostMs[ms_index].ms_cmd_data.data_dir = USB_HOST_MS_DATA_RECV;

	b_send_result = USB_Host_Ms_Send_Cmd(ms_index,&g_UsbHostMs[ms_index].ms_cmd_data);

	if((b_send_result == KAL_TRUE)&&(g_UsbHostMs[ms_index].dev_attatch == KAL_TRUE))
	{
		/* when event is retrived, result has been got in data buffer */
		kal_retrieve_eg_events(g_UsbHostMs[ms_index].event_id, EVENT_USB_MS_DONE|EVENT_USB_MS_DETATCH, 
						KAL_OR_CONSUME, &event_group, KAL_SUSPEND);

		USB_Dbg_Trace(USB_HOST_MS_READ_2,  (kal_uint32)g_UsbHostMs[ms_index].result, 0);

		g_UsbHostMs[ms_index].b_rw_result = KAL_FALSE;

		if(g_UsbHostMs[ms_index].result == USB_HOST_MS_RESULT_OK)
		{
			/* In the application layer, result may be OK because of next request sense result is OK */
			/* This is used to indicate whether the whole data are read back successfully */
			g_UsbHostMs[ms_index].b_rw_result = KAL_TRUE;
		}
		else if(g_UsbHostMs[ms_index].result == USB_HOST_MS_RESULT_CSW_FAIL)
		{
			drv_trace1(TRACE_FUNC, (kal_uint32)USB_HOST_MS_READ_FAIL, lun);
			/* translate result to request sense result */
			/* application can treat it as result OK is request sense reault is OK */
			g_UsbHostMs[ms_index].result = USB_Host_Ms_Request_Sense(lun);
		}
		else if(g_UsbHostMs[ms_index].result == USB_HOST_MS_RESULT_TIMEOUT)
		{
			USB_Dbg_Trace(USB_HOST_MS_READ_1, lun, 4);
			drv_trace2(TRACE_FUNC, (kal_uint32)USB_HOST_MS_READ_SECTOR_TIMEOUT_FAIL, lun, 0);
		}
	}
	else
	{
		USB_Dbg_Trace(USB_HOST_MS_READ_3,  (kal_uint32)g_UsbHostMs[ms_index].result, 0);
		g_UsbHostMs[ms_index].result = USB_HOST_MS_RESULT_NO_RESPONSE;
	}

	return g_UsbHostMs[ms_index].result;
}


/* WRITE command (2ah)*/
/* The data parameter will be sent out */
USB_HOST_MS_RESULT USB_Host_Ms_Write(kal_uint8 lun, kal_uint32 sec_start, kal_uint16 sec_num, kal_uint8* data)
{
	kal_bool b_send_result;
	kal_uint32 event_group;
	kal_uint8  ms_index = USB_MS_IP_Query(lun);

#ifdef __USB_OTG_TX_TEST__
	g_UsbHostMs[ms_index].host_ms_tx_test_flag = KAL_TRUE;
#endif

	USB_Dbg_Trace(USB_HOST_MS_WRITE_1, lun, 0);
	kal_mem_set(g_usb_ms_cmd, 0, USBMS_MAX_CMD_LEN);

	g_usb_ms_cmd[0] = USBMS_WRITE10;
	g_usb_ms_cmd[2] = (sec_start>>24)&0xff;
	g_usb_ms_cmd[3] = (sec_start>>16)&0xff;
	g_usb_ms_cmd[4] = (sec_start>>8)&0xff;
	g_usb_ms_cmd[5] = sec_start&0xff;

	g_usb_ms_cmd[7] = (sec_num>>8)&0xff;
	g_usb_ms_cmd[8] = sec_num&0xff;

	g_UsbHostMs[ms_index].ms_cmd_data.lun = lun;
	g_UsbHostMs[ms_index].ms_cmd_data.cmd_len = USBMS_WRITE_CMD_LEN;
	g_UsbHostMs[ms_index].ms_cmd_data.cmd_buff = g_usb_ms_cmd;
	g_UsbHostMs[ms_index].ms_cmd_data.data_len = sec_num*g_UsbHostMs[ms_index].media_info[lun].sec_size; 
	g_UsbHostMs[ms_index].ms_cmd_data.data_buff = data;
	g_UsbHostMs[ms_index].ms_cmd_data.data_dir = USB_HOST_MS_DATA_SEND;

	b_send_result = USB_Host_Ms_Send_Cmd(ms_index,&g_UsbHostMs[ms_index].ms_cmd_data);

	if((b_send_result == KAL_TRUE)&&(g_UsbHostMs[ms_index].dev_attatch == KAL_TRUE))
	{
		/* when event is retrived, result has been got in data buffer */
		kal_retrieve_eg_events(g_UsbHostMs[ms_index].event_id, EVENT_USB_MS_DONE|EVENT_USB_MS_DETATCH, 
						KAL_OR_CONSUME, &event_group, KAL_SUSPEND);

		USB_Dbg_Trace(USB_HOST_MS_WRITE_2,  (kal_uint32)g_UsbHostMs[ms_index].result, 0);

		g_UsbHostMs[ms_index].b_rw_result = KAL_FALSE;

		if(g_UsbHostMs[ms_index].result == USB_HOST_MS_RESULT_OK)
		{
			/* In the application layer, result may be OK because of next request sense result is OK */
			/* This is used to indicate whether the whole data are written out  successfully */
			g_UsbHostMs[ms_index].b_rw_result = KAL_TRUE;
		}
		else if(g_UsbHostMs[ms_index].result == USB_HOST_MS_RESULT_CSW_FAIL)
		{
			drv_trace1(TRACE_FUNC, (kal_uint32)USB_HOST_MS_WRITE_FAIL, lun);
			/* translate result to request sense result */
			/* application can treat it as result OK is request sense reault is OK */
			g_UsbHostMs[ms_index].result = USB_Host_Ms_Request_Sense(lun);
		}
		else if(g_UsbHostMs[ms_index].result == USB_HOST_MS_RESULT_TIMEOUT)
		{
			USB_Dbg_Trace(USB_HOST_MS_WRITE_1, lun, 4);
			drv_trace2(TRACE_FUNC, (kal_uint32)USB_HOST_MS_WRITE_SECTOR_TIMEOUT_FAIL, lun, 0);
		}
	}
	else
	{
		USB_Dbg_Trace(USB_HOST_MS_WRITE_3,  (kal_uint32)g_UsbHostMs[ms_index].result, 0);
		g_UsbHostMs[ms_index].result = USB_HOST_MS_RESULT_NO_RESPONSE;
	}

	return g_UsbHostMs[ms_index].result;
}


/* Construct the CBW format, and send command to scheduling queue*/
static kal_bool USB_Host_Ms_Send_Cmd(kal_uint8 ms_index,USBH_Ms_Cmd_Struct *ms_cmd)
{
	UsbMs_CBW *CBW = (UsbMs_CBW*)g_UsbHostMs[ms_index].CBWdata;
	kal_bool b_result;

	/* Construct CBW according to the command request */
	CBW->dCBWSignature = 0x43425355;
	CBW->dCBWTag = g_UsbHostMs[ms_index].CBWdata[1] +1;  /* increment tag in each command */
	CBW->dCBWDataTransferLength = ms_cmd->data_len;

	if(ms_cmd->data_dir == USB_HOST_MS_DATA_RECV)
		CBW->bmCBWFlags = USBMS_DIR_IN;
	else
		CBW->bmCBWFlags = USBMS_DIR_OUT;

	CBW->bCBWLUN = ms_cmd->lun;
	CBW->bCBWCBLength = ms_cmd->cmd_len;
	/* the CBWCB comes from each command. ex READ, WRITE, TEST UNIT READY.*/
	/* the format is different according to each command */
	kal_mem_set(CBW->CBWCB, 0, USBMS_CBWCB_LENGTH);
	kal_mem_cpy(CBW->CBWCB, ms_cmd->cmd_buff, ms_cmd->cmd_len);

	/* assign the data buffer */
	/* In OUT direction, the data will be sent during transfer */
	/* In IN direction, the received data will be stored in this buffer */
	g_UsbHostMs[ms_index].data = ms_cmd->data_buff;
	g_UsbHostMs[ms_index].data_length = ms_cmd->data_len;
	g_UsbHostMs[ms_index].data_dir = ms_cmd->data_dir;
	g_UsbHostMs[ms_index].ms_state = USB_HOST_MS_CBW;

	/* Note that CBW, DATA, CSW transfer is handled in HISR level,
	    And when the transfer complete, it will retrive the event to wake up waiting task */

	/* To prevent USB disconn intr coming during this moment, so we cannot flush this packet */
	IRQMask(USB_IRQ_MAP[g_UsbHostMs[ms_index].common_info.usb_ip_port]);

	b_result = USBD_Send_Req(g_UsbHostMs[ms_index].common_info,g_UsbHostMs[ms_index].ep_tx_info, USBMS_CBW_LENGTH, CBW);

	if(USBD_Get_UnMask_Irq(g_UsbHostMs[ms_index].common_info) == KAL_TRUE)
		IRQUnmask(USB_IRQ_MAP[g_UsbHostMs[ms_index].common_info.usb_ip_port]);

	return b_result;
}


/************************************************************
	ms class handler. Note that it is executed in OTG HIST context
*************************************************************/

/* handler for control endpoint */
/* It handles both standard and class specific EP0 command*/
static void USB_Host_Ms_Ctrl_EP_Hdlr(kal_uint8 ms_index,USB_HCD_STATUS result, kal_uint32 param)
{
	/* Store the command because it will be change immediatly*/
	USB_HOST_MS_EP0_CMD ms_cmd = g_UsbHostMs[ms_index].ms_cmd;
	kal_bool tr_result;


	USB_Dbg_Trace(USB_HOST_MS_CTRL_EP_HDLR, (kal_uint32)result, (kal_uint32)ms_cmd);

	/* Unless another EP0 command is issued, the command should be set to NONE*/
	g_UsbHostMs[ms_index].ms_cmd = USB_HOST_MS_EP0_CMD_NONE;

	if(result != USB_HCD_OK)
	{
		/* translate the result */
		/* for EP0 error, the handler dose not do error handling,
		    the error handling is done in the upper layer state */
		if(result == USB_HCD_STALL)
			g_UsbHostMs[ms_index].result = USB_HOST_MS_RESULT_STALL;
		else if(result == USB_HCD_TIMEOUT)
			g_UsbHostMs[ms_index].result = USB_HOST_MS_RESULT_TIMEOUT;
		else
			g_UsbHostMs[ms_index].result = USB_HOST_MS_RESULT_NO_RESPONSE;

		USB_Dbg_Trace(USB_HOST_SET_EVENT, 0, 0);
		kal_set_eg_events(g_UsbHostMs[ms_index].event_id, EVENT_USB_MS_DONE, KAL_OR);		
	}
	else
	{
		/* result is OK */
		switch(ms_cmd)
		{
		case USB_HOST_MS_EP0_CMD_RESET:
		case USB_HOST_MS_EP0_CMD_GET_LUN:
			g_UsbHostMs[ms_index].result = USB_HOST_MS_RESULT_OK;
			USB_Dbg_Trace(USB_HOST_SET_EVENT, 0, 0);
			kal_set_eg_events(g_UsbHostMs[ms_index].event_id, EVENT_USB_MS_DONE, KAL_OR);		
			break;

		case USB_HOST_MS_EP0_CMD_CLEAR_STALL_IN:
		case USB_HOST_MS_EP0_CMD_CLEAR_STALL_OUT:
			/* Clear IN or clear OUT stall are completed,
			    The next action is determined according to the previous state before STALL*/
			if(g_UsbHostMs[ms_index].ms_state == USB_HOST_MS_CBW_CLEAR_STALL)
			{
				/* The CBW is stalled. Do not issue DATA or CSW any more.
				    Return STALL result and let upper layer state machine handle it */
				g_UsbHostMs[ms_index].result = USB_HOST_MS_RESULT_STALL;
				USB_Dbg_Trace(USB_HOST_SET_EVENT, 0, 0);
				kal_set_eg_events(g_UsbHostMs[ms_index].event_id, EVENT_USB_MS_DONE, KAL_OR);
			}
			else if(g_UsbHostMs[ms_index].ms_state == USB_HOST_MS_DATA_CLEAR_STALL)
			{
				/* DATA is stalled. Clear STALL and attempt to receive CSW */
				/* Receive CSW */
				tr_result = USBD_Recv_Req(g_UsbHostMs[ms_index].common_info,g_UsbHostMs[ms_index].ep_rx_info, USBMS_CSW_LENGTH, &g_UsbHostMs[ms_index].CSW);

				if(tr_result == KAL_TRUE)
				{
					g_UsbHostMs[ms_index].ms_state = USB_HOST_MS_CSW;
				}
				else
				{
					g_UsbHostMs[ms_index].result = USB_HOST_MS_RESULT_NO_RESPONSE;
					USB_Dbg_Trace(USB_HOST_SET_EVENT, 0, 0);
					kal_set_eg_events(g_UsbHostMs[ms_index].event_id, EVENT_USB_MS_DONE, KAL_OR);
				}
			}
			else if(g_UsbHostMs[ms_index].ms_state == USB_HOST_MS_CSW_CLEAR_STALL)
			{
				/* CSW is stalled. Clear STALL and attepmt to receive CSW */
				/* send CSW */
				tr_result = USBD_Recv_Req(g_UsbHostMs[ms_index].common_info,g_UsbHostMs[ms_index].ep_rx_info, USBMS_CSW_LENGTH, &g_UsbHostMs[ms_index].CSW);

				if(tr_result == KAL_FALSE)
				{
					g_UsbHostMs[ms_index].result = USB_HOST_MS_RESULT_NO_RESPONSE;
					USB_Dbg_Trace(USB_HOST_SET_EVENT, 0, 0);
					kal_set_eg_events(g_UsbHostMs[ms_index].event_id, EVENT_USB_MS_DONE, KAL_OR);
				}
			}
			else
			{
				/* In all other states, it should not come to EP0 handler */
				EXT_ASSERT(0, (kal_uint32)ms_cmd, (kal_uint32)g_UsbHostMs[ms_index].ms_state, 0);
			}
			break;
		}
	}
}


/* handler for ctrl endpoint */
/* It handles CBW, DATA, CSW state machine */
/* When we use DMA for MS host function, and FIFO is double, then we transit the state after DMA callback does not mean the FIFO packet had been processed */
/* It will make our state machine is wrong */
static void USB_Host_Ms_Bulk_EP_Hdlr(kal_uint8 ms_index,USB_HCD_STATUS result, kal_uint32 param)
{
	USB_Dbg_Trace(USB_HOST_MS_BULK_EP_HDLR,  (kal_uint32)result, (kal_uint32)g_UsbHostMs[ms_index].ms_state);

	if(g_UsbHostMs[ms_index].ms_state == USB_HOST_MS_CBW)
	{
		USB_Host_Ms_CBW_Hdler(ms_index,result, param);
	}
	else if(g_UsbHostMs[ms_index].ms_state == USB_HOST_MS_DATA)
	{
		if((result != USB_HCD_OK)&&(result != USB_HCD_DETATCH)&&
			(g_UsbHostMs[ms_index].data_dir == USB_HOST_MS_DATA_RECV)&&((USB_EP_DIRECTION)param == USB_EP_TX_DIR))
		{
			USB_Dbg_Trace(USB_HOST_MS_BULK_EP_HDLR_ERROR1, 0, 0);
			/* Error is in CBW, not DATA */
			g_UsbHostMs[ms_index].ms_state = USB_HOST_MS_CBW;
			USB_Host_Ms_CBW_Hdler(ms_index,result, param);
		}
		else
		{
			USB_Host_Ms_DATA_Hdler(ms_index,result, param);
		}
	}
	else if((g_UsbHostMs[ms_index].ms_state == USB_HOST_MS_CSW)||(g_UsbHostMs[ms_index].ms_state == USB_HOST_MS_CSW_CLEAR_STALL))
	{
		if((result != USB_HCD_OK)&&(result != USB_HCD_DETATCH)&&
			(g_UsbHostMs[ms_index].data_dir == USB_HOST_MS_DATA_SEND)&&((USB_EP_DIRECTION)param == USB_EP_TX_DIR))
		{
			USB_Dbg_Trace(USB_HOST_MS_BULK_EP_HDLR_ERROR2, 0, 0);
			/* Error is in DATA, not CSW */
			g_UsbHostMs[ms_index].ms_state = USB_HOST_MS_DATA;
			USB_Host_Ms_DATA_Hdler(ms_index,result, param);
		}
		else
		{

#ifdef __USB_OTG_TX_TEST__
			if (g_UsbHostMs[ms_index].host_ms_tx_test_flag == KAL_TRUE)
			{
				result = USBD_Send_Req(g_UsbHostMs[ms_index].common_info,g_UsbHostMs[ms_index].ep_tx_info, USB_HOST_MS_MAX_DATA_LENGTH, g_UsbHostMs[ms_index].data);
				return;
			}
#endif
#ifdef __USB_OTG_RX_TEST__
			if (g_UsbHostMs[ms_index].host_ms_rx_test_flag == KAL_TRUE)
			{
				result = USBD_Recv_Req(g_UsbHostMs[ms_index].common_info,g_UsbHostMs[ms_index].ep_rx_info, USB_HOST_MS_MAX_DATA_LENGTH, g_UsbHostMs[ms_index].data);
				g_UsbHostMs[ms_index].ms_state = USB_HOST_MS_CSW;
				return;
			}
#endif

			USB_Host_Ms_CSW_Hdler(ms_index,result, param);
		}
	}
	else if((g_UsbHostMs[ms_index].ms_state == USB_HOST_MS_NONE)&&(result == USB_HCD_NO_RESPONSE))
	{
		// cable just plug out, RX / TX timeout , and wait Disconnect interrupt trigger.
	}
	else
	{
		/* Note that in USB_HOST_MS_CBW_CLEAR_STALL and USB_HOST_MS_DATA_CLEAR_STALL state,
		    only ctrl EP handler should be called, but not enter this bulk EP handler*/
		EXT_ASSERT(0, (kal_uint32)g_UsbHostMs[ms_index].ms_state, 0, 0);
	}
}


/* This callback function is for bulk EP */
/* The bulk EP part handles CBW, DATA, CSW state machine */
/* Run in HISR */
static void USB_Host_Ms_State_Hdlr(kal_uint8 usb_ip_port,USB_HCD_STATUS result, kal_uint32 param)
{
	kal_uint8 ms_index = USB_MS_Check_index(usb_ip_port);
	USB_Dbg_Trace(USB_HOST_MS_STATE_HDLR,  (kal_uint32)result, (kal_uint32)g_UsbHostMs[ms_index].ms_cmd);

	if(g_UsbHostMs[ms_index].ms_cmd == USB_HOST_MS_EP0_CMD_NONE)
	{
		USB_Host_Ms_Bulk_EP_Hdlr(ms_index,result, param);
	}
	else
	{
		if(result == USB_HCD_OK)
		{
			ASSERT(0);
		}
		else if (result == USB_HCD_STALL)
		{
			USB_Dbg_Trace(USB_HOST_MS_STATE_HDLR_ERROR1, 0, 0);
			g_UsbHostMs[ms_index].result = USB_HOST_MS_RESULT_STALL;
		}
		else
		{
			/* WARNING ! */
			/* This means that TX endpoint is error, and then RX one is also error */
			/* Happens because TX for DATA and RX for CSW */
			/* Does not go to bulk handler is to prevent set event twice */
			USB_Dbg_Trace(USB_HOST_MS_STATE_HDLR_ERROR2, 0, 0);
		}
	}
}


/* This callback function is for control EP */
/* The control EP part handles class specific EP0 command */
/* Run in HISR */
static void USB_Host_Ms_Hdlr(kal_uint8 usb_ip_port,USB_HCD_STATUS result, kal_uint32 param)
{
	kal_uint8 ms_index = USB_MS_Check_index(usb_ip_port);
	USB_Dbg_Trace(USB_HOST_MS_HDLR,  (kal_uint32)result, (kal_uint32)g_UsbHostMs[ms_index].ms_cmd);

	if(g_UsbHostMs[ms_index].ms_cmd != USB_HOST_MS_EP0_CMD_NONE)
	{
		USB_Host_Ms_Ctrl_EP_Hdlr(ms_index,result, param);
	}
	else
	{
		ASSERT(0);
	}
}


void USB_Host_Ms_Clear_Stall(kal_uint8 ms_index)
{	
	if (g_UsbHostMs[ms_index].stall_ep_dir == USB_EP_TX_DIR)
	{		
		USBD_Clear_Feature(g_UsbHostMs[ms_index].common_info,g_UsbHostMs[ms_index].ep_tx_info,KAL_FALSE, USB_Host_Ms_Hdlr);
	}
	else
	{	
		USBD_Clear_Feature(g_UsbHostMs[ms_index].common_info,g_UsbHostMs[ms_index].ep_rx_info,KAL_FALSE, USB_Host_Ms_Hdlr);	
	}	
	
	g_UsbHostMs[ms_index].result = USB_HOST_MS_RESULT_STALL;	
	USB_Dbg_Trace(USB_HOST_SET_EVENT, 0, 0);
	kal_set_eg_events(g_UsbHostMs[ms_index].event_id, EVENT_USB_MS_DONE, KAL_OR);
}

/* Ctrl EP CBW handler, handle the state machine */
static void USB_Host_Ms_CBW_Hdler(kal_uint8 ms_index,USB_HCD_STATUS result, kal_uint32 param)
{
	kal_bool tr_result;
//	ilm_struct *usb_ilm = NULL;
	usb_host_usbattach_ind_struct *usb_host_attach;

	USB_Dbg_Trace(USB_HOST_MS_CBW_HDLR, (kal_uint32)result, param);

	if(result == USB_HCD_OK)
	{
		/* check the real sent out length */
		if(param != USBMS_CBW_LENGTH)
			EXT_ASSERT(0, param, 0, 0);

		if(g_UsbHostMs[ms_index].data_length != 0)
		{
			/* DATA state should be the following state */
			/* Since data length is not zero, data direction must not NONE */
			if(g_UsbHostMs[ms_index].data_dir == USB_HOST_MS_DATA_NONE)
				EXT_ASSERT(0, (kal_uint32)g_UsbHostMs[ms_index].data_dir, g_UsbHostMs[ms_index].data_length, 0);

			if(g_UsbHostMs[ms_index].data_dir == USB_HOST_MS_DATA_RECV)
			{
				/* Receive data */
				if(g_UsbHostMs[ms_index].data_length > USB_HOST_MS_MAX_DATA_LENGTH)
				{
					/* DMA length has limit, so each transfer request should should have size limit */
					tr_result = USBD_Recv_Req(g_UsbHostMs[ms_index].common_info,g_UsbHostMs[ms_index].ep_rx_info, USB_HOST_MS_MAX_DATA_LENGTH, g_UsbHostMs[ms_index].data);

					if(tr_result == KAL_TRUE)
					{
						g_UsbHostMs[ms_index].sending_data_length = USB_HOST_MS_MAX_DATA_LENGTH;
						g_UsbHostMs[ms_index].remain_data_length = g_UsbHostMs[ms_index].data_length - USB_HOST_MS_MAX_DATA_LENGTH;
						g_UsbHostMs[ms_index].sent_data_length = 0;
					}
					else
					{
						ASSERT(0);
//						g_UsbHostMs[ms_index].result = USB_HOST_MS_RESULT_NO_RESPONSE;
//						USB_Dbg_Trace(USB_HOST_SET_EVENT, 0, 0);
//						kal_set_eg_events(g_UsbHostMs[ms_index].event_id, EVENT_USB_MS_DONE, KAL_OR);
					}
				}
				else
				{
					/* Prepare to recieve the whole data */
					tr_result = USBD_Recv_Req(g_UsbHostMs[ms_index].common_info,g_UsbHostMs[ms_index].ep_rx_info, g_UsbHostMs[ms_index].data_length, g_UsbHostMs[ms_index].data);

					if(tr_result == KAL_TRUE)
					{
						g_UsbHostMs[ms_index].sending_data_length = g_UsbHostMs[ms_index].data_length;
						g_UsbHostMs[ms_index].remain_data_length = 0;
						g_UsbHostMs[ms_index].sent_data_length = 0;
					}
					else
					{
						ASSERT(0);
//						g_UsbHostMs[ms_index].result = USB_HOST_MS_RESULT_NO_RESPONSE;
//						USB_Dbg_Trace(USB_HOST_SET_EVENT, 0, 0);
//						kal_set_eg_events(g_UsbHostMs[ms_index].event_id, EVENT_USB_MS_DONE, KAL_OR);
					}
				}
			}
			else
			{
				/* Send data*/
				if(g_UsbHostMs[ms_index].data_length > USB_HOST_MS_MAX_DATA_LENGTH)
				{
					/* DMA length has limit, so each transfer request should should have size limit */
					tr_result = USBD_Send_Req(g_UsbHostMs[ms_index].common_info,g_UsbHostMs[ms_index].ep_tx_info, USB_HOST_MS_MAX_DATA_LENGTH, g_UsbHostMs[ms_index].data);

					if(tr_result == KAL_TRUE)
					{
						g_UsbHostMs[ms_index].sending_data_length = USB_HOST_MS_MAX_DATA_LENGTH;
						g_UsbHostMs[ms_index].remain_data_length = g_UsbHostMs[ms_index].data_length - USB_HOST_MS_MAX_DATA_LENGTH;
						g_UsbHostMs[ms_index].sent_data_length = 0;
					}
					else
					{
						ASSERT(0);
//						g_UsbHostMs[ms_index].result = USB_HOST_MS_RESULT_NO_RESPONSE;
//						USB_Dbg_Trace(USB_HOST_SET_EVENT, 0, 0);
//						kal_set_eg_events(g_UsbHostMs[ms_index].event_id, EVENT_USB_MS_DONE, KAL_OR);
					}
				}
				else
				{
					/* Send the whole data out */
					tr_result = USBD_Send_Req(g_UsbHostMs[ms_index].common_info,g_UsbHostMs[ms_index].ep_tx_info, g_UsbHostMs[ms_index].data_length, g_UsbHostMs[ms_index].data);

					if(tr_result == KAL_TRUE)
					{
						g_UsbHostMs[ms_index].sending_data_length = g_UsbHostMs[ms_index].data_length;
						g_UsbHostMs[ms_index].remain_data_length = 0;
						g_UsbHostMs[ms_index].sent_data_length = 0;
					}
					else
					{
						ASSERT(0);
//						g_UsbHostMs[ms_index].result = USB_HOST_MS_RESULT_NO_RESPONSE;
//						USB_Dbg_Trace(USB_HOST_SET_EVENT, 0, 0);
//						kal_set_eg_events(g_UsbHostMs[ms_index].event_id, EVENT_USB_MS_DONE, KAL_OR);
					}
				}
			}

			/* change to DATA state */
			g_UsbHostMs[ms_index].ms_state = USB_HOST_MS_DATA;
		}
		else
		{
			/* CSW state should be the following state */
			/* Send CSW */
			tr_result = USBD_Recv_Req(g_UsbHostMs[ms_index].common_info,g_UsbHostMs[ms_index].ep_rx_info, USBMS_CSW_LENGTH, &g_UsbHostMs[ms_index].CSW);

			if(tr_result == KAL_TRUE)
			{
				g_UsbHostMs[ms_index].ms_state = USB_HOST_MS_CSW;
			}
			else
			{
				ASSERT(0);
//				g_UsbHostMs[ms_index].result = USB_HOST_MS_RESULT_NO_RESPONSE;
//				USB_Dbg_Trace(USB_HOST_SET_EVENT, 0, 0);
//				kal_set_eg_events(g_UsbHostMs[ms_index].event_id, EVENT_USB_MS_DONE, KAL_OR);
			}
		}
	}
	else if(result == USB_HCD_STALL)
	{
		/* CBW is OUT endpoint, so clear STALL OUT */
		g_UsbHostMs[ms_index].ms_state = USB_HOST_MS_CBW_CLEAR_STALL;
		g_UsbHostMs[ms_index].ms_cmd = USB_HOST_MS_EP0_CMD_CLEAR_STALL_OUT;

		/* Clear data01 */
		USBD_Clear_Data01(g_UsbHostMs[ms_index].common_info,g_UsbHostMs[ms_index].ep_tx_info);

		g_UsbHostMs[ms_index].stall_ep_dir = USB_EP_TX_DIR;

		/* Send message to USB task */
		usb_host_attach = (usb_host_usbattach_ind_struct*)construct_local_para(sizeof(usb_host_usbattach_ind_struct), TD_CTRL);
//		usb_host_attach->usb_ip_port = usb_ip_port;
		usb_host_attach->feature_index = ms_index;
		
		
		USB_Send_Msg_Ext_Queue(MOD_USB, MSG_ID_USB_MSHOST_CLEAR_STALL_IND, usb_host_attach);
//		DRV_BuildPrimitive(usb_ilm, stack_get_active_module_id(),MOD_USB, MSG_ID_USB_MSHOST_CLEAR_STALL_IND, usb_host_attach);
//		msg_send_ext_queue(usb_ilm);
		
//		USBD_Clear_Stall(usb_ip_port,g_UsbHostMs[ms_index].ep_tx_num, USB_EP_TX_DIR, KAL_FALSE,USB_Host_Ms_Hdlr);
	}
	else
	{
		if((result == USB_HCD_TIMEOUT)||(result == USB_HCD_DMA_TIMEOUT))
		{
			/* Other error condition, notify application about this error */
			g_UsbHostMs[ms_index].result = USB_HOST_MS_RESULT_TIMEOUT;
		}
		else
		{
			/* Other error condition, notify application about this error */
			g_UsbHostMs[ms_index].result = USB_HOST_MS_RESULT_NO_RESPONSE;
		}

		/* translate state to be NONE */
		g_UsbHostMs[ms_index].ms_state = USB_HOST_MS_NONE;

		USB_Dbg_Trace(USB_HOST_SET_EVENT, 0, 0);
		kal_set_eg_events(g_UsbHostMs[ms_index].event_id, EVENT_USB_MS_DONE, KAL_OR);
	}
}


/* Ctrl EP DATA handler, handle the state mcahine */
static void USB_Host_Ms_DATA_Hdler(kal_uint8 ms_index,USB_HCD_STATUS result, kal_uint32 param)
{
	kal_bool tr_result;
//	ilm_struct *usb_ilm;
//	usb_host_usbattach_ind_struct *usb_host_attach;

	USB_Dbg_Trace(USB_HOST_MS_DATA_HDLR, (kal_uint32)result, param);

	if(result == USB_HCD_OK)
	{
		g_UsbHostMs[ms_index].sent_data_length += param;

		/* In case some device may return 0 first and then real data, so check sent data length */
		if((g_UsbHostMs[ms_index].sending_data_length != param)&&(g_UsbHostMs[ms_index].sent_data_length != 0))
		{
			/* The real send/receive length is not the expected length */
			/* No matter the remaining data length, end the data phase directly*/
			/* Check whether the data is CSW or not, if yes, enter CSW Hdler directly*/
			if((param == USBMS_CSW_LENGTH) && (g_UsbHostMs[ms_index].data[0] == 0x55) && (g_UsbHostMs[ms_index].data[1] == 0x53)
				&& (g_UsbHostMs[ms_index].data[2] == 0x42) && (g_UsbHostMs[ms_index].data[3] == 0x53))
			{
				kal_mem_cpy((kal_uint8*)&g_UsbHostMs[ms_index].CSW, g_UsbHostMs[ms_index].data, USBMS_CSW_LENGTH);
				USB_Host_Ms_CSW_Hdler(ms_index,result, param);
				return;
			}

			/* Receive CSW, and enter CSW state */
			tr_result = USBD_Recv_Req(g_UsbHostMs[ms_index].common_info,g_UsbHostMs[ms_index].ep_rx_info, USBMS_CSW_LENGTH, &g_UsbHostMs[ms_index].CSW);

			if(tr_result == KAL_TRUE)
			{
				g_UsbHostMs[ms_index].ms_state = USB_HOST_MS_CSW;
			}
			else
			{
				ASSERT(0);
//				g_UsbHostMs[ms_index].result = USB_HOST_MS_RESULT_NO_RESPONSE;
//				USB_Dbg_Trace(USB_HOST_SET_EVENT, 0, 0);
//				kal_set_eg_events(g_UsbHostMs[ms_index].event_id, EVENT_USB_MS_DONE, KAL_OR);
			}
		}
		else
		{
			/* In case some device may return 0 first and then real data, so check sent data length */
			if(g_UsbHostMs[ms_index].sent_data_length == 0)
				g_UsbHostMs[ms_index].remain_data_length += g_UsbHostMs[ms_index].sending_data_length;

			if(g_UsbHostMs[ms_index].remain_data_length != 0)
			{
				/* More data need to send/receive */

				if(g_UsbHostMs[ms_index].data_dir == USB_HOST_MS_DATA_NONE)
					EXT_ASSERT(0, (kal_uint32)g_UsbHostMs[ms_index].data_dir, g_UsbHostMs[ms_index].data_length, g_UsbHostMs[ms_index].remain_data_length);

				if(g_UsbHostMs[ms_index].data_dir == USB_HOST_MS_DATA_RECV)
				{
					/* Receive data */
					if(g_UsbHostMs[ms_index].remain_data_length > USB_HOST_MS_MAX_DATA_LENGTH)
					{
						/* DMA length has limit, so each transfer request should should have size limit */
						tr_result = USBD_Recv_Req(g_UsbHostMs[ms_index].common_info,g_UsbHostMs[ms_index].ep_rx_info, USB_HOST_MS_MAX_DATA_LENGTH, (g_UsbHostMs[ms_index].data+g_UsbHostMs[ms_index].sent_data_length));

						if(tr_result == KAL_TRUE)
						{
							g_UsbHostMs[ms_index].sending_data_length = USB_HOST_MS_MAX_DATA_LENGTH;
							g_UsbHostMs[ms_index].remain_data_length = g_UsbHostMs[ms_index].remain_data_length - USB_HOST_MS_MAX_DATA_LENGTH;
						}
						else
						{
							ASSERT(0);
//							g_UsbHostMs[ms_index].result = USB_HOST_MS_RESULT_NO_RESPONSE;
//							USB_Dbg_Trace(USB_HOST_SET_EVENT, 0, 0);
//							kal_set_eg_events(g_UsbHostMs[ms_index].event_id, EVENT_USB_MS_DONE, KAL_OR);
						}
					}
					else
					{
						/* Prepare to recieve the whole data */
						tr_result = USBD_Recv_Req(g_UsbHostMs[ms_index].common_info,g_UsbHostMs[ms_index].ep_rx_info, g_UsbHostMs[ms_index].remain_data_length, (g_UsbHostMs[ms_index].data+g_UsbHostMs[ms_index].sent_data_length));

						if(tr_result == KAL_TRUE)
						{
							g_UsbHostMs[ms_index].sending_data_length = g_UsbHostMs[ms_index].remain_data_length;
							g_UsbHostMs[ms_index].remain_data_length = 0;
						}
						else
						{
							ASSERT(0);
//							g_UsbHostMs[ms_index].result = USB_HOST_MS_RESULT_NO_RESPONSE;
//							USB_Dbg_Trace(USB_HOST_SET_EVENT, 0, 0);
//							kal_set_eg_events(g_UsbHostMs[ms_index].event_id, EVENT_USB_MS_DONE, KAL_OR);
						}
					}
				}
				else
				{
					/* Send data */
					if(g_UsbHostMs[ms_index].remain_data_length > USB_HOST_MS_MAX_DATA_LENGTH)
					{
						/* DMA length has limit, so each transfer request should should have size limit */
						tr_result = USBD_Send_Req(g_UsbHostMs[ms_index].common_info,g_UsbHostMs[ms_index].ep_tx_info, USB_HOST_MS_MAX_DATA_LENGTH, (g_UsbHostMs[ms_index].data+g_UsbHostMs[ms_index].sent_data_length));

						if(tr_result == KAL_TRUE)
						{
							g_UsbHostMs[ms_index].sending_data_length = USB_HOST_MS_MAX_DATA_LENGTH;	
							g_UsbHostMs[ms_index].remain_data_length = g_UsbHostMs[ms_index].remain_data_length - USB_HOST_MS_MAX_DATA_LENGTH;
						}
						else
						{
							ASSERT(0);
//							g_UsbHostMs[ms_index].result = USB_HOST_MS_RESULT_NO_RESPONSE;
//							USB_Dbg_Trace(USB_HOST_SET_EVENT, 0, 0);
//							kal_set_eg_events(g_UsbHostMs[ms_index].event_id, EVENT_USB_MS_DONE, KAL_OR);
						}
					}
					else
					{
						/* Send the whole data out */
						tr_result = USBD_Send_Req(g_UsbHostMs[ms_index].common_info,g_UsbHostMs[ms_index].ep_tx_info, g_UsbHostMs[ms_index].remain_data_length, (g_UsbHostMs[ms_index].data+g_UsbHostMs[ms_index].sent_data_length));

						if(tr_result == KAL_TRUE)
						{
							g_UsbHostMs[ms_index].sending_data_length = g_UsbHostMs[ms_index].remain_data_length;
							g_UsbHostMs[ms_index].remain_data_length = 0;
						}
						else
						{
							ASSERT(0);
//							g_UsbHostMs[ms_index].result = USB_HOST_MS_RESULT_NO_RESPONSE;
//							USB_Dbg_Trace(USB_HOST_SET_EVENT, 0, 0);
//							kal_set_eg_events(g_UsbHostMs[ms_index].event_id, EVENT_USB_MS_DONE, KAL_OR);
						}
					}
				}

				/* Still in DATA state */
				g_UsbHostMs[ms_index].ms_state = USB_HOST_MS_DATA;
			}
			else
			{
				/* CSW state should be the following state */
				/* Send CSW */
				tr_result = USBD_Recv_Req(g_UsbHostMs[ms_index].common_info,g_UsbHostMs[ms_index].ep_rx_info, USBMS_CSW_LENGTH, &g_UsbHostMs[ms_index].CSW);

				if(tr_result == KAL_TRUE)
					g_UsbHostMs[ms_index].ms_state = USB_HOST_MS_CSW;					
				else
				{
					ASSERT(0);
//					g_UsbHostMs[ms_index].result = USB_HOST_MS_RESULT_NO_RESPONSE;
//					USB_Dbg_Trace(USB_HOST_SET_EVENT, 0, 0);
//					kal_set_eg_events(g_UsbHostMs[ms_index].event_id, EVENT_USB_MS_DONE, KAL_OR);
				}
			}
		}
	}
	else if(result == USB_HCD_STALL)
	{
		/* Clear data stall acoording to data direction */
		if(g_UsbHostMs[ms_index].data_dir == USB_HOST_MS_DATA_RECV)
		{
			g_UsbHostMs[ms_index].ms_state = USB_HOST_MS_DATA_CLEAR_STALL;
			g_UsbHostMs[ms_index].ms_cmd = USB_HOST_MS_EP0_CMD_CLEAR_STALL_IN;

			/* clear data01 */
			USBD_Clear_Data01(g_UsbHostMs[ms_index].common_info,g_UsbHostMs[ms_index].ep_rx_info);

			g_UsbHostMs[ms_index].stall_ep_dir = USB_EP_RX_DIR;

			/* Send message to USB task */
//			usb_host_attach = (usb_host_usbattach_ind_struct*)construct_local_para(sizeof(usb_host_usbattach_ind_struct), TD_CTRL);
//			usb_host_attach->usb_ip_port = usb_ip_port;
//			usb_host_attach->feature_index = ms_index;		
			
//			DRV_BuildPrimitive(usb_ilm, stack_get_active_module_id(),MOD_USB, MSG_ID_USB_MSHOST_CLEAR_STALL_IND, usb_host_attach);
//			msg_send_ext_queue(usb_ilm);					
			USBD_Clear_Feature(g_UsbHostMs[ms_index].common_info,g_UsbHostMs[ms_index].ep_rx_info, KAL_FALSE,USB_Host_Ms_Hdlr);	
		}
		else
		{
			g_UsbHostMs[ms_index].ms_state = USB_HOST_MS_DATA_CLEAR_STALL;
			g_UsbHostMs[ms_index].ms_cmd = USB_HOST_MS_EP0_CMD_CLEAR_STALL_OUT;

			/* clear data01 */
			USBD_Clear_Data01(g_UsbHostMs[ms_index].common_info,g_UsbHostMs[ms_index].ep_tx_info);
	
			g_UsbHostMs[ms_index].stall_ep_dir = USB_EP_TX_DIR;

			/* Send message to USB task */
//			usb_host_attach = (usb_host_usbattach_ind_struct*)construct_local_para(sizeof(usb_host_usbattach_ind_struct), TD_CTRL);
//			usb_host_attach->feature_index = ms_index;
			
//			DRV_BuildPrimitive(usb_ilm, stack_get_active_module_id(),MOD_USB, MSG_ID_USB_MSHOST_CLEAR_STALL_IND, usb_host_attach);
//			msg_send_ext_queue(usb_ilm);
			USBD_Clear_Feature(g_UsbHostMs[ms_index].common_info,g_UsbHostMs[ms_index].ep_tx_info, KAL_FALSE,USB_Host_Ms_Hdlr);
		}
	}
	else
	{
		if((result == USB_HCD_TIMEOUT)||(result == USB_HCD_DMA_TIMEOUT))
		{
			/* Other error condition, notify application about this error */
			g_UsbHostMs[ms_index].result = USB_HOST_MS_RESULT_TIMEOUT;
		}
		else
		{
			/* Other error condition, notify application about this error */
			g_UsbHostMs[ms_index].result = USB_HOST_MS_RESULT_NO_RESPONSE;
		}

		/* translate state to be NONE */
		g_UsbHostMs[ms_index].ms_state = USB_HOST_MS_NONE;

		USB_Dbg_Trace(USB_HOST_SET_EVENT, 0, 0);
		kal_set_eg_events(g_UsbHostMs[ms_index].event_id, EVENT_USB_MS_DONE, KAL_OR);
	}
}


/* Ctrl EP CSW handler, handle the state mcahine */
static void USB_Host_Ms_CSW_Hdler(kal_uint8 ms_index,USB_HCD_STATUS result, kal_uint32 param)
{
	UsbMs_CBW *CBW = (UsbMs_CBW*)g_UsbHostMs[ms_index].CBWdata;
//	ilm_struct *usb_ilm;
//	usb_host_usbattach_ind_struct *usb_host_attach;

	USB_Dbg_Trace(USB_HOST_MS_CSW_HDLR, (kal_uint32)result, param);

	if(result == USB_HCD_OK)
	{
		/* translate state to be NONE */
		g_UsbHostMs[ms_index].ms_state = USB_HOST_MS_NONE;

		/* Check the real received length */
		if((param != USBMS_CSW_LENGTH)||(CBW->dCBWTag != g_UsbHostMs[ms_index].CSW.dCSWTag))
		{
			g_UsbHostMs[ms_index].result = USB_HOST_MS_RESULT_TIMEOUT;
		}
		else
		{
			/* Check CSW result */
			if((kal_bool)g_UsbHostMs[ms_index].CSW.bmCSWStatus == KAL_TRUE)
				g_UsbHostMs[ms_index].result = USB_HOST_MS_RESULT_CSW_FAIL;
			else
				g_UsbHostMs[ms_index].result = USB_HOST_MS_RESULT_OK;
		}

		/* Notify application that the whole CBW, DATA, CSW is completed */
		USB_Dbg_Trace(USB_HOST_SET_EVENT, 0, 0);
		kal_set_eg_events(g_UsbHostMs[ms_index].event_id, EVENT_USB_MS_DONE, KAL_OR);
	}
	else if(result == USB_HCD_STALL)
	{
		if(g_UsbHostMs[ms_index].ms_state == USB_HOST_MS_CSW)
		{
			/* Receive STALL in the first CSW, clear stall and try CSW again after clear stall */
			g_UsbHostMs[ms_index].ms_state = USB_HOST_MS_CSW_CLEAR_STALL;
			g_UsbHostMs[ms_index].ms_cmd = USB_HOST_MS_EP0_CMD_CLEAR_STALL_IN;

			/* clear data01 */
			USBD_Clear_Data01(g_UsbHostMs[ms_index].common_info,g_UsbHostMs[ms_index].ep_rx_info);

			g_UsbHostMs[ms_index].stall_ep_dir = USB_EP_RX_DIR;

			/* Send message to USB task */
//			usb_host_attach = (usb_host_usbattach_ind_struct*)construct_local_para(sizeof(usb_host_usbattach_ind_struct), TD_CTRL);
//			usb_host_attach->usb_ip_port = usb_ip_port;
//			usb_host_attach->feature_index = ms_index;
	
//			DRV_BuildPrimitive(usb_ilm, stack_get_active_module_id(),MOD_USB, MSG_ID_USB_MSHOST_CLEAR_STALL_IND, usb_host_attach)			msg_send_ext_queue(usb_ilm);
			
			USBD_Clear_Feature(g_UsbHostMs[ms_index].common_info,g_UsbHostMs[ms_index].ep_rx_info, KAL_FALSE,USB_Host_Ms_Hdlr);
		}
		else if(g_UsbHostMs[ms_index].ms_state == USB_HOST_MS_CSW_CLEAR_STALL)
		{
			/* Receive STALL in the second CSW. Do not issue CSW any more
			     Notify application to handle the STALL result */
			g_UsbHostMs[ms_index].result = USB_HOST_MS_RESULT_STALL;

			/* translate state to be NONE */
			g_UsbHostMs[ms_index].ms_state = USB_HOST_MS_NONE;

			USB_Dbg_Trace(USB_HOST_SET_EVENT, 0, 0);
			kal_set_eg_events(g_UsbHostMs[ms_index].event_id, EVENT_USB_MS_DONE, KAL_OR);
		}
		
		
	}
	else
	{
		if((result == USB_HCD_TIMEOUT)||(result == USB_HCD_DMA_TIMEOUT))
		{
			/* Other error condition, notify application about this error */
			g_UsbHostMs[ms_index].result = USB_HOST_MS_RESULT_TIMEOUT;
		}
		else
		{
			/* Other error condition, notify application about this error */
			g_UsbHostMs[ms_index].result = USB_HOST_MS_RESULT_NO_RESPONSE;
		}

		/* translate state to be NONE */
		g_UsbHostMs[ms_index].ms_state = USB_HOST_MS_NONE;

		USB_Dbg_Trace(USB_HOST_SET_EVENT, 0, 0);
		kal_set_eg_events(g_UsbHostMs[ms_index].event_id, EVENT_USB_MS_DONE, KAL_OR);
	}
}


#endif  /* __OTG_ENABLE__ */


