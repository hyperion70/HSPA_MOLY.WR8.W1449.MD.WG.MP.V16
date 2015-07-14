/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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

/*******************************************************************************
 *
 * Filename:
 * ---------
 *	flash_user.C
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This is the flash user's API
 *  Original file name is flash_int.c
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

//RHR remove #include "kal_release.h"
//RHR remove #include "fat_fs.h"
#include "DrvFlash.h"
#include "NAND_FDM.h"
//RHR remove #include "custom_MemoryDevice.h"
// Add for RHR
#include "fs_type.h"
#include "fs_iprot.h"
//RHR remove #include "kal_non_specific_general_types.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
// Add for RHR
#if ( !defined(__FS_SYSDRV_ON_NAND__) && !defined( _NAND_FLASH_BOOTING_) &&!defined(__EMMC_BOOTING__))
extern NOR_FLASH_DRV_Data  FlashDriveData;
extern FS_Driver NORFlashDriver;
	#ifdef __USB_MASS_STORAGE_ENABLE__
	static FS_Driver *CardDrv = &NORFlashDriver;
	#endif
#endif


#ifdef __USB_MASS_STORAGE_ENABLE__

#include "drv_comm.h"
#include "usb_msdisk.h"

#define FLASH_USB_ADAPT_C

#if ( !defined(__FS_SYSDRV_ON_NAND__) && !defined( _NAND_FLASH_BOOTING_) &&!defined(__EMMC_BOOTING__))
static kal_uint32 NOR_RelativeSector=0xFFFFFFFF;
static kal_bool usbms_read_capacity_nor(kal_uint32 *max_lba, kal_uint32 *sec_len)
{
   kal_int32 status;
   NOR_RelativeSector = 0;
   status = CardDrv->MountDevice((void *)(&FlashDriveData), 1, FS_DEVICE_FDISK, 0);
	if(status != 512)
		ASSERT(0);
  if(FlashDriveData.PartitionSectors!=0)
	{
	  // Calcualte the start address of the user drive
    NOR_RelativeSector  = (FlashDriveData.TotalFATSectors-1) / (256l * 1 * 1024) + 1;
    if(NOR_RelativeSector>=63)
    {
      NOR_RelativeSector = 63;
    }    	  
    // For the drive with system drive, the exported capacity is user drive size+ parition start address
		*max_lba = FlashDriveData.PartitionSectors-1;	
	}
	else
	{
		*max_lba = FlashDriveData.TotalFATSectors-1;	
	}

	*sec_len =512;

   return KAL_TRUE;
}
static kal_bool usbms_read_nor( void *data, kal_uint32 LBA, kal_uint16 sec_len)
{
	kal_int32 status;
 	if(NOR_RelativeSector==0xFFFFFFFF)
	{
		kal_uint32 tmp_max_lba,tmp_sec_len;
		usbms_read_capacity_nor(&tmp_max_lba,&tmp_sec_len);
  }
	status = CardDrv->ReadSectors((void *)(&FlashDriveData),(LBA+NOR_RelativeSector),sec_len,data);

	if(status)
		ASSERT(0);

	return KAL_TRUE;
}

static kal_bool usbms_write_nor(void *data, kal_uint32 LBA, kal_uint16 sec_len)
{
   kal_int32 status;

 	if(NOR_RelativeSector==0xFFFFFFFF)
	{
		kal_uint32 tmp_max_lba,tmp_sec_len;
		usbms_read_capacity_nor(&tmp_max_lba,&tmp_sec_len);
  }
	  status = CardDrv->WriteSectors((void *)(&FlashDriveData),(LBA+NOR_RelativeSector),sec_len,data);

	if(status)
	    ASSERT(0);

	return KAL_TRUE;
}

/*status =0(ok),1(MediaChanged),2(NoMedia)*/
static USB_STORAGE_DEV_STATUS usbms_checkmedia_exit_nor(void)
{
   return USB_STORAGE_DEV_STATUS_OK;
}

static kal_bool usbms_format_nor()
{
   CardDrv->MountDevice((void *)(&FlashDriveData), 1, FS_DEVICE_FDISK, 0);

   return KAL_TRUE;
}

static kal_bool usbms_prevmedia_removal_nor(kal_bool enable)
{
   return KAL_TRUE;
}

static USB_STORAGE_DEV_TYPE usbms_dev_type_nor(void)
{
	return USB_STORAGE_DEV_NOR;
}

#endif /* !__FS_SYSDRV_ON_NAND__ && !_NAND_FLASH_BOOTING_ */

USB_DiskDriver_STRUCT USB_NOR_drv =
{
#if ( !defined(__FS_SYSDRV_ON_NAND__) && !defined( _NAND_FLASH_BOOTING_)&&!defined(__EMMC_BOOTING__) )
	usbms_read_nor,
	usbms_write_nor,
	usbms_format_nor,
	usbms_checkmedia_exit_nor,
	usbms_prevmedia_removal_nor,
	usbms_read_capacity_nor,
//	usbms_read_formatcapacity_nor,
	usbms_dev_type_nor
#else
   0, 0, 0, 0, 0, 0, 0
#endif /* !__FS_SYSDRV_ON_NAND__ && !_NAND_FLASH_BOOTING_ */
};

#if defined(NAND_SUPPORT)
/* parameter for performance of USB mode */
kal_uint32 write_startsec_array[4];
kal_uint32 read_startsec_array[4];
kal_uint32 write_length_array[128];
kal_uint32 read_length_array[128];

kal_uint32 total_read_sector;
kal_uint32 total_write_sector;
kal_int32 total_read_time;
kal_int32 total_write_time;


#if ( defined(__NANDFDM_MULTI_INSTANCE__) && defined(__NAND_FDM_50__) )
extern NAND_FLASH_DRV_DATA  NANDFlashDriveData[];
extern const kal_uint8 NANDDiskNum;
#else	// ( defined(__NANDFDM_MULTI_INSTANCE__) && defined(__NAND_FDM_50__) )
extern NAND_FLASH_DRV_DATA  NANDFlashDriveData;
#endif  // ( defined(__NANDFDM_MULTI_INSTANCE__) && defined(__NAND_FDM_50__) )
extern FS_Driver NANDFlashDriver;
static FS_Driver *NANDCardDrv = &NANDFlashDriver;
//extern kal_int32 TMD_System_Clock;
static kal_uint32 NAND_RelativeSector=0xFFFFFFFF;
static kal_bool usbms_read_capacity_nand(kal_uint32 *max_lba, kal_uint32 *sec_len)
{
   kal_int32 status;
   NAND_RelativeSector = 0;

#if ( defined(__NANDFDM_MULTI_INSTANCE__) && defined(__NAND_FDM_50__) )
   #if defined (__NAND_SUPPORT_RAW_DISK__)
   if(NANDDiskNum>=4)
   {
      status = NANDCardDrv->MountDevice((void *)(&(NANDFlashDriveData[(NANDDiskNum-4)])), 1, FS_DEVICE_FDISK, 0);
   }
   else
   {
      status = NANDCardDrv->MountDevice((void *)(&(NANDFlashDriveData[(NANDDiskNum-1)])), 1, FS_DEVICE_FDISK, 0);
   }
   #else
   status = NANDCardDrv->MountDevice((void *)(&(NANDFlashDriveData[NANDDiskNum>1 ? (NANDDiskNum-2):(NANDDiskNum-1)])), 1, FS_DEVICE_FDISK, 0);
   #endif
#else	// ( defined(__NANDFDM_MULTI_INSTANCE__) && defined(__NAND_FDM_50__) )
   status = NANDCardDrv->MountDevice((void *)(&NANDFlashDriveData), 1, FS_DEVICE_FDISK, 0);
#endif  // ( defined(__NANDFDM_MULTI_INSTANCE__) && defined(__NAND_FDM_50__) )
	if(status != 512)
		ASSERT(0);

    if(NANDCardDrv->MountDevice != SuperAND_FDM_MountDevice)
    {
#if ( defined(__NANDFDM_MULTI_INSTANCE__) && defined(__NAND_FDM_50__) )
      #if defined (__NAND_SUPPORT_RAW_DISK__)
      if(NANDDiskNum>=4)
      {
   	    *max_lba = NANDFlashDriveData[(NANDDiskNum-4)].flash_info.total_FAT_sectors - 1;
      }
      else
      {
   	    *max_lba = NANDFlashDriveData[(NANDDiskNum-1)].flash_info.total_FAT_sectors - 1;
      }
      #else
 	    *max_lba = NANDFlashDriveData[NANDDiskNum>1 ? (NANDDiskNum-2):(NANDDiskNum-1)].flash_info.total_FAT_sectors - 1;
      #endif //defined (__NAND_SUPPORT_RAW_DISK__)
#else	// ( defined(__NANDFDM_MULTI_INSTANCE__) && defined(__NAND_FDM_50__) )
      if(NANDFlashDriveData.flash_info.partition_sectors!=0)
      {
 	      *max_lba = NANDFlashDriveData.flash_info.partition_sectors;
	      // Calcualte the start address of the user drive
        NAND_RelativeSector  = (NANDFlashDriveData.flash_info.total_FAT_sectors -1) / (256l * 1 * 1024) + 1;
        if(NAND_RelativeSector>=63)
        {
          NAND_RelativeSector = 63;
        }    	  
       // For the drive with system drive, the exported capacity is user drive size+ parition start address
		    *max_lba = NANDFlashDriveData.flash_info.partition_sectors-1;	 	      
 	    }
 	    else
 	    {
 	      *max_lba = NANDFlashDriveData.flash_info.total_FAT_sectors - 1;
 	    }
#endif	// ( defined(__NANDFDM_MULTI_INSTANCE__) && defined(__NAND_FDM_50__) )
 	}
 	else
 	{
 	    SuperAND_FLASH_DRV_DATA *D = (SuperAND_FLASH_DRV_DATA*)&NANDFlashDriveData;
 	    *max_lba = D->total_fat_sectors - 1;
 	}
	*sec_len =512;

   return KAL_TRUE;
}
static kal_bool usbms_read_nand( void *data, kal_uint32 LBA, kal_uint16 sec_len)
{
	kal_int32 status;
	kal_int32 start_time, end_time;
	if(NAND_RelativeSector==0xFFFFFFFF)
	{
		kal_uint32 tmp_max_lba,tmp_sec_len;
		usbms_read_capacity_nand(&tmp_max_lba,&tmp_sec_len);
  }

 start_time = kal_get_systicks();	
#if ( defined(__NANDFDM_MULTI_INSTANCE__) && defined(__NAND_FDM_50__) )
  #if defined(__NAND_SUPPORT_RAW_DISK__)
  if(NANDDiskNum>=4)
  {
    status = NANDCardDrv->ReadSectors((void *)(&(NANDFlashDriveData[(NANDDiskNum-4)])),LBA,sec_len,data);
  }
  else
  {
    status = NANDCardDrv->ReadSectors((void *)(&(NANDFlashDriveData[(NANDDiskNum-1)])),LBA,sec_len,data);
  }
  #else
	status = NANDCardDrv->ReadSectors((void *)(&(NANDFlashDriveData[NANDDiskNum>1 ? (NANDDiskNum-2):(NANDDiskNum-1)])),LBA,sec_len,data);
  #endif //defined(__NAND_SUPPORT_RAW_DISK__)
#else	// ( defined(__NANDFDM_MULTI_INSTANCE__) && defined(__NAND_FDM_50__) )
	status = NANDCardDrv->ReadSectors((void *)(&NANDFlashDriveData),(LBA+NAND_RelativeSector),sec_len,data);
#endif  // ( defined(__NANDFDM_MULTI_INSTANCE__) && defined(__NAND_FDM_50__) )
  end_time = kal_get_systicks();	


	if(status) ASSERT(0);

	/* record start sector and sector length for histogram statistics;
	   record total read sectors and read time for throughput test */
	read_startsec_array[(LBA%4)]++;
	if(sec_len < 128)
	  read_length_array[(sec_len-1)]++;
	else
	  read_length_array[127]++;

	total_read_sector += sec_len;
	total_read_time += (end_time - start_time);

	return KAL_TRUE;
}

static kal_bool usbms_write_nand(void *data, kal_uint32 LBA, kal_uint16 sec_len)
{
   kal_int32 status;
   kal_int32 start_time, end_time;


   //status = NANDCardDrv->WriteSectors((void *)(&NANDFlashDriveData),LBA,sec_len,data);


	if(NAND_RelativeSector==0xFFFFFFFF)
	{
		kal_uint32 tmp_max_lba,tmp_sec_len;
		usbms_read_capacity_nand(&tmp_max_lba,&tmp_sec_len);
  }
	{
	   start_time = kal_get_systicks();
#if ( defined(__NANDFDM_MULTI_INSTANCE__) && defined(__NAND_FDM_50__) )
     #if defined(__NAND_SUPPORT_RAW_DISK__)
     if(NANDDiskNum>=4)
     {
       status = NANDCardDrv->WriteSectors((void *)(&(NANDFlashDriveData[(NANDDiskNum-4)])),LBA,sec_len,data);
     }
     else
     {
       status = NANDCardDrv->WriteSectors((void *)(&(NANDFlashDriveData[(NANDDiskNum-1)])),LBA,sec_len,data);
     }
     #else
	   status = NANDCardDrv->WriteSectors((void *)(&(NANDFlashDriveData[NANDDiskNum>1 ? (NANDDiskNum-2):(NANDDiskNum-1)])),LBA,sec_len,data);
     #endif
#else	// ( defined(__NANDFDM_MULTI_INSTANCE__) && defined(__NAND_FDM_50__) )
	   status = NANDCardDrv->WriteSectors((void *)(&NANDFlashDriveData),(LBA+NAND_RelativeSector),sec_len,data);
#endif  // ( defined(__NANDFDM_MULTI_INSTANCE__) && defined(__NAND_FDM_50__) )
	   end_time = kal_get_systicks();	
	}




	if(status)
	    ASSERT(0);


	/* record start sector and sector length for histogram statistics;
	   record total write sectors and write time for throughput test */
	write_startsec_array[(LBA%4)]++;
	if(sec_len < 128)
	  write_length_array[(sec_len-1)]++;
	else
	  write_length_array[127]++;

	total_write_sector += sec_len;
	total_write_time += (end_time - start_time);


	return KAL_TRUE;
}

/*status =0(ok),1(MediaChanged),2(NoMedia)*/
static USB_STORAGE_DEV_STATUS usbms_checkmedia_exit_nand(void)
{
   return USB_STORAGE_DEV_STATUS_OK;
}

static kal_bool usbms_format_nand()
{
#if ( defined(__NANDFDM_MULTI_INSTANCE__) && defined(__NAND_FDM_50__) )
   #if defined(__NAND_SUPPORT_RAW_DISK__)
   if(NANDDiskNum>=4)
   {
     NANDCardDrv->MountDevice((void *)(&(NANDFlashDriveData[(NANDDiskNum-4)])), 1, FS_DEVICE_FDISK, 0);
   }
   else
   {
     NANDCardDrv->MountDevice((void *)(&(NANDFlashDriveData[(NANDDiskNum-1)])), 1, FS_DEVICE_FDISK, 0);
   }
   #else
   NANDCardDrv->MountDevice((void *)(&(NANDFlashDriveData[NANDDiskNum>1 ? (NANDDiskNum-2):(NANDDiskNum-1)])), 1, FS_DEVICE_FDISK, 0);
   #endif //defined(__NAND_SUPPORT_RAW_DISK__)
#else	// ( defined(__NANDFDM_MULTI_INSTANCE__) && defined(__NAND_FDM_50__) )
   NANDCardDrv->MountDevice((void *)(&NANDFlashDriveData), 1, FS_DEVICE_FDISK, 0);
#endif	// ( defined(__NANDFDM_MULTI_INSTANCE__) && defined(__NAND_FDM_50__) )

   return KAL_TRUE;
}

static kal_bool usbms_prevmedia_removal_nand(kal_bool enable)
{
   return KAL_TRUE;
}




static USB_STORAGE_DEV_TYPE usbms_dev_type_nand(void)
{
	return USB_STORAGE_DEV_NAND;
}

USB_DiskDriver_STRUCT USB_NAND_drv = {
	usbms_read_nand,
	usbms_write_nand,
	usbms_format_nand,
	usbms_checkmedia_exit_nand,
	usbms_prevmedia_removal_nand,
	usbms_read_capacity_nand,
//	usbms_read_formatcapacity_nand,
	usbms_dev_type_nand
};

#else //defined(NAND_SUPPORT)

USB_DiskDriver_STRUCT USB_NAND_drv = {
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL
};

#endif //defined(NAND_SUPPORT)

#endif /* __USB_MASS_STORAGE_ENABLE__ */


#include "flash_opt.h"

#ifdef __NOR_FDM5__

int Check_NORFlash_Formatted(void)
{
#if ( !defined(__FS_SYSDRV_ON_NAND__) && !defined( _NAND_FLASH_BOOTING_)&&!defined(__EMMC_BOOTING__) && !defined(__SMART_PHONE_PLATFORM__))

   int i;
   NORLayoutInfo *L = ((NOR_MTD_DATA *)FlashDriveData.MTDData)->LayoutInfo;
   volatile kal_uint32 *pData;
   int VirginNum = 0;


   for ( i=0;i < L->TotalBlks; i++)
   {
      pData = (volatile kal_uint32*)BlockAddress(FlashDriveData.MTDData, i);
      if (*pData == 0xffffffff) {
      	VirginNum++;
      	if (VirginNum>1) {
      		return 1; // unformatted.
      	}
      }
   }
   return 0; // formatted

#else   // The following is __FS_SYSDRV_ON_NAND__ or _NAND_FLASH_BOOTING_

   #if defined(__NAND_FDM_50__)
   return 1;
   #else
   return 0; //formatted (may false alarm!)
   #endif

#endif /* !__FS_SYSDRV_ON_NAND__ && !_NAND_FLASH_BOOTING_ */
}

#else  // __NOR_FDM5__

int Check_NORFlash_Formatted(void)
{
#if ( !defined(__FS_SYSDRV_ON_NAND__) && !defined( _NAND_FLASH_BOOTING_)&&!defined(__EMMC_BOOTING__) && !defined(__SMART_PHONE_PLATFORM__))

   int i = 0, j;
   int addr;
   NOR_Flash_MTD_Data *p = (NOR_Flash_MTD_Data *)FlashDriveData.MTDData;
   int VirginNum = 0;

   addr = (int)(p->BaseAddr);

   while(p->RegionInfo[i].BlockSize)
   {
      for(j = 0; j < p->RegionInfo[i].RegionBlocks; j++)
      {
         if(*(volatile unsigned short*)addr == 0xffff)
         {
         	VirginNum++;
         	if (VirginNum>1) {
	         	return 1;  // unformatted
         	}
            //return 0; //formatted (may false alarm!)
         }
         addr += p->RegionInfo[i].BlockSize;
      }
      i++;
   }
   return 0; // formatted

#else   // The following is __FS_SYSDRV_ON_NAND__ or _NAND_FLASH_BOOTING_

   #if defined(__NAND_FDM_50__)
   return 1;
   #else
   return 0; //formatted (may false alarm!)
   #endif

#endif /* !__FS_SYSDRV_ON_NAND__ && !_NAND_FLASH_BOOTING_ */
}

#endif   // __NOR_FDM5__
