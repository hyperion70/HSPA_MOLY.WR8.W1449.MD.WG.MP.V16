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
 * tst_sp_logging.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements Smartphone Catcher logging.  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __TST_SP_LOGGING_H__
#define __TST_SP_LOGGING_H__
 
#include "kal_public_api.h"
#include "dcl.h"

#ifdef __LOGACC_ENABLE__
  #include "tst_lga_hw.h"
#endif  //__LOGACC_ENABLE__

#if !defined(__TST_ON_AOS__) && !defined(__TST_ON_AOS_PC__)
  #include "ccci.h"
#endif//#ifndef __TST_ON_AOS__

//special options
//#define __TST_SP_USB_THROUGHPUT_MEASUREMENT__
//With this mode, we fill into fake data into L1 and PS logging buffers
//It's activated by CCCI commands
//After it is enabled, fake data will be filled in from TST Reader and trc process hisr
//The data will be filled as long as some space are available.


//definitions
#define MD_LOG_BUF_NUM (8)
#define MD_CMD_BUF_NUM (2)  //ARM and DSP buffers

//logging buffer idx
#define PS_LOG_BUF_IDX (0)
#define L1_LOG_BUF_IDX (1)
#define DSP_LOG_BUF_IDX (2)
//DSP MLT logging
#define MLT_DMDSP_LOG_BUF_IDX (3)
#define MLT_MD2G_LOG_BUF_IDX (4)
//AST L1 logging
#define AST_L1_LOG_BUF_IDX (5)
//FDDSP Logging
#define MLT_FDDSP_LOG_BUF_IDX (6)
//MALMO ASM Logging
#define MALMO_ASM_LOG_BUF_IDX (7)

#define RX_RCV_BUF_IDX (0)
#define DSP_RX_RCV_BUF_IDX (1)

#define AP_TRIGGER_THRESHOLD_SD (50)	//%
#define AP_TRIGGER_THRESHOLD_USB (25)	//%
#define AP_TRIGGER_INTERVAL (10) //*4.615ms
#define AP_TRIGGER_EXCEPTION_INTERVAL (512) //*4.615ms
#define AP_TRIGGER_EXCEPTION_MAX_WAIT_INTERVAL (1<<12) //19 sec
#define TST_EXCEPTION_CCCI_READ_TIMEOUT_VALUE (2) //us

#define MLT_FDDSP_CHANNEL (0)

#ifdef __TST_ON_AOS__
  #define TST_CCCI_SP_USB_READ_CHANNEL (1)
  #define TST_CCCI_SP_USB_WRITE_CHANNEL (0)
#else   //#ifdef __TST_ON_AOS__
  #define TST_CCCI_SP_USB_READ_CHANNEL (CCCI_MD_LOG_TX)
  #define TST_CCCI_SP_USB_WRITE_CHANNEL (CCCI_MD_LOG_RX)
#endif  //#ifdef __TST_ON_AOS__

#define SHARED_MEM_HEADER (0x2454ABCD)
#define SHARED_MEM_VERSION (0x2)

#define L1_SHARE_BUF_SIZ (1<<18)
#define PS_SHARE_BUF_SIZ (1<<18)
#if defined(__SMART_PHONE_MODEM__) && defined(__AST_TL1_TDD__)
  #define AST_L1_SHARE_BUF_SIZ (1<<17)
#else
  #define AST_L1_SHARE_BUF_SIZ 0
#endif  //#if defined(__AST_TL1_TDD__)

#if defined(__DSP_FCORE4__)
  #define DAK_SHARE_BUF_SIZ (1<<15)
#else
  #define DAK_SHARE_BUF_SIZ 0
#endif  //#if defined(__DSP_FCORE4__)

#if defined(__SMART_PHONE_MODEM__) && defined(__DSPIRDBG_SP__)
  
  #include "reg_base.h"  
  
  #ifndef MD2G_SHEME_BASE
    #define   MD2G_SHEME_BASE                              BFMDIF_base          //(0x65000000) in MT6276, (0x61400000) in MT6573, (0x85000000) in MT6575
  #endif
  
  #define TST_DP_USBLOG1_BUFE_H_ADDR   (MD2G_SHEME_BASE+0x062a)  //-> higher 16 bit of BufE address
  #define TST_DP_USBLOG1_BUFE_L_ADDR   (MD2G_SHEME_BASE+0x062c)  //-> lower 16 bit of BufE address    
  #define TST_DP_USBLOG1_SIZE_ADDR     (MD2G_SHEME_BASE+0x062e)  
  #define TST_DP_USBLOG1_USBREADY_ADDR   (MD2G_SHEME_BASE+0x0630)
  #define TST_DP_USBLOG2_BUFE_H_ADDR   (MD2G_SHEME_BASE+0x0632)
  #define TST_DP_USBLOG2_BUFE_L_ADDR   (MD2G_SHEME_BASE+0x0634)
  #define TST_DP_USBLOG2_SIZE_ADDR     (MD2G_SHEME_BASE+0x0636)
  #define TST_DP_USBLOG2_USBREADY_ADDR   (MD2G_SHEME_BASE+0x0638)

  #define MLT_DMDSP_LOG_BUF_SIZ (196544)  //(8188 byte * 24)+32 = 196512+32 --> required 1 more 32bytes for alignment
  #define MLT_MD2G_LOG_BUF_SIZ (196544) //(8188 byte * 24)+32 = 196512+32 
  #define MLT_LOG_BUF_TOTAL_SIZ (MLT_DMDSP_LOG_BUF_SIZ+MLT_MD2G_LOG_BUF_SIZ)
  
#else 
  #define MLT_LOG_BUF_TOTAL_SIZ 0
#endif  //#if defined(__SMART_PHONE_MODEM__) && defined(__DSPIRDBG_SP__)

//FDDSP SP Logging
#if defined(__SMART_PHONE_MODEM__) && defined(__FDDSPIRDBG_SP__)

  #if defined(__SMART_PHONE_MODEM__) && defined(__DSPIRDBG_SP__)
	  #error "__FDDSPIRDBG_SP__ and __DSPIRDBG_SP__ cannot be defined at the same time!"
  #endif
  
  #define MLT_FDDSP_LOG_BUF_SIZ (384*1024+32)  // 384 KB + 32 byte (required 1 more 32bytes for alignment)
 
#else 
  #define MLT_FDDSP_LOG_BUF_SIZ 0
#endif  //#if defined(__SMART_PHONE_MODEM__) && defined(__FDDSPIRDBG_SP__)

#if defined(__SMART_PHONE_MODEM__) && defined(__TST_MALMO_SUPPORT__) && defined(__TST_ASM_SUPPORT__)
  #define MALMO_ASM_LOG_BUF_SIZ ((1<<18)+32) //(required 1 more 32bytes for alignment)
#else
  #define MALMO_ASM_LOG_BUF_SIZ (0)
#endif

#ifndef __TST_ON_AOS__
  #define ccci_write_cmd ccci_tst_stream_write_with_reserved
  #define shared_mem_write_ary memcpy
  #define shared_mem_set_array memset
#endif  //#ifndef __TST_ON_AOS__

#define tst_sp_usb_ut_printf(...)
 
//define CCCI cmds
typedef enum
{
    CCCI_MSG_ID_TST_SHARED_MEM_CREATE_REQ      = 0x00000001,   /* M2A, MD asks AP to create the share mem */
    CCCI_MSG_ID_TST_SHARED_MEM_ADDR_REPORT     = 0x00000002,   /* A2M, AP reports the shared mem addr to MD */
    CCCI_MSG_ID_TST_LOGGING_START              = 0x00000003,   /* M2A, MD informs that the shared mem info is completed */
    CCCI_MSG_ID_TST_EXCEPTION_MODE_REPORT      = 0x00000004,   /* M2A, MD informs it enters the exception mode */
    CCCI_MSG_ID_TST_TRIGGER_LOG_MOVE           = 0x00000005,   /* M2A, MD asks AP to move logs */
    CCCI_MSG_ID_TST_TRIGGER_CMD_MOVE           = 0x00000006,   /* A2M, AP asks MD to move cmd */
    CCCI_MSG_ID_TST_NEXT_CMD_REQ               = 0x00000007,   /* M2A, MD asks AP to move next cmd */
    CCCI_MSG_ID_TST_DUMP_TO_USB                = 0x00000008,   /* A2M, AP tells MD the current logging mode is USB */
    CCCI_MSG_ID_TST_DUMP_TO_FILE               = 0x00000009,   /* A2M, AP tells MD the current logging mode is log2File */
    CCCI_MSG_ID_TST_LOGGING_READY              = 0x0000000A,   /* A2M, AP tells MD it's ready for logging */
    CCCI_MSG_ID_TST_SD_FILE_REQUEST            = 0x0000000B,   /* M2A, MD asks AP to fill SD filter into cmd buf */
    CCCI_MSG_ID_TST_SWITCH_MD_LOGGING_MODE     = 0x0000000C,   /* A2M, AP asks to switch logging mode */
    CCCI_MSG_ID_TST_AP_MD_UT_CMD               = 0x0000000D,   /* A2M, AP asks to perform some UT operations */
    CCCI_MSG_ID_TST_MEMORY_DUMP_ENABLE_REQ     = 0x0000000E,   /* A2M, AP asks to enable memory dump */
    CCCI_MSG_ID_TST_MEMORY_DUMP_DISABLE_REQ    = 0x0000000F,   /* A2M, AP asks to disable memory dump */ 
    CCCI_MSG_ID_TST_UT_THROUGHPUT_MEASURE_PS   = 0x00000010,   /* A2M, AP asks to enter the throughput measurement mode, PS only*/ 
    CCCI_MSG_ID_TST_UT_THROUGHPUT_MEASURE_ALL  = 0x00000011,   /* A2M, AP asks to enter the throughput measurement mode, PS+L1+... */ 
    CCCI_MSG_ID_TST_UT_THROUGHPUT_MEASURE_STOP = 0x00000012,   /* A2M, AP asks to leave the throughput measurement mode*/ 
    CCCI_MSG_ID_TST_HANDSHAKE_DONE_IDX         = 0x00000013    /* M2A, MD tells AP that handshake is done */
} tst_ccci_cmd_msg_id_t;

typedef enum
{
	TST_AP_STATUS_NORMAL=0,
	TST_AP_STATUS_BUSY,
	TST_AP_STATUS_POWER_SAVING,
	TST_AP_STATUS_PAUSE_LOGGING,
	TST_AP_STATUS_END
}
tst_ap_status_ind_enum_t;

//define MD command sets
typedef enum
{
  MD_CMD_NULL,
  MD_CMD_MEM_DUMP_START,
  MD_CMD_END
} tst_md_cmds_set_t;

//define AP command sets
typedef enum
{
  AP_CMD_NULL,
  AP_CMD_END
} tst_ap_cmds_set_t;

typedef struct
{
  unsigned int header;
  unsigned short ctrl_buf_len;
  unsigned short version;
  unsigned short md_cmd;
  unsigned short md_ack;
  unsigned short ap_cmd;
  unsigned short ap_ack;
  unsigned char ap_status;
  unsigned char md_status;
  unsigned char m2a_buf_num;
  unsigned char a2m_buf_num;
  unsigned int reserved;
}shared_mem_header_struct_t;

typedef struct
{
  unsigned int ptr;
  unsigned int size;
  unsigned int start_pos;
  unsigned int end_pos;

} shared_mem_buf_des_struct_t;

//Simulation code for CCCI interface
//Shengkai: pseudo struct for MD-AP CCCI
typedef struct  
{
  kal_uint8 ref_count; 
  kal_uint16 msg_len;  
  kal_uint32 msg_id;
  kal_uint32 extra_data[2];
}
tst_ccci_data_struct_t;

typedef enum
{
  TST_SP_USB_LOG_NULL=0,
  TST_SP_USB_LOG_SIZE_REQ,
  TST_SP_USB_LOG_SIZE_GOT,
  TST_SP_USB_LOG_MEM_INIT,
  TST_SP_USB_LOG_START
}
tst_sp_usb_logging_status_t; 

typedef enum
{
  TST_SP_USB_ENTER_EXCEPTION_MODE=0,
  TST_SP_USB_SEND_FIXED_PATTERN=1,
  TST_SP_USB_LAST_CMD
}
tst_sp_usb_ap_md_ut_cmd_t;

#ifdef __SMART_PHONE_MODEM__
  #define tst_ccci_buf_t CCCI_BUFF_T
#else
  #define tst_ccci_buf_t int
#endif

//Function declaration
void tst_sp_usb_copy_data_to_shared_mem(kal_uint32 i, const kal_uint8* buf, kal_uint32 data_len, kal_uint32 *start_pos);
kal_uint32 tst_sp_usb_query_free_space(kal_uint32 buf_idx);
void tst_sp_usb_update_ps_logging_ptr(void);
int tst_sp_usb_report_exception_mode(void);
void tst_sp_usb_assert_save_mem_dump(void);
#ifdef __SMART_PHONE_MODEM__
  void tst_ccci_msg_handle(CCCI_BUFF_T* tst_ccci_data);
#endif  //#ifdef __SMART_PHONE_MODEM__
void tst_sp_usb_update_ps_logging_ptr(void);
void tst_sp_usb_duplicate_ring_buffer(kal_uint32 i, const kal_uint8* src, kal_uint32 start_idx, kal_uint32 end_idx);
void tst_sp_usb_update_logging_ptr(kal_uint32 idx, kal_uint32 ptr_end_idx);
kal_uint32 tst_sp_usb_get_logging_ap_read_ptr(kal_uint32 idx);
void tst_sp_usb_update_l1_logging_ptr(kal_uint32 ptr_end_idx);
void tst_register_sp_usb_handler(DCL_DEV port);
void tst_sp_usb_check_and_trigger_ap(void);
void tst_sp_usb_ccci_registration(void);
void tst_sp_usb_issue_read_trigger_to_ap(unsigned int data1, unsigned int data2);
kal_uint32 tst_sp_usb_get_logging_ap_write_ptr(kal_uint32 idx);
kal_int32 tst_exception_read_ccci_channel(tst_ccci_buf_t* buff);
void tst_ccci_exception_handler(tst_ccci_buf_t* tst_ccci_data);
kal_uint32 tst_sp_usb_send_l1_log(kal_uint8* cur_buf, kal_uint32 nLen, kal_uint32 nTotalSentChar,  kal_uint64 nChecksum);
kal_bool tst_sp_usb_report_exception_to_ap(void);
void tst_sp_usb_exception_report_handshake_stage(void);
kal_bool tst_sp_usb_md_logging_enable_status(void);
void tst_fddsp_splogging_create_isr(void);
void tst_fddsp_splogging_update_handler(void);

#if defined(__SMART_PHONE_MODEM__) && defined(__TST_MALMO_SUPPORT__) && defined(__TST_ASM_SUPPORT__)
void tst_malmo_asm_update_rptr_sp();
void tst_malmo_asm_update_wptr_sp();
#endif

#endif //__TST_SP_LOGGING_H__
