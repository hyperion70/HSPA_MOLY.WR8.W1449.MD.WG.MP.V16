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
 *   ipc_rpc_cpsvc_sdio.c
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
#include "syscomp_config.h"
#include "ipc_rpc.h"
#include "ccci.h"

#include "sdio_fw_api_public.h"

/*************************************************************************
* FUNCTION
*  void IPC_RPC_Secure_Algo
*
* DESCRIPTION
*  This function use to handle control channel messages from AP side
*
* PARAMETERS
*  *   
* RETURNS
*  NA
*
*************************************************************************/
kal_int32 IPC_RPC_Secure_Algo (kal_uint8 Direction, kal_uint32 ContentAddr,
                             kal_uint32 ContentLen, kal_uint8 *CustomSeed,
                             kal_uint8 *ResText)
{
   kal_int32 index = IPC_RPC_USE_DEFAULT_INDEX;
   IPC_RPC_LV_T LV[IPC_RPC_MAX_ARG_NUM];
   kal_int32 ret, count = 0;
   kal_uint32 num = 0;
   kal_status ev_result = KAL_NOT_PRESENT;//, sema_result = KAL_SEM_NOT_AVAILABLE;
   kal_uint32 retrieved_events =0;  
   
   // Direction
   LV[count].len = sizeof(kal_uint8);
   LV[count++].val = (void *)&Direction;
   // ContentAddr
   LV[count].len = ContentLen;
   LV[count++].val = (void *)ContentAddr;
   // ContentLen
   LV[count].len = sizeof(kal_uint32);
   LV[count++].val = (void *)&ContentLen;
   // CustomSeed
   LV[count].len = sizeof(kal_uint32);
   LV[count++].val = (void *)CustomSeed;
   
   ret = IPC_RPC_CCCI_Write(&index, IPC_RPC_CPSVC_SECURE_ALGO_OP, LV, count); // Ipc_Cpsvc_Read request
   if (ret != CCCI_SUCCESS)
   {
      return ret;
   }

   if (KAL_TRUE == kal_query_systemInit() ) 
   {
       while (ev_result == KAL_NOT_PRESENT) 
       {
           ev_result = kal_retrieve_eg_events(g_IPC_RPC_CSEvgrp, 1 << index, KAL_AND_CONSUME,  &retrieved_events, KAL_NO_SUSPEND);
           if (KAL_SUCCESS != ev_result)
           {
               //query whether SDIO TX data ready or not?
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
       while( KAL_FALSE == ccci_chk_recentry_in_queue(CCCI_IPC_RPC_ACK_CHANNEL, KAL_TRUE));
       #endif
   } 
   else 
   {
       ev_result = kal_retrieve_eg_events(g_IPC_RPC_CSEvgrp, 1 << index, KAL_AND_CONSUME ,  &retrieved_events, KAL_SUSPEND);
   }

   // return code
   LV[num].len = sizeof(kal_int32);
   LV[num++].val = (void *)&count;
   // return code
   LV[num].len = ContentLen;
   LV[num++].val = (void *)ResText;

   ret = IPC_RPC_CCCI_Read(index, IPC_RPC_CPSVC_SECURE_ALGO_OP, LV, &num);
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
*  void IPC_RPC_GPIO_GetPin
*
* DESCRIPTION
*  This function use to handle control channel messages from AP side
*  major information : query the GPIO pin 
*
* PARAMETERS
*  *   
* RETURNS
*  NA
*
*************************************************************************/
kal_int32 IPC_RPC_GPIO_GetPin(kal_uint8 *GPIOName, kal_uint32 GPIONameLength, kal_uint32 *GPIOPin)
{
    kal_int32 index = IPC_RPC_USE_DEFAULT_INDEX;
    IPC_RPC_LV_T LV[IPC_RPC_MAX_ARG_NUM];
    kal_int32 ret, count = 0;//, size_val = 0;
    kal_uint32 num = 0;
	
    kal_status ev_result = KAL_NOT_PRESENT;//, sema_result = KAL_SEM_NOT_AVAILABLE;
    kal_uint32 retrieved_events = 0;
	
    LV[count].len = GPIONameLength;
    LV[count++].val = (void *) GPIOName;

    LV[count].len = sizeof(kal_uint32);
    LV[count++].val = (void *)&GPIONameLength;

    ret = IPC_RPC_CCCI_Write(&index, IPC_RPC_GPIO_GETPIN_OP, LV, count);

    if(ret != CCCI_SUCCESS)
    {
        return ret;
    }

    if(KAL_TRUE == kal_query_systemInit() ) 
    {
	while(ev_result == KAL_NOT_PRESENT) 
	{
	    ev_result = kal_retrieve_eg_events(g_IPC_RPC_CSEvgrp, 1 << index, KAL_AND_CONSUME,  &retrieved_events, KAL_NO_SUSPEND);
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
    else if(INT_QueryExceptionStatus() == KAL_TRUE) 
    {
	#if defined (__SDIO_DEVICE_CONNECTIVITY__)
	;//do nothing
	#else //CCIF
	while( KAL_FALSE == ccci_chk_recentry_in_queue(CCCI_IPC_RPC_ACK_CHANNEL, KAL_TRUE));
	#endif
    } 
    else 
    {
	 ev_result = kal_retrieve_eg_events(g_IPC_RPC_CSEvgrp, 1 << index, KAL_AND_CONSUME ,  &retrieved_events, KAL_SUSPEND);
    }

    // return status
    LV[num].len = sizeof(kal_int32);
    LV[num++].val = (void *)&count;

    // return GPIO Pin
    LV[num].len = sizeof(kal_int32);
    LV[num++].val = (void *)GPIOPin;

    ret = IPC_RPC_CCCI_Read(index, IPC_RPC_GPIO_GETPIN_OP, LV, &num);
    if(ret != CCCI_SUCCESS)
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
