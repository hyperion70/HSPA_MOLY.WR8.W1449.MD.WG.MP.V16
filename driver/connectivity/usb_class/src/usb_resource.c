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
 *    usb_resource.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  This file implements usb resource management
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
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifdef __USB_ENABLE__

#include "drv_comm.h"
//////#include "app_buff_alloc.h"
//#include "gpt_sw.h"
#include "usb_comm.h"
//#include "usb_drv.h"
#include "usb.h"
#include "usb_adap.h"
#include "usb_resource.h"
#include "usb_custom.h"
#ifdef WEBCAM_SUPPORT
#include "usbvideo_drv.h"
#endif
#include "usb_custom_def.h"
#ifdef __OTG_ENABLE__
#include "usb_mode.h"
#endif

#ifdef __USB_MASS_STORAGE_ENABLE__
#include "usbms_adap.h"
#include "usbms_drv.h"

#endif

////#include "kal_release.h"
#include "kal_public_api.h"
#include "kal_general_types.h"


extern kal_bool INT_USBBoot(void);
extern kal_bool is_init_log_enable;
extern kal_bool is_init_stage;
extern kal_uint8 USB_TEST_Buffer[USBMS_MAX_BUFFERSIZE];


#if defined(__MTK_TARGET__)
__attribute__((aligned(4)))
#endif
 static const kal_uint16 USB_Language_String[] = 
{
	0x0304,
	0x0409
};

static const kal_uint8 devdscr[]=
{
	// Standard Device Descriptor
   	USB_DEVDSC_LENGTH,   		//bLength
   	USB_DEVICE,					//bDescriptorType
	0x10, /* USB spec rev is 1.1 */ 	//bcdUSB		
	0x01, /* USB spec rev is 1.1 */	//bcdUSB
	0x00,						//bDeviceClass
	0x00,						//bDeviceSubClass
	0x00,						//bDeviceProtocol
	USB_EP0_MAXP, /* USB_EP0_MAXP == 8 or 64*/ //bMaxPacketSize0
	(kal_uint8)(MTK_USB_VID),				//idVendor
	(kal_uint8)(MTK_USB_VID>>8),				//idVendor
	0x00,						//idProduct
	0x00,						//idProduct
	(kal_uint8)(USB_DEVDSC_BCDDEVICE_PHONE),	//bcdDevice
	(kal_uint8)(USB_DEVDSC_BCDDEVICE_PHONE>>8),	//bcdDevice
	0x00,						//iManufacturer
	0x00,						//iProduct
	0x00,						//iSerialNumber
	0x01 //USB_DEVDSC_CONFIGS			//bNumConfigurations
};

static const kal_uint8 cfgdscr[]=
{
	/* Initialise the descriptors for main configuration 1 */
	USB_CFGDSC_LENGTH,			//bLength
	USB_CONFIG, 				//bDescriptorType
	0x00,						//wTotalLength
	0x00,						//wTotalLength
	0x00,						//bNumInterfaces
	0x01,  /*the value = (cfg index+1), select this config's number*/  //bConfigurationValue
	0x00,						//iConfiguration
	USB_CFGDSC_ATTR_NATURE, 	//bmAttributes
	USB_CFGDSC_MAXPOWER 		//bMaxPower
};



#ifdef __OTG_ENABLE__
static const kal_uint8 otgdscr[]=
{
 	 USB_OTGDSC_LENGTH,			//bLength
	 USB_OTG_DESC,				//bDescriptorType
	 (USB_OTG_HNP_SUPPORT | USB_OTG_SRP_SUPPORT)	//bAttribute
};
#endif	


#ifdef __USB_HS_ENABLE__
static const kal_uint8 dev_qual_dscr[]=
{
	/* Initialise the Standard Device_Qualiifier Descriptor */
	USB_DEV_QUA_DSC_LENGTH,		//bLength
	USB_DEVICE_QUALIFIER,		//bDescriptorType
	0x00, /* USB spec rev is 2.0 */	//bcdUSB
	0x02, /* USB spec rev is 2.0 */	//bcdUSB
	0x00,						//bDeviceClass
	0x00,						//bDeviceSubClass
	0x00,						//bDeviceProtocol
	USB_EP0_MAXP,/* USB_EP0_MAXP == 64*///bMaxPacketSize0
	0x00,						//bNumConfigurations
	0x00						//bReserved
};

static const kal_uint8 other_speed_cfg_dscr[]=
{
	/* Initialise the descriptors for other speed configuration */
	USB_OTHER_CFGDSC_LENGTH,	//bLength
	USB_OTHER_SPEED,			//bDescriptorType
	0x00,						//wTotalLength
	0x00,						//wTotalLength
	0x00,						//bNumInterfaces
	0x01,   /*the value = (cfg index+1), select this config's number*/ //bConfigurationValue
	0x00,						//iConfiguration
	0x00,						//bmAttributes
	0x00						//MaxPower
};		
#endif



/* interface specific create and init functions */
static Usb_IfCreate_Info usb_ifcreate_tbl[USB_MAX_INTERFACE];
static kal_uint8 usb_ifcreate_number = 0;
/* device code */
static Usb_Device_Code usb_device_code;

/* static functions */
static void USB_Resource_Reset(void);
#ifndef __USB_COMPOSITE_NO_SERIAL__
#ifdef __USB_MASS_STORAGE_ENABLE__
static kal_bool USB_Is_Default_Serial_Number(void);
#endif
#endif

/* Register class specific create functions, class specific create function should create interface descriptor */
void USB_Register_CreateFunc(kal_char* if_name, usb_create_if_func_ptr if_create_func, usb_void_func if_init_func,
				usb_void_func if_enable_func, usb_speed_if_func_ptr if_speed_func, usb_void_func if_resume_func)
{
	if((usb_ifcreate_number >= USB_MAX_INTERFACE)||(if_create_func == NULL)||(if_init_func == NULL)||(if_enable_func == NULL)||(if_speed_func == NULL))
		ASSERT(0);
//		EXT_ASSERT(0, (kal_uint32)usb_ifcreate_number, (kal_uint32)if_create_func, (kal_uint32)if_init_func);

	usb_ifcreate_tbl[usb_ifcreate_number].if_name_ptr = if_name;
	usb_ifcreate_tbl[usb_ifcreate_number].if_create_func = if_create_func;
	usb_ifcreate_tbl[usb_ifcreate_number].if_init_func = if_init_func;
	usb_ifcreate_tbl[usb_ifcreate_number].if_enable_func = if_enable_func;
#ifdef __USB_HS_ENABLE__
	usb_ifcreate_tbl[usb_ifcreate_number].if_speed_func = if_speed_func;
#endif
	usb_ifcreate_tbl[usb_ifcreate_number].if_resume_func = if_resume_func;
	usb_ifcreate_number++;	
}


/* Register class specific device and product code */
void USB_Register_Device_Code(kal_uint8 device_code, kal_uint8 subclass_code, 
									kal_uint8 protocol_code, kal_uint16 product_code)
{
	if (usb_device_code.b_registerd == KAL_TRUE)
		ASSERT(0);
	
	usb_device_code.device_code = device_code;
	usb_device_code.subclass_code = subclass_code;
	usb_device_code.protocol_code = protocol_code;
	usb_device_code.product_code= product_code;
	usb_device_code.b_registerd= KAL_TRUE;
}


/* Deregister class specific create functions,class specific device and product code should be called when cable plug out */
void USB_DeRegister_CreateFunc(void)
{
	usb_ifcreate_number = 0;
	usb_device_code.b_registerd = KAL_FALSE;		
}


/* Deregister class specific device and product code, should be called when cable plug out */
//void USB_DeRegister_Device_Code(void)
//{
//	usb_device_code.b_registerd = KAL_FALSE;	
//}

static void USB_Check_Ep_Number()
{
	if((gUsbDevice.resource_ep_intr_tx_number > USB_MAX_EP_INTR_TX)
		||(gUsbDevice.resource_ep_bulk_tx_number > USB_MAX_EP_BULK_TX)		
		||((gUsbDevice.resource_ep_bulk_tx_number+gUsbDevice.resource_ep_intr_tx_number) >MAX_TX_EP_NUM)	
		||(gUsbDevice.resource_ep_bulk_rx_number > USB_MAX_EP_BULK_RX))
	{	
		ASSERT(0);
	}
}

static void USB_Check_Descriptor()
{
	if((gUsbDevice.resource_interface_number > USB_MAX_INTERFACE)
		||(gUsbDevice.resource_string_number > USB_MAX_STRING)
		||(gUsbDevice.resource_iad_number > USB_MAX_IAD))
	{
		ASSERT(0);
	}
}
 


/* Get interrupt TX endpoint number and endpoint info pointer */
Usb_Ep_Info* USB_Get_Intr_Ep(kal_uint8 *p_num)
{
	/* Interrupt number assign from max */
	*p_num = MAX_TX_EP_NUM-gUsbDevice.resource_ep_intr_tx_number;
	gUsbDevice.resource_ep_intr_tx_number++;

//	if((gUsbDevice.resource_ep_intr_tx_number > USB_MAX_EP_INTR_TX)||
//		((gUsbDevice.resource_ep_bulk_tx_number+gUsbDevice.resource_ep_intr_tx_number) >MAX_TX_EP_NUM))
//	{
//		EXT_ASSERT(0, (kal_uint32)gUsbDevice.resource_ep_intr_tx_number, USB_MAX_EP_INTR_TX, 0);
//	}

	USB_Check_Ep_Number();

	return (&gUsbDevice.ep_intr_tx_info[gUsbDevice.resource_ep_intr_tx_number-1]);
}


/* Get bulk TX endpoint number and endpoint info pointer */
Usb_Ep_Info* USB_Get_Bulk_Tx_Ep(kal_uint8 *p_num)
{
#ifdef __USB_EP_TEST__
	gUsbDevice.resource_ep_bulk_tx_number = 2;
	*p_num = gUsbDevice.resource_ep_bulk_tx_number;
	return (&gUsbDevice.ep_bulk_tx_info[gUsbDevice.resource_ep_bulk_tx_number - 1]);
#else
	gUsbDevice.resource_ep_bulk_tx_number++;

//	if((gUsbDevice.resource_ep_bulk_tx_number > USB_MAX_EP_BULK_TX)||
//		((gUsbDevice.resource_ep_bulk_tx_number+gUsbDevice.resource_ep_intr_tx_number) >MAX_TX_EP_NUM))
//	{
//		EXT_ASSERT(0, (kal_uint32)gUsbDevice.resource_ep_bulk_tx_number, USB_MAX_EP_BULK_TX, 0);
//	}

	USB_Check_Ep_Number();

	*p_num = gUsbDevice.resource_ep_bulk_tx_number;
	return (&gUsbDevice.ep_bulk_tx_info[gUsbDevice.resource_ep_bulk_tx_number - 1]);
#endif
}


/* get bulk RX endpoint number and endpoint info pointer */
Usb_Ep_Info* USB_Get_Bulk_Rx_Ep(kal_uint8 *p_num)
{
#ifdef __USB_EP_TEST__
	gUsbDevice.resource_ep_bulk_rx_number = 2;
	*p_num = gUsbDevice.resource_ep_bulk_rx_number;
	return (&gUsbDevice.ep_bulk_rx_info[gUsbDevice.resource_ep_bulk_rx_number - 1]);
#else
	gUsbDevice.resource_ep_bulk_rx_number++;

//	if(gUsbDevice.resource_ep_bulk_rx_number > USB_MAX_EP_BULK_RX)
//	{
//		EXT_ASSERT(0, (kal_uint32)gUsbDevice.resource_ep_bulk_rx_number, USB_MAX_EP_BULK_RX, 0);
//	}
	USB_Check_Ep_Number();

	*p_num = gUsbDevice.resource_ep_bulk_rx_number;
	return (&gUsbDevice.ep_bulk_rx_info[gUsbDevice.resource_ep_bulk_rx_number - 1]);
#endif
}

#ifdef  __USB_SUPPORT_ISO_PIPE__
/* get ISO TX endpoint number and endpoint info pointer */
Usb_Ep_Info* USB_Get_Iso_Tx_Ep(kal_uint8 *p_num)
{
#ifdef __USB_EP_TEST__
	gUsbDevice.resource_ep_iso_tx_number = 2;
	*p_num = gUsbDevice.resource_ep_iso_tx_number;
	return (&gUsbDevice.ep_iso_tx_info[gUsbDevice.resource_ep_iso_tx_number - 1]);
#else
	gUsbDevice.resource_ep_iso_tx_number++;

	if(gUsbDevice.resource_ep_iso_tx_number > USB_MAX_EP_ISO_TX)
		ASSERT(0);

	*p_num = gUsbDevice.resource_ep_iso_tx_number;
	return (&gUsbDevice.ep_iso_tx_info[gUsbDevice.resource_ep_iso_tx_number - 1]);
#endif
}
#endif  /*  __USB_SUPPORT_ISO_PIPE__ */


#if  defined(__USB_SUPPORT_ISO_PIPE__)||defined(__MBIM_SUPPORT__)||defined(__ECM_SUPPORT__)
/* register interface alternate setting number */
Usb_Alternate_Interface_Info* USB_Get_Interface_Alternate_Setting(kal_uint8 p_num)
{
	gUsbDevice.resource_interface_alternate_number[p_num]++;

//	ASSERT(gUsbDevice.resource_interface_alternate_number[p_num] <= USB_MAX_INTERFACE_ALTERNATE_NUM)
		
	if(gUsbDevice.resource_interface_alternate_number[p_num] > USB_MAX_INTERFACE_ALTERNATE_NUM)
		ASSERT(0);

	gUsbDevice.if_info[p_num].alternate_setting = gUsbDevice.resource_interface_alternate_number[p_num];
//	*p_setting = gUsbDevice.resource_interface_alternate_number[p_num];
	return (&gUsbDevice.if_info[p_num].alternate_if_info[gUsbDevice.resource_interface_alternate_number[p_num] -1]);
}
#endif /*defined(__USB_SUPPORT_ISO_PIPE__)||defined(__MBIM_SUPPORT__)*/

/* Get interface number and interface info pointer */
Usb_Interface_Info* USB_Get_Interface_Number(kal_uint8 *p_num)
{
	gUsbDevice.resource_interface_number++;

//	ASSERT(gUsbDevice.resource_interface_number <= USB_MAX_INTERFACE);
	
	USB_Check_Descriptor();

	*p_num = gUsbDevice.resource_interface_number - 1;
	return (&gUsbDevice.if_info[gUsbDevice.resource_interface_number - 1]);
}


/* Get string number and point device recource_string to real string pointer */
kal_uint8 USB_Get_String_Number(void *usb_string)
{
	Usb_String_Dscr *string = (Usb_String_Dscr *)usb_string;
	gUsbDevice.resource_string_number++;

//	ASSERT(gUsbDevice.resource_string_number <= USB_MAX_STRING);

	USB_Check_Descriptor();
	
	gUsbDevice.resource_string[gUsbDevice.resource_string_number - 1] = string;
	return (gUsbDevice.resource_string_number - 1);
}

#ifndef __USB_COMPOSITE_NO_SERIAL__
#ifdef __USB_MASS_STORAGE_ENABLE__
/* Get string number and point device recource_string to real string pointer */
static kal_bool USB_Is_Default_Serial_Number(void)
{
	kal_uint32	i;
	
	/* check if it is default serial_number */			

	for(i=1; i<USB_SERIAL_STRING_LEN; i++)
	{
		if(gUsbDevice.serial_string[i] != 0x66)
		{
			return KAL_FALSE;
		}
	}		
	return KAL_TRUE;
}
#endif
#endif

Usb_IAD_Dscr* USB_Get_IAD_Number(void)
{
	gUsbDevice.resource_iad_number++;

//	ASSERT(gUsbDevice.resource_iad_number <= USB_MAX_IAD);
	
	USB_Check_Descriptor();

//	*p_num = gUsbDevice.resource_iad_number - 1;
	return (&gUsbDevice.iad_desc[gUsbDevice.resource_iad_number - 1]);
}

#ifndef __MBIM_SUPPORT__
/* Create all descriptors, including device and class specific */
void USB_Software_Create(void)
{
	kal_uint32  index_if = 0;
	kal_uint32  index_ep;
	kal_uint32  if_len = 0;
	


#if  defined(__USB_SUPPORT_ISO_PIPE__)||defined(__MBIM_SUPPORT__)||defined(__ECM_SUPPORT__)
	kal_uint32  index_if_setting;
#endif

	/* initial resource number */
	USB_Resource_Reset();

	
	kal_mem_cpy(&(gUsbDevice.devdscr), devdscr, USB_DEVDSC_LENGTH);
	kal_mem_cpy(&(gUsbDevice.cfgdscr), cfgdscr, USB_CFGDSC_LENGTH);
	

	/* string descriptor */
	USB_Get_String_Number((void *)USB_Language_String);   /*  index 0 */

	/* check class has registered create function and device code */
	if((usb_ifcreate_number == 0) || (usb_device_code.b_registerd == KAL_FALSE))
		ASSERT(0);
//		EXT_ASSERT(0, (kal_uint32)usb_ifcreate_number, (kal_uint32)usb_device_code.b_registerd, 0);

	/* call the create function for each class */
	for(index_if=0; index_if<usb_ifcreate_number; index_if++)
	{
//		if(usb_ifcreate_tbl[index_if].if_create_func == NULL)
//			ASSERT(0);
		
		if(usb_ifcreate_tbl[index_if].if_create_func != NULL)	
		usb_ifcreate_tbl[index_if].if_create_func(usb_ifcreate_tbl[index_if].if_name_ptr);

		if((gUsbDevice.if_info[index_if].ifdscr_size == 0)||(usb_ifcreate_tbl[index_if].if_create_func == NULL))
			ASSERT(0);
	}

	/* Initialise the Standard Device Descriptor */

	/* Get IP version */
//	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_GET_IP_VERSION, (DCL_CTRL_DATA_T  *)&dcl_data);

	if(USB_IP_Version() == DCL_USB_IP_V3)
	{
		gUsbDevice.devdscr.bcdUSB = 0x0200; /* USB spec rev is 2.0 */
	}

	gUsbDevice.devdscr.bDeviceClass = usb_device_code.device_code;
	gUsbDevice.devdscr.bDeviceSubClass = usb_device_code.subclass_code;
	gUsbDevice.devdscr.bDeviceProtocol = usb_device_code.protocol_code;
	gUsbDevice.devdscr.idProduct = usb_device_code.product_code;

	/* For PC side tool to differentiate phone or modem card */
	if (USBDL_Mode_Type()== USBDL_MODE_FAST_META)//(USBDL_Is_USB_Fast_Meta_Mode() == KAL_TRUE)
	{
		gUsbDevice.devdscr.bcdDevice = 0x0900;
	}
	else
	{
		#ifdef  __USB_MODEM_CARD_SUPPORT__
		#ifdef __NDIS_SUPPORT__
		gUsbDevice.devdscr.bcdDevice = USB_DEVDSC_BCDDEVICE_MODEM_CARD_FOR_NDIS;
		#else	
		gUsbDevice.devdscr.bcdDevice = USB_DEVDSC_BCDDEVICE_MODEM_CARD;
		#endif
		#else
		gUsbDevice.devdscr.bcdDevice = USB_DEVDSC_BCDDEVICE_PHONE;
		#endif
	}
	
	gUsbDevice.devdscr.iManufacturer = USB_Get_String_Number((void *)gUsbDevice.device_param->manufacture_string);
	gUsbDevice.devdscr.iProduct = USB_Get_String_Number((void *)gUsbDevice.device_param->product_string);

	/* Serial string is got during initialization procedure */
	if((gUsbDevice.device_type == USB_CDC_ACM)||(gUsbDevice.device_type == USB_CDC_ACM_LOGGING)||(USB_Check_Composite_With_COM(gUsbDevice.device_type) == KAL_TRUE))
	{
		#ifndef __USB_COMPOSITE_NO_SERIAL__
		#ifdef __USB_MASS_STORAGE_ENABLE__
		if(gUsbDevice.device_type == USB_COMPOSITE_DEVICES)
		{
			if((USB_Ms_Get_Max_LUN() != USBMS_INVALID_MAX_LUN) && (USB_Ms_Get_Max_LUN() != 0))
			{				
		  	 	if(USB_Is_Default_Serial_Number() == KAL_FALSE)
				{
		  			gUsbDevice.devdscr.iSerialNumber = USB_Get_String_Number((void *)gUsbDevice.serial_string);
				}
			}
		}
		#endif
		#endif
		/* No serial number */
	}
	else
	{
		gUsbDevice.devdscr.iSerialNumber = USB_Get_String_Number((void *)gUsbDevice.serial_string);
	}

	if((gUsbDevice.device_type == USB_IMAGE) || (USB_Check_Composite_With_COM(gUsbDevice.device_type)== KAL_TRUE))
	{
		gUsbDevice.devdscr.bNumConfigurations = 1;
	}
	else
	{
		gUsbDevice.devdscr.bNumConfigurations = gUsbDevice.current_table_index+1; // add self power
	}


	/* Initialise the descriptors for main configuration 1 */
	gUsbDevice.cfgdscr.bNumInterfaces = gUsbDevice.resource_interface_number;

	if(gUsbDevice.remoteWk == KAL_TRUE)
		gUsbDevice.cfgdscr.bmAttributes |= USB_CFGDSC_ATTR_REMOTEWAKEUP;

//	if(gUsbDevice.self_powered == KAL_TRUE)
//		gUsbDevice.cfgdscr.bmAttributes |= USB_CFGDSC_ATTR_SELFPOWER;

	gUsbDevice.cfgdscr.bMaxPower = gUsbDevice.multi_Max_Power[0];

#ifdef __OTG_ENABLE__
	kal_mem_cpy(&(gUsbDevice.otgdscr), otgdscr, USB_OTGDSC_LENGTH);
//	if(g_UsbMode.usb_boot == KAL_FALSE)
//	{
//		gUsbDevice.otgdscr.bLength = USB_OTGDSC_LENGTH;
//		gUsbDevice.otgdscr.bDescriptorType = USB_OTG_DESC;
//		gUsbDevice.otgdscr.bAttribute = (USB_OTG_HNP_SUPPORT | USB_OTG_SRP_SUPPORT);
//	}	
#endif	

	/* Configuration length */
	for(index_if = 0; index_if < gUsbDevice.resource_iad_number; index_if++)
	{
		if_len += gUsbDevice.iad_desc[index_if].bLength;
	}
	
	for(index_if = 0; index_if < gUsbDevice.resource_interface_number; index_if++)
	{
		if_len += gUsbDevice.if_info[index_if].ifdscr_size;

		for(index_ep = 0; index_ep<gUsbDevice.if_info[index_if].ifdscr.stdif.bNumEndpoints; index_ep++)
		{
			if_len += gUsbDevice.if_info[index_if].ep_info[index_ep]->epdscr_size;
		}

	#if  defined(__USB_SUPPORT_ISO_PIPE__)||defined(__MBIM_SUPPORT__)||defined(__ECM_SUPPORT__)
		/* interface alternate settings */
		for(index_if_setting = 0; index_if_setting < gUsbDevice.if_info[index_if].alternate_setting; index_if_setting++)
		{
			if_len += gUsbDevice.if_info[index_if].alternate_if_info[index_if_setting].ifdscr_size;

			for(index_ep = 0; index_ep < gUsbDevice.if_info[index_if].alternate_if_info[index_if_setting].stdif.bNumEndpoints; index_ep++)
			{
				if_len += gUsbDevice.if_info[index_if].alternate_if_info[index_if_setting].ep_info[index_ep]->epdscr_size;
			}
		}
	#endif
	}

#ifdef __OTG_ENABLE__
	if(g_UsbMode.usb_boot == KAL_FALSE)
		gUsbDevice.cfgdscr.wTotalLength = (USB_CFGDSC_LENGTH + if_len + USB_OTGDSC_LENGTH);
	else
		gUsbDevice.cfgdscr.wTotalLength = (USB_CFGDSC_LENGTH + if_len);
#else
	gUsbDevice.cfgdscr.wTotalLength = (USB_CFGDSC_LENGTH + if_len);
#endif
	/* allocate configuration descriptor memory */
	if (gUsbDevice.conf == NULL)
		gUsbDevice.conf = (kal_uint8 *)USB_Get_Memory(1024);//(kal_uint8 *)USB_TEST_Buffer;	

#ifdef __USB_HS_ENABLE__
	/* Initialise the Standard Device_Qualiifier Descriptor */
	kal_mem_cpy(&(gUsbDevice.dev_qual_dscr), dev_qual_dscr, USB_DEV_QUA_DSC_LENGTH);

   	gUsbDevice.dev_qual_dscr.bDeviceClass = usb_device_code.device_code;
	gUsbDevice.dev_qual_dscr.bDeviceSubClass = usb_device_code.subclass_code; 
	gUsbDevice.dev_qual_dscr.bDeviceProtocol = usb_device_code.protocol_code;
	gUsbDevice.dev_qual_dscr.bNumConfigurations = gUsbDevice.devdscr.bNumConfigurations;

	/* Initialise the descriptors for other speed configuration */
	kal_mem_cpy(&(gUsbDevice.other_speed_cfg_dscr), other_speed_cfg_dscr, USB_OTHER_CFGDSC_LENGTH);

	gUsbDevice.other_speed_cfg_dscr.wTotalLength = gUsbDevice.cfgdscr.wTotalLength;
	gUsbDevice.other_speed_cfg_dscr.bNumInterfaces = gUsbDevice.cfgdscr.bNumInterfaces;
	gUsbDevice.other_speed_cfg_dscr.iConfiguration = 0;
	gUsbDevice.other_speed_cfg_dscr.bmAttributes = gUsbDevice.cfgdscr.bmAttributes;
	gUsbDevice.other_speed_cfg_dscr.MaxPower = gUsbDevice.cfgdscr.bMaxPower;
#else
	USB_Software_Speed_Init(KAL_FALSE);
#endif
}


void USB_Software_Speed_Init(kal_bool b_other_speed)
{
	kal_uint32  index_if = 0;
	kal_uint32  index_ep;
	kal_uint32  index_iad;
	kal_uint32  Conf_index;
#ifdef __USB_HS_ENABLE__
	kal_uint32  index;
#endif
#if  defined(__USB_SUPPORT_ISO_PIPE__)||defined(__MBIM_SUPPORT__)||defined(__ECM_SUPPORT__)
	kal_uint32  index_if_setting;
#endif

	if((usb_ifcreate_number == 0)||(gUsbDevice.conf == NULL))
		ASSERT(0);


#ifdef __USB_HS_ENABLE__
	/* decide EP is high speed or full speed descriptors */
	for(index = 0; index < usb_ifcreate_number; index++)
	{
		if(usb_ifcreate_tbl[index].if_speed_func != NULL)
			usb_ifcreate_tbl[index].if_speed_func(b_other_speed);
		else
			ASSERT(0);
	}
#endif



	/* re-construct configuration descriptor */
	/* kal_mem_cpy(dst,src,len) */
#ifdef __USB_HS_ENABLE__
	if(b_other_speed == KAL_FALSE)
	{
		kal_mem_cpy((kal_uint8 *)(gUsbDevice.conf), (kal_uint8*)&gUsbDevice.cfgdscr, USB_CFGDSC_LENGTH);
		Conf_index = USB_CFGDSC_LENGTH;
	}
	else
	{
		kal_mem_cpy((kal_uint8 *)(gUsbDevice.conf), (kal_uint8*)&gUsbDevice.other_speed_cfg_dscr, USB_OTHER_CFGDSC_LENGTH);
		Conf_index = USB_OTHER_CFGDSC_LENGTH;
	}
#else
	kal_mem_cpy((kal_uint8 *)(gUsbDevice.conf), (kal_uint8*)&gUsbDevice.cfgdscr, USB_CFGDSC_LENGTH);
	Conf_index = USB_CFGDSC_LENGTH;
#endif

	if(gUsbDevice.resource_iad_number == 0)
	{
		/* No IAD, not VIDEO nor composite, either */
		for(index_if = 0; index_if < gUsbDevice.resource_interface_number; index_if++)
		{
			kal_mem_cpy((kal_uint8 *)(gUsbDevice.conf + Conf_index), (kal_uint8*)&gUsbDevice.if_info[index_if].ifdscr.stdif,
				gUsbDevice.if_info[index_if].ifdscr_size);
			Conf_index += gUsbDevice.if_info[index_if].ifdscr_size;

			for(index_ep = 0; index_ep < gUsbDevice.if_info[index_if].ifdscr.stdif.bNumEndpoints; index_ep++)
			{
				kal_mem_cpy((kal_uint8 *)(gUsbDevice.conf + Conf_index), (kal_uint8 *)&(gUsbDevice.if_info[index_if].ep_info[index_ep]->epdesc.stdep),
					gUsbDevice.if_info[index_if].ep_info[index_ep]->epdscr_size);
				Conf_index += gUsbDevice.if_info[index_if].ep_info[index_ep]->epdscr_size;
			}
		}
	}
	else
	{
		for(index_iad = 0; index_iad < gUsbDevice.resource_iad_number; index_iad++)
		{
			kal_mem_cpy((kal_uint8 *)(gUsbDevice.conf + Conf_index), (kal_uint8*)&gUsbDevice.iad_desc[index_iad], gUsbDevice.iad_desc[index_iad].bLength);
			Conf_index += gUsbDevice.iad_desc[index_iad].bLength;

			for(index_if = gUsbDevice.iad_desc[index_iad].bFirstInterface;
				index_if < (gUsbDevice.iad_desc[index_iad].bFirstInterface + gUsbDevice.iad_desc[index_iad].bInterfaceCount); index_if++)
			{
		#ifdef WEBCAM_SUPPORT
				if((gUsbDevice.if_info[index_if].ifdscr.stdif.bInterfaceClass == USBVIDEO_CC_VIDEO)
					&&(gUsbDevice.if_info[index_if].ifdscr.stdif.bInterfaceSubClass == USBVIDEO_SC_VIDEOSTREAMING)
					&&(gUsbDevice.if_info[index_if].ifdscr.stdif.bInterfaceProtocol == USBVIDEO_PC_PROTOCOL_UNDEFINED))
				{
					/* Modify in order to pass USB UVC compliance test tool */
					kal_mem_cpy((kal_uint8 *)(gUsbDevice.conf + Conf_index),
						(kal_uint8*)&gUsbDevice.if_info[index_if].ifdscr.stdif, USB_IFDSC_LENGTH);
					Conf_index += USB_IFDSC_LENGTH;

					for(index_ep = 0; index_ep < gUsbDevice.if_info[index_if].ifdscr.stdif.bNumEndpoints; index_ep++)
					{
						kal_mem_cpy((kal_uint8 *)(gUsbDevice.conf + Conf_index),
							(kal_uint8 *)&(gUsbDevice.if_info[index_if].ep_info[index_ep]->epdesc.stdep),
								gUsbDevice.if_info[index_if].ep_info[index_ep]->epdscr_size);
						Conf_index += gUsbDevice.if_info[index_if].ep_info[index_ep]->epdscr_size;
					}

					kal_mem_cpy((kal_uint8 *)(gUsbDevice.conf + Conf_index),
						(kal_uint8 *)(((kal_uint32)&gUsbDevice.if_info[index_if].ifdscr.stdif)+USB_IFDSC_LENGTH),
						gUsbDevice.if_info[index_if].ifdscr_size-USB_IFDSC_LENGTH);

					Conf_index += gUsbDevice.if_info[index_if].ifdscr_size-USB_IFDSC_LENGTH;

			#ifdef  __USB_SUPPORT_ISO_PIPE__
					/* interface alternate settings */
					for(index_if_setting = 0; index_if_setting < gUsbDevice.if_info[index_if].alternate_setting; index_if_setting++)
					{
						/* Modify in order to pass USB UVC compliance test tool */
						kal_mem_cpy((kal_uint8 *)(gUsbDevice.conf + Conf_index),
							(kal_uint8*)&gUsbDevice.if_info[index_if].alternate_if_info[index_if_setting].stdif,
							USB_IFDSC_LENGTH);
						Conf_index += USB_IFDSC_LENGTH;

						for(index_ep = 0; index_ep < gUsbDevice.if_info[index_if].alternate_if_info[index_if_setting].stdif.bNumEndpoints; index_ep++)
						{
							kal_mem_cpy((kal_uint8 *)(gUsbDevice.conf + Conf_index),
								(kal_uint8 *)&(gUsbDevice.if_info[index_if].alternate_if_info[index_if_setting].ep_info[index_ep]->epdesc.stdep),
								gUsbDevice.if_info[index_if].alternate_if_info[index_if_setting].ep_info[index_ep]->epdscr_size);
							Conf_index += gUsbDevice.if_info[index_if].alternate_if_info[index_if_setting].ep_info[index_ep]->epdscr_size;
						}
		/*
						kal_mem_cpy((kal_uint8 *)(gUsbDevice.conf + Conf_index),
							(kal_uint8 *)(((kal_uint32)&gUsbDevice.if_info[index_if].alternate_if_info[index_if_setting].stdif)+USB_IFDSC_LENGTH),
							gUsbDevice.if_info[index_if].alternate_if_info[index_if_setting].ifdscr_size-USB_IFDSC_LENGTH);
						Conf_index += gUsbDevice.if_info[index_if].alternate_if_info[index_if_setting].ifdscr_size-USB_IFDSC_LENGTH;
		*/
					}
			#endif
				}
				else
		#endif	/* WEBCAM_SUPPORT */
				{
					kal_mem_cpy((kal_uint8 *)(gUsbDevice.conf + Conf_index), (kal_uint8*)&gUsbDevice.if_info[index_if].ifdscr.stdif,
						gUsbDevice.if_info[index_if].ifdscr_size);
					Conf_index += gUsbDevice.if_info[index_if].ifdscr_size;

					for(index_ep = 0; index_ep < gUsbDevice.if_info[index_if].ifdscr.stdif.bNumEndpoints; index_ep++)
					{
						kal_mem_cpy((kal_uint8 *)(gUsbDevice.conf + Conf_index), (kal_uint8 *)&(gUsbDevice.if_info[index_if].ep_info[index_ep]->epdesc.stdep),
							gUsbDevice.if_info[index_if].ep_info[index_ep]->epdscr_size);
						Conf_index += gUsbDevice.if_info[index_if].ep_info[index_ep]->epdscr_size;
					}

		#if defined(__MBIM_SUPPORT__)||defined(__ECM_SUPPORT__)
					/* interface alternate settings */
					for(index_if_setting = 0; index_if_setting < gUsbDevice.if_info[index_if].alternate_setting; index_if_setting++)
					{
						kal_mem_cpy((kal_uint8 *)(gUsbDevice.conf + Conf_index),
							(kal_uint8*)&gUsbDevice.if_info[index_if].alternate_if_info[index_if_setting].stdif,
							gUsbDevice.if_info[index_if].alternate_if_info[index_if_setting].ifdscr_size);
						Conf_index += gUsbDevice.if_info[index_if].alternate_if_info[index_if_setting].ifdscr_size;

						for(index_ep = 0; index_ep < gUsbDevice.if_info[index_if].alternate_if_info[index_if_setting].stdif.bNumEndpoints; index_ep++)
						{
							kal_mem_cpy((kal_uint8 *)(gUsbDevice.conf + Conf_index),
								(kal_uint8 *)&(gUsbDevice.if_info[index_if].alternate_if_info[index_if_setting].ep_info[index_ep]->epdesc.stdep),
								gUsbDevice.if_info[index_if].alternate_if_info[index_if_setting].ep_info[index_ep]->epdscr_size);
							Conf_index += gUsbDevice.if_info[index_if].alternate_if_info[index_if_setting].ep_info[index_ep]->epdscr_size;
						}
					}
		#endif
				}
			}
		}
		
#ifdef __USB_MODEM_CARD_SUPPORT__
		
		for(; index_if < gUsbDevice.resource_interface_number; index_if++)
		{
			kal_mem_cpy((kal_uint8 *)(gUsbDevice.conf + Conf_index), (kal_uint8*)&gUsbDevice.if_info[index_if].ifdscr.stdif,
				gUsbDevice.if_info[index_if].ifdscr_size);
			Conf_index += gUsbDevice.if_info[index_if].ifdscr_size;

			for(index_ep = 0; index_ep < gUsbDevice.if_info[index_if].ifdscr.stdif.bNumEndpoints; index_ep++)
			{
					kal_mem_cpy((kal_uint8 *)(gUsbDevice.conf + Conf_index), (kal_uint8 *)&(gUsbDevice.if_info[index_if].ep_info[index_ep]->epdesc.stdep),
						gUsbDevice.if_info[index_if].ep_info[index_ep]->epdscr_size);
					Conf_index += gUsbDevice.if_info[index_if].ep_info[index_ep]->epdscr_size;
				}
		}
#endif
	}

#ifdef __OTG_ENABLE__	
	if(g_UsbMode.usb_boot == KAL_FALSE)
	{
		kal_mem_cpy((kal_uint8 *)(gUsbDevice.conf + Conf_index), (kal_uint8*)&gUsbDevice.otgdscr, USB_OTGDSC_LENGTH);
		Conf_index+=USB_OTGDSC_LENGTH;
	}	
#endif
	ASSERT(Conf_index == gUsbDevice.cfgdscr.wTotalLength);
}


#else
void USB_Software_Create(void)
{
	kal_uint32  index_if = 0;
//	kal_uint32  index_ep;
//	kal_uint32  if_len = 0;
	
	/* initial resource number */
	USB_Resource_Reset();
	kal_mem_cpy(&(gUsbDevice.devdscr), devdscr, USB_DEVDSC_LENGTH);
	kal_mem_cpy(&(gUsbDevice.cfgdscr), cfgdscr, USB_CFGDSC_LENGTH);
	

	/* string descriptor */
	USB_Get_String_Number((void *)USB_Language_String);   /*  index 0 */

	/* check class has registered create function and device code */
	if((usb_ifcreate_number == 0) || (usb_device_code.b_registerd == KAL_FALSE))
		ASSERT(0);
//		EXT_ASSERT(0, (kal_uint32)usb_ifcreate_number, (kal_uint32)usb_device_code.b_registerd, 0);

	/* call the create function for each class */
	for(index_if=0; index_if<usb_ifcreate_number; index_if++)
	{
//		if(usb_ifcreate_tbl[index_if].if_create_func == NULL)
//			ASSERT(0);
		
		if(usb_ifcreate_tbl[index_if].if_create_func != NULL)	
		usb_ifcreate_tbl[index_if].if_create_func(usb_ifcreate_tbl[index_if].if_name_ptr);

		if((gUsbDevice.if_info[index_if].ifdscr_size == 0)||(usb_ifcreate_tbl[index_if].if_create_func == NULL))
			ASSERT(0);
	}

	/* Initialise the Standard Device Descriptor */

	/* Get IP version */
//	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_GET_IP_VERSION, (DCL_CTRL_DATA_T  *)&dcl_data);

	if(USB_IP_Version() == DCL_USB_IP_V3)
	{
		gUsbDevice.devdscr.bcdUSB = 0x0200; /* USB spec rev is 2.0 */
	}

	gUsbDevice.devdscr.bDeviceClass = usb_device_code.device_code;
	gUsbDevice.devdscr.bDeviceSubClass = usb_device_code.subclass_code;
	gUsbDevice.devdscr.bDeviceProtocol = usb_device_code.protocol_code;
	gUsbDevice.devdscr.idProduct = usb_device_code.product_code;

	/* For PC side tool to differentiate phone or modem card */
	if (USBDL_Mode_Type()== USBDL_MODE_FAST_META)//(USBDL_Is_USB_Fast_Meta_Mode() == KAL_TRUE)
	{
		gUsbDevice.devdscr.bcdDevice = 0x0900;
	}
	else
	{
		#ifdef  __USB_MODEM_CARD_SUPPORT__
		#ifdef __NDIS_SUPPORT__
		gUsbDevice.devdscr.bcdDevice = USB_DEVDSC_BCDDEVICE_MODEM_CARD_FOR_NDIS;
		#else	
		gUsbDevice.devdscr.bcdDevice = USB_DEVDSC_BCDDEVICE_MODEM_CARD;
		#endif
		#else
		gUsbDevice.devdscr.bcdDevice = USB_DEVDSC_BCDDEVICE_PHONE;
		#endif
	}
	
	gUsbDevice.devdscr.iManufacturer = USB_Get_String_Number((void *)gUsbDevice.device_param->manufacture_string);
	gUsbDevice.devdscr.iProduct = USB_Get_String_Number((void *)gUsbDevice.device_param->product_string);

	/* Serial string is got during initialization procedure */
	if((gUsbDevice.device_type == USB_CDC_ACM)||(gUsbDevice.device_type == USB_CDC_ACM_LOGGING)||(USB_Check_Composite_With_COM(gUsbDevice.device_type) == KAL_TRUE))
	{
		#ifndef __USB_COMPOSITE_NO_SERIAL__
		#ifdef __USB_MASS_STORAGE_ENABLE__
		if(((USB_Ms_Get_Max_LUN() != USBMS_INVALID_MAX_LUN) && (USB_Ms_Get_Max_LUN() != 0)) || (gUsbDevice.device_type == USB_MORPHING_MBIM))
		{				
	  	 	if(USB_Is_Default_Serial_Number() == KAL_FALSE)
			{
	  			gUsbDevice.devdscr.iSerialNumber = USB_Get_String_Number((void *)gUsbDevice.serial_string);
			}
		}
		#endif
		#endif
		/* No serial number */
	}
	else
	{
		gUsbDevice.devdscr.iSerialNumber = USB_Get_String_Number((void *)gUsbDevice.serial_string);
	}

	if((gUsbDevice.device_type == USB_IMAGE) || (USB_Check_Composite_With_COM(gUsbDevice.device_type)== KAL_TRUE))
	{
		#ifdef __MBIM_SUPPORT__
			if (gUsbDevice.device_type == USB_MORPHING_MBIM)
			{
				gUsbDevice.devdscr.bNumConfigurations = gUsbDevice.morph_cfg_num;
			}
		#else
			gUsbDevice.devdscr.bNumConfigurations = 1;		
		#endif
	}
	else
	{
		gUsbDevice.devdscr.bNumConfigurations = gUsbDevice.current_table_index+1; // add self power
	}
	
}

void USB_Configuration_Setup(kal_uint8 cfg_num)
{
	kal_uint32  index_if = 0;
	kal_uint32  index_iad = 0;
	kal_uint32  index_ep;
	kal_uint32  if_len = 0;	
	/* Initialise the descriptors for main configuration 1 */
#if  defined(__MBIM_SUPPORT__)
		kal_uint32	index_if_setting;
#endif

	if(gUsbDevice.remoteWk == KAL_TRUE)
		gUsbDevice.cfgdscr.bmAttributes |= USB_CFGDSC_ATTR_REMOTEWAKEUP;

	gUsbDevice.cfgdscr.bMaxPower = gUsbDevice.multi_Max_Power[0];

	/* update Morphing cfg */
	 if(gUsbDevice.device_type == USB_MORPHING_MBIM) // for MBIM + Mass storage
	 {
	 	if((cfg_num == 1) && (gUsbDevice.morph_active == KAL_FALSE))
	 	{
			cfg_num = 0;  
			//the mac os 10.7.4 will select config1 , not config2 directly.. 
			//so if mac select config1 and identity is not successful , let us set config1 as cd_rom only
	 	}	
		gUsbDevice.cfgdscr.bNumInterfaces = gUsbDevice.morph_interface_num[cfg_num];
		/* Configuration length */
		for(index_if = 0; index_if < gUsbDevice.cfgdscr.bNumInterfaces; index_if++)
		{
			for(index_iad = 0; index_iad < gUsbDevice.resource_iad_number; index_iad++)
			{
				if(index_if == gUsbDevice.iad_desc[index_iad].bFirstInterface)
				{
					if_len += gUsbDevice.iad_desc[index_iad].bLength;
					break;
				}
			}
		}
	 }	
	 else
	 {
		/* Configuration length */
		for(index_if = 0; index_if < gUsbDevice.resource_iad_number; index_if++)
		{
			if_len += gUsbDevice.iad_desc[index_if].bLength;
		}
		gUsbDevice.cfgdscr.bNumInterfaces = gUsbDevice.resource_interface_number;
	 }

	/* update cfg function description */ 
 	for(index_if = 0; index_if < gUsbDevice.cfgdscr.bNumInterfaces; index_if++)
	{
		if_len += gUsbDevice.if_info[index_if].ifdscr_size;

		for(index_ep = 0; index_ep<gUsbDevice.if_info[index_if].ifdscr.stdif.bNumEndpoints; index_ep++)
		{
			if_len += gUsbDevice.if_info[index_if].ep_info[index_ep]->epdscr_size;
		}

	#if  defined(__USB_SUPPORT_ISO_PIPE__)||defined(__MBIM_SUPPORT__)||defined(__ECM_SUPPORT__)
		/* interface alternate settings */
		for(index_if_setting = 0; index_if_setting < gUsbDevice.if_info[index_if].alternate_setting; index_if_setting++)
		{
			if_len += gUsbDevice.if_info[index_if].alternate_if_info[index_if_setting].ifdscr_size;

			for(index_ep = 0; index_ep < gUsbDevice.if_info[index_if].alternate_if_info[index_if_setting].stdif.bNumEndpoints; index_ep++)
			{
				if_len += gUsbDevice.if_info[index_if].alternate_if_info[index_if_setting].ep_info[index_ep]->epdscr_size;
			}
		}
	#endif
	}
	gUsbDevice.cfgdscr.wTotalLength = (USB_CFGDSC_LENGTH + if_len);
	
	/* allocate configuration descriptor memory */
	if (gUsbDevice.conf == NULL)
		gUsbDevice.conf = (kal_uint8 *)USB_Get_Memory(1024);//(kal_uint8 *)USB_TEST_Buffer;	
 
	#ifdef __USB_HS_ENABLE__
		 /* Initialise the Standard Device_Qualiifier Descriptor */
		 kal_mem_cpy(&(gUsbDevice.dev_qual_dscr), dev_qual_dscr, USB_DEV_QUA_DSC_LENGTH);

		 gUsbDevice.dev_qual_dscr.bDeviceClass = usb_device_code.device_code;
		 gUsbDevice.dev_qual_dscr.bDeviceSubClass = usb_device_code.subclass_code; 
		 gUsbDevice.dev_qual_dscr.bDeviceProtocol = usb_device_code.protocol_code;
		 gUsbDevice.dev_qual_dscr.bNumConfigurations = gUsbDevice.devdscr.bNumConfigurations;
 
		 /* Initialise the descriptors for other speed configuration */
		 kal_mem_cpy(&(gUsbDevice.other_speed_cfg_dscr), other_speed_cfg_dscr, USB_OTHER_CFGDSC_LENGTH);
	 
		 gUsbDevice.other_speed_cfg_dscr.wTotalLength = gUsbDevice.cfgdscr.wTotalLength;
		 gUsbDevice.other_speed_cfg_dscr.bNumInterfaces = gUsbDevice.cfgdscr.bNumInterfaces;
		 gUsbDevice.other_speed_cfg_dscr.iConfiguration = 0;
		 gUsbDevice.other_speed_cfg_dscr.bmAttributes = gUsbDevice.cfgdscr.bmAttributes;
		 gUsbDevice.other_speed_cfg_dscr.MaxPower = gUsbDevice.cfgdscr.bMaxPower;
	#else
		 USB_Software_Speed_Init(KAL_FALSE,0);
	#endif	
}

	/* re-construct configuration descriptor */
	/* kal_mem_cpy(dst,src,len) */
void USB_Software_Speed_Init(kal_bool b_other_speed, kal_uint8 cfg_num)
{
	kal_uint32  index_if = 0;
	kal_uint32  index_ep;
	kal_uint32  index_iad;
	kal_uint32  Conf_index;
#ifdef __USB_HS_ENABLE__
	kal_uint32  index;
#endif
#if  defined(__USB_SUPPORT_ISO_PIPE__)||defined(__MBIM_SUPPORT__)||defined(__ECM_SUPPORT__)
	kal_uint32  index_if_setting;
#endif

	if((usb_ifcreate_number == 0)||(gUsbDevice.conf == NULL))
		ASSERT(0);


#ifdef __USB_HS_ENABLE__
	/* decide EP is high speed or full speed descriptors */
	for(index = 0; index < usb_ifcreate_number; index++)
	{
		if(usb_ifcreate_tbl[index].if_speed_func != NULL)
			usb_ifcreate_tbl[index].if_speed_func(b_other_speed);
		else
			ASSERT(0);
	}
#endif

#ifdef __USB_HS_ENABLE__
	if(b_other_speed == KAL_FALSE)
	{
		kal_mem_cpy((kal_uint8 *)(gUsbDevice.conf), (kal_uint8*)&gUsbDevice.cfgdscr, USB_CFGDSC_LENGTH);
		Conf_index = USB_CFGDSC_LENGTH;
	}
	else
	{		
		kal_mem_cpy((kal_uint8 *)(gUsbDevice.conf), (kal_uint8*)&gUsbDevice.other_speed_cfg_dscr, USB_OTHER_CFGDSC_LENGTH);
		Conf_index = USB_OTHER_CFGDSC_LENGTH;
	}
#else
	kal_mem_cpy((kal_uint8 *)(gUsbDevice.conf), (kal_uint8*)&gUsbDevice.cfgdscr, USB_CFGDSC_LENGTH);
	Conf_index = USB_CFGDSC_LENGTH;
#endif

		for(index_if = 0; index_if < gUsbDevice.cfgdscr.bNumInterfaces; index_if++)
		{
			for( index_iad = 0; index_iad < gUsbDevice.resource_iad_number; index_iad++)
			{
				if(index_if == gUsbDevice.iad_desc[index_iad].bFirstInterface)
				{
					kal_mem_cpy((kal_uint8 *)(gUsbDevice.conf + Conf_index), (kal_uint8*)&gUsbDevice.iad_desc[index_iad], gUsbDevice.iad_desc[index_iad].bLength);
					Conf_index += gUsbDevice.iad_desc[index_iad].bLength;
					break;
				}
			}			
			
			kal_mem_cpy((kal_uint8 *)(gUsbDevice.conf + Conf_index), (kal_uint8*)&gUsbDevice.if_info[index_if].ifdscr.stdif,
				gUsbDevice.if_info[index_if].ifdscr_size);
			Conf_index += gUsbDevice.if_info[index_if].ifdscr_size;

			for(index_ep = 0; index_ep < gUsbDevice.if_info[index_if].ifdscr.stdif.bNumEndpoints; index_ep++)
			{
				kal_mem_cpy((kal_uint8 *)(gUsbDevice.conf + Conf_index), (kal_uint8 *)&(gUsbDevice.if_info[index_if].ep_info[index_ep]->epdesc.stdep),
					gUsbDevice.if_info[index_if].ep_info[index_ep]->epdscr_size);
				Conf_index += gUsbDevice.if_info[index_if].ep_info[index_ep]->epdscr_size;
			}

		#if defined(__MBIM_SUPPORT__)||defined(__ECM_SUPPORT__)
			/* interface alternate settings */
			for(index_if_setting = 0; index_if_setting < gUsbDevice.if_info[index_if].alternate_setting; index_if_setting++)
			{
				kal_mem_cpy((kal_uint8 *)(gUsbDevice.conf + Conf_index),
				(kal_uint8*)&gUsbDevice.if_info[index_if].alternate_if_info[index_if_setting].stdif,
				gUsbDevice.if_info[index_if].alternate_if_info[index_if_setting].ifdscr_size);
				Conf_index += gUsbDevice.if_info[index_if].alternate_if_info[index_if_setting].ifdscr_size;
				for(index_ep = 0; index_ep < gUsbDevice.if_info[index_if].alternate_if_info[index_if_setting].stdif.bNumEndpoints; index_ep++)
				{
			 		kal_mem_cpy((kal_uint8 *)(gUsbDevice.conf + Conf_index),
					(kal_uint8 *)&(gUsbDevice.if_info[index_if].alternate_if_info[index_if_setting].ep_info[index_ep]->epdesc.stdep),
					gUsbDevice.if_info[index_if].alternate_if_info[index_if_setting].ep_info[index_ep]->epdscr_size);
					Conf_index += gUsbDevice.if_info[index_if].alternate_if_info[index_if_setting].ep_info[index_ep]->epdscr_size;
				}
			}
#endif			
			
		}
	ASSERT(Conf_index == gUsbDevice.cfgdscr.wTotalLength);
}	
#endif

/* init EP of each interface (class specific) */
void USB_Software_Init(void)
{
	kal_uint32 index;


	for(index = 0; index < usb_ifcreate_number; index++)
	{
		if(usb_ifcreate_tbl[index].if_init_func != NULL)
			usb_ifcreate_tbl[index].if_init_func();
		else
			ASSERT(0);
	}
}

/* resume EP of each interface (class specific) */
void USB_Software_Resume(void)
{
	kal_uint32 index;
	for(index = 0; index < usb_ifcreate_number; index++)
	{
		if(usb_ifcreate_tbl[index].if_resume_func != NULL)
			usb_ifcreate_tbl[index].if_resume_func();
	}
}


/* init EP of each interface (class specific) */
void USB_Software_Enable(void)
{
	kal_uint32 index;


	for(index = 0; index < usb_ifcreate_number; index++)
	{
		if(usb_ifcreate_tbl[index].if_enable_func != NULL)
			usb_ifcreate_tbl[index].if_enable_func();
		else
			ASSERT(0);
	}
}


/* Reset the resource maintain in this file */
static void USB_Resource_Reset(void)
{
	kal_uint32 temp_addr, temp_addr2;
	temp_addr = (kal_uint32)&gUsbDevice.resource_ep_bulk_tx_number;
	temp_addr2 = (kal_uint32)&gUsbDevice.resource_iad_number;

	
	kal_mem_set(&gUsbDevice.resource_ep_bulk_tx_number, 0, temp_addr2 - temp_addr);

/*	
#ifdef  __USB_SUPPORT_ISO_PIPE__
	kal_uint32 	index;
#endif

	gUsbDevice.resource_ep_bulk_tx_number = 0;
   	gUsbDevice.resource_ep_bulk_rx_number = 0;
   	gUsbDevice.resource_ep_intr_tx_number = 0;
   	gUsbDevice.resource_interface_number = 0;
#ifdef  __USB_SUPPORT_ISO_PIPE__
	gUsbDevice.resource_ep_iso_tx_number = 0;

	for(index = 0; index < USB_MAX_INTERFACE; index++)
		gUsbDevice.resource_interface_alternate_number[index] = 0;
#endif
	gUsbDevice.resource_string_number = 0;
	gUsbDevice.resource_iad_number = 0;
*/	
}


#endif /* __USB_ENABLE__ */

