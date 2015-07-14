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
 *   ccci_uart_drv.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This function implements UART drivers of CCCI .
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
 * removed!
 *
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
#if defined(__MODEM_CCCI_EXIST__)

#include "kal_public_api.h"
#include "kal_trace.h"
#include "tst_trace.h"

#include "ccci.h"
#include "ccci_int.h"
#include "intrCtrl.h"
#include "drv_comm.h"
#include "drv_hisr.h"
#include "uart_sw.h"
#include "dcl.h"
#include "ccci_uart_drv.h"

#include "us_timer.h"

#ifdef CCCI_UART_GIO
#define __CCCI_DEBUG_INFO__
#endif //- CCCI_UART_GIO

#include "drv_msgid.h"
#include "ccif.h"

extern void tst_sys_trace(kal_char *);
extern MODEM_RUNTIME_DATA ap_md_share_data;
extern void UART_DriverInit(UART_PORT port,kal_uint32 flag);
extern kal_bool INT_QueryExceptionStatus(void);
/********************************************************************************
 * Define import global variables.
 ********************************************************************************/
#ifdef __MTK_TARGET__
extern kal_uint8 INT_Exception_Enter ;
#endif
extern kal_bool  ccci_debug_phychan_full;
/*******************************************************************************
 * Define import function prototype.
 *******************************************************************************/


/*******************************************************************************
 * Define global variables.
 *******************************************************************************/
kal_uint8 data_for_putuartbyte;

static CCCI_UARTP_T ccci_uart_port[MAX_CCCI_UART_PORT] =
{
    /* The first two ports are from MD view, the third one is from AP view */
    { CCCI_TST_CHANNEL, CCCI_TST_ACK_CHANNEL, CCCI_TR_CHANNEL, CCCI_TR_ACK_CHANNEL, 0, 0, 0 /* write_flag */,  MOD_NIL, MOD_NIL }
    ,{ CCCI_AT_CHANNEL_TX, CCCI_AT_ACK_CHANNEL_TX, CCCI_AT_CHANNEL_RX, CCCI_AT_ACK_CHANNEL_RX, 0, 0,0 /* write_flag */, MOD_NIL, MOD_NIL }
    ,{ CCCI_CCMNI1_RX, CCCI_CCMNI1_RX_ACK, CCCI_CCMNI1_TX, CCCI_CCMNI1_TX_ACK, 0, 0,0 /* write_flag */, MOD_NIL, MOD_NIL }
    ,{ CCCI_CCMNI2_RX, CCCI_CCMNI2_RX_ACK, CCCI_CCMNI2_TX, CCCI_CCMNI2_TX_ACK, 0, 0,0 /* write_flag */, MOD_NIL, MOD_NIL }
    ,{ CCCI_CCMNI3_RX, CCCI_CCMNI3_RX_ACK, CCCI_CCMNI3_TX, CCCI_CCMNI3_TX_ACK, 0, 0,0 /* write_flag */, MOD_NIL, MOD_NIL }
    ,{ CCCI_GPS_CHANNEL_TX, CCCI_GPS_ACK_CHANNEL_TX, CCCI_GPS_CHANNEL_RX, CCCI_GPS_ACK_CHANNEL_RX, 0, 0,0 /* write_flag */, MOD_NIL, MOD_NIL }
};

CCCI_UARTP_BUFF_T ccci_uartp_buff[MAX_CCCI_UART_PORT];

static DCL_STATUS     CCCI_UART_Handler(DCL_DEV dev,DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);
Seriport_HANDLER_T    CCCI_Uart_Drv_Handler = {DCL_UART_CCCI_TYPE, CCCI_UART_Handler};

//- Pupa disable for debug :20120217
//-#define __CCCI_DEBUG_ATCMD_ERROR___
//- Pupa end

//- Pupa add for debug :20120209
#ifdef __CCCI_DEBUG_ATCMD_ERROR___
#ifdef  __CCCI_DEBUG_ATCMD_ERROR_BUFFER_DEBUG__
#error  "redefine __CCCI_DEBUG_ATCMD_ERROR_BUFFER_DEBUG__"
#endif
//#define __CCCI_DEBUG_ATCMD_ERROR_BUFFER_DEBUG__
#ifdef    __CCCI_DEBUG_ATCMD_MISMATCH__
#define CCCI_DEBUG_MEMDUMP_SIZE    2048
#undef     CCCI_UARTB_POP_MULTI
#define CCCI_UARTB_POP_MULTI(uartb, bufaddr, output_addr, length)  \
        do {    \
            CCCI_UARTB_T *uartbp = (uartb); \
            if ( length <= (uartbp->len - 1) - uartbp->read + 1) \
            { \
                kal_mem_cpy((kal_uint8 *)output_addr , (kal_uint8 *)(bufaddr) + uartbp->read , length); \
                kal_mem_cpy(((kal_uint8 *)&g_CCCI_Debug_Memdump.offset[0]+ g_CCCI_Debug_Memdump.offset) , (kal_uint8 *)(bufaddr) + uartbp->read , length); \
                if (length == (uartbp->len - 1) - uartbp->read + 1) \
                { \
                    (uartbp->read)= 0; \
                } \
                else \
                { \
                    (uartbp->read) += length; \
                } \
                length = 0; \
                g_CCCI_Debug_Memdump.offset = (g_CCCI_Debug_Memdump.offset + length) % CCCI_DEBUG_MEMDUMP_SIZE;\
            } \
            else \
            { \
                kal_uint32 tmp;\
                tmp = (uartbp->len - 1) - uartbp->read + 1;\
                kal_mem_cpy((kal_uint8 *)output_addr , (kal_uint8 *)(bufaddr) + uartbp->read , tmp); \
                kal_mem_cpy(((kal_uint8 *)&g_CCCI_Debug_Memdump.offset[0]+ g_CCCI_Debug_Memdump.offset) , (kal_uint8 *)(bufaddr) + uartbp->read , tmp); \
                (kal_uint8 *)output_addr += tmp; \
               g_CCCI_Debug_Memdump.offset = (g_CCCI_Debug_Memdump.offset + tmp) % CCCI_DEBUG_MEMDUMP_SIZE;\
                tmp = length - ((uartbp->len - 1) - uartbp->read + 1); \
                kal_mem_cpy((kal_uint8 *)output_addr , (kal_uint8 *)(bufaddr) , tmp); \
                kal_mem_cpy(((kal_uint8 *)&g_CCCI_Debug_Memdump.offset[0]+ g_CCCI_Debug_Memdump.offset) , (kal_uint8 *)(bufaddr) , tmp); \
                uartbp->read = tmp ; \
                g_CCCI_Debug_Memdump.offset = (g_CCCI_Debug_Memdump.offset + tmp) % CCCI_DEBUG_MEMDUMP_SIZE;\
                length = 0; \
            } \
         } while (0)

typedef struct
{
    kal_uint32     offset;
    kal_uint32    buffer[CCCI_DEBUG_MEMDUMP_SIZE];
} CCCI_DEBUG_MEMDUMP_T;
CCCI_DEBUG_MEMDUMP_T    g_CCCI_Debug_Memdump;
#endif    //- __CCCI_DEBUG_ATCMD_ERROR_BUFFER_DEBUG__
#endif    //- __CCCI_DEBUG_ATCMD_ERROR___
//- Pupa end

#ifdef CCCI_UART_GIO

typedef struct CCCI_UART_GIO_CTLBLK
{
    kal_uint32 gio_port_mask;
} CCCI_UART_GIO_CTLBLK_T;


CCCI_UART_GIO_CTLBLK_T        ccci_uart_gio_ctlblk;
CCCI_GIOPDU_CTLBLK_T        ccci_giopdu_ctlblk[MAX_CCCI_GIOPDU_PORT];
CCCI_GIOPDU_FLOWCTL_T        ccci_giopdu_flowctl;

kal_uint8     ccci_ap_md_net_ULRingQ_mismatch = 0;
kal_uint8     ccci_ap_md_net_DLRingQ_mismatch = 0;

const kal_uint32             ccci_gioport_2_uartport[MAX_CCCI_GIOPDU_PORT] = {uart_port_ccmni1_ccci-FIRST_CCCI_UART_PORT,
        uart_port_ccmni2_ccci-FIRST_CCCI_UART_PORT,
        uart_port_ccmni3_ccci-FIRST_CCCI_UART_PORT
                                                                             };

kal_int32 ccci_uart_gio_tx_go_BCE (kal_uint32 gio_port, kal_uint32 entry);

#define CCCI_GIOPDU_RX_PRELOAD_THRESHOLD(gIOPORT)            (ccci_giopdu_ctlblk[gIOPORT].rx_ringQ_threshold)

#define CCCI_GIOPDU_GIO_ENABLE_TXMAXGPD2BCE(gIOPORT)        (ccci_giopdu_ctlblk[gIOPORT].option & 0x000000FF)            //- CCCI_GIOPDU_ENABLE_TX_MAX_GPD2BCE
#define CCCI_GIOPDU_GIO_ENABLE_RXMAXPRELOAD(gIOPORT)        ((ccci_giopdu_ctlblk[gIOPORT].option & 0x0000FF00) >> 8);    //- CCCI_GIOPDU_ENABLE_RX_MAX_PRELOAD_MASK
#define CCCI_GIOPDU_GIO_ENABLE_TXBCEKICKBACK(gIOPORT)        (ccci_giopdu_ctlblk[gIOPORT].option & 0x40000000)            //- CCCI_GIOPDU_ENABLE_TX_BCE_KICKBACK_MASK
#define CCCI_GIOPDU_GIO_ENABLE_TXMERGERECYCLE(gIOPORT)        (ccci_giopdu_ctlblk[gIOPORT].option & 0x80000000)            //- CCCI_GIOPDU_ENABLE_RX_MERGE_RECYCLE_MASK


#ifdef    CCCI_GIOPDU_UPLINK_FLC_FLOWCTL
#ifdef CCCI_GIOPDU_UPLINK_PLANB_FLOWCTL
#define ccci_uart_gio_rx_load_gpd    ccci_uart_gio_rx_load_gpd_X
#else
#define ccci_uart_gio_rx_load_gpd    ccci_uart_gio_rx_load_gpd_XB
#endif
#define ccci_uart_gio_rx_recv_data    ccci_uart_gio_rx_recv_data_X

#endif
#ifdef CCCI_GIOPDU_UPLINK_CCCI_FLOWCTL
#define ccci_uart_gio_rx_load_gpd    ccci_uart_gio_rx_load_gpd_0
#define ccci_uart_gio_rx_recv_data    ccci_uart_gio_rx_recv_data_0
#endif

#define CCCI_GIOPDU_ASSERT()        EXT_ASSERT(0, 0, 0, 0)

#ifdef CCCI_UART_GIO_IT
kal_timerid ccci_uart_gio_it_timer;
#endif

kal_bool CCCI_GIOPDU_TimerCB_in = 0;
kal_bool CCCI_GIOPDU_CCIFCB_in = 0;

kal_uint32 ccci_uart_gio_task_send_retry = 0;

#ifdef CCCI_GIOPDU_DEBUG_TRACE
kal_uint8 ccci_giopdu_err_string[6][32] = {    "CCCI_GIOPDU_NO_ERR",
        "CCCI_GIOPDU_RINGQ_NO_SPACE",
        "CCCI_GIOPDU_RINGQ_LOCKED",
        "CCCI_GIOPDU_LINK_LOCK",
        "CCCI_GIOPDU_BCE_LOCK",
        "CCCI_GIOPDU_NO_PENDING_GPD"
                                          };
kal_uint8 ccci_giopdu_entry_string[4][8] = { "TASK", "BCE", "NULL", "CCIF"};
#define ___CCCI_UART_GIO_TRACE(...)        kal_prompt_trace(__VA_ARGS__)
#else
#define ___CCCI_UART_GIO_TRACE(...)
#endif
void ccci_uart_gio_rx_partition (void);
#endif //- CCCI_UART_GIO


/*************************************************************************
* FUNCTION
*  ccci_uart_send_message_to_ap_retry
*
* DESCRIPTION
*
*
* PARAMETERS
*  none
*
* RETURNS
*  none
*
*************************************************************************/
static kal_int32 ccci_uart_send_message_to_ap_retry(kal_uint32 port, kal_uint32 channel, kal_uint32 retry_us)
{
    CCCI_BUFF_T  buff;
    kal_int32    ret;
    kal_uint32   start_time, end_time;

    //- send ccif message
    CCCI_INIT_MAILBOX(&buff, 0);
    buff.reserved = port;

    start_time = ust_get_current_time();
    while (1) 
    {
        ret = ccci_write(channel, &buff);
        if ( CCCI_NO_PHY_CHANNEL == ret )
        {
            end_time = ust_get_current_time();
            if ( ust_get_duration(start_time, end_time) > retry_us )
            {
                ccci_debug_phychan_full = 1;
                EXT_ASSERT(0, UART_CCCI_ERROR_WRITE_NO_PHYSICAL_CHANNEL, 0, 0);
            }
        }
        //- success, or none physical channel full case
        else
        {
            break;
        }
    } while( CCCI_NO_PHY_CHANNEL == ret );

    if ( CCCI_SUCCESS != ret )
    {
        EXT_ASSERT(0, ret, 0, 0);
    }

    return ret;
}


#if defined(CCCI_UART_GIO)
const kal_uint32    ccci_uart_to_user_meaasge[2][MAX_CCCI_UART_PORT] = {{
        MSG_ID_UART_READY_TO_READ_IND, MSG_ID_UART_READY_TO_READ_IND, MSG_ID_UPS1_READY_TO_READ_IND,
        MSG_ID_UPS2_READY_TO_READ_IND, MSG_ID_UPS3_READY_TO_READ_IND, MSG_ID_UART_READY_TO_READ_IND
    },
    {
        MSG_ID_UART_READY_TO_WRITE_IND, MSG_ID_UART_READY_TO_WRITE_IND, MSG_ID_UPS1_READY_TO_WRITE_IND,
        MSG_ID_UPS2_READY_TO_WRITE_IND, MSG_ID_UPS3_READY_TO_WRITE_IND, MSG_ID_UART_READY_TO_WRITE_IND
    }
};
#else
const kal_uint32    ccci_uart_to_user_meaasge[2][MAX_CCCI_UART_PORT] = {{
        MSG_ID_UART_READY_TO_READ_IND, MSG_ID_UART_READY_TO_READ_IND, MSG_ID_UART_READY_TO_READ_IND,
        MSG_ID_UART_READY_TO_READ_IND, MSG_ID_UART_READY_TO_READ_IND, MSG_ID_UART_READY_TO_READ_IND
    },
    {
        MSG_ID_UART_READY_TO_WRITE_IND, MSG_ID_UART_READY_TO_WRITE_IND, MSG_ID_UART_READY_TO_WRITE_IND,
        MSG_ID_UART_READY_TO_WRITE_IND, MSG_ID_UART_READY_TO_WRITE_IND, MSG_ID_UART_READY_TO_WRITE_IND
    }
};

#endif
/*************************************************************************
* FUNCTION
*  ccci_uart_send_message_to_user
*
* DESCRIPTION
*
*
* PARAMETERS
*  none
*
* RETURNS
*  none
*
*************************************************************************/
static void ccci_uart_send_message_to_user(kal_uint32 port, kal_uint32 isTx, kal_uint32 owner)
{
    kal_bool    need_localpara = 1;

    uart_ready_to_write_ind_struct    *local_para; //- uart_ready_to_write_ind_struct is similar as uart_ready_to_read_ind_struct

#if defined(CCCI_UART_GIO)
    if ((1 << port) & CCCI_UART_CCMNI_PORT_MASK)
    {
        need_localpara = 0;
    }
#endif

    if (need_localpara)
    {
        local_para = (uart_ready_to_write_ind_struct *) construct_local_para (sizeof(uart_ready_to_write_ind_struct), TD_RESET);
        local_para->port = FIRST_CCCI_UART_PORT + port;

        msg_send5 (MOD_CCCI_HISR, owner, 0, ccci_uart_to_user_meaasge[isTx][port], (local_para_struct*)local_para);
    }
    else
    {
        msg_send4 (MOD_CCCI_HISR, owner, 0, ccci_uart_to_user_meaasge[isTx][port]);
    }
}

/*************************************************************************
* FUNCTION
*  ccci_uart_behave_nonblock
*
* DESCRIPTION
*  -
*
* PARAMETERS
*  none
*
* RETURNS
*  none
*
*************************************************************************/
static kal_bool ccci_uart_behave_nonblock(DCL_DEV port)
{
    port += FIRST_CCCI_UART_PORT;


    if (port >= uart_port_ccmni1_ccci && port <= uart_port_gps_ccci)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}


/*************************************************************************
* FUNCTION
*  ccci_uart_tx_callback
*
* DESCRIPTION
*  This function implements the CCCI callback function for TST drivers.
*
* PARAMETERS
*  none
*
* RETURNS
*  none
*
*************************************************************************/
static void ccci_uart_tx_callback(CCCI_BUFF_T *buff)
{
    ASSERT(0);
}


/*************************************************************************
* FUNCTION
*  ccci_uart_tx_ack_callback
*
* DESCRIPTION
*  This function implements the CCCI callback function for TST drivers.
*
* PARAMETERS
*  none
*
* RETURNS
*  none
*
*************************************************************************/
static void ccci_uart_tx_ack_callback(CCCI_BUFF_T *buff)
{
    kal_uint32 port;

#ifdef CCCI_UART_GIO
    kal_uint32    gio_port;
    kal_int32    ret = 0;
    kal_uint32    is_gio = 0;

    CCCI_GIOPDU_CCIFCB_in = 1;

    if (CCCI_GIOPDU_TimerCB_in)
        EXT_ASSERT (0, 0, 0, 0);
#endif

    /* get port number stored in the CCCI buffer */
    port = CCCI_MAILBOX_ID(buff);

#ifdef CCCI_UART_GIO
    is_gio = (1 << port) & CCCI_UART_CCMNI_PORT_MASK;
    if (is_gio)
    {
        ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] DL_CCIFcb In");
    }
#endif

    /* YuSu Owner would like to receive ready to write */
    if ( KAL_FALSE == ccci_uart_behave_nonblock(port))
    {
        /* set an event */
        kal_set_eg_events(ccci_uart_port[port].event, 1, KAL_OR);
    }
    else
    {
        if (ccci_uart_port[port].write_flag == 1)
        {
            ccci_uart_port[port].write_flag = 0;
            ccci_uart_send_message_to_user (port, 1, ccci_uart_port[port].tx_owner);
        }

#ifdef CCCI_UART_GIO
        //- kickback BCE if needed
        if (is_gio)
        {
#ifdef CCCI_CCIF_HISR_BCE_KICKBACK
            ret = ccci_uart_gio_tx_go_BCE (CCCI_GIOPDU_UNDESIGNATE_PORT, CCCI_GIOPDU_TX_GO_ENTRY_CCIF_HISR);
            gio_port = (port + FIRST_CCCI_UART_PORT) - FIRST_CCCI_CCMNI_PORT;
            if (ret)
            {
                ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] DL_CCIFcb%d : %s", gio_port, ccci_giopdu_err_string[0-ret]);
            }
#endif

            ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] DL_CCIFcb Out");
        }
#endif
    }

#ifdef CCCI_UART_GIO
    CCCI_GIOPDU_CCIFCB_in = 0;
#endif
}


/*************************************************************************
* FUNCTION
*  ccci_uart_rx_callback
*
* DESCRIPTION
*  This function implements the CCCI callback function for TST drivers.
*
* PARAMETERS
*  none
*
* RETURNS
*  none
*
*************************************************************************/
static void ccci_uart_rx_callback(CCCI_BUFF_T *buff)
{
    kal_uint32 i;

    /* get port number from logical channel */
    for (i = 0; i < MAX_CCCI_UART_PORT; i++)
    {
        if (ccci_uart_port[i].rx_channel == buff->channel)
        {
            break;
        }
    }
    if (i >= MAX_CCCI_UART_PORT)
    {
        EXT_ASSERT(0, i, buff->channel, 0);
    }

    if (ccci_uart_port[i].flag == 1)
    {
        ccci_uart_port[i].flag = 0;
        ccci_uart_send_message_to_user (i, 0, ccci_uart_port[i].rx_owner);
    }
}


/*************************************************************************
* FUNCTION
*  ccci_uart_rx_ack_callback
*
* DESCRIPTION
*  This function implements the CCCI callback function for TST drivers.
*
* PARAMETERS
*  none
*
* RETURNS
*  none
*
*************************************************************************/
static void ccci_uart_rx_ack_callback(CCCI_BUFF_T *buff)
{
    /* This should not be called by MD side */
    ASSERT(0);
}

/*************************************************************************
* FUNCTION
*  ccci_uart_buffer_invalid
*
* DESCRIPTION
*  This function checks whether a UART buffer is no allocated.
*
* PARAMETERS
*  port    -   CCCI UART port (not device port) (value: 0 ~ 5)
*
* RETURNS
*  KAL_TRUE  - AP allocates CCCI buffer for this UART port.
*  KAL_FALSE - AP doesn't allocate CCCI buffer for this UART port.
*
*************************************************************************/
static kal_uint32 ccci_uart_buffer_invalid(kal_uint32 port)
{
    ASSERT(port < ap_md_share_data.UartPortNum);
    
    if (ap_md_share_data.UartShareMemBase[port] == CCCI_UART_BUFF_INVALID_MARK || \
    	  ap_md_share_data.UartShareMemSize[port] == CCCI_UART_BUFF_INVALID_MARK)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}	

/*************************************************************************
* FUNCTION
*  ccci_uart_open
*
* DESCRIPTION
*  This function opens an UART driver port.
*
* PARAMETERS
*  port    -   no use
*  owner   -   no use
*
* RETURNS
*  KAL_TRUE for success
*  KAL_FALSE for failure
*
*************************************************************************/
static kal_bool ccci_uart_open(DCL_DEV port, module_type owner)
{
    kal_uint32 ret;

    if (port >= (FIRST_CCCI_UART_PORT + MAX_CCCI_UART_PORT))
    {
        return KAL_FALSE;
    }
    port -= FIRST_CCCI_UART_PORT;

    /* initialize CCCI channels for TX */
    ret = ccci_owner_init(ccci_uart_port[port].tx_channel, kal_get_task_by_moduleID(owner), ccci_uart_tx_callback);
    if (ret != CCCI_SUCCESS)
    {
        return KAL_FALSE;
    }
    ret = ccci_owner_init(ccci_uart_port[port].tx_ack_channel, kal_get_task_by_moduleID(owner), ccci_uart_tx_ack_callback);
    if (ret != CCCI_SUCCESS)
    {
        return KAL_FALSE;
    }

    /* save TX owner */
    ccci_uart_port[port].tx_owner = owner;
#ifdef MTK_SYSSERV_DEBUG
    if (owner == MOD_SSDBG1)
    {
        /* SSDBG2 handles RX */
        owner = MOD_SSDBG2;
    }
#endif

    /* intialize CCCI channels for RX */
    ret = ccci_owner_init(ccci_uart_port[port].rx_channel, kal_get_task_by_moduleID(owner), ccci_uart_rx_callback);
    if (ret != CCCI_SUCCESS)
    {
        return KAL_FALSE;
    }
    ret = ccci_owner_init(ccci_uart_port[port].rx_ack_channel, kal_get_task_by_moduleID(owner), ccci_uart_rx_ack_callback);
    if (ret != CCCI_SUCCESS)
    {
        return KAL_FALSE;
    }

    /* save RX owner */
    ccci_uart_port[port].rx_owner = owner;

    if (ccci_uart_buffer_invalid(port) == KAL_FALSE)
    {
        CCCI_UARTB_INIT(((ccci_uartp_buff[port]).tx),(ccci_uartp_buff[port].rx_buff-ccci_uartp_buff[port].tx_buff));
        CCCI_UARTB_INIT(((ccci_uartp_buff[port]).rx), (ccci_uartp_buff[port].rx_buff-ccci_uartp_buff[port].tx_buff));
    }

    /* initialize the nofify flag */
    ccci_uart_port[port].flag = 1;

    /* create an event */
    if (ccci_uart_port[port].event == NULL)
    {
        ccci_uart_port[port].event = kal_create_event_group("CCCIUART");
    }

    return KAL_TRUE;
}


/*************************************************************************
* FUNCTION
*  ccci_uart_close
*
* DESCRIPTION
*  This function closes the UART port.
*
* PARAMETERS
*  port   -  no use
*  owner  -  no use
*
* RETURNS
*  none
*
*************************************************************************/
static void ccci_uart_close(DCL_DEV port, module_type owner)
{
    if (port >= (FIRST_CCCI_UART_PORT + MAX_CCCI_UART_PORT))
    {
        ASSERT(0);
    }
    port -= FIRST_CCCI_UART_PORT;

    /* de-initialize the CCCI channels */
    ccci_deinit(ccci_uart_port[port].tx_channel);
    ccci_deinit(ccci_uart_port[port].tx_ack_channel);
    ccci_deinit(ccci_uart_port[port].rx_channel);
    ccci_deinit(ccci_uart_port[port].rx_ack_channel);

    /* clear ccci_uart_port[] */
    ccci_uart_port[port].flag = 0;
    ccci_uart_port[port].tx_owner = MOD_NIL;
    ccci_uart_port[port].rx_owner = MOD_NIL;
}


/*************************************************************************
* FUNCTION
*  ccci_uart_getbytes
*
* DESCRIPTION
*  This function reads data from the UART port.
*
* PARAMETERS
*  port       -   no use
*  Buffaddr   -   address of buffer to get
*  Length     -   buffer length
*  status     -   no use
*  ownerid    -   no use
*
* RETURNS
*  Number of bytes actually gotten
*
*************************************************************************/
static kal_uint16 ccci_uart_getbytes(DCL_DEV port, kal_uint8 *Buffaddr, kal_uint16 Length, kal_uint8 *status, module_type ownerid)
{
    kal_uint32 avail, cnt, mask;

    if (port >= (FIRST_CCCI_UART_PORT + MAX_CCCI_UART_PORT))
    {
        return KAL_FALSE;
    }
    port -= FIRST_CCCI_UART_PORT;

    if (ccci_uart_port[port].rx_owner != ownerid)
    {
        EXT_ASSERT(0, port + FIRST_CCCI_UART_PORT, ownerid, ccci_uart_port[port].rx_owner);
    }

    if (status != NULL)
    {
        *status = 0;
    }

    /* get number of bytes available in the buffer */
    mask = SaveAndSetIRQMask();
    CCCI_UARTB_GETAVAIL(((ccci_uartp_buff[port]).rx), avail);
    if (avail < Length)
    {
        /* cannot fit the required size; set the nofify flag */

        /*
         * NoteXXX: It is not necessary to use a mutex to protect flag access.
         *          This is because the flag is always be set in the task level
         *          and always be cleared in the HISR level.
         */

        ccci_uart_port[port].flag = 1;
    }
    RestoreIRQMask(mask);

    //- Pupa add for debug :20120209
#ifdef __CCCI_DEBUG_ATCMD_ERROR___
    if((port+FIRST_CCCI_UART_PORT) == uart_port_at_ccci)
    {
        kal_char debug_info[100];

        sprintf(debug_info, "CCCI Length=0x%X, avail=0x%X, RxR:0x%X, RxW:0x%X", Length, avail, (ccci_uartp_buff[port].rx)->read, (ccci_uartp_buff[port].rx)->write);
        tst_sys_trace(debug_info);
    }
#endif
    //- Pupa end

    if (avail != 0)
    {

        if (avail >= Length) //can output all
        {
            cnt = Length;
            CCCI_UARTB_POP_MULTI(((ccci_uartp_buff[port]).rx),(ccci_uartp_buff[port]).rx_buff, Buffaddr,Length);


        }
        else // can not output all
        {

            cnt = avail;
            CCCI_UARTB_POP_MULTI(((ccci_uartp_buff[port]).rx),(ccci_uartp_buff[port]).rx_buff, Buffaddr,avail);

        }
    }
    else
    {
        cnt = 0;
    }

    if (cnt != 0)
    {
        /* ack */
        ccci_uart_send_message_to_ap_retry (port, ccci_uart_port[port].rx_ack_channel, CCCI_UART_SEND_RETRY);
    }

    return cnt;
}

/*************************************************************************
* FUNCTION
*  ccci_uart_puttstexceuartbytes
*
* DESCRIPTION
*  Dedicate for TST channel in Meta mode (exception only)
*
* PARAMETERS
*  port       -   no use
*  Buffaddr   -   address of buffer to put
*  Legnth     -   buffer length
*
* RETURNS	
*  none
*
*************************************************************************/
void ccci_uart_puttstexceuartbytes(DCL_DEV port, kal_uint8 *Buffaddr, kal_uint16 Length)
{
    volatile   kal_uint32 left;
    kal_uint32 tx_cnt = 0;
    kal_uint8  *next_cpy_addr;

    if (port >= (FIRST_CCCI_UART_PORT + MAX_CCCI_UART_PORT)) 
    {
        return;
    }
    port -= FIRST_CCCI_UART_PORT;

    if (Length == 0) 
    {
        return;
    }

    do 
    {        
        CCCI_UARTB_GETROOMLEFT(((ccci_uartp_buff[port]).tx), left);

        if (left == 0)
        {	//- retry
            continue;	
        }
        
        next_cpy_addr = Buffaddr + tx_cnt;
        
        //- Available space is large enough to push remaining data
        if (left > (Length - tx_cnt)) 
        {
            left = Length - tx_cnt;
            
            CCCI_UARTB_PUSH_MULTI(((ccci_uartp_buff[port]).tx), (ccci_uartp_buff[port]).tx_buff, next_cpy_addr, left);
            ccci_uart_send_message_to_ap_retry (port, ccci_uart_port[port].tx_channel, CCCI_UART_SEND_RETRY);
			
            return;
        }
        else 
        {
            tx_cnt += left;

            //- Copy data from the user buffer to the TST buffer            
            CCCI_UARTB_PUSH_MULTI(((ccci_uartp_buff[port]).tx), (ccci_uartp_buff[port]).tx_buff, next_cpy_addr, left);
            ccci_uart_send_message_to_ap_retry (port, ccci_uart_port[port].tx_channel, CCCI_UART_SEND_RETRY);
        }
    } while (tx_cnt != Length);
}

/*************************************************************************
* FUNCTION
*  ccci_uart_putbytes
*
* DESCRIPTION
*  This function writes data to the UART port.
*
* PARAMETERS
*  port       -   no use
*  Buffaddr   -   address of buffer to put
*  Legnth     -   buffer length
*  ownerid    -   no use
*
* RETURNS
*  Number of bytes actually put
*
*************************************************************************/
static kal_uint16 ccci_uart_putbytes(DCL_DEV port, kal_uint8 *Buffaddr, kal_uint16 Length, module_type ownerid)
{
    kal_uint32 left, cnt, event,mask, shiftIndex;

    if (port >= (FIRST_CCCI_UART_PORT + MAX_CCCI_UART_PORT))
    {
        return KAL_FALSE;
    }
    port -= FIRST_CCCI_UART_PORT;

    if (ccci_uart_port[port].tx_owner != ownerid)
    {
        EXT_ASSERT(0, port + FIRST_CCCI_UART_PORT, ownerid, ccci_uart_port[port].tx_owner);
    }

    if (Length == 0)
    {
        return 0;
    }

    kal_retrieve_eg_events(ccci_uart_port[port].event, 1, KAL_OR_CONSUME, &event, KAL_NO_SUSPEND);
    cnt = Length;

    do
    {
        /* get available space in the TST buffer */

        mask = SaveAndSetIRQMask();

        CCCI_UARTB_GETROOMLEFT(((ccci_uartp_buff[port]).tx), left);
        if ( (left < cnt) && ccci_uart_behave_nonblock(port) )
        {
            /* cannot fit the required size; set the nofify flag */

            /*
            * NoteXXX: It is not necessary to use a mutex to protect flag access.
            *          This is because the flag is always be set in the task level
            *          and always be cleared in the HISR level.
            */

            ccci_uart_port[port].write_flag = 1;
        }
        RestoreIRQMask(mask);

        if (left > cnt)
        {
            /* copy data from the user buffer to the TST buffer */
            //CCCI_UARTB_PUSH_MULTI(uartb, bufaddr, input_addr, len)
            CCCI_UARTB_PUSH_MULTI(((ccci_uartp_buff[port]).tx), (ccci_uartp_buff[port]).tx_buff, Buffaddr,cnt);

            /* write data through CCCI */
            ccci_uart_send_message_to_ap_retry (port, ccci_uart_port[port].tx_channel, CCCI_UART_SEND_RETRY);
        }
        else
        {
            /* copy data from the user buffer to the TST buffer */

            cnt -= left;
            shiftIndex = left;

            //CCCI_UARTB_PUSH_MULTI(uartb, bufaddr, input_addr, len)
            CCCI_UARTB_PUSH_MULTI(((ccci_uartp_buff[port]).tx), (ccci_uartp_buff[port]).tx_buff, Buffaddr,left);

            //shift input buffer address
            Buffaddr += shiftIndex;

            /* write data through CCCI */
            ccci_uart_send_message_to_ap_retry (port, ccci_uart_port[port].tx_channel, CCCI_UART_SEND_RETRY);

            /* Yusu owner would like to receive msg when free space is available instead of handing by driver */
            if (KAL_FALSE == ccci_uart_behave_nonblock(port))
            {
                /* wait for an event */
                kal_retrieve_eg_events(ccci_uart_port[port].event, 1, KAL_OR_CONSUME, &event, KAL_SUSPEND);
            }
            else
            {
                Length -= cnt;
                break;
            }
        }
    }
    while (cnt > 0);

    return Length;
}


/*************************************************************************
* FUNCTION
*  ccci_uart_putisrbytes
*
* DESCRIPTION
*  This function writes data to the UART port in a LISR context.
*
* PARAMETERS
*  port       -   no use
*  Buffaddr   -   address of buffer to put
*  Length     -   buffer length
*  ownerid    -   no use
*
* RETURNS
*  Number of bytes actually put
*
*************************************************************************/
static kal_uint16 ccci_uart_putisrbytes(DCL_DEV port, kal_uint8 *Buffaddr, kal_uint16 Length, module_type ownerid)
{
    kal_uint32     left, cnt;
    kal_int32    ret;
    CCCI_BUFF_T buff;
    kal_uint32    retry = CCCI_UART_MAX_RETRY;
    kal_bool    always_retry;

    if (port >= (FIRST_CCCI_UART_PORT + MAX_CCCI_UART_PORT))
    {
        return KAL_FALSE;
    }
    port -= FIRST_CCCI_UART_PORT;

    if (ccci_uart_port[port].tx_owner != ownerid)
    {
        EXT_ASSERT(0, port + FIRST_CCCI_UART_PORT, ownerid, ccci_uart_port[port].tx_owner);
    }

    if (Buffaddr == NULL)
    {
        EXT_ASSERT(0, 0, 0, 0);
    }

    CCCI_UARTB_GETROOMLEFT(((ccci_uartp_buff[port]).tx), left);

    if (Length > left)
    {
        EXT_ASSERT(0, Length, left, 0);
    }

    /* copy data from the user buffer to the TST buffer */
    cnt = Length;

    CCCI_UARTB_PUSH_MULTI(((ccci_uartp_buff[port]).tx), (ccci_uartp_buff[port]).tx_buff, Buffaddr,cnt);

    /* write data through CCCI */

    CCCI_INIT_STREAM(&buff, (kal_uint32)((ccci_uartp_buff[port]).tx_buff), CCCI_TX_BUFF_LEN);

    always_retry = !retry;

    do
    {
        retry --;
        ret = ccci_write_internal(ccci_uart_port[port].tx_channel, &buff, (kal_bool)0);
        if (ret == CCCI_NO_PHY_CHANNEL)
        {
            continue;
        }

        if (ret == CCCI_SUCCESS)
        {
            break;
        }
        else
        {
            EXT_ASSERT(0, ret, 0, 0);
        }
    }
    while (always_retry || (retry != 0));

    if (!always_retry && (retry == 0))
    {
        ccci_debug_phychan_full = 1;
        EXT_ASSERT(0, port + FIRST_CCCI_UART_PORT, ownerid, ret);
    }

    return Length;
}


/*************************************************************************
* FUNCTION
*  ccci_uart_getisrtxavail
*
* DESCRIPTION
*  This function gets the remaining space in the TST buffer.
*
* PARAMETERS
*  port   -   no use
*
* RETURNS
*  number of bytes remained available in the TST buffer
*
*************************************************************************/
static kal_uint16 ccci_uart_getisrtxavail(DCL_DEV port)
{
    kal_uint32 left;


    if (port >= (FIRST_CCCI_UART_PORT + MAX_CCCI_UART_PORT))
    {
        return KAL_FALSE;
    }
    port -= FIRST_CCCI_UART_PORT;

    CCCI_UARTB_GETROOMLEFT(((ccci_uartp_buff[port]).tx), left);

    return left;
}


/*************************************************************************
* FUNCTION
*  ccci_uart_putexbytess
*
* DESCRIPTION
*  This is an empty function.
*
* PARAMETERS
*  port   -   no use
*  data   -   no use
*  len    -   no use
*
* RETURNS
*  none
*
*************************************************************************/
static void ccci_uart_putuartbytes(DCL_DEV port, kal_uint8 *data, kal_uint16 len)
{
    module_type ownerid;
    if ((port >= (FIRST_CCCI_UART_PORT + MAX_CCCI_UART_PORT)) || (port < FIRST_CCCI_UART_PORT))
    {
        return;
    }

    ownerid = ccci_uart_port[port-FIRST_CCCI_UART_PORT].tx_owner;
    ccci_uart_putbytes(port, data, len, ownerid);
}


/*************************************************************************
* FUNCTION
*  ccci_uart_putexbyte
*
* DESCRIPTION
*  This is an empty function.
*
* PARAMETERS
*  port    -   no use
*  data    -   no use
*
* RETURNS
*  none
*
*************************************************************************/
static void ccci_uart_putuartbyte(DCL_DEV port, kal_uint8 data)
{
    if (port >= (FIRST_CCCI_UART_PORT + MAX_CCCI_UART_PORT))
    {
        return;
    }

    data_for_putuartbyte = data;
    ccci_uart_putuartbytes(port,&data_for_putuartbyte,sizeof(data_for_putuartbyte));
}

/*************************************************************************
* FUNCTION
*  ccci_uart_getexbytes
*
* DESCRIPTION
*  This is an empty function.
*
* PARAMETERS
*  port   -   no use
*
* RETURNS
*  data from MD RX of SWDBG
*
*************************************************************************/
static kal_uint8 ccci_uart_getuartbyte(DCL_DEV port)
{
    /* This function can only be called after exception*/
    kal_uint32 avail;
    kal_uint8 data;

    if (port >= (FIRST_CCCI_UART_PORT + MAX_CCCI_UART_PORT))
    {
        return KAL_FALSE;
    }
    port -= FIRST_CCCI_UART_PORT;


    if(INT_Exception_Enter == 0)
        ASSERT(0);

    CCCI_UARTB_GETAVAIL(((ccci_uartp_buff[port]).rx), avail);


    while(avail==0)
    {
        CCCI_UARTB_GETAVAIL(((ccci_uartp_buff[port]).rx), avail);
    }

    CCCI_UARTB_POP(((ccci_uartp_buff[port]).rx), (ccci_uartp_buff[port]).rx_buff, data);

    return data;
}


/*************************************************************************
* FUNCTION
*  ccci_uart_getrxavail
*
* DESCRIPTION
*  This is an empty function.
*
* PARAMETERS
*  port   -   no use
*
* RETURNS
*  always zero
*
*************************************************************************/
static kal_uint16 ccci_uart_getrxavail(DCL_DEV port)
{
    kal_uint32 avail;

    if (port >= (FIRST_CCCI_UART_PORT + MAX_CCCI_UART_PORT))
    {
        return KAL_FALSE;
    }
    port -= FIRST_CCCI_UART_PORT;

    CCCI_UARTB_GETROOMLEFT(((ccci_uartp_buff[port]).rx), avail);

    return avail;
}


/*************************************************************************
* FUNCTION
*  ccci_uart_gettxavail
*
* DESCRIPTION
*  This is an empty function.
*
* PARAMETERS
*  port   -   no use
*
* RETURNS
*  always zero
*
*************************************************************************/
static kal_uint16 ccci_uart_gettxavail(DCL_DEV port)
{
    kal_uint32 avail;

    if (port >= (FIRST_CCCI_UART_PORT + MAX_CCCI_UART_PORT))
    {
        return KAL_FALSE;
    }
    port -= FIRST_CCCI_UART_PORT;


    CCCI_UARTB_GETROOMLEFT(((ccci_uartp_buff[port]).tx), avail);

    return avail;
}


/*************************************************************************
* FUNCTION
*  ccci_uart_purge
*
* DESCRIPTION
*  This is an empty function.
*
* PARAMETERS
*  port    -   no use
*  dir     -   no use
*  owner   -   no use
*
* RETURNS
*  none
*
*************************************************************************/
static void ccci_uart_purge(DCL_DEV port, UART_buffer dir, module_type owner)
{
    /* ccci uart like interface can not stop */

    return ;
}


/*************************************************************************
* FUNCTION
*  ccci_uart_setowner
*
* DESCRIPTION
*  This is an empty function.
*
* PARAMETERS
*  port     -   no use
*  owner    -   no use
*
* RETURNS
*  none
*
*************************************************************************/
static void ccci_uart_setowner(DCL_DEV port, module_type owner)
{
    if ((port >= (FIRST_CCCI_UART_PORT + MAX_CCCI_UART_PORT)) || (port < FIRST_CCCI_UART_PORT))
    {
        return;
    }

    /* only AT command channel can be used to change owner */
    if (uart_port_at_ccci != port) return;
    else
    {
        port -= FIRST_CCCI_UART_PORT;
        ccci_uart_port[port].rx_owner = owner;
        ccci_uart_port[port].tx_owner = owner;

        ccci_change_owner_only(ccci_uart_port[port].tx_channel,owner);
        ccci_change_owner_only(ccci_uart_port[port].tx_ack_channel,owner);
        ccci_change_owner_only(ccci_uart_port[port].rx_channel,owner);
        ccci_change_owner_only(ccci_uart_port[port].rx_ack_channel,owner);
    }
}


/*************************************************************************
* FUNCTION
*  ccci_uart_setflowctrl
*
* DESCRIPTION
*  This is an empty function.
*
* PARAMETERS
*  port    -   no use
*  XON     -   no use
*  owner   -   no use
*
* RETURNS
*  none
*
*************************************************************************/
static void ccci_uart_setflowctrl(DCL_DEV port, kal_bool XON, module_type owner)
{
    /* ccci uart interface is control by driver itself */
    return ;
}


/*************************************************************************
* FUNCTION
*  ccci_uart_configescape
*
* DESCRIPTION
*  This is an empty function.
*
* PARAMETERS
*  port           -   no use
*  EscChar        -   no use
*  ESCGuardtime   -   no use
*  owner          -   no use
*
* RETURNS
*  none
*
*************************************************************************/
static void ccci_uart_configescape(DCL_DEV port, kal_uint8 EscChar, kal_uint16 ESCGuardtime, module_type owner)
{
    /* ccci uart interface is control by driver itself */
    return ;
}


/*************************************************************************
* FUNCTION
*  ccci_uart_setdcbconfig
*
* DESCRIPTION
*  This is an empty function.
*
* PARAMETERS
*  port          -   no use
*  UART_Config   -   no use
*  owner         -   no use
*
* RETURNS
*  none
*
*************************************************************************/
static void ccci_uart_setdcbconfig(DCL_DEV port, UARTDCBStruct *UART_Config, module_type owner)
{
    /* ccci uart interface is control by driver itself */
    return ;
}


/*************************************************************************
* FUNCTION
*  ccci_uart_ctrldcd
*
* DESCRIPTION
*  This is an empty function.
*
* PARAMETERS
*  port    -   no use
*  SDCD    -   no use
*  owner   -   no use
*
* RETURNS
*  none
*
*************************************************************************/
static void ccci_uart_ctrldcd(DCL_DEV port, IO_level SDCD, module_type owner)
{
    /* ccci uart interface is control by driver itself */
    return ;
}


/*************************************************************************
* FUNCTION
*  ccci_uart_ctrlbreak
*
* DESCRIPTION
*  This is an empty function.
*
* PARAMETERS
*  port       -   no use
*  IO_level   -   no use
*  owner      -   no use
*
* RETURNS
*  none
*
*************************************************************************/
static void ccci_uart_ctrlbreak(DCL_DEV port, IO_level SBREAK, module_type owner)
{
    /* ccci uart interface is control by driver itself */
    return ;
}


/*************************************************************************
* FUNCTION
*  ccci_uart_clrrxbuffer
*
* DESCRIPTION
*  This is an empty function.
*
* PARAMETERS
*  port    -   no use
*  owner   -   no use
*
* RETURNS
*  none
*
*************************************************************************/
static void ccci_uart_clrrxbuffer(DCL_DEV port, module_type owner)
{

    if (port >= (FIRST_CCCI_UART_PORT + MAX_CCCI_UART_PORT))
    {
        return;
    }
    port -= FIRST_CCCI_UART_PORT;


    CCCI_UARTB_INIT(((ccci_uartp_buff[port]).rx), (ccci_uartp_buff[port].rx_buff-ccci_uartp_buff[port].tx_buff));
}


/*************************************************************************
* FUNCTION
*  ccci_uart_clrtxbuffer
*
* DESCRIPTION
*  This is an empty function.
*
* PARAMETERS
*  port    -   no use
*  owner   -   no use
*
* RETURNS
*  none
*
*************************************************************************/
static void ccci_uart_clrtxbuffer(DCL_DEV port, module_type owner)
{
    if (port >= (FIRST_CCCI_UART_PORT + MAX_CCCI_UART_PORT))
    {
        return;
    }
    port -= FIRST_CCCI_UART_PORT;

    CCCI_UARTB_INIT(((ccci_uartp_buff[port]).tx),(ccci_uartp_buff[port].rx_buff-ccci_uartp_buff[port].tx_buff));
}


/*************************************************************************
* FUNCTION
*  ccci_uart_setbaudrate
*
* DESCRIPTION
*  This is an empty function.
*
* PARAMETERS
*  port       -   no use
*  baudrate   -   no use
*  owner      -   no use
*
* RETURNS
*  none
*
*************************************************************************/
static void ccci_uart_setbaudrate(DCL_DEV port, UART_baudrate baudrate, module_type owner)
{
    /* ccci uart interface is control by driver itself, set baudrate is useless */
    return ;
}


/*************************************************************************
* FUNCTION
*  ccci_uart_sendisrdata
*
* DESCRIPTION
*  This is an empty function.
*
* PARAMETERS
*  port          -   no use
*  buffaddr      -   no use
*  Length        -   no use
*  mode          -   no use
*  escape_char   -   no use
*  ownerid       -   no use
*
* RETURNS
*  always zero
*
*************************************************************************/
static kal_uint16 ccci_uart_sendisrdata(DCL_DEV port, kal_uint8 *Buffaddr, kal_uint16 Length, kal_uint8 mode, kal_uint8 escape_char, module_type ownerid)
{
    if (port >= (FIRST_CCCI_UART_PORT + MAX_CCCI_UART_PORT))
    {
        return KAL_FALSE;
    }

    return ccci_uart_putisrbytes(port, Buffaddr,Length,ownerid);
}


/*************************************************************************
* FUNCTION
*  ccci_uart_senddata
*
* DESCRIPTION
*  This is an empty function.
*
* PARAMETERS
*  port          -   no use
*  buffaddr      -   no use
*  Length        -   no use
*  mode          -   no use
*  escape_char   -   no use
*  ownerid       -   no use
*
* RETURNS
*  always zero
*
*************************************************************************/
static kal_uint16 ccci_uart_senddata(DCL_DEV port, kal_uint8 *Buffaddr, kal_uint16 Length, kal_uint8 mode, kal_uint8 escape_char, module_type ownerid)
{
    if (port >= (FIRST_CCCI_UART_PORT + MAX_CCCI_UART_PORT))
    {
        return KAL_FALSE;
    }


    return ccci_uart_putbytes(port, Buffaddr, Length, ownerid);
}


/*************************************************************************
* FUNCTION
*  ccci_uart_getownerid
*
* DESCRIPTION
*  This is an empty function.
*
* PARAMETERS
*  port   -   no use
*
* RETURNS
*  always MOD_NIL
*
*************************************************************************/
static module_type ccci_uart_getownerid(DCL_DEV port)
{
    if (port >= (FIRST_CCCI_UART_PORT + MAX_CCCI_UART_PORT))
    {
        return (module_type)KAL_FALSE;
    }
    port -= FIRST_CCCI_UART_PORT;

    /* TST channel always return TR because only TR and TST will use TST channel */

    return ccci_uart_port[port].rx_owner;
}


/*************************************************************************
* FUNCTION
*  ccci_uart_setautobaud_div
*
* DESCRIPTION
*  This is an empty function.
*
* PARAMETERS
*  port    -   no use
*  owner   -   no use
*
* RETURNS
*  none
*
*************************************************************************/
static void ccci_uart_setautobaud_div(DCL_DEV port, module_type owner)
{
    return ;
}


/*************************************************************************
* FUNCTION
*  ccci_uart_register_tx_cb
*
* DESCRIPTION
*  This is an empty function.
*
* PARAMETERS
*  port    -   no use
*  owner   -   no use
*  func    -   no use
*
* RETURNS
*  none
*
*************************************************************************/
static void ccci_uart_register_tx_cb(DCL_DEV port, module_type owner, DCL_UART_TX_FUNC func)
{
    return ;
}


/*************************************************************************
* FUNCTION
*  ccci_uart_register_rx_cb
*
* DESCRIPTION
*  This is an empty function.
*
* PARAMETERS
*  port    -   no use
*  owner   -   no use
*  func    -   no use
*
* RETURNS
*  none
*
*************************************************************************/
static void ccci_uart_register_rx_cb(DCL_DEV port, module_type owner, DCL_UART_RX_FUNC func)
{
    return ;
}



/*************************************************************************
* FUNCTION
*  ccci_uart_ReadDCBConfig
*
* DESCRIPTION
*  This is an empty function.
*
* PARAMETERS
*  port    -   no use
*  owner   -   no use
*  func    -   no use
*
* RETURNS
*  none
*
*************************************************************************/
static void ccci_uart_ReadDCBConfig(DCL_DEV port, UARTDCBStruct *DCB)
{
    return ;
}

/*************************************************************************
* FUNCTION
*  ccci_uart_CtrlRI
*
* DESCRIPTION
*  This is an empty function.
*
* PARAMETERS
*  port    -   no use
*  owner   -   no use
*  func    -   no use
*
* RETURNS
*  none
*
*************************************************************************/
static void ccci_uart_CtrlRI (DCL_DEV port, IO_level SRI, module_type ownerid)
{
    return ;
}


/*************************************************************************
* FUNCTION
*  ccci_uart_CtrlDTR
*
* DESCRIPTION
*  This is an empty function.
*
* PARAMETERS
*  port    -   no use
*  owner   -   no use
*  func    -   no use
*
* RETURNS
*  none
*
*************************************************************************/

static void ccci_uart_CtrlDTR(DCL_DEV port, IO_level SDTR, module_type ownerid)
{
    return ;
}


/*************************************************************************
* FUNCTION
*  ccci_uart_ReadHWStatus
*
* DESCRIPTION
*  This is an empty function.
*
* PARAMETERS
*  port    -   no use
*  owner   -   no use
*  func    -   no use
*
* RETURNS
*  none
*
*************************************************************************/

static void ccci_uart_ReadHWStatus(DCL_DEV port, IO_level *SDSR, IO_level *SCTS)
{
    return ;
}


/*************************************************************************
* FUNCTION
*  ccci_ups_get_DL_buffer_attribute
*
* DESCRIPTION
*  .
*
* PARAMETERS
*  none
*
* RETURNS
*  none
*
*************************************************************************/
void ccci_ups_get_UL_buffer_attribute (kal_uint8** addr, kal_uint32* length)
{
#ifdef CCCI_UART_GIO
    if (ccci_giopdu_flowctl.rx_buffer_size)
    {
        *length        = ccci_giopdu_flowctl.rx_buffer_size;
        *addr         = (kal_uint8*)(ccci_giopdu_flowctl.rx_buffer_base);
    }
    else
    {
        *addr = 0;
    }
#else
    *addr    = 0;
    *length = 0;
#endif
}

#ifdef CCCI_UART_GIO
#ifdef CCCI_UART_GIO_IT
/*************************************************************************
* FUNCTION
*  ccci_uart_gio_initial_IT
*
* DESCRIPTION
*  .
*
* PARAMETERS
*  none
*
* RETURNS
*  none
*
*************************************************************************/
void ccci_uart_gio_initial_IT (void)
{
#ifdef CCCI_UART_GIO_IT

    ccci_uart_gio_it_timer = kal_create_timer("CCCI_GIO_IT");
    kal_set_timer(ccci_uart_gio_it_timer,
                  ccci_uart_gio_it_timer_callback,
                  NULL,
                  1,
                  1);    //- 1 tick timer
#endif
}
#endif //- CCCI_UART_GIO_IT

/*************************************************************************
* FUNCTION
*  ccci_uart_gio_initial
*
* DESCRIPTION
*  .
*
* PARAMETERS
*  none
*
* RETURNS
*  none
*
*************************************************************************/
void ccci_uart_gio_initial (void)
{
    kal_uint32 index;
    kal_uint32 rx_ringQ_max_len;
    kal_uint32 max_len;

    ccci_giopdu_flowctl.rx_buffer_base = (kal_uint8*)ap_md_share_data.MDULNetShareMemBase;
    ccci_giopdu_flowctl.rx_buffer_size = ap_md_share_data.MDULNetShareMemSize;
    ccci_giopdu_flowctl.tx_buffer_base = (kal_uint8*)ap_md_share_data.MDDLNetShareMemBase;
    ccci_giopdu_flowctl.tx_buffer_size = ap_md_share_data.MDDLNetShareMemSize;

    rx_ringQ_max_len = ccci_giopdu_flowctl.rx_buffer_size / (3 * CCCI_GIOPDU_ENTRY_LENGTH);

    for (index = 0; index < MAX_CCCI_GIOPDU_PORT; index ++)
    {
        CCCI_GIOPDU_SMCTL_T *rx_ctl = (CCCI_GIOPDU_SMCTL_T *)(ap_md_share_data.NetULCtrlShareMemBase[index]);
        CCCI_GIOPDU_SMCTL_T *tx_ctl = (CCCI_GIOPDU_SMCTL_T *)(ap_md_share_data.NetDLCtrlShareMemBase[index]);

        ccci_giopdu_ctlblk[index].rx_ctl = rx_ctl;
        ccci_giopdu_ctlblk[index].tx_ctl = tx_ctl;
        ccci_giopdu_ctlblk[index].rx_ringQ = (CCCI_GIOPDU_RINGQ_T*)(rx_ctl + 1);
        ccci_giopdu_ctlblk[index].tx_ringQ = (CCCI_GIOPDU_RINGQ_T*)(tx_ctl + 1);

        max_len = (ap_md_share_data.NetULCtrlShareMemSize[index] - sizeof(CCCI_GIOPDU_SMCTL_T)) / sizeof(CCCI_GIOPDU_RINGQ_T);
        if (max_len > rx_ringQ_max_len)
        {
            ccci_ap_md_net_ULRingQ_mismatch |= (1 << index);
            max_len = rx_ringQ_max_len;
        }
        ccci_giopdu_ctlblk[index].rx_ctl->ringQ_len = max_len;

        ccci_giopdu_ctlblk[index].rx_ringQ_threshold = (max_len + 3) >> 2;

        if ( ap_md_share_data.NetDLCtrlShareMemSize[index] != tx_ctl->ringQ_len * sizeof(CCCI_GIOPDU_RINGQ_T) + sizeof(CCCI_GIOPDU_SMCTL_T) )
        {
            ccci_ap_md_net_DLRingQ_mismatch |= (1 << index);
        }

    }

#ifdef CCCI_GIOPDU_UPLINK_CCCI_FLOWCTL
    ccci_uart_gio_rx_partition ();
#endif
}
/*************************************************************************
* FUNCTION
*  ccci_uart_send_message_to_ap
*
* DESCRIPTION
*
*
* PARAMETERS
*  none
*
* RETURNS
*  none
*
*************************************************************************/
static kal_int32 ccci_uart_send_message_to_ap(kal_uint32 port, kal_uint32 channel)
{
    CCCI_BUFF_T    buff;
    kal_int32    ret;

    //- send ccif message
    CCCI_INIT_MAILBOX(&buff, 0);
    buff.reserved = port;

    ret = ccci_write(channel, &buff);

    if ( ret == CCCI_SUCCESS || ret == CCCI_NO_PHY_CHANNEL )
    {
        return ret;
    }
    else
    {
        //- This case should not happen during initialization and exception handler.
        EXT_ASSERT(0, ret, 0, 0);
        return ret;
    }
}

/*************************************************************************
* FUNCTION
*  ccci_uart_gio_bce_callback
*
* DESCRIPTION
*  This function implements the CCCI callback function for BCE.
*
* PARAMETERS
*  none
*
* RETURNS
*  none
*
*************************************************************************/
void ccci_uart_gio_bce_callback(kal_bool status, kal_uint32 cur_dscr_seg_addr)
{
    kal_uint32    port, gio_port;
    kal_uint32    output_addr;
    gpd_node    *p_pfirst;
    gpd_node    *p_plast;
    gpd_list    *ptr_proclist;
    gpd_list    *ptr_recylist;

#ifdef CCCI_BCE_HISR_BCE_KICKBACK
    kal_int32     ret = 0;
#endif

    ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] DL_BCEcb In");

    if (status == KAL_FALSE)
    {
        ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] DL_BCEcb Fail %08x", cur_dscr_seg_addr);
    }

    for (gio_port=0; gio_port<MAX_CCCI_GIOPDU_PORT; gio_port++)
    {
        if (ccci_giopdu_flowctl.startBCMask & (1 << gio_port))
        {
            ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] DL_BCEcb %d", gio_port);
            break;
        }
    }

    if (gio_port == MAX_CCCI_GIOPDU_PORT)
        EXT_ASSERT(0, 0 , 0 ,0);


#ifdef CCCI_UART_GIO_IT
    ccci_giopdu_flowctl.it_state = 0;
#endif
    ccci_giopdu_flowctl.startBCMask &= (~((kal_uint32)1 << gio_port));
    port = ccci_gioport_2_uartport[gio_port];

//-    ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] DL_BCEcb %d, M %08x", gio_port, ccci_giopdu_flowctl.startBCMask);

    //- send ccif message
    if ( CCCI_NO_PHY_CHANNEL == ccci_uart_send_message_to_ap (port, ccci_uart_port[port].tx_channel) )
    {
        ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] DL_BCEcb send fail");
        ccci_uart_gio_task_send_retry |= (1 << gio_port);
    }

    //- adjust value of avai_out
    CCCI_GIOPDU_ADJUST_TX_AVAIOUT (gio_port, ccci_giopdu_ctlblk[gio_port].procRingQBaseNext);

//-    ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] DL_BCEcb%d : avai_out->%d", gio_port, ccci_giopdu_ctlblk[gio_port].tx_ctl->avai_out);

    ptr_proclist = &ccci_giopdu_ctlblk[gio_port].processing_gpd_list;
    //- To get processing gpd list
    p_pfirst = gpd_lib_list_poll_ex (ptr_proclist, &p_plast);
    //- restore EOF for general DPG "END" format
    p_plast->w1.next_gpd_addr = NULL;

    ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] DL_BCEcb%d : avai_out->%d *Plist %08x %08x", gio_port, ccci_giopdu_ctlblk[gio_port].tx_ctl->avai_out, p_pfirst, p_plast);

    output_addr = *((kal_uint32*)p_pfirst+4);
    if (output_addr == 0)
        EXT_ASSERT(0, 0, 0, 0);

    output_addr = *((kal_uint32*)p_plast+4);
    if (output_addr == 0)
        EXT_ASSERT(0, 0, 0, 0);

#ifdef CCCI_GIOPDU_DEBUG_TRACE_DL0
    ccci_giopdu_ctlblk[gio_port].DL_done += gpd_lib_size((gpd_node*)p_pfirst);
    ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] DL_done : %d", ccci_giopdu_ctlblk[gio_port].DL_done);
#endif

    //- prepare recycle gpd list
    if (CCCI_GIOPDU_GIO_ENABLE_TXMERGERECYCLE (gio_port))
    {
        //- merge to gio_port0
        gio_port = 0;
        port = ccci_gioport_2_uartport[0];
    }

    ptr_recylist = &ccci_giopdu_ctlblk[gio_port].recycle_gpd_list;
    if (ccci_giopdu_ctlblk[gio_port].recycle_gpd_first == 0)
    {
        gpd_lib_list_create ( ptr_recylist );
        //- let head gpd of processing as head gpd of recycle
        ccci_giopdu_ctlblk[gio_port].recycle_gpd_first = p_pfirst;
        //- check if need to notify user to recycle gpd
        if (!ccci_giopdu_ctlblk[gio_port].recycle_msg)
        {
            ccci_giopdu_ctlblk[gio_port].recycle_msg = 1;
            //- send ilm to notify user
            ccci_uart_send_message_to_user (port, 1, ccci_uart_port[port].tx_owner);

            ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] DL_BCEcb%d : Notify user to recycle", gio_port);
        }
    }

    //- let processing gpd list append to recycle gpd list
    gpd_lib_list_add_ex(ptr_recylist, p_pfirst, p_plast);

    if (ccci_giopdu_ctlblk[gio_port].recycle_gpd_first == p_pfirst)
    {
        ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] DL_BCEcb%d : PendingRCY head->%08x", gio_port, ccci_giopdu_ctlblk[gio_port].recycle_gpd_first);
    }
    else
    {
        ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] DL_BCEcb%d : PendingRCY head->%08x, add->%08x", gio_port, ccci_giopdu_ctlblk[gio_port].recycle_gpd_first, p_pfirst);
    }

#ifdef CCCI_BCE_HISR_BCE_KICKBACK
    //- kickback BCE if needed
    ret = ccci_uart_gio_tx_go_BCE (CCCI_GIOPDU_UNDESIGNATE_PORT, CCCI_GIOPDU_TX_GO_ENTRY_BCE_HISR);
    if (ret)
        ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] DL_BCEcb%d : %s", gio_port, ccci_giopdu_err_string[0-ret]);
#endif


    ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] DL_BCEcb Out");
}
/*************************************************************************
* FUNCTION
*  ccci_uart_gio_start_BCE
*
* DESCRIPTION
*  .
*
* PARAMETERS
*  none
*
* RETURNS
*  none
*
*************************************************************************/
void ccci_uart_gio_start_BCE (void* start_desc)
{

#ifdef CCCI_UART_GIO_IT
    kal_uint32 int_mask;

    int_mask = SaveAndSetIRQMask();
    ccci_giopdu_flowctl.it_state = 1;
    RestoreIRQMask(int_mask);

#else
    kal_bool    res;

    if (KAL_FALSE == hw_cmd_byte_copy_query_busy(BYTECOPY_UPS))
    {
        //- to start BCE engine
        ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] DL_StartBCE %08x", start_desc);
        ccci_giopdu_flowctl.byte_copy_start.BYTE_COPY_DSCR_ADDR = start_desc;
        res = hw_cmd_byte_copy_start(BYTECOPY_UPS, &ccci_giopdu_flowctl.byte_copy_start);
        if (res == KAL_TRUE)
            ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] DL_StartBCE (Ok)");
        else
            ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] DL_StartBCE (Err)");
    }
    else
    {
        ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] DL_StartBCE (Busy)");
    }
#endif
}

/*************************************************************************
* FUNCTION
*  ccci_uart_gio_it_timer_callback
*
* DESCRIPTION
*  .
*
* PARAMETERS
*  none
*
* RETURNS
*  none
*
*************************************************************************/
#ifdef CCCI_UART_GIO_IT
void ccci_uart_gio_it_timer_callback (void *param_ptr)
{
    kal_uint32 i;
    kal_uint32 port;

    CCCI_GIOPDU_TimerCB_in = 1;

    if (CCCI_GIOPDU_CCIFCB_in)
        EXT_ASSERT (0, 0, 0, 0);

    for (i=uart_port_ccmni1_ccci; i<=uart_port_ccmni3_ccci; i++)
    {
        port = i - uart_port_tst_ccci;
        if (ccci_giopdu_flowctl.ilmRxBGFlag & (1 << port))
        {
            ccci_uart_send_message_to_user (port, 0, ccci_uart_port[port].rx_owner);
            ccci_giopdu_flowctl.ilmRxBGFlag &= (~(1 << port));
        }
    }

    if ((ccci_giopdu_flowctl.it_state == 1) && (ccci_giopdu_flowctl.startBCMask))
    {
        ccci_uart_gio_bce_callback (KAL_TRUE, 0);
    }

    CCCI_GIOPDU_TimerCB_in = 0;
}
#endif    //- CCCI_UART_GIO_IT

/*************************************************************************
* FUNCTION
*  ccci_uart_gio_is_gio_port
*
* DESCRIPTION
*  This function implements the CCCI callback function for TST drivers.
*
* PARAMETERS
*  none
*
* RETURNS
*  none
*
*************************************************************************/
static kal_bool ccci_uart_gio_is_gio_port(DCL_DEV port)
{
    if ((1 << (port - FIRST_CCCI_CCMNI_PORT)) & ccci_uart_gio_ctlblk.gio_port_mask)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

#ifdef CCCI_GIOPDU_UPLINK_CCCI_FLOWCTL
/*************************************************************************
* FUNCTION
*  ccci_uart_gio_rx_preload_0
*
* DESCRIPTION
*
*
* PARAMETERS
*  port    -   the GIO port
*  option   -   no use
*  owner    -   the current task
*
* RETURNS
*  status (success or fail)
*
*************************************************************************/
void ccci_uart_gio_rx_preload_0 (kal_uint32 gio_port, kal_bool isSendMsg)
{
    kal_uint32    left, avai_in, read_out, port, len, max_in;

#ifdef CCCI_GIOPDU_EXTDBG
    kal_uint32                i;
    kal_uint32                base1;
    CCCI_GIOPDU_DBGBLK_HEADER_T    *dbginfo_H;
    CCCI_GIOPDU_RINGQ_T        *ptr_ringQ;
#endif


    CCCI_GIOPDU_RINGQ_GETLOADAVAIL (ccci_giopdu_ctlblk[gio_port].rx_ctl, left, avai_in, read_out, len);

    max_in = CCCI_GIOPDU_GIO_ENABLE_RXMAXPRELOAD(gio_port);

    if (max_in)
    {
        if (avai_in || read_out)
        {
            if ((len - max_in) >= left)
            {
                //- enough ringQ space
                return;
            }
            else
            {
                left = max_in - (len - left) + 1;
            }
        }
        else
        {
            //- init state
            left = max_in;
        }
    }

    if (!left)
    {
        ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] UL_pload%d : No left space", gio_port);

        return;
    }

#ifdef CCCI_GIOPDU_EXTDBG
    base1 = avai_in;
    for (i=0; i<left; i++)
    {
        ptr_ringQ = ccci_giopdu_ctlblk[gio_port].rx_ringQ + base1;
        //- Debug : set D12
        dbginfo_H             = (CCCI_GIOPDU_DBGBLK_HEADER_T*)(ptr_ringQ->ptr_entry) - 1;
        dbginfo_H->port        = gio_port;
        dbginfo_H->avai_in    = base1;

        base1 ++;
        if (base1 == len)
            base1 = 0;
    }
#endif

    avai_in += left;
    if (avai_in >= len)
        avai_in -= len;

    CCCI_GIOPDU_ADJUST_RX_AVAIIN (gio_port, avai_in);

    ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] UL_pload%d : in->%d", gio_port, avai_in);

    if (isSendMsg)
    {
        port = ccci_gioport_2_uartport[gio_port];
        ccci_uart_send_message_to_ap_retry (port, ccci_uart_port[port].rx_ack_channel, CCCI_UART_SEND_RETRY);

        ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] UL_pload%d : Send CCIF", gio_port);
    }
}

/*************************************************************************
* FUNCTION
*  ccci_uart_gio_rx_partition
*
* DESCRIPTION
*
*
* PARAMETERS
*  port    -   the GIO port
*  option   -   no use
*  owner    -   the current task
*
* RETURNS
*  status (success or fail)
*
*************************************************************************/
void ccci_uart_gio_rx_partition (void)
{
    kal_uint8    *curr;
    kal_uint8    *upper;
    kal_uint32    gio_port;
    kal_uint32    i;
    kal_uint32    entry_len;

#ifdef CCCI_GIOPDU_EXTDBG
    CCCI_GIOPDU_DBGBLK_HEADER_T    *dbginfo_H;
    CCCI_GIOPDU_DBGBLK_FOOTER_T    *dbginfo_L;
#endif
    CCCI_GIOPDU_RINGQ_T        *ptr_ringQ;

    curr    = ccci_giopdu_flowctl.rx_buffer_base;
    upper     = curr + ccci_giopdu_flowctl.rx_buffer_size;
    //- 4 byte align
    curr         = (kal_uint8*)((((kal_uint32)curr + 3) >> 2) << 2);
    entry_len    = ((CCCI_GIOPDU_MAX_PDU_SIZE + 3) >> 2) << 2;

    ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI]DL Partirion");

    for (gio_port=0; gio_port<MAX_CCCI_GIOPDU_PORT; gio_port++)
    {
        //- To fill all ptr_x in ringQ by each gio_port
        ptr_ringQ = ccci_giopdu_ctlblk[gio_port].rx_ringQ;

        for (i=0; i<ccci_giopdu_ctlblk[gio_port].rx_ctl->ringQ_len; i++)
        {
#ifdef CCCI_GIOPDU_EXTDBG
            //- Debug : set DHF
            dbginfo_H = (CCCI_GIOPDU_DBGBLK_HEADER_T*)curr;
            dbginfo_H->header = CCCI_GIOPDU_DBG_HEADER;
            //- Debug : reset D1234
            memset ( (kal_uint8*)dbginfo_H, CCCI_GIOPDU_DBG_INVALID_1B, (sizeof(CCCI_GIOPDU_DBGBLK_HEADER_T) - sizeof(kal_uint32)) );
            curr += sizeof (CCCI_GIOPDU_DBGBLK_HEADER_T);
#endif

            ptr_ringQ->ptr_entry = curr; //- curr point to data field now
            curr = curr + entry_len;
            //- first time, no need to check wrap
            ptr_ringQ ++;

#ifdef CCCI_GIOPDU_EXTDBG
            dbginfo_L = (CCCI_GIOPDU_DBGBLK_FOOTER_T*)curr;
            dbginfo_L->footer = CCCI_GIOPDU_DBG_FOOTER;
            curr += sizeof(CCCI_GIOPDU_DBGBLK_FOOTER_T);
#endif
        }
    }

    if (curr >= upper)
    {
        EXT_ASSERT (0, 0, 0, 0);
    }
}

#endif //- CCCI_GIOPDU_UPLINK_CCCI_FLOWCTL

/*************************************************************************
* FUNCTION
*  ccci_uart_gio_enable
*
* DESCRIPTION
*  The function is to enable the GIO mode.
*
* PARAMETERS
*  port    -   the GIO port
*  option   -   no use
*  owner    -   the current task
*
* RETURNS
*  status (success or fail)
*
*************************************************************************/
kal_uint8 ccci_uart_gio_enable (DCL_DEV port, kal_uint32 option, module_type owner)
{
    kal_uint32 gio_port;

#ifndef CCCI_UART_GIO_IT
    if (!ccci_uart_gio_ctlblk.gio_port_mask)
    {
        //- to register callback of BCE
        hw_cmd_byte_copy_register_callback((tpfnBCCallback)ccci_uart_gio_bce_callback);

        //- Init byte copy engine
        //- In 3G projects, BCE will be initialzed by UL2. In 2G only projects, UPS task
        //- will call this function to initialize BCE. From Wonder, BCE init function
        //- can be called for several times. There is no concern if UL2 initilaized BCE
        //- and CCCI also initialize it.
        hw_cmd_byte_copy_init();
    }
#endif

    gio_port = port - FIRST_CCCI_CCMNI_PORT;

    /* error check: pointers should be NULL before port open */
    if ((ccci_uart_gio_ctlblk.gio_port_mask & (1 << gio_port)) == 0)
    {
        if (ccci_giopdu_ctlblk[gio_port].rx_ctl->avai_in != 0 || \
            ccci_giopdu_ctlblk[gio_port].rx_ctl->read_out != 0 || \
            ccci_giopdu_ctlblk[gio_port].tx_ctl->avai_out != 0)
        {
            EXT_ASSERT(0, 0, 0, 0);
        }
    }

    ccci_uart_gio_ctlblk.gio_port_mask |= (1 << gio_port);


    ccci_giopdu_ctlblk[gio_port].option                = option;
    ccci_giopdu_ctlblk[gio_port].waiting_gpd_first    = NULL;


#ifdef CCCI_GIOPDU_UPLINK_CCCI_FLOWCTL
    //- preload
    ccci_uart_gio_rx_preload_0 (gio_port, 1);
#endif

    return KAL_TRUE;
}

/*************************************************************************
* FUNCTION
*  ccci_uart_gio_disable
*
* DESCRIPTION
*  The function should not be called.
*
* PARAMETERS
*  port    -   the GIO port
*  option   -   no use
*  owner    -   the current task
*
* RETURNS
*  status (success or fail)
*
*************************************************************************/
kal_uint8 ccci_uart_gio_disable (DCL_DEV port, kal_uint32 option, module_type owner)
{
    ccci_uart_gio_ctlblk.gio_port_mask &= (~(1 << (port - FIRST_CCCI_CCMNI_PORT)));

    return KAL_TRUE;
}

/*************************************************************************
* FUNCTION
*  ccci_uart_gio_tx_go_BCE
*
* DESCRIPTION
*  The function is for gio users to send gpd ptr to HW medium.
*  there will be BD or GPD format(for CCCI driver, there will be GPD format confirmed by Stan Chen(UPS owner)
*
* PARAMETERS
*  gio_port        -
*  entry         -
*
* RETURNS
*  gpd ptr
*
*************************************************************************/
kal_uint32 ccci_dbg_go_BCE[10];
kal_int32 ccci_uart_gio_tx_go_BCE (kal_uint32 gio_port, kal_uint32 entry)
{
    kal_uint32     i, int_mask;
    kal_uint32    tmp_len;
    kal_uint8    *tmp_ptr;
    kal_uint8    *tmp_end;
    kal_uint32    left, base, max_input;
    kal_uint32    output_addr;
    gpd_node    *p_wfirst;
    gpd_node    *p_wlast;
    gpd_node    *p_pfirst;
    gpd_node    *p_plast = NULL;    //- avoid complier warning (may be used uninitialized in this function [-Wuninitialized])
    gpd_node    *node = NULL;        //- avoid complier warning (may be used uninitialized in this function [-Wuninitialized])
    gpd_node    *node_cut;
    gpd_itr        local_itr;
    gpd_list    *ptr_list;
    CCCI_GIOPDU_RINGQ_T    *ptr_ringQ;

    kal_int32    ret = CCCI_GIOPDU_NO_ERR;

#ifdef CCCI_GIOPDU_EXTDBG
    CCCI_GIOPDU_DBGBLK_HEADER_T    *dbginfo_H;
#endif

    if (gio_port >= CCCI_GIOPDU_UNDESIGNATE_PORT)    gio_port = ccci_giopdu_flowctl.nextProcPort;


    //- BG task is processing in gpd linking, give up kick back
    ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] DL_goBCE I (%s)", ccci_giopdu_entry_string[entry-1]);
    if (entry & CCCI_GIOPDU_TX_GO_ENTRY_HISR_MASK)
    {
        if (ccci_giopdu_flowctl.startLinkMask)
        {
            if (hw_cmd_byte_copy_query_busy(BYTECOPY_UPS) == KAL_TRUE)
            {
                ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] DL_goBCE BCEHW Busy ");
            }
            else
            {
                ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] DL_goBCE BCEHW Idle XXX");
            }
            ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] DL_goBCE O (%s)", ccci_giopdu_entry_string[entry-1]);

            return    CCCI_GIOPDU_ERR_LINK_LOCK;
        }
    }

    //- To check lock status, only BG need to lock IRQ
    if (entry == CCCI_GIOPDU_TX_GO_ENTRY_BG_TASK)    int_mask = SaveAndSetIRQMask();
    if (ccci_giopdu_flowctl.startBCMask)
    {
        ret = CCCI_GIOPDU_ERR_BCE_LOCK;
    }
    else
    {
        for (i=0; i<MAX_CCCI_GIOPDU_PORT; i++)
        {
            if (gio_port >= MAX_CCCI_GIOPDU_PORT)
            {
                gio_port = 0;
            }
            //- To check waiting list available ??
            if (ccci_giopdu_ctlblk[gio_port].waiting_gpd_first)
            {
                //- To get free ringQ size
                CCCI_GIOPDU_RINGQ_GETPUSHAVAIL (ccci_giopdu_ctlblk[gio_port].tx_ctl, left, base);
                if (left)
                {
                    //- to lock BC resource
                    ccci_giopdu_flowctl.startBCMask |= (1 << gio_port);
                    ccci_giopdu_flowctl.nextProcPort = gio_port + 1;
//-                    ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] DL_goBCE M %08x", ccci_giopdu_flowctl.startBCMask);
                    break;
                }
                else
                {
                    //- To lack RingQ length
                    ccci_uart_port[ccci_gioport_2_uartport[gio_port]].write_flag    = 1;
                }
            }
            gio_port ++;
        }
        if (i == MAX_CCCI_GIOPDU_PORT)    ret = CCCI_GIOPDU_ERR_BCE_NOT_START;
    }
    if (entry == CCCI_GIOPDU_TX_GO_ENTRY_BG_TASK)    RestoreIRQMask(int_mask);
    if (ret)
    {
        if (hw_cmd_byte_copy_query_busy(BYTECOPY_UPS) == KAL_TRUE)
        {
            ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] DL_goBCE BCEHW Busy ");
        }
        else
        {
            ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] DL_goBCE BCEHW Idle XXX");
        }

        ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] DL_goBCE O (%s)", ccci_giopdu_entry_string[entry-1]);

        return ret;
    }

    p_wfirst    = gpd_lib_list_poll_ex (&ccci_giopdu_ctlblk[gio_port].waiting_gpd_list, &p_wlast);
    p_pfirst    = p_wfirst;
    ccci_giopdu_ctlblk[gio_port].waiting_gpd_first = 0;
    gpd_lib_iterator_create(&local_itr, &p_wfirst); // Initialize gpd_list struct

    ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] DL_goBCE *Wlist %08x %08x", p_wfirst, p_wlast);

    //- traverse
    max_input = CCCI_GIOPDU_GIO_ENABLE_TXMAXGPD2BCE(gio_port);
    ccci_dbg_go_BCE[0] = max_input;

    for (i=0; i<left; i++)
    {
        ccci_dbg_go_BCE[1] = i;
        node = gpd_lib_iterator_next(&local_itr);
        ccci_dbg_go_BCE[2] = (kal_uint32)node;

        if (node && max_input)
        {
            p_plast = node;
            ccci_dbg_go_BCE[3] = base;
            ptr_ringQ = ccci_giopdu_ctlblk[gio_port].tx_ringQ + base;
            ccci_dbg_go_BCE[4] = (kal_uint32)ptr_ringQ;
            tmp_ptr = ptr_ringQ->ptr_entry;
            tmp_len = gpd_lib_data_size(node);
            //- Debug : check D12
#ifdef CCCI_GIOPDU_EXTDBG
            dbginfo_H = (CCCI_GIOPDU_DBGBLK_HEADER_T*)(tmp_ptr - sizeof(CCCI_GIOPDU_DBGBLK_HEADER_T));
            if ((dbginfo_H->port != gio_port) || (dbginfo_H->avai_in != base))
            {
                CCCI_GIOPDU_ASSERT();
            }
            //- Debug : set D3E
            dbginfo_H->avai_out = base;
            tmp_end = tmp_ptr + tmp_len + 3;                //- BCE end address must be 4-bytes align
            tmp_end = (kal_uint8*)((kal_uint32)tmp_end & 0xFFFFFFFC);
            *tmp_end = CCCI_GIOPDU_DBG_ENDER;
            ccci_dbg_go_BCE[5] = (kal_uint32)tmp_end;
#endif
            //- write len in ringQ
            ptr_ringQ->len_entry = tmp_len;
            //- write len in BCE extend field
            gpd_lib_umts_setOutputAddr(node, tmp_ptr);

            output_addr = *((kal_uint32*)node+4);
            ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] DL_goBCE node %08x OutNode %08x OutTmp %08x", node, output_addr, tmp_ptr);
            if (output_addr == 0)
            {
                EXT_ASSERT (0, (kal_uint32)node, (kal_uint32)output_addr, (kal_uint32)tmp_ptr);
            }

#ifdef CCCI_UART_GIO_IT
            {
                //- memory copy here !!!
                bd_node        *ptr_bd_it;
                kal_uint8    *ptr_it;
                kal_uint32    len_it;
                kal_uint32    len_total_it = 0;
                kal_uint8    *tmp_last_it = tmp_ptr;

                ptr_bd_it = gpd_lib_umts_getFirstBD (node);
                while (ptr_bd_it)
                {
                    ptr_it = gpd_lib_umts_getBDDataPtr (ptr_bd_it);
                    len_it = gpd_lib_umts_getBDDataLen (ptr_bd_it);
                    len_total_it += len_it;

                    if (len_total_it > CCCI_GIOPDU_MAX_PDU_SIZE)
                        EXT_ASSERT (0, 0, 0, 0);

                    ccci_dbg_go_BCE[7] = (kal_uint32)ptr_it;
                    ccci_dbg_go_BCE[8] = (kal_uint32)tmp_ptr;
                    ccci_dbg_go_BCE[9] = len_it;
                    if ((ptr_it != NULL) && (len_it))
                    {
                        kal_mem_cpy(tmp_last_it, ptr_it, len_it);
                        tmp_last_it += len_it;
                    }
                    else
                    {
                        EXT_ASSERT (0, 0, 0, 0);
                    }

                    ptr_bd_it = gpd_lib_umts_nextBD(ptr_bd_it);
                }
            }
#endif

            max_input --;
            base ++;
            ccci_dbg_go_BCE[6] = max_input;
            if (base == ccci_giopdu_ctlblk[gio_port].tx_ctl->ringQ_len)
                base = 0;
        }
        else
        {
            break;
        }
    }

    //- break the gpd list and add residual gpd in waiting list
    //- to make processing list
    ccci_giopdu_ctlblk[gio_port].procRingQBaseNext = base;
    ptr_list = &(ccci_giopdu_ctlblk[gio_port].processing_gpd_list);
    gpd_lib_list_create ( ptr_list );
    gpd_lib_list_add_ex(ptr_list, p_pfirst, p_plast);
    ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] DL_goBCE *Plist %08x %08x", p_pfirst, p_plast);

#ifdef CCCI_GIOPDU_DEBUG_TRACE_DL0
    ccci_giopdu_ctlblk[gio_port].DL_proc += gpd_lib_size((gpd_node*)p_pfirst);
    ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] DL_proc : %d", ccci_giopdu_ctlblk[gio_port].DL_proc);
#endif

    //- to check waiting list
    if (node == 0)
    {
        //- we have no waiting gpd and (i != left)
        ccci_giopdu_ctlblk[gio_port].waiting_gpd_first = 0;
        ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] DL_goBCE *Wlist %08x %08x", 0, 0);
    }
    else
    {
        if (i == left)
        {
            //- need to get next node to check
            node_cut = gpd_lib_iterator_next(&local_itr);
        }

        node_cut = gpd_lib_iterator_cut(&local_itr);

        if (node_cut)
        {
            //- to make waiting list
            ptr_list = &(ccci_giopdu_ctlblk[gio_port].waiting_gpd_list);
            gpd_lib_list_create ( ptr_list );
            gpd_lib_list_add_ex(ptr_list, node_cut, p_wlast);
            ccci_giopdu_ctlblk[gio_port].waiting_gpd_first = node_cut;
            ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] DL_goBCE *Wlist %08x %08x", node_cut, p_wlast);
        }
        else
        {
            ccci_giopdu_ctlblk[gio_port].waiting_gpd_first = 0;
            ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] DL_goBCE *Wlist %08x %08x", 0, 0);
        }
    }

    ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] DL_goBCE%d : empty->%d, proc->%d, wi->%08x", gio_port, left, i, ccci_giopdu_ctlblk[gio_port].waiting_gpd_first);

    //- restore 0xFFFFFFFF for BCE DPG "END" format
    p_plast->w1.next_gpd_addr = (void*)0xFFFFFFFF;
    //- start BCE here
    ccci_uart_gio_start_BCE((void*)(p_pfirst));

    ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] DL_goBCE O (%s)", ccci_giopdu_entry_string[entry-1]);

    return CCCI_GIOPDU_NO_ERR;
}

/*************************************************************************
* FUNCTION
*  ccci_uart_gio_tx_send_data
*
* DESCRIPTION
*  The function is for gio users to send gpd ptr to HW medium.
*  there will be BD or GPD format(for CCCI driver, there will be GPD format confirmed by Stan Chen(UPS owner)
*
* PARAMETERS
*  port    -   the GIO port
*  gpd    -   the data ptr (can be BD/GPD) > physical queue space
*  option   -   no use
*  owner    -   the current task
*
* RETURNS
*  gpd ptr
*
*************************************************************************/
void* ccci_uart_gio_tx_send_data(DCL_DEV port, void* gpd_first, void* gpd_last, kal_uint32 option, module_type ownerid)
{
    kal_uint32  int_mask;
    kal_uint32    gio_port;
    kal_int32    ret;
    gpd_list    *ptr_list;

    if (!ccci_uart_gio_is_gio_port(port))
    {

        ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] DL_send(%d) : ERROR_0(%08x)", port, gpd_first);

        return  NULL;
    }

    gio_port = port - FIRST_CCCI_CCMNI_PORT;
    port -= FIRST_CCCI_UART_PORT;

    ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] DL_send%d I", gio_port);

#ifdef CCCI_GIOPDU_DEBUG_TRACE_DL0
    ccci_giopdu_ctlblk[gio_port].DL_in += gpd_lib_size((gpd_node*)gpd_first);
    ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] DL_in : %d", ccci_giopdu_ctlblk[gio_port].DL_in);
#endif

    if (ccci_uart_port[port].tx_owner != ownerid)
    {
        EXT_ASSERT(0, port + FIRST_CCCI_UART_PORT, ownerid, ccci_uart_port[port].tx_owner);
    }

    int_mask = SaveAndSetIRQMask();
    ccci_giopdu_flowctl.startLinkMask |= ((kal_uint32)1 << gio_port);
    RestoreIRQMask(int_mask);
    if (gpd_first)
    {
        //- To create gpd list
        ptr_list = &(ccci_giopdu_ctlblk[gio_port].waiting_gpd_list);
        if (!ccci_giopdu_ctlblk[gio_port].waiting_gpd_first)
        {
            gpd_lib_list_create ( ptr_list );     // Initialize gpd_list struct
            ccci_giopdu_ctlblk[gio_port].waiting_gpd_first = gpd_first;
        }
        //- To add new gpd to waiting list
        gpd_lib_list_add_ex(ptr_list, gpd_first, gpd_last); // add nodes into gpd_list

        ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] DL_send%d *Wlist %08x %08x", gio_port, ccci_giopdu_ctlblk[gio_port].waiting_gpd_first, gpd_last);
    }
    int_mask = SaveAndSetIRQMask();
    ccci_giopdu_flowctl.startLinkMask &= ~((kal_uint32)1 << gio_port);
    RestoreIRQMask(int_mask);

    ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] DL_send%d : wi->%08x", gio_port, ccci_giopdu_ctlblk[gio_port].waiting_gpd_list);

    ret = ccci_uart_gio_tx_go_BCE (CCCI_GIOPDU_UNDESIGNATE_PORT, CCCI_GIOPDU_TX_GO_ENTRY_BG_TASK);

    if (ret)
        ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] DL_send%d : %s", gio_port, ccci_giopdu_err_string[0-ret]);

    return NULL;
}

/*************************************************************************
* FUNCTION
*  ccci_uart_gio_tx_recycle_gpd
*
* DESCRIPTION
*  The function is for gio users to recyle the gpd ptr from HW medium.
*
* PARAMETERS
*  port    -   the GIO port
*  gpd    -   the data ptr
*  option   -   no use
*  owner    -   the current task
*
* RETURNS
*  gpd ptr
*
*************************************************************************/
void* ccci_uart_gio_tx_recycle_gpd(DCL_DEV port, kal_uint32 option, module_type ownerid)
{
    kal_uint32    gio_port, hisr_port;
    kal_uint32    int_mask;
    kal_int32    ret;
    gpd_node    *p_rfirst = 0;
    gpd_node    *p_rlast;
    gpd_list    *ptr_recylist;

    if (!ccci_uart_gio_is_gio_port(port))
    {
        return  NULL;
    }

    gio_port = port - FIRST_CCCI_CCMNI_PORT;
    port -= FIRST_CCCI_UART_PORT;

    if (ccci_uart_port[port].tx_owner != ownerid)
    {
        EXT_ASSERT(0, port + FIRST_CCCI_UART_PORT, ownerid, ccci_uart_port[port].tx_owner);
    }

    ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] DL_recycle I");

    if ( ccci_uart_gio_task_send_retry & (1 << gio_port) )
    {
        kal_uint32 savedMask;
    	
        ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] DL_recycle tx start");
    	
        hisr_port = ccci_gioport_2_uartport[gio_port];
        ccci_uart_send_message_to_ap_retry(hisr_port, ccci_uart_port[hisr_port].tx_channel, CCCI_UART_SEND_RETRY);
        
        savedMask = SaveAndSetIRQMask();
        ccci_uart_gio_task_send_retry &= ~ (1 << gio_port);
        RestoreIRQMask(savedMask);
        
        ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] DL_recycle tx done");
    }

    if (CCCI_GIOPDU_GIO_ENABLE_TXMERGERECYCLE (gio_port))
    {
        gio_port = 0;
    }

    //- To check if there are recycle gpd list ewaiting to recycle
    if (ccci_giopdu_ctlblk[gio_port].recycle_gpd_first)
    {
        ptr_recylist = &ccci_giopdu_ctlblk[gio_port].recycle_gpd_list;
        int_mask = SaveAndSetIRQMask();
        p_rfirst = gpd_lib_list_poll_ex (ptr_recylist, &p_rlast);
        ccci_giopdu_ctlblk[gio_port].recycle_gpd_first    = 0;
        ccci_giopdu_ctlblk[gio_port].recycle_msg        = 0;
        RestoreIRQMask(int_mask);
    }

    if (p_rfirst)
    {
        ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] DL_recycle->%08x)", p_rfirst);
    }
    else
    {
        ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] DL_recycle (NO GPD)");
    }

    if (CCCI_GIOPDU_GIO_ENABLE_TXBCEKICKBACK(gio_port))
    {
        ret = ccci_uart_gio_tx_go_BCE (CCCI_GIOPDU_UNDESIGNATE_PORT, CCCI_GIOPDU_TX_GO_ENTRY_BG_TASK);

        if (ret)
            ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] DL_recy%d : %s", gio_port, ccci_giopdu_err_string[0-ret]);
    }

#ifdef CCCI_GIOPDU_DEBUG_TRACE_DL0
    ccci_giopdu_ctlblk[gio_port].DL_out += gpd_lib_size((gpd_node*)p_rfirst);
    ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] DL_out : %d", ccci_giopdu_ctlblk[gio_port].DL_out);
#endif

    ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] DL_recycle O");

    return p_rfirst;
}

#ifdef CCCI_GIOPDU_UPLINK_CCCI_FLOWCTL
/*************************************************************************
* FUNCTION
*  ccci_uart_gio_rx_load_gpd_0
*
* DESCRIPTION
*  The function is for gio users to load gpd ptr to received waiting list.
*
* PARAMETERS
*  port    -   the GIO port
*  gpd    -   the data ptr
*  option   -   no use
*  owner    -   the current task
*
* RETURNS
*  gpd ptr
*
*************************************************************************/
void* ccci_uart_gio_rx_load_gpd_0(DCL_DEV port, void* gpd_first, void* gpd_last, kal_uint32 option, module_type ownerid)
{
    kal_uint32    gio_port, left, base;
    gpd_list    *ptr_wllist;

#ifdef CCCI_UART_GIO_IT
    kal_uint32 int_mask;
#endif

    if (!ccci_uart_gio_is_gio_port(port) || (gpd_first == NULL))
    {
        ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] UL_load(%d) : ERROR_0 (%08x)", port, gpd_first);

        return gpd_first;
    }
    gio_port = port - FIRST_CCCI_CCMNI_PORT;
    port -= FIRST_CCCI_UART_PORT;

    if (ccci_uart_port[port].rx_owner != ownerid)
    {
        EXT_ASSERT(0, port + FIRST_CCCI_UART_PORT, ownerid, ccci_uart_port[port].rx_owner);
    }
    CCCI_GIOPDU_RINGQ_GETPULLAVAIL(ccci_giopdu_ctlblk[gio_port].rx_ctl, left, base);

    //- To create gpd list if needed
    ptr_wllist = &(ccci_giopdu_ctlblk[gio_port].waitload_gpd_list);
    if (!ccci_giopdu_ctlblk[gio_port].waitload_gpd_first)
    {
        gpd_lib_list_create ( ptr_wllist );                                 // Initialize gpd_list struct
        ccci_giopdu_ctlblk[gio_port].waitload_gpd_first = gpd_first;
    }
    gpd_lib_list_add_ex(ptr_wllist, gpd_first, gpd_last);                     // add nodes into gpd_list

    ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] UL_load%d : wait to recv->%d", gio_port, left);

    ccci_uart_gio_rx_preload_0 (gio_port, 1);

    //- Notify user to receive data
    if (left)
    {
#ifdef CCCI_UART_GIO_IT
        int_mask = SaveAndSetIRQMask();
        //- let timer cb to send user ilm
        ccci_giopdu_flowctl.ilmRxBGFlag |= (1 << port);
        RestoreIRQMask(int_mask);
#else
        ccci_uart_send_message_to_user (port, 0, ccci_uart_port[port].rx_owner);
#endif
    }

    left = base; //- avoid warning (set but not used [-Wunused-but-set-variable])

    return NULL;
}

/*************************************************************************
* FUNCTION
*  ccci_uart_gio_rx_recv_data_0
*
* DESCRIPTION
*  The function is for gio users to receive gpd list.
*
* PARAMETERS
*  port    -   the GIO port
*  option   -   no use
*  owner    -   the current task
*
* RETURNS
*  gpd ptr
*
*************************************************************************/
void* ccci_uart_gio_rx_recv_data_0(DCL_DEV port, kal_uint32 option, module_type ownerid)
{
    kal_uint32    i, gio_port, left, base, int_mask;
    kal_uint32    tmp_len;
    kal_uint8    *tmp_ptr;
    gpd_node    *node;
    gpd_node    *node_cut;
    gpd_node    *p_wlfirst;
    gpd_node    *p_wllast;
    gpd_node    *p_rvfirst;
    gpd_list    *ptr_wllist;
    gpd_itr        local_itr;

    CCCI_GIOPDU_RINGQ_T    *ptr_ringQ;

#ifdef CCCI_GIOPDU_EXTDBG
    CCCI_GIOPDU_DBGBLK_HEADER_T    *dbginfo_H;
    CCCI_GIOPDU_DBGBLK_FOOTER_T    *dbginfo_L;
#endif

    if (!ccci_uart_gio_is_gio_port(port))
    {
        return  NULL;
    }
    gio_port = port - FIRST_CCCI_CCMNI_PORT;
    port -= FIRST_CCCI_UART_PORT;

    if (ccci_uart_port[port].rx_owner != ownerid)
    {
        EXT_ASSERT(0, port + FIRST_CCCI_UART_PORT, ownerid, ccci_uart_port[port].rx_owner);
    }

    int_mask = SaveAndSetIRQMask();
    CCCI_GIOPDU_RINGQ_GETPULLAVAIL(ccci_giopdu_ctlblk[gio_port].rx_ctl, left, base);
    if (left == 0)
    {
        //- only inavailable need to send message to user
        ccci_uart_port[port].flag = 1;
    }
    RestoreIRQMask(int_mask);

    ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] UL_recv%d I: QR->%d", gio_port, left);

    if (left == 0)
    {
        ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] UL_recv%d O: No data to recv", gio_port);

        return NULL;
    }
    ptr_wllist = &(ccci_giopdu_ctlblk[gio_port].waitload_gpd_list);
    if (!ccci_giopdu_ctlblk[gio_port].waitload_gpd_first)
    {
        ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] UL_recv%d O: No Wload", gio_port);

        return NULL;
    }
    p_wlfirst    = gpd_lib_list_poll_ex (ptr_wllist, &p_wllast);
    if (p_wlfirst != ccci_giopdu_ctlblk[gio_port].waitload_gpd_first)
    {
        EXT_ASSERT (0, 0, 0, 0);
    }

    //- traverse : to fill length of data field and copy content to BD
    gpd_lib_iterator_create(&local_itr, &p_wlfirst);
    for (i=0; i<left; i++)
    {
        node = gpd_lib_iterator_next(&local_itr);
        if (node)
        {
            ptr_ringQ    = ccci_giopdu_ctlblk[gio_port].rx_ringQ + base;
            tmp_ptr        = ptr_ringQ->ptr_entry;
            tmp_len     = ptr_ringQ->len_entry;

#ifdef CCCI_GIOPDU_EXTDBG
            //- Debug : check D123E
            dbginfo_H = (CCCI_GIOPDU_DBGBLK_HEADER_T*)(tmp_ptr) - 1;
            dbginfo_L = (CCCI_GIOPDU_DBGBLK_FOOTER_T*)(tmp_ptr + CCCI_GIOPDU_MAX_PDU_SIZE);
            if ( (dbginfo_H->port != gio_port) || (dbginfo_H->avai_in != base) ||
                    (dbginfo_H->avai_out != base) || (*(tmp_ptr + tmp_len) != CCCI_GIOPDU_DBG_ENDER) ||
                    (dbginfo_H->header != CCCI_GIOPDU_DBG_HEADER) || (dbginfo_L->footer != CCCI_GIOPDU_DBG_FOOTER)
               )
            {
                CCCI_GIOPDU_ASSERT();
            }
            //- Debug : set D4 / reset D2
            dbginfo_H->avai_in    = CCCI_GIOPDU_DBG_INVALID_4B;
            dbginfo_H->read_out    = base;
#endif

            //- to read RinQ content (ptr / size)
            gpd_lib_data_setSize(node, tmp_len);
            //- memory cpy here!
            kal_mem_cpy (gpd_lib_data_getAddr(node), tmp_ptr, tmp_len);
            base ++;
            if (base == ccci_giopdu_ctlblk[gio_port].rx_ctl->ringQ_len)
                base = 0;
        }
        else
        {
            break;
        }
    }

    p_rvfirst = p_wlfirst;

    CCCI_GIOPDU_ADJUST_RX_READOUT(gio_port, base);

    if (node == NULL)
    {
        //- avail > load request
        ccci_giopdu_ctlblk[gio_port].waitload_gpd_first = NULL;
    }
    else if (i == left)
    {
        //- avail <= load request
        node_cut = gpd_lib_iterator_next(&local_itr);
        if (node_cut)
        {
            //- break the loading and wait load list
            if (node_cut != gpd_lib_iterator_cut(&local_itr))
            {
                EXT_ASSERT  (0, 0, 0, 0);
            }
            //- create loading list
            gpd_lib_list_create ( ptr_wllist );
            gpd_lib_list_add_ex(ptr_wllist, node_cut, p_wllast);

            ccci_giopdu_ctlblk[gio_port].waitload_gpd_first = node_cut;
        }
        else
        {
            //- avail > load request
            ccci_giopdu_ctlblk[gio_port].waitload_gpd_first = NULL;

            ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] UL_recv%d : proc->%d (GPD_NULL)", gio_port, i);
        }

    }
    else
    {
        EXT_ASSERT  (0, 0, 0, 0);
    }


    if (ccci_giopdu_ctlblk[gio_port].waitload_gpd_first)
    {
        ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] UL_recv%d : left->%d, done->%d, rd_out->%d, Wload->%08x", gio_port, left, i, ccci_giopdu_ctlblk[gio_port].rx_ctl->read_out, ccci_giopdu_ctlblk[gio_port].waitload_gpd_first);
    }
    else
    {
        ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] UL_recv%d : left->%d, done->%d, rd_out->%d, (GPD_NULL)", gio_port, left, i, ccci_giopdu_ctlblk[gio_port].rx_ctl->read_out);
    }

    ccci_uart_gio_rx_preload_0 (gio_port, 1);

    //- send message to AP
    //- ccci_uart_send_message_to_ap_retry (port, ccci_uart_port[port].rx_ack_channel, CCCI_UART_SEND_RETRY);

    ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] UL_recv%d O", gio_port);

    return p_rvfirst;
}
#endif //- CCCI_GIOPDU_UPLINK_CCCI_FLOWCTL

/*************************************************************************
* FUNCTION
*  ccci_uart_gio_tx_flush_gpd
*
* DESCRIPTION
*  unsupport feature.
*
* PARAMETERS
*  port    -   the GIO port
*  option   -   no use
*  owner    -   the current task
*
* RETURNS
*  gpd ptr
*
*************************************************************************/
void* ccci_uart_gio_tx_flush_gpd (DCL_DEV port, kal_uint32 option, module_type owner)
{
    return NULL;
}


#ifdef CCCI_GIOPDU_UPLINK_FLC_FLOWCTL
#ifndef CCCI_GIOPDU_UPLINK_PLANB_FLOWCTL
/*************************************************************************
* FUNCTION
*  ccci_uart_gio_rx_load_gpd_XB
*
* DESCRIPTION
*
*
* PARAMETERS
*  port    -   the GIO port
*  option   -   no use
*  owner    -   the current task
*
* RETURNS
*  status (success or fail)
*
*************************************************************************/
void* ccci_uart_gio_rx_load_gpd_XB (DCL_DEV port, void* gpd_first, void* gpd_last, kal_uint32 option, module_type ownerid)
{
    kal_uint32    i, gio_port, left, base, read_out, len;
    kal_uint32    tmp_len;
    kal_uint8    *tmp_ptr;
    gpd_node    *node = NULL;    //- avoid warning (may be used uninitialized in this function [-Wuninitialized])
    gpd_node    *node_cut;
    gpd_node    *p_wlfirst;
    gpd_node    *p_wllast;
    gpd_list    *ptr_llist;
    gpd_itr        local_itr;

    CCCI_GIOPDU_RINGQ_T    *ptr_ringQ;

#ifdef CCCI_GIOPDU_EXTDBG
    CCCI_GIOPDU_DBGBLK_HEADER_T    *dbginfo_H;
    CCCI_GIOPDU_DBGBLK_FOOTER_T    *dbginfo_L;
#endif

    if (!ccci_uart_gio_is_gio_port(port) || (gpd_first == NULL))
    {
        ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] UL_load(%d) : ERROR_0 (%08x)", port, gpd_first);

        EXT_ASSERT (0, 0, 0, 0) ;
    }
    gio_port = port - FIRST_CCCI_CCMNI_PORT;
    port -= FIRST_CCCI_UART_PORT;

    if (ccci_uart_port[port].rx_owner != ownerid)
    {
        EXT_ASSERT(0, port + FIRST_CCCI_UART_PORT, ownerid, ccci_uart_port[port].rx_owner);
    }

#ifdef CCCI_GIOPDU_DEBUG_TRACE
    {
        kal_uint32 left, base;
        CCCI_GIOPDU_RINGQ_GETPULLAVAIL(ccci_giopdu_ctlblk[gio_port].rx_ctl, left, base);
        ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] UL_load%d : wait to recv->%d", gio_port, left);
        base = base; //- avoid warning
    }
#endif

    CCCI_GIOPDU_RINGQ_GETLOADAVAIL(ccci_giopdu_ctlblk[gio_port].rx_ctl, left, base, read_out, len);

    if (!left)
        EXT_ASSERT (0, 0, 0, 0);

    //- traverse
    p_wlfirst    = gpd_first;
    p_wllast    = gpd_last;
    gpd_lib_iterator_create(&local_itr, &p_wlfirst);                             // Initialize gpd_list struct
    for (i=0; i<left; i++)
    {
        node = gpd_lib_iterator_next(&local_itr);
        if (node)
        {
            ptr_ringQ = ccci_giopdu_ctlblk[gio_port].rx_ringQ + base;
            //- to write RinQ content (ptr / size)
            tmp_ptr = gpd_lib_data_getAddr(node);
            tmp_len = gpd_lib_data_size(node);
            ptr_ringQ->ptr_entry = tmp_ptr;
            ptr_ringQ->len_entry = tmp_len;


#ifdef CCCI_GIOPDU_EXTDBG
            //- Debug : set D12
            dbginfo_H = (CCCI_GIOPDU_DBGBLK_HEADER_T*)(tmp_ptr) - 1;
            dbginfo_H->port        = gio_port;
            dbginfo_H->avai_in    = base;
            dbginfo_H->header     = CCCI_GIOPDU_DBG_HEADER;
            dbginfo_L = (CCCI_GIOPDU_DBGBLK_FOOTER_T*)(tmp_ptr + CCCI_GIOPDU_MAX_PDU_SIZE);
            dbginfo_L->footer     = CCCI_GIOPDU_DBG_FOOTER;
#endif

            base ++;
            if (base == len)
                base = 0;
        }
        else
        {
            break;
        }
    }

    ptr_llist = &(ccci_giopdu_ctlblk[gio_port].loading_gpd_list);
    if (!ccci_giopdu_ctlblk[gio_port].loading_gpd_first)
    {
        gpd_lib_list_create ( ptr_llist );
        ccci_giopdu_ctlblk[gio_port].loading_gpd_first = p_wlfirst;
    }

    if (node == NULL)
    {
        //- avail > load request, no need to cut interator
        gpd_lib_list_add_ex(ptr_llist, p_wlfirst, p_wllast);
    }
    else if (i == left)
    {
        //- avail <= load request
        node_cut = gpd_lib_iterator_next(&local_itr);
        if (node_cut)
        {
            //- avail < load request
            EXT_ASSERT  (0, 0, 0, 0);
        }
        else
        {
            //- left == num of wait load, no need to cut interator
            gpd_lib_list_add_ex(ptr_llist, p_wlfirst, p_wllast);
        }
    }
    else
    {
        EXT_ASSERT  (0, 0, 0, 0);
    }
    //- adjust value of avai_in
    CCCI_GIOPDU_ADJUST_RX_AVAIIN (gio_port, base);

    ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] UL_pload%d : in->%d", gio_port, base);

    {
        ccci_uart_send_message_to_ap_retry (port, ccci_uart_port[port].rx_ack_channel, CCCI_UART_SEND_RETRY);

        ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] UL_pload%d : Send CCIF", gio_port);

    }

    return NULL;
}
#endif //- !CCCI_GIOPDU_UPLINK_PLANB_FLOWCTL

#ifdef CCCI_GIOPDU_UPLINK_PLANB_FLOWCTL
/*************************************************************************
* FUNCTION
*  ccci_uart_gio_rx_preload_X
*
* DESCRIPTION
*
*
* PARAMETERS
*  port    -   the GIO port
*  option   -   no use
*  owner    -   the current task
*
* RETURNS
*  status (success or fail)
*
*************************************************************************/
void ccci_uart_gio_rx_preload_X (kal_uint32 gio_port, kal_bool isSendMsg)
{
    kal_uint32    i, port, left, base, read_out, len, max_in;
    kal_uint32    tmp_len;
    kal_uint8    *tmp_ptr;
    gpd_node    *node;
    gpd_node    *node_cut;
    gpd_node    *p_wlfirst;
    gpd_node    *p_wllast;
    gpd_list    *ptr_wllist;
    gpd_list    *ptr_llist;
    gpd_itr        local_itr;

    CCCI_GIOPDU_RINGQ_T    *ptr_ringQ;

#ifdef CCCI_GIOPDU_EXTDBG
    CCCI_GIOPDU_DBGBLK_HEADER_T    *dbginfo_H;
    CCCI_GIOPDU_DBGBLK_FOOTER_T    *dbginfo_L;
#endif

    CCCI_GIOPDU_RINGQ_GETLOADAVAIL(ccci_giopdu_ctlblk[gio_port].rx_ctl, left, base, read_out, len);

    if (!left || !ccci_giopdu_ctlblk[gio_port].waitload_gpd_first)
        return;

    max_in = CCCI_GIOPDU_GIO_ENABLE_RXMAXPRELOAD(gio_port);

    if (max_in)
    {
        if (base || read_out)
        {
            if ((len - max_in) >= left)
            {
                //- enough ringQ space
                return;
            }
            else
            {
                left = max_in - (len - left) + 1;
            }
        }
        else
        {
            //- init state
            left = max_in;
        }
    }

    if (!left)
    {
        ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] UL_pload%d : No left space", gio_port);

        return;
    }

    //- get the gpd list of wait load
    ptr_wllist    = &(ccci_giopdu_ctlblk[gio_port].waitload_gpd_list);
    p_wlfirst    = gpd_lib_list_poll_ex (ptr_wllist, &p_wllast);
    if (ccci_giopdu_ctlblk[gio_port].waitload_gpd_first != p_wlfirst)
        EXT_ASSERT(0, 0, 0, 0);


    //- traverse
    gpd_lib_iterator_create(&local_itr, &p_wlfirst);                             // Initialize gpd_list struct
    for (i=0; i<left; i++)
    {
        node = gpd_lib_iterator_next(&local_itr);
        if (node)
        {
            ptr_ringQ = ccci_giopdu_ctlblk[gio_port].rx_ringQ + base;
            //- to write RinQ content (ptr / size)
            tmp_ptr = gpd_lib_data_getAddr(node);
            tmp_len = gpd_lib_data_size(node);
            ptr_ringQ->ptr_entry = tmp_ptr;
            ptr_ringQ->len_entry = tmp_len;


#ifdef CCCI_GIOPDU_EXTDBG
            //- Debug : set D12
            dbginfo_H = (CCCI_GIOPDU_DBGBLK_HEADER_T*)(tmp_ptr) - 1;
            dbginfo_H->port        = gio_port;
            dbginfo_H->avai_in    = base;
            dbginfo_H->header     = CCCI_GIOPDU_DBG_HEADER;
            dbginfo_L = (CCCI_GIOPDU_DBGBLK_FOOTER_T*)(tmp_ptr + CCCI_GIOPDU_MAX_PDU_SIZE);
            dbginfo_L->footer     = CCCI_GIOPDU_DBG_FOOTER;
#endif

            base ++;
            if (base == len)
                base = 0;
        }
        else
        {
            break;
        }
    }

    ptr_llist = &(ccci_giopdu_ctlblk[gio_port].loading_gpd_list);
    if (!ccci_giopdu_ctlblk[gio_port].loading_gpd_first)
    {
        gpd_lib_list_create ( ptr_llist );
        ccci_giopdu_ctlblk[gio_port].loading_gpd_first = p_wlfirst;
    }

    if (node == NULL)
    {
        //- avail > load request, no need to cut interator
        gpd_lib_list_add_ex(ptr_llist, p_wlfirst, p_wllast);
        //- to indicate there are no wait load list
        ccci_giopdu_ctlblk[gio_port].waitload_gpd_first = NULL;
    }
    else if (i == left)
    {
        //- avail <= load request
        node_cut = gpd_lib_iterator_next(&local_itr);
        if (node_cut)
        {
            //- avail < load request
            //- break the loading and wait load list
            if (node_cut != gpd_lib_iterator_cut(&local_itr))
            {
                EXT_ASSERT  (0, 0, 0, 0);
            }
            //- append to loading list
            gpd_lib_list_add_ex(ptr_llist, p_wlfirst, node);
            //- create wait load list and append residual gpd
            gpd_lib_list_create ( ptr_wllist );
            gpd_lib_list_add_ex (ptr_wllist, node_cut, p_wllast);
            ccci_giopdu_ctlblk[gio_port].waitload_gpd_first = node_cut;
        }
        else
        {
            //- left == num of wait load, no need to cut interator
            gpd_lib_list_add_ex(ptr_llist, p_wlfirst, p_wllast);
            //- to indecate there are no wait load list
            ccci_giopdu_ctlblk[gio_port].waitload_gpd_first = NULL;
        }

    }
    else
    {
        EXT_ASSERT  (0, 0, 0, 0);
    }
    //- adjust value of avai_in
    CCCI_GIOPDU_ADJUST_RX_AVAIIN (gio_port, base);

    ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] UL_pload%d : in->%d", gio_port, base);

    if (isSendMsg)
    {
        port = ccci_gioport_2_uartport[gio_port];
        ccci_uart_send_message_to_ap_retry (port, ccci_uart_port[port].rx_ack_channel, CCCI_UART_SEND_RETRY);

        ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] UL_pload%d : Send CCIF", gio_port);

    }

    return;
}
#endif //- CCCI_GIOPDU_UPLINK_PLANB_FLOWCTL
/*************************************************************************
* FUNCTION
*  ccci_uart_gio_rx_recv_data_X
*
* DESCRIPTION
*  The function is for gio users to receive gpd ptr from HW medium.
*
* PARAMETERS
*  port    -   the GIO port
*  option   -   no use
*  owner    -   the current task
*
* RETURNS
*  gpd ptr
*
*************************************************************************/

void* ccci_uart_gio_rx_recv_data_X (DCL_DEV port, kal_uint32 option, module_type ownerid)
{
    kal_uint32    i, gio_port, left, base, int_mask;
    kal_uint32    tmp_len;
    kal_uint8    *tmp_ptr;
    gpd_node    *node;
    gpd_node    *node_cut;
    gpd_node    *p_lfirst;
    gpd_node    *p_llast;
    gpd_node    *p_rvfirst;
    gpd_list    *ptr_llist;
    gpd_itr        local_itr;

    CCCI_GIOPDU_RINGQ_T    *ptr_ringQ;

#ifdef CCCI_GIOPDU_EXTDBG
    CCCI_GIOPDU_DBGBLK_HEADER_T    *dbginfo_H;
    CCCI_GIOPDU_DBGBLK_FOOTER_T    *dbginfo_L;
#endif

    if (!ccci_uart_gio_is_gio_port(port))
    {
        return  NULL;
    }
    gio_port = port - FIRST_CCCI_CCMNI_PORT;
    port -= FIRST_CCCI_UART_PORT;

    if (ccci_uart_port[port].rx_owner != ownerid)
    {
        EXT_ASSERT(0, port + FIRST_CCCI_UART_PORT, ownerid, ccci_uart_port[port].rx_owner);
    }

    int_mask = SaveAndSetIRQMask();
    CCCI_GIOPDU_RINGQ_GETPULLAVAIL(ccci_giopdu_ctlblk[gio_port].rx_ctl, left, base);
    if (left == 0)
    {
        //- only inavailable need to send message to user
        ccci_uart_port[port].flag = 1;
    }
    RestoreIRQMask(int_mask);

    ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] UL_recv%d I: QR->%d", gio_port, left);

    if (left == 0)
    {
        ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] UL_recv%d O: No data to recv", gio_port);

        return NULL;
    }

    ptr_llist = &(ccci_giopdu_ctlblk[gio_port].loading_gpd_list);
    if (!ccci_giopdu_ctlblk[gio_port].loading_gpd_first)
    {
        EXT_ASSERT (0, 0, 0, 0);
    }

    p_lfirst    = gpd_lib_list_poll_ex (ptr_llist, &p_llast);
    if (p_lfirst != ccci_giopdu_ctlblk[gio_port].loading_gpd_first)
    {
        EXT_ASSERT (0, 0, 0, 0);
    }

    //- traverse : to fill length of data field
    gpd_lib_iterator_create(&local_itr, &p_lfirst);
    for (i=0; i<left; i++)
    {
        node = gpd_lib_iterator_next(&local_itr);
        if (node)
        {
            ptr_ringQ = ccci_giopdu_ctlblk[gio_port].rx_ringQ + base;
            tmp_ptr = ptr_ringQ->ptr_entry;
            tmp_len = ptr_ringQ->len_entry;

#ifdef CCCI_GIOPDU_EXTDBG
            //- Debug : check D123E
            dbginfo_H = (CCCI_GIOPDU_DBGBLK_HEADER_T*)(tmp_ptr) - 1;
            dbginfo_L = (CCCI_GIOPDU_DBGBLK_FOOTER_T*)(tmp_ptr + CCCI_GIOPDU_MAX_PDU_SIZE);
            if ( (dbginfo_H->port != gio_port) || (dbginfo_H->avai_in != base) ||
                    (dbginfo_H->avai_out != base) || (*(tmp_ptr + tmp_len) != CCCI_GIOPDU_DBG_ENDER) ||
                    (dbginfo_H->header != CCCI_GIOPDU_DBG_HEADER) || (dbginfo_L->footer != CCCI_GIOPDU_DBG_FOOTER)
               )
            {
                CCCI_GIOPDU_ASSERT();
            }
            //- Debug : set D4 / reset D2
            dbginfo_H->avai_in    = CCCI_GIOPDU_DBG_INVALID_4B;
            dbginfo_H->read_out    = base;
#endif

            //- to read RinQ content(size) and fill in gpd filed
            gpd_lib_data_setSize(node, tmp_len);

            base ++;
            if (base == ccci_giopdu_ctlblk[gio_port].rx_ctl->ringQ_len)
                base = 0;
        }
        else
        {
            break;
        }
    }

    p_rvfirst = p_lfirst;
    CCCI_GIOPDU_ADJUST_RX_READOUT(gio_port, base);

    if (node == NULL)
    {
        //- avail > load request
        ccci_giopdu_ctlblk[gio_port].loading_gpd_first = NULL;
    }
    else if (i == left)
    {
        //- avail <= load request
        node_cut = gpd_lib_iterator_next(&local_itr);
        if (node_cut)
        {
            //- avail < load request
            //- break the loading and wait load list
            if (node_cut != gpd_lib_iterator_cut(&local_itr))
            {
                EXT_ASSERT  (0, 0, 0, 0);
            }
            //- create loading list
            gpd_lib_list_create ( ptr_llist );
            gpd_lib_list_add_ex(ptr_llist, node_cut, p_llast);

            ccci_giopdu_ctlblk[gio_port].loading_gpd_first = node_cut;
        }
        else
        {
            //- avail == load request
            ccci_giopdu_ctlblk[gio_port].loading_gpd_first = NULL;
        }

    }
    else
    {
        EXT_ASSERT  (0, 0, 0, 0);
    }

    if (ccci_giopdu_ctlblk[gio_port].loading_gpd_first)
    {
        ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] UL_recv%d : left->%d, done->%d, rd_out->%d, loading->%08x", gio_port, left, i, ccci_giopdu_ctlblk[gio_port].rx_ctl->read_out, ccci_giopdu_ctlblk[gio_port].loading_gpd_first);
    }
    else
    {
        ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] UL_recv%d : left->%d, done->%d, rd_out->%d, (GPD_NULL)", gio_port, left, i, ccci_giopdu_ctlblk[gio_port].rx_ctl->read_out);
    }

#ifdef CCCI_GIOPDU_UPLINK_PLANB_FLOWCTL
    ccci_uart_gio_rx_preload_X (gio_port, 0);
#endif
    //- send message to AP
    ccci_uart_send_message_to_ap_retry (port, ccci_uart_port[port].rx_ack_channel, CCCI_UART_SEND_RETRY);

    return p_rvfirst;
}

#ifdef CCCI_GIOPDU_UPLINK_PLANB_FLOWCTL
/*************************************************************************
* FUNCTION
*  ccci_uart_gio_rx_load_gpd_X
*
* DESCRIPTION
*  The function is for gio users to load gpd ptr to HW medium.
*
* PARAMETERS
*  port    -   the GIO port
*  gpd    -   the data ptr
*  option   -   no use
*  owner    -   the current task
*
* RETURNS
*  gpd ptr
*
*************************************************************************/
void* ccci_uart_gio_rx_load_gpd_X (DCL_DEV port, void* gpd_first, void* gpd_last, kal_uint32 option, module_type ownerid)
{
    kal_uint32    gio_port;
    gpd_list    *ptr_wllist;
    gpd_itr        local_itr;

    CCCI_GIOPDU_RINGQ_T    *ptr_ringQ;

    if (!ccci_uart_gio_is_gio_port(port) || (gpd_first == NULL))
    {
        ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] UL_load(%d) : ERROR_0 (%08x)", port, gpd_first);

        return  gpd_first;
    }
    gio_port = port - FIRST_CCCI_CCMNI_PORT;
    port -= FIRST_CCCI_UART_PORT;

    if (ccci_uart_port[port].rx_owner != ownerid)
    {
        EXT_ASSERT(0, port + FIRST_CCCI_UART_PORT, ownerid, ccci_uart_port[port].rx_owner);
    }

    ptr_wllist = &(ccci_giopdu_ctlblk[gio_port].waitload_gpd_list);

#ifdef CCCI_GIOPDU_UPLINK_PLANB_FLOWCTL
    if (!ccci_giopdu_ctlblk[gio_port].waitload_gpd_first)
    {
        //- create wait_load_list
        gpd_lib_list_create ( ptr_wllist );                                 // Initialize gpd_list struct
        ccci_giopdu_ctlblk[gio_port].waitload_gpd_first = gpd_first;
    }
#endif

    gpd_lib_list_add_ex (ptr_wllist, gpd_first, gpd_last);                     // add nodes into gpd_list

#ifdef CCCI_GIOPDU_DEBUG_TRACE
    {
        kal_uint32 left, base;
        CCCI_GIOPDU_RINGQ_GETPULLAVAIL(ccci_giopdu_ctlblk[gio_port].rx_ctl, left, base);
        ___CCCI_UART_GIO_TRACE(MOD_TST, "[CCCI] UL_load%d : wait to recv->%d", gio_port, left);
    }
#endif

    ccci_uart_gio_rx_preload_X (gio_port, 1);

    return NULL;

}
#endif //- CCCI_GIOPDU_UPLINK_PLANB_FLOWCTL

#endif //- CCCI_GIOPDU_UPLINK_FLC_FLOWCTL
/*************************************************************************
* FUNCTION
*  ccci_uart_gio_rx_load_null_gpd
*
* DESCRIPTION
*  unsupport feature
*
* PARAMETERS
*  port    -   the GIO port
*  gpd    -   the data ptr
*  option   -   no use
*  owner    -   the current task
*
* RETURNS
*  None
*
*************************************************************************/
void ccci_uart_gio_load_dummy_gpd(DCL_DEV port, void* TX_gpd, kal_uint32 TX_size, void* RX_gpd, kal_uint32 RX_size)
{
    return;
}


/*************************************************************************
* FUNCTION
*  ccci_uart_gio_rx_flush_gpd
*
* DESCRIPTION
*  unsupport feature
*
* PARAMETERS
*  port    -   the GIO port
*  option   -   no use
*  owner    -   the current task
*
* RETURNS
*  gpd ptr
*
*************************************************************************/
void* ccci_uart_gio_rx_flush_gpd(DCL_DEV port, kal_uint32 option, module_type owner)
{
    return NULL;
}

#endif //- CCCI_UART_GIO

/*************************************************************************
* FUNCTION
*  UART_Handler
*
* DESCRIPTION
*  This is an the new hal function for upper user.
*
* PARAMETERS
*  port    -   no use
*  owner   -   no use
*  func    -   no use
*
* RETURNS
*  none
*
*************************************************************************/
DCL_STATUS CCCI_UART_Handler(DCL_DEV dev,DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
    kal_bool    return_flag = KAL_FALSE;
    DCL_STATUS    return_status = STATUS_OK;

    switch (cmd)
    {
    case SIO_CMD_INIT:
    {
        UART_CTRL_INIT_T* prCtrlInit;
        prCtrlInit = &(data->rUARTCtrlInit);
        UART_DriverInit(dev,(module_type)(prCtrlInit->u4Flag));
    }
    break;

    case SIO_CMD_OPEN:
    {
        UART_CTRL_OPEN_T* prCtrlOpen;
        prCtrlOpen = &(data->rUARTCtrlOPEN);
        return_flag =ccci_uart_open(dev, (module_type)(prCtrlOpen->u4OwenrId));
        if(return_flag == KAL_FALSE)
            return_status = STATUS_FAIL;
    }
    break;

    case SIO_CMD_CLOSE:
    {
        UART_CTRL_CLOSE_T* prCtrlClose;
        prCtrlClose = &(data->rUARTCtrlCLOSE);
        ccci_uart_close(dev, (module_type)(prCtrlClose->u4OwenrId));
    }
    break;

    case SIO_CMD_GET_BYTES:
    {
        UART_CTRL_GET_BYTES_T* prCtrlGetBytes;
        prCtrlGetBytes = &(data->rUARTCtrlGETBYTES);
        prCtrlGetBytes->u2RetSize= ccci_uart_getbytes(dev, prCtrlGetBytes->puBuffaddr, prCtrlGetBytes->u2Length, prCtrlGetBytes->pustatus, (module_type)(prCtrlGetBytes->u4OwenrId));
    }
    break;

    case SIO_CMD_PUT_BYTES:
    {
        UART_CTRL_PUT_BYTES_T* prCtrlPutBytes;
        prCtrlPutBytes = &(data->rUARTCtrlPUTBYTES);
        prCtrlPutBytes->u2RetSize= ccci_uart_putbytes(dev, prCtrlPutBytes->puBuffaddr, prCtrlPutBytes->u2Length, (module_type)(prCtrlPutBytes->u4OwenrId));
    }
    break;


    case SIO_CMD_GET_RX_AVAIL:
    {
        UART_CTRL_RX_AVAIL_T* prCtrlRXAvail;
        prCtrlRXAvail = &(data->rUARTCtrlRXAVAIL);
        prCtrlRXAvail->u2RetSize =ccci_uart_getrxavail(dev);
    }
    break;

    case SIO_CMD_GET_TX_AVAIL:
    {
        UART_CTRL_TX_AVAIL_T* prCtrlTXAvail;
        prCtrlTXAvail = &(data->rUARTCtrlTXAVAIL);
        prCtrlTXAvail->u2RetSize = ccci_uart_gettxavail(dev);
    }
    break;

    case SIO_CMD_PUT_ISR_BYTES:
    {
        UART_CTRL_PUT_BYTES_T* prCtrlPutBytes;
        prCtrlPutBytes = &(data->rUARTCtrlPUTBYTES);
        prCtrlPutBytes->u2RetSize = ccci_uart_putisrbytes(dev,prCtrlPutBytes->puBuffaddr,prCtrlPutBytes->u2Length,
                                    (module_type)(prCtrlPutBytes->u4OwenrId));
    }
    break;

    case SIO_CMD_GET_ISR_TX_AVAIL:
    {
        UART_CTRL_TX_AVAIL_T* prCtrlTXAail;
        prCtrlTXAail = &(data->rUARTCtrlTXAVAIL);
        prCtrlTXAail->u2RetSize =ccci_uart_getisrtxavail(dev);
    }
    break;

    case SIO_CMD_PURGE:
    {
        UART_CTRL_PURGE_T* prCtrlPurge;
        prCtrlPurge = &(data->rUARTCtrlPURGE);
        ccci_uart_purge(dev, (UART_buffer)(prCtrlPurge->dir), (module_type)(prCtrlPurge->u4OwenrId));
    }
    break;

    case SIO_CMD_SET_OWNER:
    {
        UART_CTRL_OWNER_T* prCtrlOwner;
        prCtrlOwner = &(data->rUARTCtrlOWNER);
        ccci_uart_setowner(dev, (module_type)(prCtrlOwner->u4OwenrId));
    }
    break;

    case SIO_CMD_SET_FLOW_CTRL:
    {
        UART_CTRL_FLOW_CTRL_T* prCtrlFlowCtrl;
        prCtrlFlowCtrl = &(data->rUARTCtrlFLOWCTRL);
        ccci_uart_setflowctrl(dev, (kal_bool)(prCtrlFlowCtrl->bXON), (module_type)(prCtrlFlowCtrl->u4OwenrId));
    }
    break;

    case SIO_CMD_CONFIG_ESCAPE:
    {
        UART_CTRL_CONFIG_ESP_T* prCtrlConfigEsp;
        prCtrlConfigEsp = &(data->rUARTCtrlCONFIGESP);
        ccci_uart_configescape(dev,prCtrlConfigEsp->uEscChar,prCtrlConfigEsp->u2ESCGuardtime, (module_type)(prCtrlConfigEsp->u4OwenrId));
    }
    break;

    case SIO_CMD_SET_DCB_CONFIG:
    {
        UARTDCBStruct *prDCB;
        UART_CTRL_DCB_T* prCtrlDCB;
        prCtrlDCB = &(data->rUARTCtrlDCB);
        prDCB = (UARTDCBStruct*)(&(prCtrlDCB->rUARTConfig));
        ccci_uart_setdcbconfig(dev,prDCB, (module_type)(prCtrlDCB->u4OwenrId));
    }
    break;

    case SIO_CMD_CTRL_DCD:
    {
        UART_CTRL_DCD_T* prCtrlDCD;
        prCtrlDCD = &(data->rUARTCtrlDCD);
        ccci_uart_ctrldcd(dev, (IO_level)(prCtrlDCD->rIOLevelDCD), (module_type)(prCtrlDCD->u4OwenrId));
    }
    break;

    case SIO_CMD_CTRL_BREAK:
    {
        UART_CTRL_BREAK_T* prCtrlBreak;
        prCtrlBreak = &(data->rUARTCtrlBREAK);
        ccci_uart_ctrlbreak(dev, (IO_level)(prCtrlBreak->rIOLevelBRK), (module_type)(prCtrlBreak->u4OwenrId));
    }
    break;

    case SIO_CMD_CLR_RX_BUF:
    {
        UART_CTRL_CLR_BUFFER_T* prCtrlClrBuffer;
        prCtrlClrBuffer = &(data->rUARTCtrlCLRBUFFER);
        ccci_uart_clrrxbuffer(dev, (module_type)(prCtrlClrBuffer->u4OwenrId));
    }
    break;

    case SIO_CMD_CLR_TX_BUF:
    {
        UART_CTRL_CLR_BUFFER_T* prCtrlClrBuffer;
        prCtrlClrBuffer = &(data->rUARTCtrlCLRBUFFER);
        ccci_uart_clrtxbuffer(dev, (module_type)(prCtrlClrBuffer->u4OwenrId));
    }
    break;

    case SIO_CMD_SET_BAUDRATE:
    {
        UART_CTRL_BAUDRATE_T* prCtrlBaudrate;
        prCtrlBaudrate = &(data->rUARTCtrlBAUDRATE);
        ccci_uart_setbaudrate(dev,prCtrlBaudrate->baudrate, (module_type)(prCtrlBaudrate->u4OwenrId));
    }
    break;

    case SIO_CMD_SEND_ISR_DATA:
    {
        UART_CTRL_SEND_DATA_T* prCtrlSendData;
        prCtrlSendData = &(data->rUARTCtrlSENDDATA);
        prCtrlSendData->u2RetSize = ccci_uart_sendisrdata(dev,prCtrlSendData->puBuffaddr,prCtrlSendData->u2Length,
                                    prCtrlSendData->umode,prCtrlSendData->uescape_char, (module_type)(prCtrlSendData->u4OwenrId));
    }
    break;

    case SIO_CMD_SEND_DATA:
    {
        UART_CTRL_SEND_DATA_T* prCtrlSendData;
        prCtrlSendData = &(data->rUARTCtrlSENDDATA);
        prCtrlSendData->u2RetSize = ccci_uart_senddata(dev,prCtrlSendData->puBuffaddr,prCtrlSendData->u2Length,
                                    prCtrlSendData->umode,prCtrlSendData->uescape_char, (module_type)(prCtrlSendData->u4OwenrId));
    }
    break;

    case SIO_CMD_GET_OWNER_ID:
    {
        UART_CTRL_OWNER_T* prCtrlOwner;
        prCtrlOwner = &(data->rUARTCtrlOWNER);

        prCtrlOwner->u4OwenrId =  ccci_uart_getownerid(dev);
    }
    break;

    case SIO_CMD_SET_AUTOBAUD_DIV:
    {
        UART_CTRL_AUTO_BAUDDIV_T* prCtrlAutoBaudDiv;
        prCtrlAutoBaudDiv = &(data->rUARTCtrlAUTOBAUDDIV);
        ccci_uart_setautobaud_div(dev, (module_type)(prCtrlAutoBaudDiv->u4OwenrId));
    }
    break;

    case SIO_CMD_REG_TX_CB:
    {
        UART_CTRL_REG_TX_CB_T* prCtrlTxCB;
        prCtrlTxCB = &(data->rUARTCtrlREGTXCB);
        ccci_uart_register_tx_cb(dev, (module_type)(prCtrlTxCB->u4OwenrId),(DCL_UART_TX_FUNC)prCtrlTxCB->func);
    }
    break;

    case SIO_CMD_REG_RX_CB:
    {
        UART_CTRL_REG_RX_CB_T * prCtrlRxCb;
        prCtrlRxCb = &(data->rUARTCtrlREGRXCB);
        ccci_uart_register_rx_cb(dev, (module_type)(prCtrlRxCb->u4OwenrId),(DCL_UART_RX_FUNC)prCtrlRxCb->func);
    }
    break;


    case SIO_CMD_GET_UART_BYTE:
    {
        UART_CTRL_GET_UART_BYTE_T* prCtrlGetUartByte;
        prCtrlGetUartByte = &(data->rUARTCtrlGETUARTBYTE);
        prCtrlGetUartByte->uByte = ccci_uart_getuartbyte(dev);
    }
    break;

    case SIO_CMD_PUT_UART_BYTE:
    {
        UART_CTRL_PUT_UART_BYTE_T* prCtrlPutUartByte;
        prCtrlPutUartByte = &(data->rUARTCtrlPUTUARTBYTE);
        ccci_uart_putuartbyte(dev,prCtrlPutUartByte->uData);
    }
    break;

    case SIO_CMD_PUT_UART_BYTES:
    {

        UART_CTRL_PUT_UART_BYTES_T* prCtrlPutUartBytes;
        prCtrlPutUartBytes = &(data->rUARTCtrlPUTUARTBYTES);

        if ((dev == FIRST_CCCI_UART_PORT) && INT_QueryExceptionStatus() == KAL_TRUE)
        {
            ccci_uart_puttstexceuartbytes(dev,prCtrlPutUartBytes->puBuffaddr, (module_type)(prCtrlPutUartBytes->u2Length));
        }
        else
        {
            ccci_uart_putuartbytes(dev,prCtrlPutUartBytes->puBuffaddr, (module_type)(prCtrlPutUartBytes->u2Length));
        }
    }
    break;

    case SIO_CMD_READ_DCB_CONFIG:
    {
        UARTDCBStruct *prDCB;
        UART_CTRL_DCB_T* prCtrlDCB;
        prCtrlDCB = &(data->rUARTCtrlDCB);
        prDCB = (UARTDCBStruct*)(&(prCtrlDCB->rUARTConfig));
        ccci_uart_ReadDCBConfig(dev,prDCB);
    }
    break;

    case SIO_CMD_CTRL_RI:
    {
        UART_CTRL_RI_T* prCtrlRI;
        prCtrlRI= &(data->rUARTCtrlRI);
        ccci_uart_CtrlRI(dev, (IO_level)(prCtrlRI->rIOLevelSRI), (module_type)(prCtrlRI->u4OwenrId));
    }
    break;

    case SIO_CMD_CTRL_DTR:
    {
        UART_CTRL_DTR_T* prCtrlDTR;
        prCtrlDTR = &(data->rUARTCtrlDTR);
        ccci_uart_CtrlDTR(dev, (IO_level)(prCtrlDTR->rIOLevelDTR), (module_type)(prCtrlDTR->u4OwenrId));
    }
    break;

    case SIO_CMD_READ_HW_STATUS:
    {
        IO_level* pSDSR;
        IO_level* pSCTS;
        UART_CTRL_RHS_T* prCtrlRHS;
        prCtrlRHS = &(data->rUARTCtrlRHS);
        pSDSR = (IO_level*)(&(prCtrlRHS->rIOLevelDSR));
        pSCTS = (IO_level*)(&(prCtrlRHS->rIOLevelCTS));
        ccci_uart_ReadHWStatus(dev,pSDSR,pSCTS);
    }
    break;

#ifdef CCCI_UART_GIO
    case SIO_CMD_GIO_ENABLE:
    {
        UART_GIO_ENABLE_T* prCtrGE;
        prCtrGE = &(data->rUARTGIOEnable);
        prCtrGE->status = ccci_uart_gio_enable(dev, prCtrGE->option, prCtrGE->u4OwnerId);
    }
    break;

    case SIO_CMD_GIO_DISABLE:
    {
        UART_GIO_DISABLE_T* prCtrGE;
        prCtrGE = &(data->rUARTGIODisable);
        prCtrGE->status = ccci_uart_gio_disable(dev, prCtrGE->option, prCtrGE->u4OwnerId);
    }
    break;


    case SIO_CMD_GIO_TX_SEND_DATA:
    {
        UART_GIO_TX_SEND_DATA_T* prCtrGE;
        prCtrGE = &(data->rUARTGIOTXSendData);
        prCtrGE->pOut_GPD = ccci_uart_gio_tx_send_data(dev, prCtrGE->pIn_GPD, prCtrGE->pIn_GPD_last, prCtrGE->option, prCtrGE->u4OwnerId);
    }
    break;


    case SIO_CMD_GIO_TX_RECYCLE_GPD:
    {
        UART_GIO_TX_RECYCLE_GPD_T* prCtrGE;
        prCtrGE = &(data->rUARTGIOTXRecycleGPD);
        prCtrGE->pOut_GPD = (DCL_UINT8*)ccci_uart_gio_tx_recycle_gpd(dev, prCtrGE->option, prCtrGE->u4OwnerId);
    }
    break;

    case SIO_CMD_GIO_TX_FLUSH_GPD:
    {
        UART_GIO_TX_FLUSH_GPD_T* prCtrGE;
        prCtrGE = &(data->rUARTGIOTXFlushGPD);
        prCtrGE->pOut_GPD = (DCL_UINT8*)ccci_uart_gio_tx_flush_gpd(dev, prCtrGE->option, prCtrGE->u4OwnerId);
    }
    break;

    case SIO_CMD_GIO_RX_RECV_DATA:
    {
        UART_GIO_RX_RECV_DATA_T* prCtrGE;
        prCtrGE = &(data->rUARTGIORXRecvData);
        prCtrGE->pOut_GPD = (DCL_UINT8*)ccci_uart_gio_rx_recv_data(dev, prCtrGE->option, prCtrGE->u4OwnerId);
    }
    break;

    case SIO_CMD_GIO_RX_LOAD_GPD:
    {
        UART_GIO_RX_LOAD_GPD_T* prCtrGE;
        prCtrGE = &(data->rUARTGIORXLoadGPD);
        prCtrGE->pOut_GPD = ccci_uart_gio_rx_load_gpd(dev, prCtrGE->pIn_GPD, prCtrGE->pIn_GPD_last, prCtrGE->option, prCtrGE->u4OwnerId);
    }
    break;

    case SIO_CMD_GIO_RX_FLUSH_GPD:
    {
        UART_GIO_RX_FLUSH_GPD_T* prCtrGE;
        prCtrGE = &(data->rUARTGIORXFlushGPD);
        prCtrGE->pOut_GPD = (DCL_UINT8*)ccci_uart_gio_rx_flush_gpd(dev, prCtrGE->option, prCtrGE->u4OwnerId);
    }
    break;
    case SIO_CMD_GIO_LOAD_DUMMY_GPD:
    {
        UART_GIO_LOAD_DUMMY_GPD_T* prCtrGE;
        prCtrGE = &(data->rUARTGIOLOADDUMMYGPD);
        ccci_uart_gio_load_dummy_gpd(dev, prCtrGE->pTX_GPD, prCtrGE->TX_size, prCtrGE->pRX_GPD, prCtrGE->RX_size);
    }
    break;
#endif //- CCCI_UART_GIO



    default:
        return STATUS_INVALID_CMD;
    }

    return return_status;
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
#endif

#endif  /* __MODEM_CCCI_EXIST__ */

