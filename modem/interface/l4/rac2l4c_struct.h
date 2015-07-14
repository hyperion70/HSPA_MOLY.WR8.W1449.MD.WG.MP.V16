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
 *	rac2l4c_struct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for structure definition between RAC and L4C.
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
 * removed!
 *
 * removed!
 * removed!
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


/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*******************************************************************************
 *  FILENAME : rac2l4c_struct.h
 *  SYNOPSIS : Functions for encoding/decoding.
 *
 *                      R E V I S I O N    H I S T O R Y
 *
 */
#ifndef _RAC2L4C_STRUCT_H
#define _RAC2L4C_STRUCT_H

//#include "kal_non_specific_general_types.h"
#include "kal_public_defs.h"
#include "ps_public_enum.h"
#include "mcd_l4_common.h"
#include "mcd_mm_common_gen_struct.h"
#include "mcd_l3_inc_struct.h"
#include "l3_inc_local.h"
#include "kal_general_types.h"
#include "l4c_common_enum.h"
#include "l4crac_enums.h"
#if defined (__MMDC__) && defined (__MMDC_TYPE1_DUAL_LOAD__)
#include "l3_inc_enums.h"
#endif

typedef struct {
    plmn_id_struct plmn_id;
    kal_uint8 status;
} plmn_info_struct;

typedef struct {
    LOCAL_PARA_HDR
    l4c_source_id_enum src_id; /* source id*/
    l4c_rac_response_enum response; /* OK*/
} l4crac_act_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    l4c_source_id_enum src_id; /* source id*/
    plmn_selection_mode_enum plmn_sel_mode; /* AUTO/MANUAL*/
    l4c_rac_response_enum gsm_status; /* OK/No Cell/Limited service*/
    l4c_rac_gprs_status_enum gprs_status; /* l4c_rac_gprs_status_enum */
//    kal_uint8 acq_service; /* acquired service: CS/PS/CS_PS*/
    cell_info_and_rat_struct cell_info;
    /* MAUI_01650679, __NW_REGISTRATION_CAUSE__ */
    mm_cause_enum cause; /* registration result */
    data_speed_support_enum cell_data_speed_support;
} l4crac_reg_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    l4c_source_id_enum src_id; /* source id*/
    l4c_rac_gprs_status_enum gprs_status; /* l4c_rac_gprs_status_enum */
    data_speed_support_enum cell_data_speed_support;
} l4crac_ps_reg_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    l4c_source_id_enum src_id; /* source id*/
    //kal_uint8 service; /* CS/PS/CS_PS*/
    //kal_uint8 status; /* l4c_rac_dereg_cnf_status_enum */
} l4crac_dereg_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    l4c_source_id_enum src_id; /* source id*/
    l4c_rac_response_enum response; /* OK or ERROR */
    mm_cause_enum cause;
    kal_uint8 num_of_hplmn;
    rac_plmn_list_struct plmn_list;
} l4crac_plmn_list_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    rac_plmn_list_struct plmn_list;
} l4crac_plmn_list_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    l4c_rac_response_enum gsm_status; /* l4c_rac_response_enum */
    l4c_rac_gprs_status_enum gprs_status; /* l4c_rac_gprs_status_enum */
    cell_info_and_rat_struct cell_info;
    reg_state_enum gsm_state; /* reg_state_enum */
    reg_state_enum gprs_state; /* reg_state_enum */
    /* MAUI_01650679, __NW_REGISTRATION_CAUSE__ */
    mm_cause_enum cause; /* registration result */
    domain_id_enum domain;
    data_speed_support_enum cell_data_speed_support;
} l4crac_reg_state_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    domain_id_enum domain; /* domain_id_enum */
    mm_cause_enum cause; /* mm_cause_enum */
} l4crac_reg_cause_ind_struct;

#if 0 //rx_level, mtk02285, remove old interface
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */

typedef struct {
    LOCAL_PARA_HDR
    kal_bool full_nw_nameP;
    kal_uint8 full_nw_name_len;
    kal_uint8 full_nw_name[24];
    kal_bool short_nw_nameP;
    kal_uint8 short_nw_name_len;
    kal_uint8 short_nw_name[24];
    kal_bool nw_time_zoneP;
    kal_uint8 nw_time_zone;
    kal_bool nw_time_zone_timeP;
    nw_time_zone_time_struct nw_time_zone_time;
    kal_bool lsa_idP;
    kal_uint8 lsa_id_len;
    kal_uint8 lsa_id[3];
    kal_bool nw_day_light_saving_timeP;
    kal_uint8 nw_day_light_saving_time;
    /* MAUI_01664028, mtk02118: added for MMI to exactly know which PLMN the NITZ comes from */
    plmn_id_struct plmn_id;
} l4crac_nw_info_ind_struct;   /* Struct shall be the same as gmmreg_nw_info_ind_struct. */

typedef struct {
    LOCAL_PARA_HDR
    l4c_source_id_enum src_id; /* source id*/
    l4c_rac_response_enum gsm_status; /* OK/No Cell/Limited service*/
    l4c_rac_gprs_status_enum gprs_status; /* l4c_rac_gprs_status_enum */
} l4crac_class_change_cnf_struct;


typedef struct {
    LOCAL_PARA_HDR
    l4c_source_id_enum src_id; /* source id*/
    l4c_rac_response_enum gsm_status; /* OK/No Cell/Limited service*/
    l4c_rac_gprs_status_enum gprs_status; /* l4c_rac_gprs_status_enum */

} l4crac_set_preferred_band_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_bool is_gsm_conn_exist;
    gmmreg_cipher_ind_enum gsm_cipher_cond; 
    gmmreg_cipher_ind_enum gprs_cipher_cond; 
} l4crac_cipher_ind_struct; /* Must same as gmmreg_cipher_ind_struct */

typedef struct {
    LOCAL_PARA_HDR
    cell_info_and_rat_struct cell_info;
    l4c_rac_response_enum gsm_status; /* l4c_rac_response_enum */
} l4crac_hz_cell_info_update_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_bool is_dedicated_mode;
} l4crac_hz_dedicated_mode_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_bool is_pkt_transfer_mode;
} l4crac_hz_pkt_transfer_mode_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    mmi_event_enum event_id;  //mmi_event_enum
} l4crac_ps_event_report_ind_struct; 

typedef struct {
    LOCAL_PARA_HDR
    l4c_source_id_enum src_id;
    kal_bool result;
} l4crac_set_roaming_mode_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    l4c_source_id_enum src_id; /* source id*/
    l4c_rac_response_enum gsm_status; /* l4c_rac_response_enum */
    l4c_rac_gprs_status_enum gprs_status; /* l4c_rac_gprs_status_enum */
    mm_cause_enum cause;
    cell_info_and_rat_struct cell_info;
    data_speed_support_enum cell_data_speed_support;
} l4crac_plmn_search_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    l4c_source_id_enum src_id;
    kal_bool result;
    mm_cause_enum cause;
} l4crac_set_rat_mode_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    l4c_source_id_enum src_id;
} l4crac_plmn_list_stop_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    l4c_source_id_enum src_id;
    kal_bool result;    
} l4crac_set_prefer_rat_cnf_struct;


//#ifdef __GEMINI__
typedef struct {
    LOCAL_PARA_HDR
    l4c_rac_mmrr_service_status_enum service_status;
} l4crac_mmrr_service_status_ind_struct; //GEMINI, 20080217
//#endif

//#ifdef __REL5__
typedef struct {
	kal_uint8          category;
	l4_addr_bcd_struct	tel_number;
} rac_ecc_number_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 no_ecc; //number of ECC list
    rac_ecc_number_struct ecc_list[16]; //ECC list
} l4crac_nw_ecc_ind_struct;
//#endif
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 susp_id;
} l4crac_suspend_status_ind_struct; 

typedef struct {
    LOCAL_PARA_HDR
    l4c_source_id_enum src_id;
    end_session_result_enum result;
} l4crac_end_ps_data_session_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    l4c_source_id_enum src_id;
    susp_resu_result_enum result;
} l4crac_susp_resu_update_cnf_struct;

#ifdef __CSG_SUPPORT__
typedef struct {
    LOCAL_PARA_HDR
    l4c_source_id_enum src_id; /* source id*/
    l4c_rac_response_enum response; /* OK or ERROR */
    mm_cause_enum cause;
    rac_csg_list_struct csg_list;
} l4crac_csg_list_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    l4c_source_id_enum src_id;
} l4crac_csg_list_stop_cnf_struct;
#endif /* __CSG_SUPPORT__ */

#if defined (__MMDC__) && defined (__MMDC_TYPE1_DUAL_LOAD__)
typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;         //20120215 mtk80370: please DO NOT change the order of element in this struct
    //module_type peer_module;     /* No needed module */
    mm_proc_enum mm_peer_procedure;
    mm_cause_enum mm_peer_reject_cause;
    plmn_id_struct mm_peer_plmn_id;
}l4crac_peer_reject_ind_struct;

typedef struct {
	kal_uint8 ref_count;
	kal_uint16 msg_len;
	ind_type_enum ind_type;
	as_cell_type_enum cell_type;
}l4crac_to_peer_info_ind_struct;

#endif

#endif

