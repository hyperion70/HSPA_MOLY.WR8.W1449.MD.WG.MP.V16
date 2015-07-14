/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *	flash_disk.C
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This is the NOR Flash raw disk code
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
 *==============================================================================
 ****************************************************************************/
#if defined(__MTK_TARGET__)

#include "flash_opt.h"

#if !defined(_NAND_FLASH_BOOTING_)  && !defined(__EMMC_BOOTING__)  && !defined(__SMART_PHONE_MODEM__)

//__SMART_MD_NFI_DRIVER__: Use NAND flash but do not define _NAND_FLASH_BOOTING_ to force NOR booting flow

/********************************************************/
/*                  Include Header Files                */
/********************************************************/
#include "flash_disk_internal.h"
#include "flash_mtd_internal.h"
#include "flash_disk.h"
#include "fs_errcode.h"

#ifdef __UBL__
volatile kal_uint32 processing_irqCnt;
#endif //__UBL__

/*---------------------------------------------------------------
 * flag to indicate if flash is mounted
 * set to KAL_TRUE in MountDevice(), set to KAL_FALSE in ShutDown()
 *--------------------------------------------------------------*/

extern NOR_FLASH_DISK_Data EntireDiskDriveData;
extern void waitNonBlockEraseDone();

#define ENTIRE_DISK_DRIVER_DATA &EntireDiskDriveData

#if defined(__SYSDRV_BACKUP_DISK_RAW__) && !defined(__UBL__)
static kal_uint32 BackupPartitionStatus = BACKUP_DISK_STATUS_EMPTY;
static kal_bool BP_is_mount = KAL_FALSE;	//only one Backup Partition in system, use a global var instead of tie with data structure
static kal_uint32 currW, currR;
#endif //__SYSDRV_BACKUP_DISK_RAW__ && !__UBL__

#define RAW_DISK0_DRIVER_DATA &FlashDiskDriveData[RAW_DISK0]
#define TC01_DISK_DRIVER_DATA &FlashDiskDriveData[TC01_DISK]

#ifdef __CUSTOMER_TC01_DISK__
kal_uint32 tc01_logical_block_size_ratio = 0;
kal_uint32 tc01_page_per_block = 0;
#endif //__CUSTOMER_TC01_DISK__

#if (!defined(__FUE__) && !defined(__UBL__))

void create_FDM_lock()
{
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) || defined(__NOR_IDLE_SWEEP__)
   CreateFDMLock();
#else //MB && ! idle sweep
   if (fdm_reclaim_mutex==KAL_NILMUTEX_ID)
      fdm_reclaim_mutex = kal_create_mutex("MutexReclaim");
#endif // __SINGLE_BANK_NOR_FLASH_SUPPORT__ || __NOR_IDLE_SWEEP__
}

/*****************************************************************
Description : acquire FDM synchronization lock.
Input       :
Output      : None
******************************************************************/
void retrieve_FDM_lock(void)
{
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) || defined(__NOR_IDLE_SWEEP__)

   extern void GetFDMLock(void);
   GetFDMLock();

#elif defined(__NOR_FDM5__)

   extern void nFDM_LOCK(void);
   nFDM_LOCK();

#else

   extern void FDM_LOCK(void);
   FDM_LOCK();

#endif
}

/*****************************************************************
Description : relieve FDM synchronization lock.
Input       :
Output      : None
******************************************************************/
void release_FDM_lock(void)
{
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) || defined(__NOR_IDLE_SWEEP__)

   extern void FreeFDMLock(void);
   FreeFDMLock();

#elif defined(__NOR_FDM5__)

   extern void nFDM_UNLOCK(void);
   nFDM_UNLOCK();

#else

   extern void FDM_UNLOCK(void);
   FDM_UNLOCK();

#endif
}
#else // __FUE__ && __UBL__

#define create_FDM_lock()
#define retrieve_FDM_lock()
#define release_FDM_lock()

#endif //!__FUE__ && !__UBL__


/*******************************************************************//**
 * Invoke before flash read/write/erase operation.
 * used when __NOR_SUPPORT_RAW_DISK__ or __UBL_NOR_FULL_DRIVER__ is defined.
 * accessed by backup partition and LG partition. (!__UBL__)
 * also access LG partition in bootloader (__UBL__ || __UBL_NOR_FULL_DRIVER__)
 **********************************************************************/
static void MountDevice(NOR_FLASH_DISK_Data *D)
{
   kal_int32 Result;

#ifndef __UBL__
   if(D->is_mount && INT_QueryExceptionStatus() == KAL_FALSE)
      return;
   create_FDM_lock();

   retrieve_FDM_lock();
   
#else //__UBL__

   if(D->is_mount)
      return;

#endif //__UBL__

   Result = D->MTDDriver->MountDevice(D->MTDData, (void*)&D->FlashInfo);

   release_FDM_lock();

   if (Result < FS_NO_ERROR)
      ASSERT(0);

   D->is_mount = KAL_TRUE;
}


/*******************************************************************//**
 * Read data from flash raw disk
 *
 * @par Catagory:
 * NOR RAW DISK
 *
 * @param[in] disk The number of disk to be read
 * @param[in] addr Start address relative to specified disk
 * @param[in] data_ptr Buffer for storing read data
 * @param[in] len The size of data_ptr
 *
 * @remarks
 * 1. File system non-block operation will be finished and then do raw disk read opertaion
 *
 * @return
 * RAW_DISK_ERR_WRONG_ADDRESS: Illegal read address
 * RAW_DISK_ERR_NONE: Read successful
 **********************************************************************/
kal_int32 readRawDiskData(NOR_FLASH_DISK_Data *D, kal_uint32 addr, kal_uint8* data_ptr, kal_uint32 len)
{

   kal_uint32 phyAddr;
   kal_uint32 diskSize = D->DiskSize;

   if(addr >= diskSize || addr+len > diskSize)
   {
      return RAW_DISK_ERR_WRONG_ADDRESS;
   }
   phyAddr = (kal_uint32)((NOR_Flash_MTD_Data*)D->MTDData)->BaseAddr + addr;

   if(!D->is_mount)
   {
      MountDevice(D);
   }

   retrieve_FDM_lock();
   waitNonBlockEraseDone(); //if file system is mount, wait non-blocking erase ready if any

   kal_mem_cpy(data_ptr, (void *)phyAddr, len);

   release_FDM_lock();

   return RAW_DISK_ERR_NONE;
}


#if !defined(__MINI_BOOTLOADER__) && (defined(__NOR_SUPPORT_RAW_DISK__)||defined(__NOR_FULL_DRIVER__))

/*******************************************************************//**
 * Write data into flash raw disk
 *
 * @par Catagory:
 * NOR RAW DISK
 *
 * @param[in] disk The number of disk to be read
 * @param[in] addr Start address relative to specified disk
 * @param[in] data_ptr Buffer for storing read data
 * @param[in] len The size of data_ptr
 *
 * @remarks
 * 1. File system non-block operation will be finished and then do raw disk read opertaion
 *
 * @return
 * RAW_DISK_ERR_WRONG_ADDRESS: Illegal program start address
 * RAW_DISK_ERR_NO_SPACE: No enough space to write len bytes data
 * RAW_DISK_ERR_PROG_FAIL: Program fail
 * RAW_DISK_ERR_NONE: Program successful
 **********************************************************************/

#if defined(__INTEL_SIBLEY__)

#ifdef __UBL__
//FDM is not exist, declare a 1KB buffer for Sibley
kal_uint8 SIBLEY_BUFFER[1024];
#else //!__UBL__
extern NOR_FLASH_DRV_Data FlashDriveData;
#define SIBLEY_BUFFER FlashDriveData.Buffer
#endif //__UBL__

#endif //__INTEL_SIBLEY__


kal_int32 writeRawDiskData(NOR_FLASH_DISK_Data *D, kal_uint32 addr, kal_uint8* data_ptr, kal_uint32 len)
{
   kal_uint32 dest,src;
   kal_uint32 diskSize = D->DiskSize;
   kal_int32 result = FLASH_DISK_DONE;
   kal_uint32 DoneLength=0;

   if(addr >= diskSize)
   {
      return RAW_DISK_ERR_WRONG_ADDRESS;
   }

   if(addr+len > diskSize)
      return RAW_DISK_ERR_NO_SPACE;

   if(!D->is_mount)
   {
      MountDevice(D);
   }

   retrieve_FDM_lock();

   while ( DoneLength < len )
   {
      dest = (kal_uint32)((NOR_Flash_MTD_Data*)D->MTDData)->BaseAddr + addr + DoneLength;
      src = (kal_uint32)data_ptr+DoneLength;

      D->MTDDriver->MapWindow(D->MTDData, BlockIndex((void*)D->MTDData,addr+DoneLength), 0);

      // if dest address not word align or write length is one, write one byte at a time
      if ( ((kal_uint32)dest&(sizeof(FLASH_CELL)-1)) || ((len-DoneLength)==1) )
      {
         result = D->MTDDriver->ProgramData(D->MTDData, (void *)dest, (void *)src, 1);
         if(result != FLASH_DISK_DONE )
         {
            break;
         }
         DoneLength++;
      } // dest address is word align
      else
      {
         kal_uint32 blockSize = BlockSize(D->MTDData,BlockIndex(D->MTDData, addr + DoneLength));
         kal_uint32 programBytes = len-DoneLength;
         //calculate the block address boundary
         kal_uint32 nextBlkAddr = (dest+ blockSize) & (~(blockSize -1));

#ifdef __INTEL_SIBLEY__
         kal_uint32 nextRegionAddr = (dest+1024) & (~(1024-1));

#endif // __INTEL_SIBLEY__  

         //if the data write across block boundary, shrink into a block
         if ( dest+programBytes > (nextBlkAddr))
            programBytes = nextBlkAddr - dest;

#ifndef __INTEL_SIBLEY__
         //round down to multiple of word
         programBytes = (programBytes)&(~(sizeof(FLASH_CELL)-1));
#else // __INTEL_SIBLEY__
         if(dest+programBytes > nextRegionAddr)
            programBytes = nextRegionAddr - dest;
         if(programBytes & 0x1)    //the length is odd, use FDM buffer as temp buffer
         {
            kal_mem_cpy(SIBLEY_BUFFER,(void*)src,programBytes);
            SIBLEY_BUFFER[programBytes] = 0xFF;
         }
#endif // __INTEL_SIBLEY__  


         // program a word should be word align (MTD limitation)
         if(programBytes == sizeof(FLASH_CELL) &&  (src%sizeof(FLASH_CELL)))
         {
            FLASH_CELL Cell;
            kal_uint8 *b = (kal_uint8*) &Cell;
            b[0] = *((kal_uint8*)src);
            b[1] = *((kal_uint8*)src+1);
            result = D->MTDDriver->ProgramData(D->MTDData, (void *)dest, (void *)&Cell, programBytes);
            if(result != FLASH_DISK_DONE )
            {
               break;
            }
         }
         else
         {
            if(programBytes & 0x1)   //must be Sibley flash
            {
#ifdef __INTEL_SIBLEY__
               result = D->MTDDriver->ProgramData(D->MTDData, (void *)dest, (void *)SIBLEY_BUFFER, programBytes+1);
#else
               ASSERT(0);
#endif
            }
            else
            {
               result = D->MTDDriver->ProgramData(D->MTDData, (void *)dest, (void *)src, programBytes);
            }
            if(result != FLASH_DISK_DONE )
            {
               break;
            }
         }
         DoneLength += programBytes;
      }
   }

   release_FDM_lock();

   if(result != FLASH_DISK_DONE )
   {
      return RAW_DISK_ERR_PROG_FAIL;
   }
   return RAW_DISK_ERR_NONE;

}

/*******************************************************************//**
 * Erase a block of flash raw disk
 *
 * @par Catagory:
 * NOR RAW DISK
 *
 * @param[in] disk The number of disk to be read
 * @param[in] blkIdx The block index to be erased
 *
 * @remarks
 * 1. File system non-block operation will be finished and then do raw disk read opertaion
 *
 * @return
 * RAW_DISK_ERR_WRONG_ADDRESS: Illegal block index to be erased
 * RAW_DISK_ERR_ERASE_FAIL: Erase fail
 * RAW_DISK_ERR_NONE: Program successful
 **********************************************************************/
kal_int32 eraseRawDiskBlock(NOR_FLASH_DISK_Data *D, kal_uint32 blkIdx)
{

   kal_int32 result;

   if(!D->is_mount)
   {
      MountDevice(D);
   }

   if(blkIdx >= D->FlashInfo.TotalBlocks)   //TotalBlocks are initialized in MountDevice()
   {
      return RAW_DISK_ERR_WRONG_ADDRESS;
      //ASSERT(0); //how to output msg?
   }

   retrieve_FDM_lock();//same as fota's function

   D->MTDDriver->MapWindow(D->MTDData, blkIdx, 0);

   result = D->MTDDriver->EraseBlock(D->MTDData,blkIdx);

   release_FDM_lock();

   if(result == FLASH_DISK_DONE )
      return RAW_DISK_ERR_NONE;
   return RAW_DISK_ERR_ERASE_FAIL;
}

#endif //!__MINI_BOOTLOADER__ && (__NOR_SUPPORT_RAW_DISK__ || __NOR_FULL_DRIVER__)


#if defined(__CUSTOMER_TC01_DISK__) && !defined(__UBL__) && !defined(__FUE__)

/*******************************************************************//**
 * Read data from flash TC01_DISK disk (raw disk)
 *
 * @par Catagory:
 * NOR RAW DISK
 *
 * @param[in] addr Start address relative to TC01_DISK disk
 * @param[in] data_ptr Buffer for storing read data
 * @param[in] len The size of data_ptr
 *
 * @return
 * RAW_DISK_ERR_WRONG_ADDRESS: Illegal read address
 * RAW_DISK_ERR_NONE: Read successful
 **********************************************************************/
kal_int32 ReadRawDataItem(kal_uint32 block_idx, kal_uint32 page_idx, kal_uint32 length, kal_uint8* data_ptr)
{
   NOR_FLASH_DISK_Data * D = TC01_DISK_DRIVER_DATA;
   NOR_Flash_MTD_Data *mtdData = (NOR_Flash_MTD_Data*)D->MTDData;
   kal_uint32 addr;

   //TC01 Disk size may larger than physical block size
   //tc01_logical_block_size_ratio = logical block size of TC01 disk / physical block size
   //Assume physical block in TC01 disk is uniform block (blocks with the same size)
   if(tc01_logical_block_size_ratio == 0)
      tc01_logical_block_size_ratio = TC01_DISK_BLOCK_SIZE / BlockSize(mtdData, 0);

   if(tc01_page_per_block == 0)
      tc01_page_per_block = BlockSize(mtdData, 0) / TC01_DISK_PAGE_SIZE ;


   block_idx = block_idx * tc01_logical_block_size_ratio + page_idx/tc01_page_per_block;
   page_idx = page_idx % tc01_page_per_block;

   //addr is Start address relative to TC01_DISK disk
   addr = ((kal_uint32)BlockAddress((void*)mtdData , block_idx) - (kal_uint32)mtdData->BaseAddr)  + (page_idx << TC01_DISK_PAGE_SHIFT);

   return readRawDiskData(D,addr,data_ptr,length);
}

kal_int32 WriteRawDataItem(kal_uint32 block_idx, kal_uint32 page_idx, kal_uint32 length, kal_uint8* data_ptr)
{
   NOR_FLASH_DISK_Data * D = TC01_DISK_DRIVER_DATA;
   NOR_Flash_MTD_Data *mtdData = (NOR_Flash_MTD_Data*)D->MTDData;
   kal_uint32 addr;

   if(tc01_logical_block_size_ratio == 0)
      tc01_logical_block_size_ratio = TC01_DISK_BLOCK_SIZE / BlockSize(mtdData, 0);

   if(tc01_page_per_block == 0)
      tc01_page_per_block = BlockSize(mtdData, 0) / TC01_DISK_PAGE_SIZE ;


   block_idx = block_idx * tc01_logical_block_size_ratio + page_idx/tc01_page_per_block;
   page_idx = page_idx % tc01_page_per_block;

   //addr is Start address relative to TC01_DISK disk
   addr = ((kal_uint32)BlockAddress((void*)mtdData , block_idx) -  (kal_uint32)mtdData->BaseAddr)  + (page_idx << TC01_DISK_PAGE_SHIFT);

   return writeRawDiskData(D,addr,data_ptr,length);
}


/*******************************************************************//**
 * Erase a block of flash TC01_DISK disk (raw disk)
 *
 * @par Catagory:
 * NOR RAW DISK
 *
 * @param[in] block_baseaddr The block address to be erased
 *
 * @remarks
 *
 * @return
 * RAW_DISK_ERR_WRONG_ADDRESS: Illegal block index to be erased
 * RAW_DISK_ERR_ERASE_FAIL: Erase fail
 * RAW_DISK_ERR_NONE: Program successful
 **********************************************************************/

kal_int32 EraseRawDataItem(kal_uint32 block_idx)
{
   NOR_FLASH_DISK_Data * D = TC01_DISK_DRIVER_DATA;
   kal_int32 result, i;

   if(tc01_logical_block_size_ratio == 0)
      tc01_logical_block_size_ratio = TC01_DISK_BLOCK_SIZE / BlockSize(D->MTDData, 0);

   block_idx = block_idx * tc01_logical_block_size_ratio;

   for(i = 0; i < tc01_logical_block_size_ratio; i++)
   {
      result = eraseRawDiskBlock(TC01_DISK_DRIVER_DATA,block_idx+i);
      if(result != RAW_DISK_ERR_NONE)
         break;
   }

   return result;
}
#endif //__CUSTOMER_TC01_DISK__ && !__UBL__ && !__FUE__


#if defined(__SYSDRV_BACKUP_DISK_RAW__) && !defined(__UBL__) && !defined(__FUE__)
/****************************************************************************/
/*                                                                          */
/*            Support NOR Flash Backup Partition Function                   */
/*                                                                          */
/****************************************************************************/


#ifndef __INTEL_SIBLEY__

static void readBackupData(kal_uint32 addr, kal_uint8* data_ptr, kal_uint32 len)
{
   kal_uint32 result;
   result = readRawDiskData(RAW_DISK0_DRIVER_DATA,addr,data_ptr,len);
   if(result != RAW_DISK_ERR_NONE)
      ASSERT(0);
}

static void writeBackupData(kal_uint8* data_ptr, kal_uint32 len)
{
   kal_uint32 result;
   result = writeRawDiskData(RAW_DISK0_DRIVER_DATA,currW,data_ptr,len);
   if(result != RAW_DISK_ERR_NONE)
      ASSERT(0);
   currW += len;
}

#else //__INTEL_SIBLEY__
static void readBackupData(kal_uint32 addr, kal_uint8* data_ptr, kal_uint32 len)
{
   kal_uint32 readLen;
   NOR_FLASH_DISK_Data * D = RAW_DISK0_DRIVER_DATA;
   kal_uint32 bufIdx = D->bufIdx;
   kal_uint32 diskSize = D->DiskSize;

   if(addr > diskSize || (addr + len) > diskSize)
      ASSERT(0);

   if(BackupPartitionStatus == BACKUP_DISK_STATUS_LOCK)
   {
      readRawDiskData(D,addr,data_ptr,len);
      return;
   }

   //make sure address range is reasonable (data write into flash and buffer)
   if((addr + len) > currW+bufIdx)
      memset(data_ptr,0xFF,len);

   //all in flash
   if(addr < currW && (addr + len) <= currW)
      readRawDiskData(D,addr,data_ptr,len);
   else if(addr < currW)   //half in flash
   {
      readLen = currW - addr;
      readRawDiskData(D,addr,data_ptr,readLen);
      memcpy(data_ptr+readLen, D->Buffer,len-readLen);
   }
   else    //all in buffer
   {
      memcpy(data_ptr, D->Buffer+addr-currW,len);
   }
}


/*******************************************************************//**
 * Write backup item into NOR flash RAW_DISK0 or Sibley Buffer
 *
 * @par Catagory:
 * NOR RAW DISK (Sibley)
 *
 * @param[in] data_ptr Buffer for storing read data
 * @param[in] len The size of data_ptr
 *
 * @remarks
 * 1. Assert if program fail
 *
 **********************************************************************/
static void writeBackupData(kal_uint8* data_ptr, kal_uint32 len)
{
   kal_uint32 left = len;
   NOR_FLASH_DISK_Data * D = RAW_DISK0_DRIVER_DATA;
   kal_int32 result;

   while(left)
   {
      kal_uint32 bufIdx = D->bufIdx;
      //write to flash by using user's buffer
      if(bufIdx == 0 && left >= SIBLEY_REGION_SIZE)
      {
         result = writeRawDiskData(D, currW, data_ptr+(len-left), SIBLEY_REGION_SIZE);
         if(result != RAW_DISK_ERR_NONE)
            ASSERT(0);
         currW+=SIBLEY_REGION_SIZE;
         left -= SIBLEY_REGION_SIZE;
      }
      else
      {
         //write to buffer byte by byte
         if(left+bufIdx >= SIBLEY_REGION_SIZE)
         {
            kal_mem_cpy((void *)(D->Buffer + bufIdx),(void *)((kal_uint32)data_ptr+len-left),SIBLEY_REGION_SIZE-bufIdx);
            //dump to flash if write buffer full
            result = writeRawDiskData(D, currW, D->Buffer, SIBLEY_REGION_SIZE);
            if(result != RAW_DISK_ERR_NONE)
               ASSERT(0);

            //update currW, currW is the index of write point in flash (virtual disk)
            currW += SIBLEY_REGION_SIZE;
            left -= SIBLEY_REGION_SIZE-bufIdx;

            //reset buffer
            D->bufIdx = 0;
            memset(D->Buffer, 0xFF, SIBLEY_REGION_SIZE);

         }
         else
         {
            kal_mem_cpy((void *)(D->Buffer + bufIdx),(void *)((kal_uint32)data_ptr+len-left),left);

            D->bufIdx += left;
            //left = 0;
            break;
         }
      }
   }//left
}

static void lockBackupData()
{
   NOR_FLASH_DISK_Data * D = RAW_DISK0_DRIVER_DATA;
   kal_uint32 lockRegionAddr = D->DiskSize - SIBLEY_REGION_SIZE;
   kal_int32 result;
   FLASH_CELL cell;
   cell = LOCK_MARK;

   //flush buffer data to NOR flash if valid data is in Buffer and the buffer is not the latest region of NOR flash
   if(D->bufIdx != 0 && currW != lockRegionAddr)
   {
      result = writeRawDiskData(D, currW, D->Buffer, SIBLEY_REGION_SIZE);
      if(result != RAW_DISK_ERR_NONE)
         ASSERT(0);
      currW += SIBLEY_REGION_SIZE;
      memset(D->Buffer, 0xFF, SIBLEY_REGION_SIZE);
      D->bufIdx=0;
   }

   //write locked mark to the end of Buffer
   kal_mem_cpy((void *)(D->Buffer+SIBLEY_REGION_SIZE-sizeof(cell)),(void *)&cell, sizeof(cell));

   //write buffer to NOR flash
   result = writeRawDiskData(D, lockRegionAddr, D->Buffer, SIBLEY_REGION_SIZE);
   if(result != RAW_DISK_ERR_NONE)
      ASSERT(0);
}
#endif //__INTEL_SIBLEY__


void initBackupPartition()
{
   NOR_FLASH_DISK_Data * D = RAW_DISK0_DRIVER_DATA;
   kal_uint32 region;
   FLASH_CELL cell;

   //initial data structure
   if(!D->is_mount)
   {
      MountDevice(D);
   }

   //erase all blocks in backup partition
   for(region = 0; region < D->FlashInfo.ActualRegionNum; region++)
   {
      kal_uint32 i;
      for (i=0; i<D->FlashInfo.RegionBlocks[region]; i++)
      {
         eraseRawDiskBlock(D, i);
      }
   }

#ifdef __INTEL_SIBLEY__
   D->Buffer =  (kal_uint8 *)get_ctrl_buffer(SIBLEY_REGION_SIZE);
   memset(D->Buffer,0xFF,SIBLEY_REGION_SIZE);
#endif //__INTEL_SIBLEY__

   //write init mark
   cell = INIT_MARK;
   currW = 0;

   writeBackupData((kal_uint8*) &cell, sizeof(cell));
   currR = 2;

   //set status init
   BackupPartitionStatus = BACKUP_DISK_STATUS_INIT;
   BP_is_mount = KAL_TRUE;
}


/*******************************************************************//**
 * Read data from flash backup partition
 *
 * @par Catagory:
 * NOR RAW DISK
 *
 * @param[in] ID ID of data item to be read
 * @param[in] data_ptr Buffer for storing read data
 * @param[in] len The size of data_ptr
 *
 * @remarks
 * 1. File system non-block operation will be finished and then do raw disk read opertaion
 *
 * @return
 * Lenght of data item ID
 * 0 if no such item
 **********************************************************************/
kal_int32 readBackupPartition(kal_uint16 ID, kal_uint8* data_ptr, kal_uint32 len )
{
   FLASH_CELL cell;
   kal_uint32 length,readLen;
   kal_uint32 startCurrR = currR;
   kal_bool found  = KAL_FALSE;
   kal_int32 status;

   //init backup partition variable
   status = getBackupPartitionStatus();
   if(status == BACKUP_DISK_STATUS_EMPTY)
      return 0; //no data

   //find the data with the same LID
   do
   {
      readBackupData(currR,(kal_uint8*)&cell,sizeof(cell));
      if(cell == ID)
      {
         readBackupData(currR+2,(kal_uint8*)&length,sizeof(length));
         found = KAL_TRUE;
         break;
      }
      else if(cell != 0xFFFF)    //find next
      {
         readBackupData(currR+2,(kal_uint8*)&length,sizeof(length));
         currR += length + BACKUP_HEADER; //ID+len+data => 2+4+len
      }
      else    //rotate the head, circular read
      {
         currR = 2;
      }
   }
   while(startCurrR!=currR);

   if(found)
   {
      readLen = (length>len)?len:length;
      readBackupData(currR+BACKUP_HEADER,data_ptr,readLen);
      return readLen;
   }

   return 0 ;

}

/*******************************************************************//**
 * Write backup item into NOR flash RAW_DISK0
 *
 * @par Catagory:
 * NOR RAW DISK
 *
 * @param[in] ID ID of data item to be read
 * @param[in] data_ptr Buffer for storing read data
 * @param[in] len The size of data_ptr
 *
 * @remarks
 * 1. Assert if program fail
 *
 * @return
 * RAW_DISK_ERR_NO_INIT: Backup partition is not in init state (cannot write at empty or locked status)
 * RAW_DISK_ERR_NO_SPACE: No enough space to write backup item
 * RAW_DISK_ERR_NONE: Program successful
 **********************************************************************/
kal_int32 writeBackupPartition(kal_uint16 ID, kal_uint8* data_ptr, kal_uint32 len)
{
   NOR_FLASH_DISK_Data * D = RAW_DISK0_DRIVER_DATA;
   kal_uint32 diskSize = D->DiskSize;
   kal_int32 status;

   status = getBackupPartitionStatus();

   if(status != BACKUP_DISK_STATUS_INIT)
      return RAW_DISK_ERR_NO_INIT;  //not writable
   if(diskSize < currW+BACKUP_HEADER+len)
      return RAW_DISK_ERR_NO_SPACE;  //space not enough

   //LID
   writeBackupData((kal_uint8*)&ID,sizeof(ID));
   //len
   writeBackupData((kal_uint8*)&len,sizeof(len));
   //data
   writeBackupData(data_ptr, len);

   return RAW_DISK_ERR_NONE;
}


void lockBackupPartition()
{
   NOR_FLASH_DISK_Data * D = RAW_DISK0_DRIVER_DATA;
   kal_uint32 diskSize = D->DiskSize;
   kal_int32 status;
   FLASH_CELL cell;

   status = getBackupPartitionStatus();

   if(status != BACKUP_DISK_STATUS_INIT)
      ASSERT(0); //backup partition not init, cannot lock

   readRawDiskData(RAW_DISK0_DRIVER_DATA,diskSize-2,(kal_uint8*)&cell,sizeof(cell));

   if(cell != 0xFFFF)
   {
      ASSERT(0); //cannot write lock mark
   }

   //write lock mark
   cell = LOCK_MARK;
#ifndef __INTEL_SIBLEY__
   writeRawDiskData(D, diskSize-sizeof(cell), (kal_uint8*)&cell, sizeof(cell));
#else
   lockBackupData();
#endif
   currR = 2;

#ifdef __INTEL_SIBLEY__
   free_ctrl_buffer(D->Buffer);
#endif //__INTEL_SIBLEY__

   //set status locked
   BackupPartitionStatus = BACKUP_DISK_STATUS_LOCK;
   BP_is_mount = KAL_TRUE;

}



/*******************************************************************//**
 * Get backup partition status
 *
 * @par Catagory:
 * NOR RAW DISK
 *
 * @remarks
 * 1. Assert if program fail
 *
 * @return
 * EMPTY: Backup partition not initilized, cannot read or write
 * INIT: Backup partition initlized, can do read/write/lock
 * LOCK: Backup partition locked, can do read/init
 **********************************************************************/
kal_int32 getBackupPartitionStatus()
{
   NOR_FLASH_DISK_Data * D =RAW_DISK0_DRIVER_DATA;
   kal_uint32 diskSize = D->DiskSize;

   FLASH_CELL cell;

   if(BP_is_mount)
      return BackupPartitionStatus;

   //the first backup partition operation after mount, check backup partition INIT/LOCK mark for status
   currW = currR = 0;
   readRawDiskData(RAW_DISK0_DRIVER_DATA,0,(kal_uint8*)&cell,sizeof(cell));
   if(cell != INIT_MARK)
   {
      BackupPartitionStatus = BACKUP_DISK_STATUS_EMPTY;
   }
   else
   {
      readRawDiskData(RAW_DISK0_DRIVER_DATA,diskSize-sizeof(cell),(kal_uint8*)&cell,sizeof(cell));
      if(cell == LOCK_MARK)
      {
         BackupPartitionStatus = BACKUP_DISK_STATUS_LOCK;
         currR = 2;
      }
      else if(cell == 0xFFFF)
      {
         BackupPartitionStatus = BACKUP_DISK_STATUS_INIT;
         currR = 2;
#ifndef __INTEL_SIBLEY__
         currW = 2;
#endif
         //scan partition to see the latest write
      }
      else
      {
         ASSERT(0); //wrong lock mark
      }
   }

   BP_is_mount = KAL_TRUE;


   return BackupPartitionStatus;
}

#endif //__SYSDRV_BACKUP_DISK_RAW__ && !__UBL__ && !__FUE__

extern void Custom_NOR_Init(void);
kal_int32 NOR_init (void)
{
   Custom_NOR_Init();
   MountDevice(ENTIRE_DISK_DRIVER_DATA);
   return ERROR_NOR_SUCCESS;
}

kal_int32 NOR_ReadPhysicalPage (kal_uint32 block_idx, kal_uint32 page_idx, kal_uint8 * data_ptr)
{
   NOR_FLASH_DISK_Data * D = ENTIRE_DISK_DRIVER_DATA;
   NOR_Flash_MTD_Data *mtdData = (NOR_Flash_MTD_Data*)D->MTDData;
   kal_int32 result;

   kal_uint32 addr = ((kal_uint32)BlockAddress((void*)mtdData , block_idx) - (kal_uint32)mtdData->BaseAddr)  + (page_idx<<NOR_FLASH_PAGE_SHIFT);

   result = readRawDiskData(D, addr, data_ptr, NOR_FLASH_PAGE_SIZE);

   if(result!=RAW_DISK_ERR_NONE) return ERROR_NOR_READ;
   return ERROR_NOR_SUCCESS;
}

#if defined(__NOR_FULL_DRIVER__) && !defined(__MINI_BOOTLOADER__)
kal_int32 NOR_ProgramPhysicalPage (kal_uint32 block_idx, kal_uint32 page_idx, kal_uint8 * data_ptr)
{
   NOR_FLASH_DISK_Data * D = ENTIRE_DISK_DRIVER_DATA;
   NOR_Flash_MTD_Data *mtdData = (NOR_Flash_MTD_Data*)D->MTDData;
   kal_int32 result;

   kal_uint32 addr = ((kal_uint32)BlockAddress((void*)mtdData , block_idx) -  (kal_uint32)mtdData->BaseAddr)  + (page_idx<<NOR_FLASH_PAGE_SHIFT);

   result = writeRawDiskData(D,addr,data_ptr,NOR_FLASH_PAGE_SIZE);
   if(result!=RAW_DISK_ERR_NONE) return ERROR_NOR_PROGRAM;
   return ERROR_NOR_SUCCESS;
}

kal_int32 NOR_ErasePhysicalBlock (kal_uint32 block_idx)
{
   kal_int32 result;
   result = eraseRawDiskBlock(ENTIRE_DISK_DRIVER_DATA, block_idx);
   if(result!=RAW_DISK_ERR_NONE) return ERROR_NOR_ERASE;
   return ERROR_NOR_SUCCESS;
}
#endif //__UBL_NOR_FULL_DRIVER__

kal_uint32 NOR_BlockSize(kal_uint32 block_idx)
{
   NOR_FLASH_DISK_Data * D = ENTIRE_DISK_DRIVER_DATA;
   NOR_Flash_MTD_Data *mtdData = (NOR_Flash_MTD_Data*)D->MTDData;
   return BlockSize(mtdData, block_idx);
}

kal_uint32 NOR_BlockIndex(kal_uint32 block_addr)
{
   NOR_FLASH_DISK_Data * D = ENTIRE_DISK_DRIVER_DATA;
   NOR_Flash_MTD_Data *mtdData = (NOR_Flash_MTD_Data*)D->MTDData;

   return BlockIndex(mtdData, block_addr);
}

#ifdef __UBL__
extern kal_int32 EMI_QueryIsRemapped(void);
extern kal_uint32 custom_RAM_baseaddr(void); //BANK 1; after remapping, NOR flash will be map to BANK 1
#endif

// Return value:
//    ERROR_NOR_OVERRANGE: address out of NOR flash size
//    ERROR_NOR_SUCCESS: block_addr to *block_index, *offset translation successful
kal_int32 NOR_Addr2BlockIndexOffset(kal_uint32 block_addr, kal_uint32 *block_index, kal_uint32 *offset)
{
   NOR_FLASH_DISK_Data * D = ENTIRE_DISK_DRIVER_DATA;
   NOR_Flash_MTD_Data *mtdData = (NOR_Flash_MTD_Data*)D->MTDData;

   #ifdef __UBL__
   if(EMI_QueryIsRemapped())
      block_addr = block_addr & (~custom_RAM_baseaddr()); 
   #endif

   *block_index = BlockIndex(mtdData, block_addr);
   if(*block_index == INVALID_BLOCK_INDEX)
      return ERROR_NOR_OVERRANGE;

   *offset = block_addr % BlockSize(mtdData, *block_index);

   return ERROR_NOR_SUCCESS;
}

// Translate block_index and offset to block address (*addr)
// Return value:
//    ERROR_NOR_SUCCESS
kal_int32 NOR_BlockIndexOffset2Addr(kal_uint32 block_index, kal_uint32 offset, kal_uint32 *addr)
{
   NOR_FLASH_DISK_Data * D = ENTIRE_DISK_DRIVER_DATA;
   NOR_Flash_MTD_Data *mtdData = (NOR_Flash_MTD_Data*)D->MTDData;

   *addr = (kal_uint32)BlockAddress(mtdData, block_index) -  (kal_uint32)mtdData->BaseAddr + offset;

   return ERROR_NOR_SUCCESS;
}



//-----------------------------------------------------------------------------------------------
// Raw Disk API/ TC01 Disk/ Backup Partition Unit Test
//-----------------------------------------------------------------------------------------------
//#define NOR_RAW_DISK_UNIT_TEST
#define NOR_RAW_DISK_UNIT_TEST_REPEAT KAL_TRUE
//#define NOR_RAW_DISK_UNIT_TEST_REPEAT KAL_FALSE


#ifdef NOR_RAW_DISK_UNIT_TEST

#include "DrvFlash_UT.h"
#include "kal_public_api.h"

#include "custom_MemoryDevice.h"

#define BUFF_SIZE 2048
kal_uint8 buff[BUFF_SIZE];
kal_uint8 buff2[BUFF_SIZE];

#define dbg_text text

extern char text[200];

#define TC01_DISK_PAGE_PER_BLOCK (TC01_DISK_BLOCK_SIZE/TC01_DISK_PAGE_SIZE)
//return KAL_TRUE if data is not consistant

extern NOR_FLASH_DISK_Data EntireDiskDriveData;

extern kal_bool CompareData(void * Address, void * Data, kal_uint32 Length);

void NOR_CUSTOMER_TC01_DISK_Unit_Test(void);

void  NOR_Full_Driver_Unit_Test(void);


void NOR_Raw_Disk_Unit_Test(void)
{
   while(NOR_RAW_DISK_UNIT_TEST_REPEAT)
   {

	  basic_log("----- Read Raw Disk API UT Start -----\n\r");


      NOR_Full_Driver_Unit_Test();


      //basic_log("----- Raw Disk API UT Start -----\n\r");
      //TBD

      NOR_CUSTOMER_TC01_DISK_Unit_Test();

      //basic_log("----- Backup Partition UT Start -----\n\r");
      //TBD

	  basic_log("----- Read Raw Disk API UT End -----\n\r");


//   basic_log("NOR_Raw_Disk_Unit_Test Finished.\n\r");



      kal_sleep_task(10);
   }
}


#if defined(__NOR_FULL_DRIVER__) && !defined(__MINI_BOOTLOADER__)

void  NOR_Full_Driver_Unit_Test(void)
{

   kal_uint32 i,j;
   kal_uint32 addr = 0;
   kal_uint32 pageIdx, blkIdx, blkSize;
   kal_uint32 totalBlk = 0;

   

   NOR_init();


   for(blkIdx = 0; blkIdx < EntireDiskDriveData.FlashInfo.TotalBlocks ; blkIdx++)
   {
   
      for(pageIdx = 0; pageIdx < NOR_BlockSize(blkIdx)/NOR_FLASH_PAGE_SIZE; pageIdx++)
      {
         NOR_ReadPhysicalPage(blkIdx, pageIdx,buff);

		 if(CompareData(buff, (kal_uint8*)addr, NOR_FLASH_PAGE_SIZE))
		    ASSERT(0);
		 
		 addr += NOR_FLASH_PAGE_SIZE;
	  }
   }

}
#else

void  NOR_Full_Driver_Unit_Test(void){;}


#endif


#ifdef __UBL__


kal_bool CompareData(void * Address, void * Data, kal_uint32 Length)
{
    kal_uint32 i;

    if((kal_uint32)Address&0x3==0 && (kal_uint32)Data&0x3==0)
    {
       kal_uint32* Source = (kal_uint32*)Address;
       kal_uint32* Dest = (kal_uint32*)Data;
       for(i=0;i<(Length>>2);i++)
       {
          if(Source[i] != Dest[i])
          	 return KAL_TRUE;
       }
    }
    else if((kal_uint32)Address&0x1==0 && (kal_uint32)Data&0x1==0)
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


#endif //__UBL__


#ifdef __CUSTOMER_TC01_DISK__
void NOR_CUSTOMER_TC01_DISK_Unit_Test(void)
{

   kal_uint32 i,j;
   

   basic_log("----- TC01 Disk UT Start -----\n\r");

   basic_log("[1] Erase all blocks.\n\r");

   for(i = 0 ; i < NOR_BOOTING_NOR_DISK1_SIZE / TC01_DISK_BLOCK_SIZE; i++)
   {
      EraseRawDataItem(i);
	  kal_sleep_task(10);
   }

   basic_log("[2] Write page data sequencial.\n\r");

   for(i = 0 ; i < NOR_BOOTING_NOR_DISK1_SIZE / TC01_DISK_BLOCK_SIZE; i++)
   {
      for(j = 0; j < TC01_DISK_PAGE_PER_BLOCK; j++)
      {
         kal_mem_set(buff, i*TC01_DISK_PAGE_PER_BLOCK+j, BUFF_SIZE);
         WriteRawDataItem(i,j, BUFF_SIZE/(j+1), buff);
         ReadRawDataItem(i,j, BUFF_SIZE, buff2);
         if(KAL_TRUE == CompareData(buff,buff2,BUFF_SIZE/(j+1)))
            ASSERT(0);
		 kal_sleep_task(10);
      }
   }

   basic_log("[3] Check page data .\n\r");

   for(i = 0 ; i < NOR_BOOTING_NOR_DISK1_SIZE / TC01_DISK_BLOCK_SIZE; i++)
   {
      for(j = 0; j < TC01_DISK_PAGE_PER_BLOCK; j++)
      {
         kal_mem_set(buff, i*TC01_DISK_PAGE_PER_BLOCK+j, BUFF_SIZE);
         ReadRawDataItem(i,j, BUFF_SIZE, buff2);
         if(KAL_TRUE == CompareData(buff,buff2,BUFF_SIZE/(j+1)))
            ASSERT(0);
		 kal_sleep_task(10);
      }
   }

   basic_log("[4] Erease block one by one.\n\r");

   for(i = 0 ; i < NOR_BOOTING_NOR_DISK1_SIZE / TC01_DISK_BLOCK_SIZE; i++)
   {
      for(j = 0; j < TC01_DISK_PAGE_PER_BLOCK; j++)
      {
         kal_mem_set(buff, i*TC01_DISK_PAGE_PER_BLOCK+j, BUFF_SIZE);
         ReadRawDataItem(i,j, BUFF_SIZE, buff2);
         if(KAL_TRUE == CompareData(buff,buff2,BUFF_SIZE/(j+1)))
            ASSERT(0);
      }

      EraseRawDataItem(i);

      kal_mem_set(buff, 0xff, BUFF_SIZE);

      for(j = 0; j < TC01_DISK_PAGE_PER_BLOCK; j++)
      {
         ReadRawDataItem(i,j,BUFF_SIZE, buff2);
         if(KAL_TRUE == CompareData(buff,buff2,BUFF_SIZE))
            ASSERT(0);
      }
	  kal_sleep_task(10);
   }



}
#else !__CUSTOMER_TC01_DISK__
void NOR_CUSTOMER_TC01_DISK_Unit_Test(void)
{
   ;
}
#endif //__CUSTOMER_TC01_DISK__



#endif //NOR_RAW_DISK_UNIT_TEST



#endif //!_NAND_FLASH_BOOTING_ && !__EMMC_BOOTING__ && !__SMART_PHONE_PLATFORM__
#endif // __MTK_TARGET__
