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
 *   fs_internal_api.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file provides MTK file system internal common APIs.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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

/*-----------------------------------
 * Included Header Files
 *-----------------------------------*/

#include "kal_general_types.h"
#include "fs_internal_def.h"
#include "fs_gprot.h"
#include "rtfiles.h"
#include "fs_utility.h"
#include "fs_kal.h"
#include "fs_internal_api.h"
#include "cache_sw.h"   // for AFM
#include "kal_afm.h"    // for _XData allocation

/*-----------------------------------
 * Macros
 *-----------------------------------*/

// Assert
#define fs_assert_local(expr) fs_assert(expr, fs_internal_api_c)
#define fs_ext_assert_local(expr, e1, e2, e3) fs_ext_assert(expr, fs_internal_api_c, e1, e2, e3)

/*-----------------------------------
 * Global Variables
 *-----------------------------------*/

/*-----------------------------------
 * Funciton Bodies
 *-----------------------------------*/
FS_DEVICE_TYPE_ENUM fs_conf_get_default_devtype(void)
{
#if defined(__EMMC_BOOTING__)
    return FS_DEVICE_TYPE_EMMC;
#elif defined(_NAND_FLASH_BOOTING_) || defined(__FS_SYSDRV_ON_NAND__)
    return FS_DEVICE_TYPE_NAND;
#else
    return FS_DEVICE_TYPE_NOR;
#endif
}

FS_Device* fs_conf_find_dev_by_devtype(FS_DEVICE_TYPE_ENUM dev_type, kal_uint32 serial)
{
   FS_Device   *dev;
   kal_uint32  dev_flag;
   kal_uint32  count;

   dev_flag = fs_conf_get_devflag_by_devtype(dev_type);

   if (0 == dev_flag || 0 == serial)
      return NULL;

   for (dev = (FS_Device*)gFS_DeviceList, count = 0; dev->DeviceType; dev++)
   {
      if (dev->DeviceFlags & dev_flag)
      {
         count++;

         if (count == serial)
         {
            return dev;
         }
      }
   }

   return NULL;
}

kal_uint32 fs_conf_get_devflag_by_devtype(FS_DEVICE_TYPE_ENUM dev_type)
{
   switch (dev_type)
   {
      case FS_DEVICE_TYPE_NOR:
         return FS_DEVICE_NOR_FLASH;

      case FS_DEVICE_TYPE_NAND:
         return FS_DEVICE_NAND_FLASH;

      case FS_DEVICE_TYPE_EXTERNAL:
         return FS_DEVICE_EXTERNAL;

      case FS_DEVICE_TYPE_CARD:
         return FS_DEVICE_REMOVABLE;

      case FS_DEVICE_TYPE_SIMPLUS:
         return FS_DEVICE_SIMPLUS;

      default:
         return 0;
   }
}

kal_uint32 fs_conf_get_devtype_by_devflag(kal_uint32 dev_flag)
{
   if (dev_flag & FS_DEVICE_NOR_FLASH)
   {
      return FS_DEVICE_TYPE_NOR;
   }
   else if (dev_flag & FS_DEVICE_NAND_FLASH)
   {
      return FS_DEVICE_TYPE_NAND;
   }
   else if (dev_flag & FS_DEVICE_EXTERNAL)
   {
      return FS_DEVICE_TYPE_EXTERNAL;
   }
   else if (dev_flag & FS_DEVICE_REMOVABLE)
   {
      return FS_DEVICE_TYPE_CARD;
   }

   return FS_DEVICE_TYPE_UNKNOWN;
}

FS_File* fs_conf_get_file_by_fh(FS_HANDLE fh)
{
    kal_int16  ft_idx;

    ft_idx = FS_GetFileTableIdx(fh);

    if (ft_idx >= 0 && ft_idx < FS_MAX_FILES)
        return (FS_File*)(gFS_Data.FileTable + ft_idx);
    else
        return NULL;
}

kal_uint32 fs_conf_get_first_drive_size(FS_Device *dev, kal_uint32 avail_sectors) // unit: #sectors
{
#ifdef __EMMC_BOOTING__
    kal_uint32 dev_flag;

    dev_flag = dev->DeviceFlags;

    if (dev_flag & FS_DEVICE_EMMC)
    {
        if (avail_sectors < _gfs_system_drive_size)
        {
            return (0xFFFFFFFF);
        }
        else
        {
            return (avail_sectors - _gfs_system_drive_size);
        }

    }
#endif // __EMMC_BOOTING__

    return 0xFFFFFFFF;
}

WCHAR fs_conf_get_native_drive_letter(WCHAR drv_letter)
{
    drv_letter = fs_util_wchar_toupper(drv_letter);

    if (drv_letter == (WCHAR)DrvMappingNew) // It should be capital 'Z'
    {
        return (WCHAR)DrvMappingOld;
    }
    else if (drv_letter >= (WCHAR)MT_BASE_DRIVE_LETTER &&
             drv_letter < (WCHAR)(MT_BASE_DRIVE_LETTER + FS_MAX_DRIVES))
    {
        return drv_letter;
    }
    else
    {
        return 0;
    }
}

kal_bool fs_conf_query_if_sys_drv(WCHAR drv_letter, WCHAR *native_drv_letter)
{
    // get native drive letter
    drv_letter = fs_conf_get_native_drive_letter(drv_letter);

    // fill-in native_drv_letter
    if (native_drv_letter)
    {
        *native_drv_letter = drv_letter;
    }

    // check if system drive
    if (drv_letter == DrvMappingOld)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }

}

FS_Drive* fs_conf_get_drv_struct_by_drv_letter(WCHAR drv_letter)
{
    drv_letter = fs_conf_get_native_drive_letter(drv_letter);

    if (0 != drv_letter)
    {
        return (FS_Drive*)&(gFS_Data.DriveTable[drv_letter - MT_BASE_DRIVE_LETTER]);
    }
    else
    {
        return NULL;
    }
}

#define FS_TLS_TOOLS

kal_uint32 fs_conf_get_tls_idx()
{
    return (kal_uint32)RTFSYSGetTaskIndex();
}

#define FS_FILE_HANDLE_TOOLS

kal_bool fs_fh_is_aborted(FS_File *f)
{
    if (f->Valid == FS_FH_ABORTED)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

#define FS_FORMAT_TOOLS
/*------------------------------------------------------------------
 * NOTE:
 *    1. Ensure Device and System is locked before using this API.
 *    2. Ensure all device buffers are flushed and discarded before
 *       because this API will directly access device via driver.
 *------------------------------------------------------------------*/
int fs_fmt_self_format(FS_Device *Dev, kal_uint32 DeviceType)
{
   FS_PartitionRecord   par0, par1;
   kal_uint32           public_drive_size;
   kal_uint32           sectors_per_cylinder;
   kal_uint8            *buf;
   kal_uint8            media_descriptor;
   kal_int32            result = FS_NO_ERROR;
   FS_MasterBootRecord  *mbr;

   buf = (kal_uint8*)get_ctrl_buffer(512);

   // driver checking
   if (NULL == Dev ||
       NULL == Dev->Driver ||
       NULL == Dev->Driver->ReadSectors ||
       NULL == Dev->Driver->WriteSectors ||
       NULL == Dev->Driver->GetDiskGeometry ||
       NULL == Dev->Driver->HighLevelFormat)
   {
      result = FS_UNSUPPORTED_DRIVER_FUNCTION;
      goto SelfFormt_Exit;
   }

   result = Dev->Driver->ReadSectors(Dev->DriverData, 0, 1, (void*)buf);

   if (FS_NO_ERROR > result)
      goto SelfFormt_Exit;

   kal_mem_set((void*)&par0, 0, sizeof(FS_PartitionRecord));
   kal_mem_set((void*)buf, 0, sizeof(FS_MasterBootRecord));

   /*------------------------------------------------------
    * Step 1. Get total FAT sectors by GetDiskGeometry.
    *         GetDiskGeometry should fill-in par.Sector.
    *------------------------------------------------------*/

   Dev->Driver->GetDiskGeometry(Dev->DriverData, &par0, &media_descriptor);

   if (0 == par0.Sectors)
   {
      result = FS_INVALID_FILE_SYSTEM;
      goto SelfFormt_Exit;
   }

   /*---------------------
    * Step 2. Create MBR
    *---------------------*/

   switch (DeviceType)
   {
      case FS_DEVICE_FDISK:

         // 1. create MBR
         FS_CreateMasterBootRecord((void*)buf, &par0);

         // 2. Split partition if required
         mbr    = (FS_MasterBootRecord*)buf;

         public_drive_size = fs_conf_get_first_drive_size(Dev, par0.Sectors - mbr->PTable[0].RelativeSector);

         fs_assert_local(public_drive_size != 0xFFFFFFFF);

         if (public_drive_size != 0xFFFFFFFF && public_drive_size > 0)  // for customer version (assert is disabled), invalid public drive size should be passed.
         {
            sectors_per_cylinder = (mbr->PTable[0].EndHead + 1) * (mbr->PTable[0].EndSector & 63);

            fs_assert_local(mbr->PTable[0].Sectors >= sectors_per_cylinder);    // [todo] should remove cylinder rule

            public_drive_size= fs_min(public_drive_size, (mbr->PTable[0].Sectors - sectors_per_cylinder));

            fs_assert_local(par0.Sectors > public_drive_size);

            if ((result = FS_SplitPartition((void*)buf, public_drive_size)) < FS_NO_ERROR)
            {
                goto SelfFormt_Exit;
            }
         }

         // 3. Write MBR
         result = Dev->Driver->WriteSectors(Dev->DriverData, 0, 1, (void*)buf);

         if (FS_NO_ERROR > result)
            goto SelfFormt_Exit;

         break;

      default:

         result = FS_INVALID_FILE_SYSTEM;
         goto SelfFormt_Exit;
   }

   /*---------------------
    * Step 3. Create PBRs
    *---------------------*/

   //--- 1. copy partition records
   par0 = ((FS_MasterBootRecord*)buf)->PTable[0];
   par1 = ((FS_MasterBootRecord*)buf)->PTable[1];

   //--- 2. create and write par0's PBR

   result = Dev->Driver->ReadSectors(Dev->DriverData, par0.RelativeSector, 1, (void*)buf);

   if (FS_NO_ERROR > result)
      goto SelfFormt_Exit;

   // create and write PBR, then format FAT table for system drive
   FS_CreateBootSector((void*)buf, &par0, 0xF8, 0, FS_FMT_SINGLE_FAT);

   // write PBR
   result = Dev->Driver->WriteSectors(Dev->DriverData, par0.RelativeSector, 1, (void*)buf);

   if (FS_NO_ERROR > result)
      goto SelfFormt_Exit;

   result = Dev->Driver->HighLevelFormat(Dev->DriverData, par0.RelativeSector);

   if (FS_NO_ERROR > result)
      goto SelfFormt_Exit;

   //--- 3. create and write par1's PBR
   if (public_drive_size > 0)
   {
      result = Dev->Driver->ReadSectors(Dev->DriverData, par1.RelativeSector, 1, (void*)buf);

      if (FS_NO_ERROR > result)
         goto SelfFormt_Exit;

      FS_CreateBootSector((void*)buf, &par1, 0xF8, 0, FS_FMT_SINGLE_FAT);

      // write PBR
      result = Dev->Driver->WriteSectors(Dev->DriverData, par1.RelativeSector, 1, (void*)buf);

      if (FS_NO_ERROR > result)
         goto SelfFormt_Exit;

      result = Dev->Driver->HighLevelFormat(Dev->DriverData, par1.RelativeSector);

      if (FS_NO_ERROR > result)
         goto SelfFormt_Exit;
   }

SelfFormt_Exit:

   free_ctrl_buffer(buf);

   return result;
}

#define FS_BIT_OPERATION_LIBRARY

void fs_lib_bit_set(kal_uint32 *bitmap, kal_uint32 index)
{
    kal_uint32 seg;

    seg = index >> 5;                 // index / (sizeof(kal_uint32) * 8)
    index = index & 0x00007FFF;     // index % (sizeof(kal_uint32) * 8)

    bitmap[seg] |= (1 << index);
}

void fs_lib_bit_clear(kal_uint32 *bitmap, kal_uint32 index)
{
    kal_uint32 seg;

    seg = index >> 5;                 // index / (sizeof(kal_uint32) * 8)
    index = index & 0x00007FFF;     // index % (sizeof(kal_uint32) * 8)

    bitmap[seg] &= ~(1 << index);
}

void fs_lib_bit_init_map(kal_uint32 *bitmap, kal_uint32 size) // size: number of "kal_uint32"
{
    // clear bit map
    kal_mem_set(bitmap, 0, size * sizeof(kal_uint32));
}

kal_uint32 fs_lib_bit_find_first_zero(kal_uint32 *bitmap, kal_uint32 size)
{
    kal_uint32 seg, ofs, tmp;

    for (seg = 0; seg < size; ++seg)
    {
        if (bitmap[seg] != 0xFFFFFFFF)
        {
            ofs = 31;
            tmp = ~bitmap[seg];

            if (tmp & 0x0000FFFF) { ofs  -= 16; tmp <<= 16; }
            if (tmp & 0x00FF0000) { ofs  -= 8; tmp <<= 8; }
            if (tmp & 0x0F000000) { ofs  -= 4; tmp <<= 4; }
            if (tmp & 0x30000000) { ofs  -= 2; tmp <<= 2; }
            if (tmp & 0x40000000) { ofs  -= 1; }

            return (seg * 32) + ofs;
        }
    }

    return (0xFFFFFFFF);
}


#define FS_MEMORY_MANAGER

#if defined(__FS_XDATA_MEMORY_NOT_IN_STACK__)

#define FS_MEMPOOL_XDATA_AFM_OPTIONS    (NULL)
#define FS_MEMPOOL_XDATA_COUNT          (40)
const int FS_MEMPOOL_XDATA_TOTAL_SIZE = KAL_AFM_POOL_OVERHEAD(FS_MEMPOOL_XDATA_AFM_OPTIONS, 1) +
                                        KAL_AFM_SUBPOOL_OVERHEAD(FS_MEMPOOL_XDATA_AFM_OPTIONS, sizeof(_XData), FS_MEMPOOL_XDATA_COUNT);
__fs_align(32) kal_uint8 _gfs_xdata[FS_MEMPOOL_XDATA_TOTAL_SIZE];
kal_uint32            _gfs_xdata_subpool_size[]   = {(kal_uint32)(sizeof(_XData)), 0xFFFFFFFF};
kal_uint32            _gfs_xdata_subpool_count[]  = {FS_MEMPOOL_XDATA_COUNT, 0xFFFFFFFF};
KAL_AFM_ID            _gfs_xdata_afm_id = NULL;
kal_uint32            _gfs_xdata_available = FS_MEMPOOL_XDATA_COUNT;

#endif  // __FS_XDATA_MEMORY_NOT_IN_STACK__

void fs_mem_init()
{
    #if defined(__FS_XDATA_MEMORY_NOT_IN_STACK__)
    kal_uint32 left_mem;
    _gfs_xdata_afm_id = kal_afm_create(_gfs_xdata,
                                     FS_MEMPOOL_XDATA_TOTAL_SIZE,
                                     _gfs_xdata_subpool_size,
                                     _gfs_xdata_subpool_count,
	                                 FS_MEMPOOL_XDATA_AFM_OPTIONS,
	                                 &left_mem);
    #endif
}

void* fs_mem_alloc(fs_mem_type_enum type, kal_uint32 size, kal_uint32 options)
{
    void *addr = NULL;

    fs_lock_get_mutex(_gfs_lock_common, FS_INFINITE);

    #if defined(__FS_XDATA_MEMORY_NOT_IN_STACK__)
    if (FS_MEM_TYPE_XDATA == type)    // for FS job
    {
        addr = kal_afm_alloc(_gfs_xdata_afm_id, sizeof(_XData));

        if (addr == NULL) ASSERT(0);

        _gfs_xdata_available--;
    }
    #endif

    fs_lock_free_mutex(_gfs_lock_common);

    return addr;
}

void fs_mem_free(fs_mem_type_enum type, void * addr, kal_uint32 size)
{
    fs_lock_get_mutex(_gfs_lock_common, FS_INFINITE);

    #if defined(__FS_XDATA_MEMORY_NOT_IN_STACK__)
    if (FS_MEM_TYPE_XDATA == type)    // for FS job
    {
        kal_afm_free(_gfs_xdata_afm_id, addr);

        _gfs_xdata_available++;
    }
    #endif

    fs_lock_free_mutex(_gfs_lock_common);
}
