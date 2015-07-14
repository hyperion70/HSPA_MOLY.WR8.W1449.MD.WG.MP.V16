/*******************************************************************************
*  Modification Notice:
*  --------------------------
*  This software is modified by MediaTek Inc. and the information contained
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
*******************************************************************************/


/*****************************************************************************
 *
 * Filename:
 * ---------
 * tst_ext.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains data structures for both L1 and PS traces
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
 
#ifndef TST_EXT_H
#define TST_EXT_H

#include "kal_general_types.h"
#include "fs_type.h"

//Common definitions
#define TST_COMMIT_BATCH 10
// (1<<24) is 16M, don't define it less than 1M (1<<20)
#define TST_MAX_LOG_SIZE_FOR_SINGLE_FILE (1<<24)
#if !defined(__SMART_PHONE_MODEM__)
  #define TST_FSWRITE_BUFFER_SIZE (1<<14)
  //TST_L1_BUFFER_SIZE_FOR_WRITE_FILE must be smaller than TST_FSWRITE_BUFFER_SIZE
  #define TST_L1_BUFFER_SIZE_FOR_WRITE_FILE (1<<13)
#else //#if !defined(__SMART_PHONE_MODEM__)
  #define TST_FSWRITE_BUFFER_SIZE (1<<13)
  //TST_L1_BUFFER_SIZE_FOR_WRITE_FILE must be smaller than TST_FSWRITE_BUFFER_SIZE
  #define TST_L1_BUFFER_SIZE_FOR_WRITE_FILE (1<<12)
#endif  //#if !defined(__SMART_PHONE_MODEM__)

#define TST_FILE_MIN_DISK_SIZE (1<<17)

//TFT event
#define TFT_EVENT_SD_CARD_READY 0x1

//Common typedefs
typedef enum
{
  TST_Write2File_None,  //Not to SD
  TST_Write2File_Only,  //SD
  TST_Write2File_Both,  //USB and SD
}
tst_write2_sd_option_t;

typedef enum
{
 NO_LOG_ERROR,
 DISK_FULL,
 NO_CARD,
 ERR_EXTEND,
 ERR_WRITE,
 ERR_COMMIT,
 ERR_OPEN,
 ERR_CLOSE,
 ERR_DIR,
 ERR_ALLOC_MEM
}tst_log_to_file_err_enum;

#ifdef __TST_WRITE_TO_FILE__ 

typedef struct 
{
  tst_write2_sd_option_t tst_write2_sd_option; //bWriteToFile and bWriteToFileOnly
  kal_bool   bAlreadyAssertDump;
  kal_bool   bHeadOfOnePacket;
  kal_bool   bAssertForFull;

  kal_char   cDriveLetter;
  WCHAR      strAssertFolderName[64];
  kal_uint32 nDiskFreeSpace;
  kal_uint32 nFileFreeSpace;
  FS_HANDLE  fHandle;
  kal_uint32 nOmitPacketCount;
  kal_uint32 nBufferPtr;
  kal_uint32 nCommitCountDown;
  kal_uint8  buffer[TST_FSWRITE_BUFFER_SIZE];

  kal_uint32 nL1BufferWritePtr;
  kal_uint32 nL1BufferVancancy;  
  kal_uint8  L1Buffer[TST_L1_BUFFER_SIZE_FOR_WRITE_FILE];
}
tst_dump_info_struct;

extern tst_dump_info_struct tst_dump_info;

#endif //#ifdef __TST_WRITE_TO_FILE__

//extern variables
extern tst_log_to_file_err_enum tst_err_log_to_file;

//Common function prototype
extern tst_write2_sd_option_t tst_file_query_write2file_option(void);
extern kal_uint32 tst_file_query_l1_log_space(void);
extern kal_uint32 tst_file_query_ps_log_space(void);
extern void tst_file_init_l1_log_buf(void);
extern void tst_file_sp_check_sd_ready(void);
extern kal_uint32 tst_file_check_if_output2uart(void);
extern kal_uint32 tst_file_indicate_write2file_only(void);
extern void tst_file_dump_ps_log_to_file(kal_uint8 *buffer, kal_uint32 length);
extern kal_uint32 tst_file_dump_isr_log_to_file(kal_uint8 *buffer, kal_uint32 length);
extern void tst_dump_reset_file_buf_info(void);
extern kal_bool tst_file_get_ps_log_head_packet(void);
extern kal_uint32 tst_file_request_file_space_on_disk(kal_uint32 request_space);
extern kal_uint32 tst_file_query_disk_space(void);
extern kal_uint32 tst_file_reserve_ps_log_space(kal_uint32 length);
extern void tst_file_set_tst_write2_sd_option(tst_write2_sd_option_t tst_write2_sd_option);
extern kal_bool tst_file_query_if_write2sd_start(void);
extern kal_uint32 tst_file_query_omit_pkt(void);
extern FS_HANDLE tst_file_query_write_handler(void);
extern void tst_file_set_write_handler(FS_HANDLE fHandle);
extern WCHAR* tst_file_query_assert_folder_name(void);
extern kal_uint32 tst_file_query_nBufferPtr(void);
extern kal_bool tst_file_set_already_dump(void);
extern kal_bool tst_file_reserve_disk_space(kal_uint32 length);
extern kal_int32 tst_file_store_unsaved_log(void);
extern void tst_file_check_and_dump_isr_log(void);
extern void tst_file_set_ps_log_head_packet(kal_bool value);
void tst_file_dump_log_to_file(kal_uint8 *buffer, kal_uint32 length, kal_uint32 caller_context);
kal_bool tst_file_check_lga_data_saved(void);

extern kal_uint8* tst_file_ex_tmp_buf;
extern kal_uint32 tst_file_ex_tmp_buf_size;

#endif	 

