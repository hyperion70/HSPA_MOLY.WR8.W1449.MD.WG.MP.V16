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
 *   This is the header file of File System utility
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
#ifndef _FS_UTILITY_H
#define _FS_UTILITY_H

#include "kal_general_types.h"
#include "kal_public_api.h" // for ASSERT and EXT_ASSERT
#include "fs_internal_def.h"
#include "fs_gprot.h"
#include "fs_iprot.h"
#include "kal_trace.h"

#define FS_TRACE_MAX_TASKNAME_LEN   (3)

#ifdef __FS_TRACE_SUPPORT__
#define FS_TRACE_MAX_FILENAME_LEN   (128)
#define MAX_TRACE_STR_LEN           (128)
#define MT_TRACE_TMP_LEN            (1536)
extern kal_uint32 g_TraceFlag;
extern char       TraceStrBuf[MAX_TRACE_STR_LEN];
extern char       TraceTmpBuf[MT_TRACE_TMP_LEN];
#endif // __FS_TRACE_SUPPORT__

/*-------------------------------------
 * Enumerations and Structures
 *-------------------------------------*/

typedef struct
{
    kal_uint32 RTCTime;
    kal_uint32 SYSTime;
} FS_TRACE_TIME;

typedef enum
{
    FS_DRV_READ         = FS_API_END + 1,
    FS_DRV_WRITE
} fs_drv_api_enum;

/*-------------------------------------
 * Macro Definitions
 *-------------------------------------*/

// FS utility
#define fs_min(X,Y) ((X) < (Y)) ? (X) : (Y)
#define fs_max(X,Y) ((X) > (Y)) ? (X) : (Y)

// Trace extra info options
#define MT_TRACE_INFO_FILE    (0x00000100)
#define MT_TRACE_INFO_WSTR    (0x00000200)
#define MT_TRACE_INFO_BSTR    (0x00000400)
#define MT_TRACE_INFO_TASK    (0x00000800)
#define MT_TRACE_INFO_MASK    (0x00000F00)

// Trace class
#define MT_TRACE_CLASS_MASK   (0x000000FF)

// Argument Count
#define MT_TRACE_ARG_COUNT_MASK   (0x00FF0000)
#define MT_TRACE_ARG_COUNT_SHIFT  (16)

#if defined(__FS_TRACE_SUPPORT__) && !defined(__FS_CARD_DOWNLOAD__)
#define fs_util_time_init()               kal_uint32 _time_start, _time_stop
#define fs_util_time_init_with_duration() kal_uint32 _time_start, _time_stop, _time_duration=0
#define fs_util_time_start()              fs_util_get_time(&_time_start)
#define fs_util_time_stop()               fs_util_get_time(&_time_stop)
#define fs_util_time_get_duration()       fs_util_get_duration(_time_start, _time_stop)
#define fs_util_time_set_duration()       _time_duration = fs_util_get_duration(_time_start, _time_stop)
#define fs_util_time_query_duration()     _time_duration
extern void         fs_util_get_time(kal_uint32 *time);
extern void         fs_util_get_time_aux(FS_TRACE_TIME *Time);
extern kal_uint32   fs_util_get_duration(kal_uint32 start_time, kal_uint32 end_time);
extern kal_uint32   fs_util_get_duration_aux(FS_TRACE_TIME *StartTime, FS_TRACE_TIME *EndTime);
extern FS_File*     fs_util_get_file_by_fh(FS_HANDLE fh);
#else // !__FS_TRACE_SUPPORT__
#define fs_util_time_init()
#define fs_util_time_init_with_duration()
#define fs_util_time_start()
#define fs_util_time_stop()
#define fs_util_time_get_duration()       0
#define fs_util_time_set_duration()
#define fs_util_time_query_duration()     0
#endif // __FS_TRACE_SUPPORT__

#ifndef GEN_FOR_PC

#if defined(__FS_TRACE_SUPPORT__) && !defined(__FS_CARD_DOWNLOAD__)
extern void fs_util_trace_info(kal_uint32 flag, void *extra_info, kal_uint32 msg_index, const char *arg_type, ...);
#define fs_util_trace_info5ex(flag, arg, data1, data2, data3, data4, data5, extra_info) fs_util_trace_info((kal_uint32)flag | (5<<MT_TRACE_ARG_COUNT_SHIFT), extra_info, arg, data1, data2, data3, data4, data5)
#define fs_util_trace_info5(flag, arg, data1, data2, data3, data4, data5)       fs_util_trace_info((kal_uint32)flag | (5<<MT_TRACE_ARG_COUNT_SHIFT), NULL, arg, data1, data2, data3, data4, data5)
#define fs_util_trace_info4(flag, arg, data1, data2, data3, data4, extra_info)  fs_util_trace_info((kal_uint32)flag | (4<<MT_TRACE_ARG_COUNT_SHIFT), extra_info, arg, data1, data2, data3, data4)
#define fs_util_trace_info2(flag, arg, data1, data2, extra_info)                fs_util_trace_info((kal_uint32)flag | (2<<MT_TRACE_ARG_COUNT_SHIFT), extra_info, arg, data1, data2)
#define fs_util_trace_info1(flag, arg, data1, extra_info)                       fs_util_trace_info((kal_uint32)flag | (1<<MT_TRACE_ARG_COUNT_SHIFT), extra_info, arg, data1)
#define fs_util_trace_info0(flag, arg, extra_info)                              fs_util_trace_info((kal_uint32)flag, extra_info, arg)

extern void fs_util_trace_err(kal_uint32 flag, kal_int32 errcode, fs_src_file_enum filecode, kal_uint32 line, void *extra_info);
extern void fs_util_trace_err_slim(kal_int32 errcode, fs_src_file_enum filecode, kal_uint32 line);
extern void fs_util_trace_str(kal_uint32 flag, void *str);
extern void fs_util_trace_device_io(kal_int32 flag, kal_uint32 address, kal_uint32 length, kal_uint32 duration);

#else // !__FS_TRACE_SUPPORT__ || __FS_CARD_DOWNLOAD__
#define fs_util_trace_info5ex(A, B, C, D, E, F, G, H)
#define fs_util_trace_info5(A, B, C, D, E, F, G)
#define fs_util_trace_info4(A, B, C, D, E, F, G)
#define fs_util_trace_info2(A, B, C, D, E)
#define fs_util_trace_info1(A, B, C, D)
#define fs_util_trace_info0(A, B, C)

#define fs_util_trace_err(A, B, C, D, E)
#define fs_util_trace_err_slim(A, B, C)
#define fs_util_trace_str(A, B)
#define fs_util_trace_device_io(A, B, C, D)

#endif // __FS_TRACE_SUPPORT__ && !__FS_CARD_DOWNLOAD__

#if defined(__MTK_TARGET__) && defined(__FS_TRACE_SUPPORT__) && !defined(__FS_CARD_DOWNLOAD__) && !defined(__FS_MODIS_FDM__)
extern void fs_util_swla_hook(FS_Device * dev, kal_uint32 api, kal_uint32 action);
#else
#define fs_util_swla_hook(A, B, C)
#endif

#endif // !GEN_FOR_PC

#if (defined(DEBUG_KAL) && !defined(__FS_PROPRIETARY_SET__)) && !defined(__FS_SLIM_CHECKSTACK__)
    #define fs_util_check_stack   kal_check_stack
#else  // !DEBUG_KAL || __FS_PROPRIETARY_SET__
    #define fs_util_check_stack()
#endif // DEBUG_KAL && !__FS_PROPRIETARY_SET__


#if defined(__MTK_TARGET__) && !defined(__UBL__)

#if defined(DEBUG_KAL)
    #define fs_assert(expr, file) do {if(!(expr)) fs_err_assert(file, __LINE__); } while (0)
#else   // !DEBUG_KAL
    #define fs_assert(expr, file)
#endif  // DEBUG_KAL

    #define fs_ext_assert(expr, file, e1, e2, e3) do {if(!(expr)) fs_err_assert_ext(file, __LINE__, e1, e2, e3); } while (0)

#else   // !MTK_TARGET || UBL

    #define fs_assert(expr, file) ASSERT(expr)
    #define fs_ext_assert(expr, file, e1, e2, e3) EXT_ASSERT(expr, e1, e2, e3)

#endif  // MTK_TARGET && !UBL

/*-------------------------------------
 * Exported Functions
 *-------------------------------------*/

// trace
typedef void (*fs_trace_func)(trace_class_enum, kal_uint32, const kal_char* , ...);

void                fs_util_trace_print_assert_info(fs_src_file_enum file, kal_uint32 line, kal_uint32 e1, kal_uint32 e2, kal_uint32 e3);
extern void         fs_util_get_top_file_handle_consumer(kal_uint8 *count, kal_uint8 *index);
extern kal_uint32   fs_util_trace_print_file_hanlde_consumer(fs_trace_func trace_func, trace_class_enum trace_class);
extern void         fs_util_trace_print_file_table(fs_trace_func trace_func, trace_class_enum trace_class);

// string
extern WCHAR        fs_util_wchar_toupper(WCHAR c);
extern int          fs_util_wstr_to_bstr(const WCHAR *wstr, char *bstr, kal_uint32 bstr_len);
extern char         fs_util_gen_friendly_char(char c);
extern char         fs_util_get_short_char(char c);
extern int          fs_util_is_power_two(unsigned int i);
extern void         fs_util_char_to_hex(char * Name, kal_uint32 TimeStamp);
extern int          fs_util_validate_sfn_char(char c);
extern int          fs_util_validate_lfn_char(WCHAR c);
extern int          fs_util_comp_uni_ascii(const char * FileName, const char* str, int len);
extern WCHAR        fs_util_uni_to_native(WCHAR unicode);
extern WCHAR        fs_util_native_to_uni(WCHAR native);
extern char         fs_util_toupper(signed char c);
extern kal_uint32   fs_util_trace_io_statistics(fs_trace_func trace_func, trace_class_enum trace_class, FS_TaskIOStatistics *stat);

// KBD
extern kal_bool     fs_util_kbd_is_key_pressed(kal_uint8 key);

// PWM
extern void         fs_util_pwm_poweron(void);

// WDT
extern void         fs_util_wdt_restart(void);
#ifdef __FS_CARD_DOWNLOAD__
extern int          fs_util_dchar_strlen(const char *str);
extern char *       fs_util_dchar_strcpy(char *to, const char *from);
extern char *       fs_util_dchar_strncpy(char *to, const char *from, int n);
extern int          fs_util_dchar_strcmp(const char *s1, const char *s2);
extern char *       fs_util_dchar_strchr(const char *s, int c);
extern char *       fs_util_dchar_strrchr(const char *str, int ch);
#else
#define fs_util_dchar_strlen    kal_dchar_strlen
#define fs_util_dchar_strcpy    kal_dchar_strcpy
#define fs_util_dchar_strncpy   kal_dchar_strncpy
#define fs_util_dchar_strcmp    kal_dchar_strcmp
#define fs_util_dchar_strchr    kal_dchar_strchr
#define fs_util_dchar_strrchr   kal_dchar_strrchr
#endif

extern kal_uint32 fs_util_get_default_encoding_length(void);

/*-------------------------------------
 * External Function References
 *-------------------------------------*/

extern kal_bool            kal_trace_check_filter_on(trace_class_enum trc_class, kal_uint32 msg_index);

#if (defined(DEBUG_KAL) && !defined(__FS_PROPRIETARY_SET__))
   extern void             kal_check_stack(void);
#endif // DEBUG_KAL && !__FS_PROPRIETARY_SET__

extern fs_util_ucs_to_wchar_func _gfs_util_ucs_to_wchar_func;

extern fs_util_get_default_encoding_length_func _gfs_util_get_default_encoding_length_func;

#endif // _FS_UTILITY_H
