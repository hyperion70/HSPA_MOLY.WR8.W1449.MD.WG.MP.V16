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
 * tst_alc_logging.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements PS trace functions when Malmo Logging is enabled
 *   When __TST_MALMO_SUPPORT__ is defined, tst_trace_alc.c will replace tst_trace.c
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
#ifndef __TST_ALC_LOGGING_H__
#define __TST_ALC_LOGGING_H__

//**************************************************************
//      GV
//**************************************************************
#define TST_BUS_MONITOR_BUF_SIZE (1<<20)
#define TRC_L1_ALC_BUF_SIZ (1<<19) //Set to 512 KB due to L1 trace drop issue

//#define __TST_MALMO_ADOE_MANUAL_MODE__

#define __TST_ADOE_MANUAL_MODE_ASM_BUF_ALT_TH__ (2) //N means to set the threshold to be 1/N of buffer size
#define __TST_ADOE_MANUAL_MODE_L1_BUF_ALT_TH__ (2) //N means to set the threshold to be 1/N of buffer size
#define __TST_ADOE_MANUAL_MODE_PS_BUF_ALT_TH__ (2) //N means to set the threshold to be 1/N of buffer size

//**************************************************************
//      Function Declaration
//**************************************************************
void tst_malmo_init(void);
void tst_alc_reinit(void);
void tst_alc_decide_logging_flag(void);
void tst_alc_wait_for_flush(void);
void tst_alc_switch_off_in_exception(void);
void trc_alc_redump_l1_buf_as_fatal_error(void);
void tst_alc_get_l1_buffer_ptr(kal_uint32 *read_ptr, kal_uint32 *write_ptr);
void tst_alc_get_ps_buffer_ptr(kal_uint32 *read_ptr, kal_uint32 *write_ptr);
void tst_alc_update_ps_buffer_ptr_globally(void);
void tst_alc_update_l1_read_ptr(kal_uint32 ptr);
void tst_alc_update_ps_read_ptr(kal_uint32 ptr);
kal_uint32 tst_alc_calculate_max_l1_output_size( 
	kal_uint32 start_ptr, kal_uint32 end_ptr, 
	const kal_uint32 buffer_size, const kal_uint32 max_output_size, 
	kal_uint32 *new_start_ptr, kal_bool *handle_wrap  );

void tst_adoe_init(void);
void tst_adoe_ignore_nxtbufrdy(void);

#endif  //__TST_ALC_LOGGING_H__
