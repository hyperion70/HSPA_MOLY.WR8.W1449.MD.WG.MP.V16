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
 *    usb_mode.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements usb mode selection
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
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
 * removed!
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

#include "drv_comm.h"
////#include "stack_common.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
////#include "app_ltlcom.h"       /* Task message communiction */
////#include "syscomp_config.h"
////#include "task_config.h"
////#include "stacklib.h"
//#include "reg_base.h"
#include "usb_comm.h"
#include "drvsignals.h"
//#include "Eint.h"
////#include "kal_release.h"
#include "intrCtrl.h"
#include "init.h"

//#include "usb_drv.h"
#include "usb_adap.h"
#include "usb.h"
#include "usb_resource.h"

#ifdef __USB_MASS_STORAGE_ENABLE__
#include "usbms_drv.h"
//#include "usbms_state.h"
#include "usbms_adap.h"
#include "usb_msdisk.h"
#endif

#ifdef __USB_COM_PORT_ENABLE__
#include "usbacm_adap.h"
#include "usbacm_drv.h"
#include "usbacm_ft.h"

#ifdef __USB_LOGGING__
#include "usbacm_logging.h"
#include "usblog_drv.h"
#endif /*__USB_LOGGING__*/
#endif /*__USB_COM_PORT_ENABLE__*/

#ifdef WEBCAM_SUPPORT
#include "usbvideo_drv.h"
#include "usbvideo_state.h"
#endif

#ifdef __USB_IMAGE_CLASS__
#include "usbimage_drv.h"
#endif
#ifdef PICTBRIDGE_SUPPORT
#include "ptp_state.h"
#endif

#ifdef __OTG_ENABLE__
//#include "otg_drv.h"
#include "otg.h"
//#include "usbd.h"
//#include "usb_host_ms_state.h"
#endif
#include "usb_task.h"
#include "usb_mode.h"
#include "usb_custom.h"

//#include "app_buff_alloc.h"
//#include "nvram.h"
//#include "nvram_interface.h"
//#include "nvram_user_defs.h"
#include "usb_trc.h"
#include "usb_debug_tool.h"


//#ifdef MT6318
//#include "pmic6318_sw.h"
//#endif

//#include "fat_fs.h"
//#include "Rtfiles.h"

#ifdef __MULTI_BOOT__
#include "multiboot_config.h"
#endif /* __MULTI_BOOT__ */

#ifdef __USB_STRESS_TEST__
#include "usbacm_echo.h"
#endif

#include "fs_type.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "uart_sw.h"
#include "kal_trace.h"
#include "fs_func.h"
#include "fs_errcode.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#ifdef __USB_LOGGING__
#include "drv_sw_features_usb.h"
#endif
#if defined(__MTP_ENABLE__)||defined(__USB_MASS_STORAGE_ENABLE__)||defined(__OTG_SRP_HNP_APP_FIXED__)
#include "usb_custom_def.h"
#endif

#include "drv_msgid.h"
#include "fs_iprot.h"


Usb_Mode_Struct g_UsbMode;

#if defined(__MTP_ENABLE__)||defined(__USB_MASS_STORAGE_ENABLE__)||defined(__OTG_SRP_HNP_APP_FIXED__)
extern kal_uint8 USB_TEST_Buffer[USBMS_MAX_BUFFERSIZE];
#endif

extern kal_uint8 INT_Exception_Enter;
extern kal_bool is_init_log_enable;
extern kal_bool is_init_stage;

/* extern functions */
extern kal_uint16 INT_BootMode(void);
extern kal_bool INT_USBBoot(void);
extern kal_uint8 g_usb_logging_port_num;
#if defined (__USB_MODEM_CARD_SUPPORT__)
extern void tst_file_notify_sd_ready(void);
#endif

#ifdef  __USB_MASS_STORAGE_ENABLE__
/* static functions */
#ifdef __USB_IN_NORMAL_MODE__
#if !defined(__MODEM_CARD__) || !defined(__MODEM_CCCI_EXIST__)	
static FS_DEVICE_TYPE_ENUM USB_Ms_Dev_To_Fs_Type(USB_STORAGE_DEV_TYPE type);
#endif
#endif
static void USB_End_Ms(void);
#endif
#ifdef __OTG_ENABLE__
static kal_bool b_is_fs_lock = KAL_FALSE;
#endif

static USB_COMPOSITE_DEVICE_TYPE usb_compsite_table[USB_MAX_COMPOSITE_DEVICES];
static kal_uint32 usb_compsite_table_indx;

/************************************************************
	mode selection  functions
*************************************************************/


#if defined(__MTP_ENABLE__)||defined(__USB_MASS_STORAGE_ENABLE__)
static void USB_Check_Run_On_HISR()
{
	if(kal_if_hisr() == KAL_TRUE)
		ASSERT(0);
}
#endif

kal_bool USB_Check_Composite_With_COM(USB_DEVICE_TYPE type)
{
	if ((type == USB_COMPOSITE_MULTI_COM)||(type == USB_COMPOSITE_RNDIS_COM)||(type == USB_COMPOSITE_VIDEO_COM)||(type == USB_COMPOSITE_DEVICES)
		 ||(type == USB_MORPHING_MBIM))
		return KAL_TRUE;
	else
		return KAL_FALSE;

}

void USB_Init_Mode(void)
{
	g_UsbMode.mode_param = 0x00;
	g_UsbMode.cable_type = USB_MODE_CABLE_PLUGOUT;
	g_UsbMode.previous_cable_type = USB_MODE_CABLE_PLUGOUT;
#if defined (__USB_MODEM_CARD_SUPPORT__)
//	g_UsbMode.usb_comport_driver = USB_COMPORT_WIN_SINGLE_INTERFACE;
//#else
	g_UsbMode.usb_comport_driver = USB_COMPORT_WIN;
#endif
	gUsbDevice.usb_send_config_result = KAL_TRUE;
#if defined(__USB_MASS_STORAGE_ENABLE__)||defined(__MTP_ENABLE__)
	g_UsbMode.b_ms_first_plugin = KAL_TRUE;
#endif
#ifdef __OTG_ENABLE__
	g_UsbMode.b_start_srp = KAL_FALSE;
	g_UsbMode.b_start_hnp = KAL_FALSE;
	g_UsbMode.b_usb_pdnmode = KAL_TRUE;
#endif
}


#ifdef __OTG_ENABLE__

void OTG_Mode_Selection(void)
{
#ifndef __MEUT__
	USB_DRV_CTRL_PHY_FUNC_T  dcl_data;
	kal_bool b_is_power_down = KAL_FALSE;
	OTG_DRV_CTRL_GET_PLUG_TYPE_T dcl_plug_type;
	OTG_PLUG_TYPE plug_type = OTG_PLUG_B;


	/* FT mode */
	if (INT_BootMode() == MTK_FACTORY_MODE)
	{
		if((g_UsbMode.mode_param&(1<<(kal_uint32)USB_MODE_NVRAM_READ_DONE)) != 0)
		{
	#ifdef __USB_COM_PORT_ENABLE__ //__USB_DOWNLOAD__
			if(((g_UsbMode.mode_param&(1<<(kal_uint32)USB_MODE_FT_START_DONE)) != 0)||(USBDL_Mode_Type()!= USBDL_MODE_NONE))
				//(USBDL_Is_USB_Download_Mode() == KAL_TRUE)||(USBDL_Is_USB_Fast_Meta_Mode()== KAL_TRUE))
	#else
			if((g_UsbMode.mode_param&(1<<(kal_uint32)USB_MODE_FT_START_DONE)) != 0)
	#endif
			{
				DclOTG_DRV_Control(g_OTG_Dcl_Handle, OTG_DRV_CMD_GET_PLUG_TYPE, (DCL_CTRL_DATA_T  *)&dcl_plug_type);
				plug_type = (OTG_PLUG_TYPE)dcl_plug_type.type;

//				if(OTG_Get_Plug_Type() == OTG_PLUG_B)
				if(plug_type == OTG_PLUG_B)
				{
					OTG_Init_Phase1();
					OTG_B_Set_Session_Valid(KAL_TRUE);
				}
			}
		}
		return;
	}

	/* AT mode */
	if (INT_IsBootForUSBAT() == KAL_TRUE)
	{
		if((g_UsbMode.mode_param&(1<<(kal_uint32)USB_MODE_NVRAM_READ_DONE)) != 0)
		{
//			if(OTG_Get_Plug_Type() == OTG_PLUG_B)
			if(plug_type == OTG_PLUG_B)			
			{
				OTG_Init_Phase1();
				OTG_B_Set_Session_Valid(KAL_TRUE);
			}
		}
		return;
	}


	/* Normal mode, not SRP */
#if 0 // Revise boot mode.	
/* under construction !*/
#else
    if ((g_UsbMode.cable_type != USB_MODE_CABLE_PLUGOUT)&&(g_UsbMode.cable_type != USB_MODE_CABLE_ERROR)
#endif
		&&((g_UsbMode.mode_param&(1<<(kal_uint32)USB_MODE_NVRAM_READ_DONE)) != 0)&&(g_UsbMode.b_start_srp == KAL_FALSE))
	{
		DclOTG_DRV_Control(g_OTG_Dcl_Handle, OTG_DRV_CMD_GET_PLUG_TYPE, (DCL_CTRL_DATA_T  *)&dcl_plug_type);
		plug_type = (OTG_PLUG_TYPE)dcl_plug_type.type;

//		if(OTG_Get_Plug_Type() == OTG_PLUG_A)
		if(plug_type == OTG_PLUG_A)
		{
			/* Enable USB power */
			if(g_UsbMode.b_usb_pdnmode == KAL_TRUE)
			{
				g_UsbMode.b_usb_pdnmode = KAL_FALSE;
				USB_PDNmode(KAL_FALSE);
				OTG_Init_Phase1();
				OTG_Init_Phase2();

				/* A cable must enable phy power for V2 */
//				USB_Phy_Enable(USB_PHY_OWNER_USB);
				dcl_data.owner = DCL_USB_PHY_OWNER_USB;
				DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_PHY_ENABLE, (DCL_CTRL_DATA_T  *)&dcl_data);
			}
		}
		else
		{
			OTG_Init_Phase1();
			OTG_B_Set_Session_Valid(KAL_TRUE);
		}

		return;
	}

#if 0 // Revise boot mode.
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#ifdef __MTP_ENABLE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

	/* Cable plug out */
	if(((g_UsbMode.cable_type == USB_MODE_CABLE_PLUGOUT)&&(g_UsbMode.previous_cable_type != USB_MODE_CABLE_PLUGOUT))||
		((g_UsbMode.cable_type == USB_MODE_CABLE_ERROR)&&(g_UsbMode.previous_cable_type == USB_MODE_CABLE_A_PLUGIN)))
	{
//		g_UsbMode.b_start_hnp = KAL_FALSE;
		g_UsbMode.b_start_srp = KAL_FALSE;

		USB_Dbg_Trace(USB_OTG_MODE_SELECTION, g_UsbMode.cable_type, g_UsbMode.b_usb_pdnmode);

		if(g_UsbMode.cable_type == USB_MODE_CABLE_PLUGOUT)
		{
			/* Power down USB */
			/* If user does not choose function, it will be TRUE */
			if(g_UsbMode.b_usb_pdnmode == KAL_FALSE)
			{
				g_UsbMode.b_usb_pdnmode = KAL_TRUE;
				USB_PDNmode(KAL_TRUE);
				b_is_power_down = KAL_TRUE;
			}

			/* Release SW here */
			DclOTG_DRV_Control(g_OTG_Dcl_Handle, OTG_DRV_CMD_PROCESS_EXCEPTIONS, NULL);
//			OTG_Process_Exceptions();
			OTG_Release();
			USB_Free_Memory();

			if(b_is_power_down == KAL_TRUE)
			{
//				USB_Release_Drv();
				DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_RELEASE_DRV, NULL);
			}
		}
		else if (g_UsbMode.cable_type == USB_MODE_CABLE_ERROR)
		{
			/* Release SW here */
			DclOTG_DRV_Control(g_OTG_Dcl_Handle, OTG_DRV_CMD_PROCESS_EXCEPTIONS, NULL);
//			OTG_Process_Exceptions();

			g_UsbMode.cable_type = USB_MODE_CABLE_A_PLUGIN;
			g_UsbMode.previous_cable_type = USB_MODE_CABLE_PLUGOUT;
		}

		g_UsbMode.b_start_hnp = KAL_FALSE;
		return;
	}

	/* Normal mode and SRP is start */
	if((g_UsbMode.b_start_srp == KAL_TRUE)&&(g_UsbMode.usb_boot == KAL_FALSE))
	{
		if(g_UsbMode.cable_type == USB_MODE_CABLE_B_PLUGIN)
		{
			/* SRP succeed, so detect B plug in */
			g_UsbMode.b_start_srp = KAL_FALSE;
		}
		else if(g_UsbMode.cable_type == USB_MODE_CABLE_A_PLUGIN)
		{
			g_UsbMode.b_start_srp = KAL_FALSE;
			/* In case B device do SRP procedure, then A plug is plugged at this time */
			DclOTG_DRV_Control(g_OTG_Dcl_Handle, OTG_DRV_CMD_PROCESS_EXCEPTIONS, NULL);
//			OTG_Process_Exceptions();
		}
	}
#endif /* __MEUT__ */
}

#else

void USB_Mode_Selection(void)
{
#ifndef __MEUT__
	if(g_UsbMode.cable_type == USB_MODE_CABLE_A_PLUGIN)
		ASSERT(0);
	#ifdef __USB_COM_PORT_ENABLE__
	/* FT mode */
	if(INT_BootMode() == MTK_FACTORY_MODE)
	{
		if((g_UsbMode.mode_param&(1<<(kal_uint32)USB_MODE_NVRAM_READ_DONE)) != 0)
		{
	#ifdef __USB_COM_PORT_ENABLE__ //__USB_DOWNLOAD__
			if(((g_UsbMode.mode_param&(1<<(kal_uint32)USB_MODE_FT_START_DONE)) != 0)||(USBDL_Mode_Type()!= USBDL_MODE_NONE))
			//	(USBDL_Is_USB_Download_Mode() == KAL_TRUE)||(USBDL_Is_USB_Fast_Meta_Mode()== KAL_TRUE))
	#else
			if((g_UsbMode.mode_param&(1<<(kal_uint32)USB_MODE_FT_START_DONE)) != 0)
	#endif
			{
				USB_Init_ACM_In_Meta();
			}
		}
		return;
	}

	/* AT mode */
	if (INT_IsBootForUSBAT() == KAL_TRUE)
	{
		if(((g_UsbMode.mode_param&(1<<(kal_uint32)USB_MODE_NVRAM_READ_DONE)) != 0)&& (g_UsbMode.cable_type != USB_MODE_CABLE_PLUGOUT))
		{
			USB_Init_ACM_In_AT_Mode();
		}
		return;
	}

	#endif /*__USB_COM_PORT_ENABLE__*/

	/*  Normal mode */
#if 0 // Revise boot mode.	
/* under construction !*/
#else
if ((g_UsbMode.cable_type != USB_MODE_CABLE_PLUGOUT)
#endif
		&&((g_UsbMode.mode_param&(1<<(kal_uint32)USB_MODE_NVRAM_READ_DONE)) != 0)
		&&((g_UsbMode.usb_comport_boot == USB_NORMAL_BOOT)||(g_UsbMode.usb_menu_en == KAL_TRUE)))
	{
		/* Notify UEM*/
		USB_Send_Msg(USB_SEND_MSG_PLUG_IN);
		return;
	}
#if 0 // Revise boot mode.
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#ifdef __USB_MASS_STORAGE_ENABLE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#ifdef __MTP_ENABLE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	/* Cable plug out */
	if((g_UsbMode.cable_type == USB_MODE_CABLE_PLUGOUT) && (g_UsbMode.previous_cable_type != USB_MODE_CABLE_PLUGOUT))
	{
		USB_Release_Type(KAL_TRUE, KAL_TRUE);
		USB_Free_Memory();
	}
#endif /* __MEUT__ */
}

#endif


/************************************************************
	Configure mode functions
*************************************************************/
#ifdef __USB_COM_PORT_ENABLE__

static void USB_Register_Com_Port1(void)
{
#ifdef  __USB_COMPORT_SUPPORT_TC01_DRIVER__
		//Modem port
		USB_Register_CreateFunc("ACM COMMU1", USB_Acm1_CommIf_Create, USB_Acm1_CommIf_Reset,
								USB_Acm1_CommIf_Enable, USB_Acm1_CommIf_Speed_Reset, NULL);
		USB_Register_CreateFunc("ACM DATA1", USB_Acm1_DataIf_Create, USB_Acm1_DataIf_Reset,
									USB_Acm1_DataIf_Enable, USB_Acm1_DataIf_Speed_Reset, NULL);
#else
	#if defined (__USB_MODEM_CARD_SUPPORT__)
		if(1)// (g_UsbMode.usb_comport_driver == USB_COMPORT_WIN_SINGLE_INTERFACE)
		{
			USB_Register_CreateFunc("ACM_DATA1_AND_COMM1", USB_Acm_DataCommIf_Create, USB_Acm_DataCommIf_Reset,
								USB_Acm_DataCommIf_Enable, USB_Acm_DataCommIf_Speed_Reset, NULL);
		}
		else
	#endif
		{
		/* initailize CDC_ACM */
			USB_Register_CreateFunc("ACM DATA1", USB_Acm1_DataIf_Create, USB_Acm1_DataIf_Reset,
									USB_Acm1_DataIf_Enable, USB_Acm1_DataIf_Speed_Reset, NULL);
			USB_Register_CreateFunc("ACM COMMU1", USB_Acm1_CommIf_Create, USB_Acm1_CommIf_Reset,
								USB_Acm1_CommIf_Enable, USB_Acm1_CommIf_Speed_Reset, NULL);
		}								
#endif
}

#if defined(__USB_COMPORT_SUPPORT_TC01_DRIVER__)&& defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
static void USB_Register_TC01_Com_Port2(void)
{
	//Diagnostic port
	USB_Register_CreateFunc("ACM VEND.", USB_Acm_VendorIf_Create, USB_Acm_VendorIf_Reset,
							USB_Acm_VendorIf_Enable, USB_Acm_VendorIf_Speed_Reset, NULL);
}
#endif

static void USB_Enable_Com_Port1(void)
{
			/* Because we already pull high D+ at boot loader */

#if defined(__USB_COMPORT_SUPPORT_TC01_DRIVER__)&& defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
			USB_Init(USB_COMPOSITE_MULTI_COM, KAL_FALSE, KAL_TRUE); //cannot open USB_IRQ,until USB ACM Reset
#else
			USB_Init(USB_CDC_ACM, KAL_FALSE, KAL_TRUE); //cannot open USB_IRQ,until USB ACM Reset
#endif

			// Meta tool use polling way: continue sending Data, so Interrupt will happen.
			USB_Set_Device_State(DEVSTATE_CONFIG);

#if defined(__USB_COMPORT_SUPPORT_TC01_DRIVER__)&& defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
			USB_Acm_VendorIf_Reset();
			USB_Acm_VendorIf_Enable();
#else
			USB_Acm1_DataIf_Reset();
			USB_Acm1_DataIf_Enable();
			USB_Acm1_CommIf_Reset();
			USB_Acm1_CommIf_Enable();
#endif


			//Activate ISR & unmask IRQ
		#ifndef __OTG_ENABLE__

				/* LISR should be unmask after all initialize and enable any USB interrupt */
//				USB_Drv_Activate_ISR();
				DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_DRV_ACTIVATE_ISR, NULL);

//				USBDMA_Drv_Activate_ISR();
				DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_DMA_DRV_ACTIVATE_ISR, NULL);

		#else  //OTG must open interrupt

				if (g_UsbMode.b_usb_pdnmode == KAL_TRUE)
				{
					g_UsbMode.b_usb_pdnmode = KAL_FALSE;
					DclOTG_DRV_Control(g_OTG_Dcl_Handle, OTG_DRV_CMD_DRV_ACTIVATE_ISR, NULL);
//					OTG_Drv_Activate_ISR();
				}

				DclOTG_DRV_Control(g_OTG_Dcl_Handle, OTG_DRV_CMD_DMA_DRV_ACTIVATE_ISR, NULL);
//				OTGDMA_Drv_Activate_ISR();


		#endif	/* __OTG_ENABLE__ */
		
}


void USB_Init_ACM_In_Meta(void)
{
	static kal_bool b_init_acm_meta = KAL_FALSE;
	USB_DRV_CTRL_EP_CTRL_FUNC_3_T dcl_data;
	kal_uint32 tx_count;


	if(b_init_acm_meta == KAL_TRUE)
	{
		return;
	}
	else	//(b_init_acm_meta == KAL_FALSE)
	{
		b_init_acm_meta = KAL_TRUE;

		/* init ft acm parameters*/
		USB_Acm_FT_Init(); //set factory mode port number

		USB_Register_Com_Port1();
		#if defined(__USB_COMPORT_SUPPORT_TC01_DRIVER__)&& defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
			USB_Register_TC01_Com_Port2();
		#endif
		USB_Register_Device_Code(USB_ACM_DEVICE_CODE, USB_ACM_SUBCLASS_CODE,USB_ACM_PROTOCOL_CODE, g_UsbACM_Comm.acm_param->desc_product);

#ifndef __USB_COM_PORT_ENABLE__ //__USB_DOWNLOAD__

#if defined(__USB_COMPORT_SUPPORT_TC01_DRIVER__)&& defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
		USB_Init(USB_COMPOSITE_MULTI_COM, KAL_TRUE, KAL_FALSE);
#else
		USB_Init(USB_CDC_ACM, KAL_TRUE, KAL_FALSE);
#endif

#else
		if(USBDL_Mode_Type()== USBDL_MODE_USB_DOWNLOAD)//(USBDL_Is_USB_Download_Mode() == KAL_TRUE)
		{
			USB_Enable_Com_Port1();

			dcl_data.u4ep_num = (DCL_UINT32)g_UsbACM[g_UsbACM_Comm.ft_port_num].txpipe->byEP;
			DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_TXEP_PK_SIZE, (DCL_CTRL_DATA_T  *)&dcl_data);
			tx_count = (kal_uint32)dcl_data.u4result;

			// Use ep to make sure USB max packet size is correct (bootloader & MAUI load is the same version)
			if (tx_count != USB_Bulk_Max_Packet_Size())
				ASSERT(0);
/*			
			if (USB_Is_High_Speed() == KAL_TRUE)
			{
				//USBDL_EP_BULK_MAXP : HS Enable = 512 , FS Only = 64
				if(tx_count != USBDL_EP_BULK_MAXP)
				   ASSERT(0);
			}
			else
			{
				if(tx_count!= USB_EP_BULK_MAXP_FS)
				ASSERT(0);
			}
*/

			//if TST putbytes before USB Ready, send ready to write message
			if(g_UsbACM[g_UsbACM_Comm.ft_port_num].config_send_Txilm == KAL_TRUE)
			{
				g_UsbACM[g_UsbACM_Comm.ft_port_num].send_Txilm = KAL_TRUE;

				/* if someone PutBytes before usb ready, then issue ready-to-write message */
				if(USB2UARTPort[g_UsbACM_Comm.ft_port_num].tx_cb != NULL)
					USB2UARTPort[g_UsbACM_Comm.ft_port_num].tx_cb(USB2UARTPort[g_UsbACM_Comm.ft_port_num].port_no);
			}
		}
		else
		{
			USB_Init(USB_CDC_ACM, KAL_TRUE,KAL_FALSE);
		}
#endif
	}
}



void USB_Init_ACM_In_AT_Mode(void)
{

	USB_Register_Com_Port1();
	#if defined(__USB_COMPORT_SUPPORT_TC01_DRIVER__)&& defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
		USB_Register_TC01_Com_Port2();
	#endif	
	USB_Register_Device_Code(USB_ACM_DEVICE_CODE, USB_ACM_SUBCLASS_CODE,USB_ACM_PROTOCOL_CODE, g_UsbACM_Comm.acm_param->desc_product);

	USB_Enable_Com_Port1();
}


#endif /*__USB_COM_PORT_ENABLE__*/


USBDL_MODE_PRARM USBDL_Mode_Type(void)
{
	DCL_BOOL  dcl_data;
	DCL_HANDLE usb_dcl_handle;
	USBDL_MODE_PRARM  mode = USBDL_MODE_NONE;
	
	usb_dcl_handle = DclUSB_DRV_Open(DCL_USB, FLAGS_NONE);

	DclUSB_DRV_Control(usb_dcl_handle, USB_DRV_CMD_USBDL_IS_USB_DL_MODE, (DCL_CTRL_DATA_T  *)&dcl_data);
	if (dcl_data)
		mode = USBDL_MODE_USB_DOWNLOAD;
	else
	{
		DclUSB_DRV_Control(usb_dcl_handle, USB_DRV_CMD_USBDL_IS_USB_FAST_META_MODE, (DCL_CTRL_DATA_T  *)&dcl_data);
		if (dcl_data)
			mode = USBDL_MODE_FAST_META;
	}

	DclUSB_DRV_Close(usb_dcl_handle);

	return mode;

}

kal_bool USB_Exception_Check(void)
{
	/* This function can only be called after exception*/
#if defined(__USB_BOOTUP_TRACE__)
	if(INT_Exception_Enter == 0 && (!(is_init_log_enable == KAL_TRUE && is_init_stage == KAL_TRUE)))
#else
	if(INT_Exception_Enter == 0)
#endif
		return KAL_TRUE;
	else
		return KAL_FALSE;
}


/* The enable parameter decides whether to turn on D+ at this time, use in SRP */
void USB_Config_Type(USB_DEVICE_TYPE type, kal_bool b_enable, kal_uint32 *parameter)
{
#ifdef __USB_LOGGING__
	kal_uint32 usb_port;
#endif

	if(type != USB_STOP_MTP)
		g_UsbMode.usb_config_result = KAL_TRUE;

	if((g_UsbMode.usb_comport_boot != USB_NORMAL_BOOT)&&(g_UsbMode.usb_menu_en == KAL_FALSE))
	{
		/* STOP_MS or STOP_MTP is for USB boot up mode */
//		if((type != USB_STOP_MS)&&(type != USB_STOP_MTP)
//			&&(type != USB_CDC_ACM)&&(type != USB_COMPOSITE_MULTI_COM)
//			&&(type != USB_COMPOSITE_RNDIS_COM)&&(type != USB_COMPOSITE_VIDEO_COM)
//			&&(type != USB_MASS_STORAGE_CDROM_ONLY))
		if((type != USB_STOP_MS)&&(type != USB_STOP_MTP)&&(type != USB_MASS_STORAGE_CDROM_ONLY)
			&&(type != USB_MORPHING_MBIM) &&(type != USB_CDC_ACM)
			&&(USB_Check_Composite_With_COM(type)!= KAL_TRUE))
			ASSERT(0);
//			EXT_ASSERT(0, (kal_uint32)type, 0, 0);
	}
	else
	{
	 #if 0 // Revise boot mode.
/* under construction !*/
/* under construction !*/
/* under construction !*/
	 #endif	
	}

	if(((USB_Get_Device_Type() != USB_UNKOWN)&&(type != USB_STOP_MS)&&(type != USB_STOP_MTP))
		||(((USB_Get_Device_Type() != USB_MASS_STORAGE)&&(USB_Get_Device_Type() != USB_MASS_STORAGE_CDROM_ONLY))&&(type == USB_STOP_MS))
		||((USB_Get_Device_Type() != USB_IMAGE_MTP)&&(type == USB_STOP_MTP)))
	{
		ASSERT(0);
//		EXT_ASSERT(0, (kal_uint32)USB_Get_Device_Type(), (kal_uint32)type, 0);
	}

	switch(type)
	{
#ifdef __USB_COM_PORT_ENABLE__
#if defined(__USB_DATA_CONNECTION__)
	case USB_DATA_CONNECTION_COM:
#endif
#if defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
	case USB_COMPOSITE_MULTI_COM:
#endif
	case USB_CDC_ACM:
#ifdef __USB_LOGGING__

		if(g_usb_logging_port_num != 0)
		{
			if(g_UsbMode.usb_comport_boot == 0)
				ASSERT(0);

			/* Reset owner id, to avoid UART owner still use USB com port after USB had been config as logging mode */
			/* Logging ports must be the last ports */
			for(usb_port = (g_UsbMode.usb_comport_boot - g_usb_logging_port_num); usb_port < MAX_USB_PORT_NUM; usb_port++)
			{
				USB2UARTPort[usb_port].ownerid = MOD_DRV_HISR;
			}

			USBACM_LOGGING_Init();

	#ifdef __DSPIRDBG__
		#ifdef __USB_SW_LOGGING_WITH_ISR__
			USB_LOGGING_DSP_Drv_Activate_ISR();
		#endif
	#endif
		}
#endif	/*__USB_LOGGING__*/

		g_UsbACM_Comm.acm_owner = USB_ACM_OWNER_UART;

		/* Com port 1 */
		USB_Register_Com_Port1();

/*		
	#ifdef __USB_COMPORT_SUPPORT_TC01_DRIVER__
		USB_Register_CreateFunc("ACM COMMU1", USB_Acm1_CommIf_Create, USB_Acm1_CommIf_Reset,
								USB_Acm1_CommIf_Enable, USB_Acm1_CommIf_Speed_Reset, NULL);
		USB_Register_CreateFunc("ACM DATA1", USB_Acm1_DataIf_Create, USB_Acm1_DataIf_Reset,
								USB_Acm1_DataIf_Enable, USB_Acm1_DataIf_Speed_Reset, NULL);
	#else
		#if defined (__USB_MODEM_CARD_SUPPORT__)
		if (g_UsbMode.usb_comport_driver == USB_COMPORT_WIN_SINGLE_INTERFACE)
		{
			USB_Register_CreateFunc("ACM_DATA1_AND_COMM1", USB_Acm_DataCommIf_Create, USB_Acm_DataCommIf_Reset,
								USB_Acm_DataCommIf_Enable, USB_Acm_DataCommIf_Speed_Reset, NULL);
		}
		else
		#endif
		{
			USB_Register_CreateFunc("ACM DATA1", USB_Acm1_DataIf_Create, USB_Acm1_DataIf_Reset,
								USB_Acm1_DataIf_Enable, USB_Acm1_DataIf_Speed_Reset, NULL);
			USB_Register_CreateFunc("ACM COMMU1", USB_Acm1_CommIf_Create, USB_Acm1_CommIf_Reset,
								USB_Acm1_CommIf_Enable, USB_Acm1_CommIf_Speed_Reset, NULL);
		}
	#endif
*/
#if defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
		if(type == USB_COMPOSITE_MULTI_COM || type == USB_DATA_CONNECTION_COM)
		{
			/* Com port 2 */
	#ifdef __USB_COMPORT_SUPPORT_TC01_DRIVER__
			USB_Register_TC01_Com_Port2();
	#elif defined(__USB_COMPORT_SUPPORT_MTK_DRIVER__)
			USB_Register_CreateFunc("ACM DATA2", USB_Acm2_DataIf_Create, USB_Acm2_DataIf_Reset,
								USB_Acm2_DataIf_Enable, USB_Acm2_DataIf_Speed_Reset, NULL);
		#if defined (__USB_MODEM_CARD_SUPPORT__)
	    if (g_UsbMode.usb_comport_boot == USB_BOOT_THREE_PORT)
	    {
				USB_Register_CreateFunc("ACM DATA3", USB_Acm3_DataIf_Create, USB_Acm3_DataIf_Reset,
									USB_Acm3_DataIf_Enable, USB_Acm3_DataIf_Speed_Reset, NULL);
			    tst_file_notify_sd_ready();	/* This function is used by USB driver under data card projects.
								 * On data card projects, MS reports itself as CDROM in the begining.
								 * Then SD card is locked. 
								 * SD card will be unlocked if we set it as 3 comports
								 */
	    }
	    else
	    {
//				g_UsbMS.disk_buffer = (void*)USB_TEST_Buffer;
				
				USB_Ms_Set_Current_Driver(LOGIC_DRIVE_MS);
				if (USB_Ms_Get_Max_LUN() != USBMS_INVALID_MAX_LUN)
				{
					USB_Init_Normal_Mode_Ms();
//					USB_Init_Normal_Mode_Ms((kal_uint32 *)g_UsbMS.disk_buffer);
					
					/* Initialize MASS STORAGE MODE */
					if(g_UsbMode.usb_config_result == KAL_TRUE)
					{
						/* Initialize storage function */
						USB_Register_CreateFunc("MASS STORAGE", USB_Ms_If_Create, USB_Ms_If_Reset,
							USB_Ms_If_Enable, USB_Ms_If_Speed_Reset, USB_Ms_If_Resume);
					}
					else
					{
						USB_End_Normal_Mode_Ms();
					}
				}
				else
				{
					tst_file_notify_sd_ready();/* This function is used by USB driver under data card projects.
								    * On data card projects, MS reports itself as CDROM in the begining.
								    * Then SD card is locked. 
								    * SD card will be unlocked if we set it as 3 comports
								    */
				}
			}
		#endif //__USB_MODEM_CARD_SUPPORT__
	#else //__USB_COMPORT_SUPPORT_MTK_DRIVER__
			USB_Register_CreateFunc("ACM DATA2", USB_Acm2_DataIf_Create, USB_Acm2_DataIf_Reset,
								USB_Acm2_DataIf_Enable, USB_Acm2_DataIf_Speed_Reset, NULL);
			USB_Register_CreateFunc("ACM COMMU2", USB_Acm2_CommIf_Create, USB_Acm2_CommIf_Reset,
								USB_Acm2_CommIf_Enable, USB_Acm2_CommIf_Speed_Reset, NULL);
	#endif
		}
#endif

#if !defined(__USB_COMPORT_SUPPORT_TC01_DRIVER__)
	#if defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
		#if defined (__USB_MODEM_CARD_SUPPORT__)
		if(type == USB_COMPOSITE_MULTI_COM)// && (g_UsbMode.usb_comport_driver == USB_COMPORT_WIN_SINGLE_INTERFACE))
		{
	        if (g_UsbMode.usb_comport_boot == USB_BOOT_TWO_PORT)//2comprt + mass storage case
            	USB_Register_Device_Code(0x00, 0x00, 0x00, g_UsbACM_Comm.acm_param->desc_product_port_3);
        	else
							USB_Register_Device_Code(0x00, 0x00, 0x00, g_UsbACM_Comm.acm_param->desc_product_dual_port);
		}
		else
		#endif //__USB_MODEM_CARD_SUPPORT__
		#if defined(__USB_DATA_CONNECTION__)
		if (type == USB_DATA_CONNECTION_COM)
		{
			USB_Register_Device_Code(USB_COMPOSITE_DEVICE_CODE, USB_COMPOSITE_SUBCLASS_CODE,
								USB_COMPOSITE_PROTOCOL_CODE, g_UsbACM_Comm.acm_param->desc_data_connection_product_dual_port);
			type = USB_COMPOSITE_MULTI_COM;
		}
		else
		#endif //__USB_DATA_CONNECTION__
		{
			if(type == USB_COMPOSITE_MULTI_COM && ((g_UsbMode.usb_comport_driver == USB_COMPORT_WIN)||(g_UsbMode.usb_comport_driver == USB_COMPORT_LINUX)))
			{
	        #if defined (__USB_MODEM_CARD_SUPPORT__)
	            if (g_UsbMode.usb_comport_boot == USB_BOOT_TWO_PORT)//2comprt + mass storage case
          			{
          					USB_Register_Device_Code(USB_COMPOSITE_DEVICE_CODE, USB_COMPOSITE_SUBCLASS_CODE,
                                     					USB_COMPOSITE_PROTOCOL_CODE, g_UsbACM_Comm.acm_param->desc_product_port_3);
          			}
          			else
	        		#endif
	        		{
			    		USB_Register_Device_Code(USB_COMPOSITE_DEVICE_CODE, USB_COMPOSITE_SUBCLASS_CODE,
								USB_COMPOSITE_PROTOCOL_CODE, g_UsbACM_Comm.acm_param->desc_product_dual_port);
				}
			}
			else
	#endif //__USB_MULTIPLE_COMPORT_SUPPORT__
#endif //__USB_COMPORT_SUPPORT_TC01_DRIVER__
			{
	      #if defined(__USB_MODEM_CARD_SUPPORT__) && defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
	        if (g_UsbMode.usb_comport_boot == USB_BOOT_TWO_PORT)//2comprt + mass storage case
				{
					USB_Register_Device_Code(USB_ACM_DEVICE_CODE, USB_ACM_SUBCLASS_CODE,
								USB_ACM_PROTOCOL_CODE, g_UsbACM_Comm.acm_param->desc_product_port_3);
				}
				else
				#endif
				#if defined(__USB_DATA_CONNECTION__)
				if (type == USB_DATA_CONNECTION_COM)
				{
					USB_Register_Device_Code(USB_ACM_DEVICE_CODE, USB_ACM_SUBCLASS_CODE,
								USB_ACM_PROTOCOL_CODE, g_UsbACM_Comm.acm_param->desc_data_connection_product);
					type = USB_CDC_ACM;
				}
				else
				#endif
				{
					USB_Register_Device_Code(USB_ACM_DEVICE_CODE, USB_ACM_SUBCLASS_CODE,
										USB_ACM_PROTOCOL_CODE, g_UsbACM_Comm.acm_param->desc_product);
				}
			}
#if !defined(__USB_COMPORT_SUPPORT_TC01_DRIVER__) && defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
		}
#endif
		USB_Init(type, b_enable, KAL_FALSE);
		break;
#endif /*__USB_COM_PORT_ENABLE__*/
//#if defined (__USB_MASS_STORAGE_ENABLE__) && defined (__USB_IN_NORMAL_MODE__) //Revise Boot Mode
#if defined (__USB_MASS_STORAGE_ENABLE__)
#if defined(__USB_MODEM_CARD_SUPPORT__)||defined(__USB_DATA_CONNECTION__)
		case USB_DATA_CONNECTION:
		case USB_MASS_STORAGE_CDROM_ONLY:
		if(kal_if_hisr() == KAL_FALSE)
		{
//			if (g_UsbMS.disk_buffer == NULL)
//			{
//		        g_UsbMS.disk_buffer = (void*)USB_TEST_Buffer;
//			}

			USB_Ms_Set_Current_Driver(LOGIC_DRIVE_CDROM);
			
			USB_Init_Normal_Mode_Ms();
//            USB_Init_Normal_Mode_Ms((kal_uint32 *)g_UsbMS.disk_buffer);

            /* Initialize MASS STORAGE MODE */
            if(g_UsbMode.usb_config_result == KAL_TRUE)
            {
                /* Initialize storage function */
                USB_Register_CreateFunc("MASS STORAGE", USB_Ms_If_Create, USB_Ms_If_Reset,
                                USB_Ms_If_Enable, USB_Ms_If_Speed_Reset, USB_Ms_If_Resume);
								USB_Register_Device_Code(USB_MS_DEVICE_CODE, USB_MS_SUBCLASS_CODE,
									USB_MS_PROTOCOL_CODE, g_UsbMS.ms_param->desc_product);
            }
            else
            {
                USB_End_Normal_Mode_Ms();
            }
            
            USB_Init(USB_MASS_STORAGE, b_enable, KAL_FALSE);
        }
        else
        	ASSERT(0);
		break;
#ifdef __MBIM_SUPPORT__		
		case USB_MORPHING_MBIM:
		if(kal_if_hisr() == KAL_FALSE)
		{
			USB_Ms_Set_Current_Driver(LOGIC_DRIVE_CDROM);
			
			USB_Init_Normal_Mode_Ms();

            /* Initialize MASS STORAGE MODE */
            if(g_UsbMode.usb_config_result == KAL_TRUE)
            {
				USB_Register_Device_Code(USB_COMPOSITE_DEVICE_CODE, USB_COMPOSITE_SUBCLASS_CODE,
								USB_COMPOSITE_PROTOCOL_CODE, g_UsbACM_Comm.acm_param->desc_mbim_morphing_product);

				g_UsbACM_Comm.acm_owner = USB_ACM_OWNER_UART;

                USB_Register_CreateFunc("MORPHING", USB_Ms_If_Create, USB_Ms_If_Reset,
                                USB_Ms_If_Enable, USB_Ms_If_Speed_Reset, USB_Ms_If_Resume);				
				USB_Register_CreateFunc("MBIM COMMU", USB_MBIM_CommIf_Create, USB_MBIM_CommIf_Reset,
						USB_MBIM_CommIf_Enable, USB_MBIM_CommIf_Speed_Reset, NULL);
				USB_Register_CreateFunc("MBIM DATA", USB_MBIM_DataIf_Create, USB_MBIM_DataIf_Reset,
						USB_MBIM_DataIf_Enable, USB_MBIM_DataIf_Speed_Reset, NULL);					
				gUsbDevice.morph_active = KAL_FALSE;				
				gUsbDevice.morph_cfg_num = 2;
				gUsbDevice.morph_interface_num[0] = 1;				
				gUsbDevice.morph_interface_num[1] = 3;				
            }
            else
            {
                USB_End_Normal_Mode_Ms();
            }
            
            USB_Init(USB_MORPHING_MBIM, b_enable, KAL_FALSE);
        }
        else
        	ASSERT(0);
		break;
#endif

#endif /*__USB_MODEM_CARD_SUPPORT__*/
		case USB_MASS_STORAGE:
		#if defined (__USB_MASS_STORAGE_CDROM_ENABLE__) 
		USB_Ms_Set_Current_Driver(LOGIC_DRIVE_MS);
		#endif 
		if(kal_if_hisr() == KAL_FALSE)
		{
			//USB_Init_Normal_Mode_Ms(parameter);
			
			USB_Init_Normal_Mode_Ms();
//			g_UsbMS.disk_buffer = (void*)USB_TEST_Buffer;
//			USB_Init_Normal_Mode_Ms((kal_uint32 *)g_UsbMS.disk_buffer);

			/* Initialize MASS STORAGE MODE */
			if(g_UsbMode.usb_config_result == KAL_TRUE)
			{
				/* Initialize storage function */
				USB_Register_CreateFunc("MASS STORAGE", USB_Ms_If_Create, USB_Ms_If_Reset,
								USB_Ms_If_Enable, USB_Ms_If_Speed_Reset, USB_Ms_If_Resume);
				USB_Register_Device_Code(USB_MS_DEVICE_CODE, USB_MS_SUBCLASS_CODE,
									USB_MS_PROTOCOL_CODE, g_UsbMS.ms_param->desc_product);

				USB_Init(USB_MASS_STORAGE, b_enable, KAL_FALSE);
			}
			else
			{
				USB_End_Normal_Mode_Ms();
			}
		}
		else
		{
	#ifdef __OTG_ENABLE__
		#ifdef __OTG_SRP_HNP_APP_FIXED__
			/* This case is the state of B-device changes its state from B-host to B-peripheral, it is HNP phase 2 */
			if(OTG_Get_Plug_Type() == OTG_PLUG_B)
			{
				OTG_Hdlr_Send_Msg(OTG_HDLR_TASK_INIT_NOMAL_MS, parameter);
			}
		#endif

			/* Initialize storage function */
			USB_Register_CreateFunc("MASS STORAGE", USB_Ms_If_Create, USB_Ms_If_Reset,
							USB_Ms_If_Enable, USB_Ms_If_Speed_Reset, USB_Ms_If_Resume);
			USB_Register_Device_Code(USB_MS_DEVICE_CODE, USB_MS_SUBCLASS_CODE,
								USB_MS_PROTOCOL_CODE, g_UsbMS.ms_param->desc_product);

			/* initialize MASS STORAGE MODE */
			USB_Init(USB_MASS_STORAGE, b_enable, KAL_FALSE);
	#else
		ASSERT(0); //EXT_ASSERT(0, 0, 0, 0);
	#endif
		}
		break;

#if  defined (__NVRAM_IN_USB_MS__)
	case USB_STOP_MS:
		/* This can not be executed in HISR*/
//		if(kal_if_hisr() == KAL_TRUE)
//		{
//			ASSERT(0);
//		}

		USB_Check_Run_On_HISR();

		/* Prevent USB still communicate with PC before handset power down */
		USB_Set_Device_Type(USB_UNKOWN);
//		gUsbDevice.is_configured_now = KAL_FALSE;
		USB_Set_Device_State(DEVSTATE_DEFAULT);

		USB_PDNmode(KAL_TRUE);   /* power down USB, disable D+ pull high */
		USB_Release_Ms_Status();

//		USB_Release_Drv();
		DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_RELEASE_DRV, NULL);

		if(g_UsbMode.usb_boot == KAL_TRUE)
		{
#if 0 // Revise boot mode.
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
			USB_End_Ms();
		}
		else
		{
	#ifdef __USB_IN_NORMAL_MODE__
			USB_End_Normal_Mode_Ms();
	#else
			ASSERT(0);
	#endif
		}

		USB_DeRegister_CreateFunc();
//		USB_DeRegister_Device_Code();
		USB_Release_Device_Status();
		USB_Release();
		USB_Free_Memory();

		break;
#endif   /* __NVRAM_IN_USB_MS__ */

#endif  //__USB_MASS_STORAGE_ENABLE__

#ifdef WEBCAM_SUPPORT
	case USB_VIDEO:
	case USB_COMPOSITE_VIDEO_COM:	// Webcam + COM1

		USB_Register_CreateFunc("USBVIDEO VC", USBVideo_VC_If_Create, USBVideo_VC_If_Reset,
								USBVideo_VC_If_Enable, USBVideo_VC_If_Speed_Reset, NULL);
		USB_Register_CreateFunc("USBVIDEO VS", USBVideo_VS_If_Create, USBVideo_VS_If_Reset,
								USBVideo_VS_If_Enable, USBVideo_VS_If_Speed_Reset, NULL);

	//	if(type == USB_COMPOSITE_VIDEO_COM)
#ifdef __COMPOSITE_WEBCAM__
		if(g_UsbMode.usb_comport_boot != USB_NORMAL_BOOT)
		{	
			if(g_UsbMode.usb_comport_boot == USB_BOOT_TWO_PORT)
				USB2UART_Switch_Mapping(uart_port_usb2,0,KAL_TRUE);

			USB_Set_Device_Type(USB_COMPOSITE_VIDEO_COM);

			/* Com port */
			USB_Register_CreateFunc("ACM COMMU1", USB_Acm1_CommIf_Create, USB_Acm1_CommIf_Reset,
								USB_Acm1_CommIf_Enable, USB_Acm1_CommIf_Speed_Reset, NULL);

			USB_Register_CreateFunc("ACM DATA1", USB_Acm1_DataIf_Create, USB_Acm1_DataIf_Reset,
								USB_Acm1_DataIf_Enable, USB_Acm1_DataIf_Speed_Reset, NULL);
			
			USB_Register_Device_Code(USB_COMPOSITE_DEVICE_CODE, USB_COMPOSITE_SUBCLASS_CODE,
									USB_COMPOSITE_PROTOCOL_CODE, g_USBVideo.custom_param->desc_composite_product);
			
			USB_Init(USB_COMPOSITE_VIDEO_COM, b_enable, KAL_FALSE);
		}
		else
#endif
		{   		
			USB_Register_Device_Code(USBVIDEO_DEVICE_CODE, USBVIDEO_SUBCLASS_CODE,USBVIDEO_PROTOCOL_CODE, g_USBVideo.custom_param->desc_product);
			USB_Init(USB_VIDEO, b_enable, KAL_FALSE);
		}		

		break;
#endif /* WEBCAM_SUPPORT */

#ifdef PICTBRIDGE_SUPPORT
	case  USB_IMAGE:
		/* Initailize IMAGE class */
		USB_Register_CreateFunc("IMAGE", USB_Image_If_Create, USB_Image_If_Reset,
									USB_Image_If_Enable, USB_Image_If_Speed_Reset, NULL);
		USB_Register_Device_Code(USB_IMAGE_DEVICE_CODE, USB_IMAGE_SUBCLASS_CODE,
									USB_IMAGE_PROTOCOL_CODE, g_USBImage.image_param->desc_product);
		/* Get 4-byte alignment image buffer and xml buffer */
		/* We divide the 32KB buffer into several segments */
		g_PTPImage.dps_response_rx_data = (kal_uint8 *)parameter;
		g_PTPImage.dps_request_rx_data = (kal_uint8 *)g_PTPImage.dps_response_rx_data + USB_IMAGE_PTP_MAX_XMLHRSPONSESIZE;
		g_PTPImage.dps_response_tx_data = (kal_uint8 *)g_PTPImage.dps_request_rx_data + USB_IMAGE_PTP_MAX_XMLHREQUESTSIZE;
		g_PTPImage.dps_request_tx_data = (kal_uint8 *)g_PTPImage.dps_response_tx_data + USB_IMAGE_PTP_MAX_XMLBUFFERSIZE;
		g_USBImage.image_buffer = (USB_IMAGE_PTP_BUFFER *)((kal_uint32)g_PTPImage.dps_request_tx_data + USB_IMAGE_PTP_MAX_XMLBUFFERSIZE);
		g_USBImage.image_info_buffer = (kal_uint8 *)g_PTPImage.dps_request_tx_data + USB_IMAGE_PTP_MAX_START_JOB_XMLBUFFERSIZE;

		USB_Init(USB_IMAGE, b_enable, KAL_FALSE);
		break;
#endif  //PICTBRIDGE_SUPPORT

#ifdef __MTP_ENABLE__
	case  USB_IMAGE_MTP:
		/* Initailize IMAGE class */
		USB_Register_CreateFunc("IMAGE_MTP", USB_Image_If_Create, USB_Image_If_Reset,
									USB_Image_If_Enable, USB_Image_If_Speed_Reset, NULL);
		USB_Register_Device_Code(USB_IMAGE_DEVICE_CODE, USB_IMAGE_SUBCLASS_CODE,
									USB_IMAGE_PROTOCOL_CODE, g_USBImage.mtp_image_param->desc_product);

		USB_Init(USB_IMAGE_MTP, b_enable, KAL_FALSE);
		break;

	#if  defined (__NVRAM_IN_USB_MS__)
	case USB_STOP_MTP:
		/* This can not be executed in HISR */
//		if(kal_if_hisr() == KAL_TRUE)
//		{
//			ASSERT(0);
//		}

		USB_Check_Run_On_HISR();
		
#if 0 // Revise boot mode.
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
		/* Prevent USB still communicate with PC before handset power down */
		USB_Set_Device_Type(USB_UNKOWN);
//		gUsbDevice.is_configured_now = KAL_FALSE;
		USB_Set_Device_State(DEVSTATE_DEFAULT);

		USB_PDNmode(KAL_TRUE);   /* power down USB, disable D+ pull high */
		USB_Free_DMA_Channel(g_USBImage.txpipe->byEP, g_USBImage.rxpipe->byEP, USB_EP_TX_DIR, KAL_TRUE);
//		USB_Release_Drv();
		DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_RELEASE_DRV, NULL);
		USB_Release_Image_Status();

		/* Only MTP enable OK, the UEM can send STOP_MTP */
		if(g_UsbMode.usb_config_result == KAL_FALSE)
			ASSERT(0);

		/* Notify MTP to unlock FS */
		USB_Release_MTP_Status();
		g_USBImage.b_mtp_stop_type = KAL_TRUE;

		USB_DeRegister_CreateFunc();
//		USB_DeRegister_Device_Code();
		USB_Release_Device_Status();
		USB_Release();
		USB_Free_Memory();

		break;
	#endif
#endif  /* __MTP_ENABLE__ */

#ifdef __USB_TETHERING__
	case USB_COMPOSITE_RNDIS_COM: // ISD + COM2
	case USB_RNDIS:

		g_UsbACM_Comm.acm_owner = USB_ACM_OWNER_UART;

		USB_Register_CreateFunc("ISD COMMU", USB_ISD_CommIf_Create, USB_ISD_CommIf_Reset,
								USB_ISD_CommIf_Enable, USB_ISD_CommIf_Speed_Reset, NULL);

		USB_Register_CreateFunc("ISD DATA", USB_ISD_DataIf_Create, USB_ISD_DataIf_Reset,
								USB_ISD_DataIf_Enable, USB_ISD_DataIf_Speed_Reset, NULL);

#if defined(__USB_MULTIPLE_COMPORT_SUPPORT__) && !defined(__USB_COMPORT_SUPPORT_TC01_DRIVER__)
		if(type == USB_COMPOSITE_RNDIS_COM)
		{
			/* Com port */
			USB_Register_CreateFunc("ACM COMMU2", USB_Acm2_CommIf_Create, USB_Acm2_CommIf_Reset,
								USB_Acm2_CommIf_Enable, USB_Acm2_CommIf_Speed_Reset, NULL);

			USB_Register_CreateFunc("ACM DATA2", USB_Acm2_DataIf_Create, USB_Acm2_DataIf_Reset,
								USB_Acm2_DataIf_Enable, USB_Acm2_DataIf_Speed_Reset, NULL);
			
			USB_Register_Device_Code(USB_COMPOSITE_DEVICE_CODE, USB_COMPOSITE_SUBCLASS_CODE,
									USB_COMPOSITE_PROTOCOL_CODE, g_UsbACM_Comm.acm_param->desc_isd_com_product);
		}
		else
#endif		
		{   	/* ISD Descriptor */		
			USB_Register_Device_Code(USB_ISD_DEVICE_CODE, USB_ISD_SUBCLASS_CODE,
								USB_ISD_PROTOCOL_CODE, g_UsbACM_Comm.acm_param->desc_isd_product);
		}

		USB_Init(type, b_enable, KAL_FALSE);
		
		break;
#endif
	case USB_COMPOSITE_DEVICES:
		{
			kal_uint32 i;
			drvusb_usbcfg_req_struct *usbcfg;
			
			for ( i=0; i<usb_compsite_table_indx; i++)
			{
				switch(usb_compsite_table[i])
				{
#ifdef __USB_COM_PORT_ENABLE__
					case USB_COMP_CDC_ACM:
						g_UsbACM_Comm.acm_owner = USB_ACM_OWNER_UART;
					#ifdef __USB_COMPORT_SUPPORT_TC01_DRIVER__
						USB_Register_CreateFunc("ACM COMMU1", USB_Acm1_CommIf_Create, USB_Acm1_CommIf_Reset,
												USB_Acm1_CommIf_Enable, USB_Acm1_CommIf_Speed_Reset, NULL);
						USB_Register_CreateFunc("ACM DATA1", USB_Acm1_DataIf_Create, USB_Acm1_DataIf_Reset,
												USB_Acm1_DataIf_Enable, USB_Acm1_DataIf_Speed_Reset, NULL);
					#else
						USB_Register_CreateFunc("ACM DATA1", USB_Acm1_DataIf_Create, USB_Acm1_DataIf_Reset,
											USB_Acm1_DataIf_Enable, USB_Acm1_DataIf_Speed_Reset, NULL);
						USB_Register_CreateFunc("ACM COMMU1", USB_Acm1_CommIf_Create, USB_Acm1_CommIf_Reset,
											USB_Acm1_CommIf_Enable, USB_Acm1_CommIf_Speed_Reset, NULL);
					#endif
						break;
#if defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
					case USB_COMP_CDC_ACM2:
					#ifdef __USB_COMPORT_SUPPORT_TC01_DRIVER__
						USB_Register_CreateFunc("ACM VEND", USB_Acm_VendorIf_Create, USB_Acm_VendorIf_Reset,
								USB_Acm_VendorIf_Enable, USB_Acm_VendorIf_Speed_Reset, NULL);
					#else
						USB_Register_CreateFunc("ACM DATA2", USB_Acm2_DataIf_Create, USB_Acm2_DataIf_Reset,
								USB_Acm2_DataIf_Enable, USB_Acm2_DataIf_Speed_Reset, NULL);
						USB_Register_CreateFunc("ACM COMMU2", USB_Acm2_CommIf_Create, USB_Acm2_CommIf_Reset,
								USB_Acm2_CommIf_Enable, USB_Acm2_CommIf_Speed_Reset, NULL);
					#endif
						break;
#endif //__USB_MULTIPLE_COMPORT_SUPPORT__
#if defined (__USB_MODEM_CARD_SUPPORT__)
						
#ifdef __MBIM_SUPPORT__
					case USB_COMP_MBIM:
						g_UsbACM_Comm.acm_owner = USB_ACM_OWNER_UART;
						USB_Register_CreateFunc("MBIM COMMU", USB_MBIM_CommIf_Create, USB_MBIM_CommIf_Reset,
											USB_MBIM_CommIf_Enable, USB_MBIM_CommIf_Speed_Reset, NULL);
						USB_Register_CreateFunc("MBIM DATA", USB_MBIM_DataIf_Create, USB_MBIM_DataIf_Reset,
											USB_MBIM_DataIf_Enable, USB_MBIM_DataIf_Speed_Reset, NULL);
						break;
#endif
						
#ifdef __ECM_SUPPORT__
					case USB_COMP_ECM:
						g_UsbACM_Comm.acm_owner = USB_ACM_OWNER_UART;
						USB_Register_CreateFunc("ECM COMMU", USB_ECM_CommIf_Create, USB_ECM_CommIf_Reset,
											USB_ECM_CommIf_Enable, USB_ECM_CommIf_Speed_Reset, NULL);
						USB_Register_CreateFunc("ECM DATA", USB_ECM_DataIf_Create, USB_ECM_DataIf_Reset,
											USB_ECM_DataIf_Enable, USB_ECM_DataIf_Speed_Reset, NULL);
						break;
#endif
						
					case USB_COMP_SI_CDC_ACM:
						g_UsbACM_Comm.acm_owner = USB_ACM_OWNER_UART;
						USB_Register_CreateFunc("ACM_DATA1_AND_COMM1", USB_Acm_DataCommIf_Create, USB_Acm_DataCommIf_Reset,
												USB_Acm_DataCommIf_Enable, USB_Acm_DataCommIf_Speed_Reset, NULL);
						break;
						
					case USB_COMP_SI_CDC_ACM2:
						USB_Register_CreateFunc("ACM_DATA1_AND_COMM2", USB_Acm2_DataCommIf_Create, USB_Acm2_DataCommIf_Reset,
												USB_Acm2_DataCommIf_Enable, USB_Acm2_DataCommIf_Speed_Reset, NULL);
						break;
						
					case USB_COMP_REDUCED_CDC_ACM2:
						g_UsbACM_Comm.acm_owner = USB_ACM_OWNER_UART;
						USB_Register_CreateFunc("ACM DATA2", USB_Acm2_DataIf_Create, USB_Acm2_DataIf_Reset,
								USB_Acm2_DataIf_Enable, USB_Acm2_DataIf_Speed_Reset, NULL);
						break;
						
					case USB_COMP_REDUCED_CDC_ACM3:
						USB_Register_CreateFunc("ACM DATA3", USB_Acm3_DataIf_Create, USB_Acm3_DataIf_Reset,
									USB_Acm3_DataIf_Enable, USB_Acm3_DataIf_Speed_Reset, NULL);
						//fixed me: 
						// did it need to remove????
	    					tst_file_notify_sd_ready();
						break;
						
					case USB_COMP_REDUCED_CDC_ACM4:
						USB_Register_CreateFunc("ACM DATA4", USB_Acm4_DataIf_Create, USB_Acm4_DataIf_Reset,
									USB_Acm4_DataIf_Enable, USB_Acm4_DataIf_Speed_Reset, NULL);
						break;
						
					case USB_COMP_REDUCED_CDC_ACM5:
						USB_Register_CreateFunc("ACM DATA5", USB_Acm5_DataIf_Create, USB_Acm5_DataIf_Reset,
									USB_Acm5_DataIf_Enable, USB_Acm5_DataIf_Speed_Reset, NULL);
						break;
#endif //__USB_MODEM_CARD_SUPPORT__
#endif //__USB_COM_PORT_ENABLE__

#ifdef __USB_MASS_STORAGE_ENABLE__
					case USB_COMP_MASS_STORAGE:
						//g_UsbMS.disk_buffer = (void*)USB_TEST_Buffer;
						#if defined (__USB_MASS_STORAGE_CDROM_ENABLE__) 						
						USB_Ms_Set_Current_Driver(LOGIC_DRIVE_MS);
						#endif
						if (USB_Ms_Get_Max_LUN() != USBMS_INVALID_MAX_LUN)
						{
							USB_Init_Normal_Mode_Ms();
							/* Initialize storage function */
							USB_Register_CreateFunc("MASS STORAGE", USB_Ms_If_Create, USB_Ms_If_Reset,
								USB_Ms_If_Enable, USB_Ms_If_Speed_Reset, USB_Ms_If_Resume);
						}
						else
						{
							#if defined (__USB_MODEM_CARD_SUPPORT__)
							//fixed me: 
							// did it need to remove????
							tst_file_notify_sd_ready();
							#endif
						}
						break;
#endif //__USB_MASS_STORAGE_ENABLE__
					default:
						break;
				}
			}
			//USB_Register_Device_Code(0x00, 0x00, 0x00, g_UsbACM_Comm.acm_param->desc_product_port_3);
			usbcfg = (drvusb_usbcfg_req_struct *)parameter;

//			USB_Register_Device_Code(*(parameter+1), 
//						 *(parameter+2),
//						 *(parameter+3),
//						 *(parameter+4));
			USB_Register_Device_Code(usbcfg->device_code, 
						 usbcfg->subclass_code,
						 usbcfg->protocol_code,
						 usbcfg->product_code);
		}
#ifdef __USB_LOGGING__
			
					if((g_usb_logging_port_num != 0) && (USB2UARTPort[g_UsbMode.usb_comport_boot-1].ownerid == MOD_DRV_HISR))
					{	
						USBACM_LOGGING_Init();
			
	#ifdef __DSPIRDBG__
		#ifdef __USB_SW_LOGGING_WITH_ISR__
						USB_LOGGING_DSP_Drv_Activate_ISR();
		#endif
	#endif
					}
#endif	/*__USB_LOGGING__*/
	
		USB_Init(type, b_enable, KAL_FALSE);
		
		//USB_Init(USB_COMPOSITE_MULTI_COM, b_enable, KAL_FALSE);
		break;

	default :
		EXT_ASSERT(0, (kal_uint32)type, (kal_uint32)USB_Get_Device_Type(), 0);
		break;
	}
}


/* The enable parameter decides whether to turn off D+ at this time */
void USB_Release_Type(kal_bool b_enable, kal_bool b_plugout)
{
	USB_DEVICE_TYPE device_type;
	kal_uint32 usb_port;
//#ifdef __USB_TETHERING__
//	ilm_struct *ilm;
//	 rndis_usb_config_cnf_struct  *result; 
//#endif


	device_type = USB_Get_Device_Type();
	USB_Dbg_Trace(USB_RELEASE_TYPE, (kal_uint32)device_type, (kal_uint32)b_enable);
//	gUsbDevice.is_configured_now = KAL_FALSE;
	USB_Set_Device_State(DEVSTATE_DEFAULT);

	/* note that device type should be set to unknown here,
	in case UART owner uses other UART functions */
	USB_Set_Device_Type(USB_UNKOWN);

	if(b_enable == KAL_TRUE)
	{
#ifdef __OTG_ENABLE__
		/* Power down USB */
		if(g_UsbMode.b_usb_pdnmode == KAL_FALSE)
		{
			USB_PDNmode(KAL_TRUE);
		}
#else
		/* power down USB */
		/* Disable D+ pull high */
		USB_PDNmode(KAL_TRUE);
#endif
	}

	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_SET_DISCON_STATUS, NULL);
//	USB_Set_DMA_Stop_Flag();

	/* Stop and release resource */
	switch (device_type)
	{
#ifdef __MBIM_SUPPORT__		
	case USB_MORPHING_MBIM:
			gUsbDevice.morph_active = KAL_FALSE;		
			if(kal_if_hisr() == KAL_FALSE)
			{
				USB_Release_Ms_Status();
				USB_End_Normal_Mode_Ms();
			}
			else
			{
				ASSERT(0);
			}			
		break;
#endif		
#ifdef __USB_MASS_STORAGE_ENABLE__
	case USB_DATA_CONNECTION:
	case USB_MASS_STORAGE_CDROM_ONLY:
	case USB_MASS_STORAGE:
		if(g_UsbMode.usb_boot == KAL_FALSE) /* normal mode */
		{
#ifdef __USB_IN_NORMAL_MODE__
			if(kal_if_hisr() == KAL_FALSE)
			{
				USB_Release_Ms_Status();
				USB_End_Normal_Mode_Ms();
			}
			else
			{
	#ifdef __OTG_ENABLE__
		#ifdef __OTG_SRP_HNP_APP_FIXED__
				USB_Release_Ms_Status();
		#endif
				OTG_Hdlr_Send_Msg(OTG_HDLR_TASK_END_NORMAL_MS, 0);
	#else
				ASSERT(0);
	#endif
			}
#else
			ASSERT(0);
#endif
		}
		else
		{
#ifdef __NVRAM_IN_USB_MS__
			if(kal_if_hisr() == KAL_FALSE)
			{
				USB_Release_Ms_Status();
				USB_End_Ms();
			}
			else
			{
	#ifdef __OTG_ENABLE__
				ASSERT(0);
//				OTG_Hdlr_Send_Msg(OTG_HDLR_TASK_END_MS, 0);
	#else
				ASSERT(0);
	#endif
			}
#endif
		}
		break;
#endif  //__USB_MASS_STORAGE_ENABLE__
#ifdef __USB_COM_PORT_ENABLE__
	case USB_CDC_ACM:
#if defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
	case USB_COMPOSITE_MULTI_COM:
#endif
#ifdef __USB_LOGGING__
//	case USB_CDC_ACM_LOGGING:
		if(g_usb_logging_port_num != 0)
		{
			USBACM_LOGGING_Stop();
		}
//		else
#endif /* __USB_LOGGING__ */
		{
			/* Notify UART owner that virtual UART cable is plug out */
			/* Note that this should be called before release ACM status */
			/* Logging ports' owner id shoudl be MOD_DRV_HISR */
			for(usb_port = 0; usb_port < MAX_USB_PORT_NUM; usb_port++)
			{
				if(USB2UARTPort[usb_port].ownerid != MOD_DRV_HISR)
				{
					if((gUsbDevice.nDevState != DEVSTATE_DEFAULT)&&(g_UsbACM[usb_port].send_UARTilm == KAL_TRUE))
					{						
						USB2UART_Sendilm(USB2UARTPort[usb_port].port_no, MSG_ID_UART_PLUGOUT_IND);
					}	
					else if(gUsbDevice.nDevState == DEVSTATE_DEFAULT)
						USB2UART_Sendilm(USB2UARTPort[usb_port].port_no, MSG_ID_UART_PLUGOUT_IND);
				}
			}
		}

		/* Release global variable g_UsbACM resource*/
		USB_Release_Acm_Status();
		break;
#endif /*__USB_COM_PORT_ENABLE__*/


#ifdef __USB_TETHERING__		
	case USB_COMPOSITE_RNDIS_COM:
	case USB_RNDIS:		

		USB_ISD_Stop_Transfer(); // only stop data transfer  UPS will close port --> release global variable

		for(usb_port = 0; usb_port < MAX_USB_PORT_NUM; usb_port++)
		{
			if((USB2UARTPort[usb_port].ownerid != MOD_DRV_HISR)&&(b_plugout == KAL_TRUE))
			{
				USB2UART_Sendilm(USB2UARTPort[usb_port].port_no, MSG_ID_UART_PLUGOUT_IND);
			}
		}

		/* Release global variable g_UsbACM resource*/
		USB_Release_Acm_Status();

// notice UPS Cable out
// USB should send CNF message back to UPS
		
//		if (g_UsbMode.rndis_cnf_response == KAL_TRUE)
//		{
				
		/* Notify UPS USB is config */
//		result = ( rndis_usb_config_cnf_struct*)construct_local_para(sizeof( rndis_usb_config_cnf_struct), TD_CTRL);
//		result->confirm = KAL_FALSE;
		
//		DRV_BuildPrimitive(ilm, MOD_USB,MOD_UPS, MSG_ID_RNDIS_USB_CONFIG_CNF, result);		
//		msg_send_ext_queue(ilm);
		
//			USB2UART_Sendilm(0, MSG_ID_RNDIS_USB_CONFIG_CNF);
//			g_UsbMode.rndis_cnf_response = KAL_FALSE;
//		}

		break;
#endif

#ifdef WEBCAM_SUPPORT
	case USB_VIDEO:
	case USB_COMPOSITE_VIDEO_COM:	
		if(g_UsbMode.cable_type == USB_MODE_CABLE_PLUGOUT)/*real plug out, not these two messages result in*/
		{
			/* Update video state machine */
			USBVideo_Plug_Out_Hdlr();
		}

		USB_Release_Video_Status();

		if(device_type == USB_COMPOSITE_VIDEO_COM)
		{
			for(usb_port = 0; usb_port < MAX_USB_PORT_NUM; usb_port++)
			{
				if((g_UsbACM[usb_port].send_UARTilm == KAL_TRUE)&&(USB2UARTPort[usb_port].ownerid != MOD_DRV_HISR))
				{
					USB2UART_Sendilm(USB2UARTPort[usb_port].port_no, MSG_ID_UART_PLUGOUT_IND);
				}
			}
			

// switch back to initial mapping
#if defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
			if(g_UsbMode.usb_comport_boot == USB_BOOT_TWO_PORT)
				USB2UART_Switch_Mapping(uart_port_usb2,1,KAL_FALSE);	
#endif
			USB_Release_Acm_Status();
		}
		
		break;
#endif  /* WEBCAM_SUPPORT */

#ifdef __MTP_ENABLE__
	case USB_IMAGE_MTP:
		/* If MTP enable fail, then it should not call to here */
		USB_Release_MTP_Status();
		g_USBImage.b_mtp_release_type = KAL_TRUE;
		USB_Free_DMA_Channel(g_USBImage.txpipe->byEP, g_USBImage.rxpipe->byEP, USB_EP_TX_DIR, KAL_TRUE);
		USB_Release_Image_Status();
		break;

	case USB_UNKOWN:
		/* UEM already config, USB send enable msg to MTP, but MTP does not response yet, and cable is out */
		if(g_USBImage.b_wait_enable_rsp == KAL_TRUE)
		{
			ASSERT(0);
//			g_USBImage.b_is_pending_disable_mtp_msg = KAL_TRUE;
//			g_USBImage.b_mtp_release_type = KAL_TRUE;
		}
		break;
#endif /* __MTP_ENABLE__ */

#ifdef PICTBRIDGE_SUPPORT
	case USB_IMAGE:
		USB_Free_DMA_Channel(g_USBImage.txpipe->byEP, 0, USB_EP_TX_DIR, KAL_FALSE);
		USB_Release_Image_Status();
		USB_Image_Reset_PTP_Hdlr();
		break;
#endif  /* PICTBRIDGE_SUPPORT */
	default:
		break;
	}

	if(device_type != USB_UNKOWN)
	{
		USB_DeRegister_CreateFunc();
//		USB_DeRegister_Device_Code();
	#ifdef __OTG_SRP_HNP_APP_FIXED__
		/* Release global variable gUsbDevice resource*/
		USB_Release_Device_Status();
	#else
		if((kal_if_hisr() == KAL_FALSE)||(device_type != USB_MASS_STORAGE))
		{
			/* Release global variable gUsbDevice resource */
			USB_Release_Device_Status();
		}
	#endif
		USB_Release();
		USB_Free_Memory();
	}

	if(b_enable == KAL_TRUE)
	{
#ifdef __OTG_ENABLE__
		/* power down USB */
		if(g_UsbMode.b_usb_pdnmode == KAL_FALSE)
		{
			g_UsbMode.b_usb_pdnmode = KAL_TRUE;
//			USB_Release_Drv();
			DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_RELEASE_DRV, NULL);
		}
#else
		/* USB IP V3 should disable 52MHz AHB clock after DMA channel free */
//		USB_Release_Drv();
		DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_RELEASE_DRV, NULL);
#endif
	}

	/* 1. MTP stop type still send the plug out msg here */
	/* 2. When device type is USB_UNKOWN, maybe it is MTP device but MTP task does not send enable response msg yet */
#ifdef __MTP_ENABLE__
//	if((b_plugout == KAL_TRUE)&&(device_type != USB_IMAGE_MTP)&&(g_USBImage.b_wait_enable_rsp == KAL_FALSE))
	if((b_plugout == KAL_TRUE)&&(device_type != USB_IMAGE_MTP)&&(g_USBImage.b_is_pending_disable_mtp_msg == KAL_FALSE))
#else
	if(b_plugout == KAL_TRUE)
#endif
	{
		drv_trace0(TRACE_FUNC, (kal_uint32)USB_PLUG_OUT);

	#ifdef __OTG_SRP_HNP_APP_FIXED__
		if(g_UsbMode.usb_boot == KAL_TRUE)
	#else
		if((g_UsbMode.usb_comport_boot == USB_NORMAL_BOOT)||(g_UsbMode.usb_menu_en == KAL_TRUE))
	#endif
		{
			// if  USBBoot = T  => usb_comport_boot = USB_NORMAL_BOOT
			/* Notify UEM, MS mode must send this message to shut down */
			USB_Send_Msg(USB_SEND_MSG_PLUG_OUT);
		}
	}
}


#ifdef __OTG_ENABLE__

/* Only change from HISR to task */
void OTG_Hdlr_Select(OTG_HDLR_TASK_TYPE type, kal_uint32 *parameter)
{
	switch(type)
	{
#ifdef __USB_MASS_STORAGE_ENABLE__
	case OTG_HDLR_TASK_END_NORMAL_MS:
#ifndef __OTG_SRP_HNP_APP_FIXED__
		USB_Release_Ms_Status();
#endif
		USB_End_Normal_Mode_Ms();
#ifndef __OTG_SRP_HNP_APP_FIXED__
		/* Release global variable gUsbDevice resource */
		USB_Release_Device_Status();
		USB_Free_Memory();
#endif
		break;

	case OTG_HDLR_TASK_ONLY_END_NORMAL_MS:
		USB_End_Normal_Mode_Ms();
		break;
#ifdef __OTG_SRP_HNP_APP_FIXED__
	case OTG_HDLR_TASK_INIT_NOMAL_MS:
		//USB_Init_Normal_Mode_Ms(parameter);
		
		USB_Init_Normal_Mode_Ms();
//		g_UsbMS.disk_buffer = (void*)USB_TEST_Buffer;
//		USB_Init_Normal_Mode_Ms((kal_uint32 *)g_UsbMS.disk_buffer);
		break;
#endif
//	case OTG_HDLR_TASK_INIT_MS:
//	case OTG_HDLR_TASK_END_MS:
#endif //__USB_MASS_STORAGE_ENABLE__
	default:
		ASSERT(0);
		break;
	}
}

#endif

/************************************************************
	mass storage mode functions
*************************************************************/

#ifdef __USB_MASS_STORAGE_ENABLE__

//#ifdef __USB_IN_NORMAL_MODE__ //Revise boot mode
#if !defined(__MODEM_CARD__) || !defined(__MODEM_CCCI_EXIST__)	
static FS_DEVICE_TYPE_ENUM USB_Ms_Dev_To_Fs_Type(USB_STORAGE_DEV_TYPE type)
{
	FS_DEVICE_TYPE_ENUM fs_type = FS_DEVICE_TYPE_MAX_VALUE;

	switch(type)
	{
	case USB_STORAGE_DEV_NOR:
		fs_type = FS_DEVICE_TYPE_NOR;
		break;
 	case USB_STORAGE_DEV_NAND:
 		fs_type = FS_DEVICE_TYPE_NAND;
 		break;
 	case USB_STORAGE_DEV_CARD:
 		fs_type = FS_DEVICE_TYPE_CARD;
 		break;
#if defined (__USB_MASS_STORAGE_CDROM_ENABLE__)
 	case USB_STORAGE_DEV_CDROM:
 		#if defined(NAND_SUPPORT)
 		fs_type = FS_DEVICE_TYPE_NAND;
 		#else
 		fs_type = FS_DEVICE_TYPE_NOR;
 		#endif
 		break;
#endif
 	default:
 		EXT_ASSERT(0, (kal_uint32)type, 0, 0);
 		break;
	}
	return fs_type;
}
#endif

void USB_Init_Normal_Mode_Ms(void)
{
	kal_int32 index;
	USB_STORAGE_DEV_TYPE dev_type;
	kal_uint8 max_lun = USB_Ms_Get_Max_LUN();
#if !defined(__MODEM_CARD__) || !defined(__MODEM_CCCI_EXIST__)	
	kal_int32	result;
	FS_DEVICE_TYPE_ENUM fs_type;
#endif


	/* This function can not be executed in HISR*/
//	if(kal_if_hisr() == KAL_TRUE)
//	{
//		ASSERT(0);
//	}
	USB_Check_Run_On_HISR();


	/* Get disk buffer */
//	g_UsbMS.disk_buffer = (void*)mem_addr;
	if (g_UsbMS.disk_buffer == NULL)
		g_UsbMS.disk_buffer = (void*)USB_Get_Memory (USBMS_MAX_BUFFERSIZE);//(void*)USB_TEST_Buffer;

	/* lock file system */
#ifdef __OTG_ENABLE__
	if(b_is_fs_lock == KAL_TRUE)
		ASSERT(0);
	b_is_fs_lock = KAL_TRUE;

	USB_Dbg_Trace(USB_MS_LOCKFAT, 0, 0);
#endif

#if defined(__MODEM_CARD__)&&defined(__MODEM_CCCI_EXIST__)
	/* query whether each device can be exported or not (system driver disk)*/	
	for(index = max_lun; index >= 0; index--)
	{
		/* get each device type and translate to file system type */
		dev_type = USB_Ms_Dev_Type(index);
		if(dev_type == USB_STORAGE_DEV_CARD)
		{
			//skip
		}
		#ifdef __USB_IN_NORMAL_MODE_IMPROVE__
		#ifdef __USB_MASS_STORAGE_CDROM_ENABLE__		
		else if (dev_type == USB_STORAGE_DEV_CDROM)
		{
			WCHAR  temp_path[] = {'z', ':', '\\', 'c', 'd', 'r', 'o', 'm', '.', 'i', 's', 'o', '\0'};
			g_UsbMS.cdrom_drive_handle = FS_Open(temp_path, FS_READ_WRITE);
		}
		#endif
		#endif
		else
		{
			ASSERT(0);
		}
	}
#else
	result = FS_LockFAT((int)FS_EXPORT_ENUM);

	if(result < 0)
	{
		USB_Dbg_Trace(USB_MS_LOCKFAT_FAIL, result, 0);
		drv_trace0(TRACE_FUNC, (kal_uint32)USBMS_LOCKFAT_FAIL);
		g_UsbMode.usb_config_result = KAL_FALSE;
		return;
	}

	/* query whether each device can be exported or not (system driver disk)*/
	for(index = max_lun; index >= 0; index--)
	{
		/* get each device type and translate to file system type */
		dev_type = USB_Ms_Dev_Type(index);
		fs_type = USB_Ms_Dev_To_Fs_Type(dev_type);
		/* query whether it can be exported or not */
		result = FS_GetDevStatus((int)fs_type, (int)FS_EXPORT_STATE_ENUM);

		if(result == FS_NO_ERROR)
		{
			/* Device is not exported, means it is system drive inside */
#ifdef __USB_IN_NORMAL_MODE_IMPROVE__
#ifdef __USB_MASS_STORAGE_CDROM_ENABLE__
			if (dev_type == USB_STORAGE_DEV_CDROM)
			{
				WCHAR  temp_path[] = {'z', ':', '\\', 'c', 'd', 'r', 'o', 'm', '.', 'i', 's', 'o', '\0'};
				//kal_uint16   drvLetter = 0;

				/* Re-lock again to let USB can get the handle exactly */
				g_UsbMS.cdrom_drive_handle = FS_Open(temp_path, FS_READ_WRITE);
				//if(g_UsbMS.system_drive_handle < 0)
				//{
				//	EXT_ASSERT(0, (kal_uint32)g_UsbMS.system_drive_handle, 0, 0);
				//}

				//g_UsbMS.device_type = dev_type;
			}
			else
#endif /*__USB_MODEM_CARD_SUPPORT__*/
			{
                extern USB_DiskDriver_STRUCT USB_SYSTEM_drv;
				FS_LockFAT((int)FS_EXPORT_FINISHED_ENUM); //Notic File System , for improvement	
				g_UsbMS.device_type = dev_type;
				USB_Ms_Change_Register_DiskDriver(index, &USB_SYSTEM_drv);
			}
#else /* __USB_IN_NORMAL_MODE_IMPROVE__ */

#ifndef __NANDFDM_MULTI_INSTANCE__  //New File System Architecture -> shouldn't use __USB_IN_NORMAL_MODE_IMPROVE__
			USB_Ms_DeRegister_DiskDriver(index);
#endif

#endif /* __USB_IN_NORMAL_MODE_IMPROVE__ */
		}
		else if(result != FS_DEVICE_EXPORTED_ERROR)
		{
			ASSERT(0);
//			EXT_ASSERT(0, result, (kal_uint32)dev_type, (kal_uint32)fs_type);
		}
	}
#endif	
}


void USB_End_Normal_Mode_Ms(void)
{
#if !defined(FMT_NOT_PRESENT)	
//	ilm_struct *ilm = NULL;
#endif	
#ifdef __OTG_ENABLE__
	USB_Dbg_Trace(USB_MS_UNLOCKFAT, 0, 0);

	if(b_is_fs_lock == KAL_FALSE)
		ASSERT(0);
	b_is_fs_lock = KAL_FALSE;
#endif

	/* This function can not be executed in HISR*/
//	if(kal_if_hisr() == KAL_TRUE)
//		EXT_ASSERT(0, 0, 0, 0);
	USB_Check_Run_On_HISR();

#ifdef __USB_IN_NORMAL_MODE_IMPROVE__
	#ifdef __USB_MASS_STORAGE_CDROM_ENABLE__
	if(g_UsbMS.cdrom_drive_handle != -1)
		FS_Close(g_UsbMS.cdrom_drive_handle);
	g_UsbMS.cdrom_drive_handle = -1;
	#endif /*__USB_MODEM_CARD_SUPPORT__*/
#endif
#if !defined(__MODEM_CARD__)||!defined(__MODEM_CCCI_EXIST__)
	FS_LockFAT((int)FS_REMOUNT_ENUM);
#endif
#if !defined(FMT_NOT_PRESENT)	
    USB_Send_Msg_Ext_Queue(MOD_FMT, MSG_ID_USB_MSDRV_REMOUNT_REQ, NULL);
#endif    
}

//#endif  /* __USB_IN_NORMAL_MODE__ */


void USB_Init_Ms(kal_bool bFirst)
{
#ifdef __P_PROPRIETARY_COPYRIGHT__
/* under construction !*/
#endif
#ifdef __USB_MASS_STORAGE_CDROM_ENABLE__
	WCHAR  temp_path[] = {'z', ':', '\\', 'c', 'd', 'r', 'o', 'm', '.', 'i', 's', 'o', '\0'};
#endif
	/* This function can not be executed in HISR*/
//	if(kal_if_hisr() == KAL_TRUE)
//		ASSERT(0);
	USB_Check_Run_On_HISR();

//	if(bFirst == KAL_FALSE)  //MAUI_01204668 in Mass Storage mode, if Alarm is ringing on th background,
//		ASSERT(0);            //plug out and in usb cable, system doesn't shutdown until Alarm stops.
                            // In this case,USb_Init_MS function can be executed twice.

#ifdef __NVRAM_IN_USB_MS__
	/* Notify UEM*/
	USB_Send_Msg(USB_SEND_MSG_PLUG_IN);
#else
	if(bFirst == KAL_TRUE)
	{
		/* Notify UEM*/
		USB_Send_Msg(USB_SEND_MSG_PLUG_IN);
	}
#endif

	/* If not first time plug in, only notify UEM*/
	if(bFirst == KAL_TRUE)
	{
		/* get unique string from nvram and construct serial string*/
		USB_Get_Serial_Value();

#ifdef __P_PROPRIETARY_COPYRIGHT__
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

		/* must lock file system before turn on USB power */
		FS_LockFAT((int)FS_EXPORT_ENUM);	//lock file system in ms mode,other API can access NVRAM.
		FS_LockFAT((int)FS_EXPORT_FINISHED_ENUM); //Notic File System , for improvement
		
#ifdef __USB_MASS_STORAGE_CDROM_ENABLE__
		g_UsbMS.cdrom_drive_handle = FS_Open(temp_path, FS_READ_WRITE);
#endif

		USB_Register_CreateFunc("MASS STORAGE", USB_Ms_If_Create, USB_Ms_If_Reset,
										USB_Ms_If_Enable, USB_Ms_If_Speed_Reset, USB_Ms_If_Resume);
		USB_Register_Device_Code(USB_MS_DEVICE_CODE, USB_MS_SUBCLASS_CODE,
											USB_MS_PROTOCOL_CODE, g_UsbMS.ms_param->desc_product);

		/* initialize MASS STORAGE MODE */
		USB_Init(USB_MASS_STORAGE, KAL_TRUE, KAL_FALSE);
	}
}


static void USB_End_Ms(void)
{
#ifdef __NVRAM_IN_USB_MS__
	/* This function can not be executed in HISR*/
//	if(kal_if_hisr() == KAL_TRUE)
//		EXT_ASSERT(0, 0, 0, 0);

	USB_Check_Run_On_HISR();
	FS_LockFAT((int)FS_UNLOCK_USB_ENUM);
	//FS_LockFAT((int)FS_REMOUNT_ENUM);
#else
	ASSERT(0);
#endif
}

#endif  /* __USB_MASS_STORAGE_ENABLE__ */




/* TRUE : USB boot with Mass storage protocol */
/* FALSE : USB boot with MTP protocol */
kal_bool USB_Boot_With_MS(void)
{
	if(g_UsbMode.usb_boot == KAL_FALSE)
		ASSERT(0);

#ifdef __USB_BOOT_WITH_MTP__
	return KAL_FALSE;
#else

#if defined(__USB_MASS_STORAGE_ENABLE__)

#ifdef __MTP_ENABLE__
	if(g_UsbMode.b_usb_boot_with_ms == KAL_TRUE)
		return KAL_TRUE;
	else
		return KAL_FALSE;
#else
	return KAL_TRUE;
#endif

#else  /* __USB_MASS_STORAGE_ENABLE__ */

//#ifdef __MTP_ENABLE__
	return KAL_FALSE;
//#else
//	ASSERT(0);
//#endif

#endif  /* __USB_MASS_STORAGE_ENABLE__ */

#endif
}

void USB_Composite_Device_Table_Reset(void)
{
	kal_uint32 i;
	for ( i=0; i<USB_MAX_COMPOSITE_DEVICES; i++)
		usb_compsite_table[i] = USB_COMP_UNKOWN;
	
	usb_compsite_table_indx = 0;
}

void USB_Composite_Device_Table_Register(USB_COMPOSITE_DEVICE_TYPE type)
{
	if (usb_compsite_table_indx == USB_MAX_COMPOSITE_DEVICES)
		ASSERT(0);

	usb_compsite_table[usb_compsite_table_indx] = type;
	usb_compsite_table_indx++;
}

#if defined(__USB_MODEM_CARD_SUPPORT__)
void USB_Mode_Switch(USB_DEVICE_TYPE type)
{
	drvusb_usbcfg_req_struct *usbcfg;
	ilm_struct usbilm;
	ilm_struct *usb_ilm = &usbilm;
	
	/* Disable D+ pull high, but plug out is false */
	USB_Release_Type(KAL_TRUE, KAL_FALSE);
	
	kal_sleep_task(100);
	
	
	//Bootloader will set DL flag. we clear it here for prevent download fail.
	INT_SetCmdToSys(SYS_CMD_CLR_DL_FLAG);
	

	//USB_Config_Type(USB_COMPOSITE_MULTI_COM, KAL_TRUE, NULL);
	gUsbDevice.usb_send_config_result = KAL_FALSE;
	usbcfg = (drvusb_usbcfg_req_struct*) construct_local_para(sizeof(drvusb_usbcfg_req_struct), TD_CTRL);
	
	USB_Composite_Device_Table_Reset();
#if defined(__MBIM_SUPPORT__)||defined(__ECM_SUPPORT__)
	if(g_UsbMode.usb_comport_driver == USB_COMPORT_WIN) 
	{
	USB_Composite_Device_Table_Register(USB_COMP_MBIM);
		usbcfg->product_code = g_UsbACM_Comm.acm_param->desc_mbim_4vcom_product;
		drv_trace0(TRACE_FUNC, (kal_uint32)PC_OS_IS_WIN);
		usbcfg->device_code = USB_COMPOSITE_DEVICE_CODE;
		usbcfg->subclass_code = USB_COMPOSITE_SUBCLASS_CODE;
		usbcfg->protocol_code = USB_COMPOSITE_PROTOCOL_CODE;		
	}
	else
	{
		USB_Composite_Device_Table_Register(USB_COMP_ECM);
		usbcfg->product_code = g_UsbACM_Comm.acm_param->desc_ecm_4vcom_product;	
		usbcfg->device_code = USB_MAC_COMPOSITE_DEVICE_CODE;
		usbcfg->subclass_code = USB_MAC_COMPOSITE_SUBCLASS_CODE;
		usbcfg->protocol_code = USB_MAC_COMPOSITE_PROTOCOL_CODE;		
	}
	
	USB_Composite_Device_Table_Register(USB_COMP_SI_CDC_ACM2);
	USB_Composite_Device_Table_Register(USB_COMP_REDUCED_CDC_ACM3);
	USB_Composite_Device_Table_Register(USB_COMP_REDUCED_CDC_ACM4);	
	USB_Composite_Device_Table_Register(USB_COMP_REDUCED_CDC_ACM5);
	USB_Composite_Device_Table_Register(USB_COMP_MASS_STORAGE);
	
	usbcfg->mode = type; 
	usbcfg->parameter = (kal_uint32 *)usbcfg;
	
#else

	//5VCOM
	USB_Composite_Device_Table_Register(USB_COMP_SI_CDC_ACM);
	USB_Composite_Device_Table_Register(USB_COMP_SI_CDC_ACM2);
	USB_Composite_Device_Table_Register(USB_COMP_REDUCED_CDC_ACM3);
	USB_Composite_Device_Table_Register(USB_COMP_REDUCED_CDC_ACM4);
	USB_Composite_Device_Table_Register(USB_COMP_REDUCED_CDC_ACM5);
	USB_Composite_Device_Table_Register(USB_COMP_MASS_STORAGE);
	
	usbcfg->mode = type; 
	usbcfg->parameter = (kal_uint32 *)usbcfg;
	usbcfg->device_code = USB_COMPOSITE_NO_IAD_DEVICE_CODE;
	usbcfg->subclass_code = USB_COMPOSITE_NO_IAD_SUBCLASS_CODE;
	usbcfg->protocol_code = USB_COMPOSITE_NO_IAD_PROTOCOL_CODE;
	usbcfg->product_code = g_UsbACM_Comm.acm_param->desc_5vcom_product;
#endif
	
	DRV_BuildPrimitive(usb_ilm, MOD_USB, MOD_USB, MSG_ID_DRVUEM_USBCFG_REQ,(local_para_struct*)usbcfg);
	msg_send_ext_queue(usb_ilm);
}
#endif //#if defined(__USB_MODEM_CARD_SUPPORT__)

#ifdef __MTP_ENABLE__

void USB_Init_MTP(kal_bool bFirst)
{
	/* This function can not be executed in HISR*/
//	if(kal_if_hisr() == KAL_TRUE)
//		ASSERT(0);
	USB_Check_Run_On_HISR();

//	if(bFirst == KAL_FALSE)  //MAUI_01204668 in Mass Storage mode, if Alarm is ringing on th background,
//		ASSERT(0);            //plug out and in usb cable, system doesn't shutdown until Alarm stops.
                            // In this case,USb_Init_MS function can be executed twice.

#ifdef __NVRAM_IN_USB_MS__
	/* Notify UEM*/
	USB_Send_Msg(USB_SEND_MSG_PLUG_IN);
#else
	if(bFirst == KAL_TRUE)
	{
		/* Notify UEM*/
		USB_Send_Msg(USB_SEND_MSG_PLUG_IN);
	}
#endif

	/* If not first time plug in, only notify UEM*/
	if(bFirst == KAL_TRUE)
	{
		/* Get unique string from nvram and construct serial string*/
		USB_Get_Serial_Value();

		/* Initailize IMAGE class */
		USB_Register_CreateFunc("IMAGE_MTP", USB_Image_If_Create, USB_Image_If_Reset,
									USB_Image_If_Enable, USB_Image_If_Speed_Reset, NULL);
		USB_Register_Device_Code(USB_IMAGE_DEVICE_CODE, USB_IMAGE_SUBCLASS_CODE,
									USB_IMAGE_PROTOCOL_CODE, g_USBImage.mtp_image_param->desc_product);

		/* Must lock file system before turn on USB power */
		USB_Init(USB_IMAGE_MTP, KAL_TRUE, KAL_FALSE);
	}
}

#endif /* __MTP_ENABLE__ */

