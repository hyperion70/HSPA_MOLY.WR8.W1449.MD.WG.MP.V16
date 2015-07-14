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
 *   ccci_uart_drv_sdio.c
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
#include "kal_public_api.h"
#include "kal_public_defs.h"
#include "reg_base.h"
#include "ccci.h"
#include "intrCtrl.h"
#include "drv_comm.h"
#include "drv_hisr.h"
#include "uart_sw.h"
#include "dcl.h"
#include "ccci_uart_drv.h"
#include "kal_public_defs.h" //MSBB change #include "stack_common.h"
#include "stack_types.h"
#include "task_config.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "drv_msgid.h"


#if defined(__MODEM_CCCI_EXIST__)
#if defined(__SMART_PHONE_MODEM__)

#include "kal_trace.h"
#include "tst_trace.h"
extern void tst_sys_trace(kal_char *);
extern MODEM_RUNTIME_DATA ap_md_share_data;
extern void UART_DriverInit(UART_PORT port,kal_uint32 flag);
/*******************************************************************************
 * Define import global variables.
 *******************************************************************************/
#ifdef __MTK_TARGET__
extern kal_uint8 INT_Exception_Enter ;
#endif

#include "sdio_fw_api_public.h"
#include "us_timer.h"
#if ( !defined(__L1_STANDALONE__) && !defined(__MAUI_BASIC__) )
	#include "gpd_lib.h"
#endif
/********************************************************************************
 * Define global variables.
 ********************************************************************************/
kal_uint8 data_for_putuartbyte;

#if defined (__SDIO_DEVICE_CONNECTIVITY__)
//	kal_uint32 RR_notify=0;
//	kal_uint32 RR_notify_base=2;
	kal_uint32 enqueue=0, dequeue=0;
	kal_uint32 UPS_enqueue = 0, UPS_dequeue = 0;

	//avoid race condition in ccci_uart_gio_tx_recycle_gpd 
	extern PUBLIC kal_uint32 gio_recycle_readindx;
	extern PUBLIC kal_uint32 gio_recycle_writeindx;
	extern PUBLIC SDIO_QUERY_INFO_ENTRY gGIO_RECYCLE[RECYCLE_queue_count];

	//avoid race condition in ccci_uart_gio_rx_recv_data
	extern PUBLIC kal_uint32 gio_receive_readindx[RX_num];
	extern PUBLIC kal_uint32 gio_receive_writeindx[RX_num];
	extern PUBLIC SDIO_QUERY_INFO_ENTRY gGIO_RECEIVE[RX_num][TX_queue_count];
#endif


PRIVATE CCCI_UARTP_T ccci_uart_port[MAX_CCCI_UART_PORT] =
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

PRIVATE DCL_STATUS     CCCI_UART_Handler(DCL_DEV dev,DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);
PUBLIC Seriport_HANDLER_T    CCCI_Uart_Drv_Handler = {DCL_UART_CCCI_TYPE, CCCI_UART_Handler};


/*************************************************************************
* FUNCTION
*  ccci_gio_dummy_callback
*
* DESCRIPTION
*  This function is to avoid mis-used case.
*
* PARAMETERS
*  buff - ccci header
*
* RETURNS
*  N/A
*
*************************************************************************/
static void ccci_gio_dummy_callback(CCCI_BUFF_T *buff)
{
	ASSERT(0);
}


/*************************************************************************
* FUNCTION
*  ccci_uart_behave_nonblock
*
* DESCRIPTION
*  This function to check which port is non-blocking behavior.
*
* PARAMETERS
*  port -- input port
*
* RETURNS
*  True/False
*
*************************************************************************/
PRIVATE kal_bool ccci_uart_behave_nonblock(DCL_DEV port)
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
*  This function implements the CCCI callback function.
*
* PARAMETERS
*  buff - ccci header
*
* RETURNS
*  none
*
*************************************************************************/
PRIVATE void ccci_uart_tx_callback(CCCI_BUFF_T *buff)
{
	#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		kal_char debug_info[100];
	#endif
	#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		sprintf(debug_info, " in ccci_uart_Tx_callback ... \n\r");
		CCCI_TRACE(debug_info);
	#endif
	#if defined (__SDIO_DEVICE_CONNECTIVITY__)
	{
		kal_uint32 port = 0;
		kal_uint32 tx;

		if(buff->channel >= CCCI_TST_CHANNEL && buff->channel <= CCCI_TR_ACK_CHANNEL)
			port = 0;			
		else if(buff->channel >= CCCI_AT_CHANNEL_TX && buff->channel <= CCCI_AT_ACK_CHANNEL_RX)
			port = 1;
		else if(buff->channel >= CCCI_CCMNI1_RX && buff->channel <= CCCI_CCMNI1_TX_ACK)
			port = 2;
		else if(buff->channel >= CCCI_CCMNI2_RX && buff->channel <= CCCI_CCMNI2_TX_ACK)
			port = 3;
		else if(buff->channel >= CCCI_CCMNI3_RX && buff->channel <= CCCI_CCMNI3_TX_ACK)
			port = 4;
		else if(buff->channel >= CCCI_GPS_CHANNEL_TX && buff->channel <= CCCI_GPS_ACK_CHANNEL_RX)
			port = 5;
		else
			EXT_ASSERT(0, buff->channel, 0, 0);//invalid port
		
		//update RX index in shared memory mode or send ilm to user to re-send data again in user control mode
		if(!ccci_uart_port[port].gio_mode)
		{
			dequeue++;
			
			//update the padding size in read index
			tx = (buff->data[1]);
			if(tx <= ((ccci_uartp_buff[port]).tx->len - (ccci_uartp_buff[port]).tx->read ))
				(ccci_uartp_buff[port]).tx->read = (((ccci_uartp_buff[port]).tx->read + tx + 3) >> 2 ) << 2 ;
			else
				(ccci_uartp_buff[port]).tx->read = ((tx+3) >> 2 ) << 2;
			
			if(	(ccci_uartp_buff[port]).tx->read > (ccci_uartp_buff[port]).tx->len)
				ASSERT(0);//invalid length

			//wrap read to 0 when read = len
			(ccci_uartp_buff[port]).tx->read %= (ccci_uartp_buff[port]).tx->len;
			

			if ( KAL_FALSE == ccci_uart_behave_nonblock(port))
			{
				/* set an event */
				kal_set_eg_events(ccci_uart_port[port].event, 1, KAL_OR);
			}
			else
			{
				if (ccci_uart_port[port].write_flag == 1) 
				{
					uart_ready_to_write_ind_struct * local_para = (uart_ready_to_write_ind_struct *) 
					construct_local_para (sizeof(uart_ready_to_write_ind_struct), TD_RESET);
					local_para->port = FIRST_CCCI_UART_PORT + port;
					
					ccci_uart_port[port].write_flag = 0;
					msg_send5 (MOD_CCCI_HISR, ccci_uart_port[port].tx_owner, 0, MSG_ID_UART_READY_TO_WRITE_IND, (local_para_struct*)local_para);	  
				}
			}
		}
		else
		{	
        if (ccci_uart_port[port].write_flag == 1)
        {       
					//uart_ready_to_write_ind_struct * local_para = (uart_ready_to_write_ind_struct *) 
					//construct_local_para (sizeof(uart_ready_to_write_ind_struct), TD_RESET);
			
					//add in 2012_03_08 request by Stan Chen to round robin notify UPS 
					//no matter there have data or not, CCCI service will notify UPS to recycle data sequentiallly
    			//RR_notify = (RR_notify%RX_num) + RR_notify_base;
    			//local_para->port = FIRST_CCCI_UART_PORT + port;
                   			             
    			//msg_send5 (MOD_CCCI_HISR, ccci_uart_port[port].tx_owner, 0, MSG_ID_UART_READY_TO_WRITE_IND, (local_para_struct*)local_para);
    			switch(port)
    			{
    				case 2:
    					msg_send4 (MOD_CCCI_HISR, ccci_uart_port[port].tx_owner, 0, MSG_ID_UPS1_READY_TO_WRITE_IND);
    					break;
    				case 3:
    					msg_send4 (MOD_CCCI_HISR, ccci_uart_port[port].tx_owner, 0, MSG_ID_UPS2_READY_TO_WRITE_IND);
    					break;
    				case 4:
    					msg_send4 (MOD_CCCI_HISR, ccci_uart_port[port].tx_owner, 0, MSG_ID_UPS3_READY_TO_WRITE_IND);
    					break;
    				default:
    					ASSERT(0);
    			}
        }
		}
	}
	#else //for CCIF
		ASSERT(0);
	#endif
}


/*************************************************************************
* FUNCTION
*  ccci_uart_tx_ack_callback
*
* DESCRIPTION
*  This function implements the CCCI callback function. (should not be used in SDIO )
*  
* PARAMETERS
*  buff - ccci header
*
* RETURNS
*  none
*
*************************************************************************/
PRIVATE void ccci_uart_tx_ack_callback(CCCI_BUFF_T *buff)
{
	kal_uint32 port;

	/* get port number stored in the CCCI buffer */
	port = CCCI_MAILBOX_ID(buff);

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
			uart_ready_to_write_ind_struct * local_para = (uart_ready_to_write_ind_struct *) 
			construct_local_para (sizeof(uart_ready_to_write_ind_struct), TD_RESET);
			local_para->port = FIRST_CCCI_UART_PORT + port;
			
			ccci_uart_port[port].write_flag = 0;
		  msg_send5 (MOD_CCCI_HISR, ccci_uart_port[port].tx_owner, 0, MSG_ID_UART_READY_TO_WRITE_IND, (local_para_struct*)local_para);	  
		}
	}  
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
PRIVATE void ccci_uart_rx_callback(CCCI_BUFF_T *buff)
{
	  kal_uint32 port;
	
		/* get port number from logical channel */
	  for (port = 0; port < MAX_CCCI_UART_PORT; port++) 
		{
	    if (ccci_uart_port[port].rx_channel == buff->channel) 
			{
	      	break;
	    }
	  }
   	if (port >= MAX_CCCI_UART_PORT) 
		{
       	EXT_ASSERT(0, port, buff->channel, 0);
   	}

	//1. the gio users don't need to use the shared memory concept
	//2. others, update the uart buffer when it is non-gio mode	
	#if defined (__SDIO_DEVICE_CONNECTIVITY__)
		if (!ccci_uart_port[port].gio_mode)
		{
			kal_uint32 temp_len = buff->data[1]-CCCI_HAL_OVERHEAD;
			kal_uint32 left;

			CCCI_UARTB_GETROOMLEFT(((ccci_uartp_buff[port]).rx), left);

			if(left >= temp_len)
				CCCI_UARTB_PUSH_MULTI(((ccci_uartp_buff[port]).rx), (ccci_uartp_buff[port]).rx_buff , (kal_uint8*)buff+CCCI_HAL_OVERHEAD, temp_len);
			else
				ASSERT(0);//the size need to be tuned
				
			//release memory to SDIO driver
			sdio_recycle_single_buffer(get_ngio_handle(), (kal_uint32)buff);
 
     #endif
	 		//if the rx_owner try to receive more data than buffer size that the callback will tell user try to get data again
    		if (ccci_uart_port[port].flag == 1) 
			{
				uart_ready_to_read_ind_struct* local_para = (uart_ready_to_read_ind_struct *) 
				construct_local_para (sizeof(uart_ready_to_read_ind_struct), TD_RESET);
				local_para->port = FIRST_CCCI_UART_PORT + port;

				//clear the flag, the flag will be raised again if the available buffer size still cannot match the user requirement
		      ccci_uart_port[port].flag = 0;
    		  msg_send5 (MOD_CCCI_HISR, ccci_uart_port[port].rx_owner, 0, MSG_ID_UART_READY_TO_READ_IND, (local_para_struct*)local_para);
    		}
	#if defined (__SDIO_DEVICE_CONNECTIVITY__)
		}
		else
		{
    		if (ccci_uart_port[port].flag == 1)
			{      
				//ccci will notify the GIO user to receive data
				//uart_ready_to_read_ind_struct* local_para = (uart_ready_to_read_ind_struct *) 
				//construct_local_para (sizeof(uart_ready_to_read_ind_struct), TD_RESET);
				//local_para->port = FIRST_CCCI_UART_PORT + port;
	
	
				//clear the flag, the flag will be raised again if the available buffer size still cannot match the user requirement
				ccci_uart_port[port].flag = 0;
				//msg_send5 (MOD_CCCI_HISR, ccci_uart_port[port].rx_owner, 0, MSG_ID_UART_READY_TO_READ_IND, (local_para_struct*)local_para);
				switch(port)
  			{
  				case 2:
  					msg_send4 (MOD_CCCI_HISR, ccci_uart_port[port].tx_owner, 0, MSG_ID_UPS1_READY_TO_READ_IND);
  					break;
  				case 3:
  					msg_send4 (MOD_CCCI_HISR, ccci_uart_port[port].tx_owner, 0, MSG_ID_UPS2_READY_TO_READ_IND);
  					break;
  				case 4:
  					msg_send4 (MOD_CCCI_HISR, ccci_uart_port[port].tx_owner, 0, MSG_ID_UPS3_READY_TO_READ_IND);
  					break;
  				default:
  					ASSERT(0);
  			}
				
			}
		}
	#endif
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
PRIVATE void ccci_uart_rx_ack_callback(CCCI_BUFF_T *buff)
{
    /* This should not be called by MD side */
    ASSERT(0);
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
PUBLIC kal_bool ccci_uart_open(DCL_DEV port, module_type owner)
{
    kal_uint32 ret;


    if (port >= (FIRST_CCCI_UART_PORT + MAX_CCCI_UART_PORT)) 
	{
        	return KAL_FALSE;
    }
    port -= FIRST_CCCI_UART_PORT;


	#if defined (__SDIO_DEVICE_CONNECTIVITY__)
    	/* initialize CCCI channels for TX */
    	ret = ccci_owner_init(ccci_uart_port[port].tx_channel, kal_get_task_by_moduleID(owner), ccci_uart_tx_callback);
	#else //for CCIF
		ret = ccci_owner_init(ccci_uart_port[port].tx_channel, kal_get_task_by_moduleID(owner), ccci_uart_tx_callback);
	#endif

    if (ret != CCCI_SUCCESS) 
	{
       	return KAL_FALSE;
    }


	#if defined (__SDIO_DEVICE_CONNECTIVITY__)
    	ret = ccci_owner_init(ccci_uart_port[port].tx_ack_channel, kal_get_task_by_moduleID(owner), ccci_gio_dummy_callback);
	#else //for CCIF
		ret = ccci_owner_init(ccci_uart_port[port].tx_ack_channel, kal_get_task_by_moduleID(owner), ccci_uart_tx_ack_callback);
	#endif

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
	#if defined (__SDIO_DEVICE_CONNECTIVITY__)
    	ret = ccci_owner_init(ccci_uart_port[port].rx_channel, kal_get_task_by_moduleID(owner), ccci_uart_rx_callback);
	#else //for CCIF
		ret = ccci_owner_init(ccci_uart_port[port].rx_channel, kal_get_task_by_moduleID(owner), ccci_uart_rx_callback);
	#endif

    if (ret != CCCI_SUCCESS) 
	{
        return KAL_FALSE;
    }

	#if defined (__SDIO_DEVICE_CONNECTIVITY__)
    	ret = ccci_owner_init(ccci_uart_port[port].rx_ack_channel, kal_get_task_by_moduleID(owner), ccci_gio_dummy_callback);
	#else //for CCIF
		ret = ccci_owner_init(ccci_uart_port[port].rx_ack_channel, kal_get_task_by_moduleID(owner), ccci_uart_rx_ack_callback);	
	#endif

    if (ret != CCCI_SUCCESS) 
	{
        return KAL_FALSE;
    }

   	/* save RX owner */
    ccci_uart_port[port].rx_owner = owner;

	CCCI_UARTB_INIT(((ccci_uartp_buff[port]).tx),(ccci_uartp_buff[port].rx_buff-ccci_uartp_buff[port].tx_buff));
    CCCI_UARTB_INIT(((ccci_uartp_buff[port]).rx), (ccci_uartp_buff[port].rx_buff-ccci_uartp_buff[port].tx_buff));

    /* initialize the nofify flag */
    ccci_uart_port[port].flag = 1;

    /* create an event */
    if (ccci_uart_port[port].event == NULL) 
	{
        ccci_uart_port[port].event = kal_create_event_group("CCCIUART");
    }
    
	/* Default is Non-GIO mode*/
	ccci_uart_port[port].gio_mode = 0;
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
PRIVATE void ccci_uart_close(DCL_DEV port, module_type owner)
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
    ccci_uart_port[port].write_flag = 0;
    ccci_uart_port[port].tx_owner = MOD_NIL;
    ccci_uart_port[port].rx_owner = MOD_NIL;
    ccci_uart_port[port].gio_mode = 0;
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
*  Length     -   buffer length (not incluiding the ccci overhead)
*  status     -   no use
*  ownerid    -   no use
*
* RETURNS
*  Number of bytes actually gotten
*
*************************************************************************/
PRIVATE kal_uint16 ccci_uart_getbytes(DCL_DEV port, kal_uint8 *Buffaddr, kal_uint16 Length, kal_uint8 *status, module_type ownerid)
{
    kal_uint32 avail, cnt, mask;

    

    if (port >= (FIRST_CCCI_UART_PORT + MAX_CCCI_UART_PORT)) 
    {
        return KAL_FALSE;
    }
    port -= FIRST_CCCI_UART_PORT;

	//filter the GIO usage
    if(ccci_uart_port[port].gio_mode)
	ASSERT(0);

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
    if (avail != 0) 
    {
    	//mask = SaveAndSetIRQMask();
        
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
		//RestoreIRQMask(mask);
    } 
    else 
    {
        cnt = 0;
    }

	#if defined (__SDIO_DEVICE_CONNECTIVITY__)
		;//do nothing, MD don't need to notify AP
	#else
		if (cnt != 0) {
	        /* ack */
	        CCCI_INIT_MAILBOX(&buff, port);
	        do {
	            ret = ccci_write(ccci_uart_port[port].rx_ack_channel, &buff);
	            if (ret == CCCI_NO_PHY_CHANNEL) {
	                continue;
	            } if (ret == CCCI_SUCCESS) {
	                break;
	            } else {
	                EXT_ASSERT(0, ret, 0, 0);
	            }
	        } while (1);
	    }
	#endif

    return cnt;
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
*  Legnth     -   buffer length (incluiding the ccci overhead, in CCIF is 0, in SDIO is 16 bytes)
*  ownerid    -   no use
*
* RETURNS
*  Number of bytes actually put
*
*************************************************************************/
PRIVATE kal_uint16 ccci_uart_putbytes(DCL_DEV port, kal_uint8 *Buffaddr, kal_uint16 Length, module_type ownerid)
{
    //user should reserve CCCI header in the Length parameter
    kal_uint32 left, flag, cnt, event, ret,mask, update_overhead=1, remain = 0;
	
	#if defined (__SDIO_DEVICE_CONNECTIVITY__)
		CCCI_BUFF_T* ccci_buffer = NULL;	
		CCCI_UARTB_T *tx = NULL;
	#else//CCIF
		CCCI_BUFF_T buff;  
	#endif

	//calculate the responding port number
    if (port >= (FIRST_CCCI_UART_PORT + MAX_CCCI_UART_PORT)) 
    {
        return KAL_FALSE;
    }
    port -= FIRST_CCCI_UART_PORT;

	//filter the GIO usage
    if(ccci_uart_port[port].gio_mode)
		ASSERT(0);

    if (ccci_uart_port[port].tx_owner != ownerid) 
    {
        EXT_ASSERT(0, port + FIRST_CCCI_UART_PORT, ownerid, ccci_uart_port[port].tx_owner);
    }

	//miss used case, return 0 since CCCI doesn't transfer any data size in the API
    if (Length == 0) 
    {
        return 0;
    }

    //consume the set event from non-block user in ccci_uart_tx_ack_callback()
    kal_retrieve_eg_events(ccci_uart_port[port].event, 1, KAL_OR_CONSUME, &event, KAL_NO_SUSPEND);

	//record the request size from user
    cnt = Length;

    do 
    {
        /* get available space in the Ring buffer */
        
        mask = SaveAndSetIRQMask();
        
        CCCI_UARTB_GETROOMLEFT_NEW(((ccci_uartp_buff[port]).tx), left, flag);
		
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
		//don't need to calculate ccci overhead when ccci doesn't send any message in last time
		if(update_overhead == 1)
			cnt += CCCI_HAL_OVERHEAD;
		#endif 
		
        if ( (left < cnt) && ccci_uart_behave_nonblock(port) ) 
        {
            /* cannot fit the required size; set the nofify flag */

            /*
		         *	 NoteXXX: It is not necessary to use a mutex to protect flag access.
		         *    This is because the flag is always be set in the task level
		         *    and always be cleared in the HISR level.
		         */

            ccci_uart_port[port].write_flag = 1;
        }
		
        RestoreIRQMask(mask);

        if (left > cnt) 
        {
            /* copy data from the user buffer to the Ring buffer */
			
   	    	#if defined (__SDIO_DEVICE_CONNECTIVITY__)			
			    tx = (ccci_uartp_buff[port]).tx;
				ccci_buffer = (CCCI_BUFF_T*)((kal_uint32)ccci_uartp_buff[port].tx_buff + tx->write);

			    ccci_buffer->data[0] = (kal_uint32)ccci_uartp_buff[port].tx_buff + tx->write + CCCI_HAL_OVERHEAD;
			    ccci_buffer->data[1] = cnt; //including CCCI header
			    ccci_buffer->channel = CCCI_MAX_CHANNEL; //need to initialize
			    ccci_buffer->reserved = 0;
				
				//use memcpy to copy data length excluding CCCI header since ccci_buffer already record CCCI header info
				cnt -= CCCI_HAL_OVERHEAD;

				//the remaining size cnt will be 0 in the MACRO judgement
			    CCCI_UARTB_PUSH_MULTI_NEW(((ccci_uartp_buff[port]).tx), (ccci_uartp_buff[port]).tx_buff , (kal_uint8 *)(Buffaddr), cnt, flag, remain);
				
				//force 4-bytes alignment
				(ccci_uartp_buff[port]).tx->write = ((((ccci_uartp_buff[port]).tx->write + 3) >>2) << 2);
				if( (ccci_uartp_buff[port]).tx->write > (ccci_uartp_buff[port]).tx->len )
					ASSERT(0);
				(ccci_uartp_buff[port]).tx->write %= (ccci_uartp_buff[port]).tx->len;
				enqueue++;//for debug

				//need to re-add ccci header overhead again in next round
				update_overhead = 1;

	    	#else //for CCIF
			    CCCI_UARTB_PUSH_MULTI(((ccci_uartp_buff[port]).tx), (ccci_uartp_buff[port]).tx_buff, Buffaddr,cnt);
					
		        /* write data through CCCI */
		        CCCI_INIT_STREAM(&buff, (kal_uint32)((ccci_uartp_buff[port]).tx_buff), (ccci_uartp_buff[port].rx_buff-ccci_uartp_buff[port].tx_buff));

		    #endif
			
			
        	do {
				#if defined (__SDIO_DEVICE_CONNECTIVITY__)
					ret = ccci_write(ccci_uart_port[port].tx_channel, ccci_buffer);
				#else //for CCIF
		            ret = ccci_write(ccci_uart_port[port].tx_channel, &buff);
				#endif
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
					//invalid status
					EXT_ASSERT(0, ret, 0, 0);
	            }
        	} while (1);
        } 
        else 
        {
	        /* copy data from the user buffer to the TST buffer */
	        #if defined (__SDIO_DEVICE_CONNECTIVITY__)
			    if(left >= CCCI_HAL_OVERHEAD + 4)
			    {
					tx = (ccci_uartp_buff[port]).tx;

					#if 1 // avoid unalignment case when R > W and request size is bigger than R-W-1==> round down firstly ex: 7 -> 4
						if(left & 0xF)
							left = (left>>2)<<2;
						else
							;
					#endif 
				    ccci_buffer = (CCCI_BUFF_T*)((kal_uint32)ccci_uartp_buff[port].tx_buff + tx->write);
					
					ccci_buffer->data[0] = (kal_uint32)ccci_uartp_buff[port].tx_buff + tx->write + CCCI_HAL_OVERHEAD;
					ccci_buffer->data[1] = left;
					ccci_buffer->channel = CCCI_MAX_CHANNEL;
					ccci_buffer->reserved = 0;

					//count the remaining request size
					cnt -= left;
					//use memcpy to copy data length excluding CCCI header since ccci_buffer already record CCCI header info
					left -= CCCI_HAL_OVERHEAD;
					
		            CCCI_UARTB_PUSH_MULTI_NEW(((ccci_uartp_buff[port]).tx), (ccci_uartp_buff[port]).tx_buff, (kal_uint8 *)(Buffaddr), left, flag, remain);	

					//need to re-add ccci header overhead again in next round
					update_overhead = 1;
	    		}
			    else
			    {
			    	if((ccci_uartp_buff[port]).tx->write >= (ccci_uartp_buff[port]).tx->read)
			    	{	
						(ccci_uartp_buff[port]).tx->write += (ccci_uartp_buff[port]).tx->len - (ccci_uartp_buff[port]).tx->write;
						(ccci_uartp_buff[port]).tx->write %= (ccci_uartp_buff[port]).tx->len;

						//the W must be equal to L
						if((ccci_uartp_buff[port]).tx->write != 0)
							ASSERT(0);
			    	}
					else
						;//do nothing
					
					//bypass call ccci write API
					ccci_buffer = NULL;
					//don't need to re-add ccci header overhead again in next round
					update_overhead = 0;
			    }
				enqueue++;//for debug
			
		    #else //for CCIF
	            cnt -= left;
	            CCCI_UARTB_PUSH_MULTI(((ccci_uartp_buff[port]).tx), (ccci_uartp_buff[port]).tx_buff, Buffaddr,left);
	           
	            /* write data through CCCI */

	            CCCI_INIT_STREAM(&buff, (kal_uint32)((ccci_uartp_buff[port]).tx_buff), CCCI_TX_BUFF_LEN);
		    #endif
            do {
				#if defined (__SDIO_DEVICE_CONNECTIVITY__)
					if(ccci_buffer != NULL)
					{
						ret = ccci_write(ccci_uart_port[port].tx_channel, ccci_buffer);
					}
					else
					{
						ret = CCCI_SUCCESS;
					}
				#else //for CCIF
	            	ret = ccci_write(ccci_uart_port[port].tx_channel, &buff);
				#endif
				
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
            } while (1);

            /* Yusu owner would like to receive msg when free space is available instead of handing by driver */
            if (KAL_FALSE == ccci_uart_behave_nonblock(port))
            {
				#if defined(__SDIO_DEVICE_CONNECTIVITY__)
				if(ccci_buffer == NULL)
					;//ust_busy_wait(CCCI_WAIT_MAX_TIME); //retry again we need to tune the time stamp
				else
				#endif
                /* wait for an event */
                kal_retrieve_eg_events(ccci_uart_port[port].event, 1, KAL_OR_CONSUME, &event, KAL_SUSPEND);
            }
            else
            {
            	//record the transferred size in Length = (request size - remaining size)
                Length -= cnt;
                break;
            }
        }

    } while (cnt > 0);
	//return the already transferred message length
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
PRIVATE kal_uint16 ccci_uart_putisrbytes(DCL_DEV port, kal_uint8 *Buffaddr, kal_uint16 Length, module_type ownerid)
{
    kal_uint32 left, flag, cnt, ret, remain=0;
    CCCI_BUFF_T *ccci_buffer=NULL;
    #if defined (__SDIO_DEVICE_CONNECTIVITY__)
	    CCCI_UARTB_T *tx=NULL;
    #endif

    

    if (port >= (FIRST_CCCI_UART_PORT + MAX_CCCI_UART_PORT)) 
    {
        return KAL_FALSE;
    }
    port -= FIRST_CCCI_UART_PORT;

	//filter the GIO usage
    if(ccci_uart_port[port].gio_mode)
		ASSERT(0);

    if (ccci_uart_port[port].tx_owner != ownerid) 
    {
        EXT_ASSERT(0, port + FIRST_CCCI_UART_PORT, ownerid, ccci_uart_port[port].tx_owner);
    }

    if (Buffaddr == NULL) 
    {
        EXT_ASSERT(0, 0, 0, 0);
    }

    CCCI_UARTB_GETROOMLEFT_NEW(((ccci_uartp_buff[port]).tx), left, flag);
	

    /* copy data from the user buffer to the TST buffer */
    cnt = Length;
    #if defined (__SDIO_DEVICE_CONNECTIVITY__)
    	cnt += CCCI_HAL_OVERHEAD;
    #endif

    if (cnt > left) 
    {
        EXT_ASSERT(0, Length, left, 0);
    }
	
    #if defined (__SDIO_DEVICE_CONNECTIVITY__)
	    tx = (ccci_uartp_buff[port]).tx;
		ccci_buffer = (CCCI_BUFF_T*)((kal_uint32)ccci_uartp_buff[port].tx_buff + tx->write);
		
	    ccci_buffer->data[0] = (kal_uint32)ccci_uartp_buff[port].tx_buff + tx->write + CCCI_HAL_OVERHEAD;
	    ccci_buffer->data[1] = cnt;
	    ccci_buffer->channel = CCCI_MAX_CHANNEL;
	    ccci_buffer->reserved = 0;
		cnt -= CCCI_HAL_OVERHEAD;
	    CCCI_UARTB_PUSH_MULTI_NEW(((ccci_uartp_buff[port]).tx), (ccci_uartp_buff[port]).tx_buff, Buffaddr,cnt, flag, remain);
		//force 4-bytes alignment
		(ccci_uartp_buff[port]).tx->write = ((((ccci_uartp_buff[port]).tx->write + 3) >>2) << 2);
		if((ccci_uartp_buff[port]).tx->write > (ccci_uartp_buff[port]).tx->len)
			ASSERT(0);
		(ccci_uartp_buff[port]).tx->write %= (ccci_uartp_buff[port]).tx->len;
    #else //for CCIF
    	CCCI_UARTB_PUSH_MULTI(((ccci_uartp_buff[port]).tx), (ccci_uartp_buff[port]).tx_buff, Buffaddr,cnt);
    	
    /* write data through CCCI */

    CCCI_INIT_STREAM(&buff, (kal_uint32)((ccci_uartp_buff[port]).tx_buff), CCCI_TX_BUFF_LEN);
    #endif
    do 
    {
    	#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			ret = ccci_write_internal_sdio(ccci_uart_port[port].tx_channel, ccci_buffer, 0, 0);
		#else
			ret = ccci_write_internal(ccci_uart_port[port].tx_channel, &buff,0, 0);
		#endif
		
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
    } while (1);

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
PRIVATE kal_uint16 ccci_uart_getisrtxavail(DCL_DEV port)
{
    kal_uint32 left;

	
	
    if (port >= (FIRST_CCCI_UART_PORT + MAX_CCCI_UART_PORT)) {
        return KAL_FALSE;
    }
    port -= FIRST_CCCI_UART_PORT;

	//filter the GIO usage
    if(ccci_uart_port[port].gio_mode)
	ASSERT(0);

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
PRIVATE void ccci_uart_putuartbytes(DCL_DEV port, kal_uint8 *data, kal_uint16 len)
{
    module_type ownerid;

    
	
    if ((port >= (FIRST_CCCI_UART_PORT + MAX_CCCI_UART_PORT)) || (port < FIRST_CCCI_UART_PORT)) 
    {
        return;
    }

	//filter the GIO usage
    if(ccci_uart_port[port-FIRST_CCCI_UART_PORT].gio_mode)
		ASSERT(0);
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
PRIVATE void ccci_uart_putuartbyte(DCL_DEV port, kal_uint8 data)
{
    //filter the GIO usage
    if (port >= (FIRST_CCCI_UART_PORT + MAX_CCCI_UART_PORT)) 
    {
        return;
    }

	//filter the GIO usage
    if(ccci_uart_port[port-FIRST_CCCI_UART_PORT].gio_mode)
		ASSERT(0);
	
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
PRIVATE kal_uint8 ccci_uart_getuartbyte(DCL_DEV port)
{
    /* This function can only be called after exception*/
    kal_uint32 avail;
    kal_uint8 data;

   
    if (port >= (FIRST_CCCI_UART_PORT + MAX_CCCI_UART_PORT)) 
    {
        return KAL_FALSE;
    }
    port -= FIRST_CCCI_UART_PORT;

	//filter the GIO usage
    if(ccci_uart_port[port].gio_mode)
		ASSERT(0);


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
PRIVATE kal_uint16 ccci_uart_getrxavail(DCL_DEV port)
{
	kal_uint32 avail;
   
	if (port >= (FIRST_CCCI_UART_PORT + MAX_CCCI_UART_PORT)) 
	{
    	return KAL_FALSE;
   	}
   	port -= FIRST_CCCI_UART_PORT;

   	//filter the GIO usage
   	if(ccci_uart_port[port].gio_mode)
   		ASSERT(0);

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
PRIVATE kal_uint16 ccci_uart_gettxavail(DCL_DEV port)
{
    kal_uint32 avail;
    	
    if (port >= (FIRST_CCCI_UART_PORT + MAX_CCCI_UART_PORT)) 
    {
		return KAL_FALSE;
    }
    port -= FIRST_CCCI_UART_PORT;

	//filter the GIO usage
    if(ccci_uart_port[port].gio_mode)
		ASSERT(0);

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
PRIVATE void ccci_uart_purge(DCL_DEV port, UART_buffer dir, module_type owner)
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
PRIVATE void ccci_uart_setowner(DCL_DEV port, module_type owner)
{
	if ((port >= (FIRST_CCCI_UART_PORT + MAX_CCCI_UART_PORT)) || (port < FIRST_CCCI_UART_PORT))
	{
		return;
	}
	
	/* only AT command channel can be used to change owner */
	if (uart_port_at_ccci != port) 
		return;
	else 
	{
		port -= FIRST_CCCI_UART_PORT;
		ccci_uart_port[port].tx_owner = ccci_uart_port[port].rx_owner = (kal_uint8)owner;
		
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
PRIVATE void ccci_uart_setflowctrl(DCL_DEV port, kal_bool XON, module_type owner)
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
PRIVATE void ccci_uart_configescape(DCL_DEV port, kal_uint8 EscChar, kal_uint16 ESCGuardtime, module_type owner)
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
PRIVATE void ccci_uart_setdcbconfig(DCL_DEV port, UARTDCBStruct *UART_Config, module_type owner)
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
PRIVATE void ccci_uart_ctrldcd(DCL_DEV port, IO_level SDCD, module_type owner)
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
PRIVATE void ccci_uart_ctrlbreak(DCL_DEV port, IO_level SBREAK, module_type owner)
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
PRIVATE void ccci_uart_clrrxbuffer(DCL_DEV port, module_type owner)
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
PRIVATE void ccci_uart_clrtxbuffer(DCL_DEV port, module_type owner)
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
PRIVATE void ccci_uart_setbaudrate(DCL_DEV port, UART_baudrate baudrate, module_type owner)
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
PRIVATE kal_uint16 ccci_uart_sendisrdata(DCL_DEV port, kal_uint8 *Buffaddr, kal_uint16 Length, kal_uint8 mode, kal_uint8 escape_char, module_type ownerid)
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
PRIVATE kal_uint16 ccci_uart_senddata(DCL_DEV port, kal_uint8 *Buffaddr, kal_uint16 Length, kal_uint8 mode, kal_uint8 escape_char, module_type ownerid)
{
    

    if (port >= (FIRST_CCCI_UART_PORT + MAX_CCCI_UART_PORT)) 
    {
        return KAL_FALSE;
    }

	//filter the GIO usage
    if(ccci_uart_port[port-FIRST_CCCI_UART_PORT].gio_mode)
		ASSERT(0);
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
PRIVATE module_type ccci_uart_getownerid(DCL_DEV port)
{
    if (port >= (FIRST_CCCI_UART_PORT + MAX_CCCI_UART_PORT)) 
    {
        return KAL_FALSE;
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
PRIVATE void ccci_uart_setautobaud_div(DCL_DEV port, module_type owner)
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
PRIVATE void ccci_uart_register_tx_cb(DCL_DEV port, module_type owner, DCL_UART_TX_FUNC func)
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
PRIVATE void ccci_uart_register_rx_cb(DCL_DEV port, module_type owner, DCL_UART_RX_FUNC func)
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
PRIVATE void ccci_uart_ReadDCBConfig(DCL_DEV port, UARTDCBStruct *DCB)
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
PRIVATE void ccci_uart_CtrlRI (DCL_DEV port, IO_level SRI, module_type ownerid)
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
PRIVATE void ccci_uart_CtrlDTR(DCL_DEV port, IO_level SDTR, module_type ownerid)
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
PRIVATE void ccci_uart_ReadHWStatus(DCL_DEV port, IO_level *SDSR, IO_level *SCTS)
{
   return ;
}


#if ( !defined(__L1_STANDALONE__) && !defined(__MAUI_BASIC__) )
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
PRIVATE kal_uint8 ccci_uart_gio_enable(DCL_DEV port, kal_uint32 option, module_type owner)
{
	#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		kal_char debug_info[100];
	#endif
	#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		sprintf(debug_info, " in ccci_uart_gio_enable ...  \n\r");
		CCCI_TRACE(debug_info);
	#endif
	//check the validation of port
   	if (port >= (FIRST_CCCI_UART_PORT + MAX_CCCI_UART_PORT)) 
	{
       	return KAL_FALSE;
   	}
	
   	port -= FIRST_CCCI_UART_PORT;
	
	//check the validation of owner
	if (ccci_uart_port[port].tx_owner != owner) 
	{
		#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
			sprintf(debug_info, "<!owner in gio_enable> owner=%d, tx_owner=%d ...  \n\r", owner, ccci_uart_port[port].tx_owner);
			CCCI_TRACE(debug_info);
		#endif
	   	EXT_ASSERT(0, port + FIRST_CCCI_UART_PORT, owner, ccci_uart_port[port].tx_owner);
	}
		
	if (ccci_uart_port[port].rx_owner != owner) 
	{
		#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
			sprintf(debug_info, "<!owner in gio_enable> owner=%d, rx_owner=%d ...  \n\r", owner, ccci_uart_port[port].rx_owner);
			CCCI_TRACE(debug_info);
		#endif
	       	EXT_ASSERT(0, port + FIRST_CCCI_UART_PORT, owner, ccci_uart_port[port].rx_owner);
	}

	//check whether the GIO user or not
	if (port >= 2 && port <= 4)
    {
    	//set the GIO mode in uart port
		ccci_uart_port[port].gio_mode = KAL_TRUE;

        //Stan
        ccci_uart_port[port].flag = 1;
        ccci_uart_port[port].write_flag = 1;
		#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
			sprintf(debug_info, " leave ccci_uart_gio_enable ...  \n\r");
			CCCI_TRACE(debug_info);
		#endif
	    return KAL_TRUE;
    }
    else
    {
		#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
			sprintf(debug_info, " error user in gio_enable ...  \n\r");
			CCCI_TRACE(debug_info);
		#endif
       	return KAL_FALSE;
    }
	
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
PRIVATE kal_uint8 ccci_uart_gio_disable(DCL_DEV port, kal_uint32 option, module_type owner)
{
	//should not call the disable api in SDIO mode confirmed by Stan Chen
	#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		kal_char debug_info[100];
	#endif
	#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		sprintf(debug_info, " in ccci_uart_gio_disable ...  \n\r");
		CCCI_TRACE(debug_info);
	#endif
	EXT_ASSERT(0, port, owner, 0);
	return 0;
}



/*************************************************************************
* FUNCTION
*  ccci_gio_putbytes
*
* DESCRIPTION
*  The function is internal API to process send data list and return the remaing list to UPS.(non-blocking)
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
PRIVATE void* ccci_gio_putbytes(DCL_DEV port, void* buff, module_type ownerid)
{
	kal_uint16 available;
	CCCI_BUFF_T ccci_header;
	kal_uint32 addr, length, count = 0;
	gpd_itr     itr;
    gpd_node*   node = NULL;
	gpd_node*   node_header = NULL;

	#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		kal_char debug_info[100];
	#endif
	
	#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		sprintf(debug_info, " in ccci_gio_putbytes ...  \n\r");
		CCCI_TRACE(debug_info);
	#endif
	
	if (ccci_uart_port[port].tx_owner != ownerid) 
	{
		#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
			sprintf(debug_info, "<!owner in gio_putbytes> owner=%d, tx_owner=%d", ownerid, ccci_uart_port[port].tx_owner);
			CCCI_TRACE(debug_info);
		#endif
		EXT_ASSERT(0, port + FIRST_CCCI_UART_PORT, ownerid, ccci_uart_port[port].tx_owner);
	}
	
	if(buff == NULL)
	{
		#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
			sprintf(debug_info, "<NULL in gio_putbytes>");
			CCCI_TRACE(debug_info);
		#endif
		ASSERT(0);
	}

	//get the remaining space in GIO queue
	available = sdio_query_queue_space(get_gio_handle(), 2, SDIO_RX);
	
	// Create an iterator
	gpd_lib_iterator_create( &itr, (gpd_node**)&buff ); 
	
	//fill in CCCI header of each node in the buff
	while( (node = gpd_lib_iterator_next(&itr)) != NULL)
	{
		//PC-add 0824
		if(count == 0)
			node_header = node;
		count++;
		//PC-end
		
		#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
			sprintf(debug_info, " available = %d ...  \n\r", available);
			CCCI_TRACE(debug_info);
		#endif
		if( available == 0 ) 
			break;

		//only GPD mode for CCCI driver view (not BD mode confirmed by Stan Chen)
		addr = (kal_uint32) node;//bug -->0525 using node instead of using buff
		length = (kal_uint32) (gpd_lib_data_size(node)+ CCCI_HAL_OVERHEAD);//including CCCI header overhead 16 bytes
		CCCI_INIT_STREAM(&ccci_header, addr, length);

		//since we can't modify CCCI header in GIO mode, hence we fill-in the used channel in advanced
		ccci_header.channel = ccci_uart_port[port].tx_channel;
		
		//add the ccci header into the reserved header in GIO buffer
	    gpd_lib_umts_addHeader((gpd_node*)node, (kal_uint8 *)&ccci_header, sizeof(CCCI_BUFF_T));

		//remove the node from list
		//PC-delele 0824
		//node = gpd_lib_iterator_remove(&itr);
		
		//ccci_write_internal_sdio(ccci_uart_port[port].tx_channel, (CCCI_BUFF_T *)node, 1, 2);
		//PC-end

		available--;
		UPS_enqueue++; // 0525 for debug
	}
	//PC-add 0824
	ccci_write_internal_sdio(ccci_uart_port[port].tx_channel, (CCCI_BUFF_T *)node_header, 1, 2);
	node = gpd_lib_iterator_cut(&itr);
	//PC-end
	
	#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		sprintf(debug_info, " leave ccci_gio_putbytes, write_flag = %d ...  \n\r", ccci_uart_port[port].write_flag);
		CCCI_TRACE(debug_info);
	#endif
	//for non-blocking usage
	return node;

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
*  None
*
*************************************************************************/
PRIVATE void* ccci_uart_gio_tx_send_data(DCL_DEV port, void* gpd, kal_uint32 option, module_type owner)
{
	kal_uint16 available;
	CCCI_BUFF_T ccci_header;
	kal_uint32 addr, length;
	gpd_itr     itr;
    gpd_node*   node = NULL;
	#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		kal_char debug_info[100];
	#endif

	if (port >= (FIRST_CCCI_UART_PORT + MAX_CCCI_UART_PORT)) 
	{
		ASSERT(0);
	}
	port -= FIRST_CCCI_UART_PORT;
	
	//check the valid to use gio service
    if(!ccci_uart_port[port].gio_mode)
   	{
   		#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		sprintf(debug_info, "<!GIO mode in gio_putbytes> port=%d, owner=%d", port, owner);
		CCCI_TRACE(debug_info);
		#endif
		ASSERT(0);
   	}

	#if 0
/* under construction !*/
/* under construction !*/
	#endif
	#if 1
	{		
		if (ccci_uart_port[port].tx_owner != owner) 
		{
			#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
				sprintf(debug_info, "<!owner in gio_putbytes> owner=%d, tx_owner=%d", owner, ccci_uart_port[port].tx_owner);
				CCCI_TRACE(debug_info);
			#endif
			EXT_ASSERT(0, port + FIRST_CCCI_UART_PORT, owner, ccci_uart_port[port].tx_owner);
		}
		
		if(gpd == NULL)
		{
			#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
				sprintf(debug_info, "<NULL in gio_putbytes>");
				CCCI_TRACE(debug_info);
			#endif
			ASSERT(0);
		}

		//get the remaining space in GIO queue
		available = sdio_query_queue_space(get_gio_handle(), 2, SDIO_RX);

        if ( available > 0 )
		{
    		// Create an iterator
    		gpd_lib_iterator_create( &itr, (gpd_node**)&gpd ); 

    		//fill in CCCI header of each node in the buff
    		while( (node = gpd_lib_iterator_next(&itr)) != NULL)
    		{
    			#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
    				sprintf(debug_info, " available = %d ...  \n\r", available);
    				CCCI_TRACE(debug_info);
    			#endif
    			if( available == 0 ) 
    				break;

    			//only GPD mode for CCCI driver view (not BD mode confirmed by Stan Chen)
    			addr = (kal_uint32) node;//bug -->0525 using node instead of using buff
    			length = (kal_uint32) (gpd_lib_data_size(node)+ CCCI_HAL_OVERHEAD);//including CCCI header overhead 16 bytes
    			CCCI_INIT_STREAM(&ccci_header, addr, length);

    			//since we can't modify CCCI header in GIO mode, hence we fill-in the used channel in advanced
    			ccci_header.channel = ccci_uart_port[port].tx_channel;
    			
    			//add the ccci header into the reserved header in GIO buffer
    		    gpd_lib_umts_addHeader((gpd_node*)node, (kal_uint8 *)&ccci_header, sizeof(CCCI_BUFF_T));

    			//remove the node from list
    			//node = gpd_lib_iterator_remove(&itr);    		   			

    			available--;
    			UPS_enqueue++; // 0525 for debug
    		}

            node = gpd_lib_iterator_cut(&itr);
            ccci_write_internal_sdio(ccci_uart_port[port].tx_channel, (CCCI_BUFF_T *)gpd, 1, 2);

    		#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
    			sprintf(debug_info, " leave ccci_uart_gio_tx_send_data, write_flag = %d ...  \n\r", ccci_uart_port[port].write_flag);
    			CCCI_TRACE(debug_info);
    		#endif
    		//for non-blocking usage
    		return node;
        }
        else return gpd;           
	}
	#endif

	
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
*  None
*
*************************************************************************/
PRIVATE void* ccci_uart_gio_tx_recycle_gpd(DCL_DEV port, kal_uint32 option, module_type owner)
{
    gpd_node*   gpd = NULL;
	kal_uint32 mask;
	kal_uint8 read_index,write_index;

	#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		kal_char debug_info[100];
	#endif
	#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		sprintf(debug_info, " in ccci_uart_gio_tx_recycle_gpd ...  \n\r");
		CCCI_TRACE(debug_info);
	#endif
	if (port >= (FIRST_CCCI_UART_PORT + MAX_CCCI_UART_PORT)) 
	{
		ASSERT(0);
	}
	port -= FIRST_CCCI_UART_PORT;

	
	//check the valid to use gio service
   	if(!ccci_uart_port[port].gio_mode)
   	{
		#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
			sprintf(debug_info, "<!GIO mode in gio_putbytes> port=%d, owner=%d", port, owner);
			CCCI_TRACE(debug_info);
		#endif
		ASSERT(0);
   	}


	//check the valid of owner
	if (ccci_uart_port[port].tx_owner != owner) 
	{
		#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
			sprintf(debug_info, "<!owner in gio_putbytes> owner=%d, tx_owner=%d", owner, ccci_uart_port[port].tx_owner);
			CCCI_TRACE(debug_info);
		#endif
		EXT_ASSERT(0, port + FIRST_CCCI_UART_PORT, owner, ccci_uart_port[port].tx_owner);
	}

	read_index = gio_recycle_readindx;
	write_index = gio_recycle_writeindx;
    mask = SaveAndSetIRQMask();   
  	if( ccci_uart_port[port].write_flag == 0 ) ccci_uart_port[port].write_flag = 1; 
    RestoreIRQMask(mask);
	

    if ( write_index == read_index ) return NULL;
    else 
    {
    	do
	{	
		//avoid using gRX directly due to race conditon issue
		gpd = gpd_lib_add(gpd, (gpd_node*) gGIO_RECYCLE[read_index].buffer_addr);
		read_index++;
		read_index = (read_index)%RECYCLE_queue_count;
		UPS_dequeue++;//0525 for debug
    	}while( write_index != read_index );
		
	//avoid using sdio_rx_readindx[port] directly due to race conditon issue
	gio_recycle_readindx = read_index;
    }
	return gpd;	
}



/*************************************************************************
* FUNCTION
*  ccci_uart_gio_tx_flush_gpd
*
* DESCRIPTION
*  The function should not be called since the SDIO doesn't support the feature.
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
PRIVATE void* ccci_uart_gio_tx_flush_gpd(DCL_DEV port, kal_uint32 option, module_type owner)
{
	#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		kal_char debug_info[100];
	#endif
	#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		sprintf(debug_info, " in ccci_uart_gio_tx_flush_gpd ...  \n\r");
		CCCI_TRACE(debug_info);
	#endif
	ASSERT(0);
	return 0;
}

/*************************************************************************
* FUNCTION
*  ccci_uart_gio_rx_recv_data
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
*  the data ptr
*
*************************************************************************/
PRIVATE void* ccci_uart_gio_rx_recv_data(DCL_DEV port, kal_uint32 option, module_type owner)
{
   	kal_uint32 mask;
	gpd_node* gpd = NULL;
	kal_uint8 read_index,write_index; 
    kal_uint32 i;

	#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		kal_char debug_info[100];
	#endif
	#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		sprintf(debug_info, " in ccci_uart_gio_rx_recv_data ...  \n\r");
		CCCI_TRACE(debug_info);
	#endif

	if (port >= (FIRST_CCCI_UART_PORT + MAX_CCCI_UART_PORT)) 
	{
		return KAL_FALSE;
	}
    	port -= FIRST_CCCI_UART_PORT;

	//check the valid to use gio service
    if(!ccci_uart_port[port].gio_mode)
   	{
		#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
			sprintf(debug_info, "<!GIO mode in gio_putbytes> port=%d, owner=%d", port, owner);
			CCCI_TRACE(debug_info);
		#endif
		ASSERT(0);
   	}
	
	//check the valid of owner
	if (ccci_uart_port[port].rx_owner != owner) 
	{
	    EXT_ASSERT(0, port + FIRST_CCCI_UART_PORT, owner, ccci_uart_port[port].rx_owner);
		ASSERT(0);
	}	
	
    i = (port-2);
	
	mask = SaveAndSetIRQMask();
	read_index = gio_receive_readindx[i];
	write_index = gio_receive_writeindx[i];
	if(write_index == read_index)
	{
		if(ccci_uart_port[port].flag == 0) ccci_uart_port[port].flag = 1;
	}
	RestoreIRQMask(mask);
	
	if ( (read_index >= TX_queue_count) || (write_index >= TX_queue_count) )
		ASSERT(0);

    if ( write_index != read_index )
    {
    	do
    	{		   
    		gpd = gpd_lib_add(gpd, (gpd_node*) gGIO_RECEIVE[i][read_index].buffer_addr);
           	read_index++; 
    		read_index = (read_index)%TX_queue_count;
    	}while( write_index != read_index );
        
        gio_receive_readindx[i] = read_index;
    }   
     
	return gpd;
}


/*************************************************************************
* FUNCTION
*  ccci_uart_gio_rx_load_gpd
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
*  None
*
*************************************************************************/
PRIVATE void ccci_uart_gio_rx_load_gpd(DCL_DEV port, void* gpd, kal_uint32 option, module_type owner)
{
	SDIO_STATUS status;
	SDIO_BUFFER_DESCRIPTOR bd;
	kal_uint16 available, used;
	#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		kal_char debug_info[100];
	#endif
	#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		sprintf(debug_info, " in ccci_uart_gio_rx_load_gpd ...  \n\r");
		CCCI_TRACE(debug_info);
	#endif

	if (port >= (FIRST_CCCI_UART_PORT + MAX_CCCI_UART_PORT)) 
	{
		ASSERT(0);
	}
	
	port -= FIRST_CCCI_UART_PORT;
	
	//check the valid to use gio service
    if(!ccci_uart_port[port].gio_mode)
   	{
		#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
			sprintf(debug_info, "<!GIO mode in gio_putbytes> port=%d, owner=%d ...  \n\r", port, owner);
			CCCI_TRACE(debug_info);
		#endif
		ASSERT(0);
   	}

	//check the valid of owner
	if (ccci_uart_port[port].rx_owner != owner) 
	{
	    EXT_ASSERT(0, port + FIRST_CCCI_UART_PORT, owner, ccci_uart_port[port].rx_owner);
	}

	//get the remaining space in GIO queue
	available = sdio_query_queue_space(get_gio_handle(), port, SDIO_TX);

	//parse the gpd number from user data ptr
	used = gpd_lib_size((gpd_node*)gpd);

	if(used > available)
	{
		#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
			sprintf(debug_info, "the transferred gpd # is over the underline size ...  \n\r");
			CCCI_TRACE(debug_info);
		#endif
		ASSERT(0);
	}
	

	SDIO_BUFFER_SET_LENGTH(bd, (kal_uint32) gpd_lib_data_size((gpd_node*) gpd));  
	SDIO_BUFFER_SET_PRIORITY(bd, port);
	SDIO_BUFFER_SET_ADDRESS(bd, (kal_uint32)gpd);
	
	//the gpd will not include CCCI header
	if((status = sdio_tx_load(get_gio_handle(), &bd)) != 0)
	{
		#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
			sprintf(debug_info, "invalid status = %d in rx_load_gpd...\n\r", status);
			CCCI_TRACE(debug_info);
		#endif
		ASSERT(0);
	}
	#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		sprintf(debug_info, " leave ccci_uart_gio_rx_load_gpd ...  \n\r");
		CCCI_TRACE(debug_info);
	#endif
}



/*************************************************************************
* FUNCTION
*  ccci_uart_gio_rx_load_null_gpd
*
* DESCRIPTION
*  The function is for gio users to load null gpd ptr to HW medium.
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
PRIVATE void ccci_uart_gio_load_dummy_gpd(DCL_DEV port, void* TX_gpd, kal_uint32 TX_size, void* RX_gpd, kal_uint32 RX_size)
{
	SDIO_BUFFER_DESCRIPTOR bd;

	#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		kal_char debug_info[100];
	#endif
	#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		sprintf(debug_info, " in ccci_uart_gio_load_dummy_gpd ...  \n\r");
		CCCI_TRACE(debug_info);
	#endif
	
	if (port >= (FIRST_CCCI_UART_PORT + MAX_CCCI_UART_PORT)) 
	{
		ASSERT(0);
	}
	
	port -= FIRST_CCCI_UART_PORT;
	
	//check the valid to use gio service
   	if(!ccci_uart_port[port].gio_mode)
   	{
		#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
			sprintf(debug_info, "<!GIO mode in gio_putbytes> port=%d", port);
			CCCI_TRACE(debug_info);
		#endif
		ASSERT(0);
   	}
	

	#define UPS_BASE 2
	if(TX_gpd != NULL)
	{
		//must to initialize the length to be zero in dummy gpd
		SDIO_BUFFER_SET_LENGTH(bd, 0);  
		SDIO_BUFFER_SET_PRIORITY(bd, UPS_BASE);
		SDIO_BUFFER_SET_ADDRESS(bd, (kal_uint32)TX_gpd);

		if(sdio_load_dummy_GPD(get_gio_handle(), &bd, SDIO_RX, TX_size) != 0)
		{
			#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
				sprintf(debug_info, "invalid status in rx_load_gpd");
				CCCI_TRACE(debug_info);
			#endif
			ASSERT(0);
		}
	}
	
	if(RX_gpd != NULL)
	{	
		SDIO_BUFFER_SET_LENGTH(bd, (kal_uint32) gpd_lib_data_size((gpd_node*) RX_gpd));  
		SDIO_BUFFER_SET_PRIORITY(bd, port);
		SDIO_BUFFER_SET_ADDRESS(bd, (kal_uint32)RX_gpd);

		if(sdio_load_dummy_GPD(get_gio_handle(), &bd, SDIO_TX, RX_size) != SDIO_SUCCESS)
		{
			#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
				sprintf(debug_info, "invalid status in rx_load_gpd");
				CCCI_TRACE(debug_info);
			#endif
			ASSERT(0);
		}
	}
	#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		sprintf(debug_info, " leave ccci_uart_gio_load_dummy_gpd ...  \n\r");
		CCCI_TRACE(debug_info);
	#endif
}


/*************************************************************************
* FUNCTION
*  ccci_uart_gio_rx_flush_gpd
*
* DESCRIPTION
*  The function should not be called since the SDIO doesn't support the feature.
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
PRIVATE void* ccci_uart_gio_rx_flush_gpd(DCL_DEV port, kal_uint32 option, module_type owner)
{
	#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		kal_char debug_info[100];
	#endif
	#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		sprintf(debug_info, " in ccci_uart_gio_rx_flush_gpd ...  \n\r");
		CCCI_TRACE(debug_info);
	#endif

	ASSERT(0);
	return 0;
}
#endif//( !defined(__L1_STANDALONE__) && !defined(__MAUI_BASIC__) )

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
	kal_bool return_flag = KAL_FALSE;
	kal_bool return_status = STATUS_OK;
	
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
					return_flag =ccci_uart_open(dev,prCtrlOpen->u4OwenrId);
					if(return_flag == KAL_FALSE)
					return_status = STATUS_FAIL;
				}
			break;
			
		case SIO_CMD_CLOSE:
				{
					UART_CTRL_CLOSE_T* prCtrlClose;
					prCtrlClose = &(data->rUARTCtrlCLOSE);
					ccci_uart_close(dev,prCtrlClose->u4OwenrId);
				}
			break;
			
		case SIO_CMD_GET_BYTES:
				{
					UART_CTRL_GET_BYTES_T* prCtrlGetBytes;
					prCtrlGetBytes = &(data->rUARTCtrlGETBYTES);
					prCtrlGetBytes->u2RetSize= ccci_uart_getbytes(dev, prCtrlGetBytes->puBuffaddr, prCtrlGetBytes->u2Length, prCtrlGetBytes->pustatus, prCtrlGetBytes->u4OwenrId);
				}
			break;
			
		case SIO_CMD_PUT_BYTES:
				{
					UART_CTRL_PUT_BYTES_T* prCtrlPutBytes;
					prCtrlPutBytes = &(data->rUARTCtrlPUTBYTES);
					prCtrlPutBytes->u2RetSize= ccci_uart_putbytes(dev, prCtrlPutBytes->puBuffaddr, prCtrlPutBytes->u2Length, prCtrlPutBytes->u4OwenrId);
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
																prCtrlPutBytes->u4OwenrId);
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
					ccci_uart_purge(dev,prCtrlPurge->dir,prCtrlPurge->u4OwenrId);
				}
			break;
			
		case SIO_CMD_SET_OWNER:
				{
					 UART_CTRL_OWNER_T* prCtrlOwner;
					 prCtrlOwner = &(data->rUARTCtrlOWNER);
					 ccci_uart_setowner(dev,prCtrlOwner->u4OwenrId);					 
				}
			break;
			
		case SIO_CMD_SET_FLOW_CTRL:
				{
					UART_CTRL_FLOW_CTRL_T* prCtrlFlowCtrl;
					prCtrlFlowCtrl = &(data->rUARTCtrlFLOWCTRL);
					ccci_uart_setflowctrl(dev,prCtrlFlowCtrl->bXON,prCtrlFlowCtrl->u4OwenrId);
				}
			break;
			
		case SIO_CMD_CONFIG_ESCAPE:
				{
					UART_CTRL_CONFIG_ESP_T* prCtrlConfigEsp;
					prCtrlConfigEsp = &(data->rUARTCtrlCONFIGESP);
					ccci_uart_configescape(dev,prCtrlConfigEsp->uEscChar,prCtrlConfigEsp->u2ESCGuardtime,prCtrlConfigEsp->u4OwenrId);					
				}
			break;
   			
		case SIO_CMD_SET_DCB_CONFIG:
				{
					UARTDCBStruct *prDCB;
					UART_CTRL_DCB_T* prCtrlDCB;
					prCtrlDCB = &(data->rUARTCtrlDCB);
					prDCB = (UARTDCBStruct*)(&(prCtrlDCB->rUARTConfig));
					ccci_uart_setdcbconfig(dev,prDCB,prCtrlDCB->u4OwenrId);
				}
			break;
			
		case SIO_CMD_CTRL_DCD:
				{
					 UART_CTRL_DCD_T* prCtrlDCD;
					 prCtrlDCD = &(data->rUARTCtrlDCD);
					 ccci_uart_ctrldcd(dev,prCtrlDCD->rIOLevelDCD,prCtrlDCD->u4OwenrId);
				}
			break;
			
		case SIO_CMD_CTRL_BREAK:
				{
					UART_CTRL_BREAK_T* prCtrlBreak;
					prCtrlBreak = &(data->rUARTCtrlBREAK);
					ccci_uart_ctrlbreak(dev,prCtrlBreak->rIOLevelBRK,prCtrlBreak->u4OwenrId);
				}
			break;
   			
		case SIO_CMD_CLR_RX_BUF:
				{
					UART_CTRL_CLR_BUFFER_T* prCtrlClrBuffer;
					prCtrlClrBuffer = &(data->rUARTCtrlCLRBUFFER);
					ccci_uart_clrrxbuffer(dev,prCtrlClrBuffer->u4OwenrId);
				}
			break;
			
		case SIO_CMD_CLR_TX_BUF:
				{
					UART_CTRL_CLR_BUFFER_T* prCtrlClrBuffer;
					prCtrlClrBuffer = &(data->rUARTCtrlCLRBUFFER);
					ccci_uart_clrtxbuffer(dev,prCtrlClrBuffer->u4OwenrId);
				}
			break;
			
		case SIO_CMD_SET_BAUDRATE:
				{
					UART_CTRL_BAUDRATE_T* prCtrlBaudrate;
					prCtrlBaudrate = &(data->rUARTCtrlBAUDRATE);
					ccci_uart_setbaudrate(dev,prCtrlBaudrate->baudrate,prCtrlBaudrate->u4OwenrId);
				}
			break;
   
		case SIO_CMD_SEND_ISR_DATA:
				{
					UART_CTRL_SEND_DATA_T* prCtrlSendData;
					prCtrlSendData = &(data->rUARTCtrlSENDDATA);
					prCtrlSendData->u2RetSize = ccci_uart_sendisrdata(dev,prCtrlSendData->puBuffaddr,prCtrlSendData->u2Length,
										prCtrlSendData->umode,prCtrlSendData->uescape_char,prCtrlSendData->u4OwenrId);
				}	
			break;
			
		case SIO_CMD_SEND_DATA:
				{
					UART_CTRL_SEND_DATA_T* prCtrlSendData;
					prCtrlSendData = &(data->rUARTCtrlSENDDATA);
					prCtrlSendData->u2RetSize = ccci_uart_senddata(dev,prCtrlSendData->puBuffaddr,prCtrlSendData->u2Length,
										prCtrlSendData->umode,prCtrlSendData->uescape_char,prCtrlSendData->u4OwenrId);
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
					 ccci_uart_setautobaud_div(dev,prCtrlAutoBaudDiv->u4OwenrId);
				}
			break;
			
		case SIO_CMD_REG_TX_CB:
				{
					UART_CTRL_REG_TX_CB_T* prCtrlTxCB;
					prCtrlTxCB = &(data->rUARTCtrlREGTXCB);
					ccci_uart_register_tx_cb(dev,prCtrlTxCB->u4OwenrId,(DCL_UART_TX_FUNC)prCtrlTxCB->func); 
				}
			break;
			
		case SIO_CMD_REG_RX_CB:
				{
					 UART_CTRL_REG_RX_CB_T * prCtrlRxCb;
					 prCtrlRxCb = &(data->rUARTCtrlREGRXCB);
					 ccci_uart_register_rx_cb(dev,prCtrlRxCb->u4OwenrId,(DCL_UART_RX_FUNC)prCtrlRxCb->func); 
				}
			break;


		case SIO_CMD_GET_UART_BYTE:
				{
					 //UART_CTRL_GET_UART_BYTE_T* prCtrlGetUartByte;
					 //prCtrlGetUartByte = &(data->rUARTCtrlGETUARTBYTE);
					 ccci_uart_getuartbyte(dev); 
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
					 ccci_uart_putuartbytes(dev,prCtrlPutUartBytes->puBuffaddr,prCtrlPutUartBytes->u2Length); 
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
					 ccci_uart_CtrlRI(dev,prCtrlRI->rIOLevelSRI,prCtrlRI->u4OwenrId); 
				}
			break;
			
		case SIO_CMD_CTRL_DTR:
				{
					UART_CTRL_DTR_T* prCtrlDTR;
					prCtrlDTR = &(data->rUARTCtrlDTR);
					 ccci_uart_CtrlDTR(dev,prCtrlDTR->rIOLevelDTR,prCtrlDTR->u4OwenrId); 
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
#if ( !defined(__L1_STANDALONE__) && !defined(__MAUI_BASIC__) )			
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
					prCtrGE->pOut_GPD = ccci_uart_gio_tx_send_data(dev, prCtrGE->pIn_GPD, prCtrGE->option, prCtrGE->u4OwnerId);
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
					ccci_uart_gio_rx_load_gpd(dev, prCtrGE->pIn_GPD, prCtrGE->option, prCtrGE->u4OwnerId);
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
#endif
		default:
			return STATUS_INVALID_CMD;
		}

	return return_status;//return STATUS_OK;
}

#endif  /* __SMART_PHONE_MODEM__ */
#endif  /* __MODEM_CCCI_EXIST__ */

