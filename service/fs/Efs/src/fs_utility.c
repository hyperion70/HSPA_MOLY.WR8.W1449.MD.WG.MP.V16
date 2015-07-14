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
 * Filename:
 * ---------
 *   fs_utility.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is the source file of File System utility
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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

#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "fs_internal_def.h"
#include "fs_gprot.h"
#include "fs_iprot.h"
#include "rtfiles.h"
#include "fs_kal.h"
#include "fs_utility.h"
#include "fs_internal_api.h"
#include "kal_trace.h"
#include "fs_trc.h"
#include "stdio.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "dcl.h"            // for WDT, KBD and PWM
//#include "Conversions.h"	// for UCS2_TO_WCHAR
#include "SST_sla.h"        // for SWLA hooker

/*-------------------------------------
 * Macros
 *-------------------------------------*/

// Assert
#define fs_assert_local(expr) fs_assert(expr, fs_utility_c)
#define fs_ext_assert_local(expr, e1, e2, e3) fs_ext_assert(expr, fs_utility_c, e1, e2, e3)

/*-------------------------------------
 * Function Declarations
 *-------------------------------------*/
extern kal_uint32   INT_GetCurrentTime(void);
extern kal_bool     INT_QueryExceptionStatus(void);

void fs_util_trace_get_task_name(kal_taskid taskid, char *dest, kal_uint32 length);

/*-------------------------------------
 * Global Variables
 *-------------------------------------*/
#ifdef __FS_TRACE_SUPPORT__
   char                 _gfs_trace_str_buf[MAX_TRACE_STR_LEN];
#endif

fs_util_ucs_to_wchar_func _gfs_util_ucs_to_wchar_func = NULL;

fs_util_get_default_encoding_length_func _gfs_util_get_default_encoding_length_func = NULL;


/*-------------------------------------
 * Local Variables
 *-------------------------------------*/
static const char ShortNameChars[] = " $%'-_@~`!(){}^#&0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

/*-------------------------------------
 * Function Bodies
 *-------------------------------------*/
#ifndef __FS_CARD_DOWNLOAD__
kal_bool fs_util_kbd_is_key_pressed(kal_uint8 key)
{
    HKBD_CTRL_KEY_STA_T keysta;
    DCL_HANDLE          handle;

    keysta.key = key;

    handle = DclHKBD_Open(DCL_KBD, 0);

    DclHKBD_Control(handle, HKBD_CMD_GET_KEY_STATUS, (DCL_CTRL_DATA_T*)&keysta);

    DclHKBD_Close(handle);

    return (kal_bool)keysta.sta;
}

void fs_util_pwm_poweron()
{
    DCL_HANDLE handle;

    handle = DclPW_Open(DCL_PW, FLAGS_NONE);

    DclPW_Control(handle, PW_CMD_POWERON, NULL);

    DclPW_Close(handle);
}

void fs_util_wdt_restart()
{
    DCL_HANDLE dcl_wdt_handle;

    dcl_wdt_handle = DclWDT_Open(DCL_WDT,0);

    DclWDT_Control(dcl_wdt_handle, WDT_CMD_RESTART, 0);

    DclWDT_Close(dcl_wdt_handle);
}
#endif /* !__FS_CARD_DOWNLOAD__ */

/*----------------------------------*/
int fs_util_is_power_two(unsigned int i)
{
   if (i == 0)
      return 0; // it's a power of two, put we need > 0
   while (i != 0)
   {
      if ((i & 1) && (i != 1))
         return 0;
      i >>= 1;
   }
   return 1;
}

/*-----------------------------------*/
void fs_util_char_to_hex(char * Name, DWORD TimeStamp)
// write 8 hex digits, no zero termination
{
   UINT i;
   char HexDigits[] = "0123456789ABCDEF";

   for (i=0; i<8; i++)
   {
      Name[7-i] = HexDigits[TimeStamp & 0xF];
      TimeStamp >>= 4;
   }
}

/*-----------------------------------*/
int fs_util_validate_sfn_char(char c)
// ".", "\\", and ":" is invalid
{
   if ( strchr(ShortNameChars, c) )
      return 1;
   else
      return 0;
}

/*-----------------------------------*/
int fs_util_validate_lfn_char(WCHAR c)
// "\\" and ":" is invalid
{
   char invalidLongNameChars[] = {0x22, 0x2A, 0x2F, 0x3A, 0x3C, 0x3E, 0x3F, 0x5C, 0x7C, 0}; // total 9 chars

   if (c < 0x80)
   {
      /*
       * Totally 32 + 9 = 41 chars are invalid.
       *
       * Valid ASCII chars for SFN           : 79 chars " $%'-_@~`!(){}^#&0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
       * Additional valid ASCII chars for LFN: 7 chars  ".+,;=[]"       - W10.20 / Stanley
       */
      if ((c < 0x20) || strchr(invalidLongNameChars, (char)c))
         return 0;
   }

   return 1;
}


/*-----------------------------------*/
/* COMPare Unicode and Ascii STRING */
int fs_util_comp_uni_ascii(const char * FileName, const char* str, int len)
{
   int i;

   for (i=0; i<len; i++)
   {
      if (!compASCII(FileName, i, str[i]))
         return 0;
   }
   return 1;
}
/* Generate friendly ASCII characters only */
char fs_util_gen_friendly_char(char c)
{
   c = fs_util_toupper(c);

   if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z'))
      return c;
   else
      return '_';
}

/*-----------------------------------*/
char fs_util_get_short_char(char c)
{
   c = fs_util_toupper(c);
   return fs_util_validate_sfn_char(c) ? c : '_';
}

#if defined(__FS_NATIVE_ENCODING_TRANSPARENT__) || defined(__FS_CARD_DOWNLOAD__) || !defined(__MMI_FMI__)
static char fs_util_gen_ascii_char(WCHAR wc)
{
   int num;

   num = wc & 0x3F;

   if (num >= 36)
      num -= 36;

   if (num >= 0 && num <= 9)
      return ('0' + num);
   else
      return ('A' + num - 10);
}
#endif

kal_uint32 fs_util_get_default_encoding_length(void)
{
    if (_gfs_util_get_default_encoding_length_func)
    {
        return (_gfs_util_get_default_encoding_length_func)();
    }
    else
    {
        return 1;
    }
}

kal_uint16 fs_util_ucs_to_wchar(kal_uint16 ucs2)
{
    if (_gfs_util_ucs_to_wchar_func)
    {
        return (_gfs_util_ucs_to_wchar_func)(ucs2);
    }
    else
    {
        return 0xFFFF;
    }
}

/*-----------------------------------*/
WCHAR fs_util_uni_to_native(WCHAR unicode)
{
   WCHAR encode;

   if ( unicode < 0x80 )
      return unicode;
   else
   {
  #if defined(__FS_NATIVE_ENCODING_TRANSPARENT__) || defined(__FS_CARD_DOWNLOAD__) || !defined(__MMI_FMI__)
      // The #if statement should sync to fs_util_gen_ascii_char()
      encode = (WCHAR)fs_util_gen_ascii_char(unicode);

  #else /* !__FS_NATIVE_ENCODING_TRANSPARENT__ */

      encode = fs_util_ucs_to_wchar(unicode);
      fs_assert_local(encode != 0x0000);

  #endif /* __FS_NATIVE_ENCODING_TRANSPARENT__ */

      return encode;
   }
}

/*-----------------------------------*/
WCHAR fs_util_native_to_uni(WCHAR native)
{
   return native;
}

/*-----------------------------------*/
char fs_util_toupper(signed char c)
{
   if ( (c >= 'a') && (c <= 'z') )
      return c - ('a' - 'A');
   return c;
}

/*-----------------------------------*/
WCHAR fs_util_wchar_toupper(WCHAR c)
{
   // check if ascii code
   if ((c >= 0x61) && (c <= 0x7a))
      return c - (0x61 - 0x41);

   return c;
}

/*******************************************************************//**
 * Transform wide file name string to byte file name string for TRACE purpose
 *
 * @par Category:
 * File System
 *
 * @par Change Log:
 * W09.09: Add this function to improve FS trace readability
 *
 * @param[in]  WN        Wide file name string (WCHAR*)
 * @param[out] BN        Byte file name string (CHAR*)
 * @param[in]  BNLength  Maximum length of byte file name string
 *
 * @note
 * Boundary cases (e.g., BFLength = 0 or 1) are not checked! Please use this function carefully.
 **********************************************************************/
int fs_util_wstr_to_bstr(const WCHAR *WN, char *BN, kal_uint32 BNLength)
{
   char           w[2];
   kal_uint32     bLen = 0;
   kal_int32      lossflag = 0;

   /* preserve a byte for tail */
   BNLength--;

   while (*WN && bLen < BNLength)
   {
      /* get a wide char */
      *(WCHAR*)w = *WN;

      /* if this is an ASCII char, append it to byte string, else print the encoding */
      if (w[0] < 0x80 && w[1] == 0x00)
      {
         BN[bLen] = w[0];
         bLen++;
      }
      else
      {
         if (bLen + 6 < BNLength)
         {
            kal_sprintf(BN + bLen, "(%04X)", *(WCHAR*)w);
            bLen += 6;
            lossflag = 1;
         }
         else
            break;
      }

      /* go to next wide char */
      WN++;
   }

   /* append a tail to byte string */
   BN[bLen] = 0;

   return lossflag;
}

/**
 * @brief this function gets RTC time clock and system tick
 *
 * @param[in,out] Time
 *    FS_TRACE_TIME structure
 */
#ifndef __FS_CARD_DOWNLOAD__
void fs_util_get_time(kal_uint32 *time)
{
   *time = INT_GetCurrentTime();
}

void fs_util_get_time_aux(FS_TRACE_TIME *Time)
{
   Time->RTCTime = INT_GetCurrentTime();
   Time->SYSTime = kal_get_systicks();
}

/**
 * @brief this function gets the duration from 2 FS_TRACE_TIME structures
 *
 * @param[in] StartTime Start time
 * @param[in] EndTime   End time
 *
 * @Returns Duration (unit: us)
 */
kal_uint32 fs_util_get_duration(kal_uint32 start_time, kal_uint32 end_time)
{
   start_time = (start_time > end_time) ? (end_time + 0x01000000 - start_time) : (end_time - start_time);

   return (kal_uint32)(start_time * 31.25);  // convert to us
}

kal_uint32 fs_util_get_duration_aux(FS_TRACE_TIME *StartTime, FS_TRACE_TIME *EndTime)
{
   kal_uint32 rtc_clk_cnt;
   kal_uint32 sys_tick_cnt;
   kal_uint32 tmp;

   sys_tick_cnt = EndTime->SYSTime - StartTime->SYSTime;
   rtc_clk_cnt = (StartTime->RTCTime > EndTime->RTCTime) ? (EndTime->RTCTime + 0x01000000 - StartTime->RTCTime) : (EndTime->RTCTime - StartTime->RTCTime);

   if(rtc_clk_cnt != 0 || sys_tick_cnt > 216)
   {
      if(sys_tick_cnt > 216)
      {
         sys_tick_cnt = sys_tick_cnt * 4615;       // convert to us

         // how many RTC clocks are there in sys_tick_cnt?
         tmp = sys_tick_cnt / 31.25;

         // Is there any extra RTC clocks?
         if (rtc_clk_cnt > tmp)
            rtc_clk_cnt -= tmp;
         else
            rtc_clk_cnt = 0;

         // If yes, add them to the result
         return sys_tick_cnt + (kal_uint32)(rtc_clk_cnt * 31.25);
      }
      else
      {
         return (kal_uint32)(rtc_clk_cnt * 31.25);  // convert to us
      }
   }
   else  // rtc_clk_cnt == 0 && sys_tick_cnt <= 216
      return 0;
}

#ifdef __FS_TRACE_SUPPORT__
void fs_util_trace_print_file_table(fs_trace_func trace_func, trace_class_enum trace_class)
{
    int        i;
    RTFile    *f;
    RTFHANDLE  fh;
    char       taskname[FS_TRACE_MAX_TASKNAME_LEN];
    char      *p_filename;

    if (trace_func==NULL) return;

    trace_func(trace_class, FS_INFO_FT_TITLE);

    for (i = 0, f = gFS_Data.FileTable; i < FS_MAX_FILES; i++, f++)
    {
        // get task name
        fs_util_trace_get_task_name((kal_taskid)(f->Task), taskname, FS_TRACE_MAX_TASKNAME_LEN);

        // get file name
        p_filename = f->DirEntry.Dir.FileName;

        // get file handle
        if (f->Valid)
            fh = GetFileHandle(f);
        else
            fh = 0;

        // print this file slot
        trace_func(trace_class, FS_INFO_FT_SLOT, i, fh, taskname[0], taskname[1], taskname[2], f->OwnerLR, f->Lock, f->Valid,
                   p_filename[0], p_filename[1], p_filename[2], p_filename[3], p_filename[4], p_filename[5], p_filename[6], p_filename[7],
                   p_filename[8], p_filename[9], p_filename[10]);

        if (f->Valid)   {
            kal_buffer_trace(trace_class, FS_INFO_FT_LFN, kal_wstrlen((WCHAR *)(f->FullName))*2+2, (kal_uint8*)(f->FullName));
        }
    }

    trace_func(trace_class, FS_INFO_FT_TAIL);
}

void fs_util_trace_wstr_int(const WCHAR *wstr, trace_class_enum trace_class)
{
    if (fs_util_wstr_to_bstr(wstr, _gfs_trace_str_buf, MAX_TRACE_STR_LEN))  {
        if (trace_class == TRACE_ERROR) {
            kal_buffer_trace(trace_class, FS_INFO_LFN_ERR, kal_wstrlen(wstr)*2+2, (kal_uint8*)wstr);
        }
        else {
            kal_buffer_trace(trace_class, FS_INFO_LFN, kal_wstrlen(wstr)*2+2, (kal_uint8*)wstr);
        }
    }
    else {
        if (trace_class == TRACE_ERROR) {
            kal_print_string_trace(MOD_FS, TRACE_ERROR, "[FS ERR] %s\n", _gfs_trace_str_buf);
        }
        else    {
            kal_print_string_trace(MOD_FS, TRACE_FUNC, "[FS] %s\n", _gfs_trace_str_buf);
        }
    }
}

void fs_util_trace_str(kal_uint32 flag, void *str)
{
       if (flag & MT_TRACE_INFO_WSTR)
       {
          fs_util_wstr_to_bstr((const WCHAR*)str, _gfs_trace_str_buf, MAX_TRACE_STR_LEN);
          str = (void*)_gfs_trace_str_buf;
       }
}

#include <stdarg.h>

void fs_util_trace_info(kal_uint32 flag, void *extra_info, kal_uint32 msg_index, const char *arg_type, ...)
{
   #define MAX_ARG 5
   char         *fn;
   kal_uint32    dev_type;
   RTFile       *f;
   kal_uint8     extra_info_wstr = 0;
   kal_uint32    data[MAX_ARG];
   kal_int32     i;
   kal_int32     arg_count;
   char          taskname[FS_TRACE_MAX_TASKNAME_LEN];
   va_list       args;

   arg_count = (flag & MT_TRACE_ARG_COUNT_MASK) >> MT_TRACE_ARG_COUNT_SHIFT;

   va_start(args, arg_type);

   for (i=0;i<arg_count;i++)   {
       data[i]=va_arg(args, kal_uint32);
   }
   va_end(args);

   if (kal_if_hisr() || kal_if_lisr())
      return;

   if (kal_trace_check_filter_on((trace_class_enum)(flag & MT_TRACE_CLASS_MASK), msg_index))   {
       if (extra_info)
       {
          if (flag & MT_TRACE_INFO_FILE)
          {
             f = (RTFile *)extra_info;
             fn = f->DirEntry.Dir.FileName;
             dev_type=fs_conf_get_devtype_by_devflag(f->Dev->DeviceFlags);

             kal_trace((trace_class_enum)(flag & MT_TRACE_CLASS_MASK), msg_index, arg_type, kal_get_active_module_id(),
                fn[0], fn[1], fn[2], fn[3], fn[4], fn[5], fn[6], fn[7], fn[8], fn[9], fn[10], dev_type,
                data[0], data[1], data[2], data[3], data[4]);

             return;
          }
          else if (flag & MT_TRACE_INFO_TASK)  {
              f = (RTFile *)extra_info;
              // get task name
              fs_util_trace_get_task_name((kal_taskid)(f->Task), taskname, FS_TRACE_MAX_TASKNAME_LEN);
              kal_trace((trace_class_enum)(flag & MT_TRACE_CLASS_MASK), msg_index, arg_type, kal_get_active_module_id(),
                 taskname[0], taskname[1], taskname[2],
                 data[0], data[1], data[2], data[3], data[4]);
              return;
          }
          else {  // must be MT_TRACE_INFO_WSTR
              extra_info_wstr = 1;
          }
       }
       else // without extra infomation
       {
            // go through to print logs
       }

       kal_trace((trace_class_enum)(flag & MT_TRACE_CLASS_MASK), msg_index, arg_type, kal_get_active_module_id(), data[0], data[1], data[2], data[3], data[4]);

       if (extra_info_wstr)
          fs_util_trace_wstr_int((const WCHAR*)extra_info, (trace_class_enum)(flag & MT_TRACE_CLASS_MASK));
   }
}

void fs_util_trace_err_slim(kal_int32 errcode, fs_src_file_enum filecode, kal_uint32 line)
{
    if (kal_if_hisr() || kal_if_lisr())
    {
        return;
    }

    if (kal_trace_check_filter_on(TRACE_ERROR, FS_API_FS_ERR__enum))
    {
        kal_trace(TRACE_ERROR, FS_API_FS_ERR, kal_get_active_module_id(), errcode, filecode, line);

        #if defined(__TST_TRACE_ENABLED__)
        switch (errcode)
        {
            case FS_TOO_MANY_FILES:  // for fatal error 0xA01
                fs_util_trace_print_file_hanlde_consumer(kal_trace, TRACE_ERROR);
            case FS_ACCESS_DENIED:
            case FS_ERROR_RESERVED:
                fs_util_trace_print_file_table(kal_trace, TRACE_ERROR);
                break;

            default:
                break;
        }
        #endif
    }
}

void fs_util_trace_err(kal_uint32 flag, kal_int32 errcode, fs_src_file_enum filecode, kal_uint32 line, void *extra_info)
{
   RTFile      *f;
   kal_uint32  dev_type;
   char        *sfn;

   if (kal_if_hisr() || kal_if_lisr())
      return;

   if (kal_trace_check_filter_on(TRACE_ERROR, FS_API_FS_ERR__enum))
   {
       if (extra_info)
       {
          if (flag & MT_TRACE_INFO_FILE)
          {
             f = (RTFile *)extra_info;

             dev_type = fs_conf_get_devtype_by_devflag(f->Dev->DeviceFlags);

             sfn = f->DirEntry.Dir.FileName;

             kal_trace(TRACE_ERROR, FS_API_FS_ERR_FILE, kal_get_active_module_id(), errcode, filecode, line, sfn[0], sfn[1], sfn[2], sfn[3], sfn[4], sfn[5], sfn[6], sfn[7], sfn[8], sfn[9], sfn[10], dev_type);
          }
          else // MT_TRACE_INFO_WSTR
          {
             kal_trace(TRACE_ERROR, FS_API_FS_ERR, kal_get_active_module_id(), errcode, filecode, line);

             fs_util_trace_wstr_int((const WCHAR*)extra_info, TRACE_ERROR);
          }
       }
       else
       {
          kal_trace(TRACE_ERROR, FS_API_FS_ERR, kal_get_active_module_id(), errcode, filecode, line);
       }

       #if defined(__TST_TRACE_ENABLED__)
       switch (errcode)
       {
          case FS_TOO_MANY_FILES:
             fs_util_trace_print_file_hanlde_consumer(kal_trace, TRACE_ERROR);
          case FS_ACCESS_DENIED:
          case FS_ERROR_RESERVED:
             fs_util_trace_print_file_table(kal_trace, TRACE_ERROR);
             break;

          default:
             break;
       }
       #endif
  }
}

void fs_util_trace_device_io(kal_int32 flag, kal_uint32 address, kal_uint32 length, kal_uint32 duration)
{
    kal_uint32 devflag;
    kal_uint32 speed;

    devflag=fs_conf_get_devtype_by_devflag(flag & 0xFFFF);
    speed=(kal_uint32)((length * 512 * 976.5) / duration);

    if (flag>>16)    {
        fs_util_trace_info5(TRACE_GROUP_1, FS_INFO_GR1_WRITESECTORS, devflag, (length * 512), duration, speed, address);
        fs_util_trace_info4(TRACE_GROUP_2, FS_INFO_GR2_WRITESECTORS, devflag, address, length, duration, NULL);
    }
    else {
        fs_util_trace_info5(TRACE_GROUP_1, FS_INFO_GR1_READSECTORS, devflag, (length * 512), duration, speed, address);
        fs_util_trace_info4(TRACE_GROUP_2, FS_INFO_GR2_READSECTORS, devflag, address, length, duration, NULL);
    }
}

#endif // __FS_TRACE_SUPPORT__

void fs_util_trace_get_task_name(kal_taskid taskid, char *dest, kal_uint32 length)
{
    char *p_name;
    int   i;

    p_name = (char*)kal_get_task_name_ptr((void*)taskid);

    if (p_name == NULL)
    {
        dest[0] = 'U';
        dest[1] = 'N';
        dest[2] = 'D';
    }
    else
    {
        for (i = 0; i < length; ++i)
        {
            if (p_name[i])
            {
                dest[i] = p_name[i];
            }
            else
            {
                while (i < length)
                {
                    dest[i++] = ' ';
                }

                break;
            }
        }
    }
}

void fs_util_trace_print_assert_info(fs_src_file_enum file, kal_uint32 line, kal_uint32 e1, kal_uint32 e2, kal_uint32 e3)
{
    kal_assert_trace(TRACE_ERROR, FS_SST_ASSERT_INFO1, file, line);
    kal_assert_trace(TRACE_ERROR, FS_SST_ASSERT_INFO2, e1, e2, e3);
    kal_assert_trace(TRACE_ERROR, FS_SST_ASSERT_GUIDELINE);
}

#define SWAP(a, b, _type) { _type tmp; tmp=a; a=b; b=tmp; }

// Get Top File Handle Consumer for Fatal Error 0xA01
void fs_util_get_top_file_handle_consumer(kal_uint8 *count, kal_uint8 *index)
{
    kal_int32 i, j;

    RTFile *f=gFS_Data.FileTable;

    // zero the counter
     for (i=0;i<FS_MAX_FILES;i++)   {
         count[i]=0;
         index[i]=i;
     }

     // For each valid file handle in the file table
     for (i=0;i<FS_MAX_FILES;i++)   {
         if (f[i].Valid) {
             // Search for the same OwnerLR, including itself.
             for (j=0;j<=i;j++)  {
                 if (f[i].OwnerLR == f[j].OwnerLR)   {  // this must be true when i==j
                     count[j]++;
                     break;
                 }
             }
         }
     }

     // use bubble sort to find the top consumers
     for (i=FS_MAX_FILES-1;i>0;i--)
         for (j=0; j<i; j++)   {
             if (count[j]<count[j+1]) {
                 SWAP(count[j], count[j+1], kal_uint8);
                 SWAP(index[j], index[j+1], kal_uint8);
             }
         }

    return;
}

// Error Handler: Print Top File Handle Consumers
// Return value: LR of the top consumer
kal_uint32 fs_util_trace_print_file_hanlde_consumer(fs_trace_func trace_func, trace_class_enum trace_class)
{
    kal_uint8 count[64];
    kal_uint8 index[64];


    if (FS_MAX_FILES>=64) return 0;

    fs_util_get_top_file_handle_consumer(count, index);

#ifdef __FS_TRACE_SUPPORT__
    if (trace_func!=NULL)   {
        RTFile *f;
        kal_int32 i;
        char taskname[FS_TRACE_MAX_TASKNAME_LEN];

        trace_func(trace_class, FS_SST_TOO_MANY_OPENED_FILES);
        trace_func(trace_class, FS_INFO_TOP_FH_USER_TITLE);

        for (i=0; i<FS_MAX_FILES && count[i]!=0; i++)   {
            f = & gFS_Data.FileTable[index[i]];
            fs_util_trace_get_task_name((kal_taskid)(f->Task), taskname, FS_TRACE_MAX_TASKNAME_LEN);
            trace_func(trace_class, FS_INFO_TOP_FH_USER, (i+1), taskname[0], taskname[1], taskname[2], f->OwnerLR, count[i]);
        }
        trace_func(trace_class, FS_INFO_TOP_FH_USER_TAIL);
    }
#endif

    return gFS_Data.FileTable[index[0]].OwnerLR;
}

#if defined(__FS_IO_STATISTICS__)
kal_uint32 fs_util_trace_io_statistics(fs_trace_func trace_func, trace_class_enum trace_class, FS_TaskIOStatistics *stat)
{
    kal_int32 task_index;
    kal_int32 thread_count;
    kal_uint32 total_io_data=0;
    kal_uint32 total_io_count=0;
    kal_uint32 total_io_time=0;
    kal_uint8 task[64];

    thread_count=RTFSYSGetThreadCount();

#ifdef __FS_TRACE_SUPPORT__
    trace_func(trace_class, FS_INFO_IO_STAT_TITLE);
#endif

    // Calculate Total IO statistics and initialize sorting external indexes
    for (task_index=0; task_index<thread_count; task_index++)    {
        total_io_data  += stat[task_index].SectorCount;
        total_io_count += stat[task_index].AccessCount;
        total_io_time  += stat[task_index].AccessTime;
        task[task_index] = task_index;
    }

    total_io_time++; // avoid divide by zero

#ifdef __FS_TRACE_SUPPORT__
{
    kal_int32 i, j;
    char taskname[FS_TRACE_MAX_TASKNAME_LEN];

    // External bubble sort
    for (i=thread_count-1;i>0;i--)
        for (j=0; j<i; j++)   {
            if (stat[task[j]].SectorCount < stat[task[j+1]].SectorCount) {
                SWAP(task[j], task[j+1], kal_uint8);
            }
        }

    // Print IO statistics of each task
    for (i=0; i<thread_count; i++)    {
        task_index=task[i];
        fs_util_trace_get_task_name((kal_taskid)(gFS_TaskList[task_index]), taskname, FS_TRACE_MAX_TASKNAME_LEN);
        trace_func(trace_class, FS_INFO_IO_STAT_ENTRY, (i+1), taskname[0], taskname[1], taskname[2],
            stat[task_index].AccessCount,
            (stat[task_index].SectorCount/2),
            (stat[task_index].AccessTime/40),
            (100*stat[task_index].AccessTime/total_io_time));
    }

    // Print total
    trace_func(trace_class, FS_INFO_IO_STAT_LINE);
    trace_func(trace_class, FS_INFO_IO_STAT_TOTAL, total_io_count, (total_io_data/2), (total_io_time/40));
    trace_func(trace_class, FS_INFO_IO_STAT_TAIL);
}
#endif

    return (stat[task[0]].AccessTime/40);
}
#endif

#else // __FS_CARD_DOWNLOAD__
int fs_util_dchar_strlen(const char *str)
{
   char *temp=(char *)str;
   int len=0;

   while ( *temp!='\0' || *(temp+1)!='\0' )
   {
      temp+=2;
      len+=2;
   }

   return len;
}

/*-----------------------------------*/
char *fs_util_dchar_strcpy(char *to, const char *from)
{
   char *temp=to;

   while ( *from!='\0' || *(from+1)!='\0' )
   {
      *to++ = *from++;
      *to++ = *from++;
   }

    *to++=0;
    *to=0;
   return temp;
}
/*-----------------------------------*/
char *fs_util_dchar_strncpy(char *to, const char *from, int n)
{
   int i;
   char *temp = to;

   n = (n&0x01) ? n+1 : n;

   for (i = 0; i < n; i+=2)
   {
      *to++ = *from++;
      *to++ = *from++;

      if ( (*from=='\0') && (*(from+1)=='\0') )
      {
         while (++i <= n)
            *to++ = 0;
         return(to);
      }

   }

   *to++=0;
   *to=0;
   return(temp);
}

int fs_util_dchar_strcmp(const char *s1, const char *s2)
{
   WCHAR wide_s1, wide_s2;

   while ( (*s1!='\0') || (*(s1+1)!='\0') )
   {
      if ( (*s1!=*s2) || (*(s1+1)!=*(s2+1)) )
         break;

      s1+=2;
      s2+=2;
   }

   wide_s1 = *s1 | (*(s1+1)<<8);
   wide_s2 = *s2 | (*(s2+1)<<8);

   return( wide_s1 - wide_s2 );
}
/*-----------------------------------*/
char *fs_util_dchar_strchr(const char *s, int c)
{
   c &= 0xffff;

   while ( *s!='\0' || *(s+1)!='\0' )
   {
       if ( (*s==(c&0xff)) && (*(s+1)==(c>>8)) )
         return (char*)s;

       s+=2;
     }

  return (0);
}


/*-----------------------------------*/
char *fs_util_dchar_strrchr(const char *str, int ch)
{
   char *found=0;
   ch &= 0xffff;

   while ( *str!='\0' || *(str+1)!='\0' )
   {
       if ( (*str==(ch&0xff)) && (*(str+1)==(ch>>8)) )
         found = (char *)str;

       str+=2;
   }

   return found;
}

#endif /* __FS_CARD_DOWNLOAD__ */

#if defined(__MTK_TARGET__) && defined(__FS_TRACE_SUPPORT__) && !defined(__FS_CARD_DOWNLOAD__) && !defined(__FS_MODIS_FDM__)
void fs_util_swla_hook(FS_Device * dev, kal_uint32 api, kal_uint32 action)
{
    kal_char   name[4];

    if (api < FS_API_END)   // FS API
    {
        name[0] = 'F';

        if (api == FS_API_READ)
        {
            name[1] = 'R';
        }
        else    // FS_API_WRITE
        {
            name[1] = 'W';
        }
    }
    else    // Driver
    {
        name[0] = 'D';

        if (api == FS_DRV_READ)
        {
            name[1] = 'R';
        }
        else    // FS_DRV_WRITE
        {
            name[1] = 'W';
        }
    }

    name[2] = '0' + (dev - (FS_Device *)gFS_DeviceList);
    name[3] = 0;

    SLA_CustomLogging(name, (SA_ACTION_T)action);
}
#endif


