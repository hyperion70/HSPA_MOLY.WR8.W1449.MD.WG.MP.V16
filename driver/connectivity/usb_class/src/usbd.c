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
 *    usbd.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements usb1.1 host driver
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
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#if defined(__OTG_ENABLE__)||defined(__IC_USB_ENABLE__)

#include "drv_comm.h"
#include "kal_public_defs.h" //MSBB change #include "stack_common.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "kal_public_api.h" //#include "stack_ltlcom.h" //MSBB change #include "app_ltlcom.h"       /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"
//#include "stacklib.h"
//#include "reg_base.h"
#include "usb_comm.h"
#include "drvsignals.h"
#include "eint.h"
///#include "kal_release.h"

#include "dcl.h"  
//#include "usb_drv.h"
//#include "usb_phy_drv.h"
#include "usb_adap.h"
#include "usb.h"
//#include "usb_resource.h"
#include "otg.h" 
//#include "usb_comm.h"
#include "usb_hcd.h"
//#include "usb_drv.h"
//#include "otg_drv.h"
#include "usb_custom.h"
#include "usb.h"
#include "usb_adap.h"
#include "usbd.h"
#include "usb_debug_tool.h"
#include "usb_trc.h"
//#include "kal_non_specific_general_types.h"
//#include "kal_release.h"
#include "usb_host_default_drv.h"
#include "usb_host_ms_drv.h"
#ifdef __USB_HOST_COM_PORT_SUPPORT__
#include "usb_host_acm_drv.h"
#endif
#ifdef __IC_USB_EEM_SUPPORT__
#include "icusb_eem_drv.h"
#endif
#ifdef __IC_USB_ICCD_SUPPORT__
#include "icusb_iccd_drv.h"
#endif
#include "usb_debug_tool.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
///#include "task_main_func.h"
//#include "nvram_common_defs.h"
#include "uart_sw.h"
#include "usbvideo_custom.h"
///#include "kal_active_module.h"
#include "drv_features.h"
#include "intrCtrl.h"
#include "kal_public_api.h" //#include "stack_ltlcom.h"
#include "kal_trace.h"
#include "nvram_struct.h"
#include "nvram_enums.h"
#include "kal_general_types.h"
#include "nvram_data_items.h"
#include "kal_public_api.h"
#include "kal_public_defs.h"


static USBD_Struct gUsbHost[USB_HOST_NUM];
static USBD_Common_Struct gUsbHost_Comm;

//static kal_uint8 g_usb_ip_port = 0;
//static kal_uint8 IP_PORT_TO_INDEX_ARRAY[USB_HOST_NUM];
//static kal_uint8 IP_INDEX_TO_PORT_ARRAY[USB_HOST_NUM];
static kal_bool QUERY_IF_SUPPORT_OTG_ARRAY[USB_HOST_NUM];
static kal_uint8 g_suspend_if = 0;

extern const kal_uint8  USB_IRQ_MAP[USB_IP_NUM];

DCL_HANDLE g_USB_HCD_Dcl_Handle = 0;

#if defined(__OTG_ENABLE__)

/* Should put the default driver in the last line */
USBD_ClassDriver_Struct  *USB_EXT_CLASS_DRV[] =
{
	&USB_Host_Ms_Drv,
#ifdef __USB_HOST_COM_PORT_SUPPORT__
	&USB_Host_Acm_Drv,
#endif
	&USB_Host_Ext_Default_Drv
};

#endif


#if defined(__IC_USB_ENABLE__)

/* Should put default driver in the last line */
USBD_ClassDriver_Struct * USB_INT_CLASS_DRV[] =
{
	&USB_Host_Ms_Drv,
	&USB_Host_Iccd_Drv,
	&USB_Host_Eem_Drv,
	&USB_Host_Int_Default_Drv
};

#endif


static void USBD_Attatch(kal_uint8 usb_ip_index, USB_HCD_STATUS result, kal_uint32 param);
static void USBD_Detach(kal_uint8 usb_ip_index, USB_HCD_STATUS result, kal_uint32 param);
static void USBD_Resume(kal_uint8 usb_ip_index, USB_HCD_STATUS result, kal_uint32 param);
static void USBD_Set_Address(USBH_Common_Struct common_str, kal_uint8 address);
static void USBD_Get_Descriptor(USBH_Common_Struct common_str, kal_uint16 type_index, kal_uint16 lang_id, kal_uint16 buflen, kal_uint8 *buffer);
static void USBD_Set_Configuration(USBH_Common_Struct common_strt, kal_uint16 config_value);
static void USBD_Ch9_Callback(kal_uint8 usb_ip_port, USB_HCD_STATUS result, kal_uint32 param);
static void USBD_EP0_Hdlr(kal_uint8 usb_ip_port, USB_HCD_STATUS result, kal_uint32 param);
static void USBD_Resume_Device(USBH_Common_Struct common_str);
static void USBD_Delay_Reset_Device(kal_uint8 usb_ip_port,USB_HCD_STATUS reset_reason, kal_uint32 timeout);


/************************************************************
	gUsbHost initialize and release functions
*************************************************************/

/* Initialize USBD information, called in OTG_Host_Up_Hdlr() */
void USBD_Init_Status(kal_uint8 usb_ip_port)
{
	kal_uint32 	index;
	kal_uint32 index2;


	if(gUsbHost_Comm.usbd_com_ep0_mutex_id == 0)
		gUsbHost_Comm.usbd_com_ep0_mutex_id = kal_create_mutex("USBD_COMM_EP0_MUTEX");

//	if(gUsbHost_Comm.usbd_com_ep0_event_id == 0)
//		gUsbHost_Comm.usbd_com_ep0_event_id = kal_create_event_group("USBD_COMM_EP0_EVENT");

	if(gUsbHost[usb_ip_port].usbd_ep0_mutex_id == 0)
		gUsbHost[usb_ip_port].usbd_ep0_mutex_id = kal_create_mutex("USBD_EP0_MUTEX");

	if(gUsbHost[usb_ip_port].usbd_resume_mutex_id == 0)
		gUsbHost[usb_ip_port].usbd_resume_mutex_id = kal_create_mutex("USBD_RESUME_MUTEX");

	if(gUsbHost[usb_ip_port].usbd_ep0_event_id == 0)
		gUsbHost[usb_ip_port].usbd_ep0_event_id = kal_create_event_group("USBD_EP0_EVENT");

	if(gUsbHost[usb_ip_port].usbd_resume_event_id == 0)
		gUsbHost[usb_ip_port].usbd_resume_event_id = kal_create_event_group("USBD_RESUME_EVENT");

	gUsbHost[usb_ip_port].desc_info.cfg_number = 0;
	gUsbHost[usb_ip_port].set_cfg_number = 0;

	for(index = 0; index < USBD_MAX_CFG_NUM; index++)
	{
		gUsbHost[usb_ip_port].desc_info.cfg_info[index].interface_number = 0;
		gUsbHost[usb_ip_port].desc_info.cfg_info[index].match_class_num = 0;
		gUsbHost[usb_ip_port].desc_info.cfg_info[index].active_if_index_map = 0;
		gUsbHost[usb_ip_port].desc_info.cfg_info[index].match_class_driver_point = 0;

		gUsbHost[usb_ip_port].desc_info.p_otg_desc[index] = NULL;

		for(index2 = 0; index2 < USBD_MAX_IF_PER_CFG; index2++)
		{
			gUsbHost[usb_ip_port].desc_info.cfg_info[index].match_class_driver_index[index2] = 0xFF;
		}
	}

	for(index = 0; index < USBD_MAX_INTERFACE_NUM; index++)
	{
		gUsbHost[usb_ip_port].desc_info.interface_info[index].ep_number = 0;
	}

	gUsbHost[usb_ip_port].ep0_state = USBD_EP0_NONE;
	gUsbHost[usb_ip_port].ch9_state = USBD_CH9_START;
	gUsbHost[usb_ip_port].b_suspend_mode = KAL_FALSE;
	gUsbHost[usb_ip_port].usb_ip_port = usb_ip_port;
}


/* Release USBD information */
void USBD_Release_Status(kal_uint8 usb_ip_port)
{
	/* Release all resource in case no detatch interrupt before disable interrupt */
//	USBD_Detach_Hdlr(usb_ip_port, USB_HCD_DETATCH, 0);
	USBD_Detach(usb_ip_port, USB_HCD_DETATCH, 0);
}


/* Each USB IP which supports host function should register itself only once */
void USBD_Register_Port_Info(kal_uint8 usb_ip_port, kal_bool b_is_ext_ip)
{
	kal_uint32 index;
//	kal_uint32 savedMask;
	kal_uint8 drv_num = 0;
	kal_uint8 drv_weight_num = 0;
	USBD_ClassDriver_Struct  **class_driver_ptr = NULL;
	kal_bool otg_support = KAL_FALSE;

/*
	savedMask = SaveAndSetIRQMask();
	for(index = 0; index < USB_HOST_NUM; index++)
	{
		if((g_usb_ip_port&(1<<index)) == 0)
		{
			g_usb_ip_port |= 1<<index;
			usb_ip_port = index;
			RestoreIRQMask(savedMask);
			break;
		}
	}
*/

	if(usb_ip_port >= USB_HOST_NUM)
		ASSERT(0);

	gUsbHost_Comm.host_match_param = USB_GetCustomFunc()->get_host_match_param_func();

	if(b_is_ext_ip == KAL_TRUE)
	{
#if defined(__OTG_ENABLE__)
		class_driver_ptr = USB_EXT_CLASS_DRV;
		drv_num = sizeof(USB_EXT_CLASS_DRV)/sizeof(USBD_ClassDriver_Struct*);
		drv_weight_num = gUsbHost_Comm.host_match_param->ext_drv_num;
#endif
	}
	else
	{
#if defined(__IC_USB_ENABLE__)
		class_driver_ptr = USB_INT_CLASS_DRV;
		drv_num = sizeof(USB_INT_CLASS_DRV)/sizeof(USBD_ClassDriver_Struct*);
		drv_weight_num = gUsbHost_Comm.host_match_param->int_drv_num;
#endif
	}

	if((drv_num > USBD_MAX_CLASS_DRIVER)||(drv_num <= 1)||(drv_num != drv_weight_num))
		EXT_ASSERT(0, drv_num, drv_weight_num, 0);

	for(index = 0; index < drv_num; index++)
	{
		gUsbHost[usb_ip_port].class_driver_ptr[index] = *(class_driver_ptr+index);
	}

	gUsbHost[usb_ip_port].default_class_driver_index = (drv_num -1);
//	*usb_ip_port_ptr = usb_ip_port;

	/* Build IP lookup table */
//	IP_PORT_TO_INDEX_ARRAY[usb_ip_port] = ip_index;
//	IP_INDEX_TO_PORT_ARRAY[ip_index] = usb_ip_port;

	if(b_is_ext_ip == KAL_TRUE)
	{
#if defined(__OTG_ENABLE__)
		otg_support = KAL_TRUE;
#endif
	}

	QUERY_IF_SUPPORT_OTG_ARRAY[usb_ip_port] = otg_support;
}


static void USBD_Resume_Device(USBH_Common_Struct common_str)
{
	kal_uint32 event_group;
	USB_HCD_CTRL_IP_NUM_T		dcl_data;	
	dcl_data.ip = (DCL_UINT8)common_str.usb_ip_port;
// Task level : resume device
// HISR level : (ex: HISR CBW), doesn't need to do anything

	if(kal_if_hisr() == KAL_TRUE)
		return;
	
// prevent next Task will enter & run to wait event  --> mutex protect
	kal_take_mutex(gUsbHost[common_str.usb_ip_port].usbd_resume_mutex_id);

// prevent Resume has just happend right here
	if(gUsbHost[common_str.usb_ip_port].b_suspend_mode == KAL_TRUE)
	{	
		gUsbHost[common_str.usb_ip_port].b_suspend_mode = KAL_FALSE; 
		g_suspend_if &= ~(gUsbHost[common_str.usb_ip_port].desc_info.cfg_info[gUsbHost[common_str.usb_ip_port].set_cfg_number-1].active_if_index_map);		
		
		if(QUERY_IF_SUPPORT_OTG_ARRAY[common_str.usb_ip_port] == KAL_FALSE)
		{	// only ICUSB support Remote wakeup  => race condition may happend
			DclUSB_HCD_Control(g_USB_HCD_Dcl_Handle, USB_HCD_CMD_USB_HCD_Send_Resume, (DCL_CTRL_DATA_T  *)&dcl_data);	
				 // USB_HCD_Resume_Recovery_Timeout --> class Resume handler
			
			// Wait until gpt timeout 20ms --> blocking API , return until Resume Signal done
			kal_retrieve_eg_events(gUsbHost[common_str.usb_ip_port].usbd_resume_event_id, EVENT_USBD_RESUME_DONE|EVENT_USBD_EP0_DETACH,
					KAL_OR_CONSUME, &event_group, KAL_SUSPEND); 			
		}
#if defined(__OTG_ENABLE__)		
		else	
		{
			/* A device wants to resume bus */
			DclOTG_DRV_Control(g_OTG_Dcl_Handle, OTG_DRV_CMD_A_RESUME_REQ, NULL);
//			OTG_A_Resume_Req();
		}
#endif		
	}
	else
	{
		g_suspend_if &= ~(1<<common_str.if_num);		
	}
	
	kal_give_mutex(gUsbHost[common_str.usb_ip_port].usbd_resume_mutex_id);

}



/*  =======================================================
	Class Driver usage API
========================================================  */



void USBD_Start_Setup_Cmd(USBH_Common_Struct common_str, Usb_Command *usbd_cmd, kal_uint8* data_ptr, USBD_EP0_DATA_DIR direction, kal_uint32 length, kal_bool b_is_from_class_drv, usbd_ep0_callback callback)
{
	kal_uint32 event_group;
	kal_uint8 usb_ip_port = common_str.usb_ip_port;
//	USBH_EP_Struct usb_ep_str;
	USB_HCD_CTRL_EP0_SETUP_REQ_T		dcl_data;
//	usb_ep_str.ep_num = 0;
//	usb_ep_str.direction = USB_EP_TX_DIR;
//	usb_ep_str.ep_type = USB_ENDPT_CTRL;

	dcl_data.common_str.if_num = (DCL_UINT32)(common_str.if_num);			
	dcl_data.common_str.usb_ip_port = (DCL_UINT8)(common_str.usb_ip_port);						
	dcl_data.usb_ep_str.ep_max_pkt_size = 64;
	dcl_data.usb_ep_str.ep_num = 0;
	dcl_data.usb_ep_str.ep_real_num = 0;	
	dcl_data.usb_ep_str.ep_type = (DCL_USB_ENDPT_TXFER_TYPE)USB_ENDPT_CTRL;
	dcl_data.usb_ep_str.direction = (DCL_USB_EP_DIRECTION)USB_EP_TX_DIR;	
	dcl_data.u2nBytes = 8;
	dcl_data.pSrc = &gUsbHost[usb_ip_port].ep0_status.setup_cmd;
		
		
	if(callback == NULL) 
		ASSERT(0);

	if(b_is_from_class_drv == KAL_TRUE)
	{
		if((kal_if_lisr() == KAL_TRUE)||(kal_if_hisr() == KAL_TRUE))
			ASSERT(0);
		
		kal_take_mutex(gUsbHost[usb_ip_port].usbd_ep0_mutex_id);

		USBD_Resume_Device(common_str);

		USB_Dbg_Trace(USBD_EP0_CMD_TAKE_MUTEX,  0, 0);

		if(gUsbHost[usb_ip_port].ch9_state == USBD_CH9_STOP)
		{
			// It should be due to cable out
			/* Can not be removed since detach only set event once */
			kal_retrieve_eg_events(gUsbHost[usb_ip_port].usbd_ep0_event_id, EVENT_USBD_EP0_DONE|EVENT_USBD_EP0_DETACH,
						KAL_OR_CONSUME, &event_group, KAL_NO_SUSPEND);
			USB_Dbg_Trace(USBD_EP0_CMD_REC_EVENT,  1, 0);

			USB_Dbg_Trace(USBD_EP0_CMD_GIVE_MUTEX,  1, 0);
			kal_give_mutex(gUsbHost[usb_ip_port].usbd_ep0_mutex_id);
			return;
		}
	}
	else
	{
//		if(kal_if_hisr() == KAL_FALSE)  //QQ Test --> connect handler(task , not class drive) 
//			ASSERT(0);
	}

	/* To prevent USB disconn intr coming during this moment, so we cannot flush this ep0 packet */
	IRQMask(USB_IRQ_MAP[usb_ip_port]);

	if(gUsbHost[usb_ip_port].ch9_state != USBD_CH9_STOP)
	{
		kal_mem_cpy((kal_uint8*)&gUsbHost[usb_ip_port].ep0_status.setup_cmd, (kal_uint8*)usbd_cmd, sizeof(Usb_Command)/sizeof(kal_uint8));

		gUsbHost[usb_ip_port].ep0_status.data_ptr = data_ptr;
		gUsbHost[usb_ip_port].ep0_status.ep0_data_dir = direction;
		gUsbHost[usb_ip_port].ep0_status.sofar = 0;
		gUsbHost[usb_ip_port].ep0_status.todo = length;
		gUsbHost[usb_ip_port].ep0_callback = callback;
		gUsbHost[usb_ip_port].ep0_state = USBD_EP0_SETUP;

		DclUSB_HCD_Control(g_USB_HCD_Dcl_Handle, USB_HCD_CMD_USB_HCD_EP0_Setup_Req, (DCL_CTRL_DATA_T  *)&dcl_data);	
	}

	if(USBD_Get_UnMask_Irq(common_str) == KAL_TRUE)
	{
		IRQUnmask(USB_IRQ_MAP[usb_ip_port]);
	}

	if(b_is_from_class_drv == KAL_TRUE)
	{
		/* Wait until command done */
		kal_retrieve_eg_events(gUsbHost[usb_ip_port].usbd_ep0_event_id, EVENT_USBD_EP0_DONE|EVENT_USBD_EP0_DETACH,
						KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
		USB_Dbg_Trace(USBD_EP0_CMD_REC_EVENT,  2, 0);

		USB_Dbg_Trace(USBD_EP0_CMD_GIVE_MUTEX,  2, 0);
		kal_give_mutex(gUsbHost[usb_ip_port].usbd_ep0_mutex_id);
	}
}


kal_bool USBD_Send_Req(USBH_Common_Struct common_str,USBH_EP_Struct ep_str, kal_uint16 nBytes, void *pSrc)
{	
	USB_HCD_CTRL_EP_DATA_TXFER_T		dcl_data;
//	kal_bool	result;
	
	USBD_Resume_Device(common_str);
		
	dcl_data.common_str.if_num = (DCL_UINT32)(common_str.if_num);			
	dcl_data.common_str.usb_ip_port = (DCL_UINT8)(common_str.usb_ip_port);						
	dcl_data.usb_ep_str.ep_max_pkt_size = (DCL_UINT16)(ep_str.ep_max_pkt_size);
	dcl_data.usb_ep_str.ep_num = (DCL_UINT8)(ep_str.ep_num);
	dcl_data.usb_ep_str.ep_real_num = (DCL_UINT8)(ep_str.ep_real_num);	
	dcl_data.usb_ep_str.ep_type = (DCL_USB_ENDPT_TXFER_TYPE)(ep_str.ep_type);
	dcl_data.usb_ep_str.direction = (DCL_USB_EP_DIRECTION)(ep_str.direction);		
	dcl_data.u2nBytes = (DCL_UINT16)nBytes;
	dcl_data.pData = pSrc;
		
	DclUSB_HCD_Control(g_USB_HCD_Dcl_Handle, USB_HCD_CMD_USB_HCD_Send_Req, (DCL_CTRL_DATA_T  *)&dcl_data);
	return (kal_bool)dcl_data.return_value;
}

kal_bool USBD_Recv_Req(USBH_Common_Struct common_str,USBH_EP_Struct ep_str, kal_uint16 nBytes, void *pDst)
{
	USB_HCD_CTRL_EP_DATA_TXFER_T		dcl_data;
		
	USBD_Resume_Device(common_str);
	
	dcl_data.common_str.if_num = (DCL_UINT32)(common_str.if_num);			
	dcl_data.common_str.usb_ip_port = (DCL_UINT8)(common_str.usb_ip_port);						
	dcl_data.usb_ep_str.ep_max_pkt_size = (DCL_UINT16)(ep_str.ep_max_pkt_size);
	dcl_data.usb_ep_str.ep_num = (DCL_UINT8)(ep_str.ep_num);
	dcl_data.usb_ep_str.ep_real_num = (DCL_UINT8)(ep_str.ep_real_num);	
	dcl_data.usb_ep_str.ep_type = (DCL_USB_ENDPT_TXFER_TYPE)(ep_str.ep_type);
	dcl_data.usb_ep_str.direction = (DCL_USB_EP_DIRECTION)(ep_str.direction);		
	dcl_data.u2nBytes = (DCL_UINT16)nBytes;
	dcl_data.pData = pDst;
	
	DclUSB_HCD_Control(g_USB_HCD_Dcl_Handle, USB_HCD_CMD_USB_HCD_Recv_Req, (DCL_CTRL_DATA_T  *)&dcl_data);	
	return (kal_bool)dcl_data.return_value;
}


void USBD_Suspend_Req(USBH_Common_Struct common_str)
{
//	kal_uint32 index;

	if(((g_suspend_if&(1<<common_str.if_num)) != 0)||(gUsbHost[common_str.usb_ip_port].set_cfg_number == 0))
		ASSERT(0);

	g_suspend_if |= 1<<common_str.if_num;

/*	

	if(gUsbHost[common_str.usb_ip_port].desc_info.cfg_info[gUsbHost[common_str.usb_ip_port].set_cfg_number-1].active_if_index_map == g_suspend_if)
	{
		gUsbHost[common_str.usb_ip_port].b_suspend_mode = KAL_TRUE;

		if(QUERY_IF_SUPPORT_OTG_ARRAY[common_str.usb_ip_port] == KAL_FALSE)
		{
		      // IC USB : should be called in HISR level
		      //MS: GPT Timeout , EEM: SuspendHint , ICCD: GPT Timeout
			if(kal_if_hisr() == KAL_FALSE)
				ASSERT(0);

			USB_HCD_Send_Suspend(common_str.usb_ip_port); // DCL
			// turn off power
		}
#if defined(__OTG_ENABLE__)
		else
		{
			// A device wants to suspend bus 
		DclOTG_DRV_Control(g_OTG_Dcl_Handle, OTG_DRV_CMD_A_SUSPEND_REQ, NULL);
//		OTG_A_Suspend_Req();
		}
#endif

		// Call the suspend functions
		if((gUsbHost[common_str.usb_ip_port].desc_info.cfg_info[gUsbHost[common_str.usb_ip_port].set_cfg_number-1].match_class_num == 0)||
			(gUsbHost[common_str.usb_ip_port].desc_info.cfg_info[gUsbHost[common_str.usb_ip_port].set_cfg_number-1].interface_number == 0))
			ASSERT(0);

		// set_cfg_number != 0 must match some drivers 
		for(index = 0; index < gUsbHost[common_str.usb_ip_port].desc_info.cfg_info[gUsbHost[common_str.usb_ip_port].set_cfg_number-1].interface_number; index++)
		{
			if(gUsbHost[common_str.usb_ip_port].desc_info.cfg_info[gUsbHost[common_str.usb_ip_port].set_cfg_number-1].match_class_driver_index[index] < gUsbHost[common_str.usb_ip_port].default_class_driver_index)
				gUsbHost[common_str.usb_ip_port].class_driver_ptr[gUsbHost[common_str.usb_ip_port].desc_info.cfg_info[gUsbHost[common_str.usb_ip_port].set_cfg_number-1].match_class_driver_index[index]]->suspend(common_str.usb_ip_port);
		}
	}
*/	
}

void USBD_Reset_Req(USBH_Common_Struct common_str)
{
	USB_HCD_CTRL_RESET_T		dcl_data;
	dcl_data.ip = (DCL_UINT8)(common_str.usb_ip_port);
	dcl_data.reset_reason = (DCL_USB_HCD_STATUS)USB_HCD_OK;

	USBD_Resume_Device(common_str);

//	USB_HCD_Disconn_Hdlr(common_str.usb_ip_port);  // 1.release drive  2 disable interrupt 3 notice class driver
	DclUSB_HCD_Control(g_USB_HCD_Dcl_Handle, USB_HCD_CMD_USB_HCD_Disconn_Hdlr, (DCL_CTRL_DATA_T  *)&dcl_data);		
	// because Vsim doesn't turn off --> DP still high -> Connect interrupt
	DclUSB_HCD_Control(g_USB_HCD_Dcl_Handle, USB_HCD_CMD_USB_HCD_Reset_Device, (DCL_CTRL_DATA_T  *)&dcl_data);		
}

void USBD_Register_Drv_Info(USBH_Common_Struct common_str,USB_HCD_HDLR_TYPE type, USBH_EP_Struct ep_str, usb_hcd_intr_handler_ptr hdlr)
{
	USB_HCD_CTRL_REGISTER_DRV_INFO_T		dcl_data;

	dcl_data.ip = (DCL_UINT8)(common_str.usb_ip_port);
	dcl_data.type = (DCL_USB_HCD_HDLR_TYPE)type;
	dcl_data.u4ep_num = (DCL_UINT32)(ep_str.ep_num);
	dcl_data.hdlr = (DCL_USB_HCD_INTR_HDLR)hdlr;
	
	DclUSB_HCD_Control(g_USB_HCD_Dcl_Handle, USB_HCD_CMD_USB_HCD_Register_Drv_Info, (DCL_CTRL_DATA_T  *)&dcl_data);	
}

kal_uint8  USBD_HW_Mapping_EP(USBH_Common_Struct common_str,USB_EP_DIRECTION direction)
{
	USB_HCD_CTRL_EP_MAPPING_T  dcl_data;
	
	dcl_data.ip = (DCL_UINT8)(common_str.usb_ip_port);
	dcl_data.direction = (DCL_USB_EP_DIRECTION)direction;

	DclUSB_HCD_Control(g_USB_HCD_Dcl_Handle, USB_HCD_CMD_USB_HCD_HW_Mapping_EP, (DCL_CTRL_DATA_T  *)&dcl_data);
	return (kal_uint8)dcl_data.return_value;
}

void USBD_Dis_Attach(USBH_Common_Struct common_str)
{
	USB_HCD_CTRL_IP_NUM_T		dcl_data;
	dcl_data.ip = (DCL_UINT8)(common_str.usb_ip_port);
	
	DclUSB_HCD_Control(g_USB_HCD_Dcl_Handle, USB_HCD_CMD_USB_HCD_Dis_Attach, (DCL_CTRL_DATA_T  *)&dcl_data);	
}

void USBD_En_Attach(USBH_Common_Struct common_str)
{
	USB_HCD_CTRL_IP_NUM_T		dcl_data;
	dcl_data.ip = (DCL_UINT8)(common_str.usb_ip_port);

	DclUSB_HCD_Control(g_USB_HCD_Dcl_Handle, USB_HCD_CMD_USB_HCD_En_Attach, (DCL_CTRL_DATA_T  *)&dcl_data);		
}

void USBD_Config_TxEP_Type(USBH_Common_Struct common_str,USBH_EP_Struct ep_str,kal_bool b_is_switch_to_dma)
{
	USB_HCD_CTRL_EP_CTRL_FUNC_5_T		dcl_data;

	dcl_data.common_str.if_num = (DCL_UINT32)(common_str.if_num);			
	dcl_data.common_str.usb_ip_port = (DCL_UINT8)(common_str.usb_ip_port);						
	dcl_data.usb_ep_str.ep_max_pkt_size = (DCL_UINT16)(ep_str.ep_max_pkt_size);
	dcl_data.usb_ep_str.ep_num = (DCL_UINT8)(ep_str.ep_num);
	dcl_data.usb_ep_str.ep_real_num = (DCL_UINT8)(ep_str.ep_real_num);	
	dcl_data.usb_ep_str.ep_type = (DCL_USB_ENDPT_TXFER_TYPE)(ep_str.ep_type);
	dcl_data.usb_ep_str.direction = (DCL_USB_EP_DIRECTION)(ep_str.direction);
	dcl_data.set = (DCL_BOOL)b_is_switch_to_dma;
	
	DclUSB_HCD_Control(g_USB_HCD_Dcl_Handle, USB_HCD_CMD_USB_HCD_Config_TxEP_Type, (DCL_CTRL_DATA_T  *)&dcl_data);		
}

void USBD_Config_RxEP_Type(USBH_Common_Struct common_str,USBH_EP_Struct ep_str,kal_bool b_is_switch_to_dma)
{
	USB_HCD_CTRL_EP_CTRL_FUNC_5_T		dcl_data;
	dcl_data.common_str.if_num = (DCL_UINT32)(common_str.if_num);			
	dcl_data.common_str.usb_ip_port = (DCL_UINT8)(common_str.usb_ip_port);						
	dcl_data.usb_ep_str.ep_max_pkt_size = (DCL_UINT16)(ep_str.ep_max_pkt_size);
	dcl_data.usb_ep_str.ep_num = (DCL_UINT8)(ep_str.ep_num);
	dcl_data.usb_ep_str.ep_real_num = (DCL_UINT8)(ep_str.ep_real_num);	
	dcl_data.usb_ep_str.ep_type = (DCL_USB_ENDPT_TXFER_TYPE)(ep_str.ep_type);
	dcl_data.usb_ep_str.direction = (DCL_USB_EP_DIRECTION)(ep_str.direction);
	dcl_data.set = (DCL_BOOL)b_is_switch_to_dma;
	
	DclUSB_HCD_Control(g_USB_HCD_Dcl_Handle, USB_HCD_CMD_USB_HCD_Config_RxEP_Type, (DCL_CTRL_DATA_T  *)&dcl_data);			
}

void USBD_EP_Interval(USBH_Common_Struct common_str,USBH_EP_Struct ep_str,kal_uint8 interval)
{
	USB_HCD_CTRL_EP_CTRL_FUNC_2_T		dcl_data;
	dcl_data.common_str.if_num = (DCL_UINT32)(common_str.if_num);			
	dcl_data.common_str.usb_ip_port = (DCL_UINT8)(common_str.usb_ip_port);						
	dcl_data.usb_ep_str.ep_max_pkt_size = (DCL_UINT16)(ep_str.ep_max_pkt_size);
	dcl_data.usb_ep_str.ep_num = (DCL_UINT8)(ep_str.ep_num);
	dcl_data.usb_ep_str.ep_real_num = (DCL_UINT8)(ep_str.ep_real_num);	
	dcl_data.usb_ep_str.ep_type = (DCL_USB_ENDPT_TXFER_TYPE)(ep_str.ep_type);
	dcl_data.usb_ep_str.direction = (DCL_USB_EP_DIRECTION)(ep_str.direction);
	dcl_data.interval = (DCL_UINT8)interval;

	DclUSB_HCD_Control(g_USB_HCD_Dcl_Handle, USB_HCD_CMD_USB_HCD_EP_Interval, (DCL_CTRL_DATA_T  *)&dcl_data);
}

void USBD_RxEPInit(USBH_Common_Struct common_str,USBH_EP_Struct ep_str)
{
	USB_HCD_CTRL_EP_CTRL_FUNC_1_T		dcl_data;
	
	dcl_data.common_str.if_num = (DCL_UINT32)(common_str.if_num);			
	dcl_data.common_str.usb_ip_port = (DCL_UINT8)(common_str.usb_ip_port);						
	dcl_data.usb_ep_str.ep_max_pkt_size = (DCL_UINT16)(ep_str.ep_max_pkt_size);
	dcl_data.usb_ep_str.ep_num = (DCL_UINT8)(ep_str.ep_num);
	dcl_data.usb_ep_str.ep_real_num = (DCL_UINT8)(ep_str.ep_real_num);	
	dcl_data.usb_ep_str.ep_type = (DCL_USB_ENDPT_TXFER_TYPE)(ep_str.ep_type);
	dcl_data.usb_ep_str.direction = (DCL_USB_EP_DIRECTION)(ep_str.direction);

	DclUSB_HCD_Control(g_USB_HCD_Dcl_Handle, USB_HCD_CMD_USB_HCD_RxEPInit, (DCL_CTRL_DATA_T  *)&dcl_data);
}


void USBD_TxEPInit(USBH_Common_Struct common_str,USBH_EP_Struct ep_str)
{
	USB_HCD_CTRL_EP_CTRL_FUNC_1_T		dcl_data;
	dcl_data.common_str.if_num = (DCL_UINT32)(common_str.if_num);			
	dcl_data.common_str.usb_ip_port = (DCL_UINT8)(common_str.usb_ip_port);						
	dcl_data.usb_ep_str.ep_max_pkt_size = (DCL_UINT16)(ep_str.ep_max_pkt_size);
	dcl_data.usb_ep_str.ep_num = (DCL_UINT8)(ep_str.ep_num);
	dcl_data.usb_ep_str.ep_real_num = (DCL_UINT8)(ep_str.ep_real_num);	
	dcl_data.usb_ep_str.ep_type = (DCL_USB_ENDPT_TXFER_TYPE)(ep_str.ep_type);
	dcl_data.usb_ep_str.direction = (DCL_USB_EP_DIRECTION)(ep_str.direction);

	DclUSB_HCD_Control(g_USB_HCD_Dcl_Handle, USB_HCD_CMD_USB_HCD_TxEPInit, (DCL_CTRL_DATA_T  *)&dcl_data);
}


void USBD_RxEPEn(USBH_Common_Struct common_str,USBH_EP_Struct ep_str, kal_uint8 interval, kal_bool bDMA)
{
	USB_HCD_CTRL_EP_ENABLE_T		dcl_data;
	dcl_data.common_str.if_num = (DCL_UINT32)(common_str.if_num);			
	dcl_data.common_str.usb_ip_port = (DCL_UINT8)(common_str.usb_ip_port);						
	dcl_data.usb_ep_str.ep_max_pkt_size = (DCL_UINT16)(ep_str.ep_max_pkt_size);
	dcl_data.usb_ep_str.ep_num = (DCL_UINT8)(ep_str.ep_num);
	dcl_data.usb_ep_str.ep_real_num = (DCL_UINT8)(ep_str.ep_real_num);	
	dcl_data.usb_ep_str.ep_type = (DCL_USB_ENDPT_TXFER_TYPE)(ep_str.ep_type);
	dcl_data.usb_ep_str.direction = (DCL_USB_EP_DIRECTION)(ep_str.direction);	
	dcl_data.u1interval = (DCL_UINT8)interval;
	dcl_data.fgbDMA = (DCL_BOOL)bDMA;

	DclUSB_HCD_Control(g_USB_HCD_Dcl_Handle, USB_HCD_CMD_USB_HCD_RxEPEn, (DCL_CTRL_DATA_T  *)&dcl_data);
}

void USBD_TxEPEn(USBH_Common_Struct common_str,USBH_EP_Struct ep_str, kal_uint8 interval, kal_bool bDMA)
{
	USB_HCD_CTRL_EP_ENABLE_T		dcl_data;
	dcl_data.common_str.if_num = (DCL_UINT32)(common_str.if_num);			
	dcl_data.common_str.usb_ip_port = (DCL_UINT8)(common_str.usb_ip_port);						
	dcl_data.usb_ep_str.ep_max_pkt_size = (DCL_UINT16)(ep_str.ep_max_pkt_size);
	dcl_data.usb_ep_str.ep_num = (DCL_UINT8)(ep_str.ep_num);
	dcl_data.usb_ep_str.ep_real_num = (DCL_UINT8)(ep_str.ep_real_num);	
	dcl_data.usb_ep_str.ep_type = (DCL_USB_ENDPT_TXFER_TYPE)(ep_str.ep_type);
	dcl_data.usb_ep_str.direction = (DCL_USB_EP_DIRECTION)(ep_str.direction);	
	dcl_data.u1interval = (DCL_UINT8)interval;
	dcl_data.fgbDMA = (DCL_BOOL)bDMA;

	DclUSB_HCD_Control(g_USB_HCD_Dcl_Handle, USB_HCD_CMD_USB_HCD_TxEPEn, (DCL_CTRL_DATA_T  *)&dcl_data);
}


void USBD_TxEPDis(USBH_Common_Struct common_str,USBH_EP_Struct ep_str, kal_bool bDMA)
{
	USB_HCD_CTRL_EP_DISABLE_T		dcl_data;
	dcl_data.common_str.if_num = (DCL_UINT32)(common_str.if_num);			
	dcl_data.common_str.usb_ip_port = (DCL_UINT8)(common_str.usb_ip_port);						
	dcl_data.usb_ep_str.ep_max_pkt_size = (DCL_UINT16)(ep_str.ep_max_pkt_size);
	dcl_data.usb_ep_str.ep_num = (DCL_UINT8)(ep_str.ep_num);
	dcl_data.usb_ep_str.ep_real_num = (DCL_UINT8)(ep_str.ep_real_num);	
	dcl_data.usb_ep_str.ep_type = (DCL_USB_ENDPT_TXFER_TYPE)(ep_str.ep_type);
	dcl_data.usb_ep_str.direction = (DCL_USB_EP_DIRECTION)(ep_str.direction);	
	dcl_data.fgbDMA = (DCL_BOOL)bDMA;
			
	DclUSB_HCD_Control(g_USB_HCD_Dcl_Handle, USB_HCD_CMD_USB_HCD_TxEPDis, (DCL_CTRL_DATA_T  *)&dcl_data);
}


void USBD_RxEPDis(USBH_Common_Struct common_str,USBH_EP_Struct ep_str, kal_bool bDMA)
{
	USB_HCD_CTRL_EP_DISABLE_T		dcl_data;
	dcl_data.common_str.if_num = (DCL_UINT32)(common_str.if_num);			
	dcl_data.common_str.usb_ip_port = (DCL_UINT8)(common_str.usb_ip_port);						
	dcl_data.usb_ep_str.ep_max_pkt_size = (DCL_UINT16)(ep_str.ep_max_pkt_size);
	dcl_data.usb_ep_str.ep_num = (DCL_UINT8)(ep_str.ep_num);
	dcl_data.usb_ep_str.ep_real_num = (DCL_UINT8)(ep_str.ep_real_num);	
	dcl_data.usb_ep_str.ep_type = (DCL_USB_ENDPT_TXFER_TYPE)(ep_str.ep_type);
	dcl_data.usb_ep_str.direction = (DCL_USB_EP_DIRECTION)(ep_str.direction);	
	dcl_data.fgbDMA = (DCL_BOOL)bDMA;
			
	DclUSB_HCD_Control(g_USB_HCD_Dcl_Handle, USB_HCD_CMD_USB_HCD_RxEPDis, (DCL_CTRL_DATA_T  *)&dcl_data);
}


void USBD_EPFIFORead(USBH_Common_Struct common_str,USBH_EP_Struct ep_str, kal_uint16 nBytes, void *pDst)
{
	USB_HCD_CTRL_EP_DATA_TXFER_T		dcl_data;
	dcl_data.common_str.if_num = (DCL_UINT32)(common_str.if_num);			
	dcl_data.common_str.usb_ip_port = (DCL_UINT8)(common_str.usb_ip_port);						
	dcl_data.usb_ep_str.ep_max_pkt_size = (DCL_UINT16)(ep_str.ep_max_pkt_size);
	dcl_data.usb_ep_str.ep_num = (DCL_UINT8)(ep_str.ep_num);
	dcl_data.usb_ep_str.ep_real_num = (DCL_UINT8)(ep_str.ep_real_num);	
	dcl_data.usb_ep_str.ep_type = (DCL_USB_ENDPT_TXFER_TYPE)(ep_str.ep_type);
	dcl_data.usb_ep_str.direction = (DCL_USB_EP_DIRECTION)(ep_str.direction);	
	dcl_data.u2nBytes = (DCL_UINT16)nBytes;
	dcl_data.pData = pDst;

	DclUSB_HCD_Control(g_USB_HCD_Dcl_Handle, USB_HCD_CMD_USB_HCD_EPFIFORead, (DCL_CTRL_DATA_T  *)&dcl_data);	
}


void USBD_EPFIFOWrite(USBH_Common_Struct common_str,USBH_EP_Struct ep_str, kal_uint16 nBytes, void *pDst)
{
	USB_HCD_CTRL_EP_DATA_TXFER_T		dcl_data;
	dcl_data.common_str.if_num = (DCL_UINT32)(common_str.if_num);			
	dcl_data.common_str.usb_ip_port = (DCL_UINT8)(common_str.usb_ip_port);						
	dcl_data.usb_ep_str.ep_max_pkt_size = (DCL_UINT16)(ep_str.ep_max_pkt_size);
	dcl_data.usb_ep_str.ep_num = (DCL_UINT8)(ep_str.ep_num);
	dcl_data.usb_ep_str.ep_real_num = (DCL_UINT8)(ep_str.ep_real_num);	
	dcl_data.usb_ep_str.ep_type = (DCL_USB_ENDPT_TXFER_TYPE)(ep_str.ep_type);
	dcl_data.usb_ep_str.direction = (DCL_USB_EP_DIRECTION)(ep_str.direction);	
	dcl_data.u2nBytes = (DCL_UINT16)nBytes;
	dcl_data.pData = pDst;

	DclUSB_HCD_Control(g_USB_HCD_Dcl_Handle, USB_HCD_CMD_USB_HCD_EPFIFOWrite, (DCL_CTRL_DATA_T  *)&dcl_data);	
}


kal_uint16 USBD_EP0_Data_Length(USBH_Common_Struct common_str)
{
	USB_HCD_CTRL_EP_CTRL_FUNC_3_T		dcl_data;
	dcl_data.common_str.if_num = (DCL_UINT32)(common_str.if_num);			
	dcl_data.common_str.usb_ip_port = (DCL_UINT8)(common_str.usb_ip_port);	
		
	DclUSB_HCD_Control(g_USB_HCD_Dcl_Handle, USB_HCD_CMD_USB_HCD_EP0_Data_Length, (DCL_CTRL_DATA_T  *)&dcl_data);
	return (kal_uint16)dcl_data.return_value;
}


kal_uint32 USBD_EP_Rx_Pkt_Len(USBH_Common_Struct common_str,USBH_EP_Struct ep_str)
{
	USB_HCD_CTRL_EP_CTRL_FUNC_4_T		dcl_data;
	dcl_data.common_str.if_num = (DCL_UINT32)(common_str.if_num);			
	dcl_data.common_str.usb_ip_port = (DCL_UINT8)(common_str.usb_ip_port);						
	dcl_data.usb_ep_str.ep_max_pkt_size = (DCL_UINT16)(ep_str.ep_max_pkt_size);
	dcl_data.usb_ep_str.ep_num = (DCL_UINT8)(ep_str.ep_num);
	dcl_data.usb_ep_str.ep_real_num = (DCL_UINT8)(ep_str.ep_real_num);	
	dcl_data.usb_ep_str.ep_type = (DCL_USB_ENDPT_TXFER_TYPE)(ep_str.ep_type);
	dcl_data.usb_ep_str.direction = (DCL_USB_EP_DIRECTION)(ep_str.direction);	
		
	DclUSB_HCD_Control(g_USB_HCD_Dcl_Handle, USB_HCD_CMD_USB_HCD_EP_Rx_Pkt_Len, (DCL_CTRL_DATA_T  *)&dcl_data);
	return (kal_uint32)dcl_data.return_value;
}


void USBD_Clear_Data01(USBH_Common_Struct common_str,USBH_EP_Struct ep_str)	
{
	USB_HCD_CTRL_EP_CTRL_FUNC_1_T		dcl_data;
	dcl_data.common_str.if_num = (DCL_UINT32)(common_str.if_num);			
	dcl_data.common_str.usb_ip_port = (DCL_UINT8)(common_str.usb_ip_port);						
	dcl_data.usb_ep_str.ep_max_pkt_size = (DCL_UINT16)(ep_str.ep_max_pkt_size);
	dcl_data.usb_ep_str.ep_num = (DCL_UINT8)(ep_str.ep_num);
	dcl_data.usb_ep_str.ep_real_num = (DCL_UINT8)(ep_str.ep_real_num);	
	dcl_data.usb_ep_str.ep_type = (DCL_USB_ENDPT_TXFER_TYPE)(ep_str.ep_type);
	dcl_data.usb_ep_str.direction = (DCL_USB_EP_DIRECTION)(ep_str.direction);	
		
	DclUSB_HCD_Control(g_USB_HCD_Dcl_Handle, USB_HCD_CMD_USB_HCD_Clear_Data01, (DCL_CTRL_DATA_T  *)&dcl_data);	
}


void USBD_Get_DMA_Channel(USBH_Common_Struct common_str,USBH_EP_Struct usb_tx_str, USBH_EP_Struct usb_rx_str, USB_EP_DIRECTION direction, kal_bool same_chan)
{
	USB_HCD_CTRL_DMA_CHANNEL_FUNC_T		dcl_data;
	dcl_data.common_str.if_num = (DCL_UINT32)(common_str.if_num);			
	dcl_data.common_str.usb_ip_port = (DCL_UINT8)(common_str.usb_ip_port);
	dcl_data.usb_tx_str.ep_max_pkt_size = (DCL_UINT16)(usb_tx_str.ep_max_pkt_size);
	dcl_data.usb_tx_str.ep_num = (DCL_UINT8)(usb_tx_str.ep_num);
	dcl_data.usb_tx_str.ep_real_num = (DCL_UINT8)(usb_tx_str.ep_real_num);	
	dcl_data.usb_tx_str.ep_type = (DCL_USB_ENDPT_TXFER_TYPE)(usb_tx_str.ep_type);
	dcl_data.usb_tx_str.direction = (DCL_USB_EP_DIRECTION)(usb_tx_str.direction);		
	dcl_data.usb_rx_str.ep_max_pkt_size = (DCL_UINT16)(usb_rx_str.ep_max_pkt_size);
	dcl_data.usb_rx_str.ep_num = (DCL_UINT8)(usb_rx_str.ep_num);
	dcl_data.usb_rx_str.ep_real_num = (DCL_UINT8)(usb_rx_str.ep_real_num);	
	dcl_data.usb_rx_str.ep_type = (DCL_USB_ENDPT_TXFER_TYPE)(usb_rx_str.ep_type);
	dcl_data.usb_rx_str.direction = (DCL_USB_EP_DIRECTION)(usb_rx_str.direction);		
	dcl_data.direction = (DCL_USB_EP_DIRECTION)direction;
	dcl_data.same_chan = (DCL_BOOL)same_chan;

	DclUSB_HCD_Control(g_USB_HCD_Dcl_Handle, USB_HCD_CMD_USB_HCD_Get_DMA_Channel, (DCL_CTRL_DATA_T  *)&dcl_data);
}


void USBD_Free_DMA_Channel(USBH_Common_Struct common_str,USBH_EP_Struct usb_tx_str, USBH_EP_Struct usb_rx_str, USB_EP_DIRECTION direction, kal_bool same_chan)
{
	USB_HCD_CTRL_DMA_CHANNEL_FUNC_T		dcl_data;
	dcl_data.common_str.if_num = (DCL_UINT32)(common_str.if_num);			
	dcl_data.common_str.usb_ip_port = (DCL_UINT8)(common_str.usb_ip_port);
	dcl_data.usb_tx_str.ep_max_pkt_size = (DCL_UINT16)(usb_tx_str.ep_max_pkt_size);
	dcl_data.usb_tx_str.ep_num = (DCL_UINT8)(usb_tx_str.ep_num);
	dcl_data.usb_tx_str.ep_real_num = (DCL_UINT8)(usb_tx_str.ep_real_num);	
	dcl_data.usb_tx_str.ep_type = (DCL_USB_ENDPT_TXFER_TYPE)(usb_tx_str.ep_type);
	dcl_data.usb_tx_str.direction = (DCL_USB_EP_DIRECTION)(usb_tx_str.direction);		
	dcl_data.usb_rx_str.ep_max_pkt_size = (DCL_UINT16)(usb_rx_str.ep_max_pkt_size);
	dcl_data.usb_rx_str.ep_num = (DCL_UINT8)(usb_rx_str.ep_num);
	dcl_data.usb_rx_str.ep_real_num = (DCL_UINT8)(usb_rx_str.ep_real_num);	
	dcl_data.usb_rx_str.ep_type = (DCL_USB_ENDPT_TXFER_TYPE)(usb_rx_str.ep_type);
	dcl_data.usb_rx_str.direction = (DCL_USB_EP_DIRECTION)(usb_rx_str.direction);		
	dcl_data.direction = (DCL_USB_EP_DIRECTION)direction;
	dcl_data.same_chan = (DCL_BOOL)same_chan;

	DclUSB_HCD_Control(g_USB_HCD_Dcl_Handle, USB_HCD_CMD_USB_HCD_Free_DMA_Channel, (DCL_CTRL_DATA_T  *)&dcl_data);
}

void USBD_DMA_Setup(USBH_Common_Struct common_str,USBH_EP_Struct ep_str,kal_uint32 addr, kal_uint32 length,usb_dma_callback callback,kal_bool callback_upd_run, kal_bool known_size, USB_DMA_TYPE dma_type)				
{
	USB_HCD_CTRL_DMA_SETUP_FUNC_T		dcl_data;
	dcl_data.common_str.if_num = (DCL_UINT32)(common_str.if_num);			
	dcl_data.common_str.usb_ip_port = (DCL_UINT8)(common_str.usb_ip_port);
	dcl_data.usb_ep_str.ep_max_pkt_size = (DCL_UINT16)(ep_str.ep_max_pkt_size);
	dcl_data.usb_ep_str.ep_num = (DCL_UINT8)(ep_str.ep_num);
	dcl_data.usb_ep_str.ep_real_num = (DCL_UINT8)(ep_str.ep_real_num);	
	dcl_data.usb_ep_str.ep_type = (DCL_USB_ENDPT_TXFER_TYPE)(ep_str.ep_type);
	dcl_data.usb_ep_str.direction = (DCL_USB_EP_DIRECTION)(ep_str.direction);	
	dcl_data.u4addr = (DCL_UINT32)addr;
	dcl_data.u4addr = (DCL_UINT32)length;
	dcl_data.callback = (DCL_USB_HCD_DMA_CALLBACK)callback;
	dcl_data.fgcallback_upd_run = (DCL_BOOL)callback_upd_run;
	dcl_data.fgknown_size = (DCL_BOOL)known_size;
	dcl_data.dma_type = (DCL_USB_DMA_TYPE)dma_type;
	
	DclUSB_HCD_Control(g_USB_HCD_Dcl_Handle, USB_HCD_CMD_USB_HCD_DMA_Setup, (DCL_CTRL_DATA_T  *)&dcl_data);
}


void USBD_Set_EP_Max_Pkt(USBH_Common_Struct common_str,USBH_EP_Struct ep_str)
{
	USB_HCD_CTRL_EP_CTRL_FUNC_1_T		dcl_data;
	dcl_data.common_str.if_num = (DCL_UINT32)(common_str.if_num);			
	dcl_data.common_str.usb_ip_port = (DCL_UINT8)(common_str.usb_ip_port);						
	dcl_data.usb_ep_str.ep_max_pkt_size = (DCL_UINT16)(ep_str.ep_max_pkt_size);
	dcl_data.usb_ep_str.ep_num = (DCL_UINT8)(ep_str.ep_num);
	dcl_data.usb_ep_str.ep_real_num = (DCL_UINT8)(ep_str.ep_real_num);	
	dcl_data.usb_ep_str.ep_type = (DCL_USB_ENDPT_TXFER_TYPE)(ep_str.ep_type);
	dcl_data.usb_ep_str.direction = (DCL_USB_EP_DIRECTION)(ep_str.direction);	

	DclUSB_HCD_Control(g_USB_HCD_Dcl_Handle, USB_HCD_CMD_USB_HCD_Set_EP_Max_Pkt, (DCL_CTRL_DATA_T  *)&dcl_data);
}


void USBD_Set_UnMask_Irq(kal_uint8 usb_ip_port,kal_bool set)
{
	USB_HCD_CTRL_SYSTEM_T		dcl_data;
	dcl_data.ip = (DCL_UINT8)usb_ip_port;
	dcl_data.set = (DCL_BOOL)set;

	DclUSB_HCD_Control(g_USB_HCD_Dcl_Handle, USB_HCD_CMD_USB_HCD_Set_UnMask_Irq, (DCL_CTRL_DATA_T  *)&dcl_data);
}


kal_bool USBD_Get_UnMask_Irq(USBH_Common_Struct common_str)
{
	USB_HCD_CTRL_IP_NUM_T		dcl_data;
	dcl_data.ip = (DCL_UINT8)(common_str.usb_ip_port);
	
	DclUSB_HCD_Control(g_USB_HCD_Dcl_Handle, USB_HCD_CMD_USB_HCD_Get_UnMask_Irq, (DCL_CTRL_DATA_T  *)&dcl_data);
	return (kal_bool)dcl_data.return_value;
}


kal_bool USBD_Is_High_Speed(USBH_Common_Struct common_str)
{
	USB_HCD_CTRL_IP_NUM_T		dcl_data;
	dcl_data.ip = (DCL_UINT8)(common_str.usb_ip_port);

	DclUSB_HCD_Control(g_USB_HCD_Dcl_Handle, USB_HCD_CMD_USB_HCD_Is_High_Speed, (DCL_CTRL_DATA_T  *)&dcl_data);
	return (kal_bool)dcl_data.return_value;
}


void USBD_VBusEnable(USBH_Common_Struct common_str,kal_bool enable)
{
	USB_HCD_CTRL_SYSTEM_T		dcl_data;
	dcl_data.ip = (DCL_UINT8)(common_str.usb_ip_port);
	dcl_data.set = (DCL_BOOL)enable;		

	DclUSB_HCD_Control(g_USB_HCD_Dcl_Handle, USB_HCD_CMD_USB_HCD_VBusEnable, (DCL_CTRL_DATA_T  *)&dcl_data);	
}

kal_bool USBD_Bootup_Mode(void)
{
	PW_CTRL_IS_USB_BOOT CtrlVal;
	DCL_HANDLE handle;

	handle=DclPW_Open(DCL_PW, FLAGS_NONE);
	DclPW_Control(handle, PW_CMD_IS_USB_BOOT,(DCL_CTRL_DATA_T *)&CtrlVal);
	DclPW_Close(handle);

	return (kal_bool)CtrlVal.val; // USB Bootup mode doesn't have FMT 
}



#if defined(__IC_USB_ENABLE__)
void ICUSB_Drv_Init(void)
{
	IC_USB_Drv_Activate_ISR(); // DCL
	IC_USBDMA_Drv_Activate_ISR(); // DCL
}
#endif
/************************************************************
	system ctrl functions
*************************************************************/
/* called by OTG_Host_Up_Hdlr */
/* Initialize USBD(Host) */
void USBD_Init(kal_uint8 usb_ip_port)
{
	USB_HCD_CTRL_IP_NUM_T 		dcl_data;
//	USB_HCD_CTRL_SYSTEM_T  		dcl_data1;
	USBH_Common_Struct common_str;
	USBH_EP_Struct usb_ep_str;	
	
	common_str.usb_ip_port = usb_ip_port;
	usb_ep_str.ep_num = 0;//EP0 Control	
	dcl_data.ip = (DCL_UINT8)usb_ip_port;
//	dcl_data1.ip = (DCL_UINT8)usb_ip_port;
//	dcl_data1.set = KAL_TRUE;		
			
	if (g_USB_HCD_Dcl_Handle == 0)
	{	
	DclUSB_HCD_Initialize();
	g_USB_HCD_Dcl_Handle = DclUSB_HCD_Open(DCL_USB, FLAGS_NONE);
	}	
	
	/* Init HCD driver */
	DclUSB_HCD_Control(g_USB_HCD_Dcl_Handle, USB_HCD_CMD_USB_HCD_Init_Drv_Info, (DCL_CTRL_DATA_T  *)&dcl_data);	
	
	USBD_Register_Drv_Info(common_str, USB_HCD_HDLR_ATTACH, usb_ep_str, USBD_Attatch);
	USBD_Register_Drv_Info(common_str, USB_HCD_HDLR_DETACH, usb_ep_str, USBD_Detach);
	USBD_Register_Drv_Info(common_str, USB_HCD_HDLR_RESUME, usb_ep_str, USBD_Resume);
	USBD_Register_Drv_Info(common_str, USB_HCD_HDLR_EP0, usb_ep_str, USBD_EP0_Hdlr);

	DclUSB_HCD_Control(g_USB_HCD_Dcl_Handle, USB_HCD_CMD_USB_HCD_Initialize_Drv, (DCL_CTRL_DATA_T  *)&dcl_data);	

	if(QUERY_IF_SUPPORT_OTG_ARRAY[usb_ip_port] == KAL_FALSE)
	{
		DclUSB_HCD_Control(g_USB_HCD_Dcl_Handle, USB_HCD_CMD_USB_HCD_SWRST, (DCL_CTRL_DATA_T  *)&dcl_data);	
		DclUSB_HCD_Control(g_USB_HCD_Dcl_Handle, USB_HCD_CMD_USB_HCD_EnSysIntr, (DCL_CTRL_DATA_T  *)&dcl_data);	
//		USB_HCD_EnSysIntr(usb_ip_port,KAL_TRUE); // DCL
		DclUSB_HCD_Control(g_USB_HCD_Dcl_Handle, USB_HCD_CMD_USB_HCD_VBusEnable, (DCL_CTRL_DATA_T  *)&dcl_data);	
//		USB_HCD_VBusEnable(usb_ip_port,KAL_TRUE);// DCL			
	}

	DclUSB_HCD_Control(g_USB_HCD_Dcl_Handle, USB_HCD_CMD_USB_HCD_EP0En, (DCL_CTRL_DATA_T  *)&dcl_data);	

    USB_GPTI_GetHandle(&(gUsbHost[usb_ip_port].gpt_handle));

//	if((gUsbHost[usb_ip_port].gpt_handle == 0) ||(gUsbHost[usb_ip_port].gpt_handle == 0x7F))
//		gUsbHost[usb_ip_port].gpt_handle = USB_GPTI_GetHandle();//DclSGPT_Open(DCL_GPT_CB, 0);
//		GPTI_GetHandle(&gUsbHost[usb_ip_port].gpt_handle);
}

/* Release USBD(Host) */
void USBD_Release(kal_uint8 usb_ip_port)
{
//	DCL_HANDLE handle;
	kal_uint8 index;
	USB_HCD_CTRL_IP_NUM_T 		dcl_data;
	dcl_data.ip = (DCL_UINT8)usb_ip_port;
	
//	handle = (DCL_HANDLE)gUsbHost[usb_ip_port].gpt_handle;
//	gUsbHost[usb_ip_port].gpt_handle = DclSGPT_Close(&handle);	
//	GPTI_ReleaseHandle(&gUsbHost[usb_ip_port].gpt_handle);
	USB_GPTI_ReleaseHandle(&(gUsbHost[usb_ip_port].gpt_handle));


	DclUSB_HCD_Control(g_USB_HCD_Dcl_Handle, USB_HCD_CMD_USB_HCD_Release_Drv_Info, (DCL_CTRL_DATA_T  *)&dcl_data);
	DclUSB_HCD_Control(g_USB_HCD_Dcl_Handle, USB_HCD_CMD_USB_HCD_Release_Drv, (DCL_CTRL_DATA_T  *)&dcl_data);

	for (index = 0; index <USBD_MAX_CFG_NUM; index++)
		gUsbHost[usb_ip_port].desc_info.p_conf_data[index] = NULL;
}


/* Used for multiple USB IPs */
void USBD_Attatch_Hdlr(kal_uint8 usb_ip_port, USB_HCD_STATUS result, kal_uint32 param)
{
//	kal_uint32 event_group;

	kal_take_mutex(gUsbHost_Comm.usbd_com_ep0_mutex_id);

	/* Start CH9 state machine */
	USBD_Ch9_Callback(usb_ip_port, result, param);

	/* Unmask USB IRQ until here */
	USB_Dbg_Trace(USB_HCD_UNMASK_HISR,  1, 0);
	
	USBD_Set_UnMask_Irq(usb_ip_port, KAL_TRUE);
	
	IRQUnmask(USB_IRQ_MAP[usb_ip_port]);

	/* Wait until enumeration done or disconnect */
	/* Since IP is enumerated one by one, so ENUMERATION done must happen after this wait event  */
//	kal_retrieve_eg_events(gUsbHost_Comm.usbd_com_ep0_event_id, EVENT_USBD_EP0_ENUMERATION|EVENT_USBD_EP0_DETACH,
//					KAL_OR_CONSUME, &event_group, KAL_SUSPEND);

	kal_give_mutex(gUsbHost_Comm.usbd_com_ep0_mutex_id);
}


/* Attatch interrupt handler*/
static void USBD_Attatch(kal_uint8 usb_ip_port, USB_HCD_STATUS result, kal_uint32 param)
{
	kal_uint32 index;
	usb_host_usbattach_ind_struct *usb_host_attach;
//	ilm_struct *usb_ilm = NULL;


	if(kal_if_hisr() == KAL_FALSE)
		ASSERT(0);

	gUsbHost[usb_ip_port].ch9_state = USBD_CH9_START;

	for(index = 0; index < USBD_MAX_CFG_NUM; index++)
	{
		gUsbHost[usb_ip_port].desc_info.p_otg_desc[index] = NULL;
	}

	gUsbHost[usb_ip_port].support_hnp = USBD_HNP_NOT_SUPPORT;


	/* Send message to USB task */
	usb_host_attach = (usb_host_usbattach_ind_struct*)construct_local_para(sizeof(usb_host_usbattach_ind_struct), TD_CTRL);

	usb_host_attach->usb_ip_port = usb_ip_port;
	usb_host_attach->result = (kal_uint8)result;
	usb_host_attach->param = param;

	USB_Send_Msg_Ext_Queue(MOD_USB,MSG_ID_USB_HOST_ATTACH_IND, usb_host_attach);
	
//	DRV_BuildPrimitive(usb_ilm,stack_get_active_module_id(),MOD_USB, MSG_ID_USB_HOST_ATTACH_IND, usb_host_attach);
//	msg_send_ext_queue(usb_ilm);
}


void USBD_Detach_Hdlr(kal_uint8 usb_ip_port, USB_HCD_STATUS result, kal_uint32 param)
{
	kal_uint32 index, index2;


	gUsbHost[usb_ip_port].ch9_state = USBD_CH9_STOP;

	// Call the detach function
	if(gUsbHost[usb_ip_port].set_cfg_number != 0)
	{
		if((gUsbHost[usb_ip_port].desc_info.cfg_info[gUsbHost[usb_ip_port].set_cfg_number-1].match_class_num == 0)||
			(gUsbHost[usb_ip_port].desc_info.cfg_info[gUsbHost[usb_ip_port].set_cfg_number-1].interface_number == 0))
			ASSERT(0);

		/* set_cfg_number != 0 must match some drivers */
		for(index = 0; index < gUsbHost[usb_ip_port].desc_info.cfg_info[gUsbHost[usb_ip_port].set_cfg_number-1].interface_number; index++)
		{
			if(gUsbHost[usb_ip_port].desc_info.cfg_info[gUsbHost[usb_ip_port].set_cfg_number-1].match_class_driver_index[index] < gUsbHost[usb_ip_port].default_class_driver_index)
				gUsbHost[usb_ip_port].class_driver_ptr[gUsbHost[usb_ip_port].desc_info.cfg_info[gUsbHost[usb_ip_port].set_cfg_number-1].match_class_driver_index[index]]->detach(usb_ip_port);
		}
	}

//	gUsbHost[usb_ip_port].default_class_driver_index = 0;
	gUsbHost[usb_ip_port].set_cfg_number = 0;
	gUsbHost[usb_ip_port].ch9_error_count = 0;
	gUsbHost[usb_ip_port].desc_info.cfg_number = 0;
	gUsbHost[usb_ip_port].support_hnp = USBD_HNP_NOT_SUPPORT;
	gUsbHost[usb_ip_port].b_suspend_mode = KAL_FALSE;
	gUsbHost[usb_ip_port].b_is_match_hub = KAL_FALSE;

	for(index = 0; index < USBD_MAX_CFG_NUM; index++)
	{
//		if(gUsbHost[usb_ip_port].desc_info.p_conf_data[index] != NULL)
//			free_ctrl_buffer(gUsbHost[usb_ip_port].desc_info.p_conf_data[index]);

		gUsbHost[usb_ip_port].desc_info.p_conf_data[index] = NULL;
		gUsbHost[usb_ip_port].desc_info.p_otg_desc[index] = NULL;
		gUsbHost[usb_ip_port].desc_info.cfg_info[index].interface_number = 0;
		gUsbHost[usb_ip_port].desc_info.cfg_info[index].match_class_num = 0;
		gUsbHost[usb_ip_port].desc_info.cfg_info[index].active_if_index_map = 0;
		gUsbHost[usb_ip_port].desc_info.cfg_info[index].match_class_driver_point = 0;

		for(index2 = 0; index2 < USBD_MAX_IF_PER_CFG; index2++)
		{
			gUsbHost[usb_ip_port].desc_info.cfg_info[index].match_class_driver_index[index2] = 0xFF;
		}
	}

	for(index = 0; index < USBD_MAX_INTERFACE_NUM; index++)
	{
		gUsbHost[usb_ip_port].desc_info.interface_info[index].ep_number = 0;
	}
}


/* Detach interrupt handler */
static void USBD_Detach(kal_uint8 usb_ip_port, USB_HCD_STATUS result, kal_uint32 param)
{
//	if((gUsbHost[usb_ip_port].ch9_state != USBD_CH9_ENUM_OK)&&(gUsbHost[usb_ip_port].ch9_state != USBD_CH9_ENUM_FAIL))
//	{
//		kal_set_eg_events(gUsbHost_Comm.usbd_com_ep0_event_id, EVENT_USBD_EP0_DETACH, KAL_OR);
//	}

	USB_Dbg_Trace(USBD_EP0_CMD_SET_EVENT,  1, 0);
	kal_set_eg_events(gUsbHost[usb_ip_port].usbd_ep0_event_id, EVENT_USBD_EP0_DETACH, KAL_OR);
	USBD_Detach_Hdlr(usb_ip_port, result, param);
}


static void USBD_Reset_Resource(kal_uint8 usb_ip_port)
{
	USB_HCD_CTRL_IP_NUM_T		dcl_data;
	dcl_data.ip = (DCL_UINT8)usb_ip_port;
	
	DclUSB_HCD_Control(g_USB_HCD_Dcl_Handle, USB_HCD_CMD_USB_HCD_Reset_Resource, (DCL_CTRL_DATA_T  *)&dcl_data);		
}

/* Resume interrupt handler */
static void USBD_Resume(kal_uint8 usb_ip_port, USB_HCD_STATUS result, kal_uint32 param)
{
	kal_uint32 index;

	// Call the resume functions
	if(gUsbHost[usb_ip_port].set_cfg_number != 0)
	{
		if((gUsbHost[usb_ip_port].desc_info.cfg_info[gUsbHost[usb_ip_port].set_cfg_number-1].match_class_num == 0)||
			(gUsbHost[usb_ip_port].desc_info.cfg_info[gUsbHost[usb_ip_port].set_cfg_number-1].interface_number == 0))
			ASSERT(0);

		/* set_cfg_number != 0 must match some drivers */
		for(index = 0; index < gUsbHost[usb_ip_port].desc_info.cfg_info[gUsbHost[usb_ip_port].set_cfg_number-1].interface_number; index++)
		{
			if(gUsbHost[usb_ip_port].desc_info.cfg_info[gUsbHost[usb_ip_port].set_cfg_number-1].match_class_driver_index[index] < gUsbHost[usb_ip_port].default_class_driver_index)
				gUsbHost[usb_ip_port].class_driver_ptr[gUsbHost[usb_ip_port].desc_info.cfg_info[gUsbHost[usb_ip_port].set_cfg_number-1].match_class_driver_index[index]]->resume(usb_ip_port);
		}
		// class Driver clear flag
		g_suspend_if &= ~(gUsbHost[usb_ip_port].desc_info.cfg_info[gUsbHost[usb_ip_port].set_cfg_number-1].active_if_index_map);
		// Kay: clear suspend flag
	}

	kal_set_eg_events(gUsbHost[usb_ip_port].usbd_resume_event_id, EVENT_USBD_RESUME_DONE, KAL_OR);

}
/************************************************************
	EP0 functions
*************************************************************/
/* Set Address request */
static void USBD_Set_Address(USBH_Common_Struct common_str, kal_uint8 address)
{
	Usb_Command usbd_cmd;

	usbd_cmd.bmRequestType = USB_CMD_STDDEVOUT;
	usbd_cmd.bRequest = USB_SET_ADDRESS;
	usbd_cmd.wValue = address;
	usbd_cmd.wIndex = 0;
	usbd_cmd.wLength = 0;

	USBD_Start_Setup_Cmd(common_str, &usbd_cmd, NULL, USBD_EP0_DATA_SEND, 0, KAL_FALSE, USBD_Ch9_Callback);
}

/* Clear Stall request */
void USBD_Clear_Feature(USBH_Common_Struct common_str,USBH_EP_Struct usb_ep_str,kal_bool b_is_from_class_drv, usbd_ep0_callback callback)
{
	Usb_Command usbd_cmd;

	usbd_cmd.bmRequestType = USB_CMD_STDEPOUT;
	usbd_cmd.bRequest = USB_CLEAR_FEATURE;
	usbd_cmd.wValue = USB_FTR_EPHALT;
	usbd_cmd.wIndex = usb_ep_str.ep_num;

	if(usb_ep_str.direction == USB_EP_RX_DIR)
		usbd_cmd.wIndex |= 0x80;

	usbd_cmd.wLength = 0x00;

	USBD_Start_Setup_Cmd(common_str, &usbd_cmd, NULL, USBD_EP0_DATA_NULL, 0, b_is_from_class_drv, callback);
}


/* Get Descriptor request */
static void USBD_Get_Descriptor(USBH_Common_Struct common_str, kal_uint16 type_index, kal_uint16 lang_id, kal_uint16 buflen, kal_uint8 *buffer)
{
	Usb_Command usbd_cmd;

	usbd_cmd.bmRequestType = USB_CMD_STDDEVIN;
	usbd_cmd.bRequest = USB_GET_DESCRIPTOR;
	usbd_cmd.wValue = type_index;
	usbd_cmd.wIndex = lang_id;
	usbd_cmd.wLength = buflen;

	USBD_Start_Setup_Cmd(common_str, &usbd_cmd, buffer, USBD_EP0_DATA_RECV, buflen, KAL_FALSE, USBD_Ch9_Callback);
}

/* Get Configuration request */
void USBD_Set_Descriptor(USBH_Common_Struct common_str, kal_uint16 type_index, kal_uint16 lang_id, kal_uint16 buflen,kal_bool b_is_from_class_drv, usbd_ep0_callback callback,kal_uint8 *buffer)
{
	Usb_Command usbd_cmd;

	usbd_cmd.bmRequestType = USB_CMD_STDDEVOUT;
	usbd_cmd.bRequest = USB_SET_DESCRIPTOR;
	usbd_cmd.wValue = type_index;
	usbd_cmd.wIndex = lang_id;
	usbd_cmd.wLength = buflen;

	USBD_Start_Setup_Cmd(common_str, &usbd_cmd, buffer, USBD_EP0_DATA_SEND, buflen, b_is_from_class_drv, callback);
}


/* Set Configuration request */
static void USBD_Set_Configuration(USBH_Common_Struct common_str, kal_uint16 config_value)
{
	Usb_Command usbd_cmd;

	usbd_cmd.bmRequestType = USB_CMD_STDDEVOUT;
	usbd_cmd.bRequest = USB_SET_CONFIGURATION;
	usbd_cmd.wValue = config_value;
	usbd_cmd.wIndex = 0;
	usbd_cmd.wLength = 0;

	USBD_Start_Setup_Cmd(common_str, &usbd_cmd, NULL, USBD_EP0_DATA_SEND, 0, KAL_FALSE, USBD_Ch9_Callback);
}


/* Get Configuration request */
void USBD_Get_Configuration(USBH_Common_Struct common_str,kal_bool b_is_from_class_drv, usbd_ep0_callback callback,kal_uint8 *buffer)
{
	Usb_Command usbd_cmd;

	usbd_cmd.bmRequestType = USB_CMD_STDDEVIN;
	usbd_cmd.bRequest = USB_GET_CONFIGURATION;
	usbd_cmd.wValue = 0;
	usbd_cmd.wIndex = 0;
	usbd_cmd.wLength = 1;

	USBD_Start_Setup_Cmd(common_str, &usbd_cmd, buffer, USBD_EP0_DATA_RECV, 1, b_is_from_class_drv, callback);
}

/* Get Interface request */
void USBD_Get_Interface(USBH_Common_Struct common_str,kal_uint16 interface,kal_bool b_is_from_class_drv, usbd_ep0_callback callback,kal_uint8 *buffer)
{
	Usb_Command usbd_cmd;

	usbd_cmd.bmRequestType = USB_CMD_STDIFIN;
	usbd_cmd.bRequest = USB_GET_INTERFACE;
	usbd_cmd.wValue = 0;
	usbd_cmd.wIndex = interface;
	usbd_cmd.wLength = 1;

	USBD_Start_Setup_Cmd(common_str, &usbd_cmd, buffer, USBD_EP0_DATA_RECV, 1, b_is_from_class_drv, callback);
}

/* Set Interface request */
void USBD_Set_Interface(USBH_Common_Struct common_str,kal_uint16 interface,kal_uint16 setting,kal_bool b_is_from_class_drv, usbd_ep0_callback callback)
{
	Usb_Command usbd_cmd;

	usbd_cmd.bmRequestType = USB_CMD_STDIFOUT;
	usbd_cmd.bRequest = USB_SET_INTERFACE;
	usbd_cmd.wValue = setting;
	usbd_cmd.wIndex = interface;
	usbd_cmd.wLength = 0;

	USBD_Start_Setup_Cmd(common_str, &usbd_cmd, NULL, USBD_EP0_DATA_SEND, 0, b_is_from_class_drv, callback);
}

/* Get Sync frame request */
void USBD_Sync_Frame(USBH_Common_Struct common_str,kal_uint16 endpoint,kal_bool b_is_from_class_drv, usbd_ep0_callback callback,kal_uint8 *buffer)
{
	Usb_Command usbd_cmd;

	usbd_cmd.bmRequestType = USB_CMD_STDEPIN;
	usbd_cmd.bRequest = USB_SYNCH_FRAME;
	usbd_cmd.wValue = 0;
	usbd_cmd.wIndex = endpoint;
	usbd_cmd.wLength = 2;

	USBD_Start_Setup_Cmd(common_str, &usbd_cmd, buffer, USBD_EP0_DATA_RECV, 2, b_is_from_class_drv, callback);
}


/* Get Status request */
void USBD_Get_Status(USBH_Common_Struct common_str,kal_bool b_is_from_class_drv, usbd_ep0_callback callback,kal_uint8 *buffer)
{
	Usb_Command usbd_cmd;

	usbd_cmd.bmRequestType = USB_CMD_STDDEVIN;
	usbd_cmd.bRequest = USB_GET_STATUS;
	usbd_cmd.wValue = 0;
	usbd_cmd.wIndex = 0;
	usbd_cmd.wLength = 2;

	USBD_Start_Setup_Cmd(common_str, &usbd_cmd, buffer, USBD_EP0_DATA_RECV, 2, b_is_from_class_drv, callback);
}

/* Set Feature request */
static void USBD_Set_Feature(USBH_Common_Struct common_str, kal_uint16 feature_value, kal_bool b_is_from_class_drv, usbd_ep0_callback callback)
{
	Usb_Command usbd_cmd;

	usbd_cmd.bmRequestType = USB_CMD_STDDEVOUT;
	usbd_cmd.bRequest = USB_SET_FEATURE;
	usbd_cmd.wValue = feature_value;
	usbd_cmd.wIndex = 0;
	usbd_cmd.wLength = 0;

	USBD_Start_Setup_Cmd(common_str, &usbd_cmd, NULL, USBD_EP0_DATA_SEND, 0, b_is_from_class_drv, callback);
}

static void USBD_EP0_Data_Req(USBH_Common_Struct common_str,USBH_EP_Struct ep_str, kal_uint16 nBytes, void *pData)
{
	USB_HCD_CTRL_EP0_DATA_REQ_T    dcl_data;

	dcl_data.common_str.if_num = (DCL_UINT32)(common_str.if_num);			
	dcl_data.common_str.usb_ip_port = (DCL_UINT8)(common_str.usb_ip_port);						
	dcl_data.usb_ep_str.ep_max_pkt_size = (DCL_UINT16)(ep_str.ep_max_pkt_size);
	dcl_data.usb_ep_str.ep_num = (DCL_UINT8)(ep_str.ep_num);
	dcl_data.usb_ep_str.ep_real_num = (DCL_UINT8)(ep_str.ep_real_num);	
	dcl_data.usb_ep_str.ep_type = (DCL_USB_ENDPT_TXFER_TYPE)(ep_str.ep_type);
	dcl_data.usb_ep_str.direction = (DCL_USB_EP_DIRECTION)(ep_str.direction);		
	dcl_data.u2nBytes = (DCL_UINT16)nBytes;
	dcl_data.pData = pData;

	DclUSB_HCD_Control(g_USB_HCD_Dcl_Handle, USB_HCD_CMD_USB_HCD_EP0_Data_Req, (DCL_CTRL_DATA_T  *)&dcl_data);			
}

static void USBD_EP0_Status_Req(USBH_Common_Struct common_str,USBH_EP_Struct ep_str)
{
	USB_HCD_CTRL_EP0_STATUS_REQ_T    dcl_data;

	dcl_data.common_str.if_num = (DCL_UINT32)(common_str.if_num);			
	dcl_data.common_str.usb_ip_port = (DCL_UINT8)(common_str.usb_ip_port);						
	dcl_data.usb_ep_str.ep_max_pkt_size = (DCL_UINT16)(ep_str.ep_max_pkt_size);
	dcl_data.usb_ep_str.ep_num = (DCL_UINT8)(ep_str.ep_num);
	dcl_data.usb_ep_str.ep_real_num = (DCL_UINT8)(ep_str.ep_real_num);	
	dcl_data.usb_ep_str.ep_type = (DCL_USB_ENDPT_TXFER_TYPE)(ep_str.ep_type);
	dcl_data.usb_ep_str.direction = (DCL_USB_EP_DIRECTION)(ep_str.direction);		

	DclUSB_HCD_Control(g_USB_HCD_Dcl_Handle, USB_HCD_CMD_USB_HCD_EP0_Status_Req, (DCL_CTRL_DATA_T  *)&dcl_data);			
}


USBD_HNP_SUPPORT_TYPE USBD_Get_HNP_Support(kal_uint8 usb_ip_port)
{
	return gUsbHost[usb_ip_port].support_hnp;
}


kal_bool USBD_Is_Match_Hub(kal_uint8 usb_ip_port)
{
	return gUsbHost[usb_ip_port].b_is_match_hub;
}

/* Reset after timeout, note that timeout unit is 10ms */
static void USBD_Delay_Reset_Device(kal_uint8 usb_ip_port,USB_HCD_STATUS reset_reason, kal_uint32 timeout)
{
	USB_HCD_CTRL_DELAY_RESET_DEVICE_T  dcl_data;
	dcl_data.ip = (DCL_UINT8)usb_ip_port;
	dcl_data.result = (DCL_USB_HCD_STATUS)reset_reason;
	dcl_data.u4param = (DCL_UINT32)timeout;

	DclUSB_HCD_Control(g_USB_HCD_Dcl_Handle, USB_HCD_CMD_USB_HCD_Delay_Reset_Device, (DCL_CTRL_DATA_T  *)&dcl_data);
}

#if (defined(__OTG_ENABLE__)&&defined(__USB_HS_ENABLE__))

static void USBD_Delay_Resume_Timeout(void *parameter)
{
	USBD_Struct *USBD_Data = (USBD_Struct *)parameter;
	kal_uint8 usb_ip_port = USBD_Data->usb_ip_port;

      //called by USBD_Delay_Suspend_Timeout , used in test mode

//	DclSGPT_Control((DCL_HANDLE)(gUsbHost[usb_ip_port].gpt_handle), SGPT_CMD_STOP, 0);
	USB_GPTI_StopItem(gUsbHost[usb_ip_port].gpt_handle);

	if(QUERY_IF_SUPPORT_OTG_ARRAY[usb_ip_port] == KAL_TRUE)
	{
		DclOTG_DRV_Control(g_OTG_Dcl_Handle, OTG_DRV_CMD_A_RESUME_REQ, NULL);
//	OTG_A_Resume_Req();
	}
	else
	{
		ASSERT(0);  //ICUSB : USB1.1 --> doesn't have test mode
	}
}


static void USBD_Delay_Suspend_Timeout(void *parameter)
{
	USBD_Struct *USBD_Data = (USBD_Struct *)parameter;
	kal_uint8 usb_ip_port = USBD_Data->usb_ip_port;
//	SGPT_CTRL_START_T start;
	
//	DclSGPT_Control((DCL_HANDLE)(gUsbHost[usb_ip_port].gpt_handle), SGPT_CMD_STOP, 0);
	USB_GPTI_StopItem(gUsbHost[usb_ip_port].gpt_handle);

	if(QUERY_IF_SUPPORT_OTG_ARRAY[usb_ip_port] == KAL_TRUE)
	{
	/* Suspend bus */
	DclOTG_DRV_Control(g_OTG_Dcl_Handle, OTG_DRV_CMD_A_SUSPEND_REQ, NULL);
//	OTG_A_Suspend_Req();
	}
	else
	{
		ASSERT(0); //ICUSB : USB1.1 --> doesn't have test mode
	}

//	start.u2Tick = USBD_TEST_MODE_DELAY;					
// 	start.pfCallback = USBD_Delay_Resume_Timeout;			
//  	start.vPara = &gUsbHost[usb_ip_port];							
//  DclSGPT_Control((DCL_HANDLE)(gUsbHost[usb_ip_port].gpt_handle), SGPT_CMD_START, (DCL_CTRL_DATA_T*)&start);	
	USB_GPTI_StartItem(gUsbHost[usb_ip_port].gpt_handle, USBD_TEST_MODE_DELAY,USBD_Delay_Resume_Timeout, &gUsbHost[usb_ip_port]);
}



static void USBD_Test_Mode_Null(kal_uint8 usb_ip_port, USB_HCD_STATUS result, kal_uint32 param)
{
	return;
}


static void USBD_Delay_Get_Devdsc_Timeout(void *parameter)
{
	USBD_Struct *USBD_Data = (USBD_Struct *)parameter;
	USBH_Common_Struct common_str;
	USBH_EP_Struct usb_ep_str;		
	common_str.usb_ip_port = USBD_Data->usb_ip_port;
	usb_ep_str.ep_num = 0;//EP0 Control

//	DclSGPT_Control((DCL_HANDLE)(gUsbHost[common_str.usb_ip_port].gpt_handle), SGPT_CMD_STOP, 0);
	USB_GPTI_StopItem(gUsbHost[common_str.usb_ip_port].gpt_handle);

	if(QUERY_IF_SUPPORT_OTG_ARRAY[common_str.usb_ip_port] == KAL_TRUE)
	{
		USBD_Register_Drv_Info(common_str,USB_HCD_HDLR_EP0, usb_ep_str, USBD_Test_Mode_Null);
	}
	else
	{
		ASSERT(0);//ICUSB : USB1.1 --> doesn't have test mode
	}

	USBD_Get_Descriptor(common_str, USB_DEVICE<<8, 0, sizeof(gUsbHost[common_str.usb_ip_port].desc_info.dev_desc),
									(kal_uint8*)&gUsbHost[common_str.usb_ip_port].desc_info.dev_desc);
}


static void USBD_Delay_In_Timeout(void *parameter)
{
	USBD_Struct *USBD_Data = (USBD_Struct *)parameter;
	USBH_Common_Struct common_str;
	USBH_EP_Struct usb_ep_str;
//	USB_HCD_CTRL_REGISTER_DRV_INFO_T		dcl_data;
	common_str.usb_ip_port = USBD_Data->usb_ip_port; 
	usb_ep_str.ep_num = 0;
	usb_ep_str.direction = USB_EP_RX_DIR;
	usb_ep_str.ep_type = USB_ENDPT_CTRL;
//	dcl_data.ip = (DCL_UINT8)common_str.usb_ip_port;
//	dcl_data.type = (DCL_USB_HCD_HDLR_TYPE)usb_ep_str.ep_type;
//	dcl_data.u4ep_num = (DCL_UINT32)usb_ep_str.ep_num;
//	dcl_data.hdlr = (DCL_USB_HCD_INTR_HDLR)USBD_Test_Mode_Null;

//	DclSGPT_Control((DCL_HANDLE)(gUsbHost[common_str.usb_ip_port].gpt_handle), SGPT_CMD_STOP, 0);
	USB_GPTI_StopItem(gUsbHost[common_str.usb_ip_port].gpt_handle);

	if(QUERY_IF_SUPPORT_OTG_ARRAY[common_str.usb_ip_port] == KAL_TRUE)
	{
//		DclUSB_HCD_Control(g_USB_HCD_Dcl_Handle, USB_HCD_CMD_USB_HCD_Register_Drv_Info, (DCL_CTRL_DATA_T  *)&dcl_data);	
		USBD_Register_Drv_Info(common_str,USB_HCD_HDLR_EP0, usb_ep_str, USBD_Test_Mode_Null);
		USBD_EP0_Data_Req(common_str,usb_ep_str, gUsbHost[common_str.usb_ip_port].ep0_status.todo, gUsbHost[common_str.usb_ip_port].ep0_status.data_ptr);
	}
	else
	{
		ASSERT(0);  //ICUSB : USB1.1 --> doesn't have test mode
	}
}


static void USBD_Test_Mode_Delay_In_Hdlr(kal_uint8 usb_ip_port, USB_HCD_STATUS result, kal_uint32 param)
{
//		SGPT_CTRL_START_T start;
//    start.u2Tick =  USBD_TEST_MODE_DELAY;					
//    start.pfCallback = USBD_Delay_In_Timeout;			
//    start.vPara = &gUsbHost[usb_ip_port];							
//    DclSGPT_Control((DCL_HANDLE)(gUsbHost[usb_ip_port].gpt_handle), SGPT_CMD_START, (DCL_CTRL_DATA_T*)&start);	
    
	USB_GPTI_StartItem(gUsbHost[usb_ip_port].gpt_handle, USBD_TEST_MODE_DELAY,USBD_Delay_In_Timeout, &gUsbHost[usb_ip_port]);
}


static void USBD_Test_Mode_Hdlr(kal_uint8 usb_ip_port, USBD_TEST_MODE_TYPE test_type)
{
	USBH_Common_Struct common_str;
	USBH_EP_Struct usb_ep_str;	
//	SGPT_CTRL_START_T start;
	common_str.usb_ip_port = usb_ip_port;
	usb_ep_str.ep_num = 0;//EP0 Control

	if(test_type == USBD_TEST_MODE_TYPE_SE0)
	{
		USB_Enter_Test_Mode(USB_TEST_MODE_TYPE_SE0_NAK);
	}
	else if(test_type == USBD_TEST_MODE_TYPE_J)
	{
		USB_Enter_Test_Mode(USB_TEST_MODE_TYPE_J);
	}
	else if(test_type == USBD_TEST_MODE_TYPE_K)
	{
		USB_Enter_Test_Mode(USB_TEST_MODE_TYPE_K);
	}
	else if(test_type == USBD_TEST_MODE_TYPE_TEST_PACKET)
	{
		USB_Enter_Test_Mode(USB_TEST_MODE_TYPE_PACKET);
	}
	else if(test_type == USBD_TEST_MODE_TYPE_HS_HOST_PORT_SUSPEND_RESUME)
	{
//		start.u2Tick = USBD_TEST_MODE_DELAY;					
//    start.pfCallback = USBD_Delay_Suspend_Timeout;			
//    start.vPara = &gUsbHost[usb_ip_port];							
//    DclSGPT_Control((DCL_HANDLE)(gUsbHost[usb_ip_port].gpt_handle), SGPT_CMD_START, (DCL_CTRL_DATA_T*)&start);	

		USB_GPTI_StartItem(gUsbHost[usb_ip_port].gpt_handle, USBD_TEST_MODE_DELAY,USBD_Delay_Suspend_Timeout, &gUsbHost[usb_ip_port]);
	}
	else if(test_type == USBD_TEST_MODE_TYPE_SINGLE_STEP_GET_DEV_DESC)
	{
//		start.u2Tick = USBD_TEST_MODE_DELAY;					
//    start.pfCallback = USBD_Delay_Get_Devdsc_Timeout;			
//    start.vPara = &gUsbHost[usb_ip_port];							
//    DclSGPT_Control((DCL_HANDLE)(gUsbHost[usb_ip_port].gpt_handle), SGPT_CMD_START, (DCL_CTRL_DATA_T*)&start);	
		USB_GPTI_StartItem(gUsbHost[usb_ip_port].gpt_handle, USBD_TEST_MODE_DELAY,USBD_Delay_Get_Devdsc_Timeout, &gUsbHost[usb_ip_port]);
	}
	else if(test_type == USBD_TEST_MODE_TYPE_SINGLE_STEP_SET_FEATURE)
	{
		if(QUERY_IF_SUPPORT_OTG_ARRAY[usb_ip_port] == KAL_TRUE)
		{
			USBD_Register_Drv_Info(common_str, USB_HCD_HDLR_EP0, usb_ep_str, USBD_Test_Mode_Delay_In_Hdlr);
		}
		else
		{
			ASSERT(0); //ICUSB : USB1.1 --> doesn't have test mode
		}

		USBD_Get_Descriptor(common_str, USB_DEVICE<<8, 0, sizeof(gUsbHost[usb_ip_port].desc_info.dev_desc),
									(kal_uint8*)&gUsbHost[usb_ip_port].desc_info.dev_desc);
	}
	else if(test_type == USBD_TEST_MODE_TYPE_UNSUPPORTED_DEVICE)
	{
		// Call the default driver startup function
		drv_trace0(TRACE_FUNC, (kal_uint32)USB_HCD_TEST_UN_SUPPORT);
		gUsbHost[usb_ip_port].class_driver_ptr[gUsbHost[usb_ip_port].default_class_driver_index]->startup(usb_ip_port, NULL, 0, 0);
	}
}

#endif /* (defined(__OTG_ENABLE__)&&defined(__USB_HS_ENABLE__)) */


static void USBD_Set_Address_Recovery_Timeout(void *parameter)
{
	USBD_Struct *USBD_Data = (USBD_Struct *)parameter;
	kal_uint8 usb_ip_port = USBD_Data->usb_ip_port;

//	DclSGPT_Control((DCL_HANDLE)(gUsbHost[usb_ip_port].gpt_handle), SGPT_CMD_STOP, 0);
	USB_GPTI_StopItem(gUsbHost[usb_ip_port].gpt_handle);

	USB_Dbg_Trace(USBD_CH9_CALLBACK_TIME_OUT,  0, 0);
	gUsbHost[usb_ip_port].ch9_state = USBD_CH9_SET_ADDR;
	gUsbHost[usb_ip_port].ep0_callback(usb_ip_port, USB_HCD_OK, gUsbHost[usb_ip_port].ep0_status.sofar);
}

/* match rule : =================
1. power
2. match class number : max
3. match most important class
4. high speed / full speed 
5. HW limitation : EP number & memory size
=> customer can easy to change rule 
 =========================== */

#if 0   // for customize use
/* under construction !*/
/* under construction !*/
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


static kal_uint8 USBD_Cfg_Class_Point(kal_uint8 usb_ip_port,kal_uint8 cfg_number)
{
	return gUsbHost[usb_ip_port].desc_info.cfg_info[cfg_number].match_class_driver_point;
}

static kal_uint8 USBD_Cfg_Power(kal_uint8 usb_ip_port,kal_uint8 cfg_number)
{
	return gUsbHost[usb_ip_port].desc_info.cfg_info[cfg_number].p_cfg_desc->bMaxPower;
}


static void USBD_Match_Method(kal_uint8 usb_ip_port,kal_uint32 parse_cfg_number)
{
		kal_uint16 max_support_power = USBD_Get_Max_Power()/2;
		kal_uint16 support_power = 256;
		kal_uint8 match_drv_point = 0;
	
//		if(gUsbHost[usb_ip_port].desc_info.cfg_info[parse_cfg_number].match_class_driver_point != 0)
		if(USBD_Cfg_Class_Point(usb_ip_port,parse_cfg_number) != 0)			
		{
			if(gUsbHost_Comm.host_match_param->current_follow_spec == KAL_TRUE)
			{
				/* We compare the current value and choose the one which < 100mA */
//				if(gUsbHost[usb_ip_port].desc_info.cfg_info[parse_cfg_number].p_cfg_desc->bMaxPower <= max_support_power)
				if(USBD_Cfg_Power(usb_ip_port,parse_cfg_number) <= max_support_power)
				{
//					if(gUsbHost[usb_ip_port].desc_info.cfg_info[parse_cfg_number].match_class_driver_point > match_drv_point)
					if(USBD_Cfg_Class_Point(usb_ip_port,parse_cfg_number) > match_drv_point)
					{
						match_drv_point = USBD_Cfg_Class_Point(usb_ip_port,parse_cfg_number);//gUsbHost[usb_ip_port].desc_info.cfg_info[parse_cfg_number].match_class_driver_point;
						support_power = USBD_Cfg_Power(usb_ip_port,parse_cfg_number);//gUsbHost[usb_ip_port].desc_info.cfg_info[parse_cfg_number].p_cfg_desc->bMaxPower;

						gUsbHost[usb_ip_port].set_cfg_number = gUsbHost[usb_ip_port].desc_info.cfg_info[parse_cfg_number].p_cfg_desc->bConfigurationValue;

						if(gUsbHost[usb_ip_port].set_cfg_number != (parse_cfg_number+1))
							ASSERT(0);
					}
				}
			}
			else
			{
//				if(gUsbHost[usb_ip_port].desc_info.cfg_info[parse_cfg_number].match_class_driver_point > match_drv_point)
				if(USBD_Cfg_Class_Point(usb_ip_port,parse_cfg_number) > match_drv_point)
				{
					match_drv_point = USBD_Cfg_Class_Point(usb_ip_port,parse_cfg_number);//gUsbHost[usb_ip_port].desc_info.cfg_info[parse_cfg_number].match_class_driver_point;
					support_power = USBD_Cfg_Power(usb_ip_port,parse_cfg_number);//gUsbHost[usb_ip_port].desc_info.cfg_info[parse_cfg_number].p_cfg_desc->bMaxPower;

					gUsbHost[usb_ip_port].set_cfg_number = gUsbHost[usb_ip_port].desc_info.cfg_info[parse_cfg_number].p_cfg_desc->bConfigurationValue;

					if(gUsbHost[usb_ip_port].set_cfg_number != (parse_cfg_number+1))
						ASSERT(0);
				}
				else if(USBD_Cfg_Class_Point(usb_ip_port,parse_cfg_number)== match_drv_point)
				{
					/* We compare the current value and choose the one which < 100mA */
					if(support_power > max_support_power)
					{
//						if(gUsbHost[usb_ip_port].desc_info.cfg_info[parse_cfg_number].p_cfg_desc->bMaxPower < support_power)
						if(USBD_Cfg_Power(usb_ip_port,parse_cfg_number) < support_power)
						{
							support_power = USBD_Cfg_Power(usb_ip_port,parse_cfg_number);//gUsbHost[usb_ip_port].desc_info.cfg_info[parse_cfg_number].p_cfg_desc->bMaxPower;
							gUsbHost[usb_ip_port].set_cfg_number = gUsbHost[usb_ip_port].desc_info.cfg_info[parse_cfg_number].p_cfg_desc->bConfigurationValue;

							if(gUsbHost[usb_ip_port].set_cfg_number != (parse_cfg_number+1))
								ASSERT(0);
						}
					}
					else
					{
						/* support_power <= max_support_power */
						if((USBD_Cfg_Power(usb_ip_port,parse_cfg_number) > support_power)&&(USBD_Cfg_Power(usb_ip_port,parse_cfg_number) <= max_support_power))
						{
							support_power = USBD_Cfg_Power(usb_ip_port,parse_cfg_number);//gUsbHost[usb_ip_port].desc_info.cfg_info[parse_cfg_number].p_cfg_desc->bMaxPower;
							gUsbHost[usb_ip_port].set_cfg_number = gUsbHost[usb_ip_port].desc_info.cfg_info[parse_cfg_number].p_cfg_desc->bConfigurationValue;

							if(gUsbHost[usb_ip_port].set_cfg_number != (parse_cfg_number+1))
								ASSERT(0);
						}
					}
				}
			}
		} // match method
}


/* CH9 state machine. Each time EP0 setup, data, status complete, this callback functio will be called */
static void USBD_Ch9_Callback(kal_uint8 usb_ip_port, USB_HCD_STATUS result, kal_uint32 param)
{
	kal_uint32 data_size;
	kal_uint32 data_offset;
	kal_uint32 ep_index;
	kal_uint32 if_index;
	kal_uint32 index, index2;
	kal_uint32 interface_number;
	Usb_If_Dscr *p_interface_desc;
	static kal_uint8 get_cfg9_number = 0;
	static kal_uint8 get_cfg_number = 0;
	kal_uint32 parse_cfg_number;
	kal_uint32 event_group;
	USBH_EP_Struct usb_ep_str;
	USBH_Common_Struct common_str;
	USB_HCD_CTRL_SET_ADDRESS_T		dcl_data;
//	SGPT_CTRL_START_T start;
	usb_ep_str.ep_num = 0;//EP0 Control
	usb_ep_str.direction= USB_EP_TX_DIR;//EP0 Control
	common_str.usb_ip_port = usb_ip_port;

	if(((result == USB_HCD_NO_RESPONSE)||(result == USB_HCD_TIMEOUT)||(result == USB_HCD_STALL))
		&&(gUsbHost[usb_ip_port].ch9_state != USBD_CH9_START))
	{
		USB_Dbg_Trace(USBD_CH9_CALLBACK_ERROR,  (kal_uint32)result, (kal_uint32)gUsbHost[usb_ip_port].ch9_state);

		if((gUsbHost[usb_ip_port].ch9_state == USBD_CH9_SET_HNP_ENABLE)&&(result == USB_HCD_STALL))
	 	{
			/* Only match default driver then enable HNP feature */
			gUsbHost[usb_ip_port].support_hnp = USBD_HNP_ENABLE_STALL;
			/* enumeration is completed. reset error count to zero*/
			gUsbHost[usb_ip_port].ch9_error_count = 0;
			gUsbHost[usb_ip_port].ch9_state = USBD_CH9_ENUM_OK;

			// call the startup function
			drv_trace0(TRACE_FUNC, (kal_uint32)USB_HCD_RESPONSE_ERROR);
			gUsbHost[usb_ip_port].class_driver_ptr[gUsbHost[usb_ip_port].default_class_driver_index]->startup(usb_ip_port, NULL, 0, 0);

//			kal_set_eg_events(gUsbHost_Comm.usbd_com_ep0_event_id, EVENT_USBD_EP0_ENUMERATION, KAL_OR);
			}
		else
		{
			gUsbHost[usb_ip_port].ch9_error_count = 0;
			gUsbHost[usb_ip_port].ch9_state = USBD_CH9_ENUM_FAIL;

			// call the startup function
			drv_trace0(TRACE_FUNC, (kal_uint32)USB_HCD_ENUM_FAIL);
			gUsbHost[usb_ip_port].class_driver_ptr[gUsbHost[usb_ip_port].default_class_driver_index]->startup(usb_ip_port, NULL, 0, 0);

//			kal_set_eg_events(gUsbHost_Comm.usbd_com_ep0_event_id, EVENT_USBD_EP0_ENUMERATION, KAL_OR);		
		}
/*		
	 	else if(gUsbHost[usb_ip_port].ch9_error_count >= 3)
	 	{
			gUsbHost[usb_ip_port].ch9_error_count = 0;
			gUsbHost[usb_ip_port].ch9_state = USBD_CH9_ENUM_FAIL;

			// call the startup function
			gUsbHost[usb_ip_port].class_driver_ptr[gUsbHost[usb_ip_port].default_class_driver_index]->startup(usb_ip_port, NULL, 0, 0);

//			kal_set_eg_events(gUsbHost_Comm.usbd_com_ep0_event_id, EVENT_USBD_EP0_ENUMERATION, KAL_OR);
	 	}
	 	else
	 	{
			// error handling 
			gUsbHost[usb_ip_port].ch9_error_count++;

			USBD_Reset_Resource(usb_ip_port);
			// Error count does not exceed limitation, so restart enumeration 
		 		USBD_Set_UnMask_Irq(usb_ip_port, KAL_FALSE);
	 		// re-start enumeration after delay timeout 
		 		USBD_Delay_Reset_Device(usb_ip_port, result, USBD_ERROR_DELAY);
	 		}
*/
		// When error or stall, we return here 
		return;
	}


	if(gUsbHost[usb_ip_port].ch9_state == USBD_CH9_START)
	{
		USB_Dbg_Trace(USBD_CH9_CALLBACK_START,  0, 0);

		/* Should be task start enumeration */
		if((kal_if_lisr() == KAL_TRUE)||(kal_if_hisr() == KAL_TRUE))
			ASSERT(0);

		/* First, we set max packet size of ep0 as 8 */
		usb_ep_str.ep_max_pkt_size = 8;
		USBD_Set_EP_Max_Pkt(common_str,usb_ep_str); //USB_HCD_CTRL_EP_CTRL_FUNC_1_T

		get_cfg9_number = 0;
		get_cfg_number = 0;
		gUsbHost[usb_ip_port].ch9_state = USBD_CH9_GET_DEV_DESC_8;

		/* Get 8 bytes device descriptor */
		USBD_Get_Descriptor(common_str, USB_DEVICE<<8, 0, 8, (kal_uint8*)&gUsbHost[usb_ip_port].desc_info.dev_desc);
	}
	else if(gUsbHost[usb_ip_port].ch9_state == USBD_CH9_GET_DEV_DESC_8)
	{
		USB_Dbg_Trace(USBD_CH9_CALLBACK_GET_DEV_DESC_8,  0, 0);

		/* Check device descriptor */
		if((gUsbHost[usb_ip_port].desc_info.dev_desc.bLength != USB_DEVDSC_LENGTH)||(gUsbHost[usb_ip_port].desc_info.dev_desc.bDescriptorType != USB_DEVICE))
		{
			USB_Dbg_Trace(USBD_CH9_CALLBACK_ERROR,  (kal_uint32)gUsbHost[usb_ip_port].ch9_state, 0);
			/* error handling */
			gUsbHost[usb_ip_port].ch9_error_count++;

			USBD_Reset_Resource(usb_ip_port);
			/* error count does not exceed limitation, so restart enumeration*/
			USBD_Set_UnMask_Irq(usb_ip_port, KAL_FALSE);
			/* re-start enumeration after delay timeout */
			USBD_Delay_Reset_Device(usb_ip_port, result, USBD_ERROR_DELAY);
			return;
		}

		/* According to device */
		usb_ep_str.ep_max_pkt_size = gUsbHost[usb_ip_port].desc_info.dev_desc.bMaxPacketSize0;//EP0 Control
		USBD_Set_EP_Max_Pkt(common_str,usb_ep_str); // USB_HCD_CTRL_EP_CTRL_FUNC_1_T

		USBD_Set_Address(common_str, 1);
		gUsbHost[usb_ip_port].ch9_state = USBD_CH9_DELAY_SET_ADDR;
	}
	else if(gUsbHost[usb_ip_port].ch9_state == USBD_CH9_DELAY_SET_ADDR)
	{
		USB_Dbg_Trace(USBD_CH9_CALLBACK_DELAY_SET_ADDR,  0, 0);

		/* Delay at least 2ms for the "set_address" recovery period, in USB spec. 9.2.6.3 */
//		start.u2Tick = USBD_SET_ADDRESS_RECOVERY_DELAY;					
//    start.pfCallback = USBD_Set_Address_Recovery_Timeout;			
//    start.vPara = &gUsbHost[usb_ip_port];							
//    DclSGPT_Control((DCL_HANDLE)(gUsbHost[usb_ip_port].gpt_handle), SGPT_CMD_START, (DCL_CTRL_DATA_T*)&start);	
		USB_GPTI_StartItem(gUsbHost[usb_ip_port].gpt_handle, USBD_SET_ADDRESS_RECOVERY_DELAY,USBD_Set_Address_Recovery_Timeout, &gUsbHost[usb_ip_port]);
	}
	else if(gUsbHost[usb_ip_port].ch9_state == USBD_CH9_SET_ADDR)
	{
		USB_Dbg_Trace(USBD_CH9_CALLBACK_SET_ADDR,  0, 0);

		dcl_data.ip = (DCL_UINT8)usb_ip_port;
		dcl_data.addr = 1;
		DclUSB_HCD_Control(g_USB_HCD_Dcl_Handle, USB_HCD_CMD_USB_HCD_SetAddress, (DCL_CTRL_DATA_T  *)&dcl_data);					

		USBD_Get_Descriptor(common_str, USB_DEVICE<<8, 0, USB_DEVDSC_LENGTH,(kal_uint8*)&gUsbHost[usb_ip_port].desc_info.dev_desc);

		gUsbHost[usb_ip_port].ch9_state = USBD_CH9_GET_DEV_DESC;
	}
	else if(gUsbHost[usb_ip_port].ch9_state == USBD_CH9_GET_DEV_DESC)
	{
		if(get_cfg9_number == 0)
		{
			/* First time enter here */
			if(gUsbHost[usb_ip_port].ep0_status.todo != USB_DEVDSC_LENGTH)//Descriptor length = 18
				ASSERT(0);
		}

		USB_Dbg_Trace(USBD_CH9_CALLBACK_GET_DEV_DESC,  0, 0);

#ifdef __USB_HS_ENABLE__
		/* OTG test mode */
		if(gUsbHost[usb_ip_port].desc_info.dev_desc.idVendor == 0x1A0A)
		{
			/*  Enter OTG test mode */
			switch(gUsbHost[usb_ip_port].desc_info.dev_desc.idProduct)
			{
			case USBD_TEST_SE0_NAK:
				USB_Enter_Test_Mode(USB_TEST_MODE_TYPE_SE0_NAK);
				break;
			case USBD_TEST_J:
				USB_Enter_Test_Mode(USB_TEST_MODE_TYPE_J);
				break;
			case USBD_TEST_K:
				USB_Enter_Test_Mode(USB_TEST_MODE_TYPE_K);
				break;
			case USBD_TEST_PACKET:
				USB_Enter_Test_Mode(USB_TEST_MODE_TYPE_PACKET);
				break;
			case USBD_TEST_HS_HOST_PORT_SUSPEND_RESUME:
				USBD_Test_Mode_Hdlr(usb_ip_port, USBD_TEST_MODE_TYPE_HS_HOST_PORT_SUSPEND_RESUME);
				break;
			case USBD_TEST_SINGLE_STEP_GET_DEV_DESC:
				USBD_Test_Mode_Hdlr(usb_ip_port, USBD_TEST_MODE_TYPE_SINGLE_STEP_GET_DEV_DESC);
				break;
			case USBD_TEST_SINGLE_STEP_SET_FEATURE:
				USBD_Test_Mode_Hdlr(usb_ip_port, USBD_TEST_MODE_TYPE_SINGLE_STEP_SET_FEATURE);
				break;
//			case USBD_TEST_UNSUPPORTED_DEVICE:
//				USBD_Test_Mode_Hdlr(usb_ip_port, USBD_TEST_MODE_TYPE_UNSUPPORTED_DEVICE);
//				break;
			default:
				break;
			}
			return;				
		}
#endif

		if(get_cfg9_number == 0)
		{
			/* First time enter here, we get device descriptor */
			gUsbHost[usb_ip_port].desc_info.cfg_number = gUsbHost[usb_ip_port].desc_info.dev_desc.bNumConfigurations;

			if(gUsbHost[usb_ip_port].desc_info.cfg_number > USBD_MAX_CFG_NUM)
				gUsbHost[usb_ip_port].desc_info.cfg_number = USBD_MAX_CFG_NUM;
		}

		if (gUsbHost[usb_ip_port].desc_info.p_conf_data[get_cfg9_number] == NULL)
			gUsbHost[usb_ip_port].desc_info.p_conf_data[get_cfg9_number] = (kal_uint8 *)USB_Get_Memory(USB_MAX_OS_FEATURE_DESC_LENGTH);//(kal_uint8 *)get_ctrl_buffer(USB_CFGDSC_LENGTH);

		USBD_Get_Descriptor(common_str, (USB_CONFIG<<8)+get_cfg9_number, 0, USB_CFGDSC_LENGTH,
								gUsbHost[usb_ip_port].desc_info.p_conf_data[get_cfg9_number]);

		get_cfg9_number++;

		if(get_cfg9_number > gUsbHost[usb_ip_port].desc_info.cfg_number)
		{
			EXT_ASSERT(0, get_cfg9_number, gUsbHost[usb_ip_port].desc_info.cfg_number, 0);
		}
		else if(get_cfg9_number == gUsbHost[usb_ip_port].desc_info.cfg_number)
		{
			/* Get all config descriptors of the device */
			gUsbHost[usb_ip_port].ch9_state = USBD_CH9_GET_CONF_DESC_9;
		}
	}
	else if(gUsbHost[usb_ip_port].ch9_state == USBD_CH9_GET_CONF_DESC_9)
	{
		USB_Dbg_Trace(USBD_CH9_CALLBACK_GET_CONF_DESC_9,  0, 0);

		data_size = ((Usb_Cfg_Dscr*)gUsbHost[usb_ip_port].desc_info.p_conf_data[get_cfg_number])->wTotalLength;

		if(data_size >= 1024)
		{
			/* Size is too large, it is not a reasonable length. Let it match the default driver */
			// call the startup function
			drv_trace0(TRACE_FUNC, (kal_uint32)USB_HCD_COMMAND_FAIL);
			gUsbHost[usb_ip_port].class_driver_ptr[gUsbHost[usb_ip_port].default_class_driver_index]->startup(usb_ip_port, NULL, 0, 0);
//			kal_set_eg_events(gUsbHost_Comm.usbd_com_ep0_event_id, EVENT_USBD_EP0_ENUMERATION, KAL_OR);

			return;
		}

//		free_ctrl_buffer(gUsbHost[usb_ip_port].desc_info.p_conf_data[get_cfg_number]);
		if(gUsbHost[usb_ip_port].desc_info.p_conf_data[get_cfg_number] == NULL)
			gUsbHost[usb_ip_port].desc_info.p_conf_data[get_cfg_number] = (kal_uint8 *)USB_Get_Memory(USB_MAX_OS_FEATURE_DESC_LENGTH);//(kal_uint8 *)get_ctrl_buffer(data_size);

		USBD_Get_Descriptor(common_str, (USB_CONFIG<<8)+get_cfg_number, 0, data_size, gUsbHost[usb_ip_port].desc_info.p_conf_data[get_cfg_number]);
		get_cfg_number++;

		if(get_cfg_number > gUsbHost[usb_ip_port].desc_info.cfg_number)
		{
			EXT_ASSERT(0, get_cfg_number, gUsbHost[usb_ip_port].desc_info.cfg_number, 0);
		}
		else if(get_cfg_number == gUsbHost[usb_ip_port].desc_info.cfg_number)
		{
			gUsbHost[usb_ip_port].ch9_state = USBD_CH9_GET_CONF_DESC;
	}
	}
	else if(gUsbHost[usb_ip_port].ch9_state == USBD_CH9_GET_CONF_DESC)
	{
		USB_Dbg_Trace(USBD_CH9_CALLBACK_GET_CONF_DESC,  0, 0);

		/* They stands for all endpoint and interface number inside the device, not inside the single configuration */
		ep_index = 0;
		if_index = 0;

		for(parse_cfg_number = 0; parse_cfg_number < gUsbHost[usb_ip_port].desc_info.cfg_number; parse_cfg_number++)
		{
			/* Reset OTG descriptor */
			gUsbHost[usb_ip_port].desc_info.p_otg_desc[parse_cfg_number] = NULL;

			/* Configuration descriptor */
			gUsbHost[usb_ip_port].desc_info.cfg_info[parse_cfg_number].p_cfg_desc = (Usb_Cfg_Dscr*)gUsbHost[usb_ip_port].desc_info.p_conf_data[parse_cfg_number];


			data_size = gUsbHost[usb_ip_port].desc_info.cfg_info[parse_cfg_number].p_cfg_desc->wTotalLength;
			data_offset = gUsbHost[usb_ip_port].desc_info.cfg_info[parse_cfg_number].p_cfg_desc->bLength;

			if((data_offset != USB_CFGDSC_LENGTH)||(gUsbHost[usb_ip_port].default_class_driver_index == 0))
				ASSERT(0);

			gUsbHost[usb_ip_port].desc_info.cfg_info[parse_cfg_number].interface_number = 0;
			interface_number = 0;

			/* Parse each interface descriptor of each configuration */
			while(data_offset < data_size)
			{
				if((ep_index < USBD_MAX_EP_NUM)&&(if_index < USBD_MAX_INTERFACE_NUM))
				{
					p_interface_desc = (Usb_If_Dscr*)&gUsbHost[usb_ip_port].desc_info.p_conf_data[parse_cfg_number][data_offset];

					if (p_interface_desc->bLength == 0)
						break;

					if(p_interface_desc->bDescriptorType == USB_INTERFACE)
					{
						if(interface_number == USBD_MAX_IF_PER_CFG)
						{
							/* If device has 5 interfaces will meet this ASSERT */
//							EXT_ASSERT(0, parse_cfg_number, data_size, data_offset);
							/* Skip the while loop directly */
							data_offset = data_size;
						}
						else
						{
							gUsbHost[usb_ip_port].desc_info.interface_info[if_index].p_interface_desc = p_interface_desc;
							gUsbHost[usb_ip_port].desc_info.cfg_info[parse_cfg_number].p_interface_info[interface_number] = &gUsbHost[usb_ip_port].desc_info.interface_info[if_index];

							data_offset += gUsbHost[usb_ip_port].desc_info.interface_info[if_index].p_interface_desc->bLength;
							if_index++;

							gUsbHost[usb_ip_port].desc_info.cfg_info[parse_cfg_number].p_interface_info[interface_number]->ep_number = 0;
							gUsbHost[usb_ip_port].desc_info.cfg_info[parse_cfg_number].interface_number++;
							interface_number++;
						}
					}
					else if(p_interface_desc->bDescriptorType == USB_ENDPOINT)
					{
						if(interface_number == 0)
						{
							EXT_ASSERT(0, parse_cfg_number, data_size, data_offset);
						}
						else
						{
							if(gUsbHost[usb_ip_port].desc_info.cfg_info[parse_cfg_number].p_interface_info[interface_number-1]->ep_number <= USBD_MAX_EP_PER_IF)
							{
								gUsbHost[usb_ip_port].desc_info.ep_info[ep_index].p_stdep = (Usb_Ep_Dscr*)p_interface_desc;
								gUsbHost[usb_ip_port].desc_info.cfg_info[parse_cfg_number].p_interface_info[interface_number-1]->p_ep_info[gUsbHost[usb_ip_port].desc_info.cfg_info[parse_cfg_number].p_interface_info[interface_number-1]->ep_number] =
									&gUsbHost[usb_ip_port].desc_info.ep_info[ep_index]; //lint !e661 !e662

								data_offset += gUsbHost[usb_ip_port].desc_info.ep_info[ep_index].p_stdep->bLength;
							ep_index++;
								gUsbHost[usb_ip_port].desc_info.cfg_info[parse_cfg_number].p_interface_info[interface_number-1]->ep_number++; //lint !e661 !e662
							}
							else
							{
								/* if the interface has many endpoints */
								data_offset += p_interface_desc->bLength;
							}
						}
					}
					else if(p_interface_desc->bDescriptorType == USB_OTG_DESC)
					{
						gUsbHost[usb_ip_port].desc_info.p_otg_desc[parse_cfg_number] = (Usb_Otg_Dscr*)p_interface_desc;
						data_offset += p_interface_desc->bLength;
					}
					else if(p_interface_desc->bDescriptorType == USB_STRING)
					{
						gUsbHost[usb_ip_port].desc_info.string_desc = (Usb_String_Dscr*)p_interface_desc;
						data_offset += p_interface_desc->bLength;
					}
					else if(p_interface_desc->bDescriptorType == USB_DEVICE_QUALIFIER)
					{
						gUsbHost[usb_ip_port].desc_info.dev_qual_dscr = (Usb_Dev_Qual_Dscr*)p_interface_desc;
						data_offset += p_interface_desc->bLength;
					}	
					else if(p_interface_desc->bDescriptorType == USB_OTHER_SPEED)
					{
						gUsbHost[usb_ip_port].desc_info.other_speed_cfg_dscr = (Usb_Other_Speed_Cfg_Dscr*)p_interface_desc;
						data_offset += p_interface_desc->bLength;
					}
					else if(p_interface_desc->bDescriptorType == USB_INTERFACE_ASSOCIATION)
					{
							data_offset += p_interface_desc->bLength;					
					}		
					else if(p_interface_desc->bDescriptorType == USB_INTERFACE_POWER)
					{
							data_offset += p_interface_desc->bLength;					
					}					
					else
					{
						/* For video class, it has IAD or USBVIDEO_CS_INTERFACE (0x24)*/
						data_offset += p_interface_desc->bLength;
					}
				}
				else
				{
					EXT_ASSERT(0, if_index, ep_index, parse_cfg_number);
			}
		}

			if(interface_number == 0)
				ASSERT(0);

			for(index = 0; index < interface_number; index++)
		{
				for(index2 = 0; index2 <= gUsbHost[usb_ip_port].default_class_driver_index; index2++)
				{
					if(gUsbHost[usb_ip_port].class_driver_ptr[index2]->match(usb_ip_port, &gUsbHost[usb_ip_port].desc_info, parse_cfg_number, index) == KAL_TRUE)
					{
						/* Each interface should at least match default driver, so we do not count default driver */
						if(index2 != gUsbHost[usb_ip_port].default_class_driver_index)
						{
							gUsbHost[usb_ip_port].desc_info.cfg_info[parse_cfg_number].match_class_num++;
							gUsbHost[usb_ip_port].desc_info.cfg_info[parse_cfg_number].active_if_index_map |= 1<<index;
							gUsbHost[usb_ip_port].desc_info.cfg_info[parse_cfg_number].match_class_driver_point += *(gUsbHost_Comm.host_match_param->ext_class_driver_weight_tbl+index2);
						}

						gUsbHost[usb_ip_port].desc_info.cfg_info[parse_cfg_number].match_class_driver_index[index] = index2;
				break;
		}
				}
			}

			/* Match method */
			USBD_Match_Method(usb_ip_port,parse_cfg_number);
			
		}//for (parse_cfg_number)

		gUsbHost[usb_ip_port].support_hnp = USBD_HNP_NOT_SUPPORT;

		/* Match default driver */
		if(gUsbHost[usb_ip_port].set_cfg_number == 0)
		{
			if((gUsbHost[usb_ip_port].desc_info.p_otg_desc[0] != NULL)&&(gUsbHost[usb_ip_port].desc_info.p_otg_desc[0]->bAttribute&USB_OTG_HNP_SUPPORT))
			{
				/* Only match default driver then enable HNP feature */
				USB_Dbg_Trace(USBD_CH9_CALLBACK_SET_HNP_ENABLE,  0, 0);
				USBD_Set_Feature(common_str, USB_FTR_B_HNP_ENB, KAL_FALSE,USBD_Ch9_Callback);
				gUsbHost[usb_ip_port].ch9_state = USBD_CH9_SET_HNP_ENABLE;
			}
			else
			{
				USB_Dbg_Trace(USBD_CH9_CALLBACK_SET_CONF_DONE,  1, 0);

				/* Check if it matches hub class */
				if((gUsbHost[usb_ip_port].desc_info.dev_desc.bDeviceClass == USB_HUB_DEVICE_CLASS_CODE)
					&& (gUsbHost[usb_ip_port].desc_info.cfg_info[0].p_interface_info[0]->p_interface_desc->bInterfaceClass == USB_HUB_INTERFACE_CLASS_CODE))
				{
					gUsbHost[usb_ip_port].b_is_match_hub = KAL_TRUE;
				}
				else
				{
					gUsbHost[usb_ip_port].b_is_match_hub = KAL_FALSE;
				}

				// call the startup function
				drv_trace0(TRACE_FUNC, (kal_uint32)USB_HCD_UN_SUPPORT);
				gUsbHost[usb_ip_port].class_driver_ptr[gUsbHost[usb_ip_port].default_class_driver_index]->startup(usb_ip_port, NULL, 0, 0);

//				kal_set_eg_events(gUsbHost_Comm.usbd_com_ep0_event_id, EVENT_USBD_EP0_ENUMERATION, KAL_OR);

				/* enumeration is completed. reset error count to zero*/
				gUsbHost[usb_ip_port].ch9_error_count = 0;
				gUsbHost[usb_ip_port].ch9_state = USBD_CH9_ENUM_OK;
			}
		}
		else
		{
			USB_Dbg_Trace(USBD_CH9_CALLBACK_SET_CONF,  gUsbHost[usb_ip_port].set_cfg_number, 0);
			USBD_Set_Configuration(common_str, gUsbHost[usb_ip_port].set_cfg_number);
			gUsbHost[usb_ip_port].ch9_state = USBD_CH9_SET_CONF;
		}
	}
	else if((gUsbHost[usb_ip_port].ch9_state == USBD_CH9_SET_CONF)||(gUsbHost[usb_ip_port].ch9_state == USBD_CH9_SET_HNP_ENABLE))
	{
		USB_Dbg_Trace(USBD_CH9_CALLBACK_SET_CONF_DONE,  2, 0);

		if(gUsbHost[usb_ip_port].ch9_state == USBD_CH9_SET_HNP_ENABLE)
			gUsbHost[usb_ip_port].support_hnp = USBD_HNP_SUPPORT;

		/* Enumeration is completed. reset error count to zero */
		gUsbHost[usb_ip_port].ch9_error_count = 0;
		gUsbHost[usb_ip_port].ch9_state = USBD_CH9_ENUM_OK;

		/* Clear all events, that may exist after previous detatch or USBD enumeration, before class drivers want to use ep0 commands */
		kal_retrieve_eg_events(gUsbHost[usb_ip_port].usbd_ep0_event_id, EVENT_USBD_EP0_DONE|EVENT_USBD_EP0_DETACH,
				KAL_OR_CONSUME, &event_group, KAL_NO_SUSPEND);

		USB_Dbg_Trace(USBD_EP0_CMD_REC_EVENT,  3, 0);

		// Call the startup function
		if(gUsbHost[usb_ip_port].set_cfg_number == 0)
		{
			drv_trace0(TRACE_FUNC, (kal_uint32)USB_HCD_UN_SUPPORT);
			gUsbHost[usb_ip_port].class_driver_ptr[gUsbHost[usb_ip_port].default_class_driver_index]->startup(usb_ip_port, NULL, 0, 0);
		}
		else
		{
			/* set_cfg_number != 0 must match some drivers */
			for(index = 0; index < gUsbHost[usb_ip_port].desc_info.cfg_info[gUsbHost[usb_ip_port].set_cfg_number-1].interface_number; index++)
			{
				if(gUsbHost[usb_ip_port].desc_info.cfg_info[gUsbHost[usb_ip_port].set_cfg_number-1].match_class_driver_index[index] < gUsbHost[usb_ip_port].default_class_driver_index)
					gUsbHost[usb_ip_port].class_driver_ptr[gUsbHost[usb_ip_port].desc_info.cfg_info[gUsbHost[usb_ip_port].set_cfg_number-1].match_class_driver_index[index]]->startup(usb_ip_port, &gUsbHost[usb_ip_port].desc_info, (gUsbHost[usb_ip_port].set_cfg_number-1), index);
			}
		}

//		kal_set_eg_events(gUsbHost_Comm.usbd_com_ep0_event_id, EVENT_USBD_EP0_ENUMERATION, KAL_OR);
	}
}


/* EP0 handler. The SETUP, DATA, STATUS state is handled in this handler */
static void USBD_EP0_Hdlr(kal_uint8 usb_ip_port, USB_HCD_STATUS result, kal_uint32 param)
{
	USBH_Common_Struct common_str;
	USBH_EP_Struct usb_ep_str;
	common_str.usb_ip_port = usb_ip_port; 
	usb_ep_str.ep_num = 0;
	usb_ep_str.ep_type = USB_ENDPT_CTRL;

	if(result == USB_HCD_OK)
	{
		if(gUsbHost[usb_ip_port].ep0_state == USBD_EP0_SETUP)
		{
			if(gUsbHost[usb_ip_port].ep0_status.todo != 0)
			{
				/* Have data to send/recv */
				if(gUsbHost[usb_ip_port].ep0_status.ep0_data_dir == USBD_EP0_DATA_RECV)
				{
					usb_ep_str.direction = USB_EP_RX_DIR;
					USBD_EP0_Data_Req(common_str,usb_ep_str, gUsbHost[usb_ip_port].ep0_status.todo, gUsbHost[usb_ip_port].ep0_status.data_ptr);
				}
				else if(gUsbHost[usb_ip_port].ep0_status.ep0_data_dir == USBD_EP0_DATA_SEND)
				{
					usb_ep_str.direction = USB_EP_TX_DIR;
					USBD_EP0_Data_Req(common_str,usb_ep_str, gUsbHost[usb_ip_port].ep0_status.todo, gUsbHost[usb_ip_port].ep0_status.data_ptr);
				}

				gUsbHost[usb_ip_port].ep0_state = USBD_EP0_DATA;
			}
			else
			{
				/* Request for the status */
				usb_ep_str.direction = USB_EP_RX_DIR;// Setup + IN				
				USBD_EP0_Status_Req(common_str,usb_ep_str);
				gUsbHost[usb_ip_port].ep0_state = USBD_EP0_STATUS;
			}
		}
		else if(gUsbHost[usb_ip_port].ep0_state == USBD_EP0_DATA)
		{
			/* request for the "status" packet */
			if(gUsbHost[usb_ip_port].ep0_status.ep0_data_dir == USBD_EP0_DATA_RECV)
			{	
				usb_ep_str.direction = USB_EP_TX_DIR;// Setup + IN + OUT				
				USBD_EP0_Status_Req(common_str,usb_ep_str);
			}
			else  if(gUsbHost[usb_ip_port].ep0_status.ep0_data_dir == USBD_EP0_DATA_SEND)
			{	
				usb_ep_str.direction = USB_EP_RX_DIR;// Setup + OUT + IN				
				USBD_EP0_Status_Req(common_str,usb_ep_str);
			}

			gUsbHost[usb_ip_port].ep0_state = USBD_EP0_STATUS;
		}
		else if(gUsbHost[usb_ip_port].ep0_state == USBD_EP0_STATUS)
		{
			USB_Dbg_Trace(USBD_EP0_CMD_SET_EVENT,  2, 0);
			kal_set_eg_events(gUsbHost[usb_ip_port].usbd_ep0_event_id, EVENT_USBD_EP0_DONE, KAL_OR);

			gUsbHost[usb_ip_port].ep0_state = USBD_EP0_NONE;
			gUsbHost[usb_ip_port].ep0_callback(usb_ip_port, result, gUsbHost[usb_ip_port].ep0_status.sofar);
		}
		else
		{
			ASSERT(0);
		}
	} /* result == USB_HCD_OK */
	else if((result == USB_HCD_NO_RESPONSE)||(result == USB_HCD_TIMEOUT)||(result == USB_HCD_STALL))
	{
		USB_Dbg_Trace(USBD_EP0_CMD_SET_EVENT,  3, 0);
		kal_set_eg_events(gUsbHost[usb_ip_port].usbd_ep0_event_id, EVENT_USBD_EP0_DONE, KAL_OR);

		// no matter it is in which state, return to NONE
		gUsbHost[usb_ip_port].ep0_state = USBD_EP0_NONE;
		gUsbHost[usb_ip_port].ep0_callback(usb_ip_port, result, param);
	}
}


#endif /* __OTG_ENABLE__*/


