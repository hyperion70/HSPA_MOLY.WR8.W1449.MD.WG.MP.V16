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
 *   icusb_eem_drv.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  This file implements the host EEM class driver
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
#include "gpt_sw.h"
//#include "stack_common.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "kal_public_api.h" //#include "stack_ltlcom.h" //MSBB change #include "app_ltlcom.h"       /* Task message communiction */
//#include "otg.h"
#include "icusb_debug_tool.h"
#include "usb_trc.h"
#include "eem_struct.h" //MT_NOTE: temp --
#include "dcl.h"

#ifdef __IC_USB_ENABLE__


#ifdef __IC_USB_EEM_SUPPORT__


USB_Host_EEM_Struct g_UsbHostEem[USB_MAX_EEM_NUM];

static kal_uint8 usb_host_eem_support_num = 0;
static kal_uint8 usb_host_eem_config_num = 0xFF;
static kal_uint8 usb_host_eem_support_real_num = 0;

static kal_bool USB_Host_Eem_Match(kal_uint8 usb_ip_port,USBD_Desc_Info *p_desc_info, kal_uint32 cfg_num, kal_uint32 if_num);
static void USB_Host_Eem_Startup(kal_uint8 usb_ip_port, USBD_Desc_Info *p_desc_info, kal_uint32 cfg_num, kal_uint32 if_num);
static void USB_Host_Eem_Suspend(kal_uint8 usb_ip_port);
static void USB_Host_Eem_Resume(kal_uint8 usb_ip_port);
static kal_uint8 USB_EEM_Check_index(kal_uint8 usb_ip_port);




static kal_uint8 USB_EEM_Check_index(kal_uint8 usb_ip_port)
{
	kal_uint8 index;
	for (index = 0; index< USB_MAX_EEM_NUM; index++)
	{
		if (usb_ip_port == g_UsbHostEem[index].common_info.usb_ip_port)
			return index;
	}

	 // no matching 
	 ASSERT(0);
}



void USB_Host_Eem_State_Start(void)
{	
	kal_uint8 eem_index = 0;//USB_EEM_Check_index(usb_ip_port);
		
	USBD_Config_TxEP_Type(g_UsbHostEem[eem_index].common_info,g_UsbHostEem[eem_index].ep_tx_info,KAL_TRUE);
	USBD_Config_RxEP_Type(g_UsbHostEem[eem_index].common_info,g_UsbHostEem[eem_index].ep_rx_info,KAL_FALSE);	
}

//void USB_Host_Eem_State_End(void)
//{
//	USB_Host_Eem_Detach(g_UsbHostEem[eem_index].common_info.usb_ip_port);
//}

void USB_Host_EEM_Send_Message(msg_type msg_id)
{
	kal_uint8 eem_index = 0;//= USB_EEM_Check_index(usb_ip_port);
    ilm_struct *usb_ilm;
    eem_tx_buff_free_ind_struct* local_ptr = NULL;		

	usb_ilm = allocate_ilm(MOD_DRV_HISR);
	usb_ilm->src_mod_id = MOD_DRV_HISR;
	usb_ilm->sap_id = DRIVER_PS_SAP;
	usb_ilm->dest_mod_id = MOD_EEM;
	

	if (msg_id == MSG_ID_EEM_TX_BUFF_FREE_IND)
	{
	    usb_ilm->msg_id = MSG_ID_EEM_TX_BUFF_FREE_IND;
	    local_ptr = (eem_tx_buff_free_ind_struct*) construct_local_para(sizeof(eem_tx_buff_free_ind_struct), TD_RESET);
	    local_ptr->pool_id = g_UsbHostEem[eem_index].tx_buffer[g_UsbHostEem[eem_index].tx_sent_buff_index].pool_id;
	    usb_ilm->local_para_ptr = (local_para_struct *)local_ptr;
	    //usb_ilm->peer_buff_ptr = (peer_buff_struct*)g_UsbHostEem[eem_index].tx_buffer[g_UsbHostEem[eem_index].tx_sent_buff_index].data_ptr;//MT_NOTE: it should be "buffer_ptr", not "data_ptr"
	    //remove_hdr_of_peer_buff(usb_ilm->peer_buff_ptr, USB_EEM_Header_Length);
	    usb_ilm->peer_buff_ptr = (peer_buff_struct*)g_UsbHostEem[eem_index].tx_buffer[g_UsbHostEem[eem_index].tx_sent_buff_index].buffer_ptr;//MT_NOTE: it should be "buffer_ptr", not "data_ptr"	    	   	    
	}
	else if (msg_id == MSG_ID_EEM_DATA_IND)
	{ 
	    usb_ilm->msg_id = MSG_ID_EEM_DATA_IND;
		usb_ilm->peer_buff_ptr = (peer_buff_struct*)g_UsbHostEem[eem_index].rx_buffer[g_UsbHostEem[eem_index].rx_full_buff_index].buffer_ptr;
		usb_ilm->peer_buff_ptr->pdu_len = g_UsbHostEem[eem_index].rx_buffer[g_UsbHostEem[eem_index].rx_full_buff_index].data_length + USB_EEM_Header_Length;		
//		usb_ilm->peer_buff_ptr->free_tail_space = usb_ilm->peer_buff_ptr->free_tail_space + (USB_EEM_MAX_FRAME_SIZE + USB_EEM_Header_Length - usb_ilm->peer_buff_ptr->pdu_len);				
//		usb_ilm->peer_buff_ptr->free_header_space = 0; // total (1520) = header space(0) + data  + Tail speace (1520 - data)

		remove_head_of_peer_buff(usb_ilm->peer_buff_ptr, USB_EEM_Header_Length);
	}
	else
		ASSERT(0);

	
	msg_send_ext_queue(usb_ilm);
	
}

void USB_Host_Eem_Data_Transfer(USB_EP_DIRECTION direction)
{	
	kal_uint8 eem_index  = 0;//= USB_EEM_Check_index(usb_ip_port);
		
	if (direction == USB_EP_TX_DIR)
	{

		if (g_UsbHostEem[eem_index].tx_wait_buff_index != g_UsbHostEem[eem_index].tx_sent_buff_index)
		{
			if (g_UsbHostEem[eem_index].tx_buffer[g_UsbHostEem[eem_index].tx_sent_buff_index].data_ptr == NULL)
				ASSERT(0);

			if (g_UsbHostEem[eem_index].tx_buffer[g_UsbHostEem[eem_index].tx_sent_buff_index].data_length == 0)
				ASSERT(0);			
				
			g_UsbHostEem[eem_index].dma_tx_running = KAL_TRUE;

			drv_trace2(TRACE_FUNC, (kal_uint32)USB_HOST_EEM_SEND_FRAME_BUFFER,g_UsbHostEem[eem_index].tx_sent_buff_index,g_UsbHostEem[eem_index].tx_wait_buff_index);

			USBD_DMA_Setup(g_UsbHostEem[eem_index].common_info,g_UsbHostEem[eem_index].ep_tx_info,
				(kal_uint32)g_UsbHostEem[eem_index].tx_buffer[g_UsbHostEem[eem_index].tx_sent_buff_index].data_ptr, g_UsbHostEem[eem_index].tx_buffer[g_UsbHostEem[eem_index].tx_sent_buff_index].data_length,
				USB_Host_Eem_DMA_TX_Hdlr,KAL_FALSE, KAL_TRUE, USB_DMA1_TYPE);	
		}
	}
	else  //RX
	{
		if (g_UsbHostEem[eem_index].ep_rx_status != EEM_RX_MIDDLE_PACKET)
			ASSERT(0);
		
		if (g_UsbHostEem[eem_index].rx_last_data_length % g_UsbHostEem[eem_index].ep_rx_info.ep_max_pkt_size)
		{
			g_UsbHostEem[eem_index].rx_dma_length = g_UsbHostEem[eem_index].rx_last_data_length - (g_UsbHostEem[eem_index].rx_last_data_length % g_UsbHostEem[eem_index].ep_rx_info.ep_max_pkt_size);
		}
		else
		{
			g_UsbHostEem[eem_index].rx_dma_length = g_UsbHostEem[eem_index].rx_last_data_length - g_UsbHostEem[eem_index].ep_rx_info.ep_max_pkt_size;
		}	

		if (g_UsbHostEem[eem_index].rx_last_data_length == 0)
			ASSERT(0);
		
		g_UsbHostEem[eem_index].ep_rx_status = EEM_RX_LAST_PACKET;
		g_UsbHostEem[eem_index].dma_rx_running = KAL_TRUE;
		
		drv_trace2(TRACE_FUNC, (kal_uint32)USB_HOST_EEM_RECEIVE_DATA_BUFFER,g_UsbHostEem[eem_index].rx_full_buff_index,g_UsbHostEem[eem_index].rx_empty_buff_index);

		USBD_DMA_Setup(g_UsbHostEem[eem_index].common_info,g_UsbHostEem[eem_index].ep_rx_info,
			(kal_uint32)(g_UsbHostEem[eem_index].rx_buffer[g_UsbHostEem[eem_index].rx_full_buff_index].data_ptr), g_UsbHostEem[eem_index].rx_dma_length,USB_Host_Eem_DMA_RX_Hdlr,KAL_FALSE, KAL_TRUE, USB_DMA1_TYPE);	

		// g_UsbHostEem[eem_index].rx_buffer[g_UsbHostEem[eem_index].rx_full_buff_index].data_ptr  = remove header & copy FIFO Read Data
	}
}


void USB_Host_Eem_DMA_RX_Hdlr(void)
{
	kal_uint8 eem_index = 0;//= USB_EEM_Check_index(usb_ip_port);
		
	if (g_UsbHostEem[eem_index].dma_rx_running == KAL_FALSE)
		ASSERT(0);
	
	g_UsbHostEem[eem_index].dma_rx_running = KAL_FALSE;

	g_UsbHostEem[eem_index].rx_buffer[g_UsbHostEem[eem_index].rx_full_buff_index].data_ptr += g_UsbHostEem[eem_index].rx_dma_length;
	g_UsbHostEem[eem_index].rx_last_data_length -= g_UsbHostEem[eem_index].rx_dma_length;
	
	if(g_UsbHostEem[eem_index].rx_last_data_length == 0)
		ASSERT(0);
	
	drv_trace2(TRACE_FUNC, (kal_uint32)USB_HOST_EEM_RX_DMA_Callback,g_UsbHostEem[eem_index].rx_full_buff_index,g_UsbHostEem[eem_index].rx_dma_length);
	USBD_Config_RxEP_Type(g_UsbHostEem[eem_index].common_info,g_UsbHostEem[eem_index].ep_rx_info,KAL_FALSE);
	
	USBD_Recv_Req(g_UsbHostEem[eem_index].common_info,g_UsbHostEem[eem_index].ep_rx_info, g_UsbHostEem[eem_index].rx_last_data_length,g_UsbHostEem[eem_index].rx_buffer[g_UsbHostEem[eem_index].rx_full_buff_index].data_ptr);	

}

void USB_Host_Eem_DMA_TX_Hdlr(void)
{	
	kal_uint8 eem_index  = 0;//= USB_EEM_Check_index(usb_ip_port);
		
	if (g_UsbHostEem[eem_index].dma_tx_running == KAL_FALSE)
		ASSERT(0);
	
	g_UsbHostEem[eem_index].dma_tx_running = KAL_FALSE;

	drv_trace2(TRACE_FUNC, (kal_uint32)USB_HOST_EEM_TX_DMA_Callback,g_UsbHostEem[eem_index].tx_sent_buff_index,g_UsbHostEem[eem_index].tx_buffer[g_UsbHostEem[eem_index].tx_sent_buff_index].data_length);

    USB_Host_EEM_Send_Message(MSG_ID_EEM_TX_BUFF_FREE_IND);  
	
	g_UsbHostEem[eem_index].tx_buffer[g_UsbHostEem[eem_index].tx_sent_buff_index].data_ptr = NULL;
	g_UsbHostEem[eem_index].tx_buffer[g_UsbHostEem[eem_index].tx_sent_buff_index].data_length = 0;


	if (g_UsbHostEem[eem_index].tx_sent_buff_index == (EEM_TX_BUFFER_NUM-1))// index 0~9
		g_UsbHostEem[eem_index].tx_sent_buff_index = 0;
	else
		g_UsbHostEem[eem_index].tx_sent_buff_index ++;

// After sending command to SIM Card, there might be some data to be received.
	USBD_Recv_Req(g_UsbHostEem[eem_index].common_info,g_UsbHostEem[eem_index].ep_rx_info, USB_EEM_MIN_FRAME_SIZE, g_UsbHostEem[eem_index].rx_buffer[g_UsbHostEem[eem_index].rx_full_buff_index].data_ptr);


	if (g_UsbHostEem[eem_index].tx_wait_buff_index != g_UsbHostEem[eem_index].tx_sent_buff_index)
	{
		USB_Host_Eem_Data_Transfer(USB_EP_TX_DIR);
	}		
}

void  USB_Host_Eem_Parse_Header(kal_uint16 length)
{
	kal_uint16  pkt_header;
	kal_uint8 eem_index  = 0;//= USB_EEM_Check_index(usb_ip_port);

	g_UsbHostEem[eem_index].usb_command = KAL_FALSE;	
	
	if (length > 0)
		USBD_EPFIFORead(g_UsbHostEem[eem_index].common_info,g_UsbHostEem[eem_index].ep_rx_info, length, g_UsbHostEem[eem_index].rx_buffer[g_UsbHostEem[eem_index].rx_full_buff_index].data_ptr);

	pkt_header = *(g_UsbHostEem[eem_index].rx_buffer[g_UsbHostEem[eem_index].rx_full_buff_index].data_ptr+1);
	pkt_header = (pkt_header <<8 )| (*(g_UsbHostEem[eem_index].rx_buffer[g_UsbHostEem[eem_index].rx_full_buff_index].data_ptr));

		if (pkt_header & USB_EEM_Packet_Type_Mask) //bit15 : decide Command / Data packet
		{
		// Command packet
			switch((pkt_header & USB_EEM_Command)>>11) //bit13~11 : EEM Command
			{
				case USB_HOST_EEM_CMD_ECHO:  //function table
					
				if  ((pkt_header & USB_EEM_Command_Param) < ( g_UsbHostEem[eem_index].ep_rx_info.ep_max_pkt_size -USB_EEM_Header_Length)) //bit 10~bit 0 : Echo Length
					{
					USB_Host_Eem_ECHO_Command(g_UsbHostEem[eem_index].common_info,g_UsbHostEem[eem_index].ep_rx_info, length, g_UsbHostEem[eem_index].rx_buffer[g_UsbHostEem[eem_index].rx_full_buff_index].data_ptr);
					g_UsbHostEem[eem_index].ep_rx_status = EEM_RX_LAST_PACKET;
					}
					else // still has data to receive
					{
						drv_trace1(TRACE_FUNC, (kal_uint32)USB_HOST_EEM_RECEIVE_DATA_ERROR,1);
						ASSERT(0);  
					}
					
					break;
												
				case USB_HOST_EEM_CMD_SUSPEND_HINT: 				
				g_UsbHostEem[eem_index].usb_command = KAL_TRUE;
						USBD_Suspend_Req(g_UsbHostEem[eem_index].common_info);
						USBD_Suspend_Req(g_UsbHostEem[eem_index].common_info);
	
					break;			
					
				case USB_HOST_EEM_CMD_RESPONSE_HINT: 
				g_UsbHostEem[eem_index].usb_command = KAL_TRUE;
				g_UsbHostEem[eem_index].reponse_hint = KAL_TRUE;
				g_UsbHostEem[eem_index].response_time = (pkt_header & USB_EEM_Command_Param);
				 //set HW : IN token interval = g_UsbHostEem[eem_index].response_time
					 
					break;		
					
				case USB_HOST_EEM_CMD_RESPONSE_COMPLETE_HINT:
				if ((g_UsbHostEem[eem_index].dma_tx_running == KAL_FALSE)&&(g_UsbHostEem[eem_index].dma_rx_running == KAL_FALSE))
				{
					g_UsbHostEem[eem_index].reponse_complete_hint = KAL_TRUE;
					g_UsbHostEem[eem_index].response_complete_time = (pkt_header & USB_EEM_Command_Param);
				//Stop polling 
				//setup GPT timer	
				}
									
					break;	

				case USB_HOST_EEM_CMD_ECHO_RESPONSE: 
				case USB_HOST_EEM_CMD_TICKLE:	
				default: 
					ASSERT(0);
					break;			
			}

		if (g_UsbHostEem[eem_index].usb_command == KAL_FALSE) // not suspend hint
			{
 				g_UsbHostEem[eem_index].ep_rx_status = EEM_RX_FIRST_PACKET;		
 				USBD_Recv_Req(g_UsbHostEem[eem_index].common_info,g_UsbHostEem[eem_index].ep_rx_info, USB_EEM_MIN_FRAME_SIZE, g_UsbHostEem[eem_index].rx_buffer[g_UsbHostEem[eem_index].rx_full_buff_index].data_ptr);
			}
		}
		else 
		{
		// Data  packet
		
		drv_trace2(TRACE_FUNC, (kal_uint32)USB_HOST_EEM_RECEIVE_DATA_BUFFER,g_UsbHostEem[eem_index].rx_full_buff_index,g_UsbHostEem[eem_index].rx_empty_buff_index);

			if  (((pkt_header & USB_EEM_DATA_Length) < USB_EEM_MIN_FRAME_SIZE)||((pkt_header & USB_EEM_DATA_Length) > USB_EEM_MAX_FRAME_SIZE))
				ASSERT(0);

				// min EEM Frame = 64 B  , min EEM Packet  = 70 B
				// max EEM Frame = 1518 B ,  max EEM Packet = 1524 B
				
		g_UsbHostEem[eem_index].rx_buffer[g_UsbHostEem[eem_index].rx_full_buff_index].data_length= (pkt_header & USB_EEM_DATA_Length);  // EEM frame length
		g_UsbHostEem[eem_index].rx_buffer[g_UsbHostEem[eem_index].rx_full_buff_index].data_ptr = g_UsbHostEem[eem_index].rx_buffer[g_UsbHostEem[eem_index].rx_full_buff_index].data_ptr + length;
		g_UsbHostEem[eem_index].rx_last_data_length = g_UsbHostEem[eem_index].rx_buffer[g_UsbHostEem[eem_index].rx_full_buff_index].data_length+USB_EEM_Header_Length - length;// usb need to received last data length
			
		if (((pkt_header & USB_EEM_DATA_Length)+USB_EEM_Header_Length) < 2*g_UsbHostEem[eem_index].ep_rx_info.ep_max_pkt_size) 
			{
				// FIFO +FIFO (total EEM Frame size < 128 - 2B)
			g_UsbHostEem[eem_index].ep_rx_status = EEM_RX_LAST_PACKET;		
			USBD_Recv_Req(g_UsbHostEem[eem_index].common_info,g_UsbHostEem[eem_index].ep_rx_info, g_UsbHostEem[eem_index].rx_last_data_length, g_UsbHostEem[eem_index].rx_buffer[g_UsbHostEem[eem_index].rx_full_buff_index].data_ptr);												
			}
			else 
			{
				// FIFO+DMA+FIFO
			g_UsbHostEem[eem_index].ep_rx_status = EEM_RX_MIDDLE_PACKET;
			USBD_Config_RxEP_Type(g_UsbHostEem[eem_index].common_info,g_UsbHostEem[eem_index].ep_rx_info,KAL_TRUE);	
			drv_trace1(TRACE_FUNC, (kal_uint32)USB_HOST_EEM_RECEIVE_DATA,g_UsbHostEem[eem_index].rx_last_data_length);
				USB_Host_Eem_Data_Transfer(USB_EP_RX_DIR);	
			}			
		}
}

void USB_Host_Eem_Bulk_RX_Hdlr(void)
{
	kal_uint16  	pkt_length;
	kal_uint8 eem_index = 0;//= USB_EEM_Check_index(usb_ip_port);

	if (g_UsbHostEem[eem_index].rx_empty_buff_index == g_UsbHostEem[eem_index].rx_full_buff_index)
		ASSERT(0);  // no space to save Data

	if(g_UsbHostEem[eem_index].rx_buffer[g_UsbHostEem[eem_index].rx_full_buff_index].data_ptr == NULL)
		ASSERT(0);
	
	pkt_length = USBD_EP_Rx_Pkt_Len(g_UsbHostEem[eem_index].common_info,g_UsbHostEem[eem_index].ep_rx_info);	

	drv_trace2(TRACE_FUNC, (kal_uint32)USB_HOST_EEM_RX_FIFO_Read,g_UsbHostEem[eem_index].rx_full_buff_index,pkt_length);

	if (g_UsbHostEem[eem_index].ep_rx_status == EEM_RX_FIRST_PACKET)
	{		
		if (pkt_length < 2)	
			ASSERT(0);

	 	USB_Host_Eem_Parse_Header(pkt_length);
	}
	else if (g_UsbHostEem[eem_index].ep_rx_status == EEM_RX_LAST_PACKET)
	{
			if (pkt_length >= g_UsbHostEem[eem_index].rx_last_data_length)			
				USBD_EPFIFORead(g_UsbHostEem[eem_index].common_info,g_UsbHostEem[eem_index].ep_rx_info, g_UsbHostEem[eem_index].rx_last_data_length, g_UsbHostEem[eem_index].rx_buffer[g_UsbHostEem[eem_index].rx_full_buff_index].data_ptr);
			else // receive data less then expected
				USBD_EPFIFORead(g_UsbHostEem[eem_index].common_info,g_UsbHostEem[eem_index].ep_rx_info, pkt_length, g_UsbHostEem[eem_index].rx_buffer[g_UsbHostEem[eem_index].rx_full_buff_index].data_ptr);
		
			USB_Host_EEM_Send_Message(MSG_ID_EEM_DATA_IND);
			
				
			if (g_UsbHostEem[eem_index].rx_full_buff_index == (EEM_RX_BUFFER_NUM-1)) // total 10 buffer ; index 0~ 9
				g_UsbHostEem[eem_index].rx_full_buff_index = 0;
			else
				g_UsbHostEem[eem_index].rx_full_buff_index++;				

			g_UsbHostEem[eem_index].ep_rx_status = EEM_RX_FIRST_PACKET;
				
			if (g_UsbHostEem[eem_index].rx_full_buff_index != g_UsbHostEem[eem_index].rx_empty_buff_index)
			{
				// receive next Data header
				if(pkt_length > g_UsbHostEem[eem_index].rx_last_data_length)
				{
					g_UsbHostEem[eem_index].rx_last_data_length = 0;
					USB_Host_Eem_Parse_Header(pkt_length-g_UsbHostEem[eem_index].rx_last_data_length);
				}
				else
				{		
					if (pkt_length <g_UsbHostEem[eem_index].rx_last_data_length)
						g_UsbHostEem[eem_index].rx_buffer[g_UsbHostEem[eem_index].rx_full_buff_index].data_length -= (g_UsbHostEem[eem_index].rx_last_data_length - pkt_length);

					g_UsbHostEem[eem_index].rx_last_data_length = 0;	
					USBD_Recv_Req(g_UsbHostEem[eem_index].common_info,g_UsbHostEem[eem_index].ep_rx_info, USB_EEM_MIN_FRAME_SIZE, g_UsbHostEem[eem_index].rx_buffer[g_UsbHostEem[eem_index].rx_full_buff_index].data_ptr);
				}
			}
			else
			{
				// Stop sending IN token if there is no FLC RX Buffer
			}				
	}
	else // middle packet should use DMA
		ASSERT(0);

	if (g_UsbHostEem[eem_index].rx_full_buff_index >= EEM_RX_BUFFER_NUM)
		ASSERT(0);
}

static void USB_Host_EEM_State_Hdlr(kal_uint8 usb_ip_port, USB_HCD_STATUS result, kal_uint32 param)
{
	kal_uint8 eem_index = USB_EEM_Check_index(usb_ip_port);
		
		if(result == USB_HCD_OK)
		{
				USB_Host_Eem_Bulk_RX_Hdlr();
		}
		else if (result == USB_HCD_STALL)
		{
				ASSERT(0);
		}
		else	if (result == USB_HCD_TIMEOUT)
		{  
				// NAK time out  --> receive command again
		USBD_Recv_Req(g_UsbHostEem[eem_index].common_info,g_UsbHostEem[eem_index].ep_rx_info, USB_EEM_MIN_FRAME_SIZE, g_UsbHostEem[eem_index].rx_buffer[g_UsbHostEem[eem_index].rx_full_buff_index].data_ptr);
		}
		else
				ASSERT(0);
}

void USB_Host_Eem_ECHO_Command(USBH_Common_Struct common_str,USBH_EP_Struct usb_ep_str, kal_uint16 nBytes, void *pDst)
{
	kal_uint8 eem_index = USB_EEM_Check_index(common_str.usb_ip_port);
	kal_uint16  pkt_header;

	if (g_UsbHostEem[eem_index].ep_rx_status != EEM_RX_LAST_PACKET)
		ASSERT(0);

	pkt_header = (USB_EEM_Command_TYPE |(USB_HOST_EEM_CMD_ECHO_RESPONSE <<11)|nBytes);
	
//	USBD_EPFIFOWrite (common_str.usb_ip_port,usb_ep_str.ep_num, nBytes, pDst);		//QQ Test
}


static kal_bool USB_Host_Eem_Match(kal_uint8 usb_ip_port,USBD_Desc_Info *p_desc_info, kal_uint32 cfg_num, kal_uint32 if_num)
{
	kal_uint32 index;
	kal_bool b_match = KAL_FALSE;
	kal_uint8 temp_ep;
	kal_uint16 temp_packet;
	
	
	if(p_desc_info->dev_desc.bDeviceClass == USB_EEM_DEVICE_CODE)
	{
		/* Find data interface */
		if((p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_interface_desc->bInterfaceClass == USB_EEM_DATA_INTERFACE_CLASS_CODE)
				&& (p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_interface_desc->bInterfaceSubClass == USB_EEM_DATA_INTERFACE_SUBCLASS_CODE)
				&& (p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_interface_desc->bInterfaceProtocol == USB_EEM_DATA_INTERFACE_PROTOCOL_CODE))
		{
			b_match = KAL_TRUE;

				/* Check endpoint */
			for(index = 0; index < p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->ep_number; index++)
			{
				if(((p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_ep_info[index]->p_stdep->bEndpointAddress&USB_EP_DIR) == USB_EP_DIR_IN)
					&& (p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_ep_info[index]->p_stdep->bmAttributes == USB_EP_BULK))
				{
					temp_ep = p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_ep_info[index]->p_stdep->bEndpointAddress&(~USB_EP_DIR);
					temp_packet = p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_ep_info[index]->p_stdep->wMaxPacketSize[0]
									+ (p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_ep_info[index]->p_stdep->wMaxPacketSize[1]<<8);

						/* endpoint initialize check FIFO size and endpont number */
					if(temp_ep > MAX_RX_EP_NUM)
						b_match = KAL_FALSE;

				}
				else if(((p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_ep_info[index]->p_stdep->bEndpointAddress & USB_EP_DIR) == USB_EP_DIR_OUT)
					&& (p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_ep_info[index]->p_stdep->bmAttributes == USB_EP_BULK))
				{
					temp_ep = p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_ep_info[index]->p_stdep->bEndpointAddress&(~USB_EP_DIR);
					temp_packet = p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_ep_info[index]->p_stdep->wMaxPacketSize[0]
									+ (p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_ep_info[index]->p_stdep->wMaxPacketSize[1]<<8);

					if(temp_ep > MAX_TX_EP_NUM)
						b_match = KAL_FALSE;
				}
			}
		}
	}

	if (b_match == KAL_TRUE)
	{
		if (usb_host_eem_config_num != cfg_num)
		{
			usb_host_eem_config_num = cfg_num;
			usb_host_eem_support_num = 1;
		}
		else
		{
			usb_host_eem_support_num  ++;
		}
		
		if (usb_host_eem_support_num  > USB_MAX_EEM_NUM)
			b_match = KAL_FALSE;
	}
	
	return b_match;
}


static void USB_Host_Eem_Startup(kal_uint8 usb_ip_port, USBD_Desc_Info *p_desc_info, kal_uint32 cfg_num, kal_uint32 if_num)
{
 	kal_uint8 index;
 	kal_uint8 eem_index;
 	USBH_EP_Struct	ep_temp;
	ep_temp.ep_num = 0;

	usb_host_eem_support_real_num ++;
	
	if (usb_host_eem_support_real_num  > USB_MAX_EEM_NUM)
		ASSERT(0);
	
	eem_index = usb_host_eem_support_real_num-1; //start from 0
	
	/* Check endpoint */
	for(index = 0; index < p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->ep_number; index++)
	{
		if(((p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_ep_info[index]->p_stdep->bEndpointAddress&USB_EP_DIR) == USB_EP_DIR_IN)
			&& (p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_ep_info[index]->p_stdep->bmAttributes == USB_EP_BULK))
		{
			g_UsbHostEem[eem_index].ep_rx_info.ep_real_num  = p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_ep_info[index]->p_stdep->bEndpointAddress&(~USB_EP_DIR);
			g_UsbHostEem[eem_index].ep_rx_info.ep_max_pkt_size = p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_ep_info[index]->p_stdep->wMaxPacketSize[0]
							+ (p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_ep_info[index]->p_stdep->wMaxPacketSize[1]<<8);
		}
		else if(((p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_ep_info[index]->p_stdep->bEndpointAddress & USB_EP_DIR) == USB_EP_DIR_OUT)
			&& (p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_ep_info[index]->p_stdep->bmAttributes == USB_EP_BULK))
		{
			g_UsbHostEem[eem_index].ep_tx_info.ep_real_num = p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_ep_info[index]->p_stdep->bEndpointAddress&(~USB_EP_DIR);
			g_UsbHostEem[eem_index].ep_tx_info.ep_max_pkt_size = p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_ep_info[index]->p_stdep->wMaxPacketSize[0]
							+ (p_desc_info->cfg_info[cfg_num].p_interface_info[if_num]->p_ep_info[index]->p_stdep->wMaxPacketSize[1]<<8);
		}
	}

	if(((USBD_Is_High_Speed(g_UsbHostEem[eem_index].common_info) == KAL_TRUE)&&(g_UsbHostEem[eem_index].ep_rx_info.ep_max_pkt_size > USB_EP_BULK_MAXP_HS))
		||((USBD_Is_High_Speed(g_UsbHostEem[eem_index].common_info) == KAL_FALSE)&&(g_UsbHostEem[eem_index].ep_rx_info.ep_max_pkt_size > USB_EP_BULK_MAXP_FS)))
	{
		EXT_ASSERT(0, USBD_Is_High_Speed(g_UsbHostEem[eem_index].common_info), g_UsbHostEem[eem_index].ep_rx_info.ep_max_pkt_size, 0);
	}


	if(((USBD_Is_High_Speed(g_UsbHostEem[eem_index].common_info) == KAL_TRUE)&&(g_UsbHostEem[eem_index].ep_tx_info.ep_max_pkt_size > USB_EP_BULK_MAXP_HS))
		||((USBD_Is_High_Speed(g_UsbHostEem[eem_index].common_info) == KAL_FALSE)&&(g_UsbHostEem[eem_index].ep_tx_info.ep_max_pkt_size > USB_EP_BULK_MAXP_FS)))
	{
		EXT_ASSERT(0, USBD_Is_High_Speed(g_UsbHostEem[eem_index].common_info), g_UsbHostEem[eem_index].ep_tx_info.ep_max_pkt_size, 0);
	}


	g_UsbHostEem[eem_index].dev_error_count = 0;
	g_UsbHostEem[eem_index].config = KAL_TRUE;
	g_UsbHostEem[eem_index].dev_attatch = KAL_TRUE;

	g_UsbHostEem[eem_index].common_info.usb_ip_port = usb_ip_port;
	g_UsbHostEem[eem_index].common_info.if_num = if_num;
	
	g_UsbHostEem[eem_index].ep_rx_info.direction = USB_EP_RX_DIR;
	g_UsbHostEem[eem_index].ep_tx_info.direction = USB_EP_TX_DIR;
	g_UsbHostEem[eem_index].ep_rx_info.ep_type= USB_ENDPT_BULK;
	g_UsbHostEem[eem_index].ep_tx_info.ep_type = USB_ENDPT_BULK;
	g_UsbHostEem[eem_index].ep_rx_info.ep_num= USBD_HW_Mapping_EP(g_UsbHostEem[eem_index].common_info,USB_EP_RX_DIR);
	g_UsbHostEem[eem_index].ep_tx_info.ep_num= USBD_HW_Mapping_EP(g_UsbHostEem[eem_index].common_info,USB_EP_TX_DIR);	
	
	USBD_RxEPInit(g_UsbHostEem[eem_index].common_info,g_UsbHostEem[eem_index].ep_rx_info);
	USBD_TxEPInit(g_UsbHostEem[eem_index].common_info,g_UsbHostEem[eem_index].ep_tx_info);
	
	USBD_Set_EP_Max_Pkt(g_UsbHostEem[eem_index].common_info,g_UsbHostEem[eem_index].ep_rx_info);  
	USBD_Set_EP_Max_Pkt(g_UsbHostEem[eem_index].common_info,g_UsbHostEem[eem_index].ep_rx_info); 

	USBD_RxEPEn(g_UsbHostEem[eem_index].common_info,g_UsbHostEem[eem_index].ep_rx_info, 16, KAL_FALSE);
	USBD_TxEPEn(g_UsbHostEem[eem_index].common_info,g_UsbHostEem[eem_index].ep_tx_info, 16, KAL_TRUE);
	
	USBD_Register_Drv_Info(g_UsbHostEem[eem_index].common_info,USB_HCD_HDLR_EP_RX, g_UsbHostEem[eem_index].ep_rx_info, USB_Host_EEM_State_Hdlr);

	USBD_Get_DMA_Channel(g_UsbHostEem[eem_index].common_info,g_UsbHostEem[eem_index].ep_tx_info,ep_temp, USB_EP_TX_DIR, KAL_FALSE);
	USBD_Get_DMA_Channel(g_UsbHostEem[eem_index].common_info,ep_temp,g_UsbHostEem[eem_index].ep_rx_info, USB_EP_RX_DIR, KAL_FALSE);	
		 	 
/* EEM UT Test 
 1. TX  : use Send Frame Command --> Device compare data
 2. RX  : use Get Frame Command --> Host compare data */ 
 
}



void USB_Host_Eem_Detach(kal_uint8 usb_ip_port)
{
	kal_uint8 eem_index = USB_EEM_Check_index(usb_ip_port);
	DCL_HANDLE handle;
	
	if((g_UsbHostEem[eem_index].sleep_timer_handle != 0)&&(g_UsbHostEem[eem_index].sleep_timer_handle != 0x7F))
	{	
	
		USB_GPTI_ReleaseHandle(&(g_UsbHostEem[eem_index].sleep_timer_handle));	
//		handle = (DCL_HANDLE)g_UsbHostEem[eem_index].sleep_timer_handle;
//		g_UsbHostEem[eem_index].sleep_timer_handle = DclSGPT_Close(&handle);
//		GPTI_ReleaseHandle(&g_UsbHostEem[eem_index].sleep_timer_handle);	
	}
	
	USBD_Free_DMA_Channel(g_UsbHostEem[eem_index].common_info,g_UsbHostEem[eem_index].ep_tx_info, g_UsbHostEem[eem_index].ep_rx_info, USB_EP_TX_DIR, KAL_FALSE);
	USBD_TxEPDis(g_UsbHostEem[eem_index].common_info,g_UsbHostEem[eem_index].ep_tx_info, KAL_FALSE);
	USBD_RxEPDis(g_UsbHostEem[eem_index].common_info,g_UsbHostEem[eem_index].ep_rx_info, KAL_FALSE);

	g_UsbHostEem[eem_index].dev_attatch = KAL_FALSE;

	usb_host_eem_support_num = 0;
	usb_host_eem_config_num = 0xFF;
	usb_host_eem_support_real_num = 0;
	
}

static void USB_Host_Eem_Suspend(kal_uint8 usb_ip_port)
{
// this is called by USBD_Suspend: all class has already enter suspend mode 
}


static void USB_Host_Eem_Resume(kal_uint8 usb_ip_port)
{

}

USBD_ClassDriver_Struct USB_Host_Eem_Drv = 
{
	USB_Host_Eem_Match,
	USB_Host_Eem_Startup,
	USB_Host_Eem_Detach,
	USB_Host_Eem_Suspend,
	USB_Host_Eem_Resume
};


#endif /* __IC_USB_EEM_SUPPORT__ */

#endif  /* __IC_USB_ENABLE__ */


