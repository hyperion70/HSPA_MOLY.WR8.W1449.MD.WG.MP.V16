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
 *   mdif.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This function implements MDIF.
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

#ifndef __IVP__
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#endif
#include "reg_base.h"
#ifndef __IVP__
#include "intrCtrl.h"
#include "drv_hisr.h"
#include "task_config.h"
#include "init.h"
#include "custom_scatstruct.h"
#include "us_timer.h"
#else /* __IVP__ */
#include "sal_header.h"
#endif /* __IVP__ */

#if defined(__DSP_FCORE4__)

#include "mdci_int.h"
#include "mdci.h"
#include "dmdsp_init.h"

#if defined(__MODEM_CCCI_EXIST__)
#include "ccci.h"
#endif /* __MODEM_CCCI_EXIST__ */


/*******************************************************************************
 * Define global variables.
 *******************************************************************************/
typedef struct
{
  kal_uint32   tick;
  MDCI_CTRL_T  ct;
} MDCI_TRANS_LOG;

#define DebugEntryNo 8 /* defined the log no for each channel */

kal_uint32              g_mcud_chkaddr = (MDMDIF_SRAM + MDMDIF_SRAM_OFFSET + MDMDIF_SRAM_SIZE - 4);
__attribute__  ((zero_init)) kal_uint32       mdci_trans_log_index[MDCI_MAX_CHANNEL] = {};
__attribute__  ((zero_init)) MDCI_TRANS_LOG   mdci_trans_log_pool[MDCI_MAX_CHANNEL][DebugEntryNo]={};
__attribute__  ((zero_init)) MDCI_BUFF_T      mdci_last_rx_snapshot[MDIF_MAX_PHY]={};
__attribute__  ((zero_init)) kal_uint8        mdci_readindx_for_MD;
__attribute__  ((zero_init)) kal_uint8        mdci_writeindx_for_FC;
__attribute__  ((zero_init)) kal_uint32       mdci_exception_check_write_result;
__attribute__  ((zero_init)) kal_uint32       mdci_exception_info_write_result;
kal_bool		mdci_exception_handshake_done = KAL_FALSE;
MDCI_CTRL_T		mdci_ctrl_pool[MDCI_MAX_CHANNEL];
kal_uint32		mdci_last_con;
kal_uint32		mdci_last_rx_channel;

DSP_RUNTIME_DATA        md_dsp_share_data;
kal_uint32              mdci_md_offset;
volatile kal_bool 	    g_dsp_boot_success = KAL_FALSE;


/*******************************************************************************
 * Define import global variables.
 *******************************************************************************/
#if defined(__MODEM_CCCI_EXIST__)
extern MODEM_RUNTIME_DATA ap_md_share_data;
#endif /* __MODEM_CCCI_EXIST__ */

/*******************************************************************************
 * Define import function prototype.
 *******************************************************************************/
extern kal_bool kal_query_systemInit(void);
extern kal_bool INT_QueryExceptionStatus(void);
extern kal_uint32 mdci_fill_DSPShareMemInfo(DSP_SHARE_MEM_INFO* output_p);
extern kal_uint32 kal_get_systicks(void);


/*******************************************************************************
 * Define porting function prototype.
 *******************************************************************************/
#ifdef __IVP__
kal_taskid kal_get_current_thread_ID(void)
{
	return 0;
}

kal_bool kal_query_systemInit(void)
{
	return 0;
}

kal_bool INT_QueryExceptionStatus(void)
{
	return 0;
}
#endif/* __IVP__ */




/*************************************************************************
* FUNCTION
*  mdci_is_chanel_need_check_owner
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
static kal_bool mdci_is_chanel_need_check_owner(MDCI_CHANNEL_T channel)
{
	
#ifndef __IVP__
	if(INT_QueryExceptionStatus() == KAL_TRUE  || kal_query_systemInit() == KAL_TRUE)	
	{
		return KAL_FALSE;
	}
	else
#endif /* __IVP__ */
	{

		return KAL_FALSE;
	}

}

/*************************************************************************
* FUNCTION
*  mdci_hisr
*
* DESCRIPTION
*  This function processes MDIF HISR.
*
* PARAMETERS
*  none
*
* RETURNS
*  none
*
*************************************************************************/
void mdci_hisr()
{
    kal_uint32 channel, arb;


    if (*MDIF_CON & MDIF_CON_ARB) {
        arb = 1;
    } else {
        arb = 0;
    }

    /* get logical channel which has data to read */
    for (channel = 0; channel < MDCI_MAX_CHANNEL; channel++) {
        if (mdci_ctrl_pool[channel].state & MDCI_ACTIVE_ISR) {
#ifndef __IVP__
            mdci_trans_log_pool[channel][mdci_trans_log_index[channel]].tick = kal_get_systicks();
#endif /* __IVP__ */            
            kal_mem_cpy(&(mdci_trans_log_pool[channel][mdci_trans_log_index[channel]].ct),&mdci_ctrl_pool[channel], sizeof(MDCI_CTRL_T));
            mdci_trans_log_index[channel]++;
            mdci_trans_log_index[channel]%=(DebugEntryNo);
            
            
            if (mdci_ctrl_pool[channel].state & MDCI_ACTIVE_READ) {
                /* a mdci_read() is waiting */
                /* set an event */
                #ifndef __IVP__
                kal_set_eg_events(mdci_ctrl_pool[channel].event, 1, KAL_OR);
								#else /* __IVP__ */
								dbg_print("Error, IVP should not come here \n\r");
								#endif

                /* clear MDCI_ACTIVE_ISR (only keep MDCI_ACTIVE_READ) */
                mdci_ctrl_pool[channel].state = MDCI_ACTIVE_READ;
            } else {
                /* invoke callback function */
                if (mdci_ctrl_pool[channel].funp == NULL) {
                    EXT_ASSERT(0, channel, 0, 0);
                } else {
                    mdci_ctrl_pool[channel].funp(&(mdci_ctrl_pool[channel].buff));
                }
                /* set IDLE */
                mdci_ctrl_pool[channel].state = MDCI_IDLE;
            }

            /* only one channel at one time under sequential mode */
            if (arb == 0) {
                break;
            }
        } 
    }

    if (arb == 0 && channel == MDCI_MAX_CHANNEL) {
        ASSERT(0);
    }

    /* Unmask MDIF */
#if defined(MDIF_FOR_AP_SIDE)
    IRQUnmask(IRQ_APMDIF_CODE); 
#else
    IRQUnmask(IRQ_MDIF_CODE);
#endif
}


/*************************************************************************
* FUNCTION
*  mdci_lisr
*
* DESCRIPTION
*  This function processes MDIF LISR.
*
* PARAMETERS
*  none
*
* RETURNS
*  none
*
*************************************************************************/

__attribute__((section ("INTSRAM_ROCODE"))) void mdci_lisr()
{
    kal_uint32 arb, phy_chann, i, log_chann;
    MDCI_BUFF_T *buff;


    /* mask MDIF */
#if defined(MDIF_FOR_AP_SIDE)
    IRQMask(IRQ_APMDIF_CODE);
#else
    IRQMask(IRQ_MDIF_CODE);
#endif

    /* get arbitration mode */
    if (*MDIF_CON & MDIF_CON_ARB)
    {
        arb = 1;
    }
    else
    {
        arb = 0;
    }

    /* get physical channel which needs to be read */
    phy_chann = *MDIF_RCHNUM;

    //for (i = 0; i < MDIF_MAX_PHY; i++) {
     for (i = mdci_readindx_for_MD; i < mdci_readindx_for_MD + MDIF_MAX_PHY; i++)
    {
        /* get logical channel one by one*/
        if (phy_chann == 0) break;
        i = i % MDIF_MAX_PHY;
        
        /* get logical channel number */
        if (arb == 0)
        {
            buff = (MDCI_BUFF_T *)MDIF_RXCHDATA + phy_chann;
            log_chann = buff->channel;
            i = phy_chann;
        }
        else if (phy_chann & (1 << i))
        {
            buff = (MDCI_BUFF_T *)MDIF_RXCHDATA + i;
            log_chann = buff->channel;
        }
        else
        {
            continue;
        }

        /* validate logical channel */
        if (log_chann == MDCI_FORCE_RESET_MODEM_CHANNEL)
        {
            #define FORCE_RESET_MODEM   (0)
            EXT_ASSERT(FORCE_RESET_MODEM, log_chann, phy_chann, 0);
        }
        else if (log_chann >= MDCI_MAX_CHANNEL)
        {
            EXT_ASSERT(0, log_chann, phy_chann, 0);
        }
   

        /* check state */
        if (mdci_ctrl_pool[log_chann].state == MDCI_ACTIVE_READ)
        {
            /* use OR operation since a mdci_read() is waiting */
            mdci_ctrl_pool[log_chann].state |= MDCI_ACTIVE_ISR;
        }
        else if (mdci_ctrl_pool[log_chann].state == MDCI_IDLE)
        {
            mdci_ctrl_pool[log_chann].state = MDCI_ACTIVE_ISR;
        }
        else if (mdci_ctrl_pool[log_chann].state == MDCI_ACTIVE_WRITE)
        {
            /* a mdci_write() is not finished */
            EXT_ASSERT(0, phy_chann, log_chann, mdci_ctrl_pool[log_chann].state);
        }
        else if (mdci_ctrl_pool[log_chann].state == MDCI_ACTIVE_ISR)
        {
            /* a mdci_hisr() is not done yet */
            if (arb == 0)
            {
                /* not allow in sequential mode */
                EXT_ASSERT(0, phy_chann, log_chann, mdci_ctrl_pool[log_chann].state);
            }
            else
            {
                /* pend */
                break; // KC: change the continue to break due to mdif phy race condition problem.
                //continue;
            }
        }
        else
        {
            EXT_ASSERT(0, phy_chann, log_chann, mdci_ctrl_pool[log_chann].state);
        }

        /* copy channel buffer */
        kal_mem_cpy(&(mdci_ctrl_pool[log_chann].buff), buff, sizeof(MDCI_BUFF_T));

        /* ack MDIF to release the physical channel */
        *MDIF_ACK = (1 << i);
        phy_chann &= ~(1<<i);

        /* only one channel at one time under sequential mode */
        if (arb == 0)
        { 
            break;
        }
    }

    mdci_readindx_for_MD = i;


#ifndef __IVP__
    /* activate HISR */    
    if (KAL_TRUE == kal_query_systemInit())
    {
#endif /* __IVP__ */
        mdci_hisr();
#ifndef __IVP__
    }
    else
    {
        drv_active_hisr(DRV_MDIF_HISR_ID);
    }
#endif /* __IVP__ */    
}

/*************************************************************************
* FUNCTION
*  mdci_init
*
* DESCRIPTION
*  This function initialized MDIF.
*
* PARAMETERS
*  arb          -    arbitration mode flag
*  md_offset    -    modem side master offset address(in bytes).
*
* RETURNS
*  none
*
*************************************************************************/
void mdci_hw_init(kal_uint32 arb, kal_uint32 md_offset)
{
    /* set arbitration mode */
    if (arb == 1) {
        *MDIF_CON |= MDIF_CON_ARB;
    }

    /* initialize the MD side address offset */
    mdci_md_offset = md_offset;


    /* register LISR */

#if defined(MDIF_FOR_AP_SIDE)
    IRQ_Register_LISR(IRQ_APMDIF_CODE, mdci_lisr, "MDIF LISR");
#else
    IRQ_Register_LISR(IRQ_MDIF_CODE, mdci_lisr, "MDIF LISR");
#endif

#ifndef __IVP__
    /* register HISR */
    DRV_Register_HISR(DRV_MDIF_HISR_ID, mdci_hisr);
#endif /* __IVP__ */

    /* set IRQ sensitivity */
#if defined(MDIF_FOR_AP_SIDE)
    IRQSensitivity(IRQ_APMDIF_CODE, LEVEL_SENSITIVE);
#else
    IRQSensitivity(IRQ_MDIF_CODE, LEVEL_SENSITIVE);
#endif
    /* unmask MDIF */
#if defined(MDIF_FOR_AP_SIDE)
    IRQUnmask(IRQ_APMDIF_CODE);
#else
    IRQUnmask(IRQ_MDIF_CODE);
#endif
}


/*************************************************************************
* FUNCTION
*  mdci_owner_init
*
* DESCRIPTION
*  This function initializes the logical channel for the specified task.
*
* PARAMETERS
*  channel    -    logical channel
*  task       -    owner task
*  funp       -    ISR callback function
*
* RETURNS
*  MDIF error code.
*
*************************************************************************/
kal_int32 mdci_owner_init(MDCI_CHANNEL_T channel, kal_taskid task, MDCI_CALLBACK funp)
{
    kal_uint32 owner, mask;
    kal_int32 ret;


    /* error checking */
    if (channel >= MDCI_MAX_CHANNEL)
        return MDCI_INVALID_PARAM;
    if (funp == NULL)
        return MDCI_INVALID_PARAM;
    if (kal_if_lisr())
        return MDCI_IN_LISR;

    ret = MDCI_SUCCESS;

    owner = (kal_uint32)task;

    /* check if the channel is free */
    mask = SaveAndSetIRQMask();
    if (mdci_ctrl_pool[channel].owner != 0) {
        ret = MDCI_IN_USE;
    } else {
        mdci_ctrl_pool[channel].owner = owner;
    }
    RestoreIRQMask(mask);
    if (ret != MDCI_SUCCESS)
        return ret;

    /* initialize the control block */
    mdci_ctrl_pool[channel].state = MDCI_IDLE;
    kal_mem_set(&(mdci_ctrl_pool[channel].buff), 0, sizeof(MDCI_BUFF_T));
    mdci_ctrl_pool[channel].funp = funp;

    return ret;
}


/*************************************************************************
* FUNCTION
*  mdci_init
*
* DESCRIPTION
*  This function initializes the logical channel.
*
* PARAMETERS
*  channel    -    logical channel
*  funp       -    ISR callback function
*
* RETURNS
*  MDIF error code.
*
*************************************************************************/
kal_int32 mdci_init(MDCI_CHANNEL_T channel, MDCI_CALLBACK funp)
{
    kal_taskid task;


    /* get the current task */
    task = kal_get_current_thread_ID();

    return mdci_owner_init(channel, task, funp);
}


/*************************************************************************
* FUNCTION
*  mdci_deinit
*
* DESCRIPTION
*  This function de-initializes the logical channel.
*
* PARAMETERS
*  channel    -    logical channel
*
* RETURNS
*  MDIF error code.
*
*************************************************************************/
kal_int32 mdci_deinit(MDCI_CHANNEL_T channel)
{
    kal_uint32 owner, mask;
    kal_int32 ret;


    /* error checking */
    if (channel >= MDCI_MAX_CHANNEL)
        return MDCI_INVALID_PARAM;
    if (kal_if_lisr())
        return MDCI_IN_LISR;

    /* get the current task */
    owner = (kal_uint32)kal_get_current_thread_ID();

    /* check owner */
    if (mdci_ctrl_pool[channel].owner != owner) {
        return MDCI_NOT_OWNER;
    }

    ret = MDCI_SUCCESS;

    /* check state */
    mask = SaveAndSetIRQMask();
    if (mdci_ctrl_pool[channel].state != MDCI_IDLE) {
        ret = MDCI_IN_USE;
    } else {
        /* free the channel */
        mdci_ctrl_pool[channel].owner = 0;
    }
    RestoreIRQMask(mask);

    return ret;
}


/*************************************************************************
* FUNCTION
*  mdci_write
*
* DESCRIPTION
*  This function writes data through either mailbox channel or stream
*  channel.
*
* PARAMETERS
*  channel    -    logical channel
*  buff       -    pointer to channel buffer
*
* RETURNS
*  MDIF error code.
*
*************************************************************************/
kal_uint32 log_index = 0;

typedef struct err_log_t
{
    kal_uint32 return_tick;
    kal_uint32 return_value;
    kal_uint32 return_busy;
    kal_uint32 return_write_index;
}ERR_LOG_T;



__attribute__  ((zero_init)) ERR_LOG_T mdci_err_log[DebugEntryNo] = {};


__attribute__((section ("INTSRAM_ROCODE"))) kal_int32 mdci_write_internal(MDCI_CHANNEL_T channel, MDCI_BUFF_T *buff,kal_bool check_lisr)
{
    kal_uint32 owner, mask, mdci_busy, phy_chann, saveaddr = 0;
    kal_int32 ret;
    MDCI_BUFF_T *chdata;


    /* check if a LISR is running */
    if (1 == check_lisr) { 
    	if (kal_if_lisr())
       {   
              mask = SaveAndSetIRQMask();
              mdci_err_log[log_index].return_tick = kal_get_systicks();
              mdci_err_log[log_index].return_value = MDCI_IN_LISR;
              log_index++;
			  log_index %= DebugEntryNo;
              RestoreIRQMask(mask);
        	return MDCI_IN_LISR;
        }
    }

    /* check parameters */
    if (channel >= MDCI_MAX_CHANNEL)
    {
        mask = SaveAndSetIRQMask();
        mdci_err_log[log_index].return_tick = kal_get_systicks();
        mdci_err_log[log_index].return_value = MDCI_INVALID_PARAM;
        log_index++;
        log_index %= DebugEntryNo;
        RestoreIRQMask(mask);
        return MDCI_INVALID_PARAM;
    }
    if (buff == NULL)
    {
        mask = SaveAndSetIRQMask();
        mdci_err_log[log_index].return_tick = kal_get_systicks();
        mdci_err_log[log_index].return_value = MDCI_INVALID_PARAM;
        log_index++;
        log_index %= DebugEntryNo;

        RestoreIRQMask(mask);
        return MDCI_INVALID_PARAM;
    }

    /* get the current task */
    owner = (kal_uint32)kal_get_current_thread_ID();

    /* check owner */
    if (mdci_ctrl_pool[channel].owner != owner && mdci_is_chanel_need_check_owner(channel) ) 
    {
        mask = SaveAndSetIRQMask();
        mdci_err_log[log_index].return_tick = kal_get_systicks();
        mdci_err_log[log_index].return_value = MDCI_NOT_OWNER;
        log_index++;
        log_index %= DebugEntryNo;

        RestoreIRQMask(mask);
        return MDCI_NOT_OWNER;
    }

    /* check state */
    ret = MDCI_SUCCESS;
    mask = SaveAndSetIRQMask();
    if (mdci_ctrl_pool[channel].state != MDCI_IDLE) 
    {
        ret = MDCI_IN_USE;
    } 
    else 
    {
        /* set ACTIVE_WRITE */
        mdci_ctrl_pool[channel].state = MDCI_ACTIVE_WRITE;
    }
    RestoreIRQMask(mask);
    if (ret != MDCI_SUCCESS)
    {
        mask = SaveAndSetIRQMask();
        mdci_err_log[log_index].return_tick = kal_get_systicks();
        mdci_err_log[log_index].return_value = ret;
        log_index++;
        log_index %= DebugEntryNo;

        RestoreIRQMask(mask);
        return ret;
    }

    /* get one physical channel */
    mask = SaveAndSetIRQMask();
    mdci_busy = *MDIF_BUSY;
    //for (phy_chann = 0; phy_chann < MDIF_MAX_PHY; phy_chann++) {
    for (phy_chann = mdci_writeindx_for_FC ; phy_chann < (mdci_writeindx_for_FC + MDIF_MAX_PHY); phy_chann++) {
	 phy_chann %= MDIF_MAX_PHY;
        if (mdci_busy & (1 << phy_chann)) {
            //continue;
            
            mdci_err_log[log_index].return_tick = kal_get_systicks();
            mdci_err_log[log_index].return_value = MDCI_NO_PHY_CHANNEL;
            mdci_err_log[log_index].return_busy = mdci_busy;
            mdci_err_log[log_index].return_write_index = mdci_writeindx_for_FC;
        	log_index++;
        	log_index %= DebugEntryNo;

            
            RestoreIRQMask(mask);
            mdci_ctrl_pool[channel].state = MDCI_IDLE;
        		return MDCI_NO_PHY_CHANNEL;        		
            //break;
        } else {
            /* set BUSY bit */
            *MDIF_BUSY = (1 << phy_chann);
	     mdci_writeindx_for_FC = (phy_chann + 1)%MDIF_MAX_PHY;
            break;
        }
    }
    


    /* set logical channel number */
    buff->channel = channel;

    
#ifndef __IVP__
    mdci_trans_log_pool[channel][mdci_trans_log_index[channel]].tick = kal_get_systicks();
#endif /* __IVP__ */    
    
    /* add a MD offset for the stream buffer address */
    if (!MDCI_IS_MAILBOX(buff)) {
        saveaddr = MDCI_STREAM_ADDR(buff);
#if defined(MDIF_FOR_AP_SIDE)
        MDCI_STREAM_ADDR(buff) |= mdci_md_offset;
#else /* MDIF_FOR_AP_SIDE */
        MDCI_STREAM_ADDR(buff) &= ~mdci_md_offset;
#endif  /* MDIF_FOR_AP_SIDE */
    }

    /* copy channel buffer */
    chdata = (MDCI_BUFF_T *)MDIF_TXCHDATA + phy_chann;
    kal_mem_cpy(chdata, buff, sizeof(MDCI_BUFF_T));

    
    /* restore the stream buffer address */
    if (!MDCI_IS_MAILBOX(buff)) {
        MDCI_STREAM_ADDR(buff) = saveaddr;
    }

    /* start MDIF */
    *MDIF_TCHNUM = phy_chann;


    /* set ACTIVE_IDLE */
    mdci_ctrl_pool[channel].state = MDCI_IDLE;

    RestoreIRQMask(mask);
    

    /* do transaction log */
    kal_mem_cpy(&(mdci_ctrl_pool[channel].buff), buff, sizeof(MDCI_BUFF_T));
    kal_mem_cpy(&(mdci_trans_log_pool[channel][mdci_trans_log_index[channel]].ct), &mdci_ctrl_pool[channel], sizeof(MDCI_CTRL_T));
    mdci_trans_log_index[channel]++;
    mdci_trans_log_index[channel]%=(DebugEntryNo);

    return MDCI_SUCCESS;
}

/*************************************************************************
* FUNCTION
*  ds_mdci_write_and_wait
*
* DESCRIPTION
*  This function writes data through either mailbox channel or stream
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
kal_int32 mdci_write_and_wait(MDCI_CHANNEL_T channel, MDCI_BUFF_T *buff, kal_uint32 ticks)
{
    kal_uint32 mdci_busy, phy_chann, saveaddr = 0;
    kal_int32 ret;
    MDCI_BUFF_T *chdata;
    volatile kal_uint32 reserved_value=0;


    

    /* query if used in init stage or exception */
    if (KAL_TRUE != kal_query_systemInit() && KAL_TRUE != INT_QueryExceptionStatus())
    {
    	return MDCI_API_INVALID;
    }
    
       
    
    /* check parameters */
    if (channel >= MDCI_MAX_CHANNEL)
        return MDCI_INVALID_PARAM;
    if (buff == NULL)
        return MDCI_INVALID_PARAM;


    *MDIF_ACK = 0xFFFFFFFF;



    /* check state */
    ret = MDCI_NOT_RECEIVE;
    buff->reserved = MDCI_EXCEPTION_CHECK_ID;

    /* get one physical channel */
    
    mdci_busy = *MDIF_BUSY;
    if (0xFF == mdci_busy)
    {
    	  return MDCI_NO_PHY_CHANNEL;
    }
    
    
    for (phy_chann = mdci_writeindx_for_FC ; phy_chann < (mdci_writeindx_for_FC + MDIF_MAX_PHY); phy_chann++) 
    {
	    phy_chann %= MDIF_MAX_PHY;
        chdata = (MDCI_BUFF_T *)MDIF_TXCHDATA + phy_chann;
        
        reserved_value = *(volatile kal_uint32*)(&(chdata->reserved));
        if (reserved_value == MDCI_EXCEPTION_CHECK_ID) 
        {
        		return MDCI_NO_PHY_CHANNEL;        		
        } 
        else 
        {
            /* set BUSY bit */
            *MDIF_BUSY |= (1 << phy_chann);
	        mdci_writeindx_for_FC = (phy_chann + 1)%MDIF_MAX_PHY;
            break;
        }
    }    
    
    /* set logical channel number */
    buff->channel = channel;


    /* copy channel buffer */
    chdata = (MDCI_BUFF_T *)MDIF_TXCHDATA + phy_chann;
    kal_mem_cpy(chdata, buff, sizeof(MDCI_BUFF_T));
    
    /* restore the stream buffer address */
    if (!MDCI_IS_MAILBOX(buff)) {
        MDCI_STREAM_ADDR(buff) = saveaddr;
    }

    /* start MDIF */
    *MDIF_TCHNUM = phy_chann;
    
    while (ticks > 0)
    {
        reserved_value = *(volatile kal_uint32*)(&(chdata->reserved));
        if (reserved_value != MDCI_EXCEPTION_CHECK_ID)
        {
        	ret = MDCI_SUCCESS;
        	break;	
        }
        
        ust_busy_wait(1);
    	ticks--;	
    }


    return ret;
}

/*************************************************************************
* FUNCTION
*  mdci_read
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
*  MDIF error code.
*
*************************************************************************/
kal_int32 mdci_read(MDCI_CHANNEL_T channel, MDCI_BUFF_T *buff)
{
    kal_uint32 owner, mask, ret, event;
    kal_char event_name[20];


#ifdef __IVP__
    dbg_print("Error.... can not use mdci_read in IVP\n\r");
    while(1);
#endif

    /* check if a LISR is running */
    if (kal_if_lisr())
        return MDCI_IN_LISR;

    /* check parameters */
    if (channel >= MDCI_MAX_CHANNEL)
        return MDCI_INVALID_PARAM;
    if (buff == NULL)
        return MDCI_INVALID_PARAM;

    /* get the current task */
    owner = (kal_uint32)kal_get_current_thread_ID();

    /* check owner */
    if (mdci_ctrl_pool[channel].owner != owner && mdci_is_chanel_need_check_owner(channel)) {
        return MDCI_NOT_OWNER;
    }

    /* create an event for the first use */ 
    if (mdci_ctrl_pool[channel].event == NULL) {
        sprintf(event_name, "MDIF%d event", channel);
        mdci_ctrl_pool[channel].event = kal_create_event_group(event_name);
        if (mdci_ctrl_pool[channel].event == NULL)
            ASSERT(0);
    }

    /* check state */
    ret = MDCI_SUCCESS;
    mask = SaveAndSetIRQMask();
    if (mdci_ctrl_pool[channel].state != MDCI_IDLE) {
        ret = MDCI_IN_USE;
    } else {
        /* set ACTIVE_WRITE */
        mdci_ctrl_pool[channel].state = MDCI_ACTIVE_READ;
    }
    RestoreIRQMask(mask);
    if (ret != MDCI_SUCCESS)
        return ret;

#ifndef __IVP__
    /* wait for the event */
    kal_retrieve_eg_events(mdci_ctrl_pool[channel].event, 1, KAL_OR_CONSUME, &event, KAL_SUSPEND);
#endif    
    if (event != 1) {
        ASSERT(0);
    }

    /* read channel buffer */
    memcpy(buff, &(mdci_ctrl_pool[channel].buff), sizeof(MDCI_BUFF_T));

    /* set ACTIVE_IDLE */
    mdci_ctrl_pool[channel].state = MDCI_IDLE;

    return MDCI_SUCCESS;
}

/*************************************************************************
* FUNCTION
*  mdci_read_and_wait
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
kal_uint32 mdci_read_and_wait(MDCI_CHANNEL_T channel, MDCI_BUFF_T *buff, kal_uint32 ticks)
{
    MDCI_RETURNVAL_T ret;
    MDCI_BUFF_T *chdata;
    kal_uint32 index, cur_phych;
    volatile kal_uint32 reserved_value=0;
    volatile kal_uint32 chk_channel=0;
    

    /* query if used in init stage or exception */
    if (KAL_TRUE != kal_query_systemInit() && KAL_TRUE != INT_QueryExceptionStatus())
    {
    	return MDCI_API_INVALID;
    }
    

    /* check parameters */
    if (channel >= MDCI_MAX_CHANNEL)
        return MDCI_INVALID_PARAM;
    if (buff == NULL)
        return MDCI_INVALID_PARAM;


    /* check state */
    ret = MDCI_NOT_RECEIVE;
      
    
        
    while (ticks > 0)
    {
	    for (index = mdci_readindx_for_MD; index < mdci_readindx_for_MD + MDIF_MAX_PHY; index++)
    	{
		
       	    cur_phych = index % MDIF_MAX_PHY;
    		chdata = (MDCI_BUFF_T *)MDIF_RXCHDATA + cur_phych;
    		reserved_value = *(volatile kal_uint32 *)(&(chdata->reserved));
    		chk_channel = *(volatile kal_uint32 *)(&(chdata->channel));
        	if (reserved_value == MDCI_EXCEPTION_CHECK_ID && chk_channel == channel)
        	{
        		kal_mem_cpy(buff, chdata, sizeof(MDCI_BUFF_T));
			    mdci_readindx_for_MD = cur_phych;
			    *(volatile kal_uint32*)(&(chdata->reserved)) = 0;
			    return MDCI_SUCCESS;
        	}
    	}

        ust_busy_wait(1);
       	ticks--;	
    }

    
    
    return ret;
}

/*************************************************************************
* FUNCTION
*  mdci_mailbox_write
*
* DESCRIPTION
*  This function writes data through a mailbox channel.
*
* PARAMETERS
*  channel    -    logical channel
*  id         -    mailbox id
*
* RETURNS
*  MDIF error code.
*
*************************************************************************/
kal_int32 mdci_mailbox_write(MDCI_CHANNEL_T channel, kal_uint32 id)
{
    MDCI_BUFF_T buff;


    /* initialize a MDIF channel buffer */
    kal_mem_set(&buff, 0, sizeof(MDCI_BUFF_T));
    MDCI_INIT_MAILBOX(&buff, id);

    /* write */
    return mdci_write(channel, &buff);
}

/*************************************************************************
* FUNCTION
*  ds_mdci_mailbox_write_and_wait
*
* DESCRIPTION
*  This function writes data through a mailbox channel.
*
* PARAMETERS
*  channel    -    logical channel
*  id         -    mailbox id
*  ticks      -    max ticks to wait
*
* RETURNS
*  MDIF error code.
*
*************************************************************************/
kal_int32 mdci_mailbox_write_and_wait(MDCI_CHANNEL_T channel, kal_uint32 id, kal_uint32 ticks)
{
    MDCI_BUFF_T buff;


    /* initialize a MDIF channel buffer */
    kal_mem_set(&buff, 0, sizeof(MDCI_BUFF_T));
    MDCI_INIT_MAILBOX(&buff, id);

    /* write */
    return mdci_write_and_wait(channel, &buff, ticks);
}

/*************************************************************************
* FUNCTION
*  mdci_mailbox_read
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
kal_int32 mdci_mailbox_read(MDCI_CHANNEL_T channel)
{
    MDCI_BUFF_T buff;
    kal_uint32 ret;


    /* read */
    ret = mdci_read(channel, &buff);

    if (ret == MDCI_SUCCESS) {
        /* return mailbox id for success read */
        return MDCI_MAILBOX_ID(&buff);
    } else {
        /* return error code for fail read */
        return ret;
    }
}

/*************************************************************************
* FUNCTION
*  mdci_mailbox_read_and_wait
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
kal_int32 mdci_mailbox_read_and_wait(MDCI_CHANNEL_T channel, kal_uint32 ticks)
{
    MDCI_BUFF_T buff;
    kal_uint32 ret;


    /* read */
    ret = mdci_read_and_wait(channel, &buff,ticks);

    if (ret == MDCI_SUCCESS) {
        /* return mailbox id for success read */
        return MDCI_MAILBOX_ID(&buff);
    } else {
        /* return error code for fail read */
        return ret;
    }
}

/*************************************************************************
* FUNCTION
*  mdci_mailbox_write_with_reserved
*
* DESCRIPTION
*  This function writes data through a mailbox channel.
*
* PARAMETERS
*  channel    -    logical channel
*  id         -    mailbox id
*
* RETURNS
*  MDIF error code.
*
*************************************************************************/
kal_int32 mdci_mailbox_write_with_reserved(MDCI_CHANNEL_T channel, kal_uint32 id,kal_uint32 reserved)
{
    MDCI_BUFF_T buff;


    /* initialize a MDIF channel buffer */
    kal_mem_set(&buff, 0, sizeof(MDCI_BUFF_T));
    MDCI_INIT_MAILBOX(&buff, id);
    
    buff.reserved = reserved;
    /* write */
    return mdci_write(channel, &buff);
}


/*************************************************************************
* FUNCTION
*  mdci_mailbox_read_with_reserved
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
kal_int32 mdci_mailbox_read_with_reserved(MDCI_CHANNEL_T channel,kal_uint32 *reserved)
{
    MDCI_BUFF_T buff;
    kal_uint32 ret;


    /* read */
    ret = mdci_read(channel, &buff);
    *reserved = buff.reserved;
    
    if (ret == MDCI_SUCCESS) {
        /* return mailbox id for success read */
        return MDCI_MAILBOX_ID(&buff);
    } else {
        /* return error code for fail read */
        return ret;
    }
}



/*************************************************************************
* FUNCTION
*  mdci_stream_write_with_reserved
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
*  MDIF error code.
*
*************************************************************************/
kal_int32 mdci_stream_write_with_reserved(MDCI_CHANNEL_T channel, kal_uint32 addr, kal_uint32 len,kal_uint32 reserved)
{
    MDCI_BUFF_T buff;


    /* initialize a MDIF channel buffer */
    kal_mem_set(&buff, 0, sizeof(MDCI_BUFF_T));
    MDCI_INIT_STREAM(&buff, addr, len);

    buff.reserved = reserved; /* KC add for FS_MDIF */
    /* write */
    return mdci_write(channel, &buff);
}


/*************************************************************************
* FUNCTION
*  mdci_stream_read_with_reserved
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
kal_int32 mdci_stream_read_with_reserved(MDCI_CHANNEL_T channel, kal_uint32 *addr, kal_uint32 *len, kal_uint32 *reserved)
{
    MDCI_BUFF_T buff;
    kal_uint32 ret;


    /* read */
    ret = mdci_read(channel, &buff);

    if (ret == MDCI_SUCCESS) {
        /* get the start address and length of the buffer */
        *addr = MDCI_STREAM_ADDR(&buff);
        *len = MDCI_STREAM_LEN(&buff);
	 *reserved = buff.reserved; /* KC add for flexible */
    }

    return ret;
}


/*************************************************************************
* FUNCTION
*  mdci_stream_write
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
*  MDIF error code.
*
*************************************************************************/
kal_int32 mdci_stream_write(MDCI_CHANNEL_T channel, kal_uint32 addr, kal_uint32 len)
{
    MDCI_BUFF_T buff;


    /* initialize a MDIF channel buffer */
    kal_mem_set(&buff, 0, sizeof(MDCI_BUFF_T));
    MDCI_INIT_STREAM(&buff, addr, len);

    /* write */
    return mdci_write(channel, &buff);
}

/*************************************************************************
* FUNCTION
*  ds_mdci_stream_write_and_wait
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
*  MDIF error code.
*
*************************************************************************/
kal_int32 mdci_stream_write_and_wait(MDCI_CHANNEL_T channel, kal_uint32 addr, kal_uint32 len, kal_uint32 ticks)
{
    MDCI_BUFF_T buff;


    /* initialize a MDIF channel buffer */
    kal_mem_set(&buff, 0, sizeof(MDCI_BUFF_T));
    MDCI_INIT_STREAM(&buff, addr, len);

    /* write */
    return mdci_write_and_wait(channel, &buff,ticks);
}

/*************************************************************************
* FUNCTION
*  mdci_stream_read
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
kal_int32 mdci_stream_read(MDCI_CHANNEL_T channel, kal_uint32 *addr, kal_uint32 *len)
{
    MDCI_BUFF_T buff;
    kal_uint32 ret;


    /* read */
    ret = mdci_read(channel, &buff);

    if (ret == MDCI_SUCCESS) {
        /* get the start address and length of the buffer */
        *addr = MDCI_STREAM_ADDR(&buff);
        *len = MDCI_STREAM_LEN(&buff);
    }

    return ret;
}

/*************************************************************************
* FUNCTION
*  ds_mdci_stream_read_and_wait
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
kal_int32 mdci_stream_read_and_wait(MDCI_CHANNEL_T channel, kal_uint32 *addr, kal_uint32 *len, kal_uint32 ticks)
{
    MDCI_BUFF_T buff;
    kal_uint32 ret;


    /* read */
    ret = mdci_read_and_wait(channel, &buff,ticks);

    if (ret == MDCI_SUCCESS) {
        /* get the start address and length of the buffer */
        *addr = MDCI_STREAM_ADDR(&buff);
        *len = MDCI_STREAM_LEN(&buff);
    }

    return ret;
}

/*************************************************************************
* FUNCTION
*  Check_If_Log_In_Phy
*
* DESCRIPTION
*  This function will read the buffer and check if one logical is exist in physical buffer
*
* PARAMETERS
*  query_log    -    			logical channel
*  Is_Ack_All_if_found -		pointer to the start address of the buffer to read
*   
* RETURNS
*  KAL_TRUE if the query logical is in physical, KAL_FALSE if such logical channel is not in.
*
*************************************************************************/
kal_bool mdci_Check_If_Log_In_Phy(kal_uint32 query_log, kal_bool Is_Ack_All_if_found)
{
	kal_uint32 arb = 1, phy_chann, i, log_channel;
	MDCI_BUFF_T *buff;

	phy_chann = *MDIF_RCHNUM;
	
	for(i=0;i<MDIF_MAX_PHY;i++)
	{
	     	if (arb == 0) {
            		buff = (MDCI_BUFF_T *)MDIF_RXCHDATA + phy_chann;
            		log_channel = buff->channel;
            		//i = phy_chann;
        	} else if (phy_chann & (1 << i)) {
            		buff = (MDCI_BUFF_T *)MDIF_RXCHDATA + i;
            		log_channel = buff->channel;
        	} else {
            		continue;
        	}

		if ( query_log == log_channel) {

			if ( KAL_TRUE == Is_Ack_All_if_found) *MDIF_ACK = 0xFFFFFFFF;

			return KAL_TRUE;
		}
	}

	return KAL_FALSE;
		
}


/*************************************************************************
* FUNCTION
*  mdci_query_sharemem_addr
*
* DESCRIPTION
*  This function reads data through a stream channel.
*
* PARAMETERS
*  channel    -    			logical channel
*  *   
* RETURNS
*  The address of the share memory of the input logical channel
*
*************************************************************************/
kal_uint32 mdci_query_sharemem_addr(MDCI_CHANNEL_T channel,kal_uint32 *size)
{
    return 0;
}

/*************************************************************************
* FUNCTION
*  void mdci_change_owner_only
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
void mdci_change_owner_only(MDCI_CHANNEL_T channel,kal_uint8 owner)
{

#ifndef __IVP__	
	mdci_ctrl_pool[channel].owner = (kal_uint32)(kal_get_task_by_moduleID(owner));
	//(kal_uint32)(task_info_g[mod_task_g[owner]].task_id);
#endif /* __IVP__ */

	
}

/*************************************************************************
* FUNCTION
*  void mdci_boot_ack
*
* DESCRIPTION
*  This function .
*
* PARAMETERS
*  channel    -    			logical channel
*  *   
* RETURNS
*  The address of the share memory of the input logical channel
*
*************************************************************************/
void mdci_control_m2d_cb(MDCI_BUFF_T *bufp)
{
       // we should not receive the msg from m2d channel
	ASSERT(0);
	return;
}

void mdci_control_d2m_cb(MDCI_BUFF_T *bufp)
{
      
      if (MDCI_MAILBOX_ID(bufp) == MDCIMSG_ID_NORMAL_BOOT_READY)
      {
	  g_dsp_boot_success = KAL_TRUE;

	}
	return;
}



/*************************************************************************
* FUNCTION
*  void mdci_init_handshake_phase1
*
* DESCRIPTION
*  This function .
*
* PARAMETERS
*  channel    -    			logical channel
*  *   
* RETURNS
*  The address of the share memory of the input logical channel
*
*************************************************************************/
#if defined(__DSP_BOOT_SEC__)
extern kal_bool sync_status;
#endif  /* __DSP_BOOT_SEC__ */
kal_uint32 fill_status = 1;
void mdci_init_handshake_phase1(void) 
{

#if defined(__DSP_BOOT_SEC__) && !defined(_NAND_FLASH_BOOTING_)
    sync_status = dmdsp_sync_done();
#endif  /* __DSP_BOOT_SEC__ && !_NAND_FLASH_BOOTING_ */
    
    /* Retrieve debug flag */
    if (MDUD_SYNC_VALUE == *(volatile unsigned long *)g_mcud_chkaddr)
    {
        md_dsp_share_data.Is_MCU_Debug = 1;
        *(volatile unsigned long *)g_mcud_chkaddr = 0;
    }
    else
    {
        md_dsp_share_data.Is_MCU_Debug = 0;
    }


	*MDIF_ACK = 0xFFFFFFFF;
    /* set all share memory to zero*/
    kal_mem_set((void *)MDMDIF_INITDATA,0x0, 256-MDMDIF_SRAM_INITDATA_OFFSET);
    /* copy related information */
    kal_mem_cpy(&(md_dsp_share_data.Prefix),"MDIF",4);
    kal_mem_cpy(&(md_dsp_share_data.Platform),"MT6276E0",8);
    kal_mem_cpy(&(md_dsp_share_data.Postfix),"MDIF",4);
    md_dsp_share_data.DriverVersion = 0;
    md_dsp_share_data.WakeUpEINT = 0;
    md_dsp_share_data.MailboxPortNum = 5;
    md_dsp_share_data.BootChannel = MDCI_CONTROL_CHANNEL_D2M;
    md_dsp_share_data.BootReadyID = MDCIMSG_ID_NORMAL_BOOT_READY;
    #if defined(__MODEM_CCCI_EXIST__)
    md_dsp_share_data.MdlogShareMemBase = ap_md_share_data.MdlogShareMemBase;
    md_dsp_share_data.MdlogShareMemSize = ap_md_share_data.MdlogShareMemSize;
    #else
    md_dsp_share_data.MdlogShareMemBase = 0;
    md_dsp_share_data.MdlogShareMemSize = 0;
    #endif
    md_dsp_share_data.Reserved3 = 0;

    fill_status = mdci_fill_DSPShareMemInfo(&(md_dsp_share_data.ShareMemInfo));
    kal_mem_cpy((void *)MDMDIF_INITDATA,(void *)&md_dsp_share_data,sizeof(DSP_RUNTIME_DATA));

}
	

/*************************************************************************
* FUNCTION
*  void mdci_init_handshake_phase2
*
* DESCRIPTION
*  This function .
*
* PARAMETERS
*  channel    -    			logical channel
*  *   
* RETURNS
*  The address of the share memory of the input logical channel
*
*************************************************************************/
void mdci_init_handshake_phase2(kal_uint16 _boot_mode) 
{	   
    mdci_init(MDCI_CONTROL_CHANNEL_M2D,mdci_control_m2d_cb);
    mdci_init(MDCI_CONTROL_CHANNEL_D2M,mdci_control_d2m_cb);
}



/*************************************************************************
* FUNCTION
*  kal_uint32 mdci_fill_DSPShareMemInfo
*
* DESCRIPTION
*  This function fill the DSPShareMemInfo into md_dsp_share_data.ShareMemInfo
*
* PARAMETERS
*  DSP_SHARE_MEM_INFO* output_p : pointer of md_dsp_share_data.ShareMemInfo
*
* RETURNS                             
*  N/A
*
*************************************************************************/
kal_uint32 mdci_fill_DSPShareMemInfo(DSP_SHARE_MEM_INFO* output_p) 
{
    kal_uint32 regCount = 0;
    EXTSRAM_REGION_INFO_T *regionp;

    custom_mk_mcu_dsp_sharemem_info();
    custom_query_mcu_cacheable_dsp_cacheable_region(&regionp);
    while (regionp->addr != 0 || regionp->len != 0) {
       if (regionp->len == 0) {
          regionp++;
          continue;
       }
       output_p->addr[regCount] = regionp->addr;
       output_p->len[regCount] = regionp->len;
       output_p->attribute[regCount] = DSP_SHARE_REG_CACHEABLE;
       regCount ++; 
       regionp++;
       EXT_ASSERT(regCount <= DSP_MAX_SHARE_REG_COUNT, regCount, 0, 0);
    }
    custom_query_mcu_noncacheable_dsp_cacheable_region(&regionp);
    while (regionp->addr != 0 || regionp->len != 0) {
       if (regionp->len == 0) {
          regionp++;
          continue;
       }
       output_p->addr[regCount] = regionp->addr;
       output_p->len[regCount] = regionp->len;
       output_p->attribute[regCount] = DSP_SHARE_REG_CACHEABLE;
       regCount ++; 
       regionp++;
       EXT_ASSERT(regCount <= DSP_MAX_SHARE_REG_COUNT, regCount, 0, 0);
    }
    custom_query_mcu_cacheable_dsp_noncacheable_region(&regionp);
    while (regionp->addr != 0 || regionp->len != 0) {
       if (regionp->len == 0) {
          regionp++;
          continue;
       }
       output_p->addr[regCount] = regionp->addr;
       output_p->len[regCount] = regionp->len;
       output_p->attribute[regCount] = DSP_SHARE_REG_NONCACHEABLE;
       regCount ++;
       regionp++; 
       EXT_ASSERT(regCount <= DSP_MAX_SHARE_REG_COUNT, regCount, 0, 0);
    }
    custom_query_mcu_noncacheable_dsp_noncacheable_region(&regionp);
    while (regionp->addr != 0 || regionp->len != 0) {
       if (regionp->len == 0) {
          regionp++;
          continue;
       }
       output_p->addr[regCount] = regionp->addr;
       output_p->len[regCount] = regionp->len;
       output_p->attribute[regCount] = DSP_SHARE_REG_NONCACHEABLE;
       regCount ++; 
       regionp++;
       EXT_ASSERT(regCount <= DSP_MAX_SHARE_REG_COUNT, regCount, 0, 0);
    }
    output_p->reg_count = regCount;
    return 0;
}

#endif /* __DSP_FCORE4__ */
