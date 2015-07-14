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
 *    usbms_msdc.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  This file implements usb adaption layer of msdc card for mass storage
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
 *
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
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================ 
 ****************************************************************************/
#ifdef __USB_MASS_STORAGE_ENABLE__

//RHR ADD
#include "kal_general_types.h"
#include "kal_public_api.h"
//RHR REMOVE
/*
#include "kal_public_api.h" //MSBB change #include "kal_release.h"
//MSBB remove #include "kal_non_specific_general_types.h"
#include "drv_comm.h"
#include "gpt_sw.h"
#include "usb_comm.h"
#include "usb_drv.h"
#include "usb.h"
#include "usbms_drv.h"
#include "usbms_adap.h"
#include "usb_custom.h"
#include "Rtfiles.h"
#include "fat_fs.h"
#include "custom_fs.h"
*/
//RHR
#include "usb_msdisk.h"

#include "msdc_def.h"
#include "fs_type.h"

/***********************************************
	MS and SD Disk Related functions
************************************************/

//#if !defined(DCL_MSDC_INTERFACE)
#include "msdc_def.h"
//#endif

#ifdef __MSDC_MS__
	#include "ms_def.h"
	extern FS_Driver FS_MsDrv;
	FS_Driver *CardDrv = &FS_MsDrv;
#elif defined(__MSDC_MSPRO__)	
	#include "mspro_def.h"	
	FS_Driver *CardDrv = &FS_MspDrvAll;		
#elif defined(__MSDC_SD_MMC__)
	#if defined(DCL_MSDC_INTERFACE)
	#include "dcl.h"
	#else
	#include "sd_def.h"
	#endif
	extern FS_Driver FS_SdDrv;
	FS_Driver *CardDrv = &FS_SdDrv;
#endif

#if ( (defined(__MSDC_MS__)) || (defined(__MSDC_SD_MMC__)) || (defined(__MSDC_MSPRO__)) )
static kal_bool usbms_read_all(void *data, kal_uint32 LBA, kal_uint16 sec_len, kal_uint32 ID)
{
	kal_int32 status;
	ASSERT(CardDrv != NULL);
	status = CardDrv->ReadSectors((void*)ID, LBA, sec_len, data);

	if(status)
		return KAL_FALSE;

	return KAL_TRUE;
}

static kal_bool usbms_write_all(void *data, kal_uint32 LBA, kal_uint16 sec_len, kal_uint32 ID)
{
	kal_int32 status;
	ASSERT(CardDrv != NULL);
	status = CardDrv->WriteSectors((void*)ID, LBA, sec_len, data);

	if(status)
		return KAL_FALSE;

	return KAL_TRUE;
}

/*
typedef  enum{
 	USB_MS_EXIST,
 	USB_MS_CHANGED,
 	USB_MS_NOT_EXIST,
 	USB_MS_LOCKED
}USB_MS_EXIST_ENUM;
*/
/*status =0(ok),1(MediaChanged),2(NoMedia)*/

#if defined(DCL_MSDC_INTERFACE)

static USB_STORAGE_DEV_STATUS usbms_checkmedia_exist_all(kal_uint32 ID)
{
	DCL_BOOL changed = DCL_FALSE;
	DCL_HANDLE dclHandle = DCL_HANDLE_NONE;
	DCL_BOOL isCardExist = DCL_FALSE;
	DCL_BOOL isWP = DCL_FALSE;
#if defined(__MSDC_SD_MMC__)&&(defined (LIPTON_BB) ||defined(ROSEMARY_BB))
	SD_CTRL_GET_CAPACITY_T capacity;
#endif
//jinxing add for dual T-card.
#if defined(__SIM_PLUS__) || defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
	sd_select_enum sel;
	SD_CTRL_ANALOG_SWITCH_T prSwitch;
#endif

#if defined(__SIM_PLUS__) || defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
	if((MSDC_HANDLE *)ID == &MSDC_Blk[0])
   {
		sel = SD_EXT;
	}
	else
   {
#if defined(__SIM_PLUS__)
		sel = SD_SIM;
#elif defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
		sel = SD_T_CARD_2;
#endif
	}

   if(sel==SD_EXT)
	{
    dclHandle = DclSD_Open(DCL_SD, DCL_SD_FLAGS_DEVICE_CARD1|DCL_SD_FLAGS_USAGE_CMD);
	if (dclHandle == DCL_HANDLE_INVALID)
		return USB_STORAGE_DEV_STATUS_NOMEDIA;
   }
   else
   {
      #if defined(__SIM_PLUS__) || defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
      dclHandle = DclSD_Open(DCL_SD, DCL_SD_FLAGS_DEVICE_SIMPLUS|DCL_SD_FLAGS_USAGE_CMD);
      if (dclHandle == DCL_HANDLE_INVALID)
         return USB_STORAGE_DEV_STATUS_NOMEDIA;
      #else
         ASSERT(0);
      #endif
   }
   prSwitch.u4TargetInterface=sel;
   //DclSD_Control(dclHandle, SD_CTRL_CMD_ANALOG_SWITCH, (DCL_CTRL_DATA_T*)&prSwitch);
   #else
   dclHandle = DclSD_Open(DCL_SD, DCL_SD_FLAGS_DEVICE_CARD1|DCL_SD_FLAGS_USAGE_CMD);
	if (dclHandle == DCL_HANDLE_INVALID)
		return USB_STORAGE_DEV_STATUS_NOMEDIA;
#endif
//jinxing add done
	DclSD_Control(dclHandle, SD_CTRL_CMD_GET_AND_CLEAR_MEDIA_CHANGED, (DCL_CTRL_DATA_T*)&changed);
	if(changed)
	{
		//return USB_MS_CHANGED;
		DclSD_Close(dclHandle);
		return USB_STORAGE_DEV_STATUS_MEDIA_CHANGE;
	}

	DclSD_Control(dclHandle, SD_CTRL_CMD_IS_EXISTENCE, (DCL_CTRL_DATA_T*)&isCardExist);
	if (isCardExist)
	{
		#if defined(__MSDC_SD_MMC__)
		DclSD_Control(dclHandle, SD_CTRL_CMD_WRITE_PROTECTION, (DCL_CTRL_DATA_T*)&isWP);
		if(isWP)
		{		
			//return USB_MS_LOCKED;
			DclSD_Close(dclHandle);
			return USB_STORAGE_DEV_STATUS_WP;
		}
		#endif
		#if defined(__MSDC_MS__)
		if(gMS.is_wp)
		{
			//return USB_MS_LOCKED;
			return USB_STORAGE_DEV_STATUS_WP;
		}
		#endif	
		#if defined(__MSDC_MSPRO__)		
		if(gMSP.is_wp)		
		{			
			//return USB_MS_LOCKED;		
			return USB_STORAGE_DEV_STATUS_WP;
		}					
		#endif
		//return USB_MS_EXIST;

		#if defined(__MSDC_SD_MMC__)
		#if (defined (LIPTON_BB) ||defined(ROSEMARY_BB))
		// TFlash larger than 8GB is not support
		
		DclSD_Control(dclHandle, SD_CTRL_CMD_GET_CAPACITY, (DCL_CTRL_DATA_T*)&capacity);
		if (*(capacity.pu8Capacity) > ((unsigned long long)FS_MAX_DISK_SIZE*1024*1024))
		{
			DclSD_Close(dclHandle);
			return USB_STORAGE_DEV_STATUS_NOMEDIA;
		}
		#endif //(LIPTON_BB) ||defined(ROSEMARY_BB))
		#endif

		DclSD_Close(dclHandle);
		return USB_STORAGE_DEV_STATUS_OK;
	}

	DclSD_Close(dclHandle);
	//return USB_MS_NOT_EXIST;   
	return USB_STORAGE_DEV_STATUS_NOMEDIA;
}

#else

static USB_STORAGE_DEV_STATUS usbms_checkmedia_exist_all(kal_uint32 ID)
{
	kal_bool changed;

	changed = MSDC_GetMediaChanged((void*)ID);
	if(changed)
	{
		//return USB_MS_CHANGED;
		return USB_STORAGE_DEV_STATUS_MEDIA_CHANGE;
	}
		
	if(gMSDC_Handle->mIsPresent)
	{
		#if defined(__MSDC_SD_MMC__)
		if(gSD->mWPEnabled)
		{		
			//return USB_MS_LOCKED;
			return USB_STORAGE_DEV_STATUS_WP;
		}
		#endif
		#if defined(__MSDC_MS__)
		if(gMS.is_wp)
		{
			//return USB_MS_LOCKED;
			return USB_STORAGE_DEV_STATUS_WP;
		}
		#endif	
		#if defined(__MSDC_MSPRO__)		
		if(gMSP.is_wp)		
		{			
			//return USB_MS_LOCKED;		
			return USB_STORAGE_DEV_STATUS_WP;
		}					
		#endif
		//return USB_MS_EXIST;

		#if defined(__MSDC_SD_MMC__)
		#if (defined (LIPTON_BB) ||defined(ROSEMARY_BB))
		// TFlash larger than 8GB is not support
		if (gSD->mCSD.capacity > ((unsigned long long)FS_MAX_DISK_SIZE*1024*1024))
			return USB_STORAGE_DEV_STATUS_NOMEDIA;
		#endif //(LIPTON_BB) ||defined(ROSEMARY_BB))
		#endif

		return USB_STORAGE_DEV_STATUS_OK;
	}
	
	//return USB_MS_NOT_EXIST;   
	return USB_STORAGE_DEV_STATUS_NOMEDIA;
}

#endif//defined(DCL_MSDC_INTERFACE)

static kal_bool usbms_format_all(kal_uint32 ID)
{
	kal_uint32 status;
	
	ASSERT(CardDrv != NULL);
	status = CardDrv->MountDevice((void*)ID,0,0,0);
	if(status != 512)
		return KAL_FALSE;

	return KAL_TRUE;  
}

static kal_bool usbms_prevmedia_removal_all(kal_bool enable)
{
	return KAL_TRUE;
}

#if defined(DCL_MSDC_INTERFACE)

static kal_bool usbms_read_capacity_all(kal_uint32 *max_lba, kal_uint32 *sec_len, kal_uint32 ID)
{
	kal_int32 status;
	DCL_HANDLE dclHandle = DCL_HANDLE_NONE;
	SD_CTRL_GET_CAPACITY_T capacity;
//jinxing add for dual T-card.
#if defined(__SIM_PLUS__) || defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
	sd_select_enum sel;
	SD_CTRL_ANALOG_SWITCH_T prSwitch;
#endif

	ASSERT(CardDrv != NULL);
	status = CardDrv->MountDevice((void*)ID, 0, 0, 0);
	if(status != 512)
		return KAL_FALSE;

	#if defined(__MSDC_MS__)   	
		*max_lba = gMS.TotalSectors-1;   
	#elif defined(__MSDC_MSPRO__)   	
		*max_lba = gMSP.user_block*gMSP.block_size-1;   
	#elif defined(__MSDC_SD_MMC__)
	#if defined(__SIM_PLUS__) || defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
	if((MSDC_HANDLE *)ID == &MSDC_Blk[0])
   {
		sel = SD_EXT;
	}
	else
   {
#if defined(__SIM_PLUS__)
		sel = SD_SIM;
#elif defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
		sel = SD_T_CARD_2;
#endif
	}

   if(sel==SD_EXT)
	{
    	dclHandle = DclSD_Open(DCL_SD, DCL_SD_FLAGS_DEVICE_CARD1|DCL_SD_FLAGS_USAGE_CMD);
		if (dclHandle == DCL_HANDLE_INVALID)
			return KAL_FALSE;
   }
   else
   {
      #if defined(__SIM_PLUS__) || defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
      dclHandle = DclSD_Open(DCL_SD, DCL_SD_FLAGS_DEVICE_SIMPLUS|DCL_SD_FLAGS_USAGE_CMD);
      if (dclHandle == DCL_HANDLE_INVALID)
         return KAL_FALSE;
      #else
         ASSERT(0);
      #endif
   }
	prSwitch.u4TargetInterface=sel; 
   DclSD_Control(dclHandle, SD_CTRL_CMD_ANALOG_SWITCH, (DCL_CTRL_DATA_T*)&prSwitch);
   #else
   dclHandle = DclSD_Open(DCL_SD, DCL_SD_FLAGS_DEVICE_CARD1|DCL_SD_FLAGS_USAGE_CMD);
	if (dclHandle == DCL_HANDLE_INVALID)
		return KAL_FALSE;
#endif
//jinxing add done
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	
		DclSD_Control(dclHandle, SD_CTRL_CMD_GET_CAPACITY, (DCL_CTRL_DATA_T*)&capacity);
		DclSD_Close(dclHandle);
		*max_lba =(capacity.pu8Capacity)/512 -1;
	#endif
	*sec_len =512;
	return KAL_TRUE;
}

#else

static kal_bool usbms_read_capacity_all(kal_uint32 *max_lba, kal_uint32 *sec_len, kal_uint32 ID)
{
	kal_int32 status;

	ASSERT(CardDrv != NULL);
	status = CardDrv->MountDevice((void*)ID, 0, 0, 0);
	if(status != 512)
		return KAL_FALSE;

	#if defined(__MSDC_MS__)   	
		*max_lba = gMS.TotalSectors-1;   
	#elif defined(__MSDC_MSPRO__)   	
		*max_lba = gMSP.user_block*gMSP.block_size-1;   
	#elif defined(__MSDC_SD_MMC__)
		*max_lba = gSD->mCSD.capacity/512 -1;
	#endif
	*sec_len =512;
	return KAL_TRUE;
}

#endif//defined(DCL_MSDC_INTERFACE)

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
	#if defined(__MSDC_MS__)   	
/* under construction !*/
	#elif defined(__MSDC_MSPRO__)   	
/* under construction !*/
	#elif defined(__MSDC_SD_MMC__)
/* under construction !*/
	#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
static USB_STORAGE_DEV_TYPE usbms_read_dev_type_all(void)
{
	return USB_STORAGE_DEV_CARD;
}

/*---------------------------[ MSDC Externl Memory Driver ]--------------------------*/
static kal_bool usbms_read_msdc(void *data, kal_uint32 LBA, kal_uint16 sec_len)
{
	return usbms_read_all(data, LBA, sec_len, EXT_MEM_ID);
}
static kal_bool usbms_write_msdc(void *data, kal_uint32 LBA, kal_uint16 sec_len)
{
	return usbms_write_all(data, LBA, sec_len, EXT_MEM_ID);
}
static USB_STORAGE_DEV_STATUS usbms_checkmedia_exist_msdc(void)
{
	return usbms_checkmedia_exist_all(EXT_MEM_ID);
}
static kal_bool usbms_format_msdc(void)
{
	return usbms_format_all(EXT_MEM_ID);
}
static kal_bool usbms_prevmedia_removal_msdc(kal_bool enable)
{
	return usbms_prevmedia_removal_all(enable);
}
static kal_bool usbms_read_capacity_msdc(kal_uint32 *max_lba, kal_uint32 *sec_len)
{
	return usbms_read_capacity_all(max_lba, sec_len, EXT_MEM_ID);
}
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

static USB_STORAGE_DEV_TYPE usbms_read_dev_type_msdc(void)
{
	return usbms_read_dev_type_all();
}
USB_DiskDriver_STRUCT USB_MSDC_drv = 
{
	usbms_read_msdc,
	usbms_write_msdc,
	usbms_format_msdc,
	usbms_checkmedia_exist_msdc,
	usbms_prevmedia_removal_msdc,
	usbms_read_capacity_msdc,
	//usbms_read_formatcapacity_msdc,
	usbms_read_dev_type_msdc
};
/*-----------------------------------------------------------------------*/

#ifdef __SIM_PLUS__
/*---------------------------[ SIM+ Memory Driver ]--------------------------*/
static kal_bool usbms_read_simplus(void *data, kal_uint32 LBA, kal_uint16 sec_len)
{
	return usbms_read_all(data, LBA, sec_len, SIMPLUS_MEM_ID);
}
static kal_bool usbms_write_simplus(void *data, kal_uint32 LBA, kal_uint16 sec_len)
{
	return usbms_write_all(data, LBA, sec_len, SIMPLUS_MEM_ID);
}
static USB_STORAGE_DEV_STATUS usbms_checkmedia_exist_simplus(void)
{
	return usbms_checkmedia_exist_all(SIMPLUS_MEM_ID);
}
static kal_bool usbms_format_simplus(void)
{
	return usbms_format_all(SIMPLUS_MEM_ID);
}
static kal_bool usbms_prevmedia_removal_simplus(kal_bool enable)
{
	return usbms_prevmedia_removal_all(enable);
}
static kal_bool usbms_read_capacity_simplus(kal_uint32 *max_lba, kal_uint32 *sec_len)
{
	return usbms_read_capacity_all(max_lba, sec_len, SIMPLUS_MEM_ID);
}
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
static USB_STORAGE_DEV_TYPE usbms_read_dev_type_simplus(void)
{
	return usbms_read_dev_type_all();
}

USB_DiskDriver_STRUCT USB_SIMPLUS_drv = 
{
	usbms_read_simplus,
	usbms_write_simplus,
	usbms_format_simplus,
	usbms_checkmedia_exist_simplus,
	usbms_prevmedia_removal_simplus,
	usbms_read_capacity_simplus,
	//usbms_read_formatcapacity_simplus,
	usbms_read_dev_type_simplus
};

/*-----------------------------------------------------------------------*/
#endif

#if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
/*---------------------------[ SIM+ Memory Driver ]--------------------------*/
static kal_bool usbms_read_tcard_2(void *data, kal_uint32 LBA, kal_uint16 sec_len)
{
	return usbms_read_all(data, LBA, sec_len, TCARD_2_MEM_ID);
}
static kal_bool usbms_write_tcard_2(void *data, kal_uint32 LBA, kal_uint16 sec_len)
{
	return usbms_write_all(data, LBA, sec_len, TCARD_2_MEM_ID);
}
static USB_STORAGE_DEV_STATUS usbms_checkmedia_exist_tcard_2(void)
{
	return usbms_checkmedia_exist_all(TCARD_2_MEM_ID);
}
static kal_bool usbms_format_tcard_2(void)
{
	return usbms_format_all(TCARD_2_MEM_ID);
}
static kal_bool usbms_prevmedia_removal_tcard_2(kal_bool enable)
{
	return usbms_prevmedia_removal_all(enable);
}
static kal_bool usbms_read_capacity_tcard_2(kal_uint32 *max_lba, kal_uint32 *sec_len)
{
	return usbms_read_capacity_all(max_lba, sec_len, TCARD_2_MEM_ID);
}
static USB_STORAGE_DEV_TYPE usbms_read_dev_type_tcard_2(void)
{
	return usbms_read_dev_type_all();
}

USB_DiskDriver_STRUCT USB_tCard_2_drv =
{
	usbms_read_tcard_2,
	usbms_write_tcard_2,
	usbms_format_tcard_2,
	usbms_checkmedia_exist_tcard_2,
	usbms_prevmedia_removal_tcard_2,
	usbms_read_capacity_tcard_2,
	//usbms_read_formatcapacity_simplus,
	usbms_read_dev_type_tcard_2
};

/*-----------------------------------------------------------------------*/
#endif //DRV_MSDC_DUAL_TCARD_BY_SWITCH


#endif   /*__MSDC_MS__,__MSDC_SD_MMC__*/

#endif /*__USB_MASS_STORAGE_ENABLE__*/

