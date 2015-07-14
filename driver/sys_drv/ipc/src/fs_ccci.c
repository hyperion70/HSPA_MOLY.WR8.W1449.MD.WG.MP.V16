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
 *   fs_ccci.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This function implements file system adaptation layer with CCCI interfaces.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*******************************************************************************
 * Include header files
 *******************************************************************************/


#if defined(__MODEM_CCCI_EXIST__)

#include <stdarg.h>
#include "kal_public_api.h"
#include "tst_trace.h"
#include "kal_trace.h"

#include "ccci.h"
#include "ccif.h"
#include "ccci_int.h"

#include "fs_type.h"
#include "fs_ccci.h"
#include "ccci_fssvc.h"

#include "us_timer.h"

/********************************************************************************
 * Define import global variables.
 ********************************************************************************/
extern kal_bool  ccci_debug_phychan_full;

/*******************************************************************************
 * Define import function prototype.
 *******************************************************************************/


/*******************************************************************************
 * Define global variables.
 *******************************************************************************/

pFS_StreamBuffer_T FS_REQ_BUF[FS_CCCI_REQ_BUFFER_NUM];

// separate variables in AP and MD sides
kal_uint32 FS_ReadIndex = 0;
kal_uint32 FS_WriteIndex = 0;
kal_uint32 FS_CCCIBufCount = 0;
kal_semid gFS_CCCI_SemId = NULL;

kal_uint32 FS_ShareBuffer_BlockSize;
kal_uint32 FS_Max_index = 0;
volatile kal_uint32 FS_SystemInit_WaitAP = 0;

extern kal_bool kal_query_systemInit(void);
extern kal_bool INT_QueryExceptionStatus(void);

static kal_int32 FS_CCCI_Write(kal_int32 *index, kal_uint32 op, FS_CCCI_LV_T *pLV, kal_uint32 num);
static kal_int32 FS_CCCI_Read(kal_int32 index, kal_uint32 op, FS_CCCI_LV_T *pLV, kal_uint32 *num);


/* Modem */
kal_semid gFS_CCCI_CSSemId = NULL;
kal_eventgrpid gFS_CCCI_CSEvgrp = NULL;
static kal_bool lock_RW = (kal_bool)1;


#define FS_CCCI_ENTER_CRITICAL_SECTION     if (KAL_TRUE == kal_query_systemInit()  || INT_QueryExceptionStatus() == KAL_TRUE) \
                                           {                                                                                  \
                                              lock_RW--;                                                                      \
                                           }                                                                                  \
                                           else                                                                               \
                                           {                                                                                  \
                                              kal_take_sem(gFS_CCCI_CSSemId, KAL_INFINITE_WAIT);                              \
                                           }

#define FS_CCCI_LEAVE_CRITICAL_SECTION     if (KAL_TRUE == kal_query_systemInit()  || INT_QueryExceptionStatus() == KAL_TRUE) \
                                           {                                                                                  \
                                              lock_RW++;                                                                      \
                                           }                                                                                  \
                                           else                                                                               \
                                           {                                                                                  \
                                              kal_give_sem(gFS_CCCI_CSSemId);                                                 \
                                           }

/*************************************************************************
* FUNCTION
*  FS_Process_CMD
*
* DESCRIPTION
*  This function use to retrieve event from index
*
*
* PARAMETERS
*  *
* RETURNS
*  retrived status
*
*************************************************************************/
void FS_Process_CMD(kal_int32 index)
{
    kal_status ev_result = KAL_NOT_PRESENT;
    kal_uint32 retrieved_events =0;

    if (KAL_TRUE == kal_query_systemInit() )
    {
        volatile kal_uint32 time0, time1;
        time0 = ust_get_current_time();
        
        while (ev_result == KAL_NOT_PRESENT)
        {
            ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME,  &retrieved_events, KAL_NO_SUSPEND);
            if (KAL_SUCCESS != ev_result)
            {
                while ( 0x0 == *MDCCIF_RCHNUM)
                {
                    time1 = ust_get_duration(time0, ust_get_current_time()) + FS_SystemInit_WaitAP;
                    ccci_excep_dbg_logging_InHS2(CCCI_EXCEP_DBG_HS_FS_WAIT_TIME, (void*)&time1);
                }
                
                ccif_lisr();
            }
            else
            {
                break;
            }
        }

        FS_SystemInit_WaitAP = time1;
    }
    else if (INT_QueryExceptionStatus() == KAL_TRUE)
    {
        while ( KAL_FALSE == ccci_chk_recentry_in_queue(CCCI_FS_ACK_CHANNEL, KAL_TRUE));
    }
    else
    {
        ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME ,  &retrieved_events, KAL_SUSPEND);
    }

}

/*************************************************************************
* FUNCTION
*  FS_CCCI_Wrapper
*
* DESCRIPTION
*  This function use to handle real FS between AP/MD
*
*
* PARAMETERS
*  *
* RETURNS
*  NA
*
*************************************************************************/

kal_int32 FS_CCCI_Wrapper(FS_CCCI_OP_ID_T fs_op,...)
{
    kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
    FS_CCCI_LV_T LV[FS_CCCI_MAX_ARG_NUM];
    kal_int32 ret, count = 0 , size_val = 0;
    kal_uint32 num = 0;
    va_list ap;

    /* Start to fill the input paramter */
    va_start(ap, fs_op);
    while ( (size_val = va_arg(ap,int)) != FS_CCCI_EOF_TERM_PATTERN  )
    {
        /* If terminate pattern is found, that means the input is end */
        if (size_val == FS_CCCI_INPUT_TERM_PATTERN)
        {
            break;
        }

        if (count >= FS_CCCI_MAX_ARG_NUM)
        {
            EXT_ASSERT( 0, FS_CCCI_ERROR_USER_INPUT_PARAM_FULL, fs_op, count);
        }

        LV[count].len = (kal_uint32)size_val;
        LV[count++].val = (void *)(va_arg(ap,void *));
    }

    /* Pass the parameter to share memory */
    ret = FS_CCCI_Write(&index, fs_op, LV, count); // FS_Read request

    /* Chceck the result */
    if (ret != CCCI_SUCCESS)
    {
        return ret;
    }

    /* Wait for AP response the RPC is finished */
    FS_Process_CMD(index);

    //bypass the void MD_FS_ShutDown(void)
    if(fs_op != FS_CCCI_OP_SHUTDOWN)
    {
        /* fill the resturen code */
        LV[num].len = sizeof(kal_int32);
        LV[num++].val = (void *)&count;
    }

    /* Start to get the return parameter */
    while ( (size_val = va_arg(ap,int)) != FS_CCCI_EOF_TERM_PATTERN )
    {
        if (num >= FS_CCCI_MAX_ARG_NUM)
        {
            EXT_ASSERT( 0, FS_CCCI_ERROR_USER_OUTPUT_PARAM_FULL, fs_op, num);
        }

        LV[num].len = (kal_uint32)size_val;
        LV[num++].val = (void *)(va_arg(ap,void *));

    }

    /* Get the return information */
    ret = FS_CCCI_Read(index, fs_op, LV, &num);

    if (ret != CCCI_SUCCESS)
    {
        return ret;
    }
    else
    {
        return count;
    }

}

kal_uint8 fs_ccci_string[5][8] = {"CCCI:0", "CCCI:1", "CCCI:2", "CCCI:3", "CCCI:4"};
static kal_int32 FS_CCCI_Write(kal_int32 *index, kal_uint32 op, FS_CCCI_LV_T *pLV, kal_uint32 num)
{
    kal_uint32 i, len = 0, tlen;
    kal_uint8 *ptr;
    kal_uint8 *ptr_buf_boundary;
    FS_CCCI_LV_T *pTmp;
    kal_int32 ret, retry;
    kal_int32 windex = FS_CCCI_USE_DEFAULT_INDEX; //- avoid warning : windex may be used before being set
    kal_uint32 start_time, current_time;

    FS_CCCI_ENTER_CRITICAL_SECTION;

    if ( INT_QueryExceptionStatus() == KAL_TRUE ) retry = FS_CCCI_EXCEPT_MAX_RETRY;

    if (*index < 0)
    {
        if (FS_CCCIBufCount >= FS_CCCI_REQ_BUFFER_NUM)
        {
            FS_CCCI_LEAVE_CRITICAL_SECTION;
            return FS_CCCI_ERROR_SHARE_BUFFER_UNAVALIABLE;
        }

        for (i=0; i<FS_CCCI_REQ_BUFFER_NUM; i++)
        {
            if (FS_WriteIndex & (0x1 << i))
                continue;  /* KC: the channel is used by others */
            else
            {
                windex = i; /* KC: get a full channel */
                FS_WriteIndex |=  (0x1 <<i); /* KC: occupy the channel */
                if (i >= FS_Max_index)
                {
                    FS_Max_index = i;
                    kal_buffer_trace(TRACE_INFO, TR_BUFFER_TRACE, 8, fs_ccci_string[i]);
                }
                break;
            }
        }

        if (FS_CCCI_REQ_BUFFER_NUM == i)
        {
            EXT_ASSERT( 0, FS_CCCI_ERROR_WRITE_BUFFER_FULL, op, FS_WriteIndex);
        }


    }
    else
    {
        windex = *index;
    }


    ptr_buf_boundary = (kal_uint8*)(FS_REQ_BUF[windex]) + FS_ShareBuffer_BlockSize;
    FS_REQ_BUF[windex]->fs_operationID	= op;
    FS_REQ_BUF[windex]->num      		= num;
    //- point to LV[0]
    ptr = (kal_uint8*)FS_REQ_BUF[windex] + 2*sizeof(kal_uint32);
    for(i = 0; i < num; i++)
    {
        // adjusted to be 4-byte aligned
        tlen = ((pLV[i].len + 3) >> 2) << 2;

        if ((ptr + sizeof(kal_uint32) + tlen) > ptr_buf_boundary)
        {
            EXT_ASSERT( 0, FS_CCCI_ERROR_INPUT_PARAM_LEN_TO_LONG, op, FS_ShareBuffer_BlockSize);
        }

        //- point to LV[i]
        pTmp = (FS_CCCI_LV_T *)ptr;

        pTmp->len = pLV[i].len;
        kal_mem_cpy(ptr + sizeof(kal_uint32), pLV[i].val, pLV[i].len);

        //- adjust pointer to LV[i+1]
        ptr += sizeof(kal_uint32) + tlen;
    }

    len = (kal_uint32)(ptr - (kal_uint8*)(FS_REQ_BUF[windex]));

    start_time = ust_get_current_time();
    do {
        ret = ccci_stream_write_with_reserved(CCCI_FS_CHANNEL, (kal_uint32)(FS_REQ_BUF[windex]), len + sizeof(kal_uint32),windex);
        if ( CCCI_NO_PHY_CHANNEL == ret )
        {
            current_time = ust_get_current_time();
            if ( ust_get_duration(start_time, current_time) > FS_CCCI_SEND_RETRY )
            {
                ccci_debug_phychan_full = 1;
                EXT_ASSERT(0, FS_CCCI_ERROR_WRITE_NO_PHYSICAL_CHANNEL, 0, 0);
            }

            if ( INT_QueryExceptionStatus() == KAL_TRUE )
            {
                retry--;
                if ( retry == 0 )
                    break;
            }
        }
    } while( CCCI_NO_PHY_CHANNEL == ret );

    if (ret == CCCI_SUCCESS)
    {
        if (*index < 0)
        {
            /* only MD will get in */
            *index = windex;

            //*index = FS_WriteIndex;
            //FS_CCCI_INC_BUF_INDEX(FS_WriteIndex);
            FS_CCCIBufCount++;
        }
    }

    FS_CCCI_LEAVE_CRITICAL_SECTION;

    return ret;
}

static kal_int32 FS_CCCI_Read(kal_int32 index, kal_uint32 op, FS_CCCI_LV_T *pLV, kal_uint32 *num)
{
    kal_uint32 i, no_copy = 0;
    kal_uint8 *ptr;
    kal_uint32 num_read;
    kal_uint32 value1;
    kal_uint32 value2;
    FS_CCCI_LV_T *pTmp;


    FS_CCCI_ENTER_CRITICAL_SECTION;

    if (!op && (FS_CCCIBufCount == 0))
    {
        FS_CCCI_LEAVE_CRITICAL_SECTION;
        return FS_CCCI_ERROR_BUFCOUNT_ZERO;
    }

    value1 = FS_CCCI_API_RESP_ID | op;
    value2 = FS_REQ_BUF[index]->fs_operationID;
    if (op && (value1 != value2))
    {
        EXT_ASSERT( 0, FS_CCCI_ERROR_RETURN_OPID_NOT_SYNC, value1, value2);
    }

    num_read = FS_REQ_BUF[index]->num;
    if (op)
    {
        if (*num != num_read)
        {
            EXT_ASSERT( 0, FS_CCCI_ERROR_RETURN_PARAM_NUM_MISMATCH, op, num_read);
        }
    }
    else
    {
        *num = num_read;
        no_copy = 1;
    }

    //- point to LV[0]
    ptr = (kal_uint8*)FS_REQ_BUF[index] + 2*sizeof(kal_uint32);
    for(i = 0; i < *num; i++)
    {
        //- point to LV[i];
        pTmp = (FS_CCCI_LV_T *)ptr;

        value1 = pTmp->len;
        if (op && (pLV[i].len < value1))
        {
            EXT_ASSERT( 0, FS_CCCI_ERROR_RETURN_PARAMX_LEN_TO_LONG, pLV[i].len, value1);
        }

        pLV[i].len = value1;
        if (no_copy)
        {
            pLV[i].val = (void *)(ptr + sizeof(kal_uint32));
        }
        else
        {
            kal_mem_cpy(pLV[i].val, ptr + sizeof(kal_uint32), pLV[i].len);
        }

        // adjusted to be 4-byte aligned
        ptr = ptr + (sizeof(kal_uint32) + (((value1 + 3) >> 2) << 2));
    }

    if (!no_copy)
    {

        FS_WriteIndex &= ~( 0x1 << index);

        //FS_CCCI_INC_BUF_INDEX(FS_ReadIndex);
        FS_CCCIBufCount--;
    }

    FS_CCCI_LEAVE_CRITICAL_SECTION;

    return CCCI_SUCCESS;
}


void FS_CCCI_Callback(CCCI_BUFF_T *buff)
{
    kal_uint32 addr = CCCI_STREAM_ADDR(buff);
    kal_uint32 FS_OPINDEX = buff->reserved;

    /* Modem */
    if (addr != (kal_uint32)(FS_REQ_BUF[FS_OPINDEX]))
    {
        EXT_ASSERT( 0, FS_CCCI_ERROR_RETURN_BASEADDR_NOT_SYNC, addr, (kal_uint32)(FS_REQ_BUF[FS_OPINDEX]));
    }

    kal_set_eg_events(gFS_CCCI_CSEvgrp,  (1<< (FS_OPINDEX)) , KAL_OR);


}

void FS_CCCI_Init(void)
{

    kal_int32	i;
    kal_uint32	size;
    kal_uint8*   ptr;




    size = (ap_md_share_data.FileShareMemSize / FS_CCCI_REQ_BUFFER_NUM);
    ptr = (kal_uint8 *) (ap_md_share_data.FileShareMemBase);
    for (i=0; i<FS_CCCI_REQ_BUFFER_NUM; i++)
    {
        FS_REQ_BUF[i]		= (FS_StreamBuffer_T *)(ptr);
        ptr += size;
    }
    FS_ShareBuffer_BlockSize = size;


    gFS_CCCI_CSEvgrp = kal_create_event_group("FS_DRV");

    /* Modem */
    gFS_CCCI_CSSemId = kal_create_sem("FS_DRVCS", 1);

}

#endif /* __MODEM_CCCI_EXIST__ */

