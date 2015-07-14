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
 *   em_struct.h
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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

 
#ifndef _EM_PUBLIC_STRUCT_H
#define _EM_PUBLIC_STRUCT_H

#include "ps_public_struct.h"
#include "kal_general_types.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "ps_em_enum.h"

typedef kal_uint32 request_info_type;

typedef enum
{
   /* RR */ 
    /* Begin of RR EM INFO Request enum */
   RR_EM_CELL_SELECT_PARA_INFO = 0, RR_EM_INFO_BEGIN = RR_EM_CELL_SELECT_PARA_INFO,
   RR_EM_CHANNEL_DESCR_INFO,
   RR_EM_CTRL_CHANNEL_DESCR_INFO,
   RR_EM_RACH_CTRL_PARA_INFO,
   RR_EM_LAI_INFO,
   RR_EM_RADIO_LINK_COUNTER_INFO,
   RR_EM_MEASUREMENT_REPORT_INFO,
   /* ZY : Temp solution : Cell allocation list*/
   RR_EM_CA_LIST_INFO,
   /* RR new structure */
   RR_EM_CONTROL_MSG_INFO,
   RR_EM_SI2Q_INFO_STRUCT_INFO, 
   RR_EM_MI_INFO_STRUCT_INFO,
   RR_EM_BLK_INFO,
   RR_EM_TBF_INFO,
   RR_EM_GPRS_GENERAL_INFO,
//#ifndef __UMTS_RAT__ 
//   RR_EM_INFO_END = RR_EM_GPRS_GENERAL_INFO,
//#else /* defined __UMTS_RAT__ */
   RRM_EM_IR_PROGRESS_STATUS_IND_STRUCT_INFO,
   RRM_EM_IR_PARAMETER_STATUS_IND_STRUCT_INFO,
   RRM_EM_IR_RESELECT_STATUS_IND_STRUCT_INFO,
   RRM_EM_IR_3G_NEIGHBOR_MEAS_STATUS_IND_STRUCT_INFO,
   RR_EM_INFO_END = RRM_EM_IR_3G_NEIGHBOR_MEAS_STATUS_IND_STRUCT_INFO,
//#endif
   /*End of RR EM INFO Request enum*/
   
   /* CC */ 
   CC_EM_CHANNEL_INFO = 50,
   CC_EM_CALL_INFO,
   
   /* SS */
   SS_EM_INFO,
   
   /* MM */
   MM_EM_INFO,
   /*EM ehancement for RR new structure*/
   MMRR_EM_PLMN_INFO_STRUCT_INFO,
                                        
   /* UEM */                            
   UEM_EM_BATTERY_INFO,
   
   /* gprs em begins */
   GMM_EM_INFO,
   TCM_EM_EXT_PDP_INFO,
   TCM_EM_INT_PDP_INFO,
   TCM_EM_CONTEXT_INFO, //new
   SNDCP_EM_INFO,
   LLC_EM_INFO,
   PPP_EM_INFO,
   SM_EM_INFO,

//#ifdef __VIDEO_CALL_SUPPORT__       
    /* VT EM Display, 2007/11/30 */
    /* VT owner comments VT EM enum is not needed in WR8 */
    //VT_EM_CALL_STATE_INFO = 50, VT_EM_BEGIN = VT_EM_CALL_STATE_INFO,/* vt_em_call_state_choice */
    //VT_EM_MASTER_SLAVE_STATUS_INFO,     /* vt_em_master_slave_status_choice */
    //VT_EM_RETRANSMISSION_PROTOCOL_INFO, /* vt_em_retransmission_protocol_choice */
    //VT_EM_INCOMING_AUDIO_CHANNEL_INFO,  /* vt_em_audio_channel_info_struct */
    //VT_EM_OUTGOING_AUDIO_CHANNEL_INFO,  /* vt_em_audio_channel_info_struct */
    //VT_EM_INCOMING_VIDEO_CHANNEL_INFO,  /* vt_em_video_channel_info_struct */
    //VT_EM_OUTGOING_VIDEO_CHANNEL_INFO,  /* vt_em_video_channel_info_struct */
    //VT_EM_ADM_MEM_MAX_USED_INFO,        /* kal_uint32 */
    //VT_EM_STATISTIC_INFO,               /* vt_em_statistic_info_struct */
    //VT_EM_ROUND_TRIP_DELAY_INFO,        /* kal_uint32 */
    //VT_EM_INCOMING_XSRP_INFO,           /* vt_em_incoming_xSRP */
    //VT_EM_OUTGOING_XSRP_INFO,           /* vt_em_outgoing_xSRP */
	//VT_EM_END = VT_EM_OUTGOING_XSRP_INFO,
//#endif

//#ifdef __UMTS_RAT__          //For MAUI, MONZA2G exclude 3G
   /**
    * Gibran 20061228
    * UAS MEME/CSCE measuremnt and cell status structure
    */
   UAS_3G_GENERAL_STATUS_IND_STRUCT_INFO = 70, URR_EM_INFO_BEGIN = UAS_3G_GENERAL_STATUS_IND_STRUCT_INFO,
   /* Put 1st XXX_STATUS_IND_STRUCT_INFO in front of XXX_EM_INFO_BEGIN 
      in order to show enum_name in XXX_STATUS_IND_STRUCT_INFO not in XXX_EM_INFO_BEGIN. */
   SIBE_EM_3G_SIB_IND_STRUCT_INFO,
   CSCE_EM_SERV_CELL_IND_STRUCT_INFO = 75,
   CSCE_EM_NEIGH_CELL_IND_STRUCT_INFO,
   CSCE_EM_R_STATUS_IND_STRUCT_INFO,
   CSCE_EM_H_STATUS_IND_STRUCT_INFO,
//#ifdef __UMTS_R8__
   CSCE_EM_APBCR_STATUS_IND_STRUCT_INFO,
//#endif
   CSCE_EM_MEAS_RULE_STATUS_IND_STRUCT_INFO,
   CSCE_EM_INFO_MULTIPLE_PLMN_STRUCT_INFO,
   MEME_EM_INFO_UMTS_CELL_STATUS_STRUCT_INFO = 90, MEME_EM_INFO_BEGIN = MEME_EM_INFO_UMTS_CELL_STATUS_STRUCT_INFO,
   MEME_EM_INFO_GSM_CELL_STATUS_STRUCT_INFO,
   MEME_EM_INFO_EVENT_TYPE_1_PARAMETER_STRUCT_INFO,
   MEME_EM_INFO_EVENT_TYPE_2_PARAMETER_STRUCT_INFO,
   MEME_EM_INFO_EVENT_TYPE_3_PARAMETER_STRUCT_INFO,
   MEME_EM_INFO_EVENT_TYPE_4_PARAMETER_STRUCT_INFO,
   MEME_EM_INFO_EVENT_TYPE_5_PARAMETER_STRUCT_INFO,
   MEME_EM_INFO_EVENT_TYPE_6_PARAMETER_STRUCT_INFO,
   MEME_EM_INFO_H_SERVING_CELL_INFO,
   MEME_EM_3G_BLER_IND_STRUCT_INFO, MEME_EM_INFO_END = MEME_EM_3G_BLER_IND_STRUCT_INFO,
   URR_EM_TGPS_STATUS_IND_STRUCT_INFO = 110,  
   URR_EM_INFO_UMTS_SRNC_ID_INFO,
//#ifdef __UMTS_TDD128_MODE__
   UAS_3G_TDD128_HANDOVER_SEQUENCE_IND_STRUCT_INFO = 130,
//#endif
   SLCE_EM_PS_DATA_RATE_STATUS_IND_STRUCT_INFO = 140,
   RRCE_EM_INFO_UMTS_DCH_STATE_CONFIGURATION_INFO = 155,   
   RRCE_EM_INFO_UMTS_FACH_STATE_CONFIGURATION_INFO,   
   URR_EM_INFO_END = RRCE_EM_INFO_UMTS_FACH_STATE_CONFIGURATION_INFO,
//#endif /* __UMTS_RAT__ */   
//#ifdef __UMTS_R8__
   UL1_EM_HS_DSCH_CONFIGURATION_INFO = 170,
   UL1_EM_EDCH_CONFIGURATION_INFO,
   UL1_EM_CPC_CONFIGURATION_INFO,
   UL1_EM_SECONDARY_HS_CONFIGURATION_STATUS_INFO,
   UL1_EM_PRIMARY_HS_DSCH_BLER_INFO,
   UL1_EM_SECONDARY_HS_DSCH_BLER_INFO,
   UL1_EM_EDCH_ACK_RATE_INFO,
//#endif
//#if defined(__UMTS_RAT__) && defined(__UMTS_TDD128_MODE__)
   /* __UL2_EM_MODE__ */
   UL2_EM_ADM_POOL_STATUS_IND_STRUCT_INFO = 185, UL2_EM_INFO_BEGIN = UL2_EM_ADM_POOL_STATUS_IND_STRUCT_INFO,
   UL2_EM_PS_DATA_RATE_STATUS_IND_STRUCT_INFO, 
   UL2_EM_HSDSCH_RECONFIG_STATUS_IND_STRUCT_INFO,
   UL2_EM_URLC_EVENT_STATUS_IND_STRUCT_INFO,
   UL2_EM_3G_BLER_IND_STRUCT_INFO,
   UL2_EM_INFO_END = UL2_EM_3G_BLER_IND_STRUCT_INFO,
//#endif
   CUS_EM_INFO_1 = 200,
   CUS_EM_INFO_2,
   CUS_EM_INFO_3,
   NUM_OF_EM_INFO
} em_info_enum;

typedef enum {
    ACCESS_CLASS_NOT_BARRED      = 0,
    ACCESS_CLASS_EMERGENCY_ONLY  = 1,
    ACCESS_CLASS_ALL_BARRED      = 2,
    ACCESS_CLASS_NOT_AVAILABLE   = 3
} access_class_level_enum;

typedef enum {
    PPAC_FOR_NONE_DOMAIN = 0, 
    PPAC_FOR_CS_DOMAIN = 1, 
    PPAC_FOR_PS_DOMAIN = 2, 
    PPAC_FOR_CS_PS_DOMAIN = 3, 
    PPAC_NOT_AVAILABLE = 4
} ppac_domain_enum;

//mtk01616_080622: for L4A code gen (Do NOT remove)
#define EM_INFO_REQ_NUM NUM_OF_EM_INFO

/* local parameter structures */

/* To identify the status of info_request */
typedef enum
{
   EM_ON  = 0,
   EM_OFF = 1,
   EM_NC  = 2 /* No change */
} em_info_status_enum;

/* For TSTL4C_EM_UPDATE_REQ */
typedef struct
{
   LOCAL_PARA_HDR
   em_info_status_enum  info_request[NUM_OF_EM_INFO];
} tstl4c_em_update_req_struct;


/* For TSTL4C_EM_START_REQ, TSTL4C_EM_STOP_REQ */
typedef struct
{
   LOCAL_PARA_HDR
   module_type mod_id;
   request_info_type	info_request;
} tstl4c_em_start_req_struct;

typedef tstl4c_em_start_req_struct tstl4c_em_stop_req_struct;


/* peer buffer structures */
/* RR structure */		
typedef struct
{
	kal_uint8	crh;   //CELL-RESELECT-HYSTERESIS
	kal_uint8	ms_txpwr;   // 	maximum TX power level an MS may use when accessing on a CCH
	kal_uint8	rxlev_access_min;   //	minimum received signal level at the MS for which it is permitted to access the system
} rr_em_cell_select_para_info_struct;
			
typedef struct
{
	kal_uint8	channel_type;   //	channel type
	kal_uint8	tn;   //	timeslot number
	kal_uint8	tsc;   //	training sequence code
	kal_uint8	hopping_flag;   //	hopping or not
	kal_uint8	maio;   //	MAIO value
	kal_uint8	hsn;   //	HSN value
	kal_uint8	num_of_carriers;   //	number of carriers in the BA list(in the non-hopping case, this shall be set to 1)
	kal_uint16	arfcn[64];   //	ARFCN value in the MA
	kal_bool     is_BCCH_arfcn_valid; /*the BCCH_arfcn is only valid 
	                              when receives H.O cmd in DEDI-state*/
	kal_uint16 BCCH_arfcn;   //	Target_BCCH carrier
	
	/*ZY:2006-08-15 add cipher algo for EM */
	kal_uint8	cipher_algo;  // ciphering value, OFF/A51/A52
	kal_uint8 imeisv_digit[16]; /* To show IMEISV if sent in ciphering mode setting procedure */
	
    kal_uint8 channel_mode;

	/* brwang, 051024, [AMR engineering mode info.] */
       #ifdef __AMR_SUPPORT__
//	rr_mpal_amr_req_struct amr_decode_buf;
       kal_bool amr_valid; /* the AMR(TRUE) or not(FALSE) */
//       kal_uint32 frame_number;/* the frame number to get RATSCCH messages */
//       kal_uint8 cmip;  /* CMI phase */
       kal_uint8 mr_ver;   /* MultiRate speech VERsion : 001-amr verion 1*/
       kal_bool nscb;      /* Noise Supression Control Bit : 0-noise supression is used */
       kal_bool icmi;       /* Initial Codec Mode Indicator : 0-is defined bythe implicit rule */
       kal_uint8 start_codec_mode; /* Start Codec Mode */
       kal_uint8 acs;       /* AMR Codec Activate Set */
       kal_uint8 threshold[3]; /* Threshold1/Threshold2/Threshold3 */
       kal_uint8 hysteresis[3]; /* Hysteresis1/Hysteresis2/Hysteresis3 */
       #endif
} rr_em_channel_descr_info_struct;	//This shall be used in IDLE and DEDI state
			
typedef struct
{	
	kal_uint8	mscr;   //	MSC release
	kal_uint8	att;   //	att flag
	kal_uint8	bs_ag_blks_res;   //	BS-AG-BLKS-RES
	kal_uint8	ccch_conf;   //	CCCH-CONF
	kal_uint8	cbq2;   //	Cell Bar Qualify 2
	kal_uint8	bs_pa_mfrms;   //	BS-PA-MFRMS
	kal_uint8	t3212;   //	T3212 timeout value
} rr_em_ctrl_channel_descr_info_struct;
			
typedef struct
{		
	kal_uint8	max_retrans;   //	MAX Retrans value
	kal_uint8	tx_integer;   //	TX integer
	kal_uint8	cba;   //	cell bar for access
	kal_uint8	re;   //	call reestablishment allowed
	kal_uint8	acc_class[2];   //	acces control class
	kal_bool	CB_supported;	// cell broadcast is supported
} rr_em_rach_ctrl_para_info_struct;
			
typedef struct
{			
	kal_uint16	max_value;   //	timeout value for the DSF or RLF
	kal_int16	current_value;   //	current value in the DSF or RLF calculation
	kal_uint8	dtx_ind;	//DTX indicator
	kal_uint8	dtx_used;	//DTX used or not
	kal_bool	is_dsf;		//timeout value for the DSF or RLF	
} rr_em_radio_link_counter_info_struct;  //This shall be used in IDLE and DEDI state
			
typedef struct
{
	
	kal_uint8	rr_state;	//current RR state	3: IDLE, 4: ACCESS, 5: PKT_TRANSFER 6: DEDICATED
	kal_uint16	serving_arfcn;	//serving cell ARFCN
	kal_uint8	serving_bsic;	//serving cell BSIC

	kal_uint8 serving_current_band;

	kal_uint8	serv_gprs_supported;	//serving cell support GPRS or not		
	kal_int16	serv_rla_in_quarter_dbm;	/*rssi level for serving cell (BCCH
                   	                  in IDLE-state) & (TCH in DEDI-state) & (PDTCH in TRANSFER-state) */
    	kal_bool     is_serv_BCCH_rla_valid;  /*To indicate if the serv_BCCH rssi is valid*/                   	                     
	kal_int16	serv_BCCH_rla_in_dedi_state;	/*rssi level for serving cell (BCCH) in DEDI-State*/
	kal_uint8	quality;	//serving cell -TCH measured quality	

   	/* 2003-0919, add new C31/C32 cvalue information for GPRS service */
   	kal_bool     gprs_pbcch_present; // To indicate if the current cell supports GPRS & PBCCH is present

	/* 2003-0919, add new C31/C32 cvalue information for GPRS service */
   	kal_bool     gprs_c31_c32_enable; // To indicate if the current mode is GPRS_PMO_MODE or GPRS_PCCCH_MODE
	kal_int16	c31[32];	//C31 value for the neighbor cell	   

	kal_int16	c1_serv_cell;	//C1 value for the serving cell
	kal_int16	c2_serv_cell;	/* if gprs_c31_c32_enable is false, this field is shown as c2_value for serv_cell
	                              if gprs_c31_c32_enable is true, this field is shown as c32_value for serv_cell */
	kal_int16	c31_serv_cell;	/* if gprs_c31_c32_enable is false, this field is ignore
	                              if gprs_c31_c32_enable is true, this field shall be shown in based on report c31_value*/
	                                 

	kal_uint8	num_of_carriers;	//number of carriers in the BA list
	kal_uint16	nc_arfcn[32];	//ARFCN value in the BA list(The list will be sorted by the RSSI level)
	kal_int16	rla_in_quarter_dbm[32];	//rssi level for each carrier
	kal_uint8	nc_info_status[32];	/*Bit0 = 0: "nc_bsic","frame_offset","ebit_offset" is invalid
									Bit0 = 1: "nc_bsic","frame_offset","ebit_offset" is valid
             									Bit1 = 0: "c1","c2" is invalid
             									Bit1 = 1: "c1","c2" is valid 
             									Bit2 = 0: "gprs_status" is invalid
             									Bit2 = 1: "gprs_status" is valid */
	kal_uint8	nc_bsic[32];	//neighbor cell BSIC
	kal_int32	frame_offset[32];	//frame offset for each carrier
	kal_int32	ebit_offset[32];	//ebit offset for each carrier
	kal_int16	c1[32];	//C1 value for the neighbor cell
	kal_int16	c2[32];	/* if gprs_c31_c32_enable is false, this field is shown as c2_value for nbr_cell
                           if gprs_c31_c32_enable is true, this field is shown as c32_value for nbr_cell */

	
	//kal_uint8	nbr_gprs_supported[32];	//0: not supported, 1: supported
	kal_uint8	multiband_report;	//MULTIBAND_REPORT value
	kal_uint8	timing_advance;		//Timing advance, range is 0 - 63

    kal_int16 tx_power_level; 
    kal_int16 serv_rla_full_value_in_quater_dbm;
    kal_uint8 nco;

	kal_uint8	rxqual_sub;		//rx quality (sub), range is 0 - 7
	kal_uint8	rxqual_full;		//RX quality (full), range is 0 - 7
	kal_int16       using_tx_power_in_dbm; /*DL_DTX_AND_TX_POWER*/
#ifdef __AMR_SUPPORT__
    kal_bool amr_info_valid;
    kal_uint8 cmr_cmc_cmiu_cmid;
    kal_uint8 c_i;
    kal_uint16 icm;
    kal_uint16 acs;
    kal_bool dl_dtx_used; /*DL_DTX_AND_TX_POWER*/ 
#endif /* __AMR_SUPPORT__ */
/* brwang, 05/12/27, cell lock support */    
#ifdef __FWP_NC_LAI_INFO__
	kal_uint8	num_of_nc_lai;			/* how many valid LAI info in nc_lai[] array */
	rr_em_lai_info_struct	nc_lai[6]; 	/* store LAI and CID for at most 6 strongest neighbor cells */
#endif /* __FWP_NC_LAI_INFO__ */
/* brwang, 05/12/27, cell lock support */   
} rr_em_measurement_report_info_struct;	//This shall be used in IDLE and DEDI state;
			

/*ZY : 2007/07/25 : Add for Cell allocation list*/
typedef struct
{
        kal_uint8   valid;
        kal_uint8   number_of_channels;
        kal_uint16 arfcn_list[64];
} rr_em_ca_list_info_struct;  


typedef struct
{	
	kal_uint8	msg_type;	/*receives msg type from network in Dedi-State
	                          0: Assignment Command
	                          1: Channel Release
	                          2: Additional Assignment 
	                          3: Classmark Enquiry
	                          4: Ciphering Mode Command
	                          5: Configure Change Command
	                          6: Handover Command
	                          7: Frequency Redefinition
	                          8: Channel Mode Modify
	                          9: Cell Selection Indicator*/
	                           	                           

   kal_uint8 rr_cause;

} rr_em_control_msg_info_struct;


/*Byron: 2006/08/06: Add for SI2q information*/
typedef struct
{
	kal_bool 	present;	
	kal_uint8 no_of_instance;
	kal_bool 	emr_report;
       kal_bool 	pemr_report;
	kal_bool 	umts_parameter_exist;
} rr_em_si2q_info_struct;


/*Byron: 2006/08/06: Add for measurement information*/
typedef struct
{
	kal_bool 	present;
	kal_uint8 no_of_instance;
	kal_bool 	emr_report;
	kal_bool 	umts_parameter_exist;
} rr_em_mi_info_struct;

/* James 2012/8/15: move up gprs info for EM UT */
#ifdef __PS_SERVICE__
typedef struct 
{
	kal_uint32 t3192;         // in msec
	kal_uint32 t3168;         // in msec
	kal_uint8  rp;            // radio priority
	kal_uint8  gprs_support;  // GPRS channel request support(0 not support, 1 support, 2 support but not decode)
	kal_uint8  egprs_support; // EGPRS channel request support(0 not support, 1 support)
	kal_uint8  sgsn_r;		  // PS domain is R99 or R98(0 R98, 1 R99)
	kal_uint8  pfc_support;   // packet flow context support(0 not support, 1 support)
	kal_uint8  epcr_support;  // EGPRS channel request support(0 not support, 1 support)
	kal_uint8  bep_period;	  // BEP period
}rr_em_gprs_general_info_struct;
#endif /* #ifdef __PS_SERVICE__ */

/**************************************************************************
  * GSM DM - Engineer Mode
  *
  * Notes: Following structures are maintained by RR task                                               
  **************************************************************************/
/***************************** Beging of RR DM EM Config  **************************/

#ifndef _RRM_CONTEXT_H_
    typedef enum 
    {
        RRM_NULL_STATE               = 0,
        RRM_INACTIVE_STATE           = 1,
        RRM_CELL_SEL_STATE           = 2,
        RRM_IDLE_STATE               = 3,
        RRM_ACCESS_STATE             = 4,
        RRM_PKT_TRANSFER_STATE       = 5,
        RRM_DEDICATED_STATE          = 6,
        RRM_CELL_RESEL_STATE         = 7,
        RRM_NUM_STATES               = 8
    } rrm_state_enum;
#endif

#ifndef _ENH_PARAMS_SRC_ENUM
#define _ENH_PARAMS_SRC_ENUM
    typedef enum
    {
        SRC_INVALID,
        SRC_SI,
        SRC_MI,
        SRC_PSI,
        SRC_PMO,
        SRC_DEFAULT
    } enh_params_src_enum;
#endif

#ifdef __UMTS_RAT__

#ifndef _RRM_CONTEXT_H_
typedef enum {
    INTER_RAT_MEAS_NOT_REQUIRED                                      = 000,
    INTER_RAT_MEAS_NOT_MEET_QSEARCH_PARA                             = 001,
#ifdef __UMTS_TDD128_MODE__
    INTER_RAT_MEAS_START                                             = 002,
#endif /*__UMTS_TDD128_MODE__*/
#ifdef __UMTS_FDD_MODE__
    INTER_RAT_FIXED_PERIOD_MEAS_START                                = 002,
    INTER_RAT_FIXED_PERIOD_MEAS_START_FOR_RANKING_RESEL              = 003,
    INTER_RAT_FIXED_PERIOD_MEAS_START_FOR_PRIO_RESEL                 = 004,
    INTER_RAT_VARIOUS_PERIOD_MEAS_START_FOR_PRIO_RESEL               = 005,
    INTER_RAT_FIXED_PERIOD_MEAS_STOP_FOR_PRIO_RESEL                  = 006,
    INTER_RAT_VARIOUS_PERIOD_MEAS_STOP_FOR_PRIO_RESEL                = 007,
#endif /*__UMTS_FDD_MODE__*/

    IRCR_FAILURE_SERVING_RLC_C_NOT_VALID                             = 100,
    IRCR_FAILURE_NO_SUITABLE_UMTS_CELL_FOUND                         = 110,
    IRCR_FAILURE_CRITERIA_1                                          = 120,
    IRCR_FAILURE_CRITERIA_2                                          = 130,
    IRCR_FAILURE_CRITERIA_3                                          = 140,
    IRCR_SUCCESS_TO_UTRAN                                            = 150,

    IRHO_FAILURE_COMMAND_PROCESSING_ERROR                            = 200,
    IRHO_FAILURE_HANDOVER_FAILED_IN_UMTS                             = 210,
    IRHO_SUCCESS_TO_UTRAN                                            = 220
} rrm_ir_progress_enum;
#endif

typedef struct
{
   rrm_ir_progress_enum ir_progress;
   rrm_state_enum       rrm_state; 
} rrm_em_ir_progress_status_ind_struct;
/*QJZH: Add TDD_EM Related Data Struct Items*/
typedef struct
{
  enh_params_src_enum        ir_source;
  kal_uint8         umts_3g_search_priority;
  kal_uint8         qsearch_i;
  kal_uint8         qsearch_c;
  kal_uint8         qsearch_c_initial;
  kal_uint8         qsearch_p;
#ifdef __UMTS_FDD_MODE__
  kal_uint8         fdd_qoffset;
  kal_uint8         fdd_rep_quant;
  kal_uint8         fdd_multirat_reporting;
  kal_uint8         fdd_qmin;  
  kal_uint8         fdd_reporting_offset;
  kal_uint8         fdd_reporting_threshold;  
  kal_uint8         f_qmin_off;
  kal_uint8         f_rep_thr_2;
  kal_int8          gsm_pri;
  kal_uint8         thr_pri_srh;
  kal_uint8         thr_gsm_low;
  kal_uint8         h_pri;
  kal_uint8         t_resel; 
#endif /*__UMTS_FDD_MODE__*/

#ifdef __UMTS_TDD128_MODE__
  kal_uint8         tdd_qoffset;
  kal_uint8         tdd_multirat_reporting;
  kal_uint8         tdd_reporting_offset;
  kal_uint8         tdd_reporting_threshold;
#endif /*__UMTS_TDD128_MODE__*/

}rrm_em_ir_parameter_status_ind_struct;


typedef struct
{
#ifdef __UMTS_FDD_MODE__ 
  kal_bool         is_valid[6];
  kal_uint16       uarfcn[6];
  kal_uint16       scrambling_code[6];
  kal_int16        cpich_rscp[6];
  kal_int16        cpich_ec_n0[6];
  kal_bool         tx_diversity[6];
  kal_uint32       umts_resel_hit_duration[6];
  /* The value of hit_criteria is the combination value.
  IR_RESEL_NO_CRITERIA_HIT = 0x00,
  IR_RESEL_RANKING_CRITERIA_HIT = 0x01,
  IR_RESEL_WCDMA_PREFER_HIT = 0x02,
  IR_RESEL_HIGH_PRIORITY_HIT = 0x10,
  IR_RESEL_LOW_PRIORITY_HIT  = 0x20,
  IR_RESEL_ANY_PRIORITY_HIT  = 0x40 */  
  kal_uint8        hit_critiria[6]; /* Show with binary representation */
#endif /*__UMTS_FDD_MODE__*/
     
#ifdef __UMTS_TDD128_MODE__
  kal_bool         is_valid[2];
  kal_uint16       uarfcn[2];
  kal_uint16       cell_parameter[2];
  kal_uint8        rscp[2];
  kal_uint8        sctd[2];
  kal_bool         tstd[2];
#endif /*__UMTS_TDD128_MODE__*/


}rrm_em_ir_reselect_status_ind_struct;

typedef struct
{
#ifdef __UMTS_FDD_MODE__
  kal_bool          is_valid[18];
  kal_uint16        uarfcn[18];
  kal_uint16        scrambling_code[18];
  kal_int16         cpich_rscp[18];
  kal_int16         cpich_ec_n0[18];
  kal_bool          tx_diversity[18];
  kal_int8          priority [18];
  kal_uint8         thr_high[18]; 
  kal_uint8         thr_low[18];
  kal_uint8         qrx_lev_min[18];
    
  /*  
   * IR_INITIAL_VALUE = 0,
   * NEVER_ALLOWED = 1, 
   * PLMN_ID_MISMATCHED = 2,   
   * LA_NOT_ALLOWED = 3,
   * CELL_BARRED = 4,
   * TEMP_FAILURE = 5,
   * CRITERIA3_NOT_SATISFIED = 6
   */
  kal_uint8         fail_type[18];
#endif /*__UMTS_FDD_MODE__*/
    
#ifdef __UMTS_TDD128_MODE__
  kal_bool          is_valid[6];
  kal_uint16        uarfcn[6];
  kal_uint16        cell_parameter[6];
  kal_uint8         rscp[6];
  kal_uint8         sctd[6];
  kal_bool          tstd[6];
#endif /*__UMTS_TDD128_MODE__*/


}rrm_em_ir_3g_neighbor_meas_status_ind_struct;
#endif
/***************************** End of RR DM EM Config  ****************************/

/*SHUANG_EM_UT*/ 
#ifndef __MTK_TARGET__

typedef union
    {
    rr_em_cell_select_para_info_struct rr_em_cell_select_para_info;
    rr_em_channel_descr_info_struct rr_em_channel_descr_info;
    rr_em_ctrl_channel_descr_info_struct rr_em_ctrl_channel_descr_info;
    rr_em_rach_ctrl_para_info_struct rr_em_rach_ctrl_para_info;
    rr_em_lai_info_struct rr_em_lai_info;
    rr_em_radio_link_counter_info_struct rr_em_radio_link_counter_info;
    rr_em_measurement_report_info_struct rr_em_measurement_report_info;
    rr_em_ca_list_info_struct rr_em_ca_list_info;
    rr_em_control_msg_info_struct rr_em_control_msg_info;
    rr_em_si2q_info_struct rr_em_si2q_info;
    rr_em_mi_info_struct rr_em_mi_info;

    /* James 2012/8/15: add gprs info for EM UT */
#ifdef __PS_SERVICE__
    rr_em_gprs_general_info_struct rr_em_gprs_general_info;
#endif
    
#ifdef __UMTS_RAT__
    rrm_em_ir_progress_status_ind_struct rrm_em_ir_progress_status_ind;
    rrm_em_ir_parameter_status_ind_struct rrm_em_ir_parameter_status_ind;    
    rrm_em_ir_reselect_status_ind_struct rrm_em_ir_reselect_status_ind;
    rrm_em_ir_3g_neighbor_meas_status_ind_struct 
    rrm_em_ir_3g_neighbor_meas_status_ind;
#endif
    }em_rr_structs_union;

#endif


/* CC structure */
typedef struct
{
   kal_uint8   cause;	//channel sync cause
   kal_uint8   channel_type;	//channel type
   kal_uint8   channel_mode;	//channel mode
} cc_em_channel_info_struct;

typedef struct
{
	kal_uint8	call_id;	//call id
	kal_uint8	ti;	//transaction identifier
	kal_uint8	state;	//call state
	kal_uint8	aux_state;	//auxiliary state
   	kal_uint8	pi; //progress indicator
	kal_uint16	cause;	//call disconnect cause
	kal_uint8	cause_location;	//cause originating locatioin   
} cc_em_call_info_struct;

/* CB structure */
typedef struct
{
	kal_uint16	sn;	//serial number
	kal_uint16	mi;	//message identifier
	kal_uint8	dcs;	//data code scheme
	kal_uint8	page;	//current number of this page
	kal_uint8	pages;	//total number of pages
} cb_em_info_struct;
     
/* SS structure */
typedef struct
{			
	kal_uint8	ss_state;	//ciss state
	kal_uint8	ti;	//transaction identifier
	kal_uint8	call_id;	//call id
	kal_uint8	invoke_id;	//invoke id
	kal_uint8	num_invoke;	//number of active invokes
	kal_uint8	op_code;	//operation code
	kal_uint8	ss_code;	//supplementary service code
	kal_uint8	bs_code;	//basic service code
} ss_em_info_struct;

/* MM structure */ 
typedef struct
{
   kal_uint8   t3212_val;	//T3212 timer value
   kal_uint8   att_flag;	//ATT flag
   kal_uint8   mm_cause;	//MM Reject cause, if any
   kal_uint8   mm_state;	//MM State
   kal_uint8   mcc[3];	//MCC
   kal_uint8   mnc[3];	//MNC
   kal_uint8   loc[2];	 //registered LAC
   kal_uint8   rac;     //registered RAC
   kal_uint8   tmsi[4];	//TMSI, if valid
   kal_bool is_t3212_running;
   kal_uint16  t3212_timer_value;
   kal_uint16  t3212_passed_time;
   kal_uint8 common_access_class; //for Access Class ?V Common, value defined in access_class_level_enum
   kal_uint8 cs_access_class; //for Access Class ?V CS Domain, value defined in access_class_level_enum
   kal_uint8 ps_access_class; //for Access Class ?V PS Domain, value defined in access_class_level_enum
   ppac_domain_enum paging_for_ppac; //for PPAC - Paging, value defined in ppac_domain_enum
   ppac_domain_enum lr_for_ppac; //for PPAC - Registration, value defined in ppac_domain_enum
   access_class_level_enum lr_access_class; //for PPAC - Registration access class, value defined in access_class_level_enum
   kal_uint8 lu_req_mobile_identity; //mobile identity used in last location update request
#if defined(__WISDOM_EM__) || defined(__ADVANCED_EM__)
   kal_uint8 imsi[9];
   kal_uint8 gsm_update_status;
   kal_uint8 current_rat;
#endif
} mm_em_info_struct;

/* UEM structure */
typedef struct
{
	kal_int32	adc_value;	//battery ADC value
	kal_uint8	battery_level;	//battery level
	kal_uint8	battery_status;	//battery status: battery_status_enum
} uem_em_battery_info;


/* The rr_em_tbf_status_struct is updated whenever TBF is established/reallocated or released. */
typedef struct
{
	kal_uint8	tbf_mode;                // GPRS or EGPRS TBF mode

	/* UL TBF info */
	kal_uint8	ul_tbf_status;      //	access/active/inactive
	kal_uint8	ul_rel_cause;       //	if applicable
	kal_uint8	ul_ts_allocation;   // timeslot allocation  
	kal_uint8 ul_rlc_mode;            // RLC ACK / UNACK mode
	kal_uint8 ul_mac_mode;         // Dynamic allocation / Extended dynamic allocation / Fixed allocation
       /* new created fields */
       kal_uint16 number_rlc_octect;  // RLC requested octect/byte number
	kal_uint8 ul_tfi;
	kal_uint8 ul_granularity;
	kal_uint8 ul_usf;
       kal_uint8 ul_tai;
       kal_uint16 ul_tqi;       
	kal_uint16  ul_window_size;    // GPRS: 64, EGPRS 64 ~1024   
			
       /* DL TBF info */
	kal_uint8	dl_tbf_status;     //	active/inactive/release pending
	kal_uint8	dl_rel_cause;      //	if applicable
	kal_uint8	dl_ts_allocation;      // Ttimeslot allocation
	kal_uint8 dl_rlc_mode;            // RLC ACK / UNACK mode
	kal_uint8 dl_mac_mode;          // Dynamic allocation / Extended dynamic allocation / Fixed allocation
       /* new created fields */
	kal_uint8 dl_tfi;
       kal_uint8 dl_tai;
	kal_uint16 dl_window_size;	// GPRS: 64, EGPRS 64 ~1024   
#ifdef __EGPRS_MODE__	
	kal_uint8 dl_out_of_memory;   // EGPRS IR out of memory indication
#endif /* __EGPRS_MODE__ */
}rr_em_tbf_status_struct;

/* The new rr_em_blk_info_struct is updated every N (configurable?) block period during TBF. 
    N should be adjusted to suitable/smooth display rate. */
typedef struct
{
	/* UL TBF info */       
	kal_uint8	ul_coding_scheme;   
	kal_uint8 ul_cv;
	kal_uint8 ul_tlli;
	kal_uint16 ul_bsn1;
#ifdef __EGPRS_MODE__	
	kal_uint16 ul_bsn2;
       kal_uint8 ul_cps;
	kal_uint8 ul_rsb;
	kal_uint8 ul_spb;
#endif /* __EGPRS_MODE__ */

	/* DL TBF info */
	kal_uint8 dl_c_value_in_rx_level;  /* for both GPRS/EGPRS C value (channel quality) */
       kal_uint8 dl_rxqual;                         /* for GPRS RX QUAL (channel quality) */
       kal_uint8 dl_sign_var;                     /* for GPRS signal variance (channel quality) */
                     
	kal_uint8 dl_coding_scheme;
	kal_uint8 dl_fbi;
	kal_uint16 dl_bsn1;	
#ifdef __EGPRS_MODE__	
	kal_uint16 dl_bsn2;
	kal_uint8 dl_cps;
	kal_uint8 dl_gmsk_mean_bep_lev;	  /* for EGPRS GMSK mean BEP level (channel quality). valid: 0 ~ 31. invalid: 255 */
	kal_uint8 dl_8psk_mean_bep_lev;	  /* for EGPRS 8PSK mean BEP level (channel quality) . valid: 0 ~ 31. invalid: 255 */
       kal_uint8 dl_tn_mean_bep_lev[8];	  /* for EGPRS Timeslot Number mean BEP level (channel quality). valid: 0 ~ 31. invalid: 255 */		
#endif /* __EGPRS_MODE__ */       
       kal_uint8 dl_tn_interference_lev[8]; /* for GPRS/EGPRS Timeslot Number interference (channel quality). valid: 0 ~ 15. invalid: 255 */		       
}rr_em_blk_info_struct;

/* Poying: 20101210. Remove for EM_MODE. */
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/* Poying: 20101210. Add for EM_MODE */
typedef struct{
    kal_uint8 nsapi;
    kal_uint8 data_speed_value;  // data_speed_activate_enum 
} tcm_mmi_em_data_speed_struct;

/* Poying: 20101210. Add for EM_MODE */
typedef struct{
    kal_uint8 num_of_valid_entries;                                 // indicate how many valid records in data_speed[]
    tcm_mmi_em_data_speed_struct data_speed[GPRS_MAX_PDP_SUPPORT];  // might be 1~7
} tcm_mmi_em_info_struct;

/* Poying: To check TCM EM mode by UT */
typedef struct
{
   LOCAL_PARA_HDR
   tcm_mmi_em_info_struct tcm_em_info ;
} l4cps_check_tcm_mmi_em_info_struct;

typedef enum{ // mtk01936 SM EM mode
     LOG_EM_MODE_PDP_INACTIVE, // PDP-INACTIVE
     LOG_EM_MODE_PDP_ACTIVE_PENDING, // PDP-ACTIVE-PENDING
     LOG_EM_MODE_PDP_INACTIVE_PENDING, // PDP-INACTIVE-PENDING
     LOG_EM_MODE_PDP_ACTIVE, // PDP-ACTIVE
     LOG_EM_MODE_PDP_MODIFY_PENDING, // PDP-MODIFY-PENDING
     LOG_EM_MODE_PDP_CONTEXT_ENUM_TOTAL
} sm_em_mode_pdp_context_enum;

typedef struct
{
   /*
     * MTK Question: what is the index mean? Does it mean the PDP array index?
     * Response: Yes
     */
   kal_uint8   pdp_index;

   kal_uint8   nsapi; // NSAPI 

   /*
     * MTK Question: How many states do you need to show? Just inactive & active?
     * Response:
     * PDP status is like below
     * PDP-INACTIVE
     * PDP-ACTIVE_-PENDING
     * PDP-INACTIVE-PENDING
     * PDP-ACTIVE
     * PDP-MODIFY-PENDING
     */
   sm_em_mode_pdp_context_enum   pdp_context_status; 

   kal_uint8   ip[16]; // IPv4 address or IPv6 address(not ready)

   kal_uint16 sdu_size; // Max SDU size in Bytes

   kal_uint8   apn[100];

   /*
     * MTK Question: In our current design, we clear the cause value after PDP deactivation, do you need to see the previous deactivation cause?
     * Response:
     * If MS work normal, just see the previos deactivaion cause.
     * If MS send PDP act msg to Network, MS recevie PDP reject msg from Network, then we need to see reject casue.
     */
   kal_uint8   sm_cause;          //  if applicable

   /*
     * MTK Question: Is this the neg QoS? According to 24.008 Table 10.5.156?
     * LG Response: Yes
     */
   kal_uint8 neg_delay_class; // possible value are Decimal 1, 2, 3, 4
   kal_uint8 neg_reliability_class; // possible value are Decimal 1, 2, 3, 4, 5
   kal_uint8 neg_peak_throughput; // possible value are Decimal 1~9
   kal_uint8 neg_precedence_class; // possible value are Decimal 1, 2, 3, 4
   kal_uint8 neg_mean_throughput; // possible value are Decimal 1~18
   kal_uint8 neg_traffic_class; // possible value are Decimal 1, 2, 3, 4
   kal_uint8 neg_delivery_order; // possible value are Decimal 1, 2
   kal_uint8 neg_delivery_of_err_sdu; // possible value are Decimal 1, 2, 3
   kal_uint8 neg_max_sdu_size; // max SDU size according to 24.008 Table 10.5.156 encoding
   kal_uint8 neg_max_bitrate_up_lnk; // possible value are Decimal 1~254
   kal_uint8 neg_max_bitrate_down_lnk;  // possible value are Decimal 1~254
   kal_uint8 neg_residual_bit_err_rate; // possible value are Decimal 1~9
   kal_uint8 neg_sdu_err_ratio; // possible value are Decimal 1~7
   kal_uint8 neg_transfer_delay; // possible value are Decimal 1~62
   kal_uint8 neg_traffic_hndl_priority; // possible value are Decimal 1, 2, 3
   kal_uint8 neg_guarntd_bit_rate_up_lnk; // possible value are Decimal 1~254
   kal_uint8 neg_guarntd_bit_rate_down_lnk;  // possible value are Decimal 1~254
   kal_uint8 neg_signalling_indication;
   kal_uint8 neg_source_statistics_descriptor;
   kal_uint8 neg_ext_max_bitrate_down_lnk;
   kal_uint8 neg_ext_guarntd_bit_rate_down_lnk;
   kal_uint8 neg_ext_max_bitrate_up_lnk;
   kal_uint8 neg_ext_guarntd_bit_rate_up_lnk;
   /* Poying: 20101210. Add for EM_MODE. */
   kal_uint8 human_readable_neg_delay_class; // delay_class_enum
   kal_uint8 human_readable_neg_reliability_class; // sm_readable_reliability_class_enum
   kal_uint8 human_readable_neg_peak_throughput; // sm_readable_peak_throughput_class_enum
   kal_uint8 human_readable_neg_precedence_class; // sm_readable_precedence_class_enum
   kal_uint8 human_readable_neg_mean_throughput; // sm_readable_mean_throughput_enum
   kal_uint8 human_readable_neg_traffic_class; // sm_readable_traffic_class_enum
   kal_uint8 human_readable_neg_delivery_order; // sm_readable_delivery_order_enum
   kal_uint8 human_readable_neg_delivery_of_err_sdu; // sm_readable_delivery_of_err_sdu_enum
   kal_uint16 human_readable_neg_max_sdu_size;
   kal_uint32 human_readable_neg_max_bitrate_up_lnk;
   kal_uint32 human_readable_neg_max_bitrate_down_lnk;
   kal_uint8 human_readable_neg_residual_bit_err_rate; // sm_readable_residual_bit_error_rate_enum
   kal_uint8 human_readable_neg_sdu_err_ratio; // sm_readable_sdu_err_ratio_enum
   kal_uint16 human_readable_neg_transfer_delay; 
   kal_uint8 human_readable_neg_traffic_hndl_priority; // sm_readable_traffic_hndl_priority_enum
   kal_uint32 human_readable_neg_guarntd_bit_rate_up_lnk;
   kal_uint32 human_readable_neg_guarntd_bit_rate_down_lnk;
   kal_uint8 human_readable_neg_signalling_indication; // sm_readable_signaling_indication_enum
   kal_uint8 human_readable_neg_source_statistics_descriptor; // sm_readable_source_statistics_descriptor_enum
   kal_uint32 human_readable_neg_ext_max_bitrate_down_lnk;
   kal_uint32 human_readable_neg_ext_guarntd_bit_rate_down_lnk;
   kal_uint32 human_readable_neg_ext_max_bitrate_up_lnk;
   kal_uint32 human_readable_neg_ext_guarntd_bit_rate_up_lnk;
} sm_em_pdp_info_struct;

/* Poying: Need to define enum so Catcher can get from database */
typedef enum{
      SM_EM_MAX_PDP_SUPPORT = 11 // nsapi 5~15
} sm_em_max_pdp_support_enum;

/* Poying: Should display all nsapi no matter they are active or not. */
typedef struct{
   kal_uint8   num_of_active_pdp_context;
   sm_em_pdp_info_struct pdp[11]; // nsapi 5~15
} sm_em_info_struct;


typedef struct
{
   kal_uint16	ready_timer; //Ready timer value in SECONDS.
   kal_uint16	rau_timer;   //Periodical Routing Area Updating timer value in minute
   kal_uint8	ms_state;    //MS_NULL_STATE = 0,
                            //    MS_READY_STATE,
                            //    MS_STANDBY_STATE,
                            //    MS_FORCED_TO_STANDBY_STATE
   kal_bool is_rau_timer_running;
   kal_uint16  rau_timer_passed_time; //in minute   
   kal_uint8 attach_req_mobile_identity; //mobile identity used in last gprs attach request
#if defined(__WISDOM_EM__) || defined(__ADVANCED_EM__)
   kal_uint8 ptmsi[4]; /* P-TMSI */
   kal_uint8 attach_rej_cause; /* Attach Reject Cause, mm_cause_enum */
   kal_uint8 rau_rej_cause; /* RAU Reject Cause, mm_cause_enum */
   kal_uint8 gprs_update_status; /* gprs_update_status_enum */
   kal_uint8 cipher_algo; /* Cipher algorithm */
   kal_uint8 attach_type;/* GPRS Attach Type */
   kal_uint8 gmm_state; /* GMM state, gmm_state_enum */
   kal_uint8 gprs_attach_status; /* GPRS_DETACHED = 0, GPRS_ATTACHED = 1 */
#endif /* defined(__WISDOM_EM__) || defined(__ADVANCED_EM__) */
}gmm_em_info_struct;



typedef struct
{
	kal_uint32	num_checksum_error;
	kal_uint32  requested_ip;
	kal_uint32  negotiated_ip;
	kal_uint32  requested_dns;
	kal_uint32  negotiated_dns;
} ppp_em_info_struct;


typedef struct
{
	kal_uint32	num_reasm_failure;
} sndcp_em_info_struct;

typedef struct
{
    kal_uint8   sapi_id;
    kal_uint16  n201_ui;
    kal_uint16  n201_i;
    kal_uint16  kU;
    kal_uint16  kD;
    kal_uint32	num_fcs_error;
} llc_sapi_info_struct ;

typedef struct
{
    llc_sapi_info_struct  sapi_info[2];
} llc_em_info_struct;

typedef struct
{
    kal_uint8 is_higher_pri_plmn_srch; /* indicate that if the higher priority PLMN search is performing */
    kal_uint8 hp_timeout_timer; /* higher priority PLMN search timer (6 mins per unit) */
    kal_uint8 hp_count_down_timer; /* higher priority PLMN search count down timer (6 mins per unit) */
    kal_uint8 rplmn[6]; /* RPLMN */
    kal_uint8 eq_plmn[5][6]; /* 1~5 equivalent PLMNs (6 digits for each PLMN ID) */
    kal_uint8 forbid_plmn[4][6]; /* 1~4 forbidden PLMNs (6 digits for each PLMN ID) */
#if defined(__WISDOM_EM__) || defined(__ADVANCED_EM__)
    kal_uint8 hplmn[6];
    kal_uint8 previous_rplmn[6];
    kal_uint8 requested_plmn[6];
    kal_uint8 plmn_sel_mode;
#endif
} mmrr_plmn_info_struct;


#ifdef __UMTS_RAT__    //For MAUI, MONZA2G exclude 3G
/**
 * Remus 20080626
 * Added MEME EM info in Catcher 
 */

typedef struct {
    kal_uint8   MeasId;
    kal_uint8   EventType;
    kal_uint8   fc;
    kal_uint8   MeasQuantity; // FDD only
    kal_int16   W;            // FDD only
    kal_int16   R;            // FDD only
#ifdef __UMTS_TDD128_MODE__
    kal_int16   Threshold;    // TDD128 only
#endif
    kal_int16   Hystersis;
    kal_uint16  TimeToTrigger;
} event_1_struct;

typedef struct {
    kal_uint8   MeasId;
    kal_uint8   EventType; // 0: 2A, 1: 2B, 2: 2C, 3: 2D, 4: 2E, 5: 2F
    kal_uint8   fc;
    kal_uint8   MeasQuantity; // FDD only
    kal_int16   UsedW;        // FDD only
    kal_int16   nonUsedW;     // FDD only
#ifdef __UMTS_TDD128_MODE__
    kal_int16   UsedT;        // TDD128 only
#endif
    kal_int16   nonUsedT;
    kal_int16   Hystersis;
    kal_uint16  TimeToTrigger;
} event_2_struct;

typedef struct {
    kal_uint8   MeasId;
    kal_uint8   EventType; // 0: 3A, 1: 3B, 2: 3C, 3: 3D
    kal_uint8   fc;
    kal_int32   ThresholdOwnSystem;
    kal_int32   ThresholdOtherSystem;
    kal_int16   W; // FDD only
    kal_int16   Hystersis;
    kal_uint16  TimeToTrigger;
} event_3_struct;

typedef struct {
    kal_uint8   MeasId;
    kal_uint8   TrCHId;
    kal_uint8   EventType; // 0: 4A, 1: 4B
    kal_uint8   Threshold;
    kal_uint16  TimeToTrigger;
    kal_uint16  PendingTimeAfterTrigger;
    kal_uint16  TxInteruptionAfterTrigger;
} event_4_struct;

typedef struct {
    kal_uint8   MeasId;
    kal_uint8   TrCHId;
    kal_uint16  TotalCRC;
    kal_uint16  BadCRC;
    kal_uint16  PendingTimeAfterTrigger;
} event_5_struct;

typedef struct {
    kal_uint8   MeasId;
    kal_uint8   EventType; // 0: 6A, 1: 6B, 2: 6C, 3: 6D, 4: 6E, 5: 6F
    kal_uint8   fc;
    kal_int16   TxThreshold;
    kal_uint16  TimeToTrigger;
} event_6_struct;

typedef struct {
    kal_uint8 num_event_info;
    event_1_struct em_event_info[6];
} meme_em_info_event_type_1_parameter_struct;

typedef struct {
    kal_uint8 num_event_info;
    event_2_struct em_event_info[6];
} meme_em_info_event_type_2_parameter_struct;

typedef struct {
    kal_uint8 num_event_info;
    event_3_struct em_event_info[4];
} meme_em_info_event_type_3_parameter_struct;

typedef struct {
    kal_uint8 num_event_info;
    event_4_struct em_event_info[4];
} meme_em_info_event_type_4_parameter_struct;

typedef struct {
    kal_uint8 num_event_info;
    event_5_struct em_event_info[2];
} meme_em_info_event_type_5_parameter_struct;

typedef struct {
    kal_uint8 num_event_info;
    event_6_struct em_event_info[4];
} meme_em_info_event_type_6_parameter_struct;


typedef struct {
    kal_uint8 TrCHId;
    kal_uint32 TotalCRC;
    kal_uint32 BadCRC;
} trch_bler_struct;

typedef struct {
    kal_uint8 num_trch;
    trch_bler_struct TrCHBler[8];
} meme_em_periodic_bler_report_ind;


#if defined(__UMTS_TDD128_MODE__)
typedef struct
{    
    kal_uint16 UARFCN;
    kal_uint16 CELLPARAID; 
    kal_int32 RSCP; /* value = RSCP/4096 */
    kal_int32 ISCP[6]; /* value = ISCP/4096, timeslot 1 - 6 */ 
    kal_bool isServingCell;/* if it is KAL_TRUE, MMI or Catcher display the cell in Red*/    
} meme_umts_cell_struct;

typedef struct
{
    kal_uint16 workingFreq; 
    kal_uint8 num_cells;
    meme_umts_cell_struct umts_cell_list[64];
} meme_em_info_umts_cell_status_struct;
#endif

#if defined(__UMTS_FDD_MODE__)
typedef struct uas_cell_plmn_id
{
    kal_uint16              mcc;
    kal_uint16              mnc;
} uas_cell_plmn_id;

/* BIT STRING URA-Identity */
typedef struct meme_umts_ura_identity
{
   kal_uint8                numBits;
   kal_uint8                stringData[2];
}
meme_umts_ura_identity;

typedef struct
{    
    kal_uint16              UARFCN;
    kal_uint16              PSC;        // FDD only
    kal_int32               RSCP;       /* value = RSCP/4096 */
    kal_int32               ECN0;       /* value = ECN0/4096 */ // FDD only
    kal_uint8               cell_type;  /*MONITORED: 0, DETECTED: 2, ACTIVE: 4 */  
    kal_uint8               Band;
    kal_int32               RSSI;
    kal_uint32              Cell_identity;

    kal_uint8               validity;
#define MEME_UMTS_CELL_INFO_LAC_VALID 0x01
#define MEME_UMTS_CELL_INFO_RAC_VALID 0x02
#define MEME_UMTS_CELL_INFO_CID_VALID 0x04

    /* Extended Cell Info */
    kal_uint8               num_plmn_id;
    uas_cell_plmn_id        plmn_id_list[6];
    kal_uint16              lac;
    kal_uint8               rac;
    kal_uint8               num_ura_id;
    meme_umts_ura_identity  uraIdentity[8];
} meme_umts_cell_struct;

typedef struct
{
    kal_int8 tx_power; // FDD only
    kal_uint8 num_cells;
    meme_umts_cell_struct umts_cell_list[32];
} meme_em_info_umts_cell_status_struct;
#endif

typedef struct
{    
    kal_uint8 frequency_band;
    kal_uint16 arfcn;
    kal_uint8 bsic;
    kal_int16 rssi; /* value = rssi /4 */
    kal_bool verified;
} meme_gsm_cell_struct;


typedef struct
{
    kal_uint8 num_cells;
    meme_gsm_cell_struct gsm_cell_list[6];
} meme_em_info_gsm_cell_status_struct;

/* 20101006 
 * H-Serving cell information is added into EM */
typedef struct
{
   kal_uint16 HSDSCH_Serving_UARFCN;     /* uarfcn of HS-DSCH serving cell, 0xFFFF means invalid */
   kal_uint16 HSDSCH_Serving_PSC;        /* psc of HS-DSCH serving cell, 0xFFFF means invalid */
   kal_uint16 EDCH_Serving_UARFCN;       /* uarfcn of E-DCH serving cell, 0xFFFF means invalid */
   kal_uint16 EDCH_Serving_PSC;          /* psc of E-DCH serving cell, 0xFFFF means invalid */
} meme_em_info_h_serving_cell_ind_struct;

/**
 * Gibran 20061228
 * Added Cell Status for EM in Catcher 
 * Gibran 20080627
 * Modified CSCE structure for EM in Catcher/MMI.
 */
typedef enum                     
{
   EM_3G_IN_SERV_ABOVE_S,  /* green button */
   EM_3G_IN_SERV_BELOW_S,  /* yellow button */
   EM_3G_OUT_OF_SERV,      /* orange button */
   EM_3G_NO_SERV,          /* red button */
   EM_3G_NO_CHANGE         /* no change */
} em_3g_service_status_enum;

typedef enum                     
{
   EM_3G_RRC_IDLE,  
   EM_3G_RRC_CELL_FACH,
   EM_3G_RRC_CELL_PCH,
   EM_3G_RRC_URA_PCH,
   EM_3G_RRC_CELL_DCH,
   EM_3G_RRC_INACTIVE,
   EM_3G_RRC_NO_CHANGE,
   // RRCE R7 new states   
   EM_3G_RRC_CELL_FACH_HSDPA,
   EM_3G_RRC_CELL_PCH_HSDPA_DATA,  
   EM_3G_RRC_CELL_PCH_HSDPA_PAGING,  
   EM_3G_RRC_URA_PCH_HSDPA_PAGING,
   // RRCE R8 new states 
   EM_3G_RRC_CELL_FACH_HSUPA,
   EM_3G_RRC_CELL_PCH_HSUPA_DATA,  
   EM_3G_RRC_CELL_PCH_READYtoHSPA
} em_3g_rrc_state_enum;

typedef struct
{
   em_3g_service_status_enum  service_status;               //MMI
   em_3g_rrc_state_enum      umts_rrc_state;                //MMI     
   kal_uint16        uarfcn_DL;                             //MMI
   /* if 0xFFFFFFFF means Invalid, set to empty; 0xFFFFFFFE means No Change. */
   kal_uint16        psc;                                   //MMI
   /* if 0xFFFFFFFF means Invalid, set to empty; 0xFFFFFFFE means No Change.*/
#ifdef __UMTS_TDD128_MODE__
   kal_uint16        workingFreq;                           //MMI
   /* if 0xFFFFFFFF means Invalid, set to empty; 0xFFFFFFFE means No Change. */
   kal_uint16        uppch_Position;                       //MMI
   /* if 0xFFFFFFFF means Invalid, set to empty; 0xFFFFFFFE means No Change.*/
#endif
} uas_em_3g_status;

typedef struct
{
   LOCAL_PARA_HDR
   uas_em_3g_status  uas_3g_general_status;
} csce_em_3g_general_status_ind_struct;
#ifdef __UMTS_TDD128_MODE__
typedef enum
{
   INTRA_TR_HHO, 
   INTRA_TM_HHO,
   INTER_TR_HHO,
   INTER_TM_HHO,
   INTRA_TR_BHO,
   INTRA_TM_BHO,
   INTER_TR_BHO,
   INTER_TM_BHO,
   HHO_REVERT,
   BHO_REVERT
} em_3g_handover_type_enum; /* the enum name should be shown in MMI */

typedef struct
{
   kal_uint16   primary_uarfcn_DL;	              
   kal_uint16   working_uarfcn;	          
   kal_uint16   physicalCellId;                   

}em_3g_cell_info;

typedef struct
{
   em_3g_handover_type_enum  service_status;
   em_3g_cell_info           old_cell_info;
   em_3g_cell_info           target_cell_info;
} uas_em_handover_status;

typedef struct
{
   //LOCAL_PARA_HDR
   uas_em_handover_status  uas_3g_general_status;
} rrce_em_3g_handover_sequence_ind_struct;

#endif /*__UMTS_TDD128_MODE__*/

typedef struct
{
   kal_uint16        uarfcn_DL;     //MMI
   kal_uint16        psc;           //MMI
   kal_uint32        Sib_Scheduled; //MMI
   /* MIB      0x0001
      SB1      0x0002
      SB2      0x0004
      SIB1     0x0008
      SIB2     0x0010
      SIB3     0x0020
      SIB4     0x0040
      SIB5     0x0080
      SIB6     0x0100
      SIB7     0x0200
      SIB11    0x0400
      SIB12    0x0800
      SIB18    0x1000
      SIB16    0x4000 
      SIB5bis      0x8000
      SIB11bis 0x00010000
      SIB19 0x00020000
      SIB20 0x00040000
      */
   kal_uint32        received_Sib_Type;   //MMI
   kal_bool          is_finished;      //MMI
/*    20110524 YenChih
  *    kal_uint8 deferredSIB11 is only used in UMTS_R7 for catcher to display deferred SIB11 related information
  *                 0x00: status not change,  
  *                 0x01: deferred SIB11 is on-going, 
  *                 0x02: deferred SIB11 is finished
  */
   kal_uint8        deferredSIB11_ongoing;   //MMI
} sibe_em_sib_status;

/* Viola 20080627, sibe_em_sib_status as the discussion with Shyla,
Sib_Scheduled brings a bitmask for several SIBs, which indicate the SIBs UE needs to receive. Catcher should gray the other SIBs not contained in the variable. Sib_Scheduled would change 0~2 times during SIB collection, I suggest that Catcher could store the current Sib_Scheduled value and compare it with the latest received one. 
received_Sib_Type: This variable may contain one or several SIBs. Catcher shall mark "v" for the SIB(s) contained in this variable, but shall all keep the v of the other SIBs, which is marked by pervious "sibe_em_sib_status" messages.
is_finished: is_finished sets to True, it means that the current SIB Collection finishes. When a new collection starts, Catcher shall clean the "v" mark of all SIBs.
*/

typedef struct
{
   LOCAL_PARA_HDR
   sibe_em_sib_status      sib_status;
} sibe_em_sib_status_ind_struct;

typedef struct
{
    kal_uint8 mcc1;
    kal_uint8 mcc2;
    kal_uint8 mcc3;
    kal_uint8 mnc1;
    kal_uint8 mnc2;
    kal_uint8 mnc3;
} plmn_struct;

typedef struct
{
   kal_uint8         cellidx;
   kal_uint16        uarfcn_DL;   /* UARFCN */  //MMI
   kal_uint16        psc;                       //MMI
   kal_bool          is_s_criteria_satisfied;   //MMI
   /* is_s_criteria_satisfied, 0: FALSE, 1: TRUE */
   kal_int8          qQualmin;  /* Qualmin */   //MMI
   kal_int8          qRxlevmin; /* Qrxlevmin */ //MMI
   /* the following value should be divided by 4096, the result may be float */
   kal_int32         srxlev;                    //MMI                   
   kal_int32         squal;                     //MMI               
   kal_int32         rscp;                      //MMI
#ifdef __UMTS_FDD_MODE__   
   kal_int32         ec_no;                     //MMI
#endif   
   kal_uint16        cycleLength;               //MMI
#ifdef __UMTS_FDD_MODE__   
/* number as k, value is 2k/100 in sec, float */
   kal_uint8         quality_measure;   /* 0: RSCP, 1: EcN0 */ //MMI
#endif
   /**
    * Dennis Weng 20101015
    * add band, rssi, cell_identity
    */   
   kal_uint8         band;
   kal_int32         rssi;
   kal_uint32        cell_identity;
#ifdef __UMTS_R8__
/* csg_id: 0xFFFFFFFF means not show this csg_id */
   kal_uint32        csg_id;
/* apbcr_priority: -2 means not show apbcr_priority, Sprio_search1, Sprio_search2, and Threshserv_low */
   kal_int8          apbcr_priority;              //MMI
   kal_uint8         sprio_search1;              //MMI
   kal_uint8         sprio_search2;              //MMI
   kal_uint8         threshserv_low;             //MMI
#endif

#if defined(__UMTS_FDD_MODE__)
   /* AT&T EM mode */
   kal_uint8         multi_plmn_count;
   plmn_struct       multi_plmn_id[6];

   kal_bool          lac_valid;
   kal_uint16        lac;

   kal_bool          rac_valid;
   kal_uint8         rac;

   kal_bool          ura_valid;
   kal_uint8         num_ura_id;
   meme_umts_ura_identity uraIdentity[8];
#endif
} csce_em_serv_cell_s_status;

typedef struct
{
    kal_uint8 multi_plmn_count;
    plmn_struct multi_plmn_id[6];
} csce_em_info_multiple_plmn_struct;

typedef struct
{
   kal_uint8         cellidx;
   kal_uint16        uarfcn_DL;                 //MMI
   kal_uint16        psc;                       //MMI
   kal_bool          is_s_criteria_satisfied;   //MMI
/* is_s_criteria_satisfied, 0: FALSE, 1: TRUE */
   kal_int8          qQualmin;  /* Qualmin */   //MMI
   kal_int8          qRxlevmin; /* Qrxlevmin */ //MMI
   /* the following value should be divided by 4096, the result may be float */
   kal_int32         srxlev;                    //MMI     
   kal_int32         squal;                     //MMI     
   kal_int32         rscp;                      //MMI      
   kal_int32         ec_no;                     //MMI        
#ifdef __UMTS_R8__
/* apbcr_priority: -2 means not show apbcr_priority, Threshx_high, and Threshx_low */
   kal_int8          apbcr_priority;              //MMI
   kal_uint8         threshx_high;               //MMI
   kal_uint8         threshx_low;                //MMI
#endif

#if defined(__UMTS_FDD_MODE__)
   /* AT&T EM mode */
   kal_uint32        cell_identity;

   kal_bool          multi_plmn_valid;

   kal_uint8         multi_plmn_count;
   plmn_struct       multi_plmn_id[6];

   kal_bool          lac_valid;
   kal_uint16        lac;

   kal_bool          rac_valid;
   kal_uint8         rac;

   kal_bool          ura_valid;
   kal_uint8         num_ura_id;
   meme_umts_ura_identity uraIdentity[8];
#endif
} csce_em_neigh_cell_s_status;

typedef struct
{
   kal_uint8         cellidx;
   kal_uint16        arfcn;                     //MMI
   kal_uint8         bsic;                      //MMI
   kal_bool          is_bsic_verified;          //MMI
   kal_bool          is_s_criteria_satisfied;   //MMI
/* is_s_criteria_satisfied, 0: FALSE, 1: TRUE */
   kal_uint8         freq_band;                 //MMI
   /* 0: 1800Band, 1: 1900Band */
   kal_int8          qRxlevmin; /* Qrxlevmin */ //MMI
   /* the following value should be divided by 4096, the result may be float */
   kal_int32         srxlev;                    //MMI
   kal_int32         rssi;                      //MMI
#ifdef __UMTS_R8__
/* apbcr_priority: -2 means not show apbcr_priority, Threshx_high, and Threshx_low */
   kal_int8          apbcr_priority;            //MMI
   kal_uint8         threshx_high;              //MMI
   kal_uint8         threshx_low;               //MMI
#endif
} csce_em_2G_neigh_cell_s_status;
 
typedef struct
{
   LOCAL_PARA_HDR
   csce_em_serv_cell_s_status      serv_cell;
} csce_em_serv_cell_s_status_ind_struct;

typedef enum
{
  EM_UMTS_CELL,
  EM_GSM_CELL
} em_RAT_type_enum;

#ifdef __UMTS_R8__
typedef enum
{
  EM_CLEAN_NEIGH_CELL_INFO,
  EM_UPDATE_RH_NEIGH_CELL_INFO,
  EM_UPDATE_APBCR_NEIGH_CELL_INFO
}em_neigh_cell_operation_enum;
#endif

typedef struct
{
   LOCAL_PARA_HDR 
   kal_uint8               neigh_cell_count;
#ifdef __UMTS_R8__
   em_neigh_cell_operation_enum      operation;
#endif
   em_RAT_type_enum        RAT_type;
   union
   {
      csce_em_neigh_cell_s_status      neigh_cells[16];
      csce_em_2G_neigh_cell_s_status   GSM_neigh_cells[16];
   }
   choice;
   /* for the element over neigh_cell_count, left blank */ 
} csce_em_neigh_cell_s_status_ind_struct;

typedef struct
{
   kal_uint8      cellidx;
   kal_uint8      celltype;               //MMI
   /* 1: ServCell, 2: IntraFreq NeighCell, 3: InterFreq NeighCell, 4: InterRAT NeighCell, 5: Detected NieghCell */
   kal_int32      r_value;                //MMI
   /* the value should be divided by 4096, the result may be float */
   kal_int32      Treselection;           //MMI
   /* if ServCell, it's Tresel_s; others, it's Tresel_acc */
   kal_uint8      chan_fail_type;         //MMI
   /* 0: Normal, 1: BCH failure, 2: Attempt failure, 4: MainCH failure */
} csce_em_cell_r_status;

typedef struct
{
   LOCAL_PARA_HDR 
   kal_uint8               cell_count;
   csce_em_cell_r_status   cell_r_status[9];      /* for the element over neigh_cell_count, left blank */ 
} csce_em_cell_r_status_ind_struct;

typedef struct
{
   kal_uint8      cellidx;
   kal_int32      h_value;       //MMI
   /* the value should be divided by 4096, the result may be float */     
   kal_uint8      HCS_PRIO;      //MMI
} csce_em_cell_h_status;

typedef struct
{
   LOCAL_PARA_HDR 
   kal_uint8               cell_count;
   csce_em_cell_h_status   cell_h_status[9];      /* for the element over neigh_cell_count, left blank */ 
} csce_em_cell_h_status_ind_struct;

#ifdef __UMTS_R8__
typedef struct
{
   kal_uint8      cellidx;
   kal_uint8      celltype;               //MMI
   /* 1: ServCell, 2: IntraFreq NeighCell, 3: InterFreq NeighCell, 4: InterRAT NeighCell, 5: Detected NieghCell */
   kal_int32      Treselection;           //MMI
   /* if ServCell, it's Tresel_s; others, it's Tresel_acc */
   kal_uint8      chan_fail_type;         //MMI
   /* 0: Normal, 1: BCH failure, 2: Attempt failure, 4: MainCH failure */
} csce_em_cell_apbcr_status;

typedef struct
{
   LOCAL_PARA_HDR 
   kal_uint8               cell_count;
   csce_em_cell_apbcr_status   cell_apbcr_status[16];      /* for the element over neigh_cell_count, left blank */ 
} csce_em_cell_apbcr_status_ind_struct;
#endif

#ifdef __UMTS_R8__
typedef struct
{
   kal_bool	   dl_64QAM_on;
} ul1_em_hs_dsch_configuration_struct;

typedef struct
{
   kal_bool	   ul_16QAM_on;
} ul1_em_edch_configuration_struct;

typedef struct
{
   kal_bool	   dtx_on;
	kal_bool	   drx_on;
} ul1_em_cpc_configuration_struct;

typedef struct
{
   kal_bool    dc_on;
   kal_uint16  dl_freq;
   kal_uint16  psc;
   kal_bool    dl_64QAM_on;
} ul1_em_secondary_hs_dsch_configuration_status_struct;

typedef struct
{
   kal_uint16  dsch_error_all;
   kal_uint16  dsch_error_new_data;
   kal_uint16  dsch_error_after_retx;
} ul1_em_primary_hs_dsch_bler_struct;

typedef struct
{
   kal_uint16  dsch_error_all;
   kal_uint16  dsch_error_new_data;
   kal_uint16  dsch_error_after_retx;
} ul1_em_secondary_hs_dsch_bler_struct;

typedef struct
{
   kal_uint16  edch_ack_cnt;
} ul1_em_edch_ack_rate_struct;
#endif

typedef struct
{
   LOCAL_PARA_HDR  
   /* the "sx","s_intra_search_value","s_intra_search_value",
   "s_search_hcs_value", "s_search_rat_value", 
   "s_hcs_rat_value", "s_limit_search_rat_value" 
   should be divided by 4096, the result may be float */
   kal_int32        sx;                            //MMI
   kal_bool         is_s_intra_search_valid;
   kal_int32        s_intra_search_value;          //MMI
   kal_bool         is_s_inter_search_valid;
   kal_int32        s_inter_search_value;          //MMI
   kal_bool         is_s_search_hcs_valid;
   kal_int32        s_search_hcs_value;            //MMI
   kal_bool         is_s_search_rat_valid;
   kal_int32        s_search_rat_value;            //MMI
   kal_bool         is_s_hcs_rat_valid;
   kal_int32        s_hcs_rat_value;               //MMI
   kal_bool         is_s_limit_search_rat_valid;
   kal_int32        s_limit_search_rat_value;      //MMI
   /* For meas_tgt_cells: 
      1st LSB: UMTS Intra-Freq Cells, 2nd LSB: UMTS Inter-Freq Cells, 3rd LSB: GSM Inter-RAT Cells 
      "Meas Target Type" in "Measurement Rule Status":
      0: Serv Cell only
      1: Serv with IntraFreq Cell
      2: Serv with InterFreq Cell
      3: Serv with Intra/InterFreq Cell
      4: Serv with InterRAT Cell
      5: Serv with IntraFreq/InterRAT Cell
      6: Serv with InterFreq/InterRAT Cell
      7: Serv with Intra/InterFreq/InterRAT Cell
      If the 1st&2nd LSB are all set to '0', make the "UMTS Satisfied Neighbour Cells Status" be invalid; 
      If the 3rd LSB is set to '0', make the "GSM Satisfied Neighbour Cells Status" be invalid. */
   kal_uint32       meas_tgt_cells;               //MMI

#ifdef __UMTS_R8__
/* For apbcr_enabled_type:
      1: MEAS_RULE
      2: MEAS_RULE_AND_APB_H_PRIO
      3: MEAS_RULE_AND_APB_ALL_PRIO
      If apbcr_enabled_type is 1, please do not show apbMeasTargetCells, is_gsm_apbcr_enabled, apbcr_uarfcn .
   */
   kal_uint8        apbcr_enabled_type;               //MMI
   /* For apbMeasTargetCells:
      0: None cell
      1: intraFreq Cell
      2: interFreq Cell
      3: Intra/InterFreq Cell
      4: GSM Cell
      5: intraFreq/GSM Cell
      6: interFreq/GSM Cell
      7: Intra/InterFreq/GSM Cell
      8: LTE Cell
      9: intraFreq/LTE Cell
     10: interFreq/LTE Cell
     11: intraFreq/interFreq/LTE Cell
     12: GSM/LTE Cell
     13: intraFreq/GSM/LTE Cell
     14: interFreq/GSM/LTE Cell
     15: Intra/InterFreq/GSM/LTE Cell
   */
   kal_uint32       apbMeasTargetCells;                 //MMI
   kal_bool         is_gsm_apbcr_enabled;               //MMI
   kal_uint16       apbcr_uarfcn[2];                    //MMI
#endif

} csce_em_meas_rule_status_ind_struct;

typedef enum                     
{
   EM_TDD_MEASURE,  
   EM_FDD_MEASURE,
   EM_GSM_RSSI,
   EM_GSM_BSIC_INIT,
   EM_GSM_BSIC_CNF,
   EM_MULTI_CARRIER      
} em_tgps_measure_enum;


typedef struct
{
   kal_bool          existed;  
   kal_uint8          tgpsi;  /* 1~6 */
   kal_bool          is_gap_deactive;
   /* is_gap_deactive, 0: gap is ACTIVE, 1: gap is DEACTIVE */
   em_tgps_measure_enum    measure_purpose;  
} urr_em_tgps_status;

typedef struct
{
   urr_em_tgps_status        tgps_status[6]; 						
     
} urr_em_tgps_status_ind_struct;

typedef struct
{
   kal_uint16        srnc;
     
} urr_umts_srnc_id_struct; 

typedef struct
{
   kal_uint8     RAB_ID;
   kal_int8      RB_ID;  
   kal_uint32    DL_rate;   /* the value should be divided by 1000, the result may be float, uint: kbps */
   kal_uint32    UL_rate;   /* the value should be divided by 1000, the result may be float, uint: kbps */

} slce_em_ps_data_status;

typedef struct
{
   kal_uint8         ps_number;								
   slce_em_ps_data_status        ps_data_status[8]; 						
     
} slce_em_ps_data_rate_status_ind_struct;

typedef struct
{
	/* UMAC related */
   kal_uint8	dl_mac_hspa_type;  // dl_mac_type display : 0:NA, 1:MAC-hs, 2:MAC-ehs
	kal_uint8	ul_mac_hspa_type;  // ul_mac_type display : 0:NA, 1:MAC-ees, 2:MAC-iis

	/* UL1 PHY related */
	kal_uint8 fdpch[6];           // fdpch slot format display : 0~9: SlotFormat-0 ~ SlotFormat-9, 10:NA(NotConfigured	)
	
} rrce_em_dch_state_configuration_status_struct ;

typedef struct
{
	/* eDRX related */
   kal_bool	eDRXcfgStatus;  // Note that this is config status from RRC viewpoint, not real operating status from UL1 viewpoint
	
} rrce_em_fach_state_configuration_status_struct ;

#endif /* __UMTS_RAT__ */

/**************************************************************************
  * Video Telephony (3G324M) - Engineer Mode
  *
  * Notes: Following structures are maintained by VT task                                               
  * Meggie: 2007/10/05:  Add VT EM related structures     
  **************************************************************************/
/***************************** VT EM Config  ********************************/
typedef enum{
    VT_EM_DATA_TYPE_INVALID = -1,
    VT_EM_DATA_TYPE_AUDIO = 0,
    VT_EM_DATA_TYPE_VIDEO
}vt_em_channel_data_type;

typedef struct{
    LOCAL_PARA_HDR
    vt_em_config_struct em_config;
}l4c_vt_em_set_config_req_struct;   /* MSG: MSG_ID_L4C_VT_EM_SET_CONFIG_REQ */

typedef struct{
    LOCAL_PARA_HDR
    vt_em_config_struct em_config;
}l4c_vt_em_get_config_cnf_struct;   /* MSG: MSG_ID_L4C_VT_EM_GET_CONFIG_CNF */


/****************************  VT EM Display  ********************************/
/* Radvision strucuture dependent */
typedef enum{
    VT_EM_CALL_STATE_INIT = -1,
    VT_EM_CALL_STATE_SYNCHRONIZED = 0,
    VT_EM_CALL_STATE_CONNECTED,
    VT_EM_CALL_STATE_CONNECTEDCHANNELS,
    VT_EM_CALL_STATE_IDLE,
    VT_EM_CALL_STATE_RESETTING,
    VT_EM_CALL_STATE_LOSTSYNC
}vt_em_call_state_choice; /* Refer to Rv3G324mCallState type */

typedef enum
{
    VT_EM_CODEC_TYPE_Unknown = -1,
    VT_EM_CODEC_TYPE_Amr,
    VT_EM_CODEC_TYPE_Mpeg4,
    VT_EM_CODEC_TYPE_H264,
    VT_EM_CODEC_TYPE_H239Control,
    VT_EM_CODEC_TYPE_H239ExtendedVideo,
    VT_EM_CODEC_TYPE_G7221,
    VT_EM_CODEC_TYPE_G726,
    VT_EM_CODEC_TYPE_H324AnnexI,
    VT_EM_CODEC_TYPE_SessionReset,
    VT_EM_CODEC_TYPE_G7222,
    VT_EM_CODEC_TYPE_G7231,
    VT_EM_CODEC_TYPE_H263,
    VT_EM_CODEC_TYPE_G711,
    VT_EM_CODEC_TYPE_G722,
    VT_EM_CODEC_TYPE_G729,
    VT_EM_CODEC_TYPE_H249NavigationKey,
    VT_EM_CODEC_TYPE_H249SoftKeys,
    VT_EM_CODEC_TYPE_H249PointingDevice,
    VT_EM_CODEC_TYPE_H249ModalInterface,
    VT_EM_CODEC_TYPE_Last
} vt_em_codec_type;

/* Radvision strucuture independent */
typedef enum{
    VT_EM_MASTER_SLAVE_STATUS_INVALID = -1,
    VT_EM_SLAVE = 0,
    VT_EM_MASTER
}vt_em_master_slave_status_choice;

typedef enum{
    VT_EM_RETRANSMISSION_PROTOCOL_INVALID = -1,
    VT_EM_RETRANSMISSION_PROTOCOL_SRP = 0,
    VT_EM_RETRANSMISSION_PROTOCOL_NSRP,
    VT_EM_RETRANSMISSION_PROTOCOL_WNSRP
}vt_em_retransmission_protocol_choice;

typedef enum{
    VT_EM_RESOLUTION_INVALID = -1,
    VT_EM_RESOLUTION_SQCIF = 0,
    VT_EM_RESOLUTION_QCIF,
    VT_EM_RESOLUTION_CIF
}vt_em_video_resolution_choice;

typedef enum{
    VT_EM_H223_AL_TYPE_UNKNOWN = -1,
    VT_EM_H223_AL_TYPE_1 = 0,
    VT_EM_H223_AL_TYPE_2,
    VT_EM_H223_AL_TYPE_3
}vt_em_al_type;

typedef struct{
    kal_uint16 lcn;
    kal_uint8   is_chan_duplex;
    vt_em_codec_type   codec_type;
    vt_em_video_resolution_choice  resolution_choice;
    vt_em_al_type forward_al;
    kal_int32   max_sdu_size;
}vt_em_video_channel_info_struct;

typedef struct{
    kal_uint16 lcn;
    kal_uint8   is_chan_duplex;
    vt_em_codec_type   codec_type;
    vt_em_al_type forward_al;
    kal_int32   max_sdu_size;
}vt_em_audio_channel_info_struct;

typedef enum{
    VT_EM_RP_UNKNOWN = -1,
    VT_EM_RP_COMMAND = 0,
    VT_EM_RP_RESPONSE
}vt_em_xSRP_data_type;

typedef struct{
    kal_uint8 sq;
    vt_em_xSRP_data_type type;
}vt_em_outgoing_xSRP;

typedef struct{
    kal_uint8 sq;
    vt_em_xSRP_data_type type;
}vt_em_incoming_xSRP;

typedef struct{        
        kal_uint32 vt_csr_DL_Q_frame_num;
        kal_uint32 vt_csr_UL_Q_frame_num;
        kal_uint32 vt_MED_DL_Q_frame_num;
        kal_uint32 vt_MED_DL_Q_state;

        kal_uint32 vt_DL_video_frame_num;
        kal_uint32 vt_DL_video_frame_size;
        kal_uint32 vt_DL_video_I_frame_num;
        kal_uint32 vt_DL_video_P_frame_num;

        kal_uint32 vt_DL_audio_frame_num;
        kal_uint32 vt_DL_audio_frame_size;
        
        kal_uint32 vt_UL_video_frame_num;
        kal_uint32 vt_UL_video_frame_size;
        kal_uint32 vt_UL_video_drop_frame_num;
        kal_uint32 vt_UL_video_drop_frame_size;

        kal_uint32 vt_UL_audio_frame_num;
        kal_uint32 vt_UL_audio_frame_size;
        kal_uint32 vt_UL_audio_drop_frame_num;
        kal_uint32 vt_UL_audio_drop_frame_size;

        kal_uint32 vt_UL_csr_size;
        kal_uint32 vt_UL_csr_num;
        kal_uint32 vt_DL_csr_size;
        kal_uint32 vt_DL_csr_num;

        kal_uint32 vt_downlink_mc_tbl[16];  /* # pkts using this mc entry */
        kal_uint32 vt_uplink_mc_tbl[16];

        kal_uint32 vt_ra_add_failures;
        kal_uint32 vt_incoming_audio_crc_errors;
        kal_uint32 vt_incoming_video_crc_errors;
        kal_uint32 vt_incoming_control_crc_errors;
        kal_uint32 vt_incoming_control_total_packets;
}vt_em_statistic_info_struct;

typedef struct{
    LOCAL_PARA_HDR
    em_info_enum em_info;
}l4cvt_em_display_ind_struct;   /* MSG: VT to L4C */
/************************** VT EM Definition End  *****************************/

/* __UL2_EM_MODE__ */
#if defined(__UMTS_RAT__) && defined(__UMTS_TDD128_MODE__)
typedef struct							
{								
    kal_uint16                      max_usage_kbytes;          /*Maximum used size of the pool, <= 999*/
    kal_uint16                      avg_usage_kbytes;           /*Average used size of the pool, <= 999*/
} adm_pool_info_struct;

typedef struct							
{		
    adm_pool_info_struct      dl_adm_pool_info[4]; /*dl_adm_pool_info[0] ~ dl_adm_pool_info[2] 
                                              represent the info of  DL ADM POOl 1 ~ 3 and 
                                              dl_adm_pool_info[3] represent the info TOTAL DL ADM POOL*/
    adm_pool_info_struct      ul_adm_pool_info[4];/* ul_adm_pool_info[0] ~ ul_adm_pool_info[2] 
                                              represent the info of  UL ADM POOl 1 ~ 3 and 
                                              ul_adm_pool_info[3] represent the info TOTAL UL ADM POOL*/
} ul2_em_adm_pool_status_ind_struct;					
 							
typedef enum 							
{								
    Invalid,                                        /*show blank */				
    No_Modify,                                   /*show "=" */				
    Add_Queue,                                  /*show "V" */				
    Delete_Queue,                                /*show "X" */				
    Reconfigure_T1,                              /*show "T1" */				
    Reconfigure_WindowSize,                   /*show "WS" */				
    Reconfigure_T1_WindowSize,               /*show "T1_WS" */			
    Reconfigure_C_T,                          /*show "C_T"*/				
} reconfigure_operation_E;						
	
typedef struct							
{				
    reconfigure_operation_E               reconfig_info[8];         /* reconfiguration operation of the Queue 0 ~ 7 */
} ul2_em_hsdsch_reconfig_status_ind_struct;					
typedef struct
{
    kal_uint16           rx_mac_data_rate; 		/* kbps, <=2800*/
   	kal_uint16           rx_pdcp_data_rate;  	/* kbps, <= 2800*/
    kal_uint16           tx_mac_data_rate;  	/*kbps, <=400*/
    kal_uint16       	 tx_pdcp_data_rate;      /*kbps, <=400*/
} ul2_em_ps_data_rate_status_ind_struct;

typedef enum
{	
    URLC_ESTABLISH,               //display "EST"
    URLC_REESTABLISH,           //display "REEST"
    URLC_RECONFIG,                //display "RECFG"
    URLC_RELEASE,                   //display "REL"
    URLC_SUSPEND,                  //display "SUSPD"
    URLC_RESUME,                    //display "RES"
    URLC_RESET,                        //display "RST"
    URLC_DISCARD                   //display "DISCD"
} RLC_ACTION_INFO; 

typedef struct			
{				
    kal_bool                  is_srb;         // if TRUE, display "S", else display "U"
    kal_uint8                 cn_domain;  // for 0, display "CS"; for 1, display "PS"; for 2, display "ALL" 
} ul2_em_rb_info_struct; 		
				
typedef struct			
{				
    kal_uint8                  rlc_mode;   //for 1, display "TM"; for 2, display "UM"; for 3, display "AM", other "Error"
    kal_uint8                  direction;    //for 1, display "UL"; for 2, display "DL"; for 3, display "Both", other "Error"
} ul2_em_rlc_info_struct; 		

typedef struct			
{				
    kal_uint16              pdu_Size;    //display the value   
    kal_uint16              tx_window_size;  //display the value, range [1, 2048] 
    kal_uint16              rx_window_size;   //display the value, range[1, 2048] 
    kal_uint8               discard_mode;    //value is 0/1/2/3, display the value 
    kal_uint16              discard_value;    //display the value, range [0, 9999]
} ul2_em_rlc_parameter_struct; 		
				
typedef struct			
{	
    kal_int8                        rb_id;        // display the value, range [-5, 32]
    RLC_ACTION_INFO                 rlc_action; 	
    ul2_em_rb_info_struct           rb_info; 	
    ul2_em_rlc_info_struct          rlc_info; 	
    ul2_em_rlc_parameter_struct     rlc_parameter;
    kal_bool                        flush_data_indicator;    //if TRUE, display "Flush", else show blank
    kal_uint8                       reset_cause;                //value is 0/1/2, display the value
} ul2_em_urlc_event_status_ind_struct;	

typedef struct
{
	kal_uint8				num_trch;
	trch_bler_struct  		TrCHBler[8];
} ul2_em_periodic_bler_report_ind;
#endif

typedef struct
{
    kal_uint8 group_id;                  /* Group ID */
    unsigned char group_name[MAX_LEN_OF_NW_GROUP_NAME];
    
    module_type  mod_id;                 /* Mod ID */

    kal_uint32 event_id;                 /* Evnet ID */
    unsigned char event_name[MAX_LEN_OF_NW_EVENT_NAME];
    
    kal_uint16 ring_tone_id;             /* Ring Tone ID */        
} em_network_event_struct;

extern em_network_event_struct em_network_event_tbl[];

extern kal_uint32 em_get_total_mod(void);

extern kal_uint32 em_get_total_info_req(void);

extern kal_uint32 em_nw_get_total_event(void);

#endif /* ~_EM_STRUCT_H */

