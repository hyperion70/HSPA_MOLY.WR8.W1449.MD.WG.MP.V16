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
 *   ipc_msgsvc_msgid.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Header file of IP_MSGSVC_MODULE.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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

#ifndef __IPC_MSGSVC_MSGID_H__
#define __IPC_MSGSVC_MSGID_H__

#include "module_msg_range.h"

typedef enum
{
	IPC_MSG_ID_SYS_BEGIN = MSG_ID_CCCI_MSG_CODE_BEGIN,
	IPC_MSG_ID_SYS_RANGE = MSG_ID_CCCI_MSG_CODE_TAIL - MSG_ID_CCCI_MSG_CODE_BEGIN
}IPC_MSG_ID_CODE_BEGIN;

typedef enum
{
	IPC_MSG_ID_INVALID_TYPE = MSG_ID_CCCI_MSG_CODE_BEGIN,
    #include "l4_ipc_msgid.h"

	IPC_MSG_ID_END
}ipc_msg_type;




#endif  /* !__IPC_MSGSVC_MSGID_H__ */


