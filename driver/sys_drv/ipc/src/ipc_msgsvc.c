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
 *   ipc_msgsvc.c
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
 *
 * removed!
 * removed!
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*******************************************************************************
 * Include header files
 *******************************************************************************/

#include "kal_public_api.h"
#include <stdio.h>
#include <string.h>

#include "reg_base.h"
#include "config_hw.h"
#include "intrCtrl.h"
#include "drv_comm.h"
#include "drv_hisr.h"
#include "in_defs.h"

#include "init.h"
#include "cache_sw.h"
#include "tst_trace.h"
#include "kal_trace.h"

#if defined(__MODEM_CCCI_EXIST__)
#include "ccci.h"
#include "us_timer.h"
#include "ipc_msgsvc.h"
#include "ccif.h"
#include "ccci_int.h"
static kal_bool ipc_msgsvc_lock_RW = (kal_bool)1;


//#define __IPCMSG_DEBUG_TRACE__


/********************************************************************************
 * Define import global variables.
 ********************************************************************************/
extern kal_bool  ccci_debug_phychan_full;

/*******************************************************************************
 * Define import function prototype.
 *******************************************************************************/
kal_bool ipc_msgsvc_sendmsg(kal_uint32 ipc_task_id, void *buffer_ptr, kal_uint16 msg_size,  kal_wait_mode wait_mode, kal_bool message_to_head);
extern kal_bool kal_query_systemInit(void);
extern kal_bool INT_QueryExceptionStatus(void);
extern void kal_buffer_trace(trace_class_enum trc_class, kal_uint32 msg_index, const kal_char* fmt, kal_uint32 buf_len, const kal_uint8* pData);


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
                                              kal_take_sem(ipc_msgsvc_ch.semaphore, KAL_INFINITE_WAIT);                       \
                                           }                                                                                  \
 
#define IPC_MSGSVC_EXIT_CRITICAL_SECTION   if (KAL_TRUE == kal_query_systemInit()  || INT_QueryExceptionStatus() == KAL_TRUE) \
                                           {                                                                                  \
                                              ipc_msgsvc_lock_RW++;                                                           \
                                           }                                                                                  \
                                           else                                                                               \
                                           {                                                                                  \
                                              kal_give_sem(ipc_msgsvc_ch.semaphore);                                          \
                                           }


/*******************************************************************************
 * Define global variables.
 *******************************************************************************/
Ipcsvc_Share_ST *ipcsvc_share_rx_g;
Ipcsvc_Share_ST *ipcsvc_share_tx_g;

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

__attribute__((section ("NONCACHEDZI"))) ipc_ilm_t ipc_ilm_arr[MAX_NUM_IPC_TASKS];

/*************************************************************************
* FUNCTION
*  ipc_svc_errcb
*
* DESCRIPTION
*  This function assert and only be used for channel which should not have callback
*
* PARAMETERS
*  none
*
* RETURNS
*  none
*
*************************************************************************/
void ipc_svc_errcb(CCCI_BUFF_T *bufp)
{
    ASSERT(0);
    return;
}

/*************************************************************************
* FUNCTION
*  ipc_msgsvc_rcvmsg_hisr
*
* DESCRIPTION
*  Callback function of receive message
*
* PARAMETERS
*  none
*
* RETURNS
*  none
*
*************************************************************************/
#ifndef CCCI_CODE_EXT_RAM
__attribute__((section ("INTSRAM_ROCODE")))
#endif
void ipc_msgsvc_rcvmsg_hisr(CCCI_BUFF_T *bufp)
{
    kal_uint32  i = 0, tmp_msg_id;
    kal_int32	leftSize, ret, retry = IPC_MSG_MAX_RETRY;
    ipc_ilm_t   *temp_ipc_ilm = NULL;
    void *local_param = NULL, *peer_buff = NULL;
    local_para_struct   l_para_header;
    local_para_struct   *pl_para_header = NULL;
    peer_buff_struct    peer_header;
    peer_buff_struct    *pPeer_header = NULL;

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
        EXT_ASSERT(0, IPC_MSG_CCCI_ERROR_RECV_ID_MISMATCH, bufp->reserved, bufp->channel);
    }

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
        leftSize = ipcsvc_share_rx_g->size - ipcsvc_share_rx_g->rx_offset;
        
        if (leftSize >= sizeof(local_para_struct))
        {
            pl_para_header = temp_ipc_ilm->local_para_ptr;
        }
        else
        {
            kal_mem_cpy((kal_uint8*)(&l_para_header), (kal_uint8*)temp_ipc_ilm->local_para_ptr, leftSize);
            kal_mem_cpy((kal_uint8*)(&l_para_header) + leftSize, (kal_uint8*)&(ipcsvc_share_rx_g->buffer), sizeof(local_para_struct) - leftSize);
            pl_para_header = &l_para_header;
        }

        if ((kal_uint32)temp_ipc_ilm->local_para_ptr != ((kal_uint32)&(ipcsvc_share_rx_g->buffer) + ipcsvc_share_rx_g->rx_offset))
        {
            ASSERT(0);
        }

        /* Source should not keep the data because agent will relieve it in current design */
        if (1 != pl_para_header->ref_count)
        {
            ASSERT(0);
        }
        local_param = construct_local_para(pl_para_header->msg_len, 1);

        if (ipcsvc_share_rx_g->rx_offset + pl_para_header->msg_len == ipcsvc_share_rx_g->size  )
        {
#if defined(__IPCMSG_DEBUG_TRACE__)
            kal_buffer_trace(TRACE_INFO, TR_BUFFER_TRACE, sizeof(md_local_para_str), (const kal_uint8 *)ipc_local_para_str);
            kal_buffer_trace(TRACE_INFO, TR_BUFFER_TRACE, 4, (const kal_uint8 *)&(ipcsvc_share_rx_g->rx_offset));
            kal_buffer_trace(TRACE_INFO, TR_BUFFER_TRACE, pl_para_header->msg_len, (const kal_uint8 *)temp_ipc_ilm->local_para_ptr);
#endif
            kal_mem_cpy((kal_uint8 *)local_param, (kal_uint8 *)temp_ipc_ilm->local_para_ptr, pl_para_header->msg_len);
            ipcsvc_share_rx_g->rx_offset = 0;
        }
        else if (ipcsvc_share_rx_g->rx_offset + pl_para_header->msg_len <  ipcsvc_share_rx_g->size )
        {

#if defined(__IPCMSG_DEBUG_TRACE__)
            kal_buffer_trace(TRACE_INFO, TR_BUFFER_TRACE, sizeof(md_local_para_str), (const kal_uint8 *)ipc_local_para_str);
            kal_buffer_trace(TRACE_INFO, TR_BUFFER_TRACE, 4, (const kal_uint8 *)&(ipcsvc_share_rx_g->rx_offset));
            kal_buffer_trace(TRACE_INFO, TR_BUFFER_TRACE, pl_para_header->msg_len, (const kal_uint8 *)temp_ipc_ilm->local_para_ptr);
#endif

            kal_mem_cpy((kal_uint8 *)local_param, (kal_uint8 *)temp_ipc_ilm->local_para_ptr, pl_para_header->msg_len);
            ipcsvc_share_rx_g->rx_offset += pl_para_header->msg_len ;
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
                        pl_para_header->msg_len - (ipcsvc_share_rx_g->size - ipcsvc_share_rx_g->rx_offset));

            ipcsvc_share_rx_g->rx_offset = pl_para_header->msg_len - ((ipcsvc_share_rx_g->size) - ipcsvc_share_rx_g->rx_offset);
        }

#if defined(__IPCMSG_DEBUG_TRACE__)
        kal_buffer_trace(TRACE_INFO, TR_BUFFER_TRACE, sizeof(md_local_para_str), (const kal_uint8 *)md_local_para_str);
        kal_buffer_trace(TRACE_INFO, TR_BUFFER_TRACE, pl_para_header->msg_len, (const kal_uint8 *)local_param);
#endif
    }

    /* allocate the memoy space for peer_buff usage */
    if (temp_ipc_ilm->peer_buff_ptr)
    {
        leftSize = ipcsvc_share_rx_g->size - ipcsvc_share_rx_g->rx_offset;
        
        if (leftSize >= sizeof(peer_buff_struct))
        {
            pPeer_header = temp_ipc_ilm->peer_buff_ptr;
        }
        else
        {
            kal_mem_cpy((kal_uint8*)(&peer_header), (kal_uint8*)temp_ipc_ilm->peer_buff_ptr, leftSize);
            kal_mem_cpy((kal_uint8*)(&peer_header) + leftSize, (kal_uint8*)&(ipcsvc_share_rx_g->buffer), sizeof(peer_buff_struct) - leftSize);
            pPeer_header = &peer_header;
        }

        if ((kal_uint32)temp_ipc_ilm->peer_buff_ptr != ((kal_uint32)&(ipcsvc_share_rx_g->buffer) + ipcsvc_share_rx_g->rx_offset))
        {
            ASSERT(0);
        }

        if (1 != pPeer_header->ref_count)
        {
            ASSERT(0);
        }

        peer_buff = construct_peer_buff( pPeer_header->pdu_len, \
                                         pPeer_header->free_header_space, \
                                         pPeer_header->free_tail_space, 1);

        if (ipcsvc_share_rx_g->rx_offset + pPeer_header->pdu_len == ipcsvc_share_rx_g->size)
        {

#if defined(__IPCMSG_DEBUG_TRACE__)
            kal_buffer_trace(TRACE_INFO, TR_BUFFER_TRACE, sizeof(ipc_peer_buff_str), (const kal_uint8 *)ipc_peer_buff_str);
            kal_buffer_trace(TRACE_INFO, TR_BUFFER_TRACE, 4, (const kal_uint8 *)&(ipcsvc_share_rx_g->rx_offset));
            kal_buffer_trace(TRACE_INFO, TR_BUFFER_TRACE, pPeer_header->pdu_len, (const kal_uint8 *)temp_ipc_ilm->peer_buff_ptr);
#endif

            kal_mem_cpy((kal_uint8 *)peer_buff,  (kal_uint8 *)temp_ipc_ilm->peer_buff_ptr, pPeer_header->pdu_len);
            ipcsvc_share_rx_g->rx_offset = 0;
        }
        else if (ipcsvc_share_rx_g->rx_offset + pPeer_header->pdu_len < ipcsvc_share_rx_g->size)
        {

#if defined(__IPCMSG_DEBUG_TRACE__)
            kal_buffer_trace(TRACE_INFO, TR_BUFFER_TRACE, sizeof(ipc_peer_buff_str), (const kal_uint8 *)ipc_peer_buff_str);
            kal_buffer_trace(TRACE_INFO, TR_BUFFER_TRACE, 4, (const kal_uint8 *)&(ipcsvc_share_rx_g->rx_offset));
            kal_buffer_trace(TRACE_INFO, TR_BUFFER_TRACE, pPeer_header->pdu_len, (const kal_uint8 *)temp_ipc_ilm->peer_buff_ptr);
#endif
            kal_mem_cpy((kal_uint8 *)peer_buff,  (kal_uint8 *)temp_ipc_ilm->peer_buff_ptr, pPeer_header->pdu_len);
            ipcsvc_share_rx_g->rx_offset += pPeer_header->pdu_len;
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
                        pPeer_header->pdu_len - (ipcsvc_share_rx_g->size - ipcsvc_share_rx_g->rx_offset));
            ipcsvc_share_rx_g->rx_offset = pPeer_header->pdu_len - ((ipcsvc_share_rx_g->size) - ipcsvc_share_rx_g->rx_offset);
        }


#if defined(__IPCMSG_DEBUG_TRACE__)
        kal_buffer_trace(TRACE_INFO, TR_BUFFER_TRACE, sizeof(md_peer_buff_str), (const kal_uint8 *)md_peer_buff_str);
        kal_buffer_trace(TRACE_INFO, TR_BUFFER_TRACE, pPeer_header->pdu_len, (const kal_uint8 *)peer_buff);
#endif
    }

    do
    {
        /* feedback to the sender the message is receive */
        ret = ccci_mailbox_write_with_reserved(ipc_msgsvc_ch.receive_ack_channel, IPC_MSGSVC_RVC_DONE, bufp->reserved);

        retry--;
    }
    while ((ret == CCCI_NO_PHY_CHANNEL) && (retry >= 0));

    if (ret == CCCI_NO_PHY_CHANNEL)
    {
        ccci_debug_phychan_full = 1;
        EXT_ASSERT(0, IPC_MSG_CCCI_ERROR_WRITE_NO_PHYSICAL_CHANNEL, (kal_uint32)ret, bufp->reserved);
    }
    else if (ret != CCCI_SUCCESS)
    {
        EXT_ASSERT(0, IPC_MSG_CCCI_ERROR_WRITE_INTERNAL_FAIL, (kal_uint32)ret, bufp->reserved);
    }

#if defined(__IPCMSG_DEBUG_TRACE__)
    kal_buffer_trace(TRACE_INFO, TR_BUFFER_TRACE, sizeof(md_msg_str), (const kal_uint8 *)md_msg_str);
    kal_buffer_trace(TRACE_INFO, TR_BUFFER_TRACE, sizeof(ilm_struct), (const kal_uint8 *)ilmp);
#endif

    CCCI_AP_MSG_TO_KAL_MSG(temp_ipc_ilm->msg_id, tmp_msg_id);

    msg_send6 (MOD_CCCI_HISR, ipc_msgsvc_maptbl[i].task_id, temp_ipc_ilm->sap_id, tmp_msg_id, local_param, peer_buff);     
    return;
}


/*************************************************************************
* FUNCTION
*  ipc_msgsvc_sendmsg_cb
*
* DESCRIPTION
*  Callback function of send message
*
* PARAMETERS
*  none
*
* RETURNS
*  none
*
*************************************************************************/
void ipc_msgsvc_sendmsg_cb(CCCI_BUFF_T *bufp)
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

    if (i == MAX_IPC_MSGSVC_TASKS)
    {
        EXT_ASSERT(0, IPC_MSG_CCCI_ERROR_TXCB_ID_MISMATCH, (kal_uint32)i, bufp->reserved);
    }

    kal_set_eg_events(ipc_msgsvc_ch.event,  (1 << i) , KAL_OR);
    return;
}

/*************************************************************************
* FUNCTION
*  ipc_msgsvc_allocate_ilm
*
* DESCRIPTION
*  Legacy mode for allocate ilm from user's request
*
* PARAMETERS
*  none
*
* RETURNS
*  none
*
*************************************************************************/
ipc_ilm_t* ipc_msgsvc_allocate_ilm(module_type module_id)
{
    kal_uint32 i=0;
    ipc_ilm_t* ptr_ilm = NULL;

    for (i = 0 ; i < MAX_IPC_MSGSVC_TASKS; i++)
    {
        if (module_id == ipc_msgsvc_maptbl[i].task_id)
        {
#if defined(CCCI_INIT_HANDSHAKE_MODE1)
            ptr_ilm = (ipc_ilm_t*)(ap_md_share_data.IPCMDIlmShareMemBase);
            ptr_ilm = ptr_ilm + i;
#else
            ptr_ilm = &ipc_ilm_arr[i];
#endif
        }

    }

    return ptr_ilm;
}



/*************************************************************************
* FUNCTION
*  ipc_msgsvc_send_ext_queue
*
* DESCRIPTION
*  Send message to Queue
*
* PARAMETERS
*  none
*
* RETURNS
*  none
*
*************************************************************************/
kal_bool ipc_msgsvc_send_ext_queue(ipc_ilm_t*ipc_ilm_t_ptr)
{
    return ipc_msgsvc_sendmsg((kal_uint32)(ipc_ilm_t_ptr->dest_mod_id), (void *)(ipc_ilm_t_ptr), (kal_uint16)sizeof(ipc_ilm_t),  KAL_INFINITE_WAIT, KAL_FALSE);


}

/*************************************************************************
* FUNCTION
*  ipc_msgsvc_sendmsg
*
* DESCRIPTION
*  Send message
*
* PARAMETERS
*  none
*
* RETURNS
*  none
*
*************************************************************************/
kal_bool ipc_msgsvc_sendmsg(kal_uint32 ipc_task_id, void *buffer_ptr, kal_uint16 msg_size,  kal_wait_mode wait_mode, kal_bool message_to_head)
{
    kal_uint32	i, j ;
    kal_uint32	retrieved_events = 0, orig_local_addr = 0 , orig_peer_addr = 0, orig_tx_offset, used_len = 0;
    kal_int32	result = CCCI_SUCCESS;
    kal_int32	retry = IPC_MSG_MAX_RETRY;
    kal_bool	ret;
    ipc_ilm_t   *temp_ipc_ilm = NULL;

    local_para_struct    *tmp_local_para_ptr = NULL;
    peer_buff_struct     *tmp_peer_buff_ptr = NULL;



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
        EXT_ASSERT(0, IPC_MSG_CCCI_ERROR_SEND_ID_MISMATCH, ipc_task_id, temp_ipc_ilm->src_mod_id);
    }

    /* Use critical section to protect ENTER */
    IPC_MSGSVC_ENTER_CRITICAL_SECTION

    temp_ipc_ilm->src_mod_id =  ipc_msgsvc_maptbl[j].extq_id;

    /* Check if peer buff and local parameter exist and store to writer share buffer */
    orig_tx_offset	= ipcsvc_share_tx_g->tx_offset;
    if (temp_ipc_ilm->local_para_ptr != NULL)
    {
        if (1 != temp_ipc_ilm->local_para_ptr->ref_count)
        {
            ASSERT(0);
        }

        /* Max length: ipcsvc_share_tx_g->size - 1. Spare 1 byte to handle wrap condition */
        used_len = temp_ipc_ilm->local_para_ptr->msg_len;        
        if ( used_len >= ipcsvc_share_tx_g->size )
        {
            ASSERT(0);
        }

        orig_local_addr	= (kal_uint32)((kal_uint8 *)&ipcsvc_share_tx_g->buffer + ipcsvc_share_tx_g->tx_offset);

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
        //- free_local_para(temp_ipc_ilm->local_para_ptr); //- free iff send msg success
        tmp_local_para_ptr = temp_ipc_ilm->local_para_ptr;
        temp_ipc_ilm->local_para_ptr = (local_para_struct *)orig_local_addr;

    }





    if (temp_ipc_ilm->peer_buff_ptr != NULL)
    {

        if (1 != temp_ipc_ilm->peer_buff_ptr->ref_count)
        {
            ASSERT(0);
        }

        /* Max length: ipcsvc_share_tx_g->size - 1. Spare 1 byte to handle wrap condition */
        used_len += temp_ipc_ilm->peer_buff_ptr->pdu_len;
        if ( used_len >= ipcsvc_share_tx_g->size )
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
        //- free_peer_buff(temp_ipc_ilm->peer_buff_ptr);//- free iff send msg success
        tmp_peer_buff_ptr = temp_ipc_ilm->peer_buff_ptr;
        temp_ipc_ilm->peer_buff_ptr = (peer_buff_struct *)orig_peer_addr;

    }

    CCCI_KAL_MSG_TO_AP_MSG(temp_ipc_ilm->msg_id, temp_ipc_ilm->msg_id);

    if (KAL_INFINITE_WAIT != wait_mode)
    {
        retry = 1;
    }
    do
    {
        result = ccci_stream_write_with_reserved(ipc_msgsvc_ch.send_channel, (kal_uint32)buffer_ptr, msg_size ,ipc_msgsvc_maptbl[i].extq_id);

        if (wait_mode != KAL_INFINITE_WAIT)
            retry--;
    }
    while ((result != CCCI_SUCCESS) && (retry >= 0));

    if (result == CCCI_SUCCESS)
    {
        if (tmp_local_para_ptr)	free_local_para (tmp_local_para_ptr);
        if (tmp_peer_buff_ptr)	free_peer_buff	(tmp_peer_buff_ptr);

        //- Wait for feedabck by retrieve event
        kal_retrieve_eg_events(ipc_msgsvc_ch.event, 1 << i, KAL_AND_CONSUME,  &retrieved_events, KAL_SUSPEND);
        ret = KAL_TRUE;
    }
    else
    {
        //- ret != CCCI_SUCCESS
        {
            if (tmp_local_para_ptr)
            {
                temp_ipc_ilm->local_para_ptr = tmp_local_para_ptr;
                ipcsvc_share_tx_g->tx_offset = orig_tx_offset;
            }

            if (tmp_peer_buff_ptr)
            {
                temp_ipc_ilm->peer_buff_ptr = tmp_peer_buff_ptr;
            }
        }
        ret = KAL_FALSE;
    }


    /* Exit critical section */
    IPC_MSGSVC_EXIT_CRITICAL_SECTION

    /* Finish */
    return ret;
}


/*************************************************************************
* FUNCTION
*  ipc_msgsvc_receive_msg_ext_q
*
* DESCRIPTION
*  Empty function
*
* PARAMETERS
*  none
*
* RETURNS
*  none
*
*************************************************************************/
kal_bool ipc_msgsvc_receive_msg_ext_q(kal_msgqid task_ext_qid, ilm_struct *ilm_ptr)
{
    /* This function is useless because we will send the message directly to the task's queue */
    return KAL_TRUE;
}




/*************************************************************************
* FUNCTION
*  ipc_msgsvc_receivemsg
*
* DESCRIPTION
*  Empty function
*
* PARAMETERS
*  none
*
* RETURNS
*  none
*
*************************************************************************/
void ipc_msgsvc_receivemsg(kal_uint32 ipc_task_id, void *buffer_ptr, kal_uint16 msg_size,  kal_wait_mode wait_mode, kal_bool message_to_head)
{
    /* This function is useless because we will send the message directly to the task's queue */
}

/*************************************************************************
* FUNCTION
*  ipc_msgsvc_init
*
* DESCRIPTION
*  Initialize message service
*
* PARAMETERS
*  none
*
* RETURNS
*  none
*
*************************************************************************/

void ipc_msgsvc_init(void)
{



    //Send message does not need callback
    ccci_init(ipc_msgsvc_ch.send_channel , ipc_svc_errcb );
    //send mesage ack need to implement callback
    ccci_init(ipc_msgsvc_ch.send_ack_channel , ipc_msgsvc_sendmsg_cb);
    //Receive mesage need to implement callback
    ccci_init(ipc_msgsvc_ch.receive_channel , ipc_msgsvc_rcvmsg_hisr);
    //Receive mesage ack does not need to implement callback
    ccci_init(ipc_msgsvc_ch.receive_ack_channel , ipc_svc_errcb);
    //Initialize the event for usage
    ipc_msgsvc_ch.event = kal_create_event_group("IPC_MSGSVC");
    //Initialize the semaphore for critical section
    ipc_msgsvc_ch.semaphore = kal_create_sem("IPC_MSGSVC",1);


}


/*************************************************************************
* FUNCTION
*  ipc_msgsvc_test
*
* DESCRIPTION
*  Test function of message service
*
* PARAMETERS
*  none
*
* RETURNS
*  none
*
*************************************************************************/
void ipc_msgsvc_test(void)
{


#ifdef MTK_SYSSERV_DEBUG

    EXT_ASSERT(0, 0, 0, 0);

#endif /*  MTK_SYSSERV_DEBUG */

}

#endif /* __MODEM_CCCI_EXIST__ */
