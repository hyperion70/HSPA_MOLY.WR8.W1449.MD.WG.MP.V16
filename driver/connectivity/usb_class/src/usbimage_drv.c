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
*  A. Patent Notice:
*  The software delivered hereunder, including any and all updates and upgrades,
*  might be subject to patent rights of standard-setting organizations, patent pools
*  or their respective patent owners, that will be necessarily infringed by the use
*  and distribution of the products incorporating all or part of this software.
*  According to the licensing terms of these patent holders, it is your sole
*  obligation to obtain the necessary patent licenses from these patent holders
*  before you can use or distribute the products incorporating all or part of this
*  software. MediaTek shall not be liable for your failure to obtain or maintain such
*  licenses.
*
*    As a courtesy to our customers, the following are some of the software that might
*    contain such patent licenses, but MediaTek does not warrant the accuracy or
*    completeness of the information below.
*    (1) MPEG4/AAC/AACPLUS/AACVPLUSV2: essential patents license must be obtained
*        from Via Licensing: <www.vialicensing.com>
*    (2) WAP/MMS security RC5 algorithm belongs to RSA Data Security:
*        <www.rsasecurity.com>
*    Notice: Please contact RSA to get this license before shipping the products to
*    USA which include RC5 security algorithm.
*
*  B. In addition, customers must contact the respective licensors to obtain
*  necessary software licenses before it can use or distribute the licensed
*  products.
*
*    As a courtesy to our customers, the following are some of the software licensers
*    and the notice or disclaimer required by their licenses, but MediaTek does not
*    warrant the accuracy or completeness of the information below.
*    (1) Microsoft Windows Media (WMA software):
*        Microsoft: <www.microsoft.com>
*        Approved OEM Manufacturers: <wmlicense.smdisp.net/oem_approved/>
*        Sample Windows Media Licensing Agreements:
*        <www.microsoft.com/windows/windowsmedia/licensing/agreements.aspx>
*    Notice in header or documentation: "This product is protected by certain
*    intellectual property rights of Microsoft and cannot be used or further
*    distributed without a license from Microsoft."
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   usbimage_drv.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  This file implements usb IMAGE class driver
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef __USB_IMAGE_CLASS__

#include "drv_comm.h"
//#include "reg_base.h"
#include "intrCtrl.h"
#include "kal_public_defs.h" //MSBB change #include "stack_common.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "kal_public_api.h" //#include "stack_ltlcom.h" //MSBB change #include "app_ltlcom.h"
////#include "app_buff_alloc.h"
#include "usb_comm.h"
#include "drvsignals.h"
//#include "gpt_sw.h"
#include "drm_gprot.h"

//#include "usb_drv.h"
#include "usb_adap.h"
#include "usb.h"
#include "usb_resource.h"

#include "usb_custom.h"
#include "usbimage_drv.h"
#ifdef PICTBRIDGE_SUPPORT
#include "ptp_state.h"
#endif
#ifdef __MTP_ENABLE__
#include "usbimage_mtp_state.h"
#endif
#include "usb_debug_tool.h"
#include "usb_trc.h"

/*This will be removed when change back to media task*/
//#include "custom_config.h"


///#include "kal_release.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "kal_public_api.h" //#include "stack_ltlcom.h"
///#include "fs_func.h"
#include "fs_errcode.h"
#include "kal_trace.h"
#include "kal_general_types.h"
#include "kal_public_api.h"



/* Global variables */
#pragma arm section zidata = "NONCACHEDZI", rwdata = "NONCACHEDRW"
__align(4) USB_IMAGE_CONTAINER g_USB_Image_Response;
#pragma arm section zidata, rwdata

USBImage_Struct g_USBImage;

/* Static variables */
static kal_bool intr_pkt_buf_is_full = KAL_FALSE;
static kal_bool g_intr_pipe_is_running = KAL_FALSE;

/* Static functions */
static void USB_Image_Tx_DMA_Callback(void);
#ifdef PICTBRIDGE_SUPPORT
static void USB_Image_Ep0_Cancel_Hdlr(void *data);
#endif
#ifdef __MTP_ENABLE__
static void USB_MTP_Image_Ep0_Cancel_Hdlr(void *data);
static void USB_Image_Rx_DMA_Callback(void);
#endif
static void USB_Image_Ep0_Command(Usb_Ep0_Status *pep0state, Usb_Command *pcmd);
static void USB_Image_IntrTx_Reset(void);
static void USB_Image_BulkTx_Reset(void);
static void USB_Image_BulkRx_Reset(void);
static void USB_Image_Cmd_Reset(void);
static void USB_Image_IntrTx_Hdlr(void);
#ifdef PICTBRIDGE_SUPPORT
static void USB_Image_BulkRx_Hdr(void );
#endif
#ifdef __MTP_ENABLE__
static void USB_MTP_Image_BulkRx_Hdr(void);
#endif

/************************************************************
	USB Image MTP DCL Interface APIs
*************************************************************/
DCL_STATUS USB_Image_Driver(DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	DCL_STATUS return_status = STATUS_OK;
	
	switch (cmd)
	{
#ifdef __MTP_ENABLE__
		case USB_IMAGE_MTP_CMD_GET_DESCRIPTION_STRING_1_PTR:
			{
				USB_IMAGE_CTRL_FUNC1_T* prImage_Ctrl_Fun1;
				prImage_Ctrl_Fun1 = &(data->rImage_Ctrl_Fun1);			
				prImage_Ctrl_Fun1->u2String = (DCL_UINT16 *)USB_MTP_Image_Get_Storage_Description_String_1_Ptr();
			}
			break;
		
		case USB_IMAGE_MTP_CMD_GET_DESCRIPTION_STRING_2_PTR:
			{
				USB_IMAGE_CTRL_FUNC1_T* prImage_Ctrl_Fun1;
				prImage_Ctrl_Fun1 = &(data->rImage_Ctrl_Fun1);			
				prImage_Ctrl_Fun1->u2String = (DCL_UINT16 *)USB_MTP_Image_Get_Storage_Description_String_2_Ptr();
			}
			break;
#endif /* __MTP_ENABLE__ */						
		default:
			return_status = STATUS_INVALID_CMD;
			break;
	}
	return return_status;
}

/************************************************************
	USB image suspend handler
*************************************************************/
void USB_Image_Suspend_Hdlr(void)
{
#ifdef __MTP_ENABLE__
	if(USB_Get_Device_Type() == USB_IMAGE_MTP)
	{
		/* SessionOpen means PC already set configuration done */
		if(g_USBImage.is_session_open == KAL_TRUE)
		{
			g_USBImage.is_session_open = KAL_FALSE;

			if(g_USBImage.b_wait_req_rsp == KAL_TRUE)
			{
				/* Send abort to MTP */
				USB_MTP_Image_Send_Msg(USB_MTP_IMAGE_MSG_HOST_SUSPEND_IND);
			}
			else
			{
				/* PC suspend and no any MTP command is running */
				USB_Dbg_Trace(USB_MTP_CLOSE_SESSION, 1, 0);
//				g_USBImage.is_session_open = KAL_FALSE;
				g_USBImage.b_is_mtp_abnormal_msg = KAL_FALSE;

				g_USBImage.data_total_size = 0;
				g_USBImage.data_pool_ptr = NULL;
				g_USBImage.data_pool_size = 0;
				g_USBImage.data_size = 0;

				g_USBImage.image_cmd.Code = MTP_CLOSE_SESSION;
				g_USBImage.image_cmd.Parameter1 = 0;
				g_USBImage.image_cmd.Parameter2 = 0;
				g_USBImage.image_cmd.Parameter3 = 0;
				g_USBImage.image_cmd.Parameter4 = 0;
				g_USBImage.image_cmd.Parameter5 = 0;

				/* Send msg to MTP */
				USB_MTP_Image_Send_Msg(USB_MTP_IMAGE_MSG_OPERATION_REQ);

				g_USBImage.b_host_suspend = KAL_TRUE;
			}
		}
	}
#endif

	g_USBImage.is_suspend_state = KAL_TRUE;
}


/************************************************************
	Utility functions
*************************************************************/
void USB_Image_Copy_Unicode_String(kal_uint8 *pdest, const kal_uint16 *source_string, kal_uint8 string_num)
{
//	kal_uint8 *index;
//	kal_uint32 count;


	*pdest = string_num;
	kal_mem_cpy(pdest+1, (kal_uint8*)source_string, 2*string_num);


/*
	index = (kal_uint8 *)pdest + 1;

	for(count = 0; count < string_num; count++)
	{
		kal_mem_cpy(index, (kal_uint8*)&source_string[count] , 2);
		index += 2;
	}
*/
}

/************************************************************
	Interface initialization functions
*************************************************************/
/* interface create function, prepare descriptor */
void USB_Image_If_Create(void *ifname)
{
	kal_uint8		ep_tx_id;
	kal_uint8		ep_rx_id;
	kal_uint8		ep_intr_id;
	kal_uint8		if_id;
	kal_uint32	index;
#ifdef PICTBRIDGE_SUPPORT
	static const kal_uint8 PTP_COMPATIBLE_ID[] = {0x50, 0x54, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00};
#endif
#ifdef __MTP_ENABLE__
	static const kal_uint8 MTP_COMPATIBLE_ID[] = {0x4D, 0x54, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00};
	static const kal_uint16 MTP_EXTENSION_STRING[] = {'m', 'i', 'c', 'r', 'o', 's', 'o', 'f', 't', '.', 'c', 'o', 'm', '/', 'W', 'M', 'D', 'R', 'M', 'P', 'D', ':', ' ', '1', '0', '.', '1', ';', '\0'};
#endif

	/* Get resource number and register to gUsbDevice */
	g_USBImage.image_if_info = USB_Get_Interface_Number(&if_id);
	g_USBImage.image_ep_in_info = USB_Get_Bulk_Tx_Ep(&ep_tx_id);
	g_USBImage.image_ep_out_info = USB_Get_Bulk_Rx_Ep(&ep_rx_id);
	g_USBImage.image_ep_intr_info = USB_Get_Intr_Ep(&ep_intr_id);

	/* record interface name and interface descriptor length */
	g_USBImage.image_if_info->interface_name_ptr = (kal_char *)ifname;
	g_USBImage.image_if_info->ifdscr_size = USB_IFDSC_LENGTH;
	g_USBImage.image_ep_in_info->epdscr_size = USB_EPDSC_LENGTH;
	g_USBImage.image_ep_out_info->epdscr_size = USB_EPDSC_LENGTH;
	g_USBImage.image_ep_intr_info->epdscr_size = USB_EPDSC_LENGTH;

	/* related endpoint info and class specific command handler */
	g_USBImage.image_if_info->ep_info[0] = (Usb_Ep_Info*)g_USBImage.image_ep_in_info;
	g_USBImage.image_if_info->ep_info[1] = (Usb_Ep_Info*)g_USBImage.image_ep_out_info;
	g_USBImage.image_if_info->ep_info[2] = (Usb_Ep_Info*)g_USBImage.image_ep_intr_info;
	g_USBImage.image_if_info->if_class_specific_hdlr = USB_Image_Ep0_Command;

	/* standard interface descriptor */
	g_USBImage.image_if_info->ifdscr.stdif.bLength = USB_IFDSC_LENGTH;
	g_USBImage.image_if_info->ifdscr.stdif.bDescriptorType = USB_INTERFACE;
	g_USBImage.image_if_info->ifdscr.stdif.bInterfaceNumber = if_id;
	g_USBImage.image_if_info->ifdscr.stdif.bAlternateSetting = 0;
	g_USBImage.image_if_info->ifdscr.stdif.bNumEndpoints = USB_IMAGE_EP_NUMBER;
	g_USBImage.image_if_info->ifdscr.stdif.bInterfaceClass = USB_IMAGE_INTERFACE_CLASS_CODE;
	g_USBImage.image_if_info->ifdscr.stdif.bInterfaceSubClass = USB_IMAGE_INTERFACE_SUBCLASS_CODE;
	g_USBImage.image_if_info->ifdscr.stdif.bInterfaceProtocol = USB_IMAGE_INTERFACE_PROTOCOL_CODE;

	/* OS feature descriptors */
	kal_mem_set(&gUsbDevice.os_feature_desc, 0x00, sizeof(Usb_Ext_Compat_ID_OS_Feature_Dscr));

	gUsbDevice.os_feature_desc.dwLength = USB_MAX_OS_FEATURE_DESC_LENGTH;
	gUsbDevice.os_feature_desc.bcdVersion = 0x0100;
	gUsbDevice.os_feature_desc.wIndex = USB_FTR_EXT_COMPAT_ID;
	gUsbDevice.os_feature_desc.bCount = 0x01;
	gUsbDevice.os_feature_desc.bFirstInterfaceNumber = if_id;
	gUsbDevice.os_feature_desc.bPads_2 = 0x01;

#ifdef PICTBRIDGE_SUPPORT
	if(USB_Get_Device_Type() == USB_IMAGE)
	{
		for(index = 0; index < 8; index++)
		{
			gUsbDevice.os_feature_desc.compatibleID[index] = PTP_COMPATIBLE_ID[index];
		}

		g_USBImage.image_if_info->ifdscr.stdif.iInterface = USB_Get_String_Number((void *)g_USBImage.image_param->image_interface_string);
	}
#endif

#ifdef __MTP_ENABLE__
	if(USB_Get_Device_Type() == USB_IMAGE_MTP)
	{
		for(index = 0; index < 8; index++)
		{
			gUsbDevice.os_feature_desc.compatibleID[index] = MTP_COMPATIBLE_ID[index];
		}
		g_USBImage.image_if_info->ifdscr.stdif.iInterface = USB_Get_String_Number((void *)g_USBImage.mtp_image_param->image_interface_string);
	}
#endif

	/* Endpoint handler */
	g_USBImage.image_ep_in_info->ep_reset = USB_Image_BulkTx_Reset;
	USB_Register_Drv_Info(USB_DRV_HDLR_EP_TX, ep_tx_id, NULL);

	g_USBImage.image_ep_out_info->ep_reset = USB_Image_BulkRx_Reset;
#ifdef PICTBRIDGE_SUPPORT
	if(USB_Get_Device_Type() == USB_IMAGE)
	USB_Register_Drv_Info(USB_DRV_HDLR_EP_RX, ep_rx_id, USB_Image_BulkRx_Hdr);
#endif
#ifdef __MTP_ENABLE__
	if(USB_Get_Device_Type() == USB_IMAGE_MTP)
		USB_Register_Drv_Info(USB_DRV_HDLR_EP_RX, ep_rx_id, USB_MTP_Image_BulkRx_Hdr);
#endif

	g_USBImage.image_ep_intr_info->ep_reset = USB_Image_IntrTx_Reset;
	USB_Register_Drv_Info(USB_DRV_HDLR_EP_TX, ep_intr_id, USB_Image_IntrTx_Hdlr);

	/* Endpoint descriptor */
	g_USBImage.image_ep_in_info->epdesc.stdep.bLength = USB_EPDSC_LENGTH;
	g_USBImage.image_ep_in_info->epdesc.stdep.bDescriptorType = USB_ENDPOINT;
	g_USBImage.image_ep_in_info->epdesc.stdep.bEndpointAddress = (USB_EP_DIR_IN|ep_tx_id);
	g_USBImage.image_ep_in_info->epdesc.stdep.bmAttributes = USB_EP_BULK;
#ifndef __USB_HS_ENABLE__
	g_USBImage.image_ep_in_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_BULK_MAXP&0xff;
//	g_USBImage.image_ep_in_info->epdesc.stdep.wMaxPacketSize[1] = (USB_EP_BULK_MAXP>>8)&0xff;
	g_USBImage.image_ep_in_info->epdesc.stdep.wMaxPacketSize[1] = 0x00;
#endif
	g_USBImage.image_ep_in_info->epdesc.stdep.bInterval = 0;
	g_USBImage.image_ep_in_info->ep_status.epin_status.byEP = ep_tx_id;
	g_USBImage.image_ep_in_info->ep_status.epin_status.nBytesLeft = USB_EP_NODATA;

	g_USBImage.image_ep_out_info->epdesc.stdep.bLength = USB_EPDSC_LENGTH;
	g_USBImage.image_ep_out_info->epdesc.stdep.bDescriptorType = USB_ENDPOINT;
	g_USBImage.image_ep_out_info->epdesc.stdep.bEndpointAddress = (USB_EP_DIR_OUT|ep_rx_id);
	g_USBImage.image_ep_out_info->epdesc.stdep.bmAttributes = USB_EP_BULK;
#ifndef __USB_HS_ENABLE__
	g_USBImage.image_ep_out_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_BULK_MAXP&0xff;
//	g_USBImage.image_ep_out_info->epdesc.stdep.wMaxPacketSize[1] = (USB_EP_BULK_MAXP>>8)&0xff;
	g_USBImage.image_ep_out_info->epdesc.stdep.wMaxPacketSize[1] = 0x00;
#endif
	g_USBImage.image_ep_out_info->epdesc.stdep.bInterval = 0;
	g_USBImage.image_ep_out_info->ep_status.epout_status.byEP = ep_rx_id;

	g_USBImage.image_ep_intr_info->epdesc.stdep.bLength = USB_EPDSC_LENGTH;
	g_USBImage.image_ep_intr_info->epdesc.stdep.bDescriptorType = USB_ENDPOINT;
	g_USBImage.image_ep_intr_info->epdesc.stdep.bEndpointAddress = (USB_EP_DIR_IN | ep_intr_id);
	g_USBImage.image_ep_intr_info->epdesc.stdep.bmAttributes = USB_EP_INTR;
#ifndef __USB_HS_ENABLE__
	g_USBImage.image_ep_intr_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_INTR_MAXP&0xff;
//	g_USBImage.image_ep_intr_info->epdesc.stdep.wMaxPacketSize[1] = (USB_EP_INTR_MAXP>>8)&0xff;
	g_USBImage.image_ep_intr_info->epdesc.stdep.wMaxPacketSize[1] = 0x00;
#endif
	g_USBImage.image_ep_intr_info->epdesc.stdep.bInterval = 16;
	g_USBImage.image_ep_intr_info->ep_status.epin_status.byEP = ep_intr_id;
	g_USBImage.image_ep_intr_info->ep_status.epin_status.nBytesLeft = USB_EP_NODATA;

#ifdef PICTBRIDGE_SUPPORT
	if(USB_Get_Device_Type() == USB_IMAGE)
	{
		USB_Get_DMA_Channel(ep_tx_id, 0, USB_EP_TX_DIR, KAL_FALSE);

		/* Prepare the DeviceInfo Dataset */
		g_PTPImage.image_deviceinfo.StandardVersion = 100;
		g_PTPImage.image_deviceinfo.VenderExtensionID[0] = 0;
		g_PTPImage.image_deviceinfo.VenderExtensionID[1] = 0;
		g_PTPImage.image_deviceinfo.VenderExtensionVersion = 0;
		g_PTPImage.image_deviceinfo.VendorExtensionDesc = 0x00;	/* empty string */
		g_PTPImage.image_deviceinfo.FunctionalMode[0] = PTP_STANDARD_MODE&0xff;
//		g_PTPImage.image_deviceinfo.FunctionalMode[1] = (PTP_STANDARD_MODE>>8)&0xff;
		g_PTPImage.image_deviceinfo.FunctionalMode[1] = 0x00;

		g_PTPImage.image_deviceinfo.OperationsSupportedSize[0] = PTP_MAX_OPERATION_CODE_SIZE&0xff;
//		g_PTPImage.image_deviceinfo.OperationsSupportedSize[1] = (PTP_MAX_OPERATION_CODE_SIZE>>8)&0xff;
//		g_PTPImage.image_deviceinfo.OperationsSupportedSize[2] = (PTP_MAX_OPERATION_CODE_SIZE>>16)&0xff;
//		g_PTPImage.image_deviceinfo.OperationsSupportedSize[3] = (PTP_MAX_OPERATION_CODE_SIZE>>24)&0xff;
		g_PTPImage.image_deviceinfo.OperationsSupportedSize[1] = 0x00;
		g_PTPImage.image_deviceinfo.OperationsSupportedSize[2] = 0x00;
		g_PTPImage.image_deviceinfo.OperationsSupportedSize[3] = 0x00;

		g_PTPImage.image_deviceinfo.OperationsSupported[0][0] = PTP_GET_DEVICE_INFO&0xff;
		g_PTPImage.image_deviceinfo.OperationsSupported[0][1] = (PTP_GET_DEVICE_INFO>>8)&0xff;
		g_PTPImage.image_deviceinfo.OperationsSupported[1][0] = PTP_OPEN_SESSION&0xff;
		g_PTPImage.image_deviceinfo.OperationsSupported[1][1] = (PTP_OPEN_SESSION>>8)&0xff;
		g_PTPImage.image_deviceinfo.OperationsSupported[2][0] = PTP_CLOSE_SESSION&0xff;
		g_PTPImage.image_deviceinfo.OperationsSupported[2][1] = (PTP_CLOSE_SESSION>>8)&0xff;
		g_PTPImage.image_deviceinfo.OperationsSupported[3][0] = PTP_GET_STORAGE_IDS&0xff;
		g_PTPImage.image_deviceinfo.OperationsSupported[3][1] = (PTP_GET_STORAGE_IDS>>8)&0xff;
		g_PTPImage.image_deviceinfo.OperationsSupported[4][0] = PTP_GET_STORAGE_INFO&0xff;
		g_PTPImage.image_deviceinfo.OperationsSupported[4][1] = (PTP_GET_STORAGE_INFO>>8)&0xff;
		g_PTPImage.image_deviceinfo.OperationsSupported[5][0] = PTP_GET_NUM_OBJECTS&0xff;
		g_PTPImage.image_deviceinfo.OperationsSupported[5][1] = (PTP_GET_NUM_OBJECTS>>8)&0xff;
		g_PTPImage.image_deviceinfo.OperationsSupported[6][0] = PTP_GET_OBJECT_HANDLES&0xff;
		g_PTPImage.image_deviceinfo.OperationsSupported[6][1] = (PTP_GET_OBJECT_HANDLES>>8)&0xff;
		g_PTPImage.image_deviceinfo.OperationsSupported[7][0] = PTP_GET_OBJECT_INFO&0xff;
		g_PTPImage.image_deviceinfo.OperationsSupported[7][1] = (PTP_GET_OBJECT_INFO>>8)&0xff;
		g_PTPImage.image_deviceinfo.OperationsSupported[8][0] = PTP_GET_OBJECT&0xff;
		g_PTPImage.image_deviceinfo.OperationsSupported[8][1] = (PTP_GET_OBJECT>>8)&0xff;
		g_PTPImage.image_deviceinfo.OperationsSupported[9][0] = PTP_GET_THUMB&0xff;
		g_PTPImage.image_deviceinfo.OperationsSupported[9][1] = (PTP_GET_THUMB>>8)&0xff;
		g_PTPImage.image_deviceinfo.OperationsSupported[10][0] = PTP_SEND_OBJECT_INFO&0xff;
		g_PTPImage.image_deviceinfo.OperationsSupported[10][1] = (PTP_SEND_OBJECT_INFO>>8)&0xff;
		g_PTPImage.image_deviceinfo.OperationsSupported[11][0] = PTP_SEND_OBJECT&0xff;
		g_PTPImage.image_deviceinfo.OperationsSupported[11][1] = (PTP_SEND_OBJECT>>8)&0xff;
		g_PTPImage.image_deviceinfo.OperationsSupported[12][0] = PTP_GET_PARTIAL_OBJECT&0xff;
		g_PTPImage.image_deviceinfo.OperationsSupported[12][1] = (PTP_GET_PARTIAL_OBJECT>>8)&0xff;

		g_PTPImage.image_deviceinfo.EventsSupportedSize[0] = PTP_MAX_EVENT_CODE_SIZE&0xff;
//		g_PTPImage.image_deviceinfo.EventsSupportedSize[1] = (PTP_MAX_EVENT_CODE_SIZE>>8)&0xff;
//		g_PTPImage.image_deviceinfo.EventsSupportedSize[2] = (PTP_MAX_EVENT_CODE_SIZE>>16)&0xff;
//		g_PTPImage.image_deviceinfo.EventsSupportedSize[3] = (PTP_MAX_EVENT_CODE_SIZE>>24)&0xff;
		g_PTPImage.image_deviceinfo.EventsSupportedSize[1] = 0x00;
		g_PTPImage.image_deviceinfo.EventsSupportedSize[2] = 0x00;
		g_PTPImage.image_deviceinfo.EventsSupportedSize[3] = 0x00;

		g_PTPImage.image_deviceinfo.EventsSupported[0][0] = PTP_CANCEL_TRANSACTION&0xff;
		g_PTPImage.image_deviceinfo.EventsSupported[0][1] = (PTP_CANCEL_TRANSACTION>>8)&0xff;
		g_PTPImage.image_deviceinfo.EventsSupported[1][0] = PTP_STORE_ADDED&0xff;
		g_PTPImage.image_deviceinfo.EventsSupported[1][1] = (PTP_STORE_ADDED>>8)&0xff;
		g_PTPImage.image_deviceinfo.EventsSupported[2][0] = PTP_STORE_REMOVED&0xff;
		g_PTPImage.image_deviceinfo.EventsSupported[2][1] = (PTP_STORE_REMOVED>>8)&0xff;
		g_PTPImage.image_deviceinfo.EventsSupported[3][0] = PTP_OBJECT_ADDED&0xff;
		g_PTPImage.image_deviceinfo.EventsSupported[3][1] = (PTP_OBJECT_ADDED>>8)&0xff;
		g_PTPImage.image_deviceinfo.EventsSupported[4][0] = PTP_OBJECT_REMOVED&0xff;
		g_PTPImage.image_deviceinfo.EventsSupported[4][1] = (PTP_OBJECT_REMOVED>>8)&0xff;
		g_PTPImage.image_deviceinfo.EventsSupported[5][0] = PTP_OBJECT_INFO_CHAGNED&0xff;
		g_PTPImage.image_deviceinfo.EventsSupported[5][1] = (PTP_OBJECT_INFO_CHAGNED>>8)&0xff;
		g_PTPImage.image_deviceinfo.EventsSupported[6][0] = PTP_REQUEST_OBJECT_TRANSFER&0xff;
		g_PTPImage.image_deviceinfo.EventsSupported[6][1] = (PTP_REQUEST_OBJECT_TRANSFER>>8)&0xff;

		g_PTPImage.image_deviceinfo.DevicePropertiesSupportedSize[0] = 0;		/* empty array */
		g_PTPImage.image_deviceinfo.DevicePropertiesSupportedSize[1] = 0;
		g_PTPImage.image_deviceinfo.DevicePropertiesSupportedSize[2] = 0;
		g_PTPImage.image_deviceinfo.DevicePropertiesSupportedSize[3] = 0;
		g_PTPImage.image_deviceinfo.CaptureFormatsSize[0] = 0;				/* empty array */
		g_PTPImage.image_deviceinfo.CaptureFormatsSize[1] = 0;
		g_PTPImage.image_deviceinfo.CaptureFormatsSize[2] = 0;
		g_PTPImage.image_deviceinfo.CaptureFormatsSize[3] = 0;
		g_PTPImage.image_deviceinfo.ImageFormatsSize[0] = PTP_MAX_OBJECT_FORMAT_CODE_SIZE&0xff;
//		g_PTPImage.image_deviceinfo.ImageFormatsSize[1] = (PTP_MAX_OBJECT_FORMAT_CODE_SIZE>>8)&0xff;
//		g_PTPImage.image_deviceinfo.ImageFormatsSize[2] = (PTP_MAX_OBJECT_FORMAT_CODE_SIZE>>16)&0xff;
//		g_PTPImage.image_deviceinfo.ImageFormatsSize[3] = (PTP_MAX_OBJECT_FORMAT_CODE_SIZE>>24)&0xff;
		g_PTPImage.image_deviceinfo.ImageFormatsSize[1] = 0x00;
		g_PTPImage.image_deviceinfo.ImageFormatsSize[2] = 0x00;
		g_PTPImage.image_deviceinfo.ImageFormatsSize[3] = 0x00;

		g_PTPImage.image_deviceinfo.ImageFormats[0][0] = PTP_EXIF_JPEG&0xff;
		g_PTPImage.image_deviceinfo.ImageFormats[0][1] = (PTP_EXIF_JPEG>>8)&0xff;
		g_PTPImage.image_deviceinfo.ImageFormats[1][0] = PTP_SCRIPT&0xff;
		g_PTPImage.image_deviceinfo.ImageFormats[1][1] = (PTP_SCRIPT>>8)&0xff;
//		g_PTPImage.image_deviceinfo.ImageFormats[2][0] = PTP_TIFF_EP&0xff;
//		g_PTPImage.image_deviceinfo.ImageFormats[2][1] = (PTP_TIFF_EP>>8)&0xff;

		/* Prepare the StorageInfo Dataset */
		g_PTPImage.image_storageinfo.StorageType = PTP_FIXED_RAM;
		g_PTPImage.image_storageinfo.FilesystemType = PTP_GENERIC_FLAT;
		g_PTPImage.image_storageinfo.AccessCapability = PTP_READ_WRITE;
//		g_PTPImage.image_storageinfo.FreeSpaceInImages[0] = 0x0034;
//		g_PTPImage.image_storageinfo.FreeSpaceInImages[1] = 0x0000;
		g_PTPImage.image_storageinfo.FreeSpaceInImages[0] = 0xffff;
		g_PTPImage.image_storageinfo.FreeSpaceInImages[1] = 0xffff;

		/* Prepare the ObjectInfo Dataset */
		g_PTPImage.image_objectinfo.ProtectionStatus = PTP_NO_PROTECTION;
		g_PTPImage.image_objectinfo.ImageBitDepth[0] = 0;			/* no use */
		g_PTPImage.image_objectinfo.ImageBitDepth[1]= 0;
		g_PTPImage.image_objectinfo.ParentObject[0] = 0;
		g_PTPImage.image_objectinfo.ParentObject[1] = 0;
		g_PTPImage.image_objectinfo.AssociationType = 0;			/* no use */
		g_PTPImage.image_objectinfo.AssociationDesc = 0;			/* no use */
		g_PTPImage.image_objectinfo.SequenceNumber = 0;			/* no use */
	}
#endif

#ifdef __MTP_ENABLE__
	if(USB_Get_Device_Type() == USB_IMAGE_MTP)
	{
		USB_Get_DMA_Channel(ep_tx_id, ep_rx_id, USB_EP_TX_DIR, KAL_TRUE);

		/* Prepare the DeviceInfo Dataset */
		g_MTPImage.image_deviceinfo.StandardVersion = 100;

		g_MTPImage.image_deviceinfo.VenderExtensionID[0] = MTP_VENDER_EXTENSION_ID_093&0xffff;
//		g_MTPImage.image_deviceinfo.VenderExtensionID[1] = (MTP_VENDER_EXTENSION_ID_093>>16)&0xffff;
//		g_MTPImage.image_deviceinfo.VenderExtensionID[0] = MTP_VENDER_EXTENSION_ID_10&0xffff;
//		g_MTPImage.image_deviceinfo.VenderExtensionID[1] = (MTP_VENDER_EXTENSION_ID_10>>16)&0xffff;

		g_MTPImage.image_deviceinfo.VenderExtensionVersion = 100;
		USB_Image_Copy_Unicode_String(&g_MTPImage.image_deviceinfo.VendorExtensionDescNum, MTP_EXTENSION_STRING, 29);

		g_MTPImage.image_deviceinfo.FunctionalMode[0] = MTP_STANDARD_MODE&0xff;
//		g_MTPImage.image_deviceinfo.FunctionalMode[1] = (MTP_STANDARD_MODE>>8)&0xff;
		g_MTPImage.image_deviceinfo.FunctionalMode[1] = 0x00;

		g_MTPImage.image_deviceinfo.OperationsSupportedSize[0] = MTP_MAX_OPERATION_CODE_SIZE&0xff;
//		g_MTPImage.image_deviceinfo.OperationsSupportedSize[1] = (MTP_MAX_OPERATION_CODE_SIZE>>8)&0xff;
//		g_MTPImage.image_deviceinfo.OperationsSupportedSize[2] = (MTP_MAX_OPERATION_CODE_SIZE>>16)&0xff;
//		g_MTPImage.image_deviceinfo.OperationsSupportedSize[3] = (MTP_MAX_OPERATION_CODE_SIZE>>24)&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupportedSize[1] = 0x00;
		g_MTPImage.image_deviceinfo.OperationsSupportedSize[2] = 0x00;
		g_MTPImage.image_deviceinfo.OperationsSupportedSize[3] = 0x00;

		g_MTPImage.image_deviceinfo.OperationsSupported[0][0] = MTP_GET_DEVICE_INFO&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[0][1] = (MTP_GET_DEVICE_INFO>>8)&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[1][0] = MTP_OPEN_SESSION&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[1][1] = (MTP_OPEN_SESSION>>8)&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[2][0] = MTP_CLOSE_SESSION&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[2][1] = (MTP_CLOSE_SESSION>>8)&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[3][0] = MTP_GET_STORAGE_IDS&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[3][1] = (MTP_GET_STORAGE_IDS>>8)&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[4][0] = MTP_GET_STORAGE_INFO&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[4][1] = (MTP_GET_STORAGE_INFO>>8)&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[5][0] = MTP_GET_NUM_OBJECTS&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[5][1] = (MTP_GET_NUM_OBJECTS>>8)&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[6][0] = MTP_GET_OBJECT_HANDLES&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[6][1] = (MTP_GET_OBJECT_HANDLES>>8)&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[7][0] = MTP_GET_OBJECT_INFO&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[7][1] = (MTP_GET_OBJECT_INFO>>8)&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[8][0] = MTP_GET_OBJECT&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[8][1] = (MTP_GET_OBJECT>>8)&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[9][0] = MTP_DELETE_OBJECT&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[9][1] = (MTP_DELETE_OBJECT>>8)&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[10][0] = MTP_SEND_OBJECT_INFO&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[10][1] = (MTP_SEND_OBJECT_INFO>>8)&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[11][0] = MTP_SEND_OBJECT&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[11][1] = (MTP_SEND_OBJECT>>8)&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[12][0] = MTP_GET_DEVICE_PROP_DESC&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[12][1] = (MTP_GET_DEVICE_PROP_DESC>>8)&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[13][0] = MTP_GET_DEVICE_PROP_VALUE&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[13][1] = (MTP_GET_DEVICE_PROP_VALUE>>8)&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[14][0] = MTP_SET_DEVICE_PROP_VALUE&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[14][1] = (MTP_SET_DEVICE_PROP_VALUE>>8)&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[15][0] = MTP_GET_PARTIAL_OBJECT&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[15][1] = (MTP_GET_PARTIAL_OBJECT>>8)&0xff;

		g_MTPImage.image_deviceinfo.OperationsSupported[16][0] = MTP_GET_OBJECT_PROPS_SUPPORTED&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[16][1] = (MTP_GET_OBJECT_PROPS_SUPPORTED>>8)&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[17][0] = MTP_GET_OBJECT_PROP_DESC&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[17][1] = (MTP_GET_OBJECT_PROP_DESC>>8)&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[18][0] = MTP_GET_OBJECT_PROP_VALUE&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[18][1] = (MTP_GET_OBJECT_PROP_VALUE>>8)&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[19][0] = MTP_SET_OBJECT_PROP_VALUE&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[19][1] = (MTP_SET_OBJECT_PROP_VALUE>>8)&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[20][0] = MTP_GET_OBJECT_PROP_LIST&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[20][1] = (MTP_GET_OBJECT_PROP_LIST>>8)&0xff;

/*
		g_MTPImage.image_deviceinfo.OperationsSupported[20][0] = MTP_GET_OBJECT_REFERENCES&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[20][1] = (MTP_GET_OBJECT_REFERENCES>>8)&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[21][0] = MTP_SET_OBJECT_REFERENCES&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[21][1] = (MTP_SET_OBJECT_REFERENCES>>8)&0xff;

		g_MTPImage.image_deviceinfo.OperationsSupported[22][0] = MTP_SET_OBJECT_PROTECTION&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[22][1] = (MTP_SET_OBJECT_PROTECTION>>8)&0xff;

		g_MTPImage.image_deviceinfo.OperationsSupported[23][0] = MTP_RESET_DEVICE_PROP_VALUE&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[23][1] = (MTP_RESET_DEVICE_PROP_VALUE>>8)&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[24][0] = MTP_GET_OBJECT_PROP_LIST&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[24][1] = (MTP_GET_OBJECT_PROP_LIST>>8)&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[25][0] = MTP_SET_OBJECT_PROP_LIST&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[25][1] = (MTP_SET_OBJECT_PROP_LIST>>8)&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[26][0] = MTP_SEND_OBJECT_PROP_LIST&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[26][1] = (MTP_SEND_OBJECT_PROP_LIST>>8)&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[27][0] = MTP_GET_SECURE_TIME_CHALLENGE&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[27][1] = (MTP_GET_SECURE_TIME_CHALLENGE>>8)&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[28][0] = MTP_SET_SECURE_TIME_RESPONSE&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[28][1] = (MTP_SET_SECURE_TIME_RESPONSE>>8)&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[29][0] = MTP_SET_LICENSE_RESPONSE&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[29][1] = (MTP_SET_LICENSE_RESPONSE>>8)&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[30][0] = MTP_GET_SYNC_LIST&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[30][1] = (MTP_GET_SYNC_LIST>>8)&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[31][0] = MTP_SEND_METER_CHALLENGE_QUERY&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[31][1] = (MTP_SEND_METER_CHALLENGE_QUERY>>8)&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[32][0] = MTP_GET_METER_CHALLENGE&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[32][1] = (MTP_GET_METER_CHALLENGE>>8)&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[33][0] =  MTP_SET_METER_RESPONSE&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[33][1] = ( MTP_SET_METER_RESPONSE>>8)&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[34][0] = MTP_CLEAN_DATA_STORE&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[34][1] = (MTP_CLEAN_DATA_STORE>>8)&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[35][0] = MTP_GET_LICENSE_STATE&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[35][1] = (MTP_GET_LICENSE_STATE>>8)&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[36][0] = MTP_DRM_CMD_1&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[36][1] = (MTP_DRM_CMD_1>>8)&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[37][0] = MTP_DRM_CMD_2&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[37][1] = (MTP_DRM_CMD_2>>8)&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[38][0] = MTP_DRM_CMD_3&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[38][1] = (MTP_DRM_CMD_3>>8)&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[39][0] = MTP_DRM_CMD_4&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[39][1] = (MTP_DRM_CMD_4>>8)&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[40][0] = MTP_FORMAT_STORE&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[40][1] = (MTP_FORMAT_STORE>>8)&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[41][0] = MTP_RESET_DEVICE&0xff;
		g_MTPImage.image_deviceinfo.OperationsSupported[41][1] = (MTP_RESET_DEVICE>>8)&0xff;
*/

		g_MTPImage.image_deviceinfo.EventsSupportedSize[0] = MTP_MAX_EVENT_CODE_SIZE&0xff;
//		g_MTPImage.image_deviceinfo.EventsSupportedSize[1] = (MTP_MAX_EVENT_CODE_SIZE>>8)&0xff;
//		g_MTPImage.image_deviceinfo.EventsSupportedSize[2] = (MTP_MAX_EVENT_CODE_SIZE>>16)&0xff;
//		g_MTPImage.image_deviceinfo.EventsSupportedSize[3] = (MTP_MAX_EVENT_CODE_SIZE>>24)&0xff;
		g_MTPImage.image_deviceinfo.EventsSupportedSize[1] = 0x00;
		g_MTPImage.image_deviceinfo.EventsSupportedSize[2] = 0x00;
		g_MTPImage.image_deviceinfo.EventsSupportedSize[3] = 0x00;

		g_MTPImage.image_deviceinfo.EventsSupported[0][0] = MTP_CANCEL_TRANSACTION&0xff;
		g_MTPImage.image_deviceinfo.EventsSupported[0][1] = (MTP_CANCEL_TRANSACTION>>8)&0xff;
		g_MTPImage.image_deviceinfo.EventsSupported[1][0] = MTP_STORE_ADDED&0xff;
		g_MTPImage.image_deviceinfo.EventsSupported[1][1] = (MTP_STORE_ADDED>>8)&0xff;
		g_MTPImage.image_deviceinfo.EventsSupported[2][0] = MTP_STORE_REMOVED&0xff;
		g_MTPImage.image_deviceinfo.EventsSupported[2][1] = (MTP_STORE_REMOVED>>8)&0xff;
		g_MTPImage.image_deviceinfo.EventsSupported[3][0] = MTP_DEVICE_RESET&0xff;
		g_MTPImage.image_deviceinfo.EventsSupported[3][1] = (MTP_DEVICE_RESET>>8)&0xff;

		g_MTPImage.image_deviceinfo.DevicePropertiesSupportedSize[0] = MTP_MAX_DEVICE_PROPERTIES_SUPPORTED_SIZE&0xff;
//		g_MTPImage.image_deviceinfo.DevicePropertiesSupportedSize[1] = (MTP_MAX_DEVICE_PROPERTIES_SUPPORTED_SIZE>>8)&0xff;
//		g_MTPImage.image_deviceinfo.DevicePropertiesSupportedSize[2] = (MTP_MAX_DEVICE_PROPERTIES_SUPPORTED_SIZE>>16)&0xff;
//		g_MTPImage.image_deviceinfo.DevicePropertiesSupportedSize[3] = (MTP_MAX_DEVICE_PROPERTIES_SUPPORTED_SIZE>>24)&0xff;
		g_MTPImage.image_deviceinfo.DevicePropertiesSupportedSize[1] = 0;
		g_MTPImage.image_deviceinfo.DevicePropertiesSupportedSize[2] = 0;
		g_MTPImage.image_deviceinfo.DevicePropertiesSupportedSize[3] = 0;

		g_MTPImage.image_deviceinfo.DevicePropertiesSupported[0][0] = MTP_SYNCHRONIZATION_PARTNER&0xff;
		g_MTPImage.image_deviceinfo.DevicePropertiesSupported[0][1] = (MTP_SYNCHRONIZATION_PARTNER>>8)&0xff;
		g_MTPImage.image_deviceinfo.DevicePropertiesSupported[1][0] = MTP_DEVICE_FRIENDLY_NAME&0xff;
		g_MTPImage.image_deviceinfo.DevicePropertiesSupported[1][1] = (MTP_DEVICE_FRIENDLY_NAME>>8)&0xff;
/*
//		g_MTPImage.image_deviceinfo.DevicePropertiesSupported[2][0] = MTP_DATE_TIME&0xff;
//		g_MTPImage.image_deviceinfo.DevicePropertiesSupported[2][1] = (MTP_DATE_TIME>>8)&0xff;
		g_MTPImage.image_deviceinfo.DevicePropertiesSupported[2][0] = MTP_DEVICELCON&0xff;
		g_MTPImage.image_deviceinfo.DevicePropertiesSupported[2][1] = (MTP_DEVICELCON>>8)&0xff;
		g_MTPImage.image_deviceinfo.DevicePropertiesSupported[3][0] = MTP_SECURE_TIME&0xff;
		g_MTPImage.image_deviceinfo.DevicePropertiesSupported[3][1] = (MTP_SECURE_TIME>>8)&0xff;
		g_MTPImage.image_deviceinfo.DevicePropertiesSupported[4][0] = MTP_DEVICE_CERIFICATE&0xff;
		g_MTPImage.image_deviceinfo.DevicePropertiesSupported[4][1] = (MTP_DEVICE_CERIFICATE>>8)&0xff;
*/
		g_MTPImage.image_deviceinfo.CaptureFormatsSize[0] = 0;				/* Empty array */
		g_MTPImage.image_deviceinfo.CaptureFormatsSize[1] = 0;
		g_MTPImage.image_deviceinfo.CaptureFormatsSize[2] = 0;
		g_MTPImage.image_deviceinfo.CaptureFormatsSize[3] = 0;

		g_MTPImage.image_deviceinfo.PlaybackFormatsSize[0] = MTP_MAX_PLAYBACK_FORMAT_CODE_SIZE&0xff;
//		g_MTPImage.image_deviceinfo.PlaybackFormatsSize[1] = (MTP_MAX_PLAYBACK_FORMAT_CODE_SIZE>>8)&0xff;
//		g_MTPImage.image_deviceinfo.PlaybackFormatsSize[2] = (MTP_MAX_PLAYBACK_FORMAT_CODE_SIZE>>16)&0xff;
//		g_MTPImage.image_deviceinfo.PlaybackFormatsSize[3] = (MTP_MAX_PLAYBACK_FORMAT_CODE_SIZE>>24)&0xff;
		g_MTPImage.image_deviceinfo.PlaybackFormatsSize[1] = 0x00;
		g_MTPImage.image_deviceinfo.PlaybackFormatsSize[2] = 0x00;
		g_MTPImage.image_deviceinfo.PlaybackFormatsSize[3] = 0x00;

		g_MTPImage.image_deviceinfo.PlaybackFormats[0][0] = MTP_UNDEFINED&0xff;
		g_MTPImage.image_deviceinfo.PlaybackFormats[0][1] = (MTP_UNDEFINED>>8)&0xff;
		g_MTPImage.image_deviceinfo.PlaybackFormats[1][0] = MTP_ASSOCIATION&0xff;
		g_MTPImage.image_deviceinfo.PlaybackFormats[1][1] = (MTP_ASSOCIATION>>8)&0xff;
/*
		g_MTPImage.image_deviceinfo.PlaybackFormats[2][0] = MTP_MP3&0xff;
		g_MTPImage.image_deviceinfo.PlaybackFormats[2][1] = (MTP_MP3>>8)&0xff;
		g_MTPImage.image_deviceinfo.PlaybackFormats[3][0] = MTP_DEFINED&0xff;
		g_MTPImage.image_deviceinfo.PlaybackFormats[3][1] = (MTP_DEFINED>>8)&0xff;
		g_MTPImage.image_deviceinfo.PlaybackFormats[4][0] = MTP_WMA&0xff;
		g_MTPImage.image_deviceinfo.PlaybackFormats[4][1] = (MTP_WMA>>8)&0xff;
		g_MTPImage.image_deviceinfo.PlaybackFormats[5][0] = MTP_ABSTRACT_AUDIOVIDEO_PLAYLIST&0xff;
		g_MTPImage.image_deviceinfo.PlaybackFormats[5][1] = (MTP_ABSTRACT_AUDIOVIDEO_PLAYLIST>>8)&0xff;
*/

		g_USB_Image_Data_Header.ContainerType = USB_IMAGE_DATA_BLOCK;
	}
#endif

	/* Two never change assignments */
	g_USB_Image_Response.ContainerType = USB_IMAGE_RESPONSE_BLOCK;

	for(index = 0; index < USB_IMAGE_MAX_INTERRUPT_PKT; index++)
	{
		g_USBImage.image_event_array[index].ContainerType = USB_IMAGE_EVENT_BLOCK;
	}
}


/* interface reset function, enable EP*/
void USB_Image_If_Reset(void)
{
//	module_type 	src_mod;
//	ilm_struct 	*usb_ilm = NULL;


	g_USBImage.txpipe = &g_USBImage.image_ep_in_info->ep_status.epin_status;
	g_USBImage.rxpipe = &g_USBImage.image_ep_out_info->ep_status.epout_status;
	g_USBImage.intrpipe = &g_USBImage.image_ep_intr_info->ep_status.epin_status;

	USB_Stop_DMA_Channel(g_USBImage.txpipe->byEP, USB_EP_TX_DIR);
	USB_Clear_Tx_EP_FIFO(g_USBImage.txpipe->byEP, USB_ENDPT_BULK, KAL_TRUE);
	USB_Clear_Rx_EP_FIFO(g_USBImage.rxpipe->byEP, USB_ENDPT_BULK, KAL_TRUE);
	USB_Clear_Tx_EP_FIFO(g_USBImage.intrpipe->byEP, USB_ENDPT_INTR, KAL_TRUE);

	g_USBImage.is_suspend_state = KAL_FALSE;
	g_USBImage.usb_reset = KAL_TRUE;

	/* Initialize state machine */
	/* send reset message to usb task, task handles the PTP state machine*/
	if(g_USBImage.send_usb_image_reset_ilm == KAL_TRUE)
	{
		/* avoid sending too many messages to USB task */
	 	g_USBImage.send_usb_image_reset_ilm = KAL_FALSE;
		USB_Dbg_Trace(USB_IMAGE_SEND_RESET_MSG, 0, 0);

//		if(kal_if_hisr() == KAL_TRUE)
//			src_mod = MOD_DRV_HISR;
//		else
//			src_mod = MOD_USB;

	#ifdef PICTBRIDGE_SUPPORT
		if(USB_Get_Device_Type() == USB_IMAGE)
		{
			if(g_PTPImage.dps_discovery == KAL_TRUE)
				USB_Image_Send_Msg(USB_IMAGE_MSG_MMI_HOST_RESET_IND);

			USB_Send_Msg_Ext_Queue(MOD_USB, MSG_ID_USB_PTPIMAGE_RESET_IND, NULL);

//		 	DRV_BuildPrimitive(usb_ilm, src_mod,MOD_USB, MSG_ID_USB_PTPIMAGE_RESET_IND, NULL);
//	 		msg_send_ext_queue(usb_ilm);
		}
	#endif

	#ifdef __MTP_ENABLE__
		if(USB_Get_Device_Type() == USB_IMAGE_MTP)
		{
		
			USB_Send_Msg_Ext_Queue(MOD_USB, MSG_ID_USB_MTPIMAGE_RESET_IND, NULL);
//		 	DRV_BuildPrimitive(usb_ilm, src_mod,MOD_USB, MSG_ID_USB_MTPIMAGE_RESET_IND, NULL);
//	 		msg_send_ext_queue(usb_ilm);
		}
	#endif
	}
}


void USB_Image_If_Enable(void)
{
	/* Configure DMA setting for EP */
	USB_TxEPEn(g_USBImage.txpipe->byEP, USB_ENDPT_BULK, USB_EP_USE_ONLY_DMA, KAL_TRUE, KAL_FALSE);

	/*Non-DMA*/
	USB_RxEPEn(g_USBImage.rxpipe->byEP, USB_ENDPT_BULK, USB_EP_USE_DMA_ON_DEMAND, KAL_TRUE, KAL_FALSE);
	USB_TxEPEn(g_USBImage.intrpipe->byEP, USB_ENDPT_INTR, USB_EP_USE_NO_DMA, KAL_TRUE, KAL_FALSE);
}


void USB_Image_If_Speed_Reset(kal_bool b_other_speed)
{
#ifdef __USB_HS_ENABLE__
	g_USBImage.image_ep_intr_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_INTR_MAXP_FS&0xff;
//	g_USBImage.image_ep_intr_info->epdesc.stdep.wMaxPacketSize[1] = (USB_EP_INTR_MAXP_FS>>8)&0xff;
	g_USBImage.image_ep_intr_info->epdesc.stdep.wMaxPacketSize[1] = 0x00;

	if(USB_Is_High_Speed() == KAL_TRUE)
	{
		if(b_other_speed == KAL_FALSE)
		{
			g_USBImage.image_ep_in_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_BULK_MAXP_HS&0xff;
			g_USBImage.image_ep_in_info->epdesc.stdep.wMaxPacketSize[1] = (USB_EP_BULK_MAXP_HS>>8)&0xff;
			g_USBImage.image_ep_out_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_BULK_MAXP_HS&0xff;
			g_USBImage.image_ep_out_info->epdesc.stdep.wMaxPacketSize[1] = (USB_EP_BULK_MAXP_HS>>8)&0xff;
		}
		else
		{
			g_USBImage.image_ep_in_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_BULK_MAXP_FS&0xff;
//			g_USBImage.image_ep_in_info->epdesc.stdep.wMaxPacketSize[1] = (USB_EP_BULK_MAXP_FS>>8)&0xff;
			g_USBImage.image_ep_in_info->epdesc.stdep.wMaxPacketSize[1] = 0x00;
			g_USBImage.image_ep_out_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_BULK_MAXP_FS&0xff;
//			g_USBImage.image_ep_out_info->epdesc.stdep.wMaxPacketSize[1] = (USB_EP_BULK_MAXP_FS>>8)&0xff;
			g_USBImage.image_ep_out_info->epdesc.stdep.wMaxPacketSize[1] = 0x00;
		}
	}
	else
	{
		if(b_other_speed == KAL_FALSE)
		{
			g_USBImage.image_ep_in_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_BULK_MAXP_FS&0xff;
//			g_USBImage.image_ep_in_info->epdesc.stdep.wMaxPacketSize[1] = (USB_EP_BULK_MAXP_FS>>8)&0xff;
			g_USBImage.image_ep_in_info->epdesc.stdep.wMaxPacketSize[1] = 0x00;
			g_USBImage.image_ep_out_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_BULK_MAXP_FS&0xff;
//			g_USBImage.image_ep_out_info->epdesc.stdep.wMaxPacketSize[1] = (USB_EP_BULK_MAXP_FS>>8)&0xff;
			g_USBImage.image_ep_out_info->epdesc.stdep.wMaxPacketSize[1] = 0x00;
		}
		else
		{
			g_USBImage.image_ep_in_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_BULK_MAXP_HS&0xff;
			g_USBImage.image_ep_in_info->epdesc.stdep.wMaxPacketSize[1] = (USB_EP_BULK_MAXP_HS>>8)&0xff;
			g_USBImage.image_ep_out_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_BULK_MAXP_HS&0xff;
			g_USBImage.image_ep_out_info->epdesc.stdep.wMaxPacketSize[1] = (USB_EP_BULK_MAXP_HS>>8)&0xff;
		}
	}
#endif
}

/************************************************************
	USB image reset function
*************************************************************/
void USB_Image_Reset_Hdlr(void)
{
	g_USBImage.send_usb_image_reset_ilm = KAL_TRUE;
	g_USBImage.is_session_open = KAL_FALSE;
	g_USBImage.usb_reset = KAL_FALSE;
	g_USBImage.image_ep0_reset = KAL_FALSE;
	g_USBImage.intr_state = IMAGE_INTR_IDLE;
	g_USBImage.intr_read_ptr = 0;
	g_USBImage.intr_write_ptr = 0;
	g_USBImage.total_rx_bytes = 0;
	g_USBImage.current_rx_bytes = 0;
	g_USBImage.total_tx_bytes = 0;
	g_USBImage.current_tx_bytes = 0;
	g_USBImage.state = USB_IMAGE_CMD_RX;
}


#ifdef PICTBRIDGE_SUPPORT

void USB_Image_Reset_PTP_Hdlr(void)
{
	kal_int32		fs_result;


	g_PTPImage.rw_bytes = 0;
	g_PTPImage.get_data_error = KAL_FALSE;
	g_PTPImage.mmi_start_job = KAL_FALSE;
	g_PTPImage.next_xml_is_start_job = KAL_FALSE;
	g_PTPImage.is_start_job_xml = KAL_FALSE;
	g_PTPImage.is_wait_host_respone = KAL_FALSE;
	g_PTPImage.script_flag = (1<<DDISCVRY);

	if(g_PTPImage.current_file_handle != PTP_NO_HANDLE)
	{
#ifdef __DRM_SUPPORT__
		fs_result = DRM_close_file(g_PTPImage.current_file_handle);
#else
		fs_result = FS_Close(g_PTPImage.current_file_handle);
#endif

		if(fs_result != FS_NO_ERROR)
			USB_Dbg_Trace(USB_DBG_PTP_CLOSE_FS_ERROR, 0, 0);

		g_PTPImage.current_opened_object_handle = 0x00;
		g_PTPImage.current_file_handle = PTP_NO_HANDLE;
	}

	g_PTPImage.dps_discovery = KAL_FALSE;
	g_PTPImage.received_xml_size = 0;
	g_PTPImage.send_dps_request_xml_size = 0;
	g_PTPImage.send_dps_response_xml_size = 0;
}

#endif

/************************************************************
	global variable g_USBImage initialize and release functions
*************************************************************/
/* initialize global variable g_USBImage */
void USB_Init_Image_Status(void)
{
	g_USBImage.txpipe = NULL;
	g_USBImage.rxpipe = NULL;
	g_USBImage.intrpipe = NULL;
	g_USBImage.usb_image_stop = KAL_FALSE;

	USB_Image_Reset_Hdlr();
}


#ifdef PICTBRIDGE_SUPPORT

void USB_Init_PTP_Status(void)
{
	/* Initail file handle */
	g_PTPImage.current_opened_object_handle = 0x00;
	g_PTPImage.current_file_handle = PTP_NO_HANDLE;

	/* Register handler to handle the EP0 Rx handler  */
	USB_Register_EP0_RxHdlr(USB_Image_Ep0_Cancel_Hdlr);
}

#endif

#ifdef __MTP_ENABLE__

void USB_Init_MTP_Status(void)
{
	g_USBImage.b_wait_req_rsp = KAL_FALSE;
	g_USBImage.b_delay_disable_mtp_msg_for_req = KAL_FALSE;
	g_USBImage.b_mtp_stop_type = KAL_FALSE;
	g_USBImage.b_is_mtp_abnormal_msg = KAL_FALSE;
	g_USBImage.b_host_suspend = KAL_FALSE;
	g_USBImage.b_device_cancel = KAL_FALSE;

	/* Register handler to handle the EP0 Rx handler  */
	USB_Register_EP0_RxHdlr(USB_MTP_Image_Ep0_Cancel_Hdlr);
}

#endif

/* Release global variable g_USBImage */
void USB_Release_Image_Status(void)
{
	g_USBImage.txpipe = NULL;
	g_USBImage.rxpipe = NULL;
	g_USBImage.intrpipe = NULL;
	g_USBImage.usb_image_stop = KAL_FALSE;

	USB_Image_Reset_Hdlr();

	/* Release the EP0 Rx handler   */
	USB_Register_EP0_RxHdlr(NULL);
}


#ifdef __MTP_ENABLE__

/* This function usually is called by USB task, except by HISR when device down of OTG handler */
void USB_Release_MTP_Status(void)
{
	USB_Dbg_Trace(USB_IMAGE_RELEASE_MTP, g_USBImage.b_wait_enable_rsp, g_USBImage.b_wait_req_rsp);

	if((g_USBImage.b_wait_enable_rsp == KAL_TRUE)&&(g_USBImage.b_wait_req_rsp == KAL_TRUE))
		ASSERT(0);

	if(g_USBImage.b_wait_enable_rsp == KAL_TRUE)
	{
		ASSERT(0);
//		g_USBImage.b_is_pending_disable_mtp_msg = KAL_TRUE;
	}
	else if(g_USBImage.mtp_state == IMAGE_MTP_HOST_SUSPEND)
	{
		g_USBImage.b_delay_disable_mtp_msg_for_req = KAL_TRUE;
	}
	else
	{
		/* Send MTP disable msg to MTP task */
		USB_MTP_Image_Send_Msg(USB_MTP_IMAGE_MSG_DISABLE_REQ);
	}
	g_USBImage.mtp_image_buffer = NULL;
}

#endif

/************************************************************
	TX path DMA callback function
*************************************************************/
/* TX DMA callback function */
static void USB_Image_Tx_DMA_Callback(void)
{
//	ilm_struct *usb_ilm = NULL;


	USB_Dbg_Trace(USB_IMAGE_BUILD_DMA_TX_CALLBACK, 0 , 0);

	if(USB_Get_Device_State() == DEVSTATE_CONFIG)
	{
	#ifdef PICTBRIDGE_SUPPORT
		if(USB_Get_Device_Type() == USB_IMAGE)
		{
			/* Send a message to usb task, let PTP state machine handle the transmitted data */
			
			USB_Send_Msg_Ext_Queue(MOD_USB,MSG_ID_USB_PTPIMAGE_DATA_TX_DONE_CONF, NULL);
//			DRV_BuildPrimitive(usb_ilm, MOD_DRV_HISR, MOD_USB,MSG_ID_USB_PTPIMAGE_DATA_TX_DONE_CONF, NULL);
//			msg_send_ext_queue(usb_ilm);
		}
	#endif

	#ifdef __MTP_ENABLE__
		if(USB_Get_Device_Type() == USB_IMAGE_MTP)
		{
			/* Send a message to usb task, let MTP state machine handle the transmitted data */
			
			USB_Send_Msg_Ext_Queue(MOD_USB,MSG_ID_USB_MTPIMAGE_DATA_TX_DONE_CONF, NULL);
//			DRV_BuildPrimitive(usb_ilm, MOD_DRV_HISR, MOD_USB,MSG_ID_USB_MTPIMAGE_DATA_TX_DONE_CONF, NULL);
//			msg_send_ext_queue(usb_ilm);
		}
	#endif
	}
}

#ifdef __MTP_ENABLE__

static void USB_Image_Rx_DMA_Callback(void)
{
//	ilm_struct *usb_ilm = NULL;


	USB_Dbg_Trace(USB_IMAGE_BUILD_DMA_RX_CALLBACK, 0 , 0);

	if(USB_Get_Device_State() == DEVSTATE_CONFIG)
	{
		if(USB_Get_Device_Type() == USB_IMAGE_MTP)
		{
			/* Send a message to usb task, let MTP state machine handle the transmitted data */

			USB_Send_Msg_Ext_Queue(MOD_USB,MSG_ID_USB_MTPIMAGE_DATA_RX_DONE_CONF, NULL);
			
//			DRV_BuildPrimitive(usb_ilm, MOD_DRV_HISR, MOD_USB,MSG_ID_USB_MTPIMAGE_DATA_RX_DONE_CONF, NULL);
//			msg_send_ext_queue(usb_ilm);
		}
	}
}


/************************************************************
	RX/TX path build functions(use DMA)
*************************************************************/
/* Prepare to transmit Tx packet from addr and length len */
void USB_Image_BuildRx(void *addr, kal_uint32 len)
{
	USB_Dbg_Trace(USB_IMAGE_BUILD_DMA_RX, len , 0);

	/* Stop and ack DMA if previous DMA is not yet ready */
	USB_Stop_DMA_Channel(g_USBImage.rxpipe->byEP, USB_EP_RX_DIR);

	/* Initialize rxpipe data */
//	g_USBImage.rxpipe->pData = (kal_uint8 *)addr;
//	g_USBImage.rxpipe->nBytesRecv = 0;
	g_USBImage.rxpipe->nBuffLen = (kal_int32)len;

	IRQMask(IRQ_USB_CODE);

	/* USB reset and ep0 reset cmd will both stop DMA */
	/* If they happen before IRQmask, we will not build DMA in the following if conditions */
	/* If they happen after IRQmask, they will stop DMA */
	/* If before they stop DMA, the DMA already done, this DMA callback message will be ignored by USB task if checking */
	if((g_USBImage.usb_reset == KAL_FALSE)&&(g_USBImage.image_ep0_reset == KAL_FALSE)
		&&(g_USBImage.mtp_state == IMAGE_MTP_ENABLE))
	{
		/* DMA running state is "NOT" cleared inside the USB_Image_Rx_DMA_Callback function */
		USB_DMA_Setup(g_USBImage.rxpipe->byEP, USB_EP_RX_DIR, USB_ENDPT_BULK, (kal_uint32)addr, len,
				USB_Image_Rx_DMA_Callback, KAL_FALSE, KAL_TRUE, USB_DMA1_TYPE);
	}

	if(USB_Get_UnMask_Irq() == KAL_TRUE)
		IRQUnmask(IRQ_USB_CODE);
}

#endif

/* Prepare to transmit Tx packet from addr and length len */
void USB_Image_BuildTx(void *addr, kal_uint32 len)
{
	USB_Dbg_Trace(USB_IMAGE_BUILD_DMA_TX, len , 0);

	/* Stop and ack DMA if previous DMA is not yet ready */
	USB_Stop_DMA_Channel(g_USBImage.txpipe->byEP, USB_EP_TX_DIR);

	/* initialize Tx pipe*/
//	g_USBImage.txpipe->pData = (kal_uint8 *)addr;
//	g_USBImage.txpipe->nBytesLeft = (kal_int32)len;

	IRQMask(IRQ_USB_CODE);

	if((g_USBImage.usb_reset == KAL_FALSE)&&(g_USBImage.image_ep0_reset == KAL_FALSE))
	{
#ifdef PICTBRIDGE_SUPPORT
		if(USB_Get_Device_Type() == USB_IMAGE)
		{
			/* DMA running state is "NOT" cleared inside the USB_Image_Tx_DMA_Callback function */
			USB_DMA_Setup(g_USBImage.txpipe->byEP, USB_EP_TX_DIR, USB_ENDPT_BULK, (kal_uint32)addr, len,
				USB_Image_Tx_DMA_Callback, KAL_FALSE, KAL_TRUE, USB_DMA1_TYPE);
		}
#endif

#ifdef __MTP_ENABLE__
		if((USB_Get_Device_Type() == USB_IMAGE_MTP)&&(g_USBImage.mtp_state == IMAGE_MTP_ENABLE))
		{
			/* DMA running state is "NOT" cleared inside the USB_Image_Tx_DMA_Callback function */
			USB_DMA_Setup(g_USBImage.txpipe->byEP, USB_EP_TX_DIR, USB_ENDPT_BULK, (kal_uint32)addr, len,
				USB_Image_Tx_DMA_Callback, KAL_FALSE, KAL_TRUE, USB_DMA1_TYPE);
		}
#endif
	}

	if(USB_Get_UnMask_Irq() == KAL_TRUE)
		IRQUnmask(IRQ_USB_CODE);
}


/* Prepare to transmit Tx response packet from addr and length len */
void USB_Image_ReturnTx(void *addr, kal_uint32 len)
{
	USB_Dbg_Trace(USB_IMAGE_BUILD_RETURN_DMA_TX, len , 0);

	if(g_USBImage.state != USB_IMAGE_CMD_RX)
		ASSERT(0);

	/* Stop and ack DMA if previous DMA is not yet ready */
	USB_Stop_DMA_Channel(g_USBImage.txpipe->byEP, USB_EP_TX_DIR);

	/* initialize Tx pipe*/
//	g_USBImage.txpipe->pData = (kal_uint8 *)addr;
//	g_USBImage.txpipe->nBytesLeft = (kal_int32)len;

	IRQMask(IRQ_USB_CODE);

	if((g_USBImage.usb_reset == KAL_FALSE)&&(g_USBImage.image_ep0_reset == KAL_FALSE))
	{
#ifdef PICTBRIDGE_SUPPORT
		if(USB_Get_Device_Type() == USB_IMAGE)
		{
			/* DMA running state is "NOT" cleared inside the USB_Image_Tx_DMA_Callback function */
			USB_DMA_Setup(g_USBImage.txpipe->byEP, USB_EP_TX_DIR, USB_ENDPT_BULK, (kal_uint32)addr, len,
				NULL, KAL_FALSE, KAL_TRUE, USB_DMA1_TYPE);
		}
#endif

#ifdef __MTP_ENABLE__
		if((USB_Get_Device_Type() == USB_IMAGE_MTP)&&(g_USBImage.mtp_state == IMAGE_MTP_ENABLE))
		{
			/* DMA running state is "NOT" cleared inside the USB_Image_Tx_DMA_Callback function */
			USB_DMA_Setup(g_USBImage.txpipe->byEP, USB_EP_TX_DIR, USB_ENDPT_BULK, (kal_uint32)addr, len,
				NULL, KAL_FALSE, KAL_TRUE, USB_DMA1_TYPE);
		}
#endif
	}

	if(USB_Get_UnMask_Irq() == KAL_TRUE)
		IRQUnmask(IRQ_USB_CODE);
}


/************************************************************
	Utility functions
*************************************************************/
void USB_Send_Null_Packet(kal_uint8 ep_num)
{
	kal_bool		bEPEmpty;
	kal_uint32 	count = 0;


	/* Make sure that previous packets are already sent out,
	maybe last DMA data has triggered DMA done but data are still in FIFO*/
	bEPEmpty = USB_Is_EP_Tx_Empty(ep_num, USB_ENDPT_BULK);

	/* If cable plug out at this time, add timeout to avoid looping here */
	while((bEPEmpty == KAL_FALSE)&&(count != 300)&&(USB_Get_Device_State() == DEVSTATE_CONFIG))
	{
		count++;
		kal_sleep_task(1);
		bEPEmpty = USB_Is_EP_Tx_Empty(ep_num, USB_ENDPT_BULK);
	}

	if(USB_Get_Device_State() != DEVSTATE_CONFIG)
	{
		USB_Dbg_Trace(USB_IMAGE_CABLE_PLUG_OUT, (kal_uint32)USB_Get_Device_State(), 0);
		return;
	}

	if(bEPEmpty == KAL_FALSE)
	{
		/* time out */
		USB_Dbg_Trace(USB_IMAGE_NULL_PKT_TIME_OUT, 0, 0);
		return;
	}

	/* send out a NULL packet */
	USB_EPFIFOWrite(ep_num, 0, NULL);
	USB_EP_Tx_Ready(ep_num, USB_ENDPT_BULK);

	/* mak sure previous NULL pkt has been sent out
	avoid next DMA data in FIFO sent out instead of previos NULL pkt.*/
	bEPEmpty = USB_Is_EP_Tx_Empty(ep_num, USB_ENDPT_BULK);

	/* If cable plug out at this time, add timeout to avoid looping here */
	count = 0;
	while((bEPEmpty == KAL_FALSE)&&(count != 300)&&(USB_Get_Device_State() == DEVSTATE_CONFIG))
	{
		count++;
		kal_sleep_task(1);
		bEPEmpty = USB_Is_EP_Tx_Empty(ep_num, USB_ENDPT_BULK);
	}

	if(USB_Get_Device_State() != DEVSTATE_CONFIG)
	{
		USB_Dbg_Trace(USB_IMAGE_CABLE_PLUG_OUT, (kal_uint32)USB_Get_Device_State(), 0);
		return;
	}

	if(bEPEmpty == KAL_FALSE)
	{
		/* time out */
		USB_Dbg_Trace(USB_IMAGE_NULL_PKT_TIME_OUT, 0, 0);
		return;
	}
}


#ifdef __MTP_ENABLE__

void USB_Send_Header_Packet(kal_uint8 ep_num, void *pSrc)
{
	kal_bool		bEPEmpty;
	kal_uint32 	count = 0;


	/* Make sure that previous packets are already sent out
	maybe last DMA data has triggered DMA done but data are still in FIFO*/
	bEPEmpty = USB_Is_EP_Tx_Empty(ep_num, USB_ENDPT_BULK);
	while((bEPEmpty == KAL_FALSE)&&(count != 300)&&(USB_Get_Device_State() == DEVSTATE_CONFIG))
	{
		count++;
		kal_sleep_task(1);
		bEPEmpty = USB_Is_EP_Tx_Empty(ep_num, USB_ENDPT_BULK);
	}

	if((bEPEmpty == KAL_FALSE)&&(USB_Get_Device_State() == DEVSTATE_CONFIG))
		ASSERT(0);

	/* Send out a 12B packet for header */
	USB_EPFIFOWrite(ep_num, 12, pSrc);
	USB_EP_Tx_Ready(ep_num, USB_ENDPT_BULK);

	/* mak sure previous NULL pkt has been sent out
	avoid next DMA data in FIFO sent out instead of previos NULL pkt */
	bEPEmpty = USB_Is_EP_Tx_Empty(ep_num, USB_ENDPT_BULK);

	/* If cable plug out at this time, add timeout to avoid looping here */
	count = 0;
	while((bEPEmpty == KAL_FALSE)&&(count != 300)&&(USB_Get_Device_State() == DEVSTATE_CONFIG))
	{
		count++;
		kal_sleep_task(1);
		bEPEmpty = USB_Is_EP_Tx_Empty(ep_num, USB_ENDPT_BULK);
	}

	if(USB_Get_Device_State() != DEVSTATE_CONFIG)
	{
		USB_Dbg_Trace(USB_IMAGE_CABLE_PLUG_OUT, (kal_uint32)USB_Get_Device_State(), 0);
		return;
	}

	if(bEPEmpty == KAL_FALSE)
	{
		/* time out */
		USB_Dbg_Trace(USB_IMAGE_NULL_PKT_TIME_OUT, 0, 0);
		return;
	}
}


#endif


/* Send interrupt endpoint status packet */
void USB_Image_Send_Intr(void)
{
	kal_uint32 savedMask;
	kal_bool start_intr_pipe = KAL_FALSE;
	kal_uint32 max_intr_pkt_size;


	USB_Dbg_Trace(USB_IMAGE_SEND_INTERRUPT, (kal_uint32)g_USBImage.intr_write_ptr, (kal_uint32)g_USBImage.intr_read_ptr);

	if(USB_Get_Device_State() != DEVSTATE_CONFIG)
	{
		USB_Dbg_Trace(USB_IMAGE_CABLE_PLUG_OUT, (kal_uint32)USB_Get_Device_State(), 0);
		return;
	}

	if(intr_pkt_buf_is_full == KAL_TRUE)
	{
		USB_Dbg_Trace(USB_IMAGE_INTERRUPT_PKT_FULL, 0, 0);

		if(g_USBImage.is_suspend_state == KAL_TRUE)
		{
	#ifdef PICTBRIDGE_SUPPORT
			if(USB_Get_Device_Type() == USB_IMAGE)
				USB_Image_Send_Msg(USB_IMAGE_MSG_MMI_HOST_RESET_IND);
	#endif
			g_USBImage.usb_image_stop = KAL_TRUE;
		}
		return;
	}

	g_USBImage.image_event_array[g_USBImage.intr_write_ptr].ContainerLength = g_USBImage.image_event.ContainerLength;
	g_USBImage.image_event_array[g_USBImage.intr_write_ptr].Code = g_USBImage.image_event.Code;
	g_USBImage.image_event_array[g_USBImage.intr_write_ptr].TransactionID = g_USBImage.image_event.TransactionID;
	g_USBImage.image_event_array[g_USBImage.intr_write_ptr].Parameter1 = g_USBImage.image_event.Parameter1;

	savedMask = SaveAndSetIRQMask();

	g_USBImage.intr_write_ptr++;

	if(g_USBImage.intr_write_ptr == USB_IMAGE_MAX_INTERRUPT_PKT)
		g_USBImage.intr_write_ptr = 0;

	if(g_USBImage.intr_write_ptr == g_USBImage.intr_read_ptr)
	{
		intr_pkt_buf_is_full = KAL_TRUE;
	}

	if(g_intr_pipe_is_running == KAL_FALSE)
	{
		g_intr_pipe_is_running = KAL_TRUE;
		start_intr_pipe = KAL_TRUE;
	}

	RestoreIRQMask(savedMask);

	if(start_intr_pipe == KAL_TRUE)
	{
		if(g_USBImage.intr_state != IMAGE_INTR_IDLE)
			EXT_ASSERT(0, (kal_uint32)g_USBImage.intr_state, 0, 0);
/*
	#ifdef __USB_HS_ENABLE__
		if(USB_Is_High_Speed() == KAL_TRUE)
			max_intr_pkt_size = USB_EP_INTR_MAXP_HS;
		else
			max_intr_pkt_size = USB_EP_INTR_MAXP_FS;
	#else
		max_intr_pkt_size = USB_EP_INTR_MAXP;
	#endif
*/
		max_intr_pkt_size = USB_Intr_Max_Packet_Size();

		if(max_intr_pkt_size > g_USBImage.image_event_array[g_USBImage.intr_read_ptr].ContainerLength)
		{
			/* Send short packet */
			g_USBImage.intr_state = IMAGE_INTR_SEND_LAST_PKT;

			USB_Dbg_Trace(USB_IMAGE_SEND_INTERRUPT3,
				g_USBImage.image_event_array[g_USBImage.intr_read_ptr].ContainerLength , 0);

			USB_EPFIFOWrite(g_USBImage.intrpipe->byEP, g_USBImage.image_event_array[g_USBImage.intr_read_ptr].ContainerLength,
				(kal_uint8 *)&g_USBImage.image_event_array[g_USBImage.intr_read_ptr]);
		}
		else
		{
			g_USBImage.intr_state = IMAGE_INTR_SEND_ONE_PKT;

			USB_Dbg_Trace(USB_IMAGE_SEND_INTERRUPT1, max_intr_pkt_size, 0);

			USB_EPFIFOWrite(g_USBImage.intrpipe->byEP, max_intr_pkt_size,
					(kal_uint8 *)&g_USBImage.image_event_array[g_USBImage.intr_read_ptr]);
		}

		USB_EP_Tx_Ready(g_USBImage.intrpipe->byEP,  USB_ENDPT_INTR);
	}
}

#ifdef PICTBRIDGE_SUPPORT

void USB_Image_Cancel_By_Device(void)
{
	USB_Dbg_Trace(USB_IMAGE_CANCEL_BY_DEVICE1, 0, 0);
	USB_Image_Send_Msg(USB_IMAGE_MSG_MMI_OPEN_FILE_FAIL_IND);

	g_PTPImage.current_file_handle = PTP_NO_HANDLE;
	g_USBImage.state = USB_IMAGE_CMD_RX;
//	g_USBImage.host_cancel_flag = KAL_FALSE;

	USB_Dbg_Trace(USB_IMAGE_CANCEL_BY_DEVICE2, 0, 0);
	/* cancel transaction interrupt, if cancel transaction, then bulk pipe will stop */
	g_USBImage.image_event.ContainerLength = USB_IMAGE_CONTAINER_LENGTH;
	g_USBImage.image_event.Code = PTP_CANCEL_TRANSACTION;
	g_USBImage.image_event.TransactionID = g_USBImage.current_transactionID;
	USB_Image_Send_Intr();
}

#endif

/************************************************************
	EP0 command parse functions
*************************************************************/
/* Class specific reset command handler */
static void USB_Image_Cmd_Reset(void)
{
#ifdef PICTBRIDGE_SUPPORT
	kal_int32		fs_result;
#endif

	USB_Stop_DMA_Channel(g_USBImage.txpipe->byEP, USB_EP_TX_DIR);
	/* Cannot clear FIFO */
//	USB_Clear_Tx_EP_FIFO(g_USBImage.txpipe->byEP, USB_ENDPT_BULK, KAL_TRUE);
//	USB_Clear_Rx_EP_FIFO(g_USBImage.rxpipe->byEP, USB_ENDPT_BULK, KAL_TRUE);
//	USB_Clear_Tx_EP_FIFO(g_USBImage.intrpipe->byEP, USB_ENDPT_INTR, KAL_TRUE);

	/* Reset from reset signal or class specific EP0 RESET command */
	/* We cannot send reset message because if host reset and then send the first packet very quickly, */
	/* our state machine will not be "USB_IMAGE_CMD_RX" and assert */
	g_USBImage.image_ep0_reset = KAL_TRUE;
	g_USBImage.state = USB_IMAGE_CMD_RX;

#ifdef __MTP_ENABLE__
//	g_USBImage.host_cancel_flag = KAL_FALSE;
#endif
//	g_USBImage.send_usb_image_reset_ilm = KAL_TRUE;

#ifdef PICTBRIDGE_SUPPORT
	if((USB_Get_Device_Type() == USB_IMAGE)&&(g_PTPImage.current_file_handle != PTP_NO_HANDLE))
	{
	#ifdef __DRM_SUPPORT__
		fs_result = DRM_close_file(g_PTPImage.current_file_handle);
	#else
		fs_result = FS_Close(g_PTPImage.current_file_handle);
	#endif

		if(fs_result != FS_NO_ERROR)
			USB_Dbg_Trace(USB_DBG_PTP_CLOSE_FS_ERROR, 0, 0);

		g_PTPImage.current_opened_object_handle = 0x00;
		g_PTPImage.current_file_handle = PTP_NO_HANDLE;
	}
#endif
}

#ifdef PICTBRIDGE_SUPPORT

/* handle the class specific cancellation request */
static void USB_Image_Ep0_Cancel_Hdlr(void *data)
{
	kal_uint32	nCount;
	kal_uint32	cancel_transaction_ID;


	/* Read the cancel request data block */
	nCount = (kal_uint16)USB_EP0_Pkt_Len();

	if(nCount == 6)
	{
		USB_EPFIFORead(0, 6, &g_USBImage.cancel_block, KAL_FALSE);

		if(g_USBImage.cancel_block.Cancellation_Code != PTP_CANCEL_TRANSACTION)
			ASSERT(0);

		cancel_transaction_ID = (kal_uint16)g_USBImage.cancel_block.TransactionID[1];
		cancel_transaction_ID <<= 16;
		cancel_transaction_ID |= (kal_uint16)g_USBImage.cancel_block.TransactionID[0];

		if(cancel_transaction_ID != g_USBImage.current_transactionID)
		{
			/* If host indeed send the wrong id, we should not assert */
			USB_Dbg_Trace(USB_IMAGE_EP0_CANCEL_WITH_WRONG_TRANSACTION_ID, cancel_transaction_ID, g_USBImage.current_transactionID);
			drv_trace2(TRACE_FUNC, (kal_uint32)USBIMAGE_EP0_CANCEL_ERROR, cancel_transaction_ID, g_USBImage.current_transactionID);
//			EXT_ASSERT(0, g_USBImage.current_transactionID, cancel_transaction_ID, 0);
		}

//		g_USBImage.host_cancel_flag = KAL_TRUE;
		USB_Image_Cmd_Reset();
		USB_Image_BulkTx_Reset();
		USB_Image_BulkRx_Reset();

		USB_Set_Endpoint0_State(USB_EP0_RX_STATUS);
   		USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, KAL_FALSE, KAL_TRUE);
	}
	else
	{
		EXT_ASSERT(0, nCount, 0, 0);
	}
}

#endif

#ifdef __MTP_ENABLE__

/* Handle the class specific cancellation request */
static void USB_MTP_Image_Ep0_Cancel_Hdlr(void *data)
{
//	ilm_struct *usb_ilm = NULL;
	kal_uint32 nCount;
	kal_uint32 cancel_transaction_ID;


	/* Read the cancel request data block */
	nCount = (kal_uint16)USB_EP0_Pkt_Len();

	if(nCount == 6)
	{
		USB_EPFIFORead(0, 6, &g_USBImage.cancel_block, KAL_FALSE);

		if(g_USBImage.cancel_block.Cancellation_Code != MTP_CANCEL_TRANSACTION)
			ASSERT(0);

		cancel_transaction_ID = (kal_uint16)g_USBImage.cancel_block.TransactionID[1];
		cancel_transaction_ID <<= 16;
		cancel_transaction_ID |= (kal_uint16)g_USBImage.cancel_block.TransactionID[0];

		if(cancel_transaction_ID != g_USBImage.current_transactionID)
		{
			/* If host indeed send the wrong id, we should not assert */
			USB_Dbg_Trace(USB_IMAGE_EP0_CANCEL_WITH_WRONG_TRANSACTION_ID, cancel_transaction_ID, g_USBImage.current_transactionID);
			drv_trace2(TRACE_FUNC, (kal_uint32)USBIMAGE_EP0_CANCEL_ERROR, cancel_transaction_ID, g_USBImage.current_transactionID);
//			EXT_ASSERT(0, g_USBImage.current_transactionID, cancel_transaction_ID, 0);
		}


//		g_USBImage.host_cancel_flag = KAL_TRUE;
		/* Send abort message to MTP task */
//		USB_MTP_Image_Send_Msg(USB_MTP_IMAGE_MSG_HOST_ABORT_IND);

		if(g_USBImage.b_is_mtp_abnormal_msg == KAL_FALSE)
		{
			/* Send cancel msg to USB task to prevent race condition, set g_USBImage.mtp_state = IMAGE_MTP_HOST_CANCEL */
			g_USBImage.mtp_state = IMAGE_MTP_HOST_CANCEL;
			
			USB_Send_Msg_Ext_Queue(MOD_USB, MSG_ID_USB_MTPIMAGE_CANCEL_IND, NULL);
//			DRV_BuildPrimitive(usb_ilm, MOD_DRV_HISR, MOD_USB, MSG_ID_USB_MTPIMAGE_CANCEL_IND, NULL);
//			msg_send_ext_queue(usb_ilm);
		}
		else
		{
			g_USBImage.b_is_mtp_abnormal_msg = KAL_FALSE;
		}

		USB_Stop_DMA_Channel(g_USBImage.txpipe->byEP, USB_EP_TX_DIR);
		/* Cannot clear FIFO */
		USB_Clear_Tx_EP_FIFO(g_USBImage.txpipe->byEP, USB_ENDPT_BULK, KAL_FALSE);
		USB_Clear_Rx_EP_FIFO(g_USBImage.rxpipe->byEP, USB_ENDPT_BULK, KAL_FALSE);

		/* Reset from reset signal or class specific EP0 RESET command */
		g_USBImage.state = USB_IMAGE_CMD_RX;

//		USB_Image_Cmd_Reset();
		USB_Image_BulkTx_Reset();
		USB_Image_BulkRx_Reset();

		USB_Set_Endpoint0_State(USB_EP0_RX_STATUS);
   		USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, KAL_FALSE, KAL_TRUE);
	}
	else
	{
		EXT_ASSERT(0, nCount, 0, 0);
	}
}

#endif

/* Parse image class specific commands */
static void USB_Image_Ep0_Command(Usb_Ep0_Status *pep0state, Usb_Command *pcmd)
{
	kal_bool  bError = KAL_FALSE;


	switch (pcmd->bRequest)
	{
		case  USB_IMAGE_RESET:
			if( (pcmd->bmRequestType != USB_CMD_CLASSIFOUT) ||(pcmd->wValue != 0) ||(pcmd->wIndex != 0) )
			{
				bError = KAL_TRUE;
			}
			else
			{
				USB_Dbg_Trace(USB_IMAGE_EP0_RESET, 0, 0);
				drv_trace0(TRACE_FUNC, (kal_uint32)USBIMAGE_EP0_RESET);
				USB_Image_Cmd_Reset();
				USB_Image_BulkTx_Reset();
				USB_Image_BulkRx_Reset();
				USB_Image_IntrTx_Reset();
			}
			break;

		case  USB_IMAGE_CANCEL:
			if( (pcmd->bmRequestType != USB_CMD_CLASSIFOUT) ||(pcmd->wValue != 0) ||(pcmd->wIndex != 0)||(pcmd->wLength != 6))
			{
				bError = KAL_TRUE;
			}
			else
			{
				drv_trace0(TRACE_FUNC, (kal_uint32)USBIMAGE_EP0_CANCEL);
				USB_Dbg_Trace(USB_IMAGE_EP0_CANCEL, 0, 0);
				USB_Set_Endpoint0_State(USB_EP0_RX);
			}
			break;

		case  USB_IMAGE_GET_DEVICE_STATUS:
			if( (pcmd->bmRequestType != USB_CMD_CLASSIFIN) ||(pcmd->wValue != 0) ||(pcmd->wIndex != 0) )
			{
				bError = KAL_TRUE;
			}
			else
			{
		#ifdef PICTBRIDGE_SUPPORT
				if(USB_Get_Device_Type() == USB_IMAGE)
				{
/*
					if(g_USBImage.host_cancel_flag == KAL_TRUE)
					{
						USB_Dbg_Trace(USB_IMAGE_EP0_GET_DEVICE_STATUS, 1, 0);
						g_USBImage.device_status.wLength = 4;
						g_USBImage.device_status.Code = PTP_DEVICE_BUSY;
						USB_Generate_EP0Data(pep0state, pcmd, &g_USBImage.device_status, 4);
					}
					else
					{
*/
						USB_Dbg_Trace(USB_IMAGE_EP0_GET_DEVICE_STATUS, 2, 0);
						g_USBImage.device_status.wLength = 4;
						g_USBImage.device_status.Code = PTP_OK;
						USB_Generate_EP0Data(pep0state, pcmd, &g_USBImage.device_status, 4);
//					}
				}
		#endif

		#ifdef __MTP_ENABLE__
				if(USB_Get_Device_Type() == USB_IMAGE_MTP)
				{
					if(g_USBImage.mtp_state == IMAGE_MTP_HOST_CANCEL)
					{
						USB_Dbg_Trace(USB_IMAGE_EP0_GET_DEVICE_STATUS, 1, 0);
						drv_trace0(TRACE_FUNC, (kal_uint32)USBIMAGE_EP0_GET_STATUS_BUSY);

						/* Contiune busy untill USB receive MTP send abort event */
						USB_Stop_DMA_Channel(g_USBImage.txpipe->byEP, USB_EP_TX_DIR);
						/* Cannot clear FIFO */
						USB_Clear_Tx_EP_FIFO(g_USBImage.txpipe->byEP, USB_ENDPT_BULK, KAL_FALSE);
						USB_Clear_Rx_EP_FIFO(g_USBImage.rxpipe->byEP, USB_ENDPT_BULK, KAL_FALSE);

						/* Switch back to receive MTP RX cmd */
						if(USB_RxEP_Usage(g_USBImage.rxpipe->byEP) == USB_EP_STATE_DMA)
							USB_Config_RxEP_Type(g_USBImage.rxpipe->byEP, USB_ENDPT_BULK, KAL_FALSE);

						g_USBImage.state = USB_IMAGE_CMD_RX;
						g_USBImage.device_status.wLength = 4;
						g_USBImage.device_status.Code = MTP_DEVICE_BUSY;
						USB_Generate_EP0Data(pep0state, pcmd, &g_USBImage.device_status, 4);
					}
					else if (g_USBImage.b_device_cancel == KAL_TRUE)
					{
						g_USBImage.b_device_cancel = KAL_FALSE;

						USB_Dbg_Trace(USB_IMAGE_EP0_GET_DEVICE_STATUS, 2, 0);
						drv_trace0(TRACE_FUNC, (kal_uint32)USBIMAGE_EP0_GET_STATUS_CANCEL);

						/* Switch back to receive MTP RX cmd */
						if(USB_RxEP_Usage(g_USBImage.rxpipe->byEP) == USB_EP_STATE_DMA)
							USB_Config_RxEP_Type(g_USBImage.rxpipe->byEP, USB_ENDPT_BULK, KAL_FALSE);

						g_USBImage.state = USB_IMAGE_CMD_RX;
						g_USBImage.device_status.wLength = 12;
						g_USBImage.device_status.Code = MTP_TRANSACTION_CANCELLED;
						g_USBImage.device_status.TxEndPoint = g_USBImage.image_ep_in_info->epdesc.stdep.bEndpointAddress;
						g_USBImage.device_status.RxEndPoint = g_USBImage.image_ep_out_info->epdesc.stdep.bEndpointAddress;

						USB_Generate_EP0Data(pep0state, pcmd, &g_USBImage.device_status, 12);
					}
					else
					{
						USB_Dbg_Trace(USB_IMAGE_EP0_GET_DEVICE_STATUS, 3, 0);
						drv_trace0(TRACE_FUNC, (kal_uint32)USBIMAGE_EP0_GET_STATUS_OK);
						g_USBImage.device_status.wLength = 4;
						g_USBImage.device_status.Code = MTP_OK;
						g_USBImage.b_is_mtp_abnormal_msg = KAL_FALSE;
						USB_Generate_EP0Data(pep0state, pcmd, &g_USBImage.device_status, 4);
					}
				}
		#endif
			}
			break;

		default:
			drv_trace1(TRACE_FUNC, (kal_uint32)USBIMAGE_ERROR_CMDS, (kal_uint32)pcmd->bRequest);
			bError = KAL_TRUE;
			break;
	}

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

/************************************************************
	endpoint reset  functions
*************************************************************/
/* Bulk In endpoint reset function */
static void USB_Image_BulkTx_Reset(void)
{
	return;
}


/* Bulk Out endpoint reset function */
static void USB_Image_BulkRx_Reset(void)
{
	return;
}


/* Interrupt endpoint reset function */
static void USB_Image_IntrTx_Reset(void)
{
	g_USBImage.intr_state = IMAGE_INTR_IDLE;
	intr_pkt_buf_is_full = KAL_FALSE;
	g_intr_pipe_is_running = KAL_FALSE;
}

/************************************************************
	Interrupt EP IN handle functions
*************************************************************/

/* Interrupt endpoint done handler */
static void USB_Image_IntrTx_Hdlr(void)
{
	kal_uint32  len;
	kal_uint8   *addr;
	kal_uint32   read_ptr = g_USBImage.intr_read_ptr;
	kal_uint32 max_intr_pkt_size;


	USB_Dbg_Trace(USB_IMAGE_INTERRUPT_HANDLER, (kal_uint32)g_USBImage.intr_state, (kal_uint32)g_USBImage.intr_read_ptr);

	if(USB_Get_Device_State() != DEVSTATE_CONFIG)
	{
		/* USB reset */
		USB_Dbg_Trace(USB_IMAGE_DEVICE_RESET, 0, 0);
		return;
	}
/*

#ifdef __USB_HS_ENABLE__
	if(USB_Is_High_Speed() == KAL_TRUE)
		max_intr_pkt_size = USB_EP_INTR_MAXP_HS;
	else
		max_intr_pkt_size = USB_EP_INTR_MAXP_FS;
#else
		max_intr_pkt_size = USB_EP_INTR_MAXP;
#endif

*/
	max_intr_pkt_size = USB_Intr_Max_Packet_Size();


	switch(g_USBImage.intr_state)
	{
	case IMAGE_INTR_SEND_ONE_PKT:
		addr = (kal_uint8 *)(kal_uint32)&g_USBImage.image_event_array[read_ptr] + max_intr_pkt_size;

		if((g_USBImage.image_event_array[read_ptr].ContainerLength - max_intr_pkt_size) != max_intr_pkt_size)
		{
			/* Lask packet is a short packet */
			g_USBImage.intr_state = IMAGE_INTR_SEND_LAST_PKT;

			len = g_USBImage.image_event_array[read_ptr].ContainerLength - max_intr_pkt_size;

			/* Send last null or short packet */
			USB_Dbg_Trace(USB_IMAGE_SEND_INTERRUPT3, len, (kal_uint32)addr);
			USB_EPFIFOWrite(g_USBImage.intrpipe->byEP, len, addr);
		}
		else
		{
			g_USBImage.intr_state = IMAGE_INTR_SEND_TWO_PKT;

			USB_Dbg_Trace(USB_IMAGE_SEND_INTERRUPT2, max_intr_pkt_size, (kal_uint32)addr);
			USB_EPFIFOWrite(g_USBImage.intrpipe->byEP, max_intr_pkt_size, addr);
		}

		USB_EP_Tx_Ready(g_USBImage.intrpipe->byEP,  USB_ENDPT_INTR);
		break;

	case IMAGE_INTR_SEND_TWO_PKT:
		g_USBImage.intr_state = IMAGE_INTR_SEND_LAST_PKT;

		/* Send last null packet */
		USB_Dbg_Trace(USB_IMAGE_SEND_INTERRUPT3, 0, 0);
		USB_EPFIFOWrite(g_USBImage.intrpipe->byEP, 0, NULL);
		USB_EP_Tx_Ready(g_USBImage.intrpipe->byEP,  USB_ENDPT_INTR);
		break;

	case IMAGE_INTR_SEND_LAST_PKT:
		g_USBImage.intr_state = IMAGE_INTR_IDLE;
		intr_pkt_buf_is_full = KAL_FALSE;
		g_USBImage.intr_read_ptr++;

		if(g_USBImage.intr_read_ptr == USB_IMAGE_MAX_INTERRUPT_PKT)
			g_USBImage.intr_read_ptr = 0;

		if(g_USBImage.intr_write_ptr == g_USBImage.intr_read_ptr)
		{
			/* No interrupt pkt queue */
			g_intr_pipe_is_running = KAL_FALSE;
		}
		else
		{
			g_intr_pipe_is_running = KAL_TRUE;

			if(max_intr_pkt_size > g_USBImage.image_event_array[g_USBImage.intr_read_ptr].ContainerLength)
			{
				g_USBImage.intr_state = IMAGE_INTR_SEND_LAST_PKT;

				USB_Dbg_Trace(USB_IMAGE_SEND_INTERRUPT3,
					g_USBImage.image_event_array[g_USBImage.intr_read_ptr].ContainerLength , 0);

				USB_EPFIFOWrite(g_USBImage.intrpipe->byEP, g_USBImage.image_event_array[g_USBImage.intr_read_ptr].ContainerLength,
					(kal_uint8 *)&g_USBImage.image_event_array[g_USBImage.intr_read_ptr]);
			}
			else
			{
				g_USBImage.intr_state = IMAGE_INTR_SEND_ONE_PKT;

				USB_Dbg_Trace(USB_IMAGE_SEND_INTERRUPT1, max_intr_pkt_size, 0);

				USB_EPFIFOWrite(g_USBImage.intrpipe->byEP, max_intr_pkt_size,
						(kal_uint8 *)&g_USBImage.image_event_array[g_USBImage.intr_read_ptr]);
			}

			USB_EP_Tx_Ready(g_USBImage.intrpipe->byEP,  USB_ENDPT_INTR);
		}
		break;
	case IMAGE_INTR_IDLE:
	default:
		EXT_ASSERT(0, (kal_uint32)g_USBImage.intr_state, 0, 0);
		break;
	}
}


#ifdef PICTBRIDGE_SUPPORT

/************************************************************
	Bulk EP OUT handle functions
*************************************************************/
/* EP Bulk Out interrupt handler, called by EP interrupt */
static void USB_Image_BulkRx_Hdr(void)
{
	kal_uint32	nCount;
	ilm_struct 	*usb_ilm;
	USB_IMAGE_CONTAINER *data;


	/* Check data length */
	nCount = USB_EP_Rx_Pkt_Len(g_USBImage.rxpipe->byEP);

	if(nCount != 0)
	{
		drv_trace1(TRACE_FUNC, (kal_uint32)USBIMAGE_GET, nCount);

		if(g_USBImage.state == USB_IMAGE_CMD_RX)
		{
			/* Only when we receive the first packet, then we set this flag as false */
			g_USBImage.image_ep0_reset = KAL_FALSE;

			/* Read the data out */
			USB_EPFIFORead(g_USBImage.rxpipe->byEP, nCount, &g_USBImage.image_cmd, KAL_FALSE);
			g_USBImage.current_transactionID = g_USBImage.image_cmd.TransactionID;

			/* Check if the cmds have DATA RX state */
			if((g_USBImage.image_cmd.Code == PTP_SEND_OBJECT_INFO)||(g_USBImage.image_cmd.Code == PTP_SEND_OBJECT))
			{
				/* No message send to USB MTP state machine until we receive the first data packet */
				g_USBImage.state = USB_IMAGE_DATA_RX;
				g_USBImage.current_rx_bytes = 0;

				if(g_USBImage.image_cmd.Code == PTP_SEND_OBJECT_INFO)
				{
					if((g_USBImage.image_cmd.Parameter1|g_USBImage.image_cmd.Parameter2) != 0x00000000)
					{
						EXT_ASSERT(0, g_USBImage.image_cmd.Parameter1, g_USBImage.image_cmd.Parameter2, 0);
//						USB_CtrlEPStall(g_USBImage.txpipe->byEP, USB_EP_TX_DIR, KAL_TRUE);
//						USB_CtrlEPStall(g_USBImage.rxpipe->byEP, USB_EP_RX_DIR, KAL_TRUE);
					}
				}
			}
			else
			{
			
				USB_Send_Msg_Ext_Queue(MOD_USB,MSG_ID_USB_PTPIMAGE_DATA_RX_DONE_CONF, NULL);
//				DRV_BuildPrimitive(usb_ilm, MOD_DRV_HISR, MOD_USB,MSG_ID_USB_PTPIMAGE_DATA_RX_DONE_CONF, NULL);
//				msg_send_ext_queue(usb_ilm);
			}
		}
		else if(g_USBImage.state == USB_IMAGE_DATA_RX)
		{
			/* Begin to receive data packet */
			if(g_USBImage.current_rx_bytes == 0)
			{
				if(g_USBImage.image_cmd.Code == PTP_SEND_OBJECT)
				{
					if(g_PTPImage.dps_rx_buffer_index == 1)
					{
						/* Read the data out */
						USB_EPFIFORead(g_USBImage.rxpipe->byEP, nCount, g_PTPImage.dps_request_rx_data, KAL_FALSE);
						data = (USB_IMAGE_CONTAINER*)g_PTPImage.dps_request_rx_data;
						g_USBImage.total_rx_bytes = data->ContainerLength;

						if(data->ContainerLength > USB_IMAGE_PTP_MAX_XMLHREQUESTSIZE)
						{
							EXT_ASSERT(0, data->ContainerLength, USB_IMAGE_PTP_MAX_XMLHREQUESTSIZE, 0);
						}
					}
					else if(g_PTPImage.dps_rx_buffer_index == 0)
					{
						/* Read the data out */
						USB_EPFIFORead(g_USBImage.rxpipe->byEP, nCount, g_PTPImage.dps_response_rx_data, KAL_FALSE);
						data = (USB_IMAGE_CONTAINER*)g_PTPImage.dps_response_rx_data;
						g_USBImage.total_rx_bytes = data->ContainerLength;

						if(data->ContainerLength > USB_IMAGE_PTP_MAX_XMLHRSPONSESIZE)
						{
							EXT_ASSERT(0, data->ContainerLength, USB_IMAGE_PTP_MAX_XMLHRSPONSESIZE, 0);
						}
					}
					else
					{
						EXT_ASSERT(0, g_PTPImage.dps_rx_buffer_index, 0, 0);
					}
				}
				else if (g_USBImage.image_cmd.Code == PTP_SEND_OBJECT_INFO)
				{
					/* Read the data out */
					USB_EPFIFORead(g_USBImage.rxpipe->byEP, nCount, g_USBImage.image_info_buffer, KAL_FALSE);
					data = (USB_IMAGE_CONTAINER*)g_USBImage.image_info_buffer;
					g_USBImage.total_rx_bytes = data->ContainerLength;

					if(data->ContainerLength > USB_IMAGE_PTP_MAX_OBJECT_INFO)
					{
						EXT_ASSERT(0, data->ContainerLength, USB_IMAGE_PTP_MAX_OBJECT_INFO, 0);
					}
				}
				else
				{
					EXT_ASSERT(0, g_USBImage.image_cmd.Code, 0, 0);
				}
			}
			else
			{
				if(g_USBImage.image_cmd.Code == PTP_SEND_OBJECT)
				{
					if(g_PTPImage.dps_rx_buffer_index == 1)
					{
						USB_EPFIFORead(g_USBImage.rxpipe->byEP, nCount, g_PTPImage.dps_request_rx_data + g_USBImage.current_rx_bytes, KAL_FALSE);
					}
					else if(g_PTPImage.dps_rx_buffer_index == 0)
					{
						USB_EPFIFORead(g_USBImage.rxpipe->byEP, nCount, g_PTPImage.dps_response_rx_data + g_USBImage.current_rx_bytes, KAL_FALSE);
					}
					else
					{
						EXT_ASSERT(0, g_PTPImage.dps_rx_buffer_index, 0, 0);
					}
				}
				else if (g_USBImage.image_cmd.Code == PTP_SEND_OBJECT_INFO)
				{
					USB_EPFIFORead(g_USBImage.rxpipe->byEP, nCount,
						(kal_uint8 *)g_USBImage.image_info_buffer + g_USBImage.current_rx_bytes, KAL_FALSE);
				}
				else
				{
					EXT_ASSERT(0, g_USBImage.image_cmd.Code, 0, 0);
				}
			}

			g_USBImage.current_rx_bytes += nCount;

			if(g_USBImage.current_rx_bytes < g_USBImage.total_rx_bytes)
			{
				/* Do nothing */
			}
			else if(g_USBImage.current_rx_bytes == g_USBImage.total_rx_bytes)
			{
				g_USBImage.state = USB_IMAGE_RESPONSE;

				USB_Send_Msg_Ext_Queue(MOD_USB,MSG_ID_USB_PTPIMAGE_DATA_RX_DONE_CONF, NULL);

//				DRV_BuildPrimitive(usb_ilm, MOD_DRV_HISR, MOD_USB,MSG_ID_USB_PTPIMAGE_DATA_RX_DONE_CONF, NULL);
//				msg_send_ext_queue(usb_ilm);
			}
			else
			{
				EXT_ASSERT(0, g_USBImage.current_rx_bytes, g_USBImage.total_rx_bytes, 0);
			}
		}
		else
		{
			/* Because cable is quickly plugged in/out, printer send many OUT commands, make target go to wrong state*/
			/* Send stall not assert */
			/* Stop DMA first */
			USB_Stop_DMA_Channel(g_USBImage.txpipe->byEP, USB_EP_TX_DIR);

			USB_CtrlEPStall(g_USBImage.txpipe->byEP, USB_EP_TX_DIR, KAL_TRUE);
			USB_CtrlEPStall(g_USBImage.rxpipe->byEP, USB_EP_RX_DIR, KAL_TRUE);
//			EXT_ASSERT(0, g_USBImage.state, 0, 0);
		}
	}

	/* Clear OutPktRdy */
	USB_EP_Rx_Ready(g_USBImage.rxpipe->byEP, USB_ENDPT_BULK);
}


/************************************************************
	Send message functions used by the whole image class driver
*************************************************************/
void USB_Image_Send_Msg(USB_IMAGE_MSG_TYPE usb_msg_type)
{
	usb_image_xml_struct *xml_receive_ind;
	usb_mmi_dps_discovery_ind_struct *dps_xml_ind;
	ilm_struct *usb_ilm;
	module_type src_mod;
	module_type dest_mod;


	if(g_USBImage.usb_image_stop == KAL_TRUE)
		return;

#ifdef __PICTBRIDGE_USB_TEST__
	dest_mod = MOD_CUSTOM1;
#else
	dest_mod = MOD_MMI;
#endif

	if(kal_if_hisr() == KAL_TRUE)
		src_mod = MOD_DRV_HISR;
	else
		src_mod = MOD_USB;

	if(usb_msg_type == USB_IMAGE_MSG_MMI_DISCOVERY_IND)
	{
		dps_xml_ind = (usb_mmi_dps_discovery_ind_struct*)construct_local_para(
							sizeof(usb_mmi_dps_discovery_ind_struct), TD_CTRL);

		dps_xml_ind->dps_xml_request_address = g_PTPImage.dps_request_tx_data + USB_IMAGE_CONTAINER_LENGTH;
		dps_xml_ind->dps_xml_request_buffer_size = USB_IMAGE_PTP_MAX_XMLBUFFERSIZE - USB_IMAGE_CONTAINER_LENGTH;
		dps_xml_ind->dps_xml_response_address = g_PTPImage.dps_response_tx_data + USB_IMAGE_CONTAINER_LENGTH;
		dps_xml_ind->dps_xml_response_buffer_size = USB_IMAGE_PTP_MAX_XMLBUFFERSIZE - USB_IMAGE_CONTAINER_LENGTH;
		dps_xml_ind->dps_xml_start_job_buffer_size = USB_IMAGE_PTP_MAX_START_JOB_XMLBUFFERSIZE - USB_IMAGE_CONTAINER_LENGTH;

		/* send a message to mmi, let it know the addresses can be placed xml packet  */
		USB_Send_Msg_Ext_Queue(dest_mod,MSG_ID_USB_MMI_DPS_DISCOVERY_IND, dps_xml_ind);
//		DRV_BuildPrimitive(usb_ilm, src_mod, dest_mod,MSG_ID_USB_MMI_DPS_DISCOVERY_IND, dps_xml_ind);
	}
	else if(usb_msg_type == USB_IMAGE_MSG_MMI_HREQUEST_IND)
	{
		xml_receive_ind = (usb_image_xml_struct*)construct_local_para(
							sizeof(usb_image_xml_struct), TD_CTRL);

		xml_receive_ind->xml_address = g_PTPImage.dps_request_rx_data + USB_IMAGE_CONTAINER_LENGTH;
		xml_receive_ind->xml_packet_size = g_PTPImage.received_xml_size;

		/* send a message to mmi, let it know a request xml packet arrive */
		USB_Send_Msg_Ext_Queue(dest_mod,MSG_ID_USB_MMI_DPS_HREQUEST_IND, xml_receive_ind);
//		DRV_BuildPrimitive(usb_ilm, src_mod, dest_mod,MSG_ID_USB_MMI_DPS_HREQUEST_IND, xml_receive_ind);
	}
	else if(usb_msg_type == USB_IMAGE_MSG_MMI_HRESPONSE_IND)
	{
		xml_receive_ind = (usb_image_xml_struct*)construct_local_para(
							sizeof(usb_image_xml_struct), TD_CTRL);

		xml_receive_ind->xml_address = g_PTPImage.dps_response_rx_data + USB_IMAGE_CONTAINER_LENGTH;
		xml_receive_ind->xml_packet_size = g_PTPImage.received_xml_size;

		/* send a message to mmi, let it know a response xml packet arrive */
		USB_Send_Msg_Ext_Queue(dest_mod,MSG_ID_USB_MMI_DPS_HRESPONSE_IND, xml_receive_ind);
//		DRV_BuildPrimitive(usb_ilm, src_mod, dest_mod,MSG_ID_USB_MMI_DPS_HRESPONSE_IND, xml_receive_ind);
	}
	else if(usb_msg_type == USB_IMAGE_MSG_MMI_DREQUEST_CONF)
	{
		USB_Send_Msg_Ext_Queue(MOD_USB,MSG_ID_USB_PTPIMAGE_DATA_RX_DONE_CONF, NULL);
//		DRV_BuildPrimitive(usb_ilm, src_mod, dest_mod,MSG_ID_USB_MMI_DPS_DREQUEST_CONF, NULL);
	}
	else if(usb_msg_type == USB_IMAGE_MSG_MMI_DRESPONSE_CONF)
	{
		USB_Send_Msg_Ext_Queue(dest_mod,MSG_ID_USB_MMI_DPS_DRESPONSE_CONF, NULL);
//		DRV_BuildPrimitive(usb_ilm, src_mod, dest_mod,MSG_ID_USB_MMI_DPS_DRESPONSE_CONF, NULL);
	}
/*
	else if(usb_msg_type == USB_IMAGE_MSG_MMI_CONNECT_TO_PC_IND)
	{
		USB_Send_Msg_Ext_Queue(usb_ilm,dest_mod,MSG_ID_USB_MMI_PTP_CONNECT_TO_PC_IND, NULL);
//		DRV_BuildPrimitive(usb_ilm, src_mod, dest_mod,MSG_ID_USB_MMI_PTP_CONNECT_TO_PC_IND, NULL);
	}
*/
	else if(usb_msg_type == USB_IMAGE_MSG_MMI_OPEN_FILE_FAIL_IND)
	{
		USB_Send_Msg_Ext_Queue(dest_mod,MSG_ID_USB_MMI_PTP_OPEN_FILE_FAIL_IND, NULL);
//		DRV_BuildPrimitive(usb_ilm, src_mod, dest_mod,MSG_ID_USB_MMI_PTP_OPEN_FILE_FAIL_IND, NULL);
	}
	else if(usb_msg_type == USB_IMAGE_MSG_MMI_HOST_RESET_IND)
	{
		USB_Send_Msg_Ext_Queue(dest_mod,MSG_ID_USB_MMI_PTP_HOST_RESET_IND, NULL);
//		DRV_BuildPrimitive(usb_ilm, src_mod, dest_mod,MSG_ID_USB_MMI_PTP_HOST_RESET_IND, NULL);
	}
	else
	{
		usb_ilm = NULL;
		EXT_ASSERT(0, (kal_uint32)usb_msg_type, 0, 0);
	}

//	msg_send_ext_queue(usb_ilm);
}

#endif   /* PICTBRIDGE_SUPPORT */



#ifdef __MTP_ENABLE__

/************************************************************
	Bulk EP OUT handle functions
*************************************************************/
/* EP Bulk Out interrupt handler, called by EP interrupt */
static void USB_MTP_Image_BulkRx_Hdr(void)
{
	kal_uint32 nCount;
//	ilm_struct *usb_ilm = NULL;
	USB_IMAGE_CONTAINER *data;
	static kal_bool b_rx_null_pkt = KAL_FALSE;

	/* Check data length */
	nCount = USB_EP_Rx_Pkt_Len(g_USBImage.rxpipe->byEP);

	if(nCount == 0)
	{
		/* V2 IP will issue a intr for last 64B, and an extra intr for 0 byte */
		if(b_rx_null_pkt == KAL_FALSE)
			ASSERT(0);
		/* Clear RxPktRdy */
		USB_EP_Rx_Ready(g_USBImage.rxpipe->byEP, USB_ENDPT_BULK);
	}
	else
	{
		drv_trace1(TRACE_FUNC, (kal_uint32)USBIMAGE_GET, nCount);

		if(USB_RxEP_Usage(g_USBImage.rxpipe->byEP) == USB_EP_STATE_DMA)
			ASSERT(0);

		if(g_USBImage.state == USB_IMAGE_CMD_RX)
		{
			/* Only when we receive the first packet, then we set those flags as false */
			g_USBImage.image_ep0_reset = KAL_FALSE;
//			g_USBImage.host_cancel_flag = KAL_FALSE;

			b_rx_null_pkt = KAL_FALSE;
			/* Write the 5 parameters as 0x00 first */
			kal_mem_set(&g_USBImage.image_cmd.Parameter1, 0x00, 20);

			/* Read the cmd packet out, and it always short packet (<64) */
			USB_EPFIFORead(g_USBImage.rxpipe->byEP, nCount, &g_USBImage.image_cmd, KAL_FALSE);
			g_USBImage.current_transactionID = g_USBImage.image_cmd.TransactionID;

			/* Clear RxPktRdy */
			USB_EP_Rx_Ready(g_USBImage.rxpipe->byEP, USB_ENDPT_BULK);

			/* Query if the cmds have DATA RX state */
			if(USB_MTP_Is_RX_Cmd(g_USBImage.image_cmd.Code) == KAL_TRUE)
			{
				/* No message send to USB MTP state machine until we receive the DMA callback of data phase */
				g_USBImage.state = USB_IMAGE_DATA_RX;
				g_USBImage.current_rx_bytes = 0;

				/* Save debug info */
				if(g_USBImage.image_cmd.Code == MTP_SEND_OBJECT_INFO)
					USB_Dbg_Trace(USB_MTP_SEND_OBJECT_INFO, g_USBImage.image_cmd.Parameter1, g_USBImage.image_cmd.Parameter2);
				else if(g_USBImage.image_cmd.Code == MTP_SEND_OBJECT)
					USB_Dbg_Trace(USB_MTP_SEND_OBJECT, 0, 0);
				else if(g_USBImage.image_cmd.Code == MTP_SET_DEVICE_PROP_VALUE)
					USB_Dbg_Trace(USB_MTP_SET_DEVICE_PROP_VALUE, g_USBImage.image_cmd.Parameter1, 0);
				else if(g_USBImage.image_cmd.Code == MTP_SET_OBJECT_PROP_VALUE)
					USB_Dbg_Trace(USB_MTP_SET_OBJECT_PROP_VALUE, g_USBImage.image_cmd.Parameter1, g_USBImage.image_cmd.Parameter2);
				else if(g_USBImage.image_cmd.Code == MTP_SET_OBJECT_REFERENCES)
					USB_Dbg_Trace(USB_MTP_SET_OBJECT_REFERENCES, g_USBImage.image_cmd.Parameter1, 0);
			}
			else
			{
			
				USB_Send_Msg_Ext_Queue(MOD_USB,MSG_ID_USB_MTPIMAGE_DATA_RX_DONE_CONF, NULL);
//				DRV_BuildPrimitive(usb_ilm, MOD_DRV_HISR, MOD_USB,MSG_ID_USB_MTPIMAGE_DATA_RX_DONE_CONF, NULL);
//				msg_send_ext_queue(usb_ilm);
			}
		}
		else if(g_USBImage.state == USB_IMAGE_DATA_RX)
		{
			/* To make sure this function only enter once */
			if((g_USBImage.current_rx_bytes != 0)||(nCount != USB_IMAGE_CONTAINER_LENGTH))
				EXT_ASSERT(0, g_USBImage.current_rx_bytes, nCount, 0);

			/* Read the first data packet out by FIFOread */
			USB_EPFIFORead(g_USBImage.rxpipe->byEP, USB_IMAGE_CONTAINER_LENGTH, g_USBImage.mtp_image_buffer, KAL_FALSE);
			data = (USB_IMAGE_CONTAINER*)g_USBImage.mtp_image_buffer;
			/* g_USBImage.total_rx_bytes is the tatal bytes of the data phase without 12B header */
			g_USBImage.total_rx_bytes = data->ContainerLength - USB_IMAGE_CONTAINER_LENGTH;

			g_USBImage.data_total_size = g_USBImage.total_rx_bytes;
			g_USBImage.data_pool_size = USB_IMAGE_MTP_MAX_RX_BUFFERSIZE;

			g_USBImage.buffer_read_index = 0;
			g_USBImage.buffer_write_index = 0;
			g_USBImage.buffer_rw_bytes[0] = 0;
			g_USBImage.buffer_rw_bytes[1] = 0;

			if(g_USBImage.total_rx_bytes != 0)
			{
		#ifdef __USB_HS_ENABLE__
				if(USB_Is_High_Speed() == KAL_TRUE)
				{
					if((g_USBImage.total_rx_bytes%USB_EP_BULK_MAXP_HS) == 0)
						b_rx_null_pkt = KAL_TRUE;
				}
				else
				{
					if((g_USBImage.total_rx_bytes%USB_EP_BULK_MAXP_FS) == 0)
						b_rx_null_pkt = KAL_TRUE;
				}
		#else
				if((g_USBImage.total_rx_bytes%USB_EP_BULK_MAXP) == 0)
					b_rx_null_pkt = KAL_TRUE;
		#endif

				/* Switch endpoint state to use DMA */
				/* Change ep state must before clear RxPktRdy, otherwise, there may be one packet lost after clear RxPktRdy and before switch to DMA */
				USB_Config_RxEP_Type(g_USBImage.rxpipe->byEP, USB_ENDPT_BULK, KAL_TRUE);

				/* Clear RxPktRdy */
				USB_EP_Rx_Ready(g_USBImage.rxpipe->byEP, USB_ENDPT_BULK);

				if(g_USBImage.total_rx_bytes <= USB_IMAGE_MTP_MAX_RX_BUFFERSIZE)
				{
					/* Only needs to config DMA once */
					USB_Image_BuildRx((kal_uint8 *)g_USBImage.mtp_image_buffer, g_USBImage.total_rx_bytes);
				}
				else
				{
					USB_Image_BuildRx((kal_uint8 *)g_USBImage.mtp_image_buffer, USB_IMAGE_MTP_MAX_RX_BUFFERSIZE);
				}

				if(g_USBImage.image_cmd.Code == MTP_SET_DEVICE_PROP_VALUE)
					g_USBImage.state = USB_IMAGE_RESPONSE;
			}
			else
			{
				/* USB HISR already receive all packet, but if the file with 0 bytes,
						its g_USBImage.buffer_rw_bytes[g_USBImage.buffer_write_index] will be 0 */
				/* No needs to use DMA, we already receive all data by one packet */
				/* Clear RxPktRdy */
				USB_EP_Rx_Ready(g_USBImage.rxpipe->byEP, USB_ENDPT_BULK);

				/* Already received all data by one FIFO packet */
				
				USB_Send_Msg_Ext_Queue(MOD_USB,MSG_ID_USB_MTPIMAGE_DATA_RX_DONE_CONF, NULL);
//				DRV_BuildPrimitive(usb_ilm, MOD_DRV_HISR, MOD_USB,MSG_ID_USB_MTPIMAGE_DATA_RX_DONE_CONF, NULL);
//				msg_send_ext_queue(usb_ilm);
			}
		}
		else
		{
			/* Send stall not assert */
			/* Stop DMA first */
			USB_Stop_DMA_Channel(g_USBImage.txpipe->byEP, USB_EP_TX_DIR);

			USB_CtrlEPStall(g_USBImage.txpipe->byEP, USB_EP_TX_DIR, KAL_TRUE);
			USB_CtrlEPStall(g_USBImage.rxpipe->byEP, USB_EP_RX_DIR, KAL_TRUE);
			/* Record debug info */
			drv_trace2(TRACE_FUNC, (kal_uint32)USB_MTP_PC_SEND_WRONG_PACKET, nCount, (kal_uint32)g_USBImage.state);
			USB_Dbg_Trace(USB_MTP_HOST_SEND_PACKET_IN_WRONG_STATE, nCount, (kal_uint32)g_USBImage.state);
		}
	}
}

/************************************************************
	Send message functions used by the whole image class driver
*************************************************************/
void USB_MTP_Image_Send_Msg(USB_MTP_IMAGE_MSG_TYPE usb_msg_type)
{
	usb_mtp_operation_req_struct* usb_mtp_req_ind;
	usb_mtp_event_ind_struct* usb_mtp_abort_ind;
//	ilm_struct *usb_ilm = NULL;
//	module_type src_mod;


	if(g_USBImage.usb_image_stop == KAL_TRUE)
		return;

//	if(kal_if_hisr() == KAL_TRUE)
//		src_mod = MOD_DRV_HISR;
//	else
//		src_mod = MOD_USB;

	if(usb_msg_type == USB_MTP_IMAGE_MSG_ENABLE_REQ)
	{
		USB_Dbg_Trace(USB_MTP_SEND_ENABLE_REQ_MSG, g_USBImage.b_wait_enable_rsp, g_USBImage.mtp_state);

		if(g_USBImage.b_wait_enable_rsp == KAL_TRUE)
			ASSERT(0);
		g_USBImage.b_wait_enable_rsp = KAL_TRUE;

		if(g_USBImage.mtp_state == IMAGE_MTP_ENABLE)
			ASSERT(0);

		USB_Send_Msg_Ext_Queue(MOD_MTP, MSG_ID_USB_MTP_ENABLE_REQ, NULL);

//		DRV_BuildPrimitive(usb_ilm, src_mod, MOD_MTP, MSG_ID_USB_MTP_ENABLE_REQ, NULL);
	}
	else if (usb_msg_type == USB_MTP_IMAGE_MSG_DISABLE_REQ)
	{
		USB_Dbg_Trace(USB_MTP_SEND_DISABLE_REQ_MSG, g_USBImage.b_wait_disable_rsp, g_USBImage.mtp_state);

		if(g_USBImage.b_wait_disable_rsp == KAL_TRUE)
			ASSERT(0);
		g_USBImage.b_wait_disable_rsp = KAL_TRUE;

		/* "Disable" state is set when USB sent the msg */
		if(g_USBImage.mtp_state == IMAGE_MTP_DISABLE)
			ASSERT(0);
		g_USBImage.mtp_state = IMAGE_MTP_DISABLE;

		USB_Send_Msg_Ext_Queue(MOD_MTP, MSG_ID_USB_MTP_DISABLE_REQ, NULL);

//		DRV_BuildPrimitive(usb_ilm, src_mod, MOD_MTP, MSG_ID_USB_MTP_DISABLE_REQ, NULL);
	}
	else if (usb_msg_type == USB_MTP_IMAGE_MSG_OPERATION_REQ)
	{
		USB_Dbg_Trace(USB_MTP_SEND_OP_REQ_MSG, g_USBImage.b_wait_req_rsp, g_USBImage.mtp_state);

		if(g_USBImage.b_wait_req_rsp == KAL_TRUE)
			ASSERT(0);
		g_USBImage.b_wait_req_rsp = KAL_TRUE;

		if((g_USBImage.mtp_state == IMAGE_MTP_DISABLE)||(g_USBImage.b_is_mtp_abnormal_msg == KAL_TRUE))
			ASSERT(0);

		usb_mtp_req_ind = (usb_mtp_operation_req_struct*)construct_local_para(
							sizeof(usb_mtp_operation_req_struct), TD_CTRL);

		usb_mtp_req_ind->op_code = g_USBImage.image_cmd.Code;
		usb_mtp_req_ind->op_params[0] = g_USBImage.image_cmd.Parameter1;
		usb_mtp_req_ind->op_params[1] = g_USBImage.image_cmd.Parameter2;
		usb_mtp_req_ind->op_params[2] = g_USBImage.image_cmd.Parameter3;
		usb_mtp_req_ind->op_params[3] = g_USBImage.image_cmd.Parameter4;
		usb_mtp_req_ind->op_params[4] = g_USBImage.image_cmd.Parameter5;

		usb_mtp_req_ind->data_total_size = g_USBImage.data_total_size;
		usb_mtp_req_ind->data_pool_ptr = g_USBImage.data_pool_ptr;
		usb_mtp_req_ind->data_pool_size = g_USBImage.data_pool_size;
		usb_mtp_req_ind->data_size = g_USBImage.data_size;

		USB_Send_Msg_Ext_Queue(MOD_MTP, MSG_ID_USB_MTP_OPERATION_REQ, usb_mtp_req_ind);

//		DRV_BuildPrimitive(usb_ilm, src_mod, MOD_MTP, MSG_ID_USB_MTP_OPERATION_REQ, usb_mtp_req_ind);
	}
	else if((usb_msg_type == USB_MTP_IMAGE_MSG_HOST_ABORT_IND)||(usb_msg_type == USB_MTP_IMAGE_MSG_HOST_SUSPEND_IND))
	{
		USB_Dbg_Trace(USB_MTP_SEND_ABORT_EVENT_MSG, g_USBImage.mtp_state, usb_msg_type);

		if(g_USBImage.mtp_state == IMAGE_MTP_DISABLE)
			ASSERT(0);

//		if(usb_msg_type == USB_MTP_IMAGE_MSG_DEVICE_ABORT_IND)
//			g_USBImage.mtp_state = IMAGE_MTP_DEVICE_ABORT;
		if(usb_msg_type == USB_MTP_IMAGE_MSG_HOST_SUSPEND_IND)
			g_USBImage.mtp_state = IMAGE_MTP_HOST_SUSPEND;

		usb_mtp_abort_ind = (usb_mtp_event_ind_struct*)construct_local_para(
							sizeof(usb_mtp_event_ind_struct), TD_CTRL);

		usb_mtp_abort_ind->event = (kal_uint16)USB_MTP_EVENT_ABORT;
		usb_mtp_abort_ind->event_code = 0x00;
		usb_mtp_abort_ind->params[0] = 0x00;
		usb_mtp_abort_ind->params[1] = 0x00;
		usb_mtp_abort_ind->params[2] = 0x00;

		USB_Send_Msg_Ext_Queue(MOD_MTP, MSG_ID_USB_MTP_EVENT_IND, usb_mtp_abort_ind);

//		DRV_BuildPrimitive(usb_ilm, src_mod, MOD_MTP, MSG_ID_USB_MTP_EVENT_IND, usb_mtp_abort_ind);
	}
//	else if (usb_msg_type == USB_MTP_IMAGE_MSG_HOST_CANCEL_IND)
//	{
//		g_USBImage.mtp_state = IMAGE_MTP_HOST_CANCEL;
//		USB_Send_Msg_Ext_Queue(usb_ilm,MOD_USB, MSG_ID_USB_MTPIMAGE_CANCEL_IND, NULL);
//	}
//		DRV_BuildPrimitive(usb_ilm, src_mod, MOD_USB, MSG_ID_USB_MTPIMAGE_CANCEL_IND, NULL);
//	}
//	else if (usb_msg_type == USB_MTP_IMAGE_MSG_HOST_RESET_IND)
//	{
//		USB_Send_Msg_Ext_Queue(usb_ilm,MOD_MTP, MSG_ID_USB_MTP_EVENT_IND, NULL);
//		DRV_BuildPrimitive(usb_ilm, src_mod, MOD_MTP, MSG_ID_USB_MTP_EVENT_IND, NULL);
//	}
	else
	{
//		usb_ilm = NULL;
		EXT_ASSERT(0, (kal_uint32)usb_msg_type, 0, 0);
	}

//	msg_send_ext_queue(usb_ilm);
}

/************************************************************
	Used by DCL API Interface
*************************************************************/
kal_uint16* USB_MTP_Image_Get_Storage_Description_String_1_Ptr()
{
	return (kal_uint16*)g_USBImage.mtp_image_param->image_storage_description_string_1;
}

kal_uint16* USB_MTP_Image_Get_Storage_Description_String_2_Ptr()
{
	return (kal_uint16*)g_USBImage.mtp_image_param->image_storage_description_string_2;
}


#endif /* __MTP_ENABLE__ */

#endif   /* __USB_IMAGE_CLASS__ */

