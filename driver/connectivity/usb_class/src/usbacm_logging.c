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
 *    usbacm_logging.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements USB logging tool state machine and related functions
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __USB_COM_PORT_ENABLE__

#ifdef __USB_LOGGING__
//#include "kal_release.h"
#include "kal_public_defs.h" //MSBB change #include "stack_common.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "kal_public_api.h" //#include "stack_ltlcom.h" //MSBB change #include "app_ltlcom.h"       /* Task message communication */
#include "drv_comm.h"
//#include "intrCtrl.h"
//#include "usb_drv.h"
#include "usblog_drv.h"
#include "dsplog_drv.h"

#ifdef __MODEM_3G_LOGGING__
#include "wlog3g.h"
#endif
//#include "usblog_hw.h"
#include "usb_comm.h"
#include "usb_adap.h"
#include "usb.h"
//#include "usb_resource.h"
#include "usbacm_drv.h"
#include "usbacm_logging.h"
#include "usb_debug_tool.h"

//#include "kal_non_specific_general_types.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
//#include "kal_active_module.h"
#include "kal_public_api.h" //#include "stack_ltlcom.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#ifdef __USB_SW_LOGGING_V8__
//#include "app_mem_med.h"
#include "med_utility.h"
#endif


extern kal_uint8 g_usb_logging_port_num;


#ifdef __DSPIRDBG__


#if defined(DRV_USB_LOGGING_V6) || defined(DRV_USB_LOGGING_V5)
#ifdef __MTK_TARGET__
__attribute__ ((section ("NONCACHEDZI"), aligned(16))) 
#endif /* __MTK_TARGET__ */
kal_uint8	g_usb_logging_dsp_buff1[USB_LOGGING_DSP_BUFFER1_NUM][USB_LOGGING_DSP_BUFFER1_SIZE];

#ifdef __MTK_TARGET__
__attribute__ ((section ("NONCACHEDZI"), aligned(16))) 
#endif /* __MTK_TARGET__ */
kal_uint8	g_usb_logging_dsp_buff2[USB_LOGGING_DSP_BUFFER2_NUM][USB_LOGGING_DSP_BUFFER2_SIZE];

#endif

#ifdef DRV_USB_LOGGING_V8
	__align(32)  kal_uint8	*g_usb_logging_dsp_buff1;
	__align(32)  kal_uint8	*g_usb_logging_dsp_buff2;
#endif

#endif /* __DSPIRDBG__ */

#ifdef __MODEM_3G_LOGGING__

#if defined(DRV_USB_LOGGING_V5)||defined(DRV_USB_LOGGING_V8)
/* Both IRDBG and 3G logging use 16byte-alignment */
/* Max 1.18MB/s */
#ifdef __MTK_TARGET__
__attribute__ ((section ("NONCACHEDZI"), aligned(16))) 
#endif /* __MTK_TARGET__ */
kal_uint8	g_usb_logging_3g_buff1[USB_LOGGING_3G_BUFFER1_NUM][USB_LOGGING_3G_BUFFER1_SIZE];
/* Max 0.77MB/s */

#ifdef __MTK_TARGET__
__attribute__ ((section ("NONCACHEDZI"), aligned(16))) 
#endif /* __MTK_TARGET__ */
kal_uint8	g_usb_logging_3g_buff2[USB_LOGGING_3G_BUFFER2_NUM][USB_LOGGING_3G_BUFFER2_SIZE];
/* Max 1.93MB/s */

#ifdef __MTK_TARGET__
__attribute__ ((section ("NONCACHEDZI"), aligned(16))) 
#endif /* __MTK_TARGET__ */
kal_uint8	g_usb_logging_3g_buff3[USB_LOGGING_3G_BUFFER3_NUM][USB_LOGGING_3G_BUFFER3_SIZE];
/* For set 2 buffer D */
/* Max 12,3MB/s*/

#ifdef __MTK_TARGET__
__attribute__ ((section ("NONCACHEDZI"), aligned(16))) 
#endif /* __MTK_TARGET__ */

kal_uint8	g_usb_logging_3g_buff4[USB_LOGGING_3G_BUFFER4_NUM][USB_LOGGING_3G_BUFFER4_SIZE];
#endif



#endif /* __MODEM_3G_LOGGING__ */


/* Exception flag */
extern kal_uint8  INT_Exception_Enter;
extern module_type stack_int_get_active_module_id(void);

/* IRDMA default handle */
static kal_uint8 g_usb_irdma_handle = 255;

USBACM_LOGGING_Struct  g_USBACM_Logging_Tool;

#if (defined(MTK_SLEEP_ENABLE) && defined(__CENTRALIZED_SLEEP_MANAGER__) && defined(DRV_USB_LOGGING_SLEEP_DIS))
extern void L1SM_Multi_SW_WakeUp(void); 
extern kal_uint8 L1SM_GetHandle( void );
extern void L1SM_SleepDisable( kal_uint8 handle );
extern void L1SM_SleepEnable( kal_uint8 handle );
extern kal_uint8 L1SM_IntGetHandle( void );
extern void L1SM_IntSleepDisable( kal_uint8 handle );
extern void L1SM_IntSleepEnable( kal_uint8 handle );
kal_uint8 LockARM_handle = 0;  // should be globe variable
kal_uint8 LockMD2G_handle = 0;  // should be globe variable
#endif


static void USBACM_LOGGING_DMA_Callback(void);
#ifdef __DSPIRDBG__
static void USBACM_LOGGING_DSP1_Hdlr(void);
static void USBACM_LOGGING_Update_DSP1_Buf_Index(void);
static void USBACM_LOGGING_DSP2_Hdlr(void);
static void USBACM_LOGGING_Update_DSP2_Buf_Index(void);
static kal_uint8* USBACM_LOGGING_Get_Buff_Addr(kal_uint8 buf_index, kal_uint8 index);
#endif

#ifdef __MODEM_3G_LOGGING__
static void USBACM_LOGGING_3G_Hdlr(void);
static void USBACM_LOGGING_Update_3G_Buf_Index(void);
#endif /*__MODEM_3G_LOGGING__*/


static void USBACM_LOGGING_Clear_Buf_Index(void);
static void USBACM_LOGGING_Decide_Tx_Buffer_Num(void);

#if defined(DRV_USB_LOGGING_V6) || defined(DRV_USB_LOGGING_V5)

void USB_LOGGING_Modem_Sleep(kal_bool b_en)
{
#if (defined(MTK_SLEEP_ENABLE) && defined(__CENTRALIZED_SLEEP_MANAGER__) && defined(DRV_USB_LOGGING_SLEEP_DIS))
  if(LockMD2G_handle == 0)
  {
	LockMD2G_handle = L1SM_IntGetHandle(); // just get once
  }
  if(LockARM_handle == 0)
  {
	LockARM_handle = L1SM_GetHandle(); // just get once
  }

  if(b_en == KAL_FALSE)
  {
  	if(LockMD2G_handle && LockARM_handle)
  	{
		L1SM_IntSleepDisable( LockMD2G_handle ); // should lock MD2G first
		L1SM_SleepDisable( LockARM_handle );
		L1SM_Multi_SW_WakeUp(); 
	
		if(kal_if_hisr() == KAL_FALSE)
		{
			kal_sleep_task(4);
		}
		else
		{
			ASSERT(0);
		}			
  	}
  }
  else
  {
		L1SM_SleepEnable( LockARM_handle ); // should un-lock ARM first
		L1SM_IntSleepEnable( LockMD2G_handle );  
  }
#endif	

}
void USB_LOGGING_Clear_Buff(kal_uint8 buf_index, kal_uint8 index)
{
#ifdef __DSPIRDBG__
	if(buf_index == 0)
	{
		DSP_LOGGING_DSP_Clear_Buff(buf_index, index);
	}
	else if (buf_index == 1)
	{
		DSP_LOGGING_DSP_Clear_Buff(buf_index, index);	
	}
#ifdef __MODEM_3G_LOGGING__
	else if(buf_index <= 4)
	{
		USB_LOGGING_3G_Clear_Buffer((buf_index-USBACM_LOGGING_DSP_SOURCE_NUM), index);
	}

#endif
	else
	{
		EXT_ASSERT(0, (kal_uint32)buf_index, 0, 0);
	}
#else  /* __DSPIRDBG__ */
#ifdef __MODEM_3G_LOGGING__
	if((buf_index <= 4)&&(buf_index >= 2))
	{
		USB_LOGGING_3G_Clear_Buffer((buf_index-USBACM_LOGGING_DSP_SOURCE_NUM), index);
	}
	else
#endif
	{
		EXT_ASSERT(0, (kal_uint32)buf_index, 0, 0);
	}
#endif  /* __DSPIRDBG__ */
}


static kal_uint8 USB_LOGGING_Get_Buff_Num(kal_uint8 buf_index)
{
	switch(buf_index)
	{
#ifdef __DSPIRDBG__
	case 0:
		return USB_LOGGING_DSP_BUFFER1_NUM;
	case 1:
		return USB_LOGGING_DSP_BUFFER2_NUM;
#endif
#ifdef __MODEM_3G_LOGGING__
	case 2:
		return USB_LOGGING_3G_BUFFER1_NUM;
	case 3:
		return USB_LOGGING_3G_BUFFER2_NUM;
	case 4:
		return USB_LOGGING_3G_BUFFER3_NUM;
#endif
	default:
		EXT_ASSERT(0, (kal_uint32)buf_index, 0, 0);
		return 0;
	}
}


static kal_uint32 USB_LOGGING_Get_Buff_Size(kal_uint8 buf_index)
{
	kal_uint32 ret;

	switch(buf_index)
	{
#ifdef __DSPIRDBG__
	case 0:
		ret = USB_LOGGING_DSP_BUFFER1_SIZE;
		break;
	case 1:
		ret =  USB_LOGGING_DSP_BUFFER2_SIZE;
		break;
#endif
#ifdef __MODEM_3G_LOGGING__
	case 2:
		ret =  USB_LOGGING_3G_BUFFER1_SIZE;
		break;
	case 3:
		ret =  USB_LOGGING_3G_BUFFER2_SIZE;
		break;
	case 4:
		ret =  USB_LOGGING_3G_BUFFER3_SIZE;
		break;
#endif
	default:
		EXT_ASSERT(0, (kal_uint32)buf_index, 0, 0);
		ret =  0;
		break;
	}
	return ret;
}

static kal_uint8* USBACM_LOGGING_Get_Buff_Addr(kal_uint8 buf_index, kal_uint8 index)
{
	switch(buf_index)
	{
#ifdef __DSPIRDBG__
	case 0:
		if (index < USB_LOGGING_DSP_BUFFER1_NUM)
			return g_usb_logging_dsp_buff1[index];
		else
			EXT_ASSERT(0, index, 0, 0);

		break;
	case 1:
		if (index < USB_LOGGING_DSP_BUFFER2_NUM)
			return g_usb_logging_dsp_buff2[index];
		else
			EXT_ASSERT(0, index, 0, 0);

		break;
#endif
#ifdef __MODEM_3G_LOGGING__
	case 2:
		if (index < USB_LOGGING_3G_BUFFER1_NUM)
			return g_usb_logging_3g_buff1[index];
		else
			EXT_ASSERT(0, index, 0, 0);

		break;
	case 3:
		if (index < USB_LOGGING_3G_BUFFER2_NUM)
			return g_usb_logging_3g_buff2[index];
		else
			EXT_ASSERT(0, index, 0, 0);

		break;
	case 4:
		if (index < USB_LOGGING_3G_BUFFER3_NUM)
			return g_usb_logging_3g_buff3[index];
		else
			EXT_ASSERT(0, index, 0, 0);

		break;
#endif
	default:
		EXT_ASSERT(0, buf_index, 0, 0);
		break;
	}
	return NULL;
}

#ifdef __DSPIRDBG__

/* Be called at USB LOGGING HOST HISR */
static void USBACM_LOGGING_Update_DSP1_Buf_Index(void)
{
	kal_uint8     total_full_index;


	USB_Dbg_Trace(USBACM_LOGGING_DSP_HOST_BUF_INDEX, (kal_uint32)g_USBACM_Logging_Tool.buffer_full_index[0], 0);
	total_full_index = DSP_LOGGING_Get_DSP_Status(0);
	g_USBACM_Logging_Tool.buffer_full_index[0] |= total_full_index;
	USB_Dbg_Trace(USBACM_LOGGING_DSP_HOST_BUF_INDEX, (kal_uint32)g_USBACM_Logging_Tool.buffer_full_index[0], total_full_index);

	/* When HISR coming, we cannot accept that all buffer's status bits were not be set */
	ASSERT(total_full_index != 0);
}


/* Be called at USB LOGGING SLAVE HISR */
static void USBACM_LOGGING_Update_DSP2_Buf_Index(void)
{
#if !defined(DRV_USB_LOGGING_V5_SINGLE_DSP)
	kal_uint8     total_full_index;


	USB_Dbg_Trace(USBACM_LOGGING_DSP_SLAVE_BUF_INDEX, (kal_uint32)g_USBACM_Logging_Tool.buffer_full_index[1], 0);
	total_full_index = DSP_LOGGING_Get_DSP_Status(1);
	g_USBACM_Logging_Tool.buffer_full_index[1] |= total_full_index;
	USB_Dbg_Trace(USBACM_LOGGING_DSP_SLAVE_BUF_INDEX, (kal_uint32)g_USBACM_Logging_Tool.buffer_full_index[1], (kal_uint32)total_full_index);

	/* When HISR coming, we cannot accept that all buffer's status bits were not be set */
	ASSERT(total_full_index != 0);
#endif
}


static void USBACM_LOGGING_DSP1_Hdlr(void)
{
	kal_uint8* buff_addr;
	kal_uint32  count;


	USB_Dbg_Trace(USBACM_LOGGING_DSP_HOST_HDLR, 0, 0);
	USBACM_LOGGING_Update_DSP1_Buf_Index();

	/* In case usb is plugged out just before this critical section */
//	if((USB_Get_Device_Type() == USB_CDC_ACM_LOGGING)
//		&&(g_USBACM_Logging_Tool.dma_owner == USBACM_LOGGING_DMA_OWNER_NONE))
	if((g_UsbACM[USB_Get_Comport_Boot_Status()-1].txpipe != NULL)
		&&(g_USBACM_Logging_Tool.dma_owner == USBACM_LOGGING_DMA_OWNER_NONE))
	{
		/* Decide to trigger DMA for what source and transmit count */
		USBACM_LOGGING_Decide_Tx_Buffer_Num();
		g_USBACM_Logging_Tool.dma_owner = USBACM_LOGGING_DMA_OWNER_LOG_SRC;

		if(g_USBACM_Logging_Tool.transmitting_count == 0)
			ASSERT(0);

		USB_Dbg_Trace(USBACM_LOGGING_DSP_HOST_SET_DMA,
			(kal_uint32)g_USBACM_Logging_Tool.dma_read_index[g_USBACM_Logging_Tool.transmitting_buf_index],
			(kal_uint32)g_USBACM_Logging_Tool.transmitting_count);

		buff_addr = USBACM_LOGGING_Get_Buff_Addr(g_USBACM_Logging_Tool.transmitting_buf_index,
				g_USBACM_Logging_Tool.dma_read_index[g_USBACM_Logging_Tool.transmitting_buf_index]);
		count = g_USBACM_Logging_Tool.buff_size[g_USBACM_Logging_Tool.transmitting_buf_index]*g_USBACM_Logging_Tool.transmitting_count;

		USB_DMA_Setup(g_UsbACM[USB_Get_Comport_Boot_Status()-1].txpipe->byEP, USB_EP_TX_DIR, USB_ENDPT_BULK, (kal_uint32)buff_addr, count,
			USBACM_LOGGING_DMA_Callback, KAL_FALSE, KAL_TRUE, USB_DMA1_TYPE);
	}
}


/* USB LOGGING DSP HISR */
static void USBACM_LOGGING_DSP2_Hdlr(void)
{
	kal_uint8* buff_addr;
	kal_uint32  count;


	USB_Dbg_Trace(USBACM_LOGGING_DSP_SLAVE_HDLR, 0, 0);
	USBACM_LOGGING_Update_DSP2_Buf_Index();

	/* in case usb is plugged out just before this critical section */
//	if((USB_Get_Device_Type() == USB_CDC_ACM_LOGGING)
//		&&(g_USBACM_Logging_Tool.dma_owner == USBACM_LOGGING_DMA_OWNER_NONE))
	if((g_UsbACM[USB_Get_Comport_Boot_Status()-1].txpipe != NULL)
		&&(g_USBACM_Logging_Tool.dma_owner == USBACM_LOGGING_DMA_OWNER_NONE))
	{
		/* decide to trigger DMA for what source and transmit count */
		USBACM_LOGGING_Decide_Tx_Buffer_Num();
		g_USBACM_Logging_Tool.dma_owner = USBACM_LOGGING_DMA_OWNER_LOG_SRC;

		if(g_USBACM_Logging_Tool.transmitting_count == 0)
			ASSERT(0);

		USB_Dbg_Trace(USBACM_LOGGING_DSP_SLAVE_SET_DMA,
			(kal_uint32)g_USBACM_Logging_Tool.dma_read_index[g_USBACM_Logging_Tool.transmitting_buf_index],
			(kal_uint32)g_USBACM_Logging_Tool.transmitting_count);

		buff_addr = USBACM_LOGGING_Get_Buff_Addr(g_USBACM_Logging_Tool.transmitting_buf_index,
					g_USBACM_Logging_Tool.dma_read_index[g_USBACM_Logging_Tool.transmitting_buf_index]);
		count = g_USBACM_Logging_Tool.buff_size[g_USBACM_Logging_Tool.transmitting_buf_index]*g_USBACM_Logging_Tool.transmitting_count;

		USB_DMA_Setup(g_UsbACM[USB_Get_Comport_Boot_Status()-1].txpipe->byEP, USB_EP_TX_DIR, USB_ENDPT_BULK, (kal_uint32)buff_addr, count,
			USBACM_LOGGING_DMA_Callback, KAL_FALSE, KAL_TRUE, USB_DMA1_TYPE);
	}
}

#endif /* __DSPIRDBG__ */

#ifdef __MODEM_3G_LOGGING__

/* Be called at USB LOGGING HISR */
static void USBACM_LOGGING_Update_3G_Buf_Index(void)
{
	kal_uint32   buf_index;
	kal_uint8     total_full_index = 0;
	kal_uint8     status_index;


	for(buf_index = USBACM_LOGGING_DSP_SOURCE_NUM; buf_index < USBACM_LOGGING_TOTAL_SOURCE_NUM; buf_index++)
	{
		status_index = USB_LOGGING_Get_3G_Status((buf_index-USBACM_LOGGING_DSP_SOURCE_NUM));
		USB_Dbg_Trace(USBACM_LOGGING_3G_BUF_INDEX, (kal_uint32)g_USBACM_Logging_Tool.buffer_full_index[buf_index], (kal_uint32)status_index);
		total_full_index |= status_index;
		g_USBACM_Logging_Tool.buffer_full_index[buf_index] |= status_index;
		USB_Dbg_Trace(USBACM_LOGGING_3G_BUF_INDEX, (kal_uint32)g_USBACM_Logging_Tool.buffer_full_index[buf_index], 0);
	}

//	USB_Dbg_Trace(USBACM_LOGGING_3G_BUF_INDEX, g_USBACM_Logging_Tool.buffer_full_index[0], g_USBACM_Logging_Tool.buffer_full_index[1]);

	/* When HISR coming, we cannot accept that all buffer's status bits were not be set */
	ASSERT(total_full_index != 0);
}


void USBACM_LOGGING_3G_Reset(void)
{
	ilm_struct 	*usb_ilm = NULL;
//	module_type 	src_mod;


	USB_LOGGING_3G_Reset();

//	src_mod = stack_int_get_active_module_id();

	/* send a message to USB */

	USB_Send_Msg_Ext_Queue(usb_ilm,MOD_USB,MSG_ID_USB_LOGGING_RESET_IND, NULL);
//	DRV_BuildPrimitive(usb_ilm, src_mod, MOD_USB,MSG_ID_USB_LOGGING_RESET_IND, NULL);
//	msg_send_ext_queue(usb_ilm);
}


/* USB LOGGING 3G HISR */
static void USBACM_LOGGING_3G_Hdlr(void)
{
	kal_uint8* buff_addr;
	kal_uint32  count;


	USB_Dbg_Trace(USBACM_LOGGING_3G_HDLR, 0, 0);
	USBACM_LOGGING_Update_3G_Buf_Index();

	/* In case USB is plugged out just before this critical section */
//	if((USB_Get_Device_Type() == USB_CDC_ACM_LOGGING)
//		&&(g_USBACM_Logging_Tool.dma_owner == USBACM_LOGGING_DMA_OWNER_NONE))
	if((g_UsbACM[USB_Get_Comport_Boot_Status()-1].txpipe != NULL)
		&&(g_USBACM_Logging_Tool.dma_owner == USBACM_LOGGING_DMA_OWNER_NONE))
	{
		/* decide to trigger DMA for what source and transmit count*/
		USBACM_LOGGING_Decide_Tx_Buffer_Num();
		g_USBACM_Logging_Tool.dma_owner = USBACM_LOGGING_DMA_OWNER_LOG_SRC;

		if(g_USBACM_Logging_Tool.transmitting_count == 0)
			ASSERT(0);

		USB_Dbg_Trace(USBACM_LOGGING_3G_SET_DMA,
			(kal_uint32)g_USBACM_Logging_Tool.dma_read_index[g_USBACM_Logging_Tool.transmitting_buf_index],
			(kal_uint32)g_USBACM_Logging_Tool.transmitting_count);

		buff_addr = USBACM_LOGGING_Get_Buff_Addr(g_USBACM_Logging_Tool.transmitting_buf_index, g_USBACM_Logging_Tool.dma_read_index[g_USBACM_Logging_Tool.transmitting_buf_index]);
		count = g_USBACM_Logging_Tool.buff_size[g_USBACM_Logging_Tool.transmitting_buf_index]*g_USBACM_Logging_Tool.transmitting_count;

		USB_DMA_Setup(g_UsbACM[USB_Get_Comport_Boot_Status()-1].txpipe->byEP, USB_EP_TX_DIR, USB_ENDPT_BULK, (kal_uint32)buff_addr, count,
				USBACM_LOGGING_DMA_Callback, KAL_FALSE, KAL_TRUE, USB_DMA1_TYPE);
	}
}


void USBACM_LOGGING_Reset_Hdlr(void)
{
	kal_uint32   buf_index;
	kal_uint8     total_full_index = 0;


	kal_sleep_task(10);

	/* Check if any data in the buffers */
	for(buf_index = USBACM_LOGGING_DSP_SOURCE_NUM; buf_index < USBACM_LOGGING_TOTAL_SOURCE_NUM; buf_index++)
	{
		total_full_index |= USB_LOGGING_Get_3G_Status((buf_index-USBACM_LOGGING_DSP_SOURCE_NUM));
	}

	if(total_full_index != 0)
	{
		ASSERT(0);
//		g_USBACM_Logging_Tool.b_reset = KAL_TRUE;
	}
	else
	{
		g_USBACM_Logging_Tool.dma_owner = USBACM_LOGGING_DMA_OWNER_NONE;
		g_USBACM_Logging_Tool.transmitting_count = 0;
		g_USBACM_Logging_Tool.transmitting_buf_index = 0;
		g_USBACM_Logging_Tool.full_times = 0;
		g_USBACM_Logging_Tool.b_reset = KAL_FALSE;

		for(buf_index = USBACM_LOGGING_DSP_SOURCE_NUM; buf_index < USBACM_LOGGING_TOTAL_SOURCE_NUM; buf_index++)
		{
			g_USBACM_Logging_Tool.dma_read_index[buf_index] = 0;
			g_USBACM_Logging_Tool.empty_buf_count[buf_index] = 0;
			g_USBACM_Logging_Tool.buffer_transmitted_times[buf_index] = 0;
			g_USBACM_Logging_Tool.buffer_transmitted_num[buf_index] = 0;
		}
		USB_LOGGING_3G_Restart();
	}
}


#endif /* __MODEM_3G_LOGGING__ */

/* Only be called at DMA call back */
static void USBACM_LOGGING_Clear_Buf_Index(void)
{
	kal_uint32   read_ptr;
	kal_uint8     buf_index = g_USBACM_Logging_Tool.transmitting_buf_index;
	kal_uint8	    clear_buf_index = 0xff;

	USB_Dbg_Trace(USBACM_LOGGING_CLEAR_BUF1, buf_index, (kal_uint32)g_USBACM_Logging_Tool.buffer_full_index[buf_index]);

	for(read_ptr = g_USBACM_Logging_Tool.dma_read_index[buf_index];
			read_ptr < (g_USBACM_Logging_Tool.dma_read_index[buf_index] + g_USBACM_Logging_Tool.transmitting_count); read_ptr++)
	{
		if((g_USBACM_Logging_Tool.buffer_full_index[buf_index]&(0x01<<read_ptr)) == 0)
			EXT_ASSERT(0, (kal_uint32)g_USBACM_Logging_Tool.buffer_full_index[buf_index], 0x01<<read_ptr, 0);

		USB_LOGGING_Clear_Buff(buf_index, read_ptr);
		clear_buf_index &= ~(0x01<<read_ptr);
	}

	g_USBACM_Logging_Tool.buffer_full_index[buf_index] &= clear_buf_index;

	USB_Dbg_Trace(USBACM_LOGGING_CLEAR_BUF2, buf_index, (kal_uint32)g_USBACM_Logging_Tool.buffer_full_index[buf_index]);

	if((g_USBACM_Logging_Tool.dma_read_index[buf_index] + g_USBACM_Logging_Tool.transmitting_count) > g_USBACM_Logging_Tool.buff_num[buf_index])
		EXT_ASSERT(0, (kal_uint32)(g_USBACM_Logging_Tool.dma_read_index[buf_index] + g_USBACM_Logging_Tool.transmitting_count), (kal_uint32)g_USBACM_Logging_Tool.buff_num[buf_index], 0);

	if((g_USBACM_Logging_Tool.dma_read_index[buf_index] + g_USBACM_Logging_Tool.transmitting_count) == g_USBACM_Logging_Tool.buff_num[buf_index])
		g_USBACM_Logging_Tool.dma_read_index[buf_index] = 0;
	else
		g_USBACM_Logging_Tool.dma_read_index[buf_index] += g_USBACM_Logging_Tool.transmitting_count;
}


static void USBACM_LOGGING_Decide_Tx_Buffer_Num(void)
{
	kal_bool	    buf_not_all_empty = KAL_FALSE;
	kal_uint32   buf_index;
	kal_uint32   read_ptr;
	kal_uint32   empty_buffer;
	kal_uint32   temp_buf_index = 0;
	kal_uint32   transmitting_count = 0;

	// Decide the empty buffer number
	for(buf_index = 0; buf_index < USBACM_LOGGING_TOTAL_SOURCE_NUM; buf_index++)
	{
		USB_Dbg_Trace(USBACM_LOGGING_DECIDE_BUF1, buf_index, (kal_uint32)g_USBACM_Logging_Tool.buffer_full_index[buf_index]);	
		if(g_USBACM_Logging_Tool.buffer_full_index[buf_index] != 0)
		{
			temp_buf_index = buf_index;
			buf_not_all_empty = KAL_TRUE;
			break;
		}
	}

	if(buf_not_all_empty == KAL_FALSE)
	{
		USB_Dbg_Trace(USBACM_LOGGING_BUFF_EMPTY, 0, 0);
//		g_USBACM_Logging_Tool.transmitting_buf_index = temp_buf_index;
		g_USBACM_Logging_Tool.transmitting_count = 0;
		return;
	}

	/* buf is not all empty */
	for(buf_index = temp_buf_index; buf_index < USBACM_LOGGING_TOTAL_SOURCE_NUM; buf_index++)
	{
		if(g_USBACM_Logging_Tool.buffer_full_index[buf_index] != 0)
		{
			empty_buffer = 0;

			for(read_ptr = 0; read_ptr < g_USBACM_Logging_Tool.buff_num[buf_index]; read_ptr++)
			{
				if((g_USBACM_Logging_Tool.buffer_full_index[buf_index]&(0x01<<read_ptr)) == 0)
				{
					empty_buffer++;
				}
			}

			g_USBACM_Logging_Tool.empty_buf_count[buf_index] = empty_buffer;

			if(g_USBACM_Logging_Tool.empty_buf_count[temp_buf_index] > g_USBACM_Logging_Tool.empty_buf_count[buf_index])
			{
				temp_buf_index = buf_index;
			}
		}
	}

	USB_Dbg_Trace(USBACM_LOGGING_DECIDE_BUF2, temp_buf_index, 0);

	if(g_USBACM_Logging_Tool.empty_buf_count[temp_buf_index] == 0)  /* drop packet */
	{
		g_USBACM_Logging_Tool.full_times++;
		USB_Dbg_Trace(USBACM_LOGGING_DROP_PKT, g_USBACM_Logging_Tool.full_times, 0);

//		if(g_USBACM_Logging_Tool.full_times >= 2)
//			ASSERT(0);
	}

	g_USBACM_Logging_Tool.transmitting_buf_index = temp_buf_index;
	g_USBACM_Logging_Tool.buffer_transmitted_times[temp_buf_index]++;

	/* Decide how many buffer to be sent */
	for(read_ptr = g_USBACM_Logging_Tool.dma_read_index[temp_buf_index]; read_ptr < g_USBACM_Logging_Tool.buff_num[temp_buf_index]; read_ptr++)
	{
		if((g_USBACM_Logging_Tool.buffer_full_index[temp_buf_index]&(0x01<<read_ptr)) != 0)
			transmitting_count++;
		else
			break;
	}

	g_USBACM_Logging_Tool.buffer_transmitted_num[temp_buf_index] += transmitting_count;
	g_USBACM_Logging_Tool.transmitting_count = transmitting_count;
	USB_Dbg_Trace(USBACM_LOGGING_DECIDE_BUF3, transmitting_count, g_USBACM_Logging_Tool.dma_read_index[temp_buf_index]);

	if(transmitting_count == 0)
		ASSERT(0);
}


/* DMA callback function for TX sent out data */
static void USBACM_LOGGING_DMA_Callback(void)
{
	kal_uint8* buff_addr;
	kal_uint32  count;


	if((g_USBACM_Logging_Tool.dma_owner != USBACM_LOGGING_DMA_OWNER_DMA)
		&&(g_USBACM_Logging_Tool.dma_owner != USBACM_LOGGING_DMA_OWNER_LOG_SRC))
	{
		EXT_ASSERT(0, (kal_uint32)g_USBACM_Logging_Tool.dma_owner, 0, 0);
	}

#ifndef  __DSP_LOGGING_TEST__
	USBACM_LOGGING_Clear_Buf_Index();
#endif

	/* In case usb cable is plugged out just before this critical section */
//	if(USB_Get_Device_Type() == USB_CDC_ACM_LOGGING)
	if(g_UsbACM[USB_Get_Comport_Boot_Status()-1].txpipe != NULL)
	{
		/* decide if trigger DMA */
		USBACM_LOGGING_Decide_Tx_Buffer_Num();

		if(g_USBACM_Logging_Tool.transmitting_count != 0)
		{
			g_USBACM_Logging_Tool.dma_owner = USBACM_LOGGING_DMA_OWNER_DMA;

			USB_Dbg_Trace(USBACM_LOGGING_DMA_SET_DMA,
				(kal_uint32)g_USBACM_Logging_Tool.dma_read_index[g_USBACM_Logging_Tool.transmitting_buf_index],
				(kal_uint32)g_USBACM_Logging_Tool.transmitting_count);

			buff_addr = USBACM_LOGGING_Get_Buff_Addr(g_USBACM_Logging_Tool.transmitting_buf_index, g_USBACM_Logging_Tool.dma_read_index[g_USBACM_Logging_Tool.transmitting_buf_index]);
			count = g_USBACM_Logging_Tool.buff_size[g_USBACM_Logging_Tool.transmitting_buf_index]*g_USBACM_Logging_Tool.transmitting_count;

			USB_DMA_Setup(g_UsbACM[USB_Get_Comport_Boot_Status()-1].txpipe->byEP, USB_EP_TX_DIR, USB_ENDPT_BULK, (kal_uint32)buff_addr, count,
				USBACM_LOGGING_DMA_Callback, KAL_FALSE, KAL_TRUE, USB_DMA1_TYPE);
		}
		else
		{
			g_USBACM_Logging_Tool.dma_owner = USBACM_LOGGING_DMA_OWNER_NONE;
		}
	}
}


/* Called when USB configure type */
void USBACM_LOGGING_Init(void)
{
	kal_uint32   buf_index;
	
#ifdef __DSPIRDBG__
	kal_uint32	sub_buf_index;
	kal_uint8		*buf_addr;
	volatile kal_uint32	*tmp_buf_addr_ptr;
#endif

	USB_Dbg_Trace(USBACM_LOGGING_INT, 0, 0);
	g_USBACM_Logging_Tool.dma_owner = USBACM_LOGGING_DMA_OWNER_NONE;
	g_USBACM_Logging_Tool.transmitting_count = 0;
	g_USBACM_Logging_Tool.transmitting_buf_index = 0;
	g_USBACM_Logging_Tool.full_times = 0;
	g_USBACM_Logging_Tool.b_reset = KAL_FALSE;
	g_USBACM_Logging_Tool.b_enable = KAL_FALSE;

	for(buf_index = 0; buf_index < USBACM_LOGGING_TOTAL_SOURCE_NUM; buf_index++)
	{
		g_USBACM_Logging_Tool.empty_buf_count[buf_index] = 0;
		g_USBACM_Logging_Tool.buffer_transmitted_times[buf_index] = 0;
		g_USBACM_Logging_Tool.buffer_transmitted_num[buf_index] = 0;
	}

#ifdef __MODEM_3G_LOGGING__
	for(buf_index = USBACM_LOGGING_DSP_SOURCE_NUM; buf_index < USBACM_LOGGING_TOTAL_SOURCE_NUM; buf_index++)
	{
		g_USBACM_Logging_Tool.dma_read_index[buf_index] = 0;
		g_USBACM_Logging_Tool.buffer_full_index[buf_index] = 0;
	}
#endif
#ifdef __DSPIRDBG__
		USB_LOGGING_Modem_Sleep(KAL_FALSE);
#endif

	if(g_USBACM_Logging_Tool.b_not_first_time == KAL_FALSE)
	{
		/* Only init one time */
		g_USBACM_Logging_Tool.b_not_first_time = KAL_TRUE;

	#ifdef __DSPIRDBG__
		for(buf_index = 0; buf_index < USBACM_LOGGING_DSP_SOURCE_NUM; buf_index++)
		{
			g_USBACM_Logging_Tool.dma_read_index[buf_index] = 0;
			g_USBACM_Logging_Tool.buffer_full_index[buf_index] = 0;
			g_USBACM_Logging_Tool.buff_num[buf_index] = USB_LOGGING_Get_Buff_Num(buf_index);
			g_USBACM_Logging_Tool.buff_size[buf_index] = USB_LOGGING_Get_Buff_Size(buf_index);
		}
	#endif
	#ifdef __MODEM_3G_LOGGING__
		for(buf_index = USBACM_LOGGING_DSP_SOURCE_NUM; buf_index < USBACM_LOGGING_TOTAL_SOURCE_NUM; buf_index++)
		{
			g_USBACM_Logging_Tool.buff_num[buf_index] = USB_LOGGING_Get_Buff_Num(buf_index);
			g_USBACM_Logging_Tool.buff_size[buf_index] = USB_LOGGING_Get_Buff_Size(buf_index);
		}
	#endif


	#ifdef __DSPIRDBG__
		DSP_LOGGING_DSP_Init(0, (kal_uint8 *)g_usb_logging_dsp_buff1);
#if !defined(DRV_USB_LOGGING_V5_SINGLE_DSP)	
		DSP_LOGGING_DSP_Init(1, (kal_uint8 *)g_usb_logging_dsp_buff2);
#endif
//		USB_LOGGING_Modem_Sleep(KAL_TRUE);
		USB_LOGGING_Register_DSP_Hldr(USBACM_LOGGING_DSP1_Hdlr, USBACM_LOGGING_DSP2_Hdlr);

		// Fill in the DSP header
		buf_addr = USBACM_LOGGING_Get_Buff_Addr(0, 0);

		for(sub_buf_index = 0; sub_buf_index < (USB_LOGGING_DSP_BUFFER1_NUM*IRDBG_L2_HOST_BUFF_NUM); sub_buf_index++)
		{
			tmp_buf_addr_ptr = (kal_uint32 *)buf_addr;
			*tmp_buf_addr_ptr = IRDBG_HOST_L2_BUFF_HEADER;
			buf_addr += IRDBG_L2_BUFF_SIZE;
		}

		buf_addr = USBACM_LOGGING_Get_Buff_Addr(1, 0);

		for(sub_buf_index = 0; sub_buf_index < (USB_LOGGING_DSP_BUFFER2_NUM*IRDBG_L2_SLAVE_BUFF_NUM); sub_buf_index++)
		{
			tmp_buf_addr_ptr = (kal_uint32 *)buf_addr;
			*tmp_buf_addr_ptr = IRDBG_SLAVE_L2_BUFF_HEADER;
			buf_addr += IRDBG_L2_BUFF_SIZE;
		}

		if(g_usb_irdma_handle == 255)
			g_usb_irdma_handle = L1D_IRDMA_Power_GetHandle();
		if(g_usb_irdma_handle == 255)
			ASSERT(0);
	#endif

	#ifdef __MODEM_3G_LOGGING__
		USB_LOGGING_3G_Init((kal_uint8 *)g_usb_logging_3g_buff1, (kal_uint8 *)g_usb_logging_3g_buff2,
				(kal_uint8 *)g_usb_logging_3g_buff3, (kal_uint8 *)g_usb_logging_3g_buff4);
		USB_LOGGING_Register_3G_Hldr(USBACM_LOGGING_3G_Hdlr);
	#endif
	}
}


/* Be called when PC configure USB */
void USBACM_LOGGING_Start_Hdlr(void)
{
	kal_uint8* buff_addr;
	kal_uint32  count;


	USB_Dbg_Trace(USBACM_LOGGING_START, (kal_uint32)g_USBACM_Logging_Tool.b_enable, 0);

	if(g_USBACM_Logging_Tool.b_enable == KAL_TRUE)
		ASSERT(0);

	g_USBACM_Logging_Tool.b_enable = KAL_TRUE;

	/* When we re-start logging, we must sent out all data in IRDBG buffers */
	USBACM_LOGGING_Decide_Tx_Buffer_Num();

	if(g_USBACM_Logging_Tool.transmitting_count != 0)
	{
		/* Send the previous time data before plugging out cable */
		g_USBACM_Logging_Tool.dma_owner = USBACM_LOGGING_DMA_OWNER_DMA;

		buff_addr = USBACM_LOGGING_Get_Buff_Addr(g_USBACM_Logging_Tool.transmitting_buf_index, g_USBACM_Logging_Tool.dma_read_index[g_USBACM_Logging_Tool.transmitting_buf_index]);
		count = g_USBACM_Logging_Tool.buff_size[g_USBACM_Logging_Tool.transmitting_buf_index]*g_USBACM_Logging_Tool.transmitting_count;

		USB_DMA_Setup(g_UsbACM[USB_Get_Comport_Boot_Status()-1].txpipe->byEP, USB_EP_TX_DIR, USB_ENDPT_BULK, (kal_uint32)buff_addr, count,
				USBACM_LOGGING_DMA_Callback, KAL_FALSE, KAL_TRUE, USB_DMA1_TYPE);

		while((g_USBACM_Logging_Tool.dma_owner != USBACM_LOGGING_DMA_OWNER_NONE)&&(USB_Get_Device_State() == DEVSTATE_CONFIG))
		{
			/* Cannot be 3G source */
			if(g_USBACM_Logging_Tool.transmitting_buf_index >= USBACM_LOGGING_DSP_SOURCE_NUM)
				ASSERT(0);

			kal_sleep_task(1);
		}
	}

#ifdef __DSPIRDBG__		
//	USB_LOGGING_Modem_Sleep(KAL_FALSE);
	DSP_LOGGING_DSP_Start();
	L1D_IRDMA_Power_On(g_usb_irdma_handle);
#endif

#ifdef __MODEM_3G_LOGGING__
	USB_LOGGING_3G_Start();
#endif
}


void USBACM_LOGGING_Connect_Hdlr(void)
{
	kal_uint32   buf_index;


	USB_Dbg_Trace(USBACM_LOGGING_CONN, (kal_uint32)g_USBACM_Logging_Tool.b_enable, 0);

	if(g_USBACM_Logging_Tool.b_enable == KAL_TRUE)
		return;

	g_USBACM_Logging_Tool.b_enable = KAL_TRUE;

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
#endif

	g_USBACM_Logging_Tool.transmitting_count = 0;
	g_USBACM_Logging_Tool.transmitting_buf_index = 0;
	g_USBACM_Logging_Tool.full_times = 0;
	g_USBACM_Logging_Tool.b_reset = KAL_FALSE;

	for(buf_index = 0; buf_index < USBACM_LOGGING_TOTAL_SOURCE_NUM; buf_index++)
	{
		g_USBACM_Logging_Tool.empty_buf_count[buf_index] = 0;
		g_USBACM_Logging_Tool.buffer_transmitted_times[buf_index] = 0;
		g_USBACM_Logging_Tool.buffer_transmitted_num[buf_index] = 0;
	}

#ifdef __MODEM_3G_LOGGING__
	for(buf_index = USBACM_LOGGING_DSP_SOURCE_NUM; buf_index < USBACM_LOGGING_TOTAL_SOURCE_NUM; buf_index++)
	{
		g_USBACM_Logging_Tool.dma_read_index[buf_index] = 0;
		g_USBACM_Logging_Tool.buffer_full_index[buf_index] = 0;
	}
#endif

#ifdef __DSPIRDBG__
//	USB_LOGGING_Modem_Sleep(KAL_FALSE);
	DSP_LOGGING_DSP_Start();
	L1D_IRDMA_Power_On(g_usb_irdma_handle);
#endif
#ifdef __MODEM_3G_LOGGING__
	USB_LOGGING_3G_Start();
#endif
}


/* Be called when plugging out cable */
void USBACM_LOGGING_Stop(void)
{
	USB_Dbg_Trace(USBACM_LOGGING_STOP, (kal_uint32)g_USBACM_Logging_Tool.b_enable, 0);

	if(g_USBACM_Logging_Tool.b_enable == KAL_TRUE)
	{
		g_USBACM_Logging_Tool.b_enable = KAL_FALSE;
#ifdef __DSPIRDBG__
	L1D_IRDMA_Power_Off(g_usb_irdma_handle);
	DSP_LOGGING_DSP_Stop();

	USB_LOGGING_Modem_Sleep(KAL_TRUE);
#endif
#ifdef __MODEM_3G_LOGGING__
		USB_LOGGING_3G_Stop();
#endif
	}
}


void	USBACM_LOGGING_Discon_Hdlr(void)
{
	USB_Dbg_Trace(USBACM_LOGGING_DISCONN, (kal_uint32)g_USBACM_Logging_Tool.b_enable, 0);
	USBACM_LOGGING_Stop();

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
}


// for test
static kal_bool b_test_pattern = KAL_TRUE;

//void USBACM_LOGGING_Flush_Data(void)
void USB_DSPIRDBG_Flush_Data(void)
{
	kal_uint32  index;
	kal_uint32  buf_index;
	kal_uint8 *buff_addr;
	static kal_uint8 dummy_data = 0xff;

//	if(INT_Exception_Enter == 0)
//		ASSERT(0);

	USB_Exception_Check();


//	if(USB_Get_Device_Type() != USB_CDC_ACM_LOGGING)
	if(g_usb_logging_port_num == 0)
	{
		/* This function should only be called when assertion, if not CDC_ACM type, return it directly */
		return;
	}

	/* wait for the running DMA done */
	USB_Polling_Transmit_Done(g_UsbACM[USB_Get_Comport_Boot_Status()-1].txpipe->byEP, USB_ENDPT_BULK);

	for(buf_index = 0; buf_index < USBACM_LOGGING_TOTAL_SOURCE_NUM; buf_index++)
	{
		for(index = 0; index < g_USBACM_Logging_Tool.buff_num[buf_index]; index++)
		{
			if((g_USBACM_Logging_Tool.dma_read_index[buf_index] + index) == g_USBACM_Logging_Tool.buff_num[buf_index])
				buff_addr = USBACM_LOGGING_Get_Buff_Addr(buf_index, 0);
			else
				buff_addr = USBACM_LOGGING_Get_Buff_Addr(buf_index, g_USBACM_Logging_Tool.dma_read_index[buf_index] + index);

			if(b_test_pattern == KAL_TRUE)
			{
				// add only for test
				buff_addr[0] = 0x77;
				buff_addr[1] = 0x88;
				buff_addr[2] = index;
			}

			USB_Polling_Transmit_Data(g_UsbACM[USB_Get_Comport_Boot_Status()-1].txpipe->byEP, USB_EP_TX_DIR, USB_ENDPT_BULK, (kal_uint32)buff_addr, g_USBACM_Logging_Tool.buff_size[buf_index], NULL, KAL_FALSE, KAL_TRUE, USB_DMA1_TYPE);
		}

		// send one byte dummy data
		USB_Polling_Transmit_Data(g_UsbACM[USB_Get_Comport_Boot_Status()-1].txpipe->byEP, USB_EP_TX_DIR, USB_ENDPT_BULK, (kal_uint32)&dummy_data, 1, NULL, KAL_FALSE, KAL_TRUE, USB_DMA1_TYPE);
	}
}


#elif defined(DRV_USB_LOGGING_V8)
kal_uint8 USB_LOGGING_Get_Buff_Num(kal_uint8 buf_index)
{
	kal_uint8 ret;
	switch(buf_index)
	{
#ifdef __DSPIRDBG__
	case 0:
		ret = USB_LOGGING_DSP_BUFFER1_NUM;
		break;
	case 1:
		ret = USB_LOGGING_DSP_BUFFER2_NUM;
		break;
#endif
#ifdef __MODEM_3G_LOGGING__
	case 2:
		ret = USB_LOGGING_3G_BUFFER1_NUM;
		break;
	case 3:
		ret = USB_LOGGING_3G_BUFFER2_NUM;
		break;
	case 4:
		ret = USB_LOGGING_3G_BUFFER3_NUM;
		break;
#endif
	default:
		EXT_ASSERT(0, (kal_uint32)buf_index, 0, 0);
		ret = 0;
		break;
	}
	return ret;
}


kal_uint32 USB_LOGGING_Get_Buff_Size(kal_uint8 buf_index)
{
	kal_uint32 ret;

	switch(buf_index)
	{
#ifdef __DSPIRDBG__
	case 0:
		ret = USB_LOGGING_DSP_BUFFER1_SIZE;
		break;
	case 1:
		ret =  USB_LOGGING_DSP_BUFFER2_SIZE;
		break;
#endif
#ifdef __MODEM_3G_LOGGING__
	case 2:
		ret =  USB_LOGGING_3G_BUFFER1_SIZE;
		break;
	case 3:
		ret =  USB_LOGGING_3G_BUFFER2_SIZE;
		break;
	case 4:
		ret =  USB_LOGGING_3G_BUFFER3_SIZE;
		break;
#endif

	default:
		EXT_ASSERT(0, (kal_uint32)buf_index, 0, 0);
		ret =  0;
		break;
	}
	return ret;
}


void USB_LOGGING_Clear_Buff(kal_uint8 buf_index, kal_uint8 index)
{
#ifdef __DSPIRDBG__
	if(buf_index == 0)
	{
		DSP_LOGGING_DSP_Clear_Buff(buf_index,index);
	}
	else if (buf_index == 1)
	{
		DSP_LOGGING_DSP_Clear_Buff(buf_index,index);
	}
#ifdef __MODEM_3G_LOGGING__
	else if(buf_index <= 4)
	{
		USB_LOGGING_3G_Clear_Buffer((buf_index-USBACM_LOGGING_DSP_SOURCE_NUM), index);
	}

#endif
	else
	{
		EXT_ASSERT(0, (kal_uint32)buf_index, 0, 0);
	}
#else  /* __DSPIRDBG__ */
#ifdef __MODEM_3G_LOGGING__
	if((buf_index <= 4)&&(buf_index >= 2))
	{
		USB_LOGGING_3G_Clear_Buffer((buf_index-USBACM_LOGGING_DSP_SOURCE_NUM), index);
	}
	else
#endif
	{
		EXT_ASSERT(0, (kal_uint32)buf_index, 0, 0);
	}
#endif  /* __DSPIRDBG__ */
}


static kal_uint8* USBACM_LOGGING_Get_Buff_Addr(kal_uint8 buf_index, kal_uint8 index)
{
	switch(buf_index)
	{
#ifdef __DSPIRDBG__
	case 0:
		if (index < USB_LOGGING_DSP_BUFFER1_NUM)
			//return g_usb_logging_dsp_buff1[index];
			return g_usb_logging_dsp_buff1+(index*USB_LOGGING_DSP_BUFFER1_SIZE);
		else
			EXT_ASSERT(0, index, 0, 0);

		break;
	case 1:
		if (index < USB_LOGGING_DSP_BUFFER2_NUM)
			//return g_usb_logging_dsp_buff2[index];
			return g_usb_logging_dsp_buff2+(index*USB_LOGGING_DSP_BUFFER2_SIZE);
		else
			EXT_ASSERT(0, index, 0, 0);

		break;
#endif
#ifdef __MODEM_3G_LOGGING__
	case 2:
		if (index < USB_LOGGING_3G_BUFFER1_NUM)
			return g_usb_logging_3g_buff1[index];
		else
			EXT_ASSERT(0, index, 0, 0);

		break;
	case 3:
		if (index < USB_LOGGING_3G_BUFFER2_NUM)
			return g_usb_logging_3g_buff2[index];
		else
			EXT_ASSERT(0, index, 0, 0);

		break;
	case 4:
		if (index < USB_LOGGING_3G_BUFFER3_NUM)
			return g_usb_logging_3g_buff3[index];
		else
			EXT_ASSERT(0, index, 0, 0);

		break;
/*
#ifdef __MODEM_3G_LOGGING_BUF1__
	case 5:
		if(index >= USB_LOGGING_3G_BUFFER4_NUM)
			EXT_ASSERT(0, index, 0, 0);

		return g_usb_logging_buff6[index];
		break;
#endif
*/
#endif
	default:
		EXT_ASSERT(0, buf_index, 0, 0);
		break;
	}
	return NULL;
}

#ifdef __DSPIRDBG__

static void USBACM_LOGGING_MDCI_Hdlr(kal_uint32 addr, kal_uint32 len, kal_uint32 index)
{
	kal_uint32 header;
	
	USB_Dbg_Trace(USBACM_LOGGING_DSP_HOST_HDLR, index, len);
	//drv_trace2(TRACE_GROUP_2, (kal_uint32)USBACM_MDCI_SENT, len, index);
	
    if(len == 0)
		ASSERT(0);

	/* send out header*/
	if(index == 0)
	{
		header = IRDBG_HOST_L2_BUFF_HEADER;
	}
	else if(index == 1)
	{
		header = IRDBG_SLAVE_L2_BUFF_HEADER;
	}
	else
	{
		ASSERT(0);
	}
	USB_EPFIFOWrite(g_UsbACM[USB_Get_Comport_Boot_Status()-1].txpipe->byEP, 4, &header);
	USB_EP_Tx_Ready(g_UsbACM[USB_Get_Comport_Boot_Status()-1].txpipe->byEP, USB_ENDPT_BULK);

	/* In case usb is plugged out just before this critical section */
//	if((gUsbDevice.device_type == USB_CDC_ACM_LOGGING)
//		&&(g_USBACM_Logging_Tool.dma_owner == USBACM_LOGGING_DMA_OWNER_NONE))
	if((g_UsbACM[USB_Get_Comport_Boot_Status()-1].txpipe != NULL)
		&&(g_USBACM_Logging_Tool.dma_owner == USBACM_LOGGING_DMA_OWNER_NONE))
	{
		/* Decide to trigger DMA for what source and transmit count */
		g_USBACM_Logging_Tool.dma_owner = USBACM_LOGGING_DMA_OWNER_LOG_SRC;

		USB_Dbg_Trace(USBACM_LOGGING_DSP_HOST_SET_DMA, addr, len);

		USB_DMA_Setup(g_UsbACM[USB_Get_Comport_Boot_Status()-1].txpipe->byEP, USB_EP_TX_DIR, USB_ENDPT_BULK, (kal_uint32)addr, len,
			USBACM_LOGGING_DMA_Callback, KAL_FALSE, KAL_TRUE, USB_DMA1_TYPE);
	}
}

#endif /* __DSPIRDBG__ */

#ifdef __MODEM_3G_LOGGING__

/* Be called at USB LOGGING HISR */
static void USBACM_LOGGING_Update_3G_Buf_Index(void)
{
	kal_uint32   buf_index;
	kal_uint8     total_full_index = 0;
	kal_uint8     status_index;


	for(buf_index = USBACM_LOGGING_DSP_SOURCE_NUM; buf_index < USBACM_LOGGING_TOTAL_SOURCE_NUM; buf_index++)
	{
		status_index = USB_LOGGING_Get_3G_Status((buf_index-USBACM_LOGGING_DSP_SOURCE_NUM));
		USB_Dbg_Trace(USBACM_LOGGING_3G_BUF_INDEX, (kal_uint32)g_USBACM_Logging_Tool.buffer_full_index[buf_index], (kal_uint32)status_index);
		total_full_index |= status_index;
		g_USBACM_Logging_Tool.buffer_full_index[buf_index] |= status_index;
		USB_Dbg_Trace(USBACM_LOGGING_3G_BUF_INDEX, (kal_uint32)g_USBACM_Logging_Tool.buffer_full_index[buf_index], 0);
	}

//	USB_Dbg_Trace(USBACM_LOGGING_3G_BUF_INDEX, g_USBACM_Logging_Tool.buffer_full_index[0], g_USBACM_Logging_Tool.buffer_full_index[1]);

	/* When HISR coming, we cannot accept that all buffer's status bits were not be set */
	ASSERT(total_full_index != 0);
}


void USBACM_LOGGING_3G_Reset(void)
{
	ilm_struct 	*usb_ilm = NULL;
//	module_type 	src_mod;


	USB_LOGGING_3G_Reset();

//	src_mod = stack_int_get_active_module_id();

	/* send a message to USB */

	USB_Send_Msg_Ext_Queue(usb_ilm,MOD_USB,MSG_ID_USB_LOGGING_RESET_IND, NULL);
//	DRV_BuildPrimitive(usb_ilm, src_mod, MOD_USB,MSG_ID_USB_LOGGING_RESET_IND, NULL);
//	msg_send_ext_queue(usb_ilm);
}


/* USB LOGGING 3G HISR */
static void USBACM_LOGGING_3G_Hdlr(void)
{
	kal_uint8* buff_addr;
	kal_uint32  count;


	USB_Dbg_Trace(USBACM_LOGGING_3G_HDLR, 0, 0);
	USBACM_LOGGING_Update_3G_Buf_Index();

	/* In case USB is plugged out just before this critical section */
//	if((gUsbDevice.device_type == USB_CDC_ACM_LOGGING)
//		&&(g_USBACM_Logging_Tool.dma_owner == USBACM_LOGGING_DMA_OWNER_NONE))
	if((g_UsbACM[USB_Get_Comport_Boot_Status()-1].txpipe != NULL)
		&&(g_USBACM_Logging_Tool.dma_owner == USBACM_LOGGING_DMA_OWNER_NONE))
	{
		/* decide to trigger DMA for what source and transmit count*/
		USBACM_LOGGING_Decide_Tx_Buffer_Num();
		g_USBACM_Logging_Tool.dma_owner = USBACM_LOGGING_DMA_OWNER_LOG_SRC;

		if(g_USBACM_Logging_Tool.transmitting_count == 0)
			ASSERT(0);

		USB_Dbg_Trace(USBACM_LOGGING_3G_SET_DMA, 			(kal_uint32)g_USBACM_Logging_Tool.dma_read_index[g_USBACM_Logging_Tool.transmitting_buf_index],
			(kal_uint32)g_USBACM_Logging_Tool.transmitting_count);

		buff_addr = USBACM_LOGGING_Get_Buff_Addr(g_USBACM_Logging_Tool.transmitting_buf_index, g_USBACM_Logging_Tool.dma_read_index[g_USBACM_Logging_Tool.transmitting_buf_index]);
		count = g_USBACM_Logging_Tool.buff_size[g_USBACM_Logging_Tool.transmitting_buf_index]*g_USBACM_Logging_Tool.transmitting_count;

		USB_DMA_Setup(g_UsbACM[USB_Get_Comport_Boot_Status()-1].txpipe->byEP, USB_EP_TX_DIR, USB_ENDPT_BULK, (kal_uint32)buff_addr, count,
				USBACM_LOGGING_DMA_Callback, KAL_FALSE, KAL_TRUE, USB_DMA1_TYPE);
	}
}


void USBACM_LOGGING_Reset_Hdlr(void)
{
	kal_uint32   buf_index;
	kal_uint8     total_full_index = 0;


	kal_sleep_task(10);

	/* Check if any data in the buffers */
	for(buf_index = USBACM_LOGGING_DSP_SOURCE_NUM; buf_index < USBACM_LOGGING_TOTAL_SOURCE_NUM; buf_index++)
	{
		total_full_index |= USB_LOGGING_Get_3G_Status((buf_index-USBACM_LOGGING_DSP_SOURCE_NUM));
	}

	if(total_full_index != 0)
	{
		ASSERT(0);
//		g_USBACM_Logging_Tool.b_reset = KAL_TRUE;
	}
	else
	{
		g_USBACM_Logging_Tool.dma_owner = USBACM_LOGGING_DMA_OWNER_NONE;
		g_USBACM_Logging_Tool.transmitting_count = 0;
		g_USBACM_Logging_Tool.transmitting_buf_index = 0;
		g_USBACM_Logging_Tool.full_times = 0;
		g_USBACM_Logging_Tool.b_reset = KAL_FALSE;

		for(buf_index = USBACM_LOGGING_DSP_SOURCE_NUM; buf_index < USBACM_LOGGING_TOTAL_SOURCE_NUM; buf_index++)
		{
			g_USBACM_Logging_Tool.dma_read_index[buf_index] = 0;
			g_USBACM_Logging_Tool.empty_buf_count[buf_index] = 0;
			g_USBACM_Logging_Tool.buffer_transmitted_times[buf_index] = 0;
			g_USBACM_Logging_Tool.buffer_transmitted_num[buf_index] = 0;
		}
		USB_LOGGING_3G_Restart();
	}
}


#endif /* __MODEM_3G_LOGGING__ */

/* Only be called at DMA call back */
static void USBACM_LOGGING_Clear_Buf_Index(void)
{
	kal_uint32   read_ptr;
	kal_uint8     buf_index = g_USBACM_Logging_Tool.transmitting_buf_index;
	kal_uint8	    clear_buf_index = 0xff;


	USB_Dbg_Trace(USBACM_LOGGING_CLEAR_BUF1, (kal_uint32)g_USBACM_Logging_Tool.buffer_full_index[0], (kal_uint32)g_USBACM_Logging_Tool.buffer_full_index[1]);

	for(read_ptr = g_USBACM_Logging_Tool.dma_read_index[buf_index];
			read_ptr < (g_USBACM_Logging_Tool.dma_read_index[buf_index] + g_USBACM_Logging_Tool.transmitting_count); read_ptr++)
	{
		if((g_USBACM_Logging_Tool.buffer_full_index[buf_index]&(0x01<<read_ptr)) == 0)
			EXT_ASSERT(0, (kal_uint32)g_USBACM_Logging_Tool.buffer_full_index[buf_index], 0x01<<read_ptr, 0);

		//USB_LOGGING_Clear_Buff(buf_index, read_ptr);
		clear_buf_index &= ~(0x01<<read_ptr);
	}

	//drv_trace1(TRACE_GROUP_2, (kal_uint32)USBACM_MDCI_CLEAR, buf_index);
    USB_LOGGING_Clear_Buff(buf_index, read_ptr);    // Fabian: move this line out since the previous for loop isn't run in
                                                    // both (g_USBACM_Logging_Tool.dma_read_index[buf_index] & g_USBACM_Logging_Tool.transmitting_count) are 0
    
	g_USBACM_Logging_Tool.buffer_full_index[buf_index] &= clear_buf_index;

	USB_Dbg_Trace(USBACM_LOGGING_CLEAR_BUF2, (kal_uint32)g_USBACM_Logging_Tool.buffer_full_index[0], (kal_uint32)g_USBACM_Logging_Tool.buffer_full_index[1]);

	if((g_USBACM_Logging_Tool.dma_read_index[buf_index] + g_USBACM_Logging_Tool.transmitting_count) > g_USBACM_Logging_Tool.buff_num[buf_index])
		EXT_ASSERT(0, (kal_uint32)(g_USBACM_Logging_Tool.dma_read_index[buf_index] + g_USBACM_Logging_Tool.transmitting_count), (kal_uint32)g_USBACM_Logging_Tool.buff_num[buf_index], 0);

	if((g_USBACM_Logging_Tool.dma_read_index[buf_index] + g_USBACM_Logging_Tool.transmitting_count) == g_USBACM_Logging_Tool.buff_num[buf_index])
		g_USBACM_Logging_Tool.dma_read_index[buf_index] = 0;
	else
		g_USBACM_Logging_Tool.dma_read_index[buf_index] += g_USBACM_Logging_Tool.transmitting_count;
}


static void USBACM_LOGGING_Decide_Tx_Buffer_Num(void)
{
	kal_bool	    buf_not_all_empty = KAL_FALSE;
	kal_uint32   buf_index;
	kal_uint32   read_ptr;
	kal_uint32   empty_buffer;
	kal_uint32   temp_buf_index = 0;
	kal_uint32   transmitting_count = 0;


	USB_Dbg_Trace(USBACM_LOGGING_DECIDE_BUF1, (kal_uint32)g_USBACM_Logging_Tool.buffer_full_index[0], (kal_uint32)g_USBACM_Logging_Tool.buffer_full_index[1]);

	// Decide the empty buffer number
	for(buf_index = 0; buf_index < USBACM_LOGGING_TOTAL_SOURCE_NUM; buf_index++)
	{
		if(g_USBACM_Logging_Tool.buffer_full_index[buf_index] != 0)
		{
			temp_buf_index = buf_index;
			buf_not_all_empty = KAL_TRUE;
			break;
		}
	}

	if(buf_not_all_empty == KAL_FALSE)
	{
		USB_Dbg_Trace(USBACM_LOGGING_BUFF_EMPTY, 0, 0);
//		g_USBACM_Logging_Tool.transmitting_buf_index = temp_buf_index;
		g_USBACM_Logging_Tool.transmitting_count = 0;
		return;
	}

	/* buf is not all empty */
	for(buf_index = temp_buf_index; buf_index < USBACM_LOGGING_TOTAL_SOURCE_NUM; buf_index++)
	{
		if(g_USBACM_Logging_Tool.buffer_full_index[buf_index] != 0)
		{
			empty_buffer = 0;

			for(read_ptr = 0; read_ptr < g_USBACM_Logging_Tool.buff_num[buf_index]; read_ptr++)
			{
				if((g_USBACM_Logging_Tool.buffer_full_index[buf_index]&(0x01<<read_ptr)) == 0)
				{
					empty_buffer++;
				}
			}

			g_USBACM_Logging_Tool.empty_buf_count[buf_index] = empty_buffer;

			if(g_USBACM_Logging_Tool.empty_buf_count[temp_buf_index] > g_USBACM_Logging_Tool.empty_buf_count[buf_index])
			{
				temp_buf_index = buf_index;
			}
		}
	}

	USB_Dbg_Trace(USBACM_LOGGING_DECIDE_BUF2, temp_buf_index, 0);

	if(g_USBACM_Logging_Tool.empty_buf_count[temp_buf_index] == 0)  /* drop packet */
	{
		g_USBACM_Logging_Tool.full_times++;
		USB_Dbg_Trace(USBACM_LOGGING_DROP_PKT, g_USBACM_Logging_Tool.full_times, 0);

//		if(g_USBACM_Logging_Tool.full_times >= 2)
//			ASSERT(0);
	}

	g_USBACM_Logging_Tool.transmitting_buf_index = temp_buf_index;
	g_USBACM_Logging_Tool.buffer_transmitted_times[temp_buf_index]++;

	/* Decide how many buffer to be sent */
	for(read_ptr = g_USBACM_Logging_Tool.dma_read_index[temp_buf_index]; read_ptr < g_USBACM_Logging_Tool.buff_num[temp_buf_index]; read_ptr++)
	{
		if((g_USBACM_Logging_Tool.buffer_full_index[temp_buf_index]&(0x01<<read_ptr)) != 0)
			transmitting_count++;
		else
			break;
	}

	g_USBACM_Logging_Tool.buffer_transmitted_num[temp_buf_index] += transmitting_count;
	g_USBACM_Logging_Tool.transmitting_count = transmitting_count;
	USB_Dbg_Trace(USBACM_LOGGING_DECIDE_BUF3, transmitting_count, g_USBACM_Logging_Tool.dma_read_index[temp_buf_index]);

	if(transmitting_count == 0)
		ASSERT(0);
}


/* DMA callback function for TX sent out data */
static void USBACM_LOGGING_DMA_Callback(void)
{

	USB_Dbg_Trace(USB_ACM_DMA_CALLBACK, 0, 0);
	
	if((g_USBACM_Logging_Tool.dma_owner != USBACM_LOGGING_DMA_OWNER_DMA)
		&&(g_USBACM_Logging_Tool.dma_owner != USBACM_LOGGING_DMA_OWNER_LOG_SRC))
	{
		EXT_ASSERT(0, (kal_uint32)g_USBACM_Logging_Tool.dma_owner, 0, 0);
	}

#ifndef  __DSP_LOGGING_TEST__
	USBACM_LOGGING_Clear_Buf_Index();
#endif

	/* In case usb cable is plugged out just before this critical section */
//	if(gUsbDevice.device_type == USB_CDC_ACM_LOGGING)
	if(g_UsbACM[USB_Get_Comport_Boot_Status()-1].txpipe != NULL)
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
		{
			g_USBACM_Logging_Tool.dma_owner = USBACM_LOGGING_DMA_OWNER_NONE;
		}
	}
}


/* Called when USB configure type */
void USBACM_LOGGING_Init(void)
{
	kal_uint32   buf_index;


	USB_Dbg_Trace(USBACM_LOGGING_INT, 0, 0);
	g_USBACM_Logging_Tool.dma_owner = USBACM_LOGGING_DMA_OWNER_NONE;
	g_USBACM_Logging_Tool.transmitting_count = 0;
	g_USBACM_Logging_Tool.transmitting_buf_index = 0;
	g_USBACM_Logging_Tool.full_times = 0;
	g_USBACM_Logging_Tool.b_reset = KAL_FALSE;
	g_USBACM_Logging_Tool.b_enable = KAL_FALSE;

	for(buf_index = 0; buf_index < USBACM_LOGGING_TOTAL_SOURCE_NUM; buf_index++)
	{
		g_USBACM_Logging_Tool.empty_buf_count[buf_index] = 0;
		g_USBACM_Logging_Tool.buffer_transmitted_times[buf_index] = 0;
		g_USBACM_Logging_Tool.buffer_transmitted_num[buf_index] = 0;
	}

#ifdef __MODEM_3G_LOGGING__
	for(buf_index = USBACM_LOGGING_DSP_SOURCE_NUM; buf_index < USBACM_LOGGING_TOTAL_SOURCE_NUM; buf_index++)
	{
		g_USBACM_Logging_Tool.dma_read_index[buf_index] = 0;
		g_USBACM_Logging_Tool.buffer_full_index[buf_index] = 0;
	}
#endif

	if(g_USBACM_Logging_Tool.b_not_first_time == KAL_FALSE)
	{
		/* Only init one time */
		g_USBACM_Logging_Tool.b_not_first_time = KAL_TRUE;
		

#ifdef __DSPIRDBG__

		if ((g_usb_logging_dsp_buff1 == NULL) || (g_usb_logging_dsp_buff2 == NULL))
		{
		#ifdef __MED_IN_ASM__
			//BUF_SIZE + "32 bytes" for 32bytes alignment
			g_usb_logging_dsp_buff1 = (kal_uint8*)applib_asm_alloc_anonymous_nc(USB_LOGGING_DSP_BUFFER1_NUM*USB_LOGGING_DSP_BUFFER1_SIZE+32);
			g_usb_logging_dsp_buff2 = (kal_uint8*)applib_asm_alloc_anonymous_nc(USB_LOGGING_DSP_BUFFER2_NUM*USB_LOGGING_DSP_BUFFER2_SIZE+32);
		#else
			//BUF_SIZE + "32 bytes" for 32bytes alignment
			g_usb_logging_dsp_buff1 = (kal_uint8*)med_alloc_ext_mem(USB_LOGGING_DSP_BUFFER1_NUM*USB_LOGGING_DSP_BUFFER1_SIZE+32);
			g_usb_logging_dsp_buff2 = (kal_uint8*)med_alloc_ext_mem(USB_LOGGING_DSP_BUFFER2_NUM*USB_LOGGING_DSP_BUFFER2_SIZE+32);
		#endif
		
			//for 32bytes alignment
			g_usb_logging_dsp_buff1 = (kal_uint8*)(((kal_uint32)g_usb_logging_dsp_buff1+31)&0xFFFFFFE0);
			g_usb_logging_dsp_buff2 = (kal_uint8*)(((kal_uint32)g_usb_logging_dsp_buff2+31)&0xFFFFFFE0);
		}
		
		for(buf_index = 0; buf_index < USBACM_LOGGING_DSP_SOURCE_NUM; buf_index++)
		{
			g_USBACM_Logging_Tool.dma_read_index[buf_index] = 0;
			g_USBACM_Logging_Tool.buffer_full_index[buf_index] = 0;
		}
		
		for(buf_index = 0; buf_index < USBACM_LOGGING_DSP_SOURCE_NUM; buf_index++)
		{
			g_USBACM_Logging_Tool.buff_num[buf_index] = USB_LOGGING_Get_Buff_Num(buf_index);
			g_USBACM_Logging_Tool.buff_size[buf_index] = USB_LOGGING_Get_Buff_Size(buf_index);
		}
#endif
#ifdef __MODEM_3G_LOGGING__
		for(buf_index = USBACM_LOGGING_DSP_SOURCE_NUM; buf_index < USBACM_LOGGING_TOTAL_SOURCE_NUM; buf_index++)
		{
			g_USBACM_Logging_Tool.buff_num[buf_index] = USB_LOGGING_Get_Buff_Num(buf_index);
			g_USBACM_Logging_Tool.buff_size[buf_index] = USB_LOGGING_Get_Buff_Size(buf_index);
		}
#endif


	#ifdef __DSPIRDBG__
		DSP_LOGGING_DSP_Init((kal_uint8 *)g_usb_logging_dsp_buff1, (kal_uint8 *)g_usb_logging_dsp_buff2);
		USB_LOGGING_Register_DSP_Hldr(USBACM_LOGGING_MDCI_Hdlr);

		//// Fill in the DSP header
		//buf_addr = USBACM_LOGGING_Get_Buff_Addr(0, 0);
        //
		//for(sub_buf_index = 0; sub_buf_index < (USB_LOGGING_DSP_BUFFER1_NUM); sub_buf_index++)
		//{
		//	tmp_buf_addr_ptr = (kal_uint32 *)buf_addr;
		//	*tmp_buf_addr_ptr = IRDBG_HOST_L2_BUFF_HEADER;
		//	buf_addr += IRDBG_L2_BUFF_SIZE;
		//}
        //
		//buf_addr = USBACM_LOGGING_Get_Buff_Addr(1, 0);
        //
		//for(sub_buf_index = 0; sub_buf_index < (USB_LOGGING_DSP_BUFFER2_NUM*IRDBG_L2_SLAVE_BUFF_NUM); sub_buf_index++)
		//{
		//	tmp_buf_addr_ptr = (kal_uint32 *)buf_addr;
		//	*tmp_buf_addr_ptr = IRDBG_SLAVE_L2_BUFF_HEADER;
		//	buf_addr += IRDBG_L2_BUFF_SIZE;
		//}

		if(g_usb_irdma_handle == 255)
			g_usb_irdma_handle = L1D_IRDMA_Power_GetHandle();
		if(g_usb_irdma_handle == 255)
			ASSERT(0);
	#endif

	#ifdef __MODEM_3G_LOGGING__
		USB_LOGGING_3G_Init((kal_uint8 *)g_usb_logging_3g_buff1, (kal_uint8 *)g_usb_logging_3g_buff2,
				(kal_uint8 *)g_usb_logging_3g_buff3, (kal_uint8 *)g_usb_logging_3g_buff4);
		USB_LOGGING_Register_3G_Hldr(USBACM_LOGGING_3G_Hdlr);
	#endif
	}
}


/* Be called when PC configure USB */
void USBACM_LOGGING_Start_Hdlr(void)
{
	kal_uint8* buff_addr;
	kal_uint32  count;


	USB_Dbg_Trace(USBACM_LOGGING_START, (kal_uint32)g_USBACM_Logging_Tool.b_enable, 0);

	if(g_USBACM_Logging_Tool.b_enable == KAL_TRUE)
		ASSERT(0);

	g_USBACM_Logging_Tool.b_enable = KAL_TRUE;

	/* When we re-start logging, we must sent out all data in IRDBG buffers */
	USBACM_LOGGING_Decide_Tx_Buffer_Num();

	if(g_USBACM_Logging_Tool.transmitting_count != 0)
	{
		/* Send the previous time data before plugging out cable */
		g_USBACM_Logging_Tool.dma_owner = USBACM_LOGGING_DMA_OWNER_DMA;

		buff_addr = USBACM_LOGGING_Get_Buff_Addr(g_USBACM_Logging_Tool.transmitting_buf_index, g_USBACM_Logging_Tool.dma_read_index[g_USBACM_Logging_Tool.transmitting_buf_index]);
		count = g_USBACM_Logging_Tool.buff_size[g_USBACM_Logging_Tool.transmitting_buf_index]*g_USBACM_Logging_Tool.transmitting_count;

		USB_DMA_Setup(g_UsbACM[USB_Get_Comport_Boot_Status()-1].txpipe->byEP, USB_EP_TX_DIR, USB_ENDPT_BULK, (kal_uint32)buff_addr, count,
				USBACM_LOGGING_DMA_Callback, KAL_FALSE, KAL_TRUE, USB_DMA1_TYPE);

		while((g_USBACM_Logging_Tool.dma_owner != USBACM_LOGGING_DMA_OWNER_NONE)&&(	USB_Get_Device_State() == DEVSTATE_CONFIG))
		{
			/* Cannot be 3G source */
			if(g_USBACM_Logging_Tool.transmitting_buf_index >= USBACM_LOGGING_DSP_SOURCE_NUM)
				ASSERT(0);

			kal_sleep_task(1);
		}
	}

#ifdef __DSPIRDBG__
	//drv_trace0(TRACE_GROUP_2, (kal_uint32)USBACM_MDCI_START);
	DSP_LOGGING_DSP_Start();
	L1D_IRDMA_Power_On(g_usb_irdma_handle);
#endif

#ifdef __MODEM_3G_LOGGING__
	USB_LOGGING_3G_Start();
#endif
}


void USBACM_LOGGING_Connect_Hdlr(void)
{
	kal_uint32   buf_index;

	USB_Dbg_Trace(USBACM_LOGGING_CONN, (kal_uint32)g_USBACM_Logging_Tool.b_enable, 0);

	if(g_USBACM_Logging_Tool.b_enable == KAL_TRUE)
		return;

	g_USBACM_Logging_Tool.b_enable = KAL_TRUE;

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
#else
	
#endif

	g_USBACM_Logging_Tool.transmitting_count = 0;
	g_USBACM_Logging_Tool.transmitting_buf_index = 0;
	g_USBACM_Logging_Tool.full_times = 0;
	g_USBACM_Logging_Tool.b_reset = KAL_FALSE;

	for(buf_index = 0; buf_index < USBACM_LOGGING_TOTAL_SOURCE_NUM; buf_index++)
	{
		g_USBACM_Logging_Tool.empty_buf_count[buf_index] = 0;
		g_USBACM_Logging_Tool.buffer_transmitted_times[buf_index] = 0;
		g_USBACM_Logging_Tool.buffer_transmitted_num[buf_index] = 0;
	}

#ifdef __MODEM_3G_LOGGING__
	for(buf_index = USBACM_LOGGING_DSP_SOURCE_NUM; buf_index < USBACM_LOGGING_TOTAL_SOURCE_NUM; buf_index++)
	{
		g_USBACM_Logging_Tool.dma_read_index[buf_index] = 0;
		g_USBACM_Logging_Tool.buffer_full_index[buf_index] = 0;
	}
#endif

#ifdef __DSPIRDBG__
	//drv_trace0(TRACE_GROUP_2, (kal_uint32)USBACM_MDCI_START);
	DSP_LOGGING_DSP_Start();
	L1D_IRDMA_Power_On(g_usb_irdma_handle);
#endif
#ifdef __MODEM_3G_LOGGING__
	USB_LOGGING_3G_Start();
#endif
}


/* Be called when plugging out cable */
void USBACM_LOGGING_Stop(void)
{

	USB_Dbg_Trace(USBACM_LOGGING_STOP, (kal_uint32)g_USBACM_Logging_Tool.b_enable, 0);

	if(g_USBACM_Logging_Tool.b_enable == KAL_TRUE)
	{
		g_USBACM_Logging_Tool.b_enable = KAL_FALSE;
#ifdef __DSPIRDBG__
		L1D_IRDMA_Power_Off(g_usb_irdma_handle);
		//drv_trace0(TRACE_GROUP_2, (kal_uint32)USBACM_MDCI_STOP);
		
		DSP_LOGGING_DSP_Stop();
#endif
#ifdef __MODEM_3G_LOGGING__
		USB_LOGGING_3G_Stop();
#endif
	}
}


void	USBACM_LOGGING_Discon_Hdlr(void)
{
	USB_Dbg_Trace(USBACM_LOGGING_DISCONN, (kal_uint32)g_USBACM_Logging_Tool.b_enable, 0);
	USBACM_LOGGING_Stop();

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
}


// for test
static kal_bool b_test_pattern = KAL_TRUE;

//void USBACM_LOGGING_Flush_Data(void)
void USB_DSPIRDBG_Flush_Data(void)
{
	kal_uint32  index;
	kal_uint32  buf_index;
	kal_uint8 *buff_addr;
	static kal_uint8 dummy_data = 0xff;

//	if(INT_Exception_Enter == 0)
//		ASSERT(0);

	USB_Exception_Check();


//	if(gUsbDevice.device_type != USB_CDC_ACM_LOGGING)
	if(g_usb_logging_port_num == 0)
	{
		/* This function should only be called when assertion, if not CDC_ACM type, return it directly */
		return;
	}

	/* wait for the running DMA done */
	USB_Polling_Transmit_Done(g_UsbACM[USB_Get_Comport_Boot_Status()-1].txpipe->byEP, USB_ENDPT_BULK);

	for(buf_index = 0; buf_index < USBACM_LOGGING_TOTAL_SOURCE_NUM; buf_index++)
	{
		for(index = 0; index < g_USBACM_Logging_Tool.buff_num[buf_index]; index++)
		{
			if((g_USBACM_Logging_Tool.dma_read_index[buf_index] + index) == g_USBACM_Logging_Tool.buff_num[buf_index])
				buff_addr = USBACM_LOGGING_Get_Buff_Addr(buf_index, 0);
			else
				buff_addr = USBACM_LOGGING_Get_Buff_Addr(buf_index, g_USBACM_Logging_Tool.dma_read_index[buf_index] + index);

			if(b_test_pattern == KAL_TRUE)
			{
				// add only for test
				buff_addr[0] = 0x77;
				buff_addr[1] = 0x88;
				buff_addr[2] = index;
			}

			USB_Polling_Transmit_Data(g_UsbACM[USB_Get_Comport_Boot_Status()-1].txpipe->byEP, USB_EP_TX_DIR, USB_ENDPT_BULK, (kal_uint32)buff_addr, g_USBACM_Logging_Tool.buff_size[buf_index], NULL, KAL_FALSE, KAL_TRUE, USB_DMA1_TYPE);
		}

		// send one byte dummy data
		USB_Polling_Transmit_Data(g_UsbACM[USB_Get_Comport_Boot_Status()-1].txpipe->byEP, USB_EP_TX_DIR, USB_ENDPT_BULK, (kal_uint32)&dummy_data, 1, NULL, KAL_FALSE, KAL_TRUE, USB_DMA1_TYPE);
	}
}

#endif

#endif  /*__USB_LOGGING__ */

#endif
