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
 * TCM2L4C_STRUCT.H
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file describes the common struct of TCM and L4C.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/

#ifndef _TCM2L4C_STRUCT_H
#define _TCM2L4C_STRUCT_H

//------------------------------ suggest Add ------------------------------
//#include "kal_non_specific_general_types.h"
#include "l4c2tcm_func.h"
#include "mcd_l3_inc_gprs_struct.h"
#include "l3_inc_local.h"
//#include "app_ltlcom.h"
//#include "l4c_common_enum.h"
#include "l4c2tcm_struct.h"

//------------------------------ suggest Add ------------------------------
#include "kal_general_types.h"
#include "ps_public_struct.h"
#include "ps_public_enum.h"

/* __APP_SECONDARY_PDP_SUPPORT__ */
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 context_id;
    kal_uint8 src_id;
} tcm_pdp_reactivate_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 context_id;
    kal_uint8 src_id;
    kal_bool cause2_present ; // if network has cause_2 value in ACTIVATE_PDP_CONTEXT_ACCEPT
    kal_uint16 cause2 ; // just relay the PDP accept cause_2 value, ex: PDP_TYPE_IPV4_ONLY_ALLOWED, 
                                 // PDP_TYPE_IPV6_ONLY_ALLOWED, SINGLE_ADDR_BEARERS_ONLY_ALLOWED
    kal_bool ip_addr_present; // If NW assign IPv4 address or not
    //#ifdef __IPV6__
    kal_bool ipv6_addr_present; // If NW assign IPv6 address or not
    //#endif // #ifdef __IPV6__
    kal_uint8 ip_addr[4]; // IPv4 address content
    //#ifdef __IPV6__
    kal_uint8 ipv6_addr[16]; // IPv6 address content
    //#endif // #ifdef __IPV6__
    kal_uint8 pri_dns_addr[4];
    kal_uint8 sec_dns_addr[4];    
    kal_uint8 additional_para_type; //tcm_pdp_activate_req_additional_para_type_enum
    kal_uint32 additional_para_content; // __HSPA_DATA_PATH_OPT__
    kal_uint8 pdp_type; //pdp_addr_type_enum // SATe 
    l4c_qos_struct qos;  // SATe 
   /* following are for __APP_SECONDARY_PDP_SUPPORT__ */
    kal_bool  is_qos_fulfilled; // Flag indicates whether the requested QoS is fulfilled by established bearer
    qos_struct neg_qos;
    //#ifdef __IPV6__
    kal_bool ipv6_dns1_present; // If NW assign IPv6 DNS1 address or not
    kal_bool ipv6_dns2_present; // If NW assign IPv6 DNS2 address or not
    kal_uint8 ipv6_dns1[16]; // IPv6 DNS1 address content
    kal_uint8 ipv6_dns2[16]; // IPv6 DNS1 address content
    // TODO: if network assign more than two IPv6 DNS server addresses?
    //#endif // #ifdef __IPV6__
} tcm_pdp_activate_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 context_id;
    kal_bool is_rejected_by_nw; // if this PDP is rejected by NW using SM peer msg, KAL_TRUE, else, KAL_FALSE
    kal_uint16 cause; /* reject cause (also used for cause_2) */
    kal_uint8 src_id;
    kal_uint8 additional_para_type; //tcm_pdp_activate_req_additional_para_type_enum
    kal_uint32 additional_para_content; // __HSPA_DATA_PATH_OPT__
   /* following are for __APP_SECONDARY_PDP_SUPPORT__ */
    kal_uint8 linked_context_id; //0xFF: means REJECT, otherwise replace the context id and send ACTIVATE_CNF
    kal_bool  is_qos_fulfilled; // Flag indicates whether the requested QoS is fulfilled by established bearer
} tcm_pdp_activate_rej_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 context_id;
    kal_uint8 src_id;
} tcm_pdp_activate_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 context_id;
    kal_uint8 src_id;
    qos_struct new_neg_qos;
} tcm_pdp_modify_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 context_id;
    kal_uint16 cause; /* reject cause*/
    kal_uint8 src_id;
} tcm_pdp_modify_rej_struct;

// __GPRS_BEARER_REPORT_NEGOTIATED_QOS__
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 context_id;
    qos_struct new_neg_qos;
} tcm_pdp_modify_ind_struct;
// ~ __GPRS_BEARER_REPORT_NEGOTIATED_QOS__

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 context_id;
    kal_uint8 src_id;
} tcm_pdp_deactivate_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 context_id_list[11];
    kal_uint16 cause; /* deactivation cause*/
    kal_uint8 src_id;
} tcm_pdp_deactivate_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 current_action; /* CurrentAction*/
    kal_uint8 status; /* Status*/
    cell_info_struct cell_info; /* CELL INFO STRUCTURE*/
    kal_uint8 cause; /* Cause*/
    kal_uint8 src_id;
} tcm_mobility_status_ind_struct;

/* for __APP_SECONDARY_PDP_SUPPORT__ */
typedef struct {
    LOCAL_PARA_HDR
    kal_bool	result; // result
    kal_uint16	err_cause;  // error cause
    kal_uint8	context_id; // context ID
} tcm_pdp_qos_tft_modify_rsp_struct;
/* ~ for __APP_SECONDARY_PDP_SUPPORT__ */

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 context_id;
    kal_uint8 event_id;  //mmi_event_enum
    kal_uint8 pdp_addr_len;
    kal_uint8 pdp_addr_type;
    kal_uint8 pdp_addr[MAXIMUM_POSSIBLE_ADDR_LEN];
    kal_uint8 src_id;
} l4ctcm_ps_event_report_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
	kal_uint8 valid_contexts;
	kal_uint8 context_id[GPRS_MAX_PDP_SUPPORT];
	kal_uint8 bearer_capability[GPRS_MAX_PDP_SUPPORT];	
} l4ctcm_bearer_capability_ind_struct; //hspa_mmi_h2

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 context_id;
    kal_uint8 event_id; /* event kind*/
    kal_uint8 pdp_addr_len;
    kal_uint8 pdp_addr_type;
    kal_uint8 pdp_addr[16];
    kal_uint8 src_id;
} tcm_event_rep_ind_struct;


typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 result;
    kal_uint16 error_cause; /* erica 20060320 */
} l4ctcm_set_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool	result;
    kal_uint16	cause;
} l4ctcm_set_acl_mode_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool result;
    kal_uint16	cause;
    kal_uint16	start_index;
    kal_uint16	num_of_entries;
    kal_bool	       more_flag;
    tcm_acl_entry_struct	acl_list[TCM_MAX_PEER_ACL_ENTRIES];
} l4ctcm_get_acl_entries_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool result;
    kal_uint16	cause;
} l4ctcm_add_acl_entry_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool result;
    kal_uint16	cause;
} l4ctcm_set_acl_entry_cnf_struct;
typedef struct
{
    LOCAL_PARA_HDR
    kal_bool result;
    kal_uint16	cause;
} l4ctcm_del_acl_entry_cnf_struct;
	
typedef l4ctcm_set_cnf_struct l4ctcm_start_cnf_struct;
typedef l4ctcm_set_cnf_struct l4ctcm_set_pri_pdp_info_cnf_struct;
typedef l4ctcm_set_cnf_struct l4ctcm_set_sec_pdp_info_cnf_struct;
typedef l4ctcm_set_cnf_struct l4ctcm_set_qos_info_cnf_struct;
typedef l4ctcm_set_cnf_struct l4ctcm_set_eqos_info_cnf_struct;
typedef l4ctcm_set_cnf_struct l4ctcm_set_ppp_auth_info_cnf_struct;
typedef l4ctcm_set_cnf_struct l4ctcm_set_gprs_account_info_cnf_struct;
//typedef l4ctcm_set_cnf_struct l4ctcm_set_gprs_statistics_info_cnf_struct;
typedef l4ctcm_set_cnf_struct l4ctcm_undefine_pdp_info_cnf_struct; //mtk00714 w0637: AT definition
typedef l4ctcm_set_cnf_struct l4ctcm_set_config_option_cnf_struct; 
//typedef l4ctcm_set_cnf_struct l4ctcm_enter_data_mode_cnf_struct; //mtk02285, 20110322
typedef l4ctcm_set_cnf_struct l4ctcm_set_ppp_auth_cnf_struct;   // mtk02126 define this struct for MSC to recognize MAUI_02420720

typedef l4ctcm_set_cnf_struct l4ctcm_set_msq_mode_cnf_struct ;  /* __MEDIATEK_SMART_QOS__ */  
typedef l4ctcm_set_cnf_struct l4ctcm_set_msq_entry_cnf_struct ; /* __MEDIATEK_SMART_QOS__ */  

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 context_id;
    kal_uint8 result;
    kal_uint16 error_cause;
} l4ctcm_enter_data_mode_cnf_struct; //mtk02285, 20110322

typedef struct {
    LOCAL_PARA_HDR 
    kal_uint8 query_id;
} l4ctcm_get_gprs_statistics_info_req_struct;

typedef struct {
    LOCAL_PARA_HDR 
    kal_uint8 query_id;
    kal_uint32 total_rx_data;
    kal_uint32 total_tx_data;
    kal_uint32 last_rx_data;
    kal_uint32 last_tx_data;
} l4ctcm_get_gprs_statistics_info_rsp_struct;

typedef struct {
    LOCAL_PARA_HDR 
    kal_uint8 reset_id;
} l4ctcm_set_gprs_statistics_info_req_struct;

typedef struct {
    LOCAL_PARA_HDR  
    kal_uint8 reset_id;
} l4ctcm_set_gprs_statistics_info_cnf_struct;

#ifdef __TCM_UT__ // these messages are used for check L4CTCM callback functions
    typedef struct
    {
        LOCAL_PARA_HDR
        l4c_prim_pdp_info_list_struct l4c_prim_pdp_info_list;
    } tcm_ut_check_callback_l4ctcm_get_pri_pdp_info_struct;
    //MSG_ID_TCM_UT_CHECK_CALLBACK_L4CTCM_GET_PRI_PDP_INFO, l4c_prim_pdp_info_list_struct
    
    typedef struct
    {
        LOCAL_PARA_HDR
        l4c_gprs_statistics_info_struct l4c_gprs_statistics_info;
    } tcm_ut_check_callback_l4ctcm_get_gprs_statistics_info_struct;
    //MSG_ID_TCM_UT_CHECK_CALLBACK_L4CTCM_GET_GPRS_STATISTICS_INFO, l4c_gprs_statistics_info_struct

    // __GPRS_BEARER_REPORT_NEGOTIATED_QOS__
    typedef struct
    {
        LOCAL_PARA_HDR
        qos_struct neg_qos;
    } tcm_ut_check_callback_l4ctcm_query_neg_qos_info_struct;
    //MSG_ID_TCM_UT_CHECK_CALLBACK_L4CTCM_QUERY_NEG_QOS_INFO,    
    // ~ __GPRS_BEARER_REPORT_NEGOTIATED_QOS__

    #ifdef __TCPIP__ /* ABM */
    typedef struct
    {
        LOCAL_PARA_HDR
        l4c_ext_gprs_statistics_info_struct l4c_ext_gprs_statistics_info;
    } tcm_ut_check_callback_l4ctcm_get_ext_gprs_statistics_info_struct;
    //MSG_ID_TCM_UT_CHECK_CALLBACK_L4CTCM_GET_EXT_GPRS_STATISTICS_INFO, l4c_ext_gprs_statistics_info_struct
    #endif

    #ifdef __TCM_EXT_CALL_HISTORY_SUPPORT__
    typedef struct
    {
        LOCAL_PARA_HDR
        l4c_ext_gprs_call_history_info_struct l4c_ext_gprs_call_history_info;
    } tcm_ut_check_callback_l4ctcm_query_ext_gprs_history_struct;
    //MSG_ID_TCM_UT_CHECK_CALLBACK_L4CTCM_QUERY_EXT_GPRS_HISTORY, l4c_ext_gprs_call_history_info_struct
    #endif
    
    typedef struct
    {
    	LOCAL_PARA_HDR
            l4c_sec_pdp_info_list_struct l4c_sec_pdp_info_list;
    } tcm_ut_check_callback_l4ctcm_get_sec_pdp_info_struct;
    //MSG_ID_TCM_UT_CHECK_CALLBACK_L4CTCM_GET_SEC_PDP_INFO, l4c_sec_pdp_info_list_struct
    
    typedef struct
    {
        LOCAL_PARA_HDR
        tcm_packet_filter_struct mmi_packet_filter;
    } tcm_ut_check_callback_tcm_write_tft_struct;
    //MSG_ID_TCM_UT_CHECK_CALLBACK_TCM_WRITE_TFT, mmi_packet_filter_struct
    
    typedef struct
    {
        LOCAL_PARA_HDR
        l4c_tft_struct l4c_tft;
    } tcm_ut_check_callback_l4ctcm_set_tft_info_struct;
    //MSG_ID_TCM_UT_CHECK_CALLBACK_L4CTCM_SET_TFT_INFO, l4c_tft_struct
    
    typedef struct
    {
        LOCAL_PARA_HDR
        l4c_tft_struct l4c_tft;
    } tcm_ut_check_callback_l4ctcm_get_tft_info_struct;
    //MSG_ID_TCM_UT_CHECK_CALLBACK_L4CTCM_GET_TFT_INFO, l4c_tft_struct
    
    typedef struct
    {
        LOCAL_PARA_HDR
        l4c_qos_list_struct l4c_qos_list;
    } tcm_ut_check_callback_l4ctcm_get_qos_info_struct;
    //MSG_ID_TCM_UT_CHECK_CALLBACK_L4CTCM_GET_QOS_INFO, l4c_qos_list_struct
    
    typedef struct
    {
        LOCAL_PARA_HDR
        l4c_config_option_list_struct l4c_config_option_list;
    } tcm_ut_check_callback_l4ctcm_get_config_option_info_struct;
    //MSG_ID_TCM_UT_CHECK_CALLBACK_L4CTCM_GET_CONFIG_OPTION_INFO, l4c_config_option_list_struct
    
    typedef struct
    {
        LOCAL_PARA_HDR
        l4c_eqos_list_struct l4c_eqos_list;
    } tcm_ut_check_callback_l4ctcm_get_eqos_info_struct;
    //MSG_ID_TCM_UT_CHECK_CALLBACK_L4CTCM_GET_EQOS_INFO, l4c_eqos_list_struct
    
    typedef struct
    {
        LOCAL_PARA_HDR
        kal_uint16 val;
    } tcm_ut_check_callback_l4ctcm_encode_sdu_size_struct;
    //MSG_ID_TCM_UT_CHECK_CALLBACK_L4CTCM_ENCODE_SDU_SIZE, kal_uint16 val_ptr
    
    typedef struct
    {
        LOCAL_PARA_HDR
        kal_uint16 val;
    } tcm_ut_check_callback_l4ctcm_decode_sdu_size_struct;
    //MSG_ID_TCM_UT_CHECK_CALLBACK_L4CTCM_DECODE_SDU_SIZE, kal_uint16 val_ptr
    
    typedef struct
    {
        LOCAL_PARA_HDR
        kal_uint16 val;
    } tcm_ut_check_callback_l4ctcm_encode_bit_rate_struct;
    //MSG_ID_TCM_UT_CHECK_CALLBACK_L4CTCM_ENCODE_BIT_RATE, kal_uint16 val_ptr
    
    typedef struct
    {
        LOCAL_PARA_HDR
        kal_uint32 rate;
    } tcm_ut_check_callback_l4ctcm_decode_bit_rate_struct;
    //MSG_ID_TCM_UT_CHECK_CALLBACK_L4CTCM_DECODE_BIT_RATE, kal_uint32 rate_ptr
    
    typedef struct
    {
    	LOCAL_PARA_HDR
            kal_uint16 val;
    } tcm_ut_check_callback_l4ctcm_encode_transfer_delay_struct;
    //MSG_ID_TCM_UT_CHECK_CALLBACK_L4CTCM_ENCODE_TRANSFER_DELAY, kal_uint16 val_ptr
    
    typedef struct
    {
    	LOCAL_PARA_HDR
            kal_uint16 val;
    } tcm_ut_check_callback_l4ctcm_decode_transfer_delay_struct;
    //MSG_ID_TCM_UT_CHECK_CALLBACK_L4CTCM_DECODE_TRANSFER_DELAY, kal_uint16 delay_ptr
    
    typedef struct
    {
    	LOCAL_PARA_HDR
            kal_uint8 length; 
            kal_uint8 addr[100];
    } tcm_ut_check_callback_l4ctcm_get_pdp_addr_struct;
    //MSG_ID_TCM_UT_CHECK_CALLBACK_L4CTCM_GET_PDP_ADDR, kal_uint8 length, kal_uint8 addr[100]
    
    typedef struct
    {
    	LOCAL_PARA_HDR
            kal_uint8 total_context[100]; 
            kal_uint8 state_list[100];
    } tcm_ut_check_callback_l4ctcm_get_context_state_struct;
    //MSG_ID_TCM_UT_CHECK_CALLBACK_L4CTCM_GET_CONTEXT_STATE, kal_uint8 total_context[100], kal_uint8 state_list[100]
    
    typedef struct
    {
    	LOCAL_PARA_HDR
            kal_uint8 empty_gprs_prof_entry[100];
    } tcm_ut_check_callback_l4ctcm_get_empty_gprs_prof_struct;
    //MSG_ID_TCM_UT_CHECK_CALLBACK_L4CTCM_GET_EMPTY_GPRS_PROF, kal_uint8 empty_gprs_prof_entry[100]
    
    typedef struct
    {
    	LOCAL_PARA_HDR
            kal_bool is_chap;
    } tcm_ut_check_callback_l4ctcm_get_ppp_auth_struct;
    //MSG_ID_TCM_UT_CHECK_CALLBACK_L4CTCM_GET_PPP_AUTH, kal_bool is_chap
    
    typedef struct
    {
    	LOCAL_PARA_HDR
            kal_uint8 context_id;
    } tcm_ut_check_callback_l4ctcm_cmux_port_to_cid_struct;
    //MSG_ID_TCM_UT_CHECK_CALLBACK_L4CTCM_CMUX_PORT_TO_CID, kal_uint8 context_id

    typedef struct
    {
    	LOCAL_PARA_HDR

      /* TCM statistic data */
      kal_uint8 last_context_id;
      kal_uint32	total_rx_data;
      kal_uint32	total_tx_data;
      kal_uint32	last_rx_data;
      kal_uint32	last_tx_data;
      kal_bool     statistic_is_writing;		// if statistic is writing to nvram
      kal_bool     statistic_needs_update; 	// statistic needs to be updated
  
  
      /* TCM call history data */  
      kal_bool call_history_is_writing;  // if call history is writing to nvram
      kal_bool call_history_needs_update;  // if call history is needs to be updated
      kal_uint8 query_serial_number;
      kal_uint8 reset_serial_number;

      kal_uint32    call_history_last_ext_conn_duration[3]; // New Feature: Call History: need to remember the most recently activated (may still in active state) external PDP connection time in ticks (4.615ms)
      kal_uint32    call_history_ext_conn_last_update_tick[3]; // New Feature: Call Hisotry: need to remember when is the last time (in tick) we update the connection duration
  
      kal_uint64    call_history_total_ext_tx_data; // New Feature: Call History: need to remember total external PDP tx data in Bytes
      kal_uint64    call_history_total_ext_rx_data; // New Feature: Call History: need to remember total external PDP rx data in Bytes
      kal_uint64    call_history_last_ext_tx_data[3]; // New Feature: Call History: need to remember the most recently activated (may still in active state) external PDP tx data in Bytes
      kal_uint64    call_history_last_ext_rx_data[3]; // New Feature: Call History: need to remember the most recently activated (may still in active state) external PDP rx data in Bytes
      kal_uint64    call_history_total_ext_conn_duration; // New Feature: Call History: need to remember total external PDP connection time in ticks (4.615ms), if there are 3 active PDPs, 1 tick pass will be count as 3 ticks
  
      kal_uint64    call_history_ext_conn_last_update_tx_bytes[3]; // New Feature: Call Hisotry: need to remember the last tx bytes
      kal_uint64    call_history_ext_conn_last_update_rx_bytes[3]; // New Feature: Call Hisotry: need to remember the last rx bytes


    }tcm_ut_check_call_history_context_content_struct;

    typedef struct
    {
    	LOCAL_PARA_HDR

      /* TCM statistic data */
      kal_uint8 last_context_id;
      kal_uint32	total_rx_data;
      kal_uint32	total_tx_data;
      kal_uint32	last_rx_data;
      kal_uint32	last_tx_data;
      kal_bool     statistic_is_writing;		// if statistic is writing to nvram
      kal_bool     statistic_needs_update; 	// statistic needs to be updated
  
  
      /* TCM call history data */  
      kal_bool call_history_is_writing;  // if call history is writing to nvram
      kal_bool call_history_needs_update;  // if call history is needs to be updated
      kal_uint8 query_serial_number;
      kal_uint8 reset_serial_number;

      kal_uint32    call_history_last_ext_conn_duration[3]; // New Feature: Call History: need to remember the most recently activated (may still in active state) external PDP connection time in ticks (4.615ms)
      kal_uint32    call_history_ext_conn_last_update_tick[3]; // New Feature: Call Hisotry: need to remember when is the last time (in tick) we update the connection duration
  
      kal_uint32    call_history_total_ext_tx_data; // New Feature: Call History: need to remember total external PDP tx data in Bytes
      kal_uint32    call_history_total_ext_rx_data; // New Feature: Call History: need to remember total external PDP rx data in Bytes
      kal_uint32    call_history_last_ext_tx_data[3]; // New Feature: Call History: need to remember the most recently activated (may still in active state) external PDP tx data in Bytes
      kal_uint32    call_history_last_ext_rx_data[3]; // New Feature: Call History: need to remember the most recently activated (may still in active state) external PDP rx data in Bytes
      kal_uint32    call_history_total_ext_conn_duration; // New Feature: Call History: need to remember total external PDP connection time in ticks (4.615ms), if there are 3 active PDPs, 1 tick pass will be count as 3 ticks
  
      kal_uint32    call_history_ext_conn_last_update_tx_bytes[3]; // New Feature: Call Hisotry: need to remember the last tx bytes
      kal_uint32    call_history_ext_conn_last_update_rx_bytes[3]; // New Feature: Call Hisotry: need to remember the last rx bytes


    }tcm_ut_check_call_history_context_content_small_struct;


    typedef struct
    {
    	LOCAL_PARA_HDR
        kal_bool callback_func_return_value;
    }tcm_ut_check_callback_check_pdp_context_exist_or_during_activating_func_struct;
    // MSG_ID_TCM_UT_CHECK_CALLBACK_CHECK_PDP_CONTEXT_EXIST_OR_DURING_ACTIVATING_FUNC

    typedef struct
    {
    	LOCAL_PARA_HDR
        kal_bool callback_func_return_value;
        kal_uint8 valid_contexts;
        kal_uint8 context_id[GPRS_MAX_PDP_SUPPORT];
        kal_uint8 bearer_capability[GPRS_MAX_PDP_SUPPORT];
    }tcm_ut_check_callback_l4ctcm_get_bearer_capability_struct;
    // MSG_ID_TCM_UT_CHECK_CALLBACK_L4CTCM_GET_BEARER_CAPABILITY


#endif // ~ __TCM_UT__ // these messages are used for check L4CTCM callback functions

typedef struct
{
    LOCAL_PARA_HDR

    kal_uint8 query_id;

    kal_uint8      which_cid_is_last_cid;
    kal_uint64    call_history_total_ext_tx_data;
    kal_uint64    call_history_total_ext_rx_data;
    kal_uint64    call_history_last_ext_tx_data;
    kal_uint64    call_history_last_ext_rx_data;
    kal_uint64    call_history_total_ext_conn_duration_in_secs;
    kal_uint32    call_history_last_ext_conn_duration_in_secs;
    /*
    typedef struct
    {
        kal_uint8      which_cid_is_last_cid;
        kal_uint64    call_history_total_ext_tx_data;
        kal_uint64    call_history_total_ext_rx_data;
        kal_uint64    call_history_last_ext_tx_data;
        kal_uint64    call_history_last_ext_rx_data;
        kal_uint64    call_history_total_ext_conn_duration_in_secs;
        kal_uint32    call_history_last_ext_conn_duration_in_secs;
    }l4c_ext_gprs_call_history_info_struct;
    */
} l4ctcm_query_ext_gprs_history_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 reset_id;
} l4ctcm_reset_ext_gprs_history_cnf_struct;

#endif 


