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
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2001
 *
 *******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *   l4c_msg_hdlr_defs.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   l4 related message / handler function mapping
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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

//#ifdef __MOD_CSM__
L4C_CNF(MSG_ID_L4CCSM_CC_STARTUP_CNF, l4ccsm_cc_startup_cnf_hdlr)
//#ifdef __MOD_SMU__
L4C_CNF(MSG_ID_L4CCSM_CC_ACM_RESET_CNF,l4ccsm_cc_acm_reset_cnf_hdlr)
L4C_CNF(MSG_ID_L4CCSM_CC_ACMMAX_SET_CNF,l4ccsm_cc_acmmax_set_cnf_hdlr)
//#endif /* __MOD_SMU__ */ 
L4C_CNF(MSG_ID_L4CCSM_CC_LAST_CCM_RESET_CNF,l4ccsm_cc_ccm_reset_cnf_hdlr)
L4C_CNF(MSG_ID_L4CCSM_CC_CRSS_CNF,l4ccsm_cc_crss_cnf_hdlr)
L4C_CNF(MSG_ID_L4CCSM_CC_CALL_DEFLECTION_CNF,l4ccsm_cc_call_deflection_cnf_hdlr)
L4C_CNF(MSG_ID_L4CCSM_CC_START_DTMF_CNF,l4ccsm_cc_start_dtmf_cnf_hdlr)
L4C_CNF(MSG_ID_L4CCSM_CC_STOP_DTMF_CNF,l4ccsm_cc_stop_dtmf_cnf_hdlr)
L4C_CNF(MSG_ID_L4CCSM_CC_CALL_ACCEPT_CNF,l4ccsm_cc_call_accept_cnf_hdlr)
L4C_CNF(MSG_ID_L4CCSM_CC_CALL_MODIFY_CNF,l4ccsm_cc_call_modify_cnf_hdlr)
L4C_CNF(MSG_ID_L4CCSM_CC_CALL_SETUP_CNF,l4ccsm_cc_call_setup_cnf_hdlr)
L4C_CNF(MSG_ID_L4CCSM_CC_CALL_DISC_CNF,l4ccsm_cc_call_disc_cnf_hdlr)
L4C_CNF(MSG_ID_L4CCSM_CC_EMERGENCY_CALL_SETUP_CNF,l4ccsm_cc_call_setup_cnf_hdlr) /* not implemented yet */
#if defined(__TCPIP_OVER_CSD__)
L4C_CNF(MSG_ID_L4CCSM_CC_SET_CSD_PROF_CNF,l4ccsm_cc_set_csd_prof_cnf_hdlr)
#endif
L4C_CNF(MSG_ID_L4CCSM_CC_SAT_SETUP_CNF,l4ccsm_cc_sat_setup_cnf_hdlr)
L4C_CNF(MSG_ID_L4CCSM_CC_SAT_SEND_DTMF_CNF,l4ccsm_cc_sat_send_dtmf_cnf_hdlr)
L4C_CNF(MSG_ID_L4CCSM_CC_UPDATE_ALS_CNF,l4ccsm_cc_update_als_cnf_hdlr)

L4C_CNF(MSG_ID_L4CCSM_CISS_STARTUP_CNF,l4ccsm_ciss_startup_cnf_hdlr)
L4C_CNF(MSG_ID_L4CCSM_CISS_SS_PARSE_CNF,l4ccsm_ciss_ss_parse_cnf_hdlr)
L4C_CNF(MSG_ID_L4CCSM_CISS_CF_END_CNF,l4ccsm_ciss_cf_end_cnf_hdlr)
L4C_CNF(MSG_ID_L4CCSM_CISS_CW_END_CNF,l4ccsm_ciss_cw_end_cnf_hdlr)
L4C_CNF(MSG_ID_L4CCSM_CISS_CB_END_CNF,l4ccsm_ciss_cb_end_cnf_hdlr)
L4C_CNF(MSG_ID_L4CCSM_CISS_EMLPP_END_CNF,l4ccsm_ciss_emlpp_end_cnf_hdlr)
L4C_CNF(MSG_ID_L4CCSM_CISS_CLI_END_CNF,l4ccsm_ciss_cli_end_cnf_hdlr)
L4C_CNF(MSG_ID_L4CCSM_CISS_CCBS_END_CNF,l4ccsm_ciss_ccbs_end_cnf_hdlr)
L4C_CNF(MSG_ID_L4CCSM_CISS_PUSSR_END_CNF,l4ccsm_ciss_pussr_end_cnf_hdlr)
L4C_CNF(MSG_ID_L4CCSM_CISS_USSR_END_CNF,l4ccsm_ciss_ussd_end_cnf_hdlr)           /* not implemented yet */
L4C_CNF(MSG_ID_L4CCSM_CISS_USSN_END_CNF,l4ccsm_ciss_ussn_end_cnf_hdlr)
//#ifdef __SAT__
L4C_CNF(MSG_ID_L4CCSM_CISS_SIM_END_CNF,l4ccsm_ciss_sim_end_cnf_hdlr)
//#endif

//SSAGPS
#ifdef __AGPS_CONTROL_PLANE__
L4C_CNF(MSG_ID_L4CCSM_CISS_AERP_END_CNF,l4ccsm_ciss_aerp_end_cnf_hdlr)
L4C_CNF(MSG_ID_L4CCSM_CISS_MOLR_END_CNF,l4ccsm_ciss_molr_end_cnf_hdlr)
#endif
//#endif /* __MOD_CSM__ */ 

//#ifdef __MOD_UEM__
L4C_CNF(MSG_ID_L4CUEM_STARTUP_CNF,l4cuem_startup_cnf_hdlr)
L4C_CNF(MSG_ID_L4CUEM_SET_AUDIO_PROFILE_CNF,l4cuem_set_audio_profile_cnf_hdlr)
L4C_CNF(MSG_ID_L4CUEM_SET_AUDIO_PARAM_CNF,l4cuem_set_audio_param_cnf_hdlr)
L4C_CNF(MSG_ID_L4CUEM_SET_HW_LEVEL_CNF,l4cuem_set_hw_level_cnf_hdlr)
L4C_CNF(MSG_ID_L4CUEM_AUDIO_PLAY_BY_NAME_CNF,l4cuem_audio_play_by_name_cnf_hdlr)
L4C_CNF(MSG_ID_L4CUEM_AUDIO_STOP_BY_NAME_CNF,l4cuem_audio_stop_by_name_cnf_hdlr)
L4C_CNF(MSG_ID_L4CUEM_AUDIO_PLAY_BY_STRING_CNF,l4cuem_audio_play_by_string_cnf_hdlr)
L4C_CNF(MSG_ID_L4CUEM_AUDIO_STOP_BY_STRING_CNF,l4cuem_audio_stop_by_string_cnf_hdlr)
#if defined(__NONE_USED_L4MMI_MESSAGE__)
L4C_CNF(MSG_ID_L4CUEM_VM_RECORD_CNF,l4cuem_vm_general_cnf_hdlr)  /* voice memo related */
L4C_CNF(MSG_ID_L4CUEM_VM_PLAY_CNF,l4cuem_vm_general_cnf_hdlr)
L4C_CNF(MSG_ID_L4CUEM_VM_STOP_CNF,l4cuem_vm_stop_cnf_hdlr)
L4C_CNF(MSG_ID_L4CUEM_VM_DELETE_CNF,l4cuem_vm_general_cnf_hdlr)
L4C_CNF(MSG_ID_L4CUEM_VM_ABORT_CNF,l4cuem_vm_general_cnf_hdlr)
L4C_CNF(MSG_ID_L4CUEM_VM_PAUSE_CNF,l4cuem_vm_pause_cnf_hdlr)
L4C_CNF(MSG_ID_L4CUEM_VM_RESUME_CNF,l4cuem_vm_general_cnf_hdlr)
L4C_CNF(MSG_ID_L4CUEM_VM_APPEND_CNF,l4cuem_vm_general_cnf_hdlr)
L4C_CNF(MSG_ID_L4CUEM_VM_GET_INFO_CNF,l4cuem_vm_get_info_cnf_hdlr)
L4C_CNF(MSG_ID_L4CUEM_VM_RENAME_CNF,l4cuem_vm_general_cnf_hdlr)
#endif /* __NONE_USED_L4MMI_MESSAGE__ */ 
//#endif /* __MOD_UEM__ */ 

//#ifdef __MOD_RAC__
L4C_CNF(MSG_ID_L4CRAC_ACT_CNF,l4crac_act_cnf_hdlr)
L4C_CNF(MSG_ID_L4CRAC_REG_CNF,l4crac_reg_cnf_hdlr)
L4C_CNF(MSG_ID_L4CRAC_PS_REG_CNF,l4crac_ps_reg_cnf_hdlr)
L4C_CNF(MSG_ID_L4CRAC_DEREG_CNF,l4crac_dereg_cnf_hdlr)
L4C_CNF(MSG_ID_L4CRAC_PLMN_LIST_CNF,l4crac_plmn_list_cnf_hdlr)
L4C_CNF(MSG_ID_L4CRAC_CLASS_CHANGE_CNF,l4crac_class_change_cnf_hdlr)
L4C_CNF(MSG_ID_L4CRAC_SET_PREFERRED_BAND_CNF,l4crac_set_preferred_band_cnf_hdlr) //tommy 030610 add for band selection
L4C_CNF(MSG_ID_L4CRAC_RFOFF_CNF,l4crac_rfoff_cnf_hdlr)
L4C_CNF(MSG_ID_L4CRAC_SET_ROAMING_MODE_CNF,l4crac_set_roaming_mode_cnf_hdlr)
L4C_CNF(MSG_ID_L4CRAC_PLMN_SEARCH_CNF,l4crac_plmn_search_cnf_hdlr)
L4C_CNF(MSG_ID_L4CRAC_SET_RAT_MODE_CNF,l4crac_set_rat_mode_cnf_hdlr)
L4C_CNF(MSG_ID_L4CRAC_PLMN_LIST_STOP_CNF,l4crac_plmn_list_stop_cnf_hdlr)
L4C_CNF(MSG_ID_L4CRAC_SET_PREFER_RAT_CNF,l4crac_set_prefer_rat_cnf_hdlr)
L4C_CNF(MSG_ID_L4CRAC_END_PS_DATA_SESSION_CNF,l4crac_end_ps_data_session_cnf_hdlr) //mtk02475: for Fast Dormancy
L4C_CNF(MSG_ID_L4CRAC_CSG_LIST_CNF,l4crac_csg_list_cnf_hdlr)
L4C_CNF(MSG_ID_L4CRAC_CSG_LIST_STOP_CNF,l4crac_csg_list_stop_cnf_hdlr) 
#if defined(__2STAGE_NW_SELECTION__)
L4C_CNF(MSG_ID_L4CRAC_SUSP_RESU_UPDATE_CNF,l4crac_susp_resu_update_cnf_hdlr)
#endif

//#endif /* __MOD_RAC__ */ 

//#ifdef __MOD_PHB__
L4C_CNF(MSG_ID_L4CPHB_INIT_LN_CNF,l4cphb_init_ln_cnf_hdlr)
L4C_CNF(MSG_ID_L4CPHB_STARTUP_CNF,l4cphb_startup_cnf_hdlr)
L4C_CNF(MSG_ID_L4CPHB_SEARCH_CNF,l4cphb_search_cnf_hdlr)
L4C_CNF(MSG_ID_L4CPHB_READ_CNF,l4cphb_read_cnf_hdlr)
L4C_CNF(MSG_ID_L4CPHB_WRITE_CNF,l4cphb_write_cnf_hdlr)
L4C_CNF(MSG_ID_L4CPHB_DELETE_CNF,l4cphb_delete_cnf_hdlr)
L4C_CNF(MSG_ID_L4CPHB_READ_LN_CNF,l4cphb_read_ln_cnf_hdlr)
L4C_CNF(MSG_ID_L4CPHB_WRITE_LN_CNF,l4cphb_write_ln_cnf_hdlr)
L4C_CNF(MSG_ID_L4CPHB_DELETE_LN_CNF,l4cphb_delete_ln_cnf_hdlr)
L4C_CNF(MSG_ID_L4CPHB_APPROVE_CNF,l4cphb_approve_cnf_hdlr)
L4C_CNF(MSG_ID_L4CPHB_SYNC_CNF,l4cphb_sync_cnf_hdlr)
L4C_CNF(MSG_ID_L4CPHB_WRITE_USIM_CNF,l4cphb_write_usim_cnf_hdlr)
L4C_CNF(MSG_ID_L4CPHB_READ_USIM_CNF,l4cphb_read_usim_cnf_hdlr)
L4C_CNF(MSG_ID_L4CPHB_DELETE_USIM_CNF,l4cphb_delete_usim_cnf_hdlr)
L4C_CNF(MSG_ID_L4CPHB_CHECK_WRITE_USIM_ENTRY_CNF,l4cphb_check_write_usim_entry_cnf_hdlr)
#ifdef __CANCEL_LOCK_POWERON__         
L4C_CNF(MSG_ID_L4CPHB_INIT_ME_LN_CNF,l4cphb_init_me_ln_cnf_hdlr)
L4C_CNF(MSG_ID_L4CPHB_INIT_ME_PHB_CNF,l4cphb_init_me_phb_cnf_hdlr)
#endif
L4C_CNF(MSG_ID_L4CPHB_FDN_GET_NAME_CNF,l4cphb_fdn_get_name_cnf)
#ifdef __PHB_ACCESS_SIM_LN__
L4C_CNF(MSG_ID_L4CPHB_READ_SIM_LN_CNF,l4cphb_read_sim_ln_cnf)
L4C_CNF(MSG_ID_L4CPHB_WRITE_SIM_LN_CNF,l4cphb_write_sim_ln_cnf)
L4C_CNF(MSG_ID_L4CPHB_DELETE_SIM_LN_CNF,l4cphb_delete_sim_ln_cnf)
#endif
//#endif /* __MOD_PHB__ */ 

//#ifdef __MOD_SMU__
L4C_CNF(MSG_ID_L4CSMU_START_CNF,l4csmu_start_cnf_hdlr)
L4C_CNF(MSG_ID_L4CSMU_SECURITY_CNF,l4csmu_security_cnf_hdlr)
L4C_CNF(MSG_ID_L4CSMU_SET_PERSONALIZATION_CNF,l4csmu_set_personalization_cnf_hdlr) /* SML */
L4C_CNF(MSG_ID_L4CSMU_GET_SHARED_KEY_CNF,l4csmu_get_shared_key_cnf_hdlr) /* SML */
L4C_CNF(MSG_ID_L4CSMU_UPDATE_SLB_CNF,l4csmu_update_slb_cnf_hdlr) /* SML */
L4C_CNF(MSG_ID_L4CSMU_RESET_SLB_CNF,l4csmu_reset_slb_cnf_hdlr) /* SML */
L4C_CNF(MSG_ID_L4CSMU_GET_SLB_VERSION_CNF,l4csmu_get_slb_version_cnf_hdlr) /* SML */
L4C_CNF(MSG_ID_L4CSMU_GET_SIM_LOCK_STATUS_CNF,l4csmu_get_sim_lock_status_cnf_hdlr) /* SML */
L4C_CNF(MSG_ID_L4CSMU_SML_EVENT_IND,l4csmu_sml_event_ind_hdlr) /* SML */
L4C_CNF(MSG_ID_L4CSMU_SML_STATUS_CNF,l4csmu_sml_status_cnf_hdlr) /* SML */
L4C_CNF(MSG_ID_L4CSMU_PLMN_SEL_WRITE_CNF,l4csmu_plmn_sel_write_cnf_hdlr)
L4C_CNF(MSG_ID_L4CSMU_SIM_ACCESS_CNF,l4csmu_sim_access_cnf_hdlr)
L4C_CNF(MSG_ID_L4CSMU_PUCT_WRITE_CNF,l4csmu_puct_write_cnf_hdlr)
L4C_CNF(MSG_ID_L4CSMU_CSP_READ_CNF,l4c_null_hdlr)
#if defined (__SMS_DEPERSONALIZATION__)
L4C_CNF(MSG_ID_L4CSMU_SMS_DEPERSONALIZATION_CNF,l4csmu_sms_depersonalization_cnf_hdlr)
#endif
L4C_CNF(MSG_ID_L4CSMU_DIAL_MODE_CNF,l4csmu_dial_mode_cnf_hdlr)
L4C_CNF(MSG_ID_L4CSMU_PUCT_READ_CNF,l4c_null_hdlr)
//#endif /* __MOD_SMU__ */ 

//#ifdef __SAT__
L4C_CNF(MSG_ID_SAT_MENU_SELECT_CNF,l4csat_menu_select_cnf_hdlr)
//#endif
#ifdef __SATCE__
L4C_CNF(MSG_ID_L4CSMU_SAT_OPEN_CHANNEL_CNF,l4csmu_sat_open_channel_cnf_hdlr)
#endif /* __SATCE__ */ 
/* SATcE End */

//#ifdef __MOD_SMSAL__
L4C_CNF(MSG_ID_L4CSMSAL_INIT_CNF,l4csmsal_init_cnf_hdlr)
L4C_CNF(MSG_ID_L4CSMSAL_READ_CNF,l4csmsal_read_cnf_hdlr)
L4C_CNF(MSG_ID_L4CSMSAL_SEND_CNF,l4csmsal_send_cnf_hdlr)
L4C_CNF(MSG_ID_L4CSMSAL_WRITE_CNF,l4csmsal_write_cnf_hdlr)
L4C_CNF(MSG_ID_L4CSMSAL_DELETE_CNF,l4csmsal_delete_cnf_hdlr)
L4C_CNF(MSG_ID_L4CSMSAL_SEND_FROM_STORAGE_CNF,l4csmsal_send_storage_cnf_hdlr)
L4C_CNF(MSG_ID_L4CSMSAL_SEND_ABORT_CNF,l4csmsal_send_abort_cnf_hdlr)
L4C_CNF(MSG_ID_L4CSMSAL_SEND_DELIVER_REPORT_CNF,l4csmsal_send_deliver_report_cnf_hdlr) 
//#ifdef __SAT__
L4C_CNF(MSG_ID_L4CSMSAL_SAT_SEND_CNF,l4csmsal_sat_send_cnf_hdlr)
//#endif
//#ifdef __CB__
L4C_CNF(MSG_ID_L4CSMSAL_CB_UPDATE_CNF,l4csmsal_cb_update_cnf_hdlr)
//#endif
L4C_CNF(MSG_ID_L4CSMSAL_SET_COMMON_PARA_CNF,l4csmsal_set_common_para_cnf_hdlr)
L4C_CNF(MSG_ID_L4CSMSAL_SET_PROFILE_PARA_CNF,l4csmsal_set_profile_para_cnf_hdlr)
L4C_CNF(MSG_ID_L4CSMSAL_COPY_MSG_CNF,l4csmsal_copy_msg_cnf_hdlr)
L4C_CNF(MSG_ID_L4CSMSAL_SET_STATUS_CNF,l4csmsal_set_status_cnf_hdlr)
L4C_CNF(MSG_ID_L4CSMSAL_GET_MAILBOX_NUM_CNF,l4csmsal_get_mailbox_num_cnf_hdlr)
#ifdef __CANCEL_LOCK_POWERON__           
L4C_CNF(MSG_ID_L4CSMSAL_INIT_ME_SMS_CNF,l4csmsal_init_me_sms_cnf_hdlr)
#endif
L4C_CNF(MSG_ID_L4CSMSAL_SET_MSG_WAITING_CNF,l4csmsal_set_msg_waiting_cnf_hdlr)
#ifdef __SMS_RAW_DATA_ACCESS_SUPPORT__           
L4C_CNF(MSG_ID_L4CSMSAL_READ_RAW_DATA_CNF,l4csmsal_read_raw_data_cnf_hdlr)
L4C_CNF(MSG_ID_L4CSMSAL_WRITE_RAW_DATA_CNF,l4csmsal_write_raw_data_cnf_hdlr)
#endif
//#endif /* __MOD_SMSAL__ */ 

//#ifdef __MOD_TCM__
L4C_CNF(MSG_ID_TCM_PDP_ACTIVATE_CNF,tcm_pdp_activate_cnf_hdlr)
L4C_CNF(MSG_ID_TCM_PDP_ACTIVATE_REJ,tcm_pdp_activate_rej_hdlr)
L4C_CNF(MSG_ID_TCM_PDP_DEACTIVATE_CNF,tcm_pdp_deactivate_cnf_hdlr)
#ifdef __APP_SECONDARY_PDP_SUPPORT__
L4C_CNF(MSG_ID_TCM_PDP_REACTIVATE_CNF,tcm_pdp_reactivate_cnf_hdlr)
#endif
L4C_CNF(MSG_ID_TCM_PDP_MODIFY_CNF,tcm_pdp_modify_cnf_hdlr)
L4C_CNF(MSG_ID_TCM_PDP_MODIFY_REJ,tcm_pdp_modify_rej_hdlr)
L4C_CNF(MSG_ID_L4CTCM_START_CNF,l4ctcm_start_cnf_hdlr)
L4C_CNF(MSG_ID_L4CTCM_SET_PRI_PDP_INFO_CNF,l4ctcm_set_cnf_hdlr)
L4C_CNF(MSG_ID_L4CTCM_SET_SEC_PDP_INFO_CNF,l4ctcm_set_cnf_hdlr)
L4C_CNF(MSG_ID_L4CTCM_SET_QOS_INFO_CNF,l4ctcm_set_cnf_hdlr)
L4C_CNF(MSG_ID_L4CTCM_SET_EQOS_INFO_CNF,l4ctcm_set_cnf_hdlr) /* CH_Liang 2005/08/04 R99  feature */
L4C_CNF(MSG_ID_L4CTCM_SET_TFT_INFO_CNF,l4ctcm_set_cnf_hdlr)
L4C_CNF(MSG_ID_L4CTCM_SET_GPRS_STATISTICS_INFO_CNF,l4ctcm_set_cnf_hdlr)
L4C_CNF(MSG_ID_L4CTCM_SET_PPP_AUTH_CNF,l4ctcm_set_cnf_hdlr) //tommy add 031015 for danny 
L4C_CNF(MSG_ID_L4CTCM_SET_MSQ_MODE_CNF,l4ctcm_set_cnf_hdlr) /* __MEDIATEK_SMART_QOS__ */
L4C_CNF(MSG_ID_L4CTCM_SET_MSQ_ENTRY_CNF,l4ctcm_set_cnf_hdlr) /* __MEDIATEK_SMART_QOS__ */
L4C_CNF(MSG_ID_L4CTCM_UNDEFINE_PDP_INFO_CNF,l4ctcm_set_cnf_hdlr) //mtk00714 w0633: AT definition
L4C_CNF(MSG_ID_L4CTCM_SET_ACL_MODE_CNF,l4ctcm_set_acl_mode_cnf_hdlr)
L4C_CNF(MSG_ID_L4CTCM_GET_ACL_ENTRIES_CNF,l4ctcm_get_acl_entries_cnf_hdlr)
L4C_CNF(MSG_ID_L4CTCM_SET_ACL_ENTRY_CNF,l4ctcm_set_acl_entry_cnf_hdlr)
L4C_CNF(MSG_ID_L4CTCM_ADD_ACL_ENTRY_CNF,l4ctcm_add_acl_entry_cnf_hdlr)
L4C_CNF(MSG_ID_L4CTCM_DEL_ACL_ENTRY_CNF,l4ctcm_del_acl_entry_cnf_hdlr)
#if defined(__EXT_PDP_CONTEXT_ON__) && defined(__PS_DIALUP__)
L4C_CNF(MSG_ID_L4CPPP_ACTIVATE_CNF,l4cppp_activate_cnf_hdlr)
L4C_CNF(MSG_ID_L4CPPP_DEACTIVATE_CNF,l4cppp_deactivate_cnf_hdlr)
L4C_CNF(MSG_ID_L4CPPP_RESUME_CNF,l4cppp_resume_cnf_hdlr)
#else
L4C_CNF(MSG_ID_L4CPPP_ACTIVATE_CNF,l4c_null_hdlr)
L4C_CNF(MSG_ID_L4CPPP_DEACTIVATE_CNF,l4c_null_hdlr)
L4C_CNF(MSG_ID_L4CPPP_RESUME_CNF,l4c_null_hdlr)
#endif
L4C_CNF(MSG_ID_L4CABM_SET_GPRS_ACCOUNT_INFO_CNF,l4c_ps_abm_set_gprs_account_info_cnf_hdlr) //modify in W04.11 for change gprs account from tcm to abm
L4C_CNF(MSG_ID_L4CABM_GET_GPRS_ACCOUNT_INFO_CNF,l4c_ps_abm_get_gprs_account_info_cnf_hdlr)
#ifdef __NDIS_SUPPORT__
L4C_CNF(MSG_ID_L4CTCM_ENTER_DATA_MODE_CNF,l4ctcm_enter_data_mode_cnf_handler) //mtk00758: for WM +CGDATA = M-WM
L4C_CNF(MSG_ID_L4CTCM_SET_CONFIG_OPTION_CNF,l4ctcm_set_config_option_cnf_handler) 
#elif __TCM_UT__  // Poying: Add for TCM_UT
L4C_CNF(MSG_ID_L4CTCM_ENTER_DATA_MODE_CNF,l4c_null_hdlr)
L4C_CNF(MSG_ID_L4CTCM_SET_CONFIG_OPTION_CNF,l4c_null_hdlr) 
#endif /* __NDIS_SUPPORT__ */ 
L4C_CNF(MSG_ID_L4CTCM_QUERY_EXT_GPRS_HISTORY_RSP,l4c_null_hdlr) // R6 optimization
L4C_CNF(MSG_ID_L4CTCM_RESET_EXT_GPRS_HISTORY_CNF,l4c_null_hdlr) // R6 optimization
L4C_CNF(MSG_ID_L4CTCM_GET_GPRS_STATISTICS_INFO_RSP,l4c_null_hdlr)
//#endif /* __MOD_TCM__ */ 

#ifdef __TCPIP__
L4C_CNF(MSG_ID_L4CABM_START_CNF,l4c_ps_abm_start_cnf_hdlr) //modify in W04.11 for ask abm start after phonebook startup
#else
L4C_CNF(MSG_ID_L4CABM_START_CNF,l4c_null_hdlr) //modify in W04.11 for ask abm start after phonebook startup
#endif

#if defined(__TCPIP_OVER_CSD__)
L4C_CNF(MSG_ID_L4CPPP_CSD_ACTIVATE_CNF,l4cppp_csd_activate_cnf_hdlr)
L4C_CNF(MSG_ID_L4CPPP_CSD_DEACTIVATE_CNF,l4cppp_csd_deactivate_cnf_hdlr)
#endif 

#ifdef __CSD_FAX__      /* add by mtk00714 */
L4C_CNF(MSG_ID_L4C_T30_TX_MSG_CNF,l4c_t30_tx_msg_cnf_hdlr) //erica add for FAX
L4C_CNF(MSG_ID_L4C_T30_RX_MSG_CNF,l4c_t30_rx_msg_cnf_hdlr)
L4C_CNF(MSG_ID_L4C_T30_RW_PARAM_CNF,l4c_t30_rw_param_cnf_hdlr)
L4C_CNF(MSG_ID_L4C_T30_TX_BCS_CNF,l4c_t30_tx_bcs_cnf_hdlr)
L4C_CNF(MSG_ID_L4C_T30_RX_BCS_CNF,l4c_t30_rx_bcs_cnf_hdlr)
L4C_CNF(MSG_ID_L4C_T30_TX_SILENCE_CNF,l4c_t30_tx_silence_cnf_hdlr)
L4C_CNF(MSG_ID_L4C_T30_RX_SILENCE_CNF,l4c_t30_rx_silence_cnf_hdlr)
L4C_CNF(MSG_ID_L4C_T30_RW_STR_PARAM_CNF,l4c_t30_rw_str_param_cnf_hdlr)
L4C_CNF(MSG_ID_L4C_T30_TX_PPM_CNF,l4c_t30_tx_ppm_cnf_hdlr) //Robert add
#endif /* __CSD_FAX__ */ 

L4C_CNF(MSG_ID_L4C_OPEN_UART_PORT_CNF,l4c_open_uart_port_cnf_hdlr)
L4C_CNF(MSG_ID_L4C_CLOSE_UART_PORT_CNF,l4c_close_uart_port_cnf_hdlr)

L4C_CNF(MSG_ID_L4C_CHANGE_UART_PORT_CNF,l4c_change_uart_port_cnf_hdlr)

#ifdef __WAP_SUPPORT
L4C_CNF(MSG_ID_L4CWAP_PROF_ACCESS_CNF,l4c_wap_prof_access_cnf_hdlr) //tommy add for profile access confirm message ID
#endif /* WAP_SUPPORT */

/*MSG from DT*/
L4C_CNF(MSG_ID_L4CDT_DOWNLOAD_CNF,l4c_null_hdlr)
L4C_CNF(MSG_ID_L4CDT_UPLOAD_CNF,l4c_null_hdlr)
L4C_CNF(MSG_ID_L4CDT_FILELIST_CNF,l4c_null_hdlr)
L4C_CNF(MSG_ID_L4CDT_FILECOUNT_CNF,l4c_null_hdlr)
L4C_CNF(MSG_ID_L4CDT_DISKINFO_CNF,l4c_null_hdlr)

#ifdef __NBR_CELL_INFO__
L4C_CNF(MSG_ID_L4CPS_NBR_CELL_INFO_START_CNF,l4cps_nbr_cell_info_start_cnf_hdlr)  /*  081107 Lexel: for Cell info */
L4C_CNF(MSG_ID_L4CPS_NBR_CELL_INFO_STOP_CNF,l4cps_nbr_cell_info_stop_cnf_hdlr)   /*  081107 Lexel: for Cell info */
#endif

/* MSG from EXT_MODEM */
#ifdef __EXT_MODEM__
L4C_CNF(MSG_ID_L4C_EXT_MODEM_SETUP_CNF,l4c_ext_modem_setup_cnf_hdlr)
L4C_CNF(MSG_ID_L4C_EXT_MODEM_DISC_CNF,l4c_ext_modem_disc_cnf_hdlr)
#endif /* __EXT_MODEM__ */ 

//#ifdef __MOD_CSM__
L4C_IND(MSG_ID_L4CCSM_CC_ATTACH_IND,l4ccsm_cc_attach_ind_hdlr)
L4C_IND(MSG_ID_L4CCSM_CC_DETACH_IND,l4ccsm_cc_detach_ind_hdlr)
L4C_IND(MSG_ID_L4CCSM_CC_CCM_IND,l4ccsm_cc_ccm_ind_hdlr)
L4C_IND(MSG_ID_L4CCSM_CC_CALL_MODIFY_IND,l4ccsm_cc_call_modify_ind_hdlr)
L4C_IND(MSG_ID_L4CCSM_CC_CALL_SETUP_IND,l4ccsm_cc_call_setup_ind_hdlr)
L4C_IND(MSG_ID_L4CCSM_CC_CALL_ALERT_IND,l4ccsm_cc_call_alert_ind_hdlr)
L4C_IND(MSG_ID_L4CCSM_CC_CALL_CONNECT_IND,l4ccsm_cc_call_connect_ind_hdlr)
L4C_IND(MSG_ID_L4CCSM_CC_CALL_DISC_IND,l4ccsm_cc_call_disc_ind_hdlr)
L4C_IND(MSG_ID_L4CCSM_CC_CALL_REL_IND,l4ccsm_cc_call_rel_ind_hdlr)
L4C_IND(MSG_ID_L4CCSM_CC_PROGRESS_IND,l4c_null_hdlr)
L4C_IND(MSG_ID_L4CCSM_CC_CALL_PROC_IND,l4c_null_hdlr)
L4C_IND(MSG_ID_L4CCSM_CC_NOTIFY_SS_IND,l4ccsm_cc_notify_ss_ind_hdlr)
L4C_IND(MSG_ID_L4CCSM_CC_AUTO_DTMF_START_IND,l4ccsm_cc_auto_dtmf_start_ind_hdlr)
L4C_IND(MSG_ID_L4CCSM_CC_AUTO_DTMF_COMPLETE_IND,l4ccsm_cc_auto_dtmf_compl_ind_hdlr)
L4C_IND(MSG_ID_L4CCSM_CC_CCBS_CALL_DEACTIVATE_IND,l4c_null_hdlr)
L4C_IND(MSG_ID_L4CCSM_CC_CALL_PREEMPT_IND,l4c_null_hdlr)
L4C_IND(MSG_ID_L4CCSM_CC_UART_TRANSFER_IND,l4ccsm_cc_uart_transfer_ind_hdlr)
L4C_IND(MSG_ID_L4CCSM_CC_CSD_EST_IND,l4ccsm_cc_csd_est_ind_hdlr)
L4C_IND(MSG_ID_L4CCSM_CPHS_DISPLAY_ALS_IND,l4ccsm_cphs_display_als_ind_hdlr) /* tommy 030722 add for ripple CPHS feature*/
L4C_IND(MSG_ID_L4CCSM_CC_CALL_INFO_IND,l4ccsm_cc_call_info_ind_hdlr) /* tommy add 031002 for aux turn off loudspeaker and adc pool */
L4C_IND(MSG_ID_L4CCSM_CC_CPI_IND,l4ccsm_cc_cpi_ind_hdlr) //mtk00714 add 20041210 for +ECPI
L4C_IND(MSG_ID_L4CCSM_CC_CALL_SYNC_IND,l4ccsm_cc_call_sync_ind_hdlr) /*mtk00924 add 050727 for indicate MMI to get call info*/
L4C_IND(MSG_ID_L4CCSM_CC_VIDEO_CALL_STATUS_IND,l4ccsm_cc_video_call_status_ind_hdlr)	
L4C_IND(MSG_ID_L4CCSM_CC_UPDATE_CALL_STATE_IND,l4ccsm_cc_update_call_state_ind_hdlr) /* MAUI_01315252, update call state */
L4C_IND(MSG_ID_L4CCSM_CC_CALL_PRESENT_IND,l4ccsm_cc_call_present_ind_hdlr)

#if defined(__TCPIP_OVER_CSD__)
L4C_IND(MSG_ID_L4CPPP_CSD_DEACTIVATE_IND,l4cppp_csd_deactivate_ind_hdlr) /* MAUI_02420727 */
#endif

L4C_IND(MSG_ID_L4CCSM_CISS_USSR_BEGIN_IND,l4ccsm_ciss_ussr_begin_ind_hdlr)
L4C_IND(MSG_ID_L4CCSM_CISS_USSN_BEGIN_IND,l4ccsm_ciss_ussn_begin_ind_hdlr)
L4C_IND(MSG_ID_L4CCSM_CISS_USSR_FAC_IND,l4ccsm_ciss_ussr_fac_ind_hdlr)
L4C_IND(MSG_ID_L4CCSM_CISS_USSN_FAC_IND,l4ccsm_ciss_ussn_fac_ind_hdlr)
L4C_IND(MSG_ID_L4CCSM_CISS_CB_FAC_IND,l4c_null_hdlr)
L4C_IND(MSG_ID_L4CCSM_CPHS_DISPLAY_CFU_IND,l4ccsm_cphs_display_cfu_ind_hdlr) /* tommy 030602 add for paul CPHS feature*/
//SSAGPS
#ifdef __AGPS_CONTROL_PLANE__
L4C_IND(MSG_ID_L4CCSM_CISS_MTLR_BEGIN_IND,l4ccsm_ciss_mtlr_begin_ind_hdlr)
L4C_IND(MSG_ID_L4CCSM_CISS_AERQ_BEGIN_IND,l4ccsm_ciss_aerq_begin_ind_hdlr)
L4C_IND(MSG_ID_L4CCSM_CISS_AERP_FAC_IND,l4ccsm_ciss_aerp_fac_ind_hdlr)
L4C_IND(MSG_ID_L4CCSM_CISS_AECL_BEGIN_IND,l4ccsm_ciss_aecl_begin_ind_hdlr)
L4C_IND(MSG_ID_L4CCSM_CISS_MOLR_FAC_IND,l4ccsm_ciss_molr_fac_ind_hdlr)
#endif
//#endif /* __MOD_CSM__ */ 

#if defined(__NONE_USED_L4MMI_MESSAGE__)
L4C_IND(MSG_ID_L4CUEM_VM_RECORD_FINISH_IND,l4cuem_vm_record_finish_ind_hdlr)
L4C_IND(MSG_ID_L4CUEM_VM_PLAY_FINISH_IND,l4cuem_vm_play_finish_ind_hdlr)
#endif /* __NONE_USED_L4MMI_MESSAGE__ */ 

//#ifdef __MOD_RAC__
//L4C_IND(MSG_ID_L4CRAC_REG_IND,)
L4C_IND(MSG_ID_L4CRAC_REG_STATE_IND,l4crac_reg_state_ind_hdlr)
L4C_IND(MSG_ID_L4CRAC_REG_CAUSE_IND,l4crac_reg_cause_ind_hdlr) // __NW_REG_CAUSE_REPORT__ mtk02285 20090310
// L4C_IND(MSG_ID_L4CRAC_RX_LEVEL_IND,) //rx_level, mtk02285, remove old interface
L4C_IND(MSG_ID_L4CRAC_NW_INFO_IND,l4crac_nw_info_ind_hdlr)
L4C_IND(MSG_ID_L4CRAC_CIPHER_IND,l4crac_cipher_ind_hdlr)
L4C_IND(MSG_ID_L4CRAC_NW_ECC_IND,l4crac_nw_ecc_ind_hdlr)//mtk01616_070905: for R5 ECC category
L4C_IND(MSG_ID_L4CRAC_PS_EVENT_REPORT_IND,l4crac_ps_event_report_ind_hdlr)
#ifdef __HOMEZONE_SUPPORT__
L4C_IND(MSG_ID_L4CRAC_HZ_CELL_INFO_UPDATE_IND,l4crac_hz_cell_info_update_ind_hdlr) /* CH_Liang 2005.05.31 Homezone feature */
L4C_IND(MSG_ID_L4CRAC_HZ_DEDICATED_MODE_IND,l4crac_hz_dedicated_mode_ind_hdlr)
L4C_IND(MSG_ID_L4CRAC_HZ_PKT_TRANSFER_MODE_IND,l4crac_hz_pkt_transfer_mode_ind_hdlr)
#endif /* __HOMEZONE_SUPPORT__ */ 
#ifdef __GEMINI__
L4C_IND(MSG_ID_L4CRAC_SEARCH_NORMAL_FINISH_IND,l4crac_search_normal_finish_ind_hdlr)
L4C_IND(MSG_ID_L4CRAC_MMRR_SERVICE_STATUS_IND,l4crac_mmrr_service_status_ind_hdlr)	// for solving emergecy call issue in Gemini
#endif /* __GEMINI__ */ 
#ifdef __MMDC_TYPE1_DUAL_LOAD__
L4C_IND(MSG_ID_L4CRAC_PEER_REJECT_IND,l4crac_peer_reject_ind_hdlr)
L4C_IND(MSG_ID_L4CRAC_TO_PEER_INFO_IND,l4crac_to_peer_info_ind_hdlr)
#endif
#if defined(__REPORT_AVAILABLE_PLMN__)
L4C_IND(MSG_ID_L4CRAC_PLMN_LIST_IND,l4crac_plmn_list_ind_hdlr)
#endif
#if defined(__2STAGE_NW_SELECTION__)
L4C_IND(MSG_ID_L4CRAC_SUSPEND_STATUS_IND,l4crac_suspend_status_ind_hdlr)
#endif

//#endif /* __MOD_RAC__ */ 

/* SIM BEGIN */	
L4C_IND(MSG_ID_L4CSMU_SECURITY_IND,l4csmu_security_cnf_hdlr)
L4C_IND(MSG_ID_L4CSMU_MMRR_READY_IND,l4csmu_mmrr_ready_ind_hdlr) // 030822 tommy add for power on enhance for Paul	
L4C_IND(MSG_ID_L4CSMU_MMI_INFO_IND,l4csmu_mmi_info_ind_hdlr) // 030609 tommy add for CPHS feature for Paul
#if defined (__SMS_DEPERSONALIZATION__)
L4C_IND(MSG_ID_L4CSMU_SML_STATUS_NOTIFY_IND,l4csmu_sml_status_notify_ind_hdlr)
#endif
L4C_IND(MSG_ID_L4CSMU_GID1_VERIFY_IND,l4csmu_gid1_verify_ind_hdlr)

/* SAT BEGIN */	
//#ifdef __SAT__
L4C_IND(MSG_ID_SAT_DSPL_TEXT_IND,l4csat_dspl_text_ind_hdlr)
L4C_IND(MSG_ID_SAT_GET_INKEY_IND,l4csat_get_inkey_ind_hdlr)
L4C_IND(MSG_ID_SAT_GET_INPUT_IND,l4csat_get_input_ind_hdlr)
L4C_IND(MSG_ID_SAT_SETUP_MENU_IND,l4csat_setup_menu_ind_hdlr)
L4C_IND(MSG_ID_SAT_SELECT_ITEM_IND,l4csat_select_item_ind_hdlr)
L4C_IND(MSG_ID_SAT_PLAY_TONE_IND,l4csat_play_tone_ind_hdlr)
L4C_IND(MSG_ID_SAT_SETUP_CALL_IND,l4csat_setup_call_ind_hdlr)
L4C_IND(MSG_ID_SAT_SEND_SMS_IND,l4csat_send_sms_ind_hdlr)
L4C_IND(MSG_ID_SAT_SEND_SS_IND,l4csat_send_ss_ind_hdlr)
L4C_IND(MSG_ID_SAT_SEND_USSD_IND,l4csat_send_ussd_ind_hdlr)
L4C_IND(MSG_ID_SAT_MMI_INFO_IND,l4csat_mmi_info_ind_hdlr)
/* tommy 030602 add for paul new indication */
L4C_IND(MSG_ID_SAT_SETUP_IDLE_DSPL_IND,l4csat_setup_idle_dspl_ind_hdlr) 
L4C_IND(MSG_ID_SAT_RUN_AT_COMMAND_IND,l4csat_run_at_command_ind_hdlr)
L4C_IND(MSG_ID_SAT_SEND_DTMF_IND,l4csat_send_dtmf_ind_hdlr)
L4C_IND(MSG_ID_SAT_LANG_NOTIFY_IND,l4csat_lang_notify_ind_hdlr)
L4C_IND(MSG_ID_SAT_LAUNCH_BROWSER_IND,l4csat_launch_browser_ind_hdlr)
L4C_IND(MSG_ID_SAT_NO_OTHER_CMD_IND,l4csat_no_other_cmd_ind_hdlr)
L4C_IND(MSG_ID_L4CCSM_CC_SAT_EVDL_CALL_IND,l4ccsm_cc_sat_evdl_call_ind_hdlr)


/* End Benson SATcE */
//#endif /* __SAT__ */ 

#ifdef __SATCE__
//mtk01616_070530 begin
L4C_IND(MSG_ID_L4CSMU_SAT_SET_CSD_PROF_IND,l4csmu_sat_set_csd_prof_ind_hdlr)
L4C_IND(MSG_ID_L4CSMU_SAT_SET_GPRS_PROF_IND,l4csmu_sat_set_gprs_prof_ind_hdlr)
L4C_IND(MSG_ID_L4CSMU_SAT_OPEN_CHANNEL_IND,l4csmu_sat_open_channel_ind_hdlr)
L4C_IND(MSG_ID_L4CSMU_SAT_CLOSE_CHANNEL_IND,l4csmu_sat_close_channel_ind_hdlr)
L4C_IND(MSG_ID_L4CSMU_SAT_SEND_DATA_IND,l4csmu_sat_send_data_ind_hdlr)
L4C_IND(MSG_ID_L4CSMU_SAT_RECV_DATA_IND,l4csmu_sat_recv_data_ind_hdlr)
L4C_IND(MSG_ID_L4CSMU_SAT_NOTIFY_MMI_IND,l4csmu_sat_notify_mmi_ind_hdlr)
//mtk01616_070530 end
#endif /* __SATCE__ */ 

//#ifdef __CB__
L4C_IND(MSG_ID_L4CSMSAL_CB_MSG_TEXT_IND,l4csmsal_cb_msg_text_ind_hdlr)
L4C_IND(MSG_ID_L4CSMSAL_CB_MSG_PDU_IND,l4csmsal_cb_msg_pdu_ind_hdlr)
L4C_IND(MSG_ID_L4CSMSAL_CB_DL_IND,l4c_null_hdlr)
//#endif /* __CB__ */ 
L4C_IND(MSG_ID_L4CSMSAL_MT_SMS_FINAL_ACK_IND,l4csmsal_mt_sms_final_ack_ind_hdlr) 
L4C_IND(MSG_ID_L4CSMSAL_MEM_FULL_IND,l4csmsal_mem_full_ind_hdlr)
L4C_IND(MSG_ID_L4CSMSAL_MEM_EXCEED_IND,l4csmsal_mem_exceed_ind_hdlr)
L4C_IND(MSG_ID_L4CSMSAL_MEM_AVAILABLE_IND,l4csmsal_mem_available_ind_hdlr)
L4C_IND(MSG_ID_L4CSMSAL_MSG_WAITING_IND,l4csmsal_msg_waiting_ind_hdlr)
L4C_IND(MSG_ID_L4CSMSAL_ENHANCED_VOICE_MAIL_IND,l4csmsal_enhanced_voice_mail_ind_hdlr)  
L4C_IND(MSG_ID_L4CSMSAL_NEW_MSG_PDU_IND,l4csmsal_new_msg_pdu_ind_hdlr)
L4C_IND(MSG_ID_L4CSMSAL_NEW_MSG_TEXT_IND,l4csmsal_new_msg_text_ind_hdlr)
L4C_IND(MSG_ID_L4CSMSAL_NEW_MSG_INDEX_IND,l4csmsal_new_msg_index_ind_hdlr)
L4C_IND(MSG_ID_L4CSMSAL_APP_DATA_IND,l4csmsal_app_data_ind_hdlr)
L4C_IND(MSG_ID_L4CSMSAL_SYNC_MSG_IND,l4csmsal_sync_msg_ind_hdlr)
L4C_IND(MSG_ID_L4CSMSAL_STARTUP_READ_MSG_IND,l4csmsal_startup_read_msg_ind_hdlr)
L4C_IND(MSG_ID_L4CSMSAL_STARTUP_BEGIN_IND,l4csmsal_startup_begin_ind_hdlr)
L4C_IND(MSG_ID_L4CSMSAL_STARTUP_FINISH_IND,l4csmsal_startup_finish_ind_hdlr)
L4C_IND(MSG_ID_L4CSMSAL_FDN_CHECK_IND,l4csmsal_fdn_check_ind_hdlr)
L4C_IND(MSG_ID_L4CSMSAL_PPE_CHECK_IND,l4csmsal_ppe_check_ind_hdlr)

#if defined (__SMS_DEPERSONALIZATION__)
L4C_IND(MSG_ID_L4CSMSAL_SMS_DEPERSONALIZATION_IND,l4csmsal_depersonalization_ind_hdlr)
#endif
#ifdef __HOMEZONE_SUPPORT__
L4C_IND(MSG_ID_L4CSMSAL_HZ_CB_MSG_IND,l4csmsal_hz_cb_msg_ind_hdlr) /* temp use */
#endif 
L4C_IND(MSG_ID_L4CSMSAL_CB_GS_CHANGE_IND,l4csmsal_cb_gs_change_ind_hdlr)

#ifdef __CSD_FAX__
L4C_IND(MSG_ID_L4C_T30_READY_IND,l4c_t30_ready_ind_hdlr) //erica add for FAX
L4C_IND(MSG_ID_L4C_T30_TRANSFER_UART_IND,l4c_t30_transfer_uart_ind_hdlr)
L4C_IND(MSG_ID_L4C_T30_REPORT_PARAM_IND,l4c_t30_report_param_ind_hdlr)
L4C_IND(MSG_ID_L4C_T30_TX_BCS_IND,l4c_t30_tx_bcs_ind_hdlr)
L4C_IND(MSG_ID_L4C_T30_VOICE_MODE_IND,l4c_t30_voice_mode_ind_hdlr)
#endif /* __CSD_FAX__ */ 

//#ifdef __MOD_TCM__
L4C_IND(MSG_ID_TCM_PDP_ACTIVATE_IND,tcm_pdp_activate_ind_hdlr)
L4C_IND(MSG_ID_TCM_PDP_DEACTIVATE_IND,tcm_pdp_deactivate_ind_hdlr)
#ifdef __GPRS_BEARER_REPORT_NEGOTIATED_QOS__
L4C_IND(MSG_ID_TCM_PDP_MODIFY_IND,tcm_pdp_modify_ind_hdlr) // __GPRS_BEARER_REPORT_NEGOTIATED_QOS__	
#endif
L4C_IND(MSG_ID_TCM_MOBILITY_STATUS_IND,l4c_null_hdlr)     // mtk02126: NOT USED
L4C_IND(MSG_ID_TCM_EVENT_REP_IND,l4c_null_hdlr)           // mtk02126: Only found in comments
//#if defined(__SP_RIL_SUPPORT__) //TCM should wrapped the code more well
L4C_IND(MSG_ID_L4CTCM_PS_EVENT_REPORT_IND,l4ctcm_ps_event_report_ind_hdlr)
//#endif 
#if defined(__HSDPA_SUPPORT__)
L4C_IND(MSG_ID_L4CTCM_BEARER_CAPABILITY_IND,l4ctcm_bearer_capability_ind_hdlr) //hspa_mmi_h2, mtk02285
#endif 
#if defined(__EXT_PDP_CONTEXT_ON__) && defined(__PS_DIALUP__)    
L4C_IND(MSG_ID_L4CPPP_DEACTIVATE_IND,l4cppp_deactivate_ind_hdlr)
L4C_IND(MSG_ID_L4CPPP_ESCAPE_IND,l4cppp_escape_ind_hdlr)
#else
L4C_IND(MSG_ID_L4CPPP_DEACTIVATE_IND,l4c_null_hdlr)
L4C_IND(MSG_ID_L4CPPP_ESCAPE_IND,l4c_null_hdlr)
#endif
#if defined(__EXT_PDP_CONTEXT_ON__) && defined(__PS_DIALUP__) && defined(__PPP_TYPE_PDP_DIALUP_SUPPORT__)
L4C_IND(MSG_ID_L4CPPP_PPPTYPEPDP_ACTIVATED_IND,l4cppp_ppptypepdp_activated_ind_hdlr) // Carlson 2009.04.18 PPP Type PDP Dialup Feature
#else
L4C_IND(MSG_ID_L4CPPP_PPPTYPEPDP_ACTIVATED_IND,l4c_null_hdlr) // Carlson 2009.04.18 PPP Type PDP Dialup Feature
#endif
#if defined(__EXT_PDP_CONTEXT_ON__) && defined(__PS_DIALUP__) && defined(__IPV4V6__) && defined(__IPV6__)
L4C_IND(MSG_ID_L4CPPP_IPV4V6_FALLBACK_IND,l4cppp_ipv4v6_fallback_ind_hdlr)
L4C_IND(MSG_ID_L4CPPP_INITIAL_IP_TYPE_IND,l4cppp_initial_ip_type_ind_hdlr)
#else
L4C_IND(MSG_ID_L4CPPP_IPV4V6_FALLBACK_IND,l4c_null_hdlr)
L4C_IND(MSG_ID_L4CPPP_INITIAL_IP_TYPE_IND,l4c_null_hdlr)
#endif    
//#endif /* __MOD_TCM__ */ 

L4C_IND(MSG_ID_L4CPHB_STARTUP_BEGIN_IND,l4cphb_startup_begin_ind_hdlr) 
L4C_IND(MSG_ID_L4CPHB_STARTUP_READ_IND,l4cphb_startup_read_ind_hdlr)
L4C_IND(MSG_ID_FLC_STATUS_REPORT_IND,l4c_null_hdlr)

#ifdef __NBR_CELL_INFO__
L4C_IND(MSG_ID_L4CPS_NBR_CELL_INFO_IND,l4cps_nbr_cell_info_ind_hdlr)   /* 081107 Lexel: for Cell info*/
#endif
#ifdef __MMDC_TYPE1_DUAL_LOAD__
L4C_IND(MSG_ID_L4CAS_LTE_CELL_INFO_IND,l4cas_lte_cell_info_hdlr)
L4C_IND(MSG_ID_L4CAS_TO_PEER_INFO_IND, l4cas_to_peer_info_ind_hdlr)
#endif

L4C_IND(MSG_ID_L4CPS_GAS_CELL_POWER_LEVEL_IND,l4cps_gas_cell_power_level_ind_hdlr) //rx_level, mtk02285
#ifdef __UMTS_RAT__
L4C_IND(MSG_ID_L4CPS_UAS_CELL_POWER_LEVEL_IND,l4cps_uas_cell_power_level_ind_hdlr)
#endif

/* MSG from EXT_MODEM */
#ifdef __EXT_MODEM__
L4C_IND(MSG_ID_L4C_EXT_MODEM_DISC_IND,l4c_ext_modem_disc_ind_hdlr)
#endif 

#if defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__)
L4C_IND(MSG_ID_L4CRAC_END_PS_DATA_SESSION_IND, l4crac_end_ps_data_session_ind_hdlr)
#endif

#if defined(__ACMT_SUPPORT__)
L4C_IND(MSG_ID_L4C_PROTOCOL_REJ_IND, l4c_protocol_rej_ind_hdlr)
#endif

#ifdef __TCPIP__
#if defined(__MOD_TCM__) 
#if defined(__INT_PDP_CONTEXT_ON__)
L4C_REQ(MSG_ID_L4C_PS_ABM_SETUP_REQ,l4c_ps_exe_abm_setup_req_hdlr)
L4C_REQ(MSG_ID_L4C_PS_ABM_DISC_REQ,l4c_ps_exe_abm_disc_req_hdlr)
#ifdef __APP_SECONDARY_PDP_SUPPORT__
L4C_REQ(MSG_ID_L4C_PS_ABM_QOS_TFT_MODIFY_REQ,l4c_ps_exe_abm_qos_tft_modify_req_hdlr)	// Karen
L4C_REQ(MSG_ID_L4C_PS_ABM_REACTIVATE_REQ,l4c_ps_exe_abm_reactivate_req_hdlr)
#endif /* __APP_SECONDARY_PDP_SUPPORT__ */ 
#endif /* __INT_PDP_CONTEXT_ON__ */
#endif /* __MOD_TCM__ */ 

#if defined(__TCPIP_OVER_CSD__)
L4C_REQ(MSG_ID_L4C_CC_ABM_SETUP_REQ,l4c_cc_exe_abm_setup_req_hdlr)
L4C_REQ(MSG_ID_L4C_CC_ABM_DISC_REQ,l4c_cc_exe_abm_disc_req_hdlr)
#endif

L4C_REQ(MSG_ID_L4C_ABM_DISALLOW_GPRS_AND_CSD_REQ,l4c_abm_disallow_gprs_and_csd_req_hdlr)
L4C_REQ(MSG_ID_L4C_ABM_ALLOW_GPRS_AND_CSD_REQ,l4c_abm_allow_gprs_and_csd_req_hdlr)

#if defined(__EXT_PDP_CONTEXT_ON__) && defined(__PS_DIALUP__) && defined(__DIALUP_GPRS_COUNTER_SUPPORT__)
#ifdef __MOD_TCM__
L4C_REQ(MSG_ID_L4C_PS_ABM_GET_DIALUP_INFO_REQ,l4c_ps_abm_get_dialup_info_req_hdlr)
L4C_REQ(MSG_ID_L4C_ABM_DIALUP_DISC_REQ,l4c_abm_dialup_disc_req_hdlr)
L4C_REQ(MSG_ID_L4C_PS_ABM_RESET_DIALUP_INFO_REQ,l4c_ps_abm_reset_dialup_info_req_hdlr)
#else
L4C_REQ(MSG_ID_L4C_PS_ABM_GET_DIALUP_INFO_REQ,l4c_null_hdlr)
L4C_REQ(MSG_ID_L4C_ABM_DIALUP_DISC_REQ,l4c_abm_dialup_disc_req_hdlr)
L4C_REQ(MSG_ID_L4C_PS_ABM_RESET_DIALUP_INFO_REQ,l4c_null_hdlr)
#endif     
#else
L4C_REQ(MSG_ID_L4C_PS_ABM_GET_DIALUP_INFO_REQ,l4c_null_hdlr)
L4C_REQ(MSG_ID_L4C_ABM_DIALUP_DISC_REQ,l4c_abm_dialup_disc_req_hdlr)
L4C_REQ(MSG_ID_L4C_PS_ABM_RESET_DIALUP_INFO_REQ,l4c_null_hdlr)
#endif /* defined(__EXT_PDP_CONTEXT_ON__) && defined(__PS_DIALUP__) && defined(__DIALUP_GPRS_COUNTER_SUPPORT__) */ 
#endif /* __TCPIP__ */ 

L4C_REQ(MSG_ID_L4C_OPEN_UART_PORT_REQ,l4c_null_hdlr)
L4C_REQ(MSG_ID_L4C_CLOSE_UART_PORT_REQ,l4c_null_hdlr)

L4C_REQ(MSG_ID_L4C_CHANGE_UART_PORT_REQ,l4c_null_hdlr)


//SS LBS
#ifdef __AGPS_CONTROL_PLANE__ //the following msg will be forwarded to l4c_lbs_message_dispatch()
L4C_REQ(MSG_ID_LBS_MTLR_BEGIN_RES_REQ,l4c_null_hdlr)
L4C_REQ(MSG_ID_LBS_AERQ_BEGIN_RES_REQ,l4c_null_hdlr)
L4C_REQ(MSG_ID_LBS_AERP_BEGIN_REQ,l4c_null_hdlr)
L4C_REQ(MSG_ID_LBS_AERP_END_REQ,l4c_null_hdlr)
L4C_REQ(MSG_ID_LBS_AECL_BEGIN_RES_REQ,l4c_null_hdlr)
L4C_REQ(MSG_ID_LBS_MOLR_BEGIN_REQ,l4c_null_hdlr)
L4C_REQ(MSG_ID_LBS_MOLR_END_REQ,l4c_null_hdlr)
L4C_REQ(MSG_ID_AGPS_ENABLE_DISABLE_REQ,l4c_null_hdlr)
L4C_REQ(MSG_ID_AGPS_KEY_UPDATE_REQ,l4c_null_hdlr)
L4C_REQ(MSG_ID_AGPS_CP_ABORT_REQ,l4c_null_hdlr)
#endif
#ifdef __AGPS_SUPPORT__
L4C_REQ(MSG_ID_L4C_LBS_SERVICE_STATE_REQ,l4c_lbs_service_state_req_hdlr)
L4C_REQ(MSG_ID_L4C_LBS_ROAMING_STATE_REQ,l4c_lbs_roaming_state_req_hdlr)
L4C_REQ(MSG_ID_L4C_LBS_DATA_CONN_STATE_REQ,l4c_lbs_data_conn_state_req_hdlr)
L4C_REQ(MSG_ID_L4C_LBS_CURRENT_RAT_REQ,l4c_lbs_current_rat_req_hdlr)
#endif
