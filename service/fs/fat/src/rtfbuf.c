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
 *   rtfiles.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file contains core functions of file system.
 *
 * Author:
 * -------
 *
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *============================================================================
 ****************************************************************************/

/**************************************************************************/
/*                                                                        */
/*  File: BUFFERS.C                              Copyright (c) 1998,2002  */
/*  Version: 4.0                                 On Time Informatik GmbH  */
/*                                                                        */
/*                                                                        */
/*                                      On Time        /////////////----- */
/*                                    Informatik GmbH /////////////       */
/* --------------------------------------------------/////////////        */
/*                                  Real-Time and System Software         */
/*                                                                        */
/**************************************************************************/

/*
 * Include
 */
#include "kal_public_api.h" //MSBB change #include "kal_release.h"

#include "fs_gprot.h"
#include "fs_internal_api.h"
#include "rtfiles.h"
#include "rtfex.h"
#include "rtfbuf.h"
#include "fs_utility.h"
#include "fs_kal.h"
#include "kal_trace.h"
#include "fs_trc.h"

/*
 * Macro
 */

// Trace
#define fs_util_trace_err_noinfo(error_code) fs_util_trace_err_slim(error_code, rtfbuf_c, __LINE__)


// Assert
#define fs_assert_local(expr) fs_assert(expr, rtfbuf_c)
#define fs_ext_assert_local(expr, e1, e2, e3) fs_ext_assert(expr, rtfbuf_c, e1, e2, e3)

#ifdef _MSC_VER
   #define INTERN _fastcall
#elif defined __BORLANDC__
   #define INTERN __fastcall
#else
   #define INTERN
#endif
#define B_FREE    0x00
#define B_VALID   0x01   // buffer has valid data
#define B_DIRTY   0x02   // buffer has valid data and must be written to disk
#define B_INUSE   0x04   // buffer is being accessed by RTFiles
#define B_BUSY    0x08   // buffer is being accessed by a device driver
#define B_SINGLE  0x10   // single buffer for emergent use only /* Guarantee fixed disk access, Karen Hsu, 2005/05/19 */


/*
 * Locals
 */

#ifdef __FS_DEBUG__
static RTFBufferStatistic BufferStat = { 0 };
#endif
static RTFBuffer * FirstBuffer = NULL;
#ifdef __FS_DEDICATED_BUFFER__
   RTFMutex *MTMemLock = NULL;
#endif

#if !defined(__MTK_TARGET__) || defined(GEN_FOR_PC) || defined(__RESOURCE_GEN_) || defined(NVRAM_AUTO_GEN)
    #define __fs_cache_align(x)
#elif defined(__ARMCC_VERSION)
    #define __fs_cache_align(x)   __align(x)
#elif defined(__GNUC__)
    #ifdef __DYNAMIC_SWITCH_CACHEABILITY_
    #define __fs_cache_align(x)   __attribute__ ((aligned(x), zero_init, section ("NONCACHEDZI")))
    #else
    #define __fs_cache_align(x)   __attribute__ ((aligned(x)))
    #endif
#endif

#if !defined(__GNUC__) && defined(__DYNAMIC_SWITCH_CACHEABILITY__)
#pragma arm section zidata = "NONCACHEDZI"
#endif // !__GNUC__ && __DYNAMIC_SWITCH_CACHEABILITY__

#ifdef __FS_CARD_SUPPORT__
   #ifndef _NAND_FLASH_BOOTING_
      #define __FS_EMERGENT_NOR_BUFFER_SUPPORT__
      RTFBuffer g_Emergent_NOR_Buffer;
      __fs_cache_align(FS_CACHE_ALIGNMENT_OFFSET) BYTE g_Emergent_NOR_BufferData[RTF_MIN_BUFFER_SIZE];
   #endif
   #ifdef NAND_SUPPORT
      #define __FS_EMERGENT_NAND_BUFFER_SUPPORT__
      RTFBuffer g_Emergent_NAND_Buffer;
      __fs_cache_align(FS_CACHE_ALIGNMENT_OFFSET) BYTE g_Emergent_NAND_BufferData[RTF_MIN_BUFFER_SIZE];
   #endif
      #define __FS_EMERGENT_CARD_BUFFER_SUPPORT__
      RTFBuffer g_Emergent_Card_Buffer;
      __fs_cache_align(FS_CACHE_ALIGNMENT_OFFSET) BYTE g_Emergent_Card_BufferData[RTF_MIN_BUFFER_SIZE];
#else
   #if (defined NAND_SUPPORT) && !(defined _NAND_FLASH_BOOTING_)
      #define __FS_EMERGENT_NOR_BUFFER_SUPPORT__
      RTFBuffer g_Emergent_NOR_Buffer;
      __fs_cache_align(FS_CACHE_ALIGNMENT_OFFSET) BYTE g_Emergent_NOR_BufferData[RTF_MIN_BUFFER_SIZE];
      #define __FS_EMERGENT_NAND_BUFFER_SUPPORT__
      RTFBuffer g_Emergent_NAND_Buffer;
      __fs_cache_align(FS_CACHE_ALIGNMENT_OFFSET) BYTE g_Emergent_NAND_BufferData[RTF_MIN_BUFFER_SIZE];
   #endif
#endif /* __FS_CARD_SUPPORT__ */

#ifdef __FS_DEDICATED_BUFFER__
BYTE  gFS_DedicatedBufferLock = 0;  // flag to indicate if FS dedicated buffer has been allocated
#endif /* __FS_DEDICATED_BUFFER__ */

#if !defined(__GNUC__) && defined(__DYNAMIC_SWITCH_CACHEABILITY__)
#pragma arm section zidata
#endif // !__GNUC__ && __DYNAMIC_SWITCH_CACHEABILITY__

/*-----------------------------------*/
static void INTERN UpFront(RTFBuffer * B)
{
/* Guarantee fixed disk access, Karen Hsu, 2005/05/19, ADD START */
   if (B->Flags & B_SINGLE)
      return;
/* Guarantee fixed disk access, Karen Hsu, 2005/05/19, ADD END */

   if (B != FirstBuffer)
   {
      // unlink it
      B->Prev->Next = B->Next;
      B->Next->Prev = B->Prev;

      // link into front
      B->Next = FirstBuffer;
      B->Prev = FirstBuffer->Prev;

      B->Next->Prev = B;
      B->Prev->Next = B;

      FirstBuffer = B;
   }
}

/*-----------------------------------*/
static void INTERN ToTail(RTFBuffer * B)
{
/* Guarantee fixed disk access, Karen Hsu, 2005/05/19, ADD START */
   if (B->Flags & B_SINGLE)
      return;
/* Guarantee fixed disk access, Karen Hsu, 2005/05/19, ADD END */

   if (B == FirstBuffer)
      FirstBuffer = FirstBuffer->Next;
   else
   {
      // unlink it
      B->Prev->Next = B->Next;
      B->Next->Prev = B->Prev;

      B->Next = FirstBuffer;
      B->Prev = FirstBuffer->Prev;

      B->Next->Prev = B;
      B->Prev->Next = B;
   }
}

/*******************************************************************//**
 * Unlink specified device's inuse buffer
 *
 * @par Category:
 * File System
 *
 * this is called by UnlockDevice, GetBuffer, SearchBuffer and SafeUnlock
 **********************************************************************/
void FreeBuffer(RTFDevice * Dev)
{
   if (Dev->DevData.B)
   {
      Dev->DevData.B->Flags &= ~B_INUSE;
      Dev->DevData.B = NULL;
   }
}

/*******************************************************************//**
 * Discard specified buffer
 *
 * @par Category:
 * File System
 *
 * This function handles related flags and links in buffer structure.
 **********************************************************************/
void DiscardOtherBuffer(RTFBuffer * B)
{

   /* Guarantee fixed disk access, Karen Hsu, 2005/05/19, ADD START */
   if (B->Flags & B_SINGLE)
      B->Flags = B_SINGLE;
   else
   /* Guarantee fixed disk access, Karen Hsu, 2005/05/19, ADD END */

      B->Flags = 0;
   B->recoverable_flag = RTF_NORMAL_WRITE;
   ToTail(B);
}

/*******************************************************************//**
 * Discard device's in-use buffer
 *
 * @par Category:
 * File System
 *
 * This function handles the device structure. Buffer structure is handled by DiscardOtherBuffer().
 **********************************************************************/
void DiscardBuffer(RTFDevice * Dev)
// this frees a buffer
{

   DiscardOtherBuffer(Dev->DevData.B);
   Dev->DevData.B = NULL;
}

/*-----------------------------------*/
void AllocBuffers(void)
{
   RTFBuffer * B;
   UINT i;

   if (FirstBuffer)
      return;

/* Guarantee fixed disk access, Karen Hsu, 2005/05/19, ADD START */
#ifdef __FS_EMERGENT_NOR_BUFFER_SUPPORT__
   g_Emergent_NOR_Buffer.Flags |= B_SINGLE;
   g_Emergent_NOR_Buffer.recoverable_flag = RTF_NORMAL_WRITE;
   g_Emergent_NOR_Buffer.Data = g_Emergent_NOR_BufferData;
#endif

#ifdef __FS_EMERGENT_NAND_BUFFER_SUPPORT__
   g_Emergent_NAND_Buffer.Flags |= B_SINGLE;
   g_Emergent_NAND_Buffer.recoverable_flag = RTF_NORMAL_WRITE;
   g_Emergent_NAND_Buffer.Data = g_Emergent_NAND_BufferData;
#endif
/* Guarantee fixed disk access, Karen Hsu, 2005/05/19, ADD END */

#ifdef __FS_EMERGENT_CARD_BUFFER_SUPPORT__  /* PATCH , WCP_SW, 2006/08/03, ADD BEGIN */
   g_Emergent_Card_Buffer.Flags |= B_SINGLE;
   g_Emergent_Card_Buffer.recoverable_flag = RTF_NORMAL_WRITE;
   g_Emergent_Card_Buffer.Data = g_Emergent_Card_BufferData;
#endif /* PATCH , WCP_SW, 2006/08/03, ADD END */

#ifdef __FS_DEBUG__
   BufferStat.TotalBuffers = FS_MAX_BUFFERS;
#endif

   #if 0 // [SLIM]
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif

   if (((DWORD) gFS_Data.BufferTable) % 4)
      fs_err_internal_fatal(FS_ERR_BUFFER_02, NULL);

   for (i=0; i<FS_MAX_BUFFERS; i++)
   {
      B = gFS_Data.BufferTable + i;
      B->Num = i;
      B->recoverable_flag = RTF_NORMAL_WRITE;
      B->Data = gFS_Data.BufferData + (i*RTF_MIN_BUFFER_SIZE);
      B->Next = B + 1;
      B->Prev = B - 1;
   }

   FirstBuffer = gFS_Data.BufferTable;

   FirstBuffer->Prev = FirstBuffer + FS_MAX_BUFFERS - 1;
   FirstBuffer->Prev->Next = FirstBuffer;
}

#ifdef __FS_DEBUG__

/*-----------------------------------*/
void RTFAPI RTFBufferInfo(RTFBufferStatistic * BufferInfo)
{
   RTFBuffer * B;

#ifdef DEBUG
   UINT Test = 0;
#endif

   if (FirstBuffer == 0)
      AllocBuffers();

   *BufferInfo = BufferStat;

   BufferInfo->CacheHits = BufferInfo->PhysicalBufferReads ? 100 * (BufferInfo->CachedBufferReads) / (BufferInfo->PhysicalBufferReads + BufferInfo->CachedBufferReads) : 0;

   BufferInfo->ValidBuffers = 0;

   B = FirstBuffer;
   do
   {
      if (B->Flags & B_VALID)
         BufferInfo->ValidBuffers++;
#ifdef DEBUG
      if (B->Flags & B_DIRTY)
         Test++;
#endif
      B = B->Next;
   } while (B != FirstBuffer);
#ifdef DEBUG
   if (Test != BufferStat.DirtyBuffers)
      fs_err_internal_fatal(FS_ERR_BUFFER_03, NULL);
#endif
}

#endif

/*-----------------------------------*/
static void INTERN ReadBuffer(RTFBuffer * B)
{


   XTRY
      case XCODE:
         B->Flags |= B_BUSY;
         rtf_core_read_sectors(B->Dev, B->Data, B->Sector, 1, 0);

         #ifdef __FS_DEBUG__
         BufferStat.PhysicalBufferReads++;
         #endif

         B->Flags |= B_VALID;
         break;
      default:
         ToTail(B);
         B->Flags &= ~B_INUSE;
         break;
      case XFINALLY:
         B->Flags &= ~B_BUSY;
         break;
   XENDX
}

/*******************************************************************//**
 * Write specified buffer to disk
 *
 * @par Category:
 * File System
 *
 * @remarks
 * If number of FAT table > 1, FAT table data will be "mirrored" to all other FAT tables!
 **********************************************************************/
static void INTERN WriteBuffer(RTFBuffer * B)
{
   #ifdef DEBUG
   if (B->Flags != (B_INUSE | B_VALID | B_DIRTY))
      fs_err_internal_fatal(FS_ERR_BUFFER_04, NULL);
   #endif

   XTRY
      case XCODE:

         B->Flags |= B_BUSY;

         // recoverable_flag indicates if it has to use recoverablewritesector or not
         if (B->recoverable_flag == RTF_RECOVERABLE_WRITE)
           rtf_core_write_sectors(B->Dev, B->Data, B->Sector, 1, 0, RTF_RECOVERABLE_WRITE);
         else
           rtf_core_write_sectors(B->Dev, B->Data, B->Sector, 1, 0, RTF_NORMAL_WRITE);

         // clear the recoverable_flag
         B->recoverable_flag = RTF_NORMAL_WRITE;

         /* clear dirty flag */
         B->Flags &= ~B_DIRTY;

         #ifdef __FS_DEBUG__
         BufferStat.PhysicalBufferWrites++;
         BufferStat.AsynchBufferFlushs += (B->FirstDirtyTime != B->Dev->DevData.AccessCount);
         BufferStat.DirtyBuffers--;
         #endif

         // check if this is a FAT sector and we have to
         // take care of other FATs
         // We will ignore any errors here, but we do want
         // critical errors.

         {
            int i, FATs;

            if ((B->FATSectorInfo) && ((B->Dev->DeviceFlags & RTF_DEVICE_SINGLE_FAT) == 0))
               FATs = B->FATSectorInfo->FATCount;
            else
               FATs = 1;

            if (FATs > 1)
            {
               if(B->Flags & B_SINGLE)
                   B->Flags = B_VALID | B_INUSE | B_BUSY | B_SINGLE;
               else
                   B->Flags = B_VALID | B_INUSE | B_BUSY;

               for (i=1; i<FATs; i++)
               {
                  rtf_core_write_sectors(B->Dev, B->Data, B->Sector + i * B->FATSectorInfo->SectorsPerFAT, 1, NO_RAISE, RTF_NORMAL_WRITE);
#ifdef __FS_DEBUG__
                  BufferStat.PhysicalBufferWrites++;
                  BufferStat.AsynchBufferFlushs += B->FirstDirtyTime != B->Dev->DevData.AccessCount;
#endif
               }
               if(B->Flags & B_SINGLE)
                   B->Flags = B_VALID | B_INUSE | B_SINGLE;
               else
                   B->Flags = B_VALID | B_INUSE;
            }
         }
         break;
      default: // only the first FAT can raise exceptions
         B->Flags &= ~B_INUSE;
         break;
      case XFINALLY:
         B->Flags &= ~B_BUSY;

         break;
   XENDX
}

void RTFAPI AdjustBuffer(void)
{
   RTFBuffer * B;

   FlushAllBuffers(gFS_Data.DriveTable[0].Dev);
   DiscardAllBuffers(gFS_Data.DriveTable[0].Dev);

   B = FirstBuffer->Next;
   do
   {
      B->Flags |= B_INUSE;
      B->Dev = 0x0;
      B = B->Next;
   }while (B != FirstBuffer);

   FirstBuffer->Next = FirstBuffer;
}

/*-----------------------------------*/
void *SearchBuffer(RTFDevice * Dev, RTFSector Sector)
{
   RTFBuffer * B;    // selected buffer

   #ifdef DEBUG
   if (!RTFSYSOwnMutex(RTFLock))
      fs_err_internal_fatal(FS_ERR_BUFFER_05, NULL);
   #endif

   if (Dev->DevData.B && (Dev->DevData.B->Sector == Sector))
      return Dev->DevData.B->Data;

/* Guarantee fixed disk access, Karen Hsu, 2005/05/19, ADD START */
#ifdef __FS_EMERGENT_NOR_BUFFER_SUPPORT__
   B = &g_Emergent_NOR_Buffer;
   if (B->Flags & B_VALID)
   {
      if ((B->Sector == Sector) && (B->Dev == Dev))
      {
         B->Flags |= B_INUSE;
         FreeBuffer(Dev);
         Dev->DevData.B = B;
         return B->Data;
      }
   }
#endif

#ifdef __FS_EMERGENT_NAND_BUFFER_SUPPORT__
   B = &g_Emergent_NAND_Buffer;
   if (B->Flags & B_VALID)
   {
      if ((B->Sector == Sector) && (B->Dev == Dev))
      {
         B->Flags |= B_INUSE;
         FreeBuffer(Dev);
         Dev->DevData.B = B;
         return B->Data;
      }
   }
#endif
/* Guarantee fixed disk access, Karen Hsu, 2005/05/19, ADD END */

#ifdef __FS_EMERGENT_CARD_BUFFER_SUPPORT__ /* PATCH , WCP_SW, 2006/08/03, ADD BEGIN */
   B = &g_Emergent_Card_Buffer;
   if (B->Flags & B_VALID)
   {
      if ((B->Sector == Sector) && (B->Dev == Dev))
      {
         B->Flags |= B_INUSE;
         FreeBuffer(Dev);
         Dev->DevData.B = B;
         return B->Data;
      }
   }
#endif /* PATCH , WCP_SW, 2006/08/03, ADD END */

   // search forward for the sector in question

   B = FirstBuffer;
   do
   {
      if (B->Flags & B_VALID)
      {
         if ((B->Sector == Sector) && (B->Dev == Dev))
         {
            #ifdef DEBUG
            if (B->Flags & (B_INUSE | B_BUSY))  // double allocation
               fs_err_internal_fatal(FS_ERR_BUFFER_06, NULL);
            #endif

            /* move matched buffer to the front, and set it as device's INUSE buffer */
            UpFront(B);
            B->Flags |= B_INUSE;
            FreeBuffer(Dev);
            Dev->DevData.B = B;
            return B->Data;
         }
      }
      else
         return NULL;
      B = B->Next;
   } while (B != FirstBuffer);
   return NULL;
}

/*-----------------------------------*/
void *GetBuffer(RTFDevice * Dev, RTFSector Sector, UINT Flags)
{
   RTFBuffer * B;    // selected buffer

   #ifdef DEBUG
   if (!RTFSYSOwnMutex(RTFLock))
      fs_err_internal_fatal(FS_ERR_BUFFER_07, NULL);
   if (Dev->DevData.AltBuffer)
      fs_err_internal_fatal(FS_ERR_BUFFER_08, NULL);
   #endif

   /* check if device's B pointer (INUSE buffer) is matched. */
   if ((Flags & ALT_BUFFER) == 0)
   {
      if (Dev->DevData.B)
      {
         if (Dev->DevData.B->Sector == Sector)
         {
            /* if device's INUSE buffer is matched, bingo! use it! */
            return Dev->DevData.B->Data;
         }
         else
         {
            /* if not matched, unlink it (clean INUSE flag and B pointer) */
            FreeBuffer(Dev);
         }
      }
   }

   // search forward for the sector in question or an invalid (free) buffer

   B = FirstBuffer;
   do
   {
      if (B->Flags != 0)
      {
         if ((B->Sector == Sector) && (B->Dev == Dev))
         {
            #ifdef __FS_DEBUG_CACHE__
            if (B->Flags & (B_INUSE | B_BUSY))  // double allocation
               fs_err_internal_fatal(FS_ERR_BUFFER_09, NULL);
            if ((B->Flags & B_VALID) == 0)
               fs_err_internal_fatal(FS_ERR_BUFFER_10, NULL);
            #endif

            #ifdef __FS_DEBUG__
            BufferStat.CachedBufferReads++;
            #endif

            B->Flags |= B_INUSE;

            goto SaveAndExit;
         }
      }
      else // not allocated buffers follow the first unallocated buffer
      {
         #ifdef __FS_DEBUG_CACHE__
         {
            RTFBuffer * B1 = B;
            do
            {
               if (B1->Flags != 0)
                  fs_err_internal_fatal(FS_ERR_BUFFER_11, NULL);
               B1 = B1->Next;
            }
            while (B1 != FirstBuffer);
         }
         #endif

         goto ReadAndExit;
      }
      B = B->Next;
   } while (B != FirstBuffer);

   #ifdef __FS_DEBUG__
   BufferStat.BuffersDiscarded++; // we have to discard one
   #endif

   // now search backwards (oldest first) for a buffer to discard:
   // for any buffer on the same device
   // or for a clean buffer

   B = FirstBuffer->Prev;
   do
   {
      if (((B->Flags & B_INUSE) == 0) &&   /* it's not in use and (we can't change other device's INUSE buffer!) */
          ((B->Dev == Dev) ||               /* it's occupied by this device or (to replace any buffer occupied by this device) */
           ((B->Flags & B_DIRTY) == 0)))    /* it's not dirty (to replace other device's non-INUSE and non-dirty buffer */
      {
         #ifdef __FS_DEBUG_CACHE__
         if (B->Flags & B_BUSY)
            fs_err_internal_fatal(FS_ERR_BUFFER_12, NULL);
         #endif

         /* flush buffer if it is dirty */
         if (B->Flags & B_DIRTY)
         {
            #ifdef __FS_DEBUG_CACHE__
            if (B->Dev != Dev)
               fs_err_internal_fatal(FS_ERR_BUFFER_13, NULL);
            #endif

            /* set INUSE flag because we will use this buffer later */
            B->Flags        |= B_INUSE;

            WriteBuffer(B);
         }
         goto ReadAndExit;
      }
      B = B->Prev;
   } while (B != FirstBuffer->Prev);

   /* B is FirstBuffer->Prev here */

/* Guarantee fixed disk access, Karen Hsu, 2005/05/19, ADD START */
#ifdef __FS_EMERGENT_NOR_BUFFER_SUPPORT__
   if(Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
   {
      B = &g_Emergent_NOR_Buffer;
      B->Flags |= B_INUSE;
      if ((B->Sector == Sector) && (B->Dev == Dev))
         goto SaveAndExit;
      else
         goto ReadAndExit;
   }
#endif

#ifdef __FS_EMERGENT_NAND_BUFFER_SUPPORT__
   if(Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
   {
      B = &g_Emergent_NAND_Buffer;
      B->Flags |= B_INUSE;
      if ((B->Sector == Sector) && (B->Dev == Dev))
         goto SaveAndExit;
      else
         goto ReadAndExit;
   }
#endif
/* Guarantee fixed disk access, Karen Hsu, 2005/05/19, ADD END */

#ifdef __FS_EMERGENT_CARD_BUFFER_SUPPORT__ /* PATCH , WCP_SW, 2006/08/03, ADD BEGIN */
   if(Dev->DeviceFlags & RTF_DEVICE_REMOVABLE)
   {
      B = &g_Emergent_Card_Buffer;
      B->Flags |= B_INUSE;
      if ((B->Sector == Sector) && (B->Dev == Dev))
         goto SaveAndExit;
      else
         goto ReadAndExit;
   }
#endif /* PATCH , WCP_SW, 2006/08/03, ADD END */

   fs_util_trace_err_noinfo(RTF_OUT_OF_BUFFERS);
   fs_util_trace_info2(TRACE_ERROR, FS_ERR_GETBUFFER_OUT_OF_BUFFERS, Sector, fs_conf_get_devtype_by_devflag(Dev->DeviceFlags), NULL);


   /* if no buffer satisfies the conditions, raise an exception */
   XRAISE(RTF_OUT_OF_BUFFERS);

ReadAndExit:
   B->Dev           = Dev;
   B->Sector        = Sector;
   B->FATSectorInfo = NULL;

   // for emergency buffer
   if (B->Flags & B_SINGLE)
   {
      B->Flags = (B_SINGLE | B_INUSE);
   }
   else
      B->Flags         = B_INUSE;

   B->recoverable_flag = RTF_NORMAL_WRITE;

   if (Flags & NO_LOAD)
      B->Flags |= B_VALID;
   else
      ReadBuffer(B);

SaveAndExit:
   UpFront(B);

   /* udpate B pointer */
   if (Flags & ALT_BUFFER)
      Dev->DevData.AltBuffer = B;
   else
      Dev->DevData.B = B;
   return B->Data;
}

/*-----------------------------------*/
#ifdef __FS_DEBUG__
static void INTERN FlushOldest(RTFDevice * Dev)
{
   // search backwards (oldest first) for a buffer to commit

   RTFBuffer * B = FirstBuffer->Prev;

   do
   {
      if ((B->Flags & B_DIRTY) && (B->Dev == Dev))
      {
         #ifdef DEBUG
         if (B->Flags & B_BUSY)
            fs_err_internal_fatal(FS_ERR_BUFFER_16, NULL);
         #endif
         if (B->Flags & B_INUSE)
            WriteBuffer(B);
         else
         {
            B->Flags |= B_INUSE;
            WriteBuffer(B);
            B->Flags &= ~B_INUSE;
         }
         return;
      }
      B = B->Prev;
   } while (B != FirstBuffer->Prev);

   #ifdef DEBUG
   // Some debugging. This is actually not a fatal error.
   // The file system can keep on going if no buffer to commit is found.
   // The only danger now is a critical error on an other device, which
   // could throw an out-of-buffer exception
   fs_err_internal_fatal(FS_ERR_BUFFER_17, NULL);
   #endif
}
#endif

/*-----------------------------------*/
void SetDirty(RTFDevice * Dev)
{
   RTFBuffer * B = Dev->DevData.B;
   #ifdef DEBUG
   if (B == NULL)
       fs_err_internal_fatal(FS_ERR_BUFFER_18, NULL);
   if ((B->Flags & B_INUSE) == 0)
       fs_err_internal_fatal(FS_ERR_BUFFER_19, NULL);
   if ((B->Flags & B_VALID) == 0)
       fs_err_internal_fatal(FS_ERR_BUFFER_20, NULL);
   #endif

   if (B->Flags & B_DIRTY)
#ifdef __FS_DEBUG__
      BufferStat.CachedBufferWrites += (B->LastDirtyTime != B->Dev->DevData.AccessCount);
#else
   ;
#endif
   else
   {
      B->Flags |= B_DIRTY;
#ifdef __FS_DEBUG__
      if (++BufferStat.DirtyBuffers > BufferStat.MaxDirtyBuffers)
         BufferStat.MaxDirtyBuffers = BufferStat.DirtyBuffers;
#endif
      B->FirstDirtyTime = B->Dev->DevData.AccessCount;
   }
   B->LastDirtyTime = B->Dev->DevData.AccessCount;

   // prevent from human errors
   B->recoverable_flag = RTF_NORMAL_WRITE;

#ifdef __FS_DEBUG__
   if (BufferStat.DirtyBuffers > (FS_MAX_BUFFERS-2))
      FlushOldest(Dev);
#endif

/* Guarantee fixed disk access, Karen Hsu, 2005/05/19, ADD START */
   if (B->Flags & B_SINGLE)
      WriteBuffer(B);
/* Guarantee fixed disk access, Karen Hsu, 2005/05/19, ADD END */

}

/*-----------------------------------*/
void SetRecoverableFlag(RTFDevice * Dev, BYTE block_type)
{
   RTFBuffer * B = Dev->DevData.B;
   #ifdef DEBUG
   if (B == NULL)
       fs_err_internal_fatal(FS_ERR_BUFFER_21, NULL);
   #endif

   if (block_type == FS_BLOCK_PROTECTION_ENUM)
      B->recoverable_flag = RTF_RECOVERABLE_WRITE;
   else
      B->recoverable_flag = RTF_NORMAL_WRITE;
}

/*******************************************************************//**
 * Commit device's INUSE buffer
 *
 * @par Category:
 * File System
 **********************************************************************/
void RTFAPI CommitBuffer(RTFDevice * Dev)
// write a buffer if it is dirty
{
   RTFBuffer * B = Dev->DevData.B;
   #ifdef DEBUG
   if (B == NULL)
       fs_err_internal_fatal(FS_ERR_BUFFER_22, NULL);
   if ((B->Flags & B_INUSE) == 0)
       fs_err_internal_fatal(FS_ERR_BUFFER_23, NULL);
   if ((B->Flags & B_VALID) == 0)
       fs_err_internal_fatal(FS_ERR_BUFFER_24, NULL);
   #endif
   if (B->Flags & B_DIRTY)
      WriteBuffer(B);
}

/*-----------------------------------*/
void RTFAPI DiscardAllBuffers(RTFDevice * Dev)
{
   RTFBuffer * B;

Again:
   B = FirstBuffer;
   do
   {
      if ((B->Flags & B_VALID) == 0)
      {
         #ifdef DEBUG
         {
            RTFBuffer * B1 = B;
            do
            {
               if (B1->Flags != 0)
                  fs_err_internal_fatal(FS_ERR_BUFFER_25, NULL);
               B1 = B1->Next;
            }
            while (B1 != FirstBuffer);
         }
         #endif
         return;
      }
      else
         if (B->Dev == Dev)
         {
            if (Dev->DevData.B == B)
               DiscardBuffer(Dev);
            else
               DiscardOtherBuffer(B);
            goto Again;
         }
      B = B->Next;
   } while (B != FirstBuffer);
}

/*-----------------------------------*/
void RTFAPI DiscardBuffersRange(RTFDevice * Dev, RTFSector Sector, RTFSector Count, int Commit)
{
   RTFBuffer * B;

/* Guarantee fixed disk access, Karen Hsu, 2005/05/19, ADD START */
//don't put these two cases behind
#ifdef __FS_EMERGENT_NOR_BUFFER_SUPPORT__
   B = &g_Emergent_NOR_Buffer;
   if ((B->Dev == Dev) && (B->Sector >= Sector) && (B->Sector < (Sector+Count)))
   {
      B->Flags = B_SINGLE;
      B->recoverable_flag = RTF_NORMAL_WRITE;
      if (Dev->DevData.B == B)
         Dev->DevData.B = NULL;
   }
#endif

#ifdef __FS_EMERGENT_NAND_BUFFER_SUPPORT__
   B = &g_Emergent_NAND_Buffer;
   if ((B->Dev == Dev) && (B->Sector >= Sector) && (B->Sector < (Sector+Count)))
   {
      B->Flags = B_SINGLE;
      B->recoverable_flag = RTF_NORMAL_WRITE;
      if (Dev->DevData.B == B)
         Dev->DevData.B = NULL;
   }
#endif
/* Guarantee fixed disk access, Karen Hsu, 2005/05/19, ADD END */

#ifdef __FS_EMERGENT_Card_BUFFER_SUPPORT__ /* PATCH , WCP_SW, 2006/08/03, ADD BEGIN */
   B = &g_Emergent_Card_Buffer;
   if ((B->Dev == Dev) && (B->Sector >= Sector) && (B->Sector < (Sector+Count)))
   {
      B->Flags = B_SINGLE;
      B->recoverable_flag = RTF_NORMAL_WRITE;
      if (Dev->DevData.B == B)
         Dev->DevData.B = NULL;
   }
#endif /* PATCH , WCP_SW, 2006/08/03, ADD END */

Again:
   B = FirstBuffer;
   do
   {
      if ((B->Flags & B_VALID) == 0)
      {
         #ifdef DEBUG
         {
            RTFBuffer * B1 = B;
            do
            {
               if (B1->Flags != 0)
                  fs_err_internal_fatal(FS_ERR_BUFFER_26, NULL);
               B1 = B1->Next;
            }
            while (B1 != FirstBuffer);
         }
         #endif
         return;
      }
      else
      {
         if ((B->Dev == Dev) && (B->Sector >= Sector) && (B->Sector < (Sector + Count)))
         {
            if ((B->Flags & B_DIRTY) && Commit)
            {
               #ifdef DEBUG
               if (B->Flags & B_BUSY)
                  fs_err_internal_fatal(FS_ERR_BUFFER_27, NULL);
               #endif
               if (B->Flags & B_INUSE)
                  WriteBuffer(B);
               else
               {
                  B->Flags |= B_INUSE;
                  WriteBuffer(B);
                  B->Flags &= ~B_INUSE;
               }
            }
            if (Dev->DevData.B == B)
               DiscardBuffer(Dev);
            else
               DiscardOtherBuffer(B);
            goto Again;
         }
      }
      B = B->Next;
   } while (B != FirstBuffer);
}

/*******************************************************************//**
 * Flush all buffers occupied by a specified device
 *
 * @par Category:
 * File System
 *
 * @note
 * Keep device's B pointer after flush all its buffers.
 **********************************************************************/
void RTFAPI FlushAllBuffers(RTFDevice * Dev)
{
   RTFBuffer * B;

Again:
   B = FirstBuffer;
   do
   {
      if ((B->Flags & B_DIRTY) && (B->Dev == Dev))
      {
         #ifdef DEBUG
         if (B->Flags & B_BUSY)
            fs_err_internal_fatal(FS_ERR_BUFFER_28, NULL);
         #endif

         /* do not modify device's B pointer and buffer's INUSE flag */
         if (B->Flags & B_INUSE)
            WriteBuffer(B);
         else
         {
            /* WriteBuffer requires flag INUSE, DIRTY and VALID, so set INUSE before call WriteBuffer */
            B->Flags |= B_INUSE;
            WriteBuffer(B);
            B->Flags &= ~B_INUSE;
         }
         goto Again;
      }
      B = B->Next;
   } while (B != FirstBuffer);
}

/*******************************************************************//**
 * Flush all FAT data buffer of a specified device
 *
 * @par Category:
 * File System
 **********************************************************************/
void FlushFAT(RTFDevice * Dev)
{
   RTFBuffer * B;

Again:
   B = FirstBuffer;
   do
   {
      if ((B->Flags & B_DIRTY) && B->FATSectorInfo && (B->Dev == Dev))
      {
         #ifdef DEBUG
         if (B->Flags & B_BUSY)
            fs_err_internal_fatal(FS_ERR_BUFFER_29, NULL);
         if (B->FATSectorInfo->Dev != Dev)
            fs_err_internal_fatal(FS_ERR_BUFFER_30, NULL);
         #endif
         if (B->Flags & B_INUSE)
            WriteBuffer(B);
         else
         {
            B->Flags |= B_INUSE;
            WriteBuffer(B);
            B->Flags &= ~B_INUSE;
         }
         goto Again;
      }
      B = B->Next;
   } while (B != FirstBuffer);
}

/*******************************************************************//**
 * Flush all buffers of a specified device by the order of logical sector number
 *
 * @par Category:
 * File System
 *
 * @note
 * In FAT12/16, FAT will always be committed before directory entry!
 **********************************************************************/
void RTFAPI FlushAllBuffersInGeometryOrder(RTFDevice * Dev)
{
   RTFBuffer * B;
   RTFBuffer * W;

Again:
   B = FirstBuffer;
   W = NULL;
   do
   {
      if ((B->Flags & B_DIRTY) && (B->Dev == Dev))
      {
         #ifdef DEBUG
         if (B->Flags & B_BUSY)
            fs_err_internal_fatal(FS_ERR_BUFFER_31, NULL);
         #endif
         if (W == NULL || W->Sector > B->Sector)
         {
            W = B;
         }
      }
      B = B->Next;
   } while (B != FirstBuffer);

   if (W != NULL)
   {
      if (W->Flags & B_INUSE)
      {
         WriteBuffer(W);
      }
      else
      {
         W->Flags |= B_INUSE;
         WriteBuffer(W);
         W->Flags &= ~B_INUSE;
      }
      goto Again;
   }
}




#ifdef DEBUG
/*-----------------------------------*/
static void INTERN EntryExitCheck(RTFDevice * Dev, _XData * XD)
{
   int i;

   if (FirstBuffer == NULL) // buffers not initialized yet
      return;
   if ((XD == NULL) || (XD->Next == NULL)) // are we leaving the the file system?
   {
      RTFBuffer * B;

      if (Dev->DevData.B)
         fs_err_internal_fatal(FS_ERR_BUFFER_32, NULL);

      // check that the buffer chain is not corrupted

      B = FirstBuffer;
      for (i=0; i<FS_MAX_BUFFERS-1; i++)
         B = B->Next;
      if (B == FirstBuffer)
         fs_err_internal_fatal(FS_ERR_BUFFER_33, NULL);
      B = B->Next;
      if (B != FirstBuffer)
         fs_err_internal_fatal(FS_ERR_BUFFER_34, NULL);

      // now check backward links
      B = FirstBuffer->Prev;
      for (i=0; i<FS_MAX_BUFFERS-1; i++)
         B = B->Prev;
      if (B == FirstBuffer->Prev)
         fs_err_internal_fatal(FS_ERR_BUFFER_35, NULL);
      B = B->Prev;
      if (B != FirstBuffer->Prev)
         fs_err_internal_fatal(FS_ERR_BUFFER_36, NULL);

      // check that not buffers of this drive are in use or busy
      B = gFS_Data.BufferTable;
      for (i=0; i<FS_MAX_BUFFERS; i++)
      {
         if ((B->Dev == Dev) && (B->Flags & (B_INUSE | B_BUSY)))
            fs_err_internal_fatal(FS_ERR_BUFFER_37, NULL);
         B++;
      }

      // check that RTFiles and the drive are locked
      if (!RTFSYSOwnMutex(RTFLock) || !RTFSYSOwnMutex(Dev->DevData.Lock))
         fs_err_internal_fatal(FS_ERR_BUFFER_38, NULL);

   }
   else  // we are not leaving, so make sure the next exception handler is in scope
      if ((void*) XD <= (void*) &XD)
          fs_err_internal_fatal(FS_ERR_BUFFER_39, NULL);
}

/*-----------------------------------*/
static void INTERN CheckReleased(_XData * XD)
{
   RTFDevice * Dev;

   if ((XD == NULL) || (XD->Next == NULL)) // are we leaving the file system?
   {
      for (Dev = gFS_DeviceList; Dev->DeviceType; Dev++)
         if (RTFSYSOwnMutex(Dev->DevData.Lock))
            fs_err_internal_fatal(FS_ERR_BUFFER_40, NULL);
      if (RTFSYSOwnMutex(RTFLock))
         fs_err_internal_fatal(FS_ERR_BUFFER_41, NULL);
   }
}
#endif



#ifdef __FS_DEDICATED_BUFFER__

fs_buffer_alloc_data_struct _gfs_dedicated_buffer;

void RTFAPI MTBufInit(const kal_uint32 buf_addr, const kal_uint32 buf_size)
{
   kal_uint32 offset;

   // 1. initialize FS dedicated buffer allocation data
   _gfs_dedicated_buffer.free_addr = (kal_uint32)buf_addr;
   _gfs_dedicated_buffer.free_size = (kal_uint32)buf_size;

   // 2. let buffer pool be 4-byte aligned
   offset = _gfs_dedicated_buffer.free_addr & 0x3;

   if (offset > 0)
   {
      offset = 4 - offset;
      _gfs_dedicated_buffer.free_addr += offset;
      _gfs_dedicated_buffer.free_size = buf_size - offset;
   }

   _gfs_dedicated_buffer.allocated_times = 0;
}

int RTFAPI MTBufCheckRange(unsigned int addr)
{
   if ((addr >= (unsigned int)gFS_DedicatedBufferPool) &&
   	   (addr < (unsigned int)gFS_DedicatedBufferPool + FS_DEDICATED_BUFFER_SIZE))
      return 1;
   else
      return 0;
}


int RTFAPI MTBufAlloc(unsigned int size, unsigned char **buf, unsigned int flag)
{
   kal_uint32     i;
   kal_taskid     task_id;

   fs_lock_get_mutex(_gfs_lock_common, FS_INFINITE);

   /*
    * check
    * 1. If allocator is the correct task?
    * 2. If free size is available?
    * 3. If allocation times is valid?
    */

   task_id = kal_get_current_thread_ID();

   // check 1
   if (0 < _gfs_dedicated_buffer.allocated_times || 0 == size)
   {
      if (task_id != _gfs_dedicated_buffer.allocated_task)
      {
         *buf = NULL;
         size = 0;

         goto MTBufAlloc_Exit;
      }
   }

   // check 2
   if (((flag & FS_INT_DBUF_ALLOC_PRECISE) && (size > _gfs_dedicated_buffer.free_size)) ||   // check for precise allocation
        (0 == _gfs_dedicated_buffer.free_size)) // check for greedy allocation
   {
      *buf = NULL;
      size = 0;

      goto MTBufAlloc_Exit;
   }

   // check 3
   if (_gfs_dedicated_buffer.allocated_times < FS_INT_DBUF_ALLOC_MAX_TIMES)
   {
      /*
       * We have exactly free size for either precise or greedy allocation.
       */

      *buf = (unsigned char*)_gfs_dedicated_buffer.free_addr; // must be a 4-byte aligned address

      // calculate correct allocation size
      if (size > _gfs_dedicated_buffer.free_size)
      {
         size = _gfs_dedicated_buffer.free_size;
      }

      // register this allocation
      i = _gfs_dedicated_buffer.allocated_times;
      _gfs_dedicated_buffer.allocated_times++;
      _gfs_dedicated_buffer.allocated_addr[i] = _gfs_dedicated_buffer.free_addr;
      _gfs_dedicated_buffer.allocated_size[i] = size;

      // calculate new free address (let new free address be 4-byte aligned)
      _gfs_dedicated_buffer.free_addr += size;
      _gfs_dedicated_buffer.free_size -= size;

      i = _gfs_dedicated_buffer.free_addr & 0x3;

      if (i > 0)
      {
         i = 4 - i;

         if (_gfs_dedicated_buffer.free_size >= i) // consider offset for 4-byte aligned new free address
         {
            _gfs_dedicated_buffer.free_addr += i;
            _gfs_dedicated_buffer.free_size -= i;
         }
         else
         {
            _gfs_dedicated_buffer.free_addr += _gfs_dedicated_buffer.free_size;
            _gfs_dedicated_buffer.free_size = 0;
         }
      }

      // register task id
      _gfs_dedicated_buffer.allocated_task = task_id;
   }

MTBufAlloc_Exit:

   fs_lock_free_mutex(_gfs_lock_common);

   return size;
}


void RTFAPI MTBufFree(unsigned int size, unsigned char **buf)
{
   kal_uint8   i;
   kal_taskid  task_id;

   if (NULL == *buf || 0 == size)
   {
      *buf = NULL;
      return;
   }

   fs_lock_get_mutex(_gfs_lock_common, FS_INFINITE);

   // Check 1. Owner task
   task_id = kal_get_current_thread_ID();

   if (task_id != _gfs_dedicated_buffer.allocated_task)
   {
      fs_assert_local(0);
   }

   // Check 2. Allocation times
   i = _gfs_dedicated_buffer.allocated_times;

   if (0 == i)
   {
      fs_assert_local(0);
   }

   // Check 3. Allocated size

   i = i - 1; // get index

   if (size != _gfs_dedicated_buffer.allocated_size[i])
   {
      fs_assert_local(0);
   }

   // Check 4. Allocated address
   if ((kal_uint32)(*buf) != _gfs_dedicated_buffer.allocated_addr[i])
   {
      fs_assert_local(0);
   }

   // update free memory information
   size = _gfs_dedicated_buffer.free_addr - _gfs_dedicated_buffer.allocated_addr[i];
   _gfs_dedicated_buffer.free_size += size;
   _gfs_dedicated_buffer.free_addr = _gfs_dedicated_buffer.allocated_addr[i];

   // free memory
   _gfs_dedicated_buffer.allocated_size[i] = _gfs_dedicated_buffer.allocated_addr[i] = 0;
   _gfs_dedicated_buffer.allocated_times--;

   *buf = NULL;

   if (0 == _gfs_dedicated_buffer.allocated_times)
   {
      _gfs_dedicated_buffer.allocated_task = 0;
   }

   fs_lock_free_mutex(_gfs_lock_common);
}

// Interval Buffer

#ifdef __FS_INTERVAL_BUFFER__

struct fs_interval_buffer;
typedef struct
{
    kal_uint32 *address;
    kal_uint32  size;
    RTFDevice  *dev;
    kal_uint32  lba_addr;
    kal_uint32  lba_length;
    kal_uint32  handle;
    kal_uint8   valid;
} fs_interval_buffer;

fs_interval_buffer gfs_intbuf = {0};

// Initialization Funtion
int fs_srv_buf_alloc(void)
{
    kal_uint32 len;
    kal_int32 result=FS_NO_ERROR;

    gfs_intbuf.lba_addr   = 0;
    gfs_intbuf.lba_length = 0;
    gfs_intbuf.address    = NULL;
    gfs_intbuf.size       = FS_DEDICATED_BUFFER_SIZE;

    // Use FS buffer
    len=MTBufAlloc(gfs_intbuf.size, (unsigned char **)&(gfs_intbuf.address), FS_INT_DBUF_ALLOC_PRECISE);

    if (len==0) {
           gfs_intbuf.address = NULL;
           result=FS_FAIL_GET_MEM;
    }

    return result;
}

// Finalization Function
int fs_srv_buf_final(void)
{
    kal_int32 result=FS_NO_ERROR;

    if (gfs_intbuf.address!=NULL)   {
        MTBufFree(gfs_intbuf.size, (unsigned char **)&(gfs_intbuf.address));
    }

    return result;
}

#define SECTOR_SIZE (512)

void *fs_srv_buf_get(RTFDevice * Dev, RTFSector Sector, UINT Flags)
{
    void *buf_ptr=NULL;
    kal_int32 result=FS_NO_ERROR;
    kal_uint32 sector_offset;

    if (gfs_intbuf.address == NULL) {
        return GetBuffer(Dev, Sector, Flags);
    }

    if ( (gfs_intbuf.lba_length==0) ||
         (Sector < gfs_intbuf.lba_addr) ||
         (Sector >= (gfs_intbuf.lba_addr + gfs_intbuf.lba_length)))   {

        result=rtf_core_read_sectors(Dev, gfs_intbuf.address, Sector, (FS_DEDICATED_BUFFER_SIZE/SECTOR_SIZE), NO_RAISE);
        gfs_intbuf.lba_addr=Sector;
        gfs_intbuf.lba_length=(FS_DEDICATED_BUFFER_SIZE/SECTOR_SIZE);
    }

    if (result < FS_NO_ERROR)   {
        gfs_intbuf.lba_addr=0;
        gfs_intbuf.lba_length=0;
    }
    else {
        sector_offset = Sector - gfs_intbuf.lba_addr;
        buf_ptr = (void*)((kal_uint8*)gfs_intbuf.address + (sector_offset * SECTOR_SIZE));
    }

    return buf_ptr;
}

#endif // __FS_INTERVAL_BUFFER__
#endif /* __FS_DEDICATED_BUFFER__ */

