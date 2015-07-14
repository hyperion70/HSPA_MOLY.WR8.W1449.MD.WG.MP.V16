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
 *    usb_adap.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  This file implements device mode adaption layer between HW driver and class drivers
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#ifdef __USB_ENABLE__


#include "drv_comm.h"
//#include "stack_common.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "kal_public_api.h" //#include "stack_ltlcom.h" //MSBB change #include "app_ltlcom.h"       /* Task message communiction */
#if defined(__USB_COM_PORT_ENABLE__)&&defined(__USB_BOOTUP_TRACE__)
#include "drvpdn.h"
#endif

#include "usb_comm.h"
#include "usb.h"
#include "usb_adap.h"
#include "usb_resource.h"
//#include "usb_drv.h"
#include "usbms_drv.h"
#include "usbacm_drv.h"


#ifdef __MTP_ENABLE__
#include "usbimage_drv.h"
#endif

#include "usb_debug_tool.h"
#include "dcl.h"
#if defined(__DUAL_TALK_MODEM_SUPPORT__)
#include "lpwr.h"
#endif
#if defined(__DUAL_TALK_MODEM_SUPPORT__)
extern LPWR_STRUCT LPWR_DEV[];
extern const char gpio_usb_wakeup_pin;
#endif


void USB_Register_Drv_Info(USB_DRV_HDLR_TYPE type, kal_uint32 ep_num, usb_drv_intr_handler_ptr hdlr)
{
	USB_DRV_CTRL_REGISTER_DRV_INFO_T dcl_reg_data;


	dcl_reg_data.u4ep_num = (DCL_UINT32)ep_num;
	dcl_reg_data.type = (DCL_USB_DRV_HDLR_TYPE)type;
	dcl_reg_data.hdlr = (DCL_USB_FUNC_TYPE_0)hdlr;
	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_REGISTER_DRV_INFO, (DCL_CTRL_DATA_T  *)&dcl_reg_data);
}


void USB_Set_UnMask_Irq(kal_bool set)
{
	DCL_BOOL dcl_data = (DCL_BOOL)set;


	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_SET_UNMASK_IRQ, (DCL_CTRL_DATA_T  *)&dcl_data);
}


/* Get the irq status */
kal_bool USB_Get_UnMask_Irq(void)
{
#if (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	DCL_BOOL dcl_data;

	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_GET_UNMASK_IRQ, (DCL_CTRL_DATA_T  *)&dcl_data);

	return (kal_bool)dcl_data;
#else
	return KAL_TRUE;
#endif
}


kal_uint16 USB_GetFrameCount(void)
{
//	kal_uint16 sof;
	DCL_UINT16 dcl_data;


	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_GET_FRAME_COUNT, (DCL_CTRL_DATA_T  *)&dcl_data);
//	sof = (kal_uint16)dcl_data;
	return (kal_uint16)dcl_data;
}


void USB_PDNmode(kal_bool pdn_en)
{
	DCL_BOOL dcl_data = (DCL_BOOL)pdn_en;

	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_PDN_ENABLE, (DCL_CTRL_DATA_T  *)&dcl_data);
}


void USB_TxEPEn(kal_uint32 ep_num, USB_ENDPT_TXFER_TYPE ep_type, USB_ENDPT_DMA_USAGE dma_usage_type, kal_bool is_flush, kal_bool is_ft_mode)
{
	USB_DRV_CTRL_EP_ENABLE_T dcl_data;

	dcl_data.u4ep_num = (DCL_UINT32)ep_num;
	dcl_data.ep_type = (DCL_USB_ENDPT_TXFER_TYPE)ep_type;
	dcl_data.dma_usage_type = (DCL_USB_ENDPT_DMA_USAGE)dma_usage_type;
	dcl_data.fgis_flush = (DCL_BOOL)is_flush;
	dcl_data.fgis_ft_mode = (DCL_BOOL)is_ft_mode;
	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_TXEP_EN, (DCL_CTRL_DATA_T  *)&dcl_data);
}



void USB_TxEPDis(kal_uint32 ep_num, USB_ENDPT_DMA_USAGE dma_usage_type)
{
	USB_DRV_CTRL_EP_DISABLE_T dcl_data;

	dcl_data.u4ep_num = (DCL_UINT32)ep_num;
	dcl_data.dma_usage_type = (DCL_USB_ENDPT_DMA_USAGE)dma_usage_type;
	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_TXEP_DIS, (DCL_CTRL_DATA_T  *)&dcl_data);
}


void USB_RxEPEn(kal_uint32 ep_num, USB_ENDPT_TXFER_TYPE ep_type, USB_ENDPT_DMA_USAGE dma_usage_type, kal_bool is_flush, kal_bool is_ft_mode)
{
	USB_DRV_CTRL_EP_ENABLE_T dcl_data;


	dcl_data.u4ep_num = (DCL_UINT32)ep_num;
	dcl_data.ep_type = (DCL_USB_ENDPT_TXFER_TYPE)ep_type;
	dcl_data.dma_usage_type = (DCL_USB_ENDPT_DMA_USAGE)dma_usage_type;
	dcl_data.fgis_flush = (DCL_BOOL)is_flush;
	dcl_data.fgis_ft_mode = (DCL_BOOL)is_ft_mode;
	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_RXEP_EN, (DCL_CTRL_DATA_T  *)&dcl_data);
}


void USB_RxEPDis(kal_uint32 ep_num, USB_ENDPT_DMA_USAGE dma_usage_type)
{
	USB_DRV_CTRL_EP_DISABLE_T dcl_data;


	dcl_data.u4ep_num = (DCL_UINT32)ep_num;
	dcl_data.dma_usage_type = (DCL_USB_ENDPT_DMA_USAGE)dma_usage_type;
	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_RXEP_DIS, (DCL_CTRL_DATA_T  *)&dcl_data);
}


void USB_Config_TxEP_Type(kal_uint32 ep_num, USB_ENDPT_TXFER_TYPE ep_type, kal_bool b_is_use_dma)
{
	USB_DRV_CTRL_EP_CONFIG_TYPE_T dcl_data;


	dcl_data.u4ep_num = (DCL_UINT32)ep_num;
	dcl_data.ep_type = (DCL_USB_ENDPT_TXFER_TYPE)ep_type;
	dcl_data.fg_is_switch_to_dma = (DCL_BOOL)b_is_use_dma;
	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_CONFIG_TXEP_TYPE, (DCL_CTRL_DATA_T  *)&dcl_data);
}



void USB_Config_RxEP_Type(kal_uint32 ep_num, USB_ENDPT_TXFER_TYPE ep_type, kal_bool b_is_use_dma)
{
	USB_DRV_CTRL_EP_CONFIG_TYPE_T dcl_data;


	dcl_data.u4ep_num = (DCL_UINT32)ep_num;
	dcl_data.ep_type = (DCL_USB_ENDPT_TXFER_TYPE)ep_type;
	dcl_data.fg_is_switch_to_dma = (DCL_BOOL)b_is_use_dma;
	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_CONFIG_RXEP_TYPE, (DCL_CTRL_DATA_T  *)&dcl_data);
}


void USB_TxEPClearDataTog(kal_uint32 ep_num, USB_ENDPT_TXFER_TYPE ep_type)
{
	USB_DRV_CTRL_EP_COMMON_FUNC_T  dcl_data;


	dcl_data.u4ep_num = (DCL_UINT32)ep_num;
	dcl_data.type = (DCL_USB_ENDPT_TXFER_TYPE)ep_type;
	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_TXEP_CLEAR_DATATOG, (DCL_CTRL_DATA_T  *)&dcl_data);
}


void USB_RxEPClearDataTog(kal_uint32 ep_num, USB_ENDPT_TXFER_TYPE ep_type)
{
	USB_DRV_CTRL_EP_COMMON_FUNC_T  dcl_data;


	dcl_data.u4ep_num = (DCL_UINT32)ep_num;
	dcl_data.type = (DCL_USB_ENDPT_TXFER_TYPE)ep_type;
	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_RxEP_CLEAR_DATATOG, (DCL_CTRL_DATA_T  *)&dcl_data);
}


USB_EP_STATE USB_TxEP_Usage(kal_uint32 ep_num)
{
	USB_DRV_CTRL_EP_STATE_T dcl_data;


	dcl_data.u4ep_num = (DCL_UINT32)ep_num;
	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_TXEP_USAGE, (DCL_CTRL_DATA_T  *)&dcl_data);
	return (USB_EP_STATE)dcl_data.result;
}


USB_EP_STATE USB_RxEP_Usage(kal_uint32 ep_num)
{
	USB_DRV_CTRL_EP_STATE_T dcl_data;


	dcl_data.u4ep_num = (DCL_UINT32)ep_num;
	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_RXEP_USAGE, (DCL_CTRL_DATA_T  *)&dcl_data);
	return (USB_EP_STATE)dcl_data.result;
}


void USB_EPFIFORead(kal_uint32 ep_num, kal_uint16 nBytes, void *pDst, kal_bool force_one_byte_access)
{
	USB_DRV_CTRL_EP_FIFO_RW_T dcl_data;


	dcl_data.u4ep_num = (DCL_UINT32)ep_num;
	dcl_data.u2nBytes = (DCL_UINT16)nBytes;
	dcl_data.paddr = (void *)pDst;
	dcl_data.fg_force_one_byte_access = (DCL_BOOL)force_one_byte_access;
	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_EPFIFO_READ, (DCL_CTRL_DATA_T  *)&dcl_data);
}


void USB_EPFIFOWrite (kal_uint32 ep_num, kal_uint16 nBytes, void *pSrc)
{
	USB_DRV_CTRL_EP_FIFO_RW_T dcl_data;


	dcl_data.u4ep_num = (DCL_UINT32)ep_num;
	dcl_data.u2nBytes = (DCL_UINT16)nBytes;
	dcl_data.paddr = (void *)pSrc;
	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_EPFIFO_WRITE, (DCL_CTRL_DATA_T  *)&dcl_data);
}


void USB_CtrlEPStall(kal_uint32 ep_num, USB_EP_DIRECTION direction, kal_bool stall_enable)
{
	USB_DRV_CTRL_EP_STALL_T dcl_data;


	dcl_data.u4ep_num = (DCL_UINT32)ep_num;
	dcl_data.direction = (DCL_USB_EP_DIRECTION)direction;
	dcl_data.fgen = (DCL_BOOL)stall_enable;
	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_CTRLEPSTALL, (DCL_CTRL_DATA_T  *)&dcl_data);
}


/*
void USB_Get_EP0_Status(kal_bool *p_transaction_end, kal_bool *p_sent_stall)
{

	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_CTRLEPSTALL, (DCL_CTRL_DATA_T  *)&dcl_data);
}
*/

void USB_Update_EP0_State(USB_EP0_DRV_STATE state, kal_bool stall, kal_bool end)
{
	USB_DRV_CTRL_UPDATE_EPSTATE_T dcl_data;


	dcl_data.state = (DCL_USB_EP0_DRV_STATE)state;
	dcl_data.fgstall = (DCL_BOOL)stall;
	dcl_data.fgend = (DCL_BOOL)end;
	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_UPDATE_EP0_STATE, (DCL_CTRL_DATA_T  *)&dcl_data);
}


kal_uint32 USB_EP0_Pkt_Len(void)
{
//	kal_uint32 count;
	DCL_UINT32 dcl_data;


	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_GET_EP0_PKT_LEN, (DCL_CTRL_DATA_T  *)&dcl_data);
//	count = (kal_uint32)dcl_data;
	return (kal_uint32)dcl_data;
}


void USB_EP_Tx_Ready(kal_uint32 ep_num, USB_ENDPT_TXFER_TYPE ep_type)
{
	USB_DRV_CTRL_EP_COMMON_FUNC_T dcl_data;


	dcl_data.u4ep_num = (DCL_UINT32)ep_num;
	dcl_data.type = (DCL_USB_ENDPT_TXFER_TYPE)ep_type;
	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_TXEP_READY, (DCL_CTRL_DATA_T  *)&dcl_data);
}


kal_uint32 USB_EP_Rx_Pkt_Len(kal_uint32 ep_num)
{
	USB_DRV_CTRL_EP_CTRL_FUNC_3_T dcl_data;
//	kal_uint32 count;


	dcl_data.u4ep_num = (DCL_UINT32)ep_num;
	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_GET_RXEP_PKT_LEN, (DCL_CTRL_DATA_T  *)&dcl_data);
//	count = (kal_uint32)dcl_data.u4result;
	return (kal_uint32)dcl_data.u4result;
}



void USB_EP_Rx_Ready(kal_uint32 ep_num, USB_ENDPT_TXFER_TYPE ep_type)
{
	USB_DRV_CTRL_EP_COMMON_FUNC_T dcl_data;


	dcl_data.u4ep_num = (DCL_UINT32)ep_num;
	dcl_data.type = (DCL_USB_ENDPT_TXFER_TYPE)ep_type;
	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_RXEP_READY, (DCL_CTRL_DATA_T  *)&dcl_data);
}


kal_bool USB_Is_EP_Tx_Empty(kal_uint32 ep_num, USB_ENDPT_TXFER_TYPE ep_type)
{
	USB_DRV_CTRL_EP_CTRL_FUNC_4_T dcl_data;


	dcl_data.u4ep_num = (DCL_UINT32)ep_num;
	dcl_data.ep_type = (DCL_USB_ENDPT_TXFER_TYPE)ep_type;
	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_IS_TXEP_EMPTY, (DCL_CTRL_DATA_T  *)&dcl_data);
	return (kal_bool)dcl_data.fgresult;
}


kal_bool USB_Is_EP_Rx_Empty(kal_uint32 ep_num, USB_ENDPT_TXFER_TYPE ep_type)
{
	USB_DRV_CTRL_EP_CTRL_FUNC_4_T dcl_data;


	dcl_data.u4ep_num = (DCL_UINT32)ep_num;
	dcl_data.ep_type = (DCL_USB_ENDPT_TXFER_TYPE)ep_type;
	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_IS_RXEP_EMPTY, (DCL_CTRL_DATA_T  *)&dcl_data);
	return (kal_bool)dcl_data.fgresult;
}


void USB_Clear_Tx_EP_FIFO(kal_uint32 ep_num, USB_ENDPT_TXFER_TYPE ep_type, kal_bool b_reset_toggle)
{
	USB_DRV_CTRL_EP_CTRL_FUNC_2_T dcl_data;


	dcl_data.u4ep_num = (DCL_UINT32)ep_num;
	dcl_data.ep_type = (DCL_USB_ENDPT_TXFER_TYPE)ep_type;
	dcl_data.fg_reset_toggle = (DCL_BOOL)b_reset_toggle;
	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_CLEAR_TXEP_FIFO, (DCL_CTRL_DATA_T  *)&dcl_data);
}


void USB_Clear_Rx_EP_FIFO(kal_uint32 ep_num, USB_ENDPT_TXFER_TYPE ep_type, kal_bool b_reset_toggle)
{
	USB_DRV_CTRL_EP_CTRL_FUNC_2_T dcl_data;


	dcl_data.u4ep_num = (DCL_UINT32)ep_num;
	dcl_data.ep_type = (DCL_USB_ENDPT_TXFER_TYPE)ep_type;
	dcl_data.fg_reset_toggle = (DCL_BOOL)b_reset_toggle;
	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_CLEAR_RXEP_FIFO, (DCL_CTRL_DATA_T  *)&dcl_data);
}


/* DMA control functions */
void USB_Get_DMA_Channel(kal_uint32 ep_tx_num, kal_uint32 ep_rx_num, USB_EP_DIRECTION direction, kal_bool same_chan)
{
	USB_DRV_CTRL_DMA_FUNC_T dcl_data;


	dcl_data.u4ep_tx_num = (DCL_UINT32)ep_tx_num;
	dcl_data.u4ep_rx_num = (DCL_UINT32)ep_rx_num;
	dcl_data.direction = (DCL_USB_EP_DIRECTION)direction;
	dcl_data.fgsame_chan = (DCL_BOOL)same_chan;
	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_GET_DMA_CHANNEL, (DCL_CTRL_DATA_T  *)&dcl_data);
}



void USB_Stop_DMA_Channel(kal_uint32 ep_num, USB_EP_DIRECTION direction)
{
	USB_DRV_CTRL_EP_COMMON_FUNC_T dcl_data;


	dcl_data.u4ep_num = (DCL_UINT32)ep_num;
	dcl_data.direction = (DCL_USB_EP_DIRECTION)direction;
	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_STOP_DMA_CHANNEL, (DCL_CTRL_DATA_T  *)&dcl_data);
}


void USB_Free_DMA_Channel(kal_uint32 ep_tx_num, kal_uint32 ep_rx_num, USB_EP_DIRECTION direction, kal_bool same_chan)
{
	USB_DRV_CTRL_DMA_FUNC_T dcl_data;


	dcl_data.u4ep_tx_num = (DCL_UINT32)ep_tx_num;
	dcl_data.u4ep_rx_num = (DCL_UINT32)ep_rx_num;
	dcl_data.direction = (DCL_USB_EP_DIRECTION)direction;
	dcl_data.fgsame_chan = (DCL_BOOL)same_chan;
	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_FREE_DMA_CHANNEL, (DCL_CTRL_DATA_T  *)&dcl_data);
}



void USB_DMA_Setup(kal_uint32 ep_num, USB_EP_DIRECTION direction, USB_ENDPT_TXFER_TYPE ep_type, kal_uint32 addr, kal_uint32 length,
					usb_dma_callback callback, kal_bool callback_upd_run, kal_bool known_size, USB_DMA_TYPE dma_type)
{
	USB_DRV_CTRL_DMA_SETUP_FUNC_T dcl_data;


	dcl_data.u4ep_num = (DCL_UINT32)ep_num;
	dcl_data.direction = (DCL_USB_EP_DIRECTION)direction;
	dcl_data.ep_type = (DCL_USB_ENDPT_TXFER_TYPE)ep_type;
	dcl_data.u4addr = (DCL_UINT32)addr;
	dcl_data.u4length = (DCL_UINT32)length;
	dcl_data.callback = (DCL_USB_FUNC_TYPE_0)callback;
	dcl_data.fgcallback_upd_run = (DCL_BOOL)callback_upd_run;
	dcl_data.fgknown_size = (DCL_BOOL)known_size;
	dcl_data.dma_type = (DCL_USB_DMA_TYPE)dma_type;
	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_DMA_SETUP, (DCL_CTRL_DATA_T  *)&dcl_data);
}


kal_bool USB_DMA_Get_Run_Status(kal_uint32 ep_num, USB_EP_DIRECTION direction)
{
	USB_DRV_CTRL_EP_CTRL_FUNC_1_T dcl_data;


	dcl_data.u4ep_num = (DCL_UINT32)ep_num;
	dcl_data.direction = (DCL_USB_EP_DIRECTION)direction;
	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_GET_DMA_RUN_STATUS, (DCL_CTRL_DATA_T  *)&dcl_data);
	return (kal_bool)dcl_data.fg_result;
}

void USB_DMA_Set_Run_Status(kal_uint32 ep_num, USB_EP_DIRECTION direction, kal_bool status)
{
	USB_DRV_CTRL_DMA_STATUS_FUNC_T dcl_data;



	dcl_data.u4ep_num = (DCL_UINT32)ep_num;
	dcl_data.direction = (DCL_USB_EP_DIRECTION)direction;
	dcl_data.fgstatus = (DCL_BOOL)status;
	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_SET_DMA_RUN_STATUS, (DCL_CTRL_DATA_T  *)&dcl_data);
}



void USB_Set_DMA_Limiter(kal_uint32 dma_limit_num)
{
	DCL_UINT32 dcl_data;


	dcl_data = (DCL_UINT32)dma_limit_num;
	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_SET_DMA_LIMITER, (DCL_CTRL_DATA_T  *)&dcl_data);
}



void USB_Switch_DMA_Burst_mode(kal_bool b_enable)
{
	DCL_BOOL dcl_data;


	dcl_data = (DCL_BOOL)b_enable;
	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_SWITCH_DMA_BURST_MODE, (DCL_CTRL_DATA_T  *)&dcl_data);
}


void USB_Register_DMA_Channel(kal_uint32 ep_num, USB_EP_DIRECTION direction, kal_uint8 chan_num, kal_bool same_chan)
{
	USB_DRV_CTRL_DMA_CTRL_FUNC_2_T dcl_data;


	dcl_data.u4ep_num = (DCL_UINT32)ep_num;
	dcl_data.direction = (DCL_USB_EP_DIRECTION)direction;
	dcl_data.u1chan_num = (DCL_UINT8)chan_num;
	dcl_data.fgsame_chan = (DCL_BOOL)same_chan;
	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_REGISTER_DMA_CHANNEL, (DCL_CTRL_DATA_T  *)&dcl_data);
}


void USB_Set_DMA_Burst_Mode(kal_uint8 dma_burst_mode)
{
	DCL_UINT8  dcl_data;


	dcl_data = (DCL_UINT8)dma_burst_mode;
	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_SET_DMA_BURST_MODE, (DCL_CTRL_DATA_T  *)&dcl_data);
}


kal_bool USB_Is_High_Speed(void)
{
	DCL_BOOL  dcl_data;


	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_USB_IS_HIGH_SPEED, (DCL_CTRL_DATA_T  *)&dcl_data);
	return (kal_bool)dcl_data;
}


void USB_Enter_Test_Mode(USB_TEST_MODE_TYPE test_selector)
{
	USB_DRV_CTRL_USB_TEST_MODE_FUNC_T  dcl_data;


	dcl_data.test_selector = (DCL_USB_TEST_MODE_TYPE)test_selector;
	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_ENTER_TESTMODE, (DCL_CTRL_DATA_T  *)&dcl_data);
}



kal_bool USB_Is_FIFO_Not_Empty(void)
{
	DCL_BOOL  dcl_data;


	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_IS_FIFO_Not_Empty, (DCL_CTRL_DATA_T  *)&dcl_data);
	return (kal_bool)dcl_data;
}



kal_bool USB_Is_Suspend_Power_Status(void)
{
	DCL_BOOL  dcl_data;


	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_IS_SUSPEND_POWER_STATUS, (DCL_CTRL_DATA_T  *)&dcl_data);
	return (kal_bool)dcl_data;
}



void USB_Polling_Transmit_Done(kal_uint32 ep_num, USB_ENDPT_TXFER_TYPE ep_type)
{
	USB_DRV_CTRL_EP_COMMON_FUNC_T  dcl_data;


	dcl_data.u4ep_num = (DCL_UINT32)ep_num;
	dcl_data.type = (DCL_USB_ENDPT_TXFER_TYPE)ep_type;
	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_POLLING_TX_DONE, (DCL_CTRL_DATA_T  *)&dcl_data);
}



void USB_Polling_Transmit_Data(kal_uint32 ep_num, USB_EP_DIRECTION direction, USB_ENDPT_TXFER_TYPE ep_type, kal_uint32 addr, kal_uint32 length,
				usb_dma_callback callback, kal_bool callback_upd_run, kal_bool known_size, USB_DMA_TYPE dma_type)
{
	/* config DMA to transmit data*/
	USB_DMA_Setup(ep_num, direction, ep_type, addr, length, callback, callback_upd_run, known_size, dma_type);

	/* wait for transmit done*/
	USB_Polling_Transmit_Done(ep_num, ep_type);
}



void USB_Polling_Recv_Data(void)
{
	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_POLLING_RX_DATA, NULL);
}


void USB_Clr_RX_EP_ISR(kal_uint32 ep_num)
{
	USB_DRV_CTRL_EP_COMMON_FUNC_T   dcl_data;


	dcl_data.u4ep_num = (DCL_UINT32)ep_num;
	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_CLR_RXEP_ISR, (DCL_CTRL_DATA_T  *)&dcl_data);
}


kal_bool USB_Get_RX_EP_ISR_Status(kal_uint32 ep_num)
{
	USB_DRV_CTRL_EP_CTRL_FUNC_1_T  dcl_data;


	dcl_data.u4ep_num = (DCL_UINT32)ep_num;
	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_GET_RXEP_ISR_STATUS, (DCL_CTRL_DATA_T  *)&dcl_data);
	return (kal_bool)dcl_data.fg_result;
}



/*
kal_bool USBDL_Is_USB_Download_Mode(void)
{
	DCL_BOOL  dcl_data;
	DCL_HANDLE usb_dcl_handle;

	usb_dcl_handle = DclUSB_DRV_Open(DCL_USB, FLAGS_NONE);
	DclUSB_DRV_Control(usb_dcl_handle, USB_DRV_CMD_USBDL_IS_USB_DL_MODE, (DCL_CTRL_DATA_T  *)&dcl_data);
	DclUSB_DRV_Close(usb_dcl_handle);

	return (kal_bool)dcl_data;
}

kal_bool USBDL_Is_USB_Fast_Meta_Mode(void)
{
	DCL_BOOL  dcl_data;
	DCL_HANDLE usb_dcl_handle;

	usb_dcl_handle = DclUSB_DRV_Open(DCL_USB, FLAGS_NONE);
	DclUSB_DRV_Control(usb_dcl_handle, USB_DRV_CMD_USBDL_IS_USB_FAST_META_MODE, (DCL_CTRL_DATA_T  *)&dcl_data);
	DclUSB_DRV_Close(usb_dcl_handle);

	return (kal_bool)dcl_data;
}
*/

void USB_Debug_Information(kal_uint32 ep_num, USB_EP_DIRECTION direction, kal_bool check_error)
{
	USB_DRV_CTRL_EP_STALL_T  dcl_data;


	dcl_data.u4ep_num = (DCL_UINT32)ep_num;
	dcl_data.direction = (DCL_USB_EP_DIRECTION)direction;
	dcl_data.fgen = (DCL_BOOL)check_error;
	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_DEBUG_INFO, (DCL_CTRL_DATA_T  *)&dcl_data);
}


DCL_USB_IP_VERSION USB_IP_Version(void)
{
	USB_DRV_CTRL_GET_IP_VERSION_T dcl_data;

	/* Get IP version */
	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_GET_IP_VERSION, (DCL_CTRL_DATA_T  *)&dcl_data);
	return dcl_data.ip_version;
}

void USB_DUMP(void)
{
	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_DUMP, NULL);
}


kal_uint32 USB_Intr_Max_Packet_Size(void)
{
	kal_uint32 max_intr_pkt_size;
	
#ifdef __USB_HS_ENABLE__
	if(USB_Is_High_Speed() == KAL_TRUE)
		max_intr_pkt_size = USB_EP_INTR_MAXP_HS;
	else
		max_intr_pkt_size = USB_EP_INTR_MAXP_FS;
#else
	max_intr_pkt_size = USB_EP_INTR_MAXP;
#endif

	return max_intr_pkt_size;
}

kal_uint32 USB_Bulk_Max_Packet_Size(void)
{
	kal_uint32 max_bulk_pkt_size;

#ifdef __USB_HS_ENABLE__	
	if(USB_Is_High_Speed() == KAL_TRUE) 
		max_bulk_pkt_size = USB_EP_BULK_MAXP_HS;
	else
		max_bulk_pkt_size = USB_EP_BULK_MAXP_FS;
#else
	max_bulk_pkt_size = USB_EP_BULK_MAXP;
#endif

	return max_bulk_pkt_size;
}

#ifdef  __USB_SUPPORT_ISO_PIPE__
kal_uint32 USB_Iso_Max_Packet_Size(void)
{
	kal_uint32 max_iso_pkt_siz;

#ifdef __USB_HS_ENABLE__	
	if(USB_Is_High_Speed() == KAL_TRUE) 
		max_iso_pkt_siz = USB_EP_ISO_MAXP_HS;
	else
		max_iso_pkt_siz = USB_EP_ISO_MAXP_FS;
#else
	max_iso_pkt_siz = USB_EP_ISO_MAXP_FS;
#endif

	return max_iso_pkt_siz;
}
#endif

#ifdef __USB_HS_ENABLE__	
kal_uint32 USB_Speed_Reset_Packet_Size(kal_bool b_other_speed)
{
	kal_uint32  max_packet;

	if(USB_Is_High_Speed() == KAL_TRUE)
	{
		if(b_other_speed == KAL_FALSE)
			max_packet = USB_EP_BULK_MAXP_HS;
		else
			max_packet = USB_EP_BULK_MAXP_FS;
	}
	else
	{
		if(b_other_speed == KAL_FALSE)
			max_packet = USB_EP_BULK_MAXP_FS;
		else
			max_packet = USB_EP_BULK_MAXP_HS;
	}

	return max_packet;
}
#endif

//===========================  DCL interface to other module =====================================//

void USB_GPTI_StartItem(kal_uint32 handle,kal_uint16 tick,void (*gptimer_func)(void *),void *parameter)
{
	SGPT_CTRL_START_T start;

//GPTI_StartItem(g_UsbACM[usb_port].dma_handle, 100, USB_Acm_DMA_Timeout, &USB2UARTPort[usb_port]);
	start.u2Tick = tick;
	start.pfCallback = gptimer_func;
	start.vPara = parameter;
	DclSGPT_Control((DCL_HANDLE)handle, SGPT_CMD_START, (DCL_CTRL_DATA_T*)&start);
}

void USB_GPTI_StopItem(kal_uint32 handle)
{
	DclSGPT_Control((DCL_HANDLE)handle, SGPT_CMD_STOP, 0);
}

void USB_GPTI_GetHandle(kal_uint32* handle)
{
	if((*handle == 0) ||(*handle == 0x7F))
		*handle =(kal_uint32)DclSGPT_Open(DCL_GPT_CB, 0);
}


void USB_GPTI_ReleaseHandle(kal_uint32* handle)
{
	DCL_HANDLE temp;
	
	if((*handle != 0) &&(*handle != 0x7F))
	{
		temp = (DCL_HANDLE)*handle;
 		DclSGPT_Close(&temp);
		*handle = 0;
	}
}


#ifdef WEBCAM_SUPPORT
void USB_GPT3_Start(void)
{
	DCL_HANDLE gpt_handle;

	gpt_handle=DclFGPT_Open(DCL_GPT_FreeRUN3,0);
	DclFGPT_Control(gpt_handle,FGPT_CMD_START,0);
	DclFGPT_Close(gpt_handle);
}

void USB_GPT3_Stop(void)
{
	DCL_HANDLE gpt_handle;

	gpt_handle=DclFGPT_Open(DCL_GPT_FreeRUN3,0);
	DclFGPT_Control(gpt_handle,FGPT_CMD_STOP,0);
	DclFGPT_Close(gpt_handle);
}

kal_uint32 USB_GPT3_return_current_count(void)
{
	DCL_HANDLE gpt_handle;
	FGPT_CTRL_RETURN_COUNT_T count;

	gpt_handle=DclFGPT_Open(DCL_GPT_FreeRUN3,0);
	DclFGPT_Control(gpt_handle,FGPT_CMD_RETURN_COUNT,(DCL_CTRL_DATA_T*)&count);
	return (kal_uint32)count;
}
#endif

/*
kal_bool USB_INT_USBBoot(void)  // in order to reduce code size, use macro
{
	DCL_HANDLE g_PW_Dcl_Handle;
	PW_CTRL_IS_USB_BOOT CtrlVal;

	g_PW_Dcl_Handle = DclPMU_Open(DCL_PW, FLAGS_NONE);
	DclPW_Control(g_PW_Dcl_Handle, PW_CMD_IS_USB_BOOT,(DCL_CTRL_DATA_T *)&CtrlVal);
	return (kal_bool)CtrlVal.val;
}
*/

void USB_CHR_USB_EINT_UnMask(void)
{
	DCL_HANDLE g_PWIC_Dcl_Handle;
	
	g_PWIC_Dcl_Handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
	Dcl_Chr_Det_Control(g_PWIC_Dcl_Handle, CHR_DET_CMD_UNMASK_EINT, NULL); //Unmask EINT for next detection
	DclPMU_Close(g_PWIC_Dcl_Handle);
}

#if defined(__DUAL_TALK_MODEM_SUPPORT__)

void USB_Remote_Wake_UP_Start(void)
{
#if defined(__DUAL_TALK_MODEM_SUPPORT__)  

   DCL_HANDLE handle;
   handle = DclGPIO_Open( DCL_GPIO, gpio_usb_wakeup_pin);
   DclGPIO_Control(handle, GPIO_CMD_WRITE_LOW, NULL);
   DclGPIO_Close(handle);       
#endif   
}

void USB_Remote_Wake_UP_End(void)
{
#if defined(__DUAL_TALK_MODEM_SUPPORT__)  
   DCL_HANDLE handle;
   handle = DclGPIO_Open( DCL_GPIO, gpio_usb_wakeup_pin);
   DclGPIO_Control(handle, GPIO_CMD_WRITE_HIGH, NULL);
   DclGPIO_Close(handle);      
#endif   
}

void USB_Lock_SleepMode(void)
{
   lpwr_main_fast_disable(&LPWR_DEV[PDN_USB]);
}

void USB_UnLock_SleepMode(void)

{
   lpwr_main_fast_enable(&LPWR_DEV[PDN_USB]);   
}
#endif

/*
void USB_Get_Current_Table(void)  // in order to reduce code size, use macro
{
	DCL_HANDLE pmu_handle; 

	pmu_handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(pmu_handle, CHR_GET_CHR_CURRENT_LIST, (DCL_CTRL_DATA_T *)&gUsbDevice.get_chr_current_list);
	DclPMU_Close(pmu_handle);
}

void USB_BMT_NO_CHARGING_OUT(void) // in order to reduce code size, use macro
{
	DCL_HANDLE bmt_handler;
	BMT_CTRL_SENDMES2UEM_T bmt_cmd_data1;

	bmt_handler = DclBMT_Open(DCL_BMT,FLAGS_NONE);
	bmt_cmd_data1.ChargerMsg = DCL_BMT_USB_NO_CHARGING_OUT;
	DclBMT_Control(bmt_handler, BMT_CMD_SENDMES2UEM, (DCL_CTRL_DATA_T *)&bmt_cmd_data1); // New API with CMD & DATA
}

void USB_BMT_NO_CHARGING_IN(void) // in order to reduce code size, use macro
{
	DCL_HANDLE bmt_handler;
	BMT_CTRL_SENDMES2UEM_T bmt_cmd_data1;

	bmt_handler = DclBMT_Open(DCL_BMT,FLAGS_NONE);
	bmt_cmd_data1.ChargerMsg = DCL_BMT_USB_NO_CHARGING_IN;
	DclBMT_Control(bmt_handler, BMT_CMD_SENDMES2UEM, (DCL_CTRL_DATA_T *)&bmt_cmd_data1); // New API with CMD & DATA
}

*/
#endif /* #ifdef __USB_ENABLE__ */



//===========================  Boot Trace interface to bootarm.s and TST =====================================//
/*
 * Must provide dumy APIs to MoDis
 */
void USB_Boot_Trace_Init(void)
{
#if defined(__USB_COM_PORT_ENABLE__)&&defined(__USB_BOOTUP_TRACE__)
	g_USB_Dcl_Handle = DclUSB_DRV_Open(DCL_USB, FLAGS_NONE);
	
	g_UsbMode.cable_type = USB_MODE_CABLE_B_PLUGIN;
	USB_Set_Device_State(DEVSTATE_DEFAULT);

	
	gUsbDevice.device_param = USB_GetCustomFunc()->get_device_param_func();
	g_UsbACM_Comm.acm_param = USB_GetCustomFunc()->get_acm_param_func();
	
#if defined(__OLD_PDN_ARCH__)
#if defined(__OLD_PDN_DEFINE__)
	USB_DRV_WriteReg(DRVPDN_CON0_CLR, DRVPDN_CON0_USB);
#elif defined(__CLKG_DEFINE__)
	USB_DRV_WriteReg(CG_CLR0, CG_CON0_USB);
#endif
#else
	//		DRVPDN_Disable(PDN_USB);	
	PDN_CLR(PDN_USB); //power up dev
#endif

	USB_Config_Type(USB_CDC_ACM, KAL_TRUE, NULL);
	while(USB_Get_Device_State() != DEVSTATE_CONFIG)
	{
		USB_HISR();
	}
#endif
}

void USB_Boot_Trace_Release(void)
{
#if defined(__USB_COM_PORT_ENABLE__)&&defined(__USB_BOOTUP_TRACE__)
	if(g_UsbACM[0].txpipe != NULL)
	{
		USB_Release_Type(KAL_TRUE, KAL_FALSE);
	}
#endif
}
