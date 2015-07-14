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
 *    usb_host_default_drv.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements host default class driver
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef __OTG_ENABLE__

#include "drv_comm.h"
//#include "stack_common.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "kal_public_api.h" //#include "stack_ltlcom.h" //MSBB change #include "app_ltlcom.h"       /* Task message communiction */
#include "usbd.h"
#include "otg_if.h"
//#include "otg_drv.h"
#include "dcl.h"
#include "otg.h"
#include "usb_debug_tool.h"
//#include "kal_non_specific_general_types.h"
#include "kal_public_api.h" //#include "stack_ltlcom.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "kal_general_types.h"


static kal_bool USB_Host_Default_Match(kal_uint8 usb_ip_port,USBD_Desc_Info *p_desc_info, kal_uint32 cfg_num, kal_uint32 if_num)
{
//	*p_cfg_num = 0;
	return KAL_TRUE;
}


static void USB_Host_Default_Startup(kal_uint8 usb_ip_port, USBD_Desc_Info *p_desc_info, kal_uint32 cfg_num, kal_uint32 if_num)
{
//	ilm_struct *USB_ilm = NULL;
	OTG_DRV_CTRL_GET_PLUG_TYPE_T  dcl_data;
	OTG_PLUG_TYPE plug_type;


	DclOTG_DRV_Control(g_OTG_Dcl_Handle, OTG_DRV_CMD_GET_PLUG_TYPE, (DCL_CTRL_DATA_T  *)&dcl_data);
	plug_type = (OTG_PLUG_TYPE)dcl_data.type;

	USB_Dbg_Trace(USB_HOST_DEFAULT_STARTUP, (kal_uint32)plug_type, (kal_uint32)USBD_Get_HNP_Support(usb_ip_port));

//	if(OTG_Get_Plug_Type() == OTG_PLUG_A)
	if(plug_type == OTG_PLUG_A)
	{
		if(USBD_Get_HNP_Support(usb_ip_port) == USBD_HNP_NOT_SUPPORT)
		{
			if(USBD_Is_Match_Hub(usb_ip_port) == KAL_FALSE)
				OTG_Display_Message(OTG_DISPLAY_MSG_UN_SUPPORT);
			else
				OTG_Display_Message(OTG_DISPLAY_MSG_HUB_NOT_SUPPORT);

			/* Compliance test only */
	#ifndef __OTG_SRP_HNP_APP_FIXED__
			DclOTG_DRV_Control(g_OTG_Dcl_Handle, OTG_DRV_CMD_A_STOP_HOST, NULL);
//			OTG_A_Stop_Host();
	#endif

			USB_Dbg_Trace(USBD_HOST_STOP_VBUS,  1, 0);
		}
		else if (USBD_Get_HNP_Support(usb_ip_port) == USBD_HNP_ENABLE_STALL)
		{
			OTG_Display_Message(OTG_DISPLAY_MSG_NO_RESPONSE);

			/* Compliance test only */
	#ifndef __OTG_SRP_HNP_APP_FIXED__
			DclOTG_DRV_Control(g_OTG_Dcl_Handle, OTG_DRV_CMD_A_STOP_HOST, NULL);
//			OTG_A_Stop_Host();
	#endif
			
			USB_Dbg_Trace(USBD_HOST_STOP_VBUS, 2, 0);
		}
		else
		{
			OTG_Display_Message(OTG_DISPLAY_MSG_HNP_PROCESS);

			USB_Send_Msg_Ext_Queue(MOD_USB,MSG_ID_USBD_START_HNP,NULL);

//			DRV_BuildPrimitive(USB_ilm,stack_get_active_module_id(),MOD_USB,MSG_ID_USBD_START_HNP,NULL);
//			msg_send_ext_queue(USB_ilm);
		}
	}
	else
	{
		OTG_Display_Message(OTG_DISPLAY_MSG_UN_SUPPORT);
		DclOTG_DRV_Control(g_OTG_Dcl_Handle, OTG_DRV_CMD_B_STOP_HOST, NULL);
//		OTG_B_Stop_Host();
	}
}


static void USB_Host_Default_Detach(kal_uint8 usb_ip_port)
{
	// for test
	volatile static kal_uint32 detach_count = 0;


	detach_count++;
}


static void USB_Host_Default_Suspend(kal_uint8 usb_ip_port)
{
	// for test
//	volatile static kal_uint32 detach_count = 0;


//	detach_count++;
}


static void USB_Host_Default_Resume(kal_uint8 usb_ip_port)
{
	// for test
//	volatile static kal_uint32 detach_count = 0;


//	detach_count++;
}


USBD_ClassDriver_Struct USB_Host_Ext_Default_Drv =
{
	USB_Host_Default_Match,
	USB_Host_Default_Startup,
	USB_Host_Default_Detach,
	USB_Host_Default_Suspend,
	USB_Host_Default_Resume
};
#endif


#ifdef __IC_USB_ENABLE__

static kal_bool	USB_Host_Int_Default_Match(kal_uint8 usb_ip_port,USBD_Desc_Info *p_desc_info, kal_uint32 cfg_num, kal_uint32 if_num)
{
	ASSERT(0);
	return KAL_TRUE;
}


static void USB_Host_Int_Default_Startup(kal_uint8 usb_ip_port, USBD_Desc_Info *p_desc_info, kal_uint32 cfg_num, kal_uint32 if_num)
{
	USB_Host_ICCD_Enumeration_Fail(usb_ip_port);
}


static void USB_Host_Int_Default_Detach(kal_uint8 usb_ip_port)
{

}


static void USB_Host_Int_Default_Suspend(kal_uint8 usb_ip_port)
{

}


static void USB_Host_Int_Default_Resume(kal_uint8 usb_ip_port)
{

}


USBD_ClassDriver_Struct USB_Host_Int_Default_Drv =
{
	USB_Host_Int_Default_Match,
	USB_Host_Int_Default_Startup,
	USB_Host_Int_Default_Detach,
	USB_Host_Int_Default_Suspend,
	USB_Host_Int_Default_Resume
};

#endif

