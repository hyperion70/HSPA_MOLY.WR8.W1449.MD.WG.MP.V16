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
 *   uas_gas_enums.h
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
 * ----------------------------------------------------------------------------
 * $Log:$
 *
 * 11 23 2012 yanjuan.feng
 * [MOLY00003839] [TDD_GAS]fix UT
 * .modify 3G2 redirection related bug
 * 
 * 09 09 2012 yong.su
 * [MOLY00003321] [3G TDD][RRCE][InterRAT]modified code for MAX_TARGET_GSM_CELLS_NUM
 * .
 * 
 * 08 14 2012 peter.chien
 * [MOLY00002118] [PS1][GAS] Internal inject message test for MEAS IT
 * .
 * 
 * 08 14 2012 peter.chien
 * [MOLY00002118] [PS1][GAS] Internal inject message test for MEAS IT
 * .
 *
 * 05 25 2012 haizhou.liu
 * removed!
 * .
 *
 * 05 17 2012 c-hua.yang
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
 * 11 08 2011 junzhen.qin
 * removed!
 * .
 *
 * 10 28 2010 adeline.chang
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
 * Supported 3rd criteria for InterRAT cell reselection to UTRAN.
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Add copyright header.
 ******************************************************************************/

#ifndef _UAS_GAS_ENUMS_H
#define _UAS_GAS_ENUMS_H

/* MACROS ******************************************************************/
/* MAX Values */
#define MAX_LEN_HO_TO_GSM_MSG (251)  /* Octets */
#define MAX_LEN_TLV_CLASSMARK_2 (5)  /* Octets */
#define MAX_LEN_V_CLASSMARK_3  (32)     /* Octets */
#define MAX_LEN_HO_TO_UTRAN_MSG  (251) /* Octets */
#define MAX_LEN_UTRAN_HANDOVER_INFO_MSG (251) /* Octets*/
#define MAX_NR_OF_FDD_CELLS_IN_CELL_LIST 32 
#define MAX_NUM_MEASURED_UMTS_FDD_CELL 64

#ifdef __UMTS_FDD_MODE__
#define MAX_NUM_MEASURED_UMTS_CARRIERS (3)
#endif //__UMTS_FDD_MODE__

#ifdef __UMTS_TDD128_MODE__
#define MAX_NUM_MEASURED_UMTS_CARRIERS (9)
#endif //__UMTS_TDD128_MODE__

#define MAX_NUM_MEASURED_GSM_CELLS 32
#define UAS_GAS_INVALID_UARFCN (0xffff)

#if defined(__UMTS_TDD128_MODE__)
#define MAX_NR_OF_TDD_CELLS_IN_CELL_LIST (32)
#define MAX_NUM_MEASURED_UMTS_TDD_CELL (64)
#endif //defined(__UMTS_TDD128_MODE__)

/*Other constants*/
#define INTER_RRC_GSM_CIPHERING_KEY_LENGTH   8  
#define INTER_RRC_UMTS_CIPHERING_KEY_LENGTH 16
#define INTER_RRC_UMTS_INTEGRITY_KEY_LENGTH 16
#define TEMP_FAILURE_PENALTY_TIME 30 /*Haizhou 20100819 Time penalty for convert temp failure to initial_value after resel to ucell fai*/

#define INTER_RRC_LEN_PLMN_IDENTITY 3

/* MAX/MIN values */
#define MAX_UARFCN_RSSI_VAL 63
#define MIN_UARFCN_RSSI_VAL 0
#define MAX_UCELL_RSCP_VAL 91
#define MIN_UCELL_RSCP_VAL -5
#define MAX_UCELL_EC_NO_VAL 49
#define MIN_UCELL_EC_NO_VAL 0

#define MAX_UMTS_UARFCN 16383
#define MIN_UMTS_UARFCN 0
#if 0
/* under construction !*/
/* under construction !*/
#endif
#define INVALID_NC_MODE (0xFF)

#ifdef __UMTS_FDD_MODE__ 
#ifdef __FDD_REDIRECTION__
#define MAX_TARGET_GSM_CELLS_NUM (32)
#else
#define MAX_TARGET_GSM_CELLS_NUM (1)
#endif
#endif
#ifdef __UMTS_TDD128_MODE__ 
#if defined(__UMTS_R6__) || defined(__GERAN_R6__)
#define MAX_TARGET_GSM_CELLS_NUM (32)
#else
#define MAX_TARGET_GSM_CELLS_NUM (1)
#endif
#endif

#if (defined(__UMTS_R5__) && (defined(__GERAN_R5__)))
#define MAX_GSM_SYS_INFO_BLOCKS_NUM (8)
#endif

#if defined(__PS_HO__) && defined (__UMTS_R6__)    
#define MAX_LEN_V_MS_RADIO_ACCESS_CAPABILITY (64)
#endif

#ifdef __WCDMA_PREFERRED__
#define INTER_DEFAULT_RSCP_THRESHOLD (11) /* -105 dBm */
#define INTER_DEFAULT_EC_N0_THRESHOLD (19) /* -15 dB */
#endif /* __WCDMA_PREFERRED__ */

/* TYPES DEFINITIONS ********************************************************/

typedef enum 
{
   UMTS_SIGNALLING_KEYS_FOR_CS_DOMAIN,
   UMTS_SIGNALLING_KEYS_FOR_PS_DOMAIN
}te_umts_signalling_connection_keys;

/**
 * @brief 
 *     te_ir_handover_status specifies the result of inter-RAT handover 
 *     procedure 
 *     . 
 */

typedef enum
{
             /* Handover message is correct or procedure is success*/
   IR_HANDOVER_STATUS_NORMAL_EVENT,
             /* Applicable during Evaluation only*/
   IR_HANDOVER_STATUS_FREQUENCY_NOT_IMPLEMENTED,
	     /* Applicable only for Activation procedure
    * HO to GSM: Handover procedure failed due to lower layer failure at GSM . 
    * HO to UTRAN: Failure to establish channels on cell(s) required for handover
    *             at any point during handover activation procedure. */
   IR_HANDOVER_STATUS_PHYSICAL_CHANNEL_FAILURE,   
   /* Applicable during Evaluation procedure
    * Handover procedure failed due to inconsitent/missing parameters protocol
    * error. */
  IR_HANDOVER_STATUS_GSM_PROTOCOL_ERROR, 
             /* Applicable only during Evaluation procedure
    * HO to GSM: Handover message has a channel mode configuration which is not
    *           supported
    * HO to UTRAN : Predefined configuration not read or default configuration 
    *              not implemented. */
   IR_HANDOVER_STATUS_UNSUPPORTED_CONFIGURATION,  
   /* Applicable only for activation procedure, e.g. abort CS connection by UAS */
   IR_HANDOVER_STATUS_UNSPICIFIED_ERROR
}te_ir_handover_status;


/**
 * @brief 
 *     te_rrc_frequency_band specifies the frequency band. 
 */

typedef enum {
  GSM_BAND_INDICATOR_DCS1800, /*Default */
  GSM_BAND_INDICATOR_PCS1900
} te_gsm_band_indicator;

typedef enum {
   CIPHER_STATUS_NOT_STARTED,
   CIPHER_STATUS_STARTED
}te_cn_domain_cipher_status;	   
   
typedef enum {
    L1_AVAILIBILITY_STATUS_VACANT, /* During Cell selection*/
    L1_AVAILIBILITY_STATUS_SHARED, /* IDLE camped,URA_PCH,CELL_PCH */
    L1_AVAILIBILITY_STATUS_OCCUPIED /* PTM,DEDICATED,CELL_FACH,CELL_DCH*/
}te_l1_availibility_status;    

typedef enum {
  IR_CELL_RESELECTION_SUCCESS,
  IR_CELL_RESELECTION_FAILURE,
  IR_CELL_RESELECTION_TIMEOUT
}te_ir_cell_reselection_status;

typedef enum {
  IR_CELL_CHANGE_COMPLETE_SUCCESS,
  IR_CELL_CHANGE_COMPLETE_FAIL,
  IR_CELL_CHANGE_COMPLETE_FAIL_BY_NAS_COMMAND
}te_ir_cell_change_complete_status;

/*Byron: 2007/05/08: Add for real CCO fail cause*/
typedef enum {
  IR_FREQUENCY_NOT_IMPLEMENTED,
  IR_NO_RESPONSE_ON_TARGET_CELL,
  IR_REJECT_ON_TARGET_CELL,
  /*3G failed reason*/
  IR_CONFIGURATION_UNACCEPTABLE,
  IR_PHYSICAL_CHANNEL_FAILURE,
  /* for Gemini */
  IR_SUSPENDING_DURING_IR_CELL_RESEL,
  IR_CELL_CHANGE_FAIL_REASON_NONE
}te_ir_cell_change_fail_reason_enum;

typedef enum {
   IR_CELL_RESELECTION_TYPE_NORMAL,
   IR_CELL_RESELECTION_TYPE_LIMITED_SERVICE
}te_ir_cell_reselection_type;

typedef enum {
   IR_CELL_CHANGE_TRIGGER_AUTONOMOUS,
   IR_CELL_CHANGE_TRIGGER_NW_CONTROLLED,
#ifdef __CMCC_STD_FR__
   IR_CELL_CHANGE_TRIGGER_STD_FR,
#endif
   IR_CELL_CHANGE_TRIGGER_NW_CONTROLLED_REDIRECTION
}te_ir_cell_change_trigger;

typedef enum {
   IR_BAR_STATUS_NOT_BARRED,
   IR_BAR_STATUS_BARRED
}te_ir_bar_status;

typedef enum {
   IR_RESEL_CRITERIA3_NOT_SATISFIED,
   IR_RESEL_CRITERIA3_UNKNOWN,
   IR_RESEL_CRITERIA3_SATISFIED
}te_ir_resel_criteria3_status;
/* not use enum
typedef enum {
   IR_ORIGINATING_RAT_TYPE_UMTS_FDD
}te_ir_originating_rat_type;
*/
/* Enum modification:
 * IR_URRC_STATE_MIN and IR_URRC_STATE_MAX are removed */
typedef enum {
#ifdef __UMTS_TDD128_MODE__
        IR_URRC_INVALID = 0,
#endif
        IR_URRC_IDLE            = 1,
	IR_URRC_PCH,
	IR_URRC_FACH,
	IR_URRC_DCH
}te_ir_urrc_state;

/* Define for Evaluation or Activation Failed Type */
typedef enum
{ 
    IR_INITIAL_VALUE = 0,
    NEVER_ALLOWED = 1, //For Frequency Band Not Support Case.
    PLMN_ID_MISMATCHED = 2,   
    LA_NOT_ALLOWED = 3,
    CELL_BARRED = 4,
    TEMP_FAILURE = 5,
    CRITERIA3_NOT_SATISFIED = 6
}te_eval_activate_fail_type;

#if (defined(__UMTS_R5__) && defined(__GERAN_R5__))
typedef enum{
   GERAN_SysInfo_None,
   GERAN_SysInfo_SI,
   GERAN_SysInfo_PSI
} GERAN_SysInfoType;
#endif


typedef enum
{
    UMTS_UNDEFINED_MODE
#if defined(__UMTS_FDD_MODE__)
    ,UMTS_FDD_MODE
#endif
#if defined(__UMTS_TDD128_MODE__)
    ,UMTS_TDD_MODE
#endif
} te_umts_mode;

#endif /* UAS_GAS_ENUMS_H */
