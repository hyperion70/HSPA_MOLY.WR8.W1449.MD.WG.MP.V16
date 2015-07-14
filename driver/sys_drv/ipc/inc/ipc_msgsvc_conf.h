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
 *   ipc_msgsvc_conf.h
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

#ifndef __IPC_MSGSVC_CONF_H__
#define __IPC_MSGSVC_CONF_H__

#if defined(__MODEM_CCCI_EXIST__)

// Cross Core IPC Direction :  AP 2 MD
// Priority   -->   Local module ID -->     External ID     --> Max sent message
X_IPC_MODULE_CONF(1,MOD_L4C,0,1),     //Module_Entry_1
#ifdef __GEMINI__
    X_IPC_MODULE_CONF(1,MOD_L4C_2,1,1), //TASK_ID_2
#if (GEMINI_PLUS >= 3)
    X_IPC_MODULE_CONF(1,MOD_L4C_3,2,1), //TASK_ID_3
#endif    /* GEMINI_PLUS >= 3 */
#if (GEMINI_PLUS >= 4)
    X_IPC_MODULE_CONF(1,MOD_L4C_4,3,1), //TASK_ID_3
#endif    /* GEMINI_PLUS >= 4 */
#endif /* __GEMINI__ */

// Cross Core IPC Direction :  MD 2 AP
// Priority   -->   Local module ID -->     External ID     --> Max sent message
#define AP_UINFY_ID_FLAG ((kal_uint32)1<<31)
X_IPC_MODULE_CONF(1,APMOD_AGPS,(0|AP_UINFY_ID_FLAG),1),    //Module_Entry_3
X_IPC_MODULE_CONF(1,APMOD_DHCP,(1|AP_UINFY_ID_FLAG),1),    //Module_Entry_4
X_IPC_MODULE_CONF(1,APMOD_GPS ,(2|AP_UINFY_ID_FLAG),1),    //Module_Entry_5

#endif /* __MODEM_CCCI_EXIST__ */
#endif  /* !__IPC_MSGSVC_CONF_H__ */


