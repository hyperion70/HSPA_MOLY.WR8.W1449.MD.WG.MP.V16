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
 *   ccci_fssvc.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*******************************************************************************
 * Include header files
 *******************************************************************************/

#if defined(__MODEM_CCCI_EXIST__)

#include <stdarg.h>

#include "kal_public_api.h"

#include "ccci.h"
#include "fs_type.h"
#include "ccif.h"
#include "fs_ccci.h"
#include "ccci_fssvc.h"

/*******************************************************************************
 * Define import global variables.
 *******************************************************************************/


/*******************************************************************************
 * Define import function prototype.
 *******************************************************************************/
kal_int32 FS_CCCI_Wrapper(FS_CCCI_OP_ID_T fs_op,...);

/********************************************************************************
 * Define global variables.
 ********************************************************************************/

/* Modem */
kal_int32 MD_FS_Open(const WCHAR * FileName, kal_uint32 Flag)
{
    kal_uint32 n_filename = kal_dchar_strlen((const char *)FileName) + sizeof(WCHAR);

    return FS_CCCI_Wrapper(FS_CCCI_OP_OPEN, n_filename,			(void *)FileName,
                           sizeof(kal_uint32),	(void *)&Flag,		FS_CCCI_INPUT_TERM_PATTERN,
                           FS_CCCI_EOF_TERM_PATTERN);
}

kal_int32 MD_FS_OpenHint(const WCHAR * FileName, kal_uint32 Flag, FS_FileOpenHint * DSR_Hint)
{
    kal_uint32 n_filename = kal_dchar_strlen((const char *)FileName) + sizeof(WCHAR);

    return FS_CCCI_Wrapper(FS_CCCI_OP_OPENHINT,	n_filename,					(void *)FileName,
                           sizeof(kal_uint32),			(void *)&Flag,
                           sizeof(FS_FileOpenHint),	(void *)DSR_Hint,	FS_CCCI_INPUT_TERM_PATTERN,
                           sizeof(FS_FileOpenHint),	(void *)DSR_Hint,	FS_CCCI_EOF_TERM_PATTERN);
}

kal_int32 MD_FS_Close(FS_HANDLE FileHandle)
{
    return FS_CCCI_Wrapper(FS_CCCI_OP_CLOSE,	sizeof(FS_HANDLE), (void *)&FileHandle, FS_CCCI_INPUT_TERM_PATTERN,
                           FS_CCCI_EOF_TERM_PATTERN);
}

kal_int32 MD_FS_Read(FS_HANDLE FileHandle, void * DataPtr, kal_uint32 Length, kal_uint32 * Read)
{
    return FS_CCCI_Wrapper(FS_CCCI_OP_READ, sizeof(FS_HANDLE),	(void *)&FileHandle,
                           sizeof(kal_uint32), (void *)&Length,		FS_CCCI_INPUT_TERM_PATTERN,
                           sizeof(kal_uint32), (void *)Read,
                           Length, 			(void*) DataPtr, 		FS_CCCI_EOF_TERM_PATTERN);
}

kal_int32 MD_FS_Write(FS_HANDLE FileHandle, void * DataPtr, kal_uint32 Length, kal_uint32 * Written)
{
    return FS_CCCI_Wrapper(FS_CCCI_OP_WRITE,	sizeof(FS_HANDLE),	(void *)&FileHandle,
                           Length,				(void *)DataPtr,
                           sizeof(kal_uint32), (void *)&Length, FS_CCCI_INPUT_TERM_PATTERN,
                           sizeof(kal_uint32), (void *)Written, FS_CCCI_EOF_TERM_PATTERN);
}

kal_int32 MD_FS_Seek(FS_HANDLE FileHandle, kal_int32 Offset, kal_int32 Whence)
{
    return FS_CCCI_Wrapper(FS_CCCI_OP_SEEK, sizeof(FS_HANDLE), (void *)&FileHandle,
                           sizeof(kal_int32), (void *)&Offset,
                           sizeof(kal_int32), (void *)&Whence, FS_CCCI_INPUT_TERM_PATTERN,
                           FS_CCCI_EOF_TERM_PATTERN);
}

kal_int32 MD_FS_GetFileSize(FS_HANDLE FileHandle, kal_uint32 * Size)
{
    return FS_CCCI_Wrapper(FS_CCCI_OP_GETFILESIZE,	sizeof(FS_HANDLE),	(void *)&FileHandle,	FS_CCCI_INPUT_TERM_PATTERN,
                           sizeof(kal_uint32),	(void *)Size,			FS_CCCI_EOF_TERM_PATTERN);
}

kal_int32 MD_FS_Delete(const WCHAR * FileName)
{
    kal_uint32 n_filename = kal_dchar_strlen((const char *)FileName) + sizeof(WCHAR);

    return FS_CCCI_Wrapper(FS_CCCI_OP_DELETE, n_filename, (void *)FileName,	FS_CCCI_INPUT_TERM_PATTERN,
                           FS_CCCI_EOF_TERM_PATTERN);
}


kal_int32 MD_FS_GetAttributes(const WCHAR * FileName)
{
    kal_uint32 n_filename = kal_dchar_strlen((const char *)FileName) + sizeof(WCHAR);

    return FS_CCCI_Wrapper(FS_CCCI_OP_GETATTRIBUTES, n_filename, (void *)FileName,	FS_CCCI_INPUT_TERM_PATTERN,
                           FS_CCCI_EOF_TERM_PATTERN);
}

kal_int32 MD_FS_CreateDir(const WCHAR * DirName)
{
    kal_uint32 n_dirname = kal_dchar_strlen((const char *)DirName) + sizeof(WCHAR);

    return FS_CCCI_Wrapper(FS_CCCI_OP_CREATEDIR, n_dirname, (void *)DirName,	FS_CCCI_INPUT_TERM_PATTERN,
                           FS_CCCI_EOF_TERM_PATTERN);
}


kal_int32 MD_FS_RemoveDir(const WCHAR * DirName)
{
    kal_uint32 n_dirname = kal_dchar_strlen((const char *)DirName) + sizeof(WCHAR);

    return FS_CCCI_Wrapper(FS_CCCI_OP_REMOVEDIR, n_dirname, (void *)DirName,	FS_CCCI_INPUT_TERM_PATTERN,
                           FS_CCCI_EOF_TERM_PATTERN);
}

kal_int32 MD_FS_GetFolderSize(const WCHAR *DirName, kal_uint32 Flag, kal_uint8 *RecursiveStack, const kal_uint32 StackSize)
{

    kal_uint32 n_dirname = kal_dchar_strlen((const char *)DirName) + sizeof(WCHAR);

    return FS_CCCI_Wrapper(FS_CCCI_OP_GETFOLDERSIZE,	n_dirname,			(void *)DirName,
                           sizeof(kal_uint32), (void *)&Flag,		FS_CCCI_INPUT_TERM_PATTERN,
                           FS_CCCI_EOF_TERM_PATTERN);
}

kal_int32 MD_FS_Rename(const WCHAR * FileName, const WCHAR * NewName)
{
    kal_uint32 n_filename = kal_dchar_strlen((const char *)FileName) + sizeof(WCHAR);
    kal_uint32 n_newname = kal_dchar_strlen((const char *)NewName) + sizeof(WCHAR);

    return FS_CCCI_Wrapper(FS_CCCI_OP_RENAME,	n_filename, (void *)FileName,
                           n_newname,	(void *)NewName,	FS_CCCI_INPUT_TERM_PATTERN,
                           FS_CCCI_EOF_TERM_PATTERN);
}

kal_int32 MD_FS_Move(const WCHAR * SrcFullPath, const WCHAR * DstFullPath, kal_uint32 Flag, FS_ProgressCallback Progress, kal_uint8 *RecursiveStack, const kal_uint32 StackSize)
{
    kal_uint32 n_srcfullpath = kal_dchar_strlen((const char *)SrcFullPath) + sizeof(WCHAR);
    kal_uint32 n_dstfullpath = kal_dchar_strlen((const char *)DstFullPath) + sizeof(WCHAR);


    return FS_CCCI_Wrapper(FS_CCCI_OP_MOVE,	n_srcfullpath, 		(void *)SrcFullPath,
                           n_dstfullpath, 		(void *)DstFullPath,
                           sizeof(kal_uint32), (void *)&Flag, 		FS_CCCI_INPUT_TERM_PATTERN,
                           FS_CCCI_EOF_TERM_PATTERN);
}


kal_int32 MD_FS_Count(const WCHAR * FullPath, UINT Flag, BYTE *RecursiveStack, const UINT StackSize)
{
    kal_uint32 n_fullpath = kal_dchar_strlen((const char *)FullPath) + sizeof(WCHAR);

    return FS_CCCI_Wrapper(FS_CCCI_OP_COUNT,	n_fullpath,			(void *)FullPath,
                           sizeof(kal_uint32),	(void *)&Flag,		FS_CCCI_INPUT_TERM_PATTERN,
                           FS_CCCI_EOF_TERM_PATTERN);
}


kal_int32 MD_FS_XDelete(const WCHAR * FullPath, kal_uint32 Flag, kal_uint8 *RecursiveStack, const kal_uint32 StackSize)
{
    kal_uint32 n_fullpath = kal_dchar_strlen((const char *)FullPath) + sizeof(WCHAR);

    return FS_CCCI_Wrapper(FS_CCCI_OP_XDELETE,	n_fullpath, 		(void *)FullPath,
                           sizeof(kal_uint32), (void *)&Flag, 		FS_CCCI_INPUT_TERM_PATTERN,
                           FS_CCCI_EOF_TERM_PATTERN);
}

kal_int32 MD_FS_FindFirst(const WCHAR * NamePattern, kal_uint8 Attr, kal_uint8 AttrMask, FS_DOSDirEntry * FileInfo, WCHAR * FileName, kal_uint32 MaxLength)
{
    kal_uint32 n_namepattern = kal_dchar_strlen((const char *)NamePattern) + sizeof(WCHAR);

    return FS_CCCI_Wrapper(FS_CCCI_OP_FINDFIRST,	n_namepattern,			(void *)NamePattern,
                           sizeof(kal_uint8),		(void *)&Attr,
                           sizeof(kal_uint8),		(void *)&AttrMask,
                           sizeof(kal_uint32), 	(void *)&MaxLength,		FS_CCCI_INPUT_TERM_PATTERN,
                           sizeof(FS_DOSDirEntry), (void *)FileInfo,
                           MaxLength,				(void *)FileName,		FS_CCCI_EOF_TERM_PATTERN);
}

kal_int32 MD_FS_FindNext(FS_HANDLE FileHandle, FS_DOSDirEntry * FileInfo, WCHAR * FileName, kal_uint32 MaxLength)
{
    return FS_CCCI_Wrapper(FS_CCCI_OP_FINDNEXT, sizeof(FS_HANDLE),		(void *)&FileHandle,
                           sizeof(kal_uint32), 	(void *)&MaxLength, FS_CCCI_INPUT_TERM_PATTERN,
                           sizeof(FS_DOSDirEntry), (void *)FileInfo,
                           MaxLength, 				(void *)FileName, 	FS_CCCI_EOF_TERM_PATTERN);
}

kal_int32 MD_FS_FindClose(FS_HANDLE FileHandle)
{
    return FS_CCCI_Wrapper(FS_CCCI_OP_FINDCLOSE, sizeof(FS_HANDLE), (void *)&FileHandle,	FS_CCCI_INPUT_TERM_PATTERN,
                           FS_CCCI_EOF_TERM_PATTERN);
}

kal_int32 MD_FS_GetDrive(kal_uint32 Type, kal_uint32 Serial, kal_uint32 AltMask)
{
    return FS_CCCI_Wrapper(FS_CCCI_OP_GETDRIVE, sizeof(kal_uint32), (void *)&Type,
                           sizeof(kal_uint32), (void *)&Serial,
                           sizeof(kal_uint32), (void *)&AltMask,	FS_CCCI_INPUT_TERM_PATTERN,
                           FS_CCCI_EOF_TERM_PATTERN);
}

kal_int32 MD_FS_GetClusterSize(kal_uint32 DriveIdx)
{
    return FS_CCCI_Wrapper(FS_CCCI_OP_GETCLUSTERSIZE, sizeof(kal_uint32), (void *)&DriveIdx,	FS_CCCI_INPUT_TERM_PATTERN,
                           FS_CCCI_EOF_TERM_PATTERN);
}

kal_int32 MD_FS_SetDiskFlag(void)
{
    return FS_CCCI_Wrapper(FS_CCCI_OP_SETDISKFLAG,	FS_CCCI_INPUT_TERM_PATTERN,
                           FS_CCCI_EOF_TERM_PATTERN);
}


kal_int32 MD_FS_CloseAll(void)
{
    return FS_CCCI_Wrapper(FS_CCCI_OP_CLOSEALL,	FS_CCCI_INPUT_TERM_PATTERN,
                           FS_CCCI_EOF_TERM_PATTERN);
}

kal_int32 MD_FS_ClearDiskFlag(void)
{
    return FS_CCCI_Wrapper(FS_CCCI_OP_CLEARDISKFLAG,	FS_CCCI_INPUT_TERM_PATTERN,
                           FS_CCCI_EOF_TERM_PATTERN);
}

kal_int32 MD_FS_GetDiskInfo(const WCHAR * DriveName, FS_DiskInfo * DiskInfo, kal_int32 Flags)
{
    kal_uint32 n_drivename = kal_dchar_strlen((const char *)DriveName) + sizeof(WCHAR);

    return FS_CCCI_Wrapper(FS_CCCI_OP_GETDISKINFO,	n_drivename, 		(void *)DriveName,
                           sizeof(kal_int32),	(void *)&Flags,		FS_CCCI_INPUT_TERM_PATTERN,
                           sizeof(FS_DiskInfo),(void *)DiskInfo,	FS_CCCI_EOF_TERM_PATTERN);
}

void MD_FS_ShutDown(void)
{
    FS_CCCI_Wrapper(FS_CCCI_OP_SHUTDOWN,	FS_CCCI_INPUT_TERM_PATTERN,
                    FS_CCCI_EOF_TERM_PATTERN);
}

kal_int32 MD_FS_UnlockAll(void)
{
    return FS_CCCI_Wrapper(FS_CCCI_OP_UNLOCKALL,	FS_CCCI_INPUT_TERM_PATTERN,
                           FS_CCCI_EOF_TERM_PATTERN);
}

kal_int32 MD_FS_LockFAT(kal_uint32 Type)
{
    return FS_CCCI_Wrapper(FS_CCCI_OP_LOCKFAT, sizeof(kal_uint32), (void *)&Type,	FS_CCCI_INPUT_TERM_PATTERN,
                           FS_CCCI_EOF_TERM_PATTERN);
}

kal_int32 MD_FS_OTPWrite(kal_int32 devtype, kal_uint32 Offset, void * BufferPtr, kal_uint32 Length)
{
    return FS_CCCI_Wrapper(FS_CCCI_OP_OTPWRITE, sizeof(FS_HANDLE),	(void *)&devtype,
                           sizeof(FS_HANDLE),	(void *)&Offset,
                           Length, 			(void *) BufferPtr,
                           sizeof(kal_uint32), (void *)&Length,	FS_CCCI_INPUT_TERM_PATTERN,
                           FS_CCCI_EOF_TERM_PATTERN);
}

kal_int32 MD_FS_OTPRead(kal_int32 devtype, kal_uint32 Offset, void * BufferPtr, kal_uint32 Length)
{
    return FS_CCCI_Wrapper(FS_CCCI_OP_OTPREAD,	sizeof(FS_HANDLE),	(void *)&devtype,
                           sizeof(kal_uint32), (void *)&Offset,
                           sizeof(kal_uint32), (void *)&Length,	FS_CCCI_INPUT_TERM_PATTERN,
                           Length,			 	(void *) BufferPtr,	FS_CCCI_EOF_TERM_PATTERN);
}

kal_int32 MD_FS_OTPQueryLength(kal_int32 devtype, kal_uint32 *Length)
{
    return FS_CCCI_Wrapper(FS_CCCI_OP_OTPQUERYLENGTH,	sizeof(kal_uint32), (void *)&devtype,	FS_CCCI_INPUT_TERM_PATTERN,
                           sizeof(kal_int32),	(void *)Length,		FS_CCCI_EOF_TERM_PATTERN);
}

kal_int32 MD_FS_OTPLock(kal_int32 devtype)
{
    return FS_CCCI_Wrapper(FS_CCCI_OP_OTPLOCK, sizeof(kal_uint32), (void *)&devtype,	FS_CCCI_INPUT_TERM_PATTERN,
                           FS_CCCI_EOF_TERM_PATTERN);
}

kal_int32 MD_FS_Restore(const WCHAR * FileName, void* pBuffer, kal_uint32 Length)
{
    kal_uint32 n_filename = kal_dchar_strlen((const char *)FileName) + sizeof(WCHAR);

    return FS_CCCI_Wrapper(FS_CCCI_OP_RESTORE,	n_filename, 		(void *)FileName,
                           Length,				(void *)pBuffer,
                           sizeof(kal_uint32), (void *)&Length,	FS_CCCI_INPUT_TERM_PATTERN,
                           FS_CCCI_EOF_TERM_PATTERN);

}

#endif /* __MODEM_CCCI_EXIST__ */

