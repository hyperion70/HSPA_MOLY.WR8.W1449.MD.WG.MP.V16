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
 *   usbvideo_drv.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements usb video class driver
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
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef WEBCAM_SUPPORT


#include "drv_comm.h"
#include "intrCtrl.h"
//#include "stack_common.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "kal_public_api.h" //#include "stack_ltlcom.h" //MSBB change #include "app_ltlcom.h"
//#include "app_buff_alloc.h"
//#include "usb_comm.h"
#include "dcl.h"
//#include "usb_drv.h"
#include "usb_adap.h"
#include "usb.h"
#include "usb_resource.h"
#include "usbvideo_drv.h"
//#include "usbvideo_state.h"
#include "usb_custom.h"
#include "usbvideo_if.h"
#include "usbvideo_custom.h"
#include "usb_debug_tool.h"
#include "usb_trc.h"
//#include "kal_non_specific_general_types.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "kal_public_api.h" //#include "stack_ltlcom.h"
//#include "kal_release.h"
#include "kal_trace.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "usb_custom_def.h"

/*This will be removed when change back to media task*/
//#include "custom_config.h"
#include "cal_comm_def.h"
#include "cal_api.h"
#include "mm_comm_def.h"

CAL_FEATURE_WEBCAM_GET_ATTR_INFO_STRUCT UsbvideoAttrInfo;      // CAL_FEATURE_WEBCAM_GET_ATTR_INFO
CAL_FEATURE_WEBCAM_GET_VIDEO_SIZE_STRUCT UsbvideoVideoSize;    // CAL_FEATURE_WEBCAM_GET_VIDEO_SIZE
CAL_FEATURE_WEBCAM_GET_STILL_SIZE_STRUCT UsbvideoStillSize;    // CAL_FEATURE_WEBCAM_GET_STILL_SIZE
CAL_FEATURE_WEBCAM_GET_COMPRESSION_STRUCT UsbvideoCompression; // CAL_FEATURE_WEBCAM_GET_COMPRESSION
CAL_FEATURE_WEBCAM_GET_DEFAULT_IDX_STRUCT UsbvideoDeafultIdx;  // CAL_FEATURE_WEBCAM_GET_DEFAULT_IDX
CAL_FEATURE_CTRL_STRUCT CalFeatureCtrlStruct;



USBVideo_Struct g_USBVideo;

/* Static functions */
static void USBVideo_Send_Set_Attr_Meg(void);
static void USBVideo_Set_Attr(void *data);
static void USBVideo_Set_ProbControl(void *data);
static void USBVideo_Set_Still_ProbControl(void *data);
static void USBVideo_Set_Still_ImageControl(void *data);/* take picture */
static void USBVideo_Ep0_VC_Command(Usb_Ep0_Status *pep0state, Usb_Command *pcmd);
static void USBVideo_Ep0_VS_Command(Usb_Ep0_Status *pep0state, Usb_Command *pcmd);
static void USBVideo_IntrTx_Reset(void);
#ifdef  __WEBCAM_SUPPORT_ISO_PIPE__
static void USBVideo_IsoTx_Reset(void);
#else
static void USBVideo_BulkTx_Reset(void);
#endif
static void USBVideo_IntrTx_Hdlr(void );
static void USBVideo_Tx_Incall_DMA_Callback(void);
static void USBVideo_Tx_DMA_Callback(void);
#ifdef  __WEBCAM_SUPPORT_ISO_PIPE__
static void USBVideo_SetInterface_Callback(Usb_Command *pcmd);
#else
static void USBVideo_ClearFeature_Callback(Usb_Command *pcmd);
#endif

static kal_uint8* USBVideo_Get_Video_Buffer(void);
static void USBVideo_Complete_Video_Buffer(kal_uint8* addr, kal_uint32 size, kal_uint32 time, USBVIDEO_VIDEO_SIZE_TYPE video_size_type);
static kal_uint8* USBVideo_Get_Still_Buffer(void);
static void USBVideo_Complete_Still_Buffer(kal_uint8* addr, kal_uint32 size, kal_uint32 time, USBVIDEO_STILL_SIZE_TYPE still_size_type);
static void USBVideo_Set_Default_JPEG_Max_Size(kal_uint8 index, kal_uint32 max_size);

//=================== DCL Interface API =============================================//

DCL_STATUS USB_Video_Driver(DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	DCL_STATUS return_status = STATUS_OK;
	
	switch (cmd)
	{
		case USB_Video_CMD_Set_Default_JPEG_Max_Size:
			{
				USB_VIDEO_CTRL_FUNC1_T* prVideo_Ctrl_Fun1;
				prVideo_Ctrl_Fun1 = &(data->rVideo_Ctrl_Fun1);
				USBVideo_Set_Default_JPEG_Max_Size((kal_uint8)prVideo_Ctrl_Fun1->uindex,(kal_uint32)prVideo_Ctrl_Fun1->u4max_size);
			}
			break;
		
		case USB_Video_CMD_Complete_Still_Buffer:
			{
				USB_VIDEO_CTRL_FUNC2_T* prVideo_Ctrl_Fun2;
				prVideo_Ctrl_Fun2 = &(data->rVideo_Ctrl_Fun2);			
				USBVideo_Complete_Still_Buffer((kal_uint8 *)prVideo_Ctrl_Fun2->uaddr , (kal_uint32)prVideo_Ctrl_Fun2->u4size,(kal_uint32)prVideo_Ctrl_Fun2->u4time,(USBVIDEO_STILL_SIZE_TYPE)prVideo_Ctrl_Fun2->u4size_type);
			}
			break;

		case USB_Video_CMD_Complete_Video_Buffer:
			{
				USB_VIDEO_CTRL_FUNC2_T* prVideo_Ctrl_Fun2;
				prVideo_Ctrl_Fun2 = &(data->rVideo_Ctrl_Fun2);			
				USBVideo_Complete_Video_Buffer((kal_uint8 *)prVideo_Ctrl_Fun2->uaddr , (kal_uint32)prVideo_Ctrl_Fun2->u4size,(kal_uint32)prVideo_Ctrl_Fun2->u4time,(USBVIDEO_VIDEO_SIZE_TYPE)prVideo_Ctrl_Fun2->u4size_type);
			}
			break;

		case USB_Video_CMD_Get_Still_Buffer:
			{
				USB_VIDEO_CTRL_FUNC3_T* prVideo_Ctrl_Fun3;
				prVideo_Ctrl_Fun3 = &(data->rVideo_Ctrl_Fun3);			
				prVideo_Ctrl_Fun3->u2Retresult = (DCL_UINT8 *)USBVideo_Get_Still_Buffer();
			}
			break;

		case USB_Video_CMD_Get_Video_Buffer:
			{
				USB_VIDEO_CTRL_FUNC3_T* prVideo_Ctrl_Fun3;
				prVideo_Ctrl_Fun3 = &(data->rVideo_Ctrl_Fun3);
				prVideo_Ctrl_Fun3->u2Retresult = (DCL_UINT8 *)USBVideo_Get_Video_Buffer();
			}
			break;

		default:
			return_status = STATUS_INVALID_CMD;
			break;
	}
	return return_status;
}

/************************************************************
	Attribute tables
*************************************************************/

/* subtype lengths */
static const USBVideo_Attr_Sub_Map g_USBVideo_Focus_Map[] =
{
	{(kal_uint8)USBVIDEO_ATTR_FOCUS_SET, 1},
	{(kal_uint8)USBVIDEO_ATTR_FOCUS_SPEED, 1}
};


static const USBVideo_Attr_Sub_Map g_USBVideo_Zoom_Map[] =
{
	{(kal_uint8)USBVIDEO_ATTR_ZOOM_ZOOM, 1},
	{(kal_uint8)USBVIDEO_ATTR_ZOOM_DIGITALZOOM, 1},
	{(kal_uint8)USBVIDEO_ATTR_ZOOM_SPEED, 1}
};


static const USBVideo_Attr_Sub_Map g_USBVideo_PanTilt_Ab_Map[] =
{
	{(kal_uint8)USBVIDEO_ATTR_AB_PANTILT_PAN, 4},
	{(kal_uint8)USBVIDEO_ATTR_AB_PANTILT_TILT, 4}
};


static const USBVideo_Attr_Sub_Map g_USBVideo_PanTilt_Re_Map[] =
{
	{(kal_uint8)USBVIDEO_ATTR_RE_PANTILT_PAN, 1},
	{(kal_uint8)USBVIDEO_ATTR_RE_PANTILT_PAN_SPEED, 1},
	{(kal_uint8)USBVIDEO_ATTR_RE_PANTILT_TILT, 1},
	{(kal_uint8)USBVIDEO_ATTR_RE_PANTILT_TILT_SPEED, 1}
};


static const USBVideo_Attr_Sub_Map g_USBVideo_Roll_Map[] =
{
	{(kal_uint8)USBVIDEO_ATTR_ROLL_SET, 1},
	{(kal_uint8)USBVIDEO_ATTR_ROLL_SPEED, 1}
};


static const USBVideo_Attr_Sub_Map g_USBVideo_AWB_Map[] =
{
	{(kal_uint8)USBVIDEO_ATTR_WHITE_BALANCE_BLUE, 2},
	{(kal_uint8)USBVIDEO_ATTR_WHITE_BALANCE_RED, 2}
};


/* CT attribute. Descriptor shift mapping table, attribute data length, and whether it has subtypes*/
static const USBVideo_Attr_Map g_USBVideo_CT_Attr_Map[] =
{
	{USBVIDEO_ATTRIBUTE_SCANNING_MODE, 0, 1, NULL},
	{USBVIDEO_ATTRIBUTE_AE_MODE, 1, 1, NULL},
	{USBVIDEO_ATTRIBUTE_AE_PRIORITY, 2, 1, NULL},
	{USBVIDEO_ATTRIBUTE_EXP_TIME_ABSOLUTE, 3, 4, NULL},
	{USBVIDEO_ATTRIBUTE_EXP_TIME_RELATIVE, 4, 1, NULL},
	{USBVIDEO_ATTRIBUTE_FOCUS_ABSOLUTE, 5, 2, NULL},
	{USBVIDEO_ATTRIBUTE_FOCUS_RELATIVE, 6, 2, g_USBVideo_Focus_Map},
	{USBVIDEO_ATTRIBUTE_FOCUS_AUTO, 17, 1, NULL},
	{USBVIDEO_ATTRIBUTE_IRIS_ABSOLUTE, 7, 2, NULL},
	{USBVIDEO_ATTRIBUTE_IRIS_RELATIVE, 8, 1, NULL},
	{USBVIDEO_ATTRIBUTE_ZOOM_ABSOLUTE, 9, 2, NULL},
	{USBVIDEO_ATTRIBUTE_ZOOM_RELATIVE, 10, 3, g_USBVideo_Zoom_Map},
	{USBVIDEO_ATTRIBUTE_PANTILT_ABSOLUTE, 11, 8, g_USBVideo_PanTilt_Ab_Map},
	{USBVIDEO_ATTRIBUTE_PANTILT_RELATIVE, 12, 4, g_USBVideo_PanTilt_Re_Map},
	{USBVIDEO_ATTRIBUTE_ROLL_ABSOLUTE, 13, 2, NULL},
	{USBVIDEO_ATTRIBUTE_ROLL_RELATIVE, 14, 2, g_USBVideo_Roll_Map},
	{USBVIDEO_ATTRIBUTE_PRIVACY, 18, 1, NULL}
};


/* PU attribute. Descriptor shift mapping table, attribute data length, and whether it has subtypes*/
static const USBVideo_Attr_Map g_USBVideo_PU_Attr_Map[] =
{
	{USBVIDEO_ATTRIBUTE_BACKLIGHT_COMPENSATION, 8, 2, NULL},
	{USBVIDEO_ATTRIBUTE_BRIGHTNESS, 0, 2, NULL},
	{USBVIDEO_ATTRIBUTE_CONTRAST, 1, 2, NULL},
	{USBVIDEO_ATTRIBUTE_GAIN, 9, 2, NULL},
	{USBVIDEO_ATTRIBUTE_POWER_LINE_FREQUENCY, 10, 1, NULL},
	{USBVIDEO_ATTRIBUTE_HUE, 2, 2, NULL},
	{USBVIDEO_ATTRIBUTE_SATURATION, 3, 2, NULL},
	{USBVIDEO_ATTRIBUTE_SHARPNESS, 4, 2, NULL},
	{USBVIDEO_ATTRIBUTE_GAMMA, 5, 2, NULL},
	{USBVIDEO_ATTRIBUTE_WHITE_BALANCE_TMP, 6, 2, NULL},
	{USBVIDEO_ATTRIBUTE_WHITE_BALANCE_TMP_AUTO, 12, 1, NULL},
	{USBVIDEO_ATTRIBUTE_WHITE_BALANCE_COMP, 7, 4, g_USBVideo_AWB_Map},
	{USBVIDEO_ATTRIBUTE_WHITE_BALANCE_COMP_AUTO, 13, 1, NULL},
	{USBVIDEO_ATTRIBUTE_DIGITAL_MULTIPLIER, 14, 2, NULL},
	{USBVIDEO_ATTRIBUTE_DIGITAL_MULTIPLIER_LIMIT, 15, 2, NULL},
	{USBVIDEO_ATTRIBUTE_HUE_AUTO, 11, 1, NULL}
	//{USBVIDEO_ATTRIBUTE_ANALOG_VIDEO_STANDARD, 16, 1, NULL},	/* for 1.1 version*/
	//{USBVIDEO_ATTRIBUTE_ANALOG_LOCK_STATUS, 17, 1, NULL}
};

/* Used to store the attributes(may be come from multiple set confirm), and gather them all,
    return to host at one time */
static kal_uint8 g_USBVideo_Attr_Value[USBVIDEO_MAX_ATTR_VALUE_SIZE];

/************************************************************
	utility functions
*************************************************************/
static kal_uint32 USBVideo_Get_Max(kal_uint32 value1, kal_uint32 value2)
{
	if(value1 >= value2)
		return value1;
	else
		return value2;
}


/************************************************************
	Send message function used by the whole video class driver
*************************************************************/

void USBVideo_Send_Msg(USBVIDEO_MSG_TYPE usb_msg_type, kal_uint32 param1, kal_uint32 param2)
{
	usbvideo_video_size_struct *start_cnf;
	usbvideo_still_size_struct *still_ind;
	usbvideo_still_dma_struct *still_dma;
	usbvideo_result_struct *result;
//	ilm_struct *send_ilm = NULL;
	module_type dest_mod;

#if ( (defined(__WEBCAM_CAMERA_TEST__)) || (defined(__WEBCAM_USB_TEST__)) )
	dest_mod = MOD_CUSTOM1;
#else
	dest_mod = MOD_MED;
#endif


//	src_mod = stack_get_active_module_id();

	if(usb_msg_type == USBVIDEO_MSG_MED_START_SUCCESS_CNF)
	{
		start_cnf = (usbvideo_video_size_struct*)construct_local_para(
							sizeof(usbvideo_video_size_struct), TD_CTRL);
		start_cnf->video_size_type = (USBVIDEO_VIDEO_SIZE_TYPE)param1;
		start_cnf->video_compression_type = (USBVIDEO_COMPRESSION_TYPE)param2;
		start_cnf->result = CONFIG_OK;

		USB_Send_Msg_Ext_Queue(dest_mod,MSG_ID_USB_MED_START_VIDEO_CNF,start_cnf);

//		DRV_BuildPrimitive(send_ilm,src_mod,dest_mod,MSG_ID_USB_MED_START_VIDEO_CNF,start_cnf);
	}
	else if(usb_msg_type == USBVIDEO_MSG_MED_START_FAIL_CNF)
	{
		start_cnf = (usbvideo_video_size_struct*)construct_local_para(
							sizeof(usbvideo_video_size_struct), TD_CTRL);
		start_cnf->video_size_type = (USBVIDEO_VIDEO_SIZE_TYPE)param1;
		start_cnf->video_compression_type = (USBVIDEO_COMPRESSION_TYPE)param2;
		start_cnf->result = CONFIG_FAIL; /*  because USB cable plug out */

		USB_Send_Msg_Ext_Queue(dest_mod,MSG_ID_USB_MED_START_VIDEO_CNF,start_cnf);

//		DRV_BuildPrimitive(send_ilm,src_mod,dest_mod,MSG_ID_USB_MED_START_VIDEO_CNF,start_cnf);
	}
	else if(usb_msg_type == USBVIDEO_MSG_MED_START_FAIL_CONFIG_CNF)
	{
		start_cnf = (usbvideo_video_size_struct*)construct_local_para(
							sizeof(usbvideo_video_size_struct), TD_CTRL);
		start_cnf->video_size_type = (USBVIDEO_VIDEO_SIZE_TYPE)param1;
		start_cnf->video_compression_type = (USBVIDEO_COMPRESSION_TYPE)param2;
		start_cnf->result = CANNOT_CONFIG; /*  because USB cable plug out */

		USB_Send_Msg_Ext_Queue(dest_mod,MSG_ID_USB_MED_START_VIDEO_CNF,start_cnf);
//		DRV_BuildPrimitive(send_ilm,src_mod,dest_mod,MSG_ID_USB_MED_START_VIDEO_CNF,start_cnf);
	}
	else if(usb_msg_type == USBVIDEO_MSG_MED_CHANGE_VIDEO_IND)
	{
		start_cnf = (usbvideo_video_size_struct*)construct_local_para(
							sizeof(usbvideo_video_size_struct), TD_CTRL);
		start_cnf->video_size_type = (USBVIDEO_VIDEO_SIZE_TYPE)param1;
		start_cnf->video_compression_type = (USBVIDEO_COMPRESSION_TYPE)param2;
		start_cnf->result = CONFIG_OK;

		USB_Send_Msg_Ext_Queue(dest_mod,MSG_ID_USB_MED_CHANGE_VIDEO_IND,start_cnf);

//		DRV_BuildPrimitive(send_ilm,src_mod,dest_mod,MSG_ID_USB_MED_CHANGE_VIDEO_IND,start_cnf);
	}
	else if(usb_msg_type == USBVIDEO_MSG_MED_STILL_CAPTURE_IND)
	{
		still_ind = (usbvideo_still_size_struct*)construct_local_para(
							sizeof(usbvideo_still_size_struct), TD_CTRL);
		still_ind->still_size_type = (USBVIDEO_STILL_SIZE_TYPE)param1;
		still_ind->still_compression_type = (USBVIDEO_COMPRESSION_TYPE)param2;

		USB_Send_Msg_Ext_Queue(dest_mod,MSG_ID_USB_MED_START_STILL_IND,still_ind);

//		DRV_BuildPrimitive(send_ilm,src_mod,dest_mod,MSG_ID_USB_MED_START_STILL_IND,still_ind);
	}
	else if(usb_msg_type == USBVIDEO_MSG_MED_START_IND)
	{
		start_cnf = (usbvideo_video_size_struct*)construct_local_para(
							sizeof(usbvideo_video_size_struct), TD_CTRL);
		start_cnf->video_size_type = (USBVIDEO_VIDEO_SIZE_TYPE)param1;
		start_cnf->video_compression_type = (USBVIDEO_COMPRESSION_TYPE)param2;
		start_cnf->result = CONFIG_OK;

		USB_Send_Msg_Ext_Queue(dest_mod,MSG_ID_USB_MED_START_VIDEO_IND,  start_cnf);
		/* restart video after still capture */

//		DRV_BuildPrimitive(send_ilm,src_mod,dest_mod,MSG_ID_USB_MED_START_VIDEO_IND,  start_cnf);
	}
	else if(usb_msg_type == USBVIDEO_MSG_MED_DEVICE_STILL_CNF)  /* be used at HW trigger */
	{
		result = (usbvideo_result_struct*)construct_local_para(
							sizeof(usbvideo_result_struct), TD_CTRL);
		result->result = (kal_bool) param1;

		USB_Send_Msg_Ext_Queue(dest_mod,MSG_ID_USB_MED_DEVICE_STILL_CNF,result);

//		DRV_BuildPrimitive(send_ilm,src_mod,dest_mod,MSG_ID_USB_MED_DEVICE_STILL_CNF,result);
	}
	else if(usb_msg_type == USBVIDEO_MSG_MED_PAUSE_CNF)
	{
		result = (usbvideo_result_struct*)construct_local_para(
							sizeof(usbvideo_result_struct), TD_CTRL);
		result->result = (kal_bool) param1;

		USB_Send_Msg_Ext_Queue(dest_mod,MSG_ID_USB_MED_PAUSE_CNF,result);

//		DRV_BuildPrimitive(send_ilm,src_mod,dest_mod,MSG_ID_USB_MED_PAUSE_CNF,result);
	}
	else if(usb_msg_type == USBVIDEO_MSG_MED_RESUME_SUCCESS_CNF)
	{
		start_cnf = (usbvideo_video_size_struct*)construct_local_para(
							sizeof(usbvideo_video_size_struct), TD_CTRL);
		start_cnf->video_size_type = (USBVIDEO_VIDEO_SIZE_TYPE)param1;
		start_cnf->video_compression_type = (USBVIDEO_COMPRESSION_TYPE)param2;
		start_cnf->result = CONFIG_OK;

		USB_Send_Msg_Ext_Queue(dest_mod,MSG_ID_USB_MED_RESUME_VIDEO_CNF,start_cnf);
//		DRV_BuildPrimitive(send_ilm,src_mod,dest_mod,MSG_ID_USB_MED_RESUME_VIDEO_CNF,start_cnf);
	}
	else if(usb_msg_type == USBVIDEO_MSG_MED_RESUME_FAIL_CNF)
	{
		start_cnf = (usbvideo_video_size_struct*)construct_local_para(
							sizeof(usbvideo_video_size_struct), TD_CTRL);
		start_cnf->video_size_type = (USBVIDEO_VIDEO_SIZE_TYPE)param1;
		start_cnf->video_compression_type = (USBVIDEO_COMPRESSION_TYPE)param2;
		start_cnf->result = CONFIG_FAIL;

		USB_Send_Msg_Ext_Queue(dest_mod,MSG_ID_USB_MED_RESUME_VIDEO_CNF,start_cnf);
//		DRV_BuildPrimitive(send_ilm,src_mod,dest_mod,MSG_ID_USB_MED_RESUME_VIDEO_CNF,start_cnf);
	}
	else if(usb_msg_type == USBVIDEO_MSG_MED_STOP_IND) /*stop because of cable plugging out */
	{

		USB_Send_Msg_Ext_Queue(dest_mod,MSG_ID_USB_MED_STOP_IND,NULL);

//		DRV_BuildPrimitive(send_ilm,src_mod,dest_mod,MSG_ID_USB_MED_STOP_IND,NULL);
	}
	else if(usb_msg_type == USBVIDEO_MSG_MED_STOP_CNF)  /* stop request from media task */
	{
		result = (usbvideo_result_struct*)construct_local_para(
							sizeof(usbvideo_result_struct), TD_CTRL);
		result->result = (kal_bool) param1;

		USB_Send_Msg_Ext_Queue(dest_mod,MSG_ID_USB_MED_STOP_CNF,result);

//		DRV_BuildPrimitive(send_ilm,src_mod,dest_mod,MSG_ID_USB_MED_STOP_CNF,result);
	}
	else if(usb_msg_type == USBVIDEO_MSG_MED_ABORT_IND) /* OS sleep then wakeup, webcam must be abort */
	{
		USB_Send_Msg_Ext_Queue(dest_mod,MSG_ID_USB_MED_ABORT_IND,NULL);

//		DRV_BuildPrimitive(send_ilm,src_mod,dest_mod,MSG_ID_USB_MED_ABORT_IND,NULL);
	}
	else if(usb_msg_type == USBVIDEO_MSG_USB_ENUM_DONE)
	{
		USB_Send_Msg_Ext_Queue(MOD_USB,MSG_ID_USB_ENUM_DONE,NULL);

//		DRV_BuildPrimitive(send_ilm,src_mod,MOD_USB,MSG_ID_USB_ENUM_DONE,NULL);
	}
	else if(usb_msg_type == USBVIDEO_MSG_USB_COMPLETE_VIDEO)
	{

		/* !!! Note that source need to modify after camera phase in*/
		USB_Send_Msg_Ext_Queue(MOD_USB,MSG_ID_USB_VIDEO_COMPLETE,NULL);

//		DRV_BuildPrimitive(send_ilm,src_mod,MOD_USB,MSG_ID_USB_VIDEO_COMPLETE,NULL);
	}
	else if(usb_msg_type == USBVIDEO_MSG_USB_DMA_DONE)
	{
		USB_Send_Msg_Ext_Queue(MOD_USB,MSG_ID_USB_VIDEO_DMA_DONE,NULL);
//		DRV_BuildPrimitive(send_ilm,(module_type)param1,MOD_USB,MSG_ID_USB_VIDEO_DMA_DONE,NULL);
//		msg_send_ext_queue(send_ilm);
	}
	else if(usb_msg_type == USBVIDEO_MSG_USB_CHANGE_SIZE)
	{
		USB_Send_Msg_Ext_Queue(MOD_USB,MSG_ID_USB_VIDEO_CHANGE_SIZE,NULL);

//		DRV_BuildPrimitive(send_ilm,src_mod,MOD_USB,MSG_ID_USB_VIDEO_CHANGE_SIZE,NULL);
	}
	else if(usb_msg_type == USBVIDEO_MSG_USB_STILL_CAPTURE)
	{
		USB_Send_Msg_Ext_Queue(MOD_USB,MSG_ID_USB_STILL_CAPTURE,NULL);

//		DRV_BuildPrimitive(send_ilm,src_mod,MOD_USB,MSG_ID_USB_STILL_CAPTURE,NULL);
	}
	else if(usb_msg_type == USBVIDEO_MSG_USB_COMPLETE_STILL)
	{
		/* !!! Note that source need to modify after camera phase in*/
		USB_Send_Msg_Ext_Queue(MOD_USB,MSG_ID_USB_STILL_COMPLETE,NULL);

//		DRV_BuildPrimitive(send_ilm,src_mod,MOD_USB,MSG_ID_USB_STILL_COMPLETE,NULL);
	}
	else if(usb_msg_type == USBVIDEO_MSG_USB_STILL_DMA_DONE)
	{
		USB_Send_Msg_Ext_Queue(MOD_USB,MSG_ID_USB_VIDEO_STILL_DMA_DONE,NULL);

//		DRV_BuildPrimitive(send_ilm,(module_type)param1,MOD_USB,MSG_ID_USB_VIDEO_STILL_DMA_DONE,NULL);
//		msg_send_ext_queue(send_ilm);

	}
	else if(usb_msg_type == USBVIDEO_MSG_USB_STILL_DMA_PARTIAL)
	{
		still_dma = (usbvideo_still_dma_struct*)construct_local_para(
							sizeof(usbvideo_still_dma_struct), TD_CTRL);
		still_dma->index = param1;
		
		USB_Send_Msg_Ext_Queue(MOD_USB,MSG_ID_USB_VIDEO_STILL_DMA_PARTIAL,still_dma);

//		DRV_BuildPrimitive(send_ilm,src_mod,MOD_USB,MSG_ID_USB_VIDEO_STILL_DMA_PARTIAL,still_dma);
	}
	else if(usb_msg_type == USBVIDEO_MSG_USB_INCALL_DMA_DONE)
	{
		USB_Send_Msg_Ext_Queue(MOD_USB,MSG_ID_USB_VIDEO_INCALL_DMA_DONE,NULL);

//		DRV_BuildPrimitive(send_ilm,(module_type)param1,MOD_USB,MSG_ID_USB_VIDEO_INCALL_DMA_DONE,NULL);		
//		msg_send_ext_queue(send_ilm);
	}
	else if(usb_msg_type == USBVIDEO_MSG_USB_INCALL_TIMEOUT)
	{
		USB_Send_Msg_Ext_Queue(MOD_USB,MSG_ID_USB_VIDEO_INCALL_TIMEOUT,NULL);

//		DRV_BuildPrimitive(send_ilm,src_mod,MOD_USB,MSG_ID_USB_VIDEO_INCALL_TIMEOUT,NULL);
	}
	else if(usb_msg_type == USBVIDEO_MSG_USB_INCALL_CHANGE_SIZE)
	{
		USB_Send_Msg_Ext_Queue(MOD_USB,MSG_ID_USB_VIDEO_INCALL_CHANGE_SIZE,NULL);

//		DRV_BuildPrimitive(send_ilm,src_mod,MOD_USB,MSG_ID_USB_VIDEO_INCALL_CHANGE_SIZE,NULL);
	}
/*
	else if(usb_msg_type == USBVIDEO_MSG_USB_ABORT)
	{
		USB_Send_Msg_Ext_Queue(send_ilm,MOD_USB,MSG_ID_USB_VIDEO_ABORT,NULL);

//		DRV_BuildPrimitive(send_ilm,src_mod,MOD_USB,MSG_ID_USB_VIDEO_ABORT,NULL);
	}
*/
	else
	{
//		send_ilm = NULL;
		EXT_ASSERT(0, (kal_uint32)usb_msg_type, 0, 0);
	}

//	msg_send_ext_queue(send_ilm);
}


/************************************************************
	interface initialization functions
*************************************************************/

/* video control interface create function, prepare descriptor */
void USBVideo_VC_If_Create(void *ifname)
{
	kal_uint8 ep_id;
	kal_uint8 if_id;
//	kal_uint8 iad_id;
	kal_uint8 vc_interface_string_num;
	USBVideo_Attr_Value attr_value;
	const USBVideo_Attr_Info* attr_info;
	kal_uint8 attr_size;
	kal_uint32 attr_index;
	kal_uint32 map_index, map_size;
	kal_uint16 ct_attr = 0;
	kal_uint16 pu_attr = 0;
	kal_uint32 total_size;
	kal_uint32 shift_index;
	kal_uint8* p_desc;
	kal_uint32 if_desc_index = 0;
	kal_uint32 ep_desc_index;


	/* Get resource number and register to gUsbDevice */
	g_USBVideo.vc_if_info = USB_Get_Interface_Number(&if_id);
	g_USBVideo.vc_ep_intr_info = USB_Get_Intr_Ep(&ep_id);

	/* record interface name and interface descriptor length */
	g_USBVideo.vc_if_info->interface_name_ptr = (kal_char *)ifname;
	g_USBVideo.vc_if_info->ifdscr_size = 0; /* Will be modified after the following attribute parts*/

	/* related endpoint info and class specific command handler*/
	g_USBVideo.vc_if_info->ep_info[0] = g_USBVideo.vc_ep_intr_info;
	g_USBVideo.vc_if_info->if_class_specific_hdlr = USBVideo_Ep0_VC_Command;

	/* Construct IAD descriptor */
	g_USBVideo.iad_desc = USB_Get_IAD_Number();
	g_USBVideo.iad_desc->bLength = USB_IAD_LENGTH;
	g_USBVideo.iad_desc->bDescriptorType = USB_INTERFACE_ASSOCIATION;
	g_USBVideo.iad_desc->bFirstInterface = if_id;
	g_USBVideo.iad_desc->bInterfaceCount = USBVIDEO_IF_NUMBER;
	g_USBVideo.iad_desc->bFunctionClass = USBVIDEO_CC_VIDEO;
	g_USBVideo.iad_desc->bFunctionSubClass = USBVIDEO_SC_VIDEO_INTERFACE_COLLECTION;
	g_USBVideo.iad_desc->bFunctionProtocol = USBVIDEO_PC_PROTOCOL_UNDEFINED;
	vc_interface_string_num = USB_Get_String_Number((void *)g_USBVideo.custom_param->vc_interface_string);
	g_USBVideo.iad_desc->iFunction = vc_interface_string_num;

	/* Standard interface descriptor */
	p_desc = get_ctrl_buffer(sizeof(Usb_If_Dscr));
	((Usb_If_Dscr*)p_desc)->bLength = USB_IFDSC_LENGTH;
	((Usb_If_Dscr*)p_desc)->bDescriptorType = USB_INTERFACE;
	((Usb_If_Dscr*)p_desc)->bInterfaceNumber = if_id;
	((Usb_If_Dscr*)p_desc)->bAlternateSetting = 0;
	((Usb_If_Dscr*)p_desc)->bNumEndpoints = USBVIDEO_VC_EP_NUMBER;
	((Usb_If_Dscr*)p_desc)->bInterfaceClass = USBVIDEO_CC_VIDEO;
	((Usb_If_Dscr*)p_desc)->bInterfaceSubClass = USBVIDEO_SC_VIDEOCONTROL;
	((Usb_If_Dscr*)p_desc)->bInterfaceProtocol = USBVIDEO_PC_PROTOCOL_UNDEFINED;
	((Usb_If_Dscr*)p_desc)->iInterface = vc_interface_string_num;
	kal_mem_cpy(&g_USBVideo.vc_if_info->ifdscr.classif[if_desc_index], p_desc, USB_IFDSC_LENGTH);
	if_desc_index += USB_IFDSC_LENGTH;
	free_ctrl_buffer(p_desc);

	/* class-specific VC interface descriptor */
	p_desc = get_ctrl_buffer(sizeof(USBVideo_Class_VC_If_Dscr));
	((USBVideo_Class_VC_If_Dscr*)p_desc)->bLength = USBVIDEO_VC_INTERFACE_LENGTH;
	((USBVideo_Class_VC_If_Dscr*)p_desc)->bDescriptorType = USBVIDEO_CS_INTERFACE;
	((USBVideo_Class_VC_If_Dscr*)p_desc)->bDescriptorSubType = USBVIDEO_VC_HEADER;
	//((USBVideo_Class_VC_If_Dscr*)p_desc)->bcdUSB[0] = 0x10; /* video spec rev is 1.1 */
	//((USBVideo_Class_VC_If_Dscr*)p_desc)->bcdUSB[1] = 0x01;
	((USBVideo_Class_VC_If_Dscr*)p_desc)->bcdUSB[0] = 0x00; /* video spec rev is 1.0 */
	((USBVideo_Class_VC_If_Dscr*)p_desc)->bcdUSB[1] = 0x01;
	total_size = sizeof(USBVideo_Class_VC_If_Dscr)+sizeof(USBVideo_CT_Dscr)+sizeof(USBVideo_OT_Dscr)+sizeof(USBVideo_PU_Dscr);
	((USBVideo_Class_VC_If_Dscr*)p_desc)->wTotalLength[0] = total_size&0xff;
	((USBVideo_Class_VC_If_Dscr*)p_desc)->wTotalLength[1] = (total_size>>8)&0xff;
	((USBVideo_Class_VC_If_Dscr*)p_desc)->dwClockFrequency[0] = USBVIDEO_CLOCK_FREQUENCY&0xff;
	((USBVideo_Class_VC_If_Dscr*)p_desc)->dwClockFrequency[1] = (USBVIDEO_CLOCK_FREQUENCY>>8)&0xff;
//	((USBVideo_Class_VC_If_Dscr*)p_desc)->dwClockFrequency[2] = (USBVIDEO_CLOCK_FREQUENCY>>16)&0xff;
//	((USBVideo_Class_VC_If_Dscr*)p_desc)->dwClockFrequency[3] = (USBVIDEO_CLOCK_FREQUENCY>>24)&0xff;
	((USBVideo_Class_VC_If_Dscr*)p_desc)->dwClockFrequency[2] = 0x00;
	((USBVideo_Class_VC_If_Dscr*)p_desc)->dwClockFrequency[3] = 0x00;
	((USBVideo_Class_VC_If_Dscr*)p_desc)->bInCollection = 1; /* number of VS interface*/
	((USBVideo_Class_VC_If_Dscr*)p_desc)->baInterfaceNr = if_id + 1; /* VS interface number */
	kal_mem_cpy(&g_USBVideo.vc_if_info->ifdscr.classif[if_desc_index ], p_desc, USBVIDEO_VC_INTERFACE_LENGTH);
	if_desc_index += USBVIDEO_VC_INTERFACE_LENGTH;
	free_ctrl_buffer(p_desc);

	/* input (camera) terminal descriptor */
	p_desc = get_ctrl_buffer(sizeof(USBVideo_CT_Dscr));
	((USBVideo_CT_Dscr*)p_desc)->bLength = USBVIDEO_VC_CT_LENGTH;
	((USBVideo_CT_Dscr*)p_desc)->bDescriptorType = USBVIDEO_CS_INTERFACE;
	((USBVideo_CT_Dscr*)p_desc)->bDescriptorSubType = USBVIDEO_VC_INPUT_TERMINAL;
	((USBVideo_CT_Dscr*)p_desc)->bTerminalID = USBVIDEO_CT_ID;
	((USBVideo_CT_Dscr*)p_desc)->wTerminalType[0] = USBVIDEO_ITT_CAMERA&0xff;
	((USBVideo_CT_Dscr*)p_desc)->wTerminalType[1] = (USBVIDEO_ITT_CAMERA>>8)&0xff;
	((USBVideo_CT_Dscr*)p_desc)->bAssocTerminal = 0x0; /* no association*/
	((USBVideo_CT_Dscr*)p_desc)->iTerminal = USB_Get_String_Number((void *)g_USBVideo.custom_param->vc_camera_string);
	((USBVideo_CT_Dscr*)p_desc)->wObjectiveFocalLengthMin[0] = 0;
	((USBVideo_CT_Dscr*)p_desc)->wObjectiveFocalLengthMin[1] = 0;
	((USBVideo_CT_Dscr*)p_desc)->wObjectiveFocalLengthMax[0] = 0;
	((USBVideo_CT_Dscr*)p_desc)->wObjectiveFocalLengthMax[1] = 0;
	((USBVideo_CT_Dscr*)p_desc)->wOcularFocalLength[0] = 0;
	((USBVideo_CT_Dscr*)p_desc)->wOcularFocalLength[1] = 0;
	((USBVideo_CT_Dscr*)p_desc)->bControlSize = 0x2;

//	attr_info = g_USBVideo.camera_param->usbvideo_get_attr_info(&attr_size);/*  look for Usbvideo_attr.c */
        CalFeatureCtrlStruct.FeatureCtrlCode = CAL_FEATURE_GET_OPERATION;
        CalFeatureCtrlStruct.FeatureId = CAL_FEATURE_WEBCAM_GET_ATTR_INFO;
        CalFeatureCtrlStruct.FeatureInfo.FeatureStructured.pWebCamAttrInfo = &UsbvideoAttrInfo;
        CalCtrl(CAL_FEATURE_CTRL, &CalFeatureCtrlStruct, NULL, 0, NULL);

        attr_info = UsbvideoAttrInfo.pWebCamAttrInfo;
        attr_size = UsbvideoAttrInfo.WebCamAttrInfoNum;


	if(attr_info == NULL)
		ASSERT(0);

	map_size = sizeof(g_USBVideo_CT_Attr_Map)/sizeof(USBVideo_Attr_Map);
	for(attr_index = 0; attr_index < attr_size; attr_index++)
	{
		if(attr_info[attr_index].b_feature == KAL_TRUE)		//lint !e613
		{
			for(map_index = 0; map_index < map_size; map_index++)
			{
				if(g_USBVideo_CT_Attr_Map[map_index].attr_type == attr_info[attr_index].type)	//lint !e613
				{
					/* descriptor attr */
					ct_attr |= (1<<g_USBVideo_CT_Attr_Map[map_index].shift);/* add into descriptor*/

					/* supported list */
					shift_index = (kal_uint32)attr_info[attr_index].type;	//lint !e613
					g_USBVideo.vc_ct_support |= (1<<shift_index);

					/* support set attribute list*/
					if(attr_info[attr_index].b_set == KAL_TRUE)	//lint !e613
					{
						g_USBVideo.vc_ct_set |= (1<<shift_index);
					}
				}
			}

			/* check attr in this descriptor */
			if(attr_info[attr_index].type == USBVIDEO_ATTRIBUTE_FOCAL_MIN)	//lint !e613
			{
				attr_value.type = USBVIDEO_ATTRIBUTE_FOCAL_MIN;
				attr_value.req_type = USBVIDEO_REQUEST_GET_CUR;
//				g_USBVideo.camera_param->usbvideo_get_attr_value(&attr_value);
				CalFeatureCtrlStruct.FeatureCtrlCode = CAL_FEATURE_GET_OPERATION;
				CalFeatureCtrlStruct.FeatureId = CAL_FEATURE_WEBCAM_GET_ATTR;
				CalFeatureCtrlStruct.FeatureInfo.FeatureStructured.pWebCamAttr = &attr_value;
				CalCtrl(CAL_FEATURE_CTRL, &CalFeatureCtrlStruct, NULL, 0, NULL);

				((USBVideo_CT_Dscr*)p_desc)->wObjectiveFocalLengthMin[0] = attr_value.value&0xff;
				((USBVideo_CT_Dscr*)p_desc)->wObjectiveFocalLengthMin[1] = (attr_value.value>>8)&0xff;
			}
			else if(attr_info[attr_index].type == USBVIDEO_ATTRIBUTE_FOCAL_MAX)	//lint !e613
			{
				attr_value.type = USBVIDEO_ATTRIBUTE_FOCAL_MAX;
				attr_value.req_type = USBVIDEO_REQUEST_GET_CUR;
//				g_USBVideo.camera_param->usbvideo_get_attr_value(&attr_value);
                    		CalFeatureCtrlStruct.FeatureCtrlCode = CAL_FEATURE_GET_OPERATION;
                    		CalFeatureCtrlStruct.FeatureId = CAL_FEATURE_WEBCAM_GET_ATTR;
                    		CalFeatureCtrlStruct.FeatureInfo.FeatureStructured.pWebCamAttr = &attr_value;
                    		CalCtrl(CAL_FEATURE_CTRL, &CalFeatureCtrlStruct, NULL, 0, NULL);

				((USBVideo_CT_Dscr*)p_desc)->wObjectiveFocalLengthMax[0] = attr_value.value&0xff;
				((USBVideo_CT_Dscr*)p_desc)->wObjectiveFocalLengthMax[1] = (attr_value.value>>8)&0xff;
			}
			else if(attr_info[attr_index].type == USBVIDEO_ATTRIBUTE_FOCAL_LENGTH)	//lint !e613
			{
				attr_value.type = USBVIDEO_ATTRIBUTE_FOCAL_LENGTH;
				attr_value.req_type = USBVIDEO_REQUEST_GET_CUR;
//				g_USBVideo.camera_param->usbvideo_get_attr_value(&attr_value);
                    		CalFeatureCtrlStruct.FeatureCtrlCode = CAL_FEATURE_GET_OPERATION;
                    		CalFeatureCtrlStruct.FeatureId = CAL_FEATURE_WEBCAM_GET_ATTR;
                    		CalFeatureCtrlStruct.FeatureInfo.FeatureStructured.pWebCamAttr = &attr_value;
                    		CalCtrl(CAL_FEATURE_CTRL, &CalFeatureCtrlStruct, NULL, 0, NULL);

				((USBVideo_CT_Dscr*)p_desc)->wOcularFocalLength[0] = attr_value.value&0xff;
				((USBVideo_CT_Dscr*)p_desc)->wOcularFocalLength[1] = (attr_value.value>>8)&0xff;
			}
		}
	}
	((USBVideo_CT_Dscr*)p_desc)->bmControls[0] = ct_attr&0xff;
	((USBVideo_CT_Dscr*)p_desc)->bmControls[1] = (ct_attr>>8)&0xff;
	kal_mem_cpy(&g_USBVideo.vc_if_info->ifdscr.classif[if_desc_index ], p_desc, USBVIDEO_VC_CT_LENGTH);
	if_desc_index += USBVIDEO_VC_CT_LENGTH;
	free_ctrl_buffer(p_desc);

	/* output terminal descriptor */
	p_desc = get_ctrl_buffer(sizeof(USBVideo_OT_Dscr));
	((USBVideo_OT_Dscr*)p_desc)->bLength = USBVIDEO_VC_OT_LENGTH;
	((USBVideo_OT_Dscr*)p_desc)->bDescriptorType = USBVIDEO_CS_INTERFACE;
	((USBVideo_OT_Dscr*)p_desc)->bDescriptorSubType = USBVIDEO_VC_OUTPUT_TERMINAL;
	((USBVideo_OT_Dscr*)p_desc)->bTerminalID = USBVIDEO_OT_ID;
	((USBVideo_OT_Dscr*)p_desc)->wTerminalType[0] = USBVIDEO_TT_STREAMING&0xff;
	((USBVideo_OT_Dscr*)p_desc)->wTerminalType[1] = (USBVIDEO_TT_STREAMING>>8)&0xff;
	((USBVideo_OT_Dscr*)p_desc)->bAssocTerminal = 0x0; /* no association*/
	((USBVideo_OT_Dscr*)p_desc)->bSourceID = USBVIDEO_PU_ID;
	((USBVideo_OT_Dscr*)p_desc)->iTerminal = USB_Get_String_Number((void *)g_USBVideo.custom_param->vc_output_string);
	kal_mem_cpy(&g_USBVideo.vc_if_info->ifdscr.classif[if_desc_index ], p_desc, USBVIDEO_VC_OT_LENGTH);
	if_desc_index += USBVIDEO_VC_OT_LENGTH;
	free_ctrl_buffer(p_desc);

	/* processing unit descriptor */
	p_desc = get_ctrl_buffer(sizeof(USBVideo_PU_Dscr));
	((USBVideo_PU_Dscr*)p_desc)->bLength = USBVIDEO_VC_PU_LENGTH;
	((USBVideo_PU_Dscr*)p_desc)->bDescriptorType = USBVIDEO_CS_INTERFACE;
	((USBVideo_PU_Dscr*)p_desc)->bDescriptorSubType = USBVIDEO_VC_PROCESSING_UNIT;
	((USBVideo_PU_Dscr*)p_desc)->bUintID = USBVIDEO_PU_ID;
	((USBVideo_PU_Dscr*)p_desc)->bSourceID = USBVIDEO_CT_ID;
	((USBVideo_PU_Dscr*)p_desc)->wMaxMultiplier[0] = 0;
	((USBVideo_PU_Dscr*)p_desc)->wMaxMultiplier[1] = 0;
	((USBVideo_PU_Dscr*)p_desc)->bControlSize = 0x2;

	map_size = sizeof(g_USBVideo_PU_Attr_Map)/sizeof(USBVideo_Attr_Map);
	for(attr_index = 0; attr_index < attr_size; attr_index++)
	{
		if(attr_info[attr_index].b_feature == KAL_TRUE)		//lint !e613
		{
			for(map_index = 0; map_index < map_size; map_index++)
			{
				if(g_USBVideo_PU_Attr_Map[map_index].attr_type == attr_info[attr_index].type)	//lint !e613
				{
					/* descriptor attr */
					pu_attr |= (1<<g_USBVideo_PU_Attr_Map[map_index].shift);

					/* Supported list */
					shift_index = (kal_uint32)attr_info[attr_index].type&(~0x80);	//lint !e613
					g_USBVideo.vc_pu_support |= (1<<shift_index);

					/* support set attribute list*/
					if(attr_info[attr_index].b_set == KAL_TRUE)	//lint !e613
					{
						g_USBVideo.vc_pu_set |= (1<<shift_index);
					}
				}
			}

			/* get attr in this descriptor*/
			if(attr_info[attr_index].type == USBVIDEO_ATTRIBUTE_MAX_MULTIPLIER)	//lint !e613
			{
				attr_value.type = USBVIDEO_ATTRIBUTE_MAX_MULTIPLIER;
				attr_value.req_type = USBVIDEO_REQUEST_GET_CUR;
//				g_USBVideo.camera_param->usbvideo_get_attr_value(&attr_value);
                    		CalFeatureCtrlStruct.FeatureCtrlCode = CAL_FEATURE_GET_OPERATION;
                    		CalFeatureCtrlStruct.FeatureId = CAL_FEATURE_WEBCAM_GET_ATTR;
                    		CalFeatureCtrlStruct.FeatureInfo.FeatureStructured.pWebCamAttr = &attr_value;
                    		CalCtrl(CAL_FEATURE_CTRL, &CalFeatureCtrlStruct, NULL, 0, NULL);

				((USBVideo_PU_Dscr*)p_desc)->wMaxMultiplier[0] = attr_value.value&0xff;
				((USBVideo_PU_Dscr*)p_desc)->wMaxMultiplier[1] = (attr_value.value>>8)&0xff;
			}
		}
	}
	((USBVideo_PU_Dscr*)p_desc)->bmControls[0] = pu_attr&0xff;
	((USBVideo_PU_Dscr*)p_desc)->bmControls[1] = (pu_attr>>8)&0xff;
	((USBVideo_PU_Dscr*)p_desc)->iProcessing = USB_Get_String_Number((void *)g_USBVideo.custom_param->vc_processing_unit_string);
	//((USBVideo_PU_Dscr*)p_desc)->bmVideoStandards	= 0;  /* for 1.1 revision */

	kal_mem_cpy(&g_USBVideo.vc_if_info->ifdscr.classif[if_desc_index ], p_desc, USBVIDEO_VC_PU_LENGTH);
	if_desc_index += USBVIDEO_VC_PU_LENGTH;
	free_ctrl_buffer(p_desc);

	if (if_desc_index > USB_MAX_IFDSC_LENGTH)
		ASSERT(0);

	/* endpoint handler*/
	USB_Register_Drv_Info(USB_DRV_HDLR_EP_TX, ep_id, USBVideo_IntrTx_Hdlr);
	g_USBVideo.vc_ep_intr_info->ep_reset = USBVideo_IntrTx_Reset;

	/* standard interrupt endpoint descriptor */
	p_desc = get_ctrl_buffer(sizeof(Usb_Ep_Dscr));
	((Usb_Ep_Dscr*)p_desc)->bLength = USB_EPDSC_LENGTH;
	((Usb_Ep_Dscr*)p_desc)->bDescriptorType = USB_ENDPOINT;
	((Usb_Ep_Dscr*)p_desc)->bEndpointAddress = (USB_EP_DIR_IN | ep_id);	/*InPipe*/
	((Usb_Ep_Dscr*)p_desc)->bmAttributes = USB_EP_INTR;
#ifdef __USB_HS_ENABLE__
	((Usb_Ep_Dscr*)p_desc)->wMaxPacketSize[0] = USB_EP_INTR_MAXP_FS&0xff;
//	((Usb_Ep_Dscr*)p_desc)->wMaxPacketSize[1] = (USB_EP_INTR_MAXP_FS>>8)&0xff;
	((Usb_Ep_Dscr*)p_desc)->wMaxPacketSize[1] = 0x00;
#else
	((Usb_Ep_Dscr*)p_desc)->wMaxPacketSize[0] = USB_EP_INTR_MAXP&0xff;
//	((Usb_Ep_Dscr*)p_desc)->wMaxPacketSize[1] = (USB_EP_INTR_MAXP>>8)&0xff;
	((Usb_Ep_Dscr*)p_desc)->wMaxPacketSize[1] = 0x00;
#endif
	((Usb_Ep_Dscr*)p_desc)->bInterval = 1;
	g_USBVideo.vc_ep_intr_info->ep_status.epin_status.byEP = ep_id;
	g_USBVideo.vc_ep_intr_info->ep_status.epin_status.nBytesLeft = USB_EP_NODATA;
	kal_mem_cpy(&g_USBVideo.vc_ep_intr_info->epdesc.classep[0], p_desc, USB_EPDSC_LENGTH);
	ep_desc_index = USB_EPDSC_LENGTH;
	free_ctrl_buffer(p_desc);

	/* class-specific interrupt endpoint descriptor */
	p_desc = get_ctrl_buffer(sizeof(USBVideo_Intr_Ep_Dscr));
	((USBVideo_Intr_Ep_Dscr*)p_desc)->bLength = USBVIDEO_VC_INTR_LENGTH;
	((USBVideo_Intr_Ep_Dscr*)p_desc)->bDescriptorType = USBVIDEO_CS_ENDPOINT;
	((USBVideo_Intr_Ep_Dscr*)p_desc)->bDescriptorSubType = USB_EP_INTR;
#ifdef __USB_HS_ENABLE__
	((USBVideo_Intr_Ep_Dscr*)p_desc)->wMaxTransferSize[0] = USB_EP_INTR_MAXP_FS&0xff;
//	((USBVideo_Intr_Ep_Dscr*)p_desc)->wMaxTransferSize[1] = (USB_EP_INTR_MAXP_FS>>8)&0xff;
	((USBVideo_Intr_Ep_Dscr*)p_desc)->wMaxTransferSize[1] = 0x00;
#else
	((USBVideo_Intr_Ep_Dscr*)p_desc)->wMaxTransferSize[0] = USB_EP_INTR_MAXP&0xff;
//	((USBVideo_Intr_Ep_Dscr*)p_desc)->wMaxTransferSize[1] = (USB_EP_INTR_MAXP>>8)&0xff;
	((USBVideo_Intr_Ep_Dscr*)p_desc)->wMaxTransferSize[1] = 0x00;
#endif
	kal_mem_cpy(&g_USBVideo.vc_ep_intr_info->epdesc.classep[ep_desc_index], p_desc, USBVIDEO_VC_INTR_LENGTH);
	ep_desc_index += USBVIDEO_VC_INTR_LENGTH;
	free_ctrl_buffer(p_desc);

	/* construct interface size */
	g_USBVideo.vc_if_info->ifdscr_size = if_desc_index;
	g_USBVideo.vc_ep_intr_info->epdscr_size = ep_desc_index;
}


/* video control interface reset function */
void USBVideo_VC_If_Reset(void)
{
	g_USBVideo.intrpipe = &g_USBVideo.vc_ep_intr_info->ep_status.epin_status;
}


/* video control interface enable function, enable interrupt endpoint */
void USBVideo_VC_If_Enable(void)
{
	/* Non-DMA */
	USB_TxEPEn(g_USBVideo.intrpipe->byEP, USB_ENDPT_INTR, USB_EP_USE_NO_DMA, KAL_TRUE, KAL_FALSE);
}


void USBVideo_VC_If_Speed_Reset(kal_bool b_other_speed)
{

}


/* video streaming interface create function, prepare descriptor */
void USBVideo_VS_If_Create(void *ifname)
{
	kal_uint8 ep_tx_id;
	kal_uint8 if_id;
	kal_uint8 video_size_num;
	kal_uint8 still_size_num;
	kal_uint8 compression_num;
	//kal_uint8 incall_jpeg_size_num;
	kal_uint32 index;
	kal_uint32 total_length;
	const USBVideo_Video_Size_Info *p_video_size_param;
	const USBVideo_Still_Size_Info *p_still_size_param;
	const USBVideo_Compression_Info *p_compression_param;
	kal_uint8* p_desc;
	kal_uint32 if_desc_index = 0;
	kal_uint32 max_frame_size;

//	p_video_size_param = g_USBVideo.camera_param->usbvideo_get_video_size_info(&video_size_num);
        CalFeatureCtrlStruct.FeatureCtrlCode = CAL_FEATURE_GET_OPERATION;
        CalFeatureCtrlStruct.FeatureId = CAL_FEATURE_WEBCAM_GET_VIDEO_SIZE;
        CalFeatureCtrlStruct.FeatureInfo.FeatureStructured.pWebCamVideoSize = &UsbvideoVideoSize;
        CalCtrl(CAL_FEATURE_CTRL, &CalFeatureCtrlStruct, NULL, 0, NULL);
        p_video_size_param = UsbvideoVideoSize.pWebCamVideoSizeInfo;
        video_size_num = UsbvideoVideoSize.WebCamVideoSizeInfoNum;
//	p_still_size_param = g_USBVideo.camera_param->usbvideo_get_still_size_info(&still_size_num);
        CalFeatureCtrlStruct.FeatureCtrlCode = CAL_FEATURE_GET_OPERATION;
        CalFeatureCtrlStruct.FeatureId = CAL_FEATURE_WEBCAM_GET_STILL_SIZE;
        CalFeatureCtrlStruct.FeatureInfo.FeatureStructured.pWebCamStillSize = &UsbvideoStillSize;
        CalCtrl(CAL_FEATURE_CTRL, &CalFeatureCtrlStruct, NULL, 0, NULL);
        p_still_size_param = UsbvideoStillSize.pWebCamStillSizeInfo;
        still_size_num = UsbvideoStillSize.WebCamStillSizeInfoNum;
//	p_compression_param = g_USBVideo.camera_param->usbvideo_get_compression_info(&compression_num); 
       CalFeatureCtrlStruct.FeatureCtrlCode = CAL_FEATURE_GET_OPERATION;
        CalFeatureCtrlStruct.FeatureId = CAL_FEATURE_WEBCAM_GET_COMPRESSION;
        CalFeatureCtrlStruct.FeatureInfo.FeatureStructured.pWebCamCompression = &UsbvideoCompression;
        CalCtrl(CAL_FEATURE_CTRL, &CalFeatureCtrlStruct, NULL, 0, NULL);
        p_compression_param = UsbvideoCompression.pWebCamCompressionInfo;
        compression_num = UsbvideoCompression.WebCamCompressionInfoNum;

	g_USBVideo.video_control.p_video_size_info = p_video_size_param;
	g_USBVideo.video_control.video_size_num = video_size_num;
	g_USBVideo.video_control.p_still_size_info = p_still_size_param;
	g_USBVideo.video_control.still_size_num = still_size_num;

	/* check the sequence index, following design should have this assumption  */
	for(index = 0; index < video_size_num; index++)
	{
		if((kal_uint32)p_video_size_param[index].type != (index + 1))
			EXT_ASSERT(0, index, (kal_uint32)p_video_size_param[index].type, 0);
	}

	for(index = 0; index < still_size_num; index++)
	{
		if((kal_uint32)p_still_size_param[index].type != (index + 1))
			EXT_ASSERT(0, index, (kal_uint32)p_still_size_param[index].type, 0);
	}

	for(index = 0; index < compression_num; index++)
	{
		if((kal_uint32)p_compression_param[index].type != (index + 1))
			EXT_ASSERT(0, index, (kal_uint32)p_compression_param[index].type, 0);
	}

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
#endif

	/* get resource number and register to gUsbDevice */
	g_USBVideo.vs_if_info = USB_Get_Interface_Number(&if_id);
	g_USBVideo.vs_interface_id = if_id;

#ifdef  __WEBCAM_SUPPORT_ISO_PIPE__
	g_USBVideo.vs_if_alter_info = USB_Get_Interface_Alternate_Setting(if_id);

	g_USBVideo.vs_ep_tx_info = USB_Get_Iso_Tx_Ep(&ep_tx_id);
#else
	g_USBVideo.vs_ep_tx_info = USB_Get_Bulk_Tx_Ep(&ep_tx_id);
#endif

	/* record interface name and interface descriptor length */
	g_USBVideo.vs_if_info->interface_name_ptr = (kal_char *)ifname;
	g_USBVideo.vs_if_info->ifdscr_size = 0; /* Will be modified after the following attribute parts*/

	/* related endpoint info and class specific command handler*/
	g_USBVideo.vs_if_info->ep_info[0] = g_USBVideo.vs_ep_tx_info;
	g_USBVideo.vs_if_info->if_class_specific_hdlr = USBVideo_Ep0_VS_Command;

	/* standard interface descriptor */
	p_desc = get_ctrl_buffer(sizeof(Usb_If_Dscr));
	((Usb_If_Dscr*)p_desc)->bLength = USB_IFDSC_LENGTH;
	((Usb_If_Dscr*)p_desc)->bDescriptorType = USB_INTERFACE;
	((Usb_If_Dscr*)p_desc)->bInterfaceNumber = if_id;
	((Usb_If_Dscr*)p_desc)->bAlternateSetting = 0;
#ifdef  __WEBCAM_SUPPORT_ISO_PIPE__
	((Usb_If_Dscr*)p_desc)->bNumEndpoints = 0;
#else
	((Usb_If_Dscr*)p_desc)->bNumEndpoints = USBVIDEO_VS_EP_NUMBER;
#endif
	((Usb_If_Dscr*)p_desc)->bInterfaceClass = USBVIDEO_CC_VIDEO;
	((Usb_If_Dscr*)p_desc)->bInterfaceSubClass = USBVIDEO_SC_VIDEOSTREAMING;
	((Usb_If_Dscr*)p_desc)->bInterfaceProtocol = USBVIDEO_PC_PROTOCOL_UNDEFINED;
	((Usb_If_Dscr*)p_desc)->iInterface = USB_Get_String_Number((void *)g_USBVideo.custom_param->vs_interface_string);
	kal_mem_cpy(&g_USBVideo.vs_if_info->ifdscr.classif[if_desc_index ], p_desc, USB_IFDSC_LENGTH);
	if_desc_index += USB_IFDSC_LENGTH;
	free_ctrl_buffer(p_desc);

	/* class specific VS interface descriptor, input header descriptor */
	p_desc = get_ctrl_buffer(sizeof(USBVideo_Class_VS_If_Dscr));
	((USBVideo_Class_VS_If_Dscr*)p_desc)->bLength = USBVIDEO_VS_INTERFACE_LENGTH;
	((USBVideo_Class_VS_If_Dscr*)p_desc)->bDescriptorType = USBVIDEO_CS_INTERFACE;
	((USBVideo_Class_VS_If_Dscr*)p_desc)->bDescriptorSubType = USBVIDEO_VS_INPUT_HEADER;
	((USBVideo_Class_VS_If_Dscr*)p_desc)->bNumFormats = 0x01; /* one format descriptor for MJPEG*/
	total_length = sizeof(USBVideo_Class_VS_If_Dscr)+sizeof(USBVideo_MJPEG_Format_Dscr)
				+(video_size_num*sizeof(USBVideo_MJPEG_Frame_Dscr))
				+USBVIDEO_VS_STILL_LENGTH + (sizeof(USBVideo_Still_Size)*still_size_num) + (sizeof(kal_uint8)*compression_num)
				+sizeof(USBVideo_Color_Dscr);
	((USBVideo_Class_VS_If_Dscr*)p_desc)->wTotalLength[0] = total_length&0xff;
	((USBVideo_Class_VS_If_Dscr*)p_desc)->wTotalLength[1] = (total_length>>8)&0xff;
	((USBVideo_Class_VS_If_Dscr*)p_desc)->bEndpointAddress = (USB_EP_DIR_IN|ep_tx_id);   /*InPipe*/
	((USBVideo_Class_VS_If_Dscr*)p_desc)->bmInfo = 0; /* No dynamic format change support */
	((USBVideo_Class_VS_If_Dscr*)p_desc)->bTerminalLink = USBVIDEO_OT_ID;
	((USBVideo_Class_VS_If_Dscr*)p_desc)->bStillCaptureMethod = USBVIDEO_STILL_CAPTURE_METHOD_2;
#ifdef __USBVIDEO_DEVICE_TRIGGER_SUPPORT__
	((USBVideo_Class_VS_If_Dscr*)p_desc)->bTriggerSupport = USBVIDEO_HARDWARE_TRIGGER_SUPPORT;
	((USBVideo_Class_VS_If_Dscr*)p_desc)->bTriggerUsage = USBVIDEO_HARDWARE_TRIGGER_STILL;
#else
	((USBVideo_Class_VS_If_Dscr*)p_desc)->bTriggerSupport = USBVIDEO_HARDWARE_TRIGGER_NOT_SUPPORT;
	((USBVideo_Class_VS_If_Dscr*)p_desc)->bTriggerUsage = 0;
#endif
	((USBVideo_Class_VS_If_Dscr*)p_desc)->bControlSize = 1;
	((USBVideo_Class_VS_If_Dscr*)p_desc)->bmaControls = 0;
	kal_mem_cpy(&g_USBVideo.vs_if_info->ifdscr.classif[if_desc_index], p_desc, USBVIDEO_VS_INTERFACE_LENGTH);
	if_desc_index +=USBVIDEO_VS_INTERFACE_LENGTH;
	free_ctrl_buffer(p_desc);

	/* MJPEG video format descriptor */
	p_desc = get_ctrl_buffer(sizeof(USBVideo_MJPEG_Format_Dscr));
	((USBVideo_MJPEG_Format_Dscr*)p_desc)->bLength = USBVIDEO_VS_MJPEG_FORMAT_LENGTH;
	((USBVideo_MJPEG_Format_Dscr*)p_desc)->bDescriptorType = USBVIDEO_CS_INTERFACE;
	((USBVideo_MJPEG_Format_Dscr*)p_desc)->bDescriptorSubType = USBVIDEO_VS_FORMAT_MJPEG;
	((USBVideo_MJPEG_Format_Dscr*)p_desc)->bFormatIndex = 1;
	((USBVideo_MJPEG_Format_Dscr*)p_desc)->bNumFrameDescriptors = video_size_num;
	((USBVideo_MJPEG_Format_Dscr*)p_desc)->bmFlags = USBVIDEO_FIXED_SIZE_SAMPLES;
//	((USBVideo_MJPEG_Format_Dscr*)p_desc)->bDefaultFrameIndex = (kal_uint8)g_USBVideo.camera_param->usbvideo_get_default_video_index();
	((USBVideo_MJPEG_Format_Dscr*)p_desc)->bDefaultFrameIndex = UsbvideoDeafultIdx.WebCamVideoSizeIdx;
	((USBVideo_MJPEG_Format_Dscr*)p_desc)->bAspectRatioX = 0;
	((USBVideo_MJPEG_Format_Dscr*)p_desc)->bAspectRatioY = 0;
	((USBVideo_MJPEG_Format_Dscr*)p_desc)->bmInterlaceFlags = 0;
	((USBVideo_MJPEG_Format_Dscr*)p_desc)->bCopyProtect = 0;
	kal_mem_cpy(&g_USBVideo.vs_if_info->ifdscr.classif[if_desc_index], p_desc, USBVIDEO_VS_MJPEG_FORMAT_LENGTH);
	if_desc_index += USBVIDEO_VS_MJPEG_FORMAT_LENGTH;
	free_ctrl_buffer(p_desc);

	/* MJPEG frame descriptor */
	p_desc = get_ctrl_buffer(sizeof(USBVideo_MJPEG_Frame_Dscr)*video_size_num);
	for(index = 0; index < video_size_num; index++)
	{
		((USBVideo_MJPEG_Frame_Dscr*)p_desc)[index].bLength = USBVIDEO_VS_MJPEG_FRAME_LENGTH;
		((USBVideo_MJPEG_Frame_Dscr*)p_desc)[index].bDescriptorType = USBVIDEO_CS_INTERFACE;
		((USBVideo_MJPEG_Frame_Dscr*)p_desc)[index].bDescriptorSubType = USBVIDEO_VS_FRAME_MJPEG;
		((USBVideo_MJPEG_Frame_Dscr*)p_desc)[index].bFrameIndex = (kal_uint8)p_video_size_param[index].type;
		((USBVideo_MJPEG_Frame_Dscr*)p_desc)[index].bmCapabilities = 0;
		((USBVideo_MJPEG_Frame_Dscr*)p_desc)[index].wWidth[0] = p_video_size_param[index].width&0xff;
		((USBVideo_MJPEG_Frame_Dscr*)p_desc)[index].wWidth[1] = (p_video_size_param[index].width>>8)&0xff;
		((USBVideo_MJPEG_Frame_Dscr*)p_desc)[index].wHeight[0] = p_video_size_param[index].height&0xff;
		((USBVideo_MJPEG_Frame_Dscr*)p_desc)[index].wHeight[1] = (p_video_size_param[index].height>>8)&0xff;
		((USBVideo_MJPEG_Frame_Dscr*)p_desc)[index].dwMinBitRate[0] = p_video_size_param[index].min_bit_rate&0xff;
		((USBVideo_MJPEG_Frame_Dscr*)p_desc)[index].dwMinBitRate[1] = (p_video_size_param[index].min_bit_rate>>8)&0xff;
		((USBVideo_MJPEG_Frame_Dscr*)p_desc)[index].dwMinBitRate[2] = (p_video_size_param[index].min_bit_rate>>16)&0xff;
		((USBVideo_MJPEG_Frame_Dscr*)p_desc)[index].dwMinBitRate[3] = (p_video_size_param[index].min_bit_rate>>24)&0xff;
		((USBVideo_MJPEG_Frame_Dscr*)p_desc)[index].dwMaxBitRate[0] = p_video_size_param[index].max_bit_rate&0xff;
		((USBVideo_MJPEG_Frame_Dscr*)p_desc)[index].dwMaxBitRate[1] = (p_video_size_param[index].max_bit_rate>>8)&0xff;
		((USBVideo_MJPEG_Frame_Dscr*)p_desc)[index].dwMaxBitRate[2] = (p_video_size_param[index].max_bit_rate>>16)&0xff;
		((USBVideo_MJPEG_Frame_Dscr*)p_desc)[index].dwMaxBitRate[3] = (p_video_size_param[index].max_bit_rate>>24)&0xff;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
		if(g_USBVideo.video_control.b_set_default_jpeg_max_size[index]==KAL_FALSE)
			EXT_ASSERT(0, index, 0, 0);
		max_frame_size = USBVideo_Get_Max(p_video_size_param[index].max_frame_size,
												g_USBVideo.video_control.default_jpeg_max_size[index]);
		((USBVideo_MJPEG_Frame_Dscr*)p_desc)[index].dwMaxVideoFrameBufferSize[0] = max_frame_size&0xff;
		((USBVideo_MJPEG_Frame_Dscr*)p_desc)[index].dwMaxVideoFrameBufferSize[1] = (max_frame_size>>8)&0xff;
		((USBVideo_MJPEG_Frame_Dscr*)p_desc)[index].dwMaxVideoFrameBufferSize[2] = (max_frame_size>>16)&0xff;
		((USBVideo_MJPEG_Frame_Dscr*)p_desc)[index].dwMaxVideoFrameBufferSize[3] = (max_frame_size>>24)&0xff;
		((USBVideo_MJPEG_Frame_Dscr*)p_desc)[index].dwDefaultFrameInterval[0] = p_video_size_param[index].default_frame_interval&0xff;
		((USBVideo_MJPEG_Frame_Dscr*)p_desc)[index].dwDefaultFrameInterval[1] = (p_video_size_param[index].default_frame_interval>>8)&0xff;
		((USBVideo_MJPEG_Frame_Dscr*)p_desc)[index].dwDefaultFrameInterval[2] = (p_video_size_param[index].default_frame_interval>>16)&0xff;
		((USBVideo_MJPEG_Frame_Dscr*)p_desc)[index].dwDefaultFrameInterval[3] = (p_video_size_param[index].default_frame_interval>>24)&0xff;
		((USBVideo_MJPEG_Frame_Dscr*)p_desc)[index].bFrameIntervalType = 0;
		((USBVideo_MJPEG_Frame_Dscr*)p_desc)[index].dwMinFrameInterval[0] = p_video_size_param[index].min_frame_interval&0xff;
		((USBVideo_MJPEG_Frame_Dscr*)p_desc)[index].dwMinFrameInterval[1] = (p_video_size_param[index].min_frame_interval>>8)&0xff;
		((USBVideo_MJPEG_Frame_Dscr*)p_desc)[index].dwMinFrameInterval[2] = (p_video_size_param[index].min_frame_interval>>16)&0xff;
		((USBVideo_MJPEG_Frame_Dscr*)p_desc)[index].dwMinFrameInterval[3] = (p_video_size_param[index].min_frame_interval>>24)&0xff;
		((USBVideo_MJPEG_Frame_Dscr*)p_desc)[index].dwMaxFrameInterval[0] = p_video_size_param[index].max_frame_interval&0xff;
		((USBVideo_MJPEG_Frame_Dscr*)p_desc)[index].dwMaxFrameInterval[1] = (p_video_size_param[index].max_frame_interval>>8)&0xff;
		((USBVideo_MJPEG_Frame_Dscr*)p_desc)[index].dwMaxFrameInterval[2] = (p_video_size_param[index].max_frame_interval>>16)&0xff;
		((USBVideo_MJPEG_Frame_Dscr*)p_desc)[index].dwMaxFrameInterval[3] = (p_video_size_param[index].max_frame_interval>>24)&0xff;
		((USBVideo_MJPEG_Frame_Dscr*)p_desc)[index].dwFrameIntervalStep[0] = p_video_size_param[index].frame_interval_step&0xff;
		((USBVideo_MJPEG_Frame_Dscr*)p_desc)[index].dwFrameIntervalStep[1] = (p_video_size_param[index].frame_interval_step>>8)&0xff;
		((USBVideo_MJPEG_Frame_Dscr*)p_desc)[index].dwFrameIntervalStep[2] = (p_video_size_param[index].frame_interval_step>>16)&0xff;
		((USBVideo_MJPEG_Frame_Dscr*)p_desc)[index].dwFrameIntervalStep[3] = (p_video_size_param[index].frame_interval_step>>24)&0xff;
		kal_mem_cpy(&g_USBVideo.vs_if_info->ifdscr.classif[if_desc_index], &((USBVideo_MJPEG_Frame_Dscr*)p_desc)[index], USBVIDEO_VS_MJPEG_FRAME_LENGTH);
		if_desc_index +=USBVIDEO_VS_MJPEG_FRAME_LENGTH;
	}
	free_ctrl_buffer(p_desc);

	/* still image frame descriptor */
	p_desc = get_ctrl_buffer(sizeof(USBVideo_Still_Frame_Dscr));
	((USBVideo_Still_Frame_Dscr*)p_desc)->bLength =
				USBVIDEO_VS_STILL_LENGTH + (sizeof(USBVideo_Still_Size)*still_size_num) + (sizeof(kal_uint8)*compression_num);
	((USBVideo_Still_Frame_Dscr*)p_desc)->bDescriptorType = USBVIDEO_CS_INTERFACE;
	((USBVideo_Still_Frame_Dscr*)p_desc)->bDescriptorSubType = USBVIDEO_VS_STILL_IMAGE_FRAME;
	((USBVideo_Still_Frame_Dscr*)p_desc)->bEndpointAddress = 0;   /*for method 2*/
	((USBVideo_Still_Frame_Dscr*)p_desc)->bNumImageSizePatterns = still_size_num;
	((USBVideo_Still_Frame_Dscr*)p_desc)->bNumCompressionPattern = compression_num;
	((USBVideo_Still_Frame_Dscr*)p_desc)->p_image_patterns = (USBVideo_Still_Size *)get_ctrl_buffer(sizeof(USBVideo_Still_Size)*still_size_num);
	((USBVideo_Still_Frame_Dscr*)p_desc)->p_compression_patterns =  (kal_uint8 *)get_ctrl_buffer(sizeof(kal_uint8)*compression_num);
	for(index = 0; index < still_size_num; index++)
	{
		((USBVideo_Still_Frame_Dscr*)p_desc)->p_image_patterns[index].wWidth[0] = p_still_size_param[index].width&0xff;
		((USBVideo_Still_Frame_Dscr*)p_desc)->p_image_patterns[index].wWidth[1] = (p_still_size_param[index].width>>8)&0xff;
		((USBVideo_Still_Frame_Dscr*)p_desc)->p_image_patterns[index].wHeight[0] = p_still_size_param[index].height&0xff;
		((USBVideo_Still_Frame_Dscr*)p_desc)->p_image_patterns[index].wHeight[1] = (p_still_size_param[index].height>>8)&0xff;
	}
	for(index = 0; index < compression_num; index++)
	{
		((USBVideo_Still_Frame_Dscr*)p_desc)->p_compression_patterns[index] = p_compression_param[index].compression;
	}
	g_USBVideo.vs_if_info->ifdscr.classif[if_desc_index] = ((USBVideo_Still_Frame_Dscr*)p_desc)->bLength;
	g_USBVideo.vs_if_info->ifdscr.classif[if_desc_index+1] = ((USBVideo_Still_Frame_Dscr*)p_desc)->bDescriptorType;
	g_USBVideo.vs_if_info->ifdscr.classif[if_desc_index+2] = ((USBVideo_Still_Frame_Dscr*)p_desc)->bDescriptorSubType;
	g_USBVideo.vs_if_info->ifdscr.classif[if_desc_index+3] = ((USBVideo_Still_Frame_Dscr*)p_desc)->bEndpointAddress;
	g_USBVideo.vs_if_info->ifdscr.classif[if_desc_index+4] = ((USBVideo_Still_Frame_Dscr*)p_desc)->bNumImageSizePatterns;
	if_desc_index+=5;
	kal_mem_cpy(&g_USBVideo.vs_if_info->ifdscr.classif[if_desc_index], ((USBVideo_Still_Frame_Dscr*)p_desc)->p_image_patterns, sizeof(USBVideo_Still_Size)*still_size_num);
	if_desc_index +=(sizeof(USBVideo_Still_Size)*still_size_num);
	g_USBVideo.vs_if_info->ifdscr.classif[if_desc_index] = ((USBVideo_Still_Frame_Dscr*)p_desc)->bNumCompressionPattern;
	if_desc_index+=1;
	kal_mem_cpy(&g_USBVideo.vs_if_info->ifdscr.classif[if_desc_index], ((USBVideo_Still_Frame_Dscr*)p_desc)->p_compression_patterns, sizeof(kal_uint8)*compression_num);
	if_desc_index +=(sizeof(kal_uint8)*compression_num);
	free_ctrl_buffer(((USBVideo_Still_Frame_Dscr*)p_desc)->p_image_patterns);
	free_ctrl_buffer(((USBVideo_Still_Frame_Dscr*)p_desc)->p_compression_patterns);
	free_ctrl_buffer(p_desc);	/* should be freed last one */

	/* Color matching descriptor */
	p_desc = get_ctrl_buffer(sizeof(USBVideo_Color_Dscr));
	((USBVideo_Color_Dscr*)p_desc)->bLength = USBVIDEO_VS_COLOR_MATCHING_LENGTH;
	((USBVideo_Color_Dscr*)p_desc)->bDescriptorType = USBVIDEO_CS_INTERFACE;
	((USBVideo_Color_Dscr*)p_desc)->bDescriptorSubType = USBVIDEO_VS_COLORFORMAT;
	((USBVideo_Color_Dscr*)p_desc)->bColorPrimaries = 0;
	((USBVideo_Color_Dscr*)p_desc)->bTransferCharacteristics = 0;
	((USBVideo_Color_Dscr*)p_desc)->bMatrixCoefficients = 0;
	kal_mem_cpy(&g_USBVideo.vs_if_info->ifdscr.classif[if_desc_index], p_desc, USBVIDEO_VS_COLOR_MATCHING_LENGTH);
	if_desc_index += USBVIDEO_VS_COLOR_MATCHING_LENGTH;
	free_ctrl_buffer(p_desc);

	if (if_desc_index > USB_MAX_IFDSC_LENGTH)
		ASSERT(0);

#ifdef  __WEBCAM_SUPPORT_ISO_PIPE__
	g_USBVideo.vs_if_alter_info->ifdscr_size = USB_IFDSC_LENGTH;
	g_USBVideo.vs_if_alter_info->ep_info[0] = g_USBVideo.vs_ep_tx_info;
	/* Alternate interface setting descriptor */
	g_USBVideo.vs_if_alter_info->stdif.bLength = USB_IFDSC_LENGTH;
	g_USBVideo.vs_if_alter_info->stdif.bDescriptorType = USB_INTERFACE;
	g_USBVideo.vs_if_alter_info->stdif.bInterfaceNumber = if_id;
	g_USBVideo.vs_if_alter_info->stdif.bAlternateSetting = 0x01;
	g_USBVideo.vs_if_alter_info->stdif.bNumEndpoints = USBVIDEO_VS_EP_NUMBER;
	g_USBVideo.vs_if_alter_info->stdif.bInterfaceClass = USBVIDEO_CC_VIDEO;
	g_USBVideo.vs_if_alter_info->stdif.bInterfaceSubClass = USBVIDEO_SC_VIDEOSTREAMING;
	g_USBVideo.vs_if_alter_info->stdif.bInterfaceProtocol = USBVIDEO_PC_PROTOCOL_UNDEFINED;
//	g_USBVideo.vs_if_alter_info->stdif.iInterface = USB_Get_String_Number((void *)g_USBVideo.custom_param->vs_interface_string);
	g_USBVideo.vs_if_alter_info->stdif.iInterface = 0x0;
#endif  /* #ifdef  __WEBCAM_SUPPORT_ISO_PIPE__ */

	/* endpoint handler */
	USB_Register_Drv_Info(USB_DRV_HDLR_EP_TX, ep_tx_id, NULL);
#ifdef  __WEBCAM_SUPPORT_ISO_PIPE__
	g_USBVideo.vs_ep_tx_info->ep_reset = USBVideo_IsoTx_Reset;
#else  /* __WEBCAM_SUPPORT_ISO_PIPE__ */
	g_USBVideo.vs_ep_tx_info->ep_reset = USBVideo_BulkTx_Reset;
#endif

	/* endpoint descriptor */
#ifdef  __WEBCAM_SUPPORT_ISO_PIPE__
	g_USBVideo.vs_ep_tx_info->epdesc.stdep.bLength = USB_EPDSC_LENGTH;
	g_USBVideo.vs_ep_tx_info->epdesc.stdep.bDescriptorType = USB_ENDPOINT;
	g_USBVideo.vs_ep_tx_info->epdesc.stdep.bEndpointAddress = (USB_EP_DIR_IN|ep_tx_id);
	g_USBVideo.vs_ep_tx_info->epdesc.stdep.bmAttributes = USB_EP_ISO|(USB_ISO_ASYNCHRONOUS<<2);
#ifndef __USB_HS_ENABLE__
	g_USBVideo.vs_ep_tx_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_ISO_MAXP&0xff;
	g_USBVideo.vs_ep_tx_info->epdesc.stdep.wMaxPacketSize[1] = (USB_EP_ISO_MAXP>>8)&0xff;
#endif
	g_USBVideo.vs_ep_tx_info->epdesc.stdep.bInterval = 1;
	g_USBVideo.vs_ep_tx_info->ep_status.epin_status.byEP = ep_tx_id;
	g_USBVideo.vs_ep_tx_info->ep_status.epin_status.nBytesLeft = USB_EP_NODATA;

#else  /* __WEBCAM_SUPPORT_ISO_PIPE__ */
	g_USBVideo.vs_ep_tx_info->epdesc.stdep.bLength = USB_EPDSC_LENGTH;
	g_USBVideo.vs_ep_tx_info->epdesc.stdep.bDescriptorType = USB_ENDPOINT;
	g_USBVideo.vs_ep_tx_info->epdesc.stdep.bEndpointAddress = (USB_EP_DIR_IN|ep_tx_id);
	g_USBVideo.vs_ep_tx_info->epdesc.stdep.bmAttributes = USB_EP_BULK;
#ifndef __USB_HS_ENABLE__
	g_USBVideo.vs_ep_tx_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_BULK_MAXP&0xff;
//	g_USBVideo.vs_ep_tx_info->epdesc.stdep.wMaxPacketSize[1] = (USB_EP_BULK_MAXP>>8)&0xff;
	g_USBVideo.vs_ep_tx_info->epdesc.stdep.wMaxPacketSize[1] = 0x00;
#endif
	g_USBVideo.vs_ep_tx_info->epdesc.stdep.bInterval = 0;
	g_USBVideo.vs_ep_tx_info->ep_status.epin_status.byEP = ep_tx_id;
	g_USBVideo.vs_ep_tx_info->ep_status.epin_status.nBytesLeft = USB_EP_NODATA;

#endif  /* __WEBCAM_SUPPORT_ISO_PIPE__ */

	USB_Get_DMA_Channel(ep_tx_id, 0, USB_EP_TX_DIR, KAL_FALSE);

	/* construct interface size */
	g_USBVideo.vs_if_info->ifdscr_size = if_desc_index;
	g_USBVideo.vs_ep_tx_info->epdscr_size = USB_EPDSC_LENGTH;

	/* construct video probe and control setting */
	/* assign default value first, may be changed in the probe and commit flow */
	//index = (kal_uint32)g_USBVideo.camera_param->usbvideo_get_default_video_index(); 
	index = UsbvideoDeafultIdx.WebCamVideoSizeIdx;
	g_USBVideo.vs_probe_control.bmHint[0] = 0;
	g_USBVideo.vs_probe_control.bmHint[1] = 0;
	g_USBVideo.vs_probe_control.bFormatIndex = 1;  /* only one MJPEG format */
	g_USBVideo.vs_probe_control.bFrameIndex = index;
	g_USBVideo.vs_probe_control.dwFrameInterval[0] = p_video_size_param[index-1].default_frame_interval&0xff;
	g_USBVideo.vs_probe_control.dwFrameInterval[1] = (p_video_size_param[index-1].default_frame_interval>>8)&0xff;
	g_USBVideo.vs_probe_control.dwFrameInterval[2] = (p_video_size_param[index-1].default_frame_interval>>16)&0xff;
	g_USBVideo.vs_probe_control.dwFrameInterval[3] = (p_video_size_param[index-1].default_frame_interval>>24)&0xff;
	g_USBVideo.vs_probe_control.wKeyFrameRate[0] = 1;
	g_USBVideo.vs_probe_control.wKeyFrameRate[1] = 0;
	g_USBVideo.vs_probe_control.wPFrameRate[0] = 0;
	g_USBVideo.vs_probe_control.wPFrameRate[1] = 0;
	g_USBVideo.vs_probe_control.wCompQuality[0] = 0;
	g_USBVideo.vs_probe_control.wCompQuality[1] = 0;
	g_USBVideo.vs_probe_control.wCompWindowSize[0] = 0;
	g_USBVideo.vs_probe_control.wCompWindowSize[1] = 0;
	g_USBVideo.vs_probe_control.wDelay[0] = 0;
	g_USBVideo.vs_probe_control.wDelay[1] = 0;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	max_frame_size = USBVideo_Get_Max(p_video_size_param[index-1].max_frame_size,
												g_USBVideo.video_control.default_jpeg_max_size[index-1]);
	g_USBVideo.vs_probe_control.dwMaxVideoFrameSize[0] = max_frame_size&0xff;
	g_USBVideo.vs_probe_control.dwMaxVideoFrameSize[1] = (max_frame_size>>8)&0xff;
	g_USBVideo.vs_probe_control.dwMaxVideoFrameSize[2] = (max_frame_size>>16)&0xff;
	g_USBVideo.vs_probe_control.dwMaxVideoFrameSize[3] = (max_frame_size>>24)&0xff;
	g_USBVideo.vs_probe_control.dwMaxPayloadTransferSize[0] = USBVIDEO_MAX_PAYLOAD_LENGTH&0xff;
	g_USBVideo.vs_probe_control.dwMaxPayloadTransferSize[1] = (USBVIDEO_MAX_PAYLOAD_LENGTH>>8)&0xff;
//	g_USBVideo.vs_probe_control.dwMaxPayloadTransferSize[2] = (USBVIDEO_MAX_PAYLOAD_LENGTH>>16)&0xff;
//	g_USBVideo.vs_probe_control.dwMaxPayloadTransferSize[3] = (USBVIDEO_MAX_PAYLOAD_LENGTH>>24)&0xff;
	g_USBVideo.vs_probe_control.dwMaxPayloadTransferSize[2] = 0x00;
	g_USBVideo.vs_probe_control.dwMaxPayloadTransferSize[3] = 0x00;
	/* for 1.1 version */
	/*
	g_USBVideo.vs_probe_control.dwClockFrequency[0] = USBVIDEO_CLOCK_FREQUENCY&0xff;
	g_USBVideo.vs_probe_control.dwClockFrequency[1] = (USBVIDEO_CLOCK_FREQUENCY>>8)&0xff;
	g_USBVideo.vs_probe_control.dwClockFrequency[2] = (USBVIDEO_CLOCK_FREQUENCY>>16)&0xff;
	g_USBVideo.vs_probe_control.dwClockFrequency[3] = (USBVIDEO_CLOCK_FREQUENCY>>24)&0xff;
	g_USBVideo.vs_probe_control.bmFramingInfo = 0;
	g_USBVideo.vs_probe_control.bPreferedVersion = 1;
	g_USBVideo.vs_probe_control.bMinVersion = 0;
	g_USBVideo.vs_probe_control.bMaxVersion = 1;
	*/

	/* construct still probe and control setting */
	/* assign default value first, may be changed in the probe and commit flow */
	//index = (kal_uint32)g_USBVideo.camera_param->usbvideo_get_default_still_index();
	index = UsbvideoDeafultIdx.WebCamStillSizeIdx;
	g_USBVideo.vs_still_probe_control.bFormatIndex = 1;
	g_USBVideo.vs_still_probe_control.bFrameIndex = (kal_uint8)index;
	//g_USBVideo.vs_still_probe_control.bCompressionIndex = (kal_uint8)g_USBVideo.camera_param->usbvideo_get_default_compression_index();
	g_USBVideo.vs_still_probe_control.bCompressionIndex = UsbvideoDeafultIdx.WebCamCompressionIdx;


	g_USBVideo.vs_still_probe_control.dwMaxVideoFrameSize[0] = p_still_size_param[index-1].max_frame_size&0xff;
	g_USBVideo.vs_still_probe_control.dwMaxVideoFrameSize[1] = (p_still_size_param[index-1].max_frame_size>>8)&0xff;
	g_USBVideo.vs_still_probe_control.dwMaxVideoFrameSize[2] = (p_still_size_param[index-1].max_frame_size>>16)&0xff;
	g_USBVideo.vs_still_probe_control.dwMaxVideoFrameSize[3] = (p_still_size_param[index-1].max_frame_size>>24)&0xff;
	g_USBVideo.vs_still_probe_control.dwMaxPayloadTransferSize[0] = USBVIDEO_MAX_PAYLOAD_LENGTH&0xff;
	g_USBVideo.vs_still_probe_control.dwMaxPayloadTransferSize[1] = (USBVIDEO_MAX_PAYLOAD_LENGTH>>8)&0xff;
//	g_USBVideo.vs_still_probe_control.dwMaxPayloadTransferSize[2] = (USBVIDEO_MAX_PAYLOAD_LENGTH>>16)&0xff;
//	g_USBVideo.vs_still_probe_control.dwMaxPayloadTransferSize[3] = (USBVIDEO_MAX_PAYLOAD_LENGTH>>24)&0xff;
	g_USBVideo.vs_still_probe_control.dwMaxPayloadTransferSize[2] = 0x00;
	g_USBVideo.vs_still_probe_control.dwMaxPayloadTransferSize[3] = 0x00;

	/* register class-specific handler for standard ep0 cmd */
#ifdef  __WEBCAM_SUPPORT_ISO_PIPE__
	USB_Register_EP0_Class_CmdHdlr(USB_SET_INTERFACE, USBVideo_SetInterface_Callback);
#else
	USB_Register_EP0_Class_CmdHdlr(USB_CLEAR_FEATURE, USBVideo_ClearFeature_Callback);
#endif
}


/* video streaming interface reset function, enable EP*/
void USBVideo_VS_If_Reset(void)
{
	g_USBVideo.txpipe = &g_USBVideo.vs_ep_tx_info->ep_status.epin_status;

	if(g_USBVideo.state!=USBVIDEO_STATE_STOP)
	{
		/* No plug out, but reset */
		/* stop DMA if it is on */
		if(USB_DMA_Get_Run_Status(g_USBVideo.txpipe->byEP, USB_EP_TX_DIR) == KAL_TRUE)
		{
			/* Stop DMA will clear run status */
			USB_Stop_DMA_Channel(g_USBVideo.txpipe->byEP, USB_EP_TX_DIR);

#ifdef  __WEBCAM_SUPPORT_ISO_PIPE__
			/* Clear FIFO, if not clear it, the next packet may be false */
			USB_Clear_Tx_EP_FIFO(g_USBVideo.txpipe->byEP, USB_ENDPT_ISO, KAL_TRUE);
#else
			/* Clear FIFO, if not clear it, the next packet may be false */
			USB_Clear_Tx_EP_FIFO(g_USBVideo.txpipe->byEP, USB_ENDPT_BULK, KAL_TRUE);
#endif
			/* Clear dma running state here */
//			USB_DMA_Set_Run_Status(g_USBVideo.txpipe->byEP, USB_EP_TX_DIR, KAL_FALSE);
		}

#ifndef  __WEBCAM_SUPPORT_ISO_PIPE__
		USB_TxEPClearDataTog(g_USBVideo.txpipe->byEP, USB_ENDPT_BULK);
#endif

		g_USBVideo.usb_video_dma_stop = KAL_TRUE;
		g_USBVideo.video_control.video_buffer_read_index = 0;
		g_USBVideo.video_control.video_buffer_write_index = 0;
		g_USBVideo.video_control.video_buffer_full = KAL_FALSE;
		g_USBVideo.video_control.send_video_msg = KAL_TRUE;
		g_USBVideo.video_control.sent_video_size = 0;

//		USBVideo_Send_Msg(USBVIDEO_MSG_USB_ABORT, 0, 0);
	}
}


void USBVideo_VS_If_Enable(void)
{
#ifdef  __WEBCAM_SUPPORT_ISO_PIPE__
	/* ISO, DMA */
	USB_TxEPEn(g_USBVideo.txpipe->byEP, USB_ENDPT_ISO, USB_EP_USE_ONLY_DMA, KAL_TRUE, KAL_FALSE);
#else
	/* DMA */
	USB_TxEPEn(g_USBVideo.txpipe->byEP, USB_ENDPT_BULK, USB_EP_USE_ONLY_DMA, KAL_TRUE, KAL_FALSE);
#endif
}


void USBVideo_VS_If_Speed_Reset(kal_bool b_other_speed)
{
#ifdef __USB_HS_ENABLE__
	#ifdef  __WEBCAM_SUPPORT_ISO_PIPE__

	g_USBVideo.vs_ep_tx_info->epdesc.stdep.wMaxPacketSize[0] = USB_VIDEO_EP_ISO_MAXP&0xff;
	g_USBVideo.vs_ep_tx_info->epdesc.stdep.wMaxPacketSize[1] = (USB_VIDEO_EP_ISO_MAXP>>8)&0xff;

	#else /* __WEBCAM_SUPPORT_ISO_PIPE__ */

	if(USB_Is_High_Speed() == KAL_TRUE)
	{
		if(b_other_speed == KAL_FALSE)
		{
			g_USBVideo.vs_ep_tx_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_BULK_MAXP_HS&0xff;
			g_USBVideo.vs_ep_tx_info->epdesc.stdep.wMaxPacketSize[1] = (USB_EP_BULK_MAXP_HS>>8)&0xff;
		}
		else
		{
			g_USBVideo.vs_ep_tx_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_BULK_MAXP_FS&0xff;
//			g_USBVideo.vs_ep_tx_info->epdesc.stdep.wMaxPacketSize[1] = (USB_EP_BULK_MAXP_FS>>8)&0xff;
			g_USBVideo.vs_ep_tx_info->epdesc.stdep.wMaxPacketSize[1] = 0x00;
		}
	}
	else
	{
		if(b_other_speed == KAL_FALSE)
		{
			g_USBVideo.vs_ep_tx_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_BULK_MAXP_FS&0xff;
//			g_USBVideo.vs_ep_tx_info->epdesc.stdep.wMaxPacketSize[1] = (USB_EP_BULK_MAXP_FS>>8)&0xff;
			g_USBVideo.vs_ep_tx_info->epdesc.stdep.wMaxPacketSize[1] = 0x00;
		}
		else
		{
			g_USBVideo.vs_ep_tx_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_BULK_MAXP_HS&0xff;
			g_USBVideo.vs_ep_tx_info->epdesc.stdep.wMaxPacketSize[1] = (USB_EP_BULK_MAXP_HS>>8)&0xff;
		}
	}
	#endif  /* __WEBCAM_SUPPORT_ISO_PIPE__ */
#endif
}

/************************************************************
	global variable g_USBVideo initialize and release functions
*************************************************************/

/* initialize global variable g_USBVideo */
void USB_Init_Video_Status(void)
{
//	DCL_HANDLE gpt_handle;
	drv_trace0(TRACE_FUNC, (kal_uint32)USBVIDEO_INIT);

//	g_USBVideo.camera_param = USBVideo_Get_Camera_Param();//for Dual sensor(after UEM detect)
        CalFeatureCtrlStruct.FeatureCtrlCode = CAL_FEATURE_GET_OPERATION;
        CalFeatureCtrlStruct.FeatureId = CAL_FEATURE_WEBCAM_GET_DEFAULT_IDX;
        CalFeatureCtrlStruct.FeatureInfo.FeatureStructured.pWebCamDeafultIdx = &UsbvideoDeafultIdx;
        CalCtrl(CAL_FEATURE_CTRL, &CalFeatureCtrlStruct, NULL, 0, NULL);

	/* initailize g_USBVideo */
	g_USBVideo.txpipe = NULL;
	g_USBVideo.intrpipe = NULL;
	g_USBVideo.vs_interface_id = 0;
	g_USBVideo.vc_ct_support = 0;
	g_USBVideo.vc_ct_set = 0;
	g_USBVideo.vc_pu_support = 0;
	g_USBVideo.vc_pu_set = 0;
	g_USBVideo.state = USBVIDEO_STATE_STOP;
	g_USBVideo.commit_video_index = 0;
	g_USBVideo.probe_state = USBVIDEO_PROBE_NONE;
	g_USBVideo.commit_still_index = 0;
	g_USBVideo.vc_white_balance_error_setting = KAL_FALSE;
	g_USBVideo.still_probe_state = USBVIDEO_PROBE_NONE;
	g_USBVideo.video_start_state = USBVIDEO_START_NONE;
	g_USBVideo.video_control.video_buffer_addr[0] = NULL;
	g_USBVideo.video_control.video_buffer_read_index = 0;
	g_USBVideo.video_control.video_buffer_write_index = 0;
	g_USBVideo.video_control.video_buffer_full = KAL_FALSE;
	g_USBVideo.video_control.send_video_msg = KAL_TRUE;
	g_USBVideo.video_control.sent_video_size = 0;
	g_USBVideo.video_control.video_frame_id = 0;
	g_USBVideo.usb_video_dma_stop = KAL_FALSE;
	g_USBVideo.is_get_buffer_after_change_size = KAL_TRUE;

	if (g_USBVideo.video_control.incall_jpeg_buff == NULL)
		g_USBVideo.video_control.incall_jpeg_buff = (kal_uint8 *)USB_Get_Memory(USBVIDEO_MAX_PAYLOAD_LENGTH);//g_USBVIDEO_BUFFER;

//	g_USBVideo.video_control.b_processing_dma = KAL_FALSE;
	/* Start GPT timer 3 for PTS */
//	GPT_Start(3);
//	gpt_handle=DclFGPT_Open(DCL_GPT_FreeRUN3,0);
//	DclFGPT_Control(gpt_handle,FGPT_CMD_START,0);
//	DclFGPT_Close(gpt_handle);
	USB_GPT3_Start();	
		
	USB_GPTI_GetHandle(&(g_USBVideo.video_control.timer_handle));//DclSGPT_Open(DCL_GPT_CB, 0);//GPTI_GetHandle(&g_USBVideo.video_control.timer_handle);   

//	if ((g_USBVideo.video_control.timer_handle==0)||(g_USBVideo.video_control.timer_handle==0x7F))
//		g_USBVideo.video_control.timer_handle = USB_GPTI_GetHandle();//DclSGPT_Open(DCL_GPT_CB, 0);//GPTI_GetHandle(&g_USBVideo.video_control.timer_handle);   

#ifdef WEBCAM_TEST_DMA_DELAY
 	USB_GPTI_GetHandle(&(g_USBVideo.test_timer_handle));
//	if((g_USBVideo.test_timer_handle==0)||(g_USBVideo.test_timer_handle==0x7F))
//		g_USBVideo.test_timer_handle = USB_GPTI_GetHandle();//DclSGPT_Open(DCL_GPT_CB, 0);//GPTI_GetHandle(&g_USBVideo.test_timer_handle);
	g_USBVideo.test_enable = KAL_FALSE;
#endif
}

/* release global variable g_USBVideo */
void USB_Release_Video_Status(void)
{
//	DCL_HANDLE handle;
//	DCL_HANDLE gpt_handle;
	drv_trace0(TRACE_FUNC, (kal_uint32)USBVIDEO_RELEASE);


	USB_Free_DMA_Channel(g_USBVideo.txpipe->byEP, 0, USB_EP_TX_DIR, KAL_FALSE);

	/* Release g_USBVideo resource */
	g_USBVideo.txpipe = NULL;
	g_USBVideo.intrpipe = NULL;
	g_USBVideo.vs_interface_id = 0;
	g_USBVideo.vc_ct_support = 0;
	g_USBVideo.vc_ct_set = 0;
	g_USBVideo.vc_pu_support = 0;
	g_USBVideo.vc_pu_set = 0;
	g_USBVideo.state = USBVIDEO_STATE_STOP;
	g_USBVideo.commit_video_index = 0;
	g_USBVideo.probe_state = USBVIDEO_PROBE_NONE;
	g_USBVideo.commit_still_index = 0;
	g_USBVideo.still_probe_state = USBVIDEO_PROBE_NONE;
	g_USBVideo.video_start_state = USBVIDEO_START_NONE;
	g_USBVideo.video_control.video_buffer_addr[0] = NULL;
	g_USBVideo.video_control.video_buffer_read_index = 0;
	g_USBVideo.video_control.video_buffer_write_index = 0;
	g_USBVideo.video_control.video_buffer_full = KAL_FALSE;
	g_USBVideo.video_control.send_video_msg = KAL_TRUE;
	g_USBVideo.video_control.sent_video_size = 0;
	g_USBVideo.video_control.video_frame_id = 0;
	g_USBVideo.usb_video_dma_stop = KAL_FALSE;
	g_USBVideo.is_get_buffer_after_change_size = KAL_TRUE;

	g_USBVideo.video_control.incall_jpeg_buff = NULL;

//	g_USBVideo.video_control.b_processing_dma = KAL_FALSE;
	/* Stop GPT timer */
//	GPT_Stop(3);
//	gpt_handle=DclFGPT_Open(DCL_GPT_FreeRUN3,0);
//	DclFGPT_Control(gpt_handle,FGPT_CMD_STOP,0);
//	DclFGPT_Close(gpt_handle);
	USB_GPT3_Stop();
	USB_GPTI_ReleaseHandle(&(g_USBVideo.video_control.timer_handle));
//	handle = (DCL_HANDLE)g_USBVideo.video_control.timer_handle;
//	g_USBVideo.video_control.timer_handle = DclSGPT_Close(&handle);//GPTI_ReleaseHandle(&g_USBVideo.video_control.timer_handle);

#ifdef WEBCAM_TEST_DMA_DELAY
	USB_GPTI_ReleaseHandle(&(g_USBVideo.test_timer_handle));

//	handle = (DCL_HANDLE)g_USBVideo.test_timer_handle;
//	g_USBVideo.test_timer_handle = DclSGPT_Close(&handle);//GPTI_ReleaseHandle(&g_USBVideo.test_timer_handle);
#endif
}


/************************************************************
	EP0 command parse functions
*************************************************************/
kal_bool USBVideo_Get_PU_Attr_Cur_Value(USBVIDEO_ATTRIBUTE_TYPE type)
{
	USBVideo_Attr_Value attr_value;
	kal_bool   result;
	kal_uint32   attr_temp;


	/* Must check this attr if support or not, if not support we return false */
	attr_temp = (kal_uint32)type&(0x7f);

	if((g_USBVideo.vc_pu_support&(1<<attr_temp)) != 0)
	{
		attr_value.type = type;
		attr_value.req_type = USBVIDEO_REQUEST_GET_CUR;
		attr_value.subtype = 0;
//		g_USBVideo.camera_param->usbvideo_get_attr_value(&attr_value);   /*get we need attr from camera driver */
		CalFeatureCtrlStruct.FeatureCtrlCode = CAL_FEATURE_GET_OPERATION;
		CalFeatureCtrlStruct.FeatureId = CAL_FEATURE_WEBCAM_GET_ATTR;
		CalFeatureCtrlStruct.FeatureInfo.FeatureStructured.pWebCamAttr = &attr_value;
		CalCtrl(CAL_FEATURE_CTRL, &CalFeatureCtrlStruct, NULL, 0, NULL);

		result = (kal_bool)attr_value.value;
	}
	else
	{
		result = KAL_FALSE;
	}

	return result;
}


static void USBVideo_Send_Set_Attr_Meg(void)
{
//	ilm_struct *send_ilm;
	usbvideo_attr_msg_struct *attr_req;
	module_type dest_mod;


#if ( (defined(__WEBCAM_CAMERA_TEST__)) || (defined(__WEBCAM_USB_TEST__)) )
	dest_mod = MOD_CUSTOM1;
#else
	dest_mod = MOD_MED;
#endif

	attr_req = (usbvideo_attr_msg_struct*)construct_local_para(
				sizeof(usbvideo_attr_msg_struct), TD_CTRL);

	kal_mem_cpy(&attr_req->attr_value, &g_USBVideo.set_attr_value, sizeof(USBVideo_Attr_Value));

	USB_Send_Msg_Ext_Queue(dest_mod,MSG_ID_USB_MED_SET_CAMERA_ATTR_REQ,attr_req);
//	DRV_BuildPrimitive(send_ilm,MOD_DRV_HISR,dest_mod,MSG_ID_USB_MED_SET_CAMERA_ATTR_REQ,attr_req);
//	msg_send_ext_queue(send_ilm);
}



/* Rx handler for set attribute control */
static void USBVideo_Set_Attr(void *data)
{
	kal_bool  bError = KAL_FALSE;
	kal_uint32 nCount;
	kal_uint8 recv[8];
	USBVideo_Attr_Value attr_value;
	kal_uint32 index, index2;
	kal_uint32 subtype_num;
	kal_uint32 process_num;
	const USBVideo_Attr_Map *attr_map;
	kal_uint8 *subtype_cnf;
	kal_uint32 attr_index;
	kal_uint32  attr_max, attr_min, attr_res, attr_set = 0;
//	kal_uint16  hue_max, hue_min, hue_set;


	g_USBVideo.vc_set_wbalance_tmp_intr = KAL_FALSE;
	g_USBVideo.vc_set_hue_intr = KAL_FALSE;

	nCount = USB_EP0_Pkt_Len();

	if(nCount != 0)
	{
		USB_EPFIFORead(0, nCount, recv, KAL_FALSE);

		if(((kal_uint32)g_USBVideo.set_attr_value.type&0x80) == 0)
		{
			/* camera terminal attribute */
			attr_map = g_USBVideo_CT_Attr_Map;
			subtype_cnf = g_USBVideo.vc_ct_subtype_cnf;
			attr_index = (kal_uint32)g_USBVideo.set_attr_value.type - 1;
		}
		else
		{
			/* processing unit attribute*/
			attr_map = g_USBVideo_PU_Attr_Map;
			subtype_cnf = g_USBVideo.vc_pu_subtype_cnf;
			attr_index = ((kal_uint32)g_USBVideo.set_attr_value.type&(~0x80)) - 1;
		}

		process_num = 0;

		if(attr_map[attr_index].subtype_table != NULL)
		{
			/* has subtype for the current attribute type */
			subtype_num = sizeof(attr_map[attr_index].subtype_table)/sizeof(USBVideo_Attr_Sub_Map);  /* how many subtype */

			/* Must check the SET_CUR's value is vaild first */
			for(index = 0; index < subtype_num; index++)
			{
				attr_value.subtype = attr_map[attr_index].subtype_table[index].subtype;
				attr_value.type = g_USBVideo.set_attr_value.type;

				attr_value.req_type = USBVIDEO_REQUEST_GET_MIN;
//				g_USBVideo.camera_param->usbvideo_get_attr_value(&attr_value);  /*get we need attr from camera driver */
                    		CalFeatureCtrlStruct.FeatureCtrlCode = CAL_FEATURE_GET_OPERATION;
                    		CalFeatureCtrlStruct.FeatureId = CAL_FEATURE_WEBCAM_GET_ATTR;
                    		CalFeatureCtrlStruct.FeatureInfo.FeatureStructured.pWebCamAttr = &attr_value;
                    		CalCtrl(CAL_FEATURE_CTRL, &CalFeatureCtrlStruct, NULL, 0, NULL);
				attr_min = attr_value.value;

				attr_value.req_type = USBVIDEO_REQUEST_GET_MAX;
//				g_USBVideo.camera_param->usbvideo_get_attr_value(&attr_value);  /*get we need attr from camera driver */
                    		CalFeatureCtrlStruct.FeatureCtrlCode = CAL_FEATURE_GET_OPERATION;
                    		CalFeatureCtrlStruct.FeatureId = CAL_FEATURE_WEBCAM_GET_ATTR;
                    		CalFeatureCtrlStruct.FeatureInfo.FeatureStructured.pWebCamAttr = &attr_value;
                    		CalCtrl(CAL_FEATURE_CTRL, &CalFeatureCtrlStruct, NULL, 0, NULL);

				attr_max = attr_value.value;

				attr_value.req_type = USBVIDEO_REQUEST_GET_RES;
//				g_USBVideo.camera_param->usbvideo_get_attr_value(&attr_value);  /*get we need attr from camera driver */
                    		CalFeatureCtrlStruct.FeatureCtrlCode = CAL_FEATURE_GET_OPERATION;
                    		CalFeatureCtrlStruct.FeatureId = CAL_FEATURE_WEBCAM_GET_ATTR;
                    		CalFeatureCtrlStruct.FeatureInfo.FeatureStructured.pWebCamAttr = &attr_value;
                    		CalCtrl(CAL_FEATURE_CTRL, &CalFeatureCtrlStruct, NULL, 0, NULL);

				attr_res = attr_value.value;

				attr_set = 0;

				for(index2 = 0; index2 < attr_map[attr_index].subtype_table[index].length; index2++)/*each subtype's length*/
				{
					/* For value larger than one byte */
					attr_set += (recv[index2 + process_num]<<(index2*8));
				}

				if((attr_set < attr_min)||(attr_set > attr_max)||(((attr_set-attr_min)%attr_res) != 0))
				{
					g_USBVideo.error_code = USBVIDEO_ERROR_OUT_OF_RANGE;
					bError = KAL_TRUE;
				}
				process_num += index2;
			}

			if(bError == KAL_FALSE)
			{
				process_num = 0;
				subtype_cnf[attr_index] = 0;

				for(index = 0; index < subtype_num; index++)
				{
					g_USBVideo.set_attr_value.value = 0;
					g_USBVideo.set_attr_value.subtype = attr_map[attr_index].subtype_table[index].subtype;


					for(index2 = 0; index2 < attr_map[attr_index].subtype_table[index].length; index2++)/*each subtype's length*/
					{
						/* For value larger than one byte */
						g_USBVideo.set_attr_value.value += (recv[index2 + process_num]<<(index2*8));
					}

					USBVideo_Send_Set_Attr_Meg();	/* one subtype, one message */

					process_num += index2;
					subtype_cnf[attr_index] |= (1<<index);
				}
			}
		}
		else
		{
			/* Do not have subtype for the current attribute type */
			g_USBVideo.set_attr_value.value = 0;
			g_USBVideo.set_attr_value.subtype = 0;

			attr_value.type = g_USBVideo.set_attr_value.type;
			attr_value.subtype = 0;

			attr_value.req_type = USBVIDEO_REQUEST_GET_MIN;
//			g_USBVideo.camera_param->usbvideo_get_attr_value(&attr_value);  /*get we need attr from camera driver */
                	CalFeatureCtrlStruct.FeatureCtrlCode = CAL_FEATURE_GET_OPERATION;
                	CalFeatureCtrlStruct.FeatureId = CAL_FEATURE_WEBCAM_GET_ATTR;
                	CalFeatureCtrlStruct.FeatureInfo.FeatureStructured.pWebCamAttr = &attr_value;
                	CalCtrl(CAL_FEATURE_CTRL, &CalFeatureCtrlStruct, NULL, 0, NULL);

			attr_min = attr_value.value;

			attr_value.req_type = USBVIDEO_REQUEST_GET_MAX;
//			g_USBVideo.camera_param->usbvideo_get_attr_value(&attr_value);  /*get we need attr from camera driver */
               	 	CalFeatureCtrlStruct.FeatureCtrlCode = CAL_FEATURE_GET_OPERATION;
                	CalFeatureCtrlStruct.FeatureId = CAL_FEATURE_WEBCAM_GET_ATTR;
                	CalFeatureCtrlStruct.FeatureInfo.FeatureStructured.pWebCamAttr = &attr_value;
                	CalCtrl(CAL_FEATURE_CTRL, &CalFeatureCtrlStruct, NULL, 0, NULL);

			attr_max = attr_value.value;

			attr_value.req_type = USBVIDEO_REQUEST_GET_RES;
//			g_USBVideo.camera_param->usbvideo_get_attr_value(&attr_value);  /*get we need attr from camera driver */
                	CalFeatureCtrlStruct.FeatureCtrlCode = CAL_FEATURE_GET_OPERATION;
                	CalFeatureCtrlStruct.FeatureId = CAL_FEATURE_WEBCAM_GET_ATTR;
                	CalFeatureCtrlStruct.FeatureInfo.FeatureStructured.pWebCamAttr = &attr_value;
                	CalCtrl(CAL_FEATURE_CTRL, &CalFeatureCtrlStruct, NULL, 0, NULL);

			attr_res = attr_value.value;

			if(attr_value.type == USBVIDEO_ATTRIBUTE_HUE)
			{
				if(USBVideo_Get_PU_Attr_Cur_Value(USBVIDEO_ATTRIBUTE_HUE_AUTO) == KAL_TRUE)
				{
					g_USBVideo.error_code = USBVIDEO_ERROR_WRONG_STATE;
					bError = KAL_TRUE;
				}
				else
				{
					/* We need transfer for HUE */
					/* We use 0 to 360 instead of -18000 to 18000 because of msn! */
//					hue_max = ((kal_int16) (attr_max*100))-18000;
//					hue_min = ((kal_int16) (attr_min*100))-18000;

//					hue_max = ((kal_uint16)(attr_max));
//					hue_min = ((kal_uint16)(attr_min));

					if(nCount == 2)
						attr_set = (recv[0]|(recv[1]<<8));
					else
						attr_set = recv[0];

					if((attr_set < attr_min)||(attr_set > attr_max)||(((attr_set - attr_min)%attr_res) != 0))
					{
						g_USBVideo.error_code = USBVIDEO_ERROR_OUT_OF_RANGE;
						bError = KAL_TRUE;
					}
					else
					{
//						g_USBVideo.set_attr_value.value = (kal_uint32)((hue_set+18000)/100);
						g_USBVideo.set_attr_value.value = attr_set;

						USBVideo_Send_Set_Attr_Meg();
					}
				}
			}
			else if (attr_value.type == USBVIDEO_ATTRIBUTE_HUE_AUTO)
			{
				g_USBVideo.set_attr_value.value = recv[0];

				attr_set = g_USBVideo.set_attr_value.value;

				attr_value.req_type = USBVIDEO_REQUEST_GET_CUR;
//				g_USBVideo.camera_param->usbvideo_get_attr_value(&attr_value);  /*get we need attr from camera driver */
                    		CalFeatureCtrlStruct.FeatureCtrlCode = CAL_FEATURE_GET_OPERATION;
                    		CalFeatureCtrlStruct.FeatureId = CAL_FEATURE_WEBCAM_GET_ATTR;
                    		CalFeatureCtrlStruct.FeatureInfo.FeatureStructured.pWebCamAttr = &attr_value;
                    		CalCtrl(CAL_FEATURE_CTRL, &CalFeatureCtrlStruct, NULL, 0, NULL);

				/* Setting value is different from current setting */
				if(attr_value.value != attr_set)
				{
					g_USBVideo.vc_set_hue_intr = KAL_TRUE;
				}
			}
			else if(attr_value.type == USBVIDEO_ATTRIBUTE_WHITE_BALANCE_TMP_AUTO)
			{
				g_USBVideo.set_attr_value.value = recv[0];

				attr_set = g_USBVideo.set_attr_value.value;

				attr_value.req_type = USBVIDEO_REQUEST_GET_CUR;
//				g_USBVideo.camera_param->usbvideo_get_attr_value(&attr_value);  /*get we need attr from camera driver */
                    		CalFeatureCtrlStruct.FeatureCtrlCode = CAL_FEATURE_GET_OPERATION;
                    		CalFeatureCtrlStruct.FeatureId = CAL_FEATURE_WEBCAM_GET_ATTR;
                    		CalFeatureCtrlStruct.FeatureInfo.FeatureStructured.pWebCamAttr = &attr_value;
                    		CalCtrl(CAL_FEATURE_CTRL, &CalFeatureCtrlStruct, NULL, 0, NULL);

				/* Setting value is different from current setting */
				if(attr_value.value != attr_set)
				{
					g_USBVideo.vc_set_wbalance_tmp_intr = KAL_TRUE;
				}
			}
			else if(attr_value.type == USBVIDEO_ATTRIBUTE_WHITE_BALANCE_TMP)
			{
				if(USBVideo_Get_PU_Attr_Cur_Value(USBVIDEO_ATTRIBUTE_WHITE_BALANCE_TMP_AUTO) == KAL_TRUE)
				{
					g_USBVideo.error_code = USBVIDEO_ERROR_WRONG_STATE;
					bError = KAL_TRUE;
				}
				else
				{
					g_USBVideo.set_attr_value.value = recv[0]|(recv[1]<<8);
					attr_set = g_USBVideo.set_attr_value.value;

					if((attr_set < attr_min)||(attr_set > attr_max)||(((attr_set-attr_min)%attr_res) != 0))
					{
						g_USBVideo.error_code = USBVIDEO_ERROR_OUT_OF_RANGE;
						bError = KAL_TRUE;
					}
					else
					{
						USBVideo_Send_Set_Attr_Meg();
					}
				}
			}
			else
			{
				for(index = 0; index < attr_map[attr_index].length; index++)
				{
					/* For value larger than one byte */
					g_USBVideo.set_attr_value.value += (recv[index]<<(index*8));
				}

				attr_set = g_USBVideo.set_attr_value.value;
			}

			if((attr_value.type != USBVIDEO_ATTRIBUTE_HUE)&&(attr_value.type != USBVIDEO_ATTRIBUTE_WHITE_BALANCE_TMP))
			{
				if((attr_set < attr_min)||(attr_set > attr_max)||(((attr_set-attr_min)%attr_res) != 0))
				{
					g_USBVideo.error_code = USBVIDEO_ERROR_OUT_OF_RANGE;
					bError = KAL_TRUE;
				}
				else
				{
					USBVideo_Send_Set_Attr_Meg();
				}
			}
		}
	}
	else
	{
		/* nCount == 0 */
		bError = KAL_TRUE;
	}

	/* Only bError == KAL_TRUE is handled here */
	if(bError == KAL_TRUE)
	{
		USB_Set_Endpoint0_State(USB_EP0_RX_STATUS);
		USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, KAL_TRUE, KAL_TRUE);
	}

	USB_Register_EP0_RxHdlr(NULL);
}


/* RX handler for video probe and commit control */
static void USBVideo_Set_ProbControl(void *data)
{
	kal_uint32 nCount;
	kal_bool  bError;
	kal_bool  bEnd;
	kal_uint8 recv[26];
	static kal_uint32 nTotal = 0;
	const USBVideo_Video_Size_Info *p_video_size_param;
	kal_uint8 video_size_num;
	kal_uint32 max_frame_size;
//	kal_uint32 savedMask;
	kal_bool b_change_size = KAL_FALSE;


	p_video_size_param = g_USBVideo.video_control.p_video_size_info;  /* be set at USBVideo_VS_If_Create() */
	video_size_num = g_USBVideo.video_control.video_size_num;

	/* Read setting and set video setting */
	nCount = USB_EP0_Pkt_Len();  /*  because ep0 get 8 bytes at a time */

	if(nCount != 0)
	{
		/* Check illegal probe length */
		if((nCount > USB_EP0_MAXP)||((nTotal + nCount) > 26))
		{
			/* Illegal probe length, return STALL */
			drv_trace2(TRACE_FUNC, (kal_uint32)USBVIDEO_SET_PROB_CONTROL_ERROR, nCount, nTotal);
			USB_Dbg_Trace(USB_VIDEO_PROBE_CONTROL_ERROR, nCount, nTotal);
			USB_Set_Endpoint0_State(USB_EP0_RX_STATUS);
	   		USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, KAL_TRUE, KAL_TRUE);
	   		USB_Register_EP0_RxHdlr(NULL);
	   		nTotal = 0;
	   		return;
		}
		else
		{
			USB_EPFIFORead(0, nCount, recv, KAL_FALSE);
		}

		kal_mem_cpy(&((kal_uint8*)&g_USBVideo.vs_recv_probe_control)[nTotal], recv, nCount);
		nTotal += nCount;

		if(nTotal == 26)	/* All probe control are received */
		//if( (nTotal == 34) ||(nTotal == 26) )
		{
			if(g_USBVideo.vs_recv_probe_control.bFrameIndex!=g_USBVideo.vs_probe_control.bFrameIndex)
			{
				/* update current frame index if PC request for a new one */
				if(g_USBVideo.vs_recv_probe_control.bFrameIndex > video_size_num)
					EXT_ASSERT(0, (kal_uint32)g_USBVideo.vs_recv_probe_control.bFrameIndex, (kal_uint32)video_size_num, 0);

				g_USBVideo.vs_probe_control.bFrameIndex = g_USBVideo.vs_recv_probe_control.bFrameIndex;
				g_USBVideo.vs_probe_control.dwFrameInterval[0] = p_video_size_param[g_USBVideo.vs_probe_control.bFrameIndex-1].default_frame_interval&0xff;
				g_USBVideo.vs_probe_control.dwFrameInterval[1] = (p_video_size_param[g_USBVideo.vs_probe_control.bFrameIndex-1].default_frame_interval>>8)&0xff;
				g_USBVideo.vs_probe_control.dwFrameInterval[2] = (p_video_size_param[g_USBVideo.vs_probe_control.bFrameIndex-1].default_frame_interval>>16)&0xff;
				g_USBVideo.vs_probe_control.dwFrameInterval[3] = (p_video_size_param[g_USBVideo.vs_probe_control.bFrameIndex-1].default_frame_interval>>24)&0xff;
				max_frame_size = USBVideo_Get_Max(p_video_size_param[g_USBVideo.vs_probe_control.bFrameIndex-1].max_frame_size,
												g_USBVideo.video_control.default_jpeg_max_size[g_USBVideo.vs_probe_control.bFrameIndex-1]);
				g_USBVideo.vs_probe_control.dwMaxVideoFrameSize[0] = max_frame_size&0xff;
				g_USBVideo.vs_probe_control.dwMaxVideoFrameSize[1] = (max_frame_size>>8)&0xff;
				g_USBVideo.vs_probe_control.dwMaxVideoFrameSize[2] = (max_frame_size>>16)&0xff;
				g_USBVideo.vs_probe_control.dwMaxVideoFrameSize[3] = (max_frame_size>>24)&0xff;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
			}

			if(g_USBVideo.probe_state == USBVIDEO_PROBE_IN)
			{
				g_USBVideo.probe_state = USBVIDEO_PROBE_DONE;
				USB_Dbg_Trace(USB_VIDEO_PROBE_DONE, 0, 0);
			}
			else if(g_USBVideo.probe_state == USBVIDEO_COMMIT_IN)
			{
				if(g_USBVideo.commit_video_index != g_USBVideo.vs_probe_control.bFrameIndex) /*  0 by default*/
				{
					g_USBVideo.commit_video_index = g_USBVideo.vs_probe_control.bFrameIndex;
					b_change_size = KAL_TRUE;
				}
				else
				{
					b_change_size = KAL_FALSE;
				}

				/* commit done */
				g_USBVideo.usb_video_dma_stop = KAL_FALSE;

				/* Clear FIFO, if not clear it, the next packet may be false */
				if(USB_DMA_Get_Run_Status(g_USBVideo.txpipe->byEP, USB_EP_TX_DIR) == KAL_FALSE)
				{
			#ifdef  __WEBCAM_SUPPORT_ISO_PIPE__
					/* Clear FIFO, if not clear it, the next packet may be false */
					USB_Clear_Tx_EP_FIFO(g_USBVideo.txpipe->byEP, USB_ENDPT_ISO, KAL_TRUE);
			#else
					/* Clear FIFO, if not clear it, the next packet may be false */
					USB_Clear_Tx_EP_FIFO(g_USBVideo.txpipe->byEP, USB_ENDPT_BULK, KAL_TRUE);
			#endif
				}

				g_USBVideo.probe_state = USBVIDEO_COMMIT_DONE;
				USB_Dbg_Trace(USB_VIDEO_PROBE_COMMIT_DONE, 0, 0);
//				g_USBVideo.video_compression_index = (kal_uint8)g_USBVideo.camera_param->usbvideo_get_default_compression_index();
				g_USBVideo.video_compression_index =  UsbvideoDeafultIdx.WebCamCompressionIdx;
				/* In case another un-support still image application is opened,
				    so reset the still probe state when recv new probe commit */
				/* Because some applications will capture still image after reset still probe state without commit still index,
						so we do not reset here */
/*
				if(g_USBVideo.still_probe_state == USBVIDEO_COMMIT_DONE)
				{
					drv_trace0(TRACE_FUNC, USBVIDEO_STILL_PROBE_NONE);
					USB_Dbg_Trace(USB_VIDEO_STILL_PROBE_NONE, 0, 0);
					g_USBVideo.still_probe_state = USBVIDEO_PROBE_NONE;
					g_USBVideo.commit_still_index = 0;
				}
*/

				if(g_USBVideo.state == USBVIDEO_STATE_STOP)
				{
					USBVideo_Send_Msg(USBVIDEO_MSG_USB_ENUM_DONE, 0, 0);
				}
				else if ((g_USBVideo.state == USBVIDEO_STATE_SEND) || (g_USBVideo.state == USBVIDEO_STATE_DROP))
				{
					if(b_change_size == KAL_TRUE)
					{
						USBVideo_Send_Msg(USBVIDEO_MSG_USB_CHANGE_SIZE, 0, 0);

						/* MTK driver will probe/commit twice */
						/* Avoid race condition with DMA HISR */

						/* Stop DMA if it is on */
						if(USB_DMA_Get_Run_Status(g_USBVideo.txpipe->byEP, USB_EP_TX_DIR) == KAL_TRUE)
						{
							USB_Stop_DMA_Channel(g_USBVideo.txpipe->byEP, USB_EP_TX_DIR);

					#ifdef  __WEBCAM_SUPPORT_ISO_PIPE__
							/* Clear FIFO, if not clear it, the next packet may be false */
							USB_Clear_Tx_EP_FIFO(g_USBVideo.txpipe->byEP, USB_ENDPT_ISO, KAL_TRUE);
					#else
							/* Clear FIFO, if not clear it, the next packet may be false */
							USB_Clear_Tx_EP_FIFO(g_USBVideo.txpipe->byEP, USB_ENDPT_BULK, KAL_TRUE);
					#endif

							/* Clear DMA running state here*/
//							USB_DMA_Set_Run_Status(g_USBVideo.txpipe->byEP, USB_EP_TX_DIR, KAL_FALSE);
					 	}

						g_USBVideo.state = USBVIDEO_STATE_DROP;
						/* This flag will make sure that camera must get buffer address then complete */
						g_USBVideo.is_get_buffer_after_change_size = KAL_FALSE;
						g_USBVideo.video_control.sent_video_size = 0;
						g_USBVideo.video_control.video_buffer_write_index = 0;
						g_USBVideo.video_control.video_buffer_read_index = 0;
						g_USBVideo.video_control.video_buffer_full = KAL_FALSE;
						g_USBVideo.video_control.send_video_msg = KAL_TRUE;
					}
					else
					{
						/* app open and close will run to here */
						USB_Dbg_Trace(USB_VIDEO_PROBE_COMMIT_DONE_1, 0, 0);

						/* DMA not running means 1. first time commit. 2. USB sent out image, and camera not call complete */

						/* Stop DMA if it is on */
						if(USB_DMA_Get_Run_Status(g_USBVideo.txpipe->byEP, USB_EP_TX_DIR) == KAL_TRUE)
						{
							USB_Stop_DMA_Channel(g_USBVideo.txpipe->byEP, USB_EP_TX_DIR);

					#ifdef  __WEBCAM_SUPPORT_ISO_PIPE__
							/* Clear FIFO, if not clear it, the next packet may be false */
							USB_Clear_Tx_EP_FIFO(g_USBVideo.txpipe->byEP, USB_ENDPT_ISO, KAL_TRUE);
					#else
							/* Clear FIFO, if not clear it, the next packet may be false */
							USB_Clear_Tx_EP_FIFO(g_USBVideo.txpipe->byEP, USB_ENDPT_BULK, KAL_TRUE);
					#endif

							/* Clear DMA running state here*/
//							USB_DMA_Set_Run_Status(g_USBVideo.txpipe->byEP, USB_EP_TX_DIR, KAL_FALSE);

							g_USBVideo.video_control.sent_video_size = 0;

							/* Those settings may be work in perview mode, but incall jpeg should consider */
/*
							g_USBVideo.video_control.video_buffer_write_index = 0;
							g_USBVideo.video_control.video_buffer_read_index = 0;
							g_USBVideo.video_control.video_buffer_full = KAL_FALSE;
							g_USBVideo.video_control.send_video_msg = KAL_TRUE;
*/

							USB_Dbg_Trace(USB_VIDEO_PROBE_COMMIT_DONE_2, (kal_uint32)g_USBVideo.video_control.dma_type, 0);

							/* Not send null packet */
							g_USBVideo.video_control.dma_done_type = USBVIDEO_DMA_DONE_STOP;

							/* Notify state machine to update state */
							if(g_USBVideo.video_control.dma_type == USBVIDEO_DMA_VIDEO)
							{
								USBVideo_Send_Msg(USBVIDEO_MSG_USB_DMA_DONE, (kal_uint32)MOD_DRV_HISR, 0);
							}
							else if(g_USBVideo.video_control.dma_type == USBVIDEO_DMA_INCALL_JPEG)
							{
								/* If MT call when app is close and end MT call, next time open app,
								   it will happen because incall jpeg is still in DMA */
								/* incall jpeg case, must call this fuinction to re-tigger incall jpeg */
								USBVideo_Send_Msg(USBVIDEO_MSG_USB_INCALL_DMA_DONE, (kal_uint32)MOD_DRV_HISR, 0);
							}
							else
							{
								EXT_ASSERT(0, (kal_uint32)g_USBVideo.video_control.dma_type, (kal_uint32)g_USBVideo.state, 0);
							}
						}
					}
				}
				/* Do not need to send change size msg when in pause state
				    because the image size is queried each time*/
				else if(g_USBVideo.state == USBVIDEO_STATE_PAUSE)
				{
					/* Stop DMA if it is on */
					if(USB_DMA_Get_Run_Status(g_USBVideo.txpipe->byEP, USB_EP_TX_DIR) == KAL_TRUE)
					{
						USB_Stop_DMA_Channel(g_USBVideo.txpipe->byEP, USB_EP_TX_DIR);

				#ifdef  __WEBCAM_SUPPORT_ISO_PIPE__
						/* Clear FIFO, if not clear it, the next packet may be false */
						USB_Clear_Tx_EP_FIFO(g_USBVideo.txpipe->byEP, USB_ENDPT_ISO, KAL_TRUE);
				#else
						/* Clear FIFO, if not clear it, the next packet may be false */
						USB_Clear_Tx_EP_FIFO(g_USBVideo.txpipe->byEP, USB_ENDPT_BULK, KAL_TRUE);
				#endif

						/* clear dma running state here*/
//						USB_DMA_Set_Run_Status(g_USBVideo.txpipe->byEP, USB_EP_TX_DIR, KAL_FALSE);
					}

					/* pause state, commit will trigger change size */
					USBVideo_Send_Msg(USBVIDEO_MSG_USB_INCALL_CHANGE_SIZE, 0, 0);
				}
				else
				{
					drv_trace1(TRACE_FUNC, (kal_uint32)USBVIDEO_SET_COMMIT_VIDEO_STATE, (kal_uint32)g_USBVideo.state);
				}
			}/* if(g_USBVideo.probe_state == USBVIDEO_PROBE_IN) */

			bError = KAL_FALSE;
			bEnd = KAL_TRUE;
		}
		else
		{
			bError = KAL_FALSE;
			bEnd = KAL_FALSE;
		}
	}
	else
	{
		/* nCount == 0 */
		bError = KAL_TRUE;
		bEnd = KAL_TRUE;
	}

	if(bEnd == KAL_FALSE)
	{
		USB_Set_Endpoint0_State(USB_EP0_RX);
	}
	else
	{
		USB_Set_Endpoint0_State(USB_EP0_RX_STATUS);
		USB_Register_EP0_RxHdlr(NULL);
		nTotal = 0;
	}

	USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, bError, bEnd);
}


/* Rx handler for still probe and commit control */
static void USBVideo_Set_Still_ProbControl(void *data)
{
	kal_uint32 nCount;
	kal_bool  bError;
	kal_bool  bEnd;
	kal_uint8 recv[11];
	static kal_uint32 nStillTotal = 0;
	const USBVideo_Still_Size_Info *p_still_size_param;
	kal_uint8 still_size_num;

	p_still_size_param = g_USBVideo.video_control.p_still_size_info;  /*  be set at USBVideo_VS_If_Create() */
	still_size_num = g_USBVideo.video_control.still_size_num;

	/* read setting and set still commit parameter */
	nCount = USB_EP0_Pkt_Len();

	if(nCount != 0)
	{
		/* check illegal probe length */
		if((nCount > USB_EP0_MAXP)||((nStillTotal + nCount) > 11))
		{
			/* Illegal probe length, return STALL */
			drv_trace2(TRACE_FUNC, (kal_uint32)USBVIDEO_SET_STILL_PROB_CONTROL_ERROR, nCount, nStillTotal);
			USB_Dbg_Trace(USB_VIDEO_STILL_PROBE_CONTROL_ERROR, nCount, nStillTotal);
			USB_Set_Endpoint0_State(USB_EP0_RX_STATUS);
	   		USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, KAL_TRUE, KAL_TRUE);
	   		USB_Register_EP0_RxHdlr(NULL);
	   		nStillTotal = 0;
	   		return;
		}
		else
		{
			USB_EPFIFORead(0, nCount, recv, KAL_FALSE);
		}

		kal_mem_cpy(&((kal_uint8*)&g_USBVideo.vs_recv_still_probe_control)[nStillTotal], recv, nCount);
		nStillTotal += nCount;

		if(nStillTotal == 11)
		{
			if(g_USBVideo.vs_recv_still_probe_control.bFrameIndex != g_USBVideo.vs_still_probe_control.bFrameIndex)
			{
				if(g_USBVideo.vs_recv_still_probe_control.bFrameIndex > still_size_num)
					ASSERT(0);

				g_USBVideo.vs_still_probe_control.bFrameIndex = g_USBVideo.vs_recv_still_probe_control.bFrameIndex;
				g_USBVideo.vs_still_probe_control.dwMaxVideoFrameSize[0] = p_still_size_param[g_USBVideo.vs_still_probe_control.bFrameIndex-1].max_frame_size&0xff;
				g_USBVideo.vs_still_probe_control.dwMaxVideoFrameSize[1] = (p_still_size_param[g_USBVideo.vs_still_probe_control.bFrameIndex-1].max_frame_size>>8)&0xff;
				g_USBVideo.vs_still_probe_control.dwMaxVideoFrameSize[2] = (p_still_size_param[g_USBVideo.vs_still_probe_control.bFrameIndex-1].max_frame_size>>16)&0xff;
				g_USBVideo.vs_still_probe_control.dwMaxVideoFrameSize[3] = (p_still_size_param[g_USBVideo.vs_still_probe_control.bFrameIndex-1].max_frame_size>>24)&0xff;
			}

//			if(g_USBVideo.vs_recv_still_probe_control.bCompressionIndex != g_USBVideo.vs_still_probe_control.bCompressionIndex)
//			{
				g_USBVideo.vs_still_probe_control.bCompressionIndex = g_USBVideo.vs_recv_still_probe_control.bCompressionIndex;
//			}

			if(g_USBVideo.still_probe_state == USBVIDEO_PROBE_IN)
			{
				g_USBVideo.still_probe_state = USBVIDEO_PROBE_DONE;
				USB_Dbg_Trace(USB_VIDEO_STILL_PROBE_DONE,  (kal_uint32)g_USBVideo.commit_still_index, 0);
			}
			else if(g_USBVideo.still_probe_state == USBVIDEO_COMMIT_IN)
			{
				g_USBVideo.still_probe_state = USBVIDEO_COMMIT_DONE;
				g_USBVideo.commit_still_index = g_USBVideo.vs_still_probe_control.bFrameIndex;
				drv_trace1(TRACE_FUNC, (kal_uint32)USBVIDEO_STILL_COMMIT_DONE, g_USBVideo.commit_still_index);
				g_USBVideo.commit_still_compression_index = g_USBVideo.vs_still_probe_control.bCompressionIndex;
				USB_Dbg_Trace(USB_VIDEO_STILL_PROBE_COMMIT_DONE, (kal_uint32) g_USBVideo.commit_still_index, 0);
			}
			else
			{
				EXT_ASSERT(0, (kal_uint32)g_USBVideo.still_probe_state, 0, 0);
			}

			/* still capture dose not need send size message to USB task because still capture size will be
			    queried each time */
			bError = KAL_FALSE;
			bEnd = KAL_TRUE;
		}
		else
		{
			bError = KAL_FALSE;
			bEnd = KAL_FALSE;
		}
	}
	else
	{
		/* nCount == 0 */
		bError = KAL_TRUE;
		bEnd = KAL_TRUE;
	}

	if(bEnd == KAL_FALSE)
	{
		USB_Set_Endpoint0_State(USB_EP0_RX);
	}
	else
	{
		USB_Set_Endpoint0_State(USB_EP0_RX_STATUS);
		USB_Register_EP0_RxHdlr(NULL);
		nStillTotal = 0;
	}

	USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, bError, bEnd);
}


/* Rx handler for still image trigger by host */
static void USBVideo_Set_Still_ImageControl(void *data)
{
	kal_uint32 nCount;
	kal_uint8 recv[1];
	kal_bool  bError = KAL_FALSE;


	/* Read setting */
	nCount = USB_EP0_Pkt_Len();

	if(nCount != 1)
	{
		bError = KAL_TRUE;
	}
	else
	{
		USB_EPFIFORead(0, nCount, recv, KAL_FALSE);

		if((g_USBVideo.state != USBVIDEO_STATE_PRE_PAUSE)&&(g_USBVideo.state != USBVIDEO_STATE_PAUSE)
			&&(g_USBVideo.state != USBVIDEO_STATE_STOP)&&(g_USBVideo.commit_still_index != 0)
			&&((recv[0] == USBVIDEO_STILL_IMAGE_TRANSMIT)))
		{
			USBVideo_Send_Msg(USBVIDEO_MSG_USB_STILL_CAPTURE, 0, 0);
		}
	}

	USB_Set_Endpoint0_State(USB_EP0_RX_STATUS);
	USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, bError, KAL_TRUE);
	USB_Register_EP0_RxHdlr(NULL);
}


/* parse video  class vc specific command */
static void USBVideo_Ep0_VC_Command(Usb_Ep0_Status *pep0state, Usb_Command *pcmd)
{
	kal_bool  bError = KAL_FALSE;
	usbvideo_attr_msg_struct *attr_req;
	ilm_struct *send_ilm;
	kal_uint32 info;
	USBVideo_Attr_Value attr_value;
	USBVideo_Attr_Value 	set_attr_value;
	kal_uint32 index, index2;
	kal_uint32 match_value;
	const USBVideo_Attr_Map *attr_map;
	kal_uint32 attr_index;
	kal_uint32 subtype_size;
	kal_uint32 process_num = 0;
	kal_uint8  error_code;
	kal_uint16    hue_control;
	kal_uint32   attr_temp;


	switch(pcmd->bRequest)
	{
	case USBVIDEO_SET_CUR:
		if(pcmd->wIndex == (USBVIDEO_CT_ID<<8))/*entity ID in the high byte */
		{
			match_value = (1<<(pcmd->wValue>>8));/* CS in the high byte */

			if(((g_USBVideo.vc_ct_support&match_value)==0) || ((g_USBVideo.vc_ct_set&match_value)==0))
				EXT_ASSERT(0, (kal_uint32)pcmd->wIndex, (kal_uint32)pcmd->wValue, (kal_uint32)pcmd->bRequest);

			if(g_USBVideo_CT_Attr_Map[(pcmd->wValue>>8)-1].length!=pcmd->wLength)
				EXT_ASSERT(0, (kal_uint32)g_USBVideo_CT_Attr_Map[(pcmd->wValue>>8)-1].length, (kal_uint32)pcmd->wLength, 0);
		}
		else if(pcmd->wIndex == (USBVIDEO_PU_ID<<8))
		{
			match_value = (1<<(pcmd->wValue>>8));

			if(((g_USBVideo.vc_pu_support&match_value)==0) || ((g_USBVideo.vc_pu_set&match_value)==0))
				EXT_ASSERT(0, (kal_uint32)pcmd->wIndex, (kal_uint32)pcmd->wValue, (kal_uint32)pcmd->bRequest);

			if(g_USBVideo_PU_Attr_Map[(pcmd->wValue>>8)-1].length != pcmd->wLength)
			{
				if(((pcmd->wValue>>8)|0x80) != (kal_uint32)USBVIDEO_ATTRIBUTE_HUE)
					EXT_ASSERT(0, (kal_uint32)g_USBVideo_PU_Attr_Map[(pcmd->wValue>>8)-1].length, (kal_uint32)pcmd->wLength, 0);
			}
		}
		else
		{
			EXT_ASSERT(0, (kal_uint32)pcmd->wIndex, (kal_uint32)pcmd->wValue, (kal_uint32)pcmd->bRequest);
		}

		/* set attribute type to global variable, this variable will be used in Rx handler USBVideo_Set_Attr*/
		if(pcmd->wIndex == (USBVIDEO_CT_ID<<8))
		{
			g_USBVideo.set_attr_value.type = (USBVIDEO_ATTRIBUTE_TYPE)(pcmd->wValue>>8);
		}
		else if(pcmd->wIndex == (USBVIDEO_PU_ID<<8))
		{
			g_USBVideo.set_attr_value.type = (USBVIDEO_ATTRIBUTE_TYPE)((pcmd->wValue>>8)|0x80);
		}
		else
		{
			EXT_ASSERT(0, (kal_uint32)pcmd->wIndex, (kal_uint32)pcmd->bRequest, 0);
		}

		g_USBVideo.set_attr_value.subtype = 0;

		/* register handler to handle the get data*/
		USB_Register_EP0_RxHdlr(USBVideo_Set_Attr);
		USB_Set_Endpoint0_State(USB_EP0_RX);
		break;
	case USBVIDEO_GET_MIN:
	case USBVIDEO_GET_MAX:
	case USBVIDEO_GET_RES:
	case USBVIDEO_GET_CUR:
	case USBVIDEO_GET_DEF:
		if(pcmd->wIndex == (USBVIDEO_CT_ID<<8))
		{
			match_value = (1<<(pcmd->wValue>>8));

			if((g_USBVideo.vc_ct_support&match_value) == 0)
			{
				bError = KAL_TRUE;
				g_USBVideo.error_code = USBVIDEO_ERROR_INVAILD_CONTROL;
				break;
			}
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
		}
		else if(pcmd->wIndex == (USBVIDEO_PU_ID<<8))
		{
			match_value = (1<<(pcmd->wValue>>8));

			if((g_USBVideo.vc_pu_support&match_value) == 0)
			{
				bError = KAL_TRUE;
				g_USBVideo.error_code = USBVIDEO_ERROR_INVAILD_CONTROL;
				break;
			}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
		}
		else if((pcmd->wIndex) == 0x0000)
		{
			if(((pcmd->wValue)>>8) == USBVIDEO_VC_REQUEST_ERROR_CODE_CONTROL)
			{
				switch (g_USBVideo.error_code)
				{
				case USBVIDEO_NO_ERROR:
					error_code = USBVIDEO_VC_REQUEST_ERROR_NO_ERROR;
					break;
				case USBVIDEO_ERROR_NOT_READY:
					error_code = USBVIDEO_VC_REQUEST_ERROR_NOT_READY;
					break;
				case USBVIDEO_ERROR_WRONG_STATE:
					error_code = USBVIDEO_VC_REQUEST_ERROR_WRONG_STATE;
					break;
				case USBVIDEO_ERROR_POWER:
					error_code = USBVIDEO_VC_REQUEST_ERROR_POWER;
					break;
				case USBVIDEO_ERROR_OUT_OF_RANGE:
					error_code = USBVIDEO_VC_REQUEST_ERROR_OUT_OF_RANGE;
					break;
				case USBVIDEO_ERROR_INVALID_UNIT:
					error_code = USBVIDEO_VC_REQUEST_ERROR_INVALID_UNIT;
					break;
				case USBVIDEO_ERROR_INVAILD_CONTROL:
					error_code = USBVIDEO_VC_REQUEST_ERROR_INVALID_CONTROL;
					break;
				case USBVIDEO_ERROR_INVAILD_REQUEST:
					error_code = USBVIDEO_VC_REQUEST_ERROR_INVALID_REQUEST;
					break;
				case USBVIDEO_ERROR_UNKNOWN:
					error_code = USBVIDEO_VC_REQUEST_ERROR_UNKNOWN;
					break;
				default:
					EXT_ASSERT(0, (kal_uint32)g_USBVideo.error_code, 0, 0);
					break;
				}

				USB_Generate_EP0Data(pep0state, pcmd, &error_code, pcmd->wLength);
			}
			else
			{
				bError = KAL_TRUE;
				EXT_ASSERT(0, (kal_uint32)pcmd->wIndex, (kal_uint32)pcmd->wValue, (kal_uint32)pcmd->bRequest);
			}
			break;
		}
		else
		{
			bError = KAL_TRUE;
			EXT_ASSERT(0, (kal_uint32)pcmd->wIndex, (kal_uint32)pcmd->wValue, (kal_uint32)pcmd->bRequest);
			break;
		}

		if(pcmd->wIndex == (USBVIDEO_CT_ID<<8))
		{
			attr_value.type = (USBVIDEO_ATTRIBUTE_TYPE)(pcmd->wValue>>8);   /*  CS  */
			attr_map = g_USBVideo_CT_Attr_Map;
			attr_index = (kal_uint32)attr_value.type - 1;
		}
		else if(pcmd->wIndex == (USBVIDEO_PU_ID<<8))
		{
			attr_value.type = (USBVIDEO_ATTRIBUTE_TYPE)((pcmd->wValue>>8)|0x80);
			attr_map = g_USBVideo_PU_Attr_Map;
			attr_index = ((kal_uint32)attr_value.type&(~0x80)) - 1;
		}
		else
		{
			attr_value.type = USBVIDEO_ATTRIBUTE_PU_MAX;
			attr_index = 0;
			attr_map = NULL;
			EXT_ASSERT(0, (kal_uint32)pcmd->wIndex, (kal_uint32)pcmd->bRequest, 0);
		}

		/* Check cmd length of USBVIDEO_ATTRIBUTE_WHITE_BALANCE_TMP_AUTO because of UVC compliance test tool bug */
		/* UVC tool will send the wrong length cmd, and we disable white balance auto attr */
		if(attr_map[attr_index].length != pcmd->wLength)	//lint !e613
		{
			if(attr_value.type == USBVIDEO_ATTRIBUTE_WHITE_BALANCE_TMP_AUTO)
			{
				/* Use trick to avoid USB UVC compliance test tool's bug */
				g_USBVideo.vc_white_balance_error_setting = KAL_TRUE;

				set_attr_value.type = USBVIDEO_ATTRIBUTE_WHITE_BALANCE_TMP_AUTO;
				set_attr_value.subtype = 0;
				set_attr_value.value = 0x00;
				set_attr_value.req_type = USBVIDEO_REQUEST_INIT;  //set initial value(Klockwork)

				attr_req = (usbvideo_attr_msg_struct*)construct_local_para(
							sizeof(usbvideo_attr_msg_struct), TD_CTRL);
				kal_mem_cpy(&attr_req->attr_value, &set_attr_value, sizeof(USBVideo_Attr_Value));
				
				USB_Send_Msg_Ext_Queue(MOD_MED,MSG_ID_USB_MED_SET_CAMERA_ATTR_REQ, attr_req);
//				DRV_BuildPrimitive(send_ilm,MOD_DRV_HISR, MOD_MED,MSG_ID_USB_MED_SET_CAMERA_ATTR_REQ, attr_req);
//				msg_send_ext_queue(send_ilm);

				g_USBVideo_Attr_Value[0] = 0x00;
				USB_Generate_EP0Data(pep0state, pcmd, g_USBVideo_Attr_Value, 1);
				break;
			}
		}

		attr_value.req_type = (USBVIDEO_ATTR_REQUEST_TYPE)(pcmd->bRequest);

		if(attr_map[attr_index].subtype_table != NULL)	//lint !e613
		{
			subtype_size = sizeof(attr_map[attr_index].subtype_table)/sizeof(USBVideo_Attr_Sub_Map);

			for(index = 0; index< subtype_size; index++)
			{
				attr_value.subtype = attr_map[attr_index].subtype_table[index].subtype;	//lint !e613
//				g_USBVideo.camera_param->usbvideo_get_attr_value(&attr_value);/*get we need attr from camera driver */
                    		CalFeatureCtrlStruct.FeatureCtrlCode = CAL_FEATURE_GET_OPERATION;
                    		CalFeatureCtrlStruct.FeatureId = CAL_FEATURE_WEBCAM_GET_ATTR;
                    		CalFeatureCtrlStruct.FeatureInfo.FeatureStructured.pWebCamAttr = &attr_value;
                    		CalCtrl(CAL_FEATURE_CTRL, &CalFeatureCtrlStruct, NULL, 0, NULL);

				/*lint -save -e613 */
				for(index2 = 0; index2 < attr_map[attr_index].subtype_table[index].length; index2++)
				{
					g_USBVideo_Attr_Value[process_num+index2] = (attr_value.value>>(index2*8))&0xff;
				}
				/*lint -restore */

				process_num+=index2;
			}
		}
		else
		{
			attr_value.subtype = 0;
//			g_USBVideo.camera_param->usbvideo_get_attr_value(&attr_value);/*get we need attr from camera driver */
                	CalFeatureCtrlStruct.FeatureCtrlCode = CAL_FEATURE_GET_OPERATION;
                	CalFeatureCtrlStruct.FeatureId = CAL_FEATURE_WEBCAM_GET_ATTR;
                	CalFeatureCtrlStruct.FeatureInfo.FeatureStructured.pWebCamAttr = &attr_value;
                	CalCtrl(CAL_FEATURE_CTRL, &CalFeatureCtrlStruct, NULL, 0, NULL);

			if(attr_value.type == USBVIDEO_ATTRIBUTE_HUE)
			{
				if(pcmd->bRequest == USBVIDEO_GET_RES)
				{
//					hue_control = (kal_int16)attr_value.value;
//					hue_control = hue_control*100;
					g_USBVideo_Attr_Value[0] = attr_value.value&0xff;
					g_USBVideo_Attr_Value[1] = (attr_value.value>>8)&0xff;
				}
				else
				{
					/* we use 0 to 360 instead of -18000 to 18000 because of msn! */
					hue_control = attr_value.value;
//					hue_control = (hue_control-180)*100;
					g_USBVideo_Attr_Value[0] = hue_control&0xff;
					g_USBVideo_Attr_Value[1] = (hue_control>>8)&0xff;
				}
//				process_num = 2;
			}
			else
			{
				/*lint -save -e613 */
				for(index2 = 0; index2 < attr_map[attr_index].length; index2++)
				{
					g_USBVideo_Attr_Value[process_num+index2] = (attr_value.value>>(index2*8))&0xff;
				}
				/*lint -restore */
				process_num = index2;
			}
		}

//		USB_Generate_EP0Data(pep0state, pcmd, g_USBVideo_Attr_Value, process_num);
		USB_Generate_EP0Data(pep0state, pcmd, g_USBVideo_Attr_Value, pcmd->wLength);
		break;
	case USBVIDEO_GET_INFO:
		info = 0;

		if(pcmd->wIndex == (USBVIDEO_CT_ID<<8))
		{
//			info = (1<<USBVIDEO_ATTR_INFO_ASYNC_CTRL);

			if((g_USBVideo.vc_ct_support&(1<<(pcmd->wValue>>8)))!=0)
				info |= 1<<USBVIDEO_ATTR_INFO_SUPPORT_GET;

			if((g_USBVideo.vc_ct_set&(1<<(pcmd->wValue>>8)))!=0)
				info |= 1<<USBVIDEO_ATTR_INFO_SUPPORT_SET;

		}
		else if(pcmd->wIndex == (USBVIDEO_PU_ID<<8))
		{
			if((g_USBVideo.vc_pu_support&(1<<(pcmd->wValue>>8))) != 0)
				info |= 1<<USBVIDEO_ATTR_INFO_SUPPORT_GET;

			if((g_USBVideo.vc_pu_set&(1<<(pcmd->wValue>>8))) != 0)
				info |= 1<<USBVIDEO_ATTR_INFO_SUPPORT_SET;

			attr_value.type = (USBVIDEO_ATTRIBUTE_TYPE)((pcmd->wValue>>8)|0x80);

			if(attr_value.type == USBVIDEO_ATTRIBUTE_WHITE_BALANCE_TMP)
			{
				/* For WHITE_BALANCE_TMP we must take care that WHITE_BALANCE_TMP_AUTO support or not */
				attr_temp = (kal_uint32)USBVIDEO_ATTRIBUTE_WHITE_BALANCE_TMP_AUTO&(0x7f);

				if((g_USBVideo.vc_pu_support&(1<<attr_temp)) != 0)
				{
					/* Support white balance auto */
					info |= 1<<USBVIDEO_ATTR_INFO_AUTO_UPDATE;

					/* Query current state is on or off */
					if(USBVideo_Get_PU_Attr_Cur_Value(USBVIDEO_ATTRIBUTE_WHITE_BALANCE_TMP_AUTO) == KAL_TRUE)
					{
						info |= 1<<USBVIDEO_ATTR_INFO_DISBALE; /* state */
					}
				}
				else
				{
//					info |= (1<<USBVIDEO_ATTR_INFO_ASYNC_CTRL);
				}
			}
			else if(attr_value.type == USBVIDEO_ATTRIBUTE_HUE)
			{
				attr_temp = (kal_uint32)USBVIDEO_ATTRIBUTE_HUE_AUTO&(0x7f);

				if((g_USBVideo.vc_pu_support&(1<<attr_temp)) != 0)
				{
					/* Support hue auto */
					info |= 1<<USBVIDEO_ATTR_INFO_AUTO_UPDATE;

					/* Query current state is on or off */
					if(USBVideo_Get_PU_Attr_Cur_Value(USBVIDEO_ATTRIBUTE_HUE_AUTO) == KAL_TRUE)
					{
						info |= 1<<USBVIDEO_ATTR_INFO_DISBALE; /* state */
					}
				}
				else
				{
//					info |= (1<<USBVIDEO_ATTR_INFO_ASYNC_CTRL);
				}
			}
			else
			{
//				info = (1<<USBVIDEO_ATTR_INFO_ASYNC_CTRL);
			}
		}
		else
		{
			EXT_ASSERT(0, (kal_uint32)pcmd->wIndex, (kal_uint32)pcmd->bRequest, (kal_uint32)pcmd->wValue);
		}

		g_USBVideo_Attr_Value[0] = (kal_uint8)info;

		USB_Generate_EP0Data(pep0state, pcmd, g_USBVideo_Attr_Value, 1);
		break;
	case USBVIDEO_GET_LEN:
		/* not support command */
		bError = KAL_TRUE;
		g_USBVideo.error_code = USBVIDEO_ERROR_INVAILD_REQUEST;
		break;
	default:
		bError = KAL_TRUE;
		drv_trace1(TRACE_FUNC, (kal_uint32)USBVIDEO_VC_ERROR_CMD, pcmd->bRequest);
		break;
	}

	if(USB_Get_Endpoint0_State() == USB_EP0_IDLE)
	{
		USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, bError, KAL_TRUE);
	}
	else
	{
		USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, bError, KAL_FALSE);
	}
}


/* Parse video class VS specific command */
static void USBVideo_Ep0_VS_Command(Usb_Ep0_Status *pep0state, Usb_Command *pcmd)
{
	kal_bool  bError = KAL_FALSE;
	kal_uint8 info = (1<<USBVIDEO_ATTR_INFO_SUPPORT_GET)|(1<<USBVIDEO_ATTR_INFO_SUPPORT_SET);
	kal_uint32  video_index;
	kal_uint32 max_frame_size;


	switch(pcmd->wValue)
	{
	case USBVIDEO_VS_PROBE_CONTROL:
	case USBVIDEO_VS_COMMIT_CONTROL:
		if(pcmd->wIndex == g_USBVideo.vs_interface_id)
		{
			if((pcmd->bRequest == USBVIDEO_GET_CUR)&&(pcmd->wLength == 26))
			//&& ((pcmd->wLength == 26)||(pcmd->wLength == 34)) )
			{
				USB_Generate_EP0Data(pep0state, pcmd, &g_USBVideo.vs_probe_control, 26);
			}
			else if((pcmd->bRequest == USBVIDEO_GET_MAX)||(pcmd->bRequest == USBVIDEO_GET_MIN))
			{
				kal_mem_cpy((kal_uint8 *)&g_USBVideo.vs_recv_probe_control, (kal_uint8 *)&g_USBVideo.vs_probe_control, sizeof(USBVideo_Probe_Commit_Struct));

				/* Set the video index */
				if(pcmd->bRequest == USBVIDEO_GET_MAX)
					video_index = g_USBVideo.video_control.video_size_num-1;
				else
					video_index = 0;

				g_USBVideo.vs_recv_probe_control.bFrameIndex = video_index;
				g_USBVideo.vs_recv_probe_control.dwFrameInterval[0] = g_USBVideo.video_control.p_video_size_info[video_index].default_frame_interval&0xff;
				g_USBVideo.vs_recv_probe_control.dwFrameInterval[1] = (g_USBVideo.video_control.p_video_size_info[video_index].default_frame_interval>>8)&0xff;
				g_USBVideo.vs_recv_probe_control.dwFrameInterval[2] = (g_USBVideo.video_control.p_video_size_info[video_index].default_frame_interval>>16)&0xff;
				g_USBVideo.vs_recv_probe_control.dwFrameInterval[3] = (g_USBVideo.video_control.p_video_size_info[video_index].default_frame_interval>>24)&0xff;

				max_frame_size = USBVideo_Get_Max(g_USBVideo.video_control.p_video_size_info[video_index].max_frame_size,
												g_USBVideo.video_control.default_jpeg_max_size[video_index]);

				g_USBVideo.vs_recv_probe_control.dwMaxVideoFrameSize[0] = max_frame_size&0xff;
				g_USBVideo.vs_recv_probe_control.dwMaxVideoFrameSize[1] = (max_frame_size>>8)&0xff;
				g_USBVideo.vs_recv_probe_control.dwMaxVideoFrameSize[2] = (max_frame_size>>16)&0xff;
				g_USBVideo.vs_recv_probe_control.dwMaxVideoFrameSize[3] = (max_frame_size>>24)&0xff;

				USB_Generate_EP0Data(pep0state, pcmd, &g_USBVideo.vs_recv_probe_control, pcmd->wLength);
			}
			else if((pcmd->bRequest == USBVIDEO_GET_INFO)&&(pcmd->wLength == 1))
			{
				USB_Generate_EP0Data(pep0state, pcmd, &info, 1);
			}
			else if((pcmd->bRequest == USBVIDEO_SET_CUR)&&(pcmd->wLength == 26))
			//&& ((pcmd->wLength == 26)||(pcmd->wLength == 34)))
			{
				/* register handler to handle the get data*/
				USB_Register_EP0_RxHdlr(USBVideo_Set_ProbControl);
				USB_Set_Endpoint0_State(USB_EP0_RX);

				if(pcmd->wValue==USBVIDEO_VS_PROBE_CONTROL)
					g_USBVideo.probe_state = USBVIDEO_PROBE_IN;
				else
					g_USBVideo.probe_state = USBVIDEO_COMMIT_IN;
			}
			else
			{
				bError = KAL_TRUE;
			}
		}
		else
		{
			bError = KAL_TRUE;
		}
		break;
	case USBVIDEO_VS_STILL_PROBE_CONTROL:
	case USBVIDEO_VS_STILL_COMMIT_CONTROL:
		if((pcmd->bRequest == USBVIDEO_GET_CUR) && (pcmd->wIndex == g_USBVideo.vs_interface_id)
			&& (pcmd->wLength == 11))
		{
			USB_Generate_EP0Data(pep0state, pcmd, &g_USBVideo.vs_still_probe_control, 11);
		}
		else if((pcmd->bRequest == USBVIDEO_GET_INFO) && (pcmd->wIndex == g_USBVideo.vs_interface_id)
			&& (pcmd->wLength == 1))
		{
			USB_Generate_EP0Data(pep0state, pcmd, &info, 1);
		}
		else if((pcmd->bRequest == USBVIDEO_SET_CUR) && (pcmd->wIndex == g_USBVideo.vs_interface_id)
			&& (pcmd->wLength == 11))
		{
			/* register handler to handle the get data*/
			USB_Register_EP0_RxHdlr(USBVideo_Set_Still_ProbControl);
			USB_Set_Endpoint0_State(USB_EP0_RX);

			if(pcmd->wValue==USBVIDEO_VS_STILL_PROBE_CONTROL)
				g_USBVideo.still_probe_state = USBVIDEO_PROBE_IN;
			else
				g_USBVideo.still_probe_state = USBVIDEO_COMMIT_IN;
		}
		else
		{
			bError = KAL_TRUE;
		}
		break;
	case USBVIDEO_VS_STILL_IMAGE_TRIGGER_CONTROL:
		if((pcmd->bRequest == USBVIDEO_SET_CUR) && (pcmd->wIndex == g_USBVideo.vs_interface_id)
			&& (pcmd->wLength == 1))
		{
			/* register handler to handle the get data*/
			USB_Register_EP0_RxHdlr(USBVideo_Set_Still_ImageControl);
			USB_Set_Endpoint0_State(USB_EP0_RX);
		}
		else
		{
			bError = KAL_TRUE;
		}
		break;
	default:
		bError = KAL_TRUE;
		break;
	}

	if(bError == KAL_TRUE)
	{
		drv_trace1(TRACE_FUNC, (kal_uint32)USBVIDEO_VS_ERROR_CMD, pcmd->bRequest);
	}

	if(USB_Get_Endpoint0_State() == USB_EP0_IDLE)
		USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, bError, KAL_TRUE);
	else
		USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, bError, KAL_FALSE);
}


/************************************************************
	endpoint reset functions and interrupt endpoint send function
*************************************************************/

/* Intr TX endpoint reset function */
static void USBVideo_IntrTx_Reset(void)
{
	g_USBVideo.vc_intr_done = KAL_TRUE;
}


#ifdef  __WEBCAM_SUPPORT_ISO_PIPE__
/* Iso Tx endpoint reset function */
static void USBVideo_IsoTx_Reset(void)
{
	return;
}

#else

/* bulk Tx endpoint reset function */
static void USBVideo_BulkTx_Reset(void)
{
	return;
}

#endif


/* Intr Tx endpoint done handler */
static void USBVideo_IntrTx_Hdlr(void)
{
	/* To do is to set intr done flag */
	g_USBVideo.vc_intr_done = KAL_TRUE;
}

/* Send interrupt endpoint status packet */
kal_bool USBVideo_Send_Intr(void *addr,kal_uint32 len)
{
	/* This flag is used to check whether the previous sent out interrupt packet has been acked */
	if(g_USBVideo.vc_intr_done == KAL_FALSE)
	{
		return KAL_FALSE;
	}
	else
	{
		g_USBVideo.vc_intr_done = KAL_FALSE;
		USB_EPFIFOWrite(g_USBVideo.intrpipe->byEP, len, (kal_uint32*)addr);
		USB_EP_Tx_Ready(g_USBVideo.intrpipe->byEP, USB_ENDPT_INTR);
		return KAL_TRUE;
	}
}


/************************************************************
	Tx path DMA callback function and ep0 clear feature handler
*************************************************************/

/* TX incall JPEG DMA callback function */
static void USBVideo_Tx_Incall_DMA_Callback(void)
{
	USB_Dbg_Trace(USB_VIDEO_SEND_INCALL_JPEG_DMA_CALLBACK, 0, 0);

	/* In normal case DMA status should be true, it should be disabled only by USB HISR receive clear halt command */
	if(USB_DMA_Get_Run_Status(g_USBVideo.txpipe->byEP, USB_EP_TX_DIR) == KAL_TRUE)
	{
		USB_DMA_Set_Run_Status(g_USBVideo.txpipe->byEP, USB_EP_TX_DIR, KAL_FALSE);

		if(g_USBVideo.video_control.dma_type != USBVIDEO_DMA_INCALL_JPEG)
			EXT_ASSERT(0, (kal_uint32)g_USBVideo.video_control.dma_type, (kal_uint32)g_USBVideo.state, 0);

		if(g_USBVideo.video_control.sent_video_size == g_USBVideo.video_control.incall_jpeg_size)
		{
			/* the whole packet is sent */
			g_USBVideo.video_control.sent_video_size = 0;
			g_USBVideo.video_control.dma_done_type = USBVIDEO_DMA_DONE_COMPLETE;
			USB_Dbg_Trace(USB_VIDEO_SEND_INCALL_JPEG_DMA_DONE, 0, 0);
			USBVideo_Send_Msg(USBVIDEO_MSG_USB_INCALL_DMA_DONE, (kal_uint32)MOD_DRV_HISR, 0);
		}
		else
		{
			USBVideo_Send_Incall_JPEG();
		}
	}
	/* else may be diabled by USB HISR */
}

#ifdef WEBCAM_TEST_DMA_DELAY
/* GPT timeout function for incall setting*/
static void USBVideo_Test_Timeout(void *parameter)
{
	USB_GPTI_StopItem(g_USBVideo.test_timer_handle);
//	DclSGPT_Control((DCL_HANDLE)(g_USBVideo.test_timer_handle), SGPT_CMD_STOP, 0);
	if(g_USBVideo.test_enable == KAL_TRUE)
	{
		g_USBVideo.test_enable = KAL_FALSE;
		USB_DMA_Set_Run_Status(g_USBVideo.txpipe->byEP, USB_EP_TX_DIR, KAL_FALSE);
		USBVideo_Send_Video();
	}
}
#endif

/* TX video/still DMA callback function */
static void USBVideo_Tx_DMA_Callback(void)
{
	kal_uint32 index;
	kal_uint32 total_size;
	#ifdef WEBCAM_TEST_DMA_DELAY
	kal_bool bDelay = KAL_FALSE;
	SGPT_CTRL_START_T start;
	#endif


	/* In normal case DMA status should be true, it should be disabled only by USB HISR receive clear halt command */
	if(USB_DMA_Get_Run_Status(g_USBVideo.txpipe->byEP, USB_EP_TX_DIR) == KAL_TRUE)
	{
		USB_DMA_Set_Run_Status(g_USBVideo.txpipe->byEP, USB_EP_TX_DIR, KAL_FALSE);

		if(g_USBVideo.video_control.dma_type == USBVIDEO_DMA_VIDEO)
		{
			total_size = g_USBVideo.video_control.video_size[g_USBVideo.video_control.video_buffer_read_index];
		}
		else if(g_USBVideo.video_control.dma_type == USBVIDEO_DMA_STILL)
		{
			total_size = g_USBVideo.video_control.still_size;
		}
		else
		{
			total_size = 0;
			EXT_ASSERT(0, (kal_uint32)g_USBVideo.video_control.dma_type, (kal_uint32)g_USBVideo.state, 0);
		}

		/* error checking */
		if((g_USBVideo.video_control.sent_video_size == 0)||(g_USBVideo.video_control.sent_video_size > total_size))
		{
			EXT_ASSERT(0, total_size, g_USBVideo.video_control.sent_video_size, (kal_uint32)g_USBVideo.video_control.dma_type);
		}

		if(g_USBVideo.video_control.sent_video_size == total_size)
		{
			/* the whole packet is sent */
			g_USBVideo.video_control.sent_video_size = 0;
			g_USBVideo.video_control.dma_done_type = USBVIDEO_DMA_DONE_COMPLETE;

			if(g_USBVideo.video_control.dma_type == USBVIDEO_DMA_VIDEO)
				USBVideo_Send_Msg(USBVIDEO_MSG_USB_DMA_DONE, (kal_uint32)MOD_DRV_HISR, 0);
			else if(g_USBVideo.video_control.dma_type == USBVIDEO_DMA_STILL)
				USBVideo_Send_Msg(USBVIDEO_MSG_USB_STILL_DMA_DONE, (kal_uint32)MOD_DRV_HISR, 0);
			else
				EXT_ASSERT(0, (kal_uint32)g_USBVideo.video_control.dma_type, (kal_uint32)g_USBVideo.state, 0);
		}
		else
		{
			/* continue to send the left part of the current image */
			if(g_USBVideo.video_control.dma_type == USBVIDEO_DMA_STILL)
			{
				for(index = 1; index < USBVIDEO_VIDEO_BUFFER_NUMBER; index++)
				{
					/* Note that one playload length should be reserved, because the previous header
					    should be copied to the next payload */
					if(  ( (g_USBVideo.video_control.sent_video_size - USBVIDEO_MAX_PAYLOAD_LENGTH) >  (g_USBVideo.video_control.video_buffer_size*index))
						&& (	(g_USBVideo.video_control.sent_video_size - USBVIDEO_MAX_PAYLOAD_LENGTH -(USBVIDEO_MAX_PAYLOAD_LENGTH-USBVIDEO_PAYLOAD_HEADER_LENGTH))
							 <= (g_USBVideo.video_control.video_buffer_size*index)) )   /* "<=" make sure only issue message one time */
					{
						g_USBVideo.video_control.dma_done_type = USBVIDEO_DMA_DONE_COMPLETE;
						USBVideo_Send_Msg(USBVIDEO_MSG_USB_STILL_DMA_PARTIAL, index, 0);
					}
				}
			}
#if 1
		#ifdef WEBCAM_TEST_DMA_DELAY
			USB_DMA_Set_Run_Status(g_USBVideo.txpipe->byEP, USB_EP_TX_DIR, KAL_TRUE);
			USB_GPTI_StartItem(g_USBVideo.test_timer_handle, 50, USBVideo_Test_Timeout, NULL);
//			start.u2Tick = 50;
//			start.pfCallback = USBVideo_Test_Timeout;
//			start.vPara = NULL;
//			DclSGPT_Control((DCL_HANDLE)(g_USBVideo.test_timer_handle), SGPT_CMD_START, (DCL_CTRL_DATA_T*)&start);			
			g_USBVideo.test_enable = KAL_TRUE;
		#else
			USBVideo_Send_Video();
		#endif
#endif
		}
	}
	/* else may be disabled by USB HISR */
}


#ifdef  __WEBCAM_SUPPORT_ISO_PIPE__

/* For ISO pipe */
/* Endpoint 0 set interface handler */
/* Close PC application, PC will send this command */
static void USBVideo_SetInterface_Callback(Usb_Command *pcmd)
{
	/* Check if alternate setting number as 0 */
	if((pcmd->bmRequestType == USB_CMD_STDIFOUT)&&(pcmd->wValue == 0x00)
		&&(pcmd->wIndex == g_USBVideo.vs_interface_id)&&(g_USBVideo.probe_state == USBVIDEO_COMMIT_DONE))
	{
		/* In case it is in pause state, stop configuring default JPEG image*/
//		DclSGPT_Control((DCL_HANDLE)(g_USBVideo.video_control.timer_handle), SGPT_CMD_STOP, 0);
		USB_GPTI_StopItem(g_USBVideo.video_control.timer_handle);
		g_USBVideo.video_control.b_stop_timer = KAL_TRUE;
	}
}

#else

/* For bulk pipe */
/* Endpoint 0 clear halt feature handler */
/* Close PC application, PC will send this command */
static void USBVideo_ClearFeature_Callback(Usb_Command *pcmd)
{
	if((pcmd->bmRequestType == USB_CMD_STDEPOUT)&&(pcmd->wValue == USB_FTR_EPHALT)
		&& ((pcmd->wIndex& 0x0f) == g_USBVideo.txpipe->byEP))
	{
		/* In case it is in pause state, stop configuring default JPEG image*/
//		DclSGPT_Control((DCL_HANDLE)(g_USBVideo.video_control.timer_handle), SGPT_CMD_STOP, 0);
		USB_GPTI_StopItem(g_USBVideo.video_control.timer_handle);
		g_USBVideo.video_control.b_stop_timer = KAL_TRUE;

		/* Stop DMA if it is on */
		if(USB_DMA_Get_Run_Status(g_USBVideo.txpipe->byEP, USB_EP_TX_DIR) == KAL_TRUE)
		{
			USB_Stop_DMA_Channel(g_USBVideo.txpipe->byEP, USB_EP_TX_DIR);

	#ifdef  __WEBCAM_SUPPORT_ISO_PIPE__
			/* Clear FIFO, if not clear it, the next packet may be false */
			USB_Clear_Tx_EP_FIFO(g_USBVideo.txpipe->byEP, USB_ENDPT_ISO, KAL_TRUE);
	#else
			/* Clear FIFO, if not clear it, the next packet may be false */
			USB_Clear_Tx_EP_FIFO(g_USBVideo.txpipe->byEP, USB_ENDPT_BULK, KAL_TRUE);
	#endif

			/* Set DMA running state here*/
			/* When PC want to run probe commit scenario, it will issue a ep clear halt feature cmd to reset data toggle */
			/* If DMA is still running, and we run ep clear halt feature cmd, we will reset data token in DMA running, then DMA will hang!*/
			/* So we stop DMA here, but in SW state, we still want to stop DMA during probe commit scenario */
			USB_DMA_Set_Run_Status(g_USBVideo.txpipe->byEP, USB_EP_TX_DIR, KAL_TRUE);
		}
	}
}

#endif

/************************************************************
	Send video and incall JPEG file functions
*************************************************************/


/* Send incall JPEG file */
void USBVideo_Send_Incall_JPEG(void)
{
	kal_uint32 time;
	kal_uint16 sof;
	USBVideo_Payload_Header *pHeader;
	kal_uint32 sent_video_size;
//	DCL_HANDLE gpt_handle;
//	FGPT_CTRL_RETURN_COUNT_T count;


	if(USB_DMA_Get_Run_Status(g_USBVideo.txpipe->byEP, USB_EP_TX_DIR) == KAL_TRUE)
		EXT_ASSERT(0, (kal_uint32)g_USBVideo.video_control.dma_type, (kal_uint32)g_USBVideo.state, 0);

	if( (g_USBVideo.video_control.dma_type != USBVIDEO_DMA_INCALL_JPEG)
		||(g_USBVideo.video_control.incall_jpeg_buff==NULL))
		EXT_ASSERT(0, (kal_uint32)g_USBVideo.video_control.dma_type, (kal_uint32)g_USBVideo.state,
					(kal_uint32)g_USBVideo.video_control.incall_jpeg_buff);

//	time = (kal_uint32)GPT_return_current_count();
//	gpt_handle=DclFGPT_Open(DCL_GPT_FreeRUN3,0);
//	DclFGPT_Control(gpt_handle,FGPT_CMD_RETURN_COUNT,(DCL_CTRL_DATA_T*)&count);
//	time = count;
	time = USB_GPT3_return_current_count();
	
	sof = USB_GetFrameCount();

	/* copy JPEG file to buffer and fill the header */
	pHeader = (USBVideo_Payload_Header*)g_USBVideo.video_control.incall_jpeg_buff;
	pHeader->bHeaderLength = sizeof(USBVideo_Payload_Header);
	pHeader->bmHeaderInfo = (1<<USBVIDEO_PAYLOAD_PTS) | (1<<USBVIDEO_PAYLOAD_SCR)
							|(g_USBVideo.video_control.video_frame_id<<USBVIDEO_PAYLOAD_FRAME_ID|1<<USBVIDEO_PAYLOAD_EOH);

	pHeader->dwPTS[0] = time&0xff;
	pHeader->dwPTS[1] = (time>>8)&0xff;
	pHeader->dwPTS[2] = (time>>16)&0xff;
	pHeader->dwPTS[3] = (time>>24)&0xff;
	pHeader->dwSCR[0] = time&0xff;
	pHeader->dwSCR[1] = (time>>8)&0xff;
	pHeader->dwSCR[2] = (time>>16)&0xff;
	pHeader->dwSCR[3] = (time>>24)&0xff;
	pHeader->dwSCR[4] = sof&0xff;
	pHeader->dwSCR[5] = (sof>>8)&0xff;

	kal_mem_cpy( &g_USBVideo.video_control.incall_jpeg_buff[USBVIDEO_PAYLOAD_HEADER_LENGTH],
					&g_USBVideo.video_control.incall_jpeg_addr[g_USBVideo.video_control.sent_video_size],
					(USBVIDEO_MAX_PAYLOAD_LENGTH -USBVIDEO_PAYLOAD_HEADER_LENGTH));

	USB_Dbg_Trace(USB_VIDEO_SEND_INCALL_JPEG,
		g_USBVideo.video_control.incall_jpeg_buff[USBVIDEO_PAYLOAD_HEADER_LENGTH], g_USBVideo.video_control.sent_video_size);

	if(g_USBVideo.video_control.incall_jpeg_size <=
		(g_USBVideo.video_control.sent_video_size+USBVIDEO_MAX_PAYLOAD_LENGTH -USBVIDEO_PAYLOAD_HEADER_LENGTH) )
	{
		/* the last part of the image */
		/* Note that sent size must be updated before config DMA to avoid race condition,
			Once config DMA, it may switch to DMA HISR any time (before sent size is updated)*/
		sent_video_size = g_USBVideo.video_control.sent_video_size;
		g_USBVideo.video_control.sent_video_size = g_USBVideo.video_control.incall_jpeg_size;
		g_USBVideo.video_control.video_frame_id  = g_USBVideo.video_control.video_frame_id ^ 0x1;
		pHeader->bmHeaderInfo |= (1<<USBVIDEO_PAYLOAD_EOF);

#ifdef  __WEBCAM_SUPPORT_ISO_PIPE__
		USB_DMA_Setup(g_USBVideo.txpipe->byEP, USB_EP_TX_DIR, USB_ENDPT_ISO,
					(kal_uint32)g_USBVideo.video_control.incall_jpeg_buff,
					g_USBVideo.video_control.incall_jpeg_size - sent_video_size + USBVIDEO_PAYLOAD_HEADER_LENGTH,
					USBVideo_Tx_Incall_DMA_Callback, KAL_TRUE, KAL_TRUE, USB_DMA1_TYPE);
#else
		USB_DMA_Setup(g_USBVideo.txpipe->byEP, USB_EP_TX_DIR, USB_ENDPT_BULK,
					(kal_uint32)g_USBVideo.video_control.incall_jpeg_buff,
					g_USBVideo.video_control.incall_jpeg_size - sent_video_size + USBVIDEO_PAYLOAD_HEADER_LENGTH,
					USBVideo_Tx_Incall_DMA_Callback, KAL_TRUE, KAL_TRUE, USB_DMA1_TYPE);
#endif
	}
	else
	{
		/* ""Not"" the last part of the image */
		/* Note that sent size must be updated before config DMA to avoid race condition,
			Once config DMA, it may switch to DMA HISR any time (before sent size is updated)*/
		g_USBVideo.video_control.sent_video_size += (USBVIDEO_MAX_PAYLOAD_LENGTH -USBVIDEO_PAYLOAD_HEADER_LENGTH);

#ifdef  __WEBCAM_SUPPORT_ISO_PIPE__
		USB_DMA_Setup(g_USBVideo.txpipe->byEP, USB_EP_TX_DIR, USB_ENDPT_ISO,
					(kal_uint32)g_USBVideo.video_control.incall_jpeg_buff,
					USBVIDEO_MAX_PAYLOAD_LENGTH,
					USBVideo_Tx_Incall_DMA_Callback, KAL_TRUE, KAL_TRUE, USB_DMA1_TYPE);
#else
		USB_DMA_Setup(g_USBVideo.txpipe->byEP, USB_EP_TX_DIR, USB_ENDPT_BULK,
					(kal_uint32)g_USBVideo.video_control.incall_jpeg_buff,
					USBVIDEO_MAX_PAYLOAD_LENGTH,
					USBVideo_Tx_Incall_DMA_Callback, KAL_TRUE, KAL_TRUE, USB_DMA1_TYPE);
#endif
	}
}


/* Send video and still image */
void USBVideo_Send_Video(void)
{
	kal_uint32 time;
	kal_uint16 sof;
	kal_uint32 buffer_index;
	USBVideo_Payload_Header *pHeader;
	USBVideo_Payload_Header *pHeader_last;
	kal_uint8 *buff;
	kal_uint32 sent_video_size;
	static kal_uint32 total_size = 0;
//	DCL_HANDLE gpt_handle;
//	FGPT_CTRL_RETURN_COUNT_T count;

	if(USB_DMA_Get_Run_Status(g_USBVideo.txpipe->byEP, USB_EP_TX_DIR) == KAL_TRUE)
		EXT_ASSERT(0, (kal_uint32)g_USBVideo.video_control.dma_type, (kal_uint32)g_USBVideo.state, 0);

	if(g_USBVideo.video_control.dma_type == USBVIDEO_DMA_VIDEO)
	{
		/* the sending one is video */
		/* add check for race condition */
		if(g_USBVideo.video_control.sent_video_size!=0)
		{
			if(total_size!=g_USBVideo.video_control.video_size[g_USBVideo.video_control.video_buffer_read_index])
				EXT_ASSERT(0, total_size, g_USBVideo.video_control.video_size[g_USBVideo.video_control.video_buffer_read_index],
					g_USBVideo.video_control.sent_video_size);
		}

		buffer_index = g_USBVideo.video_control.video_buffer_read_index;
		total_size = g_USBVideo.video_control.video_size[buffer_index];

		if((total_size == 0) || (total_size <= g_USBVideo.video_control.sent_video_size))
		{
			EXT_ASSERT(0, g_USBVideo.video_control.sent_video_size,
					g_USBVideo.video_control.video_buffer_read_index, g_USBVideo.video_control.video_buffer_write_index);
		}
	}
	else if(g_USBVideo.video_control.dma_type == USBVIDEO_DMA_STILL)
	{
		/* the sending one is still */
		total_size = g_USBVideo.video_control.still_size;
		buffer_index = 0;
	}
	else
	{
//		total_size = 0;
		buffer_index = 0;
		EXT_ASSERT(0, (kal_uint32)g_USBVideo.video_control.dma_type, (kal_uint32)g_USBVideo.state, 0);
	}

//	time = (kal_uint32)GPT_return_current_count();	
//	gpt_handle=DclFGPT_Open(DCL_GPT_FreeRUN3,0);
//	DclFGPT_Control(gpt_handle,FGPT_CMD_RETURN_COUNT,(DCL_CTRL_DATA_T*)&count);
//	time = count;
	
	time = USB_GPT3_return_current_count();
	sof = USB_GetFrameCount();

	sent_video_size = g_USBVideo.video_control.sent_video_size;
	/* the start of packet header */
	buff = &g_USBVideo.video_control.video_buffer_addr[buffer_index][sent_video_size];
	/* current buffer header */
	pHeader = (USBVideo_Payload_Header*)buff;

	if(g_USBVideo.video_control.sent_video_size!=0)
	{
		/* previous buffer header */
		pHeader_last = (USBVideo_Payload_Header*)(buff + USBVIDEO_PAYLOAD_HEADER_LENGTH - USBVIDEO_MAX_PAYLOAD_LENGTH);
		pHeader->bHeaderLength = sizeof(USBVideo_Payload_Header);
		pHeader->bmHeaderInfo = pHeader_last->bmHeaderInfo;
		pHeader->dwPTS[0] = pHeader_last->dwPTS[0];
		pHeader->dwPTS[1] = pHeader_last->dwPTS[1];
		pHeader->dwPTS[2] = pHeader_last->dwPTS[2];
		pHeader->dwPTS[3] = pHeader_last->dwPTS[3];
	}
	else
	{
		/* toggle frame ID */
		pHeader->bmHeaderInfo |= (g_USBVideo.video_control.video_frame_id<<USBVIDEO_PAYLOAD_FRAME_ID);
	}

	pHeader->dwSCR[0] = time&0xff;
	pHeader->dwSCR[1] = (time>>8)&0xff;
	pHeader->dwSCR[2] = (time>>16)&0xff;
	pHeader->dwSCR[3] = (time>>24)&0xff;
	pHeader->dwSCR[4] = sof&0xff;
	pHeader->dwSCR[5] = (sof>>8)&0xff;

	if(total_size <= (g_USBVideo.video_control.sent_video_size + USBVIDEO_MAX_PAYLOAD_LENGTH -USBVIDEO_PAYLOAD_HEADER_LENGTH) )
	{
		/* the last part of the image */
		pHeader->bmHeaderInfo |= (1<<USBVIDEO_PAYLOAD_EOF);

		/* Note that sent size must be updated before config DMA to avoid race condition,
			Once config DMA, it may switch to DMA HISR any time (before sent size is updated)*/
		/* This means that the following serveral lines must not change order*/
		g_USBVideo.video_control.sent_video_size = total_size;
		g_USBVideo.video_control.video_frame_id  = g_USBVideo.video_control.video_frame_id ^ 0x1;

		USB_Dbg_Trace(USB_VIDEO_SEND_VIDEO_1,
			(kal_uint32)g_USBVideo.video_control.video_buffer_addr[buffer_index][sent_video_size + USBVIDEO_PAYLOAD_HEADER_LENGTH],
				(total_size - sent_video_size + USBVIDEO_PAYLOAD_HEADER_LENGTH));

#ifdef  __WEBCAM_SUPPORT_ISO_PIPE__
		USB_DMA_Setup(g_USBVideo.txpipe->byEP, USB_EP_TX_DIR,  USB_ENDPT_ISO,
					(kal_uint32)&g_USBVideo.video_control.video_buffer_addr[buffer_index][sent_video_size],
					total_size - sent_video_size + USBVIDEO_PAYLOAD_HEADER_LENGTH,
					USBVideo_Tx_DMA_Callback, KAL_TRUE, KAL_TRUE, USB_DMA1_TYPE);
#else
		USB_DMA_Setup(g_USBVideo.txpipe->byEP, USB_EP_TX_DIR,  USB_ENDPT_BULK,
					(kal_uint32)&g_USBVideo.video_control.video_buffer_addr[buffer_index][sent_video_size],
					total_size - sent_video_size + USBVIDEO_PAYLOAD_HEADER_LENGTH,
					USBVideo_Tx_DMA_Callback, KAL_TRUE, KAL_TRUE, USB_DMA1_TYPE);
#endif
	}
	else
	{
		/* ""Not"" the last part of the image */
		/* Note that sent size must be updated before config DMA to avoid race condition,
			Once config DMA, it may switch to DMA HISR any time (before sent size is updated)*/
		g_USBVideo.video_control.sent_video_size += (USBVIDEO_MAX_PAYLOAD_LENGTH -USBVIDEO_PAYLOAD_HEADER_LENGTH);

		USB_Dbg_Trace(USB_VIDEO_SEND_VIDEO_2,
			(kal_uint32)g_USBVideo.video_control.video_buffer_addr[buffer_index][sent_video_size + USBVIDEO_PAYLOAD_HEADER_LENGTH],
				USBVIDEO_MAX_PAYLOAD_LENGTH);

#ifdef  __WEBCAM_SUPPORT_ISO_PIPE__
		USB_DMA_Setup(g_USBVideo.txpipe->byEP, USB_EP_TX_DIR, USB_ENDPT_ISO,
					(kal_uint32)&g_USBVideo.video_control.video_buffer_addr[buffer_index][sent_video_size],
					USBVIDEO_MAX_PAYLOAD_LENGTH,
					USBVideo_Tx_DMA_Callback, KAL_TRUE, KAL_TRUE, USB_DMA1_TYPE);
#else
		USB_DMA_Setup(g_USBVideo.txpipe->byEP, USB_EP_TX_DIR, USB_ENDPT_BULK,
					(kal_uint32)&g_USBVideo.video_control.video_buffer_addr[buffer_index][sent_video_size],
					USBVIDEO_MAX_PAYLOAD_LENGTH,
					USBVideo_Tx_DMA_Callback, KAL_TRUE, KAL_TRUE, USB_DMA1_TYPE);
#endif
	}
}


/************************************************************
	Get and complete video/still buffer functions used by camera driver
	Note that these functions are used called in HISR context
*************************************************************/

/* camera driver use this function to get the current video buffer addr */
kal_uint8* USBVideo_Get_Video_Buffer(void)
{
	kal_uint8 *addr;
	kal_uint32 savedMask;
	// for debug
	static kal_uint8 get_video_buff_write_index;
	static kal_uint8 get_video_buff_read_index;
	static kal_bool get_video_buff_full_flag;


	USB_Dbg_Trace(USB_VIDEO_GET_VIDEO_BUF_1, (kal_uint32)g_USBVideo.state, (kal_uint32)g_USBVideo.usb_video_dma_stop);

	if(g_USBVideo.state == USBVIDEO_STATE_PAUSE)
		EXT_ASSERT(0, 0, 0, 0);

	/* !!! Should add check current time it is video state */
	if(g_USBVideo.state == USBVIDEO_STATE_STILL)
	{
		return addr = g_USBVideo.video_control.video_buffer_addr[0] + USBVIDEO_PAYLOAD_HEADER_LENGTH;
	}
	else if((g_USBVideo.state != USBVIDEO_STATE_SEND) && (g_USBVideo.state != USBVIDEO_STATE_DROP))
	{
		return NULL;
	}

	if(g_USBVideo.usb_video_dma_stop == KAL_TRUE)
	{
		return addr = g_USBVideo.video_control.video_buffer_addr[0] + USBVIDEO_PAYLOAD_HEADER_LENGTH;
	}

	if(g_USBVideo.video_control.video_buffer_addr[0]==NULL)
		ASSERT(0);

	savedMask = SaveAndSetIRQMask();
	if(g_USBVideo.video_control.video_buffer_full == KAL_TRUE)
	{
		g_USBVideo.video_control.video_buffer_full = KAL_FALSE;
		/* back one write index */
		if(g_USBVideo.video_control.video_buffer_write_index == 0)
			g_USBVideo.video_control.video_buffer_write_index = USBVIDEO_VIDEO_BUFFER_NUMBER - 1;
		else
			g_USBVideo.video_control.video_buffer_write_index--;
	}

#ifdef  __MTK_INTERNAL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

	addr = g_USBVideo.video_control.video_buffer_addr[g_USBVideo.video_control.video_buffer_write_index];
	addr += USBVIDEO_PAYLOAD_HEADER_LENGTH;	/* header offset */

	g_USBVideo.is_get_buffer_after_change_size = KAL_TRUE;

	RestoreIRQMask(savedMask);

	drv_trace4(TRACE_FUNC, (kal_uint32)USBVIDEO_GET_BUFFER, get_video_buff_read_index,
					get_video_buff_write_index, (kal_uint32)get_video_buff_full_flag, 0);

	USB_Dbg_Trace(USB_VIDEO_GET_VIDEO_BUF_2, (kal_uint32)get_video_buff_read_index, (kal_uint32)get_video_buff_write_index);

	return addr;
}


/* camera driver use this function to notify USB driver that it complete filling this buffer  */
void USBVideo_Complete_Video_Buffer
	(kal_uint8* addr, kal_uint32 size, kal_uint32 time, USBVIDEO_VIDEO_SIZE_TYPE video_size_type)
{
	USBVideo_Payload_Header *pHeader;
	kal_uint32 savedMask;
	// for debug
	static kal_uint8 complete_video_buff_write_index;
	static kal_uint8 complete_video_buff_read_index;
	static kal_bool complete_video_buff_full_flag;


	USB_Dbg_Trace(USB_VIDEO_COMPLETE_VIDEO_BUF_1, (kal_uint32)g_USBVideo.state, size);

	/* !!! Should add check current time it is video state */
	if(((g_USBVideo.state != USBVIDEO_STATE_SEND)&&(g_USBVideo.state != USBVIDEO_STATE_DROP))||
		(g_USBVideo.usb_video_dma_stop == KAL_TRUE)||(g_USBVideo.is_get_buffer_after_change_size == KAL_FALSE))
	{
		USB_Dbg_Trace(USB_VIDEO_COMPLETE_VIDEO_BUF_3, (kal_uint32)g_USBVideo.state, size);
		return ;
	}

	/* This will be executed in camera HISR, mask IRQ to avoid race condition with USB HISR*/
	if(g_USBVideo.commit_video_index == (kal_uint8)video_size_type)
	{
		if(g_USBVideo.state == USBVIDEO_STATE_DROP)
			g_USBVideo.state = USBVIDEO_STATE_SEND;
	}
	else
	{
		/* ignore the unmatched size packet */
		USB_Dbg_Trace(USB_VIDEO_COMPLETE_VIDEO_BUF_4, (kal_uint32)video_size_type, (kal_uint32)g_USBVideo.commit_video_index);
		return;
	}

	// avoid USB Recieve Still command from PC
	//double confirm Video state  & disable USB Interrupt
	IRQMask(IRQ_USB_CODE);

	if((g_USBVideo.state == USBVIDEO_STATE_SEND)||(g_USBVideo.state == USBVIDEO_STATE_DROP))
	{
			/* chek the returned addr matches state machine check */
		if((addr-USBVIDEO_PAYLOAD_HEADER_LENGTH)!=g_USBVideo.video_control.video_buffer_addr[g_USBVideo.video_control.video_buffer_write_index])
			EXT_ASSERT(0, (kal_uint32)addr, (kal_uint32)g_USBVideo.video_control.video_buffer_addr[g_USBVideo.video_control.video_buffer_write_index], 0);

		/* check the still size */
		if(((kal_uint32)video_size_type > g_USBVideo.video_control.video_size_num))
			EXT_ASSERT(0, (kal_uint32)video_size_type, (kal_uint32)g_USBVideo.video_control.video_size_num, 0);

		if(size > g_USBVideo.video_control.p_video_size_info[(kal_uint32)video_size_type - 1].max_frame_size)
			EXT_ASSERT(0, size, g_USBVideo.video_control.p_video_size_info[(kal_uint32)video_size_type - 1].max_frame_size, (kal_uint32)video_size_type);

		g_USBVideo.video_control.video_size[g_USBVideo.video_control.video_buffer_write_index] = size;
		pHeader = (USBVideo_Payload_Header*)g_USBVideo.video_control.video_buffer_addr[g_USBVideo.video_control.video_buffer_write_index];
		pHeader->dwPTS[0] = time&0xff;
		pHeader->dwPTS[1] = (time>>8)&0xff;
		pHeader->dwPTS[2] = (time>>16)&0xff;
		pHeader->dwPTS[3] = (time>>24)&0xff;
		pHeader->bHeaderLength = sizeof(USBVideo_Payload_Header);
		pHeader->bmHeaderInfo = (1<<USBVIDEO_PAYLOAD_PTS)|(1<<USBVIDEO_PAYLOAD_SCR)|(1<<USBVIDEO_PAYLOAD_EOH);
		/* dwSCR will be filled when configring DMA to send */

		savedMask = SaveAndSetIRQMask();
		/* Get buffer function not move W pointer, only complete will move W pointer */
		g_USBVideo.video_control.video_buffer_write_index++;

		if(g_USBVideo.video_control.video_buffer_write_index == USBVIDEO_VIDEO_BUFFER_NUMBER)
			g_USBVideo.video_control.video_buffer_write_index = 0;

		if(g_USBVideo.video_control.video_buffer_write_index == g_USBVideo.video_control.video_buffer_read_index)
			g_USBVideo.video_control.video_buffer_full = KAL_TRUE;

		complete_video_buff_write_index = g_USBVideo.video_control.video_buffer_write_index;
		complete_video_buff_read_index = g_USBVideo.video_control.video_buffer_read_index;
		complete_video_buff_full_flag = g_USBVideo.video_control.video_buffer_full;

		RestoreIRQMask(savedMask);

		drv_trace4(TRACE_FUNC, (kal_uint32)USBVIDEO_COMPLETE_BUFFER, complete_video_buff_read_index,
						complete_video_buff_write_index, (kal_uint32)complete_video_buff_full_flag, 0);

		USB_Dbg_Trace(USB_VIDEO_COMPLETE_VIDEO_BUF_2, (kal_uint32)complete_video_buff_read_index, (kal_uint32)complete_video_buff_write_index);

		/* Send message to notify USB task */
		if(g_USBVideo.video_control.send_video_msg == KAL_TRUE)
		{
			g_USBVideo.video_control.send_video_msg = KAL_FALSE; /* will be set TRUE when DMA done */
			USBVideo_Send_Msg(USBVIDEO_MSG_USB_COMPLETE_VIDEO, 0, 0);
		}
	}

	if(USB_Get_UnMask_Irq() == KAL_TRUE)
		IRQUnmask(IRQ_USB_CODE);

}


/* camera driver use this function to get the current still buffer addr */
kal_uint8* USBVideo_Get_Still_Buffer(void)
{
	USB_Dbg_Trace(USB_VIDEO_GET_STILL_BUF, (kal_uint32)g_USBVideo.state, (kal_uint32)g_USBVideo.still_probe_state);

	if(g_USBVideo.state == USBVIDEO_STATE_STOP)
		return NULL;

	if( (g_USBVideo.state!=USBVIDEO_STATE_STILL) ||
		(USB_DMA_Get_Run_Status(g_USBVideo.txpipe->byEP, USB_EP_TX_DIR) == KAL_TRUE))
		EXT_ASSERT(0, (kal_uint32)g_USBVideo.state, (kal_uint32)g_USBVideo.video_control.video_buffer_read_index,
					(kal_uint32)g_USBVideo.video_control.video_buffer_write_index);

	if(g_USBVideo.video_control.video_buffer_addr[0]==NULL)
		EXT_ASSERT(0, 0, 0, 0);

//	addr = g_USBVideo.video_control.video_buffer_addr[0];
//	addr += USBVIDEO_PAYLOAD_HEADER_LENGTH;	/* header offset */

	return (kal_uint8 *)(g_USBVideo.video_control.video_buffer_addr[0] + USBVIDEO_PAYLOAD_HEADER_LENGTH);
}


/* camera driver use this function to notify USB driver that it complete filling this buffer  */
void USBVideo_Complete_Still_Buffer
	(kal_uint8* addr, kal_uint32 size, kal_uint32 time, USBVIDEO_STILL_SIZE_TYPE still_size_type)
{
	USBVideo_Payload_Header *pHeader;


	USB_Dbg_Trace(USB_VIDEO_COMPLETE_STILL_BUF, (kal_uint32)g_USBVideo.state, (kal_uint32)g_USBVideo.usb_video_dma_stop);

	if((g_USBVideo.state == USBVIDEO_STATE_STOP)||(g_USBVideo.usb_video_dma_stop == KAL_TRUE))
		return;

	if( (g_USBVideo.state != USBVIDEO_STATE_STILL) ||
		(USB_DMA_Get_Run_Status(g_USBVideo.txpipe->byEP, USB_EP_TX_DIR) == KAL_TRUE))
		EXT_ASSERT(0, (kal_uint32)g_USBVideo.state, (kal_uint32)g_USBVideo.video_control.video_buffer_read_index,
					(kal_uint32)g_USBVideo.video_control.video_buffer_write_index);

	/* chek the returned addr matches state machine check */
	if((addr-USBVIDEO_PAYLOAD_HEADER_LENGTH)!=g_USBVideo.video_control.video_buffer_addr[0])
		EXT_ASSERT(0, (kal_uint32)addr, (kal_uint32)g_USBVideo.video_control.video_buffer_addr[0], 0);

	/* check the still size */
	if(((kal_uint32)still_size_type > g_USBVideo.video_control.still_size_num))
		EXT_ASSERT(0, (kal_uint32)still_size_type, (kal_uint32)g_USBVideo.video_control.still_size_num, 0);

	if(size>g_USBVideo.video_control.p_still_size_info[(kal_uint32)still_size_type - 1].max_frame_size)
		EXT_ASSERT(0, size, g_USBVideo.video_control.p_still_size_info[(kal_uint32)still_size_type - 1].max_frame_size, (kal_uint32)still_size_type);

	if(g_USBVideo.video_control.video_buffer_write_index!=0)
		EXT_ASSERT(0, (kal_uint32)g_USBVideo.state, (kal_uint32)g_USBVideo.video_control.video_buffer_read_index,
					(kal_uint32)g_USBVideo.video_control.video_buffer_write_index);

	g_USBVideo.video_control.still_size = size;
	pHeader = (USBVideo_Payload_Header*)g_USBVideo.video_control.video_buffer_addr[0];
	pHeader->dwPTS[0] = time&0xff;
	pHeader->dwPTS[1] = (time>>8)&0xff;
	pHeader->dwPTS[2] = (time>>16)&0xff;
	pHeader->dwPTS[3] = (time>>24)&0xff;
	pHeader->bHeaderLength = sizeof(USBVideo_Payload_Header);
	pHeader->bmHeaderInfo = (1<<USBVIDEO_PAYLOAD_PTS)|(1<<USBVIDEO_PAYLOAD_SCR)|(1<<USBVIDEO_PAYLOAD_STILL)|(1<<USBVIDEO_PAYLOAD_EOH);
	/* dwSCR will be filled when configring DMA to send */

	USBVideo_Send_Msg(USBVIDEO_MSG_USB_COMPLETE_STILL, 0, 0);
}


/************************************************************
	Preview resolution information provided by camera and used by MMI
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

void USBVideo_Set_Default_JPEG_Max_Size(kal_uint8 index, kal_uint32 max_size)
{
	g_USBVideo.video_control.default_jpeg_max_size[index] = max_size;
	g_USBVideo.video_control.b_set_default_jpeg_max_size[index] = KAL_TRUE;
}


#endif /* WEBCAM_SUPPORT */


