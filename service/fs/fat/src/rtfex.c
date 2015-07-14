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
 *   rtfex.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file contains functions for exception handling
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
 * removed!
 * removed!
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
 *============================================================================
 ****************************************************************************/

/**************************************************************************/
/*                                                                        */
/*  File: RTFEX.C                                Copyright (c) 1998,2002  */
/*  Version: 4.0                                 On Time Informatik GmbH  */
/*                                                                        */
/*                                                                        */
/*                                      On Time        /////////////----- */
/*                                    Informatik GmbH /////////////       */
/* --------------------------------------------------/////////////        */
/*                                  Real-Time and System Software         */
/*                                                                        */
/**************************************************************************/

#include "fs_internal_def.h"
#include "rtfex.h"
#include "fs_kal.h"
#include "fs_utility.h"
#include "fs_errcode.h"
#include "rtfbuf.h"
#include "setjmp.h"
#include "fs_gprot.h"
#include "fs_internal_api.h"

#ifndef NODEBUG
   #define DEBUG
#endif

#ifdef _MSC_VER
   #define INTERN _fastcall
#elif defined __BORLANDC__
   #define INTERN __fastcall
#else
   #define INTERN
#endif

#ifdef EVALVER
#include <evalchk.h>
#else
#define RTEVALCHECK(n, m)
#endif

int _XTlsIndex = -1;  // assume this is an illegal value
#ifdef DEBUG
int _XWin32XChainTlsIndex = -1;
#endif

typedef enum { XCode,      // excuting code block
               XHandling,  // handling an exception
               XFinally    // executing finally block
             } XStatus;

//#define fs_util_trace_err_noinfo(error_code) fs_util_trace_err(NULL, error_code, rtfex_c, __LINE__, NULL)
#define fs_util_trace_err_noinfo(error_code) fs_util_trace_err_slim(error_code, rtfex_c, __LINE__)


/*
 * Locals
 */
static RTFErrorAction RTFDefaultCriticalErrorHandler(WCHAR Drive, DWORD SerialNumber, int ErrorCode);
static RTFCriticalErrorHandler CriticalError = RTFDefaultCriticalErrorHandler;

/*-----------------------------------*/
static void Init(void)
{
   RTEVALCHECK(2, 0x98731092)

   _XTlsIndex = RTFSYSAllocTLS();

   #if 0    // [slim]
/* under construction !*/
/* under construction !*/
   #endif

#ifdef DEBUG
   _XWin32XChainTlsIndex = RTFSYSAllocTLS();
   if (_XWin32XChainTlsIndex == -1)
      fs_err_internal_fatal(FS_ERR_TLS_01, NULL);
#endif
}

/*-----------------------------------*/
_XData *  XAPI _XHandler(void)
{
   if (_XTlsIndex == -1)
      Init();
   return RTFSYSGetTLS(_XTlsIndex);
}

/*-----------------------------------*/
void XAPI _XReExecute(void)
{
   _XData * XD = RTFSYSGetTLS(_XTlsIndex);

#ifdef DEBUG
   if (XD == NULL)
      fs_err_internal_fatal(FS_ERR_EXCEPTION_05, NULL);
#endif

   XD->XValue = XNOEX;
   XD->State = XCode;
   XD->IsHandled = 1;
   XRESTORECONTEXT(&XD->Context, XCODE);
}

/*-----------------------------------*/
void XAPI _XInitBlock(_XData * XD)
{
   if (_XTlsIndex == -1)
      Init();
   XD->Next = RTFSYSGetTLS(_XTlsIndex);
#ifdef DEBUG
/*
      if (XD->Next == NULL)
         RTFSYSSetTLS(_XWin32XChainTlsIndex, rtfGetFS(0));
      else
         if (rtfGetFS(0) != RTFSYSGetTLS(_XWin32XChainTlsIndex))
            RTFSYSErrorExit("Win32 exception handler frame below RTF exception frame", 1);
*/
#endif
   RTFSYSSetTLS(_XTlsIndex, XD);
   XD->XValue = XNOEX;
   XD->State = XCode;
   XD->IsHandled = 1;
}

/*-----------------------------------*/
void  XAPI _XHandled(_XData * XD)
{
#ifdef DEBUG
   switch (XD->State)
   {
      case XHandling:
         break;
      case XCode:
      case XFinally:
         fs_err_internal_fatal(FS_ERR_EXCEPTION_06, NULL);
      default:
         fs_err_internal_fatal(FS_ERR_EXCEPTION_07, NULL);
   }
#endif
   XD->XValue = XNOEX;
   XD->State = XCode;
   XD->IsHandled = 1;
}

#if defined(__FS_XDATA_MEMORY_NOT_IN_STACK__)

/*-----------------------------------*/
void XAPI _XRaiseException(int XValue)
{
   _XData * XD;

   if (_XTlsIndex == -1)
      Init();

#ifdef DEBUG
   if (XValue >= 0)
      fs_err_internal_fatal(FS_ERR_EXCEPTION_01, NULL);
#endif

   XD = RTFSYSGetTLS(_XTlsIndex);

   while (XD != NULL)
   {
#ifdef DEBUG
      //if (rtfGetFS(0) != RTFSYSGetTLS(_XWin32XChainTlsIndex))
         //RTFSYSErrorExit("Win32 exception handler frame below RTF exception frame", 1);
#endif
      XD->IsHandled = 0;

      switch (XD->State)
      {
         case XCode:       //  execute the handler
            XD->XValue = XValue;
            XD->State = XHandling;
            XRESTORECONTEXT(&XD->Context, XValue);
         case XHandling:   // next up must handle it, do finally first
            XD->XValue = XValue;
            XD->State = XFinally;
            XRESTORECONTEXT(&XD->Context, XFINALLY);
         case XFinally:  // raise within finally; propagate
#ifdef DEBUG
            fs_err_internal_fatal(FS_ERR_EXCEPTION_02, NULL);
#endif
            RTFSYSSetTLS(_XTlsIndex, XD = XD->Next);

            fs_mem_free(FS_MEM_TYPE_XDATA, XD, sizeof(_XData));

            break;
#ifdef DEBUG
         default:
            fs_err_internal_fatal(FS_ERR_EXCEPTION_03, NULL);
#endif
      }
   }
   fs_err_internal_fatal(FS_ERR_EXCEPTION_04, NULL);
}


/*-----------------------------------*/
XAction XAPI _XCloseBlock(_XData * XD)
{
   int xvalue;
   int xhandled;

#ifdef DEBUG
   if (RTFSYSGetTLS(_XTlsIndex) != XD)
      fs_err_internal_fatal(FS_ERR_EXCEPTION_08, NULL);
#endif

   switch (XD->State)
   {
      case XHandling:   // exception is now handled
      case XCode:       // no exception
         XD->State = XFinally;
         XRESTORECONTEXT(&XD->Context, XFINALLY);
      case XFinally:  // we are done
         RTFSYSSetTLS(_XTlsIndex, XD->Next);

         xvalue = XD->XValue;
         xhandled = XD->IsHandled;

         fs_mem_free(FS_MEM_TYPE_XDATA, XD, sizeof(_XData));

         if (xhandled)
            return XBreak;  // continue after XTRY block
         else
            _XRaiseException(xvalue); // propagate
         break;
#ifdef DEBUG
      default:
         fs_err_internal_fatal(FS_ERR_EXCEPTION_09, NULL);
#endif
   }
   return XBreak;   // never get here
}

/*------------------------------------*/
XAction XAPI _XCloseBlockCanReturn(_XData * XD)
{
   int xvalue;
   int xhandled;
   _XData * next;

#ifdef DEBUG
   if (RTFSYSGetTLS(_XTlsIndex) != XD)
      fs_err_internal_fatal(FS_ERR_EXCEPTION_10, NULL);
#endif

   switch (XD->State)
   {
      case XHandling:   // exception is now handled
      case XCode:       // no exception
         XD->State = XFinally;
         XRESTORECONTEXT(&XD->Context, XFINALLY);
      case XFinally:    // we are done
         RTFSYSSetTLS(_XTlsIndex, XD->Next);

         xvalue = XD->XValue;
         xhandled = XD->IsHandled;
         next = XD->Next;

         fs_mem_free(FS_MEM_TYPE_XDATA, XD, sizeof(_XData));

         if (xhandled)
            return XBreak;   // continue after XTRY block
         else
            if (next != NULL)
               _XRaiseException(xvalue); // propagate
            else
               return XReturn;  // return to return
         break;
#ifdef DEBUG
      default:
         fs_err_internal_fatal(FS_ERR_EXCEPTION_11, NULL);
#endif
   }
   return XBreak;   // never get here
}

/*-----------------------------------*/
XAction XAPI _XCloseBlockNoPropagate(_XData * XD)
{
   int xhandled;

#ifdef DEBUG
   if (RTFSYSGetTLS(_XTlsIndex) != XD)
      fs_err_internal_fatal(FS_ERR_EXCEPTION_12, NULL);
#endif

   switch (XD->State)
   {
      case XHandling:   // exception is now handled
      case XCode:       // no exception
         XD->State = XFinally;
         XRESTORECONTEXT(&XD->Context, XFINALLY);
      case XFinally:    // we are done
         RTFSYSSetTLS(_XTlsIndex, XD->Next);

         xhandled = XD->IsHandled;

         fs_mem_free(FS_MEM_TYPE_XDATA, XD, sizeof(_XData));

         return (xhandled) ? XBreak : XReturn;
#ifdef DEBUG
      default:
         fs_err_internal_fatal(FS_ERR_EXCEPTION_13, NULL);
#endif
   }
   return XBreak;   // never get here
}


#else   // !__FS_XDATA_MEMORY_NOT_IN_STACK__

/*-----------------------------------*/
void XAPI _XRaiseException(int XValue)
{
   _XData * XD;

   if (_XTlsIndex == -1)
      Init();

#ifdef DEBUG
   if (XValue >= 0)
      fs_err_internal_fatal(FS_ERR_EXCEPTION_01, NULL);
#endif

   XD = RTFSYSGetTLS(_XTlsIndex);

   while (XD != NULL)
   {
#ifdef DEBUG
      //if (rtfGetFS(0) != RTFSYSGetTLS(_XWin32XChainTlsIndex))
         //RTFSYSErrorExit("Win32 exception handler frame below RTF exception frame", 1);
#endif
      XD->IsHandled = 0;

      switch (XD->State)
      {
         case XCode:       //  execute the handler
            XD->XValue = XValue;
            XD->State = XHandling;
            XRESTORECONTEXT(&XD->Context, XValue);
         case XHandling:   // next up must handle it, do finally first
            XD->XValue = XValue;
            XD->State = XFinally;
            XRESTORECONTEXT(&XD->Context, XFINALLY);
         case XFinally:  // raise within finally; propagate
#ifdef DEBUG
            fs_err_internal_fatal(FS_ERR_EXCEPTION_02, NULL);
#endif
            RTFSYSSetTLS(_XTlsIndex, XD = XD->Next);
            break;
#ifdef DEBUG
         default:
            fs_err_internal_fatal(FS_ERR_EXCEPTION_03, NULL);
#endif
      }
   }
   fs_err_internal_fatal(FS_ERR_EXCEPTION_04, NULL);
}


/*-----------------------------------*/
XAction XAPI _XCloseBlock(_XData * XD)
{
#ifdef DEBUG
   if (RTFSYSGetTLS(_XTlsIndex) != XD)
      fs_err_internal_fatal(FS_ERR_EXCEPTION_08, NULL);
#endif

   switch (XD->State)
   {
      case XHandling:   // exception is now handled
      case XCode:       // no exception
         XD->State = XFinally;
         XRESTORECONTEXT(&XD->Context, XFINALLY);
      case XFinally:  // we are done
         RTFSYSSetTLS(_XTlsIndex, XD->Next);
         if (XD->IsHandled)
            return XBreak;  // continue after XTRY block
         else
            _XRaiseException(XD->XValue); // propagate
         break;
#ifdef DEBUG
      default:
         fs_err_internal_fatal(FS_ERR_EXCEPTION_09, NULL);
#endif
   }
   return XBreak;   // never get here
}

/*------------------------------------*/
XAction XAPI _XCloseBlockCanReturn(_XData * XD)
{
#ifdef DEBUG
   if (RTFSYSGetTLS(_XTlsIndex) != XD)
      fs_err_internal_fatal(FS_ERR_EXCEPTION_10, NULL);
#endif

   switch (XD->State)
   {
      case XHandling:   // exception is now handled
      case XCode:       // no exception
         XD->State = XFinally;
         XRESTORECONTEXT(&XD->Context, XFINALLY);
      case XFinally:    // we are done
         RTFSYSSetTLS(_XTlsIndex, XD->Next);
         if (XD->IsHandled)
            return XBreak;   // continue after XTRY block
         else
            if (XD->Next != NULL)
               _XRaiseException(XD->XValue); // propagate
            else
               return XReturn;  // return to return
         break;
#ifdef DEBUG
      default:
         fs_err_internal_fatal(FS_ERR_EXCEPTION_11, NULL);
#endif
   }
   return XBreak;   // never get here
}

/*-----------------------------------*/
XAction XAPI _XCloseBlockNoPropagate(_XData * XD)
{
#ifdef DEBUG
   if (RTFSYSGetTLS(_XTlsIndex) != XD)
      fs_err_internal_fatal(FS_ERR_EXCEPTION_12, NULL);
#endif

   switch (XD->State)
   {
      case XHandling:   // exception is now handled
      case XCode:       // no exception
         XD->State = XFinally;
         XRESTORECONTEXT(&XD->Context, XFINALLY);
      case XFinally:    // we are done
         RTFSYSSetTLS(_XTlsIndex, XD->Next);
         return (XD->IsHandled) ? XBreak : XReturn;
#ifdef DEBUG
      default:
         fs_err_internal_fatal(FS_ERR_EXCEPTION_13, NULL);
#endif
   }
   return XBreak;   // never get here
}

#endif  // __FS_XDATA_MEMORY_NOT_IN_STACK__

#ifndef __FS_CARD_DOWNLOAD__

static int INTERN MediaChanged(RTFDevice * Dev)
{
   int volatile Result;
   RTFSYSFreeMutex(RTFLock);

   XTRY
      case XCODE:
         CheckMedia(Dev);
         if (Dev->DevData.MountState < Initialized)
            Result = RTF_DRIVE_NOT_READY;
         else
            Result = Dev->Driver->MediaChanged(Dev->DriverData);
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
static int INTERN CheckSerialNumber(RTFDrive * Drive, int ErrorCode)
// must not raise any exceptions
{
   RTFBootRecord * BR;
   int volatile Result;

   // lock file system as we now need a buffer
   RTFSYSLockMutex(RTFLock, RTF_INFINITE);
   XTRY
      case XCODE:
         // clear any media changed errors
         MediaChanged(Drive->Dev);

         // if the current temp buffer is the boot sector, then we can't do our thing
         if (Drive->Dev->DevData.B &&
             (Drive->Dev->DevData.B->Sector == Drive->FirstSector))
         {
            fs_util_trace_err_noinfo(ErrorCode);

            XRAISE(ErrorCode);
         }

         BR = GetBuffer(Drive->Dev, Drive->FirstSector, NO_LOAD | ALT_BUFFER); // not! filled
         rtf_core_read_sectors(Drive->Dev, (void*)BR, Drive->FirstSector, 1, NO_CRITICAL);
#if defined(__NOT_SUPPORT_FAT32__)
         if (BR->BP.E._16.BPB.SerialNumber != Drive->SerialNumber)
#else
         if (((Drive->FATType == RTFAT32) ? BR->BP.E._32.BPB.SerialNumber : BR->BP.E._16.BPB.SerialNumber) != Drive->SerialNumber)
#endif /* __NOT_SUPPORT_FAT32__ */
            Result = RTF_WRONG_MEDIA;
         else
            Result = RTF_NO_ERROR;
         break;
      default:
         Result = XVALUE;
         XHANDLED;
         break;
      case XFINALLY:
         // manually discard the buffer
         if (Drive->Dev->DevData.AltBuffer)
         {
            DiscardOtherBuffer(Drive->Dev->DevData.AltBuffer);
            Drive->Dev->DevData.AltBuffer = NULL;
         }
         RTFSYSFreeMutex(RTFLock);
         break;
   XENDX
   return Result;
}

#endif /* __FS_CARD_DOWNLOAD__ */


/*-----------------------------------*/

void MTErrHdlr_RemovableDeviceRWError(RTFDevice *Dev)
{
#ifndef __FS_CARD_DOWNLOAD__
   int      i;
   RTFile   *f;

   if (HasFileSystem == Dev->DevData.MountState)
   {
      for (i = 0, f = gFS_Data.FileTable; i < FS_MAX_FILES; i++, f++)
      {
         if (f->Dev == Dev)
         {
            f->Valid = MT_ENUM_FH_MEDIACHANGED;
         }
      }

      UnmountDevice(Dev, 0); // unmount device to discard all buffers of this device but NOT clean file table

      /*
       * Set Dev as Initialized for FS_TestMSDC() because FS_TestMSDC() will see Device
       * mount status to judge if memory card is existed before.
       *
       * Note. If user tries to access this device again before removing device, device mount status
       *       will be kept as Initialized in LocateDrive()=>MountLogicalDrive(). That means, this device
       *       will not be re-mounted again until it is re-plugged-in.
       */
      Dev->DevData.MountState = Initialized;
   }
#endif /* __FS_CARD_DOWNLOAD__ */
}

RTFErrorAction HandleCriticalError(RTFDevice * Dev, int ErrorCode)
// device is locked, but RTFiles is not locked when called
{
#ifndef __FS_CARD_DOWNLOAD__
   #define LostMedia(Code) ((Code == RTF_MEDIA_CHANGED) || (Code == RTF_WRONG_MEDIA) || (Code == RTF_DRIVE_NOT_FOUND) || (Code == RTF_DRIVE_NOT_READY))
   RTFDrive * Drive = (Dev->DevData.FirstDrive && (Dev->DevData.FirstDrive->MountState >= HasFileSystem)) ? Dev->DevData.FirstDrive : NULL;

   if(Dev->DevData.Reserved & FS_DEVICE_ENTER_CRITICAL_ERROR)
   {
       // Critical error happened in critical error handler.
       if (LostMedia(ErrorCode))
           Dev->DevData.ErrorCondition = ErrorCode;
       Dev->DevData.Reserved &= ~FS_DEVICE_ENTER_CRITICAL_ERROR;
       return RTFFail;
   }
   else
   {
        Dev->DevData.Reserved |= FS_DEVICE_ENTER_CRITICAL_ERROR;
   }

   if (LostMedia(ErrorCode) && Drive)
   {
      ErrorCode = CheckSerialNumber(Drive, ErrorCode);
      if (ErrorCode == RTF_NO_ERROR)
      {
         Dev->DevData.Reserved &= ~FS_DEVICE_ENTER_CRITICAL_ERROR;
         return RTFRetry;
      }
   }

   while (1)
   {
      /* now CriticalError() always returns RTFFail */
      RTFErrorAction Result = CriticalError(Drive ? (MT_BASE_DRIVE_LETTER + (Drive - gFS_Data.DriveTable)) : Dev->DevData.FriendlyName[5], Drive ? Drive->SerialNumber : 0, ErrorCode);

      switch (Result)
      {
         case RTFFail:
            if (LostMedia(ErrorCode))
            {
               Dev->DevData.ErrorCondition = ErrorCode; // this will unmount the device and discard all buffers
            }

            Dev->DevData.Reserved &= ~FS_DEVICE_ENTER_CRITICAL_ERROR;

            return RTFFail;

         #if !defined(__FS_SLIM_CRITICAL_ERROR_HDR__)  // [slim]: RTFRetry will not happen currently!
         case RTFRetry:
            if (LostMedia(ErrorCode) && Drive)
            {
               ErrorCode = CheckSerialNumber(Drive, ErrorCode);
               if (ErrorCode == RTF_NO_ERROR)
               {
                  Dev->DevData.Reserved &= ~FS_DEVICE_ENTER_CRITICAL_ERROR;
                  return RTFRetry;
               }
               else
                  break; // keep on looping
            }
            else
            {
               Dev->DevData.Reserved &= ~FS_DEVICE_ENTER_CRITICAL_ERROR;
               return RTFRetry;
            }
         #endif // !__FS_SLIM_CRITICAL_ERROR_HDR__

         default:
            // fs_err_internal_fatal(FS_ERR_EXCEPTION_14, NULL); // [slim]
            return RTFFail;
      }
   }
#else
    return RTFFail;
#endif /* __FS_CARD_DOWNLOAD__ */
}

/*-----------------------------------*/
static RTFErrorAction RTFDefaultCriticalErrorHandler(WCHAR Drive, DWORD SerialNumber, int ErrorCode)
{
   return RTFFail;
}

