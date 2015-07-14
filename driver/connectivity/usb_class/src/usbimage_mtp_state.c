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
 *   usbimage_mtp_state.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  This file implements the state machine of USB task and related command handler functions for MEDIA TRANSFER PROTOCOL (MTP).
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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

#ifdef __MTP_ENABLE__

//#include "kal_non_specific_general_types.h"
//#include "kal_release.h"
#include "kal_public_api.h"
#include "kal_trace.h"
    
#include "drv_comm.h"
//#include "intrCtrl.h"
//#include "stack_common.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "kal_public_api.h" //#include "stack_ltlcom.h" //MSBB change #include "app_ltlcom.h"
//#include "app_buff_alloc.h"
//#include "usb_comm.h"
#include "drvsignals.h"

//#include "usb_drv.h"
#include "usb_adap.h"
#include "usb.h"
//#include "usb_resource.h"

#include "usb_custom.h"
#include "usbimage_drv.h"
#include "usbimage_mtp_state.h"
#include "usb_debug_tool.h"
#include "usb_trc.h"

#include "kal_general_types.h"
#include "kal_public_api.h"


/* Global variables */
#pragma arm section zidata = "NONCACHEDZI", rwdata = "NONCACHEDRW"
__align(4) USB_IMAGE_CONTAINER_HEADER g_USB_Image_Data_Header;
#pragma arm section zidata, rwdata


USB_IMAGE_MTP_Struct g_MTPImage;


/* static functions */
static void USB_MTP_Image_DATA_RX_Hdlr(void);
static void USB_MTP_Image_DATA_TX_Hdlr(void);

static void USB_MTP_Image_Operation(void);
static void USB_MTP_Image_Operation_Rsp_Hdlr(local_para_struct *buf);
static void USB_MTP_No_Data_Phase_Cmd_Hdlr(void);
static void USB_MTP_Get_Data_Phase_Cmd_Hdlr(void);


static void USB_MTP_No_Data_From_MTP_Hdlr(usb_mtp_operation_rsp_struct *ptr);
static void USB_MTP_TX_Data_From_MTP_Hdlr(usb_mtp_operation_rsp_struct *ptr, kal_bool b_is_first_rsp);
static void USB_MTP_TX_DMA_Callback_Hdlr(void);
static void USB_MTP_RX_Data_To_MTP_Hdlr(usb_mtp_operation_rsp_struct *ptr);
static void USB_MTP_RX_Data_Callback_Hdlr(void);

/* USB handles MTP commands */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
static void USB_MTP_Cmd_Get_Device_Info(void);
static void USB_MTP_Cmd_Get_Device_Prop_Desc(void);
static void USB_MTP_Cmd_Get_Device_Prop_Value(void);
static void USB_MTP_Cmd_Set_Device_Prop_Value(void);
static void USB_MTP_Cmd_Unknown(void);


/************************************************************
	Parse all messages to USB task for MTP state
*************************************************************/
void USB_MTP_Parse_MTP_Meg(ilm_struct *p_recv_ilm)
{
	USB_Dbg_Trace(USB_IMAGE_PARSE_MTP_MSG, (kal_uint32)g_USBImage.mtp_state, 0);

	/* "Disable" state is set when USB sent the disable msg */
	if(g_USBImage.mtp_state != IMAGE_MTP_ENABLE)
		return;

	if(g_USBImage.b_host_suspend == KAL_TRUE)
	{
		g_USBImage.b_host_suspend = KAL_FALSE;
		return;
	}

	USB_MTP_Image_Operation_Rsp_Hdlr(p_recv_ilm->local_para_ptr);
}


void USB_MTP_Parse_MTP_Event_Meg(ilm_struct *p_recv_ilm)
{
	usb_mtp_event_ind_struct *ptr = (usb_mtp_event_ind_struct *)p_recv_ilm->local_para_ptr;


	USB_Dbg_Trace(USB_IMAGE_PARSE_MTP_EVENT_MSG, (kal_uint32)g_USBImage.mtp_state, ptr->event);

	if((usb_mtp_event_enum)ptr->event == USB_MTP_EVENT_NORMAL)
	{
		/* Memory card in/out event */
		g_USBImage.image_event.ContainerLength = USB_IMAGE_RES_1_PARA;
		g_USBImage.image_event.Code = ptr->event_code;
		g_USBImage.image_event.TransactionID = 0xffffffff;
		g_USBImage.image_event.Parameter1 = ptr->params[0];

		USB_Image_Send_Intr();
	}
	else if((usb_mtp_event_enum)ptr->event == USB_MTP_EVENT_ABORT)
	{
		/* Abort response */
		if(g_USBImage.mtp_state == IMAGE_MTP_HOST_CANCEL)
		{
			/* User press cancel */
			g_USBImage.mtp_state = IMAGE_MTP_ENABLE;
		}
		else if(g_USBImage.mtp_state == IMAGE_MTP_HOST_SUSPEND)
		{
			/* PC suspend, but cable still in */
			g_USBImage.mtp_state = IMAGE_MTP_ENABLE;

			USB_Dbg_Trace(USB_MTP_CLOSE_SESSION, 2, 0);
//			g_USBImage.is_session_open = KAL_FALSE;

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

		if(g_USBImage.b_delay_disable_mtp_msg_for_req == KAL_TRUE)
		{
			g_USBImage.b_delay_disable_mtp_msg_for_req = KAL_FALSE;

			/* Send MTP disable msg to MTP task */
			USB_MTP_Image_Send_Msg(USB_MTP_IMAGE_MSG_DISABLE_REQ);
		}
	}
}


void USB_MTP_Parse_USB_Meg(ilm_struct *p_recv_ilm)
{
	switch(p_recv_ilm->msg_id)
	{
	case MSG_ID_USB_MTPIMAGE_DATA_RX_DONE_CONF:
		/* Received data from USB_HISR */
		USB_MTP_Image_DATA_RX_Hdlr();
		break;

	case MSG_ID_USB_MTPIMAGE_DATA_TX_DONE_CONF:
		/* transmitted data from DMA callback*/
		USB_MTP_Image_DATA_TX_Hdlr();
		break;

	case MSG_ID_USB_MTPIMAGE_CANCEL_IND:
		USB_Stop_DMA_Channel(g_USBImage.txpipe->byEP, USB_EP_TX_DIR);
		/* Clear FIFO, but not reset data toggle */
		USB_Clear_Tx_EP_FIFO(g_USBImage.txpipe->byEP, USB_ENDPT_BULK, KAL_FALSE);
		USB_Clear_Rx_EP_FIFO(g_USBImage.rxpipe->byEP, USB_ENDPT_BULK, KAL_FALSE);

		/* Send abort message to MTP task here to prevent USB send abort and then send req to MTP task */
		USB_MTP_Image_Send_Msg(USB_MTP_IMAGE_MSG_HOST_ABORT_IND);
		break;

	case MSG_ID_USB_MTPIMAGE_RESET_IND:
		/* Reset from reset signal */
		g_USBImage.state = USB_IMAGE_CMD_RX;
		USB_Image_Reset_Hdlr();
		break;

	default:
		EXT_ASSERT(0, (kal_uint32)p_recv_ilm->msg_id, (kal_uint32)g_USBImage.state, 0);
		break;
	}
}


/* RX path state machine */
static void USB_MTP_Image_DATA_RX_Hdlr(void)
{
	switch(g_USBImage.state)
	{
	case USB_IMAGE_CMD_RX:
		if(g_USBImage.mtp_state != IMAGE_MTP_HOST_CANCEL)
		{
			/* After DRV_HISR send DATA_RX_DONE_CONF msg, and USB receives ep0 cancel command, then it will meet this condition. */
			/* Parse MTP cmds */
			USB_MTP_Image_Operation();
		}
		break;

	case USB_IMAGE_DATA_RX:
		/* Received data from USB HISR or DMA callback */
		if(g_USBImage.total_rx_bytes != 0)
		{
			/* Received data from DMA callback */
			g_USBImage.current_rx_bytes += g_USBImage.rxpipe->nBuffLen;

			if(g_USBImage.buffer_rw_bytes[g_USBImage.buffer_write_index] != 0)
				ASSERT(0);

			g_USBImage.buffer_rw_bytes[g_USBImage.buffer_write_index] = g_USBImage.rxpipe->nBuffLen;
		}

		USB_MTP_RX_Data_Callback_Hdlr();
		break;

	case USB_IMAGE_RESPONSE:
		g_USBImage.state = USB_IMAGE_CMD_RX;
		USB_MTP_Cmd_Set_Device_Prop_Value();
		break;

	case USB_IMAGE_DATA_TX:
	default:
		EXT_ASSERT(0, (kal_uint32)g_USBImage.state, 0, 0);
		break;
	}
}


/* TX path state machine */
static void USB_MTP_Image_DATA_TX_Hdlr(void)
{
	/* Stop DMA running status */
	USB_DMA_Set_Run_Status(g_USBImage.txpipe->byEP, USB_EP_TX_DIR, KAL_FALSE);

	switch(g_USBImage.state)
	{
	/* Send Response */
	case USB_IMAGE_RESPONSE:
		g_USBImage.state = USB_IMAGE_CMD_RX;

	#ifdef __USB_HS_ENABLE__
		/*  Check if already sent out the (max pkt size)*N bytes */
		if(USB_Is_High_Speed() == KAL_TRUE)
		{
			/*  Check if sent out the 512N bytes */
			if((g_USBImage.total_tx_bytes%USB_EP_BULK_MAXP_HS) == 0)
			{
				USB_Send_Null_Packet(g_USBImage.txpipe->byEP);
			}
		}
		else
		{
			/*  Check if sent out the 64N bytes */
			if((g_USBImage.total_tx_bytes%USB_EP_BULK_MAXP_FS) == 0)
			{
				USB_Send_Null_Packet(g_USBImage.txpipe->byEP);
			}
		}
	#else
		/*  Check if sent out the (max pkt size)*N bytes */
		if((g_USBImage.total_tx_bytes%USB_EP_BULK_MAXP) == 0)
		{
			USB_Send_Null_Packet(g_USBImage.txpipe->byEP);
		}
	#endif

		USB_Image_ReturnTx(&g_USB_Image_Response, g_USB_Image_Response.ContainerLength);
		break;

	case USB_IMAGE_DATA_TX:
		if(g_USBImage.buffer_rw_bytes[g_USBImage.buffer_read_index] == 0)
			ASSERT(0);
		g_USBImage.buffer_rw_bytes[g_USBImage.buffer_read_index] = 0;

		g_USBImage.buffer_read_index ^= 1;

		USB_MTP_TX_DMA_Callback_Hdlr();
		break;

	case USB_IMAGE_CMD_RX:
		if(g_USBImage.mtp_state != IMAGE_MTP_HOST_CANCEL)
		{
			/* After DRV_HISR send DATA_TX_DONE_CONF msg, and USB receives ep0 cancel command, then it will meet this condition. */
			EXT_ASSERT(0, (kal_uint32)g_USBImage.state, 0, 0);
		}
		break;

	case USB_IMAGE_DATA_RX:
	default:
		EXT_ASSERT(0, (kal_uint32)g_USBImage.state, 0, 0);
		break;
	}
}


static void USB_MTP_Image_Operation_Rsp_Hdlr(local_para_struct *buf)
{
	usb_mtp_operation_rsp_struct *ptr = (usb_mtp_operation_rsp_struct *)buf;
	kal_bool b_first_rsp = KAL_FALSE;


	USB_Dbg_Trace(USB_MTP_RECEIVE_RSP_MSG, ptr->op_code, g_USBImage.image_cmd.Code);

	if(ptr->op_code != g_USBImage.image_cmd.Code)
	{
		EXT_ASSERT(0, (kal_uint32)g_USBImage.image_cmd.Code, (kal_uint32)ptr->op_code, 0);
	}

	if(((ptr->rsp_code>>8) != 0x20)&&((ptr->rsp_code>>8) != 0xA8))
		EXT_ASSERT(0, ptr->rsp_code, 0, 0);

	switch(g_USBImage.state)
	{
	case USB_IMAGE_RESPONSE:
		/* MTP cmd without data phase */
		USB_MTP_No_Data_From_MTP_Hdlr(ptr);
		break;

	case USB_IMAGE_DATA_RX:
		if((g_USBImage.buffer_rw_bytes[g_USBImage.buffer_read_index] == 0)&&(g_USBImage.total_rx_bytes != 0))
			ASSERT(0);

		g_USBImage.buffer_rw_bytes[g_USBImage.buffer_read_index] = 0;

		g_USBImage.buffer_read_index ^= 1;

		USB_MTP_RX_Data_To_MTP_Hdlr(ptr);
		break;

	case USB_IMAGE_DATA_TX:
		if(g_USBImage.buffer_rw_bytes[g_USBImage.buffer_write_index] != 0)
			ASSERT(0);

		if((((usb_mtp_result_enum)ptr->result_code == USB_MTP_RESULT_OK)||((usb_mtp_result_enum)ptr->result_code == USB_MTP_RESULT_CONTINUE))
			&&(ptr->rsp_code == MTP_OK))
		{
			g_USBImage.buffer_rw_bytes[g_USBImage.buffer_write_index] = ptr->data_size;
		}

		if(g_USBImage.b_is_first_rsp == KAL_TRUE)
		{
			g_USBImage.b_is_first_rsp = KAL_FALSE;
			b_first_rsp = KAL_TRUE;
		}

		USB_MTP_TX_Data_From_MTP_Hdlr(ptr, b_first_rsp);
		break;

	case USB_IMAGE_CMD_RX:
		/* When code run to here means USB task indeed want MTP send response msg, but state is gone because some reasons */
		/* Therefore we should not assert here */
		USB_Dbg_Trace(USB_MTP_RESPONSE_MSG_WITH_WRONG_STATE, (kal_uint32)g_USBImage.state, 0);
		drv_trace1(TRACE_FUNC, (kal_uint32)USB_MTP_RESPONSE_WARNING, (kal_uint32)g_USBImage.state);
		break;

	default:
		EXT_ASSERT(0, (kal_uint32)g_USBImage.state, 0, 0);
		break;
	}
}

/************************************************************
	Utility functions
*************************************************************/
kal_bool USB_MTP_Is_RX_Cmd(kal_uint16 cmd_code)
{
	kal_bool cmd_is_rx_cmd;


	switch(cmd_code)
	{
	case MTP_SEND_OBJECT_INFO:
	case MTP_SEND_OBJECT:
	case MTP_SET_DEVICE_PROP_VALUE:
	case MTP_SET_OBJECT_PROP_VALUE:
	case MTP_SET_OBJECT_REFERENCES:
		cmd_is_rx_cmd = KAL_TRUE;
		break;
	default:
		cmd_is_rx_cmd = KAL_FALSE;
		break;
	}

	return cmd_is_rx_cmd;
}


/************************************************************
	MTP command handler utilities
*************************************************************/
static void USB_MTP_No_Data_Phase_Cmd_Hdlr(void)
{
	/* Only send Response */
	g_USBImage.state = USB_IMAGE_RESPONSE;

	g_USBImage.data_total_size = 0;
	g_USBImage.data_pool_ptr = NULL;
	g_USBImage.data_pool_size = 0;
	g_USBImage.data_size = 0;

	/* Send msg to MTP */
	USB_MTP_Image_Send_Msg(USB_MTP_IMAGE_MSG_OPERATION_REQ);
}


static void USB_MTP_Get_Data_Phase_Cmd_Hdlr(void)
{
	g_USBImage.state = USB_IMAGE_DATA_TX;

	g_USBImage.buffer_read_index = 0;
	g_USBImage.buffer_write_index = 0;
	g_USBImage.buffer_rw_bytes[0] = 0;
	g_USBImage.buffer_rw_bytes[1] = 0;

	g_USBImage.data_pool_ptr = (kal_uint8 *)g_USBImage.mtp_image_buffer->data_buffer[g_USBImage.buffer_write_index];
	g_USBImage.data_pool_size = USB_IMAGE_MTP_MAX_TX_BUFFERSIZE;

	g_USBImage.b_is_first_rsp = KAL_TRUE;

	/* Send msg to MTP */
	USB_MTP_Image_Send_Msg(USB_MTP_IMAGE_MSG_OPERATION_REQ);
}


/************************************************************
	Parse MTP command functions
*************************************************************/
/* Parse MTP operations */
static void USB_MTP_Image_Operation(void)
{
	if(g_USBImage.image_cmd.ContainerType != USB_IMAGE_COMMAND_BLOCK)
	{
		EXT_ASSERT(0, g_USBImage.image_cmd.ContainerType, 0, 0);
	}

	USB_Dbg_Trace(USB_MTP_IMAGE_OP_HDLR, g_USBImage.current_transactionID, 0);

	if((g_USBImage.is_session_open == KAL_FALSE)&&(
		(g_USBImage.image_cmd.Code != MTP_GET_DEVICE_INFO)&&(g_USBImage.image_cmd.Code != MTP_OPEN_SESSION)))
	{
		USB_Dbg_Trace(USB_IMAGE_SESSION_NOT_OPEN_ERROR, 0, 0);
		/* Only Send Response */
		g_USBImage.state = USB_IMAGE_CMD_RX;

		g_USB_Image_Response.ContainerLength = USB_IMAGE_CONTAINER_LENGTH;
		g_USB_Image_Response.Code = MTP_SESSION_NOT_OPEN;
		g_USB_Image_Response.TransactionID = g_USBImage.current_transactionID;
		USB_Image_ReturnTx(&g_USB_Image_Response, USB_IMAGE_CONTAINER_LENGTH);
		return;
	}

	/* Parse MTP commands */
	switch(g_USBImage.image_cmd.Code)
	{
		/* MTP cmds handled by USB task*/
	case MTP_GET_DEVICE_INFO:
		USB_Dbg_Trace(USB_MTP_GET_DEVICE_INFO, 0, 0);
		USB_MTP_Cmd_Get_Device_Info();
		break;
	case MTP_GET_DEVICE_PROP_DESC:
		USB_Dbg_Trace(USB_MTP_GET_DEVICE_PROP_DESC, g_USBImage.image_cmd.Parameter1, 0);
		USB_MTP_Cmd_Get_Device_Prop_Desc();
		break;
	case MTP_GET_DEVICE_PROP_VALUE:
		USB_Dbg_Trace(USB_MTP_GET_DEVICE_PROP_VALUE, g_USBImage.image_cmd.Parameter1, 0);
		USB_MTP_Cmd_Get_Device_Prop_Value();
		break;
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
#else
		/* MTP cmds without data phase */
	case MTP_OPEN_SESSION:
		USB_Dbg_Trace(USB_MTP_OPEN_SESSION, g_USBImage.image_cmd.Parameter1, 0);
		g_USBImage.is_session_open = KAL_TRUE;
		USB_MTP_No_Data_Phase_Cmd_Hdlr();
		break;
	case MTP_CLOSE_SESSION:
		USB_Dbg_Trace(USB_MTP_CLOSE_SESSION, 0, 0);
		g_USBImage.is_session_open = KAL_FALSE;
		USB_MTP_No_Data_Phase_Cmd_Hdlr();
		break;
#endif
	case MTP_DELETE_OBJECT:
		USB_Dbg_Trace(USB_MTP_DELETE_OBJECT, g_USBImage.image_cmd.Parameter1, g_USBImage.image_cmd.Parameter2);
		USB_MTP_No_Data_Phase_Cmd_Hdlr();
		break;
	case MTP_GET_NUM_OBJECTS:
		USB_Dbg_Trace(USB_MTP_GET_NUM_OBJECTS,  g_USBImage.image_cmd.Parameter1,  g_USBImage.image_cmd.Parameter2);
		USB_MTP_No_Data_Phase_Cmd_Hdlr();
		break;
	case MTP_SKIP:
		USB_Dbg_Trace(USB_MTP_SKIP, g_USBImage.image_cmd.Parameter1, 0);
		ASSERT(0);
		break;

		/* MTP cmds with TX phase cmds */
	case MTP_GET_STORAGE_IDS:
		USB_Dbg_Trace(USB_MTP_GET_STORAGE_IDS, 0, 0);
		USB_MTP_Get_Data_Phase_Cmd_Hdlr();
		break;
	case MTP_GET_STORAGE_INFO:
		USB_Dbg_Trace(USB_MTP_GET_STORAGE_INFO,  g_USBImage.image_cmd.Parameter1, 0);
		USB_MTP_Get_Data_Phase_Cmd_Hdlr();
		break;
	case MTP_GET_OBJECT_HANDLES:
		USB_Dbg_Trace(USB_MTP_GET_OBJECT_HANDLES, g_USBImage.image_cmd.Parameter1, g_USBImage.image_cmd.Parameter2);
		USB_MTP_Get_Data_Phase_Cmd_Hdlr();
		break;
	case MTP_GET_OBJECT_INFO:
		USB_Dbg_Trace(USB_MTP_GET_OBJECT_INFO, g_USBImage.image_cmd.Parameter1, 0);
		USB_MTP_Get_Data_Phase_Cmd_Hdlr();
		break;
	case MTP_GET_OBJECT:
		USB_Dbg_Trace(USB_MTP_GET_OBJECT, g_USBImage.image_cmd.Parameter1, 0);
		USB_MTP_Get_Data_Phase_Cmd_Hdlr();
		break;
	case MTP_GET_PARTIAL_OBJECT:
		USB_Dbg_Trace(USB_MTP_GET_PARTIAL_OBJECT, g_USBImage.image_cmd.Parameter1, g_USBImage.image_cmd.Parameter2);
		USB_MTP_Get_Data_Phase_Cmd_Hdlr();
		break;
	case MTP_GET_OBJECT_PROPS_SUPPORTED:
		USB_Dbg_Trace(USB_MTP_GET_OBJECT_PROPS_SUPPORTED, g_USBImage.image_cmd.Parameter1, 0);
		USB_MTP_Get_Data_Phase_Cmd_Hdlr();
		break;
	case MTP_GET_OBJECT_PROP_DESC:
		USB_Dbg_Trace(USB_MTP_GET_OBJECT_PROP_DESC, g_USBImage.image_cmd.Parameter1, g_USBImage.image_cmd.Parameter2);
		USB_MTP_Get_Data_Phase_Cmd_Hdlr();
		break;
	case MTP_GET_OBJECT_PROP_VALUE:
		USB_Dbg_Trace(USB_MTP_GET_OBJECT_PROP_VALUE, g_USBImage.image_cmd.Parameter1, g_USBImage.image_cmd.Parameter2);
		USB_MTP_Get_Data_Phase_Cmd_Hdlr();
		break;
	case MTP_GET_OBJECT_PROP_LIST:
		USB_Dbg_Trace(USB_MTP_GET_OBJECT_PROP_LIST, g_USBImage.image_cmd.Parameter1, g_USBImage.image_cmd.Parameter2);
		USB_MTP_Get_Data_Phase_Cmd_Hdlr();
		break;
//	case MTP_GET_OBJECT_REFERENCES:
//		USB_Dbg_Trace(USB_MTP_GET_OBJECT_REFERENCES, g_USBImage.image_cmd.Parameter1, 0);
//		ASSERT(0);
//		USB_MTP_Get_Data_Phase_Cmd_Hdlr();
//		break;

		/* MTP cmds with RX phase cmds */
	case MTP_SEND_OBJECT_INFO:
//		USB_Dbg_Trace(USB_MTP_SEND_OBJECT_INFO, g_USBImage.image_cmd.Parameter1, g_USBImage.image_cmd.Parameter2);
//		USB_MTP_Send_Data_Phase_Cmd_Hdlr();
//		break;
	case MTP_SEND_OBJECT:
//		USB_Dbg_Trace(USB_MTP_SEND_OBJECT, 0, 0);
//		USB_MTP_Send_Data_Phase_Cmd_Hdlr();
//		break;
	case MTP_SET_DEVICE_PROP_VALUE:
//		USB_Dbg_Trace(USB_MTP_SET_DEVICE_PROP_VALUE, g_USBImage.image_cmd.Parameter1, 0);
//		USB_MTP_Cmd_Set_Device_Prop_Value();
//		break;
	case MTP_SET_OBJECT_PROP_VALUE:
//		USB_Dbg_Trace(USB_MTP_SET_OBJECT_PROP_VALUE, g_USBImage.image_cmd.Parameter1, g_USBImage.image_cmd.Parameter2);
//		USB_MTP_Send_Data_Phase_Cmd_Hdlr();
//		break;
	case MTP_SET_OBJECT_REFERENCES:
//		USB_Dbg_Trace(USB_MTP_SET_OBJECT_REFERENCES, g_USBImage.image_cmd.Parameter1, 0);
		ASSERT(0);
//		USB_MTP_Send_Data_Phase_Cmd_Hdlr();
		break;

	default:
		USB_MTP_Cmd_Unknown();
		break;
	}
}


static void USB_MTP_No_Data_From_MTP_Hdlr(usb_mtp_operation_rsp_struct *ptr)
{
	USB_Dbg_Trace(USB_MTP_NO_DATA_HDLR, ptr->result_code, ptr->rsp_code);

	/* No data phase commands */
	if(g_USBImage.image_cmd.Code == MTP_GET_NUM_OBJECTS)
	{
		g_USB_Image_Response.ContainerLength = USB_IMAGE_RES_1_PARA;
		g_USB_Image_Response.Parameter1 = ptr->rsp_params[0];
	}
	else
	{
		g_USB_Image_Response.ContainerLength = USB_IMAGE_CONTAINER_LENGTH;
	}

	g_USB_Image_Response.TransactionID = g_USBImage.current_transactionID;
	g_USB_Image_Response.Code = ptr->rsp_code;

	g_USBImage.state = USB_IMAGE_CMD_RX;
	USB_Image_ReturnTx(&g_USB_Image_Response, g_USB_Image_Response.ContainerLength);
}


static void USB_MTP_TX_Data_From_MTP_Hdlr(usb_mtp_operation_rsp_struct *ptr, kal_bool b_is_first_rsp)
{
	USB_Dbg_Trace(USB_MTP_TX_DATA_HDLR, ptr->result_code, ptr->rsp_code);

	if((((usb_mtp_result_enum)ptr->result_code == USB_MTP_RESULT_OK)||((usb_mtp_result_enum)ptr->result_code == USB_MTP_RESULT_CONTINUE))
		&&(ptr->rsp_code == MTP_OK))
	{
		/* In this condition, the value of data_total_size and data_size are valid */
		if((ptr->data_total_size < ptr->data_size)||(ptr->data_size == 0))
			EXT_ASSERT(0, ptr->data_total_size, ptr->data_size, 0);

		if((b_is_first_rsp == KAL_TRUE)&&(ptr->data_total_size != ptr->data_size)&&(ptr->data_size != g_USBImage.data_pool_size))
			EXT_ASSERT(0, ptr->data_total_size, ptr->data_size, g_USBImage.data_pool_size);

		if(b_is_first_rsp == KAL_TRUE)
		{
			g_USBImage.total_tx_bytes = ptr->data_total_size;
			g_USBImage.current_tx_bytes = 0;

			if(ptr->data_size > USB_IMAGE_MTP_MAX_TX_BUFFERSIZE)
				EXT_ASSERT(0, ptr->data_size, USB_IMAGE_MTP_MAX_TX_BUFFERSIZE, 0);

			USB_Dbg_Trace(USB_MTP_TX_DATA_HDLR_1, ptr->data_total_size, ptr->data_size);

			/* Write data packet's header */
			g_USB_Image_Data_Header.ContainerLength = g_USBImage.total_tx_bytes + USB_IMAGE_CONTAINER_LENGTH;
			g_USB_Image_Data_Header.Code = g_USBImage.image_cmd.Code;
			g_USB_Image_Data_Header.TransactionID = g_USBImage.current_transactionID;
		}
		else
		{
			USB_Dbg_Trace(USB_MTP_TX_DATA_HDLR_2, ptr->data_total_size, ptr->data_size);

			if((g_USBImage.total_tx_bytes != ptr->data_total_size)||(ptr->data_size > USB_IMAGE_MTP_MAX_TX_BUFFERSIZE))
				EXT_ASSERT(0, g_USBImage.total_tx_bytes, ptr->data_total_size, USB_IMAGE_MTP_MAX_TX_BUFFERSIZE);
		}
	}
	else
	{
		/* The value of data_total_size and data_size are invalid, go error handling */
		USB_Dbg_Trace(USB_MTP_TX_DATA_UNVALID_MSG, ptr->result_code, ptr->rsp_code);
		drv_trace2(TRACE_FUNC, (kal_uint32)USB_MTP_TX_RESPONSE_INVAILD_MTP_MSG, ptr->result_code, ptr->rsp_code);

		g_USBImage.b_is_mtp_abnormal_msg = KAL_TRUE;

		/* Store the response code */
		g_USB_Image_Response.Code = ptr->rsp_code;
		g_USB_Image_Response.TransactionID = g_USBImage.current_transactionID;
	}

	if((g_USBImage.buffer_write_index^1) >= 2)
		ASSERT(0);

	/* If the other buffer is empty, it means that DMA must not be running , and we trigger DMA for this buffer */
	if(g_USBImage.buffer_rw_bytes[g_USBImage.buffer_write_index^1] == 0)
	{
		if((USB_DMA_Get_Run_Status(g_USBImage.txpipe->byEP, USB_EP_TX_DIR) == KAL_TRUE)
			||(g_USBImage.buffer_read_index != g_USBImage.buffer_write_index))
			ASSERT(0);

		if(g_USBImage.b_is_mtp_abnormal_msg == KAL_FALSE)
		{
			if(b_is_first_rsp == KAL_TRUE)
				USB_Send_Header_Packet(g_USBImage.txpipe->byEP, &g_USB_Image_Data_Header);

			/* Set up TX DMA */
			USB_Image_BuildTx((void *)g_USBImage.mtp_image_buffer->data_buffer[g_USBImage.buffer_read_index],
					g_USBImage.buffer_rw_bytes[g_USBImage.buffer_read_index]);

			g_USBImage.current_tx_bytes += g_USBImage.buffer_rw_bytes[g_USBImage.buffer_read_index];

			if(g_USBImage.current_tx_bytes == g_USBImage.total_tx_bytes)
			{
				/* Total data is sent out */
				g_USBImage.state = USB_IMAGE_RESPONSE;

				if(g_USBImage.image_cmd.Code == MTP_GET_PARTIAL_OBJECT)
				{
					g_USB_Image_Response.ContainerLength = USB_IMAGE_RES_1_PARA;
					g_USB_Image_Response.Parameter1 = ptr->rsp_params[0];

					if(ptr->rsp_params[0] != g_USBImage.total_tx_bytes)
						EXT_ASSERT(0, ptr->rsp_params[0], g_USBImage.total_tx_bytes, 0);
				}
				else
				{
					g_USB_Image_Response.ContainerLength = USB_IMAGE_CONTAINER_LENGTH;
				}

				g_USB_Image_Response.Code = ptr->rsp_code;
				g_USB_Image_Response.TransactionID = g_USBImage.current_transactionID;
			}
			else
			{
				/* Since the other buffer is empty, if there is still data to send, notify MTP task */
				g_USBImage.buffer_write_index ^= 1;
				g_USBImage.data_pool_ptr = (kal_uint8 *)g_USBImage.mtp_image_buffer->data_buffer[g_USBImage.buffer_write_index];

				/* Send msg to MTP */
				USB_MTP_Image_Send_Msg(USB_MTP_IMAGE_MSG_OPERATION_REQ);
			}
		}
		else
		{
			/* g_USBImage.b_is_mtp_abnormal_msg == KAL_TRUE, run error handling */
			g_USBImage.b_is_mtp_abnormal_msg = KAL_FALSE;

			if(b_is_first_rsp == KAL_TRUE)
			{
				/* Write data packet's header */
				g_USB_Image_Data_Header.ContainerLength = USB_IMAGE_CONTAINER_LENGTH;
				g_USB_Image_Data_Header.Code = g_USBImage.image_cmd.Code;
				g_USB_Image_Data_Header.TransactionID = g_USBImage.current_transactionID;

//				USB_Send_Header_Packet(g_USBImage.txpipe->byEP, &g_USB_Image_Data_Header);

//				g_USBImage.current_tx_bytes = g_USBImage.total_tx_bytes = 0;
				g_USBImage.current_tx_bytes = 0;
			}
			else
			{
				/* Modify total_tx_bytes */
//				g_USBImage.total_tx_bytes = g_USBImage.current_tx_bytes;

				/* the g_USBImage.current_tx_bytes must be 16K*N */
				if((g_USBImage.current_tx_bytes%USB_IMAGE_MTP_MAX_TX_BUFFERSIZE) != 0)
					EXT_ASSERT(0, g_USBImage.current_tx_bytes, 0, 0);

				USB_Send_Null_Packet(g_USBImage.txpipe->byEP);
			}

			/* Total data is sent out */
			g_USBImage.state = USB_IMAGE_CMD_RX;

			if(g_USBImage.image_cmd.Code == MTP_GET_PARTIAL_OBJECT)
			{
				g_USB_Image_Response.ContainerLength = USB_IMAGE_RES_1_PARA;
				g_USB_Image_Response.Parameter1 = g_USBImage.current_tx_bytes;
			}
			else
			{
				g_USB_Image_Response.ContainerLength = USB_IMAGE_CONTAINER_LENGTH;
			}

			USB_Image_ReturnTx(&g_USB_Image_Response, g_USB_Image_Response.ContainerLength);
		}
	}
}


static void USB_MTP_TX_DMA_Callback_Hdlr(void)
{
	USB_Dbg_Trace(USB_MTP_TX_DMA_CALLBACK_HDLR, g_USBImage.buffer_rw_bytes[0], g_USBImage.buffer_rw_bytes[1]);

	/* If the other buffer is full, trigger DMA to send out */
	if(g_USBImage.buffer_rw_bytes[g_USBImage.buffer_read_index] != 0)
	{
		/* Set up TX DMA */
		USB_Image_BuildTx((void *)g_USBImage.mtp_image_buffer->data_buffer[g_USBImage.buffer_read_index],
				g_USBImage.buffer_rw_bytes[g_USBImage.buffer_read_index]);

		if((g_USBImage.b_is_mtp_abnormal_msg == KAL_TRUE)
			||(g_USBImage.buffer_write_index != g_USBImage.buffer_read_index))
			ASSERT(0);

		g_USBImage.current_tx_bytes += g_USBImage.buffer_rw_bytes[g_USBImage.buffer_read_index];

		if(g_USBImage.current_tx_bytes == g_USBImage.total_tx_bytes)
		{
			/* Total data is sent out */
			g_USBImage.state = USB_IMAGE_RESPONSE;
		}
		else
		{
			/* Since the other buffer is empty, if there is still data to send, notify MTP task */
			g_USBImage.buffer_write_index ^= 1;
			g_USBImage.data_pool_ptr = (kal_uint8 *)g_USBImage.mtp_image_buffer->data_buffer[g_USBImage.buffer_write_index];

			/* Send msg to MTP */
			USB_MTP_Image_Send_Msg(USB_MTP_IMAGE_MSG_OPERATION_REQ);
		}
	}

	if(g_USBImage.b_is_mtp_abnormal_msg == KAL_TRUE)
	{
		/* Run error handling */
		g_USBImage.b_is_mtp_abnormal_msg = KAL_FALSE;

		/* Modify total_tx_bytes */
//		g_USBImage.total_tx_bytes = g_USBImage.current_tx_bytes;

		g_USBImage.state = USB_IMAGE_CMD_RX;

		if(g_USBImage.image_cmd.Code == MTP_GET_PARTIAL_OBJECT)
		{
			g_USB_Image_Response.ContainerLength = USB_IMAGE_RES_1_PARA;
			g_USB_Image_Response.Parameter1 = g_USBImage.current_tx_bytes;
		}
		else
		{
			g_USB_Image_Response.ContainerLength = USB_IMAGE_CONTAINER_LENGTH;
		}

		/* the g_USBImage.current_tx_bytes must be 16K*N */
		if((g_USBImage.current_tx_bytes%USB_IMAGE_MTP_MAX_TX_BUFFERSIZE) != 0)
			EXT_ASSERT(0, g_USBImage.current_tx_bytes, 0, 0);

		USB_Send_Null_Packet(g_USBImage.txpipe->byEP);

		USB_Image_ReturnTx(&g_USB_Image_Response, g_USB_Image_Response.ContainerLength);
	}
}


static void USB_MTP_RX_Data_To_MTP_Hdlr(usb_mtp_operation_rsp_struct *ptr)
{
	USB_Dbg_Trace(USB_MTP_RX_DATA_HDLR_1, g_USBImage.buffer_rw_bytes[0], g_USBImage.buffer_rw_bytes[1]);

	/* If the other buffer is not empty, it means that DMA must not be running because buffers are full before MTP handled */
	if((((usb_mtp_result_enum)ptr->result_code != USB_MTP_RESULT_OK)&&((usb_mtp_result_enum)ptr->result_code != USB_MTP_RESULT_CONTINUE))
		||(ptr->rsp_code != MTP_OK))
	{
		/* "Error!", go to error handling */
		USB_Dbg_Trace(USB_MTP_RX_DATA_UNVALID_MSG, ptr->result_code, ptr->rsp_code);
		drv_trace2(TRACE_FUNC, (kal_uint32)USB_MTP_RX_RESPONSE_INVAILD_MTP_MSG, ptr->result_code, ptr->rsp_code);

		g_USBImage.b_is_mtp_abnormal_msg = KAL_TRUE;

		/* Record the response message */
		if(g_USBImage.image_cmd.Code == MTP_SEND_OBJECT_INFO)
		{
			g_USB_Image_Response.ContainerLength = USB_IMAGE_RES_3_PARA;
			g_USB_Image_Response.Parameter1 = ptr->rsp_params[0];
			g_USB_Image_Response.Parameter2 = ptr->rsp_params[1];
			g_USB_Image_Response.Parameter3 = ptr->rsp_params[2];
		}
		else
		{
			g_USB_Image_Response.ContainerLength = USB_IMAGE_CONTAINER_LENGTH;
		}

		g_USB_Image_Response.TransactionID = g_USBImage.current_transactionID;
		g_USB_Image_Response.Code = ptr->rsp_code;
	}


	if(g_USBImage.buffer_rw_bytes[g_USBImage.buffer_read_index] != 0)
	{
		if((USB_DMA_Get_Run_Status(g_USBImage.rxpipe->byEP, USB_EP_RX_DIR) == KAL_TRUE)
			||(g_USBImage.buffer_read_index != g_USBImage.buffer_write_index))
			ASSERT(0);

		if(g_USBImage.b_is_mtp_abnormal_msg == KAL_FALSE)
		{
			/* There are still data to receive */
			g_USBImage.data_pool_ptr = (kal_uint8 *)g_USBImage.mtp_image_buffer->data_buffer[g_USBImage.buffer_read_index];
			g_USBImage.data_size = g_USBImage.buffer_rw_bytes[g_USBImage.buffer_read_index];

			/* Send msg to MTP task */
			USB_MTP_Image_Send_Msg(USB_MTP_IMAGE_MSG_OPERATION_REQ);

			if(g_USBImage.current_rx_bytes != g_USBImage.total_rx_bytes)
			{
				/* There are still data we want to receive */
				g_USBImage.buffer_write_index ^= 1;

				if((g_USBImage.total_rx_bytes - g_USBImage.current_rx_bytes) <= USB_IMAGE_MTP_MAX_RX_BUFFERSIZE)
				{
					/* Set up RX DMA */
					USB_Image_BuildRx((void *)g_USBImage.mtp_image_buffer->data_buffer[g_USBImage.buffer_write_index],
						g_USBImage.total_rx_bytes - g_USBImage.current_rx_bytes);
				}
				else
				{
					/* Set up RX DMA */
					USB_Image_BuildRx((void *)g_USBImage.mtp_image_buffer->data_buffer[g_USBImage.buffer_write_index],
						USB_IMAGE_MTP_MAX_RX_BUFFERSIZE);
				}
			}
		}
		else
		{
			g_USBImage.buffer_rw_bytes[g_USBImage.buffer_read_index] = 0;
			g_USBImage.buffer_read_index ^= 1;

			/* Send stall packet to stop RX packet */
			if(g_USBImage.current_rx_bytes != g_USBImage.total_rx_bytes)
			{
				g_USBImage.b_device_cancel = KAL_TRUE;
				USB_CtrlEPStall(g_USBImage.txpipe->byEP, USB_EP_TX_DIR, KAL_TRUE);
				USB_CtrlEPStall(g_USBImage.rxpipe->byEP, USB_EP_RX_DIR, KAL_TRUE);
			}
		}
	}
	else
	{
		/* If another buffer is empty => 1. USB had already received the whole data */
		/* 2. DMA is running */
		if(g_USBImage.current_rx_bytes == g_USBImage.total_rx_bytes)
		{
			if(g_USBImage.b_is_mtp_abnormal_msg == KAL_FALSE)
			{
				if(g_USBImage.image_cmd.Code == MTP_SEND_OBJECT_INFO)
				{
					g_USB_Image_Response.ContainerLength = USB_IMAGE_RES_3_PARA;
					g_USB_Image_Response.Parameter1 = ptr->rsp_params[0];
					g_USB_Image_Response.Parameter2 = ptr->rsp_params[1];
					g_USB_Image_Response.Parameter3 = ptr->rsp_params[2];
				}
				else
				{
					g_USB_Image_Response.ContainerLength = USB_IMAGE_CONTAINER_LENGTH;
				}

				g_USB_Image_Response.TransactionID = g_USBImage.current_transactionID;
				g_USB_Image_Response.Code = ptr->rsp_code;
			}

			if(g_USBImage.total_rx_bytes != 0)
			{
				/* Switch RX ep to FIFO */
				USB_Config_RxEP_Type(g_USBImage.rxpipe->byEP, USB_ENDPT_BULK, KAL_FALSE);
			}

			g_USBImage.b_is_mtp_abnormal_msg = KAL_FALSE;
			g_USBImage.state = USB_IMAGE_CMD_RX;
			USB_Image_ReturnTx(&g_USB_Image_Response, g_USB_Image_Response.ContainerLength);
		}
	}
}


static void USB_MTP_RX_Data_Callback_Hdlr(void)
{
	USB_Dbg_Trace(USB_MTP_RX_DATA_CALLBACK_HDLR, g_USBImage.buffer_rw_bytes[0], g_USBImage.buffer_rw_bytes[1]);

	if((g_USBImage.buffer_write_index^1) >= 2)
		ASSERT(0);

	/* If the other buffer is empty, it means that DMA must not be running , and we trigger DMA for this buffer,
		If the other buffer is not empty, it means that MTP task still handle that buffer */
	if(g_USBImage.buffer_rw_bytes[g_USBImage.buffer_write_index^1] == 0)
	{
		if((USB_DMA_Get_Run_Status(g_USBImage.rxpipe->byEP, USB_EP_RX_DIR) == KAL_TRUE)
			||(g_USBImage.buffer_read_index != g_USBImage.buffer_write_index))
			ASSERT(0);

		if(g_USBImage.b_is_mtp_abnormal_msg == KAL_FALSE)
		{
			g_USBImage.data_pool_ptr = (kal_uint8 *)g_USBImage.mtp_image_buffer->data_buffer[g_USBImage.buffer_read_index];
			g_USBImage.data_size = g_USBImage.buffer_rw_bytes[g_USBImage.buffer_read_index];

			if((g_USBImage.data_size == 0)&&(g_USBImage.total_rx_bytes != 0))
				ASSERT(0);

			/* Send msg to MTP task */
			USB_MTP_Image_Send_Msg(USB_MTP_IMAGE_MSG_OPERATION_REQ);

			if(g_USBImage.current_rx_bytes != g_USBImage.total_rx_bytes)
			{
				/* There are still data we want to receive */
				g_USBImage.buffer_write_index ^= 1;

				if((g_USBImage.total_rx_bytes - g_USBImage.current_rx_bytes) <= USB_IMAGE_MTP_MAX_RX_BUFFERSIZE)
				{
					/* Set up RX DMA */
					USB_Image_BuildRx((void *)g_USBImage.mtp_image_buffer->data_buffer[g_USBImage.buffer_write_index],
						g_USBImage.total_rx_bytes - g_USBImage.current_rx_bytes);
				}
				else
				{
					/* Set up RX DMA */
					USB_Image_BuildRx((void *)g_USBImage.mtp_image_buffer->data_buffer[g_USBImage.buffer_write_index],
						USB_IMAGE_MTP_MAX_RX_BUFFERSIZE);
				}
			}
		}
		else
		{
			if(g_USBImage.buffer_rw_bytes[g_USBImage.buffer_read_index] == 0)
				ASSERT(0);
			g_USBImage.buffer_rw_bytes[g_USBImage.buffer_read_index] = 0;

			g_USBImage.buffer_read_index ^= 1;

			/* Send stall packet */
			if(g_USBImage.current_rx_bytes != g_USBImage.total_rx_bytes)
			{
				g_USBImage.b_device_cancel = KAL_TRUE;
				USB_CtrlEPStall(g_USBImage.txpipe->byEP, USB_EP_TX_DIR, KAL_TRUE);
				USB_CtrlEPStall(g_USBImage.rxpipe->byEP, USB_EP_RX_DIR, KAL_TRUE);
			}
		}
	}

	/* g_USBImage.current_rx_bytes is updated in DMA callback */
	if((g_USBImage.b_is_mtp_abnormal_msg == KAL_TRUE)&&(g_USBImage.current_rx_bytes == g_USBImage.total_rx_bytes))
	{
		g_USBImage.b_is_mtp_abnormal_msg = KAL_FALSE;

		if(g_USBImage.total_rx_bytes != 0)
		{
			/* Switch RX ep to FIFO */
			USB_Config_RxEP_Type(g_USBImage.rxpipe->byEP, USB_ENDPT_BULK, KAL_FALSE);
		}

		g_USBImage.state = USB_IMAGE_CMD_RX;
		USB_Image_ReturnTx(&g_USB_Image_Response, g_USB_Image_Response.ContainerLength);
	}
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

/* The serial number shall be a 32 character hexadecimal string, and one extra terminating Null cahracter */
static void USB_MTP_Cmd_Get_Device_Info(void)
{
	kal_uint8 *index = (kal_uint8*)g_USBImage.mtp_image_buffer;
	kal_uint8 element_num1 = sizeof(MTP_DeviceInfo_Struct)/sizeof(kal_uint8) -1;
	kal_uint8 element_num2 = g_USBImage.mtp_image_param->image_manufacturer_size;
	kal_uint8 element_num3 = g_USBImage.mtp_image_param->image_model_size;
	kal_uint8 element_num4 = g_USBImage.mtp_image_param->image_device_version_size;
	kal_uint32 count;


	g_USB_Image_Data_Header.ContainerLength = USB_IMAGE_CONTAINER_LENGTH + element_num1
		+ 4 + (element_num2 + element_num3 + element_num4 + 33)*2;
	g_USB_Image_Data_Header.Code = MTP_GET_DEVICE_INFO;
	g_USB_Image_Data_Header.TransactionID = g_USBImage.current_transactionID;

	USB_Send_Header_Packet(g_USBImage.txpipe->byEP, &g_USB_Image_Data_Header);

	kal_mem_cpy(index, &g_MTPImage.image_deviceinfo, element_num1);
	index += element_num1;

	USB_Image_Copy_Unicode_String(index, g_USBImage.mtp_image_param->image_manufacturer_string, element_num2);
	index += element_num2*2 + 1;

	USB_Image_Copy_Unicode_String(index, g_USBImage.mtp_image_param->image_model_string, element_num3);
	index += element_num3*2 + 1;

	USB_Image_Copy_Unicode_String(index, g_USBImage.mtp_image_param->image_device_version_string, element_num4);
	index += element_num4*2 + 1;

//	kal_mem_set(index, 33, 1);
	*index = 33;
	index++;

	/* gUsbDevice.serial_string[0] is 0x0320 */
	kal_mem_cpy(index, (kal_uint8*)&gUsbDevice.serial_string[1], 2*(USB_SERIAL_STRING_LEN-1));
	index += 2*(USB_SERIAL_STRING_LEN-1);

	kal_mem_set(index, 0x00, 2*(34-USB_SERIAL_STRING_LEN));

	for(count = 0; count < (33-USB_SERIAL_STRING_LEN); count++)
	{
//		kal_mem_set(index, '1', 1);
		*index = '1';
		index += 2;
	}

	g_USBImage.state = USB_IMAGE_RESPONSE;
	g_USB_Image_Response.ContainerLength = USB_IMAGE_CONTAINER_LENGTH;
	g_USB_Image_Response.TransactionID = g_USBImage.current_transactionID;
	g_USB_Image_Response.Code = MTP_OK;

	g_USBImage.total_tx_bytes = g_USB_Image_Data_Header.ContainerLength - USB_IMAGE_CONTAINER_LENGTH;
	USB_Image_BuildTx((void *)g_USBImage.mtp_image_buffer, g_USBImage.total_tx_bytes);
}


static void USB_MTP_Cmd_Get_Device_Prop_Desc(void)
{
	kal_uint8 *index = (kal_uint8*)g_USBImage.mtp_image_buffer;
	MTP_DeviceProperty_Struct *temp;
 	kal_uint8 element_num1 = sizeof(MTP_DeviceProperty_Struct)/sizeof(kal_uint8) -1;
	kal_uint8 element_num2;
	kal_uint8 element_num3;


	g_USBImage.state = USB_IMAGE_RESPONSE;
	g_USB_Image_Response.ContainerLength = USB_IMAGE_CONTAINER_LENGTH;
	g_USB_Image_Response.TransactionID = g_USBImage.current_transactionID;
	g_USB_Image_Response.Code = MTP_OK;

	g_USB_Image_Data_Header.Code = MTP_GET_DEVICE_PROP_DESC;
	g_USB_Image_Data_Header.TransactionID = g_USBImage.current_transactionID;

	if(g_USBImage.image_cmd.Parameter1 == MTP_DEVICE_FRIENDLY_NAME)
	{
		element_num2 = g_USBImage.mtp_image_param->image_device_friendly_name_default_value_size;
		element_num3 = g_USBImage.mtp_image_param->image_device_friendly_name_current_value_size;

		g_USB_Image_Data_Header.ContainerLength = USB_IMAGE_CONTAINER_LENGTH + element_num1
			+ 3 + (element_num2 + element_num3)*2;

		USB_Send_Header_Packet(g_USBImage.txpipe->byEP, &g_USB_Image_Data_Header);

		temp = (MTP_DeviceProperty_Struct *)index;
		temp->DevicePropertyCode = MTP_DEVICE_FRIENDLY_NAME;
		temp->DataType = 0xFFFF; /* string */
		temp->GetSet = 0x01;  /* Get/Set */
		index += element_num1;

		USB_Image_Copy_Unicode_String(index, g_USBImage.mtp_image_param->image_device_friendly_name_default_value_string, element_num2);
		index += element_num2*2 + 1;

		USB_Image_Copy_Unicode_String(index, g_USBImage.mtp_image_param->image_device_friendly_name_current_value_string, element_num3);
		index += element_num3*2 + 1;

//		kal_mem_set(index, 0x00, 1); /* FormFlag is None */
		*index = 0x00;

		g_USBImage.total_tx_bytes = g_USB_Image_Data_Header.ContainerLength - USB_IMAGE_CONTAINER_LENGTH;
		USB_Image_BuildTx((void *)g_USBImage.mtp_image_buffer, g_USBImage.total_tx_bytes);
	}
	else if (g_USBImage.image_cmd.Parameter1 == MTP_SYNCHRONIZATION_PARTNER)
	{
		element_num2 = g_USBImage.mtp_image_param->image_synchronization_partner_default_value_size;
		element_num3 = g_USBImage.mtp_image_param->image_synchronization_partner_current_value_size;

		g_USB_Image_Data_Header.ContainerLength = USB_IMAGE_CONTAINER_LENGTH + element_num1
			+ 3 + (element_num2 + element_num3)*2;

		USB_Send_Header_Packet(g_USBImage.txpipe->byEP, &g_USB_Image_Data_Header);

		temp = (MTP_DeviceProperty_Struct *)index;
		temp->DevicePropertyCode = MTP_SYNCHRONIZATION_PARTNER;
		temp->DataType = 0xFFFF; /* string */
		temp->GetSet = 0x01;  /* Get/Set */
		index += element_num1;

		USB_Image_Copy_Unicode_String(index, g_USBImage.mtp_image_param->image_synchronization_partner_default_value_string, element_num2);
		index += element_num2*2 + 1;

		USB_Image_Copy_Unicode_String(index, g_USBImage.mtp_image_param->image_synchronization_partner_current_value_string, element_num3);
		index += element_num3*2 + 1;

//		kal_mem_set(index, 0x00, 1); /* FormFlag is None */
		*index = 0x00;

		g_USBImage.total_tx_bytes = g_USB_Image_Data_Header.ContainerLength - USB_IMAGE_CONTAINER_LENGTH;
		USB_Image_BuildTx((void *)g_USBImage.mtp_image_buffer, g_USBImage.total_tx_bytes);
	}
	else
	{
		ASSERT(0);
	}
}


static void USB_MTP_Cmd_Get_Device_Prop_Value(void)
{
	ASSERT(0);
}


static void USB_MTP_Cmd_Set_Device_Prop_Value(void)
{
	USB_Config_RxEP_Type(g_USBImage.rxpipe->byEP, USB_ENDPT_BULK, KAL_FALSE);

	/* Send Response */
	g_USB_Image_Response.ContainerLength = USB_IMAGE_CONTAINER_LENGTH;
	g_USB_Image_Response.Code = MTP_OK;
	g_USB_Image_Response.TransactionID = g_USBImage.current_transactionID;
	USB_Image_ReturnTx(&g_USB_Image_Response, USB_IMAGE_CONTAINER_LENGTH);
}


static void USB_MTP_Cmd_Unknown(void)
{
	/* Send Response */
/*
	g_USBImage.state = USB_IMAGE_CMD_RX;
	g_USB_Image_Response.ContainerLength = USB_IMAGE_CONTAINER_LENGTH;
	g_USB_Image_Response.Code = MTP_OPERATION_NOT_SUPPORTED;
	g_USB_Image_Response.TransactionID = g_USBImage.current_transactionID;
	USB_Image_ReturnTx(&g_USB_Image_Response, USB_IMAGE_CONTAINER_LENGTH);

	g_USBImage.image_event.ContainerLength = USB_IMAGE_CONTAINER_LENGTH;
	g_USBImage.image_event.Code = MTP_CANCEL_TRANSACTION;
	g_USBImage.image_event.TransactionID = g_USBImage.current_transactionID;
	USB_Image_Send_Intr();
*/
	EXT_ASSERT(0, 0, 0, 0);
}

#endif  /* __MTP_ENABLE__ */

