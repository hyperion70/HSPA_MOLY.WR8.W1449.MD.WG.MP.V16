/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   fs_kal.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file system service abstraction layer for file system
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
 *
 *
 * removed!
 * removed!
 *
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
 *
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

/**************************************************************************/
/*                                                                        */
/*  File: SYSW32.C                               Copyright (c) 1998,2002  */
/*  Version: 4.0                                 On Time Informatik GmbH  */
/*                                                                        */
/*                                                                        */
/*                                      On Time        /////////////----- */
/*                                    Informatik GmbH /////////////       */
/* --------------------------------------------------/////////////        */
/*                                  Real-Time and System Software         */
/*                                                                        */
/**************************************************************************/

/*************************************************************************
 * Included header files
 *************************************************************************/
#if defined(WIN32)
#include "windows.h"
#endif

#include "kal_public_defs.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_internal_api.h"    // for KAL_ERROR_FILESYS_INTERNAL_FAILED
#include "fs_internal_def.h"
#include "fs_gprot.h"
#include "fs_iprot.h"
#include "rtfiles.h"
#include "fs_kal.h"
#include "dcl.h"
#include "rtfex.h"
#include "fs_utility.h"
#include "fs_trc.h"
#if defined(__AUDIO_DSP_LOWPOWER__)
#include "audlp_exp.h"
#endif

/*************************************************************************
 * Constant and Declaration
 *************************************************************************/

// Assert
#define fs_assert_local(expr) fs_assert(expr, fs_kal_c)
#define fs_ext_assert_local(expr, e1, e2, e3) fs_ext_assert(expr, fs_kal_c, e1, e2, e3)

/*  TLS: Thread Local Storage */
#define MAX_TLS_INDEX 2
#define INI_SEM 1
#define FS_TLS_DEFAULT 0
#define MAX_MUTEX          12
#ifndef __FS_CARD_DOWNLOAD__
static RTFMutex   M[ MAX_MUTEX ];
static kal_uint32 NextMutex = 0;
#endif /* !__FS_CARD_DOWNLOAD__ */
extern _XData* gFS_TaskData[][MAX_TLS_INDEX];
static kal_int32  FS_TLS_Index = -1;
static kal_int8   FS_TCT_Index = 0;
#ifndef __FS_CARD_DOWNLOAD__
#ifndef WIN32
extern kal_bool INT_QueryExceptionStatus(void);
#endif

/*-------------------
 * Global Variables
 *-------------------*/

FS_Mutex *_gfs_lock_common = NULL;

// RTC tool
DCL_HANDLE rtc_handler = DCL_HANDLE_INVALID;

/*************************************************************************
* FUNCTION
*  stack_config
*
* DESCRIPTION
*  This function implements to get system date time
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void
RTFAPI RTFSYSGetDateTime(RTFDOSDateTime * TimeDate)
{
    RTC_CTRL_GET_TIME_T rtc_time;

    // Always zero rtc_time, in case of unsupported RTC platforms.
    kal_mem_set(&rtc_time, 0, sizeof(RTC_CTRL_GET_TIME_T));

    /*
     * Get a RTC handle in the first time.
     * This handle will not be closed in the future.
     */

    if (DCL_HANDLE_INVALID == rtc_handler)
        rtc_handler = DclRTC_Open(DCL_RTC, FLAGS_NONE);

    DclRTC_Control(rtc_handler, RTC_CMD_GET_TIME, (DCL_CTRL_DATA_T*)&rtc_time);

	TimeDate->Day = rtc_time.u1Day;
	TimeDate->Hour = rtc_time.u1Hour;
	TimeDate->Minute = rtc_time.u1Min;
	TimeDate->Month = rtc_time.u1Mon;
	TimeDate->Second2 = rtc_time.u1Sec >> 1;    // Second only contain 5 bits
	TimeDate->Year1980 = rtc_time.u1Year + 20;  // Adapt to windows is 1980 base while RTC is 2000 base
}

/*************************************************************************
* FUNCTION
*  RTFSYSAllocMutex
*
* DESCRIPTION
*  This function implements to create filesystem mutex
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
RTFMutex*
RTFAPI RTFSYSAllocMutex(const char * Name)
{
    if (NextMutex >= MAX_MUTEX)
    {
        fs_err_internal_fatal(FS_ERR_MUTEX_01, (void*)MAX_MUTEX);
    }

    M[NextMutex].rtf_lock_count = 0;
    M[NextMutex].rtf_sem_owner = KAL_NILTASK_ID;
    M[NextMutex].DeviceNum_1 = 0;
    M[NextMutex].DeviceNum_2 = 0;
    M[NextMutex++].rtf_sem = kal_create_sem((kal_char*)Name, INI_SEM);

    return &M[NextMutex-1];
}

/*************************************************************************
* FUNCTION
*  RTFSYSOwnMutex
*
* DESCRIPTION
*  This function implements to get filesystem mutex
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
int RTFAPI
RTFSYSOwnMutex(RTFMutex * Mutex)
{
	kal_taskid current_task;

	current_task = kal_get_current_thread_ID();

	if (Mutex->rtf_sem_owner == current_task)
		return (int)(KAL_TRUE);
	else
		return (int)(KAL_FALSE);
}

/*************************************************************************
* FUNCTION
*  RTFSYSLockMutex
*
* DESCRIPTION
*  This function implements to take mutex during dedicated time period
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
int
RTFAPI RTFSYSLockMutex(RTFMutex * Mutex, UINT Timeout)
{
   /* XXX!!!. Timeout lock is not support by Nucleus Plus =>wrong*/
   kal_taskid current_task;
   int ret_val = RTF_NO_ERROR;

   #ifdef __P_PROPRIETARY_COPYRIGHT__
/* under construction !*/
/* under construction !*/
   #endif

   current_task = kal_get_current_thread_ID();

   // task not ready
   if (current_task == KAL_NILTASK_ID)
      return RTF_NO_ERROR;
   /*
    * Bypass all FS lock operations in exception mode to avoid unexpected suspend behavior. (W10.37)
    *
    * NOTE 1. If a "HISR" triggers an exception, bypass lock operation to avoid another fatal error
    *         because only "task" can get semaphore (kal_take_sem) successfully.
    *
    * NOTE 2. HISR should NOT use FS in normal mode. It only walks here when an exception is triggerred in HISR.
    */
   else if (INT_QueryExceptionStatus() == KAL_TRUE)
      return RTF_NO_ERROR;

   if (Mutex->rtf_sem_owner == current_task)
   {
      Mutex->rtf_lock_count++;
      return (ret_val);
   }

   #if defined(__AUDIO_DSP_LOWPOWER__)
   AUDMA_LOCK(AUDMA_ID_FS);
   #endif

   ret_val = ((kal_take_sem(Mutex->rtf_sem, (kal_wait_mode)Timeout) == KAL_SUCCESS) ? RTF_NO_ERROR : MT_LOCK_MUTEX_FAIL);

   if (ret_val != RTF_NO_ERROR)
   {
      #if defined(__AUDIO_DSP_LOWPOWER__)
      AUDMA_UNLOCK(AUDMA_ID_FS);
      #endif

      return ret_val;
   }

   /* Update owner and lock count */
   Mutex->rtf_sem_owner = current_task;
   Mutex->rtf_lock_count = 1;

   return (ret_val);
}

/*************************************************************************
* FUNCTION
*  RTFSYSFreeMutex
*
* DESCRIPTION
*  This function implements to release filesystem mutex
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void RTFAPI
RTFSYSFreeMutex(RTFMutex * Mutex)
{
   kal_taskid current_task;

   #ifdef __P_PROPRIETARY_COPYRIGHT__
/* under construction !*/
/* under construction !*/
   #endif

   current_task = kal_get_current_thread_ID();

   // task not ready
   if(current_task == KAL_NILTASK_ID)
      return;
   /*
    * Bypass all FS lock operations in exception mode to avoid unexpected suspend behavior. (W10.37)
    *
    * NOTE 1. If a "HISR" triggers an exception, bypass lock operation to avoid another fatal error
    *         because only "task" can get semaphore (kal_take_sem) successfully.
    *
    * NOTE 2. HISR should NOT use FS in normal mode. It only walks here when an exception is triggerred in HISR.
    */
   else if (INT_QueryExceptionStatus() == KAL_TRUE)
      return;

   #ifndef WIN32
   if (INT_QueryExceptionStatus() == KAL_FALSE) /* Should only be possible for exception cases */
      fs_assert_local(Mutex->rtf_sem_owner == current_task);
   #else
      fs_assert_local(Mutex->rtf_sem_owner == current_task);
   #endif

   Mutex->rtf_lock_count--;

   if (Mutex->rtf_lock_count == 0)
   {
      Mutex->rtf_sem_owner = KAL_NILTASK_ID;
      /* Solve MMI hang for waiting lock, Karen Hsu, 2004/04/23, ADD START */
      Mutex->DeviceNum_1 = 0;
      Mutex->DeviceNum_2 = 0;
      /* Solve MMI hang for waiting lock, Karen Hsu, 2004/04/23, ADD END */

      kal_give_sem(Mutex->rtf_sem);

      #if defined(__AUDIO_DSP_LOWPOWER__)
      AUDMA_UNLOCK(AUDMA_ID_FS);
      #endif
   }
}
#endif /* !__FS_CARD_DOWNLOAD__ */
/*************************************************************************
* FUNCTION
*  RTFSYSAllocTLS
*
* DESCRIPTION
*  This function implements to record filesystem internal task index
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
int RTFAPI
RTFSYSAllocTLS(void)
{
	fs_assert_local(FS_TLS_Index < MAX_TLS_INDEX);
	return(++FS_TLS_Index);
}

/*************************************************************************
* FUNCTION
*  stack_config
*
* DESCRIPTION
*  This function implements to config Protocol Stack's configuration
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void RTFAPI
RTFSYSSetTLS(int Index, void * Value)
{
    kal_uint8 task_indx;

#ifndef __FS_CARD_DOWNLOAD__
    kal_taskid current_task;

    fs_assert_local(Index <= FS_TLS_Index);

    current_task = kal_get_current_thread_ID();
    /* Find current task id is registered or not */
    for (task_indx=0; task_indx<FS_TCT_Index+1; task_indx++)
    {
        if (gFS_TaskList[task_indx] == current_task) break;
    }

    /* Not found */
    if (task_indx == FS_TCT_Index+1)
    {
        if (FS_TCT_Index >= FS_MAX_THREAD)
        {
            fs_err_internal_fatal(FS_ERR_TLS_02, (void*)FS_MAX_THREAD);
            return;
        }

        /* Register current task id as new one */
        gFS_TaskList[FS_TCT_Index] = current_task;
        gFS_TaskData[FS_TCT_Index][Index] = (_XData*)Value;
        FS_TCT_Index++;
        return;
    }
#else
    task_indx = 0;
#endif
    gFS_TaskData[task_indx][Index] = (_XData*)Value;

    return;
}

kal_uint8 RTFAPI RTFSYSGetTaskIndex()
{
#ifndef __FS_CARD_DOWNLOAD__
   kal_uint8 task_indx;
   kal_taskid current_task;

   current_task = kal_get_current_thread_ID();

   for (task_indx = 0; task_indx <= FS_TCT_Index; task_indx++)
      if (gFS_TaskList[task_indx] == current_task) return task_indx;

   if (FS_TCT_Index >= FS_MAX_THREAD)
   {
      fs_err_internal_fatal(FS_ERR_TLS_02, (void*)FS_MAX_THREAD);
   }

   // Register current task id as new one
   gFS_TaskList[FS_TCT_Index++] = current_task;

   return (FS_TCT_Index - 1);
#else
   return 0;
#endif
}

/*************************************************************************
* FUNCTION
*  stack_config
*
* DESCRIPTION
*  This function implements to config Protocol Stack's configuration
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_taskid _fs_int_missed_task;
void * RTFAPI
RTFSYSGetTLS(int Index)
{
    kal_uint8 task_indx;
#ifndef __FS_CARD_DOWNLOAD__
    kal_taskid current_task;

    fs_assert_local(Index < MAX_TLS_INDEX);

    current_task = kal_get_current_thread_ID();
    for (task_indx=0; task_indx<FS_TCT_Index+1; task_indx++)
    {
        if (gFS_TaskList[task_indx] == current_task) break;
    }

    //fs_assert_local(task_indx != FS_TCT_Index);
    if(task_indx == FS_TCT_Index+1)
    {
        _fs_int_missed_task = current_task;
        return (void*)FS_TLS_DEFAULT;
    }
#else
    task_indx = 0;
#endif

    return(void*)gFS_TaskData[ task_indx ][ Index ];
}


int RTFSYSGetThreadCount(void)
{
    return FS_TCT_Index;
}

/*
 * File System Exception (Assert and Fatal) Handlers
 */

#if !defined(__UBL__)

void *              _gfs_err_info               = NULL;
kal_uint32          _gfs_err_assert_line        = 0;
fs_src_file_enum    _gfs_err_assert_file        = rtfiles_c;
kal_uint32          _gfs_err_assert_param[3]    = {0, 0, 0};

void fs_err_assert_ext(fs_src_file_enum file, kal_uint32 line, kal_uint32 e1, kal_uint32 e2, kal_uint32 e3)
{
    kal_uint32 lr;
    FS_GET_RETURN_ADDRESS(lr);
    _gfs_err_assert_line        = line;
    _gfs_err_assert_file        = file;
    _gfs_err_assert_param[0]    = e1;
    _gfs_err_assert_param[1]    = e2;
    _gfs_err_assert_param[2]    = e3;
    kal_fatal_error_handler(KAL_ERROR_FILESYS_NORMAL_FAILED, lr);  // A02
}

void fs_err_assert(fs_src_file_enum file, kal_uint32 line)
{
    kal_uint32 lr;
    FS_GET_RETURN_ADDRESS(lr);
    _gfs_err_assert_line    = line;
    _gfs_err_assert_file    = file;
    kal_fatal_error_handler(KAL_ERROR_FILESYS_NORMAL_FAILED, lr); // A02
}

void fs_err_user_fatal(kal_int32 code, void *info)
{
    kal_fatal_error_handler(KAL_ERROR_FILESYS_INTERNAL_FAILED, (kal_uint32)info);  // A01
}

void fs_err_internal_fatal(kal_int32 code, void *info)
{
    kal_uint32 lr;
    FS_GET_RETURN_ADDRESS(lr);
    _gfs_err_info = info;
    kal_fatal_error_handler(KAL_ERROR_FILESYS_NORMAL_FAILED, lr);  // A02
}

#endif // !__UBL__

