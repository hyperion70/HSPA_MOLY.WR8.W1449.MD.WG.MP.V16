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
 *   ICusb_eem_adap.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  This file implements the host EEM class adaption layer API.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "drv_comm.h"
#include "usb_comm.h"
#include "usb.h"
#include "usbd.h"
#include "icusb_eem_drv.h"
#include "icusb_eem_adap.h"
#include "gpt_sw.h"
//#include "stack_common.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "kal_public_api.h" //#include "stack_ltlcom.h" //MSBB change #include "app_ltlcom.h"       /* Task message communiction */
#include "icusb_debug_tool.h"
#include "usb_trc.h"
#include "flc_api.h"
#include "dcl.h"



#ifdef __IC_USB_ENABLE__

#ifdef __IC_USB_EEM_SUPPORT__

void USB_EEM_rx_buff_release(kal_uint8 eem_index,void* buff_ptr[], kal_uint32* num)
{
	kal_uint8 index,index2;
		
	if (g_UsbHostEem[eem_index].rx_empty_buff_index > g_UsbHostEem[eem_index].rx_full_buff_index)
	{	
		*num = g_UsbHostEem[eem_index].rx_empty_buff_index - g_UsbHostEem[eem_index].rx_full_buff_index;
		for (index = 0; index < *num; index++)
		{
				(peer_buff_struct *)buff_ptr[index] = g_UsbHostEem[eem_index].rx_buffer[g_UsbHostEem[eem_index].rx_full_buff_index].buffer_ptr;
			 	g_UsbHostEem[eem_index].rx_full_buff_index++;		
		}
	}
	else
	{	
		*num = EEM_RX_BUFFER_NUM - g_UsbHostEem[eem_index].rx_full_buff_index;
		for (index = 0; index < *num; index++)
		{
			 (peer_buff_struct *)buff_ptr[index] = g_UsbHostEem[eem_index].rx_buffer[g_UsbHostEem[eem_index].rx_full_buff_index].buffer_ptr;
			 	g_UsbHostEem[eem_index].rx_full_buff_index++;		
		}

		for (index = *num ; index < (*num + g_UsbHostEem[eem_index].rx_empty_buff_index); index++)
		{
			 (peer_buff_struct *)buff_ptr[index] = g_UsbHostEem[eem_index].rx_buffer[index2].buffer_ptr;
			 	index2++;	
		}	
		*num = *num + g_UsbHostEem[eem_index].rx_empty_buff_index;			
	}

}

void USB_EEM_rx_buff_reserve(kal_uint8 eem_index,void* buff_ptr[], kal_uint32 num)
{
	kal_uint8 index;
	kal_uint16 dummy;
	static kal_bool first = KAL_TRUE;


	if (num >= EEM_RX_BUFFER_NUM)
		ASSERT(0);

	if (g_UsbHostEem[eem_index].rx_empty_buff_index > (EEM_RX_BUFFER_NUM-1)) // total 10 buffer ; index 0~ 9
		ASSERT(0);	

	ICUSB_Dbg_Trace(IC_USB_EEM_RECEIVE,  g_UsbHostEem[eem_index].rx_empty_buff_index,g_UsbHostEem[eem_index].rx_full_buff_index);	

	for (index = 0; index< num; index++)
	{	
    	g_UsbHostEem[eem_index].rx_buffer[g_UsbHostEem[eem_index].rx_empty_buff_index].buffer_ptr = (peer_buff_struct *)buff_ptr[index]; 	
 //   	g_UsbHostEem[eem_index].rx_buffer[g_UsbHostEem[eem_index].rx_empty_buff_index].data_ptr = (kal_uint8 *)((kal_uint8 *)g_UsbHostEem[eem_index].rx_buffer[g_UsbHostEem[eem_index].rx_empty_buff_index].buffer_ptr + sizeof(*g_UsbHostEem[eem_index].rx_buffer[g_UsbHostEem[eem_index].rx_empty_buff_index].buffer_ptr));//+ g_UsbHostEem[eem_index].rx_buffer[g_UsbHostEem[eem_index].rx_empty_buff_index].buffer_ptr ->free_header_space);
    	g_UsbHostEem[eem_index].rx_buffer[g_UsbHostEem[eem_index].rx_empty_buff_index].data_ptr = (kal_uint8 *)get_peer_buff_pdu((peer_buff_struct *)buff_ptr[index], &dummy);    	

		drv_trace1(TRACE_FUNC, (kal_uint32)USB_HOST_EEM_GET_RX_BUFFER,g_UsbHostEem[eem_index].rx_empty_buff_index);

		if (g_UsbHostEem[eem_index].rx_empty_buff_index == (EEM_RX_BUFFER_NUM-1)) // total 10 buffer ; index 0~ 9
			g_UsbHostEem[eem_index].rx_empty_buff_index = 0;
		else
		g_UsbHostEem[eem_index].rx_empty_buff_index++;	
			
		ICUSB_Dbg_Trace(IC_USB_EEM_RECEIVE,  0,0);
	}
	if (first)
	{
#if 1	// USB EEM_RX Enable 
		USBD_Recv_Req(g_UsbHostEem[eem_index].common_info,g_UsbHostEem[eem_index].ep_rx_info, USB_EEM_MIN_FRAME_SIZE, g_UsbHostEem[eem_index].rx_buffer[g_UsbHostEem[eem_index].rx_full_buff_index].data_ptr);
		first = KAL_FALSE;
#endif		
	}	
	
	if (g_UsbHostEem[eem_index].rx_empty_buff_index >= EEM_RX_BUFFER_NUM)
		ASSERT(0);
		
}

USB_EEM_RESPONSE  USB_EEM_Send_Frame(kal_uint8 eem_index,peer_buff_struct *peer_buff_ptr, flc2_pool_id_enum pool_id)
{
	kal_uint16  header,length;

	length  = peer_buff_ptr->pdu_len;

	if ((length > USB_EEM_MAX_FRAME_SIZE)||(length < USB_EEM_MIN_FRAME_SIZE))
		ASSERT(0);
	
	header = USB_EEM_Data_TYPE |USB_EEM_Data_CRC_SET |length;

	prepend_to_peer_buff(peer_buff_ptr, (void *)&header, USB_EEM_Header_Length);

	ICUSB_Dbg_Trace(IC_USB_EEM_SEND,  0, length);
	ICUSB_Dbg_Trace(IC_USB_EEM_SEND,  g_UsbHostEem[eem_index].tx_wait_buff_index, g_UsbHostEem[eem_index].tx_sent_buff_index);	

	length = peer_buff_ptr->pdu_len; // EEM Packet length

	if ((length % g_UsbHostEem[eem_index].ep_tx_info.ep_max_pkt_size) == 0)
	{
		header = 0x0000; 
		// add ZLE at the end of Frame
		append_to_peer_buff(peer_buff_ptr,(void *)&header,USB_EEM_Header_Length);
		length = length+USB_EEM_Header_Length;
	}
	
	g_UsbHostEem[eem_index].tx_buffer[g_UsbHostEem[eem_index].tx_wait_buff_index].buffer_ptr = peer_buff_ptr;	
	g_UsbHostEem[eem_index].tx_buffer[g_UsbHostEem[eem_index].tx_wait_buff_index].data_ptr = (kal_uint8 *)((kal_uint8 *)peer_buff_ptr + sizeof(*peer_buff_ptr) + peer_buff_ptr->free_header_space);
	g_UsbHostEem[eem_index].tx_buffer[g_UsbHostEem[eem_index].tx_wait_buff_index].data_length = length;
	g_UsbHostEem[eem_index].tx_buffer[g_UsbHostEem[eem_index].tx_wait_buff_index].pool_id = pool_id;

	if (g_UsbHostEem[eem_index].tx_wait_buff_index == (EEM_TX_BUFFER_NUM-1))// total 10 buffer: index 0~9
		g_UsbHostEem[eem_index].tx_wait_buff_index = 0;
	else
		g_UsbHostEem[eem_index].tx_wait_buff_index ++;
	

	if (g_UsbHostEem[eem_index].dma_tx_running == KAL_TRUE)
	{	
		return USB_EEM_TRANSFER; // last packet hasn't send out		
	}
	else //DMA not running
	{
		drv_trace1(TRACE_FUNC, (kal_uint32)USB_HOST_EEM_SEND_FRAME,g_UsbHostEem[eem_index].tx_wait_buff_index);
		USB_Host_Eem_Data_Transfer(USB_EP_TX_DIR);
		
		return USB_EEM_DONE;
	}	
	
	if (g_UsbHostEem[eem_index].tx_wait_buff_index >= EEM_TX_BUFFER_NUM)
		ASSERT(0);
}




kal_bool  USB_EEM_START(kal_uint8 eem_index, module_type ownerid)
{
	kal_uint8 index;

	ICUSB_Dbg_Trace(IC_USB_EEM_START,  0,0);	
	drv_trace0(TRACE_FUNC, (kal_uint32)USB_HOST_EEM_START);	
		
	g_UsbHostEem[eem_index].rx_full_buff_index = 0;
	g_UsbHostEem[eem_index].rx_empty_buff_index = 0;
	g_UsbHostEem[eem_index].ep_rx_status = EEM_RX_FIRST_PACKET;	
	
	for (index =0 ; index < EEM_RX_BUFFER_NUM; index++)
		g_UsbHostEem[eem_index].rx_buffer[index].data_ptr = NULL;
	
// set all EEM initial value
//enable EEM endpoint interrupt

	if ((g_UsbHostEem[eem_index].config == KAL_FALSE)||(g_UsbHostEem[eem_index].dev_attatch == KAL_FALSE))
		return KAL_FALSE;
	else
		return KAL_TRUE;
	
}

kal_bool  USB_EEM_END(kal_uint8 eem_index, module_type ownerid)
{		
	ICUSB_Dbg_Trace(IC_USB_EEM_END,  0,0);	
	drv_trace0(TRACE_FUNC, (kal_uint32)USB_HOST_EEM_END);			
//stop DMA
	USB_Host_Eem_Detach(g_UsbHostEem[eem_index].common_info.usb_ip_port);
//disable EP
	return KAL_TRUE;
}



#endif /* __IC_USB_EEM_SUPPORT__ */

#endif  /* __IC_USB_ENABLE__ */


