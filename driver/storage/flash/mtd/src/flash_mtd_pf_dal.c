/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *    flash_mtd_pf_dal.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This is flash MTD driver for parallel flash devices (for Combo Memory).
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================*/

#if defined(__COMBO_MEMORY_SUPPORT__)

#include "flash_opt.h"

#if !defined(__SERIAL_FLASH__)

#include "DrvFlash.h"
//MSBB remove #include "kal_non_specific_general_types.h"
#include "fat_fs.h"
#include "combo_flash_init.h"
#include "flash_opt.h"
#include "flash_mtd_pf_dal.h"

#include "us_timer.h"   ///< for time-logging to lsatisfy tERS requirement of Spansion WS-P in ESB
#include "flash_mtd.h"
#include "flash_mtd_internal.h"

#ifdef __NOR_FDM5__
#error "FDM5 doesn't support Combo Memory."
#endif //__NOR_FDM5__


#ifdef NOR_RESUME_SUSPEND_INTERVAL
extern kal_uint32 resume_time_g;  // to store suspend time (Qbit) to satisfy tERS
#endif


//-----------------------------------------------------------------------------
// [DAL] Page buffer program size record in init
//-----------------------------------------------------------------------------

kal_uint32 CMEM_PAGE_SIZE = 512;



//-----------------------------------------------------------------------------
// Enhancen Single Bank
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// [DAL] for Flash_ReturnReady IRQ callback function
//-----------------------------------------------------------------------------

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

//--------------------------------------------------------------------------
// Following global variables should be modified only when I-bit is disabled
//
extern kal_bool            NOR_FLASH_BUSY;
extern kal_bool            NOR_FLASH_SUSPENDED;
extern kal_uint32          gNOR_ReturnReadyBegin;
extern kal_uint32          gNOR_ReturnReadyEnd;


extern NOR_FLASH_DRV_Data  FlashDriveData;

#if defined(__FOTA_DM__)
extern kal_bool            FOTA_Flash_busy;
extern NOR_FLASH_DRV_Data  NORFlashDriveData;
#endif /* __FOTA_DM__ */

#if (defined(__TOSHIBA_TV__) || defined(__TOSHIBA_TY__))
extern void tBUSYDelay(void); //function body in flash_mtd.amd.c
#else
#define tBUSYDelay()
#endif

#if defined(__SPANSION_VS_R__) || defined(__SPANSION_WS_R__)
extern kal_bool isProgram_WVSR(void);
#endif


#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */



//-----------------------------------------------------------------------------
// [DAL] Init functions Implementatins
//-----------------------------------------------------------------------------

//the timing should sync with flash_opt.h
kal_int32 ADMUX_DAL_Init_Driver(NOR_MTD_Driver *driver, PF_MTD_Data *data, kal_uint32 baseaddr, kal_uint32 type)
{

   data->SuspendLatency = 0;
   data->ResumeInterval = 0;
   data->CMD->CMD_UnlockBlock = PF_DAL_Dev_Dummy;
   data->CMD->DYB_Lock = KAL_FALSE;


   switch (type)
   {
#if defined(NOR_FLASH_TYPE_INTEL_SERIES)
      case CMEM_NOR_CS_INTEL_SERIES:
         data->CMD->CMD_UnlockBlock = PF_DAL_Dev_UnlockBlock_INTEL;
         return ADMUX_DAL_Init_INTEL(driver, data);
#endif //NOR_FLASH_TYPE_INTEL_SERIES

#if defined(__INTEL_SIBLEY__)
      case CMEM_NOR_CS_INTEL_SIBLEY:
         data->CMD->CMD_UnlockBlock = PF_DAL_Dev_UnlockBlock_INTEL;
         CMEM_PAGE_SIZE = 1024;
         return ADMUX_DAL_Init_INTEL_SIBLEY(driver, data);
#endif //__INTEL_SIBLEY__         

#if defined(__AMD_SERIES_NOR__)
         //case CMEM_NOR_CS_RAM_DISK,
         //case CMEM_NOR_CS_SST,
         //case CMEM_NOR_CS_AMD_SERIES,
#if defined(NOR_FLASH_TYPE_SPANSION_PL_J)
      case CMEM_NOR_CS_SPANSION_PL_J:
         data->SuspendLatency = 35;
         break;
#endif
#if defined(__SPANSION_PL_N__) || defined(__SPANSION_WS_N__) || defined(__SPANSION_GL_N__)
      case CMEM_NOR_CS_SPANSION_PL_N:
      case CMEM_NOR_CS_SPANSION_WS_N:
      case CMEM_NOR_CS_SPANSION_GL_N:
         data->SuspendLatency = 20;
         break;
#endif
#if defined(__SPANSION_WS_P__)
      case CMEM_NOR_CS_SPANSION_WS_P:
         data->SuspendLatency = 40;
         data->ResumeInterval = 40;
         break;
#endif
#if defined(NOR_FLASH_TYPE_SPANSION_NS_N)
      case CMEM_NOR_CS_SPANSION_NS_N:
         data->SuspendLatency = 35;
         data->ResumeInterval = 30;
		 data->CMD->DYB_Lock = KAL_TRUE;
         break;
#endif
#if defined(NOR_FLASH_TYPE_SPANSION_NS_P)
      case CMEM_NOR_CS_SPANSION_NS_P:
         data->SuspendLatency = 20;
         data->ResumeInterval = 30;
		 data->CMD->DYB_Lock = KAL_TRUE;
         break;
#endif
#if defined(__SPANSION_NS_J__)
      case CMEM_NOR_CS_SPANSION_NS_J:
         data->CMD->CMD_UnlockBlock = PF_DAL_Dev_UnlockBlock_Spansion_NS_J;
         data->ResumeInterval = 35;
         break;
#endif
#if defined(__TOSHIBA_TV__) || defined(__TOSHIBA_TY__)
      case CMEM_NOR_CS_TOSHIBA_TV:
      case CMEM_NOR_CS_TOSHIBA_TY:
         return ADMUX_DAL_Init_TOSHIBA(driver, data);
#endif
#if defined(__SAMSUNG_SPANSION_NS_J_LIKE__)
      case CMEM_NOR_CS_SAMSUNG_SPANSION_NS_J_LIKE:
         data->CMD->CMD_UnlockBlock = PF_DAL_Dev_UnlockBlock_Samsung_Spansion_NS_J_Like;

         data->SuspendLatency = 20;
         data->ResumeInterval = 30;
         break;
#endif
#if defined(__SPANSION_VS_R__) || defined(__SPANSION_WS_R__)
      case CMEM_NOR_CS_SPANSION_VS_R:
      case CMEM_NOR_CS_SPANSION_WS_R:
         data->SuspendLatency = 30;
         data->ResumeInterval = 30;

         return ADMUX_DAL_Init_WVSR(driver, data);
#endif
#if defined(__SPANSION_VS_R64__)
      case CMEM_NOR_CS_SPANSION_VS_R64:
         data->SuspendLatency = 30;
		 data->CMD->DYB_Lock = KAL_TRUE;		 
         break;
#endif
      default:
         // default AMD series
         //NOR_FLASH_TYPE_TOSHIBA
         break;

#endif // __AMD_SERIES_NOR__

// Define neither INTEL nor AMD series, ASSERT
#if !(defined(__AMD_SERIES_NOR__) || defined(__INTEL_SERIES_NOR__))
      default:
         ASSERT(0);
         break;
#endif // __AMD_SERIES_NOR__

   }

#if defined(__AMD_SERIES_NOR_PROGRAM__)
   return ADMUX_DAL_Init_AMD(driver, data);
#endif

   return CMEM_ERR_MTD_INIT_FAIL;

}




#ifndef __NOR_FDM5__


#if defined(__SPANSION_NS_J__) || defined(__SAMSUNG_SPANSION_NS_J_LIKE__) || defined(__INTEL_SERIES_NOR__)
#define __FLASH_DEFAULT_LOCKED__
#endif

int PF_DAL_MountDevice(void * DriveData, void *Info)
{
   NOR_MTD_FlashInfo * FlashInfo=Info;
   PF_MTD_Data * D = DriveData;
   kal_uint32 i, MaxBlockSize = 0;

#if defined(__FLASH_DEFAULT_LOCKED__)
   kal_uint32 block;
   volatile FLASH_CELL * fp;
#endif
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) && defined(__MULTI_BANK_NOR_DEVICE__)
   kal_uint32 TotalSize_Block = 0;
//   kal_uint32 TotalSize_Bank = 0;
#endif
#if defined(__FOTA_DM__)
   kal_uint32 start_blk = 0;
   kal_uint32 end_blk = 0;
#endif   /* __FOTA_DM__ */

   i = 0;
   FlashInfo->TotalBlocks = 0;
   while(D->RegionInfo[i].BlockSize != 0)
   {
      FlashInfo->BlockSize[i] = D->RegionInfo[i].BlockSize;
      FlashInfo->RegionBlocks[i] = D->RegionInfo[i].RegionBlocks;
      FlashInfo->TotalBlocks += D->RegionInfo[i].RegionBlocks;
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) && defined(__MULTI_BANK_NOR_DEVICE__)
      TotalSize_Block += D->RegionInfo[i].BlockSize * D->RegionInfo[i].RegionBlocks;
#endif

      if(D->RegionInfo[i].BlockSize > MaxBlockSize)
         MaxBlockSize = D->RegionInfo[i].BlockSize;
      i++;
   }
   FlashInfo->ActualRegionNum = i;
   FlashInfo->PageSize = CMEM_PAGE_SIZE;

#if defined(__FLASH_DEFAULT_LOCKED__)
   /* In some NOR flash, all blocks are protected on power up. We unprotect them here. */

#if defined(__FOTA_DM__)
   // unlock all FOTA reserved blocks in MAUI, unlock all blocks except for FUE block in FUE
   if( (FlashInfo->baseUnlockBlock != INVALID_BLOCK_INDEX) && (FlashInfo->endUnlockBlock != INVALID_BLOCK_INDEX) )
   {
      start_blk = FlashInfo->baseUnlockBlock;
      end_blk = FlashInfo->endUnlockBlock;
   }
   else
   {
      start_blk = 0;
      end_blk = FlashInfo->TotalBlocks;
   }
   for(block = start_blk; block < end_blk; block++)
#else  /* !__FOTA_DM__ */
   // unlock all FS blocks in MAUI
   for(block = 0; block < FlashInfo->TotalBlocks; block++)
#endif /* __FOTA_DM__ */
   {
      D->CurrAddr = BlockAddress(D, block);
      fp = (volatile FLASH_CELL *) D->CurrAddr;

      D->CMD->CMD_UnlockBlock(fp);

   }
#endif //__FLASH_DEFAULT_LOCKED__

#if ( defined(__NOR_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) ) && defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   insertTestLISR();
#endif

   return FS_NO_ERROR;
}




/*******************************************************************//**
 * Shutdown NOR flash device
 *
 * @par Category:
 * NOR MTD (NOR FDM 4.0 for Combo memory support, General)
 *
 * @param[in] DriveData       NOR flash MTD data
 *
 * @remarks
 * This function must be placed on RAM because flash may be busy/resumed inside!
 **********************************************************************/

int PF_DAL_ShutDown(void * DriveData)
{
   PF_MTD_Data  *D = DriveData;
   volatile FLASH_CELL *fp = (volatile FLASH_CELL*)D->CurrAddr;
   FLASH_CELL		  status;
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   kal_uint32		  saved_mask;
#endif  /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */


   while(1)
   {
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
      saved_mask = SaveAndSetIRQMask();

      // if NOR_FLASH_SUSPEND is TRUE, NOR_FLASH_BUSY should be also TRUE!
      if(NOR_FLASH_SUSPENDED)
      {
         fp[0] = D->CMD->Resume; /* resume suspended erase operation */
         NOR_FLASH_SUSPENDED = KAL_FALSE;

         gNOR_ReturnReadyEnd = NOR_DEFAULT_RETURN_READY_LATENCY;

#ifdef NOR_RESUME_SUSPEND_INTERVAL
         resume_time_g = ust_get_current_time();  // get suspend time to guarantee tERS
#endif

         tBUSYDelay();
      }
#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

      status = D->CMD->CMD_ReadStatus(fp);

      // Flash ready, break loop
      // (AMD Series) Flash timeout, reset flash and break loop
      if(status & ((PF_Status*)D->StatusMap)[PF_SR_READY])
      {
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
         NOR_FLASH_BUSY = KAL_FALSE;
         RestoreIRQMask(saved_mask);
#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

         break;
      }

      //Flash busy, loop to read status again
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
      RestoreIRQMask(saved_mask);
#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */
   }

   D->CurrAddr = NULL;

   return FS_NO_ERROR;
}


#endif // !__NOR_FDM5__



/*-----------------------------------*/
// In FUE environment, no need to wait flash to become ready
#if !(defined(__FUE__) || defined(__UBL__) || defined(__EXT_BOOTLOADER__))

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)



#ifdef __SINGLE_BANK_NOR_FLASH_SUPPORT_PRAGMA__
#pragma arm section code = "SNORCODE"
#endif

// The below function is only invoked by MAUI, should not linked in bootloader

/*******************************************************************//**
 * Issue suspend command and wait until flash is suspended
 *
 * @par Category:
 * NOR MTD (Enhanced Single Bank)
 *
 * @par Change Log:
 * 2008-11-20: Add Spansion WSP support: wait awhile to satisfy tERS before issue suspend
 *             command, then wait another 40us to satisfy tESL before polling.
 * 2008-11-27: Modify Spansion WSP support to general tESL and tERS support for all Spansion NOR flash.
 *
 * @note
 * Only called by Flash_ReturnReady
 **********************************************************************/
static void waitReady(volatile FLASH_CELL *flash_base) /* instruction prefetch should be disabled */
{
   /*----------------------------------------------------------------
    * Local Variables
    *----------------------------------------------------------------*/

   static kal_uint16 status;

#ifdef NOR_RESUME_SUSPEND_INTERVAL
   kal_uint32        resume_to_suspend_duration;
#endif

   PF_MTD_Data  *mtd_data = NULL;

#if defined(__FOTA_DM__)
   if(FOTA_Flash_busy)
   {
      mtd_data = (PF_MTD_Data *)NORFlashDriveData.MTDData;
   }
   else
#endif   /* __FOTA_DM__ */
   {
      mtd_data = (PF_MTD_Data *)FlashDriveData.MTDData;
   }


   /*----------------------------------------------------------------
    * Code Body
    *----------------------------------------------------------------*/

#ifdef NOR_RESUME_SUSPEND_INTERVAL

   /* if flash was ever resumed */
   if (resume_time_g != NOR_DEFAULT_RESUME_TIME)
   {
      /* get current time */
      resume_to_suspend_duration = ust_get_current_time();

      /* calculate duration from last resume */
      resume_to_suspend_duration = ust_qbit_to_us(ust_get_duration(resume_time_g, resume_to_suspend_duration));

      /* wait awhile to satisfy timing requirement (tERS) */
      if (resume_to_suspend_duration < mtd_data->ResumeInterval)
      {
         DelayAWhile_UST(mtd_data->ResumeInterval - resume_to_suspend_duration);
      }

      /* reset resume_time_g */
      resume_time_g = NOR_DEFAULT_RESUME_TIME;
   }

#endif   /* NOR_RESUME_SUSPEND_INTERVAL */

   /* issue suspend command */
#if defined(__SPANSION_VS_R__) || defined(__SPANSION_WS_R__)   
   //ensure the unlock address
   flash_base = (volatile FLASH_CELL *)((kal_uint32)flash_base & (ADDR_UNLOCK_MASK<<1) | (ADDR_UNLOCK_1<<1)); 

   if(isProgram_WVSR())
   {
      flash_base[0] = WVSR_CMD_PROGRAM_SUSPEND;
   }
   else
#endif //__SPANSION_VS_R__ || __SPANSION_WS_R__
   {
      flash_base[0] = mtd_data->CMD->Suspend;
   }



   /*---------------------------------------------------------------------
    * Spansion NOR flash requires tESL delay before starting to polling status bits.
    * !TODO: If DQ6 fails, the polling mechanism here needs to be changed! (ex. WS256P)
    * !CHALLENGE: We can't distinguish it's program suspend or erase suspend!
    * (a flag may be used to get such infomation)
    *---------------------------------------------------------------------*/

#ifdef NOR_SUSPEND_LATENCY
   DelayAWhile_UST(mtd_data->SuspendLatency);
#else
#ifdef __AMD_SERIES_NOR__
   DelayAWhile_UST(5);
#endif //__AMD_SERIES_NOR__
#endif //NOR_SUSPEND_LATENCY

   // polling until flash ready

   while(1)
   {

      status = mtd_data->CMD->CMD_ReadStatus(flash_base);
      if(status & ((PF_Status*)mtd_data->StatusMap)[PF_SR_READY])
         break;
      }

   NOR_FLASH_SUSPENDED = KAL_TRUE;

}


/*******************************************************************//**
 * Let flash return to ready status when an interrupt comes
 *
 * @par Category:
 * NOR MTD (Enhanced Single Bank)
 **********************************************************************/
void Flash_ReturnReady(void)
{
   PF_MTD_Data     *mtd_data    = NULL;
   static FLASH_CELL       status;
   volatile FLASH_CELL    *check_ptr    = NULL;
   volatile kal_uint16     result;

#if defined(__FOTA_DM__)
   if(FOTA_Flash_busy)
   {
      mtd_data = (PF_MTD_Data *)NORFlashDriveData.MTDData;
   }
   else
#endif /* !__FOTA_DM__ */
   {
      mtd_data = (PF_MTD_Data *)FlashDriveData.MTDData;
   }


#if defined(__MULTI_BANK_NOR_DEVICE__)
   check_ptr = (volatile kal_uint16*)mtd_data->CurrPollAddr;
#else
   check_ptr = (volatile kal_uint16*)mtd_data->BaseAddr;
#endif //__MULTI_BANK_NOR_DEVICE__

   ASSERT(~(mtd_data->Signature) == ((kal_uint32)mtd_data->RegionInfo));

   if((!NOR_FLASH_SUSPENDED) && NOR_FLASH_BUSY)
   {
      gNOR_ReturnReadyBegin = ust_get_current_time();  // get start time of Flash_ReturnReady (only when flash is busy)

      status = mtd_data->CMD->CMD_ReadStatus(check_ptr);

      if(!(status & ((PF_Status*)mtd_data->StatusMap)[PF_SR_READY]))
      {
         waitReady(check_ptr);
      }
      else
      {
         NOR_FLASH_BUSY = KAL_FALSE;
      }

      gNOR_ReturnReadyEnd = ust_get_current_time();   // get end time of Flash_ReturnReady

   }
}


#endif   /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT_PRAGMA__)
#pragma arm section code
#endif
#endif   // !__FUE__ && !__UBL__ && !__EXT_BOOTLOADER__

#ifdef __SINGLE_BANK_NOR_FLASH_SUPPORT_PRAGMA__
#pragma arm section code = "SNORCODE"
#endif

#ifdef __NOR_FULL_DRIVER_PRAGMA__
#pragma arm section code = "INTERNCODE"
#endif




/*******************************************************************//**
 * Suspend erasing block
 *
 * @par Category:
 * NOR MTD (Multibank)
 *
 * @remarks
 * This function is NOT allowed to use for program suspend! Because this function will
 * use polling to check if flash is suspended. However program-suspended block is not
 * allowed to read!
 *
 * @note
 * Only used by NOR(SIB)_ReadSectors
 **********************************************************************/
int PF_DAL_SuspendErase(void * DriveData, kal_uint32 BlockIndex)
{
#ifdef NOR_RESUME_SUSPEND_INTERVAL
   kal_uint32 resume_to_suspend_duration;
#endif
   kal_uint16 status;

#ifndef __NOR_FDM5__
   PF_MTD_Data * D = DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *) D->CurrAddr;
   kal_uint32 savedMask;
#else
   NOR_MTD_DATA *D= DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *)BlockAddress(D,BlockIndex);
#endif

#if (defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__))
   //This function is not used in ESB, place assert chech whether ESB use the function abnormally
   ASSERT(0);
#endif

#ifdef NOR_RESUME_SUSPEND_INTERVAL
   /*******************************************************************//**
    * Disable interrupt to let resume_time_g be correct.
    * !NOTE: This delay in ESB/LCSB may cause 60-qbit assert! (Now ESB will not use this function)
    **********************************************************************/

   /* if flash was ever resumed */
   if (resume_time_g != NOR_DEFAULT_RESUME_TIME)
   {
      /* get current time */
      resume_to_suspend_duration = ust_get_current_time();

      /* calculate duration from last resume */
      resume_to_suspend_duration = ust_qbit_to_us(ust_get_duration(resume_time_g, resume_to_suspend_duration));

      /* wait awhile to satisfy timing requirement (tERS) */
      if (resume_to_suspend_duration < D->ResumeInterval)
      {
         DelayAWhile_UST(D->ResumeInterval - resume_to_suspend_duration);
      }

      /* reset resume_time_g */
      resume_time_g = NOR_DEFAULT_RESUME_TIME;
   }

#endif   /* NOR_RESUME_SUSPEND_INTERVAL */

   fp[0]     = D->CMD->Suspend;

   /*******************************************************************//**
    * Spansion NOR flash requires tESL delay before starting to polling status bits.
    * !NOTE: This delay in ESB/LCSB may cause 60-qbit assert! (Now ESB will not use this function)
    **********************************************************************/

#ifdef NOR_SUSPEND_LATENCY
   DelayAWhile_UST(D->SuspendLatency);
#endif

   // AMD: polling DQ7. If block is erasing, DQ7 = 0, if block is erase-suspended, DQ7 = 1
   //while(!(s & POLL_BUSY))

   while(1)
   {
      savedMask = SaveAndSetIRQMask();
      status = D->CMD->CMD_ReadStatus(fp);
      RestoreIRQMask(savedMask);      

      if(status & ((PF_Status*)D->StatusMap)[PF_SR_READY])
      {
         break; //Flash Ready
      }
   }

//   BLTest(2);  // Do exception simulation randomly after flash is suspended.

   return FS_NO_ERROR;
}


/*******************************************************************//**
 * Resume suspended operation
 *
 * @par Category:
 * NOR MTD (MuiltiBank)
 *
 * @caller
 * FDM ReadSectors function
 **********************************************************************/
int PF_DAL_ResumeErase(void * DriveData, kal_uint32 BlockIndex)
{
   kal_uint32 savedMask;
#ifndef __NOR_FDM5__
   PF_MTD_Data  *D  = DriveData;
   volatile FLASH_CELL *fp = (volatile FLASH_CELL *) D->CurrAddr;
#else  /* __NOR_FDM5__ */
   NOR_MTD_DATA *D= DriveData;
   volatile FLASH_CELL *fp = (volatile FLASH_CELL *)BlockAddress(D, BlockIndex);
#endif /* !__NOR_FDM5__ */


   //Do not use ResumeErase function in ESB
#if (defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__))
   ASSERT(0);
#endif

   savedMask = SaveAndSetIRQMask();         // Disable interrupt to let NOR_FLASH_SUSPENDED and resume_time_g be correct.

   fp[0]     = D->CMD->Resume;

#ifdef NOR_RESUME_SUSPEND_INTERVAL
   resume_time_g = ust_get_current_time();  // get suspend time to guarantee tERS
#endif

// Not need to delay in MB setting
//   tBUSYDelay();

   RestoreIRQMask(savedMask);

   return FS_NO_ERROR;
}


//-----------------------------------------------------------------------------
// [DAL] MTD Internal Functions - Unlock Block
//-----------------------------------------------------------------------------

#if defined(__SPANSION_NS_J__)
void PF_DAL_Dev_UnlockBlock_Spansion_NS_J(volatile FLASH_CELL * fp)

{
   kal_uint32 savedMask;
   kal_uint32 data_cache_id;

   savedMask = SaveAndSetIRQMask();
   data_cache_id = INT_DisableDataCache();

   /* enter block protection/unprotection command sequence */
   fp[0] = 0x60;
   fp[0] = 0x60;

   *(kal_uint16*)(((kal_uint32)fp) | 0x80)  = 0x60;

   /* exit block protection/unprotection command sequence (by reset command) */
   fp[0] = 0xF0;

   INT_RestoreDataCache(data_cache_id);
   RestoreIRQMask(savedMask);

}
#endif //__SPANSION_NS_J__

#if defined(__SAMSUNG_SPANSION_NS_J_LIKE__)
void PF_DAL_Dev_UnlockBlock_Samsung_Spansion_NS_J_Like(volatile FLASH_CELL * fp)

{
   kal_uint32 savedMask;
   kal_uint32 data_cache_id;

   savedMask = SaveAndSetIRQMask();
   data_cache_id = INT_DisableDataCache();

   /* enter block protection/unprotection command sequence */
   fp[0] = 0x60;
   fp[0] = 0x60;

   *(kal_uint16*)(((kal_uint32)fp) | 0x84)  = 0x60;

   /* exit block protection/unprotection command sequence (by reset command) */
   fp[0] = 0xF0;

   INT_RestoreDataCache(data_cache_id);
   RestoreIRQMask(savedMask);

}
#endif //__SAMSUNG_SPANSION_NS_J_LIKE__

#if defined(__INTEL_SERIES_NOR__)
void PF_DAL_Dev_UnlockBlock_INTEL(volatile FLASH_CELL * fp)

{
   kal_uint32 savedMask;
   kal_uint32 data_cache_id;

   savedMask = SaveAndSetIRQMask();
   data_cache_id = INT_DisableDataCache();

   //UNLOCK_COMMAND
   fp[0] = INTEL_CMD_LOCK_SETUP;
   fp[0] = INTEL_CMD_UNLOCK;

   fp[0] = INTEL_CMD_RD_ID;
   if( fp[2] & INTEL_BLOCK_LOCK_FLAG)
      ASSERT(0);
   fp[0] = INTEL_CMD_RD_ARRAY;

   INT_RestoreDataCache(data_cache_id);
   RestoreIRQMask(savedMask);

}
#endif //__INTEL_SERIES_NOR__


void PF_DAL_Dev_Dummy(volatile FLASH_CELL * fp)
{
   ;
}


//-----------------------------------------------------------------------------
// [DAL] MTD Internal Functions - Read Status
//-----------------------------------------------------------------------------
// Remark: IRQ should be disable before invoke the function
// Caller: Flash_ReturnReady, waitReady, PF_DAL_SuspendErase


FLASH_CELL PF_DAL_Dev_ReadStatus_INTEL(volatile FLASH_CELL *fp)
{
   kal_uint32 data_cache_id;

   kal_uint16 result;

   data_cache_id = INT_DisableDataCache();

   fp[0] = INTEL_CMD_RD_SR;
   result = fp[0];
   fp[0] = INTEL_CMD_RD_ARRAY;

   INT_RestoreDataCache(data_cache_id);

   return result;
}


// if the 0xFF(INTEL_CMD_RD_ARRAY) command is no inpect on WVSR flash, the code of INTEL and WVSR can be merge
FLASH_CELL PF_DAL_Dev_ReadStatus_WVSR(volatile FLASH_CELL *fp)
{
   kal_uint32 data_cache_id;

   kal_uint16 result;

   data_cache_id = INT_DisableDataCache();


   fp = (volatile FLASH_CELL *)((kal_uint32)fp & (ADDR_UNLOCK_MASK<<1)); 

   fp[ADDR_UNLOCK_1] = WVSR_CMD_RD_SR;
   result = fp[0];
   // VSR flash automaticly reset to array mode after read status

   INT_RestoreDataCache(data_cache_id);

   return result;

}

//set DQ6 to indicat flash ready (DQ6 = 1, flash ready)
FLASH_CELL PF_DAL_Dev_ReadStatus_AMD(volatile FLASH_CELL *fp)
{
   kal_uint32 data_cache_id;
   kal_uint16 result=TOGGLE_BUSY,result1,result2;

   data_cache_id = INT_DisableDataCache();

   result1 = fp[0];
   result2 = fp[0];

   // set DQ6 to 0 (Busy Bit) if DQ6 is toggle
   if((result1 ^ result2) & TOGGLE_BUSY)
   {
      result &= ~TOGGLE_BUSY;
   }

   if(result2 & POLL_TIMEOUT)
   {
      //Time out bit is only valid when DQ6 is toggle
      result1 = fp[0];
      result2 = fp[0];
      if((result1 ^ result2) & TOGGLE_BUSY)
      {
         // reset flash
         fp[0] = CMD_RESET;
      }
	  // flash ready, or  flash time out
	  result |= TOGGLE_BUSY;
   }


   // flash not busy, flash erase suspend
   if((result1^ result2) & TOGGLE_ERASE_SUSPEND)
   {
      result |= TOGGLE_ERASE_SUSPEND;
      result |= TOGGLE_BUSY;
   }

   INT_RestoreDataCache(data_cache_id);

   return result;
}




#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT_PRAGMA__) || defined(__NOR_FULL_DRIVER_PRAGMA__)
#pragma arm section code
#endif

#endif// __SERIAL_FLASH__

#endif //__COMBO_MEMORY_SUPPORT__                                                                                                                                      
