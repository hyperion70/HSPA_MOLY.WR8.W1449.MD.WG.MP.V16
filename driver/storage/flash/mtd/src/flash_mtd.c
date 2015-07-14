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

/*******************************************************************************
 *
 * Filename:
 * ---------
 *	FlashConf.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is a flash MTD driver for AMD and Toshiba flash devices.
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
Forbidden to use kal_internal_api.h and tst_ltlcom.h in modules other than KAL.

[Check-in branch]
MAUI
MSBB_II_DEV

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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "DrvFlash.h"
#include "flash_mtd_internal.h"
#include "reg_base.h"
#include "us_timer.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "flash_mtd_ut.h"

#define CHECK_LOG_START(a)
#define CHECK_LOG_STOP(a)

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
kal_uint32 gNOR_ReturnReadyBegin   = 0;
kal_uint32 gNOR_ReturnReadyEnd     = NOR_DEFAULT_RETURN_READY_LATENCY;
#endif  /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

#ifdef NOR_RESUME_SUSPEND_INTERVAL
extern kal_uint32 resume_time_g;  // to store suspend time (Qbit) to satisfy tERS
#endif

kal_uint32 gNonBlockingEraseBlockAddr = INVALID_BLOCK_ADDR;

/*******************************************************************************
 * For NOR FDM Customized Setting
 *******************************************************************************/
#ifdef 	__NOR_IDLE_SWEEP__ 
void setIdleSweepThreshold(NOR_FLASH_DRV_Data * D, kal_uint32 MaxSectorsPerBlock)
{
   D->IdleSweepThreshold = 2 * MaxSectorsPerBlock;  	
}
#endif


/*******************************************************************************
 * For NOR FDM Unit test
 *******************************************************************************/
#if defined(__BASIC_LOAD_FLASH_TEST__)
#include "DrvFlash_UT.h"
//******************************************************************************
// FDM_UT_Item test mapping
// NOR_FDM_UT_RW_STRESS(0): 	R/W Stress Test
// NOR_FDM_UT_AUTO:				6 Hour Power Test (CFI test + 2 hr Normal Power On/Off testing + 2hr Random Power Loss test + 2hr Busy Power Loss test + Performance Profiling test)
// NOR_FDM_UT_AUTO_16HR: 
// NOR_FDM_UT_NORMAL_POWER_ON_OFF: Watch dog reset after program/erase operation is done
// NOR_FDM_UT_RANDOM_POWER_LOSS:   Watch dog reset randomly
// NOR_FDM_UT_BUSY_POWER_LOSS:     Watch dog reset during program/erase busy
// NOR_FDM_UT_CFI:                 Check Geometry setting by CFI information
// NOR_FDM_UT_PROFILING:           Read/Write performance profiling
// NOR_FDM_UT_ATE:                 Map to NOR_FDM_UT_RANDOM_POWER_LOSS r/w pattern and disable watch dog reset
// NOR_FDM_UT_BOOTROM:
// NOR_FDM_UT_OTP:
// NOR_FDM_UT_API:
//******************************************************************************
const kal_uint8 FDM_UT_Item = NOR_FDM_UT_AUTO;

#endif


#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) && defined(__MTK_TARGET__)
kal_uint32 NOR_Flash_Base_Address = 0;
#endif


/*******************************************************************//**
 * Get time duration (unit: qbit) spent in last execution of Flash_ReturnReady.
 * Purpose: L1 TDMA interrupt LISR will call this API to get the tolerant range
 *          for abnormal interrupt checking.
 *
 * @par Catagory:
 * NOR MTD (Sleep Mode Support)
 *
 * @par Change Log:
 * W09.17: Added (Stanley Chu)
 *
 * @remarks
 * 1. gNOR_ReturnReadyBegin and gNOR_ReturnReadyEnd are updated only if interrupt
 *    comes when flash is busy! If flash is busy or already suspended, they are
 *    NOT be updated to avoid overwriting the previous valid information.
 * 2. gNOR_ReturnReadyEnd will be reset when flash is resumed in normal mode to
 *    avoid giving wrong information to L1 in sleep mode.
 * 3. After this API is called, and flash is not erase/program-suspended by
 *    Flash_ReturnReady before next read, next read will get 0 (read-clear).
 * 4. In multi-bank FDM or old 2G scheme (before 09A), always return 0.
 **********************************************************************/
__nor_section_RAM kal_uint32 NOR_GetReturnReadyLatency(void)
{
   #if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

   kal_uint32 latency;

   if (gNOR_ReturnReadyEnd != NOR_DEFAULT_RETURN_READY_LATENCY)  // use gNOR_ReturnReadyEnd to judge if latency has ever been read.
   {
      latency = ust_get_duration(gNOR_ReturnReadyBegin, gNOR_ReturnReadyEnd);
      gNOR_ReturnReadyEnd = NOR_DEFAULT_RETURN_READY_LATENCY;

      return latency;
   }
   else
   {
      return 0;
   }

   #else  /* !__SINGLE_BANK_NOR_FLASH_SUPPORT__ */

   return 0;

   #endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */
}

#ifndef __NOR_FDM5__


__nor_section_RAM void * BlockAddress(void* DriverData, kal_uint32 BlockIndex)
{
   NOR_Flash_MTD_Data * D=DriverData;
   kal_uint32 addr  = 0;
   kal_uint32 region = 0, BlockUpperBound = 0;

   BlockUpperBound = D->RegionInfo[0].RegionBlocks;
   while(BlockUpperBound <= BlockIndex)
   {
      addr += D->RegionInfo[region].RegionBlocks * D->RegionInfo[region].BlockSize;
      region++;
      BlockUpperBound += D->RegionInfo[region].RegionBlocks;
   }
   addr += (BlockIndex - (BlockUpperBound-D->RegionInfo[region].RegionBlocks)) * D->RegionInfo[region].BlockSize;

   return (D->BaseAddr + addr);
}



#ifdef __SPANSION_NS_N__
__nor_section_RAM  kal_uint32 CalBlkAddr(void* DriverData, kal_uint32 Addr)
{
   NOR_Flash_MTD_Data * D=DriverData;
   kal_uint32 AddrLowBound=0, AddrUpperBound  = 0;
   kal_uint32 region = 0, StartBlkIndex = 0;

   Addr -= (kal_uint32)D->BaseAddr;

   /*calculate the start block index*/
   AddrUpperBound = (D->RegionInfo[region].RegionBlocks) * (D->RegionInfo[region].BlockSize);

   do{
      if (AddrUpperBound >= Addr)
         break;
      else
      {
         StartBlkIndex += D->RegionInfo[region].RegionBlocks;
         region++;
         AddrLowBound = AddrUpperBound;
         AddrUpperBound += D->RegionInfo[region].RegionBlocks * D->RegionInfo[region].BlockSize;
      }
   }while(D->RegionInfo[region].RegionBlocks != 0);

   if(D->RegionInfo[region].RegionBlocks == 0 )
   {
      ASSERT(0);
      return 0;
   }
   return (kal_uint32)D->BaseAddr + (Addr &(~(D->RegionInfo[region].BlockSize-1)));
}
#endif /*__SPANSION_NS_N__*/
#else  /*__NOR_FDM5__*/


__nor_section_RAM void * BlockAddress(void * DriverData, kal_uint32 BlockIndex)
{
   NOR_MTD_DATA * D = DriverData;
   if (BlockIndex >= (D->LayoutInfo->TotalBlks))
   {
      ASSERT(0);
      return 0;
   }

   return (D->BaseAddr + BlockIndex* (D->LayoutInfo->BlkSize) );
}


#endif /* !__NOR_FDM5__ */

/*-----------------------------------*/
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
#define INVALID_BLOCK_ENTRY (0xFFFFFFFF)


kal_bool NOR_FLASH_BUSY = KAL_FALSE;
kal_bool NOR_FLASH_SUSPENDED = KAL_FALSE;

__nor_section_RAM static kal_uint32 LookupAddress(void * DriveData, kal_uint32 BlockIndex)
{
   NOR_Flash_MTD_Data * D = DriveData;
   kal_uint32  addr = 0;
   static kal_uint32 replaced = 0;
   static kal_uint32 look_up_hit = 0;
   static kal_uint32 look_up_miss = 0;
   if( D->lookup_tbl[BlockIndex&(LOOKUP_TABLE_SIZE-1)][0].BlockIndex != INVALID_BLOCK_ENTRY )
   {
      if(D->lookup_tbl[BlockIndex&(LOOKUP_TABLE_SIZE-1)][0].BlockIndex != BlockIndex)
      {
         if(D->lookup_tbl[BlockIndex&(LOOKUP_TABLE_SIZE-1)][1].BlockIndex != INVALID_BLOCK_ENTRY)
         {
            if(D->lookup_tbl[BlockIndex&(LOOKUP_TABLE_SIZE-1)][1].BlockIndex != BlockIndex)
            {
               look_up_miss++;
               if( replaced & (0x1 << (BlockIndex&(LOOKUP_TABLE_SIZE-1))) )
               {
                  D->lookup_tbl[BlockIndex&(LOOKUP_TABLE_SIZE-1)][1].BlockIndex = BlockIndex;
                  addr = D->lookup_tbl[BlockIndex&(LOOKUP_TABLE_SIZE-1)][1].BaseAddress = (kal_uint32)BlockAddress(D, BlockIndex);
                  replaced &= ~(0x1 << (BlockIndex&(LOOKUP_TABLE_SIZE-1))); /* zero first */
               }
               else
               {
                  D->lookup_tbl[BlockIndex&(LOOKUP_TABLE_SIZE-1)][0].BlockIndex = BlockIndex;
                  addr = D->lookup_tbl[BlockIndex&(LOOKUP_TABLE_SIZE-1)][0].BaseAddress = (kal_uint32)BlockAddress(D, BlockIndex);
                  replaced |= 0x1 << (BlockIndex&(LOOKUP_TABLE_SIZE-1)); /* one first */
               }
            }
            else
            {
               look_up_hit++;
               addr = D->lookup_tbl[BlockIndex&(LOOKUP_TABLE_SIZE-1)][1].BaseAddress;
               replaced &= ~(0x1 << (BlockIndex&(LOOKUP_TABLE_SIZE-1))); /* zero first */
            }
         }
         else
         {
            look_up_miss++;
            D->lookup_tbl[BlockIndex&(LOOKUP_TABLE_SIZE-1)][1].BlockIndex = BlockIndex;
            addr = D->lookup_tbl[BlockIndex&(LOOKUP_TABLE_SIZE-1)][1].BaseAddress = (kal_uint32)BlockAddress(D, BlockIndex);
            replaced &= ~(0x1 << (BlockIndex&(LOOKUP_TABLE_SIZE-1))); /* zero first */
         }
      }
      else
      {
         look_up_hit++;
         addr = D->lookup_tbl[BlockIndex&(LOOKUP_TABLE_SIZE-1)][0].BaseAddress;
         replaced |= 0x1 << (BlockIndex&(LOOKUP_TABLE_SIZE-1)); /* one first */
      }
   }
   else
   {
      look_up_miss++;
      D->lookup_tbl[BlockIndex&(LOOKUP_TABLE_SIZE-1)][0].BlockIndex = BlockIndex;
      addr = D->lookup_tbl[BlockIndex&(LOOKUP_TABLE_SIZE-1)][0].BaseAddress = (kal_uint32)BlockAddress(D, BlockIndex);
      replaced |= 0x1 << (BlockIndex&(LOOKUP_TABLE_SIZE-1)); /* one first */
   }
   return addr;
}

#if defined(__MULTI_BANK_NOR_DEVICE__)
__nor_section_RAM void MapBank(NOR_Flash_MTD_Data * D)
{
   kal_uint32 offset = (kal_uint32)D->CurrAddr - (kal_uint32)D->BaseAddr;
   kal_uint32 Partiton =0;
   kal_uint32 Addr=0;
   kal_uint32 BankAddrUpperBound = D->BankInfo[Partiton].BankSize * D->BankInfo[Partiton].Banks;

   while(offset >= BankAddrUpperBound )
   {
      Addr += BankAddrUpperBound;
      offset -= BankAddrUpperBound;
      Partiton++;
      BankAddrUpperBound = D->BankInfo[Partiton].BankSize * D->BankInfo[Partiton].Banks;
   }
   Addr += ((offset/D->BankInfo[Partiton].BankSize)*D->BankInfo[Partiton].BankSize);
   D->CurrBankAddr = D->BaseAddr + Addr;
   D->CurrBankSize = D->BankInfo[Partiton].BankSize;
   return;
}
#endif // __MULTI_BANK_NOR_DEVICE__
__nor_section_RAM void * MapWindow(void * DriveData, kal_uint32 BlockIndex, kal_uint32 WindowIndex)
{
   NOR_Flash_MTD_Data * D = DriveData;

   /* MapWindow: window index greater zero */
   ASSERT(WindowIndex == 0);
   D->CurrAddr = (void *)LookupAddress(D, BlockIndex);

#if defined(__MULTI_BANK_NOR_DEVICE__)
   if (((kal_uint32)D->CurrAddr) < ((kal_uint32)D->CurrBankAddr) ||
      ((kal_uint32)D->CurrAddr) >= ((kal_uint32)D->CurrBankAddr + (kal_uint32)D->CurrBankSize))
   {
      MapBank(D);
   }
   if(((kal_uint32)D->CurrAddr) == ((kal_uint32)D->CurrBankAddr) )
   {
      D->CurrPollAddr = (void*)((kal_uint32)D->CurrBankAddr+(kal_uint32)D->CurrBankSize - 4);
   }
   else
   {
      D->CurrPollAddr = D->CurrBankAddr;
   }
#endif // __MULTI_BANK_NOR_DEVICE__

   return D->CurrAddr;
}

#else /* !__SINGLE_BANK_NOR_FLASH_SUPPORT__ */
__nor_section_RAM void * MapWindow(void * DriveData, kal_uint32 BlockIndex, kal_uint32 WindowIndex)
{
   NOR_Flash_MTD_Data * D = DriveData;

   /* MapWindow: window index greater zero */
   ASSERT(WindowIndex == 0);
   return D->CurrAddr = BlockAddress(D, BlockIndex);
}
#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

#ifndef __NOR_FDM5__
__nor_section_RAM kal_uint32 BlockSize(void* DriveData, kal_uint32 BlockIndex)
{
   NOR_Flash_MTD_Data *D = DriveData;
   kal_uint32 region = 0, BlockUpperBound = 0;

   BlockUpperBound = D->RegionInfo[region].RegionBlocks;
   while(BlockUpperBound <= BlockIndex)
   {
      region++;
      BlockUpperBound += D->RegionInfo[region].RegionBlocks;
   }

   return (D->RegionInfo[region].BlockSize);
}

__nor_section_RAM kal_uint32 BlockIndex(void* DriveData, kal_uint32 blk_addr)
{
   NOR_Flash_MTD_Data *D = DriveData;
   kal_uint32     region = 0, BlockUpperAddr = 0;
   kal_uint32     blk_idx = 0;

   BlockUpperAddr = D->RegionInfo[region].RegionBlocks * D->RegionInfo[region].BlockSize;

   while( (BlockUpperAddr < blk_addr) && (D->RegionInfo[region].BlockSize) )
   {
      blk_idx += D->RegionInfo[region].RegionBlocks;
      blk_addr -= BlockUpperAddr;
      region++;
      BlockUpperAddr = D->RegionInfo[region].RegionBlocks*D->RegionInfo[region].BlockSize;
   }

   if(BlockUpperAddr >= blk_addr)
   {
      blk_idx += blk_addr / D->RegionInfo[region].BlockSize;
   }
   else
      blk_idx = INVALID_BLOCK_INDEX;
   return blk_idx;
}
#else /*__NOR_FDM5__*/

__nor_section_RAM kal_uint32 BlockSize(void * DriverData, kal_uint32 BlockIndex)
{
   NOR_MTD_DATA   *D = DriverData;

   if (BlockIndex >= (D->LayoutInfo->TotalBlks))
   {
      ASSERT(0);
      return 0;
   }

   return (D->LayoutInfo->BlkSize);
}
__nor_section_RAM kal_uint32 BlockIndex(void* DriverData, kal_uint32 blk_addr)
{
   NOR_MTD_DATA   *D = DriverData;
   kal_uint32     region = 0, BlockUpperAddr = 0;
   kal_uint32     blk_idx = 0;

   blk_idx = blk_addr / D->LayoutInfo->BlkSize;

   return blk_idx;
}
#endif /* !__NOR_FDM5__ */


// Non-blocking erase must located in FDM region
// Other MTD user are not allow to use non-blocking erase
#if !defined(_NAND_FLASH_BOOTING_) && !defined(__UBL__) && !defined(__FUE__) && !defined(__FS_SYSDRV_ON_NAND__) && !(defined(__SMART_PHONE_PLATFORM__)&&defined(__SMART_PHONE_MODEM__))
__nor_section_RAM void waitNonBlockEraseDone()
{
   extern NOR_FLASH_DRV_Data FlashDriveData;
   NOR_Flash_MTD_Data *D = (NOR_Flash_MTD_Data *)FlashDriveData.MTDData;
	
   if(gNonBlockingEraseBlockAddr != INVALID_BLOCK_ADDR)
   {
      while(FlashDriveData.MTDDriver->CheckDeviceReady(D, BlockIndex(D, gNonBlockingEraseBlockAddr - (kal_uint32)D->BaseAddr) ) != FS_NO_ERROR);
   }
   
   gNonBlockingEraseBlockAddr = INVALID_BLOCK_ADDR;
   
}
#endif // !_NAND_FLASH_BOOTING_ && !__UBL__


// Since flash_mtd_sf.c already has one CompareData
// Avoid duplicated defined by wrap compile option
#ifndef __SERIAL_FLASH__
kal_bool CompareData(void * Address, void * Data, kal_uint32 Length)
{
    kal_uint32 i;

    if(((kal_uint32)Address&0x3)==0 && ((kal_uint32)Data&0x3)==0)
    {
       kal_uint32* Source = (kal_uint32*)Address;
       kal_uint32* Dest = (kal_uint32*)Data;

       for(i=0;i<(Length>>2);i++)
       {
          if(Source[i] != Dest[i])
          	return KAL_TRUE;
       }
    }
    else if(((kal_uint32)Address&0x1)==0 && ((kal_uint32)Data&0x1)==0)
    {
       kal_uint16* Source = (kal_uint16*)Address;
       kal_uint16* Dest = (kal_uint16*)Data;

       for(i=0;i<(Length>>1);i++)
       {
          if(Source[i] != Dest[i])
          	return KAL_TRUE;
       }
    }
    else
    {
       kal_uint8* Source = (kal_uint8*)Address;
       kal_uint8* Dest = (kal_uint8*)Data;

       for(i=0;i<Length;i++)
       {
          if(Source[i] != Dest[i])
          	return KAL_TRUE;
       }
    }

    return KAL_FALSE;
}
#endif // !__SERIAL_FLASH__



#if defined(__SERIAL_FLASH__) && defined(__MTK_TARGET__)

__nor_section_SECOND_PART kal_uint32 get_ROM_BASE(void)
{
   #if (defined(__FUE__) && defined(__FOTA_DM__)) || defined(__UBL__)
   return 0;
   #else
   ////Sync with INT_RetrieveFlashBaseAddr(init_memory_stack.c) in MAUI
   extern kal_uint32 Image$$ROM$$Base;

   return ((kal_uint32)(&Image$$ROM$$Base) & 0xf8000000);
   #endif
}

__nor_section_SECOND_PART kal_uint32 get_NOR_FLASH_BASE_ADDRESS(void)
{
   return NOR_FLASH_BASE_ADDRESS;
}

__nor_section_SECOND_PART kal_uint32 get_NOR_ALLOCATED_FAT_SPACE(void)
{
   return NOR_ALLOCATED_FAT_SPACE;
}


#endif //__SERIAL_FLASH__ && __MTK_TARGET__


//To Do: avoid smart phone modem load to reference NOR MTD
#if (defined(__AMD_SERIES_NOR__) || defined(__SERIAL_FLASH__))

#if !defined(__UBL__)  // When build bootloader, KAL function does not exist!
/*******************************************************************//**
 * Enhanced delay function (Unit: us)
 *
 * @par Catagory:
 * General
 *
 * @par Change Log:
 * W08.29: Disable frame facility temporarily (use QBit only now) because TMD_System_Clock does not exist
 *         in FOTA environment. Better solution to retrieve frame number is required!
 *
 * @par Todo:
 * Use for-loop to extend the delay range
 *
 * @param[in] delay Time to delay (Unit: us)
 *
 * @remarks
 * This function is based on TDMA timing mechansim, i.e., It needs TDMA Qbit number to operate.
 *
 * @returns
 * Return if delay time is totally exhausted.
 *
 **********************************************************************/
__nor_section_RAM void DelayAWhile_UST(kal_uint32 delay)
{
    kal_uint32             start_qbit;      ///< Starting TDMA Qbit
    kal_uint32             curr_qbit;       ///< Current TDMA Qbit
    kal_uint32             elapse_qbit;     ///< Elapse number of Qbit

   // Qbit may not be ready in system initialization stage, use for-loop instead
   if (kal_query_systemInit()) {

      // minimum delay is 5
      if (delay < 5)
         delay = 5;

      // delay = delay / 5 ~= delay * 52 / 2^8;
      delay = (delay * 52) >> 8;

      // for-loop to wait
      for (; delay > 0; --delay)
         for (curr_qbit = COUNTER_05US; curr_qbit > 0; --curr_qbit);

      return;
   }

   // Read start qbit
   start_qbit = ust_get_current_time();

   /*******************************************************************//**
    * Calculate how many qbit should be waited. Store the result to "delay".
    * delay = delay * 13 / 12 ~= delay * 13 * 21.3333 / 2^8
    * => Limit: Maximum delay is 15,449,521 us = 15,449 ms = 15 sec
    ***********************************************************************/

   // delay * 13 * 21.333 ~= delay * 278
   delay = delay * 278;

   // delay / 2^8 ~= (delay >> 8) + 1 (for saving code, add one more qbit in all cases. Actually we only have to do such thing when "delay & 255 == 1"
   delay = (delay >> 8) + 1;

   // wait until "delay" qbits are all elapsed
   do {
      curr_qbit   = ust_get_current_time();
      elapse_qbit = ust_get_duration(start_qbit, curr_qbit);
   } while (elapse_qbit < delay);

   return;
}


#else /* __UBL__ */

__nor_section_RAM void DelayAWhile_UST(kal_uint32 delay)
{
   kal_uint32             curr_qbit;       ///< Current TDMA Qbit

   // minimum delay is 5
   if (delay < 5)
      delay = 5;

   // delay = delay / 5 ~= delay * 52 / 2^8;
   delay = (delay * 52) >> 8;

   // for-loop to wait
   for (; delay > 0; --delay)
      for (curr_qbit = COUNTER_05US; curr_qbit > 0; --curr_qbit);

}

#endif /* !__UBL__ */

#endif /* __AMD_SERIES_NOR__ || __SERIAL_FLASH__ */


#if defined(__BASIC_LOAD_FLASH_TEST__)
char mtd_msg_g[200];
char mtd_inst_g[200];

/*******************************************************************//**
 * Show readable NOR flash related error message
 *
 * @par Catagory:
 * NOR MTD
 *
 * @note
 * 1. Make sure flash is ready before this function is called.
 *    Because print function is not located in RAM!
 **********************************************************************/
__nor_section_RAM void MTD_PrintAssertInfo(void)
{
   dbg_print("\n============ NOR Flash Fatal Error ============\n");
   dbg_print(mtd_msg_g);
   dbg_print(mtd_inst_g);
   dbg_print("===============================================\n");
}
/*******************************************************************//**
 * Generate readable NOR flash related error message
 *
 * @par Catagory:
 * NOR MTD
 *
 * @note
 * 1. This function is only enabled in basic load.
 * 2. Make sure to put this function on RAM because of flash busy issue.
 **********************************************************************/
__nor_section_RAM void MTD_GenerateAssertInfo(kal_uint32 err_code)
{
   kal_uint32  instruction = 1;

   /* generate assert description */
   switch (err_code)
   {
      case NOR_MTD_ERASE_FAIL:
         kal_sprintf(mtd_msg_g, "ERROR: Erase block failed!\n");
         break;

      case NOR_MTD_ERASE_POLL_BUSY_FAIL:
         kal_sprintf(mtd_msg_g, "ERROR: Erase block failed. DQ6 stops toggling but DQ7 is always ZERO!\n");
         instruction = 3;
         break;

      case NOR_MTD_ERASE_TIMEOUT:
         kal_sprintf(mtd_msg_g, "ERROR: Erase block timeout!\n");
         instruction = 3;
         break;

      case NOR_MTD_ERASE_COMP_DATA_FAIL:
         kal_sprintf(mtd_msg_g, "ERROR: Erase block is not successful. Data compare failed!\n");
         instruction = 3;
         break;

      case NOR_MTD_ERASE_COMP_BLOCK_DATA_FAIL:
         kal_sprintf(mtd_msg_g, "ERROR: Erase block is not successful. Non-0xFF data is found in erasing block!\n");
         instruction = 3;
         break;

      case NOR_MTD_PROGRAM_COMP_DATA_FAIL:
         kal_sprintf(mtd_msg_g, "ERROR: Program is not successful. Data compare failed!\n");
         break;

      case NOR_MTD_PROGRAM_WRITE_BUFFER_FAIL:
         kal_sprintf(mtd_msg_g, "ERROR: Program is not successful. Write to buffer failed!\n");
         break;

      case NOR_MTD_DATA_CORRUPTED:
         kal_sprintf(mtd_msg_g, "ERROR: Signature mismatch. MTD data is corrupted!\n");
         break;

      case NOR_MTD_RAM_ROM_CONTENTS_UNMATCH:
         kal_sprintf(mtd_msg_g, "ERROR: The contents of ROM and RAM are different. Flash ready test failed!\n");
         break;

      case NOR_MTD_BANK_REGION_INFO_UNMATCH:
         kal_sprintf(mtd_msg_g, "ERROR: BankInfo is unmatched to RegionInfo!\n");
         instruction = 2;
         break;

      default:
         break;
   }

   /* generate instructions */
   if (instruction == 1) {
      kal_sprintf(mtd_inst_g, "INSTRUCTION: Please read back raw image, then send it with Hyper Terminal log to WCT/SE2/CS5 for further analysis, thanks.\n");

   } else if (instruction == 2) {
      kal_sprintf(mtd_inst_g, "INSTRUCTION: Please check custom files and memory database again, thanks.\n");

   } else if (instruction == 3) {
      kal_sprintf(mtd_inst_g, "INSTRUCTION: Please contact NOR flash vendor, thanks.\n");
   }
}

#endif // __BASIC_LOAD_FLASH_TEST__ 
