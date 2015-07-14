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
 *   format.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file provides format function.
 *
 * Author:
 * -------
 *
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
/*  File: FORMAT.C                               Copyright (c) 1998,2002  */
/*  Version: 4.0                                 On Time Informatik GmbH  */
/*                                                                        */
/*                                                                        */
/*                                      On Time        /////////////----- */
/*                                    Informatik GmbH /////////////       */
/* --------------------------------------------------/////////////        */
/*                                  Real-Time and System Software         */
/*                                                                        */
/**************************************************************************/

/* RTFiles formatting. */

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "rtfiles.h"
#include "fs_kal.h"
#include "fs_utility.h"
#include "fs_internal_api.h"
#include "rtfex.h"
#include "wchar.h"
#include "setjmp.h"

#define SECTOR_SIZE 512


extern int compUAstring(const char * FileName, const char* str, int len);


/*-----------------------------------*/
int RTFAPI RTFFormat(const WCHAR * DriveName,
                     UINT MinSectorsPerCluster,
                     RTFFormatCallback Progress,
                     kal_uint32 Flags,
                     kal_uint32 caller_address)
{
   RTFBootRecord     *BR = NULL;
   RTFPartitionInfo  Par;
   RTFFileInfo       FI;
   RTFHANDLE         drive_fh;
   RTFDrive          *drive;
   int               Result   = RTF_NO_ERROR;
   int               FATType  = RTF_ERROR_RESERVED;
   int               TryCount = 1;
   BYTE              *ScratchSector = NULL;
   kal_uint32        SystemSectors, RootDirSectors, FATSectors, Written;

   drive_fh = RTFOpen(DriveName, RTF_READ_WRITE, caller_address); // this ensures exclusive access

   if (drive_fh < RTF_NO_ERROR)
      return drive_fh;

   ScratchSector = (BYTE*) get_ctrl_buffer(SECTOR_SIZE); // alloc template sector space
   BR            = (RTFBootRecord*) ScratchSector;

   Result = RTFGetFileInfo(drive_fh, &FI, RTF_FI_ALL); // make sure it's a drive name
   if (Result < RTF_NO_ERROR) goto ExitWithErrorCode;

   // Shalyn Chua (mtk00576)
   // if ((strlen(FI.FullName) != 6) || (memcmp(FI.FullName, "\\\\.\\", 4) != 0))
   if ((kal_dchar_strlen(FI.FullName) != 12) || !(fs_util_comp_uni_ascii(FI.FullName, "\\\\.\\", 4)))
   {
       Result = RTF_PARAM_ERROR;
       goto ExitWithErrorCode;
   }

   Result = RTFGetPartitionInfo(DriveName, &Par, FS_PARTITION_INFO_ALL);
   if (Result < RTF_NO_ERROR) goto ExitWithErrorCode;

   #if !defined(__FS_SLIM_LOW_LEVEL_FORMAT__)
   if (Flags & RTF_FMT_FORCE_LOW_LEVEL)
   {
Retry:
      if (TryCount >= 2) goto ExitWithErrorCode;

      TryCount++;

      if ((Flags & RTF_FMT_NO_LOW_LEVEL) == 0)       //if ((Par.PhysicalDiskIndex == -1) && ((Flags & RTF_FMT_NO_LOW_LEVEL) == 0))
      {
         Result = RTFRawLowLevelFormat(Par.DeviceListIndex, DriveName, Progress, Flags);
         if (Result < RTF_NO_ERROR) goto ExitWithErrorCode;

         #ifdef __BOOT_FAT_RESET__

         // Shutdown FS to let driver to re-mount and re-calculate the device later.
         Result = RTFUnlockAll();
         RTFShutDown();

         /*
          * RTFShutDown will close all files, open drive file again here.
          * NOTE:
          *       1. For device w/o Auto-Format feature, this step will re-mount drive. MBR/PBR will also be created by driver's SelfFormat() during mount.
          *       2. For device w/  Auto-Format feature, this step will re-mount drive. MBR/PBR will also be created by Auto-Format mechansim in MountLogicalDrive().
          */
         drive_fh = RTFOpen(DriveName, RTF_READ_WRITE, caller_address);

         if (drive_fh < RTF_NO_ERROR)
            return drive_fh;

         #endif // __BOOT_FAT_RESET__
      }

      Result = RTFGetPartitionInfo(DriveName, &Par, FS_PARTITION_INFO_ALL); // formating might have changed it
      if (Result < RTF_NO_ERROR) goto ExitWithErrorCode;
   }

   if (Par.Partition.Sectors == 0) goto Retry;

   #else // __FS_SLIM_LOW_LEVEL_FORMAT__

Retry:
   if (TryCount >= 2) goto ExitWithErrorCode;

   TryCount++;

   if (Par.Partition.Sectors == 0)
   {
      Result = FS_INVALID_FILE_SYSTEM;
      goto ExitWithErrorCode;
   }

   #endif // !__FS_SLIM_LOW_LEVEL_FORMAT__

   if (Flags & RTF_FMT_NO_LOW_LEVEL)
   {
      Result = RTFRead(drive_fh, (void*)BR, SECTOR_SIZE, NULL);
      if (Result < RTF_NO_ERROR) goto ExitWithErrorCode;

      if (BR->BP.SectorsOnDisk != 0)
         BR->BP.TotalSectors = BR->BP.SectorsOnDisk;

      if (BR->Signature != 0xAA55 ||
          BR->BP.TotalSectors > Par.Partition.Sectors ||
          BR->BP.BytesPerSector != SECTOR_SIZE ||
          BR->BP.SectorsPerCluster == 0 ||
          BR->BP.ReservedSectors == 0 ||
          BR->BP.NumberOfFATs == 0)
      {
         Result = RTFSeek(drive_fh, 0, RTF_FILE_BEGIN);
         if (Result < RTF_NO_ERROR) goto ExitWithErrorCode;

         goto NewBootSecotrs;
      }

      FATSectors     = (BR->BP.SectorsPerFAT) ? BR->BP.SectorsPerFAT : BR->BP.E._32.SectorsPerFAT;
      RootDirSectors = (BR->BP.DirEntries * 32 + (BR->BP.BytesPerSector - 1)) / BR->BP.BytesPerSector;

      Written        = BR->BP.TotalSectors
                     - BR->BP.ReservedSectors
                     - BR->BP.NumberOfFATs * FATSectors
                     - RootDirSectors;
      Written = Written / BR->BP.SectorsPerCluster;

      if (Written <= 0xFF4L)
         FATType = 12;
      else if (Written <= 0xFFF4l)
         FATType = 16;
#if !defined(__NOT_SUPPORT_FAT32__)
      else if (Written <= 0xFFFFFF4l)
         FATType = 32;
#endif /* __NOT_SUPPORT_FAT32__ */
      else
         goto NewBootSecotrs;

      Written = 0;

#if !defined(__NOT_SUPPORT_FAT32__)
      if (FATType == 32)
      {
         /*
          * For FAT32, BR->BP.DirEntries should be zero. Assign one cluster size to
          * RootDirSectors for clean job below.
          */
         RootDirSectors = BR->BP.SectorsPerCluster;

         if (BR->BP.E._32.RootDirCluster != 2)
         {
            BR->BP.E._32.RootDirCluster = 2;
            Result = RTFSeek(drive_fh, 0, RTF_FILE_BEGIN);
            if (Result < RTF_NO_ERROR) goto ExitWithErrorCode;

            Result = RTFWrite(drive_fh, (void*)BR, SECTOR_SIZE, NULL);
            if (Result < RTF_NO_ERROR) goto ExitWithErrorCode;

            Result = RTFSeek(drive_fh, BR->BP.E._32.BackupBootSector * SECTOR_SIZE, RTF_FILE_BEGIN);
            if (Result < RTF_NO_ERROR) goto ExitWithErrorCode;

            Result = RTFWrite(drive_fh, (void*)BR, SECTOR_SIZE, NULL);
            if (Result < RTF_NO_ERROR) goto ExitWithErrorCode;
         }
      }
#endif /* __NOT_SUPPORT_FAT32__ */

      SystemSectors  = BR->BP.ReservedSectors
                     + BR->BP.NumberOfFATs * FATSectors
                     + RootDirSectors;

      goto ZeroFATRegion;
   }

NewBootSecotrs:
   Result = RTFCreateBootSector(ScratchSector, &Par.Partition, Par.MediaDescriptor, MinSectorsPerCluster, Flags);
   if (Result < RTF_NO_ERROR) goto ExitWithErrorCode;
   FATType = Result;

#if 0
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
#endif
       // end of modified

#if !defined(__NOT_SUPPORT_FAT32__)
   if (FATType == 32)
      RootDirSectors = BR->BP.SectorsPerCluster;
   else
#endif /* __NOT_SUPPORT_FAT32__ */

      RootDirSectors = BR->BP.DirEntries / 16;

#if !defined(__NOT_SUPPORT_FAT32__)
   FATSectors     = (FATType != 32) ? BR->BP.SectorsPerFAT : BR->BP.E._32.SectorsPerFAT;
#else
   FATSectors     = BR->BP.SectorsPerFAT;
#endif /* __NOT_SUPPORT_FAT32__ */

   SystemSectors  = BR->BP.ReservedSectors
                  + BR->BP.NumberOfFATs * FATSectors
                  + RootDirSectors;

   if (Progress) Progress((char *)DriveName, RTF_FMT_PGS_HIGH_FMT, SystemSectors, Written = 0);

   // write boot sector to the disk
   Result = RTFWrite(drive_fh, (void*)BR, SECTOR_SIZE, NULL);
   if (Result < RTF_NO_ERROR) goto Retry;

#if !defined(__NOT_SUPPORT_FAT32__)
   // if this is FAT-32, write backup boot sector
   if (FATType == 32)
   {
      Result = RTFSeek(drive_fh, BR->BP.E._32.BackupBootSector * SECTOR_SIZE, RTF_FILE_BEGIN);
      if (Result < RTF_NO_ERROR) goto ExitWithErrorCode;

      Result = RTFWrite(drive_fh, (void*)BR, SECTOR_SIZE, NULL);
      if (Result < RTF_NO_ERROR) goto ExitWithErrorCode;
   }
#endif /* __NOT_SUPPORT_FAT32__ */

   // save data we need further down

ZeroFATRegion:
   {
      UINT FatCount = BR->BP.NumberOfFATs;
      BYTE MediaDescriptor = BR->BP.MediaDescriptor;
      RTFSector StartOfFAT = BR->BP.ReservedSectors;
      #if !defined(__NOT_SUPPORT_FAT32__)
      RTFSector InfoSector = BR->BP.E._32.FSInfoSector;
      #endif
      kal_uint32 i, j;

      kal_mem_set(ScratchSector, 0, SECTOR_SIZE);

      /*
       * Step 1. Clear info sector (FAT32 only).
       *
       * Note. We will re-construct info sector's contents in UpdateClusterWatermark().
       */

      #if !defined(__NOT_SUPPORT_FAT32__)
      if ((FATType == 32) && (InfoSector > 0) && (InfoSector < StartOfFAT))
      {
         Result = RTFSeek(drive_fh, InfoSector * SECTOR_SIZE, RTF_FILE_BEGIN);
         if (Result < RTF_NO_ERROR) goto ExitWithErrorCode;

         Result = RTFWrite(drive_fh, ScratchSector, SECTOR_SIZE, NULL);
         if (Result < RTF_NO_ERROR) goto ExitWithErrorCode;
      }
      #endif /* __NOT_SUPPORT_FAT32__ */

      Written = (kal_uint32)StartOfFAT;
      if (Progress) Progress((char*)DriveName, RTF_FMT_PGS_HIGH_FMT, SystemSectors, Written);

      /*
       * Step 2. Clear root directory.
       *
       * Remarks: Root directory should be cleaned before FAT table for disk robustness.
       *          Otherwise, if FAT table cleaning is interrupted, and root directory is
       *          not cleaned, FS may think some folders are already existed but they are
       *          homeless because FAT table is cleaned before.                  - W09.46
       *
       * Note: For FAT32, it seems not requried to clean root directory because in
       *       CreateNewDirEntry(), any new allocated cluster for root directory will
       *       be filled-in ZEROs before used. Here we clean 1 cluster (cluster 2) for FAT32.
       *
       * Todo: Remove clean job for FAT32, or consider the case: The 1st cluster of root
       *       directory is not 2 (not fixed for FAT32).
       */

      Result = RTFSeek(drive_fh, (StartOfFAT + FatCount * FATSectors) * SECTOR_SIZE, RTF_FILE_BEGIN);
      if (Result < RTF_NO_ERROR) goto ExitWithErrorCode;

      for (i = 0; i < RootDirSectors; i++)
      {
         Result = RTFWrite(drive_fh, ScratchSector, SECTOR_SIZE, NULL);
         if (Result < RTF_NO_ERROR) goto ExitWithErrorCode;
      }

      Written += RootDirSectors;
      if (Progress) Progress((char *)DriveName, RTF_FMT_PGS_HIGH_FMT, SystemSectors, Written);

      /*
       * Step 3. Clear FAT table(s).
       */

      Result = RTFSeek(drive_fh, StartOfFAT * SECTOR_SIZE, RTF_FILE_BEGIN);
      if (Result < RTF_NO_ERROR) goto ExitWithErrorCode;

      for (j = 0; j < FatCount; j++)
      {
         switch (FATType)
         {
            #if !defined(__NOT_SUPPORT_FAT32__)
            case 32:
               {
                  kal_uint32 * FPtr = (void*) ScratchSector;
                  FPtr[2] = 0x0FFFFFFF; // this is for the root dir
                  FPtr[1] = 0x0FFFFFFF;
               }
            #endif /* __NOT_SUPPORT_FAT32__ */
            case 16:
               {
                  WORD * FPtr = (void*) ScratchSector;
                  FPtr[1] = 0xFFFF;
               }
            case 12:
               ScratchSector[2] = 0xFF;
               ScratchSector[1] = 0xFF;
               ScratchSector[0] = MediaDescriptor;
         }

         for (i = 0; i < FATSectors; i++)
         {
            Result = RTFWrite(drive_fh, ScratchSector, SECTOR_SIZE, NULL);
            if (Result < RTF_NO_ERROR) goto ExitWithErrorCode;

            if (i == 0) kal_mem_set(ScratchSector, 0, 3*4);
         }

         Written += FATSectors;
         if (Progress) Progress((char *)DriveName, RTF_FMT_PGS_HIGH_FMT, SystemSectors, Written);
      }
   }

//DiscardDataRegion:
   // to help flash disks to perform well, we will delete all data sectors
   // devices which do not support this will ignore this
   #ifdef ERASE_DATA_SECTOR  // kumar remove it
   {
      kal_uint32 AbsOff, ToDo, Done, Increment;

      AbsOff = Par.PartitionSector + Par.Partition.RelativeSector;
      ToDo   = Par.Partition.Sectors;
      Increment = ToDo / 50;

      if (RTFRawDiscardSectors(Par.DeviceListIndex, AbsOff + SystemSectors, 1) >= RTF_NO_ERROR)
      {
         if (Progress) Progress((char *)DriveName, RTF_FMT_PGS_CLEAR_MEDIUM, Par.Partition.Sectors, 0);

#if !defined(__NOT_SUPPORT_FAT32__)
         if (FATType == 32)
         {
            RTFRawDiscardSectors(Par.DeviceListIndex, AbsOff + 2, 6-2);  // 2 3 4 5
            RTFRawDiscardSectors(Par.DeviceListIndex, AbsOff + 7, 32-7); // 7-31
         }
#endif /* __NOT_SUPPORT_FAT32__ */

         if (Progress) Progress((char *)DriveName, RTF_FMT_PGS_CLEAR_MEDIUM, Par.Partition.Sectors, SystemSectors);

         ToDo -= SystemSectors;
         Done = SystemSectors;

         while (ToDo > 0)
         {
            kal_uint32 n = (ToDo > Increment) ? Increment : ToDo;
            RTFRawDiscardSectors(Par.DeviceListIndex, AbsOff + Done, n);
            ToDo -= n;
            Done += n;
            if (Progress) Progress((char *)DriveName, RTF_FMT_PGS_CLEAR_MEDIUM, Par.Partition.Sectors, Done);
         }
      }
   }
   #endif // ERASE_DATA_SECTOR

   if (ScratchSector != NULL) free_ctrl_buffer(ScratchSector);

   // close volumn file (NOTE: it will set this drive as UnMounted!)
   RTFClose(drive_fh);

   // try to re-mount this drive myself
   // here we only re-mount fixed drive because Removable Device will be handled outside (in FS_GeneralFormat) (W09.37)
   drive = MTGetRTFDriveByDriveFileName(DriveName);

   #ifdef __FS_OPEN_HINT__
   if (drive) MTHintExpireByDrive(drive); // expire all internal hints in this drive
   #endif /* __FS_OPEN_HINT__ */

   if ((drive != NULL) && (drive->MountState < HasFileSystem) && ((drive->Dev->DeviceFlags & RTF_DEVICE_REMOVABLE) == 0))
   XTRY
      case XCODE:
         SafeLock(MT_LOCK_RTF, NULL, RTF_INFINITE);   // device lock is already locked by FS_GeneralFormat
         MountLogicalDrive(drive, HasFileSystem);
         break;
      default:
         break;
      case XFINALLY:
         SafeUnlock(MT_LOCK_RTF);
         break;
   XENDX

   return FATType;

ExitWithErrorCode:
   if (ScratchSector != NULL) free_ctrl_buffer(ScratchSector);
   RTFClose(drive_fh);
   return Result;
}


