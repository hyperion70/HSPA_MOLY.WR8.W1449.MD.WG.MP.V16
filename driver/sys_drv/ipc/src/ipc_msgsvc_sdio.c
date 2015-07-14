/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   ipc_msgsvc_sdio.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This function implements inter-processor-communication message service.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*******************************************************************************
 * Include header files
 *******************************************************************************/

#include "kal_public_api.h" //MSBB change #include "kal_release.h"
#include <stdio.h>
#include <string.h>
#include "reg_base.h"
#include "config_hw.h"
#include "intrCtrl.h"
#include "drv_comm.h"
#include "drv_hisr.h"
#include "in_defs.h"
#include "kal_public_defs.h" //MSBB change #include "stack_common.h"
#include "stack_types.h"
#include "task_config.h"
#include "init.h"
#include "cache_sw.h"
#include "tst_trace.h"
#include "kal_trace.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "kal_internal_api.h"


//KC
#if defined(__MODEM_CCCI_EXIST__)
#if defined(__SMART_PHONE_MODEM__)

#include "ccci.h"
#include "us_timer.h"
#include "ipc_msgsvc.h"

#include "sdio_fw_api_public.h"
PRIVATE kal_bool ipc_msgsvc_lock_RW=1;


//#define __IPCMSG_DEBUG_TRACE__


/*******************************************************************************
 * Define import global variables.
 *******************************************************************************/


/*******************************************************************************
 * Define import function prototype.
 *******************************************************************************/
kal_bool ipc_msgsvc_sendmsg(kal_uint32 ipc_task_id, void *buffer_ptr, kal_uint16 msg_size,  kal_wait_mode wait_mode, kal_bool message_to_head);


#if defined(__IPCMSG_DEBUG_TRACE__)
const kal_char ipc_local_para_str[] = "ipc_local_para";
const kal_char md_local_para_str[] = "md_local_para";
const kal_char ipc_peer_buff_str[] = "ipc_peer_buff";
const kal_char md_peer_buff_str[] = "md_peer_buff";
const kal_char md_msg_str[] = "md_msg";
#endif


/*******************************************************************************
 * Define macro
 *******************************************************************************/
#define IPC_MSGSVC_ENTER_CRITICAL_SECTION  if (KAL_TRUE == kal_query_systemInit()  || INT_QueryExceptionStatus() == KAL_TRUE) \
                                           {                                                                                  \
                                              ipc_msgsvc_lock_RW--;                                                           \
                                           }                                                                                  \
                                           else                                                                               \
                                           {                                                                                  \
                                              kal_take_sem(ipc_msgsvc_ch.semaphore, KAL_INFINITE_WAIT);                              \
                                           }                                                                                  \
                                 
#define IPC_MSGSVC_EXIT_CRITICAL_SECTION   if (KAL_TRUE == kal_query_systemInit()  || INT_QueryExceptionStatus() == KAL_TRUE)    \
                                           {                                                                                  \
                                              ipc_msgsvc_lock_RW++;                                                           \
                                           }                                                                                  \
                                           else                                                                               \
                                           {                                                                                  \
                                              kal_give_sem(ipc_msgsvc_ch.semaphore);                                                 \
                                           }                                                          


/*******************************************************************************
 * Define global variables.
 *******************************************************************************/
PUBLIC Ipcsvc_Share_ST *ipcsvc_share_rx_g;
PUBLIC Ipcsvc_Share_ST *ipcsvc_share_tx_g;

/* Mapping task */
#define X_IPC_MODULE_CONF(a,b,c,d) {c,b}
IPC_MSGSVC_TASKMAP_T ipc_msgsvc_maptbl[MAX_NUM_IPC_TASKS] = 
{
    #include "ipc_msgsvc_conf.h"
};

#define MAX_IPC_MSGSVC_TASKS MAX_NUM_IPC_TASKS


/* Processing channel */
#if defined(IPC_MSGSVC_AP_TEST)
IPC_MSGSVC_T ipc_msgsvc_ch = { CCCI_MSGSVC_RCV_CHANNEL , CCCI_MSGSVC_RCV_ACK_CHANNEL, CCCI_MSGSVC_SEND_CHANNEL , CCCI_MSGSVC_SEND_ACK_CHANNEL,NULL};
#else
IPC_MSGSVC_T ipc_msgsvc_ch = { CCCI_MSGSVC_SEND_CHANNEL , CCCI_MSGSVC_SEND_ACK_CHANNEL, CCCI_MSGSVC_RCV_CHANNEL , CCCI_MSGSVC_RCV_ACK_CHANNEL, NULL};
#endif

/* The mapping table used for query */
//IPC_MSGSVC_TASKMAP_T    extq_task_maptbl[MAX_NUM_IPC_TASKS] = { {0, MOD_MMI } };
/* ipc_ilm arrary used for each task */
__attribute__  ((section ("NONCACHEDZI")))    ipc_ilm_t ipc_ilm_arr[MAX_NUM_IPC_TASKS] = {};

/*************************************************************************
* FUNCTION
*  ipc_svc_errcb
*
* DESCRIPTION
*  This function assert and only be used for channel which should not have callback
*
* PARAMETERS
*  bufp - ccci header
*
* RETURNS
*  none
*
*************************************************************************/
PRIVATE void ipc_svc_errcb(CCCI_BUFF_T *bufp)
{
    ASSERT(0);
}

/*************************************************************************
* FUNCTION
*  ipc_msgsvc_rcvmsg_hisr
*
* DESCRIPTION
*  This function will process the received data from AP side
*
* PARAMETERS
*  bufp - ccci header
*
* RETURNS
*  none
*
*************************************************************************/
__attribute__  ((section ("INTSRAM_ROCODE"))) PRIVATE void ipc_msgsvc_rcvmsg_hisr(CCCI_BUFF_T *bufp)
{
    kal_uint32	i = 0;
    ipc_ilm_t	*temp_ipc_ilm = NULL;
    void *local_param = NULL, *peer_buff = NULL;
    #if defined (__SDIO_DEVICE_CONNECTIVITY__)
    kal_uint32 len = 0;
	local_para_struct local_para_temp;//
	peer_buff_struct peer_buff_temp;//
    #endif
		
    /* get task id from mapping table of ext queue id */
    for (i = 0; i < MAX_IPC_MSGSVC_TASKS; i++) 
    {
	if ( ipc_msgsvc_maptbl[i].extq_id == bufp->reserved )
	{
   	    break;
	}
    }
		
    /* check if the extquque id can not be found */
    if (i >= MAX_IPC_MSGSVC_TASKS) 
    {
	EXT_ASSERT(0, i, bufp->channel, 0);
    }
		
    #if defined (__SDIO_DEVICE_CONNECTIVITY__)	
	    len = CCCI_HAL_OVERHEAD;//16 bytes
	    temp_ipc_ilm = (ipc_ilm_t *)((kal_uint8*)bufp+len);
	    len += sizeof(ipc_ilm_t);//24 bytes
	    
	    kal_mem_cpy((kal_uint8 *)&local_para_temp,(kal_uint8 *)bufp+len, sizeof(local_para_struct));	
		temp_ipc_ilm->local_para_ptr = 	(local_para_struct *)(&local_para_temp);		
	    if(temp_ipc_ilm->local_para_ptr)
	    {
			//the limitation is due to asynchrous interface between AP/MD, MD cann't aware the change immediately
			if (1 != temp_ipc_ilm->local_para_ptr->ref_count)
			{
		   	    ASSERT(0);
			}	  
			local_param = construct_local_para(temp_ipc_ilm->local_para_ptr->msg_len, 1);
			kal_mem_cpy((kal_uint8 *)local_param,(kal_uint8 *)bufp+len, temp_ipc_ilm->local_para_ptr->msg_len);
			len += temp_ipc_ilm->local_para_ptr->msg_len; // need 4 bytes alignment or not??
	    }
		kal_mem_cpy((kal_uint8 *)&peer_buff_temp,(kal_uint8 *)bufp+len, sizeof(peer_buff_struct));	
		temp_ipc_ilm->peer_buff_ptr = 	(peer_buff_struct *)(&peer_buff_temp);	
	    if (temp_ipc_ilm->peer_buff_ptr)
	    {
			if (1 != temp_ipc_ilm->peer_buff_ptr->ref_count)
			{
		   	    ASSERT(0);
			}	  
			peer_buff = construct_peer_buff(temp_ipc_ilm->peer_buff_ptr->pdu_len, \
			temp_ipc_ilm->peer_buff_ptr->free_header_space, \
			temp_ipc_ilm->peer_buff_ptr->free_tail_space, 1);
			kal_mem_cpy((kal_uint8 *)peer_buff,(kal_uint8 *)bufp+len, temp_ipc_ilm->peer_buff_ptr->pdu_len);
			len += temp_ipc_ilm->peer_buff_ptr->pdu_len;
	    }
	    //release SDIO memory
	    sdio_recycle_single_buffer(get_ngio_handle(), (kal_uint32) bufp); 
		
	    msg_send6 (MOD_CCCI_HISR, ipc_msgsvc_maptbl[i].task_id, temp_ipc_ilm->sap_id, temp_ipc_ilm->msg_id, local_param, peer_buff);
	    return;	
    #else //CCIF
	    /* retrieve the ipc msgsvc message */
	    if (CCCI_STREAM_LEN(bufp) != sizeof(ipc_ilm_t))
	    {
			ASSERT(0);
	    }
	    else
	    {
			temp_ipc_ilm = (ipc_ilm_t *)CCCI_STREAM_ADDR(bufp);
	    }
			
	    /* allocate the memoy space for local paramter usage */
	    if (temp_ipc_ilm->local_para_ptr)
	    {	
				
			if ((kal_uint32)temp_ipc_ilm->local_para_ptr != ((kal_uint32)&(ipcsvc_share_rx_g->buffer) + ipcsvc_share_rx_g->rx_offset))
			{
		  	    ASSERT(0);
			}
				
			/* Source should not keep the data because agent will relieve it in current design */
			if (1 != temp_ipc_ilm->local_para_ptr->ref_count)
			{
			    ASSERT(0);
			}	  
			local_param = construct_local_para(temp_ipc_ilm->local_para_ptr->msg_len, 1);
							   
			if (ipcsvc_share_rx_g->rx_offset + temp_ipc_ilm->local_para_ptr->msg_len == ipcsvc_share_rx_g->size  )	   
			{
		        #if defined(__IPCMSG_DEBUG_TRACE__)
				    kal_buffer_trace(TRACE_INFO, TR_BUFFER_TRACE, sizeof(md_local_para_str), (const kal_uint8 *)ipc_local_para_str);
				    kal_buffer_trace(TRACE_INFO, TR_BUFFER_TRACE, 4, (const kal_uint8 *)&(ipcsvc_share_rx_g->rx_offset));
				    kal_buffer_trace(TRACE_INFO, TR_BUFFER_TRACE, temp_ipc_ilm->local_para_ptr->msg_len, (const kal_uint8 *)temp_ipc_ilm->local_para_ptr);
			    #endif 
			    kal_mem_cpy((kal_uint8 *)local_param,(kal_uint8 *)temp_ipc_ilm->local_para_ptr,temp_ipc_ilm->local_para_ptr->msg_len);
			    ipcsvc_share_rx_g->rx_offset = 0;	
			
			}
			else if (ipcsvc_share_rx_g->rx_offset + temp_ipc_ilm->local_para_ptr->msg_len <  ipcsvc_share_rx_g->size )
			{
			
			    #if defined(__IPCMSG_DEBUG_TRACE__)
				    kal_buffer_trace(TRACE_INFO, TR_BUFFER_TRACE, sizeof(md_local_para_str), (const kal_uint8 *)ipc_local_para_str);
				    kal_buffer_trace(TRACE_INFO, TR_BUFFER_TRACE, 4, (const kal_uint8 *)&(ipcsvc_share_rx_g->rx_offset));
				    kal_buffer_trace(TRACE_INFO, TR_BUFFER_TRACE, temp_ipc_ilm->local_para_ptr->msg_len, (const kal_uint8 *)temp_ipc_ilm->local_para_ptr);
			    #endif 
			
			    kal_mem_cpy((kal_uint8 *)local_param,(kal_uint8 *)temp_ipc_ilm->local_para_ptr,temp_ipc_ilm->local_para_ptr->msg_len);
			    ipcsvc_share_rx_g->rx_offset += temp_ipc_ilm->local_para_ptr->msg_len ;
			}
			else
			{
			
		        #if defined(__IPCMSG_DEBUG_TRACE__)
				    kal_buffer_trace(TRACE_INFO, TR_BUFFER_TRACE, sizeof(md_local_para_str), (const kal_uint8 *)ipc_local_para_str);
				    kal_buffer_trace(TRACE_INFO, TR_BUFFER_TRACE, 4, (const kal_uint8 *)&(ipcsvc_share_rx_g->rx_offset));
				    kal_buffer_trace(TRACE_INFO, TR_BUFFER_TRACE, (ipcsvc_share_rx_g->size) - ipcsvc_share_rx_g->rx_offset, (const kal_uint8 *)temp_ipc_ilm->local_para_ptr);
			    #endif 
			
				
			    kal_mem_cpy((kal_uint8 *)local_param,(kal_uint8 *)temp_ipc_ilm->local_para_ptr, (ipcsvc_share_rx_g->size) - ipcsvc_share_rx_g->rx_offset);
			    kal_mem_cpy((kal_uint8 *)local_param + ((ipcsvc_share_rx_g->size) - ipcsvc_share_rx_g->rx_offset), \
			    (kal_uint8 *)temp_ipc_ilm->local_para_ptr - ipcsvc_share_rx_g->rx_offset , \
			    temp_ipc_ilm->local_para_ptr->msg_len - (ipcsvc_share_rx_g->size - ipcsvc_share_rx_g->rx_offset));
			
			    ipcsvc_share_rx_g->rx_offset = temp_ipc_ilm->local_para_ptr->msg_len - ((ipcsvc_share_rx_g->size) - ipcsvc_share_rx_g->rx_offset);	
						
			}
		
		    #if defined(__IPCMSG_DEBUG_TRACE__)
				kal_buffer_trace(TRACE_INFO, TR_BUFFER_TRACE, sizeof(md_local_para_str), (const kal_uint8 *)md_local_para_str);
				kal_buffer_trace(TRACE_INFO, TR_BUFFER_TRACE, temp_ipc_ilm->local_para_ptr->msg_len, (const kal_uint8 *)local_param);
			#endif
			
			
    	}
		
	    /* allocate the memoy space for peer_buff usage */
	    if (temp_ipc_ilm->peer_buff_ptr)
	    {
				
			if ((kal_uint32)temp_ipc_ilm->peer_buff_ptr != ((kal_uint32)&(ipcsvc_share_rx_g->buffer) + ipcsvc_share_rx_g->rx_offset))
			{
			    ASSERT(0);
			}
				
			if (1 != temp_ipc_ilm->peer_buff_ptr->ref_count)
			{
			    ASSERT(0);
			}	  
				 
			peer_buff = construct_peer_buff( temp_ipc_ilm->peer_buff_ptr->pdu_len, \
			temp_ipc_ilm->peer_buff_ptr->free_header_space, \
			temp_ipc_ilm->peer_buff_ptr->free_tail_space, 1);
				
			if (ipcsvc_share_rx_g->rx_offset + temp_ipc_ilm->peer_buff_ptr->pdu_len == ipcsvc_share_rx_g->size)
			{
			
			    #if defined(__IPCMSG_DEBUG_TRACE__)
				    kal_buffer_trace(TRACE_INFO, TR_BUFFER_TRACE, sizeof(ipc_peer_buff_str), (const kal_uint8 *)ipc_peer_buff_str);
				    kal_buffer_trace(TRACE_INFO, TR_BUFFER_TRACE, 4, (const kal_uint8 *)&(ipcsvc_share_rx_g->rx_offset));
				    kal_buffer_trace(TRACE_INFO, TR_BUFFER_TRACE, temp_ipc_ilm->peer_buff_ptr->pdu_len, (const kal_uint8 *)temp_ipc_ilm->peer_buff_ptr);
			    #endif
			
			    kal_mem_cpy((kal_uint8 *)peer_buff,  (kal_uint8 *)temp_ipc_ilm->peer_buff_ptr, temp_ipc_ilm->peer_buff_ptr->pdu_len);
			    ipcsvc_share_rx_g->rx_offset = 0;
			}
			else if (ipcsvc_share_rx_g->rx_offset + temp_ipc_ilm->peer_buff_ptr->pdu_len < ipcsvc_share_rx_g->size)
			{
			
			    #if defined(__IPCMSG_DEBUG_TRACE__)
				    kal_buffer_trace(TRACE_INFO, TR_BUFFER_TRACE, sizeof(ipc_peer_buff_str), (const kal_uint8 *)ipc_peer_buff_str);
				    kal_buffer_trace(TRACE_INFO, TR_BUFFER_TRACE, 4, (const kal_uint8 *)&(ipcsvc_share_rx_g->rx_offset));
				    kal_buffer_trace(TRACE_INFO, TR_BUFFER_TRACE, temp_ipc_ilm->peer_buff_ptr->pdu_len, (const kal_uint8 *)temp_ipc_ilm->peer_buff_ptr);
			    #endif
			    kal_mem_cpy((kal_uint8 *)peer_buff,  (kal_uint8 *)temp_ipc_ilm->peer_buff_ptr, temp_ipc_ilm->peer_buff_ptr->pdu_len);
			    ipcsvc_share_rx_g->rx_offset += temp_ipc_ilm->peer_buff_ptr->pdu_len;
			}
			else
			{
			
			    #if defined(__IPCMSG_DEBUG_TRACE__)
				    kal_buffer_trace(TRACE_INFO, TR_BUFFER_TRACE, sizeof(ipc_peer_buff_str), (const kal_uint8 *)ipc_peer_buff_str);
				    kal_buffer_trace(TRACE_INFO, TR_BUFFER_TRACE, 4, (const kal_uint8 *)&(ipcsvc_share_rx_g->rx_offset));
				    kal_buffer_trace(TRACE_INFO, TR_BUFFER_TRACE, ipcsvc_share_rx_g->size - ipcsvc_share_rx_g->rx_offset, (const kal_uint8 *)temp_ipc_ilm->peer_buff_ptr);
			    #endif		
			    kal_mem_cpy((kal_uint8 *)peer_buff, (kal_uint8 *)temp_ipc_ilm->peer_buff_ptr, ipcsvc_share_rx_g->size - ipcsvc_share_rx_g->rx_offset);
			    kal_mem_cpy((kal_uint8 *)peer_buff+  ipcsvc_share_rx_g->size - ipcsvc_share_rx_g->rx_offset, \
				(kal_uint8 *)temp_ipc_ilm->peer_buff_ptr - ipcsvc_share_rx_g->rx_offset, \
				temp_ipc_ilm->peer_buff_ptr->pdu_len - (ipcsvc_share_rx_g->size - ipcsvc_share_rx_g->rx_offset));
				ipcsvc_share_rx_g->rx_offset = temp_ipc_ilm->peer_buff_ptr->pdu_len - ((ipcsvc_share_rx_g->size) - ipcsvc_share_rx_g->rx_offset);
			}
		
		
			#if defined(__IPCMSG_DEBUG_TRACE__)
				kal_buffer_trace(TRACE_INFO, TR_BUFFER_TRACE, sizeof(md_peer_buff_str), (const kal_uint8 *)md_peer_buff_str);
				kal_buffer_trace(TRACE_INFO, TR_BUFFER_TRACE, temp_ipc_ilm->peer_buff_ptr->pdu_len, (const kal_uint8 *)peer_buff);
			#endif       
	    }
			
	    /* feedback to the sender the message is receive */
	    ccci_mailbox_write_with_reserved(ipc_msgsvc_ch.receive_ack_channel, IPC_MSGSVC_RVC_DONE, bufp->reserved);
			
		
	    #if defined(__IPCMSG_DEBUG_TRACE__)
		    kal_buffer_trace(TRACE_INFO, TR_BUFFER_TRACE, sizeof(md_msg_str), (const kal_uint8 *)md_msg_str);
		    kal_buffer_trace(TRACE_INFO, TR_BUFFER_TRACE, sizeof(ilm_struct), (const kal_uint8 *)ilmp);
	    #endif        
		
		msg_send6 (MOD_CCCI_HISR, ipc_msgsvc_maptbl[i].task_id, temp_ipc_ilm->sap_id, temp_ipc_ilm->msg_id, local_param, peer_buff);		 
	    return;
	#endif
}

/*************************************************************************
* FUNCTION
*  ipc_msgsvc_sendmsg_cb
*
* DESCRIPTION
*  This function is the cb of sendmsg
*
* PARAMETERS
*  bufp - ccci header
*
* RETURNS
*  none
*
*************************************************************************/
PRIVATE void ipc_msgsvc_sendmsg_cb(CCCI_BUFF_T *bufp)
{
    kal_uint32 i = 0;
    /* get task id from mapping table of ext queue id */
    for (i = 0; i < MAX_IPC_MSGSVC_TASKS; i++) 
    {
        if ( ipc_msgsvc_maptbl[i].extq_id == bufp->reserved )
        {
            break;
        }
    }
    kal_set_eg_events(ipc_msgsvc_ch.event,  (1 << i) , KAL_OR);
    return;
}

/*************************************************************************
* FUNCTION
*  ipc_msgsvc_allocate_ilm
*
* DESCRIPTION
*  This function will allocate ilm data structure
*
* PARAMETERS
*  module_id - 
*
* RETURNS
*  ipc_ilm_t - ilm structure ptr
*
*************************************************************************/
PUBLIC ipc_ilm_t* ipc_msgsvc_allocate_ilm(module_type module_id)
{
    kal_uint32 i=0;

    for (i = 0 ; i < MAX_IPC_MSGSVC_TASKS; i++)
    {
        if (module_id == ipc_msgsvc_maptbl[i].task_id)
        {
            return &ipc_ilm_arr[i];
        }

    }

    return NULL;
}



/*************************************************************************
* FUNCTION
*  ipc_msgsvc_send_ext_queue
*
* DESCRIPTION
*  This function will return if the owner need to check
*
* PARAMETERS
*  none
*
* RETURNS
*  none
*
*************************************************************************/
PUBLIC kal_bool ipc_msgsvc_send_ext_queue(ipc_ilm_t*ipc_ilm_t_ptr)
{
    return ipc_msgsvc_sendmsg((kal_uint32)(ipc_ilm_t_ptr->dest_mod_id), (void *)(ipc_ilm_t_ptr), (kal_uint16)sizeof(ipc_ilm_t),  KAL_INFINITE_WAIT, KAL_FALSE);
    
    
}


/*************************************************************************
* FUNCTION
*  ipc_msgsvc_sendmsg
*
* DESCRIPTION
*  This function is the internal api to send message
*
* PARAMETERS
*  ipc_task_id     -  
*  buffer_ptr      -
*  msg_size        -
*  wait_mode       -
*  message_to_head -
*
* RETURNS
*  status - success/fail
*
*************************************************************************/
PRIVATE kal_bool ipc_msgsvc_sendmsg(kal_uint32 ipc_task_id, void *buffer_ptr, kal_uint16 msg_size,	kal_wait_mode wait_mode, kal_bool message_to_head)
{
    kal_uint32 i, j ;
    kal_uint32 retrieved_events = 0, orig_local_addr = 0 , orig_peer_addr = 0, update_buff_addr=0;
    kal_int32 result = CCCI_SUCCESS;
    ipc_ilm_t	*temp_ipc_ilm = NULL;

    #if defined(__SDIO_DEVICE_CONNECTIVITY__)
		CCCI_BUFF_T ccci_buff;
    kal_uint32 len = 0;
    #endif
	
		
		
    temp_ipc_ilm = (ipc_ilm_t *)buffer_ptr;
		
    /* get ext queue id from mapping table of task id */
    for (i = 0; i < MAX_IPC_MSGSVC_TASKS; i++) 
    {
        if ( ipc_msgsvc_maptbl[i].task_id == ipc_task_id )
	{
            break;
	}
    }
	
    /* get ext queue id from mapping table of task id */
    for (j = 0; j < MAX_IPC_MSGSVC_TASKS; j++) 
    {
        if ( ipc_msgsvc_maptbl[j].task_id == temp_ipc_ilm->src_mod_id )
	{
            break;
	}
    }
		
    /* check if the extquque id can not be found */
    if (i >= MAX_IPC_MSGSVC_TASKS || j >= MAX_IPC_MSGSVC_TASKS) 
    {
	EXT_ASSERT(0, i, j, ipc_task_id);
    }
		
    /* Use critical section to protect ENTER */
    IPC_MSGSVC_ENTER_CRITICAL_SECTION
	
    temp_ipc_ilm->src_mod_id =	ipc_msgsvc_maptbl[j].extq_id; 

    #if defined (__SDIO_DEVICE_CONNECTIVITY__)
    //the same design rule in FS/RPC
    if (temp_ipc_ilm->local_para_ptr != NULL && temp_ipc_ilm->peer_buff_ptr != NULL)
    {
			//calculate total length including CCCI overhead
			len = sizeof(CCCI_BUFF_T) + sizeof(ipc_ilm_t) + temp_ipc_ilm->local_para_ptr->msg_len + temp_ipc_ilm->peer_buff_ptr->pdu_len;
					
			//when assert in here, we should increase the shared buffer in CCCI 
			if(ipcsvc_share_tx_g->size < len)
		  	    ASSERT(0);

			update_buff_addr = (kal_uint32)((kal_uint8 *)&ipcsvc_share_tx_g->buffer);
			//initialize ccci_buffer content & copy ccci_buffer to memory
			ccci_buff.data[0] = (kal_uint32)update_buff_addr;
			ccci_buff.data[1] = (kal_uint32)len;
			ccci_buff.channel = (kal_uint32)ipc_msgsvc_ch.send_channel;
			ccci_buff.reserved = (kal_uint32)ipc_msgsvc_maptbl[i].extq_id;
			kal_mem_cpy((kal_uint8 *)update_buff_addr ,(kal_uint8 *)&ccci_buff, CCCI_HAL_OVERHEAD);
			
			//copy ilm to memory
			update_buff_addr += CCCI_HAL_OVERHEAD;							
			kal_mem_cpy((kal_uint8 *)update_buff_addr ,(kal_uint8 *)temp_ipc_ilm, sizeof(ipc_ilm_t));
			
			//copy loca_para_struct to memory
			update_buff_addr += sizeof(ipc_ilm_t); //24 bytes
			orig_local_addr = update_buff_addr;
			kal_mem_cpy((kal_uint8 *)update_buff_addr,(kal_uint8 *)temp_ipc_ilm->local_para_ptr, temp_ipc_ilm->local_para_ptr->msg_len);

			//copy peer buff_struct to memory
			update_buff_addr += temp_ipc_ilm->local_para_ptr->msg_len;//should be 4 bytes alignment?? 0530
			orig_peer_addr = update_buff_addr;
			kal_mem_cpy((kal_uint8 *)update_buff_addr,(kal_uint8 *)temp_ipc_ilm->local_para_ptr, temp_ipc_ilm->local_para_ptr->msg_len);

			free_local_para(temp_ipc_ilm->local_para_ptr);
			temp_ipc_ilm->local_para_ptr = (local_para_struct *)orig_local_addr;//assign not NULL ptr to indicate there have content 
					
			free_peer_buff(temp_ipc_ilm->peer_buff_ptr);
			temp_ipc_ilm->peer_buff_ptr = (peer_buff_struct *)orig_peer_addr;//assign not NULL ptr to indicate there have content			
				
			do
			{
			    result = ccci_write(ipc_msgsvc_ch.send_channel, (CCCI_BUFF_T *)&ipcsvc_share_tx_g->buffer);	
	}
	while (KAL_INFINITE_WAIT == wait_mode && CCCI_SUCCESS != result);
			
	/* Wait for feedabck by retrieve event */
	kal_retrieve_eg_events(ipc_msgsvc_ch.event, 1 << i, KAL_AND_CONSUME,  &retrieved_events, KAL_SUSPEND);
			
			
	/* Exit critical section */ 
	IPC_MSGSVC_EXIT_CRITICAL_SECTION
		
	/* Finish */		
	return KAL_TRUE;
    }
		
    if (temp_ipc_ilm->local_para_ptr != NULL)
    {
	if (1 != temp_ipc_ilm->local_para_ptr->ref_count)
	{
	    ASSERT(0);
	}
					
			len = sizeof(CCCI_BUFF_T) + sizeof(ipc_ilm_t) + temp_ipc_ilm->local_para_ptr->msg_len;

			if(ipcsvc_share_tx_g->size < len)
			    ASSERT(0);

			update_buff_addr = (kal_uint32)((kal_uint8 *)&ipcsvc_share_tx_g->buffer);
			//initialize ccci_buffer content & copy ccci_buffer to memory
			ccci_buff.data[0] = (kal_uint32)update_buff_addr;
			ccci_buff.data[1] = (kal_uint32)len;
			ccci_buff.channel = (kal_uint32)ipc_msgsvc_ch.send_channel;
			ccci_buff.reserved = (kal_uint32)ipc_msgsvc_maptbl[i].extq_id;
			kal_mem_cpy((kal_uint8 *)update_buff_addr ,(kal_uint8 *)&ccci_buff, CCCI_HAL_OVERHEAD);
			
			//copy ilm to memory
			update_buff_addr += CCCI_HAL_OVERHEAD;	
			kal_mem_cpy((kal_uint8 *)update_buff_addr ,(kal_uint8 *)temp_ipc_ilm, sizeof(ipc_ilm_t));

			//copy loca_para_struct to memory
			update_buff_addr += sizeof(ipc_ilm_t); //24 bytes
			orig_local_addr = update_buff_addr;
			kal_mem_cpy((kal_uint8 *)&ipcsvc_share_tx_g->buffer,(kal_uint8 *)temp_ipc_ilm->local_para_ptr, temp_ipc_ilm->local_para_ptr->msg_len);

			free_local_para(temp_ipc_ilm->local_para_ptr);
			temp_ipc_ilm->local_para_ptr = (local_para_struct *)orig_local_addr;			
    }

    if (temp_ipc_ilm->peer_buff_ptr != NULL)
    {
	if (1 != temp_ipc_ilm->peer_buff_ptr->ref_count)
	{
  	    ASSERT(0);
	}
			
	len = sizeof(CCCI_BUFF_T) + 3*sizeof(kal_uint32) + sizeof(ipc_ilm_t) + sizeof(peer_buff_struct) + temp_ipc_ilm->peer_buff_ptr->pdu_len;
				  
	if(ipcsvc_share_tx_g->size < len)
	    ASSERT(0);
			update_buff_addr = (kal_uint32)((kal_uint8 *)&ipcsvc_share_tx_g->buffer);
			//initialize ccci_buffer content & copy ccci_buffer to memory
			ccci_buff.data[0] = (kal_uint32)update_buff_addr;
			ccci_buff.data[1] = (kal_uint32)len;
			ccci_buff.channel = (kal_uint32)ipc_msgsvc_ch.send_channel;
			ccci_buff.reserved = (kal_uint32)ipc_msgsvc_maptbl[i].extq_id;
			kal_mem_cpy((kal_uint8 *)update_buff_addr ,(kal_uint8 *)&ccci_buff, CCCI_HAL_OVERHEAD);
			
			//copy ilm to memory
			update_buff_addr += CCCI_HAL_OVERHEAD;	
			kal_mem_cpy((kal_uint8 *)update_buff_addr ,(kal_uint8 *)temp_ipc_ilm, sizeof(ipc_ilm_t));

			//copy loca_para_struct to memory
			update_buff_addr += sizeof(ipc_ilm_t); //24 bytes
			orig_peer_addr = update_buff_addr;
			kal_mem_cpy((kal_uint8 *)&ipcsvc_share_tx_g->buffer,(kal_uint8 *)temp_ipc_ilm->peer_buff_ptr, temp_ipc_ilm->peer_buff_ptr->pdu_len);
						
			free_peer_buff(temp_ipc_ilm->peer_buff_ptr);
			temp_ipc_ilm->peer_buff_ptr = (peer_buff_struct *)orig_peer_addr;			
    }
				
    do
    {
			result = ccci_write(ipc_msgsvc_ch.send_channel, (CCCI_BUFF_T *)&ipcsvc_share_tx_g->buffer);	
    }
    while (KAL_INFINITE_WAIT == wait_mode && CCCI_SUCCESS != result);
		
    /* Wait for feedabck by retrieve event */
    kal_retrieve_eg_events(ipc_msgsvc_ch.event, 1 << i, KAL_AND_CONSUME,  &retrieved_events, KAL_SUSPEND);
				
    /* Exit critical section */ 
    IPC_MSGSVC_EXIT_CRITICAL_SECTION
	
    /* Finish */		
    return KAL_TRUE;
			
    #else //CCIF	
    /* Check if peer buff and local parameter exist and store to writer share buffer */
    if (temp_ipc_ilm->local_para_ptr != NULL)
    {
	if (1 != temp_ipc_ilm->local_para_ptr->ref_count)
	{
	    ASSERT(0);
	}	 
	
	orig_local_addr = (kal_uint32)((kal_uint8 *)&ipcsvc_share_tx_g->buffer + ipcsvc_share_tx_g->tx_offset);
			
	if (ipcsvc_share_tx_g->tx_offset + temp_ipc_ilm->local_para_ptr->msg_len == ipcsvc_share_tx_g->size  )	   
	{
	    kal_mem_cpy((kal_uint8 *)&ipcsvc_share_tx_g->buffer + ipcsvc_share_tx_g->tx_offset,(kal_uint8 *)temp_ipc_ilm->local_para_ptr,temp_ipc_ilm->local_para_ptr->msg_len);
	    ipcsvc_share_tx_g->tx_offset = 0;
	}
	else if (ipcsvc_share_tx_g->tx_offset + temp_ipc_ilm->local_para_ptr->msg_len <  ipcsvc_share_tx_g->size )
	{
	    kal_mem_cpy((kal_uint8 *)&ipcsvc_share_tx_g->buffer + ipcsvc_share_tx_g->tx_offset,(kal_uint8 *)temp_ipc_ilm->local_para_ptr,temp_ipc_ilm->local_para_ptr->msg_len);
	    ipcsvc_share_tx_g->tx_offset += temp_ipc_ilm->local_para_ptr->msg_len ;
	}
	else
	{
	    kal_mem_cpy((kal_uint8 *)&ipcsvc_share_tx_g->buffer + ipcsvc_share_tx_g->tx_offset ,(kal_uint8 *)temp_ipc_ilm->local_para_ptr, (ipcsvc_share_tx_g->size) - ipcsvc_share_tx_g->tx_offset);
			
	    kal_mem_cpy((kal_uint8 *)&ipcsvc_share_tx_g->buffer , \
			(kal_uint8 *)temp_ipc_ilm->local_para_ptr +  (ipcsvc_share_tx_g->size) - ipcsvc_share_tx_g->tx_offset , \
			temp_ipc_ilm->local_para_ptr->msg_len - (ipcsvc_share_tx_g->size - ipcsvc_share_tx_g->tx_offset));
	
	    ipcsvc_share_tx_g->tx_offset = temp_ipc_ilm->local_para_ptr->msg_len - ((ipcsvc_share_tx_g->size) - ipcsvc_share_tx_g->tx_offset);	
				
	}
	
	/* Free local parameter and peer buff */
	free_local_para(temp_ipc_ilm->local_para_ptr);
	temp_ipc_ilm->local_para_ptr = (local_para_struct *)orig_local_addr;
	
    }
	
	
	
	
	
    if (temp_ipc_ilm->peer_buff_ptr != NULL)
    {
			
	if (1 != temp_ipc_ilm->peer_buff_ptr->ref_count)
	{
  	    ASSERT(0);
	}	  
			 
	
	orig_peer_addr = (kal_uint32)((kal_uint8 *)&ipcsvc_share_tx_g->buffer + ipcsvc_share_tx_g->tx_offset);
			
	if (ipcsvc_share_tx_g->tx_offset + temp_ipc_ilm->peer_buff_ptr->pdu_len == ipcsvc_share_tx_g->size)
	{
	    kal_mem_cpy((kal_uint8 *)&ipcsvc_share_tx_g->buffer + ipcsvc_share_tx_g->tx_offset,  (kal_uint8 *)temp_ipc_ilm->peer_buff_ptr, temp_ipc_ilm->peer_buff_ptr->pdu_len);
	    ipcsvc_share_tx_g->tx_offset = 0;
	}
	else if (ipcsvc_share_tx_g->tx_offset + temp_ipc_ilm->peer_buff_ptr->pdu_len < ipcsvc_share_tx_g->size)
	{
	    kal_mem_cpy((kal_uint8 *)&ipcsvc_share_tx_g->buffer + ipcsvc_share_tx_g->tx_offset,  (kal_uint8 *)temp_ipc_ilm->peer_buff_ptr, temp_ipc_ilm->peer_buff_ptr->pdu_len);
	    ipcsvc_share_tx_g->tx_offset += temp_ipc_ilm->peer_buff_ptr->pdu_len;
	}
	else
	{
	    kal_mem_cpy((kal_uint8 *)&ipcsvc_share_tx_g->buffer + ipcsvc_share_tx_g->tx_offset, (kal_uint8 *)temp_ipc_ilm->peer_buff_ptr, ipcsvc_share_tx_g->size - ipcsvc_share_tx_g->tx_offset);
	    kal_mem_cpy((kal_uint8 *)&ipcsvc_share_tx_g->buffer, \
	  	        (kal_uint8 *)temp_ipc_ilm->peer_buff_ptr + ipcsvc_share_tx_g->size - ipcsvc_share_tx_g->tx_offset, \
			temp_ipc_ilm->peer_buff_ptr->pdu_len - (ipcsvc_share_tx_g->size - ipcsvc_share_tx_g->tx_offset));
	    ipcsvc_share_tx_g->tx_offset = temp_ipc_ilm->peer_buff_ptr->pdu_len - ((ipcsvc_share_tx_g->size) - ipcsvc_share_tx_g->tx_offset);
	}
	
	/* Free peer buffer */
	free_peer_buff(temp_ipc_ilm->peer_buff_ptr);
	temp_ipc_ilm->peer_buff_ptr = (peer_buff_struct *)orig_peer_addr;
	
    }
	   
		
    do
    {
	result = ccci_stream_write_with_reserved(ipc_msgsvc_ch.send_channel, (kal_uint32)buffer_ptr, msg_size ,ipc_msgsvc_maptbl[i].extq_id);
    }
    while (KAL_INFINITE_WAIT == wait_mode && CCCI_SUCCESS != result);
		
    /* Wait for feedabck by retrieve event */
    kal_retrieve_eg_events(ipc_msgsvc_ch.event, 1 << i, KAL_AND_CONSUME,  &retrieved_events, KAL_SUSPEND);
		
		
    /* Exit critical section */ 
    IPC_MSGSVC_EXIT_CRITICAL_SECTION
	
    /* Finish */		
    return KAL_TRUE;
    #endif
}

/*************************************************************************
* FUNCTION
*  ipc_msgsvc_receive_msg_ext_q
*
* DESCRIPTION
*  This function is useless because we will send the message directly to the task's queue
*
* PARAMETERS
*  uesless
*
* RETURNS
*  none
*
*************************************************************************/
PUBLIC kal_bool ipc_msgsvc_receive_msg_ext_q(kal_msgqid task_ext_qid, ilm_struct *ilm_ptr)
{
	/* This function is useless because we will send the message directly to the task's queue */
	return 0;
}

/*************************************************************************
* FUNCTION
*  ipc_msgsvc_receivemsg
*
* DESCRIPTION
*  This function is useless because we will send the message directly to the task's queue
*
* PARAMETERS
*  useless
*
* RETURNS
*  none
*
*************************************************************************/
PUBLIC void ipc_msgsvc_receivemsg(kal_uint32 ipc_task_id, void *buffer_ptr, kal_uint16 msg_size,  kal_wait_mode wait_mode, kal_bool message_to_head)
{
    /* This function is useless because we will send the message directly to the task's queue */
}

/*************************************************************************
* FUNCTION
*  ipc_msgsvc_init
*
* DESCRIPTION
*  This function is to initialize ipc message passing service
*
* PARAMETERS
*  none
*
* RETURNS
*  none
*
*************************************************************************/

PUBLIC void ipc_msgsvc_init(void)
{
    #if defined (__SDIO_DEVICE_CONNECTIVITY__)
    //Send message does not need callback
    ccci_init(ipc_msgsvc_ch.send_channel ,  ipc_msgsvc_sendmsg_cb);
    //send mesage ack need to implement callback
    ccci_init(ipc_msgsvc_ch.send_ack_channel , ipc_svc_errcb);
    //Receive mesage need to implement callback
    ccci_init(ipc_msgsvc_ch.receive_channel , ipc_msgsvc_rcvmsg_hisr);
    //Receive mesage ack does not need to implement callback
    ccci_init(ipc_msgsvc_ch.receive_ack_channel , ipc_svc_errcb);
    #else //for CCIF
    //Send message does not need callback
    ccci_init(ipc_msgsvc_ch.send_channel , ipc_svc_errcb );
    //send mesage ack need to implement callback
    ccci_init(ipc_msgsvc_ch.send_ack_channel , ipc_msgsvc_sendmsg_cb);
    //Receive mesage need to implement callback
    ccci_init(ipc_msgsvc_ch.receive_channel , ipc_msgsvc_rcvmsg_hisr);
    //Receive mesage ack does not need to implement callback
    ccci_init(ipc_msgsvc_ch.receive_ack_channel , ipc_svc_errcb);
    #endif
	
    //Initialize the event for usage
    ipc_msgsvc_ch.event = kal_create_event_group("IPC_MSGSVC");
    //Initialize the semaphore for critical section 
    ipc_msgsvc_ch.semaphore = kal_create_sem("IPC_MSGSVC",1); 
}
#endif /* __SMART_PHONE_MODEM__ */
#endif /* __MODEM_CCCI_EXIST__ */
