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
 *   fs_ccci.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Header file of FS_CCCI.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/




#ifndef __FS_CCCI_H__
#define __FS_CCCI_H__

#if defined(__MODEM_CCCI_EXIST__)

#include "kal_general_types.h"
#if !defined(__SDIO_DEVICE_CONNECTIVITY__)
#include "ccci_fssvc.h"

/*******************************************************************************
 * Define marco or constant.
 *******************************************************************************/
#define FS_CCCI_EXCEPT_MAX_RETRY        7
#define FS_CCCI_MAX_RETRY        		0xFFFF
#define FS_CCCI_REQ_BUFFER_NUM   		5 /* support 5 concurrently request*/
#define FS_CCCI_MAX_ARG_NUM				6 /* parameter number */

#define FS_CCCI_USE_DEFAULT_INDEX		-1

#define FS_CCCI_API_RESP_ID				0xFFFF0000

#define FS_CCCI_INPUT_TERM_PATTERN      0xFFFFFFFE
#define FS_CCCI_EOF_TERM_PATTERN        0xFFFFFFFF

#define FS_CCCI_INC_BUF_INDEX(x)		(x = (x + 1) % FS_CCCI_REQ_BUFFER_NUM)

#define FS_CCCI_SEND_RETRY    CCCI_SEND_RETRY_DEFAULT

/*******************************************************************************
 * Define data structure.
 *******************************************************************************/

typedef struct FS_CCCI_LV_STRUCT
{
    kal_uint32 len;
    void *val;
} FS_CCCI_LV_T;

typedef struct FS_StreamBuffer_STRUCT
{
    kal_uint32		fs_operationID;
    kal_uint32		num;
    FS_CCCI_LV_T	LV0;
} FS_StreamBuffer_T, *pFS_StreamBuffer_T;

/*******************************************************************************
 * Declare function prototype.
 *******************************************************************************/
void 		FS_CCCI_Init(void);
kal_int32	FS_CCCI_Wrapper(FS_CCCI_OP_ID_T fs_op,...);
























#elif defined(__SMART_PHONE_MODEM__) //- __SDIO_DEVICE_CONNECTIVITY__ && __SMART_PHONE_MODEM__
#include "ccci.h"
#include "fs_gprot.h"


/*******************************************************************************
 * Define marco or constant.
 *******************************************************************************/
#define PUBLIC
#define PRIVATE
#define FS_CCCI_EXCEPT_MAX_RETRY        7
#define FS_CCCI_MAX_RETRY        0xFFFF
#define FS_CCCI_REQ_BUFFER_NUM   5 /* support 5 concurrently request*/
#define FS_CCCI_MAX_ARG_NUM	6 /* parameter number */
#define FS_CCCI_MAX_BUF_SIZE	16384
//2048

#define FS_CCCI_USE_DEFAULT_INDEX	-1

#define FS_CCCI_API_RESP_ID	0xFFFF0000

#define FS_CCCI_INC_BUF_INDEX(x)	(x = (x + 1) % FS_CCCI_REQ_BUFFER_NUM)

/*******************************************************************************
 * Define data structure.
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

typedef struct FS_CCCI_LV_STRUCT
{
    kal_uint32 len;
    void *val;
} FS_CCCI_LV_T;

typedef struct FS_StreamBuffer_STRUCT
{
#if defined (__SDIO_DEVICE_CONNECTIVITY__)
    CCCI_BUFF_T ccci_header;
#endif
    kal_uint32	fs_operationID;
    kal_uint8	buffer[FS_CCCI_MAX_BUF_SIZE];
} FS_StreamBuffer_T;

extern FS_StreamBuffer_T *FS_REQ_BUF;


/*******************************************************************************
 * Declare function prototype.
 *******************************************************************************/
PRIVATE kal_int32 FS_CCCI_Write(kal_int32 *index, kal_uint32 op, FS_CCCI_LV_T *pLV, kal_uint32 num);
PRIVATE kal_int32 FS_CCCI_Read(kal_int32 index, kal_uint32 op, FS_CCCI_LV_T *pLV, kal_uint32 *num);
PUBLIC void FS_CCCI_TX_Callback(CCCI_BUFF_T *buff);
PUBLIC void FS_CCCI_Callback(CCCI_BUFF_T *buff);
PUBLIC void FS_CCCI_Init(void);


// General I/O
kal_int32 MD_FS_Open(const WCHAR * FileName, kal_uint32 Flag);
kal_int32 MD_FS_OpenHint(const WCHAR * FileName, kal_uint32 Flag, FS_FileOpenHint * DSR_Hint);
kal_int32 MD_FS_Close(FS_HANDLE FileHandle);
kal_int32 MD_FS_CloseAll(void);
kal_int32 MD_FS_Read(FS_HANDLE FileHandle, void * DataPtr, kal_uint32 Length, kal_uint32 * Read);
kal_int32 MD_FS_Write(FS_HANDLE FileHandle, void * DataPtr, kal_uint32 Length, kal_uint32 * Written);
//kal_int32 MD_FS_SetSeekHint(FS_HANDLE FileHandle, kal_uint32 HintNum, FS_FileLocationHint * Hint);
kal_int32 MD_FS_Seek(FS_HANDLE FileHandle, kal_int32 Offset, kal_int32 Whence);
//kal_int32 MD_FS_Commit(FS_HANDLE FileHandle);
//kal_int32 MD_FS_ReleaseFH(void * TaskId);
//kal_int32 MD_FS_Abort(kal_uint32 ActionHandle);
//kal_int32 MD_FS_ParseFH(FS_HANDLE FileHandle);
//kal_int32 MD_FS_GenVirtualFileName(FS_HANDLE FileHandle, WCHAR * VFileNameBuf, kal_uint32 BufLength, kal_uint32 VFBeginOffset, kal_uint32 VFValidLength);

//Information
//kal_int32 MD_FS_GetFileInfo(FS_HANDLE FileHandle, FS_FileInfo * FileInfo);
kal_int32 MD_FS_GetFileSize(FS_HANDLE FileHandle, kal_uint32 * Size);
//kal_int32 MD_FS_GetFilePosition(FS_HANDLE FileHandle, kal_uint32 * Position);
//kal_int32 MD_FS_SetFileTime(FS_HANDLE FileHandle, const FS_DOSDateTime * Time);
kal_int32 MD_FS_GetAttributes(const WCHAR * FileName);
//kal_int32 MD_FS_GetFirstCluster(FS_HANDLE FileHandle, kal_uint32 * Cluster);

//File Only Operation
//kal_int32 MD_FS_SetAttributes(const WCHAR * FileName, kal_uint8 Attributes);
kal_int32 MD_FS_Delete(const WCHAR * FileName);
//kal_int32 MD_FS_PseudoMerge(const WCHAR * FileName1, const WCHAR * FileName2);
//kal_int32 MD_FS_CheckFile(const WCHAR * FileName);

//Folder Only Operation
//kal_int32 MD_FS_GetCurrentDir(WCHAR * DirName, kal_uint32 MaxLength);
//kal_int32 MD_FS_SetCurrentDir(const WCHAR * DirName);
kal_int32 MD_FS_CreateDir(const WCHAR * DirName);
kal_int32 MD_FS_RemoveDir(const WCHAR * DirName);
kal_int32 MD_FS_GetFolderSize(const WCHAR *DirName, kal_uint32 Flag, kal_uint8 *RecursiveStack, const kal_uint32 StackSize);

//File and Folder Operations
//kal_int32 MD_FS_Extend(FS_HANDLE FileHandle, kal_uint32 Length);
//kal_int32 MD_FS_Truncate(FS_HANDLE FileHandle);
//kal_int32 MD_FS_MakeFileName(FS_HANDLE FileHandle, kal_uint32 Flag, WCHAR * FileName, kal_uint32 MaxLength);
kal_int32 MD_FS_Rename(const WCHAR * FileName, const WCHAR * NewName);

kal_int32 MD_FS_Move(const WCHAR * SrcFullPath, const WCHAR * DstFullPath, kal_uint32 Flag, FS_ProgressCallback Progress, kal_uint8 *RecursiveStack, const kal_uint32 StackSize);

kal_int32 MD_FS_Count(const WCHAR * FullPath, kal_uint32 Flag, kal_uint8 *RecursiveStack, const kal_uint32 StackSize);
kal_int32 MD_FS_XDelete(const WCHAR * FullPath, kal_uint32 Flag, kal_uint8 *RecursiveStack, const kal_uint32 StackSize);

//Find File
kal_int32 MD_FS_FindFirst(const WCHAR * NamePattern, kal_uint8 Attr, kal_uint8 AttrMask, FS_DOSDirEntry * FileInfo, WCHAR * FileName, kal_uint32 MaxLength);
kal_int32 MD_FS_FindNext(FS_HANDLE FileHandle, FS_DOSDirEntry * FileInfo, WCHAR * FileName, kal_uint32 MaxLength);
//kal_int32 MD_FS_FindFirstN(const WCHAR * NamePattern, FS_Pattern_Struct * PatternArray, kal_uint32 PatternNum, kal_uint8 ArrayMask, kal_uint8 Attr, kal_uint8 AttrMask, FS_DOSDirEntry * FileInfo, WCHAR * FileName, kal_uint32 MaxLength, kal_uint32 EntryIndex, kal_uint32 Flag);
//kal_int32 MD_FS_FindNextN(FS_HANDLE Handle, FS_Pattern_Struct * PatternArray, kal_uint32 PatternNum, kal_uint8 ArrayMask, FS_DOSDirEntry * FileInfo, WCHAR * FileName, kal_uint32 MaxLength, kal_uint32 Flag);
kal_int32 MD_FS_FindClose(FS_HANDLE FileHandle);

#ifdef __FS_SORT_SUPPORT__
//kal_int32 MD_FS_XFindReset(const WCHAR * Pattern, FS_Pattern_Struct * PatternArray, kal_uint32 PatternNum, kal_uint8 ArrayMask, kal_uint8 AttrMask, kal_uint32 Flag, kal_uint32 Timeout, kal_uint32 * Position);
//kal_int32 MD_FS_XFindStart(const WCHAR * Pattern, FS_DOSDirEntry * FileInfo, WCHAR * FileName, kal_uint32 MaxLength, kal_uint32 Index, kal_uint32 * Position, kal_uint32 Flag);
//kal_int32 MD_FS_XFindClose(kal_uint32 * Position);
#endif

//Drive Management
kal_int32 MD_FS_GetDrive(kal_uint32 Type, kal_uint32 Serial, kal_uint32 AltMask);
//kal_int32 MD_FS_GeneralFormat(const WCHAR * DriveName, kal_uint32 Level, FS_FormatCallback Progress);
kal_int32 MD_FS_GetClusterSize(kal_uint32 DriveIdx);
#ifdef __FS_QM_SUPPORT__
//kal_int32 MD_FS_QmGetFree(const kal_uint8 * Path);
#endif
//kal_int32 MD_FS_CreateBootSector(void * BootSector, const FS_PartitionRecord * Partition, kal_uint8 MediaDescriptor, kal_uint32 MinSectorsPerCluster, kal_uint32 Flags);
//kal_int32 MD_FS_GetPartitionInfo(const WCHAR * DriveName, FS_PartitionRecord * PartitionInfo);
//kal_int32 MD_FS_CommitAll(const WCHAR * DriveName);
//kal_int32 MD_FS_MappingDrive(kal_uint32 UpperOldDrv, kal_uint32 UpperNewDrv);

//Power Lost Detection and Recovery
kal_int32 MD_FS_SetDiskFlag(void);
//kal_int32 MD_FS_CheckDiskFlag(void);
kal_int32 MD_FS_ClearDiskFlag(void);
#ifdef __FS_CHECKDRIVE_SUPPORT__
//kal_int32 MD_FS_CheckDrive(const kal_uint32 DriveIdx, kal_uint8 * CheckBuffer, const kal_uint32 CheckBufferSize);
#endif

//Disk Management
//kal_int32 MD_FS_CreateMasterBootRecord(void * SectorBuffer, const FS_PartitionRecord * DiskGeometry);
//kal_int32 MD_FS_SplitPartition(void * MasterBootRecord, kal_uint32 Sectors);
kal_int32 MD_FS_GetDiskInfo(const WCHAR * DriveName, FS_DiskInfo * DiskInfo, kal_int32 Flags);
//kal_int32 MD_FS_GetDevType(const WCHAR * Path);
//kal_int32 MD_FS_GetDevStatus(kal_uint32 DriveIdx, kal_uint32 Flag);
//kal_int32 MD_FS_GetDevPartitions(kal_uint32 QueryTarget);

//Card management
//kal_int32 MD_FS_TestMSDC(void *slot_id);
//kal_int32 MD_FS_CloseMSDC(kal_uint32 MSDCIndex, kal_uint32 Mode);

//OTG Card Reader Management
//kal_int32 MD_FS_ConfigExtDevice(kal_int32 Action, FS_Driver *DrvFuncs, kal_int32 Slots, void **SlotIdArray, kal_int32 *SlotsConfiged);

//File System Run-Time LifeCycle
void MD_FS_ShutDown(void);
kal_int32 MD_FS_UnlockAll(void);
//kal_int32 MD_FS_SanityCheck(void);
kal_int32 MD_FS_LockFAT(kal_uint32 Type);

//File System Run-Time Debug
//kal_int32 MD_FS_CountUsedFH(kal_int32 flag);
#ifdef __FS_TRACE_SUPPORT__
//kal_int32 MD_FS_SetTrace(kal_uint32 Flag, kal_uint32 Timeout);
//kal_int32 MD_FS_DumpFHTable(void);
#endif

//DirCache
//kal_int32 MD_FS_SetDirCache(FS_HANDLE FileHandle, kal_uint32 NewValue);
//kal_int32 MD_FS_GetDirCache(FS_HANDLE FileHandle, kal_uint32 *CurrValue);
//kal_int32 MD_FS_ExpireDirCache(FS_HANDLE FileHandle);

//Flash Device Direct IO
kal_int32 MD_FS_OTPWrite(kal_int32 devtype, kal_uint32 Offset, void * BufferPtr, kal_uint32 Length);
kal_int32 MD_FS_OTPRead(kal_int32 devtype, kal_uint32 Offset, void * BufferPtr, kal_uint32 Length);
kal_int32 MD_FS_OTPQueryLength(kal_int32 devtype, kal_uint32 *Length);
kal_int32 MD_FS_OTPLock(kal_int32 devtype);

//Flash Sweep
//kal_int32 MD_FS_SweepDevice(const kal_int32 devtype);

kal_int32 MD_FS_Restore(const WCHAR * FileName, void* pBuffer, kal_uint32 Length);

#endif //#if !defined(__SDIO_DEVICE_CONNECTIVITY__)

#endif /* #if defined(__MODEM_CCCI_EXIST__) */

#endif  /* __FS_CCCI_H__ */


