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
 *   em_public_struct_filter.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Engineer mode public structures.
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
 *
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

 
#ifndef _EM_PUBLIC_PARAM_STRUCT_H
#define _EM_PUBLIC_PARAM_STRUCT_H

#include "ps_public_struct.h"
#include "kal_general_types.h"
#include "kal_public_defs.h" 
#include "ps_em_enum.h"

typedef int bool;

typedef enum
{
   RR_CELL_SELECT_PARA_INFO_PARAM,//rr_em_cell_select_para_info_struct -> rr_cell_select_para_info_param_struct
   RR_CHANNEL_DESCR_INFO_PARAM,//rr_em_channel_descr_info_struct
   RR_CTRL_CHANNEL_DESCR_INFO_PARAM,//rr_em_ctrl_channel_descr_info_struct
   RR_RACH_CTRL_PARA_INFO_PARAM,//rr_em_rach_ctrl_para_info_struct
   RR_LAI_INFO_PARAM,//rr_em_lai_info_struct
   RR_RADIO_LINK_COUNTER_INFO_PARAM,//rr_em_radio_link_counter_info_struct
   RR_MEASUREMENT_REPORT_INFO_PARAM,//rr_em_measurement_report_info_struct
   RR_TBF_STATUS_PARAM,//rr_em_tbf_status_struct
   RR_GPRS_GENERAL_INFO_PARAM,//rr_em_gprs_general_info_struct
#ifdef __UMTS_TDD128_MODE__
   RRM_IR_3G_NEIGHBOR_MEAS_STATUS_IND_PARAM,//rrm_em_ir_3g_neighbor_meas_status_ind_struct
#endif   
   MM_INFO_PARAM,//mm_em_info_struct
   GMM_INFO_PARAM,//gmm_em_info_struct
   SM_INFO_PARAM,//sm_em_info_struct
#ifdef __UMTS_RAT__ 
   CSCE_3G_GENERAL_STATUS_IND_PARAM,//csce_em_3g_general_status_ind_struct
   CSCE_SERV_CELL_S_STATUS_IND_PARAM,//csce_em_serv_cell_s_status_ind_struct
   CSCE_CELL_R_STATUS_IND_PARAM,//csce_em_cell_r_status_ind_struct
   MEME_INFO_UMTS_CELL_STATUS_PARAM,//meme_em_info_umts_cell_status_struct
   MEME_INFO_GSM_CELL_STATUS_PARAM,//meme_em_info_gsm_cell_status_struct
#endif
} probe_info_param_enum;

typedef enum
{
	RR_EM_CELL_SELECT_PARA_INFO,
	RR_EM_CHANNEL_DESCR_INFO,
	RR_EM_CTRL_CHANNEL_DESCR_INFO,
	RR_EM_CTRL_CHANNEL_DESCR_INFO,
	RR_EM_RACH_CTRL_PARA_INFO,
	RR_EM_LAI_INFO,
	RR_EM_RADIO_LINK_COUNTER_INFO,
	RR_EM_MEASUREMENT_REPORT_INFO,
	RR_EM_TBF_INFO,
	RR_EM_GPRS_GENERAL_INFO,
#ifdef __UMTS_TDD128_MODE__	
	RRM_EM_IR_3G_NEIGHBOR_MEAS_STATUS_IND_STRUCT_INFO,
#endif
	MM_EM_INFO,
	GMM_EM_INFO,
	SM_EM_INFO,
#ifdef __UMTS_RAT__	
	UAS_3G_GENERAL_STATUS_IND_STRUCT_INFO,
	CSCE_EM_SERV_CELL_IND_STRUCT_INFO,
	CSCE_EM_R_STATUS_IND_STRUCT_INFO,
	MEME_EM_INFO_UMTS_CELL_STATUS_STRUCT_INFO,
	MEME_EM_INFO_GSM_CELL_STATUS_STRUCT_INFO,
#endif
} em_mapping_table_enum;

typedef struct
{
   unsigned char   t3212_val;	//T3212 timer value
   unsigned char   att_flag;	//ATT flag
   unsigned char   mcc[3];	//MCC
   unsigned char   mnc[3];	//MNC
   unsigned char   loc[2];	 //registered LAC
   unsigned char   rac;     //registered RAC
   unsigned char   tmsi[4];	//TMSI, if valid
#if defined(__WISDOM_EM__) || defined(__ADVANCED_EM__)
   unsigned char current_rat;
#endif
} mm_info_param_struct;

typedef struct
{
	unsigned char	ms_state;    //MS_NULL_STATE = 0,
                            //    MS_READY_STATE,
                            //    MS_STANDBY_STATE,
                            //    MS_FORCED_TO_STANDBY_STATE
#if defined(__WISDOM_EM__) || defined(__ADVANCED_EM__)
   unsigned char ptmsi[4]; /* P-TMSI */
#endif
} gmm_info_param_struct;

typedef struct
{
	/* UL TBF info */
	unsigned char ul_ts_allocation;   //Number of TS Used(UL),default value: 0
	                              //No Number Of Used Timeslots(UL)
	unsigned char ul_tfi;             //TFI(UL),default value: 0xff
    /* DL TBF info */
	unsigned char dl_ts_allocation;   // Number of TS Used(DL),default value: 0
	                              //No Number Of Used Timeslots(DL)
	unsigned char dl_tfi;             //TFI(DL),default value: 0xff
} rr_tbf_status_param_struct;


typedef enum                     
{
   RRC_IDLE,  
   RRC_CELL_FACH,
   RRC_CELL_PCH,
   RRC_URA_PCH,
   RRC_CELL_DCH,
   RRC_INACTIVE,
   RRC_NO_CHANGE
 
} rrc_state_param_enum;

typedef struct
{
   rrc_state_param_enum   umts_rrc_state;
} uas_3g_param_status;

typedef struct
{
   unsigned char         ref_count;
   unsigned short        msg_len;
   uas_3g_param_status  uas_3g_general_status;
} csce_3g_general_status_ind_param_struct;


typedef struct
{
   unsigned char   nsapi; // NSAPI 
   unsigned char   ip[16]; // IPv4 address or IPv6 address
   unsigned char   apn[100];
   unsigned char human_readable_neg_delay_class; 
   unsigned char human_readable_neg_reliability_class; 
   unsigned char human_readable_neg_peak_throughput; 
   unsigned char human_readable_neg_precedence_class; 
   unsigned char human_readable_neg_mean_throughput; 
} sm_pdp_info_param_struct;

typedef struct{
   sm_pdp_info_param_struct pdp[11]; // nsapi 5~15
} sm_info_param_struct;

typedef struct
{
   unsigned char      cellidx;            
   int      Treselection;           
   
} csce_cell_r_param_status;

typedef struct
{
   unsigned char                   cell_count;
   csce_cell_r_param_status   cell_r_status[9]; 
         
} csce_cell_r_status_ind_param_struct;

typedef struct
{ 
   signed char          qRxlevmin; 
} csce_serv_cell_s_param_status;

typedef struct
{
   csce_serv_cell_s_param_status      serv_cell;
} csce_serv_cell_s_status_ind_param_struct;

#if defined(__UMTS_TDD128_MODE__)
typedef struct
{    
    unsigned short UARFCN;
    unsigned short CELLPARAID; 
    int RSCP; 
    bool isServingCell;
} meme_umts_cell_param_struct;

typedef struct
{ 
    unsigned char num_cells;
    meme_umts_cell_param_struct umts_cell_list[64];
} meme_info_umts_cell_status_param_struct;
#endif

typedef struct
{    
    unsigned char frequency_band;
    unsigned short arfcn;
    unsigned char bsic;
    short rssi; 
} meme_gsm_cell_param_struct;

typedef struct
{
    unsigned char num_cells;
    meme_gsm_cell_param_struct gsm_cell_list[6];
} meme_info_gsm_cell_status_param_struct;

/* GAS part*/
typedef struct
{
	unsigned char	crh;   //CELL-RESELECT-HYSTERESIS
	unsigned char	ms_txpwr;   // 	maximum TX power level an MS may use when accessing on a CCH
	unsigned char	rxlev_access_min;   //	minimum received signal level at the MS for which it is permitted to access the system
} rr_cell_select_para_info_param_struct;

typedef struct
{
	unsigned char	channel_type;   //	channel type
	unsigned char	tn;   //	timeslot number
	unsigned char	tsc;   //	training sequence code
	unsigned char	hopping_flag;   //	hopping or not
	unsigned char	maio;   //	MAIO value
	unsigned char	hsn;   //	HSN value
	unsigned short	arfcn[64];   //	ARFCN value in the MA
	unsigned short BCCH_arfcn;   
} rr_channel_descr_info_param_struct;	

typedef struct
{
	unsigned char	att;   //	att flag
	unsigned char	bs_ag_blks_res;   //	BS-AG-BLKS-RES
	unsigned char	bs_pa_mfrms;   //	BS-PA-MFRMS
	unsigned char	t3212;   //	T3212 timeout value
} rr_ctrl_channel_descr_info_param_struct;
			
typedef struct
{		
	unsigned char	max_retrans;   //	MAX Retrans value
	unsigned char	tx_integer;   //	TX integer
	unsigned char	cba;   //	cell bar for access
	unsigned char	re;   //	call reestablishment allowed
} rr_rach_ctrl_para_info_param_struct;
			
typedef struct
{			
	short	current_value; 
	unsigned char	dtx_ind;	//DTX indicator
} rr_radio_link_counter_info_param_struct;  
			
typedef struct
{
	unsigned short	serving_arfcn;	//serving cell ARFCN
	unsigned char	serving_bsic;	//serving cell BSIC
	unsigned char serving_current_band;
	short	serv_rla_in_quarter_dbm;

  bool     gprs_c31_c32_enable; 

	short	c1_serv_cell;	
	short	c2_serv_cell;	/* if gprs_c31_c32_enable is false, this field is shown as c2_value for serv_cell
	                              if gprs_c31_c32_enable is true, this field is shown as c32_value for serv_cell */
	short	c31_serv_cell;	/* if gprs_c31_c32_enable is false, this field is ignore
	                              if gprs_c31_c32_enable is true, this field shall be shown in based on report c31_value*/
	                                 
	short	rla_in_quarter_dbm[32];	//rssi level for each carrier
	unsigned char	timing_advance;		//Timing advance, range is 0 - 63
  short tx_power_level; 
  short serv_rla_full_value_in_quater_dbm;
  unsigned char nco;
	unsigned char	rxqual_sub;
	unsigned char	rxqual_full;
	short       using_tx_power_in_dbm; 
} rr_measurement_report_info_param_struct;

typedef struct
{			
	unsigned char	mcc[3];	//MCC
	unsigned char	mnc[3];	//MNC
	unsigned char	lac[2];	//LAC
	unsigned short	cell_id;	 //cell ID
  unsigned char       rac;
#ifdef __PS_SERVICE__
    unsigned char nmo;
#endif
} rr_lai_info_param_struct;

#ifdef __PS_SERVICE__
typedef struct 
{
	unsigned char  gprs_support;
	unsigned char  egprs_support;
}rr_gprs_general_info_param_struct;
#endif /* #ifdef __PS_SERVICE__ */

#ifdef __UMTS_TDD128_MODE__
typedef struct
{ 
  unsigned short        uarfcn[6];
  unsigned short        cell_parameter[6];
  unsigned char         rscp[6];
}rrm_ir_3g_neighbor_meas_status_ind_param_struct;
#endif

#endif /* ~_EM_PUBLIC_PARAM_STRUCT_H */
