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
 *   fs_ccci_sdio.c
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
#if defined(__SMART_PHONE_MODEM__)

#include <stdarg.h>

//#define __FS_CCCI_UT__

#include "kal_public_api.h" //MSBB change #include "kal_release.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "kal_internal_api.h"
#include "reg_base.h"
#include "syscomp_config.h"
#include "fs_type.h"
#include "fs_ccci.h"
#include "ccci.h"


#include "sdio_fw_api_public.h"
/*******************************************************************************
 * Define global variables.
 *******************************************************************************/

//- add to narrow down NVRAM fatal 
kal_uint32	FS_opcode_history[DebugEntryNo][3];
kal_uint32	FS_opcode_history_idx;
//- end


FS_StreamBuffer_T* FS_REQ_BUF=NULL;


// separate variables in AP and MD sides
kal_uint32 FS_ReadIndex = 0;
kal_uint32 FS_WriteIndex = 0;
kal_uint32 FS_CCCIBufCount = 0;
kal_semid gFS_CCCI_SemId = NULL;

//extern kal_bool kal_query_systemInit(void);
//extern kal_bool INT_QueryExceptionStatus(void);


/* Modem */
kal_semid gFS_CCCI_CSSemId = NULL;
kal_eventgrpid gFS_CCCI_CSEvgrp = NULL;
static kal_bool lock_RW=1;


#define FS_CCCI_ENTER_CRITICAL_SECTION     if (KAL_TRUE == kal_query_systemInit()  || INT_QueryExceptionStatus() == KAL_TRUE) \
                                           {                                                                                  \
                                              lock_RW--;                                                                      \
                                           }                                                                                  \
                                           else                                                                               \
                                           {                                                                                  \
                                              kal_take_sem(gFS_CCCI_CSSemId, KAL_INFINITE_WAIT);                              \
                                           }                                                                                  \
                                 
#define FS_CCCI_LEAVE_CRITICAL_SECTION     if (KAL_TRUE == kal_query_systemInit()  || INT_QueryExceptionStatus() == KAL_TRUE) \
                                           {                                                                                  \
                                              lock_RW++;                                                                      \
                                           }                                                                                  \
                                           else                                                                               \
                                           {                                                                                  \
                                              kal_give_sem(gFS_CCCI_CSSemId);                                                 \
                                           }                                                                                  \

/*************************************************************************
* FUNCTION
*  kal_int32 FS_CCCI_Write
*
* DESCRIPTION
*  This function is to write memory into FS shared buffer and though the HW medium tranfer shared data to AP side .
*
* PARAMETERS
*  index - indicate used shared buffer
*  op - the operation
*  pLV - the structure pointer of length and value
*  num - the sets of LV
*     
* RETURNS
*  the status
*
*************************************************************************/
PRIVATE kal_int32 FS_CCCI_Write(kal_int32 *index, kal_uint32 op, FS_CCCI_LV_T *pLV, kal_uint32 num)
{
   kal_uint32 i, len = 0, tlen;
   kal_uint8 *ptr;
   FS_CCCI_LV_T *pTmp;
   kal_int32 windex=0, ret, retry = FS_CCCI_MAX_RETRY;
   #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
   kal_char debug_info[100];
   #endif

   FS_CCCI_ENTER_CRITICAL_SECTION;
  
   #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
   sprintf(debug_info, "op id = %x in FS_CCCI_Write .. \r\n", op);
   CCCI_TRACE(debug_info);
   #endif
   if ( INT_QueryExceptionStatus() == KAL_TRUE ) 
       retry = FS_CCCI_EXCEPT_MAX_RETRY;

   if (*index < 0)
   {
      if (FS_CCCIBufCount == FS_CCCI_REQ_BUFFER_NUM)
      {
         FS_CCCI_LEAVE_CRITICAL_SECTION;
         return CCCI_FAIL;
      }

	  for (i=0;i<FS_CCCI_REQ_BUFFER_NUM;i++) 
	  {
	  	if (FS_WriteIndex & (0x1 << i))
			continue;  /*the channel is used by others */
		else 
		{
			windex = i; /* get a empty channel */
			FS_WriteIndex |=  (0x1 <<i); /* occupy the channel */
			break;
		}
	  }
   }
   else
   {
      windex = *index;
   }
   
   FS_REQ_BUF[windex].fs_operationID = op;
   ptr = FS_REQ_BUF[windex].buffer;
    
   // entry count;
   pTmp = (FS_CCCI_LV_T *)ptr;
   pTmp->len = num;
   
   ptr += sizeof(kal_uint32);
   
   for(i = 0; i < num; i++)
   {   
	  if ((ptr + 2 * sizeof(kal_uint32) + pLV[i].len ) > (FS_REQ_BUF[windex].buffer + FS_CCCI_MAX_BUF_SIZE))	
      {
		 #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		 	sprintf(debug_info, "size over FS shared buffer size in FS_CCCI_Write .. \r\n");
		 	CCCI_TRACE(debug_info);
   		 #endif
		 #if defined (__FS_TEST__)
		 ASSERT(0);//for debug
		 #else
		 kal_fatal_error_handler( KAL_ERROR_FILESYS_INTERNAL_FAILED, CCCI_INVALID_PARAM);
		 #endif
      }
	  
      pTmp = (FS_CCCI_LV_T *)ptr;

      pTmp->len = pLV[i].len;
      // adjusted to be 4-byte aligned
      tlen = ((pLV[i].len + 3) >> 2) << 2;
	  
      kal_mem_cpy(ptr + sizeof(kal_uint32), pLV[i].val, pLV[i].len);
	
      len += tlen;
	  #if defined (__SDIO_DEVICE_CONNECTIVITY__)
	  /* count the length attribute in transferred length */
	  len += sizeof(kal_uint32); 
	  #endif
      ptr += sizeof(kal_uint32) + tlen;
   }
   
   do
   {

#if defined (__SDIO_DEVICE_CONNECTIVITY__)
	FS_REQ_BUF[windex].ccci_header.data[0] = (kal_uint32)(FS_REQ_BUF+windex);
	/* CCCI header + op_id + num + LV  */
	FS_REQ_BUF[windex].ccci_header.data[1] = CCCI_HAL_OVERHEAD + sizeof(kal_uint32)+ sizeof(kal_uint32) + len;
	FS_REQ_BUF[windex].ccci_header.reserved = windex;
	ret = ccci_write(CCCI_FS_CHANNEL, (CCCI_BUFF_T *)(FS_REQ_BUF+windex));
#else //for CCIF
		ret = ccci_stream_write_with_reserved(CCCI_FS_CHANNEL, (kal_uint32)(FS_REQ_BUF + windex), len + sizeof(kal_uint32),windex); 
#endif
      retry--;
   } while ((ret == CCCI_NO_PHY_CHANNEL) && (retry >= 0));
   
   if (ret == CCCI_NO_PHY_CHANNEL)
   {
	  #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
	  	sprintf(debug_info, "CCCI_NO_PHY_CHANNEL in FS_CCCI_Write .. \r\n");
		CCCI_TRACE(debug_info);
 	  #endif
	  #if defined (__FS_TEST__)
	  ASSERT(0); //for debug
	  #else
      kal_fatal_error_handler(KAL_ERROR_FILESYS_INTERNAL_FAILED, CCCI_NO_PHY_CHANNEL);
	  #endif
   }

   if (ret == CCCI_SUCCESS)
   {
      if (*index < 0)
      {
	  	/* only MD will get in */
		*index = windex;
         FS_CCCIBufCount++;
      }
   }
   
   FS_CCCI_LEAVE_CRITICAL_SECTION;

   return ret;
}


/*************************************************************************
* FUNCTION
*  kal_int32 FS_CCCI_Read
*
* DESCRIPTION
*  This function is to read memory from FS shared buffer and though the HW medium get shared data from AP side .
*
* PARAMETERS
*  index - indicate used shared buffer
*  op - the operation
*  pLV - the structure pointer of length and value
*  num - the sets of LV
*     
* RETURNS
*  the status
*
*************************************************************************/
PRIVATE kal_int32 FS_CCCI_Read(kal_int32 index, kal_uint32 op, FS_CCCI_LV_T *pLV, kal_uint32 *num)
{
   kal_uint32 i, no_copy = 0;
   kal_uint8 *ptr;
   FS_CCCI_LV_T *pTmp;
   #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
	 kal_char debug_info[100];
   #endif
   
   FS_CCCI_ENTER_CRITICAL_SECTION;
   #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		 sprintf(debug_info, "in FS_CCCI_Read .. \r\n", op);
		 CCCI_TRACE(debug_info);
   #endif
   if (!op && (FS_CCCIBufCount == 0))
   {
      FS_CCCI_LEAVE_CRITICAL_SECTION;
      return CCCI_FAIL;
   }

   if (op && (FS_REQ_BUF[index].fs_operationID != (FS_CCCI_API_RESP_ID | op)))
   {
	  #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		 sprintf(debug_info, "the mismatch op id in FS_CCCI_Read .. \r\n");
		 CCCI_TRACE(debug_info);
   	  #endif
	  #if defined (__FS_TEST__)
	  ASSERT(0);
	  #else
	  kal_fatal_error_handler(KAL_ERROR_FILESYS_INTERNAL_FAILED, CCCI_NOT_OWNER);
	  #endif
   }
   
   ptr = FS_REQ_BUF[index].buffer;
   
   // entry count
   pTmp = (FS_CCCI_LV_T *)ptr;
   if (op)
   {
      if (*num != pTmp->len)
      {
		  #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		  sprintf(debug_info, "the mismatch num in FS_CCCI_Read .. \r\n");
		  CCCI_TRACE(debug_info);
   	      #endif
		  #if defined (__FS_TEST__)
		  ASSERT(0);
		  #else
		  kal_fatal_error_handler(KAL_ERROR_FILESYS_INTERNAL_FAILED, CCCI_INVALID_PARAM);
		  #endif
      }
   }
   else
   {
      *num = pTmp->len;
      no_copy = 1;
   }
   
   //bypass the num memory size
   ptr += sizeof(kal_uint32);
   for(i = 0; i < *num; i++)
   {
      pTmp = (FS_CCCI_LV_T *)ptr;

      if (op && (pLV[i].len < pTmp->len))
      {
		 #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		 sprintf(debug_info, "buffer overflow in FS_CCCI_Read .. \r\n");
		 CCCI_TRACE(debug_info);
   	     #endif
		 #if defined (__FS_TEST__)
		 ASSERT(0);
		 #else
         kal_fatal_error_handler(KAL_ERROR_FILESYS_INTERNAL_FAILED, CCCI_INVALID_PARAM);
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

      FS_WriteIndex &= ~( 0x1 << index);   

      //FS_CCCI_INC_BUF_INDEX(FS_ReadIndex);
      FS_CCCIBufCount--;
   }

   FS_CCCI_LEAVE_CRITICAL_SECTION;

   return CCCI_SUCCESS;
}


/*************************************************************************
* FUNCTION
*  void FS_CCCI_TX_Callback
*
* DESCRIPTION
*  This function is TX callback for SDIO medium
*
* PARAMETERS
*  buff - CCCI header
*     
* RETURNS
*  the status
*
*************************************************************************/
PUBLIC void FS_CCCI_TX_Callback(CCCI_BUFF_T *buff)
{
	#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		kal_char debug_info[100];
    #endif
	#if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		sprintf(debug_info, "release buff address = %x, data0 = %x, data1=%x, chann = %x, reserve = %x in FS_CCCI_TX_Callback .. \r\n", buff, buff->data[0], buff->data[1], buff->channel, buff->reserved);
		CCCI_TRACE(debug_info);
 	#endif
}


/*************************************************************************
* FUNCTION
*  void FS_CCCI_Callback
*
* DESCRIPTION
*  This function is RX callback for SDIO medium .
*
* PARAMETERS
*  buff - CCCI header
*     
* RETURNS
*  the status
*
*************************************************************************/
PUBLIC void FS_CCCI_Callback(CCCI_BUFF_T *buff)
{
   kal_uint32 addr = CCCI_STREAM_ADDR(buff);
   //kal_uint32 FS_OPINDEX = buff->reserved;
   #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
		kal_char debug_info[100];
   #endif
	
   /* Modem */
   #ifdef __SDIO_DEVICE_CONNECTIVITY__
   
	   //- add to narrow down NVRAM fatal 
	   if (!( FS_WriteIndex & (1 << (buff->reserved)) ))
	   {	//- invalid HISR, assert
			EXT_ASSERT (0, FS_WriteIndex, buff->reserved, (kal_uint32)buff);
	   }
   	   FS_opcode_history[FS_opcode_history_idx][0] = buff->reserved;			//- index
   	   FS_opcode_history[FS_opcode_history_idx][1] = *((kal_uint32*)buff);	    //- op_code
   	   FS_opcode_history[FS_opcode_history_idx][2] = buff->data[1];  			//- len
   	   FS_opcode_history_idx ++;
   	   if (FS_opcode_history_idx == DebugEntryNo)	FS_opcode_history_idx = 0;
   	   //- end

   	   //copy memory to MD
	   //the buff include the ccci header, we copy the buff content to shared memory
	   kal_mem_cpy((kal_uint32*)(FS_REQ_BUF + buff->reserved), (kal_uint32*)buff, buff->data[1]);
	   //release the memory pool to SDIO driver
	   #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
	   sprintf(debug_info, "release buff address = %x , data0 = %x, data1=%x, chann = %x, reserve = %x in FS_CCCI_Callback .. \r\n", buff, buff->data[0], buff->data[1], buff->channel, buff->reserved);
	   CCCI_TRACE(debug_info);
 	   #endif
	   sdio_recycle_single_buffer(get_ngio_handle(), (kal_uint32)buff);
   #endif
   
   //CCCI_HAL_OVERHEAD is 16 in CCCI on SDIO, CCCI_HAL_OVERHEAD is 0 in CCCI on CCIF
   if (addr != (kal_uint32)(FS_REQ_BUF + buff->reserved))
   {
	  #if defined (__CCCI_DEBUG_INFO__) || defined (__CCCI_IT_DEBUG_INFO__)
	  sprintf(debug_info, "AP return the unexpected buffer start address .. \r\n");
	  CCCI_TRACE(debug_info);
 	  #endif
	  #if defined (__FS_TEST__)
	  ASSERT(0);
	  #else
      kal_fatal_error_handler(KAL_ERROR_FILESYS_INTERNAL_FAILED, CCCI_NOT_OWNER);
	  #endif
   }

   kal_set_eg_events(gFS_CCCI_CSEvgrp,  (1<< (buff->reserved)) , KAL_OR);

   
}


/*************************************************************************
* FUNCTION
*  void FS_CCCI_Init
*
* DESCRIPTION
*  This function is to initialize FS service
*
* PARAMETERS
*  N/A
*     
* RETURNS
*  N/A
*
*************************************************************************/
PUBLIC void FS_CCCI_Init(void)
{
   FS_REQ_BUF = (FS_StreamBuffer_T *) (ap_md_share_data.FileShareMemBase);

   gFS_CCCI_CSEvgrp = kal_create_event_group("FS_DRV");
/* Modem */
   gFS_CCCI_CSSemId = kal_create_sem("FS_DRVCS", 1);

}

/* Modem */

/*************************************************************************
* FUNCTION
*  kal_int32 MD_FS_Open
*
* DESCRIPTION
*  This function is to open file
*
* PARAMETERS
*  
*     
* RETURNS
*  
*
*************************************************************************/
kal_int32 MD_FS_Open(const WCHAR * FileName, kal_uint32 Flag)
{
   kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
   FS_CCCI_LV_T LV[FS_CCCI_MAX_ARG_NUM];
   kal_int32 ret, count = 0;
   kal_uint32 num = 0;
   kal_status ev_result = KAL_NOT_PRESENT;//,sema_result =KAL_SEM_NOT_AVAILABLE;
   kal_uint32 retrieved_events =0;
   

   // FileName
   LV[count].len = kal_dchar_strlen((const char *)FileName) + sizeof(WCHAR);
   LV[count++].val = (void *)FileName;
   // Flag
   LV[count].len = sizeof(kal_uint32);
   LV[count++].val = (void *)&Flag;
   
   ret = FS_CCCI_Write(&index, FS_CCCI_OP_OPEN, LV, count); // FS_Read request
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }

   if (KAL_TRUE == kal_query_systemInit() ) 
   {
   		while (ev_result == KAL_NOT_PRESENT) 
		{
			//sema_result =   kal_take_sem(gFS_CCCI_SemId, KAL_NO_WAIT); // wait for an event;
			ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME, &retrieved_events, KAL_NO_SUSPEND);
			if (KAL_SUCCESS != ev_result)
			{
			#if defined (__SDIO_DEVICE_CONNECTIVITY__)
				//the query function from SDIO driver
				while (!sdio_query_txqueue_data_available(get_ngio_handle()));
				ccci_hisr();
			#else //for CCIF
				while ( 0x0 == *MDCCIF_RCHNUM);
	  			ccif_lisr();
			#endif	  		
			} 
			else 
			{
				break;
			}
		}
   } 
   else if (INT_QueryExceptionStatus() == KAL_TRUE) 
   {
   	#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			;//do nothing
		#else //CCIF
			while ( KAL_FALSE == ccci_chk_recentry_in_queue(CCCI_FS_ACK_CHANNEL, KAL_TRUE));
		#endif
   } 
   else 
   {
   	//kal_take_sem(gFS_CCCI_SemId, KAL_INFINITE_WAIT); // wait for an event;
		ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME, &retrieved_events, KAL_SUSPEND);
   }
   // return code
   LV[num].len = sizeof(kal_int32);
   LV[num++].val = (void *)&count;
   ret = FS_CCCI_Read(index, FS_CCCI_OP_OPEN, LV, &num);
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }
   else
   {
      return count;
   }
}


/*************************************************************************
* FUNCTION
*  kal_int32 MD_FS_OpenHint
*
* DESCRIPTION
*  This function is to open file
*
* PARAMETERS
*  
*     
* RETURNS
*  
*
*************************************************************************/
kal_int32 MD_FS_OpenHint(const WCHAR * FileName, kal_uint32 Flag, FS_FileOpenHint * DSR_Hint)
{
   kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
   FS_CCCI_LV_T LV[FS_CCCI_MAX_ARG_NUM];
   kal_int32 ret, count = 0;
   kal_uint32 num = 0;
   kal_status ev_result = KAL_NOT_PRESENT;//,sema_result =KAL_SEM_NOT_AVAILABLE;
   kal_uint32 retrieved_events =0;
	 

   // FileName
   LV[count].len = kal_dchar_strlen((const char *)FileName) + sizeof(WCHAR);
   LV[count++].val = (void *)FileName;
   // Flag
   LV[count].len = sizeof(kal_uint32);
   LV[count++].val = (void *)&Flag;
   // DSR_Hint
   LV[count].len = sizeof(FS_FileOpenHint);
   LV[count++].val = (void *)DSR_Hint;
   
   ret = FS_CCCI_Write(&index, FS_CCCI_OP_OPENHINT, LV, count); // FS_Read request
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }

   if (KAL_TRUE == kal_query_systemInit() ) 
   {
	  while (ev_result == KAL_NOT_PRESENT) 
	  {
	  	//sema_result =	 kal_take_sem(gFS_CCCI_SemId, KAL_NO_WAIT); // wait for an event;
	  	ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME,  &retrieved_events, KAL_NO_SUSPEND);
	  	if (KAL_SUCCESS != ev_result)
	  	{
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			while (!sdio_query_txqueue_data_available(get_ngio_handle()));
			ccci_hisr();
		#else //for CCIF
		   	while ( 0x0 == *MDCCIF_RCHNUM);
		    ccif_lisr();
		#endif
	   	} 
		else 
		{
		   break;
	    }
	  }
   } 
   else if (INT_QueryExceptionStatus() == KAL_TRUE) 
   {
	  #if defined (__SDIO_DEVICE_CONNECTIVITY__)
			;//do nothing
		#else //CCIF
			while ( KAL_FALSE == ccci_chk_recentry_in_queue(CCCI_FS_ACK_CHANNEL, KAL_TRUE));
		#endif
   }
   else 
   {
	   //kal_take_sem(gFS_CCCI_SemId, KAL_INFINITE_WAIT); // wait for an event;
	   ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME ,  &retrieved_events, KAL_SUSPEND);
   }
   // return code
   LV[num].len = sizeof(kal_int32);
   LV[num++].val = (void *)&count;
   // DSR_Hint
   LV[num].len = sizeof(FS_FileOpenHint);
   LV[num++].val = (void *)DSR_Hint;
   ret = FS_CCCI_Read(index, FS_CCCI_OP_OPENHINT, LV, &num);
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }
   else
   {
      return count;
   }
}


/*************************************************************************
* FUNCTION
*  kal_int32 MD_FS_Close
*
* DESCRIPTION
*  This function is to open file
*
* PARAMETERS
*  
*     
* RETURNS
*  
*
*************************************************************************/
kal_int32 MD_FS_Close(FS_HANDLE FileHandle)
{
   kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
   FS_CCCI_LV_T LV[FS_CCCI_MAX_ARG_NUM];
   kal_int32 ret, count = 0;
   kal_uint32 num = 0;
   kal_status ev_result = KAL_NOT_PRESENT;//,sema_result =KAL_SEM_NOT_AVAILABLE;
   kal_uint32 retrieved_events =0;
	 

   // FileHandle
   LV[count].len = sizeof(FS_HANDLE);
   LV[count++].val = (void *)&FileHandle;
   
   ret = FS_CCCI_Write(&index, FS_CCCI_OP_CLOSE, LV, count); // FS_Read request
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }

   if (KAL_TRUE == kal_query_systemInit() ) {
	   while (ev_result == KAL_NOT_PRESENT) {
	  	 //sema_result =	 kal_take_sem(gFS_CCCI_SemId, KAL_NO_WAIT); // wait for an event;
	   	ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME,  &retrieved_events, KAL_NO_SUSPEND);
	   	if (KAL_SUCCESS != ev_result)
	   	{
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			while (!sdio_query_txqueue_data_available(get_ngio_handle()));
			ccci_hisr();
		#else //for CCIF
			while ( 0x0 == *MDCCIF_RCHNUM);
			ccif_lisr();
		#endif
		} else {
			break;
		}
	}
   } else if (INT_QueryExceptionStatus() == KAL_TRUE) {
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			;//do nothing
		#else //CCIF
			while ( KAL_FALSE == ccci_chk_recentry_in_queue(CCCI_FS_ACK_CHANNEL, KAL_TRUE));
		#endif
   } else {
	   //kal_take_sem(gFS_CCCI_SemId, KAL_INFINITE_WAIT); // wait for an event;
    ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME ,  &retrieved_events, KAL_SUSPEND);
   }
   // return code
   LV[num].len = sizeof(kal_int32);
   LV[num++].val = (void *)&count;
   ret = FS_CCCI_Read(index, FS_CCCI_OP_CLOSE, LV, &num);
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }
   else
   {
      return count;
   }
}

/*
kal_int32 MD_FS_CloseAll(void)
{
   return CCCI_FAIL;
}
*/


/*************************************************************************
* FUNCTION
*  kal_int32 MD_FS_Read
*
* DESCRIPTION
*  This function is to open file
*
* PARAMETERS
*  
*     
* RETURNS
*  
*
*************************************************************************/
kal_int32 MD_FS_Read(FS_HANDLE FileHandle, void * DataPtr, kal_uint32 Length, kal_uint32 * Read)
{
   kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
   FS_CCCI_LV_T LV[FS_CCCI_MAX_ARG_NUM];
   kal_int32 ret, count = 0;
   kal_uint32 num = 0;
   kal_status ev_result = KAL_NOT_PRESENT;//,sema_result =KAL_SEM_NOT_AVAILABLE;
   kal_uint32 retrieved_events =0;
   
   // FileHandle
   LV[count].len = sizeof(FS_HANDLE);
   LV[count++].val = (void *)&FileHandle;
   // Length
   LV[count].len = sizeof(kal_uint32);
   LV[count++].val = (void *)&Length;
   
   ret = FS_CCCI_Write(&index, FS_CCCI_OP_READ, LV, count); // FS_Read request
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }

   if (KAL_TRUE == kal_query_systemInit() ) {
	   while (ev_result == KAL_NOT_PRESENT) {
	  	 //sema_result =	 kal_take_sem(gFS_CCCI_SemId, KAL_NO_WAIT); // wait for an event;
	   	ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME,  &retrieved_events, KAL_NO_SUSPEND);
	   	if (KAL_SUCCESS != ev_result)
	   	{
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			while (!sdio_query_txqueue_data_available(get_ngio_handle()));
			ccci_hisr();
		#else //for CCIF
			while ( 0x0 == *MDCCIF_RCHNUM);
			ccif_lisr();
		#endif
	   	} else {
		   break;
	       }
	   }
   } else if (INT_QueryExceptionStatus() == KAL_TRUE) {
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			;//do nothing
		#else //CCIF
			while ( KAL_FALSE == ccci_chk_recentry_in_queue(CCCI_FS_ACK_CHANNEL, KAL_TRUE));
		#endif
    } else {
	   //kal_take_sem(gFS_CCCI_SemId, KAL_INFINITE_WAIT); // wait for an event;
	   ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME ,  &retrieved_events, KAL_SUSPEND);
   }
   // return code
   LV[num].len = sizeof(kal_int32);
   LV[num++].val = (void *)&count;
   // Read
   LV[num].len = sizeof(kal_uint32);
   LV[num++].val = Read;
   // DataPtr
   LV[num].len = Length;
   LV[num++].val = DataPtr;
   ret = FS_CCCI_Read(index, FS_CCCI_OP_READ, LV, &num);
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }
   else
   {
      return count;
   }
}


/*************************************************************************
* FUNCTION
*  kal_int32 MD_FS_Write
*
* DESCRIPTION
*  This function is to open file
*
* PARAMETERS
*  
*     
* RETURNS
*  
*
*************************************************************************/
kal_int32 MD_FS_Write(FS_HANDLE FileHandle, void * DataPtr, kal_uint32 Length, kal_uint32 * Written)
{
   kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
   FS_CCCI_LV_T LV[FS_CCCI_MAX_ARG_NUM];
   kal_int32 ret, count = 0;
   kal_uint32 num = 0;
   kal_status ev_result = KAL_NOT_PRESENT;//,sema_result =KAL_SEM_NOT_AVAILABLE;
   kal_uint32 retrieved_events =0;
   
   // FileHandle
   LV[count].len = sizeof(FS_HANDLE);
   LV[count++].val = (void *)&FileHandle;
   // DataPtr
   LV[count].len = Length;
   LV[count++].val = DataPtr;
   // Length
   LV[count].len = sizeof(kal_uint32);
   LV[count++].val = (void *)&Length;
   
   ret = FS_CCCI_Write(&index, FS_CCCI_OP_WRITE, LV, count); // FS_Read request
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }

   if (KAL_TRUE == kal_query_systemInit() ) {
	   while (ev_result == KAL_NOT_PRESENT) {
	  	 //sema_result =	 kal_take_sem(gFS_CCCI_SemId, KAL_NO_WAIT); // wait for an event;
	   	ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME,  &retrieved_events, KAL_NO_SUSPEND);
	   	if (KAL_SUCCESS != ev_result)
	   	{
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			while (!sdio_query_txqueue_data_available(get_ngio_handle()));
			ccci_hisr();
		#else //for CCIF
			while ( 0x0 == *MDCCIF_RCHNUM);
			ccif_lisr();
		#endif
	   	} else {
		   break;
	       }
	   }
   } else if (INT_QueryExceptionStatus() == KAL_TRUE) {
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			;//do nothing
		#else //CCIF
			while ( KAL_FALSE == ccci_chk_recentry_in_queue(CCCI_FS_ACK_CHANNEL, KAL_TRUE));
		#endif
    } else {
	   //kal_take_sem(gFS_CCCI_SemId, KAL_INFINITE_WAIT); // wait for an event;
	   ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME ,  &retrieved_events, KAL_SUSPEND);
   }
   // return code
   LV[num].len = sizeof(kal_int32);
   LV[num++].val = (void *)&count;
   // Written
   LV[num].len = sizeof(kal_uint32);
   LV[num++].val = Written;
   ret = FS_CCCI_Read(index, FS_CCCI_OP_WRITE, LV, &num);
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }
   else
   {
      return count;
   }
}

/*
kal_int32 MD_FS_SetSeekHint(FS_HANDLE FileHandle, kal_uint32 HintNum, FS_FileLocationHint * Hint)
{
   return CCCI_FAIL;
}
*/


/*************************************************************************
* FUNCTION
*  kal_int32 MD_FS_Seek
*
* DESCRIPTION
*  This function is to open file
*
* PARAMETERS
*  
*     
* RETURNS
*  
*
*************************************************************************/
kal_int32 MD_FS_Seek(FS_HANDLE FileHandle, kal_int32 Offset, kal_int32 Whence)
{
   kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
   FS_CCCI_LV_T LV[FS_CCCI_MAX_ARG_NUM];
   kal_int32 ret, count = 0;
   kal_uint32 num = 0;
   kal_status ev_result = KAL_NOT_PRESENT;//,sema_result =KAL_SEM_NOT_AVAILABLE;
   kal_uint32 retrieved_events =0;
   
   // FileHandle
   LV[count].len = sizeof(FS_HANDLE);
   LV[count++].val = (void *)&FileHandle;
   // Offset
   LV[count].len = sizeof(kal_int32);
   LV[count++].val = (void *)&Offset;
   // Whence
   LV[count].len = sizeof(kal_int32);
   LV[count++].val = (void *)&Whence;
   
   ret = FS_CCCI_Write(&index, FS_CCCI_OP_SEEK, LV, count); // FS_Read request
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }

   if (KAL_TRUE == kal_query_systemInit() ) {
	   while (ev_result == KAL_NOT_PRESENT) {
	  	 //sema_result =	 kal_take_sem(gFS_CCCI_SemId, KAL_NO_WAIT); // wait for an event;
	   	ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME,  &retrieved_events, KAL_NO_SUSPEND);
	   	if (KAL_SUCCESS != ev_result)
	   	{
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			while (!sdio_query_txqueue_data_available(get_ngio_handle()));
			ccci_hisr();
		#else //for CCIF
			while ( 0x0 == *MDCCIF_RCHNUM);
			ccif_lisr();
		#endif
	   	} else {
		   break;
	       }
	   }
   } else if (INT_QueryExceptionStatus() == KAL_TRUE) {
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			;//do nothing
		#else //CCIF
			while ( KAL_FALSE == ccci_chk_recentry_in_queue(CCCI_FS_ACK_CHANNEL, KAL_TRUE));
		#endif
    } else {
	   //kal_take_sem(gFS_CCCI_SemId, KAL_INFINITE_WAIT); // wait for an event;
	   ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME ,  &retrieved_events, KAL_SUSPEND);
   }
   // return code
   LV[num].len = sizeof(kal_int32);
   LV[num++].val = (void *)&count;
   ret = FS_CCCI_Read(index, FS_CCCI_OP_SEEK, LV, &num);
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }
   else
   {
      return count;
   }
}

/*
kal_int32 MD_FS_Commit(FS_HANDLE FileHandle)
{
   return CCCI_FAIL;
}

kal_int32 MD_FS_ReleaseFH(void * TaskId)
{
   return CCCI_FAIL;
}

kal_int32 MD_FS_Abort(kal_uint32 ActionHandle)
{
   return CCCI_FAIL;
}

kal_int32 MD_FS_ParseFH(FS_HANDLE FileHandle)
{
   return CCCI_FAIL;
}

kal_int32 MD_FS_GenVirtualFileName(FS_HANDLE FileHandle, WCHAR * VFileNameBuf, kal_uint32 BufLength, kal_uint32 VFBeginOffset, kal_uint32 VFValidLength)
{
   return CCCI_FAIL;
}

kal_int32 MD_FS_GetFileInfo(FS_HANDLE FileHandle, FS_FileInfo * FileInfo)
{
   return CCCI_FAIL;
}
*/


/*************************************************************************
* FUNCTION
*  kal_int32 MD_FS_GetFileSize
*
* DESCRIPTION
*  This function is to open file
*
* PARAMETERS
*  
*     
* RETURNS
*  
*
*************************************************************************/
kal_int32 MD_FS_GetFileSize(FS_HANDLE FileHandle, kal_uint32 * Size)
{
   kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
   FS_CCCI_LV_T LV[FS_CCCI_MAX_ARG_NUM];
   kal_int32 ret, count = 0;
   kal_uint32 num = 0;
   kal_status ev_result = KAL_NOT_PRESENT;//,sema_result =KAL_SEM_NOT_AVAILABLE;
   kal_uint32 retrieved_events =0;
   
   // FileHandle
   LV[count].len = sizeof(FS_HANDLE);
   LV[count++].val = (void *)&FileHandle;
   
   ret = FS_CCCI_Write(&index, FS_CCCI_OP_GETFILESIZE, LV, count); // FS_Read request
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }

   if (KAL_TRUE == kal_query_systemInit() ) {
	   while (ev_result == KAL_NOT_PRESENT) {
	   	ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME,  &retrieved_events, KAL_NO_SUSPEND);
	   	if (KAL_SUCCESS != ev_result)
	   	{
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			while (!sdio_query_txqueue_data_available(get_ngio_handle()));
			ccci_hisr();
		#else //for CCIF
			while ( 0x0 == *MDCCIF_RCHNUM);
			ccif_lisr();
		#endif
		} else {
			break;
		}
	}
   } else if (INT_QueryExceptionStatus() == KAL_TRUE) {
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			;//do nothing
		#else //CCIF
			while ( KAL_FALSE == ccci_chk_recentry_in_queue(CCCI_FS_ACK_CHANNEL, KAL_TRUE));
		#endif
   } else {
	   ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME ,  &retrieved_events, KAL_SUSPEND);
   }
   // return code
   LV[num].len = sizeof(kal_int32);
   LV[num++].val = (void *)&count;
   // Size
   LV[num].len = sizeof(kal_uint32);
   LV[num++].val = (void *)Size;
   ret = FS_CCCI_Read(index, FS_CCCI_OP_GETFILESIZE, LV, &num);
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }
   else
   {
      return count;
   }
}

/*
kal_int32 MD_FS_GetFilePosition(FS_HANDLE FileHandle, kal_uint32 * Position)
{
   return CCCI_FAIL;
}

kal_int32 MD_FS_SetFileTime(FS_HANDLE FileHandle, const FS_DOSDateTime * Time)
{
   return CCCI_FAIL;
}

kal_int32 MD_FS_GetAttributes(const WCHAR * FileName)
{
   return CCCI_FAIL;
}

kal_int32 MD_FS_GetFirstCluster(FS_HANDLE FileHandle, kal_uint32 * Cluster)
{
   return CCCI_FAIL;
}

kal_int32 MD_FS_SetAttributes(const WCHAR * FileName, kal_uint8 Attributes)
{
   return CCCI_FAIL;
}
*/


/*************************************************************************
* FUNCTION
*  kal_int32 MD_FS_Delete
*
* DESCRIPTION
*  This function is to open file
*
* PARAMETERS
*  
*     
* RETURNS
*  
*
*************************************************************************/
kal_int32 MD_FS_Delete(const WCHAR * FileName)
{
   kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
   FS_CCCI_LV_T LV[FS_CCCI_MAX_ARG_NUM];
   kal_int32 ret, count = 0;
   kal_uint32 num = 0;
   kal_status ev_result = KAL_NOT_PRESENT;//,sema_result =KAL_SEM_NOT_AVAILABLE;
   kal_uint32 retrieved_events =0;
   
   // FileName
   LV[count].len = kal_dchar_strlen((const char *)FileName) + sizeof(WCHAR);
   LV[count++].val = (void *)FileName;
   
   ret = FS_CCCI_Write(&index, FS_CCCI_OP_DELETE, LV, count); // FS_Read request
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }

   if (KAL_TRUE == kal_query_systemInit() ) {
	   while (ev_result == KAL_NOT_PRESENT) {
	   	ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME,  &retrieved_events, KAL_NO_SUSPEND);
	   	if (KAL_SUCCESS != ev_result)
	   	{
		
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			while (!sdio_query_txqueue_data_available(get_ngio_handle()));
			ccci_hisr();
		#else //for CCIF
			while ( 0x0 == *MDCCIF_RCHNUM);
			ccif_lisr();
		#endif
	   	} else {
		   break;
	       }
	   }
   } else if (INT_QueryExceptionStatus() == KAL_TRUE) {
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			;//do nothing
		#else //CCIF
			while ( KAL_FALSE == ccci_chk_recentry_in_queue(CCCI_FS_ACK_CHANNEL, KAL_TRUE));
		#endif
    } else {
	   ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME ,  &retrieved_events, KAL_SUSPEND);
   }
   // return code
   LV[num].len = sizeof(kal_int32);
   LV[num++].val = (void *)&count;
   ret = FS_CCCI_Read(index, FS_CCCI_OP_DELETE, LV, &num);
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }
   else
   {
      return count;
   }
}


/*************************************************************************
* FUNCTION
*  kal_int32 MD_FS_GetAttributes
*
* DESCRIPTION
*  This function is to open file
*
* PARAMETERS
*  
*     
* RETURNS
*  
*
*************************************************************************/
kal_int32 MD_FS_GetAttributes(const WCHAR * FileName)
{
   kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
   FS_CCCI_LV_T LV[FS_CCCI_MAX_ARG_NUM];
   kal_int32 ret, count = 0;
   kal_uint32 num = 0;
   kal_status ev_result = KAL_NOT_PRESENT;//,sema_result =KAL_SEM_NOT_AVAILABLE;
   kal_uint32 retrieved_events =0;
   
   // FileName
   LV[count].len = kal_dchar_strlen((const char *)FileName) + sizeof(WCHAR);
   LV[count++].val = (void *)FileName;
   
   ret = FS_CCCI_Write(&index, FS_CCCI_OP_GETATTRIBUTES, LV, count); // FS_Read request
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }

   if (KAL_TRUE == kal_query_systemInit() ) {
	   while (ev_result == KAL_NOT_PRESENT) {
	   	ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME,  &retrieved_events, KAL_NO_SUSPEND);
	   	if (KAL_SUCCESS != ev_result)
	   	{
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			while (!sdio_query_txqueue_data_available(get_ngio_handle()));
			ccci_hisr();
		#else //for CCIF
			while ( 0x0 == *MDCCIF_RCHNUM);
			ccif_lisr();
		#endif
	   	} else {
		   break;
	       }
	   }
   } else if (INT_QueryExceptionStatus() == KAL_TRUE) {
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			;//do nothing
		#else //CCIF
			while ( KAL_FALSE == ccci_chk_recentry_in_queue(CCCI_FS_ACK_CHANNEL, KAL_TRUE));
		#endif
   } else {
	   ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME ,  &retrieved_events, KAL_SUSPEND);
   }
   // return code
   LV[num].len = sizeof(kal_int32);
   LV[num++].val = (void *)&count;
   ret = FS_CCCI_Read(index, FS_CCCI_OP_GETATTRIBUTES, LV, &num);
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }
   else
   {
      return count;
   }
}


/*
kal_int32 MD_FS_PseudoMerge(const WCHAR * FileName1, const WCHAR * FileName2)
{
   return CCCI_FAIL;
}

kal_int32 MD_FS_CheckFile(const WCHAR * FileName)
{
   return CCCI_FAIL;
}

kal_int32 MD_FS_GetCurrentDir(WCHAR * DirName, kal_uint32 MaxLength)
{
   return CCCI_FAIL;
}

kal_int32 MD_FS_SetCurrentDir(const WCHAR * DirName)
{
   return CCCI_FAIL;
}
*/


/*************************************************************************
* FUNCTION
*  kal_int32 MD_FS_CreateDir
*
* DESCRIPTION
*  This function is to open file
*
* PARAMETERS
*  
*     
* RETURNS
*  
*
*************************************************************************/
kal_int32 MD_FS_CreateDir(const WCHAR * DirName)
{
   kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
   FS_CCCI_LV_T LV[FS_CCCI_MAX_ARG_NUM];
   kal_int32 ret, count = 0;
   kal_uint32 num = 0;
   kal_status ev_result = KAL_NOT_PRESENT;//,sema_result =KAL_SEM_NOT_AVAILABLE;
   kal_uint32 retrieved_events =0;
   
   // DirName
   LV[count].len = kal_dchar_strlen((const char *)DirName) + sizeof(WCHAR);
   LV[count++].val = (void *)DirName;
   
   ret = FS_CCCI_Write(&index, FS_CCCI_OP_CREATEDIR, LV, count); // FS_Read request
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }

   if (KAL_TRUE == kal_query_systemInit() ) {
	   while (ev_result == KAL_NOT_PRESENT) {
	   	ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME,  &retrieved_events, KAL_NO_SUSPEND);
	   	if (KAL_SUCCESS != ev_result)
	   	{
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			while (!sdio_query_txqueue_data_available(get_ngio_handle()));
			ccci_hisr();
		#else //for CCIF
			while ( 0x0 == *MDCCIF_RCHNUM);
			ccif_lisr();
		#endif
	   	} else {
		   break;
	       }
	   }
   } else if (INT_QueryExceptionStatus() == KAL_TRUE) {
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			;//do nothing
		#else //CCIF
			while ( KAL_FALSE == ccci_chk_recentry_in_queue(CCCI_FS_ACK_CHANNEL, KAL_TRUE));
		#endif
    } else {
	   ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME ,  &retrieved_events, KAL_SUSPEND);
   }
   // return code
   LV[num].len = sizeof(kal_int32);
   LV[num++].val = (void *)&count;
   ret = FS_CCCI_Read(index, FS_CCCI_OP_CREATEDIR, LV, &num);
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }
   else
   {
      return count;
   }
}


/*************************************************************************
* FUNCTION
*  kal_int32 MD_FS_RemoveDir
*
* DESCRIPTION
*  This function is to open file
*
* PARAMETERS
*  
*     
* RETURNS
*  
*
*************************************************************************/
kal_int32 MD_FS_RemoveDir(const WCHAR * DirName)
{
   kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
   FS_CCCI_LV_T LV[FS_CCCI_MAX_ARG_NUM];
   kal_int32 ret, count = 0;
   kal_uint32 num = 0;
   kal_status ev_result = KAL_NOT_PRESENT;//,sema_result =KAL_SEM_NOT_AVAILABLE;
   kal_uint32 retrieved_events =0;
   
   // DirName
   LV[count].len = kal_dchar_strlen((const char *)DirName) + sizeof(WCHAR);
   LV[count++].val = (void *)DirName;
   
   ret = FS_CCCI_Write(&index, FS_CCCI_OP_REMOVEDIR, LV, count); // FS_Read request
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }

   if (KAL_TRUE == kal_query_systemInit() ) {
	   while (ev_result == KAL_NOT_PRESENT) {
	   	ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME,  &retrieved_events, KAL_NO_SUSPEND);
	   	if (KAL_SUCCESS != ev_result)
	   	{
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			while (!sdio_query_txqueue_data_available(get_ngio_handle()));
			ccci_hisr();
		#else //for CCIF
			while ( 0x0 == *MDCCIF_RCHNUM);
			ccif_lisr();
		#endif
	   	} else {
		   break;
	       }
	   }
   } else if (INT_QueryExceptionStatus() == KAL_TRUE) {
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			;//do nothing
		#else //CCIF
			while ( KAL_FALSE == ccci_chk_recentry_in_queue(CCCI_FS_ACK_CHANNEL, KAL_TRUE));
		#endif
   } else {
	   ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME ,  &retrieved_events, KAL_SUSPEND);
   }
   // return code
   LV[num].len = sizeof(kal_int32);
   LV[num++].val = (void *)&count;
   ret = FS_CCCI_Read(index, FS_CCCI_OP_REMOVEDIR, LV, &num);
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }
   else
   {
      return count;
   }
}


/*************************************************************************
* FUNCTION
*  kal_int32 MD_FS_GetFolderSize
*
* DESCRIPTION
*  This function is to open file
*
* PARAMETERS
*  
*     
* RETURNS
*  
*
*************************************************************************/
kal_int32 MD_FS_GetFolderSize(const WCHAR *DirName, kal_uint32 Flag, kal_uint8 *RecursiveStack, const kal_uint32 StackSize)
{
 
 kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
 FS_CCCI_LV_T LV[FS_CCCI_MAX_ARG_NUM];
 kal_int32 ret, count = 0;
 kal_uint32 num = 0;   
 kal_status ev_result = KAL_NOT_PRESENT;//,sema_result =KAL_SEM_NOT_AVAILABLE;
 kal_uint32 retrieved_events =0;
 
 // DirName
 LV[count].len = kal_dchar_strlen((const char *)DirName) + sizeof(WCHAR);
 LV[count++].val = (void *)DirName;
 // Flag
 LV[count].len = sizeof(kal_uint32);
 LV[count++].val = (void *)&Flag;
 // RecursiveStack/StackSize => NULL: use default stack
 
 ret = FS_CCCI_Write(&index, FS_CCCI_OP_GETFOLDERSIZE, LV, count); // FS_Read request
 if (ret != CCCI_SUCCESS)
 {
	return ret;
 }
 
 if (KAL_TRUE == kal_query_systemInit() ) {
	 while (ev_result == KAL_NOT_PRESENT) {
	  ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME,  &retrieved_events, KAL_NO_SUSPEND);
	  if (KAL_SUCCESS != ev_result)
	  {
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			while (!sdio_query_txqueue_data_available(get_ngio_handle()));
			ccci_hisr();
		#else //for CCIF
			while ( 0x0 == *MDCCIF_RCHNUM);
			ccif_lisr();
		#endif
	  } else {
		 break;
		 }
	 }
 } else if (INT_QueryExceptionStatus() == KAL_TRUE) {
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			;//do nothing
		#else //CCIF
			while ( KAL_FALSE == ccci_chk_recentry_in_queue(CCCI_FS_ACK_CHANNEL, KAL_TRUE));
		#endif
 } else {
	 ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME ,  &retrieved_events, KAL_SUSPEND);
 }
 // return code
 LV[num].len = sizeof(kal_int32);
 LV[num++].val = (void *)&count;
 ret = FS_CCCI_Read(index, FS_CCCI_OP_GETFOLDERSIZE, LV, &num);
 if (ret != CCCI_SUCCESS)
 {
	return ret;
 }
 else
 {
	return count;
 }
 
}

/*


kal_int32 MD_FS_Extend(FS_HANDLE FileHandle, kal_uint32 Length)
{
   return CCCI_FAIL;
}

kal_int32 MD_FS_Truncate(FS_HANDLE FileHandle)
{
   return CCCI_FAIL;
}

kal_int32 MD_FS_MakeFileName(FS_HANDLE FileHandle, kal_uint32 Flag, WCHAR * FileName, kal_uint32 MaxLength)
{
   return CCCI_FAIL;
}

*/


/*************************************************************************
* FUNCTION
*  kal_int32 MD_FS_Rename
*
* DESCRIPTION
*  This function is to open file
*
* PARAMETERS
*  
*     
* RETURNS
*  
*
*************************************************************************/
kal_int32 MD_FS_Rename(const WCHAR * FileName, const WCHAR * NewName)
{
	kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
	FS_CCCI_LV_T LV[FS_CCCI_MAX_ARG_NUM];
	kal_int32 ret, count = 0;
	kal_uint32 num = 0;   
	kal_status ev_result = KAL_NOT_PRESENT;//,sema_result =KAL_SEM_NOT_AVAILABLE;
	kal_uint32 retrieved_events =0;
	
	// FileName
	LV[count].len = kal_dchar_strlen((const char *)FileName) + sizeof(WCHAR);
	LV[count++].val = (void *)FileName;
	// NewName
	LV[count].len = kal_dchar_strlen((const char *)NewName) + sizeof(WCHAR);
	LV[count++].val = (void *)NewName;

	ret = FS_CCCI_Write(&index, FS_CCCI_OP_RENAME, LV, count); // FS_Read request
	if (ret != CCCI_SUCCESS)
	{
	   return ret;
	}
	
	if (KAL_TRUE == kal_query_systemInit() ) {
		while (ev_result == KAL_NOT_PRESENT) {
		 ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME,	&retrieved_events, KAL_NO_SUSPEND);
		 if (KAL_SUCCESS != ev_result)
		 {
		 #if defined (__SDIO_DEVICE_CONNECTIVITY__)
			while (!sdio_query_txqueue_data_available(get_ngio_handle()));
			ccci_hisr();
		 #else //for CCIF
			while ( 0x0 == *MDCCIF_RCHNUM);
			ccif_lisr();
		 #endif
		 } else {
			break;
			}
		}
	} else if (INT_QueryExceptionStatus() == KAL_TRUE) {
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			;//do nothing
		#else //CCIF
			while ( KAL_FALSE == ccci_chk_recentry_in_queue(CCCI_FS_ACK_CHANNEL, KAL_TRUE));
		#endif
	} else {
		ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME ,	&retrieved_events, KAL_SUSPEND);
	}
	// return code
	LV[num].len = sizeof(kal_int32);
	LV[num++].val = (void *)&count;
	ret = FS_CCCI_Read(index, FS_CCCI_OP_RENAME, LV, &num);
	if (ret != CCCI_SUCCESS)
	{
	   return ret;
	}
	else
	{
	   return count;
	}


}


/*************************************************************************
* FUNCTION
*  kal_int32 MD_FS_Move
*
* DESCRIPTION
*  This function is to open file
*
* PARAMETERS
*  
*     
* RETURNS
*  
*
*************************************************************************/
kal_int32 MD_FS_Move(const WCHAR * SrcFullPath, const WCHAR * DstFullPath, kal_uint32 Flag, FS_ProgressCallback Progress, kal_uint8 *RecursiveStack, const kal_uint32 StackSize)
{
	kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
	FS_CCCI_LV_T LV[FS_CCCI_MAX_ARG_NUM];
	kal_int32 ret, count = 0;
	kal_uint32 num = 0;	 
	kal_status ev_result = KAL_NOT_PRESENT;//,sema_result =KAL_SEM_NOT_AVAILABLE;
	kal_uint32 retrieved_events =0;
	   
	// SrcFullPath
	LV[count].len = kal_dchar_strlen((const char *)SrcFullPath) + sizeof(WCHAR);
	LV[count++].val = (void *)SrcFullPath;
	// DstFullPath
	LV[count].len = kal_dchar_strlen((const char *)DstFullPath) + sizeof(WCHAR);
	LV[count++].val = (void *)DstFullPath;
	// Flag
	LV[count].len = sizeof(kal_uint32);
	LV[count++].val = (void *)&Flag;
	// Progress/RecursiveStack/StackSize => NULL: use default stack
	   
	ret = FS_CCCI_Write(&index, FS_CCCI_OP_MOVE, LV, count); // FS_Read request
	if (ret != CCCI_SUCCESS)
	{
		return ret;
	}
	
	if (KAL_TRUE == kal_query_systemInit() ) {
	   while (ev_result == KAL_NOT_PRESENT) {
		ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME,  &retrieved_events, KAL_NO_SUSPEND);
		if (KAL_SUCCESS != ev_result)
		{
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			while (!sdio_query_txqueue_data_available(get_ngio_handle()));
			ccci_hisr();
		#else //for CCIF
			while ( 0x0 == *MDCCIF_RCHNUM);
			ccif_lisr();
		#endif
		} else {
		   break;
		}
	 }
   	} else if (INT_QueryExceptionStatus() == KAL_TRUE) {
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			;//do nothing
		#else //CCIF
			while ( KAL_FALSE == ccci_chk_recentry_in_queue(CCCI_FS_ACK_CHANNEL, KAL_TRUE));
		#endif
   	} else {
	   ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME ,  &retrieved_events, KAL_SUSPEND);
	 }
	 // return code
	 LV[num].len = sizeof(kal_int32);
	 LV[num++].val = (void *)&count;
	 ret = FS_CCCI_Read(index, FS_CCCI_OP_MOVE, LV, &num);
	 if (ret != CCCI_SUCCESS)
	 {
		  return ret;
	 }
	 else
	 {
		  return count;
	 }

}


/*************************************************************************
* FUNCTION
*  kal_int32 MD_FS_Count
*
* DESCRIPTION
*  This function is to open file
*
* PARAMETERS
*  
*     
* RETURNS
*  
*
*************************************************************************/
kal_int32 MD_FS_Count(const WCHAR * FullPath, UINT Flag, BYTE *RecursiveStack, const UINT StackSize)
{
	kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
	FS_CCCI_LV_T LV[FS_CCCI_MAX_ARG_NUM];
	kal_int32 ret, count = 0;
	kal_uint32 num = 0;   
	kal_status ev_result = KAL_NOT_PRESENT;//,sema_result =KAL_SEM_NOT_AVAILABLE;
	kal_uint32 retrieved_events =0;
	
	// FullPath
	LV[count].len = kal_dchar_strlen((const char *)FullPath) + sizeof(WCHAR);
	LV[count++].val = (void *)FullPath;
	// Flag
	LV[count].len = sizeof(kal_uint32);
	LV[count++].val = (void *)&Flag;
	// RecursiveStack/StackSize => NULL: use default stack
	
	ret = FS_CCCI_Write(&index, FS_CCCI_OP_COUNT, LV, count); // FS_Read request
	if (ret != CCCI_SUCCESS)
	{
	   return ret;
	}
	
	if (KAL_TRUE == kal_query_systemInit() ) {
		while (ev_result == KAL_NOT_PRESENT) {
		 ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME,	&retrieved_events, KAL_NO_SUSPEND);
		 if (KAL_SUCCESS != ev_result)
		 {
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			while (!sdio_query_txqueue_data_available(get_ngio_handle()));
			ccci_hisr();
		#else //for CCIF
			while ( 0x0 == *MDCCIF_RCHNUM);
			ccif_lisr();
		#endif
		 } else {
			break;
			}
		}
	} else if (INT_QueryExceptionStatus() == KAL_TRUE) {
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			;//do nothing
		#else //CCIF
			while ( KAL_FALSE == ccci_chk_recentry_in_queue(CCCI_FS_ACK_CHANNEL, KAL_TRUE));
		#endif
	} else {
		ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME ,	&retrieved_events, KAL_SUSPEND);
	}
	// return code
	LV[num].len = sizeof(kal_int32);
	LV[num++].val = (void *)&count;
	ret = FS_CCCI_Read(index, FS_CCCI_OP_COUNT, LV, &num);
	if (ret != CCCI_SUCCESS)
	{
	   return ret;
	}
	else
	{
	   return count;
	}

}


/*************************************************************************
* FUNCTION
*  kal_int32 MD_FS_XDelete
*
* DESCRIPTION
*  This function is to open file
*
* PARAMETERS
*  
*     
* RETURNS
*  
*
*************************************************************************/
kal_int32 MD_FS_XDelete(const WCHAR * FullPath, kal_uint32 Flag, kal_uint8 *RecursiveStack, const kal_uint32 StackSize)
{
   kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
   FS_CCCI_LV_T LV[FS_CCCI_MAX_ARG_NUM];
   kal_int32 ret, count = 0;
   kal_uint32 num = 0;   
   kal_status ev_result = KAL_NOT_PRESENT;//,sema_result =KAL_SEM_NOT_AVAILABLE;
   kal_uint32 retrieved_events =0;
   
   // FullPath
   LV[count].len = kal_dchar_strlen((const char *)FullPath) + sizeof(WCHAR);
   LV[count++].val = (void *)FullPath;
   // Flag
   LV[count].len = sizeof(kal_uint32);
   LV[count++].val = (void *)&Flag;
   // RecursiveStack/StackSize => NULL: use default stack
   
   ret = FS_CCCI_Write(&index, FS_CCCI_OP_XDELETE, LV, count); // FS_Read request
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }

   if (KAL_TRUE == kal_query_systemInit() ) {
	   while (ev_result == KAL_NOT_PRESENT) {
	   	ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME,  &retrieved_events, KAL_NO_SUSPEND);
	   	if (KAL_SUCCESS != ev_result)
	   	{
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			while (!sdio_query_txqueue_data_available(get_ngio_handle()));
			ccci_hisr();
		#else //for CCIF
			while ( 0x0 == *MDCCIF_RCHNUM);
			ccif_lisr();
		#endif
	   	} else {
		   break;
	       }
	   }
   } else if (INT_QueryExceptionStatus() == KAL_TRUE) {
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			;//do nothing
		#else //CCIF
			while ( KAL_FALSE == ccci_chk_recentry_in_queue(CCCI_FS_ACK_CHANNEL, KAL_TRUE));
		#endif
    } else {
	   ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME ,  &retrieved_events, KAL_SUSPEND);
   }
   // return code
   LV[num].len = sizeof(kal_int32);
   LV[num++].val = (void *)&count;
   ret = FS_CCCI_Read(index, FS_CCCI_OP_XDELETE, LV, &num);
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }
   else
   {
      return count;
   }
}


/*************************************************************************
* FUNCTION
*  kal_int32 MD_FS_FindFirst
*
* DESCRIPTION
*  This function is to open file
*
* PARAMETERS
*  
*     
* RETURNS
*  
*
*************************************************************************/
kal_int32 MD_FS_FindFirst(const WCHAR * NamePattern, kal_uint8 Attr, kal_uint8 AttrMask, FS_DOSDirEntry * FileInfo, WCHAR * FileName, kal_uint32 MaxLength)
{
   kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
   FS_CCCI_LV_T LV[FS_CCCI_MAX_ARG_NUM];
   kal_int32 ret, count = 0;
   kal_uint32 num = 0;
   kal_status ev_result = KAL_NOT_PRESENT;//,sema_result =KAL_SEM_NOT_AVAILABLE;
   kal_uint32 retrieved_events =0;
   
   // NamePattern
   LV[count].len = kal_dchar_strlen((const char *)NamePattern) + sizeof(WCHAR);
   LV[count++].val = (void *)NamePattern;
   // Attr
   LV[count].len = sizeof(kal_uint8);
   LV[count++].val = (void *)&Attr;
   // AttrMask
   LV[count].len = sizeof(kal_uint8);
   LV[count++].val = (void *)&AttrMask;
   // MaxLength
   LV[count].len = sizeof(kal_uint32);
   LV[count++].val = (void *)&MaxLength;
   
   ret = FS_CCCI_Write(&index, FS_CCCI_OP_FINDFIRST, LV, count); // FS_Read request
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }

   if (KAL_TRUE == kal_query_systemInit() ) {
	   while (ev_result == KAL_NOT_PRESENT) {
	   	ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME,  &retrieved_events, KAL_NO_SUSPEND);
	   	if (KAL_SUCCESS != ev_result)
	   	{
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			while (!sdio_query_txqueue_data_available(get_ngio_handle()));
			ccci_hisr();
		#else //for CCIF
			while ( 0x0 == *MDCCIF_RCHNUM);
			ccif_lisr();
		#endif
	   	} else {
		   break;
	       }
	   }
   } else if (INT_QueryExceptionStatus() == KAL_TRUE) {
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			;//do nothing
		#else //CCIF
			while ( KAL_FALSE == ccci_chk_recentry_in_queue(CCCI_FS_ACK_CHANNEL, KAL_TRUE));
		#endif
   } else {
	   ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME ,  &retrieved_events, KAL_SUSPEND);
   }
   // return code
   LV[num].len = sizeof(kal_int32);
   LV[num++].val = (void *)&count;
   // FileInfo
   LV[num].len = sizeof(FS_DOSDirEntry);
   LV[num++].val = (void *)FileInfo;
   // FileName
   LV[num].len = MaxLength;
   LV[num++].val = (void *)FileName;
   ret = FS_CCCI_Read(index, FS_CCCI_OP_FINDFIRST, LV, &num);
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }
   else
   {
      return count;
   }
}


/*************************************************************************
* FUNCTION
*  kal_int32 MD_FS_FindNext
*
* DESCRIPTION
*  This function is to open file
*
* PARAMETERS
*  
*     
* RETURNS
*  
*
*************************************************************************/
kal_int32 MD_FS_FindNext(FS_HANDLE FileHandle, FS_DOSDirEntry * FileInfo, WCHAR * FileName, kal_uint32 MaxLength)
{
   kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
   FS_CCCI_LV_T LV[FS_CCCI_MAX_ARG_NUM];
   kal_int32 ret, count = 0;
   kal_uint32 num = 0;
   kal_status ev_result = KAL_NOT_PRESENT;//,sema_result =KAL_SEM_NOT_AVAILABLE;
   kal_uint32 retrieved_events =0;
   
   // FileHandle
   LV[count].len = sizeof(FS_HANDLE);
   LV[count++].val = (void *)&FileHandle;
   // MaxLength
   LV[count].len = sizeof(kal_uint32);
   LV[count++].val = (void *)&MaxLength;
   
   ret = FS_CCCI_Write(&index, FS_CCCI_OP_FINDNEXT, LV, count); // FS_Read request
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }

   if (KAL_TRUE == kal_query_systemInit() ) {
	   while (ev_result == KAL_NOT_PRESENT) {
	   	ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME,  &retrieved_events, KAL_NO_SUSPEND);
	   	if (KAL_SUCCESS != ev_result)
	   	{
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			while (!sdio_query_txqueue_data_available(get_ngio_handle()));
			ccci_hisr();
		#else //for CCIF
			while ( 0x0 == *MDCCIF_RCHNUM);
			ccif_lisr();
		#endif
			} else {
				break;
			}
	   	   }
   } else if (INT_QueryExceptionStatus() == KAL_TRUE) {
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			;//do nothing
		#else //CCIF
			while ( KAL_FALSE == ccci_chk_recentry_in_queue(CCCI_FS_ACK_CHANNEL, KAL_TRUE));
		#endif
   } else {
	   ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME ,  &retrieved_events, KAL_SUSPEND);
   }
   // return code
   LV[num].len = sizeof(kal_int32);
   LV[num++].val = (void *)&count;
   // FileInfo
   LV[num].len = sizeof(FS_DOSDirEntry);
   LV[num++].val = (void *)FileInfo;
   // FileName
   LV[num].len = MaxLength;
   LV[num++].val = (void *)FileName;
   ret = FS_CCCI_Read(index, FS_CCCI_OP_FINDNEXT, LV, &num);
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }
   else
   {
      return count;
   }
}

/*
kal_int32 MD_FS_FindFirstN(const WCHAR * NamePattern, FS_Pattern_Struct * PatternArray, kal_uint32 PatternNum, kal_uint8 ArrayMask, kal_uint8 Attr, kal_uint8 AttrMask, FS_DOSDirEntry * FileInfo, WCHAR * FileName, kal_uint32 MaxLength, kal_uint32 EntryIndex, kal_uint32 Flag)
{
   return CCCI_FAIL;
}

kal_int32 MD_FS_FindNextN(FS_HANDLE Handle, FS_Pattern_Struct * PatternArray, kal_uint32 PatternNum, kal_uint8 ArrayMask, FS_DOSDirEntry * FileInfo, WCHAR * FileName, kal_uint32 MaxLength, kal_uint32 Flag)
{
   return CCCI_FAIL;
}
*/


/*************************************************************************
* FUNCTION
*  kal_int32 MD_FS_FindClose
*
* DESCRIPTION
*  This function is to open file
*
* PARAMETERS
*  
*     
* RETURNS
*  
*
*************************************************************************/
kal_int32 MD_FS_FindClose(FS_HANDLE FileHandle)
{
   kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
   FS_CCCI_LV_T LV[FS_CCCI_MAX_ARG_NUM];
   kal_int32 ret, count = 0;
   kal_uint32 num = 0;
   kal_status ev_result = KAL_NOT_PRESENT;//,sema_result =KAL_SEM_NOT_AVAILABLE;
   kal_uint32 retrieved_events =0;
   
   // FileHandle
   LV[count].len = sizeof(FS_HANDLE);
   LV[count++].val = (void *)&FileHandle;
   
   ret = FS_CCCI_Write(&index, FS_CCCI_OP_FINDCLOSE, LV, count); // FS_Read request
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }

   if (KAL_TRUE == kal_query_systemInit() ) {
	   while (ev_result == KAL_NOT_PRESENT) {
	   	ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME,  &retrieved_events, KAL_NO_SUSPEND);
	   	if (KAL_SUCCESS != ev_result)
	   	{
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			while (!sdio_query_txqueue_data_available(get_ngio_handle()));
			ccci_hisr();
		#else //for CCIF
			while ( 0x0 == *MDCCIF_RCHNUM);
			ccif_lisr();
		#endif
	   	} else {
		   break;
	       }
	   }
   } else if (INT_QueryExceptionStatus() == KAL_TRUE) {
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			;//do nothing
		#else //CCIF
			while ( KAL_FALSE == ccci_chk_recentry_in_queue(CCCI_FS_ACK_CHANNEL, KAL_TRUE));
		#endif
   } else {
	   ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME ,  &retrieved_events, KAL_SUSPEND);
   }
   // return code
   LV[num].len = sizeof(kal_int32);
   LV[num++].val = (void *)&count;
   ret = FS_CCCI_Read(index, FS_CCCI_OP_FINDCLOSE, LV, &num);
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }
   else
   {
      return count;
   }
}

/*
#ifdef __FS_SORT_SUPPORT__
kal_int32 MD_FS_XFindReset(const WCHAR * Pattern, FS_Pattern_Struct * PatternArray, kal_uint32 PatternNum, kal_uint8 ArrayMask, kal_uint8 AttrMask, kal_uint32 Flag, kal_uint32 Timeout, kal_uint32 * Position)
{
   return CCCI_FAIL;
}

kal_int32 MD_FS_XFindStart(const WCHAR * Pattern, FS_DOSDirEntry * FileInfo, WCHAR * FileName, kal_uint32 MaxLength, kal_uint32 Index, kal_uint32 * Position, kal_uint32 Flag)
{
   return CCCI_FAIL;
}

kal_int32 MD_FS_XFindClose(kal_uint32 * Position)
{
   return CCCI_FAIL;
}
#endif

*/


/*************************************************************************
* FUNCTION
*  kal_int32 MD_FS_GetDrive
*
* DESCRIPTION
*  This function is to open file
*
* PARAMETERS
*  
*     
* RETURNS
*  
*
*************************************************************************/
kal_int32 MD_FS_GetDrive(kal_uint32 Type, kal_uint32 Serial, kal_uint32 AltMask)
{
	kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
	   FS_CCCI_LV_T LV[FS_CCCI_MAX_ARG_NUM];
	   kal_int32 ret, count = 0;
	   kal_uint32 num = 0;
	   kal_status ev_result = KAL_NOT_PRESENT;//,sema_result =KAL_SEM_NOT_AVAILABLE;
	   kal_uint32 retrieved_events =0;
	   
	   // Type
	   LV[count].len = sizeof(kal_uint32);
	   LV[count++].val = (void *)&Type;
	   // Serial
	   LV[count].len = sizeof(kal_uint32);
	   LV[count++].val = (void *)&Serial;
	   // AltMask
	   LV[count].len = sizeof(kal_uint32);
	   LV[count++].val = (void *)&AltMask;
	   
	   ret = FS_CCCI_Write(&index, FS_CCCI_OP_GETDRIVE,LV ,count); // FS_Read request
	   if (ret != CCCI_SUCCESS)
	   {
		  return ret;
	   }
	
	   if (KAL_TRUE == kal_query_systemInit() ) {
		   while (ev_result == KAL_NOT_PRESENT) {
			ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME,  &retrieved_events, KAL_NO_SUSPEND);
			if (KAL_SUCCESS != ev_result)
			{
			#if defined (__SDIO_DEVICE_CONNECTIVITY__)
				while (!sdio_query_txqueue_data_available(get_ngio_handle()));
				ccci_hisr();
			#else //for CCIF
				while ( 0x0 == *MDCCIF_RCHNUM);
				ccif_lisr();
			#endif
			} else {
			   break;
			   }
		   }
	   } else if (INT_QueryExceptionStatus() == KAL_TRUE) {
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			;//do nothing
		#else //CCIF
			while ( KAL_FALSE == ccci_chk_recentry_in_queue(CCCI_FS_ACK_CHANNEL, KAL_TRUE));
		#endif
	   } else {
		   ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME ,  &retrieved_events, KAL_SUSPEND);
	   }
	   // return code
	   LV[num].len = sizeof(kal_int32);
	   LV[num++].val = (void *)&count;
	   ret = FS_CCCI_Read(index, FS_CCCI_OP_GETDRIVE, LV, &num);
	   if (ret != CCCI_SUCCESS)
	   {
		  return ret;
	   }
	   else
	   {
		  return count;
	   }

}

/*
kal_int32 MD_FS_GeneralFormat(const WCHAR * DriveName, kal_uint32 Level, FS_FormatCallback Progress)
{
   return CCCI_FAIL;
}
*/


/*************************************************************************
* FUNCTION
*  kal_int32 MD_FS_GetClusterSize
*
* DESCRIPTION
*  This function is to open file
*
* PARAMETERS
*  
*     
* RETURNS
*  
*
*************************************************************************/
kal_int32 MD_FS_GetClusterSize(kal_uint32 DriveIdx)
{
   kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
   FS_CCCI_LV_T LV[FS_CCCI_MAX_ARG_NUM];
   kal_int32 ret, count = 0;
   kal_uint32 num = 0;
   kal_status ev_result = KAL_NOT_PRESENT;//,sema_result =KAL_SEM_NOT_AVAILABLE;
   kal_uint32 retrieved_events =0;
   
   // DriveIdx
   LV[count].len = sizeof(kal_uint32);
   LV[count++].val = (void *)&DriveIdx;
   
   ret = FS_CCCI_Write(&index, FS_CCCI_OP_GETCLUSTERSIZE, LV, count); // FS_Read request
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }

   if (KAL_TRUE == kal_query_systemInit() ) {
	   while (ev_result == KAL_NOT_PRESENT) {
	   	ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME,  &retrieved_events, KAL_NO_SUSPEND);
	   	if (KAL_SUCCESS != ev_result)
	   	{
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			while (!sdio_query_txqueue_data_available(get_ngio_handle()));
			ccci_hisr();
		#else //for CCIF
			while ( 0x0 == *MDCCIF_RCHNUM);
			ccif_lisr();
		#endif
	   	} else {
		   break;
	       }
	   }
   } else if (INT_QueryExceptionStatus() == KAL_TRUE) {
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			;//do nothing
		#else //CCIF
			while ( KAL_FALSE == ccci_chk_recentry_in_queue(CCCI_FS_ACK_CHANNEL, KAL_TRUE));
		#endif
   } else {
	   ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME ,  &retrieved_events, KAL_SUSPEND);
   }
   // return code
   LV[num].len = sizeof(kal_int32);
   LV[num++].val = (void *)&count;
   ret = FS_CCCI_Read(index, FS_CCCI_OP_GETCLUSTERSIZE, LV, &num);
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }
   else
   {
      return count;
   }
}

/*
#ifdef __FS_QM_SUPPORT__
kal_int32 MD_FS_QmGetFree(const kal_uint8 * Path)
{
   return CCCI_FAIL;
}
#endif

kal_int32 MD_FS_CreateBootSector(void * BootSector, const FS_PartitionRecord * Partition, kal_uint8 MediaDescriptor, kal_uint32 MinSectorsPerCluster, kal_uint32 Flags)
{
   return CCCI_FAIL;
}

kal_int32 MD_FS_GetPartitionInfo(const WCHAR * DriveName, FS_PartitionRecord * PartitionInfo)
{
   return CCCI_FAIL;
}

kal_int32 MD_FS_CommitAll(const WCHAR * DriveName)
{
   return CCCI_FAIL;
}

kal_int32 MD_FS_MappingDrive(kal_uint32 UpperOldDrv, kal_uint32 UpperNewDrv)
{
   return CCCI_FAIL;
}
*/


/*************************************************************************
* FUNCTION
*  kal_int32 MD_FS_SetDiskFlag
*
* DESCRIPTION
*  This function is to open file
*
* PARAMETERS
*  
*     
* RETURNS
*  
*
*************************************************************************/
kal_int32 MD_FS_SetDiskFlag(void)
{
   kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
   FS_CCCI_LV_T LV[FS_CCCI_MAX_ARG_NUM];
   kal_int32 ret, count = 0;
   kal_uint32 num = 0;
   kal_status ev_result = KAL_NOT_PRESENT;//,sema_result =KAL_SEM_NOT_AVAILABLE;
   kal_uint32 retrieved_events =0;
   
   ret = FS_CCCI_Write(&index, FS_CCCI_OP_SETDISKFLAG, LV, count); // FS_Read request
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }

   if (KAL_TRUE == kal_query_systemInit() ) {
	   while (ev_result == KAL_NOT_PRESENT) {
	   	ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME,  &retrieved_events, KAL_NO_SUSPEND);
	   	if (KAL_SUCCESS != ev_result)
	   	{
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			while (!sdio_query_txqueue_data_available(get_ngio_handle()));
			ccci_hisr();
		#else //for CCIF
			while ( 0x0 == *MDCCIF_RCHNUM);
			ccif_lisr();
		#endif
	   	} else {
		   break;
	       }
	   }
   } else if (INT_QueryExceptionStatus() == KAL_TRUE) {
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			;//do nothing
		#else //CCIF
			while ( KAL_FALSE == ccci_chk_recentry_in_queue(CCCI_FS_ACK_CHANNEL, KAL_TRUE));
		#endif
   } else {
	   ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME ,  &retrieved_events, KAL_SUSPEND);
   }
   // return code
   LV[num].len = sizeof(kal_int32);
   LV[num++].val = (void *)&count;
   ret = FS_CCCI_Read(index, FS_CCCI_OP_SETDISKFLAG, LV, &num);
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }
   else
   {
      return count;
   }
}


/*************************************************************************
* FUNCTION
*  kal_int32 MD_FS_CloseAll
*
* DESCRIPTION
*  This function is to open file
*
* PARAMETERS
*  
*     
* RETURNS
*  
*
*************************************************************************/
kal_int32 MD_FS_CloseAll(void)
{
   kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
   FS_CCCI_LV_T LV[FS_CCCI_MAX_ARG_NUM];
   kal_int32 ret, count = 0;
   kal_uint32 num = 0;
   kal_status ev_result = KAL_NOT_PRESENT;//,sema_result =KAL_SEM_NOT_AVAILABLE;
   kal_uint32 retrieved_events =0;
   
   ret = FS_CCCI_Write(&index, FS_CCCI_OP_CLOSEALL, LV, count); // FS_Read request
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }

   if (KAL_TRUE == kal_query_systemInit() ) {
	   while (ev_result == KAL_NOT_PRESENT) {
	   	ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME,  &retrieved_events, KAL_NO_SUSPEND);
	   	if (KAL_SUCCESS != ev_result)
	   	{
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			while (!sdio_query_txqueue_data_available(get_ngio_handle()));
			ccci_hisr();
		#else //for CCIF
			while ( 0x0 == *MDCCIF_RCHNUM);
			ccif_lisr();
		#endif
	   	} else {
		   break;
	       }
	   }
   } else if (INT_QueryExceptionStatus() == KAL_TRUE) {
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			;//do nothing
		#else //CCIF
			while ( KAL_FALSE == ccci_chk_recentry_in_queue(CCCI_FS_ACK_CHANNEL, KAL_TRUE));
		#endif
   } else {
	   ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME ,  &retrieved_events, KAL_SUSPEND);
   }
   // return code
   LV[num].len = sizeof(kal_int32);
   LV[num++].val = (void *)&count;
   ret = FS_CCCI_Read(index, FS_CCCI_OP_CLOSEALL, LV, &num);
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }
   else
   {
      return count;
   }
}


/*
kal_int32 MD_FS_CheckDiskFlag(void)
{
   return CCCI_FAIL;
}
*/


/*************************************************************************
* FUNCTION
*  kal_int32 MD_FS_ClearDiskFlag
*
* DESCRIPTION
*  This function is to open file
*
* PARAMETERS
*  
*     
* RETURNS
*  
*
*************************************************************************/
kal_int32 MD_FS_ClearDiskFlag(void)
{
   kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
   FS_CCCI_LV_T LV[FS_CCCI_MAX_ARG_NUM];
   kal_int32 ret, count = 0;
   kal_uint32 num = 0;
   kal_status ev_result = KAL_NOT_PRESENT;//,sema_result =KAL_SEM_NOT_AVAILABLE;
   kal_uint32 retrieved_events =0;
   
   ret = FS_CCCI_Write(&index, FS_CCCI_OP_CLEARDISKFLAG, LV, count); // FS_Read request
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }

   if (KAL_TRUE == kal_query_systemInit() ) {
	   while (ev_result == KAL_NOT_PRESENT) {
	   	ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME,  &retrieved_events, KAL_NO_SUSPEND);
	   	if (KAL_SUCCESS != ev_result)
	   	{
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			while (!sdio_query_txqueue_data_available(get_ngio_handle()));
			ccci_hisr();
		#else //for CCIF
			while ( 0x0 == *MDCCIF_RCHNUM);
			ccif_lisr();
		#endif
	   	} else {
		   break;
	       }
	   }
   } else if (INT_QueryExceptionStatus() == KAL_TRUE) {
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			;//do nothing
		#else //CCIF
			while ( KAL_FALSE == ccci_chk_recentry_in_queue(CCCI_FS_ACK_CHANNEL, KAL_TRUE));
		#endif
   } else {
	   ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME ,  &retrieved_events, KAL_SUSPEND);
   }
   // return code
   LV[num].len = sizeof(kal_int32);
   LV[num++].val = (void *)&count;
   ret = FS_CCCI_Read(index, FS_CCCI_OP_CLEARDISKFLAG, LV, &num);
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }
   else
   {
      return count;
   }
}

/*
#ifdef __FS_CHECKDRIVE_SUPPORT__
kal_int32 MD_FS_CheckDrive(const kal_uint32 DriveIdx, kal_uint8 * CheckBuffer, const kal_uint32 CheckBufferSize)
{
   return CCCI_FAIL;
}
#endif

kal_int32 MD_FS_CreateMasterBootRecord(void * SectorBuffer, const FS_PartitionRecord * DiskGeometry)
{
   return CCCI_FAIL;
}

kal_int32 MD_FS_SplitPartition(void * MasterBootRecord, kal_uint32 Sectors)
{
   return CCCI_FAIL;
}
*/


/*************************************************************************
* FUNCTION
*  kal_int32 MD_FS_GetDiskInfo
*
* DESCRIPTION
*  This function is to open file
*
* PARAMETERS
*  
*     
* RETURNS
*  
*
*************************************************************************/
kal_int32 MD_FS_GetDiskInfo(const WCHAR * DriveName, FS_DiskInfo * DiskInfo, kal_int32 Flags)
{
   kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
   FS_CCCI_LV_T LV[FS_CCCI_MAX_ARG_NUM];
   kal_int32 ret, count = 0;
   kal_uint32 num = 0;
   kal_status ev_result = KAL_NOT_PRESENT;//,sema_result =KAL_SEM_NOT_AVAILABLE;
   kal_uint32 retrieved_events =0;
   
   // DriveName
   LV[count].len = kal_dchar_strlen((const char *)DriveName) + sizeof(WCHAR);
   LV[count++].val = (void *)DriveName;
   // Flags
   LV[count].len = sizeof(kal_int32);
   LV[count++].val = (void *)&Flags;
   
   ret = FS_CCCI_Write(&index, FS_CCCI_OP_GETDISKINFO, LV, count); // FS_Read request
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }

   if (KAL_TRUE == kal_query_systemInit() ) {
	   while (ev_result == KAL_NOT_PRESENT) {
	   	ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME,  &retrieved_events, KAL_NO_SUSPEND);
	   	if (KAL_SUCCESS != ev_result)
		{
			#if defined (__SDIO_DEVICE_CONNECTIVITY__)
				while (!sdio_query_txqueue_data_available(get_ngio_handle()));
				ccci_hisr();
			#else //for CCIF
				while ( 0x0 == *MDCCIF_RCHNUM);
				ccif_lisr();
			#endif
			} else {
				break;
			}
	   	}
   } else if (INT_QueryExceptionStatus() == KAL_TRUE) {
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			;//do nothing
		#else //CCIF
			while ( KAL_FALSE == ccci_chk_recentry_in_queue(CCCI_FS_ACK_CHANNEL, KAL_TRUE));
		#endif
   } else {
	   ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME ,  &retrieved_events, KAL_SUSPEND);
   }
   // return code
   LV[num].len = sizeof(kal_int32);
   LV[num++].val = (void *)&count;
   // DiskInfo
   LV[num].len = sizeof(FS_DiskInfo);
   LV[num++].val = (void *)DiskInfo;
   ret = FS_CCCI_Read(index, FS_CCCI_OP_GETDISKINFO, LV, &num);
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }
   else
   {
      return count;
   }
}

/*
kal_int32 MD_FS_GetDevType(const WCHAR * Path)
{
   return CCCI_FAIL;
}

kal_int32 MD_FS_GetDevStatus(kal_uint32 DriveIdx, kal_uint32 Flag)
{
   return CCCI_FAIL;
}

kal_int32 MD_FS_GetDevPartitions(kal_uint32 QueryTarget)
{
   return CCCI_FAIL;
}

kal_int32 MD_FS_TestMSDC(void *slot_id)
{
   return CCCI_FAIL;
}

kal_int32 MD_FS_CloseMSDC(kal_uint32 MSDCIndex, kal_uint32 Mode)
{
   return CCCI_FAIL;
}

kal_int32 MD_FS_ConfigExtDevice(kal_int32 Action, FS_Driver *DrvFuncs, kal_int32 Slots, void **SlotIdArray, kal_int32 *SlotsConfiged)
{
   return CCCI_FAIL;
}
*/


/*************************************************************************
* FUNCTION
*  kal_int32 MD_FS_ShutDown
*
* DESCRIPTION
*  This function is to open file
*
* PARAMETERS
*  
*     
* RETURNS
*  
*
*************************************************************************/
void MD_FS_ShutDown(void)
{
   kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
   FS_CCCI_LV_T LV[FS_CCCI_MAX_ARG_NUM];
   kal_int32 ret, count = 0;
   kal_uint32 num = 0;
   kal_status ev_result = KAL_NOT_PRESENT;//,sema_result =KAL_SEM_NOT_AVAILABLE;
   kal_uint32 retrieved_events =0;
   
   ret = FS_CCCI_Write(&index, FS_CCCI_OP_SHUTDOWN, LV, count); // FS_Read request
   if (ret != CCCI_SUCCESS)
   {
      kal_fatal_error_handler(KAL_ERROR_FILESYS_INTERNAL_FAILED, ret);
   }
   
   if (KAL_TRUE == kal_query_systemInit() ) {
	   while (ev_result == KAL_NOT_PRESENT) {
	   	ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME,  &retrieved_events, KAL_NO_SUSPEND);
	   	if (KAL_SUCCESS != ev_result)
	   	{
			#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			while (!sdio_query_txqueue_data_available(get_ngio_handle()));
			ccci_hisr();
			#else
			while ( 0x0 == *MDCCIF_RCHNUM);
			ccif_lisr();
			#endif
	   	} else {
		   break;
	       }
	   }
   } else if (INT_QueryExceptionStatus() == KAL_TRUE) {
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			;//do nothing
		#else //CCIF
			while ( KAL_FALSE == ccci_chk_recentry_in_queue(CCCI_FS_ACK_CHANNEL, KAL_TRUE));
		#endif
   } else {
	   ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME ,  &retrieved_events, KAL_SUSPEND);
   }
   // return code: N/A
   ret = FS_CCCI_Read(index, FS_CCCI_OP_SHUTDOWN, LV, &num);
   if (ret != CCCI_SUCCESS)
   {
      //kal_fatal_error_handler(KAL_ERROR_FILESYS_INTERNAL_FAILED, ret);
   }
}


/*************************************************************************
* FUNCTION
*  kal_int32 MD_FS_UnlockAll
*
* DESCRIPTION
*  This function is to open file
*
* PARAMETERS
*  
*     
* RETURNS
*  
*
*************************************************************************/
kal_int32 MD_FS_UnlockAll(void)
{
   kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
   FS_CCCI_LV_T LV[FS_CCCI_MAX_ARG_NUM];
   kal_int32 ret, count = 0;
   kal_uint32 num = 0;
   kal_status ev_result = KAL_NOT_PRESENT;//,sema_result =KAL_SEM_NOT_AVAILABLE;
   kal_uint32 retrieved_events =0;
   
   ret = FS_CCCI_Write(&index, FS_CCCI_OP_UNLOCKALL, LV, count); // FS_Read request
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }

   if (KAL_TRUE == kal_query_systemInit() ) {
	   while (ev_result == KAL_NOT_PRESENT) {
	   	ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME,  &retrieved_events, KAL_NO_SUSPEND);
	   	if (KAL_SUCCESS != ev_result)
	   	{
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			while (!sdio_query_txqueue_data_available(get_ngio_handle()));
			ccci_hisr();
		#else //for CCIF
			while ( 0x0 == *MDCCIF_RCHNUM);
			ccif_lisr();
		#endif
			} else {
				break;
			}
	   	   }
   } else if (INT_QueryExceptionStatus() == KAL_TRUE) {
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			;//do nothing
		#else //CCIF
			while ( KAL_FALSE == ccci_chk_recentry_in_queue(CCCI_FS_ACK_CHANNEL, KAL_TRUE));
		#endif
   } else {
	   ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME ,  &retrieved_events, KAL_SUSPEND);
   }
   // return code
   LV[num].len = sizeof(kal_int32);
   LV[num++].val = (void *)&count;
   ret = FS_CCCI_Read(index, FS_CCCI_OP_UNLOCKALL, LV, &num);
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }
   else
   {
      return count;
   }
}

/*
kal_int32 MD_FS_SanityCheck(void)
{
   return CCCI_FAIL;
}
*/


/*************************************************************************
* FUNCTION
*  kal_int32 MD_FS_LockFAT
*
* DESCRIPTION
*  This function is to open file
*
* PARAMETERS
*  
*     
* RETURNS
*  
*
*************************************************************************/
kal_int32 MD_FS_LockFAT(kal_uint32 Type)
{
   kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
   FS_CCCI_LV_T LV[FS_CCCI_MAX_ARG_NUM];
   kal_int32 ret, count = 0;
   kal_uint32 num = 0;
   kal_status ev_result = KAL_NOT_PRESENT;//,sema_result =KAL_SEM_NOT_AVAILABLE;
   kal_uint32 retrieved_events =0;
   
   // Type
   LV[count].len = sizeof(kal_uint32);
   LV[count++].val = (void *)&Type;
   
   ret = FS_CCCI_Write(&index, FS_CCCI_OP_LOCKFAT, LV, count); // FS_Read request
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }

   if (KAL_TRUE == kal_query_systemInit() ) {
	   while (ev_result == KAL_NOT_PRESENT) {
	   	ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME,  &retrieved_events, KAL_NO_SUSPEND);
	   	if (KAL_SUCCESS != ev_result)
	   	{
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			while (!sdio_query_txqueue_data_available(get_ngio_handle()));
			ccci_hisr();
	    #else //for CCIF
			while ( 0x0 == *MDCCIF_RCHNUM);
			ccif_lisr();
		#endif
	   	} else {
		   break;
	       }
	   }
   } else if (INT_QueryExceptionStatus() == KAL_TRUE) {
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			;//do nothing
		#else //CCIF
			while ( KAL_FALSE == ccci_chk_recentry_in_queue(CCCI_FS_ACK_CHANNEL, KAL_TRUE));
		#endif
   } else {
	   ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME ,  &retrieved_events, KAL_SUSPEND);
   }
   // return code
   LV[num].len = sizeof(kal_int32);
   LV[num++].val = (void *)&count;
   ret = FS_CCCI_Read(index, FS_CCCI_OP_LOCKFAT, LV, &num);
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }
   else
   {
      return count;
   }
}


/*************************************************************************
* FUNCTION
*  kal_int32 MD_FS_OTPWrite
*
* DESCRIPTION
*  This function is to open file
*
* PARAMETERS
*  
*     
* RETURNS
*  
*
*************************************************************************/
kal_int32 MD_FS_OTPWrite(kal_int32 devtype, kal_uint32 Offset, void * BufferPtr, kal_uint32 Length)
{
   kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
   FS_CCCI_LV_T LV[FS_CCCI_MAX_ARG_NUM];
   kal_int32 ret, count = 0;
   kal_uint32 num = 0;
   kal_status ev_result = KAL_NOT_PRESENT;//,sema_result =KAL_SEM_NOT_AVAILABLE;
   kal_uint32 retrieved_events =0;
   
   // FileHandle
   LV[count].len = sizeof(FS_HANDLE);
   LV[count++].val = (void *)&devtype;
   //
   LV[count].len = sizeof(FS_HANDLE);
   LV[count++].val = (void *)&Offset;
   // DataPtr
   LV[count].len = Length;
   LV[count++].val = BufferPtr;
   // Length
   LV[count].len = sizeof(kal_uint32);
   LV[count++].val = (void *)&Length;
   
   ret = FS_CCCI_Write(&index, FS_CCCI_OP_OTPWRITE, LV, count); // FS_Read request
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }
 
   if (KAL_TRUE == kal_query_systemInit() ) {
	   while (ev_result == KAL_NOT_PRESENT) {
	   	ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME,  &retrieved_events, KAL_NO_SUSPEND);
	   	if (KAL_SUCCESS != ev_result)
	   	{
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			while (!sdio_query_txqueue_data_available(get_ngio_handle()));
			ccci_hisr();
		#else //for CCIF
			while ( 0x0 == *MDCCIF_RCHNUM);
			ccif_lisr();
		#endif
	   	} else {
		   break;
	       }
	   }
   } else if (INT_QueryExceptionStatus() == KAL_TRUE) {
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			;//do nothing
		#else //CCIF
			while ( KAL_FALSE == ccci_chk_recentry_in_queue(CCCI_FS_ACK_CHANNEL, KAL_TRUE));
		#endif
    } else {
	   ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME ,  &retrieved_events, KAL_SUSPEND);
   }
   // return code
   LV[num].len = sizeof(kal_int32);
   LV[num++].val = (void *)&count;
   
   ret = FS_CCCI_Read(index, FS_CCCI_OP_OTPWRITE, LV, &num);
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }
   else
   {
      return count;
   }
}


/*************************************************************************
* FUNCTION
*  kal_int32 MD_FS_OTPRead
*
* DESCRIPTION
*  This function is to open file
*
* PARAMETERS
*  
*     
* RETURNS
*  
*
*************************************************************************/
kal_int32 MD_FS_OTPRead(kal_int32 devtype, kal_uint32 Offset, void * BufferPtr, kal_uint32 Length)
{
   kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
   FS_CCCI_LV_T LV[FS_CCCI_MAX_ARG_NUM];
   kal_int32 ret, count = 0;
   kal_uint32 num = 0; 
   kal_status ev_result = KAL_NOT_PRESENT;//,sema_result =KAL_SEM_NOT_AVAILABLE;
   kal_uint32 retrieved_events =0;
   
   // FileHandle
   LV[count].len = sizeof(FS_HANDLE);
   LV[count++].val = (void *)&devtype;
   // Offset
   LV[count].len = sizeof(kal_uint32);
   LV[count++].val = (void *)&Offset;
   // Length
   LV[count].len = sizeof(kal_uint32);
   LV[count++].val = (void *)&Length;
   
   ret = FS_CCCI_Write(&index, FS_CCCI_OP_OTPREAD, LV, count); // FS_Read request
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }
 
   if (KAL_TRUE == kal_query_systemInit() ) {
	   while (ev_result == KAL_NOT_PRESENT) {
	   	ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME,  &retrieved_events, KAL_NO_SUSPEND);
	   	if (KAL_SUCCESS != ev_result)
	   	{
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			while (!sdio_query_txqueue_data_available(get_ngio_handle()));
			ccci_hisr();
		#else //for CCIF
			while ( 0x0 == *MDCCIF_RCHNUM);
			ccif_lisr();
		#endif
	   	} else {
		   break;
	       }
	   }
   } else if (INT_QueryExceptionStatus() == KAL_TRUE) {
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			;//do nothing
		#else //CCIF
			while ( KAL_FALSE == ccci_chk_recentry_in_queue(CCCI_FS_ACK_CHANNEL, KAL_TRUE));
		#endif
    } else {
	   ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME ,  &retrieved_events, KAL_SUSPEND);
   }
   // return code
   LV[num].len = sizeof(kal_int32);
   LV[num++].val = (void *)&count;
   // BufferPtr
   LV[num].len = Length;
   LV[num++].val = BufferPtr;
   ret = FS_CCCI_Read(index, FS_CCCI_OP_OTPREAD, LV, &num);
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }
   else
   {
      return count;
   }
}


/*************************************************************************
* FUNCTION
*  kal_int32 MD_FS_OTPQueryLength
*
* DESCRIPTION
*  This function is to open file
*
* PARAMETERS
*  
*     
* RETURNS
*  
*
*************************************************************************/
kal_int32 MD_FS_OTPQueryLength(kal_int32 devtype, kal_uint32 *Length)
{
   kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
   FS_CCCI_LV_T LV[FS_CCCI_MAX_ARG_NUM];
   kal_int32 ret, count = 0;
   kal_uint32 num = 0; 
   kal_status ev_result = KAL_NOT_PRESENT;//,sema_result =KAL_SEM_NOT_AVAILABLE;
   kal_uint32 retrieved_events =0;
	   
   // Type
   LV[count].len = sizeof(kal_uint32);
   LV[count++].val = (void *)&devtype;

   
   ret = FS_CCCI_Write(&index, FS_CCCI_OP_OTPQUERYLENGTH,LV ,count); // FS_Read request
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }
	 
   if (KAL_TRUE == kal_query_systemInit() ) {
      while (ev_result == KAL_NOT_PRESENT) {
	ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME,  &retrieved_events, KAL_NO_SUSPEND);
	if (KAL_SUCCESS != ev_result)
    {
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			while (!sdio_query_txqueue_data_available(get_ngio_handle()));
			ccci_hisr();
 	    #else //for CCIF
			while ( 0x0 == *MDCCIF_RCHNUM);
			ccif_lisr();
		#endif
	} else {
	   break;
        }
      }
   } else if (INT_QueryExceptionStatus() == KAL_TRUE) {
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			;//do nothing
		#else //CCIF
			while ( KAL_FALSE == ccci_chk_recentry_in_queue(CCCI_FS_ACK_CHANNEL, KAL_TRUE));
		#endif
   } else {
	   ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME ,  &retrieved_events, KAL_SUSPEND);
   }

   // return code
   LV[num].len = sizeof(kal_int32);
   LV[num++].val = (void *)&count;

   // return length   
   LV[num].len = sizeof(kal_int32);
   LV[num++].val = (void *)Length;
   
   ret = FS_CCCI_Read(index, FS_CCCI_OP_OTPQUERYLENGTH, LV, &num);
   if (ret != CCCI_SUCCESS)
   {
	  return ret;
   }
   else
   {
	  return count;
   }

}


/*************************************************************************
* FUNCTION
*  kal_int32 MD_FS_OTPLock
*
* DESCRIPTION
*  This function is to open file
*
* PARAMETERS
*  
*     
* RETURNS
*  
*
*************************************************************************/
kal_int32 MD_FS_OTPLock(kal_int32 devtype)
{
   kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
   FS_CCCI_LV_T LV[FS_CCCI_MAX_ARG_NUM];
   kal_int32 ret, count = 0;
   kal_uint32 num = 0; 
   kal_status ev_result = KAL_NOT_PRESENT;//,sema_result =KAL_SEM_NOT_AVAILABLE;
   kal_uint32 retrieved_events =0;
   
   // Type
   LV[count].len = sizeof(kal_uint32);
   LV[count++].val = (void *)&devtype;
   
   ret = FS_CCCI_Write(&index, FS_CCCI_OP_OTPLOCK, LV, count); // FS_Read request
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }
 
   if (KAL_TRUE == kal_query_systemInit() ) {
	   while (ev_result == KAL_NOT_PRESENT) {
	   	ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME,  &retrieved_events, KAL_NO_SUSPEND);
	   	if (KAL_SUCCESS != ev_result)
	   	{
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			while (!sdio_query_txqueue_data_available(get_ngio_handle()));
			ccci_hisr();
	    #else //for CCIF
			while ( 0x0 == *MDCCIF_RCHNUM);
			ccif_lisr();
		#endif
	   	} else {
		   break;
	       }
	   }
   } else if (INT_QueryExceptionStatus() == KAL_TRUE) {
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			;//do nothing
		#else //CCIF
			while ( KAL_FALSE == ccci_chk_recentry_in_queue(CCCI_FS_ACK_CHANNEL, KAL_TRUE));
		#endif
   } else {
	   ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME ,  &retrieved_events, KAL_SUSPEND);
   }
   // return code
   LV[num].len = sizeof(kal_int32);
   LV[num++].val = (void *)&count;
   ret = FS_CCCI_Read(index, FS_CCCI_OP_OTPLOCK, LV, &num);
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }
   else
   {
      return count;
   }
}

/*
kal_int32 MD_FS_CountUsedFH(kal_int32 flag)
{
   return CCCI_FAIL;
}

#ifdef __FS_TRACE_SUPPORT__
kal_int32 MD_FS_SetTrace(kal_uint32 Flag, kal_uint32 Timeout)
{
   return CCCI_FAIL;
}

kal_int32 MD_FS_DumpFHTable(void)
{
   return CCCI_FAIL;
}
#endif

kal_int32 MD_FS_SetDirCache(FS_HANDLE FileHandle, kal_uint32 NewValue)
{
   return CCCI_FAIL;
}

kal_int32 MD_FS_GetDirCache(FS_HANDLE FileHandle, kal_uint32 *CurrValue)
{
   return CCCI_FAIL;
}

kal_int32 MD_FS_ExpireDirCache(FS_HANDLE FileHandle)
{
   return CCCI_FAIL;
}

kal_int32 MD_FS_SweepDevice(const kal_int32 devtype)
{
   return CCCI_FAIL;
}
*/
kal_int32 MD_FS_Restore(const WCHAR * FileName, void* pBuffer, kal_uint32 Length)
{
   kal_int32 index = FS_CCCI_USE_DEFAULT_INDEX;
   FS_CCCI_LV_T LV[FS_CCCI_MAX_ARG_NUM];
   kal_int32 ret, count = 0;
   kal_uint32 num = 0;
   /* KC add for CCCI porting */
   kal_status ev_result = KAL_NOT_PRESENT;//,sema_result =KAL_SEM_NOT_AVAILABLE;
   kal_uint32 retrieved_events =0;
   
   // FileName
   LV[count].len = kal_dchar_strlen((const char *)FileName) + sizeof(WCHAR);
   LV[count++].val = (void *)FileName;
   
    // pBuffer
   LV[count].len = Length;
   LV[count++].val = (void *)pBuffer;
   
    // Length
   LV[count].len = sizeof(kal_uint32);
   LV[count++].val = (void *)&Length;
   
   ret = FS_CCCI_Write(&index, FS_CCCI_OP_RESTORE, LV, count); // FS_Read request  
   
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }
 
   if (KAL_TRUE == kal_query_systemInit() ) {
	   while (ev_result == KAL_NOT_PRESENT) {
	   	ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME,  &retrieved_events, KAL_NO_SUSPEND);
	   	if (KAL_SUCCESS != ev_result)
	   	{
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			while (!sdio_query_txqueue_data_available(get_ngio_handle()));
			ccci_hisr();
	    #else //for CCIF
			while ( 0x0 == *MDCCIF_RCHNUM);
			ccif_lisr();
		#endif
	   	} else {
		   break;
	       }
	   }
   } else if (INT_QueryExceptionStatus() == KAL_TRUE) {
		#if defined (__SDIO_DEVICE_CONNECTIVITY__)
			;//do nothing
		#else //CCIF
			while ( KAL_FALSE == ccci_chk_recentry_in_queue(CCCI_FS_ACK_CHANNEL, KAL_TRUE));
		#endif
   } else {
	   ev_result = kal_retrieve_eg_events(gFS_CCCI_CSEvgrp, 1 << index, KAL_AND_CONSUME ,  &retrieved_events, KAL_SUSPEND);
   }
   // return code
   LV[num].len = sizeof(kal_int32);
   LV[num++].val = (void *)&count;
   ret = FS_CCCI_Read(index, FS_CCCI_OP_RESTORE, LV, &num);
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }
   else
   {
      return count;
   }
}

#endif /* __SMART_PHONE_MODEM__ */
#endif /* __MODEM_CCCI_EXIST__ */

