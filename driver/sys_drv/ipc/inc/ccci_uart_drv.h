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
 *   ccci_uart_drv.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Header file of UART driver of CCCI.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __CCCI_UART_DRV_H__
#define __CCCI_UART_DRV_H__

#if defined(__MODEM_CCCI_EXIST__)

#if !defined(__SDIO_DEVICE_CONNECTIVITY__)

//- __3G_NEW_DATA_PLANE_ARCH__ stands for option to distinguish PS use UART data path or GPD data path.
//- Feature owner: TDD - Johnson Liu.
//-                FDD - Kathie Ho.
#if defined(__CR4__) && defined(__3G_NEW_DATA_PLANE_ARCH__)
#define CCCI_UART_GIO
#endif
/*******************************************************************************
 * Include header files
 *******************************************************************************/
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "uart_sw.h"
#include "dcl.h"

#ifdef CCCI_UART_GIO
#include "gpd_lib.h"
#include "bytecopy.h"
#endif

/*******************************************************************************
 * Define constants.
 *******************************************************************************/
//-#define CCCI_UART_GIO_IT
#define CCCI_BCE_HISR_BCE_KICKBACK
#define CCCI_CCIF_HISR_BCE_KICKBACK

#ifdef __FLC2_CCCI_SHARE_MEM__
//- share buffer flow control by CCCI ???
#define CCCI_GIOPDU_UPLINK_FLC_FLOWCTL
#endif

#define CCCI_GIOPDU_EXTDBG
#define CCCI_GIOPDU_DEBUG_TRACE
//-#define CCCI_GIOPDU_DEBUG_TRACE_DL0


#define CCCI_TX_BUFF_LEN 		192
#define CCCI_RX_BUFF_LEN 		192
#define MAX_CCCI_UART_PORT 		6
#define MAX_CCCI_GIOPDU_PORT	3
#define FIRST_CCCI_UART_PORT 	uart_port_tst_ccci
#define FIRST_CCCI_CCMNI_PORT	uart_port_ccmni1_ccci

#define CCCI_UART_CCMNI_PORT_MASK	0x1C

//- retry forever if value was 0x0
#define CCCI_UART_MAX_RETRY		0x0

#define CCCI_UART_SEND_RETRY    CCCI_SEND_RETRY_DEFAULT

#define CCCI_UART_BUFF_INVALID_MARK    0

#ifdef CCCI_UART_GIO
#define CCCI_GIOPDU_DBG_HEADER				0xE1E1E1E1
#define CCCI_GIOPDU_DBG_FOOTER				0xE2E2E2E2
#define CCCI_GIOPDU_DBG_ENDER				0xE3
#define CCCI_GIOPDU_DBG_INVALID_4B			0xCCCCCCCC
#define CCCI_GIOPDU_DBG_INVALID_1B			0xDD

#define CCCI_GIOPDU_TX_GO_ENTRY_BG_TASK			0x01
#define CCCI_GIOPDU_TX_GO_ENTRY_BCE_HISR		0x02
#define CCCI_GIOPDU_TX_GO_ENTRY_CCIF_HISR		0x04
#define CCCI_GIOPDU_TX_GO_ENTRY_HISR_MASK		(CCCI_GIOPDU_TX_GO_ENTRY_BCE_HISR | CCCI_GIOPDU_TX_GO_ENTRY_CCIF_HISR)

#define CCCI_GIOPDU_NO_ERR					0
#define CCCI_GIOPDU_ERR_RINGQ_NO_SPACE		-1
#define CCCI_GIOPDU_ERR_RINGQ_LOCKED		-2
#define CCCI_GIOPDU_ERR_LINK_LOCK			-3
#define CCCI_GIOPDU_ERR_BCE_LOCK			-4
#define CCCI_GIOPDU_ERR_BCE_NOT_START		-5

#define CCCI_GIOPDU_UNDESIGNATE_PORT		0xFFFF

#define CCCI_GIOPDU_ENABLE_TX_MAX_GPD2BCE_MASK		0x000000FF
#define CCCI_GIOPDU_ENABLE_RX_MAX_PRELOAD_MASK		0x0000FF00
#define CCCI_GIOPDU_ENABLE_TX_BCE_KICKBACK_MASK		0x40000000
#define CCCI_GIOPDU_ENABLE_RX_MERGE_RECYCLE_MASK	0x80000000

#define CCCI_GIOPDU_MAX_PDU_SIZE			1500

#ifdef CCCI_GIOPDU_UPLINK_FLC_FLOWCTL
#undef	CCCI_GIOPDU_UPLINK_CCCI_FLOWCTL
//-#define CCCI_GIOPDU_UPLINK_PLANB_FLOWCTL
#else
#define CCCI_GIOPDU_UPLINK_CCCI_FLOWCTL
#endif

#ifdef CCCI_GIOPDU_EXTDBG
#define CCCI_GIOPDU_ENTRY_LENGTH		( sizeof(CCCI_GIOPDU_DBGBLK_HEADER_T) + sizeof(CCCI_GIOPDU_DBGBLK_FOOTER_T) + CCCI_GIOPDU_MAX_PDU_SIZE )
#else
#define CCCI_GIOPDU_ENTRY_LENGTH		( CCCI_GIOPDU_MAX_PDU_SIZE )
#endif

#endif //- CCCI_UART_GIO


#ifndef CCCI_UART_GIO
#undef CCCI_UART_GIO_IT
#endif

/*******************************************************************************
 * Define data structures.
 *******************************************************************************/

/* CCCI UART Buffer Structure */
typedef struct CCCI_UART_BUFFER_STRUCT
{
    kal_uint32 read;
    kal_uint32 write;
    kal_uint32 len;
} CCCI_UARTB_T;

/* CCCI UART PORT Structure */
typedef struct CCCI_UART_PORT_STRUCT
{
    kal_uint32 tx_channel; /* CCCI channel for TX */
    kal_uint32 tx_ack_channel; /* CCCI channel for TX ACK */
    kal_uint32 rx_channel;  /* CCCI channel for RX */
    kal_uint32 rx_ack_channel;  /* CCCI channel for RX ACK */
    kal_eventgrpid event;   /* notify event */
    kal_uint32 flag;    /* notify flag */
    kal_uint32 write_flag;
    module_type tx_owner;   /* TX owner */
    module_type rx_owner;   /* RX owner */
} CCCI_UARTP_T;

typedef struct CCCI_UART_PORT_BUFFER_STRUCT
{

    CCCI_UARTB_T *tx;
    CCCI_UARTB_T *rx;
    kal_uint8 *tx_buff;
    kal_uint8 *rx_buff;

} CCCI_UARTP_BUFF_T;


#ifdef CCCI_UART_GIO

typedef struct CCCI_GIOPDU_SMCTL
{
    kal_uint32	avai_in;
    kal_uint32	avai_out;
    kal_uint32	read_out;
    kal_uint32	ringQ_len;
} CCCI_GIOPDU_SMCTL_T, *pCCCI_GIOPDU_SMCTL_T;

typedef struct CCCI_GIOPDU_RINGQ
{
    kal_uint8	*ptr_entry;
    kal_uint32	len_entry;
} CCCI_GIOPDU_RINGQ_T, *pCCCI_GIOPDU_RINGQ_T;

typedef struct CCCI_GIOPDU_CTLBLK
{
    CCCI_GIOPDU_SMCTL_T 	*tx_ctl;
    CCCI_GIOPDU_SMCTL_T 	*rx_ctl;
    CCCI_GIOPDU_RINGQ_T 	*tx_ringQ;
    CCCI_GIOPDU_RINGQ_T 	*rx_ringQ;

    kal_uint32				rx_ringQ_threshold;
    kal_uint32				low_threshold;
    kal_uint32				recycle_msg;
    kal_uint32				option;

    kal_uint32				procRingQBaseNext;

    //- TX parts
    gpd_node				*waiting_gpd_first;
    gpd_node				*recycle_gpd_first;
    gpd_list				waiting_gpd_list;
    gpd_list				processing_gpd_list;
    gpd_list				recycle_gpd_list;

    //- RX parts
    gpd_node				*waitload_gpd_first;
    gpd_list				waitload_gpd_list;
    gpd_list				recv_gpd_list;

#ifdef CCCI_GIOPDU_UPLINK_FLC_FLOWCTL
    gpd_node				*loading_gpd_first;
    gpd_node				*loading_gpd_last;
    gpd_list				loading_gpd_list;
#endif

#ifdef CCCI_GIOPDU_DEBUG_TRACE_DL0
    kal_uint32				DL_in;
    kal_uint32				DL_proc;
    kal_uint32				DL_done;
    kal_uint32				DL_out;
#endif

} CCCI_GIOPDU_CTLBLK_T;

typedef struct CCCI_GIOPDU_FLOWCTL
{
    kal_uint8		*tx_buffer_base;
    kal_uint8		*rx_buffer_base;
    kal_uint32		tx_buffer_size;
    kal_uint32		rx_buffer_size;

    kal_uint32		nextProcPort;
    kal_uint32		startLinkMask;
    kal_uint32		lockRingQMask;
    kal_uint32		startBCMask;
    kal_uint32		ilmRxBGFlag;

    cmd_byte_copy_start_struct	byte_copy_start;

#ifdef CCCI_UART_GIO_IT
    kal_uint32		it_state;
#endif
} CCCI_GIOPDU_FLOWCTL_T;

#endif	//- CCCI_UART_GIO

/*******************************************************************************
 * Define macros.
 *******************************************************************************/

#define CCCI_UARTB_INIT(uartb, size) 									\
		do {    														\
        	CCCI_UARTB_T *uartbp = (uartb); 							\
            uartbp->read	= 0;   										\
            uartbp->write	= 0;  										\
            uartbp->len		= (size);   								\
        } while (0)

#define CCCI_UARTB_GETAVAIL(uartb, avail)   							\
        do {    														\
            volatile CCCI_UARTB_T	*uartbp = (uartb); 							\
            kal_uint32 		r_value = uartbp->read;						\
            kal_uint32 		w_value = uartbp->write;					\
            (avail) = 0;  												\
            if (w_value >= r_value)  									\
                (avail) = w_value - r_value; 							\
            else    													\
                (avail) = uartbp->len - r_value + w_value;   			\
        } while (0)

#define CCCI_UARTB_POP(uartb, bufaddr, data)  							\
        do {    														\
            CCCI_UARTB_T	*uartbp = (uartb); 							\
            kal_uint32 		r_value = uartbp->read;						\
            kal_uint32 		len		= uartbp->len;						\
            (data) = *((kal_uint8 *)(bufaddr) + r_value);   			\
            r_value ++;													\
            if (r_value >= len)    										\
                r_value -= len;    										\
            uartbp->read = r_value;										\
        } while (0)

//will not pop more than 1 array
#define CCCI_UARTB_POP_MULTI(uartb, bufaddr, output_addr, length)  		\
        do {    														\
            CCCI_UARTB_T	*uartbp = (uartb); 							\
            kal_uint32 		r_value = uartbp->read;						\
            kal_uint32 		len		= uartbp->len;						\
            if ( length <= (len - 1) - r_value + 1) 					\
            { 															\
            	kal_mem_cpy((kal_uint8 *)output_addr , (kal_uint8 *)(bufaddr) + r_value , length); \
            	if (length == (len - 1) - r_value + 1) 					\
            	{ 														\
            		(uartbp->read)= 0; 									\
            	} 														\
            	else 													\
            	{ 														\
            		(uartbp->read) = length + r_value;					\
            	} 														\
            	length = 0; 											\
            } 															\
            else 														\
            { 															\
            	kal_mem_cpy((kal_uint8 *)output_addr , (kal_uint8 *)(bufaddr) + r_value , (len - 1) - r_value + 1); 	\
            	output_addr = (kal_uint8 *)output_addr + (len - 1) - r_value + 1; 										\
            	kal_mem_cpy((kal_uint8 *)output_addr , (kal_uint8 *)(bufaddr) , length - ((len - 1) - r_value + 1)); 	\
            	uartbp->read = length - ((len - 1) - r_value + 1) ; 													\
            	length = 0; 																							\
            } 																											\
         } while (0)

#define CCCI_UARTB_GETROOMLEFT(uartb, roomleft) 						\
        do {    														\
            CCCI_UARTB_T	*uartbp = (uartb); 							\
            kal_uint32 		r_value = uartbp->read;						\
            kal_uint32 		w_value = uartbp->write;					\
            kal_uint32 		len		= uartbp->len;						\
            if (r_value <= w_value)  									\
            {   														\
                (roomleft) = len - w_value + r_value - 1;    			\
            } else {    												\
                (roomleft) = r_value - w_value - 1;  					\
            }   														\
        } while (0)

#define CCCI_UARTB_PUSH(uartb, bufaddr, data)   						\
        do {    														\
            CCCI_UARTB_T	*uartbp = (uartb); 							\
            kal_uint32 		w_value = uartbp->write;					\
            *((kal_uint8 *)(bufaddr) + w_value) = (data); 				\
            if (w_value >= (uartbp->len - 1)) 							\
            {  															\
                uartbp->write = 0;  									\
            } else {    												\
                (uartbp->write) = w_value + 1;    						\
            }   														\
        } while (0)


//will not push one bytes
#define CCCI_UARTB_PUSH_MULTI(uartb, bufaddr, input_addr, length)   	\
        do {    														\
            CCCI_UARTB_T	*uartbp = (uartb); 							\
            kal_uint32 		w_value = uartbp->write;					\
            kal_uint32 		len		= uartbp->len;						\
            if (length <= ((uartbp->len - 1) - w_value + 1)) 			\
            { 															\
            	kal_mem_cpy((kal_uint8 *)(bufaddr) + w_value, (kal_uint8 *)input_addr , length); \
            	if (length == ((len - 1) - w_value + 1)) 				\
            	{ 														\
            		(uartbp->write) = 0; 								\
            	} 														\
            	else 													\
            	{ 														\
            		(uartbp->write) = length + w_value; 				\
            	} 														\
            	length = 0; 											\
            } 															\
            else 														\
            { 															\
                kal_mem_cpy((kal_uint8 *)(bufaddr) + w_value, (kal_uint8 *)input_addr , ((len - 1) - w_value + 1)); 							\
                kal_mem_cpy((kal_uint8 *)(bufaddr) , (kal_uint8 *)input_addr + ((len - 1) - w_value + 1) , length - ((len - 1) - w_value +1));	\
                (uartbp->write) = length - ((len - 1) - w_value +1);    																		\
                length =0; 																														\
            }   																																\
        } while (0)

#define CCCI_GIOPDU_ADJUST_RX_READOUT(gIOPORT, vALUE)		do {ccci_giopdu_ctlblk[gIOPORT].rx_ctl->read_out = vALUE;} while (0)
#define CCCI_GIOPDU_ADJUST_RX_AVAIIN(gIOPORT, vALUE)		do {ccci_giopdu_ctlblk[gIOPORT].rx_ctl->avai_in = vALUE;} while (0)
#define CCCI_GIOPDU_ADJUST_TX_AVAIOUT(gIOPORT, vALUE)		do {ccci_giopdu_ctlblk[gIOPORT].tx_ctl->avai_out = vALUE;} while (0)

#define CCCI_GIOPDU_RINGQ_GETPUSHAVAIL(cTL, aVAIL, bASE)				\
        do {    														\
            CCCI_GIOPDU_SMCTL_T	*ctl = (cTL); 							\
            kal_uint32 		in	= ctl->avai_in;							\
            kal_uint32 		out = ctl->avai_out;						\
            if (in > out)	  											\
                (aVAIL) = in - out - 1;									\
            else    													\
                (aVAIL) = ctl->ringQ_len - out + in - 1;				\
            bASE = out;													\
        } while (0)

#define CCCI_GIOPDU_RINGQ_GETPULLAVAIL(cTL, aVAIL, bASE)				\
        do {    														\
            CCCI_GIOPDU_SMCTL_T	*ctl = (cTL); 							\
            kal_uint32 		out= ctl->avai_out;							\
            kal_uint32 		rdout = ctl->read_out;						\
            if (out >= rdout)	  										\
                (aVAIL) = out - rdout;									\
            else    													\
                (aVAIL) = ctl->ringQ_len - rdout + out;					\
            bASE = rdout;												\
        } while (0)

#define CCCI_GIOPDU_RINGQ_GETLOADAVAIL(cTL, aVAIL1, aVAIIN, rDOUT, lEN)			\
        do {    																\
            CCCI_GIOPDU_SMCTL_T	*ctl = (cTL); 									\
            aVAIIN	= ctl->avai_in;												\
            rDOUT	= ctl->read_out;											\
			lEN		= ctl->ringQ_len;											\
    		if (rDOUT > aVAIIN)	  												\
               	(aVAIL1) = rDOUT - aVAIIN - 1;									\
     		else    															\
               	(aVAIL1) = lEN - aVAIIN + rDOUT - 1; 							\
        } while (0)

#define CCCI_GIOPDU_RINGQ_GETLOADPENDING(cTL, pENDING)							\
        do {    																\
            CCCI_GIOPDU_SMCTL_T	*ctl = (cTL); 									\
            kal_uint32 in	= ctl->avai_in;										\
            kal_uint32 rdout= ctl->read_out;									\
			kal_uint32 len		= ctl->ringQ_len;								\
    		if (in > rdout)	  													\
               	(pENDING) = in - rdout + 1;										\
     		else    															\
               	(pENDING) = len - rdout + in + 1; 								\
        } while (0)


/*******************************************************************************
 * Define export variables.
 *******************************************************************************/
extern CCCI_UARTP_BUFF_T ccci_uartp_buff[MAX_CCCI_UART_PORT];

extern Seriport_HANDLER_T    CCCI_Uart_Drv_Handler;

#ifdef CCCI_UART_GIO
extern kal_uint8 ccci_ap_md_net_ULRingQ_mismatch;
extern kal_uint8 ccci_ap_md_net_DLRingQ_mismatch;
#endif
/*******************************************************************************
 * Declare function prototype.
 *******************************************************************************/

#ifdef CCCI_UART_GIO
typedef void (*CCCI_BCE_CALLBACK)(void);

extern void ccci_bce_callback (void);

extern void ccci_uart_gio_initial (void);

#ifdef CCCI_UART_GIO_IT
extern void ccci_uart_gio_it_timer_callback(void *param_ptr);
extern void ccci_uart_gio_initial_IT (void);
#endif

#endif //- CCCI_UART_GIO





















#else //- __SDIO_DEVICE_CONNECTIVITY__
#if defined(__SMART_PHONE_MODEM__)
#include "ccci.h"
#include "dcl.h"
#include "uart_sw.h"

/*******************************************************************************
 * Define constants.
 *******************************************************************************/

#define CCCI_TX_BUFF_LEN 192
#define CCCI_RX_BUFF_LEN 192
#define MAX_CCCI_UART_PORT 6
#define FIRST_CCCI_UART_PORT uart_port_tst_ccci

/*******************************************************************************
 * add for GIO services
 ******************************************************************************/
//export the API or not
#define PUBLIC
#define PRIVATE

/*******************************************************************************
 * Define data structures.
 *******************************************************************************/

/* CCCI UART Buffer Structure */
typedef struct CCCI_UART_BUFFER_STRUCT
{
    kal_uint32 read;
    kal_uint32 write;
    kal_uint32 len;
} CCCI_UARTB_T;

/* CCCI UART PORT Structure */
typedef struct CCCI_UART_PORT_STRUCT
{
    kal_uint32 tx_channel; /* CCCI channel for TX */
    kal_uint32 tx_ack_channel; /* CCCI channel for TX ACK */
    kal_uint32 rx_channel;  /* CCCI channel for RX */
    kal_uint32 rx_ack_channel;  /* CCCI channel for RX ACK */
    kal_eventgrpid event;   /* notify event */
    kal_uint32 flag;    /* notify flag */
    kal_uint32 write_flag;
    module_type tx_owner;   /* TX owner */
    module_type rx_owner;   /* RX owner */
#if defined (__SDIO_DEVICE_CONNECTIVITY__)
    kal_uint32 gio_mode;
#endif
} CCCI_UARTP_T;

typedef struct CCCI_UART_PORT_BUFFER_STRUCT
{

    CCCI_UARTB_T *tx;
    CCCI_UARTB_T *rx;
    kal_uint8 *tx_buff;
    kal_uint8 *rx_buff;

} CCCI_UARTP_BUFF_T;


extern CCCI_UARTP_BUFF_T ccci_uartp_buff[MAX_CCCI_UART_PORT];

/*******************************************************************************
 * Define macros.
 *******************************************************************************/

#define CCCI_UARTB_INIT(uartb, size) \
        do {    \
            CCCI_UARTB_T *uartbp = (uartb); \
            uartbp->read = 0;   \
            uartbp->write = 0;  \
            uartbp->len = (size);    \
        } while (0)

#define CCCI_UARTB_GETAVAIL(uartb, avail)   \
        do {    \
            CCCI_UARTB_T *uartbp = (uartb); \
            (avail) = 0;  \
            if (uartbp->write >= uartbp->read)  \
                (avail) = uartbp->write - uartbp->read; \
            else    \
                (avail) = uartbp->len - uartbp->read + uartbp->write;   \
        } while (0)

#define CCCI_UARTB_POP(uartb, bufaddr, data)  \
        do {    \
            CCCI_UARTB_T *uartbp = (uartb); \
            (data) = *((kal_uint8 *)(bufaddr) + uartbp->read);   \
            (uartbp->read)++;   \
            if (uartbp->read >= uartbp->len)    \
                uartbp->read -= uartbp->len;    \
        } while (0)

//will not pop more than 1 array
#define CCCI_UARTB_POP_MULTI(uartb, bufaddr, output_addr, length)  \
        do {    \
            CCCI_UARTB_T *uartbp = (uartb); \
            if ( length <= (uartbp->len - 1) - uartbp->read + 1) \
            { \
            	kal_mem_cpy((kal_uint8 *)output_addr , (kal_uint8 *)(bufaddr) + uartbp->read , length); \
            	if (length == (uartbp->len - 1) - uartbp->read + 1) \
            	{ \
            		(uartbp->read)= 0; \
            	} \
            	else \
            	{ \
            		(uartbp->read) += length; \
            	} \
            	length = 0; \
            } \
            else \
            { \
            	kal_mem_cpy((kal_uint8 *)output_addr , (kal_uint8 *)(bufaddr) + uartbp->read , (uartbp->len - 1) - uartbp->read + 1); \
            	output_addr =(kal_uint8 *)output_addr + ((uartbp->len - 1) - uartbp->read + 1); \
            	kal_mem_cpy((kal_uint8 *)output_addr , (kal_uint8 *)(bufaddr) , length - ((uartbp->len - 1) - uartbp->read + 1)); \
            	uartbp->read = length - ((uartbp->len - 1) - uartbp->read + 1) ; \
            	length = 0; \
            } \
         } while (0)


#define CCCI_UARTB_GETROOMLEFT_NEW(uartb, roomleft, flag) \
        do {    \
            CCCI_UARTB_T *uartbp = (uartb); \
            if (uartbp->read <= uartbp->write)  \
            {   \
                (roomleft) = uartbp->len - uartbp->write;   \
                flag = 1; \
            }else {    \
                (roomleft) = uartbp->read - uartbp->write - 1;  \
                flag = 0; \
            }   \
        } while (0)


#define CCCI_UARTB_GETROOMLEFT(uartb, roomleft) \
        do {    \
            CCCI_UARTB_T *uartbp = (uartb); \
            if (uartbp->read <= uartbp->write)  \
            {   \
                (roomleft) = uartbp->len - uartbp->write + uartbp->read - 1;    \
            } else {    \
                (roomleft) = uartbp->read - uartbp->write - 1;  \
            }   \
        } while (0)


#define CCCI_UARTB_PUSH(uartb, bufaddr, data)   \
        do {    \
            CCCI_UARTB_T *uartbp = (uartb); \
            *((kal_uint8 *)(bufaddr) + uartbp->write) = (data); \
            if (uartbp->write >= (uartbp->len - 1)) \
            {   \
                uartbp->write = 0;  \
            } else {    \
                (uartbp->write)++;    \
            }   \
        } while (0)


#define CCCI_UARTB_PUSH_MULTI_NEW(uartb, bufaddr, input_addr, length, flag, remain)   \
        do {    \
            CCCI_UARTB_T *uartbp = (uartb); \
            if(flag == 1) \
            {	\
	            if (length + CCCI_HAL_OVERHEAD <= ((uartbp->len - 1) - uartbp->write + 1)) \
	            { \
	            	kal_mem_cpy((kal_uint8 *)(bufaddr) + uartbp->write + CCCI_HAL_OVERHEAD, (kal_uint8 * )input_addr + remain , length); \
	            	remain += length; \
	            	if (length + CCCI_HAL_OVERHEAD == ((uartbp->len - 1) - uartbp->write + 1)) \
	            	{ \
	            		(uartbp->write) = 0; \
	            	} \
	            	else \
	            	{ \
	            		(uartbp->write) = (uartbp->write + length + CCCI_HAL_OVERHEAD); \
	            	} \
	            	length = 0; \
	            } \
	            else \
	            {	\
	            	kal_mem_cpy((kal_uint8 *)(bufaddr) + uartbp->write + CCCI_HAL_OVERHEAD, (kal_uint8 * )input_addr + remain , ((uartbp->len - 1) - uartbp->write + 1)); \
	            	remain += length; \
					(uartbp->write) = (uartbp->write + length + CCCI_HAL_OVERHEAD); \
	                length = length - ((uartbp->len - 1) - uartbp->write +1); \
            	}\
	       } \
	       else \
           { \
            	if (length + CCCI_HAL_OVERHEAD <= (uartbp->read - uartbp->write -1) ) \
            	{\
	                kal_mem_cpy((kal_uint8 *)(bufaddr) + uartbp->write + CCCI_HAL_OVERHEAD, (kal_uint8 * )input_addr + remain , length); \
	                remain += length; \
					(uartbp->write) = (uartbp->write + length + CCCI_HAL_OVERHEAD); \
					(uartbp->write) %= uartbp->len; \
	                length = 0; \
				} \
            	else \
            	{ \
					kal_mem_cpy((kal_uint8 *)(bufaddr) + uartbp->write + CCCI_HAL_OVERHEAD, (kal_uint8 * )input_addr + remain , (uartbp->read - uartbp->write -1)); \
					remain += length; \
					(uartbp->write) += (uartbp->read - uartbp->write -1); \
					(uartbp->write) %= uartbp->len; \
	                length -= (uartbp->read - uartbp->write -1); \
            	} \
           }   \
        } while (0)

#define CCCI_UARTB_PUSH_MULTI(uartb, bufaddr, input_addr, length)   \
        do {    \
            CCCI_UARTB_T *uartbp = (uartb); \
            if (length <= ((uartbp->len - 1) - uartbp->write + 1)) \
            { \
            	kal_mem_cpy((kal_uint8 *)(bufaddr) + uartbp->write, (kal_uint8 *)input_addr , length); \
            	if (length == ((uartbp->len - 1) - uartbp->write + 1)) \
            	{ \
            		(uartbp->write) = 0; \
            	} \
            	else \
            	{ \
            		(uartbp->write) += length; \
            	} \
            	length = 0; \
            } \
            else \
            { \
                kal_mem_cpy((kal_uint8 *)(bufaddr) + uartbp->write, (kal_uint8 *)input_addr , ((uartbp->len - 1) - uartbp->write + 1)); \
                kal_mem_cpy((kal_uint8 *)(bufaddr) , (kal_uint8 *)input_addr + ((uartbp->len - 1) - uartbp->write + 1) , length - ((uartbp->len - 1) - uartbp->write +1)); \
                (uartbp->write) = length - ((uartbp->len - 1) - uartbp->write +1);    \
                length =0; \
            }   \
        } while (0)
#endif //end (__SMART_PHONE_MODEM__)

/*******************************************************************************
 * Define export variables.
 *******************************************************************************/

extern PUBLIC Seriport_HANDLER_T    CCCI_Uart_Drv_Handler;

/*******************************************************************************
 * Declare function.
 *******************************************************************************/
PRIVATE kal_bool ccci_uart_behave_nonblock(DCL_DEV port);
PRIVATE void ccci_uart_tx_callback(CCCI_BUFF_T *buff);
PRIVATE void ccci_uart_tx_ack_callback(CCCI_BUFF_T *buff);
PRIVATE void ccci_uart_rx_callback(CCCI_BUFF_T *buff);
PRIVATE void ccci_uart_rx_ack_callback(CCCI_BUFF_T *buff);
PRIVATE kal_bool ccci_uart_open(DCL_DEV port, module_type owner);
PRIVATE void ccci_uart_close(DCL_DEV port, module_type owner);
PRIVATE kal_uint16 ccci_uart_getbytes(DCL_DEV port, kal_uint8 *Buffaddr, kal_uint16 Length, kal_uint8 *status, module_type ownerid);
PRIVATE kal_uint16 ccci_uart_putbytes(DCL_DEV port, kal_uint8 *Buffaddr, kal_uint16 Length, module_type ownerid);
PRIVATE kal_uint16 ccci_uart_putisrbytes(DCL_DEV port, kal_uint8 *Buffaddr, kal_uint16 Length, module_type ownerid);
PRIVATE kal_uint16 ccci_uart_getisrtxavail(DCL_DEV port);
PRIVATE void ccci_uart_putuartbytes(DCL_DEV port, kal_uint8 *data, kal_uint16 len);
PRIVATE void ccci_uart_putuartbyte(DCL_DEV port, kal_uint8 data);
PRIVATE kal_uint8 ccci_uart_getuartbyte(DCL_DEV port);
PRIVATE kal_uint16 ccci_uart_getrxavail(DCL_DEV port);
PRIVATE kal_uint16 ccci_uart_gettxavail(DCL_DEV port);
PRIVATE void ccci_uart_purge(DCL_DEV port, UART_buffer dir, module_type owner);
PRIVATE void ccci_uart_setowner(DCL_DEV port, module_type owner);
PRIVATE void ccci_uart_setflowctrl(DCL_DEV port, kal_bool XON, module_type owner);
PRIVATE void ccci_uart_configescape(DCL_DEV port, kal_uint8 EscChar, kal_uint16 ESCGuardtime, module_type owner);
PRIVATE void ccci_uart_setdcbconfig(DCL_DEV port, UARTDCBStruct *UART_Config, module_type owner);
PRIVATE void ccci_uart_ctrldcd(DCL_DEV port, IO_level SDCD, module_type owner);
PRIVATE void ccci_uart_ctrlbreak(DCL_DEV port, IO_level SBREAK, module_type owner);
PRIVATE void ccci_uart_clrrxbuffer(DCL_DEV port, module_type owner);
PRIVATE void ccci_uart_clrtxbuffer(DCL_DEV port, module_type owner);
PRIVATE void ccci_uart_setbaudrate(DCL_DEV port, UART_baudrate baudrate, module_type owner);
PRIVATE kal_uint16 ccci_uart_sendisrdata(DCL_DEV port, kal_uint8 *Buffaddr, kal_uint16 Length, kal_uint8 mode, kal_uint8 escape_char, module_type ownerid);
PRIVATE kal_uint16 ccci_uart_senddata(DCL_DEV port, kal_uint8 *Buffaddr, kal_uint16 Length, kal_uint8 mode, kal_uint8 escape_char, module_type ownerid);
PRIVATE module_type ccci_uart_getownerid(DCL_DEV port);
PRIVATE void ccci_uart_setautobaud_div(DCL_DEV port, module_type owner);
PRIVATE void ccci_uart_register_tx_cb(DCL_DEV port, module_type owner, DCL_UART_TX_FUNC func);
PRIVATE void ccci_uart_register_rx_cb(DCL_DEV port, module_type owner, DCL_UART_RX_FUNC func);
PRIVATE void ccci_uart_ReadDCBConfig(DCL_DEV port, UARTDCBStruct *DCB);
PRIVATE void ccci_uart_CtrlRI (DCL_DEV port, IO_level SRI, module_type ownerid);
PRIVATE void ccci_uart_CtrlDTR(DCL_DEV port, IO_level SDTR, module_type ownerid);
PRIVATE void ccci_uart_ReadHWStatus(DCL_DEV port, IO_level *SDSR, IO_level *SCTS);





//enable GIO and reture the status
PRIVATE kal_uint8 ccci_uart_gio_enable(DCL_DEV port, kal_uint32 option, module_type owner);

//enable GIO and reture the status
PRIVATE kal_uint8 ccci_uart_gio_disable(DCL_DEV port, kal_uint32 option, module_type owner);

PRIVATE void* ccci_gio_putbytes(DCL_DEV port, void* buff, module_type ownerid);

//for gio users to send gpd ptr to HW medium
PRIVATE void* ccci_uart_gio_tx_send_data(DCL_DEV port, void* gpd, kal_uint32 option, module_type owner);

//for gio users to recyle the gpd ptr from HW medium
PRIVATE void* ccci_uart_gio_tx_recycle_gpd(DCL_DEV port, kal_uint32 option, module_type owner);

//empty function with assert(0)
PRIVATE void* ccci_uart_gio_tx_flush_gpd(DCL_DEV port, kal_uint32 option, module_type owner);

//for gio users to receive gpd ptr from HW medium
PRIVATE void* ccci_uart_gio_rx_recv_data(DCL_DEV port, kal_uint32 option, module_type owner);

//for gio users to load gpd ptr to HW medium
PRIVATE void ccci_uart_gio_rx_load_gpd(DCL_DEV port, void* gpd, kal_uint32 option, module_type owner);

PRIVATE void ccci_uart_gio_rx_load_null_gpd(DCL_DEV port, void* gpd, kal_uint32 option, module_type owner);

PRIVATE void ccci_uart_gio_load_dummy_gpd(DCL_DEV port, void* TX_gpd, kal_uint32 TX_size, void* RX_gpd, kal_uint32 RX_size);

//empty function with assert(0)
PRIVATE void* ccci_uart_gio_rx_flush_gpd(DCL_DEV port, kal_uint32 option, module_type owner);


#endif //#if !defined(__SDIO_DEVICE_CONNECTIVITY__)

#endif //end (__MODEM_CCCI_EXIST__)
#endif  /* !__CCCI_UART_H__ */


