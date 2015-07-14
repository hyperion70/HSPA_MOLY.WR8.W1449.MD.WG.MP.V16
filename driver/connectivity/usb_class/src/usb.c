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
 *    usb.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements usb1.1 driver
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef __USB_ENABLE__

#include "drv_comm.h"
//#include "stack_common.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "kal_public_api.h" //#include "kal_public_api.h" //#include "stack_ltlcom.h" //MSBB change #include "app_ltlcom.h"       /* Task message communiction */
///#include "syscomp_config.h"
///#include "task_config.h"
///#include "stacklib.h"
//#include "reg_base.h"
#include "drvsignals.h"
#include "init.h"

///#include "app_buff_alloc.h"
//#include "drvpdn.h"
#include "intrCtrl.h"
//#include "gpio_sw.h"

#include "usb_comm.h"
//#include "usb_drv.h"
#include "dcl.h"
#include "usb.h"
#include "usb_adap.h"
#include "usb_resource.h"
#ifdef __USB_MASS_STORAGE_ENABLE__
#include "usbms_drv.h"
#endif
#include "usbacm_drv.h"
#ifdef WEBCAM_SUPPORT
#include "usbvideo_drv.h"
#endif
#include "usb_custom.h"
#include "usb_debug_tool.h"
#include "usb_trc.h"
#include "usb_memory_def.h"
//#include "usb_msdisk.h"
//#include "fs_type.h"
//#include "fs_func.h"
#include "usb_task.h"


#ifdef __OTG_ENABLE__
#include "otg.h"
//#include "otg_drv.h"
#endif
#include "usb_mode.h"
#ifdef __USB_IMAGE_CLASS__
#include "usbimage_drv.h"
#endif


#ifdef __MULTI_BOOT__
#include "multiboot_config.h"
//MSBB remove #include "fctycomp_config.h"
#endif /* __MULTI_BOOT__ */

#ifdef __USB_STRESS_TEST__
#include "usbacm_echo.h"
#endif


///#include "kal_release.h"
#include "drv_features.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "kal_public_api.h" //#include "stack_ltlcom.h"
#include "uart_sw.h"
#include "kal_trace.h"
#include "kal_public_api.h"
#include "kal_general_types.h"

#include "drv_msgid.h"	

/* Device structure, handle usb level data */
Usb_Device gUsbDevice;
static kal_uint32 g_usb_mask_owner = 0;
#if !(defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
static kal_uint32 g_usb_mask_count = 0;
static kal_bool g_usb_mask_en = KAL_FALSE;
static kal_uint32 g_usb_mask_cnt[USB_MASK_OWNER_MAX];
#endif


DCL_HANDLE g_USB_Dcl_Handle = 0;

/* Exception flag */
extern kal_uint8 INT_Exception_Enter;
#if defined(__USB_BOOTUP_TRACE__)
extern kal_bool is_init_log_enable;
extern kal_bool is_init_stage;
#endif //__USB_BOOTUP_TRACE__
extern kal_uint8 g_usb_logging_port_num;

extern void DRV_RESET(void);

#if defined(__USB_MODEM_CARD_SUPPORT__)
extern void USB_Release_Type(kal_bool b_enable, kal_bool b_plugout);
#endif



/* static fuctions */
static void USB_Init_Device_Status(void);
static void USB_Reset(void);
static void USB_Disable_Charging(void);
static void USB_Suspend(void);
static void USB_Resume(void);
static void USB_Initialize(kal_bool double_fifo);
static kal_bool USB_Cmd_SetAddress(Usb_Ep0_Status *pep0state, Usb_Command *pcmd);
static kal_bool USB_Cmd_GetDescriptor(Usb_Ep0_Status *pep0state, Usb_Command *pcmd);
static kal_bool USB_Cmd_SetConfiguration(Usb_Ep0_Status *pep0state, Usb_Command *pcmd);
static kal_bool USB_Cmd_GetConfiguration(Usb_Ep0_Status *pep0state, Usb_Command *pcmd);
static kal_bool USB_Cmd_SetFeature(Usb_Command *pcmd, kal_bool bset);
static kal_bool USB_Cmd_GetStatus(Usb_Ep0_Status *pep0state, Usb_Command *pcmd);
static void USB_Stdcmd(Usb_Ep0_Status *pep0state, Usb_Command *pcmd);
static void USB_Endpoint0_Idle (void);
static void USB_Endpoint0_Rx(void);
static void USB_Endpoint0_Tx(void);
static void USB_Endpoint0_Hdlr(void);




/************************************************************
	Utilities functions
*************************************************************/
/*
USB_DEVICE_STATE USB_Get_Device_State(void)
{
	return gUsbDevice.nDevState;
}


void USB_Set_Device_State(USB_DEVICE_STATE usb_device_state)
{
	gUsbDevice.nDevState = usb_device_state;
}


USB_DEVICE_TYPE USB_Get_Device_Type(void)
{
	return gUsbDevice.device_type;
}


void USB_Set_Device_Type(USB_DEVICE_TYPE usb_device_type)
{
	gUsbDevice.device_type = usb_device_type;
}


USB_EP0_STATE USB_Get_Endpoint0_State(void)
{
	return gUsbDevice.ep0_state;
}


void USB_Set_Endpoint0_State(USB_EP0_STATE ep0_state)
{
	gUsbDevice.ep0_state = ep0_state;
}



USB_Comport_Boot_Status USB_Get_Comport_Boot_Status(void)
{
	return g_UsbMode.usb_comport_boot;
}

*/


/************************************************************
	gUsbDevice initialize and release functions
*************************************************************/

/* initialize the  global variable gUsbDevice */
static void USB_Init_Device_Status(void)
{
	kal_uint32 	index = 0;

	kal_uint32 temp_addr = (kal_uint32)&gUsbDevice.resource_ep_bulk_tx_number;
	kal_uint32 temp_addr2 = (kal_uint32)&gUsbDevice.conf;


// clear resource parameter
// clear descriptor descriptor
//	temp_addr = (kal_uint32)&gUsbDevice.resource_ep_bulk_tx_number;
//	temp_addr2 = (kal_uint32)&gUsbDevice.conf;

	kal_mem_set(&gUsbDevice.resource_ep_bulk_tx_number, 0, temp_addr2 - temp_addr);
/*
	gUsbDevice.resource_ep_bulk_tx_number = 0;
	gUsbDevice.resource_ep_bulk_rx_number = 0;
	gUsbDevice.resource_ep_intr_tx_number = 0;
	gUsbDevice.resource_interface_number = 0;
	gUsbDevice.resource_string_number = 0;
*/

/*
	kal_mem_set(&gUsbDevice.cfgdscr, 0, sizeof(Usb_Cfg_Dscr));

	for( index = 0; index < USB_MAX_INTERFACE; index++)
	{
		kal_mem_set(&gUsbDevice.if_info[index], 0, sizeof(Usb_Interface_Info));
	}

	for( index = 0; index < USB_MAX_EP_BULK_TX; index++)
	{
		kal_mem_set(&gUsbDevice.ep_bulk_tx_info[index], 0, sizeof(Usb_Ep_Info));
	}

	for( index = 0; index < USB_MAX_EP_BULK_RX; index++)
	{
		kal_mem_set(&gUsbDevice.ep_bulk_rx_info[index], 0, sizeof(Usb_Ep_Info));
	}

	for( index = 0; index < USB_MAX_EP_INTR_TX; index++)
	{
		kal_mem_set(&gUsbDevice.ep_intr_tx_info[index], 0, sizeof(Usb_Ep_Info));
	}

	for( index = 0; index < USB_MAX_STRING; index++)
	{
		gUsbDevice.resource_string[index] = NULL;
	}

*/

#ifdef __USB_HS_ENABLE__
	gUsbDevice.usb_test_type = USB_TEST_MODE_TYPE_NONE;
#endif
	gUsbDevice.device_type = USB_UNKOWN;
#if defined(DRV_USB_REMOTE_WAKEUP_SUPPORT)
	gUsbDevice.remoteWk = KAL_TRUE;
#else
	gUsbDevice.remoteWk = KAL_FALSE;
#endif	
#if defined(__DUAL_TALK_MODEM_SUPPORT__)   
	gUsbDevice.isRemoteWking = KAL_FALSE;	
#endif
	gUsbDevice.self_powered = KAL_FALSE;
	gUsbDevice.config_num = 0;

	for(index = 0; index < USB_MAX_INTERFACE; index++)
		gUsbDevice.interface_num[index] = 0;

	gUsbDevice.ep0_rx_handler = NULL;
	gUsbDevice.ep0_class_cmd_handler.b_enable = KAL_FALSE;

}


/* release the already get memory, and reset some parameter,
    note that hisr should not be reset to NULL since it may already be created*/
void USB_Release_Device_Status(void)
{
//	kal_uint32 	index = 0;
//	gUsbDevice.conf = NULL;

	USB_Init_Device_Status();

/*
	kal_mem_set(&gUsbDevice.cfgdscr, 0, sizeof(Usb_Cfg_Dscr));

	for( index = 0; index < USB_MAX_INTERFACE; index++)
	{
		kal_mem_set(&gUsbDevice.if_info[index], 0, sizeof(Usb_Interface_Info));
	}

	for( index = 0; index < USB_MAX_EP_BULK_TX; index++)
	{
		kal_mem_set(&gUsbDevice.ep_bulk_tx_info[index], 0, sizeof(Usb_Ep_Info));
	}

	for( index = 0; index < USB_MAX_EP_BULK_RX; index++)
	{
		kal_mem_set(&gUsbDevice.ep_bulk_rx_info[index], 0, sizeof(Usb_Ep_Info));
	}

	for( index = 0; index < USB_MAX_EP_INTR_TX; index++)
	{
		kal_mem_set(&gUsbDevice.ep_intr_tx_info[index], 0, sizeof(Usb_Ep_Info));
	}

	for( index = 0; index < USB_MAX_STRING; index++)
	{
		gUsbDevice.resource_string[index] = NULL;
	}

	if(gUsbDevice.conf != NULL)
	{
		free_ctrl_buffer(gUsbDevice.conf);
		gUsbDevice.conf = NULL;
	}
#ifdef __USB_HS_ENABLE__
	gUsbDevice.usb_test_type = USB_TEST_MODE_TYPE_NONE;
#endif
	gUsbDevice.remoteWk = KAL_FALSE;
	gUsbDevice.self_powered = KAL_FALSE;
	gUsbDevice.config_num = 0;

	for(index = 0; index < USB_MAX_INTERFACE; index++)
		gUsbDevice.interface_num[index] = 0;

	gUsbDevice.device_type = USB_UNKOWN;
	gUsbDevice.ep0_rx_handler = NULL;
	gUsbDevice.ep0_class_cmd_handler.b_enable = KAL_FALSE;

	gUsbDevice.resource_ep_bulk_tx_number = 0;
	gUsbDevice.resource_ep_bulk_rx_number = 0;
	gUsbDevice.resource_ep_intr_tx_number = 0;
	gUsbDevice.resource_interface_number = 0;
	gUsbDevice.resource_string_number = 0;
*/	
}



/************************************************************
	EP0 functions
*************************************************************/

/* Register EP0 RX data handler */
//void USB_Register_EP0_RxHdlr(usb_ep0_rx_ptr handler)
//{
//	gUsbDevice.ep0_rx_handler = handler;
//}


void USB_Register_EP0_Class_CmdHdlr(kal_uint8 cmd, usb_ep0_cmd_ptr handler)
{
	gUsbDevice.ep0_class_cmd_handler.cmd = cmd;
	gUsbDevice.ep0_class_cmd_handler.ep0_cmd_hdlr = handler;
	gUsbDevice.ep0_class_cmd_handler.b_enable = KAL_TRUE;
}


/* Prepare TX data infomration for pep0state, data is actually sent out in TX state handler */
void USB_Generate_EP0Data(Usb_Ep0_Status*pep0state, Usb_Command*pcmd, void *data, kal_int32 len)
{
	pep0state->pData = (void*)data;

	pep0state->nBytesLeft = len;
	
	/* Only transmit at most command request */
	if (pcmd->wLength < pep0state->nBytesLeft)
		pep0state->nBytesLeft = pcmd->wLength;
	
	/* No need ZLP when wLength == transfer size */
	if (pcmd->wLength == pep0state->nBytesLeft)
		pep0state->no_ZLP = KAL_TRUE;
	else
		pep0state->no_ZLP = KAL_FALSE;
	
	/* EP0 go to TX state */
	gUsbDevice.ep0_state = USB_EP0_TX;
}


void USB_Send_Msg_Ext_Queue(module_type dstid,msg_type msg_id,void *data)
{
	ilm_struct usb_ilm;
	ilm_struct *pUsb_ilm = &usb_ilm;

	module_type src_mod	= kal_get_active_module_id();

//	src_mod = stack_get_active_module_id();

	DRV_BuildPrimitive(pUsb_ilm, src_mod, dstid, msg_id, data);
	msg_send_ext_queue(pUsb_ilm);
}

/************************************************************
	Memory control APIs
*************************************************************/
kal_uint32 USB_Get_Memory(kal_uint32 len)
{
	kal_uint32 address;

//because com port init in drv_init phase2 (before USB task init)
// can only initialize parameter here.
    if(len & 0xF) 
    {
	  len = (len + 16) & ~(0xF);
	}	  
	
	if ((gUsbDevice.reserved_memory_size == 0) &&(gUsbDevice.memory_addr == 0))
	{
		gUsbDevice.memory_addr = (kal_uint32)USB_BUFFER;
		gUsbDevice.reserved_memory_size = USB_MAX_MEMORY_SIZE;	
	}

	if ((gUsbDevice.reserved_memory_size < len)||(gUsbDevice.memory_addr == 0))
		ASSERT(0);

	USB_Dbg_Trace(USB_MEMORY_GET, (kal_uint32)gUsbDevice.reserved_memory_size,len);
	drv_trace2(TRACE_FUNC, (kal_uint32)USB_GET_MEMORY_ADDR,gUsbDevice.reserved_memory_size,len);

	gUsbDevice.reserved_memory_size = gUsbDevice.reserved_memory_size - len;	
	address = gUsbDevice.memory_addr;
	gUsbDevice.memory_addr = gUsbDevice.memory_addr + len;
	
	return address;
}

void USB_Free_Memory(void)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif	
}


/************************************************************
	system ctrl functions
*************************************************************/
static void USB_Initialize_EP(USB_DEVICE_TYPE type,kal_bool reset)
{
	DCL_BOOL dcl_bl_data = (DCL_BOOL)reset;	
#ifndef __USB_MODEM_CARD_SUPPORT__
	USB_DRV_CTRL_GET_FIFO_SIZE_T dcl_fifo_size;
	DCL_STATUS dcl_status;
#endif

//	USB_Initialize_Drv_Phase2(KAL_FALSE/KAL_TRUE);
//	dcl_bl_data = (DCL_BOOL)reset;	

	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_INITIALIZE_DRV_PHASE_2, (DCL_CTRL_DATA_T  *)&dcl_bl_data);

#ifndef __USB_MODEM_CARD_SUPPORT__
	/* Initialize according to application */
	dcl_status = DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_GET_TOTAL_FIFO_SIZE, (DCL_CTRL_DATA_T  *)&dcl_fifo_size);
	
	if((dcl_fifo_size.fifo_size == DCL_USB_TOTAL_FIFO_SIZE_2304)&&(dcl_status == STATUS_OK)&&(USB_Check_Composite_With_COM(type)== KAL_TRUE))
	{
		/* Only composite device needs to use single FIFO due to FIFO size limitation */
		USB_Initialize(KAL_FALSE);
	}
	else
	{
		USB_Initialize(KAL_TRUE);
	}
#else
	/* Modem Card Use Single FIFO */
	USB_Initialize(KAL_FALSE);
#endif
}

/* Init function, called when user select usb type,
    entry function for task , B_eanble is D+ detection enable */
void USB_Init(USB_DEVICE_TYPE type, kal_bool b_enable, kal_bool is_ft_mode)
{
	DCL_BOOL dcl_bl_data = (DCL_BOOL)is_ft_mode;
#ifdef __OTG_ENABLE__
	USB_DRV_CTRL_PHY_FUNC_T  dcl_data;
#endif
//	USB_DRV_CTRL_GET_FIFO_SIZE_T dcl_fifo_size;
//	DCL_STATUS dcl_status;


//	dcl_bl_data = (DCL_BOOL)is_ft_mode;
	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_INIT_DRV_INFO, (DCL_CTRL_DATA_T  *)&dcl_bl_data);
#if !(defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	g_usb_mask_en = KAL_TRUE;
#endif
//	USB_Init_Drv_Info(is_ft_mode);	/* Initialize driver parameters */


	USB_Init_Device_Status();	/* Initialize global variable gUsbDevice */

	switch (type)
	{
#if defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
	case USB_COMPOSITE_MULTI_COM:
#endif
#ifdef __USB_TETHERING__
	case USB_COMPOSITE_RNDIS_COM:
	case USB_RNDIS:
#endif
//#ifdef __USB_LOGGING__
//	case USB_CDC_ACM_LOGGING:
//#endif
#ifdef __USB_COM_PORT_ENABLE__
	case USB_CDC_ACM:
#if defined (__USB_MODEM_CARD_SUPPORT__)
		USB_Init_Ms_Status();
#endif
		USB_Init_Acm_Status();
		break;
#endif
#ifdef  __USB_MASS_STORAGE_ENABLE__
	case USB_MASS_STORAGE:
		USB_Init_Ms_Status();
		break;
#endif
#ifdef WEBCAM_SUPPORT
	case USB_VIDEO:
		USB_Init_Video_Status();
		break;
		
	case USB_COMPOSITE_VIDEO_COM:
		USB_Init_Video_Status();
		USB_Init_Acm_Status();
		break;
#endif
#ifdef PICTBRIDGE_SUPPORT
	case USB_IMAGE:
		USB_Init_Image_Status();
		USB_Init_PTP_Status();
		USB_Image_Reset_PTP_Hdlr();
		break;
#endif
#ifdef __MTP_ENABLE__
	case USB_IMAGE_MTP:
		USB_Init_Image_Status();
		USB_Init_MTP_Status();
		break;
#endif
	case USB_COMPOSITE_DEVICES:
#if defined (__USB_MODEM_CARD_SUPPORT__)
		USB_Init_Ms_Status();
#endif
		USB_Init_Acm_Status();
		break;
#ifdef __MBIM_SUPPORT__				
#if defined (__USB_MODEM_CARD_SUPPORT__)
	case USB_MORPHING_MBIM:
		USB_Init_Ms_Status();
		USB_Init_Acm_Status();
		break;				
#endif		
#endif
	default:
		EXT_ASSERT(0, (kal_uint32)type, 0, 0);
		break;
	}

	gUsbDevice.device_type = type;
	/* Init the mask */
	g_usb_mask_owner = 0;

	/* Register reset and ep0 interrupt handler to driver info */
	USB_Register_Drv_Info(USB_DRV_HDLR_RESET, 0, USB_Reset);
	USB_Register_Drv_Info(USB_DRV_HDLR_EP0, 0, USB_Endpoint0_Hdlr);
	USB_Register_Drv_Info(USB_DRV_HDLR_SUSPEND, 0, USB_Suspend);
	USB_Register_Drv_Info(USB_DRV_HDLR_RESUME, 0, USB_Resume);

	/* Create USB descriptors */
	USB_Software_Create();

	#ifdef __MBIM_SUPPORT__
		USB_Configuration_Setup(0);
	#endif	

#ifdef __USB_RAMDISK__
	if (type == USB_MASS_STORAGE)
	{
		FAT_Init();
	}
#endif   /*__USB_RAMDISK__*/

#ifdef __USB_COM_PORT_ENABLE__ //__USB_DOWNLOAD__
	/* Because USB IP's registers were already set in bootloader */
	if (USBDL_Mode_Type()!= USBDL_MODE_NONE) //((USBDL_Is_USB_Download_Mode() == KAL_TRUE)||(INT_IsBootForUSBAT() == KAL_TRUE))
	{
		return;
	}
#endif

	if(b_enable == KAL_TRUE)
	{
#ifdef __OTG_ENABLE__
		if(g_UsbMode.b_usb_pdnmode == KAL_TRUE)
		{
			g_UsbMode.b_usb_pdnmode = KAL_FALSE;
			USB_PDNmode(KAL_FALSE);
			OTG_Init_Phase2();
			dcl_data.owner = DCL_USB_PHY_OWNER_USB;
			DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_PHY_ENABLE, (DCL_CTRL_DATA_T  *)&dcl_data);
//			USB_Phy_Enable(USB_PHY_OWNER_USB);
		}
#else
		/* enable USB power, host can detect USB device*/
		USB_PDNmode(KAL_FALSE);
#endif
	}

	/* Reset and initialize system initial value and registers*/
	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_RESET_DRV, NULL);
//	USB_Reset_Drv();  /* reset hw power register */

	USB_Initialize_EP(type,KAL_FALSE);

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

#ifndef __OTG_ENABLE__
	/* LISR should be unmask after all initialize and enable any USB interrupt */
//	USB_Drv_Activate_ISR();
	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_DRV_ACTIVATE_ISR, NULL);

//	USBDMA_Drv_Activate_ISR();
	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_DMA_DRV_ACTIVATE_ISR, NULL);
#endif	/* __OTG_ENABLE__ */

	/* Set D+ to high finally */
	if(b_enable == KAL_TRUE)
	{

#if defined(__DM_LAWMO_SUPPORT__)
		if(g_UsbMode.b_lock_usb_boot == KAL_FALSE)
#endif
		{
			DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_DP_PULL_UP, NULL);
//			USB_Pull_Up_DP_Line();
		}
	}
}


/*
void USB_Release(void)
{

}
*/
void USB_UnMask_USB_CORE(USB_MASK_OWNER owner)
{
	
#if !(defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	kal_uint32 savedMask;
#endif

if(owner >= USB_MASK_OWNER_MAX)
	ASSERT(0);

#if (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	IRQUnmask(IRQ_USB_CODE);
#else	
	savedMask = SaveAndSetIRQMask();
	
	if(g_usb_mask_count > 0)
	   g_usb_mask_count--;	
	else
	   ASSERT(0);	
	
	g_usb_mask_cnt[owner] = g_usb_mask_cnt[owner] - 1;	
	
	//when not active lisr and hisr first , we don't UnMask(USB_CODE) 
	if(g_usb_mask_count == 0)
	{
		if(g_usb_mask_en == KAL_TRUE)
		{
		IRQUnmask(IRQ_USB_CODE);
	}	
	}	
	RestoreIRQMask(savedMask);
#endif	
}

void USB_Mask_USB_CORE(USB_MASK_OWNER owner)
{
#if !(defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	kal_uint32 savedMask;
#endif

if(owner >= USB_MASK_OWNER_MAX)
	ASSERT(0);

#if (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
		IRQMask(IRQ_USB_CODE);
#else
	savedMask = SaveAndSetIRQMask();
	g_usb_mask_cnt[owner] = g_usb_mask_cnt[owner] + 1;
	g_usb_mask_count++;
    IRQMask(IRQ_USB_CODE);
	RestoreIRQMask(savedMask);	
#endif	
}


static void USB_Irq_Control(USB_MASK_OWNER owner,kal_bool unmask)
{
	kal_uint32 savedMask;

	if(owner >= USB_MASK_OWNER_MAX)
		ASSERT(0);
//		EXT_ASSERT(0, (kal_uint32)owner, g_usb_mask_owner, 0);

	if ((g_usb_mask_owner & (1<<(kal_uint32)owner))!= 0) // only print log when owner is changed. => prevent too many debug log.
		USB_Dbg_Trace(USB_UNMASK_IRQ, (kal_uint32)owner, g_usb_mask_owner);

	savedMask = SaveAndSetIRQMask();

	if (unmask == KAL_TRUE)
	{
		g_usb_mask_owner &= ~(1<<(kal_uint32)owner);

		if(g_usb_mask_owner == 0)
			USB_Set_UnMask_Irq(KAL_TRUE);
	}
	else
	{
		if(g_usb_mask_owner == 0)
			USB_Set_UnMask_Irq(KAL_FALSE);
		
		g_usb_mask_owner |= 1<<(kal_uint32)owner;
	}
	RestoreIRQMask(savedMask);

}

void USB_UnMask_Irq(USB_MASK_OWNER owner)
{
	USB_Irq_Control(owner,KAL_TRUE);
/*
	kal_uint32 savedMask;


	if(owner >= USB_MASK_OWNER_MAX)
		EXT_ASSERT(0, (kal_uint32)owner, g_usb_mask_owner, 0);

	if ((g_usb_mask_owner & (1<<(kal_uint32)owner))!= 0) // only print log when owner is changed. => prevent too many debug log.
		USB_Dbg_Trace(USB_UNMASK_IRQ, (kal_uint32)owner, g_usb_mask_owner);

	savedMask = SaveAndSetIRQMask();
	g_usb_mask_owner &= ~(1<<(kal_uint32)owner);

	if(g_usb_mask_owner == 0)
	{
		USB_Set_UnMask_Irq(KAL_TRUE);
	}

	RestoreIRQMask(savedMask);
*/	
}


void USB_Mask_Irq(USB_MASK_OWNER owner)
{
	USB_Irq_Control(owner,KAL_FALSE);
/*
	kal_uint32 savedMask;


	if(owner >= USB_MASK_OWNER_MAX)
		EXT_ASSERT(0, (kal_uint32)owner, g_usb_mask_owner, 0);

	if ((g_usb_mask_owner & (1<<(kal_uint32)owner))== 0) // only print log when owner is changed. => prevent too many debug log.
		USB_Dbg_Trace(USB_MASK_IRQ, (kal_uint32)owner, g_usb_mask_owner);

	savedMask = SaveAndSetIRQMask();

	if(g_usb_mask_owner == 0)
	{
		USB_Set_UnMask_Irq(KAL_FALSE);
	}

	g_usb_mask_owner |= 1<<(kal_uint32)owner;
	RestoreIRQMask(savedMask);
*/	
}


/* Reset device, called when receive reset interrupt */
static void USB_Reset(void)
{
	kal_uint32 ep_num;
//#if defined(__USB_MODEM_CARD_SUPPORT__)
//        volatile kal_uint32 delay;
//#endif  /*__USB_MODEM_CARD_SUPPORT__*/
//	DCL_BOOL dcl_bl_data;
//	USB_DRV_CTRL_GET_FIFO_SIZE_T dcl_fifo_size;
//	DCL_STATUS dcl_status;


//	gUsbDevice.is_configured_now = KAL_FALSE;
	USB_Disable_Charging();

/////////////Add for USB disconnect (USB disable)
//#if defined(__USB_MODEM_CARD_SUPPORT__)
//       if (gUsbDevice.nDevState == DEVSTATE_CONFIG)
//       {
//             USB_Set_UnMask_Irq(KAL_FALSE);
//            USB_Release_Type(KAL_TRUE, KAL_TRUE);
//            for (delay = 0; delay < 250; delay++);
//            DRV_RESET();
//       }
//#endif
///////////////

	// Initialize driver info and system interrupt
	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_RESET_DRV_INFO, NULL);
//	USB_ResetDrv_Info();

	USB_Initialize_EP(gUsbDevice.device_type,KAL_TRUE);

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

	gUsbDevice.nDevState = DEVSTATE_DEFAULT;

	for(ep_num = 0; ep_num < gUsbDevice.resource_ep_bulk_tx_number; ep_num++)
	{
		if(gUsbDevice.ep_bulk_tx_info[ep_num].ep_reset)
			gUsbDevice.ep_bulk_tx_info[ep_num].ep_reset();
	}

	for(ep_num = 0; ep_num < gUsbDevice.resource_ep_bulk_rx_number; ep_num++)
	{
		if(gUsbDevice.ep_bulk_rx_info[ep_num].ep_reset)
			gUsbDevice.ep_bulk_rx_info[ep_num].ep_reset();
	}

	for(ep_num = 0; ep_num < gUsbDevice.resource_ep_intr_tx_number; ep_num++)
	{
		if(gUsbDevice.ep_intr_tx_info[ep_num].ep_reset)
			gUsbDevice.ep_intr_tx_info[ep_num].ep_reset();
	}

#ifdef __OTG_ENABLE__
	OTG_B_EnDis_HNP(KAL_FALSE);
#endif
}


static void USB_Disable_Charging(void)
{
#ifndef __MEUT__
//	ilm_struct *ilm_charge = NULL;
//	bmt_usb_ind_struct *ind;

	/* In assert mode, we cannot send message.
	 * Thus, we just retun.
	 */
	 if (USB_Exception_Check() == KAL_FALSE)//if(INT_Exception_Enter != 0 || (is_init_log_enable == KAL_TRUE && is_init_stage == KAL_TRUE))
		return;
		
	if (USB_Default_Charging() == KAL_TRUE) // force USB charging 
		return;
	
	if((gUsbDevice.config_num != 0)&&(INT_BootMode() != MTK_FACTORY_MODE))
	{
		USB_Send_Msg(USB_SEND_BMT_STOP_CHARGE);
/*		
		ind = (bmt_usb_ind_struct*)construct_local_para(sizeof(bmt_usb_ind_struct), TD_CTRL);

		ind->usb_ind = PMU_CHARGE_CURRENT_0_00_MA;//(PMU_CHR_CURRENT_ENUM)get_chr_current_list.pCurrentList[0];

		USB_Send_Msg_Ext_Queue(ilm_charge, MOD_BMT, MSG_ID_BMT_USB_IND, ind);

		drv_trace2(TRACE_FUNC, (kal_uint32)USB_CONFIG_NUM,gUsbDevice.config_num,gUsbDevice.current_table_index);	
*/		
//		DRV_BuildPrimitive(ilm_charge, MOD_DRV_HISR, MOD_BMT, MSG_ID_BMT_USB_IND, ind);
//		msg_send_ext_queue(ilm_charge);
	}
#endif /* __MEUT__ */
}


static void USB_Suspend(void)
{
#if defined(__DUAL_TALK_MODEM_SUPPORT__)   
	kal_uint32 usb_port;
    kal_uint32 savedMask;
	kal_bool is_need_resume = KAL_FALSE;
	kal_bool remote_wake = KAL_FALSE;
#endif		
	USB_Disable_Charging();
#if defined(__DUAL_TALK_MODEM_SUPPORT__)   
    if(USB_Get_Device_State() == DEVSTATE_CONFIG)
    {		  	  
	  for(usb_port = 0; usb_port < MAX_USB_PORT_NUM; usb_port++)
	  {      
	  	if(((g_UsbACM[usb_port].line_state & CONTROL_LINE_SIGNAL_DTR) == CONTROL_LINE_SIGNAL_DTR))
	  	{
        if((g_UsbACM[usb_port].setup_dma == KAL_TRUE) || 
			(USB_Is_EP_Tx_Empty(g_UsbACM[usb_port].txpipe->byEP,USB_ENDPT_BULK) == KAL_FALSE) ||
			g_UsbACM[usb_port].intr_state != ACM_INTR_IDLE)
        {
          is_need_resume = KAL_TRUE;       
		   break;
        }
	  }
	  }
	  savedMask = SaveAndSetIRQMask();
	  if(gUsbDevice.isRemoteWking == KAL_FALSE)
      {
        if(is_need_resume == KAL_TRUE)
        {
          gUsbDevice.isRemoteWking = KAL_TRUE;
    	  USB_Lock_SleepMode();	
    	  USB_Remote_Wake_UP_Start();			  
        }
		else
		{
		  USB_UnLock_SleepMode();	  
		}
	  }
      RestoreIRQMask(savedMask);    
      drv_trace1(TRACE_FUNC, (kal_uint32)USB_REMOTE_WAKEUP, (kal_uint32)is_need_resume);  	  
    }    	
#endif

#ifdef __USB_IMAGE_CLASS__
	if((gUsbDevice.device_type == USB_IMAGE)||(gUsbDevice.device_type == USB_IMAGE_MTP))
	{
		USB_Image_Suspend_Hdlr();
	}
#endif

/////////////Add for USB disconnect (USB disable)
//#if defined(__USB_MODEM_CARD_SUPPORT__)
//	if(gUsbDevice.nDevState == DEVSTATE_CONFIG)
//	{
//		USB_Release_Type(KAL_TRUE, KAL_TRUE);
//		DRV_RESET();
//	}
//#endif
///////////////
#ifdef	__TC01__
/* under construction !*/
/* under construction !*/
#endif	//__TC01__
}


static void USB_Resume(void)
{
#ifndef __MEUT__
//	ilm_struct *ilm_charge = NULL;
//	bmt_usb_ind_struct *ind;
#if defined(__DUAL_TALK_MODEM_SUPPORT__) 	
    kal_uint32 savedMask;	
#endif
//	DCL_HANDLE pmu_handle;
//	PMU_CTRL_CHR_GET_CHR_CURRENT_LIST get_chr_current_list;

#if defined(__DUAL_TALK_MODEM_SUPPORT__)   
		  savedMask = SaveAndSetIRQMask();	 
		  USB_Lock_SleepMode();		 
		  USB_Remote_Wake_UP_End();		  
          RestoreIRQMask(savedMask); 		  
          gUsbDevice.isRemoteWking = KAL_FALSE;
#endif

	/* In assert mode, we cannot send message.
	 * Thus, we just retun.
	 */
	 if (USB_Exception_Check() == KAL_FALSE)//if(INT_Exception_Enter != 0 || (is_init_log_enable == KAL_TRUE && is_init_stage == KAL_TRUE))
		return;

	if((gUsbDevice.config_num != 0)&&(INT_BootMode() != MTK_FACTORY_MODE))
	{
	
		USB_Send_Msg(USB_SEND_BMT_START_CHARGE);
/*		
		ind = (bmt_usb_ind_struct*)construct_local_para(sizeof(bmt_usb_ind_struct), TD_CTRL);

		if (gUsbDevice.config_num > gUsbDevice.current_table_index)
			ind->usb_ind = PMU_CHARGE_CURRENT_0_00_MA;
		else
			ind->usb_ind = (PMU_CHR_CURRENT_ENUM)gUsbDevice.get_chr_current_list.pCurrentList[gUsbDevice.current_table_index-gUsbDevice.config_num];

		USB_Send_Msg_Ext_Queue(ilm_charge,MOD_BMT, MSG_ID_BMT_USB_IND, ind);

		drv_trace2(TRACE_FUNC, (kal_uint32)USB_CONFIG_NUM,gUsbDevice.config_num,gUsbDevice.current_table_index);
*/		
		
//		DRV_BuildPrimitive(ilm_charge, MOD_DRV_HISR, MOD_BMT, MSG_ID_BMT_USB_IND, ind);
//		msg_send_ext_queue(ilm_charge);
	}
	
	USB_Software_Resume();

#endif /* __MEUT__ */
}


static void USB_TxEPInit(kal_uint32 ep_num, kal_uint16 data_size, USB_ENDPT_TXFER_TYPE type, kal_bool double_fifo)
{
	USB_DRV_CTRL_USB_EP_INIT_T dcl_data;


	dcl_data.u4ep_num = (DCL_UINT32)ep_num;
	dcl_data.u2data_size = (DCL_UINT16)data_size;
	dcl_data.type = (DCL_USB_ENDPT_TXFER_TYPE)type;
	dcl_data.fgdouble_fifo = (DCL_BOOL)double_fifo;
	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_TXEP_INIT, (DCL_CTRL_DATA_T *)&dcl_data);
}


static void USB_RxEPInit(kal_uint32 ep_num, kal_uint16 data_size, USB_ENDPT_TXFER_TYPE type, kal_bool double_fifo)
{
	USB_DRV_CTRL_USB_EP_INIT_T dcl_data;


	dcl_data.u4ep_num = (DCL_UINT32)ep_num;
	dcl_data.u2data_size = (DCL_UINT16)data_size;
	dcl_data.type = (DCL_USB_ENDPT_TXFER_TYPE)type;
	dcl_data.fgdouble_fifo = (DCL_BOOL)double_fifo;
	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_RXEP_INIT, (DCL_CTRL_DATA_T *)&dcl_data);
}


/* initialize system */
static void USB_Initialize(kal_bool double_fifo)
{
	kal_uint32 index_ep;
	kal_uint16 wMaxPacketSize;
	kal_uint32 	index;
	kal_bool	temp_fifo;


//	gUsbDevice.nDevState = DEVSTATE_DEFAULT;
#ifdef __USB_HS_ENABLE__
	/* initial class specific speed-related endpoint, and re-prepare descriptor */
#ifdef __MBIM_SUPPORT__
	USB_Software_Speed_Init(KAL_FALSE,0);
#else
	USB_Software_Speed_Init(KAL_FALSE);
#endif
#endif

	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_RESET_FIFO, NULL);
//	USB_Reset_FIFO();

#ifdef  __USB_EP_TEST__
	for(index_ep = 1; index_ep < gUsbDevice.resource_ep_bulk_tx_number; index_ep++)
	{
//		wMaxPacketSize = (kal_uint8)gUsbDevice.ep_bulk_tx_info[index_ep].epdesc.stdep.wMaxPacketSize[1];
//		wMaxPacketSize <<= 8;
//		wMaxPacketSize |= (kal_uint8)gUsbDevice.ep_bulk_tx_info[index_ep].epdesc.stdep.wMaxPacketSize[0];

		wMaxPacketSize = USB_Bulk_Max_Packet_Size();

		USB_TxEPInit((gUsbDevice.ep_bulk_tx_info[index_ep].epdesc.stdep.bEndpointAddress&(~USB_EP_DIR)),
						wMaxPacketSize, USB_ENDPT_BULK,double_fifo);
		gUsbDevice.ep_bulk_tx_info[index_ep].ep_status.epin_status.nBytesLeft = USB_EP_NODATA;
	}

	for(index_ep = 1; index_ep < gUsbDevice.resource_ep_bulk_rx_number; index_ep++)
	{
//		wMaxPacketSize = (kal_uint8)gUsbDevice.ep_bulk_rx_info[index_ep].epdesc.stdep.wMaxPacketSize[1];
//		wMaxPacketSize <<= 8;
//		wMaxPacketSize |= (kal_uint8)gUsbDevice.ep_bulk_rx_info[index_ep].epdesc.stdep.wMaxPacketSize[0];

		wMaxPacketSize = USB_Bulk_Max_Packet_Size();

		USB_RxEPInit((gUsbDevice.ep_bulk_rx_info[index_ep].epdesc.stdep.bEndpointAddress&(~USB_EP_DIR)),
						wMaxPacketSize, USB_ENDPT_BULK,double_fifo);
		gUsbDevice.ep_bulk_rx_info[index_ep].ep_status.epout_status.nBuffLen = 0;
		gUsbDevice.ep_bulk_rx_info[index_ep].ep_status.epout_status.nBytesRecv = 0;
	}

#ifdef  __USB_SUPPORT_ISO_PIPE__
	for(index_ep = 1; index_ep < gUsbDevice.resource_ep_iso_tx_number; index_ep++)
	{
//		wMaxPacketSize = (kal_uint8)gUsbDevice.ep_iso_tx_info[index_ep].epdesc.stdep.wMaxPacketSize[1];
//		wMaxPacketSize <<= 8;
//		wMaxPacketSize |= (kal_uint8)gUsbDevice.ep_iso_tx_info[index_ep].epdesc.stdep.wMaxPacketSize[0];

		wMaxPacketSize = USB_Iso_Max_Packet_Size();

		USB_TxEPInit((gUsbDevice.ep_iso_tx_info[index_ep].epdesc.stdep.bEndpointAddress&(~USB_EP_DIR)),
						wMaxPacketSize, USB_ENDPT_ISO,double_fifo);
		gUsbDevice.ep_iso_tx_info[index_ep].ep_status.epin_status.nBytesLeft = USB_EP_NODATA;
	}
#endif

#else /* __USB_EP_TEST__ */
	for(index_ep = 0; index_ep < gUsbDevice.resource_ep_bulk_tx_number; index_ep++)
	{
//		wMaxPacketSize = (kal_uint8)gUsbDevice.ep_bulk_tx_info[index_ep].epdesc.stdep.wMaxPacketSize[1];
//		wMaxPacketSize <<= 8;
//		wMaxPacketSize |= (kal_uint8)gUsbDevice.ep_bulk_tx_info[index_ep].epdesc.stdep.wMaxPacketSize[0];

		wMaxPacketSize = USB_Bulk_Max_Packet_Size();

		temp_fifo = (index_ep == 0)?double_fifo:KAL_FALSE;
		#if defined(__USB_MODEM_CARD_SUPPORT__)				
			if(index_ep == 5) temp_fifo = KAL_TRUE;
		#endif
//		if(index_ep == 0)
//			temp_fifo = double_fifo;
//		else
//			temp_fifo = KAL_FALSE;

			USB_TxEPInit((gUsbDevice.ep_bulk_tx_info[index_ep].epdesc.stdep.bEndpointAddress&(~USB_EP_DIR)),
					wMaxPacketSize, USB_ENDPT_BULK, temp_fifo);

		gUsbDevice.ep_bulk_tx_info[index_ep].ep_status.epin_status.nBytesLeft = USB_EP_NODATA;
	}

	for(index_ep = 0; index_ep < gUsbDevice.resource_ep_bulk_rx_number; index_ep++)
	{
//		wMaxPacketSize = (kal_uint8)gUsbDevice.ep_bulk_rx_info[index_ep].epdesc.stdep.wMaxPacketSize[1];
//		wMaxPacketSize <<= 8;
//		wMaxPacketSize |= (kal_uint8)gUsbDevice.ep_bulk_rx_info[index_ep].epdesc.stdep.wMaxPacketSize[0];

		wMaxPacketSize = USB_Bulk_Max_Packet_Size();

		temp_fifo = (index_ep == 0)?double_fifo:KAL_FALSE;
		#if defined(__USB_MODEM_CARD_SUPPORT__)		
			if(index_ep == 5) temp_fifo = KAL_TRUE;
		#endif
//		if(index_ep == 0)
//			temp_fifo = double_fifo;
//		else
//			temp_fifo = KAL_FALSE;

			USB_RxEPInit((gUsbDevice.ep_bulk_rx_info[index_ep].epdesc.stdep.bEndpointAddress&(~USB_EP_DIR)),
					wMaxPacketSize, USB_ENDPT_BULK, temp_fifo);

		gUsbDevice.ep_bulk_rx_info[index_ep].ep_status.epout_status.nBuffLen = 0;
		gUsbDevice.ep_bulk_rx_info[index_ep].ep_status.epout_status.nBytesRecv = 0;
	}
#ifdef  __USB_SUPPORT_ISO_PIPE__
	for(index_ep = 0; index_ep < gUsbDevice.resource_ep_iso_tx_number; index_ep++)
	{
//		wMaxPacketSize = (kal_uint8)gUsbDevice.ep_iso_tx_info[index_ep].epdesc.stdep.wMaxPacketSize[1];
//		wMaxPacketSize <<= 8;
//		wMaxPacketSize |= (kal_uint8)gUsbDevice.ep_iso_tx_info[index_ep].epdesc.stdep.wMaxPacketSize[0];

		wMaxPacketSize = USB_Iso_Max_Packet_Size();

		USB_TxEPInit((gUsbDevice.ep_iso_tx_info[index_ep].epdesc.stdep.bEndpointAddress&(~USB_EP_DIR)),
						wMaxPacketSize, USB_ENDPT_ISO,double_fifo);
		gUsbDevice.ep_iso_tx_info[index_ep].ep_status.epin_status.nBytesLeft = USB_EP_NODATA;
	}
#endif

#endif /* __USB_EP_TEST__ */
	for(index_ep = 0; index_ep < gUsbDevice.resource_ep_intr_tx_number; index_ep++)
	{
//		wMaxPacketSize = (kal_uint8)gUsbDevice.ep_intr_tx_info[index_ep].epdesc.stdep.wMaxPacketSize[1];
//		wMaxPacketSize <<= 8;
//		wMaxPacketSize |= (kal_uint8)gUsbDevice.ep_intr_tx_info[index_ep].epdesc.stdep.wMaxPacketSize[0];

		wMaxPacketSize = USB_Intr_Max_Packet_Size();

		USB_TxEPInit((gUsbDevice.ep_intr_tx_info[index_ep].epdesc.stdep.bEndpointAddress&(~USB_EP_DIR)),
						wMaxPacketSize, USB_ENDPT_INTR,KAL_FALSE);
		gUsbDevice.ep_intr_tx_info[index_ep].ep_status.epin_status.nBytesLeft = USB_EP_NODATA;
	}

	/* Clear current configuration pointer */
	gUsbDevice.self_powered = KAL_FALSE;
#if defined(DRV_USB_REMOTE_WAKEUP_SUPPORT)
	gUsbDevice.remoteWk = KAL_TRUE;
#else
	gUsbDevice.remoteWk = KAL_FALSE;
#endif	
#if defined(__DUAL_TALK_MODEM_SUPPORT__)   
	gUsbDevice.isRemoteWking = KAL_FALSE;		
#endif
	gUsbDevice.config_num = 0;        /*  set configuration command value  */

	for(index = 0; index < USB_MAX_INTERFACE; index++)
		gUsbDevice.interface_num[index] = 0;

	gUsbDevice.ep0_state = USB_EP0_IDLE;
	gUsbDevice.ep0info.byFAddr = 0xff;   /*  device (function) address, no use, at HW still set 0x00 */

	/* initial class specific interface functions*/
	USB_Software_Init();
}


/************************************************************
	EP0 functions
*************************************************************/

/* parse command Set Address */
static kal_bool USB_Cmd_SetAddress(Usb_Ep0_Status *pep0state, Usb_Command *pcmd)
{
	kal_bool bError = KAL_TRUE;
	USB_DRV_CTRL_USB_SET_ADDR_T dcl_set_addr;

	/* Store device function address until status stage of request */
	if (pcmd->bmRequestType == USB_CMD_STDDEVOUT)
	{
		if (gUsbDevice.nDevState <= DEVSTATE_ADDRESS)
		{
			pep0state->byFAddr = (kal_uint8)pcmd->wValue;

			if ((gUsbDevice.nDevState == DEVSTATE_DEFAULT) && (pep0state->byFAddr<=127))
			{
				gUsbDevice.nDevState = DEVSTATE_SET_ADDRESS;

				dcl_set_addr.u1addr = (DCL_UINT8)pep0state->byFAddr;
				dcl_set_addr.state = (DCL_USB_SET_ADDR_STATE)USB_SET_ADDR_DATA;

				DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_SET_ADDRESS, (DCL_CTRL_DATA_T *)&dcl_set_addr);

//				USB_SetAddress(pep0state->byFAddr, USB_SET_ADDR_DATA);
			}
			else
			{
				gUsbDevice.nDevState = DEVSTATE_DEFAULT;
			}
			
			bError = KAL_FALSE;
		}
	}
	
	return bError;
}

/* parse command Get Descriptor */
static kal_bool USB_Cmd_GetDescriptor(Usb_Ep0_Status *pep0state, Usb_Command *pcmd)
{
	kal_bool bError = KAL_FALSE;
	kal_uint8 byConfig;
	kal_uint8 bystr;
	Usb_Cfg_Dscr *pcfg;
#if (defined(__USB_IMAGE_CLASS__)||defined(__MBIM_SUPPORT__))
	static const kal_uint16 USB_OS_STRING[] = {'M', 'S', 'F', 'T', '1', '0', '0'};
#endif


	/* Decode the required descriptor from the command */
	if (pcmd->bmRequestType != USB_CMD_STDDEVIN)
	{
		bError = KAL_TRUE;
	}
	else
	{
		switch (pcmd->wValue & USB_CMD_DESCMASK)
		{
		case USB_CMD_DEVICE:
			/* First time host get device descriptor will only get 8 bytes (one packet), but no reset */
			if(gUsbDevice.device_type == USB_IMAGE)
			{
				if(pcmd->wLength == 64)
					gUsbDevice.ep0_send_one_pkt = KAL_TRUE;
			}

			/* Prepare to return Standard Device Descriptor */
			USB_Generate_EP0Data(pep0state, pcmd, &gUsbDevice.devdscr, sizeof(Usb_Dev_Dscr));
			break;

		case USB_CMD_CONFIG:
			byConfig = (kal_uint8)(pcmd->wValue & 0x00FF);
			#ifdef __MBIM_SUPPORT__
				USB_Configuration_Setup(byConfig);
				#ifdef __USB_HS_ENABLE__
					USB_Software_Speed_Init(KAL_FALSE,byConfig);
				#endif									
			#else
	#ifdef __USB_HS_ENABLE__
			USB_Software_Speed_Init(KAL_FALSE);
	#endif
			#endif				
			if (byConfig >= gUsbDevice.devdscr.bNumConfigurations)
			{
				bError = KAL_TRUE;
			}
			else
			{
				/* Get pointer to request configuration descriptor */
				pcfg = (Usb_Cfg_Dscr*)gUsbDevice.conf;

				if (USB_Check_Composite_With_COM(gUsbDevice.device_type)== KAL_FALSE)
				{	
					/* Memory copy to modify descriptor */
					pcfg->bConfigurationValue = (byConfig + 1);

					pcfg->bMaxPower = gUsbDevice.multi_Max_Power[byConfig];

					if (gUsbDevice.multi_Max_Power[byConfig] == 0)										
						pcfg->bmAttributes |= (USB_CFGDSC_ATTR_SELFPOWER|USB_CFGDSC_ATTR_NATURE); /* Return self power */
					else
						pcfg->bmAttributes |= USB_CFGDSC_ATTR_NATURE;						/* Return bus power */
						
//					if(byConfig == (USB_DEVDSC_CONFIGS-1))
//					{
//						/* Return self power */
//						pcfg->bmAttributes = (USB_CFGDSC_ATTR_SELFPOWER|USB_CFGDSC_ATTR_NATURE);
//					}
//					else
	//				{
	//					/* Return bus power */
	//					pcfg->bmAttributes = USB_CFGDSC_ATTR_NATURE;
	//				}

				}
			#ifdef __MBIM_SUPPORT__
				if(gUsbDevice.device_type == USB_MORPHING_MBIM)
				{
					pcfg->bConfigurationValue = (byConfig + 1);
				}
			#endif  
				if(gUsbDevice.device_type == USB_IMAGE)
				{
					if(pcmd->wLength == 8)
						gUsbDevice.ep0_send_one_pkt = KAL_TRUE;
				}

				/* Prepare to return Configuration Descriptors */
				USB_Generate_EP0Data(pep0state, pcmd, pcfg, pcfg->wTotalLength);
			}
			break;

		case USB_CMD_STRING:
			bystr = (kal_uint8)(pcmd->wValue & 0x00FF);

			if (bystr >= gUsbDevice.resource_string_number)
			{
		#if (defined(__USB_IMAGE_CLASS__)||defined(__MBIM_SUPPORT__))
				if((bystr == 0xEE)&&((gUsbDevice.device_type == USB_IMAGE)||(gUsbDevice.device_type == USB_IMAGE_MTP) || (gUsbDevice.device_type == USB_MORPHING_MBIM)))
				{
					gUsbDevice.os_string_desc.bLength = USB_MAX_OS_STRING_LENGTH;
					gUsbDevice.os_string_desc.bDescriptorType = USB_STRING;

					kal_mem_cpy(gUsbDevice.os_string_desc.qwSignature, (kal_uint8*)USB_OS_STRING, 14);

					gUsbDevice.os_string_desc.bMS_VendorCode = USB_GET_MS_DESCRIPTOR;
					gUsbDevice.os_string_desc.bPad = 0x00;

					/* Get pointer to request string descriptor */
					USB_Generate_EP0Data(pep0state, pcmd, (void *)&gUsbDevice.os_string_desc, USB_MAX_OS_STRING_LENGTH);
				}
				else
				{
					bError = KAL_TRUE;
				}
		#else
				bError = KAL_TRUE;
		#endif
			}
			else
			{
				/* Get pointer to requested string descriptor */
				USB_Generate_EP0Data(pep0state, pcmd, (void *)gUsbDevice.resource_string[bystr],
							(*(kal_uint8 *)gUsbDevice.resource_string[bystr]));
			}
			break;

	#ifdef __USB_HS_ENABLE__
		case USB_CMD_DEVICE_QUALIFIER:
			/* Prepare to return Standard Device_Qualifier Descriptor */
			USB_Generate_EP0Data(pep0state, pcmd, &gUsbDevice.dev_qual_dscr, sizeof(Usb_Dev_Qual_Dscr));
			break;
		case USB_CMD_OTHER_SPEED:
//			USB_Software_Speed_Init(KAL_TRUE);
			byConfig = (kal_uint8)(pcmd->wValue & 0x00FF);
			#ifdef __MBIM_SUPPORT__
				USB_Configuration_Setup(byConfig);
				USB_Software_Speed_Init(KAL_TRUE,byConfig);
			#else
			USB_Software_Speed_Init(KAL_TRUE);
			#endif

			if (byConfig >= gUsbDevice.devdscr.bNumConfigurations)
			{
				bError = KAL_TRUE;
			}
			else
			{
				/* Get pointer to requested configuration descriptor */
				pcfg = (Usb_Cfg_Dscr*)gUsbDevice.conf;

				if (USB_Check_Composite_With_COM(gUsbDevice.device_type)== KAL_FALSE)
				{	
					/*  Memory copy to modify descriptor */
					pcfg->bConfigurationValue = (byConfig + 1);
					pcfg->bMaxPower = gUsbDevice.multi_Max_Power[byConfig];
				}				
				/* Prepare to return Configuration Descriptors */
				USB_Generate_EP0Data(pep0state, pcmd, pcfg, pcfg->wTotalLength);
			}
			break;
	#endif
		default:
			bError = KAL_TRUE;
			break;
		}
	}

	return bError;
}


/* Parse command Set Configuration */
static kal_bool USB_Cmd_SetConfiguration(Usb_Ep0_Status *pep0state, Usb_Command *pcmd)
{
	kal_bool bError = KAL_FALSE;
	kal_uint8 byConfig;
#ifndef __MEUT__
//	DCL_HANDLE pmu_handle;
//	PMU_CTRL_CHR_GET_CHR_CURRENT_LIST get_chr_current_list;
//	kal_uint8 index;
//	ilm_struct *ilm = NULL;
	/* add for usb charging */
//	ilm_struct *ilm_charge = NULL;
//	bmt_usb_ind_struct *ind;
	/* uart plug in ind*/
	uart_plugin_ind_struct *ilm_uart_plug_in;
	kal_uint32 usb_port;
#endif




#ifdef __USB_COM_PORT_ENABLE__ //__USB_DOWNLOAD__
	if (USBDL_Mode_Type()!= USBDL_MODE_NONE)//((USBDL_Is_USB_Download_Mode() == KAL_TRUE)||(INT_IsBootForUSBAT() == KAL_TRUE))
	{
		ASSERT(0);
//		return bError;
	}
#endif

//	gUsbDevice.self_powered = KAL_FALSE;
//	gUsbDevice.is_configured_now = KAL_FALSE;

	byConfig = (kal_uint8)(pcmd->wValue & 0x00FF);

	USB_Dbg_Trace(USB_EP0_SET_CONFIGURATION, 0, (kal_uint32)byConfig);

	if (gUsbDevice.nDevState == DEVSTATE_DEFAULT)
	{
		bError = KAL_TRUE;
	}
	/* Assumes configurations are numbered from 1 to NumConfigurations */
	else
	{
		if (byConfig > gUsbDevice.devdscr.bNumConfigurations)
		{
			bError = KAL_TRUE;
		}
		else if (byConfig == 0)
		{
			USB_Disable_Charging();
			gUsbDevice.nDevState = DEVSTATE_ADDRESS;
			gUsbDevice.config_num = 0;
		}
		else
		{
			drv_trace0(TRACE_FUNC, (kal_uint32)USB_IS_CONFIGURE);

			USB_Software_Enable();

			gUsbDevice.nDevState = DEVSTATE_CONFIG;
//			gUsbDevice.is_configured_now = KAL_TRUE;
			gUsbDevice.config_num = byConfig;

			if (USB_Check_Composite_With_COM(gUsbDevice.device_type)== KAL_FALSE)
			{						
			    // get descriptor = 3 --> set configurtaion = 4		
				if (gUsbDevice.multi_Max_Power[byConfig-1] == 0)										
						gUsbDevice.self_powered = KAL_TRUE; /* Return self power */
				else
						gUsbDevice.self_powered = KAL_FALSE;						/* Return bus power */
			
//				if(byConfig == USB_DEVDSC_CONFIGS)
//				{
//					gUsbDevice.self_powered = KAL_TRUE;
//				}
//				else
//				{
//					gUsbDevice.self_powered = KAL_FALSE;
//				}
			}
		}
	}

#ifndef __MEUT__

	//In assert mode, we cannot send message.
	if (USB_Exception_Check() == KAL_TRUE)//	if(INT_Exception_Enter == 0 && (!(is_init_log_enable == KAL_TRUE && is_init_stage == KAL_TRUE)))
	{
		if(INT_BootMode() != MTK_FACTORY_MODE)
		{
			if((byConfig > 0) && (byConfig <= gUsbDevice.devdscr.bNumConfigurations))
			{
				USB_Send_Msg(USB_SEND_BMT_START_CHARGE);
/*				
				ind = (bmt_usb_ind_struct*)construct_local_para(sizeof(bmt_usb_ind_struct), TD_CTRL);

				if (byConfig > gUsbDevice.current_table_index)
					ind->usb_ind = PMU_CHARGE_CURRENT_0_00_MA;
				else
					ind->usb_ind = (PMU_CHR_CURRENT_ENUM)gUsbDevice.get_chr_current_list.pCurrentList[gUsbDevice.current_table_index-byConfig];							

				USB_Send_Msg_Ext_Queue(ilm_charge,MOD_BMT, MSG_ID_BMT_USB_IND, ind);

				drv_trace2(TRACE_FUNC, (kal_uint32)USB_CONFIG_NUM,byConfig,gUsbDevice.current_table_index);
*/								
	//			DRV_BuildPrimitive( ilm_charge, MOD_DRV_HISR, MOD_BMT, MSG_ID_BMT_USB_IND, ind);
	//			msg_send_ext_queue(ilm_charge);
			}
		}
		else
		{
			/* meta mode, notify ft task */
			
			USB_Send_Msg_Ext_Queue(MOD_FT, MSG_ID_USB_FT_IND, NULL);
//			DRV_BuildPrimitive(ilm, MOD_DRV_HISR, MOD_FT, MSG_ID_USB_FT_IND, NULL);
//			msg_send_ext_queue(ilm);
		}
	}

#ifdef __USB_COM_PORT_ENABLE__
	/* Notify UART owner that virtual UART is plug in */
	if(gUsbDevice.nDevState == DEVSTATE_CONFIG)
	{
#ifndef __MBIM_SUPPORT__	
//		if((gUsbDevice.device_type == USB_CDC_ACM)||(gUsbDevice.device_type == USB_COMPOSITE_MULTI_COM)||(gUsbDevice.device_type == USB_COMPOSITE_RNDIS_COM)||(gUsbDevice.device_type == USB_RNDIS)||(gUsbDevice.device_type == USB_COMPOSITE_VIDEO_COM))
		if ((gUsbDevice.device_type == USB_CDC_ACM)||(gUsbDevice.device_type == USB_RNDIS)||(gUsbDevice.device_type == USB_DATA_CONNECTION_COM)||(USB_Check_Composite_With_COM(gUsbDevice.device_type)== KAL_TRUE))
		{
	#ifdef __USB_STRESS_TEST__
			/* notify usb task to start logging */
	
			USB_Send_Msg_Ext_Queue(MOD_USB, MSG_ID_USB_TEST_START_IND, NULL);
//			DRV_BuildPrimitive(ilm, MOD_DRV_HISR, MOD_USB, MSG_ID_USB_TEST_START_IND, NULL);
//			msg_send_ext_queue(ilm);
	#endif

			for(usb_port = 0; usb_port < MAX_USB_PORT_NUM; usb_port++)
			{
				if(USB2UARTPort[usb_port].ownerid != MOD_DRV_HISR && USB2UARTPort[usb_port].ownerid != MOD_NIL)
				{
	 				//In assert mode, we cannot send message.
					if (USB_Exception_Check() == KAL_TRUE) //if(INT_Exception_Enter == 0 && (!(is_init_log_enable == KAL_TRUE && is_init_stage == KAL_TRUE)))
					{					
					  ilm_uart_plug_in = (uart_plugin_ind_struct*)construct_local_para(sizeof(uart_plugin_ind_struct), TD_CTRL);
					  ilm_uart_plug_in->port = USB2UARTPort[usb_port].port_no;

						USB_Send_Msg_Ext_Queue(USB2UARTPort[usb_port].ownerid, MSG_ID_UART_PLUGIN_IND, ilm_uart_plug_in);
//						DRV_BuildPrimitive(ilm, MOD_DRV_HISR, USB2UARTPort[usb_port].ownerid, MSG_ID_UART_PLUGIN_IND, ilm_uart_plug_in);
//						msg_send_ext_queue(ilm);
					}

					g_UsbACM[usb_port].send_UARTilm = KAL_TRUE;

					if(g_UsbACM[usb_port].config_send_Txilm == KAL_TRUE )
					{
						g_UsbACM[usb_port].send_Txilm = KAL_TRUE;
						/* if someone PutBytes once, then issue ready-to-write message */
						if(USB2UARTPort[usb_port].tx_cb != NULL)
							USB2UARTPort[usb_port].tx_cb(USB2UARTPort[usb_port].port_no);
					}
					else
					{
						g_UsbACM[usb_port].send_Txilm = KAL_FALSE;
					}
				}
			}
		}				
#else
//		if((gUsbDevice.device_type == USB_CDC_ACM)||(gUsbDevice.device_type == USB_COMPOSITE_MULTI_COM)||(gUsbDevice.device_type == USB_COMPOSITE_RNDIS_COM)||(gUsbDevice.device_type == USB_RNDIS)||(gUsbDevice.device_type == USB_COMPOSITE_VIDEO_COM))
		if ((gUsbDevice.device_type == USB_MORPHING_MBIM) && byConfig == 1)
		{
			;
		}
		else
		{
			if((gUsbDevice.device_type == USB_MORPHING_MBIM) && (byConfig == 2))
			{
				//Bootloader will set DL flag. we clear it here for prevent download fail.
				if(gUsbDevice.morph_active == KAL_TRUE) // if morphing pass switch cd_rom to mass storage
				{
				INT_SetCmdToSys(SYS_CMD_CLR_DL_FLAG);			
				USB_Ms_Set_Current_Driver(LOGIC_DRIVE_MS);	
			}	
			}	
			if ((gUsbDevice.device_type == USB_CDC_ACM)||(gUsbDevice.device_type == USB_RNDIS)||(gUsbDevice.device_type == USB_DATA_CONNECTION_COM)||(USB_Check_Composite_With_COM(gUsbDevice.device_type)== KAL_TRUE))
			{
				for(usb_port = 0; usb_port < MAX_USB_PORT_NUM; usb_port++)
				{
					if((USB2UARTPort[usb_port].ownerid != MOD_DRV_HISR) 
						&& (USB2UARTPort[usb_port].ownerid != MOD_NIL) 
						&& (g_UsbACM[usb_port].data_interface_id != 0xFF))
					{
			//In assert mode, we cannot send message.
						if (USB_Exception_Check() == KAL_TRUE) //if(INT_Exception_Enter == 0 && (!(is_init_log_enable == KAL_TRUE && is_init_stage == KAL_TRUE)))
			{
						  ilm_uart_plug_in = (uart_plugin_ind_struct*)construct_local_para(sizeof(uart_plugin_ind_struct), TD_CTRL);
						  ilm_uart_plug_in->port = USB2UARTPort[usb_port].port_no;
									USB_Send_Msg_Ext_Queue(USB2UARTPort[usb_port].ownerid, MSG_ID_UART_PLUGIN_IND, ilm_uart_plug_in);
			}
	
						g_UsbACM[usb_port].send_UARTilm = KAL_TRUE;
	
						if(g_UsbACM[usb_port].config_send_Txilm == KAL_TRUE )
						{
							g_UsbACM[usb_port].send_Txilm = KAL_TRUE;
							/* if someone PutBytes once, then issue ready-to-write message */
							if(USB2UARTPort[usb_port].tx_cb != NULL)
								USB2UARTPort[usb_port].tx_cb(USB2UARTPort[usb_port].port_no);
						}
						else
			{
							g_UsbACM[usb_port].send_Txilm = KAL_FALSE;
						}
					}
				}	
			}					
			}
#endif

	#ifdef IC_MODULE_TEST
	    USB_MT_DMATest();
	#endif	

	#ifdef __USB_TETHERING__
		//In assert mode, we cannot send message.
		if((gUsbDevice.device_type == USB_RNDIS)||(gUsbDevice.device_type == USB_COMPOSITE_RNDIS_COM))
		{
			/* Notify UPS USB is config */			
			USB_Send_Msg_Ext_Queue(MOD_UPS_HIGH, MSG_ID_RNDIS_USB_ENUM_IND, NULL);
//			DRV_BuildPrimitive(ilm, MOD_DRV_HISR, MOD_UPS, MSG_ID_RNDIS_USB_ENUM_IND, NULL);	
//			msg_send_ext_queue(ilm);
//			g_UsbMode.rndis_cnf_response = KAL_FALSE;
		}
	#endif /* __USB_TETHERING__*/
	}
#endif /*__USB_COM_PORT_ENABLE__*/
#endif /* __MEUT__ */

	return bError;
}


/* Parse command Get Configuration */
static kal_bool USB_Cmd_GetConfiguration(Usb_Ep0_Status *pep0state, Usb_Command *pcmd)
{
	kal_bool bError = KAL_FALSE;


	if( (gUsbDevice.nDevState == DEVSTATE_ADDRESS) && (!pcmd->wValue))
	{
		/* Prepare to return zero */
		USB_Generate_EP0Data(pep0state, pcmd, &pcmd->wValue, 1);
	}
	else if( gUsbDevice.nDevState == DEVSTATE_CONFIG)
	{
		/* Prepare to return configuration value */
		USB_Generate_EP0Data(pep0state, pcmd, &gUsbDevice.config_num, 1);
	}
	else
	{
		bError = KAL_TRUE;
	}

	return bError;
}


/* Parse command Set Interface */
static kal_bool USB_Cmd_SetInterface(Usb_Ep0_Status *pep0state, Usb_Command *pcmd)
{
	gUsbDevice.interface_num[pcmd->wIndex] = pcmd->wValue&0x00FF;
	return KAL_FALSE;
}


/* Parse command Get Interface */
static kal_bool USB_Cmd_GetInterface(Usb_Ep0_Status *pep0state, Usb_Command *pcmd)
{
	USB_Generate_EP0Data(pep0state, pcmd, &gUsbDevice.interface_num[pcmd->wIndex], 1);
	return KAL_FALSE;
}


static kal_bool USB_Get_EP_Stall_Status(kal_uint32 ep_num, USB_EP_DIRECTION direction)
{
	USB_DRV_CTRL_EP_CTRL_FUNC_1_T	 dcl_data;

	dcl_data.u4ep_num = (DCL_UINT32)ep_num;
	dcl_data.direction = (DCL_USB_EP_DIRECTION)direction;
	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_GET_EP_STALL_STATUS, (DCL_CTRL_DATA_T *)&dcl_data);
	return (kal_bool)dcl_data.fg_result;
}


/* Parse command Set/Clear Feature */
/* bset  true means command SET_FETURE, false means command CLEAR_FEATURE */
static kal_bool USB_Cmd_SetFeature(Usb_Command *pcmd, kal_bool bset)
{
	kal_bool bError = KAL_FALSE;
#ifdef  __USB_MASS_STORAGE_ENABLE__
//	ilm_struct *usb_ilm = NULL;
#endif


	switch (pcmd->bmRequestType)
	{
	/* device */
	case USB_CMD_STDDEVOUT:

	if (pcmd->wValue == USB_FTR_DEVREMWAKE)
		{
			gUsbDevice.remoteWk = bset;
	}
	#ifdef __USB_HS_ENABLE__
	else if (pcmd->wValue == USB_FTR_TEST_MODE)
			{
		if(((pcmd->wIndex)>>8)== USB_TEST_J)			
				gUsbDevice.usb_test_type = USB_TEST_MODE_TYPE_J;
		else if(((pcmd->wIndex)>>8)== USB_TEST_K)			
				gUsbDevice.usb_test_type = USB_TEST_MODE_TYPE_K;
		else if(((pcmd->wIndex)>>8)== USB_TEST_SE0_NAK)			
				gUsbDevice.usb_test_type = USB_TEST_MODE_TYPE_SE0_NAK;
		else if(((pcmd->wIndex)>>8)== USB_TEST_PACKET)			
				gUsbDevice.usb_test_type = USB_TEST_MODE_TYPE_PACKET;
		else		
				bError = KAL_TRUE;
			}
	#endif
#ifdef __OTG_ENABLE__
	else if (pcmd->wValue == USB_FTR_B_HNP_ENB)
	{
		OTG_B_EnDis_HNP(KAL_TRUE);
	}
	else if (pcmd->wValue == USB_FTR_A_HNP_SUPPORT)
	{
	}
	else if (pcmd->wValue == USB_FTR_A_ALT_HNP_SUPPORT)
	{
	}	
#endif
	else
	{
		bError = KAL_TRUE;
	}
		break;
	/* endpoint */
	case USB_CMD_STDEPOUT:		
		switch (pcmd->wValue)
		{
		case USB_FTR_EPHALT:
			if (pcmd->wIndex != 0)
			{
					if(((pcmd->wIndex&0x80)&&(((pcmd->wIndex&0x0f) > MAX_TX_EP_NUM)||((pcmd->wIndex&0x0f) == 0x00)))
						||(((pcmd->wIndex&0x80)==0)&&(((pcmd->wIndex&0x0f) > MAX_RX_EP_NUM)||((pcmd->wIndex&0x0f) == 0x00))))
					{
						drv_trace0(TRACE_FUNC, (kal_uint32)USB_EP0_SetFeature);
						USB_Dbg_Trace(USB_CMD_SetFeature, pcmd->wIndex, 0);
						
						return KAL_TRUE;
					}

#ifdef  __USB_MASS_STORAGE_ENABLE__
					if((gUsbDevice.device_type == USB_MASS_STORAGE)&&(bset == KAL_FALSE))
					{	
						/* When stall by invalid cmd, PC must use MS reset cmd to clear stall */
						/* Ignore this cmd, and still return stall */						
						if((g_UsbMS.cbw_is_vaild == KAL_FALSE)||(g_UsbMS.ms_is_reset == KAL_TRUE))
							return KAL_FALSE;

						if(((pcmd->wIndex&0x80)&&(USB_Get_EP_Stall_Status(pcmd->wIndex&0x0f, USB_EP_TX_DIR) == KAL_TRUE))
							||(((pcmd->wIndex&0x80)==0)&&(USB_Get_EP_Stall_Status(pcmd->wIndex&0x0f, USB_EP_RX_DIR) == KAL_TRUE)))
							USB_Send_Msg_Ext_Queue(MOD_USB, MSG_ID_USB_MSDRV_CLEAR_STALL_REQ, NULL);
					}
#endif
				
				/* command EP direction zero indicate OUT EP */
				if(pcmd->wIndex&0x80)
				{
					/* TX EP */
//#ifdef  __USB_COMPORT_SUPPORT_TC01_DRIVER__
//Microsoft driver has the same behavior
//							if(((gUsbDevice.device_type == USB_CDC_ACM)||(gUsbDevice.device_type == USB_COMPOSITE_MULTI_COM)||(gUsbDevice.device_type == USB_RNDIS)||(gUsbDevice.device_type == USB_COMPOSITE_RNDIS_COM)||(gUsbDevice.device_type == USB_COMPOSITE_VIDEO_COM))
//								&&(bset == KAL_FALSE)&&(USB_Get_EP_Stall_Status(pcmd->wIndex&0x0f, USB_EP_TX_DIR) == KAL_FALSE))
							if (((gUsbDevice.device_type == USB_CDC_ACM)||(gUsbDevice.device_type == USB_RNDIS)||(USB_Check_Composite_With_COM(gUsbDevice.device_type)== KAL_TRUE))
								&&(bset == KAL_FALSE)&&(USB_Get_EP_Stall_Status(pcmd->wIndex&0x0f, USB_EP_TX_DIR) == KAL_FALSE))
							{
								USB_TxEPClearDataTog(pcmd->wIndex&0x0f, USB_ENDPT_BULK);
								break;
							}
//#endif
							USB_CtrlEPStall((pcmd->wIndex& 0x0f), USB_EP_TX_DIR, bset);
				}
				else
				{
					/* RX EP */
							drv_trace0(TRACE_FUNC, (kal_uint32)USB_EP0_Clear_Stall);
							USB_CtrlEPStall((pcmd->wIndex& 0x0f), USB_EP_RX_DIR, bset);
				}
#ifdef  __USB_MASS_STORAGE_ENABLE__
				/* Means this stall is triggered by PC set ep halt feature */
				if((gUsbDevice.device_type == USB_MASS_STORAGE)&&(bset == KAL_TRUE))
					g_UsbMS.cbw_is_vaild = KAL_TRUE;
#endif				
			}
			break;
		default:
			bError = KAL_TRUE;
			break;
		}
		break;
	case USB_CMD_STDIFOUT:
	default:
		bError = KAL_TRUE;
		break;
	}

	return bError;
}


/* Parse command Get Status */
static kal_bool USB_Cmd_GetStatus(Usb_Ep0_Status *pep0state, Usb_Command *pcmd)
{
	kal_bool bError = KAL_FALSE;
	static kal_uint16 status = 0;


	switch (pcmd->bmRequestType)
	{
	case USB_CMD_STDDEVIN:
		status = (kal_uint16)(((kal_uint8)gUsbDevice.remoteWk<<1)|((kal_uint8)gUsbDevice.self_powered));
		USB_Generate_EP0Data( pep0state, pcmd, &status, 2);
		break;
	case USB_CMD_STDIFIN:
		USB_Generate_EP0Data( pep0state, pcmd, &status, 2);
		break;
	case USB_CMD_STDEPIN:
		if(pcmd->wIndex & 0x80)
		{
			/* TX EP*/
			status = (kal_uint16)USB_Get_EP_Stall_Status((pcmd->wIndex & 0x000f), USB_EP_TX_DIR);
			USB_Dbg_Trace(USB_EP0_GET_STATUS_TX, (kal_uint32)status, 0);
		}
		else
		{
			/* RX EP*/
			status = (kal_uint16)USB_Get_EP_Stall_Status((pcmd->wIndex & 0x000f), USB_EP_RX_DIR);
			USB_Dbg_Trace(USB_EP0_GET_STATUS_RX, status, 0);
		}
		USB_Generate_EP0Data( pep0state, pcmd, &status, 2);
		break;
	default:
		bError = KAL_TRUE;
		break;
	}

	return bError;
}


void USB_EP0_Command_Hdlr(kal_bool bError)
{
	if(USB_Get_Endpoint0_State() == USB_EP0_IDLE)
	{
		USB_Set_Endpoint0_State(USB_EP0_RX_STATUS);
		USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, bError, KAL_TRUE);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif		
	}
	else
	{
		USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, bError, KAL_FALSE);
	}
}



/* Parse usb standard command */
static void USB_Stdcmd(Usb_Ep0_Status *pep0state, Usb_Command *pcmd)
{
	kal_bool   bError = KAL_FALSE;


	gUsbDevice.ep0_send_one_pkt = KAL_FALSE;

	/* For webcam to stop DMA then reset data toggle */
	if((gUsbDevice.ep0_class_cmd_handler.b_enable == KAL_TRUE) &&
		(gUsbDevice.ep0_class_cmd_handler.cmd == pcmd->bRequest) )
	{
		/* Besides standard cmd, still need to do extra this, like webcam halt feature*/
		gUsbDevice.ep0_class_cmd_handler.ep0_cmd_hdlr(pcmd);
	}

	switch (pcmd->bRequest)
	{
	case USB_SET_ADDRESS:
		drv_trace0(TRACE_FUNC, (kal_uint32)USB_EP0_SET_ADDR);
		USB_Dbg_Trace(USB_EP0_SET_ADDRESS, 0, 0);
		bError = USB_Cmd_SetAddress(pep0state, pcmd);
		break;
	case USB_GET_DESCRIPTOR:
//		drv_trace0(TRACE_FUNC, (kal_uint32)USB_EP0_GET_DESCRIPT);
		USB_Dbg_Trace(USB_EP0_GET_DESCRIPTOR, 0, 0);
		bError = USB_Cmd_GetDescriptor(pep0state, pcmd);
		break;
	case USB_SET_CONFIGURATION:
		drv_trace0(TRACE_FUNC, (kal_uint32)USB_EP0_SET_CONFIG);	
		bError = USB_Cmd_SetConfiguration(pep0state, pcmd);
		break;
	case USB_SET_INTERFACE:
//		drv_trace0(TRACE_FUNC, (kal_uint32)USB_EP0_SET_INTER);	
		USB_Dbg_Trace(USB_EP0_SET_INTERFACE, 0, 0);
		bError = USB_Cmd_SetInterface(pep0state, pcmd);
		break;
	case USB_GET_CONFIGURATION:
//		drv_trace0(TRACE_FUNC, (kal_uint32)USB_EP0_GET_CONFIG);		
		USB_Dbg_Trace(USB_EP0_GET_CONFIGURATION, 0, 0);
		bError = USB_Cmd_GetConfiguration(pep0state, pcmd);
		break;
	case USB_GET_INTERFACE:
//		drv_trace0(TRACE_FUNC, (kal_uint32)USB_EP0_GET_INTER);		
		USB_Dbg_Trace(USB_EP0_GET_INTERFACE, 0, 0);
		bError = USB_Cmd_GetInterface(pep0state, pcmd);
		break;
	case USB_SET_FEATURE:
#ifdef  __USB_MASS_STORAGE_ENABLE__
		USB_Dbg_Trace(USB_EP0_SET_FEATURE, (kal_uint32)g_UsbMS.cbw_is_vaild, 0);
#else
		USB_Dbg_Trace(USB_EP0_SET_FEATURE, 0, 0);
#endif
		bError = USB_Cmd_SetFeature(pcmd, KAL_TRUE);
		break;
	case USB_CLEAR_FEATURE:
#ifdef  __USB_MASS_STORAGE_ENABLE__
		USB_Dbg_Trace(USB_EP0_CLEAR_FEATURE, (kal_uint32)g_UsbMS.cbw_is_vaild, 0);
#else
		USB_Dbg_Trace(USB_EP0_CLEAR_FEATURE, 0, 0);
#endif
		bError = USB_Cmd_SetFeature(pcmd, KAL_FALSE);
		break;
	case USB_GET_STATUS:
//		drv_trace0(TRACE_FUNC, (kal_uint32)USB_EP0_GET_STAT);	
		bError = USB_Cmd_GetStatus(pep0state, pcmd);
		break;
	/* Stall the command if an unrecognized request is received */
	case USB_SYNCH_FRAME:   /*Only support for Isoc traffic*/
	case USB_SET_DESCRIPTOR:
	default:
		drv_trace0(TRACE_FUNC, (kal_uint32)USB_EP0_UNSUPPORT);	
		bError = KAL_TRUE;
		break;
	}

	USB_EP0_Command_Hdlr(bError);
	
}

#if (defined(__USB_IMAGE_CLASS__)||defined(__MBIM_SUPPORT__))
/* Parse command Get MS Descriptor */
static void USB_Cmd_Get_MS_Descriptor(Usb_Ep0_Status *pep0state, Usb_Command *pcmd)
{
	kal_bool bError = KAL_FALSE;
	kal_uint32 length;

	/* Linux will sent pcmd->wIndex == USB_FTR_EXT_PROPERTIES, but MTK didn't support it now. */
	#if defined(__MBIM_SUPPORT__)	
	if((pcmd->wValue == 0x00)&&(pcmd->wIndex == USB_FTR_EXT_COMPAT_ID) 
			&& (gUsbDevice.nDevState != DEVSTATE_CONFIG) && (gUsbDevice.device_type == USB_MORPHING_MBIM))
	{
		gUsbDevice.morph_active = KAL_TRUE;
	#else
	if((pcmd->wValue == 0x00)&&(pcmd->wIndex == USB_FTR_EXT_COMPAT_ID))
	{
	#endif
		if(pcmd->wLength < sizeof(Usb_Ext_Compat_ID_OS_Feature_Dscr))
			length = pcmd->wLength;
		else
			length = sizeof(Usb_Ext_Compat_ID_OS_Feature_Dscr);

		/* Prepare to return Standard Device Descriptor */
		USB_Generate_EP0Data(pep0state, pcmd, &gUsbDevice.os_feature_desc, (kal_int32)length);
	}
	else
	{
		bError = KAL_TRUE;
	}

	/* EP0 will stall in error case, thus no need assertion */
	//if(gUsbDevice.ep0_state == USB_EP0_IDLE)
	//{
	//	ASSERT(0);
	//}
	//else
	{
		USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, bError, KAL_FALSE);
	}
}

#endif


/* Parse EP0 requested command */
static void USB_Endpoint0_Idle (void)
{
	/* Read ep0 data */
	USB_EPFIFORead(0, 8, &gUsbDevice.cmd, KAL_FALSE);

	/* Check request type */
	switch (gUsbDevice.cmd.bmRequestType & USB_CMD_TYPEMASK)
	{
	case USB_CMD_STDREQ:
		/* standard request */
		USB_Stdcmd(&gUsbDevice.ep0info, &gUsbDevice.cmd);
		break;

	case USB_CMD_CLASSREQ:
		/* class specific request */
		//check PC send Data packet:  index parts
		if ((gUsbDevice.cmd.wIndex & 0xFF) > USB_MAX_INTERFACE)
		{
			/* error occur, stall endpoint*/
			USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, KAL_TRUE, KAL_FALSE);
			return;
		}
		if((gUsbDevice.cmd.bmRequestType == USB_CMD_CLASSIFIN) || (gUsbDevice.cmd.bmRequestType == USB_CMD_CLASSIFOUT))
		{
			if(gUsbDevice.if_info[(gUsbDevice.cmd.wIndex & 0xff)].if_class_specific_hdlr != NULL)
			{
				gUsbDevice.if_info[(gUsbDevice.cmd.wIndex & 0xff)].if_class_specific_hdlr(&gUsbDevice.ep0info, &gUsbDevice.cmd);
			}
			else
			{
				/* error occur, stall endpoint*/
				USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, KAL_TRUE, KAL_FALSE);
			}
		}
		else
		{
			/* error occur, stall endpoint*/
			USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, KAL_TRUE, KAL_FALSE);
		}
		break;

#if (defined(__USB_IMAGE_CLASS__)||defined(__MBIM_SUPPORT__))

	case USB_CMD_VENDREQ:
		/* Vendor specific request */
		if(gUsbDevice.cmd.bmRequestType == USB_CMD_VENDDEVIN)
		{
			if(gUsbDevice.cmd.bRequest == USB_GET_MS_DESCRIPTOR)
			{
				/* OS feature descriptors */
				USB_Cmd_Get_MS_Descriptor(&gUsbDevice.ep0info, &gUsbDevice.cmd);
			}
		}
		else
		{
			/* error occur, stall endpoint*/
			USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, KAL_TRUE, KAL_FALSE);
		}

		break;
#else
	case USB_CMD_VENDREQ:
#endif
	default:
		/* Stall the command if a reserved request is received */
		USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, KAL_TRUE, KAL_FALSE);
		break;
	}
}


/* EP0 RX handler, called when EP0 interrupt happened and in RX state */
static void USB_Endpoint0_Rx(void)
{
	if (gUsbDevice.ep0_rx_handler != NULL)
	{
		/* called rx handler to get data*/
		gUsbDevice.ep0_rx_handler(&gUsbDevice.ep0info);
	}
	else
	{
		/* this should not happened, user should register rx handler when set EP0 into RX state */
		/* error occur, stall endpoint*/
		ASSERT(0);
//		USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, KAL_TRUE, KAL_FALSE);
	}
}


/* EP0 TX handler, called when EP0 interrupt happened and in TX state,
     or EP0 just translate from IDLE to TX state */
static void USB_Endpoint0_Tx(void)
{
	kal_int32 nBytes;


	/* Determine number of bytes to send */
	if (gUsbDevice.ep0info.nBytesLeft <= USB_EP0_MAXP)
	{
		nBytes = gUsbDevice.ep0info.nBytesLeft;
		gUsbDevice.ep0info.nBytesLeft = 0;
	}
	else
	{
		nBytes = USB_EP0_MAXP;
		gUsbDevice.ep0info.nBytesLeft -= USB_EP0_MAXP;
	}

	/* Send out data */
	USB_EPFIFOWrite (0, nBytes, gUsbDevice.ep0info.pData);

	/* Update data pointer and  prepare for next transaction */
	gUsbDevice.ep0info.pData = (kal_uint8 *)gUsbDevice.ep0info.pData + nBytes;

	if((nBytes < USB_EP0_MAXP)||(gUsbDevice.ep0_send_one_pkt == KAL_TRUE)||((gUsbDevice.ep0info.no_ZLP == KAL_TRUE)&&(gUsbDevice.ep0info.nBytesLeft==0)))
	{
		gUsbDevice.ep0_state = USB_EP0_IDLE;
		/* Last data, set end as true */
		USB_Update_EP0_State(USB_EP0_DRV_STATE_WRITE_RDY, KAL_FALSE, KAL_TRUE);
	}
	else
	{
		USB_Update_EP0_State(USB_EP0_DRV_STATE_WRITE_RDY, KAL_FALSE, KAL_FALSE);
	}
}


/* EP0 interrupt handler called by USB_HISR */
static void USB_Endpoint0_Hdlr(void)
{
	kal_bool b_transaction_end;
	kal_bool b_sent_stall;
	kal_uint32 nCount;
	USB_DRV_CTRL_USB_SET_ADDR_T dcl_set_addr;
	USB_DRV_CTRL_GET_EP_STATUS_T  dcl_data;


//	USB_Get_EP0_Status(&b_transaction_end, &b_sent_stall);
	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_GET_EP0_STATUS, (DCL_CTRL_DATA_T  *)&dcl_data);
	b_transaction_end = (kal_bool)dcl_data.fg_transaction_end;
	b_sent_stall = (kal_bool)dcl_data.fg_sent_stall;

	/* Check for SentStall */
	/* SentStall && SetupEnd are impossible to occur together*/
	if (b_sent_stall == KAL_TRUE)
	{
		USB_Update_EP0_State(USB_EP0_DRV_STATE_CLEAR_SENT_STALL, KAL_FALSE, KAL_FALSE);
		gUsbDevice.ep0_state = USB_EP0_IDLE;
	}

	/* Check for SetupEnd */
	if (b_transaction_end == KAL_TRUE)
	{
		USB_Update_EP0_State(USB_EP0_DRV_STATE_TRANSACTION_END, KAL_FALSE, KAL_FALSE);
		gUsbDevice.ep0_state = USB_EP0_IDLE;
	}

	/* Call relevant routines for endpoint 0 state */
	if (gUsbDevice.ep0_state == USB_EP0_IDLE)
	{
		/* receive command request */
		nCount = USB_EP0_Pkt_Len();

		if (nCount > 0)
		{
			/* idle state handler */
			USB_Endpoint0_Idle();
		}
	}
	else if (gUsbDevice.ep0_state == USB_EP0_RX)
	{
		/* Rx state handler */
		USB_Endpoint0_Rx();
	}
	else if (gUsbDevice.ep0_state == USB_EP0_RX_STATUS)
	{
		/* Data stage is RX, status stage is TX*/
		if(gUsbDevice.nDevState == DEVSTATE_SET_ADDRESS)
		{
			dcl_set_addr.u1addr = (DCL_UINT8)gUsbDevice.ep0info.byFAddr;
			dcl_set_addr.state = (DCL_USB_SET_ADDR_STATE)USB_SET_ADDR_STATUS;

			DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_SET_ADDRESS, (DCL_CTRL_DATA_T *)&dcl_set_addr);

//			USB_SetAddress(gUsbDevice.ep0info.byFAddr, USB_SET_ADDR_STATUS);
			gUsbDevice.nDevState = DEVSTATE_ADDRESS;
		}

	#ifdef __USB_HS_ENABLE__
		if(gUsbDevice.usb_test_type != USB_TEST_MODE_TYPE_NONE)
		{
			USB_Disable_Charging(); //because of PMIC current consumption problem,Gnd will be rase to 6~8mv.=>for USB compliance test,disable charging.
			/* After status complete, target must transmit to test mode in 3ms */
			USB_Enter_Test_Mode(gUsbDevice.usb_test_type);
			return;
		}
	#endif

		gUsbDevice.ep0_state = USB_EP0_IDLE;

		/* In case next setup followed the previous status very fast and interrupt only happens once*/
		/* receive command request */
		nCount = USB_EP0_Pkt_Len();

		if (nCount > 0)
		{
			DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_GET_TX_ISR_STATUS, NULL);
//			USB_Read_TX_ISR_Status();

			/* idle state handler */
			USB_Endpoint0_Idle();
		}
	}

	/* must use if, not else if, EP0 may enter TX state in previous IDLE state handler */
	if (gUsbDevice.ep0_state == USB_EP0_TX)
	{
		/* Tx state handler */
		USB_Endpoint0_Tx();
	}
}




#endif  /* __USB_ENABLE__ */

