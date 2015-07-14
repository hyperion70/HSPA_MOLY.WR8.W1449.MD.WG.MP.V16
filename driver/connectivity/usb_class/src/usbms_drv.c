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
 *    usbms_drv.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements usb MASS STORAGE class driver
 *
 * Author:
 * -------
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

#ifdef  __USB_MASS_STORAGE_ENABLE__

#include "drv_comm.h"
//#include "reg_base.h"
#include "intrCtrl.h"
//#include "stack_common.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "kal_public_api.h" //#include "stack_ltlcom.h" //MSBB change #include "app_ltlcom.h"
//#include "app_buff_alloc.h"
//#include "usb_comm.h"
#include "drvsignals.h"
//#include "gpt_sw.h"

//#include "usb_drv.h"
#include "usb_adap.h"
#include "usb.h"
#include "usb_resource.h"

#include "usbms_drv.h"
#include "usbms_adap.h"
#include "usb_custom.h"
#include "usb_debug_tool.h"
#include "usb_trc.h"
//#include "kal_non_specific_general_types.h"
//#include "kal_release.h"
#include "kal_public_api.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "kal_public_api.h" //#include "stack_ltlcom.h"
#include "kal_trace.h"

#include "kal_public_api.h"
#include "kal_general_types.h"

#include "drv_msgid.h"

#if defined(DRV_USB_POWER_DOWN_SUPPORT)&&defined(MTK_SLEEP_ENABLE)&&defined(DRV_USB_SLEEP_SUPPORT)
extern kal_uint8 L1SM_GetHandle(void);
kal_uint8 usbms_pdn_handle = 0;
#endif


UsbMs_Struct g_UsbMS;


/* static functions */
//static void USB_Ms_DMA_Timeout_hdlr(void *parameter);
static void USB_Ms_Rx_DMA_Callback(void);
static void USB_Ms_Tx_DMA_Callback(void);
static void USB_Ms_Ep0_Command(Usb_Ep0_Status *pep0state, Usb_Command *pcmd);
static void USB_Ms_BulkOut_Hdlr(void);
static void USB_Ms_BulkIn_Reset(void);
static void USB_Ms_BulkOut_Reset(void);
static void USB_Ms_Cmd_Reset(void);



const kal_uint8 ms_if_dscr[]=
{
	USB_IFDSC_LENGTH,	//bLength;
	USB_INTERFACE,	//bDescriptorType;
	0x00,	//bInterfaceNumber;
	0x00,	//bAlternateSetting;
	USB_MS_EP_NUMBER,	//bNumEndpoints;
	USB_MS_INTERFACE_CLASS_CODE,	//bInterfaceClass;
	USB_MS_INTERFACE_SUBCLASS_CODE,	//bInterfaceSubClass;
	USB_MS_INTERFACE_PROTOCOL_CODE,	//bInterfaceProtocol;
	0x00	//iInterface;
};

const kal_uint8 ms_ep_in_dscr[]=
{
	USB_EPDSC_LENGTH,	//bLength;
	USB_ENDPOINT,	//bDescriptorType;
	0x00,	//bEndpointAddress;
	USB_EP_BULK,	//bmAttributes;
	0x40,	//wMaxPacketSize[2];	
	0x00,	//wMaxPacketSize[2];	
	0x00	//bInterval;
};

const kal_uint8 ms_ep_out_dscr[]=
{
	USB_EPDSC_LENGTH,	//bLength;
	USB_ENDPOINT,	//bDescriptorType;
	0x00,	//bEndpointAddress;
	USB_EP_BULK,	//bmAttributes;
	0x40,	//wMaxPacketSize[2];	
	0x00,	//wMaxPacketSize[2];	
	0x00	//bInterval;
};

#ifdef __MBIM_SUPPORT__
	static const kal_uint8 MBIM_COMPATIBLE_ID[] = {0x41, 0x4C, 0x54, 0x52, 0x43, 0x46, 0x47, 0x00};
	static const kal_uint8 MBIM_SUBCOMPATIBLE_ID[] = {0x32, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
#endif

/************************************************************
	DMA time out handler
*************************************************************/
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
#endif

/************************************************************
	TX/RX path build functions(use DMA)
*************************************************************/

/* Prepare to receive RX packet to addr and length len */
void USB_Ms_BuildRx(void *addr, kal_uint32 len)
{
//	GPTI_StopItem(g_UsbMS.dma_timeout_handle);

	USB_Dbg_Trace(USB_MS_BUILD_DMA_RX, 0 , 0);

	/* For CBW is 31 */
	if(len == 31)
	{
		ASSERT(0);
//		GPTI_StartItem(g_UsbMS.dma_timeout_handle, USBMS_DMA_TIMEOUT, USB_Ms_DMA_Timeout_hdlr, NULL);
	}

	/* Stop and ack DMA if previous DMA is not yet ready */
	USB_Stop_DMA_Channel(g_UsbMS.rxpipe->byEP, USB_EP_RX_DIR);

	/* Initialize rxpipe data */
	g_UsbMS.rxpipe->pData = (kal_uint8 *)addr;
	g_UsbMS.rxpipe->nBytesRecv = 0;
	g_UsbMS.rxpipe->nBuffLen = (kal_int32)len;

	USB_Mask_USB_CORE(USB_MASK_OWNER_MS); //IRQMask(IRQ_USB_CODE);

	/* USB reset and MS ep0 reset cmd will both stop DMA */
	/* If they happen before IRQmask, we will not build DMA in the following if conditions */
	/* If they happen after IRQmask, they will stop DMA */
	/* If before they stop DMA, the DMA already done, this DMA callback message will be ignored by USB task if checking */

	//After USB Reset or USB_EP0_Command_Reset, we must build DMA RX for the first CBW (reset = True)(nState = IDLE)
	//make sure : handle USB Reset message first. (ex. going to build RX + USB_RESET+ Build RX+ USB_RESET_Message(build RX))
	if((g_UsbMS.usb_reset == KAL_FALSE)&&(g_UsbMS.ms_is_reset == KAL_FALSE))
	{
		/* DMA running state is NOT cleared by USB_Ms_Rx_DMA_Callback */
		USB_DMA_Setup(g_UsbMS.rxpipe->byEP, USB_EP_RX_DIR, USB_ENDPT_BULK, (kal_uint32)addr, len,
					USB_Ms_Rx_DMA_Callback, KAL_FALSE, KAL_TRUE, USB_DMA1_TYPE);
	}
	
	//USB_UnMask_Irq(USB_MASK_OWNER_MS);
	if(USB_Get_UnMask_Irq() == KAL_TRUE)
		USB_UnMask_USB_CORE(USB_MASK_OWNER_MS); //IRQUnmask(IRQ_USB_CODE);

}


/* Prepare to transmit Tx packet from addr and length len */
void USB_Ms_BuildTx(void *addr, kal_uint32 len)
{
	USB_Dbg_Trace(USB_MS_BUILD_DMA_TX, 0, 0);

	/* Stop and ack DMA if previous DMA is not yet ready */
	USB_Stop_DMA_Channel(g_UsbMS.txpipe->byEP, USB_EP_TX_DIR);

	/* Initialize TX pipe */
	g_UsbMS.txpipe->pData = (kal_uint8 *)addr;
	g_UsbMS.txpipe->nBytesLeft = (kal_int32)len;

	USB_Mask_USB_CORE(USB_MASK_OWNER_MS); //IRQMask(IRQ_USB_CODE);


	/* USB reset and MS ep0 reset cmd will both stop DMA */
	/* If they happen before IRQmask, we will not build DMA in the following if conditions */
	/* If they happen after IRQmask, they will stop DMA */
	/* If before they stop DMA, the DMA already done, this DMA callback message will be ignored by USB task's if checking */
	if ((g_UsbMS.usb_reset == KAL_FALSE)&&(g_UsbMS.ms_is_reset == KAL_FALSE))
	{
		/* For CSW is 13 */
		if(len != 13)
		{
			/* DMA running state is NOT cleared by USB_Ms_Tx_DMA_Callback */
			USB_DMA_Setup(g_UsbMS.txpipe->byEP, USB_EP_TX_DIR, USB_ENDPT_BULK, (kal_uint32)addr, len,
						USB_Ms_Tx_DMA_Callback, KAL_FALSE, KAL_TRUE, USB_DMA1_TYPE);
		}
		else
		{
			/* DMA running state is NOT cleared by USB_Ms_Tx_DMA_Callback */
			USB_DMA_Setup(g_UsbMS.txpipe->byEP, USB_EP_TX_DIR, USB_ENDPT_BULK, (kal_uint32)addr, len,
						NULL, KAL_FALSE, KAL_TRUE, USB_DMA1_TYPE);
		}
	}
	
	//USB_UnMask_Irq(USB_MASK_OWNER_MS);
	if(USB_Get_UnMask_Irq() == KAL_TRUE)
		USB_UnMask_USB_CORE(USB_MASK_OWNER_MS); //IRQUnmask(IRQ_USB_CODE);

}


/************************************************************
	interface initialization functions
*************************************************************/

/* interface create function, prepare descriptor */
void USB_Ms_If_Create(void *ifname)
{
	kal_uint8 ep_in_id;
	kal_uint8 ep_out_id;
	kal_uint8 if_id;


	/* get resource number and register to gUsbDevice */
	g_UsbMS.ms_if_info = USB_Get_Interface_Number(&if_id);
	g_UsbMS.ms_ep_in_info = USB_Get_Bulk_Tx_Ep(&ep_in_id);
	g_UsbMS.ms_ep_out_info = USB_Get_Bulk_Rx_Ep(&ep_out_id);

	/* record interface name and interface descriptor length */
	g_UsbMS.ms_if_info->interface_name_ptr = (kal_char *)ifname;
	g_UsbMS.ms_if_info->ifdscr_size = USB_IFDSC_LENGTH;
	g_UsbMS.ms_ep_in_info->epdscr_size = USB_EPDSC_LENGTH;
	g_UsbMS.ms_ep_out_info->epdscr_size = USB_EPDSC_LENGTH;

	/* related endpoint info and class specific command handler*/
	g_UsbMS.ms_if_info->ep_info[0] = (Usb_Ep_Info*)g_UsbMS.ms_ep_in_info;
	g_UsbMS.ms_if_info->ep_info[1] = (Usb_Ep_Info*)g_UsbMS.ms_ep_out_info;
	g_UsbMS.ms_if_info->if_class_specific_hdlr = USB_Ms_Ep0_Command;

	kal_mem_cpy(&(g_UsbMS.ms_if_info->ifdscr.stdif), ms_if_dscr, USB_IFDSC_LENGTH);
	kal_mem_cpy(&(g_UsbMS.ms_ep_in_info->epdesc.stdep), ms_ep_in_dscr, USB_EPDSC_LENGTH);
	kal_mem_cpy(&(g_UsbMS.ms_ep_out_info->epdesc.stdep), ms_ep_out_dscr, USB_EPDSC_LENGTH);

	g_UsbMS.ms_if_info->ifdscr.stdif.bInterfaceNumber = if_id;
	g_UsbMS.ms_if_info->ifdscr.stdif.iInterface = USB_Get_String_Number((void *)g_UsbMS.ms_param->interface_string);

	/* endpoint handler */
	USB_Register_Drv_Info(USB_DRV_HDLR_EP_TX, ep_in_id, NULL);
	g_UsbMS.ms_ep_in_info->ep_reset = USB_Ms_BulkIn_Reset;
	USB_Register_Drv_Info(USB_DRV_HDLR_EP_RX, ep_out_id, USB_Ms_BulkOut_Hdlr);
	g_UsbMS.ms_ep_out_info->ep_reset = USB_Ms_BulkOut_Reset;

	g_UsbMS.ms_ep_in_info->epdesc.stdep.bEndpointAddress = (USB_EP_DIR_IN | ep_in_id);	/*InPipe*/
	g_UsbMS.ms_ep_in_info->ep_status.epin_status.byEP = ep_in_id;
	g_UsbMS.ms_ep_in_info->ep_status.epin_status.nBytesLeft = USB_EP_NODATA;
	g_UsbMS.ms_ep_out_info->epdesc.stdep.bEndpointAddress = (USB_EP_DIR_OUT | ep_out_id);	/*OutPipe*/
	g_UsbMS.ms_ep_out_info->ep_status.epout_status.byEP = ep_out_id;

	USB_Get_DMA_Channel(ep_in_id, ep_out_id, USB_EP_TX_DIR, KAL_TRUE); /*  in & out eps use the same DMA channel */

#ifdef __MBIM_SUPPORT__	

	if(gUsbDevice.device_type == USB_MORPHING_MBIM)
	{
		kal_uint32 index;
		/* OS feature descriptors */
		kal_mem_set(&gUsbDevice.os_feature_desc, 0x00, sizeof(Usb_Ext_Compat_ID_OS_Feature_Dscr));
		
		gUsbDevice.os_feature_desc.dwLength = USB_MAX_OS_FEATURE_DESC_LENGTH;
		gUsbDevice.os_feature_desc.bcdVersion = 0x0100;
		gUsbDevice.os_feature_desc.wIndex = USB_FTR_EXT_COMPAT_ID;
		gUsbDevice.os_feature_desc.bCount = 0x01;
		gUsbDevice.os_feature_desc.bFirstInterfaceNumber = 0x00;
		gUsbDevice.os_feature_desc.bPads_2 = 0x01;			
		for(index = 0; index < 8; index++)
		{
			gUsbDevice.os_feature_desc.compatibleID[index] = MBIM_COMPATIBLE_ID[index];
			gUsbDevice.os_feature_desc.subcompatibleID[index] = MBIM_SUBCOMPATIBLE_ID[index];					
		}
	}
#endif

//	if((g_UsbMS.dma_timeout_handle == 0) || (g_UsbMS.dma_timeout_handle == 0x7F))
//		GPTI_GetHandle(&g_UsbMS.dma_timeout_handle);   /* for DMA time out use!!*/
}


/* interface reset function */
void USB_Ms_If_Reset(void)
{
	kal_uint8 index;
	
	/* This must not exist because use this trivky to avoid reset abnormal operation when writing to flash*/
	g_UsbMS.txpipe = &g_UsbMS.ms_ep_in_info->ep_status.epin_status;
	g_UsbMS.rxpipe = &g_UsbMS.ms_ep_out_info->ep_status.epout_status;

	g_UsbMS.usb_reset= KAL_TRUE;
	g_UsbMS.ms_read_write_reset = KAL_TRUE;
	
	for (index = 0;index<MAX_DISK_DRVER;index++)
	{
		g_UsbMS.power_off_state[index] = KAL_FALSE;
		g_UsbMS.prev_write_fail[index] = KAL_FALSE;		
	}

	/* Stop DMA */
	USB_Stop_DMA_Channel(g_UsbMS.rxpipe->byEP, USB_EP_RX_DIR);
}

/* interface resume function */
void USB_Ms_If_Resume(void)
{
	kal_uint8 index;		
	for (index = 0;index<MAX_DISK_DRVER;index++)
	{
		g_UsbMS.power_off_state[index] = KAL_FALSE;
		g_UsbMS.prev_write_fail[index] = KAL_FALSE;		
	}
}



/* interface enable function, enable EP*/
void USB_Ms_If_Enable(void)
{
//	ilm_struct *usb_ilm = NULL;


	/* Stop DMA */
	/* Compliance test tool will set configuration , but no reset */
	USB_Stop_DMA_Channel(g_UsbMS.rxpipe->byEP, USB_EP_RX_DIR);

	/* Configure DMA setting for EP */
	USB_TxEPEn(g_UsbMS.txpipe->byEP, USB_ENDPT_BULK, USB_EP_USE_ONLY_DMA, KAL_TRUE, KAL_FALSE);
	USB_RxEPEn(g_UsbMS.rxpipe->byEP, USB_ENDPT_BULK, USB_EP_USE_DMA_ON_DEMAND, KAL_TRUE, KAL_FALSE);

	USB_Dbg_Trace(USB_MS_SWITCH_TO_FIFO_RX_BY_USB_CONFIG, 0, 0);
	/* We do not dynamically switch TX's usage, since if we config TX DMA, and in DMA callback, we switch to FIFO,
	but last packet is sent out after we switch to FIFO, IP will give a ep intr for this DMA "sending" packet, so we will see two ep intrs */

	/* Send reset message to usb task, task handle the ms state machine */
	if(g_UsbMS.is_send_usb_reset_ilm == KAL_TRUE)
	{
		g_UsbMS.is_send_usb_reset_ilm = KAL_FALSE;

		USB_Send_Msg_Ext_Queue(MOD_USB,MSG_ID_USB_MSDRV_RESET_IND, NULL);

//		DRV_BuildPrimitive(usb_ilm, MOD_DRV_HISR, MOD_USB,MSG_ID_USB_MSDRV_RESET_IND, NULL);
//		msg_send_ext_queue(usb_ilm);
	}
}


/* interface speed reset function, change EP's speed-specific descriptor */
void USB_Ms_If_Speed_Reset(kal_bool b_other_speed)
{
#ifdef __USB_HS_ENABLE__

	kal_uint32  max_packet;
	max_packet = USB_Speed_Reset_Packet_Size(b_other_speed);	


	g_UsbMS.ms_ep_in_info->epdesc.stdep.wMaxPacketSize[0] = max_packet &0xff;
	g_UsbMS.ms_ep_in_info->epdesc.stdep.wMaxPacketSize[1] = (max_packet>>8) &0xff;
	
	g_UsbMS.ms_ep_out_info->epdesc.stdep.wMaxPacketSize[0] = max_packet &0xff;
	g_UsbMS.ms_ep_out_info->epdesc.stdep.wMaxPacketSize[1] = (max_packet>>8)&0xff;

#endif
}


/************************************************************
	global variable g_UsbMS initialize and release functions
*************************************************************/

/* initialize global variable g_UsbMS */
void USB_Init_Ms_Status(void)
{
	kal_uint8 index;

	g_UsbMS.nState = USBMS_IDLE;
	g_UsbMS.txpipe = NULL;
	g_UsbMS.rxpipe = NULL;
	g_UsbMS.max_LUN = USB_Ms_Get_Max_LUN();
	g_UsbMS.current_LUN = 0;
	g_UsbMS.is_send_usb_reset_ilm = KAL_TRUE;
	g_UsbMS.cbw_is_vaild = KAL_TRUE;
	g_UsbMS.ms_is_reset = KAL_FALSE;
	g_UsbMS.usb_reset = KAL_FALSE;
	g_UsbMS.CSWDataResidue = 0;
	g_UsbMS.CSWStatusError = 0x00;
	g_UsbMS.sensePtr = NULL;

	for (index = 0;index<MAX_DISK_DRVER;index++)
	{
		g_UsbMS.power_off_state[index] = KAL_FALSE;
		g_UsbMS.prev_write_fail[index] = KAL_FALSE;		
	}
	
#if defined(DRV_USB_POWER_DOWN_SUPPORT)&&defined(MTK_SLEEP_ENABLE)&&defined(DRV_USB_SLEEP_SUPPORT)
	if (usbms_pdn_handle == 0)
	{
		usbms_pdn_handle = L1SM_GetHandle();
	}
#endif
}


/* release global variable g_UsbMS */
void USB_Release_Ms_Status(void)
{
	USB_Free_DMA_Channel(g_UsbMS.txpipe->byEP, g_UsbMS.rxpipe->byEP, USB_EP_TX_DIR, KAL_TRUE);
	USB_Init_Ms_Status();
//	g_UsbMS.disk_buffer = NULL;
}


/************************************************************
	Tx/Rx path DMA callback function
*************************************************************/

/* RX DMA callback function*/
static void USB_Ms_Rx_DMA_Callback(void)
{
//	ilm_struct *usb_ilm = NULL;
	usb_ms_rec_done_conf_struct *rec_done_conf;


	/* MS reset cmd must re start from RX CBW */
//	g_UsbMS.ms_is_reset = KAL_FALSE;
//	g_UsbMS.usb_reset = KAL_FALSE;

/*
	if(g_UsbMS.rxpipe->nBuffLen == 31)
	{
		GPTI_StopItem(g_UsbMS.dma_timeout_handle);
	}
*/
	if(USB_Get_Device_State() == DEVSTATE_CONFIG)
	{
		g_UsbMS.rxpipe->nBytesRecv = g_UsbMS.rxpipe->nBuffLen;

		/* Send message to usb task, let ms state machine handle the received data */
		rec_done_conf = (usb_ms_rec_done_conf_struct *)construct_local_para(
							sizeof(usb_ms_rec_done_conf_struct), TD_CTRL);
		rec_done_conf->pData = g_UsbMS.rxpipe->pData;
		rec_done_conf->nBuffLen = g_UsbMS.rxpipe->nBuffLen;
		rec_done_conf->nBytesRecv = g_UsbMS.rxpipe->nBuffLen;

		USB_Send_Msg_Ext_Queue(MOD_USB, MSG_ID_USB_MSDRV_REC_DONE_CONF, rec_done_conf);

//		DRV_BuildPrimitive(usb_ilm, MOD_DRV_HISR,MOD_USB, MSG_ID_USB_MSDRV_REC_DONE_CONF, rec_done_conf);
//		msg_send_ext_queue(usb_ilm);
	}
}


/* TX DMA callback function */
static void USB_Ms_Tx_DMA_Callback(void)
{
//	ilm_struct *usb_ilm = NULL;


	if(USB_Get_Device_State() == DEVSTATE_CONFIG)
	{
		g_UsbMS.txpipe->nBytesLeft = USB_EP_NODATA;

		/*send message to usb task, let ms state machine handle the transmitted data*/
		USB_Send_Msg_Ext_Queue(MOD_USB, MSG_ID_USB_MSDRV_TRX_DONE_CONF, NULL);
		
//		DRV_BuildPrimitive(usb_ilm, MOD_DRV_HISR,MOD_USB, MSG_ID_USB_MSDRV_TRX_DONE_CONF, NULL);
//		msg_send_ext_queue(usb_ilm);
	}
}


/************************************************************
	EP0 command parse functions
*************************************************************/

/* Reset command handler */
static void USB_Ms_Cmd_Reset(void)
{
//	ilm_struct *usb_ilm = NULL;


	/* Stop and ack DMA if previous DMA is not yet ready */
	USB_Stop_DMA_Channel(g_UsbMS.rxpipe->byEP, USB_EP_RX_DIR);

	USB_Clear_Tx_EP_FIFO(g_UsbMS.txpipe->byEP, USB_ENDPT_BULK, KAL_TRUE);
	USB_Clear_Rx_EP_FIFO(g_UsbMS.rxpipe->byEP, USB_ENDPT_BULK, KAL_TRUE);

	/* Switch endpoint state to use FIFOread */
	if(USB_RxEP_Usage(g_UsbMS.rxpipe->byEP) == USB_EP_STATE_DMA)
		USB_Config_RxEP_Type(g_UsbMS.rxpipe->byEP, USB_ENDPT_BULK, KAL_FALSE);

	/* Send reset message to usb task, task handle the state machine */
	if(g_UsbMS.is_send_usb_reset_ilm == KAL_TRUE)
	{
		/* avoid sending too many messages to task when task is busy writing*/
		g_UsbMS.is_send_usb_reset_ilm = KAL_FALSE;

		USB_Send_Msg_Ext_Queue(MOD_USB, MSG_ID_USB_MSDRV_RESET_IND, NULL);

//		DRV_BuildPrimitive(usb_ilm, MOD_DRV_HISR,MOD_USB, MSG_ID_USB_MSDRV_RESET_IND, NULL);
//		msg_send_ext_queue(usb_ilm);
	}
}


/* parse MS class specific command */
static void USB_Ms_Ep0_Command(Usb_Ep0_Status *pep0state, Usb_Command *pcmd)
{
	kal_bool  bError = KAL_FALSE;


	switch (pcmd->bRequest)
	{
	case USB_MS_RESET:
		if( (pcmd->bmRequestType != USB_CMD_CLASSIFOUT) ||(pcmd->wValue != 0) )
		{
			bError = KAL_TRUE;
		}
		else
		{
			/* In USB compliance tool, PC will send MS ep0 reset cmd, and then clear ep feature, and send CBW */
			USB_Dbg_Trace(USB_MS_EP0_RESET, 0, 0);
			g_UsbMS.cbw_is_vaild = KAL_TRUE;
			g_UsbMS.ms_is_reset = KAL_TRUE;
			/* Build DMA RX here */
			USB_Ms_Cmd_Reset();
			/* Must clear stall status here */
			USB_CtrlEPStall(g_UsbMS.txpipe->byEP, USB_EP_TX_DIR, KAL_FALSE);
			USB_CtrlEPStall(g_UsbMS.rxpipe->byEP, USB_EP_RX_DIR, KAL_FALSE);
		}
		break;

	case USB_MS_GETMAXLUN:
		if( (pcmd->bmRequestType != USB_CMD_CLASSIFIN) ||(pcmd->wValue != 0) )
		{
			bError = KAL_TRUE;
		}
		else
		{
			#if defined(__USB_MASS_CLEARFIFOTOGGLE_IN_MAXLUN__)
			/* Stop and ack DMA if previous DMA is not yet ready */
			USB_Stop_DMA_Channel(g_UsbMS.rxpipe->byEP, USB_EP_RX_DIR);

				USB_Clear_Tx_EP_FIFO(g_UsbMS.txpipe->byEP, USB_ENDPT_BULK, KAL_TRUE);
				USB_Clear_Rx_EP_FIFO(g_UsbMS.rxpipe->byEP, USB_ENDPT_BULK, KAL_TRUE);
			/* Switch endpoint state to use FIFOread */
			if(USB_RxEP_Usage(g_UsbMS.rxpipe->byEP) == USB_EP_STATE_DMA)
				USB_Config_RxEP_Type(g_UsbMS.rxpipe->byEP, USB_ENDPT_BULK, KAL_FALSE);
			#endif		
			g_UsbMS.max_LUN = USB_Ms_Get_Max_LUN();
			USB_Generate_EP0Data(pep0state, pcmd, (void *)&g_UsbMS.max_LUN, 1);
		}
		break;

	default:
		bError = KAL_TRUE;
		break;
	}

	if(bError == KAL_TRUE)
		drv_trace1(TRACE_FUNC, (kal_uint32)USBMS_ERROR_CMD, (kal_uint32)pcmd->bRequest);

	USB_EP0_Command_Hdlr(bError);
/*
	if(USB_Get_Endpoint0_State() == USB_EP0_IDLE)
	{
		USB_Set_Endpoint0_State(USB_EP0_RX_STATUS);
		USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, bError, KAL_TRUE);
	}
	else
	{
		USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, bError, KAL_FALSE);
	}
*/	
}


/* EP Bulk Out interrupt handler, called by EP interrupt */
static void USB_Ms_BulkOut_Hdlr(void)
{
	kal_uint32 nCount;
//	ilm_struct *usb_ilm = NULL;
	usb_ms_rec_done_conf_struct *rec_done_conf;


	/* Check received packet length */
	nCount = USB_EP_Rx_Pkt_Len(g_UsbMS.rxpipe->byEP);

	if(nCount == 31)
	{
		USB_EPFIFORead(g_UsbMS.rxpipe->byEP, 31, g_UsbMS.CBWdata, KAL_FALSE);

		USB_Dbg_Trace(USB_MS_FIFO_RX_HDLR, 0, 0);

		g_UsbMS.rxpipe->nBytesRecv = 31;
		g_UsbMS.rxpipe->pData = (kal_uint8 *)g_UsbMS.CBWdata;
		g_UsbMS.rxpipe->nBuffLen = 31;

		/* Send message to usb task, let ms state machine handle the received data */
#if 0		
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

//		USB_Send_Msg_Ext_Queue(MOD_USB, MSG_ID_USB_MSDRV_REC_DONE_CONF, rec_done_conf);

//		DRV_BuildPrimitive(usb_ilm, MOD_DRV_HISR,MOD_USB, MSG_ID_USB_MSDRV_REC_DONE_CONF, rec_done_conf);
//		msg_send_ext_queue(usb_ilm);

		/* Switch endpoint state to use DMA */
		/* Change EP state must before clear RxPktRdy.
		Otherwise, if there are packets arriving after clear RxPktRdy and before switch to DMA,
		then endpoint interrupt should be triggered, and result in an unexpected RX intr */
		USB_Config_RxEP_Type(g_UsbMS.rxpipe->byEP, USB_ENDPT_BULK, KAL_TRUE);

		/* Clear RxPktRdy */
		USB_EP_Rx_Ready(g_UsbMS.rxpipe->byEP, USB_ENDPT_BULK);
		if(g_UsbMS.nState == USBMS_IDLE) 
		{
			if((g_UsbMS.usb_reset == KAL_FALSE)&&(g_UsbMS.ms_is_reset == KAL_FALSE))
			{		
				kal_uint8   *CBWCB;
				UsbMs_CBW 	*CBW = (UsbMs_CBW *)((kal_uint8 *)g_UsbMS.CBWdata); 
	
				CBWCB = (kal_uint8*)CBW->CBWCB;			
				switch(CBWCB[0])
				{	
					case USBMS_WRITE10:
					case USBMS_WRITE12:
						USB_Ms_Cmd(g_UsbMS.CBWdata);
						return;
					default:	
						break;						
				}
			}
		}
		rec_done_conf = (usb_ms_rec_done_conf_struct *)construct_local_para(
							sizeof(usb_ms_rec_done_conf_struct), TD_CTRL);
		rec_done_conf->pData = g_UsbMS.rxpipe->pData;
		rec_done_conf->nBuffLen = g_UsbMS.rxpipe->nBuffLen;
		rec_done_conf->nBytesRecv = g_UsbMS.rxpipe->nBytesRecv;
		USB_Send_Msg_Ext_Queue(MOD_USB, MSG_ID_USB_MSDRV_REC_DONE_CONF, rec_done_conf);					
	}
	else
	{
		/* Error handling */
		USB_Dbg_Trace(USB_MS_FIFO_RX_WITH_WRONG_CBW_SIZE, nCount, 0);
		drv_trace1(TRACE_FUNC, (kal_uint32)USBMS_RX_WRONG_CBW_LENGTH, nCount);

		/* Clear RxPktRdy */
//		USB_EP_Rx_Ready(g_UsbMS.rxpipe->byEP, USB_ENDPT_BULK);

		g_UsbMS.cbw_is_vaild = KAL_FALSE;
		USB_CtrlEPStall(g_UsbMS.txpipe->byEP, USB_EP_TX_DIR, KAL_TRUE);
		USB_CtrlEPStall(g_UsbMS.rxpipe->byEP, USB_EP_RX_DIR, KAL_TRUE);
	}
}


/* Bulk In endpoint reset function */
static void USB_Ms_BulkIn_Reset(void)
{
	return;
}


/* Bulk Out endpoint reset function */
static void USB_Ms_BulkOut_Reset(void)
{
	return;
}

#endif //__USB_MASS_STORAGE_ENABLE__


