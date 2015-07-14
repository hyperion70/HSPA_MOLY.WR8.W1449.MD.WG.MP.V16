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
 *	fs_func.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *    This file wrap the file system
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "fs_internal_def.h"
#include "fs_gprot.h"
#include "fs_iprot.h"
#include "rtfiles.h"
#include "rtfex.h"
#include "rtfbuf.h"
#include "fs_kal.h"
#include "fs_internal.h"
#include "fs_utility.h"
#include "fs_internal_api.h"
#include "kal_trace.h"
#include "fs_trc.h"     // "stack_config.h" is included by "kal_release.h"

#if defined(__BOOT_FAT_RESET__)
#include "kbd_table.h"
#endif /* __BOOT_FAT_RESET__ */

#include "init.h"
#include "system_trc.h"
#include "init_trc_api.h"

#include "fs_errcode.h"
#include "string.h"
#include "setjmp.h"

#if !defined(__MODEM_CCCI_EXIST__)

// Trace
#define fs_util_trace_err_noinfo(error_code) fs_util_trace_err_slim(error_code, fs_func_c, __LINE__)

// Assert
#define fs_assert_local(expr) fs_assert(expr, fs_func_c)
#define fs_ext_assert_local(expr, e1, e2, e3) fs_ext_assert(expr, fs_func_c, e1, e2, e3)

extern kal_bool    INT_QueryExceptionStatus(void);
extern kal_uint32  INT_GetCurrentTime(void);
extern void        InitDebugPrint(void);
extern void        DebugPrint(kal_uint8, kal_uint8, kal_uint8*);
extern UINT        OpenHintStamp;
#if defined(__MTP_ENABLE__)
extern void        *SysLockFATTask;
#endif /* __MTP_ENABLE__ */
kal_bool           FATReset = KAL_FALSE;	//__BOOT_FAT_RESET__. Cannot enclose with __BOOT_FAT_RESET__ because NAND FDM will use this.

/*
 * locals
 */

#if !defined(__FS_QM_SUPPORT__) && defined(__MTK_TARGET__)
sys_indirect_init_func g_fs_dummy_init = 0;
#endif

void FS_Config(fs_config_enum type, void * data)
{
    if (type == FS_CONFIG_UTILITY_FUNC)
    {
        _gfs_util_ucs_to_wchar_func = ((fs_config_encoding_api_struct *)data)->ucs_to_wchar_func;

        _gfs_util_get_default_encoding_length_func = ((fs_config_encoding_api_struct *)data)->get_default_encoding_length_func;
    }
}


/* ------------------------------------------------------------------------------- */
int FS_OpenLR(const WCHAR * FileName, kal_uint32 Flag, kal_uint32 caller_address)
{
    int Result = RTF_NO_ERROR;
    WCHAR * FileName2;

    fs_util_trace_info2(TRACE_FUNC | MT_TRACE_INFO_WSTR, FS_API_FS_OPEN_S, caller_address, Flag, (void*)FileName);

    FileName2 = TruncateWideWhiteSpacesAndPeriods(FileName);

#if !defined(__MTK_TARGET__)
    Flag &= ~FS_PROTECTION_MODE;
#endif

    Result = RTFOpen(FileName2, Flag, caller_address);

    fs_util_trace_info1(TRACE_FUNC, FS_API_FS_OPEN_E, (kal_uint32)Result, NULL);

    fs_util_check_stack();

    return Result;
}

/* ------------------------------------------------------------------------------- */
int FS_Open(const WCHAR * FileName, kal_uint32 Flag)
{
    kal_uint32 lr;
    FS_GET_RETURN_ADDRESS(lr);

    return FS_OpenLR(FileName, Flag, lr);
}

/* ------------------------------------------------------------------------------- */
int FS_Close(FS_HANDLE FileHandle)
{
   int Result = RTF_NO_ERROR;
   fs_util_time_init();

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_CLOSE_S, FileHandle, NULL);
   fs_util_time_start();

   Result = RTFClose(FileHandle);

   fs_util_time_stop();
   fs_util_trace_info2(TRACE_FUNC, FS_API_FS_CLOSE_E, Result, fs_util_time_get_duration(), NULL);

   fs_util_check_stack();

   return Result;
}

/* ------------------------------------------------------------------------------- */
int FS_Read(FS_HANDLE FileHandle, void * DataPtr, kal_uint32 Length, kal_uint32 * Read)
{
   int         Result = RTF_NO_ERROR;
   kal_uint32  read_int;

   fs_util_time_init_with_duration();

   /*
    *  RTFRead() accepts NULL "Read". We forcedily use internal Read instead of NULL
    *  for more solid trace, especially for throughput calculation.
    */
   if (NULL == Read) Read = &read_int;

   fs_util_trace_info4(TRACE_FUNC | MT_TRACE_INFO_FILE, FS_API_FS_READ_S, FileHandle, (kal_uint32)DataPtr, Length, NULL, (void*)fs_conf_get_file_by_fh(FileHandle));
   fs_util_time_start();

   Result = RTFRead(FileHandle, DataPtr, Length, Read);

   fs_util_time_stop();
   fs_util_time_set_duration();

   if (fs_util_time_query_duration() > 0)
      fs_util_trace_info4(TRACE_FUNC, FS_API_FS_READ_E, Result, *Read, fs_util_time_query_duration(), (kal_uint32)((Length * 976.5) / fs_util_time_query_duration()), NULL);
   else // avoid dividing by zero
      fs_util_trace_info4(TRACE_FUNC, FS_API_FS_READ_E, Result, *Read, 0, 0, NULL);

   fs_util_check_stack();

   return Result;
}

/* ------------------------------------------------------------------------------- */
int FS_Write(FS_HANDLE FileHandle, void * DataPtr, kal_uint32 Length, kal_uint32 * Written)
{
   int      Result = RTF_NO_ERROR;
   kal_uint32  written_int;

   fs_util_time_init_with_duration();

   /*
    *  RTFRead() accepts NULL "Read". We forcedily use internal Read instead of NULL
    *  for more solid trace, especially for throughput calculation.
    */
   if (NULL == Written) Written = &written_int;

   fs_util_trace_info4(TRACE_FUNC | MT_TRACE_INFO_FILE, FS_API_FS_WRITE_S, FileHandle, (UINT)DataPtr, Length, NULL, (void*)fs_conf_get_file_by_fh(FileHandle));
   fs_util_time_start();

   Result = RTFWrite(FileHandle, DataPtr, Length, Written);

   fs_util_time_stop();
   fs_util_time_set_duration();

   if (fs_util_time_query_duration() > 0)
      fs_util_trace_info4(TRACE_FUNC, FS_API_FS_WRITE_E, Result, *Written,  fs_util_time_query_duration(), (kal_uint32)((Length * 976.5) / fs_util_time_query_duration()), NULL);
   else // avoid dividing by zero
      fs_util_trace_info4(TRACE_FUNC, FS_API_FS_WRITE_E, Result, *Written, 0, 0, NULL);

   fs_util_check_stack();

   return Result;
}

kal_int64 FS_SeekLargeFile(FS_HANDLE FileHandle, kal_int64 Offset, int Whence)
{
   kal_int64 Result = RTF_NO_ERROR;

   fs_util_trace_info4(TRACE_FUNC, FS_API_FS_SEEKLARGEFILE_S, (kal_uint32)FileHandle, (kal_int32)Offset, (kal_int32)Offset, Whence, NULL);

   Result = RTFSeek(FileHandle, Offset, Whence);

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_SEEKLARGEFILE_E, (kal_int32)Result, NULL);

   fs_util_check_stack();

   return Result;
}

/* ------------------------------------------------------------------------------- */
int FS_Seek(FS_HANDLE FileHandle, int Offset, int Whence)
{
   kal_int64 Result = RTF_NO_ERROR;
   fs_util_time_init(); // for SQC FS smart file seeker only! Need to remove in W10.36MP

   fs_util_trace_info4(TRACE_FUNC | MT_TRACE_INFO_FILE, FS_API_FS_SEEK_S, (kal_uint32)FileHandle, Offset, Whence, NULL, NULL);
   fs_util_time_start();

   Result = RTFSeek(FileHandle, Offset, Whence);

   fs_util_time_stop();

   if (Result >= RTF_NO_ERROR)
   {
      if ((kal_int32)Result < 0)
         Result = FS_LONG_FILE_POS;
   }

   fs_util_trace_info2(TRACE_FUNC, FS_API_FS_SEEK_E, (kal_int32)Result, fs_util_time_get_duration(), NULL);

   fs_util_check_stack();

   return (kal_int32)Result;
}

/* ------------------------------------------------------------------------------- */
int FS_Commit(FS_HANDLE FileHandle)
{
   int Result = RTF_NO_ERROR;

   fs_util_trace_info1(TRACE_FUNC | MT_TRACE_INFO_FILE, FS_API_FS_COMMIT_S, FileHandle, (void*)fs_conf_get_file_by_fh(FileHandle));

   Result = RTFCommit(FileHandle, FS_COMMIT_RESUMESECTOR);

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_COMMIT_E, Result, NULL);

   fs_util_check_stack();

   return Result;
}

/* ------------------------------------------------------------------------------- */
int FS_GetFileSize(FS_HANDLE FileHandle, kal_uint32 * Size)
{
   int Result = RTF_NO_ERROR;

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_GETFILESIZE_S, FileHandle, NULL);

   Result = RTFGetFileSize(FileHandle, Size);

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_GETFILESIZE_E, *Size, NULL);

   fs_util_check_stack();

   return Result;
}

/* ------------------------------------------------------------------------------- */
int FS_Delete(const WCHAR * FileName)
{
   int Result = RTF_NO_ERROR;

   fs_util_trace_info0(TRACE_FUNC | MT_TRACE_INFO_WSTR, FS_API_FS_DELETE_S, (void*)FileName);

   Result = RTFDelete(FileName);

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_DELETE_E, Result, NULL);

   fs_util_check_stack();

   return Result;
}

/* ------------------------------------------------------------------------------- */
int FS_CreateDir(const WCHAR * DirName)
{
   int Result = RTF_NO_ERROR;
   WCHAR * DirName2;

   fs_util_trace_info0(TRACE_FUNC | MT_TRACE_INFO_WSTR, FS_API_FS_CREATEDIR_S, (void*)DirName);

   DirName2 = TruncateWideWhiteSpacesAndPeriods(DirName);

   Result = RTFCreateDir(DirName2, 0);

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_CREATEDIR_E, Result, NULL);

   fs_util_check_stack();

   return Result;
}

/* ------------------------------------------------------------------------------- */
int FS_CreateBootSector(void * BootSector, const FS_PartitionRecord * Partition, kal_uint8 MediaDescriptor, kal_uint32 MinSectorsPerCluster, kal_uint32 Flags)
{
   int Result = RTF_NO_ERROR;

   Result = RTFCreateBootSector(BootSector, (RTFPartitionRecord *)Partition, MediaDescriptor, MinSectorsPerCluster, Flags);

   fs_util_check_stack();

   return Result;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function returns the cluster size of the specified drive
PARAMETER
      DriveLetter: The drive letter ('Z' or 0x43, 0x44, ...etc.)
RETURN
      Success:  Cluster size in byte
      Error:    RTF_DRIVE_NOT_FOUND
                RTF_INVALID_FILE_SYSTEM
------------------------------------------------------------------------------- */
int FS_GetClusterSize(kal_uint32 DriveLetter)
{
   int volatile Result = RTF_DRIVE_NOT_FOUND;
   RTFDrive * Drive;

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_GETCLUSTERSIZE_S, DriveLetter, NULL);

   Drive = (RTFDrive*)fs_conf_get_drv_struct_by_drv_letter(DriveLetter);

   if (NULL == Drive)
   {
      return Result;
   }

   if (Drive->MountState == HasFileSystem && Drive->Dev->DevData.MountState >= Mounted)
   {
      Result = Drive->ClusterSize;
   }
   else
   {
      /* Tell caller that it was Not Initialized Yet */
      Result = FS_DRIVE_NOT_FOUND;
   }

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_GETCLUSTERSIZE_E, Result, NULL);

   fs_util_check_stack();

   return Result;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function Create the MBR (Sector 0)
PARAMETER
RETURN
NOTE
------------------------------------------------------------------------------- */
int FS_CreateMasterBootRecord(void * SectorBuffer, const FS_PartitionRecord * DiskGeometry)
{
   int Result = RTF_NO_ERROR;

   Result = RTFCreateMasterBootRecord(SectorBuffer, (RTFPartitionRecord *)DiskGeometry);

   fs_util_check_stack();

   return Result;
}

/* ------------------------------------------------------------------------------- */
void FS_ShutDown(void)
{
   fs_util_trace_info0(TRACE_FUNC, FS_API_FS_SHUTDOWN_S, NULL);

   RTFShutDown();

   fs_util_check_stack();
}



/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides a facility to handle the following critical jobs
      (1) RUN ONCE
          <a> file system initialization,
              fixed device mount, system drive mount
          <b> make 'Z' drive letter as system drive alias
          <c> system drive power lose recovery
          <d> file system trace/debug level default setting
          <e> system drive quota sweep
          <f> mount removable card device
      (2) RUN AFTER FILE SYSTEM INITIALIZED
          <g> quota configure check
PARAMETER
      None
RETURN
      (1) Return <c> status , power lose recovery on system drive
      (2) OK:      RTF_NO_ERROR
          ERROR:   MT_QUOTA_OVER_DISK_SPACE
                   MT_QUOTA_USAGE_WARNING
NOTE
   This function cannot wait to get any lock!
------------------------------------------------------------------------------- */

/* for file table */
#ifdef __MTK_TARGET__
extern kal_uint32 _fs_filetable$$Base, _fs_filetable$$Length;
#else
RTFile __pragma(data_seg("_fs_filetable_begin")) _fs_file_table_begin_p = {0};

#pragma comment(linker, "/MERGE:_fs_filetable_content=_fs_filetable_begin")

RTFile __pragma(data_seg("_fs_filetable_end")) _fs_file_table_end_p = {0};

#pragma comment(linker, "/MERGE:_fs_filetable_end=_fs_filetable_begin")
#endif

/* for general indirect init function */
#ifdef __MTK_TARGET__
#ifndef __MAUI_BASIC__
extern kal_uint32 _indirect_init$$Base, _indirect_init$$Length;
#endif
#else
__fs_align(32) kal_uint32 __pragma(data_seg("_indirect_init_begin")) _indirect_init_begin_p = 0;

#pragma comment(linker, "/MERGE:_indirect_init_content=_indirect_init_begin")

__fs_align(32) kal_uint32 __pragma(data_seg("_indirect_init_end")) _indirect_init_end_p = 0;

#pragma comment(linker, "/MERGE:_indirect_init_end=_indirect_init_begin")
#endif

void FS_SetFileTable(void *table)
{
}

int FS_SanityCheck(void)
{
   int         Result = RTF_NO_ERROR;
   int         drvLetter;
   RTFDevice   *Dev = NULL;
   int         fh, i;
   WCHAR       path[4] = {'X', ':', '\\', 0};

   /* get the device that contains system drive */
   Dev = &gFS_DeviceList[gFS_DeviceNumOfSYSDRV - 1];

   if (RTFLock == NULL)
   /* RUN ONCE Block */
   {
        #ifdef __FS_QM_SUPPORT__
        /* for general indirect init function */
        {
            typedef void (*_indirect_init_func)(void);
            kal_uint32 i, total = 0;
            kal_uint32 *value;

            #ifdef __MTK_TARGET__
            #ifndef __MAUI_BASIC__

                #if !defined(__FS_QM_SUPPORT__)
                g_fs_dummy_init = 0;
                #endif

            value = (kal_uint32 *)&_indirect_init$$Base;
            total = (kal_uint32)&_indirect_init$$Length/sizeof(_indirect_init_func);
            #endif  // !__MAUI_BASIC__

            #else   // !__MTK_TARGET__
            value = (kal_uint32 *)&_indirect_init_begin_p;
            total = (kal_uint32)(&_indirect_init_end_p - &_indirect_init_begin_p) - 1;
            #endif  // __MTK_TARGET__

            for (i = 0; i < total; i++)
            {
                _indirect_init_func init_func = (_indirect_init_func)((kal_uint32 *)*(value + i));

                if (init_func)
                {
                    init_func();
                }
            }
        }
        #endif

        // if MMI not present, user provided external file table memory section is ignore,
        // use internal table gFS_FileTable pre-defined in fs_config.c by default.
        #if !defined(__EMPTY_MMI__)

   	    /* for file table */
        #ifdef __MTK_TARGET__

        gFS_Data.FileTable = (RTFile *)&_fs_filetable$$Base;
        FS_MAX_FILES = (kal_uint32)&_fs_filetable$$Length/sizeof(FS_File);

        #else   // !__MTK_TARGET__

        gFS_Data.FileTable = (RTFile *)&_fs_file_table_begin_p;
        FS_MAX_FILES = (kal_uint32)(&_fs_file_table_end_p - &_fs_file_table_begin_p);

        #endif  // __MTK_TARGET__

        #endif

      print_bootup_trace_enter(SST_INIT_RTFINIT);
      RTFInit();
      print_bootup_trace_exit(SST_INIT_RTFINIT);

      //--- Drive Remapping ---

      drvLetter = MTGetDrive(MT_DRIVE_I_SYSTEM, 1, MT_NO_ALT_DRIVE);

      /* make 'Z' drive letter as system drive alias */
      if (drvLetter > 0)
      {
         MTMappingDrive(drvLetter, 90);
      }

#ifdef __BOOT_FAT_RESET__
      // check if user triggers file system reset
      if (fs_util_kbd_is_key_pressed(DEVICE_KEY_LEFT) && fs_util_kbd_is_key_pressed(DEVICE_KEY_END))
      {
          WCHAR FileName[7];  // __BOOT_FAT_RESET__

          fs_util_pwm_poweron();
          FATReset = KAL_TRUE;
          InitDebugPrint();

          DebugPrint(0, 10, (kal_uint8*)"Formatting SysDrv");
          kal_dchar_strcpy((char*)FileName, (char*)L"\\\\.\\Z:");
          FS_GeneralFormat(FileName, FS_FORMAT_LOW, NULL);

          DebugPrint(0, 10, (kal_uint8*)"Formatting UserDrv");
          drvLetter = MTGetDrive(MT_DRIVE_V_NORMAL, 1, MT_NO_ALT_DRIVE);
          if(drvLetter > 0)
          {
          	  FileName[4] = drvLetter;
              FS_GeneralFormat(FileName, FS_FORMAT_LOW, NULL);
          }
          FATReset = KAL_FALSE;
      }
#endif // __BOOT_FAT_RESET__

      if ( (Dev->DevData.ErrorCondition == FS_FDM_USER_DRIVE_BROKEN)
         ||(Dev->DevData.ErrorCondition == FS_FDM_SYS_DRIVE_BROKEN)
         ||(Dev->DevData.ErrorCondition == FS_FDM_MULTIPLE_BROKEN)
         ||(Dev->DevData.ErrorCondition == FS_FDM_VERSION_MISMATCH)
         )
      {
         Result = Dev->DevData.ErrorCondition;
      }
      if (Result == RTF_NO_ERROR)
      {
      	 print_bootup_trace_enter(SST_INIT_RTFSANITY);
         Result = RTFSanityCheck();
         print_bootup_trace_exit(SST_INIT_RTFSANITY);

#ifdef __FS_QM_SUPPORT__
         if (kal_query_boot_mode() != USBMS_BOOT)
         {
            SweepDrive('Z');
         }
#endif /* __FS_QM_SUPPORT__ */
      }

      // mount removable device (memory card)
      Dev = (RTFDevice*)fs_conf_find_dev_by_devtype(FS_DEVICE_TYPE_CARD, 1);

      if (Dev != NULL)
      {
         MountRemovableDevice(Dev);
      }

      #ifdef __FS_CARD2_SUPPORT__
      // mount removable device (memory card #2)
      Dev = (RTFDevice*)fs_conf_find_dev_by_devtype(FS_DEVICE_TYPE_CARD, 2);

      if (Dev != NULL)
      {
         MountRemovableDevice(Dev);
      }
      #endif // __FS_CARD2_SUPPORT__

      /*
       * Try to mount all non-removable drives to HasFileSystem stage by opening "root directory"
       * NOTE: Do not use opening "volume file" because drive will be set as Unmounted after "volume file" is closed. (W09.52)
       */
      for (i = 0; i < FS_MAX_DRIVES; i++)
      {
         if (gFS_Data.DriveTable[i].Dev == NULL)
         {
            break;
         }

         /*
          * Previously drive should be mounted as Mounted in ScanPartitionTable()->InitLogicalDrive()
          * System drive should be mounted as HasFileSystem in RTFCheckBootUpFlag()
          */
         if ((gFS_Data.DriveTable[i].Dev->DeviceFlags & (FS_DEVICE_NAND_FLASH | FS_DEVICE_NOR_FLASH)) &&
         	 (gFS_Data.DriveTable[i].MountState < HasFileSystem))
         {
            path[0] = i + MT_BASE_DRIVE_LETTER;

            fh = FS_Open(path, FS_READ_ONLY);   // open the root dir to mount drive

            if (fh > FS_NO_ERROR)
            {
               FS_Close(fh);
            }
         }
      }
   }
   else
   /* 2ND CALL Block */
   {
      if ( (Dev->DevData.ErrorCondition == FS_FDM_USER_DRIVE_BROKEN)
         ||(Dev->DevData.ErrorCondition == FS_FDM_SYS_DRIVE_BROKEN)
         ||(Dev->DevData.ErrorCondition == FS_FDM_MULTIPLE_BROKEN)
         ||(Dev->DevData.ErrorCondition == FS_FDM_VERSION_MISMATCH)
         )
      {
         Result = Dev->DevData.ErrorCondition;
      }

      if (Result == RTF_NO_ERROR)
      {
#ifdef __FS_QM_SUPPORT__
         Result = ChkQuotaConfig('Z');
#endif /* __FS_QM_SUPPORT__ */
      }
   }

   return Result;
}

/* ------------------------------------------------------------------------------- */
int FS_SetDiskFlag(void)
{
   int Result = RTF_NO_ERROR;

   Result = RTFSetBootUpFlag(KAL_TRUE);

   fs_util_check_stack();

   return Result;
}

/* ------------------------------------------------------------------------------- */
int FS_ClearDiskFlag(void)
{
   int Result = RTF_NO_ERROR;

   fs_util_trace_info0(TRACE_FUNC, FS_API_FS_CLEARDISKFLAG_S, NULL);

   Result = RTFSetBootUpFlag(KAL_FALSE);

   fs_util_check_stack();

   return Result;
}

/*******************************************************************//**
 * Unlock all devices and files (system error handling only!)
 *
 * @par Category:
 * File System
 **********************************************************************/
int FS_UnlockAll(void)
{
   int Result = RTF_NO_ERROR;

   fs_util_trace_info0(TRACE_FUNC, FS_API_FS_UNLOCKALL_S, NULL);

   Result = RTFUnlockAll();

   fs_util_check_stack();

   return Result;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      Reterive information about a logical drive
PARAMETER
RETURN
NOTE
------------------------------------------------------------------------------- */
int FS_GetDiskInfo(const WCHAR * DriveName, FS_DiskInfo * DiskInfo, int Flags)
{
   int Result = RTF_NO_ERROR;
   int i;
   RTFDevice * volatile Dev=NULL;

   fs_util_trace_info2(TRACE_FUNC, FS_API_FS_GETDISKINFO_S, *(kal_uint8*)DriveName, Flags, NULL);

   i = FindDeviceNumberByDriveIdx((int)DriveName[0]);

   if (i)
   {
      Dev = &gFS_DeviceList[i - 1];
      if (CardBusyCheck && (Dev->DeviceFlags & RTF_DEVICE_REMOVABLE))
      {
         if (FS_GetDevStatus(FS_DEVICE_TYPE_CARD, FS_FEATURE_STATE_ENUM) == FS_DEVICE_BUSY)
         {
            Result = FS_DEVICE_BUSY;

            fs_util_trace_info2(TRACE_FUNC, FS_API_FS_GETDISKINFO_E_DEV, Result, fs_conf_get_devtype_by_devflag(Dev->DeviceFlags), NULL);

            return Result;
         }
      }
   }

   fs_init();

   if(MTDiskInfoLock == NULL)
      MTDiskInfoLock = RTFSYSAllocMutex("MTDSKIFLock");

   if (Dev && (Dev->DeviceFlags & RTF_DEVICE_REMOVABLE))
   {
      SafeLock(MT_LOCK_DISKIF, NULL, RTF_INFINITE);
      MTDiskInfoLock->DeviceNum_1 = i;
   }

   Result = RTFGetDiskInfoEx(DriveName, (RTFDiskInfo *)DiskInfo, Flags);

   if (Dev && (Dev->DeviceFlags & RTF_DEVICE_REMOVABLE))
   {
      MTDiskInfoLock->DeviceNum_1 = 0;
      SafeUnlock(MT_LOCK_DISKIF);
   }

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_GETDISKINFO_E, Result, NULL);

   fs_util_check_stack();

   return Result;
}

/* ------------------------------------------------------------------------------- */
int FS_OpenHintLR(const WCHAR * FileName, kal_uint32 Flag, FS_FileOpenHint * DSR_Hint, kal_uint32 caller_address)
{
   int Result = RTF_NO_ERROR;
   WCHAR * FileName2;

   if (DSR_Hint != NULL)
      fs_util_trace_info4(TRACE_FUNC | MT_TRACE_INFO_WSTR, FS_API_FS_OPENHINT_S_HINT, caller_address, Flag, DSR_Hint->Cluster, DSR_Hint->Index, (void*)FileName);
   else
      fs_util_trace_info2(TRACE_FUNC | MT_TRACE_INFO_WSTR, FS_API_FS_OPENHINT_S, caller_address, Flag, (void*)FileName);

   FileName2 = TruncateWideWhiteSpacesAndPeriods(FileName);

#if !defined(__MTK_TARGET__)
       Flag &= ~FS_PROTECTION_MODE;
#endif

   Result = RTFOpenHint(FileName2, Flag, (RTFDirLocation *)DSR_Hint, caller_address);

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_OPENHINT_E, Result, NULL);

   fs_util_check_stack();

   return Result;
}


/* ------------------------------------------------------------------------------- */
int FS_OpenHint(const WCHAR * FileName, kal_uint32 Flag, FS_FileOpenHint * DSR_Hint)
{
    kal_uint32 lr;
    FS_GET_RETURN_ADDRESS(lr);

    return FS_OpenHintLR(FileName, Flag, DSR_Hint, lr);
}

int FS_GetSysInfo(kal_uint32 options, fs_sysinfo_struct *info)
{
    // paramter check
    if (info == NULL || (options & FS_SI_ALL) == 0)
    {
        return FS_PARAM_ERROR;
    }

    // query body
    if (options & FS_SI_BASIC_INFO)
    {
        //--- RTFiles32

        if (RTFLock != NULL)
        {
            info->initialized = 1;
        }
        else
        {
            info->initialized = 0;
        }
    }

    return FS_NO_ERROR;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides a facility to let task looks up the
      device status
PARAMETER
      QueryTarget: the index number get from FS_GetDrive
                OR the type enum get from FS_GetDevType
      Flag:        FS_MOUNT_STATE_ENUM
                or FS_FEATURE_STATE_ENUM
                or FS_EXPORT_STATE_ENUM
RETURN
      Success:  RTF_NO_ERROR (means depends on the flag,
                              FS_MOUNT_STATE_ENUM => Mounted,
                              FS_FEATURE_STATE_ENUM => Device not busy,
                              FS_EXPORT_STATE_ENUM => Device not exported.)
                              FS_CARD_BATCHCOUNT_STATE_ENUM => Is free cluster counted on CARD
      Error:    RTF_PARAM_ERROR
                MT_MSDC_MOUNT_ERROR
                MT_FLASH_MOUNT_ERROR
                MT_DEVICE_BUSY
                MT_DEVICE_EXPORTED_ERROR
NOTE
   This function cannot wait to get any lock!
------------------------------------------------------------------------------- */
int FS_GetDevStatus(kal_uint32 QueryTarget, kal_uint32 QueryType)
{
    RTFDrive        *Drive = NULL;
    RTFDevice       *Dev = NULL;
    kal_taskid      current_task;
    RTFDeviceInfo   dev_info;
    int             result = RTF_PARAM_ERROR;

    // lower-case drive letter should be acceptable (W10.18)
    QueryTarget = fs_util_wchar_toupper(QueryTarget);

    // locate Drive by index , or find it by type flag
    if (QueryTarget >= MT_BASE_DRIVE_LETTER && QueryTarget < (MT_BASE_DRIVE_LETTER + FS_MAX_DRIVES))
    {
        fs_util_trace_info2(TRACE_FUNC, FS_API_FS_GETDEVSTATUS_S_DRIVE, QueryTarget, QueryType, NULL);

        Drive = &gFS_Data.DriveTable[QueryTarget - MT_BASE_DRIVE_LETTER];
    }
    else if (QueryTarget < FS_DEVICE_TYPE_MAX_VALUE)
    {
        fs_util_trace_info2(TRACE_FUNC, FS_API_FS_GETDEVSTATUS_S_TYPE, QueryTarget, QueryType, NULL);

        Dev = (RTFDevice*)fs_conf_find_dev_by_devtype((FS_DEVICE_TYPE_ENUM)QueryTarget, 1);
    }
    else
    {
        // Fall through... and return PARAM_ERROR
    }

    // Return if neither Dev nor Drive found
    if (Drive == NULL && Dev == NULL)
    {
        // Fall through... and return PARAM_ERROR
    }
    else
    {
        // Now Do Query job
        if (Dev == NULL)
        {
            Dev = Drive->Dev;
        }

        switch (QueryType)
        {
            case FS_MOUNT_STATE_ENUM:
                if (Dev->DevData.MountState >= Mounted)
                {
                    if ((Drive == NULL) ||  /* QueryTarget is Device */
                    (Drive != NULL && Drive->MountState == HasFileSystem) /* QueryTarget is Drive */)
                    {
                        if (Dev->DevData.Reserved &FS_DEVICE_COUNT_FREE_CLUSTER)
                        {
                            result = MT_DEVICE_BUSY;

                            break;
                        }
                        else
                        {
                            result = RTF_NO_ERROR;
                            break;
                        }
                    }
                    #ifdef __FS_LIMITED_DISK_SIZE__
                    else if (NULL != Drive && SizeExceeded == Drive->MountState)
                    {
                        result = MT_DISK_SIZE_TOO_LARGE;
                        break;
                    }
                    #endif
                }

                if (Drive == NULL && (Dev->DeviceFlags &MT_DEVICE_EXTERNAL))
                /* QueryTarget is Device, query for OTG Card Reader */
                {
                    if (g_ExternalDevice == KAL_TRUE)
                    {
                        result = RTF_NO_ERROR;
                        break;
                    }

                    result = MT_EXTERNAL_DEVICE_NOT_PRESENT;

                    break;
                }
                /* Otherwise, treat as built-in card or card-slot */
                else if (Dev->DeviceFlags & RTF_DEVICE_REMOVABLE)
                {
                    result = MT_MSDC_MOUNT_ERROR;

                    break;
                }
                else if (Dev->DeviceFlags &(MT_DEVICE_NAND_FLASH | MT_DEVICE_NOR_FLASH))
                {
                    if (Dev->DevData.ErrorCondition < 0)
                    {
                        result = Dev->DevData.ErrorCondition;

                        break;
                    }
                    else
                    {
                        result = MT_FLASH_MOUNT_ERROR;

                        break;
                    }
                }
                // should not touch here, but throw away
                break;

            case FS_FEATURE_STATE_ENUM:
                current_task = kal_get_current_thread_ID();

                if (MTFMLock)
                {
                    if (MTFMLock->DeviceNum_1 == Dev->DeviceNumber)
                    // Candidates : FS_CheckDrive() , FS_GeneralFormat(), FS_TestMSDC() (Specifiec for FMT task)
                    if (MTFMLock->rtf_sem_owner != current_task)
                    {
                        result = MT_DEVICE_BUSY;

                        break;
                    }
                }

                if (MTMoveLock)
                {
                    if ((MTMoveLock->DeviceNum_1 == Dev->DeviceNumber) ||
                        (MTMoveLock->DeviceNum_2 == Dev->DeviceNumber))
                    {
                        // Candidates : FS_Move()
                        if (MTMoveLock->rtf_sem_owner != current_task)
                        {
                            result = MT_DEVICE_BUSY;

                            break;
                        }
                    }
                }

                if (MTXdelLock)
                {
                    if (MTXdelLock->DeviceNum_1 == Dev->DeviceNumber)
                    {
                        // Candidates : FS_XDelete()
                        if (MTXdelLock->rtf_sem_owner != current_task)
                        {
                            result = MT_DEVICE_BUSY;

                            break;
                        }
                    }
                }

                if (MTXLock)
                {
                    if (MTXLock->DeviceNum_1 == Dev->DeviceNumber)
                    {
                        // Candidates : FS_Count() , FS_GetFolderSize(), FS_SetSeekHint()
                        if (MTXLock->rtf_sem_owner != current_task)
                        {
                            result = MT_DEVICE_BUSY;

                            break;
                        }
                    }
                }

                if (MTDiskInfoLock)
                {
                    if (MTDiskInfoLock->DeviceNum_1 == Dev->DeviceNumber)
                    {
                        // Candidates : FS_GetDiskInfo()
                        if (MTDiskInfoLock->rtf_sem_owner != current_task)
                        {
                            result = MT_DEVICE_BUSY;

                            break;
                        }
                    }
                }

                result = RTF_NO_ERROR;
                break;

            case FS_EXPORT_STATE_ENUM:

                // check EXPORTING flag
                if (Dev->DeviceFlags &MT_DEVICE_EXPORTING)
                {
                    result = MT_DEVICE_EXPORTED_ERROR;

                    break;
                }

                #if defined(__MTP_ENABLE__)
                // check MTP mode
                if (SysLockFATTask)
                {
                    kal_taskid TaskId = kal_get_current_thread_ID();

                    if (TaskId && strcmp(kal_get_task_name_ptr(TaskId), "NVRAM") != 0 &&  // not NVRAM
                    SysLockFATTask != TaskId)
                    // not SysLockFATTask owner
                    {
                        result = MT_DEVICE_EXPORTED_ERROR;

                        break;
                    }
                }
                #endif /* __MTP_ENABLE__ */

                result = RTF_NO_ERROR;
                break;

            case FS_CARD_BATCHCOUNT_STATE_ENUM:

                if (Dev->DeviceFlags &RTF_DEVICE_REMOVABLE)
                {
                    if (Drive == NULL)
                    {
                        Drive = Dev->DevData.FirstDrive;
                    }
                    if (Drive != NULL)
                    {
                        if (Drive->FreeClusterCount == RTF_INVALID_CLUSTER)
                        {
                            result = FS_CARD_BATCHCOUNT_NOT_PRESENT;

                            break;
                        }
                        else
                        {
                            result = FS_NO_ERROR;
                            break;
                        }
                    }
                }

                break;

            case FS_DEVICE_PRESENCE_ENUM:

                /*--------------------------------------
                 * Detect if device exists.
                 * Only support memory card currently.
                 *--------------------------------------*/

                if (Dev->DeviceFlags &RTF_DEVICE_REMOVABLE)
                {
                    if (Dev->Driver->IOCtrl == NULL)
                    {
                        result = FS_UNSUPPORTED_DRIVER_FUNCTION;

                        break;
                    }
                    else
                    {
                        dev_info.DeviceInfo.Card.Flag = 0;
                        Dev->Driver->IOCtrl(Dev->DriverData, FS_IOCTRL_QUERY_CARD_INFO, &dev_info);

                        if (dev_info.DeviceInfo.Card.Flag &MT_DEVICE_FLAG_PRESENT)
                        {
                            return FS_NO_ERROR;
                        }
                        else
                        {
                            result = FS_MSDC_NOT_PRESENT;

                            break;
                        }
                    }
                }
                else
                {
                    // for other devices type, temporarily return FS_UNSUPPORTED_DRIVER_FUNCTION
                    result = FS_UNSUPPORTED_DRIVER_FUNCTION;

                    break;
                }

            default:
                break;
        }
    }

    if (result < FS_NO_ERROR)
    {
        fs_util_trace_err_noinfo(result);   // print error log using TRACE_ERROR filter
    }

    fs_util_trace_info1(TRACE_FUNC, FS_API_FS_GETDEVSTATUS_E, result, NULL);

    return result;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function Split the Partition 0
PARAMETER
RETURN
NOTE
------------------------------------------------------------------------------- */
int FS_SplitPartition(void * MasterBootRecord, kal_uint32 Sectors)
{
   int Result = RTF_NO_ERROR;

   Result = RTFSplitPartition(MasterBootRecord, Sectors);

   fs_util_check_stack();

   return Result;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides a facility to delete a file or folder
      recursively
PARAMETER
      FullPath       : Source path to be deleted
      Flag           : FS_FILE_TYPE, FS_DIR_TYPE, FS_RECURSIVE_TYPE
      RecursiveStack : A memory pointer to store deep folder hierarchy recrusive data
      StackSize      : The size of RecursiveStack
RETURN
      Success: >= RTF_NO_ERROR , Depends on number of objects processed by recursive engine
      Error:   RTF_PARAM_ERROR
               RTF_INVALID_FILENAME
               RTF_PATH_NOT_FOUND
               MT_FAIL_GET_MEM
               RTF_GENERAL_FAILURE
NOTE
      1. This API leverage the Recursive Class
------------------------------------------------------------------------------- */
int FS_XDeleteEx(const WCHAR * FullPath, kal_uint32 Flag, FS_ProgressCallback Progress, kal_uint8 *RecursiveStack, const kal_uint32 StackSize)
{
   int volatile Result = RTF_NO_ERROR;

   // set XDelete start flag in the beginning
   g_Xdelete = KAL_TRUE;

   fs_util_trace_info1(TRACE_FUNC | MT_TRACE_INFO_WSTR, FS_API_FS_XDELETEEX_S, Flag, (void*)FullPath);

   /* XDelete - 1 : Parameter Check */
   if (((Flag &  (FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE)) == 0) ||
        (Flag & ~(FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE)))
   {
      fs_util_trace_err_noinfo(RTF_PARAM_ERROR);

      return RTF_PARAM_ERROR;
   }

   fs_init();

   if(MTXdelLock == NULL)
      MTXdelLock = RTFSYSAllocMutex("MTXdelLock");

   Result = RecAUX_IsFolderRW(FullPath); // search once inside

   // last function call may spend lots of time (search parent), check if XDelete is aborted
   if (g_Xdelete != KAL_TRUE)
   {
      fs_util_trace_err_noinfo(MT_ABORTED_ERROR);

      return MT_ABORTED_ERROR;
   }

   // the path is a file
   if (Result == RTF_PARAM_ERROR)
   {
      if(!RecursiveStack)
      {
          SafeLock(MT_LOCK_XDEL, NULL, RTF_INFINITE);
          MTXdelLock->DeviceNum_1 = FindDeviceNumberByDriveIdx((int)FullPath[0]);
      }

      Result = RTFDelete(FullPath);

      if(!RecursiveStack)
      {
          MTXdelLock->DeviceNum_1 = 0;
          SafeUnlock(MT_LOCK_XDEL);
      }

      fs_util_trace_info1(TRACE_FUNC, FS_API_FS_XDELETEEX_E, Result, NULL);

      return Result;
   }

   if ( MT_MAXPATH_IN_WCHAR_UNIT <= kal_wstrlen(FullPath) )
   {
      Result = MT_PATH_OVER_LEN_ERROR;
   }

   if (Result < RTF_NO_ERROR)
   {
      fs_util_trace_err_noinfo(Result);

      return Result;
   }

   /* XDelete - 2 : Action */

   /*----------------------------------------------------------------------------------
    * Get MT_LOCK_XDEL only if RecursiveStack is NULL to prevent file system getting too
    * much control buffer.
    *----------------------------------------------------------------------------------*/
   if(!RecursiveStack)
   {
       SafeLock(MT_LOCK_XDEL, NULL, RTF_INFINITE);
       MTXdelLock->DeviceNum_1 = FindDeviceNumberByDriveIdx((int)FullPath[0]);
   }

   g_Xdelete = KAL_TRUE;

   Result = RecAUX_XDeleteFolder(FullPath, Flag | FS_XDEL_ABORT_WATCH, Progress, RecursiveStack, StackSize);

   g_Xdelete = KAL_TRUE;

   if(!RecursiveStack)
   {
       MTXdelLock->DeviceNum_1 = 0;
       SafeUnlock(MT_LOCK_XDEL);
   }

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_XDELETEEX_E, Result, NULL);

   fs_util_check_stack();

   return Result;
}

int FS_XDelete(const WCHAR * FullPath, kal_uint32 Flag, kal_uint8 *RecursiveStack, const kal_uint32 StackSize)
{
    return FS_XDeleteEx(FullPath, Flag, NULL, RecursiveStack, StackSize);
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides users to get drive name at run time
PARAMETER
      Type:
         MT_DRIVE_I_SYSTEM    (0x00000004)
         MT_DRIVE_V_NORMAL    (0x00000008)
         MT_DRIVE_V_REMOVABLE (0x00000010)
         MT_DRIVE_V_EXTERNAL  (0x00000020)
         MT_DRIVE_V_SIMPLUS  (0x00000040)
      Serial:
         Positive integer     (same type drive may have several choices)
      AltMask:
         MT_NO_ALT_DRIVE      (0x00000001, No alternative)
         MT_ONLY_ALT_SERIAL   (0x00000002, alternative serial)
         other                (OR alternative type)
RETURN
      Success:                0x43~0x47 (A~G)
      Error:                  RTF_PARAM_ERROR
                              RTF_DRIVE_NOT_FOUND
NOTE
       Drive name support:    Floppy*2 + NOR*2 + NAND*2 + Removable*n (n>0)
------------------------------------------------------------------------------- */
int FS_GetDrive(kal_uint32 Type, kal_uint32 Serial, kal_uint32 AltMask)
{
   int Result = RTF_NO_ERROR;

   fs_util_trace_info4(TRACE_FUNC, FS_API_FS_GETDRIVE_S, Type, Serial, AltMask, NULL, NULL);

   Result = MTGetDrive(Type, Serial, AltMask);

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_GETDRIVE_E, Result, NULL);

   fs_util_check_stack();

   return Result;
}

/* ------------------------------------------------------------------------------- */
int FS_GetFilePosition(FS_HANDLE fh, kal_uint32 *position)
{
   int result = RTF_NO_ERROR;

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_GETFILEPOSITION_S, fh, NULL);

   result = RTFGetFilePosition(fh, position);

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_GETFILEPOSITION_E, *position, NULL);

   fs_util_check_stack();

   return result;
}

/* ------------------------------------------------------------------------------- */
int FS_GetAttributes(const WCHAR * FileName)
{
   int Result = RTF_NO_ERROR;
   WCHAR * FileName2;

   fs_util_trace_info0(TRACE_FUNC | MT_TRACE_INFO_WSTR, FS_API_FS_GETATTRIBUTES_S, (void*)FileName);

   FileName2 = TruncateWideWhiteSpacesAndPeriods(FileName);
   Result = RTFGetAttributes(FileName2);

   if (FS_NO_ERROR == Result)
      fs_util_trace_info1(TRACE_FUNC, FS_API_FS_GETATTRIBUTES_E, Result, NULL);

   fs_util_check_stack();

   return Result;
}

int FS_GetFileInfoEx(FS_HANDLE FileHandle, FS_FileInfo *FileInfo, kal_uint32 Flags)
{
   int Result = RTF_NO_ERROR;

   fs_util_trace_info2(TRACE_FUNC, FS_API_FS_GETFILEINFO_S, FileHandle,(kal_uint32)FileInfo, NULL);

   Result = RTFGetFileInfo(FileHandle, (RTFFileInfo*)FileInfo, Flags);

   if (FS_NO_ERROR == Result) fs_util_trace_info0(TRACE_FUNC, FS_API_FS_GETFILEINFO_E, NULL);

   fs_util_check_stack();

   return Result;
}

/* ------------------------------------------------------------------------------- */
int FS_GetFileInfo(FS_HANDLE FileHandle, FS_FileInfo * FileInfo)
{
   int Result = RTF_NO_ERROR;

   fs_util_trace_info2(TRACE_FUNC, FS_API_FS_GETFILEINFO_S, FileHandle,(kal_uint32)FileInfo, NULL);

   Result = RTFGetFileInfo(FileHandle, (RTFFileInfo *)FileInfo, RTF_FI_ALL);

   if (FS_NO_ERROR == Result) fs_util_trace_info0(TRACE_FUNC, FS_API_FS_GETFILEINFO_E, NULL);

   fs_util_check_stack();

   return Result;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function return the flash type for the corresponding path
PARAMETER
      Path: The full-path which begin with drive letter
RETURN
      Success:  FS_DEVICE_TYPE_NOR (1)
                FS_DEVICE_TYPE_NAND (2)
                FS_DEVICE_TYPE_CARD (3)
                FS_DEVICE_TYPE_EXTERNAL (4)
      Error:    RTF_DRIVE_NOT_FOUND
------------------------------------------------------------------------------- */
int FS_GetDevType(const WCHAR * Path)
{
   int volatile   Result  = RTF_DRIVE_NOT_FOUND;
   FS_Drive       *Drive  = NULL;

   fs_util_trace_info0(TRACE_FUNC | MT_TRACE_INFO_WSTR, FS_API_FS_GETDEVTYPE_S, (void*)Path);

   fs_init();

   /* Get Drive */
   if (Path == NULL)
   {
      fs_util_trace_err_noinfo(RTF_PARAM_ERROR);

      return RTF_PARAM_ERROR;
   }

   Drive = fs_conf_get_drv_struct_by_drv_letter((WCHAR)Path[0]);

   /* Now Get Device Type by Drive ptr */
   if (Drive)
   {
      if(Drive->Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
         Result = FS_DEVICE_TYPE_NOR;
      else if(Drive->Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
         Result = FS_DEVICE_TYPE_NAND;
      #if defined(__EMMC_BOOTING__)
      else if(Drive->Dev->DeviceFlags & FS_DEVICE_EMMC)
         Result = FS_DEVICE_TYPE_EMMC;
      #endif
      else if(Drive->Dev->DeviceFlags & MT_DEVICE_EXTERNAL)
         Result = FS_DEVICE_TYPE_EXTERNAL;
      else if(Drive->Dev->DeviceFlags & RTF_DEVICE_REMOVABLE)
         Result = FS_DEVICE_TYPE_CARD;
   }

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_GETDEVTYPE_E, Result, NULL);

   return Result;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides user to specify several check points of file to speedup
      the seek function. FS_Seek will start to seek from these places.
PARAMETER
      FileHandle: The file handle to be seeked
      HintNum:    Number of hint
      Hint:       Pointer to user defined hint
RETURN
      Success:    The number of hint that is successfully set
      Error:      RTF_ACCESS_DENIED
NOTE
      1. User should specify the hint in "bytes".
      2. This function only provides hint. One should not call this to extend file.
         i.e. Hint in bytes cannot be larger than the file size.
      3. User should allocate and free the memory by himself
      4. User should sort the hint by himself (small to big), or hint setting will
         be stopped by the number not in sequence
      5. After processed, "index" in each hint entry is cluster-aligned and is a "absolute"
         file offset in bytes. "Cluster" is the corresponding cluster number of each index.
------------------------------------------------------------------------------- */
int FS_SetSeekHint(FS_HANDLE FileHandle, kal_uint32 HintNum, FS_FileLocationHint * Hint)
{
   int volatile Result = RTF_NO_ERROR;
   RTFile * volatile f = NULL;
   kal_uint32 Tmp1, Tmp2;
   kal_uint32 Ofs, Ofs2;
   kal_uint32 FileSize, ClusterSize, Index;

   fs_util_trace_info2(TRACE_FUNC, FS_API_FS_SETSEEKHINT_S, FileHandle, HintNum, NULL);

   if((RTFLock == NULL) || (Hint == NULL))
   {
      fs_util_trace_err_noinfo(RTF_ACCESS_DENIED);

      return RTF_ACCESS_DENIED;
   }

   if(MTXLock == NULL)
      MTXLock = RTFSYSAllocMutex("MTXLock");

   SafeLock(MT_LOCK_EXT, NULL, RTF_INFINITE);

   XTRY
      case XCODE:
         f = ParseFileHandle(FileHandle);

         FileSize = f->DirEntry.Dir.FileSize;
         ClusterSize = f->Drive->ClusterSize;
         Tmp2 = FIRST_FILE_CLUSTER(f->DirEntry.Dir);

         /* user only assign "index", we let those indexes cluster-aligned */

         #ifdef __FS_INTERVAL_BUFFER__
         fs_srv_buf_alloc();
         #endif

         while(1)
         {
            /* read index */
            Index = Hint[f->HintNum].Index;

            /* COMPLETE */
            if(f->HintNum == HintNum)
               break;

            /* STOP: index should be smaller than file size */
            if(Index > FileSize)
               break;

            /* STOP: index should be sorted (small to big) by user */
            if(f->HintNum)
            {
               if(Index < Hint[f->HintNum-1].Index)
                  break;
            }

            /* get offset based on previous index */
            Ofs = (f->HintNum) ? (Index - Hint[f->HintNum-1].Index) : (Index);
            Ofs2 = 0;

            /* set f->Seek_Hint */
            f->Seek_Hint = (RTFDirLocation *)Hint;

            /* process this hint, make index cluster-aligned (Ofs2) */
            while(Ofs >= ClusterSize)
            {
               if(Tmp2 < 2L)
               {
                  fs_util_trace_err_noinfo(RTF_FAT_ALLOC_ERROR);

                  XRAISE(RTF_FAT_ALLOC_ERROR);
               }

               if(Tmp2 >= RTF_CLUSTER_CHAIN_END)
                  break; //incorrect file size
               Ofs -= ClusterSize;
               Ofs2 += ClusterSize;
               Tmp1 = Tmp2;
               #ifdef __FS_INTERVAL_BUFFER__
                   Tmp2 = fs_srv_get_cluster_value(f->Drive, Tmp1, FS_GET_CLUSTER_DEFAULT, fs_srv_buf_get);
               #else
                   Tmp2 = fs_srv_get_cluster_value(f->Drive, Tmp1, FS_GET_CLUSTER_DEFAULT, GetBuffer);
               #endif
            }

            /* STOP: cluster chain is not matched to file size */
            if(Tmp2 >= RTF_CLUSTER_CHAIN_END)
               break;

            /* set index and corresponding cluster number to f->Seek_Hint, note that "index" is cluster-aligned, and is a absolute offset in bytes! */
            Hint[f->HintNum].Index = (f->HintNum) ?
                                     (Ofs2 + f->Seek_Hint[f->HintNum-1].Index) : Ofs2;
            Hint[f->HintNum].Cluster = Tmp2;

            /* go to process next hint */
            f->HintNum++;
         }

         Result = f->HintNum;
         break;
      default:
         if (f != NULL)
         {
            f->HintNum = 0;
            f->Seek_Hint = 0;
         }
         Result = XVALUE; //API dose not need XHANDLED
         break;
      case XFINALLY:

         if (f != NULL)
         {
         #ifdef __FS_SMART_FILE_SEEKER__
            if (f->HintNum > 0)
            {
               f->usr_ptr_type = FS_TBL_USR_PTR_MILESTONE;  // old version seek hint
            }
            else  // something wrong during FS_SetSeekHint, disable seek hint
            {
               f->usr_ptr_type = FS_TBL_USR_PTR_NONE;
            }

            f->usr_ptr = NULL;   // old version

         #endif

         #ifdef __FS_INTERVAL_BUFFER__
             fs_srv_buf_final();
         #endif

            UnlockDevice(f->Dev);
         }

         SafeUnlock(MT_LOCK_EXT);
         break;
   XEND_API

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_SETSEEKHINT_E, Result, NULL);

   fs_util_check_stack();

   return Result;
}

/* ------------------------------------------------------------------------------- */
int FS_Truncate(FS_HANDLE FileHandle)
{
   int Result = RTF_NO_ERROR;

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_TRUNCATE_S, FileHandle, NULL);

   Result = RTFTruncate(FileHandle);

   fs_util_trace_info0(TRACE_FUNC, FS_API_FS_TRUNCATE_E, NULL);

   fs_util_check_stack();

   return Result;
}

/* ------------------------------------------------------------------------------- */
int FS_Rename(const WCHAR * FileName, const WCHAR * NewName)
{
   int Result = FS_NO_ERROR;
   WCHAR * NewName2;

   fs_util_trace_info0(TRACE_FUNC | MT_TRACE_INFO_WSTR, FS_API_FS_RENAME_S_OLDNAME, (void*)FileName);
   fs_util_trace_info0(TRACE_FUNC | MT_TRACE_INFO_WSTR, FS_API_FS_RENAME_S_NEWNAME, (void*)NewName);

   NewName2 = TruncateWideWhiteSpacesAndPeriods(NewName);
   Result = RTFRename(FileName, NewName2);

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_RENAME_E, Result, NULL);

   fs_util_check_stack();

   return Result;
}

/*******************************************************************//**
 * Control or configure device, or read physical information of device by drive name
 *
 * @par Category:
 * File System
 *
 * @par Change Log:
 * W09.12: Initial version (Stanley Chu)
 **********************************************************************/
int FS_IOCtrl(const WCHAR* DriveName, kal_uint32 CtrlAction, void* CtrlData)
{
   int                 device_num;
   int volatile        result       = FS_NO_ERROR;
   RTFDevice          *dev          = NULL;
   #if (defined(__CMMB_CAS_SMD_SUPPORT__) && !defined(__FS_PROPRIETARY_SET__))
   int                 ctrl_data;
   #endif

   fs_util_trace_info2(TRACE_FUNC, FS_API_FS_IOCTRL_S, *(kal_uint8*)DriveName, CtrlAction, NULL);

   XTRY
      case XCODE:

         /*
          * Get device information
          */

         if (NULL != DriveName)
         {
            // get device number by drive name
            device_num = FindDeviceNumberByDriveIdx((int)(DriveName[0]));

            if (device_num)
            {
               dev = &gFS_DeviceList[device_num - 1];

               // check if driver supports IOCtrl
               if (dev->Driver->IOCtrl == NULL)
               {
                  fs_util_trace_err_noinfo(FS_UNSUPPORTED_DRIVER_FUNCTION);

                  XRAISE(FS_UNSUPPORTED_DRIVER_FUNCTION);
               }
            }
            // can't get proper device number
            else
            {
               fs_util_trace_err_noinfo(FS_PARAM_ERROR);

               XRAISE(FS_PARAM_ERROR);
            }
         }
         else
         {
            if ((FS_IOCTRL_QUERY_PHYSICAL_MAP == CtrlAction) ||
                (FS_IOCTRL_QUERY_PHYSICAL_MAP_DEV_TYPE_ONLY == CtrlAction))
            {
               // check parameters
               if (NULL == CtrlData)
               {
                  fs_util_trace_err_noinfo(FS_PARAM_ERROR);

                  XRAISE(FS_PARAM_ERROR);
               }
            }
            else
            {
               fs_util_trace_err_noinfo(FS_PARAM_ERROR);

               XRAISE(FS_PARAM_ERROR);
            }
         }

         // lock device
         SafeLock(MT_LOCK_DEV, dev, RTF_INFINITE);

         switch (CtrlAction)
         {
            case FS_IOCTRL_CONTROL_DEV_POWER:

               // CtrlData: KAL_TRUE / KAL_FALSE
               result = dev->Driver->IOCtrl(dev->DriverData, FS_IOCTRL_CONTROL_DEV_POWER, CtrlData);

               if (result < FS_NO_ERROR)
               {
                  XRAISE(result);
               }

               break;

#if (defined(__CMMB_CAS_SMD_SUPPORT__) && !defined(__FS_PROPRIETARY_SET__))  // ULC projects does not support memory card

            /*---------------------------------------
          	 * Configure CMMB CAS card command sector
             *---------------------------------------*/
            case FS_IOCTRL_SET_COMMAND_SECTOR:

               /*-------------------------------------------------------------------------
                * We will always configure sector #0 as the command sector because FS will
                * not touch sector 0 after reading MBR in mount stage.
                * This is true for all FAT types.
                *
                * So we only allows user to set command sector when device's mount state is HasFileSystem.
                *-------------------------------------------------------------------------*/
               if (dev->DevData.MountState < HasFileSystem)
               {
                  fs_util_trace_err_noinfo(FS_DRIVE_NOT_READY);

                  XRAISE(FS_DRIVE_NOT_READY);
               }

               // query device type
               result = dev->Driver->IOCtrl(dev->DriverData, FS_IOCTRL_QUERY_DEVICE_TYPE, &ctrl_data);

               if (result < 0)
               {
                  fs_util_trace_err_noinfo(result);

                  XRAISE(result);
               }

               // if device is CAS card, configure command sector
               if (ctrl_data == FS_IOCTRL_DEVICE_CAS_CARD)
               {
                  // we always configure sector #0 as the command sector
                  ctrl_data = 0;

                  // configure it!
                  result = dev->Driver->IOCtrl(dev->DriverData, FS_IOCTRL_SET_COMMAND_SECTOR, &ctrl_data);

                  // set command sector failed..
                  if (result < 0)
                  {
                     fs_util_trace_err_noinfo(result);

                     XRAISE(result);
                  }
               }
               // unproper device
               else
               {
                  fs_util_trace_err_noinfo(FS_UNSUPPORTED_DEVICE);

                  XRAISE(FS_UNSUPPORTED_DEVICE);
               }
            	break;
#endif  /* __CMMB_CAS_SMD_SUPPORT__ && !__FS_PROPRIETARY_SET__ */

#ifdef __AUDIO_DSP_LOWPOWER__
            /*------------------------------------------
          	 * Query physical map of a specific file
             *------------------------------------------*/
            case FS_IOCTRL_QUERY_PHYSICAL_MAP:
            case FS_IOCTRL_QUERY_PHYSICAL_MAP_DEV_TYPE_ONLY:

               ((FS_PMapInfo*)CtrlData)->ValidEntryCnt = 0;
               ((FS_PMapInfo*)CtrlData)->DevType       = FS_DEVICE_TYPE_UNKNOWN;

               result = MTQueryPhysicalMap((FS_PMapInfo*)CtrlData);

               if (FS_IOCTRL_QUERY_PHYSICAL_MAP_DEV_TYPE_ONLY == CtrlAction)
               {
                  if (FS_DEVICE_TYPE_UNKNOWN == ((FS_PMapInfo*)CtrlData)->DevType)
                  {
                     XRAISE(FS_INVALID_FILE_HANDLE);
                  }
                  else
                  {
                     result = FS_NO_ERROR;
                  }
               }
               else if (result < FS_NO_ERROR)
               {
                  XRAISE(result);
               }

               break;
#endif // __AUDIO_DSP_LOWPOWER__

            /*------------------------------------------
          	 * Query NOR/NAND/Card physical information
             *------------------------------------------*/
            case FS_IOCTRL_QUERY_CARD_INFO:
            case FS_IOCTRL_QUERY_NAND_INFO:
            case FS_IOCTRL_QUERY_NOR_INFO:

            	// check if NAND flash device
            	if (!(dev->DeviceFlags & FS_DEVICE_NAND_FLASH) &&
            	    !(dev->DeviceFlags & FS_DEVICE_NOR_FLASH) &&
            	    !(dev->DeviceFlags & FS_DEVICE_REMOVABLE))
            	{
                  fs_util_trace_err_noinfo(FS_UNSUPPORTED_DEVICE);

                  XRAISE(FS_UNSUPPORTED_DEVICE);
            	}

            	// initialize control data
            	kal_mem_set(CtrlData, 0, sizeof(FS_DeviceInfo));

            	// query driver
            	result = dev->Driver->IOCtrl(dev->DriverData, CtrlAction, CtrlData);

            	if (result < 0)
               {
                  fs_util_trace_err_noinfo(result);

                  XRAISE(result);
               }

            	break;

            default:

               // unsupported IO control options
               fs_util_trace_err_noinfo(FS_UNSUPPORTED_DRIVER_FUNCTION);

               XRAISE(FS_UNSUPPORTED_DRIVER_FUNCTION);

               break;
         }
         break;

      default:
         result = XVALUE;
         break;

      case XFINALLY:
         SafeUnlock(MT_LOCK_DEV);
         break;

   XEND_API

   fs_util_trace_info0(TRACE_FUNC, FS_API_FS_IOCTRL_E, NULL);

   fs_util_check_stack();

   return result;
}

int FS_CheckVolumeLabel(WCHAR *Label)
{
    #if !defined(__FS_SLIM_VOLUME_LABEL__)

    char temp_label[12];

    fs_util_trace_info0(TRACE_FUNC | MT_TRACE_INFO_WSTR, FS_API_FS_CHECKVOLUMELABEL_E, (void*)Label);

    XTRY
        case XCODE:
            /*
             * 1. Basic check
             */
            CheckValidVolumeLabel(Label);

            /*
             * 2. Check if new label can be transformed to SFN correctly by current encoding
             *    For failed case, GenerateVolumeLabel will raise exception.
             */
            GenerateVolumeLable((char *)Label, temp_label);
        default:
            break;
        case XFINALLY:
            break;
    XEND_API

    return FS_NO_ERROR;

    #else

    return FS_ERR_UNSUPPORTED_SERVICE;

    #endif
}

int FS_CheckFileName(WCHAR *Path)
{
    fs_util_trace_info0(TRACE_FUNC | MT_TRACE_INFO_WSTR, FS_API_FS_CHECKFILENAME_E, (void*)Path);

    XTRY
        case XCODE:
            CheckValidFileName2(Path, KAL_TRUE);
        default:
            break;
        case XFINALLY:
            break;
    XEND_API

    return FS_NO_ERROR;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides facility for user to trace file system behavior
PARAMETER
      Flag: FS_TRACE_API, MT_TRACE_ERROR, FS_TRACE_DISABLE
RETURN
      This function always return successful
 ------------------------------------------------------------------------------- */
#ifdef __FS_TRACE_SUPPORT__

int FS_SetTrace(kal_uint32 Flag, kal_uint32 Timeout)
{
   return RTF_NO_ERROR;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides facility for user to dump file handle table
RETURN
      This function always return successful
 ------------------------------------------------------------------------------- */
int FS_DumpFHTable(void)
{
   fs_util_trace_info0(TRACE_FUNC, FS_API_FS_DUMPFHTABLE_S, NULL);

   fs_util_trace_err_noinfo(RTF_ERROR_RESERVED);

   fs_util_check_stack();

   return RTF_NO_ERROR;
}
#else // !__FS_TRACE_SUPPORT__
int FS_SetTrace(kal_uint32 Flag, kal_uint32 Timeout)
{
   return FS_NO_ERROR;
}
#endif // __FS_TRACE_SUPPORT__

/* ------------------------------------------------------------------------------- */
int FS_FindFirst(const WCHAR * NamePattern, kal_uint8 Attr, kal_uint8 AttrMask, FS_DOSDirEntry * FileInfo, WCHAR * FileName, kal_uint32 MaxLength)
{
    kal_uint32    lr;
    int Result    = RTF_NO_ERROR;
    RTFFileOpenHint *OpenHint = NULL;

    FS_GET_RETURN_ADDRESS(lr);

    fs_util_trace_info4(TRACE_FUNC | MT_TRACE_INFO_WSTR, FS_API_FS_FINDFIRST_S, lr, Attr, AttrMask, MaxLength, (void*)NamePattern);

    if (FileInfo != NULL)
        OpenHint = (RTFFileOpenHint*)FS_GetOpenHintByDOSDirEntry(FileInfo);

    Result = RTFFindFirstEx(NamePattern, Attr, AttrMask, (RTFDOSDirEntry*)FileInfo, FileName, MaxLength, OpenHint, lr);

    if (FileInfo)
        fs_util_trace_info4(TRACE_FUNC | MT_TRACE_INFO_WSTR, FS_API_FS_FINDFIRST_E_INFO, Result, FileInfo->Attributes, FileInfo->NTReserved, NULL, (void*)FileName);
    else
        fs_util_trace_info1(TRACE_FUNC | MT_TRACE_INFO_WSTR, FS_API_FS_FINDFIRST_E, Result, (void*)FileName);

    fs_util_check_stack();

    return Result;

}

/* ------------------------------------------------------------------------------- */
int FS_FindNext(FS_HANDLE FileHandle, FS_DOSDirEntry * FileInfo, WCHAR * FileName, kal_uint32 MaxLength)
{
    int             Result    = FS_NO_ERROR;
    RTFFileOpenHint *OpenHint = NULL;

    fs_util_trace_info2(TRACE_FUNC, FS_API_FS_FINDNEXT_S, FileHandle, MaxLength, NULL);

    if (FileInfo != NULL)
        OpenHint = (RTFFileOpenHint*)FS_GetOpenHintByDOSDirEntry(FileInfo);

    Result = RTFFindNextEx(FileHandle, (RTFDOSDirEntry *)FileInfo, FileName, MaxLength, OpenHint);

    if (Result == FS_NO_ERROR)
    {
        if (FileInfo)
            fs_util_trace_info2(TRACE_FUNC | MT_TRACE_INFO_WSTR, FS_API_FS_FINDNEXT_E_INFO, FileInfo->Attributes, FileInfo->NTReserved, (void*)FileName);
        else
            fs_util_trace_info0(TRACE_FUNC | MT_TRACE_INFO_WSTR, FS_API_FS_FINDNEXT_E, (void*)FileName);
    }

    fs_util_check_stack();

    return Result;
}

/* ------------------------------------------------------------------------------- */
int FS_FindClose(FS_HANDLE FileHandle)
{
   int Result = RTF_NO_ERROR;

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_FINDCLOSE_S, FileHandle, NULL);

   Result = RTFFindClose(FileHandle);

   fs_util_check_stack();

   return Result;
}

FS_QuotaStruct *gFS_IntQuotaSet;
UINT            FS_MAX_QSET;

void FS_QuotaInit(FS_QuotaStruct *quota, kal_uint32 total)
{
    gFS_IntQuotaSet = quota;
    FS_MAX_QSET = total;
}

#endif /* #if !defined(__MODEM_CCCI_EXIST__) */
