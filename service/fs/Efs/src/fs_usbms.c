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
 *   fs_usbms.c
 *
 * Project:
 * --------
 *   Maui Software
 *
 * Description:
 * ------------
 *   Interface between File System and USB mass storage driver
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
#include "fs_kal.h"
#include "fs_utility.h"
#include "rtfiles.h"

#include "drv_comm.h"
#include "usb_msdisk.h"

FS_HANDLE           gFS_USBMS_PhoneDriveHandle = -1;
kal_uint32          _gfs_usbms_err_line        = 0;
kal_uint32          _gfs_usbms_err_param[3]    = {0, 0, 0};

static void fs_usbms_error(kal_uint32 line, kal_uint32 e1, kal_uint32 e2, kal_uint32 e3)
{
    _gfs_usbms_err_line = line;
    _gfs_usbms_err_param[0] = e1;
    _gfs_usbms_err_param[1] = e2;
    _gfs_usbms_err_param[2] = e3;
}

#undef  fs_ext_assert_local
#define fs_ext_assert_local(expr, e1, e2, e3)  do {if(!(expr)) fs_usbms_error(__LINE__, e1, e2, e3); } while (0)

static kal_bool fs_usbms_read_sysdrv( void *data, kal_uint32 LBA, kal_uint16 sec_len)
{
    kal_uint32  received_file_size;
    kal_int64   offset, seek_result;
    kal_int32	result;

    if (gFS_USBMS_PhoneDriveHandle<0) return KAL_FALSE;

    offset = LBA;
    offset = offset*512;

    seek_result = FS_SeekLargeFile(gFS_USBMS_PhoneDriveHandle, offset, FS_FILE_BEGIN);

    fs_ext_assert_local((seek_result>=0)&&(seek_result==offset), (kal_uint32)seek_result, (kal_uint32)gFS_USBMS_PhoneDriveHandle, (kal_uint32)offset);

    if (seek_result != offset) return KAL_FALSE;

    result = FS_Read(gFS_USBMS_PhoneDriveHandle, data, (sec_len*512), &received_file_size);

    fs_ext_assert_local(result>=0, (kal_uint32)result, (kal_uint32)gFS_USBMS_PhoneDriveHandle, 0);

    if (result<0) return KAL_FALSE;

    return KAL_TRUE;
}


static kal_bool fs_usbms_write_sysdrv(void *data, kal_uint32 LBA, kal_uint16 sec_len)
{
    kal_uint32  file_size;
    kal_int32   result;
    kal_int64   offset, seek_result;

    if (gFS_USBMS_PhoneDriveHandle<0) return KAL_FALSE;

    result = FS_GetFileSize(gFS_USBMS_PhoneDriveHandle, &file_size);

    fs_ext_assert_local(result>=0, (kal_uint32)result, (kal_uint32)gFS_USBMS_PhoneDriveHandle, 0);

    if (result<0) return KAL_FALSE;

    fs_ext_assert_local( (((LBA + sec_len)*512) <= file_size), file_size, LBA, sec_len);

    if (((LBA + sec_len)*512) > file_size) return KAL_FALSE;

    offset = LBA;
    offset = offset*512;

    seek_result = FS_SeekLargeFile(gFS_USBMS_PhoneDriveHandle, offset, FS_FILE_BEGIN);

    fs_ext_assert_local((seek_result>=0)&&(seek_result==offset), (kal_uint32)seek_result, (kal_uint32)gFS_USBMS_PhoneDriveHandle, (kal_uint32)offset);

    if (seek_result != offset) return KAL_FALSE;

    result = FS_Write(gFS_USBMS_PhoneDriveHandle, data, (sec_len*512), &file_size);

    fs_ext_assert_local(result>=0, (kal_uint32)result, (kal_uint32)gFS_USBMS_PhoneDriveHandle, 0);

    if (result<0) return KAL_FALSE;

    return KAL_TRUE;
}


static kal_bool fs_usbms_read_capacity_sysdrv(kal_uint32 *max_lba, kal_uint32 *sec_len)
{
    kal_uint32  lba = 512;
    kal_int32   result;

    if (gFS_USBMS_PhoneDriveHandle<0) return KAL_FALSE;

    *sec_len = 512;
    result = FS_GetFileSize(gFS_USBMS_PhoneDriveHandle, &lba);

    fs_ext_assert_local(result>=0, (kal_uint32)result, (kal_uint32)gFS_USBMS_PhoneDriveHandle, 0);

    if (result<0) return KAL_FALSE;

    *max_lba = (lba/512) - 1;

    return KAL_TRUE;
}

static USB_STORAGE_DEV_STATUS fs_usbms_checkmedia_exit_sysdrv(void)
{
    return USB_STORAGE_DEV_STATUS_OK;
}


static kal_bool fs_usbms_format_sysdrv()
{
    return KAL_TRUE;
}


static kal_bool fs_usbms_prevmedia_removal_sysdrv(kal_bool enable)
{
    return KAL_TRUE;
}


/*
static kal_bool fs_usbms_read_formatcapacity_sysdrv(kal_uint32 *no_of_blks, kal_uint32 *blk_len)
{
	return KAL_TRUE;
}
*/

static USB_STORAGE_DEV_TYPE fs_usbms_dev_type_sysdrv(void)
{
    RTFDevice *Dev;
    USB_STORAGE_DEV_TYPE result;

    Dev = &gFS_DeviceList[gFS_DeviceNumOfSYSDRV-1];

    if (Dev->DeviceFlags & FS_DEVICE_NOR_FLASH)  {
        result = USB_STORAGE_DEV_NOR;
    }
    else {  // (Dev->DeviceFlags & FS_DEVICE_NAND_FLASH)
        result = USB_STORAGE_DEV_NAND;
    }
    return result;
}

/* If we want to export the drive which system drive in the same disk, then we need to build this fake MS APIs to replace NOR or NAND flash APIs */
USB_DiskDriver_STRUCT USB_SYSTEM_drv =
{
    fs_usbms_read_sysdrv,
    fs_usbms_write_sysdrv,
    fs_usbms_format_sysdrv,
    fs_usbms_checkmedia_exit_sysdrv,
    fs_usbms_prevmedia_removal_sysdrv,
    fs_usbms_read_capacity_sysdrv,
//    fs_usbms_read_formatcapacity_sysdrv,
    fs_usbms_dev_type_sysdrv
};

