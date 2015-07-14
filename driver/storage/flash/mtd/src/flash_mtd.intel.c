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
 *    flash_mtd.intel.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This is flash MTD driver for INTEL series devices.
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
 *============================================================================*/

/********************************************************/
/*                  Include Header Files                */
/********************************************************/
#include "DrvFlash.h"
#include "fs_errcode.h"

#include "flash_opt.h"
#include "flash_mtd.h"
#include "flash_mtd_internal.h"
#include "reg_base.h"
#include "us_timer.h"
#include "nor_profile.h"
#include "kal_general_types.h"
#include "kal_public_api.h"

#include "combo_flash_init.h"
#include "flash_mtd_pf_dal.h"

#include "flash_mtd_ut.h"

extern kal_uint32 INT_GetCurrentTime(void);
extern kal_bool INT_QueryExceptionStatus(void);

#if defined(__BASIC_LOAD_FLASH_TEST__)
void NORTEST_Reset(void);
extern char text[100];
extern kal_uint8 RandomNum;
extern kal_uint32 ProgramNum, EraseNum;
extern kal_uint8 PLTestOption;	// 0: Random reset    1: reset only in flash busy time.
extern kal_uint32 ResetTimeout;

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
void NORTestLISR(void);
void triggerTestIRQ(void);
#define BLTest(Num) \
	{\
		if (RandomNum == Num) {\
			if (PLTestOption==0) { \
				RandomNum = (RandomNum+1) % 5;\
				triggerTestIRQ();\
			} else { \
				if (ResetTimeout==0) {\
					if (RandomNum & 0x01) { \
						NORTEST_Reset();\
					} else { \
						triggerTestIRQ();\
					} \
				} else {\
					ResetTimeout--;\
					RandomNum = (RandomNum+1) % 5;\
					triggerTestIRQ();\
				}\
			}\
		}\
	}
#else  /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */
#define BLTest(Num) \
   {\
      if (RandomNum == Num)\
      {\
         if (PLTestOption == 1)\
         {\
            if (ResetTimeout==0) {\
       	       NORTEST_Reset();\
            } else {\
               ResetTimeout--;\
               RandomNum = (RandomNum+1) % 5;\
            }\
         }\
      }\
   }
#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

#else  // __BASIC_LOAD_FLASH_TEST__

#if defined(__FUE_STRESS_TEST__) && defined(__FUE__)

#include "fue_init.h"

extern void NORTEST_Delay_us(kal_uint32 count);
extern void NORTEST_Delay_30us(kal_uint32 count);
extern void NORTEST_Reset(void);
extern kal_uint8 RandomNum;
extern kal_uint8 PLTestOption;

#define triggerTestIRQ()

#define BLTest(Num) \
	{\
		kal_uint32 val = rand();\
		val += (*(volatile kal_uint32*)(COUNTER_32K))^(*(volatile kal_uint16 *)(TDMA_base + 0x00));\
		if (3 == Num) {\
			if (PLTestOption==0) { \
				if( (RandomNum & 0x7) == 3)\
					triggerTestIRQ();\
			} else { \
				if ( (RandomNum & 0xF) == 7) {\
					val %= 2100;\
					NORTEST_Delay_us(val);\
					NORTEST_Reset();\
				} else if((RandomNum & 0xF) == 3){\
					triggerTestIRQ();\
				}\
			}\
		}\
		else if(0 == Num) {\
			if (PLTestOption==0) { \
				if( (RandomNum & 0x3) == 3)\
					triggerTestIRQ();\
			} else { \
				if ( (RandomNum & 0x7) == 7) {\
					val %= 1500000;\
					if(val<60)\
						val = 60;\
					NORTEST_Delay_30us(val/30);\
					NORTEST_Reset();\
				} else if((RandomNum & 0x7) == 3){\
					triggerTestIRQ();\
				}\
			}\
		}\
	}

#else    /* !(__FUE_STRESS_TEST__ && __FUE__) */
#define BLTest(Num)
#endif   /* __FUE_STRESS_TEST__ && __FUE__ */
#endif   // __BASIC_LOAD_FLASH_TEST__

#ifdef __INTEL_SERIES_NOR__

/* ************************************************************
         INTEL NOR FLASH MTD Flash Driver
   ************************************************************ */

#define UNLOCK_COMMAND(a) \
           {\
              fp[a] = INTEL_CMD_LOCK_SETUP;\
              fp[a] = INTEL_CMD_UNLOCK;\
              fp[a] = INTEL_CMD_RD_ARRAY;}

#define LOCK_COMMAND(a) \
           {\
              fp[a] = INTEL_CMD_LOCK_SETUP;\
              fp[a] = INTEL_CMD_LOCK;\
              fp[a] = INTEL_CMD_RD_ARRAY;}

/* Support INTEL-series Page Buffer Program */
#ifdef __PAGE_BUFFER_PROGRAM__
   extern kal_uint32 PAGE_BUFFER_SIZE;
#endif

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

extern kal_bool            NOR_FLASH_BUSY; /*should be modified only when I-bit is disabled*/
extern kal_bool            NOR_FLASH_SUSPENDED; /*should be modified only when I-bit is disabled*/
extern kal_uint32          gNOR_ReturnReadyBegin;
extern kal_uint32          gNOR_ReturnReadyEnd;

#if defined(__FOTA_DM__)
   extern kal_bool            FOTA_Flash_busy;
   extern NOR_FLASH_DRV_Data  NORFlashDriveData;
#endif   /* __FOTA_DM__ */

#endif   /*__SINGLE_BANK_NOR_FLASH_SUPPORT__*/


static int CheckDeviceReady_INTEL(void * DriveData, kal_uint32 BlockIndex);


#ifndef __NOR_FDM5__
#ifndef __COMBO_MEMORY_SUPPORT__
__nor_section_RAM static int MountDevice_INTEL(void * DriveData,void *Info )
{
   NOR_MTD_FlashInfo * FlashInfo=Info;
   NOR_Flash_MTD_Data * D = DriveData;
   kal_uint32 i=0;
   // for unlock block
   kal_uint32 block;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *) D->CurrAddr;
   kal_uint32 savedMask;
   kal_uint32 data_cache_id;
   #if (defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) && (defined( __MULTI_BANK_NOR_DEVICE__) || defined(__ARM9_MMU__) || defined(__ARM11_MMU__)))
   kal_uint32 TotalSize_Block = 0;
//   kal_uint32 TotalSize_Bank = 0;
   #endif   /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ && (__MULTI_BANK_NOR_DEVICE__ || __ARM9_MMU__ || __ARM11_MMU__) */
   #if defined(__FOTA_DM__)
   kal_uint32 start_blk = 0;
   kal_uint32 end_blk = 0;
   #endif   /* __FOTA_DM__ */


   FlashInfo->TotalBlocks = 0;
   while(D->RegionInfo[i].BlockSize != 0)
   {
      FlashInfo->BlockSize[i] = D->RegionInfo[i].BlockSize;
      FlashInfo->RegionBlocks[i] = D->RegionInfo[i].RegionBlocks;
      FlashInfo->TotalBlocks += D->RegionInfo[i].RegionBlocks;
      #if (defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) && (defined( __MULTI_BANK_NOR_DEVICE__) || defined(__ARM9_MMU__) || defined(__ARM11_MMU__)))
      TotalSize_Block += D->RegionInfo[i].BlockSize * D->RegionInfo[i].RegionBlocks;
      #endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ && (__MULTI_BANK_NOR_DEVICE__ || __ARM9_MMU__ || __ARM11_MMU__) */
      i++;
   }
   FlashInfo->ActualRegionNum = i;

   #ifndef __INTEL_SIBLEY__
	FlashInfo->PageSize = 512;
   #else
	FlashInfo->PageSize = 1024;
   #endif

   #if (defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) && (defined( __MULTI_BANK_NOR_DEVICE__) || defined(__ARM9_MMU__) || defined(__ARM11_MMU__)))

   /*check customization */

   // TODO: check the part
   // CL_Add 2.21
   //disable for raw disk support
   //i=0;
   //while(D->BankInfo[i].BankSize != 0)
   //{
   //   TotalSize_Bank += D->BankInfo[i].BankSize * D->BankInfo[i].Banks;
   //   i++;
   //}
   //EXT_ASSERT(TotalSize_Bank==TotalSize_Block,0,0,0);
   // CL_Add

   #endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ && (__MULTI_BANK_NOR_DEVICE__ || __ARM9_MMU__ || __ARM11_MMU__) */

   waitNonBlockEraseDone();

   // unlock all blocks
   #if defined(__FOTA_DM__)
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
   for(block = 0; block < FlashInfo->TotalBlocks; block++)
   #endif /* __FOTA_DM__ */
   {
      D->CurrAddr = BlockAddress(D, block);
      fp = (volatile FLASH_CELL *) D->CurrAddr;

      savedMask = SaveAndSetIRQMask();
      data_cache_id = INT_DisableDataCache();
      UNLOCK_COMMAND(0)
      fp[0] = INTEL_CMD_RD_ID;
      if( fp[2] & INTEL_BLOCK_LOCK_FLAG)
         ASSERT(0);
      fp[0] = INTEL_CMD_RD_ARRAY;

      INT_RestoreDataCache(data_cache_id);
      RestoreIRQMask(savedMask);
   }

#if defined(__BASIC_LOAD_FLASH_TEST__) && defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
	 insertTestLISR();
#endif

   return FS_NO_ERROR;
}
#endif // ! __COMBO_MEMORY_SUPPORT__
#endif // !__NOR_FDM5__

__nor_section_RAM static void DelayAWhile_SIB(kal_uint32 Delay)
{

   volatile kal_uint32 CurrentTime,StartTime;

   StartTime = INT_GetCurrentTime(); //32KHz Fregquency Counter

   if(Delay != 0)
   {
       while(1)
       {
          CurrentTime = INT_GetCurrentTime();
          if(StartTime > CurrentTime)
          {
             if (CurrentTime> Delay)
                break;
          }
          else if ((CurrentTime-StartTime)>(Delay))
             break;
       }
   }
   while(1)
   {
      CurrentTime = INT_GetCurrentTime();
      if(StartTime != CurrentTime)
         break;
   }

   return;
}


#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

/* ------------------------------------------------------------------ */

// Can program check ready and Erase check ready be merged into one check Function like waitReady_SIB (for Multi-bank)

__nor_section_RAM kal_int32 CheckReadyAndResume_SIB(kal_uint32 addr) /* for program operation only */
{
   kal_uint32 data_cache_id;
   static kal_uint16 check_data = 0;
   kal_uint32 savedMask;
   kal_int32   status = RESULT_FLASH_BUSY;

   savedMask = SaveAndSetIRQMask();

   if(NOR_FLASH_SUSPENDED)
   {
      SNOR_MTD_ASSERT(NOR_FLASH_BUSY, *(volatile kal_uint16*)addr, *(volatile kal_uint16*)addr, addr);

      *(volatile kal_uint16*)addr = INTEL_CMD_RESUME;
      *(volatile kal_uint16*)addr = INTEL_CMD_RD_SR;

      NOR_FLASH_SUSPENDED = KAL_FALSE;

      gNOR_ReturnReadyEnd = NOR_DEFAULT_RETURN_READY_LATENCY;
   }

   data_cache_id = INT_DisableDataCache();

   *(volatile kal_uint16*)addr = INTEL_CMD_RD_SR;
   check_data = *(volatile kal_uint16*)addr;
   
   *(volatile kal_uint16*)addr = INTEL_CMD_RD_ARRAY;
      
   if(check_data & INTEL_READY_FLAG)
   {
      NOR_FLASH_BUSY = KAL_FALSE;
      
      if (check_data & INTEL_PROGRAM_ERROR_FLAG)
         status = RESULT_FLASH_FAIL;    
      else
         status = RESULT_FLASH_DONE;   	
   }

   INT_RestoreDataCache(data_cache_id);
   RestoreIRQMask(savedMask);

   return status;
}
#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */


/*-----------------------------------*/
__nor_section_RAM int WaitReady_SIB(kal_uint32 addr,kal_uint16 wait_method,kal_uint32 Delay)
{
   kal_uint16 stat_data;
   kal_uint32 data_cache_id;

   data_cache_id = INT_DisableDataCache();

   DelayAWhile_SIB(Delay);

   while(1)
   {
      DelayAWhile_SIB(0);
      *(volatile kal_uint16*)addr = INTEL_CMD_RD_SR;
      stat_data = *(volatile kal_uint16*)addr;
      if(stat_data & INTEL_READY_FLAG)
         break;
      BLTest(3);
   }
   *(volatile kal_uint16*)addr = INTEL_CMD_RD_ARRAY;

   INT_RestoreDataCache(data_cache_id);

   if(wait_method == INTEL_WAIT_PROGRAM)
   {
      /* Program */
      if (stat_data & INTEL_PROGRAM_ERROR_FLAG)
      	 return RESULT_FLASH_FAIL;
   }else if (wait_method == INTEL_WAIT_ERASE) {
      /* Erase */
      if (stat_data & INTEL_ERASE_ERROR_FLAG)
      	 return RESULT_FLASH_FAIL;
   }else{
      /* Sibley Blank Check */
      return RESULT_FLASH_DONE;
   }
   return RESULT_FLASH_DONE;
}


/*-----------------------------------*/
__nor_section_RAM int WaitReady_INTEL(kal_uint32 addr,kal_uint16 wait_method)
{
   kal_uint16 stat_data;
   kal_uint32 data_cache_id;

   data_cache_id = INT_DisableDataCache();

   while(1)
   {
      *(volatile kal_uint16*)addr = INTEL_CMD_RD_SR;
      stat_data = *(volatile kal_uint16*)addr;
      if(stat_data & INTEL_READY_FLAG)
         break;
      BLTest(0);
   }
   *(volatile kal_uint16*)addr = INTEL_CMD_RD_ARRAY;

   INT_RestoreDataCache(data_cache_id);

   if(wait_method == INTEL_WAIT_PROGRAM)
   {
      /* Program */
      if (stat_data & INTEL_PROGRAM_ERROR_FLAG)
      	 return RESULT_FLASH_FAIL;
//         ASSERT(0);
   }else if (wait_method == INTEL_WAIT_ERASE) {
      /* Erase */
      if (stat_data & INTEL_ERASE_ERROR_FLAG) {
      	 return RESULT_FLASH_FAIL;
      }
   }else{
      /* Sibley Blank Check */
      return RESULT_FLASH_DONE;
   }
   return RESULT_FLASH_DONE;
}

__nor_section_RAM static int LockEraseBlkAddr_INTEL(void * DriveData, void *BlkAddr,UINT ACTION)
{
   kal_uint32 savedMask;
   kal_uint32 data_cache_id;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *) BlkAddr;

   if(ACTION == ACTION_UNLOCK)
   {
      savedMask = SaveAndSetIRQMask();
      data_cache_id = INT_DisableDataCache();
      UNLOCK_COMMAND(0)
      fp[0] = INTEL_CMD_RD_ID;
      if( fp[2] & INTEL_BLOCK_LOCK_FLAG)
         ASSERT(0);
      fp[0] = INTEL_CMD_RD_ARRAY;
      INT_RestoreDataCache(data_cache_id);
      RestoreIRQMask(savedMask);
   }
   else if(ACTION== ACTION_LOCK)
   {
      savedMask = SaveAndSetIRQMask();
      data_cache_id = INT_DisableDataCache();
      LOCK_COMMAND(0)
      fp[0] = INTEL_CMD_RD_ID;
      if( !(fp[2] & INTEL_BLOCK_LOCK_FLAG))
         ASSERT(0);
      fp[0] = INTEL_CMD_RD_ARRAY;
      INT_RestoreDataCache(data_cache_id);
      RestoreIRQMask(savedMask);
   }
   else if (ACTION== ACTION_ERASE)
   {
      savedMask = SaveAndSetIRQMask();
      //Erase command
      fp[0] = INTEL_CMD_ERASE_SETUP;
      fp[0] = INTEL_CMD_ERASE_CONFIRM;

      RestoreIRQMask(savedMask);
      WaitReady_INTEL((kal_uint32)fp, INTEL_WAIT_ERASE);
   }
   else
   {
      ASSERT(0);
   }
   return FS_NO_ERROR;
}


/*******************************************************************//**
 * Shutdown NOR flash device
 *
 * @par Catagory:
 * NOR MTD (NOR FDM 4.0, INTEL-series)
 *
 * @param[in] DriveData       NOR flash MTD data
 *
 * @remarks
 * This function must be placed on RAM because flash may be busy/resumed inside!
 **********************************************************************/
#ifndef __NOR_FDM5__
#ifndef __COMBO_MEMORY_SUPPORT__
__nor_section_RAM static int ShutDown_INTEL(void *DriveData)
{
   NOR_Flash_MTD_Data  *D = DriveData;
   volatile FLASH_CELL *fp = (volatile FLASH_CELL*)D->CurrAddr;
   FLASH_CELL          stat_data;
   kal_uint32          data_cache_id;
   #if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   kal_uint32          saved_mask;
   #endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

   data_cache_id = INT_DisableDataCache();

   while (1)
   {
      #if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
      saved_mask = SaveAndSetIRQMask();

      // resume suspended operation issued by ISR (ESB only)
      if(NOR_FLASH_SUSPENDED)
      {
         *(volatile FLASH_CELL*)fp = INTEL_CMD_RESUME;

         NOR_FLASH_SUSPENDED = KAL_FALSE;

         #ifdef __MONZA_2G__
         gNOR_ReturnReadyEnd = NOR_DEFAULT_RETURN_READY_LATENCY;
         #endif
      }
      #endif  /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

      // read status register
      *(volatile FLASH_CELL*)fp = INTEL_CMD_RD_SR;
      stat_data = *(volatile FLASH_CELL*)fp;

      // if flash is ready, break, else loops again
      if (stat_data & INTEL_READY_FLAG)
      {
         // set flash to read array (if not, read operation later will get status data and lead to data abort)
        *(volatile FLASH_CELL*)fp = INTEL_CMD_RD_ARRAY;

         #if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
         NOR_FLASH_BUSY = KAL_FALSE;
         RestoreIRQMask(saved_mask);
         #endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

         break;
      }
      else
      {
         #if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
         RestoreIRQMask(saved_mask);
         #endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */
      }
   }

   D->CurrAddr = NULL;

   INT_RestoreDataCache(data_cache_id);

   return FS_NO_ERROR;
}
#endif // !_COMBO_MEMORY_SUPPORT__
#endif /* !__NOR_FDM5__ */

/*-----------------------------------*/
__nor_section_RAM static int EraseBlock_INTEL(void * DriveData, kal_uint32 BlockIndex)
{
   kal_uint32 savedMask;

#if !(defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__))
   kal_uint8 Retry = 0;
#endif

#ifndef __NOR_FDM5__
   NOR_Flash_MTD_Data * D = DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *) D->CurrAddr;
   ASSERT((~D->Signature == (kal_uint32)D->RegionInfo));
#else
   NOR_MTD_DATA *D= DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *)BlockAddress(D,BlockIndex);
   ASSERT(D->Signature == ~((kal_uint32)D->LayoutInfo));
#endif

   waitNonBlockEraseDone();

#if !(defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__))
ERASE:
#endif

   savedMask = SaveAndSetIRQMask();

   //Erase command
   fp[0] = INTEL_CMD_ERASE_SETUP;
   fp[0] = INTEL_CMD_ERASE_CONFIRM;

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

   NOR_FLASH_BUSY = KAL_TRUE;
   RestoreIRQMask(savedMask);
   while( FS_FLASH_ERASE_BUSY == CheckDeviceReady_INTEL(DriveData, BlockIndex) ) {
      // polling flash status per 1 ms to avoid heavy EMI traffic
      // To Do: avoid smart phone modem load to reference NOR MTD
      //DelayAWhile_UST(1000);
   	  BLTest(2);
   }

#else /* multi-bank */

   RestoreIRQMask(savedMask);
   // Intel Sibley had a issue which power-off during erase busy will cause erase failure in the next time power-up.
   // Issue second time seems work.
   if(WaitReady_INTEL((kal_uint32)fp, INTEL_WAIT_ERASE)==RESULT_FLASH_FAIL) {
   	  if (Retry<3) {
	   	  Retry++;
		  fp[0] = INTEL_CMD_CLR_SR;
		  fp[0] = INTEL_CMD_RD_ARRAY;
	   	  goto ERASE;
   	  } else {
   	      ASSERT(0);
   	  }
   }

#endif  /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

#if defined(__BASIC_LOAD_FLASH_TEST__)
	EraseNum++;
#endif

   return FS_NO_ERROR;
}

/*-----------------------------------*/

#if (defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__))

/* ------------------------------------------------------------------ */
__nor_section_RAM kal_int32 CheckReadyAndResume_INTEL(kal_uint32 addr,kal_uint16 data) /* for program operation only */
{
   kal_uint32 data_cache_id;
   static kal_uint16 check_data = 0;
   //static kal_uint16 toggle_data = 0;
   kal_uint32 savedMask;
   kal_int32   status = RESULT_FLASH_BUSY;

   savedMask = SaveAndSetIRQMask();

   if(NOR_FLASH_SUSPENDED)
   {
      SNOR_MTD_ASSERT(NOR_FLASH_BUSY, *(volatile kal_uint16*)addr, *(volatile kal_uint16*)addr, addr);

      *(volatile kal_uint16*)addr = INTEL_CMD_RESUME;
      *(volatile kal_uint16*)addr = INTEL_CMD_RD_SR;

      NOR_FLASH_SUSPENDED = KAL_FALSE;

      #ifdef __MONZA_2G__
      gNOR_ReturnReadyEnd = NOR_DEFAULT_RETURN_READY_LATENCY;
      #endif
   }

   data_cache_id = INT_DisableDataCache();

   *(volatile kal_uint16*)addr = INTEL_CMD_RD_SR;
   check_data = *(volatile kal_uint16*)addr;
   *(volatile kal_uint16*)addr = INTEL_CMD_RD_ARRAY;
   
   if(check_data & INTEL_READY_FLAG)
   {
      check_data = *(volatile kal_uint16*)addr;
      NOR_FLASH_BUSY = KAL_FALSE;
      if (check_data == data) {
	      status = RESULT_FLASH_DONE;
      } else {
          status = RESULT_FLASH_FAIL;
      }
   }

   INT_RestoreDataCache(data_cache_id);
   RestoreIRQMask(savedMask);

   return status;
}
#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */


#ifdef NOR_FLASH_TYPE_INTEL_SERIES

__nor_section_RAM kal_int32 WordProgram_INTEL(volatile FLASH_CELL* Address, FLASH_CELL Data)
{
   kal_uint32 savedMask;
   kal_int32 result = RESULT_FLASH_BUSY;

   savedMask = SaveAndSetIRQMask();

   ((volatile FLASH_CELL*)Address)[0] = INTEL_CMD_CLR_SR; //clear status register first
   ((volatile FLASH_CELL*)Address)[0] = INTEL_CMD_PGM_WORD;
   ((volatile FLASH_CELL*)Address)[0] = Data;

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

   NOR_FLASH_BUSY = KAL_TRUE;
   RestoreIRQMask(savedMask);
   do
   {
      result = CheckReadyAndResume_INTEL((kal_uint32)Address, Data);
      BLTest(1);
   }
   while (result == RESULT_FLASH_BUSY);

#else  /* multi-bank */

   RestoreIRQMask(savedMask);
   result = WaitReady_INTEL((kal_uint32)Address, INTEL_WAIT_PROGRAM);

#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */
   return result;
}

__nor_section_RAM static int ProgramData_INTEL(void * DriveData, void * Address, void * Data, kal_uint32 Length)
{
   kal_uint32 savedMask;
   kal_uint32  restore_value;
   kal_int32 result = RESULT_FLASH_BUSY;

#ifndef __NOR_FDM5__
   NOR_Flash_MTD_Data * D = DriveData;
   ASSERT((~D->Signature == (kal_uint32)D->RegionInfo));
#else
   NOR_MTD_DATA *D= DriveData;
   ASSERT(D->Signature == ~((kal_uint32)D->LayoutInfo));
#endif

#if defined(__BASIC_LOAD_FLASH_TEST__)
   ProgramNum++;
#endif

   switch (Length)
   {
      case sizeof(FLASH_CELL):

         result = WordProgram_INTEL(Address, *(FLASH_CELL*)Data);

         break;

      case 1:
      {
         volatile FLASH_CELL *fp;
         kal_uint32 ofs = ((kal_uint32) Address) & (sizeof(FLASH_CELL)-1);
         FLASH_CELL Cell;
         kal_uint8 *b = (kal_uint8*) &Cell;

         fp   = (FLASH_CELL*) (((kal_uint32) Address) & ~(sizeof(FLASH_CELL)-1)); // round it down
         Cell = fp[0];

         b[ofs] = ((kal_uint8*)Data)[0];

         result = WordProgram_INTEL(fp, Cell);

      }
      break;

#ifdef __PAGE_BUFFER_PROGRAM__
      case 512:

#ifdef __COMBO_MEMORY_SUPPORT__
      if(PAGE_BUFFER_SIZE)
#endif		
      {
         kal_uint32 ISRCountBefore,ISRCountAfter;
         kal_uint32 i, j, k;
         volatile FLASH_CELL *fp,*dfp;
         FLASH_CELL *dtp;

         fp = (volatile FLASH_CELL *)Address;

         if((((kal_uint32)Data) % sizeof(FLASH_CELL)))   // Data address is not word-aligned
         {
            kal_uint8 *bdp =	(kal_uint8*)Data;
            FLASH_CELL Cell;
            kal_uint8 *b = (kal_uint8*)&Cell;
            j = 0;

            for(k = 0; k < (Length/sizeof(FLASH_CELL))/PAGE_BUFFER_SIZE; k++)
            {

               dfp = &(fp[k*PAGE_BUFFER_SIZE]);

               savedMask = SaveAndSetIRQMask();

               ISRCountBefore = PROCESSING_IRQ_CNT;

               *dfp = INTEL_CMD_CLR_SR;	//clear status register first
               *dfp = INTEL_CMD_BUF_PGM;	//enter buffered programming
               *dfp = PAGE_BUFFER_SIZE-1; //set data count
               b[0]=bdp[j++];
               b[1]=bdp[j++];
               *dfp++ = Cell;

#if !(defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__))
               RestoreIRQMask(savedMask);
#endif

               for(i = 1; i < PAGE_BUFFER_SIZE; i++)
               {
                  b[0]=bdp[j++];
                  b[1]=bdp[j++];
                  *dfp++ = Cell;
               }

               fp[k*PAGE_BUFFER_SIZE] = INTEL_CMD_BUF_PGM_CNF;   // set confirm command to flush buffer to flash

               ISRCountAfter = PROCESSING_IRQ_CNT;

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

               NOR_FLASH_BUSY = KAL_TRUE;
               RestoreIRQMask(savedMask);
               do
               {
                  result = CheckReadyAndResume_INTEL((kal_uint32)&fp[(k+1)*PAGE_BUFFER_SIZE-1], Cell);
                  BLTest(3);
               }
               while (result == RESULT_FLASH_BUSY);

               if (result == RESULT_FLASH_FAIL)
                  return result;

#else  /* multi-bank */

               result = WaitReady_INTEL((kal_uint32)&fp[k*PAGE_BUFFER_SIZE], INTEL_WAIT_PROGRAM);
               if(ISRCountBefore != ISRCountAfter)
               {
                  if (CompareData((void*)&(fp[k*PAGE_BUFFER_SIZE]),(void*)&(bdp[k*PAGE_BUFFER_SIZE<<1]),PAGE_BUFFER_SIZE)==KAL_TRUE)
                  {
                     ASSERT(0);
                  }
               }

#endif  /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */
            }

         }
         else   //Data address is word-aligned
         {
            FLASH_CELL *dp = (FLASH_CELL*)Data;

            for(k = 0; k < (Length/sizeof(FLASH_CELL))/PAGE_BUFFER_SIZE; k++)
            {
               dfp = &(fp[k*PAGE_BUFFER_SIZE]);
               dtp = &(dp[k*PAGE_BUFFER_SIZE]);

               savedMask = SaveAndSetIRQMask();

               ISRCountBefore = PROCESSING_IRQ_CNT;

               *dfp = INTEL_CMD_CLR_SR;	 //clear status register first
               *dfp = INTEL_CMD_BUF_PGM;	 // enter buffered programming
               *dfp = PAGE_BUFFER_SIZE-1;  // set data count
               *dfp++ = *dtp++;

#if !(defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__))
               RestoreIRQMask(savedMask);
#endif

               for(i = 1; i < PAGE_BUFFER_SIZE; i++)
               {
                  *dfp++ = *dtp++;  // fill data to device buffer
               }

               fp[k*PAGE_BUFFER_SIZE] = INTEL_CMD_BUF_PGM_CNF; // set confirm command to flush buffer to flash

               ISRCountAfter = PROCESSING_IRQ_CNT;

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

               NOR_FLASH_BUSY = KAL_TRUE;
               RestoreIRQMask(savedMask);
               do
               {
                  result = CheckReadyAndResume_INTEL((kal_uint32)&fp[(k+1)*PAGE_BUFFER_SIZE-1], (kal_uint16)dp[(k+1)*PAGE_BUFFER_SIZE-1]);
                  BLTest(5);
               }
               while (result == RESULT_FLASH_BUSY);

               if(result == RESULT_FLASH_FAIL)
                  return result;

#else  /* multi-bank */

               result = WaitReady_INTEL((kal_uint32)&fp[k*PAGE_BUFFER_SIZE], INTEL_WAIT_PROGRAM);
               if(ISRCountBefore != ISRCountAfter)
               {
                  if (CompareData((void*)&(fp[k*PAGE_BUFFER_SIZE]),(void*)&(dp[k*PAGE_BUFFER_SIZE]),PAGE_BUFFER_SIZE)==KAL_TRUE)
                  {
                     ASSERT(0);
                  }
               }

#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */
            }

         }

         break;  // break the 512 case only PAGE_BUFFER_SIZE != 0 (when combo memory turn on, PAGE_BUFFER_SIZE may be 0 even if __PAGE_BUFFER_PROGRAM__ defined)
      }
      // if combo memory support on, PAGE_BUFFER_SIZE == 0, do not break the switch case, do word program at the default case
#endif //  __PAGE_BUFFER_PROGRAM__
      default:
      {
         kal_uint32 i, j;
         volatile FLASH_CELL *fp;

         fp = (volatile FLASH_CELL *)Address;
         if((((kal_uint32)Data) % sizeof(FLASH_CELL)))  // Data address is not word-aligned
         {
            kal_uint8 *bdp =  (kal_uint8*)Data;
            FLASH_CELL Cell;
            kal_uint8 *b = (kal_uint8*)&Cell;

            j = 0;
            for(i = 0; i < Length/sizeof(FLASH_CELL); i++)
            {
               b[0] = bdp[j++];
               b[1] = bdp[j++];

               result = WordProgram_INTEL(&fp[i], Cell);

               if (result == RESULT_FLASH_FAIL)
                  return RESULT_FLASH_FAIL;

            }
         }
         else  // Data address is word-aligned
         {
            FLASH_CELL *dp = (FLASH_CELL*)Data;

            for(i = 0; i < Length/sizeof(FLASH_CELL); i++)
            {

               result = WordProgram_INTEL(&fp[i], dp[i]);

               if (result == RESULT_FLASH_FAIL)
                  return RESULT_FLASH_FAIL;

            }
         }
      }
      break;

   }

   if (result == RESULT_FLASH_FAIL)
      return RESULT_FLASH_FAIL;

   return FS_NO_ERROR;
}
#endif


#if defined(__INTEL_SIBLEY__) //__INTEL_SIBLEY__

/*******************************************************************//**
 * Program data to NOR flash
 *
 * @par Catagory:
 * NOR MTD (SIBLEY)
 *
 * @param[in,out] DriveData   NOR flash drive data
 * @param[in]     Address     Logical sector ID to recoverable write (see remarks!)
 *
 * @notes
 *
 * @remarks
 * 1. "Sector" may not be the actual logical sector ID to recoverable write! Because in SIBLEY, two continuous logical sectors share one physical sector, the same "Sector" will be used when writing logical sectors of the same physical sector!
 *
 **********************************************************************/
__nor_section_RAM static int ProgramData_SIB(void *DriveData, void *Address, void *Data, kal_uint32 Length)
{

   volatile FLASH_CELL  *fp = (volatile FLASH_CELL*)Address;
   FLASH_CELL           *dp = (FLASH_CELL*)Data;
   kal_uint8            *Bdp = (kal_uint8 *)Data;
   kal_uint32           savedMask, i;
    kal_int32           result = RESULT_FLASH_BUSY;
#ifndef __NOR_FDM5__
   NOR_Flash_MTD_Data *D = DriveData;
   ASSERT((~D->Signature == (kal_uint32)D->RegionInfo));
#else
   NOR_MTD_DATA *D= DriveData;
   ASSERT(D->Signature == ~((kal_uint32)D->LayoutInfo));
#endif

#if defined(__BASIC_LOAD_FLASH_TEST__)
   ProgramNum++;
#endif

    waitNonBlockEraseDone();

   NOR_PROFILE_MTD_WRITE_Count();

   // buffer program
   if(Length > 16)
   {
      ASSERT((Length & 1) == 0);

      // data address is word-aligned
      if (((kal_uint32)Data & 0x1) == 0)
      {
         fp[0] = INTEL_CMD_CLR_SR;        //clear status register first
         fp[0] = SIB_CMD_PGM_BUF_C1;
         fp[0] = (Length >> 1) - 1;
         for(i = 0; i < Length / sizeof(FLASH_CELL); i++)
         {
            fp[i] = dp[i];
         }
         savedMask = SaveAndSetIRQMask();
         fp[0] = SIB_CMD_PGM_BUF_C2;
      }
      // buffer program, data address is not word-aligned
      else
      {
         FLASH_CELL Cell;
         kal_uint8 *b = (kal_uint8*) &Cell;

         // buffered program
         fp[0] = INTEL_CMD_CLR_SR;        //clear status register first
         fp[0] = SIB_CMD_PGM_BUF_C1;
         fp[0] = (Length >> 1) - 1;
         for(i = 0; i < Length / sizeof(FLASH_CELL); i++)
         {
            b[0] = Bdp[0];
            b[1] = Bdp[1];
            fp[i] = Cell;
            Bdp += 2;
         }
         savedMask = SaveAndSetIRQMask();
         fp[0] = SIB_CMD_PGM_BUF_C2;
      }

      NOR_PROFILE_MTD_WRITE_Start();
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

      NOR_FLASH_BUSY = KAL_TRUE;
      RestoreIRQMask(savedMask);

      do
      {
         result = CheckReadyAndResume_SIB((kal_uint32)fp);
         BLTest(1);
      }
      while (result == RESULT_FLASH_BUSY);


#else  /* multi-bank */

      RestoreIRQMask(savedMask);
      result = WaitReady_SIB((kal_uint32)&fp[0], INTEL_WAIT_PROGRAM, Length >> 5 );

#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */
      NOR_PROFILE_MTD_WRITE_End();

      // Inside CompareData, there will be NOT assert if compare data failed. So it does have to compare data after buffer programming (w08.48).
   }
   // word program
   else if(Length <= 16)
   {
      kal_uint32 AddrPtr = (kal_uint32)Address;
      kal_uint32 DataPtr = (kal_uint32)Data;
      kal_uint32 ofs;
      FLASH_CELL Cell;
      kal_uint8 *b = (kal_uint8*) &Cell;

      // A3 must equal to zero
      ASSERT(((kal_uint32)Address&0x10)==0 &&(((kal_uint32)Address+Length-1)&0x10)==0);

      while(Length >0)
      {
         if ((AddrPtr % sizeof(FLASH_CELL) !=0) || (Length < sizeof(FLASH_CELL)))
         {
            ofs = (AddrPtr) & (sizeof(FLASH_CELL)-1);
            fp = (FLASH_CELL*) (AddrPtr & ~(sizeof(FLASH_CELL)-1)); // round it down
            Cell = fp[0];
            b[ofs] = ((kal_uint8*)DataPtr)[0];
            Length=Length-1;
            AddrPtr=AddrPtr+1;
            DataPtr=DataPtr+1;
         }
         else
         {
            fp = (FLASH_CELL*) (AddrPtr);
            b[0] = ((kal_uint8*)DataPtr)[0];
            b[1] = ((kal_uint8*)DataPtr)[1];
            Length=Length-2;
            AddrPtr=AddrPtr+2;
            DataPtr=DataPtr+2;
         }
         savedMask = SaveAndSetIRQMask();
         fp[0] = INTEL_CMD_CLR_SR;        //clear status register first
         fp[0] = SIB_CMD_PGM_WORD;
         fp[0] = Cell;

         NOR_PROFILE_MTD_WRITE_Start();
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

         NOR_FLASH_BUSY = KAL_TRUE;
         RestoreIRQMask(savedMask);
         do
         {
            result = CheckReadyAndResume_SIB((kal_uint32)fp);
            BLTest(1);
         }
         while (result == RESULT_FLASH_BUSY);


#else  /* multi-bank */

         RestoreIRQMask(savedMask);
         result = WaitReady_SIB((kal_uint32)fp, INTEL_WAIT_PROGRAM, 0);

#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */
         NOR_PROFILE_MTD_WRITE_End();


         if (result == RESULT_FLASH_FAIL)
            return RESULT_FLASH_FAIL;
      }
   }
   else
   {
      ASSERT(0);
   }
   return FS_NO_ERROR;
}
#endif //__INTEL_SIBLEY__

#if (defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) && !defined(__COMBO_MEMORY_SUPPORT__))

extern NOR_FLASH_DRV_Data  FlashDriveData;
extern kal_bool            NOR_FLASH_BUSY;
extern kal_bool            NOR_FLASH_SUSPENDED;

__nor_section_RAM static void waitReady(volatile FLASH_CELL *flash_base) /* instruction prefetch should be disabled */
{
   static FLASH_CELL s = 0 ;

   /* issue suspend command */
   flash_base[0] = INTEL_CMD_SUSPEND;
   flash_base[0] = INTEL_CMD_RD_SR;

   s = flash_base[0];
   while(!(s&INTEL_READY_FLAG))
   {
      flash_base[0] = INTEL_CMD_RD_SR;
      s = flash_base[0];
   }
   NOR_FLASH_SUSPENDED = KAL_TRUE;
   flash_base[0] = INTEL_CMD_RD_ARRAY;

}

#if !defined(__FUE__) && !defined(__UBL__)
__nor_section_RAM void Flash_ReturnReady(void) /* should be invoked only when interrupt is disabled */
{
   NOR_Flash_MTD_Data *mtd_data = NULL;
   static FLASH_CELL s;
   kal_uint32 data_cache_id;
   volatile FLASH_CELL *flash_p = NULL;

   #if defined(__FOTA_DM__)
   if(FOTA_Flash_busy)
   {
      mtd_data = (NOR_Flash_MTD_Data *)NORFlashDriveData.MTDData;
   }
   else
   #endif   /* __FOTA_DM__ */
   {
      mtd_data = (NOR_Flash_MTD_Data *)FlashDriveData.MTDData;
   }

   ASSERT(~(mtd_data->Signature) == ((kal_uint32)mtd_data->RegionInfo));

   flash_p = (volatile FLASH_CELL *)mtd_data->CurrAddr;

   if((!NOR_FLASH_SUSPENDED) && NOR_FLASH_BUSY)
   {
      gNOR_ReturnReadyBegin = ust_get_current_time();  // get start time of Flash_ReturnReady (Only when flash is busy)

      data_cache_id = INT_DisableDataCache();

      flash_p[0] = INTEL_CMD_RD_SR;
      s = flash_p[0];

      if(!( s & INTEL_READY_FLAG))
      {
         waitReady(flash_p);
      }
      else
      {
         NOR_FLASH_BUSY = KAL_FALSE;
      }
      flash_p[0] = INTEL_CMD_RD_ARRAY;
      INT_RestoreDataCache(data_cache_id);

      gNOR_ReturnReadyEnd = ust_get_current_time();     // get end time of Flash_ReturnReady

   }
}
#else // UBL
__nor_section_RAM void Flash_ReturnReady(void) /* should be invoked only when interrupt is disabled */
{
   return;	
}

#endif //!__UBL__


__nor_section_RAM kal_bool Flash_CheckReady(void)
{
#ifdef __ERASE_QUEUE_ENABLE__	
   NOR_Flash_MTD_Data *mtd_data = (NOR_Flash_MTD_Data *)FlashDriveData.MTDData;
   static FLASH_CELL s;
   kal_uint32 data_cache_id;
   volatile FLASH_CELL *flash_p = NULL;
   kal_bool result = KAL_FALSE;

   ASSERT(~(mtd_data->Signature) == ((kal_uint32)mtd_data->RegionInfo));

#if (defined(__MULTI_BANK_NOR_DEVICE__) || defined(__ARM9_MMU__) || defined(__ARM11_MMU__))
   flash_p = (volatile kal_uint16*)FlashDriveData.processedBankAddr;
#else  /* !__MULTI_BANK_NOR_DEVICE__ && !__ARM9_MMU__ && !__ARM11_MMU__*/
   flash_p = (volatile FLASH_CELL *)mtd_data->CurrAddr;
#endif /* __MULTI_BANK_NOR_DEVICE__ || __ARM9_MMU__ || __ARM11_MMU__*/

   data_cache_id = INT_DisableDataCache();

   flash_p[0] = INTEL_CMD_RD_SR;
   s = flash_p[0];

   if(s & INTEL_READY_FLAG)
   {
      NOR_FLASH_BUSY = KAL_FALSE;
      result = KAL_TRUE;
   }
   flash_p[0] = INTEL_CMD_RD_ARRAY;
   INT_RestoreDataCache(data_cache_id);

   return result;
#else
   return KAL_FALSE;
#endif //__ERASE_QUEUE_ENABLE__   
}

__nor_section_RAM void Flash_ResumeOperation(void)
{
#ifdef __ERASE_QUEUE_ENABLE__	
#if (defined(__MULTI_BANK_NOR_DEVICE__) || defined(__ARM9_MMU__) || defined(__ARM11_MMU__))
   volatile FLASH_CELL *fp = (volatile FLASH_CELL *) FlashDriveData.processedBankAddr;
#else  /* !__MULTI_BANK_NOR_DEVICE__ && !__ARM9_MMU__ && !__ARM11_MMU__*/
   NOR_Flash_MTD_Data  *mtd_data = (NOR_Flash_MTD_Data *)FlashDriveData.MTDData;
   volatile FLASH_CELL *fp = (volatile FLASH_CELL *) mtd_data->CurrAddr;
#endif /* __MULTI_BANK_NOR_DEVICE__ || __ARM9_MMU__ || __ARM11_MMU__*/

   SNOR_MTD_ASSERT(NOR_FLASH_BUSY && NOR_FLASH_SUSPENDED, NOR_FLASH_BUSY, NOR_FLASH_SUSPENDED, (fp[0]<<16)|fp[0]);

   fp[0] = INTEL_CMD_RESUME;
   fp[0] = INTEL_CMD_RD_SR;

   NOR_FLASH_SUSPENDED = KAL_FALSE;
#endif   
}

__nor_section_RAM void Flash_SuspendOperation(void)
{
#ifdef __ERASE_QUEUE_ENABLE__
   NOR_Flash_MTD_Data *mtd_data = (NOR_Flash_MTD_Data *)FlashDriveData.MTDData;
#if (defined(__MULTI_BANK_NOR_DEVICE__) || defined(__ARM9_MMU__) || defined(__ARM11_MMU__))
   volatile FLASH_CELL *flash_p = (volatile FLASH_CELL *) FlashDriveData.processedBankAddr;
#else  /* !__MULTI_BANK_NOR_DEVICE__ && !__ARM9_MMU__ && !__ARM11_MMU__*/
   volatile FLASH_CELL *flash_p = (volatile FLASH_CELL *)mtd_data->CurrAddr;
#endif /* __MULTI_BANK_NOR_DEVICE__ || __ARM9_MMU__ || __ARM11_MMU__*/
   kal_uint32 data_cache_id;
   static FLASH_CELL s = 0 ;

   SNOR_MTD_ASSERT(NOR_FLASH_BUSY && !(NOR_FLASH_SUSPENDED), NOR_FLASH_BUSY, NOR_FLASH_SUSPENDED, (flash_p[0]<<16)|flash_p[0]);
   ASSERT(~(mtd_data->Signature) == ((kal_uint32)mtd_data->RegionInfo));

   data_cache_id = INT_DisableDataCache();

   /* issue suspend command */
   flash_p[0] = INTEL_CMD_SUSPEND;
   flash_p[0] = INTEL_CMD_RD_SR;

   s = flash_p[0];
   while(!(s&INTEL_READY_FLAG))
   {
      flash_p[0] = INTEL_CMD_RD_SR;
      s = flash_p[0];
   }
   flash_p[0] = INTEL_CMD_RD_ARRAY;
   NOR_FLASH_SUSPENDED = KAL_TRUE;
   INT_RestoreDataCache(data_cache_id);
   #endif   
}

/* program a word at one time */
__nor_section_RAM void Flash_ProgramData(void *target, void *src, kal_uint32 size)
{
   volatile FLASH_CELL *dest = (volatile FLASH_CELL*)target;
   FLASH_CELL stat_data;
   kal_uint32 idx = 0;
   kal_uint32 data_cache_id = 0;

   SNOR_MTD_ASSERT(!((((kal_uint32)dest) & (sizeof(FLASH_CELL)-1)) || (((kal_uint32)src) & (sizeof(FLASH_CELL)-1))),
                   (kal_uint32)dest, (kal_uint32)src, sizeof(FLASH_CELL));

   data_cache_id = INT_DisableDataCache();

   while(size)
   {
      dest[idx] = INTEL_CMD_CLR_SR;
      #ifndef __INTEL_SIBLEY__
      dest[idx] = INTEL_CMD_PGM_WORD;
      #else //__INTEL_SIBLEY__
      dest[idx] = SIB_CMD_PGM_WORD;
      #endif //__INTEL_SIBLEY__
      dest[idx] = ((FLASH_CELL*)src)[idx];
      NOR_FLASH_BUSY = KAL_TRUE;

      while(1)
      {
         dest[idx] = INTEL_CMD_RD_SR;
         stat_data = dest[idx];
         if(stat_data & INTEL_READY_FLAG)
            break;
      }
      dest[idx]= INTEL_CMD_RD_ARRAY;

      if (stat_data & INTEL_PROGRAM_ERROR_FLAG) {
         ASSERT(0);
     }

      idx++;
      size -= sizeof(FLASH_CELL);
   }

   INT_RestoreDataCache(data_cache_id);
}

#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

/*-----------------------------------*/
__nor_section_RAM static int NonBlockEraseBlock_INTEL(void * DriveData, kal_uint32  BlockIndex) /* Added by Eric */
{
   kal_uint32 savedMask;
#ifndef __NOR_FDM5__
   NOR_Flash_MTD_Data * D = DriveData;
   volatile FLASH_CELL *fp = (volatile FLASH_CELL *) D->CurrAddr;
   ASSERT((~D->Signature == (kal_uint32)D->RegionInfo));
#else
   NOR_MTD_DATA *D= DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *)BlockAddress(D,BlockIndex);;
   ASSERT(D->Signature == ~((kal_uint32)D->LayoutInfo));
#endif

   waitNonBlockEraseDone();

   savedMask = SaveAndSetIRQMask();
   //Erase command
   fp[0] = INTEL_CMD_ERASE_SETUP;
   fp[0] = INTEL_CMD_ERASE_CONFIRM;

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   NOR_FLASH_BUSY = KAL_TRUE;
#endif
   RestoreIRQMask(savedMask);

#if defined(__BASIC_LOAD_FLASH_TEST__)
	EraseNum++;
#endif

   BLTest(1);

   gNonBlockingEraseBlockAddr = (kal_uint32)fp;

   return FS_NO_ERROR;
}

/*-----------------------------------*/
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
__nor_section_RAM static kal_int32 CheckDeviceReady_INTEL(void * DriveData, kal_uint32 BlockIndex) /* Added by Eric */
{
   kal_uint16 stat_data;
   kal_int32   status;
   kal_uint32 data_cache_id;
   kal_uint32 savedMask = 0;

   NOR_Flash_MTD_Data * D = DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *) D->CurrAddr;
   ASSERT((~D->Signature == (kal_uint32)D->RegionInfo));

   /* ensure that the status check is atomic */
   savedMask = SaveAndSetIRQMask();
   data_cache_id = INT_DisableDataCache();

   fp[0] = INTEL_CMD_RD_SR;
   stat_data = fp[0];

   if(stat_data & INTEL_READY_FLAG)
   {
      if(stat_data & INTEL_ERASE_SUSPEND)
      {
         /* flash is erase suspended */
         SNOR_MTD_ASSERT( NOR_FLASH_BUSY, NOR_FLASH_SUSPENDED, (kal_uint32)fp, (fp[0] << 16) | fp[0] );

         fp[0] = INTEL_CMD_RESUME;

         NOR_FLASH_SUSPENDED = KAL_FALSE;

         #ifdef __MONZA_2G__
         gNOR_ReturnReadyEnd = NOR_DEFAULT_RETURN_READY_LATENCY;
         #endif

         status =  FS_FLASH_ERASE_BUSY;
      }
      else
      {
         fp[0] = INTEL_CMD_RD_ARRAY;
         NOR_FLASH_BUSY = KAL_FALSE;
         /********************************************//**
          * If an interrupt comes during program/erase, in waitReady(), the device may deny the
          * "Suspend Erase/Program" command because the device is near/already ready. However,
          * NOR_FLASH_SUSPENDED is still be set to KAL_TRUE.
          *
          * In such case, after back to erase/program operation, CheckDeviceReady will reach here
          * because flash is not busy and not erase suspended (but with NOR_FLASH_SUSPENDED = KAL_TRUE). If NOR_FLASH_SUSPENDED
          * is not set to KAL_FALSE here, next time when an interrupt comes during erase/program
          * operation, Flash_ReturnReady() will be misleaded by wrong NOR_FLASH_SUSPENDED and return
          * to IRQ handler directly even if flash is still erasing/programing, leading to an execution
          * error! (Added in w08.28)
          ***********************************************/
         NOR_FLASH_SUSPENDED = KAL_FALSE;
         status = FS_NO_ERROR;
      }
   }
   else
   {
      status = FS_FLASH_ERASE_BUSY;
   }

   INT_RestoreDataCache(data_cache_id);
   RestoreIRQMask(savedMask);

   if((gNonBlockingEraseBlockAddr == (kal_uint32)fp) && (FS_NO_ERROR == status))
   {
      gNonBlockingEraseBlockAddr = INVALID_BLOCK_ADDR;   	
   }


   return status;
}
#else
__nor_section_RAM static int CheckDeviceReady_INTEL(void * DriveData, kal_uint32 BlockIndex) /* Added by Eric */
{
   kal_uint16 stat_data;
   kal_uint32 data_cache_id;
   kal_uint32 savedMask;

#ifndef __NOR_FDM5__
   NOR_Flash_MTD_Data * D = DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *) D->CurrAddr;
   ASSERT((~D->Signature == (kal_uint32)D->RegionInfo));
#else
   NOR_MTD_DATA *D= DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *)BlockAddress(D,BlockIndex);
   ASSERT(D->Signature == ~((kal_uint32)D->LayoutInfo));
#endif

   savedMask = SaveAndSetIRQMask();
   data_cache_id = INT_DisableDataCache();

   fp[0] = INTEL_CMD_RD_SR;
   stat_data = fp[0];
   fp[0] = INTEL_CMD_RD_ARRAY;

   INT_RestoreDataCache(data_cache_id);
   RestoreIRQMask(savedMask);

   if(stat_data & INTEL_READY_FLAG)
   {

       if(gNonBlockingEraseBlockAddr == (kal_uint32)fp)
       {
          gNonBlockingEraseBlockAddr = INVALID_BLOCK_ADDR;   	
       }
      return FS_NO_ERROR;
   }
   else
      return FS_FLASH_ERASE_BUSY;
}
#endif
/*-----------------------------------*/
#ifndef __COMBO_MEMORY_SUPPORT__
__nor_section_RAM static int SuspendErase_INTEL(void * DriveData, kal_uint32 BlockIndex) /* Added by Eric */
{

#ifndef __NOR_FDM5__
   NOR_Flash_MTD_Data * D = DriveData;
   volatile FLASH_CELL *fp = (volatile FLASH_CELL *) D->CurrAddr;
#else
   NOR_MTD_DATA *D= DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *)BlockAddress(D,BlockIndex);
#endif

   FLASH_CELL s = 0;
   kal_uint32 data_cache_id;

#if (defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__))
   kal_uint32 savedMask;
   savedMask = SaveAndSetIRQMask();
#endif

   data_cache_id = INT_DisableDataCache();

   fp[0] = INTEL_CMD_SUSPEND;
   fp[0] = INTEL_CMD_RD_SR;
   s = fp[0];
   while(!(s&INTEL_READY_FLAG))
   {
      fp[0] = INTEL_CMD_RD_SR;
      s = fp[0];
   }
   fp[0] = INTEL_CMD_RD_ARRAY;

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   NOR_FLASH_SUSPENDED = KAL_TRUE;
#endif

   INT_RestoreDataCache(data_cache_id);

#if (defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__))
   RestoreIRQMask(savedMask);
#endif

   return FS_NO_ERROR;
}

/*-----------------------------------*/
__nor_section_RAM static int ResumeErase_INTEL(void * DriveData, kal_uint32 BlockIndex) /* Added by Eric */
{
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   kal_uint32 savedMask;
#endif

#ifndef __NOR_FDM5__
   NOR_Flash_MTD_Data * D = DriveData;
   volatile FLASH_CELL *fp = (volatile FLASH_CELL *) D->CurrAddr;
#else
   NOR_MTD_DATA *D= DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *)BlockAddress(D,BlockIndex);
#endif


#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   savedMask = SaveAndSetIRQMask();
#endif

   fp[0] = INTEL_CMD_RESUME;

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   NOR_FLASH_SUSPENDED = KAL_FALSE;
   RestoreIRQMask(savedMask);
#endif

   return FS_NO_ERROR;
}
#endif //!__COMBO_MEMORY_SUPPORT__


/*-----------------------------------*/
#ifdef __INTEL_SIBLEY__
__nor_section_RAM static int BlankCheck_SIB(void * DriveData, kal_uint32 BlockIndex) //Especially for Sibley
{
   kal_uint32 savedMask;
   kal_uint16 stat_data;

#ifndef __NOR_FDM5__
   NOR_Flash_MTD_Data * D = DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *) D->CurrAddr;
   ASSERT((~D->Signature == (kal_uint32)D->RegionInfo));
#else
   NOR_MTD_DATA *D= DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *)BlockAddress(D,BlockIndex);
   ASSERT(D->Signature == ~((kal_uint32)D->LayoutInfo));
#endif

   savedMask = SaveAndSetIRQMask();
   //Blank Check Command
   fp[0] = SIB_CMD_BLANK_CK_C1;
   fp[0] = SIB_CMD_BLANK_CK_C2;
   RestoreIRQMask(savedMask);

   WaitReady_INTEL((kal_uint32)fp, SIB_WAIT_BLANK_CHECK);
   //Read Status Command
   savedMask = SaveAndSetIRQMask();
   fp[0] = INTEL_CMD_RD_SR;
   stat_data = fp[0];
   fp[0] = INTEL_CMD_CLR_SR;
   fp[0] = INTEL_CMD_RD_ARRAY;
   RestoreIRQMask(savedMask);
   return (stat_data & SIB_NOT_ALL_ERASED_FLAG)?0:1; // SR[5]=1 means not all erased
}
#endif


/*--------------------------------------------------------------------------
     Single bank NOR flash support
  --------------------------------------------------------------------------*/
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

#if !defined(__FUE__) && !defined(__UBL__)

__nor_section_RAM kal_bool IsEraseSuspended_INTEL(void * DriveData, kal_uint32 BlockIndex)
{
   kal_uint16 stat_data = 0;
   kal_uint32 data_cache_id = 0, savedMask = 0;
#ifndef __NOR_FDM5__
   NOR_Flash_MTD_Data * D = DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *) D->CurrAddr;
   #ifdef DEBUG
      SNOR_MTD_ASSERT(D->CurrAddr == BlockAddress(D, BlockIndex), (kal_uint32)(D->CurrAddr), (kal_uint32)(BlockAddress(D, BlockIndex)), BlockIndex);
   #endif
#else
   NOR_MTD_DATA *D= DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *)BlockAddress(D,BlockIndex);
#endif

   savedMask = SaveAndSetIRQMask();

   data_cache_id = INT_DisableDataCache();

   // Ready Status
   fp[0] = INTEL_CMD_RD_SR;
   stat_data = fp[0];

   // Switch back to Array mode
   fp[0] = INTEL_CMD_RD_ARRAY;

   INT_RestoreDataCache(data_cache_id);
   RestoreIRQMask(savedMask);

   if(stat_data & INTEL_READY_FLAG)
   {
      if(stat_data & INTEL_ERASE_SUSPEND)
      {
         return KAL_TRUE;
      }
   }
   
   return KAL_FALSE;

}

#else    /* __FUE__ */

__nor_section_RAM kal_bool IsEraseSuspended_INTEL(void * DriveData, kal_uint32 BlockIndex)
{
   return KAL_FALSE;
}

#endif   /* !__FUE__ */

#endif   /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */



/********************************************/
/*                                                                            */
/*                        FDM5.0 MTD SUPPORT                      */
/*                                                                            */
/********************************************/
#ifdef __NOR_FDM5__
// FDM 5 do not support ESB, the following functions do not need to put in SNORCODE section
static int MountDevice_INTEL(void * DriveData, void * Info)
{
   NOR_MTD_DATA * D = DriveData;
   NORLayoutInfo * Layout = D->LayoutInfo;
   kal_uint32 TotalPhysicalPages;
   kal_uint32 TblEntryShift=0,j=1;
   kal_uint32 block;
   volatile FLASH_CELL * fp;
   kal_uint32 savedMask;
   kal_uint32 data_cache_id;



   // check and assign D->LayoutInfo
   TotalPhysicalPages = (Layout->BlkSize)/(Layout->PageSize)*(Layout->TotalBlks);

   while(j<TotalPhysicalPages)
   {
      j = j << 1;
      TblEntryShift++;
   }
   TblEntryShift = TblEntryShift>>1;
   if((TblEntryShift) >8)
	   TblEntryShift=8;
   Layout->TblEntrys = 1<<TblEntryShift;

   if ( (Layout->TblEntrys * Layout->TotalLSMT) < TotalPhysicalPages)
      ASSERT(0);

   /* unlock all blocks */
   for(block=0; block< Layout->TotalBlks; block++)
   {

      fp = (volatile FLASH_CELL *) BlockAddress(D, block);

      savedMask = SaveAndSetIRQMask();
      data_cache_id = INT_DisableDataCache();
      UNLOCK_COMMAND(0)
      fp[0] = INTEL_CMD_RD_ID;
      if( fp[2] & INTEL_BLOCK_LOCK_FLAG)
         ASSERT(0);
      fp[0] = INTEL_CMD_RD_ARRAY;
      INT_RestoreDataCache(data_cache_id);
      RestoreIRQMask(savedMask);
   }

   return FS_NO_ERROR;
}

static int ShutDown_INTEL(void * DriveData)
{
   NOR_MTD_DATA * D = DriveData;
   NORBankInfo * BankInfo = D->LayoutInfo->BankInfo;
   kal_uint32 fp = (kal_uint32)D->BaseAddr;

   kal_uint32 i=0,j=0;

   for(i=0;BankInfo[i].Banks !=0;i++)
      for(j=0;j<BankInfo[i].Banks;j++)
      {
         WaitReady_INTEL((kal_uint32)fp, INTEL_WAIT_ERASE);
         fp+=(kal_uint32)BankInfo[i].BankSize;
      }
   return FS_NO_ERROR;
}

#endif   /* __NOR_FDM5__ */

/*-----------------------------------*/
#if defined(__MINI_BOOTLOADER__)

#if !defined(__COMBO_MEMORY_SUPPORT__)
NOR_MTD_Driver DriverName =
{
   MountDevice_INTEL,
#else
const NOR_MTD_Driver NORFlashMtd_INTEL =
{
   PF_DAL_MountDevice,
#endif   
   NULL, //ShutDown_INTEL,
   MapWindow,
   NULL, //EraseBlock_INTEL,
   NULL, //ProgramData_INTEL, ProgramData_SIB,
   NULL, //NonBlockEraseBlock_INTEL,
   NULL, //CheckDeviceReady_INTEL,
   NULL, //SuspendErase_INTEL,
   NULL, //ResumeErase_INTEL,
   NULL, //BlankCheck_SIB,
   NULL,
   NULL,
   NULL, //LockEraseBlkAddr_INTEL,
   NULL //IsEraseSuspended_INTEL
};

// !__MINI_BOOTLOADER__ && !__COMBO_MEMORY_SUPPORT__
#elif !defined(__COMBO_MEMORY_SUPPORT__)
NOR_MTD_Driver DriverName =
{
   MountDevice_INTEL,
   ShutDown_INTEL,
   MapWindow,
   EraseBlock_INTEL,

#ifndef __INTEL_SIBLEY__
   ProgramData_INTEL,
#else // !__INTEL_SIBLEY__
   ProgramData_SIB,
#endif

   NonBlockEraseBlock_INTEL,
   CheckDeviceReady_INTEL,
#ifdef __UBL__
   NULL,
   NULL,
#else   
   SuspendErase_INTEL,
   ResumeErase_INTEL,
#endif   
#ifndef __INTEL_SIBLEY__
   NULL,
#else
   BlankCheck_SIB,
#endif
   NULL,
   NULL,
   LockEraseBlkAddr_INTEL,
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   IsEraseSuspended_INTEL
#else
   NULL
#endif   
};
#else //__COMBO_MEMORY_SUPPORT__

const NOR_MTD_Driver NORFlashMtd_INTEL =
{
   PF_DAL_MountDevice,
   PF_DAL_ShutDown,
   MapWindow,
   EraseBlock_INTEL,
   NULL, //ProgramData_INTEL,    ProgramData_SIB
   NonBlockEraseBlock_INTEL,
   CheckDeviceReady_INTEL,
   #ifdef __UBL__
   NULL,
   NULL,
   #else
   PF_DAL_SuspendErase,
   PF_DAL_ResumeErase,
   #endif
   NULL, //BlankCheck_SIB
   NULL,
   NULL,
   LockEraseBlkAddr_INTEL,
   NULL //IsEraseSuspended_INTEL, is not used in FDM(ESB)
};
#endif //!__MINI_BOOTLOADER__ && !__COMBO_MEMORY_SUPPORT__



#ifdef __COMBO_MEMORY_SUPPORT__

#ifdef NOR_FLASH_TYPE_INTEL_SERIES

kal_int32 ADMUX_DAL_Init_INTEL(NOR_MTD_Driver *driver, PF_MTD_Data *data)
{
   PF_Status          *map;
   
   *driver = NORFlashMtd_INTEL;
   #if !defined(__MINI_BOOTLOADER__)
   driver->ProgramData = ProgramData_INTEL;
   data->CMD->CMD_ReadStatus = PF_DAL_Dev_ReadStatus_INTEL;
   data->CMD->Resume = INTEL_CMD_RESUME;
   data->CMD->Suspend = INTEL_CMD_SUSPEND;
   map = (PF_Status*)data->StatusMap;  
   map[PF_SR_READY] = PF_INTEL_SR_READY;
   #endif

   return CMEM_NO_ERROR;
}
#endif

#ifdef __INTEL_SIBLEY__
kal_int32 ADMUX_DAL_Init_INTEL_SIBLEY(NOR_MTD_Driver *driver, PF_MTD_Data *data)
{
   PF_Status		   *map;
 
   *driver = NORFlashMtd_INTEL;
   #if !defined(__MINI_BOOTLOADER__)
   driver->ProgramData = ProgramData_SIB;
   driver->BlankCheck = BlankCheck_SIB;
   data->CMD->CMD_ReadStatus = PF_DAL_Dev_ReadStatus_INTEL;
   data->CMD->Resume = INTEL_CMD_RESUME;
   data->CMD->Suspend = INTEL_CMD_SUSPEND;
   map = (PF_Status*)data->StatusMap;  
   map[PF_SR_READY] = PF_INTEL_SR_READY;
   #endif

   return CMEM_NO_ERROR;
}
#endif 

#endif //!__COMBO_MEMORY_SUPPORT__


#endif //__INTEL_SERIES_NOR__

