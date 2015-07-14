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
 *    flash_mtd.ramdisk.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This is flash MTD driver for ramdisk series devices.
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

MT6280 SIP_MDSP link fail.

[Solution]

Modify EXTSRAM_type_7() to switch $ram_disk_size become 0x40000 if it's MT6280

[Verification]

m sys_auto_gen on MT6280_EVB_R7R8_HSPA(SIP_MDSP).W12.17

and the generated EXTSRAM_FS maxsize becomes 0x40000 and dummy_end base is correct as well.

[Phase-in Branch]

MT6280_DVT_DEV

MODEM_DEV

[Version]

scatGenLib.pl m0.03

[Requester]

Stanley Chu

 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *******************************************************************************/

/********************************************************/
/*                  Include Header Files                */
/********************************************************/

#include "flash_opt.h"

#ifdef __RAMDISK__

#include "flash_mtd.h"
#include "flash_mtd_internal.h"
#include "DrvFlash.h"                      
#include "fs_errcode.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "fs_gprot.h"
#include "fs_iprot.h"
#include "ramdisk_gprot.h"

__attribute__ ((section ("STATICZI"))) kal_uint8 ram_disk[RAM_FS_SIZE];

#define __RAMDISK_MANAGER

/*----------------------
 * RAM Disk Manager
 *----------------------*/

//kal_uint32 _g_ramdisk_mounted = KAL_FALSE;

/*-----------------------------------*/
static void ramdisk_util_self_format_fat_pbr(void *DriveData, void *PBR, kal_uint32 RelativeSector)
{
   FS_BootRecord *BR    = (FS_BootRecord *)PBR;
   kal_uint32 FATSectors     = (BR->BP.SectorsPerFAT) ? BR->BP.SectorsPerFAT : BR->BP.E._32.SectorsPerFAT;
   kal_uint32 RootDirSectors = (BR->BP.DirEntries * 32 + (BR->BP.BytesPerSector - 1)) / BR->BP.BytesPerSector;
   kal_uint32 Written        = (BR->BP.TotalSectors - BR->BP.ReservedSectors - BR->BP.NumberOfFATs * FATSectors - RootDirSectors) / BR->BP.SectorsPerCluster;
   kal_uint32 ReservedSectors= BR->BP.ReservedSectors;
   int FATType          = FS_ERROR_RESERVED;

   if (Written <= 0xFF4L) {
      FATType = 12;
   } else if (Written <= 0xFFF4l) {
      FATType = 16;
   } else if (Written <= 0xFFFFFF4l) {
      FATType = 32;
   }

   // Write first FAT
   // After PBR used for identify FATType, PBR contents is not useful, so use the same buffer to store FAT
   kal_mem_set(PBR, 0, 512);

   switch (FATType) {
      case 32:
   {
         kal_uint32 *FPtr = PBR;
         FPtr[2] = 0x0FFFFFFF;         // this is for the root dir
         FPtr[1] = 0x0FFFFFFF;         // EOC (End Of Clusterchain)
         FPtr[0] = (kal_uint32)0x0FFFFFF8;  // MediaDescriptor
   }
      break;
      case 16:
      {
         WORD *FPtr = PBR;
         FPtr[1] = 0xFFFF;             // EOC (End Of Clusterchain)
         FPtr[0] = (WORD)0xFFF8;       // MediaDescriptor
      }
      break;
      case 12:
      {
         kal_uint8 *FPtr = PBR;
         FPtr[2] = 0xFF;               // EOC (End Of Clusterchain) (Byte 3-5)
         FPtr[1] = 0xFF;
         FPtr[0] = 0xF8;               // MediaDescriptor (Byte 0-2)
      }
      break;
   }
   // FAT12/16 : BR->BP.ReservedSectors = 1
   // FAT32    : BR->BP.ReservedSectors = 32
   ramdisk_fdm_write_sectors(DriveData, RelativeSector + ReservedSectors, 1, PBR);
}

/*-----------------------------------*/
static void ramdisk_util_self_formt_fat(void * D, int DeviceType)
{
    FS_PartitionRecord Par, Par1;
    kal_uint8 *Buffer;

    kal_mem_set((void*)&Par, 0, sizeof Par);
    kal_mem_set((void*)&Par1, 0, sizeof Par);

    Buffer = (kal_uint8 *)get_ctrl_buffer(512);

    Par.Sectors = RAM_FS_SIZE / RAM_SECTOR_SIZE;   // Total FAT sectors

   switch (DeviceType)
   {
      case FS_DEVICE_FDISK:
         FS_CreateMasterBootRecord((void*)Buffer, &Par);

         if(RAM_FS_FIRST_DRIVE_SECTORS_INT > 0)
      {
            FS_SplitPartition((void*)Buffer, RAM_FS_FIRST_DRIVE_SECTORS_INT);
         }

         /* write MBR */
         ramdisk_fdm_write_sectors((void*)D, 0, 1, (void*)Buffer);

      break;
   default:
         ASSERT(0);
         return;
   }
   /* get partition records */
   Par = ((FS_MasterBootRecord *)Buffer)->PTable[0];
   Par1 = ((FS_MasterBootRecord *)Buffer)->PTable[1];

   /* create and write PBR, then format FAT table for system drive */
   FS_CreateBootSector((void*)Buffer, &Par, 0xF8, 0, FS_FMT_SINGLE_FAT | FS_FMT_NO_FAT_32);
   ramdisk_fdm_write_sectors((void*)D, Par.RelativeSector, 1, (void*)Buffer);
   ramdisk_util_self_format_fat_pbr((void*)D, (void*)Buffer, Par.RelativeSector);

   /* create and write PBR, then format FAT table for user drive */
   if(RAM_FS_FIRST_DRIVE_SECTORS_INT > 0 && DeviceType != FS_DEVICE_FLOPPY)
      {
      FS_CreateBootSector((void*)Buffer, &Par1, 0xF8, 0, FS_FMT_SINGLE_FAT | FS_FMT_NO_FAT_32);
      ramdisk_fdm_write_sectors((void*)D, Par1.RelativeSector, 1, (void*)Buffer);
      ramdisk_util_self_format_fat_pbr((void*)D, (void*)Buffer, Par1.RelativeSector);
   }

   free_ctrl_buffer(Buffer);
}

/*-----------------------------------*/
void ramdisk_util_memcpy(void * dst, void * src, kal_uint32 len)
{
    kal_uint32 * addr_dst_32 = (kal_uint32 *) dst;
    kal_uint32 * addr_src_32 = (kal_uint32 *) src;
    kal_uint8  * addr_dst_8;
    kal_uint8  * addr_src_8;

    if (!((kal_uint32)src & 0xFFFFFFFC) && !((kal_uint32)dst & 0xFFFFFFFC))
         {
        while (len >= 4)
            {
            *addr_dst_32++ = *addr_src_32++;
            len -= 4;
            }
         }

    addr_dst_8 = (kal_uint8 *) addr_dst_32;
    addr_src_8 = (kal_uint8 *) addr_src_32;

    while (len--)
         {
        *addr_dst_8++ = *addr_src_8++;
    }
}

/*-----------------------------------*/
int ramdisk_fdm_mount_device(void * DriveData, int DeviceNumber, int DeviceType, kal_uint32 Flags)
{
    kal_uint8 *buf;

    // auto self-format if required

    // Check MBR

    buf = (kal_uint8 *)get_ctrl_buffer(512);

    ramdisk_fdm_read_sectors(DriveData, 0, 1, buf);

    if ((((FS_MasterBootRecord *)buf)->Signature == 0xAA55)
    && (((FS_MasterBootRecord *)buf)->PTable[0].Sectors != 0))
            {
        // Check PBR

        ramdisk_fdm_read_sectors(DriveData, 1, 1, buf);

        if ((((FS_BootRecord *)buf)->Signature == 0xAA55))
        {
            free_ctrl_buffer(buf);

            return 512;    // MBR and PBR are both valid
            }
    }

    free_ctrl_buffer(buf);

    // MBR or PBR is invalid, do self-format

    kal_mem_set((kal_uint8 *)(ram_disk), 0x0, RAM_FS_SIZE);

    ramdisk_util_self_formt_fat(DriveData, DeviceType);

    return 512;
}

/*-----------------------------------*/
int ramdisk_fdm_shutdown(void * DriveData)
{
   return FS_NO_ERROR;
}

/*-----------------------------------*/
int ramdisk_fdm_read_sectors(void * DriveData, kal_uint32 Sector, kal_uint32 Sectors, void * Data)
{
    kal_uint8 * addr_src     = (kal_uint8 *)ram_disk + (Sector * RAM_SECTOR_SIZE);

    ramdisk_util_memcpy(Data, (void *)addr_src, Sectors * RAM_SECTOR_SIZE);

   return FS_NO_ERROR;
}

int ramdisk_fdm_write_sectors(void * DriveData, kal_uint32 Sector, kal_uint32 Sectors, void * Data)
{
    kal_uint8 * addr_dst = (kal_uint8 *)ram_disk + (Sector * RAM_SECTOR_SIZE);

    ramdisk_util_memcpy((void *)addr_dst, Data, Sectors * RAM_SECTOR_SIZE);

   return FS_NO_ERROR;
}

int ramdisk_fdm_recoverable_write_sectors(void * DriveData, kal_uint32 Sector, kal_uint32 Sectors, void * Buffer) // Recoverable support (fake)
{
    return ramdisk_fdm_write_sectors(DriveData, Sector, Sectors, Buffer);
}

int ramdisk_fdm_resume_sector_states(void * DriveData)

{
   return FS_NO_ERROR;
}

int ramdisk_fdm_media_changed(void * DriveData)
{
   return FS_NO_ERROR;   // this is not a removeable device
}

int ramdisk_fdm_get_disk_geometry(void * DriveData, FS_PartitionRecord * DiskGeometry, kal_uint8 * MediaDescriptor)
{
   kal_mem_set((void*)DiskGeometry, 0, sizeof * DiskGeometry);
   DiskGeometry->StartSector = 1;
   DiskGeometry->Sectors = RAM_FS_SIZE / RAM_SECTOR_SIZE;
   *MediaDescriptor = 0xF8;

   return FS_NO_ERROR;
}

#define __RAMDISK_TOOLS

/*
 *  Check if RAM Disk is supported in this project. Please use this API to detect RAM Disk before using any other RAM Disk APIs.
 *
 *  Return Value:
 *      1: RAM Disk is existed.
 *      0: RAM Disk is not existed.
 */
kal_uint32 ramdisk_is_existed()
{
    #if defined(__RAMDISK__)
        return 1;
    #else
        return 0;
    #endif
}

/*
 *  Get start address of RAM Disk.
 *
 *  Return Value:
 *      Valid address must be a non-zero value. 0 means an invalid address.
 */
kal_uint32 ramdisk_get_raw_start_address()
{
    #if defined(__RAMDISK__)
        return (kal_uint32)&ram_disk[0];
    #else
        return 0;
    #endif
}

/*
 *  Get length of RAM Disk.
 *
 *  Return Value:
 *      Valid length must be a non-zero value. 0 means an invalid length.
 */
kal_uint32 ramdisk_get_raw_length()
{
    #if defined(__RAMDISK__)
        return RAM_FS_SIZE;
    #else
        return 0;
    #endif
}

/*
 *  Get raw data from RAM Disk.
 *
 *  Parameters:
 *      [in/out] buf: Buffer address to read RAM Disk data (Buffer address could be byte-aligned)
 *      [in] offset: Start offset. The valid range is 0 to disk size.
 *      [in] length: Total read length
 *
 *  Return Value:
 *      Positive integer: Number of bytes read to buffer successfully.
 *      Negative integer: It is an error code. Please refer to ramdisk_error_code enum defined in ramdisk_gprot.h for the meaning of error codes.
 */
kal_int32 ramdisk_get_raw_data(void * buf, kal_uint32 offset, kal_uint32 length)
{
    #if defined(__RAMDISK__)

        kal_uint8 * p_ramdisk;
        kal_uint8 * p_buf = (kal_uint8 *)buf;
        kal_uint32  i;

        if (offset > RAM_FS_SIZE)
        {
            return RAMDISK_INVALID_DISK_OFFSET;
        }

        if (offset + length > RAM_FS_SIZE)
        {
            return RAMDISK_INVALID_DISK_SIZE;
        }

        p_ramdisk = (kal_uint8 *)ram_disk + offset;

        for (i = 0; i < length; ++i)
        {
            *p_buf++ = *p_ramdisk++;
        }

        return i;

    #else   // !__RAMDISK__

        return RAMDISK_NOT_EXISTED;

    #endif  // __RAMDISK__
}

#endif //__RAMDISK__
