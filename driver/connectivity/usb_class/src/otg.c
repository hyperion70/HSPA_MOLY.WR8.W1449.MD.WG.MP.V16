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
 *    otg.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  This file implements otg application functions
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#ifdef __OTG_ENABLE__

#include "drv_comm.h"
#include "intrCtrl.h"
#include "init.h"

//#include "stack_common.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "kal_public_api.h" //#include "stack_ltlcom.h" //MSBB change #include "app_ltlcom.h"       /* Task message communiction */
#include "usb_comm.h"
#include "usb_adap.h"
#include "usb.h"
//#include "usb_drv.h"
//#include "usb_hcd.h"
#include "dcl.h"
#include "usbd.h"
#include "usb_host_default_drv.h"
#include "usb_host_ms_drv.h"
#ifdef __MTP_ENABLE__
#include "usbimage_drv.h"
#endif
#ifdef __USB_HOST_COM_PORT_SUPPORT__
#include "usb_host_acm_drv.h"
#endif
#ifdef __IC_USB_EEM_SUPPORT__
//#include "icusb_eem_drv.h"
#endif
#ifdef __IC_USB_ICCD_SUPPORT__
//#include "icusb_iccd_drv.h"
#endif

//#include "otg_drv.h"
#include "otg_if.h"
#include "otg.h"
#include "usb_task.h"
#include "usb_mode.h"
//#include "kal_non_specific_general_types.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
//#include "kal_active_module.h"
#include "kal_public_api.h" //#include "stack_ltlcom.h"
//#include "kal_release.h"
#include "kal_general_types.h"
#include "kal_public_api.h"

#include "dcl.h"
#include "dcl_otg_drv.h"

#ifdef __MULTI_BOOT__
#include "multiboot_config.h"
#endif /* __MULTI_BOOT__ */

#ifdef __OTG_SRP_HNP_APP_FIXED__
#include "usb_custom_def.h"
#endif



/* This option is for after HNP, target will config as MS, no USB config screen */
/* For OTG compliance test */
DCL_HANDLE g_OTG_Dcl_Handle = 0;


OTG_Struct gUsbOtg;

/* get system boot mode*/
extern kal_bool INT_USBBoot(void);
//extern kal_bool g_usb_boot_as_logging_tool;

static void OTG_Register_Drv_Info(OTG_DRV_HDLR_TYPE type, otg_intr_handler_ptr hdlr);
/* static functions */
static void OTG_Host_Up_Hdlr(void);
static void OTG_Host_Down_Hdlr(void);
static void OTG_Device_Up_Hdlr(void);
static void OTG_Device_Down_Hdlr(void);
static void OTG_A_VRise_Fail_Hdlr(void);
static void OTG_A_HNP_Fail_Hdlr(void);
static void OTG_A_HNP_Stop_Hdlr(void);
static void OTG_A_No_Response_Hdlr(void);
static void OTG_B_HNP_Fail_Hdlr(void);
static void OTG_B_SRP_Fail_Hdlr(void);
static void OTG_B_SRP_Stop_Hdlr(void);
static void OTG_B_SRP_Exception_Stop_Hdlr(void);
static void OTG_Host_Stop_Hdlr(void);



static void OTG_Register_Drv_Info(OTG_DRV_HDLR_TYPE type, otg_intr_handler_ptr hdlr)
{
	OTG_DRV_CTRL_REGISTER_DRV_INFO_T dcl_data;


	dcl_data.type = (DCL_OTG_DRV_HDLR_TYPE)type;
	dcl_data.hdlr = (DCL_OTG_FUNC_TYPE_0)hdlr;
	DclOTG_DRV_Control(g_OTG_Dcl_Handle, OTG_DRV_CMD_REGISTER_DRV_INFO, (DCL_CTRL_DATA_T *)&dcl_data);
}


/* Initialize function, init all OTG resources */
void OTG_Init_Phase1(void)
{
	gUsbOtg.b_check_srp = KAL_FALSE;
	gUsbOtg.hnp_srp_type = USB_UNKOWN;

	DclOTG_DRV_Control(g_OTG_Dcl_Handle, OTG_DRV_CMD_INIT_DRV_INFO, NULL);
//	OTG_Init_Drv_Info();


	OTG_Register_Drv_Info(OTG_DRV_HDLR_HOST_UP, OTG_Host_Up_Hdlr);
	OTG_Register_Drv_Info(OTG_DRV_HDLR_HOST_DOWN, OTG_Host_Down_Hdlr);
	OTG_Register_Drv_Info(OTG_DRV_HDLR_DEVICE_UP, OTG_Device_Up_Hdlr);
	OTG_Register_Drv_Info(OTG_DRV_HDLR_DEVICE_DOWN, OTG_Device_Down_Hdlr);
	OTG_Register_Drv_Info(OTG_DRV_HDLR_A_VRISE_FAIL, OTG_A_VRise_Fail_Hdlr);
	OTG_Register_Drv_Info(OTG_DRV_HDLR_A_HNP_FAIL, OTG_A_HNP_Fail_Hdlr);
	OTG_Register_Drv_Info(OTG_DRV_HDLR_A_HNP_STOP, OTG_A_HNP_Stop_Hdlr);
	OTG_Register_Drv_Info(OTG_DRV_HDLR_A_NO_RESPONSE, OTG_A_No_Response_Hdlr);
	OTG_Register_Drv_Info(OTG_DRV_HDLR_B_HNP_FAIL, OTG_B_HNP_Fail_Hdlr);
	OTG_Register_Drv_Info(OTG_DRV_HDLR_B_SRP_FAIL, OTG_B_SRP_Fail_Hdlr);
	OTG_Register_Drv_Info(OTG_DRV_HDLR_B_SRP_STOP, OTG_B_SRP_Stop_Hdlr);
	OTG_Register_Drv_Info(OTG_DRV_HDLR_B_SRP_EXCEPTION_STOP, OTG_B_SRP_Exception_Stop_Hdlr);
	OTG_Register_Drv_Info(OTG_DRV_HDLR_A_HOST_STOP, OTG_Host_Stop_Hdlr);
}


void OTG_Init_Phase2(void)
{
	DclOTG_DRV_Control(g_OTG_Dcl_Handle, OTG_DRV_CMD_INIT_DRV, NULL);
//	OTG_Init_Drv();
	DclOTG_DRV_Control(g_OTG_Dcl_Handle, OTG_DRV_CMD_DRV_ACTIVATE_ISR, NULL);
//	OTG_Drv_Activate_ISR();
	DclOTG_DRV_Control(g_OTG_Dcl_Handle, OTG_DRV_CMD_DMA_DRV_ACTIVATE_ISR, NULL);
//	OTGDMA_Drv_Activate_ISR();
}


/* Only cable plug out will call this function */
void OTG_Release(void)
{
	gUsbOtg.b_check_srp = KAL_FALSE;
	gUsbOtg.hnp_srp_type = USB_UNKOWN;

	DclOTG_DRV_Control(g_OTG_Dcl_Handle, OTG_DRV_CMD_RELEASE_DRV_INFO, NULL);
//	OTG_Release_Drv_Info();
}


/* Triggered from OTG_Init_SRP, so send msg to USB task */
void OTG_Start_SRP(void)
{
	USB_DRV_CTRL_PHY_FUNC_T  dcl_data;

	/* Enable USB power */
	/* SRP means Vbus is down */
	if(g_UsbMode.b_usb_pdnmode == KAL_TRUE)
	{
		g_UsbMode.b_usb_pdnmode = KAL_FALSE;
		USB_PDNmode(KAL_FALSE);
		OTG_Init_Phase1();
		OTG_Init_Phase2();

		dcl_data.owner = DCL_USB_PHY_OWNER_USB;
		DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_PHY_ENABLE, (DCL_CTRL_DATA_T  *)&dcl_data);
//		USB_Phy_Enable(USB_PHY_OWNER_USB);
	}	

	g_UsbMode.b_start_srp = KAL_TRUE;
	OTG_B_Set_Session_Valid(KAL_FALSE);
}


void OTG_Config_SRP(USB_DEVICE_TYPE type, kal_uint32 *parameter)
{
	/* Sleep for stable */
//	kal_sleep_task(5);
	gUsbOtg.hnp_srp_type = type;
	gUsbOtg.hnp_srp_parameter = parameter;
	gUsbOtg.b_check_srp = KAL_TRUE;

	/* Config request, but not pull up D+ */
	USB_Config_Type(type, KAL_FALSE, parameter);

#ifdef __MTP_ENABLE__
	if(type == USB_IMAGE_MTP)
	{
		if(g_USBImage.mtp_state == IMAGE_MTP_ENABLE)
			g_UsbMode.usb_config_result = KAL_TRUE;
		else
			g_UsbMode.usb_config_result = KAL_FALSE;
	}
#endif

	if(g_UsbMode.usb_config_result == KAL_TRUE)
	{
		OTG_Display_Message(OTG_DISPLAY_MSG_CONNECTING);
		DclOTG_DRV_Control(g_OTG_Dcl_Handle, OTG_DRV_CMD_B_START_SRP, NULL);
//		OTG_B_Start_SRP();
	}
	else
	{
		/* Error case because MS lockFAT fail */
		OTG_B_SRP_Fail_Hdlr();
	}
}


void OTG_Config_HNP(USB_DEVICE_TYPE type, kal_uint32 *parameter)
{
	gUsbOtg.hnp_srp_type = type;
	gUsbOtg.hnp_srp_parameter = parameter;

	/* HNP is already started */
	g_UsbMode.b_start_hnp = KAL_FALSE;

	switch(type)
	{
#ifdef __USB_MASS_STORAGE_ENABLE__
	case USB_MASS_STORAGE:
		/* If type is MS, initialize here */
		g_UsbMode.usb_config_result = KAL_TRUE;
		
		USB_Init_Normal_Mode_Ms();
//		g_UsbMS.disk_buffer = (void*)USB_TEST_Buffer;
//		USB_Init_Normal_Mode_Ms((kal_uint32 *)g_UsbMS.disk_buffer);
//		USB_Init_Normal_Mode_Ms(parameter);

		if(g_UsbMode.usb_config_result == KAL_TRUE)
		{
			DclOTG_DRV_Control(g_OTG_Dcl_Handle, OTG_DRV_CMD_A_START_HNP, NULL);
//			OTG_A_Start_HNP();
		}
		else
		{
			/* Error case because MS cannot start */
			OTG_A_HNP_Fail_Hdlr();
		}
		break;
#endif

#ifdef __MTP_ENABLE__
	case USB_IMAGE_MTP:
		if(g_USBImage.mtp_state == IMAGE_MTP_ENABLE)
		{
			g_UsbMode.usb_config_result = KAL_TRUE;
			DclOTG_DRV_Control(g_OTG_Dcl_Handle, OTG_DRV_CMD_A_START_HNP, NULL);
//			OTG_A_Start_HNP();
		}
		else
		{
			g_UsbMode.usb_config_result = KAL_FALSE;
			/* Error case because MTP cannot start */
			OTG_A_HNP_Fail_Hdlr();
		}
		break;
#endif
	default:
		DclOTG_DRV_Control(g_OTG_Dcl_Handle, OTG_DRV_CMD_A_START_HNP, NULL);
//		OTG_A_Start_HNP();
		break;
	}
}


static void OTG_Host_Up_Hdlr(void)
{
	kal_uint8 usb_ip_port = 0;//USB_OTG_HW_IP_Query();
	USBD_Init_Status(usb_ip_port);

/*	
	USBD_Register_Class_Driver(&USB_Host_Ms_Drv, KAL_FALSE);
#ifdef __USB_HOST_COM_PORT_SUPPORT__
	USBD_Register_Class_Driver(&USB_Host_Acm_Drv, KAL_FALSE);
#endif
#ifdef __IC_USB_EEM_SUPPORT__
	USBD_Register_Class_Driver(&USB_Host_Eem_Drv, KAL_FALSE);
#endif	
#ifdef __IC_USB_ICCD_SUPPORT__
	USBD_Register_Class_Driver(&USB_Host_Iccd_Drv, KAL_FALSE);
#endif

	USBD_Register_Class_Driver(&USB_Host_Default_Drv, KAL_TRUE);
*/	

	USBD_Init(usb_ip_port);
}


static void OTG_Host_Down_Hdlr(void)
{
	kal_uint8 usb_ip_port = 0;//USB_OTG_HW_IP_Query();
	USBD_Release_Status(usb_ip_port);
	USBD_Release(usb_ip_port);
}


static void OTG_Device_Up_Hdlr(void)
{	
#ifndef __MEUT__
	OTG_DRV_CTRL_GET_PLUG_TYPE_T  dcl_data;
	OTG_PLUG_TYPE plug_type;


	DclOTG_DRV_Control(g_OTG_Dcl_Handle, OTG_DRV_CMD_GET_PLUG_TYPE, (DCL_CTRL_DATA_T  *)&dcl_data);
	plug_type = (OTG_PLUG_TYPE)dcl_data.type;

//	if(OTG_Get_Plug_Type() == OTG_PLUG_B)
	if(plug_type == OTG_PLUG_B)
	{
		if(gUsbOtg.b_check_srp == KAL_TRUE)
		{
			/* SRP succeed, turn on D+ */
	#if defined(__DM_LAWMO_SUPPORT__)
			if(g_UsbMode.b_lock_usb_boot == KAL_FALSE)
	#endif
			{
				DclOTG_DRV_Control(g_OTG_Dcl_Handle, OTG_DRV_CMD_ENABLE_DEVICE, NULL);
//				OTG_Enable_Device();
			}

		#ifndef __OTG_SRP_HNP_APP_FIXED__
			if((g_UsbMode.usb_comport_boot == USB_NORMAL_BOOT)||(g_UsbMode.usb_menu_en == KAL_TRUE))
			{
				/* Notify UEM */
				USB_Send_Config_Cnf_Msg(gUsbOtg.hnp_srp_type, KAL_TRUE);
			}
		#endif

			/* SRP success, reset to default */
			gUsbOtg.b_check_srp = KAL_FALSE;
			gUsbOtg.hnp_srp_type = USB_UNKOWN;
			/* Set in OTG_Mode_Selection() */
//			g_UsbMode.b_start_srp = KAL_FALSE;
		}
		else
		{
			if(INT_BootMode() == MTK_FACTORY_MODE)
			{
				/* FT mode */
				USB_Init_ACM_In_Meta();	
			}
			else if(INT_IsBootForUSBAT() == KAL_TRUE)
			{
				/* AT mode */
				USB_Init_ACM_In_AT_Mode();	
			}
#if 0// Revise boot mode.				
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#ifdef __USB_MASS_STORAGE_ENABLE__
/* under construction !*/
/* under construction !*/
		#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#ifdef __MTP_ENABLE__
/* under construction !*/
/* under construction !*/
		#endif
/* under construction !*/
/* under construction !*/
		#if defined(__USB_MASS_STORAGE_ENABLE__)||defined(__MTP_ENABLE__)
/* under construction !*/
		#endif
/* under construction !*/
#endif			
			else
			{
				/* Normal mode */
				/* When in B_HOST state and device up, it is HNP second phase */
		#ifdef __OTG_SRP_HNP_APP_FIXED__
				USB_Config_Type(USB_MASS_STORAGE, KAL_TRUE, NULL);
		#else

				/* Notify UEM */
				if((g_UsbMode.usb_comport_boot == USB_NORMAL_BOOT)||(g_UsbMode.usb_menu_en == KAL_TRUE))
				{
					USB_Send_Msg(USB_SEND_MSG_PLUG_IN);
				}
			#if defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
				else if((g_UsbMode.usb_comport_boot >= USB_BOOT_TWO_PORT)&&(g_UsbMode.usb_menu_en == KAL_FALSE))
				{
					USB_Config_Type(USB_COMPOSITE_MULTI_COM, KAL_TRUE, NULL);
				}
			#endif
				else if((g_UsbMode.usb_comport_boot == USB_BOOT_ONE_PORT)&&(g_UsbMode.usb_menu_en == KAL_FALSE))
				{
//			#ifdef __USB_LOGGING__
//					if(g_usb_boot_as_logging_tool == KAL_TRUE)
//						USB_Config_Type(USB_CDC_ACM_LOGGING, KAL_TRUE, NULL);
//					else
//			#endif
						USB_Config_Type(USB_CDC_ACM, KAL_TRUE, NULL);
				}
		#endif /* __OTG_SRP_HNP_APP_FIXED__ */
			}
		}
	}
	else if(plug_type == OTG_PLUG_A)
	{
		/* This must come from HNP phase 1 */
		/* HNP is ok */
		USB_Config_Type(gUsbOtg.hnp_srp_type, KAL_TRUE, gUsbOtg.hnp_srp_parameter);

#ifndef __OTG_SRP_HNP_APP_FIXED__
		if((g_UsbMode.usb_comport_boot == USB_NORMAL_BOOT)||(g_UsbMode.usb_menu_en == KAL_TRUE))
		{
			/* Notify UEM*/
			USB_Send_Config_Cnf_Msg(gUsbOtg.hnp_srp_type, KAL_TRUE);
		}
#endif
		gUsbOtg.hnp_srp_type = USB_UNKOWN;		
	}
	else
	{
		EXT_ASSERT(0, (kal_uint32)plug_type, 0, 0);
	}
#endif /* __MEUT__ */
}


static void OTG_Device_Down_Hdlr(void)
{
#ifndef __MEUT__
	if(INT_BootMode() == MTK_FACTORY_MODE)
	{
		/* No msg to UEM */
		USB_Release_Type(KAL_FALSE, KAL_FALSE);
	}
	else
	{
		USB_Release_Type(KAL_FALSE, KAL_TRUE);
	}
#endif /* __MEUT__ */
}


static void OTG_A_VRise_Fail_Hdlr(void)
{
	OTG_Display_Message(OTG_DISPLAY_MSG_UN_SUPPORT);
}


static void OTG_A_HNP_Fail_Hdlr(void)
{
#ifdef __MTP_ENABLE__
	if(gUsbOtg.hnp_srp_type == USB_IMAGE_MTP)
	{
		/* Send MTP disable msg to MTP task */
		if(g_UsbMode.usb_config_result == KAL_TRUE)
			USB_MTP_Image_Send_Msg(USB_MTP_IMAGE_MSG_DISABLE_REQ);

		USB_Send_Config_Cnf_Msg(USB_IMAGE_MTP, KAL_FALSE);
	}
	else
#endif
	{
#ifdef __USB_MASS_STORAGE_ENABLE__
		if(gUsbOtg.hnp_srp_type == USB_MASS_STORAGE)
		{
			if(g_UsbMode.usb_config_result == KAL_TRUE)
			{
				if(kal_if_hisr() == KAL_TRUE)
					OTG_Hdlr_Send_Msg(OTG_HDLR_TASK_ONLY_END_NORMAL_MS, 0);
				else
					USB_End_Normal_Mode_Ms();
			}
		}
#endif

#ifndef __OTG_SRP_HNP_APP_FIXED__
		if((g_UsbMode.usb_comport_boot == USB_NORMAL_BOOT)||(g_UsbMode.usb_menu_en == KAL_TRUE))
		{
			if(gUsbOtg.hnp_srp_type != USB_UNKOWN)
				USB_Send_Config_Cnf_Msg(gUsbOtg.hnp_srp_type, KAL_FALSE);

			USB_Send_Msg(USB_SEND_MSG_PLUG_OUT);
		}
#endif
	}

	OTG_Display_Message(OTG_DISPLAY_MSG_HNP_STOP);
	gUsbOtg.hnp_srp_type = USB_UNKOWN;
}


/* HNP succeed will call HNP_STOP */
static void OTG_A_HNP_Stop_Hdlr(void)
{
	OTG_Display_Message(OTG_DISPLAY_MSG_HNP_STOP);
}


static void OTG_A_No_Response_Hdlr(void)
{
	OTG_Display_Message(OTG_DISPLAY_MSG_NO_RESPONSE);
}


static void OTG_B_HNP_Fail_Hdlr(void)
{
	OTG_Display_Message(OTG_DISPLAY_MSG_NO_RESPONSE);
}


static void OTG_B_SRP_Fail_Hdlr(void)
{
	if(gUsbOtg.b_check_srp == KAL_FALSE)
	{
		ASSERT(0);
	}

#ifndef __OTG_SRP_HNP_APP_FIXED__
	if((g_UsbMode.usb_comport_boot == USB_NORMAL_BOOT)||(g_UsbMode.usb_menu_en == KAL_TRUE))
	{
		/* If SRP fail will go to here */
		/* Notify UEM */
		USB_Send_Config_Cnf_Msg(gUsbOtg.hnp_srp_type, KAL_FALSE);
	}
#endif

	/* Cable pulg out will be sent here */
	USB_Release_Type(KAL_TRUE, KAL_TRUE);
//	g_UsbMode.usb_comport_boot = USB_NORMAL_BOOT;

	/* Reset to default */
	gUsbOtg.hnp_srp_type = USB_UNKOWN;
	gUsbOtg.b_check_srp = KAL_FALSE;
	g_UsbMode.b_start_srp = KAL_FALSE;

	OTG_Display_Message(OTG_DISPLAY_MSG_NO_RESPONSE);
}


/* SRP OK */
static void OTG_B_SRP_Stop_Hdlr(void)
{
	if(gUsbOtg.b_check_srp == KAL_FALSE)
	{
		ASSERT(0);
	}

	OTG_Display_Message(OTG_DISPLAY_MSG_STOP_CONNECTING);
}


/* Error case, during SRP and then plug in A cable */
static void OTG_B_SRP_Exception_Stop_Hdlr(void)
{
	if(gUsbOtg.b_check_srp == KAL_FALSE)
	{
		ASSERT(0);
	}

#ifndef __OTG_SRP_HNP_APP_FIXED__
	if((g_UsbMode.usb_comport_boot == USB_NORMAL_BOOT)||(g_UsbMode.usb_menu_en == KAL_TRUE))
	{
		/* Notify UEM*/
		USB_Send_Config_Cnf_Msg(gUsbOtg.hnp_srp_type, KAL_FALSE);
	}
#endif

	/* Cable pulg out will be sent here */
	USB_Release_Type(KAL_FALSE, KAL_TRUE);
//	g_UsbMode.usb_comport_boot = USB_NORMAL_BOOT;

	/* Reset to default */
	gUsbOtg.hnp_srp_type = USB_UNKOWN;
	gUsbOtg.b_check_srp = KAL_FALSE;
//	g_UsbMode.b_start_srp = KAL_FALSE;

	OTG_Display_Message(OTG_DISPLAY_MSG_STOP_CONNECTING);
}


static void OTG_Host_Stop_Hdlr(void)
{
	kal_uint8 usb_ip_port = 0;//USB_OTG_HW_IP_Query();
	
	USBD_Release_Status(usb_ip_port);

	if(g_UsbMode.b_start_hnp == KAL_TRUE)
	{
		g_UsbMode.b_start_hnp = KAL_FALSE;

		/* Stop HNP process before A-device choose USB function because B-device disconn or resume */
#ifndef __OTG_SRP_HNP_APP_FIXED__

		DclOTG_DRV_Control(g_OTG_Dcl_Handle, OTG_DRV_CMD_INCR_DISCONNECT_COUNT, NULL);
//		OTG_Incr_Disconn_Count();

		if((g_UsbMode.usb_comport_boot == USB_NORMAL_BOOT)||(g_UsbMode.usb_menu_en == KAL_TRUE))
		{
			/* Notify UEM */
			USB_Send_Msg(USB_SEND_MSG_PLUG_OUT);
		}
#endif
	}
}


void OTG_Display_Message(OTG_DISPLAY_MSG_TYPE otg_msg_type)
{
#ifndef __MEUT__
	module_type src_mod;
	ilm_struct usb_ilm;
	ilm_struct *pUsb_ilm = &usb_ilm;
	otg_display_struct *display_ind;


//	if(kal_if_hisr() == KAL_TRUE)
//		src_mod = MOD_DRV_HISR;
//	else
//		src_mod = MOD_USB;	

	src_mod = stack_get_active_module_id();

	display_ind = (otg_display_struct*)construct_local_para(
					sizeof(otg_display_struct), TD_CTRL);

	display_ind->type = otg_msg_type;

	DRV_BuildPrimitive(pUsb_ilm,
				src_mod,
				MOD_FMT,
				MSG_ID_OTG_DISPLAY_IND,
				display_ind);

	msg_send(pUsb_ilm);
#endif /* __MEUT__ */
}


void OTG_Hdlr_Send_Msg(OTG_HDLR_TASK_TYPE type, kal_uint32* parameter)
{
	ilm_struct usb_ilm;
	ilm_struct *pUsb_ilm = &usb_ilm;
	otg_hdlr_ind_struct *hdlr_ind;


	/* This function is used for OTG HISR to notify task */
	if(kal_if_hisr() == KAL_FALSE)
		ASSERT(0);

	hdlr_ind = (otg_hdlr_ind_struct*)construct_local_para(
					sizeof(otg_hdlr_ind_struct), TD_CTRL);
	hdlr_ind->type = type;
	hdlr_ind->parameter = parameter;
//	hdlr_ind->b_param = b_param;

	DRV_BuildPrimitive(pUsb_ilm,
				stack_get_active_module_id(),
				MOD_USB,
				MSG_ID_OTG_HDLR_IND,
				hdlr_ind);

	msg_send(pUsb_ilm);
}


/* This function should be called when B device is set HNP enabled by A device */
void OTG_B_EnDis_HNP(kal_bool set)
{
	DCL_BOOL dcl_data;


	dcl_data = (DCL_BOOL)set;
	DclOTG_DRV_Control(g_OTG_Dcl_Handle, OTG_DRV_CMD_B_EN_DIS_HNP, (DCL_CTRL_DATA_T *)&dcl_data);
}


void OTG_B_Set_Session_Valid(kal_bool set)
{
	DCL_BOOL dcl_data;


	dcl_data = (DCL_BOOL)set;
	DclOTG_DRV_Control(g_OTG_Dcl_Handle, OTG_DRV_CMD_B_SET_SESSION_VALID, (DCL_CTRL_DATA_T *)&dcl_data);
}


#endif  /* __OTG_ENABLE__ */

