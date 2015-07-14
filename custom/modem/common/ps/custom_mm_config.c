/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
 *
 * Filename:
 * ---------
 * custom_mm_config.c
 *
 * Project:
 * --------
 *   MONZA
 *
 * Description:
 * ------------
 *   This file is used to define the MM configuration.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 *
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
 *
 * removed!
 * removed!
 *
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "custom_mm_config.h"
#include "ps_public_enum.h"
#include "ps_public_utility.h"

/*****************************************************************************
* FUNCTION
*  mm_custom_stay_on_la_of_regional_provisional_service
* DESCRIPTION
*  This function is for customize MM behavior when entering forbidden LA of #12
*
* PARAMETERS
*
* RETURNS
*  MM_STAY_ON_LA_OF_REGIONAL_PROVISIONAL_SERVICE
*      follow spec (enter limited service and stay on forbidden LA of #12)
*  MM_STAY_ON_LA_OF_REGIONAL_PROVISIONAL_ONLY_IF_TEST_SIM_TEST_MODE
*      follow spec (enter limited service and stay on forbidden LA of #12) 
*      only when test sim is inserted or test mode(CTA/FTA/Operator) is enabled
*  MM_NOT_STAY_ON_LA_OF_REGINOAL_PROVISIONAL_SERVICE
*      allow MS directly retry other PLMN/RAT for normal service
* GLOBALS AFFECTED
*   None
*****************************************************************************/
mm_rej_12_handle_enum mm_custom_stay_on_la_of_regional_provisional_service(void)
{
   //suggest to use default setting [MM_STAY_ON_LA_OF_REGIONAL_PROVISIONAL_SERVICE]
   //change this setting might affect the result of FTA or IOT.
   //may only be changed on production version of software after pass all lab test
#ifdef __MM_NOT_STAY_ON_FBLA_FOR_REG_PROV__
   return MM_NOT_STAY_ON_LA_OF_REGINOAL_PROVISIONAL_SERVICE;
#else
   return MM_STAY_ON_LA_OF_REGIONAL_PROVISIONAL_SERVICE;
#endif
}  

/*****************************************************************************
* FUNCTION
*   mm_custom_is_search_hplmn_before_rplmn
*
* DESCRIPTION
*   This function is used to configure whether search HPLMN before RPLMN
*   when power on or recovery search in automatic mode.
*
*   This configuration will not take effect while verifying FTA cases.
*
* PARAMETERS
*   none
*
* RETURNS
*   KAL_TRUE:
*    - The UE will always search HPLMN before RPLMN when power on or recovery search in automatic mode
*      - The UE will take more time to get normal service if HPLMN does not exist
*      - The UE can camp on HPLMN quicker if both RPLMN and HPLMN exist
*
*   KAL_FALSE:
*   - The UE will follow the requirement of PLMN search procedure defined in 3GPP TS23.122 
*
* GLOBALS AFFECTED
*   none
*****************************************************************************/
kal_bool mm_custom_is_search_hplmn_before_rplmn(void)
{
    return sbp_query_md_feature(SBP_MM_SEARCH_HPLMN_BEFORE_RPLMN);
}


/*****************************************************************************
* FUNCTION
*  mm_custom_allow_rplmn_hplmn_combined_search
*
* DESCRIPTION
*  This function is used to configure whether search RPLMN and HPLMN together.
*
*  [Important!]
*  If return value of mm_custom_is_search_hplmn_before_rplmn is set to KAL_TRUE, 
*  configuration of mm_custom_allow_rplmn_hplmn_combined_search will not take effect.
*
* PARAMETERS
*
* RETURNS
*  kal_bool
* GLOBALS AFFECTED
*  None
*****************************************************************************/
kal_bool mm_custom_allow_rplmn_hplmn_combined_search(void)
{
    /* If search RPLMN and HPLMN together, it is more quickly to camp on HPLMN,
     * and no need to do high priority plmn search later.
     * But it may disobey test case 6.2.1.1 in spec 34.123. 
     */
   return sbp_query_md_feature(SBP_RPLMN_HPLMN_COMBINED_SEARCH);
} 


/*****************************************************************************
* FUNCTION
*  mm_custom_registration_related_setting
* DESCRIPTION
*  This function is used to query registration related setting.
*
* PARAMETERS
*  Which setting
* RETURNS
*  kal_bool
* GLOBALS AFFECTED
*  None
*****************************************************************************/
kal_bool mm_custom_registration_related_setting(mm_setting_enum setting)
{

  switch(setting)
  { 
   
   case MM_ENABLE_LR_REJ111_RETRY:
   {
#ifndef __DISABLE_LR_REJ111_RETRY__   
              return KAL_TRUE;
#else
              return KAL_FALSE;
#endif
        break;
   } 
   case MM_ENABLE_HPPLMN_SEARCH_FORCE_RELEASE_PCH_CONNECTION:
   {
#ifndef __DISABLE_HPPLMN_SEARCH_FORCE_RELEASE_PCH_CONNECTION__
          return KAL_TRUE;
#else
          return KAL_FALSE;
#endif  
        break;
    } 
/* default apply on auto/manual mode, if define this option cannot apply on auto mode */
    case MM_ENABLE_DELETE_OPERATOR_EQPLMN_IN_MANUAL_MODE:
    {
        return sbp_query_md_feature(SBP_MM_IGNORE_EQPLMN_IN_MANUAL_MODE);
        break;
    }    
    case MM_DISPLAY_ROAMING_HPLMN_IN_EPLMN:
    {
        return (sbp_query_md_feature(SBP_DISABLE_DISPLAY_ROAMING_HPLMN_IN_EPLMN)==KAL_FALSE);
        break;
    }      
    case MM_ILL_MS_ME_CAUSE_PS_INVALID_SIM:
    {
        return sbp_query_md_feature(SBP_MM_ILL_MS_ME_CAUSE_PS_INVALID_SIM);
        break;
    }      
    case MM_ENABLE_PLMNSEL_OPLMN_COEXIST:
    {
        return (sbp_query_md_feature(SBP_DISABLE_PLMNSEL_OPLMN_COEXIST)==KAL_FALSE);
        break;
    }      
/* default apply on auto/manual mode, if define this option cannot apply on manual mode */    
    case MM_ENABLE_DELETE_OPERATOR_EQPLMN_IN_AUTO_MODE:
        {
        return sbp_query_md_feature(SBP_MM_IGNORE_EQPLMN_IN_AUTO_MODE);
        break;
        }   

    
   default:
        break;
  }
  
  return KAL_FALSE;
} 

/* MAUI_03014009 Russia Operator BeeLine request to use ECC with IMEI */
/*****************************************************************************
* FUNCTION
*  mm_custom_force_ecc_with_imei
* DESCRIPTION
*  This function configures emergency call force to use IMEI during phone lock period.
*  default: KAL_FALSE (using TMSI->IMSI->IMEI)
*
* PARAMETERS
*
* RETURNS
*  kal_bool
* GLOBALS AFFECTED
*  None
*****************************************************************************/
kal_bool mm_custom_force_ecc_with_imei(void)
{
    return KAL_FALSE;
}

/* ALPS01451877 UK should be allowed to make emergency calls with expired SIM cards */
const kal_uint32 ECC_IMSI_MCC_LIST[] = {234, 235};
const kal_uint32 ECC_IMSI_MCC_NUM = sizeof(ECC_IMSI_MCC_LIST)/sizeof(kal_uint32);


/*************************************************************************
 * International Higher Priorirty PLMN Search
 * 
 * [Important!] Enable this option will violate TS23.122 and thus fail FTA cases
 *
 * - RPLMN_MCC_LIST / HPPLMN_MCC_LIST:
 *   - The UE is allowed to perform international HPPLMN search when the UE
 *     1. registers on a PLMN belonging to one of the MCCs defined in RPLMN_MCC_LIST, and
 *     2. the HPPLMN belongs to one of the MCCs defined in HPPLMN_MCC_LIST
 *
 * - If the MCC of RPLMN or HPPLMN is not restricted
 *   - RPLMN_MCC_LIST or HPPLMN_MCC_LIST shall contain only one entry {ALL_MCC_ALLOWED}
 *
 * - If the UE is not allowed to perform international HPPLMN search
 *   - RPLMN_MCC_LIST and HPPLMN_MCC_LIST shall contain only one entry {NO_MCC_ALLOWED}
 *************************************************************************/

/*  The UE is allowed to perform international HPPLMN search when the UE
 *  1. registers on a PLMN belonging to any MCC, and 
 *  2. the HPPLMN belongs to any MCC
 */
kal_uint32 RPLMN_MCC_LIST_ANY[] = {ALL_MCC_ALLOWED};
kal_uint32 HPPLMN_MCC_LIST_ANY[] = {ALL_MCC_ALLOWED};

/*  The UE is allowed to perform international HPPLMN search when the UE
 *  1. registers on a PLMN belonging to US/Canada/Mexico/British Virgin Islands, and 
 *  2. the HPPLMN belongs to any MCC
 */
kal_uint32 RPLMN_MCC_LIST_ATNT[] = {310, 311, 312, 313, 314, 315, 316, 302, 334, 348};
kal_uint32 HPPLMN_MCC_LIST_ATNT[] = {ALL_MCC_ALLOWED};

/*  The UE is allowed to perform international HPPLMN search when the UE
 *  1. registers on a PLMN belonging to US, and 
 *  2. the HPPLMN belongs to Canada
 */
kal_uint32 RPLMN_MCC_LIST_INT[] = {310, 311, 312, 313, 314, 315, 316};
kal_uint32 HPPLMN_MCC_LIST_INT[] = {302};

/* The UE is not allowed to perform international HPPLMN search */

kal_uint32 RPLMN_MCC_LIST_DEF[] = {NO_MCC_ALLOWED};
kal_uint32 HPPLMN_MCC_LIST_DEF[] = {NO_MCC_ALLOWED};

kal_uint32* RPLMN_MCC_LIST = NULL;
kal_uint32* HPPLMN_MCC_LIST = NULL;


kal_uint32 RPLMN_MCC_NUM = 0;
kal_uint32 HPPLMN_MCC_NUM = 0;

/*****************************************************************************
* FUNCTION
*   mm_custom_state_after_lu_abnormal
*
* DESCRIPTION
*   According to 3GPP TS24.008 4.4.4.9, the UE may enter the MM IDLE sub-state ATTEMPTING TO UPDATE or
*   optionally the MM IDLE sub-state PLMN SEARCH after LU abnormal 4 times.
*
* PARAMETERS
*   none
*
* RETURNS
*   MM_ENTER_STATE_DEPEND_ON_CONDITION  - Default behavior
*   MM_ENTER_STATE_PLMN_SEARCH          - Always enter MM IDLE sub-state PLMN SEARCH and perform PLMN selection
*   MM_ENTER_STATE_ATTEMPTING_TO_UPDATE - Always enter MM IDLE sub-state ATTEMPTING TO UPDATE and stay on current cell
*
* GLOBALS AFFECTED
*   none
*****************************************************************************/
mm_state_after_lu_abnormal_enum mm_custom_state_after_lu_abnormal(void)
{
    if(sbp_query_md_feature(SBP_MM_PERFORM_PLMN_SEARCH_AFTER_LU_ABNORMAL))
    {
        return MM_ENTER_STATE_PLMN_SEARCH;
    }
    else
    {
        return MM_ENTER_STATE_DEPEND_ON_CONDITION;
    }
}


/*****************************************************************************
* FUNCTION
*   mm_custom_is_try_abnormal_lai_once_more
* DESCRIPTION
*   If abnormal LU 4 times happen, MS will try to search other available and allowable PLMNs. If no other PLMN is found,
*   MS will go back to the abnormal-4-times PLMN and do registration with another 4 attempts.
*
* PARAMETERS
*   none
* RETURNS
*   kal_bool - indicate if "try abnormal lai once more" is enabled.
* GLOBALS AFFECTED
*   none
*****************************************************************************/
kal_bool mm_custom_is_try_abnormal_lai_once_more(void)
{
    return sbp_query_md_feature(SBP_MM_TRY_ABNORMAL_LAI_ONCE_MORE);
}

/*****************************************************************************
* FUNCTION
*  mm_custom_start_t3240_for_page
* DESCRIPTION
*  This function is used to configure whether start T3240 for page.
*
* PARAMETERS
*
* RETURNS
*  kal_bool
* GLOBALS AFFECTED
*  None
*****************************************************************************/
kal_bool mm_custom_start_t3240_for_page(void)
{
    /*work around CMCC 3G network issue
    1. PS signaling exist, receive page for CS domain
    2. send page response, enter MM_WAIT_FOR_NETWORK_COMMAND
    3. handover to another LA, then no MM or CM message from network
    4. can not process CM request until cs signaling or RRC release
    */
    return KAL_TRUE;
}

/*************************************************************************
 * HPLMN matching criteria enhance and customized equivalent PLMN definition
 * 
 * [Important!] Inappropriate setting may violate spec and thus fail FTA cases
 *
 * - CUSTOM_EQ_PLMN[]
 *   Ex: CUSTOM_EQ_PLMN[] = 
 *           {"001010", "00101F", "00202F", CUSTOM_EQ_PLMN_SET_END, //the first 3 PLMNs are regarded as eqivalent to each other
 *            "100011", "10002F", CUSTOM_EQ_PLMN_SET_END}           //100011 and 10002F are regarded as equivalent. 
*************************************************************************/
/*  Regards 31026F and 310260 as eqivalent. To allow cell reselection between 310260 and 31026F (T-Mobile)  */
const char *CUSTOM_EQ_PLMN_TMO[] = {"31026F", "310260", CUSTOM_EQ_PLMN_SET_END};

/* Default. Follows TS23.122 Annex A. Eg. In 310260, MS can reselect to 31026F. 
 * But if in 31026F, MS can't reselect to 310260. 
 */
const char *CUSTOM_EQ_PLMN_DEF[] = {CUSTOM_EQ_PLMN_SET_END};

const char **CUSTOM_EQ_PLMN = NULL;

kal_uint32 CUSTOM_EQ_PLMN_NUM = 0;

/*****************************************************************************
* FUNCTION
*  mm_custom_config_custom_eq_plmn_list
* DESCRIPTION
*  This function is used to configure CUSTOM_EQ_PLMN by SBP function 
*
* PARAMETERS
*
* RETURNS
*  NONE
* GLOBALS AFFECTED
*  None
*****************************************************************************/
void mm_custom_config_custom_eq_plmn_list(void)
{
    if (sbp_query_md_feature(SBP_TMO_PLMN_MATCHING) == KAL_TRUE)
    {
        CUSTOM_EQ_PLMN_NUM = sizeof(CUSTOM_EQ_PLMN_TMO)/sizeof(char *);
        CUSTOM_EQ_PLMN = CUSTOM_EQ_PLMN_TMO;
    }
    
    else
    {
        CUSTOM_EQ_PLMN_NUM = sizeof(CUSTOM_EQ_PLMN_DEF)/sizeof(char *);
        CUSTOM_EQ_PLMN = CUSTOM_EQ_PLMN_DEF;
    } 
}


/*************************************************************************
 * customized roaming allow whitelist PLMN definition
 * 
 * To prevent the specified PLMN is banned due to disable roaming
 *   Ex: HPLMN 46001, international roaming is disable but want to allow to roam on 46692, 46689.
 * - CUSTOM_WL_PLMN[]
 *   Ex: CUSTOM_WL_PLMN[] = 
 *           {"46692F","46689F"}         
 *************************************************************************/

/*  If roaming is diable, only specified PLMNs/HPLMN can be registered by UE  */

const char *CUSTOM_WL_PLMN[] = {INVALID_CUSTOM_WL_PLMN};

const kal_uint32 CUSTOM_WL_PLMN_NUM = sizeof(CUSTOM_WL_PLMN)/sizeof(char *);

/*****************************************************************************
* FUNCTION
*  mm_custom_get_erase_forbidden_la_list_timer_period
* DESCRIPTION
*  This function is used to get ERASE_FORBIDDEN_LA_LIST timer period.
*
* PARAMETERS
*  None
*
* RETURNS
*  kal_uint32
*
* GLOBALS AFFECTED
*  None
*
*****************************************************************************/
kal_uint32 mm_custom_get_erase_forbidden_la_list_timer_period(void)
{
    // TS24.008 specifies this timer should be 12~24hr.
    // Default 12hr.
    // Set 0 to disable this timer
    return 12*60*KAL_TICKS_1_MIN;
}

/*************************************************************************
 * In Japan, UE can not perform MO emergency call if UE has not completed registration procedure 
 * (so, MSC does not know MSISDN of mobile originating user), because transferring MSISDN of
 * mobile originating user to emergency authority is mandatory
 *
 * Example:
 * 1.
 * const kal_uint32 LR_BEFORE_ECC_MCC_LIST[] = {440}; // Only in Japan does UE need perform LR before ECC
 * 2.
 * const kal_uint32 LR_BEFORE_ECC_MCC_LIST[] = {NO_MCC_ALLOWED}; // UE shall perform ECC before LR regardless of MCC
 * 3.
 * const kal_uint32 LR_BEFORE_ECC_MCC_LIST[] = {ALL_MCC_ALLOWED}; // UE shall perform LR before ECC regardless of MCC
 *
 *************************************************************************/
const kal_uint32 LR_BEFORE_ECC_MCC_LIST[] = {NO_MCC_ALLOWED};
const kal_uint32 LR_BEFORE_ECC_MCC_NUM = sizeof(LR_BEFORE_ECC_MCC_LIST)/sizeof(kal_uint32);


/*************************************************************************
 * After abnormal LU 4 times, UE should wait T3212 timeout and then start next LU attempt round.
 * Customization can be done here. Config the RETRY_ABNORMAL_LAI timer value as below. UE will 
 * start the next LU attempt when the RETRY_ABNORMAL_LAI timer expires.
 *************************************************************************/
/* default value: 10 minutes */
const kal_uint32 MM_RETRY_ABNORMAL_LAI_TIMER_PERIOD = 10 * KAL_TICKS_1_MIN;
const kal_uint32 GMM_RETRY_ABNORMAL_RAI_TIMER_PERIOD = 15 * KAL_TICKS_1_MIN;


/*************************************************************************
 * Ignore equivalent PLMN list assigned by operator
 * 
 * - IGNORE_EQPLMN_OPERATOR
 *     - If HPLMN belongs to any PLMN defined in the list,
 *       all eqivalent PLMNs assigned by this HPLMN will be ignored.
 * 
 * - ADD_PLMN_IN_MANUAL_RECOVERY_SEARCH
 *    - If RPLMN is in IGNORE_EQPLMN_OPERATOR and MS lose camp in manual selection mode, 
 *      PLMN in ADD_PLMN_IN_MANUAL_RECOVERY_SEARCH is added to the search target.
 *      Only one PLMN in ADD_PLMN_IN_MANUAL_RECOVERY_SEARCH is allowed.
 * 
 *************************************************************************/
char *IGNORE_EQPLMN_OPERATOR[] = {IGNORE_EQPLMN_OPERATOR_SET_END, IGNORE_EQPLMN_OPERATOR_SET_END, IGNORE_EQPLMN_OPERATOR_SET_END};
kal_uint32 IGNORE_EQPLMN_OPERATOR_NUM = sizeof(IGNORE_EQPLMN_OPERATOR)/sizeof(char *);
char ADD_CUSTOM_PLMN_IN_MANUAL_RECOVERY_SEARCH [] = INVALID_CUSTOM_PLMN_IN_MANUAL_RECOVERY_SEARCH;

/*****************************************************************************
* FUNCTION
*  mm_custom_config_ignore_eqplmn_operator_list
* DESCRIPTION
*  This function is used to configure IGNORE_EQPLMN_OPERATOR by SBP function 
*  when IGNORE_EQPLMN_OPERATOR is empty.
*
* PARAMETERS
*
* RETURNS
*  NONE
* GLOBALS AFFECTED
*  None
*****************************************************************************/
void mm_custom_config_ignore_eqplmn_operator_list(void)
{
    kal_uint32 index = 0;

    /* If IGNORE_EQPLMN_OPERATOR is not empty, do not change the list by SBP */
    if (strcmp(IGNORE_EQPLMN_OPERATOR[0], IGNORE_EQPLMN_OPERATOR_SET_END) != 0)
    {
        return;
    }
    if (sbp_query_md_feature(SBP_MM_IGNORE_YOIGO_EQPLMN) == KAL_TRUE)
    {
        IGNORE_EQPLMN_OPERATOR[index] = "21404F";
        strcpy(ADD_CUSTOM_PLMN_IN_MANUAL_RECOVERY_SEARCH, "21407F");
        index++;
    }

    if (sbp_query_md_feature(SBP_MM_IGNORE_PLAY_EQPLMN) == KAL_TRUE)
    {
        IGNORE_EQPLMN_OPERATOR[index] = "26006F";
        strcpy(ADD_CUSTOM_PLMN_IN_MANUAL_RECOVERY_SEARCH, INVALID_CUSTOM_PLMN_IN_MANUAL_RECOVERY_SEARCH);
        index++;
    }
}


/*****************************************************************************
* FUNCTION
*  mm_custom_search_next_plmn_when_access_class_bar
* DESCRIPTION
*  This function is used to configure whether search next plmn
*  when not test sim and not test mode
*
* PARAMETERS
*
* RETURNS
*  kal_bool
* GLOBALS AFFECTED
*  None
*****************************************************************************/
kal_bool mm_custom_search_next_plmn_when_access_class_barred(void)
{
    return sbp_query_md_feature(SBP_DISABLE_PLMN_SEL_WHEN_ACCESS_BARRED);
}

/*****************************************************************************
* FUNCTION
*  mm_custom_enable_early_oos_ind
* DESCRIPTION
*  If enabled, AP will display OOS when lost coverage and AS start cell reselection
*  If disabled, AP will display OOS after lost coverage and cell reselection failure
*
* PARAMETERS
*
* RETURNS
*  kal_bool
* GLOBALS AFFECTED
*  None
*****************************************************************************/
kal_bool mm_custom_enable_early_oos_ind(void)
{
    return sbp_query_md_feature(SBP_OOS_EARLY_IND);
}

/*****************************************************************************
* FUNCTION
*  mm_custom_report_cell_global_identity
* DESCRIPTION
*  If enabled, modem will update PLMN id, LAC, cell id in 2G connected mode
*  If disabled, modem will not update PLMN id, LAC, cell id in 2G connected mode
*
* PARAMETERS
*
* RETURNS
*  kal_bool
* GLOBALS AFFECTED
*  None
*****************************************************************************/
kal_bool mm_custom_report_cell_global_identity(void)
{
#ifdef __MM_DIRECTLY_REPORT_CELL_INFO_IN_CREG_WHEN_CONNECTED_MODE__
    return KAL_TRUE;
#else
    return KAL_FALSE;
#endif
}

/*****************************************************************************
* FUNCTION
*  mm_custom_enable_dynamic_set_modem2_imei
* DESCRIPTION
*  CMCC requires: Two Modems of TDD GEMINI UE shall use the same IMEI in CMCC Network.
*  But by FT experience, Core Network may reject UE if two modems use the same IMEi.
*  The feature implement: 
*      In China network, two modems use the same IMEI.
*      In other network, two modems use different IMEI.
*
*  Note that this feature should turn on __SET_IMEI_BY_PLMN__
*
* PARAMETERS
*
* RETURNS
*  KAL_TRUE: The feature is enabled.
*  KAL_FALSE: The feature is disabled. In all networks, two modems use the SAME IMEI.
*****************************************************************************/
kal_bool mm_custom_enable_dynamic_set_modem2_imei(void)
{
    return KAL_TRUE;
}

/*************************************************************************
 * Ignore Reject cause 7, GPRS serive not allowed, in ATTACH REJECT or 
 * in ROUTING AREA UPDATING REJECT message when roaming. Reject Cause 
 * 14, GPRS serive not allowed in this PLMN, insteads of.
 * 
 * - IGNORE_GPRS_SERVICE_NOT_ALLOWED_WHEN_ROAMING_OPERATOR
 *     - If PLMN is defined in the list, UE take action as receiving reject
 *        cause 14 when UE receive ATTACH REJECT or ROUTING AREA UPDATING
 *        REJECT message with cause 7 and roaming.
 * 
 *************************************************************************/
#ifdef __GMM_CELCOM_IGNORE_GPRS_SERVICE_NOT_ALLOWED_WHEN_ROAMING__
const char *IGNORE_GPRS_SERVICE_NOT_ALLOWED_WHEN_ROAMING_OPERATOR[] = {"50219F", IGNORE_GPRS_SERVICE_NOT_ALLOWED_WHEN_ROAMING_OPERATOR_SET_END};
#else
const char *IGNORE_GPRS_SERVICE_NOT_ALLOWED_WHEN_ROAMING_OPERATOR[] = {IGNORE_GPRS_SERVICE_NOT_ALLOWED_WHEN_ROAMING_OPERATOR_SET_END};
#endif

const kal_uint32 IGNORE_GPRS_SERVICE_NOT_ALLOWED_WHEN_ROAMING_OPERATOR_NUM = sizeof(IGNORE_GPRS_SERVICE_NOT_ALLOWED_WHEN_ROAMING_OPERATOR)/sizeof(char *);

void mm_custom_config_hpplmn_search_mcc_list(void)
{
    if(sbp_query_md_feature(SBP_HPPLMN_REGARDLESS_ANY_MCC) == KAL_TRUE)      
    {
        RPLMN_MCC_LIST = RPLMN_MCC_LIST_ANY;
        HPPLMN_MCC_LIST = HPPLMN_MCC_LIST_ANY;        
        RPLMN_MCC_NUM = sizeof(RPLMN_MCC_LIST_ANY)/sizeof(kal_uint32);
        HPPLMN_MCC_NUM = sizeof(HPPLMN_MCC_LIST_ANY)/sizeof(kal_uint32);
    }
    else if (sbp_query_md_feature(SBP_ATNT_HPPLMN_SEARCH) == KAL_TRUE)
    {
        RPLMN_MCC_LIST = RPLMN_MCC_LIST_ATNT;
        HPPLMN_MCC_LIST = HPPLMN_MCC_LIST_ATNT;
        RPLMN_MCC_NUM = sizeof(RPLMN_MCC_LIST_ATNT)/sizeof(kal_uint32);
        HPPLMN_MCC_NUM = sizeof(HPPLMN_MCC_LIST_ATNT)/sizeof(kal_uint32);
    }
    else if (sbp_query_md_feature(SBP_MM_INTERNATIONAL_HPPLMN_SEARCH) == KAL_TRUE)
    {
        RPLMN_MCC_LIST = RPLMN_MCC_LIST_INT;
        HPPLMN_MCC_LIST = HPPLMN_MCC_LIST_INT;
        RPLMN_MCC_NUM = sizeof(RPLMN_MCC_LIST_INT)/sizeof(kal_uint32);
        HPPLMN_MCC_NUM = sizeof(HPPLMN_MCC_LIST_INT)/sizeof(kal_uint32);
    }
    else
    {
        RPLMN_MCC_LIST = RPLMN_MCC_LIST_DEF;
        HPPLMN_MCC_LIST = HPPLMN_MCC_LIST_DEF;
        RPLMN_MCC_NUM = sizeof(RPLMN_MCC_LIST_DEF)/sizeof(kal_uint32);
        HPPLMN_MCC_NUM = sizeof(HPPLMN_MCC_LIST_DEF)/sizeof(kal_uint32);
    } 

}

/*****************************************************************************
* FUNCTION
*  mm_init_sbp_config
* DESCRIPTION
*  This function is used to configure MM custom setting dynamically by SBP function.
*  This function is executed at MM init stage before MM receive INIT_REQ from RAC.
*
* PARAMETERS
*  NONE
* RETURNS
*  NONE
* GLOBALS AFFECTED
*  None
*****************************************************************************/
void mm_init_sbp_config(void)
{
    mm_custom_config_ignore_eqplmn_operator_list();
    mm_custom_config_hpplmn_search_mcc_list();
    mm_custom_config_custom_eq_plmn_list();
}

/*************************************************************************
 * PLMN Search abort timer for power on search
 *************************************************************************/
const kal_uint32 MM_PLMN_SEARCH_ABORT_3G_TIMER_PERIOD = 9*KAL_TICKS_1_SEC;

/*****************************************************************************
* FUNCTION
*  mm_custom_disable_previous_rplmn_info_from_nvram
* DESCRIPTION
*  This function is used to configure whether use previous RPLMN information 
*  stored in NVRAM.
*
* PARAMETERS
*
* RETURNS
*  KAL_TRUE: Don't use previous RPLMN information stored in NVRAM.
*  KAL_FALSE: Use previous RPLMN information stored in NVRAM.
* GLOBALS AFFECTED
*  None
*****************************************************************************/
kal_bool mm_custom_disable_previous_rplmn_info_from_nvram(void)
{
    return sbp_query_md_feature(SBP_MM_DISABLE_PREVIOUS_RPLMN_FROM_NVRAM);
}

