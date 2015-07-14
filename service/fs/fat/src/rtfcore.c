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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   fs_bl_main.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file contains FS for Boot loader.
 *
 * Author:
 * -------
 * -------
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/**************************************************************************/
/*                                                                        */
/*  File: RTFILES.C                              Copyright (c) 1998,2002  */
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

#if defined(WIN32)
#include "windows.h"    // !NOTE! windows.h MUST be defined ahead of Rtfiles.h! Because Rtfiles.h will check _WINDOWS_ definition which is defined in windows.h!
#endif

#include "kal_public_api.h" //MSBB change #include "kal_release.h"
#include "kal_public_defs.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_internal_api.h"    // for KAL_ERROR_FILESYS_INTERNAL_FAILED

#include "fs_gprot.h"
#include "fs_iprot.h"
#include "fs_internal_api.h"
#include "rtfiles.h"
#include "rtfex.h"
#include "rtfbuf.h"
#include "fs_utility.h"
#include "fs_kal.h"
#include "fs_trc.h"
#include "kal_trace.h"
#include "SST_sla.h"            // for SWLA hooker
#include "dcl.h"

#ifdef __FS_CARD_DOWNLOAD__
#include "bl_init.h"
#endif

/*
 * Macros
 */

#if (defined __FS_SYSDRV_ON_NAND__) && !(defined _NAND_FLASH_BOOTING_) && !(defined __EMMC_BOOTING__)
    /* Treat __FS_SYSDRV_ON_NAND__ equal _NAND_FLASH_BOOTING_ */
    #define _NAND_FLASH_BOOTING_
#endif

// Trace
#define fs_util_trace_err_noinfo(error_code) fs_util_trace_err_slim(error_code, rtfcore_c, __LINE__)


// Assert
#define fs_assert_local(expr) fs_assert(expr, rtfcore_c)
#define fs_ext_assert_local(expr, e1, e2, e3) fs_ext_assert(expr, rtfcore_c, e1, e2, e3)

#ifdef _MSC_VER
   #define INTERN _fastcall
#elif defined __BORLANDC__
   #define INTERN __fastcall
#else
   #define INTERN
#endif

#ifndef __FS_CARD_DOWNLOAD__
#define RTFINIT_BEGIN()  \
do \
{ \
   fs_assert_local(FS_MAX_DRIVES >= 1);\
   fs_assert_local(FS_MAX_BUFFERS >= 1);\
   fs_assert_local(FS_MAX_FILES >= 3);\
   fs_assert_local(FS_MAX_THREAD >= 2);\
   \
   RTFLock = RTFSYSAllocMutex("RTFiles");\
   \
   RTFSYSLockMutex(RTFLock, RTF_INFINITE);\
   RTFSYSLockMutex(RTFLock, RTF_INFINITE);\
}while(0)
#else
#define RTFINIT_BEGIN()
#endif /* __FS_CARD_DOWNLOAD__ */


#ifndef __FS_CARD_DOWNLOAD__
#define RTFINIT_END() \
do\
{\
    RTFSYSFreeMutex(RTFLock);\
    RTFSYSFreeMutex(RTFLock);\
}while(0)
#else
#define RTFINIT_END()
#endif /* __FS_CARD_DOWNLOAD__ */

/*
 * Globals
 */
UINT  OpenHintStamp;
int   TLSBlockIndex = -1;
kal_bool  NorPartition;
kal_bool  NandPartition;
const WCHAR dchar_dot[]={0x2e, 0}; /* . */
const WCHAR dchar_dot_dot[]={0x2e, 0x2e, 0}; /* .. */
const WCHAR dchar_start_dot_star[]={0x2a, 0x2e, 0x2a, 0}; /* *.* */
const WCHAR dchar_star[]={0x2a, 0}; /* *.* */
kal_bool gMT_Sanity = KAL_FALSE;
RTFMutex * RTFLock = NULL;

/*
 * Locals
 */
static const int DriveMapTBL[] =
{                       /* Pub 1, Pub 2, Sys 1, Sys 2 */
   /* NOR:NAND = 1:0 */      0x0,   0x0,  0x43,  0x0,   /* 0 0 C 0 */
   /* NOR:NAND = 2:0 */     0x43,   0x0,  0x44,  0x0,   /* C 0 D 0 */
   /* NOR:NAND = 0:1 */      0x0,   0x0,  0x43,  0x0,   /* 0 0 C 0 */
   /* NOR:NAND = 1:1 */     0x44,   0x0,  0x43,  0x0,   /* D 0 C 0 */
   /* NOR:NAND = 2:1 */     0x43,  0x44,  0x45,  0x0,   /* C D E 0 */
   /* NOR:NAND = 0:2 */     0x43,   0x0,  0x44,  0x0,   /* C 0 D 0 */
   /* NOR:NAND = 1:2 */     0x44,   0x0,  0x43, 0x45,   /* D 0 C E */
   /* NOR:NAND = 2:2 */     0x43,  0x44,  0x45, 0x46    /* C D E F */
};

/*
 * Declarations
 */
extern kal_bool     INT_QueryExceptionStatus(void);
extern kal_uint32   SaveAndSetIRQMask(void);
extern void         RestoreIRQMask(kal_uint32 irq);

int RTFAPI MTGetDrive(kal_uint32 Type, kal_uint32 Serial, kal_uint32 AltMask)
{
   UINT Count = 0;
   UINT NORCount = 0, NANDCount = 0, eMMCCount = 0, ExtCount = 0, CardCount = 0, SPlusCount = 0;
   int  Result = 0, TBLidx = -1;

#if ( defined(__NANDFDM_MULTI_INSTANCE__) && defined(__NAND_FDM_50__) )

#if defined(__NAND_SUPPORT_RAW_DISK__)

   /*
    * C (Hidden): Cust(for Wise, PXOs)
    * D (Hidden): Root(for Wise)
    * E (PUB1)  : User(for Wise)
    * F (SYS1)  : Root(for MAUI, NVRAM)
    * G (SYS2)  : Backup Partition
    * - (Hidden): LG Partition (No partition table and drive letter)
    * H (RMV)   : Memory card
    */

   if ((MT_DRIVE_I_SYSTEM == Type) && (2 == Serial))
   {
      return 'G';
   }
   else if ((MT_DRIVE_I_SYSTEM == Type) && (1 == Serial))
   {
      return 'F';
   }
   else if ((MT_DRIVE_V_NORMAL == Type) && ((1 == Serial) || (AltMask & MT_ONLY_ALT_SERIAL)))
   {
      return 'E';
   }
   else if (Type == MT_DRIVE_V_REMOVABLE)
   {
      return 'H';
   }

   if (AltMask & MT_NO_ALT_DRIVE)
   {
      Result = RTF_DRIVE_NOT_FOUND;
      goto getReturn;
   }

   if (AltMask & MT_DRIVE_V_NORMAL)
   {
      Result = 'E';
   }
   else if (AltMask & MT_DRIVE_V_REMOVABLE)
   {
      Result = 'H';
   }
   else if (AltMask & MT_DRIVE_I_SYSTEM)
   {
      Result = 'F';
   }

#else  /* !__NAND_SUPPORT_RAW_DISK__ */
   // Edward add
   if (Type == MT_DRIVE_I_SYSTEM)
   {
      return 'F';
   }
   else if ((Type == MT_DRIVE_V_NORMAL) && ((Serial == 1) || (AltMask & MT_ONLY_ALT_SERIAL)))
   {
      return 'E';
   }
   else if (Type == MT_DRIVE_V_REMOVABLE)
   {
      return 'G';
   }

   if (AltMask & MT_NO_ALT_DRIVE)
   {
      Result = RTF_DRIVE_NOT_FOUND;
      goto getReturn;
   }

   if (AltMask & MT_DRIVE_V_NORMAL)
   {
      Result = 'E';
   }
   else if (AltMask & MT_DRIVE_V_REMOVABLE)
   {
      Result = 'G';
   }
   else if (AltMask & MT_DRIVE_I_SYSTEM)
   {
      Result = 'F';
   }

#endif /* __NAND_SUPPORT_RAW_DISK__ */

   if (Result)
      return Result;
   else
      return RTF_DRIVE_NOT_FOUND;

   // Edward add end
#endif //( defined(__NANDFDM_MULTI_INSTANCE__) && defined(__NAND_FDM_50__) )

#define DEVTYPE_ALL_FLAGS (MT_DRIVE_I_SYSTEM | MT_DRIVE_V_NORMAL | MT_DRIVE_V_REMOVABLE | MT_DRIVE_V_EXTERNAL | MT_DRIVE_V_SIMPLUS)
   /* MTGetDrive - 1 Check parameter */
   if (((Type & DEVTYPE_ALL_FLAGS) == 0) ||
         ((Type & ~DEVTYPE_ALL_FLAGS) != 0) ||
         ((Type & (MT_DRIVE_I_SYSTEM | MT_DRIVE_V_NORMAL)) && (Serial > 2)) ||
         ((Type == MT_DRIVE_V_REMOVABLE) && (Serial > 2)) ||
         (Serial < 1) ||
         ((AltMask != MT_NO_ALT_DRIVE) && (AltMask & MT_NO_ALT_DRIVE)) ||
         ((AltMask != MT_ONLY_ALT_SERIAL) && (AltMask & MT_ONLY_ALT_SERIAL)) ||
         (AltMask & MT_DRIVE_V_EXTERNAL))
   {
      return RTF_PARAM_ERROR;
   }

#undef DEVTYPE_ALL_FLAGS

   /* MTGetDrive - 2 Count Drive in each type */
   SafeLock(MT_LOCK_RTF, NULL, RTF_INFINITE);

   for (Count = MT_BASE_DRIVE_INDEX; Count < FS_MAX_DRIVES; Count++)
   {
      if (gFS_Data.DriveTable[Count].Dev != NULL)
      {
         if (gFS_Data.DriveTable[Count].Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
         {
            NORCount++;
            fs_assert_local(NORCount < 3);
         }
         else if (gFS_Data.DriveTable[Count].Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
         {
            NANDCount++;
            fs_assert_local(NANDCount < 3);
         }
         else if (gFS_Data.DriveTable[Count].Dev->DeviceFlags & FS_DEVICE_EMMC)
         {
            eMMCCount++;
            fs_assert_local(eMMCCount < 3);
         }
         else if ((gFS_Data.DriveTable[Count].Dev->DeviceFlags & (RTF_DEVICE_REMOVABLE | MT_DEVICE_EXTERNAL | MT_DEVICE_SIMPLUS)) == RTF_DEVICE_REMOVABLE)
         {
            CardCount++;
            fs_assert_local(CardCount < 3);
         }
         else if (gFS_Data.DriveTable[Count].Dev->DeviceFlags & MT_DEVICE_SIMPLUS)
         {
            SPlusCount++;
            fs_assert_local(SPlusCount < 5);
         }
         else if (gFS_Data.DriveTable[Count].Dev->DeviceFlags & MT_DEVICE_EXTERNAL)
         {
            ExtCount++;
         }
      }
      else
         break;
   }

   Count = NORCount + NANDCount + eMMCCount;

   fs_assert_local((Count > 0) && (Count < 5));

   if (eMMCCount > 0)
   {
      fs_assert_local(Count == eMMCCount);   // eMMC project should not have NOR and NAND drives

      NORCount = eMMCCount; // treat eMMC booting case as NOR booting for TBLidx calculation below.
   }

#ifndef _NAND_FLASH_BOOTING_    // should bypass EMMC booting case
   fs_assert_local(NORCount > 0);
#endif

#ifdef __FS_SHADOW_NAND__
   fs_assert_local(NANDCount < 2);
#endif

#ifdef __FS_SHADOW_CARD__
   fs_assert_local(CardCount < 2);
#endif

   /* Calculate TBLidx BASE */
   TBLidx = (NORCount + NANDCount * 3 - 1) * 4;
   /* 1 0 => 0; 0 1 => 2; 0 2 => 5 */

   /* Match type first */

   switch (Type)
   {
      case MT_DRIVE_I_SYSTEM: /* Match system drive */

         if (DriveMapTBL[TBLidx + 2 + Serial - 1] != 0x0)
         {
            Result = DriveMapTBL[TBLidx + 2 + Serial - 1];
            goto getReturn;
         }

         break;

      case MT_DRIVE_V_NORMAL: /* Match normal drive */

         if (DriveMapTBL[TBLidx + 0 + Serial - 1] != 0x0)
         {
            Result = DriveMapTBL[TBLidx + 0 + Serial - 1];
            goto getReturn;
         }

         break;

      case MT_DRIVE_V_REMOVABLE: /* Match removable drive */

         if (Serial <= CardCount)
         {
            Result = MT_BASE_DRIVE_LETTER + Count + Serial - 1;
            goto getReturn;
         }

         break;

      case MT_DRIVE_V_SIMPLUS: /* Match SIMPLUS drive ; No alternative match */

         if (Serial <= SPlusCount)
         {
            Result = MT_BASE_DRIVE_LETTER + Count + CardCount + Serial - 1;
         }
         else
         {
            Result = RTF_DRIVE_NOT_FOUND;
         }

         goto getReturn;

      case MT_DRIVE_V_EXTERNAL: /* Match external drive ; No alternative match */

         if (Serial <= ExtCount)
         {
            Result = MT_BASE_DRIVE_LETTER + Count + CardCount + SPlusCount + Serial - 1;
         }
         else
         {
            Result = RTF_DRIVE_NOT_FOUND;
         }

         goto getReturn;

      default:
         Result = RTF_PARAM_ERROR;
         goto getReturn;
   }//end of switch

   if (AltMask & MT_NO_ALT_DRIVE)
   {
      Result = RTF_DRIVE_NOT_FOUND;
      goto getReturn;
   }

   /* Match serial then */
   if (AltMask & MT_ONLY_ALT_SERIAL)
   {
      switch (Type)
      {
         case MT_DRIVE_I_SYSTEM: /* Match system drive */

            if ((Serial == 2) && (DriveMapTBL[TBLidx + 2] != 0x0))
            {
               Result = DriveMapTBL[TBLidx + 2];
               goto getReturn;
            }
            else if ((Serial == 1) && (DriveMapTBL[TBLidx + 3] != 0x0))
            {
               Result = DriveMapTBL[TBLidx + 3];
               goto getReturn;
            }

            break;

         case MT_DRIVE_V_NORMAL: /* Match normal drive */

            if ((Serial == 1) && (DriveMapTBL[TBLidx + 1] != 0x0))
            {
               Result = DriveMapTBL[TBLidx + 1];
               goto getReturn;
            }
            else if ((Serial == 2) && (DriveMapTBL[TBLidx + 0] != 0x0))
            {
               Result = DriveMapTBL[TBLidx + 0];
               goto getReturn;
            }

            break;

         case MT_DRIVE_V_REMOVABLE: /* Match removable drive */

            if (CardCount > 0)
            {
               Result = MT_BASE_DRIVE_LETTER + Count + CardCount - 1;
               goto getReturn;
            }

            break;

         default:
            Result = RTF_PARAM_ERROR;
            goto getReturn;
      }//end of switch
   }

   /* Match other alter last */
   if ((DriveMapTBL[TBLidx + 1]) && (AltMask & MT_DRIVE_V_NORMAL))
   {
      Result = DriveMapTBL[TBLidx + 1];
   }
   else if ((DriveMapTBL[TBLidx + 0]) && (AltMask & MT_DRIVE_V_NORMAL))
   {
      Result = DriveMapTBL[TBLidx + 0];
   }
   else if ((CardCount > 0) && (AltMask & MT_DRIVE_V_REMOVABLE))
   {
      Result = MT_BASE_DRIVE_LETTER + Count + CardCount - 1;
   }
   else if ((DriveMapTBL[TBLidx + 3]) && (AltMask & MT_DRIVE_I_SYSTEM))
   {
      Result = DriveMapTBL[TBLidx + 3];
   }
   else if ((DriveMapTBL[TBLidx + 2]) && (AltMask & MT_DRIVE_I_SYSTEM))
   {
      Result = DriveMapTBL[TBLidx + 2];
   }

getReturn:

   SafeUnlock(MT_LOCK_RTF);

   if (Result)
      return Result;

   fs_util_trace_err_noinfo(RTF_DRIVE_NOT_FOUND);

   return RTF_DRIVE_NOT_FOUND;
}


#if defined(__FS_IO_STATISTICS__)
// The caller must obtain RTFLock before invoke this function
static void rtf_core_io_statistic(kal_uint32 sectors, kal_uint32 time)
{
    kal_int32  task_index;
    kal_int32  thread_count;
    kal_taskid current_task;

    if (gFS_TaskIOStatistics==NULL) return;

    current_task = kal_get_current_thread_ID();
    thread_count = RTFSYSGetThreadCount();

    /* Find current task id is registered or not */
    for (task_index=0; task_index<thread_count; task_index++)
    {
        if (gFS_TaskList[task_index] == current_task) break;
    }

    if (task_index == thread_count) return;

    gFS_TaskIOStatistics[task_index].AccessCount++;
    gFS_TaskIOStatistics[task_index].SectorCount+=sectors;
    gFS_TaskIOStatistics[task_index].AccessTime+=(time/25);  // time unit: 1=25us
}
#else
#define rtf_core_io_statistic(sectors, time)
#endif // __FS_IO_STATISTICS__

int rtf_core_read_sectors(RTFDevice * Dev, void * Data, RTFSector Sector, UINT Sectors, DWORD Flags)
{
   int volatile   Result;
   fs_util_time_init_with_duration();

   RTFSYSFreeMutex(RTFLock);

   XTRY
      case XCODE:
      {
         CheckMedia(Dev);

         if (Dev->DevData.ErrorCondition < RTF_NO_ERROR)
         {
            fs_util_trace_err_noinfo(Dev->DevData.ErrorCondition);
            fs_util_trace_info4(TRACE_ERROR, FS_ERR_READSECTORS_DEVICE_ERROR, Sector, Sectors, fs_conf_get_devtype_by_devflag(Dev->DeviceFlags), NULL, NULL);

            XRAISE(Dev->DevData.ErrorCondition);
         }

         if (Dev->DevData.MountState < Mounted)
         {
            fs_util_trace_err_noinfo(RTF_DRIVE_NOT_READY);
            fs_util_trace_info4(TRACE_ERROR, FS_ERR_READSECTORS_DEV_NOT_READY, Sector, Sectors, Dev->DevData.MountState, fs_conf_get_devtype_by_devflag(Dev->DeviceFlags), NULL);

            XRAISE(RTF_DRIVE_NOT_READY);
         }

         if((Sector + Sectors) > Dev->DevData.Geometry.Sectors)
         {
            fs_util_trace_err_noinfo(RTF_FAT_ALLOC_ERROR);
            fs_util_trace_info4(TRACE_ERROR, FS_ERR_READSECTORS_OUT_OF_RANGE, Sector, Sectors, Dev->DevData.Geometry.Sectors, fs_conf_get_devtype_by_devflag(Dev->DeviceFlags), NULL);

            XRAISE(RTF_FAT_ALLOC_ERROR);
         }

         fs_util_time_start();

         //fs_util_trace_info1(TRACE_GROUP_2, FS_INFO_READSECTORS_S, Sector, NULL);

         // SWLA hooker
         fs_util_swla_hook((FS_Device *)Dev, FS_DRV_READ, SA_start);

         Result = Dev->Driver->ReadSectors(Dev->DriverData, Sector, Sectors, Data);

         // SWLA hooker
         fs_util_swla_hook((FS_Device *)Dev, FS_DRV_READ, SA_stop);

         fs_util_time_stop();
         fs_util_time_set_duration();

         // IO Trace
         fs_util_trace_device_io(Dev->DeviceFlags, Sector, Sectors, fs_util_time_query_duration());

         if (Result < RTF_NO_ERROR)
         {
            fs_util_trace_err_noinfo(Result);
            fs_util_trace_info4(TRACE_ERROR, FS_ERR_READSECTORS_DRIVER_FAIL, Sector, Sectors, fs_conf_get_devtype_by_devflag(Dev->DeviceFlags), NULL, NULL);

            XRAISE(Result);
         }
         break;
      }
      default:
         if (((Flags & NO_CRITICAL) == 0) &&
             (HandleCriticalError(Dev, XVALUE) == RTFRetry))
         {
            XHANDLED;
            XREEXECUTE;
         }

         if (MT_MSDC_MOUNT_ERROR == XVALUE)
         {
            MTErrHdlr_RemovableDeviceRWError(Dev);
            XVALUE = MT_MSDC_READ_SECTOR_ERROR;
         }

         if (Flags & NO_RAISE)
         {
            Result = XVALUE;
            Dev->DevData.ErrorCondition = RTF_NO_ERROR;
            XHANDLED;
         }

         break;
      case XFINALLY:
         RTFSYSLockMutex(RTFLock, RTF_INFINITE);
         rtf_core_io_statistic(Sectors, fs_util_time_query_duration());

         break;
   XEND
   return Result;
}

/*-----------------------------------*/

/*-----------------------------------*/
int rtf_core_write_sectors(RTFDevice * Dev, void * Data, RTFSector Sector, UINT Sectors, DWORD Flags, BYTE recoverable_flag)
{
   int volatile   Result;
   int            fs_block_type = FS_BLOCK_ENUM; /* Fix multi-access bug, Karen Hsu, 2004/07/08, ADD */
   fs_util_time_init_with_duration();

   RTFSYSFreeMutex(RTFLock);

   XTRY
      case XCODE:
      {
         CheckMedia(Dev);

         if (Dev->DevData.ErrorCondition < RTF_NO_ERROR)
         {
            fs_util_trace_err_noinfo(Dev->DevData.ErrorCondition);
            fs_util_trace_info4(TRACE_ERROR, FS_ERR_WRITESECTORS_DEVICE_ERROR, Sector, Sectors, fs_conf_get_devtype_by_devflag(Dev->DeviceFlags), NULL, NULL);

            XRAISE(Dev->DevData.ErrorCondition);
         }

         if (Dev->DevData.MountState < Mounted)
         {
            fs_util_trace_err_noinfo(RTF_DRIVE_NOT_READY);
            fs_util_trace_info4(TRACE_ERROR, FS_ERR_WRITESECTORS_DEV_NOT_READY, Sector, Sectors, Dev->DevData.MountState, fs_conf_get_devtype_by_devflag(Dev->DeviceFlags), NULL);

            XRAISE(RTF_DRIVE_NOT_READY);
         }

         if ((Sector + Sectors) > Dev->DevData.Geometry.Sectors)
         {
            fs_util_trace_err_noinfo(RTF_FAT_ALLOC_ERROR);
            fs_util_trace_info4(TRACE_ERROR, FS_ERR_WRITESECTORS_OUT_OF_RANGE, Sector, Sectors, Dev->DevData.Geometry.Sectors, fs_conf_get_devtype_by_devflag(Dev->DeviceFlags), NULL);

            XRAISE(RTF_FAT_ALLOC_ERROR);
         }

         fs_block_type = (int)RTFSYSGetTLS(TLSBlockIndex);

         //fs_util_trace_info1(TRACE_GROUP_2, FS_INFO_WRITESECTORS_S, Sector, NULL);

         fs_util_time_start();

         // SWLA hooker
         fs_util_swla_hook((FS_Device *)Dev, FS_DRV_WRITE, SA_start);

         if (recoverable_flag == RTF_RECOVERABLE_WRITE)
         {
            if (Dev->Driver->RecoverableWriteSectors)
            {
               Result = Dev->Driver->RecoverableWriteSectors(Dev->DriverData, Sector, Sectors, Data);
            }
            else
            {
               fs_util_trace_err_noinfo(MT_NO_PROTECTIONMODE);
               fs_util_trace_info1(TRACE_ERROR, FS_ERR_WRITESECTORS_NO_PROTECTION_MODE, fs_conf_get_devtype_by_devflag(Dev->DeviceFlags), NULL);

               Result = FS_NO_PROTECTIONMODE;
            }
         }
         else if (fs_block_type == FS_NON_BLOCK_ENUM)
         {
            if (Dev->Driver->NonBlockWriteSectors)
            {
               Result = Dev->Driver->NonBlockWriteSectors(Dev->DriverData, Sector, Sectors, Data);
            }
            else
            {
               /* if not support nonblock mode, use block mode,  2005/02/16 */
               Result = Dev->Driver->WriteSectors(Dev->DriverData, Sector, Sectors, Data);
            }
         }
         else
         {
            Result = Dev->Driver->WriteSectors(Dev->DriverData, Sector, Sectors, Data);
         }

         // SWLA hooker
         fs_util_swla_hook((FS_Device *)Dev, FS_DRV_WRITE, SA_stop);

         fs_util_time_stop();
         fs_util_time_set_duration();

         // IO Trace, mark 0x10000, as a write trace
         fs_util_trace_device_io(Dev->DeviceFlags | 0x10000, Sector, Sectors, fs_util_time_query_duration());

         // For NAND flash bad block issue, Karen Hsu, 2004/02/20
         if (Result == RTF_BAD_SECTOR)
         {
            UINT drvIdx;

            fs_util_trace_err_noinfo(RTF_BAD_SECTOR);
            fs_util_trace_info4(TRACE_ERROR, FS_ERR_WRITESECTORS_BAD_SECTOR, Sector, Sectors, fs_conf_get_devtype_by_devflag(Dev->DeviceFlags), NULL, NULL);

            for (drvIdx = MT_BASE_DRIVE_INDEX; drvIdx < FS_MAX_DRIVES; drvIdx++)
            {
               if (gFS_Data.DriveTable[drvIdx].Dev != NULL)
               {
                  if (gFS_Data.DriveTable[drvIdx].Dev == Dev)
                  {
                     kal_uint32 fatStart, dataStart;
                     fatStart = gFS_Data.DriveTable[drvIdx].FirstFATSector;
                     dataStart = gFS_Data.DriveTable[drvIdx].FirstDataSector;

                     if (Sector >= fatStart && Sector < dataStart)
                     {

                        fs_util_trace_err_noinfo(MT_SYSTEM_CRASH);
                        fs_util_trace_info4(TRACE_ERROR, FS_ERR_WRITESECTORS_SYSTEM_CRASH, Sector, Sectors, fs_conf_get_devtype_by_devflag(Dev->DeviceFlags), NULL, NULL);

                        XRAISE(MT_SYSTEM_CRASH);
                     }
                  }
               }
               else break;
            }
         }

         if (Result < RTF_NO_ERROR)
         {
            fs_util_trace_err_noinfo(Result);
            fs_util_trace_info4(TRACE_ERROR, FS_ERR_WRITESECTORS_DRIVER_FAIL, Sector, Sectors, fs_conf_get_devtype_by_devflag(Dev->DeviceFlags), NULL, NULL);

            XRAISE(Result);
         }

         break;
      }
      default:

         if (((Flags & NO_CRITICAL) == 0) &&
               (HandleCriticalError(Dev, XVALUE) == RTFRetry))
         {
            XHANDLED;
            XREEXECUTE;
         }

         if (MT_MSDC_MOUNT_ERROR == XVALUE)
         {
            MTErrHdlr_RemovableDeviceRWError(Dev);
            XVALUE = MT_MSDC_WRITE_SECTOR_ERROR;
         }

         if (Flags & NO_RAISE)
         {
            Result = XVALUE;
            Dev->DevData.ErrorCondition = RTF_NO_ERROR;
            XHANDLED;
         }

         break;

      case XFINALLY:
         RTFSYSLockMutex(RTFLock, RTF_INFINITE);
         rtf_core_io_statistic(Sectors, fs_util_time_query_duration());

         break;
   XEND

   return Result;
}


#define RTF_CORE_DIR_ENTRY

DirEntry RTFAPI EntryType(const RTFDOSDirEntry * D)
{
   if (D->FileName[0] == '\0' || D->FileName[0] == '\xFF')
      return NeverUsed;
   if (D->FileName[0] == RTF_DELETED)
      return Available;
   if (D->Attributes == RTF_LONGNAME_ATTR)
      return Lfn;
   return InUse;
}

void MakePseudoRootDirEntry(RTFDrive * Drive, RTFDirEntry * DirEntry)
{
#if !defined(__NOT_SUPPORT_FAT32__)
   RTFCluster DirCluster = (Drive->FATType == RTFAT32) ? Drive->FirstDirSector : RTF_ROOT_DIR;
#else
   RTFCluster DirCluster = RTF_ROOT_DIR;
#endif /* __NOT_SUPPORT_FAT32__ */

   memset(DirEntry, 0, sizeof(*DirEntry));
   DirEntry->Dir.FileName[0] = '\\';
   memset((char *)DirEntry->Dir.FileName+1, ' ', 7+3);
   DirEntry->Dir.Attributes = RTF_ATTR_DIR;
   SET_FIRST_FILE_CLUSTER(DirEntry->Dir, DirCluster);
}

RTFDOSDirEntry *GetDir(RTFDrive * Drive, const RTFDirLocation * Pos)
{
   RTFSector Sector = CLUSTER_TO_SECTOR_DIR(Drive, Pos->Cluster) + (Pos->Index / DIRS_PER_SECTOR(Drive));
   fs_util_trace_info1(TRACE_GROUP_10, FS_TRC_RTF_GETDIR, Sector, NULL);

   return (RTFDOSDirEntry *) GetBuffer(Drive->Dev, Sector, 0) + (Pos->Index % DIRS_PER_SECTOR(Drive));
}
/*******************************************************************//**
 * Increase DSR->Index
 *
 * @par Category:
 * File System
 *
 * @return
 * 1: Sucessfully update the index for next directory entry
 * 0: No more directory entry
 **********************************************************************/
int IncDir(RTFDrive * Drive, RTFDirLocation * DSR)
{
   /* increase index */
   DSR->Index++;

   fs_util_trace_info2(TRACE_GROUP_10, FS_TRC_RTF_INCDIR, DSR->Cluster, DSR->Index, NULL);

   /* for root directory */
   if (DSR->Cluster == RTF_ROOT_DIR)
   {
      if (DSR->Index >= Drive->RootDirEntries)
         return 0;
   }
   /* for not root directory */
   else
   {
      /* get next cluster if new index is beyond this cluster */
      if (DSR->Index >= (Drive->ClusterSize/sizeof(RTFDOSDirEntry)))
      {
         RTFCluster NextCluster = GetClusterValue(Drive, DSR->Cluster);
         DSR->Index = 0;

         /* meet the end of cluster chain, finish search */
         if (NextCluster >= RTF_CLUSTER_CHAIN_END)
            return 0;

         /* update cluster number */
         DSR->Cluster = NextCluster;
      }
   }
   return 1;
}

/*******************************************************************//**
 * Go to next directory entry
 *
 * @par Category:
 * File System
 *
 * @return
 * Next directry entry pointer. If no more directory entry, return NULL.
 **********************************************************************/
RTFDOSDirEntry * RTFAPI NextDir(RTFDrive * Drive, RTFDirLocation * DSR)
{
   fs_util_trace_info0(TRACE_GROUP_10, FS_TRC_RTF_NEXTDIR, NULL);

   if (IncDir(Drive, DSR))
      return GetDir(Drive, DSR);
   else
      return NULL;
}

/*-----------------------------------*/
/* copy long file name from LFN entry, remain the Unicode format */
void RTFAPI CopyLFN(char * Name, const LFNDirEntry * LD)
{
   UINT i, index=0;
   WORD U;

   for (i=0; i<13; i++)
   {
      if(i < 5)
      {
         U = LD->Name1[i];
      }
      else if(i < 11)
      {
         U = LD->Name2[i-5];
      }
      else
      {
         U = LD->Name3[i-11];
      }

      if ((U == 0) || (U == 0xFFFF))
      {
         Name[index++] = 0;
         Name[index] = 0;
         break; // end of string
      }
      Name[index++] = U&0xff;
      Name[index++] = U>>8;
   }
}

/*-----------------------------------*/
/*In terms of WCHAR */
int RTFAPI LFNCharCount(const LFNDirEntry * LD)
{
   int i;

   for (i=0; i<13; i++)
   {
      if(i < 5)
      {
         if((UINT)(LD->Name1[i]) == 0)
            return i;
      }
      else if(i < 11)
      {
         if((UINT)(LD->Name2[i-5]) == 0)
            return i;
      }
      else
      {
         if((UINT)(LD->Name3[i-11]) == 0)
            return i;
      }
   }
   return 13;
}

BYTE RTFAPI ShortNameCheckSum(const BYTE * Name)
{
   int i;
   BYTE Sum = 0;
   for (i=0; i<11; i++)
      Sum = ((Sum & 1) ? 0x80 : 0) + (Sum >> 1) + Name[i];
   return Sum;
}

/*******************************************************************//**
 * Make a short file name string (native encoding) from a directory entry structure.
 *
 * @par Category:
 * File System
 *
 * @param[in] FileInfo        Directry entry structure, containing Native short name
 * @parma[in] MaxLength       The length of file name string buffer
 * @param[in, out] FileName   Buffer to store translated file name string
 **********************************************************************/
int RTFAPI MakeShortFileName(const RTFDOSDirEntry * FileInfo, char * FileName, UINT MaxLength)
{
    const char *LastName;
    const char *LastExt;
    int i, N, E;

    if (FileInfo->Attributes & RTF_ATTR_VOLUME)
    {
        // for volume label, copy all original FileName + ExtensionName to buffer
        if (12 > MaxLength)
        {
            return RTF_STRING_BUFFER_TOO_SMALL;
        }

        memcpy(FileName,(char*) FileInfo->FileName, 11);

        for (N = 10; N >= 0; N--)
        {
            if (FileName[N] != ' ')
            {
                FileName[N + 1] = '\0';

                break;
            }
        }

        if (N == -1)
        {
            FileName[0] = '\0';
        }

        return FS_NO_ERROR;
    }

    /* search the end of extension name */
    LastExt = FileInfo->Extension + 2;

    for (i=0; i<3; i++)
        if (LastExt[0] == ' ')
            LastExt--;

    if (LastExt == (const char*)((unsigned)FileInfo->Extension - 1))
    {
       LastExt = NULL;
    }

    /* search the end of file name */
    LastName = FileInfo->FileName + 7;

    for (i=0; i<8; i++)
        if (LastName[0] == ' ')
            LastName--;

    if (LastName == (const char*)((unsigned)FileInfo->FileName - 1))
    {
        // input file name contains nothing but all spaces, invalid file name
        fs_util_trace_err_noinfo(RTF_INVALID_FILENAME);

        return RTF_INVALID_FILENAME;
    }

    /* N: length of file name */
    N = LastName ? (LastName - FileInfo->FileName + 1) : 0;

    /* E: length of extension name */
    E = LastExt ? (LastExt - FileInfo->Extension + 1) : 0;

    /* check the length of full short name */
    if ((N+E+1+(E != 0)) > MaxLength)
        return RTF_STRING_BUFFER_TOO_SMALL;

    /* copy file name portion to FileName */
    memcpy(FileName,(char*) FileInfo->FileName, N);

    /* add '.' if extension name is existed */
    if (E)
    {
        FileName[N] = '.';
        N++;
    }

    /* copy extension name to FileName */
    memcpy(FileName + N, (char*) FileInfo->Extension, E);

    /* add tail mark */
    FileName[N+E] = '\0';

    return RTF_NO_ERROR;
}

/*-----------------------------------*/
RTFDOSDirEntry *StartDirSearch(RTFDrive * Drive, RTFCluster Cluster, UINT Index, RTFDirLocation * DSR)
{
   /* cluster number out of range */
   if ((Cluster != RTF_ROOT_DIR) && ((Cluster < 2L) || (Cluster >= Drive->Clusters)))
   {
      fs_util_trace_err_noinfo(FS_BAD_DIR_ENTRY);
      fs_util_trace_info4(TRACE_ERROR, FS_ERR_STARTDIRSEARCH_BEYOND_LAST_CLUSTER, Cluster, Index, fs_conf_get_devtype_by_devflag(Drive->Dev->DeviceFlags), NULL, NULL);
      XRAISE(FS_BAD_DIR_ENTRY);
   }

   DSR->Cluster = Cluster;
   DSR->Index   = Index;

   return GetDir(Drive, DSR);
}



void MTHintGen(RTFDirLocation *Hint, RTFDirLocation *DSR_SFN, RTFile *f)
{
#ifndef __FS_CARD_DOWNLOAD__
   if(f->DirEntry.LongPos.Cluster)
   {
      Hint->Cluster= f->DirEntry.LongPos.Cluster;
      Hint->Index= f->DirEntry.LongPos.Index;
   }
   else
   {
      Hint->Cluster= DSR_SFN->Cluster;
      Hint->Index  = DSR_SFN->Index;
   }

#ifdef __FS_OPEN_HINT__
   if (MTIsInternalHint(Hint) == 0)
#endif /* __FS_OPEN_HINT__ */
   {
      ((RTFFileOpenHint*)Hint)->Drive = (UINT)f->Drive;
      ((RTFFileOpenHint*)Hint)->SerialNumber = f->Drive->SerialNumber;
      ((RTFFileOpenHint*)Hint)->Stamp = OpenHintStamp;
   }
#endif
}

/*******************************************************************//**
 * Translate long file name (unicode) to short file name (native, DirEntry format)
 *
 * @par Category:
 * File System
 *
 * @param[in]  LongName  Long file name encoded by unicode
 * @param[out] ShortName Short file name encoded by native (DirEntry format)
 *
 * @par ChangeLog:
 * W09.48: Add INC_SHORT_NAME in case that extension name is beyond length 3. (Stanley Chu)
 * W09.07: Use SKIP_MATCH_SFN flag to decide if SFN should be skipped in SearchFile() more precisely. (Stanley Chu)
 *
 * @note:
 * 1. Validity of ASCII code must be checked, any invalid short file name is coded as '_'
 * 2. Both FileName and Extension is generated and filled in ShortName buffer.
 * 3. Lossyflag:
 *    1. Once lossyflag is set, LFN is required!
 *    2. If INC_SHORT_NAME is set, default SFN should be processed by IncShortName first before being created.
 *    3. If SKIP_MATCH_SFN is set, SearchFile can skip SFN matching to improve search time.
 **********************************************************************/
int GenerateShortName(const char * LongName, char * ShortName)
{
   const char * pN = LongName;
   char       * pF = ShortName;
   int          LossyFlag = 0;
   WCHAR        wide_c;
   char         c;
   char         encoding_length;
   const char * pSearch;

   encoding_length = fs_util_get_default_encoding_length();

   /* fill-in "spaces" to ShortName buffer in advance */
   memset(pF, ' ', 8 + 3);

   /* locate the last dot before NULL or backslash */
   for (pSearch  = pN; (pSearch[0] || pSearch[1]) && !(compASCII(pSearch, 0, '\\')) ; pSearch += 2);
   for (pSearch -=  2; (pSearch > pN) && !(compASCII(pSearch, 0, '.')) ; pSearch -= 2);

   /* set pSearch to NULL if dot-begin or dot-not-found (no extension name) */
   if (pSearch == pN)
   {
      pSearch = NULL;
   }

   /*---------------------------
    * Major file name portion
    *---------------------------*/

   while ((pN[0] || pN[1]) && !(compASCII(pN, 0, '\\')) && ((pF - ShortName) < 8))
   {
      if (compASCII(pN, 0, '.'))
      {
         /* break if last dot hit
          * otherwise, it's a multi-dot case, set LossyFlag and continue */
         if (pN == pSearch)
         {
            break;
         }

         /* ignore '.' */
         else
         {
            LossyFlag++;
            LossyFlag |= (INC_SHORT_NAME | SKIP_MATCH_SFN);
            pN += 2;
            continue;
         }
      }

      /*------ ASCII character ------*/
      if (isASCII(pN, 0))
      {
         /* ASCII character: not space */
         if (!(compASCII(pN, 0, ' ')))
         {
            c = fs_util_get_short_char(pN[0]);

            /* if this character is not supported by SFN, set lossy flag */
            if ((c == '_') && (!(compASCII(pN, 0, '_'))))
            {
               LossyFlag++;
               LossyFlag |= (INC_SHORT_NAME | SKIP_MATCH_SFN);
            }

            /* copy this ASCII character to native SFN buffer */
            *pF++ = c;
         }

         /* space */
         else
         {
            LossyFlag++;
            LossyFlag |= (INC_SHORT_NAME | SKIP_MATCH_SFN);

            /* !! space is ignored in native SFN !! */
         }
      }

      /*------ Non-ASCII character ------*/
      else
      {
         /* always set lossy flag to have a LFN if a non-ASCII character is encountered. Even though the length fits in SFN */
         LossyFlag++;

         /* need at least 2 bytes, so if the length of short name has reached 7, it is impossible to "preserve" this character */
         if ((encoding_length > 1) && (pF - ShortName) >= 7)
         {
            LossyFlag |= (INC_SHORT_NAME | SKIP_MATCH_SFN);
            break;
         }

         /* translate unicode to wide native character (need 2 bytes to store) */
         wide_c = fs_util_uni_to_native(*(kal_uint8 *)(pN) | (*(kal_uint8 *)(pN + 1) << 8));

         #ifndef __FS_NATIVE_ENCODING_TRANSPARENT__

         if (wide_c == 0xFFFF) // convert failed mark for both 8-bit and 16-bit encoding
         {
            wide_c = L'_';  // use '_' instead of invalid encoding
            LossyFlag |= (INC_SHORT_NAME | SKIP_MATCH_SFN);
            // Note: the conversion is failed, the output short name is wide_c & 0xFF = '_'
         }
         else if (encoding_length == 1) // convert successfully for 8-bit encoding
         {
            /*
             * If we try to convert UCS2 to a small encoding (e.g., 8-bit encoding),
             * the possibility of duplication is very high! (imagine convert Chinese
             * to ASCII). Therefore add flag SKIP_MATCH_SFN forcedly to skip SFN matching
             * match in SearchFile().
             */

            wide_c = (WCHAR)fs_util_gen_friendly_char((char)wide_c);
            LossyFlag |= (INC_SHORT_NAME | SKIP_MATCH_SFN);
         }
         else if (encoding_length > 1)  {  // copy 2-bytes native character to native SFN buffer
            *pF++ = wide_c >> 8;
         }

         /* Note: if unicode can be successfully translated to native code, SFN matching should
          * NOT be skipped in SearchFile! */

         #endif /* !__FS_NATIVE_ENCODING_TRANSPARENT__ */

         /*
          * If __FS_NATIVE_ENCODING_TRANSPARENT__ is defined, UnicodetoNative()
          * will return valid ASCII char, thus we only need to append one byte.
          */

         *pF++ = wide_c & 0xff;
      }

      /* goto next unicode character in source LFN */
      pN += 2;
   }

   /* if pN is NOT NULL, pN may be
    * 1. '\'
    * 2. '.'
    * 3. Other character (pN must be the 9th WCHAR), that is, the length of file name portion > 8 */

   if (pN[0] || pN[1])
   {
      /* if pN is "dot" */
      if (compASCII(pN, 0, '.'))
      {
         /* but NOT the LAST "dot", it's a multi-dot case, set lossy flag */
         if (pSearch != pN)
         {
            LossyFlag++;
            LossyFlag |= (INC_SHORT_NAME | SKIP_MATCH_SFN);
         }

         /*
          * Note if this is a multi-dot case, and if the first dot appears in any position of the
          * upfront 8 characters, INC_SHORT_NAME and SKIP_MATCH_SFN flags were set in above while-loop.
          *
          * However, in multi-dot case, if the first dot is located right after the 8th character, e.g.,
          * "MEDIATEK.IS.SO.STRONG", then INC_SHORT_NAME must be set as well to prevent following cases:
          *
          * 1. Create "MEDIATEK.1ST"
          * 2. Rename it to "MEDIATEK.1ST.1ST"
          * 3. FS_Open("MEDIATEK.1ST") will find it and confuse users.            (W10.11 Stanley Chu)
          */
      }
      /* if pN is '\' */
      else if (compASCII(pN, 0, '\\'))
      {
         // do nothing.
      }
      /* other wide characters, that is, the length of file name portion > 8. */
      else
      {
         LossyFlag++;
         LossyFlag |= (INC_SHORT_NAME | SKIP_MATCH_SFN);
      }
   }

   /* goto the last dot to handle extension name, if no extension name, pN = pSearch = NULL! */
   pN = pSearch;
   pF = ShortName + 8;

   /*---------------------------
    * Extension name portion
    *---------------------------*/

   if (pN)
   {
      /* skip '.' */
      pN += 2;

      while ((pN[0] || pN[1]) && !(compASCII(pN, 0, '\\')) && ((pF - ShortName) < 11))
      {
         /*------ ASCII character ------*/
         if (isASCII(pN, 0))
         {
            if (!compASCII(pN, 0, ' '))
            {
               c = fs_util_get_short_char(pN[0]);

               /* if this character is not supported by SFN, set lossy flag */
               if ((c == '_') && (!(compASCII(pN, 0, '_'))))
               {
                  LossyFlag++;
                  LossyFlag |= SKIP_MATCH_SFN;  // skip SFN matching in SearchFile()
               }

               *pF++ = c;
            }
            else  /* space */
            {
               LossyFlag++;
               LossyFlag |= SKIP_MATCH_SFN;  // skip SFN matching in SearchFile()
            }
         }
         /*------ Non-ASCII character ------*/
         else
         {
            LossyFlag++;

            /* there is no space to store WCHAR */
            if ((encoding_length > 1) && (pF - ShortName) >= 10)
           	{
               LossyFlag |= SKIP_MATCH_SFN;
               break;
            }

            wide_c = fs_util_uni_to_native(*(kal_uint8 *)(pN) | (*(kal_uint8 *)(pN + 1) << 8));

            #ifndef __FS_NATIVE_ENCODING_TRANSPARENT__

            /* if failed to translate UCS2 to Native, skip SFN matching in SearchFile()*/
            if (wide_c == 0xFFFF)
            {
               wide_c = L'_';
               LossyFlag |= SKIP_MATCH_SFN;  // skip SFN matching in SearchFile()
               // Note: the conversion is failed, the output short name is wide_c & 0xFF = '_'
            }
            else if (encoding_length == 1)
            {
               wide_c = (WCHAR)fs_util_gen_friendly_char((char)wide_c);
               LossyFlag |= (INC_SHORT_NAME | SKIP_MATCH_SFN);
            }
            else if (encoding_length > 1)  { // copy 2-bytes native character to native SFN buffer
               *pF++ = wide_c >> 8;
            }

            #endif /* !__FS_NATIVE_ENCODING_TRANSPARENT__ */

            /*
             * If __FS_NATIVE_ENCODING_TRANSPARENT__ is defined, UnicodetoNative()
             * will return valid ASCII char, thus we only need to append one byte.
             */

            *pF++ = wide_c & 0xff;
         }

         pN += 2;
      }

      /* if the length of extension name is longer than 3, set lossy flag. */
      if ((pN[0] || pN[1]) && !(compASCII(pN, 0, '\\')))
      {
         /*
          * Set INC_SHORT_NAME to enforce the default SFN is XXX~1.XXX when creating
          * a file.
          *
          * Otherwise, file creation will be failed if
          * Step 1. Create a.tiff (OK)
          * Step 2. Create a.tif  (Fail because SFN "A.TIF" is created in step 1,
          *         FS_FILE_EXISTS will be returned in SearchFile().
          *                                                    - W09.48 Stanley Chu -
          */

         LossyFlag++;
         LossyFlag |= (INC_SHORT_NAME | SKIP_MATCH_SFN);
      }
   }

   // check the 1st byte, convert it if it is a special mark for FAT
   if (ShortName[0] == 0xE5) ShortName[0] = 0x05; // use 0x05 instead of 0xE5

   return LossyFlag;
}
/*******************************************************************//**
 * Match two short file names (native/ASCII encoding) up to '\' or end-of-string.
 *
 * @par Category:
 * File System
 *
 * @par ChangeLog:
 * W09.04: Add one condition to exit matching loop: "When maximum length of SFN is reached". (Stanley Chu)
 *
 * @note
 * This function is only referenced by SearchFile()
 **********************************************************************/
int FNamesMatch(const char * N1, const char * N2)
{
   char c1 = 0, c2, c0;
   int  length = 11;  // maximum length of a short file name

   /*------------------------------------------------------
    * Condition for exiting matching loop:
    * 1. Two continuous NULL (current and previous characters) are encountered.
    * 2. Current character is not matched.
    * 3. Maximum length of a short file name is reached.
    *------------------------------------------------------*/

   do {
      c0 = c1;  // get previous character
      c1 = fs_util_toupper(*N1++);
      if (c1 == '\\') c1 = '\0';
      c2 = fs_util_toupper(*N2++);
      if (c2 == '\\') c2 = '\0';
   } while ((c1 || (c0 & 0x80)) && (c1 == c2) && (--length)); // for Thai encoding issues: 0xA8 0x00 0xA8 0x00 ...

   return c1 == c2;
}

/*-----------------------------------*/
int RTFAPI WFNamesMatch(const char * N1, const char * N2)
// match file name components in unicode, i.e. up to '\' or end-of-string
// operation on wide character string.
{
   WCHAR c1, c2;

   do {
      c1 = isASCII(N1,0) ? (WCHAR)fs_util_toupper(N1[0]) : *(WCHAR *)N1;
      N1+=2;
      if (c1 == 0x5c) c1 = 0;
      c2 = isASCII(N2,0) ? (WCHAR)fs_util_toupper(N2[0]) : *(WCHAR *)N2;
      N2+=2;
      if (c2 == 0x5c) c2 = 0;
   } while (c1 && (c1 == c2));

   return c1 == c2;
}

/*-----------------------------------*/
/* Note that FileName is expected to be a unicode stream */
int RTFAPI SearchFile(RTFile * f, UINT Flags, const char * FileName, RTFDirLocation * DSR_Hint)
// if path not found -> exception
// if file not found, returns 0, else 1
// if 0, the file's parent is opened
// update DirPos, DirEntry, and FullName in f->
// [X:][\][Path\][Path\]file (Unicode format)
{
   RTFDirLocation       DSR = { 0 };
   const RTFDOSDirEntry *dir_entry;
   const char           *inputName = FileName;
   char                 *pFull = f->FullName;
   BYTE                 CheckSum = 0;
   kal_bool             SkipMatchSFN;
   kal_bool             ApplyDSRHint;
   int                  LFNIndex;
   char                 nativeSFN[12], originSFN[12]; /* [Memo] 12 = 8 + . + 3 */
   int                  SearchCount = 0; // the number of directory entries traversed
   kal_uint32           start_time = 0, end_time = 0;
   const char           *ppN;
   const char           *pppN;
   #ifdef __FS_OPEN_HINT__
   kal_uint8            internal_hint = 0;
   kal_uint8            path_idx      = 0;
   kal_uint8            level         = 0;
   kal_uint8            new_hint      = 0;
   #endif

   #ifdef __FS_OPEN_HINT__
   if (DSR_Hint && MTIsInternalHint(DSR_Hint))
   {
      internal_hint = 1;
      path_idx = MTHintGetIndex(DSR_Hint);
      level    = MTHintGetLevel(DSR_Hint);
      new_hint = MTIsNewHint(DSR_Hint);
   }
   #endif

#ifndef __FS_CARD_DOWNLOAD__
    // abort check
    if (fs_fh_is_aborted((FS_File*)f) == KAL_TRUE)  // [async]
    {
        fs_util_trace_err_noinfo(FS_ABORTED_ERROR);

        XRAISE(FS_ABORTED_ERROR);
    }
#endif

   /* in "?:\" case, move inputName to '\' */
   /* [Memo] inputName
    *
    *        [X][:][\][.][\][D][i][r][\][.][\][D][i][r][\][A][B][C][.][e][x][t]
    *         * --> *
    */
   if ( (inputName[0]||inputName[1]) && compASCII(inputName, 1, ':'))
      inputName += 4;

   /* copy drive's current dir to f->FullName */
   /* [Memo] f->FullName
    *
    *        [X][:][\][D][i][r]
    *         *
    */
   fs_util_dchar_strcpy(pFull, f->Drive->CurrDir);
/*
 * Step 1
 *      Setup starting path to search
 */

   /* absolute path => start from root directory */
   if (compASCII(inputName, 0, '\\'))
   {
       /* [Memo] inputName
        *
        *        [X][:][\][.][\][D][i][r][\][.][\][D][i][r][\][A][B][C][.][e][x][t]
        *               *
        */
      MakePseudoRootDirEntry(f->Drive, &f->DirEntry);

      /* skip '\' in FileName */
      inputName += 2;
      /* [Memo] inputName
       *
       *        [X][:][\][.][\][D][i][r][\][.][\][D][i][r][\][A][B][C][.][e][x][t]
       *                  *
       */

      /* let f->FullName be "X:\", and skip "X:\" */
      pFull += 6;
      pFull[0] = '\0';
      pFull[1] = '\0';

      /* [Memo] f->FullName
       *
       *        [X][:][\][D][i][r]
       *         *
       *                  -
       *   =>   [X][:][\][0][i][r]
       *                  *
       */

   }
   /* it's a relative path */
   else
   {
      /* start from CurrDirEntry */
      f->DirEntry = f->Drive->CurrDirEntry;// TODO: replace with memcpy
      pFull += fs_util_dchar_strlen(pFull);
      /* [Memo] f->FullName
       *
       *        [X][:][\][D][i][r]
       *         *   --------->    *
       *        &1
       */

   }

LABLE_NextDir:

/*
 * Step 2
 *      Check if complete criteria matched
 */

{
   /*
    * inputName now has following possibility,
    * 1. points to '\' after last matched component (like "\ABC[\XXX]")
    * 2. NULL if inputName is terminated. (the last component of FileName is matched, or FileName is "X:\")
    * 3. points to the first component if search is just beginning.
    *        [X][:][\][.][\][D][i][r][\][A][B][C][.][e][x][t]
    *                  *
    */

   /* if inputName is NULL, we're done! (note that if FileName = "X:\", we will return 1 here) */
   if (inputName == NULL)
   {
      if (DSR_Hint)
      {
         MTHintGen(DSR_Hint, &DSR, f); // fill hint info in DSR_Hint
      }

      fs_util_trace_info2(TRACE_GROUP_9 , FS_TRC_RTF_SEARCHFILE, RTF_SEARCH_RET_FILE, __LINE__, NULL);

      return 1;
   }

   /* inputName is not terminated */

   /* skip "." and multiple "\" from inputName. Case like "\.\" will be skipped here~ */
   while ( WFNamesMatch((char *)inputName, (char *)dchar_dot) || compASCII(inputName, 0, '\\') )// || compASCII(inputName, 0, ' '))
      inputName += 2;
   /* [Memo] inputName
    *  1st round:
    *        [X][:][\][.][\][D][i][r][\][.][\][D][i][r][\][A][B][C][.][e][x][t]
    *                  * --> *
    * _______________________________________
    *  2nd round:
    *        [X][:][\][.][\][D][i][r][\][.][\][D][i][r][\][A][B][C][.][e][x][t]
    *                                    * --> *
    */


   /* now inputName points to the first character of next component or NULL */

   /* then check inputName again. If inputName is terminated, we are done! */
   if ( compASCII(inputName, 0, '\0') )
   {
      if (DSR_Hint)
      {
         MTHintGen(DSR_Hint, &DSR, f); // fill hint info in DSR_Hint
      }

      fs_util_trace_info2(TRACE_GROUP_9, FS_TRC_RTF_SEARCHFILE, RTF_SEARCH_RET_FILE, __LINE__, NULL);

      return 1;
   }

   /* add '\' in f->FullName's tail, and let pFull skip '\' */
   if ( !compASCII(pFull, -1, '\\'))
   {
       /* [Memo] f->FullName
        *
        *  after &1                        +
        *               [X][:][\][D][i][r][\]
        *                                  *
        */
      setASCII(pFull, 0, '\\');
      pFull += 2;
   }


   /* if last matched name is NOT a DIR, search can't be continued, raise PATH_NOT_FOUND */

   /* [Memo]
    *
    *     1st round: it could be pseudo root or current dir
    */
   if ((f->DirEntry.Dir.Attributes & RTF_ATTR_DIR) == 0)
   {
      fs_util_trace_err_noinfo(RTF_PATH_NOT_FOUND);

      XRAISE(RTF_PATH_NOT_FOUND);
   }

   /*
    * if there is only one component left (file name, without '\'), and we are searching the parent,
    * return 0 (not found, but parent found)
    */
       /* [Memo] inputName like the following, but might not in 1st round
        *
        *        [X][:][\]...[\][A][B][C][.][e][x][t]
        *                        *
        */

   if ((Flags & SEARCH_PARENT) && (fs_util_dchar_strchr(inputName, (int)'\\') == NULL))
   {
      fs_util_trace_info2(TRACE_GROUP_9, FS_TRC_RTF_SEARCHFILE, RTF_SEARCH_RET_PARENT, __LINE__, NULL);
      goto Return0; // TODO: RTF_SEARCH_RET_PARENT
   }
}

/*
 * Step 3
 *      Set-up start point of search
 */
{
   /* now we start to search in last matched directory */
   f->DirEntry.DirCluster = FIRST_FILE_CLUSTER(f->DirEntry.Dir);

    /*
     * check if directory entry is corrupted.
     *
     * normally FirstCluster should has a value
     */

    if (f->DirEntry.DirCluster == 0)
    {
        fs_util_trace_err_noinfo(FS_BAD_DIR_ENTRY);
        fs_util_trace_info0(TRACE_ERROR | MT_TRACE_INFO_WSTR, FS_INFO_DISK_ERROR, f->FullName);
        XRAISE(RTF_BAD_DIR_ENTRY);
    }

   ApplyDSRHint = KAL_FALSE;

   /* set start line for searching */
   if (DSR_Hint && DSR_Hint->Cluster)
   {
      #ifdef __FS_OPEN_HINT__
      if (internal_hint) // level should be > 0 here (DSR_Hint->Cluster > 0), or something wrong!
      {
         for (LFNIndex = 0; LFNIndex < level - 1; LFNIndex++)
         {
            // now inputName must on a WCHAR. Goto the nearest L'\\'
            while (*(WCHAR*)inputName && *((WCHAR*)inputName) != L'\\')/* [Memo] memory copy */
            {
               *(WCHAR*)pFull = *(WCHAR*)inputName;
               inputName += sizeof(WCHAR);
               pFull += sizeof(WCHAR);
               /* [Memo]
                *   inputName
                *   case 1:  [X][:][\][.][\][D][I][R][\][A][B][C][.][e][x][t]
                *                                        *->*
                *   case 2:  [A][B][C][.][e][x][t]
                *             *->*
                *   case 3:  [X][:][\][.][\][D][I][R][\][.][\][A][B][C][.][e][x][t]
                *                            *->*
                *   case 4:  [D][I][R][\][.][\][A][B][C][.][e][x][t]
                *             *->*
                *   f->FullName
                *                                    +
                *   case 1/2:  [X][:][\][D][I][R][\][A]
                *                                 *->*
                *                        +
                *   case 3/4:  [X][:][\][D]
                *                     *->*
                */

            }

            // add a L'\\' to the end of f->FullName
            /* [Memo]
             *   f->FullName
             *                                                            +
             *   case 1/2:     [X][:][\][D][I][R][\][A][B][C][.][e][x][t][\]
             *                                                         *->*
             *                                 +
             *   case 3/4:  [X][:][\][D][I][R][\]
             *                              *->*
             */
            *(WCHAR*)pFull = L'\\';
            pFull += sizeof(WCHAR);

            /*
             * Now inputName must on L'\\' or NULL.
             * Skip "\.\" and multiple L'\\'. Then go to the 1st WCHAR of
             * next level or don't move if it is already on NULL.
             */
                /* [Memo]
                 *   inputName
                 *   case 1:  [X][:][\][.][\]...[\][A][B][C][.][e][x][t]
                 *                                                       *
                 *   case 2:  [A][B][C][.][e][x][t]
                 *                                  *
                 *   case 3:  [X][:][\][.][\][D][I][R][\][D][I][R][\][.][\][A][B][C][.][e][x][t]
                 *                                                 *
                 *   case 4:  [D][I][R][\][.][\][A][B][C][.][e][x][t]
                 *                      *
                 */

            while ((*(WCHAR*)inputName == L'.' && *(WCHAR*)(inputName + sizeof(WCHAR)) == L'\\') ||
            	    *(WCHAR*)inputName == L'\\')
               inputName += sizeof(WCHAR);
         }

         // add NULL to the end of f->FullName
         *(WCHAR*)pFull = 0;
         /* [Memo]
          *   f->FullName
          *                                                            -
          *   case 1/2:     [X][:][\][D][I][R][\][A][B][C][.][e][x][t][0]
          *                                                            *
          *                                 -
          *   case 3/4:  [X][:][\][D][I][R][0]
          *                                 *
          */

         f->DirEntry.DirCluster = MTHintGetDirCluster(DSR_Hint);/* [Memo] apply hint's DirCluster, maybe there is value, or not */

         ApplyDSRHint = KAL_TRUE;
      }
      else
      #endif /* __FS_OPEN_HINT__ */
      {
         if (((RTFFileOpenHint*)DSR_Hint)->Stamp == OpenHintStamp &&
             ((RTFFileOpenHint*)DSR_Hint)->Drive == (UINT)f->Drive &&
             ((RTFFileOpenHint*)DSR_Hint)->SerialNumber == f->Drive->SerialNumber)
         {
            // move inputName to the last component of inputName
            ppN = inputName;
            pppN = NULL;
            end_time = (kal_uint32)pFull;  // preserve origianl pFull

            /* [Memo]
             *   inputName
             *                            *
             *   case 1:  [X][:][\][.][\][D][I][R][\][A][B][C][.][e][x][t]
             *                            3        2
             *             *
             *   case 2:  [A][B][C][.][e][x][t]
             *                                  2
             *                            *
             *   case 3:  [X][:][\][.][\][D][I][R][\][.][\][A][B][C][.][e][x][t]
             *                            3        2
             *             *
             *   case 4:  [D][I][R][\][.][\][A][B][C][.][e][x][t]
             *             3        2
             */

            while ((inputName = fs_util_dchar_strchr(inputName, '\\')) != 0)
            {
               // copy folder name in this level to f->FullName (use start_time, end_time temporarily)

               end_time = (kal_uint32)pFull;  // preserve origianl pFull

               for (start_time = (kal_uint32)ppN; start_time < (kal_uint32)inputName;)
               {
                   /* [Memo]
                    *   inputName
                    *                            *
                    *   case 1:  [X][:][\][.][\][D][I][R][\][A][B][C][.][e][x][t]
                    *                            3        2
                    *             *
                    *   case 2:  [A][B][C][.][e][x][t]
                    *                                  2
                    *                            *
                    *   case 3:  [X][:][\][.][\][D][I][R][\][.][\][A][B][C][.][e][x][t]
                    *                            3        2
                    *             *
                    *   case 4:  [D][I][R][\][.][\][A][B][C][.][e][x][t]
                    *             3        2
                    *
                    *   f->FullName
                    *                        +  +  +  <-- 3 to 2
                    *   case 1/3:  [X][:][\][D][I][R]
                    *                                 *
                    *                              +  +  +  +  +  +  +   <-- 3 to 2
                    *   case 2/4:  [X][:][\]...[\][A][B][C][.][e][x][t]
                    *                                                   *
                    */

                  *pFull++ = *(char*)start_time++;
                  *pFull++ = *(char*)start_time++;
               }

               // add '\' in f->FullName's tail
               if (!compASCII(pFull, -1, '\\'))
               {
                   /* [Memo]
                   *   f->FullName
                   *                                 +
                   *   case 1/3:  [X][:][\][D][I][R][\]
                   *                                    *
                   *                                                   +
                   *   case 2/4:  [X][:][\]...[\][A][B][C][.][e][x][t][\]
                   *                                                      *
                   */

                  setASCII(pFull, 0, '\\');
                  pFull += 2;
               }

               // skip any " ", ".", and multiple "\"
               /* [Memo]
                *   inputName
                *                            *
                *   case 1:  [X][:][\][.][\][D][I][R][\][.][\][A][B][C][.][e][x][t]
                *                            3                 2
                *             *
                *   case 2:  [D][I][R][\][.][\][A][B][C][.][e][x][t]
                *             3                 2
                */

               while ( WFNamesMatch((char *)inputName, (char *)dchar_dot) || compASCII(inputName, 0, '\\')) // || compASCII(inputName, 0, ' ') )
                  inputName += 2;

               pppN = ppN;
               ppN = inputName;
            }

            if(ppN && *ppN == 0) // case "\\(NULL)"
            {
               inputName = pppN;
               pFull = (char*)end_time; // restore pFull to last level
            }
            else // normal case
            {
               inputName = ppN; // pFull does not need change
            }

            ApplyDSRHint = KAL_TRUE;
         }
         else // stamp or drive or serial number is invalid, search from the top of a folder
         {
            ApplyDSRHint = KAL_FALSE;
         }
      }
   }
   else // DSR_Hint is invalid
   {
      ApplyDSRHint = KAL_FALSE;
   }

   if (ApplyDSRHint == KAL_TRUE)
   {
      dir_entry = StartDirSearch(f->Drive, DSR_Hint->Cluster, DSR_Hint->Index, &DSR);
   }
   else
   {
      dir_entry = StartDirSearch(f->Drive, f->DirEntry.DirCluster, 0, &DSR);
   }


   /* [Memo]
   *   f->FullName
   *                               -
   *   case 1:  [X][:][\][D][I][R][0]
   *                               *
   *                                                 -
   *   case 2:  [X][:][\]...[\][A][B][C][.][e][x][t][0]
   *                                                 *
   */
   setASCII(pFull, 0, '\0'); // add a tail to f->FullName
}

/*
 * Step 4
 *      Generate SFN for matching
 */
{
// TODO: should not do Step 4 unless dir_entry != NULL

   SkipMatchSFN = KAL_FALSE;

   // inputName[] Generate ShortFileName formats into nativeSFN[] (Native encoding) and originSFN[] (Leave it as-is)
   // nativeSFN[] and originSFN[] will be compared to the ShortFileName entry found from DIR search loop.
   // If the LFN => SFN convertion lossy, set SkipMatchSFN = KAL_TRUE
   {
      int idx = 0;
      int idx1 = 0, idx2 = 0;

      while(idx < 12)
      {
         nativeSFN[idx] = 0x20;
         originSFN[idx]= 0x20;
         idx++;
      }
      if ( fs_util_dchar_strcmp(inputName, (char *)dchar_dot_dot) == 0 )
      {
         //strcpy(nativeSFN, "..         ");
         nativeSFN[0] = 0x2e;
         nativeSFN[1] = 0x2e;
         nativeSFN[11] = 0x0;
         originSFN[0] = 0x0;
         goto StartRetrieveDIREntry;
      }
      else if ( fs_util_dchar_strcmp(inputName, (char *)dchar_dot) == 0 )
      {
         //strcpy(nativeSFN, ".          ");
         nativeSFN[0] = 0x2e;
         nativeSFN[11] = 0x0;
         originSFN[0] = 0x0;
         goto StartRetrieveDIREntry;
      }

      /*------------------------------------------------------------------------------
       * We don't make rules for the encoding of "FileName" except that every character
       * must occupy 2 bytes, thus we try every possible encoding here!
       *------------------------------------------------------------------------------*/

      /*------ TRY 1: Unicode encoding ------*/

      // formal short name algo (Special characters , convert and compare , eg.  1+1 )
      idx = GenerateShortName(inputName, nativeSFN);

      #ifdef __FS_NATIVE_ENCODING_TRANSPARENT__
      if (idx > 0)
      {
         /*
          * If __FS_NATIVE_ENCODING_TRANSPARENT__ is defined, FS will use formula to
          * generate valid ASCII char for any non-ascii unicode wchar.

          * Since the generated ASCII char is NOT unique to every non-ascii unicode,
          * we must skip SFN matching in SearchFile() to prevent incorrect matching result
          * due to duplicated SFN generated by GenerateShortName().
          *
          * For example.
          * Step 1. Create LFN: "XYZ" (XYZ are non-ASCII), SFN: "ABC~1" (OK)
          * Step 2. Create "ABC~1" (Failed because ABC~1 is existed).
          */
         SkipMatchSFN = KAL_TRUE;
         goto StartRetrieveDIREntry;
      }
      #endif /* __FS_NATIVE_ENCODING_TRANSPARENT__ */

      if (idx & SKIP_MATCH_SFN)
      {
         // lossy flag detected, raise SkipMatchSFN , But need validate in next bracket
         nativeSFN[0] = 0;
         SkipMatchSFN = KAL_TRUE;
      }

      /*------ TRY 2: Native encoding ------*/

      // Direct short name algo (API pass previous taken short name, bypass encoding and go through , eq. XYZ~1.TXT )
      {
         int non_ascii_flag = 0;
         int last_dot_pos = 0;
         idx1     = 0; // position to inputName[]     (input)
         idx2     = 0; // position to originSFN[] (output)

         while((idx2 < 11) && ((*(inputName + idx1) != 0) || (*(inputName + idx1 + 1) != 0)))
         {
            if((*(inputName + idx1) == 0x5C) && (*(inputName + idx1 + 1) == 0x0)) // ascii : back slash '\'
               break;
            if((*(inputName + idx1) == 0x2E) && (*(inputName + idx1 + 1) == 0x0)) // ascii : dot '.'
            {
               // fill-in space until filename portion reach 8 bytes
               while(idx2 < 8)
               {
                  originSFN[idx2] = 0x20;
                  idx2++;
               }

               if (last_dot_pos != 0) // dot hit again ,
               {
                  // don't need to compare SFN, originSFN[0] = 0x0; (let last_dot_pos > 8 to assign originSFN[0] = 0x0 later)
                  last_dot_pos += idx2;
                  break;
               }
               else               // dot hit once , last_dot_pos must be 8 to pass criteria
               {
                  last_dot_pos = idx2;
               }
            }
            // for non-ascii wide character. Note an example Thai encoding : 0xA8 0x00 0xA8 0x00 ... (ASCII code range: 0x00 ~ 0x7F)
            else if( (inputName[idx1] & 0x80) || (inputName[idx1 + 1] != 0x0))
            {
               // raise flag ! non-ascii character detected !
               non_ascii_flag ++;

               // copy this wchar to originSFN[]
               originSFN[idx2] = *(inputName + idx1);
               originSFN[idx2 + 1] = *(inputName + idx1 + 1);
               idx2 += 2;
            }
            // others , must be ascii
            else
            {
               // copy this char to originSFN[] (note only 1 byte is copied!)
               originSFN[idx2] = *(inputName + idx1);
               idx2++;
            }

            /* always increase idx1 by 2 because inputName(FileName) must be wide character string */
            idx1+=2;
         }

         // check if inputName[] (1) multi-dot  (2) dot at > 8th character (3) filename portion's length > 8 without any dot detected
         if ( (last_dot_pos > 8) || (last_dot_pos == 0 && idx2 > 8) )
         {
            // Don't need to compare originSFN[] string
            originSFN[0] = 0x0;
         }
         // if there are non-ascii characters...
         else if ( non_ascii_flag != 0 )
         {
            /* if inputName[] string ended, even though there are non-ascii characters, SFN matching is still required */
            if (  ((*(inputName + idx1) == 0) && (*(inputName + idx1 + 1) == 0))  // NULL
               || ((*(inputName + idx1) == 0x5C) && (*(inputName + idx1 + 1) == 0))   // '\'
               )
            {
               // invert SkipMatchSFN to compare originSFN[] string with SFN
               SkipMatchSFN = KAL_FALSE;

               /* 0xE5 special char will be treated as deleted */
               if (originSFN[0] == 0xE5)
                  originSFN[0] = 0x05;
            }
            else
            {
               // Don't need to compare originSFN[] string
               originSFN[0] = 0x0;
            }
         }
         else
         {
            // it's enough to just compare nativeSFN[] string with SFN , skip originSFN[] string
            originSFN[0] = 0x0;
         }
      }
      nativeSFN[11]  = 0x00;
      originSFN[11] = 0x00;
   }
}

StartRetrieveDIREntry:

/*
 * Step 5.
 *      Start search in current directory (last matched component)
 */
{
   LFNIndex = -1;

   /* retrieve directory entries to compare */
   while (dir_entry != NULL)
   {
      int Kind = EntryType(dir_entry);
#ifndef __FS_CARD_DOWNLOAD__
      if(start_time == 0)
      {
          start_time=kal_get_systicks();
      }

      SearchCount++;

#endif /* __FS_CARD_DOWNLOAD__ */

      if ((SearchCount & 0x000003FF) == 0)  // print log every 1024 entries
      {
         fs_util_trace_info1(TRACE_ERROR, FS_INFO_DIR_ENTRY_WALKED, SearchCount, NULL);
      }

      if (Kind == NeverUsed)
         break;  // file not found
      else if (Kind == Lfn)
      {
         const LFNDirEntry * LD = (void*) dir_entry;

         if (LD->Ord & 0x40) // it's the start of an LFN /* [Memo] Nth Long entry = LAST_LONG_ENTRY(0x40) | N */
         {
            // see if it fits
            char * Limit;

            /* get LFN entries count */
            LFNIndex = LD->Ord & 0x3F; /* [Memo] ex: 0x42 & 0x3F --> 2, so it's the 2nd lfn entry of this dir */
            CheckSum = LD->CheckSum;

            /* temporarily set LongPos to this directory entry */
            f->DirEntry.LongPos = DSR;

            /* check if current length of path + LFN fits in spec */
            /* [Memo]
             *  1) 13 * 2-> there is 13 chars in one LFN entry
             *  2) LFNCharCount -> to determine total char numbers in Name1 & Name2 & Name3
             */

            // TODO: 2 --> sizeof(WCHAR)
            Limit = pFull + (LFNIndex-1)*13*2 + 2*LFNCharCount(LD);

            if (Limit > (f->FullName+RTF_MAX_PATH-1) || Limit < pFull)
            {
               LFNIndex = -1;
            }
            else
            {
               Limit[0] = '\0';  // terminate the long name
               Limit[1] = '\0';
            }
         }

         if ((LD->CheckSum != CheckSum) || (LFNIndex != (LD->Ord & 0x3F)) || (LFNIndex <= 0))
         {
            LFNIndex = -1;
         }
         else
         {
            CopyLFN(pFull + --LFNIndex * 26, LD);  /* copy LFN to f->fullName */
      }


      }
      else if ((Kind == InUse) &&
               (((dir_entry->Attributes & ~RTF_ATTR_ARCHIVE) == RTF_ATTR_VOLUME) ==
                ((Flags & SEARCH_LABEL) == SEARCH_LABEL)))
      {
         // check against LFN first
         /* [Memo] reuse "Match" */
         int Match = (LFNIndex == 0) && (CheckSum == ShortNameCheckSum((const BYTE*) dir_entry->FileName));
         int length;

         if (!Match)
         {
            /* LFN does NOT exist or LFN is not belong to this file */
            LFNIndex = -1;
         }
         else
         {
            /* compare LFN and FileName up to '\' or end-of-string */
            Match =  WFNamesMatch(pFull, inputName);
         }

         /* LFN is NOT matched or LFN does not exist, start to compare SFN here */
         if (!Match)
         {
            if(SkipMatchSFN) goto SearchContinue;

            /* Copy SFN in directory entry into pFull */
            memcpy(pFull, (const char *)dir_entry->FileName, 8);
            memcpy(pFull + 8, (const char *)dir_entry->Extension, 3);
            pFull[11]='\0';

            Match = FNamesMatch(pFull, nativeSFN);

            if(!Match)
               Match = FNamesMatch(pFull, originSFN);

            /* SFN matched! */
            if (Match)
            {
               /* get length of dir/file name */
               if ( fs_util_dchar_strchr(inputName, 0x5c) )
                  length = fs_util_dchar_strlen(inputName) - fs_util_dchar_strlen(fs_util_dchar_strchr(inputName, 0x5c));
               else
                  length = fs_util_dchar_strlen(inputName);

               pFull[length] = pFull[length + 1] = '\0';

               /* append dir/file name (given by argument, NOT SFN) to f->fileName (WITHOUT '\') */
               fs_util_dchar_strncpy(pFull, inputName, length);
            }
         }

         /*-------------------- LFN or SFN matched! ----------------------*/
         if (Match == 1)
         {
            if (WFNamesMatch((char *)inputName, (char *)dchar_dot_dot) && compASCII(inputName, 1, '.') && (FIRST_FILE_CLUSTER(*dir_entry) == 0))  // ".." to root
               MakePseudoRootDirEntry(f->Drive, &f->DirEntry);
            else
            {
               /* copy matched directory entry to file structure */
               f->DirEntry.Dir = *dir_entry;
               f->DirEntry.ShortPos = DSR;

               /* if LFN NOT matched or NOT found, set LongPos.Cluster to 0 */
               if (LFNIndex != 0)
                  f->DirEntry.LongPos.Cluster = 0;
            }

            /* decide to go upper or deeper layer to continue searching */

            /* if inputName starts with "..", goto upper layer */
            //if (compASCII(inputName, 0, '.') && compASCII(inputName, 1, '.'))
            if (fs_util_dchar_strcmp(inputName, (char *)dchar_dot_dot) == 0)
            {
               /* delete tail of pFull */
               setASCII(pFull, -1, '\0');

               /* locate last '\' in new pFull */
               pFull = fs_util_dchar_strrchr(f->FullName, '\\');
               if (pFull == NULL)
               {
                  fs_util_trace_err_noinfo(RTF_PATH_NOT_FOUND);

                  XRAISE(RTF_PATH_NOT_FOUND);
               }

               /* if case "X:\", let pFull point to "X" */
               if ((pFull - 3*2) < f->FullName)
                  pFull += 2;

               /* goto upper layer */
               setASCII(pFull, 0, '\0');
            }
            else
            {
               #ifdef __FS_OPEN_HINT__
               if (internal_hint)
               {
                  if (new_hint)
                  {
                     // generate a new location for this hint
                     MTHintGen(DSR_Hint, &DSR, f);
                     MTHintNew(path_idx, level, DSR_Hint, f, (WCHAR*)pFull);

                     // update new level to stamp
                     MTHintSetLevel(DSR_Hint, level + 1);
                  }

                  // clear DSR_Hint to prevent being used in next level
                  DSR_Hint->Cluster = 0;
               }
               #endif

               /* goto deeper layer */
               pFull += fs_util_dchar_strlen(pFull);
            }

            /* move inputName (FileName) to the closest '\' */
            inputName = fs_util_dchar_strchr(inputName, '\\');

            /* goto next string to continue searching */

            #ifdef __FS_OPEN_HINT__
            level++;
            #endif

            goto LABLE_NextDir; /* CYLNE: [Memo] Step 2: Check if complete criteria */
         }
      }
SearchContinue: /* Optimize algo, Karen Hsu, 2004/04/28, ADD */
      if (Kind != Lfn)
         LFNIndex = -1;

      dir_entry = NextDir(f->Drive, &DSR);

      if ((SearchCount & 0x1FF) == 0)       // check once every 512 directory entry
      {
         #ifdef __FS_CARD_DOWNLOAD__
         WacthDogRestart(); // REVIEW: need to check with Carlos
         #else /* __FS_CARD_DOWNLOAD__ */

         register RTFDevice * Dev;

         //-- 1. abort check
         if (fs_fh_is_aborted((FS_File*)f) == KAL_TRUE)  // [async]
         {
            fs_util_trace_err_noinfo(FS_ABORTED_ERROR);

            XRAISE(FS_ABORTED_ERROR);
         }

         //-- 2. device lock release check
         end_time=kal_get_systicks();

         if ((end_time-start_time) > 400)  // 2 sec
         {
             Dev = f->Drive->Dev;

             if (Flags & SEARCH_RELEASE_LOCK)
             {
                 f->Task = kal_get_current_thread_ID();

                 UnlockDevice(Dev);
             }

             kal_sleep_task(20);        // wait for 100 ms.

             if (Flags & SEARCH_RELEASE_LOCK)
             {
                 LockDevice(Dev, 0);

                 if (f->Task != kal_get_current_thread_ID() || f->Lock == 0 || f->Valid == FS_FH_EXPORTED || f->Valid == FS_FH_MEDIACHANGED || f->Valid == FS_FH_ABORTED) // Does FS_FH_ABORTED required?
                 {
                     fs_util_trace_err_noinfo(RTF_INVALID_FILE_HANDLE);

                     XRAISE(RTF_INVALID_FILE_HANDLE);
                 }
             }

             start_time = 0;
         }
         #endif /* __FS_CARD_DOWNLOAD__ */
      }
   }

   /* nothing matched in this directory, searching is failed.. */

   {
      /* locate closest '\' in FileName */
      char *p1stSlash = fs_util_dchar_strchr(inputName, (int)'\\');

      /* if another '\' is found in FileName, which means we want to search a "directory" in current directory */
      if (p1stSlash != NULL)
      {
         /* if the last matched directory entry is a DIR, and only one 'directory name' is left in FileName, return 0! */
         if ( (f->DirEntry.Dir.Attributes & RTF_ATTR_DIR) && compASCII(p1stSlash, 1, 0x0) )
         {
            if ((pFull + fs_util_dchar_strlen(inputName) + 2) > (f->FullName + RTF_MAX_PATH))
            {
               fs_util_trace_err_noinfo(MT_PATH_OVER_LEN_ERROR);

               XRAISE(MT_PATH_OVER_LEN_ERROR);
            }

            /* append this name to f->fullName (even though it is not existed actually) */
            fs_util_dchar_strcpy(pFull, inputName);

            /* remove tail backslash in f->fullName */
            *(pFull + (int) ((int)p1stSlash - (int)inputName) ) = 0x0;

            fs_util_trace_info2(TRACE_GROUP_9, FS_TRC_RTF_SEARCHFILE, RTF_SEARCH_RET_PATH, __LINE__, NULL);
            return 0;
         }

         fs_util_trace_err_noinfo(RTF_PATH_NOT_FOUND);

         XRAISE(RTF_PATH_NOT_FOUND);
      }
   }

   /* if this is the last component (without tail '\'), and nothing matched in current directory, return 0! (SEARCH_FILES) */

Return0:

   // path is found, but not the file
   // complete full path name
   if ((pFull + fs_util_dchar_strlen(inputName) + 2) > (f->FullName + RTF_MAX_PATH))
   {
      // "*" or "*.*" should not be counted as part of path.
      if (!fs_util_dchar_strcmp(inputName, (char*)dchar_star) || !fs_util_dchar_strcmp(inputName, (char*)dchar_start_dot_star))
      {
         // append "*" or "*.*" for recursive engine and sort engine (replace *.* by *)
         fs_util_dchar_strcpy(pFull, (char*)dchar_star);

         return 0;
      }
      else
      {
         fs_util_trace_err_noinfo(MT_PATH_OVER_LEN_ERROR);

         XRAISE(MT_PATH_OVER_LEN_ERROR);
      }
   }

   /* append remaining FileName to f->FullName */
   fs_util_dchar_strcpy(pFull, inputName);

   return 0;
}
}



/*-----------------------------------*/
void RTFAPI FreeFTSlot(RTFile * f)
{
   memset(f, 0, sizeof(RTFile));
}

/*-----------------------------------*/
RTFHANDLE RTFAPI MakeNewFileHandle(RTFile * f)
{
   static UINT  Unique = 0;

   Unique = (Unique + 1) & UMAX;
   if (Unique == 0)
      Unique++;
   f->Unique = Unique;
   f->Valid = MT_ENUM_FH_VALID;
#ifndef __FS_CARD_DOWNLOAD__
   f->Task = kal_get_current_thread_ID();
#endif
   return (RTFHANDLE) ((f->Unique << (4*sizeof(int))) | (f - gFS_Data.FileTable));
}

/*-----------------------------------*/
extern kal_int32 GetFileHandle(RTFile *f)
{
   return (RTFHANDLE) ((f->Unique << (4*sizeof(int))) | (f - gFS_Data.FileTable));
}

/*-----------------------------------*/
void RTFAPI InitFilePointer(RTFile * f)
// set file pointer and cluster/sector/offset to 0
// to move back, you must call InitFilePointer first
// note that cluster 0 indicates unallocated space (except for the root)
{
   f->FilePointer = 0;
   f->Offset = 0;
   f->LastCluster = 0;

   /*
    * For non-FAT32 drive, only use low-word Cluster to make compatible with non-standard FirstClusterHi.
    * If a file is copied from a certain procedure (NTFS => FAT16), Windows may set FirstClusterHi as 1 for files on FAT16 drive.
    *                                                                                          - W10.41 -
    */
   if (RTFAT32 == f->Drive->FATType || RTF_ROOT_DIR == FIRST_FILE_CLUSTER(f->DirEntry.Dir))
      f->Cluster = FIRST_FILE_CLUSTER(f->DirEntry.Dir);
   else
      f->Cluster = FIRST_FILE_CLUSTER_LOW_WORD_ONLY(f->DirEntry.Dir);
}


/*******************************************************************//**
 * Commit SFN diretory entry of a specified file
 *
 * @par Category:
 * File System
 *
 * @note
 * 1. Move the file pointer and cluster/offset forward
 * 2. To move back, you must call InitFilePointer first.
 * 3. this function cannot move the file pointer beyond the allocated file size
 **********************************************************************/
void MoveFilePointer(RTFile * f, UINT Offset)
{
   kal_uint32 Ofs = f->Offset + Offset;
   #ifdef __FS_SMART_FILE_SEEKER__
   kal_uint32        next_milestone;
   kal_uint32        file_pos = f->FilePointer;
   RTFDirLocation    seek_hint = {0, 0};
   #endif

   if ((f->FilePointer + Offset) < f->FilePointer)
   {
      fs_util_trace_err_noinfo(RTF_FILE_TOO_LARGE);
      fs_util_trace_info2(TRACE_ERROR, FS_ERR_MOVEFILEPTR_WRAP_AROUND, f->FilePointer, Offset, NULL);

      XRAISE(RTF_FILE_TOO_LARGE);
   }

   #ifdef __FS_SMART_FILE_SEEKER__
   if (f->usr_ptr_type == FS_TBL_USR_PTR_MILESTONE && f->usr_ptr)
   {
      next_milestone = MTSH_GetNextStaticMilestone(f, file_pos);
   }
   else
   {
      next_milestone = 0;
   }
   #endif

   f->FilePointer += Offset;

   // root dir is a special case
   if (f->Cluster == RTF_ROOT_DIR)
   {
      f->Offset = Ofs;
      return;
   }

   while (Ofs >= f->Drive->ClusterSize)
   {
      // Exception! attempt to move beyond the last cluster
      if ((f->Cluster == 0) || (f->Cluster >= RTF_CLUSTER_CHAIN_END))
      {
         fs_util_trace_err_noinfo(RTF_FAT_ALLOC_ERROR);
         fs_util_trace_info1(TRACE_ERROR, FS_ERR_MOVEFILEPTR_BEYOND_LAST_CLUSTER, f->Cluster, NULL);

         XRAISE(RTF_FAT_ALLOC_ERROR);  // Attempt to move beyond last cluster
      }

      #ifdef __FS_SMART_FILE_SEEKER__
      if (next_milestone)
      {
         if ((file_pos >> f->Drive->ClusterShift) == (next_milestone >> f->Drive->ClusterShift))
         {
            if (f->Cluster >= RTF_CLUSTER_CHAIN_END)
               seek_hint.Cluster = f->LastCluster;
            else
               seek_hint.Cluster = f->Cluster;

            seek_hint.Index   = (file_pos >> f->Drive->ClusterShift) << f->Drive->ClusterShift;
            MTSH_AddSeekHint(f, &seek_hint, FS_SEEKHINT_TYPE_STATIC);

            next_milestone = MTSH_GetNextStaticMilestone(f, next_milestone);
         }

         file_pos += f->Drive->ClusterSize; // step to next cluster first (f->Cluster will be updated below)
      }
      #endif

      Ofs -= f->Drive->ClusterSize;

      /* f->Cluster stores current cluster number */
      f->LastCluster = f->Cluster;

      /* get cluster number of "the next" cluster, and store it to f->Cluster */
      f->Cluster = GetClusterValue(f->Drive, f->LastCluster);
   }

   /*
    * Set f->Cluster to 0 to indicate current cluster is the last cluster of a file.
    * Therefore we need f->LastCluster to keep the cluster number of the last cluster!
    */
   if (f->Cluster >= RTF_CLUSTER_CHAIN_END)
      f->Cluster = 0;

   /* record byte offset within a cluster in f->Offset */
   f->Offset = Ofs;

   #ifdef __FS_SMART_FILE_SEEKER__
   if (f->usr_ptr_type == FS_TBL_USR_PTR_MILESTONE && f->usr_ptr)
   {
      // check if static hint is required
      if (next_milestone && f->FilePointer >> f->Drive->ClusterShift == next_milestone >> f->Drive->ClusterShift)
      {
         if (f->Cluster)
            seek_hint.Cluster = f->Cluster;
         else
            seek_hint.Cluster = f->LastCluster;

         seek_hint.Index   = (f->FilePointer >> f->Drive->ClusterShift) << f->Drive->ClusterShift;
         MTSH_AddSeekHint(f, &seek_hint, FS_SEEKHINT_TYPE_STATIC);
      }
   }
   #endif
}

/*-----------------------------------*/
UINT MoveFilePointerSegment(RTFile * f, UINT Offset)
// move the sector aligned file pointer and cluster/offset forward within
// one segment of contiguous clusters.
// return value is length of segment in bytes.
// the file pointer is advanced by the same value.
// this function can move less bytes then requested
{
   kal_uint32 Ofs = f->Offset + Offset;
   #ifdef __FS_SMART_FILE_SEEKER__
   kal_uint32        next_milestone = 0;
   kal_uint32        file_pos = f->FilePointer;
   RTFDirLocation    seek_hint = {0, 0};
   #endif

   /* [EXCEPTION] attempt to move backward */
   if ((f->FilePointer + Offset) < f->FilePointer)
   {
      fs_util_trace_err_noinfo(RTF_FILE_TOO_LARGE);
      fs_util_trace_info2(TRACE_ERROR, FS_ERR_MOVEFILEPTR_WRAP_AROUND, f->FilePointer, Offset, NULL);

      XRAISE(RTF_FILE_TOO_LARGE);
   }

   // root dir is a special case
   if (f->Cluster == RTF_ROOT_DIR)
   {
      f->FilePointer += Offset;
      f->Offset = 0;
      return Offset;
   }

   #ifdef __FS_SMART_FILE_SEEKER__
   if (f->usr_ptr_type == FS_TBL_USR_PTR_MILESTONE && f->usr_ptr)
   {
      next_milestone = MTSH_GetNextStaticMilestone(f, file_pos);
   }
   else
   {
      next_milestone = 0;
   }
   #endif

   while (Ofs >= f->Drive->ClusterSize)
   {
      #ifdef __FS_SMART_FILE_SEEKER__
      if (next_milestone)
      {
         if ((file_pos >> f->Drive->ClusterShift) == (next_milestone >> f->Drive->ClusterShift))
         {
            if (f->Cluster >= RTF_CLUSTER_CHAIN_END)
               seek_hint.Cluster = f->LastCluster;
            else
               seek_hint.Cluster = f->Cluster;

            seek_hint.Index   = (file_pos >> f->Drive->ClusterShift) << f->Drive->ClusterShift;
            MTSH_AddSeekHint(f, &seek_hint, FS_SEEKHINT_TYPE_STATIC);

            next_milestone = MTSH_GetNextStaticMilestone(f, next_milestone);
         }

         file_pos += f->Drive->ClusterSize; // step to next cluster first (f->Cluster will be updated below)
      }
      #endif

      Ofs -= f->Drive->ClusterSize;

      f->LastCluster = f->Cluster;

      f->Cluster = GetClusterValue(f->Drive, f->LastCluster);

      /*
       * Case 1. If f->Cluster is the last cluster of file, which means f->Offset is located in this cluster,
       * not the end. Then this condition will be true and MoveFilePointerSegment() will
       * move file pointer to the end of this cluster only!
       *
       * This imply that in RTFWrite()'s l2 part, it will write data to cluster-aligned offset first,
       * then write other data starting from the next cluster. 2 writes may happen!
       *
       * Case 2. It is the end of this segment!
       */
      if (f->Cluster != (f->LastCluster + 1))
      {
         /* in this segment, we have walked (Offset - Ofs) bytes (the return value) */
         Offset -= Ofs;
         Ofs = 0;
      }
   }

   /* mark f->Cluster to 0 to indicate this is the last cluster of a file */
   if (f->Cluster >= RTF_CLUSTER_CHAIN_END)
      f->Cluster = 0;

   f->FilePointer += Offset;
   f->Offset = Ofs;

   #ifdef __FS_SMART_FILE_SEEKER__
   if (f->usr_ptr_type == FS_TBL_USR_PTR_MILESTONE && f->usr_ptr)
   {
      // check if static hint is required
      if (next_milestone && f->FilePointer >> f->Drive->ClusterShift == next_milestone >> f->Drive->ClusterShift)
      {
         if (f->Cluster)
            seek_hint.Cluster = f->Cluster;
         else
            seek_hint.Cluster = f->LastCluster;

         seek_hint.Index   = (f->FilePointer >> f->Drive->ClusterShift) << f->Drive->ClusterShift;
         MTSH_AddSeekHint(f, &seek_hint, FS_SEEKHINT_TYPE_STATIC);
      }
   }
   #endif

   return Offset;
}

RTFCluster fs_srv_get_cluster_value(RTFDrive * Drive, RTFCluster Cluster, kal_uint32 Option, fs_func_get_buffer GetBufferFunc)
{
    RTFCluster Result = 0;
    kal_uint32 Sector = 0;
    kal_uint8 *FAT = NULL;

    if ((Option == FS_GET_CLUSTER_DEFAULT) &&
        ((Cluster != 1) || (gMT_Sanity != KAL_TRUE)) &&
        ((Cluster < 2l) || (Cluster >= Drive->Clusters)))
    {
        fs_util_trace_err_noinfo(RTF_FAT_ALLOC_ERROR);
        fs_util_trace_info1(TRACE_ERROR, FS_ERR_GETCLUSTERVALUE_INVALID_IN_CLUSTER, Cluster, NULL);

        XRAISE(RTF_FAT_ALLOC_ERROR);
    }

   switch (Drive->FATType)
   {
      case RTFAT12:
      {
         kal_uint32 Pos;
         UINT       B1, B2;
         BYTE      *FATPtr;

         Pos    = Cluster + Cluster / 2;     // 0 1 3 4 6 7 9 10 12 13
         Sector = Drive->FirstFATSector + (Pos >> Drive->Dev->DevData.SectorShift);
         FATPtr = GetBufferFunc(Drive->Dev, Sector, 0);
         B1     = FATPtr[Pos & (Drive->Dev->DevData.SectorSize-1)];

         Pos++;
         Sector = Drive->FirstFATSector + (Pos >> Drive->Dev->DevData.SectorShift);
         FATPtr = GetBufferFunc(Drive->Dev, Sector, 0);
         B2     = FATPtr[Pos & (Drive->Dev->DevData.SectorSize-1)];

         Result = (Cluster & 1) ? ((B2 << 4) | (B1 >> 4)) : (((B2 & 0x0F) << 8) | B1);
         if (Result >= 0xFF7)
            Result |= 0x0FFFF000;
         FAT=(kal_uint8*)FATPtr;
         break;
      }
      case RTFAT16:
      {
         WORD * FATPtr;
         Sector = Drive->FirstFATSector + (Cluster >> (Drive->Dev->DevData.SectorShift-1));
         FATPtr = GetBufferFunc(Drive->Dev, Sector, 0);
         Result = FATPtr[Cluster & ((Drive->Dev->DevData.SectorSize >> 1)-1)];
         if (Result >= 0xFFF7)
            Result |= 0x0FFF0000;
         FAT=(kal_uint8*)FATPtr;
         break;
      }
#if !defined(__NOT_SUPPORT_FAT32__)
      case RTFAT32:
      {
         kal_uint32 * FATPtr;
         Sector = Drive->FirstFATSector + (Cluster >> (Drive->Dev->DevData.SectorShift-2));
         FATPtr = GetBufferFunc(Drive->Dev, Sector, 0);
         Result = FATPtr[Cluster & ((Drive->Dev->DevData.SectorSize >> 2)-1)] & 0x0FFFFFFF;
         FAT=(kal_uint8*)FATPtr;
         break;
      }
#endif /* __NOT_SUPPORT_FAT32__ */
      default:
         fs_err_internal_fatal(FS_ERR_CLUSTER_01, (void*)(Drive->FATType));
   }

   /* check cluster value validity, if not valid, raise FAT_ALLOC_ERROR */
   if ((Option == FS_GET_CLUSTER_DEFAULT) &&
       (Result != 0) &&
       (Result < 0x0FFFFFF7) &&
       (gMT_Sanity != KAL_TRUE) &&
       ((Result < 2) || (Result >= Drive->Clusters)))
   {
      fs_util_trace_err_noinfo(RTF_FAT_ALLOC_ERROR);
      fs_util_trace_info4(TRACE_ERROR, FS_ERR_GETCLUSTERVALUE_INVALID_OUT_CLUSTER, Cluster, Result, Result, Sector, NULL);
      fs_util_trace_info1(TRACE_ERROR, FS_INFO_DISK_ERROR2, (MT_BASE_DRIVE_LETTER + (Drive - gFS_Data.DriveTable)), NULL);
      if (FAT!=NULL)
          kal_buffer_trace(TRACE_ERROR, FS_INFO_FAT_SECTOR, FS_BUFFER_SIZE, FAT);
      XRAISE(RTF_FAT_ALLOC_ERROR);
   }

   return Result;
}

#define RTF_CORE_MOUNT
/*******************************************************************//**
 * Allocate a drive
 *
 * @par Category:
 * File System
 *
 * @note
 * 1. Search drive table starting from DriveLetter, find the frist slot with NULL device ptr,
 * then allocate this slot to the specified device.
 * 2. No device access
 * 3. Device's FirstDrive is the LAST drive to be allocated!!
 *
 * @Return
 * NULL : Too many drives, this drive can't be mounted.
 * Drive: Allocated drive
 **********************************************************************/
RTFDrive * AllocateDrive(char DriveLetter, RTFDevice * Dev)
{
   RTFDrive * Drive;

   if ((DriveLetter < 'C') && (Dev->DeviceType == FS_DEVICE_FDISK))
      DriveLetter = 'C';

   while (1)
   {
      if ((DriveLetter - MT_BASE_DRIVE_LETTER) >= FS_MAX_DRIVES)
         return NULL;

      Drive = gFS_Data.DriveTable + DriveLetter - MT_BASE_DRIVE_LETTER;
      if (Drive->Dev == Dev)
         break;

      /*
       * Find the frist slot with NULL device ptr in drive table.
       * The last found drive will be FisrtDrive, and the first found drive's NextDrive will be NULL.
       */
      if (Drive->Dev == NULL)
      {
         Drive->Dev = Dev;
         Drive->NextDrive = Dev->DevData.FirstDrive;
         Dev->DevData.FirstDrive = Drive;
         break;
      }
      DriveLetter++;
   }

   Drive->MountState = NotMounted;

   return Drive;
}


/*-----------------------------------*/
static char InitLogicalDrive(char DriveLetter,
                                    RTFDevice * Dev,
                                    RTFPartitionRecord * Geometry,
                                    RTFSector PartitionSector)
// sets up a drive with informationm from a partition entry
// no device access, but the caller must have read a partition
// table or guess at the format of a floppy
{
   RTFDrive * Drive;

   Drive = AllocateDrive(DriveLetter, Dev);
   if (Drive == NULL) // can't mount, too many drives
      return DriveLetter;

   Drive->MountState = Mounted;
   Drive->Geometry = *Geometry;
   Drive->FirstSector = PartitionSector + Geometry->RelativeSector;
   return MT_BASE_DRIVE_LETTER + (Drive - gFS_Data.DriveTable) + 1; // return next drive letter
}



/*-----------------------------------*/
void CheckMedia(RTFDevice * Dev)
{
   if ((Dev->DevData.MediaRemovedReported == 0) ||
       (Dev->DevData.MediaPresent == 0))
   {
      Dev->DevData.MediaRemovedReported = 1;

      fs_util_trace_err_noinfo(RTF_MEDIA_CHANGED);
      fs_util_trace_info1(TRACE_ERROR, FS_ERR_MEDIA_NOT_PRESENT, fs_conf_get_devtype_by_devflag(Dev->DeviceFlags), NULL);

      XRAISE(RTF_MEDIA_CHANGED);
   }
}

void CheckDirEntry(RTFile *f)
{
    kal_uint32 C;

    if (f->SpecialKind!=NormalFile) return;

    C=FIRST_FILE_CLUSTER(f->DirEntry.Dir);

    if ( (C == 1L) ||    // Note: The Rule Must Sync with CheckDir() at FS_SanityCheck()
         ((C < RTF_CLUSTER_CHAIN_END) && (C >= f->Drive->Clusters)) ||
         ((C != RTF_ROOT_DIR) && (C>RTF_CLUSTER_CHAIN_END+7)))   {
         fs_util_trace_err_noinfo(FS_BAD_DIR_ENTRY);
         fs_util_trace_info4(TRACE_ERROR, FS_ERR_DIRENTRY_INVALID_START_CLUSTER, C, C, f->Drive->Clusters, f->Drive->Clusters, NULL);
         fs_util_trace_info0(TRACE_ERROR | MT_TRACE_INFO_WSTR, FS_INFO_DISK_ERROR, f->FullName);
         XRAISE(RTF_BAD_DIR_ENTRY);
    }
}

void RTFAPI UnmountDevice(RTFDevice * Dev, int CloseFiles)
{
   UINT i;
   RTFile * f = gFS_Data.FileTable;
   RTFDrive * D = Dev->DevData.FirstDrive;

   /* clean ALL file table slots */
   if (CloseFiles)
      for (i=0; i<FS_MAX_FILES; i++, f++)
         if (f->Dev == Dev)
            FreeFTSlot(f);

   /* Drive: set all drives in Dev to NotMounted */
   while (D)
   {
      D->MountState = NotMounted;

   #ifndef __FS_CARD_DOWNLOAD__
      MTExpireDirCacheByDrive(D);   // expire dir cache
   #endif

      #ifdef __FS_OPEN_HINT__
      MTHintExpireByDrive(D);       // expire internal open hint
      #endif

      D = D->NextDrive;
   }

   /* discard all device's buffers */
   DiscardAllBuffers(Dev);

   // reset write protection flag because in MountDevice, write protection flag will NOT be clear.
   Dev->DeviceFlags &= ~MT_DEVICE_WRITE_PROTECT;

   /* Device: set device to NotMounted */
   Dev->DevData.MountState = NotMounted;
}

/*-----------------------------------*/
static int GetDiskGeometry(RTFDevice * Dev, RTFPartitionRecord * DiskGeometry, BYTE * MediaDescriptor)
{
   int volatile Result;
   RTFSYSFreeMutex(RTFLock);
   XTRY
      case XCODE:
         CheckMedia(Dev);
         if (Dev->DevData.MountState < Initialized)
            Result = RTF_DRIVE_NOT_READY;
         else
            if (Dev->Driver->GetDiskGeometry)
               Result = Dev->Driver->GetDiskGeometry(Dev->DriverData, DiskGeometry, MediaDescriptor);
            else
               Result = RTF_UNSUPPORTED_DRIVER_FUNCTION;
         break;
      default:
         Result = XVALUE;
         XHANDLED;
         break;
      case XFINALLY:
         RTFSYSLockMutex(RTFLock, RTF_INFINITE);
         break;
   XEND
   return Result;
}

/*-----------------------------------*/
int rtf_core_mount_device(RTFDevice * Dev, DWORD Flags)
{
   int volatile Result;
   int Status;
   RTFSYSFreeMutex((RTFMutex *)RTFLock);
   XTRY
      case XCODE:
         Dev->DevData.MediaRemovedReported = 1;
         CheckMedia(Dev);
         Dev->DevData.ErrorCondition = RTF_NO_ERROR;
         Dev->DevData.MediaDescriptor = 0;

         kal_mem_set((void *)&Dev->DevData.Geometry, 0, sizeof(Dev->DevData.Geometry));
         Dev->DevData.MountState = Initialized;

         Result = Dev->Driver->MountDevice(Dev->DriverData, Dev->DeviceNumber, Dev->DeviceType, Dev->DeviceFlags);

         if (Result < RTF_NO_ERROR)
         {
            Dev->DevData.ErrorCondition = Result;

            fs_util_trace_err_noinfo(Result);
            fs_util_trace_info1(TRACE_ERROR, FS_ERR_MOUNTDEVICE_DRIVER_MOUNT_FAIL, fs_conf_get_devtype_by_devflag(Dev->DeviceFlags), NULL);

            XRAISE(Result);
         }

         Dev->DevData.ErrorCondition = RTF_NO_ERROR;

         if (Result > RTF_MIN_BUFFER_SIZE)
         {
            fs_util_trace_err_noinfo(RTF_INVALID_SECTOR_SIZE);
            fs_util_trace_info1(TRACE_ERROR, FS_ERR_MOUNTDEVICE_INVALID_SECTOR_SIZE, fs_conf_get_devtype_by_devflag(Dev->DeviceFlags), NULL);

            XRAISE(RTF_INVALID_SECTOR_SIZE);
         }

         if (!fs_util_is_power_two(Result))
         {
            fs_util_trace_err_noinfo(RTF_INVALID_SECTOR_SIZE);
            fs_util_trace_info1(TRACE_ERROR, FS_ERR_MOUNTDEVICE_INVALID_SECTOR_SIZE, fs_conf_get_devtype_by_devflag(Dev->DeviceFlags), NULL);

            XRAISE(RTF_INVALID_SECTOR_SIZE);
         }

         /* set device's sector size to the return value of driver (MountDevice) */
         Dev->DevData.SectorSize = Result;
         Dev->DevData.SectorShift = 0;
         while ((1 << Dev->DevData.SectorShift) < Dev->DevData.SectorSize)
            Dev->DevData.SectorShift++;

         break;
      default:
         if (Flags & NO_RAISE)
         {
            Result = XVALUE;
            XHANDLED;
         }
         break;
      case XFINALLY:
         RTFSYSLockMutex(RTFLock, RTF_INFINITE);
         break;
   XEND
   if (Result >= RTF_NO_ERROR)
   {
      /*
       * NOTE: If FS_DEVICE_WRITE_PROTECTION flag is set already in gFS_DeviceList,
       * we keep it even if this device is not write protected by driver's report.
       */
      if((Status = GetDiskGeometry(Dev, &Dev->DevData.Geometry, &Dev->DevData.MediaDescriptor)) == RTF_WRITE_PROTECTION)
         Dev->DeviceFlags |= MT_DEVICE_WRITE_PROTECT;

      Dev->DevData.MountState = Mounted;
   }
   /* Reserve drive name for mount error device, Karen Hsu, 2004/03/04, ADD START */
   else
   {
      if((Status = GetDiskGeometry(Dev, &Dev->DevData.Geometry, &Dev->DevData.MediaDescriptor)) != 0)
      {
         if(Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
            NorPartition = KAL_TRUE;
         else if(Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
            NandPartition = KAL_TRUE;
      }
   }

   if (Status == MT_MSDC_NOT_PRESENT)
   {
      fs_util_trace_err_noinfo(Status);
      fs_util_trace_info0(TRACE_ERROR, FS_ERR_MOUNTDEVICE_MSDC_NOT_PRESENT, NULL);

      Dev->DevData.MountState = NotMounted;
      Result = Status;
   }
   /* Reserve drive name for mount error device, Karen Hsu, 2004/03/04, ADD END */
   return Result;
}

/*-----------------------------------*/
#define FS_MAX_AUTO_FORMAT_RETRY (1)

static char INTERN ScanPartitionTable(char volatile DriveLetter,
                                      RTFDevice * Dev,
                                      int PartitionKind)
// raises no exceptions
{
#if !defined(__FS_SLIM_EXTENDED_PARTITION__)
   kal_uint32 ExOffset = 0; /* Remove RVCT warning, Karen Hsu, 2004/11/02, MOD */
   int ExPartition = -1;   // see if we have an extended partition
#endif
   int i;
   int PrimPartitions = 0; // count primary partitions
   int DriveOffset = 0;
   RTFMasterBootRecord * MBR;
   int retry = 0;

    do
    {
        MBR = GetBuffer(Dev, 0, 0);

        Dev->DevData.MountState = Accessible;

        if (MBR->Signature != 0xAA55)
        {
            fs_util_trace_err_noinfo(RTF_CORRUPTED_PARTITION_TABLE);
            fs_util_trace_info2(TRACE_ERROR, FS_ERR_SCANPTABLE_MBR_SIG, MBR->Signature, fs_conf_get_devtype_by_devflag(Dev->DeviceFlags), NULL);

#ifndef __FS_CARD_DOWNLOAD__

            // try to auto format device (low + high) for device with flag FS_DEVICE_AUTO_FORMAT
            if ((Dev->DeviceFlags & FS_DEVICE_AUTO_FORMAT) && (retry < FS_MAX_AUTO_FORMAT_RETRY))
            {
                // auto format will directly r/w sectors via driver. Flush and discard all buffers first.
                FlushAllBuffers(Dev);
                DiscardAllBuffers(Dev);

                DriveOffset = fs_fmt_self_format((FS_Device*)Dev, FS_DEVICE_FDISK);

                if (DriveOffset != RTF_NO_ERROR)
                {
                    XRAISE(DriveOffset);
                }

                retry++;

                continue;   // try again
            }

#endif // !__FS_CARD_DOWNLOAD__

            XRAISE(RTF_CORRUPTED_PARTITION_TABLE);
        }

        break;

    } while (1);

   Dev->DevData.MountState = HasFileSystem;

   // process primary partions first
   for (i=0; i<4; i++)
   {
      switch (MBR->PTable[i].OSType)
      {
         // primary partions with FAT12/FA16
         case 0x01:
         case 0x04: // max 32MB, 1024 cylinder
         case 0x06: // max  2GB, 1024 cylinder
         case 0x0B: // FAT-32 CHS
         case 0x0C: // FAT-32 LBA
         case 0x0E: // max 2GB, more than 1024 cylinder
               PrimPartitions++;

               if ((PrimPartitions == 1) && (PartitionKind & RTF_PARTITION_FIRST_PRIMARY) &&
                  (Dev->DeviceFlags & MT_DEVICE_CHECK_PART) && (MBR->PTable[i].BootIndicator != 0x80))
               {
                  Dev->DevData.MountState = Accessible;

                  fs_util_trace_err_noinfo(RTF_CORRUPTED_PARTITION_TABLE);
                  fs_util_trace_info2(TRACE_ERROR, FS_ERR_SCANPTABLE_BOOT_INDICATOR, MBR->PTable[i].BootIndicator, fs_conf_get_devtype_by_devflag(Dev->DeviceFlags), NULL);

                  XRAISE(RTF_CORRUPTED_PARTITION_TABLE);
               }

               if (((PrimPartitions == 1) && (PartitionKind & RTF_PARTITION_FIRST_PRIMARY)) ||
                   ((PrimPartitions > 1) && (PartitionKind & RTF_PARTITION_OTHER_PRIMARY)))
                  DriveLetter = InitLogicalDrive(DriveLetter,
                                              Dev,
                                              MBR->PTable + i,
                                              0);
            break;
         case 0x05: // extended DOS partition max 2GB, max 1024 cylinder
         case 0x0F: // ditto, more than 1024 cylinder
#if !defined(__FS_SLIM_EXTENDED_PARTITION__)
            ExOffset = MBR->PTable[i].RelativeSector;
            ExPartition = i;
#endif
         default:   // ignore anything else
            break;
      }
   }

#if !defined(__FS_SLIM_EXTENDED_PARTITION__)
   if (PartitionKind & RTF_PARTITION_EXTENDED)
   {
      // Process extended partions.
      // Note that we support only one extended partition on a drive,
      // but this partition can contain any number of logical drives
      while (ExPartition != -1)
      {
         ExPartition = -1;

         MBR = GetBuffer(Dev, ExOffset + DriveOffset, 0);

         if (MBR->Signature != 0xAA55)
         {
            fs_util_trace_err_noinfo(RTF_CORRUPTED_PARTITION_TABLE);
            fs_util_trace_info2(TRACE_ERROR, FS_ERR_SCANPTABLE_EXT_MBR_SIG, MBR->Signature, fs_conf_get_devtype_by_devflag(Dev->DeviceFlags), NULL);

            XRAISE(RTF_CORRUPTED_PARTITION_TABLE);
         }

         for (i=0; i<4; i++)
         {
            switch (MBR->PTable[i].OSType)
            {
               // primary partions with FAT12/FAT16
               case 0x01:
               case 0x04: // max 32MB, 1024 cylinder
               case 0x06: // max 2GB, 1024 cylinder
               case 0x0B: // FAT-32 CHS
               case 0x0C: // FAT-32 LBA
               case 0x0E: // max 2GB, more than 1024 cylinder
                  DriveLetter = InitLogicalDrive(DriveLetter,
                                                 Dev,
                                                 MBR->PTable + i,
                                                 ExOffset + DriveOffset);
                  break;
               case 0x05: // extended DOS partition max 2GB, max 1024 cylinder
               case 0x0F: // ditto, more than 1024 cylinder
                  if (MBR->PTable[i].RelativeSector <= DriveOffset)
                  {
                     fs_util_trace_err_noinfo(RTF_CORRUPTED_PARTITION_TABLE);
                     fs_util_trace_info2(TRACE_ERROR, FS_ERR_SCANPTABLE_RELATIVE_SECTOR, MBR->PTable[i].RelativeSector, fs_conf_get_devtype_by_devflag(Dev->DeviceFlags), NULL);

                     XRAISE(RTF_CORRUPTED_PARTITION_TABLE);
                  }

                  DriveOffset = MBR->PTable[i].RelativeSector;
                  ExPartition = i;
               default:   // ignore anything else
                  break;
            }
         }
      }
   }
#endif   // !__FS_SLIM_EXTENDED_PARTITION__

   return DriveLetter;
}

/*-----------------------------------*/
static char INTERN ReserveLogicalDrive(char DriveLetter, RTFDevice * Dev)
// this is called for removable devices at startup
// it does not access the device and creates exactly one
// logical drive
{
   RTFDrive * Drive = AllocateDrive(DriveLetter, Dev);

   if (Drive == NULL)        // can't mount, too many drives
      return DriveLetter;
   else
      return MT_BASE_DRIVE_LETTER + (Drive - gFS_Data.DriveTable) + 1; // return next drive letter
}


void MountPartitions(RTFDevice * Dev)
// mount all partitions
{
   switch (Dev->DeviceType)
   {
      case RTF_DEVICE_FDISK:
         ScanPartitionTable('C', Dev, RTF_PARTITION_ALL);
         break;
      case RTF_DEVICE_FLOPPY:
         Dev->DevData.Geometry.OSType = 1;
         InitLogicalDrive(MT_BASE_DRIVE_LETTER + (Dev->DevData.FirstDrive - gFS_Data.DriveTable), Dev, &Dev->DevData.Geometry, 0);
         break;
      #ifdef DEBUG
      default:
         fs_err_internal_fatal(FS_ERR_MOUNT_01, NULL);
      #endif
   }
}

#ifndef __FS_CARD_DOWNLOAD__
static kal_int32 FS_GetBootMode(void)
{
    PW_CTRL_GET_POWERON_REASON CtrlVal;
    DCL_HANDLE pmu_handle;
    pmu_handle = DclPW_Open(DCL_PW, FLAGS_NONE);
    DclPW_Control(pmu_handle, PW_CMD_GET_POWERON_REASON, (DCL_CTRL_DATA_T *)&CtrlVal);
    DclPW_Close(pmu_handle);

    return (kal_int32)CtrlVal.powerOnReason;
}
#endif

/*-----------------------------------*/
void RTFAPI MountLogicalDrive(RTFDrive * Drive, MountStates State)
// prepares drive or device for a file open operation
// all required mounting is done, if required
// devices are identified by State == Initialized
{
   WCHAR driver_X[]={0x58, 0x3a, 0x5c, 0};  /*X:\\*/

   if (Drive->Dev == NULL)
   {
      XRAISE(RTF_DRIVE_NOT_FOUND);
   }

   XTRY
      case XCODE:
         if (Drive->Dev->DevData.MountState < Mounted)
         {
            int Result;

            if((Drive->Dev->DevData.MountState == NotMounted) &&
               (Drive->Dev->DeviceFlags & RTF_DEVICE_REMOVABLE))
            {
               Drive->MountState = NotMounted;
            }

            Result = rtf_core_mount_device(Drive->Dev, 0);

            if (Drive->Dev->DevData.MountState < Mounted)
            {
               fs_util_trace_info2(TRACE_ERROR, FS_ERR_MOUNTDRIVE_DEV_MOUNT_FAIL, fs_conf_get_devtype_by_devflag(Drive->Dev->DeviceFlags), Drive->Dev->DevData.MountState, NULL);

               XRAISE(Result);
            }
         }

         // don't get here if the device is not mounted

         if (Drive->MountState < Mounted)
         {
            MountPartitions(Drive->Dev);

            if (Drive->MountState < Mounted)
            {
               fs_util_trace_info2(TRACE_ERROR, FS_ERR_MOUNTDRIVE_DRV_MOUNT_FAIL, fs_conf_get_devtype_by_devflag(Drive->Dev->DeviceFlags), Drive->MountState, NULL);

               XRAISE(RTF_DRIVE_NOT_FOUND);
            }
         }

         /* get PBR to check if it is reasonable and fill drive structure */
         {
            RTFBootRecord * BR = GetBuffer(Drive->Dev, Drive->FirstSector, 0);
            RTFSector RootDirSectors, DataSectors;

            Drive->MountState = Accessible;

            /* NearJump[0]: Both 0xEB and 0xE9 are acceptable */
            if ((BR->Signature != 0xAA55) ||
               ((Drive->Dev->DeviceFlags & MT_DEVICE_CHECK_PART) &&
               (BR->NearJump[0] != 0xE9) && (BR->NearJump[0] != 0xEB)))
            {
               fs_util_trace_info4(TRACE_ERROR, FS_ERR_MOUNTDRIVE_INVALID_FS_SIG, BR->Signature, BR->NearJump[0], fs_conf_get_devtype_by_devflag(Drive->Dev->DeviceFlags), NULL, NULL);

               XRAISE(RTF_INVALID_FILE_SYSTEM);
            }

            if (BR->BP.BytesPerSector != Drive->Dev->DevData.SectorSize)
            {
               fs_util_trace_info2(TRACE_ERROR, FS_ERR_MOUNTDRIVE_INVALID_FS_SEC, BR->BP.BytesPerSector, fs_conf_get_devtype_by_devflag(Drive->Dev->DeviceFlags), NULL);

               XRAISE(RTF_INVALID_SECTOR_SIZE);
            }

            if (fs_util_is_power_two(BR->BP.SectorsPerCluster))
               Drive->SectorsPerCluster = BR->BP.SectorsPerCluster;
            else
               if ((BR->BP.SectorsPerCluster & 0x80) &&
                   ((BR->BP.SectorsPerCluster & 0x7F) >= 8) &&
                   ((BR->BP.SectorsPerCluster & 0x7F) <= 15))
                  Drive->SectorsPerCluster = 1 << (BR->BP.SectorsPerCluster & 0x7F);
               else
               {
                  fs_util_trace_info2(TRACE_ERROR, FS_ERR_MOUNTDRIVE_INVALID_FS_SPC, BR->BP.SectorsPerCluster, fs_conf_get_devtype_by_devflag(Drive->Dev->DeviceFlags), NULL);

                  XRAISE(RTF_INVALID_FILE_SYSTEM);
               }

            Drive->ClusterShift = 1;
            while ((1l << Drive->ClusterShift) < (1l * Drive->Dev->DevData.SectorSize * Drive->SectorsPerCluster))
               Drive->ClusterShift++;

            Drive->SPerCShift = 0;
            while ((1 << Drive->SPerCShift) < Drive->SectorsPerCluster)
               Drive->SPerCShift++;

            /* if BPB_TotalSector16 != 0, let BPB_TotalSector32 = BPB_TotalSector16 */
            if (BR->BP.SectorsOnDisk != 0)
               BR->BP.TotalSectors = BR->BP.SectorsOnDisk;

            Drive->FirstFATSector = Drive->FirstSector + BR->BP.ReservedSectors;
            Drive->FATCount = BR->BP.NumberOfFATs;
            RootDirSectors = (BR->BP.DirEntries * 32 + (BR->BP.BytesPerSector - 1)) / BR->BP.BytesPerSector;
            DataSectors = BR->BP.TotalSectors
                        - BR->BP.ReservedSectors
                        - (Drive->FATCount * (BR->BP.SectorsPerFAT ? BR->BP.SectorsPerFAT : BR->BP.E._32.SectorsPerFAT))
                        - RootDirSectors;

            Drive->Clusters = DataSectors >> Drive->SPerCShift;

            if (Drive->Clusters <= 0xFF4L)
               Drive->FATType = RTFAT12;
            else if (Drive->Clusters <= 0xFFF4l)
               Drive->FATType = RTFAT16;
#if !defined(__NOT_SUPPORT_FAT32__)
            else if (Drive->Clusters <= 0xFFFFFF4l)
               Drive->FATType = RTFAT32;
#endif /* __NOT_SUPPORT_FAT32__ */
            else
            {
               fs_util_trace_info2(TRACE_ERROR, FS_ERR_MOUNTDRIVE_INVALID_FS_FAT_TYPE, Drive->Clusters, fs_conf_get_devtype_by_devflag(Drive->Dev->DeviceFlags), NULL);

               XRAISE(RTF_INVALID_FILE_SYSTEM);
            }

            Drive->Clusters += 2;  // make that logical clusters

#if !defined(__NOT_SUPPORT_FAT32__)
            if (Drive->FATType == RTFAT32)
            {
               /* BPB_FSVer should be 0.0 */
               if (BR->BP.E._32.Version != 0)
               {
                  fs_util_trace_info2(TRACE_ERROR, FS_ERR_MOUNTDRIVE_INVALID_FS_FAT32_VER, BR->BP.E._32.Version, fs_conf_get_devtype_by_devflag(Drive->Dev->DeviceFlags), NULL);

                  XRAISE(RTF_INVALID_FILE_SYSTEM);
               }

               Drive->SectorsPerFAT = BR->BP.E._32.SectorsPerFAT;
               Drive->FirstDataSector = Drive->FirstFATSector + Drive->FATCount * Drive->SectorsPerFAT;
               Drive->FirstDirSector = BR->BP.E._32.RootDirCluster; // not a sector
               Drive->RootDirEntries = 0;
               Drive->SerialNumber = BR->BP.E._32.BPB.SerialNumber;
               Drive->InfoSector = (BR->BP.E._32.FSInfoSector != 0xFFFF) ? (Drive->FirstSector + BR->BP.E._32.FSInfoSector) : 0;
               // if FAT mirroring is disabled, pretend we only have one FAT
               if (BR->BP.E._32.Flags & 0x80)
               {
                  Drive->FATCount = 1;
                  Drive->FirstFATSector = Drive->FirstSector
                                        + BR->BP.ReservedSectors
                                        + (BR->BP.E._32.Flags & 0x0F)
                                          * BR->BP.E._32.SectorsPerFAT;
               }
            }
            else
#endif /* __NOT_SUPPORT_FAT32__ */
            {
               Drive->SectorsPerFAT = BR->BP.SectorsPerFAT;
               Drive->FirstDirSector = Drive->FirstFATSector + Drive->FATCount * Drive->SectorsPerFAT;
               Drive->FirstDataSector = Drive->FirstDirSector + RootDirSectors;
               Drive->RootDirEntries = BR->BP.DirEntries;
               Drive->SerialNumber = BR->BP.E._16.BPB.SerialNumber;
               Drive->InfoSector = 0;
            }
            Drive->ClusterSize = 1l << Drive->ClusterShift;

            /* make current directory as root directory */
            fs_util_dchar_strcpy(Drive->CurrDir, (char *)driver_X);
            Drive->CurrDir[0] = MT_BASE_DRIVE_LETTER + (Drive - gFS_Data.DriveTable);
            MakePseudoRootDirEntry(Drive, &Drive->CurrDirEntry);

            // do some plausibility checks

            if (BR->BP.ReservedSectors == 0)
            {
               fs_util_trace_info1(TRACE_ERROR, FS_ERR_MOUNTDRIVE_INVALID_FS_RESERVED_SEC, fs_conf_get_devtype_by_devflag(Drive->Dev->DeviceFlags), NULL);

               XRAISE(RTF_INVALID_FILE_SYSTEM);
            }

            if ((Drive->FATCount < 1) || (Drive->FATCount > 2))
            {
               fs_util_trace_info2(TRACE_ERROR, FS_ERR_MOUNTDRIVE_INVALID_FS_FAT_CNT, Drive->FATCount, fs_conf_get_devtype_by_devflag(Drive->Dev->DeviceFlags), NULL);

               XRAISE(RTF_INVALID_FILE_SYSTEM);
            }

            if (Drive->SectorsPerFAT == 0)
            {
               fs_util_trace_info1(TRACE_ERROR, FS_ERR_MOUNTDRIVE_INVALID_FS_FAT_SIZE, fs_conf_get_devtype_by_devflag(Drive->Dev->DeviceFlags), NULL);

               XRAISE(RTF_INVALID_FILE_SYSTEM);
            }

            if (Drive->SectorsPerCluster == 0)
            {
               fs_util_trace_info1(TRACE_ERROR, FS_ERR_MOUNTDRIVE_INVALID_FS_ZERO_SPC, fs_conf_get_devtype_by_devflag(Drive->Dev->DeviceFlags), NULL);

               XRAISE(RTF_INVALID_FILE_SYSTEM);
            }
         /* Check Sectors Range of Drive-onto-Device , WCP_SW , 2005/09/13, ADD START */
            /* Check If Logical Sectors Larger than Physical Sectors
             * -----------------------------------------------------
             *  This modification is a trade-off solution come from a special case.
             *  Which a cluster-overflow-formatted card will stop response once
             *  out-of-valid sector written.
             *  On spec, card must response error when try to write wrong sector.
             *  Another approach on driver is to check range every sector write.
             *  But it degrad the performance.
             *  Yet another proposal is reject mount for this case.
             *  But Windows can mount this card and make user confused.
             *  So the trade-off solution is try to limit drive cluster value at initialize.
             * */
            while ( (Drive->FirstDataSector + (Drive->Clusters - 2) * Drive->SectorsPerCluster)
                 /* Max Logical Sector */ > (Drive->Dev->DevData.Geometry.Sectors) /* Max Physical Sector */ )
            {
               Drive->Clusters--;

               fs_util_trace_info1(TRACE_ERROR, FS_ERR_MOUNTDRIVE_TOO_MANY_LOGI_SEC, fs_conf_get_devtype_by_devflag(Drive->Dev->DeviceFlags), NULL);

               if (Drive->Dev->DevData.Geometry.Sectors == 0)
               {
                  Drive->Dev->DevData.MountState = NotMounted;

                  fs_util_trace_info1(TRACE_ERROR, FS_ERR_MOUNTDRIVE_MEDIA_CHANGED, fs_conf_get_devtype_by_devflag(Drive->Dev->DeviceFlags), NULL);

                  XRAISE(RTF_MEDIA_CHANGED);
               }
               if (((Drive->Clusters - 2) * Drive->SectorsPerCluster) <= Drive->FirstDataSector)
               {
                  break;
               }
            }
         /* Check Sectors Range of Drive-onto-Device , WCP_SW , 2005/09/13, ADD END */

         }

         Drive->MountState = HasFileSystem;

         #ifdef __FS_LIMITED_DISK_SIZE__
         if (((Drive->Clusters - 2) * Drive->SectorsPerCluster)
             > (FS_MAX_DISK_SIZE * (1024 * 1024 / Drive->Dev->DevData.SectorSize)))
         {
               Drive->MountState = SizeExceeded;
               XRAISE(MT_DISK_SIZE_TOO_LARGE);
         }
         #endif // __FS_LIMITED_DISK_SIZE__

         #ifndef __FS_CARD_DOWNLOAD__
         // mark all clusters who cross sector boundary as Bad Cluster to avoid using it in the future! (powerloss issue, FAT12 only)
         {
             kal_uint32 cluster_group, cluster_crossed, cluster_value;

             XTRY
                 case XCODE:
                     if (Drive->FATType == RTFAT12)
                      {
                         for (cluster_group = 0; cluster_group < Drive->Clusters; cluster_group += FS_FAT12_CLUSTER_CROSSING_SECTOR_GROUP)
                         {
                             for (cluster_crossed = cluster_group + FS_FAT12_CLUSTER_CROSSING_SECTOR_OFFSET;
                                  cluster_crossed < (cluster_group + FS_FAT12_CLUSTER_CROSSING_SECTOR_GROUP - 1) && cluster_crossed < Drive->Clusters;
                                  cluster_crossed += FS_FAT12_CLUSTER_CROSSING_SECTOR_OFFSET)
                             {
                                 cluster_value = GetClusterValue(Drive, cluster_crossed);

                                 if (cluster_value == 0)
                                 {
                                     SetClusterValue(Drive, cluster_crossed, RTF_BAD_CLUSTER);
                                 }
                             }

                             FlushAllBuffersInGeometryOrder(Drive->Dev);
                         }
                      }

                     break;
                 default:
                     XHANDLED;
                     break;
                 case XFINALLY:
                     break;
             XENDX
         }
         #endif

         // system drive
         if (Drive->Dev->DeviceNumber == gFS_DeviceNumOfSYSDRV)
         {
            Drive->FreeClusterCount = 0;
            Drive->ClusterWatermark = RTF_INVALID_CLUSTER;
         }
         // other drives
         else {
            Drive->FreeClusterCount = RTF_INVALID_CLUSTER;  // FS_GetDiskInfo will ident this value
            Drive->ClusterWatermark = 2;
         }

#ifndef __FS_CARD_DOWNLOAD__
         // Always ount free clusters right away
         // 1. at system init
         // 2. at FS_LockFAT(FS_REMOUNT_ENUM) or FS_TestMSDC, FS_DEVICE_COUNT_FREE_CLUSTER will be set before call MountRemovableDevice().
         if ((kal_query_systemInit() == KAL_TRUE) ||
             (Drive->Dev->DeviceNumber == gFS_DeviceNumOfSYSDRV) ||
             (Drive->Dev->DevData.Reserved & FS_DEVICE_COUNT_FREE_CLUSTER))  {
            BatchCountFreeClusters(Drive);
         }
         // Add Alarm Mode boot check for memory cards (Font Support)
         else if (Drive->Dev->DeviceFlags & RTF_DEVICE_REMOVABLE)    {
            kal_int32 bootmode;
            bootmode=FS_GetBootMode();
            if (bootmode==RTCPWRON) {
                BatchCountFreeClusters(Drive);
            }
         }
#endif

#if 0 /* Fix FAT32 display wrong free size, Karen Hsu, 2005/06/06, REM */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if (defined(__FS_SHADOW_NAND__) || defined(__FS_SHADOW_CARD__))
         if (kal_query_boot_mode() != USBMS_BOOT)
         {
            InitShadowFAT(Drive);
         }
#endif
         break;
      default:
         fs_util_trace_err_noinfo(XVALUE);

         if (((State <= Initialized) && (Drive->Dev->DevData.MountState >= State)) || (Drive->MountState >= State))
            XHANDLED;

         break;
      case XFINALLY:
#ifndef __FS_CARD_DOWNLOAD__
         MTExpireDirCacheByDrive(Drive);  // reset dir cache in mount stage (W10.28)
#endif
         #ifdef __FS_OPEN_HINT__
         MTHintExpireByDrive(Drive);      // reset internal open hint in mount stage (W10.28)
         #endif

         break;
   XENDX
}

int MountRemovableDevice(RTFDevice *Dev)
{
   volatile int Result = RTF_NO_ERROR;

   fs_assert_local(Dev != NULL);

   XTRY
      case XCODE:
         SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Dev, RTF_INFINITE);
         DiscardAllBuffers(Dev);
         /* Here we assume only one drive on the dev */
         MountLogicalDrive(Dev->DevData.FirstDrive, HasFileSystem);
         break;
      default:
         if (MT_MSDC_MOUNT_ERROR == XVALUE || MT_DISK_SIZE_TOO_LARGE == XVALUE)
         {
            Result = XVALUE;

            fs_util_trace_err_noinfo(Result);
         }
         else
         {
            XTRY
               case XCODE:
                  SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Dev, RTF_INFINITE);
                  Dev->DeviceType = RTF_DEVICE_FLOPPY;
                  MountLogicalDrive(Dev->DevData.FirstDrive, HasFileSystem);
                  break;
               default:
                  Result = XVALUE;
                  XHANDLED;
                  Dev->DevData.MountState = NotMounted;
                  break;
               case XFINALLY:
                  Dev->DeviceType = FS_DEVICE_FDISK;
                  break;
            XENDX
            /* XTRY ~ XENDX Block don't return directly */
            if (Result == RTF_NO_ERROR)
               XVALUE = RTF_NO_ERROR;
            else
            {
               XVALUE = MT_MSDC_MOUNT_ERROR;

               fs_util_trace_err_noinfo(Result);
            }
         }
         break;
      case XFINALLY:
         SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV);
         break;
   XEND_API

   return Result;
}

#ifndef __FS_CARD_DOWNLOAD__
/*************************************************************************
* FUNCTION
*  RTFSYSErrorExit
*
* DESCRIPTION
*  This function implements to filesystem fatal error handler
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void RTFAPI
RTFSYSErrorExit(const char * Message, UINT ExitCode)
{
	kal_fatal_error_handler(KAL_ERROR_FILESYS_INTERNAL_FAILED, ExitCode);
}

void fs_lock_init()
{
    if (NULL == _gfs_lock_common)
    {
        _gfs_lock_common = fs_lock_alloc_mutex("FSComLock", FS_LOCK_TYPE_DEFAULT);
    }
}

FS_Mutex* fs_lock_alloc_mutex(const char *name, fs_lock_type_enum type)
{
    if (FS_LOCK_TYPE_DEFAULT == type)
    {
        return (FS_Mutex*)RTFSYSAllocMutex(name);
    }

    return NULL;
}

void fs_lock_free_mutex(FS_Mutex *mutex)
{
    //--- RTFiles implementation

    RTFSYSFreeMutex((RTFMutex*)mutex);
}

int fs_lock_get_mutex(FS_Mutex *mutex, kal_uint32 timeout)
{
    //--- RTFiles implementation

    return RTFSYSLockMutex((RTFMutex*)mutex, (kal_uint32)timeout);
}


/*************************************************************************
* FUNCTION
*  _rtfLock
*
* DESCRIPTION
*  This function implements to set and lock
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
#if defined(WIN32)
CRITICAL_SECTION CS;    // CRITICAL_SECTION is defined in "windows.h"

BYTE
_rtfLock(BYTE * Lock)
{
	kal_uint8 tmp;
	static kal_uint8 first = 0;

   if(!first)
   {
      InitializeCriticalSection(&CS);
      first = 1;
   }

   EnterCriticalSection(&CS);

	tmp = *Lock;
	*Lock = 1;

	LeaveCriticalSection(&CS);

	return tmp;
}
#else
BYTE
_rtfLock(BYTE * Lock)
{
	kal_uint8 tmp;
	kal_uint32 savedmask;

	/* Critical Section */
	savedmask = SaveAndSetIRQMask();

	tmp = *Lock;
	*Lock = 1;

	RestoreIRQMask(savedmask);

	return tmp;
}
#endif

/*******************************************************************//**
 * Promise task only takes one lock
 *
 * @par Category:
 * File System (MTK Internal Enhancement)
 *
 * @note
 * Free mutex until rtf_lock_count equals to 1
 **********************************************************************/
int RTFAPI SafeLock(DWORD Lock, RTFDevice * Dev, DWORD Timeout)
{
   int Result = RTF_NO_ERROR;

   if(kal_query_systemInit() == KAL_TRUE) //for sanity check
      return Result;

   if(Lock & MT_LOCK_FMT)
   {
      Result = RTFSYSLockMutex(MTFMLock, Timeout);
      if(Result < RTF_NO_ERROR)
         return Result;
      while(MTFMLock->rtf_lock_count > 1)
         RTFSYSFreeMutex(MTFMLock);
   }

   if(Lock & MT_LOCK_EXT)
   {
      Result = RTFSYSLockMutex(MTXLock, Timeout);
      if(Result < RTF_NO_ERROR)
         return Result;
      while(MTXLock->rtf_lock_count > 1)
         RTFSYSFreeMutex(MTXLock);
   }

   if(Lock & MT_LOCK_MOVE)
   {
      Result = RTFSYSLockMutex(MTMoveLock, Timeout);
      if(Result < RTF_NO_ERROR)
         return Result;
      while(MTMoveLock->rtf_lock_count > 1)
         RTFSYSFreeMutex(MTMoveLock);
   }

   if(Lock & MT_LOCK_XDEL)
   {
      Result = RTFSYSLockMutex(MTXdelLock, Timeout);
      if(Result < RTF_NO_ERROR)
         return Result;
      while(MTXdelLock->rtf_lock_count > 1)
         RTFSYSFreeMutex(MTXdelLock);
   }

#ifdef __FS_SORT_SUPPORT__
   if(Lock & MT_LOCK_SORT)
   {
      Result = RTFSYSLockMutex(MTSortLock, Timeout);
      if(Result < RTF_NO_ERROR)
         return Result;
      while(MTSortLock->rtf_lock_count > 1)
         RTFSYSFreeMutex(MTSortLock);
   }
#endif

   if(Lock & MT_LOCK_DISKIF)
   {
      Result = RTFSYSLockMutex(MTDiskInfoLock, Timeout);
      if(Result < RTF_NO_ERROR)
         return Result;
      while(MTDiskInfoLock->rtf_lock_count > 1)
         RTFSYSFreeMutex(MTDiskInfoLock);
   }

   if(Lock & MT_LOCK_DEV)
   {
      if((Dev) && (Dev->DeviceType & (RTF_DEVICE_FDISK | RTF_DEVICE_REMOVABLE)))
      {
         Result = RTFSYSLockMutex(Dev->DevData.Lock, Timeout);
         if(Result < RTF_NO_ERROR)
            return Result;

         while(Dev->DevData.Lock->rtf_lock_count > 1)
            RTFSYSFreeMutex(Dev->DevData.Lock);
      }
   }

   if(Lock & MT_LOCK_RTF)
   {
      fs_init();

      Result = RTFSYSLockMutex(RTFLock, Timeout);
      if(Result < RTF_NO_ERROR)
         return Result;
      while(RTFLock->rtf_lock_count > 1)
         RTFSYSFreeMutex(RTFLock);
   }

   return Result;
}

/* Promise task exits without holding lock */
int RTFAPI SafeUnlock(DWORD Lock)
{
   int Result = RTF_NO_ERROR;
   RTFDevice * Dev;

   if(kal_query_systemInit() == KAL_TRUE) //for sanity check
      return Result;

   if((Lock & MT_LOCK_RTF) || (Lock & MT_LOCK_ALL))
   {
      while(RTFSYSOwnMutex(RTFLock) == KAL_TRUE)
         RTFSYSFreeMutex(RTFLock);
   }

   if((Lock & MT_LOCK_DEV) || (Lock & MT_LOCK_ALL))
   {
      for (Dev = gFS_DeviceList; Dev->DeviceType; Dev++)
      {
         while(RTFSYSOwnMutex(Dev->DevData.Lock) == KAL_TRUE)
         {
            if (Dev->DevData.B)
               FreeBuffer(Dev);
            RTFSYSFreeMutex(Dev->DevData.Lock);
         }
      }
   }

   if(Lock & MT_LOCK_DISKIF)
   {
      while(RTFSYSOwnMutex(MTDiskInfoLock) == KAL_TRUE)
         RTFSYSFreeMutex(MTDiskInfoLock);
   }

#ifdef __FS_SORT_SUPPORT__
   if((Lock & MT_LOCK_SORT) || (Lock & MT_LOCK_ALL))
   {
      while(RTFSYSOwnMutex(MTSortLock) == KAL_TRUE)
         RTFSYSFreeMutex(MTSortLock);
   }
#endif

   if((Lock & MT_LOCK_XDEL) || (Lock & MT_LOCK_ALL))
   {
      while(RTFSYSOwnMutex(MTXdelLock) == KAL_TRUE)
         RTFSYSFreeMutex(MTXdelLock);
   }

   if((Lock & MT_LOCK_MOVE) || (Lock & MT_LOCK_ALL))
   {
      while(RTFSYSOwnMutex(MTMoveLock) == KAL_TRUE)
         RTFSYSFreeMutex(MTMoveLock);
   }

   if((Lock & MT_LOCK_EXT) || (Lock & MT_LOCK_ALL))
   {
      while(RTFSYSOwnMutex(MTXLock) == KAL_TRUE)
         RTFSYSFreeMutex(MTXLock);
   }

   if((Lock & MT_LOCK_FMT) || (Lock & MT_LOCK_ALL))
   {
      while(RTFSYSOwnMutex(MTFMLock) == KAL_TRUE)
         RTFSYSFreeMutex(MTFMLock);
   }

   return Result;
}

/*-----------------------------------*/
void RTFAPI UnlockDevice(RTFDevice * Dev)
{
   /* free inuse buffer */
   if (Dev->DevData.B)
      FreeBuffer(Dev);
   if (Dev->DevData.ErrorCondition < RTF_NO_ERROR)
      UnmountDevice(Dev, 1);

#ifdef DEBUG
   EntryExitCheck(Dev, XHANDLER);
#endif
   /* free system lock */
   RTFSYSFreeMutex(RTFLock);

   /* free device lock */
   RTFSYSFreeMutex(Dev->DevData.Lock);
#ifdef DEBUG
   CheckReleased(XHANDLER);
#endif
}

/*******************************************************************//**
 * Lock both device and system lock (non-blocking mode)
 *
 * @par Category:
 * File System
 *
 * @note
 * Increase device's access count whenever device is locked.
 **********************************************************************/
void RTFAPI LockDevice(RTFDevice * Dev, UINT Flags)
{
   int status;
   kal_uint32 timeout;

   /*--------------------------------------------------------------------------
    * SysLockFAT is only set in FS_LockFAT(FS_LOCK_USB_ENUM) and used by USB boot-up mode.
    * Since 09A, USB boot-up mode uses FS_LockFAT(FS_EXPORT_ENUM) instead to allow system
    * drive access by NVRAM.
    *--------------------------------------------------------------------------*/
   if(INT_QueryExceptionStatus() == KAL_FALSE) //allow to write exception record
      fs_assert_local(SysLockFAT == 0);

   if (CardBusyCheck && (Dev->DeviceFlags & RTF_DEVICE_REMOVABLE) && !(Flags & FS_NOBUSY_CHECK_MODE))
   {
      if (Dev->DevData.FirstDrive) // e.g., for dual T-card platform, drive letter is required to distinguish different memory card devices.
      {
         status = FS_GetDevStatus(MT_BASE_DRIVE_LETTER + (Dev->DevData.FirstDrive - gFS_Data.DriveTable), FS_FEATURE_STATE_ENUM);
      }
      else
      {
         status = FS_GetDevStatus(FS_DEVICE_TYPE_CARD, FS_FEATURE_STATE_ENUM);
      }

      if (status == MT_DEVICE_BUSY)
      {
         fs_util_trace_err_noinfo(status);
         fs_util_trace_info1(TRACE_ERROR, FS_ERR_NONBLOCKLOCKDEVICE_DEVICE_BUSY, fs_conf_get_devtype_by_devflag(Dev->DeviceFlags), NULL);

         XRAISE(status);
      }
   }

   if (Flags & FS_NONBLOCK_MODE)
   {
      timeout = RTF_NO_WAIT;
   }
   else
   {
      timeout = RTF_INFINITE;
   }

   status = RTFSYSLockMutex(Dev->DevData.Lock, timeout);

   if(status != RTF_NO_ERROR)
   {
      fs_util_trace_err_noinfo(status);
      fs_util_trace_info1(TRACE_ERROR, FS_ERR_NONBLOCKLOCKDEVICE_LOCK_DEV_FAIL, fs_conf_get_devtype_by_devflag(Dev->DeviceFlags), NULL);

      XRAISE(status);
   }

   status = RTFSYSLockMutex(RTFLock, timeout);

   if(status != RTF_NO_ERROR)
   {
      fs_util_trace_err_noinfo(status);
      fs_util_trace_info1(TRACE_ERROR, FS_ERR_NONBLOCKLOCKDEVICE_LOCK_RTF_FAIL, fs_conf_get_devtype_by_devflag(Dev->DeviceFlags), NULL);

      RTFSYSFreeMutex(Dev->DevData.Lock); /* Fix always occupy device lock bug, Karen Hsu, 2005/01/30, ADD */
      XRAISE(status);
   }

   Dev->DevData.AccessCount++;
}

/*******************************************************************//**
 * Find device lock
 *
 * @par Category:
 * File System
 *
 * @note
 * Return existed device's lock with the same driver. If not found, allocate one
 * using device's friendly name as the semaphore name.
 **********************************************************************/
RTFMutex * FindDeviceLock(RTFDevice * Dev, RTFDriver * Driver, const char * Name)
{
   for (; Dev >= gFS_DeviceList; Dev--)
      if (Dev->Driver == Driver)
         return Dev->DevData.Lock;
   return RTFSYSAllocMutex(Name);
}


#endif /* !__FS_CARD_DOWNLOAD__ */

/*-----------------------------------*/
static void INTERN InitDevices(void)
{
   RTFDevice * Dev;

   for (Dev = gFS_DeviceList; Dev->DeviceType; Dev++)
   {
      //if ((Dev->Driver->Version < 200) || (Dev->Driver->Version > RTFILE_VER))
         //RTFSYSErrorExit("Dev driver version mismatch", 1);

      if (Dev->DeviceType == FS_DEVICE_FLOPPY)
      {
         Dev->DeviceFlags |= RTF_DEVICE_REMOVABLE;
      }

      Dev->DevData.MediaPresent = (Dev->DeviceFlags & RTF_DEVICE_NO_MEDIA) == 0;
      Dev->DevData.MediaRemovedReported = 1;
      Dev->DevData.PhysicalDiskIndex = -1;

      strcpy(Dev->DevData.FriendlyName, "Disk X");
      Dev->DevData.FriendlyName[5] = (Dev - gFS_DeviceList) + '0';

    #ifndef __FS_CARD_DOWNLOAD__
      /* set device's lock */
      if (Dev->DevData.Lock == NULL)
      {
         /* allocate another lock for this device */
         if (Dev->DeviceFlags & RTF_DEVICE_NEW_LOCK)
            Dev->DevData.Lock = RTFSYSAllocMutex(Dev->DevData.FriendlyName);
         /* share one lock for the same device driver */
         else
            Dev->DevData.Lock = FindDeviceLock(Dev-1, Dev->Driver, Dev->DevData.FriendlyName);
      }
   #endif /* __FS_CARD_DOWNLOAD__ */
   }
}
/*-----------------------------------*/
static char INTERN LockedScanPartitionTable(char volatile DriveLetter,
                                            RTFDevice * Dev,
                                            int PartitionKind)
{
   XTRY // just to keep CheckReleased happy
      case XCODE:
         XTRY
            case XCODE:
               LockDevice(Dev, 0);
               DriveLetter = ScanPartitionTable(DriveLetter, Dev, PartitionKind);
               break;
            default:
               XHANDLED;
               break;
            case XFINALLY:
               UnlockDevice(Dev);
               break;
         XENDX
         break;
      default:
         break;
      case XFINALLY:
         break;
   XENDX
   return DriveLetter;
}

/*-----------------------------------*/
void ScanDevices(void)
{
   RTFDevice *Dev;
   char      DriveLetter = MT_BASE_DRIVE_LETTER;
   int       DiskIndex = 0;
   /* Dynamic assign device number, Karen Hsu, 2005/06/08, MOD START */
   int i = 1;

   // distribute disk indexes
   for (Dev = gFS_DeviceList; Dev->DeviceType; Dev++)
   {
      Dev->DeviceNumber = i;
      i++;
      if (Dev->DeviceType == FS_DEVICE_FDISK)
         Dev->DevData.PhysicalDiskIndex = DiskIndex++;
      else
         Dev->DevData.PhysicalDiskIndex = -1;
   }
   /* Dynamic assign device number, Karen Hsu, 2005/06/08, MOD END */

   // mount devices if they are not removeable
   for (Dev = gFS_DeviceList; Dev->DeviceType; Dev++)
      if ((Dev->DeviceFlags & RTF_DEVICE_REMOVABLE) == 0)
         rtf_core_mount_device(Dev, NO_RAISE);

   // mount first primary partitions in every device
   // ignore RTF_MOUNT_CONTIGUOUS devices
   for (Dev = gFS_DeviceList; Dev->DeviceType; Dev++)
   {
      if (Dev->DeviceFlags & RTF_DEVICE_MOUNT_CONTIGUOUS)
         continue;
      if (Dev->DeviceType == FS_DEVICE_FLOPPY)
      {
         DriveLetter = ReserveLogicalDrive(DriveLetter, Dev);
      }
      else
      {
         if (Dev->DevData.MountState >= Mounted)
            DriveLetter = LockedScanPartitionTable(DriveLetter, Dev, RTF_PARTITION_FIRST_PRIMARY);
         /* Reserve drive name for mount error device, Karen Hsu, 2004/03/04, ADD START */
         else if((Dev->DeviceFlags & RTF_DEVICE_REMOVABLE) == 0)
         {
            UINT idx;
            for(idx = MT_BASE_DRIVE_INDEX; idx < FS_MAX_DRIVES; idx++)
               if(gFS_Data.DriveTable[idx].Dev == NULL)
                  break;
            AllocateDrive(MT_BASE_DRIVE_LETTER + idx, Dev);
         }
         /* Reserve drive name for mount error device, Karen Hsu, 2004/03/04, ADD END */
      }
   }

   #if !defined(__FS_SLIM_EXTENDED_PARTITION__)
   // mount extended partitions in every device
   for (Dev = gFS_DeviceList; Dev->DeviceType; Dev++)
      if (((Dev->DeviceFlags & (RTF_DEVICE_REMOVABLE | RTF_DEVICE_MOUNT_CONTIGUOUS)) == 0) &&
          (Dev->DevData.MountState >= Mounted))
      {
         DriveLetter = LockedScanPartitionTable(DriveLetter, Dev, RTF_PARTITION_EXTENDED);
      }
   #endif   // !__FS_SLIM_EXTENDED_PARTITION__

   // mount other primary partitions in every device
   for (Dev = gFS_DeviceList; Dev->DeviceType; Dev++)
      if (((Dev->DeviceFlags & (RTF_DEVICE_REMOVABLE | RTF_DEVICE_MOUNT_CONTIGUOUS)) == 0) &&
          (Dev->DevData.MountState >= Mounted))
      {
         DriveLetter = LockedScanPartitionTable(DriveLetter, Dev, RTF_PARTITION_OTHER_PRIMARY);
      }
      /* Reserve drive name for mount error device, Karen Hsu, 2004/03/04, ADD START */
      else if((Dev->DeviceType & RTF_DEVICE_REMOVABLE) == 0)
      {
         if(((Dev->DeviceFlags & MT_DEVICE_NOR_FLASH) && NorPartition) ||
            ((Dev->DeviceFlags & MT_DEVICE_NAND_FLASH) && NandPartition))
         {
            UINT idx;
            for(idx = MT_BASE_DRIVE_INDEX; idx < FS_MAX_DRIVES; idx++)
               if(gFS_Data.DriveTable[idx].Dev == NULL)
                  break;
            AllocateDrive(MT_BASE_DRIVE_LETTER + idx, Dev);
         }
      }
      /* Reserve drive name for mount error device, Karen Hsu, 2004/03/04, ADD END */


   // mount RTF_MOUNT_CONTIGUOUS devices
   for (Dev = gFS_DeviceList; Dev->DeviceType; Dev++)
      if (((Dev->DeviceFlags & (RTF_DEVICE_REMOVABLE | RTF_DEVICE_MOUNT_CONTIGUOUS)) == RTF_DEVICE_MOUNT_CONTIGUOUS) &&
          (Dev->DevData.MountState >= Mounted))
      {
         DriveLetter = LockedScanPartitionTable(DriveLetter, Dev, RTF_PARTITION_ALL);
      }

   // reserve a drive letters for removable devices (assuming only one drive in each removable device!)
   for (Dev = gFS_DeviceList; Dev->DeviceType; Dev++)
      if ((Dev->DeviceType == FS_DEVICE_FDISK) &&
          ((Dev->DeviceFlags & (RTF_DEVICE_MOUNT_CONTIGUOUS | RTF_DEVICE_REMOVABLE)) == RTF_DEVICE_REMOVABLE))
      {
         DriveLetter = ReserveLogicalDrive(DriveLetter, Dev);
      }

   #if (defined(__NANDFDM_MULTI_INSTANCE__) && defined(__NAND_FDM_50__))
   {
      /*
       * In custom_MemoryDevice.h, customer could configure each
       * device as VISIBLE or INVISIBLE. Visible device will be un-mounted and
       * exported when USB cable is inserted.
       *
       * Here we dynamically add MT_DEVICE_NO_EXPORT flag to device which was set
       * to INVISIBLE to prevent them being un-mounted in FS_LockFAT()
       *                                                     - W09.45 Stanley Chu
       */
      RTFDeviceInfo info;

      for (Dev = gFS_DeviceList; Dev->DeviceType; Dev++)
      {
         /*
          * Only NAND flash device requires dynamic configuration now.
          * Note: Device with system drive will remain its default setting, and will be
          *       taken care specifically in FS_LockFAT(). Such device does not need
          *       dynamic configuraiton.
          */
         if (Dev->DeviceFlags & MT_DEVICE_NAND_FLASH && Dev->DeviceNumber != gFS_DeviceNumOfSYSDRV)
         {
            // query NAND FDM driver and mark (clean) MT_DEVICE_NO_EXPORT flag
            if (Dev->Driver->IOCtrl)
            {
               info.DeviceInfo.NAND.Flag = 0; // reset flag first

               Dev->Driver->IOCtrl(Dev->DriverData, FS_IOCTRL_QUERY_NAND_INFO, &info);

               if (info.DeviceInfo.NAND.Flag & MT_DEVICE_FLAG_VISIBLE)
                  Dev->DeviceFlags &= ~MT_DEVICE_NO_EXPORT;
               else // invisible
                  Dev->DeviceFlags |= MT_DEVICE_NO_EXPORT;
            }
         }
      }
   }
   #endif /* __NANDFDM_MULTI_INSTANCE__ && __NAND_FDM_50__ */
}


void RTFAPI RTFInit(void)
{
    RTFINIT_BEGIN();

    if(TLSBlockIndex == -1)
        TLSBlockIndex = RTFSYSAllocTLS();

    AllocBuffers();
#ifdef __FS_OPEN_HINT__
    MTHintAlloc();
#endif

    fs_lock_init();      // initialize FS internal locks

#if defined(__FS_XDATA_MEMORY_NOT_IN_STACK__)
    fs_mem_init();
#endif

#ifdef __FS_DEDICATED_BUFFER__
   MTBufInit((kal_uint32)gFS_DedicatedBufferPool, FS_DEDICATED_BUFFER_SIZE);
#endif

    InitDevices();
    ScanDevices();

   RTFINIT_END();
}

