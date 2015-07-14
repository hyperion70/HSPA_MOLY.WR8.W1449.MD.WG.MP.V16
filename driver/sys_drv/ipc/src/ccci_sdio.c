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
 *   ccci.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This function implements CCCI.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*******************************************************************************
 * Include header files
 *******************************************************************************/

#include "kal_public_api.h" //MSBB change #include "kal_release.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "kal_internal_api.h"
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
#include "eint.h"
#include "cache_sw.h"
#include "mmu_int.h"
#include "mmu.h"
#include "tst_trace.h"
#include "kal_trace.h"

#include "ps_public_l4_msgid.h"


#define __CCCI_DEBUG_APHANG_ERROR___
//-#define __CCCI_DEBUG_ATCMD_ERROR___

#if defined(__MODEM_CCCI_EXIST__) 
#if defined(__SMART_PHONE_MODEM__)
#include "ccci.h"
#include "ipc_msgsvc.h"
#include "ccci_uart_drv.h"
#include "ipc_rpc.h"
#include "fs_ccci.h"
#include "us_timer.h"
#include "ex_item.h"
#include "ex_public.h"


/*******************************************************************************
 * common part
 *******************************************************************************/
/* MD retrieve shared memory info from AP side */
MODEM_RUNTIME_DATA ap_md_share_data;

/* maintain the index of transaction */
__attribute__  ((zero_init, section ("NONCACHEDZI"))) kal_uint32 ccci_trans_log_index[CCCI_MAX_CHANNEL] ={0};
__attribute__  ((zero_init, section ("NONCACHEDZI"))) kal_uint32 ccci_trans_ack_log_index[CCCI_MAX_CHANNEL] ={0};


/* maintain the content of transaction */
__attribute__  ((zero_init, section ("NONCACHEDZI"))) CCCI_TRANS_LOG ccci_trans_log_pool[CCCI_MAX_CHANNEL][DebugEntryNo]={};
__attribute__  ((zero_init, section ("NONCACHEDZI"))) CCCI_TRANS_LOG ccci_trans_ack_log_pool[CCCI_MAX_CHANNEL][DebugEntryNo]={};

/* for recording the usage of each logical channel */
__attribute__  ((zero_init, section ("NONCACHEDZI"))) CCCI_CTRL_T ccci_ctrl_pool[CCCI_MAX_CHANNEL];

/* system service information sync between AP & MD */
kal_uint32 ccci_tick_update_write_result = 0;
kal_uint32 ccci_exception_check_write_result = 0;
kal_uint32 ccci_exception_info_write_result = 0;
kal_bool  ccci_exception_handshake_done = KAL_FALSE;

extern kal_bool INT_QueryExceptionStatus(void); // Where from ?

INLINE_MODIFIER INLINE kal_uint32 kal_get_systicks();
/*******************************************************************************
 * SDIO part
 *******************************************************************************/

 /*******************************************************************************
 * HW dependency -included files
 *******************************************************************************/
#if ( !defined(__L1_STANDALONE__) && !defined(__MAUI_BASIC__) )
#include "gpd_lib.h"
#endif
#include "stdlib.h"
#include "sdio_fw_api_public.h"

/*******************************************************************************
 * Define private variables.
 *******************************************************************************/
kal_uint32* pgSDIO_NGIO_Handle;
kal_uint32* pgSDIO_GIO_Handle;
kal_uint32 stop_process_channel=0;


/*******************************************************************************
 * Define import global variables.
 *******************************************************************************/

/* the global queue to process info. in SDIO design */
SDIO_QUERY_INFO_ENTRY gTX[TX_num][TX_queue_count]={};
SDIO_QUERY_INFO_ENTRY gRX[RX_num][RX_queue_count]={};
SDIO_QUERY_INFO_ENTRY gGIO_RECYCLE[RECYCLE_queue_count]={};//avoid race condition
SDIO_QUERY_INFO_ENTRY gGIO_RECEIVE[TX_GIO_num][TX_queue_count]={};//avoid race condition


kal_uint32 sdio_tx_readindx[TX_num]={0};
kal_uint32 sdio_tx_writeindx[TX_num]={0};
kal_uint32 sdio_rx_readindx[RX_num]={0};
kal_uint32 sdio_rx_writeindx[RX_num]={0};

kal_uint32 gio_recycle_readindx=0;//avoid race condition
kal_uint32 gio_recycle_writeindx=0;//avoid race condition
kal_uint32 gio_receive_readindx[RX_num]={0};//avoid race condition
kal_uint32 gio_receive_writeindx[RX_num]={0};//avoid race condition

/* the variable should be placed in non-cacheable region since the DMA will transfer the data*/

/* keep the mailbox info in global structure instead of local variable */
__attribute__  ((zero_init, section ("NONCACHEDZI")))	CCCI_BUFF_T gMB[RX_num][RX_queue_count]={};

/* keep the stream info in shared memory*/
__attribute__  ((zero_init, section ("NONCACHEDZI")))	kal_uint8 MDUartShareMemBase[UART_MAX_PORT_NUM][mUartShareMemSize]; 
__attribute__  ((zero_init, section ("NONCACHEDZI")))	kal_uint8 MDMdlogShareMemBase[mMdlogShareMemSize];
__attribute__  ((zero_init, section ("NONCACHEDZI")))	kal_uint8 MDPcmShareMemBase[mPcmShareMemSize];
__attribute__  ((zero_init, section ("NONCACHEDZI")))	kal_uint8 MDRpcShareMemBase[mRpcShareMemSize];
__attribute__  ((zero_init, section ("NONCACHEDZI")))	kal_uint8 MDPmicShareMemBase[mPmicShareMemSize];
__attribute__  ((zero_init, section ("NONCACHEDZI")))	kal_uint8 MDExceShareMemBase[mExceShareMemSize];
__attribute__  ((zero_init, section ("NONCACHEDZI")))	kal_uint8 MDSysShareMemBase[mSysShareMemSize];
__attribute__  ((zero_init, section ("NONCACHEDZI")))	kal_uint8 MDIPCShareMemBase[mIPCShareMemSize];
__attribute__  ((zero_init, section ("NONCACHEDZI")))	kal_uint8 MDFileShareMemBase[mFileShareMemSize];


/* record the usage of gMB*/
kal_uint32 MB_rx_writeindx[RX_num];

#ifdef __CCCI_DEBUG_INFO__
/*open the debug info by define the compile option "__CCCI_DEBUG_INFO__" */
extern void tst_sys_trace(kal_char *);
kal_uint32 ccci_debug_count0 = 0;
kal_uint32 ccci_debug_count1 = 0;
kal_uint32 ccci_debug_count2 = 0;
kal_uint32 memory_loop_back = 0;
kal_uint32 ccci_hisr_count = 0;
#endif

#ifdef __IT_LB__
__attribute__  ((zero_init, section ("NONCACHEDZI"))) kal_uint32 loop_back[TEST_LEN];
__attribute__  ((zero_init, section ("NONCACHEDZI"))) kal_uint32 test_loop_back[TEST_LEN];
kal_uint32 check_index[10] = 0;
kal_eventgrpid event_LB[10];
#endif


void ccci_boot_ack(CCCI_BUFF_T *bufp);
void ccci_system_channel_runtime_callback(CCCI_BUFF_T *bufp);
void ccci_except_ack(CCCI_BUFF_T *bufp);
void ccci_dummy_ack(CCCI_BUFF_T *bufp);
kal_bool ccci_is_channel_need_check_owner(CCCI_CHANNEL_T channel);
/*************************************************************************
* FUNCTION
*  ccci_dbg_print
*
* DESCRIPTION
*  This function prints messages via UART port.
*
* PARAMETERS
*  fmt - the undetermined paramters
*
* RETURNS
*  none
*
*************************************************************************/
#if defined(__CCCI_IT_DEBUG_INFO__)
#include "uart_internal.h"

#define MAXCHARS_CCCI 512
static char ccci_dbg_print_buf[MAXCHARS_CCCI];
volatile unsigned int ccci_dbg_print_fg = 0;
volatile unsigned int ccci_global_rb_cpsr = 0;
volatile unsigned int ccci_global_wb_cpsr = 0;
volatile unsigned int ccci_global_irqmask = 0;

void ccci_itoa(char **buf, int i, int base)
{
    char *s;
	#define ITOA_LEN 20
    int rem;
    static char rev[ITOA_LEN+1];

    rev[ITOA_LEN] = 0;
    if (i == 0)
    {
        (*buf)[0] = '0';
        ++(*buf);
        return;
    }
    s = &rev[ITOA_LEN];
    while (i)
    {
        rem = i % base;
        if (rem < 10)
            *--s = rem + '0';
        else if (base == 16)
            *--s = "abcdef"[rem - 10];
        i /= base;
    }
    while (*s)
    {
        (*buf)[0] = *s++;
        ++(*buf);
    }
}

void ccci_dbg_print(char *fmt,...)
{

    va_list ap;
    double dval;
    int ival, fract, i, j;
    unsigned int uival, uival1, uival2;
    char *p, *sval, *bp, cval, *bp_old;
    char prefix[20];

    ccci_global_irqmask = SaveAndSetIRQMask();
    
    bp = ccci_dbg_print_buf;
    *bp = 0;
    
    va_start(ap, fmt);

    for (p = fmt; *p; p++)
    {
        if (*p != '%')
        {
            *bp++= *p;
            continue;
        }

        switch (*++p) 
        {
            case 'd':
                ival= va_arg(ap, int);
                if (ival < 0)
                {
                    *bp++= '-';
					ival= -ival;
                }
                ccci_itoa (&bp, ival, 10);
                break;
            case 'o':
                ival= va_arg(ap, int);
                if (ival < 0)
                {
                    *bp++= '-';
					ival= -ival;
                }
                *bp++= '0';
                ccci_itoa (&bp, ival, 8);
                break;

            case 'x':
                uival= va_arg(ap, unsigned int);
                *bp++= '0';
                *bp++= 'x';
                bp_old = bp;

                uival1 = uival >> 16;
                uival2 = uival & 0x0000ffff;

                ccci_itoa(&bp, uival1, 16);

                i = (kal_uint32)bp - (kal_uint32)bp_old;

                if (i < 4) 
				{
                    for (j = 3; j > (3 - i); j--) 
					{
                        bp_old[j] = bp_old[j - (3 - i) - 1];
                    }
            
                    for (j = 0; j <= (3 - i); j++)
                        bp_old[j] = '0';
                }

                bp = bp_old + 4;

                bp_old = bp;

                ccci_itoa(&bp, uival2, 16);

                i = (kal_uint32)bp - (kal_uint32)bp_old;

                if (i < 4) 
				{          
                    for (j = 3; j > (3 - i); j--) 
					{
                        bp_old[j] = bp_old[j - (3 - i) - 1];
                    }
            
                    for (j = 0; j <= (3 - i); j++)
                        bp_old[j] = '0';
                }

                bp = bp_old + 4;

                break;
             
            case 'c':
                cval= va_arg(ap, int);
                *bp++= cval;
                break;
             
            case 's':
                for (sval = va_arg(ap, char *) ; *sval ; sval++ )
                   *bp++= *sval;
                break;
        }
    }
   
    *bp= 0;

    /* send to UART without using interrupt mode */
    for (bp = ccci_dbg_print_buf; *bp; bp++) 
    {
        U_PutUARTByte(0, *bp);
    }

    ccci_dbg_print_fg = 1;
    va_end (ap);
    ccci_dbg_print_fg = 2;
    RestoreIRQMask(ccci_global_irqmask);
    ccci_dbg_print_fg = 10;
    ccci_dbg_print_fg = 0;
}
#endif // end __CCCI_IT_DEBUG_INFO__


/*************************************************************************
 *FUNCTION
 *	get_gio_handle
 *
 *DESCRIPTION
 *	This function is to get the handler of gio
 *
 *PARAMETERS
 *    none
 *
 *RETURNS
 *	gio handle
 *
*************************************************************************/
kal_uint32* get_gio_handle()
{
    return pgSDIO_GIO_Handle;
}


/*************************************************************************
 *FUNCTION
 *	get_ngio_handle
 *
 *DESCRIPTION
 *	This function is to get the handle of non-gio
 *
 *PARAMETERS
 *    none
 *
 *RETURNS
 *	non-gio handle
 *
*************************************************************************/
kal_uint32* get_ngio_handle()
{
    return pgSDIO_NGIO_Handle;
}

/*************************************************************************
 *FUNCTION
 *	sdio_ccci_init
 *
 *DESCRIPTION
 *	This function is to initialize HW medium
 *
 *PARAMETERS
 *    none
 *
 *RETURNS
 *	none
 *
*************************************************************************/
void sdio_ccci_init(void)
{
    SDIO_STATUS status;
    SDIO_USER_REQ_DESCRIPTOR CCCI_Req, GIO_Req;
    
    #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		kal_char debug_info[100];
    #endif

    #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		sprintf(debug_info, "into sdio_ccci_init .. \r\n");
		CCCI_TRACE(debug_info);
    #endif
    /*sdio initialization*/
    status = sdio_init();
    if(status != (SDIO_STATUS)KAL_SUCCESS)
    {
        #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
			sprintf(debug_info, "SDIO initialization fail!! please ask SDIO driver owner .. \r\n");
			CCCI_TRACE(debug_info);
		#endif
			ASSERT(0);
    }

    /***********************************************
     *for Non-GIO user (shared memory mode)
     **********************************************/
    /* configure for non-GIO user */
    CCCI_Req.User_Type = FLAG_NONGIO_BUFFER;

    /* configure the TX num */
    CCCI_Req.TQ_Num_Req = SDIO_NONGIO_TQ_NUM;

    /* configure the RX num */
    CCCI_Req.RQ_Num_Req = SDIO_NONGIO_RQ_NUM;
    
    status = sdio_open(&pgSDIO_NGIO_Handle, &CCCI_Req);

    if(status != (SDIO_STATUS)KAL_SUCCESS)
    {
		#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
			sprintf(debug_info, "SDIO open fail!! please ask SDIO driver owner .. \r\n");
			CCCI_TRACE(debug_info);
		#endif
			ASSERT(0);
    }	

    /***********************************************
     *for GIO user (user control mode)
     **********************************************/
    /* configure for GIO user */
    GIO_Req.User_Type = FLAG_GIO_BUFFER;
	
    /* configure the TX num */
    GIO_Req.TQ_Num_Req = SDIO_GIO_TQ_NUM;
	
    /* configure the RX num */ 	
    GIO_Req.RQ_Num_Req = SDIO_GIO_RQ_NUM;

    status = sdio_open(&pgSDIO_GIO_Handle, &GIO_Req);
	
    if(status != (SDIO_STATUS)KAL_SUCCESS)
    {	
		#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
			sprintf(debug_info, "SDIO open fail!! please ask SDIO driver owner .. \r\n");
			CCCI_TRACE(debug_info);
		#endif
		ASSERT(0);
    }

    /* register HISR */
    DRV_Register_HISR(DRV_CCIF_HISR_ID, ccci_hisr);
    
}

/*************************************************************************
* FUNCTION
*  get_TotalQ_num
*
* DESCRIPTION
*  This function processes HW queue number.
*
* PARAMETERS
*  none
*
* RETURNS
*  HW queue number
*
*************************************************************************/
kal_uint32 get_TotalQ_num(void)
{
    return TX_num + RX_num;//8
}


/*************************************************************************
* FUNCTION
*  get_TX_NGIOQ_index
*
* DESCRIPTION
*  This function processes HW queue number of TX NGIO.
*
* PARAMETERS
*  none
*
* RETURNS
*  HW queue number of TX NGIO
*
*************************************************************************/
kal_uint32 get_TX_NGIOQ_index(void)
{
    return TX_num-TX_GIO_num;//0~1
}


/*************************************************************************
* FUNCTION
*  get_TX_GIOQ_index
*
* DESCRIPTION
*  This function processes HW queue number of TX GIO.
*
* PARAMETERS
*  none
*
* RETURNS
*  HW queue number of TX GIO
*
*************************************************************************/
kal_uint32 get_TX_GIOQ_index(void)
{
    return TX_num;//2~4
}


/*************************************************************************
* FUNCTION
*  get_RX_NGIOQ_index
*
* DESCRIPTION
*  This function processes HW queue number of RX NGIO.
*
* PARAMETERS
*  none
*
* RETURNS
*  HW queue number of RX NGIO
*
*************************************************************************/
kal_uint32 get_RX_NGIOQ_index(void)
{
    return TX_num + RX_num - RX_GIO_num;//5~6
}


/*************************************************************************
* FUNCTION
*  get_RX_GIOQ_index
*
* DESCRIPTION
*  This function processes HW queue number of RX GIO.
*
* PARAMETERS
*  none
*
* RETURNS
*  HW queue number of RX GIO
*
*************************************************************************/
kal_uint32 get_RX_GIOQ_index(void)
{
    return TX_num + RX_num;//7
}


/*************************************************************************
* FUNCTION
*  dispatch_info
*
* DESCRIPTION
*  This function is to dispatch info to correct channel.
*
* PARAMETERS
*  channel    -    logical channel
*
* RETURNS
*  N/A.
*
*************************************************************************/
void dispatch_info(CCCI_BUFF_T * buff)
{
    kal_uint32 logic_channel;
    kal_uint32 element;
    //kal_uint32 mask; //don't need to mask IRQ in HISR level since there are only HISR & Task level will modify the shared resource
	
    #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		kal_char debug_info[100];
    #endif

    //get the corresponding channel#
    logic_channel = buff->channel;

	//debug avoid mis-use channel num
	if(logic_channel != 0 && logic_channel != 1 && logic_channel != 2 && logic_channel != 3 &&
	   logic_channel != 4 && logic_channel != 5 && logic_channel != 6 && logic_channel != 8 &&
	   logic_channel != 10&& logic_channel != 12&& logic_channel != 14&& logic_channel != 15&&
	   logic_channel != 16&& logic_channel != 17&& logic_channel != 18&& logic_channel != 19&&
	   logic_channel != 20&& logic_channel != 22&& logic_channel != 24&& logic_channel != 26&&
	   logic_channel != 28&& logic_channel != 30&& logic_channel != 32&& logic_channel != 33&&
	   logic_channel != 34&& logic_channel != 36&& logic_channel != 38&& logic_channel != 40&&
	   logic_channel != 42&& logic_channel != 43)
	   EXT_ASSERT(0, logic_channel, 0, 0);
    /* check the logic channel number info */
    if(logic_channel == CCCI_FORCE_RESET_MODEM_CHANNEL)
    {
    	//the AP side RIL module/QA will through the method to force MD reset
    	#define FORCE_RESET_MODEM   (0)

		#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		sprintf(debug_info, "<AP>[CCCI_FORCE_RESET_MODEM_CHANNEL]");
		CCCI_TRACE(debug_info);
        #endif
        EXT_ASSERT(FORCE_RESET_MODEM, logic_channel, 0, 0);
    }
    else if(logic_channel >= CCCI_MAX_CHANNEL)
    {
		#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		sprintf(debug_info, "<AP>[CCCI_MAX_CHANNEL] log_chann=%d",logic_channel);
		CCCI_TRACE(debug_info);
        #endif
    	EXT_ASSERT(0, logic_channel, 0, 0);
    }

    /* check the log channel state info */
    if (ccci_ctrl_pool[logic_channel].state == CCCI_ACTIVE_READ)
    {
		/* use OR operation since a ccci_read() is waiting */
		ccci_ctrl_pool[logic_channel].state |= CCCI_ACTIVE_ISR;
    }
    else if (ccci_ctrl_pool[logic_channel].state == CCCI_IDLE)
    {
		ccci_ctrl_pool[logic_channel].state = CCCI_ACTIVE_ISR;
    }
    else if (ccci_ctrl_pool[logic_channel].state == CCCI_ACTIVE_WRITE)
    {
		/* a ccci_write() is not finished */
		#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		sprintf(debug_info, "<Wrong operation> logic_channel=%d,state=%d", logic_channel, ccci_ctrl_pool[logic_channel].state);
		CCCI_TRACE(debug_info);
        #endif
		EXT_ASSERT(0, logic_channel, ccci_ctrl_pool[logic_channel].state, 0);
    }
    else if (ccci_ctrl_pool[logic_channel].state == CCCI_ACTIVE_ISR)
    {
		/* continue or not: 0 yes, 1 no */
		stop_process_channel = 1;
    }
    else
    {
		#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		sprintf(debug_info, "<Unknown state> logic_channel=%d,state=%d", logic_channel, ccci_ctrl_pool[logic_channel].state);
		CCCI_TRACE(debug_info);
        #endif
		EXT_ASSERT(0, logic_channel, ccci_ctrl_pool[logic_channel].state, 0);
    }
			
    /* execute the callback function */
    if (ccci_ctrl_pool[logic_channel].funp == NULL) 
    {
		#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		sprintf(debug_info, "<NULL_PTR in CB> log_chann=%d, owner=%d", logic_channel, ccci_ctrl_pool[logic_channel].owner);
		CCCI_TRACE(debug_info);
        #endif
    	EXT_ASSERT(0, logic_channel, 0, 0);
    } 
    else
    {
		/* copy the sdio buffer into ccci control buffer pool*/
		for (element=0 ; element< 4; element++)
		{
			*(((volatile unsigned long *)&(ccci_ctrl_pool[logic_channel].buff)) + element )= *((volatile unsigned long *)buff +element);
		}
		#ifdef __IT_LB__	 //for stream case in loop back
			if(CCCI_IS_MAILBOX(buff))
			{
				;			
			}
			else
			{
				kal_uint32 temp_index;
				#ifdef __CCCI_DEBUG_INFO__
				memory_loop_back++;
				#endif
					
				element = (buff->data[1]+3) >> 2;
				for (temp_index=0 ; temp_index< element; temp_index++)
				{
					*(((volatile unsigned long *)&(loop_back)) + temp_index )= *((volatile unsigned long *)buff +temp_index);
				}
			}
		#endif
    }				


    /* check the channel state and record the transaction info for CCCI debug */
    if (ccci_ctrl_pool[logic_channel].state & CCCI_ACTIVE_ISR) 
    {
		if(logic_channel == 0  || logic_channel == 2  || logic_channel == 4  || logic_channel == 6  ||
		   logic_channel == 10 || logic_channel == 14 || logic_channel == 16 || logic_channel == 18 ||
		   logic_channel == 20 || logic_channel == 24 || logic_channel == 30 || logic_channel == 32 ||
		   logic_channel == 34 || logic_channel == 38 || logic_channel == 42)
		{
			ccci_trans_ack_log_pool[logic_channel][ccci_trans_ack_log_index[logic_channel]].tick = kal_get_systicks();
	   		kal_mem_cpy(&(ccci_trans_ack_log_pool[logic_channel][ccci_trans_ack_log_index[logic_channel]].ct), &ccci_ctrl_pool[logic_channel], sizeof(CCCI_CTRL_T));
			ccci_trans_ack_log_index[logic_channel]++;
	   		ccci_trans_ack_log_index[logic_channel]%=(DebugEntryNo);
		}
		else
		{
			ccci_trans_log_pool[logic_channel][ccci_trans_log_index[logic_channel]].tick = kal_get_systicks();
	   		kal_mem_cpy(&(ccci_trans_log_pool[logic_channel][ccci_trans_log_index[logic_channel]].ct), &ccci_ctrl_pool[logic_channel], sizeof(CCCI_CTRL_T));
			ccci_trans_log_index[logic_channel]++;
	   		ccci_trans_log_index[logic_channel]%=(DebugEntryNo);
		}
		if (ccci_ctrl_pool[logic_channel].state & CCCI_ACTIVE_READ) 
		{
		    /* set for CCCI_READ API */
	       	    kal_set_eg_events(ccci_ctrl_pool[logic_channel].event, 1, KAL_OR);
	   	    ccci_ctrl_pool[logic_channel].state = CCCI_ACTIVE_READ;
		} 
		else 
		{
		    #ifndef __IT_LB__ // for real version
		    if(CCCI_IS_MAILBOX(buff))
		        ccci_ctrl_pool[logic_channel].funp(&(ccci_ctrl_pool[logic_channel].buff));
		    else
		        ccci_ctrl_pool[logic_channel].funp(buff);			
		    #endif
				
		    #ifdef  __IT_LB__ //for loop back version
		    if(CCCI_IS_MAILBOX(buff))
		        ccci_ctrl_pool[logic_channel].funp(&(ccci_ctrl_pool[logic_channel].buff));
		    else
				ccci_ctrl_pool[logic_channel].funp((CCCI_BUFF_T*) &loop_back);
		    #endif
			
	        /* set IDLE */
	       	ccci_ctrl_pool[logic_channel].state = CCCI_IDLE;
		    stop_process_channel = 0;
		}
    } 	
}


/*************************************************************************
* FUNCTION
*  ccci_hisr
*
* DESCRIPTION
*  This function processes CCCI HISR.
*
* PARAMETERS
*  none
*
* RETURNS
*  none
*
*************************************************************************/
extern kal_uint32 UPS_enqueue;
extern kal_uint32 UPS_dequeue;

//static kal_uint32 ccci_rtr_count=0;
static kal_uint32 ccci_rtw_count=0;
//using global var. instead of local var. is to avoid DRV_HISR stack overflow
/* the first flag is the elememt number in each queue, others are status of data buffer */


SDIO_QUERY_INFO_ENTRY query_TX[TX_num][TX_queue_count] = {};
SDIO_QUERY_INFO_ENTRY query_RX[RX_num][RX_queue_count] = {};

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
#endif

kal_uint32 queue_ptr[TX_num+RX_num] = { 
    (kal_uint32) &query_TX[0][0],
    (kal_uint32) &query_TX[1][0],
    (kal_uint32) &query_TX[2][0],
    (kal_uint32) &query_TX[3][0],
    (kal_uint32) &query_TX[4][0],
    (kal_uint32) &query_RX[0][0],
    (kal_uint32) &query_RX[1][0],
    (kal_uint32) &query_RX[2][0]
    };
void ccci_hisr(void)
{
    //kal_uint32 mask;
    kal_uint32 element, index;
    CCCI_BUFF_T *buff, backup_buff;
    CCCI_BUFF_T *ccci_buff;
	
    #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
    kal_char debug_info[100];
    #endif
	
    kal_uint32 read_index, write_index;
    kal_uint32 gio_read_index, gio_write_index;



    #ifdef __CCCI_DEBUG_INFO__
		ccci_hisr_count++;
    #endif

    #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		sprintf(debug_info, "in ccci_hisr .. \r\n");
		CCCI_TRACE(debug_info);
    #endif

    /********************************************************************
     *  CCCI can query the SDIO queues when HISR is triggered by SDIO LISR
     * by sdio_query_information(gSDIO_Handle, &queue_ptr[0], &queue_ptr[TX_num])
     * query the TX and RX info. individuallly
     ********************************************************************/
    sdio_query_information(&queue_ptr[0], &queue_ptr[TX_num]);

    /********************************************************************
     *processing the TX content according the CCCI header descriptor
     *should we take care the race condition? in actually the gTX/gRX is updated in HISR 
     *(no LISR or other higher HISR will to use gTX/gRX)hence, in my opion, it doesn't need to protect
     ********************************************************************/

    /* processing the TX content according the CCCI header descriptor */
    for(index=0; index < TX_num; index++)
    {
		//the first one is the the counter information
		element = 1;
		/* parse the queue with the counter info. in each queue head (0) */
		#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
			sprintf(debug_info, "TX count = %d .. \r\n", query_TX[index][0].flags);
			CCCI_TRACE(debug_info);
	  	#endif

		while(query_TX[index][0].flags != 0)
		{	
		    #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
			    sprintf(debug_info, "gTX[%d][%d] .. \r\n", index, sdio_tx_writeindx[index]);
			    CCCI_TRACE(debug_info);
	    	#endif	
			
		    gTX[index][sdio_tx_writeindx[index]] = query_TX[index][element++];
			sdio_tx_writeindx[index]++;
	 		sdio_tx_writeindx[index] = (sdio_tx_writeindx[index])%TX_queue_count;		

		    #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
			    sprintf(debug_info, "g[%d][%d] .. \r\n", index, sdio_tx_writeindx[index]);
			    CCCI_TRACE(debug_info);
	    	#endif

		    query_TX[index][0].flags--;
		}
    }

    /* processing the RX content according the CCCI header descriptor */
    for(index = 0; index < RX_num; index++)
    {
		//the first one is the the counter information
		element = 1;
		/* parse the queue with the counter info. in each queue head (0) */
		#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
			sprintf(debug_info, "RX count = %d .. \r\n", query_RX[index][0].flags);
			CCCI_TRACE(debug_info);
    	#endif

		while(query_RX[index][0].flags != 0)
		{
			if(index == 1)
				ASSERT(0);
		    #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
			    sprintf(debug_info, "gRX[%d][%d] .. \r\n", index, sdio_rx_writeindx[index]);
			    CCCI_TRACE(debug_info);
	    	#endif
		    gRX[index][sdio_rx_writeindx[index]] = query_RX[index][element++];
			sdio_rx_writeindx[index]++;
	 		sdio_rx_writeindx[index] = (sdio_rx_writeindx[index])%RX_queue_count;	
		    //if(sdio_rx_writeindx[index] >= RX_queue_count)
		    //    sdio_rx_writeindx[index] %= RX_queue_count;
		    #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
				sprintf(debug_info, "gRX[%d][%d] .. \r\n", index, sdio_rx_writeindx[index]);
				CCCI_TRACE(debug_info);
	    	#endif
	    	query_RX[index][0].flags--;			
		}
    }

    /* fill the CCCI control block information sequentially */
    index = get_TotalQ_num();
    while ( index != 0 )
    {
		index--;
		//if(index < get_TX_NGIOQ_index())
		if(index == 0 || index == 1)	
		{
		    /*the buff include the space of GPD header and CCCI header and data buffer */
		    /********************************************************************
		     * |-----------|
		     * |CCCI header|
		     * |-----------|
		     * |data buffer|
		     * -------------
		     ********************************************************************/
			
		    /* update the read/write index of ring buffer */
		    #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
			    sprintf(debug_info, "=====================NGIO TX==========================\r\n");
			    CCCI_TRACE(debug_info);
			    sprintf(debug_info, "sdio_tx_writeindx[%d]= %d .. \r\n", index, sdio_tx_writeindx[index]);
			    CCCI_TRACE(debug_info);
			    sprintf(debug_info, "sdio_tx_readindx[%d]= %d .. \r\n", index, sdio_tx_readindx[index]);
			    CCCI_TRACE(debug_info);
			    sprintf(debug_info, "======================================================\r\n");
			    CCCI_TRACE(debug_info);
	    	#endif
		    if(sdio_tx_writeindx[index] < sdio_tx_readindx[index])
		        write_index = sdio_tx_writeindx[index] + TX_queue_count;
		    else
		        write_index = sdio_tx_writeindx[index];
				
		    read_index = sdio_tx_readindx[index];
				
		    #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
			    sprintf(debug_info, "======= (W, R) = (%d, %d) in TX NGIOQ ======= \r\n", write_index, read_index);
			    CCCI_TRACE(debug_info);
	    	#endif

		    while(write_index > read_index && stop_process_channel == 0)		  
		    {
		        #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
				 	sprintf(debug_info, "(W, R) = (%d, %d) in TX NGIOQ .. \r\n", write_index, read_index);
			  	 	CCCI_TRACE(debug_info);
	    		#endif
			 	//buff = (volatile CCCI_BUFF_T *)(gTX[index][(read_index)%queue_count].buffer_addr);		
			 	buff = ( CCCI_BUFF_T *)(gTX[index][(read_index)%TX_queue_count].buffer_addr);		

				#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
					sprintf(debug_info, "buff address =%x in TX .. \r\n", (gTX[index][(read_index)%TX_queue_count].buffer_addr));
				  	CCCI_TRACE(debug_info);
	    		#endif

			    if(CCCI_IS_MAILBOX(buff))
			    {
    			    #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
	    			    sprintf(debug_info, "TQ %d MB = (%x, %x, %x, %x) .. \r\n",index, buff->data[0], buff->data[1], buff->channel, buff->reserved);
	    		  	    CCCI_TRACE(debug_info);
	    		    #endif

					/* backup the mailbox content and  release the mailbox memory to SDIO driver */
				    kal_mem_cpy((void *) &backup_buff, (void *)buff, sizeof(CCCI_BUFF_T));
				    sdio_recycle_multiple_buffer(get_ngio_handle(), (kal_uint32*) &gTX[index][(read_index)%TX_queue_count], 1);
				    buff = (CCCI_BUFF_T *)&backup_buff;
			 	}
			 	else//for stream type
			 	{
			    	#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
				     	sprintf(debug_info, "TQ %d Stream = (%x, %x, %x, %x) .. \r\n",index, buff->data[0], buff->data[1], buff->channel, buff->reserved);
			  	     	CCCI_TRACE(debug_info);
	    		    #endif
			 	}
				
				dispatch_info(buff);
				read_index = read_index + 1;
				sdio_tx_readindx[index] = (read_index) % TX_queue_count;
		    }
		}
	#if ( !defined(__L1_STANDALONE__) && !defined(__MAUI_BASIC__) )
		else if(index == 2 || index == 3 || index == 4)
		{			
		    /***********************************************************
		        * [GPD header]-->[CCCI header]-->[data buffer]
		        ***********************************************************/
		    #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
				sprintf(debug_info, "=====================GIO TX==========================\r\n");
				CCCI_TRACE(debug_info);
				sprintf(debug_info, "sdio_tx_writeindx[%d]= %d .. \r\n", index, sdio_tx_writeindx[index]);
				CCCI_TRACE(debug_info);
				sprintf(debug_info, "sdio_tx_readindx[%d]= %d .. \r\n", index, sdio_tx_readindx[index]);
				CCCI_TRACE(debug_info);
				sprintf(debug_info, "======================================================\r\n");
				CCCI_TRACE(debug_info);
	 	    #endif
	
		    read_index = sdio_tx_readindx[index];
			write_index = sdio_tx_writeindx[index];
			
		    #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
			    sprintf(debug_info, "======= (W, R) = (%d, %d) in TX GIOQ ======= \r\n", write_index, read_index);
			    CCCI_TRACE(debug_info);
	  	    #endif

            if ( (read_index >= TX_queue_count) || (write_index >= TX_queue_count) ) ASSERT(0);
            

            if ( write_index != read_index )
            {
                element = (index-TX_GIO_base);
                gio_read_index = gio_receive_readindx[element];
                gio_write_index = gio_receive_writeindx[element];
            
                while( (write_index != read_index) && stop_process_channel == 0)
    		    {	
    		        #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
    					sprintf(debug_info, "(W, R) = (%d, %d) in TX GIOQ .. \r\n", write_index, read_index);
    				  	CCCI_TRACE(debug_info);
    	    		#endif	
        		
    				/* retrieve the CCCI header info from UPS data lib*/
    				ccci_buff = ( CCCI_BUFF_T *)gpd_lib_sdio_tx_getCCCIHeader((gpd_node*)gTX[index][read_index].buffer_addr);
                    dispatch_info(ccci_buff);
					
    				#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
						sprintf(debug_info, "TQ %d MB = (%x, %x, %x, %x) .. \r\n", index, ccci_buff->data[0], ccci_buff->data[1], ccci_buff->channel, ccci_buff->reserved);
						CCCI_TRACE(debug_info);
    		    	#endif

    				//keep recycle data and free data in uart recycle API
                    {         
    				    gGIO_RECEIVE[element][gio_write_index] = gTX[index][read_index];
    				    gio_write_index++;
				    gio_write_index = (gio_write_index)%TX_queue_count;

                        if ( gio_write_index == gio_read_index ) ASSERT(0);                        
                    }

    				// Don't update becuase read pointers are only updated in ccci_gio_recev_data()
    				read_index++;
                    read_index %= TX_queue_count;
    	    	}

                sdio_tx_readindx[index] = read_index;
                gio_receive_writeindx[element] = gio_write_index;
            }
		}
	#endif//( !defined(__L1_STANDALONE__) && !defined(__MAUI_BASIC__) )
		else if(index == 5 || index == 6)
		{
	  	    #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
			    sprintf(debug_info, "=====================NGIO RX==========================\r\n");
			    CCCI_TRACE(debug_info);
			    sprintf(debug_info, "sdio_rx_writeindx[%d]= %d .. \r\n", index, sdio_rx_writeindx[index-TX_num]);
			    CCCI_TRACE(debug_info);
			    sprintf(debug_info, "sdio_rx_readindx[%d]= %d .. \r\n", index, sdio_rx_readindx[index-TX_num]);
			    CCCI_TRACE(debug_info);
			    sprintf(debug_info, "======================================================\r\n");
			    CCCI_TRACE(debug_info);
	    	#endif
			
		    if(sdio_rx_writeindx[index-TX_num] < sdio_rx_readindx[index-TX_num])
		        write_index = sdio_rx_writeindx[index-TX_num] + RX_queue_count;
		    else
		        write_index = sdio_rx_writeindx[index-TX_num];
				
		    read_index = sdio_rx_readindx[index-TX_num];
				
		    #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
			    sprintf(debug_info, "======= (W, R) = (%d, %d) in RX NGIOQ ======= \r\n", write_index, read_index);
		  	    CCCI_TRACE(debug_info);
	   	    #endif

		    while(write_index > read_index && stop_process_channel == 0)
		    {
				#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
					sprintf(debug_info, "(W, R) = (%d, %d) in RX NGIOQ .. \r\n", write_index, read_index);
			  		CCCI_TRACE(debug_info);
		   		#endif
				buff = (CCCI_BUFF_T *)(gRX[index-TX_num][(read_index)%RX_queue_count].buffer_addr);
			
				#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
					sprintf(debug_info, "buff address =%x in RX .. \r\n", buff);
			  		CCCI_TRACE(debug_info);
		   		#endif
				
				if(CCCI_IS_MAILBOX(buff))
				{
				    #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
					    sprintf(debug_info, "RQ %d MB = (%x, %x, %x, %x) .. \r\n", index-TX_num,  buff->data[0], buff->data[1], buff->channel, buff->reserved);
			  		    CCCI_TRACE(debug_info);
		   		    #endif
				    kal_mem_cpy((void*) &backup_buff, buff, sizeof(CCCI_BUFF_T));
				    buff = &backup_buff;
			    }
				else
				{
				    #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
					    sprintf(debug_info, "RQ %d, Stream = (%x, %x, %x, %x) .. \r\n", index, buff->data[0], buff->data[1], buff->channel, buff->reserved);
			  		    CCCI_TRACE(debug_info);
		   		    #endif
				}
				dispatch_info(buff);
				read_index = read_index + 1;
				sdio_rx_readindx[index-TX_num] = (read_index) % RX_queue_count;
		    }
		}
	#if ( !defined(__L1_STANDALONE__) && !defined(__MAUI_BASIC__) )
		else if( index == 7 )
		{

		    #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
			    sprintf(debug_info, "=====================GIO RX==========================\r\n");
		  	    CCCI_TRACE(debug_info);
			    sprintf(debug_info, "sdio_rx_writeindx[%d]= %d .. \r\n", index, sdio_rx_writeindx[index-TX_num]);
		  	    CCCI_TRACE(debug_info);
			    sprintf(debug_info, "sdio_rx_readindx[%d]= %d .. \r\n", index, sdio_rx_readindx[index-TX_num]);
		  	    CCCI_TRACE(debug_info);
			    sprintf(debug_info, "======================================================\r\n");
		  	    CCCI_TRACE(debug_info);
		    #endif
                
                element = (index-TX_num);
    			read_index = sdio_rx_readindx[element];
    			write_index = sdio_rx_writeindx[element];

		    #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
			    sprintf(debug_info, "======= (W, R) = (%d, %d) in RX GIOQ ======= \r\n", write_index, read_index);
		  	    CCCI_TRACE(debug_info);
	   	    #endif

                if ( (read_index >= RX_queue_count) || (write_index >= RX_queue_count) ) ASSERT(0);

                if ( write_index != read_index )
                {                
                    gio_read_index = gio_recycle_readindx;
                    gio_write_index = gio_recycle_writeindx;
                
        		    while( (write_index != read_index) && stop_process_channel == 0 )
					{
						#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
							sprintf(debug_info, "(W, R) = (%d, %d) in RX GIOQ .. \r\n", write_index, read_index);
							CCCI_TRACE(debug_info);
						#endif
						//avoid invalid case when SDIO transfer more gpd node than ups sent
        				if(UPS_dequeue > UPS_enqueue) ASSERT(0);
                        
        				/* remove the CCCI header from UPS data content (the requirement from Stan Chen) */
        				//if(!gpd_lib_umts_delHeader((volatile gpd_node*)(gRX[element][(read_index)].buffer_addr), (kal_uint8 **) &ccci_buff))
						gpd_lib_umts_delHeader((gpd_node*)(gRX[element][(read_index)].buffer_addr), (kal_uint8 **) &ccci_buff);

                        ccci_rtw_count++;
                        if ( ccci_rtw_count >= 5 )
                        {
                            dispatch_info(ccci_buff);
                            ccci_rtw_count = 0;
                        }
						#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
							sprintf(debug_info, "RQ%d Stream = (%x, %x, %x, %x) .. \r\n", index-TX_num, ccci_buff->data[0], ccci_buff->data[1], ccci_buff->channel, ccci_buff->reserved);
							CCCI_TRACE(debug_info);
						#endif

						//keep recycle data and free data in uart recycle API
                        {                    
            				gGIO_RECYCLE[gio_write_index] = gRX[element][read_index];
					gio_write_index++;
            				gio_write_index = (gio_write_index)%RECYCLE_queue_count;

                            if ( gio_write_index == gio_read_index ) ASSERT(0);                           
                        }

                        read_index++;
        				read_index %= RX_queue_count;
        		    }

                    sdio_rx_readindx[element] = read_index;
                    gio_recycle_writeindx = gio_write_index;
                }
		}
	#endif
    }
}


/*************************************************************************
 *FUNCTION
 *	valid_channel
 *
 *DESCRIPTION
 *	This function is to check the validation in RQ0
 *
 *PARAMETERS
 *	RX_queue: the selected queue number
 *
 *RETURNS
 *	status : 0->invalid, 1->valid
 *
*************************************************************************/
kal_uint32 valid_channel(kal_uint32 RX_queue, CCCI_CHANNEL_T channel)
{
    switch(RX_queue)
    {
		case 0://others
		{
			if(channel == CCCI_CONTROL_CHANNEL     ||
			   channel == CCCI_SYSTEM_CHANNEL 	   ||
			   channel == CCCI_PCM_CHANNEL	       ||
			   channel == CCCI_TST_CHANNEL    	   ||
			   channel == CCCI_AT_CHANNEL_TX  	   ||
			   channel == CCCI_FS_CHANNEL     	   ||
			   channel == CCCI_PMIC_CHANNEL    	   ||
			   channel == CCCI_UEM_CHANNEL    	   ||
			   channel == CCCI_IPC_RPC_CHANNEL 	   ||
			   channel == CCCI_MSGSVC_SEND_CHANNEL ||
			   channel == CCCI_GPS_CHANNEL_TX      )
				return 1;
			else
				return 0;
		}
		break;
		case 1://MDLogger
		{
			if(channel == CCCI_MD_LOG_RX) //sync with shengkai
				return 1;
			else
				return 0;
		}
		break;
		case 2://Network
		{
			if(channel == CCCI_CCMNI1_RX ||
			   channel == CCCI_CCMNI2_RX || 
			   channel == CCCI_CCMNI3_RX )
				return 1;
			else
				return 0; 
		}
		break;
		default:
		{
			return 0;	
		}
    }
}

/*************************************************************************
 *FUNCTION
 *	ccci_write_internal
 *
 *DESCRIPTION
 *	This function is to write content into SDIO
 *
 *PARAMETERS
 *	channel        -        the selected logic channel
 *    buff             -        the transfer data pointer
 *    check lisr      -        check the execute unit is lisr or not
 *    rx_queue      -        which SDIO queue is choose
 *
 *RETURNS
 *	status
 *
*************************************************************************/
extern void tst_sys_trace(kal_char *);
kal_char channel_info[100];
__attribute__  ((section ("INTSRAM_ROCODE"))) kal_int32 ccci_write_internal_sdio(CCCI_CHANNEL_T channel, CCCI_BUFF_T *buff, kal_bool check_lisr, kal_uint32 rx_queue)
{
    kal_uint32 owner, mask, select_queue = 0, available;
    kal_int32 ret;
    CCCI_BUFF_T *ccci_buff=NULL;
    SDIO_STATUS status;
    SDIO_BUFFER_DESCRIPTOR bd;
	
    #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		kal_char debug_info[100];
    #endif

    /* avoid race condiction with dispatch_info by using SaveAndSetIRQMask() */
    mask = SaveAndSetIRQMask();
	
	if(channel == CCCI_MD_LOG_RX)
		ASSERT(0); //MDLogger is not supported in CCCI on SDIO yet
    /* check if a LISR is running */
    if (1 == check_lisr) 
    { 
    	if (kal_if_lisr())
		{
			RestoreIRQMask(mask);
            return CCCI_IN_LISR;
		}	
    }

    /* check parameters */
    if (channel >= CCCI_MAX_CHANNEL)
	{
		RestoreIRQMask(mask);
        return CCCI_INVALID_PARAM;
	}
	
    if (buff == NULL)
	{
		RestoreIRQMask(mask);
        return CCCI_INVALID_PARAM;
	}

    /* get the current task */
    owner = (kal_uint32)kal_get_current_thread_ID();

	/* check owner */
    if (ccci_ctrl_pool[channel].owner != owner && ccci_is_channel_need_check_owner(channel) ) 
    {
		RestoreIRQMask(mask);
        return CCCI_NOT_OWNER;
    }

	
   /********************************************************************
    * 	determine the value of RX queue
    *	RX RT mailbox/normal/stream data queue => 0
    *   RX MDLogger queue => 1
    *   RX network data => 2
    *
    ********************************************************************/
    select_queue = rx_queue;
	
    /* error check*/
    if(rx_queue == 0)
    {
        /********************************************************************
    	 *the buff include the space of GPD header and CCCI header and data buffer
		********************************************************************/
    	/* --------------- 
    	 * |             |
         * |CCCI header  |
         * |-------------|
         * |data buffer  |
         * ---------------
         */

		/* check the mis-use */
		if(!valid_channel(rx_queue, channel))
		{
			#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
				sprintf(debug_info, "<wrong usage in ccci_write> owner=%d in RQ0", ccci_ctrl_pool[channel].owner);
				CCCI_TRACE(debug_info);
			#endif
			ASSERT(0);
		}
		
		ccci_buff = (CCCI_BUFF_T * ) (buff);

		/* check the resource available or not */
		available = sdio_query_queue_space(get_ngio_handle(), select_queue, SDIO_RX);
		if(available == 0)
		{
			RestoreIRQMask(mask);
			return CCCI_NO_PHY_CHANNEL;
		}
    }	
    else if(rx_queue == 1)
    {
		/********************************************************************
		 *the buff include the space of GPD header and CCCI header and data buffer
		 ********************************************************************/
    	/* --------------- 
    	 * |             |
         * |CCCI header  |
         * |-------------|
         * |data buffer  |
         * ---------------
         */

		/* check the mis-use */
		if(!valid_channel(rx_queue, channel))
		{
			#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
				sprintf(debug_info, "<wrong usage in ccci_write> owner=%d in RQ1", ccci_ctrl_pool[channel].owner);
				CCCI_TRACE(debug_info);
			#endif
			ASSERT(0);
		}
		
		ccci_buff = (CCCI_BUFF_T * ) (buff);

		/* check the resource available or not */
		available = sdio_query_queue_space(get_ngio_handle(), select_queue, SDIO_RX);
		if(available == 0)
		{
			RestoreIRQMask(mask);
			return CCCI_NO_PHY_CHANNEL;
		}
    }
    #if ( !defined(__L1_STANDALONE__) && !defined(__MAUI_BASIC__) )
    else if(rx_queue == 2)
    {
        /* the memory from GIO is non-contious, CCCI should use GPD lib */
		/* get the ccci header from gpd node */
		/* using gpd_lib_umts_peekHeader API to look up the CCCI header information*/
		
		ccci_buff = (CCCI_BUFF_T * )gpd_lib_umts_peekHeader( (gpd_node*)buff );

		#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
			sprintf(debug_info, "in RX2, data[0]= %d, data[1]= %d, channel= %d, reserved= %d .. \r\n", ccci_buff->data[0], ccci_buff->data[1], ccci_buff->channel, ccci_buff->reserved);
			CCCI_TRACE(debug_info);
		#endif
		if(!valid_channel(rx_queue, channel))
		{
			#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
				sprintf(debug_info, "<wrong usage in ccci_write> owner=%d in RQ2 .. \r\n", ccci_ctrl_pool[channel].owner);
				CCCI_TRACE(debug_info);
			#endif
			ASSERT(0);
		}
		/* check the resource available or not */
		available = sdio_query_queue_space(get_gio_handle(), select_queue, SDIO_RX);
		if(available == 0)
		{
			RestoreIRQMask(mask);
			return CCCI_NO_PHY_CHANNEL;	
		}
    }
    #endif
    else
    {
        #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
			sprintf(debug_info, "the rx_queue is not 0, 1, 2, please check the transmitted rx_queue");
			CCCI_TRACE(debug_info);
		#endif
		ASSERT(0);
    }

    /* check state */
    ret = CCCI_SUCCESS;
    
    if (ccci_ctrl_pool[channel].state != CCCI_IDLE) 
    {
        ret = CCCI_IN_USE;
    } 
    else 
    {
	/* set ACTIVE_WRITE */
        ccci_ctrl_pool[channel].state = CCCI_ACTIVE_WRITE;		
    }

    if (ret != CCCI_SUCCESS)
	{
		RestoreIRQMask(mask);
        return ret;
	}

    if(rx_queue == 0 || rx_queue == 1)
    {
		/* set logical channel number in CCCI case*/
		/* must not modify the info of GIO case requested by Stan Chen*/
		ccci_buff->channel = channel;
    }
    /* do transaction log */	
    ccci_trans_log_pool[channel][ccci_trans_log_index[channel]].tick = kal_get_systicks();
	
    if (!CCCI_IS_MAILBOX(ccci_buff)) 
    {
		SDIO_BUFFER_SET_LENGTH(bd, ccci_buff->data[1]);//including CCCI header size
    }
    else
    {
    	/* include the GPD header */
		SDIO_BUFFER_SET_LENGTH(bd, sizeof(CCCI_BUFF_T));  	
    }
	
    /* fill in the transferred data */
    SDIO_BUFFER_SET_PRIORITY(bd, select_queue);
    status = (SDIO_STATUS)KAL_SUCCESS;	
    /* copy the buff (in network case, only send stream to AP confirmed with Stan Chen) into global gMB[RX_num][queue_count] */
    if(CCCI_IS_MAILBOX(ccci_buff))
    {
		kal_mem_cpy(&(gMB[rx_queue][MB_rx_writeindx[rx_queue]]), buff, sizeof(CCCI_BUFF_T));
		SDIO_BUFFER_SET_ADDRESS(bd, (kal_uint32) &(gMB[rx_queue][MB_rx_writeindx[rx_queue]]));
		MB_rx_writeindx[rx_queue] = (MB_rx_writeindx[rx_queue]+1)%RX_queue_count;
		/*the SDIO driver should avoid using thread_protect when the I-bit is disable, otherwise there have an assert*/
		status = sdio_rx(get_ngio_handle(), (void*) &bd);
		#ifdef __CCCI_DEBUG_INFO__
			ccci_debug_count0++;
		#endif
    }
    else
    {
		SDIO_BUFFER_SET_ADDRESS(bd, (kal_uint32) buff);
		if(rx_queue == 0 || rx_queue == 1)
		{
			status = sdio_rx(get_ngio_handle(), (void*) &bd);
			#ifdef __CCCI_DEBUG_INFO__
				ccci_debug_count1++;
			#endif
		}
		else if (rx_queue == 2)
		{
			status = sdio_rx(get_gio_handle(), (void*) &bd);
			#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
				sprintf(debug_info, "in ccci_write_internal in RX2 case .. \r\n");
				CCCI_TRACE(debug_info);
				sprintf(debug_info, "leave ccci_write_internal in RX2 case, status = %d .. \r\n", status);
				CCCI_TRACE(debug_info);
			#endif
			#ifdef __CCCI_DEBUG_INFO__
				ccci_debug_count2++;
			#endif
		}
    }
    if(status != (SDIO_STATUS)SDIO_SUCCESS)
    {
		#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
			sprintf(debug_info, "<wrong sdio status in ccci_write> status=%d,please consult with SDIO driver owner",status);
			CCCI_TRACE(debug_info);
		#endif
		EXT_ASSERT(0,status,0,0);
    }
	
    /* finish transaction and set IDLE */
    ccci_ctrl_pool[channel].state = CCCI_IDLE;
	RestoreIRQMask(mask);

    /* recording transaction log */
    kal_mem_cpy(&(ccci_ctrl_pool[channel].buff), ccci_buff, sizeof(CCCI_BUFF_T));
    kal_mem_cpy(&(ccci_trans_log_pool[channel][ccci_trans_log_index[channel]].ct), &ccci_ctrl_pool[channel], sizeof(CCCI_CTRL_T));
    ccci_trans_log_index[channel]++;
    ccci_trans_log_index[channel]%=(DebugEntryNo);
	

	if(ccci_buff->channel == 0 && (KAL_FALSE == kal_query_systemInit() && INT_QueryExceptionStatus() == KAL_FALSE))	
	{
		sprintf(channel_info, "in RX = %d, data[0]= %d, data[1]= %d, channel= %d, reserved= %d .. \r\n", select_queue, ccci_buff->data[0], ccci_buff->data[1], ccci_buff->channel, ccci_buff->reserved);
		tst_sys_trace(channel_info);
		ASSERT(0);
	}
    return status;
}

/*************************************************************************
* FUNCTION
*  kal_bool ccci_chk_recentry_in_queue
*
* DESCRIPTION
*  This function use to as a query funtion when exception happen
*
* PARAMETERS
*  query_log    -    the response logical channel from AP side
*  *   
* RETURNS
*  TRUE/FALSE
*
*************************************************************************/
kal_bool ccci_chk_recentry_in_queue(kal_uint32 query_log)
{
    CCCI_BUFF_T *ccci_return_buff;
    kal_uint32 index;

    /* initialize the queue ptr and BD info*/
    kal_uint32 queue_ptr[TX_num+RX_num];
    SDIO_QUERY_INFO_ENTRY TX[TX_num][TX_queue_count];
    SDIO_QUERY_INFO_ENTRY RX[RX_num][RX_queue_count];

    /********************************************************************
     * query the TX data from SDIO, SDIO will return the data point in different queue
     ********************************************************************/
    /* shared memory mode users */
    queue_ptr[0] = (kal_uint32) &TX[0][0]; //TX RT mailbox queue
    queue_ptr[1] = (kal_uint32) &TX[1][0]; //TX mailbox queue
    /* user control mode users */
    queue_ptr[2] = (kal_uint32) &TX[2][0]; //TX network data
    queue_ptr[3] = (kal_uint32) &TX[3][0]; //TX network data
    queue_ptr[4] = (kal_uint32) &TX[4][0]; //TX newwork data
    /* shared memory mode users */
    queue_ptr[5] = (kal_uint32) &RX[0][0]; //RX RT mailbox/normal/stream data queue
    queue_ptr[6] = (kal_uint32) &RX[1][0]; //RX MDLogger queue
    /* user control mode users */
    queue_ptr[7] = (kal_uint32) &RX[2][0]; //RX network data

    /* query mode */
    sdio_query_txqueue_data_available(get_ngio_handle());
		
    /* CCCI should query the SDIO queues when HISR is triggered by SDIO LISR */ 	  
    sdio_query_information(&queue_ptr[0], &queue_ptr[TX_num]);
	
    /* sync with AP CCCI owner that the CCCI driver will use the TX0 to transfer data */
    for(index = 1; index < TX[0][0].flags; index++)
    {
		ccci_return_buff = (CCCI_BUFF_T *)(TX[0][index].buffer_addr);
		if (ccci_return_buff->channel== query_log)
		{
				return KAL_TRUE;
		}
    }
    return KAL_FALSE;
}

/*************************************************************************
* FUNCTION
*  ccci_init_handshake_phase1 
*
* DESCRIPTION
*  notify AP that MD need the run time data for information check.
*
* PARAMETERS
*  N/A
*
* RETURNS
*  N/A
*
*************************************************************************/
#if defined(__ARM11_MMU__)
extern kal_int32 mmu_set_page_config(kal_uint32 vaddr, kal_uint32 paddr, kal_uint32 len, MMU_PAGE_CONFIG_PTR pagc);
#endif //- __ARM11_MMU__
void ccci_init_handshake_phase1(void) 
{
    CCCI_BUFF_T ccci_buff, *ccci_return_buff;
    kal_int32 i=0;
    kal_uint32 index,md_ready_to_go;
    #if defined(__ARM11_MMU__)
		MMU_PAGE_CONFIG_T pagc;
	#endif //- __ARM11_MMU__

	ccci_hw_init ();
		
    /* initialize the queue ptr and BD info*/
    kal_uint32 queue_ptr[TX_num+RX_num];
    SDIO_QUERY_INFO_ENTRY TX[TX_num][TX_queue_count];
    SDIO_QUERY_INFO_ENTRY RX[RX_num][RX_queue_count];

    #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		kal_char debug_info[100];
    #endif
    /********************************************************************
     * query the TX data from SDIO, SDIO will return the data point in different queue
     ********************************************************************/
    /* shared memory mode users */
    queue_ptr[0] = (kal_uint32) &TX[0][0]; //TX RT mailbox queue
    queue_ptr[1] = (kal_uint32) &TX[1][0]; //TX mailbox queue
    /* user control mode users */
    queue_ptr[2] = (kal_uint32) &TX[2][0]; //TX network data
    queue_ptr[3] = (kal_uint32) &TX[3][0]; //TX network data
    queue_ptr[4] = (kal_uint32) &TX[4][0]; //TX newwork data
    /* shared memory mode users */
    queue_ptr[5] = (kal_uint32) &RX[0][0]; //RX RT mailbox/normal/stream data queue
    queue_ptr[6] = (kal_uint32) &RX[1][0]; //RX MDLogger queue
    /* user control mode users */
    queue_ptr[7] = (kal_uint32) &RX[2][0]; //RX network data

    /* since the AP is not ready, we bypass the related code flow in UT stage*/

	#ifndef __UT_CCCI_ON_SDIO__
    ccci_init(CCCI_CONTROL_CHANNEL,ccci_boot_ack);
    ccci_init(CCCI_CONTROL_CHANNEL_ACK,ccci_boot_ack);
    CCCI_INIT_MAILBOX(&ccci_buff, CCMSG_ID_START_BOOT);
    ccci_buff.reserved = BOOT_CHECK_ID;
    //ret = ccci_write(CCCI_CONTROL_CHANNEL, &ccci_buff);
    ccci_write(CCCI_CONTROL_CHANNEL, &ccci_buff);

    while (1)
    {
        md_ready_to_go = 0;

	/* query mode */
	sdio_query_txqueue_data_available(get_ngio_handle());
		
	/* CCCI should query the SDIO queues when HISR is triggered by SDIO LISR */		  
	sdio_query_information(&queue_ptr[0], &queue_ptr[TX_num]);

	/* sync with AP CCCI owner that the CCCI driver will use the TX0 to transfer data */
	for(index = 0; index < TX[0][0].flags; index++)
	{
  	    ccci_return_buff = (CCCI_BUFF_T *)(TX[0][index+1].buffer_addr);
	    if (ccci_return_buff->reserved == BOOT_CHECK_ID)
            {
		kal_uint32 element;
            	md_ready_to_go = 1;
	    
		#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
			sprintf(debug_info, "RQ 0 MB = (%x, %x, %x, %x) .. \r\n", ccci_return_buff->data[0], ccci_return_buff->data[1], ccci_return_buff->channel, ccci_return_buff->reserved);
			CCCI_TRACE(debug_info);
		#endif
		sdio_tx_writeindx[0]++;
		for (element=0 ; element< 4; element++)
		{
	    	    *(((volatile unsigned long *)&(ccci_ctrl_pool[CCCI_CONTROL_CHANNEL_ACK].buff)) + element )= *((volatile unsigned long *)ccci_return_buff +element);
		}
		ccci_trans_log_pool[CCCI_CONTROL_CHANNEL_ACK][ccci_trans_log_index[CCCI_CONTROL_CHANNEL_ACK]].tick = kal_get_systicks();
   		kal_mem_cpy(&(ccci_trans_log_pool[CCCI_CONTROL_CHANNEL_ACK][ccci_trans_log_index[CCCI_CONTROL_CHANNEL_ACK]].ct), &ccci_ctrl_pool[CCCI_CONTROL_CHANNEL_ACK], sizeof(CCCI_CTRL_T));
		ccci_trans_log_index[CCCI_CONTROL_CHANNEL_ACK]++;
   		ccci_trans_log_index[CCCI_CONTROL_CHANNEL_ACK]%=(DebugEntryNo);	
		sdio_recycle_single_buffer(get_ngio_handle(), (kal_uint32) ccci_return_buff);
		sdio_tx_readindx[0]++;
                break;
            }
        }
       	if (1 == md_ready_to_go) 
	    break;
    }
	#endif //- __UT_CCCI_ON_SDIO__
	
    /* copy the run-time data to MD global structure to initialized shared memory info.*/
    for (i=0; i < (sizeof(MODEM_RUNTIME_DATA)+3) >> 2; i++)
    {
		/* attach the shared memory info. */
		*(((volatile unsigned long *)&(ap_md_share_data)) + i) = *((volatile unsigned long *)ccci_return_buff+CCCI_HAL_OVERHEAD_WORD+i);
    }

    /* transparent with previous CCCI driver design*/
    ap_md_share_data.UartPortNum = UART_MAX_PORT_NUM;
    for (index = 0; index < ap_md_share_data.UartPortNum; index++) 
    {
		/* assigned the MD shared memory info to ap_md_shared_data for backward compatible */
		ap_md_share_data.UartShareMemBase[index] = (kal_uint32) &MDUartShareMemBase[index];
		ap_md_share_data.UartShareMemSize[index] = mUartShareMemSize;
		(ccci_uartp_buff[index]).tx  = (CCCI_UARTB_T *)((ap_md_share_data.UartShareMemBase[index]));
		*((volatile kal_uint32*) ap_md_share_data.UartShareMemBase[index]+2) = 8192;//initialize length
		(ccci_uartp_buff[index]).rx  = (CCCI_UARTB_T *)(((ap_md_share_data.UartShareMemBase[index])) +sizeof(CCCI_UARTB_T)) ;  
		*((volatile kal_uint32*) ap_md_share_data.UartShareMemBase[index]+5) = 8192;//131584;//initialize length
		(ccci_uartp_buff[index]).tx_buff = (((kal_uint8 *)((ap_md_share_data.UartShareMemBase[index]))) + 2*sizeof(CCCI_UARTB_T));
		(ccci_uartp_buff[index]).rx_buff = ((((kal_uint8 *)((ap_md_share_data.UartShareMemBase[index]))) + 2*sizeof(CCCI_UARTB_T)) \
			+ ( (( ap_md_share_data.UartShareMemSize[index] - 2*sizeof(CCCI_UARTB_T)) /2 ) ));	
    }

    //MDlog (TST==>user will use the memory directly)
    ap_md_share_data.MdlogShareMemBase = (kal_uint32) &MDMdlogShareMemBase;
    ap_md_share_data.MdlogShareMemSize = mMdlogShareMemSize;
    //PCM (audio==>user will use the memory directly)
    ap_md_share_data.PcmShareMemBase = (kal_uint32) &MDPcmShareMemBase;
    ap_md_share_data.PcmShareMemSize = mPcmShareMemSize;
    //RPC
    ap_md_share_data.RpcShareMemBase = (kal_uint32) &MDRpcShareMemBase;
    ap_md_share_data.RpcShareMemSize = mRpcShareMemSize;
    //PMIC(user will use the memory directly)
    ap_md_share_data.PmicShareMemBase = (kal_uint32) &MDPmicShareMemBase;
    ap_md_share_data.PmicShareMemSize = mPmicShareMemSize;
    //Modem exception memory
    ap_md_share_data.ExceShareMemBase = (kal_uint32) &MDExceShareMemBase;
    ap_md_share_data.ExceShareMemSize = mExceShareMemSize;
    //System memory
    ap_md_share_data.SysShareMemBase = (kal_uint32) &MDSysShareMemBase;
    ap_md_share_data.SysShareMemSize = mSysShareMemSize;
    //IPC
    ap_md_share_data.IPCShareMemBase = (kal_uint32) &MDIPCShareMemBase;
    ap_md_share_data.IPCShareMemSize = mIPCShareMemSize; 
    //FS
    ap_md_share_data.FileShareMemBase = (kal_uint32) &MDFileShareMemBase;
    ap_md_share_data.FileShareMemSize = mFileShareMemSize;

    ipcsvc_share_rx_g = (Ipcsvc_Share_ST *) ap_md_share_data.IPCShareMemBase;
    ipcsvc_share_rx_g->size = (ap_md_share_data.IPCShareMemSize/2)-sizeof(Ipcsvc_Share_ST);
    ipcsvc_share_tx_g = (Ipcsvc_Share_ST *) (ap_md_share_data.IPCShareMemBase + (ap_md_share_data.IPCShareMemSize/2));
    ipcsvc_share_tx_g->size = (ap_md_share_data.IPCShareMemSize/2)-sizeof(Ipcsvc_Share_ST);
		
	#if defined(__ARM11_MMU__)
    /* in ccci on sdio the memory attribute could be non-cacheable, bufferable memory  */
    ccci_CalculateShareMem(&share_start, &share_end , &share_size);
    DEFAULT_RW_NCNB((MMU_PAGE_CONFIG_PTR)&pagc);
    mmu_set_page_config(share_start, share_start, share_size, &pagc);
    #endif //- __ARM11_MMU__

    /* don't forget to apply the early modem exception log captured */
    #if defined(__MULTI_BOOT__)
		if ( META_BOOT_ID == (ap_md_share_data.BootingStartID  & 0x000000FF) )
		{
			 /*setting the meta mode */
			(*(volatile kal_uint16 *)BOOT_CONFIG_ADDR) |= 0x0001;
		}
    #endif /*  #ifdef __MULTI_BOOT__ */
	
    ccci_deinit(CCCI_CONTROL_CHANNEL);
    ccci_deinit(CCCI_CONTROL_CHANNEL_ACK);
}

/*************************************************************************
* FUNCTION
*  void ccci_init_handshake_phase2
*
* DESCRIPTION
*  This function .
*
* PARAMETERS
*  boot mode    	-  	unused
*  *   
* RETURNS
*  N/A
*
*************************************************************************/
void ccci_init_handshake_phase2(kal_uint16 _boot_mode) 
{

    CCCI_BUFF_T ccci_buff;
	   
    ccci_init(ap_md_share_data.BootChannel,ccci_boot_ack);
    ccci_init(ap_md_share_data.BootChannel+1,ccci_boot_ack);
    
    if (ap_md_share_data.DriverVersion == CCCI_CURRENT_VERSION)
    {
        CCCI_INIT_MAILBOX(&ccci_buff, ap_md_share_data.BootReadyID);
    }
    else
    {
        CCCI_INIT_MAILBOX(&ccci_buff, CCMSG_ID_DRV_VERSION_ERR);
    }
    
    ccci_write(ap_md_share_data.BootChannel, &ccci_buff);

    ccci_deinit(ap_md_share_data.BootChannel);
    ccci_deinit(ap_md_share_data.BootChannel+1);

    if (ap_md_share_data.DriverVersion != CCCI_CURRENT_VERSION)
    {
		while(1);
    }


	#if defined(IC_MODULE_TEST)
    ccci_init(CCCI_CONTROL_CHANNEL, ccci_LB_m2d_cb);
    ccci_init(CCCI_CONTROL_CHANNEL_ACK, ccci_LB_d2m_cb);
	#endif /* IC_MODULE_TEST */


    /* For run-time information exchange with AP side */
    ccci_init(CCCI_SYSTEM_CHANNEL_ACK, ccci_system_channel_runtime_callback);
}

/*************************************************************************
* FUNCTION
*  void ccci_exception_handshake
*
* DESCRIPTION
*  This function .
*
* PARAMETERS
*  N/A
*  *   
* RETURNS
*  N/A
*
*************************************************************************/
void ccci_exception_handshake(void) 
{
    kal_uint32 read, write;
    CCCI_BUFF_T buff;
    #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		kal_char debug_info[100];
    #endif

    #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
        sprintf(debug_info, " ccci_exception_handshake = %d ...  \n\r", CheckIRQLock());
		CCCI_TRACE(debug_info);
    #endif
    // ensure in the exception state
    if(INT_QueryExceptionStatus() == KAL_FALSE) return;

    //recycle all buffer in TX Queue
    read = sdio_tx_readindx[0];
    write = sdio_tx_writeindx[0];

    #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		sprintf(debug_info, " R = %d, W = %d ...  \n\r", read, write);
		CCCI_TRACE(debug_info);
    #endif
    while( write != read)
    {
        if(write < read)
	    write += TX_queue_count;

	#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		sprintf(debug_info, " before recycle...  \n\r");
		CCCI_TRACE(debug_info);
	#endif
	sdio_recycle_multiple_buffer(get_ngio_handle(), (kal_uint32*) &gTX[0][(read++)%TX_queue_count], 1);

	#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		sprintf(debug_info, " after recycle...  \n\r");
		CCCI_TRACE(debug_info);
		sprintf(debug_info, " R = %d, W = %d ...  \n\r", read, write);
		CCCI_TRACE(debug_info);
	#endif
    }
    #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		sprintf(debug_info, " init ccci control channel...  \n\r");
		CCCI_TRACE(debug_info);
    #endif
    ccci_init(CCCI_CONTROL_CHANNEL, ccci_except_ack);
    ccci_init(CCCI_CONTROL_CHANNEL_ACK, ccci_except_ack);
    ccci_ctrl_pool[CCCI_CONTROL_CHANNEL].state = CCCI_IDLE;

    CCCI_INIT_MAILBOX(&buff, CCMSG_ID_EXCEPTION_CHECK);
    buff.reserved =  EXCEPTION_CHECK_ID;
    ccci_exception_check_write_result = ccci_write_internal_sdio(CCCI_CONTROL_CHANNEL, &buff, 0, 0); 
    #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		sprintf(debug_info, " write_result = %d ...  \n\r", ccci_exception_check_write_result);
		CCCI_TRACE(debug_info);
    #endif
    ust_busy_wait(CCCI_WAIT_MAX_TIME);
    if (KAL_TRUE != ccci_chk_recentry_in_queue(CCCI_CONTROL_CHANNEL_ACK))
    {
        ccci_exception_handshake_done = KAL_FALSE;
    }
    else
    {
   	ccci_exception_handshake_done = KAL_TRUE;
    }
   	
    #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		sprintf(debug_info, " done = %d ...  \n\r", ccci_exception_handshake_done);
		CCCI_TRACE(debug_info);
    #endif
}

/*************************************************************************
* FUNCTION
*  void ccci_exception_info_passed
*
* DESCRIPTION
*  This function .
*
* PARAMETERS
* N/A
*  *   
* RETURNS
* N/A
*
*************************************************************************/
extern EX_LOG_T *ex_log_ptr;
void ccci_exception_info_passed(void) 
{
    CCCI_BUFF_T *buff;
    #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		kal_char debug_info[100];
    #endif

    #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		sprintf(debug_info, " CCCI_exception_info_passed...\n\r");
		CCCI_TRACE(debug_info);
    #endif

	#if defined (__SDIO_DEVICE_CONNECTIVITY__)
		kal_mem_set((void*)ap_md_share_data.ExceShareMemBase, 0, sizeof(EX_LOG_T)+CCCI_HAL_OVERHEAD);
		kal_mem_cpy((void*)(ap_md_share_data.ExceShareMemBase+CCCI_HAL_OVERHEAD), ex_log_ptr, sizeof(EX_LOG_T));
	#else
		kal_mem_set((void*)ap_md_share_data.ExceShareMemBase, 0, sizeof(EX_LOG_T));
		kal_mem_cpy((void*)(ap_md_share_data.ExceShareMemBase), ex_log_ptr, sizeof(EX_LOG_T));
	#endif
    // ensure in the exception state
    if(INT_QueryExceptionStatus() == KAL_FALSE) return;

    ccci_init(CCCI_CONTROL_CHANNEL, ccci_except_ack);
    ccci_init(CCCI_CONTROL_CHANNEL_ACK, ccci_except_ack);
    ccci_ctrl_pool[CCCI_CONTROL_CHANNEL].state = CCCI_IDLE;

    buff = (CCCI_BUFF_T*) ap_md_share_data.ExceShareMemBase;
    buff->data[0] = ap_md_share_data.ExceShareMemBase;
    buff->data[1] = ap_md_share_data.ExceShareMemSize;
    buff->channel = CCCI_CONTROL_CHANNEL;
    buff->reserved =  CCMSG_ID_EXCEPTION_REC_OK;
    /*send exception to RQ 0 in exception shared memory*/
    ccci_exception_info_write_result = ccci_write_internal_sdio(CCCI_CONTROL_CHANNEL, (CCCI_BUFF_T*) ap_md_share_data.ExceShareMemBase, 0, 0);

    #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		sprintf(debug_info, " write_result = %d ...  \n\r", ccci_exception_info_write_result);
		CCCI_TRACE(debug_info);
    #endif
}

/*************************************************************************
* FUNCTION
*  ccci_read_and_wait
*
* DESCRIPTION
*  This function reads data through either mailbox channel or stream
*  channel. ONLY USED WHEN NO INTERRUPT
*
* PARAMETERS
*  channel    -    logical channel
*  buff       -    pointer to channel buffer
*
* RETURNS
*  MDIF error code.
*
*************************************************************************/
kal_uint32 ccci_read_and_wait(CCCI_CHANNEL_T channel, CCCI_BUFF_T *buff, kal_uint32 ticks)
{
    return 0;
}

/*************************************************************************
* FUNCTION
*  ccci_CalculateShareMem
*
* DESCRIPTION
*  This function .
*
* PARAMETERS
*  channel    -    logical channel
*  *   
* RETURNS
*  The address of the share memory of the input logical channel
*
*************************************************************************/
void ccci_CalculateShareMem(kal_uint32 *start_addr, kal_uint32 *end_addr , kal_uint32 *size)
{
	return;
}

/*******************************************************************************
 * Common part
 *******************************************************************************/
/*************************************************************************
* FUNCTION
*  ccci_is_channel_need_check_owner
*
* DESCRIPTION
*  This function will return if the owner need to check
*
* PARAMETERS
*  the selected logic channel
*
* RETURNS
*  status(TRUE/FALSE)
*
*************************************************************************/
kal_bool ccci_is_channel_need_check_owner(CCCI_CHANNEL_T channel)
{
    if(INT_QueryExceptionStatus() == KAL_TRUE  || kal_query_systemInit() == KAL_TRUE)
    {
		return KAL_FALSE;
    }
    else if (CCCI_TST_CHANNEL <= channel && CCCI_PMIC_ACK_CHANNEL >= channel)
    {
		return KAL_FALSE;
    }
    else if (CCCI_IPC_RPC_CHANNEL <= channel &&  CCCI_MSGSVC_RCV_ACK_CHANNEL >= channel)
    {
		return KAL_FALSE;
    }
    else
    {
		return KAL_TRUE;
    }
}

/*************************************************************************
* FUNCTION
*  ccci_owner_init
*
* DESCRIPTION
*  This function initializes the logical channel for the specified task.
*
* PARAMETERS
*  channel   -    logical channel
*  task      -    owner task
*  funp      -    ISR callback function
*
* RETURNS
*  CCCI error code.
*
*************************************************************************/
kal_int32 ccci_owner_init(CCCI_CHANNEL_T channel, kal_taskid task, CCCI_CALLBACK funp)
{
    kal_uint32 owner, mask;
    kal_int32 ret;

    /* error checking */
    if (channel >= CCCI_MAX_CHANNEL)
        return CCCI_INVALID_PARAM;
    if (funp == NULL)
        return CCCI_INVALID_PARAM;
    if (kal_if_lisr())
        return CCCI_IN_LISR;

    ret = CCCI_SUCCESS;

    owner = (kal_uint32)task;

    /* check if the channel is free */
    mask = SaveAndSetIRQMask();
    if (ccci_ctrl_pool[channel].owner != 0) 
    {
        ret = CCCI_IN_USE;
    } 
    else 
    {
        ccci_ctrl_pool[channel].owner = owner;
    }
	
    RestoreIRQMask(mask);
	
    if (ret != CCCI_SUCCESS)
        return ret;

    /* initialize the control block */
    ccci_ctrl_pool[channel].state = CCCI_IDLE;
    kal_mem_set(&(ccci_ctrl_pool[channel].buff), 0, sizeof(CCCI_BUFF_T));
    ccci_ctrl_pool[channel].funp = funp;

    return ret;
}

/*************************************************************************
* FUNCTION
*  ccci_init
*
* DESCRIPTION
*  This function initializes the logical channel.
*
* PARAMETERS
*  channel    -    logical channel
*  funp       -    ISR callback function
*
* RETURNS
*  CCCI error code.
*
*************************************************************************/
kal_int32 ccci_init(CCCI_CHANNEL_T channel, CCCI_CALLBACK funp)
{
    kal_taskid task;

    /* get the current task */
    task = kal_get_current_thread_ID();

    return ccci_owner_init(channel, task, funp);
}

/*************************************************************************
* FUNCTION
*  ccci_deinit
*
* DESCRIPTION
*  This function de-initializes the logical channel.
*
* PARAMETERS
*  channel    -    logical channel
*
* RETURNS
*  CCCI error code.
*
*************************************************************************/
kal_int32 ccci_deinit(CCCI_CHANNEL_T channel)
{
    kal_uint32 owner, mask;
    kal_int32 ret;

    /* error checking */
    if (channel >= CCCI_MAX_CHANNEL)
        return CCCI_INVALID_PARAM;
    if (kal_if_lisr())
        return CCCI_IN_LISR;

    /* get the current task */
    owner = (kal_uint32)kal_get_current_thread_ID();

    /* check owner */
    if (ccci_ctrl_pool[channel].owner != owner) 
    {
        return CCCI_NOT_OWNER;
    }

    ret = CCCI_SUCCESS;

    /* check state */
    mask = SaveAndSetIRQMask();
    if (ccci_ctrl_pool[channel].state != CCCI_IDLE) 
    {
        ret = CCCI_IN_USE;
    } 
    else 
    {
        /* free the channel */
        ccci_ctrl_pool[channel].owner = 0;
    }
    RestoreIRQMask(mask);

    return ret;
}


/*************************************************************************
* FUNCTION
*  ccci_mailbox_write
*
* DESCRIPTION
*  This function writes data through a mailbox channel.
*
* PARAMETERS
*  channel    -    logical channel
*  id         -    mailbox id
*
* RETURNS
*  CCCI error code.
*
*************************************************************************/
kal_int32 ccci_mailbox_write(CCCI_CHANNEL_T channel, kal_uint32 id)
{
    CCCI_BUFF_T buff;


    /* initialize a CCCI channel buffer */
    kal_mem_set(&buff, 0, sizeof(CCCI_BUFF_T));
    CCCI_INIT_MAILBOX(&buff, id);

    /* write */
    return ccci_write(channel, &buff);
}

/*************************************************************************
* FUNCTION
*  ccci_mailbox_write_with_reserved
*
* DESCRIPTION
*  This function writes data through a mailbox channel.
*
* PARAMETERS
*  channel    -    logical channel
*  id         -    mailbox id
*  reserved   -    additional info depended on scenario
*
* RETURNS
*  CCCI error code.
*
*************************************************************************/
kal_int32 ccci_mailbox_write_with_reserved(CCCI_CHANNEL_T channel, kal_uint32 id, kal_uint32 reserved)
{
    CCCI_BUFF_T buff;

    /* initialize a CCCI channel buffer */
    kal_mem_set(&buff, 0, sizeof(CCCI_BUFF_T));
    CCCI_INIT_MAILBOX(&buff, id);
    
    buff.reserved = reserved;
    /* write */
    return ccci_write(channel, &buff);
}

/*************************************************************************
* FUNCTION
*  ccci_read
*
* DESCRIPTION
*  This function reads data through either mailbox channel or stream
*  channel.
*
* PARAMETERS
*  channel    -    logical channel
*  buff       -    pointer to channel buffer
*
* RETURNS
*  CCCI error code.
*
*************************************************************************/
kal_int32 ccci_read(CCCI_CHANNEL_T channel, CCCI_BUFF_T *buff)
{
    kal_uint32 owner, mask, ret, event;
    kal_char event_name[20];

    /* check if a LISR is running */
    if (kal_if_lisr())
        return CCCI_IN_LISR;

    /* check parameters */
    if (channel >= CCCI_MAX_CHANNEL)
        return CCCI_INVALID_PARAM;
    if (buff == NULL)
        return CCCI_INVALID_PARAM;

    /* get the current task */
    owner = (kal_uint32)kal_get_current_thread_ID();

    /* check owner */
    if (ccci_ctrl_pool[channel].owner != owner && ccci_is_channel_need_check_owner(channel)) 
    {
        return CCCI_NOT_OWNER;
    }

    /* create an event for the first use */ 
    if (ccci_ctrl_pool[channel].event == NULL) 
    {
        sprintf(event_name, "CCCI%d event", channel);
        ccci_ctrl_pool[channel].event = kal_create_event_group(event_name);
        if (ccci_ctrl_pool[channel].event == NULL)
            ASSERT(0);
    }

    /* check state */
    ret = CCCI_SUCCESS;
    mask = SaveAndSetIRQMask();
    if (ccci_ctrl_pool[channel].state != CCCI_IDLE) 
    {
        ret = CCCI_IN_USE;
    } 
    else 
    {
        /* set ACTIVE_WRITE */
        ccci_ctrl_pool[channel].state = CCCI_ACTIVE_READ;
    }
    RestoreIRQMask(mask);
    if (ret != CCCI_SUCCESS)
        return ret;

    /* wait for the event */
    kal_retrieve_eg_events(ccci_ctrl_pool[channel].event, 1, KAL_OR_CONSUME, &event, KAL_SUSPEND);
    if (event != 1) 
    {
        ASSERT(0);
    }

    /* read channel buffer */
    memcpy(buff, &(ccci_ctrl_pool[channel].buff), sizeof(CCCI_BUFF_T));

    /* set ACTIVE_IDLE */
    ccci_ctrl_pool[channel].state = CCCI_IDLE;

    return CCCI_SUCCESS;
}



/*************************************************************************
* FUNCTION
*  ccci_mailbox_read
*
* DESCRIPTION
*  This function reads data through a mailbox channel.
*
* PARAMETERS
*  channel    -    logical channel
*
* RETURNS
*  A mailbox id or error code.
*
*************************************************************************/
kal_int32 ccci_mailbox_read(CCCI_CHANNEL_T channel)
{
    CCCI_BUFF_T buff;
    kal_uint32 ret;

    /* read */
    ret = ccci_read(channel, &buff);

    if (ret == CCCI_SUCCESS) 
    {
        /* return mailbox id for success read */
        return CCCI_MAILBOX_ID(&buff);
    } 
    else 
    {
        /* return error code for fail read */
        return ret;
    }
}

/*************************************************************************
* FUNCTION
*  ccci_mailbox_read_with_reserved
*
* DESCRIPTION
*  This function reads data through a mailbox channel.
*
* PARAMETERS
*  channel    -    logical channel
*
* RETURNS
*  A mailbox id or error code.
*
*************************************************************************/
kal_int32 ccci_mailbox_read_with_reserved(CCCI_CHANNEL_T channel,kal_uint32 *reserved)
{
    CCCI_BUFF_T buff;
    kal_uint32 ret;


    /* read */
    ret = ccci_read(channel, &buff);
    *reserved = buff.reserved;
    
    if (ret == CCCI_SUCCESS) 
    {
        /* return mailbox id for success read */
        return CCCI_MAILBOX_ID(&buff);
    } 
    else 
    {
        /* return error code for fail read */
        return ret;
    }
}

/*************************************************************************
* FUNCTION
*  ccci_stream_write
*
* DESCRIPTION
*  This function writes data through a stream channel.
*
* PARAMETERS
*  channel    -    logical channel
*  addr       -    start address of the user buffer
*  len        -    lenght of the user buffer 
*
* RETURNS
*  CCCI error code.
*
*************************************************************************/
kal_int32 ccci_stream_write(CCCI_CHANNEL_T channel, kal_uint32 addr, kal_uint32 len)
{
    CCCI_BUFF_T buff;

    /* initialize a CCCI channel buffer */
    kal_mem_set(&buff, 0, sizeof(CCCI_BUFF_T));
    CCCI_INIT_STREAM(&buff, addr, len);

    /* write */
    return ccci_write(channel, &buff);
}

/*************************************************************************
* FUNCTION
*  ccci_stream_write_with_reserved
*
* DESCRIPTION
*  This function writes data through a stream channel.
*
* PARAMETERS
*  channel    -    logical channel
*  addr       -    start address of the user buffer
*  len        -    lenght of the user buffer 
*  reserved   -    an additional parameter
*
* RETURNS
*  CCCI error code.
*
*************************************************************************/
kal_int32 ccci_stream_write_with_reserved(CCCI_CHANNEL_T channel, kal_uint32 addr, kal_uint32 len,kal_uint32 reserved)
{
	#if defined (__SDIO_DEVICE_CONNECTIVITY__)
	{
		//PC - add
		//differet implementation due to a defect of the RVCT 3.1 compiler.
		//PC - end
		CCCI_BUFF_T *buff;
	

		buff = (CCCI_BUFF_T *)(addr);
		buff->data[0] = addr+16;
        buff->data[1] = len;  
        buff->channel = CCCI_MAX_CHANNEL;	
	  buff->reserved = reserved;
		if(channel == CCCI_MD_LOG_RX)
			return ccci_write_internal_sdio(channel,buff,1,2);
		else
			return ccci_write(channel, buff);
	}
	#else //CCIF
	{
		CCCI_BUFF_T buff;
	  /* initialize a CCCI channel buffer */
	  kal_mem_set(&buff, 0, sizeof(CCCI_BUFF_T));
	  CCCI_INIT_STREAM(&buff, addr, len);
		buff.reserved = reserved; 
		return ccci_write(channel, &buff);
	}
	#endif
}

/*************************************************************************
* FUNCTION
*  ccci_stream_read
*
* DESCRIPTION
*  This function reads data through a stream channel.
*
* PARAMETERS
*  channel    -    logical channel
*  addr       -    pointer to the start address of the buffer to read
*  len        -    pointer to the length of the buffer to read
*
* RETURNS
*  A mailbox id or error code.
*
*************************************************************************/
kal_int32 ccci_stream_read(CCCI_CHANNEL_T channel, kal_uint32 *addr, kal_uint32 *len)
{
    CCCI_BUFF_T buff;
    kal_uint32 ret;


    /* read */
    ret = ccci_read(channel, &buff);

    if (ret == CCCI_SUCCESS) 
    {
        /* get the start address and length of the buffer */
        *addr = CCCI_STREAM_ADDR(&buff);
        *len = CCCI_STREAM_LEN(&buff);
    }

    return ret;
}

/*************************************************************************
* FUNCTION
*  ccci_stream_read_with_reserved
*
* DESCRIPTION
*  This function reads data through a stream channel.
*
* PARAMETERS
*  channel    -    logical channel
*  addr       -    pointer to the start address of the buffer to read
*  len        -    pointer to the length of the buffer to read
*
* RETURNS
*  A mailbox id or error code.
*
*************************************************************************/
kal_int32 ccci_stream_read_with_reserved(CCCI_CHANNEL_T channel, kal_uint32 *addr, kal_uint32 *len, kal_uint32 *reserved)
{
    CCCI_BUFF_T buff;
    kal_uint32 ret;


    /* read */
    ret = ccci_read(channel, &buff);

    if (ret == CCCI_SUCCESS) 
    {
        /* get the start address and length of the buffer */
        *addr = CCCI_STREAM_ADDR(&buff);
        *len = CCCI_STREAM_LEN(&buff);
	 	*reserved = buff.reserved; 
    }

    return ret;
}

/*************************************************************************
* FUNCTION
*  void ccci_change_owner_only
*
* DESCRIPTION
*  This function let L4C change owner to CMUX.
*
* PARAMETERS
*  channel    -    			logical channel
*  *   
* RETURNS
*  The address of the share memory of the input logical channel
*
*************************************************************************/
void ccci_change_owner_only(CCCI_CHANNEL_T channel,module_type owner)
{
    ccci_ctrl_pool[channel].owner = (kal_uint32)(kal_get_task_by_moduleID(owner));
}

/*************************************************************************
* FUNCTION
*  void ccci_boot_ack
*
* DESCRIPTION
*  This function .
*
* PARAMETERS
*  channel    -    	logical channel
*  *   
* RETURNS
*  The address of the share memory of the input logical channel
*
*************************************************************************/
void ccci_boot_ack(CCCI_BUFF_T *bufp)
{
	#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
        	kal_char debug_info[100];
                sprintf(debug_info, "The initial channel %d and value %d\n",bufp->channel,bufp->data[1]);
                CCCI_TRACE(debug_info);
    	#endif
    return;
}

/*************************************************************************
* FUNCTION
*  void ccci_system_channel_runtime_callback
*
* DESCRIPTION
*  This function use to handle control channel messages from AP side
*  major information : MDSC insert or remove message and change EINT poliaty
*
* PARAMETERS
*  bufp    -    			control buffer info.
*     
* RETURNS
*  NA
*
*************************************************************************/
void ccci_system_channel_runtime_callback(CCCI_BUFF_T *bufp)
{

    if(INT_QueryExceptionStatus() == KAL_TRUE) 
	  return;
    switch(CCCI_MAILBOX_ID(bufp))
    {
    	case  CCMSG_ID_MD_L4_MOD:
    	{
    	    msg_send4 (MOD_CCCI_HISR, MOD_L4C, 0, MSG_ID_L4C_END_PS_DATA_SENSSION_REQ);        	
    	}
		break;
		case CCMSG_ID_MD_L4_MAX_TX_PWR_RED_REQ:
			{
				CCCI_COMMON_ILM_2B *local_para;
					
			    local_para = (CCCI_COMMON_ILM_2B *) construct_local_para (sizeof(CCCI_COMMON_ILM_2B), TD_RESET);
	    		local_para->HW0 = bufp->reserved & 0xFFFF;
	    		
				msg_send5 (MOD_CCCI_HISR, MOD_L4C, 0, MSG_ID_L4C_MAX_TX_PWR_RED_REQ, (local_para_struct*)local_para); 				
			}
		break;
    	default:
    	break;    	
    }//end switch
}
/*************************************************************************
* FUNCTION
*  void ccci_except_ack
*
* DESCRIPTION
*  This function use to as a ack funtion when exception happen
*
* PARAMETERS
*  bufp    -    ccci control buffer
*  *   
* RETURNS
*  NA
*
*************************************************************************/
PRIVATE void ccci_except_ack(CCCI_BUFF_T *bufp)
{
    return;
}

/*************************************************************************
* FUNCTION
*  ccci_queryBootAttributes
*
* DESCRIPTION
*  This function .
*
* PARAMETERS
*  mask    -   The mask to query attributes 
*
* RETURNS
*  The address of the share memory of the input logical channel
*
*************************************************************************/
kal_bool ccci_queryBootAttributes(kal_uint32 mask)
{
    if ((ap_md_share_data.BootAttributes & mask) != 0x0)
    {
    	return KAL_TRUE;
    }
    	return KAL_FALSE;
}

/*************************************************************************
* FUNCTION
*  void ccci_dummy_ack
*
* DESCRIPTION
*  This function use to as a ack funtion which does nothing
*
* PARAMETERS
*  bufp    -    			pointer to the buffer on this channel
* 
* RETURNS
*  NA
*
*************************************************************************/
PRIVATE void ccci_dummy_ack(CCCI_BUFF_T *bufp)
{
    return;
}

/*************************************************************************
 *FUNCTION
 *	ccci_service_init
 *
 *DESCRIPTION
 *	This function is to initialize ccci services
 *
 *PARAMETERS
 *	none
 *
 *RETURNS
 *	none
 *
*************************************************************************/
PRIVATE void ccci_service_init(void)
{
    ipc_msgsvc_init();
    ipc_rpc_init();
    FS_CCCI_Init();
}

/*************************************************************************
 *		the wrap function of CCCI driver
 *************************************************************************/

/*************************************************************************
* FUNCTION
*  void ccci_hw_init
*
* DESCRIPTION
*  This function use to initialize HW medium
*
* PARAMETERS
*  N/A
* 
* RETURNS
*  NA
*
*************************************************************************/
void ccci_hw_init(void)
{
    #if defined (__SDIO_DEVICE_CONNECTIVITY__)
		sdio_ccci_init();
    #else//CCIF
		//don't need to initial ccif hw medium
    #endif
}

/*************************************************************************
* FUNCTION
*  void ccci_hal_init
*
* DESCRIPTION
*  This function use to register ccci hisr and determine other factors
*
* PARAMETERS
*  arb - SW/HW arbitration for CCIF
*  md_offset - the AP/MD view of EMI mapping
* 
* RETURNS
*  NA
*
*************************************************************************/
void ccci_hal_init(void)
{
	DCL_HANDLE uart_handle;

	#if defined (__SDIO_DEVICE_CONNECTIVITY__)
		sdio_start_interrupt(DRV_CCIF_HISR_ID, ccci_hisr);
		ccci_service_init();
		ccci_init(CCCI_FS_CHANNEL, FS_CCCI_TX_Callback);
		ccci_init(CCCI_FS_ACK_CHANNEL, FS_CCCI_Callback);
	#else
		ccif_init(1);
		ccci_service_init();
		ccci_init(CCCI_FS_CHANNEL, FS_CCCI_Callback);
		ccci_init(CCCI_FS_ACK_CHANNEL, FS_CCCI_Callback);
	#endif
	
	uart_handle =  DclSerialPort_Open(uart_port_tst_ccci, 0);
	DclSerialPort_RegisterCallback(uart_handle, &CCCI_Uart_Drv_Handler);
	
	uart_handle =  DclSerialPort_Open(uart_port_at_ccci, 0);
	DclSerialPort_RegisterCallback(uart_handle, &CCCI_Uart_Drv_Handler);
	
	
	#if defined(__UPS_SUPPORT__)
	
	uart_handle =  DclSerialPort_Open(uart_port_ccmni1_ccci, 0);
	DclSerialPort_RegisterCallback(uart_handle, &CCCI_Uart_Drv_Handler);
	
	uart_handle =  DclSerialPort_Open(uart_port_ccmni2_ccci, 0);
	DclSerialPort_RegisterCallback(uart_handle, &CCCI_Uart_Drv_Handler);
	
	uart_handle =  DclSerialPort_Open(uart_port_ccmni3_ccci, 0);
	DclSerialPort_RegisterCallback(uart_handle, &CCCI_Uart_Drv_Handler);
	
	#endif /* __UPS_SUPPORT__ */
	
	uart_handle =  DclSerialPort_Open(uart_port_gps_ccci, 0);
	DclSerialPort_RegisterCallback(uart_handle, &CCCI_Uart_Drv_Handler);	
}
#endif  /* __SMART_PHONE_MODEM__ */
#endif  /* __MODEM_CCCI_EXIST__ */

