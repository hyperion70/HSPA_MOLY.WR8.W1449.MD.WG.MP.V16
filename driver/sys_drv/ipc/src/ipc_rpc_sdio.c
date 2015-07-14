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
 *   ipc_rpc_sdio.c
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*******************************************************************************
 * Include header files
 *******************************************************************************/


#if defined(__MODEM_CCCI_EXIST__)
#if defined(__SMART_PHONE_MODEM__)

#include <stdarg.h>

#include "kal_public_api.h" //MSBB change #include "kal_release.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "kal_internal_api.h"
#include "syscomp_config.h"
#include "ccci.h"
#include "tst_trace.h"
#include "ipc_rpc.h"


#include "sdio_fw_api_public.h"
/*******************************************************************************
 * Define import global variables.
 *******************************************************************************/


/*******************************************************************************
 * Define import function prototype.
 *******************************************************************************/


/*******************************************************************************
 * Define global variables.
 *******************************************************************************/

IPC_RPC_StreamBuffer_T* IPC_RPC_REQ_BUF=NULL;



// separate variables in AP and MD sides
kal_uint32 IPC_RPC_ReadIndex = 0;
kal_uint32 IPC_RPC_WriteIndex = 0;
kal_uint32 IPC_RPC_BufCount = 0;
kal_semid  g_IPC_RPC_SemId = NULL;

/* Modem part */
PUBLIC kal_semid       g_IPC_RPC_CSSemId = NULL;
PUBLIC kal_eventgrpid  g_IPC_RPC_CSEvgrp = NULL;
PRIVATE kal_bool lock_RW = 1;

/* define critical section owner */
#define IPC_RPC_ENTER_CRITICAL_SECTION     if (KAL_TRUE == kal_query_systemInit()  || INT_QueryExceptionStatus() == KAL_TRUE) \
                                           {                                                                                  \
                                               lock_RW--;                                                                     \
                                           }                                                                                  \
                                           else                                                                               \
                                           {                                                                                  \
                                               kal_take_sem(g_IPC_RPC_CSSemId, KAL_INFINITE_WAIT);                            \
                                           }                                                                                  \
                                 
#define IPC_RPC_LEAVE_CRITICAL_SECTION     if (KAL_TRUE == kal_query_systemInit()  || INT_QueryExceptionStatus() == KAL_TRUE) \
                                           {                                                                                  \
                                               lock_RW++;                                                                     \
                                           }                                                                                  \
                                           else                                                                               \
                                           {                                                                                  \
                                               kal_give_sem(g_IPC_RPC_CSSemId);                                               \
                                           }                                                                                  \

/*************************************************************************
* FUNCTION
*  void IPC_RPC_Write
*
* DESCRIPTION
*
* PARAMETERS
*  *   
* RETURNS
*  NA
*
*************************************************************************/
PUBLIC kal_int32 IPC_RPC_CCCI_Write(kal_int32 *index, kal_uint32 op, IPC_RPC_LV_T *pLV, kal_uint32 num)
{
   kal_uint32 i, len = 0, tlen;
   kal_uint8 *ptr;
   IPC_RPC_LV_T *pTmp;
   kal_int32 windex = 0, ret = 0, retry = IPC_RPC_MAX_RETRY;
   #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
   kal_char debug_info[100];
   #endif
	

   IPC_RPC_ENTER_CRITICAL_SECTION;
   
   #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
   sprintf(debug_info, "in IPC_RPC_CCCI_Write .. \r\n");
   CCCI_TRACE(debug_info);
   #endif
   
   if ( INT_QueryExceptionStatus() == KAL_TRUE ) 
       retry = IPC_RPC_EXCEPT_MAX_RETRY;

   if (*index < 0)
   {
      if (IPC_RPC_BufCount == IPC_RPC_REQ_BUFFER_NUM)
      {
         IPC_RPC_LEAVE_CRITICAL_SECTION;
         return CCCI_FAIL;
      }

      for (i=0;i<IPC_RPC_REQ_BUFFER_NUM;i++) 
      {
          if (IPC_RPC_WriteIndex & (0x1 << i))
              continue;  /* the channel is used by others */
          else 
	  {
              windex = i; /* get a full channel */
              IPC_RPC_WriteIndex |=  (0x1 <<i); /* occupy the channel */
              break;
          }
      }
      
      if (IPC_RPC_REQ_BUFFER_NUM == i)
      {
	  #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
	  sprintf(debug_info, "over the count of IPC_RPC buffer .. \r\n");
	  CCCI_TRACE(debug_info);
          #endif
	  #if defined (__IPC_RPC_TEST__)
	  ASSERT(0);
	  #else
          kal_fatal_error_handler( KAL_ERROR_IPC_INTERNAL_FAILED, IPC_RPC_CCCI_WRITE_BUF_FUL);
	  #endif
      }

   }
   else
   {
      windex = *index;
   }
   
   IPC_RPC_REQ_BUF[windex].rpc_opid = op;
   ptr = IPC_RPC_REQ_BUF[windex].buffer;
   
   // entry count;
   pTmp = (IPC_RPC_LV_T *)ptr;
   pTmp->len = num;
   
   ptr += sizeof(kal_uint32);
   
   for(i = 0; i < num; i++)
   {  
       //CCCI_HAL_OVERHEAD is 16 in CCCI on SDIO, CCCI_HAL_OVERHEAD is 0 in CCCI on CCIF
       if ((ptr + 2 * sizeof(kal_uint32) + pLV[i].len ) > (IPC_RPC_REQ_BUF[windex].buffer + IPC_RPC_MAX_BUF_SIZE))
       {
	   #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
           sprintf(debug_info, "size over PRC shared buffer size in RPC_CCCI_Write .. \r\n");
	   CCCI_TRACE(debug_info);
           #endif
	   #if defined (__IPC_RPC_TEST__)
	   ASSERT(0); //for debug
	   #else
           kal_fatal_error_handler( KAL_ERROR_IPC_INTERNAL_FAILED, IPC_RPC_CCCI_WRITE_REQUEST);
	   #endif
       }
          
       pTmp = (IPC_RPC_LV_T *)ptr;

       pTmp->len = pLV[i].len;
       // adjusted to be 4-byte aligned
       tlen = ((pLV[i].len + 3) >> 2) << 2;
	  
       kal_mem_cpy(ptr + sizeof(kal_uint32), pLV[i].val, pLV[i].len);
          
       len += tlen;
       #if defined (__SDIO_DEVICE_CONNECTIVITY__)
       //including the Length attribute size
       len += sizeof(kal_uint32); 
       #endif
       ptr += sizeof(kal_uint32) + tlen;
   }
   
   do
   {
   #if defined (__SDIO_DEVICE_CONNECTIVITY__)
       IPC_RPC_REQ_BUF[windex].ccci_header.data[0] = (kal_uint32)(IPC_RPC_REQ_BUF+windex);
       //CCCI header + op_id + num + LV 
       IPC_RPC_REQ_BUF[windex].ccci_header.data[1] = CCCI_HAL_OVERHEAD + sizeof(kal_uint32)+ +sizeof(kal_uint32) + len;
       IPC_RPC_REQ_BUF[windex].ccci_header.reserved = windex;
       ret = ccci_write(CCCI_FS_CHANNEL, (CCCI_BUFF_T *)(IPC_RPC_REQ_BUF+windex));
   #else //for CCIF
       ret = ccci_stream_write_with_reserved(CCCI_IPC_RPC_CHANNEL, (kal_uint32)(IPC_RPC_REQ_BUF + windex), len + sizeof(kal_uint32),windex);	 
   #endif
       retry--;
   } while ((ret == CCCI_NO_PHY_CHANNEL) && (retry >= 0));
   
   if (ret == CCCI_NO_PHY_CHANNEL)
   {
       #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
       sprintf(debug_info, "CCCI_NO_PHY_CHANNEL in IPC_RPC_CCCI_Write .. \r\n");
       CCCI_TRACE(debug_info);
       #endif
       #if defined (__IPC_RPC_TEST__)
       ASSERT(0);
       #else
       kal_fatal_error_handler(KAL_ERROR_IPC_INTERNAL_FAILED, IPC_RPC_CCCI_WRITE_NO_PHYSICAL_CHANNEL);
       #endif
   }

   if (ret == CCCI_SUCCESS)
   {
       if (*index < 0)
       {
           /* only MD will get in */
	   *index = windex;
           IPC_RPC_BufCount++;
       }
   }
   
   IPC_RPC_LEAVE_CRITICAL_SECTION;

   return ret;
}

/*************************************************************************
* FUNCTION
*  void IPC_RPC_Read
*
* DESCRIPTION
*
* PARAMETERS
*  *   
* RETURNS
*  NA
*
*************************************************************************/
PUBLIC kal_int32 IPC_RPC_CCCI_Read(kal_int32 index, kal_uint32 op, IPC_RPC_LV_T *pLV, kal_uint32 *num)
{
   kal_uint32 i, no_copy = 0;
   kal_uint8 *ptr;
   IPC_RPC_LV_T *pTmp;

   #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
   kal_char debug_info[100];
   #endif
   
   IPC_RPC_ENTER_CRITICAL_SECTION;
 	
   #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
   sprintf(debug_info, "in IPC_RPC_CCCI_Read .. \r\n");
   CCCI_TRACE(debug_info);
   #endif
   
   if (!op && (IPC_RPC_BufCount == 0))
   {
      IPC_RPC_LEAVE_CRITICAL_SECTION;
      return CCCI_FAIL;
   }

   if (op && (IPC_RPC_REQ_BUF[index].rpc_opid != (IPC_RPC_API_RESP_ID | op)))
   {
      #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
      sprintf(debug_info, "the mismatch op id in IPC_RPC_CCCI_Read .. \r\n");
      CCCI_TRACE(debug_info);
      #endif
      #if defined (__IPC_RPC_TEST__)
      ASSERT(0);
      #else
      kal_fatal_error_handler(KAL_ERROR_IPC_INTERNAL_FAILED, IPC_RPC_CCCI_READ_OPID_NOT_SYNC);
      #endif
   }

   ptr = IPC_RPC_REQ_BUF[index].buffer;
   
   // entry count
   pTmp = (IPC_RPC_LV_T *)ptr;

   if (op)
   {
      if (*num != pTmp->len)
      {
	   #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
     	   sprintf(debug_info, "the mismatch num in IPC_RPC_CCCI_READ .. \r\n");
	   CCCI_TRACE(debug_info);
      	   #endif
	   #if defined (__IPC_RPC_TEST__)
	   ASSERT(0);
	   #else
           kal_fatal_error_handler(KAL_ERROR_IPC_INTERNAL_FAILED, IPC_RPC_CCCI_READ_RESULT_NO_NOT_SYNC);
	   #endif
      }
   }
   else
   {
      *num = pTmp->len;
      no_copy = 1;
   }
   
   ptr += sizeof(kal_uint32);
   for(i = 0; i < *num; i++)
   {
      pTmp = (IPC_RPC_LV_T *)ptr;

      if (op && (pLV[i].len < pTmp->len))
      {
	   #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
	   sprintf(debug_info, "buffer overflow in IPC_RPC_CCCI_READ .. \r\n");
	   CCCI_TRACE(debug_info);
      	   #endif
	   #if defined (__IPC_RPC_TEST__)
	   ASSERT(0);
	   #else
	   kal_fatal_error_handler(KAL_ERROR_IPC_INTERNAL_FAILED, IPC_RPC_CCCI_READ_RESULT_LEN_NOT_ENOUGH);
	   #endif
      }

      pLV[i].len = pTmp->len;
      if (no_copy)
      {
         pLV[i].val = (void *)(ptr + sizeof(kal_uint32));
      }
      else
      {
         kal_mem_cpy(pLV[i].val, ptr + sizeof(kal_uint32), pLV[i].len);
      }

      // adjusted to be 4-byte aligned
      ptr += sizeof(kal_uint32) + (((pTmp->len + 3) >> 2) << 2);
   }
   
   if (!no_copy)
   {
      IPC_RPC_WriteIndex &= ~( 0x1 << index);   
      IPC_RPC_BufCount--;
   }

   IPC_RPC_LEAVE_CRITICAL_SECTION;

   return CCCI_SUCCESS;
}

/*************************************************************************
* FUNCTION
*  void IPC_RPC_Callback
*
* DESCRIPTION
*
* PARAMETERS
*  buff -    
* RETURNS
*  NA
*
*************************************************************************/
PRIVATE void IPC_RPC_Callback(CCCI_BUFF_T *buff)
{
   kal_uint32 addr = CCCI_STREAM_ADDR(buff);
//   kal_uint32 IPC_RPC_OPINDEX = buff->reserved;
   #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
   kal_char debug_info[100];
   #endif
   /* Modem */
	
   #if defined (__SDIO_DEVICE_CONNECTIVITY__)
   //copy memory to MD
   //the buff include the ccci header, we should copy the data to shared memory only
   kal_mem_cpy((kal_uint32*)(IPC_RPC_REQ_BUF + buff->reserved), (kal_uint32*)buff, buff->data[1]);
   //release the memory pool to SDIO driver
   #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
   sprintf(debug_info, "release buff address = %x in IPC_RPC_CCCI_Callback .. \r\n");
   CCCI_TRACE(debug_info);
   #endif
   sdio_recycle_single_buffer(get_ngio_handle(), (kal_uint32)buff);		  
   #endif

   if (addr != (kal_uint32)(IPC_RPC_REQ_BUF + buff->reserved))
   {
       #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
       sprintf(debug_info, "AP return the unexpected buffer start address .. \r\n");
       CCCI_TRACE(debug_info);
       #endif
       #if defined (__IPC_RPC_TEST__)
       ASSERT(0);
       #else
       kal_fatal_error_handler(KAL_ERROR_IPC_INTERNAL_FAILED, IPC_RPC_CCCI_CALLBACK_ADDR_NOT_SYNC);
       #endif
   }
   kal_set_eg_events(g_IPC_RPC_CSEvgrp,  (1<< (buff->reserved)) , KAL_OR);
}

/*************************************************************************
* FUNCTION
*  void ipc_rpc_init
*
* DESCRIPTION
*
* PARAMETERS
*  *   
* RETURNS
*  NA
*
*************************************************************************/
PUBLIC void ipc_rpc_init(void)
{
   g_IPC_RPC_CSEvgrp = kal_create_event_group("IPC_DRV");
   g_IPC_RPC_CSSemId = kal_create_sem("IPC_RPCCS", 1);
   ccci_init(CCCI_IPC_RPC_CHANNEL, IPC_RPC_Callback);
   ccci_init(CCCI_IPC_RPC_ACK_CHANNEL, IPC_RPC_Callback);

   IPC_RPC_REQ_BUF = (IPC_RPC_StreamBuffer_T *) ap_md_share_data.RpcShareMemBase;
}

#endif /* __SMART_PHONE_MODEM__ */
#endif /* __MODEM_CCCI_EXIST__ */
