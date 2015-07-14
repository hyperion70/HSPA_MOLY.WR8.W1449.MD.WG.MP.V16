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
 *   fs_task.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file provides MTK file system task
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
/*-----------------------------------
 * Included Header Files
 *-----------------------------------*/
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "fs_internal_def.h"
#include "fs_gprot.h"
#include "fs_internal_api.h"
#include "fs_trc.h"
#include "fs_utility.h"
#include "svc_sap.h"
#include "fs_msgid.h"
#include "tst_msgid.h"

#include "kal_public_defs.h" //MSBB change #include "stack_common.h"
#include "syscomp_config.h"
#include "task_config.h"

#include "fs_task.h"
#include "fs_kal.h"

#include "tst_sap.h"    // for TST inject string
#include "string.h"

#include "kal_trace.h"  // for tst_sys_trace

// Trace
#define fs_util_trace_err_noinfo(error_code) fs_util_trace_err_slim(error_code, fs_task_c, __LINE__)


// Assert
#define fs_assert_local(expr) fs_assert(expr, fs_task_c)
#define fs_ext_assert_local(expr, e1, e2, e3) fs_ext_assert(expr, fs_task_c, e1, e2, e3)

/*-----------------------------------
 * Global variables
 *-----------------------------------*/

/*-----------------------------------
 * Functions
 *-----------------------------------*/
#ifdef __FS_BENCHMARK__
#ifdef __SQLITE3_TEST_BED__
#include "kal_trace.h"
#include "sqlite3ex.h"

///////////////////////////////////////////////////////////////////////////////////////////////
// Defines
//#define FS_TEST_DB_BUF_SIZE      (150*1024)
#define FS_TEST_DB_BUF_SIZE      (450*1024)

// Locals
static int fs_db_buf[FS_TEST_DB_BUF_SIZE / 4];
static sqlite3_instance instance;
static sqlite3 *db = 0;
static int instance_init = 0;

///////////////////////////////////////////////////////////////////////////////////////////////
// Time & Logging
static kal_uint32 ticks_last = 0;
static double ticks_avg = 0;
static kal_uint32 ticks_min = 0;
static kal_uint32 ticks_max = 0;
static kal_uint32 ticks_size = 0;
static kal_uint32 ticks_paused = 0;
static kal_uint32 ticks_suspended = 0;

static const WCHAR *fs_db_log_filename = 0;
static const WCHAR *fs_db_filename_ucs2 = 0;
static const char *fs_db_filename_utf8 = 0;

static void fs_test_time_reset()
{
    ticks_last = 0;
    ticks_avg = 0;
    ticks_min = 0;
    ticks_max = 0;
    ticks_size = 0;
    ticks_paused = 0;
    ticks_suspended = 0;
}

static void fs_test_time_pause()
{
    ticks_paused=kal_get_systicks();
}

static void fs_test_time_resume()
{
    kal_uint32 ticks_now = 0;
    ticks_now=kal_get_systicks();

    ticks_suspended += (ticks_now - ticks_paused);
}

static void fs_test_time_set(int commit)
{
    kal_uint32 ticks_now = 0;
    kal_uint32 t;

    if (!commit)
    {
        ticks_last=kal_get_systicks();
        return;
    }

    ticks_now=kal_get_systicks();
    t = ticks_now - ticks_last - ticks_suspended;

    if (!ticks_min || t < ticks_min)
        ticks_min = t;
    if (t > ticks_max)
        ticks_max = t;
    ticks_avg = (double)(((double)(ticks_avg * (double)ticks_size) + (double)t) / (double)(ticks_size + 1));
    ticks_size++;
    ticks_last = ticks_now;
}

static void fs_test_file_log_delete(const WCHAR *filename)
{
/*
    int fp = FS_Open(filename, FS_READ_WRITE);
    if (fp >= FS_NO_ERROR)
    {
        FS_Close(fp);
        FS_Delete(filename);
   }
*/
}

static void fs_test_file_log(const char *data, int data_size)
{
/*
    int fp = 0;
    int wtsize = 0;

    fp = FS_Open(fs_db_log_filename, FS_READ_WRITE);
    if (fp < FS_NO_ERROR)
        fp = FS_Open(fs_db_log_filename, FS_READ_WRITE | FS_CREATE);

    FS_Seek(fp, 0, FS_FILE_END);
    FS_Write(fp, (void*)data, data_size, (UINT*)&wtsize);
    FS_Close(fp);
*/
}

static int fs_test_file_exist(const WCHAR *filename)
{
    int fp = FS_Open(filename, FS_READ_ONLY);
    if (fp >= FS_NO_ERROR)
    {
        FS_Close(fp);
        return 1;
    }
    return 0;
}


static void fs_test_time_log(const char *format, ...)
{
    va_list arg_list;
    char log[160];
    char buf[160];

    va_start(arg_list, format);
#ifdef __MTK_TARGET__
    vsnprintf(log, sizeof(log), format, arg_list);
#else
    _vsnprintf(log, sizeof(log), format, arg_list);
#endif
    va_end(arg_list);

#ifdef __MTK_TARGET__
    kal_wap_trace(
        MOD_WAP,
        TRACE_GROUP_1,
        "%s avg: %dms, min: %dms, max: %dms, samples: %d",
        log,
        kal_ticks_to_milli_secs((int)(ticks_avg+0.5)),
        kal_ticks_to_milli_secs(ticks_min),
        kal_ticks_to_milli_secs(ticks_max),
        ticks_size);
#endif
}

static void fs_test_log(const char *format, ...)
{
    va_list arg_list;
    char log[260];

    va_start(arg_list, format);
#ifdef __MTK_TARGET__
    vsnprintf(log, sizeof(log), format, arg_list);
#else
    _vsnprintf(log, sizeof(log), format, arg_list);
#endif
    va_end(arg_list);

    fs_test_file_log(log, strlen(log));

#ifdef __MTK_TARGET__
    kal_wap_trace(MOD_WAP, TRACE_GROUP_1, "%s", log);
#endif
}

///////////////////////////////////////////////////////////////////////////////////////////////
// Random related
extern kal_uint32 INT_GetCurrentTime(void);

static void fs_test_rand_init()
{
#ifdef __MTK_TARGET__
    srand(INT_GetCurrentTime());
#else
    srand((unsigned)time(0));
#endif
}

static int fs_test_rand()
{
    return rand();
}

static int fs_test_rand_range(int min_value, int max_value)
{
    return (rand()%(max_value-min_value+1)) + min_value;
}

static void fs_test_rand_fill(char *buf, int size)
{
    int i = 0;
    for (; i<size; i++)
        buf[i] = rand()%255;
}

static void fs_test_rand_fill_ascii(char *buf, int size)
{
    int i = 0;
    for (; i<size; i++)
        buf[i] = (char)fs_test_rand_range(32, 126);
}

///////////////////////////////////////////////////////////////////////////////////////////////
static void fs_test_db_transaction_begin()
{
    sqlite3_enter_instance(&instance);
    sqlite3_exec(db, "BEGIN TRANSACTION", 0, 0, 0);
}

static int fs_test_db_transaction_end()
{
    int res;

    res = sqlite3_exec(db, "END TRANSACTION", 0, 0, 0);
    sqlite3_exit_instance(&instance);

    return res;
}

///////////////////////////////////////////////////////////////////////////////////////////////
static void fs_test_db_set_filename(const WCHAR *log_file, const WCHAR *db_file_ucs2, const char *db_file_utf8)
{
    fs_db_log_filename = log_file;
    fs_db_filename_ucs2 = db_file_ucs2;
    fs_db_filename_utf8 = db_file_utf8;
}

static void fs_test_db_close()
{
    sqlite3_enter_instance(&instance);
        fs_test_time_reset();
        fs_test_time_set(0);

        sqlite3_close(db);

        fs_test_time_set(1);
        fs_test_time_log("[Close DB]");
        fs_test_log("\n");
    sqlite3_exit_instance(&instance);
    db = 0;
}

static void fs_test_db_delete_db()
{
    int fp;

    if (db)
        fs_test_db_close();

    fp = FS_Open(fs_db_filename_ucs2, FS_READ_WRITE);
    if (fp >= FS_NO_ERROR)
    {
        FS_Close(fp);
        FS_Delete(fs_db_filename_ucs2);
    }
}

static void fs_test_db_init_once()
{
    fs_test_rand_init();
}

static int fs_db_mem_usable_size = FS_TEST_DB_BUF_SIZE;

static void fs_test_set_db_mem_size(int size)
{
    fs_test_log("[Memory at %d]\n", size);
    fs_db_mem_usable_size = size;
}

static void fs_test_db_init()
{
    int fp = 0;

    //fs_test_db_delete_db();

    if (instance_init)
    {
        fs_test_log("[fs_test_db_init] Releasing last instance\n");
        sqlite3_free_instance(&instance);
    }

    fs_test_log("[fs_test_db_init] Create instance with memory: %d\n", fs_db_mem_usable_size);
    kal_mem_set(fs_db_buf, 0, sizeof(fs_db_buf));
    sqlite3_init_instance(&instance, fs_db_buf, fs_db_mem_usable_size, 0);
    instance_init = 1;

    sqlite3_enter_instance(&instance);
        fs_test_time_reset();
        fs_test_time_set(0);

        sqlite3_open(fs_db_filename_utf8, &db);

        fs_test_time_set(1);
        fs_test_time_log("[Open DB]");
        fs_test_log("\n");
    sqlite3_exit_instance(&instance);
}

#define FS_TEST_DB_SELECT_NO_LIMIT   -1
#define FS_TEST_DB_SELECT_NO_OFFSET  0

static void fs_test_db_select_query_make_limit_offset(char *sql, int limit, int offset)
{
    if (limit > FS_TEST_DB_SELECT_NO_LIMIT)
    {
        strcat(sql, " LIMIT ");
        sprintf(sql+strlen(sql), "%d", limit);
        if (offset > FS_TEST_DB_SELECT_NO_OFFSET)
        {
            strcat(sql, " OFFSET ");
            sprintf(sql+strlen(sql), "%d", offset);
        }
    }
}

static int fs_test_db_table2_select_id_order_by_indextext_limit_offset(int limit, int offset, int loop_count)
{
    sqlite3_stmt *stmt;
    int id2;
    char sql[256];
    int count = 0;
    int res;
    int i;

    //fs_test_db_init_keep_instance();
    //sqlite3_enter_instance(&instance);

    for (i=0; i<loop_count; i++)
    {
        count = 0;
        kal_mem_set(sql, 0, sizeof(sql));
        strcat(sql, "SELECT id2 FROM table2 ORDER BY table2.txta");
        fs_test_db_select_query_make_limit_offset(sql, limit, offset);

        sqlite3_prepare(db, sql, -1, &stmt, 0);

        fs_test_log("\t%s\n", sql);
        fs_test_time_reset();
        fs_test_time_set(0);
        while (sqlite3_step(stmt) == SQLITE_ROW)
        {
            id2 = sqlite3_column_int(stmt, 0);
            count++;
        }
        fs_test_time_set(1);
        sqlite3_finalize(stmt);
        fs_test_log("\tresult count: %d\n", count);
        fs_test_time_log("\t");
        fs_test_log("\n");

        offset += limit;
        kal_sleep_task(KAL_TICKS_10_MSEC);
        //kal_sleep_task(KAL_TICKS_1_SEC);
    }

    //sqlite3_exit_instance(&instance);
    //fs_test_db_close();

    return 1;
}

static void fs_test_db_table2_select_id_order_by_indextext_limit_selected_offset_4000(int limit)
{
    fs_test_db_init();
    sqlite3_enter_instance(&instance);
    sqlite3_exec(db, "BEGIN TRANSACTION", 0, 0, 0);
        fs_test_db_table2_select_id_order_by_indextext_limit_offset(limit, 0, 1);
        fs_test_db_table2_select_id_order_by_indextext_limit_offset(limit, 250, 1);
        fs_test_db_table2_select_id_order_by_indextext_limit_offset(limit, 500, 1);
        fs_test_db_table2_select_id_order_by_indextext_limit_offset(limit, 750, 1);
        fs_test_db_table2_select_id_order_by_indextext_limit_offset(limit, 1000, 1);
        fs_test_db_table2_select_id_order_by_indextext_limit_offset(limit, 1250, 1);
        fs_test_db_table2_select_id_order_by_indextext_limit_offset(limit, 1500, 1);
        fs_test_db_table2_select_id_order_by_indextext_limit_offset(limit, 1750, 1);
        fs_test_db_table2_select_id_order_by_indextext_limit_offset(limit, 2000, 1);
        fs_test_db_table2_select_id_order_by_indextext_limit_offset(limit, 2250, 1);
        fs_test_db_table2_select_id_order_by_indextext_limit_offset(limit, 2500, 1);
        fs_test_db_table2_select_id_order_by_indextext_limit_offset(limit, 2750, 1);
        fs_test_db_table2_select_id_order_by_indextext_limit_offset(limit, 3000, 1);
        fs_test_db_table2_select_id_order_by_indextext_limit_offset(limit, 3250, 1);
        fs_test_db_table2_select_id_order_by_indextext_limit_offset(limit, 3500, 1);
        fs_test_db_table2_select_id_order_by_indextext_limit_offset(limit, 3750, 1);
        fs_test_db_table2_select_id_order_by_indextext_limit_offset(limit, 4000, 1);
    sqlite3_exec(db, "END TRANSACTION", 0, 0, 0);
    sqlite3_exit_instance(&instance);
    fs_test_db_close();
}

static void fs_test_db_performance_test_1()
{
    //fs_test_db_create_all_db();

    /* LIMIT 10 */
    fs_test_set_db_mem_size(450*1024);
    fs_test_file_log_delete(L"E:\\\\fs_test_log_sort_db4000_limit_offset_in_a_conn_selected_offsets_450K_in_a_trans_limit_10");
    fs_test_db_set_filename(L"E:\\\\fs_test_log_sort_db4000_limit_offset_in_a_conn_selected_offsets_450K_in_a_trans_limit_10", L"E:\\\\db_4000", "E:\\\\db_4000");
    fs_test_db_table2_select_id_order_by_indextext_limit_selected_offset_4000(10);


    fs_test_set_db_mem_size(400*1024);
    fs_test_file_log_delete(L"E:\\\\fs_test_log_sort_db4000_limit_offset_in_a_conn_selected_offsets_400K_in_a_trans_limit_10");
    fs_test_db_set_filename(L"E:\\\\fs_test_log_sort_db4000_limit_offset_in_a_conn_selected_offsets_400K_in_a_trans_limit_10", L"E:\\\\db_4000", "E:\\\\db_4000");
    fs_test_db_table2_select_id_order_by_indextext_limit_selected_offset_4000(10);


    fs_test_set_db_mem_size(350*1024);
    fs_test_file_log_delete(L"E:\\\\fs_test_log_sort_db4000_limit_offset_in_a_conn_selected_offsets_350K_in_a_trans_limit_10");
    fs_test_db_set_filename(L"E:\\\\fs_test_log_sort_db4000_limit_offset_in_a_conn_selected_offsets_350K_in_a_trans_limit_10", L"E:\\\\db_4000", "E:\\\\db_4000");
    fs_test_db_table2_select_id_order_by_indextext_limit_selected_offset_4000(10);


    fs_test_set_db_mem_size(300*1024);
    fs_test_file_log_delete(L"E:\\\\fs_test_log_sort_db4000_limit_offset_in_a_conn_selected_offsets_300K_in_a_trans_limit_10");
    fs_test_db_set_filename(L"E:\\\\fs_test_log_sort_db4000_limit_offset_in_a_conn_selected_offsets_300K_in_a_trans_limit_10", L"E:\\\\db_4000", "E:\\\\db_4000");
    fs_test_db_table2_select_id_order_by_indextext_limit_selected_offset_4000(10);


    fs_test_set_db_mem_size(250*1024);
    fs_test_file_log_delete(L"E:\\\\fs_test_log_sort_db4000_limit_offset_in_a_conn_selected_offsets_250K_in_a_trans_limit_10");
    fs_test_db_set_filename(L"E:\\\\fs_test_log_sort_db4000_limit_offset_in_a_conn_selected_offsets_250K_in_a_trans_limit_10", L"E:\\\\db_4000", "E:\\\\db_4000");
    fs_test_db_table2_select_id_order_by_indextext_limit_selected_offset_4000(10);


    fs_test_set_db_mem_size(200*1024);
    fs_test_file_log_delete(L"E:\\\\fs_test_log_sort_db4000_limit_offset_in_a_conn_selected_offsets_200K_in_a_trans_limit_10");
    fs_test_db_set_filename(L"E:\\\\fs_test_log_sort_db4000_limit_offset_in_a_conn_selected_offsets_200K_in_a_trans_limit_10", L"E:\\\\db_4000", "E:\\\\db_4000");
    fs_test_db_table2_select_id_order_by_indextext_limit_selected_offset_4000(10);


    fs_test_set_db_mem_size(150*1024);
    fs_test_file_log_delete(L"E:\\\\fs_test_log_sort_db4000_limit_offset_in_a_conn_selected_offsets_150K_in_a_trans_limit_10");
    fs_test_db_set_filename(L"E:\\\\fs_test_log_sort_db4000_limit_offset_in_a_conn_selected_offsets_150K_in_a_trans_limit_10", L"E:\\\\db_4000", "E:\\\\db_4000");
    fs_test_db_table2_select_id_order_by_indextext_limit_selected_offset_4000(10);
}

static fs_test_db_sqlite(void)
{
    fs_test_db_init_once();

    fs_test_file_log_delete(L"E:\\\\fs_test_log_init");
    fs_test_db_set_filename(L"E:\\\\fs_test_log_init", 0, 0);
    fs_test_set_db_mem_size(150*1024);

    fs_test_db_performance_test_1();
    kal_sleep_task(KAL_TICKS_1_SEC);

}
#endif /* __SQLITE3_TEST_BED__ */

#if defined(__FS_DEDICATED_BUFFER__)

#define __FS_TASK_FS_BENCHMARK
#define FS_BENCH_SEEK_LIMIT 32
#define FS_BENCH_HINT_COUNT 1024
#define FS_BENCH_HINT_FILE  1024
#define FS_BENCH_BUFF_SIZE  (256*1024)
#define FS_BENCH_RAND_ACCESS_LEN (512)

#include "rtfiles.h"
#include "rtfbuf.h"     // for FS dedicated buffer related definition
//#include "app_mem_med.h"

static void SYS_TRACE(kal_uint8 *buff, const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    vsprintf((char *)(&buff[0]), fmt, args);
    tst_sys_trace((kal_char*)(&buff[0])); // Default
    return;
}

// The FS_TaskIOStatistics is defined in fs_gprot.h
/* ------------------------------------------------------------------------------- */
FS_TaskIOStatistics *fst_iostat=NULL;

void fs_test_stat_start(void)
{
    if (fst_iostat==NULL)   {
        // Allocate control buffer
        fst_iostat=(FS_TaskIOStatistics*)get_ctrl_buffer(FS_GetIOStatisticsSize());
        // Save current IO statistic, and start logging
        FS_StartIOLog(fst_iostat);
    }
}

kal_uint32 fs_test_stat_end(void)
{
    kal_uint32 result=0;
    if (fst_iostat!=NULL)   {
        // Stop logging, and print results to TST trace, MOD_FS: TRACE_ERROR
        result=FS_EndIOLog(fst_iostat);
        // Free control buffer
        free_ctrl_buffer(fst_iostat);
        fst_iostat=NULL;
    }
    return result;
}

/* ------------------------------------------------------------------------------- */
#define TIME_DIFF(start,end)   ((start>end)?(end+0x01000000-start):(end-start))
extern kal_uint32 INT_GetCurrentTime(void);
extern int rand(void);

// Test Process 1: Read/Write speed and Buffer Size
/* ------------------------------------------------------------------------------- */
static kal_int32 fs_bench_proc1(kal_uint8 *fs_buff, kal_uint32 fs_buff_size, kal_int32 fhandle, kal_uint32 test_file_size)
{
    kal_uint32 wSTime, wETime, wAver, len, i, dev_time;

    SYS_TRACE(&fs_buff[512], "[MAUI.FS.Benchmark][Buffer][Info] Test File Size: %d KB, Buffer Size: %d bytes", (test_file_size/1024), fs_buff_size);

    if (fs_buff_size==0) return -1;

    // Test 1: Sequential write test
    wAver=0;
    fs_test_stat_start();
    for (i=0; i < test_file_size/fs_buff_size; i++)  {

        wSTime = INT_GetCurrentTime();
        FS_Write(
            fhandle,    // File Handle
            fs_buff,    // Write Buffer
            fs_buff_size,       // Write Length
            &len        // Written bytes (out)
            );
        wETime = INT_GetCurrentTime();
        if (len!=fs_buff_size)  {
            SYS_TRACE(&fs_buff[512], "[MAUI.FS.Benchmark][Buffer][Error] Write Error at %d",i*test_file_size);
            break;
        }
        wAver += TIME_DIFF(wSTime, wETime);
    }
    dev_time=fs_test_stat_end();
    SYS_TRACE(&fs_buff[512], "[MAUI.FS.Benchmark][Buffer][Result] Buffer Size= %d bytes, Write speed= %f KB/s, time_fs= %f ms, time_dev= %d ms",
        fs_buff_size, (i*fs_buff_size)/(wAver*0.03125), (wAver*0.03125), dev_time);

    // Test 2: sequential read test
    wAver=0;
    fs_test_stat_start();
    FS_Seek(fhandle, 0, FS_FILE_BEGIN);
     for (i=0; i < test_file_size/fs_buff_size; i++)  {
        wSTime = INT_GetCurrentTime();
        FS_Read(
            fhandle,    // File Handle
            fs_buff,    // Write Buffer
            fs_buff_size,       // Write Length
            &len        // Written bytes (out)
            );
        wETime = INT_GetCurrentTime();
        wAver += TIME_DIFF(wSTime, wETime);
    }
    dev_time=fs_test_stat_end();
    SYS_TRACE(&fs_buff[512], "[MAUI.FS.Benchmark][Buffer][Result] Buffer Size= %d bytes, Read speed= %f KB/s, time_fs= %f ms, time_dev= %d ms",
        fs_buff_size, (i*fs_buff_size)/(wAver*0.03125), (wAver*0.03125), dev_time);

    return 0;
}

// Test Process 2: Search speed and Number of Files
// $Delete a non-exist file in huge folders$
/* ------------------------------------------------------------------------------- */
static kal_int32 fs_bench_proc2(kal_uint8 *fs_buff, kal_uint8 driveletter, kal_int32 filenumber)
{
    kal_uint32 wSTime, wETime, wAver, dev_time;
    kal_int32 result;
    WCHAR *filename=(WCHAR*)&fs_buff[512];

    kal_wsprintf(filename, "%c:\\%d", driveletter, filenumber);
    result=FS_GetAttributes(filename);

    if (result<0) return result;
    if (result & FS_ATTR_DIR == 0) return FS_PATH_NOT_FOUND;

    kal_wsprintf(filename, "%c:\\%d\\This.is.the.test.file.for.the.numerous.file.test.NotExist.txt", driveletter, filenumber);

    fs_test_stat_start();
    wSTime = INT_GetCurrentTime();
    result =FS_Delete(filename);
    wETime = INT_GetCurrentTime();
    wAver=TIME_DIFF(wSTime, wETime);
    dev_time=fs_test_stat_end();

    SYS_TRACE(&fs_buff[512], "[MAUI.FS.Benchmark][Search][Result] Number of Files=%d, search time taken %f ms, device time taken %d ms", filenumber, (wAver*0.03125), dev_time);

    return 0;
}

// Test Process 3: Seek speed and File Size
/* ------------------------------------------------------------------------------- */
static kal_int32 fs_bench_proc3(kal_uint8 *fs_buff, kal_uint8 driveletter, kal_int32 filesize)
{
    FS_HANDLE hnd;
    kal_uint32 wSTime, wETime, wAver, i, dev_time;
    kal_uint64 offset;
    kal_int32 result=FS_NO_ERROR;
    WCHAR *filename=(WCHAR*)&fs_buff[512];

    kal_wsprintf(filename, "%c:\\%d.txt", driveletter, filesize);
    hnd = FS_Open(filename, FS_READ_WRITE);
    if (hnd<0) return hnd;

    wAver=0;

    fs_test_stat_start();
    for (i=0;i<FS_BENCH_SEEK_LIMIT;i++)    {
        offset = rand()%(filesize*1024*1024);
        wSTime = INT_GetCurrentTime();
        result = FS_SeekLargeFile(hnd, offset, FS_FILE_BEGIN);
        wETime = INT_GetCurrentTime();
        wAver += TIME_DIFF(wSTime, wETime);
        if (result<0) break;
    }
    dev_time=fs_test_stat_end();

    FS_Close(hnd);

    SYS_TRACE(&fs_buff[512], "[MAUI.FS.Benchmark][Seek][Result] File size: %dMB, average seek time: %f us, total: %f ms, total dev time: %d ms", filesize, ((wAver*31.25)/FS_BENCH_SEEK_LIMIT), (wAver*0.03125), dev_time);

    return result;
}

// Test Process 4: Seek speed and Number of Hints
/* ------------------------------------------------------------------------------- */
static kal_int32 fs_bench_proc4(kal_uint8 *fs_buff, kal_uint8 driveletter, kal_int32 hintcount)
{
    FS_HANDLE hnd;
    kal_uint32 wSTime, wETime, wAver, i, dev_time;
    kal_uint64 offset;
    kal_int32 filesize;
    kal_int32 result=FS_NO_ERROR;
    kal_int32 cluster_size;
    kal_int32 hint_distance;
    FS_FileLocationHint *hint;

    WCHAR *filename=(WCHAR*)&fs_buff[512];
    filesize=FS_BENCH_HINT_FILE;

    while (1)   {
        kal_wsprintf(filename, "%c:\\%d.txt", driveletter, filesize);
        hnd = FS_Open(filename, FS_READ_WRITE);
        if (hnd>=0) break;
        filesize /= 2;
    }

    if (hnd<0) return hnd;

    // Set Seek Hints
    hint=(FS_FileLocationHint*)&fs_buff[512];
    filesize=filesize*1024*1024;
    cluster_size=FS_GetClusterSize(driveletter);
    hint_distance=(filesize/cluster_size/(hintcount+1))*cluster_size;

    kal_mem_set(hint, 0, sizeof(FS_FileLocationHint)*hintcount);

    for (i=0;i<hintcount;i++) {
        hint[i].Index=(i+1)*hint_distance;
    }

    result=FS_SetSeekHint(hnd, hintcount, hint);
    if (result<0) return result;

    // Start Seek Test
    wAver=0;

    fs_test_stat_start();
    for (i=0;i<FS_BENCH_SEEK_LIMIT;i++)    {
        offset = rand()%filesize;
        wSTime = INT_GetCurrentTime();
        result = FS_SeekLargeFile(hnd, offset, FS_FILE_BEGIN);
        wETime = INT_GetCurrentTime();
        wAver += TIME_DIFF(wSTime, wETime);
        if (result<0) break;
    }
    dev_time=fs_test_stat_end();

    FS_Close(hnd);

    SYS_TRACE(&fs_buff[512], "[MAUI.FS.Benchmark][SeekHint][Result] File size: %dMB, Number of Hints= %d ,average seek time: %f us, total: %f ms, total dev time: %d ms", filesize/1024/1024, hintcount, ((wAver*31.25)/FS_BENCH_SEEK_LIMIT), (wAver*0.03125), dev_time);

    return result;
}

// Test Process 5: Random Access Speed and File Size
/* ------------------------------------------------------------------------------- */
static kal_int32 fs_bench_proc5(kal_uint8 *fs_buff, kal_uint8 driveletter, kal_int32 filesize, kal_int32 fs_buff_size)
{
    FS_HANDLE hnd;
    kal_uint32 wSTime, wETime, wAver, i, len, dev_time;
    kal_uint64 offset;
    kal_int32 result;
    WCHAR *filename=(WCHAR*)&fs_buff[512];

//    SYS_TRACE(&fs_buff[512], "[MAUI.FS.Benchmark][RandomAccess][Info] Test File Size: %d MB, Buffer Size: %d bytes", filesize, fs_buff_size);

    kal_wsprintf(filename, "%c:\\%d.txt", driveletter, filesize);
    hnd = FS_Open(filename, FS_READ_WRITE);
    if (hnd<0) return hnd;

    wAver=0;

    fs_test_stat_start();
    for (i=0;i<FS_BENCH_SEEK_LIMIT;i++)    {
        offset = rand()%(filesize*1024*1024-fs_buff_size);
        wSTime = INT_GetCurrentTime();
        result = FS_SeekLargeFile(hnd, offset, FS_FILE_BEGIN);
        if (result<0) break;
        result = FS_Write(
                hnd,        // File Handle
                fs_buff,    // Write Buffer
                fs_buff_size,       // Write Length
                &len        // Written bytes (out)
                );
        wETime = INT_GetCurrentTime();
        wAver += TIME_DIFF(wSTime, wETime);
        if (result<0) break;
    }
    dev_time=fs_test_stat_end();

    if (result<0) {
        FS_Close(hnd);
        return result;
    }

    SYS_TRACE(&fs_buff[512], "[MAUI.FS.Benchmark][RandomWrite][Result] File size: %dMB, buffer size= %d, average write speed: %f KB/s, time_fs= %f ms, time_dev= %d ms",
        filesize, fs_buff_size, (i*fs_buff_size)/(wAver*0.03125), (wAver*0.03125), dev_time);

    wAver=0;

    fs_test_stat_start();
    for (i=0;i<FS_BENCH_SEEK_LIMIT;i++)    {
        offset = rand()%(filesize*1024*1024-fs_buff_size);
        wSTime = INT_GetCurrentTime();
        result = FS_SeekLargeFile(hnd, offset, FS_FILE_BEGIN);
        if (result<0) break;
        FS_Read(
            hnd,    // File Handle
            fs_buff,    // Write Buffer
            fs_buff_size,       // Write Length
            &len        // Written bytes (out)
            );
        wETime = INT_GetCurrentTime();
        wAver += TIME_DIFF(wSTime, wETime);
        if (result<0) break;
    }
    dev_time=fs_test_stat_end();

    FS_Close(hnd);

    if (result<0) {
        return result;
    }

    SYS_TRACE(&fs_buff[512], "[MAUI.FS.Benchmark][RandomRead][Result] File size: %dMB, buffer size= %d, average read speed: %f KB/s, time_fs= %f ms, time_dev= %d ms",
        filesize, fs_buff_size, (i*fs_buff_size)/(wAver*0.03125), (wAver*0.03125), dev_time);

    return 0;
}



/* ------------------------------------------------------------------------------- */
// [Out] buf_ptr: Pointer to the buffer
// [Out] buf_size: Size of allocated buffer
static kal_int32 fs_bench_buf_alloc(unsigned char **buf_ptr, kal_uint32 *buf_size)
{
    kal_uint32 len;
    kal_int32 i;
    kal_uint32 fs_buff_size_init;

    #if 0  // FS Dedicate Buffer
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
    #else  // Application Memory

    fs_buff_size_init=FS_BENCH_BUFF_SIZE;
    *buf_ptr=NULL;

    for (i=4; i!=0; i--)    {
        *buf_ptr=(void*)applib_asm_alloc_anonymous(fs_buff_size_init);
        if (*buf_ptr!=NULL) break;
        fs_buff_size_init/=2;
    }

    if (*buf_ptr==NULL) {
        tst_sys_trace("Buffer allocation failed");
        return -1;
    }

    #endif

    // Fill buffer with random values
    for (len=0;len<fs_buff_size_init;len++) {
        (*buf_ptr)[len] = rand() & 0xFF;
    }

    *buf_size=fs_buff_size_init;

    return 0;
}

static void fs_bench_buf_free(unsigned char **buf_ptr, kal_uint32 buf_size)
{
    #if 0
/* under construction !*/
    #else
    applib_asm_free_anonymous(*buf_ptr);
    #endif
}

static void fs_bench(kal_uint32 test_file_size, kal_uint8 *filename)
{
    int fhandle;
    kal_uint32 fs_buff_size, fs_buff_size_init;
    kal_uint32 file_size, file_count, hint_count;
    kal_uint8 *fs_buff;

    // Get file size 2^n KB
    test_file_size = 1024 << test_file_size;

    // Allocate Bufer
    if (fs_bench_buf_alloc(&fs_buff ,&fs_buff_size_init))   {
        return;
    }
    kal_wsprintf((WCHAR*)(&fs_buff[0]),"%s", filename);

    // Process 1: Read/Write speed and Buffer Size
    //-----------------------------------------------
    // Covert filename to wide char string, and store it to the temp buffer
    for (fs_buff_size=fs_buff_size_init;fs_buff_size>=512;fs_buff_size/=2)   {
        FS_Delete((WCHAR*)(&fs_buff[0]));
        // Create the file for writing
        fhandle = FS_Open((WCHAR*)(&fs_buff[0]), FS_READ_WRITE|FS_CREATE_ALWAYS);
        if (fhandle<0)  {
            tst_sys_trace("Can not open file for write");
            MTBufFree(fs_buff_size_init, &fs_buff);
            return;
        }

        // Run read/write test
        fs_bench_proc1(fs_buff, fs_buff_size, fhandle, test_file_size);

        // Finalize
        FS_Close(fhandle);
    }
    FS_Delete((WCHAR*)(&fs_buff[0]));

    // Process 2: Search speed and Number of Files
    //-----------------------------------------------
    for (file_count=10; ;file_count*=10) {
        if (fs_bench_proc2(fs_buff, filename[0], file_count) < 0) break;
    }

    // Process 3: Seek Speed and File Size
    //-----------------------------------------------
    for (file_size=2; ;file_size*=2) {
        if (fs_bench_proc3(fs_buff, filename[0], file_size) < 0) break;
    }

    // Process 4: Seek speed and Number of Hints
    //-----------------------------------------------
    for (hint_count=16;hint_count<=FS_BENCH_HINT_COUNT;hint_count*=2)   {
        if (fs_bench_proc4(fs_buff, filename[0], hint_count) <0) break;
    }

    // Test Process 5: Random Access Speed and File Size
    /* ------------------------------------------------------------------------------- */
    for (file_size=2; ;file_size*=2) {
        if (fs_bench_proc5(fs_buff, filename[0], file_size, 512)) break;
    }

    // Free Buffer
    fs_bench_buf_free(&fs_buff ,fs_buff_size_init);

}

#endif // __FS_DEDICATED_BUFFER__

#endif // __FS_BENCHMARK__

#define __FS_TASK_ASYNC_SUPPORT

#define FS_JOB_ID_BITS  (8 * sizeof(kal_uint32))

#define FS_JOB_ID_MAX   ((1 << ((FS_JOB_ID_BITS / 2) - 1)) - 1)     // 0xEFFF (max value of kal_int16)

#if defined(__FS_ASYNC_SUPPORT_TASK__)
/*--------------------------------------------------------
 * Job ID
 *--------------------------------------------------------*/

fs_job_id   _gfs_job_id = 1;

/*--------------------------------------------------------
 * Job Status
 *--------------------------------------------------------*/

fs_job_id       _gfs_job_running_id = 0;

fs_job_struct   *_gfs_job_running = NULL;

/*--------------------------------------------------------
 *   FS Job List
 *--------------------------------------------------------*/

fs_job_struct *_gfs_job_list = NULL;

/*--------------------------------------------------------
 *   FS Task Priority
 *--------------------------------------------------------*/

kal_uint32  _gfs_task_current_priority = 0;

kal_uint32  _gfs_task_default_priority = 0;

kal_taskid  _gfs_task_id = NULL;

#elif defined(__FS_ASYNC_SUPPORT_ALONE__)

/*--------------------------------------------------------
 * Job ID
 *--------------------------------------------------------*/

fs_job_id   _gfs_job_id = 1;

#endif  // __FS_ASYNC_SUPPORT__


#define FS_ASYNC_SERVICE_API

/*--------------------------------------------------------
 *   Internal API Declarations (Common)
 *--------------------------------------------------------*/

msg_type            fs_job_api_to_msgid(fs_api_enum api);

#if defined(__FS_ASYNC_SUPPORT_TASK__)

/*--------------------------------------------------------
 *   Internal API Declarations (Task Version)
 *--------------------------------------------------------*/

void                fs_job_dispatcher(void);
fs_job_struct*      fs_job_get_first(kal_uint32 option);
void                fs_job_insert(fs_job_struct *t);
void                fs_job_response(fs_job_struct *job);
fs_job_struct*      fs_job_search(fs_job_id id);
void                fs_task_msg_handler(ilm_struct *ilm);

#endif  // __FS_ASYNC_SUPPORT_TASK__

/*--------------------------------------------------------
 *   Internal API Bodies (Common)
 *--------------------------------------------------------*/

msg_type fs_job_api_to_msgid(fs_api_enum api)
{
    switch (api)
    {
        case FS_API_OPEN:
            return MSG_ID_FS_OPEN_RSP;
        case FS_API_WRITE:
            return MSG_ID_FS_WRITE_RSP;
        case FS_API_READ:
            return MSG_ID_FS_READ_RSP;
        case FS_API_SEEK:
            return MSG_ID_FS_SEEK_RSP;
        case FS_API_DELETE:
            return MSG_ID_FS_DELETE_RSP;
        case FS_API_GETFOLDERSIZE:
            return MSG_ID_FS_GET_FOLDER_SIZE_RSP;
        case FS_API_FINDFIRST:
            return MSG_ID_FS_FIND_FIRST_RSP;
        case FS_API_FINDFIRSTN:
            return MSG_ID_FS_FIND_FIRST_N_RSP;
        default:
            break;
    }

    return (msg_type)0;
}

#if defined(__FS_ASYNC_SUPPORT_TASK__)

/*--------------------------------------------------------
 *   Internal API Bodies (Task Version)
 *--------------------------------------------------------*/
void fs_job_check_job_list_dump(void)
{
    fs_job_struct   *job = NULL;
    kal_uint32 length=0;

    fs_lock_get_mutex(_gfs_lock_common, FS_INFINITE);

    fs_util_trace_info2(TRACE_ERROR, FS_API_FS_ASYNC_JOB_RUNNING_JOB, (kal_uint32)_gfs_job_running_id, (kal_uint32)_gfs_job_running, NULL);
    fs_util_trace_info2(TRACE_ERROR, FS_API_FS_ASYNC_JOB_LIST_ENTRY, (kal_uint32)((_gfs_job_list==NULL)?0:_gfs_job_list->id), (kal_uint32)_gfs_job_list, NULL);

    job = _gfs_job_list;

    while (job!=NULL) {
        job=job->next;
        length++;
        if (length>100) break;
        fs_util_trace_info2(TRACE_ERROR, FS_API_FS_ASYNC_JOB_LIST_ENTRY, (kal_uint32)((job==NULL)?0:job->id), (kal_uint32)job, NULL);
    }

    fs_lock_free_mutex(_gfs_lock_common);
}


kal_bool fs_job_check_job_list(fs_job_struct *exist_job)
{
    fs_job_struct   *job = NULL;
    kal_uint32 length=0;

    fs_lock_get_mutex(_gfs_lock_common, FS_INFINITE);

    job = _gfs_job_list;

    while (job!=NULL) {
        if (exist_job==job) {
            fs_util_trace_info1(TRACE_ERROR, FS_API_FS_ASYNC_JOB_LIST_ERROR_JOBPTR_EXIST, (kal_uint32)exist_job, NULL);
            fs_job_check_job_list_dump();
            fs_assert_local(0);
        }
        fs_assert_local(job->state==FS_JOB_STATE_NOT_STARTED || job->state==FS_JOB_STATE_ABORTING);
        job=job->next;
        length++;
        if (length>100) {
            fs_util_trace_info0(TRACE_ERROR, FS_API_FS_ASYNC_JOB_LIST_ERROR_ENDLESS_LINK, NULL);
            fs_job_check_job_list_dump();
            fs_assert_local(0);
        }
    }

    fs_lock_free_mutex(_gfs_lock_common);

    return KAL_TRUE;
}

kal_bool fs_job_abort(fs_job_id job_id)
{
    return fs_job_abort_ex(job_id, NULL);
}

kal_bool fs_job_abort_ex(fs_job_id job_id, void *buf)
{
    fs_job_struct   *job;
    /*
     * Case 1: Job is not started (in FS task's queue)
     * Case 2: Job is running (connot be aborted
     * Case 3: Job is finished (not sent to user task or in user task's queue)
     */

    if (job_id== 0) return KAL_FALSE;  // job id 0 is invalid! (to avoid setting ALL file handles as FS_FH_ABORTED!)

    fs_lock_get_mutex(_gfs_lock_common, FS_INFINITE);

    fs_job_check_job_list(NULL);

    if (_gfs_job_running_id == job_id)  // target job is RUNNING (Case 2)
    {
        _gfs_job_running->state = FS_JOB_STATE_ABORTING;
        fs_lock_free_mutex(_gfs_lock_common);
        return KAL_TRUE;
    }
    else                            // target job is pending in job list or queue
    {
        job = fs_job_search(job_id);    // look-up target in job list

        if (job != NULL)    // found it! target is in job list! (Case 1)
        {
            if (job->state == FS_JOB_STATE_NOT_STARTED)
            {
                job->state  = FS_JOB_STATE_ABORTING;
                job->result = FS_ABORTED_ERROR;
            }
            else if (job->state == FS_JOB_STATE_ABORTING)
            {
                // no action should be made. (should ASSERT because user can't abort the same job twice)
            }
            else    // RUNNING job can't be found by fs_job_search()!
            {
                fs_util_trace_info4(TRACE_ERROR, FS_API_FS_ASYNC_JOB_ERROR_UNEXPECTED_STATE, (kal_uint32)job->state, (kal_uint32)job->id, (kal_uint32)job, NULL, NULL);
                fs_assert_local(0);
            }

            fs_lock_free_mutex(_gfs_lock_common);
            return KAL_TRUE;
        }
        else // job may be still in queue or may be not existed (Case 3)
        {
            // The job is not yet recieved by FS task
            job = (fs_job_struct*)buf;
            if (job!=NULL)  {
                if (job->state!=FS_JOB_STATE_FINISHED)  {
                    job->state=FS_JOB_STATE_ABORTING;
                }
                fs_lock_free_mutex(_gfs_lock_common);
                return KAL_TRUE;
            }
        }
    }

    fs_lock_free_mutex(_gfs_lock_common);
    return KAL_FALSE;
}

kal_int32 fs_job_alloc_id(fs_job_id *id, fs_overlapped_struct *overlapped)
{
    //--1. check working buffer
    if (overlapped->buf == NULL ||
        overlapped->buf_size < FS_ASYNC_WORKING_BUFFER_SIZE ||
        (kal_uint32)(overlapped->buf) & 0x3)     // should be 4-byte aligned memory address
    {
        fs_util_trace_err_noinfo(FS_FAIL_GET_MEM);

        return FS_FAIL_GET_MEM;
    }

    //--2. allocate Job ID

    fs_lock_get_mutex(_gfs_lock_common, FS_INFINITE);

    fs_job_check_job_list((fs_job_struct*)(overlapped->buf));


    *id = _gfs_job_id;

    _gfs_job_id = (_gfs_job_id + 1) & FS_JOB_ID_MAX;

    if (_gfs_job_id == 0)
    {
        _gfs_job_id = 1;
    }

    fs_lock_free_mutex(_gfs_lock_common);

    return FS_NO_ERROR;
}

kal_int32 fs_job_exec_read(fs_job_read_struct *job)
{
    kal_int32  result=0;
    kal_uint32 length, read, segment_length;
    kal_uint8 *ptr;

    if (job->chunksize < (32)FS_KB) {
        result = FS_Read(job->handle,
                         job->data,
                         job->length,
                         job->read);
    }
    else {
        length = job->length;
        read=0;
        ptr=job->data;

        if (job->read !=NULL)   {
            *job->read = 0;
        }

        while (length>0) {
            if (job->state==FS_JOB_STATE_ABORTING)  {
                result=FS_ABORTED_ERROR;
                break;
            }

            segment_length = (length > job->chunksize) ? job->chunksize : length;

            result = FS_Read(job->handle,
                             ptr,
                             segment_length,
                             &read);

            if (result<0) break;

            if (job->read !=NULL)   {
                *job->read += read;
            }
            ptr       += read;
            length    -= read;
        }
    }

    return result;
}


void fs_job_dispatcher()
{
    fs_job_struct       *job;
    kal_int64           result = FS_NO_ERROR;

    // get the first job to run (it will remove job node from job list as well!)
    job = fs_job_get_first(FS_TASK_JOB_GETFIRST_POPTORUN);

    if (NULL == job) return;

    fs_util_trace_info4(TRACE_FUNC, FS_API_FS_ASYNC_JOB_DISPATCH_START, (kal_uint32)job->id, (kal_uint32)job, (kal_uint32)job->state, (kal_uint32)job->api, NULL);

    // check if this job has been aborted
    if (job->state == FS_JOB_STATE_ABORTING)
    {
        job->result = FS_ABORTED_ERROR;
    }
    else
    {
        // adjust fs task's priority if required
        fs_task_priority_change(job->priority, FS_TASK_PRIORITY_CHANGE_DEFAULT);

        // dispatch
        if (FS_API_OPEN == job->api)
        {
            result = FS_OpenLR(((fs_job_open_struct*)job)->filename,
                               ((fs_job_open_struct*)job)->flag,
                               ((fs_job_open_struct*)job)->caller_address);
        }
        else if (FS_API_GETFOLDERSIZE == job->api)
        {
            result = FS_GetFolderSize(((fs_job_get_folder_size_struct*)job)->path,
                                      ((fs_job_get_folder_size_struct*)job)->flag,
                                      ((fs_job_get_folder_size_struct*)job)->recursive_stack,
                                      ((fs_job_get_folder_size_struct*)job)->stack_size);
        }
        else if (FS_API_SEEK == job->api)
        {
            result = FS_SeekLargeFile(((fs_job_seek_struct*)job)->handle,
                                      ((fs_job_seek_struct*)job)->offset,
                                      ((fs_job_seek_struct*)job)->whence);
        }
        else if (FS_API_DELETE == job->api)
        {
            result = FS_Delete(((fs_job_delete_struct*)job)->filename);
        }
        else if (FS_API_READ == job->api)
        {
            result = fs_job_exec_read((fs_job_read_struct*)job);
        }
        else if (FS_API_WRITE == job->api)
        {
            result = FS_Write(((fs_job_write_struct*)job)->handle,
                              ((fs_job_write_struct*)job)->data,
                              ((fs_job_write_struct*)job)->length,
                              ((fs_job_write_struct*)job)->written);
        }
        else if (FS_API_FINDFIRST == job->api)
        {
            result = FS_FindFirst(((fs_job_find_first_struct*)job)->name_pattern,
                                  ((fs_job_find_first_struct*)job)->attr,
                                  ((fs_job_find_first_struct*)job)->attr_mask,
                                  ((fs_job_find_first_struct*)job)->file_info,
                                  ((fs_job_find_first_struct*)job)->file_name,
                                  ((fs_job_find_first_struct*)job)->max_length);
        }
        else if (FS_API_FINDFIRSTN == job->api)
        {
            result = FS_FindFirstN(((fs_job_find_first_n_struct*)job)->name_pattern,
                                   ((fs_job_find_first_n_struct*)job)->pattern_array,
                                   ((fs_job_find_first_n_struct*)job)->pattern_num,
                                   ((fs_job_find_first_n_struct*)job)->array_mask,
                                   ((fs_job_find_first_n_struct*)job)->attr,
                                   ((fs_job_find_first_n_struct*)job)->attr_mask,
                                   ((fs_job_find_first_n_struct*)job)->file_info,
                                   ((fs_job_find_first_n_struct*)job)->file_name,
                                   ((fs_job_find_first_n_struct*)job)->max_length,
                                   ((fs_job_find_first_n_struct*)job)->entry_index,
                                   ((fs_job_find_first_n_struct*)job)->flag);
        }
        else
        {
            fs_util_trace_info4(TRACE_ERROR, FS_API_FS_ASYNC_JOB_ERROR_UNKNOW_API, (kal_uint32)job->api, (kal_uint32)job->api, (kal_uint32)job->id, (kal_uint32)job, NULL);
            fs_assert_local(0);
        }

        job->result = result;
    }

    // update job state and FS task's status
    fs_lock_get_mutex(_gfs_lock_common, FS_INFINITE);
    fs_job_check_job_list(job);

    if (job->state != FS_JOB_STATE_ABORTING)
    {
        fs_util_trace_info4(TRACE_FUNC, FS_API_FS_ASYNC_JOB_DISPATCH_FINISH, (kal_uint32)job->id, (kal_uint32)job, (kal_uint32)job->state, (kal_uint32)job->api, NULL);
        job->state = FS_JOB_STATE_FINISHED;

    }
    else {
        fs_util_trace_info4(TRACE_FUNC, FS_API_FS_ASYNC_JOB_DISPATCH_ABORT, (kal_uint32)job->id, (kal_uint32)job, (kal_uint32)job->state, (kal_uint32)job->api, NULL);
    }

    _gfs_job_running = NULL;

    _gfs_job_running_id = 0;

    fs_lock_free_mutex(_gfs_lock_common);

    // Send response message or invoke the callback function
    // *Note*: the job pointer is freed after fs_job_response(),
    //       do not access the pointer to prevent data aborts.
    fs_job_response(job);

    /*
     * Todo List:
     *  1. Need to consider job partition (longterm plan)
     *  2. Use a CMM to parse job queue
     */
}


fs_job_struct* fs_job_get_first(kal_uint32 option)
{
    fs_job_struct *job;

    fs_util_trace_info1(TRACE_FUNC, FS_API_FS_ASYNC_JOB_GET_FIRST_S, option, NULL);
    fs_lock_get_mutex(_gfs_lock_common, FS_INFINITE);
    fs_job_check_job_list(NULL);

    if (_gfs_job_list == NULL)
    {
        job = NULL;
    }
    else
    {
        job = _gfs_job_list;

        /*
         * FS_TASK_JOB_GETFIRST_POPTORUN will be only used by Job Dispatcher.
         * It means this job is selected to be executed, therefore we need to update global status here!
         */

        if (option == FS_TASK_JOB_GETFIRST_POPTORUN)
        {
            //-- 1. Job List handling

            _gfs_job_list = _gfs_job_list->next;

            job->next = NULL;   // clear next ptr

            //-- 2. FS task status handling

            if (job->state != FS_JOB_STATE_ABORTING)
            {
                _gfs_job_running_id = job->id;

                _gfs_job_running = job;

                job->state = FS_JOB_STATE_RUNNING;

                fs_job_check_job_list(job);  // The job's buffer should be unique among the list
            }
        }
    }

    fs_lock_free_mutex(_gfs_lock_common);

    fs_util_trace_info1(TRACE_FUNC, FS_API_FS_ASYNC_JOB_GET_FIRST_E, (kal_uint32)job, NULL);

    return job;
}

void fs_job_insert(fs_job_struct *t)
{
    fs_job_struct *q;
    fs_job_struct *parent = NULL;

    fs_util_trace_info2(TRACE_FUNC, FS_API_FS_ASYNC_JOB_INSERT_S, (kal_uint32)t->id, (kal_uint32)t, NULL);

    fs_lock_get_mutex(_gfs_lock_common, FS_INFINITE);
    fs_job_check_job_list(t);

    // First job in the list
    if (NULL == _gfs_job_list)
    {
        _gfs_job_list = t;
        t->next = NULL;
    }
    else
    {
        q = _gfs_job_list;

        while (q)
        {
            if (t->priority < q->priority)  // comparing index: priority
            {
                // insert t before q

                t->next = q;

                if (q == _gfs_job_list) // become a new head
                {
                    _gfs_job_list = t;
                }
                else                    // not a new head
                {
                    parent->next = t;

                    t->next = q;
                }

                fs_lock_free_mutex(_gfs_lock_common);

                return;
            }

            parent = q;     // remember parent

            q = q->next;    // go to next node
        }

        parent->next = t;   // append to the end of job queue
    }

    fs_job_check_job_list(NULL);
    fs_lock_free_mutex(_gfs_lock_common);

    fs_util_trace_info0(TRACE_FUNC, FS_API_FS_ASYNC_JOB_INSERT_E, NULL);
}

fs_job_struct* fs_job_remove(fs_job_id id)
{
    fs_job_struct *q;
    fs_job_struct *parent  = NULL;

    fs_util_trace_info1(TRACE_FUNC, FS_API_FS_ASYNC_JOB_REMOVE_S, (kal_uint32)id, NULL);

    fs_lock_get_mutex(_gfs_lock_common, FS_INFINITE);
    fs_job_check_job_list(NULL);

    q = _gfs_job_list;

    while (q)
    {
        if (id == q->id)
        {
            if (NULL == parent)     // target is exactly the head
            {
                _gfs_job_list = q->next;
            }
            else                    // target is not the head
            {
                parent->next = q->next;
            }

            break;
        }

        parent = q;     // remember parent

        q = q->next;    // go to next node
    }

    fs_job_check_job_list(q);
    fs_lock_free_mutex(_gfs_lock_common);

    fs_util_trace_info1(TRACE_FUNC, FS_API_FS_ASYNC_JOB_REMOVE_E, (kal_uint32)q, NULL);

    return q;   // if not found, q will be NULL
}

kal_bool fs_job_register_fh(FS_File *f)
{
    if ((_gfs_task_id != NULL) && (kal_get_current_thread_ID() == _gfs_task_id))    // check NULL _gfs_task_id for FS_SanityCheck
    {
        // Note: If the job state is alread aborting, the file handle will be discarded
        if (_gfs_job_running->state == FS_JOB_STATE_ABORTING)
        {
            return KAL_FALSE;
        }
        else
        {
            f->Job   = _gfs_job_running_id;
        }
    }

    return KAL_TRUE;
}

void fs_job_response(fs_job_struct *job)
{
    fs_job_rsp_struct   *rsp;
    module_type         src_id;
    msg_type            msg_id;

    //-- 1. Send message or callback only

    // Sending ILM when done, the user have to use fs_async_msg_handler() to execute the callback function.
    if (job->response_flag != FS_RESPONSE_CALLBACK)
    {
        fs_util_trace_info4(TRACE_FUNC, FS_API_FS_ASYNC_JOB_RESPONSE_ILM, (kal_uint32)job->id, (kal_uint32)job, (kal_uint32)job->state, (kal_uint32)job->api, NULL);

        msg_id = fs_job_api_to_msgid(job->api);

        src_id = kal_get_active_module_id();

        // construct local parameter
        rsp = (fs_job_rsp_struct*)construct_local_para(sizeof(fs_job_rsp_struct), TD_RESET);
        rsp->job    = job;

        msg_send5(src_id, job->mod_id, FS_SAP, (msg_type)msg_id, (local_para_struct*)rsp);
    }

    // Calling Call Back Function directedly without sending ILM.
    else    // callback only
    {
        // TODO: Need to consider aborted case
        fs_util_trace_info4(TRACE_FUNC, FS_API_FS_ASYNC_JOB_RESPONSE_CBF, (kal_uint32)job->id, (kal_uint32)job, (kal_uint32)job->state, (kal_uint32)job->api, NULL);

        if (job->callback)
        {
            job->callback(job->id, job->result, (fs_async_callback_data_struct*)job);
        }
    }

    //-- 2. Adjust FS task's priority if required

     // get next job
    job = fs_job_get_first(FS_TASK_JOB_GETFIRST_WATCH);

    if (job != NULL)
    {
        // set ENFORCE_LOW flag for case that next job's priority is lower than current job's priority
        fs_task_priority_change(job->priority, FS_TASK_PRIORITY_CHANGE_ENFORCE_LOW);
    }
    else
    {
        // job queue is empty, reset FS task's priority
        fs_task_priority_change(_gfs_task_default_priority - 1, FS_TASK_PRIORITY_CHANGE_ENFORCE_LOW);
    }

}

fs_job_struct* fs_job_search(fs_job_id id)
{
    fs_job_struct   *job = NULL;

    fs_lock_get_mutex(_gfs_lock_common, FS_INFINITE);

    if (_gfs_job_list == NULL)
    {
        job = NULL;
    }
    else
    {
        job = _gfs_job_list;

        while (job)
        {
            if (job->id == id)
            {
                break;
            }

            job = job->next;
        }
    }

    fs_lock_free_mutex(_gfs_lock_common);

    return job;
}

/**
 * Change FS task's priority
 *
 * @par Catagory:
 * File System Task
 *
 * @param[in] new_priorty
 * @param[in] flag
 *
 *  FS_TASK_PRIORITY_CHANGE_DEFAULT     : Only raise FS task's priority is acceptable.
 *  FS_TASK_PRIORITY_CHANGE_ENFORCE_LOW : Enforce to lower FS task's priority if new_priority is lower than FS task's current priority
 *
 */
void fs_task_priority_change(kal_uint32 new_priority, kal_uint32 flag)
{
#if 0
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
}

#elif defined(__FS_ASYNC_SUPPORT_ALONE__)

#include "rtfiles.h"    // for _gfs_tls[]

/*--------------------------------------------------------
 *   Internal API Declarations (Alone Version)
 *--------------------------------------------------------*/
kal_bool fs_job_abort_ex(fs_job_id job_id, void *buf)
{
    if (job_id <= 0) return KAL_FALSE;  // job id 0 is invalid! (to avoid setting ALL file handles as FS_FH_ABORTED!)
    return KAL_TRUE;
}

kal_bool fs_job_abort(fs_job_id job_id)
{
    return fs_job_abort_ex(job_id, NULL);
}

kal_int32 fs_job_alloc_id(fs_job_id *id)
{
    //-- allocate Job ID

    fs_lock_get_mutex(_gfs_lock_common, FS_INFINITE);

    *id = _gfs_job_id;

    _gfs_job_id = (_gfs_job_id + 1) & FS_JOB_ID_MAX;

    if (_gfs_job_id == 0)
    {
        _gfs_job_id = 1;
    }

    fs_lock_free_mutex(_gfs_lock_common);

    return FS_NO_ERROR;
}

kal_bool fs_job_register_fh(FS_File *f)
{
    kal_uint32 tls_idx;

    tls_idx = fs_conf_get_tls_idx();

    if (_gfs_tls[tls_idx].current_job != 0)
    {
        if (_gfs_tls[tls_idx].aborted == KAL_TRUE)
        {
            return KAL_FALSE;
        }
        else
        {
            f->Job = _gfs_tls[tls_idx].current_job;
        }
    }

    return KAL_TRUE;
}

#endif  // __FS_ASYNC_SUPPORT__

/**
 * Transform ILM message to FS job and insert job to job list
 *
 * @par Catagory:
 * File System Task
 *
 * @param[in] ilm
 *
 * @return
 *  KAL_TRUE    : Job is successfully inserted to job list.
 *  KAL_FALSE   : Invalid message for FS task
 */
void fs_task_msg_handler(ilm_struct *ilm)
{
    /*----------------------------------------
     * Local variables
     *----------------------------------------*/
#if defined(__FS_BENCHMARK__)
    tst_module_string_inject_struct *tst_inject;
#endif

#if defined(__FS_ASYNC_SUPPORT_TASK__)
    fs_job_req_struct               *req;
#endif

    /*----------------------------------------
     * Function body
     *----------------------------------------*/

#if defined(__FS_ASYNC_SUPPORT_TASK__)

    req = (fs_job_req_struct*)(ilm->local_para_ptr);

    if (ilm->sap_id == FS_SAP)  // FS specified message
    {
        if (FS_JOB_TYPE_ASYNC_API == req->type)
        {
           fs_job_insert(req->job);
        }
        else
        {
            // no action is required
        }
    }
    else
#endif // __FS_ASYNC_SUPPORT_TASK__
    {
        /*
         * NOT FS spedified message, handle it immediately!
         * Do not use JOB concept because JOB mechanism may reject request due to resource insufficiency.
         */

        if (ilm->msg_id == MSG_ID_TST_INJECT_STRING)
        {
#if defined(__FS_BENCHMARK__)
            tst_inject = (tst_module_string_inject_struct*)ilm->local_para_ptr;
#endif

            //-- FS iteration profiling tool (Under construction)

#if defined(__FS_BENCHMARK__)

#if defined(__SQLITE3_TEST_BED__)

            //-- Smart file seeker's SQLite test bed

            if (strcmp((kal_char*)tst_inject->string, "fsq@") == 0)
            {
                fs_test_db_sqlite();
            }

#endif // __SQLITE3_TEST_BED__

#if defined(__FS_DEDICATED_BUFFER__)

            //-- File system benchmark

            if (strncmp((kal_char*)tst_inject->string, "fsb@", 4) == 0)
            {
                if (strlen((kal_char*)tst_inject->string) <= 16)
                {
                    tst_sys_trace(&((kal_char*)tst_inject->string)[4]);

                    fs_bench(tst_inject->index, &((kal_uint8*)tst_inject->string)[4]);
                }
            }
            else if (strncmp((kal_char*)tst_inject->string, "ft", 2) == 0) {
                fs_util_trace_print_file_table(kal_trace, TRACE_ERROR);
            }
            else if (strncmp((kal_char*)tst_inject->string, "fh", 2) == 0) {
                fs_util_trace_print_file_hanlde_consumer(kal_trace, TRACE_ERROR);
            }

#endif // __FS_DEDICATED_BUFFER__

#endif // __FS_BENCHMARK__
        }
    }
}

kal_bool fs_task_init(void)
{

#if 0
#if defined(__FS_ASYNC_SUPPORT_TASK__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  // __FS_ASYNC_SUPPORT_TASK__
#endif

    return KAL_TRUE;
}

void fs_task_main(task_entry_struct *task_entry_ptr)
{
    ilm_struct ilm;
#if defined(__FS_ASYNC_SUPPORT_TASK__)
    kal_uint32 msg_cnt;
#endif

    kal_set_active_module_id(MOD_FS);

#if defined(__FS_ASYNC_SUPPORT_TASK__)

    _gfs_task_id = kal_get_current_thread_ID();

#endif

    while (1)
    {
#if defined(__FS_ASYNC_SUPPORT_TASK__)
        while (1)
        {
            msg_cnt= msg_get_extq_messages();  // query pending messages

            if (msg_cnt)
            {
                if (msg_receive_extq(&ilm) == KAL_TRUE)
                    fs_task_msg_handler(&ilm);  // transform ILM message to FS job and insert job to job list

                destroy_ilm(&ilm);

                // continue while-loop to receive other messages
            }
            else // no message queued
            {
                if (_gfs_job_list == NULL)
                {
                    if (msg_receive_extq(&ilm) == KAL_TRUE)
                        fs_task_msg_handler(&ilm);  // transform ILM message to FS job and insert job to job list

                    destroy_ilm(&ilm);

                    // continue while-loop to see if there is any other message queued
                }
                else // job list is NOT empty, break message checker to do one job
                {
                    break;
                }
            }
        }

        fs_job_dispatcher();

#else   // !__FS_ASYNC_SUPPORT_TASK__

        if (msg_receive_extq(&ilm) == KAL_TRUE)
            fs_task_msg_handler(&ilm);  // transform ILM message to FS job and insert job to job list

        destroy_ilm(&ilm);

#endif  // __FS_ASYNC_SUPPORT_TASK__
    }
}

kal_bool fst_create(comptask_handler_struct **handle)
{
    static const comptask_handler_struct fs_handler_info =
    {
        fs_task_main,             /* task entry function */
        fs_task_init,             /* task initialization function */
        NULL                     /* task reset handler */
    };

    *handle = (comptask_handler_struct *)&fs_handler_info;
    return KAL_TRUE;
}



