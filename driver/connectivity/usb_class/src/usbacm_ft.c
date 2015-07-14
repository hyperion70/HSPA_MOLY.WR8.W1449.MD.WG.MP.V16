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
 *   usbacm_ft.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements usb adaption layer for factory mode API
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
    
#include "intrCtrl.h"
#include "drv_comm.h"
//#include "stack_common.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "kal_public_api.h" //#include "stack_ltlcom.h" //MSBB change #include "app_ltlcom.h"       /* Task message communiction */
#include "syscomp_config.h"
//#include "task_config.h"
//#include "stacklib.h"
//#include "reg_base.h"
//#include "drvsignals.h"

#include "usb_comm.h"
//#include "usb_drv.h"
//#include "usb_trc.h"
#include "usb_adap.h"
#include "usb.h"
#include "usbacm_drv.h"
#include "usbacm_ft.h"

#include "multiboot_config.h"
//#include "fctycomp_config.h"

//#include "kal_non_specific_general_types.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "uart_sw.h"
#include "kal_public_api.h" //#include "stack_ltlcom.h"
//#include "kal_release.h"
#include "kal_general_types.h"
#include "kal_public_api.h"

#include "drv_msgid.h"

#ifdef __USB_COM_PORT_ENABLE__
static void USB_Acm_FT_DMA_Callback(void);
static void USB_Acm_FT_Rx_Hdlr(void);
#endif /*__USB_COM_PORT_ENABLE__*/

/*This function must always exit because TST call this function and release library to custom*/
kal_uint8 USB_Acm_FT_Port(void)
{
#if defined(__USB_COMPORT_SUPPORT_TC01_DRIVER__)&& defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
	return 1; //g_UsbACM_Comm.ft_port_num = 1; //Diagnostic port (might be called before USB Meta Init)
#else
	return 0; //g_UsbACM_Comm.ft_port_num = 0; //Modem Port 
#endif		
}

#ifdef __USB_COM_PORT_ENABLE__
/* Initialize ACM functions in factory mode */
void USB_Acm_FT_Init(void)
{	
	g_UsbACM_Comm.acm_owner = USB_ACM_OWNER_FT;

#if defined(__USB_COMPORT_SUPPORT_TC01_DRIVER__)&& defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
	g_UsbACM_Comm.ft_port_num = 1; //Diagnostic port
#else
	g_UsbACM_Comm.ft_port_num = 0; //Modem Port
#endif

//#ifdef __USB_DOWNLOAD__
	if(USBDL_Mode_Type()== USBDL_MODE_NONE)//((USBDL_Is_USB_Download_Mode() == KAL_FALSE) && (USBDL_Is_USB_Fast_Meta_Mode()== KAL_FALSE))
//#endif
	{
		/* Reset owner id, to avoid UART owner still use USB com port after USB had config as META mode */
		USB2UARTPort[g_UsbACM_Comm.ft_port_num].ownerid = MOD_DRV_HISR;   //use Diagnostic port

		USB_Acm_FT_Register_Rx_Cb(USB_Acm_FT_Rx_Hdlr);
	}
}

/* The maximum length that application can send one time */
kal_uint16 USB2UART_FT_Get_Max_Len(void)
{
	return 	USB2UART_METX_TX_MAX_LEN;
}


/* DMA callback function when data are all sent out to PC */
static void USB_Acm_FT_DMA_Callback(void)
{
//	ilm_struct *USB_ilm = NULL;


	USB_DMA_Set_Run_Status(g_UsbACM[g_UsbACM_Comm.ft_port_num].txpipe->byEP, USB_EP_TX_DIR, KAL_FALSE);
	
	
	USB_Send_Msg_Ext_Queue(MOD_FT,MSG_ID_USB_FT_TX_DONE_IND,NULL);


//	DRV_BuildPrimitive(USB_ilm,MOD_DRV_HISR,MOD_FT,MSG_ID_USB_FT_TX_DONE_IND,NULL);
//	msg_send_ext_queue(USB_ilm);
}


/* Transmit data. The data is 1 byte alignment */
void USB2UART_FT_Tx_Byte(kal_uint8* addr, kal_uint16 len)
{
#ifndef __MEUT__
	if ((INT_BootMode() != MTK_FACTORY_MODE) ||(USB_Get_Device_Type() != USB_CDC_ACM)
		||(USB_Get_Device_State() != DEVSTATE_CONFIG))
		EXT_ASSERT(0, (kal_uint32)USB_Get_Device_Type(), (kal_uint32)USB_Get_Device_State(), 0);
#endif /* __MEUT__ */
		
	USB_DMA_Setup(g_UsbACM[g_UsbACM_Comm.ft_port_num].txpipe->byEP, USB_EP_TX_DIR, USB_ENDPT_BULK, (kal_uint32)addr, len, USB_Acm_FT_DMA_Callback, KAL_TRUE, KAL_TRUE, USB_DMA1_TYPE);
}


/* Transmit data. The data is 4 bytes alignment, note that length is in 4 bytes unit */
void USB2UART_FT_Tx_Word(kal_uint32* addr, kal_uint16 len)
{
#ifndef __MEUT__
	if ((INT_BootMode() != MTK_FACTORY_MODE) ||(USB_Get_Device_Type() != USB_CDC_ACM)
		||(USB_Get_Device_State() != DEVSTATE_CONFIG)||(((kal_uint32)addr)&0x3))
		EXT_ASSERT(0, (kal_uint32)USB_Get_Device_Type(), (kal_uint32)USB_Get_Device_State(), (kal_uint32)addr);
#endif /* __MEUT__ */

	/* Transfer to byte length, in this function call, it will translate to word*/
	USB_DMA_Setup(g_UsbACM[g_UsbACM_Comm.ft_port_num].txpipe->byEP, USB_EP_TX_DIR, USB_ENDPT_BULK, (kal_uint32)addr, len<<2, USB_Acm_FT_DMA_Callback, KAL_TRUE, KAL_TRUE, USB_DMA1_TYPE);
}


/* Stop transmit action */
void USB2UART_FT_Tx_Stop(void)
{
	USB_Stop_DMA_Channel(g_UsbACM[g_UsbACM_Comm.ft_port_num].txpipe->byEP, USB_EP_TX_DIR);
	g_UsbACM[g_UsbACM_Comm.ft_port_num].setup_dma = KAL_FALSE;

	/* Clear FIFO, if not clear it, the next packet may be false */
	USB_Clear_Tx_EP_FIFO(g_UsbACM[g_UsbACM_Comm.ft_port_num].txpipe->byEP, USB_ENDPT_BULK, KAL_TRUE);
		
	/* Clear dma running state here*/
	USB_DMA_Set_Run_Status(g_UsbACM[g_UsbACM_Comm.ft_port_num].txpipe->byEP, USB_EP_TX_DIR, KAL_FALSE);
}


/* Receive endpoint handler */
static void USB_Acm_FT_Rx_Hdlr(void)
{
//	ilm_struct *USB_ilm = NULL;


	USB_Send_Msg_Ext_Queue(MOD_FT,MSG_ID_USB_FT_RX_DATA_IND,NULL);

//	DRV_BuildPrimitive(USB_ilm,MOD_DRV_HISR,MOD_FT,	MSG_ID_USB_FT_RX_DATA_IND,NULL);
//	msg_send_ext_queue(USB_ilm);
}


/* Receive data. The data is 1 byte alignment */
kal_uint16 USB2UART_FT_Rx_Byte(kal_uint8* addr, kal_uint16 len)
{
	kal_uint16 real_len;
		
	/* If the receive data length is bigger than application request,
	   factory mode application request to only receive the data length in parameter */
	if(g_UsbACM_Comm.ft_data_len > len)
		real_len = len;
	else
		real_len = g_UsbACM_Comm.ft_data_len;

	kal_mem_cpy(addr, g_UsbACM_Comm.ft_data, real_len);
	g_UsbACM_Comm.ft_data_len = 0;

	/* make sure that buffer left more than 64 bytes so that 
	next receive it can push to buffer at a time */
	USB_Set_UnMask_Irq(KAL_TRUE);
	IRQUnmask(IRQ_USB_CODE);

	/* return the really length stored in data buffer */
	return real_len;
}

#endif /*__USB_COM_PORT_ENABLE__*/

