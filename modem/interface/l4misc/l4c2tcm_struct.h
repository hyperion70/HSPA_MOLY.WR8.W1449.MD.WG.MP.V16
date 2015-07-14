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
 * L4C2TCM_STRUCT.H
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

#include "ps_public_struct.h"

#ifndef _L4C2TCM_STRUCT_H
#define _L4C2TCM_STRUCT_H

//------------------------------ suggest Add ------------------------------
#include "l4c2abm_struct.h"
//#include "kal_non_specific_general_types.h"
//#include "ps2sat_struct.h"
//#include "custom_mmi_default_value.h"
//#include "app_ltlcom.h"
//#include "mmi_l3_enums.h"
//[?] #include "l4c_common_enum.h"
//------------------------------ dup symbol ------------------------------
//MAX_APN_LEN
//   ps\l4\include\l4c_common_enum.h
//   ps\interfaces\enum\mmi_l3_enums.h

//------------------------------ suggest Add ------------------------------
#include "kal_public_api.h"
#include "tcm_api.h"
#include "ps_public_enum.h"
#include "l4c2tcm_func.h"

/* __MEDIATEK_SMART_QOS__ */
#include "nvram_editor_data_item.h"

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 

/* __APP_SECONDARY_PDP_SUPPORT__ */
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 context_id;
    kal_uint8 src_id;
} tcm_pdp_reactivate_req_struct;

#ifdef __SATCE__
/* mtk00938: If you want to modify this structure, please notify ABM owner. */
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 nw_acct_id;    
    kal_bool is_apn_valid;
    kal_uint8 apn_length;
    kal_uint8 apn[50];
    kal_bool is_username_valid;
    kal_uint8 no_username;
    kal_uint8 username[16];
    kal_uint8 dcs_of_username;
    kal_bool is_passwd_valid;
    kal_uint8 no_passwd;
    kal_uint8 passwd[16];
    kal_uint8 dcs_of_passwd;
    kal_bool is_local_addr_valid;
    kal_uint8 no_local_addr;
    kal_uint8 local_addr[16]; // Internal TCPIP don't need IPv6/IPv4v6 feature, so 16*u8 size is okay
    kal_bool is_dest_addr_valid;
    kal_uint8 no_dest_addr;
    kal_uint8 dest_addr[16];
    sat_gprs_bearer_para_struct gprs_bearer;
} l4c_sate_gprs_account_info_struct;
#endif /* __SATCE__ */

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 context_id;
    kal_uint8 src_id;
    //kal_uint8 app_src;
    //kal_uint8 profile_id;
    kal_uint8 additional_para_type; //tcm_pdp_activate_req_additional_para_type_enum
    kal_uint32 additional_para_content; // __HSPA_DATA_PATH_OPT__
    l4c_gprs_account_info_struct account_info;
    tcm_ps_qos_profile_struct qos_info; //mtk02285, 20110916
#ifdef __SATCE__
    kal_bool is_sate_account_info_valid;
    l4c_sate_gprs_account_info_struct sate_account_info;
#endif /* __SATCE__ */
   /* following are for __APP_SECONDARY_PDP_SUPPORT__ */
   kal_uint8 gprs_pf_num;          // Number of gprs_pf_info
   l4c_pf_struct gprs_pf_info[8];  // Packet filter content
} tcm_pdp_activate_req_struct;


typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 context_id;
    kal_uint8 src_id;
} tcm_pdp_activate_rej_rsp_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 context_id;
    kal_uint8 src_id;
} tcm_pdp_modify_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 context_id;
    kal_uint8 additional_para_type; //tcm_pdp_activate_req_additional_para_type_enum
    kal_uint32 additional_para_content; // __HSPA_DATA_PATH_OPT__
    kal_uint8 src_id;
    #ifdef __LOCAL_DEACTIVATE_PDP_SUPPORT__
    kal_bool local_deactivate_pdp; /* __LOCAL_DEACTIVATE_PDP_SUPPORT__ */	
    #endif // ~ __LOCAL_DEACTIVATE_PDP_SUPPORT__
} tcm_pdp_deactivate_req_struct;

/* for __APP_SECONDARY_PDP_SUPPORT__ */
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8	            context_id;
    kal_bool	            is_qos_present; // indicates if QoS modification
    nvram_editor_qos_struct	modify_qos;     // modifying QoS value
    kal_uint8	            tft_opcode;     // tft_opcode_enum: the operation of TFT modification
    kal_uint8	            gprs_pf_num;    // number of gprs_pf_info
    l4c_pf_struct	        gprs_pf_info[8];// packet filter content
} ltcm_pdp_qos_tft_modify_req_struct;
/* ~for __APP_SECONDARY_PDP_SUPPORT__ */

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 context_id;
    kal_uint8 src_id;
    kal_uint8 apn_length;
    kal_uint8 apn[100];
    kal_uint8 dcomp_algo;
    kal_uint8 hcomp_algo;
    kal_uint8 pdp_type;
    kal_uint8 pdp_addr_len;
    kal_uint8 addr_val[16];  // AT+CGDCONT should not set static IPv6 address, so 16*u8 size is okay?
    kal_uint8 ipv4addralloc ;   // __REL8__
} l4ctcm_set_pri_pdp_info_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 context_id;
    kal_uint8 src_id;
    kal_uint8 prim_context_id;
    kal_uint8 dcomp_algo;
    kal_uint8 hcomp_algo;
} l4ctcm_set_sec_pdp_info_req_struct;


typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 context_id;
    kal_uint8 src_id;
    kal_uint8 tot_pf_count;
    l4c_pf_struct pf[8];
} l4ctcm_set_tft_info_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 context_id;
    kal_uint8 src_id;
    kal_uint8 qos_type;
    kal_uint8 delay_class;
    kal_uint8 reliability_class;
    kal_uint8 peak_throughput;
    kal_uint8 precedence_class;
    kal_uint8 mean_throughput;
} l4ctcm_set_qos_info_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 context_id;
    kal_uint8 src_id;
    kal_uint8 qos_type;
    kal_uint8 traffic_class;
    kal_uint8 delivery_order;
    kal_uint8 delivery_of_err_sdu;
    kal_uint8 max_sdu_size;
    kal_uint8 max_bitrate_up_lnk;
    kal_uint8 max_bitrate_down_lnk;
    kal_uint8 residual_bit_err_rate;
    kal_uint8 sdu_err_ratio;
    kal_uint8 transfer_delay;
    kal_uint8 traffic_hndl_priority;
    kal_uint8 guarntd_bit_rate_up_lnk;
    kal_uint8 guarntd_bit_rate_down_lnk;
    kal_uint8 signalling_indication;
    kal_uint8 source_statistics_descriptor;
    kal_uint8 ext_max_bitrate_down_lnk;
    kal_uint8 ext_guarntd_bit_rate_down_lnk;
    kal_uint8 ext_max_bitrate_up_lnk;
    kal_uint8 ext_guarntd_bit_rate_up_lnk;
} l4ctcm_set_eqos_info_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 src_id;
} l4ctcm_start_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 context_id;    
    kal_uint8 src_id;
    kal_uint8 is_chap;
} l4ctcm_set_ppp_auth_info_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    l4c_config_option_struct prco;
} l4ctcm_set_config_option_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 context_id;    
    kal_uint8 channel_id;
    pdp_addr_type_enum pdp_type;    
    // __HSPA_DATA_PATH_OPT__ ---
    //kal_uint8 port_number;
    kal_uint8 additional_para_type; //tcm_pdp_activate_req_additional_para_type_enum (TCM_PDP_ACT_REQ_HAS_EXTRA_PARA_AS_MODULE_ID)
    kal_uint32 additional_para_content; // module id
    // --- __HSPA_DATA_PATH_OPT__
}l4ctcm_enter_data_mode_req_struct;

/* __MEDIATEK_SMART_QOS__ */
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8  src_id;
    kal_bool   is_msq_on ;  /* True: Use R6 QOS if the current PLMN (NW/SIM) is on MSQ list (nvram_ef_msq_list_struct). */ 
} l4ctcm_set_msq_mode_req_struct ;

/* __MEDIATEK_SMART_QOS__ */
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8  src_id;
    nvram_ef_msq_entry_struct  entry ;
} l4ctcm_set_msq_entry_req_struct ;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8       context_id;
    kal_uint8       src_id;
    kal_uint8       name_length;
    kal_uint8       name_dcs;
    kal_uint8       name[32];
    kal_uint8       apn_length;
    kal_uint8       apn [ 100 ];
    kal_uint8       authentication_type;
    kal_uint8       user_name[16];
    kal_uint8       password[16];
    kal_uint8       dns[4];
} l4ctcm_set_gprs_account_info_req_struct;

/* mtk00714 w0637: AT definition */
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8		src_id;
    kal_uint8       context_id;
    kal_uint16 		undefine_action; //l4c_action_enum
} l4ctcm_undefine_pdp_info_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8	on_off;
} l4ctcm_set_acl_mode_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
	kal_uint16	start_index;
	kal_uint16	max_read_entries;
} l4ctcm_get_acl_entries_req_struct;

typedef struct
{
    kal_uint8 apn[MAX_APN_LEN];
} tcm_acl_entry_struct;

typedef struct
{
    LOCAL_PARA_HDR
	kal_uint16	       index;
	tcm_acl_entry_struct	acl_entry;
} l4ctcm_set_acl_entry_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
	tcm_acl_entry_struct	acl_entry;
} l4ctcm_add_acl_entry_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_bool	del_all;
	kal_uint16	index;
	tcm_acl_entry_struct	acl_entry;
} l4ctcm_del_acl_entry_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 query_id;
    kal_uint8 last_cid;
} l4ctcm_query_ext_gprs_history_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 reset_id; 
    kal_bool reset_all; 
    kal_bool reset_certain_cid_last_history;
    kal_uint8 context_id; 
    kal_bool reset_total_history;
} l4ctcm_reset_ext_gprs_history_req_struct;

#endif 


