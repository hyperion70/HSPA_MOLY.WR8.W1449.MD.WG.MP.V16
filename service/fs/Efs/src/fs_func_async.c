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
 *   fs_func_async.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file provides MTK file system internal definitions.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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

#if !defined(__SMART_PHONE_MODEM__)

#include "kal_general_types.h"
#include "fs_internal_def.h"
#include "fs_gprot.h"
#include "fs_kal.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"       // for module_type
#include "kal_public_api.h" //MSBB change #include "kal_release.h"        // for stack lib
#include "fs_internal_api.h"    // for FS lib
#include "fs_task.h"            // for JOB ID bitmap...etc.
#include "cache_sw.h"           // (strange!) without this, 10A.W10.50 will be failed because CPU_CACHE_LINE_SIZE is undefined ..
#include "fs_trc.h"
#include "fs_utility.h"
#include "svc_sap.h"

#define fs_assert_local(expr) fs_assert(expr, fs_func_async_c)
#define fs_ext_assert_local(expr, e1, e2, e3) fs_ext_assert(expr, fs_func_async_c, e1, e2, e3)
#define fs_util_trace_err_noinfo(error_code) fs_util_trace_err(NULL, error_code, fs_func_async_c, __LINE__, NULL)

#if defined(__FS_ASYNC_SUPPORT_TASK__)

extern fs_job_id       _gfs_job_running_id;
extern fs_job_struct   *_gfs_job_running;
extern kal_bool fs_job_check_job_list(fs_job_struct *exist_job);
extern void fs_job_check_job_list_dump(void);

//----------------------------------
//   Internal API Declarations
//----------------------------------

static kal_int32   fs_async_int_initialize_job(fs_job_struct **job, fs_overlapped_struct *overlapped);
static void        fs_async_int_register_job(fs_job_struct *job, kal_uint32 msg_id);
static void        fs_async_int_send_msg(kal_int32 msg_id, void *local_para_ptr);

#define FS_ASYNC_INTERNAL_API

static void fs_async_int_send_msg(kal_int32 msg_id, void *local_para_ptr)
{
    module_type src_id;

    src_id = kal_get_active_module_id();

    msg_send5(src_id, MOD_FS, FS_SAP, (msg_type)msg_id, (local_para_struct*)local_para_ptr);
}

static kal_int32 fs_async_int_initialize_job(fs_job_struct **job, fs_overlapped_struct *overlapped)
{
    fs_job_id       id;
    fs_job_struct   *j;
    kal_int32       result;

    // request a Job ID (valid value is > 0)
    if ((result = fs_job_alloc_id(&id, overlapped)) < 0)
    {
        return result;
    }

    j = *job = overlapped->buf; // job memory comes from user

    j->id       = id;
    j->state    = FS_JOB_STATE_NOT_STARTED;
    j->response_flag = overlapped->response_flag;
    j->callback = overlapped->callback;
    j->param    = overlapped->param;
    j->result   = FS_ABORTED_ERROR;
    j->mod_id   = kal_get_active_module_id();
    j->next     = NULL;

    if (overlapped->priority == FS_PRIORITY_DEFAULT)
        j->priority = _gfs_task_default_priority;
    else if (overlapped->priority == FS_PRIORITY_INHERITED)
        j->priority = kal_get_current_task_priority();
    else if (overlapped->priority == FS_PRIORITY_ASSIGN)
        j->priority = overlapped->priority_value - 1;
    else
        return FS_PARAM_ERROR; // invalid priority

    return (kal_int32)id;
}

static void fs_async_int_register_job(fs_job_struct *job, kal_uint32 msg_id)
{
    fs_job_req_struct   *req;

    // construct local parameter
    req = (fs_job_req_struct*)construct_local_para(sizeof(fs_job_req_struct), TD_RESET);
    req->job    = job;
    req->type   = FS_JOB_TYPE_ASYNC_API;
    job->next   = NULL;

    // adjust FS task's priority
    fs_task_priority_change(job->priority, FS_TASK_PRIORITY_CHANGE_DEFAULT);

    fs_util_trace_info4(TRACE_FUNC, FS_API_FS_ASYNC_JOB_REGISTER, (kal_uint32)job->id, (kal_uint32)job, (kal_uint32)job->state, (kal_uint32)job->api, NULL);
    fs_job_check_job_list(job);
    if (job==_gfs_job_running)  {
        fs_util_trace_info1(TRACE_ERROR, FS_API_FS_ASYNC_JOB_LIST_ERROR_JOBPTR_RUNNING, (kal_uint32)job, NULL);
        fs_job_check_job_list_dump();
        fs_assert_local(0);
    }

    // send message to FS task
    fs_async_int_send_msg(msg_id, (void *)req);
}

#define FS_ASYNC_EXPORTED_API

kal_int32 fs_async_abort_ex(fs_job_id job_id, void *buf)
{
    fs_job_abort_struct *job=(fs_job_abort_struct*)buf;

    fs_util_trace_info1(TRACE_FUNC, FS_API_FS_ASYNC_ABORT_S, job_id, NULL);

    if (job_id <= 0)    {
        fs_util_trace_err_noinfo(FS_ERR_INVALID_JOB_ID);
        return FS_ERR_INVALID_JOB_ID;
    }

    if (job!=NULL)  {
        if (job_id!=job->id)    {
            return FS_ERR_INVALID_JOB_ID;
        }
    }

    if (fs_job_abort_ex(job_id, buf)==KAL_TRUE) {
        return FS_NO_ERROR;
    }

    return FS_ERR_ASYNC_JOB_NOT_FOUND;
}

kal_int32 fs_async_abort(fs_job_id job_id)
{
    return fs_async_abort_ex(job_id, NULL);
}

kal_int32 fs_async_delete(const kal_wchar* filename, fs_overlapped_struct *overlapped)
{
    kal_int32               id;
    fs_job_delete_struct    *job;

    fs_util_trace_info1(TRACE_FUNC | MT_TRACE_INFO_WSTR, FS_API_FS_ASYNC_DELETE_S, overlapped->priority, (void*)filename);

    // initialize job
    if ((id = fs_async_int_initialize_job((fs_job_struct**)(&job), overlapped)) < 0)
    {
        return id;
    }

    // pack parameters (specific to this API itself)
    job->filename = filename;

    // pack essential job information (specific to this API itself)
    job->api        = FS_API_DELETE;

    // register this job to FS task
    fs_async_int_register_job((fs_job_struct*)job, MSG_ID_FS_DELETE_REQ);

    fs_util_trace_info1(TRACE_FUNC, FS_API_FS_ASYNC_DELETE_E, id, NULL);

    return id;
}

kal_int32 fs_async_find_first(const kal_wchar *name_pattern,
                              kal_uint8 attr, kal_uint8 attr_mask,
                              FS_DOSDirEntry *file_info, kal_wchar *file_name, kal_uint32 max_length,
                              fs_overlapped_struct *overlapped)
{
    kal_int32                   id;
    fs_job_find_first_struct    *job;

    fs_util_trace_info4(TRACE_FUNC | MT_TRACE_INFO_WSTR, FS_API_FS_ASYNC_FINDFIRST_S, overlapped->priority, attr, attr_mask, max_length, (void*)name_pattern);

    // initialize job
    if ((id = fs_async_int_initialize_job((fs_job_struct**)(&job), overlapped)) < 0)
    {
        return id;
    }

    // pack parameters (specific to this API itself)
    job->name_pattern   = (kal_wchar*)name_pattern;
    job->attr           = attr;
    job->attr_mask      = attr_mask;
    job->file_info      = file_info;
    job->file_name      = file_name;
    job->max_length     = max_length;

    // pack essential job information (specific to this API itself)
    job->api        = FS_API_FINDFIRST;

    // register this job to FS task
    fs_async_int_register_job((fs_job_struct*)job, MSG_ID_FS_FIND_FIRST_REQ);

    fs_util_trace_info1(TRACE_FUNC, FS_API_FS_ASYNC_FINDFIRST_E, id, NULL);

    return id;
}

kal_int32 fs_async_find_first_n(const kal_wchar *name_pattern,
                                FS_Pattern_Struct * pattern_array, kal_uint32 pattern_num,
                                kal_uint8 array_mask, kal_uint8 attr, kal_uint8 attr_mask,
                                FS_DOSDirEntry *file_info, kal_wchar *file_name, kal_uint32 max_length,
                                kal_uint32 entry_index, kal_uint32 flag, fs_overlapped_struct *overlapped)
{
    kal_int32                   id;
    fs_job_find_first_n_struct  *job;

    fs_util_trace_info4(TRACE_FUNC | MT_TRACE_INFO_WSTR, FS_API_FS_ASYNC_FINDFIRSTN_S, overlapped->priority, max_length, entry_index, flag, (void*)name_pattern);

    // initialize job
    if ((id = fs_async_int_initialize_job((fs_job_struct**)(&job), overlapped)) < 0)
    {
        return id;
    }

    // pack parameters (specific to this API itself)
    job->name_pattern   = (kal_wchar*)name_pattern;
    job->pattern_array  = pattern_array;
    job->pattern_num    = pattern_num;
    job->array_mask     = array_mask;
    job->attr           = attr;
    job->attr_mask      = attr_mask;
    job->file_info      = file_info;
    job->file_name      = file_name;
    job->max_length     = max_length;
    job->entry_index    = entry_index;
    job->flag           = flag;

    // pack essential job information (specific to this API itself)
    job->api        = FS_API_FINDFIRSTN;

    // register this job to FS task
    fs_async_int_register_job((fs_job_struct*)job, MSG_ID_FS_FIND_FIRST_N_REQ);

    fs_util_trace_info1(TRACE_FUNC, FS_API_FS_ASYNC_FINDFIRSTN_E, id, NULL);

    return id;
}

kal_int32 fs_async_get_folder_size(const kal_wchar* path, kal_int32 flag, void* recursive_stack, kal_uint32 stack_size, FS_ProgressCallback progress, fs_overlapped_struct *overlapped)
{
    kal_int32                       id;
    fs_job_get_folder_size_struct   *job;

    fs_util_trace_info4(TRACE_FUNC | MT_TRACE_INFO_WSTR, FS_API_FS_ASYNC_GETFOLDERSIZE_S, overlapped->priority, flag, (kal_uint32)recursive_stack, stack_size, (void*)path);

    // initialize job
    if ((id = fs_async_int_initialize_job((fs_job_struct**)(&job), overlapped)) < 0)
    {
        return id;
    }

    // pack parameters (specific to this API itself)
    job->path               = (kal_wchar*)path;
    job->flag               = flag;
    job->recursive_stack    = recursive_stack;
    job->stack_size         = stack_size;
    job->progress           = progress;

    // pack essential job information (specific to this API itself)
    job->api                = FS_API_GETFOLDERSIZE;

    // register this job to FS task
    fs_async_int_register_job((fs_job_struct*)job, MSG_ID_FS_GET_FOLDER_SIZE_REQ);

    fs_util_trace_info1(TRACE_FUNC, FS_API_FS_ASYNC_GETFOLDERSIZE_E, id, NULL);

    return id;
}

void fs_async_msg_handler(local_para_struct *local_para)
{
    fs_job_struct   *job;
    FS_File         *f;

    job = ((fs_job_rsp_struct*)local_para)->job;

    /*
     * Check if user abort the job after job is finished.
     * If yes, for opening file case, close its file handle.
     */

    if (job->api == FS_API_OPEN ||
        job->api == FS_API_FINDFIRST ||
        job->api == FS_API_FINDFIRSTN)
    {
        if (job->result > FS_NO_ERROR)  // result should be valid file handle
        {
            f = fs_conf_get_file_by_fh(job->result);

            if (f != NULL)
            {
                f->Job = 0;     // clear connection of file handle and job ID to prevent being aborted incorrectly in the future.

                if (f->Valid == FS_FH_ABORTED)      // f->Valid may be set as FS_FH_ABORTED in fs_async_abort
                {
                    if (job->api == FS_API_OPEN)    // FS_OPEN
                    {
                        FS_Close(job->result);
                    }
                    else                            // FS_FindFirst(N)
                    {
                        FS_FindClose(job->result);
                    }

                    job->result = FS_ABORTED_ERROR;
                }
            }
        }
    }

    // call callback
    if (job->callback)
    {
        job->callback(job->id, job->result, (fs_async_callback_data_struct*)job);
    }

    /*
     * 1. Job ID: For unique integer mechanism, job ID is not required to be released.
     * 2. Job memory: Job memory address (job) is notified by callback and should be released by user itself.
     * 3. ILM memory: Ilm memory should be released by user task itself.
     */
}

kal_int32 fs_async_open(const kal_wchar *filename, kal_int32 flag, fs_overlapped_struct *overlapped)
{
    kal_uint32          lr;
    kal_int32           id;
    fs_job_open_struct  *job;

    FS_GET_RETURN_ADDRESS(lr);

    fs_util_trace_info2(TRACE_FUNC | MT_TRACE_INFO_WSTR, FS_API_FS_ASYNC_OPEN_S, overlapped->priority, flag, (void*)filename);

    // initialize job
    if ((id = fs_async_int_initialize_job((fs_job_struct**)(&job), overlapped)) < 0)
    {
        return id;
    }

    // pack parameters (specific to this API itself)
    job->filename = (kal_wchar*)filename;
    job->flag     = flag;
    job->caller_address = lr;

    // pack essential job information (specific to this API itself)
    job->api      = FS_API_OPEN;

    // register this job to FS task
    fs_async_int_register_job((fs_job_struct*)job, MSG_ID_FS_OPEN_REQ);

    fs_util_trace_info1(TRACE_FUNC, FS_API_FS_ASYNC_OPEN_E, id, NULL);

    return id;
}


// TODO:
kal_int32 fs_async_read(FS_HANDLE handle, void *data, kal_uint32 length, kal_uint32 *read, fs_overlapped_struct *overlapped)
{
    return fs_async_read_interleave(handle, data, length, read, 0, overlapped);
}

kal_int32 fs_async_read_interleave(FS_HANDLE handle, void *data, kal_uint32 length, kal_uint32 *read, kal_uint32 chunksize, fs_overlapped_struct *overlapped)
{
    kal_int32           id;
    fs_job_read_struct  *job;

    fs_util_trace_info4(TRACE_FUNC | MT_TRACE_INFO_FILE, FS_API_FS_ASYNC_READ_S, overlapped->priority, handle, (kal_uint32)data, length, (void*)fs_conf_get_file_by_fh(handle));

    // initialize job
    if ((id = fs_async_int_initialize_job((fs_job_struct**)(&job), overlapped)) < 0)
    {
        return id;
    }

    // pack parameters (specific to this API itself)
    job->handle     = handle;
    job->data       = data;
    job->length     = length;
    job->read       = read;
    job->chunksize  = chunksize;

    // pack essential job information (specific to this API itself)
    job->api        = FS_API_READ;

    // register this job to FS task
    fs_async_int_register_job((fs_job_struct*)job, MSG_ID_FS_READ_REQ);

    fs_util_trace_info1(TRACE_FUNC, FS_API_FS_ASYNC_READ_E, id, NULL);

    return id;
}

kal_int32 fs_async_seek(FS_HANDLE handle, kal_int64 offset, kal_int32 whence, fs_overlapped_struct *overlapped)
{
    kal_int32           id;
    fs_job_seek_struct  *job;

    fs_util_trace_info4(TRACE_FUNC | MT_TRACE_INFO_FILE, FS_API_FS_ASYNC_SEEK_S, overlapped->priority, (kal_uint32)handle, offset, whence, NULL);

    // initialize job
    if ((id = fs_async_int_initialize_job((fs_job_struct**)(&job), overlapped)) < 0)
    {
        return id;
    }

    // pack parameters (specific to this API itself)
    job->handle     = handle;
    job->offset     = offset;
    job->whence     = whence;

    // pack essential job information (specific to this API itself)
    job->api        = FS_API_SEEK;

    // register this job to FS task
    fs_async_int_register_job((fs_job_struct*)job, MSG_ID_FS_SEEK_REQ);

    fs_util_trace_info1(TRACE_FUNC, FS_API_FS_ASYNC_SEEK_E, id, NULL);

    return id;
}

kal_int32 fs_async_write(FS_HANDLE handle, void *data, kal_uint32 length, kal_uint32 *written, fs_overlapped_struct *overlapped)
{
    kal_int32               id;
    fs_job_write_struct     *job;

    fs_util_trace_info4(TRACE_FUNC | MT_TRACE_INFO_FILE, FS_API_FS_ASYNC_WRITE_S, overlapped->priority, handle, (UINT)data, length, (void*)fs_conf_get_file_by_fh(handle));

    // initialize job
    if ((id = fs_async_int_initialize_job((fs_job_struct**)(&job), overlapped)) < 0)
    {
        return id;
    }

    // pack parameters (specific to this API itself)
    job->handle     = handle;
    job->data       = data;
    job->length     = length;
    job->written    = written;

    // pack essential job information (specific to this API itself)
    job->api        = FS_API_WRITE;

    // register this job to FS task
    fs_async_int_register_job((fs_job_struct*)job, MSG_ID_FS_WRITE_REQ);

    fs_util_trace_info1(TRACE_FUNC, FS_API_FS_ASYNC_WRITE_E, id, NULL);

    return id;
}

#elif defined(__FS_ASYNC_SUPPORT_ALONE__)

#include "rtfiles.h"    // for _gfs_tls[]

static kal_int32 fs_async_int_initialize_job(void);

#define FS_ASYNC_ALONE_INTERNAL_API

static kal_int32 fs_async_int_initialize_job(void)
{
    fs_job_id       id;
    kal_int32       result;

    // request a Job ID (valid value is > 0)
    if ((result = fs_job_alloc_id(&id)) < 0)
    {
        return result;
    }

    result = (kal_int32)fs_conf_get_tls_idx();

    _gfs_tls[result].current_job = id;
    _gfs_tls[result].aborted     = KAL_FALSE;

    return (kal_int32)id;
}

void fs_async_int_response(fs_job_id id, fs_api_enum api, kal_int64 result, fs_overlapped_struct *overlapped)
{
    fs_job_alone_rsp_struct         *rsp;
    fs_async_callback_data_struct   *data;
    module_type                     src_id;
    msg_type                        msg_id;
    kal_uint32                      tls_idx;

    tls_idx = fs_conf_get_tls_idx();

    _gfs_tls[tls_idx].current_job = 0;
    _gfs_tls[tls_idx].aborted     = KAL_FALSE;

    // Sending ILM when done, the user have to use fs_async_msg_handler() to execute the callback function.
    if (overlapped->response_flag != FS_RESPONSE_CALLBACK)
    {
        msg_id = fs_job_api_to_msgid(api);

        src_id = kal_get_active_module_id();

        // construct local parameter
        rsp = (fs_job_alone_rsp_struct*)construct_local_para(sizeof(fs_job_alone_rsp_struct), TD_RESET);

        // fill-in essential async related information
        data = rsp->data = (fs_async_callback_data_struct*)(overlapped->buf);
        data->api       = api;
        data->id        = id;
        data->result    = result;
        data->callback  = overlapped->callback;
        data->param     = overlapped->param;

        msg_send5(src_id, src_id, FS_SAP, (msg_type)msg_id, (local_para_struct*)rsp);
    }
    // Calling Call Back Function directedly without sending ILM.
    else
    {
        data = (fs_async_callback_data_struct*)(overlapped->buf);

        data->api       = api;
        data->id        = id;
        data->result    = result;
        data->callback  = overlapped->callback;
        data->param     = overlapped->param;

        if (overlapped->callback)
        {
            overlapped->callback(id, result, data);
        }
    }
}

#define FS_ASYNC_ALONE_EXPORTED_API

/*
 * FS task is NOT supported
 *      1. Execute FS API directly by blocking way in requester's context.
 *      2. Send message with result and callback to requester itself.
 */
kal_int32 fs_async_abort_ex(fs_job_id job_id, void *buf)
{
    fs_util_trace_info1(TRACE_FUNC, FS_API_FS_ASYNC_ABORT_S, job_id, NULL);

    if (job_id <= 0)    {
        return FS_ERR_INVALID_JOB_ID;
    }

    // check if target is running. If it is, set abort flag.
    fs_job_abort_ex(job_id, buf);

    return FS_NO_ERROR;
}

kal_int32 fs_async_abort(fs_job_id job_id)
{
    return fs_async_abort_ex(job_id, NULL);
}

kal_int32 fs_async_delete(const kal_wchar* filename, fs_overlapped_struct *overlapped)
{
    kal_int32   result;
    kal_int32   id;

    fs_util_trace_info1(TRACE_FUNC | MT_TRACE_INFO_WSTR, FS_API_FS_ASYNC_DELETE_S, overlapped->priority, (void*)filename);

    // initialize job (allocate JOB ID)
    if ((id = fs_async_int_initialize_job()) < 0)
    {
        return id;
    }

    result = FS_Delete(filename);

    fs_async_int_response(id, FS_API_DELETE, result, overlapped);

    fs_util_trace_info1(TRACE_FUNC, FS_API_FS_ASYNC_DELETE_E, id, NULL);

    return id;
}

kal_int32 fs_async_find_first(const kal_wchar *name_pattern,
                              kal_uint8 attr, kal_uint8 attr_mask,
                              FS_DOSDirEntry *file_info, kal_wchar *file_name, kal_uint32 max_length,
                              fs_overlapped_struct *overlapped)
{
    kal_int32   result;
    kal_int32   id;

    fs_util_trace_info4(TRACE_FUNC | MT_TRACE_INFO_WSTR, FS_API_FS_ASYNC_FINDFIRST_S, overlapped->priority, attr, attr_mask, max_length, (void*)name_pattern);

    // initialize job (allocate JOB ID)
    if ((id = fs_async_int_initialize_job()) < 0)
    {
        return id;
    }

    result = FS_FindFirst(name_pattern, attr, attr_mask, file_info, file_name, max_length);

    fs_async_int_response(id, FS_API_FINDFIRST, result, overlapped);

    fs_util_trace_info1(TRACE_FUNC, FS_API_FS_ASYNC_FINDFIRST_E, id, NULL);

    return id;
}

kal_int32 fs_async_find_first_n(const kal_wchar *name_pattern,
                                FS_Pattern_Struct * pattern_array, kal_uint32 pattern_num,
                                kal_uint8 array_mask, kal_uint8 attr, kal_uint8 attr_mask,
                                FS_DOSDirEntry *file_info, kal_wchar *file_name, kal_uint32 max_length,
                                kal_uint32 entry_index, kal_uint32 flag, fs_overlapped_struct *overlapped)
{
    kal_int32   result;
    kal_int32   id;

    fs_util_trace_info4(TRACE_FUNC | MT_TRACE_INFO_WSTR, FS_API_FS_ASYNC_FINDFIRSTN_S, overlapped->priority, max_length, entry_index, flag, (void*)name_pattern);

    // initialize job (allocate JOB ID)
    if ((id = fs_async_int_initialize_job()) < 0)
    {
        return id;
    }

    result = FS_FindFirstN(name_pattern, pattern_array, pattern_num, array_mask, attr, attr_mask, file_info, file_name, max_length, entry_index, flag);

    fs_async_int_response(id, FS_API_FINDFIRSTN, result, overlapped);

    fs_util_trace_info1(TRACE_FUNC, FS_API_FS_ASYNC_FINDFIRSTN_E, id, NULL);

    return id;
}

kal_int32 fs_async_get_folder_size(const kal_wchar* path, kal_int32 flag, void* recursive_stack, kal_uint32 stack_size, FS_ProgressCallback progress, fs_overlapped_struct *overlapped)
{
    kal_int32   result;
    kal_int32   id;

    fs_util_trace_info4(TRACE_FUNC | MT_TRACE_INFO_WSTR, FS_API_FS_ASYNC_GETFOLDERSIZE_S, overlapped->priority, flag, (kal_uint32)recursive_stack, stack_size, (void*)path);

    // initialize job (allocate JOB ID)
    if ((id = fs_async_int_initialize_job()) < 0)
    {
        return id;
    }

    result = FS_GetFolderSizeEx(path, flag, recursive_stack, stack_size, progress);

    fs_async_int_response(id, FS_API_GETFOLDERSIZE, result, overlapped);

    fs_util_trace_info1(TRACE_FUNC, FS_API_FS_ASYNC_GETFOLDERSIZE_E, id, NULL);

    return id;
}

void fs_async_msg_handler(local_para_struct *local_para)
{
    fs_async_callback_data_struct   *data;
    FS_File                         *f;

    data = ((fs_job_alone_rsp_struct*)local_para)->data;

    /*
     * Check if user abort the job after job is finished.
     * If yes, for opening file case, close its file handle.
     */

    if (data->api == FS_API_OPEN ||
        data->api == FS_API_FINDFIRST ||
        data->api == FS_API_FINDFIRSTN)
    {
        if (data->result > FS_NO_ERROR)  // result should be valid file handle
        {
            f = fs_conf_get_file_by_fh(data->result);

            if (f != NULL)
            {
                f->Job = 0;     // clear connection of file handle and job ID to prevent being aborted incorrectly in the future.

                if (f->Valid == FS_FH_ABORTED)      // f->Valid may be set as FS_FH_ABORTED in fs_async_abort
                {
                    if (data->api == FS_API_OPEN)   // FS_OPEN
                    {
                        FS_Close(data->result);
                    }
                    else                            // FS_FindFirst(N)
                    {
                        FS_FindClose(data->result);
                    }

                    data->result = FS_ABORTED_ERROR;
                }
            }
        }
    }

    // do callback
    if (data->callback)
    {
        data->callback(data->id, data->result, data);
    }

    /*
     * 1. Job ID: For unique integer mechanism, job ID is not required to be released.
     * 2. Job memory: Job memory address (data) is notified by callback and should be released by user itself.
     * 3. ILM memory: Ilm memory should be released by user task itself.
     */
}

kal_int32 fs_async_open(const kal_wchar *filename, kal_int32 flag, fs_overlapped_struct *overlapped)
{
    kal_uint32  lr;
    kal_int32   result;
    kal_int32   id;

    FS_GET_RETURN_ADDRESS(lr);

    fs_util_trace_info2(TRACE_FUNC | MT_TRACE_INFO_WSTR, FS_API_FS_ASYNC_OPEN_S, overlapped->priority, flag, (void*)filename);

    // initialize job (allocate JOB ID)
    if ((id = fs_async_int_initialize_job()) < 0)
    {
        return id;
    }

    result = FS_OpenLR(filename, flag, lr);

    fs_async_int_response(id, FS_API_OPEN, result, overlapped);

    fs_util_trace_info1(TRACE_FUNC, FS_API_FS_ASYNC_OPEN_E, id, NULL);

    return id;
}

kal_int32 fs_async_read(FS_HANDLE handle, void *data, kal_uint32 length, kal_uint32 *read, fs_overlapped_struct *overlapped)
{
    return fs_async_read_interleave(handle, data, length, read, 0, overlapped);
}

kal_int32 fs_async_read_interleave(FS_HANDLE handle, void *data, kal_uint32 length, kal_uint32 *read, kal_uint32 chunksize, fs_overlapped_struct *overlapped)
{
    kal_int32   id;
    kal_int32   result=0;
    kal_uint32  segment_length, segment_read;
    kal_uint8  *ptr;

    fs_util_trace_info4(TRACE_FUNC | MT_TRACE_INFO_FILE, FS_API_FS_ASYNC_READ_S, overlapped->priority, handle, (kal_uint32)data, length, (void*)fs_conf_get_file_by_fh(handle));

    // initialize job (allocate JOB ID)
    if ((id = fs_async_int_initialize_job()) < 0)
    {
        return id;
    }

    // The chunk is smaller than 32KB
    if (chunksize < (32)FS_KB) {
        result = FS_Read(handle ,data, length, read);
    }
    //
    else {
        ptr=data;
         if (read !=NULL)   {
             *read = 0;
         }
         while (length>0) {
             segment_length = (length > chunksize) ? chunksize : length;

             result = FS_Read(handle,
                              ptr,
                              segment_length,
                              &segment_read);

             if (result<0) break;

             if (read !=NULL)   {
                 *read += segment_read;
             }
             ptr       += segment_read;
             length    -= segment_read;
         }
     }

    fs_async_int_response(id, FS_API_READ, result, overlapped);

    fs_util_trace_info1(TRACE_FUNC, FS_API_FS_ASYNC_READ_E, id, NULL);

    return id;
}

kal_int32 fs_async_seek(FS_HANDLE handle, kal_int64 offset, kal_int32 whence, fs_overlapped_struct *overlapped)
{
    kal_int64   result;
    kal_int32   id;

    fs_util_trace_info4(TRACE_FUNC | MT_TRACE_INFO_FILE, FS_API_FS_ASYNC_SEEK_S, overlapped->priority, (kal_uint32)handle, offset, whence, NULL);

    // initialize job (allocate JOB ID)
    if ((id = fs_async_int_initialize_job()) < 0)
    {
        return id;
    }

    result = FS_SeekLargeFile(handle, offset, whence);

    fs_async_int_response(id, FS_API_SEEK, result, overlapped);

    fs_util_trace_info1(TRACE_FUNC, FS_API_FS_ASYNC_SEEK_E, id, NULL);

    return id;
}

kal_int32 fs_async_write(FS_HANDLE handle, void *data, kal_uint32 length, kal_uint32 *written, fs_overlapped_struct *overlapped)
{
    kal_int32   result;
    kal_int32   id;

    fs_util_trace_info4(TRACE_FUNC | MT_TRACE_INFO_FILE, FS_API_FS_ASYNC_WRITE_S, overlapped->priority, handle, (UINT)data, length, (void*)fs_conf_get_file_by_fh(handle));

    // initialize job (allocate JOB ID)
    if ((id = fs_async_int_initialize_job()) < 0)
    {
        return id;
    }

    result = FS_Write(handle ,data, length, written);

    fs_async_int_response(id, FS_API_WRITE, result, overlapped);

    fs_util_trace_info1(TRACE_FUNC, FS_API_FS_ASYNC_WRITE_E, id, NULL);

    return id;
}

#endif // __FS_ASYNC_SUPPORT_TASK__

#endif // !__SMART_PHONE_MODEM__
