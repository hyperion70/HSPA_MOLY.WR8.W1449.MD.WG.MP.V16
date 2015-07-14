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
 *   rtfbs.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file provides boot sector initialization
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/**************************************************************************/
/*                                                                        */
/*  File: RTFBS.C                                Copyright (c) 1998,2002  */
/*  Version: 4.0                                 On Time Informatik GmbH  */
/*                                                                        */
/*                                                                        */
/*                                      On Time        /////////////----- */
/*                                    Informatik GmbH /////////////       */
/* --------------------------------------------------/////////////        */
/*                                  Real-Time and System Software         */
/*                                                                        */
/**************************************************************************/

/* RTFiles boot sector initalization. */

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "rtfiles.h"
#include "fs_kal.h"
#include "fs_utility.h"

#define MAX_CLUSTERS_16 (0xFFF6 - 2) // max number of clusters on a FAT-16 partition
#define MAX_CLUSTERS_12 (0x0FF6 - 2) // max number of clusters on a FAT-12 partition
#define SECTOR_SIZE 512

#define STARTTRACK(P) (P->StartTrack | ((P->StartSector & 0xC0) << 2))
#define ENDTRACK(P)   (P->EndTrack   | ((P->EndSector   & 0xC0) << 2))

#if !defined(__FS_PROPRIETARY_SET__)
static const BYTE MasterBootCode[] = {
   0x33, 0xC0, 0x8E, 0xD0, 0xBC, 0x00, 0x7C, 0xFB, 0x50, 0x07, 0x50, 0x1F, 0xFC, 0xBE, 0x1B, 0x7C,
   0xBF, 0x1B, 0x06, 0x50, 0x57, 0xB9, 0xE5, 0x01, 0xF3, 0xA4, 0xCB, 0xBE, 0xBE, 0x07, 0xB1, 0x04,
   0x38, 0x2C, 0x7C, 0x09, 0x75, 0x15, 0x83, 0xC6, 0x10, 0xE2, 0xF5, 0xCD, 0x18, 0x8B, 0x14, 0x8B,
   0xEE, 0x83, 0xC6, 0x10, 0x49, 0x74, 0x16, 0x38, 0x2C, 0x74, 0xF6, 0xBE, 0x10, 0x07, 0x4E, 0xAC,
   0x3C, 0x00, 0x74, 0xFA, 0xBB, 0x07, 0x00, 0xB4, 0x0E, 0xCD, 0x10, 0xEB, 0xF2, 0x89, 0x46, 0x25,
   0x96, 0x8A, 0x46, 0x04, 0xB4, 0x06, 0x3C, 0x0E, 0x74, 0x11, 0xB4, 0x0B, 0x3C, 0x0C, 0x74, 0x05,
   0x3A, 0xC4, 0x75, 0x2B, 0x40, 0xC6, 0x46, 0x25, 0x06, 0x75, 0x24, 0xBB, 0xAA, 0x55, 0x50, 0xB4,
   0x41, 0xCD, 0x13, 0x58, 0x72, 0x16, 0x81, 0xFB, 0x55, 0xAA, 0x75, 0x10, 0xF6, 0xC1, 0x01, 0x74,
   0x0B, 0x8A, 0xE0, 0x88, 0x56, 0x24, 0xC7, 0x06, 0xA1, 0x06, 0xEB, 0x1E, 0x88, 0x66, 0x04, 0xBF,
   0x0A, 0x00, 0xB8, 0x01, 0x02, 0x8B, 0xDC, 0x33, 0xC9, 0x83, 0xFF, 0x05, 0x7F, 0x03, 0x8B, 0x4E,
   0x25, 0x03, 0x4E, 0x02, 0xCD, 0x13, 0x72, 0x29, 0xBE, 0x46, 0x07, 0x81, 0x3E, 0xFE, 0x7D, 0x55,
   0xAA, 0x74, 0x5A, 0x83, 0xEF, 0x05, 0x7F, 0xDA, 0x85, 0xF6, 0x75, 0x83, 0xBE, 0x27, 0x07, 0xEB,
   0x8A, 0x98, 0x91, 0x52, 0x99, 0x03, 0x46, 0x08, 0x13, 0x56, 0x0A, 0xE8, 0x12, 0x00, 0x5A, 0xEB,
   0xD5, 0x4F, 0x74, 0xE4, 0x33, 0xC0, 0xCD, 0x13, 0xEB, 0xB8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x56, 0x33, 0xF6, 0x56, 0x56, 0x52, 0x50, 0x06, 0x53, 0x51, 0xBE, 0x10, 0x00, 0x56, 0x8B, 0xF4,
   0x50, 0x52, 0xB8, 0x00, 0x42, 0x8A, 0x56, 0x24, 0xCD, 0x13, 0x5A, 0x58, 0x8D, 0x64, 0x10, 0x72,
   0x0A, 0x40, 0x75, 0x01, 0x42, 0x80, 0xC7, 0x02, 0xE2, 0xF7, 0xF8, 0x5E, 0xC3, 0xEB, 0x74, 0x49,
   0x6E, 0x76, 0x61, 0x6C, 0x69, 0x64, 0x20, 0x70, 0x61, 0x72, 0x74, 0x69, 0x74, 0x69, 0x6F, 0x6E,
  /*                                           p     a     r     t     i     t     i     o     n */
   0x20, 0x74, 0x61, 0x62, 0x6C, 0x65, 0x00, 0x45, 0x72, 0x72, 0x6F, 0x72, 0x20, 0x6C, 0x6F, 0x61,
  /* SP    t     a     b     l     e    NIL    e     r     r     o     r     SP    l     o     a */
   0x64, 0x69, 0x6E, 0x67, 0x20, 0x6F, 0x70, 0x65, 0x72, 0x61, 0x74, 0x69, 0x6E, 0x67, 0x20, 0x73,
  /* d     i     n     g     SP    o     p     e     r     a     t     i     n     g     SP    s */
   0x79, 0x73, 0x74, 0x65, 0x6D, 0x00, 0x4D, 0x69, 0x73, 0x73, 0x69, 0x6E, 0x67, 0x20, 0x6F, 0x70,
  /* y     s     t     e     m    NIL    M     i     s     s     i     n     g     SP    o     p */
   0x65, 0x72, 0x61, 0x74, 0x69, 0x6E, 0x67, 0x20, 0x73, 0x79, 0x73, 0x74, 0x65, 0x6D, 0x00, 0x00,
  /* e     r     a     t     i     n     g     SP    s     y     s     t     e     m */
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x8B, 0xFC, 0x1E, 0x57, 0x8B, 0xF5, 0xCB, 0x00};

static const BYTE BootCode[] = {
   0xFA, 0xB8, 0xC0, 0x07, 0x8E, 0xD8, 0x8E, 0xD0, 0xBC, 0x00, 0x04, 0xFB, 0xBE, 0x83, 0x00, 0xE8,
   0x0C, 0x00, 0xCD, 0x18, 0xF4, 0xEB, 0xFD, 0xB4, 0x0E, 0x33, 0xDB, 0xCD, 0x10, 0xC3, 0xAC, 0x0A,
   0xC0, 0x74, 0x05, 0xE8, 0xF1, 0xFF, 0xEB, 0xF6, 0xC3,

   //File System Boot Sector (C) is reserved.
   0x46, 0x69, 0x6c, 0x65, 0x20, 0x53, 0x79, 0x73, 0x74, 0x65, 0x6D, 0x20, 0x42, 0x6F, 0x6F, 0x74,
   0x20, 0x53, 0x65, 0x63, 0x74, 0x6F, 0x72, 0x20, 0x28, 0x43, 0x29, 0x20, 0x69, 0x73, 0x20, 0x72,
   0x65, 0x73, 0x65, 0x72, 0x76, 0x65, 0x64, 0x2E,
   //RTFiles Boot sector (c) 1998, 99 On Time
   //0x52, 0x54, 0x46, 0x69, 0x6C, 0x65, 0x73, 0x20, 0x42, 0x6F, 0x6F, 0x74, 0x20, 0x53, 0x65, 0x63,
   //0x74, 0x6F, 0x72, 0x20, 0x20, 0x28, 0x63, 0x29, 0x20, 0x31, 0x39, 0x39, 0x38, 0x2C, 0x39, 0x39,
   //0x20, 0x4F, 0x6E, 0x20, 0x54, 0x69, 0x6D, 0x65,

   0x0A, 0x0D, 0x54, 0x68, 0x65, 0x72, 0x65, 0x20, 0x69, 0x73, 0x20, 0x6E, 0x6F, 0x20, 0x4F, 0x53,
  /* LF    CR    T     h     e     r     e     SP    i     s     SP    n     o     SP    o     s */
   0x20, 0x74, 0x6F, 0x20, 0x62, 0x6F, 0x6F, 0x74, 0x20, 0x6F, 0x6E, 0x20, 0x74, 0x68, 0x69, 0x73,
  /* SP    t     o     SP    b     o     o     t     SP    o     n     SP    t     h     i     s */
   0x20, 0x64, 0x69, 0x73, 0x6B, 0x00};
  /* SP    d     i     s     k    NIL */

#endif /* __FS_PROPRIETARY_SET__ */

/*----------------------------------*/
static int QPowerTwo(unsigned int i)
{
   while (i != 0)
   {
      if ((i & 1) && (i != 1))
         return 0;
      i >>= 1;
   }
   return 1;
}

/*-----------------------------------*/
BYTE DefaultOSType(kal_uint32 Sectors, kal_uint32 LastCylinder)
{
   #define M *2048l
   BYTE Result;

   if (Sectors < (16 M))
      Result = 0x01;             // FAT 12
   else if (Sectors < (32 M))
      Result = 0x04;             // FAT 16, DOS < 4.0
   else if (Sectors < (512 M))
      Result = 0x06;             // FAT 16, DOS >= 4.0
   else
      Result = 0x0B;             // FAT 32
   if (LastCylinder >= 1024)
      switch (Result)
      {
         case 0x01:
         case 0x04:
         case 0x06:
            Result = 0x0E;       // FAT 16 LBA
            break;
         case 0x0B:
            Result = 0x0C;       // FAT 32 LBA
            break;
      }
   return Result;
}

/*-----------------------------------*/
int RTFAPI RTFCreateMasterBootRecord(void * MasterBootRecord,
                                     const RTFPartitionRecord * DiskGeometry)
{
   RTFMasterBootRecord * MBR = MasterBootRecord;
   kal_uint32 EndHead, EndTrack, Sectors;
#ifdef NAND_SUPPORT
   /* Added for NAND Writer Support */
   if (DiskGeometry->BootIndicator == 1)
   {
      for(Sectors = EndHead = 0; EndHead < 4; EndHead++)
      {
         if (MBR->PTable[EndHead].OSType == 0)
         {
            break;
         }
         Sectors = MBR->PTable[EndHead].RelativeSector + MBR->PTable[EndHead].Sectors;
      }
      if (DiskGeometry->Sectors < Sectors)
      {
         if (EndHead > 1)
         {
            MBR->PTable[1].Sectors = DiskGeometry->Sectors - MBR->PTable[1].RelativeSector;
         }
         else
         {
            MBR->PTable[0].Sectors = DiskGeometry->Sectors - MBR->PTable[0].RelativeSector;
         }
      }

      return RTF_NO_ERROR;
   }
#endif /* NAND_SUPPORT */

   // Acquire CHS mode disk size from disk geometry
   EndHead  = DiskGeometry->EndHead;
   Sectors  = DiskGeometry->EndSector & 63;
   EndTrack = DiskGeometry->EndTrack | (((DiskGeometry->EndSector & 0xC0) << 2));

   // Acquire LBA mode disk size from disk geometry
   if (DiskGeometry->Sectors == 0)
      return RTF_PARAM_ERROR;

   // LBA mode sectors must less than that of CHS mode
   if (DiskGeometry->Sectors < (1l * ((EndHead+1) * Sectors * (EndTrack+1))))
      return RTF_PARAM_ERROR;

   if (DiskGeometry->Sectors < 5)
      return RTF_PARAM_ERROR;

   // If Sectors is zero, then we have to make up values for EndHead, Sectors, and EndTrack
   // Since partitions always occupy complete tracks, try to minimize Sectors.
   // Some systems will grab a complete cylinder, so keep Heads low too.
   // A maximum CHS partition has (256*63*1024) sectors.

   if (Sectors == 0)
   {
      Sectors  = (DiskGeometry->Sectors-1) / (256l * 1 * 1024) + 1;
      Sectors  = fs_min(63, Sectors);
      EndHead  = (DiskGeometry->Sectors-1) / (1l * Sectors * 1024);
      EndHead  = fs_min(255, EndHead);
      EndTrack = (DiskGeometry->Sectors-1) / ((EndHead+1) * Sectors * 1);
      if (EndTrack >= 1024)  // we can't handle such tracks
         EndTrack = 0;
   }

   // check if the geometry can be used to access all of the drive
   // if not, do CHS translation
   while (DiskGeometry->Sectors > (1l * ((EndHead+1) * Sectors * (EndTrack+1))))
   {
      kal_uint32 Heads = EndHead+1;
      if (Heads <= 128)
      {
         Heads *= 2;
         EndHead = Heads - 1;
         EndTrack = (DiskGeometry->Sectors-1) / (Heads * Sectors * 1);
         if (EndTrack >= 1024)  // we can't handle such tracks
            EndTrack = 0;
      }
      else
         break;
   }

   kal_mem_set((void *)MBR, 0, SECTOR_SIZE);

#if !defined(__FS_PROPRIETARY_SET__)
   memcpy((void *)MBR->BootCode, (void *)MasterBootCode, sizeof( MasterBootCode));
#else
   kal_mem_set((void *)MBR->BootCode, (kal_uint8)'M', sizeof(MBR->BootCode));   // to save code size, use 'M' instead of MasterBootCode
#endif /* __FS_PROPRIETARY_SET__ */

   MBR->Signature = 0xAA55;

   MBR->PTable[0].BootIndicator = 0x80;

   // we will reserve the first track (not cylinder) for the partition table

   // CHS stuff. These fields are ignored on LBA-capable systems
   MBR->PTable[0].StartHead   = EndHead ? 1 : 0;
   MBR->PTable[0].StartSector = 1;
   MBR->PTable[0].StartTrack  = EndHead ? 0 : 1;

   MBR->PTable[0].EndHead     = EndHead;
   MBR->PTable[0].EndSector   = Sectors | ((EndTrack & 0x300) >> 2);
   MBR->PTable[0].EndTrack    = EndTrack;

   // LBA stuff. This must be correct on any size disk
   MBR->PTable[0].RelativeSector = Sectors;
   MBR->PTable[0].Sectors        = DiskGeometry->Sectors - Sectors;

   MBR->PTable[0].OSType = DefaultOSType(MBR->PTable[0].Sectors, (DiskGeometry->Sectors-1) / ((EndHead+1)*Sectors));

   return RTF_NO_ERROR;
}

/*-----------------------------------*/
int RTFAPI RTFSplitPartition(void * MasterBootRecord, RTFSector Sectors)
{
   RTFMasterBootRecord * MBR = MasterBootRecord;
   kal_uint32 SectorsPerCylinder,
         NewStartSector,
         NewStartCylinder,
         OldEndCylinder;
   RTFPartitionRecord * P = NULL; // The partition to split
   int i;

   // find the last partition and make sure an empty one follows

   for (i=0; i<4; i++)
      if (MBR->PTable[i].OSType != 0)
         P = MBR->PTable + i;

   if (P == NULL)
      return RTF_CORRUPTED_PARTITION_TABLE;

   if (P > (MBR->PTable + 2))
      return RTF_INVALID_FILE_SYSTEM;

   SectorsPerCylinder = (P->EndHead + 1) * (P->EndSector & 63);

   // round Sectors such that the end of the partition will be on a cylinder
   // boundary

   NewStartCylinder = (P->RelativeSector + Sectors) / SectorsPerCylinder;
#if 0
/* under construction !*/
/* under construction !*/
#else
   NewStartSector   = P->RelativeSector + Sectors;
#endif

   if (Sectors > P->Sectors)
      return RTF_INVALID_FILE_SYSTEM;

   if ((Sectors + SectorsPerCylinder) > P->Sectors)
      return RTF_INVALID_FILE_SYSTEM;

   if (NewStartCylinder >= 1024) // we can't put such values in the partition table
      NewStartCylinder = 0;

   // setup new partition

   P[1].StartHead   = 0;
   P[1].StartSector = 1 | ((NewStartCylinder & 0x300) >> 2);
   P[1].StartTrack  = NewStartCylinder;

   // move EndHead/Sector/Track from P to P+1

   P[1].EndHead     = P[0].EndHead;
   P[1].EndSector   = P[0].EndSector;
   P[1].EndTrack    = P[0].EndTrack;

   P[1].RelativeSector = NewStartSector;
   P[1].Sectors     = P[0].RelativeSector + P[0].Sectors - NewStartSector;

   // adjust P[0]'s EndHead/Sector/Track, Sectors

   OldEndCylinder   = (NewStartSector-2) / SectorsPerCylinder;
   if (OldEndCylinder >= 1024)
      OldEndCylinder = 0;

   P[0].EndSector   = (P[0].EndSector & 63) | ((OldEndCylinder & 0x300) >> 2);
   P[0].EndTrack    = OldEndCylinder;

   P[0].Sectors     = Sectors;

   // Set OSTypes

   P[0].OSType = DefaultOSType(P[0].Sectors, (P[0].RelativeSector + P[0].Sectors - 1) / SectorsPerCylinder);
   P[1].OSType = DefaultOSType(P[1].Sectors, (P[1].RelativeSector + P[1].Sectors - 1) / SectorsPerCylinder);

   return P - MBR->PTable + 1; // index of new partition
}

/*
  Partition Size    ClusterS  ClusterC
  ------------------------------------
  FAT-12   0-  1M    0.5k      0-  2k
          1M-  4M      1k     1k-  4k
          4M- 16M      2k     2k-
          8M- 16M      4k     2k-  4k

  FAT-16  2M-  8M    0.5k     4k- 16k
          8M- 32M      1k     8k- 32k
         32M-128M      2k    16k- 64k
        128M-512M      4k    32k-
        256M-512M      8k    32k- 64k

  FAT-32
        128M-256M      2k    64k-128k
        256M-  1G      4k    64k-256k
          1G-  4G      8k   128k-512k
          4G- 16G     16k   256k-  1M
         16G- 64G     32k   512k-  2M
         64G-256G     32k     2M-  8M
        256G-  1T     32k     8M- 32M
          1T-  2T     32k    32M- 64M

Default configurations do not allow cluster sizes beyond 4k for FAT-12
and 8k for FAT-16
*/

/*-----------------------------------*/
static kal_uint32 GetDefaultClusterSize(kal_uint32 Sectors, int FatType)
{
   kal_uint32 Result = 1;
   kal_uint32 Size;

   switch (FatType)
   {
      case 12:
         Size  = 1 M;
         break;
      case 16:
         Size  = 8 M;
         break;
#if !defined(__NOT_SUPPORT_FAT32__)
      case 32:
         Result = 4;
         Size  = 256 M;
         break;
#endif /* __NOT_SUPPORT_FAT32__ */
      /* Remove RVCT warning, Karen Hsu, 2004/11/02, ADD START */
      default:
         Size = 1 M;
         break;
      /* Remove RVCT warning, Karen Hsu, 2004/11/02, ADD END */
   }

   while (Size < Sectors)
   {
      Result <<= 1;
      Size <<= 2;
   }

   // the default must be Microsoft compatible, even though RTFiles supports more

   return (Result > 64) ? 64 : Result;
}

/*-----------------------------------*/
int RTFAPI RTFCreateBootSector(void * BootSector,
                               const RTFPartitionRecord * Partition,
                               BYTE MediaDescriptor,
                               UINT MinSectorsPerCluster,
                               kal_uint32 Flags)
{
   RTFBootRecord * BR = BootSector;
   int FatType;
   kal_uint32 SectorsPerCluster;
   kal_uint32 RootDirSectors, DataSectors, Clusters, NetSectors;
   /* Added for NAND Writer Support */
#ifdef NAND_SUPPORT
   if ((Partition->BootIndicator == 1) && (BR->BP.BytesPerSector != 0))
   {
      kal_uint32 FATSectors;

      FATSectors = (BR->BP.SectorsPerFAT) ? BR->BP.SectorsPerFAT : BR->BP.E._32.SectorsPerFAT;
      RootDirSectors    = (BR->BP.DirEntries * 32 + (BR->BP.BytesPerSector - 1)) / SECTOR_SIZE;
      DataSectors = BR->BP.TotalSectors
                     - BR->BP.ReservedSectors
                     - BR->BP.NumberOfFATs * FATSectors
                     - RootDirSectors;
      DataSectors = DataSectors / BR->BP.SectorsPerCluster;

      if (DataSectors <= 0xFF4L)
         FatType = 12;
      else if (DataSectors <= 0xFFF4l)
         FatType = 16;
      else
#if !defined(__NOT_SUPPORT_FAT32__)
         FatType = 32;
#else
         return RTF_INVALID_FILE_SYSTEM;
#endif /* __NOT_SUPPORT_FAT32__ */

      BR->BP.TotalSectors    = Partition->Sectors;
      BR->BP.SectorsOnDisk   = (Partition->Sectors >= 0x10000l) ? 0 : Partition->Sectors;
      goto CreatePBR_Return;
   }
#endif /* NAND_SUPPORT */

   if (!QPowerTwo(MinSectorsPerCluster))
      return RTF_PARAM_ERROR;

   #define FMT_FAT_ALL_FLAGS  (RTF_FMT_FAT_12 | RTF_FMT_FAT_16 | RTF_FMT_FAT_32)
   switch (Flags & FMT_FAT_ALL_FLAGS)
   {
      case RTF_FMT_FAT_12:
      case (RTF_FMT_FAT_12 | RTF_FMT_FAT_16):
         FatType = 12;
         break;
      case RTF_FMT_FAT_16:
      case (RTF_FMT_FAT_16 | RTF_FMT_FAT_32):
         FatType = 16;
         break;
#if !defined(__NOT_SUPPORT_FAT32__)
      case RTF_FMT_FAT_32:
         if (Flags & RTF_FMT_NO_FAT_32)
            return RTF_PARAM_ERROR;
         FatType = 32;
         break;
#endif /* __NOT_SUPPORT_FAT32__ */
      default:
         if (Partition->Sectors < (16 M))
            FatType = 12;
         else if (Partition->Sectors < (512 M))
            FatType = 16;
         else
#if !defined(__NOT_SUPPORT_FAT32__)
            if (Flags & RTF_FMT_NO_FAT_32)
               FatType = 16;
            else
               FatType = 32;
#else
            FatType = 16;
#endif /* __NOT_SUPPORT_FAT32__ */
   }

NewFATType:

#if !defined(__NOT_SUPPORT_FAT32__)
   if ((Flags & RTF_FMT_NO_FAT_32) && (FatType == 32))
       return RTF_INVALID_FILE_SYSTEM; // this can only happen due to a retry
#else
   if (FatType == 32)
       return RTF_INVALID_FILE_SYSTEM; // this can only happen due to a retry
#endif /* __NOT_SUPPORT_FAT32__ */

   kal_mem_set((void*)BR, 0, SECTOR_SIZE);
   BR->NearJump[0] = 0xEB;
   BR->NearJump[1] = 0x58;
   BR->NearJump[2] = 0x90;
#if !defined(__FS_PROPRIETARY_SET__)
   memcpy((void*)&BR->BootCode, (void*)BootCode, sizeof(BootCode));
#else
   kal_mem_set((void*)&BR->BootCode, (kal_uint8)'M', sizeof(BR->BootCode));	// to save code size, use 'M' instead of BootCode
#endif /* __FS_PROPRIETARY_SET__ */

   memcpy((void*)BR->BP.OEMName, "FileSys ", 8);
   BR->Signature          = 0xAA55;
   BR->BP.BytesPerSector  = SECTOR_SIZE;
   BR->BP.ReservedSectors = (FatType == 32) ? 32 : 1;
   BR->BP.TotalSectors    = Partition->Sectors;
   BR->BP.SectorsOnDisk   = (Partition->Sectors >= 0x10000l) ? 0 : Partition->Sectors;
   BR->BP.NumberOfHiddenSectors = Partition->RelativeSector;
   BR->BP.NumberOfFATs    = (Flags & RTF_FMT_SINGLE_FAT) ? 1 : 2;
   switch (FatType)
   {
#if !defined(__FS_PROPRIETARY_SET__)
      case 12: BR->BP.DirEntries = 128; break;
      case 16: BR->BP.DirEntries = 512; break;
#if !defined(__NOT_SUPPORT_FAT32__)
      case 32: BR->BP.DirEntries =   0; break;
#endif /* __NOT_SUPPORT_FAT32__ */
#else
      case 12:
      case 16: BR->BP.DirEntries =  16; break;
#if !defined(__NOT_SUPPORT_FAT32__)
      case 32: BR->BP.DirEntries =   0; break;
#endif /* __NOT_SUPPORT_FAT32__ */
#endif /* __FS_PROPRIETARY_SET__ */
   }
   BR->BP.MediaDescriptor = MediaDescriptor;
   BR->BP.SectorsPerTrack = Partition->EndSector & 63;
   BR->BP.NumberOfHeads   = Partition->EndHead + 1;

   {
      RTFExtendedBIOSParameter * EBPB = (FatType == 32) ? &BR->BP.E._32.BPB : &BR->BP.E._16.BPB;

      EBPB->PhysicalDiskNumber = (BR->BP.MediaDescriptor == 0xF8) ? 0x80 : 0;
      EBPB->Signature       = 0x29; // keep NT happy
      RTFSYSGetDateTime((RTFDOSDateTime*) &EBPB->SerialNumber);
      memcpy((void*)EBPB->Label, "NO NAME    ", sizeof(EBPB->Label));
      switch (FatType)
      {
         case 12: memcpy((void*)EBPB->SystemID, "FAT12   ", 8); break;
         case 16: memcpy((void*)EBPB->SystemID, "FAT16   ", 8); break;
#if !defined(__NOT_SUPPORT_FAT32__)
         case 32: memcpy((void*)EBPB->SystemID, "FAT32   ", 8); break;
#endif /* __NOT_SUPPORT_FAT32__ */
      }
   }

#if !defined(__NOT_SUPPORT_FAT32__)
   if (FatType == 32)
   {
      BR->BP.E._32.RootDirCluster = 2;
      BR->BP.E._32.FSInfoSector = 1;
      BR->BP.E._32.BackupBootSector = 6;
   }
#endif /* __NOT_SUPPORT_FAT32__ */

   RootDirSectors    = (BR->BP.DirEntries * 32 + (BR->BP.BytesPerSector - 1)) / SECTOR_SIZE;
   NetSectors        = BR->BP.TotalSectors - BR->BP.ReservedSectors - RootDirSectors;
   SectorsPerCluster = MinSectorsPerCluster ? MinSectorsPerCluster : GetDefaultClusterSize(BR->BP.TotalSectors, FatType);

NewClusterSize:

   switch (FatType)
   {
      case 12:
      case 16:
         // calculate the maximum FAT size assuming that the FAT itself needs just one sector.
         // Then, reduce the FAT one sector at a time until it no longer fits.
         // increase the FAT by one sector to a valid configuration (this
         // is done after the enclosing switch statement)

         #define FAT_12_SECTORS(Clusters) ((((Clusters)+2) * 3 / 2 - 1) / SECTOR_SIZE + 1)
         #define FAT_16_SECTORS(Clusters) ((((Clusters)+2) * 2     - 1) / SECTOR_SIZE + 1)
         #define FAT_SECTORS(Clusters)    ((FatType == 12) ? FAT_12_SECTORS(Clusters) : FAT_16_SECTORS(Clusters))

         BR->BP.SectorsPerFAT = FAT_SECTORS((FatType == 12) ? MAX_CLUSTERS_12 : MAX_CLUSTERS_16); // too large

         while (1)
         {
            DataSectors = NetSectors - BR->BP.NumberOfFATs * BR->BP.SectorsPerFAT; // too small
            Clusters    = DataSectors / SectorsPerCluster;

            // Do we have too many clusters?
            // If so, increase cluster size. This loop will increase the
            // number of data sectors, so this problem will not get fixed
            // and is detected in the first iteration
            if (Clusters > ((FatType == 12) ? MAX_CLUSTERS_12 : MAX_CLUSTERS_16))
            {
               if (SectorsPerCluster < (32l*1024))
               {
                  if ((Flags & RTF_FMT_FAT_32) == 0) // we are allowd to pick FAT type
                  {
                     switch (FatType)
                     {
                        case 12:
                           if (SectorsPerCluster >= 16)  // 8 KB
                           {
                              FatType = 16;
                              goto NewFATType;
                           }

                           break;
                        case 16:
                           if ((SectorsPerCluster >= 64) && ((Flags & RTF_FMT_NO_FAT_32) == 0)) // 32 KB
                           {
#if !defined(__NOT_SUPPORT_FAT32__)
                              FatType = 32;
                              goto NewFATType;
#else
                              return RTF_INVALID_FILE_SYSTEM;
#endif /* __NOT_SUPPORT_FAT32__ */
                           }
                     } // switch (FatType)
                  }
                  // increase cluster size if feasible or necessary
                  SectorsPerCluster *= 2;
                  goto NewClusterSize;
               }
               else
                  return RTF_INVALID_FILE_SYSTEM;
            }
            // Is our FAT big enough to hold all clusters?
            // If it's too small, increment (success).
            // This can't be true in the first interation as the maximum
            // FAT size must accomodate for MAX_CLUSTERS
            // If we have too many clusters, the previous check threw us
            // out already
            if (BR->BP.SectorsPerFAT < FAT_SECTORS(Clusters))
               break;

            BR->BP.SectorsPerFAT--;
         }
         BR->BP.SectorsPerFAT++;
         DataSectors = NetSectors - BR->BP.NumberOfFATs * BR->BP.SectorsPerFAT;
         Clusters    = DataSectors / SectorsPerCluster;
         // check that we do not have too few clusters
         if ((FatType == 16) && (Clusters <= MAX_CLUSTERS_12))
            return RTF_INVALID_FILE_SYSTEM;
         break;

#if !defined(__NOT_SUPPORT_FAT32__)
      case 32:
         // we do not have to worry about too many clusters
         // start with 512 cluster per fat (minimum for FAT-32) and increase until it fits.

         #define FAT_32_SECTORS(Clusters) ((((Clusters)+2) * 4 - 1) / SECTOR_SIZE + 1)

         for (BR->BP.E._32.SectorsPerFAT=512; ;BR->BP.E._32.SectorsPerFAT++)
         {
            DataSectors = NetSectors - BR->BP.NumberOfFATs * BR->BP.E._32.SectorsPerFAT;
            Clusters    = DataSectors / SectorsPerCluster;

            // Is our FAT big enough to hold all clusters?
            if (BR->BP.E._32.SectorsPerFAT >= FAT_32_SECTORS(Clusters))
               break;
         }
         // check that we do not have too few clusters
         if (Clusters <= MAX_CLUSTERS_16)
            return RTF_INVALID_FILE_SYSTEM;
         break;
#endif /* __NOT_SUPPORT_FAT32__ */
   }

   // record SectorsPerCluster

   if (SectorsPerCluster <= 128)
      BR->BP.SectorsPerCluster = SectorsPerCluster;
   else
   {
      BR->BP.SectorsPerCluster = 0;
      while ((1 << BR->BP.SectorsPerCluster) < SectorsPerCluster)
         BR->BP.SectorsPerCluster++;
      BR->BP.SectorsPerCluster |= 0x80;
   }

/* Added for NAND Writer Support */
#ifdef NAND_SUPPORT
CreatePBR_Return:
#endif /* NAND_SUPPORT */
   /* Add to support Renasas NAND, Karen Hsu, 2005/05/19, ADD START */
   if (Flags & RTF_FMT_GET_DATA_SECTOR)
   {
      if (FatType == 12)
         return (BR->BP.ReservedSectors + BR->BP.NumberOfFATs * BR->BP.SectorsPerFAT + RootDirSectors);
      else if (FatType == 16)
         return (BR->BP.ReservedSectors + BR->BP.NumberOfFATs * BR->BP.SectorsPerFAT + RootDirSectors);
#if !defined(__NOT_SUPPORT_FAT32__)
      else
         return (BR->BP.ReservedSectors + BR->BP.NumberOfFATs * BR->BP.E._32.SectorsPerFAT);
#endif /* __NOT_SUPPORT_FAT32__ */
   }

   /* Add to support Renasas NAND, Karen Hsu, 2005/05/19, ADD END */
   return FatType;
}


//-----------------------------------------------------------------------------
// SD Format
//-----------------------------------------------------------------------------
#define MB(x)  (x*2048)        // 1 MB = 2048 sectors * 512 bytes
#define GB(x)  (x*2048*1024)   // 1 MB = 2048 sectors * 512 bytes

// Calculate the minimum FAT table size
kal_uint32 SDGetSectorsPerFAT(kal_uint32 DataSectors, kal_uint32 SectorsPerCluster, kal_int32 FatType, kal_uint32 *Clusters)
{
    kal_uint32 MaxCluster;
    kal_uint32 SectorsPerFAT;

    MaxCluster = DataSectors / SectorsPerCluster + 2;  // Cluster 0 and 1 are reserved
    SectorsPerFAT = (MaxCluster * (FatType/4) + (SECTOR_SIZE*2-1)) / (SECTOR_SIZE*2);   // Ceil (MaxCluster * FatType / 8 / 512)
    *Clusters=MaxCluster;

    return SectorsPerFAT;
}

// Determine Sectors per Cluster (SC)
// SD file system spec V3, Table A-4, Table A-8, Table A-16
kal_uint32 SDDefaultClusterSize(kal_uint32 Sectors)
{
    kal_uint32 SectorsPerCluster;

    if (Sectors <= MB(8)) {
        SectorsPerCluster = 16;
    }
    else if (Sectors <= MB(1024)) {
        SectorsPerCluster = 32;
    }
    else {
        SectorsPerCluster = 64;
    }

    return SectorsPerCluster;
}

// Determine Boundary Unit
// SD file system spec V3, Table A-3 Table A-7
kal_uint32 SDDefaultBoundaryUnit(kal_uint32 Sectors)
{
    kal_uint32 BoundaryUnit;

    if (Sectors <= MB(8))   {
        BoundaryUnit=16;
    }
    else if (Sectors <= MB(64)) {
        BoundaryUnit=32;
    }
    else if (Sectors <= MB(256)) {
        BoundaryUnit=64;
    }
    else if (Sectors <= MB(2048)) {
        BoundaryUnit=128;
    }
    else {
        BoundaryUnit=8192;
    }
    return BoundaryUnit;
}

// Determine CHS paramters
// SD file system spec V3, Tabel A-1, A-6, A-14, CHS Recommendation
int SDGenCHSParameters(kal_uint32 Sectors, kal_uint32 *NoH, kal_uint32 *SPT)
{
    kal_uint32 NumberOfHeads, SectorsPerTrack;

    if (Sectors <= MB(2))  {
        NumberOfHeads=2; SectorsPerTrack=16;
    }
    else if (Sectors <= MB(16))  {
        NumberOfHeads=2; SectorsPerTrack=32;
    }
    else if (Sectors <= MB(32))  {
        NumberOfHeads=4; SectorsPerTrack=32;
    }
    else if (Sectors <= MB(128))  {
        NumberOfHeads=8; SectorsPerTrack=32;
    }
    else if (Sectors <= MB(504))  {
        NumberOfHeads=16; SectorsPerTrack=32;
    }
    else {
        NumberOfHeads=16; SectorsPerTrack=63;
    }

    while (Sectors > (NumberOfHeads*SectorsPerTrack*1024))   {
        NumberOfHeads*=2;
        if (NumberOfHeads==256) {
            NumberOfHeads--;
            break;
        }
    }

    *NoH=NumberOfHeads;
    *SPT=SectorsPerTrack;

    return 0;
}

// Determine Number of Root-directory Entries (RDE)
int SDGenRootDirEntires(kal_uint32 FatType)
{
    if (FatType==12 || FatType==16) {
        return 512;
    }
    else {
        return 0;
    }
}

// Generate SD Format Parameters
// Follow SD File System Spec. V3, Appendix C1, C2
int SDGenFormatParameter(
    kal_uint32  iSectors,
    kal_uint32 *oMaxClusters,
    kal_uint32 *oSectorsPerFAT,
    kal_uint32 *oHiddenSectors,
    kal_uint32 *oFatType,
    kal_uint32 *oReservedSectors,
    kal_uint32 *oUserDataOffset)
{
    kal_uint32 SectorsPerCluster;
    kal_uint32 FatType;
    kal_uint32 DirEntries, RootDirSectors;
    kal_uint32 DataSectors;
    kal_uint32 MaxCluster;
    kal_uint32 ClusterAreaOffset;
    kal_uint32 BoundaryUnit;
    kal_uint32 SectorsPerFAT;
    kal_uint32 ReservedSectors;
    kal_int32  RelativeSector=0;

    // Determine Cluster Size
    SectorsPerCluster=SDDefaultClusterSize(iSectors);

    // Determine FAT type
    if (iSectors <= MB(64))   {
        FatType = 12;  // FAT12
    }
    else if (iSectors <= MB(2048))   {
        FatType = 16;  // FAT16
    }
    else if (iSectors <= MB(32768))   {
        FatType = 32;  // FAT32
    }
    else {
        FatType = 64;
        return -1;
    }

    // Determine Boundary Unit Size
    BoundaryUnit = SDDefaultBoundaryUnit(iSectors);

    // Determine Number of Root-directory Entries (RDE)
    DirEntries = SDGenRootDirEntires(FatType);

    // RootDirSectors = BoundaryUnit;
    RootDirSectors = (DirEntries + 15) / 16;

    // Calculate FAT12/16 Format Parameter
    if (FatType==12 || FatType==16)  {
        ClusterAreaOffset = BoundaryUnit;
        ReservedSectors = 1;                // Boot Sector

        // The FAT table is growing forward to Cluster Area
        while (1)    {
            // Calculate how many sectors left in the cluster area
            DataSectors = iSectors - ClusterAreaOffset;

            // Calculate Sectors Per FAT
            SectorsPerFAT=SDGetSectorsPerFAT(DataSectors, SectorsPerCluster, FatType, &MaxCluster);

            // RelativeSector = ClusterAreaOffset - ReservedSectors - SectorsPerFAT*2 - RootDirSectors;

            // FAT table ending must less than cluster area starting
            if ((ReservedSectors + SectorsPerFAT*2 + RootDirSectors) > ClusterAreaOffset) {
                ClusterAreaOffset += BoundaryUnit;
            }
            // Condition Satisified, Calculate Partition Start
            else {
                RelativeSector = ClusterAreaOffset - ReservedSectors - SectorsPerFAT*2 - RootDirSectors;
                // MBR and BootSector must be allocated in different Boundary Unit
                if (RelativeSector < BoundaryUnit)    {
                    ClusterAreaOffset += BoundaryUnit;
                }
                else {
                    break;
                }
            }
        }
    }
    // Calculate FAT32 Format Parameter
    else {
        ClusterAreaOffset = BoundaryUnit * 2;
        RelativeSector = BoundaryUnit;
        ReservedSectors = 12;

        while (1)    {
            // Calculate how many sectors left in the cluster area
            DataSectors = iSectors - ClusterAreaOffset;

            // Calculate Sectors Per FAT
            SectorsPerFAT=SDGetSectorsPerFAT(DataSectors, SectorsPerCluster, FatType, &MaxCluster);

            // FAT table ending must aligned to boundary unit
            if ((RelativeSector + ReservedSectors + SectorsPerFAT*2) > ClusterAreaOffset)    {
                ClusterAreaOffset += BoundaryUnit;
            }
            // Condition Satisified, Calculate Reserved Sectors
            else {
                ReservedSectors = ClusterAreaOffset - RelativeSector - SectorsPerFAT*2;
                break;
            }
        }
    }

    *oMaxClusters = MaxCluster;
    *oSectorsPerFAT = SectorsPerFAT;
    *oHiddenSectors = RelativeSector;
    *oFatType = FatType;
    *oUserDataOffset = ClusterAreaOffset;
    *oReservedSectors = ReservedSectors;

   return 0;
}

// Create Master Boot Record for SDHC cards
// The return value is the offset to the Boot Sector
int SDCreateMasterBootRecord(void * MasterBootRecord, kal_uint32 Sectors)
{
    RTFMasterBootRecord *MBR = (RTFMasterBootRecord*) MasterBootRecord;

    kal_uint32 RelativeSector, TotalSectors;
    kal_uint32 NumberOfHeads, SectorsPerTrack;
    kal_uint32 StartingHead, StartingSector, StartingCylinder;
    kal_uint32 EndingHead, EndingSector, EndingCylinder;
    kal_uint8  SystemID;

    kal_uint32 MaxClusters,
        SectorsPerFAT,
        FatType,
        ReservedSectors,
        UserDataOffset;

    // Generate Format Parameter
    SDGenFormatParameter(
        Sectors,
        &MaxClusters,
        &SectorsPerFAT,
        &RelativeSector,
        &FatType,
        &ReservedSectors,
        &UserDataOffset);

    // Calculate Total Sectors in the partition
    TotalSectors = Sectors - RelativeSector;

    // Determine CHS paramters
    // SD file system spec V3, Tabel A-1, A-6, A-14, CHS Recommendation
    SDGenCHSParameters(Sectors, &NumberOfHeads, &SectorsPerTrack);

    // Calculate Partition CHS start/end
    // SD file system spec V3, C.1.2 CHS recommendation
    StartingHead     = ( RelativeSector % (NumberOfHeads*SectorsPerTrack) ) / SectorsPerTrack;
    StartingSector   = RelativeSector % SectorsPerTrack + 1;
    StartingCylinder = RelativeSector / (NumberOfHeads*SectorsPerTrack);

    EndingHead       = ( (RelativeSector + TotalSectors -1) % (NumberOfHeads*SectorsPerTrack) ) / SectorsPerTrack;
    EndingSector     = (RelativeSector + TotalSectors -1) % SectorsPerTrack + 1;
    EndingCylinder   = (RelativeSector + TotalSectors -1) / (NumberOfHeads*SectorsPerTrack);

    // Determine FAT Type
    // SD file system spec V3, Table A-4, Table A-8, Table A-16
    if (FatType==12)   {
        SystemID = 0x01;  // FAT12
    }
    else if (FatType==16)   {
        SystemID = 0x06;  // FAT16
    }
    else if (FatType==32)  {
        SystemID = 0x0B;  // FAT32
    }
    else {
        SystemID = 0x07;  // exFAT
    }

    if (EndingCylinder >= 1024) {
        switch (SystemID)   {
            case 0x01:
            case 0x04:
            case 0x06:
                SystemID = 0x0E;       // FAT 16 LBA
                break;
            case 0x0B:
                SystemID = 0x0C;       // FAT 32 LBA
                break;
            default:
                break;
        }
        EndingCylinder=1023;
        EndingHead=254;
        EndingSector=63;
    }

    // Clear MBR buffer
    kal_mem_set((void *)MBR, 0, SECTOR_SIZE);

/*
    Master Boot Record (MBR)
    ---------------------------------------
    Byte Offset Length (bytes)  Description
    ---------------------------------------
    0x0000  440 Boot Code
    0x01B8  4   Disk Signature
    0x01BC  2   Usually NULL (0x0000)
    0x01BE  16  Partition Entry 0
    0x01CE  16  Partition Entry 1
    0x01DE  16  Partition Entry 2
    0x01EE  16  Partition Entry 3
    0x01FE  2   MBR signature 0xAA55
*/

   // Copy BootCode (0~0x0)
#if !defined(__FS_PROPRIETARY_SET__)   // Perry: 0x00, Note: The size shall not exceed 446 bytes
   memcpy((void *)MBR->BootCode, (void *)MasterBootCode, sizeof(MasterBootCode));
#else
   kal_mem_set((void *)MBR->BootCode, (kal_uint8)'M', sizeof(MBR->BootCode));   // to save code size, use 'M' instead of MasterBootCode
#endif /* __FS_PROPRIETARY_SET__ */

    MBR->Signature = 0xAA55;              // 0x1FE
    MBR->PTable[0].BootIndicator = 0x00;  // 0x1BE, Table A-2

    // CHS stuff. These fields are ignored on LBA-capable systems
    MBR->PTable[0].StartHead   = StartingHead & 0xFF;
    MBR->PTable[0].StartSector = (StartingSector & 0x3F) | ((StartingCylinder & 0x300) >>2);
    MBR->PTable[0].StartTrack  = StartingCylinder & 0xFF;

    MBR->PTable[0].EndHead     = EndingHead;
    MBR->PTable[0].EndSector   = (EndingSector & 0x3F) | ((EndingCylinder & 0x300) >> 2);  // b'6 b'7 are part of cylinder
    MBR->PTable[0].EndTrack    = EndingCylinder & 0xFF;  // Cylinder

    // LBA stuff. This must be correct on any size disk
    MBR->PTable[0].RelativeSector = RelativeSector;
    MBR->PTable[0].Sectors        = TotalSectors;

    // Partition Type
    MBR->PTable[0].OSType = SystemID;

   return RelativeSector;
}


// For FAT12/16/32 Only
int SDCreateBootSector(void * BootSector, kal_uint32 Sectors, FS_PartitionRecord *Partition)
{
    kal_uint32 SectorsPerCluster;
    kal_uint32 ReservedSectors;
    kal_uint32 RelativeSector;
    kal_uint32 ClusterAreaOffset;
    kal_uint32 SectorsPerFAT;

    RTFBootRecord *BR = (RTFBootRecord*)BootSector;

    kal_uint32 MaxClusters, FatType;

    // Generate Format Parameter
    SDGenFormatParameter(
        Sectors,
        &MaxClusters,
        &SectorsPerFAT,
        &RelativeSector,
        &FatType,
        &ReservedSectors,
        &ClusterAreaOffset);

    // Determine Sectors per Cluster (SC)
    SectorsPerCluster = SDDefaultClusterSize(Sectors);

    // Clear BS buffer
    kal_mem_set((void *)BR, 0, SECTOR_SIZE);

    // Jump Command
    BR->NearJump[0] = 0xEB;
    BR->NearJump[1] = 0x00;
    BR->NearJump[2] = 0x90;

    // Boot Code
#if !defined(__FS_PROPRIETARY_SET__)
    memcpy((void*)&BR->BootCode, (void*)BootCode, sizeof(BootCode));
#else
    kal_mem_set((void*)&BR->BootCode, (kal_uint8)'M', sizeof(BR->BootCode));	// to save code size, use 'M' instead of BootCode
#endif // __FS_PROPRIETARY_SET__

    kal_mem_set((void*)BR->BP.OEMName, (kal_uint8)' ', 8);

    BR->Signature          = 0xAA55;
    BR->BP.BytesPerSector  = SECTOR_SIZE; // (SS)
    BR->BP.SectorsPerCluster = SectorsPerCluster; // (SC)
    BR->BP.ReservedSectors = ReservedSectors;  // (RSC)
    BR->BP.TotalSectors    = Partition->Sectors;  // (TS)
    BR->BP.SectorsOnDisk   = (Partition->Sectors >= 0x10000l) ? 0 : Partition->Sectors;
    BR->BP.NumberOfHiddenSectors = RelativeSector;
    BR->BP.NumberOfFATs    = 2;

    // Determin Number of Root-directory Entries (RDE)
    BR->BP.DirEntries = SDGenRootDirEntires(FatType);

    // CHS Parameters and Media Description
    BR->BP.MediaDescriptor = 0xF8;
    {
        kal_uint32 NumberOfHeads, SectorsPerTrack;

        SDGenCHSParameters(Sectors, &NumberOfHeads , &SectorsPerTrack);
        BR->BP.NumberOfHeads=NumberOfHeads;
        BR->BP.SectorsPerTrack=SectorsPerTrack;
    }

    // Common EBPB for FAT 12/16/32
    {
        RTFExtendedBIOSParameter * EBPB = (FatType == 32) ? &BR->BP.E._32.BPB : &BR->BP.E._16.BPB;

        EBPB->PhysicalDiskNumber = 0x80;
        EBPB->Signature          = 0x29;
        RTFSYSGetDateTime((RTFDOSDateTime*) &EBPB->SerialNumber);
        memcpy((void*)EBPB->Label, "NO NAME    ", sizeof(EBPB->Label));
        switch (FatType)      {
            case 12: memcpy((void*)EBPB->SystemID, "FAT12   ", 8); break;
            case 16: memcpy((void*)EBPB->SystemID, "FAT16   ", 8); break;
            case 32: memcpy((void*)EBPB->SystemID, "FAT32   ", 8); break;
            default: break;
        }
    }

   if (FatType == 32)   {
      BR->BP.E._32.RootDirCluster = 2;
      BR->BP.E._32.FSInfoSector   = 1;
      BR->BP.E._32.BackupBootSector = 6;
      BR->BP.E._32.SectorsPerFAT = SectorsPerFAT;
   }
   else {
      BR->BP.SectorsPerFAT   = SectorsPerFAT;
   }

   return FatType;
}

// Compare File System Parameters in MBR and Boot Sector
int SDCheckFormatParameter(void *MBR1, void *BS1, void *MBR2, void *BS2)
{
    RTFMasterBootRecord *mbr1 = (RTFMasterBootRecord*) MBR1;
    RTFMasterBootRecord *mbr2 = (RTFMasterBootRecord*) MBR2;
    RTFBootRecord *bs1 = (RTFBootRecord*)BS1;
    RTFBootRecord *bs2 = (RTFBootRecord*)BS2;
    kal_int32 result = FS_SD_FMT_OK;

    // MBR signatures must be the same (55AA)
    if ((mbr1->Signature != mbr2->Signature) || (bs1->Signature != bs2->Signature)) return FS_SD_FMT_SIGNATURE_FAIL;
    // There's only one possible concrete patition table
    if (memcmp((void*)&mbr1->PTable[0], (void*)&mbr2->PTable[0], sizeof(RTFPartitionRecord))) return FS_SD_FMT_MBR_FAIL;

    // Compare FAT parameters in boot sector
    // BytesPerSector(4),  SectorsPerCluster(1), ReservedSectors(4), NumberOfFATs(1)
    // DirEntries(4),      SectorsOnDisk(4)    , MediaDescriptor(1), SectorsPerFAT(4)
    // 4+1+4+1+4+4+1+4 = 23
    if (memcmp((void*)&bs1->BP.BytesPerSector, (void*)&bs2->BP.BytesPerSector, 23)) return FS_SD_FMT_BS_FAIL;

    // Compare FAT type in EBPB
    switch(mbr1->PTable[0].OSType)  {
        case 0x01:  // FAT12
        case 0x04: case 0x06: case 0x0E:  // FAT16
            if (memcmp(bs1->BP.E._16.BPB.SystemID, bs2->BP.E._16.BPB.SystemID, 8)) result = FS_SD_FMT_BS_FAIL;
            break;
        case 0x0B: case 0x0C:  // FAT32
            if (memcmp(bs1->BP.E._32.BPB.SystemID, bs2->BP.E._32.BPB.SystemID, 8)) result = FS_SD_FMT_BS_FAIL;
            break;
        default:
            return FS_SD_FMT_BS_FAIL;
    }

    return result;
}


