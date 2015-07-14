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
 *   usb_host_acm_drv.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  This file implements the host CDC ACM class driver
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef __OTG_ENABLE__

#ifdef __USB_HOST_COM_PORT_SUPPORT__

#include "drv_comm.h"
#include "usb_comm.h"
#include "usb.h"
#include "usb_adap.h"
#include "usbacm_drv.h"
#include "usbd.h"
#include "usb_host_acm_drv.h"
//#include "otg_drv.h"
//#include "stack_common.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "kal_public_api.h" //#include "stack_ltlcom.h" //MSBB change #include "app_ltlcom.h"       /* Task message communiction */
#include "otg.h"
#include "usb_debug_tool.h"
#include "usb_trc.h"

USB_Host_Acm_Struct g_UsbHostAcm;

static kal_bool USB_Host_Acm_Match(kal_uint8 usb_ip_port,USBD_Desc_Info *p_desc_info, kal_uint32 cfg_num, kal_uint32 if_num)
{
	kal_bool b_match = KAL_FALSE;
	kal_uint32 index;


	if(((p_desc_info->dev_desc.bDeviceClass == USB_ACM_DEVICE_CODE)&&(p_desc_info->dev_desc.bDeviceSubClass == USB_ACM_SUBCLASS_CODE)
		&&(p_desc_info->dev_desc.bDeviceProtocol == USB_ACM_PROTOCOL_CODE))||
		((p_desc_info->dev_desc.bDeviceClass == USB_COMPOSITE_DEVICE_CODE)&&(p_desc_info->dev_desc.bDeviceSubClass == USB_COMPOSITE_SUBCLASS_CODE)
		&&(p_desc_info->dev_desc.bDeviceProtocol == USB_COMPOSITE_PROTOCOL_CODE)))
	{
		/* Find data interface since only data interface has endpoints' information */
		if((p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_interface_desc->bInterfaceClass == USB_ACM_DATA_INTERFACE_CLASS_CODE)
			&& (p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_interface_desc->bInterfaceSubClass == USB_ACM_DATA_INTERFACE_SUBCLASS_CODE)
			&& (p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_interface_desc->bInterfaceProtocol == USB_ACM_DATA_INTERFACE_PROTOCOL_CODE))
		{
			b_match = KAL_TRUE;

			/* Check endpoint */
			for(index = 0; index < p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->ep_number; index++)
			{
				if(((p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_ep_info[index]->p_stdep->bEndpointAddress&USB_EP_DIR) == USB_EP_DIR_IN)
					&& (p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_ep_info[index]->p_stdep->bmAttributes == USB_EP_BULK))
				{
					g_UsbHostAcm.ep_rx_info.ep_num = p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_ep_info[index]->p_stdep->bEndpointAddress&(~USB_EP_DIR);
					g_UsbHostAcm.ep_rx_info.ep_max_pkt_size = p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_ep_info[index]->p_stdep->wMaxPacketSize[0]
								+ (p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_ep_info[index]->p_stdep->wMaxPacketSize[1]<<8);

					/* endpoint initialize check FIFO size and endpont number */
					if(g_UsbHostAcm.ep_rx_info.ep_num > MAX_RX_EP_NUM)
						b_match = KAL_FALSE;
				}
				else if(((p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_ep_info[index]->p_stdep->bEndpointAddress & USB_EP_DIR) == USB_EP_DIR_OUT)
					&& (p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_ep_info[index]->p_stdep->bmAttributes == USB_EP_BULK))
				{
					g_UsbHostAcm.ep_tx_info.ep_num = p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_ep_info[index]->p_stdep->bEndpointAddress&(~USB_EP_DIR);
					g_UsbHostAcm.ep_tx_info.ep_max_pkt_size = p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_ep_info[index]->p_stdep->wMaxPacketSize[0]
								+ (p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_ep_info[index]->p_stdep->wMaxPacketSize[1]<<8);


					if(g_UsbHostAcm.ep_tx_info.ep_num > MAX_TX_EP_NUM)
						b_match = KAL_FALSE;
				}
			}
		}
	}

	return b_match;
}


static void USB_Host_Acm_Startup(kal_uint8 usb_ip_port, USBD_Desc_Info *p_desc_info, kal_uint32 cfg_num, kal_uint32 if_num)
{
	/* Write the test code here */

	if(((USBD_Is_High_Speed(g_UsbHostAcm.common_info) == KAL_TRUE)&&(g_UsbHostAcm.ep_rx_info.ep_max_pkt_size > USB_EP_BULK_MAXP_HS))
		||((USBD_Is_High_Speed(g_UsbHostAcm.common_info) == KAL_FALSE)&&(g_UsbHostAcm.ep_rx_info.ep_max_pkt_size > USB_EP_BULK_MAXP_FS)))
	{
		EXT_ASSERT(0, USBD_Is_High_Speed(g_UsbHostAcm.common_info), g_UsbHostAcm.ep_rx_info.ep_max_pkt_size, 0);
	}

	
	if(((USBD_Is_High_Speed(g_UsbHostAcm.common_info) == KAL_TRUE)&&(g_UsbHostAcm.ep_tx_info.ep_max_pkt_size > USB_EP_BULK_MAXP_HS))
		||((USBD_Is_High_Speed(g_UsbHostAcm.common_info) == KAL_FALSE)&&(g_UsbHostAcm.ep_tx_info.ep_max_pkt_size > USB_EP_BULK_MAXP_FS)))
	{
		EXT_ASSERT(0, USBD_Is_High_Speed(g_UsbHostAcm.common_info), g_UsbHostAcm.ep_rx_info.ep_max_pkt_size, 0);
	}
	
}


static void USB_Host_Acm_Detach(kal_uint8 usb_ip_port)
{
	// for test
//	volatile static kal_uint32 detach_count = 0;


//	detach_count++;
}

static void USB_Host_Acm_Suspend(kal_uint8 usb_ip_port)
{


}


static void USB_Host_Acm_Resume(kal_uint8 usb_ip_port)
{


}


USBD_ClassDriver_Struct USB_Host_Acm_Drv = 
{
	USB_Host_Acm_Match,
	USB_Host_Acm_Startup,
	USB_Host_Acm_Detach,
	USB_Host_Acm_Suspend,
	USB_Host_Acm_Resume
};


#endif /* __USB_HOST_COM_PORT_SUPPORT__ */

#endif  /* __OTG_ENABLE__ */




