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
 *	fs_func_adv.c
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
#include "fs_trc.h"  // "stack_config.h" is included by "kal_release.h"

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
#define fs_util_trace_err_noinfo(error_code) fs_util_trace_err_slim(error_code, fs_func_adv_c, __LINE__)

// Assert
#define fs_assert_local(expr) fs_assert(expr, fs_func_adv_c)
#define fs_ext_assert_local(expr, e1, e2, e3) fs_ext_assert(expr, fs_func_adv_c, e1, e2, e3)

extern kal_bool    INT_QueryExceptionStatus(void);
extern kal_uint32  INT_GetCurrentTime(void);
extern void        InitDebugPrint(void);
extern void        DebugPrint(kal_uint8, kal_uint8, kal_uint8*);
extern UINT        OpenHintStamp;
#if defined(__MTP_ENABLE__)
extern void        *SysLockFATTask;
#endif /* __MTP_ENABLE__ */

/*
 * locals
 */

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides a facility to find Nth matching file
      and multi-patterns are supported
PARAMETER
      NamePattern:   Find Pattern (Must have drive name)
      PatternArray:  Multi-patterns array (should not have drive name)
      PatternNum:    Indicate how many pattern in PatternArray
      ArrayMask:     The attributes that match default NamePattern only
      Attr:          The attributes must have
      AttrMask:      The attributes must not have
      FileInfo:      File information
      FileName:      File name
      MaxLength:     The length of the file name buffer
      EntryIndex:    Find Nth index
RETURN
      Success:  RTF_NO_ERROR
      Error:    RTF_PARAM_ERROR
                RTF_FILE_NOT_FOUND
------------------------------------------------------------------------------- */
int FS_FindFirstN(const WCHAR * NamePattern,
                  FS_Pattern_Struct * PatternArray,kal_uint32 PatternNum,
                  kal_uint8 ArrayMask,
                  kal_uint8 Attr, kal_uint8 AttrMask,
                  FS_DOSDirEntry * FileInfo, WCHAR * FileName, kal_uint32 MaxLength,
                  kal_uint32 EntryIndex, kal_uint32 Flag)
{
    kal_uint32 lr;
    int result;
    fs_list_param_struct *param;
    FS_FileLocationHint * file_pos = NULL;

    FS_GET_RETURN_ADDRESS(lr);

    param = (fs_list_param_struct *)get_ctrl_buffer(sizeof(fs_list_param_struct));

    #if defined(__MTP_ENABLE__)
    if (FileInfo)
    {
        file_pos = (FS_FileLocationHint*)FS_GetOpenHintByDOSDirEntry(FileInfo);
    }
    #endif  // __MTP_ENABLE__

    fs_util_trace_info5ex(TRACE_FUNC | MT_TRACE_INFO_WSTR, FS_API_FS_FINDFIRSTN_S, lr, PatternNum, MaxLength, EntryIndex, Flag, (void*)NamePattern);

    param->path = (kal_wchar *)NamePattern;
    param->name_pattern = PatternArray;
    param->name_pattern_count = PatternNum;
    param->attr_pattern = ArrayMask;
    param->attr = Attr;
    param->attr_mask = AttrMask;
    param->buff = NULL;
    param->buff_size = 0;
    param->index = EntryIndex;

    result = RTFFindFirst(param,
                          FileInfo, FileName, MaxLength,
                          Flag, file_pos, lr);


    free_ctrl_buffer(param);

    if (result >= FS_NO_ERROR)    {
        fs_util_trace_info1(TRACE_FUNC | MT_TRACE_INFO_WSTR, FS_API_FS_FINDFIRSTN_E, result, (void*)FileName);
    }
    else {
        fs_util_trace_info1(TRACE_FUNC, FS_API_FS_FINDFIRSTN_E, result, NULL);
    }

    return result;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides a facility to find next matching file
      and multi-patterns are supported
PARAMETER
      Handle:        The file handle record the find position
      PatternArray:  Multi-patterns array (should not have drive name)
      PatternNum:    Indicate how many pattern in PatternArray
      ArrayMask:     The attributes that match default NamePattern only
      FileInfo:      File information
      FileName:      File name
      MaxLength:     The length of the file name buffer
RETURN
      Success:       RTF_NO_ERROR
      Error:         MT_ABORTED_ERROR
                     RTF_INVALID_FILE_HANDLE
                     RTF_NO_MORE_FILES
------------------------------------------------------------------------------- */
int FS_FindNextN(FS_HANDLE Handle,
                 FS_Pattern_Struct * PatternArray, kal_uint32 PatternNum,
                 kal_uint8 ArrayMask,
                 FS_DOSDirEntry * FileInfo, WCHAR * FileName, kal_uint32 MaxLength,
                 kal_uint32 Flag)
{
    #if defined(__MTP_ENABLE__)
    FS_FileLocationHint * file_pos = NULL;

    if (FileInfo)
    {
        file_pos = (FS_FileLocationHint*)FS_GetOpenHintByDOSDirEntry(FileInfo);
    }
    #else   // !__MTP_ENABLE__
    #define file_pos (NULL)
    #endif  // __MTP_ENABLE__

    fs_util_trace_info4(TRACE_FUNC, FS_API_FS_FINDNEXTN_S, Handle, PatternNum, MaxLength, Flag, NULL);

    return fs_srv_findnext(Handle,
                           PatternArray, PatternNum,
                           ArrayMask,
                           FileInfo, FileName, MaxLength,
                           Flag, file_pos);
}


#define __FS_LIST_FUNC_SEG__

kal_int32 FS_ListOpenEx(fs_list_param_struct *param, FS_HANDLE *handle, kal_bool reload, kal_uint32 caller_address);

/*****************************************************************************
 * FUNCTION
 *  FS_ListReload
 * DESCRIPTION
 *  1. This API will rebuild the list
 *  2. The first element is specified by the given index
 *
 * PARAMETERS
 *  handle         [OUT]:   special handle of List serial APIs.
 *  index          [IN]:    specific  zero-based index in the list
 * RETURNS
 *  Success or not
 *****************************************************************************/
kal_int32 FS_ListReload(fs_list_param_struct *param, FS_HANDLE *handle)
{
    return FS_ListOpenEx(param, handle, KAL_TRUE, 0);
}

/*****************************************************************************
 * FUNCTION
 *  FS_ListOpen
 *
 * DESCRIPTION
 *  1. To open specific folder and loading file elements with given parameters
 *     into a backgroud list.
 *  2. Similar to opendir of Posix.
 * PARAMETERS
 *  param    [IN/OUT]:   parameter set and list buffer; please refer to fs_list_struct.
 *  list     [OUT]:      special handle of List serial APIs.
 * RETURNS
 *  Successful: A non-negative value which is a special handle of List serial APIs.
 *  Failed: An negative error code is returned.
 *****************************************************************************/
kal_int32 FS_ListOpen(fs_list_param_struct *param, FS_HANDLE *handle)
{
    kal_uint32 lr;
    FS_GET_RETURN_ADDRESS(lr);
    return FS_ListOpenEx(param, handle, KAL_FALSE, lr);
}

kal_int32 FS_ListOpenEx(fs_list_param_struct *param, FS_HANDLE *handle, kal_bool reload, kal_uint32 caller_address)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;
//    FS_DOSDirEntry dir_entry;
    FS_FileLocationHint pos;
    WCHAR temp_sfn[FS_MAX_SFN_NATIVE_FILE_NAME_LENGTH_B + 1];
    fs_list_cntx_struct *context = param->buff;
    kal_uint32 n = FS_LIST_ENTRY(param->buff_size);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    if ((handle == NULL) ||
        (context == NULL) ||
        (param->buff_size < FS_LIST_SIZE(n)))
    {
        fs_util_trace_err_noinfo(FS_FAIL_GET_MEM);

        return FS_FAIL_GET_MEM;
    }

    fs_util_trace_info2(TRACE_FUNC | MT_TRACE_INFO_WSTR, FS_TRC_FS_LISTOPEN_S, caller_address, (kal_uint32)param, (void*)param->path);

    context->total = n;
    context->attr = param->attr;
    context->attr_mask = param->attr_mask;
    context->callback = param->callback;
    context->param = param->param;
    context->index = param->index;
    context->used = 0;

    if (reload)   {
        // Using Previous handler
        param->index += n;
        if (context->handle==0) {
            return FS_INVALID_FILE_HANDLE;
        }

        result = fs_srv_findnext(context->handle,
                     param->name_pattern, param->name_pattern_count,
                     param->attr_pattern,
                     NULL, temp_sfn, FS_MAX_SFN_NATIVE_FILE_NAME_LENGTH_B + 1,
                     FS_FIND_LFN_TRUNC, &pos);

    }
    else {
        // The new handler is given, start a new search
        context->handle = result = RTFFindFirst(param,
                                                NULL, temp_sfn, FS_MAX_SFN_NATIVE_FILE_NAME_LENGTH_B + 1,
                                                FS_FIND_LFN_TRUNC, &pos, caller_address);
    }

    if (context->callback &&
        context->callback(context->handle, FS_PGS_START, context->total, context->used, context->param) < 0)
    {
        return FS_ABORTED_ERROR;
    }


    while(result >= FS_NO_ERROR && context->used < context->total)
    {

        context->pos_buf[context->used].Cluster= pos.Cluster;
        context->pos_buf[context->used].Index= pos.Index;

        fs_util_trace_info4(TRACE_INFO, FS_TRC_FS_LISTOPEN_FILL,
                                        context->used, pos.Cluster, pos.Index, 0, NULL);

        context->used++;
        if (context->used >= context->total) break;

        if (context->used && (context->used&0x1FF) == 0)       // check once every 512 file
            kal_sleep_task(20);        // wait for 100 ms.

        /*
         * NOTE: Use FS_FIND_LFN_TRUNC to let RTFFindNext fill-in the position of LFN entry to
         *       dir_entry.Cluster and dir_entry_Index.
         */

        result = fs_srv_findnext(context->handle,
                             param->name_pattern, param->name_pattern_count,
                             param->attr_pattern,
                             NULL, temp_sfn, FS_MAX_SFN_NATIVE_FILE_NAME_LENGTH_B + 1,
                             FS_FIND_LFN_TRUNC, &pos);

        if (context->callback &&
            context->callback(context->handle, FS_PGS_ING, context->total, context->used, context->param) < 0)
        {
            result = FS_ABORTED_ERROR;
            break;
        }

    }


    if (result >= FS_NO_ERROR || result == FS_NO_MORE_FILES)// TODO: check with Smallp is it ok if empty folder with FS_NO_ERROR
    {
        *handle = context->handle;

        if (context->callback)
            context->callback(context->handle, FS_PGS_DONE, context->used, context->used, context->param);

        if (result == FS_NO_MORE_FILES)
        {
            result = FS_NO_ERROR;
        }

    }
    else
    {
        *handle = 0;
        if (context->callback)
            context->callback(context->handle, FS_PGS_FAIL, context->used, context->used, context->param);
    }

    fs_util_trace_info2(TRACE_FUNC, FS_TRC_FS_LISTOPEN_E, result, *handle, NULL);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  FS_ListNext
 * DESCRIPTION
 *  1. To retrive Nth element of the background list.
 *  2. Similar to readdir of Posix
 *  3. optional parameters could be NULL or 0
 * PARAMETERS
 *  handle         [OUT]:     special handle of List serial APIs.
 *  info           [IN/OUT]:  (optional)the DOS style information of an element if found. Such as short file name.
 *  path           [IN]:      working diretory which will be filled into internal hint
 *  lfilename      [IN/OUT]:  the buffer to carry long file name if found.
 *  lfilename_size [IN]:      the buffer size of lfilename with includes null terminator
 *  index          [IN]:      (optional)specific zero-based index in the list
 * RETURNS
 *  Success or not
 *****************************************************************************/
kal_int32 FS_ListNext(FS_HANDLE handle,
                      FS_DOSDirEntry *info, kal_wchar *path, kal_wchar *lfilename, kal_uint32 lfilename_size,
                      kal_int32 index)
{
    kal_int32 result;

    fs_util_trace_info2(TRACE_FUNC, FS_TRC_FS_LISTNEXT_S, handle, index, NULL);

    result = RTFGetListEntry(handle, path, lfilename, lfilename_size, info, index);

    fs_util_trace_info1(TRACE_FUNC | MT_TRACE_INFO_WSTR, FS_TRC_FS_LISTNEXT_E, result, (void *)lfilename);

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  FS_ListClose
 * DESCRIPTION
 *  1. To close the list.
 *  2. Similar to closedir of Posix.
 * PARAMETERS
 *  handle     [IN]:      special handle of List serial APIs.
 * RETURNS
 *  Success or not
 *****************************************************************************/
kal_int32 FS_ListClose(FS_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    fs_util_trace_info1(TRACE_FUNC, FS_TRC_FS_LISTCLOSE_S, handle, NULL);

    return RTFClose(handle);
}

#undef __FS_LIST_FUNC_SEG__

/*******************************************************************//**
 * This function provides a facility to abort FS_XDelete, FS_Move, or the
 * action on the specified file handle.
 *
 * @par Category:
 * File System
 *
 * @par Change Log:
 * W09.11: Add file handle checking to avoid data abort or aborting the 1st file mistakenly when ActionHandle == 0 (Stanley Chu)
 **********************************************************************/
int FS_Abort(kal_uint32 ActionHandle)
{
   RTFile * f;
   kal_uint32     i, u;

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_ABORT_S, ActionHandle, NULL);

   //do not lock here
   if (ActionHandle == FS_ABORT_CHECK_DRIVE)
   {
      #ifdef __FS_CHECKDRIVE_SUPPORT__
      g_CheckDrive = KAL_FALSE;
      #else
      return RTF_PARAM_ERROR;
      #endif
   }
   else if (ActionHandle == FS_ABORT_XDELETE)
   {
      g_Xdelete = KAL_FALSE;
   }
   else // abort a specified file handle
   {
      u = ActionHandle >> (4 * sizeof(int));  // get unique number in file handle
      i = ActionHandle & ((1 << (4 * sizeof(int))) - 1); // get file table index

      // check file table index, if valid, get file structure
      if (i >= FS_MAX_FILES)
      {
         return RTF_INVALID_FILE_HANDLE;
      }
      else
      {
         f = gFS_Data.FileTable + i;
      }

      // check unique, this checking should filter out case "ActionHandle = 0"
      if (f->Unique != u || f->Lock == 0)
      {
         return RTF_INVALID_FILE_HANDLE;
      }

      f->Valid = FS_FH_ABORTED; // invalidate file handle
   }

   fs_util_trace_info0(TRACE_FUNC, FS_API_FS_ABORT_E, NULL);

   fs_util_check_stack();

   return RTF_NO_ERROR;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides a facility to count the number of files
      or folders recursively
PARAMETER
      FullPath:          Source path to be counted
      Flag:              FS_FILE_TYPE, FS_DIR_TYPE, FS_RECURSIVE_TYPE
      RecursiveStack:    A memory pointer to store deep folder hierarchy recrusive data
      StackSize:         The size of RecursiveStack
RETURN
      Success: >= RTF_NO_ERROR , Depends on number of objects processed by recursive engine
      Error:   RTF_PARAM_ERROR
               RTF_INVALID_FILENAME
               RTF_PATH_NOT_FOUND
               MT_FAIL_GET_MEM
NOTE
      1. This API belong to Recursive Class
------------------------------------------------------------------------------- */
int FS_Count(const WCHAR * FullPath, kal_uint32 Flag, kal_uint8 *RecursiveStack, const kal_uint32 StackSize)
{
   int volatile Result = RTF_NO_ERROR;

   fs_util_trace_info4(TRACE_FUNC | MT_TRACE_INFO_WSTR, FS_API_FS_COUNT_S, Flag, (kal_uint32)RecursiveStack, StackSize, NULL, (void*)FullPath);

   fs_init();

   if(MTXLock == NULL)
      MTXLock = RTFSYSAllocMutex("MTXLock");

   /* Count - 1 : Parameter Check */
   if(((Flag & FS_FILE_TYPE) == 0) && ((Flag & FS_DIR_TYPE) == 0) && ((Flag & FS_RECURSIVE_TYPE) == 0))
   {
      fs_util_trace_err_noinfo(RTF_PARAM_ERROR);

      return RTF_PARAM_ERROR;
   }

   if(Flag & ~(FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE | FS_FILTER_SYSTEM_ATTR | FS_FILTER_HIDDEN_ATTR))
   {
      fs_util_trace_err_noinfo(RTF_PARAM_ERROR);

      return RTF_PARAM_ERROR;
   }

   if ( MT_MAXPATH_IN_WCHAR_UNIT <= kal_wstrlen(FullPath) )
   {
      Result = MT_PATH_OVER_LEN_ERROR;
   }
   else
   {
      Result = RecAUX_IsFolder(FullPath);
   }

   if (Result < RTF_NO_ERROR)
   {
      fs_util_trace_err_noinfo(Result);

      return Result;
   }

   /* Count - 2 : Action */

   SafeLock(MT_LOCK_EXT, NULL, RTF_INFINITE);
   MTXLock->DeviceNum_1 = FindDeviceNumberByDriveIdx((int)FullPath[0]);
   Result = RecAUX_CountNumOfObjUnderFolderTree(FullPath, Flag, NULL, RecursiveStack, StackSize);
   MTXLock->DeviceNum_1 = 0;
   SafeUnlock(MT_LOCK_EXT);

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_COUNT_E, Result, NULL);

   fs_util_check_stack();

   return Result;
}

int FS_GetCurrentDirByDrive(WCHAR *DirName, kal_uint32 MaxLength)
{
   int Result = RTF_NO_ERROR;

   fs_util_trace_info2(TRACE_FUNC, FS_API_FS_GETCURRENTDIRBYDRIVE_S, DirName[0], MaxLength, NULL);

   Result = RTFGetCurrentDirByDrive(DirName, MaxLength);

   fs_util_trace_info1(TRACE_FUNC | MT_TRACE_INFO_WSTR, FS_API_FS_GETCURRENTDIRBYDRIVE_E, Result, (void*)DirName);

   fs_util_check_stack();

   return Result;
}

/* ------------------------------------------------------------------------------- */
int FS_GetCurrentDir(WCHAR * DirName, kal_uint32 MaxLength)
{
   int Result = RTF_NO_ERROR;

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_GETCURRENTDIR_S, MaxLength, NULL);

   Result = RTFGetCurrentDir(DirName, MaxLength);

   fs_util_trace_info1(TRACE_FUNC | MT_TRACE_INFO_WSTR, FS_API_FS_GETCURRENTDIR_E, Result, (void*)DirName);

   fs_util_check_stack();

   return Result;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides general format facility for File Manager
PARAMETER
      DriveName:  The drive that should be formatted (format: "\\\\.X:\\")
      Level:      High or Low
      Progress:   The callback function
RETURN
      Success: RTF_NO_ERROR
      Error:   RTF_PARAM_ERROR
               RTF_UNSUPPORTED_DRIVER_FUNCTION
               RTF_MEDIA_CHANGED
NOTE
      1. When formating, other tasks should not be blocked at FS
      2. Only File Manager can call this function.
      3. Double lock in this function!
------------------------------------------------------------------------------- */
int FS_GeneralFormat(const WCHAR * DriveName, kal_uint32 Level, FS_FormatCallback Progress)
{
   kal_uint32          lr;
   RTFDrive *volatile  Drive = NULL;
   RTFDevice *volatile Dev;
   int volatile        Result = FS_NO_ERROR;
   kal_uint8           LocateSysDrv = KAL_FALSE;
   WCHAR               InputDrive;

   FS_GET_RETURN_ADDRESS(lr);

   fs_util_trace_info4(TRACE_FUNC, FS_API_FS_GENERALFORMAT_S, lr, (char)(DriveName[4]), Level, NULL, NULL);

   fs_init();

   if(MTFMLock == NULL)
      MTFMLock = RTFSYSAllocMutex("MTFMLock");

   XTRY
   case XCODE:

      #if !defined(__FS_SLIM_LOW_LEVEL_FORMAT__)
      if (Level != FS_FORMAT_HIGH && Level != FS_FORMAT_LOW)
      #else
      if (Level != FS_FORMAT_HIGH)  // only high-level format is allowed
      #endif
      {
         fs_util_trace_err_noinfo(RTF_PARAM_ERROR);

         XRAISE(RTF_PARAM_ERROR);
      }

      // check format
      if (kal_wstrncmp(DriveName, (WCHAR*)L"\\\\.\\", 4) != 0)
      {
         fs_util_trace_err_noinfo(RTF_PARAM_ERROR);

         XRAISE(RTF_PARAM_ERROR);
      }

      // get drive letter
      LocateSysDrv = fs_conf_query_if_sys_drv(DriveName[4], &InputDrive);

      if (0 == InputDrive)
      {
         fs_util_trace_err_noinfo(RTF_PARAM_ERROR);

         XRAISE(RTF_PARAM_ERROR);
      }

      Drive = &gFS_Data.DriveTable[InputDrive - MT_BASE_DRIVE_LETTER];

      if (Drive == NULL)
      {
         fs_util_trace_err_noinfo(RTF_PARAM_ERROR);

         XRAISE(RTF_PARAM_ERROR);
      }

      Dev = Drive->Dev;

      if (CardBusyCheck && (Dev->DeviceFlags & RTF_DEVICE_REMOVABLE))
      {
         if (FS_GetDevStatus(FS_DEVICE_TYPE_CARD, FS_FEATURE_STATE_ENUM) == FS_DEVICE_BUSY)
         {
            Result = FS_DEVICE_BUSY;

            fs_util_trace_err_noinfo(Result);

            XRAISE(Result);
         }
      }

      /*
       * Check if target drive is exporting.
       *
       * File table should NOT be cleared for this case, otherwise USB will assert
       * when it close "drive file"                         (W10.04 / Stanley Chu)
       */
      if (((Drive->Dev->DeviceFlags & MT_DEVICE_EXPORTING) == MT_DEVICE_EXPORTING) ||
      	  ((Drive->Dev->DeviceFlags & MT_DEVICE_NO_EXPORT) == 0 && (gFS_Export == FS_EXPORTED) && LocateSysDrv == 0))
      {
         fs_util_trace_err_noinfo(FS_DEVICE_EXPORTED_ERROR);

         XRAISE(FS_DEVICE_EXPORTED_ERROR);
      }

      SafeLock(MT_LOCK_FMT, NULL, RTF_INFINITE);
      MTFMLock->DeviceNum_1 = Dev->DeviceNumber;

      if(Dev->DeviceFlags & MT_DEVICE_WRITE_PROTECT)
      {
         fs_util_trace_err_noinfo(RTF_WRITE_PROTECTION);

         XRAISE(RTF_WRITE_PROTECTION);
      }

      SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Dev, RTF_INFINITE);

      FlushAllBuffers(Dev);
      DiscardAllBuffers(Dev);

      /*
       * Clear file table.
       *
       * 1. All file handles on target drive should be invalidated after format.
       * 2. If we do not clear them first, RTFFormat() will be failed because
       *    "drive file" is not allowed to be opened if there are files in open stats.
       *
       * NOTE: File table should be cleared after device lock is locked!
       */
      MTClearFileTableByDrive(Drive);

      if(Level == FS_FORMAT_HIGH)
      {
         if ((Dev->Driver->HighLevelFormat) &&
            ((Dev->DeviceFlags & FS_DEVICE_MEMORY_STICK) != FS_DEVICE_MEMORY_STICK)) //only for MSDC now
         {
            SafeUnlock(MT_LOCK_RTF); //unlock RTF only
            Result = Dev->Driver->HighLevelFormat(Dev->DriverData, Drive->FirstSector);
            SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Dev, RTF_INFINITE);

            if(Result < RTF_NO_ERROR)
            {
               fs_util_trace_err_noinfo(Result);

               XRAISE(Result);
            }

            Dev->DevData.MountState = NotMounted; // mspro
         }
         else
         {
            SafeUnlock(MT_LOCK_RTF); //unlock RTF only
            Result = RTFFormat(DriveName, 0, (RTFFormatCallback) Progress, RTF_FMT_SINGLE_FAT | RTF_FMT_NO_LOW_LEVEL, lr);

            if(Result < RTF_NO_ERROR)
            {
               fs_util_trace_err_noinfo(Result);

               XRAISE(Result);
            }

            SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Dev, RTF_INFINITE);
         }
      }
      #if !defined(__FS_SLIM_LOW_LEVEL_FORMAT__)
      else if(Level == FS_FORMAT_LOW)
      {
         if((Dev->DeviceFlags & RTF_DEVICE_REMOVABLE) ||
            (!Dev->Driver->LowLevelFormat))
         {
            fs_util_trace_err_noinfo(RTF_UNSUPPORTED_DRIVER_FUNCTION);

            XRAISE(RTF_UNSUPPORTED_DRIVER_FUNCTION);
         }

         SafeUnlock(MT_LOCK_RTF); //unlock RTF only
         Result = RTFFormat(DriveName, 0, (RTFFormatCallback) Progress, RTF_FMT_SINGLE_FAT | RTF_FMT_FORCE_LOW_LEVEL, lr);

         if(Result < RTF_NO_ERROR)
         {
            fs_util_trace_err_noinfo(Result);

            XRAISE(Result);
         }

         SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Dev, RTF_INFINITE);
      }
      #endif // !__FS_SLIM_LOW_LEVEL_FORMAT__

      if (Dev->DeviceFlags & RTF_DEVICE_REMOVABLE)
      {
         MountRemovableDevice(Dev);
      }
      #if defined(__EMMC_BOOTING__)
      else if (Dev->DeviceFlags & FS_DEVICE_EMMC)
      {
         MountLogicalDrive(Drive, HasFileSystem);
      }
      #endif

      break;
   default:
      Result = XVALUE; //API dose not need XHANDLED
      if(Progress) Progress((char *)DriveName, FS_FMT_PGS_FAIL, 0, 0);
      break;
   case XFINALLY:

      #ifdef __FS_OPEN_HINT__
      MTHintExpireByDrive(Drive);
      #endif

      MTFMLock->DeviceNum_1 = 0;
      SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV | MT_LOCK_FMT);
      break;
   XEND_API

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_GENERALFORMAT_E, Result, NULL);

   fs_util_check_stack();

   return Result;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides a facility to move/copy a file or folder
PARAMETER
      SrcFullPath    : Source path to be moved/copied
      DstFullPath    : Destination path
      Flag           : FS_MOVE_COPY, FS_MOVE_KILL, FS_MOVE_OVERWRITE
      RecursiveStack : A memory pointer to store deep folder hierarchy recrusive data
      StackSize      : The size of RecursiveStack
RETURN
      Success: >= RTF_NO_ERROR , Depends on number of objects processed by recursive engine
      Error:   RTF_PARAM_ERROR
               RTF_INVALID_FILENAME
               RTF_PATH_NOT_FOUND
               RTF_FILE_EXISTS
               MT_FAIL_GET_MEM
               RTF_GENERAL_FAILURE
NOTE
      1. Original RTFRename does not allow move to different drive
      2. Only can file to file or dir to dir
      3. This API leverage the Recursive Class
------------------------------------------------------------------------------- */
int FS_MoveLR(const WCHAR * SrcFullPath, const WCHAR * DstFullPath, kal_uint32 Flag, FS_ProgressCallback Progress,
            kal_uint8 *RecursiveStack, const kal_uint32 StackSize, kal_uint32 caller_address)
{
   int  Result = RTF_NO_ERROR;
   int  Status = 0;
   int  Total  = 0;
   WCHAR * NewDstFullPath = NULL;
   WCHAR * DstFullPath2;
   WCHAR * DstFullPath_RelPath = NULL;
   #if defined(__FS_DEDICATED_BUFFER__)
   static kal_uint8     dedicated_buffer_used = KAL_FALSE;
   static kal_taskid    dedicated_buffer_task = NULL;
   #endif

   fs_util_trace_info1(TRACE_FUNC | MT_TRACE_INFO_WSTR, FS_API_FS_MOVE_S_SRCFILE, caller_address, (void*)SrcFullPath);
   fs_util_trace_info0(TRACE_FUNC | MT_TRACE_INFO_WSTR, FS_API_FS_MOVE_S_DSTFILE, (void*)DstFullPath);

   /* XMove,XCopy - 1 : Mutex Init & Take Move Lock */
   if (Progress) Progress(FS_MOVE_PGS_PREPARE, 0, 0, 0);

   fs_init();

   if (MTMoveLock == NULL)
      MTMoveLock = RTFSYSAllocMutex("MTMoveLock");

   DstFullPath2 = TruncateWideWhiteSpacesAndPeriods(DstFullPath);

   if (!RecursiveStack)
   {
       #if defined(__FS_DEDICATED_BUFFER__)

       if (_rtfLock((BYTE *)&dedicated_buffer_used) == 1) // request Move Lock only when dedicated buffer is used.
       {
           SafeLock(MT_LOCK_MOVE, NULL, RTF_INFINITE);
           MTMoveLock->DeviceNum_1 = FindDeviceNumberByDriveIdx((int)SrcFullPath[0]);
           MTMoveLock->DeviceNum_2 = FindDeviceNumberByDriveIdx((int)DstFullPath2[0]);
       }
       else // dedicated buffer will be used (dedicated_buffer_used is set from 0 to 1 in _rtfLock)
       {
           dedicated_buffer_task = kal_get_current_thread_ID();
       }
       #else   // !__FS_DEDICATED_BUFFER__

       SafeLock(MT_LOCK_MOVE, NULL, RTF_INFINITE);
       MTMoveLock->DeviceNum_1 = FindDeviceNumberByDriveIdx((int)SrcFullPath[0]);
       MTMoveLock->DeviceNum_2 = FindDeviceNumberByDriveIdx((int)DstFullPath2[0]);

       #endif
   }

   /* XMove,XCopy - 2 : Parameter Check */
   if ((kal_wstrcmp(SrcFullPath, DstFullPath2) == 0)   || /* same path action */
       ((Flag &  (FS_MOVE_KILL | FS_MOVE_COPY)) == 0) || /* No action flag   */
       ((Flag & ~(FS_MOVE_KILL | FS_MOVE_COPY | FS_MOVE_OVERWRITE)) != 0) /* other flag not allowed */
      )
   {
      fs_util_trace_err_noinfo(RTF_PARAM_ERROR);

      Result = RTF_PARAM_ERROR;
      goto MoveReturn;
   }

   /* XMove,XCopy - 3 : Test SrcFullPath & DstFullPath */
   Status = RecAUX_TestSrcAndDestPath(SrcFullPath, DstFullPath2, Flag);
   if (Status < RTF_NO_ERROR) { Result = Status; goto MoveReturn; }

    // if destinatin is a folder with relative path, let it be full path for path length checking
    if (Status & MT_XMOVE_DEST_IS_FOLDER)
    {
        // check rule: if does not start with "X:\\", it is a relative path
        if (DstFullPath[1] != L':' && DstFullPath[2] != L'\\')
        {
            // 1. Get buffer
            DstFullPath_RelPath = get_ctrl_buffer(MT_MAX_WIDE_PATH);

            // 2. Copy current path to buffer
            Result = RTFGetCurrentDir(DstFullPath_RelPath, MT_MAX_WIDE_PATH);

            if (Result < RTF_NO_ERROR)
            {
                goto MoveReturn;
            }


            // 3. Find the last back slash
            Result = kal_dchar_strlen((char *)DstFullPath_RelPath);

            for (Result--; Result > 0; Result--)
            {
                if (DstFullPath_RelPath[Result] == L'\\')
                {
                    break;
                }
            }

            if (Result == 0)
            {
                Result = FS_PATH_NOT_FOUND;
                goto MoveReturn;
            }

            // 4. Append destination folder name to current path (check path length first)
            if ((Result + kal_dchar_strlen((char *)DstFullPath)) >= FS_MAX_PATH)
            {
                Result = FS_PATH_OVER_LEN_ERROR;
                goto MoveReturn;
            }

            kal_dchar_strcpy((char *)(DstFullPath_RelPath + Result + 1), (char *)DstFullPath);

            DstFullPath2 = DstFullPath_RelPath;
        }
    }

   // copy a file to a folder
   if (!(Status & MT_XMOVE_SRC_IS_FOLDER) && (Status & MT_XMOVE_DEST_IS_FOLDER))
   {
  	  NewDstFullPath = get_ctrl_buffer(MT_MAX_WIDE_PATH);

  	  kal_dchar_strcpy((char*)NewDstFullPath, (char*)DstFullPath2);
  	  Result = CreateCopyDestPath(SrcFullPath, NewDstFullPath);

  	  if(Result<RTF_NO_ERROR)
  	  {
  	  		goto MoveReturn;
  	  }

  	  DstFullPath2 = NewDstFullPath;
      Status = RecAUX_TestSrcAndDestPath(SrcFullPath, DstFullPath2, Flag);

      if (Status < RTF_NO_ERROR) { Result = Status; goto MoveReturn; }
   }

   if ( MT_MAXPATH_IN_WCHAR_UNIT <= kal_wstrlen(SrcFullPath)
     || MT_MAXPATH_IN_WCHAR_UNIT <= kal_wstrlen(DstFullPath2) )
   {
      Result = MT_PATH_OVER_LEN_ERROR;
      goto MoveReturn;
   }

   /* XMove,XCopy - 4 : Operation Logical Check before Dispatch */
   if (Flag & FS_MOVE_KILL)
   {
      if (Status & MT_XMOVE_SRC_DEVICE_RO) { Result = RTF_WRITE_PROTECTION; goto MoveReturn; }
      if (Status & MT_XMOVE_SRC_IS_VIRTUAL) { Result = MT_READ_ONLY_ERROR; goto MoveReturn; }
   }
   if (Status & MT_XMOVE_DEST_EXIST)
   {
      if (Flag & FS_MOVE_OVERWRITE)
      {
         if (Status & MT_XMOVE_DEST_ATTR_RO) { Result = MT_READ_ONLY_ERROR; goto MoveReturn; }
         if (Status & MT_XMOVE_DEST_IS_FOLDER)
            Result = RecAUX_XDeleteFolder(DstFullPath2, FS_DIR_TYPE | FS_FILE_TYPE | FS_RECURSIVE_TYPE, Progress, RecursiveStack, StackSize); // abort for folder copy
         else
            Result = RTFDelete(DstFullPath2);
      }
      else
      {
         Result = RTF_FILE_EXISTS;
      }
      if (Result < RTF_NO_ERROR)
         goto MoveReturn;
   }

   /* XMove,XCopy - 5 : Operation Dispatch */
   if (Progress) Progress(FS_MOVE_PGS_START, 0, 0, 0);

   if ((Flag & FS_MOVE_KILL) && (Status & MT_XMOVE_SAME_DRIVE)) /* 5-1, move in same drive */
   {
      if (Progress) Progress(FS_MOVE_PGS_ING, 2, 1, 0);

      /* NOTE: Read-only file can be moved. (Since W09.24) */
      Result = RTFRename(SrcFullPath, DstFullPath2);

      goto MoveReturn;
   }

   if ((Status & MT_XMOVE_SRC_IS_FOLDER) == 0) /* 5-2, move/copy 1 file */
   {
      Result = CopyFileLightWeight(SrcFullPath, DstFullPath2, Progress, RecursiveStack, StackSize, caller_address);

      if (Result >= RTF_NO_ERROR && (Flag & FS_MOVE_KILL))
      {
         Result = RTFDelete(SrcFullPath);
         if(Result == RTF_ACCESS_DENIED)
         {
             RTFDelete(DstFullPath2);
         }
      }
   }
   else /* 5-3, move/copy 1 folder */
   {
      Result = RTFCreateDir(DstFullPath2, 0);

      if (Result < RTF_NO_ERROR)
      {
         goto MoveReturn;
      }

      Total = RecAUX_CountNumOfObjUnderFolderTree(SrcFullPath, FS_DIR_TYPE | FS_FILE_TYPE | FS_RECURSIVE_TYPE, Progress, RecursiveStack, StackSize);

      if (Total < RTF_NO_ERROR)
      {
         Result = Total;
         goto MoveReturn;
      }

      Result = RecAUX_XCopyFolder(SrcFullPath, DstFullPath2, Status, Progress, (kal_uint32) Total, RecursiveStack, StackSize, caller_address);

      if (Result >= RTF_NO_ERROR && (Flag & FS_MOVE_KILL))
      {
         Result = RecAUX_XDeleteFolder(SrcFullPath, FS_DIR_TYPE | FS_FILE_TYPE | FS_RECURSIVE_TYPE, Progress, RecursiveStack, StackSize);
      }
   }

   /* XMove,XCopy - 6 : Operation Finished */
MoveReturn:

   if (Progress) Progress(FS_MOVE_PGS_DONE, 0, 0, 0);

   if (NewDstFullPath) free_ctrl_buffer((kal_uint8*)NewDstFullPath);

   if (DstFullPath_RelPath) free_ctrl_buffer(DstFullPath_RelPath);

   if(!RecursiveStack)
   {
       #if defined(__FS_DEDICATED_BUFFER__)

       if ((dedicated_buffer_used == KAL_TRUE) && (dedicated_buffer_task == kal_get_current_thread_ID()))
       {
          dedicated_buffer_used = KAL_FALSE;
          dedicated_buffer_task = NULL;
       }
       else
       {
          MTMoveLock->DeviceNum_1 = 0;
          MTMoveLock->DeviceNum_2 = 0;
          SafeUnlock(MT_LOCK_MOVE);
       }

       #else    // !__FS_DEDICATED_BUFFER__

       MTMoveLock->DeviceNum_1 = 0;
       MTMoveLock->DeviceNum_2 = 0;
       SafeUnlock(MT_LOCK_MOVE);

       #endif   // __FS_DEDICATED_BUFFER__
   }

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_MOVE_E, Result, NULL);

   fs_util_check_stack();

   return Result;
}

/*------------------------------------------------------------------------------*/
int FS_Move(const WCHAR * SrcFullPath, const WCHAR * DstFullPath, kal_uint32 Flag, FS_ProgressCallback Progress,
                kal_uint8 *RecursiveStack, const kal_uint32 StackSize)
{
    kal_uint32 lr;
    FS_GET_RETURN_ADDRESS(lr);
    return FS_MoveLR(SrcFullPath, DstFullPath, Flag, Progress, RecursiveStack, StackSize, lr);
}


/* ------------------------------------------------------------------------------- */
int FS_SetCurrentDir(const WCHAR * DirName)
{
   int Result = RTF_NO_ERROR;

   fs_util_trace_info0(TRACE_FUNC | MT_TRACE_INFO_WSTR, FS_API_FS_SETCURRENTDIR_S, (void*)DirName);

   Result = RTFSetCurrentDir(DirName);

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_SETCURRENTDIR_E, Result, NULL);

   fs_util_check_stack();

   return Result;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides task to lock whole file system in USB mode or set to
      nonblock/block access on driver in NORMAL mode
Parameter
      Type: FS_LOCK_TYPE_ENUM
RETURN
      Success: RTF_NO_ERROR
      Error:   RTF_PARAM_ERROR
               RTF_TIMEOUT
------------------------------------------------------------------------------- */
int FS_LockFAT(kal_uint32 Type)
{
   //int volatile  type = Type;
   RTFDevice    *Dev;
   RTFDrive     *Drive = NULL;
   RTFile       *f;
   int           i;
   int volatile  result = FS_NO_ERROR;

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_LOCKFAT_S, Type, NULL);

   if(MTFMLock == NULL)
      MTFMLock = RTFSYSAllocMutex("MTFMLock");

   switch(Type)
   {
      case FS_LOCK_USB_ENUM:
         /* USB Boot Mode Entering */
         SysLockFAT = 1;
         break;

      case FS_UNLOCK_USB_ENUM:
         /* USB Boot Mode Exiting */
         SysLockFAT = 0;
         break;

      case FS_LOCK_BLOCK_ENUM:
         SysBlockFAT = 1;
         break;

      case FS_LOCK_NONBLOCK_ENUM:
         SysBlockFAT = 0;
         break;

#if defined(__MTP_ENABLE__)
      case FS_TASK_EXPORT_ENUM:
         /* USB Normal Mode Access Entring */

         SafeLock(MT_LOCK_FMT, NULL, RTF_INFINITE);

         SysLockFATTask = kal_get_current_thread_ID();

         for (Dev = gFS_DeviceList; Dev->DeviceType; Dev++)
         {
            XTRY
               case XCODE:
                  SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Dev, RTF_INFINITE);
                  FlushAllBuffers(Dev);
                  break;
               default:
               	result = XVALUE;
                  XHANDLED;
                  break;
               case XFINALLY:
                  SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV);
                  break;
            XEND
         }

         /* Export - 2 : Scan FileTable and set FS_FH_EXPORTED for non system drive
          *          ==> app access file handle will get error next time
          *          NOTE: system drive is located on the last partition of gFS_DeviceNumOfSYSDRV device
          */
         RTFSYSLockMutex(RTFLock, RTF_INFINITE);
         for (Dev = gFS_DeviceList; Dev->DeviceType; Dev++)
         {
            if (Dev->DeviceNumber == gFS_DeviceNumOfSYSDRV)
            {
               Drive = Dev->DevData.FirstDrive;
               break; /* system drive found */
            }
         }
         for (i=0, f = gFS_Data.FileTable; i<FS_MAX_FILES; i++, f++)
         {
            if (f->Drive != NULL &&
                f->Task != SysLockFATTask &&
                f->Drive != Drive)
            {
               if (f->Dev->DeviceFlags & MT_DEVICE_NO_EXPORT)
                  continue;

               f->Valid = FS_FH_EXPORTED;

               MTExpireDirCacheByDrive(f->Drive);

               #ifdef __FS_OPEN_HINT__
               MTHintExpireByDrive(f->Drive);
               #endif
            }
         }

         gFS_ExportOwnerTaskID = kal_get_current_thread_ID();

         RTFSYSFreeMutex(RTFLock);

         SafeUnlock(MT_LOCK_FMT);
         break;

      case FS_TASK_PURGE_HANDLE_ENUM:
         /* Purge - 1 : Search the system drive */
         for (Dev = gFS_DeviceList; Dev->DeviceType; Dev++)
         {
            if (Dev->DeviceNumber == gFS_DeviceNumOfSYSDRV)
            {
               Drive = Dev->DevData.FirstDrive;
               break; /* system drive found */
            }
         }

         /* Purge - 2 : Lock Device and Purge FileHandles */
         SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Drive->Dev, RTF_INFINITE);
         for (i = 0, f = gFS_Data.FileTable; i < FS_MAX_FILES; i++, f++)
         {
            if (f->Task != SysLockFATTask && f->Drive != NULL && f->Drive != Drive)
            {
               f->Valid = FS_FH_EXPORTED;

               MTExpireDirCacheByDrive(f->Drive);

               #ifdef __FS_OPEN_HINT__
               MTHintExpireByDrive(f->Drive);
               #endif
            }
         }
         SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV);
         break; /* End of FS_PURGE_HANDLE_ENUM Block */

      case FS_TASK_REMOUNT_ENUM:

         // clean up all exported file handles
         SafeLock(MT_LOCK_RTF, NULL, RTF_INFINITE);
         for (i=0, f = gFS_Data.FileTable; i < FS_MAX_FILES; i++, f++)
         {
            if(f->Valid == FS_FH_EXPORTED)
            {
               FreeFTSlot(f);
            }
         }

         gFS_ExportOwnerTaskID = KAL_NILTASK_ID;

         SafeUnlock(MT_LOCK_RTF);

         SysLockFATTask = 0;
         break;
#endif /* __MTP_ENABLE__ */

      // TODO: Export all Drives (inc. phone drive) except the system drive
      case FS_EXPORT_ENUM:
         /* USB Normal Mode Access Entring */

         SafeLock(MT_LOCK_FMT, NULL, RTF_INFINITE);

         /* Export - 1 : Set exporting flag on normal devices, except for NO_EXPORT flags and system device device
          *          ==> app cannot open file on those devices
          */

         Dev = &gFS_DeviceList[gFS_DeviceNumOfSYSDRV - 1];
         Drive = Dev->DevData.FirstDrive;

         for (Dev = gFS_DeviceList; (Dev!=NULL) && (Dev->DeviceType!=0); Dev++)
         {
            XTRY
               case XCODE:
                  SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Dev, RTF_INFINITE);
                  if (Dev->DeviceFlags & MT_DEVICE_NO_EXPORT || Dev->DeviceNumber == gFS_DeviceNumOfSYSDRV) {
                  }
                  else
                  {
                     FlushAllBuffers(Dev);
                     Dev->DeviceFlags |= MT_DEVICE_EXPORTING;
                     Dev->DevData.Reserved |= FS_DEVICE_ABORT_COUNT_FREE_CLUSTER;
                  }
                  break;
               default:
                  if ((Dev->DeviceFlags & FS_DEVICE_REMOVABLE) && (XVALUE == FS_DRIVE_NOT_READY))
                  {
                     Dev->DeviceFlags |= MT_DEVICE_EXPORTING;
                     Dev->DevData.Reserved |= FS_DEVICE_ABORT_COUNT_FREE_CLUSTER;
                     XHANDLED;
                  }
                  break;
               case XFINALLY:
                  SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV);
                  break;
            XEND
         }

         /* Export - 2 : Scan FileTable and set FS_FH_EXPORTED for non system drive
          *          ==> app access file handle will get error next time
          *          NOTE: system drive is located on the last partition of gFS_DeviceNumOfSYSDRV device
          */

         // Lock Device and Purge FileHandles on the same device with, but not belong to, the system drive.
         SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, &gFS_DeviceList[gFS_DeviceNumOfSYSDRV - 1], RTF_INFINITE);
            for (i = 0, f = gFS_Data.FileTable; i < FS_MAX_FILES; i++, f++)  {

               // File handle is valid, and deivce is not NULL
               if ((f->Valid == MT_ENUM_FH_VALID) && (f->Dev!=NULL))    {
                   // Skip the devices that can not be exported
                   if (f->Dev->DeviceFlags & MT_DEVICE_NO_EXPORT) continue;
                   if (f->Dev == Drive->Dev && f->Drive != Drive)  {
                         f->Valid = MT_ENUM_FH_EXPORTED;
                         MTExpireDirCacheByDrive(f->Drive);
#ifdef __FS_OPEN_HINT__
                         MTHintExpireByDrive(f->Drive);
#endif
                   }
                }
            }

            // Lock the phone drive
            {
                kal_int32 drive_letter;
                WCHAR temp_path[] = {'\\', '\\', '.', '\\', 'x', ':', '\0'};

                drive_letter = MTGetDrive(FS_DRIVE_V_NORMAL, 1, FS_NO_ALT_DRIVE);
                temp_path[4] = drive_letter;

                if (FS_GetDevType(&temp_path[4]) != FS_GetDevType(L"Z"))    {
                    drive_letter = MTGetDrive(FS_DRIVE_V_NORMAL, 2, FS_NO_ALT_DRIVE);
                    temp_path[4] = drive_letter;
                }

                if (drive_letter>0) {
                    // Avoid file handle leak while calling the export twice without re-mount
                    if (gFS_USBMS_PhoneDriveHandle > 0) FS_Close(gFS_USBMS_PhoneDriveHandle);
                    // Open the phone drive, the handle will be closed in FS_REMOUNT_ENUM
                    gFS_USBMS_PhoneDriveHandle = FS_Open(temp_path, FS_READ_WRITE);
                }
            }

         SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV);

         /* Export - 3 : Process each exported device, determined by MT_DEVICE_EXPORTING flag
          *          ==> set the logical drive to unmount state
          */
         for (Dev = gFS_DeviceList; (Dev!=NULL) && (Dev->DeviceType!=0); Dev++)
         {
            if (Dev->DeviceFlags & MT_DEVICE_EXPORTING)
            {
               SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Dev, RTF_INFINITE);
               for(Drive = Dev->DevData.FirstDrive; Drive != NULL; Drive = Drive->NextDrive)
               {
                  Drive->MountState = Mounted; /* Mounted state means MBR/PBR scan already done */

                  MTExpireDirCacheByDrive(Drive);

                  #ifdef __FS_OPEN_HINT__
                  MTHintExpireByDrive(Drive);
                  #endif
               }
               SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV);
            }
         }

         gFS_Export = FS_EXPORTING;
         gFS_ExportOwnerTaskID = kal_get_current_thread_ID();

         SafeUnlock(MT_LOCK_FMT);
         break; /* End of FS_EXPORT_ENUM Block */

      case FS_PURGE_HANDLE_ENUM:
         // This operation is merged into FS_EXPORT_ENUM, and deprecated
         result = FS_PARAM_ERROR;
         break;

      case FS_EXPORT_FINISHED_ENUM:

         if (gFS_Export == FS_EXPORTING)
            gFS_Export = FS_EXPORTED;

         break;

      case FS_REMOUNT_ENUM:

         /* USB Normal Mode Access Exiting */
         SafeLock(MT_LOCK_FMT, NULL, RTF_INFINITE);

         FS_Close(gFS_USBMS_PhoneDriveHandle);
         gFS_USBMS_PhoneDriveHandle = -1;

         /* Remount - 1 : Scan file handle table and Garbage Collection
          */
         RTFSYSLockMutex(RTFLock, RTF_INFINITE);
         for (i=0, f = gFS_Data.FileTable; i<FS_MAX_FILES; i++, f++)
         {
            if(f->Valid == MT_ENUM_FH_EXPORTED)
            {
               FreeFTSlot(f);
            }
         }
         RTFSYSFreeMutex(RTFLock);

         /* Remount - 2 : ReMount exported and unmounted dirves
          */
         for (Dev = gFS_DeviceList; Dev->DeviceType; Dev++)
         {
            if (Dev->DeviceFlags & MT_DEVICE_NO_EXPORT)
               continue;
            /* system drive device may contain dirty buffers, flush it first */
            if (Dev->DeviceNumber == gFS_DeviceNumOfSYSDRV)
            {
               XTRY
                  case XCODE:
                     SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Dev, RTF_INFINITE);
                     FlushAllBuffers(Dev);
                     break;
                  default:
                     break;
                  case XFINALLY:
                     SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV);
                     break;
               XEND
            }
            /* Removable device may have several partitions... for example SIM_PLUS */
            if (Dev->DeviceFlags & RTF_DEVICE_REMOVABLE)
            {
               int PrevCardBusyCheck;

               Dev->DevData.Reserved &= ~FS_DEVICE_ABORT_COUNT_FREE_CLUSTER;
               Dev->DevData.Reserved |= FS_DEVICE_COUNT_FREE_CLUSTER;

               // Skip Free Cluster Counting, if the device is in 1-bit mode.
               if (Dev->Driver->IOCtrl != NULL) {
                    FS_DeviceInfo info;
                    kal_int32 result;
                    result=Dev->Driver->IOCtrl(Dev->DriverData, FS_IOCTRL_QUERY_CARD_INFO, &info);
                    if (FS_NO_ERROR==result && info.DeviceInfo.Card.SerialMode!=0)    {
                        Dev->DevData.Reserved &= ~FS_DEVICE_COUNT_FREE_CLUSTER;
                    }
               }

               PrevCardBusyCheck = CardBusyCheck;
               CardBusyCheck = 1;
               i = MountRemovableDevice(Dev);
               CardBusyCheck = PrevCardBusyCheck;
               Dev->DevData.Reserved &= ~FS_DEVICE_COUNT_FREE_CLUSTER;

               if (i != RTF_NO_ERROR)
               /* removable device status not ready, skip logical drive mount below */
                  continue;
            }
            for(Drive = Dev->DevData.FirstDrive; Drive != NULL; Drive = Drive->NextDrive)
            {
               if (Drive->MountState == HasFileSystem)
                  continue;

               Dev->DevData.Reserved &= ~FS_DEVICE_ABORT_COUNT_FREE_CLUSTER;
               ReMountDriveAndCountFreeClusters(Drive);
            }
         }

         /* Remount - 3 : turn off the exporting flag on each device
          */
         for (Dev = gFS_DeviceList; Dev->DeviceType; Dev++)
         {
            if ((Dev->DeviceFlags & MT_DEVICE_EXPORTING) == 0)
               continue;
            SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Dev, RTF_INFINITE);
            Dev->DeviceFlags &= ~MT_DEVICE_EXPORTING;
            SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV);
         }

         gFS_Export = FS_NOT_EXPORTED;
         gFS_ExportOwnerTaskID = KAL_NILTASK_ID;

         SafeUnlock(MT_LOCK_FMT);

         break; /* End of FS_REMOUNT_ENUM block */

      case FS_CARD_BUSY_NONBLOCK_ENUM:
         CardBusyCheck = 1;
         break;

      default:
         fs_util_trace_err_noinfo(RTF_PARAM_ERROR);

         return RTF_PARAM_ERROR;
   }

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_LOCKFAT_E, result, NULL);

   return result;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides a facility to let task looks up the
      number of partitions on the specified device
PARAMETER
      QueryTarget: the index number get from FS_GetDrive
              OR the type enum get from FS_GetDevType
RETURN
      Success:  Number of partitions on the specified device
      Error:    RTF_PARAM_ERROR
NOTE
   This function cannot wait to get any lock!
------------------------------------------------------------------------------- */
int FS_GetDevPartitions(kal_uint32 QueryTarget)
{
   RTFDrive   *Drive    = NULL;
   RTFDevice  *Dev      = NULL;

   // locate Drive by index , or find it by type flag
   if (QueryTarget >= MT_BASE_DRIVE_LETTER && QueryTarget < (MT_BASE_DRIVE_LETTER + FS_MAX_DRIVES))
   {
      fs_util_trace_info1(TRACE_FUNC, FS_API_FS_GETDEVPARTITIONS_S_DRIVE, QueryTarget, NULL);

      Drive = &gFS_Data.DriveTable[QueryTarget - MT_BASE_DRIVE_LETTER];
   }
   else if (QueryTarget < FS_DEVICE_TYPE_MAX_VALUE)
   {
      fs_util_trace_info1(TRACE_FUNC, FS_API_FS_GETDEVPARTITIONS_S_TYPE, QueryTarget, NULL);

      Dev = (RTFDevice*)fs_conf_find_dev_by_devtype((FS_DEVICE_TYPE_ENUM)QueryTarget, 1);
   }

   // Return if neither Dev nor Drive found
   if (Drive == NULL && Dev == NULL)
   {
      // Fall through... and return PARAM_ERROR
   }
   else
   {
      int count;

      if (Dev == NULL)
      {
         Dev = Drive->Dev;
      }

      // Now Do Counting job
      for(count = 0, Drive = Dev->DevData.FirstDrive; Drive != NULL; Drive = Drive->NextDrive, count++);

      fs_util_trace_info1(TRACE_FUNC, FS_API_FS_GETDEVPARTITIONS_E, count, NULL);

      return count;
   }

   fs_util_trace_err_noinfo(RTF_PARAM_ERROR);

   return RTF_PARAM_ERROR;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides mount/un-mount FS facility on MSDC Card Slots for File Manager
Parameter
      slot_id:   DriverData Pointer
Return
      Success: RTF_NO_ERROR (Card is present, mount successfully)
               MT_MSDC_NOT_PRESENT (Card is not present, unmount successfully)
               MT_EXTERNAL_DEVICE_NOT_PRESENT (Card Reader is not present, unmount successfully)
      Error:   MT_MSDC_MOUNT_ERROR
               RTF_UNSUPPORTED_DEVICE
               RTF_UNSUPPORTED_DRIVER_FUNCTION
Restriction
      1. Only File Manager can call this function.
      2. Other tasks cannot use MSDC until File Manager mount it back.
 ------------------------------------------------------------------------------- */
int FS_TestMSDC(void * slot_id, kal_uint8 * drive_list, kal_uint32 * drive_num)
{
   RTFDevice        *Dev;
   int volatile     Result = RTF_PARAM_ERROR;
   int              i, PrevCardBusyCheck;
   RTFile* volatile f;

   if (drive_list)
      fs_util_trace_info4(TRACE_FUNC, FS_API_FS_TESTMSDC_S_DRIVELIST, (kal_uint32)slot_id, (kal_uint32)drive_list, *drive_num, NULL, NULL);
   else
      fs_util_trace_info1(TRACE_FUNC, FS_API_FS_TESTMSDC_S, (kal_uint32)slot_id, NULL);

   fs_init();

   if (MTFMLock == NULL)
      MTFMLock = RTFSYSAllocMutex("MTFMLock");

   /* TestMSDC - 1 : Lock FMT */
   SafeLock(MT_LOCK_FMT, NULL, RTF_INFINITE);

   /* TestMSDC - 2 : Find the Device Slot by matching DriverData and slot_id */
   for (Dev = gFS_DeviceList; Dev->DeviceType; Dev++)
   {
      if ((Dev->DriverData == slot_id) && (Dev->DeviceFlags & RTF_DEVICE_REMOVABLE))
      {
         break;
      }
   }

   if (Dev->DeviceType == 0) /* Device Not Found */
   {
      SafeUnlock(MT_LOCK_FMT);

      fs_util_trace_err_noinfo(RTF_UNSUPPORTED_DEVICE);

      Result = RTF_UNSUPPORTED_DEVICE;
      goto FS_TestMSDC_Return;
   }

   MTFMLock->DeviceNum_1 = Dev->DeviceNumber;

   /* TestMSDC - 3 : DRV API MessageAck() , MediaChanged() */
   if (Dev->Driver->MessageAck && Dev->Driver->MediaChanged)
   {
      //XXX: don't lock device && don't check Dev's MountState
      Result = Dev->Driver->MessageAck(Dev->DriverData, FS_DEV_SLOT_ACK_ENUM);
      //XXX: don't lock device && don't check Dev's MountState
      Result = Dev->Driver->MediaChanged(Dev->DriverData);
   }
   else
   {
      /* driver does not support hot plug-in and plug-out */
      MTFMLock->DeviceNum_1 = 0;
      SafeUnlock(MT_LOCK_FMT);

      fs_util_trace_err_noinfo(RTF_UNSUPPORTED_DRIVER_FUNCTION);

      Result = RTF_UNSUPPORTED_DRIVER_FUNCTION;
      goto FS_TestMSDC_Return;
   }

   /*------------------------------------------------------------
    * now Result is the return value of Dev->Driver->MediaChanged
    *------------------------------------------------------------*/

   /* TestMSDC - 4 : Consider Exported Case */
   if (Dev->DeviceFlags & MT_DEVICE_EXPORTING)
   {
      switch (Result)
      {
         /* 4-1 : Return Exported Error */
         case MT_MSDC_PRESNET_NOT_READY:

            // set device as NotMounted for hot plug-out case
            if (Dev->DevData.MountState != NotMounted)
               Dev->DevData.MountState = NotMounted;

         case RTF_NO_ERROR:           // go through

            Result = MT_DEVICE_EXPORTED_ERROR;
            break;

         /* 4-2 : Return Plug-Out */
         case MT_MSDC_NOT_PRESENT:
         case MT_EXTERNAL_DEVICE_NOT_PRESENT:

            // set device as NotMounted for hot plug-out case
            if (Dev->DevData.MountState != NotMounted)
               Dev->DevData.MountState = NotMounted;

         default:                     // go through
            Result = MT_MSDC_NOT_PRESENT;
            break;
      }

      if(drive_list)
      {
           RTFDrive * D = Dev->DevData.FirstDrive;
           for (i=0; D && i<*drive_num; i++, D = D->NextDrive)
           {
              drive_list[i] = MT_BASE_DRIVE_LETTER + (D - gFS_Data.DriveTable);
           }
           *drive_num = i;
      }

      if(Result==MT_EXTERNAL_DEVICE_NOT_PRESENT || Result==MT_MSDC_NOT_PRESENT)
      {
          while(Dev->DevData.FirstDrive && Dev->DevData.FirstDrive->NextDrive)
          {
              Dev->DevData.FirstDrive->Dev = NULL;
              Dev->DevData.FirstDrive = Dev->DevData.FirstDrive->NextDrive;
          }
      }

      MTFMLock->DeviceNum_1 = 0;
      SafeUnlock(MT_LOCK_FMT);

      fs_util_trace_err_noinfo(Result);

      goto FS_TestMSDC_Return;
   }

   /* TestMSDC - 5 : Branch By Previous MountState Primary, By MediaChanged() Return Value Secondary */
   Dev->DevData.Reserved |= FS_DEVICE_COUNT_FREE_CLUSTER;

   // Skip Free Cluster Counting, if the device is in 1-bit mode.
   if (Dev->Driver->IOCtrl != NULL) {
        FS_DeviceInfo info;
        kal_int32 result;
        result=Dev->Driver->IOCtrl(Dev->DriverData, FS_IOCTRL_QUERY_CARD_INFO, &info);
        if (FS_NO_ERROR==result && info.DeviceInfo.Card.SerialMode!=0)    {
            Dev->DevData.Reserved &= ~FS_DEVICE_COUNT_FREE_CLUSTER;
        }
   }

   PrevCardBusyCheck = CardBusyCheck;
   CardBusyCheck = 1;

   if (Dev->DevData.MountState == NotMounted)
   {
      switch (Result)
      {
         /* 5-A-1 : Mount The Removable Device */
         case MT_MSDC_PRESNET_NOT_READY:
         case RTF_NO_ERROR:
            Dev->DeviceFlags |= RTF_DEVICE_BUSY_READ_ONLY;
            Result = MountRemovableDevice(Dev);
            Dev->DeviceFlags &= ~RTF_DEVICE_BUSY_READ_ONLY;
            break;

         /* 5-A-2 : Do Nothing */
         case MT_MSDC_NOT_PRESENT:
         case MT_EXTERNAL_DEVICE_NOT_PRESENT:
         default:
            break;
      }
   }
   else /* Previous MountState == Mounted ; However, May not HasFileSystem */
   {
      switch (Result)
      {
         /* 5-B-1 : Set UnMount, Release all Opened File Handle */
         case MT_EXTERNAL_DEVICE_NOT_PRESENT:
         case MT_MSDC_NOT_PRESENT:

            Dev->DevData.MountState = NotMounted;

            for (i=0, f = gFS_Data.FileTable; i<FS_MAX_FILES; i++, f++)
            {
               if(f->Dev == Dev)
               {
                  f->Valid = FS_FH_MEDIACHANGED;
               }
            }

            // unmount device to discard all buffers of this device
            SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Dev, RTF_INFINITE);
            UnmountDevice(Dev, 0);
            SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV);

            break;

         /* 5-B-2 : Set UnMount, Release all Opened File Handle, Then Re-Mount it */
         case MT_MSDC_PRESNET_NOT_READY:

            Dev->DevData.MountState = NotMounted;

            for (i=0, f = gFS_Data.FileTable; i<FS_MAX_FILES; i++, f++)
            {
               if(f->Dev == Dev)
               {
                  f->Valid = FS_FH_MEDIACHANGED;
               }
            }
            Result = MountRemovableDevice(Dev);
            break;

         /* 5-B-3 : Do Nothing */
         case RTF_NO_ERROR:
            if (Dev->DevData.MountState < HasFileSystem)
            {
               Result = MountRemovableDevice(Dev);
            }
            break;
         default:
            break;
      }
   }

   CardBusyCheck = PrevCardBusyCheck;
   Dev->DevData.Reserved &= ~FS_DEVICE_COUNT_FREE_CLUSTER;

   /* fill drive letters to drive list if requred */
   if(drive_list)
   {
      RTFDrive * D = Dev->DevData.FirstDrive;
      for (i=0; D && i<*drive_num; i++, D = D->NextDrive)
      {
          drive_list[i] = MT_BASE_DRIVE_LETTER + (D - gFS_Data.DriveTable);
      }
      *drive_num = i;
   }

   /* unlink all drives from non-present device */
   if(Result==MT_EXTERNAL_DEVICE_NOT_PRESENT || Result==MT_MSDC_NOT_PRESENT)
   {
       while(Dev->DevData.FirstDrive && Dev->DevData.FirstDrive->NextDrive)
       {
           Dev->DevData.FirstDrive->Dev = NULL;
           Dev->DevData.FirstDrive = Dev->DevData.FirstDrive->NextDrive;
       }
   }

   /* TestMSDC - 6 : UnLock and Return */
   MTFMLock->DeviceNum_1 = 0;
   SafeUnlock(MT_LOCK_FMT);

FS_TestMSDC_Return:

   if (Result == MT_MSDC_PRESNET_NOT_READY)
      Result =  MT_MSDC_MOUNT_ERROR;

   if (drive_list)
      fs_util_trace_info2(TRACE_FUNC, FS_API_FS_TESTMSDC_E_DRIVELIST, Result, *drive_num, NULL);
   else
      fs_util_trace_info1(TRACE_FUNC, FS_API_FS_TESTMSDC_E, Result, NULL);

   return Result;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides formal plug out facility on MSDC (built-in or OTG external) for File Manager
PARAMETER
      DriveIdx:   The drive index (0x43, 0x44, ...etc.)
      Mode:       FS_NONBLOCK_MODE
                  0x0  default block mode
RETURN
      Success:    RTF_NO_ERROR
      Error:      RTF_PARAM_ERROR
                  RTF_DRIVE_NOT_FOUND
                  RTF_INVALID_FILE_SYSTEM
                  RTF_TIMEOUT
NOTE
      1. Only File Manager can call this function.
      2. Double lock in this function!
 ------------------------------------------------------------------------------- */
int FS_CloseMSDC(kal_uint32 DriveIdx, kal_uint32 Mode)
{
   #if !defined(__FS_SLIM_SOFT_UNMOUNT__)

   RTFDrive *volatile Drive;
   int                Result = RTF_NO_ERROR;

   fs_util_trace_info2(TRACE_FUNC, FS_API_FS_CLOSEMSDC_S, DriveIdx, Mode, NULL);

   if(RTFLock == NULL)
   {
      fs_util_trace_err_noinfo(RTF_INVALID_FILE_SYSTEM);

      return RTF_INVALID_FILE_SYSTEM;
   }

   if(MTFMLock == NULL)
      MTFMLock = RTFSYSAllocMutex("MTFMLock");

   if((Mode != FS_NONBLOCK_MODE) && (Mode != 0x0))
   {
      fs_util_trace_err_noinfo(RTF_PARAM_ERROR);

      return RTF_PARAM_ERROR;
   }

   // locate Drive by index
   if (DriveIdx >= MT_BASE_DRIVE_LETTER && DriveIdx < (MT_BASE_DRIVE_LETTER + FS_MAX_DRIVES))
   {
      Drive = &gFS_Data.DriveTable[DriveIdx - MT_BASE_DRIVE_LETTER];
   }
   else
   {
      fs_util_trace_err_noinfo(RTF_DRIVE_NOT_FOUND);

      return RTF_DRIVE_NOT_FOUND;
   }

   if((Drive->Dev == NULL) || ((Drive->Dev->DeviceFlags & RTF_DEVICE_REMOVABLE) == 0))
   {
      fs_util_trace_err_noinfo(RTF_UNSUPPORTED_DEVICE);

      return RTF_UNSUPPORTED_DEVICE;
   }

   // Now Lock FMT, DEVICE, and RTFLock
   SafeLock(MT_LOCK_FMT, NULL, RTF_INFINITE);

   if (Mode == FS_NONBLOCK_MODE)
   {
      Result = SafeLock(MT_LOCK_DEV, Drive->Dev, RTF_NO_WAIT);

      if (Result != RTF_NO_ERROR)
      {
         Result = RTF_TIMEOUT;

         fs_util_trace_err_noinfo(Result);

         goto CloseReturn;
      }

      Result = SafeLock(MT_LOCK_RTF, NULL, RTF_NO_WAIT);

      if(Result != RTF_NO_ERROR)
      {
         Result = RTF_TIMEOUT;

         fs_util_trace_err_noinfo(Result);

         goto CloseReturn;
      }
   }
   else
   {
      SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Drive->Dev, RTF_INFINITE);
   }

   // Now Do clean up jobs
   XTRY
   case XCODE:
      CloseDevice(Drive->Dev);
      break;
   default:
      Result = XVALUE; //API dose not need XHANDLED
      SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV | MT_LOCK_FMT);
      break;
   case XFINALLY:

      #ifdef __FS_OPEN_HINT__
      MTHintExpireByDrive(Drive);
      #endif

      Drive->Dev->DevData.MountState = NotMounted;
      break;
   XEND_API

CloseReturn:
   SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV | MT_LOCK_FMT);

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_CLOSEMSDC_E, Result, NULL);

   fs_util_check_stack();

   return Result;

   #else    // __FS_SLIM_SOFT_UNMOUNT__

   return FS_ERR_UNSUPPORTED_SERVICE;

   #endif   // !__FS_SLIM_SOFT_UNMOUNT__
}

/* ------------------------------------------------------------------------------- */
int FS_GetDriveByHandle(FS_HANDLE handle)
{
    kal_int32   ft_idx;

    ft_idx = FS_ParseFH(handle);

    if (ft_idx < FS_NO_ERROR)
        return ft_idx;

    return (gFS_Data.FileTable[ft_idx].Drive - gFS_Data.DriveTable) + MT_BASE_DRIVE_LETTER;
}

int FS_SetSeekHintEx(FS_HANDLE FileHandle, kal_uint32 HintCount, kal_uint32 Flag, void *Buffer, kal_uint32 BufferSize)
{
   #if defined(__FS_SMART_FILE_SEEKER__) && !defined(__FS_PROPRIETARY_SET__)

   RTFSeekHintData     *D;
   RTFile * volatile    f = NULL;
   RTFile * volatile    f2 = NULL;
   FS_FileLocationHint *Hint;
   kal_uint32           Stone, FileSize, i;
   kal_int32 volatile   Result = FS_NO_ERROR;

   XTRY
      case XCODE:

         fs_util_trace_info4(TRACE_FUNC, FS_API_FS_SETSEEKHINTEX_S, FileHandle, HintCount, Flag, (kal_uint32)Buffer, NULL);

         /*
          * Memory checker (address and size)
          *
          * We need 4-byte aligned buffer
          */

         if (Buffer)
         {
            i = (kal_uint32)Buffer & 0x3;

            if (i != 0)
            {
               Buffer = (void *)((kal_uint32)Buffer + i);

               BufferSize -= i;

               if (HintCount <= 1)
               {
                  fs_util_trace_err_noinfo(FS_FAIL_GET_MEM);
                  XRAISE(FS_FAIL_GET_MEM);
               }

               HintCount -= 1;   // discount one hint for 4-byte aligned buffer address
            }
            else if (HintCount == 0)
            {
               fs_util_trace_err_noinfo(FS_PARAM_ERROR);
               XRAISE(FS_PARAM_ERROR);
            }

            // check buffer size
            if (BufferSize < FS_SEEKHINT_BUFFER_SIZE_FOR_HINT_CNT(HintCount))
            {
               fs_util_trace_err_noinfo(FS_FAIL_GET_MEM);
               XRAISE(FS_FAIL_GET_MEM);
            }
         }
         else // hint buffer unavailable
         {
            fs_util_trace_err_noinfo(FS_FAIL_GET_MEM);
            XRAISE(FS_FAIL_GET_MEM);
         }

         /*
          * Memory checker (conflict)
          *
          * Hint buffer should be unique for each file handle
          */

         for (i = 0; i < FS_MAX_FILES; i++)
         {
            f2 = gFS_Data.FileTable + i;

            if (f2->Lock != 0) // FileTable[Stone]->SeekHintData should be zero and not raise exception
            {
               if (f2->usr_ptr == Buffer)   // hint buffer should not used by others
               {
                  fs_util_trace_err_noinfo(FS_FAIL_GET_MEM);

                  XRAISE(FS_FAIL_GET_MEM);
               }
            }
         }

         // assign seek data buffer pointer
         D = (RTFSeekHintData*)Buffer;
         Hint = (FS_FileLocationHint *)((kal_uint8 *)Buffer + sizeof(RTFSeekHintData));
         D->StaticHintCount   = HintCount;

         // get file entry pointer
         f = ParseFileHandle(FileHandle);

         if (f->SpecialKind != NormalFile)
         {
            fs_util_trace_err_noinfo(FS_INVALID_FILE_HANDLE);

            XRAISE(FS_INVALID_FILE_HANDLE);
         }

         /*
          * See if user wants to place hint in advance.
          */
         if (Flag & FS_SEEKHINT_FLAG_INITIALIZE_HINT)
         {
            // 1. Get file size
            Result = FS_GetFileSize(FileHandle, &FileSize);
            if (Result < FS_NO_ERROR) XRAISE (Result);

            // 2. Reset hint
            kal_mem_set(Hint, 0, D->StaticHintCount * sizeof(RTFDirLocation));

            // 3. Calculate range
            D->StaticHintRange = FileSize / (D->StaticHintCount + 1);

            if (D->StaticHintRange < f->Drive->ClusterSize)
               D->StaticHintRange = f->Drive->ClusterSize;

            // 4. Generate milestones
            for (i = 0, Stone = D->StaticHintRange; i < D->StaticHintCount && Stone <= FileSize; i++, Stone += D->StaticHintRange)
               Hint[i].Index = Stone;

            // 5. Place hints by FS_SetSeekHint()

            UnlockDevice(f->Dev);   // release device and system lock because FS_SetSeekHint will lock them

            f = NULL;   // reset f to avoid incorrectly releasing device lock in XFinally section

            Result = FS_SetSeekHint(FileHandle, i, (FS_FileLocationHint*)Hint);

            if (Result < FS_NO_ERROR)
            {
               XRAISE(Result);
            }

            f = ParseFileHandle(FileHandle); // lock device and system lock again

            D->UsedStaticHintCount = i;

            // 6. Set placed hints as STATIC type (merge to below section)
         }

         /*
          * Setup Smart File Seeker stuff
          */

         // 1. Common part
         f->usr_ptr_type = FS_TBL_USR_PTR_MILESTONE;
         f->usr_ptr = D;
         f->Seek_Hint    = (RTFDirLocation *)((kal_uint8 *)Buffer + sizeof(RTFSeekHintData));

         // 2. Other part
         if ((Flag & FS_SEEKHINT_FLAG_INITIALIZE_HINT) == 0)
         {
            D->UsedStaticHintCount     = 0;
            D->StaticHintRange         = f->DirEntry.Dir.FileSize / (D->StaticHintCount + 1);

            if (D->StaticHintRange < f->Drive->ClusterSize)
               D->StaticHintRange = f->Drive->ClusterSize;

            f->HintNum                 = 0;

            kal_mem_set(f->Seek_Hint, 0, D->StaticHintCount * sizeof(RTFDirLocation));
         }

         break;

      default:

         Result = XVALUE;
         break;

      case XFINALLY:

         if (f)
         {
            UnlockDevice(f->Dev);
         }

         fs_util_trace_info1(TRACE_FUNC, FS_API_FS_SETSEEKHINTEX_E, Result, NULL);

         break;
   XEND_API

   return FS_NO_ERROR;

   #else    // !__FS_SMART_FILE_SEEKER__ || __FS_PROPRIETARY_SET__

   return FS_NO_ERROR;

   #endif   // __FS_SMART_FILE_SEEKER__ && !__FS_PROPRIETARY_SET__
}

int FS_CompactDir(const WCHAR* DirName, kal_uint32 Flags)
{
   int result;

   fs_util_trace_info1(TRACE_FUNC | MT_TRACE_INFO_WSTR, FS_API_FS_COMPACTDIR_S, Flags, (void*)DirName);

   result = RTFCompactDir(DirName, Flags);

   fs_util_trace_info0(TRACE_FUNC, FS_API_FS_COMPACTDIR_E, NULL);

   return result;
}

int FS_CloseAll(void)
{
   int Result = RTF_NO_ERROR;

   fs_util_trace_info0(TRACE_FUNC, FS_API_FS_CLOSEALL_S, NULL);

   if (INT_QueryExceptionStatus() == KAL_FALSE)
   {
      fs_err_user_fatal(FS_ERR_API_CLOSE_ALL, NULL);
   }

   gFS_USBMS_PhoneDriveHandle = -3;

   Result = RTFCloseAll();

   fs_util_trace_info0(TRACE_FUNC, FS_API_FS_CLOSEALL_E, NULL);

   fs_util_check_stack();

   return Result;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function will do the file handle garbage collection
PARAMETER
      TaskId:  The magic number of the task
RETURN
      Success: RTF_NO_ERROR
------------------------------------------------------------------------------- */
int FS_ReleaseFH(void * TaskId)
{
   if(TaskId)
      fs_util_trace_info1(TRACE_FUNC, FS_API_FS_RELEASEFH_S_TASKID, (kal_uint32)TaskId, NULL);
   else
      fs_util_trace_info0(TRACE_FUNC, FS_API_FS_RELEASEFH_S_ALLTASK, NULL);

   ReleaseFH(TaskId);

   fs_util_trace_info0(TRACE_FUNC, FS_API_FS_RELEASEFH_E, NULL);

   fs_util_check_stack();

   return RTF_NO_ERROR;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function parse the file handle to a index (start from 0) to file table
PARAMETER
      FileHandle: the specified file handle
RETURN
      >=0    : the index to file table
      Error : RTF_INVALID_FILE_HANDLE
------------------------------------------------------------------------------- */
int FS_ParseFH(FS_HANDLE FileHandle)
{
   kal_uint32 U = FileHandle >> (4*sizeof(int));
   kal_uint32 i = FileHandle & ((1 << (4*sizeof(int))) - 1);
   RTFile * f;

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_PARSEFH_S, FileHandle, NULL);

   f = gFS_Data.FileTable + i;

   if (i >= FS_MAX_FILES)
   {
      fs_util_trace_err_noinfo(RTF_INVALID_FILE_HANDLE);

      return RTF_INVALID_FILE_HANDLE;
   }

   if (f->Lock == 0)
   {
      fs_util_trace_err_noinfo(RTF_INVALID_FILE_HANDLE);

      return RTF_INVALID_FILE_HANDLE;
   }

   if (f->Unique != U)
   {
      fs_util_trace_err_noinfo(RTF_INVALID_FILE_HANDLE);

      return RTF_INVALID_FILE_HANDLE;
   }

   if (f->Dev == NULL)
   {
      fs_util_trace_err_noinfo(RTF_INVALID_FILE_HANDLE);

      return RTF_INVALID_FILE_HANDLE;
   }

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_PARSEFH_E, i, NULL);

   return i;
}

/* ------------------------------------------------------------------------------- */
int FS_SetFileTime(FS_HANDLE FileHandle, const FS_DOSDateTime * Time)
{
   int Result = RTF_NO_ERROR;

   fs_util_trace_info2(TRACE_FUNC, FS_API_FS_SETFILETIME_S, FileHandle, (kal_uint32)Time, NULL);

   Result = RTFSetFileTime(FileHandle, (RTFDOSDateTime *)Time);

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_SETFILETIME_E, Result, NULL);

   fs_util_check_stack();

   return Result;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides merge facility for MMTF
PARAMETER
      FileName1:  File being extended
      FileName2:  Append to FileName1, and FileName2 will be deleted
RETURN
      Success:    RTF_NO_ERROR
      Error:      RTF_INVALID_FILENAME
                  RTF_FILE_NOT_FOUND
                  RTF_ACCESS_DENIED
                  RTF_DRIVE_NOT_FOUND
NOTE
      This function will
      (1) Check file size and cross link
      (2) Append File2 to File1 without caring the last cluster of
          File1 is not cluster alinged. One calling this API should
          be aware that RTF_COMMITTED is the default setting of this call.
------------------------------------------------------------------------------- */
int FS_PseudoMerge(const WCHAR * FileName1, const WCHAR * FileName2)
{
   RTFile * volatile f1 = NULL;
   RTFile * volatile f2 = NULL;
   RTFCluster        lastC_Pos, lastC_Value, CrossPilot;
   kal_uint32        ClusterCount = 1;
   int volatile      Result = RTF_NO_ERROR;
   #ifdef __FS_OPEN_HINT__
   RTFDirLocation *volatile hint = NULL;
   #endif

   fs_util_trace_info0(TRACE_FUNC | MT_TRACE_INFO_WSTR, FS_API_FS_PSEUDOMERGE_S_FILE1, (void*)FileName1);
   fs_util_trace_info0(TRACE_FUNC | MT_TRACE_INFO_WSTR, FS_API_FS_PSEUDOMERGE_S_FILE2, (void*)FileName2);

   fs_init();

   XTRY
      case XCODE:
         f1 = ParseFileName((char *)FileName1);
         RTFSYSFreeMutex(RTFLock);
         f2 = ParseFileName((char *)FileName2);

         if(f1->Drive != f2->Drive)
         {
            fs_util_trace_err_noinfo(RTF_ACCESS_DENIED);

            XRAISE(RTF_ACCESS_DENIED);
         }

         /* General check */
         if(f1->Dev->DeviceFlags & MT_DEVICE_WRITE_PROTECT)
         {
            fs_util_trace_err_noinfo(RTF_WRITE_PROTECTION);

            XRAISE(RTF_WRITE_PROTECTION);
         }

         if ((f1->SpecialKind != NormalFile) || (f2->SpecialKind != NormalFile))
         {
            fs_util_trace_err_noinfo(RTF_INVALID_FILENAME);

            XRAISE(RTF_INVALID_FILENAME);
         }

         #ifdef __FS_OPEN_HINT__
         hint = MTHintGet(FileName2, MT_HINT_ACTION_FORCE_NO_NEW);
         if (!SearchFile(f2, SEARCH_FILES, (char *)FileName2, hint)) //merge has done before
         #else
         if (!SearchFile(f2, SEARCH_FILES, (char *)FileName2, NULL)) //merge has done before
         #endif /* __FS_OPEN_HINT__ */
         {
            fs_util_trace_err_noinfo(RTF_FILE_NOT_FOUND);

            XRAISE(RTF_FILE_NOT_FOUND);
         }

         if (!SearchFile(f1, SEARCH_FILES, (char *)FileName1, NULL)) //search to fill data
         {
            fs_util_trace_err_noinfo(RTF_FILE_NOT_FOUND);

            XRAISE(RTF_FILE_NOT_FOUND);
         }

         CheckNotOpen(f1);
         CheckNotOpen(f2);

         if ((f1->DirEntry.Dir.Attributes & (RTF_ATTR_READ_ONLY | RTF_ATTR_DIR | RTF_ATTR_VOLUME)) ||
             (f2->DirEntry.Dir.Attributes & (RTF_ATTR_READ_ONLY | RTF_ATTR_DIR | RTF_ATTR_VOLUME)))
         {
            fs_util_trace_err_noinfo(MT_READ_ONLY_ERROR);

            XRAISE(MT_READ_ONLY_ERROR);
         }

          f1->Flags |= RTF_COMMITTED;
          f2->Flags |= RTF_COMMITTED;

         /* Check file2 size */
         lastC_Pos = FIRST_FILE_CLUSTER(f2->DirEntry.Dir);
         CrossPilot = lastC_Pos;
         lastC_Value = GetClusterValue(f2->Drive, lastC_Pos);

         while(lastC_Value < RTF_CLUSTER_CHAIN_END)
         {
            if(lastC_Value < 2L)
            {
               fs_util_trace_err_noinfo(RTF_FAT_ALLOC_ERROR);

               XRAISE(RTF_FAT_ALLOC_ERROR);
            }

            lastC_Pos = lastC_Value;
            lastC_Value = GetClusterValue(f2->Drive, lastC_Pos);
            ClusterCount++;
         }

         /* If not correct, start to modify file2 size */
         if((f2->DirEntry.Dir.FileSize <= f2->Drive->ClusterSize*(ClusterCount-1)) ||
            (f2->DirEntry.Dir.FileSize > f2->Drive->ClusterSize*ClusterCount))
         {
            f2->DirEntry.Dir.FileSize = f2->Drive->ClusterSize*ClusterCount;
            UpdateDirEntry(f2);
         }

         /* Check file1 size */
         ClusterCount = 1;
         lastC_Pos = FIRST_FILE_CLUSTER(f1->DirEntry.Dir);
         lastC_Value = GetClusterValue(f1->Drive, lastC_Pos);

         while(lastC_Value < RTF_CLUSTER_CHAIN_END)
         {
            if(lastC_Value < 2L)
            {
               fs_util_trace_err_noinfo(RTF_FAT_ALLOC_ERROR);

               XRAISE(RTF_FAT_ALLOC_ERROR);
            }

            if(lastC_Pos == CrossPilot) /* Cross link */
            {
               DeleteDirEntry(f2); // will commit itself if with RTF_COMMITTED
               goto MergeReturn;
            }

            lastC_Pos = lastC_Value;
            lastC_Value = GetClusterValue(f1->Drive, lastC_Pos);
            ClusterCount++;
         }

         /* If not correct, start to modify file1 size */
         if((f1->DirEntry.Dir.FileSize <= f1->Drive->ClusterSize*(ClusterCount-1)) ||
            (f1->DirEntry.Dir.FileSize > f1->Drive->ClusterSize*ClusterCount))
         {
            f1->DirEntry.Dir.FileSize = f1->Drive->ClusterSize*ClusterCount;
            UpdateDirEntry(f1);
         }

         /* Modify file size of File1 (round-up to cluster aligned) */
         if(f1->Drive->ClusterSize > 0)
            f1->DirEntry.Dir.FileSize =
               ((f1->DirEntry.Dir.FileSize + f1->Drive->ClusterSize - 1) / f1->Drive->ClusterSize)
               *(f1->Drive->ClusterSize) + f2->DirEntry.Dir.FileSize;
         else
         {
            fs_util_trace_err_noinfo(RTF_DRIVE_NOT_FOUND);

            XRAISE(RTF_DRIVE_NOT_FOUND);
         }

         UpdateDirEntry(f1);

         lastC_Pos = FIRST_FILE_CLUSTER(f1->DirEntry.Dir);
         lastC_Value = GetClusterValue(f1->Drive, lastC_Pos);
         while(lastC_Value < RTF_CLUSTER_CHAIN_END)
         {
            if(lastC_Value < 2L)
            {
               fs_util_trace_err_noinfo(RTF_FAT_ALLOC_ERROR);

               XRAISE(RTF_FAT_ALLOC_ERROR);
            }

            lastC_Pos = lastC_Value;
            lastC_Value = GetClusterValue(f1->Drive, lastC_Pos);
         }

         /* Start to delete File2 DIR entry */
         DeleteDirEntry(f2);

         /* Connect two chains */
         SetClusterValue(f1->Drive, lastC_Pos, FIRST_FILE_CLUSTER(f2->DirEntry.Dir));
         CommitBuffer(f1->Dev);

MergeReturn:
         break;
      default:
         Result = XVALUE; //API dose not need XHANDLED
         break;
      case XFINALLY:
         if (f2 != NULL) /* imply f1 != NULL, see above */
         {
            #ifdef __FS_OPEN_HINT__
            if (hint)
            {
               // delete perfect matched hint
               if (MTHintGetMatchType(hint) == MT_HINT_MATCH_PERFECT)
                  MTHintDelete(MTHintGetIndex(hint));
            }
            #endif /* __FS_OPEN_HINT__ */

            FreeFTSlotAndDevice(f2);
            RTFSYSLockMutex(RTFLock, RTF_INFINITE);
            FreeFTSlotAndDevice(f1);
         }
         else if (f1 != NULL)
         {
            FreeFTSlotAndDevice(f1);
         }
         break;
   XEND_API

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_PSEUDOMERGE_E, Result, NULL);

   fs_util_check_stack();

   return Result;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides sanity check function for the specified file
PARAMETER
      FileName:  File to be checked
RETURN
      Success:    RTF_NO_ERROR
      Error:      RTF_CHECKDISK_RETRY (sanity check fail)
                  Other error code caused by user error (from FS_Open fail)
NOTE
      This function will adjust the allocated clusters to fit the file size
      automatically if needed
------------------------------------------------------------------------------- */
int FS_CheckFile(const WCHAR * FileName)
{
   RTFile * volatile f = NULL;
   RTFCluster lastC_Pos, lastC_Value;
   kal_uint32 FATClusterCount = 0, DIRClusterCount;
   int volatile Result = RTF_NO_ERROR;

   fs_util_trace_info0(TRACE_FUNC | MT_TRACE_INFO_WSTR, FS_API_FS_CHECKFILE_S, (void*)FileName);

   XTRY
      case XCODE:
         f = ParseFileName((char *)FileName);

         if(f->Dev->DeviceFlags & MT_DEVICE_WRITE_PROTECT)
         {
            fs_util_trace_err_noinfo(RTF_WRITE_PROTECTION);

            XRAISE(RTF_WRITE_PROTECTION);
         }

         if(f->SpecialKind != NormalFile)
         {
            fs_util_trace_err_noinfo(RTF_INVALID_FILENAME);

            XRAISE(RTF_INVALID_FILENAME);
         }

         if (!SearchFile(f, SEARCH_FILES, (char *)FileName, NULL)) //search to fill data
         {
            fs_util_trace_err_noinfo(RTF_FILE_NOT_FOUND);

            XRAISE(RTF_FILE_NOT_FOUND);
         }

         CheckNotOpen(f);

         f->Flags |= RTF_COMMITTED;

         /* Count the cluster chain length , base on Dir.FileSize , ROUND-UP */
         DIRClusterCount = (f->DirEntry.Dir.FileSize + f->Drive->ClusterSize - 1) / f->Drive->ClusterSize;

         lastC_Pos = FIRST_FILE_CLUSTER(f->DirEntry.Dir);
         if(lastC_Pos != 0)
         {
            lastC_Value = GetClusterValue(f->Drive, lastC_Pos);

            while(lastC_Value < RTF_CLUSTER_CHAIN_END)
            {
               if(lastC_Value < 2L) //The Cluster Chain BROKEN
               {
                  fs_util_trace_err_noinfo(RTF_CHECKDISK_RETRY);

                  XRAISE(RTF_CHECKDISK_RETRY);
               }

               if ((FATClusterCount == DIRClusterCount)) //The Chain should END , but not
               {
                  if( DIRClusterCount > 0 )
                  {
                     SetClusterValue(f->Drive, lastC_Pos, 0x0FFFFFFFL); //RTF_CHAIN_END_MARK
                  }
                  else  // DIRClusterCount = 0
                  {
                     /* release lastC_Pos */
                     SetClusterValue(f->Drive, lastC_Pos, 0);
                     UpdateClusterWatermark(f->Drive, lastC_Pos, 1);

                     /* resst first cluster number in directory entry */
                     SET_FIRST_FILE_CLUSTER(f->DirEntry.Dir, 0);
                     UpdateDirEntry(f);
                  }
               }
               else if ( FATClusterCount > DIRClusterCount ) //The Chain has redundancy, Clear it
               {
                  SetClusterValue(f->Drive, lastC_Pos, 0);
                  UpdateClusterWatermark(f->Drive, lastC_Pos, 1);
               }

               /* Next iteration */
               lastC_Pos = lastC_Value;
               lastC_Value = GetClusterValue(f->Drive, lastC_Pos);
               FATClusterCount++;
            }

            /* The Last Cluster, CHAIN_END_MARK */
            if( FATClusterCount > DIRClusterCount ) //Clear Original CHAIN_END_MARK
            {
               SetClusterValue(f->Drive, lastC_Pos, 0);
               UpdateClusterWatermark(f->Drive, lastC_Pos, 1);
            }

            FATClusterCount++;
         } //END if ( File's First Cluster != 0 )

         /* If not correct, start to modify file size */
         if (FATClusterCount < DIRClusterCount) //Dir.FileSize > actual allocated FAT Chain Capability
         {
            f->DirEntry.Dir.FileSize = f->Drive->ClusterSize*FATClusterCount;
            UpdateDirEntry(f);
         }

         break;
      default:
         Result = XVALUE; //API dose not need XHANDLED
         break;
      case XFINALLY:
         if (f != NULL) FreeFTSlotAndDevice(f);
         break;
   XEND_API

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_CHECKFILE_E, Result, NULL);

   fs_util_check_stack();

   return Result;
}

/* ------------------------------------------------------------------------------- */
int FS_Extend(FS_HANDLE FileHandle, kal_uint32 Length)
{
   int Result = RTF_NO_ERROR;

   fs_util_trace_info2(TRACE_FUNC, FS_API_FS_EXTEND_S, FileHandle, Length, NULL);

   Result = RTFExtend(FileHandle, Length);

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_EXTEND_E, Result, NULL);

   fs_util_check_stack();

   return Result;
}

/* ------------------------------------------------------------------------------- */
int FS_MakeFileName(FS_HANDLE FileHandle, kal_uint32 Flag, WCHAR * FileName, kal_uint32 MaxLength)
{
   int Result = RTF_NO_ERROR;
   RTFDirLocation Pos;
   RTFile * f;

   fs_util_trace_info4(TRACE_FUNC, FS_API_FS_MAKEFILENAME_S, FileHandle, Flag, MaxLength, NULL, NULL);

   if (MaxLength < ((8+3+1+1) * sizeof(WCHAR)))
   {
      fs_util_trace_err_noinfo(RTF_PARAM_ERROR);

      return RTF_PARAM_ERROR;
   }

   Result = FS_ParseFH(FileHandle);

   if (Result < RTF_NO_ERROR)
   {
      fs_util_trace_err_noinfo(Result);

      return Result;
   }

   f = gFS_Data.FileTable + Result;

   // FS_MakeFileName only supports NormalFile
   if (f->SpecialKind != NormalFile)
   {
      fs_util_trace_err_noinfo(FS_INVALID_FILE_HANDLE);

      return FS_INVALID_FILE_HANDLE;
   }

   if (Flag & FS_LONGNAME_ATTR)
      Pos = f->DirEntry.LongPos;
   else
      Pos = f->DirEntry.ShortPos;

   if (Pos.Cluster == 0)
   {
      fs_util_trace_err_noinfo(RTF_PARAM_ERROR);

      return RTF_PARAM_ERROR;
   }

   Result = MTMakeFileName(f->Drive, &Pos, FileName, MaxLength);

   if (Result < RTF_NO_ERROR)
   {
      fs_util_trace_err_noinfo(Result);

      return Result;
   }

   fs_util_trace_info1(TRACE_FUNC | MT_TRACE_INFO_WSTR, FS_API_FS_MAKEFILENAME_E, Result, (void*)FileName);

   fs_util_check_stack();

   return Result;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides a facility to reset a sort list
      recursively
PARAMETER
      PatternArray:  Multi-patterns array (should not have drive name)
      PatternNum:    Indicate how many pattern in PatternArray
      ArrayMask:     The attributes that match default NamePattern only
      AttrMask:      Filter out the name with these attributes
      Flag:          MT_NO_SORT, MT_SORT_NAME, MT_SORT_SIZE, MT_SORT_ATTR,
                     MT_SORT_TIME, MT_SORT_TYPE
      Timeout:       RTF_NO_WAIT, RTF_INFINITE
      Position:      The pointer to sorted array
RETURN
      Success: RTF_NO_ERROR
      Error:   RTF_PARAM_ERROR
               MT_FAIL_GET_MEM
               RTF_GENERAL_FAILURE
               RTF_TOO_MANY_FILES
NOTE
      1. No matter sort or not, no matter what kinds of sort, files
         should always put behind folders
------------------------------------------------------------------------------- */
#ifdef __FS_SORT_SUPPORT__

int FS_SortCompareFileName(WCHAR *FileName1, WCHAR *FileName2)
{
    int j;
    kal_uint32 u, v;

    for(j=0; j<=RTF_MAX_PATH; j++)
    {
       u = fs_util_wchar_toupper(FileName1[j]);
       v = fs_util_wchar_toupper(FileName2[j]);

       if(u < v)
       {
           return -1;
       }
       else if(u != v)
       {
           return 1;
       }
       else if(u == 0)
       {
           return 0;
       }
    }
    return 0;
}

int FS_SortCompareFileType(WCHAR *FileName1, WCHAR *FileName2)
{
    kal_uint32 TypeIdx = 0;
    char * sPtr;
    char * TmpsPtr;
    kal_uint32 TmpDotIdx;
    int j;

    kal_uint32 CheckPoint;
    int OffSet;
    kal_bool ExtNameTieFlag = KAL_FALSE;

    sPtr = kal_dchar_strrchr((char *)FileName1, 0x002e);
    if(sPtr)
    {
     sPtr += 2;
     TypeIdx = (sPtr - (char *)FileName1)/2;
    }

    if(TypeIdx == 0)
    { /* There is no extension name on both filename,
       * or just singular WCHAR extension name on both filename,
       * or the extension name are compared and tie to tie.
       */
SortTypeTie:   ExtNameTieFlag = KAL_TRUE;
       CheckPoint = 0;
       OffSet = 0;
       goto SortTypeContinue;
    }
    else
    {
       TmpsPtr = kal_dchar_strrchr((char *)FileName2, 0x002e);
       TmpDotIdx = (TmpsPtr - (char *)FileName2)/2 + 1;
       OffSet = TmpDotIdx - TypeIdx;
       CheckPoint = TypeIdx;
    }

SortTypeContinue:
    for(j=CheckPoint; j<=RTF_MAX_PATH; j++)
    {
       if((FileName1[j] == 0) && (FileName2[j+OffSet] == 0))
       {
          if(ExtNameTieFlag == KAL_FALSE)
          {  goto SortTypeTie;}
          return 0;
       }
       if ((FileName2[j+OffSet] == 0x2E) || (fs_util_wchar_toupper(FileName1[j]) > fs_util_wchar_toupper(FileName2[j+OffSet])))
          return 1;
       else if ((FileName1[j] == 0x2E) || fs_util_wchar_toupper(FileName1[j]) < fs_util_wchar_toupper(FileName2[j+OffSet]))
          return -1;
    }
    return 0;
}

int FS_XFindReset(FS_SortingParam *Param)
{
    FSSortingInternalS *SortingData;
    int Count;
    int Result = FS_NO_ERROR;

    if (Param == NULL)
    {
        fs_util_trace_err_noinfo(FS_PARAM_ERROR);

        return FS_PARAM_ERROR;
    }

    fs_util_trace_info2(TRACE_FUNC | MT_TRACE_INFO_WSTR, FS_API_FS_XFINDRESET_S, Param->PatternNum, Param->Flag, (void*)(Param->Pattern));

    // Verify Flags
    if((Param->Flag & FS_SORT_USER && !Param->CompareFunc))
    {
        Result = FS_PARAM_ERROR;
    }

    if ((Param->Flag & FS_FILE_TYPE) == 0 && (Param->Flag & FS_DIR_TYPE) == 0)

        Result = FS_PARAM_ERROR;

    if ((Param->Flag & (FS_NO_SORT | FS_SORT_NAME | FS_SORT_SIZE | FS_SORT_ATTR | FS_SORT_TYPE | FS_SORT_TIME | FS_SORT_USER)) == 0 )

        Result = FS_PARAM_ERROR;

    if (Param->Flag & ~(FS_FILE_TYPE | FS_DIR_TYPE | FS_NO_SORT | FS_SORT_NAME | FS_SORT_SIZE | FS_SORT_ATTR | FS_SORT_TIME | FS_SORT_TYPE | FS_SORT_USER))

       Result = FS_PARAM_ERROR;

    if (Result < FS_NO_ERROR)
    {
        fs_util_trace_err_noinfo(Result);

        return Result;
    }

    fs_init();

    if (MTSortLock == NULL)
      MTSortLock = RTFSYSAllocMutex("MTSortLock");

    Result = SafeLock(MT_LOCK_SORT, NULL, Param->Timeout);

    if(Result != RTF_NO_ERROR)
    {
        return Result;
    }

    if(!Param->Position || !Param->SortingBuffer || !Param->WorkingBuffer)
    {
        SafeUnlock(MT_LOCK_SORT);
        return FS_FAIL_GET_MEM;
    }

    // Calculate the max file number
    // Check Sorting buffer
    Count = ((Param->SortingBufferSize - sizeof(FSSortingInternalS))/sizeof(RTFDirLocation));
    // Check working buffer
    Result = ((Param->WorkingBufferSize - sizeof(RTFDOSDirEntry) - 3*MT_MAX_WIDE_PATH)/(sizeof(kal_uint32)+sizeof(kal_uint32)));

    if(Count<=0 || Result<=0)
    {
        SafeUnlock(MT_LOCK_SORT);
        return FS_FAIL_GET_MEM;
    }

    SortingData = (FSSortingInternalS*)Param->SortingBuffer;

    if(memcmp(SortingData->Signature, FS_SORTING_SIGNATURE, sizeof(SortingData->Signature))==0)
    {
        SafeUnlock(MT_LOCK_SORT);
        return FS_PARAM_ERROR;
    }

    // reset whole structure to 0
    kal_mem_set(SortingData, 0, sizeof(FSSortingInternalS));

    // Initialize the working buffer to 0
    kal_mem_set((char*)Param->WorkingBuffer, 0, Param->WorkingBufferSize);

    // setup the signature.
    memcpy(SortingData->Signature, FS_SORTING_SIGNATURE, sizeof(SortingData->Signature));

    // setup the user lock
    SortingData->UserLock ++;

    // setup position list
    SortingData->PosList = (RTFDirLocation*)(Param->SortingBuffer + sizeof(FSSortingInternalS));
    SortingData->PosList_File = SortingData->PosList + Count;

    // setup working buffer
    SortingData->HintList = (kal_uint32*)(Param->WorkingBuffer);
    SortingData->HintList_File = SortingData->HintList + Result;
    SortingData->HintList2 = SortingData->HintList_File;
    SortingData->HintList2_File = SortingData->HintList2 + Result;

    // setup the max file count
    SortingData->MaxCount = Count<Result?Count:Result;
    SortingData->MaxCount --;

    // Limit the maximun sorting count
    SortingData->MaxCount = SortingData->MaxCount>FS_SORTING_MAX_ENTRY?FS_SORTING_MAX_ENTRY:SortingData->MaxCount;

    SortingData->FileName = (kal_uint8*)SortingData->HintList2_File;
    SortingData->TmpName1 = (kal_uint8*)(SortingData->FileName) + MT_MAX_WIDE_PATH;
    SortingData->TmpName2 = (kal_uint8*)(SortingData->TmpName1) + MT_MAX_WIDE_PATH;
    SortingData->FileInfo = (RTFDOSDirEntry*)(SortingData->TmpName2 + MT_MAX_WIDE_PATH);

    SortingData->PosList--;
    SortingData->HintList--;
    SortingData->HintList2--;

    *Param->Position = (kal_uint32)SortingData;

    if(!(Param->Flag&(FS_SORT_USER)))
    {
         Param->CompareFunc = CompareFileName;
    }

    Count = CreateHeap(Param, SortingData);

    SortingData->Status = FS_SORT_PGS_START;

    SafeUnlock(MT_LOCK_SORT);

    if(Count < FS_NO_ERROR)
    {
        if(Count==FS_ABORTED_ERROR)
        {
            SortingData->Status = FS_SORT_PGS_ABORT;
        }
        else
        {
            SortingData->Status = FS_SORT_PGS_FAIL;
        }
    }
    else
    {
        if(Param->Flag & FS_NO_SORT)
        {
            if(Param->ProgressCallback && Param->ProgressCallback(FS_SORT_PGS_START, SortingData->TotalCount, 0, Param->ProgressCallbackParam)<0)
            {
                Count = FS_ABORTED_ERROR;
                SortingData->Status = FS_SORT_PGS_ABORT;
            }
            else
            {
                SortingData->ReadyCount = Count;
                SortingData->Status = FS_SORT_PGS_DONE;
            }
        }
        else if((Result = HeapSort(Param, SortingData))<FS_NO_ERROR)
        {
            if(Result==FS_ABORTED_ERROR)
            {
                SortingData->Status = FS_SORT_PGS_ABORT;
            }
            else
            {
                SortingData->Status = FS_SORT_PGS_FAIL;
            }
            Count = Result;
        }
        else
        {
            SortingData->Status = FS_SORT_PGS_DONE;
        }
    }
    if(Param->ProgressCallback && Param->ProgressCallback(SortingData->Status, SortingData->TotalCount, SortingData->TotalCount, Param->ProgressCallbackParam)<0)
    {
        Count = FS_ABORTED_ERROR;
        SortingData->Status = FS_SORT_PGS_ABORT;
    }

    Result = SafeLock(MT_LOCK_SORT, NULL, RTF_INFINITE);

    SortingData->UserLock --;

    if(Count<0)
    {
        kal_mem_set(SortingData->Signature, 0, sizeof(SortingData->Signature));
    }

    SafeUnlock(MT_LOCK_SORT);

    fs_util_trace_info1(TRACE_FUNC, FS_API_FS_XFINDRESET_E, Count, NULL);

    return Count;
}

#endif

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides a facility to get a sort list
      recursively
PARAMETER
      Pattern:    Find Pattern
      FileInfo:   File information
      FileName:   File name
      MaxLength:  The length of FileName buffer
      Index:      Find index
      Position:   The sorted list
RETURN
      Success:  RTF_NO_ERROR
      Error:    RTF_PARAM_ERROR
                RTF_NO_MORE_FILES
                RTF_ACCESS_DENIED
------------------------------------------------------------------------------- */
#ifdef __FS_SORT_SUPPORT__

int FS_XFindStart(const WCHAR * Pattern, FS_DOSDirEntry * FileInfo, WCHAR * FileName,
                  kal_uint32 MaxLength, kal_uint32 Index, kal_uint32 * Position, kal_uint32 Flag)
{
   int Result = RTF_NO_ERROR;
   RTFDirLocation Pos;
   FSSortingInternalS *SortingData;

   RTFDirLocation *PosList;

   RTFDirLocation *PosList_File;

   #ifdef __FS_OPEN_HINT__
   RTFDirLocation *hint = NULL;
   #endif

   fs_util_trace_info4(TRACE_FUNC | MT_TRACE_INFO_WSTR, FS_API_FS_XFINDSTART_S, Index, MaxLength, Flag, NULL, (void*)Pattern);

   if((Position==NULL) || (RTFLock == NULL) || (MTSortLock == NULL))
      return RTF_ACCESS_DENIED;

   fs_init();

   if(MTSortLock == NULL)
      MTSortLock = RTFSYSAllocMutex("MTSortLock");

   Result = SafeLock(MT_LOCK_SORT, NULL, 0);

   SortingData = (FSSortingInternalS *)*Position;

   // Check the signature
   if(memcmp(SortingData->Signature, FS_SORTING_SIGNATURE, sizeof(SortingData->Signature))!=0)
   {
        SafeUnlock(MT_LOCK_SORT);
        return FS_PARAM_ERROR;
   }

   SortingData->UserLock ++;

   PosList = SortingData->PosList;
   PosList_File = SortingData->PosList_File;

   if(Index>=SortingData->TotalCount)
   {
      Result = RTF_NO_MORE_FILES;
      goto FindStartReturn;
   }

   // if data is not ready, sleep 1 sec.
   while(SortingData->ReadyCount<Index &&
            (SortingData->Status==FS_SORT_PGS_START || SortingData->Status==FS_SORT_PGS_ING))
   {
       kal_sleep_task(KAL_TICKS_1_SEC);
   }

   if(SortingData->Status!=FS_SORT_PGS_START && SortingData->Status!=FS_SORT_PGS_ING && SortingData->Status!=FS_SORT_PGS_DONE)
   {
      Result = RTF_NO_MORE_FILES;
      goto FindStartReturn;
   }

   if(Index<SortingData->FolderCount)
   {
       Pos = PosList[SortingData->FolderCount-Index];
   }
   else if((Index-SortingData->FolderCount)<ABS(SortingData->FileCount))
   {
       Index -= SortingData->FolderCount;
       Pos = PosList_File[SortingData->FileCount+Index];
   }
   else
   {
       Result = RTF_NO_MORE_FILES;
       goto FindStartReturn;
   }

   if(Pos.Cluster < 2)
   {
      Result = RTF_NO_MORE_FILES;
      goto FindStartReturn;
   }

   Result = fs_srv_get_name_by_pos(NULL, Pattern, (RTFDOSDirEntry *)FileInfo, FileName, MaxLength, &Pos, Flag);

   if(Result >= RTF_NO_ERROR)
   {
      Result = Index + 1;

      #ifdef __FS_OPEN_HINT__
      if (0 == (SortingData->Flag & FS_SORTING_IS_FLAG_HINT_DISABLED))
      {
          // add hint for file found
          hint = MTHintGet(Pattern, MT_HINT_ACTION_FORCE_NEW);

          if (hint)
              MTHintNewManual(MTHintGetIndex(hint), Pattern, FileName, &Pos, SortingData->DirCluster);
      }
      #endif
   }
   else
   {
      fs_util_trace_err_noinfo(Result);
   }

   fs_util_check_stack();

FindStartReturn:

   SortingData->UserLock --;
   SafeUnlock(MT_LOCK_SORT);

   if (FileInfo)
      fs_util_trace_info1(TRACE_FUNC | MT_TRACE_INFO_WSTR, FS_API_FS_XFINDSTART_E_INFO, FileInfo->Attributes, (void*)FileName);
   else
      fs_util_trace_info0(TRACE_FUNC | MT_TRACE_INFO_WSTR, FS_API_FS_XFINDSTART_E, (void*)FileName);

   return Result;
}

#endif

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides a facility to close a sort list
PARAMETER
      Position:   Sorted list pointer
RETURN
      Success:    RTF_NO_ERROR
      Error:      RTF_PARAM_ERROR
                  RTF_ACCESS_DENIED
------------------------------------------------------------------------------- */
#ifdef __FS_SORT_SUPPORT__

int FS_XFindClose(kal_uint32 * Position)
{
   FSSortingInternalS *SortingData;

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_XFINDCLOSE_S, (kal_uint32)Position, NULL);

   if((RTFLock == NULL) || (MTSortLock == NULL) || (Position == NULL))
   {
      fs_util_trace_err_noinfo(RTF_ACCESS_DENIED);

      return RTF_ACCESS_DENIED;
   }

   SafeLock(MT_LOCK_SORT, NULL, 0);

   SortingData = (FSSortingInternalS *)*Position;
   // Check the signature
   if(memcmp(SortingData->Signature, FS_SORTING_SIGNATURE, sizeof(SortingData->Signature))!=0)
   {
        SafeUnlock(MT_LOCK_SORT);
        return FS_PARAM_ERROR;
   }

   // Check if there's a query in progress.
   if(SortingData->UserLock>0)
   {
       SafeUnlock(MT_LOCK_SORT);
       return RTF_ACCESS_DENIED;
   }

   kal_mem_set(SortingData->Signature, 0, sizeof(SortingData->Signature));

   SafeUnlock(MT_LOCK_SORT);

   fs_util_trace_info0(TRACE_FUNC, FS_API_FS_XFINDCLOSE_E, NULL);

   fs_util_check_stack();

   return RTF_NO_ERROR;
}

#endif

/* ------------------------------------------------------------------------------- */
int FS_GetPartitionInfo(const WCHAR * DriveName, FS_PartitionRecord * PartitionInfo)
{
   int Result = RTF_NO_ERROR;

   fs_util_trace_info2(TRACE_FUNC, FS_API_FS_GETPARTITIONINFO_S, *(kal_uint8*)DriveName, (kal_uint32)PartitionInfo, NULL);

   Result = RTFGetPartitionInfo(DriveName, (RTFPartitionInfo *)PartitionInfo, FS_PARTITION_INFO_BASIC);

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_GETPARTITIONINFO_E, Result, NULL);

   fs_util_check_stack();

   return Result;
}

/* ------------------------------------------------------------------------------- */
int FS_CommitAll(const WCHAR * DriveName)
{
   int Result = RTF_NO_ERROR;

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_COMMITALL_S, *(kal_uint8*)DriveName, NULL);

   Result = RTFCommitAll(DriveName);

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_COMMITALL_E, Result, NULL);

   fs_util_check_stack();

   return Result;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides NVRAM to map system drive name at run time
PARAMETER
      UpperOldDrv: Old drive name with capitalization determinated by FS
      UpperNewDrv: New drive name with capitalization defined by NVRAM
RETURN
      Success: RTF_NO_ERROR
      Error:   RTF_PARAM_ERROR
               RTF_DRIVE_NOT_READY
NOTE
      1. Only one combination is supported. Call twice will lose former setting.
      2. Only NVRAM can call this function.
------------------------------------------------------------------------------- */
int FS_MappingDrive(kal_uint32 UpperOldDrv, kal_uint32 UpperNewDrv)
{
    int Result = RTF_NO_ERROR;

    fs_util_trace_info2(TRACE_FUNC, FS_API_FS_MAPPINGDRIVE_S, UpperOldDrv, UpperNewDrv, NULL);

    Result = MTMappingDrive(UpperOldDrv, UpperNewDrv);

    //Result = MTMappingDrive(UpperOldDrv, UpperNewDrv);

    fs_util_trace_info1(TRACE_FUNC, FS_API_FS_MAPPINGDRIVE_E, Result, NULL);

    fs_util_check_stack();

    return Result;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function can query the free space left in gFS_IntQuotaSet (Quota Management only)
PARAMETER
      Path: The path defined in gFS_IntQuotaSet
RETURN
      Success: Free space in bytes
      Error:   RTF_PATH_NOT_FOUND         (QM token not found)
               RTF_DRIVE_NOT_FOUND        (QM token found, but not mounted)
               RTF_INVALID_FILE_SYSTEM    (QM token found, but freecluster unknow yet)
               RTF_ACCESS_DENIED          (QM token found, but flag is not enabled)
NOTE
      Path name should be exactly the same as one in gFS_IntQuotaSet
------------------------------------------------------------------------------- */
#ifdef __FS_QM_SUPPORT__

int FS_QmGetFree(const kal_uint8 * Path)
{
   int Result = RTF_PATH_NOT_FOUND;
   int RFS_for_Other, FreeSpace1, FreeSpace2;
   int i, j, k;
   RTFDrive * Drive;
   WCHAR drv_letter;

   fs_util_trace_info0(TRACE_FUNC, FS_API_FS_QMGETFREE_S, NULL);
   fs_util_trace_str(TRACE_FUNC | MT_TRACE_INFO_BSTR, (void*)Path);

   // get native (original) drive letter
   drv_letter = fs_conf_get_native_drive_letter((WCHAR)Path[0]);

   if (0 == drv_letter)
   {
      return Result;
   }

   SafeLock(MT_LOCK_RTF, NULL, RTF_INFINITE);

   for(i = FS_MAX_QSET - 1 ; i >= 0 ; i--)
   {
      /*
       * Compare drive letter (after transform to real drive letter)
       * PS. We do not hard-coded 'Z' as the quota-supported drive, thus we transform every gFS_IntQuotaSet[].Path[0] here
       */
      if (fs_conf_get_native_drive_letter((WCHAR)(gFS_IntQuotaSet[i].Path[0])) != drv_letter)
         continue;

      /* Compare the Path */
      for (j = 1; j < RTF_MAX_PATH/2; j++)
      {
         if ((gFS_IntQuotaSet[i].Path[j] == 0x00) && (Path[j] == 0x00)) // exactly match
         {
            /* calculate RFS_for_Other */
            RFS_for_Other = 0;

            for (k = FS_MAX_QSET - 1 ; k >= 0 ; k--)
            {
               if (k != i)
               {
                  if (gFS_IntQuotaSet[k].Qmin > gFS_IntQuotaSet[k].Uint)
                  {
                     RFS_for_Other += (gFS_IntQuotaSet[k].Qmin - gFS_IntQuotaSet[k].Uint);
                  }
               }
            }

            // locate drive
            Drive = &gFS_Data.DriveTable[drv_letter - MT_BASE_DRIVE_LETTER];

            if (Drive->MountState < HasFileSystem)
            {
               Result = RTF_DRIVE_NOT_FOUND;
               goto QmGetFreeReturn;
            }

            if (Drive->QuotaMgt)
            {
               if (Drive->FreeClusterCount == RTF_INVALID_CLUSTER)
               {
                  Result = RTF_INVALID_FILE_SYSTEM;
                  goto QmGetFreeReturn;
               }

               FreeSpace1 = (Drive->FreeClusterCount > RFS_for_Other) ?
                            (Drive->FreeClusterCount - RFS_for_Other) : 0;

               if (gFS_IntQuotaSet[i].Qmax == 0) //FS_QMAX_NO_LIMIT
               {
                  Result = FreeSpace1;
               }
               else
               {
                  FreeSpace2 = gFS_IntQuotaSet[i].Qmax - gFS_IntQuotaSet[i].Uint;
                  Result = (FreeSpace1 > FreeSpace2) ? FreeSpace2 : FreeSpace1; //min
               }

               Result *= Drive->ClusterSize;
               goto QmGetFreeReturn;
            }
            else
            {
               Result = RTF_ACCESS_DENIED;
               goto QmGetFreeReturn;
            }
         }

         if (gFS_IntQuotaSet[i].Path[j] != Path[j])
            break;
      } /* End for(j...) */
   } /* End for(i...) */

QmGetFreeReturn:
   SafeUnlock(MT_LOCK_RTF);

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_QMGETFREE_E, Result, NULL);

   fs_util_check_stack();

   return Result;
}

#else

// Quota Management Disabled, always return RTF_PATH_NOT_FOUND.
int FS_QmGetFree(const kal_uint8 * Path)
{
    return RTF_PATH_NOT_FOUND;
}

#endif

/* ------------------------------------------------------------------------------- */
int FS_CheckDiskFlag(void)
{
   int Result = RTF_NO_ERROR;

   fs_util_trace_info0(TRACE_FUNC, FS_API_FS_CHECKDISKFLAG_S, NULL);

   Result = RTFCheckBootUpFlag();

   fs_util_trace_info0(TRACE_FUNC, FS_API_FS_CHECKDISKFLAG_E, NULL);

   fs_util_check_stack();

   return Result;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides formal plug out facility on MSDC (built-in or OTG external) for File Manager
PARAMETER
      DriveIdx:   The drive index (0x43, 0x44, ...etc.)
      Mode:       FS_NONBLOCK_MODE
                  FS_MODE_SOFT_UNMOUNT
                  FS_MODE_SOFT_MOUNT
                  0x0  default block mode
RETURN
      Success:    RTF_NO_ERROR
      Error:      RTF_PARAM_ERROR
                  RTF_DRIVE_NOT_FOUND
                  RTF_INVALID_FILE_SYSTEM
                  RTF_TIMEOUT
NOTE
      1. Only File Manager can call this function.
      2. Double lock in this function!
 ------------------------------------------------------------------------------- */
int FS_SwitchDriveMode(kal_uint32 DriveIdx, kal_uint32 Mode)
{
   #if !defined(__FS_SLIM_OTG__)

   RTFDrive *volatile Drive;
   int                Result = RTF_NO_ERROR;

   fs_util_trace_info2(TRACE_FUNC, FS_API_FS_SWITCHDRIVEMODE_S, DriveIdx, Mode, NULL);

   if(RTFLock == NULL)
   {
      fs_util_trace_err_noinfo(RTF_INVALID_FILE_SYSTEM);

      return RTF_INVALID_FILE_SYSTEM;
   }

   if(MTFMLock == NULL)
      MTFMLock = RTFSYSAllocMutex("MTFMLock");

   // locate Drive by index
   if (DriveIdx >= MT_BASE_DRIVE_LETTER && DriveIdx < (MT_BASE_DRIVE_LETTER + FS_MAX_DRIVES))
   {
      Drive = &gFS_Data.DriveTable[DriveIdx - MT_BASE_DRIVE_LETTER];
   }
   else
   {
      fs_util_trace_err_noinfo(RTF_DRIVE_NOT_FOUND);

      return RTF_DRIVE_NOT_FOUND;
   }

   if((Drive->Dev == NULL) || ((Drive->Dev->DeviceFlags & RTF_DEVICE_REMOVABLE) == 0))
   {
      fs_util_trace_err_noinfo(RTF_UNSUPPORTED_DEVICE);

      return RTF_UNSUPPORTED_DEVICE;
   }

   // Now Lock FMT, DEVICE, and RTFLock
   SafeLock(MT_LOCK_FMT, NULL, RTF_INFINITE);

   if (Mode & FS_NONBLOCK_MODE)
   {
      Result = SafeLock(MT_LOCK_DEV, Drive->Dev, RTF_NO_WAIT);

      if(Result != RTF_NO_ERROR)
      {
         Result = RTF_TIMEOUT;

         fs_util_trace_err_noinfo(Result);

         goto CloseReturn;
      }

      Result = SafeLock(MT_LOCK_RTF, NULL, RTF_NO_WAIT);

      if(Result != RTF_NO_ERROR)
      {
         Result = RTF_TIMEOUT;

         fs_util_trace_err_noinfo(Result);

         goto CloseReturn;
      }
   }
   else
   {
      SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Drive->Dev, RTF_INFINITE);
   }

   // Now Do clean up jobs
   XTRY
   case XCODE:
      if(Mode & FS_DRIVE_SOFT_UNMOUNT)
      {
          CloseDevice(Drive->Dev);

          // Save the original value
          if(Drive->Dev->DeviceFlags & MT_DEVICE_WRITE_PROTECT)
              Drive->Dev->DevData.Reserved |= 0x01;
          else
              Drive->Dev->DevData.Reserved &= ~0x01;

          Drive->Dev->DeviceFlags |= MT_DEVICE_WRITE_PROTECT;
      }
      else if(Mode & FS_DRIVE_SOFT_MOUNT)
      {
          // Save the original value
          if(Drive->Dev->DevData.Reserved & 0x01)
              Drive->Dev->DeviceFlags |= MT_DEVICE_WRITE_PROTECT;
          else
              Drive->Dev->DeviceFlags &= ~MT_DEVICE_WRITE_PROTECT;
      }
      break;
   default:
      Result = XVALUE; //API dose not need XHANDLED
      SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV | MT_LOCK_FMT);
      break;
   case XFINALLY:

      #ifdef __FS_OPEN_HINT__
      MTHintExpireByDrive(Drive);
      #endif

      break;
   XEND_API

CloseReturn:
   SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV | MT_LOCK_FMT);

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_SWITCHDRIVEMODE_E, Result, NULL);

   fs_util_check_stack();

   return Result;

   #else    // __FS_SLIM_OTG__

   return FS_ERR_UNSUPPORTED_SERVICE;

   #endif   // !__FS_SLIM_OTG__
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      Some file formats pack multiple objects inside. This API is designed for programmers
      who want to process inside objects without copy overhead. Users call this API to
      generate a virtual file name (full-path string in fact) first. Then users can
      FS_Open(), FS_Read(), and FS_Seek() against virtual file just like a normal file.
PARAMETER
      LargeFile         The file-handler of the real-file that virtual-file mapped into.
      VFileNameBuf      A pointer of the file name string buffer provided to store
                        generated file name.
      BufLength         The available buffer length (in byte unit) of VFileNameBuf provided
                        to prevent buffer overflow.
      VFBeginOffset     Specify the segment beginning (in byte unit) in the real-file to
                        be treated as virtual-file content.
      VFValidLength     Specify the segment length (in byte unit) in the real-file to be
                        treated as virtual-file content.
RETURN
      Success:    RTF_NO_ERROR
      Error:      RTF_INVALID_FILENAME
                  RTF_PARAM_ERROR
NOTE
 ------------------------------------------------------------------------------- */
int FS_GenVirtualFileName(FS_HANDLE File, WCHAR * VFileNameBuf, kal_uint32 BufLength, kal_uint32 VFBeginOffset, kal_uint32 VFValidLength)
{
   int Result = RTF_NO_ERROR;

   fs_util_trace_info4(TRACE_FUNC, FS_API_FS_GENVIRTUALFILENAME_S, File, VFBeginOffset, VFValidLength, BufLength, NULL);

   Result = MTGenVirtualFileName( File, VFileNameBuf, BufLength, VFBeginOffset, VFValidLength);

   fs_util_trace_info1(TRACE_FUNC | MT_TRACE_INFO_WSTR, FS_API_FS_GENVIRTUALFILENAME_E, Result, (void*)VFileNameBuf);

   return Result;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      To support a special kind of device --- Card Reader, which contain variance number of slots.
PARAMETER
      Action         accept FS_SETUP_EXT_DEVICE or FS_RELEASE_EXT_DEVICE only
      DrvFuncs       The Device Driver Callback Functions, {MountDevice, Shutdown, ... }
      Slots          Number of independent slots, fill 1 device entry and *allocate* 1
                     drive element per slot.
      SlotIdArray    The DriverData (treat as slot-id) array to be fill on device list.
      SlotsDone      The Number of slots that configured and supported in FS.
RETURN
      Success:    Number of slots configured succeed.
      Error:      RTF_INVALID_FILENAME
                  RTF_PARAM_ERROR
NOTE
      Currently, No *allocate* operation commited, this API is design to keep FMT/FS/DRV iterface
      complete. But not real dynamic yet!
 ------------------------------------------------------------------------------- */
int FS_ConfigExtDevice(int Action, FS_Driver *DrvFuncs, int Slots, void **SlotIdArray, int *SlotsConfiged)
{
   int Result = RTF_NO_ERROR;
   RTFDevice *Dev = NULL;
   RTFDevice *FirstDev = NULL;
   int DevEntryCnt = 0;

   fs_util_trace_info4(TRACE_FUNC, FS_API_FS_CONFIGEXTDEVICE_S, Action, (kal_uint32)DrvFuncs, Slots, NULL, NULL);

   /* ConfigExt - 1 check parameter */
   if ((DrvFuncs == NULL) || (SlotIdArray == NULL) || (Slots < 1))
   {
      fs_util_trace_err_noinfo(RTF_PARAM_ERROR);

      return RTF_PARAM_ERROR;
   }

   /* ConfigExt - 2 Protect for concurrency or un-init state */
   fs_init();

   if (MTFMLock == NULL)
      MTFMLock = RTFSYSAllocMutex("MTFMLock");

   SafeLock(MT_LOCK_FMT, NULL, RTF_INFINITE);

   *SlotsConfiged = 0;

   /* ConfigExt - 3 Locate First Entry by Driver and Check if not supported */
   for (Dev = gFS_DeviceList; Dev->DeviceType; Dev++)
   {
      if ((Dev->Driver == (RTFDriver*) DrvFuncs) && (Dev->DeviceFlags & MT_DEVICE_EXTERNAL))
      {
         FirstDev = Dev;    // remember the first external device for MessageAck

         break;
      }
   }

   if (Dev->DeviceType == 0) // DrvFuncs is NOT FOUND!
   {
      fs_util_trace_err_noinfo(RTF_UNSUPPORTED_DEVICE);
      fs_util_trace_info0(TRACE_ERROR, FS_ERR_DRIVER_NOT_FOUND, NULL);

      SafeUnlock(MT_LOCK_FMT);

      return RTF_UNSUPPORTED_DEVICE;
   }

   if (Dev->Driver->MessageAck == NULL)
   {
      fs_util_trace_err_noinfo(RTF_UNSUPPORTED_DEVICE);
      fs_util_trace_info0(TRACE_ERROR, FS_ERR_MESSAGEACK_NOT_FOUND, NULL);

      SafeUnlock(MT_LOCK_FMT);

      return RTF_UNSUPPORTED_DRIVER_FUNCTION;
   }

   /* ConfigExt - 4 Procedure -- IN */
   if (Action == FS_SETUP_EXT_DEVICE)
   {
      //XXX: don't lock device && don't check Dev's MountState
      Result = Dev->Driver->MessageAck(Dev->DriverData, FS_DEV_IN_ACK_ENUM);

      if (Result >= RTF_NO_ERROR)
      {
         /* Assumption:
          *  The DeviceList Cannot be Dynamic ReSize, Determined on Build-time
          */
         /* Dev is the First Entry  */

         for (DevEntryCnt = 0 /* , Dev = gFS_DeviceList */; Dev->DeviceType; Dev++)
         {
            if (Slots > 0 && (Dev->Driver == (RTFDriver*) DrvFuncs) && (Dev->DeviceFlags & MT_DEVICE_EXTERNAL))
            {
               #ifdef FS_DYNAMIC_DEVICE_SUPPORT
               /******** PSEUDO CODE *********
                * Lock Dev and RTF
                      SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Dev, RTF_INFINITE);
                * Setup DeviceList
                      Dev->DriverData = SlotIdArray[DevEntryCnt];
                * Allocate Drive Table Entry
                      DrivePtr = malloc();
                * Hook to Device List
                      Dev->DevData.FirstDrive = DrivePtr;
                      DrivePtr->Dev = Dev;
                * Hook to DriveLetter Lookup Table
                      DriveLetterTBL[ 'M' + DevEntryCnt ] = DrivePtr;
                * Release LOCK
                      SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV);
                ******************************/
               #else
               /* NOTE: AllocateDrive() will pass even if it run out of gFS_Data.DriveTable
                *       Check Dev->DevData.FirstDrive here to make sure it's enough
                */
               if (Dev->DevData.FirstDrive == NULL)
               {
                  continue;
               }
               #endif
               DevEntryCnt++;
               Slots--;
            }
         }
         /* Set *SlotsConfiged Value HERE */
         *SlotsConfiged = DevEntryCnt;

         g_ExternalDevice = KAL_TRUE;
      }
   }
   /* ConfigExt - 4 OUT_ACK procedure, !!MUST!! call MessageAck() after release */
   else if (Action == FS_RELEASE_EXT_DEVICE)
   {
      /* Assumption:
       *  The DeviceList Cannot be Dynamic ReSize, Determined on Build-time
       */
      /* Dev is the First Entry  */
      for (DevEntryCnt = 0 /* , Dev = gFS_DeviceList */; Dev->DeviceType; Dev++)
      {
         if (Slots > 0 && (Dev->Driver == (RTFDriver*) DrvFuncs) && (Dev->DeviceFlags & MT_DEVICE_EXTERNAL))
         {
#ifdef FS_DYNAMIC_DEVICE_SUPPORT
            /******** PSEUDO CODE *********
             * Lock Dev and RTF
                   SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Dev, RTF_INFINITE);
             * Safe CHECK for FileTable
                   .....
             * Release Device-->Drive Relation Linking
                   DrivePtr = Dev->DevData.FirstDrive;
                   Dev->DevData.FirstDrive = NULL;
                   DrivePtr->Dev = NULL;
             * Clear Reference on DriveLetter Lookup Table
                   DriveLetterTBL[ 'M' + DevEntryCnt ] = NULL;
             * Clear Slot-id on DeviceList TABLE
                   Dev->DriverData = NULL;
             * Free Drive Table Entry
                   free( DrivePtr );
             * Release LOCK
                   SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV);
             ******************************/
#else
            /* NOTE: AllocateDrive() will pass even if it run out of gFS_Data.DriveTable
             *       Check Dev->DevData.FirstDrive here to make sure it's enough
             */
            if (Dev->DevData.FirstDrive == NULL)
            {
               continue;
            }
#endif
            DevEntryCnt++;
            Slots--;
         }
      }
      /* Set *SlotsConfiged Value HERE */
      *SlotsConfiged = DevEntryCnt;

      g_ExternalDevice = KAL_FALSE;

      //XXX: don't lock device && don't check Dev's MountState
      Result = DrvFuncs->MessageAck(FirstDev->DriverData, FS_DEV_OUT_ACK_ENUM);
   }
   /* ConfigExt - 5 NO such action, bye */
   else
   {
      Result = RTF_PARAM_ERROR;
   }

   SafeUnlock(MT_LOCK_FMT);

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_CONFIGEXTDEVICE_E, Result, NULL);

   return Result;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides facility for user to check drive
      !! Function prototype rewritten since W06.13 !!
PARAMETER
      DriveIdx: The drive index ('Z' or 0x43, 0x44, ...etc.)
      CheckBuffer: The buffer get from caller
      CheckBufferLength: The buffer length, must > 2048
RETURN
      Success: RTF_NO_ERROR
      Error:   MT_FAIL_GET_MEM
               RTF_DRIVE_NOT_FOUND
               RTF_WRITE_PROTECTION
               RTF_INVALID_FILE_SYSTEM
               RTF_ACCESS_DENIED
               MT_ABORTED_ERROR
NOTE
      1. Recommand Check Buffer Size : 128MB Disk Size ===>  8KB
                                     for 1GB Size Disk ===> 32KB
 ------------------------------------------------------------------------------- */
#ifdef __FS_CHECKDRIVE_SUPPORT__

int FS_CheckDrive(const kal_uint32 DriveLetter, kal_uint8 * CheckBuffer, const kal_uint32 CheckBufferSize)
{
   #if !defined(__FS_PROPRIETARY_SET__)

   int Result = RTF_NO_ERROR;
   RTFDrive *Drive;

   fs_util_trace_info4(TRACE_FUNC, FS_API_FS_CHECKDRIVE_S, DriveLetter, (kal_uint32)CheckBuffer, CheckBufferSize, NULL, NULL);

   /* FS_CheckDrive - 1a , RAM Parameter Check */
   if(CheckBuffer == NULL || CheckBufferSize <= 2)
   {
      Result = MT_FAIL_GET_MEM;
      goto CheckDiskReturn;
   }

   /* FS_CheckDrive - 1b , DriveLetter Parameter Check */
   Drive = (RTFDrive*)fs_conf_get_drv_struct_by_drv_letter((WCHAR)DriveLetter);

   if (NULL == Drive)
   {
      Result = RTF_DRIVE_NOT_FOUND;
      goto CheckDiskReturn;
   }

   /* FS_CheckDrive - 1c , Drive Status, Access Check */
   if (Drive->Dev->DeviceFlags & MT_DEVICE_WRITE_PROTECT)
   {
      Result = RTF_WRITE_PROTECTION;
      goto CheckDiskReturn;
   }
   else if (Drive->MountState != HasFileSystem || Drive->Dev->DevData.MountState < HasFileSystem)
   {
      Result = RTF_INVALID_FILE_SYSTEM;
      goto CheckDiskReturn;
   }

   /* FS_CheckDrive - 2a , Retrieve FMT Lock and Raise Busy State */
   if(MTFMLock == NULL)
      MTFMLock = RTFSYSAllocMutex("MTFMLock");

   SafeLock(MT_LOCK_FMT, NULL, RTF_INFINITE);
   MTFMLock->DeviceNum_1 = Drive->Dev->DeviceNumber;

   /* FS_CheckDrive - 2b , Erect Flag of CHECKDRIVE */
   g_CheckDrive = KAL_TRUE;

   /* FS_CheckDrive - 2c , Do Job of CHECKDRIVE */
   Result = ScanDrive(Drive, (void *)CheckBuffer, CheckBufferSize);

   /* FS_CheckDrive - 2d , Clear flags and Busy State */
   if (g_CheckDrive == KAL_FALSE)
   {
      Result = MT_ABORTED_ERROR;
   }
   g_CheckDrive = KAL_FALSE;

   MTFMLock->DeviceNum_1 = 0;
   SafeUnlock(MT_LOCK_FMT);

   /* FS_CheckDrive - 3 , Clean Up */

CheckDiskReturn:

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_CHECKDRIVE_E, Result, NULL);

   fs_util_check_stack();

   return Result;

   #else    // __FS_PROPRIETARY_SET__

   return FS_NO_ERROR;

   #endif   // !__FS_PROPRIETARY_SET__
}

#endif  // __FS_CHECKDRIVE_SUPPORT__

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides facility for browsing type application to associate reusable value
      on the specific directory. Then get back the value or get miss error later.
PARAMETER
      FileHandle: The file handle that FS_FindXXX serious returned. or FS_Open() with OPEN_DIR flag
      NewValue: The new reusable value to be associated.
RETURN
      Success: RTF_NO_ERROR
      Error:   RTF_INVALID_FILE_HANDLE
               RTF_ACCESS_DENIED
NOTE
      This API available since 06A Branch
 ------------------------------------------------------------------------------- */

int FS_DirCtrl(FS_HANDLE handle, kal_uint32 action, void *data)
{
    RTFile * volatile   f = NULL;
    kal_uint32          dir_cluster;
    kal_int32           i = -1;

    fs_util_trace_info4(TRACE_FUNC, FS_API_FS_DIRCTRL_E, handle, action, (kal_uint32)data, NULL, NULL);

    XTRY
        case XCODE:

            f = ParseFileHandle(handle);

            dir_cluster = FIRST_FILE_CLUSTER(f->DirEntry.Dir);

            // set, get or expire
            if ((f->DirEntry.Dir.Attributes & RTF_ATTR_DIR) == 0)   // only folder is allowed
            {
                fs_util_trace_err_noinfo(FS_ACCESS_DENIED);

                XRAISE(FS_ACCESS_DENIED);
            }

            if (action & FS_DIRCTRL_DATA_SET)   // set
            {
                i = MTSetDirCacheValue(f->Drive, dir_cluster, (kal_uint32)data);
            }
            else if (action & FS_DIRCTRL_DATA_GET)  // get
            {
                i = MTGetDirCacheValue(f->Drive, dir_cluster, (kal_uint32*)data);
            }
            else if (action & FS_DIRCTRL_DATA_EXPIRE)   // expire
            {
                i = MTExpireDirCacheValue(f->Drive, dir_cluster);
            }

            // lock or unlock
            if (action & (FS_DIRCTRL_DATA_LOCK | FS_DIRCTRL_DATA_UNLOCK))
            {
                if (i == -1)    // if lock or unlock only, i is not assigned
                {
                    i = MTSearchDirData(f->Drive, dir_cluster);

                    if (i == -1)    // target is not found
                    {
                        fs_util_trace_err_noinfo(FS_DIRCACHE_EXPIRED);

                        XRAISE(FS_DIRCACHE_EXPIRED);
                    }
                }

                if (action & FS_DIRCTRL_DATA_LOCK)
                {
                    _gfs_dir_data[i].Status |= FS_DIRDATA_MASK_LOCKED;
                }
                else
                {
                    _gfs_dir_data[i].Status &= ~FS_DIRDATA_MASK_LOCKED;
                }
            }

        default:

            break;

        case XFINALLY:

            if (f != NULL)
            {
                UnlockDevice(f->Dev);
            }

            break;
    XEND_API

    return FS_NO_ERROR;
}

int FS_SetDirCache(FS_HANDLE FileHandle, kal_uint32 NewValue)
{
    return FS_DirCtrl(FileHandle, FS_DIRCTRL_DATA_SET, (void*)NewValue);
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides facility for browsing type application to associate reusable value
      on the specific directory. Then get back the value or get miss error later.
PARAMETER
      FileHandle: The file handle that FS_FindXXX serious returned. or FS_Open() with OPEN_DIR flag
      NewValue: The new reusable value to be associated.
RETURN
      Success: RTF_NO_ERROR
      Error:   RTF_INVALID_FILE_HANDLE
               RTF_ACCESS_DENIED
NOTE
      This API available since 06A Branch
 ------------------------------------------------------------------------------- */
int FS_GetDirCache(FS_HANDLE FileHandle, kal_uint32 *CurrValue)
{
    return FS_DirCtrl(FileHandle, FS_DIRCTRL_DATA_GET, CurrValue);
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides facility for browsing type application to associate reusable value
      on the specific directory. Then get back the value or get miss error later.
PARAMETER
      FileHandle: The file handle that FS_FindXXX serious returned. or FS_Open() with OPEN_DIR flag
RETURN
      Success: RTF_NO_ERROR
      Error:   RTF_INVALID_FILE_HANDLE
               RTF_ACCESS_DENIED
NOTE
      This API available since 06A Branch
 ------------------------------------------------------------------------------- */
int FS_ExpireDirCache(FS_HANDLE FileHandle)
{
    return FS_DirCtrl(FileHandle, FS_DIRCTRL_DATA_EXPIRE, NULL);
}

int FS_GetFolderSizeEx(const WCHAR *path, kal_uint32 flag, kal_uint8 *recursive_stack, const kal_uint32 stack_size, FS_ProgressCallback progress)
{
    int volatile Result = RTF_NO_ERROR;

    fs_util_trace_info4(TRACE_FUNC | MT_TRACE_INFO_WSTR, FS_API_FS_GETFOLDERSIZE_S, flag, (kal_uint32)recursive_stack, stack_size, NULL, (void*)path);

    /* GetFolderSize - 1 : Parameter Check */
    if((flag != FS_COUNT_IN_BYTE) && (flag != FS_COUNT_IN_CLUSTER))
    {
        fs_util_trace_err_noinfo(RTF_PARAM_ERROR);

        return RTF_PARAM_ERROR;
    }

    if ( MT_MAXPATH_IN_WCHAR_UNIT <= kal_wstrlen(path) )
    {
        Result = MT_PATH_OVER_LEN_ERROR;
    }
    else
    {
        Result = RecAUX_IsFolder(path);
    }

    if (Result < RTF_NO_ERROR)
    {
        fs_util_trace_err_noinfo(Result);

        return Result;
    }

    /* GetFolderSize - 2 : Action */
    fs_init();

    if(MTXLock == NULL)
        MTXLock = RTFSYSAllocMutex("MTXLock");

    SafeLock(MT_LOCK_EXT, NULL, RTF_INFINITE);
    MTXLock->DeviceNum_1 = FindDeviceNumberByDriveIdx((int)path[0]);
    Result = RecAUX_CountSumOfSizeUnderFolderTree(path, flag, recursive_stack, stack_size, progress);
    MTXLock->DeviceNum_1 = 0;
    SafeUnlock(MT_LOCK_EXT);

    fs_util_trace_info1(TRACE_FUNC, FS_API_FS_GETFOLDERSIZE_E, Result, NULL);

    fs_util_check_stack();

    return Result;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides a facility to get folder size
PARAMETER
      DirName        : Full source path to be counted
      Flag           : FS_COUNT_IN_BYTE, FS_COUNT_IN_CLUSTER
      RecursiveStack : A memory pointer to store deep folder hierarchy recrusive data
      StackSize      : The size of RecursiveStack
RETURN
      >0       : Size in byte or cluster
      Error    : RTF_PATH_NOT_FOUND, RTF_PARAM_ERROR
NOTE
      1. The size here counts for FAT allocation, not only data setctor allocation
      2. This API leverage the Recursive Class
------------------------------------------------------------------------------- */
int FS_GetFolderSize(const WCHAR * FullPath, kal_uint32 Flag, kal_uint8 *RecursiveStack, const kal_uint32 StackSize)
{
   return FS_GetFolderSizeEx(FullPath, Flag, RecursiveStack, StackSize, NULL);
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides facility to get the first cluster (unique file/folder
      information in a drive).
PARAMETER
      FileHandle: User provides specified file handle
      Cluster:    The first cluster number to return
RETURN
      Success:    RTF_NO_ERROR
      Error:      RTF_INVALID_FILE_HANDLE
                  RTF_DATA_ERROR
NOTE
      If the file or folder does not have any content (first cluster is zero),
      you will get RTF_DATA_ERROR
------------------------------------------------------------------------------- */
int FS_GetFirstCluster(FS_HANDLE FileHandle, kal_uint32 * Cluster)
{
   int Result;

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_GETFIRSTCLUSTER_S, FileHandle, NULL);

   Result = GetFirstClusterByFileHandle(FileHandle, Cluster);
   if (Result == RTF_NO_ERROR && *Cluster == 0)
   {
      fs_util_trace_err_noinfo(RTF_DATA_ERROR);

      return RTF_DATA_ERROR;
   }

   if (Result < RTF_NO_ERROR)
   {
      *Cluster = 0;
   }

   fs_util_trace_info2(TRACE_FUNC, FS_API_FS_GETFIRSTCLUSTER_E, Result, *Cluster, NULL);

   return Result;
}

/*************************************************************************
* FUNCTION
*    FS_OTPRead
*
* DESCRIPTION
*    This function implements the OTP read function, first it enter
*    secured silicon sector, and read data from "Offset", totally read
*    "Length" bytes, then exit secured silicon sector mode
*
* PARAMETERS
*    Offset: the start position want to read (unit:bytes)
*    BufferPtr: the buffer address want to read to
*    Length: total length want to read (unit: bytes)
*
* RETURNS
*   FS_NO_ERROR: no error
*   FS_UNSUPPORTED_DEVICE: no OTP device configured
*   FS_UNSUPPORTED_DRIVER_FUNCTION: no OTP function support on configured device
*   FS_FLASH_OTP_OVERSCOPE: reading range is out of OTP range
*
*************************************************************************/
int FS_OTPRead(int devtype, kal_uint32 Offset, void * BufferPtr, kal_uint32 Length)
{
    RTFDevice * Dev;
    static int last_errcode;

    fs_util_trace_info4(TRACE_FUNC, FS_API_FS_OTPREAD_S, devtype, Offset, (kal_uint32)BufferPtr, Length, NULL);

    /* OTP_Read - 1 : Find the Device */
    if (devtype == FS_DEVICE_TYPE_UNKNOWN)  // find default device (used by FS) if user does not specify device type
    {
        devtype = (int)fs_conf_get_default_devtype();
    }

    Dev = (RTFDevice*)fs_conf_find_dev_by_devtype((FS_DEVICE_TYPE_ENUM)devtype, 1);

    if (Dev == NULL)
    {
        return FS_UNSUPPORTED_DEVICE;
    }

    /* OTP_Read - 2 : Lock Device for concurrency */
    SafeLock(MT_LOCK_DEV, Dev, RTF_INFINITE);

    /* OTP_Read - 3 : Perform IO operation */
    if (Dev->Driver->OTPAccess && Dev->Driver->OTPQueryLength)
    {
        last_errcode = Dev->Driver->OTPAccess(Dev->DriverData, FS_OTP_READ, Offset, BufferPtr, Length);
    }
    else
    {
        last_errcode = FS_UNSUPPORTED_DRIVER_FUNCTION;
    }

    /* OTP_Read - 4 : Free Device for concurrency */
    SafeUnlock(MT_LOCK_DEV);

    fs_util_trace_info1(TRACE_FUNC, FS_API_FS_OTPREAD_E, last_errcode, NULL);

    return last_errcode;
}

/*************************************************************************
* FUNCTION
*    FS_OTPWrite
*
* DESCRIPTION
*    This function implements the OTP write function, first it enter
*    secured silicon sector, and write data from "Offset", totally write
*    "Length" bytes, then exit secured silicon sector mode.
*    Be carefully, do not set bit to one if it is zero
*
* PARAMETERS
*    Offset: the start position want to write (unit:bytes)
*    BufferPtr: the buffer address want to write from
*    Length: total length want to write (unit: bytes)
*
* RETURNS
*   FS_NO_ERROR: no error
*   FS_UNSUPPORTED_DEVICE: no OTP device configured
*   FS_UNSUPPORTED_DRIVER_FUNCTION: no OTP function support on configured device
*   FS_FLASH_OTP_OVERSCOPE: reading range is out of OTP range
*   FS_FLASH_OTP_WRITEFAIL: program error occur
*   FS_FLASH_OTP_LOCK_ALREADY: OTP area is already locked
*
*************************************************************************/
int FS_OTPWrite(int devtype, kal_uint32 Offset, void * BufferPtr, kal_uint32 Length)
{
    RTFDevice * Dev;
    static int last_errcode;

    fs_util_trace_info4(TRACE_FUNC, FS_API_FS_OTPWRITE_S, devtype, Offset, (kal_uint32)BufferPtr, Length, NULL);

    /* OTP_Write - 1 : Find the Device */
    if (devtype == FS_DEVICE_TYPE_UNKNOWN)  // find default device (used by FS) if user does not specify device type
    {
        devtype = (int)fs_conf_get_default_devtype();
    }

    Dev = (RTFDevice*)fs_conf_find_dev_by_devtype((FS_DEVICE_TYPE_ENUM)devtype, 1);

    if (Dev == NULL)
    {
        return FS_UNSUPPORTED_DEVICE;
    }

    /* OTP_Write - 2 : Lock Device for concurrency */
    SafeLock(MT_LOCK_DEV, Dev, RTF_INFINITE);

    /* OTP_Write - 3 : Perform IO operation */
    if (Dev->Driver->OTPAccess && Dev->Driver->OTPQueryLength)
    {
        last_errcode = Dev->Driver->OTPAccess(Dev->DriverData, FS_OTP_WRITE, Offset, BufferPtr, Length);
    }
    else
    {
        last_errcode = FS_UNSUPPORTED_DRIVER_FUNCTION;
    }

    /* OTP_Write - 4 : Free Device for concurrency */
    SafeUnlock(MT_LOCK_DEV);

    fs_util_trace_info1(TRACE_FUNC, FS_API_FS_OTPWRITE_E, last_errcode, NULL);

    return last_errcode;
}

/*************************************************************************
* FUNCTION
*    FS_OTPLcok
*
* DESCRIPTION
*    This function implements the OTP lock function,
*
* PARAMETERS
*
* RETURNS
*   FS_NO_ERROR: no error
*   FS_FLASH_OTP_LOCK_ALREADY: OTP area is already locked
*
*************************************************************************/
int FS_OTPLock(int devtype)
{
    RTFDevice * Dev;
    static int last_errcode;

    fs_util_trace_info1(TRACE_FUNC, FS_API_FS_OTPLOCK_S, devtype, NULL);

    /* OTP_Lock - 1 : Find the Device */
    if (devtype == FS_DEVICE_TYPE_UNKNOWN)  // find default device (used by FS) if user does not specify device type
    {
        devtype = (int)fs_conf_get_default_devtype();
    }

    Dev = (RTFDevice*)fs_conf_find_dev_by_devtype((FS_DEVICE_TYPE_ENUM)devtype, 1);

    if (Dev == NULL)
    {
        return FS_UNSUPPORTED_DEVICE;
    }

    /* OTP_Lock - 2 : Lock Device for concurrency */
    SafeLock(MT_LOCK_DEV, Dev, RTF_INFINITE);

    /* OTP_Lock - 3 : Perform IO operation */
    if (Dev->Driver->OTPAccess && Dev->Driver->OTPQueryLength)
    {
        last_errcode = Dev->Driver->OTPAccess(Dev->DriverData, FS_OTP_LOCK, 0, NULL, 0);
    }
    else
    {
        last_errcode = FS_UNSUPPORTED_DRIVER_FUNCTION;
    }

    /* OTP_Lock - 4 : Free Device for concurrency */
    SafeUnlock(MT_LOCK_DEV);

    fs_util_trace_info1(TRACE_FUNC, FS_API_FS_OTPLOCK_E, last_errcode, NULL);

    return last_errcode;
}

/*************************************************************************
* FUNCTION
*    FS_OTPQueryLength
*
* DESCRIPTION
*    This function implements the OTP length query function,
*
* PARAMETERS
*    Length: total length pointer to be get (unit: byte)
*
* RETURNS
*   FS_NO_ERROR: no error
*   FS_UNSUPPORTED_DEVICE: no OTP device configured
*   FS_UNSUPPORTED_DRIVER_FUNCTION: no OTP function support on configured device
*
*************************************************************************/
int FS_OTPQueryLength(int devtype, kal_uint32 *Length)
{
    RTFDevice * Dev;
    int       Result = FS_NO_ERROR;

    fs_util_trace_info1(TRACE_FUNC, FS_API_FS_OTPQUERYLENGTH_S, devtype, NULL);

    /* OTP_QueryLength - 1 : Find the Device */
    if (devtype == FS_DEVICE_TYPE_UNKNOWN)  // find default device (used by FS) if user does not specify device type
    {
        devtype = (int)fs_conf_get_default_devtype();
    }

    Dev = (RTFDevice*)fs_conf_find_dev_by_devtype((FS_DEVICE_TYPE_ENUM)devtype, 1);

    if (Dev == NULL)
    {
        Result = FS_UNSUPPORTED_DEVICE;
    }
    else
    {
        /* OTP_QueryLength - 2 : Check IO operation */
        if (Dev->Driver->OTPAccess && Dev->Driver->OTPQueryLength)
        {
            Result = Dev->Driver->OTPQueryLength(Dev->DriverData, Length);
        }
        else
        {
            Result = FS_UNSUPPORTED_DRIVER_FUNCTION;
        }
    }

    fs_util_trace_info1(TRACE_FUNC, FS_API_FS_OTPQUERYLENGTH_E, Result, NULL);

    return Result;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides facility for user to reclaim flash disk,
      piece by piece!!
PARAMETER
      DriveType: The DeviceType , NOR, NAND, ...
RETURN
      Success: RTF_NO_ERROR
      Retry:   RTF_CHECKDISK_RETRY
      Error:   RTF_PARAM_ERROR
NOTE
 ------------------------------------------------------------------------------- */
int FS_SweepDevice(const int DeviceType)
{
   static kal_uint32 LastDeviceType = 0xffffffff;
   static RTFDrive *LastDrive = NULL;
   static RTFCluster LastCluster;
   RTFDevice *Dev;
   int Result = RTF_NO_ERROR;

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_SWEEPDEVICE_S, DeviceType, NULL);

   /* FS_SweepDrive - 1 , Check if the state hold */
   if (LastDeviceType != DeviceType)
   {
      Dev = (RTFDevice*)fs_conf_find_dev_by_devtype((FS_DEVICE_TYPE_ENUM)DeviceType, 1);

      if (Dev == NULL)
      {
         return RTF_PARAM_ERROR;
      }

      LastDeviceType = DeviceType;
      LastDrive      = Dev->DevData.FirstDrive;
      LastCluster    = 2;
   }

   /* FS_SweepDrive - 2 , Call the routine to discard sector piece by piece */
   SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, LastDrive->Dev, RTF_INFINITE);
   Result = CleanUpDataSectors(LastDrive, &LastCluster, 128);
   SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV);

   /* FS_SweepDrive - 3 , Return Continue/Stop indication */
   if (Result < 0 && LastCluster >= LastDrive->Clusters)
   {
      Dev = (RTFDevice*)fs_conf_find_dev_by_devtype((FS_DEVICE_TYPE_ENUM)DeviceType, 1); /* Need to reterive again */

      if (LastDrive->NextDrive != NULL)
      {
         LastDrive   = LastDrive->NextDrive;
         LastCluster = 2;
      }
      else
      {
         fs_util_trace_info0(TRACE_FUNC, FS_API_FS_SWEEPDEVICE_E_DONE, NULL);

         return RTF_NO_ERROR;
      }
   }

   fs_util_trace_info0(TRACE_FUNC, FS_API_FS_SWEEPDEVICE_E_RETRY, NULL);

   fs_util_check_stack();

   return RTF_CHECKDISK_RETRY;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provide various kinds of query about number of file handles
PARAMETER
      flag:  FS_FH_COUNT_CONFIGURED,
             FS_FH_COUNT_USED,
             FS_FH_COUNT_AVAILABLE,
             FS_FH_COUNT_CURRENT_TASK
RETURN
      >= 0: the number of file handles.
      Error:   RTF_PARAM_ERROR

------------------------------------------------------------------------------- */
int FS_CountUsedFH(int flag)
{
   int Result;

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_COUNTUSEDFH_S, flag, NULL);

   switch (flag)
   {
      case FS_FH_COUNT_CURRENT_TASK:
         Result = CountUsedFH(kal_get_current_thread_ID());
         break;

      case FS_FH_COUNT_AVAILABLE:
         Result = FS_MAX_FILES - CountUsedFH(NULL);
         break;

      case FS_FH_COUNT_USED:
         Result = CountUsedFH(NULL);
         break;

      case FS_FH_COUNT_CONFIGURED:
         Result = FS_MAX_FILES;
         break;

      default:
         Result = FS_PARAM_ERROR;
         break;
   }

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_COUNTUSEDFH_E, Result, NULL);

   fs_util_check_stack();

   return Result;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides facility to force mount the removable device
PARAMETER
      None
RETURN
      Success: RTF_NO_ERROR
      Error:
NOTE
 ------------------------------------------------------------------------------- */
int FS_MountRemovableDevice(void)
{
    FS_Device *device;

    device = fs_conf_find_dev_by_devtype(FS_DEVICE_TYPE_CARD, 1);

    if (device != NULL)
    {
       return MountRemovableDevice((RTFDevice*)device);
    }

    return FS_UNSUPPORTED_DEVICE;
}


/* -------------------------------------------------------------------------------
DESCRIPTION
      This function provides facility for user to recover flash disk,
PARAMETER
      DriveType: The DeviceType , NOR, NAND, ...
RETURN
      Success: RTF_NO_ERROR
      Error:   RTF_PARAM_ERROR
NOTE
 ------------------------------------------------------------------------------- */
int FS_RecoverDevice(const int DeviceType)
{
   RTFDevice *Dev;
   RTFDrive  *Drive;
   int Result = RTF_NO_ERROR;

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_RECOVERDEVICE_S, DeviceType, NULL);

   /* FS_RecoverDevice - 1 , Get the device */
   Dev = (RTFDevice*)fs_conf_find_dev_by_devtype((FS_DEVICE_TYPE_ENUM)DeviceType, 1);
   if (Dev == NULL)
   {
      fs_util_trace_err_noinfo(FS_PARAM_ERROR);

      return FS_PARAM_ERROR;
   }

   /* FS_RecoverDevice - 2 , see if function supported */
   if (Dev->DeviceFlags & FS_DEVICE_REMOVABLE)
   {
      fs_util_trace_err_noinfo(FS_UNSUPPORTED_DEVICE);

      return FS_UNSUPPORTED_DEVICE;
   }

   if (Dev->Driver->RecoverDisk == NULL)
   {
      fs_util_trace_err_noinfo(FS_UNSUPPORTED_DRIVER_FUNCTION);

      return FS_UNSUPPORTED_DRIVER_FUNCTION;
   }

   /* FS_RecoverDevice - 3 , do it and unmount all associated drive and the device */
   SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Dev, RTF_INFINITE);

   Result = Dev->Driver->RecoverDisk(Dev->DriverData);

   for ( Drive = Dev->DevData.FirstDrive; Drive != NULL; Drive = Drive->NextDrive)
   {
      Drive->MountState = NotMounted;
   }

   Dev->DevData.MountState = NotMounted;
   SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV);

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_RECOVERDEVICE_E, Result, NULL);

   return Result;
}

/* -------------------------------------------------------------------------------
DESCRIPTION
      This function is used to set the drive labe.
PARAMETER
      DriveName: The drive name
      Label: The Label to be set.
RETURN
      Success: RTF_NO_ERROR
      Error:   RTF_PARAM_ERROR
NOTE
 ------------------------------------------------------------------------------- */
int FS_SetVolumeLabel(const WCHAR * DriveName, const WCHAR * Label)
{
   #if !defined(__FS_SLIM_VOLUME_LABEL__)

   int Result;

   fs_util_trace_info1(TRACE_FUNC | MT_TRACE_INFO_WSTR, FS_API_FS_SETVOLUMELABEL_S, *(kal_uint8*)DriveName, (void*)Label);

   Result = RTFSetVolumeLabel(DriveName, Label);

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_SETVOLUMELABEL_E, Result, NULL);

   fs_util_check_stack();

   return Result;

   #else

   return FS_ERR_UNSUPPORTED_SERVICE;

   #endif
}

/* ------------------------------------------------------------------------------- */
int FS_RemoveDir(const WCHAR * DirName)
{
   int Result = RTF_NO_ERROR;

   fs_util_trace_info0(TRACE_FUNC | MT_TRACE_INFO_WSTR, FS_API_FS_REMOVEDIR_S, (void*)DirName);

   Result = RTFRemoveDir(DirName);

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_REMOVEDIR_E, Result, NULL);

   fs_util_check_stack();

   return Result;
}

/* ------------------------------------------------------------------------------- */
int FS_SetAttributes(const WCHAR * FileName, kal_uint8 Attributes)
{
   int Result = RTF_NO_ERROR;

   fs_util_trace_info1(TRACE_FUNC | MT_TRACE_INFO_WSTR, FS_API_FS_SETATTRIBUTES_S, Attributes, (void*)FileName);

   Result = RTFSetAttributes(FileName, Attributes);

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_SETATTRIBUTES_E, Result, NULL);

   fs_util_check_stack();

   return Result;
}

#if defined(__FS_IO_STATISTICS__)

kal_uint32           gFS_TaskIOStatisticsUser=0;
FS_TaskIOStatistics *gFS_TaskIOStatistics=NULL;

/* ------------------------------------------------------------------------------- */
static kal_uint32 fs_util_diff(kal_uint32 base, kal_uint32 value)
{
    if (value>base) return (value-base);
    else return (base-value);
}

/* ------------------------------------------------------------------------------- */
int FS_StartIOLog(FS_TaskIOStatistics *Statistics)
{
    kal_uint32 size=FS_GetIOStatisticsSize();
    kal_int32  result=FS_NO_ERROR;

    fs_util_trace_info1(TRACE_FUNC, FS_API_FS_STARTIOLOG_S, Statistics, NULL);

    if (Statistics==NULL) {
        result=FS_PARAM_ERROR;
    }
    else {
        RTFSYSLockMutex(RTFLock, RTF_INFINITE);

        if (gFS_TaskIOStatistics==NULL) {
            gFS_TaskIOStatistics=(FS_TaskIOStatistics*)get_ctrl_buffer(size);
            gFS_TaskIOStatisticsUser=0;
            kal_mem_set(gFS_TaskIOStatistics, 0, size);
        }

        gFS_TaskIOStatisticsUser++;

        kal_mem_set(Statistics, 0, size);
        kal_mem_cpy(Statistics, gFS_TaskIOStatistics, size);

        fs_util_trace_info0(TRACE_ERROR, FS_INFO_IO_STAT_START, NULL);
        RTFSYSFreeMutex(RTFLock);
    }

    fs_util_trace_info1(TRACE_FUNC, FS_API_FS_STARTIOLOG_E, result, NULL);

    return result;
}

/* ------------------------------------------------------------------------------- */
int FS_EndIOLog(FS_TaskIOStatistics *Statistics)
{
    kal_int32 task_index;
    kal_int32 thread_count;
    kal_int32 result=FS_NO_ERROR;

    fs_util_trace_info1(TRACE_FUNC, FS_API_FS_ENDIOLOG_S, Statistics, NULL);

    if (Statistics==NULL) {
        result=FS_PARAM_ERROR;
    }
    else {
        thread_count=RTFSYSGetThreadCount();

        RTFSYSLockMutex(RTFLock, RTF_INFINITE);

        if (gFS_TaskIOStatisticsUser>0) {
            for (task_index=0; task_index<thread_count; task_index++)    {
                Statistics[task_index].AccessTime =
                    fs_util_diff(Statistics[task_index].AccessTime, gFS_TaskIOStatistics[task_index].AccessTime);
                Statistics[task_index].AccessCount =
                    fs_util_diff(Statistics[task_index].AccessCount, gFS_TaskIOStatistics[task_index].AccessCount);
                Statistics[task_index].SectorCount =
                    fs_util_diff(Statistics[task_index].SectorCount, gFS_TaskIOStatistics[task_index].SectorCount);
            }

            #if defined(__TST_TRACE_ENABLED__)
            result=fs_util_trace_io_statistics(kal_trace, TRACE_ERROR, Statistics);
            #else
            result=fs_util_trace_io_statistics(NULL, TRACE_ERROR, Statistics);
            #endif

            gFS_TaskIOStatisticsUser--;

            if (gFS_TaskIOStatisticsUser==0)    {
                free_ctrl_buffer(gFS_TaskIOStatistics);
                gFS_TaskIOStatistics=NULL;
            }
        }

        RTFSYSFreeMutex(RTFLock);
    }

    fs_util_trace_info1(TRACE_FUNC, FS_API_FS_ENDIOLOG_E, result, NULL);

    return result;
}

#else

int FS_StartIOLog(FS_TaskIOStatistics *Statistics)
{
    fs_util_trace_info1(TRACE_FUNC, FS_API_FS_STARTIOLOG_S, Statistics, NULL);
    fs_util_trace_info0(TRACE_ERROR, FS_INFO_IO_STAT_DISABLE, NULL);
    return FS_NO_ERROR;
}
int FS_EndIOLog(FS_TaskIOStatistics *Statistics)
{
    fs_util_trace_info1(TRACE_FUNC, FS_API_FS_ENDIOLOG_S, Statistics, NULL);
    fs_util_trace_info0(TRACE_ERROR, FS_INFO_IO_STAT_DISABLE, NULL);
    return FS_NO_ERROR;
}

#endif // __FS_IO_STATISTICS__

int FS_OpenFileByHint(WCHAR DriveLetter, kal_uint32 DirCluster, kal_uint32 DirIndex, kal_uint32 Flags)
{
   int result;
   kal_uint32 lr;
   FS_GET_RETURN_ADDRESS(lr);

   fs_util_trace_info5ex(TRACE_FUNC, FS_API_FS_OPENFILEPATHBYHINT_S, lr, DriveLetter, DirCluster, DirIndex, Flags, NULL);

#if !defined(__MTK_TARGET__)
       Flags &= ~FS_PROTECTION_MODE;
#endif

   result = RTFOpenFileByHint(DriveLetter, DirCluster, DirIndex, Flags, lr);

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_OPENFILEPATHBYHINT_E, result, NULL);

   return result;
}

#if defined(__MTP_ENABLE__)

int FS_MakeFilePathByHint(WCHAR DriveLetter, kal_uint32 DirCluster, kal_uint32 DirIndex, WCHAR * FileName, kal_uint32 MaxLength)
{
   int result;

   fs_util_trace_info4(TRACE_FUNC, FS_API_FS_MAKEFILEPATHBYHINT_S, DriveLetter, DirCluster, DirIndex, MaxLength, NULL);

   result = RTFMakeFilePathByHint(DriveLetter, DirCluster, DirIndex, FileName, MaxLength);

   fs_util_trace_info1(TRACE_FUNC | MT_TRACE_INFO_WSTR, FS_API_FS_MAKEFILEPATHBYHINT_E, result, (void*)FileName);

   return result;
}

int FS_DeleteByHint(WCHAR DriveLetter, kal_uint32 DirCluster, kal_uint32 DirIndex)
{
   int result;

   fs_util_trace_info4(TRACE_FUNC, FS_API_FS_DELETEBYHINT_S, DriveLetter, DirCluster, DirIndex, NULL, NULL);

   result = RTFDeleteByHint(DriveLetter, DirCluster, DirIndex);

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_DELETEBYHINT_E, result, NULL);

   return result;
}

int FS_GetAttributesByHint(WCHAR DriveLetter, kal_uint32 DirCluster, kal_uint32 DirIndex)
{
   int result;

   fs_util_trace_info4(TRACE_FUNC, FS_API_FS_GETATTRIBUTESBYHINT_S, DriveLetter, DirCluster, DirIndex, NULL, NULL);

   result = RTFGetAttributesByHint(DriveLetter, DirCluster, DirIndex);

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_GETATTRIBUTESBYHINT_E, result, NULL);

   return result;
}

int FS_SetAttributesByHint(WCHAR DriveLetter, kal_uint32 DirCluster, kal_uint32 DirIndex, kal_uint8 Attributes)
{
   int result;

   fs_util_trace_info4(TRACE_FUNC, FS_API_FS_SETATTRIBUTESBYHINT_S, DriveLetter, DirCluster, DirIndex, Attributes, NULL);

   result = RTFSetAttributesByHint(DriveLetter, DirCluster, DirIndex, Attributes);

   fs_util_trace_info1(TRACE_FUNC, FS_API_FS_SETATTRIBUTESBYHINT_E, result, NULL);

   return result;
}

int FS_HintGetParent(WCHAR DriveLetter, kal_uint32 DirCluster, kal_uint32 DirIndex, kal_uint32 *ParentCluster, kal_uint32 *ParentIndex)
{
   int result;

   fs_util_trace_info4(TRACE_FUNC, FS_API_FS_HINTGETPARENT_S, DriveLetter, DirCluster, DirIndex, NULL, NULL);

   result = RTFHintGetParent(DriveLetter, DirCluster, DirIndex, ParentCluster, ParentIndex);

   fs_util_trace_info4(TRACE_FUNC, FS_API_FS_HINTGETPARENT_E, result, *ParentCluster, *ParentIndex, NULL, NULL);

   return result;
}

#endif // __MTP_ENABLE__

#endif // __MODEM_CCCI_EXIST__
