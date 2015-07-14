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
 * tst_trace.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file defines the index trace of TST writer module.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _TST_TRACE_H
#define _TST_TRACE_H

#ifndef GEN_FOR_PC
#include "kal_public_defs.h" //MSBB change  #include "stack_config.h"
#endif /* GEN_FOR_PC */

#include "kal_trace.h"

#if !defined(GEN_FOR_PC)
#if defined(__TST_MODULE__) || defined(__CUSTOM_RELEASE__)
    #include "tst_trace_gen.h"
#endif /* TST Trace Defintion */
#endif
BEGIN_TRACE_MAP(MOD_TST)
   TRC_MSG(TST_MSG1, "System lost %d primtives and %d traces and %d EM datas")
   TRC_MSG(TST_MSG2, "System lost %d traces, %d primtives, %d others, and %d bytes")
   TRC_MSG(TR_MSG1, "Lost Primitive [%d / %d] (32 %d, 64 %d, 128 %d, 256 %d, 512 %d, 1024 %d, 2048 %d)")
   TRC_MSG(TR_MSG2, "Lost Trace [%d / %d] (32 %d, 64 %d, 128 %d, 256 %d, 512 %d, 1024 %d, 2048 %d)")
   TRC_MSG(TR_MSG3, "Lost EM [%d / %d] (32 %d, 64 %d, 128 %d, 256 %d, 512 %d, 1024 %d, 2048 %d)")
   TRC_MSG(DROP_IN_DUMP, "Lost one message not filled completely (length is %d)")
   TRC_MSG(TR_TRACE_PEER_MSG, "Message class: TRACE_PEER")
   TRC_MSG(TR_BUFFER_TRACE, "Buffer to trace by kal_buffer_trace")   
   TRC_MSG(TR_REDUMP_WARN, "Caution: To re-dump TST ring buffer!")
   TRC_MSG(TR_REDUMP_END_WARN, "Caution: Finish re-dumping TST ring buffer!")
   TRC_MSG(TR_ONLY_LOG_TO_FILE_START, "Caution: Start to only log to file!")
   TRC_MSG(TR_ONLY_LOG_TO_FILE_STOP, "Caution: Resume to log to UART/USB! (%d messeages are in-between)")
   TRC_MSG(TST_LGA_EMB_LOGS_MSG, "MCU_BUS read_index  = %d, duration = %d, bus_ccnt = %d, trans_all_cnt = %d, trans_cnt = %d, word_all_cnt = %d, word_cnt = %d, busy_all_cnt = %d, busy_cnt = %d")
   TRC_MSG(TST_LGA_EMB_LOGS_BUF_LACK, "The buffer for LOGACC EMI LOG BUF is overflow")
   TRC_MSG(TST_LGA_EMB_COUNTER_OVERRUN, "The counter of EMI BUS is overflow for %d times")
   TRC_MSG(TST_CLEAN_BUF_DATA, "The TST ring buffer is erased, %d PS logs bytes are dropped")
   TRC_MSG(TR_CMD_SET_TRAP_FILTER, "[TR] The SAP trap settings are applied: SAP type:%Msap_type, is_trap: %d")   
   TRC_MSG(TR_CMD_SET_EMI_MASTER_MONITOR, "The result of monitored masters setting: %d. Set value (%d, %d, %d)")
   TRC_MSG(TR_CMD_SET_BW_LIMIT, "The result of EMI bandwidth limit cmd is %d")
   TRC_MSG(TR_CMD_SET_CPU_LIMIT, "The result of Task execution time limit setting is is %d.")
   TRC_MSG(TR_SET_CATCHER_FILTER_NVRAM_NOT_SAVE, "[TST Reader] Filters are set successfully but not saved to NVRAM!!")
   TRC_MSG(TR_GET_ERROR_UT_PRIMITIVE, "[TST Reader] TR recevied one incorrect UT primitive")
   TRC_MSG(TR_GET_ERROR_COMMAND, "[TST Reader] TR recevied one incorrect command from PC.")
   TRC_MSG(TR_DETECT_MODULE_NOT_EXIST, "[TST Reader] %Mmodule_type doesn't exist")
   TRC_MSG(TR_RECEIVE_UNEXPECTED_CHAR, "[TST Reader] TR: Discards %d chars.")   
   TRC_MSG(TR_LOST_ONE_CMD, "[TST Reader] tst lost one command !!")
   TRC_MSG(TR_SET_CATCHER_FILTER_NVRAM_SAVE_FAIL, "[TST Reader] TST Save Filters to Flash Error !! result = %d")
   TRC_MSG(TR_QUERY_NON_SUPPORT_AREA, "[TST Reader] Don't support read memory range of DSP-DMA (0x6000-0000 ~ 0x6FFF-FFFF) !!")
   TRC_MSG(TST_TEST_KAL_TRACE0, "[TST] kal_trace0")
   TRC_MSG(TST_TEST_KAL_TRACE1, "[TST] kal_trace1: %c")
   TRC_MSG(TST_TEST_KAL_TRACEM21, "[TST] kal_trace21(1c1d1c1d1c1d1c1d1c): %c 0x%X %c 0x%X %c 0x%X %c 0x%X %c")
   TRC_MSG(TST_TEST_KAL_TRACE31, "[TST] kal_trace31(7d3c): 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X %c %c %c")
   TRC_MSG(TST_TEST_KAL_TRACE32, "[TST] kal_trace32(8d): 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X ")
   TRC_MSG(TST_TEST_KAL_TRACE33, "[TST] kal_trace33(8d1c): 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X %c ")
   TRC_MSG(TST_TEST_KAL_TRACE126, "[TST] kal_trace126(31d2c): 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X %c %c")
   TRC_MSG(TST_TEST_KAL_TRACE129, "[TST] kal_trace129(32d1c): 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X %c")
   TRC_MSG(TST_TEST_KAL_DEV_TRACE0, "[TST] kal_dev_trace0")
   TRC_MSG(TST_TEST_KAL_ASSERT_TRACE0, "[TST] kal_assert_trace0")
   TRC_MSG(TST_TEST_KAL_TRACE_for_3rd_party0, "[TST] kal_trace_for_3rd_party0")
   TRC_MSG(TST_TEST_KAL_TRACE_for_3rd_partyStr, "[TST] kal_trace_for_3rd_party(1d1s): %x, %s")
   TRC_MSG(TST_TEST_KAL_TRACE_1d, "[TST] kal_trace with 1d: %d")
   TRC_MSG(TST_TEST_KAL_TRACE_2d, "[TST] kal_trace with 2d: %d %d")
   TRC_MSG(TST_TEST_KAL_TRACE_3d, "[TST] kal_trace with 3d: %d %d %d")
   TRC_MSG(TST_TEST_KAL_TRACE_31d, "[TST] kal_trace with 31d: %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d")
   TRC_MSG(TST_TEST_KAL_TRACE_32d, "[TST] kal_trace with 32d: %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d")
   TRC_MSG(TST_TEST_KAL_TRACE_1c, "[TST] kal_trace with 1c: %c")   
   TRC_MSG(TST_TEST_KAL_TRACE_2c, "[TST] kal_trace with 2c: %c %c")
   TRC_MSG(TST_TEST_KAL_TRACE_3c, "[TST] kal_trace with 3c: %c %c %c")
   TRC_MSG(TST_TEST_KAL_TRACE_4c, "[TST] kal_trace with 4c: %c %c %c %c")
   TRC_MSG(TST_TEST_KAL_TRACE_127c, "[TST] kal_trace with 127c: %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c")
   TRC_MSG(TST_TEST_KAL_TRACE_128c, "[TST] kal_trace with 127c: %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c")   
   TRC_MSG(TR_UT_RECEIVE_INJECT_MSG, "[TST Reader][UT] Receive one inject UT message. Src_id=%Mmodule_type, dst_id=%Mmodule_type, msg_id=%Mmsg_type")
   TRC_MSG(TR_UT_ALLOCATE_UT_LOCAL_BUF, "[TST Reader][UT] Allocate a local buffer. Addr: 0x%X, Size: 0x%X")
   TRC_MSG(TR_UT_ALLOCATE_UT_LOCAL_BUF_BUFS, "[TST Reader][UT] Allocate a buf for local parameter. Addr: 0x%X, Size: 0x%X")
   TRC_MSG(TR_UT_ALLOCATE_UT_PEER_BUF, "[TST Reader][UT] Allocate a peer buffer. Addr: 0x%X, Size: 0x%X")   
   TRC_MSG(TR_UT_MSG_REF_COUNT_INCORRECT, "[TST Reader][UT] Incorrect reference count for the msg:0x%X")   
   TRC_MSG(TR_FS_OPEN_FILE_FAILED, "[TST Reader] Fail to open files for write. Error code: 0x%X")   
   TRC_MSG(TR_FS_FILE_SEEK_FAILED, "[TST Reader] Fail to seek the file to 0x%x. Error code: 0x%X")   
   TRC_MSG(TR_FS_WRITE_LENGTH_LESS_THAN_EXPECTATION, "[TST Reader] The length being written is less than expected one. Actrual write length 0x%x. Expected write length: 0x%X")   
   TRC_MSG(TR_FS_WRITE_FAILED, "[TST Reader] Failed to write to file<%d>: line %d")      
   TRC_MSG(TST_WARN_INCORRECT_INPUT_SIZE, "[TST] The input parameters sizes (0x%x) are larger than logging buffer limit. (%d)")   
   TRC_MSG(TR_UT_ECHO_STRING, "[TST Reader][UT] Print String: %s")   
   TRC_MSG(TR_UT_VARIABLE_ENUMECHO_STRING, "[TST Reader][UT] Variable Enum Test: %Mmodule_type, short: %hd, short enum: %Mmsg_type, int: %d")   
   TRC_MSG(TST_FT_FAIL_TO_CREATE_FOLDER, "[TST] Fail to create folder: %d")   
   TRC_MSG(TST_EXCEPTION_HANDLER_REPORT_EXCEPTION_STATE_TO_DSP, "[TST] Report DSP that ARM is already in the exception state: %MMDCI_RETURNVAL_T")   
   TRC_MSG(TST_EXCEPTION_HANDLER_ASK_DSP_ASSERT, "[TST] ARM asks DSP to enter the exception state: %MMDCI_RETURNVAL_T")   
   TRC_MSG(TST_EXCEPTION_HANDLER_SEND_CMD_TO_DSP, "[TST] Send %Mtst_mdci_cmd_msg_id_t to DSP: %MMDCI_RETURNVAL_T")
   TRC_MSG(TST_EXCEPTION_HANDLER_RECEIVE_CMD_TIMEOUT, "[TST] Doesn't receive data from DSP in %d ticks: %MMDCI_RETURNVAL_T")
   TRC_MSG(TST_EXCEPTION_GET_UNEXPECTED_DSP_RESPONSE, "[TST] Get unexpected DSP response. Expect: %Mtst_mdci_cmd_msg_id_t. Get: %Mtst_mdci_cmd_msg_id_t")
   TRC_MSG(TST_EXCEPTION_GET_UNEXPECTED_DATA_FROM_DSP, "[TST] Get unexpected DSP data. Expect length: %d. Received length: %d")   
   TRC_MSG(TST_EXCEPTION_DUMP_TO_FILE_START, "[TST] Start to save the memory dump into SD card.")   
   TRC_MSG(TST_EXCEPTION_DUMP_TO_FILE_END, "[TST] Finish saving the memory dump into SD card.")   
   TRC_MSG(TR_QUERY_MONITOR_CANNOT_GET_ALLOCATED_NUM, "[TR] Can't query the number of allocated buffers: %d")   
   TRC_MSG(TST_EXCEPTION_GET_TOO_MANY_MEM_BLOCKS, "[TST] Memory type:%Mtst_mem_type_string_enum returns too many blocks (%d).")   
   TRC_MSG(TST_EXCEPTION_GET_UNEXPECTED_MEM_TYPE, "[TST] Catcher queries the unexpected memory type (%d).")   
   TRC_MSG(TST_EXCEPTION_REQUEST_TOO_LONG_MEM_LEN, "[TST] Catcher queries too large blocks (Reqest: %d bytes, Allowance: %d bytes).")   
   TRC_MSG(TST_EXCEPTION_HANDLER_SEND_DATA_TIMEOUT, "[TST] Can't send data to DSP in %d ticks: %MMDCI_RETURNVAL_T")
   TRC_MSG(TST_EXCEPTION_GET_INVAILD_DSP_RETURN_ADDR, "[TST] Get unreasonable DSP return addr (0x%x --> 0x%x). Maybe the requested size is unreasonable (0x%x).")
   TRC_MSG(TST_EXCEPTION_GET_VAILD_DSP_RETURN_ADDR, "[TST] Get DSP return addr (0x%x --> 0x%x). The requested size is (0x%x).")
   TRC_MSG(TST_CCCI_CANNOT_SEND_DATA, "[TST] Can't send data (%Mtst_mdci_cmd_msg_id_t) to DSP : %MMDCI_RETURNVAL_T")
   TRC_MSG(TST_VITI_USB_INCORRECT_CTRL_BLK, "[TST][VITI][USB] The ctrl block info (%hx) is incorrect (%d). (Should be %d)")
   TRC_MSG(TST_VITI_USB_SEND_PC_CMD_TO_VITI, "[TST][VITI][USB] Send %d bytes to VITI TST")
   TRC_MSG(TST_VITI_USB_FORWARD_DATA_NOT_INITED, "[TST][VITI][USB] DSP doesn't send connection info to MCU yet. Doesn't foward data to DSP")
   TRC_MSG(TST_VITI_USB_LOG_INIT, "[TST][VITI][USB] MCU sets up the USB virtual channel for DSP logging relay.")
   TRC_MSG(TST_VITI_USB_LOG_UPDATE_START_PTR, "[TST][VITI] Data is sent from USB driver, update read start ptr as %x")
   TRC_MSG(TST_VITI_USB_LOG_RESUME_SENDING, "[TST][VITI] Resume sending uncompleted data (size = %x), reading from: %x to %x")
   TRC_MSG(TST_VITI_USB_LOG_DATA_PENDING, "[TST][VITI] Data is pending in USB driver, len = %x, from: %x to %x")
   TRC_MSG(TST_VITI_USB_LOG_CMD_PASS, "[TST][VITI] Move data from %x to %x")
   TRC_MSG(TST_VITI_USB_DATA_READY, "[TST][VITI] Data to send = %x, read start = %x, read end = %x, sent_bytes = %x ")
   TRC_MSG(TST_VITI_USB_RING_BUF_CONTROL, "[TST][VITI][Ring] Data to send = %x, read start = %x, read end = %x, sent_bytes = %x ")
   TRC_MSG(TST_VITI_USB_DMA_NOT_SUPPORTED, "[TST][VITI]High Speed USB Interface is not supported ")
   TRC_MSG(TST_FAILED_TO_GET_RAM_STAT, "[TST] Fail to get the statistics from stack_update_sys_statistics ")
   TRC_MSG(TST_MINI_LOG_REGISTER_CALLBACK, "[TST] %MMINI_LOG_STATIC_INFO_TYPE_T register mini log callback, size = %d.")
   TRC_MSG(TST_MINI_LOG_REGISTER_CALLBACK_ALREADY, "[TST] Mini log callback has registerd already.")
   TRC_MSG(TST_MINI_LOG_REGISTER_CALLBACK_FAILED, "[TST] Mini Log total registered size(%d) > MAX_BYTES_TO_SAVE(%d).")
   TRC_MSG(TST_MINI_LOG_START_TO_DUMP, "[TST] Start to dump mini log.")
   TRC_MSG(TST_SPARE_LOG_SWITCH_LOST_MSG, "[TST] TST drops 0x%x bytes, from buf: 0x%x, start idx: 0x%x, end idx = 0x%x")
   TRC_MSG(TST_SPARE_LOG_SWITCH_LOST_L1_MSG, "[TST] L1 drops 0x%x bytes, from buf: 0x%x, start idx: 0x%x, end idx = 0x%x")
   TRC_MSG(TST_SPARE_LOG_SMALL_BUF_LEFT, "[TST] The unused RAM is too small, Pre-allocated buf size = 0x%x, Spare RAM ptr = 0x%x, size = 0x%x")
   TRC_MSG(TST_SPARE_LOG_ALREADY_START, "[TST] The spare logging has been started already. Log ptr = 0x%x, Spare RAM ptr = 0x%x, size = 0x%x")
   TRC_MSG(TST_SPARE_LOG_ALREADY_STOP, "[TST] The spare logging has been stopped already. Log ptr = 0x%x, Spare RAM ptr = 0x%x, size = 0x%x")
   TRC_MSG(TST_SPARE_LOG_START, "[TST] The spare logging starts. Log ptr = 0x%x, Spare RAM ptr = 0x%x, size = 0x%x")
   TRC_MSG(TST_SPARE_LOG_STOP, "[TST] The spare logging stops. Log ptr = 0x%x, Logging buf ptr = 0x%x, size = 0x%x")
   TRC_MSG(TST_GDI_SCREEN_SHOT_FAILED, "[TST] gdi_screen_shot_capture returns NULL")
   TRC_MSG(TST_GDI_SCREEN_SHOT_CREATE_LAYER_FAILED, "[TST] gdi_layer_create_using_outside_memory failed (0x%x)")
   TRC_MSG(TST_GDI_SCREEN_SHOT_SAVE_JPEG_FAILED, "[TST] gdi_image_encode_layer_to_jpeg failed (0x%x)")
   TRC_MSG(TST_REDUMP_LOG_FAILED, "[TST] Failed to dump the whole logging buffer. error code:%d, start pos = 0x%x, end pos = 0x%x")
   TRC_MSG(TST_REDUMP_SEARCH_REDUMP_START, "[TST] Search redump start pos. return code:%d, search_start = 0x%x, search_end = 0x%x, redump_start = 0x%x")
   TRC_MSG(TST_REDUMP_SEARCH_REDUMP_ONGOING, "[TST] Search redump start pos. search from 0x%x, local_search_len = 0x%x")
   TRC_MSG(TST_REDUMP_SEARCH_REDUMP_ONGOING_END, "[TST] Finish searching redump start pos. search from 0x%x, end at 0x%x")
   TRC_MSG(TST_REDUMP_L1_LOG_FAILED, "[TST] Failed to dump the whole L1 logging buffer. error code:%d, start pos = 0x%x, end pos = 0x%x")
   TRC_MSG(TST_REDUMP_L1_SEARCH_REDUMP_START, "[TST] Search L1 logging buffer redump start pos. return code:%d, search_start = 0x%x, search_end = 0x%x, redump_start = 0x%x")
   TRC_MSG(TST_REDUMP_L1_SEARCH_REDUMP_ONGOING, "[TST] Search L1 redump start pos. search from 0x%x, local_search_len = 0x%x")
   TRC_MSG(TST_REDUMP_L1_SEARCH_REDUMP_ONGOING_END, "[TST] Finish L1 searching redump start pos. search from 0x%x, end at 0x%x")
   TRC_MSG(TST_REDUMP_L1_INCORRECT_PKT, "[TST] Find incorrect L1 packet at 0x%x")
   TRC_MSG(TST_REDUMP_PS_INCORRECT_PKT, "[TST] Find incorrect PS packet at 0x%x")
   TRC_MSG(TST_DL_PKT_LOG, "Log DL pkt. Mod=%Mmodule_type. SAP1=%Msap_type, SAP2=%Msap_type, ptr=0x%x")
   TRC_MSG(TST_DL_PKT_LOG_GPD, "Log DL pkt. GPD header data")
   TRC_MSG(TST_DL_PKT_LOG_BD, "Log DL pkt. BD header data")
   TRC_MSG(TST_DL_PKT_LOG_Raw_Data, "Log DL pkt. raw data")
   TRC_MSG(TST_CPHY_LOG_BUF_ALLOCATION_FAILURE, "Failed to allocate Cphy log buffer. Line=%d")
END_TRACE_MAP(MOD_TST)
#endif /* _TST_TRACE_H */


