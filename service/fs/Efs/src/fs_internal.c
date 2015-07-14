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
 *     fs_internal.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *    This file defines the internals of file system abstraction layer
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
#include "kal_public_api.h"
#include "fs_internal_def.h"
#include "fs_gprot.h"
#include "rtfiles.h"
#include "rtfex.h"
#include "rtfbuf.h"
#include "fs_kal.h"
#include "fs_internal.h"
#include "fs_internal_api.h"
#include "kal_trace.h"
#include "fs_utility.h"
#include "fs_trc.h"  // "stack_config.h" is included by "kal_release.h"
#include "setjmp.h"
#include "string.h"

/************************* Internal Use *************************/
// FS trace
#define fs_util_trace_err_noinfo(error_code) fs_util_trace_err_slim(error_code, fs_internal_c, __LINE__)


// Assert
#define fs_assert_local(expr) fs_assert(expr, fs_internal_c)
#define fs_ext_assert_local(expr, e1, e2, e3) fs_ext_assert(expr, fs_internal_c, e1, e2, e3)

//Global Data
#ifdef __FS_CHECKDRIVE_SUPPORT__
kal_bool g_CheckDrive = KAL_FALSE;
#endif

// External & Dynamic Device
kal_bool g_ExternalDevice = KAL_FALSE; // init as not configured

// Abort Mechanism
kal_bool  g_Xdelete   = KAL_TRUE; //must be init with true

//Outside Function
extern void nvram_space_reserve(kal_uint32 *size_from_code);
extern void nvram_get_folder_name(WCHAR *nvram_folder_name);
extern int Check_NORFlash_Formatted(void);

#ifdef __FS_QM_SUPPORT__
static int FolderInQuotaSet(WCHAR * Folder);
#endif

#ifdef __FS_CHECKDRIVE_SUPPORT__
static int        ScanFindFirst(WCHAR * NamePattern, RTFDirEntry * DirPos);
static int        ScanFindNext(RTFHANDLE Handle, WCHAR * FileName, RTFDirEntry * DirPos);
static void       ScanFATDelete(InternScanDataStruct *SDCD, RTFCluster Cluster);
#endif

#ifdef __P_PROPRIETARY_COPYRIGHT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/* ---------------------------------------------------------------------------------- */
/* Conventions For Source Code Maintain in fs_internal.c                              */
/* > *Must* put FS Trace Log with XRAISE error in rtfiles.c and fs_func.c             */
/*   however, sub-routines here usually are middleware between rtfiles and fs_func    */
/*   you may skip FS Trace if the XRAISE doesn't need log                             */
/* ---------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------- */
/* Retrieve the system time
 */
static kal_uint32 GetTime(void)
{
    kal_uint32 time;

    time=kal_get_systicks();
    return time;
}

/* ------------------------------------------------------------------------------- */
/* Close all files on this device and then discard all related buffer */
void CloseDevice(RTFDevice * Dev)
{
   int i;
   RTFile * f;

   if(Dev == NULL) return;
   //Lock RTF and device before calling this function
   FlushAllBuffers(Dev);
   DiscardAllBuffers(Dev);

   for (i=0, f = gFS_Data.FileTable; i<FS_MAX_FILES; i++, f++)
   {
      if ((f->Lock != 0) && (f->Dev == Dev))
      {
         //don't call RTFClose here cuz it will unmount device
         FreeFTSlot(f);
      }
   }
   //should not unlock here
}
/* ------------------------------------------------------------------------------- */
/* Lookup device number by DriveLetter , 0 if not found */
int FindDeviceNumberByDriveIdx(int DriveLetter)
{
   RTFDrive *Drive = NULL;

   Drive = (RTFDrive*)fs_conf_get_drv_struct_by_drv_letter(DriveLetter);

   if (NULL != Drive)
   {
      if (Drive->Dev != NULL)
      {
         return Drive->Dev->DeviceNumber;
      }
   }

   return 0;
}
/* ------------------------------------------------------------------------------- */
/* Lookup device type by translate to flag query */
RTFDevice * FindFirstDeviceByType(FS_DEVICE_TYPE_ENUM dtype)
{
   UINT match;
   RTFDevice * Dev = gFS_DeviceList;

   switch(dtype)
   {
      case FS_DEVICE_TYPE_NOR:
         match = MT_DEVICE_NOR_FLASH;
         break;

      case FS_DEVICE_TYPE_NAND:
         match = MT_DEVICE_NAND_FLASH;
         break;

      case FS_DEVICE_TYPE_EXTERNAL:
         match = MT_DEVICE_EXTERNAL;
         break;

      case FS_DEVICE_TYPE_CARD:
         match = RTF_DEVICE_REMOVABLE;
         break;

      case FS_DEVICE_TYPE_SIMPLUS:
         match = MT_DEVICE_SIMPLUS;
         break;

      default: /* WRONG PARAMETER */
         return NULL;
   }

   for (; Dev->DeviceType; Dev++)
   {
      if (Dev->DeviceFlags & match)
      {
         return Dev;
      }
   }
   return NULL;
}

/* ------------------------------------------------------------------------------- */
/* Mount Drive and Issue BatchCountFreeClusters on the Fixed Device Again
 * NOTE: This sub-routine DO NOT check argument, use it careful!!
 */
int ReMountDriveAndCountFreeClusters(RTFDrive *Drive)
{
   int Result = RTF_NO_ERROR;

   fs_assert_local(Drive != NULL);

   XTRY
      case XCODE:
         SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Drive->Dev, RTF_INFINITE);
         DiscardAllBuffers(Drive->Dev);
         MountLogicalDrive(Drive, HasFileSystem);
         BatchCountFreeClusters(Drive);
         break;
      default:
         Result = XVALUE; //API dose not need XHANDLED
         break;
      case XFINALLY:
         SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV);
         break;
   XEND_API
   return Result;
}

/* ------------------------------------------------------------------------------- */
int ReleaseFH(void * TaskId)
{
   RTFile * f;
   UINT i;

   RTFSYSLockMutex(RTFLock, RTF_INFINITE);

   for (i=0, f = gFS_Data.FileTable; i<FS_MAX_FILES; i++, f++)
   {
      if (TaskId)
      {
         if (f->Task == TaskId)
            FreeFTSlot(f);
      }
      else if ((f->Task == kal_get_current_thread_ID()) && (f->Task != NULL))
      {
         FreeFTSlot(f);
      }
   }

   RTFSYSFreeMutex(RTFLock);
   return RTF_NO_ERROR;
}

/* ------------------------------------------------------------------------------- */
int CountUsedFH(void * TaskId)
{
   RTFile * f;
   UINT i;
   int  Result=0;

   RTFSYSLockMutex(RTFLock, RTF_INFINITE);

   for (i=0, f = gFS_Data.FileTable; i<FS_MAX_FILES; i++, f++)
   {
      if (TaskId)
      {
         if (f->Task == TaskId) Result++;
      }
      else if (f->Unique)
      {
         Result++;
      }
   }

   RTFSYSFreeMutex(RTFLock);
   return Result;
}
/* ------------------------------------------------------------------------------- */
/* Copy file to file, this function get at least 512B mem */
static int CopyFileSyncLastDateTime(RTFHANDLE FileSrc, RTFHANDLE FileDst)
{
   RTFile * volatile f1 = NULL;
   RTFile * volatile f2 = NULL;

   XTRY
      case XCODE:
         f1 = ParseFileHandle(FileSrc);
         /* do-not sync date time with virtual file file handle */
         if (f1->SpecialKind == FileMapFile) break;
         RTFSYSFreeMutex(RTFLock);
         f2 = ParseFileHandle(FileDst);

         f2->DirEntry.Dir.DateTime = f1->DirEntry.Dir.DateTime;
         f2->DirEntry.Dir.FileSize = f1->DirEntry.Dir.FileSize;
         // inherit the attributes in copying process
         f2->DirEntry.Dir.Attributes = f1->DirEntry.Dir.Attributes;
         UpdateDirEntry(f2);
         break;
      default:
         break;
      case XFINALLY:
         if (f2 != NULL) /* imply f1 != NULL, see above */
         {
            UnlockDevice(f2->Dev);
            RTFSYSLockMutex(RTFLock, RTF_INFINITE);
            UnlockDevice(f1->Dev);
         }
         else if (f1 != NULL)
         {
            SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, f1->Dev, RTF_INFINITE); /* it may raise an exception after release the system lock */
            UnlockDevice(f1->Dev);
         }
         break;
   XEND_API
   return RTF_NO_ERROR;
}

int CopyFileLightWeight(const WCHAR * SrcFullPath, const WCHAR * DstFullPath, FS_ProgressCallback Progress, BYTE * Buffer, int BufferLen, kal_uint32 caller_address)
{
   RTFHANDLE FHandle1 = 0, FHandle2 = 0;
   int volatile Result = RTF_NO_ERROR;
   kal_char *Content = NULL;
   UINT wLength1, wLength2 = 0, wLength3 = 0;
   UINT allLength = 0, okLength = 0;
   kal_uint32  LastPgsTime;
   char need_delete    = 0;
   kal_bool flush_chain_head = KAL_TRUE;
   #ifdef __FS_DEDICATED_BUFFER__
   kal_uint32  dedicated_buffer_allocated_len = 0;
   #endif

   #ifdef __FS_DEDICATED_BUFFER__
   // If BufferLen < size of FS Dedicated Buffer, try to get FS Dedicated Buffer
   if (Buffer)
   {
      BufferLen &= 0xFFFFFE00;  // let buffer length be 512 x N

      if (BufferLen != 0)
      {
         Content = (kal_char*)Buffer;
      }
      else  // buffer < 512 bytes, NOT allowed!
      {
         Result = MT_FAIL_GET_MEM;
         goto CopyReturn;
      }
   }
   else // no external buffer
   {
      BufferLen = MTBufAlloc(FS_BUFF_SIZE_MOVE, (unsigned char**)&Content, FS_INT_DBUF_ALLOC_GREEDY);

      if (BufferLen > 0)   // allocate buffer successfully
      {
         if (BufferLen < FS_DEFAULT_BUFF_SIZE_COPY_FILE) // dedicated buffer size < control buffer size
         {
            MTBufFree(BufferLen, (unsigned char**)&Content);   // Content will be set as NULL

            // go through to allocate control buffer
         }
         else  // dedicated buffer size >= control buffer size
         {
            dedicated_buffer_allocated_len = BufferLen;
            BufferLen &= 0xFFFFFE00;
         }
      }

      // if get dedicated buffer failed, go through to get control buffer
   }

   if (NULL == Content)  // working buffer is still NULL
   #endif /* __FS_DEDICATED_BUFFER__ */
   {
      if (!Buffer)
      {
         Content = get_ctrl_buffer(FS_DEFAULT_BUFF_SIZE_COPY_FILE);
         BufferLen = FS_DEFAULT_BUFF_SIZE_COPY_FILE;
      }
      else  // this should not happen!
      {
         Result = MT_FAIL_GET_MEM;
         goto CopyReturn;
      }
   }

   fs_util_trace_info1(TRACE_FUNC, FS_INFO_COPY_FILE_BUFFER_SIZE, BufferLen, NULL);

   FHandle1 = RTFOpen(SrcFullPath, RTF_READ_ONLY | RTF_OPEN_NO_DIR | RTF_OPEN_SHARED, caller_address);

   if (FHandle1 < RTF_NO_ERROR)
   {
      Result = FHandle1;
      goto CopyReturn;
   }

   RTFGetFileSize(FHandle1, &wLength1);

   FHandle2 = RTFOpen(DstFullPath, RTF_READ_WRITE | RTF_OPEN_NO_DIR | RTF_CREATE, caller_address);

   if (FHandle2 < RTF_NO_ERROR)
   {
      Result = FHandle2;
      goto CopyReturn;
   }

   allLength = wLength1;
   LastPgsTime = GetTime() & MT_PGS_PERIOD_MASK;

   while(wLength1 > 0)
   {
      if (wLength1 >= BufferLen)
      {
         wLength2 = BufferLen;
         wLength1 -= BufferLen;
      }
      else
      {
         kal_mem_set(Content, 0, BufferLen); //reduce time, do it here only
         wLength2 = wLength1;
         wLength1 = 0;
      }

      Result = RTFRead(FHandle1, Content, wLength2, &wLength3);

      if (Result < RTF_NO_ERROR)
         goto CopyReturn;

      Result = RTFWrite(FHandle2, Content, wLength2, &wLength3);

      if (Result < RTF_NO_ERROR)
         goto CopyReturn;

      okLength += wLength3;

      if (Progress != NULL)
      {
         if (LastPgsTime != (GetTime() & MT_PGS_PERIOD_MASK))
         {
            LastPgsTime = GetTime() & MT_PGS_PERIOD_MASK;
            Progress(FS_MOVE_PGS_ING, allLength, okLength, FHandle1);
         }
      }

      if (flush_chain_head)
      {
         /*
          * For sudden power lose.
          * Force to commit dir and first fat entry, so that users is able to see and delete the gargabe
          */
         RTFCommit(FHandle2, FS_COMMIT_DEFAULT);
         flush_chain_head = KAL_FALSE;
      }
   }

   CopyFileSyncLastDateTime(FHandle1, FHandle2);

CopyReturn:

   #ifdef __FS_DEDICATED_BUFFER__
   if (dedicated_buffer_allocated_len > 0)
   {
      MTBufFree(dedicated_buffer_allocated_len, (unsigned char**)&Content);
   }
   else
   #endif /* __FS_DEDICATED_BUFFER__ */
   {
      if (Content && !Buffer)
         free_ctrl_buffer(Content);
   }

   if(FHandle1 > 0) RTFClose(FHandle1);
   if(FHandle2 > 0)
   {
      need_delete = 1;  // destination file was created, need to be deleted

      /*
       * RTFCommit will commit all dirty buffers by the order of logical sector number.
       * To reach the maximum performance, call RTFCommit() to flush buffers in order first. (W10.32)
       */
      RTFCommit(FHandle2, FS_COMMIT_DEFAULT);

      RTFClose(FHandle2);
   }
   if(Result < RTF_NO_ERROR)
   {
      if(Progress) Progress(FS_MOVE_PGS_FAIL, 0, 0, Result);

      if (need_delete == 1)
      {
         #ifndef __FS_TRACE_SUPPORT__
         RTFDelete(DstFullPath);
         #else // __FS_TRACE_SUPPORT__
         {
            int Tmp_Result;

            Tmp_Result = RTFDelete(DstFullPath);

            if (Tmp_Result < RTF_NO_ERROR)
            {
               fs_util_trace_err_noinfo(Tmp_Result);
               fs_util_trace_info0(TRACE_ERROR, FS_ERR_FS_MOVE_DELETE_FILE_ERROR, NULL);
               fs_util_trace_str(TRACE_ERROR | MT_TRACE_INFO_WSTR, (void*)DstFullPath);
            }
         }
         #endif // !__FS_TRACE_SUPPORT__
      }
   }
   return Result;
}

/* This subroutine fetch continguous cluster chain and fill into ClusterArray */
static int CopyFileListClusterChain(RTFHANDLE FileSrc, RTFCluster *ClusterArray, int ArraySize, UINT *CurrFilePointer)
{
   RTFile * volatile f1 = NULL;
   int      volatile idx=0;

   XTRY
      case XCODE:
         f1 = ParseFileHandle(FileSrc);
         if (f1->Cluster != 0)
         {
            while (f1->Cluster < RTF_CLUSTER_CHAIN_END && idx < ArraySize)
            {
               if (f1->Valid == FS_FH_ABORTED)
               {
                  fs_util_trace_err_noinfo(MT_ABORTED_ERROR);

                  XRAISE(MT_ABORTED_ERROR);
               }
               ClusterArray[idx++] = f1->Cluster;
               f1->LastCluster = f1->Cluster;
               f1->Cluster = GetClusterValue(f1->Drive, f1->LastCluster);
               f1->FilePointer += f1->Drive->ClusterSize;
               if (f1->Cluster != f1->LastCluster + 1) break;
            }
         }
         *CurrFilePointer = f1->FilePointer;
         break;
      default:
         break;
      case XFINALLY:
         if (f1 != NULL) UnlockDevice(f1->Dev);
         break;
   XEND_API
   return idx;
}

int CopyFileOnSameDrive(const WCHAR * SrcFullPath, const WCHAR * DstFullPath, FS_ProgressCallback Progress, BYTE * Buffer, int BufferLen, kal_uint32 caller_address)
{
   RTFHANDLE   FHandle1 = 0, FHandle2 = 0;
   RTFCluster *ClustersArray = NULL;
   int         ReadCluster, WrittenCluster;
   int volatile Result = RTF_NO_ERROR;
   UINT allLength = 0, okLength = 0;
   kal_uint32  LastPgsTime;
   int need_canceling = 0;

   FHandle1 = RTFOpen(SrcFullPath, RTF_READ_ONLY | RTF_OPEN_NO_DIR | RTF_OPEN_SHARED, caller_address);
   if (FHandle1 < RTF_NO_ERROR)
   {
      Result = FHandle1;
      goto CopyReturn;
   }

   FHandle2 = RTFOpen(DstFullPath, RTF_READ_WRITE | RTF_OPEN_NO_DIR | RTF_CREATE, caller_address);
   if (FHandle2 < RTF_NO_ERROR)
   {
      Result = FHandle2;
      goto CopyReturn;
   }

   if(Buffer==NULL)
   {
       ClustersArray = get_ctrl_buffer(512);
   }
   else
   {
       if(BufferLen<512)
       {
           Result = MT_FAIL_GET_MEM;
           goto CopyReturn;
       }
       ClustersArray = (RTFCluster*)Buffer;
   }
   kal_mem_set(ClustersArray, 0xFF, 512); //reduce time, do it here only

   RTFGetFileSize(FHandle1, &allLength);
   LastPgsTime = GetTime() & MT_PGS_PERIOD_MASK;

   need_canceling = 1;

   /* Fill Contingous Clusters Chain into ClustersArray */
   ReadCluster = CopyFileListClusterChain(FHandle1, ClustersArray, FS_MAX_COPY_CLUSTER, &okLength);
   while (ReadCluster > 0)
   {
      /* Copy to Destination file */
      WrittenCluster = MTCopyFileByClusterChain(FHandle2, ClustersArray, ReadCluster);
      if (WrittenCluster < 0)
      {
         Result = WrittenCluster;
         goto CopyReturn;
      }

      /* Check Progress */
      if (Progress != NULL)
      {
         if (LastPgsTime != (GetTime() & MT_PGS_PERIOD_MASK))
         {
            LastPgsTime = GetTime() & MT_PGS_PERIOD_MASK;
            Progress(FS_MOVE_PGS_ING, allLength, okLength, FHandle1);
         }
      }

      /* Fill Contingous Clusters Chain into ClustersArray, Iteration */
      ReadCluster = CopyFileListClusterChain(FHandle1, ClustersArray, FS_MAX_COPY_CLUSTER, &okLength);
   }

   if (ReadCluster == 0)
   {
      if(allLength>okLength)
      {
          Result = RTF_FAT_ALLOC_ERROR;
      }
      else
      {
          CopyFileSyncLastDateTime(FHandle1, FHandle2);
      }
   }
   else
   {
      Result = ReadCluster;
   }

CopyReturn:
   if (ClustersArray && !Buffer) free_ctrl_buffer(ClustersArray);
   if (FHandle1 > 0) RTFClose(FHandle1);
   if (FHandle2 > 0) RTFClose(FHandle2);
   if (Result < RTF_NO_ERROR)
   {
      int Tmp_Result;

      if(Progress&&need_canceling) Progress(FS_MOVE_PGS_FAIL, 0, 0, Result);

      Tmp_Result = RTFDelete(DstFullPath);

      if (Tmp_Result < RTF_NO_ERROR)
      {
         fs_util_trace_err_noinfo(Tmp_Result);
         fs_util_trace_info0(TRACE_ERROR, FS_ERR_FS_MOVE_DELETE_FILE_ERROR, NULL);
         fs_util_trace_str(TRACE_ERROR | MT_TRACE_INFO_WSTR, (void*)DstFullPath);
      }
   }
   return Result;
}

int GetNameByPos(RTFile *f, WCHAR * FileName, UINT MaxLength, RTFDirLocation *Pos, RTFDOSDirEntry *FileInfo)
{
   int volatile Result = RTF_NO_ERROR;
   RTFDOSDirEntry * D;
   LFNDirEntry * LD;
   int Kind, LFNIndex = -1;
   RTFDirLocation Pos_Copy;

   fs_util_trace_info4(TRACE_GROUP_9 | TRACE_FUNC, FS_TRC_RTF_GETNAMEBYPOS, MaxLength, Pos->Cluster, Pos->Index, 0, NULL);

   Pos_Copy.Cluster = Pos->Cluster;
   Pos_Copy.Index = Pos->Index;

   XTRY //exception handler for GetDir
      case XCODE:
         SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, f->Drive->Dev, RTF_INFINITE);

         D = GetDir(f->Drive, &Pos_Copy); //check for current dir entry

         if (D == NULL)
         {
            fs_util_trace_err_noinfo(RTF_NO_MORE_FILES);
            XRAISE(RTF_NO_MORE_FILES);
         }

         Kind = EntryType(D);

         if (Kind != InUse) //try to make LFN
         {
            while (Kind == Lfn)
            {
               LD = (void*) D;

               if (LD->Ord & 0x40) // it's the start of an LFN
               {
                  char * Limit;
                  LFNIndex = LD->Ord & 0x3F;

                  Limit = ((char *)FileName) + ((LFNIndex-1)*13*2 + 2*LFNCharCount(LD));
                  if (Limit > (((char *)FileName) + MaxLength - 1))
                  {
                      /*
                       * FS_Move(): If destination is too long with LFN, bypass SFN and return
                       *            FS_PATH_OVER_LEN_ERROR directly.
                       *
                       *            Another policy is use SFN as destination file name, however SFN
                       *            should be transform to Unicode first before create it, otherwise
                       *            the result file name will be a mess because native encoding should
                       *            not be used to create file.
                       */
                      fs_util_trace_err_noinfo(MT_PATH_OVER_LEN_ERROR);
                      XRAISE(MT_PATH_OVER_LEN_ERROR);
                      //LFNIndex = -1; // old policy, SFN will be used below.
                  }
                  else
                  {
                     Limit[0] = '\0';
                     Limit[1] = '\0';
                  }
               }

               if (LFNIndex != (LD->Ord & 0x3F) || (LFNIndex <= 0))
                  LFNIndex = -1;
               else
                  CopyLFN((char *)FileName + --LFNIndex * 26, LD);

               D = NextDir(f->Drive, &Pos_Copy);

               /*
                * Disk Corruption: LFN entries are followed by a NULL entry, set Kind as
                * NeverUsed and leave while-loop, then FS_FILE_NOT_FOUND will be returned below.
                *
                * Avoid NULL D causing data abort in EntryType(). (W10.19)
                */
               if (NULL == D)
               {
                  XRAISE(RTF_FILE_NOT_FOUND);
               }

               Kind = EntryType(D);
            }

            if (LFNIndex == 0) //forget checksum to speedup
            {
                if(FileInfo)
                {
                   *FileInfo = *D;
                   FileInfo->NTReserved = MT_ENUM_FIND_LFN;
                }

               break;
            }
         }

         if (Kind == InUse) // LFN is corrupted
         {
             Result = MakeShortFileName(D, (char *)FileName, MaxLength);

             if (RTF_NO_ERROR == Result)
             {
                FileNameExtendToWCHAR((char *)FileName, FS_MAX_SFN_NATIVE_FILE_NAME_LENGTH_B);
                MTCheckFileNameCase(FileName, MaxLength, D->NTReserved);
                if(FileInfo)
                {
                   *FileInfo = *D;
                   FileInfo->NTReserved = MT_ENUM_FIND_SFN;
                }
                break;
             }
             else if (RTF_STRING_BUFFER_TOO_SMALL == Result)
             {
                fs_util_trace_err_noinfo(MT_PATH_OVER_LEN_ERROR);
                XRAISE(MT_PATH_OVER_LEN_ERROR);
             }
             else
             {
                fs_util_trace_err_noinfo(RTF_NO_MORE_FILES);
                XRAISE(RTF_NO_MORE_FILES);
             }
         }
         else
         {
             fs_util_trace_err_noinfo(RTF_FILE_NOT_FOUND);
             XRAISE(RTF_FILE_NOT_FOUND);
         }
         break;
      default:
         Result = XVALUE; //API dose not need XHANDLED
         break;
      case XFINALLY:
         SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV);
         break;
   XEND_API

   return Result;
}

int CreateCopyDestPath(const WCHAR * SrcFullPath, const WCHAR * DstFullPath)
{
   RTFHANDLE FHandle = 0;
   UINT U;
   UINT i;
   RTFile * f;
   char *ptr, *ptr2;
   int Result = RTF_NO_ERROR;

   FHandle = RTFOpen(SrcFullPath, RTF_READ_ONLY | RTF_OPEN_NO_DIR | RTF_OPEN_SHARED, 0);
   if (FHandle < RTF_NO_ERROR)
   {
   	  Result = FHandle;
      return Result;
   }

   U = FHandle >> (4*sizeof(int));
   i = FHandle & ((1 << (4*sizeof(int))) - 1);
   f = gFS_Data.FileTable + i;

   ptr = kal_dchar_strrchr((char*)DstFullPath, '\\') + 2;

   if(f->DirEntry.LongPos.Cluster)
   {
       Result = fs_srv_get_name_by_pos(f, NULL, NULL, (WCHAR *)ptr, MT_MAX_WIDE_PATH-((UINT)ptr-(UINT)DstFullPath), &f->DirEntry.LongPos, FS_FIND_DEFAULT);
   }
   else // only SFN is existed
   {
   	   ptr2 = kal_dchar_strrchr((char*)SrcFullPath, '\\') + 2;
   	   U = (MT_MAX_WIDE_PATH-((UINT)ptr-(UINT)DstFullPath))/2;
   	   for(i=0; *(((WCHAR*)ptr2)+i) && i < U; i++) *(((WCHAR*)ptr)+i)=*(((WCHAR*)ptr2)+i);

   	   if(i>=U)
   	   {
   	       Result = MT_PATH_OVER_LEN_ERROR;
   	   }
   	   else
   	   {
   	       *(((WCHAR*)ptr)+i) = 0;
   	   }
   }

   if (FHandle > 0) RTFClose(FHandle);

   return Result;
}

#ifdef __FS_CHECKDRIVE_SUPPORT__
/* ------------------------------------------------------------------------------- */
/* This function do "cd..". This function will keep the last back slash */
static int CdUp(WCHAR * Path)
{
   UINT idx;
   if(Path[kal_wstrlen((WCHAR *)Path)-1] == 0x5C)
   {
      Path[kal_wstrlen((WCHAR *)Path)-1] = 0;
      Path[kal_wstrlen((WCHAR *)Path)] = 0;
   }
   idx = kal_wstrlen((WCHAR *)Path);
   while((Path[idx] != 0x5C) && (idx > 0))
   {
      Path[idx] = 0;
      idx--;
   }
   return idx;
}
#endif

int fs_srv_get_name_by_pos(RTFile * f, const WCHAR * Pattern, RTFDOSDirEntry * FileInfo, WCHAR * FileName, UINT MaxLength, RTFDirLocation * Pos, UINT Flag)
{
   int volatile      Result = RTF_NO_ERROR;
   RTFDOSDirEntry   *D;
   LFNDirEntry      *LD;
   int               Kind, LFNIndex = -1;
   RTFDrive         *Drive = NULL;
   RTFDirLocation    Pos_Copy;
   kal_bool volatile Release_Mem = KAL_FALSE;
   WCHAR * volatile  FindName = NULL;
   kal_uint32        FindLength = 0;

   // get drive
   if (f)
   {
      Drive = f->Drive;
   }
   else if (Pattern)
   {
      Drive = (RTFDrive*)fs_conf_get_drv_struct_by_drv_letter(Pattern[0]);
   }

   if (NULL == Drive)
   {
      return RTF_PATH_NOT_FOUND;
   }

   Pos_Copy.Cluster = Pos->Cluster;
   Pos_Copy.Index = Pos->Index;

   XTRY //exception handler for GetDir
      case XCODE:
         SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Drive->Dev, RTF_INFINITE);

         D = GetDir(Drive, &Pos_Copy); //check for current dir entry

         if (D == NULL)
         {
            XRAISE(RTF_NO_MORE_FILES);
         }

         Kind = EntryType(D);

         if(Kind != InUse) //try to make LFN
         {
            if(Kind == Lfn)
            {
               if(Flag == FS_FIND_LFN_TRUNC)
               {
                  FindName = get_ctrl_buffer(MT_MAX_WIDE_NAME);

                  // if get_ctrl_buffer failed, it will cause fatal inside. No error handling should be made here.

                  Release_Mem = KAL_TRUE;
                  kal_mem_set(FindName, 0, MT_MAX_WIDE_NAME);
                  FindLength = MT_MAX_WIDE_NAME;
               }
               else
               {
                  FindName = FileName;
                  FindLength = MaxLength;
               }
            }

            while(Kind == Lfn)
            {
               LD = (void*) D;

               if (LD->Ord & 0x40) // it's the start of an LFN
               {
                  char * Limit;
                  LFNIndex = LD->Ord & 0x3F;

                  Limit = ((char *)FindName) + ((LFNIndex-1)*13*2 + 2*LFNCharCount(LD));

                  if (Limit > (((char *)FindName) + FindLength - 1))
                  {
                      /*
                       * FS_Move(): If destination is too long with LFN, bypass SFN and return
                       *            FS_PATH_OVER_LEN_ERROR directly.
                       *
                       *            Another policy is use SFN as destination file name, however SFN
                       *            should be transform to Unicode first before create it, otherwise
                       *            the result file name will be a mess because native encoding should
                       *            not be used to create file.
                       */

                      fs_util_trace_err_noinfo(MT_PATH_OVER_LEN_ERROR);

                      XRAISE(MT_PATH_OVER_LEN_ERROR);

                      //LFNIndex = -1; // old policy, SFN will be used below.
                  }
                  else
                  {
                     Limit[0] = '\0';
                     Limit[1] = '\0';
                  }
               }

               if(LFNIndex != (LD->Ord & 0x3F) || (LFNIndex <= 0))
                  LFNIndex = -1;
               else
                  CopyLFN((char *)FindName + --LFNIndex * 26, LD);

               D = NextDir(Drive, &Pos_Copy);

               /*
                * Disk Corruption: LFN entries are followed by a NULL entry, set Kind as
                * NeverUsed and leave while-loop, then FS_FILE_NOT_FOUND will be returned below.
                *
                * Avoid NULL D causing data abort in EntryType(). (W10.19)
                */
               if (NULL == D)
               {
                  XRAISE(RTF_FILE_NOT_FOUND);
               }

               Kind = EntryType(D);
            }

            if (LFNIndex == 0) //forget checksum to speedup
            {
               if (Release_Mem)
               {
                  WORD i;

                  for (i = 0 ; i < (MaxLength / 2 - 1); i++)
                     FileName[i] = FindName[i];

                  FileName[i] = 0x0000;
               }

               if (FileInfo)
               {
                  *FileInfo = *D;
                  FileInfo->NTReserved = MT_ENUM_FIND_LFN;
               }

               break; // break to XFINALLY
            }
         }

         if(Kind == InUse)
         {
             Result = MakeShortFileName(D, (char *)FileName, MaxLength);

             if (RTF_NO_ERROR == Result)
             {
                FileNameExtendToWCHAR((char *)FileName, FS_MAX_SFN_NATIVE_FILE_NAME_LENGTH_B);
                MTCheckFileNameCase(FileName, MaxLength, D->NTReserved);

                if(FileInfo)
                {
                   *FileInfo = *D;

                   if (FileInfo->FileName[0] == 0x05)
                      FileInfo->FileName[0] = 0xE5;

                   FileInfo->NTReserved = MT_ENUM_FIND_SFN;
                }

                break;
             }
             else if (RTF_STRING_BUFFER_TOO_SMALL == Result)
             {
                fs_util_trace_err_noinfo(MT_PATH_OVER_LEN_ERROR);

                XRAISE(MT_PATH_OVER_LEN_ERROR);
             }
             else
             {
                XRAISE(RTF_NO_MORE_FILES);
             }
         }
         else
         {
            XRAISE(RTF_FILE_NOT_FOUND);
         }
         break;
      default:
         Result = XVALUE; //API dose not need XHANDLED
         break;
      case XFINALLY:
         if (Release_Mem)
         {
            free_ctrl_buffer(FindName);
         }

         SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV);
         break;
   XEND_API

   return Result;
}


/* ------------------------------------------------------------------------------- */
/* Speedup find for sort */
#ifdef __FS_SORT_SUPPORT__

int GetFindByPos(const WCHAR * Pattern, RTFDOSDirEntry * FileInfo, WCHAR * FileName,
                 UINT MaxLength, RTFDirLocation * Pos, UINT Flag)
{
   int volatile      Result = RTF_NO_ERROR;
   RTFDOSDirEntry   *D;
   LFNDirEntry      *LD;
   int               Kind, LFNIndex = -1;
   RTFDrive         *Drive;
   RTFDirLocation    Pos_Copy;
   kal_bool volatile Release_Mem = KAL_FALSE;
   WCHAR * volatile  FindName = NULL;

   Drive = (RTFDrive*)fs_conf_get_drv_struct_by_drv_letter(Pattern[0]);

   if (NULL == Drive)
   {
      return RTF_PATH_NOT_FOUND;
   }

   Pos_Copy.Cluster = Pos->Cluster;
   Pos_Copy.Index = Pos->Index;

   XTRY //exception handler for GetDir
      case XCODE:
         SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Drive->Dev, RTF_INFINITE);

         D = GetDir(Drive, &Pos_Copy); //check for current dir entry

         if (D == NULL)
         {
            XRAISE(RTF_NO_MORE_FILES);
         }

         Kind = EntryType(D);

         if(Kind != InUse) //try to make LFN
         {
            UINT FindLength=0;

            if(Kind == Lfn)
            {
               if(Flag == FS_FIND_LFN_TRUNC)
               {
                  FindName = get_ctrl_buffer(MT_MAX_WIDE_NAME);

                  if(FindName == NULL)
                     goto GetFindByPosNotTrunc;

                  Release_Mem = KAL_TRUE;
                  kal_mem_set(FindName, 0, MT_MAX_WIDE_NAME);
                  FindLength = MT_MAX_WIDE_NAME;
               }
               else
               {
GetFindByPosNotTrunc:
                  FindName = FileName;
                  FindLength = MaxLength;
               }
            }

            while(Kind == Lfn)
            {
               LD = (void*) D;

               if (LD->Ord & 0x40) // it's the start of an LFN
               {
                  char * Limit;
                  LFNIndex = LD->Ord & 0x3F;

                  Limit = ((char *)FindName) + ((LFNIndex-1)*13*2 + 2*LFNCharCount(LD));

                  if (Limit > (((char *)FindName) + FindLength - 1))
                      LFNIndex = -1;
                  else
                  {
                     Limit[0] = '\0';
                     Limit[1] = '\0';
                  }
               }

               if(LFNIndex != (LD->Ord & 0x3F) || (LFNIndex <= 0))
                  LFNIndex = -1;
               else
                  CopyLFN((char *)FindName + --LFNIndex * 26, LD);

               D = NextDir(Drive, &Pos_Copy);

               /*
                * Disk Corruption: LFN entries are followed by a NULL entry,
                * raise FS_FILE_NOT_FOUND to avoid NULL D causing data abort in EntryType(). (W10.19)
                */
               if (NULL == D)
               {
                  XRAISE(RTF_FILE_NOT_FOUND);
               }

               Kind = EntryType(D);
            }

            if (LFNIndex == 0) //forget checksum to speedup
            {
               if (Release_Mem)
               {
                  WORD i;

                  for (i = 0 ; i < (MaxLength/2 - 1); i++)
                     FileName[i] = FindName[i];

                  FileName[i] = 0x0000;
               }

               if (FileInfo)
               {
                  *FileInfo = *D;
                  FileInfo->NTReserved = MT_ENUM_FIND_LFN;
               }

               break; // break to XFINALLY
            }
         }

         if(Kind == InUse)
         {
             if ((MakeShortFileName(D, (char *)FileName, MaxLength) == RTF_NO_ERROR))
             {
                FileNameExtendToWCHAR((char *)FileName, FS_MAX_SFN_NATIVE_FILE_NAME_LENGTH_B);
                if(FileInfo)
                {
                   *FileInfo = *D;
                   /* Fix 0xE5 special char will be treated as deleted, 2005/07/04, ADD START */
                   if (FileInfo->FileName[0] == 0x05)
                      FileInfo->FileName[0] = 0xE5;
                   /* Fix 0xE5 special char will be treated as deleted, 2005/07/04, ADD END */
                   FileInfo->NTReserved = MT_ENUM_FIND_SFN;
                }
                MTCheckFileNameCase(FileName, MaxLength, D->NTReserved);
                break;
             }
             else
                XRAISE(RTF_NO_MORE_FILES);
         }
         else
         {
             XRAISE(RTF_FILE_NOT_FOUND);
         }
         break;
      default:
         Result = XVALUE; //API dose not need XHANDLED
         break;
      case XFINALLY:
         if (Release_Mem) free_ctrl_buffer(FindName);

         SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV);
         break;
   XEND_API

   return Result;
}

#endif

/* ------------------------------------------------------------------------------- */
/* Special FinFirst for FindReset */
int FindFirst(const WCHAR * NamePattern, FS_Pattern_Struct * PatternArray, UINT PatternNum,
              BYTE ArrayMask, BYTE Attr, BYTE AttrMask, RTFDOSDirEntry * FileInfo,
              WCHAR * FileName, UINT MaxLength, RTFDirLocation * Pos_Hint, UINT *DirCluster)
{
   int volatile Result;
   RTFile * volatile f = NULL;
   //const RTFDOSDirEntry * D;
   RTFDirLocation * Pos;
   BYTE * volatile A;

   XTRY
      case XCODE:
         f = ParseFileName((char *)NamePattern);
         if (f->SpecialKind != NormalFile)
            XRAISE(RTF_INVALID_FILENAME);

         f->Flags = RTF_OPEN_DIR | RTF_READ_ONLY | RTF_CACHE_DATA;

         if(SearchFile(f, SEARCH_PARENT, (char *)NamePattern, NULL))
         {
            if(f->DirEntry.DirCluster == 0)
            {
               MakePseudoRootDirEntry(f->Drive, &f->DirEntry);
               if (FileInfo)
                  *FileInfo = f->DirEntry.Dir;
               setASCII(FileName, 0, '\\');
               setASCII(FileName, 1, 0);
               AttrMask = Attr = 0xFF;
            }
            else
               SET_FIRST_FILE_CLUSTER(f->DirEntry.Dir, f->DirEntry.DirCluster);
         }
         #ifdef __FS_OPEN_HINT__
         else  // else we found the parent (return 0)
         {
            /*
             * f->DirEntry.Dir now is the parent of target folders/files.
             * Copy its start cluster to f->DirEntry.DirCluster to let
             * FS keep DirCluster with new location.
             *
             * Note. FindNext will not touch f->DirEntry.DirCluster
             */
            f->DirEntry.DirCluster = FIRST_FILE_CLUSTER(f->DirEntry.Dir);
         }

         // keep DirCluster
         *DirCluster = f->DirEntry.DirCluster;

         #endif /* __FS_OPEN_HINT__ */

         InitFilePointer(f);

         A    = (void*) &f->LastCluster;
         Pos  = (void*) &f->Cluster;
         Pos->Index--;
         A[0] = Attr;
         A[1] = AttrMask | Attr;

         Result = MakeNewFileHandle(f);

         break;
      default:
         Result = XVALUE;
         break;
      case XFINALLY:
         if (f){
            if (Result < RTF_NO_ERROR)
               FreeFTSlotAndDevice(f);
            else
               UnlockDevice(f->Dev);
               }
         break;
   XEND_API

   if ((Result >= RTF_NO_ERROR) && (A[0] != 0xFF)  && (A[1] != 0xFF))
   {
      int R = fs_srv_findnext(Result, PatternArray, PatternNum, ArrayMask, (FS_DOSDirEntry*)FileInfo, FileName, MaxLength, FS_FIND_DEFAULT, (FS_FileLocationHint *)Pos_Hint);

      if (R == RTF_NO_ERROR)
         return Result;
      else
      {
         RTFFindClose(Result);
         return R;
      }
   }
   else
      return Result;
}

/* ------------------------------------------------------------------------------- */
/* Special FinNext for FindReset */
int FindNext(RTFHANDLE Handle, FS_Pattern_Struct * PatternArray, UINT PatternNum,
             BYTE ArrayMask, RTFDOSDirEntry * FileInfo, WCHAR * FileName,
             UINT MaxLength, RTFDirLocation * Pos_Hint)
{
   BYTE CheckSum = 0;
   int LFNIndex = -1;
   RTFile * volatile f = NULL;
   const char * NamePattern;
   RTFDirLocation * Pos;
   BYTE * A;
   int LastIsLFN = 0;
   kal_bool HintDone = KAL_FALSE;
   BYTE NTReserved = 0;

   XTRY
      case XCODE:
         f = ParseFileHandle(Handle);

         if(f->SpecialKind != NormalFile)
            XRAISE(RTF_INVALID_FILE_HANDLE);

         if((f->DirEntry.Dir.Attributes & RTF_ATTR_DIR) == 0)
            XRAISE(RTF_INVALID_FILE_HANDLE);

         NamePattern = kal_dchar_strrchr(f->FullName, '\\')+2;
         A           = (void*) &f->LastCluster;
         Pos         = (void*) &f->Cluster;

         if ((A[0] == 0xFF) && (A[1] == 0xFF))
            XRAISE(RTF_NO_MORE_FILES);

         if(kal_dchar_strcmp(NamePattern, (char *)dchar_start_dot_star) == 0)
            NamePattern += 4;

         while (1)
         {
            int Kind;
            const RTFDOSDirEntry * D = NextDir(f->Drive, Pos);

            if(D == NULL)
               XRAISE(RTF_NO_MORE_FILES);

            Kind = EntryType(D);

            LastIsLFN--;

            if(Kind == NeverUsed)
               XRAISE(RTF_NO_MORE_FILES);

            else if(Kind == Lfn)
            {
               const LFNDirEntry * LD = (void*) D;

               if(HintDone == KAL_FALSE)
               {
                  HintDone = KAL_TRUE;
                  Pos_Hint->Cluster = Pos->Cluster;
                  Pos_Hint->Index = Pos->Index;
               }

               if(LD->Ord & 0x40)
               {
                  char * Limit;
                  LFNIndex = LD->Ord & 0x3F;
                  CheckSum = LD->CheckSum;

                  Limit = ( (char *)FileName) + ((LFNIndex-1)*13*2 + 2*LFNCharCount(LD) );
                  if(Limit > ( ((char *)FileName) + MaxLength - 1))
                      LFNIndex = -1;
                  else
                  {
                     Limit[0] = '\0';
                     Limit[1] = '\0';
                  }
               }

               if((LD->CheckSum != CheckSum) || (LFNIndex != (LD->Ord & 0x3F)) || (LFNIndex <= 0))
                  LFNIndex = -1;
               else
                  CopyLFN((char *)FileName + --LFNIndex * 26, LD);
               LastIsLFN = 2;
            }
            else if((Kind == InUse) && ((D->Attributes & A[1]) == A[0]))
            {
               int j;

               if (D->FileName[0] == 0x2E)  // '.'
               {
                   if ((D->FileName[1] != 0x20) && (D->FileName[1] != 0x2E))  // ".X"
                   {
                       goto ContinueFindNext_3;
                   }

                   for (j = 2; j <= 7; j++)
                   {
                       if (D->FileName[j] != 0x20)
                       {
                           goto ContinueFindNext_3;  // "..XYZ" or ". XYZ"?
                       }
                   }

                   HintDone = KAL_FALSE;
                   goto ContinueFindNext_2;   // skip "."
                   /* dot, dot-dot */
               }

ContinueFindNext_3:

               if (FileInfo)
               {
                  *FileInfo = *D;
                  FileInfo->NTReserved = MT_ENUM_FIND_NONE;
               }

               if((LFNIndex == 0) && (CheckSum== ShortNameCheckSum((BYTE*) D->FileName)))
               {
                  UINT i;

                  if(PatternNum > 0)
                  {
                     if(D->Attributes & ArrayMask)
                     {
                        if(FileNamesMatch((WCHAR *)NamePattern, FileName))
                        {
                           if (FileInfo)
                              FileInfo->NTReserved = MT_ENUM_FIND_LFN;

                           goto SkipFindNext;
                        }
                        goto ContinueFindNext_1;
                     }

                     for(i = 0; i < PatternNum; i++)
                     {
                        if(PatternArray[i].Pattern == NULL)
                           XRAISE(RTF_PARAM_ERROR);

                        if(FileNamesMatch((WCHAR *)PatternArray[i].Pattern, FileName))
                        {
                           if (FileInfo)
                              FileInfo->NTReserved = MT_ENUM_FIND_LFN;

                           goto SkipFindNext;
                        }
                     }
                  }
                  else if(FileNamesMatch((WCHAR *)NamePattern, FileName))
                  {
                     if (FileInfo)
                        FileInfo->NTReserved = MT_ENUM_FIND_LFN;

                     break;
                  }
               }
               else
               {
                   LastIsLFN = 0;
               }
ContinueFindNext_1:
               if((MakeShortFileName(D, (char *)FileName, MaxLength) == RTF_NO_ERROR) &&
                  (LastIsLFN != 1)) //LFN match fail, don't have to match SFN
               {
                  UINT i;

                  FileNameExtendToWCHAR((char *)FileName, FS_MAX_SFN_NATIVE_FILE_NAME_LENGTH_B);

                  if(PatternNum > 0)
                  {
                     if(D->Attributes & ArrayMask)
                     {
                        if(FileNamesMatch((WCHAR *)NamePattern, FileName))
                        {
                           if (FileInfo)
                           {
                              if (FileInfo->FileName[0] == 0x05)
                                 FileInfo->FileName[0] = 0xE5;

                              FileInfo->NTReserved = MT_ENUM_FIND_SFN;
                           }

                           NTReserved = D->NTReserved;
                           Pos_Hint->Cluster = Pos->Cluster;
                           Pos_Hint->Index = Pos->Index;
                           break;
                        }
                        HintDone = KAL_FALSE;
                        goto ContinueFindNext_2;
                     }

                     for(i = 0; i < PatternNum; i++)
                     {
                        if(PatternArray[i].Pattern == NULL)
                           XRAISE(RTF_PARAM_ERROR);

                        if(FileNamesMatch((WCHAR *)PatternArray[i].Pattern, FileName))
                        {
                           if (FileInfo)
                           {
                              if (FileInfo->FileName[0] == 0x05)
                                 FileInfo->FileName[0] = 0xE5;

                              FileInfo->NTReserved = MT_ENUM_FIND_SFN;
                           }

                           NTReserved = D->NTReserved;
                           Pos_Hint->Cluster = Pos->Cluster;
                           Pos_Hint->Index = Pos->Index;
                           goto SkipFindNext;
                        }
                     }
                  }
                  else if(FileNamesMatch((WCHAR *)NamePattern, FileName))
                  {
                     if (FileInfo)
                     {
                        if (FileInfo->FileName[0] == 0x05)
                           FileInfo->FileName[0] = 0xE5;

                        FileInfo->NTReserved = MT_ENUM_FIND_SFN;
                     }

                     NTReserved = D->NTReserved;
                     Pos_Hint->Cluster = Pos->Cluster;
                     Pos_Hint->Index = Pos->Index;
                     break;
                  }
               }
               HintDone = KAL_FALSE;
            }
            else
               HintDone = KAL_FALSE;
ContinueFindNext_2:
            if(Kind != Lfn)
               LFNIndex = -1;
         }
SkipFindNext:
         MTCheckFileNameCase(FileName, MaxLength, NTReserved);
         break;
      default:
         break;
      case XFINALLY:
         if (f) UnlockDevice(f->Dev);
         break;
   XEND_API
   return RTF_NO_ERROR;
}

/* ------------------------------------------------------------------------------- */
int GetFirstClusterByFileName(const WCHAR *FileName, UINT * Cluster)
{
   int volatile Result = RTF_NO_ERROR;
   RTFile * volatile f = NULL;

   XTRY
      case XCODE:
         f = ParseFileName((char *)FileName);
         if (f->SpecialKind != NormalFile)
            XRAISE(RTF_INVALID_FILENAME);
         if (!SearchFile(f, SEARCH_FILES, (char *)FileName, NULL))
            XRAISE(RTF_PATH_NOT_FOUND);
         *Cluster = FIRST_FILE_CLUSTER(f->DirEntry.Dir);
         break;

      default:
         Result = XVALUE; //API dose not need XHANDLED
         break;

      case XFINALLY:
         if (f != NULL)
            FreeFTSlotAndDevice(f);
         break;
   XEND_API

   return Result;
}

/* ------------------------------------------------------------------------------- */
int GetFirstClusterByFileHandle(RTFHANDLE FileHandle, UINT * Cluster)
{
   int volatile Result = RTF_NO_ERROR;
   RTFile * volatile f = NULL;

   XTRY
      case XCODE:
         f = ParseFileHandle(FileHandle);
         if (f->SpecialKind != NormalFile)
            XRAISE(RTF_DATA_ERROR);
         *Cluster = FIRST_FILE_CLUSTER(f->DirEntry.Dir);
         break;

      default:
         Result = XVALUE; //API dose not need XHANDLED
         break;

      case XFINALLY:
         if (f != NULL)
            UnlockDevice(f->Dev);
         break;
   XEND_API

   return Result;
}
/* ------------------------------------------------------------------------------- */
#ifdef __FS_QM_SUPPORT__

static int FolderInQuotaSet(WCHAR * Folder)
{
   int i, j, k, m;
   WCHAR *WidePath = NULL;

   WidePath = get_ctrl_buffer(MT_MAX_WIDE_PATH);
   if(WidePath == NULL)
      return 0;

   for (i = FS_MAX_QSET - 1 ; i >= 0; i--)
   {
      kal_mem_set(WidePath, 0, RTF_MAX_PATH);
      k = strlen((char *)gFS_IntQuotaSet[i].Path) - 1; //remove the last '\'
      m = 0;
      for(j = 3; j < k; j++, m++)
         WidePath[m] = gFS_IntQuotaSet[i].Path[j];
      if(kal_dchar_strcmp((char *)Folder, (char *)WidePath) == 0)
      {
         if(WidePath) free_ctrl_buffer(WidePath);
         return 1;
      }
   }
   if(WidePath) free_ctrl_buffer(WidePath);
   return 0;
}

#endif

/* ------------------------------------------------------------------------------- */
#ifdef __FS_QM_SUPPORT__

void SweepDrive(BYTE DriveLetter)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   int  Result = RTF_NO_ERROR;
   int  i;
   UINT j = 0;
   UINT RFS = 0;
   int  FolderSize;
   RTFDrive * Drive;
   WCHAR *WidePath = NULL;
   WCHAR *WideName = NULL;
   WCHAR RootName[4];
   RTFHANDLE FHandle;
   RTFDOSDirEntry FileInfo;

   /*----------------------------------------------------------------*/
   /* Code Body , SECTION A :                                        */
   /*----------------------------------------------------------------*/
   Drive = (RTFDrive*)fs_conf_get_drv_struct_by_drv_letter(DriveLetter);

   if (Drive == NULL)
   {
      return;
   }

   /* do nothing if alreay swept before */
   if (Drive->QuotaMgt) return;

   /* This Drive must successful mounted */
   fs_assert_local(Drive->MountState == HasFileSystem);

   /* Get disk free space */
   if(Drive->FreeClusterCount == RTF_INVALID_CLUSTER)
   {
      ReMountDriveAndCountFreeClusters(Drive);
   }

   SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Drive->Dev, RTF_INFINITE);

   /*----------------------------------------------------------------*/
   /* Code Body , SECTION B : Check gFS_IntQuotaSet Table Setting    */
   /*----------------------------------------------------------------*/
   for (i = FS_MAX_QSET - 1 ; i >= 0; i--)
   {

      if (gFS_IntQuotaSet[i].Priority > MT_QP_DEL_ENUM) fs_assert_local(0);
      if (gFS_IntQuotaSet[i].Qmax == 0) fs_assert_local(0);
      if (gFS_IntQuotaSet[i].Qmin > gFS_IntQuotaSet[i].Qmax) fs_assert_local(0);
      if ((gFS_IntQuotaSet[i].Uint != FS_COUNT_IN_BYTE) && (gFS_IntQuotaSet[i].Uint != FS_COUNT_IN_CLUSTER)) fs_assert_local(0);

      if (DriveLetter == gFS_IntQuotaSet[i].Path[0])
      {
         if (gFS_IntQuotaSet[i].Qmax == FS_QMAX_NO_LIMIT)
         {
            gFS_IntQuotaSet[i].Qmax = 0;
         }
         else
         {
            if (gFS_IntQuotaSet[i].Uint == FS_COUNT_IN_BYTE)
            {
               if (gFS_IntQuotaSet[i].Qmax % Drive->ClusterSize)
                  gFS_IntQuotaSet[i].Qmax = (gFS_IntQuotaSet[i].Qmax / Drive->ClusterSize) + 1;
               else
                  gFS_IntQuotaSet[i].Qmax = (gFS_IntQuotaSet[i].Qmax / Drive->ClusterSize);
            }
            else
            {
               gFS_IntQuotaSet[i].Qmax = gFS_IntQuotaSet[i].Qmax;
            }
         }

         if (gFS_IntQuotaSet[i].Uint == FS_COUNT_IN_BYTE)
         {
            if (gFS_IntQuotaSet[i].Qmin % Drive->ClusterSize)
               gFS_IntQuotaSet[i].Qmin = (gFS_IntQuotaSet[i].Qmin / Drive->ClusterSize) + 1;
            else
               gFS_IntQuotaSet[i].Qmin = (gFS_IntQuotaSet[i].Qmin / Drive->ClusterSize);
         }
         else
         {
            gFS_IntQuotaSet[i].Qmin = gFS_IntQuotaSet[i].Qmin;
         }
      }
   }

   /*----------------------------------------------------------------*/
   /* Code Body , SECTION C : Disk Free Space And Quota Entry Usage  */
   /*----------------------------------------------------------------*/
   /* Raise Drive Quota Flag */
   Drive->QuotaMgt = 1;

   /* Start to sweep disk */
   WidePath = get_ctrl_buffer(MT_MAX_WIDE_PATH);
   WideName = get_ctrl_buffer(MT_MAX_WIDE_NAME);

   for (i = FS_MAX_QSET - 1 ; i >= 0; i--)
   {
      if (DriveLetter == gFS_IntQuotaSet[i].Path[0])
      {
         j = i;

         kal_mem_set(WidePath, 0, RTF_MAX_PATH);
         strcpy((char *)WidePath, (char *)gFS_IntQuotaSet[i].Path);
         FileNameExtendToWCHAR((char *)WidePath, (RTF_MAX_PATH / 2) - 1);

         // C - 1. Is Folder Exist ?
         Result = RecAUX_IsFolder(WidePath);
         if (Result < RTF_NO_ERROR)
         {
            gFS_IntQuotaSet[i].Uint= 0;
            goto SweepCalc;
         }

         FolderSize = RecAUX_CountSumOfSizeUnderFolderTree(WidePath, FS_COUNT_IN_CLUSTER, NULL, 0, NULL);

         if (FolderSize > RTF_NO_ERROR)
            gFS_IntQuotaSet[i].Uint = FolderSize;
         else
            gFS_IntQuotaSet[i].Uint = 0;

         // C - 2. Remove DEL
         if (gFS_IntQuotaSet[i].Priority == MT_QP_DEL_ENUM)
         {
            Result = RecAUX_XDeleteFolder(WidePath, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, NULL, 0);
            if(Result >= RTF_NO_ERROR)
            {
               SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Drive->Dev, RTF_INFINITE);
               gFS_IntQuotaSet[i].Uint = 0;
            }
            else //error handling
            {
               FolderSize = RecAUX_CountSumOfSizeUnderFolderTree(WidePath, FS_COUNT_IN_CLUSTER, NULL, 0, NULL);

               if (FolderSize > RTF_NO_ERROR)
                  gFS_IntQuotaSet[i].Uint = FolderSize;
               else
                  gFS_IntQuotaSet[i].Uint = 0;
            }
         }
         // C - 3. Remove if over quota
         if (gFS_IntQuotaSet[i].Qmax) //quota with limit
         {
            if (gFS_IntQuotaSet[i].Uint > gFS_IntQuotaSet[i].Qmax)
            {
               Result = RecAUX_XDeleteFolder(WidePath, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, NULL, 0);
               if (Result >= RTF_NO_ERROR)
               {
                  SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Drive->Dev, RTF_INFINITE);
                  gFS_IntQuotaSet[i].Uint = 0;
               }
            }
            else //error handling
            {
               FolderSize = RecAUX_CountSumOfSizeUnderFolderTree(WidePath, FS_COUNT_IN_CLUSTER, NULL, 0, NULL);

               if (FolderSize > RTF_NO_ERROR)
                  gFS_IntQuotaSet[i].Uint = FolderSize;
               else
                  gFS_IntQuotaSet[i].Uint = 0;
            }
         }
         // C - 4. Count RFS
SweepCalc:
         if (gFS_IntQuotaSet[i].Qmin > gFS_IntQuotaSet[i].Uint)
            RFS += (gFS_IntQuotaSet[i].Qmin - gFS_IntQuotaSet[i].Uint);
      }
   }

   /* Special for NVRAM
    * Note !!! nvram interface split on 2006/07/17,
    * here we get the NVRAM name only
    */
   nvram_get_folder_name(NvramName);

   /*----------------------------------------------------------------*/
   /* Code Body , SECTION D : Start to Sweep to Get More Free Space  */
   /*----------------------------------------------------------------*/
   if ((Drive->FreeClusterCount < RFS) || (Drive->FreeClusterCount == 0))
   {
      kal_mem_set(WidePath, 0, MT_MAX_WIDE_PATH);
      strncpy((char *)WidePath, (char *)gFS_IntQuotaSet[j].Path, 3);
      FileNameExtendToWCHAR((char *)WidePath, (RTF_MAX_PATH / 2) - 1);
      kal_wstrcpy(RootName, WidePath);

      // D - 1. Remove files under "X:\"
      RecAUX_XDeleteFolder(WidePath, FS_FILE_TYPE, NULL, NULL, 0);
   }

   if ((Drive->FreeClusterCount < RFS) || (Drive->FreeClusterCount == 0))
   {
      // D - 2. Remove folders not in gFS_IntQuotaSet
      kal_wstrcat(WidePath, L"*");
      FHandle = RTFFindFirstEx(WidePath, 0, 0, &FileInfo, WideName, RTF_MAX_PATH, NULL, NULL);
      if (FHandle > 0)
      {
         if (!WFNamesMatch((char *)WideName, (char *)dchar_dot))
         //Don't worry about dchar_dot_dot here
         {
            if (WFNamesMatch((char *)WideName, (char *)NvramName))
               goto SweepFolder;

            if (FileInfo.Attributes & RTF_ATTR_DIR)
            {
               if (WideName[0] == 0x40) //'@'
               {
                  if (FolderInQuotaSet(WideName)) //in table
                     goto SweepFolder;
               }
               kal_wstrcpy(WidePath, RootName);
               kal_wstrcat(WidePath, WideName);
               RecAUX_XDeleteFolder(WidePath, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, NULL, 0);
               if(Drive->FreeClusterCount >= RFS)
                  goto SweepReturn;
            }
         }
SweepFolder:
         while(RTFFindNextEx(FHandle, &FileInfo, (WCHAR *)WideName, RTF_MAX_PATH, NULL) == RTF_NO_ERROR)
         {
            if (!WFNamesMatch((char *)WideName, (char *)dchar_dot_dot))
            {
               if (WFNamesMatch((char *)WideName, (char *)NvramName))
                  goto SweepFolder;
               if (FileInfo.Attributes & RTF_ATTR_DIR)
               {
                  if (WideName[0] == 0x40) //'@'
                  {
                     if (FolderInQuotaSet(WideName)) //in table
                        goto SweepFolder;
                  }
                  kal_wstrcpy(WidePath, RootName);
                  kal_wstrcat(WidePath, WideName);
                  RecAUX_XDeleteFolder(WidePath, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, NULL, 0);
                  if (Drive->FreeClusterCount >= RFS)
                     goto SweepReturn;
               }
            }
         }
      }
   }

    {
        int current_priority = -1;  // default value -1: Before start to sweep MID & LOW

SweepDriveLowMid:

        if (current_priority == -1)
        {
            current_priority = MT_QP_LOW_ENUM;  // delete LOW first
        }
        else if (current_priority == MT_QP_LOW_ENUM)
        {
            current_priority = MT_QP_MID_ENUM;  // delete MID after LOW is deleted if required
        }
        else
        {
            goto SweepReturn;
        }

        if ((Drive->FreeClusterCount < RFS) || (Drive->FreeClusterCount == 0))
        {
            for (i = FS_MAX_QSET - 1 ; i >= 0; i--)
            {
                if (DriveLetter == gFS_IntQuotaSet[i].Path[0])
                {
                    // D - 3. Remove LOW
                    if (gFS_IntQuotaSet[i].Priority == current_priority)
                    {
                        kal_mem_set(WidePath, 0, RTF_MAX_PATH);
                        strcpy((char *)WidePath, (char *)gFS_IntQuotaSet[i].Path);
                        FileNameExtendToWCHAR((char *)WidePath, (RTF_MAX_PATH / 2) - 1);

                        /* check if WidePath is an existed DIR */
                        Result = RecAUX_IsFolder(WidePath);

                        if (Result < RTF_NO_ERROR) continue;

                        /* delete LOW folder */
                        Result = RecAUX_XDeleteFolder(WidePath, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, NULL, 0);

                        if (Result >= RTF_NO_ERROR)
                        {
                            SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Drive->Dev, RTF_INFINITE);

                            /* update RFS and Uint */
                            if(gFS_IntQuotaSet[i].Uint > gFS_IntQuotaSet[i].Qmin)
                                RFS += gFS_IntQuotaSet[i].Qmin;
                            else
                                RFS += gFS_IntQuotaSet[i].Uint;

                            gFS_IntQuotaSet[i].Uint = 0;

                            if (Drive->FreeClusterCount >= RFS)
                                goto SweepReturn;
                        }
                    }
                }
            } /* for (i = FS_MAX_QSET - 1 ; i >= 0; i--) , Priority LOW */
        }

        goto SweepDriveLowMid;
    }

   /*----------------------------------------------------------------*/
   /* Code Body , SECTION E : ENDING                                 */
   /*----------------------------------------------------------------*/
SweepReturn:
   if(WidePath) free_ctrl_buffer(WidePath);
   if(WideName) free_ctrl_buffer(WideName);
   SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV);
}

#endif

/* ------------------------------------------------------------------------------- */
#ifdef __FS_QM_SUPPORT__

int ChkQuotaConfig(BYTE DriveLetter)
{
   int        Result = RTF_NO_ERROR, i;
   UINT       MRS = 0, RFS = 0;
   RTFDrive * Drive;
   //--- for gFS_IntQuotaSet table checking
   int        k, j;
   kal_bool   g_FirstDownload = KAL_TRUE;
   BYTE       MaxDrvIdx;

   Drive = (RTFDrive*)fs_conf_get_drv_struct_by_drv_letter((WCHAR)DriveLetter);

   /* This Drive must successful mounted, and swept called before */
   if (Drive == NULL ||
       Drive->MountState != HasFileSystem ||
       Drive->QuotaMgt != 1)
   {
      fs_assert_local(0);
   }

   SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Drive->Dev, RTF_INFINITE);

   #if !defined(__FS_SLIM_QUOTA_CONFIG_CHECK__)

   /*
    * Check gFS_IntQuotaSet table setting
    *
    * (Only check at first download, fs_assert_local only when in-house testing)
    */
   if (Check_NORFlash_Formatted() == 0)
      g_FirstDownload = KAL_FALSE;

   if (g_FirstDownload == KAL_TRUE)
   {
      if ((FS_MAX_QSET + 1) > MT_MAX_QUOTA_ENTRY) fs_assert_local(0);

      for (i = MT_BASE_DRIVE_INDEX; i < FS_MAX_DRIVES; i++)
      {
         if (gFS_Data.DriveTable[i].Dev == NULL)
         break;
      }

      MaxDrvIdx = (MT_BASE_DRIVE_LETTER + i - 1);

      for (i = FS_MAX_QSET - 1 ; i >= 0; i--)
      {
         // Check table setting
         // Here is configure error

         if (DriveLetter != (BYTE)DrvMappingNew)
         {
            if ((gFS_IntQuotaSet[i].Path[0] < MT_BASE_DRIVE_LETTER) || (gFS_IntQuotaSet[i].Path[0]) > MaxDrvIdx) fs_assert_local(0);
         }

         if (gFS_IntQuotaSet[i].Path[1] != 0x3A) fs_assert_local(0); // ':'
         if (gFS_IntQuotaSet[i].Path[2] != 0x5C) fs_assert_local(0); // '\'
         if (gFS_IntQuotaSet[i].Path[3] != 0x40) fs_assert_local(0); // '@'
         if (strlen((char *)gFS_IntQuotaSet[i].Path) >= MT_MAXPATH_IN_WCHAR_UNIT) fs_assert_local(0);

         k = strlen((char *)gFS_IntQuotaSet[i].Path) - 1;
         if (gFS_IntQuotaSet[i].Path[k] != 0x5C) fs_assert_local(0); // last char should be '\'

         for(j = 4; j < k; j++)
         {
            if (gFS_IntQuotaSet[i].Path[j] == 0x5C) fs_assert_local(0); // not support multi-level folder
         }

      }
   }

   #endif

   /* Get NVRAM's MRS */
   nvram_space_reserve(&MRS);

   /* Calculate MRS, RFS */
   for (i = FS_MAX_QSET - 1 ; i >= 0; i--)
   {
      if (DriveLetter == gFS_IntQuotaSet[i].Path[0])
      {
         if (Drive->Clusters < gFS_IntQuotaSet[i].Qmax)
         {
            /* App. Quota Max over disk space
             * This should be configuration error
             */
            fs_util_trace_err_noinfo(MT_QUOTA_OVER_DISK_SPACE);
            fs_util_trace_info2(TRACE_ERROR, FS_ERR_QMAX_OVER_DISK, Drive->Clusters, gFS_IntQuotaSet[i].Qmax, NULL);

            Result = MT_QUOTA_OVER_DISK_SPACE;
            break;
         }

         MRS += gFS_IntQuotaSet[i].Qmin;

         if (gFS_IntQuotaSet[i].Qmin > gFS_IntQuotaSet[i].Uint)
         {
            RFS += (gFS_IntQuotaSet[i].Qmin - gFS_IntQuotaSet[i].Uint);
         }
      }
   }

   if (Drive->Clusters < MRS)
   {
      /* Total Minal Reserved Space for Applications (NVRAM included) over disk space
       * This should be configuration error
       */
      fs_util_trace_err_noinfo(MT_QUOTA_OVER_DISK_SPACE);
      fs_util_trace_info2(TRACE_ERROR, FS_ERR_QMIN_OVER_DISK, Drive->Clusters, MRS, NULL);

      Result = MT_QUOTA_OVER_DISK_SPACE;
   }
   else if (Drive->FreeClusterCount < RFS)
   {
      /* Minal Reserved Space Not Enought for Application required,
       * This should be run-time disk full error, raise warnning
       */
      fs_util_trace_err_noinfo(MT_QUOTA_USAGE_WARNING);
      fs_util_trace_info2(TRACE_ERROR, FS_ERR_QRFS_OVER_DFS, Drive->FreeClusterCount, RFS, NULL);

      Result = MT_QUOTA_USAGE_WARNING;
   }

   SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV);

   return Result;
}
#endif

/* ------------------------------------------------------------------------------- */
#ifdef __P_PROPRIETARY_COPYRIGHT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //__P_PROPRIETARY_COPYRIGHT__

/* ------------------------------------------------------------------------------- */
#ifdef __P_PROPRIETARY_COPYRIGHT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //__P_PROPRIETARY_COPYRIGHT__

/* ------------------------------------------------------------------------------- */
int MTMakeFileName(RTFDrive * Drive, RTFDirLocation * Pos, WCHAR * FileName, UINT MaxLength)
{
   BYTE              CheckSum    = 0;
   BYTE              NTReserved  = 0;
   int               LFNIndex    = -1;
   RTFDOSDirEntry    *D;
   int               Kind;

   XTRY
      case XCODE:
         SafeLock(MT_LOCK_DEV | MT_LOCK_RTF, Drive->Dev, RTF_INFINITE);

         D = GetDir(Drive, Pos);

         do
         {
            if (D == NULL)
               XRAISE(RTF_PARAM_ERROR);

            Kind = EntryType(D);

            if (Kind == NeverUsed)
            {
               XRAISE(RTF_PARAM_ERROR);
            }
            else if (Kind == Lfn)
            {
               const LFNDirEntry * LD = (void*) D;

               if (LD->Ord & 0x40) // it's the start of an LFN
               {
                  // see if it fits
                  char * Limit;
                  LFNIndex = LD->Ord & 0x3F;
                  CheckSum = LD->CheckSum;

                  /* characters stored in the LFN entry are in 2-byte unicode*/
                  Limit = ( (char *)FileName) + ((LFNIndex-1)*13*2 + 2*LFNCharCount(LD) );
                  if (Limit > ( ((char *)FileName) + MaxLength - 1)) /* not able to hold */
                      LFNIndex = -1;
                  else
                  {
                     Limit[0] = '\0';
                     Limit[1] = '\0';
                  }
               }
               if ((LD->CheckSum != CheckSum) || (LFNIndex != (LD->Ord & 0x3F)) || (LFNIndex <= 0))
                  LFNIndex = -1;
               else
                  CopyLFN((char *)FileName + --LFNIndex * 26, LD);
            }
            else if (Kind == InUse)
            {
               // check against LFN first
               if ((LFNIndex == 0) && (CheckSum== ShortNameCheckSum((BYTE*) D->FileName)))
               {
                  break;
               }
               // try short name
               if ((MakeShortFileName(D, (char *)FileName, MaxLength) == RTF_NO_ERROR) )
               {
                  FileNameExtendToWCHAR((char *)FileName, FS_MAX_SFN_NATIVE_FILE_NAME_LENGTH_B);

                  NTReserved = D->NTReserved;

                  break;
               }
            }
            if (Kind != Lfn)
               LFNIndex = -1;
            D = NextDir(Drive, Pos);
         } while (1);

         MTCheckFileNameCase(FileName, MaxLength, NTReserved);

         break;
      default:
         break;
      case XFINALLY:
         SafeUnlock(MT_LOCK_DEV | MT_LOCK_RTF);
         break;
   XEND_API

   return RTF_NO_ERROR;
}

/* ------------------------------------------------------------------------------- */
#ifdef __FS_CHECKDRIVE_SUPPORT__
/**************************************************
 *  __FS_CHECKDRIVE_SUPPORT__ feature
 *  Utilities For Directory Entries Processing
 **************************************************/

static int ScanFindFirst(WCHAR * NamePattern, RTFDirEntry * DirPos)
{
   int volatile Result;
   RTFile * volatile f = NULL;
   RTFDirLocation * Pos;
   BYTE * volatile A;
   BYTE Attr = 0, AttrMask = 0;

   XTRY
      case XCODE:
         f = ParseFileName((char *)NamePattern);
         if (f->SpecialKind != NormalFile)
            XRAISE(RTF_INVALID_FILENAME);

         f->Flags = RTF_OPEN_DIR | RTF_READ_ONLY | RTF_CACHE_DATA;

         if(SearchFile(f, SEARCH_PARENT, (char *)NamePattern, NULL))
         {
            if(f->DirEntry.DirCluster == 0)
            {
               MakePseudoRootDirEntry(f->Drive, &f->DirEntry);
               if (DirPos)
                  DirPos->Dir = f->DirEntry.Dir;
               AttrMask = Attr = 0xFF;
            }
            else
               SET_FIRST_FILE_CLUSTER(f->DirEntry.Dir, f->DirEntry.DirCluster);
         }

         InitFilePointer(f);

         A    = (void*) &f->LastCluster;
         Pos  = (void*) &f->Cluster;
         Pos->Index--;
         A[0] = Attr;
         A[1] = AttrMask | Attr;

         Result = MakeNewFileHandle(f);

         break;
      default:
         Result = XVALUE;
         break;
      case XFINALLY:
         if (f != NULL)
         {
            if (Result < RTF_NO_ERROR)
               FreeFTSlotAndDevice(f);
            else
               UnlockDevice(f->Dev);
         }
         break;
   XEND_API

   return Result;
}

static int ScanFindNext(RTFHANDLE Handle, WCHAR * FileName, RTFDirEntry * DirPos)
{
   BYTE CheckSum = 0;
   int LFNIndex = -1;
   RTFile * volatile f = NULL;
   const char * NamePattern;
   RTFDirLocation * Pos;
   BYTE * A;
   kal_bool HintDone = KAL_FALSE;
   const WCHAR *p;

   kal_mem_set(DirPos, 0, sizeof(RTFDirEntry));

   XTRY
      case XCODE:
         f = ParseFileHandle(Handle);

         if(f->SpecialKind != NormalFile)
            XRAISE(RTF_INVALID_FILE_HANDLE);

         if((f->DirEntry.Dir.Attributes & RTF_ATTR_DIR) == 0)
            XRAISE(RTF_INVALID_FILE_HANDLE);

         NamePattern = kal_dchar_strrchr(f->FullName, '\\')+2;
         A           = (void*) &f->LastCluster;
         Pos         = (void*) &f->Cluster;

         if ((A[0] == 0xFF) && (A[1] == 0xFF))
            XRAISE(RTF_NO_MORE_FILES);

         if(kal_dchar_strcmp(NamePattern, (char *)dchar_start_dot_star) == 0)
            NamePattern += 4;

         while (1)
         {
            int Kind;
            const RTFDOSDirEntry * D = NextDir(f->Drive, Pos);

            if(D == NULL)
               XRAISE(RTF_NO_MORE_FILES);

            Kind = EntryType(D);

            if(Kind == NeverUsed)
               XRAISE(RTF_NO_MORE_FILES);

            else if(Kind == Lfn)
            {
               const LFNDirEntry * LD = (void*) D;

               if(HintDone == KAL_FALSE)
               {
                  HintDone = KAL_TRUE;
                  DirPos->LongPos.Cluster = Pos->Cluster;
                  DirPos->LongPos.Index = Pos->Index;
               }

               if(LD->Ord & 0x40)
               {
                  char * Limit;
                  LFNIndex = LD->Ord & 0x3F;
                  CheckSum = LD->CheckSum;

                  Limit = ( (char *)FileName) + ((LFNIndex-1)*13*2 + 2*LFNCharCount(LD) );
                  if(Limit > ( ((char *)FileName) + RTF_MAX_PATH - 1))
                      LFNIndex = -2;
                  else
                  {
                     Limit[0] = '\0';
                     Limit[1] = '\0';
                  }
               }
               if((LD->CheckSum != CheckSum) || (LFNIndex != (LD->Ord & 0x3F)) || (LFNIndex <= 0))
                  LFNIndex = -2;
               else
                  CopyLFN((char *)FileName + --LFNIndex * 26, LD);
            }
            else if((Kind == InUse) && ((D->Attributes & A[1]) == A[0]))
            {
               if(DirPos)
                  DirPos->Dir = *D;
               if(LFNIndex == -2)
                  DelDirEntry(f->Drive, &DirPos->LongPos, Pos);
               else if((LFNIndex == 0) && (CheckSum== ShortNameCheckSum((BYTE*) D->FileName)))
               {
                  p = (WCHAR *)FileName;
                  while (p[0])
                  {
                     if (!fs_util_validate_lfn_char(*p++))
                     {
                        DelDirEntry(f->Drive, &DirPos->LongPos, Pos);
                        HintDone = KAL_FALSE;
                        goto ScanFindNextContinue;
                     }
                  }
                  DirPos->ShortPos.Cluster = Pos->Cluster;
                  DirPos->ShortPos.Index = Pos->Index;
                  break;
               }
               else if(MakeShortFileName(D, (char *)FileName, RTF_MAX_PATH) != RTF_NO_ERROR)
                  DelDirEntry(f->Drive, &DirPos->LongPos, Pos);
               else
               {
                  FileNameExtendToWCHAR((char *)FileName, FS_MAX_SFN_NATIVE_FILE_NAME_LENGTH_B);
                  DirPos->ShortPos.Cluster = Pos->Cluster;
                  DirPos->ShortPos.Index = Pos->Index;
                  break;
               }
               HintDone = KAL_FALSE;
            }
            else //Kind = Available
               HintDone = KAL_FALSE;
ScanFindNextContinue:
            if(Kind != Lfn)
               LFNIndex = -1;
         }
         break;
      default:
         break;
      case XFINALLY:
         if (f) UnlockDevice(f->Dev);
         break;
   XEND_API
   return RTF_NO_ERROR;
}
#endif

/* ------------------------------------------------------------------------------- */
#ifdef __FS_CHECKDRIVE_SUPPORT__
/**************************************************
 *  __FS_CHECKDRIVE_SUPPORT__ feature
 *  Macros & Utilities For BIT MAP Operation
 **************************************************/

#define INLINE_CMPARE_CLUSTER_BIT(Cdata, Cluster)   \
        (Cluster >= Cdata->ClsOffset && Cluster <= Cdata->ClsRange)

#define INLINE_GET_CLUSTER_BIT(Cdata, Cluster)      \
        ((Cdata->ClusterMap[ (Cluster - Cdata->ClsOffset) / 8] & 1 << ((Cluster - Cdata->ClsOffset) % 8)) != 0)

#define INLINE_SET_CLUSTER_BIT(Cdata, Cluster)      \
        (Cdata->ClusterMap[ (Cluster - Cdata->ClsOffset) / 8] |= 1 << ((Cluster - Cdata->ClsOffset) % 8))

#define INLINE_CLEAR_CLUSTER_BIT(Cdata, Cluster)    \
        (Cdata->ClusterMap[ (Cluster - Cdata->ClsOffset) / 8] &= ~(1 << ((Cluster - Cdata->ClsOffset) % 8)))

static void Clear_ClusterMap_Chain(InternScanDataStruct *SDCD, RTFCluster Cluster, UINT Count)
{
   while (Count--)
   {
      if (INLINE_CMPARE_CLUSTER_BIT(SDCD, Cluster))
         INLINE_CLEAR_CLUSTER_BIT(SDCD, Cluster);
      Cluster = (SDCD->RAWCluster)(SDCD->Drive, Cluster);
      if ((Cluster < 2L) || (Cluster >= SDCD->Drive->Clusters))
         break;
   }
}

static void ScanRootDirFATChain(InternScanDataStruct *SDCD)
{
   // FAT32   Root Directory must marked
   if(SDCD->Drive->FATType == 32)
   {
      RTFCluster tmpCluster, nextCluster;

      tmpCluster = SDCD->Drive->FirstDirSector; /* Note that it's not sector number in FAT32 */

      do
      {
         nextCluster = (SDCD->RAWCluster)(SDCD->Drive, tmpCluster);

         if (INLINE_CMPARE_CLUSTER_BIT(SDCD, tmpCluster))
            INLINE_SET_CLUSTER_BIT(SDCD, tmpCluster);

         if (nextCluster >= 2L && nextCluster < SDCD->Drive->Clusters)
         {  /* Valid Cluster */
            tmpCluster = nextCluster;
            continue;
         }

         if (nextCluster < RTF_CLUSTER_CHAIN_END)
         {
            /* InValid Cluster , Truncate the FAT Chain */
            SetClusterValue(SDCD->Drive, tmpCluster, RTF_CLUSTER_CHAIN_END);
            return;
         }

      } while (nextCluster < RTF_CLUSTER_CHAIN_END);

   } /* if(SDCD->Drive->FATType == 32) */
}
#endif /* __FS_CHECKDRIVE_SUPPORT__ */

/* ------------------------------------------------------------------------------- */

#ifdef __FS_CHECKDRIVE_SUPPORT__
/**************************************************
 *  __FS_CHECKDRIVE_SUPPORT__ feature
 *  Second Level Procedures
 **************************************************/
static int IfFHEnough(void) //for CHECKDRIVE_SUPPORT ScanDirTree only
{
   int i, j = 0;
   RTFile * f = gFS_Data.FileTable;

   for (i=0; i<FS_MAX_FILES; i++, f++)
   {
      if ((f->Dev == NULL) && (f->Task == NULL))
         j++;
   }

   if (j)
      return j;
   return RTF_TOO_MANY_FILES;
}

static int ScanDirTree(InternScanDataStruct *SDCD)
{
   RTFHANDLE FHandle = 0;
   RTFHANDLE *HistoryFH = NULL;
   UINT i = 0;
   WCHAR *Filename1 = NULL, *Filename2 = NULL, *Filename3 = NULL;
   int idx = 0, Result = RTF_NO_ERROR;
   RTFDirEntry DirPos;
   RTFCluster C;
   RTFCluster FATClusters, DirClusters;

   HistoryFH = get_ctrl_buffer((FS_MAX_FILES)*4);
   if(HistoryFH == NULL)
   {
      Result = MT_FAIL_GET_MEM;
      return Result;
   }
   kal_mem_set(HistoryFH, 0, (FS_MAX_FILES)*4);

   Filename1 = get_ctrl_buffer(MT_MAX_WIDE_PATH);
   if(Filename1 == NULL)
   {
      Result = MT_FAIL_GET_MEM;
      goto ScanDirTreeReturn;
   }
   kal_mem_set(Filename1, 0, MT_MAX_WIDE_PATH);

   Filename2 = get_ctrl_buffer(MT_MAX_WIDE_PATH);
   if(Filename2 == NULL)
   {
      Result = MT_FAIL_GET_MEM;
      goto ScanDirTreeReturn;
   }
   kal_mem_set(Filename2, 0, MT_MAX_WIDE_PATH);

   Filename3 = get_ctrl_buffer(MT_MAX_WIDE_PATH);
   if(Filename3 == NULL)
   {
      Result = MT_FAIL_GET_MEM;
      goto ScanDirTreeReturn;
   }
   kal_mem_set(Filename3, 0, MT_MAX_WIDE_PATH);
   kal_wstrncpy((WCHAR *)Filename3, (WCHAR *)SDCD->Drive->CurrDir, 3); /* Scan From Root */

   ScanRootDirFATChain(SDCD); /* FAT32 Only */

   while(idx >= 0)
   {
ScanDirTreeFirst:
      Result = IfFHEnough() - 2 /* Reserve 2 file handle for concurrency */;
      if(Result < RTF_NO_ERROR)
      {
         Result = RTF_TOO_MANY_FILES;
         goto ScanDirTreeReturn;
      }

      kal_mem_set(Filename1, 0, MT_MAX_WIDE_PATH);
      if(kal_dchar_strlen((char *)Filename3) > RTF_MAX_PATH)
      {
         Result = MT_PATH_OVER_LEN_ERROR;
         goto ScanDirTreeReturn;
      }
      kal_wstrcpy((WCHAR *)Filename1, (WCHAR *)Filename3);
      kal_wstrcat((WCHAR *)Filename1, (WCHAR *)L"*");
      FHandle = ScanFindFirst((WCHAR *)Filename1, &DirPos);
      if(FHandle > 0)
      {
ScanDirTreeNext:
         while((Result = ScanFindNext(FHandle, (WCHAR *)Filename2, &DirPos)) == RTF_NO_ERROR)
         {
            if(g_CheckDrive == KAL_FALSE)
               goto ScanDirTreeReturn;

            if((!WFNamesMatch((char *)Filename2, (char *)dchar_dot)) &&
               (!WFNamesMatch((char *)Filename2, (char *)dchar_dot_dot)))
            {
               FATClusters = 0;
               SDCD->D = DirPos.Dir;
               C = FIRST_FILE_CLUSTER(SDCD->D);
               //Invalid cluster
               if(FileNameInvalid((const char *)SDCD->D.FileName) || (C == 1L) ||
                  (C >= SDCD->Drive->Clusters) ||
                  ((SDCD->D.Attributes & RTF_ATTR_DIR) && (C == 0)) )
               {
                  DelDirEntry(SDCD->Drive, &DirPos.LongPos, &DirPos.ShortPos);
                  goto ScanDirTreeNext;
               }
               if ((C != RTF_ROOT_DIR) && (C != 0))
               {
                  do
                  {
                     //Invalid cluster
                     if ((C < 2L) || (C >= SDCD->Drive->Clusters))
                     {
                        DelDirEntry(SDCD->Drive, &DirPos.LongPos, &DirPos.ShortPos);
                        goto ScanDirTreeNext;
                     }
                     //Cross link
                     if (INLINE_CMPARE_CLUSTER_BIT(SDCD, C) && INLINE_GET_CLUSTER_BIT(SDCD, C))
                     {
                        Clear_ClusterMap_Chain(SDCD, FIRST_FILE_CLUSTER(SDCD->D), FATClusters);
                        DelDirEntry(SDCD->Drive, &DirPos.LongPos, &DirPos.ShortPos);
                        ScanFATDelete(SDCD, FIRST_FILE_CLUSTER(SDCD->D));
                        Result = RTF_CHECKDISK_RETRY;
                        goto ScanDirTreeReturn;
                     }
                     else
                     //Set Bit
                     {
                        if (INLINE_CMPARE_CLUSTER_BIT(SDCD, C))
                           INLINE_SET_CLUSTER_BIT(SDCD, C);
                     }
                     FATClusters++;
                     C = (SDCD->RAWCluster)(SDCD->Drive, C);
                  } while (g_CheckDrive == KAL_TRUE && C < RTF_CLUSTER_CHAIN_END);

               }
               if((SDCD->D.Attributes & RTF_ATTR_DIR) == 0) //File
               {
                  DirClusters = (SDCD->D.FileSize > 0) ? ((SDCD->D.FileSize-1) / SDCD->Drive->ClusterSize) + 1 : 0;

                  //Size too small
                  if (FATClusters > DirClusters)
                  {
                     DelDirEntry(SDCD->Drive, &DirPos.LongPos, &DirPos.ShortPos);
                     Clear_ClusterMap_Chain(SDCD, FIRST_FILE_CLUSTER(SDCD->D), FATClusters);
                     ScanFATDelete(SDCD, FIRST_FILE_CLUSTER(SDCD->D)); /* Clear the chain */
                     goto ScanDirTreeNext;
                  }
                  //Size too large
                  else if (FATClusters < DirClusters)
                  {
                     DelDirEntry(SDCD->Drive, &DirPos.LongPos, &DirPos.ShortPos);
                     Clear_ClusterMap_Chain(SDCD, FIRST_FILE_CLUSTER(SDCD->D), FATClusters);
                     ScanFATDelete(SDCD, FIRST_FILE_CLUSTER(SDCD->D)); /* Clear the chain */
                     goto ScanDirTreeNext;
                  }
               }
               else //Folder
               {
                  #if defined(FS_CHECKDRIVE_SUPPORT_REMOVAL_DEEP_FOLDER)
                  /* Enable this option if you want to remove the folder that located in too deep level */
                  if(idx == (FS_MAX_FILES-2))
                  {
                     DelDirEntry(SDCD->Drive, &DirPos.LongPos, &DirPos.ShortPos);
                     Clear_ClusterMap_Chain(SDCD, FIRST_FILE_CLUSTER(SDCD->D), FATClusters);
                     ScanFATDelete(SDCD, FIRST_FILE_CLUSTER(SDCD->D)); /* Clear the chain */
                     goto ScanDirTreeNext;
                  }
                  #endif /* FS_CHECKDRIVE_SUPPORT_REMOVAL_DEEP_FOLDER */
                  kal_wstrcat((WCHAR *)Filename3, (WCHAR *)Filename2);
                  kal_wstrcat((WCHAR *)Filename3, (WCHAR *)L"\\");
                  HistoryFH[idx] = FHandle;
                  idx++;
                  goto ScanDirTreeFirst;
               }
            } /* If Not dot , dotdot */
         }

         if((Result != RTF_NO_MORE_FILES) && (Result < 0))
            goto ScanDirTreeReturn;
      }
      else /* (FHandle < 0) */
      {
         Result = FHandle;
         goto ScanDirTreeReturn;
      } /* End of ScanFindFrist */

      idx--;
      if(idx >= 0)
      {
         if(FHandle > 0)
         {
            RTFFindClose(FHandle);
         }
         FHandle = HistoryFH[idx];
         HistoryFH[idx] = 0;
         CdUp((WCHAR *)Filename3);
         goto ScanDirTreeNext;
      }
      else
         break;
   } /* while( idx >= 0) */

ScanDirTreeReturn:
   if(idx >= 0)
   {
      for(i = 0; i <= idx; i++)
      {
         if(HistoryFH[i] == 0) break;
         RTFFindClose(HistoryFH[i]);
      }
   }
   if(FHandle > 0)
   {
      RTFFindClose(FHandle);
   }
   if(Filename1) free_ctrl_buffer(Filename1);
   if(Filename2) free_ctrl_buffer(Filename2);
   if(Filename3) free_ctrl_buffer(Filename3);
   if(HistoryFH) free_ctrl_buffer(HistoryFH);

   if((Result != RTF_NO_MORE_FILES) && (Result < RTF_NO_ERROR))
      return Result;
   return RTF_NO_ERROR;
}

static void ChkLostClusters(InternScanDataStruct *SDCD)
{
   RTFCluster i, C;
   UINT State = 1;

   // mark up all free and bad clusters
   i = (SDCD->ClsOffset) ? SDCD->ClsOffset : 2;

   for (;g_CheckDrive == KAL_TRUE && i <= SDCD->ClsRange; i++)
   {
      if (!INLINE_GET_CLUSTER_BIT(SDCD, i))
      {
         C = (SDCD->RAWCluster)(SDCD->Drive, i);
         /* Free or Broken Cluster */
         if (C == 0 || C == RTF_BAD_CLUSTER)
         {
            INLINE_SET_CLUSTER_BIT(SDCD, i);
         }
         /**********************************************************************************
          * The strange cluster value should not happen during power lose.
          * There's many trade-off opinions on dealing with this.
          * Conclusion is, 3 policies applied on different cases,
          * 1) Leave it as-is , applied on system drive , RTFCheckDisk().
          *    Because Critial Application such as NVRAM will stop system when hit.
          * 2) EXT_fs_assert_local() , applied on public drive when in-house testing.
          *    To early detect error.
          * 3) Logging, warnning and clear , applied on public drive when production released.
          *    To achieve integrity of file system.
          ************************************************************ 2006/03/31 ***********/
         else if (C == 1 || C >= SDCD->Drive->Clusters)
         {
            // Policy 1: Leave it as-is
            // INLINE_SET_CLUSTER_BIT(SDCD, i);

            // Policy 2: fs_assert_local
            // Use fs_assert_local() to assert when in-house test only
            if ((SDCD->Drive->Dev->DeviceFlags & RTF_DEVICE_REMOVABLE) == 0 && (C < RTF_CLUSTER_CHAIN_END))
               fs_assert_local(0);

            // Policy 3: Clear it (Do nothing here)
            // There should be warning or trace here
         }
      }
   } /* for (;g_CheckDrive == KAL_TRUE && i <= SDCD->ClsRange; i++) */

   // look for unmarked areas
   C = 0;
   i = (SDCD->ClsOffset) ? SDCD->ClsOffset : 2;
   for (;g_CheckDrive == KAL_TRUE && i <= SDCD->ClsRange; i++)
   {
      if (State != INLINE_GET_CLUSTER_BIT(SDCD, i))
      {
         if (State == 0) // end of a lost chain
         {
            RTFCluster j;
            for (j=0; j < C; j++)
               SetClusterValue(SDCD->Drive, j+i-C, 0);
         }
         State = !State;
         C = 0;
      }
      C++;
   }
}
#endif /* __FS_CHECKDRIVE_SUPPORT__ */

/* ------------------------------------------------------------------------------- */

#ifdef __FS_CHECKDRIVE_SUPPORT__
/**************************************************
 *  __FS_CHECKDRIVE_SUPPORT__ feature
 *  Utilities For Dirve Specific Operation
 **************************************************/
/*
 * ChkMonopolizeDrive()
 *  To get exclusion control on specific drive.
 *  check if any opening file handle on this drive,
 */
static void ChkMonopolizeDrive(RTFDrive * Drive)
{
   int i;
   RTFile * f;

   //Lock RTF and device before calling this function
   for (i=0, f = gFS_Data.FileTable; i<FS_MAX_FILES; i++, f++)
   {
      if ((f->Lock != 0) && (f->Drive == Drive))
      {
         fs_util_trace_err_noinfo(RTF_ACCESS_DENIED);
         fs_util_trace_info2(TRACE_ERROR | MT_TRACE_INFO_TASK, FS_ERR_ACCESS_DENIED, f->OwnerLR, GetFileHandle(f), f);

         XRAISE(RTF_ACCESS_DENIED);
      }
   }
   //should not unlock here
}

static void ScanFATDelete(InternScanDataStruct *SDCD, RTFCluster Cluster)
{
   RTFCluster NextCluster;

   while (g_CheckDrive == KAL_TRUE && Cluster < RTF_CLUSTER_CHAIN_END)
   {
      NextCluster = (SDCD->RAWCluster)(SDCD->Drive, Cluster);
      SetClusterValue(SDCD->Drive, Cluster, 0);
      Cluster = NextCluster;
   }
}
#endif /* __FS_CHECKDRIVE_SUPPORT__ */

static RTFCluster ScanFAT12_GetRAWClusterValue(RTFDrive *Drive, RTFCluster Cluster)
{
   return fs_srv_get_cluster_value(Drive, Cluster, FS_GET_CLUSTER_RAW, GetBuffer);
}

static RTFCluster ScanFAT16_GetRAWClusterValue(RTFDrive *Drive, RTFCluster Cluster)
{
   return fs_srv_get_cluster_value(Drive, Cluster, FS_GET_CLUSTER_RAW, GetBuffer);
}

static RTFCluster ScanFAT32_GetRAWClusterValue(RTFDrive *Drive, RTFCluster Cluster)
{
   return fs_srv_get_cluster_value(Drive, Cluster, FS_GET_CLUSTER_RAW, GetBuffer);
}

/* ------------------------------------------------------------------------------- */

#ifdef __FS_CHECKDRIVE_SUPPORT__
/**************************************************
 *  __FS_CHECKDRIVE_SUPPORT__ feature
 *  Main Procedure
 **************************************************/
int ScanDrive(RTFDrive * Drive, void * Buffer, unsigned int BufferLen)
{
   InternScanDataStruct SDCD;
   int volatile Result = RTF_NO_ERROR;
   RTFDirEntry Root;

   /* ScanDrive - 1. Setup Scan-Disk-Control-Data */
   SDCD.Drive      = Drive;
   SDCD.ClusterMap = (BYTE*) Buffer;
   SDCD.ClsSpan    = (BufferLen - 1) * 8;

   XTRY
      case XCODE:
         /* ScanDrive - 2. Lock Device, and exclusion access check */
         SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Drive->Dev, RTF_INFINITE);
         ChkMonopolizeDrive(Drive);

         /* ScanDrive - 3. Hook the Function Pointer to do faster GetClusterValue() */
         switch (Drive->FATType)
         {
            case 12:   SDCD.RAWCluster = ScanFAT12_GetRAWClusterValue; break;
            case 16:   SDCD.RAWCluster = ScanFAT16_GetRAWClusterValue; break;
            case 32:   SDCD.RAWCluster = ScanFAT32_GetRAWClusterValue; break;
            default:
            {
               fs_assert_local(0);
            }
         }

         /* ScanDrive - 4. Build Recursive initial Data */
ScanDriveAgain:
         SDCD.ClsOffset  = 0;

ScanDriveNextIterative:
         SDCD.ClsRange   = SDCD.ClsOffset + SDCD.ClsSpan;
         if (SDCD.ClsRange > Drive->Clusters)
         {
            SDCD.ClsRange = Drive->Clusters;
         }

         MakePseudoRootDirEntry(Drive, &Root);
         SDCD.D = Root.Dir;

         kal_mem_set(SDCD.ClusterMap, 0, SDCD.ClsSpan / 8 + 1);

         /* ScanDrive - 5. Detail Scan by Root Directory */
         Result = ScanDirTree(&SDCD);
         if (Result == RTF_CHECKDISK_RETRY)
         {
            goto ScanDriveAgain;
         }
         else if (Result < RTF_NO_ERROR)
         {
            fs_util_trace_err_noinfo(Result);

            XRAISE(Result);
         }

         ChkLostClusters(&SDCD);
         FlushAllBuffers(SDCD.Drive->Dev);

         if (SDCD.ClsRange < Drive->Clusters)
         {
            SDCD.ClsOffset = SDCD.ClsRange;
            goto ScanDriveNextIterative;
         }

         break;
      default:
         Result = XVALUE;
         break;
      case XFINALLY:
         SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV);
         break;
   XEND_API
   return Result;
}
#endif /* __FS_CHECKDRIVE_SUPPORT__ */
/* ------------------------------------------------------------------------------- */

/**************************************************
 *  Recursive Folder Traverse Engine
 *  Members:
 *          RecTravStart
 *          RecTravClose
 *          RecTravNextFolder
 *          RecTravBackward
 *          RecTravDownLevel
 *          RecTravUpLevel
 **************************************************/

/* Note: Usage Sample C:\ABC\* , must be end with star */
const static WCHAR dchar_backslash_star_postfix[] = /* \* */ { 0x005c, 0x002a, 0x0000};
RTFHANDLE RecTravStart(WCHAR * PathNamePattern)
{
   int volatile Result;
   RTFile * volatile f = NULL;
   RTFDirLocation * Pos;
   BYTE * volatile A;
   BYTE Attr = 0, AttrMask = 0;

   XTRY
      case XCODE:
         f = ParseFileName((char *)PathNamePattern);
         if (f->SpecialKind != NormalFile)
            XRAISE(RTF_INVALID_FILENAME);

         f->Flags = RTF_OPEN_DIR | RTF_READ_ONLY | RTF_CACHE_DATA;

         if(SearchFile(f, SEARCH_PARENT, (char *)PathNamePattern, NULL)) // search a file or a direcotry
         {
            // PathNamePattern is a file, and found !
            XRAISE(RTF_PARAM_ERROR);
         }
         // else we found the parent

         InitFilePointer(f);

         A    = (void*) &f->LastCluster;
         Pos  = (void*) &f->Cluster;
         Pos->Index--;

         Attr = RTF_ATTR_DIR; /* Folder Only */
         A[0] = Attr;
         A[1] = AttrMask | Attr;

         Result = MakeNewFileHandle(f);

         break;
      default:
         Result = XVALUE;
         break;
      case XFINALLY:
         if (f != NULL)
         {
            if (Result < RTF_NO_ERROR)
               FreeFTSlotAndDevice(f);
            else
               UnlockDevice(f->Dev);
         }
         break;
   XEND_API

   return Result;
}

int RecTravClose(RTFHANDLE Handle)
{
   return RTFClose(Handle);
}

static int RecTravNextFolder(RTFHANDLE Handle, WCHAR * FileName, RTFDirEntry * DirPos)
{
   BYTE CheckSum = 0;
   int LFNIndex = -1;
   RTFile * volatile f = NULL;
   const WCHAR * NamePattern;
   RTFDirLocation * Pos;
   kal_bool HintDone = KAL_FALSE;
   BYTE * A;

#ifdef __EFS_DEBUG__
   fs_assert_local(DirPos != NULL && FileName != NULL);
#endif /* __EFS_DEBUG__ */
   kal_mem_set(DirPos, 0, sizeof(RTFDirEntry));

   XTRY
      case XCODE:
         f = ParseFileHandle(Handle);

         if (f->SpecialKind != NormalFile)
         {
            XRAISE(RTF_INVALID_FILE_HANDLE);
         }

         if ((f->DirEntry.Dir.Attributes & RTF_ATTR_DIR) == 0)
         {
            XRAISE(RTF_INVALID_FILE_HANDLE);
         }

         if (f->Valid == FS_FH_ABORTED)
         {
            fs_util_trace_err_noinfo(MT_ABORTED_ERROR);

            XRAISE(MT_ABORTED_ERROR);
         }

         NamePattern = kal_wstrrchr((WCHAR*)f->FullName, 0x005c);
         A           = (void*) &f->LastCluster;
         Pos         = (void*) &f->Cluster;

        /*
         * normally FirstCluster should not be 0. Raise FS_BAD_DIR_ENTRY if it is. (W11.11)
         */

        if (Pos->Cluster == 0)
        {
            fs_util_trace_err_noinfo(FS_BAD_DIR_ENTRY);
            fs_util_trace_info0(TRACE_ERROR | MT_TRACE_INFO_WSTR, FS_INFO_DISK_ERROR, FileName);
            XRAISE(FS_BAD_DIR_ENTRY);  // [debug]
        }

         /*
          * Before W10.22, NamePattern must be end with "\\*"
          * if (kal_wstrcmp(NamePattern, dchar_backslash_star_postfix) != 0) XRAISE(RTF_PARAM_ERROR)
          *
          * Remove this limitation because if f->FullName will exceeds RTF_MAX_PATH after appending "\\*",
          * SearchFile() in RecTravStart() will not append "\\*" in f->FullName. For extreme case, FS_PARAM_ERROR
          * will be returned add TravCB->TravStatus will be assigned as FS_PARAM_ERROR. Then recursive operation
          * may be successful but return a error code. (W10.22 / Stanley Chu)
          */

         if (kal_wstrcmp(NamePattern, dchar_backslash_star_postfix) != 0 || A[0] != RTF_ATTR_DIR)
         {
            fs_util_trace_err_noinfo(RTF_PARAM_ERROR);

            XRAISE(RTF_PARAM_ERROR);
         }

         while (1)
         {
            int Kind;
            const RTFDOSDirEntry * D = NextDir(f->Drive, Pos);

            if(D == NULL)
            {
               XRAISE(RTF_NO_MORE_FILES);
            }

            Kind = EntryType(D);

            if(Kind == NeverUsed)
            {
               XRAISE(RTF_NO_MORE_FILES);
            }
            else if(Kind == Lfn)
            {
               const LFNDirEntry * LD = (void*) D;

               if(HintDone == KAL_FALSE)
               {
                  HintDone = KAL_TRUE;
                  DirPos->LongPos.Cluster = Pos->Cluster;
                  DirPos->LongPos.Index = Pos->Index;
               }

               if(LD->Ord & 0x40)
               {
                  char * Limit;
                  LFNIndex = LD->Ord & 0x3F;
                  CheckSum = LD->CheckSum;

                  Limit = ( (char *)FileName) + ((LFNIndex-1)*13*2 + 2*LFNCharCount(LD) );
                  if(Limit > ( ((char *)FileName) + RTF_MAX_PATH - 1))
                      LFNIndex = -2;
                  else
                  {
                     Limit[0] = '\0';
                     Limit[1] = '\0';
                  }
               }
               if((LD->CheckSum != CheckSum) || (LFNIndex != (LD->Ord & 0x3F)) || (LFNIndex <= 0))
                  LFNIndex = -2;
               else
                  CopyLFN((char *)FileName + --LFNIndex * 26, LD);
            }
            else if((Kind == InUse) && ((D->Attributes & A[1]) == A[0]))
            {
               DirPos->Dir = *D;
               DirPos->DirCluster = FIRST_FILE_CLUSTER(f->DirEntry.Dir);

               // try LFN first
               if((LFNIndex == 0) &&
                  (CheckSum== ShortNameCheckSum((BYTE*) D->FileName)) ) // Note: Name Match not requeired
               {
                  /* Now found one that with LFN & SFN */
                  DirPos->ShortPos.Cluster = Pos->Cluster;
                  DirPos->ShortPos.Index = Pos->Index;
                  break;
               }

               // try short name
               if ((D->FileName[0] != 0x2e) /* skip dot or dot-dot */ &&
                   (MakeShortFileName(D, (char *)FileName, RTF_MAX_PATH) == RTF_NO_ERROR))
               {
                  /* Now found one that with SFN only */
                  if (D->FileName[0] == 0x05)
                  {
                     FileName[0] = 0xE5;
                  }

                  FileNameExtendToWCHAR((char *)FileName, FS_MAX_SFN_NATIVE_FILE_NAME_LENGTH_B);
                  MTCheckFileNameCase(FileName, RTF_MAX_PATH, D->NTReserved);

                  DirPos->ShortPos.Cluster = Pos->Cluster;
                  DirPos->ShortPos.Index = Pos->Index;
                  break;
               }
               HintDone = KAL_FALSE;
            }
            else
               HintDone = KAL_FALSE;
            if(Kind != Lfn)
               LFNIndex = -1;
         }
         break;
      default:
         break;
      case XFINALLY:
         if (f) UnlockDevice(f->Dev);
         break;
   XEND_API
   return RTF_NO_ERROR;
}

/**********************************************************
 * RecTravDownLevel   ---- implement for fast
 *    f:            The File Table Pointer
 *    SaveDirInfo:  The Current DirPos to be Saved
 *    NewDirInfo :  The Down Level DirPos to be Setup
 *    FolderName :  The Folder Name to be append on
 *
 **********************************************************/
static int RecTravDownLevel(RTFile *f, RTFDirEntry *SaveDirInfo, RTFDirEntry *NewDirInfo, WCHAR *FolderName)
{
   WCHAR * NamePtr;
   RTFDirLocation * Pos;
   unsigned int NameLen;
   int result = RTF_NO_ERROR;

#ifdef __EFS_DEBUG__
   fs_assert_local(SaveDirInfo != NULL && NewDirInfo != NULL);
   fs_assert_local(FolderName != NULL);
#endif /* __EFS_DEBUG__ */
   RTFSYSLockMutex(RTFLock, RTF_INFINITE);

   // Now save and swap the directory Entry information
   memcpy(SaveDirInfo, &(f->DirEntry), sizeof(RTFDirEntry));
   memcpy(&(f->DirEntry), NewDirInfo,  sizeof(RTFDirEntry));

   // Reset position information
   Pos  = (void*) &f->Cluster;
   Pos->Cluster = FIRST_FILE_CLUSTER(f->DirEntry.Dir);
   Pos->Index   = (UINT)-1;

   // Update f->FullName , string process
   NamePtr = kal_wstrrchr((WCHAR*) f->FullName, 0x005c);
   NameLen = kal_wstrlen(FolderName);

   if ((NamePtr - (WCHAR*)f->FullName) + 1 /* Length of f->FullName including the last '\' */ + NameLen >= MT_MAXPATH_IN_WCHAR_UNIT)
   {
      result = MT_PATH_OVER_LEN_ERROR;
   }
   else
   {
      kal_wstrncpy(++NamePtr, FolderName, NameLen);                  // append folder name
      kal_wstrcpy (NamePtr+NameLen, dchar_backslash_star_postfix);   // append "\*"
   }

   RTFSYSFreeMutex(RTFLock);

   return result;
}

/**********************************************************
 * RecTravUpLevel   ---- implement for fast
 *    f:            The File Table Pointer
 *    UpDirInfo:  The Current DirPos to be Saved
 *
 **********************************************************/
static void RecTravUpLevel(RTFile *f, RTFDirEntry *UpDirInfo)
{
   WCHAR * NamePtr;
   RTFDirLocation * Pos;

#ifdef __EFS_DEBUG__
   fs_assert_local(UpDirInfo != NULL);
#endif /* __EFS_DEBUG__ */
   RTFSYSLockMutex(RTFLock, RTF_INFINITE);

   // Now clear position information, shift directory information as position information
   Pos  = (void*) &f->Cluster;
   Pos->Cluster = f->DirEntry.ShortPos.Cluster;
   Pos->Index   = f->DirEntry.ShortPos.Index;

   // Reload the Directory info
   memcpy(&(f->DirEntry), UpDirInfo,  sizeof(RTFDirEntry));

   // Update f->FullName , string process
   NamePtr = kal_wstrrchr((WCHAR*) f->FullName, 0x005c);
   NamePtr[0] = 0x0;

   NamePtr = kal_wstrrchr((WCHAR*) f->FullName, 0x005c);
   kal_wstrcpy(NamePtr, dchar_backslash_star_postfix);

   RTFSYSFreeMutex(RTFLock);
}

/**********************************************************
 * RecTravUpLevelAndBackward   ---- implement for fast
 *    f:          The File Table Pointer
 *    UpDirInfo:  The Current DirPos to be Saved, and set back to reterive name again
 *
 **********************************************************/
static void RecTravUpLevelAndBackward(RTFile *f, RTFDirEntry *UpDirInfo)
{
   WCHAR * NamePtr;
   RTFDirLocation * Pos;

#ifdef __EFS_DEBUG__
   fs_assert_local(UpDirInfo != NULL);
#endif /* __EFS_DEBUG__ */
   RTFSYSLockMutex(RTFLock, RTF_INFINITE);

   // Now clear position information, shift directory information as position information
   // But, set back to the parent entry
   Pos  = (void*) &f->Cluster;
   if (f->DirEntry.LongPos.Cluster != 0)
   {
      Pos->Cluster= f->DirEntry.LongPos.Cluster;
      Pos->Index  = f->DirEntry.LongPos.Index - 1;
   }
   else
   {
      Pos->Cluster= f->DirEntry.ShortPos.Cluster;
      Pos->Index  = f->DirEntry.ShortPos.Index - 1;
   }

   // Reload the Directory info
   memcpy(&(f->DirEntry), UpDirInfo,  sizeof(RTFDirEntry));

   // Update f->FullName , string process
   NamePtr = kal_wstrrchr((WCHAR*) f->FullName, 0x005c);
   NamePtr[0] = 0x0;

   NamePtr = kal_wstrrchr((WCHAR*) f->FullName, 0x005c);
   kal_wstrcpy(NamePtr, dchar_backslash_star_postfix);

   RTFSYSFreeMutex(RTFLock);
}

/* ------------------------------------------------------------------------------- */

/**************************************************
 *  Recursive Directroy Tree Traverse Core
 *  Members:
 *          RecTravCore_DFS
 *          RecTravCore_BFS
 *          RecTravCore_Flat
 *          RecTravCore_CloseAndRootNodeAct
 *          RecTravCore_DFS_CR
 **************************************************/
/**************************************************
 * Structure Member Required
 * TravFH     --- The FileHandle To Get Next Folder
 * MyCallBack --- The CallBack To Process Found Item
 * NameBuf
 * LevelStack
 * ListFH --- The FileHandle To Get File In Current Level
 **************************************************/

void RecTravCore_DFS(InternRecursiveEngineStruct *TravCB, RTFHANDLE TravFH, MTGenericCallBack *Act)
{
   RTFHANDLE   ListFH;
   int         LevelIdx=0;
   RTFDirEntry TmpDirPos;

#ifdef __EFS_DEBUG__
   UINT        U = TravFH >> (4*sizeof(int));
#endif /* __EFS_DEBUG__ */
   UINT        i = TravFH & ((1 << (4*sizeof(int))) - 1);
   RTFile*     fp;

   int         TravResult, ActResult;
   WCHAR*      NamePtr;
   int         MaxLength; // for FS_Count() enhancement
   int         attr_mask;

   if (Act == RecAct_CountNum)
   {
      MaxLength = 8 + 3 + 1 + 1; // We only need sufficient length for SFN to skipped LFN handling in RTFFindNextEx() to save time

      #ifdef __FS_OPEN_HINT__
      MaxLength |= MT_HINT_DISABLE;
      #endif
   }
   else
   {
      MaxLength = RTF_MAX_PATH;
   }

   fp = gFS_Data.FileTable + i;

   #ifdef __EFS_DEBUG__
   fs_assert_local(fp->Unique == U && i < FS_MAX_FILES && fp->Lock != 0 && fp->Dev != NULL);
   fs_assert_local(Act != NULL && TravCB->NameBuf != NULL);
   #endif /* __EFS_DEBUG__ */

   do
   {
      /*-- DFS 0 -------------------------------------------
       * Setup current folder.
       *----------------------------------------------------*/

      /*
       * Prepare TravCB->CurrPath and TravCB->CurrLeftLen.
       * Here we want TravCB->CurrPath to be like "X:\\A\\TARGET_FOLDER\\" for Act()
       *
       * The input fp->FullName must be like X:\\A\\TARGET_FOLDER\\*
       */

      kal_wstrcpy(TravCB->CurrPath, (WCHAR*) fp->FullName);

      RecConf_MemoryChecker(&TravCB);   // for debug (check name buffer guard pattern)

      TravResult = kal_wstrlen(TravCB->CurrPath);  // borrow TravResult as length of CurrPath
      NamePtr = TravCB->CurrPath + TravResult - 1; // NamePtr is the last WCHAR just before tailed NULL

      // calculate CurrLeftLen
      if ('*' == *NamePtr && '\\' == *(NamePtr - 1))
      {
         TravCB->CurrLeftLen = 1 /* preserve space for '\0' */ + (TravResult - 1) /* length of CurrPath - '*' */;

         if (TravCB->CurrLeftLen < MT_MAXPATH_IN_WCHAR_UNIT)
            TravCB->CurrLeftLen = MT_MAXPATH_IN_WCHAR_UNIT - TravCB->CurrLeftLen;
         else
            TravCB->CurrLeftLen = 0;

         *NamePtr = '\0';  // remove '*'
      }
      else
      {
         TravCB->TravStatus = RTF_PARAM_ERROR;
         return;
      }

      if (TravCB->Parameters.Flag & FS_RECURSIVE_TYPE) // DFS
      {
          attr_mask = RTF_ATTR_DIR;
      }
      else  // flat
      {
          attr_mask = 0;
          goto RecTravCoreFlat;
      }

      /*-- DFS 1 --------------------------------------------------------------------------------
       * Find a folder in current folder.
       * If found, enter it (go to next level), then back to DFS 0 to start a new traverse in next level.
       * If not found, do ACT for all files, go back to upper layer,
       *-----------------------------------------------------------------------------------------*/

      /*----------------------------------------------------------------------------
       * TmpDirPos reserves the position of (1st LFN entry if existed and) SFN entry found
       * fp->Cluster and fp->Offset reserves the position of SFN entry found
       * TravCB->NameBuf stores the file (folder) name only.
       *----------------------------------------------------------------------------*/
      TravResult = RecTravNextFolder(TravFH, TravCB->NameBuf, &TmpDirPos);

      RecConf_MemoryChecker(&TravCB);   // for debug (check name buffer guard pattern)

      if (TravResult == RTF_NO_ERROR) // 1 folder found
      {
         if (LevelIdx == TravCB->LevelLimit) // The directory tree is too deep to reach, fail
         {
            TravCB->TravStatus = RTF_TOO_MANY_FILES;
            break;
         }

         if (kal_wstrlen(TravCB->NameBuf) > TravCB->CurrLeftLen)
         {
            // The Path Length over Spec. definiation , reserve \\ , * , and \0
            TravCB->TravStatus = MT_PATH_OVER_LEN_ERROR;
            break;
         }

         // abort watching in XDelete case (check abort flag whenever a folder is found)
         if ((TravCB->Parameters.Flag & FS_XDEL_ABORT_WATCH) && (g_Xdelete != KAL_TRUE))
         {
            TravCB->Parameters.ErrorCode = MT_ABORTED_ERROR;
            break;
         }

         /* store f->DirEntry to LevelStack, goto DFS 0 to start a new traverse in next level. */
         ActResult = RecTravDownLevel(fp, TravCB->LevelStack + LevelIdx, &TmpDirPos, TravCB->NameBuf);

         if (ActResult < RTF_NO_ERROR) // path over len
         {
            TravCB->TravStatus = MT_PATH_OVER_LEN_ERROR;
            break;
         }

         LevelIdx++;

         continue;
      }
      else if (TravResult == FS_NO_MORE_FILES || TravResult == FS_BAD_DIR_ENTRY) // No more folder, List all Files [debug]
      {
        int ListResult;

        /*
         * RecTravNextFolder may return TravResult = FS_BAD_DIR_ENTRY if the FirstCluster of current folder is 0.
         * For this case, ignore file listing and go delete current folder directly. (W11.11)
         */

        if (TravResult == FS_NO_MORE_FILES)
        {
            /* reset start position for listing all files */
            kal_mem_set(&TmpDirPos, 0, sizeof(RTFDirEntry));

RecTravCoreFlat:

            ListFH = RTFFindFirstEx((WCHAR *)fp->FullName, 0, attr_mask, &(TmpDirPos.Dir), TravCB->NameBuf, MaxLength, NULL, TravCB->CallerAddress); // search once inside

            if (ListFH < 0)   ListResult = ListFH;
            else              ListResult = RTF_NO_ERROR;

            while (ListResult == RTF_NO_ERROR)
            {
                /* do ACT for each file */
                ActResult = Act(TravCB, TravCB->NameBuf , &(TmpDirPos.Dir) /* File */); // search once inside

                if (ActResult < RTF_NO_ERROR)
                {
                    // path over len or operation abort indication
                    ListResult = ActResult;

                    if(TravCB->Parameters.ErrorCode == MT_ABORTED_ERROR)
                    {
                        ListResult = MT_ABORTED_ERROR;
                        break;
                    }

                    continue;
                }

                ListResult = RTFFindNextEx(ListFH, &(TmpDirPos.Dir), TravCB->NameBuf, MaxLength, NULL);
            }

            RTFFindClose(ListFH);

            if ((TravCB->Parameters.Flag & FS_RECURSIVE_TYPE) == 0) // flat
            {
                if (ListResult == RTF_NO_MORE_FILES) // No more folder, No more files
                {
                    TravCB->TravStatus = RTF_NO_ERROR;
                }
                else // Error Handle of Flat
                {
                    TravCB->TravStatus = ListResult;
                }

                break;  // leave this routine (do-while-loop)
            }
        }
        else    // FS_BAD_DIR_ENTRY
        {
            // treat TravResult == FS_BAD_DIR_ENTRY as ListResult = FS_NO_MORE_FILES to delete the current folder below (W11.11)

            ListResult = FS_NO_MORE_FILES;
        }

         if (ListResult == FS_NO_MORE_FILES) // No more folder, No more files
         {
            if (LevelIdx-- > 0)
            {
               RecTravUpLevelAndBackward(fp, TravCB->LevelStack + LevelIdx);

               // update current folder
               kal_wstrcpy(TravCB->CurrPath, (WCHAR*) fp->FullName);

               RecConf_MemoryChecker(&TravCB); // for debug (check name buffer guard pattern)

               NamePtr = kal_wstrrchr(TravCB->CurrPath, 0x005c);
               *(++NamePtr) = 0x0;

               TravCB->CurrLeftLen = MT_MAXPATH_IN_WCHAR_UNIT - 1 /* preserve space for '\0' */ - (NamePtr - TravCB->CurrPath) /* kal_wstrlen(TravCB->CurrPath) */;

               // Reterieve the folder name
               TravResult = RecTravNextFolder(TravFH, TravCB->NameBuf, &TmpDirPos);

               #ifdef __EFS_DEBUG__
               // Double Check
               fs_assert_local(TravResult == RTF_NO_ERROR);
               #endif /* __EFS_DEBUG__ */

               // Act
               ActResult = Act(TravCB, TravCB->NameBuf , &(TmpDirPos.Dir) /* Folder */);

               // path over len or operation abort indication
               if (ActResult < RTF_NO_ERROR)
               {
                  ListResult = ActResult;
                  goto DFS_LIST_ERROR;
               }
            }
            continue;
         }
DFS_LIST_ERROR:
         TravCB->TravStatus = ListResult;
         break;
      }
      else /* DFS_TRAV_ERROR: */
      {
         TravCB->TravStatus = TravResult;
         break;
      }
   } while (LevelIdx >= 0);
}

void RecTravCore_BFS(InternRecursiveEngineStruct *TravCB, RTFHANDLE TravFH, MTGenericCallBack *Act)
{
   RTFHANDLE   ListFH;
   int         LevelIdx=0;
   RTFDirEntry TmpDirPos;
#ifdef __EFS_DEBUG__
   UINT        U = TravFH >> (4*sizeof(int));
#endif /* __EFS_DEBUG__ */
   UINT        i = TravFH & ((1 << (4*sizeof(int))) - 1);
   RTFile*     fp;
   int         ListResult;
   int         ActResult;
   WCHAR*      NamePtr;
   int         MaxLength; // for FS_Count() enhancement

   if (Act == RecAct_CountNum)
   {
      MaxLength = 8 + 3 + 1 + 1; // We only need sufficient length for SFN to skipped LFN handling in RTFFindNextEx() to save time

      #ifdef __FS_OPEN_HINT__
      MaxLength |= MT_HINT_DISABLE;
      #endif
   }
   else
      MaxLength = RTF_MAX_PATH;

   fp = gFS_Data.FileTable + i;

   #ifdef __EFS_DEBUG__
   fs_assert_local(fp->Unique == U && i < FS_MAX_FILES && fp->Lock != 0 && fp->Dev != NULL);
   fs_assert_local(Act != NULL && TravCB->NameBuf != NULL);
   #endif /* __EFS_DEBUG__ */

   do
   {
      /*-- BFS 0 -------------------------------------------
       * Setup current folder.
       *----------------------------------------------------*/

      kal_wstrcpy(TravCB->CurrPath, (WCHAR*) fp->FullName);
      NamePtr = kal_wstrrchr(TravCB->CurrPath, 0x005c);
      *(++NamePtr) = 0x0;  // remove tailed '*'

      // now TravCB->CurrPath is like "X:\\ABC\\"

      TravCB->CurrLeftLen = 1 /* preserve space for '\0' */ + kal_wstrlen(TravCB->CurrPath) /* length of CurrPath ('*' was removed above) */;

      if (TravCB->CurrLeftLen < MT_MAXPATH_IN_WCHAR_UNIT)
         TravCB->CurrLeftLen = MT_MAXPATH_IN_WCHAR_UNIT - TravCB->CurrLeftLen;
      else
         TravCB->CurrLeftLen = 0;

      /*-- BFS 1  ------------------------------------------
       * Traverse all files in current folder.
       *----------------------------------------------------*/

      /* Use another handle allocated by RTFFindFirstEx to list all files */
      ListFH = RTFFindFirstEx((WCHAR *)fp->FullName, 0, RTF_ATTR_DIR, &(TmpDirPos.Dir), TravCB->NameBuf, MaxLength, NULL, TravCB->CallerAddress);

      if (ListFH < 0)   ListResult = ListFH;
      else              ListResult = RTF_NO_ERROR;

      while (ListResult == RTF_NO_ERROR)
      {
         ActResult = Act(TravCB, TravCB->NameBuf , &(TmpDirPos.Dir) /* File */);

         if (ActResult < RTF_NO_ERROR)
         {  // path over len or operation abort indication
            ListResult = ActResult;
            if(TravCB->Parameters.ErrorCode==MT_ABORTED_ERROR)
            {
                ListResult = MT_ABORTED_ERROR;
                break;
            }
            continue;
         }

         ListResult = RTFFindNextEx(ListFH, &(TmpDirPos.Dir), TravCB->NameBuf, MaxLength, NULL);
      }

      RTFFindClose(ListFH);

      /*-- BFS 2 ----------------------------------------------------------------------
       * Find a folder in current folder, then enter it and goto BFS 0.
       * If no more folder, back to upper level and find next folder in upper level.
       *-------------------------------------------------------------------------------*/

      if (ListResult == RTF_NO_MORE_FILES) // No more files, Trav Next Folder
      {
         int TravResult;

BFS_PREV_LEVEL:

	     /* find next folder (attribute DIR and mask were properly set by RecTravStart) */
         TravResult = RecTravNextFolder(TravFH, TravCB->NameBuf, &TmpDirPos);

         if (TravResult == RTF_NO_ERROR) // 1 folder found
         {
            ActResult = Act(TravCB, TravCB->NameBuf , &(TmpDirPos.Dir) /* Folder */);

            if (ActResult < RTF_NO_ERROR) // path over len or operation abort indication
            {
               ListResult = ActResult;
               goto BFS_LIST_ERROR;
            }

            /*---------------------------------------------------------------------
             * We have no memory to store current layer's information for going to next level, break!
             * Note that all files in current level have been processed!
             *---------------------------------------------------------------------*/
            if (LevelIdx == TravCB->LevelLimit)
            {
               TravCB->TravStatus = RTF_TOO_MANY_FILES;
               break;
            }

            if (kal_wstrlen(TravCB->NameBuf) > TravCB->CurrLeftLen)
            {
               // The Path Length over Spec. definiation
               TravCB->TravStatus = MT_PATH_OVER_LEN_ERROR;
               break;
            }

            /* save current layer's information and go to next level */
            ActResult = RecTravDownLevel(fp, TravCB->LevelStack + LevelIdx, &TmpDirPos, TravCB->NameBuf);

            if (ActResult < RTF_NO_ERROR) // path over len
            {
               TravCB->TravStatus = MT_PATH_OVER_LEN_ERROR;
               break;
            }

            LevelIdx++;

            /* back to BFS 0 to start a traverse in next level */
            continue;
         }
         else if (TravResult == RTF_NO_MORE_FILES) // No more files, No more folders
         {
            if (LevelIdx-- > 0)
            {
               RecTravUpLevel(fp, TravCB->LevelStack + LevelIdx);
               kal_wstrcpy(TravCB->CurrPath, (WCHAR*) fp->FullName);
               NamePtr = kal_wstrrchr(TravCB->CurrPath, 0x005c);
               *(++NamePtr) = 0x0;
               TravCB->CurrLeftLen = MT_MAXPATH_IN_WCHAR_UNIT - kal_wstrlen(TravCB->CurrPath) - 1;
               goto BFS_PREV_LEVEL;
            }
            continue;
         }
/* BFS_TRAV_ERROR: */
         TravCB->TravStatus = TravResult;
         break;
      }
BFS_LIST_ERROR:
      TravCB->TravStatus = ListResult;
      break;
   } while (LevelIdx >= 0);
}

void RecTravCore_Flat(InternRecursiveEngineStruct *TravCB, RTFHANDLE TravFH, MTGenericCallBack *Act)
{
   RTFHANDLE   ListFH;
   RTFDirEntry TmpDirPos;

#ifdef __EFS_DEBUG__
   UINT        U = TravFH >> (4*sizeof(int));
#endif /* __EFS_DEBUG__ */
   UINT        i = TravFH & ((1 << (4*sizeof(int))) - 1);
   RTFile*     fp;

   int         ListResult = RTF_NO_ERROR;
   int         ActResult;
   WCHAR*      NamePtr;
   int         MaxLength;

   fp = gFS_Data.FileTable + i;

   #ifdef __EFS_DEBUG__
   fs_assert_local(fp->Unique == U && i < FS_MAX_FILES && fp->Lock != 0 && fp->Dev != NULL);
   fs_assert_local(Act != NULL && TravCB->NameBuf != NULL);
   #endif /* __EFS_DEBUG__ */

   // setup current folder
   kal_wstrcpy(TravCB->CurrPath, (WCHAR*) fp->FullName);
   NamePtr = kal_wstrrchr(TravCB->CurrPath, 0x005c);
   *(++NamePtr) = 0x0;  // remove tailed '*'

   // now TravCB->CurrPath is like "X:\\ABC\\"

   TravCB->CurrLeftLen = 1 /* preserve space for '\0' */ + kal_wstrlen(TravCB->CurrPath) /* length of CurrPath ('*' was removed above) */;

   if (TravCB->CurrLeftLen < MT_MAXPATH_IN_WCHAR_UNIT)
      TravCB->CurrLeftLen = MT_MAXPATH_IN_WCHAR_UNIT - TravCB->CurrLeftLen;
   else
      TravCB->CurrLeftLen = 0;

   if (Act == RecAct_CountNum)
   {
      MaxLength = 8 + 3 + 1 + 1; // We only need sufficient length for SFN to skipped LFN handling in RTFFindNextEx() to save time

      #ifdef __FS_OPEN_HINT__
      MaxLength |= MT_HINT_DISABLE;
      #endif
   }
   else
      MaxLength = RTF_MAX_PATH;

   // Flat , list all
   ListFH = RTFFindFirstEx((WCHAR *)fp->FullName, 0, 0, &(TmpDirPos.Dir), TravCB->NameBuf, MaxLength, NULL, TravCB->CallerAddress);

   if (ListFH < 0)   ListResult = ListFH;

   while(ListResult == RTF_NO_ERROR)
   {
      if (TmpDirPos.Dir.FileName[0] != 0x2e) // skip dot and dot-dot
      {
         ActResult = Act(TravCB, TravCB->NameBuf , &(TmpDirPos.Dir) /* File */);
         if (ActResult < RTF_NO_ERROR)
         {  // path over len or operation abort indication
            ListResult = ActResult;
            if(TravCB->Parameters.ErrorCode==MT_ABORTED_ERROR)
            {
                ListResult = MT_ABORTED_ERROR;
                break;
            }
            continue;
         }
      }

      ListResult = RTFFindNextEx(ListFH, &(TmpDirPos.Dir), TravCB->NameBuf, MaxLength, NULL);
   }
   RTFFindClose(ListFH);

   if (ListResult == RTF_NO_MORE_FILES) // No more folder, No more files
   {
      TravCB->TravStatus = RTF_NO_ERROR;
   }
   else // Error Handle of Flat
   {
      TravCB->TravStatus = ListResult;
   }
}

void RecTravCore_CloseAndRootNodeAct(InternRecursiveEngineStruct *TravCB, RTFHANDLE TravFH, MTGenericCallBack *Act)
{
#ifdef __EFS_DEBUG__
   UINT        U = TravFH >> (4*sizeof(int));
#endif /* __EFS_DEBUG__ */
   UINT        i = TravFH & ((1 << (4*sizeof(int))) - 1);
   RTFile*     fp;
   WCHAR*      NamePtr;
   RTFDirEntry TmpDirPos;

   fp = gFS_Data.FileTable + i;
#ifdef __EFS_DEBUG__
   fs_assert_local(fp->Unique == U && i < FS_MAX_FILES && fp->Lock != 0 && fp->Dev != NULL);

   fs_assert_local(Act != NULL && TravCB->NameBuf != NULL);
#endif /* __EFS_DEBUG__ */

   // setup Name Buf & current folder
   kal_wstrcpy(TravCB->CurrPath, (WCHAR*) fp->FullName); /* C:\Level1\* */
   NamePtr = kal_wstrrchr(TravCB->CurrPath, 0x005c);

   if (NamePtr == NULL)
   {
      fs_util_trace_info2(TRACE_ERROR, FS_ERR_NULL_PTR_1, fs_internal_c, __LINE__, NULL);

      return;
   }

   *NamePtr = 0x0;

   NamePtr = kal_wstrrchr(TravCB->CurrPath, 0x005c);
   if (NamePtr == NULL) /* ROOT Directory, do nothing */
   {
      return;
   }
   NamePtr++;
   kal_wstrcpy(TravCB->NameBuf, NamePtr);
   *NamePtr = 0x0;
   TravCB->CurrLeftLen = MT_MAXPATH_IN_WCHAR_UNIT - kal_wstrlen(TravCB->CurrPath) - 1;

   // prepare Dos Dir Entry
   memcpy(&TmpDirPos, &(fp->DirEntry), sizeof(RTFDirEntry));

   // Close Before Act
   RecTravClose(TravFH);

   // Act
   Act(TravCB, TravCB->NameBuf , &(TmpDirPos.Dir) /* File or Dir */);

}

#ifdef __P_PROPRIETARY_COPYRIGHT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __EFS_DEBUG__
/* under construction !*/
#endif /* __EFS_DEBUG__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __EFS_DEBUG__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __EFS_DEBUG__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __P_PROPRIETARY_COPYRIGHT__ */

/* ------------------------------------------------------------------------------- */

/**************************************************
 *  Generic CallBack Class
 *  Members:
 *          RecAct_List
 *          RecAct_CountNum
 *          RecAct_CountSize
 *          RecAct_Deletion
 *          RecAct_Copy
 *          RecAct_CopyrightDeletion
 *          RecAct_CopyrightList
 **************************************************/
/**************************************************
 * Structure Member Required
 **************************************************/
int RecAct_CountNum(InternRecursiveEngineStruct *RES, WCHAR *ObjName, RTFDOSDirEntry *ObjInfo)
{
#ifdef __EFS_DEBUG__
   fs_assert_local(RES != NULL && ObjName != NULL && ObjInfo != NULL);
#endif /* __EFS_DEBUG__ */

   if ((RES->Parameters.Flag & FS_FILTER_SYSTEM_ATTR) && (ObjInfo->Attributes & RTF_ATTR_SYSTEM))
   {
      return 0;
   }

   if ((RES->Parameters.Flag & FS_FILTER_HIDDEN_ATTR) && (ObjInfo->Attributes & RTF_ATTR_HIDDEN))
   {
      return 0;
   }

   if ((RES->Parameters.Flag & FS_DIR_TYPE) && (ObjInfo->Attributes & RTF_ATTR_DIR))
   {
      RES->Parameters.Result++;
   }
   else if ((RES->Parameters.Flag & FS_FILE_TYPE) && (ObjInfo->Attributes & (RTF_ATTR_DIR|RTF_ATTR_VOLUME)) == 0)
   {
      RES->Parameters.Result++;
   }

   if (RES->Parameters.Progress)  // abort checking
   {
      if (RES->Parameters.Progress(FS_PGS_ING, 0, 0, 0) < 0)
      {
         RES->Parameters.ErrorCode = MT_ABORTED_ERROR;

         return MT_ABORTED_ERROR;
      }
   }

   return 0;
}

int RecAct_CountSize(InternRecursiveEngineStruct *RES, WCHAR *ObjName, RTFDOSDirEntry *ObjInfo)
{
    UINT volatile Count = 0;
    RTFile * volatile f = NULL;
    UINT Cluster, NextCluster = 0;

#ifdef __EFS_DEBUG__
    fs_assert_local(RES != NULL && ObjName != NULL && ObjInfo != NULL);
    fs_assert_local(RES->Parameters.Drive != NULL && RES->Parameters.RAWCluster != NULL);
#endif /* __EFS_DEBUG__ */

    XTRY
        case XCODE:
            f = ParseFileHandle(RES->Parameters.ProgInfo);
            Cluster = FIRST_FILE_CLUSTER((*ObjInfo));

            if (Cluster == 0)   // this file has no cluster allocated for it
            {
                break;
            }

            while (NextCluster < RTF_CLUSTER_CHAIN_END)
            {
                NextCluster = RES->Parameters.RAWCluster(RES->Parameters.Drive, Cluster);

                if (NextCluster < 2)
                    break;

                Count++;

                if (Count > f->Drive->Clusters) // to avoid endless loop due to cross-link
                {
                    XRAISE(FS_FAT_ALLOC_ERROR);
                }

                Cluster = NextCluster;
            }

            break;

        default:
            break;

        case XFINALLY:
            if (f != NULL)
            {
                UnlockDevice(f->Dev);
            }
            break;

    XEND_API

    if (RES->Parameters.Flag & FS_COUNT_IN_CLUSTER)
    {
        RES->Parameters.Result += Count;
    }
    else if (RES->Parameters.Flag & FS_COUNT_IN_BYTE)
    {
        RES->Parameters.Result += Count << RES->Parameters.Drive->ClusterShift;
    }

    if (RES->Parameters.Progress)  // abort checking
    {
        if (RES->Parameters.Progress(FS_PGS_ING, 0, RES->Parameters.Result, 0) < 0)
        {
            RES->Parameters.ErrorCode = MT_ABORTED_ERROR;

            return MT_ABORTED_ERROR;
        }
    }

    return 0;
}

int RecAct_Deletion(InternRecursiveEngineStruct *RES, WCHAR *ObjName, RTFDOSDirEntry *ObjInfo)
{
   int result = RTF_NO_ERROR;

#ifdef __EFS_DEBUG__
   fs_assert_local(RES != NULL && ObjName != NULL && ObjInfo != NULL);
#endif /* __EFS_DEBUG__ */

   /*------------------------------------------------------------------------
    * Check if deletion is aborted before.
    *
    * There is another abort mechanism by calling progress call-back function
    * and check the result. However it might not be assigned, like FMGR.
    *
    * Remember to set error code in parameter, otherwise
    * RecAUX_XDeleteFolder() may return FS_NO_ERROR even if g_Xdelete was
    * set to KAL_FALSE, and "Deleted" will pop-up incorrectly.
    *-------------------------------------------------------------- W10.03 --*/
   if ((RES->Parameters.Flag & FS_XDEL_ABORT_WATCH) && (g_Xdelete != KAL_TRUE))
   {
      RES->Parameters.ErrorCode = MT_ABORTED_ERROR;
      return MT_ABORTED_ERROR;
   }

   // check if the Path Length of that file over Spec. definiation
   if (kal_wstrlen(ObjName) > RES->CurrLeftLen)
   {
      RES->Parameters.ErrorCode = MT_PATH_OVER_LEN_ERROR;
      return MT_PATH_OVER_LEN_ERROR;
   }

   kal_wstrcpy(RES->DestPath, RES->CurrPath);

   RecConf_MemoryChecker(&RES); // for debug (check name buffer guard pattern)

   kal_wstrcat(RES->DestPath, ObjName);

   RecConf_MemoryChecker(&RES); // for debug (check name buffer guard pattern)

   if ((RES->Parameters.Flag & FS_DIR_TYPE) && (ObjInfo->Attributes & RTF_ATTR_DIR))
   {
      result = RTFRemoveDir(RES->DestPath);

      /* Ignore Fail on Folder Deletion here (if any INUSE directory entry found in this DIR, RTF_ACCESS_DENIED is raised). */
      if (result < 0)
      {
         RES->Parameters.ErrorCode = result;
      }
      RES->Parameters.Result++;
   }
   else if ((RES->Parameters.Flag & FS_FILE_TYPE) && (ObjInfo->Attributes & (RTF_ATTR_DIR|RTF_ATTR_VOLUME)) == 0)
   {
      result = RTFDelete(RES->DestPath);
      if (result < 0)
      {
         RES->Parameters.ErrorCode = result;
         return 1;
      }
      RES->Parameters.Result++;
   }

   if(result == RTF_NO_ERROR && RES->Parameters.Progress)
   {
      if(RES->Parameters.Progress(FS_XDELETE_PGS_ING, 0, RES->Parameters.Result, 0) < 0)
      {
         RES->Parameters.ErrorCode = MT_ABORTED_ERROR;

         return MT_ABORTED_ERROR;
      }
   }

   return 0;
}

int RecAct_Copy(InternRecursiveEngineStruct *RES, WCHAR *ObjName, RTFDOSDirEntry *ObjInfo)
{
   int result = RTF_NO_ERROR;
   int Len_Curr, Len_Obj;

#ifdef __EFS_DEBUG__
   fs_assert_local(RES != NULL && ObjName != NULL && ObjInfo != NULL);
#endif /* __EFS_DEBUG__ */

   Len_Curr = kal_wstrlen(RES->CurrPath);
   Len_Obj  = kal_wstrlen(ObjName);

   if (Len_Obj > RES->CurrLeftLen)
   {  // The Src Path Length of that file over Spec. definiation
      return MT_PATH_OVER_LEN_ERROR;
   }

   if (Len_Curr - RES->PrefixPathLen + RES->DestPrefixPathLen + Len_Obj > MT_MAXPATH_IN_WCHAR_UNIT)
   {  // The Dest Path Length of that file over Spec. definiation
      return MT_PATH_OVER_LEN_ERROR;
   }

   kal_wstrcpy(RES->DestPath + RES->DestPrefixPathLen, RES->CurrPath + RES->PrefixPathLen);
   kal_wstrcat(RES->DestPath, ObjName);

   if (ObjInfo->Attributes & RTF_ATTR_DIR)
   {
      result = RTFCreateDir(RES->DestPath, ObjInfo->Attributes);

      if (result < 0) return result; // do not ignore fail on folder creation!

      RES->Parameters.Result++;
   }
   else
   {
      /* Note :  Here we will borrow RES->CurrPath to store full source path */
      kal_wstrcat(RES->CurrPath, ObjName);

      result = CopyFileLightWeight(RES->CurrPath, RES->DestPath, RES->Parameters.Progress, RES->Parameters.PrivateData, RES->Parameters.PrivateData?512:0, RES->CallerAddress);

      /* Note :  Here we will return RES->CurrPath to store full source path */
      RES->CurrPath[Len_Curr] = 0x0;

      if (result < 0)
      {
         RES->Parameters.ErrorCode = result;
         return result;
      }

      RES->Parameters.Result++;
   }

   if (RES->Parameters.Progress)  // add abort mechansim for folder copy
   {
      if(RES->Parameters.Progress(FS_MOVE_PGS_ING, RES->Parameters.Total, RES->Parameters.Result, RES->Parameters.ProgInfo) < 0)
      {
         RES->Parameters.ErrorCode = MT_ABORTED_ERROR;

         return MT_ABORTED_ERROR;
      }
   }

   return 0;
}

#ifdef __P_PROPRIETARY_COPYRIGHT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __EFS_DEBUG__
/* under construction !*/
#endif /* __EFS_DEBUG__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __P_PROPRIETARY_COPYRIGHT__ */

#ifdef __P_PROPRIETARY_COPYRIGHT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __EFS_DEBUG__
/* under construction !*/
#endif /* __EFS_DEBUG__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __P_PROPRIETARY_COPYRIGHT__ */
/* ------------------------------------------------------------------------------- */

/**************************************************
 *  Recursive Engine Configure Utilities
 *  Members:
 *          RecConf_Alloc
 *          RecConf_Free
 **************************************************/

int RecConf_Alloc(InternRecursiveEngineStruct **RES, BYTE *RecursiveStack, const UINT StackSize)
{
   kal_char                    *bufptr;
   InternRecursiveEngineStruct *RESptr;
   int ModifiedStackSize;

   if (RecursiveStack == NULL)
   {
      #ifdef __FS_DEDICATED_BUFFER__
      MTBufAlloc(FS_XDELETE_BUFFER_SIZE_FOR_FOLDER_LEVEL(FS_MAX_FOLDER_LEVEL), (unsigned char**)&bufptr, FS_INT_DBUF_ALLOC_PRECISE);

      if (bufptr != NULL)
      {
         RESptr = (InternRecursiveEngineStruct *) bufptr;

         kal_mem_set(bufptr, 0, sizeof(InternRecursiveEngineStruct) + (3 * RECCONF_NAMEBUF_PACKAGE_SIZE));

         RESptr->LevelStack = (RTFDirEntry*)(bufptr + (sizeof(InternRecursiveEngineStruct) + (3 * RECCONF_NAMEBUF_PACKAGE_SIZE)));
         RESptr->LevelLimit = FS_MAX_FOLDER_LEVEL;
      }
      else
      #endif /* __FS_DEDICATED_BUFFER__ */
      {
         /* Memory Usage : 64 + 3 * ((520+4) + 4) = 1648 */
         bufptr = get_ctrl_buffer(sizeof(InternRecursiveEngineStruct) + 3 * RECCONF_NAMEBUF_PACKAGE_SIZE);
         RESptr = (InternRecursiveEngineStruct *) bufptr;

         kal_mem_set(bufptr, 0, sizeof(InternRecursiveEngineStruct) + (3 * RECCONF_NAMEBUF_PACKAGE_SIZE));

         /* default max level count: 39 */
         RESptr->LevelStack = get_ctrl_buffer(RECCONF_DIRSTACK_SIZE);
         RESptr->LevelLimit = RECCONF_DIRSTACK_SIZE / sizeof(RTFDirEntry);
      }
   }
   else
   {
      /* Must 4-Byte align buffer pointer, stop dangerous usage early */
      fs_ext_assert_local( ((UINT)RecursiveStack & 0x03) == 0x00, (UINT)RecursiveStack, StackSize, 0);

      if(StackSize<(sizeof(InternRecursiveEngineStruct) + 3 * RECCONF_NAMEBUF_PACKAGE_SIZE))
      {
          return MT_FAIL_GET_MEM;
      }
      bufptr = (kal_char*) RecursiveStack;
      kal_mem_set(bufptr, 0, sizeof(InternRecursiveEngineStruct) + 3 * RECCONF_NAMEBUF_PACKAGE_SIZE);
      ModifiedStackSize = StackSize - (sizeof(InternRecursiveEngineStruct) + 3 * RECCONF_NAMEBUF_PACKAGE_SIZE);
      RESptr = (InternRecursiveEngineStruct *) bufptr;

      /* if user specify a RecursiveStack, max level count can be customized */
      RESptr->LevelStack = (RTFDirEntry*)((kal_char *)RecursiveStack + (sizeof(InternRecursiveEngineStruct) + 3 * RECCONF_NAMEBUF_PACKAGE_SIZE));
      RESptr->LevelLimit = ModifiedStackSize / sizeof(RTFDirEntry);
   }

   bufptr          += sizeof(InternRecursiveEngineStruct);
   *((int *)bufptr) = RECCONF_NAMEBUF_GUARD_PRINT;
   RESptr->CurrPath = (WCHAR*)(bufptr + sizeof(int));

   bufptr          += RECCONF_NAMEBUF_PACKAGE_SIZE;
   *((int *)bufptr) = RECCONF_NAMEBUF_GUARD_PRINT;
   RESptr->NameBuf  = (WCHAR*)(bufptr + sizeof(int));

   bufptr          += RECCONF_NAMEBUF_PACKAGE_SIZE;
   *((int *)bufptr) = RECCONF_NAMEBUF_GUARD_PRINT;
   RESptr->DestPath = (WCHAR*)(bufptr + sizeof(int));

   *RES = RESptr;

   return RTF_NO_ERROR;
}

void RecConf_MemoryChecker(InternRecursiveEngineStruct **RES)
{
   kal_char                    *bufptr;

   bufptr = (void *)(*RES);

   // Check RECCONF_NAMEBUF_GUARD_PRINT (in-house only)
   bufptr          += sizeof(InternRecursiveEngineStruct);
   fs_assert_local(*((int *)bufptr) == RECCONF_NAMEBUF_GUARD_PRINT);

   bufptr          += RECCONF_NAMEBUF_PACKAGE_SIZE;
   fs_assert_local(*((int *)bufptr) == RECCONF_NAMEBUF_GUARD_PRINT);

   bufptr          += RECCONF_NAMEBUF_PACKAGE_SIZE;
   fs_assert_local(*((int *)bufptr) == RECCONF_NAMEBUF_GUARD_PRINT);
}

void RecConf_Free(InternRecursiveEngineStruct **RES, BYTE *RecursiveStack, const UINT StackSize)
{
   RecConf_MemoryChecker(RES);

   /* Free Memory */
   if (RecursiveStack == NULL)
   {
      #ifdef __FS_DEDICATED_BUFFER__
      if (MTBufCheckRange((unsigned int)*RES))
         MTBufFree(FS_XDELETE_BUFFER_SIZE_FOR_FOLDER_LEVEL(FS_MAX_FOLDER_LEVEL), (unsigned char**)RES);
      else
      #endif /* __FS_DEDICATED_BUFFER__ */
      {
         free_ctrl_buffer((*RES)->LevelStack);
         free_ctrl_buffer((*RES));
      }
   }
   *RES = NULL;
}

/* ------------------------------------------------------------------------------- */
/**************************************************
 *  Recursive Type API Auxiliary Sub-Routines
 *  Members:
 *          RecAUX_IsFolder
 *          RecAUX_IsFolderRW
 *          RecAUX_TestSrcAndDestPath
 *          RecAUX_CountNumOfObjUnderFolderTree
 *          RecAUX_CountSumOfSizeUnderFolderTree
 *          RecAUX_XDeleteFolder
 *          RecAUX_XCopyFolder
 **************************************************/
int RecAUX_IsFolder(const WCHAR * PathName)
{
   int volatile Result = RTF_NO_ERROR;
   RTFile * volatile f = NULL;

   XTRY
      case XCODE:
         f = ParseFileName((char *)PathName);
         if (f->SpecialKind != NormalFile)
            XRAISE(RTF_INVALID_FILENAME);
         if (!SearchFile(f, SEARCH_FILES, (char *)PathName, NULL))
            XRAISE(RTF_PATH_NOT_FOUND);
         if((f->DirEntry.Dir.Attributes & RTF_ATTR_DIR) == 0)
            XRAISE(RTF_PARAM_ERROR);
         break;

      default:
         Result = XVALUE; //API dose not need XHANDLED
         break;

      case XFINALLY:
         if (f != NULL)
            FreeFTSlotAndDevice(f);
         break;
   XEND_API

   return Result;
}

int RecAUX_IsFolderRW(const WCHAR * PathName)
{
   int volatile Result = RTF_NO_ERROR;
   RTFile * volatile f = NULL;

   XTRY
      case XCODE:
         f = ParseFileName((char *)PathName);
         if (f->Dev->DeviceFlags & MT_DEVICE_WRITE_PROTECT)
            XRAISE(RTF_WRITE_PROTECTION);
         if (f->SpecialKind != NormalFile)
            XRAISE(RTF_INVALID_FILENAME);
         if (!SearchFile(f, SEARCH_FILES, (char *)PathName, NULL))
            XRAISE(RTF_PATH_NOT_FOUND);
         if((f->DirEntry.Dir.Attributes & RTF_ATTR_DIR) == 0)
            XRAISE(RTF_PARAM_ERROR);
         break;

      default:
         Result = XVALUE; //API dose not need XHANDLED
         break;

      case XFINALLY:
         if (f != NULL)
            FreeFTSlotAndDevice(f);
         break;
   XEND_API

   return Result;
}

/**********************************************************
 * RecAUX_TestSrcAndDestPath   ---- The sub-routine to check source full path and destination full path
 * RETURNS
 *    < RTF_NO_ERROR , serious error
 *    >= 0           , Value that combination of MT_XMOVE_XXX bit flag
 *
 **********************************************************/
int RecAUX_TestSrcAndDestPath(const WCHAR * SrcPathName, const WCHAR * DestPathName, UINT Flag)
{
   int volatile Result = RTF_NO_ERROR;
   RTFile * volatile f1 = NULL; // src
   RTFile * volatile f2 = NULL; // dst

   XTRY
      case XCODE:
         /* TestSrcAndDestPath - 1 : Process SrcPathName basic test */
         f1 = ParseFileName((char *)SrcPathName);
         if (f1->SpecialKind == FileMapFile)
         {
            Result |= MT_XMOVE_SRC_IS_VIRTUAL;
         }
         else
         {
            if (f1->SpecialKind != NormalFile)
               XRAISE(RTF_INVALID_FILENAME);

            CheckValidFileName2(SrcPathName, KAL_FALSE);

            if (!SearchFile(f1, SEARCH_FILES, (char *)SrcPathName, NULL))
            {
               fs_util_trace_err_noinfo(RTF_PATH_NOT_FOUND);

               XRAISE(RTF_PATH_NOT_FOUND);
            }

            if(Flag&FS_MOVE_KILL)
            {
                CheckNotOpen(f1);
            }
         }

         /* TestSrcAndDestPath - 2 : Try to access DestPathName, f2 */
         RTFSYSFreeMutex(RTFLock);

         f2 = ParseFileName((char *)DestPathName);
         if (f2->SpecialKind != NormalFile)
         {
            fs_util_trace_err_noinfo(RTF_INVALID_FILENAME);  // [trace]

            XRAISE(RTF_INVALID_FILENAME);
         }

         if (f2->Dev->DeviceFlags & MT_DEVICE_WRITE_PROTECT)
         {
            fs_util_trace_err_noinfo(RTF_WRITE_PROTECTION);  // [trace]

            XRAISE(RTF_WRITE_PROTECTION);
         }

         /* TestSrcAndDestPath - 3 : set result accroding to f1     */
         Result |= MT_XMOVE_SRC_EXIST;
         if (f1->DirEntry.Dir.Attributes & RTF_ATTR_DIR)
            Result |= MT_XMOVE_SRC_IS_FOLDER;
         if (f1->DirEntry.Dir.Attributes & RTF_ATTR_READ_ONLY)
            Result |= MT_XMOVE_SRC_ATTR_RO;
         if (f1->Dev->DeviceFlags & MT_DEVICE_WRITE_PROTECT)
            Result |= MT_XMOVE_SRC_DEVICE_RO;

         /* TestSrcAndDestPath - 4 : set result accroding to f2     */
         if (SearchFile(f2, SEARCH_FILES, (char *)DestPathName, NULL))
         {
            /* destination file or folder is already existed */

            Result |= MT_XMOVE_DEST_EXIST;

            if (f2->DirEntry.Dir.Attributes & RTF_ATTR_DIR)
               Result |= MT_XMOVE_DEST_IS_FOLDER;
            if (f2->DirEntry.Dir.Attributes & RTF_ATTR_READ_ONLY)
               Result |= MT_XMOVE_DEST_ATTR_RO;

            /* Check if SrcPathName == DestPathName */
            if ((f1->Drive == f2->Drive) &&
                (f1->SpecialKind == f2->SpecialKind) &&
                ((f1->DirEntry.ShortPos.Cluster == f2->DirEntry.ShortPos.Cluster) &&
                 (f1->DirEntry.ShortPos.Index == f2->DirEntry.ShortPos.Index)))
            {
                fs_util_trace_err_noinfo(RTF_FILE_EXISTS);

                XRAISE(RTF_FILE_EXISTS);
            }
            // if we do not want to overwrite the existed "file", raise RTF_FILE_EXISTS
            else if (!(Flag & FS_MOVE_OVERWRITE) && !(Result & MT_XMOVE_DEST_IS_FOLDER))
            {
                fs_util_trace_err_noinfo(RTF_FILE_EXISTS);

                XRAISE(RTF_FILE_EXISTS);
            }

            CheckNotOpen(f2);
         }

         if (f2->Dev->DeviceFlags & MT_DEVICE_WRITE_PROTECT)
            Result |= MT_XMOVE_DEST_DEVICE_RO;

         /* TestSrcAndDestPath - 5 : set result accroding to f1,f2  */
         if (f1->Dev == f2->Dev)
            Result |= MT_XMOVE_SAME_DEVICE;

         if (f1->Drive == f2->Drive)
            Result |= MT_XMOVE_SAME_DRIVE;

         break;
      default:
         Result = XVALUE; //API dose not need XHANDLED
         break;
      case XFINALLY:
         if (f2 != NULL) /* imply f1 != NULL, see above */
         {
            FreeFTSlotAndDevice(f2);
            RTFSYSLockMutex(RTFLock, RTF_INFINITE);
            FreeFTSlotAndDevice(f1);
         }
         else if (f1 != NULL)
         {
            SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, f1->Dev, RTF_INFINITE); /* it may raise an exception after release the system lock */
            FreeFTSlotAndDevice(f1);
         }
         break;
   XEND_API

   return Result;
}

/**********************************************************
 * RecAUX_CountNumOfObjUnderFolderTree   ---- The sub-procedure to do FS_Count
 *
 **********************************************************/
int RecAUX_CountNumOfObjUnderFolderTree(const WCHAR * FullPath, UINT Flag, FS_ProgressCallback Progress, BYTE *RecursiveStack, const UINT StackSize)
{
   int volatile Result = RTF_NO_ERROR;
   FS_HANDLE             TravFH;
   InternRecursiveEngineStruct *ReCB;

   /* CountNumOfObjUnderFolderTree - 1 : Setup InternRecursiveEngineStruct & Resources */
   Result = RecConf_Alloc(&ReCB, RecursiveStack, StackSize);
   if(Result<0)
   {
       return Result;
   }
   ReCB->Parameters.Flag = Flag;
   ReCB->Parameters.Progress = Progress;

   /* CountNumOfObjUnderFolderTree - 2 : Start a Traverse Handle */
   kal_wstrcpy(ReCB->NameBuf, FullPath);
   kal_wstrcat(ReCB->NameBuf, (WCHAR*)L"\\*");
   TravFH = RecTravStart(ReCB->NameBuf);
   if (TravFH < 0)
   {
      Result = TravFH;

      fs_util_trace_err_noinfo(Result);
      fs_util_trace_info0(TRACE_ERROR, FS_ERR_REC_TRAV_START, NULL);
   }
   else
   {
      /* CountNumOfObjUnderFolderTree - 3 : Recusrive Traverse Call */
      if (Flag & FS_RECURSIVE_TYPE)
      {
         #if !defined(__FS_SLIM_BFS__)
         RecTravCore_BFS(ReCB, TravFH, RecAct_CountNum);
         #else  // use DFS instead of BFS in Slim projects
         RecTravCore_DFS(ReCB, TravFH, RecAct_CountNum);
         #endif

         RecTravClose(TravFH);
      }
      else
      {
         RecTravCore_DFS(ReCB, TravFH, RecAct_CountNum);    // Merge Flat engine to DFS engine
         //RecTravCore_Flat(ReCB, TravFH, RecAct_CountNum);

         RecTravClose(TravFH);
      }

      /* CountNumOfObjUnderFolderTree - 4 : Check Result and Error Status after Recusrive Call */
      if (ReCB->TravStatus < 0) /* Recursive Traverse Failure */
      {
         Result = ReCB->TravStatus;

         fs_util_trace_err_noinfo(Result);
         fs_util_trace_info0(TRACE_ERROR, FS_ERR_REC_TRAV_CORE, NULL);
      }
      else if (ReCB->Parameters.ErrorCode < 0) /* RecAction Failure */
      {
         Result = ReCB->Parameters.ErrorCode;

         fs_util_trace_err_noinfo(Result);
         fs_util_trace_info0(TRACE_ERROR, FS_ERR_REC_TRAV_ACTION, NULL);
      }
      else /* Success */
      {
         Result = ReCB->Parameters.Result;
      }

   } /* if RecTracStart(...) */

   /* CountNumOfObjUnderFolderTree - 5 : Release InternRecursiveEngineStruct & Resources */
   RecConf_Free(&ReCB, RecursiveStack, StackSize);

   return Result;
}
/**********************************************************
 * RecAUX_CountSumOfSizeUnderFolderTree   ---- The sub-procedure to do FS_GetFolderSize
 *
 **********************************************************/
int RecAUX_CountSumOfSizeUnderFolderTree(const WCHAR * FullPath, UINT Flag, BYTE *RecursiveStack, const UINT StackSize, FS_ProgressCallback Progress)
{
   int volatile Result = RTF_NO_ERROR;
   FS_HANDLE             TravFH;
   InternRecursiveEngineStruct *ReCB;

   /* CountSumOfSizeUnderFolderTree - 1 : Setup InternRecursiveEngineStruct & Resources */
   Result = RecConf_Alloc(&ReCB, RecursiveStack, StackSize);
   if(Result<0)
   {
       return Result;
   }
   ReCB->Parameters.Flag = Flag;
   ReCB->Parameters.Progress = Progress;

   /* CountSumOfSizeUnderFolderTree - 2 : Start a Traverse Handle */
   kal_wstrcpy(ReCB->NameBuf, FullPath);
   kal_wstrcat(ReCB->NameBuf, (WCHAR*)L"\\*");
   TravFH = RecTravStart(ReCB->NameBuf);

   if (TravFH < 0)
   {
      Result = TravFH;

      fs_util_trace_err_noinfo(Result);
      fs_util_trace_info0(TRACE_ERROR, FS_ERR_REC_TRAV_START, NULL);
   }
   else
   {
      /* CountSumOfSizeUnderFolderTree - 3 : Recusrive Traverse Call */
      ReCB->Parameters.Drive = (RTFDrive*)fs_conf_get_drv_struct_by_drv_letter(FullPath[0]);

      if (NULL == ReCB->Parameters.Drive)
      {
         fs_assert_local(0);
      }

      switch (ReCB->Parameters.Drive->FATType)
      {
         case 12:   ReCB->Parameters.RAWCluster = ScanFAT12_GetRAWClusterValue; break;
         case 16:   ReCB->Parameters.RAWCluster = ScanFAT16_GetRAWClusterValue; break;
         case 32:   ReCB->Parameters.RAWCluster = ScanFAT32_GetRAWClusterValue; break;
         default:   fs_assert_local(0);
      }
      ReCB->Parameters.ProgInfo = TravFH;

      #if !defined(__FS_SLIM_BFS__)
      RecTravCore_BFS(ReCB, TravFH, RecAct_CountSize);
      #else
      RecTravCore_DFS(ReCB, TravFH, RecAct_CountSize);
      #endif

      RecTravCore_CloseAndRootNodeAct(ReCB, TravFH, RecAct_CountSize);

      /* CountSumOfSizeUnderFolderTree - 4 : Check Result and Error Status after Recusrive Call */
      if (ReCB->TravStatus < 0) /* Recursive Traverse Failure */
      {
         Result = ReCB->TravStatus;

         fs_util_trace_err_noinfo(Result);
         fs_util_trace_info0(TRACE_ERROR, FS_ERR_REC_TRAV_CORE, NULL);
      }
      else if (ReCB->Parameters.ErrorCode < 0) /* RecAction Failure */
      {
         Result = ReCB->Parameters.ErrorCode;

         fs_util_trace_err_noinfo(Result);
         fs_util_trace_info0(TRACE_ERROR, FS_ERR_REC_TRAV_ACTION, NULL);
      }
      else /* Success */
      {
         Result = ReCB->Parameters.Result;
      }

   } /* if RecTracStart(...) */

   /* CountSumOfSizeUnderFolderTree - 5 : Release InternRecursiveEngineStruct & Resources */
   RecConf_Free(&ReCB, RecursiveStack, StackSize);

   return Result;
}

/**********************************************************
 * RecAUX_XDeleteFolder   ---- The sub-procedure to do FS_XDelete
 *
 **********************************************************/
int RecAUX_XDeleteFolder(const WCHAR * FullPath, UINT Flag, FS_ProgressCallback Progress, BYTE *RecursiveStack, const UINT StackSize)
{
   int volatile Result = RTF_NO_ERROR;
   FS_HANDLE             TravFH;
   InternRecursiveEngineStruct *ReCB;

   /* XDeleteFolder - 1 : Setup InternRecursiveEngineStruct & Resources */
   Result = RecConf_Alloc(&ReCB, RecursiveStack, StackSize);

   if (Result < 0)
   {
       return Result;
   }

   ReCB->Parameters.Flag = Flag;
   ReCB->Parameters.Progress = Progress;

   /* XDeleteFolder - 2 : Start a Traverse Handle */
   kal_wstrcpy(ReCB->NameBuf, FullPath);
   kal_wstrcat(ReCB->NameBuf, (WCHAR*)L"\\*");
   RecConf_MemoryChecker(&ReCB); // for debug (check name buffer guard pattern)

   TravFH = RecTravStart(ReCB->NameBuf); // search parent inside

   if (TravFH < 0)
   {
      Result = TravFH;

      fs_util_trace_err_noinfo(Result);
      fs_util_trace_info0(TRACE_ERROR, FS_ERR_REC_TRAV_START, NULL);
   }
   else
   {
      /* XDeleteFolder - 3 : Recusrive Traverse Call */

      // last function call may spend lots of time (search parent), check if XDelete is aborted
      if ((Flag & FS_XDEL_ABORT_WATCH) && (g_Xdelete != KAL_TRUE))
      {
         Result = MT_ABORTED_ERROR;

         fs_util_trace_err_noinfo(Result);
         fs_util_trace_info0(TRACE_ERROR, FS_ERR_REC_TRAV_CORE, NULL);

         RecTravClose(TravFH); // close file handle, otherwise this folder will always not be deleted in the future.

         goto RecAUX_XDeleteFolder_Return;
      }

      if (Flag & FS_RECURSIVE_TYPE)
      {
         RecTravCore_DFS(ReCB, TravFH, RecAct_Deletion);
         RecTravCore_CloseAndRootNodeAct(ReCB, TravFH, RecAct_Deletion);
      }
      else
      {
         RecTravCore_DFS(ReCB, TravFH, RecAct_Deletion);    // Merge Flat engine to DFS engine
         //RecTravCore_Flat(ReCB, TravFH, RecAct_Deletion);
         RecTravClose(TravFH);
      }

      /* XDeleteFolder - 4 : Check Result and Error Status after Recusrive Call */
      if (ReCB->TravStatus < 0) /* Recursive Traverse Failure */
      {
         Result = ReCB->TravStatus;

         fs_util_trace_err_noinfo(Result);
         fs_util_trace_info0(TRACE_ERROR, FS_ERR_REC_TRAV_CORE, NULL);
      }
      else if (ReCB->Parameters.ErrorCode < 0) /* RecAction Failure */
      {
         Result = ReCB->Parameters.ErrorCode;

         fs_util_trace_err_noinfo(Result);
         fs_util_trace_info0(TRACE_ERROR, FS_ERR_REC_TRAV_ACTION, NULL);
      }
      else /* Success */
      {
         Result = ReCB->Parameters.Result;
      }

   } /* if RecTracStart(...) */

RecAUX_XDeleteFolder_Return:

   /* XDeleteFolder - 5 : Release InternRecursiveEngineStruct & Resources */
   RecConf_Free(&ReCB, RecursiveStack, StackSize);

   return Result;
}

/**********************************************************
 * RecAUX_XCopyFolder   ---- The sub-procedure to do FS_Move
 *
 **********************************************************/
int RecAUX_XCopyFolder(const WCHAR * FullPath, const WCHAR * DstPath, int Status,
                       FS_ProgressCallback Progress, UINT Total, BYTE *RecursiveStack, const UINT StackSize, kal_uint32 caller_address)
{
   int volatile Result = RTF_NO_ERROR;
   FS_HANDLE             TravFH;
   InternRecursiveEngineStruct *ReCB;
   BYTE *CopyBuffer = NULL;
   int CopyBufferLen = 0;
   int ModifiedStackSize = StackSize;

   /* Reserve Copy Folder */
   if(RecursiveStack)
   {
       if(StackSize<CopyBufferSize)
       {
           return MT_FAIL_GET_MEM;
       }
       if(StackSize<FS_MOVE_BUFFER_SIZE_FOR_FOLDER_LEVEL(128))
       {
           ModifiedStackSize = StackSize - CopyBufferSize;
           CopyBufferLen = CopyBufferSize;
       }
       else
       {
           ModifiedStackSize = FS_MOVE_BUFFER_SIZE_FOR_FOLDER_LEVEL(128) - CopyBufferSize;
           CopyBufferLen = StackSize - ModifiedStackSize;
       }
       CopyBuffer = RecursiveStack;
       RecursiveStack += CopyBufferLen;
   }

   /* XCopyFolder - 1 : Setup InternRecursiveEngineStruct & Resources */
   Result = RecConf_Alloc(&ReCB, RecursiveStack, ModifiedStackSize);

   if(Result<0)
   {
       return Result;
   }

   ReCB->CallerAddress       = caller_address;
   ReCB->Parameters.Flag     = (Status & (MT_XMOVE_SAME_DRIVE | MT_XMOVE_SAME_DEVICE));
   ReCB->Parameters.Progress = Progress;
   ReCB->Parameters.Total    = Total;
   ReCB->Parameters.PrivateData = CopyBuffer;

   /* XCopyFolder - 2 : Start a Traverse Handle */
   ReCB->DestPrefixPathLen   = kal_wstrlen(DstPath);
   ReCB->PrefixPathLen       = kal_wstrlen(FullPath);

   kal_wstrcpy(ReCB->DestPath, DstPath);
   kal_wstrcpy(ReCB->NameBuf, FullPath);
   kal_wstrcat(ReCB->NameBuf, (WCHAR*)L"\\*");

   TravFH = RecTravStart(ReCB->NameBuf);

   if (TravFH < 0)
   {
      Result = TravFH;

      fs_util_trace_err_noinfo(Result);
      fs_util_trace_info0(TRACE_ERROR, FS_ERR_REC_TRAV_START, NULL);
   }
   else
   {
      /* XCopyFolder - 3 : Recusrive Traverse Call */
      ReCB->Parameters.ProgInfo = TravFH;

      #if !defined(__FS_SLIM_BFS__)
      RecTravCore_BFS(ReCB, TravFH, RecAct_Copy);
      #else
      RecTravCore_DFS(ReCB, TravFH, RecAct_Copy);
      #endif

      RecTravClose(TravFH);

      /* XCopyFolder - 4 : Check Result and Error Status after Recusrive Call */
      if (ReCB->TravStatus < 0) /* Recursive Traverse Failure */
      {
         Result = ReCB->TravStatus;

         fs_util_trace_err_noinfo(Result);
         fs_util_trace_info0(TRACE_ERROR, FS_ERR_REC_TRAV_CORE, NULL);
      }
      else if (ReCB->Parameters.ErrorCode < 0) /* RecAction Failure */
      {
         Result = ReCB->Parameters.ErrorCode;

         fs_util_trace_err_noinfo(Result);
         fs_util_trace_info0(TRACE_ERROR, FS_ERR_REC_TRAV_ACTION, NULL);
      }
      else /* Success */
      {
         Result = ReCB->Parameters.Result;
      }

   } /* if RecTracStart(...) */

   /* XCopyFolder - 5 : Release InternRecursiveEngineStruct & Resources */
   RecConf_Free(&ReCB, RecursiveStack, ModifiedStackSize);

   return Result;
}

#ifdef __FS_SORT_SUPPORT__

unsigned int FileUintHint(WCHAR *pUCS2)
{
  unsigned char UTF8[8];
  unsigned char *pUTF8 = UTF8;
  unsigned int UCS2;
  int i, j;
  unsigned int Result = 0;

  for(i=0, j=0; i<4 && j<4; i++)
  {
     UCS2 = fs_util_wchar_toupper(pUCS2[i]);
     if(UCS2==0)
     {
          pUTF8[j++] = 0;
          break;
     }

     if(UCS2<0x80)
     {
	      pUTF8[j++] = UCS2;
     }
     else if(UCS2<0x800)
     {
        pUTF8[j++] = (0xC0|(UCS2>>6));
        pUTF8[j++] = (0x80|(UCS2&0x3F));
     }
     else if(UCS2<0x10000)
     {
        pUTF8[j++] = (0xE0|(UCS2>>12));
        pUTF8[j++] = (0x80|((UCS2>>6)&0x3F));
        pUTF8[j++] = (0x80|(UCS2&0x3F));
     }
     else if(UCS2<0x200000)
     {
        pUTF8[j++] = (0xF0|(UCS2>>18));
        pUTF8[j++] = (0x80|((UCS2>>12)&0x3F));
        pUTF8[j++] = (0x80|((UCS2>>6)&0x3F));
        pUTF8[j++] = (0x80|(UCS2&0x3F));
     }
     else if(UCS2<0x4000000)
	 {
        pUTF8[j++] = (0xF8|(UCS2>>24));
        pUTF8[j++] = (0x80|((UCS2>>18)&0x3F));
        pUTF8[j++] = (0x80|((UCS2>>12)&0x3F));
        pUTF8[j++] = (0x80|((UCS2>>6)&0x3F));

        break;
	 }
     else
     {
        pUTF8[j++] = (0xFC|(UCS2>>30));
        pUTF8[j++] = (0x80|((UCS2>>24)&0x3F));
        pUTF8[j++] = (0x80|((UCS2>>18)&0x3F));
        pUTF8[j++] = (0x80|((UCS2>>12)&0x3F));

        break;
     }
  }

  for(i=0; i<4 && pUTF8[i]; i++)
  {
     Result<<=8;
   	 Result|=pUTF8[i];
  }
  for(; i<4; i++)
  {
     Result<<=8;
  }
  return Result;
}

int CompareFileName(WCHAR *FileName1, UINT*Hint1, WCHAR *FileName2, UINT *Hint2)
{
    int j;
    UINT u, v;

    if(Hint1)
    {
        *Hint1 = FileUintHint(FileName1);
    }

    if(Hint2)
    {
        *Hint2 = FileUintHint(FileName2);
    }

    for(j=2; j<=RTF_MAX_PATH; j++)
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

static int CompareFileType(WCHAR *FileName1, WCHAR *FileName2, UINT Hint)
{
    UINT TypeIdx = 0;
    char * sPtr;
    char * TmpsPtr;
    UINT TmpDotIdx;
    int j;

    UINT CheckPoint;
    int OffSet;
    kal_bool ExtNameTieFlag = KAL_FALSE;

    sPtr = kal_dchar_strrchr((char *)FileName1, 0x002e);
    if(sPtr)
    {
     sPtr += 2;
     TypeIdx = (sPtr - (char *)FileName1)/2;
    }

    if(TypeIdx == 0 || (Hint & 0x000000FF) == 0x00000000)
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
       CheckPoint = TypeIdx + 2;
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
       if((FileName2[j+OffSet] == 0x2E) || (fs_util_wchar_toupper(FileName1[j]) > fs_util_wchar_toupper(FileName2[j+OffSet])))
          return 1;
       else if((FileName1[j] == 0x2E) || fs_util_wchar_toupper(FileName1[j]) < fs_util_wchar_toupper(FileName2[j+OffSet]))
          return -1;
    }
    return 0;
}

/* ------------------------------------------------------------------------------- */
/* This function is to create heap */
int CreateHeap(FS_SortingParam *Param, FSSortingInternalS *SortingData)
{
    RTFHANDLE FHandle = 0;

    RTFDirLocation *PosList;
    UINT *HintList;
    //UINT *HintList2;
    RTFDirLocation *PosList_File;
    UINT *HintList_File;
    UINT *HintList2_File;
    UINT MaxNameLength = 4;
    UINT NameLength;

    int index = 1;
    int Count = 0;

    int index_File = -1;
    int Count_File = 0;

    int Total_Count = 0;

    int Result;
    int Flag = Param->Flag;
    int MaxCount = SortingData->MaxCount;

    int s, p;

    WCHAR * TmpName;
    WCHAR * FileName = (WCHAR *)SortingData->FileName;
    RTFDOSDirEntry *FileInfo = (RTFDOSDirEntry *)SortingData->FileInfo;

    kal_uint32  LastPgsTime = 0;

    #ifdef __FS_OPEN_HINT__
    /*
     * If Param->Pattern is end with '\\', e.g., X:\\A\\, then we will find out "A", not files
     * inside folder "A". This will let FS_XFindStart->MTHintNewManual add wrong hint path.
     *
     * Thus we disable hint operation in this case.
     */
    for (TmpName = Param->Pattern; *TmpName != '\0'; TmpName++);

    if (*(TmpName - 1) == '\\')
        SortingData->Flag |= FS_SORTING_IS_FLAG_HINT_DISABLED;
    #endif

    TmpName = (WCHAR *)SortingData->TmpName1;
    PosList = SortingData->PosList;
    HintList = SortingData->HintList;
    //HintList2 = SortingData->HintList2;
    PosList_File = SortingData->PosList_File;
    HintList_File = SortingData->HintList_File;
    HintList2_File = SortingData->HintList2_File;

    if(Param->ProgressCallback)
    {
        SortingData->Status = FS_SORT_PGS_PREPARE;
        if(Param->ProgressCallback(FS_SORT_PGS_PREPARE, 0, 0, Param->ProgressCallbackParam)<0)
        {
            return MT_ABORTED_ERROR;
        }
    }

    /* 1. Load all the directory entry to create heap */
    if(Flag & FS_DIR_TYPE)
         FHandle = FindFirst((WCHAR *)Param->Pattern, Param->PatternArray, Param->PatternNum, Param->ArrayMask, 0, Param->AttrMask, FileInfo, (WCHAR *)FileName, MT_MAX_WIDE_NAME, PosList_File + index_File, &(SortingData->DirCluster));
    else
         FHandle = FindFirst((WCHAR *)Param->Pattern, Param->PatternArray, Param->PatternNum, Param->ArrayMask, 0, Param->AttrMask|RTF_ATTR_DIR, FileInfo, (WCHAR *)FileName, MT_MAX_WIDE_NAME, PosList_File + index_File, &(SortingData->DirCluster));

    if(FHandle >= RTF_NO_ERROR)
    {
        if(!WFNamesMatch((char *)FileName, (char *)dchar_dot))
        {//Don't worry about dchar_dot_dot here

             NameLength = kal_dchar_strlen((char*)FileName);
             MaxNameLength = MaxNameLength>NameLength? MaxNameLength: NameLength;

             if((FileInfo->Attributes & RTF_ATTR_DIR) && (Flag & FS_DIR_TYPE))
             {//----------------------------- Sort Folder ------------------------------------
                // Setup default hint information to the new file.
                PosList[index].Cluster = PosList_File[index_File].Cluster;
                PosList[index].Index = PosList_File[index_File].Index;

                if(Flag & (FS_SORT_USER|FS_SORT_NAME|FS_SORT_TYPE|FS_SORT_SIZE))
                {
                  Param->CompareFunc(FileName, (UINT*)(HintList+index), (WCHAR*)L"", NULL);
                }
                else if(Flag & FS_SORT_ATTR)
                {
                  HintList[index] = FileInfo->Attributes;
                }
                else if(Flag & FS_SORT_TIME)
                {
                  HintList[index] = 0xFFFFFFFF - ((FileInfo->DateTime.Year1980*12*31*24*60*60) +
                                    (FileInfo->DateTime.Month*31*24*60*60) +
                                    (FileInfo->DateTime.Day*24*60*60) +
                                    (FileInfo->DateTime.Hour*60*60) +
                                    (FileInfo->DateTime.Minute*60) +
                                    (FileInfo->DateTime.Second2));
                }
                else if(Flag & FS_NO_SORT)
                {
                }
                else
                {
                   Result = RTF_PARAM_ERROR;
                   goto SortReturn;
                }
                Total_Count ++;
                Count++;
                index++;
             }
             else if(!(FileInfo->Attributes & RTF_ATTR_DIR) && (Flag & FS_FILE_TYPE))
             {//----------------------------- Sort File ------------------------------------
                if(Flag & (FS_SORT_USER|FS_SORT_NAME))
                {
                  Param->CompareFunc(FileName, (UINT*)(HintList_File+index_File), (WCHAR*)L"", NULL);
                }
                else if(Flag & FS_SORT_TYPE)
                {
                  char * sPtr;

                  sPtr = kal_dchar_strrchr((char *)FileName, 0x002e);
                  if(sPtr)
                  {
                     HintList_File[index_File] = FileUintHint((WCHAR*)(sPtr+2));
                  }
                  HintList2_File[index_File] = (fs_util_wchar_toupper(FileName[0])<<16) + fs_util_wchar_toupper(FileName[1]);
                }
                else if(Flag & FS_SORT_ATTR)
                {
                  HintList_File[index_File] = FileInfo->Attributes;
                }
                else if(Flag & FS_SORT_SIZE)
                {
                  HintList_File[index_File] = FileInfo->FileSize;
                }
                else if(Flag & FS_SORT_TIME)
                {
                  HintList_File[index_File] = 0xFFFFFFFF - ((FileInfo->DateTime.Year1980*12*31*24*60*60) +
                                    (FileInfo->DateTime.Month*31*24*60*60) +
                                    (FileInfo->DateTime.Day*24*60*60) +
                                    (FileInfo->DateTime.Hour*60*60) +
                                    (FileInfo->DateTime.Minute*60) +
                                    (FileInfo->DateTime.Second2));
                }
                else if(Flag & FS_NO_SORT)
                {
                }
                else
                {
                   Result = RTF_PARAM_ERROR;
                   goto SortReturn;
                }
                Total_Count ++;
                Count_File--;
                index_File--;
             }
        }

        while((Result = fs_srv_findnext(FHandle, Param->PatternArray, Param->PatternNum, Param->ArrayMask, (FS_DOSDirEntry*)FileInfo, (WCHAR *)FileName, MT_MAX_WIDE_NAME, FS_FIND_DEFAULT, (FS_FileLocationHint*)(PosList+index) ))  == RTF_NO_ERROR)
        {
            /* Check Progress */
            if (LastPgsTime != (GetTime() & MT_PGS_PERIOD_MASK))
            {
                LastPgsTime = GetTime() & MT_PGS_PERIOD_MASK;
                if(Param->ProgressCallback && Param->ProgressCallback(FS_SORT_PGS_PREPARE, 0, 0, Param->ProgressCallbackParam)<0)
                {
                    Result = MT_ABORTED_ERROR;
                    goto SortErrorReturn;
                }
            }

            if(Result >= RTF_NO_ERROR)
            {
                if(!WFNamesMatch((char *)FileName, (char *)dchar_dot_dot))
                {//Don't worry about dchar_dot here
                    NameLength = kal_dchar_strlen((char*)FileName);
                    MaxNameLength = MaxNameLength>NameLength? MaxNameLength: NameLength;

                    if((FileInfo->Attributes & RTF_ATTR_DIR) && (Flag & FS_DIR_TYPE))
                    {
                        // Setup default hint information to the new file.
                        if(Flag & (FS_SORT_USER|FS_SORT_NAME|FS_SORT_TYPE|FS_SORT_SIZE))
                        {
                            Param->CompareFunc(FileName, (UINT*)(HintList+index), (WCHAR*)L"", NULL);
                        }
                        else if(Flag & FS_SORT_ATTR)
                        {
                            HintList[index] = FileInfo->Attributes;
                        }
                        else if(Flag & FS_SORT_TIME)
                        {
                            HintList[index] = 0xFFFFFFFF - ((FileInfo->DateTime.Year1980*12*31*24*60*60) +
                                          (FileInfo->DateTime.Month*31*24*60*60) +
                                          (FileInfo->DateTime.Day*24*60*60) +
                                          (FileInfo->DateTime.Hour*60*60) +
                                          (FileInfo->DateTime.Minute*60) +
                                          (FileInfo->DateTime.Second2));
                        }
                        else if(Flag & FS_NO_SORT)
                        {
                        }
                        else
                        {
                            Result = RTF_PARAM_ERROR;
                            goto SortReturn;
                        }
                        Total_Count ++;
                        Count++;
                        index++;

                        s = Count;
                        p = Count>>1;

                        while(ABS(s)>=2)
                        {
                            // Check hint first
                            if(HintList[p]<HintList[s])
                            {
                                break;
                            }
                            else if(HintList[p]==HintList[s])
                            {
                                if(Flag & (FS_SORT_NAME|FS_SORT_USER|FS_SORT_TYPE|FS_SORT_SIZE))
                                {
                                    //Result = GetFindByPos(Param->Pattern, FileInfo, TmpName, MT_MAX_FILE_NUM, &PosList[p], FS_FIND_DEFAULT);
                                    Result = fs_srv_get_name_by_pos(NULL, Param->Pattern, FileInfo, TmpName, MT_MAX_WIDE_PATH, &PosList[p], FS_FIND_DEFAULT);

                                    if(Result < RTF_NO_ERROR)
                                       goto SortErrorReturn;

                                    if(Param->CompareFunc(FileName, NULL, TmpName, NULL)>=0)
                                    {
                                        goto NextFile;
                                    }
                                }
                                else
                                {
                                    goto NextFile;
                                }
                            }

                            // Swap the hint information
                            SWAP_SORTING_ENTRY(p, s);

                            s = p;
                            p = s/2;
                        }
                    }
                    else if(!(FileInfo->Attributes & RTF_ATTR_DIR) && (Flag & FS_FILE_TYPE))
                    {
                        PosList_File[index_File].Cluster = PosList[index].Cluster;
                        PosList_File[index_File].Index = PosList[index].Index;

                        if(Flag & (FS_SORT_USER|FS_SORT_NAME))
                        {
                            Param->CompareFunc(FileName, (UINT*)(HintList_File+index_File), (WCHAR*)L"", NULL);
                        }
                        else if(Flag & FS_SORT_TYPE)
                        {
                            char * sPtr;

                            sPtr = kal_dchar_strrchr((char *)FileName, 0x002e);
                            if(sPtr)
                            {
                                HintList_File[index_File] = FileUintHint((WCHAR*)(sPtr+2));
                            }
                            else
                            {
                                HintList_File[index_File] = 0;
                            }
                            HintList2_File[index_File] = (fs_util_wchar_toupper(FileName[0])<<16) + fs_util_wchar_toupper(FileName[1]);
                        }
                        else if(Flag & FS_SORT_ATTR)
                        {
                            HintList_File[index_File] = FileInfo->Attributes;
                        }
                        else if(Flag & FS_SORT_SIZE)
                        {
                            HintList_File[index_File] = FileInfo->FileSize;
                        }
                        else if(Flag & FS_SORT_TIME)
                        {
                            HintList_File[index_File] = 0xFFFFFFFF - ((FileInfo->DateTime.Year1980*12*31*24*60*60) +
                                            (FileInfo->DateTime.Month*31*24*60*60) +
                                            (FileInfo->DateTime.Day*24*60*60) +
                                            (FileInfo->DateTime.Hour*60*60) +
                                            (FileInfo->DateTime.Minute*60) +
                                            (FileInfo->DateTime.Second2));
                        }
                        else if(Flag & FS_NO_SORT)
                        {
                        }
                        else
                        {
                            Result = RTF_PARAM_ERROR;
                            goto SortErrorReturn;
                        }
                        Total_Count ++;
                        index_File--;
                        Count_File--;

                        s = Count_File;
                        p = Count_File/2;

                        while(ABS(s)>=2)
                        {
                            // Check hint first
                            if(HintList_File[p]<HintList_File[s])
                            {
                                break;
                            }
                            else if(HintList_File[p]==HintList_File[s])
                            {
                                if(Flag & (FS_SORT_NAME|FS_SORT_USER|FS_SORT_TIME))
                                {
                                    //Result = GetFindByPos(Param->Pattern, FileInfo, TmpName, MT_MAX_FILE_NUM, &PosList_File[p], FS_FIND_DEFAULT);
                                    Result = fs_srv_get_name_by_pos(NULL, Param->Pattern, FileInfo, TmpName, MT_MAX_WIDE_PATH, &PosList_File[p], FS_FIND_DEFAULT);

                                    if(Result < RTF_NO_ERROR)
                                        goto SortErrorReturn;

                                    if(Param->CompareFunc(FileName, NULL, TmpName, NULL)>=0)
                                    {
                                        goto NextFile;
                                    }
                                }
                                else if(Flag & FS_SORT_TYPE)
                                {
                                    if((HintList_File[p]&0x000000FF)!=0 || HintList2_File[p]==HintList2_File[s])
                                    {
                                        //Result = GetFindByPos(Param->Pattern, FileInfo, TmpName, MT_MAX_FILE_NUM, &PosList_File[p], FS_FIND_DEFAULT);
                                        Result = fs_srv_get_name_by_pos(NULL, Param->Pattern, FileInfo, TmpName, MT_MAX_WIDE_PATH, &PosList_File[p], FS_FIND_DEFAULT);

                                        if(Result < RTF_NO_ERROR)
                                            goto SortReturn;

                                        if(CompareFileType(FileName, TmpName, HintList_File[s])>=0)
                                        {
                                          goto NextFile;
                                        }
                                    }
                                    else if(HintList2_File[p]<HintList2_File[s])
                                    {
                                        break;
                                    }
                                }
                                else
                                {
                                    goto NextFile;
                                }
                            }

                            // Swap the hint information
                            SWAP_SORTING_ENTRY_FILE(p, s);
                            if(Flag & FS_SORT_TYPE)
                            {
                                SWAP(HintList2_File[p], HintList2_File[s]);
                            }

                            s = p;
                            p = s/2;
                        }
                    }
                }
            }
            else
            {
                break;
            }
NextFile:
            if(Total_Count>MaxCount)
            {
                Result = RTF_TOO_MANY_FILES;
                goto SortErrorReturn;
            }
        }
    }
    else
    {
        Result = FHandle;
    }
SortReturn:
    if((Result!=RTF_NO_MORE_FILES) && (Result<RTF_NO_ERROR))
    {
        goto SortErrorReturn;
    }
    if(Flag & FS_NO_SORT)
    {
        // SWAP folder
        for(s=1, p=Count; s<p; s++, p--)
        {
            SWAP(PosList[s].Index, PosList[p].Index);
            SWAP(PosList[s].Cluster, PosList[p].Cluster);
        }
        // SWAP file
        for(s=-1, p=Count_File; p<s; s--, p++)
        {
            SWAP(PosList_File[s].Index, PosList_File[p].Index);
            SWAP(PosList_File[s].Cluster, PosList_File[p].Cluster);
        }
    }
    SortingData->FileCount = Count_File;
    SortingData->FolderCount = Count;
    SortingData->TotalCount = Total_Count;

    MaxNameLength = (MaxNameLength+7)&0xFFFFFFFC;
    MaxNameLength = MaxNameLength>MT_MAX_WIDE_PATH?MT_MAX_WIDE_PATH:MaxNameLength;
    SortingData->MaxFileNameLength = MaxNameLength;


    if(FHandle > 0) RTFClose(FHandle);

    return Total_Count;

SortErrorReturn:
    SortingData->FileCount = 0;
    SortingData->FolderCount = 0;
    SortingData->TotalCount = 0;
    SortingData->ReadyCount = 0;

    if(FHandle > 0) RTFClose(FHandle);

    return Result;
}

int CacheGetFindByPos(const WCHAR * Pattern, RTFDOSDirEntry * FileInfo, WCHAR * FileName,
                 UINT MaxLength, RTFDirLocation * Pos, UINT Flag, WCHAR ** CachedName, char **FreeCacheList)
{
    int Result;

    if(Pos->Index&0xFFFF0000)
    { // Cache Hit
        *CachedName = ((WCHAR*)Pos->Cluster)+2;
        return RTF_NO_ERROR;
    }

    // Check if free cache space is available
    if(*FreeCacheList)
    {
        *CachedName = (WCHAR*)*FreeCacheList;
        *FreeCacheList = *((char**)(*FreeCacheList));

        // Save the original Cluster value
        *(int*)*CachedName = Pos->Cluster;

        *CachedName += 2;

        //Result = GetFindByPos(Pattern, FileInfo, *CachedName, MaxLength, Pos, Flag);
        Result = fs_srv_get_name_by_pos(NULL, Pattern, FileInfo, *CachedName, MaxLength, Pos, Flag);

        Pos->Cluster = (int)(*CachedName - 2);
        Pos->Index |= 0x00010000;

        return Result;
    }

    *CachedName = FileName;

    //Result = GetFindByPos(Pattern, FileInfo, *CachedName, MaxLength, Pos, Flag);
    Result = fs_srv_get_name_by_pos(NULL, Pattern, FileInfo, *CachedName, MaxLength, Pos, Flag);

    return Result;
}

int HeapSort(FS_SortingParam *Param, FSSortingInternalS *SortingData)
{
    RTFDirLocation *PosList;
    UINT *HintList;
    UINT *HintList2;

    RTFDirLocation *PosList_File;
    UINT *HintList_File;
    UINT *HintList2_File;

    int m, p, s;

    int Result = RTF_NO_ERROR;
    int Flag = Param->Flag;

    int Progress = 0;
    int CacheCount = 0;

    int MaxFileNameLength = SortingData->MaxFileNameLength;

    kal_uint32  LastPgsTime = 0;

    WCHAR * TmpName1 = (WCHAR *)SortingData->TmpName1;
    WCHAR * TmpName2 = (WCHAR *)SortingData->TmpName2;
    WCHAR * FileName = (WCHAR *)SortingData->FileName;
    WCHAR * CachedTmpName1;
    WCHAR * CachedTmpName2;
    WCHAR * CachedFileName;

    /* Create Free Cache List */
    MaxFileNameLength += 4;

    /* Gather the PosList space */
    PosList = (SortingData->PosList + SortingData->FolderCount + 1);
    PosList_File = (SortingData->PosList_File + SortingData->FileCount - (MaxFileNameLength/4) + 1);

    for(; PosList<PosList_File; PosList = (RTFDirLocation*)((char*)PosList+MaxFileNameLength))
    {
        *((char**)PosList) = SortingData->FreeCacheList;
        SortingData->FreeCacheList = (char*)PosList;
    }

    /* Gather the HintList space */
    HintList = (SortingData->HintList + SortingData->FolderCount + 1);
    HintList_File = (SortingData->HintList_File + SortingData->FileCount - (MaxFileNameLength/4) + 1);

    for(; HintList<HintList_File; HintList = (UINT*)((char*)HintList+MaxFileNameLength))
    {
        *((char**)HintList) = SortingData->FreeCacheList;
        SortingData->FreeCacheList = (char*)HintList;
    }

    /* Gather the HintList2 space */
    if(Flag&FS_SORT_TYPE)
    {
        HintList2 = (SortingData->HintList2 + 1);
        HintList2_File = (SortingData->HintList2_File + SortingData->FileCount - (MaxFileNameLength/4) + 1);
    }
    else
    {
        HintList2 = SortingData->HintList2 + 1;
        HintList2_File = SortingData->HintList2_File - (MaxFileNameLength/4) + 1;
    }

    for(; HintList2<HintList2_File; HintList2 = (UINT*)((char*)HintList2+MaxFileNameLength))
    {
        *((char**)HintList2) = SortingData->FreeCacheList;
        SortingData->FreeCacheList = (char*)HintList2;
    }
    MaxFileNameLength -= 4;

    /* Setup Internal Data */
    PosList = SortingData->PosList;
    HintList = SortingData->HintList;
    HintList2 = SortingData->HintList2;
    PosList_File = SortingData->PosList_File;
    HintList_File = SortingData->HintList_File;
    HintList2_File = SortingData->HintList2_File;

    if(Param->ProgressCallback)
    {
        if(Param->ProgressCallback(FS_SORT_PGS_START, SortingData->TotalCount, 0, Param->ProgressCallbackParam)<0)
        {
            return MT_ABORTED_ERROR;
        }
    }

    SortingData->Status = FS_SORT_PGS_ING;

    m = SortingData->FolderCount;
NextFolder:
    while(m > 1)
    {
        SWAP(PosList[1].Cluster, PosList[m].Cluster);
        SWAP(PosList[1].Index, PosList[m].Index);
        HintList[1] = HintList[m];

        if(PosList[m].Index&0xFFFF0000)
        {
            PosList[m].Index &= 0x0000FFFF;
            p = *((int*)PosList[m].Cluster);
            *((char**)PosList[m].Cluster) = SortingData->FreeCacheList;
            SortingData->FreeCacheList = (char*)PosList[m].Cluster;
            PosList[m].Cluster = p;
        }

        CacheCount+=4;
        if(CacheCount>MaxFileNameLength)
        {
            CacheCount = m<<2;
            *((char**)(((char*)HintList)+CacheCount)) = SortingData->FreeCacheList;
            SortingData->FreeCacheList = ((char*)HintList)+CacheCount;
            CacheCount = 0;
        }

        m--;
        p = 1;
        s = p<<1;

        /* Check Progress */
        if (LastPgsTime != (GetTime() & MT_PGS_PERIOD_MASK))
        {
            LastPgsTime = GetTime() & MT_PGS_PERIOD_MASK;
            SortingData->ReadyCount = Progress;
            if(Param->ProgressCallback && Param->ProgressCallback(FS_SORT_PGS_ING, SortingData->TotalCount, Progress, Param->ProgressCallbackParam)<0)
            {
                return MT_ABORTED_ERROR;
            }
        }

        FileName[0] = 0;

        while(s <= m)
        {
            TmpName1[0] = TmpName2[0] = 0;

            if(s < m)
            {
                if(HintList[s+1] < HintList[s])
                {
                     s++;
                }
                else if(HintList[s+1] == HintList[s])
                {
                    if(Flag & (FS_SORT_NAME|FS_SORT_USER|FS_SORT_TYPE|FS_SORT_SIZE))
                    {
                          Result = CacheGetFindByPos(Param->Pattern, NULL, TmpName1, MaxFileNameLength, &PosList[s], FS_FIND_DEFAULT, &CachedTmpName1, &SortingData->FreeCacheList);
                          if(Result < RTF_NO_ERROR)
                             goto SortReturn;

                          Result = CacheGetFindByPos(Param->Pattern, NULL, TmpName2, MaxFileNameLength, &PosList[s+1], FS_FIND_DEFAULT, &CachedTmpName2, &SortingData->FreeCacheList);
                          if(Result < RTF_NO_ERROR)
                             goto SortReturn;

                          if(Param->CompareFunc(CachedTmpName1, NULL, CachedTmpName2, NULL)>0)
                          {
                             s++;
                          }
                     }
                }
            }

            if(HintList[p] < HintList[s])
            {
                break;
            }
            else if(HintList[p] == HintList[s])  // parent/child primary keys are the same
            {
                if(FileName[0]==0)
                {
                  Result = CacheGetFindByPos(Param->Pattern, NULL, FileName, MaxFileNameLength, &PosList[p], FS_FIND_DEFAULT, &CachedFileName, &SortingData->FreeCacheList);
                  if(Result < RTF_NO_ERROR)
                    goto SortReturn;
                }

                if(s&0x00000001)
                {
                  if(TmpName2[0]==0)
                  {
                       Result = CacheGetFindByPos(Param->Pattern, NULL, TmpName2, MaxFileNameLength, &PosList[s], FS_FIND_DEFAULT, &CachedTmpName2, &SortingData->FreeCacheList);
                       if(Result < RTF_NO_ERROR)
                             goto SortReturn;
                  }

                  if(Flag & (FS_SORT_NAME|FS_SORT_USER|FS_SORT_SIZE|FS_SORT_TYPE))
                  {
                      if(Param->CompareFunc(CachedFileName, NULL, CachedTmpName2, NULL)<=0)
                      {
                         goto NextFolder;
                      }
                  }
                  else
                  {
                      goto NextFolder;
                  }
                }
                else
                {
                  if(TmpName1[0]==0)
                  {
                      Result = CacheGetFindByPos(Param->Pattern, NULL, TmpName1, MaxFileNameLength, &PosList[s], FS_FIND_DEFAULT, &CachedTmpName1, &SortingData->FreeCacheList);
                      if(Result < RTF_NO_ERROR)
                          goto SortReturn;
                  }

                  if(Flag & (FS_SORT_NAME|FS_SORT_USER|FS_SORT_SIZE|FS_SORT_TYPE))
                  {
                      if(Param->CompareFunc(CachedFileName, NULL, CachedTmpName1, NULL)<=0)
                      {
                         goto NextFolder;
                      }
                  }
                  else
                  {
                      goto NextFolder;
                  }
               }
            }

            SWAP_SORTING_ENTRY(p, s);

            p = s;
            s = p<<1;
        }
        Progress ++;
    }

    if(m==1 && PosList[1].Index&0xFFFF0000)
    {
        PosList[1].Index &= 0x0000FFFF;
        p = *((int*)PosList[1].Cluster);
        *((char**)PosList[1].Cluster) = SortingData->FreeCacheList;
        SortingData->FreeCacheList = (char*)PosList[1].Cluster;
        PosList[1].Cluster = p;
    }

    CacheCount = 0;
    m = SortingData->FileCount;
NextFile:
    while(m < -1)
    {
        SWAP(PosList_File[-1].Cluster ,PosList_File[m].Cluster);
        SWAP(PosList_File[-1].Index ,PosList_File[m].Index);
        HintList_File[-1] = HintList_File[m];
        HintList2_File[-1] = HintList2_File[m];

        if(PosList_File[m].Index&0xFFFF0000)
        {
            PosList_File[m].Index &= 0x0000FFFF;
            p = *(int*)PosList_File[m].Cluster;
            *((char**)PosList_File[m].Cluster) = SortingData->FreeCacheList;
            SortingData->FreeCacheList = (char*)PosList_File[m].Cluster;
            PosList_File[m].Cluster = p;
        }

        CacheCount+=4;
        if(CacheCount>MaxFileNameLength)
        {
            CacheCount = (m<<2) - CacheCount + 4;
            *((char**)(((char*)HintList_File)+CacheCount)) = SortingData->FreeCacheList;

            if(Flag & FS_SORT_TYPE)
            {
                *((char**)(((char*)HintList2_File)+CacheCount)) = ((char*)HintList_File)+CacheCount;
                SortingData->FreeCacheList = ((char*)HintList2_File)+CacheCount;
            }
            else
            {
                SortingData->FreeCacheList = ((char*)HintList_File)+CacheCount;
            }
            CacheCount = 0;
        }

        m++;
        p = -1;
        s = p<<1;

        /* Check Progress */
        if (LastPgsTime != (GetTime() & MT_PGS_PERIOD_MASK))
        {
            LastPgsTime = GetTime() & MT_PGS_PERIOD_MASK;
            SortingData->ReadyCount = Progress;
            if(Param->ProgressCallback && Param->ProgressCallback(FS_SORT_PGS_ING, SortingData->TotalCount, Progress, Param->ProgressCallbackParam)<0)
            {
                return MT_ABORTED_ERROR;
            }
        }

        FileName[0] = 0;

        while(s >= m)
        {
            TmpName1[0] = TmpName2[0] = 0;

            if(s > m)
            {
                if(HintList_File[s-1] < HintList_File[s])
                {
                     s--;
                }
                else if(HintList_File[s-1] == HintList_File[s])
                {
                    // primary key are the same, compare file name
                    if(Flag & (FS_SORT_NAME|FS_SORT_USER|FS_SORT_TIME))
                    {
                        Result = CacheGetFindByPos(Param->Pattern, NULL, TmpName1, MaxFileNameLength, &PosList_File[s], FS_FIND_DEFAULT, &CachedTmpName1, &SortingData->FreeCacheList);
                        if(Result < RTF_NO_ERROR)
                           goto SortReturn;

                        Result = CacheGetFindByPos(Param->Pattern, NULL, TmpName2, MaxFileNameLength, &PosList_File[s-1], FS_FIND_DEFAULT, &CachedTmpName2, &SortingData->FreeCacheList);
                        if(Result < RTF_NO_ERROR)
                           goto SortReturn;

                        if(Param->CompareFunc(CachedTmpName1, NULL, CachedTmpName2, NULL)>0)
                        {
                           s--;
                        }
                    }
                    else if(Flag & FS_SORT_TYPE)
                    {
                        if((HintList_File[s]&0x000000FF)!=0 || HintList2_File[s-1] == HintList2_File[s])
                        {
                            Result = CacheGetFindByPos(Param->Pattern, NULL, TmpName1, MaxFileNameLength, &PosList_File[s], FS_FIND_DEFAULT, &CachedTmpName1, &SortingData->FreeCacheList);
                            if(Result < RTF_NO_ERROR)
                               goto SortReturn;

                            Result = CacheGetFindByPos(Param->Pattern, NULL, TmpName2, MaxFileNameLength, &PosList_File[s-1], FS_FIND_DEFAULT, &CachedTmpName2, &SortingData->FreeCacheList);
                            if(Result < RTF_NO_ERROR)
                               goto SortReturn;

                            if(CompareFileType(CachedTmpName1, CachedTmpName2, HintList_File[s])>0)
                            {
                                s--;
                            }
                        }
                        else if(HintList2_File[s-1] < HintList2_File[s])
                        {
                             s--;
                        }
                    }
                }
            }

            if(HintList_File[p] < HintList_File[s])
            {
                break;
            }
            // primary key are the same, compare file name
            else if(HintList_File[p] == HintList_File[s])
            {
                if ((Flag & FS_SORT_TYPE)&&((HintList_File[p] & 0x000000FF)==0))
                {
                    if(HintList2_File[p] < HintList2_File[s])
                    {
                        break;
                    }
                    else if(HintList2_File[p] > HintList2_File[p])
                    {
                        SWAP(HintList2_File[p], HintList2_File[s]);
                        goto Do_Swap_File;
                    }
                }
                // sort by size and attribute will not use file name as secondary key
                else if(Flag & (FS_SORT_SIZE|FS_SORT_ATTR))
                {
                    break;
                }

                if(FileName[0]==0)
                {
                  Result = CacheGetFindByPos(Param->Pattern, NULL, FileName, MaxFileNameLength, &PosList_File[p], FS_FIND_DEFAULT, &CachedFileName, &SortingData->FreeCacheList);
                  if(Result < RTF_NO_ERROR)
                    goto SortReturn;
                }

                if(s&0x00000001)  // right child node
                {
                  if(Flag & (FS_SORT_NAME|FS_SORT_USER|FS_SORT_TIME))
                  {
                      if(TmpName2[0]==0)
                      {
                           Result = CacheGetFindByPos(Param->Pattern, NULL, TmpName2, MaxFileNameLength, &PosList_File[s], FS_FIND_DEFAULT, &CachedTmpName2, &SortingData->FreeCacheList);
                           if(Result < RTF_NO_ERROR)
                              goto SortReturn;
                      }

                     if(Param->CompareFunc(CachedFileName, NULL, CachedTmpName2, NULL)<=0)
                      {
                          goto NextFile;
                      }
                  }
                  else if(Flag & FS_SORT_TYPE)
                  {
                    if(TmpName2[0]==0)
                    {
                         Result = CacheGetFindByPos(Param->Pattern, NULL, TmpName2, MaxFileNameLength, &PosList_File[s], FS_FIND_DEFAULT, &CachedTmpName2, &SortingData->FreeCacheList);
                         if(Result < RTF_NO_ERROR)
                            goto SortReturn;
                    }

                    if(CompareFileType(CachedFileName, CachedTmpName2, HintList_File[s])<=0)
                    {
                         goto NextFile;
                    }
                    SWAP(HintList2_File[p], HintList2_File[s]);
                  }
                  else
                  {
                         goto NextFile;
                  }
                }
                else   // left child node
                {
                  if(Flag & (FS_SORT_NAME|FS_SORT_USER|FS_SORT_TIME))
                  {
                     if(TmpName1[0]==0)
                     {
                         Result = CacheGetFindByPos(Param->Pattern, NULL, TmpName1, MaxFileNameLength, &PosList_File[s], FS_FIND_DEFAULT, &CachedTmpName1, &SortingData->FreeCacheList);
                         if(Result < RTF_NO_ERROR)
                             goto SortReturn;
                     }

                     if(Param->CompareFunc(CachedFileName, NULL, CachedTmpName1, NULL)<=0)
                     {
                         goto NextFile;
                     }
                  }
                  else if(Flag & FS_SORT_TYPE)
                  {
                     if(TmpName1[0]==0)
                     {
                         Result = CacheGetFindByPos(Param->Pattern, NULL, TmpName1, MaxFileNameLength, &PosList_File[s], FS_FIND_DEFAULT, &CachedTmpName1, &SortingData->FreeCacheList);
                         if(Result < RTF_NO_ERROR)
                             goto SortReturn;
                     }

                    if(CompareFileType(CachedFileName, CachedTmpName1, HintList_File[s])<=0)
                    {
                        goto NextFile;
                    }
                    SWAP(HintList2_File[p], HintList2_File[s]);
                  }
                  else
                  {
                        goto NextFile;
                  }
                }
            }
            else
            {
                if(Flag & FS_SORT_TYPE)
                {
                    SWAP(HintList2_File[p], HintList2_File[s]);
                }
            }

Do_Swap_File:
            SWAP_SORTING_ENTRY_FILE(p, s);

            p = s;
            s = p<<1;
        }
        Progress ++;
    }

    if(m==-1 && PosList_File[-1].Index&0xFFFF0000)
    {
        PosList_File[-1].Index &= 0x0000FFFF;
        PosList_File[-1].Cluster = *(int*)PosList_File[-1].Cluster;
    }

SortReturn:
    SortingData->ReadyCount = SortingData->TotalCount;

    return Result;
}

#endif

#ifdef __AUDIO_DSP_LOWPOWER__

#define FS_PMAPQUERY_MAX_CLUSTER_COUNT  (16)

int MTQueryPhysicalMap(FS_PMapInfo* PMapInfo)
{
    kal_uint32          dev_type;
    kal_uint32          fpos_ori = 0xFFFFFFFF;
    kal_uint32          sec_cur, sec_cnt;
    kal_uint32          cluster_cur, cluster_next;
    kal_uint16 volatile valid_entry_cnt;
    kal_uint16          total_entry_cnt;
    kal_int32 volatile  result = RTF_NO_ERROR;
    RTFile * volatile   f        = NULL;
    FS_NANDPMapQuery    NANDQueryData;
    FS_CardPMapEntry   *pCardEntry;

    XTRY
        case XCODE:

        f = ParseFileHandle(PMapInfo->FH);

        // check parameters
        if (NormalFile != f->SpecialKind)
        {
            XRAISE(RTF_PARAM_ERROR);
        }

        // check start file offset
        if (PMapInfo->Offset & 0x1FF)
        {
            XRAISE(RTF_PARAM_ERROR);
        }

        // check supported device type
        dev_type = fs_conf_get_devtype_by_devflag(f->Dev->DeviceFlags);

        if ((dev_type != FS_DEVICE_TYPE_NAND) && (dev_type != FS_DEVICE_TYPE_CARD))
        {
            XRAISE(RTF_PARAM_ERROR);
        }
        else
        {
            PMapInfo->DevType = dev_type;
        }

        // buffer should be 4-byte aligned
        if ((PMapInfo->pBuf == NULL) || ((UINT)(PMapInfo->pBuf) & 0x3 != 0))
        {
            XRAISE(MT_FAIL_GET_MEM);
        }

        // keep original file pointer
        fpos_ori = f->FilePointer;

        // go to start point of map transformation
        result = RTFSeek(PMapInfo->FH, PMapInfo->Offset, RTF_FILE_BEGIN);

        if (result < RTF_NO_ERROR) XRAISE(result);

        // get free start address of map entries and entry count
        if (FS_DEVICE_TYPE_NAND == dev_type)
        {
            total_entry_cnt = (PMapInfo->BufSize - sizeof(FS_NANDPMapHeader)) / sizeof(FS_NANDPMapEntry);

            // initialize query data for NAND
            NANDQueryData.pBuf      = (FS_NANDPMapEntry*)(PMapInfo->pBuf + sizeof(FS_NANDPMapHeader));
            NANDQueryData.BufSize   = total_entry_cnt * sizeof(FS_NANDPMapEntry);
        }
        else // FS_DEVICE_TYPE_CARD
        {
            pCardEntry = (FS_CardPMapEntry*)PMapInfo->pBuf;
            total_entry_cnt = PMapInfo->BufSize / sizeof(FS_CardPMapEntry);
        }

        if (0 == f->Cluster)
        {
            XRAISE(RTF_INVALID_FILE_POS);
        }

        sec_cur = CLUSTER_TO_SECTOR_OFS(f->Drive, f->Cluster, f->Offset);

        // handle f->Cluster
        sec_cnt = f->Drive->ClusterSize - f->Offset;
        sec_cnt = ((sec_cnt - 1) / f->Dev->DevData.SectorSize) + 1;

        // now cluster_cur is handled, enter while-loop to handle next cluster
        cluster_cur = f->Cluster;
        valid_entry_cnt = 0;

        // do until buffer is full (handle "cluster_next")
        while (valid_entry_cnt < total_entry_cnt)
        {
            cluster_next = GetClusterValue(f->Drive, cluster_cur);

            // chain is fragmented or terminated
            if ((cluster_next != cluster_cur + 1) || (sec_cnt >= FS_PMAPQUERY_MAX_CLUSTER_COUNT))
            {
                if (FS_DEVICE_TYPE_NAND == dev_type)
                {
                    // prepare query data for NAND driver
                    NANDQueryData.LSN              = sec_cur;
                    NANDQueryData.LSCnt            = sec_cnt;
                    NANDQueryData.ValidEntryCnt    = 0;
                    NANDQueryData.XferCnt          = 0;
                    NANDQueryData.ChipSel          = 0;

                    result = f->Dev->Driver->IOCtrl(f->Dev->DriverData, FS_IOCTRL_QUERY_PHYSICAL_MAP, (void*)&NANDQueryData);

                    if (result < RTF_NO_ERROR) XRAISE(result);

                    // update buffer information
                    NANDQueryData.BufSize   -= (NANDQueryData.ValidEntryCnt * sizeof(FS_NANDPMapEntry));
                    NANDQueryData.pBuf      += NANDQueryData.ValidEntryCnt;
                    valid_entry_cnt         += NANDQueryData.ValidEntryCnt;
                }
                else // FS_DEVICE_TYPE_CARD
                {
                    pCardEntry->SN          = sec_cur;
                    pCardEntry->SecCnt      = sec_cnt;

                    valid_entry_cnt++;
                    pCardEntry++;
                }

                if (cluster_next >= RTF_CHAIN_END_MARK) // this is the last cluster, we are done
                    break;
                else
                {
                    // get start sector no. of next continuous chain
                    sec_cur = CLUSTER_TO_SECTOR_OFS(f->Drive, cluster_next, 0);
                    sec_cnt = (f->Drive->ClusterSize / f->Dev->DevData.SectorSize);
                }
            }
            else // cluster_next == cluster_cur + 1
            {
                sec_cnt += (f->Drive->ClusterSize / f->Dev->DevData.SectorSize);
            }

            cluster_cur = cluster_next;
        }

        break;
    default:
        result = XVALUE;
        XHANDLED;
        break;
    case XFINALLY:
        if (result >= RTF_NO_ERROR)
        {
            PMapInfo->ValidEntryCnt = valid_entry_cnt;

            // update ChipSel for NAND device
            if (FS_DEVICE_TYPE_NAND == dev_type)
            {
                ((FS_NANDPMap*)(PMapInfo->pBuf))->Header.ChipSel = NANDQueryData.ChipSel;
            }

            result = RTF_NO_ERROR;
        }

        // restore file pointer
        if (fpos_ori != 0xFFFFFFFF)
        {
            RTFSeek(PMapInfo->FH, fpos_ori, RTF_FILE_BEGIN);
        }

        if (f != NULL) UnlockDevice(f->Dev);
    XENDX

    return result;
}
#endif // __AUDIO_DSP_LOWPOWER__

