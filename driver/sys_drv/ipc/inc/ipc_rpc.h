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
 *   ipc_rpc.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Header file of cpsvc header (cross crypto lib)
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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




#ifndef __IPC_RPC_H__
#define __IPC_RPC_H__

#if defined(__MODEM_CCCI_EXIST__)

#if !defined(__SDIO_DEVICE_CONNECTIVITY__)
/*******************************************************************************
 * Define marco or constant.
 *******************************************************************************/
#define IPC_RPC_EXCEPT_MAX_RETRY     7
#define IPC_RPC_MAX_RETRY            0xFFFF
#define IPC_RPC_REQ_BUFFER_NUM       2 /* support 2 concurrently request*/
#define IPC_RPC_SEC_REQ_BUFFER_NUM   2 /* support 2 concurrently request in security usuage*/
#define IPC_RPC_SEC_INDEX_START      0x10

#define IPC_RPC_MAX_ARG_NUM          6 /* parameter number */

#define IPC_RPC_INPUT_TERM_PATTERN   0xFFFFFFFE
#define IPC_RPC_EOF_TERM_PATTERN     0xFFFFFFFF
#define IPC_RPC_USE_DEFAULT_INDEX    -1
#define IPC_RPC_API_RESP_ID          0xFFFF0000

/*******************************************************************************
 * Define data structure.
 *******************************************************************************/

typedef struct IPC_RPC_LV_STRUCT
{
    kal_uint32 len;
    void *val;
} IPC_RPC_LV_T;

typedef struct IPC_RPC_StreamBuffer_STRUCT
{
    kal_uint32    rpc_opid;
    kal_uint32	  num;
    IPC_RPC_LV_T  LV0;
} IPC_RPC_StreamBuffer_T, *pIPC_RPC_StreamBuffer_T;

/*******************************************************************************
 * Declare function prototype.
 *******************************************************************************/
void ipc_rpc_init(void);


























#elif defined(__SMART_PHONE_MODEM__) //- __SDIO_DEVICE_CONNECTIVITY__ && __SMART_PHONE_MODEM__

#include "ccci.h"
/*******************************************************************************
 * Define marco or constant.
 *******************************************************************************/
#define PUBLIC
#define PRIVATE
#define IPC_RPC_EXCEPT_MAX_RETRY     7
#define IPC_RPC_MAX_RETRY            0xFFFF
#define IPC_RPC_REQ_BUFFER_NUM       2 /* support 2 concurrently request*/
#define IPC_RPC_MAX_ARG_NUM          6 /* parameter number */
#define IPC_RPC_MAX_BUF_SIZE         2048


#define IPC_RPC_USE_DEFAULT_INDEX    -1
#define IPC_RPC_API_RESP_ID          0xFFFF0000
#define IPC_RPC_INC_BUF_INDEX(x)     (x = (x + 1) % IPC_RPC_REQ_BUFFER_NUM)

/*******************************************************************************
 * Define data structure.
 *******************************************************************************/
typedef enum
{
    IPC_RPC_CPSVC_SECURE_ALGO_OP = 0x2001,
    IPC_RPC_GPIO_GETPIN_OP = 0x4002


} IPC_RPC_OP_ID_T;

typedef struct IPC_RPC_LV_STRUCT
{
    kal_uint32 len;
    void *val;
} IPC_RPC_LV_T;

typedef struct IPC_RPC_StreamBuffer_STRUCT
{
#if defined (__SDIO_DEVICE_CONNECTIVITY__)
    CCCI_BUFF_T ccci_header;
#endif
    kal_uint32    rpc_opid;
    kal_uint8     buffer[IPC_RPC_MAX_BUF_SIZE];
} IPC_RPC_StreamBuffer_T;


typedef enum
{
    IPC_RPC_CCCI_WRITE_REQUEST,
    IPC_RPC_CCCI_WRITE_NO_PHYSICAL_CHANNEL,
    IPC_RPC_CCCI_READ_OPID_NOT_SYNC,
    IPC_RPC_CCCI_READ_RESULT_NO_NOT_SYNC,
    IPC_RPC_CCCI_READ_RESULT_LEN_NOT_ENOUGH,
    IPC_RPC_CCCI_CALLBACK_ADDR_NOT_SYNC,
    IPC_RPC_CCCI_WRITE_BUF_FUL
} IPC_RPC_ERROR_CODE;






extern IPC_RPC_StreamBuffer_T *RPC_REQ_BUF;


/*******************************************************************************
 * Define export function prototype.
 *******************************************************************************/
extern PUBLIC kal_semid       g_IPC_RPC_CSSemId;
extern PUBLIC kal_eventgrpid  g_IPC_RPC_CSEvgrp;


/*******************************************************************************
 * Declare function prototype.
 *******************************************************************************/
PUBLIC kal_int32 IPC_RPC_CCCI_Write(kal_int32 *index, kal_uint32 op, IPC_RPC_LV_T *pLV, kal_uint32 num);
PUBLIC kal_int32 IPC_RPC_CCCI_Read(kal_int32 index, kal_uint32 op, IPC_RPC_LV_T *pLV, kal_uint32 *num);
PRIVATE void IPC_RPC_Callback(CCCI_BUFF_T *buff);
PUBLIC void ipc_rpc_init(void);

#endif //#if !defined(__SDIO_DEVICE_CONNECTIVITY__)

#endif  /* __MODEM_CCCI_EXIST__ */
#endif  /* __IPC_RPC_H__ */


