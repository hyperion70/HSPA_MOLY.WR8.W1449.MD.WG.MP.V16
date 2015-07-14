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
 *    usbms_adap.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  This file implements usb adaption layer for mass storage
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "drv_comm.h"
//#include "gpt_sw.h"
//#include "usb_comm.h"
//#include "usb_drv.h"
#include "usb_adap.h"
//#include "usb.h"
#include "usbms_drv.h"
#include "usbms_state.h"
//#include "usbms_adap.h"
//#include "usb_custom.h"
#include "usb_trc.h"
//#include "msdc_def.h"
//#include "kal_non_specific_general_types.h"
#include "usb_msdisk.h"
//#include "kal_release.h"
#include "kal_public_api.h"
#include "kal_trace.h"
#include "kal_public_api.h"

static kal_uint8 USBMS_MAX_DISK[LOGIC_DRIVE_COUNT] = {0};
static USB_DiskDriver_STRUCT  *USBMS_DISKDRV_API[LOGIC_DRIVE_COUNT][MAX_DISK_DRVER];
static Read_Capacity_Info  USBMS_DISKDRV_LBA_INFO[MAX_DISK_DRVER];
static kal_uint32 CURRENT_DRV = LOGIC_DRIVE_MS;


/***********************************************
	adaption functions
************************************************/

static void USB_Ms_Check_CURRENT_DRV(kal_uint8 LUN)  
{
	if(USBMS_DISKDRV_API[CURRENT_DRV][LUN] == NULL)
		EXT_ASSERT(0, (kal_uint32)LUN, 0, 0);
}

#ifdef __USB_MASS_STORAGE_CDROM_ENABLE__
kal_uint8 USB_Ms_Set_Current_Driver(kal_uint32 drv)
{
	if( (drv == LOGIC_DRIVE_MS)||(drv == LOGIC_DRIVE_CDROM))
		CURRENT_DRV = drv;
	else	
		EXT_ASSERT(0, drv, 0, 0);
		
	return (USBMS_MAX_DISK[CURRENT_DRV]-1);
}

kal_uint32 USB_Ms_Get_Current_Driver(void)
{
	return CURRENT_DRV;
}
#endif //__USB_MASS_STORAGE_CDROM_ENABLE__

kal_uint8 USB_Ms_Get_Max_LUN(void)
{
	//disk number 0 means no disk register for mass storage function	
	if(USBMS_MAX_DISK[CURRENT_DRV]==0)
	{
		#ifdef __USB_MODEM_CARD_SUPPORT__
		return	USBMS_INVALID_MAX_LUN;
		#else
		EXT_ASSERT(0, (kal_uint32)USBMS_MAX_DISK[CURRENT_DRV], 0, 0);
		#endif
	}
		
	return (USBMS_MAX_DISK[CURRENT_DRV]-1);
}


kal_uint8 USB_Ms_Register_DiskDriver(USB_DiskDriver_STRUCT *disk_api)
{
	USBMS_DISKDRV_API[CURRENT_DRV][USBMS_MAX_DISK[CURRENT_DRV]] = disk_api;
	USBMS_MAX_DISK[CURRENT_DRV]++;
	
	if(USBMS_MAX_DISK[CURRENT_DRV]>=MAX_DISK_DRVER)
		EXT_ASSERT(0, (kal_uint32)USBMS_MAX_DISK[CURRENT_DRV], MAX_DISK_DRVER, 0);

	return (USBMS_MAX_DISK[CURRENT_DRV]-1);
}


#ifndef __USB_IN_NORMAL_MODE_IMPROVE__
void USB_Ms_DeRegister_DiskDriver(kal_uint8 disk_index)
{
	kal_uint8 index;

	/* disk index can not exceed max LUN, and if deregister the last LUN, zero LUN is not allowed*/
	if((disk_index>=USBMS_MAX_DISK[CURRENT_DRV]) || (USBMS_MAX_DISK[CURRENT_DRV]==1))
		EXT_ASSERT(0, (kal_uint32)disk_index, (kal_uint32)USBMS_MAX_DISK[CURRENT_DRV], 0);

	if(disk_index<(USBMS_MAX_DISK[CURRENT_DRV]-1))
	{
		for(index = disk_index; index < (USBMS_MAX_DISK[CURRENT_DRV]-1); index++)
		{
			USBMS_DISKDRV_API[CURRENT_DRV][index] = USBMS_DISKDRV_API[CURRENT_DRV][index+1];
		}
	}
	USBMS_MAX_DISK[CURRENT_DRV]--;
}
#endif

void USB_Ms_Change_Register_DiskDriver(kal_uint8 disk_index, USB_DiskDriver_STRUCT *disk_api)
{
	/* disk index can not exceed max LUN */
	if(disk_index >= USBMS_MAX_DISK[CURRENT_DRV])
		EXT_ASSERT(0, (kal_uint32)disk_index, (kal_uint32)USBMS_MAX_DISK[CURRENT_DRV], 0);

	USBMS_DISKDRV_API[CURRENT_DRV][disk_index] = disk_api;
}


USB_STORAGE_DEV_STATUS USB_Ms_Checkmedia_Exist(kal_uint8 LUN)
{
	USB_Ms_Check_CURRENT_DRV(LUN);	
	
	return USBMS_DISKDRV_API[CURRENT_DRV][LUN]->usbms_checkmedia_exist();
}


kal_bool USB_Ms_Format(kal_uint8 LUN)
{
	USB_Ms_Check_CURRENT_DRV(LUN);	
	
	return USBMS_DISKDRV_API[CURRENT_DRV][LUN]->usbms_format();
}


kal_bool USB_Ms_Read_Capacity(kal_uint8 LUN, kal_uint32 *max_lba, kal_uint32 *sec_len)
{
	kal_bool ret;
	
	USB_Ms_Check_CURRENT_DRV(LUN);	
	
	ret = USBMS_DISKDRV_API[CURRENT_DRV][LUN]->usbms_read_capacity(max_lba, sec_len);
	USBMS_DISKDRV_LBA_INFO[LUN].LastBA = *max_lba;
	USBMS_DISKDRV_LBA_INFO[LUN].BlkLen = *sec_len;
	
	return ret;
}


//kal_bool USB_Ms_Read(kal_uint8 LUN, void *data, kal_uint32 LBA, kal_uint16 sec_len)
//{
//	kal_bool ret;
//	kal_uint32 time;
//	kal_uint32 performance;
//	
//	USB_Ms_Check_CURRENT_DRV(LUN);	
//	
//	if ( (LBA+sec_len-1) > USBMS_DISKDRV_LBA_INFO[LUN].LastBA)
//		return KAL_FALSE;
//		
//	time = drv_get_current_time();
//	ret = USBMS_DISKDRV_API[CURRENT_DRV][LUN]->usbms_read(data, LBA, sec_len);
//	time = drv_get_current_time()-time;
//	if(time > 0)
//	{
//		performance = sec_len*32*1024/2/time;
//		drv_trace1(TRACE_FUNC, (kal_uint32)USBMS_READ_PERFORMANCE, performance);
//	}
//	return ret;
//}
//
//
//kal_bool USB_Ms_Write(kal_uint8 LUN, void *data, kal_uint32 LBA, kal_uint16 sec_len)
//{
//	kal_bool ret;
//	kal_uint32 time;
//	kal_uint32 performance;
//	
//	USB_Ms_Check_CURRENT_DRV(LUN);	
//	
//	if ( (LBA+sec_len-1) > USBMS_DISKDRV_LBA_INFO[LUN].LastBA)
//		return KAL_FALSE;
//		
//	time = drv_get_current_time();
//	ret = USBMS_DISKDRV_API[CURRENT_DRV][LUN]->usbms_write(data, LBA, sec_len);
//	time = drv_get_current_time()-time;
//	if(time > 0)
//	{
//		performance = sec_len*32*1024/2/time;
//		drv_trace1(TRACE_FUNC, (kal_uint32)USBMS_WRITE_PERFORMANCE, performance);
//	}
//	return ret;
//}

kal_bool USB_Ms_Read_Write(USB_MS_DIRECTION direct, kal_uint8 LUN, void *data, kal_uint32 LBA, kal_uint16 sec_len)
{
	kal_bool ret;
	kal_uint32 time;
	kal_uint32 performance;
	
	USB_Ms_Check_CURRENT_DRV(LUN);	

	if (USBMS_DISKDRV_LBA_INFO[LUN].LastBA == 0)
	{
		USBMS_DISKDRV_API[CURRENT_DRV][LUN]->usbms_read_capacity(
					&USBMS_DISKDRV_LBA_INFO[LUN].LastBA, 
					&USBMS_DISKDRV_LBA_INFO[LUN].BlkLen);
	}
	
	if ( (LBA+sec_len-1) > USBMS_DISKDRV_LBA_INFO[LUN].LastBA)
		return KAL_FALSE;
		
	time = drv_get_current_time();
	if (direct == USB_MS_WRITE)
		ret = USBMS_DISKDRV_API[CURRENT_DRV][LUN]->usbms_write(data, LBA, sec_len);
	else
		ret = USBMS_DISKDRV_API[CURRENT_DRV][LUN]->usbms_read(data, LBA, sec_len);
	time = drv_get_current_time()-time;
	if(time > 0)
	{
		performance = sec_len*32*1024/2/time;
		if (direct == USB_MS_WRITE)
			drv_trace1(TRACE_FUNC, (kal_uint32)USBMS_WRITE_PERFORMANCE, performance);
		else
			drv_trace1(TRACE_FUNC, (kal_uint32)USBMS_READ_PERFORMANCE, performance);
	}
	return ret;
}

kal_bool USB_Ms_Prevmedia_Removal(kal_uint8 LUN, kal_bool enable)
{
	USB_Ms_Check_CURRENT_DRV(LUN);	
	
	return USBMS_DISKDRV_API[CURRENT_DRV][LUN]->usbms_prevmedia_removal(enable);
}


USB_STORAGE_DEV_TYPE USB_Ms_Dev_Type(kal_uint8 LUN)
{
	USB_Ms_Check_CURRENT_DRV(LUN);	

	return USBMS_DISKDRV_API[CURRENT_DRV][LUN]->usbms_dev_type();
}

