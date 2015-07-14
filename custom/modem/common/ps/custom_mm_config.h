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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef _CUSTOM_MM_CONFIG_H
#define _CUSTOM_MM_CONFIG_H

#include "kal_general_types.h"

/*************************************************************************
* Constant
*************************************************************************/
/* Do not modify the following default values */

#define MM_INVALID_TIMER_VALUE 0xffffffff
extern const kal_uint32 MM_RETRY_ABNORMAL_LAI_TIMER_PERIOD;
extern const kal_uint32 GMM_RETRY_ABNORMAL_RAI_TIMER_PERIOD;

/* International Higher Priorirty PLMN Search */
#define ALL_MCC_ALLOWED 0xfff
#define NO_MCC_ALLOWED 0xffffffff

extern kal_uint32* RPLMN_MCC_LIST;
extern kal_uint32 RPLMN_MCC_NUM;
extern kal_uint32* HPPLMN_MCC_LIST;
extern kal_uint32 HPPLMN_MCC_NUM;

extern const kal_uint32 ECC_IMSI_MCC_LIST[];
extern const kal_uint32 ECC_IMSI_MCC_NUM;

extern const kal_uint32 LR_BEFORE_ECC_MCC_LIST[];
extern const kal_uint32 LR_BEFORE_ECC_MCC_NUM;

/* CUSTOM_EQ_PLMN_SET_END indicates the end of each EQ PLMN set */
#define CUSTOM_EQ_PLMN_SET_END "FFFFFF"
extern const char **CUSTOM_EQ_PLMN;
extern kal_uint32 CUSTOM_EQ_PLMN_NUM;

#define INVALID_CUSTOM_WL_PLMN "FFFFFF"
extern const char *CUSTOM_WL_PLMN[];
extern const kal_uint32 CUSTOM_WL_PLMN_NUM;
/* Ignore equivalent PLMN list assigned by operator */
#define IGNORE_EQPLMN_OPERATOR_SET_END "FFFFFF"
extern char *IGNORE_EQPLMN_OPERATOR[];
extern kal_uint32 IGNORE_EQPLMN_OPERATOR_NUM;

#define INVALID_CUSTOM_PLMN_IN_MANUAL_RECOVERY_SEARCH "FFFFFF"
extern char ADD_CUSTOM_PLMN_IN_MANUAL_RECOVERY_SEARCH[];

/* Ignore Reject cause 7, GPRS serive not allowed, in ATTACH REJECT or 
   in ROUTING AREA UPDATING REJECT message when roaming. Reject Cause 
   14, GPRS serive not allowed in this PLMN, insteads of */
#define IGNORE_GPRS_SERVICE_NOT_ALLOWED_WHEN_ROAMING_OPERATOR_SET_END "FFFFFF"
extern const char *IGNORE_GPRS_SERVICE_NOT_ALLOWED_WHEN_ROAMING_OPERATOR[];
extern const kal_uint32 IGNORE_GPRS_SERVICE_NOT_ALLOWED_WHEN_ROAMING_OPERATOR_NUM;

extern const kal_uint32 MM_PLMN_SEARCH_ABORT_3G_TIMER_PERIOD;

/*************************************************************************
* Enum
*************************************************************************/
typedef enum
{
    MM_ENTER_STATE_DEPEND_ON_CONDITION,
    MM_ENTER_STATE_PLMN_SEARCH,
    MM_ENTER_STATE_ATTEMPTING_TO_UPDATE
}mm_state_after_lu_abnormal_enum;

typedef enum
{
    MM_ENABLE_LR_REJ111_RETRY,
    MM_ENABLE_HPPLMN_SEARCH_FORCE_RELEASE_PCH_CONNECTION,
    MM_ENABLE_DELETE_OPERATOR_EQPLMN_IN_MANUAL_MODE,
    MM_ENABLE_DELETE_OPERATOR_EQPLMN_IN_AUTO_MODE,
	MM_ENABLE_PLMNSEL_OPLMN_COEXIST,
    MM_DISPLAY_ROAMING_HPLMN_IN_EPLMN,
    MM_ILL_MS_ME_CAUSE_PS_INVALID_SIM
}mm_setting_enum;

typedef enum
{
    MM_STAY_ON_LA_OF_REGIONAL_PROVISIONAL_SERVICE,
    MM_STAY_ON_LA_OF_REGIONAL_PROVISIONAL_ONLY_IF_TEST_SIM_TEST_MODE,
    MM_NOT_STAY_ON_LA_OF_REGINOAL_PROVISIONAL_SERVICE
}mm_rej_12_handle_enum;

/*************************************************************************
* Function
*************************************************************************/
extern kal_bool mm_custom_registration_related_setting(mm_setting_enum setting);

extern mm_rej_12_handle_enum mm_custom_stay_on_la_of_regional_provisional_service(void);

extern kal_bool mm_custom_allow_rplmn_hplmn_combined_search(void);

/* MAUI_03014009 Russia Operator BeeLine request to use ECC with IMEI */
extern kal_bool mm_custom_force_ecc_with_imei(void);

/* ALPS01451877 UK should be allowed to make emergency calls with expired SIM cards */
extern kal_bool mm_custom_force_ecc_with_imsi_when_invalid_sim(void);

extern mm_state_after_lu_abnormal_enum mm_custom_state_after_lu_abnormal(void);

extern kal_bool mm_custom_is_try_abnormal_lai_once_more(void);

extern kal_bool mm_custom_start_t3240_for_page(void);

extern kal_uint32 mm_custom_get_erase_forbidden_la_list_timer_period(void);

extern kal_bool mm_custom_is_search_hplmn_before_rplmn(void);

extern kal_bool mm_custom_search_next_plmn_when_access_class_barred(void);

extern kal_bool mm_custom_enable_early_oos_ind(void);

extern kal_bool mm_custom_report_cell_global_identity(void);

extern kal_bool mm_custom_enable_dynamic_set_modem2_imei(void);

extern kal_bool mm_custom_disable_previous_rplmn_info_from_nvram (void);

#endif /* _CUSTOM_MM_CONFIG_H */

