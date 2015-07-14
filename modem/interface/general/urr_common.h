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
 *   urr_common.h
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
 * --------------------------------------------------------
 * $Log$
 *
 * 04 08 2013 jin.liang
 * [MOLY00013638] [Pre-SQC][CMCC Case][RRM][V3.3.3.26.8][7.5.3.1.2][M]Fail
 * .
 *
 * 04 08 2013 jin.liang
 * [MOLY00013638] [Pre-SQC][CMCC Case][RRM][V3.3.3.26.8][7.5.3.1.2][M]Fail
 * .
 *
 * 03 06 2013 blanden.wen
 * [MOLY00011427] modify Wait RLC ACK timer default value from 10 to 3 sec
 * .
 *
 * 02 01 2013 ethan.han
 * [MOLY00009664] [MT6280][check-in request] [Customer Request] To Enable Integrity ON/OFF for 3G AS via NVRAM
 *
 * 11 14 2012 c-hua.yang
 * [MOLY00005845] [ADR] UT environment enhancement - a tst inject is designed to avoid filling exact bit-length of the peer buffer for RRC message decoding
 * Reconciled offline work
 * 
 * 10 08 2012 bao.han
 * [MOLY00003485] [3G TDD][RRCE/SLCE/MEME] Fix VC Build warning
 *  remove NOT_USED_FSM_PARAMETERS.
 * 
 * 09 27 2012 yong.su
 * [MOLY00004236] [interface][service][kal]remove stack_ltlcom.h
 * <saved by Perforce>
 * 
 * 09 13 2012 bao.han
 * [MOLY00003485] [3G TDD][RRCE/SLCE/MEME] Fix VC Build warning
 *  Add MACRO NOT_USED_FSM_PARAMETERS() to urr_common.h  in WR8
 * 
 * 09 02 2012 yunqi.wang
 * [MOLY00002756] [3G TDD][UAS]MT6583 TDD Modem GCC Build Warning Removal
 * Warning removal
 *
 * 06 05 2012 yenchih.yang
 * removed!
 * .
 *
 * 05 31 2012 tereasa.huang
 * removed!
 * .
 *
 * 05 30 2012 yuanchun.wu
 * removed!
 * .
 *
 * 04 24 2012 wcpuser_integrator
 * removed!
 * .
 *
 * 04 12 2012 blanden.wen
 * removed!
 * .
 *
 * 04 11 2012 jingo.yeh
 * removed!
 * Assertion work-around
 *
 * 01 16 2012 c-hua.yang
 * removed!
 * removed!
 * .
 *
 * 01 10 2012 sabrina.hsu
 * removed!
 * merge RRCE R7R8 code
 *
 * 01 06 2012 chi-chung.lin
 * removed!
 * .
 *
 * 11 08 2011 yongtuan.qiao
 * removed!
 * merge MSBB code to MAUI.
 *
 * 10 07 2011 c-hua.yang
 * removed!
 * .
 *
 * 07 07 2011 c-hua.yang
 * removed!
 * RRC FREE PDU
 *
 * 07 05 2011 mw.hsu
 * removed!
 * .
 *
 * 05 31 2011 jingo.yeh
 * removed!
 * <saved by Perforce>
 *
 * 03 18 2011 jd.ni
 * removed!
 * check in Fast Dormancy RRCE part.
 *
 * 01 28 2011 yuanchun.wu
 * removed!
 * .
 *
 * 01 21 2011 sabrina.hsu
 * removed!
 * <saved by Perforce>
 *
 * 01 20 2011 sabrina.hsu
 * removed!
 * change the MSB of the mapping info with highest priority for HSDPA only projects
 *
 * 01 20 2011 sabrina.hsu
 * removed!
 * Refine HSPA code for memory reduction
 *
 * 12 27 2010 jingo.yeh
 * removed!
 * .
 *
 * 12 17 2010 tereasa.huang
 * removed!
 * Memory reduction
 *
 * 12 14 2010 nicky.chou
 * removed!
 * .
 *
 * 09 03 2010 william.chang
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
 * Modify cell name representation for TDD project
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
 * Modified EM Mode to new architecture
 *
 * removed!
 * removed!
 * Use global definition for S criteria initial value
 *
 * removed!
 * removed!
 * Add an interface to query Max tx power
 *
 * removed!
 * removed!
 * Handle CellType by function: CS_getCellType() by CSCE/CSE
 *
 * removed!
 * removed!
 * Modified comment for R5 ASN.1.
 *
 * removed!
 * removed!
 * Added a function to check curAsRat for RRCE in non-production release
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Checkin for w07.44
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
 * Add copyright header.
 *
 * removed!
 * removed!
 * add to source control recursely
 *
 * removed!
 * removed!
 * Added NULL_RRC_PSC
 *
 * removed!
 * removed!
 * Fix the bug of common enum definition for CSCE/MEME/USIME usage
 *
 * removed!
 * removed!
 * modify MAX_NUM_SEC_KEYS from 4 to 6
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 *
 ******************************************************************************/

#ifndef _URR_COMMON_H
#define _URR_COMMON_H

/* Nicky 20101008: include header files for redundant header file removal */
#include "kal_general_types.h"
#include "uas_common_enums.h"
#include "rrc_asn.h"
#include "as_common.h"
#include "kal_public_api.h"
//#include "app_ltlcom.h"
#include "sm_statemachine.h"
#include "sm_type.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "event_info_utility.h"

#define NORMAL_PLMN      0
#define TEMPORARY_PLMN   1

#define NULL_RRC_UARFCN   (0)
#define NULL_RRC_PHYSCELLID      ((RRC_DB_PhysCellId)(-1))
#define RRC_MIN_DL_UARFCN (10562) /* from 25.101 section 5.4.4 */
#define RRC_MAX_DL_UARFCN (10838) /* these definitions should be moved from here */

/* John Tang 2005/10/25: Used in USIME and other modules/utilities */
#define START_LENGTH 20
/*Christine 2007/2/1: change the number of DB_SECURITY_KEY*/

/*Jingo 2010/12/27[MAUI_02854384] change the number of DB_SECURITY_KEY from 6 to 8: 

   In the following tricky scenario, the most keys need to store is 8.
   
   1. If NW doesn't set the DL activation  time to the current RSN +1 as usual, 
       it is possible that SRB0~SRB4 use different integrity key. Thus, we need store 5 keys.
   2. NAS do AKA for CS domain and give a new CS key.
   3. NAS do AKA for PS doamin and give a new PS key.
   4. The keys described in 2 and 3 will be treated as the latest received key, 
       therefore this two keys would not be deleted when another new key is received from NAS.

   So, the maximum keys need to store is 5(SRB0~SRB4) + 1(cs) + 1(ps) +1(new) = 8
   
*/
#define MAX_NUM_SEC_KEYS  8

/*used in RRCE, SLCE and other modules*/
#define RRC_MAX_TGP_SEQUENCE (6)
#define MAC_TCTF_SIZE       2
#ifdef __UMTS_TDD128_MODE__ 
#define MAC_TCTF_SIZE_CCCH_OVER_RACH_TDD       (2)
#define MAC_TCTF_SIZE_DCCH_OVER_RACH_TDD       (4)
#endif
#define DB_SIB5_INDEX       0
#define DB_SIB6_INDEX       1

/* MH: Move from rrc_utils.h*/
#define RRC_MAX_OUTPUT_POWER(uePowerClass) (maxOutputPower[(uePowerClass) - 1])

/*Included the following here so that SLCE, CSCE, SIBE files can access it*/
/* 0xFFFFFFFF is used to indicate an invalid timer handle
 * we're assuming that the number of timers allocated within
 * the stack never reaches this value
 */
#define RRC_InvalidTmrHandle           0xFFFFFFFF

#define INVALID_SIB16_VALUE_TAG 17

/** 
 * Gibran 20080313
 * Given initial value for S criteria parameters for CISE and MEME.
 */
#define URR_MAXALLOWEDUL_TX_POWER   -50
#define URR_MIN_Q_QUALMIN           -24
#define URR_MIN_Q_RXLEVMIN          -119

extern kal_int16                    maxOutputPower[] ;


/* MH: End of movement*/

#ifdef __UMTS_TDD128_MODE__ 
#if defined(__UMTS_R7__) /* Cooper */
#define RRC_RBmapping_Info_rach_fach_valid 0x01
#define RRC_RBmapping_Info_ulDch_dlDch_valid 0x02
#define RRC_RBmapping_Info_Edch_dlDch_valid 0x04
#define RRC_RBmapping_Info_ulDch_dlHsdsch_valid 0x08
#define RRC_RBmapping_Info_Edch_dlHsdsch_valid 0x10
#define RRC_RBmapping_Info_ulDch_dlHsdschDch_valid 0x20
#define RRC_RBmapping_Info_Edch_dlHsdschDch_valid 0x40
#define RRC_RBmapping_Info_rach_dlHsdsch_valid 0x80

#define RRC_MAX_RBmapping_Info 8
#define RRC_MAX_RB_MULTIPLEXING_OPTION_SUPPORTED 5    

#elif defined(__UMTS_R6__)
#define RRC_RBmapping_Info_rach_fach_valid 0x01
#define RRC_RBmapping_Info_ulDch_dlDch_valid 0x02
#define RRC_RBmapping_Info_Edch_dlDch_valid 0x04
#define RRC_RBmapping_Info_ulDch_dlHsdsch_valid 0x08
#define RRC_RBmapping_Info_Edch_dlHsdsch_valid 0x10
#define RRC_RBmapping_Info_ulDch_dlHsdschDch_valid 0x20
#define RRC_RBmapping_Info_Edch_dlHsdschDch_valid 0x40

#define RRC_MAX_RBmapping_Info 7
#define RRC_MAX_RB_MULTIPLEXING_OPTION_SUPPORTED 5    
#elif defined(__UMTS_R5__)
#define RRC_RBmapping_Info_rach_fach_valid 0x01
#define RRC_RBmapping_Info_ulDch_dlDch_valid 0x02
#define RRC_RBmapping_Info_ulDch_dlHsdsch_valid 0x04
#define RRC_RBmapping_Info_ulDch_dlHsdschDch_valid 0x08

#define RRC_MAX_RBmapping_Info 4
#define RRC_MAX_RB_MULTIPLEXING_OPTION_SUPPORTED 4   
#else
#define RRC_RBmapping_Info_rach_fach_valid 0x01
#define RRC_RBmapping_Info_ulDch_dlDch_valid 0x02

#define RRC_MAX_RBmapping_Info 2
#define RRC_MAX_RB_MULTIPLEXING_OPTION_SUPPORTED 2  
#endif
#endif //end of TDD RB-Mapping

#ifdef __UMTS_FDD_MODE__
#ifdef __UMTS_R7__
#define RRC_MAX_NUM_EDCH_RLC_SIZE_LIST  16  // To reduce the used ctrl-buffer size of RRC_DB_UL_LogicalChannel
#endif

#ifdef __ENHANCED_COMMON_STATE_SUPPORT__ 
typedef enum
{
   Not_Support = 0,
   Enhanced_FACH_Support,
	Enhanced_FACH_PCH_Support  // if a cell supports Enhanced PCH, it must also supports Enhanced FACH
#ifdef __COMMON_EDCH_SUPPORT__	
   ,
   Enhanced_EDCH_Support,     // a cell is considered as  Enhanced_EDCH_Support only when it supports both enhanced UL E-DCH/DL HS-DSCH. 
	Enhanced_EDCH_PCH_Support
#endif
} Cell_EnhancedState_Status;

typedef enum
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif   
   CCCH_VALID,   // If Enhanced Cell_FACH recption cannot start successfully , turns to Enhanced CCCH reception over HSDPA.   
   CCCH_INVALID  // If Enhanced Cell_FACH recption cannot start successfully , do the proper error handling and do NOT start CCCH over HSDPA
}RRC_Enhanced_CCCH_Option;

typedef enum
{
   INACTIVE_SCCPCH,                // No HS_DSCH Reception, for traditional Cell_PCH/Idle_PCH like R99/R5/R6
	RACH_SCCPCH,                    // No HS_DSCH Reception, for traditional Cell_FACH like R99/R5/R6
	RACH_HS_DSCH_CCCH_ENABLED,      // RRC spec 8.5.37 HS_DSCH_RECEPTION_OF_CCCH_ENABLED
	RACH_HS_DSCH_FACH_ENABLED,      // RRC spec 8.5.36 HS_DSCH_RECEPTION_CELL_FACH_STATE
	                                // Also used for 8.5.40 Cell_PCH with dedicated H-RNTI
	INACTIVE_HS_DSCH_PCCH_ENABLED,  // 8.5.40 PCCH over HS_DSCH	                         
#ifdef __COMMON_EDCH_SUPPORT__	  
   EDCH_HS_DSCH_CCCH_ENABLED,      
	EDCH_HS_DSCH_FACH_ENABLED,      
	INACTIVE_SCCPCH_with_EDCH_HSDSCH_MAPPING,  // although UL is inactive, but the common E-DCH mapping info is needed for transition to Enhanced Cell_FACH
#endif   
   INVALID  // Invalid configuration to start Enhanced Cell_FACH	
}RRC_Common_State_TxRx;
#endif

 
#if defined (__ENHANCED_COMMON_STATE_SUPPORT__)  //used for R7R8
#define RRC_RBmapping_Info_rach_fach_valid 0x01
#define RRC_RBmapping_Info_ulDch_dlDch_valid 0x02
#define RRC_RBmapping_Info_Edch_dlDch_valid 0x04
#define RRC_RBmapping_Info_ulDch_dlHsdsch_valid 0x08
#define RRC_RBmapping_Info_Edch_dlHsdsch_valid 0x10
#define RRC_RBmapping_Info_ulDch_dlHsdschDch_valid 0x20
#define RRC_RBmapping_Info_Edch_dlHsdschDch_valid 0x40
#define RRC_RBmapping_Info_rach_dlHsdsch_valid 0x80

/* RRC_Highest_Selectable_RBmapping_Info_BitOffset is used in RRC_SelectAndUpdateRbMappingInfo
   to indicate the MSB offset of the mapping info with hgihest prioirty.
 */
#define RRC_Highest_Selectable_RBmapping_Info_BitOffset 8
/*  The RRC_MAX_RBmapping_Info is used to indicate the max number of RB mapping infos defined in 25.331.
    But it is not used in current code.
 */
//#define RRC_MAX_RBmapping_Info 8
#define RRC_MAX_RB_MULTIPLEXING_OPTION_SUPPORTED 6    //To reduce the DB size, we decide that only 6 multiplexing options are stored for each Logical channel/RB.

#elif defined(__HSUPA_SUPPORT__) 
#define RRC_RBmapping_Info_rach_fach_valid 0x01
#define RRC_RBmapping_Info_ulDch_dlDch_valid 0x02
#define RRC_RBmapping_Info_Edch_dlDch_valid 0x04
#define RRC_RBmapping_Info_ulDch_dlHsdsch_valid 0x08
#define RRC_RBmapping_Info_Edch_dlHsdsch_valid 0x10
#define RRC_RBmapping_Info_ulDch_dlHsdschDch_valid 0x20
#define RRC_RBmapping_Info_Edch_dlHsdschDch_valid 0x40

/* RRC_Highest_Selectable_RBmapping_Info_BitOffset is used in RRC_SelectAndUpdateRbMappingInfo
   to indicate the MSB offset of the mapping info with hgihest prioirty.
 */
#define RRC_Highest_Selectable_RBmapping_Info_BitOffset 7
/*  The RRC_MAX_RBmapping_Info is used to indicate the max number of RB mapping infos defined in 25.331.
    But it is not used in current code.
 */
//#define RRC_MAX_RBmapping_Info 7
#define RRC_MAX_RB_MULTIPLEXING_OPTION_SUPPORTED 5    //To reduce the DB size, we decide that only 5 multiplexing options are stored for each Logical channel/RB.

#elif defined(__HSDPA_SUPPORT__)
#define RRC_RBmapping_Info_rach_fach_valid 0x01
#define RRC_RBmapping_Info_ulDch_dlDch_valid 0x02
#define RRC_RBmapping_Info_ulDch_dlHsdsch_valid 0x08    // snyc. with HSUPA for UT maintenance
#define RRC_RBmapping_Info_ulDch_dlHsdschDch_valid 0x20 // snyc. with HSUPA for UT maintenance

/* RRC_Highest_Selectable_RBmapping_Info_BitOffset is used in RRC_SelectAndUpdateRbMappingInfo
   to indicate the MSB offset of the mapping info with hgihest prioirty.
 */
#define RRC_Highest_Selectable_RBmapping_Info_BitOffset 6
/*  The RRC_MAX_RBmapping_Info is used to indicate the max number of RB mapping infos defined in 25.331.
    But it is not used in current code.
 */
//#define RRC_MAX_RBmapping_Info 4
#define RRC_MAX_RB_MULTIPLEXING_OPTION_SUPPORTED 4   //RRC_MAX_RB_MULTIPLEXING_OPTION_SUPPORTED cannot be larger than RRC_MAX_RBmapping_Info

#else
#define RRC_RBmapping_Info_rach_fach_valid 0x01
#define RRC_RBmapping_Info_ulDch_dlDch_valid 0x02

/* RRC_Highest_Selectable_RBmapping_Info_BitOffset is used in RRC_SelectAndUpdateRbMappingInfo
   to indicate the MSB offset of the mapping info with hgihest prioirty.
 */
#define RRC_Highest_Selectable_RBmapping_Info_BitOffset 2
/*  The RRC_MAX_RBmapping_Info is used to indicate the max number of RB mapping infos defined in 25.331.
    But it is not used in current code.
 */
//#define RRC_MAX_RBmapping_Info 2
#define RRC_MAX_RB_MULTIPLEXING_OPTION_SUPPORTED 2  //RRC_MAX_RB_MULTIPLEXING_OPTION_SUPPORTED cannot be larger than RRC_MAX_RBmapping_Info
#endif
#endif //end of FDD RB-Mapping
#define RRC_WAIT_RLC_ACK_TIMER 3 /*MAUI_03136833*/

/* John Tang 2005/10/24. */
extern const DBIdx                 curMemeCellInfoListIdx;

/* Gibran Change 2006/04/28: Used for default Meas Target Group in CSCE/MEME */
extern kal_uint32            handleDefaultMeasTarget;

#ifdef UNIT_TEST
/* Jethro 20060112: Indicates whether ADR is in unit testing mode */
extern kal_bool adr_isUnitTestMode;
extern kal_bool adr_Integrity_isUnitTestMode;
extern kal_bool adr_isPduLengthUsingPeerBufferLength;
#ifdef __UMTS_FDD_MODE__
extern kal_bool adr_isForcedPeerBufFull;
#endif
#endif
#ifdef __MTK_INTERNAL__
/* under construction !*/
/* under construction !*/
#endif


typedef U16 DLScramblingCode;

typedef struct CellInformation
{
   RRC_UARFCN       uarfcn_DL;
   U8               count;
   DLScramblingCode dlScramblingCodeList[MAX_NUM_SCRAMBLING_CODE];
} CellInformation;

#ifdef __UMTS_FDD_MODE__
#if defined(__UMTS_R6__)
typedef enum
{
   FDD_HSUPA_RRC_OFF,
   FDD_HSUPA_RRC_CAT1,
   FDD_HSUPA_RRC_CAT2,
   FDD_HSUPA_RRC_CAT3,
   FDD_HSUPA_RRC_CAT4,
   FDD_HSUPA_RRC_CAT5,
   FDD_HSUPA_RRC_CAT6,
#if defined(__UMTS_R7__)   
   FDD_HSUPA_RRC_CAT7
#endif   
} FDD_RRC_HSUPA_CATEGORY;
#endif
#endif

typedef enum tReconfigResult
{
   HANDLED_SUCCESS = 0,            /* Command completed without errors */
   HANDLED_FAILED,
   IGNORE_MESSAGE
} tReconfigResult;

typedef enum tIntegrityMode
{
    NORMAL_INTEGRITY_MODE=0,
    NOCHECK_INTEGRITY_MODE=1,
    NO_INTEGRITY_MODE=2
} tIntegrityMode;

typedef kal_uint16 tIndicationCount;
typedef kal_uint16 tMemeEventValidation;

typedef enum CandidateCellType 
{ 
    SERVING_CELL_Chosen   = 1,   
    INTRA_FREQUENCY_CELL_Chosen = 2,
    INTER_FREQUENCY_CELL_Chosen   = 3,
    INTER_RAT_CELL_Chosen = 4,
    DETECTED_CELL_Chosen = 5
}   CandidateCellType;
/* Gibran 20060310: Move Here for CSCE/MEME common used 
 * Viola 20081016: Important! the order of cell type shows the priority of cell (re)selection, 
 * especially when cells have the same quality.*/

typedef enum
{
    OPERATION_SINGLE_MODE,
    OPERATION_DUAL_MODE,
    OPERATION_INVALID_MODE
}OperationMode;
/* Gibran 20070410: Move Here for CSCE/MEME/USIME common used */

typedef enum
{
   Suitable,
   Acceptable,
   CampedNotAllowed
} SelectedCellType ;
/* Gibran 20080102: Move from csce_cse_enums.h to here for CSCE/CSE common used */

typedef enum
{
    URR_UMTS_SM   = 0,
    URR_GSM_SM    = 1,
    URR_UMTS_DM   = 2,
    URR_GSM_DM    = 3,
    URR_NULL_MODE = 4
} URR_RAT_MODE_enum;
/* Gibran 20071219: for CSCE/RRCE common used */

typedef enum
{
    RRC_IE_VER_INVALID,
    RRC_IE_VER_99,
    RRC_IE_VER_4,
    RRC_IE_VER_5,
    RRC_IE_VER_6,  
    RRC_IE_VER_7,
    RRC_IE_VER_8
}RrcIeVerType;

#ifdef __UMTS_TDD128_MODE__ 
typedef enum
{
   RRC_UE_CAP_INVALID = 0,
   RRC_UE_CAP_R4,
   RRC_UE_CAP_R5_Only,
   RRC_UE_CAP_R5_HSDPA,
   RRC_UE_CAP_R7_Only,
   RRC_UE_CAP_R7_HSDPA,
   RRC_UE_CAP_R7_HSPA,
   RRC_UE_CAP_R9
}UE_CAP_TYPE;
#endif

/* Measurement Target Cells or Candidate Cells for Reselection*/
#define HANDLE_NONE_CELL 0x0000
#define HANDLE_INTRA_FREQ_CELLS 0x0001
#define HANDLE_INTER_FREQ_CELLS 0x0002
#define HANDLE_INTER_RAT_CELLS 0x0004
#define HANDLE_INTRA_FREQ_LOW_HCS_PRIO_CELLS 0x0008
#define HANDLE_INTER_FREQ_LOW_HCS_PRIO_CELLS 0x0010
#define HANDLE_INTER_RAT_LOW_HCS_PRIO_CELLS 0x0020
#define HANDLE_INTRA_FREQ_HIGH_HCS_PRIO_CELLS 0x0040
#define HANDLE_INTER_FREQ_HIGH_HCS_PRIO_CELLS 0x0080
#define HANDLE_INTER_RAT_HIGH_HCS_PRIO_CELLS 0x0100

#define HANDLE_ALL_UMTS_CELLS (HANDLE_INTRA_FREQ_CELLS | HANDLE_INTER_FREQ_CELLS | \
                             HANDLE_INTRA_FREQ_LOW_HCS_PRIO_CELLS | HANDLE_INTER_FREQ_LOW_HCS_PRIO_CELLS | \
                             HANDLE_INTRA_FREQ_HIGH_HCS_PRIO_CELLS | HANDLE_INTER_FREQ_HIGH_HCS_PRIO_CELLS)

#define HANDLE_ALL_INTER_RAT_CELLS (HANDLE_INTER_RAT_CELLS | HANDLE_INTER_RAT_LOW_HCS_PRIO_CELLS | \
                                  HANDLE_INTER_RAT_HIGH_HCS_PRIO_CELLS)                        
                        
#define HANDLE_ALL_CELLS (HANDLE_INTRA_FREQ_CELLS | HANDLE_INTER_FREQ_CELLS | HANDLE_INTER_RAT_CELLS |\
                        HANDLE_INTRA_FREQ_LOW_HCS_PRIO_CELLS | HANDLE_INTER_FREQ_LOW_HCS_PRIO_CELLS | \
                        HANDLE_INTER_RAT_LOW_HCS_PRIO_CELLS | HANDLE_INTRA_FREQ_HIGH_HCS_PRIO_CELLS | \
                        HANDLE_INTER_FREQ_HIGH_HCS_PRIO_CELLS | HANDLE_INTER_RAT_HIGH_HCS_PRIO_CELLS)

/* APB Measurement Target Cells or Candidate Cells for Reselection*/
#define HANDLE_APB_NONE_CELL 0x0000
#define HANDLE_APB_INTRA_FREQ_CELLS 0x0001 // shal not be used
#define HANDLE_APB_INTER_FREQ_CELLS 0x0002
#define HANDLE_APB_GSM_RAT_CELLS 0x0004
#define HANDLE_APB_LTE_RAT_CELLS 0x0008

/* Gibran 20060310: Move Here for CSCE/MEME/RRCE common used */

/* Definition for Control_UE_Capability_Bitmask BEGIN*/
#define ENABLE_MT_NO_RESTRICT  0x01   /* [ALPS00289798][Softbank IOT][RAN-13-01-04] Allow MT call while all AC blocked. */
/* Definition for Control_UE_Capability_Bitmask END*/


/* Cooper 20090408 */
#define AS_EXT_ASSERT1(expr, p1, p2, p3) { if (!(expr)) EXT_ASSERT(0, (p1), (p2), (p3)); }
#define AS_EXT_ASSERT2_1(expr, p1, p2, p3) { if (!(expr)) EXT_ASSERT(0, (p1), (p2), (p3)); }
#define AS_EXT_ASSERT2_2(expr, p1, p2, p3) { if (!(expr)) EXT_ASSERT(0, (p1), (p2), (p3)); }
#define AS_EXT_ASSERT3(expr, p1, p2, p3) { if (!(expr)) EXT_ASSERT(0, (p1), (p2), (p3)); }
#define AS_EXT_ASSERT4(expr, p1, p2, p3) { if (!(expr)) EXT_ASSERT(0, (p1), (p2), (p3)); }
#ifndef AS_ASSERT
#define AS_ASSERT(expr) { if (!(expr)) ASSERT(0); }
#endif
#define AS_DEBUG_ASSERT(expr) DEBUG_ASSERT(expr)
#define AS_ASSERT_EMPTY(expr)
/* Cooper end */

/*RRC assert work around*/
#ifdef __RRCE_UT__
#define RRCE_DEBUG_ASSERT(expr)do{\
   if(!(expr))\
   {\
      ASSERT(0);\
   }\
}while(0)
#define RRCE_MODEM_WARNING_MESSAGE(expr, ...)do{\
   if(!(expr))\
   {\
      if(rrce_context.bypassUTDebugAssert == KAL_FALSE)\
      {\
         ASSERT(0);\
      }\
      assert_bypass_sys_trace((kal_char *)__FILE__,  __LINE__, ##__VA_ARGS__, NULL);\
   }\
}while(0)

#else
#define RRCE_DEBUG_ASSERT(expr) DEBUG_ASSERT(expr)
#define RRCE_MODEM_WARNING_MESSAGE MODEM_WARNING_MESSAGE
#endif
  
/*RRC assert work around*/

extern RRC_EstablishmentCause RRC_GetConnEstablishmentCause(void);


/* This function is used to populate the DbError info structure, the  2nd Parameter ignored if 1st Parameter is not RRC_DB_FailureCause_protocolError */

extern void fill_DbErrorInfo(RRC_DB_FailureCause    failurecause, 
                             RRC_ProtocolErrorCause protocolErrorCause);


/**************************************************************************** 
* Function:    RRC_GetFailureCause
*
* Parameters:  void
*
* Returns:     RRC_FailureCauseWithProtErr
*
* Description: Gets the failure cause from the Error Info Object.
*****************************************************************************/
extern RRC_FailureCauseWithProtErr  RRC_GetFailureCause(void) ;

/**************************************************************************** 
* Function:    GetDedicatedTrchRlc_SizeInfoList
*
* Parameters:  pDb_TFS - pointer to RRC_TransportFormatSet 
*              pDDInfoList - pointer to the DedicatedDynamicTF_InfoList
*              
* Returns:     kal_bool - Validity result
*
* Description: This function returns the RRC_DedicatedDynamicTF_InfoList
*              
* *****************************************************************************/
extern kal_bool GetDedicatedTrchRlc_SizeInfoList( const RRC_TransportFormatSet* pDb_TFS, RRC_DedicatedDynamicTF_InfoList** pDDInfoList);


extern kal_bool GetCommonTrchRlc_SizeInfoList( const RRC_TransportFormatSet* pDb_TFS, RRC_CommonDynamicTF_InfoList** pCDInfoList);

#ifdef __UMTS_TDD128_MODE__  
extern kal_bool GetCommonTrchRlc_SizeInfoList_LCR( const RRC_TransportFormatSet_LCR* pDb_TFS, RRC_CommonDynamicTF_InfoList** pCDInfoList);
#endif 


/**************************************************************************** 
* Function:    RRC_ConvertTFStoDbTFS
*
* Parameters:  pTFS - pointer to const RRC_TransportFormatSet 
*              pDbTFS - pointer to the RRC_TransportFormatSet object of DB
*              
* Returns:     kal_bool - Validity result
*
* Description: This function copies the TFS from PDU to the DB object
*              
* *****************************************************************************/
extern kal_bool RRC_ConvertTFStoDbTFS ( const RRC_TransportFormatSet* pTFS, RRC_TransportFormatSet*  pDbTFS  );

/**************************************************************************** 
* Function:    RRC_setFailureIndicatorForDBErrorInfo
*
* Parameters: 
*
* Returns:     None
*
* Description: Sets FailureIndicator to KAL_TRUE in DB_ErrorInfo object.
*****************************************************************************/
extern void RRC_setFailureIndicatorForDBErrorInfo(void);

/****************************************************************************
* Function:    RRC_GetCurrDbCellIdx
*
* Parameters:  Pointer to DB Cell Index
*
* Returns:     T/F (indicate if there is a serving cell)
*
* Description: Get DB_Cell_Id from RRC_UTRAN_DB
*****************************************************************************/
extern kal_bool RRC_GetCurrDbCellIdx( RRC_DB_Cell_Idx*  pCurrDbCellIdx );

/****************************************************************************
* Function:    RRC_GetCurrConfigIdx
*
* Parameters:  Nil
*
* Returns:     RRC_DB_CF_Idx
*
* Description: Get current configuration index from RRC_UTRAN_DB
*****************************************************************************/
extern RRC_DB_CF_Idx RRC_GetCurrConfigIdx( void );

/******************************************************************************
 * Function:    RRC_GetTxPowerCapability
 *
 * Parameters:
 *
 * Returns:     kal_int8  UE Power capability (Actual)
 *
 * Description : Returns the actual UE power capability from the database
 *
 *******************************************************************************/
extern kal_int8 RRC_GetTxPowerCapability(void);


/****************************************************************************
* Function:    RRC_getCurrentFreqBand
*
* Parameters:  RRC_UARFCN  currentDLUarfcn
*
* Returns:     RRC_RadioFrequencyBandFDD
*
* Description:  Returns the current frequency Band based on current UARFCN
*
*****************************************************************************/

/*Rebecca 20070911: Removed for multi-band modification, use function Scsi_UarfcnValidateInAllSupportUmtsBand or
   Scsi_UarfcnValidateInAllUmtsBand*/
/*extern  RRC_RadioFrequencyBandFDD RRC_getCurrentFreqBand( RRC_UARFCN  currentDLUarfcn);*/

extern mSM_TRANSITION_FN(RRC_PDU_ignorePdu);

extern kal_int16 urr_get_max_tx_power_from_dl_uarfcn(RRC_UARFCN dl_uarfcn);

#ifdef __MODEM_EM_MODE__
extern kal_bool RRC_HandleEmUpdateReq(ilm_struct*   pIlmMsg,
                                      kal_uint32*   pEvent,
                                      kal_uint32*   pService,
                                      kal_uint32*   pInstance);

extern void RRC_SendEmStatusIndHdlr(local_para_struct* local_ptr, 
                                    peer_buff_struct*  peer_ptr,
                                    module_type        src_mod_id );
#endif


#define uas_allocSendILM(macro_src_mod, macro_dest_mod, macro_sap_id, macro_msg_id, macro_local_para_ptr, peer_buff_ptr) \
        msg_send6((macro_src_mod), (macro_dest_mod), (macro_sap_id), (macro_msg_id), (local_para_struct *)(macro_local_para_ptr), (peer_buff_struct *)(peer_buff_ptr))

extern void rrc_pdu_free_pdu(ilm_struct* ilmRlcDataInd);

extern void rrc_pdu_free_pdu_from_bch(ilm_struct* ilmBchDataInd);

/* Query the status of the capability represented by the capability_bit in Control_UE_Capability_Bitmask */
extern kal_bool RRCE_Is_Capability_Enable(kal_uint8 capability_bit);

#endif /* URR_COMMON_H */

extern mSM_TRANSITION_FN(RRC_Timer_CommonIgnore);

