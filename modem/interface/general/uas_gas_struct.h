/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   uas_gas_struct.h
 *
 * Project:
 * --------
 *   MONZA
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log:$
 * 
 * 09 27 2012 yong.su
 * [MOLY00004236] [interface][service][kal]remove stack_ltlcom.h
 * <saved by Perforce>
 *
 * 06 29 2012 henry.lai
 * [MOLY00000128] [MT6280][GAS] SI2Q/MEAS/RESEL improvement check-in
 * .
 *
 * 05 25 2012 haizhou.liu
 * removed!
 * .
 *
 * 05 25 2012 yong.su
 * removed!
 * .
 *
 * 05 17 2012 peter.chien
 * removed!
 * .
 *
 * 05 02 2012 adeline.chang
 * removed!
 * .
 *
 * 01 11 2012 shunwen.hsiao
 * removed!
 * Check in TK6280_DVT_DEV to MT6280_DVT_DEV
 *
 * 01 06 2012 chi-chung.lin
 * removed!
 * .
 *
 * 11 14 2011 zengyu.hao
 * removed!
 * merge interface: uas_gas_struct.h
 *
 * 11 11 2011 evelyn.wang
 * removed!
 * .
 *
 * 11 09 2011 ryan.ou
 * removed!
 * .
 *
 * 12 17 2010 shunwen.hsiao
 * removed!
 * .
 *
 * 10 28 2010 maruco.tu
 * removed!
 * .
 *
 * 08 04 2010 william.chang
 * removed!
 * .
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Supported 3rd criteria for InterRAT cell reselection to UTRAN.
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Add copyright header.
 ****************************************************************************/

#ifndef _UAS_GAS_STRUCT_H
#define _UAS_GAS_STRUCT_H

#include "uas_gas_enums.h"    
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "csi_umts_asn.h"     
#include "l3_inc_enums.h"     
#include "mcd_l3_inc_struct.h"
#include "csi_gsm_asn.h"      

#ifdef __CMCC_STD_FR__
#define MAX_CELL_NUM 27
#endif
//Common structure
/**
 * @brief 
 *     ts_rrc_gsm_classmark2 specifies the encoded classmark 2 inforamtion.  */
typedef struct {
  kal_uint8 length; /* in bytes  = 5*/
  kal_uint8 gsm_classmark2[MAX_LEN_TLV_CLASSMARK_2]; 
                             /* This is encoded byte stream of 
				  classmark 2  */
} ts_rrc_gsm_classmark2;

/**
 * @brief 
 *     ts_rrc_gsm_classmark3 specifies the encoded classmark 3 inforamtion.  */
typedef struct {
  kal_uint8  length;   /* length of encoded bytestream of classmark 3 in octets*/
  kal_uint8  gsm_classmark3[MAX_LEN_V_CLASSMARK_3]; 
                   /*  Encoded byte stream of classmark 3 'VALUE' part */
                   /* For bit/byte Ordering refer to CFQ-2002-0016-SP-B */ 
} ts_rrc_gsm_classmark3;

#if defined(__PS_HO__) && defined (__UMTS_R6__)    
typedef struct {
  kal_uint8  length;   /* length of encoded bytestream of gprs capability in octets*/
  kal_uint8  gsm_ms_radio_access_capability[MAX_LEN_V_MS_RADIO_ACCESS_CAPABILITY]; 
} ts_rrc_gsm_ms_radio_access_capability;   
#endif

/**
 * @brief 
 *     ts_ir_geran_handover_information_status specifies the gsm RAT
 *     information required for inter-rat handover. 
 */

typedef struct
{
  kal_uint32  length;  /* Length in bits */
  kal_uint8   value[MAX_LEN_UTRAN_HANDOVER_INFO_MSG];
}ts_ir_utran_handover_info_status;

typedef struct
{
  kal_uint32  length;  /* Length in bits */
  kal_uint8   value[MAX_LEN_HO_TO_UTRAN_MSG]; 
                /* ASN.1 encoded UTRAN handover command as received in 
		 * INTER-SYSTEM-HANDOVER-TO-UTRAN command on GSM RAT */ 
                /* If the message is not octet aligned, and fills up x bits of octet Y,
		 * Bits 8 to 8-x-1 will contain valid info*/
}ts_ir_handover_to_utran_contents;


typedef struct 
{
  te_cn_domain_cipher_status cipher_status;
  /* MH: The following flag is only used when 2G -> 3G HO and ciphering is on. Normally, this flag should
    *        be set to KAL_FALSE. If GAS got a new ciphering key, but this hasn't been activated yet (GAS
    *        hasn't received CIPHER COMMAND), and then 2G -> 3G HO happens, 3G NW will use OLD key
    *        for the folllowing ciphering. Thus, at this case, GAS should set this flag to TRUE. RRCE will use
    *        OLD key instead of NEW key for ciphering.
    *        Please refer to 25.331 CR 2567 (20070314)
    */
  kal_bool is_new_cipher_key_received;
} ts_ciphering_info;

typedef struct {
   te_gsm_band_indicator gsm_band_indicator;
   kal_uint16 bcch_arfcn;
   kal_int16 rssi_in_quarter_dbm;
   te_ir_bar_status resel_status;
}ts_ir_carrier_rssi_info;

typedef struct{
    kal_uint32 frame_offset;
    kal_uint16 quarter_bit_offset;
}ts_ir_gsm_cell_timing_info;    

typedef struct {
   te_gsm_band_indicator gsm_band_indicator;
   kal_uint16 bcch_arfcn;
   kal_bool bsic_verified;
   kal_uint8 bsic; /* This contains a valid value only if bsic_verified = TRUE */
   ts_ir_gsm_cell_timing_info gsm_cell_timing_info; /* This contains a valid value only if bsic_verified = TRUE */
}ts_ir_gsm_cell_bsic_info;

typedef struct {
   kal_uint8 num_carriers;
   ts_ir_carrier_rssi_info carrier_rssi_info[MAX_NUM_MEASURED_GSM_CELLS];
}ts_ir_gsm_cell_rssi_info;   

#ifdef __UMTS_FDD_MODE__	   
typedef struct {
  kal_uint16 scrambling_code;
  kal_uint8 cpich_rscp;  /* R99:0-91, R5:(-5)-91*/
  kal_uint8 cpich_ec_n0; /* 0-49 */
  te_ir_bar_status resel_status;
  te_ir_resel_criteria3_status criteria3_status;
}ts_ir_reported_fdd_cells_meas_info;
#endif

#ifdef __UMTS_TDD128_MODE__
typedef struct {
    kal_uint16 cell_parameter;
    kal_uint8 pccpch_rscp;  /* R99:0-91, R5:(-5)-91*/
    te_ir_bar_status resel_status;
    te_ir_resel_criteria3_status criteria3_status;
}ts_ir_reported_tdd_cells_meas_info;
#endif

typedef struct {
    kal_uint16 uarfcn;
    kal_uint8 uarfcn_rssi; /*0-63*/
    kal_uint8 num_reported_cells;
#ifdef __UMTS_FDD_MODE__
    ts_ir_reported_fdd_cells_meas_info ir_reported_fdd_cells_meas_info[MAX_NR_OF_FDD_CELLS_IN_CELL_LIST];
#endif
#ifdef __UMTS_TDD128_MODE__
    ts_ir_reported_tdd_cells_meas_info ir_reported_tdd_cells_meas_info[MAX_NR_OF_TDD_CELLS_IN_CELL_LIST];
#endif
}ts_ir_umts_carrier_meas_results;    

typedef struct {
    te_ir_bar_status rat_resel_status;
    kal_uint8 num_carriers;
    ts_ir_umts_carrier_meas_results ir_umts_carrier_meas_reults[MAX_NUM_MEASURED_UMTS_CARRIERS];
}ts_ir_umts_meas_info;

#ifdef __UMTS_FDD_MODE__
typedef struct {
   kal_uint16 uarfcn;
   kal_uint16 scrambling_code;
   kal_bool tx_diversity;
}ts_umts_fdd_cell;
#endif

#ifdef __UMTS_TDD128_MODE__
typedef struct {
   kal_uint16 uarfcn;
   kal_uint16 cell_parameter;
   kal_bool tstd;
   kal_bool sctd;
}ts_umts_tdd_cell;
#endif

typedef struct {
   te_umts_mode      mode;
#ifdef __UMTS_FDD_MODE__
   ts_umts_fdd_cell  fdd_cell;
#endif
#ifdef __UMTS_TDD128_MODE__
   ts_umts_tdd_cell  tdd_cell;
#endif
}ts_umts_target_cell;

/* Define for Evaluation or Activation Failed Handle */
typedef struct {
   te_eval_activate_fail_type eval_activate_fail_type;
   kal_uint16                 tbarred_val;  /* in sec, valid only when evalActivateFailType is CELL_BARRED */      
} ts_eval_activate_fail_handle;

typedef struct {
   kal_uint8 t3212_timer_val;
   kal_bool att_flag;
} ts_cs_specific_cn_info;

#if defined(__PS_HO__) && defined (__UMTS_R6__)    
typedef struct {
   kal_uint8 ra_code;
   kal_uint8 nmo;
} ts_ps_specific_cn_info;
#endif

//Dual mode MEME SAP start 
/*
typedef struct
{
   LOCAL_PARA_HDR
}uas_gas_config_gcell_meas_cnf_struct;*/

/*
typedef struct
{
   LOCAL_PARA_HDR
   ts_ir_gsm_cell_rssi_info gsm_cell_rssi_info;
}uas_gas_gcell_meas_ind_struct;*/

/*
typedef struct
{
   LOCAL_PARA_HDR
   ts_ir_gsm_cell_bsic_info gsm_cell_bsic_info;
}uas_gas_gcell_bsic_ind_struct;*/

/*
typedef struct {
  LOCAL_PARA_HDR
  ts_ir_umts_cell_list ir_umts_cell_list;
}gas_uas_config_ucell_meas_req_struct;*/
//Dual mode MEME SAP end

typedef struct
{
  kal_uint16 cell_change_timeout;
  /* MH: Added for informing GAS the CCO activation time (20070511)*/
  kal_uint16 cell_change_activation_time;
  kal_uint8 wait_time;
} IR3G2TimerStruct;

typedef struct
{
  kal_bool bsic_present; /* if TRUE bsic is present */
  kal_uint8 bsic; /* Optional, present if bsic_present is TRUE */
  te_gsm_band_indicator gsm_band_indicator;
  kal_uint16 bcch_arfcn;
} GSM_TargetCellInfo;

typedef struct
{
  kal_uint8 numElements;
  GSM_TargetCellInfo element[MAX_TARGET_GSM_CELLS_NUM]; /* Only the first numElements are valid*/
} GSM_TargetCellInfoList;

#if (defined(__UMTS_R5__) && defined(__GERAN_R5__))
typedef struct {
   kal_uint8 numOctets;
   kal_uint8 stringData[23]; /* Only the first numOctets elements are valid*/
} GERAN_SystemInfoBlock;

typedef struct {
   kal_uint8 numElements;
   GERAN_SystemInfoBlock element[MAX_GSM_SYS_INFO_BLOCKS_NUM]; /* Only the first numElements are valid*/
} GERAN_SystemInformation;
#endif

//From GAS to UAS
typedef struct
{
   LOCAL_PARA_HDR
}uas_gas_config_gcell_meas_cnf_struct;

typedef struct
{
   LOCAL_PARA_HDR
   kal_uint8 list_ref;
   ts_ir_gsm_cell_rssi_info gsm_cell_rssi_info;
}uas_gas_gcell_meas_ind_struct;

typedef struct
{
   LOCAL_PARA_HDR
   ts_ir_gsm_cell_bsic_info gsm_cell_bsic_info;
}uas_gas_gcell_bsic_ind_struct;

typedef struct {
  LOCAL_PARA_HDR
  kal_uint8 list_ref;
  kal_uint8 drx_cycle_num;
  kal_uint16 drx_cycle_period;
  CsiUmtsCellList umts_cell_list;
#if defined(__GERAN_R5__) && defined(__UMTS_R5__)
  kal_int8 fdd_rscp_min_in_dbm;
#endif
  kal_uint16 first_meas_uarfcn; // invalid value = UAS_GAS_INVALID_UARFCN
}gas_uas_config_ucell_meas_req_struct;

typedef struct {
  LOCAL_PARA_HDR
  te_l1_availibility_status l1_availibility_status;
}gas_uas_lower_layer_availability_req_struct;

typedef struct {
  LOCAL_PARA_HDR
  te_ir_handover_status ir_handover_to_gsm_status;
}uas_gas_ho_activate_gcell_cnf_struct;

typedef struct {
  LOCAL_PARA_HDR
  te_ir_handover_status ir_handover_to_gsm_status;
}uas_gas_handover_gcell_cnf_struct;

typedef struct {
   LOCAL_PARA_HDR
   ts_ciphering_info ciphering_info;
   plmn_search_type_enum plmn_search_type;
#if defined(__PS_HO__) && defined (__UMTS_R6__)    
  /* Set CS_DOMAIN if this is a CS HO. Set PS_DOMAIN if this is a PS HO */
  domain_id_enum  ir_ho_type;
#endif
}gas_uas_handover_ucell_req_struct;

typedef struct {
   LOCAL_PARA_HDR
   lai_struct lai;
#if defined(__PS_HO__) && defined (__UMTS_R6__)    
   kal_bool  is_cs_cn_info_valid;
   kal_bool  is_ps_cn_info_valid;
#endif
   ts_cs_specific_cn_info  gas_cs_cn_info;
#if defined(__PS_HO__) && defined (__UMTS_R6__)    
   /* For PS HO, we need to know PS CN info */
   ts_ps_specific_cn_info  gas_ps_cn_info;
#endif
}gas_uas_ho_activate_ucell_req_struct;

typedef struct {
  LOCAL_PARA_HDR
  ts_rrc_gsm_classmark2 gsm_classmark2;  /* GSM classmark 2 information */
  ts_rrc_gsm_classmark3 gsm_classmark3;  /* GSM classmark 3 information */
#if defined(__PS_HO__) && defined (__UMTS_R6__)    
  ts_rrc_gsm_ms_radio_access_capability gsm_ms_radio_access_capability;
#endif
  /* The bitmap is used to present if the ciphering algorithm A5/1, A5/2, ... , A5/7
   * is supported.
   *  bit  6    5    4    3    2    1    0
           A5/7 A5/6 A5/5 A5/4 A5/3 A5/2 A5/1
   */
  kal_uint8 gsm_security_cap;
}uas_gas_ho_gsm_info_ind_struct;

typedef struct {
  LOCAL_PARA_HDR
  te_ir_cell_reselection_status ir_cell_eval_status;
  ts_eval_activate_fail_handle	eval_activate_fail_handle;
}uas_gas_evaluate_gcell_cnf_struct;

typedef struct {
  LOCAL_PARA_HDR
  te_ir_cell_reselection_status ir_cell_activation_status;
  /*Byron: 2007/05/08: Add for real CCO fail cause*/
  te_ir_cell_change_fail_reason_enum ir_cell_change_failed_reason; 
  ts_eval_activate_fail_handle	eval_activate_fail_handle;
}uas_gas_activate_gcell_cnf_struct;

typedef struct {
  LOCAL_PARA_HDR
}uas_gas_evaluate_gcell_stop_cnf_struct;

typedef struct {
  LOCAL_PARA_HDR
 te_ir_cell_change_complete_status ir_cell_change_complete_status;
  /*Byron: 2007/05/08: Add for real CCO fail cause*/
  te_ir_cell_change_fail_reason_enum ir_cell_change_failed_reason;
}uas_gas_gcell_change_complete_ind_struct;

#ifdef __CMCC_STD_FR__
typedef struct{
  U16 cellId;
  CsiUarfcn uarfcn;	
}CellPara;
typedef struct{
  LOCAL_PARA_HDR
  U8 numElements;
  CellPara  elements[MAX_CELL_NUM];
}std_fr_cell_list;
typedef struct
{
   	LOCAL_PARA_HDR
   	kal_uint8     frThreshold;
   	kal_uint8     numElements;
   	CsiUarfcn     element[9];
}gas_uas_std_fr_info_ind_struct;
#endif

/* for R6 redirection feature */
#if (defined(__GERAN_R6__) || defined(__CMCC_FR__) || defined(__CMCC_STD_FR__))

/* Request to evaluate a cell
   because of inter RAT cell reselection or network ordered cell change */
typedef struct {
  LOCAL_PARA_HDR
 te_ir_cell_reselection_type ir_cell_reselection_type;
 te_ir_cell_change_trigger ir_cell_change_trigger;
 plmn_search_type_enum plmn_search_type;
 ts_umts_target_cell target_cell;
} gas_uas_evaluate_ucell_req_struct;

/* Request to activate a cell without an evaluation phase */
typedef struct {
  LOCAL_PARA_HDR
 kal_uint16 cell_change_timeout; /* value in seconds or zero when not required */
 te_ir_cell_reselection_type ir_cell_reselection_type;
 te_ir_cell_change_trigger ir_cell_change_trigger;
 plmn_search_type_enum plmn_search_type;
 ts_umts_target_cell target_cell; /* For IR_CELL_CHANGE_TRIGGER_NW_CONTROLLED */
#if (defined(__GERAN_R6__) || defined(__CMCC_FR__))
 CsiUmtsCellList redirection_list; /* For IR_CELL_CHANGE_TRIGGER_NW_CONTROLLED_REDIRECTION */
#endif
#ifdef __CMCC_STD_FR__
 std_fr_cell_list std_fr_cell_list;
#endif
} gas_uas_activate_ucell_req_struct;

#else

/* Request to evaluate a cell
   because of inter RAT cell reselection or network ordered cell change */
typedef struct {
  LOCAL_PARA_HDR
 kal_uint16 cell_change_timeout; /* value in seconds or zero when not required */
 te_ir_cell_reselection_type ir_cell_reselection_type;
 te_ir_cell_change_trigger ir_cell_change_trigger;
 plmn_search_type_enum plmn_search_type;
 ts_umts_target_cell target_cell;
} gas_uas_evaluate_ucell_req_struct;

/* Request to activate a cell without an evaluation phase */
typedef gas_uas_evaluate_ucell_req_struct  gas_uas_activate_ucell_req_struct;
#endif /* (defined(__GERAN_R6__) && defined(__UMTS_R6__)) || defined (__FDD_REDIRECTION__) */

/* Request to stop an ongoing evaluation */
typedef struct {
  LOCAL_PARA_HDR
} gas_uas_evaluate_ucell_stop_req_struct;


//From UAS to GAS
typedef struct {
  LOCAL_PARA_HDR
  ts_ciphering_info ciphering_info;
  //kal_bool             emergency_call;
  plmn_search_type_enum plmn_search_type;
   //kal_uint8                plmn_identity[INTER_RRC_LEN_PLMN_IDENTITY];
   te_gsm_band_indicator band_indicator;
#if defined(__PS_HO__) && defined (__UMTS_R6__)    
  domain_id_enum  existed_sig_conn_domain; /* For GAS to do invalid checking */ 
  GERAN_SysInfoType  sys_info_type; /* For 3G to 2G PS HO*/
  GERAN_SystemInformation  sys_info; /* Ignore this unless sys_info_type is for SI or PSI */
#endif
  kal_uint16         message_length;
}uas_gas_handover_gcell_req_struct;

typedef struct {
  LOCAL_PARA_HDR
   /* MH: Add t3212 and att flag. UAS should pass this info to GAS during 3G to 2G HO. (20070723)*/
   kal_uint8 t3212_timer_val;
   kal_bool att_flag;
}uas_gas_ho_activate_gcell_req_struct;

typedef struct {
  LOCAL_PARA_HDR
  te_ir_handover_status ir_handover_to_utran_status;
}gas_uas_handover_ucell_cnf_struct;

typedef struct {
  LOCAL_PARA_HDR
  te_ir_handover_status ir_handover_to_utran_status;
}gas_uas_ho_activate_ucell_cnf_struct;

typedef struct {
  LOCAL_PARA_HDR
  kal_uint8 list_ref;
#ifdef __TDD_DM_GAP_OPTIMIZATION__
  kal_bool is_bsic_gap_valid;
#endif
  te_ir_urrc_state urrc_state;	
  CsiGsmCellList gsm_cell_list;
}uas_gas_config_gcell_meas_req_struct;

typedef struct {
  LOCAL_PARA_HDR
}gas_uas_config_ucell_meas_cnf_struct;

typedef struct {
  LOCAL_PARA_HDR
  te_l1_availibility_status l1_availibility_status;
}uas_gas_lower_layer_availability_req_struct;

typedef struct {
  LOCAL_PARA_HDR
  kal_uint8 list_ref;
  ts_ir_umts_meas_info ir_umts_meas_info;
#if defined(__PRI_RESEL_SUPPORT__) // __UMTS_R8__, __GERAN_R8__
  kal_bool isLongPeriod;
#endif
#ifdef UNIT_TEST
kal_uint32 ucell_meas_ind_ms_diff;
#endif /* UNIT_TEST */
}gas_uas_ucell_meas_ind_struct;

typedef struct {
  LOCAL_PARA_HDR
  te_ir_cell_reselection_status ir_cell_eval_status;
  ts_eval_activate_fail_handle	eval_activate_fail_handle;
}gas_uas_evaluate_ucell_cnf_struct;

typedef struct {
  LOCAL_PARA_HDR
  te_ir_cell_reselection_status ir_cell_activation_status;
  ts_eval_activate_fail_handle	eval_activate_fail_handle;
  /*Byron: 2007/05/08: Add for real CCO fail cause*/
  te_ir_cell_change_fail_reason_enum ir_cell_change_failed_reason;
}gas_uas_activate_ucell_cnf_struct;

typedef struct {
  LOCAL_PARA_HDR
}gas_uas_evaluate_ucell_stop_cnf_struct;

typedef struct {
  LOCAL_PARA_HDR
  te_ir_cell_change_complete_status ir_cell_change_complete_status;
  /*Byron: 2007/05/08: Add for real CCO fail cause*/
  te_ir_cell_change_fail_reason_enum ir_cell_change_failed_reason;
}gas_uas_ucell_change_complete_ind_struct;


typedef struct {
  LOCAL_PARA_HDR
  kal_uint8 cell_change_timeout; /* value in seconds or zero when not required */
  te_ir_cell_reselection_type ir_cell_reselection_type;
  te_ir_cell_change_trigger ir_cell_change_trigger;
  plmn_search_type_enum plmn_search_type;
  GSM_TargetCellInfo target_Gcell_info;
  kal_bool nc_mode_present; /* if TRUE nc_mode is present */
  kal_uint8  nc_mode; /* Optional, present if nc_mode_present is TRUE */
}uas_gas_evaluate_gcell_req_struct;

typedef struct {
  LOCAL_PARA_HDR
  kal_uint16 cell_change_timeout; /* value in seconds or zero when not required in msecs*/
  te_ir_cell_reselection_type ir_cell_reselection_type;
  te_ir_cell_change_trigger ir_cell_change_trigger;
  kal_uint16 cell_change_activation_time; /* msecs, */ /*Byron: 2007/05/08: Add for correct CCO handling*/
  GSM_TargetCellInfoList target_Gcell_info_list;
  plmn_search_type_enum plmn_search_type;
  kal_bool nc_mode_present; /* if TRUE nc_mode is present */
  kal_uint8  nc_mode; /* Optional, present if nc_mode_present is TRUE */
  kal_uint8  wait_time; /* Seconds: 0~15, GAS should not reselect back to UMTS within "wait_time" period */
#if (defined(__UMTS_R5__) && defined(__GERAN_R5__))
  GERAN_SysInfoType  sys_info_type; /* For 3G to 2G NACC */
  GERAN_SystemInformation  sys_info; /* Ignore this unless sys_info_type is SI or PSI */
#endif
}uas_gas_activate_gcell_req_struct;

typedef struct {
  LOCAL_PARA_HDR
}uas_gas_evaluate_gcell_stop_req_struct;

typedef struct {
  LOCAL_PARA_HDR
  kal_int8 q_rxlev_min; /* Range -115 to -25 dBm */
  kal_uint8 p_compensation; /* Range 0 to 12 dBm */
}uas_gas_cell_reselection_params_req_struct;
#if 0 /*brwang, 20080830, this definition should be placed before uas_gas_evaluate_gcell_req_struct*/
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


#if (defined(__UMTS_R5__) && defined(__GERAN_R5__))
typedef struct {
   LOCAL_PARA_HDR
   kal_bool isCompressedVersion;   
} gas_uas_ho_umts_info_ind_struct;

typedef struct {
   LOCAL_PARA_HDR
   kal_bool isCompressedVersion;   
} gas_uas_ho_umts_info_rsp_struct;

#endif

#ifdef __CSG_SUPPORT__
#define MAX_NUM_ACSGL_PLMN_LIST 8
#define MAX_NUM_CSG_CARRIERS 8
#define MAX_NR_OF_CSG_CELLS_IN_CELL_LIST 8

typedef struct
{
    kal_uint16	scrambling_code;
    kal_uint8	cpich_rscp;
    kal_uint8	cpich_ec_n0;

} ir_reported_fdd_cells_csg_meas_info;

typedef struct
{
    kal_uint16	uarfcn;
    kal_uint8	uarfcn_rssi;
    kal_uint8	num_reported_cells;
    ir_reported_fdd_cells_csg_meas_info	    ir_reported_fdd_cells_csg_meas_info[MAX_NR_OF_CSG_CELLS_IN_CELL_LIST];

} ir_umts_carrier_csg_meas_results;

typedef struct
{
    kal_bool	is_best_cell_suitable_allowed_CSG;
    ir_umts_carrier_csg_meas_results	ir_umts_carrier_csg_meas_reults;
} ts_3G_csg_ucell_evluation_result;


typedef struct{
    LOCAL_PARA_HDR
    kal_uint8         num_plmn_list;
    plmn_id_struct acsgl_plmn_list[MAX_NUM_ACSGL_PLMN_LIST];
} uas_gas_acsgl_plmn_list_ind_struct;

typedef struct{
    LOCAL_PARA_HDR
    plmn_search_type_enum plmn_search_type;
    kal_uint8        num_carriers;
    kal_uint16      csg_uarfcn[MAX_NUM_CSG_CARRIERS];
} gas_uas_search_csg_ucell_req_struct;

typedef struct{
    LOCAL_PARA_HDR
    kal_uint8         num_carriers;
    ts_3G_csg_ucell_evluation_result ts_3G_csg_ucell_evluation_result[MAX_NUM_CSG_CARRIERS];
} gas_uas_search_csg_ucell_cnf_struct;

typedef struct{
    LOCAL_PARA_HDR
    plmn_search_type_enum plmn_search_type;
    kal_uint8        num_carriers;
    kal_uint16      csg_uarfcn[MAX_NUM_CSG_CARRIERS];
} gas_uas_evaluate_csg_ucell_req_struct;

typedef struct{
    LOCAL_PARA_HDR
    kal_uint8         num_carriers;
    ts_3G_csg_ucell_evluation_result ts_3G_csg_ucell_evluation_result[MAX_NUM_CSG_CARRIERS];
} gas_uas_evaluate_csg_ucell_cnf_struct;

#endif /* __CSG_SUPPORT__ */

#if defined(__PRI_RESEL_SUPPORT__) // __UMTS_R8__, __GERAN_R8__
typedef struct {
  LOCAL_PARA_HDR
  kal_uint8 list_ref;
  te_ir_urrc_state urrc_state;
  kal_int16 prio_meas_period;
  CsiGsmCellList gsm_cell_list;
}uas_gas_config_gcell_prio_meas_req_struct;

typedef struct {
  LOCAL_PARA_HDR
}gas_uas_config_ucell_prio_meas_cnf_struct;

typedef struct
{
   LOCAL_PARA_HDR
}uas_gas_config_gcell_prio_meas_cnf_struct;

typedef struct {
  LOCAL_PARA_HDR
  kal_uint8 list_ref;
  kal_int16 prio_meas_period;
  CsiUmtsCellList umts_cell_list;
  kal_int8 fdd_rscp_min_in_dbm;
  kal_uint16 first_meas_uarfcn; // invalid value = UAS_GAS_INVALID_UARFCN
}gas_uas_config_ucell_prio_meas_req_struct;
#endif // __PRI_RESEL_SUPPORT__

#ifdef __WCDMA_PREFERRED__
typedef struct {
  LOCAL_PARA_HDR
  kal_int8 wcdma_preferred_rscp_threshold;
  kal_int8 wcdma_preferred_ecn0_threshold;
  kal_uint8 offset_2g_rssi_penalty; /* dbm*/
}gas_uas_wcdma_prefer_params_ind_struct;
#endif /* __WCDMA_PREFERRED__ */
#endif /* _UAS_GAS_STRUCT_H */


