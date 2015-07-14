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
 *   ipc_msgsvc.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Header file of message driver of CCCI.
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

#ifndef __IPC_MSGSVC_H__
#define __IPC_MSGSVC_H__

#include "ipc_msgsvc_msgid.h"

/*******************************************************************************
 * Define constants.
 *******************************************************************************/
#define IPC_MSGSVC_RVC_DONE 0x12344321

#ifdef __GEMINI__
#define MAX_NUM_IPC_TASKS   (3 + GEMINI_PLUS)
#else
#define MAX_NUM_IPC_TASKS   (3 + 1)
#endif

#define IPC_MSG_MAX_RETRY 	0xFFFF

/* define AP side virtual module id as destination */
#define APMOD_AGPS          0x0401
#define APMOD_DHCP          0x0402
#define APMOD_GPS           0x0403

#define CCCI_IPC_VALID_MSG_ID_MASK    0xFF
#define CCCI_IPC_TO_AP_MSG_START      (0x80000000)
#define CCCI_IPC_TO_KAL_MSG_START     (IPC_MSG_ID_INVALID_TYPE)

#if !defined(__SDIO_DEVICE_CONNECTIVITY__)
/*******************************************************************************
 * Define data structures.
 *******************************************************************************/
/* Struct to define the control channel of IPC msg service */
typedef struct IPC_MSGSVC_STRUCT
{
    kal_uint32 send_channel;            /* IPC channel for TX */
    kal_uint32 send_ack_channel;        /* IPC channel for TX ACK */
    kal_uint32 receive_channel;         /* IPC channel for RX */
    kal_uint32 receive_ack_channel;   	/* IPC channel for RX ACK */
    kal_eventgrpid event;               /* notify event */
    kal_semid semaphore;                /* Use to protect critical section */

} IPC_MSGSVC_T;

/* Struct to define the mapping between task and external label */
typedef struct IPC_MSGSVC_TASKMAP_STRUCT
{
    kal_uint32  extq_id;            /* IPC universal mapping external queue */
    kal_uint32  task_id;            /* IPC processor internal task id */

} IPC_MSGSVC_TASKMAP_T;

/* Struct to define the communication ilm between two cores */
typedef struct ipc_ilm_struct
{
    kal_uint32           src_mod_id;
    kal_uint32           dest_mod_id;
    kal_uint32           sap_id;
    kal_uint32           msg_id;
    local_para_struct    *local_para_ptr;
    peer_buff_struct     *peer_buff_ptr;
} ipc_ilm_t;


/* struct to share ipc */
typedef struct IPC_ST
{
    kal_uint32 rx_offset;
    kal_uint32 tx_offset;
    kal_uint32 size;
    kal_uint8 *buffer;
} Ipcsvc_Share_ST;


/*******************************************************************************
 * Define macros.
 *******************************************************************************/
#define CCCI_AP_MSG_TO_KAL_MSG(ap_msg_id, kal_msg_id)    do { \
        kal_msg_id = (ap_msg_id & CCCI_IPC_VALID_MSG_ID_MASK) | CCCI_IPC_TO_KAL_MSG_START; \
    } while(0)

#define CCCI_KAL_MSG_TO_AP_MSG(kal_msg_id, ap_msg_id)    do { \
        ap_msg_id = (kal_msg_id & CCCI_IPC_VALID_MSG_ID_MASK) | CCCI_IPC_TO_AP_MSG_START; \
    } while(0)



/*******************************************************************************
 * Define export variables.
 *******************************************************************************/



/*******************************************************************************
 * Define export function.
 *******************************************************************************/
extern ipc_ilm_t* ipc_msgsvc_allocate_ilm(module_type module_id);
extern kal_bool ipc_msgsvc_send_ext_queue(ipc_ilm_t*ipc_ilm_t_ptr);
extern void ipc_msgsvc_init(void);























#else //- __SDIO_DEVICE_CONNECTIVITY__
#include "ccci.h"

/*******************************************************************************
 * Define constants.
 *******************************************************************************/
#define PUBLIC

#define PRIVATE

/*******************************************************************************
 * Define data structures.
 *******************************************************************************/
/* Struct to define the control channel of IPC msg service */
typedef struct IPC_MSGSVC_STRUCT
{
    kal_uint32 send_channel;            /* IPC channel for TX */
    kal_uint32 send_ack_channel;        /* IPC channel for TX ACK */
    kal_uint32 receive_channel;         /* IPC channel for RX */
    kal_uint32 receive_ack_channel;   	/* IPC channel for RX ACK */
    kal_eventgrpid event;               /* notify event */
    kal_semid semaphore;                /* Use to protect critical section */

} IPC_MSGSVC_T;

/* Struct to define the mapping between task and external label */
typedef struct IPC_MSGSVC_TASKMAP_STRUCT
{
    kal_uint32  extq_id;            /* IPC universal mapping external queue */
    kal_uint32  task_id;            /* IPC processor internal task id */

} IPC_MSGSVC_TASKMAP_T;

/* Struct to define the communication ilm between two cores */
typedef struct ipc_ilm_struct
{
    kal_uint32           src_mod_id;
    kal_uint32           dest_mod_id;
    kal_uint32           sap_id;
    kal_uint32           msg_id;
    local_para_struct    *local_para_ptr;
    peer_buff_struct     *peer_buff_ptr;
} ipc_ilm_t;


/* struct to share ipc */
typedef struct IPC_ST
{
    kal_uint32 rx_offset;
    kal_uint32 tx_offset;
    kal_uint32 size;
    //========================================================================
    //|CCCI header | ilm structure  | local_para_struct | local buffer | peer _buff_struct|peer buffer |
    //|    16 bytes  |      24 bytes  |               msg_len                  |              pdu_len                 |
    //========================================================================
    kal_uint8 *buffer;
} Ipcsvc_Share_ST;


/*******************************************************************************
 * Define macros.
 *******************************************************************************/



/*******************************************************************************
 * Define export variables.
 *******************************************************************************/
extern PUBLIC Ipcsvc_Share_ST *ipcsvc_share_rx_g;
extern PUBLIC Ipcsvc_Share_ST *ipcsvc_share_tx_g;

/*******************************************************************************
 * Define export function.
 *******************************************************************************/
PRIVATE void ipc_svc_errcb(CCCI_BUFF_T *bufp);
PRIVATE void ipc_msgsvc_rcvmsg_hisr(CCCI_BUFF_T *bufp);
PRIVATE void ipc_msgsvc_sendmsg_cb(CCCI_BUFF_T *bufp);
PUBLIC ipc_ilm_t* ipc_msgsvc_allocate_ilm(module_type module_id);
PUBLIC kal_bool ipc_msgsvc_send_ext_queue(ipc_ilm_t*ipc_ilm_t_ptr);
PRIVATE kal_bool ipc_msgsvc_sendmsg(kal_uint32 ipc_task_id, void *buffer_ptr, kal_uint16 msg_size,	kal_wait_mode wait_mode, kal_bool message_to_head);
PUBLIC kal_bool ipc_msgsvc_receive_msg_ext_q(kal_msgqid task_ext_qid, ilm_struct *ilm_ptr);
PUBLIC void ipc_msgsvc_receivemsg(kal_uint32 ipc_task_id, void *buffer_ptr, kal_uint16 msg_size,  kal_wait_mode wait_mode, kal_bool message_to_head);
PUBLIC void ipc_msgsvc_init(void);
#endif //#if !defined(__SDIO_DEVICE_CONNECTIVITY__)
#endif  /* !__IPC_MSGSVC_H__ */


