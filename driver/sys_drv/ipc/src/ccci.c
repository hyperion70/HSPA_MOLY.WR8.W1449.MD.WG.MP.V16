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
 *
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

#include "tst_trace.h"
#include "kal_trace.h"

#include "reg_base.h"
#include "config_hw.h"
#include "intrCtrl.h"
#include "drv_comm.h"
#include "drv_hisr.h"
#include "in_defs.h"
#include "init.h"
#include "eint.h"
#include "cache_sw.h"

#include "ps_public_l4_msgid.h"

#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__)
#include "mmu_int.h"
#include "mmu.h"
#endif

#if defined(__CR4__)
#include "mpu.h"
#endif

#define __CCCI_DEBUG_APHANG_ERROR___
//-#define __CCCI_DEBUG_ATCMD_ERROR___

#if !defined(__MODEM_CCCI_EXIST__) && !defined(IC_MODULE_TEST)
//- implement as null function
void ccci_hal_init(void)
{
    ;
}
void ccci_init_handshake_phase1(void)
{
    ;
}
void ccci_init_handshake_phase2(kal_uint16 _boot_mode)
{
    _boot_mode = _boot_mode;
}
#endif


#if defined(__MODEM_CCCI_EXIST__)
#include "ccci.h"
#include "ipc_msgsvc.h"
#include "ccci_uart_drv.h"
#include "ipc_rpc.h"
#include "fs_ccci.h"
#include "us_timer.h"
#include "ex_item.h"
#include "ex_public.h"
#include "custom_scatstruct.h"

#include "ccci_int.h"
#include "ccif.h"
/*******************************************************************************
 * Define import global variables.
 *******************************************************************************/
extern CCCI_UARTP_BUFF_T ccci_uartp_buff[MAX_CCCI_UART_PORT];
extern Ipcsvc_Share_ST *ipcsvc_share_rx_g;
extern Ipcsvc_Share_ST *ipcsvc_share_tx_g;
extern void FS_CCCI_Callback(CCCI_BUFF_T *buff);

/*******************************************************************************
 * Define import function prototype.
 *******************************************************************************/

extern kal_bool kal_query_systemInit(void);
extern kal_bool INT_QueryExceptionStatus(void);
extern void tst_sys_trace(kal_char *);
extern kal_uint32 kal_get_systicks(void);
#ifdef __SP_BOOTTRC_ENABLE__
extern void INC_TRC(kal_uint32 trace_log1, kal_uint32 trace_log2);
#endif
/*******************************************************************************
 * Define export function prototype.
 *******************************************************************************/

#ifdef __CCCI_DEBUG_APHANG_ERROR___
void ccci_exception_error_handler_aphang(void);
#endif

/*******************************************************************************
 * Define global variables.
 *******************************************************************************/
#define CCCI_AP_MD_SHARE_DATA_SIZE_2MB	0x00200000
#define CCCI_AP_MD_SHARE_DATA_SIZE_32MB 0x02000000

#if defined(CCCI_RPCSRV_SUPPORT_SECURE)
#define CCCI_AP_MD_RPC_SECURE_SHARE_DATA_SIZE_512K	0x80000
#endif

#define DebugEntryNo 8 /* defined the log no for each channel */
typedef struct
{
    kal_uint32   tick;
    CCCI_CTRL_T  ct;
} CCCI_TRANS_LOG;

__attribute__  ((zero_init))	kal_uint32     ccci_trans_log_index[CCCI_MAX_CHANNEL] = {};
__attribute__  ((zero_init))	kal_uint32     ccci_need_check_owner_mask[2] = {};
__attribute__  ((zero_init))	CCCI_TRANS_LOG ccci_trans_log_pool[CCCI_MAX_CHANNEL][DebugEntryNo]= {};
__attribute__  ((zero_init))	CCCI_BUFF_T ccif_last_rx_snapshot[CCIF_MAX_PHY]= {};
__attribute__  ((zero_init))	CCCI_BUFF_T ccif_last_tx_snapshot[CCIF_MAX_PHY]= {};
volatile 	kal_uint32  ccif_last_con;
volatile 	kal_uint32  ccif_last_rx_channel;
volatile 	kal_uint32  ccif_last_tx_channel;

#define ilm_DebugEntryNo 16
typedef struct
{
    kal_uint32   in_tick;
    kal_uint32   out_tick;
} CCCI_HISR_LOG;

typedef struct
{
    kal_uint32   in_tick;
    kal_uint32   out_tick;
    module_type _src_mod_id;
    module_type _dest_mod_id;
    msg_type    _msg_id;
    local_para_struct *_local_para_ptr;
} CCCI_ILM_SENT_LOG;

__attribute__  ((zero_init))	kal_uint32     ccci_hisr_log_index;
__attribute__  ((zero_init))	CCCI_HISR_LOG  ccci_hisr_log_pool[ilm_DebugEntryNo]= {};

__attribute__  ((zero_init))	kal_uint32         ccci_ilm_log_index;
__attribute__  ((zero_init))	CCCI_ILM_SENT_LOG  ccci_ilm_log_pool[ilm_DebugEntryNo]= {};

static CCCI_SYSMSGSVC_HISR_CALLBACK	ccci_sysmsgsvc_cb[CCMSG_ID_SYSMSGSVC_END - CCMSG_ID_SYSMSGSVC_START];
#undef	X_CCCI_SYSMSGSVC_CONF
#define	X_CCCI_SYSMSGSVC_CONF(mSGNO, mODE, iD)	{mODE, iD},
static kal_uint32					ccci_sysmsgsvc_msg[CCMSG_ID_SYSMSGSVC_END - CCMSG_ID_SYSMSGSVC_START][2] = {
																													#include "ccci_sysmsgsvc_conf.h"
																												};
#undef	X_CCCI_SYSMSGSVC_CONF

CCCI_CTRL_T ccci_ctrl_pool[CCCI_MAX_CHANNEL];
kal_uint8	ccif_readindx_for_MD=0;
kal_uint8	ccif_writeindx_for_AP=0;
volatile 	kal_uint32 ccci_exception_check_write_result = 0;
volatile 	kal_uint32 ccci_exception_info_write_result = 0;
volatile 	kal_uint32 ccci_tick_update_write_result = 0;
volatile 	kal_bool  ccci_exception_handshake_done = KAL_FALSE;
volatile 	kal_bool  ccci_debug_phychan_full = 0;
kal_bool  ccci_ap_md_share_data_mismatch = 0;

#if defined(CCCI_INIT_HANDSHAKE_MODE1)
MODEM_RUNTIME_INFO		ap_md_share_info;
MODEM_EXCEPTION_EXT		*ap_md_exception_ext;
#endif

#if defined(CCCI_RPCSRV_SUPPORT_SECURE)
volatile    kal_uint8 ccci_secure_runtimedata_checkpass = 0;
#endif

MODEM_RUNTIME_DATA ap_md_share_data;
kal_uint32 ccci_is_ap_wakeup;
kal_uint32 ccif_last_tx_busy_channel_mask;

//- This array is used to log the trnas log index of CCIF packet in share memory.
//- Goal: find the trans log index of correspondig CCIF pakcet in share memory fast.
kal_uint32 ccif_trans_log_index_mapping[CCIF_MAX_PHY];

//- Used to log CCIF mask duration.
volatile kal_uint32 ccci_mask_time_start;

#ifdef __SP_BOOTTRC_ENABLE__
//- Data required by SP bootup trace.
kal_uint32 ccci_boottrc_buffer_addr, ccci_boottrc_buffer_size, ccci_boottrc_buffer_ptr;
const kal_uint32 g_CCIF_BOOTTRC_ADDR = MDCCIF_BOOTTRC_DATA;
#endif

//- used to log CCIF_CON value specified by user;
kal_uint32 ccif_con_value = 0;

//- Addr/Size for EXCEP Log
kal_uint32 ccci_excep_dbg_log_base;
kal_uint32 ccci_excep_dbg_log_size;
kal_uint32 ccci_excep_dbg_log_base_hs2;
kal_uint32 ccci_excep_dbg_log_size_hs2;

/**************************************************************************
* FUNCTION
*  ccci_boottrc_init_log
*
* DESCRIPTION
*  API to write bootup trace to CCIF in CCCI module.
*
* PARAMETERS
*  index - key for bootup trace.
*  info  - infomation for corresponding index.
*
* RETURNS
*  none
*
**************************************************************************/

static void ccci_boottrc_init_log(kal_uint32 index, kal_uint32 info)
{
#ifdef __SP_BOOTTRC_ENABLE__
    INC_TRC(index, info);
#else
    index = index;
    info = info;
#endif
}

/*************************************************************************
* FUNCTION
*  ccci_need_check_owner_mask_init
*
* DESCRIPTION
*  init ccci_need_check_owner_maskx
*
* PARAMETERS
*  none
*
* RETURNS
*  none
*
*************************************************************************/
static void ccci_need_check_owner_mask_init(void)
{
    kal_uint32	channel, i, j;

    for (channel=0, i=0; channel<CCCI_MAX_CHANNEL; channel++, i++)
    {
        j = channel >> 5;
        i &= 0x1F;

        //- no need to check list
        if (CCCI_SYSTEM_CHANNEL == channel)
        {
            continue;
        }
        else if (CCCI_TST_CHANNEL <= channel && CCCI_PMIC_ACK_CHANNEL >= channel)
        {
            continue;
        }
        else if (CCCI_IPC_RPC_CHANNEL <= channel &&  CCCI_MSGSVC_RCV_ACK_CHANNEL >= channel)
        {
            continue;
        }
        if ((CCCI_CCMNI1_RX == channel) || (CCCI_CCMNI2_RX == channel) || (CCCI_CCMNI3_RX == channel))
        {
            continue;
        }
        else
        {
            //- else need to check owner
            ccci_need_check_owner_mask[j] |= (1 << i);
        }
    }
}

/*************************************************************************
* FUNCTION
*  ccci_is_chanel_need_check_owner
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
static kal_bool ccci_is_chanel_need_check_owner(kal_uint32 channel)
{
    kal_uint32	j = channel >> 5;
    kal_uint32	i = channel & 0x1F;

    if(INT_QueryExceptionStatus() == KAL_TRUE  || kal_query_systemInit() == KAL_TRUE)
    {
        return	KAL_FALSE;
    }

    if (ccci_need_check_owner_mask[j] & (1 << i))
    {
        return	KAL_TRUE;
    }

    return	KAL_FALSE;
}

/*************************************************************************
* FUNCTION
*  ccif_hisr
*
* DESCRIPTION
*  This function processes CCIF HISR.
*
* PARAMETERS
*  none
*
* RETURNS
*  none
*
*************************************************************************/
void ccif_hisr()
{
    kal_uint32 channel, arb;
    kal_uint32 unmask_time, duration;

    if (*CCIF_CON & CCIF_CON_ARB)
    {
        arb = 1;
    }
    else
    {
        arb = 0;
    }
    
    ccci_hisr_log_pool[ccci_hisr_log_index].in_tick = kal_get_systicks();

    /* get logical channel which has data to read */
    for (channel = 0; channel < CCCI_MAX_CHANNEL; channel++)
    {
        if (ccci_ctrl_pool[channel].state & CCCI_ACTIVE_ISR)
        {
            ccci_trans_log_pool[channel][ccci_trans_log_index[channel]].tick = kal_get_systicks();
            kal_mem_cpy(&(ccci_trans_log_pool[channel][ccci_trans_log_index[channel]].ct),&ccci_ctrl_pool[channel], sizeof(CCCI_CTRL_T));
            ccci_trans_log_index[channel]++;
            ccci_trans_log_index[channel]%=(DebugEntryNo);
            if (ccci_ctrl_pool[channel].state & CCCI_ACTIVE_READ)
            {
                /* a ccci_read() is waiting */
                /* set an event */
                kal_set_eg_events(ccci_ctrl_pool[channel].event, 1, KAL_OR);

                /* clear CCCI_ACTIVE_ISR (only keep CCCI_ACTIVE_READ) */
                ccci_ctrl_pool[channel].state = CCCI_ACTIVE_READ;
            }
            else
            {
                /* invoke callback function */
                if (ccci_ctrl_pool[channel].funp == NULL)
                {
                    EXT_ASSERT(0, channel, 0, 0);
                }
                else
                {
                    ccci_ctrl_pool[channel].funp(&(ccci_ctrl_pool[channel].buff));
                }
                /* set IDLE */
                ccci_ctrl_pool[channel].state = CCCI_IDLE;
            }

            /* only one channel at one time under sequential mode */
            if (arb == 0)
            {
                break;
            }
        }
    }

    if (arb == 0 && channel == CCCI_MAX_CHANNEL)
    {
        ASSERT(0);
    }
    
    CCIF_GET_CURRENT_TIME(unmask_time);
    CCIF_GET_TIME_DURATION(ccci_mask_time_start, unmask_time, duration);
    if ((duration > CCCI_RX_MAX_DELAY) && KAL_FALSE == kal_query_systemInit() && !L1_CHECK_ASSERT_BYPASS())
    {
        ASSERT(0);
    }
    ccci_mask_time_start = 0;
    
    ccci_hisr_log_pool[ccci_hisr_log_index].out_tick = kal_get_systicks();
    ccci_hisr_log_index++;
    ccci_hisr_log_index%=(ilm_DebugEntryNo);

    /* Unmask CCIF */
    IRQUnmask(IRQ_CCIF_CODE);

}

//- yy: should phase out by 2013/05/03
#if defined(__MTK_INTERNAL__) && defined(MT6572)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*************************************************************************
* FUNCTION
*  ccif_lisr
*
* DESCRIPTION
*  This function processes CCIF LISR.
*
* PARAMETERS
*  none
*
* RETURNS
*  none
*
*************************************************************************/
void ccif_lisr(void)
{
    kal_uint32 arb, phy_chann, i,i2, log_chann;
    CCCI_BUFF_T *buff;

    /* mask CCIF */
    IRQMask(IRQ_CCIF_CODE);

    //- Log time to check CCIF mask duration in ccif_hisr.
    if (ccci_mask_time_start == 0)    
    {
        CCIF_GET_CURRENT_TIME(ccci_mask_time_start);
    }

    /* set arbitration mode to original value because it may be reset */
    *CCIF_CON = ccif_con_value;
    /* read back CCIF_CON before reading CCIF_RCHNUM to guarantee write to CCIF_CON takes effect */
    *CCIF_CON;
    
    arb = ccif_con_value;

    /* get physical channel which needs to be read */
    phy_chann = *CCIF_RCHNUM;

    //for (i = 0; i < CCIF_MAX_PHY; i++) {
    for (i = ccif_readindx_for_MD; i < ccif_readindx_for_MD + CCIF_MAX_PHY; i++)
    {
        /* get logical channel one by one*/
        if (phy_chann == 0) break;
        i = i % CCIF_MAX_PHY;

        /* get logical channel number */
        if (arb == 0)
        {
            buff = (CCCI_BUFF_T *)CCIF_RXCHDATA + phy_chann;
            log_chann = buff->channel;
            i = phy_chann;
        }
        else if (phy_chann & (1 << i))
        {
            buff = (CCCI_BUFF_T *)CCIF_RXCHDATA + i;
            log_chann = buff->channel;
        }
        else
        {
            continue;
        }

        /* validate logical channel */
        if (log_chann == CCCI_FORCE_RESET_MODEM_CHANNEL)
        {
#define FORCE_RESET_MODEM   (0)
            EXT_ASSERT(FORCE_RESET_MODEM, log_chann, phy_chann, 0);
        }
        else if (log_chann >= CCCI_MAX_CHANNEL)
        {
            EXT_ASSERT(0, log_chann, phy_chann, 0);
        }


        /* check state */
        if (ccci_ctrl_pool[log_chann].state == CCCI_ACTIVE_READ)
        {
            /* use OR operation since a ccci_read() is waiting */
            ccci_ctrl_pool[log_chann].state |= CCCI_ACTIVE_ISR;
        }
        else if (ccci_ctrl_pool[log_chann].state == CCCI_IDLE)
        {
            ccci_ctrl_pool[log_chann].state = CCCI_ACTIVE_ISR;
        }
        else if (ccci_ctrl_pool[log_chann].state == CCCI_ACTIVE_WRITE)
        {
            /* a ccci_write() is not finished */
            EXT_ASSERT(0, phy_chann, log_chann, ccci_ctrl_pool[log_chann].state);
        }
        //- Avoid to code as (ccci_ctrl_pool[log_chann].state & (CCCI_ACTIVE_ISR | CCCI_ACTIVE_READ))
        else if ((ccci_ctrl_pool[log_chann].state == (CCCI_ACTIVE_ISR)) ||
                 ccci_ctrl_pool[log_chann].state == (CCCI_ACTIVE_ISR | CCCI_ACTIVE_READ))
        {
            /* a ccci_hisr() is not done yet */
            if (arb == 0)
            {
                /* not allow in sequential mode */
                EXT_ASSERT(0, phy_chann, log_chann, ccci_ctrl_pool[log_chann].state);
            }
            else
            {
                /* pend */
                break; // KC: change the continue to break due to ccif phy race condition problem.
                //continue;
            }
        }
        else
        {
            EXT_ASSERT(0, phy_chann, log_chann, ccci_ctrl_pool[log_chann].state);
        }



        /* copy channel buffer */
        for (i2=0 ; i2< 4; i2++)
        {
            *(((volatile unsigned long *)&(ccci_ctrl_pool[log_chann].buff)) + i2 )= *((volatile unsigned long *)buff +i2);
        }

        /* ack CCIF to release the physical channel */
        *CCIF_ACK = (1 << i);
        phy_chann &= ~(1<<i);



        /* only one channel at one time under sequential mode */
        if (arb == 0)
        {
            break;
        }
    }

    ccif_readindx_for_MD = i;

    /* activate HISR */
    if (KAL_TRUE == kal_query_systemInit())
    {
        ccif_hisr();
    }
    else
    {
        drv_active_hisr(DRV_CCIF_HISR_ID);
    }
    
//- yy: should phase out by 2013/05/03
#if defined(__MTK_INTERNAL__) && defined(MT6572)
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
}


/*************************************************************************
* FUNCTION
*  ccif_init
*
* DESCRIPTION
*  This function initialized CCIF.
*
* PARAMETERS
*  arb          -    arbitration mode flag
*  md_offset    -    modem side master offset address(in bytes).
*
* RETURNS
*  none
*
*************************************************************************/
void ccif_init(kal_uint32 arb)
{
    /* set arbitration mode */
    if (arb == 1)
    {
        *CCIF_CON |= CCIF_CON_ARB;
        ccif_con_value = CCIF_CON_ARB;
    }

    /* register LISR */
    IRQ_Register_LISR(IRQ_CCIF_CODE, ccif_lisr, "CCIF LISR");

    /* register HISR */
    DRV_Register_HISR(DRV_CCIF_HISR_ID, ccif_hisr);

    /* set IRQ sensitivity */
    IRQSensitivity(IRQ_CCIF_CODE, LEVEL_SENSITIVE);

    /* unmask CCIF */
    IRQUnmask(IRQ_CCIF_CODE);

    ipc_rpc_init();
}


/*************************************************************************
* FUNCTION
*  ccci_owner_init
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
*  CCCI error code.
*
*************************************************************************/
kal_int32 ccci_owner_init(kal_uint32 channel, kal_taskid task, CCCI_CALLBACK funp)
{
    kal_uint32 owner, mask;
    kal_int32 ret;

    /* error checking */
    if (channel >= CCCI_MAX_CHANNEL)
        return CCCI_INVALID_PARAM;
    if (funp == NULL)
        return CCCI_INVALID_PARAM;

    owner = (kal_uint32)task;
    
    /* do error-checking in normal flow */    
    if (INT_QueryExceptionStatus() == KAL_FALSE)
    {
        if (kal_if_lisr())
            return CCCI_IN_LISR;

        ret = CCCI_SUCCESS;

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
    }
    /* bypass error checking in exception handler */
    else
    {
        ccci_ctrl_pool[channel].owner = owner;
    }
    

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
kal_int32 ccci_init(kal_uint32 channel, CCCI_CALLBACK funp)
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
kal_int32 ccci_deinit(kal_uint32 channel)
{
    kal_uint32 owner, mask;
    kal_int32 ret;

    /* error checking */
    if (channel >= CCCI_MAX_CHANNEL)
        return CCCI_INVALID_PARAM;
    
    /* do error-checking in normal flow */
    if (INT_QueryExceptionStatus() == KAL_FALSE)
    {
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
            ccci_ctrl_pool[channel].funp = 0;
        }
        RestoreIRQMask(mask);

        return ret;
    }
    /* bypass error checking in exception handler */    
    else
    {
        /* free the channel */
        ccci_ctrl_pool[channel].owner = 0;
        ccci_ctrl_pool[channel].funp = 0;
        ccci_ctrl_pool[channel].state = CCCI_IDLE;
        
        return CCCI_SUCCESS;    
    }
}

/*************************************************************************
* FUNCTION
*  ccci_write
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
*  CCCI error code.
*
*************************************************************************/
__attribute__((section ("INTSRAM_ROCODE")))
kal_int32 ccci_write_internal(kal_uint32 channel, CCCI_BUFF_T *buff,kal_bool check_lisr)
{
    kal_uint32 owner, mask, ccif_busy, phy_chann;
    kal_int32 ret;
    kal_uint32 tmp_tick, log_index, tmp_index;
    CCCI_BUFF_T *chdata;

    /* check if a LISR is running */
    if (1 == check_lisr)
    {
        if (kal_if_lisr() && INT_QueryExceptionStatus() == KAL_FALSE)
            return CCCI_IN_LISR;
    }

    /* check parameters */
    if (channel >= CCCI_MAX_CHANNEL)
        return CCCI_INVALID_PARAM;
    if (buff == NULL)
        return CCCI_INVALID_PARAM;

    /* get the current task */
    owner = (kal_uint32)kal_get_current_thread_ID();

    /* check owner */
    if (ccci_ctrl_pool[channel].owner != owner && ccci_is_chanel_need_check_owner(channel) )
    {
        return CCCI_NOT_OWNER;
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
        ccci_ctrl_pool[channel].state = CCCI_ACTIVE_WRITE;

    }

    if (ret != CCCI_SUCCESS)
    {
        RestoreIRQMask(mask);
        return ret;
    }

    /* get one physical channel */
    ccif_busy = *CCIF_BUSY;
    phy_chann = ccif_writeindx_for_AP;
    if (ccif_busy & (1 << phy_chann))
    {
        //continue;
        ccci_ctrl_pool[channel].state = CCCI_IDLE;

        RestoreIRQMask(mask);
        return CCCI_NO_PHY_CHANNEL;

    }
    else
    {
        /* set BUSY bit */
        *CCIF_BUSY = (1 << phy_chann);
        ccif_writeindx_for_AP = (phy_chann + 1) % CCIF_MAX_PHY;
        
        ccif_last_tx_busy_channel_mask = ccif_busy | (1 << phy_chann);
    }

    /* set logical channel number */
    buff->channel = channel;

    /* do transaction log */
    log_index = ccci_trans_log_index[channel];
    tmp_index = (log_index + 1);
    
    /* store the physical channel to ccci_trans_log_index[channel] mapping */
    ccif_trans_log_index_mapping[phy_chann] = log_index;
    
    if (tmp_index == DebugEntryNo)	tmp_index = 0;
    ccci_trans_log_index[channel] = tmp_index;
    tmp_tick = kal_get_systicks();

    /* copy channel buffer */
    chdata = (CCCI_BUFF_T *)CCIF_TXCHDATA + phy_chann;
    *(volatile unsigned long *)chdata = *(volatile unsigned long *)buff;
    *((volatile unsigned long *)chdata+1) = *((volatile unsigned long *)buff+1);
    *((volatile unsigned long *)chdata+2) = *((volatile unsigned long *)buff+2);
    *((volatile unsigned long *)chdata+3) = *((volatile unsigned long *)buff+3);

    /* start CCIF */
    *CCIF_TCHNUM = phy_chann;

//- yy: should phase out by 2013/05/03
#if defined(__MTK_INTERNAL__) && defined(MT6572)
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

    /* set ACTIVE_IDLE */
    ccci_ctrl_pool[channel].state = CCCI_IDLE;
    RestoreIRQMask(mask);

    /* do transaction log */
    ccci_trans_log_pool[channel][log_index].tick = tmp_tick;
    kal_mem_cpy(&(ccci_ctrl_pool[channel].buff), buff, sizeof(CCCI_BUFF_T));
    kal_mem_cpy(&(ccci_trans_log_pool[channel][log_index].ct), &ccci_ctrl_pool[channel], sizeof(CCCI_CTRL_T));

    return CCCI_SUCCESS;
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
kal_int32 ccci_read(kal_uint32 channel, CCCI_BUFF_T *buff)
{
    kal_uint32 owner, mask, event;
    kal_char event_name[20];
    kal_int32 ret;


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
    if (ccci_is_chanel_need_check_owner(channel) && ccci_ctrl_pool[channel].owner != owner)
    {
        return CCCI_NOT_OWNER;
    }

    /* create an event for the first use */
    if (ccci_ctrl_pool[channel].event == NULL)
    {
        //sprintf(event_name, "CCCI%d event", channel);
        strcpy(event_name, "CCCI");
        kal_itoa(channel, event_name+strlen(event_name), 10);
        strcat(event_name, " event");

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
kal_int32 ccci_read_and_wait(kal_uint32 channel, CCCI_BUFF_T *buff, kal_uint32 ticks)
{
    CCCI_GLOBAL_ERROR_CODE ret;
    CCCI_BUFF_T *chdata;
    kal_uint32 index, cur_phych;
    volatile kal_uint32 reserved_value=0;
    volatile kal_uint32 chk_channel=0;

    /* query if used in init stage or exception */
    if (KAL_TRUE != INT_QueryExceptionStatus())
    {
        return CCCI_FAIL;
    }

    /* check parameters */
    if (channel >= CCCI_MAX_CHANNEL)
        return CCCI_INVALID_PARAM;
    if (buff == NULL)
        return CCCI_INVALID_PARAM;

    //Read the pending data
    if (ccci_ctrl_pool[channel].state != CCCI_IDLE)
    {
        kal_mem_cpy(buff, &(ccci_ctrl_pool[channel].buff), sizeof(CCCI_BUFF_T));
        ccci_ctrl_pool[channel].state = CCCI_IDLE;
        return CCCI_SUCCESS;
    }

    /* check state */
    ret = CCCI_NO_DATA;

    while (ticks > 0)
    {
        for (index = ccif_readindx_for_MD; index < ccif_readindx_for_MD + CCIF_MAX_PHY; index++)
        {
            cur_phych = index % CCIF_MAX_PHY;
            chdata = (CCCI_BUFF_T *)CCIF_RXCHDATA + cur_phych;
            reserved_value = *(volatile kal_uint32 *)(&(chdata->reserved));
            chk_channel = *(volatile kal_uint32 *)(&(chdata->channel));

#define CCCI_EXCEPTION_READ_SPECIAL_PATTER (0x2454)
            if (reserved_value != CCCI_EXCEPTION_READ_SPECIAL_PATTER && chk_channel == channel)
            //CCCI_EXCEPTION_CHECK_ID
            {
                //kal_mem_cpy(buff, chdata, sizeof(CCCI_BUFF_T));
                /* copy channel buffer */
                kal_uint32 i2;
                for (i2=0 ; i2< 4; i2++)
                {
                    *(((volatile unsigned long *)buff) + i2 )= *((volatile unsigned long *)chdata +i2);
                }
                ccif_readindx_for_MD = cur_phych;
                *(volatile kal_uint32*)(&(chdata->reserved)) = CCCI_EXCEPTION_READ_SPECIAL_PATTER;

                return CCCI_SUCCESS;
            }
        }

        ust_busy_wait(1);
        ticks--;
    }

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
kal_int32 ccci_mailbox_write(kal_uint32 channel, kal_uint32 id)
{
    CCCI_BUFF_T buff;

    /* initialize a CCCI channel buffer */
    //- kal_mem_set(&buff, 0, sizeof(CCCI_BUFF_T));
    CCCI_INIT_MAILBOX(&buff, id);

    /* write */
    return ccci_write(channel, &buff);
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
kal_int32 ccci_mailbox_read(kal_uint32 channel)
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
*  ccci_mailbox_write_with_reserved
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
kal_int32 ccci_mailbox_write_with_reserved(kal_uint32 channel, kal_uint32 id,kal_uint32 reserved)
{
    CCCI_BUFF_T buff;

    /* initialize a CCCI channel buffer */
    //- kal_mem_set(&buff, 0, sizeof(CCCI_BUFF_T));
    CCCI_INIT_MAILBOX_WITH_RESERVED(&buff, id, reserved);

    /* write */
    return ccci_write(channel, &buff);
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
kal_int32 ccci_mailbox_read_with_reserved(kal_uint32 channel,kal_uint32 *reserved)
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
*  ccci_stream_write_with_reserved
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
kal_int32 ccci_stream_write_with_reserved(kal_uint32 channel, kal_uint32 addr, kal_uint32 len,kal_uint32 reserved)
{
    CCCI_BUFF_T buff;

    /* initialize a CCCI channel buffer */
    //- kal_mem_set(&buff, 0, sizeof(CCCI_BUFF_T));
    CCCI_INIT_STREAM_WITH_RESERVED(&buff, addr, len, reserved);

    /* write */
    return ccci_write(channel, &buff);
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
kal_int32 ccci_stream_read_with_reserved(kal_uint32 channel, kal_uint32 *addr, kal_uint32 *len, kal_uint32 *reserved)
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
        *reserved = buff.reserved; /* KC add for flexible */
    }

    return ret;
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
kal_int32 ccci_stream_write(kal_uint32 channel, kal_uint32 addr, kal_uint32 len)
{
    CCCI_BUFF_T buff;

    /* initialize a CCCI channel buffer */
    //- kal_mem_set(&buff, 0, sizeof(CCCI_BUFF_T));
    CCCI_INIT_STREAM(&buff, addr, len);

    /* write */
    return ccci_write(channel, &buff);
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
kal_int32 ccci_stream_read(kal_uint32 channel, kal_uint32 *addr, kal_uint32 *len)
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
*  ccci_chk_sententry_not_receive
*
* DESCRIPTION
*  This function will read the buffer and check if one logical is exist in physical buffer
*
* PARAMETERS
*  query_log    -    			logical channel
*  data -		check if the data
*
* RETURNS
*  KAL_TRUE if the query logical is in physical, KAL_FALSE if such logical channel is not in.
*
*************************************************************************/
kal_bool ccci_chk_sententry_not_receive(kal_uint32 query_log, kal_uint32 data)
{
    kal_uint32 arb = 1, phy_chann, i, log_channel;
    CCCI_BUFF_T *buff;

    phy_chann = *CCIF_START;

    if (arb == 0)
    {
        buff = (CCCI_BUFF_T *)CCIF_TXCHDATA + phy_chann;
        log_channel = buff->channel;

        if ( query_log == log_channel && data == buff->data[1])
        {
            return KAL_TRUE;
        }

        return KAL_FALSE;
    }

    for(i=0; i<CCIF_MAX_PHY; i++)
    {
        if (phy_chann & (1 << i))
        {
            buff = (CCCI_BUFF_T *)CCIF_TXCHDATA + i;
            log_channel = buff->channel;

            if ( query_log == log_channel && data == buff->data[1])
            {
                return KAL_TRUE;
            }
        }

    }

    return KAL_FALSE;
}


/*************************************************************************
* FUNCTION
*  ccci_chk_recentry_in_queue
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
kal_bool ccci_chk_recentry_in_queue(kal_uint32 query_log, kal_bool Is_Ack_All_if_found)
{
    kal_uint32 arb = 1, phy_chann, i;
    CCCI_BUFF_T *buff;

    phy_chann = *CCIF_RCHNUM;

    if (arb == 0)
    {
        buff = (CCCI_BUFF_T *)CCIF_RXCHDATA + phy_chann;
        if (query_log == buff->channel)
        {
            if ( KAL_TRUE == Is_Ack_All_if_found) *CCIF_ACK = 0xFFFFFFFF;

            return KAL_TRUE;
        }

        return KAL_FALSE;
    }

    for(i=0; i<CCIF_MAX_PHY; i++)
    {
        if (phy_chann & (1 << i))
        {
            buff = (CCCI_BUFF_T *)CCIF_RXCHDATA + i;
            if ( query_log == buff->channel)
            {
                if ( KAL_TRUE == Is_Ack_All_if_found) *CCIF_ACK = 0xFFFFFFFF;

                return KAL_TRUE;
            }
        }
    }

    return KAL_FALSE;
}


/*************************************************************************
* FUNCTION
*  ccci_query_sharemem_addr
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
kal_uint32 ccci_query_sharemem_addr(kal_uint32 channel,kal_uint32 *size)
{
    /* We only support PCM channel to query now */
    if ( CCCI_PCM_CHANNEL == channel || CCCI_PCM_CHANNEL_ACK == channel)
    {
        *size = ap_md_share_data.PcmShareMemSize;
        return ap_md_share_data.PcmShareMemBase;
    }
    else if (CCCI_PMIC_CHANNEL == channel || CCCI_PMIC_ACK_CHANNEL == channel)
    {
        *size = ap_md_share_data.PmicShareMemSize;
        return ap_md_share_data.PmicShareMemBase;
    }
    else
    {

        ASSERT(0);
    }

    return 0;
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
void ccci_change_owner_only(kal_uint32 channel,module_type owner)
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
*  channel    -    			logical channel
*  *
* RETURNS
*  The address of the share memory of the input logical channel
*
*************************************************************************/
void ccci_boot_ack(CCCI_BUFF_T *bufp)
{
    kal_char dbgString[50];

    //sprintf(dbgString, "The initial channel %d and value %d\n",bufp->channel,bufp->data[1]);
    strcpy(dbgString, "The initial channel ");
    kal_itoa(bufp->channel, dbgString+strlen(dbgString), 10);
    strcat(dbgString, " and value");
    kal_itoa(bufp->data[1], dbgString+strlen(dbgString), 10);
    tst_sys_trace (dbgString);

    return;
}


#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__)
extern kal_int32 mmu_set_page_config(kal_uint32 vaddr, kal_uint32 paddr, kal_uint32 len, MMU_PAGE_CONFIG_PTR pagc);
#endif //- (__ARM9_MMU__) || defined(__ARM11_MMU__)
#if defined(__CR4__)
extern kal_uint32 mpu_auto_make_region(kal_uint32 base_addr, kal_uint32 length, REGION_ATTRIBUTE_TYPE attribute, kal_uint32 mode);
#endif //- (__CR4__)

#if defined(CCCI_RPCSRV_SUPPORT_SECURE)
#include "custom_scatstruct.h"

MODEM_RUNTIME_DATA_SEC ap_md_share_data_sec;
kal_uint32 u32sec_struc_starting = 0;

void ccci_secure_check_and_setting(void)
{
    //kal_uint32 u32sec_struc_starting = 0;

    //check prefix/postfix from md image layout
    custom_get_Physical_DUMMY_END(&u32sec_struc_starting);

    if (u32sec_struc_starting)
    {
        memcpy((void*)&ap_md_share_data_sec, (void*)u32sec_struc_starting, sizeof(MODEM_RUNTIME_DATA_SEC));
        
        if (ap_md_share_data_sec.Prefix == PREFIX_CCCI && ap_md_share_data_sec.Postfix == POSTFIX_CCCI)
        {
            if (ap_md_share_data_sec.Rpc_Sec_ShareMemBase && ap_md_share_data_sec.Rpc_Sec_ShareMemSize)
            {
                mpu_auto_make_region ((kal_uint32)(ap_md_share_data_sec.Rpc_Sec_ShareMemBase), CCCI_AP_MD_RPC_SECURE_SHARE_DATA_SIZE_512K, MPU_PRW_URW | MPU_XN | MPU_DEVICE_INS_OUTDEV, 1);
                ccci_secure_runtimedata_checkpass = 1;
                return;
            }
        }
    }

    //security related check fail
    ccci_secure_runtimedata_checkpass = 0;
    return;
}
#endif


/*************************************************************************
* FUNCTION
*  void ccci_init_handshake_phase1
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
void ccci_init_handshake_phase1(void)
{
    CCCI_BUFF_T ccci_buff, *ccci_return_buff;
    kal_uint32 i;
    kal_uint32 index, md_ready_to_go;
    kal_int32  ret;

#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__)
    kal_uint32 share_start,share_end,share_size;
    MMU_PAGE_CONFIG_T pagc;
#ifdef __TST_SP_LOGGING_NCB_OPT__         
    kal_uint32 v_share_start;
#endif //- __TST_SP_LOGGING_NCB_OPT__ 
#endif //- (__ARM9_MMU__) || defined(__ARM11_MMU__)

    ccci_need_check_owner_mask_init ();
    ccci_hw_init ();

    ccci_boottrc_init_log(CCCI_HW_INIT_OK, 0);

    *CCIF_CON |= CCIF_CON_ARB;
    *CCIF_ACK = 0xFFFFFFFF;
    ccci_init(CCCI_CONTROL_CHANNEL,ccci_boot_ack);
    ccci_init(CCCI_CONTROL_CHANNEL_ACK,ccci_boot_ack);
    CCCI_INIT_MAILBOX_WITH_RESERVED(&ccci_buff, CCMSG_ID_START_BOOT, BOOT_CHECK_ID);
    ret = ccci_write(CCCI_CONTROL_CHANNEL, &ccci_buff);

    ccci_boottrc_init_log(CCCI_HS1_WRITE_RESULT, (kal_uint32)ret);

    while (1)
    {
        md_ready_to_go = 0;
        if (*CCIF_RCHNUM)
        {
            for (index = 0; index < CCIF_MAX_PHY; index++)
            {
                ccci_return_buff = (CCCI_BUFF_T *)CCIF_RXCHDATA + index;

                if (ccci_return_buff->reserved == BOOT_CHECK_ID)
                {
                    md_ready_to_go = 1;
                    break;
                }
            }

            if (1 == md_ready_to_go) break;
        }
    }

    ccci_boottrc_init_log(CCCI_HS1_DONE, 0);

    *CCIF_CON &= CCIF_CON_SEQ;
    *CCIF_ACK = 0xFFFFFFFF;
#if defined(CCCI_INIT_HANDSHAKE_MODE1)
    for (i=0; i < (sizeof(MODEM_RUNTIME_INFO)+3) >> 2; i++)
    {
        *((volatile unsigned long *)&ap_md_share_info + i) = *((volatile unsigned long *)MDCCIF_INITDATA +i);
    }
#if defined(__CR4__)
#if defined(MT6280) && defined(__SMART_PHONE_MODEM__)

    //- MT6280 RNDIS case
    {
        kal_uint32 share_buffer_start_addr;
        kal_uint32 share_buffer_size_before_32MB, share_buffer_size_after_32MB;
        
        share_buffer_start_addr = custom_get_DSPTXRX_Base() + custom_get_DSPTXRX_MaxSize();
        share_buffer_size_before_32MB = CCCI_AP_MD_SHARE_DATA_SIZE_32MB - share_buffer_start_addr;
        
        //- Use one MPU region to configure from share_buffer_start_addr to 32MB.
        mpu_auto_make_region (share_buffer_start_addr, share_buffer_size_before_32MB, MPU_PRW_URW | MPU_XN | MPU_DEVICE_INS_OUTDEV, 1);
        
        //- if the share buffer uses address larger than 32MB, use another MPU region to configure remaining region.
        if (share_buffer_start_addr + ap_md_share_info.RuntimedataSize > CCCI_AP_MD_SHARE_DATA_SIZE_32MB)
        {
            share_buffer_size_after_32MB = ap_md_share_info.RuntimedataSize - CCCI_AP_MD_SHARE_DATA_SIZE_32MB;
            mpu_auto_make_region (CCCI_AP_MD_SHARE_DATA_SIZE_32MB, share_buffer_size_after_32MB, MPU_PRW_URW | MPU_XN | MPU_DEVICE_INS_OUTDEV, 1);
        }
    }
    
#else  //- (MT6280) && (__SMART_PHONE_MODEM__)

    // - smart phone and MT6280 HOSTED dongle case
    mpu_auto_make_region ((kal_uint32)(ap_md_share_info.RuntimedataBase), CCCI_AP_MD_SHARE_DATA_SIZE_2MB, MPU_PRW_URW | MPU_XN | MPU_DEVICE_INS_OUTDEV, 1);
    
    #if defined(CCCI_RPCSRV_SUPPORT_SECURE)
    ccci_secure_check_and_setting();
    #endif

#endif //- (MT6280) && (__SMART_PHONE_MODEM__)
#endif //- (__CR4__)
#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__)
    DEFAULT_RW_NCNB((MMU_PAGE_CONFIG_PTR)&pagc);
    share_start	= (kal_uint32)(ap_md_share_info.RuntimedataBase);
    share_size	= ap_md_share_info.RuntimedataSize;
    mmu_set_page_config(share_start, share_start, share_size, &pagc);

#ifdef __TST_SP_LOGGING_NCB_OPT__         
    //- Set another address mapped to CCCI share buffer to NCB
    //- Reason: change MD logger to NCB type to enhance performance
    DEFAULT_RW_NCB((MMU_PAGE_CONFIG_PTR)&pagc);
    v_share_start = NCNB_TO_NCB(ap_md_share_info.RuntimedataBase);
    //- Size is the same
    mmu_set_page_config(v_share_start, share_start, share_size, &pagc);
#endif //- __TST_SP_LOGGING_NCB_OPT__         
#endif //- (__ARM9_MMU__) || defined(__ARM11_MMU__)

    //- get ap_md_share_data here!
    kal_mem_cpy((kal_uint8 *)&ap_md_share_data, (kal_uint8 *)(ap_md_share_info.RuntimedataBase), sizeof(MODEM_RUNTIME_DATA));
    if (ap_md_share_info.RuntimedataSize != sizeof (MODEM_RUNTIME_DATA))
    {
        ccci_ap_md_share_data_mismatch = 1;
    }

    //- init ext exception data
    ap_md_exception_ext = (MODEM_EXCEPTION_EXT*)(ap_md_share_data.ExtMDExcepInfoBase);

#else
    for (i=0; i < (sizeof(MODEM_RUNTIME_DATA)+3) >> 2; i++)
    {
        *((volatile unsigned long *)&ap_md_share_data + i) = *((volatile unsigned long *)MDCCIF_INITDATA +i);
    }
#endif

#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__)
    ccci_CalculateShareMem(&share_start, &share_end , &share_size);
    DEFAULT_RW_NCNB((MMU_PAGE_CONFIG_PTR)&pagc);
    mmu_set_page_config(share_start, share_start, share_size, &pagc);
    
#ifdef __TST_SP_LOGGING_NCB_OPT__         
    //- Set another address mapped to CCCI share buffer to NCB
    //- Reason: change MD logger to NCB type to enhance performance
    ccci_CalculateShareMem(&share_start, &share_end , &share_size);
    DEFAULT_RW_NCB((MMU_PAGE_CONFIG_PTR)&pagc);
    v_share_start = NCNB_TO_NCB(share_start);
    //- Size is the same
    mmu_set_page_config(v_share_start, share_start, share_size, &pagc);
#endif //- __TST_SP_LOGGING_NCB_OPT__         
#endif //- (__ARM9_MMU__) || defined(__ARM11_MMU__)

    for (index = 0; index < ap_md_share_data.UartPortNum; index ++)
    {

        if (0 == ap_md_share_data.UartShareMemBase[index])    continue;

        (ccci_uartp_buff[index]).tx  = (CCCI_UARTB_T *)(ap_md_share_data.UartShareMemBase[index]);
        (ccci_uartp_buff[index]).rx  = (CCCI_UARTB_T *)((ap_md_share_data.UartShareMemBase[index]) + sizeof(CCCI_UARTB_T)) ;
        (ccci_uartp_buff[index]).tx_buff = ((kal_uint8 *)(ap_md_share_data.UartShareMemBase[index]) + 2*sizeof(CCCI_UARTB_T));
        (ccci_uartp_buff[index]).rx_buff = (((kal_uint8 *)(ap_md_share_data.UartShareMemBase[index]) + 2*sizeof(CCCI_UARTB_T)) \
                                            + ( (( ap_md_share_data.UartShareMemSize[index] - 2*sizeof(CCCI_UARTB_T)) /2 ) ));
    }
    ipcsvc_share_rx_g = (Ipcsvc_Share_ST *)ap_md_share_data.IPCShareMemBase;
    ipcsvc_share_tx_g = (Ipcsvc_Share_ST *)(ap_md_share_data.IPCShareMemBase + (ap_md_share_data.IPCShareMemSize/2));

    if( (ap_md_share_data.BootingStartID & 0x0000FF00) != 0 )
    {
        ex_set_memorydump_flag();
    }
    else
    {
        ex_clear_memorydump_flag();
    }
#if defined(__MULTI_BOOT__)
    if ( META_BOOT_ID == (ap_md_share_data.BootingStartID  & 0x000000FF) )
    {
        (*(volatile kal_uint16 *)BOOT_CONFIG_ADDR) |= 0x0001; /* KC setting the meta mode */
    }
#endif /*  #ifdef __MULTI_BOOT__ */

    ccci_deinit(CCCI_CONTROL_CHANNEL);
    ccci_deinit(CCCI_CONTROL_CHANNEL_ACK);
    ccci_is_ap_wakeup = 1;
    //- init R8 new data path
#ifdef CCCI_UART_GIO
    ccci_uart_gio_initial ();
#endif

    if (ap_md_share_data.ExceShareMemSize >= CCCI_EXCEP_DBG_LOG_SIZE_BOUNDARY)
    {
        //- Use last 1KB as EXCEP log.
        ccci_excep_dbg_log_base = ap_md_share_data.ExceShareMemBase + ap_md_share_data.ExceShareMemSize - CCCI_EXCEP_DBG_LOG_LARGE_SIZE;
        ccci_excep_dbg_log_size = (CCCI_EXCEP_DBG_LOG_LARGE_SIZE - CCCI_EXCEP_DBG_LOG_LARGE_SIZE_HS2);

        ccci_excep_dbg_log_base_hs2 = ap_md_share_data.ExceShareMemBase + ap_md_share_data.ExceShareMemSize - CCCI_EXCEP_DBG_LOG_LARGE_SIZE_HS2;
        ccci_excep_dbg_log_size_hs2 = CCCI_EXCEP_DBG_LOG_LARGE_SIZE_HS2;
    }
    else
    {
        //- Use last 512 bytes as EXCEP log.
        ccci_excep_dbg_log_base = ap_md_share_data.ExceShareMemBase + ap_md_share_data.ExceShareMemSize - CCCI_EXCEP_DBG_LOG_SMALL_SIZE;
        ccci_excep_dbg_log_size = (CCCI_EXCEP_DBG_LOG_SMALL_SIZE - CCCI_EXCEP_DBG_LOG_SMALL_SIZE_HS2);

        ccci_excep_dbg_log_base_hs2 = ap_md_share_data.ExceShareMemBase + ap_md_share_data.ExceShareMemSize - CCCI_EXCEP_DBG_LOG_SMALL_SIZE_HS2;
        ccci_excep_dbg_log_size_hs2 = CCCI_EXCEP_DBG_LOG_SMALL_SIZE_HS2;
    }

#ifdef __SP_BOOTTRC_ENABLE__
    //- Init boottrc addr/size/ptr. Use same address as EXCEP Log.
    ccci_boottrc_buffer_addr = ccci_excep_dbg_log_base;
    ccci_boottrc_buffer_size = ccci_excep_dbg_log_size;
    ccci_boottrc_buffer_ptr = ccci_boottrc_buffer_addr;
    
    //- Write the start address of boot up trace in AP log to offset 0 of excep share memory
    *(volatile kal_uint32*)(ap_md_share_data.ExceShareMemBase) = (ccci_boottrc_buffer_addr - ap_md_share_data.ExceShareMemBase);
#endif    
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
void ccci_dummy_ack(CCCI_BUFF_T *bufp)
{
    return;
}

/*************************************************************************
* FUNCTION
*  void CCCI_Invalid_Callback
*
* DESCRIPTION
*  -
*
* PARAMETERS
*  -
*
* RETURNS
*  NA
*
*************************************************************************/
void CCCI_Invalid_Callback(CCCI_BUFF_T *bufp)
{
    ASSERT(0);

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
*  channel    -    			logical channel
*  *
* RETURNS
*  NA
*
*************************************************************************/
void ccci_system_channel_runtime_callback(CCCI_BUFF_T *bufp)
{
    kal_int32  ret;
    kal_uint32 id;
    kal_uint32 id_1;


    if(INT_QueryExceptionStatus() == KAL_TRUE) return;
    
    id = CCCI_MAILBOX_ID(bufp);
    
    if (id & CCMSG_ID_SYSMSGSVC_MASK)
    {
        if (id >= CCMSG_ID_SYSMSGSVC_END)
            return;
			
        id_1 = id - CCMSG_ID_SYSMSGSVC_START;
					
        if (ccci_sysmsgsvc_cb[id_1])
        {
            ccci_sysmsgsvc_cb[id_1](bufp->reserved);

            if (id == CCMSG_ID_SYSMSGSVC_L1_SLEEPMASKING)
            {
                ret = ccci_send_message (CCMSG_ID_SYSMSGSVC_L1_SLEEPMASKING, bufp->reserved);
                if (ret == KAL_FALSE)
                {
                    tst_sys_trace("CCCI_SLEEPMASKING : warning1\0");
                }
            }
        }
		
        //- ilm section
        if (ccci_sysmsgsvc_msg[id_1][0] & 0x80)
        {
            if (ccci_sysmsgsvc_msg[id_1][0] & 0x40)
            {
                CCCI_COMMON_ILM_4B *local_para_4B;                
                
                local_para_4B = (CCCI_COMMON_ILM_4B *) construct_local_para (sizeof(CCCI_COMMON_ILM_4B), TD_RESET);
                local_para_4B->W0 = bufp->reserved;
                ccci_ilm_log_pool[ccci_ilm_log_index].in_tick = kal_get_systicks();
                ccci_ilm_log_pool[ccci_ilm_log_index]._src_mod_id = MOD_CCCI_HISR;
                ccci_ilm_log_pool[ccci_ilm_log_index]._dest_mod_id=MOD_L4C;
                ccci_ilm_log_pool[ccci_ilm_log_index]._msg_id=ccci_sysmsgsvc_msg[id_1][1];
                ccci_ilm_log_pool[ccci_ilm_log_index]._local_para_ptr = (local_para_struct*)local_para_4B;
                msg_send5 (MOD_CCCI_HISR, MOD_L4C, 0, ccci_sysmsgsvc_msg[id_1][1], (local_para_struct*)local_para_4B); 	
                ccci_ilm_log_pool[ccci_ilm_log_index].out_tick = kal_get_systicks();
                ccci_ilm_log_index++;
                ccci_ilm_log_index%=(ilm_DebugEntryNo); 				
            }
            else
            {
                ccci_ilm_log_pool[ccci_ilm_log_index].in_tick = kal_get_systicks();
                ccci_ilm_log_pool[ccci_ilm_log_index]._src_mod_id = MOD_CCCI_HISR;
                ccci_ilm_log_pool[ccci_ilm_log_index]._dest_mod_id=MOD_L4C;
                ccci_ilm_log_pool[ccci_ilm_log_index]._msg_id=ccci_sysmsgsvc_msg[id_1][1];
                ccci_ilm_log_pool[ccci_ilm_log_index]._local_para_ptr = 0;
                msg_send4 (MOD_CCCI_HISR, MOD_L4C, 0, ccci_sysmsgsvc_msg[id_1][1]);   
                ccci_ilm_log_pool[ccci_ilm_log_index].out_tick = kal_get_systicks();
                ccci_ilm_log_index++;
                ccci_ilm_log_index%=(ilm_DebugEntryNo);        	            	
            }
        }

        return;	
    }
    
    switch(CCCI_MAILBOX_ID(bufp))
    {
    case  CCMSG_ID_MD_L4_MOD:
    {
        ccci_ilm_log_pool[ccci_ilm_log_index].in_tick = kal_get_systicks();
        ccci_ilm_log_pool[ccci_ilm_log_index]._src_mod_id = MOD_CCCI_HISR;
        ccci_ilm_log_pool[ccci_ilm_log_index]._dest_mod_id=MOD_L4C;
        ccci_ilm_log_pool[ccci_ilm_log_index]._msg_id=MSG_ID_L4C_END_PS_DATA_SENSSION_REQ;
        ccci_ilm_log_pool[ccci_ilm_log_index]._local_para_ptr = 0;
        msg_send4 (MOD_CCCI_HISR, MOD_L4C, 0, MSG_ID_L4C_END_PS_DATA_SENSSION_REQ);
        ccci_ilm_log_pool[ccci_ilm_log_index].out_tick = kal_get_systicks();
        ccci_ilm_log_index++;
        ccci_ilm_log_index%=(ilm_DebugEntryNo);
    }
    break;
    case  CCMSG_ID_MD_L4_MAX_TX_PWR_RED_REQ:
    {
        CCCI_COMMON_ILM_2B *local_para;

        local_para = (CCCI_COMMON_ILM_2B *) construct_local_para (sizeof(CCCI_COMMON_ILM_2B), TD_RESET);
        local_para->HW0 = bufp->reserved & 0xFFFF;
        ccci_ilm_log_pool[ccci_ilm_log_index].in_tick = kal_get_systicks();
        ccci_ilm_log_pool[ccci_ilm_log_index]._src_mod_id = MOD_CCCI_HISR;
        ccci_ilm_log_pool[ccci_ilm_log_index]._dest_mod_id=MOD_L4C;
        ccci_ilm_log_pool[ccci_ilm_log_index]._msg_id=MSG_ID_L4C_MAX_TX_PWR_RED_REQ;
        ccci_ilm_log_pool[ccci_ilm_log_index]._local_para_ptr = (local_para_struct*)local_para;
        msg_send5 (MOD_CCCI_HISR, MOD_L4C, 0, MSG_ID_L4C_MAX_TX_PWR_RED_REQ, (local_para_struct*)local_para);
        ccci_ilm_log_index++;
        ccci_ilm_log_index%=(ilm_DebugEntryNo);
    }
    break;
    default:
        break;
    }//end switch
}

/*************************************************************************
* FUNCTION
*  void ccci_init_handshake_phase2
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
void ccci_init_handshake_phase2(kal_uint16 _boot_mode)
{
    kal_uint32  u32mailbox_id = 0;
    CCCI_BUFF_T ccci_buff;

    ccci_init(ap_md_share_data.BootChannel,ccci_boot_ack);
    ccci_init(ap_md_share_data.BootChannel+1,ccci_boot_ack);

    if (ap_md_share_data.DriverVersion == CCCI_CURRENT_VERSION)
    {
        u32mailbox_id = ap_md_share_data.BootReadyID;
    }
    else
    {
        u32mailbox_id = CCMSG_ID_DRV_VERSION_ERR;
    }

#if defined(CCCI_RPCSRV_SUPPORT_SECURE)
    if (!ccci_secure_runtimedata_checkpass)
    {
        u32mailbox_id = CCMSG_ID_DRV_VERSION_ERR;
    }
#endif

    CCCI_INIT_MAILBOX(&ccci_buff, u32mailbox_id);

    ccci_write(ap_md_share_data.BootChannel, &ccci_buff);

    ccci_deinit(ap_md_share_data.BootChannel);
    ccci_deinit(ap_md_share_data.BootChannel+1);

    if (u32mailbox_id == CCMSG_ID_DRV_VERSION_ERR)
    {
        while(1);
    }

    /* For run-time information exchange with AP side */
    ccci_init(CCCI_SYSTEM_CHANNEL_ACK, ccci_system_channel_runtime_callback);
    ccci_init(CCCI_SYSTEM_CHANNEL, ccci_dummy_ack);

#ifdef CCCI_UART_GIO_IT
    ccci_uart_gio_initial_IT ();
#endif
}

/*************************************************************************
* FUNCTION
*  void ccci_except_ack
*
* DESCRIPTION
*  This function use to as a ack funtion when exception happen
*
* PARAMETERS
*  channel    -    			logical channel
*  *
* RETURNS
*  NA
*
*************************************************************************/
void ccci_except_ack(CCCI_BUFF_T *bufp)
{
    return;
}

#if defined(CCCI_INIT_HANDSHAKE_MODE1)
/*************************************************************************
* FUNCTION
*  void ccci_exception_fill_aphang_info
*
* DESCRIPTION
*  This function fills AP hang related information to shared buffer.
*
* PARAMETERS
*  NA
*
* RETURNS
*  NA
*
*************************************************************************/
static void ccci_exception_fill_aphang_info()
{
    kal_uint32 start_time, end_time;
    kal_uint32 logical_channel, trans_log_index;

    if(INT_QueryExceptionStatus() == KAL_FALSE) return;

    /* MD no physical channel issue */
    if(CCIF_ALL_PHY_MASK == ccif_last_tx_busy_channel_mask)
    {
        /* Now ccif_writeindx_for_AP means the first physical channel that AP doens't respond. */
        logical_channel = ccif_last_tx_snapshot[ccif_writeindx_for_AP].channel;
        
        /* find oldest trans log in CCIF share memory */
        trans_log_index = ccif_trans_log_index_mapping[ccif_writeindx_for_AP];
        start_time = ccci_trans_log_pool[logical_channel][trans_log_index].tick;
        
        /* if physcial channel still full in exception handler, log current time as channel-full end time */
        if(CCIF_ALL_PHY_MASK == ccif_last_tx_channel)
        {
            end_time = kal_get_systicks();
        }
        /* else, find tick in trans log of latest transfered logical channel */
        else
        {
            logical_channel = ccif_last_tx_snapshot[(ccif_writeindx_for_AP + CCIF_MAX_PHY - 1) % CCIF_MAX_PHY].channel;
            trans_log_index = (ccci_trans_log_index[logical_channel] + DebugEntryNo - 1) % DebugEntryNo;
            end_time = ccci_trans_log_pool[logical_channel][trans_log_index].tick;
        }
        
        ap_md_exception_ext->send_time = start_time;
        
        /* need to discuss with USC owner for API to calculate duration between frame tick */
        if(end_time >= start_time)
        {
            ap_md_exception_ext->wait_time = end_time - start_time;
        }
        else
        {
        	  /* wrap case */
            ap_md_exception_ext->wait_time = 0xFFFFFFFF - start_time + 1 + end_time;
        }
        
        ap_md_exception_ext->exception_occur |= (1 << 1);
    }
}
#endif

/*************************************************************************
* FUNCTION
*  void ccci_exception_handshake
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
void ccci_exception_handshake(void)
{
    CCCI_BUFF_T buff;
    kal_uint32	i;
    kal_uint32	*ptr_src, *ptr_dis;

    // ensure in the exception state
    if(INT_QueryExceptionStatus() == KAL_FALSE) return;

    ccif_last_con = *CCIF_CON;
    ccif_last_rx_channel = *CCIF_RCHNUM;
    ccif_last_tx_channel = *MDCCIF_BUSY;

    //- Tx section
    ptr_src = (kal_uint32 *)MDCCIF_TXCHDATA;
    ptr_dis = (kal_uint32 *)ccif_last_tx_snapshot;
    //- Avoid to use kal_mem_cpy
    //- HW bug
    for(i=0; i<32; i++)
    {
        *ptr_dis = *ptr_src;
        ptr_dis ++;
        ptr_src ++;
    }
    //- Rx section
    ptr_src = (kal_uint32 *)MDCCIF_RXCHDATA;
    ptr_dis = (kal_uint32 *)ccif_last_rx_snapshot;
    //- Avoid to use kal_mem_cpy
    //- HW bug
    for(i=0; i<32; i++)
    {
        *ptr_dis = *ptr_src;
        ptr_dis ++;
        ptr_src ++;
    }
    
#if defined(CCCI_INIT_HANDSHAKE_MODE1)
    ccci_exception_fill_aphang_info();
    ap_md_exception_ext->exception_occur |= 1;
#endif

    /* copy exception memory */
    kal_mem_set((void*)ap_md_share_data.ExceShareMemBase, 0, sizeof(EX_LOG_T));
    kal_mem_cpy((void*)(ap_md_share_data.ExceShareMemBase), ex_log_ptr, sizeof(EX_LOG_T));

//- yy: should phase out by 2013/05/03
#if defined(__MTK_INTERNAL__) && defined(MT6572)
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
    
    *CCIF_ACK = 0xFFFFFFFF;
    ccci_init(CCCI_CONTROL_CHANNEL, ccci_except_ack);
    ccci_init(CCCI_CONTROL_CHANNEL_ACK, ccci_except_ack);
    ccci_ctrl_pool[CCCI_CONTROL_CHANNEL].state = CCCI_IDLE;

    CCCI_INIT_MAILBOX_WITH_RESERVED(&buff, CCMSG_ID_EXCEPTION_CHECK, EXCEPTION_CHECK_ID);

    ccci_exception_check_write_result = ccci_write_internal(CCCI_CONTROL_CHANNEL,&buff,KAL_FALSE);

    ust_busy_wait(CCCI_WAIT_MAX_TIME);
    if (KAL_TRUE != ccci_chk_recentry_in_queue(CCCI_CONTROL_CHANNEL_ACK, KAL_TRUE))
    {
        ccci_exception_handshake_done = KAL_FALSE;
    }
    else
    {
        ccci_exception_handshake_done = KAL_TRUE;
    }

#ifdef __CCCI_DEBUG_APHANG_ERROR___
    ccci_exception_error_handler_aphang();
#endif

    //- Pupa add for debug :20120209
#ifdef __CCCI_DEBUG_ATCMD_ERROR___
    {
        kal_uint32 i;
        kal_uint8 *ptr = (kal_uint8 *)(ap_md_share_data.UartShareMemBase[1]); //- uart_port_at_ccci
        kal_uint32 size = (ap_md_share_data.UartShareMemSize[1] + 511) / 512; //- divide by 512
        kal_uint8 start_String[] = "***CCCI_Uart1 Start***\0";
        kal_uint8 end_String[] = "***CCCI_Uart1 End***\0";

        kal_buffer_trace(TRACE_INFO, TR_BUFFER_TRACE, sizeof(start_String), start_String);
        for (i=0; i<size; i++)
        {
            kal_buffer_trace(TRACE_INFO, TR_BUFFER_TRACE, 512, ptr);
            ptr += 512;
        }
        kal_buffer_trace(TRACE_INFO, TR_BUFFER_TRACE, sizeof(end_String), end_String);
        //- kal_buffer_trace(TRACE_INFO, TR_BUFFER_TRACE, 32, (kal_uint8 *)(ap_md_share_data.UartShareMemBase[1]));
        //- kal_buffer_trace(TRACE_INFO, TR_BUFFER_TRACE, 1024, (kal_uint8 *)(ap_md_share_data.UartShareMemBase[1]));
    }
#endif
    //- Pupa end
}

/*************************************************************************
* FUNCTION
*  kal_uint32 ccci_excep_dbg_get_swla_addr
*
* DESCRIPTION
*  This function is used to get address for SWLA logging over CCCI
*
* PARAMETERS
*  *
* RETURNS
*  The address of the share memory for SWLA logging
*
*************************************************************************/
kal_uint32 ccci_excep_dbg_get_swla_addr(void)
{
    //this feature is for swla to record runtime context name
    //option switch: __SWLA_ON_CCCI__
    return ccci_excep_dbg_log_base + sizeof(ccci_excep_dbg_hdr_t) + (CCCI_EXCEP_DBG_SWLA_LOG_MARK * 4);
}

/*************************************************************************
* FUNCTION
*  kal_int32 ccci_excep_dbg_logging
*
* DESCRIPTION
*  This function is used to write log to CCCI Exception Memory
*  The function only supports 4bytes align debug info currently
*
* PARAMETERS
*  log_type    - Log type
*  state_info  - Idle task state information
*  *
* RETURNS
*  The address of the share memory of the input logical channel
*
*************************************************************************/
kal_int32 ccci_excep_dbg_logging(kal_uint32 index, void* addr)
{
    static kal_uint32       magic_number_valid = 0;
    kal_uint32              dst_addr;
    ccci_excep_dbg_hdr_t    *hdr_ptr;
    
    if (addr == NULL || ((kal_uint32)addr % 4 !=0) || index >= CCCI_EXCEP_DBG_LOG_INDEX_MAX || !ccci_excep_dbg_log_base)
        return CCCI_FAIL;
    
    hdr_ptr = (ccci_excep_dbg_hdr_t*)ccci_excep_dbg_log_base;
    
    //- if magic number is not written, set magic number at first two words
    if (magic_number_valid == 0)
    {
        magic_number_valid = 1;
        hdr_ptr->magic_number_l = CCCI_EXCEP_DBG_INDICATOR_L;
        hdr_ptr->magic_number_h = CCCI_EXCEP_DBG_INDICATOR_H;
    }

    //- yy: Current excep dbg only support 4 bytes, so the address of log will be ccci_excep_dbg_log_base + 0x10 + index * 4
    //-     Each index use one word.
    dst_addr = ccci_excep_dbg_log_base + sizeof(ccci_excep_dbg_hdr_t) + index * 4;
    
    if (dst_addr > ccci_excep_dbg_log_base + ccci_excep_dbg_log_size)
        return CCCI_FAIL;
    
    *((volatile kal_uint32 *)dst_addr) = *((kal_uint32 *)addr);
    
    //- write last index
    hdr_ptr->last_write_index = (0x80000000 | index);
    
    //- read to device type memory to ensure data is drained to EMI.
    dst_addr = *((volatile kal_uint32 *)(ccci_excep_dbg_log_base));

    return CCCI_SUCCESS;
}


/*************************************************************************
* FUNCTION
*  kal_int32 ccci_excep_dbg_logging_InHS2
*
* DESCRIPTION
*  This function is used to write log to CCCI Exception Memory
*  The function only supports 4bytes align debug info currently
*
* PARAMETERS
*  log_type    - Log type
*  state_info  - Idle task state information
*  *
* RETURNS
*  The address of the share memory of the input logical channel
*
*************************************************************************/
kal_int32 ccci_excep_dbg_logging_InHS2(kal_uint32 index, void* addr)
{
    static kal_uint32       magic_number_valid_hs = 0;
    kal_uint32              dst_addr;
    ccci_excep_dbg_hdr_t    *hdr_ptr;
    
    if (addr == NULL || ((kal_uint32)addr % 4 !=0) || index >= CCCI_EXCEP_DBG_HS_LOG_MAX || !ccci_excep_dbg_log_base_hs2)
        return CCCI_FAIL;
    
    hdr_ptr = (ccci_excep_dbg_hdr_t*)ccci_excep_dbg_log_base_hs2;
    
    //- if magic number is not written, set magic number at first two words
    if (magic_number_valid_hs == 0)
    {
        magic_number_valid_hs = 1;
        hdr_ptr->magic_number_l = CCCI_EXCEP_DBG_INDICATOR_L;
        hdr_ptr->magic_number_h = CCCI_EXCEP_DBG_INDICATOR_H;
    }

    //- yy: Current excep dbg only support 4 bytes, so the address of log will be ccci_excep_dbg_log_base + 0x10 + index * 4
    //-     Each index use one word.
    dst_addr = ccci_excep_dbg_log_base_hs2 + sizeof(ccci_excep_dbg_hdr_t) + index * 4;
    
    if (dst_addr > ccci_excep_dbg_log_base_hs2 + ccci_excep_dbg_log_size_hs2)
        return CCCI_FAIL;
    
    *((volatile kal_uint32 *)dst_addr) = *((kal_uint32 *)addr);
    
    //- write last index
    hdr_ptr->last_write_index = (0x70000000 | index);
    
    //- read to device type memory to ensure data is drained to EMI.
    dst_addr = *((volatile kal_uint32 *)(ccci_excep_dbg_log_base_hs2));

    return CCCI_SUCCESS;
}

/*************************************************************************
* FUNCTION
*  void ccci_exception_info_passed
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
void ccci_exception_info_passed(void)
{
    CCCI_BUFF_T buff;

    kal_mem_cpy((void*)(ap_md_share_data.ExceShareMemBase), ex_log_ptr, sizeof(EX_LOG_T));

    // ensure in the exception state
    if(INT_QueryExceptionStatus() == KAL_FALSE) return;

    *CCIF_ACK = 0xFFFFFFFF;
    //kal_mem_set((void *)MDCCIF_RXCHDATA, 0 , 128);
    //- Already init in ccci_exception_handshake
    //- ccci_init(CCCI_CONTROL_CHANNEL, ccci_except_ack);
    //- ccci_init(CCCI_CONTROL_CHANNEL_ACK, ccci_except_ack);
    ccci_ctrl_pool[CCCI_CONTROL_CHANNEL].state = CCCI_IDLE;

    CCCI_INIT_MAILBOX_WITH_RESERVED(&buff, CCMSG_ID_EXCEPTION_REC_OK, EXCEPTION_REC_READY);

    ccci_exception_info_write_result = ccci_write_internal(CCCI_CONTROL_CHANNEL,&buff,KAL_FALSE);
}

/*************************************************************************
* FUNCTION
*  ccci_exception_error_handler_aphang
*
* DESCRIPTION
*  This function .
*
* PARAMETERS
*  none    -
*  *
* RETURNS
*  none
*
*************************************************************************/
#ifdef __CCCI_DEBUG_APHANG_ERROR___
void ccci_exception_error_handler_aphang(void)
{
    kal_uint32 phy_chann;

    kal_uint32 time, first_tx_tran_time, last_tx_tran_time, last_rx_tran_time;
    kal_int8 index, same_tran_count=0;
    kal_char debug_info[100];
    CCCI_BUFF_T *chdata, *comp_chdata;

    phy_chann = *CCIF_START;

    time = kal_get_systicks();

    //sprintf(debug_info, "current time in ccci_exception_handshake = %d", time);
    strcpy(debug_info, "current time in ccci_exception_handshake = ");
    kal_itoa(time, debug_info+strlen(debug_info), 10);
    tst_sys_trace(debug_info);

    //sprintf(debug_info, "ccci_exception_handshake_done = %d", ccci_exception_handshake_done);
    strcpy(debug_info, "ccci_exception_handshake_done = ");
    kal_itoa(ccci_exception_handshake_done, debug_info+strlen(debug_info), 10);
    tst_sys_trace(debug_info);

    if (ccci_debug_phychan_full)
    {

        /**************************************************************************************
        *		TX information (caculate the time period between oldest~last transation time)
        **************************************************************************************/
        //find the oldest transaction time
        index = (kal_int8)ccif_writeindx_for_AP;

        //parse the same logic channel transaction in CCIF channel
        chdata = (CCCI_BUFF_T *)CCIF_TXCHDATA + index;
        for(index = 0; index < CCIF_MAX_PHY; index++)
        {
            comp_chdata = (CCCI_BUFF_T *)CCIF_TXCHDATA + index;
            if(chdata->channel == comp_chdata->channel)
                same_tran_count++;
        }

        //output the oldest transaction time
        if( ccci_trans_log_index[chdata->channel] >= same_tran_count)
            index = ccci_trans_log_index[chdata->channel]-same_tran_count;
        else
            index = ccci_trans_log_index[chdata->channel]-same_tran_count + DebugEntryNo;
        first_tx_tran_time = ccci_trans_log_pool[chdata->channel][index].tick;

        //sprintf(debug_info, "the oldest time in TX CCIF channel = %d", first_tx_tran_time);
        strcpy(debug_info, "the oldest time in TX CCIF channel = ");
        kal_itoa(first_tx_tran_time, debug_info+strlen(debug_info), 10);
        tst_sys_trace(debug_info);

        //find the last transaction time
        index = (kal_int8)(ccif_writeindx_for_AP-1);
        if(index < 0)
            index += CCIF_MAX_PHY;

        chdata = (CCCI_BUFF_T *)CCIF_TXCHDATA + index;

        //output the last transaction time
        index =(ccci_trans_log_index[chdata->channel]-1);
        if( index == 0xFF)
            index = ccci_trans_log_index[chdata->channel]-1 + DebugEntryNo;
        last_tx_tran_time = ccci_trans_log_pool[chdata->channel][index].tick;

        //sprintf(debug_info, "the last time in TX CCIF channel = %d", last_tx_tran_time);
        strcpy(debug_info, "the last time in TX CCIF channel = ");
        kal_itoa(last_tx_tran_time, debug_info+strlen(debug_info), 10);
        tst_sys_trace(debug_info);

        /**************************************************************************************
        *		RX information (caculate the time period between oldest~last transation time)
        **************************************************************************************/
        //find the last transaction time
        index = (kal_int8)(ccif_readindx_for_MD-1);
        if(index < 0)
            index += CCIF_MAX_PHY;

        chdata = (CCCI_BUFF_T *)CCIF_RXCHDATA + index;

        //output the last transaction time
        index =(ccci_trans_log_index[chdata->channel]-1);
        if( index == 0xFF)
            index += DebugEntryNo;
        last_rx_tran_time = ccci_trans_log_pool[chdata->channel][index].tick;

        //sprintf(debug_info, "the last time in RX CCIF channel = %d", last_rx_tran_time);
        strcpy(debug_info, "the last time in RX CCIF channel = ");
        kal_itoa(last_rx_tran_time, debug_info+strlen(debug_info), 10);
        tst_sys_trace(debug_info);

        if(!(last_rx_tran_time > first_tx_tran_time && last_rx_tran_time < last_tx_tran_time))
        {
            tst_sys_trace("Suspect AP hang, please check AP side CCCI first");
        }
        else if(phy_chann == 0xFF)
        {
            tst_sys_trace("Suspect AP hang, please check AP side CCCI first");
        }
    }
}
#endif //- __CCCI_DEBUG_APHANG_ERROR___


/*************************************************************************
* FUNCTION
*  void ccci_GetShareMemInfo(kal_uint32 **info, kal_uint16* count )
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
kal_uint32 ccci_share_memory[] =
{
    0,0,
    0,0,
    0,0,
    0,0,
    0,0
};


void ccci_GetShareMemInfo( kal_uint32 **info, kal_uint16* count )
{
    ccci_share_memory[0] = ap_md_share_data.PcmShareMemBase;
    ccci_share_memory[1] = ap_md_share_data.PcmShareMemSize;
    ccci_share_memory[2] = ap_md_share_data.FileShareMemBase;
    ccci_share_memory[3] = ap_md_share_data.FileShareMemSize;
    ccci_share_memory[4] = ap_md_share_data.PmicShareMemBase;
    ccci_share_memory[5] = ap_md_share_data.PmicShareMemSize;
    ccci_share_memory[6] = ap_md_share_data.UartShareMemBase[0];
    ccci_share_memory[7] = ap_md_share_data.UartShareMemSize[0];
    ccci_share_memory[8] = ap_md_share_data.UartShareMemBase[1];
    ccci_share_memory[9] = ap_md_share_data.UartShareMemSize[1];

    *info = (kal_uint32 *)ccci_share_memory;
    *count = (sizeof(ccci_share_memory)/(sizeof(kal_uint32)))/2;
}

/*************************************************************************
* FUNCTION
*  ccci_CalculateShareMem
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
void ccci_CalculateShareMem(kal_uint32 *start_addr, kal_uint32 *end_addr , kal_uint32 *size)
{
#if defined(CCCI_INIT_HANDSHAKE_MODE1)
    kal_uint32 i;
#endif

    kal_uint32 max_addr = 0;
    kal_uint32 min_addr = 0xFFFFFFFF;

    if ( min_addr > ap_md_share_data.MdlogShareMemBase && ap_md_share_data.MdlogShareMemBase!= 0 )
        min_addr = ap_md_share_data.MdlogShareMemBase;

    if ( min_addr > ap_md_share_data.PcmShareMemBase && ap_md_share_data.PcmShareMemBase!= 0)
        min_addr = ap_md_share_data.PcmShareMemBase;

    if ( min_addr > ap_md_share_data.FileShareMemBase && ap_md_share_data.FileShareMemBase!= 0)
        min_addr = ap_md_share_data.FileShareMemBase;

    if ( min_addr > ap_md_share_data.PmicShareMemBase && ap_md_share_data.PmicShareMemBase!= 0)
        min_addr = ap_md_share_data.PmicShareMemBase;

    if ( min_addr > ap_md_share_data.UartShareMemBase[0] && ap_md_share_data.UartShareMemBase[0]!= 0)
        min_addr = ap_md_share_data.UartShareMemBase[0];

    if ( min_addr > ap_md_share_data.UartShareMemBase[1] && ap_md_share_data.UartShareMemBase[1]!= 0)
        min_addr = ap_md_share_data.UartShareMemBase[1];


    if ( min_addr > ap_md_share_data.UartShareMemBase[2] && ap_md_share_data.UartShareMemBase[2]!= 0)
        min_addr = ap_md_share_data.UartShareMemBase[2];

    if ( min_addr > ap_md_share_data.UartShareMemBase[3] && ap_md_share_data.UartShareMemBase[3]!= 0)
        min_addr = ap_md_share_data.UartShareMemBase[3];

    if ( min_addr > ap_md_share_data.UartShareMemBase[4] && ap_md_share_data.UartShareMemBase[4]!= 0)
        min_addr = ap_md_share_data.UartShareMemBase[4];

    if ( min_addr > ap_md_share_data.UartShareMemBase[5] && ap_md_share_data.UartShareMemBase[5]!= 0)
        min_addr = ap_md_share_data.UartShareMemBase[5];

    if ( min_addr > ap_md_share_data.RpcShareMemBase && ap_md_share_data.RpcShareMemBase!= 0)
        min_addr = ap_md_share_data.RpcShareMemBase;

    if ( min_addr > ap_md_share_data.ExceShareMemBase && ap_md_share_data.ExceShareMemBase!= 0)
        min_addr = ap_md_share_data.ExceShareMemBase;

    if ( min_addr > ap_md_share_data.SysShareMemBase && ap_md_share_data.SysShareMemBase!= 0)
        min_addr = ap_md_share_data.SysShareMemBase;

    if ( min_addr > ap_md_share_data.IPCShareMemBase && ap_md_share_data.IPCShareMemBase!= 0)
        min_addr = ap_md_share_data.IPCShareMemBase;

#if defined(CCCI_INIT_HANDSHAKE_MODE1)
    if ( min_addr > ap_md_share_data.MiscInfoBase && ap_md_share_data.MiscInfoBase!= 0)
        min_addr = ap_md_share_data.MiscInfoBase;

    if ( min_addr > ap_md_share_data.IPCMDIlmShareMemBase && ap_md_share_data.IPCMDIlmShareMemBase!= 0)
        min_addr = ap_md_share_data.IPCMDIlmShareMemBase;

    if ( min_addr > ap_md_share_data.MDULNetShareMemBase && ap_md_share_data.MDULNetShareMemBase)
        min_addr = ap_md_share_data.MDULNetShareMemBase;

    if ( min_addr > ap_md_share_data.MDDLNetShareMemBase && ap_md_share_data.MDDLNetShareMemBase)
        min_addr = ap_md_share_data.MDDLNetShareMemBase;

    if ( min_addr > ap_md_share_data.ExtMDExcepInfoBase && ap_md_share_data.ExtMDExcepInfoBase)
        min_addr = ap_md_share_data.ExtMDExcepInfoBase;

    for (i=0; i<ap_md_share_data.NetPortNum; i++)
    {
        if ( min_addr > ap_md_share_data.NetULCtrlShareMemBase[i] && ap_md_share_data.NetULCtrlShareMemBase[i])
            min_addr = ap_md_share_data.NetULCtrlShareMemBase[i];

        if ( min_addr > ap_md_share_data.NetDLCtrlShareMemBase[i] && ap_md_share_data.NetDLCtrlShareMemBase[i])
            min_addr = ap_md_share_data.NetDLCtrlShareMemBase[i];
    }
#endif

    if ( max_addr < ap_md_share_data.MdlogShareMemBase + ap_md_share_data.MdlogShareMemSize)
        max_addr = ap_md_share_data.MdlogShareMemBase + ap_md_share_data.MdlogShareMemSize;

    if ( max_addr < ap_md_share_data.PcmShareMemBase + ap_md_share_data.PcmShareMemSize)
        max_addr = ap_md_share_data.PcmShareMemBase + ap_md_share_data.PcmShareMemSize;

    if ( max_addr < ap_md_share_data.FileShareMemBase + ap_md_share_data.FileShareMemSize)
        max_addr = ap_md_share_data.FileShareMemBase + ap_md_share_data.FileShareMemSize;

    if ( max_addr < ap_md_share_data.PmicShareMemBase + ap_md_share_data.PmicShareMemSize)
        max_addr = ap_md_share_data.PmicShareMemBase + ap_md_share_data.PmicShareMemSize;

    if ( max_addr < ap_md_share_data.UartShareMemBase[0] + ap_md_share_data.UartShareMemSize[0])
        max_addr = ap_md_share_data.UartShareMemBase[0] + ap_md_share_data.UartShareMemSize[0];

    if ( max_addr < ap_md_share_data.UartShareMemBase[1] + ap_md_share_data.UartShareMemSize[1])
        max_addr = ap_md_share_data.UartShareMemBase[1] + ap_md_share_data.UartShareMemSize[1];

    if ( max_addr < ap_md_share_data.UartShareMemBase[2] + ap_md_share_data.UartShareMemSize[2])
        max_addr = ap_md_share_data.UartShareMemBase[2] + ap_md_share_data.UartShareMemSize[2];

    if ( max_addr < ap_md_share_data.UartShareMemBase[3] + ap_md_share_data.UartShareMemSize[3])
        max_addr = ap_md_share_data.UartShareMemBase[3] + ap_md_share_data.UartShareMemSize[3];

    if ( max_addr < ap_md_share_data.UartShareMemBase[4] + ap_md_share_data.UartShareMemSize[4])
        max_addr = ap_md_share_data.UartShareMemBase[4] + ap_md_share_data.UartShareMemSize[4];

    if ( max_addr < ap_md_share_data.UartShareMemBase[5] + ap_md_share_data.UartShareMemSize[5])
        max_addr = ap_md_share_data.UartShareMemBase[5] + ap_md_share_data.UartShareMemSize[5];

    if ( max_addr < ap_md_share_data.ExceShareMemBase + ap_md_share_data.ExceShareMemSize)
        max_addr = ap_md_share_data.ExceShareMemBase + ap_md_share_data.ExceShareMemSize;

    if ( max_addr < ap_md_share_data.SysShareMemBase + ap_md_share_data.SysShareMemSize)
        max_addr = ap_md_share_data.SysShareMemBase + ap_md_share_data.SysShareMemSize;

    if ( max_addr < ap_md_share_data.IPCShareMemBase + ap_md_share_data.IPCShareMemSize)
        max_addr = ap_md_share_data.IPCShareMemBase + ap_md_share_data.IPCShareMemSize;

    if ( max_addr < ap_md_share_data.RpcShareMemBase + ap_md_share_data.RpcShareMemSize)
        max_addr = ap_md_share_data.RpcShareMemBase + ap_md_share_data.RpcShareMemSize;

#if defined(CCCI_INIT_HANDSHAKE_MODE1)
    if ( max_addr < ap_md_share_data.MiscInfoBase + ap_md_share_data.MiscInfoSize)
        max_addr = ap_md_share_data.MiscInfoBase + ap_md_share_data.MiscInfoSize;

    if ( max_addr < ap_md_share_data.IPCMDIlmShareMemBase + ap_md_share_data.IPCMDIlmShareMemSize)
        max_addr = ap_md_share_data.IPCMDIlmShareMemBase + ap_md_share_data.IPCMDIlmShareMemSize;

    if ( max_addr < ap_md_share_data.MDULNetShareMemBase + ap_md_share_data.MDULNetShareMemSize)
        max_addr = ap_md_share_data.MDULNetShareMemBase + ap_md_share_data.MDULNetShareMemSize;

    if ( max_addr < ap_md_share_data.MDDLNetShareMemBase + ap_md_share_data.MDDLNetShareMemSize)
        max_addr = ap_md_share_data.MDDLNetShareMemBase + ap_md_share_data.MDDLNetShareMemSize;

    if ( max_addr < ap_md_share_data.ExtMDExcepInfoBase + ap_md_share_data.ExtMDExcepInfoSize)
        max_addr = ap_md_share_data.ExtMDExcepInfoBase + ap_md_share_data.ExtMDExcepInfoSize;

    for (i=0; i<ap_md_share_data.NetPortNum ; i++)
    {
        if ( max_addr < ap_md_share_data.NetULCtrlShareMemBase[i] + ap_md_share_data.NetULCtrlShareMemSize[i])
            max_addr = ap_md_share_data.NetULCtrlShareMemBase[i] + ap_md_share_data.NetULCtrlShareMemSize[i];

        if ( max_addr < ap_md_share_data.NetDLCtrlShareMemBase[i] + ap_md_share_data.NetDLCtrlShareMemSize[i])
            max_addr = ap_md_share_data.NetDLCtrlShareMemBase[i] + ap_md_share_data.NetDLCtrlShareMemSize[i];
    }
#endif

    *size = max_addr - min_addr;
    *start_addr = min_addr;
    *end_addr = max_addr;
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
*  ccci_register_sysmsgsvc_callback
*
* DESCRIPTION
*  To provide user to register system message callback function in HISR LEVEL
*
* PARAMETERS
*  msgno   -	message number
*  funp    -    callback function
*
* RETURNS
*  KAL_FALSE : Fail
*  KAL_TURE  : Success
*
*************************************************************************/
kal_int32 ccci_register_sysmsgsvc_callback(kal_uint32 msgno, CCCI_SYSMSGSVC_HISR_CALLBACK funp)
{
    kal_uint32	value;

    if((msgno < CCMSG_ID_SYSMSGSVC_START) ||
            (msgno >= CCMSG_ID_SYSMSGSVC_END) ||
            (funp == NULL)
      )	return KAL_FALSE;

    value = msgno - CCMSG_ID_SYSMSGSVC_START;

    ccci_sysmsgsvc_cb[value] = funp;

    return KAL_TRUE;
}

/*************************************************************************
* FUNCTION
*  ccci_send_message
*
* DESCRIPTION
*  This function sends message to AP.
*
* PARAMETERS
*  message    	-
*  reserved		-
*
* RETURNS
*  KAL_TRUE 	: Success
*  KAL_FALSE	: Fail
*
*************************************************************************/
kal_bool ccci_send_message(kal_uint32 message, kal_uint32 reserved)
{
    kal_int32	ret;
    kal_int32	retry = 0xFFFF;
    CCCI_BUFF_T buff;

    if ( INT_QueryExceptionStatus() == KAL_TRUE ) retry = 7;

    CCCI_INIT_MAILBOX_WITH_RESERVED(&buff, message, reserved);

    do
    {
        ret = ccci_write(CCCI_SYSTEM_CHANNEL, &buff);
        if (ret == CCCI_SUCCESS)
        {
            return KAL_TRUE;
        }
        retry --;
    }
    while (retry > 0);

    //- physical channel full or other error
    if ( INT_QueryExceptionStatus() == KAL_FALSE )
    {
        ccci_debug_phychan_full = 1;
        EXT_ASSERT (0, ret, CCCI_SYSTEM_CHANNEL, message);
    }

    return KAL_FALSE;
}

#ifdef __SP_BOOTTRC_ENABLE__
/*************************************************************************
* FUNCTION
*  void ccci_boottrc_write_log_sharemem
*
* DESCRIPTION
*  This function is exported API to write bootup trace log in shared buffer.
*
* PARAMETERS
*  index - bootup trace log key.
*  value - bootup trace log value.
*
* RETURNS
*  NA
*
*************************************************************************/
void ccci_boottrc_write_log_sharemem(kal_uint32 index, kal_uint32 value)
{
    *((volatile kal_uint32 *)ccci_boottrc_buffer_ptr    ) = index;
    *((volatile kal_uint32 *)ccci_boottrc_buffer_ptr + 1) = value;
    
    ccci_boottrc_buffer_ptr += 8;

    //- wrap case
    if (ccci_boottrc_buffer_ptr == ccci_boottrc_buffer_addr + ccci_boottrc_buffer_size)
    {
        ccci_boottrc_buffer_ptr = ccci_boottrc_buffer_addr;
    }
    
    //- dummy read to drain out write buffer in CR4
    *((volatile kal_uint32*)ccci_boottrc_buffer_ptr);
}

/*************************************************************************
* FUNCTION
*  void ccci_boottrc_query_sharemem
*
* DESCRIPTION
*  This function is exported API to query address and size of bootup
*  trace in CCCI shared buffer.
*
* PARAMETERS
*  addr - pointer to address to hold address of bootup trace region.
*  size - pointer to size to hold size of bootup trace region.
*
* RETURNS
*  NA
*
*************************************************************************/
kal_int32 ccci_boottrc_query_sharemem(kal_uint32 *addr, kal_uint32 *size)
{
    if (NULL == addr || NULL == size)
        return CCCI_FAIL;
    
    *addr = ccci_boottrc_buffer_addr;
    *size = ccci_boottrc_buffer_size;

    return CCCI_SUCCESS;
}

/*************************************************************************
* FUNCTION
*  void ccci_boottrc_clear_sharemem
*
* DESCRIPTION
*  This function is exported API to clear memory used by boot-up trace.
*  The reason to clear this memory regioni is that this region will 
*  be used to store exception debug information.
*
* PARAMETERS
*  NA
*
* RETURNS
*  NA
*
*************************************************************************/
void ccci_boottrc_clear_sharemem()
{
    kal_mem_set((void*)ccci_boottrc_buffer_addr, 0, ccci_boottrc_buffer_size);
}
#endif    /* __SP_BOOTTRC_ENABLE__ */


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
void ccci_service_init(void)
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
    //don't need to initial ccif hw medium
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

    ccif_init(1);
    ccci_service_init();
    ccci_init(CCCI_FS_CHANNEL, CCCI_Invalid_Callback);
    ccci_init(CCCI_FS_ACK_CHANNEL, FS_CCCI_Callback);

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

#endif // __UPS_SUPPORT__

    uart_handle =  DclSerialPort_Open(uart_port_gps_ccci, 0);
    DclSerialPort_RegisterCallback(uart_handle, &CCCI_Uart_Drv_Handler);
}

#endif  /* __MODEM_CCCI_EXIST__ */
