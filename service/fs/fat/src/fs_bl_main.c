/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *   fs_bl_main.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file contains FS for Boot loader.
 *
 * Author:
 * -------
 * -------
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
#include "kal_public_api.h" //MSBB change #include "kal_release.h"
#include "fat_fs.h"
#include "fs_utility.h"
#include "rtfiles.h"
#include "fs_kal.h"
#include "rtfex.h"
#include "rtfbuf.h"
#include "bl_init.h"

typedef enum
{
    FS_BL_PROC_NULL,
    FS_BL_PROC_INIT,
    FS_BL_PROC_READY,
    
    FS_BL_PROC_INVALID
}fs_bl_proc_enum;

static fs_bl_proc_enum fs_bl_proc_state;

// REVIEW: remove State
// REVISE: Done
static RTFDrive *fs_bl_locate_drive(int DriveIndex)
{
    RTFDrive  *volatile Drive = NULL;
    kal_int32 volatile result = FS_NO_ERROR;
    
    if (fs_bl_proc_state == FS_BL_PROC_NULL)
    {
        RTFInit();

        fs_bl_proc_state = FS_BL_PROC_INIT;
    }

    Drive = gFS_Data.DriveTable;

    if (fs_bl_proc_state == FS_BL_PROC_INIT)
    {

        // REVIEW: need to check why it isn't empty 
        if (Drive->Dev == NULL) 
        {
            XRAISE(FS_DRIVE_NOT_FOUND);
        }

        // REVIEW: remove State
        // REVISE: Done
        XTRY
        {
            case XCODE:
                result= MountRemovableDevice(Drive->Dev);
                break;
        // REVIEW: add default
        // REVISE: Done
            default:
               result = XVALUE; 
               break;
            
            case XFINALLY:
                if (result != FS_NO_ERROR)
                    Drive = NULL;
                break;
        }
        XENDX
        fs_bl_proc_state = FS_BL_PROC_READY;
    }


    return Drive;
}

// REVIEW: remove Flag
// REVISE: Done
kal_int32 fs_bl_open(const kal_wchar *FileName)
{
   int UL;
   int     volatile          Result;
   RTFile* volatile          f              = NULL;
   
   WacthDogRestart();
   
    XTRY
    {
        case XCODE:
        {
            f = gFS_Data.FileTable;

            /* ignore any spaces ahead of FileName */
            while (compASCII(FileName, 0, ' '))
            {
                FileName += 2;
            }

            UL = fs_util_dchar_strlen((char *)FileName);

            if (((UL == 12) && fs_util_comp_uni_ascii((char *)FileName, "\\\\.\\", 4) && compASCII(FileName, 5, ':')) ||
                ((UL == 36) && fs_util_comp_uni_ascii((char *)FileName, "\\\\.\\PHYSICALDRIVE", 17)) ||
                ((UL >= 90) && (fs_util_comp_uni_ascii((char *)FileName, "\\\\.\\FMapF\\", 10))) ||
                (UL== 0))
            {
                XRAISE(FS_INVALID_FILENAME);
            }
            else
            {

                /*
                * see if the dir name contains a drive letter
                * Case UL < 2: Name has only 1 char!
                */
                f->Drive = fs_bl_locate_drive(fs_util_is_power_two(toASCII(FileName, 0)) - MT_BASE_DRIVE_LETTER);

                if (!f->Drive)
                    XRAISE(FS_DRIVE_NOT_FOUND);
                
                f->Dev = f->Drive->Dev;
                f->SpecialKind = NormalFile;
            }

            // REVIEW: remove it
            // REVIEW: Done


            f->Flags = (FS_OPEN_NO_DIR | FS_READ_ONLY);

            if (SearchFile(f, SEARCH_FILES, (char *)FileName, NULL)) // it does exist
            {
                // if this is a folder
                if ((f->DirEntry.Dir.Attributes & FS_ATTR_DIR) != 0)
                {
                    XRAISE(FS_FILE_NOT_FOUND);
                }
            }
            else // it does not exist
            {
                XRAISE(FS_FILE_NOT_FOUND);
            }

            InitFilePointer(f);

            Result = MakeNewFileHandle(f);

            break;
        }

        default:
            Result = XVALUE;
            break;

        case XFINALLY:
        {
            if (f)
            {
                if (Result < FS_NO_ERROR)
                    FreeFTSlot(f);
            }
            
            break;
        }
    } 
   XEND_API
    
   return Result;
}

     

kal_int32 fs_bl_close(FS_HANDLE FileHandle)
{
    FreeFTSlot(gFS_Data.FileTable);
    return FS_NO_ERROR;
}

     
    
int fs_bl_read(FS_HANDLE FileHandle, void * DataPtr, UINT Length, UINT * Read)
{
    RTFile* volatile f = NULL;
    UINT l1, l2, l3;
    DWORD volatile InitialFilePointer;
    int volatile Result = FS_NO_ERROR;

    *Read = 0;

    XTRY
    {
        case XCODE:
        {
            /* get device and system lock (check file's flag to decide use blocking or non-blocking mode) */
            f = gFS_Data.FileTable;

            InitialFilePointer = f->FilePointer;


            if (f->FilePointer > f->DirEntry.Dir.FileSize)
            {
               XRAISE(FS_INVALID_FILE_POS);
            }

            if ((f->FilePointer + Length) < f->FilePointer)
            {
                XRAISE(FS_FILE_TOO_LARGE);
            }


            Length = fs_min(Length, f->DirEntry.Dir.FileSize - f->FilePointer);

            /*
             * make 3 partitions:
             * 1. bytes up to next sector boundary
             * 2. complete sectors
             * 3. to end of area
             * if start and end of area are within the same sector,
             * l3 is used.
             */

            if ((f->FilePointer >> f->Dev->DevData.SectorShift) == ((f->FilePointer+Length) >> f->Dev->DevData.SectorShift))
            {
                l1 = 0;
                l2 = 0;
                l3 = Length;
            }
            else
            {
                l3 = (f->FilePointer+Length) - RTFRoundDown((f->FilePointer+Length), f->Dev->DevData.SectorSize);
                l1 = RTFRoundUp(f->FilePointer, f->Dev->DevData.SectorSize) - f->FilePointer;
                l2 = Length - l1 - l3;
            }
            
            /* Part 1 */
            if (l1 > 0)
            {
                BYTE * Data = GetBuffer(f->Dev, CLUSTER_TO_SECTOR_DIR_OFS(f->Drive, f->Cluster, f->Offset), 0);

                memcpy(DataPtr, Data + SECTOR_OFS(f->Drive, f->Offset), l1);


                *Read           += l1;
                DataPtr = (BYTE*) DataPtr + l1;
                MoveFilePointer(f, l1);
            }

            /* Part 2 */
            while (l2 > 0)
            {
                UINT       sec_length;      /* bytes in this segment */
                RTFSector  sec_amount;      /* number of sectors in segment; */
                RTFSector  sec_index;      /* sector to start writing at */

                sec_index = CLUSTER_TO_SECTOR_DIR_OFS(f->Drive, f->Cluster, f->Offset);
                sec_length = MoveFilePointerSegment(f, l2);
                sec_amount = sec_length >> f->Dev->DevData.SectorShift;

                rtf_core_read_sectors(f->Dev, DataPtr, sec_index, sec_amount, 0);

                *Read += sec_length;
                DataPtr = (BYTE*)DataPtr + sec_length;
                l2 -= sec_length;
            }

            /* Part 3 */
            if (l3 > 0)
            {
                BYTE * Data = GetBuffer(f->Dev, CLUSTER_TO_SECTOR_DIR_OFS(f->Drive, f->Cluster, f->Offset), 0);
                memcpy(DataPtr, Data + SECTOR_OFS(f->Drive, f->Offset), l3);
                MoveFilePointer(f, l3);
                *Read += l3;
            }

            
            break;
        }
        
        default:
        {
            Result = XVALUE;

            // REVIEW: add comment - for move file pointer failure
            // REVISE: Done
            if (Result != FS_FILE_TOO_LARGE &&
                f && ((InitialFilePointer + *Read) != f->FilePointer) )  /* for move file pointer failure */
            {
                XTRY
                {
                    case XCODE:
                        InitFilePointer(f);
                        MoveFilePointer(f, InitialFilePointer + *Read);
                        break;
                    default:
                        if (Result == FS_NO_ERROR)
                            Result = XVALUE;
                        XHANDLED;
                        break;
                    case XFINALLY:
                        break;
                }
                XENDX
            }
            
            break;
        }
        case XFINALLY:
        {
            break;
        }
    }
    XEND_API

return Result;
}

     
    
int fs_bl_seek(FS_HANDLE FileHandle, int Offset, int Whence)
{
    RTFile *volatile f = NULL;
    DWORD            StartPos = 0;
    DWORD volatile   NewPos;
    int              Result = FS_NO_ERROR;

    XTRY
    {
        case XCODE:
        {
            f = gFS_Data.FileTable;

            if (f->FilePointer > f->DirEntry.Dir.FileSize)
            {
                XRAISE(FS_INVALID_FILE_POS);
            }


            switch (Whence)
            {
                case FS_FILE_BEGIN:
                {
                    if (f->SpecialKind == FileMapFile)
                    {
                    StartPos = f->DirEntry.ShortPos.Index; /* BIAS */
                    }
                    else
                    {
                    StartPos = 0;
                    }

                    break;
                }
                case FS_FILE_CURRENT:
                {
                    StartPos = f->FilePointer;
                    break;
                }
                case FS_FILE_END:
                {
                    StartPos = f->DirEntry.Dir.FileSize;
                    break;
                }
            }

            Offset = (kal_int64)StartPos + Offset;

            if (Offset < 0 || Offset >= ((kal_int64)2 << 32))  // new offset can't exceed 4 GB (FAT spec)
            {
                XRAISE(FS_INVALID_FILE_POS);
            }

            NewPos = (DWORD)Offset;

            if (NewPos > f->DirEntry.Dir.FileSize)
            {
                XRAISE(FS_INVALID_FILE_POS);
            }
            
            if (NewPos < f->FilePointer) /* Looking backward */
            {
                /* we need to go back at least one cluster */
                if ((f->FilePointer - NewPos) > f->Offset)
                {
                    /* clear f->FilePointer, Offset, Cluster and LastCluster */
                    InitFilePointer(f);

                    /* use traditional method to move file pointer */
                    MoveFilePointer(f, NewPos);
                }
                /* go back but still within the same cluster */
                else
                {
                    /* everything is simple, just substract f->Offset and FilePointer by offset */
                    f->Offset -= f->FilePointer - NewPos;
                    f->FilePointer -= f->FilePointer - NewPos;
                }
            }
            else if (NewPos > f->FilePointer)
            {
                DWORD NextClusterBoundary;
                DWORD l;


                NextClusterBoundary = RTFRoundUp(f->FilePointer, f->Drive->ClusterSize);

                // move to the next cluster boundary
                if (NextClusterBoundary > NewPos)
                    NextClusterBoundary = NewPos;

                l = NextClusterBoundary - f->FilePointer;

                if (l > 0)
                    MoveFilePointer(f, l);

                l = NewPos - f->FilePointer;

                while (l > 0)
                {
                    if (f->Cluster == 0)
                    {
                        XRAISE(FS_INVALID_FILE_POS);
                    }

                    MoveFilePointerSegment(f, l);
                    l = NewPos - f->FilePointer;
                }

            }

            break;
        }
        default:
        {
            Result = XVALUE;
            break;
        }
        case XFINALLY:
        {
            break;
        }
    }
    XEND_API

    if (Result < FS_NO_ERROR)
        return (kal_int64)Result;
    else
        return (kal_int64)NewPos;
}


kal_int32 fs_bl_get_size(FS_HANDLE FileHandle, UINT * Size)
{
    RTFile * f = gFS_Data.FileTable;

    *Size = f->DirEntry.Dir.FileSize;

    return FS_NO_ERROR;
}


