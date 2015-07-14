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
 *   ccci_fssvc.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Header file of ccci_fssvc.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/




#ifndef __CCCI_FSSVC_H__
#define __CCCI_FSSVC_H__

#if defined(__MODEM_CCCI_EXIST__)

#include "fs_type.h"

/*******************************************************************************
 * File System op code
 *******************************************************************************/
typedef enum
{
    FS_CCCI_OP_OPEN = 0x1001,
    FS_CCCI_OP_SEEK,
    FS_CCCI_OP_READ,
    FS_CCCI_OP_WRITE,
    FS_CCCI_OP_CLOSE,
    FS_CCCI_OP_CLOSEALL,
    FS_CCCI_OP_CREATEDIR,
    FS_CCCI_OP_REMOVEDIR,
    FS_CCCI_OP_GETFILESIZE,
    FS_CCCI_OP_GETFOLDERSIZE,
    FS_CCCI_OP_RENAME,
    FS_CCCI_OP_MOVE,
    FS_CCCI_OP_COUNT,
    FS_CCCI_OP_GETDISKINFO,
    FS_CCCI_OP_DELETE,
    FS_CCCI_OP_GETATTRIBUTES,
    FS_CCCI_OP_OPENHINT,
    FS_CCCI_OP_FINDFIRST,
    FS_CCCI_OP_FINDNEXT,
    FS_CCCI_OP_FINDCLOSE,
    FS_CCCI_OP_LOCKFAT,
    FS_CCCI_OP_UNLOCKALL,
    FS_CCCI_OP_SHUTDOWN,
    FS_CCCI_OP_XDELETE,
    FS_CCCI_OP_CLEARDISKFLAG,
    FS_CCCI_OP_GETDRIVE,
    FS_CCCI_OP_GETCLUSTERSIZE,
    FS_CCCI_OP_SETDISKFLAG,
    FS_CCCI_OP_OTPWRITE,
    FS_CCCI_OP_OTPREAD,
    FS_CCCI_OP_OTPQUERYLENGTH,
    FS_CCCI_OP_OTPLOCK,
    FS_CCCI_OP_RESTORE = 0x1021

} FS_CCCI_OP_ID_T;


/*******************************************************************************
 * Declare function prototype.
 *******************************************************************************/

// General I/O
kal_int32 MD_FS_Open(const WCHAR * FileName, kal_uint32 Flag);
kal_int32 MD_FS_OpenHint(const WCHAR * FileName, kal_uint32 Flag, FS_FileOpenHint * DSR_Hint);
kal_int32 MD_FS_Close(FS_HANDLE FileHandle);
kal_int32 MD_FS_CloseAll(void);
kal_int32 MD_FS_Read(FS_HANDLE FileHandle, void * DataPtr, kal_uint32 Length, kal_uint32 * Read);
kal_int32 MD_FS_Write(FS_HANDLE FileHandle, void * DataPtr, kal_uint32 Length, kal_uint32 * Written);
kal_int32 MD_FS_Seek(FS_HANDLE FileHandle, kal_int32 Offset, kal_int32 Whence);

//Information
kal_int32 MD_FS_GetFileSize(FS_HANDLE FileHandle, kal_uint32 * Size);
kal_int32 MD_FS_GetAttributes(const WCHAR * FileName);

//File Only Operation
kal_int32 MD_FS_Delete(const WCHAR * FileName);

//Folder Only Operation
kal_int32 MD_FS_CreateDir(const WCHAR * DirName);
kal_int32 MD_FS_RemoveDir(const WCHAR * DirName);
kal_int32 MD_FS_GetFolderSize(const WCHAR *DirName, kal_uint32 Flag, kal_uint8 *RecursiveStack, const kal_uint32 StackSize);

//File and Folder Operations
kal_int32 MD_FS_Rename(const WCHAR * FileName, const WCHAR * NewName);
kal_int32 MD_FS_Move(const WCHAR * SrcFullPath, const WCHAR * DstFullPath, kal_uint32 Flag, FS_ProgressCallback Progress, kal_uint8 *RecursiveStack, const kal_uint32 StackSize);

kal_int32 MD_FS_Count(const WCHAR * FullPath, kal_uint32 Flag, kal_uint8 *RecursiveStack, const kal_uint32 StackSize);
kal_int32 MD_FS_XDelete(const WCHAR * FullPath, kal_uint32 Flag, kal_uint8 *RecursiveStack, const kal_uint32 StackSize);

//Find File
kal_int32 MD_FS_FindFirst(const WCHAR * NamePattern, kal_uint8 Attr, kal_uint8 AttrMask, FS_DOSDirEntry * FileInfo, WCHAR * FileName, kal_uint32 MaxLength);
kal_int32 MD_FS_FindNext(FS_HANDLE FileHandle, FS_DOSDirEntry * FileInfo, WCHAR * FileName, kal_uint32 MaxLength);
kal_int32 MD_FS_FindClose(FS_HANDLE FileHandle);

//Drive Management
kal_int32 MD_FS_GetDrive(kal_uint32 Type, kal_uint32 Serial, kal_uint32 AltMask);
kal_int32 MD_FS_GetClusterSize(kal_uint32 DriveIdx);

//Power Lost Detection and Recovery
kal_int32 MD_FS_SetDiskFlag(void);

//kal_int32 MD_FS_CheckDiskFlag(void);
kal_int32 MD_FS_ClearDiskFlag(void);

//Disk Management
kal_int32 MD_FS_GetDiskInfo(const WCHAR * DriveName, FS_DiskInfo * DiskInfo, kal_int32 Flags);

//Card management

//File System Run-Time LifeCycle
void MD_FS_ShutDown(void);
kal_int32 MD_FS_UnlockAll(void);
kal_int32 MD_FS_LockFAT(kal_uint32 Type);

//File System Run-Time Debug

//DirCache

//Flash Device Direct IO
kal_int32 MD_FS_OTPWrite(kal_int32 devtype, kal_uint32 Offset, void * BufferPtr, kal_uint32 Length);
kal_int32 MD_FS_OTPRead(kal_int32 devtype, kal_uint32 Offset, void * BufferPtr, kal_uint32 Length);
kal_int32 MD_FS_OTPQueryLength(kal_int32 devtype, kal_uint32 *Length);
kal_int32 MD_FS_OTPLock(kal_int32 devtype);

kal_int32 MD_FS_Restore(const WCHAR * FileName, void* pBuffer, kal_uint32 Length);

#endif /* #if defined(__MODEM_CCCI_EXIST__) */

#endif  /* __CCCI_FSSVC_H__ */


