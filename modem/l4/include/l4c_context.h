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
 *	l4c_context.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for ...
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/



#ifndef _L4C_CONTEXT_H
#define _L4C_CONTEXT_H

#if 0 //hong_rhr
#ifndef _RMMI_CONTEXT_H
/* under construction !*/
#endif
#endif
//#include "rmmi_context.h"
//#include "kal_non_specific_general_types.h"
//#include "app_ltlcom.h"
#include "l4c_common_enum.h"
//#include "event_shed.h"
//#include "stack_timer.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "kal_general_types.h"
#include "ps_public_enum.h"
#include "kal_public_api.h"
#include "rmmi_common_enum.h"

#if !defined(__MTK_TARGET__) && defined(__RMMI_UT__)
#include "lcd_lqueue.h"    
#endif

#if defined(__SIM_ME_LOCK__)
#include "smu_common_enums.h"
#endif

#ifndef __MMI_FMI__
#define __PHB_SORT_ENABLE__
#endif 

#if 1//def __SP_RIL_SUPPORT__
#define __DEACT_ABORT_CGACT__
#endif

#ifdef DATA_DOWNLOAD
//#include "fat_fs.h"
#define L4C_ENCODE_BYTE 2
#define L4C_MAX_DATA_DL_NAME_EXTENSION_WIDTH		(5*L4C_ENCODE_BYTE)													//NULL ermiante
#define L4C_MAX_DATA_DL_NAME_WIDTH				((13*L4C_ENCODE_BYTE)	+	L4C_MAX_DATA_DL_NAME_EXTENSION_WIDTH + L4C_ENCODE_BYTE)

typedef struct
{
	kal_uint8 filename[L4C_MAX_DATA_DL_NAME_WIDTH];
	kal_uint16 file_id;
}l4c_download_file_info;

#endif/* DATA_DOWNLOAD */

//#include "mcd_l3_inc_struct.h"
//#include "l4c_hz_context.h"

//#include "med_struct.h"

/* For GPRS_FLC_UT mtk02508 */
#if !defined(__MTK_TARGET__) && defined(__RMMI_UT__) && defined(__MOD_TCM__)
#include "lcd_lqueue.h"
#endif

#if defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__)
#include "l4c_ratdm_struct.h"
#include "mmi_l3_enums.h"
#endif

#include "l3_inc_enums.h" //for rrc_state

#define MAX_CONCAT_SMS_NUM    4

//#define MAX_CEER_REPORT_LEN    80

#define L4C_STATES      3

//#define L4C_PTR      LAYER4_PTR(l4c_ptr)
#define L4C_PTR        l4c_ptr_g

//mtk01616_100419: to share SIM1/SIM2 L4C context in Gemini 
#define L4C_COMM_PTR   l4c_comm_ptr_g

#if defined(__GEMINI__)
#define L4C_ROOT_PTR   l4c_root_ptr_g
#endif

/*#ifdef __HOMEZONE_SUPPORT__
#define HZ_PTR     l4c_ptr_g->hz_ptr
#endif*/

extern peer_buff_struct *l4c_mcd_pack (kal_uint16 structid,
                  kal_uint8 *msg,
                  kal_uint8 hdr_size,
                  kal_uint8 tlr_size);

extern kal_uint16 l4c_mcd_unpack(kal_uint16 structid,
                           peer_buff_struct *peer_buff_ptr);

#define L4C_PACK_ALLOC(ALLOC_FUNC, STRUCTID, STRUCT, MSG_PTR) \
   mcd_pseudo_alloc(STRUCTID, l4_pun_src_buff ,sizeof(l4_pun_src_buff)); \
   MSG_PTR = (STRUCT*)l4_pun_src_buff

#define L4C_UNPACK_ALLOC(ALLOC_FUNC, STRUCTID, STRUCT, MSG_PTR)

#define L4C_PACK_DEALLOC(DEALLOC_FUNC, MSG_PTR)

#define L4C_UNPACK_DEALLOC(DEALLOC_FUNC, MSG_PTR)

#define L4C_PACK(PACK_FUNC, BITS_FUNC, STRUCTID, MSG_PTR, \
                 HDR_SIZE, TLR_SIZE) \
   l4c_mcd_pack(STRUCTID, \
                (kal_uint8*)MSG_PTR, \
                HDR_SIZE, \
                TLR_SIZE)

#define L4C_UNPACK(UNPACK_FUNC, STRUCTID, STRUCT, MSG_PTR, PEER_BUFF) \
   l4c_mcd_unpack(STRUCTID, PEER_BUFF); \
   MSG_PTR = (STRUCT*)l4_pun_dest_buff

#define REMAP_UNPACK_DATA(MSG_LEN, MSG_PTR) \
   kal_mem_cpy (l4_pun_dest_buff, MSG_PTR, MSG_LEN)

#define COPY_UNPACK_DATA(MSG_LEN, MSG_PTR) \
   ASSERT(MSG_LEN <2048); \
   MSG_PTR = get_ctrl_buffer(MSG_LEN); \
   kal_mem_cpy (MSG_PTR, l4_pun_dest_buff, MSG_LEN)

#define FREE_COPY_UNPACK_DATA(MSG_PTR) \
   free_ctrl_buffer (MSG_PTR)

#define REMAP_PACK_DATA(MSG_LEN, MSG_PTR) \
   kal_mem_cpy (l4_pun_src_buff, MSG_PTR, MSG_LEN)

#define COPY_PACK_DATA(MSG_LEN, MSG_PTR) \
   MSG_PTR = get_ctrl_buffer(MSG_LEN); \
   ASSERT(MSG_LEN <2048); \
   kal_mem_cpy (MSG_PTR, l4_pun_src_buff, MSG_LEN)

#define FREE_COPY_PACK_DATA(MSG_PTR) \
   free_ctrl_buffer (MSG_PTR)

#define SUBFIELD(PARENT, CHILD) PARENT->CHILD

typedef void (*L4C_MSG_FUNCTION) ( local_para_struct *,
                                   peer_buff_struct * );

typedef void (*L4C_CMD_FUNCTION) ();


typedef struct
{
   kal_uint16   length;
   void        *data;
} l4c_parameter_struct;

typedef struct
{
   kal_bool    is_valid;
   kal_bool    need_retry;
   kal_uint16  length;
   void        *local_para;
   void        *peer_buff;
} l4c_concat_sms_buff_struct;

typedef struct
{
   kal_uint8 type;
   kal_uint8 length;
   kal_uint8 number[MAX_CC_ADDR_LEN];
} l4_number_struct;

#if 0 //__CTM_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

typedef struct
{
	kal_uint8	is_gsm_conn_exist;
	kal_uint8	gsm_cipher_cond;
	kal_uint8	gprs_cipher_cond;
} cipher_ind_msg_struct;

 #ifdef __NBR_CELL_INFO__
 typedef struct
 {
 	kal_uint32 src_id;
 	kal_bool already_cnf;	
 }cell_info_reg_table_struct; 	/* Lexel: for Cell info */
 #endif

typedef struct l4c_nw_sysconfig_struct
{
   kal_uint8 rat_mode;
   kal_uint8 prefer_rat;
   kal_bool support_roaming;
   kal_uint8 mobile_class;
} l4c_nw_sysconfig_struct;

typedef struct l4c_nw_syssel_struct
{
   kal_uint8 rat_mode;
   kal_uint8 prefer_rat;
   kal_uint8 mobile_class;
} l4c_nw_syssel_struct;

typedef enum
{
    L4C_IPV4V6_STATE_NONE = 0,
    L4C_IPV4V6_STATE_ACCEPT,
    L4C_IPV4V6_STATE_REJECT
} l4c_ipv4v6_state_enum;

typedef enum
{
    L4C_IPV4V6_PDP_ACTIVATOR_IS_L4C,
    L4C_IPV4V6_PDP_ACTIVATOR_IS_PPP
} l4c_ipv4v6_activator_enum;

#define L4C_IPV4V6_ACT_TABLE_SIZE (3) //V4V6, V4, V6

typedef struct
{
    kal_uint8 cid;
    kal_uint8 pdp_type;
    kal_uint8 state;
    kal_uint8 __aligned;
} l4c_gprs_ipv4v6_act_table_entry;

typedef struct
{
    kal_uint8 src_id;
    kal_uint8 init_cid;
    kal_uint16 cause;
    l4c_gprs_ipv4v6_act_table_entry table[L4C_IPV4V6_ACT_TABLE_SIZE];
    kal_uint32 max_activation_count;
} l4c_gprs_ipv4v6_act_struct;


typedef struct
{
/*************************************************************************/
/* Below context are placed in the front of L4C context                  */
/* to increase immediate offset access , to reduce ROM size              */
/* Please KEEP the position for the following frequent used variables    */
/*************************************************************************/
   kal_bool    route_thru_lmmi;
   kal_uint8 route_thru_lmmi_user;
   kal_bool retry_cc;
   kal_bool retry_ss;
   kal_uint8   retry_count;   
   kal_uint8 retry_src_id; //src_id that you want to retry
   kal_uint8 cfun_state;

   l4c_source_id_enum   smu_user;
   l4c_source_id_enum   ss_user; 
   l4c_source_id_enum   eq_user;
   l4c_source_id_enum   rac_user;
   l4c_source_id_enum   phb_user;
#ifdef __MOD_TCM__
   l4c_source_id_enum   tcm_user;
#endif 

   kal_uint16   smu_current_action; /*l4c_action_enum*/
   kal_uint16  ss_current_action;  
   kal_uint16  eq_current_action;
   kal_uint16   rac_current_action;
   kal_uint16   phb_current_action;
#ifdef __MOD_TCM__
   l4c_action_enum   tcm_current_action;
#endif

   event_scheduler            *event_scheduler_ptr;

    /* ============================== action ============================== */
   kal_uint16  cc_current_action[MAX_SOURCE_NUM];  /*l4c_action_enum*/
   l4c_state_enum   cc_state[MAX_SOURCE_NUM];           /* l4c_state_enum */
   kal_uint16	sms_current_action[MAX_SOURCE_NUM];   /*l4c_action_enum*/
   //l4c_sub_state_enum   cc_sub_state[MAX_SOURCE_NUM];       /* l4c_sub_state_enum */
    /* ============================== ~action ============================== */   

    /* ============================== timer ============================== */    
   eventid                    event_id[8];              /* 0: keypad
                                                           1: gprs
                                                           2: gprs
                                                           3: retry
                                                           4: hz 
                                                           5: dialup
                                                           6: RING repeat timer
                                                           7: SAT redial duration timer */
    /* ============================== ~timer ============================== */  


   /* ss_parameter is using to save local parameter for ss retry using*/
   l4c_parameter_struct       ss_parameter; //MAUI_02354954 SS doesn't support concurrent multi-chnnel request
   /* cc_parameter is using to save local parameter for cc retry using*/
   l4c_parameter_struct       cc_parameter[MAX_SOURCE_NUM];

   /* we using this local context to save local parameter if we have to send one message, 
   but we have to do another thing before it, we have to save in this parameter*/
   l4c_parameter_struct       parameter[MAX_SOURCE_NUM];

/***********************************************************************/
/* Above context are placed in the front of L4C context                */
/* to increase immediate offset access , to reduce ROM size            */
/* Please try to KEEP the position for these frequent used variables   */
/***********************************************************************/

#ifdef __SAT__ //MAUI_02354954
   /* cc_peer_buf is using to save peer buffer for retry using*/
   l4c_parameter_struct       cc_peer_buf; //for cc now, it is used by SAT call only
#endif

#if defined(__TCPIP_OVER_CSD__)
   l4c_parameter_struct       csd_parameter;
#endif

#ifdef __RSAT__ //MAUI_02354954
    /* parameter_sat is using to save SAT cc/ss/ussd/sms/dtmf local parameter using*/
   l4c_parameter_struct       parameter_sat;
#endif

   /* this flag using to chek the retry mechineism working or not. so that we can ignore some message or clear*/
   /* the queued message for retry */
   
   /*retry timer timeout, sending queued message, rety_ongoing_flag will set as TRUE until receiving cnf*/
   kal_bool    cc_retry_ongoing_flag;
   /* keep the retry count value */
   kal_uint8 mo_call_id;
   
//#if !defined(__PHB_APPROVE_BY_MMI__)
   kal_uint8 mo_call_ecc_info;
//#endif

   l4c_ussd_version_enum ussd_version; //MO USSD change phase retry

#ifdef __ECC_RETRY_ENHANCEMENT__
   kal_uint8 enhanced_ecc_id; //MAUI_02554068
#endif
    /* ============================== ~queue/retry ============================== */  

    /* ============================== other context ============================== */     
//   rmmi_context_struct        *rmmi_ptr;

/*#ifdef __HOMEZONE_SUPPORT__   
   l4c_hz_context_struct *hz_ptr;											 
#endif*/
    /* ============================== ~other context ============================== */ 

    /* ============================== flag ============================== */
   /* this flag chek if rac is actived tru or fale , we can initila submodule, and can dial ECC call*/
#ifdef __MOD_TCM__
   /* keep the value of  GPRS PDP active form NW with auto answser mode */
   kal_bool    tcm_auto_answer;
#endif //mtk02285, 201003, 6251_ram
   /* this flag using to identify the power on procedure with finish indcation, we can use it to chek */
   /* if uper layer like to write sim as power on not finish, in reg_ind if power on not finish we need*/
   /* inform MMI with attach_ind. however, if power on finish, we any reg_ind we will using reg_ind to*/
   /* inform MMI with the registed stste changed. */
   kal_bool    power_on_not_finish;
   /* this flag is using for RMMI setting some equiement value but route to LMMI , it means we LMMI tigger*/
   /* the set request , but we have to inform RMMI and afer confirm we should clear L4C state to default.*/

   /* this flag using for detect the plmn sel cnf and reg_ind message and cehck if it is first camp on this PLMN*/
   /* if true, CFU for CPHS to and SMS memory available message may be send out to NW */
   kal_bool    first_camp_on;
   /* this flag is using for SIM restart and wthin SIM_ERROR_IND with cause , we got to keep this value and when*/
   /* security cnf will perform another proceure*/
   kal_bool    sim_refresh;
   /* this flag using to make sure SIM has receive detach form NW when SIM refesh procedure is running*/
   //kal_bool    sim_reg_state_received;
   /* This flag using to make sure SIM has read all reg required data and can be trigger RAC to reg*/
   //kal_bool    sim_security_received;   
   /**/
   //kal_bool    ph_reset;
   
   kal_bool   mt_call_incoming; //mtk00468 add for remember one mt call coming , any action should be response as command conflict
   kal_bool    adc_flag; /* using for active or deavtice EM ADC indication*/
   #if defined(__MMI_FMI__)  
   kal_bool    keypad_event_flag;/* using for engineer mode for keypad event use*/
   #endif
   
   /* sim_detected: sim inserted information after SMU start cnf 
      KAL_TRUE : SIM is inserted and SMU has loaded security information and SML
      KAL_FALSE: otherwise
   */
   kal_bool    sim_detected;
   kal_uint16  sim_error_cause; 
   
   kal_bool     phb_ready_flag;
   kal_bool     sms_ready_flag;
   kal_uint8    csm_state; //l4c_csm_state_enum
   kal_uint8    evdl_mode; // default valude: 1, event downlaod is trigered by modem
   
#ifdef __MOD_TCM__
   kal_bool     tcm_ready_flag;
#endif //mtk02285, 201003, 6251_ram
   #if defined(__MMI_FMI__) && !defined(__UCM_SUPPORT__)
   kal_bool	mmi_ready_flag;   
   #endif
      
   kal_bool 				sms_da_fdn_check; //using to check if da is approve now   
       
   kal_bool   call_exist; /*copy from L4CCSM_CC_CALL_INFO_IND -> call_exist*/
  // kal_bool   ps_abm_act; /*ABM_ACT by PS: TRUE or FALSE*/
   kal_bool   csd_end_connect_race_flag; //this flag is using to avoid when we ever send connect indicatino to MMI
#ifdef __UCM_SUPPORT__   
   kal_uint8  data_call_end_race_flag; //mtk01616_090408:this flag is used to handle ath_req to end data call after call_setup_cnf
   kal_bool  csd_call_end; //MAUI_01801045 L4C local disconnects CSD call
#endif   
   // but before we send it to MMI , END key press. MMI will send ATH to end call
   
   kal_bool  call_alert; /*True: play alert tone, stop it when call connect or call release*/
   //kal_bool  cipher_ind; //from l4csmu_mmrr_ready_ind, true: enable , false: disable
   kal_bool sim_poweroff; //ture: sim power off finished  
   kal_bool sms_init_sent; //true: MSG_ID_L4CSMSAL_INIT_REQ is sent  
#ifdef __MOD_TCM__   
   kal_bool gprs_connection_timeout; /* Johnny 2006/01/12: KAL_TRUE: gprs connection timeout but can not dereg (due to command conflict) */
#endif //mtk02285, 201003, 6251_ram
   //ALPS00029231 l4c_sat_ussr_enum represents the different SAT USSR scenarios
   l4c_sat_ussr_enum sat_ussr_flag; //mtk01616 070325 :for SAT_USSD ,get ussr fac
   kal_bool mmrr_ready_flag;//mtk01616 070426:mmrr_ready_flag is used only in rac_act_cnf_hdlr to check whether mmrr_ready_ind is already received
   kal_uint8 sat_redial_flag; //mtk01616_100223: check if necessary to do sat redial 
   kal_uint32 sat_redial_duration; //mtk01616_100223: keep sat redial duration (time unit : ms , 0 if duration not present)
   #ifdef __TCPIP__ /* ABM */ 
   kal_uint8 disc_dialup_req;
   #endif
   #if !defined(__PHB_APPROVE_BY_MMI__) && (!defined(__MMI_FMI__) || defined(__ECUSD_SUPPORT__))
   kal_bool phb_approve_ussd; //mtk02508_090304: set if phb is approving ussd
   #endif
    /* ============================== ~flag ============================== */
         
    /* ============================== value ============================== */
   /* save line number here so that l4c can prepare setup call type to CC according to this value*/
   /* this value is set as default line 1 , but will be change when change line form MMI and keep */
   /* right here.*/
   kal_uint8   line_num;     /*Line_1 Line_2*/

   /* because we will active rac and smu at the same time, therefore, we have to keep*/
   /* if smu being active so that we can perform normal plmn selection. */
   kal_uint8   sms_num[MAX_SOURCE_NUM];
   kal_uint8   smu_activated;/* L4C_SMU_INACTIVE, L4C_SMU_ACTIVE,L4C_SMU_ACTIVATE_FAIL*/

   kal_uint8   sms_abort_ongoing;
   #if defined(__MMI_FMI__) 
   kal_uint8   keypad_press_timer; //mtk00468 add for ckpd to simulate driver kedpad event using. 
   #endif

#ifdef __AUTO_CALL_REJECTION__
   kal_uint8  present_call_id; 
#endif
   kal_uint8  mt_call_id; //keep the imcoimg call ID, this is make sure when release by NW we can clear the mt_call_imcoming flag correct
   kal_uint8  crss_opcode;//MMI may using chld to accept one mt call , we need to keep it so that in crss cnf we can clear the above flag

#if defined(__VTS_LATE_RESPONSE__)
   kal_uint8 dtmf_call_id;
#endif

   /* keep the CLI vlaue here so that we can fill in setup message using this variable CLIR_INVOKE,
   CLIR_SUPPRESS, CLIR_AUTO*/
   kal_uint8   clir_flag; 
#ifdef __MOD_TCM__     
   kal_uint32         gprs_em_send_data_size[3];   /* EM mode, GPRS send data left size */ //mtk02285, 20110506 //mtk00714 w0634 
   l4c_source_id_enum gprs_em_send_data_srcid[3];  /* EM mode, GPRS send data src id    */ //mtk02285, 20110506
#endif //mtk02285, 201003, 6251_ram   

//   kal_uint8     ceer_report[MAX_CEER_REPORT_LEN];//this array save the last unsuccessful call 
   kal_uint16     ceer_report;
   //setup or in call modification , the last call release.
   
   void	    *sms_da_number;
   //mtk01616_070910
////   l4c_concat_sms_buff_struct concat_sms[MAX_CONCAT_SMS_NUM];

   //kal_uint16  ps_abm_current_action;  /* L4C_NO_ACTION, ABM_ACT, ABM_DEACT*/ //mtk02285, 201003, 6251_ram
   //l4c_sub_state_enum   abm_sub_state;       /* l4c_sub_state_enum */

    #if defined(__MMI_FMI__) 
   kal_uint8  ekey_mode; /* 20040510 mtk00714 add +EKEY for Joseph: to enable testing +CKPD from Catcher during dial-up*/
    #endif

   kal_uint8 waiting_call_id; /*waiting call id for open/close waiting tone without MMI*/

#if defined(__MOD_TCM__) && defined(__INT_PDP_CONTEXT_ON__)
   //bit7-> 0: not exist, 1: exist
   //bit6 -bit0 -> profile id from abm
   #ifndef __APP_SECONDARY_PDP_SUPPORT__
   kal_uint8  pdp_context_id[MAX_INT_PDP_CONTEXT];
   #else
   kal_uint16  pdp_context_id[MAX_INT_PDP_CONTEXT];
   #endif
#endif   
   			
   #ifndef __CLOG_STORAGE_BY_MMI__
   kal_uint8 last_number_seq; //if MAX_PHB_LN_ENTRY > 20, check seq_id = 1  
   #endif
   l4_number_struct l4cphb_approve_req_string;    

   cipher_ind_msg_struct cipher_ind_msg; /* Johnny: L4C will save cipher_ind_msg additionally and send it to MMI after CALL_RING_IND */   
   
#ifdef __MOD_TCM__  // mtk02126 wrap pending_latest_auto_attach in __MOD_TCM__ MAUI_02420439
   /* Johnny:
      if SET_GPRS_CON_TYPE command conflict with SET_GPRS_CON_TYPE,
      L4C will return TRUE instead of FALSE but pending the latest auto_attach
      and re-do it when clear SET_GPRS_CON_TYPE
      
      l4c_gprs_connect_type_enum =>
      L4C_WHEN_NEEDED,
      L4C_ALWAYS,
      L4C_GPRS_CONN_TYPE_UNKNOWN (init value)
   */
   kal_uint8 pending_latest_auto_attach;   

   //kal_uint8 cid_used_by_ppp;   
   kal_uint8 disc_ppp_src_id;
#ifdef __PS_DIALUP__   
   kal_uint16 ps_dialup_port[MAX_EXT_PDP_CONTEXT+1]; //L4CPPP_FB_2   
#endif

   l4c_gprs_status_enum l4a_ps_gprs_last_status; 
   kal_uint8 l4a_ps_gprs_last_cell_support_egprs;
   kal_uint8 l4a_ps_gprs_last_data_speed_support;
   kal_uint8 l4a_ps_gprs_last_data_bearer_capability;
#endif //mtk02285, 201003, 6251_ram
   
#if defined(__DEACT_ABORT_CGACT__) && defined(__MOD_TCM__) //mtk02285, 201003, 6251_ram
    kal_bool    ext_pdp_two_ongoing_deact;  /* Only ONE abort is allowed; otherwise, this will be an array */
    kal_bool ext_pdp_activating[MAX_EXT_PDP_CONTEXT+1];
    kal_uint8 ext_pdp_src_id[MAX_EXT_PDP_CONTEXT+1];
#endif //mtk02285, DUMA00206863, abort_cgact_activation
    /*mtk80396, Add for EM PS conformance test Menu, read from NVRAM when power on*/

    /* ============================== ~value ============================== */

    /* ============================== other ============================== */

#ifdef __IRDA_SUPPORT__
   l4c_data_mode_enum      uart_data_mode;
#endif

 #if  defined(__FWP_NC_LAI_INFO__)
	kal_uint8 is_cell_lock_call;
#endif

   kal_bool power_on_pin_check;
   kal_bool data_signal_activate; /*indicate the CS signal path is setup or not for a data call*/
    kal_uint8 max_retry_count;

#if 0 //__CTM_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    kal_uint8 rat_mode;
#if defined(__NAS_RAT_PREFER__) || defined(__UMTS_FDD_PREFER__)
    l4c_prefer_rat_enum prefer_rat;
#endif
#ifdef __CSD_FAX__
    kal_uint8 fax_src_id; //temp solution for fax
#endif /*__CSD_FAX__*/

kal_uint8 single_sim_inserted_status; //first updated by reset sim result

#if defined(__GEMINI__) && !defined(__MMI_FMI__) 
rmmi_edsim_set_mode_state_enum dual_sim_mode_setting_command;
#endif /* __GEMINI__ but no __MMI_FMI__ */

#ifdef __AUTO_CALL_REJECTION__
kal_uint8 mt_call_approval;
#endif

    kal_bool ongoing_csd_dialup;	// MAUI_02284187, mtk02285
    kal_bool disallow_gprs_and_csd; // karen

#ifdef __NBR_CELL_INFO__
cell_info_reg_table_struct cell_info_reg_table[10];  
kal_uint8 cell_info_reg_index;		
#endif
	
    kal_bool sub_modules_ready; 
	

   /* [DUMA00005999], mtk02480
     *   has_deregistered is set to KAL_TRUE while we have dereg network or attach limited service only
     *   if has_deregistered=TRUE, we have to do reg_req before send PLMN_SEARCH_REQ  
     */
    kal_bool has_deregistered;	  

    kal_uint8 csq_level; //rx_level, mtk02285
    kal_uint8 ber;
    kal_int32 rssi_in_qdbm;
    kal_int32 RSCP_in_qdbm;
    kal_int32 EcN0_in_qdbm;

#ifdef __MMDC_TYPE1_DUAL_LOAD__
    kal_uint8 cur_cell_type;
    kal_uint8 cur_rr_state;
    kal_uint8 cur_act;
#endif

l4c_data_bearer_capablility_enum max_data_bearer_capa;//hspa_mmi_h2
	
    /* ============================== ~other ============================== */
/* For GPRS_FLC_UT MAUI_02419672 mtk02126 */
#if !defined(__MTK_TARGET__) && defined(__RMMI_UT__) && defined(__MOD_TCM__)
  lcd_lqueue *gprs_flc_queue;
#endif

//evshed_create, mtk02285, 20110328: remove base timer

#if defined(__OP01__)
    l4c_nw_sysconfig_struct *nw_sysconfig;
#endif

#if defined(__SYSSEL_SUPPORT__)
    l4c_nw_syssel_struct *nw_syssel;
#endif

    /* the TON of MO call number in SETUP request to CSM. between 128~255
       Refers to TS 24.008 10.5.4.7 the octet 3 of Called party BCD number IE */
    kal_uint8 cc_ton;

#ifdef __GEMINI_3G_SWITCH__
    sim_interface_enum cur_3g_switch_map; /* store the mapping to physical SIMs*/
#endif
    kal_uint8 is_valid_ef_rat_mode;
    kal_uint8 ef_rat_mode;

    kal_uint8 file_changed_map;

    kal_uint32 em_cell_lock_mode; /* Context for L4C EM cell lock feature, refer to em_cell_lock_mode_enum */

#if defined(__DUAL_TALK_MODEM_SUPPORT__)
    l4c_source_id_enum l1aud_spc_src_id;
#endif

#if defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__)
    kal_uint8 fast_dormancy_mode; //0: disable, 1: enable
    eventid fd_event;
    kal_bool is_screen_on; //0: off, 1: on
    kal_uint8 fd_timer_counter;
    single_pdp_call_history_info_struct fd_pdp_table[PS_TOT_CONTEXT];
    kal_bool scri_has_sent;
    kal_uint8 fd_monitor_tick;
    kal_uint8 fd_retry_count;
    kal_bool fd_fop_received;
    kal_bool need_resend;
#endif /* defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__) */

    kal_uint8 rf_freq_report_mode; //for gps desense
    kal_uint16 *tx_freq_tb; //pointer for 64-entry frequency table
    kal_bool mmi_info_received; //recipt flag of MSG_ID_L4CSMU_MMI_INFO_IND
    kal_uint8 ecc_category; //used for the next ATDE command
    kal_uint8 ecc_call_id; //used for telling MOD_LBS the roughly timing of ecc call

    umts_rrc_state_enum rrc_state;

    /* below informat are for thermal usage */
    l4c_source_id_enum ethermal_src;
    kal_int8 rf_tx_power; //tx power: -50 ~ 24, -127: invalid
    kal_int16 rf_temperature;
#ifdef __PPE_INTERFACE_SUPPORT__
    single_pdp_call_history_info_struct pdp_data_count_table[PS_TOT_CONTEXT];
#if 0
/* under construction !*/
#endif    
#endif

    /* below are used to save parameters of CRSM */
    kal_bool phb_update_from_crsm;      // update PHB record if CRSM is used
    
} l4c_context_struct;


/* mtk01616_100419: L4C common context is created for RAM size optimization in Gemini platform
   In Gemini, there will be two L4C context. However, some context can be shared in SIM1/SIM2.
   Now we create L4C common context,there will be only one common context in Gemini 
   For context can be shared between SIM1/SIM2, please try to move to L4C common context. */
typedef struct
{
   kal_uint32 cpi_mode;
   kal_uint32 ps_conf_test_profile;
   kal_uint8 ps_conf_test_mode;
   kal_bool wap_init_flag;
   kal_uint8 flightmode_state; //l4cmmi_flightmode_enum

   /* 030618 mtk00468 add handle the power on mode in different mode , we have to keep this value.*/
   /* when mode is not normal power , after uem_startup_cnf we dont need to initial other module*/
   kal_uint8   poweron_mode; /* POWER_ON_KEYPAD  0 POWER_ON_ALARM 1 POWER_ON_CHARGER_IN  2 */
   kal_uint8 poweroff_retry; // power off timer retry count
   kal_uint8 usb_app; //remember usb app is USB_SWITCH_PORT_APP_DATA or USB_SWITCH_PORT_APP_DEBUG
#ifdef __IP_NUMBER__
	  kal_uint8 ip_string[21];
#endif 
#ifdef __GEMINI__
    kal_uint8 dual_sim_mode_setting;
    kal_uint8 dual_sim_inserted_status;
    kal_bool during_sim_mode_switch;
    kal_bool is_dual_sim_ind_sent;
#endif
#ifdef __AGPS_CONTROL_PLANE__
    module_type agps_cp_active_module;
#endif
#ifdef __GEMINI_3G_SWITCH__
    kal_uint8 cur_3g_capability; /* bitmask, store the 3G capability setting*/
#endif
#ifdef __ETWS_SUPPORT__ 
    kal_uint8 etws_setting;
#endif
#ifdef __ECALL_SUPPORT__
    kal_bool l4c_use_tnum;
    kal_bool l4c_use_rnum;
    l4_addr_bcd_struct l4c_tnum; 
    l4_addr_bcd_struct l4c_rnum;
#endif
#if defined(__IPV4V6__) && defined(__IPV6__)
#ifdef __DEACT_ABORT_CGACT__
    kal_uint8 v4v6_act_ptr_init_cid;    /* duplicate from v4v6_act_ptr, because need to be used after free table */
#endif
    l4c_gprs_ipv4v6_act_struct* v4v6_act_ptr;
    kal_bool ipv4v6_fallback_enable;
    kal_bool ipv4v6_fallback_v4_first;
#endif

kal_uint8 rac_activated; //bit-map for GEMINI
kal_bool uem_activated;
kal_bool  is_wait_for_audio_off;

}l4c_common_context_struct;

/* -------------------------------------------------------
  * L4C Root is the GEMINI controller in Dual SIM project. 
  * Control the power on/power off/SIM mode switching procedures.
  * -------------------------------------------------------*/
#if defined(__GEMINI__)
typedef struct
{
    kal_bool has_update_sim_statust;
    kal_uint8 root_src_id;
    kal_uint8 efun_state;
#if defined(__L4C_GEMINI_BT_HF__)
    kal_uint8 last_dialed_sim;
#endif
#if defined(__SINGLE_AP_DUAL_MODEM__)
    /* bitmap representing the power-on mode for each sim
       0x01: SIM1 protocol is powered-on
       0x02: SIM2 protocol is powered-on
       0x04: SIM3 protocol is powered-on
       0x08: SIM4 protocol is powered-on
    */
    kal_uint8 sim_support_mode;
#endif
#if defined(__SIM_ME_LOCK__)
    /* below context is for link_SML */
    smu_pending_password_id_enum root_pending_password[MAX_SIM_NUM];
#endif
}l4c_root_context_struct;
#endif


extern l4c_context_struct *l4c_ptr_g;
extern l4c_common_context_struct *l4c_comm_ptr_g;
extern module_type l4c_current_mod_id;
extern	l4c_context_struct l4c_cntxt_g[L4_MAX_SIM_NUM];
/*#ifdef __HOMEZONE_SUPPORT__
extern	l4c_hz_context_struct l4c_hz_cntxt_g[L4_MAX_SIM_NUM];
#endif*/
#if defined(__GEMINI__)
extern l4c_root_context_struct l4c_root_cntxt_g;
extern l4c_root_context_struct *l4c_root_ptr_g;
#endif	    


#endif /* l4c_context.h */


