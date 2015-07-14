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
 *   fs_sst.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file provides MTK file system SST (System Stability Tracker) facility.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#if !defined(__UBL__)

/*-----------------------------------
 * Included Header Files
 *-----------------------------------*/

#include "kal_general_types.h"
#include "fs_internal_def.h"
#include "fs_gprot.h"
#include "fs_trc.h"
#include "fs_kal.h"
#include "fs_utility.h"

/*-----------------------------------
 * Definitions
 *-----------------------------------*/

#define FS_ERR_CODE1_MASK   (0xFF)  // should be the same as ERROR_CODE1_MASK_SECOND in SST_utility.h

/*-----------------------------------
 * Global Variables
 *-----------------------------------*/

/*-----------------------------------
 * Funciton Bodies
 *-----------------------------------*/
void fs_sst_normal_error_handler(kal_int32 code1, kal_int32 code2)
{
    // print title
    kal_assert_trace(TRACE_ERROR, FS_SST_USER_ERROR_TITLE);

    switch (code2)
    {
        case FS_ERR_HANDLE_01:
            #if defined(__TST_TRACE_ENABLED__)
            fs_util_trace_print_file_table(kal_assert_trace, TRACE_ERROR);
            fs_util_trace_print_file_hanlde_consumer(kal_assert_trace, TRACE_ERROR);
            #endif
            break;

        case FS_ERR_API_CLOSE_ALL:
            kal_assert_trace(TRACE_ERROR, FS_SST_API_CLOSE_ALL);
            break;

        default:
            break;
    }
}

void fs_sst_internal_error_handler(kal_int32 code1, kal_int32 code2)
{
    // print title
    kal_assert_trace(TRACE_ERROR, FS_SST_INTERNAL_ERROR_TITLE);

    switch (code2)
    {
        case FS_ERR_ASSERT:
            fs_util_trace_print_assert_info(_gfs_err_assert_file, _gfs_err_assert_line,
                                            _gfs_err_assert_param[0], _gfs_err_assert_param[1], _gfs_err_assert_param[2]);
            break;

        case FS_ERR_BUFFER_02:
            #if defined(__TST_TRACE_ENABLED__)
            fs_util_trace_print_file_table(kal_assert_trace, TRACE_ERROR);
            #endif
            break;

        case FS_ERR_CLUSTER_01:
            kal_assert_trace(TRACE_ERROR, FS_SST_CLUSTER_01, (kal_uint32)_gfs_err_info);
            break;

        case FS_ERR_CLUSTER_03:
            kal_assert_trace(TRACE_ERROR, FS_SST_CLUSTER_03, (kal_uint32)_gfs_err_info);
            break;

        case FS_ERR_CLUSTER_05:
            kal_assert_trace(TRACE_ERROR, FS_SST_CLUSTER_05, (kal_uint32)_gfs_err_info);
            break;

        case FS_ERR_CLUSTER_06:
            kal_assert_trace(TRACE_ERROR, FS_SST_CLUSTER_06, (kal_uint32)_gfs_err_info);
            break;

        case FS_ERR_DIRENTRY_01:
            kal_assert_trace(TRACE_ERROR, FS_SST_DIRENTRY_01);
            break;

        case FS_ERR_EXCEPTION_04:
            kal_assert_trace(TRACE_ERROR, FS_SST_EXCEPTION_04);
            break;

        case FS_ERR_TLS_02:
            kal_assert_trace(TRACE_ERROR, FS_SST_TLS_02, (kal_uint32)_gfs_err_info);
            break;

        case FS_ERR_MUTEX_01:
            kal_assert_trace(TRACE_ERROR, FS_SST_MUTEX_01, (kal_uint32)_gfs_err_info);
            break;

        default:
            break;
    }
}

void fs_sst_entry(kal_int32 code1, kal_int32 code2)
{
    if (code1 == (FS_ERR_USER_ERROR & FS_ERR_CODE1_MASK))
    {
        fs_sst_normal_error_handler(code2, code2);
    }
    else if (code1 == (FS_ERR_INTERNAL_ERROR & FS_ERR_CODE1_MASK))
    {
        fs_sst_internal_error_handler(code2, code2);
    }
}

#else   // __UBL__

void fs_sst_entry(kal_int32 code1, kal_int32 code2)
{
    return;
}

#endif  // !__UBL__

