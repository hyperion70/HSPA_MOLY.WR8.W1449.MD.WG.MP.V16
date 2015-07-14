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
 *    usbms_state.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *    This file implements usb mass storage state machine
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef __USB_MASS_STORAGE_ENABLE__

#include "drv_comm.h"
//#include "stack_common.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "kal_public_api.h" //#include "stack_ltlcom.h" //MSBB change #include "app_ltlcom.h"
#include "usb_comm.h"
#include "drvsignals.h"
#include "intrCtrl.h"
#include "usb_trc.h"

//#include "usb_drv.h"
#include "usb_mode.h"
#include "usb_adap.h"
#include "usb.h"
#include "usbms_drv.h"
#include "usbms_adap.h"
#include "usbms_state.h"
#include "usb_custom.h"
#include "usb_debug_tool.h"
#ifdef	__TC01__
/* under construction !*/
#endif
//#include "kal_non_specific_general_types.h"
//#include "kal_release.h"
#include "kal_public_api.h"
#include "usb_msdisk.h"

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "init.h"

#include "drv_msgid.h"

#if defined(__USB_MODEM_CARD_SUPPORT__)
extern kal_uint8 custom_em_get_usb_cdrom_config(void);
#endif

/* sense code */
#ifdef __MTK_TARGET__
__attribute__ ((section ("NONCACHEDRW"), aligned(4))) 
#endif /* __MTK_TARGET__ */
static kal_uint8 senseOk[] = {0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
					0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

#ifdef __MTK_TARGET__
__attribute__ ((section ("NONCACHEDRW"), aligned(4))) 
#endif /* __MTK_TARGET__ */
static kal_uint8 senseNoMedia[] = {0x70, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x00, 0x00,
						0x00, 0x00, 0x3A, 0x00, 0x00, 0x00, 0x00, 0x00};

#ifdef __MTK_TARGET__
__attribute__ ((section ("NONCACHEDRW"), aligned(4))) 
#endif /* __MTK_TARGET__ */
static kal_uint8 senseWriteFail[] = {0x70, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x00, 0x00,
						0x00, 0x00, 0x0c, 0x02, 0x00, 0x00, 0x00, 0x00};

#ifdef __MTK_TARGET__
__attribute__ ((section ("NONCACHEDRW"), aligned(4))) 
#endif /* __MTK_TARGET__ */
static kal_uint8 senseMediaChanged[] = {0x70, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x00, 0x00,
						0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00};

#ifdef __MTK_TARGET__
__attribute__ ((section ("NONCACHEDRW"), aligned(4))) 
#endif /* __MTK_TARGET__ */
static kal_uint8 senseInvalidFieldInCDB[] = {0x70, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x00,
							0x00, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00};
#ifdef __P_PROPRIETARY_COPYRIGHT__
#ifdef __MTK_TARGET__
/* under construction !*/
#endif /* __MTK_TARGET__ */
/* under construction !*/
/* under construction !*/
#endif

#ifdef __USB_MASS_STORAGE_CDROM_ENABLE__
//__align(4) static const kal_uint8 TOC_INF[] = {
//	0x00, 0x2E, 0x01, 0x01, 0x01, 0x14,0x00, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 
//	0x14, 0x00, 0xA1, 0x00, 0x73, 0x4D,0x65, 0x01, 0x6F, 0x72, 0x01, 0x14, 0x20, 0xA2, 0x20, 0x20, 
//	0x36, 0x2E, 0x06, 0x30, 0x3C, 0x01,0x14, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00};
#define USBSCSI_CMD_READ_TOC_REPLY_LEN_48  48 
#define USBSCSI_CMD_READ_TOC_REPLY_LEN_20  20 

#ifdef __MTK_TARGET__
__attribute__ ((section ("NONCACHEDRW"), aligned(4))) 
#endif /* __MTK_TARGET__ */
static kal_uint8 TOC_REPLY_LEN_20[] = {
	0x00,0x00,				/* TOC Data Length*/
	0x01,					/*First Track Number*/
	0x01,					/*Last Track Number*/
	0x00,					/*Reserved*/ 
	0x14,					/*0x17: DVD+R and DVD+MRW, 0x14: all others, 0x1C: reserved*/ /*ADR(0001b) & CONTROL(0100b)*/  
	0x01,					/*Track Number*/
	0x00,					/*Reserved*/   
	0x00, 0x00,0x00,0x00,	/* 4 Bytes Track Start Address */
	0x00,					/*Reserved*/   
	0x14,					/*ADR, CONTROL. 14h:DVD-ROM, 17h:Recordables and Rewritables*/  
	0xAA,					/*Track Number for the lead out area*/
	0x00,					/*Reserved*/
	0x00,0x00,0x00,0x00		/* 4 Bytes Track Start Address for the lead out area*/
}; 

#ifdef __MTK_TARGET__
__attribute__ ((section ("NONCACHEDRW"), aligned(4))) 
#endif /* __MTK_TARGET__ */
static kal_uint8 TOC_REPLY_LEN_48[] = {
	/* Full Toc Mode , not related to the MSF bit in the CDB*/
	0x00,									/* TOC Data Length*/
	USBSCSI_CMD_READ_TOC_REPLY_LEN_48-2, 	/* TOC Data Length*/
	0x01,				/*First Track Number*/
	0x01,				/*Last Track Number*/
	0x01,				/* first session */
	0x14,				/*0x17: DVD+R and DVD+MRW, 0x14: all others, 0x1C: reserved*/ /*ADR(0001b) & CONTROL(0100b)*/  
	0x00, 				/* TNO */
	0xA0,				/* First Track number in the program area */
	0x00, 0x00, 0x00,  	/* MIN/SEC/FRAME */
	0x00,			 	/* zero*/
	0x01,				/*First Track Number is 0x01*/
	0x00,				/*Disc-type= CDROM with first track in Mode 1*/
	0x00,				/* PFrame*/
	0x01,				/* first session */
	0x14,				/*0x17: DVD+R and DVD+MRW, 0x14: all others, 0x1C: reserved*/ /*ADR(0001b) & CONTROL(0100b)*/     
	0x00,				/* TNO */   
	0xA1,				/* Last Track number in the program area */
	0x00, 0x00, 0x00,  	/* MIN/SEC/FRAME */
	0x00,			 	/* zero*/
	0x01, 0x00, 0x00,	/*Last Track Number is 0x01*/
	0x01,				/* first session */
	0x14,				/*0x17: DVD+R and DVD+MRW, 0x14: all others, 0x1C: reserved*/ /*ADR(0001b) & CONTROL(0100b)*/  
	0x00,				/* TNO */   
	0xA2,				/* Start Location of lead out are*/
	0x00, 0x00, 0x00,  	/* MIN/SEC/FRAME */
	0x00,			 	/* zero*/
	0x06,     			//LBA_M, dataBuffer[34], need to fill correct value
	0x30,     			//LBA_S, dataBuffer[35], need to fill correct value
	0x3C,     			//LBA_F, dataBuffer[36], need to fill correct value
	0x01,				/* first session */
	0x14,				/*0x17: DVD+R and DVD+MRW, 0x14: all others, 0x1C: reserved*/ /*ADR(0001b) & CONTROL(0100b)*/  
	0x00,				/* TNO */   
	0x01,				/* start address of first First track */
	0x00, 0x00, 0x00,  	/* MIN/SEC/FRAME */
	0x00,			 	/* zero*/
	0x00, 0x02, 0x00	/* PMSF address */
};
#endif //__USB_MODEM_CARD_SUPPORT__

#if defined(DRV_USB_POWER_DOWN_SUPPORT)&&defined(MTK_SLEEP_ENABLE)&&defined(DRV_USB_SLEEP_SUPPORT)
extern void L1SM_SleepEnable(kal_uint8 handle);
extern void L1SM_SleepDisable(kal_uint8 handle);
extern kal_uint8 usbms_pdn_handle;
#endif


extern void DRV_RESET(void);

static void USB_Ms_Recv_Data(local_para_struct *buf);
static void USB_Ms_Transmit_Data(local_para_struct *buf);
static void USB_Ms_Generate_Csw(UsbMs_CSW *CSW, UsbMs_CBW *CBW);
static void USB_Ms_Build_Tx_CWS(UsbMs_CSW *CSW, UsbMs_CBW *CBW);
static void USB_Ms_MemInverse(void *src, void *dst, kal_uint16 len);
void USB_Ms_Cmd(void *data);
//static void USB_Ms_Cmd_Format(kal_uint8 LUN, UsbMs_CBW *CBW);
static void USB_Ms_State_Checkmedia_Exist(kal_uint8 LUN);
static void USB_Ms_Cmd_Inquiry(kal_uint8 LUN, UsbMs_CBW *CBW);
static void USB_Ms_Cmd_Test_Unit_Ready(kal_uint8 LUN, UsbMs_CBW *CBW);
static void USB_Ms_Cmd_Prev_Media_Removal(kal_uint8 LUN, UsbMs_CBW *CBW);
static void USB_Ms_Cmd_Read_Capacity(kal_uint8 LUN, UsbMs_CBW *CBW);
static void USB_Ms_Cmd_Read_FormatCapacity(kal_uint8 LUN, UsbMs_CBW *CBW);
static void USB_Ms_Cmd_RequestSense(kal_uint8 LUN, UsbMs_CBW *CBW);
static void USB_Ms_Cmd_Verify(kal_uint8 LUN, UsbMs_CBW *CBW);
static void USB_Ms_Cmd_ModeSense(kal_uint8 LUN, UsbMs_CBW *CBW);
static void USB_Ms_Cmd_ModeSense6(kal_uint8 LUN, UsbMs_CBW *CBW);
static void USB_Ms_Cmd_Start_Stop_Unit(kal_uint8 LUN, UsbMs_CBW *CBW);
static void USB_Ms_Cmd_Unknown(UsbMs_CBW *CBW);
static void USB_Ms_Cmd_Read(kal_uint8 LUN, UsbMs_CBW *CBW);
static void USB_Ms_Handle_Read(kal_uint8 LUN, UsbMs_CBW *CBW);
static void USB_Ms_Read_Fail_Handler(kal_uint8 LUN, UsbMs_CBW *CBW);
static void USB_Ms_Cmd_Write(kal_uint8 LUN, UsbMs_CBW *CBW);
static void USB_Ms_Handle_Write(kal_uint8 LUN, UsbMs_CBW *CBW, kal_uint8 sector_num);
#ifdef __USB_MASS_STORAGE_CDROM_ENABLE__
static void USB_Ms_Cmd_ReadToc(kal_uint8 LUN, UsbMs_CBW *CBW);
static void USB_Ms_Vendor(kal_uint8 LUN, UsbMs_CBW *CBW);
#endif
#ifdef __P_PROPRIETARY_COPYRIGHT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

//#pragma arm section zidata = "NONCACHEDZI", rwdata = "NONCACHEDRW"
/* allocate a non-cacheable buffer for D-cacheable region */
#ifdef __MTK_TARGET__
__attribute__ ((zero_init, section ("NONCACHEDZI"), aligned(4))) 
#endif /* __MTK_TARGET__ */
static UsbMs_CSW g_UsbMS_CSW;
//#pragma arm section zidata, rwdata


#ifdef __USB_MASS_STORAGE_CDROM_ENABLE__
//#ifdef __USB_MODEM_CARD_SUPPORT__
//static kal_bool cdrom_prevent_removal = KAL_TRUE;
//#endif
static kal_bool cdrom_ready = KAL_FALSE;
static kal_bool cdrom_request_ready = KAL_FALSE;
#endif

/************************************************************
        Tx/Rx path state machine functions
*************************************************************/
void USB_Ms_State_Main(ilm_struct *p_recv_ilm)
{
	UsbMs_CBW *CBW = (UsbMs_CBW*)g_UsbMS.CBWdata;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

	//if USB reset just happen,do nothing if message is not MSG_ID_USB_MSDRV_RESET_IND.(ignore previous message.)
	if ((p_recv_ilm->msg_id != MSG_ID_USB_MSDRV_RESET_IND) && ((g_UsbMS.usb_reset == KAL_TRUE)||(g_UsbMS.ms_is_reset == KAL_TRUE)))//receive reset
	{
		drv_trace0(TRACE_FUNC, (kal_uint32)USBMS_RESET);
	//	USB_Dbg_Trace(USB_MS_RESET_MSG, (kal_uint32)(p_recv_ilm->msg_id) , 0);
			return;
	}

	switch(p_recv_ilm->msg_id)
	{
	case MSG_ID_USB_MSDRV_REC_DONE_CONF:
		/* Receive data from DMA callback */
		USB_Ms_Recv_Data(p_recv_ilm->local_para_ptr);
		break;

	case MSG_ID_USB_MSDRV_TRX_DONE_CONF:
		/* Transmitted data from DMA callback */
		USB_Ms_Transmit_Data(p_recv_ilm->local_para_ptr);
		break;

	case MSG_ID_USB_MSDRV_CLEAR_STALL_REQ:
		g_UsbMS.nState = USBMS_IDLE;
//		g_UsbMS.nState = USBMS_GETNEXTCMD;
		g_UsbMS.CSWStatusError = 0x01;
		/* Switch RX endpoint state to use FIFO */
		if(USB_RxEP_Usage(g_UsbMS.rxpipe->byEP) == USB_EP_STATE_DMA)
			USB_Config_RxEP_Type(g_UsbMS.rxpipe->byEP, USB_ENDPT_BULK, KAL_FALSE);

		USB_Ms_Generate_Csw(&g_UsbMS_CSW, CBW);
		USB_Ms_BuildTx(&g_UsbMS_CSW, 13);
		break;

	case MSG_ID_USB_MSDRV_RESET_IND:
		/* Reset from reset signal or class specific EP0 RESET command */
		USB_Dbg_Trace(USB_MS_RECEIVE_RESET_MSG, 0, 0);
		g_UsbMS.nState = USBMS_IDLE;
//		g_UsbMS.pre_State = USBMS_RESET_STATE;
		g_UsbMS.usb_reset = KAL_FALSE;
		g_UsbMS.ms_is_reset = KAL_FALSE;
//		USB_Ms_BuildRx(g_UsbMS.CBWdata, 31);
		g_UsbMS.is_send_usb_reset_ilm = KAL_TRUE;


		break;

	default:
		ASSERT(0);
		break;
	}
}


/* RX path state machine */
static void USB_Ms_Recv_Data(local_para_struct *buf)
{
	UsbMs_CBW   *CBW;
	kal_uint8   *CBWCB;
	kal_uint8   sector_num;
	usb_ms_rec_done_conf_struct *ptr=(usb_ms_rec_done_conf_struct *)buf;


	switch(g_UsbMS.nState)
	{
	case USBMS_IDLE:
		if (ptr->nBytesRecv != 31)
		{
			EXT_ASSERT(0, (kal_uint32)ptr->nBytesRecv, 0, 0);
		}
		USB_Ms_Cmd(g_UsbMS.CBWdata);
		break;

	case USBMS_RX:
		CBW = (UsbMs_CBW*)g_UsbMS.CBWdata;
		CBWCB = (kal_uint8 *)CBW->CBWCB;

		if((CBWCB[0] == USBMS_WRITE10)||(CBWCB[0] == USBMS_WRITE12))
		{
			sector_num = ptr->nBytesRecv/512;
			USB_Ms_Handle_Write(g_UsbMS.current_LUN, CBW, sector_num);
		}
		else  /*if (CBWCB[0] == USBMS_CMD_Write)*/
		{
			EXT_ASSERT(0, (kal_uint32)CBW->CBWCB[0], 0, 0);
		}
		break;

//	case USBMS_GETNEXTCMD:
	case USBMS_ACK:
	case USBMS_TX:
	default:
		EXT_ASSERT(0, (kal_uint32)g_UsbMS.nState, 0, 0);
		break;
	}
}


/* TX path state machine */
static void USB_Ms_Transmit_Data(local_para_struct *buf)
{
	UsbMs_CBW *CBW = (UsbMs_CBW*)g_UsbMS.CBWdata;


	switch(g_UsbMS.nState)
	{
//	case USBMS_GETNEXTCMD:
//		g_UsbMS.nState = USBMS_IDLE;
//		USB_Ms_BuildRx(g_UsbMS.CBWdata, 31);
//		break;

	case USBMS_ACK:
		/*Send CSW*/
		g_UsbMS.nState = USBMS_IDLE;
//		g_UsbMS.nState = USBMS_GETNEXTCMD;
		/* Switch RX endpoint state to use FIFO */
		//USB_Config_RxEP_Type(g_UsbMS.rxpipe->byEP, USB_ENDPT_BULK, KAL_FALSE);
		//USB_Ms_Generate_Csw(&g_UsbMS_CSW, CBW);
		//USB_Ms_BuildTx(&g_UsbMS_CSW, 13);
		USB_Ms_Build_Tx_CWS(&g_UsbMS_CSW, CBW);
		break;

	case USBMS_TX:
		if((CBW->CBWCB[0] == USBMS_READ10)||(CBW->CBWCB[0] == USBMS_READ12))
		{
			USB_Ms_Handle_Read(g_UsbMS.current_LUN, CBW);
		}
		else
		{
			EXT_ASSERT(0, (kal_uint32)CBW->CBWCB[0], 0, 0);
		}
		break;

	case USBMS_IDLE:
	case USBMS_RX:
	default:
		EXT_ASSERT(0, (kal_uint32)g_UsbMS.nState, 0, 0);
		break;
	}
}


/************************************************************
        utility functions
*************************************************************/
/* Generate CSW element according to CBW and keep status */
static void USB_Ms_Generate_Csw(UsbMs_CSW *CSW, UsbMs_CBW *CBW)
{
	CSW->dCSWSignature = 0x53425355;
	CSW->dCSWTag = CBW->dCBWTag;
	CSW->dCSWDataResidue = g_UsbMS.CSWDataResidue;
	CSW->bmCSWStatus = g_UsbMS.CSWStatusError;
	g_UsbMS.CSWStatusError = 0x00;
	g_UsbMS.CSWDataResidue = 0;
}


/* inverse scr to dst, total len*/
static void USB_Ms_MemInverse(void *src, void *dst, kal_uint16 len)
{
	kal_uint32  index;
	kal_uint8 *li_data = (kal_uint8 *)src;
	kal_uint8 *bi_data = (kal_uint8 *)dst;
	li_data += (len-1);

	for(index = 0; index < len; index++)
	{
		*(bi_data+index) = *(li_data-index);
	}
}

/* Use this function to save ROM size
 * Action1: Switch RX endpoint state to use FIFO
 * Action2: Build 13 bytes CWS
 */
static void USB_Ms_Build_Tx_CWS(UsbMs_CSW *CSW, UsbMs_CBW *CBW)
{
	USB_Config_RxEP_Type(g_UsbMS.rxpipe->byEP, USB_ENDPT_BULK, KAL_FALSE);
	USB_Ms_Generate_Csw(&g_UsbMS_CSW, CBW);
	USB_Ms_BuildTx(&g_UsbMS_CSW, 13);
#if defined(DRV_USB_POWER_DOWN_SUPPORT)&&defined(MTK_SLEEP_ENABLE)&&defined(DRV_USB_SLEEP_SUPPORT)
	L1SM_SleepEnable(usbms_pdn_handle);
#endif
}



/************************************************************
        CBW parse command functions
*************************************************************/

/* parse CBW command */
void USB_Ms_Cmd(void *data)
{
	UsbMs_CBW *CBW = (UsbMs_CBW *)data;
	kal_uint8   *CBWCB;


	CBWCB = (kal_uint8*)CBW->CBWCB;

//	if((CBW->dCBWSignature != 0x43425355)||(CBW->bCBWLUN > g_UsbMS.max_LUN) ||(USB_Get_DMA_Rx_Left_Count(g_UsbMS.rxpipe->byEP) != 0))
	if((CBW->dCBWSignature != 0x43425355)||(CBW->bCBWLUN > g_UsbMS.max_LUN))
	{
		/* Run in task */
//		USB_Dbg_Trace(USB_MS_CMD_CBW_IS_NOT_VALID, USB_Get_DMA_Rx_Left_Count(g_UsbMS.rxpipe->byEP), 0);
		USB_Dbg_Trace(USB_MS_CMD_CBW_IS_NOT_VALID, 0, 0);
		g_UsbMS.cbw_is_vaild = KAL_FALSE;
		USB_CtrlEPStall(g_UsbMS.txpipe->byEP, USB_EP_TX_DIR, KAL_TRUE);
		USB_CtrlEPStall(g_UsbMS.rxpipe->byEP, USB_EP_RX_DIR, KAL_TRUE);
		return;
	}

	/* If we accept this packet, it means it is a valid CBW */
	g_UsbMS.cbw_is_vaild = KAL_TRUE;

	/* keep current LUN */
	g_UsbMS.current_LUN = CBW->bCBWLUN;

	/* determine state */
	if (CBW->dCBWDataTransferLength!=0)
	{
		if (CBW->bmCBWFlags & USBMS_DIR_IN)
			g_UsbMS.nState = USBMS_TX;
		else
			g_UsbMS.nState = USBMS_RX;
	}

	drv_trace1(TRACE_FUNC, (kal_uint32)USBMS_CBWCMD, CBWCB[0]);
#if defined(DRV_USB_POWER_DOWN_SUPPORT)&&defined(MTK_SLEEP_ENABLE)&&defined(DRV_USB_SLEEP_SUPPORT)
	L1SM_SleepDisable(usbms_pdn_handle);
#endif

	/* parse command */
	switch(CBWCB[0])
	{
//	case USBMS_FORMAT_UNIT:
//		USB_Ms_Cmd_Format(CBW->bCBWLUN, CBW);
//		break;
	case USBMS_INQUIRY:
		USB_Dbg_Trace(USB_MS_CMD_INQUIRY, 0, 0);
		USB_Ms_Cmd_Inquiry(CBW->bCBWLUN, CBW);
		break;
	case USBMS_TEST_UNIT_READY:
		USB_Dbg_Trace(USB_MS_CMD_TESTUNITREADY, 0, 0);
		USB_Ms_Cmd_Test_Unit_Ready(CBW->bCBWLUN, CBW);
		break;
	case USBMS_PREVALLOW_MEDIA_REMOVL:
		USB_Dbg_Trace(USB_MS_CMD_PREVALLOW_MEDIA_REMOVL, 0, 0);
		USB_Ms_Cmd_Prev_Media_Removal(CBW->bCBWLUN, CBW);
		break;
	case USBMS_WRITE10:
		USB_Dbg_Trace(USB_MS_CMD_USBMS_WRITE10, 0, 0);
		USB_Ms_MemInverse(&CBWCB[7], &g_UsbMS.rw_cmd.BlkLen, 2);
		USB_Ms_Cmd_Write(CBW->bCBWLUN, CBW);
		break;
	case USBMS_WRITE12:
		USB_Dbg_Trace(USB_MS_CMD_USBMS_WRITE12, 0, 0);
		USB_Ms_MemInverse(&CBWCB[6], &g_UsbMS.rw_cmd.BlkLen, 4);
		USB_Ms_Cmd_Write(CBW->bCBWLUN,CBW);
		break;
	case USBMS_READ10:
		USB_Dbg_Trace(USB_MS_CMD_USBMS_READ10, 0, 0);
		USB_Ms_MemInverse(&CBWCB[7], &g_UsbMS.rw_cmd.BlkLen, 2);
		USB_Ms_Cmd_Read(CBW->bCBWLUN, CBW);
		break;
	case USBMS_READ12:
		USB_Dbg_Trace(USB_MS_CMD_USBMS_READ12, 0, 0);
		USB_Ms_MemInverse(&CBWCB[6], &g_UsbMS.rw_cmd.BlkLen, 4);
		USB_Ms_Cmd_Read(CBW->bCBWLUN,CBW);
		break;
	case USBMS_READ_CAPACITY:
		USB_Dbg_Trace(USB_MS_CMD_READ_CAPACITY, 0, 0);
		USB_Ms_Cmd_Read_Capacity(CBW->bCBWLUN, CBW);
		break;
	case USBMS_READ_FORMATCAPACITY:
		USB_Dbg_Trace(USB_MS_CMD_READ_FORMATCAPACITY, 0, 0);
		USB_Ms_Cmd_Read_FormatCapacity(CBW->bCBWLUN, CBW);
		break;
	case USBMS_REQUESTSENSE:
		USB_Dbg_Trace(USB_MS_CMD_REQUESTSENSE, 0, 0);
		USB_Ms_Cmd_RequestSense(CBW->bCBWLUN, CBW);
		break;
	case USBMS_VERIFY:
		USB_Dbg_Trace(USB_MS_CMD_USBMS_VERIFY, 0, 0);
		USB_Ms_Cmd_Verify(CBW->bCBWLUN, CBW);
		break;
	case USBMS_MODE_SENSE:      /* Mode Sense */
		USB_Dbg_Trace(USB_MS_CMD_MODE_SENSE, 0, 0);
		USB_Ms_Cmd_ModeSense(CBW->bCBWLUN, CBW);
		break;
	case USBMS_MODE_SENSE6:      /*Mode Sense*/
		USB_Dbg_Trace(USB_MS_CMD_MODE_SENSE6, 0, 0);
		USB_Ms_Cmd_ModeSense6(CBW->bCBWLUN, CBW);
		break;
	case USBMS_START_STOP_UNIT:
		USB_Dbg_Trace(USB_MS_CMD_START_STOP_UNIT, 0, 0);
		USB_Ms_Cmd_Start_Stop_Unit(CBW->bCBWLUN, CBW);
		break;
#ifdef __USB_MASS_STORAGE_CDROM_ENABLE__
	case USBMS_READ_TOC:
		USB_Dbg_Trace(USB_MS_CMD_READ_TOC, 0, 0);
		USB_Ms_Cmd_ReadToc(CBW->bCBWLUN, CBW);
		break;
	case USBMS_VENDOR_CMD:
		USB_Dbg_Trace(USB_MS_CMD_VENDOR, USBMS_VENDOR_CMD, 0);
		USB_Ms_Vendor(CBW->bCBWLUN, CBW);
		break;
#endif //__USB_MODEM_CARD_SUPPORT__
	case USBMS_MODE_SELECT:
	case USBMS_MODE_SELECT6:
	default:
		USB_Ms_Cmd_Unknown(CBW);
		break;
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
#endif


/* check media status and generate correspongind status for CSW */
static void USB_Ms_State_Checkmedia_Exist(kal_uint8 LUN)
{
	USB_STORAGE_DEV_STATUS   msdc_status;

	msdc_status = USB_Ms_Checkmedia_Exist(LUN);
	
#ifdef __USB_MASS_STORAGE_CDROM_ENABLE__
	if ((USB_Ms_Dev_Type(LUN) == USB_STORAGE_DEV_CDROM)&&((cdrom_request_ready == KAL_FALSE)))
	{
		// for windows 2000
		msdc_status = USB_STORAGE_DEV_STATUS_NOMEDIA;
	}
#endif

	if (g_UsbMS.power_off_state[LUN] == KAL_FALSE)
	{
		switch(msdc_status)
		{
			case USB_STORAGE_DEV_STATUS_OK:
			case USB_STORAGE_DEV_STATUS_WP:
				g_UsbMS.sensePtr = (kal_uint8 *)senseOk;
				g_UsbMS.CSWStatusError = 0x00;
				break;
			case USB_STORAGE_DEV_STATUS_MEDIA_CHANGE:
				g_UsbMS.sensePtr = (kal_uint8 *)senseMediaChanged;
				g_UsbMS.CSWStatusError = 0x01;
				break;
			case USB_STORAGE_DEV_STATUS_NOMEDIA:
				g_UsbMS.sensePtr = (kal_uint8 *)senseNoMedia;
				g_UsbMS.CSWStatusError = 0x01;
				break;
			default:
				ASSERT(0);
			break;
		}
	}
	else
	{
		g_UsbMS.sensePtr = (kal_uint8 *)senseNoMedia;
		g_UsbMS.CSWStatusError = 0x01;
	}
}


/* handle CBW USBMS_INQUIRY command */
static void USB_Ms_Cmd_Inquiry(kal_uint8 LUN, UsbMs_CBW *CBW)
{
#ifdef __USB_OTG_TX_TEST__
		g_UsbMS.device_ms_tx_test_flag = KAL_TRUE;
#endif
#ifdef __USB_MASS_STORAGE_CDROM_ENABLE__
	kal_uint8  *cdrom_inquire = (kal_uint8 *)g_UsbMS.disk_buffer;
#endif

	if(CBW->dCBWDataTransferLength == 0)
	{
		USB_Ms_State_Checkmedia_Exist(LUN);
		g_UsbMS.nState = USBMS_IDLE;
//		g_UsbMS.nState = USBMS_GETNEXTCMD;
		g_UsbMS.CSWDataResidue = 0;
		/* Switch RX endpoint state to use FIFO */
		//USB_Config_RxEP_Type(g_UsbMS.rxpipe->byEP, USB_ENDPT_BULK, KAL_FALSE);
		//USB_Ms_Generate_Csw(&g_UsbMS_CSW, CBW);
		//USB_Ms_BuildTx(&g_UsbMS_CSW, 13);
		USB_Ms_Build_Tx_CWS(&g_UsbMS_CSW, CBW);
	}
	else
	{
		/*Windows Vista and 7 will allocate 0xFF byte directly. We shouldn't STALL it*/
		if(CBW->dCBWDataTransferLength > g_UsbMS.ms_param->inquire_size)
			CBW->dCBWDataTransferLength = g_UsbMS.ms_param->inquire_size;
			
		//if(CBW->dCBWDataTransferLength <= ((kal_uint32)g_UsbMS.ms_param->inquire_size))
		{
			g_UsbMS.sensePtr = (kal_uint8 *)senseOk;
			g_UsbMS.CSWStatusError = 0x00;
			g_UsbMS.nState = USBMS_ACK;
			g_UsbMS.CSWDataResidue = 0;
#ifdef __USB_MASS_STORAGE_CDROM_ENABLE__
			if (USB_Ms_Dev_Type(LUN) == USB_STORAGE_DEV_CDROM)
			{
				kal_mem_cpy(cdrom_inquire, g_UsbMS.ms_param->inquire_data, g_UsbMS.ms_param->inquire_size);
				cdrom_inquire[0]=0x05;
				USB_Ms_BuildTx((kal_uint8 *)cdrom_inquire, CBW->dCBWDataTransferLength);
			}
			else
#endif
			{
				USB_Ms_BuildTx((kal_uint8 *)g_UsbMS.ms_param->inquire_data, CBW->dCBWDataTransferLength);
			}
		}
		//else
		//{
		//	g_UsbMS.CSWDataResidue = CBW->dCBWDataTransferLength;
		//	USB_CtrlEPStall(g_UsbMS.txpipe->byEP, USB_EP_TX_DIR, KAL_TRUE);
		//}
	}
}


/* handle CBW USBMS_TEST_UNIT_READY command */
static void USB_Ms_Cmd_Test_Unit_Ready(kal_uint8 LUN, UsbMs_CBW *CBW)
{
	if(CBW->dCBWDataTransferLength != 0)
	{
		if(g_UsbMS.nState == USBMS_RX)
		{
			USB_CtrlEPStall(g_UsbMS.rxpipe->byEP, USB_EP_RX_DIR, KAL_TRUE);
		}
		else
		{
			USB_CtrlEPStall(g_UsbMS.txpipe->byEP, USB_EP_TX_DIR, KAL_TRUE);
		}
		g_UsbMS.CSWDataResidue = CBW->dCBWDataTransferLength;
	}
	else
	{
		USB_Ms_State_Checkmedia_Exist(LUN);
		g_UsbMS.nState = USBMS_IDLE;
		g_UsbMS.prev_write_fail[LUN] = KAL_FALSE;
		
//		g_UsbMS.nState = USBMS_GETNEXTCMD;
		/* Switch RX endpoint state to use FIFO */
		//USB_Config_RxEP_Type(g_UsbMS.rxpipe->byEP, USB_ENDPT_BULK, KAL_FALSE);
		//USB_Ms_Generate_Csw(&g_UsbMS_CSW, CBW);
		//USB_Ms_BuildTx(&g_UsbMS_CSW, 13);
		USB_Ms_Build_Tx_CWS(&g_UsbMS_CSW, CBW);
		
#ifdef __USB_MASS_STORAGE_CDROM_ENABLE__
		if (USB_Ms_Dev_Type(LUN) == USB_STORAGE_DEV_CDROM)
		{
			cdrom_ready = KAL_TRUE;
		}
#endif
	}
}


/* handle CBW USBMS_PREVALLOW_MEDIA_REMOVL command */
static void USB_Ms_Cmd_Prev_Media_Removal(kal_uint8 LUN, UsbMs_CBW *CBW)
{
	kal_bool msdc_status;

	if(USB_Ms_Dev_Type(LUN) == USB_STORAGE_DEV_CDROM)
	{
		USB_Ms_State_Checkmedia_Exist(LUN);
	
		if (g_UsbMS.CSWStatusError == 0x00)
		{
			msdc_status = USB_Ms_Prevmedia_Removal(LUN, KAL_TRUE);
	
			if (msdc_status == KAL_FALSE)
				USB_Ms_State_Checkmedia_Exist(LUN);
		}
	}
	else
	{
		g_UsbMS.sensePtr = (kal_uint8 *)senseInvalidFieldInCDB;
		g_UsbMS.CSWStatusError = 0x01;		
	}
	
#if defined(__USB_MASS_STORAGE_CDROM_ENABLE__)&&defined(__USB_MODEM_CARD_SUPPORT__)
	/* usb force eject solution, thus no need this variable*/
	
	//if (((CBW->CBWCB[4])& 0x03) == 0x00)
	//{
	//	cdrom_prevent_removal = KAL_FALSE;	//allow
	//}
	//else
	//{
	//	cdrom_prevent_removal = KAL_TRUE;
	//}
#endif

	g_UsbMS.nState = USBMS_IDLE;
//	g_UsbMS.nState = USBMS_GETNEXTCMD;
	/* Switch RX endpoint state to use FIFO */
	//USB_Config_RxEP_Type(g_UsbMS.rxpipe->byEP, USB_ENDPT_BULK, KAL_FALSE);
	//USB_Ms_Generate_Csw(&g_UsbMS_CSW,CBW);
	//USB_Ms_BuildTx(&g_UsbMS_CSW, 13);
	USB_Ms_Build_Tx_CWS(&g_UsbMS_CSW, CBW);
}


/* handle CBW USBMS_READ_CAPACITY command */
static void USB_Ms_Cmd_Read_Capacity(kal_uint8 LUN, UsbMs_CBW *CBW)
{
	kal_uint32 LBA;
	kal_uint32 len;
	kal_bool msdc_status;
	Read_Capacity_Info *Capacity_Info = (Read_Capacity_Info *)g_UsbMS.disk_buffer;

	USB_Ms_State_Checkmedia_Exist(LUN);

	if (g_UsbMS.CSWStatusError == 0x00)
	{
		msdc_status = USB_Ms_Read_Capacity(LUN, &LBA, &len);

		if(msdc_status == KAL_FALSE)
		{
			/* device exist but not ready yet, must return error */
			g_UsbMS.CSWStatusError = 0x01;
//			USB_Ms_State_Checkmedia_Exist(LUN);

			/*Fail case*/
			LBA = 0xFFFFFFFF;
			len = 0x200;
		}
	}
	else
	{
		/* Fail case */
		LBA = 0xFFFFFFFF;
		len = 0x200;
	}

	USB_Ms_MemInverse(&LBA, &Capacity_Info->LastBA, 4);
	USB_Ms_MemInverse(&len, &Capacity_Info->BlkLen, 4);
	g_UsbMS.nState = USBMS_ACK;
	USB_Ms_BuildTx(Capacity_Info, 8);
}


/* handle CBW USBMS_READ_FORMATCAPACITY command */
static void USB_Ms_Cmd_Read_FormatCapacity(kal_uint8 LUN, UsbMs_CBW *CBW)
{
	kal_uint32 msdc_blk_no;
	kal_uint32 msdc_blk_len;
	kal_uint32 len;
	kal_uint8  *ReadformatCapacity_Data = (kal_uint8 *)g_UsbMS.disk_buffer;
	kal_uint8 *CBWCB = CBW->CBWCB;


	len = (kal_uint8)CBWCB[7];
	len <<= 8;
	len |= (kal_uint8)CBWCB[8];

	kal_mem_set(ReadformatCapacity_Data, 0x00, 12);

	*(ReadformatCapacity_Data+3) = 0x08;

	msdc_blk_no = 0xFFFFFFFF;
	msdc_blk_len = 0x03000200;
	g_UsbMS.CSWStatusError = 0x00;

	USB_Ms_MemInverse(&msdc_blk_no, (ReadformatCapacity_Data+4), 4);
	USB_Ms_MemInverse(&msdc_blk_len, (ReadformatCapacity_Data+8), 4);

	g_UsbMS.nState = USBMS_ACK;

	//if (len >= 12)
	//	USB_Ms_BuildTx(ReadformatCapacity_Data, 12);
	//else
	//	USB_Ms_BuildTx(ReadformatCapacity_Data, len);
	
	if (len > 12)
		len = 12;
	USB_Ms_BuildTx(ReadformatCapacity_Data, len);
}


/* handle CBW USBMS_REQUESTSENSE command */
static void USB_Ms_Cmd_RequestSense(kal_uint8 LUN, UsbMs_CBW *CBW)
{
	kal_uint32 dCBWDataTransferLength = CBW->dCBWDataTransferLength;	
	
	if(dCBWDataTransferLength == 0)
	{
		USB_Ms_State_Checkmedia_Exist(LUN);
		g_UsbMS.nState = USBMS_IDLE;
//		g_UsbMS.nState = USBMS_GETNEXTCMD;
		g_UsbMS.CSWDataResidue = 0;
		/* Switch RX endpoint state to use FIFO */
		//USB_Config_RxEP_Type(g_UsbMS.rxpipe->byEP, USB_ENDPT_BULK, KAL_FALSE);
		//USB_Ms_Generate_Csw(&g_UsbMS_CSW, CBW);
		//USB_Ms_BuildTx(&g_UsbMS_CSW, 13);
		USB_Ms_Build_Tx_CWS(&g_UsbMS_CSW, CBW);
	}
	else
	{
		g_UsbMS.CSWStatusError = 0x00;
		g_UsbMS.nState = USBMS_ACK;
		g_UsbMS.CSWDataResidue = 0;

		/*MAUI_01114796
		If PC send wrong length command,USB should return stall.
		PC sned Request Mode to ask error reason, if this command request more than 18 Bytres data,
		Device should return at lease 18 bytes data instead of stall. */
		//if(len <= 18)
		//{
		//	USB_Ms_BuildTx(g_UsbMS.sensePtr, len);
		//}
		//else
		//{
		//	USB_Ms_BuildTx(g_UsbMS.sensePtr, 18);
		//}
		if(dCBWDataTransferLength > 18)
		{
			dCBWDataTransferLength = 18;
		}
		USB_Ms_BuildTx(g_UsbMS.sensePtr, dCBWDataTransferLength);
		
#ifdef __USB_MASS_STORAGE_CDROM_ENABLE__
		if (USB_Ms_Dev_Type(LUN) == USB_STORAGE_DEV_CDROM)
		{
			cdrom_request_ready = KAL_TRUE;
		}
#endif
	}
}


/* handle CBW USBMS_VERIFY command */
static void USB_Ms_Cmd_Verify(kal_uint8 LUN, UsbMs_CBW *CBW)
{
	g_UsbMS.nState = USBMS_IDLE;
//	g_UsbMS.nState = USBMS_GETNEXTCMD;
	USB_Ms_State_Checkmedia_Exist(LUN);
	/* Switch RX endpoint state to use FIFO */
	//USB_Config_RxEP_Type(g_UsbMS.rxpipe->byEP, USB_ENDPT_BULK, KAL_FALSE);
	//USB_Ms_Generate_Csw(&g_UsbMS_CSW, CBW);
	//USB_Ms_BuildTx(&g_UsbMS_CSW, 13);
	USB_Ms_Build_Tx_CWS(&g_UsbMS_CSW, CBW);
}


/* handle CBW USBMS_MODE_SENSE6 command */
static void USB_Ms_Cmd_ModeSense(kal_uint8 LUN, UsbMs_CBW *CBW)
{
	USB_STORAGE_DEV_STATUS result;
	kal_uint8 *ModeSense_Data = (kal_uint8 *)g_UsbMS.disk_buffer;


	USB_Ms_State_Checkmedia_Exist(LUN);
	result = USB_Ms_Checkmedia_Exist(LUN);

	*(ModeSense_Data) = 0x00;
	*(ModeSense_Data+1) = 0x06;
	*(ModeSense_Data+2) = 0x00;
        
	//if(result == USB_STORAGE_DEV_STATUS_WP)
	//	*(ModeSense_Data+3) = 0x80;
	//else
	//	*(ModeSense_Data+3) = 0x00;
	 *(ModeSense_Data+3) = (result == USB_STORAGE_DEV_STATUS_WP)? 0x80 : 0x00;
        
	*(ModeSense_Data+4) = 0x00;
	*(ModeSense_Data+5) = 0x00;
	*(ModeSense_Data+6) = 0x00;
	*(ModeSense_Data+7) = 0x00;

	g_UsbMS.nState = USBMS_ACK;
	USB_Ms_BuildTx(ModeSense_Data, 8);
}


/* Handle CBW USBMS_MODE_SENSE6 command */
static void USB_Ms_Cmd_ModeSense6(kal_uint8 LUN, UsbMs_CBW *CBW)
{
	USB_STORAGE_DEV_STATUS result;
	kal_uint8 *ModeSense6_Data = (kal_uint8 *)g_UsbMS.disk_buffer;


	USB_Ms_State_Checkmedia_Exist(LUN);
	result = USB_Ms_Checkmedia_Exist(LUN);

	*(ModeSense6_Data) = 0x03;
	*(ModeSense6_Data+1) = 0x00;
	if (result == USB_STORAGE_DEV_STATUS_WP)
		*(ModeSense6_Data+2) = 0x80;
	else
		*(ModeSense6_Data+2) = 0x00;
	*(ModeSense6_Data+3) = 0x00;

	g_UsbMS.nState = USBMS_ACK;
	USB_Ms_BuildTx(ModeSense6_Data,4);
}


static void USB_Ms_Cmd_Start_Stop_Unit(kal_uint8 LUN, UsbMs_CBW *CBW)
{
#if defined(__USB_MASS_STORAGE_CDROM_ENABLE__)&&defined(__USB_MODEM_CARD_SUPPORT__)
	kal_uint8 count = 0;
	kal_bool bEPEmpty;
#endif//defined(__USB_MASS_STORAGE_CDROM_ENABLE__)&&defined(__USB_MODEM_CARD_SUPPORT__)
	
	g_UsbMS.nState = USBMS_IDLE;
//	g_UsbMS.nState = USBMS_GETNEXTCMD;
	USB_Ms_State_Checkmedia_Exist(LUN);
	/* Switch RX endpoint state to use FIFO */
	//USB_Config_RxEP_Type(g_UsbMS.rxpipe->byEP, USB_ENDPT_BULK, KAL_FALSE);
	//USB_Ms_Generate_Csw(&g_UsbMS_CSW, CBW);
	//USB_Ms_BuildTx(&g_UsbMS_CSW, 13);
	USB_Ms_Build_Tx_CWS(&g_UsbMS_CSW, CBW);

	
	//00 - Stop motor    = 0x00
	//01 - Start motor   = 0x01
	//10 - Eject media   = 0x02
	//11 - Load media    = 0x03
	if ((CBW->CBWCB[4]& 0x03) == 0x01)
	{
		g_UsbMS.power_off_state[LUN] = KAL_FALSE;	//start
	}
	else
	{
		g_UsbMS.power_off_state[LUN] = KAL_TRUE;	//Off
#ifdef __TC01__
/* under construction !*/
#endif //__TC01__
#if defined(__USB_MASS_STORAGE_CDROM_ENABLE__)&&defined(__USB_MODEM_CARD_SUPPORT__)
		//if (cdrom_prevent_removal == KAL_FALSE && ((CBW->CBWCB[4]& 0x03) == 0x02))
		if (((CBW->CBWCB[4]& 0x03) == 0x02) && (USB_Ms_Dev_Type(LUN) == USB_STORAGE_DEV_CDROM))// Force Eject
		{
			if(((custom_em_get_usb_cdrom_config() & 0x04) == 0x04)) //Return : 0 for MBIM ; 1 for ECM
				g_UsbMode.usb_comport_driver = USB_COMPORT_MAC;
			else
				g_UsbMode.usb_comport_driver = USB_COMPORT_WIN;
			
		 	do{
					count++;
					kal_sleep_task(1);
					bEPEmpty = USB_Is_EP_Tx_Empty(g_UsbMS.txpipe->byEP, USB_ENDPT_BULK);
			}while((bEPEmpty == KAL_FALSE)&&(count != USBMS_VENDOR_CMD_TIMEOUT)&&(USB_Get_Device_Type() != USB_UNKOWN));
	    	    	
			/* Disable D+ pull high, but plug out is false */
			//USB_Release_Type(KAL_TRUE, KAL_FALSE);
			//kal_sleep_task(100);
			//USB_Config_Type(USB_COMPOSITE_MULTI_COM, KAL_TRUE, NULL);
			USB_Mode_Switch(USB_COMPOSITE_DEVICES);
		}
#endif//defined(__USB_MASS_STORAGE_CDROM_ENABLE__)&&defined(__USB_MODEM_CARD_SUPPORT__)
	}
}


#ifdef __USB_MASS_STORAGE_CDROM_ENABLE__
static void USB_Ms_Cmd_ReadToc(kal_uint8 LUN, UsbMs_CBW *CBW)
{
	kal_uint8 *toc_info = (kal_uint8 *)g_UsbMS.disk_buffer;
	
	if(CBW->dCBWDataTransferLength == 0)
	{
		USB_Ms_State_Checkmedia_Exist(LUN);
		g_UsbMS.nState = USBMS_IDLE;
		g_UsbMS.CSWDataResidue = 0;
		/* Switch RX endpoint state to use FIFO */
		//USB_Config_RxEP_Type(g_UsbMS.rxpipe->byEP, USB_ENDPT_BULK, KAL_FALSE);
		//USB_Ms_Generate_Csw(&g_UsbMS_CSW, CBW);
		//USB_Ms_BuildTx(&g_UsbMS_CSW, 13);
		USB_Ms_Build_Tx_CWS(&g_UsbMS_CSW, CBW);
	}
	else
	{
		g_UsbMS.CSWStatusError = 0x00;
		g_UsbMS.nState = USBMS_ACK;
		g_UsbMS.CSWDataResidue = 0;
		if(CBW->dCBWDataTransferLength <= USBSCSI_CMD_READ_TOC_REPLY_LEN_20)
		{
			kal_mem_cpy(toc_info, TOC_REPLY_LEN_20, CBW->dCBWDataTransferLength);
			toc_info[1]=CBW->dCBWDataTransferLength-2;
			USB_Ms_BuildTx((kal_uint8 *)toc_info, CBW->dCBWDataTransferLength);
		}
		else if(CBW->dCBWDataTransferLength <= USBSCSI_CMD_READ_TOC_REPLY_LEN_48)
		{
			USB_Ms_BuildTx((kal_uint8 *)TOC_REPLY_LEN_48, CBW->dCBWDataTransferLength);
		}
		else
		{
			USB_Ms_BuildTx((kal_uint8 *)TOC_REPLY_LEN_48, USBSCSI_CMD_READ_TOC_REPLY_LEN_48);
		}
	}
}

static void USB_Ms_Vendor(kal_uint8 LUN, UsbMs_CBW *CBW)
{
#if defined(__USB_MODEM_CARD_SUPPORT__)||defined(__USB_DATA_CONNECTION__)
	kal_uint8 *CBWCB = CBW->CBWCB;
	kal_uint8 count = 0;
	kal_bool bEPEmpty;
	kal_bool bvaild_cmd = KAL_FALSE;
	kal_bool breboot = KAL_FALSE;
#if defined(__USB_DATA_CONNECTION__)
	drvuem_usbcfg_req_struct *usbcfg;
#endif
	//ilm_struct *usb_ilm;

	g_UsbMS.CSWStatusError = 0x00;
	g_UsbMS.CSWDataResidue = 0;
	
	drv_trace2(TRACE_FUNC, (kal_uint32)USB_CBW_DATA,CBWCB[1],CBWCB[2]);
	
	if(CBWCB[1]==USBMS_VENDOR_CMD_SUB_SET && CBWCB[2]==USBMS_VENDOR_CMD_SUB_SET_MAC)
	{
#if defined(__USB_MODEM_CARD_SUPPORT__)
		g_UsbMode.usb_comport_driver = USB_COMPORT_MAC;
		drv_trace0(TRACE_FUNC, (kal_uint32)PC_OS_IS_MAC);
#endif
		bvaild_cmd = KAL_TRUE;
	}
	else if(CBWCB[1]==USBMS_VENDOR_CMD_SUB_SET && CBWCB[2]==USBMS_VENDOR_CMD_SUB_SET_WIN)
	{
#if defined(__USB_MODEM_CARD_SUPPORT__)
		g_UsbMode.usb_comport_driver = USB_COMPORT_WIN;
		drv_trace0(TRACE_FUNC, (kal_uint32)PC_OS_IS_WIN);
#endif
		bvaild_cmd = KAL_TRUE;
	}
	else if(CBWCB[1]==USBMS_VENDOR_CMD_SUB_SET && CBWCB[2]==USBMS_VENDOR_CMD_SUB_SET_LINUX)
	{
#if defined(__USB_MODEM_CARD_SUPPORT__)
		g_UsbMode.usb_comport_driver = USB_COMPORT_LINUX;
		drv_trace0(TRACE_FUNC, (kal_uint32)PC_OS_IS_LINUX);
#endif
		bvaild_cmd = KAL_TRUE;
	}
#if defined(__USB_MODEM_CARD_SUPPORT__)
	else if(CBWCB[1]==USBMS_VENDOR_CMD_SUB_META)
	{
		bvaild_cmd = KAL_TRUE;
		breboot = KAL_TRUE;
	}
#endif

	if(((custom_em_get_usb_cdrom_config() & 0x04) == 0x04)) //Return : 0 for MBIM ; 1 for ECM
		g_UsbMode.usb_comport_driver = USB_COMPORT_MAC;
	else
		g_UsbMode.usb_comport_driver = USB_COMPORT_WIN;
	

	if(bvaild_cmd == KAL_TRUE)
	{
		//USB_Ms_State_Checkmedia_Exist(LUN);
		g_UsbMS.nState = USBMS_IDLE;
		
		/* Switch RX endpoint state to use FIFO */
		//USB_Config_RxEP_Type(g_UsbMS.rxpipe->byEP, USB_ENDPT_BULK, KAL_FALSE);
		//USB_Ms_Generate_Csw(&g_UsbMS_CSW, CBW);
		//USB_Ms_BuildTx(&g_UsbMS_CSW, 13);
		USB_Ms_Build_Tx_CWS(&g_UsbMS_CSW, CBW);
	 	
	 	do{
			count++;
			kal_sleep_task(1);
			bEPEmpty = USB_Is_EP_Tx_Empty(g_UsbMS.txpipe->byEP, USB_ENDPT_BULK);
		}while((bEPEmpty == KAL_FALSE)&&(count != USBMS_VENDOR_CMD_TIMEOUT)&&(USB_Get_Device_Type() != USB_UNKOWN));
    	    	
		if(breboot)
		{
			/* Disable D+ pull high, but plug out is false */
			USB_Release_Type(KAL_TRUE, KAL_FALSE);
			kal_sleep_task(100);
			INT_SetCmdToSys(SYS_CMD_SET_BL_DL);
			DRV_RESET();
		}
		else
		{
#if defined(__USB_MODEM_CARD_SUPPORT__)
			USB_Mode_Switch(USB_COMPOSITE_DEVICES);
#elif defined(__USB_DATA_CONNECTION__)
			/* Disable D+ pull high, but plug out is false */
			USB_Release_Type(KAL_TRUE, KAL_FALSE);
			kal_sleep_task(100);

			//USB_Config_Type(USB_COMPOSITE_MULTI_COM, KAL_TRUE, NULL);
			gUsbDevice.usb_send_config_result = KAL_FALSE;
			usbcfg = (drvuem_usbcfg_req_struct*) construct_local_para(sizeof(drvuem_usbcfg_req_struct), TD_CTRL);
			usbcfg->mode = USB_DATA_CONNECTION_COM;

			USB_Send_Msg_Ext_Queue(MOD_USB, MSG_ID_DRVUEM_USBCFG_REQ, (local_para_struct*)usbcfg);
//			DRV_BuildPrimitive(usb_ilm, MOD_USB, MOD_USB, MSG_ID_DRVUEM_USBCFG_REQ,(local_para_struct*)usbcfg);
//			msg_send_ext_queue(usb_ilm);
#endif
		}
	}
	else
#endif //__USB_MODEM_CARD_SUPPORT__
	{
		USB_Ms_Cmd_Unknown(CBW);
	}
}
#endif //__USB_MODEM_CARD_SUPPORT__




/* handle CBW unknown command */
static void USB_Ms_Cmd_Unknown(UsbMs_CBW *CBW)
{
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
#else
	//g_UsbMS.nState = USBMS_IDLE;
	//g_UsbMS.sensePtr = (kal_uint8 *)senseInvalidFieldInCDB;
	//g_UsbMS.CSWStatusError = 0x01;
	//USB_Config_RxEP_Type(g_UsbMS.rxpipe->byEP, USB_ENDPT_BULK, KAL_FALSE);
	//g_UsbMS.CSWDataResidue = CBW->dCBWDataTransferLength;
	//USB_CtrlEPStall(g_UsbMS.txpipe->byEP, USB_EP_TX_DIR, KAL_TRUE);


	kal_uint8 count = 0;
	kal_bool bEPEmpty;
	
	g_UsbMS.nState = USBMS_IDLE;
	g_UsbMS.sensePtr = (kal_uint8 *)senseInvalidFieldInCDB;
	g_UsbMS.CSWStatusError = 0x01;

	/* check if need to send out a NULL packet */	
	if ((CBW->dCBWDataTransferLength!=0)&&(CBW->bmCBWFlags & USBMS_DIR_IN))
	{
		USB_Mask_USB_CORE(USB_MASK_OWNER_MS); //IRQMask(IRQ_USB_CODE);
		USB_EPFIFOWrite (g_UsbMS.txpipe->byEP, 0, NULL);
		USB_EP_Tx_Ready(g_UsbMS.txpipe->byEP, USB_ENDPT_BULK);
		if(USB_Get_UnMask_Irq() == KAL_TRUE)
		{
		 		USB_UnMask_USB_CORE(USB_MASK_OWNER_MS); //IRQUnmask(IRQ_USB_CODE);
		}
		do{
			count++;
			kal_sleep_task(1);
			bEPEmpty = USB_Is_EP_Tx_Empty(g_UsbMS.txpipe->byEP, USB_ENDPT_BULK);
		}while((bEPEmpty == KAL_FALSE)&&(count != USBMS_UNKNOW_CMD_TIMEOUT)&&(USB_Get_Device_Type() != USB_UNKOWN));
	}
	
	if((count != USBMS_UNKNOW_CMD_TIMEOUT)&&(USB_Get_Device_Type() != USB_UNKOWN));
	{
		USB_Ms_Build_Tx_CWS(&g_UsbMS_CSW, CBW);
	}
	
#endif
}


/* handle CBW USBMS_READ command */
static void USB_Ms_Cmd_Read(kal_uint8 LUN, UsbMs_CBW *CBW)
{
	kal_uint8 *CBWCB = CBW->CBWCB;
	g_UsbMS.ms_read_write_reset = KAL_FALSE;

	USB_Ms_State_Checkmedia_Exist(LUN);

	USB_Ms_MemInverse(&CBWCB[2], &g_UsbMS.rw_cmd.LBA, 4);
//	USB_Ms_MemInverse(&CBWCB[7], &g_UsbMS.rw_cmd.BlkLen, 2);


	if(g_UsbMS.nState == USBMS_RX)
	{
		g_UsbMS.CSWDataResidue = CBW->dCBWDataTransferLength;
		USB_CtrlEPStall(g_UsbMS.rxpipe->byEP, USB_EP_RX_DIR, KAL_TRUE);
		return;
	}

	if(CBW->dCBWDataTransferLength == 0)
	{
		/* Host expects no data transfers */
		g_UsbMS.CSWStatusError = 0x02;
		g_UsbMS.nState = USBMS_IDLE;
//		g_UsbMS.nState = USBMS_GETNEXTCMD;
		g_UsbMS.CSWDataResidue = 0;
		/* Switch RX endpoint state to use FIFO */
		//USB_Config_RxEP_Type(g_UsbMS.rxpipe->byEP, USB_ENDPT_BULK, KAL_FALSE);
		//USB_Ms_Generate_Csw(&g_UsbMS_CSW, CBW);
		//USB_Ms_BuildTx(&g_UsbMS_CSW, 13);
		USB_Ms_Build_Tx_CWS(&g_UsbMS_CSW, CBW);
	}
	else if (g_UsbMS.rw_cmd.BlkLen == 0)
	{
		/* Device expects no data transfers */
		g_UsbMS.CSWDataResidue = CBW->dCBWDataTransferLength;
		USB_CtrlEPStall(g_UsbMS.txpipe->byEP, USB_EP_TX_DIR, KAL_TRUE);
	}
	else
	{
		if(g_UsbMS.CSWStatusError == 0x00)
		{
			if((g_UsbMS.rw_cmd.BlkLen*512) != CBW->dCBWDataTransferLength)
			{
				USB_CtrlEPStall(g_UsbMS.txpipe->byEP, USB_EP_TX_DIR, KAL_TRUE);
				g_UsbMS.CSWDataResidue = CBW->dCBWDataTransferLength;
			}
			else
			{
				g_UsbMS.rw_cmd.rwindex = 0;
				g_UsbMS.rw_cmd.msdc_rwindex = 0;
				g_UsbMS.rw_cmd.rw_buffer_index = 0;
				g_UsbMS.rw_cmd.rw_error_status = KAL_FALSE;

				USB_Ms_Handle_Read(LUN, CBW);
			}
		}
		else
		{
			USB_Ms_Read_Fail_Handler(LUN, CBW);
		}
	}
}


static void USB_Ms_Handle_Read(kal_uint8 LUN, UsbMs_CBW *CBW)
{
	static kal_bool 	read_status;
	static kal_uint32	readlen = 0;


#ifdef __USB_OTG_RX_TEST__
	g_UsbMS.device_ms_rx_test_flag = KAL_TRUE;
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#ifndef  __MS_WITH_SINGLE_BUFFER__
	if(g_UsbMS.rw_cmd.rwindex == 0)		/* the first time to read */
	{
#endif
		if ((g_UsbMS.rw_cmd.BlkLen - g_UsbMS.rw_cmd.rwindex) <= USBMS_TX_MAX_SECTOR)
			readlen = g_UsbMS.rw_cmd.BlkLen - g_UsbMS.rw_cmd.rwindex;
		else
			readlen = USBMS_TX_MAX_SECTOR;

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
#else
		read_status = USB_Ms_Read_Write(USB_MS_READ, LUN, g_UsbMS.disk_buffer->ms_buffer[g_UsbMS.rw_cmd.rw_buffer_index],
					(g_UsbMS.rw_cmd.LBA + g_UsbMS.rw_cmd.msdc_rwindex), readlen);
#endif   /* __P_PROPRIETARY_COPYRIGHT__ */

#ifndef  __MS_WITH_SINGLE_BUFFER__
	}/*(g_UsbMS.rw_cmd.rwindex == 0)*/
#endif

	if (read_status == KAL_TRUE)
	{
		g_UsbMS.rw_cmd.msdc_rwindex += readlen;
		USB_Ms_BuildTx((void *)g_UsbMS.disk_buffer->ms_buffer[g_UsbMS.rw_cmd.rw_buffer_index], (512*readlen));
		g_UsbMS.rw_cmd.rwindex += readlen;

		if(g_UsbMS.rw_cmd.rwindex == g_UsbMS.rw_cmd.BlkLen)
		{
			g_UsbMS.nState = USBMS_ACK;
			return;
		}
	}
	else
	{
		USB_Ms_Read_Fail_Handler(LUN, CBW);
		return;
	}

#ifndef  __MS_WITH_SINGLE_BUFFER__
	if((g_UsbMS.rw_cmd.BlkLen - g_UsbMS.rw_cmd.rwindex) <= USBMS_TX_MAX_SECTOR)
		readlen = g_UsbMS.rw_cmd.BlkLen - g_UsbMS.rw_cmd.rwindex;
	else
		readlen = USBMS_TX_MAX_SECTOR;

	g_UsbMS.rw_cmd.rw_buffer_index ^= 1;

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
#else
	read_status = USB_Ms_Read_Write(USB_MS_READ, LUN, g_UsbMS.disk_buffer->ms_buffer[g_UsbMS.rw_cmd.rw_buffer_index],
				(g_UsbMS.rw_cmd.LBA + g_UsbMS.rw_cmd.msdc_rwindex), readlen);
#endif  /* __P_PROPRIETARY_COPYRIGHT__ */
#endif  /* __MS_WITH_SINGLE_BUFFER__ */
}


/* Handle read error condition */
static void USB_Ms_Read_Fail_Handler(kal_uint8 LUN, UsbMs_CBW *CBW)
{
	kal_bool bEPEmpty;
	kal_uint16 count = 0;


	USB_Dbg_Trace(USB_MS_READ_FAIL_HANDLER, 0, 0);

	/* Make sure previous packets are already sent out
	   maybe last DMA data has triggered DMA done but data are still in FIFO*/
	bEPEmpty = USB_Is_EP_Tx_Empty(g_UsbMS.txpipe->byEP, USB_ENDPT_BULK);
	/* If cable plug out at this time, add timeout to avoid looping here */
	while((bEPEmpty == KAL_FALSE)&&(count != USBMS_READ_FAIL_TIMEOUT)&&(USB_Get_Device_State() == DEVSTATE_CONFIG))
	{
		count++;
		kal_sleep_task(1);
		bEPEmpty = USB_Is_EP_Tx_Empty(g_UsbMS.txpipe->byEP, USB_ENDPT_BULK);
	}

	/* send out a NULL packet */
	USB_Mask_USB_CORE(USB_MASK_OWNER_MS); //IRQMask(IRQ_USB_CODE);


	if ((g_UsbMS.ms_read_write_reset == KAL_FALSE) && (count != USBMS_READ_FAIL_TIMEOUT))
	{
		USB_EPFIFOWrite (g_UsbMS.txpipe->byEP, 0, NULL);
		USB_EP_Tx_Ready(g_UsbMS.txpipe->byEP, USB_ENDPT_BULK);
	}
	
	//USB_UnMask_Irq(USB_MASK_OWNER_MS);
	if(USB_Get_UnMask_Irq() == KAL_TRUE)
	{
   		USB_UnMask_USB_CORE(USB_MASK_OWNER_MS); //IRQUnmask(IRQ_USB_CODE);
	}

	/* make sure previous NULL pkt has been sent out
	   avoid next DMA data in FIFO sent out instead of previos NULL pkt.*/
	/* To avoid "IN token received after next DMA(below part) has moved data into FIFO"
	If this happens, MTK device will send CSW of 13 bytes out to PC,
	and it will cause PC to wait for next data(about 10 seconds) and reset USB after that.
	Disk will show on PC until this condition disappear*/
	if(count != USBMS_READ_FAIL_TIMEOUT)
	{
		bEPEmpty = USB_Is_EP_Tx_Empty(g_UsbMS.txpipe->byEP, USB_ENDPT_BULK);
		/* If cable plug out at this time, add timeout to avoid looping here */
		count = 0;
		while((bEPEmpty == KAL_FALSE)&&(count != USBMS_READ_FAIL_TIMEOUT)&&(USB_Get_Device_State() == DEVSTATE_CONFIG))
		{
			count++;
			kal_sleep_task(1);
			bEPEmpty = USB_Is_EP_Tx_Empty(g_UsbMS.txpipe->byEP, USB_ENDPT_BULK);
		}
	}

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
#else
	USB_Ms_State_Checkmedia_Exist(LUN);
#endif

	g_UsbMS.nState = USBMS_IDLE;

	if((USB_Get_Device_State() == DEVSTATE_CONFIG)&&(USB_RxEP_Usage(g_UsbMS.rxpipe->byEP) == USB_EP_STATE_DMA))
	{
		/* If the FIFO state is not in DMA, this means that PC already reset USB, and re-enumerate again */
		g_UsbMS.CSWDataResidue = (g_UsbMS.rw_cmd.BlkLen-g_UsbMS.rw_cmd.msdc_rwindex)*512;
		g_UsbMS.CSWStatusError = 0x01;

		/* Switch RX endpoint state to use FIFO */
//		USB_Config_RxEP_Type(g_UsbMS.rxpipe->byEP, USB_ENDPT_BULK, KAL_FALSE);
//		USB_Ms_Generate_Csw(&g_UsbMS_CSW, CBW);
		USB_Mask_USB_CORE(USB_MASK_OWNER_MS); //IRQMask(IRQ_USB_CODE);


		if ((g_UsbMS.ms_read_write_reset == KAL_FALSE) && (count != USBMS_READ_FAIL_TIMEOUT))
		{
			USB_Config_RxEP_Type(g_UsbMS.rxpipe->byEP, USB_ENDPT_BULK, KAL_FALSE);
			USB_Ms_Generate_Csw(&g_UsbMS_CSW, CBW);
			USB_Ms_BuildTx(&g_UsbMS_CSW, 13);
		}
		
		//USB_UnMask_Irq(USB_MASK_OWNER_MS);
		if(USB_Get_UnMask_Irq() == KAL_TRUE)
		{
			USB_UnMask_USB_CORE(USB_MASK_OWNER_MS); //IRQUnmask(IRQ_USB_CODE);

		}
	}
}


/* handle CBW USBMS_WRITE command */
static void USB_Ms_Cmd_Write(kal_uint8 LUN, UsbMs_CBW *CBW)
{
	kal_uint8   *CBWCB = CBW->CBWCB;
//	USB_STORAGE_DEV_STATUS   msdc_status;

	g_UsbMS.ms_read_write_reset = KAL_FALSE;
//	msdc_status = USB_Ms_Checkmedia_Exist(LUN);

	USB_Ms_MemInverse(&CBWCB[2], &g_UsbMS.rw_cmd.LBA, 4);
//	USB_Ms_MemInverse(&CBWCB[7], &g_UsbMS.rw_cmd.BlkLen, 2);

	if(g_UsbMS.nState == USBMS_TX)
	{
		USB_CtrlEPStall(g_UsbMS.txpipe->byEP, USB_EP_TX_DIR, KAL_TRUE);
		g_UsbMS.CSWDataResidue = CBW->dCBWDataTransferLength;
		return;
	}

	if(CBW->dCBWDataTransferLength == 0)
	{
		g_UsbMS.CSWStatusError = 0x02;
		g_UsbMS.nState = USBMS_IDLE;
//		g_UsbMS.nState = USBMS_GETNEXTCMD;
		g_UsbMS.CSWDataResidue = 0;
		/* Switch RX endpoint state to use FIFO */
		if (g_UsbMS.ms_read_write_reset == KAL_FALSE)
		{
			//USB_Config_RxEP_Type(g_UsbMS.rxpipe->byEP, USB_ENDPT_BULK, KAL_FALSE);
			//USB_Ms_Generate_Csw(&g_UsbMS_CSW, CBW);
			//USB_Ms_BuildTx(&g_UsbMS_CSW, 13);
			USB_Ms_Build_Tx_CWS(&g_UsbMS_CSW, CBW);
		}
	}
	else if(g_UsbMS.rw_cmd.BlkLen == 0)
	{
		/* Device expects no data transfers */
		USB_CtrlEPStall(g_UsbMS.rxpipe->byEP, USB_EP_RX_DIR, KAL_TRUE);
		g_UsbMS.CSWDataResidue = CBW->dCBWDataTransferLength;
	}
	else
	{
		if((g_UsbMS.rw_cmd.BlkLen*512) != CBW->dCBWDataTransferLength)
		{
			USB_CtrlEPStall(g_UsbMS.rxpipe->byEP, USB_EP_RX_DIR, KAL_TRUE);
			g_UsbMS.CSWDataResidue = CBW->dCBWDataTransferLength;
		}
		else
		{
			g_UsbMS.rw_cmd.rwindex = 0;
			g_UsbMS.rw_cmd.msdc_rwindex = 0;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
			USB_Ms_Handle_Write(LUN, CBW, 0);
		}
	}
}


static void USB_Ms_Handle_Write(kal_uint8 LUN, UsbMs_CBW *CBW, kal_uint8 sector_num)
{
	kal_uint32 writelen;
	kal_bool write_status;
	kal_bool write_data = KAL_FALSE;
	kal_uint32 msdc_rwindex;
	kal_uint32 rw_buffer_index;
	kal_uint32 LBA;
	USB_STORAGE_DEV_STATUS   msdc_status;

#ifdef __USB_OTG_TX_TEST__
	g_UsbMS.device_ms_tx_test_flag = KAL_TRUE;
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	if (sector_num !=0)
	{
			msdc_status = USB_Ms_Checkmedia_Exist(LUN);

			if (msdc_status == USB_STORAGE_DEV_STATUS_OK)
				g_UsbMS.rw_cmd.rw_error_status = KAL_FALSE;
			else
				g_UsbMS.rw_cmd.rw_error_status = KAL_TRUE;	
	}

	/* Determine if it has data to write, if yes and msdc status ok, then write it */
	if((g_UsbMS.rw_cmd.rwindex != 0) && (g_UsbMS.rw_cmd.rw_error_status == KAL_FALSE))
	{
		write_data = KAL_TRUE;
	}

	/* Write the last one data */
	if (g_UsbMS.rw_cmd.rwindex == g_UsbMS.rw_cmd.BlkLen)
	{
//#ifndef  __MS_WITH_SINGLE_BUFFER__
//		g_UsbMS.rw_cmd.rw_buffer_index ^= 1;
//#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if 0
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
#ifdef __P_PROPRIETARY_COPYRIGHT__
/* under construction !*/
#endif
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
#else		
		/* RX done */
		USB_Mask_USB_CORE(USB_MASK_OWNER_MS); //IRQMask(IRQ_USB_CODE);
		if(write_data == KAL_TRUE)
		{
			/* keep write information for following MSDC write */
			msdc_rwindex = g_UsbMS.rw_cmd.msdc_rwindex;			
	        LBA = g_UsbMS.rw_cmd.LBA;	
			#ifndef  __MS_WITH_SINGLE_BUFFER__
				rw_buffer_index = g_UsbMS.rw_cmd.rw_buffer_index ^ 1;
			#else
				rw_buffer_index = g_UsbMS.rw_cmd.rw_buffer_index;			
			#endif
			g_UsbMS.rw_cmd.msdc_rwindex += sector_num;
		}

		if (g_UsbMS.nState != USBMS_IDLE)
        {
            g_UsbMS.nState = USBMS_IDLE;
//          g_UsbMS.nState = USBMS_GETNEXTCMD;
            /*Send CSW*/
            g_UsbMS.CSWDataResidue = (g_UsbMS.rw_cmd.BlkLen-g_UsbMS.rw_cmd.msdc_rwindex)*512;
            USB_Ms_Checkmedia_Exist(g_UsbMS.current_LUN);

            if((g_UsbMS.CSWDataResidue != 0) || (g_UsbMS.prev_write_fail[LUN] == KAL_TRUE))
            {
                g_UsbMS.CSWStatusError = 0x01;
				g_UsbMS.sensePtr = (kal_uint8 *)senseWriteFail;
				g_UsbMS.CSWDataResidue = 512;
				g_UsbMS.prev_write_fail[LUN] = KAL_FALSE;
            }

            g_UsbMS.rw_cmd.rw_error_status = KAL_FALSE;
            /* Switch RX endpoint state to use FIFO */
            if (g_UsbMS.ms_read_write_reset == KAL_FALSE)
            {
            	//USB_Config_RxEP_Type(g_UsbMS.rxpipe->byEP, USB_ENDPT_BULK, KAL_FALSE);
            	//USB_Ms_Generate_Csw(&g_UsbMS_CSW, CBW);
            	//USB_Ms_BuildTx(&g_UsbMS_CSW, 13);
//						msdc_rwindex = g_UsbMS.rw_cmd.msdc_rwindex;			
            	USB_Ms_Build_Tx_CWS(&g_UsbMS_CSW, CBW);
            }
    	}
    	
        //USB_UnMask_Irq(USB_MASK_OWNER_MS);
        if(USB_Get_UnMask_Irq() == KAL_TRUE)
        {
			USB_UnMask_USB_CORE(USB_MASK_OWNER_MS); //IRQUnmask(IRQ_USB_CODE);
		}

		if(write_data == KAL_TRUE)
		{
			write_status = USB_Ms_Read_Write(USB_MS_WRITE, LUN, g_UsbMS.disk_buffer->ms_buffer[rw_buffer_index],
							(LBA + msdc_rwindex), sector_num); 
#if 1
			if(write_status == KAL_TRUE)
			{
#ifdef __P_PROPRIETARY_COPYRIGHT__
/* under construction !*/
#endif
//				g_UsbMS.rw_cmd.msdc_rwindex += sector_num;
        }
			else
			{
//				g_UsbMS.rw_cmd.rw_error_status = KAL_TRUE;
				g_UsbMS.prev_write_fail[LUN] = KAL_TRUE;
				drv_trace0(TRACE_FUNC, (kal_uint32)USB_MS_WRITE_SECTOR_FAIL);
			}
#endif			
		}


#endif
	}
	else		/* more data to receive, or ready to receive the first one data packet*/
	{
#ifndef  __MS_WITH_SINGLE_BUFFER__
		/* determine the length to be received*/
		if((g_UsbMS.rw_cmd.BlkLen - g_UsbMS.rw_cmd.rwindex) <= USBMS_RX_MAX_SECTOR)
		{
			writelen = g_UsbMS.rw_cmd.BlkLen - g_UsbMS.rw_cmd.rwindex;
		}
		else
		{
			writelen = USBMS_RX_MAX_SECTOR;
		}

		USB_Ms_BuildRx((void *)g_UsbMS.disk_buffer->ms_buffer[g_UsbMS.rw_cmd.rw_buffer_index], (512 * writelen));
		g_UsbMS.rw_cmd.rwindex += writelen;

		/* write flash while receive another packet*/
		g_UsbMS.rw_cmd.rw_buffer_index ^= 1;  /*  toggle buffer index */
#endif  /* __MS_WITH_SINGLE_BUFFER__ */

		if(write_data == KAL_TRUE)
		{
			USB_Dbg_Trace(USB_MS_CMD_USBMS_MSDC, 0, 0);
			write_status = USB_Ms_Read_Write(USB_MS_WRITE, g_UsbMS.current_LUN, g_UsbMS.disk_buffer->ms_buffer[g_UsbMS.rw_cmd.rw_buffer_index],
								(g_UsbMS.rw_cmd.LBA + g_UsbMS.rw_cmd.msdc_rwindex), sector_num);
			USB_Dbg_Trace(USB_MS_CMD_USBMS_MSDC, 0, 0);

			if(write_status == KAL_TRUE)
			{
#ifdef __P_PROPRIETARY_COPYRIGHT__
/* under construction !*/
#endif
				g_UsbMS.rw_cmd.msdc_rwindex+=sector_num;
			}
			else
			{
				g_UsbMS.rw_cmd.rw_error_status = KAL_TRUE;
			}
		}

#ifdef  __MS_WITH_SINGLE_BUFFER__
		/* Determine the length to be received */
		if((g_UsbMS.rw_cmd.BlkLen - g_UsbMS.rw_cmd.rwindex) <= USBMS_RX_MAX_SECTOR)
		{
			writelen = g_UsbMS.rw_cmd.BlkLen - g_UsbMS.rw_cmd.rwindex;
		}
		else
		{
			writelen = USBMS_RX_MAX_SECTOR;
		}

		USB_Ms_BuildRx((void *)g_UsbMS.disk_buffer->ms_buffer[g_UsbMS.rw_cmd.rw_buffer_index], (512*writelen));
		g_UsbMS.rw_cmd.rwindex += writelen;
#endif /* __MS_WITH_SINGLE_BUFFER__ */
	}

	USB_Dbg_Trace(USB_MS_CMD_USBMS_USB_END, 0, 0);
}


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
#endif /* __P_PROPRIETARY_COPYRIGHT__ */

#endif //__USB_MASS_STORAGE_ENABLE__
