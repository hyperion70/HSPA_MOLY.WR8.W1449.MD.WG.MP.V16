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
 * nvram_data_items.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *    This file contains `vendor' defined logical data items stored in NVRAM.
 *    These logical data items are used in object code of Protocol Stack software.
 *
 *    As for customizable logical data items, they are defined in nvram_user_config.c
 *
 * Author:
 * -------
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
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
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 * removed!
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
 * removed!
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
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef NVRAM_NOT_PRESENT

#ifdef __AST_TL1_TDD__
#define __AST_TL1_TDD_RF_PARAMETER_DEFINE__
#endif // __AST_TL1_TDD__

#ifdef NVRAM_AUTO_GEN
#include "nvram_auto_gen.h"
#endif

#include "kal_general_types.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "kal_public_defs.h" //MSBB change #include "stack_common.h"
#include "ex_item.h"

#include "nvram_defs.h"
#include "nvram_enums.h"
#include "nvram_data_items.h"
#include "nvram_editor_data_item.h"
#include "custom_nvram_config.h"
#include "custom_nvram_sec.h"
#include "custom_nvram_restore.h"
#include "custom_nvram_config.h"
#if defined(__NVRAM_COMPRESS_SUPPORT__) && !defined(NVRAM_AUTO_GEN)
#include "nvram_default_value.h"
#endif

#if defined(__CUSTOMIZED_PORT_SETTING__) && !defined(NVRAM_AUTO_GEN)
#include "custom_port_setting.h"
#endif

#include "tst.h"

#if defined(__UMTS_RAT__) && defined(__MTK_UL1_FDD__)
#include "ul1cal.h"
#endif /* __UMTS_RAT__ && __MTK_UL1_FDD__ */

#ifdef __AST_TL1_TDD__
#include "tl1cal_ast.h"
#include "tl1d_custom_rf.h"
#endif // __AST_TL1_TDD__

#include "l1cal.h"
#if defined(__WIFI_SUPPORT__)
#include "wndrv_cal.h"
#endif



#include "dcl.h"

#include "custom_gprs_pdp_default_qos_config.h"

#if(defined(ISP_SUPPORT))
#include "drv_sw_features_isp.h"
#include "camera_tuning_para.h"
#endif

#include "nvram_default_audio.h"            /* NVRAM_EF_CUST_ACOUSTIC_DATA_SIZE */
#ifdef __GAIN_TABLE_SUPPORT__
#include "gain_table.h"
#endif /* __GAIN_TABLE_SUPPORT__ */

#include "adc_channel.h"

#if !defined(__NVRAM_SUPPORT_CUSTPACK__)// && !defined(__L1_STANDALONE__)
//    #include "nvram_cust_pack.c"
#if !defined(EXTERNAL_MMI)
    extern kal_uint8 COMMON_NVRAM_EF_SMSAL_MAILBOX_ADDR_DEFAULT[];
#endif

extern kal_uint8 COMMON_NVRAM_EF_MS_SECURITY_DEFAULT[];    

#ifdef __CPHS__
    extern kal_uint8 COMMON_NVRAM_EF_ALS_LINE_ID_DEFAULT[];
#endif
    
extern kal_uint8 COMMON_NVRAM_EF_MSCAP_DEFAULT[];
extern kal_uint8 COMMON_NVRAM_EF_RAC_PREFERENCE_DEFAULT[];
extern kal_uint8 COMMON_NVRAM_EF_SMSAL_COMMON_PARAM_DEFAULT[];
extern kal_uint8 COMMON_NVRAM_EF_CB_DEFAULT_CH_DEFAULT[];

#ifdef __MOBILE_BROADBAND_PROVISION_CONTEXT__
    extern nvram_ef_mobile_broadband_provision_context_struct COMMON_NVRAM_EF_MOBILE_BROADBAND_PROVISION_CONTEXT_DEFAULT[];
#endif

#ifdef __MEDIATEK_SMART_QOS__
    extern nvram_ef_msq_list_struct NVRAM_EF_MSQ_LIST_DEFAULT[] ;
#endif

#if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__)
    #if defined (__MTK_UL1_FDD__)

            #include "ul1_nvram_def.h"
            extern U_sUl1dRfCustomInputData COMMON_NVRAM_EF_UL1_3G_RF_PARAMETER_DEFAULT[];

    #endif
#endif

#if defined (__UL1_PLATFORM__)
    #if defined (__MTK_UL1_FDD__)
        #include "ul1_nvram_def.h"
        extern nvram_ef_ul1_rf_custpack_data_select_struct COMMON_NVRAM_EF_UL1_RF_CUSTPACK_DATA_SELECT_DEFAULT[];
        extern nvram_ef_ul1_rf_custom_data_struct COMMON_NVRAM_EF_UL1_RF_CUSTOM_DATA_DEFAULT[];
    #endif
#endif


#endif  /* __MMI_FMI__*/
/*The chip doesn't support A5/3*/
#if defined( MT6208) || defined( MT6205) || defined( MT6218) || defined( MT6219) || \
    defined( MT6217) || defined( MT6227) || defined( MT6226) || defined( MT6228) || \
    defined(MT6205B) || defined(MT6226M) || defined(MT6218B)
#define __NO_SUPPORT_A5_3__
#endif

extern void nvram_get_L1_default_value_to_write(nvram_lid_enum lid, kal_uint8 *buffer, kal_uint16 buffer_size);

/**
 * Steps of defining logical data item:
 * 1> Define LID of new logical data item into `nvram_lid_core_enum' in
 *    nvram_data_items.h
 * 2> Define two constants: SIZE and TOTAL, in nvram_data_items.h
 * 3> Define default value of that new logical data item.
 * 4> Define attributes of that new logical data item into
 *    `logical_data_item_table_core'
 * 5> Change NVRAM_TOTAL_LID_VENDOR in nvram_user_defs.h
 * 6> Add structure defination in nvram_editor_data_item.h
 * 7> Add bit-level description in nvram_editor_data_item.h
 * 8> Change version number CODED_DATA_VERSION in nvram_user_config.c
 *
 * Note that multiple copied attribute DOES NOT support for
 * near fixed logical data items.
 */

/**
 * Step 3:
 * Define necessary default values for each logical data item.
 */

kal_uint8 const NVRAM_EF_ZERO_DEFAULT[] = { 0x00 };
kal_uint8 const NVRAM_EF_FF_DEFAULT[] = { 0xFF };

static kal_uint8 const NVRAM_EF_CFU_FLAG_DEFAULT[] = {
                  0x55, 0x55
};

static nvram_ef_mm_eqplmn_locigprs_struct const NVRAM_EF_MM_EQPLMN_LOCIGPRS_DEFAULT[] = {
		0x00, //rplmn_rat
		0x00, //num_of_eq_plmn    	
		{
	    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[0]
	    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[1]
	    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[2]
	    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[3]
	    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[4]
	    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[5]
#ifdef __REL6__
	    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[6]
	    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[7]
	    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[8]
	    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[9]
	    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[10]
	    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[11]
	    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[12]
	    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[13]
	    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[14]
	    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[15]
#endif
	    },
#ifdef __PS_SERVICE__ 	
		{0xff, 0xff, 0xff, 0xff,	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}//nvram_locigprs
#endif
#ifdef __UE_EFOPLMN__
    ,    
    {0x00,0x00}, // version
	272,   // OPLMN_entry	
	{
	0x2, 0xF2, 0x50, 0x80, 0x80, 
	0x2, 0xF4, 0x40, 0x80, 0x80, 
	0x2, 0xF6, 0x10, 0x80, 0x80, 
	0x2, 0xF8, 0x1, 0x80, 0x80, 
	0x12, 0xF2, 0x10, 0x0, 0x80, 
	0x12, 0xF3, 0x30, 0x0, 0x80, 
	0x12, 0xF4, 0x10, 0x80, 0x80, 
	0x12, 0xF6, 0x7, 0x80, 0x80, 
	0x12, 0xF8, 0x9, 0x0, 0x80, 
	0x12, 0xF9, 0x1, 0x80, 0x80, 
	0x12, 0xF9, 0x20, 0x80, 0x80, 
	0x12, 0xF9, 0x10, 0x80, 0x80, 
	0x22, 0xF0, 0x20, 0x0, 0x80, 
	0x22, 0xF0, 0x50, 0x80, 0x80, 
	0x22, 0xF0, 0x30, 0x0, 0x80, 
	0x22, 0xF2, 0x5, 0x0, 0x80, 
	0x22, 0xF2, 0x1, 0x80, 0x80, 
	0x22, 0xF2, 0x88, 0x80, 0x80, 
	0x22, 0xF6, 0x10, 0x80, 0x80, 
	0x22, 0xF8, 0x10, 0x80, 0x80, 
	0x32, 0xF0, 0x30, 0x80, 0x80, 
	0x32, 0xF1, 0x10, 0x80, 0x80, 
	0x32, 0xF2, 0x10, 0x80, 0x80, 
	0x32, 0xF4, 0x51, 0x80, 0x80, 
	0x32, 0xF4, 0x30, 0x80, 0x80, 
	0x32, 0xF4, 0x85, 0x0, 0x80, 
	0x32, 0xF8, 0x10, 0x80, 0x80, 
	0x42, 0xF0, 0x80, 0x80, 0x80, 
	0x42, 0xF0, 0x70, 0x80, 0x80, 
	0x42, 0xF2, 0x10, 0x80, 0x80, 
	0x42, 0xF4, 0x50, 0x80, 0x80, 
	0x42, 0xF6, 0x20, 0x80, 0x80, 
	0x42, 0xF7, 0x50, 0x80, 0x80, 
	0x42, 0xF8, 0x20, 0x80, 0x80, 
	0x52, 0xF0, 0x10, 0x80, 0x80, 
	0x52, 0xF5, 0x10, 0x0, 0x80, 
	0x52, 0xF5, 0x60, 0x0, 0x80, 
	0x52, 0xF5, 0x70, 0x80, 0x0, 
	0x52, 0xF7, 0x20, 0x0, 0x80, 
	0x52, 0xF7, 0x40, 0x80, 0x80, 
	0x52, 0xF9, 0x10, 0x0, 0x80, 
	0x62, 0xF0, 0x10, 0x80, 0x80, 
	0x62, 0xF2, 0x20, 0x80, 0x80, 
	0x62, 0xF6, 0x10, 0x80, 0x80, 
	0x62, 0xF8, 0x10, 0x80, 0x80, 
	0x72, 0xF0, 0x77, 0x80, 0x80, 
	0x72, 0xF2, 0x10, 0x80, 0x80, 
	0x72, 0xF4, 0x20, 0x0, 0x80, 
	0x72, 0xF6, 0x20, 0x0, 0x80, 
	0x72, 0xF8, 0x10, 0x80, 0x80, 
	0x82, 0xF0, 0x10, 0x80, 0x80, 
	0x82, 0xF0, 0x1, 0x80, 0x80, 
	0x82, 0xF2, 0x20, 0x0, 0x80, 
	0x82, 0xF3, 0x50, 0x80, 0x80, 
	0x82, 0xF3, 0x1, 0x80, 0x80, 
	0x82, 0xF4, 0x10, 0x80, 0x80, 
	0x82, 0xF6, 0x20, 0x0, 0x80, 
	0x82, 0xF6, 0x30, 0x0, 0x80, 
	0x82, 0xF8, 0x10, 0x0, 0x80, 
	0x92, 0xF0, 0x10, 0x0, 0x80, 
	0x92, 0xF2, 0x10, 0x0, 0x80, 
	0x92, 0xF3, 0x4, 0x0, 0x80, 
	0x92, 0xF4, 0x30, 0x0, 0x80, 
	0x92, 0xF5, 0x50, 0x0, 0x80, 
	0x92, 0xF7, 0x10, 0x0, 0x80, 
	0x92, 0xF7, 0x30, 0x80, 0x80, 
	0x3, 0x2, 0x16, 0x80, 0x0, 
	0x3, 0x2, 0x22, 0x80, 0x0, 
	0x13, 0x0, 0x62, 0x0, 0x80, 
	0x13, 0x0, 0x14, 0x80, 0x80, 
	0x13, 0x0, 0x83, 0x80, 0x80, 
	0x13, 0x0, 0x74, 0x80, 0x80, 
	0x33, 0x4, 0x30, 0x0, 0x80, 
	0x33, 0x4, 0x20, 0x80, 0x80, 
	0x33, 0x8, 0x50, 0x0, 0x80, 
	0x43, 0xF0, 0x2, 0x0, 0x80, 
	0x43, 0x2, 0x6, 0x0, 0x80, 
	0x43, 0x4, 0x29, 0x0, 0x80, 
	0x43, 0x6, 0x41, 0x0, 0x80, 
	0x43, 0x8, 0x71, 0x80, 0x80, 
	0x53, 0xF0, 0x10, 0x0, 0x80, 
	0x53, 0x2, 0x11, 0x0, 0x80, 
	0x53, 0x4, 0x68, 0x0, 0x80, 
	0x53, 0x6, 0x11, 0x0, 0x80, 
	0x53, 0x8, 0x11, 0x0, 0x80, 
	0x63, 0x0, 0x11, 0x0, 0x80, 
	0x63, 0xF2, 0x96, 0x0, 0x80, 
	0x63, 0xF3, 0x10, 0x80, 0x80, 
	0x63, 0xF3, 0x20, 0x0, 0x80, 
	0x63, 0xF4, 0x93, 0x0, 0x80, 
	0x63, 0x5, 0x48, 0x0, 0x80, 
	0x63, 0x6, 0x11, 0x0, 0x80, 
	0x63, 0xF8, 0x10, 0x0, 0x80, 
	0x73, 0xF0, 0x20, 0x80, 0x80, 
	0x73, 0xF0, 0x40, 0x0, 0x80, 
	0x73, 0x4, 0x31, 0x0, 0x80, 
	0x73, 0x6, 0x53, 0x0, 0x80, 
	0x4, 0xF0, 0x40, 0x80, 0x80, 
	0x4, 0xF1, 0x10, 0x0, 0x80, 
	0x4, 0xF2, 0x77, 0x0, 0x80, 
	0x4, 0xF4, 0x24, 0x80, 0x80, 
	0x4, 0xF4, 0x96, 0x0, 0x80, 
	0x4, 0xF4, 0x11, 0x0, 0x80, 
	0x4, 0xF4, 0x86, 0x0, 0x80, 
	0x4, 0xF4, 0x2, 0x0, 0x80, 
	0x4, 0xF4, 0x3, 0x0, 0x80, 
	0x4, 0xF4, 0x72, 0x0, 0x80, 
	0x4, 0xF4, 0x50, 0x0, 0x80, 
	0x4, 0xF4, 0x34, 0x0, 0x80, 
	0x4, 0xF4, 0x64, 0x0, 0x80, 
	0x14, 0xF0, 0x30, 0x0, 0x80, 
	0x14, 0xF2, 0x2, 0x0, 0x80, 
	0x14, 0xF2, 0x5, 0x80, 0x80, 
	0x14, 0xF3, 0x20, 0x80, 0x80, 
	0x14, 0xF5, 0x30, 0x0, 0x80, 
	0x14, 0xF6, 0x10, 0x0, 0x80, 
	0x14, 0xF6, 0x30, 0x0, 0x80, 
	0x14, 0xF7, 0x20, 0x0, 0x80, 
	0x14, 0xF8, 0x2, 0x0, 0x80, 
	0x14, 0xF9, 0x20, 0x80, 0x80, 
	0x14, 0xF9, 0x30, 0x0, 0x80, 
	0x24, 0xF0, 0x10, 0x80, 0x80, 
	0x24, 0xF1, 0x20, 0x0, 0x80, 
	0x24, 0xF2, 0x20, 0x0, 0x80, 
	0x24, 0xF4, 0x20, 0x80, 0x80, 
	0x24, 0xF5, 0x10, 0x80, 0x80, 
	0x24, 0xF5, 0x20, 0x80, 0x80, 
	0x24, 0xF5, 0x50, 0x0, 0x80, 
	0x24, 0xF6, 0x20, 0x80, 0x80, 
	0x24, 0xF6, 0x40, 0x80, 0x80, 
	0x24, 0xF7, 0x20, 0x80, 0x80, 
	0x24, 0xF8, 0x99, 0x0, 0x80, 
	0x24, 0xF9, 0x10, 0x0, 0x80, 
	0x34, 0xF2, 0x11, 0x0, 0x80, 
	0x34, 0xF4, 0x50, 0x0, 0x80, 
	0x34, 0xF6, 0x20, 0x0, 0x80, 
	0x34, 0xF7, 0x10, 0x0, 0x80, 
	0x34, 0xF8, 0x10, 0x0, 0x80, 
	0x44, 0xF0, 0x1, 0x80, 0x0, 
	0x54, 0xF0, 0x50, 0x80, 0x0, 
	0x54, 0xF0, 0x80, 0x80, 0x0, 
	0x54, 0xF2, 0x20, 0x0, 0x80, 
	0x54, 0xF4, 0x30, 0x80, 0x80, 
	0x54, 0xF4, 0x40, 0x0, 0x80, 
	0x54, 0xF5, 0x10, 0x80, 0x80, 
	0x54, 0xF6, 0x20, 0x80, 0x80, 
	0x54, 0xF6, 0x90, 0x0, 0x80, 
	0x54, 0xF7, 0x80, 0x0, 0x80, 
	0x64, 0xF0, 0x10, 0x80, 0x80, 
	0x64, 0xF6, 0x79, 0x0, 0x80, 
	0x64, 0xF6, 0x99, 0x0, 0x80, 
	0x64, 0xF6, 0x39, 0x0, 0x80, 
	0x74, 0xF0, 0x10, 0x0, 0x80, 
	0x74, 0xF2, 0x20, 0x80, 0x80, 
	0x5, 0xF2, 0x21, 0x80, 0x80, 
	0x5, 0xF5, 0x30, 0x80, 0x80, 
	0x5, 0xF5, 0x1, 0x0, 0x80, 
	0x15, 0xF0, 0x10, 0x0, 0x80, 
	0x15, 0xF0, 0x1, 0x80, 0x80, 
	0x15, 0xF4, 0x20, 0x0, 0x80, 
	0x15, 0xF5, 0x30, 0x0, 0x80, 
	0x15, 0xF5, 0x50, 0x0, 0x80, 
	0x25, 0xF0, 0x99, 0x0, 0x80, 
	0x25, 0xF5, 0x50, 0x0, 0x80, 
	0x25, 0xF5, 0x10, 0x0, 0x80, 
	0x25, 0xF5, 0x20, 0x0, 0x80, 
	0x25, 0xF8, 0x20, 0x80, 0x0, 
	0x35, 0xF0, 0x10, 0x80, 0x80, 
	0x35, 0xF7, 0x30, 0x0, 0x80, 
	0x35, 0xF9, 0x88, 0x0, 0x80, 
	0x45, 0xF0, 0x10, 0x0, 0x80, 
	0x45, 0xF1, 0x50, 0x0, 0x80, 
	0x45, 0xF2, 0x10, 0x0, 0x80, 
	0x45, 0x4, 0x11, 0x0, 0x80, 
	0x45, 0xF6, 0x10, 0x0, 0x80, 
	0x45, 0xF7, 0x2, 0x0, 0x80, 
	0x45, 0xF8, 0x10, 0x0, 0x80, 
	0x45, 0xF9, 0x0, 0x0, 0x80, 
	0x55, 0xF0, 0x10, 0x0, 0x80, 
	0x55, 0xF2, 0x8, 0x0, 0x80, 
	0x6, 0xF2, 0x20, 0x80, 0x80, 
	0x6, 0xF2, 0x30, 0x80, 0x80, 
	0x6, 0xF3, 0x30, 0x0, 0x80, 
	0x6, 0xF3, 0x20, 0x0, 0x80, 
	0x6, 0xF4, 0x10, 0x0, 0x80, 
	0x6, 0xF4, 0x0, 0x0, 0x80, 
	0x6, 0xF5, 0x20, 0x0, 0x80, 
	0x6, 0xF6, 0x10, 0x0, 0x80, 
	0x6, 0xF7, 0x40, 0x80, 0x80, 
	0x6, 0xF8, 0x10, 0x0, 0x80, 
	0x6, 0xF9, 0x1, 0x0, 0x80, 
	0x16, 0xF0, 0x20, 0x0, 0x80, 
	0x16, 0xF1, 0x40, 0x0, 0x80, 
	0x16, 0xF2, 0x20, 0x0, 0x80, 
	0x16, 0xF3, 0x20, 0x0, 0x80, 
	0x16, 0xF4, 0x30, 0x0, 0x80, 
	0x16, 0xF4, 0x20, 0x0, 0x80, 
	0x16, 0xF5, 0x30, 0x0, 0x80, 
	0x16, 0xF6, 0x30, 0x0, 0x80, 
	0x16, 0xF6, 0x20, 0x0, 0x80, 
	0x16, 0xF7, 0x30, 0x0, 0x80, 
	0x16, 0xF8, 0x10, 0x0, 0x80, 
	0x16, 0xF8, 0x70, 0x0, 0x80, 
	0x16, 0xF9, 0x10, 0x0, 0x80, 
	0x26, 0xF0, 0x10, 0x0, 0x80, 
	0x26, 0xF1, 0x6, 0x0, 0x80, 
	0x26, 0xF2, 0x10, 0x0, 0x80, 
	0x26, 0xF3, 0x20, 0x0, 0x80, 
	0x26, 0xF4, 0x10, 0x0, 0x80, 
	0x26, 0xF5, 0x10, 0x0, 0x80, 
	0x26, 0xF6, 0x10, 0x0, 0x80, 
	0x26, 0xF7, 0x30, 0x0, 0x80, 
	0x26, 0xF8, 0x30, 0x0, 0x80, 
	0x26, 0xF9, 0x10, 0x0, 0x80, 
	0x36, 0xF0, 0x20, 0x0, 0x80, 
	0x36, 0xF1, 0x40, 0x80, 0x80, 
	0x36, 0xF2, 0x20, 0x0, 0x80, 
	0x36, 0xF3, 0x10, 0x0, 0x80, 
	0x36, 0xF4, 0x10, 0x0, 0x80, 
	0x36, 0xF5, 0x31, 0x0, 0x80, 
	0x36, 0xF6, 0x10, 0x0, 0x80, 
	0x36, 0xF8, 0x10, 0x0, 0x80, 
	0x36, 0xF9, 0x20, 0x0, 0x80, 
	0x46, 0xF0, 0x40, 0x0, 0x80, 
	0x46, 0xF0, 0x30, 0x80, 0x80, 
	0x46, 0xF0, 0x50, 0x0, 0x80, 
	0x46, 0xF1, 0x10, 0x0, 0x80, 
	0x46, 0xF1, 0x1, 0x0, 0x80, 
	0x46, 0xF2, 0x28, 0x0, 0x80, 
	0x46, 0xF3, 0x10, 0x0, 0x80, 
	0x46, 0xF5, 0x10, 0x0, 0x80, 
	0x46, 0xF6, 0x10, 0x0, 0x80, 
	0x46, 0xF7, 0x1, 0x0, 0x80, 
	0x46, 0xF8, 0x40, 0x0, 0x80, 
	0x46, 0xF9, 0x10, 0x0, 0x80, 
	0x56, 0xF0, 0x1, 0x0, 0x80, 
	0x56, 0xF1, 0x10, 0x0, 0x80, 
	0x56, 0xF2, 0x20, 0x0, 0x80, 
	0x56, 0xF3, 0x1, 0x0, 0x80, 
	0x56, 0xF4, 0x10, 0x0, 0x80, 
	0x56, 0xF5, 0x10, 0x80, 0x80, 
	0x7, 0xF2, 0x76, 0x0, 0x80, 
	0x7, 0xF4, 0x10, 0x80, 0x80, 
	0x7, 0xF6, 0x10, 0x0, 0x80, 
	0x7, 0x8, 0x40, 0x0, 0x80, 
	0x17, 0xF0, 0x12, 0x80, 0x80, 
	0x17, 0xF0, 0x37, 0x0, 0x80, 
	0x17, 0xF2, 0x30, 0x80, 0x80, 
	0x17, 0xF2, 0x40, 0x80, 0x80, 
	0x17, 0xF4, 0x40, 0x0, 0x80, 
	0x17, 0xF6, 0x1, 0x80, 0x80, 
	0x27, 0xF2, 0x43, 0x0, 0x80, 
	0x27, 0xF4, 0x40, 0x80, 0x80, 
	0x27, 0xF4, 0x20, 0x80, 0x80, 
	0x27, 0xF4, 0x30, 0x80, 0x80, 
	0x37, 0xF0, 0x10, 0x80, 0x80, 
	0x37, 0x32, 0x21, 0x0, 0x80, 
	0x37, 0xF4, 0x60, 0x80, 0x80, 
	0x37, 0xF6, 0x10, 0x0, 0x80, 
	0x37, 0xF8, 0x10, 0x0, 0x80, 
	0x47, 0xF0, 0x10, 0x80, 0x80, 
	0x47, 0xF4, 0x40, 0x0, 0x80, 
	0x47, 0xF4, 0x10, 0x0, 0x80, 
	0x47, 0xF6, 0x30, 0x0, 0x80, 
	0x47, 0xF8, 0x70, 0x80, 0x80, 
	0x47, 0xF8, 0x1, 0x0, 0x80, 
	0x57, 0xF0, 0x0, 0x0, 0x80, 
	0x9, 0xF1, 0x72, 0x0, 0x80, 
	0x9, 0xF1, 0x21, 0x0, 0x80, 
	0x9, 0xF1, 0x91, 0x0, 0x80, 
	0x9, 0xF1, 0x41, 0x0, 0x80, 
	0x9, 0xF1, 0x51, 0x0, 0x80
	}
#endif    
};

#ifdef __TC02_SECURITY_REQUIREMENT__
static kal_uint8 const NVRAM_EF_MM_IMSI_LOCI_GLOCI_DEFAULT[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //EF_IMSI
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, //EF_LOCI
    0xff, 0xff, 0xff, 0xff,	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff //EF_GLOCI
};
#endif /* __TC02_SECURITY_REQUIREMENT__ */

#if defined(__ATCMD_ONOFF_CHECK__)
const nvram_atcmd_check_context_struct NVRAM_EF_ATCMD_ONOFF_CHECK_DEFAULT =
{
        {ATCMD_CHECK_ENABLE, 0x26598088, ATCMD_CHECK_ENABLE, 0X26598088},
        ATCMD_CHECK_ENABLE,  /* enable */
        {0x26598088, ATCMD_CHECK_ENABLE, 0x26598088}
};
#endif

#if defined(__ETWS_SUPPORT__)
const nvram_ef_etws_setting_struct NVRAM_EF_ETWS_SETTING_DEFAULT =
{
#ifdef __UE_SIMULATOR__
        0x01  /* always ON */
#else
        0x00
#endif        
};
#endif

static kal_uint8 const NVRAM_EF_BAND_INFO_DEFAULT[] = {
        0x00, /* mcc1 */
        0x00, /* mcc2 */
        0x00, /* mcc3 */
        0x00, /* learned_band */
        0x00, /* working_band */
        0x00  /* when __BAND_PRIORITY_SEARCH__ is defined, this
               * byte is used to set the priority for each band:
               *
               *      850     1900    1800    900
               *     +-------------------------------+
               * bit | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 | 
               *     +-------------------------------+
               * The priority of each band is representive by two bits:
               *
               * <ex> bit 5 and 4 is the priority for 1900 band:
               *         '0'   '0' -> priority value 0
               *         '0'   '1' -> priority value 1
               *         '1'   '0' -> priority value 2
               *         '1'   '1' -> priority value 3
               *  
               *      The smaller the value is, the higher the priroity is:
               *      (1) if no band is preferred, the value can be assigned:
               *          0x00, 0x55, 0xaa, or 0xff
               *      (2) if 900/1800 is prefered, the value can be assigned:
               *          0x50, 0xF0, 0xF5 and so on.
               *      (3) if 850/1900 is prefered, the value can be assigned:
               *          0x05, 0x0F, 0x5F and so on.
               *      (4) if the band prefered order is 1900 -> 8500 -> 900 -> 1800,
               *          the value 0x4e (0100 1110) should be used.
               */
};

static kal_uint8 const NVRAM_EF_CLASSMARK_RACAP_DEFAULT[] = {
       /*---BYTE 1 to BYTE 6 : From MS CLASSMARK3 -------------------------*/

    /*Evelyn 071127 add compile option for EDGE CARD: different power class*/
#if defined ( __EDGE_CARD_CLASS_12__ )

#if defined( __EGSM900__) && defined( __DCS1800__)
#if defined ( __DISABLE_EGSM__ )
                  0x50,  /* MS supports P-GSM and DCS band */
#else
                  0x60,  /* MS supports E-GSM and DCS band */
#endif                  
                  0x25,  /* E-GSM power class 5, DCS power class 2 */
#elif defined( __PGSM900__) && defined( __DCS1800__)
                  0x50,  /* MS supports P-GSM and DCS band */
                  0x25,  /* P-GSM power class 5, DCS power class 2 */
#elif defined( __EGSM900__)
                  0x60,  /* MS supports E-GSM band only */
                  0x05,  /* E-GSM power class 5 */
#elif defined (__PGSM900__)
                  0x60,  /* MS supports P-GSM band only */
                  0x05,  /* P-GSM power class 5 */
#elif defined ( __DCS1800__ )
                  0x40,  /* MS supports DCS band only */
                  0x02,  /* DCS power class 2 */
#else
                  0x00,  /* None of GSM900 and DCS1800 are supported */
                  0x00,
#endif

#else /*__EDGE_CARD_CALSS_12__  */
       /* Claire 030922 change : Support multiband compile option */
#if defined( __EGSM900__) && defined( __DCS1800__)
#if defined ( __DISABLE_EGSM__ )
                  0x50,  /* MS supports P-GSM and DCS band */
#else
                  0x60,  /* MS supports E-GSM and DCS band */
#endif                  
                  0x14,  /* E-GSM power class 4, DCS power class 1 */
#elif defined( __PGSM900__) && defined( __DCS1800__)
                  0x50,  /* MS supports P-GSM and DCS band */
                  0x14,  /* P-GSM power class 4, DCS power class 1 */
#elif defined( __EGSM900__)
                  0x60,  /* MS supports E-GSM band only */
                  0x04,  /* E-GSM power class 4 */
#elif defined (__PGSM900__)
                  0x60,  /* MS supports P-GSM band only */
                  0x04,  /* P-GSM power class 4 */
#elif defined ( __DCS1800__ )
                  0x40,  /* MS supports DCS band only */
                  0x01,  /* DCS power class 1 */
#else
                  0x00,  /* None of GSM900 and DCS1800 are supported */
                  0x00,
#endif

#endif /* __EDGE_CARD_CALSS_12__  */
                  0x01,  /* HSCSD multislot cap not present, UCS2 =1 */
                  /* Claire 030922 change : Support multiband compile option */


#if defined( __GSM450__) || defined( __GSM480__)
#ifdef __AGPS_CONTROL_PLANE__
                  0xcf,  /* Extended Measurement cap = 1, AGPS support (support for conventional GPS), GSM 400 band support */
#else
                  0x81,  /* Extended Measurement cap = 1, AGPS not support (no support for conventional GPS), GSM 400 band support */
#endif /* __AGPS_CONTROL_PLANE__ */
#else
#ifdef __AGPS_CONTROL_PLANE__
                  0xce,  /* Extended Measurement cap = 1, AGPS support (support for conventional GPS), GSM 400 band not support */
#else
                  0x80,  /* Extended Measurement cap = 1, AGPS not support (no support for conventional GPS), GSM 400 band not support */
#endif /* __AGPS_CONTROL_PLANE__ */
#endif


#if !defined( __GSM450__) && !defined( __GSM480__) && !defined( __GSM850__)
                  0x00,  /* GSM 400 and GSM 850 are not suported */
#elif defined( __GSM450__) && !defined( __GSM480__) && !defined( __GSM850__)
                 0x90,  /* GSM 450 is supported with power class 4*/
#elif !defined( __GSM450__) && defined( __GSM480__) && !defined( __GSM850__)
                 0x50,  /* GSM 480 is supported with power class 4*/
#elif !defined( __GSM450__) && !defined( __GSM480__) && defined( __GSM850__)
                 0x02,  /* GSM 850 is supported*/
#elif defined( __GSM450__) && defined( __GSM480__) && !defined( __GSM850__)
                 0xd0,  /* GSM 450 and 480 are supported with power class 4*/
#elif defined( __GSM450__) && !defined( __GSM480__) && defined( __GSM850__)
                 0x92,  /* GSM 450 with power class 4 and GSM 850 are supported*/
#elif !defined( __GSM450__) && defined( __GSM480__) && defined( __GSM850__)
                 0x52,  /* GSM 450 with power class 4 and GSM 850 are supported*/
#else
                 0xd2,   /* GSM 450, 480 with power class 4 and 850 are supported*/
#endif

/*Evelyn 071127 add compile option for EDGE CARD: different power class*/
#if defined( __EDGE_CARD_CLASS_12__ )

#if defined( __GSM850__) && defined( __PCS1900__)
                  0xb2,  /* GSM 850 is power class 5 ,PCS 1900 is suportedwith power class 2*/
#elif  defined( __PCS1900__)
                  0x12,  /* PCS 1900 is suported , power class 2 */
#elif  defined( __GSM850__)
                  0xa0,  /* GSM 850 is power class 5 */
#else
                  0x00,  /* Both GSM 850 and DCS 1900 are not supported */
#endif

#else /* __EDGE_CARD_CALSS_12__  */

#if defined( __GSM850__) && defined( __PCS1900__)
                  0x91,  /* GSM 850 is power class 4 ,PCS 1900 is suportedwith power class 1*/
#elif  defined( __PCS1900__)
                  0x11,  /* PCS 1900 is suported , power class 1 */
#elif  defined( __GSM850__)
                  0x80,  /* GSM 850 is power class 4 */
#else
                  0x00,  /* Both GSM 850 and DCS 1900 are not supported */
#endif

#endif /* __EDGE_CARD_CALSS_12__  */


       /*---BYTE 7 to BYTE 9 : From MS CLASSMARK2 -----------  */
                  0x30,  /* ES_IND =1, Revision level =01, A51 algo supported---*/
                  0x58,  /* PS cap =1, SS sreen indicator =01, SM cap =1 */

/* CCBS supported */
#if defined(__NO_SUPPORT_A5_3__) && defined(__DISABLE_A5_2__) && defined(__CCBS_SUPPORT__)
#ifdef __AGPS_CONTROL_PLANE__
                  0xa4,
#else
                  0x84,
#endif
#elif !defined(__NO_SUPPORT_A5_3__) && defined(__DISABLE_A5_2__) && defined(__CCBS_SUPPORT__)
#ifdef __AGPS_CONTROL_PLANE__
                  0xa6,
#else
                  0x86,
#endif
#elif defined(__NO_SUPPORT_A5_3__) && !defined(__DISABLE_A5_2__) && defined(__CCBS_SUPPORT__)
#ifdef __AGPS_CONTROL_PLANE__
                  0xa5,
#else
                  0x85,
#endif
#elif !defined(__NO_SUPPORT_A5_3__) && !defined(__DISABLE_A5_2__) && defined(__CCBS_SUPPORT__)
#ifdef __AGPS_CONTROL_PLANE__
                  0xa7,
#else
                  0x87,
#endif
/* CCBS not supported */
#elif defined(__NO_SUPPORT_A5_3__) && defined(__DISABLE_A5_2__) && !defined(__CCBS_SUPPORT__)
#ifdef __AGPS_CONTROL_PLANE__
                  0xa0,
#else
                  0x80,
#endif
#elif !defined(__NO_SUPPORT_A5_3__) && defined(__DISABLE_A5_2__) && !defined(__CCBS_SUPPORT__)
#ifdef __AGPS_CONTROL_PLANE__
                  0xa2,
#else
                  0x82,
#endif
#elif defined(__NO_SUPPORT_A5_3__) && !defined(__DISABLE_A5_2__) && !defined(__CCBS_SUPPORT__)
#ifdef __AGPS_CONTROL_PLANE__
                  0xa1,
#else
                  0x81,
#endif
#else //!defined(__NO_SUPPORT_A5_3__) && !defined(__DISABLE_A5_2__) && !defined(__CCBS_SUPPORT__)
#ifdef __AGPS_CONTROL_PLANE__
                  0xa3,
#else
                  0x83,
#endif
#endif

       /*---BYTE 10 to BYTE 12 : From MS RA capability and MS network capability --*/

                           /* BYTE 10:
                            * bit 8: multislot capability present,
                            * bit 7 ~ 3: mutlislot capability,
                            * bit 2: GPRS extended Dynamic Allocation cap =1
                            * bit 1 : RL indicator = 0 => R98 MS, 1 => R99 MS */
#ifdef __R99__
   #if defined(__EDGE_CARD_CLASS_10__) || defined(__GPRS_MULTISLOT_CLASS_10__)
                  0xab,   /* Default GPRS multislot class 10, ext DA support, R99 */
   #else
                  0xb3,  /* Default GPRS multislot class 12, ext DA support, R99 */
   #endif
#else /* __R99__*/
   #if defined(__EDGE_CARD_CLASS_10__) || defined(__GPRS_MULTISLOT_CLASS_10__)
                  0xaa,   /* Default GPRS multislot class 10, ext DA support, R98 */
   #else
                  0xb2,  /* Default GPRS multislot class 12, ext DA support, R98 */
   #endif
#endif /* __R99__ */

                           /* BYTE 11:
                            * bit 8 : GEA1
                            * bit 7 : GEA2
                            * bit 6 : GEA3
                            * bit 5 : GEA4
                            * bit 4 : GEA5
                            * bit 3 : GEA6
                            * bit 2 : GEA7
                            * bit 1 : SM cap in GPRS =1 */
/* Peter 080520: change complie option */
#ifdef __NO_SUPPORT_A5_3__
                  0xc1, /* GEA1, 2 and SM cap support */
#else // The chip support A5/3(GEA/3)
    0xe1, /* GEA1, 2, 3 and SM cap support */
#endif

                           /* BYTE 12: Lanslo 20060215: for selecting GPRS or EGPRS capability
                             * bit 8: PFC mode = 0b
                             * bit 7: EDGE multislot class present / EDGE support = 1b
                             * bit 6 ~ 2: EDGE multislot capability = 01100b
                             * bit 1: EDGE extended dynamic allocation capability = 1b
                             * Old value 0x80, new 0xd9(PFC on), 0x59 (PFC off) */

/* Evelyn 20090511: open the PFC support bit */
#ifdef __EGPRS_MODE__
   #if defined(__EDGE_CARD_CLASS_10__) || defined(__EDGE_MULTISLOT_CLASS_10__)
                  0xD5,   /* PFC on, EGPRS multislot class 10, Ext DA support */
   #else
                  0xD9,   /* PFC on, EGPRS multislot class 12, Ext DA support */
   #endif
#else /* __EGPRS_MODE__ */
   #ifdef __R99__
                  0x80,   /* PFC on */
   #else
                  0x00,   /* PFC off */
   #endif
#endif /* __EGPRS_MODE__ */

// Jelly 20090602 Use __EPSK_TX__
#if (defined(__EGPRS_MODE__) && defined(__EPSK_TX__))
                  0xAA,   /* BYTE 13: Evelyn 20090422: set 8PSK power class in NVRAM
                            * bit8~7 : 8psk radio cap 2 = E2 *
                            * bit6~5 : 8psk radio cap 1 = E2 *
                            * bit4~3 : 8psk 850 Band    = E2 *
                            * bit2~1 : 8psk 1900 Band   = E2 */
#else /* __EGPRS_MODE__ */
                  0x00,   /* No 8PSK power class */
#endif /* __EGPRS_MODE__ */

/* Modify for High multislot class */
#if defined (__MULTISLOT_CLASS_34__) || defined (__MULTISLOT_CLASS_45__)
#if defined(__EPSK_TX__) && !defined(__EPSK_TX_SW_SWITCH_OFF__)
                  0xEc    /* BYTE 14: Evelyn 20090905: set high multislot class
                           *  bit 8   : EPSK_TX
                           *  bit 7   : high multislot class present or not
                           *  bit 6~1 : binany coding for high multislot value
                           *  For example, high multislot class 44 = 0x6c
                           */
#else
                  0x6c    /* BYTE 14: Evelyn 20090905: set high multislot class
                           *  bit 8   : EPSK_TX
                           *  bit 7   : high multislot class present or not
                           *  bit 6~1 : binany coding for high multislot value
                           *  For example, high multislot class 44 = 0x6c
                           */
#endif
#else
#if defined(__EPSK_TX__) && !defined(__EPSK_TX_SW_SWITCH_OFF__)
                  0x80   /* BYTE 14: Evelyn 20090905: set high multislot class
                           *  bit 8   : EPSK_TX
                           */
#else
                  0x00   /* BYTE 14: Evelyn 20090905: set high multislot class
                           *  bit 8   : EPSK_TX
                           */
#endif
#endif

/* Bit8+Bit7(10 for VAMOS2, 01 for VAMOS1, 00 for no support VAMOS */
/* Other bits are resevered */
#if defined(__VAMOS_2__) && defined(__CUSTOMIZE_VAMOS__)
                    ,0x80
#elif defined(__VAMOS_1__) && defined(__CUSTOMIZE_VAMOS__)
                    ,0x40
#else
                    ,0x00
#endif

/* Peter, 20080804: Modify the order of classmark3 info */
#if 0
#if defined(__REL4__) || defined(__REL5__) || defined(__SAIC__) || defined(__REPEATED_ACCH__)
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
   #if defined(__REL4__) || defined(__REL5__)
/* under construction !*/
   #else
/* under construction !*/
   #endif  /* defined(__REL4__) || defined(__REL5__) */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #ifdef __SAIC__
/* under construction !*/
   #else
/* under construction !*/
   #endif /* __SAIC__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #ifdef __REPEATED_ACCH__
/* under construction !*/
   #else
/* under construction !*/
   #endif /* __REPEATED_ACCH__ */
/* under construction !*/
#endif /* defined(__REL4__) || defined(__REL5__) || defined(__SAIC__) || defined(__REPEATED_ACCH__) */
/* under construction !*/
#endif
};

#ifdef __UMTS_RAT__

#ifdef __UMTS_FDD_MODE__
static kal_uint8 const NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_DEFAULT[] =
{
    // R99 CAP #29
    /* PDCP part */
#if defined(__RFC2507_SUPPORT__) && defined(__CUSTOMIZE_RFC2507_SUPPORT__)
    0x02, /* PDCP_supportForRfc2507: supported */
#else
    0x01, /* PDCP_supportForRfc2507: not supported */
#endif

#ifndef __UMTS_R5__
    0x00, /* MAX_HeaderCompressionLengthContext: 512 */
#else
    0x01, /* MAX_HeaderCompressionLengthContext: 1024 */
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    /* RLC part */
#ifdef __UMTS_R8__
    0x06, /* RRC_TotalRLC_AM_BufferSize: RRC_kb1000 */
#elif defined(__UMTS_R5__)
    0x05, /* RRC_TotalRLC_AM_BufferSize: RRC_kb500 */
#else
    0x04, /* RRC_TotalRLC_AM_BufferSize: RRC_kb150. */
#endif

    0x00, /* RRC_MaximumRLC_WindowSize: RRC_mws2047 */
    0x04, /* RRC_MaximumAM_EntityNumberRLC_Cap: RRC_am8 */

    /* UL TRCH part */
    0x01, /* ul_TransChCapability.modeSpecificInfo.selection: RRC_UL_TransChCapability_modeSpecificInfo_fdd_selected */
    0x08, /* ul_TransChCapability.maxNoBitsTransmitted: RRC_b10240 */
    0x00, /* ul_TransChCapability.maxConvCodeBitsTransmitted: RRC_b640 */
    0x02, /* ul_TransChCapability.turboEncodingSupport.selection: RRC_TurboSupport_supported_selected */
    0x08, /* ul_TransChCapability.turboEncodingSupport.choice.supported: RRC_b10240 */
    0x02, /* ul_TransChCapability.maxSimultaneousTransChs: RRC_MaxSimultaneousTransChsUL_e8 */
    0x03, /* ul_TransChCapability.maxTransmittedBlocks: RRC_MaxTransportBlocksUL_tb16 */
    0x05, /* ul_TransChCapability.maxNumberOfTFC: RRC_MaxNumberOfTFC_UL_tfc64 */
    0x00, /* ul_TransChCapability.maxNumberOfTF: RRC_tf32 */
    0x01, /* tdd.maxSimultaneousCCTrCH_Count: 1(TDD_R4 only), not used in FDD */
    /* DL TRCH part */
    0x08, /* maxNoBitsReceived: RRC_b10240 */
    0x01, /* maxConvCodeBitsReceived: RRC_b1280 */
    0x02, /* turboDecodingSupport: RRC_TurboSupport_supported_selected */
    0x08, /* turboDecodingSupport.choice.supported: RRC_b10240 */
    0x01, /* maxSimultaneousTransChs: RRC_MaxSimultaneousTransChsDL_e8 */
    0x01, /* maxSimultaneousCCTrCH_Count: DL_TCH_MAXSIMCCTRCH_COUNT */
    0x03, /* maxReceivedTransportBlocks: RRC_MaxTransportBlocksDL_tb32 */
    0x05, /* maxNumberOfTFC: RRC_MaxNumberOfTFC_DL_tfc128 */
    0x01, /* maxNumberOfTF: RRC_tf64 */

    /* Capability for CSCE use (WCDMA prefered, not part of UE capability which report to Network) */
#ifdef __WCDMA_PREFERRED__
    0x28+ /* 2G RSSI penalty: default value is 40 */
#endif /* __WCDMA_PREFERRED__ */
    0x00,

    /* RF Frequency Capability Info */
    0x00, /* reserved, original is for RF band */
    0x02, /* power class for all frequency bands: 00: Power Class 1, 01: Power Class 2, 02: Power Class 3, 03: Power Class 4 */
    0xAA, /* reserved, original is for Power Class bitmask */
    0xAA, /* reserved, original is for Power Class bitmask */

    /* R99 CAP Additional part #5 */
    /* 20101020 Chi-Chung: According to PDCP request, turn off LSR on FDD R5R6 and MAUI branches */
    0x00, /* losslessSRNS_RelocationSupport: 0 not supported, 1 supported */

    0x00, /* cipheringAlgorithmCap.stringData[0] */
#if defined(__UMTS_R7__) && !defined(__UE_SIMULATOR__) && defined(__CUSTOMIZE_UEA2_UIA2_SUPPORT__)
    0x07, /* cipheringAlgorithmCap.stringData[1]: UEA2|UEA1|UEA0 */
#else
    0x03, /* cipheringAlgorithmCap.stringData[1]: UEA1|UEA0*/
#endif

    0x00, /* integrityProtectionAlgorithmCap.stringData[0] */
#if defined(__UMTS_R7__) && !defined(__UE_SIMULATOR__) && defined(__CUSTOMIZE_UEA2_UIA2_SUPPORT__)
    0x06  /* integrityProtectionAlgorithmCap.stringData[1]: UIA2|UIA1 */
#else
    0x02  /* integrityProtectionAlgorithmCap.stringData[1]: UIA1 */
#endif

    , /* Capability for RRCE use (not part of UE capability which report to Network) */
      /* bit 8~5: not used */
#if defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__)
    0x0a+
#endif /* defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__) */
#if 0  /* 6589: default setting changes to not send SCRI in PCH state for power saving optimization, also to meet some operators requirement. */
#ifdef __FAST_DORMANCY__
/* under construction !*/
#endif /* __FAST_DORMANCY__ */
#endif
    0x00

    , /* Capability for RRCE use (not part of UE capability which report to Network) */
      /* bit 8~3: not used 
       * bit 2: Turn on advanced power saving method in idle & PCH states Level 2
       * bit 1: Turn on advanced power saving method in idle & PCH states */
#ifdef __SMART_PAGING_3G_FDD__
#ifdef __SMART_PAGING_3G_FDD_OFF__
    0x00+
#else
    0x01+
#endif /* __SMART_PAGING_3G_FDD_OFF__ */
#endif /* __SMART_PAGING_3G_FDD__ */
    0x00

   ,  /* Capability for RRCE use (not part of UE capability which report to Network) */
      /* bit 8~7: not used 
       * bit 1: bypass integrity checking(ip checking always pass). 
       * e.g. 0x01: UE will bypass integrity checking for every DL msg.
       *      0x00: UE will handle integrity checking as usual. */
   0x0

    /* Access Stratum Release Indicator */
   ,
#if defined(__UMTS_R8__)
   0x04 /* RRC_AccessStratumReleaseIndicator_rel_8 */
#elif defined(__UMTS_R7__)
   0x03 /* RRC_AccessStratumReleaseIndicator_rel_7 */
#elif defined(__UMTS_R6__)
   0x02 /* RRC_AccessStratumReleaseIndicator_rel_6 */
#elif defined(__UMTS_R5__)
   0x01 /* RRC_AccessStratumReleaseIndicator_rel_5 */
#elif defined(__UMTS_R4__)
   0x00 /* RRC_AccessStratumReleaseIndicator_rel_4 */
#else
   0x00
#endif

    /* PHYCH part */
   ,0x03, /* DL PhyChCap -  dlPhyCh_maxNoDPCH_PDSCH_Codes: 3 */


                          /* r3_cap1: USIME_R3_Cap1
                            * bit 8~5: maxNoDPDCH_BitsTransmitted
                            * bit 4~0: maxNoPhysChBitsReceived */

   0x40+ /* UL PhyChCap - maxNoDPDCH_BitsTransmitted: RRC_MaxNoDPDCH_BitsTransmitted_b9600 */
   0x08, /* DL PhyChCap - maxNoPhysChBitsReceived: RRC_MaxNoPhysChBitsReceived_b19200 */


                          /* r3_cap2: USIME_R3_Cap2
                            * bit 8~7: not used
                            * bit 6: sfn_sfnType2Capability
                            * bit 5~4: multiModeCapability
                            * bit 3: supportOfMulticarrier
                            * bit 2: supportOfGSM
                            * bit 1: supportForSF_512 */
   0x00+ /* sfn_sfnType2Capability: 0x20 supported, 0x00 not supported */

#if defined(__UMTS_FDD_MODE__) && defined(__UMTS_TDD128_MODE__)
   0x10+ /* RRC_MultiModeCapability_fdd_tdd */
#elif defined(__UMTS_FDD_MODE__)
   0x08+ /* RRC_MultiModeCapability_fdd */
#elif defined(__UMTS_TDD128_MODE__)
   0x00+ /* RRC_MultiModeCapability_tdd */
#endif

   0x00+ /* supportOfMulticarrier: 0x04 supported, 0x00 not supported */
#if defined (__GSM_RAT__)
   0x02+ /* supportOfGSM: 0x02 supported, 0x00 not supported */
#endif
   0x00, /* USIME_supportForSF_512: 0x01 supported, 0x00 not supported */

                          /* r3_cap3: USIME_R3_Cap3
                            * bit 8: validity_CellPCH_UraPCH
                            * bit 7: rx_tx_TimeDifferenceType2Capable
                            * bit 6: supportForIPDL
                            * bit 5: supportForUE_GPS_TimingOfCellFrames
                            * bit 4~3: networkAssistedGPS_Supported
                            * bit 2: ue_BasedOTDOA_Supported
                            * bit 1: standaloneLocMethodsSupported */
#ifdef __UAGPS_CP_SUPPORT__
   0x80+ /* validity_CellPCH_UraPCH: 0x80: supported, 0x00 not supported */
#endif

   0x00+ /* rx_tx_TimeDifferenceType2Capable: 0x40: supported, 0x00 not supported */
   0x00+ /* supportForIPDL: 0x20: supported, 0x00 not supported */

#if defined(__UAGPS_CP_SUPPORT__) && defined(__L1_GPS_REF_TIME_SUPPORT__)
   0x00+ /* supportForUE_GPS_TimingOfCellFrames: 0x10: supported, 0x00 not supported */
#endif

#ifdef __UAGPS_CP_SUPPORT__
   0x08+ /* networkAssistedGPS_Supported: RRC_NetworkAssistedGPS_Supported_bothNetworkAndUE_Based */
#else
   0x0C+ /* networkAssistedGPS_Supported: RRC_NetworkAssistedGPS_Supported_noNetworkAssistedGPS */
#endif

   0x00+ /* ue_BasedOTDOA_Supported: 0x02: supported, 0x00 not supported */

#ifdef __UAGPS_CP_SUPPORT__
   0x01+ /* standaloneLocMethodsSupported: 0x01: supported, 0x00 not supported */
#endif
   0x00

    /* R4 CAP */
#if defined(__UMTS_R4__) || defined(__UMTS_R5__)
    ,   // >#I
                           /* r4_cap1: USIME_R4_Cap1
                            * bit 8~6: not used
                            * bit 4: USIME_supportForRfc3095
                            * bit 3~0: maxROHC_ContextSessions */
    0x00+ /* USIME_supportForRfc3095: 0x10 support, 0x00 not support */
    0x00, /* maxROHC_ContextSessions: RRC_MaxROHC_ContextSessions_r4_s2 */

    0x00, /* reverseCompressionDepth_high_byte */
    0x00 /* reverseCompressionDepth_low_byte */
#endif /* defined(__UMTS_R4__) || defined(__UMTS_R5__) */

    /* R5 CAP */
#ifdef __UMTS_R5__
    ,   // >#I
                           /* r5_cap1: USIME_R5_Cap1
                            * bit 8: not used
                            * bit 7: hsdpa_category_change_for_test
                            * bit 6: supportForRfc3095ContextRelocation
                            * bit 5: supportOfUTRAN_ToGERAN_NACC
                            * bit 4: losslessDLRLCPDUSizeChange
                            * bit 2~3: dl_CapabilityWithSimultaneousHS_DSCHConfig 
                            * bit 1: dl_CapabilityWithSimultaneousHS_DSCHConfigValid */
#if defined(__UMTS_FDD_MODE__) && defined(__HSDPA_SUPPORT__)
    0x00+ /* hsdpa_category_change_for_test: 0x40 HSDPA category has been changed by tst inject or NVRAM editor for test purpose, 0x00 HSDPA category not been modified for test purpose */
#endif    
    0x00+ /* supportForRfc3095ContextRelocation: 0x20 supported, 0x00 not supported */
    0x10+ /* supportOfUTRAN_ToGERAN_NACC: 0x10 supported, 0x00 not supported */
    0x00+ /* losslessDLRLCPDUSizeChange: 0x08 supported, 0x00 not supported */
    0x02+ /* dl_CapabilityWithSimultaneousHS_DSCHConfig: 0x00 kbps32, 0x02 kbps64, 0x04 kbps128, 0x06 kbps384*/
    0x01,  /* fddPhysicalChannelCapab_hspdsch_edch: 0x01 valid, 0x00 not valid */

#ifdef FDD_HSDSCH_CATEGORY
    FDD_HSDSCH_CATEGORY, /* fdd_hsdpa_category */
#else
    0x00,
#endif

#ifdef TDD_HSDSCH_CATEGORY
    TDD_HSDSCH_CATEGORY /* tdd128_hsdpa_category */
#else
    0x00
#endif
#endif /* __UMTS_R5__ */

    /* R6 CAP */
#ifdef __UMTS_R6__
    ,   // >#I
                          /* r6_cap1: USIME_R6_Cap1
                            * bit 8~6: not used
                            * bit 5: hsupa_category_change_for_test
                            * bit 4: supportOfCSHandoverToGAN
                            * bit 3: doesNotBenifitFromBatteryConsumptionOptimization
                            * bit 2: supportForFDPCH 
                            * bit 1: supportForSIB11bis */
#if defined(__UMTS_FDD_MODE__) && defined(__HSUPA_SUPPORT__)
    0x00+ /* hsupa_category_change_for_test: 0x10 HSUPA category has been changed by tst inject or NVRAM editor for test purpose, 0x00 HSUPA category not been modified for test purpose */
#endif
    0x00+ /* supportOfCSHandoverToGAN: 0x08 support, 0x00 not support */
#ifdef __NOT_BENEFIT_FROM_BATTERY_CONSUMPTION_OPTIMISATION__
    0x04+ /* doesNotBenifitFromBatteryConsumptionOptimization: 0x04 does not benefit, 0x00 benefit */
#endif    
    0x02+ /* supportForFDPCH: 0x02 supported, 0x00 not supported */
    0x01,  /* supportForSIB11bis: 0x01 supported, 0x00 not supported */

#ifdef FDD_EDCH_CATEGORY
    FDD_EDCH_CATEGORY /* fdd_edch_category */
#else
    0x00
#endif

#endif /* __UMTS_R6__ */

    /* R7 CAP */
#ifdef __UMTS_R7__
    ,   // >#I
                          /* r7_cap1: USIME_R7_Cap1
                            * bit 8: discontinuousDpcchTransmission
                            * bit 7: hsdschReceptionCellUraPch
                            * bit 6: hsdschReceptionCellFach
                            * bit 5: enhancedFdpch
                            * bit 4: hsscchlessHsdschOperation
                            * bit 3: mac_ehsSupport
                            * bit 2: supportOfTwoLogicalChannel
                            * bit 1: supportForCSVoiceoverHSPA */
#if defined(__ENHANCED_COMMON_STATE_SUPPORT__) && defined(__CUSTOMIZE_ENHANCED_COMMON_STATE_SUPPORT__)
    0x40+ /* hsdschReceptionCellUraPch: 0x40 supported, 0x00 not supported */
    0x20+ /* hsdschReceptionCellFach: 0x20 supported, 0x00 not supported*/
#endif

    0x10+ /* enhancedFdpch: 0x10 supported, 0x00 not supported */

#ifdef __CPC_SUPPORT__
    0x80+ /* discontinuousDpcchTransmission: 0x80 supported, 0x00 not supported */
#endif

#if defined(__CPC_SUPPORT__) && defined(__CUSTOMIZE_HSSCCH_LESS_SUPPORT__)
    0x08+ /* hsscchlessHsdschOperation: 0x08 supported, 0x00 not supported */
#endif

#ifdef __MAC_EHS_SUPPORT__
    0x04+ /* mac_ehsSupport: 0x04 supported, 0x00 not supported */
#endif

    0x00+ /* supportOfTwoLogicalChannel: 0x02 supported, 0x00 not supported */

#if defined(__CSHSPA_SUPPORT__) && defined(__CUSTOMIZE_CSHSPA_SUPPORT__)
    0x01+  /* pdcp_supportForCSVoiceoverHSPA: 0x01 supported, 0x00 not supported */
#endif

    0x00,

                          /* r7_cap2: USIME_R7_Cap2
                            * bit 8~7: not used
                            * bit 6: supportofPSHandoverToGAN
                            * bit 5: supportofTxDivOnNonMIMOChannel
                            * bit 4: supportEDPDCHPowerInterpolation
                            * bit 3: supportForTwoDRXSchemesInPCH
                            * bit 2: supportForEDPCCHPowerBoosting
                            * bit 1: slotFormat4 */
    0x00+ /* supportofPSHandoverToGAN: 0x20 supported, 0x00 not supported */
    0x00+ /* supportofTxDivOnNonMIMOChannel: 0x10 supported, 0x00 not supported */
    0x00+ /* supportEDPDCHPowerInterpolation: 0x08 supported, 0x00 not supported */
    0x04+ /* supportForTwoDRXSchemesInPCH: 0x04 supported, 0x00 not supported */
    0x02+ /* supportForEDPCCHPowerBoosting: 0x02 supported, 0x00 not supported */
    0x01   /* slotFormat4: 0x01 supported, 0x00 not supported */
#endif /* __UMTS_R7__ */

    /* R8 CAP */
#ifdef __UMTS_R8__
    ,   // >#I
    0x0e, /* fdd_hsdpa_category_2: 14 , 
           * This value is only used when FDD_HSDSCH_CATEGORY > 20 (dual cell) */

                          /* r8_cap1: USIME_R8_Cap1
                            * bit 5~8: eutraFeatureGroupIndicators
                            * bit 4: supportOfInterRATHOToEUTRAFDD
                            * bit 3: supportOfEUTRAFDD
                            * bit 2: supportOfHsdschDrxOperation
                            * bit 1: supportOfTargetCellPreConfig */

#ifdef __LTE_RAT__
    0xC0+ /* eutraFeatureGroupIndicators: 0xC0 fully supported, 0x00 not supported */
    0x08+ /* supportOfInterRATHOToEUTRAFDD: 0x08 supported, 0x00 not supported */
    0x04+ /* supportOfEUTRAFDD: 0x04 supported, 0x00 not supported */
#endif

#if defined(__HSDSCH_DRX_CELL_FACH_SUPPORT__) && defined(__CUSTOMIZE_HSDSCH_DRX_CELL_FACH_SUPPORT__)
    0x02+ /* supportOfHsdschDrxOperation: 0x02 supported, 0x00 not supported */
#endif

#if defined(__HSDSCH_CELL_CHANGE_ENHANCE_SUPPORT__) && defined(__CUSTOMIZE_HSDSCH_CELL_CHANGE_ENHANCE_SUPPORT__)
    0x01+ /* supportOfTargetCellPreConfig: 0x01 supported, 0x00 not supported */
#endif

    0x00,

                          /* r8_cap2: USIME_R8_Cap2
                            * bit 8: supportOfInterRATHOToEUTRATDD
                            * bit 7: supportOfEUTRATDD
                            * bit 6: supportCellSpecificTxDiversityinDC_Operation
                            * bit 5: supportForPriorityReselectionInUTRAN
                            * bit 4: supportOfCSG
                            * bit 3: supportOfMACiis
                            * bit 2: supportOfCommonEDCH
                            * bit 1: adjacentFrequencyMeasurements */
#ifdef __LTE_RAT__
    0x00+ /* supportOfInterRATHOToEUTRATDD: 0x80 supported, 0x00 not supported */
    0x00+ /* supportOfEUTRATDD: 0x40 supported, 0x00 not supported */
#endif

#ifdef __DCHSDPA_ADJ_FREQ_SUPPORT__
    0x20+ /* supportCellSpecificTxDiversityinDC_Operation: 0x20 supported, 0x00 not supported */
#endif

#ifdef __PRI_RESEL_SUPPORT__
    0x10+ /* supportForPriorityReselectionInUTRAN: 0x10 supported, 0x00 not supported */
#endif

#ifdef __CSG_SUPPORT__
    0x08+ /* supportOfCSG: 0x08 supported, 0x00 not supported */
#endif

#if defined(__MAC_IIS_SUPPORT__) && defined(__CUSTOMIZE_MAC_IIS_SUPPORT__)
    0x04+ /* supportOfMACiis: 0x04 supported, 0x00 not supported */
#endif

#if defined(__COMMON_EDCH_SUPPORT__) && defined(__CUSTOMIZE_COMMON_EDCH_SUPPORT__)
    0x02+ /* supportOfCommonEDCH: 0x02 supported, 0x00 not supported */
#endif

#ifdef __DCHSDPA_ADJ_FREQ_SUPPORT__
    0x01+  /* adjacentFrequencyMeasurements: 0x01 supported, 0x00 not supported */
#endif

    0x00
#endif /* __UMTS_R8__ */
};

/* The default data was encoded result of SCSI's ScsiFrequencyInfoRepository which saves the 110 plmns' 3 uarfcn. */
static kal_uint8 const NVRAM_EF_UMTS_FREQUENCY_REPOSITORY_DEFAULT[] =
{0XA1, 0X02
, 0X06, 0X00, 0X00, 0X03, 0X0F, 0XA9, 0X44, 0XA5, 0X76, 0X04
, 0X0C, 0X00, 0X00, 0X0C, 0X1F, 0X54, 0X47, 0X52, 0XA4, 0X08
, 0X18, 0X00, 0X00, 0X04, 0X3E, 0XA7, 0XC6, 0XA0, 0XA8, 0X10
, 0X30, 0X00, 0X00, 0X10, 0X7D, 0X4D, 0XC5, 0X32, 0XF0, 0X20
, 0X00, 0X80, 0X00, 0X10, 0XFA, 0XA2, 0X2A, 0X8E, 0XE0, 0X40
, 0X01, 0X00, 0X20, 0X01, 0XF5, 0X28, 0X94, 0XAE, 0XC0, 0X80
, 0X02, 0X00, 0X80, 0X03, 0XDA, 0X63, 0XE0, 0X40, 0X60, 0X80
, 0X60, 0X01, 0XED, 0X41, 0X30, 0X20, 0X30, 0X40, 0X30, 0X30
, 0XFA, 0XA5, 0X4A, 0X8E, 0XE0, 0X40, 0X60, 0X80, 0X20, 0XA1
, 0XFD, 0X3B, 0X14, 0XF8, 0X53, 0X7F, 0X02, 0X03, 0X04, 0X01
, 0X00, 0X0F, 0XA9, 0X8D, 0XA6, 0X96, 0X04, 0X06, 0X08, 0X04
, 0X00, 0X1F, 0XD2, 0X89, 0X4B, 0XA5, 0X2B, 0X90, 0X40, 0X50
, 0X40, 0X10, 0X90, 0XFE, 0X95, 0XDA, 0X51, 0X29, 0X76, 0X82
, 0X02, 0X82, 0X00, 0X03, 0X07, 0XD4, 0XF8, 0XD3, 0XB3, 0X04
, 0X05, 0X04, 0X00, 0X03, 0X0F, 0XEA, 0X24, 0XA8, 0XF2, 0XA5
, 0X48, 0X20, 0X28, 0X20, 0X00, 0X00, 0X7F, 0X4D, 0X3D, 0X31
, 0XD4, 0XDF, 0XC1, 0X01, 0X81, 0X80, 0X00, 0X43, 0XDA, 0X50
, 0XE0, 0X80, 0XC0, 0XC1, 0X01, 0X21, 0XF5, 0X31, 0XD4, 0XD3
, 0X41, 0X01, 0X81, 0X82, 0X40, 0X83, 0XEA, 0X82, 0XAA, 0X23
, 0X82, 0X03, 0X03, 0X04, 0X83, 0X87, 0XD4, 0XEC, 0XD3, 0XE5
, 0X02, 0X06, 0X02, 0X00, 0X01, 0X0F, 0X6A, 0X54, 0X81, 0X03
, 0X01, 0X00, 0X01, 0X07, 0XD4, 0XA2, 0X52, 0XB9, 0X02, 0X06
, 0X02, 0X00, 0X03, 0X0F, 0X69, 0XA7, 0X81, 0X03, 0X01, 0X00
, 0X03, 0X87, 0XB5, 0X11, 0X40, 0X80, 0X80, 0X80, 0X40, 0X03
, 0XDA, 0X95, 0XA0, 0X40, 0X40, 0X41, 0X21, 0X21, 0XF5, 0X41
, 0X75, 0X12, 0X40, 0X80, 0X80, 0X80, 0X00, 0X43, 0XDA, 0X63
, 0XA0, 0X40, 0X40, 0X41, 0X01, 0X01, 0XED, 0X38, 0X10, 0X50
, 0X10, 0X00, 0X00, 0X80, 0XF6, 0X97, 0X58, 0X28, 0X08, 0X00
, 0X08, 0X08, 0X7B, 0X4E, 0X04, 0X14, 0X04, 0X00, 0X00, 0X04
, 0X3D, 0XA7, 0X66, 0X0A, 0X02, 0X00, 0X10, 0X12, 0X1E, 0XD2
, 0X87, 0X05, 0X01, 0X00, 0X01, 0X00, 0X0F, 0X69, 0XA7, 0X82
, 0X80, 0X82, 0X80, 0X01, 0X07, 0XD4, 0XEC, 0XD3, 0X81, 0X05
, 0X01, 0X05, 0X00, 0X05, 0X0F, 0X69, 0X8E, 0X82, 0X80, 0X82
, 0X80, 0X01, 0X87, 0XF4, 0XA1, 0X22, 0X46, 0X88, 0X54, 0X08
, 0X14, 0X14, 0X00, 0X1C, 0X3E, 0XA6, 0X36, 0X94, 0X38, 0X10
, 0X28, 0X28, 0X00, 0X18, 0X7B, 0X4E, 0XCC, 0X18, 0X00, 0X08
, 0X00, 0X0C, 0X3E, 0XA5, 0X0A, 0X95, 0XB8, 0X30, 0X00, 0X10
, 0X00, 0X10, 0X7B, 0X4D, 0X34, 0X10, 0X14, 0X00, 0X00, 0X20
, 0X3D, 0XA9, 0X52, 0X08, 0X08, 0X00, 0X02, 0X00, 0X1F, 0X88
, 0X1B, 0X4E, 0X05, 0X3B, 0X10, 0X40, 0X40, 0X00, 0X20, 0X00
, 0XFE, 0XA0, 0XBA, 0X8F, 0X2A, 0X24, 0X83, 0X02, 0X82, 0X80
, 0X80, 0X07, 0XB4, 0XEC, 0X41, 0X81, 0X41, 0X40, 0X00, 0X43
, 0XEA, 0X57, 0X29, 0X42, 0X83, 0X81, 0X02, 0X00, 0X02, 0X87
, 0XA8, 0X9F, 0X41, 0XC0, 0X81, 0X00, 0X00, 0XC3, 0XDA, 0X50
, 0XE0, 0X60, 0X60, 0X80, 0X00, 0X41, 0XE8, 0X87, 0XF0, 0X40
, 0X00, 0X40, 0X30, 0X40, 0XF6, 0XA0, 0XA8, 0X20, 0X00, 0X20
, 0X28, 0X08, 0X7B, 0X4C, 0X6C, 0X0C, 0X04, 0X00, 0X10, 0X04
, 0X01, 0X45, 0X4E, 0X04, 0X00, 0X08, 0X00, 0X08, 0X1E, 0XD2
, 0XB9, 0X02, 0X00, 0X04, 0X00, 0X08, 0X0F, 0X69, 0XA5, 0X81
, 0X00, 0X02, 0X00, 0X83, 0X07, 0XB5, 0X2A, 0X40, 0X80, 0X42
, 0X40, 0X00, 0X43, 0XDA, 0X50, 0XA0, 0X40, 0X21, 0X20, 0X20
, 0X01, 0XED, 0X3E, 0X30, 0X20, 0X30, 0X80, 0X00, 0X10, 0XF6
, 0X9A, 0X68, 0X10, 0X18, 0X40, 0X00, 0X10, 0X7B, 0X51, 0XEC
, 0X08, 0X0C, 0X20, 0X00, 0X18, 0X3D, 0XA5, 0X6E, 0X04, 0X06
, 0X10, 0X04, 0X00, 0X1E, 0XD3, 0XE3, 0X02, 0X04, 0X04, 0X00
, 0X05, 0X0F, 0X69, 0X75, 0X81, 0X02, 0X02, 0X00, 0X81, 0X07
, 0XB4, 0XF9, 0X40, 0X81, 0X01, 0X02, 0X40, 0X43, 0XDA, 0X95
, 0X60, 0X40, 0X80, 0XC0, 0X00, 0X21, 0XED, 0X38, 0X10, 0X20
, 0X40, 0X60, 0X00, 0X20, 0XF6, 0X98, 0XD8, 0X10, 0X20, 0X30
, 0X00, 0X18, 0X7B, 0X50, 0X54, 0X08, 0X14, 0X00, 0X00, 0X04
, 0X3D, 0XA8, 0X2A, 0X04, 0X0A, 0X00, 0X00, 0X04, 0X1E, 0XD3
, 0X7F, 0X02, 0X05, 0X00, 0X09, 0X09, 0X0F, 0X6A, 0X54, 0X81
, 0X03, 0X04, 0X00, 0X00, 0X87, 0XD4, 0XAE, 0XD2, 0XED, 0X02
, 0X06, 0X08, 0X00, 0X03, 0X0F, 0X69, 0XC0, 0X81, 0X03, 0X04
, 0X00, 0X03, 0X07, 0XD5, 0X05, 0X54, 0X79, 0X02, 0X07, 0X02
, 0X00, 0X01, 0X0F, 0X69, 0XF1, 0X81, 0X03, 0X81, 0X00, 0X01
, 0X07, 0XB5, 0X2A, 0XC0, 0X81, 0XC0, 0X80, 0X01, 0X43, 0XEA
, 0X51, 0X29, 0X5D, 0X82, 0X01, 0X02, 0X80, 0X00, 0X87, 0XB4
, 0XDF, 0XC1, 0X00, 0X81, 0X40, 0X00, 0X83, 0XDA, 0X89, 0X20
, 0XA0, 0X00, 0XA0, 0X00, 0X41, 0XED, 0X3E, 0X30, 0X50, 0X00
, 0X50, 0X00, 0X60, 0XF6, 0X94, 0X38, 0X30, 0X18, 0X48, 0X00
, 0X10, 0X7D, 0X4A, 0X15, 0X2B, 0X60
};

//#ifdef __BAND_PRIORITY_SEARCH__
static kal_uint8 const NVRAM_EF_UMTS_BAND_PRIORITY_DEFAULT[] =
{
        /**
         * these bytes are used to set the priority of each band.
         * Total size: 22bytes (one byte for each band)
         * Value(Priority) range: 0x00(the highest) ~ 0xFF(the lowest)
         * Default value for each band: 0xFF
         *
         * Band    I    II    III   IV     V    VI    VII   VIII
         *      +-----------------------------------------------+
         * byte |  0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  | 
         *      +-----------------------------------------------+
         *
         * Band   IX     X    XI    XII  XIII   XIV   XV    XVI
         *      +-----------------------------------------------+
         * byte |  8  |  9  | 10  | 11  | 12  | 13  | 14  | 15  | 
         *      +-----------------------------------------------+
         *
         * Band  XVII  XVIII  XIX   XX    XXI  XXII
         *      +-----------------------------------+
         * byte | 16  | 17  | 18  | 19  | 20  | 21  |
         *      +-----------------------------------+
         */
  0xFF, /* Band I */
  0xFF, /* Band II */
  0xFF, /* Band III */
  0xFF, /* Band IV */
  0xFF, /* Band V */
  0xFF, /* Band VI */
  0xFF, /* Band VII */
  0xFF, /* Band VIII */
  0xFF, /* Band IX */
  0xFF, /* Band X */
  0xFF, /* Band XI */
  0xFF, /* Band XII */
  0xFF, /* Band XIII */
  0xFF, /* Band XIV */
  0xFF, /* Band XV */
  0xFF, /* Band XVI */
  0xFF, /* Band XVII */
  0xFF, /* Band XVIII */
  0xFF, /* Band XIX */
  0xFF, /* Band XX */
  0xFF, /* Band XXI */
  0xFF  /* Band XXII */
};
//#endif /* __BAND_PRIORITY_SEARCH__ */

#endif /* __UMTS_FDD_MODE__ */

#ifdef __UMTS_TDD128_MODE__
#ifdef __AST_TL1_TDD__
static kal_uint8 const NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_DEFAULT[] =
{
    /* PDCP part */
#ifdef __RFC2507_SUPPORT__
    0x02, /* PDCP_supportForRfc2507: supported */
#else
    0x01, /* PDCP_supportForRfc2507: not supported */
#endif /* __RFC2507_SUPPORT__ */

    0x01, /* MAX_HeaderCompressionLengthContext:  1024 */ 

    /* RLC part */
#ifdef __UMTS_R7__
        0x05, /* RRC_TotalRLC_AM_BufferSize: RRC_kb150. */
#else
        0x04, /* RRC_TotalRLC_AM_BufferSize: RRC_kb500 */
#endif

    //0x04, /* RRC_TotalRLC_AM_BufferSize: RRC_kb150(TDD_R4). For R5, remember to revise the later-release raw data in USIME
             //and keep buffer_size_R99 <= buffer_size_R5 */
    0x00, /* RRC_MaximumRLC_WindowSize: RRC_mws2047(TDD_R4) */
    //0x06, /* RRC_MaximumAM_EntityNumberRLC_Cap: RRC_am30(TDD_R4) */
#ifdef __UMTS_R7__
        0x04, /* RRC_MaximumAM_EntityNumberRLC_Cap: RRC_am30(TDD_R4) */
#else
        0x06, /* RRC_MaximumAM_EntityNumberRLC_Cap: RRC_am8(TDD_R4) */
#endif
    /* UL TRCH part */
    0x02, /* ul_TransChCapability.modeSpecificInfo.selection: RRC_UL_TransChCapability_modeSpecificInfo_tdd_selected */
    0x07, /* ul_TransChCapability.maxNoBitsTransmitted: RRC_b8960(TDD_R4) */
    0x00, /* ul_TransChCapability.maxConvCodeBitsTransmitted: RRC_b640(TDD_R4) */
    0x02, /* ul_TransChCapability.turboEncodingSupport.selection: RRC_TurboSupport_supported_selected */
    0x07, /* ul_TransChCapability.turboEncodingSupport.choice.supported: RRC_b8960 */
    0x02, /* ul_TransChCapability.maxSimultaneousTransChs: RRC_MaxSimultaneousTransChsUL_e8 */
    0x04, /* ul_TransChCapability.maxTransmittedBlocks: RRC_MaxTransportBlocksUL_tb32 */
    0x05, /* ul_TransChCapability.maxNumberOfTFC: RRC_MaxNumberOfTFC_UL_tfc64 */
    0x00, /* ul_TransChCapability.maxNumberOfTF: RRC_tf32 */
    0x01, /* transportChannelCapability.ul_TransChCapability.modeSpecificInfo.choice.tdd.maxSimultaneousCCTrCH_Count: 1(TDD_R4 only) */
    /* DL TRCH part */
    0x07, /* maxNoBitsReceived: RRC_b8960(TDD_R4) */
    0x00, /* maxConvCodeBitsReceived: RRC_b640(TDD_R4) */
    0x02, /* turboDecodingSupport: RRC_TurboSupport_supported_selected */
    0x07, /* turboDecodingSupport.choice.supported: RRC_b8960 */
    0x01, /* maxSimultaneousTransChs: RRC_MaxSimultaneousTransChsDL_e8 */
    0x01, /* maxSimultaneousCCTrCH_Count: DL_TCH_MAXSIMCCTRCH_COUNT */
    0x03, /* maxReceivedTransportBlocks: RRC_MaxTransportBlocksDL_tb32 */
#ifdef __AST1001__
    0x05, /* maxNumberOfTFC: RRC_MaxNumberOfTFC_DL_tfc128 */
#else /* __AST2001__ */
    0x04, /* maxNumberOfTFC: RRC_MaxNumberOfTFC_DL_tfc96 */
#endif

    0x01, /* maxNumberOfTF: RRC_tf64 */
    /* RF Frequency Capability Info */
    0x00, /* reserved, original is for RF band */
    0x00, /* reserve for future band use, currently this shall be set to 0 */
    0x01, /* 0: Power Class 1, 1: Power Class 2, 2: Power Class 3, 3: Power Class 4  */
    0x00, /* TDD_R4 sync with FDD, dummy byte */
    0x00, /* TDD_R4 sync with FDD, dummy byte */

    /* R99 CAP Additional part #5 */
    0x01, /* losslessSRNS_RelocationSupport: 1 supported */
    0x00, /* cipheringAlgorithmCap.stringData[0] */
#ifdef __UMTS_R7__
    //0x07, /* cipheringAlgorithmCap.stringData[1]: UEA2|UEA1|UEA0 */
    0x01,
#else
    0x01, /* cipheringAlgorithmCap.stringData[1]: UEA0*/
#endif

    0x00, /* integrityProtectionAlgorithmCap.stringData[0] */
#ifdef __UMTS_R7__
    //0x06  /* integrityProtectionAlgorithmCap.stringData[1]: UIA2|UIA1 */
    0x02
#else
    0x02  /* integrityProtectionAlgorithmCap.stringData[1]: UIA1 */
#endif

,   /* Capability for RRCE use (not part of UE capability which report to Network) */
#if defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__)
    0x02+
#endif /* defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__) */
#ifdef __FAST_DORMANCY__
    0x01+
#endif /* __FAST_DORMANCY__ */
    0x00
    , /* Capability for RRCE use (not part of UE capability which report to Network) */
                           /* bit 8~3: not used 
                                                 * bit 2: Turn on 3G Smart Paging Level 2 (RRCE listen paging each 2 DRX without learning)
                                                 * bit 1: Turn on 3G Smart Paging */
#ifdef __SMART_PAGING_3G_FDD__
#ifdef __SMART_PAGING_3G_FDD_OFF__ /* This compile option only defined in MT6280 chip, used to keep the code sync with MT6583 and further product (Smart paging not turn on in MT6280) */
    0x00+
#else
    0x01+
#endif /* __SMART_PAGING_3G_FDD_OFF__ */
#endif /* __SMART_PAGING_3G_FDD__ */
    0x00
    /* R5 CAP #3 */
#ifdef __UMTS_R5__
    ,   // >#I
                           /* r5_cap1: USIME_R5_Cap1
                            * bit 8~5: not used
                            * bit 4: losslessDLRLCPDUSizeChange
                            * bit 2~3: dl_CapabilityWithSimultaneousHS_DSCHConfig 
                            * bit 1: dl_CapabilityWithSimultaneousHS_DSCHConfigValid */
    0x08+ /* losslessDLRLCPDUSizeChange: 0x08 supported, 0x00 not supported */
    0x02+ /* dl_CapabilityWithSimultaneousHS_DSCHConfig: 0x00 kbps32, 0x02 kbps64, 0x04 kbps128, 0x06 kbps384*/
    0x01,  /* validity of dl_CapabilityWithSimultaneousHS_DSCHConfig: 0x01 valid, 0x00 not valid */

#ifdef FDD_HSDSCH_CATEGORY
    FDD_HSDSCH_CATEGORY, /* fdd_hsdpa_category */
#else
    0x00,
#endif

#ifdef TDD_HSDSCH_CATEGORY
    TDD_HSDSCH_CATEGORY /* tdd128_hsdpa_category */
#else
    0x00
#endif
#endif /* __UMTS_R5__ */

    /* R6 CAP #2 */
#ifdef __UMTS_R6__
    ,   // >#I
                          /* r6_cap1: USIME_R6_Cap1
                            * bit 8~3: not used
                            * bit 2: supportForFDPCH 
                            * bit 1: supportForSIB11bis */
    0x00+ /* supportForFDPCH: 0x02 supported, 0x00 not supported */
    //0x01,  /* supportForSIB11bis: 0x01 supported, 0x00 not supported */
    0x00,/*TDD not support but FDD support*/
#ifdef FDD_EDCH_CATEGORY
    FDD_EDCH_CATEGORY /* fdd_edch_category */
#else
    0x00
#endif

#endif /* __UMTS_R6__ */

    /* R7 CAP #2 */
#ifdef __UMTS_R7__
    ,   // >#I
                          /* r7_cap1: USIME_R7_Cap1
                            * bit 8: discontinuousDpcchTransmission
                            * bit 7: hsdschReceptionCellUraPch
                            * bit 6: hsdschReceptionCellFach
                            * bit 5: enhancedFdpch
                            * bit 4: hsscchlessHsdschOperation
                            * bit 3: mac_ehsSupport
                            * bit 2: supportOfTwoLogicalChannel
                            * bit 1: supportForCSVoiceoverHSPA */
#ifdef __ENHANCED_COMMON_STATE_SUPPORT__
    0x40+ /* hsdschReceptionCellUraPch: 0x40 supported, 0x00 not supported */
    0x20+ /* hsdschReceptionCellFach: 0x20 supported, 0x00 not supported*/
#endif

    0x00+ /* enhancedFdpch: 0x10 supported, 0x00 not supported */

#ifdef __CPC_SUPPORT__
    0x80+ /* discontinuousDpcchTransmission: 0x80 supported, 0x00 not supported */
    0x08+ /* hsscchlessHsdschOperation: 0x08 supported, 0x00 not supported */
#endif

#ifdef __MAC_EHS_SUPPORT__
    0x04+ /* mac_ehsSupport: 0x04 supported, 0x00 not supported */
#endif
    0x02+ /* supportOfTwoLogicalChannel: 0x02 supported, 0x00 not supported */
    0x00,  /* pdcp_supportForCSVoiceoverHSPA: 0x01 supported, 0x00 not supported */

                          /* r7_cap2: USIME_R7_Cap2
                            * bit 8~5: not used
                            * bit 4: supportEDPDCHPowerInterpolation
                            * bit 3: supportForTwoDRXSchemesInPCH
                            * bit 2: supportForEDPCCHPowerBoosting
                            * bit 1: slotFormat4 */
    0x00+ /* supportEDPDCHPowerInterpolation: 0x08 supported, 0x00 not supported */
    0x00+ /* supportForTwoDRXSchemesInPCH: 0x04 supported, 0x00 not supported */
    0x00+ /* supportForEDPCCHPowerBoosting: 0x02 supported, 0x00 not supported */
    0x00   /* slotFormat4: 0x01 supported, 0x00 not supported */
#endif /* __UMTS_R7__ */
};
#endif /* __AST_TL1_TDD__ */

/* The default data was encoded result of SCSI's ScsiFrequencyInfoRepository which saves the 15 plmns' 22 uarfcn. */
static kal_uint8 const NVRAM_EF_UMTS_FREQUENCY_REPOSITORY_DEFAULT[] =
{0X00, 0X00
, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00
, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00
};

#endif /* __UMTS_TDD128_MODE__ */

#endif /* __UMTS_RAT__ */


#ifdef  __BTMODULE_RFMD3500__
static kal_uint8 const NVRAM_EF_BTRADIO_RFMD3500_DEFAULT[] = {
/* BluetoothAddress                  ,  6 */ 0xAD,0x5A,0x00,0x00,0x00,0x00,
/* MinEncryptionSize                 ,  1 */ 0x01,
/* MaxEncryptionSize                 ,  1 */ 0x10,
/* HCITransportLayerParameters       ,  3 */ 0x02,0x00,0x00,
/* FixedPIN                          , 16 */ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                                             0x00,0x00,0x00,0x00,0x00,0x00,
/* FixedPINLength                    ,  1 */ 0x00,
/* SleepEnableMask					 ,	1 */ 0x01,
/* LowPowerClockParameter	   	  	 ,  8 */ 0x03,0x02,0x00,0x00,0x00,0x10,0x00,0x00,
/* PowerControlConfiguration         , 13 */ 0x07,0x07,0x07,0x02,0x00,0x01,0x02,0x03,0x04,0x05,
                                             0x06,0x07,0x07,
/* SleepControlParameters            , 12 */ 0x00,0x00,0x14,0x10,0x20,0x30,0x30,0x30,0x30,0x00,
                                             0x03,0x02,
/* DebugControl                      ,  4 */ 0x00,0x00,0x2C,0x01,
/* LCandRMOverrideEnable             ,  4 */ 0x10,0x00,0x00,0x00,
/* RadioRegisterOverride             ,  6 */ 0x01,0x00,0x00,0x00,0x0D,0x7F,
/* CodecConfiguration                ,  8 */ 0x20,0x00,0x10,0x1F,0x00,0x0F,0x0F,0x02,
/* CVSDGainVolumeSettings            ,  6 */ 0x02,0x00,0x00,0x00,0x0E,0x0E,
/* VoiceSettings                     ,  2 */ 0x60,0x00,
/* UserBaudRate                      ,  3 */ 0x11,0x00,0x17,
/* CoexistenceParameters             ,  4 */// 0x02,0xA4,0x0E,0x00,
/* LowPowerDriftRate                 ,  1 */ 0x2D,
/* MaxTxPowerLevel                   ,  1 */ 0x04,
/* AdaptiveFrequencyHoppingParameters, 29 */ 0x02,0x00,0x3C,0x00,0x3C,0x00,0x00,0x01,0x0A,0x05,
                                             0x13,0x4F,0x02,0x08,0x01,0x0C,0x01,0x00,0x00,0x00,
                                             0x40,0x00,0x00,0x00,0x40,0x00,0x00,0x0A,0x05,
/* BufferSize                        ,  4 */ 0x7C,0x00,0x7C,0x00,
/* GPIO Mapping                      , 16 */ 0xFF,0x01,0xFF,0x02,0x04,0x06,0xFF,0x00,0xFF,0x00,
                                             0xFF,0x00,0xFF,0x00,0xFF,0x00,
/* GPIO Polarity                     ,  4 */ 0x00,0x00,0x04,0x00
};
#endif /* __BTMODULE_RFMD3500__*/



#if defined(__GPS_SUPPORT__) && defined(__MNL_SUPPORT__)
static kal_uint8 const NVRAM_EF_MNL_SETTING_DATA_DEFAULT[] = {
/* Internal LNA Enable          ,  1  */ 0x00,
/* TCXO Frequency Drift         ,  1  */ 0x01,
/* SBAS Mode                    ,  1  */ 0x00,
/* Clock Type                   ,  1  */ 0x00,
/* Frequency Error for XTAL     ,  1  */ 0x00,
/* Frame Sync Enable            ,  1  */ 0x00,
/* Reserved                     ,  10 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
#endif /* __GPS_SUPPORT__ & __MNL_SUPPORT__ */

#if defined (__WIFI_BT_SINGLE_ANTENNA_SUPPORT__)
//#if defined(__BTMODULE_MT6276__)|| defined(__BTMODULE_MT6622__) || defined(__BTMODULE_MT6626__)
static kal_uint32 const NVRAM_EF_BWCS_SETTING_DATA_DEFAULT[] =
{
    /* Real Time RSSI Threshold : BT / WIFI1 / WIFI2 */
    73, 73, 73,
    /* Non Real Time RSSI Threshold : BT / WIFI1 / WIFI2 */
    73, 73, 73,
    /* Antenna path compensation */
    10,
    /* antenna path switch protection period, Unit is frames (4.615us) */
    2000,
    /* TX Flow control : medium time / period time */
    0x0E00, 0x01,
    /* BT RX Range : Low / High */
    0xC4, 0xE2,
    /* BT TX power : WIFI OFF / WIFI SCO / WIFI ACL */
    0x07, 0x07, 0x06,
    /* Reserved                     ,  5 */
    0x00, 0x00, 0x00, 0x00, 0x00
};
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
#endif	/* #if 0 */
#endif /* __WIFI_BT_SINGLE_ANTENNA_SUPPORT__ */

#ifdef __PS_SERVICE__
static kal_uint8 const NVRAM_EF_TCM_PDP_PROFILE_DEFAULT[] = {
                  0x00, 0x00, 0x21, 0x01,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

                  //0x10, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  //0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
                  //0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // req qos
                  PS_QOS_PROFILE_DEFAULT_REQ_LENGTH,
                  PS_QOS_PROFILE_DEFAULT_REQ_UNUSED_1,
                  PS_QOS_PROFILE_DEFAULT_REQ_DELAY_CLASS,
                  PS_QOS_PROFILE_DEFAULT_REQ_RELIABILITY_CLASS,
                  PS_QOS_PROFILE_DEFAULT_REQ_PEAK_THROUGHPUT,
                  PS_QOS_PROFILE_DEFAULT_REQ_UNUSED_2,
                  PS_QOS_PROFILE_DEFAULT_REQ_PRECEDENCE_CLASS,
                  PS_QOS_PROFILE_DEFAULT_REQ_UNUSED_3,
                  PS_QOS_PROFILE_DEFAULT_REQ_MEAN_THROUGHPUT,
                  PS_QOS_PROFILE_DEFAULT_REQ_TRAFFIC_CLASS,
                  PS_QOS_PROFILE_DEFAULT_REQ_DELIVERY_ORDER,
                  PS_QOS_PROFILE_DEFAULT_REQ_DELIVERY_OF_ERR_SDU,
                  PS_QOS_PROFILE_DEFAULT_REQ_MAX_SDU_SIZE,
                  PS_QOS_PROFILE_DEFAULT_REQ_MAX_BIT_RATE_UPLINK,
                  PS_QOS_PROFILE_DEFAULT_REQ_MAX_BIT_RATE_DOWNLINK,
                  PS_QOS_PROFILE_DEFAULT_REQ_RESIDUAL_BIT_ERROR_RATE,
                  PS_QOS_PROFILE_DEFAULT_REQ_SDU_ERROR_RATIO,
                  PS_QOS_PROFILE_DEFAULT_REQ_TRANSFER_DELAY,
                  PS_QOS_PROFILE_DEFAULT_REQ_TRAFFIC_HNDL_PRIORITY,
                  PS_QOS_PROFILE_DEFAULT_REQ_GUARANTEED_BIT_RATE_UPLINK,
                  PS_QOS_PROFILE_DEFAULT_REQ_GUARANTEED_BIT_RATE_DOWNLINK,
                  PS_QOS_PROFILE_DEFAULT_REQ_UNUSED_4,
                  PS_QOS_PROFILE_DEFAULT_REQ_SIGNALING_INDICATION,
                  PS_QOS_PROFILE_DEFAULT_REQ_SOURCE_STAT_DESCPTOR,
                  PS_QOS_PROFILE_DEFAULT_REQ_EXT_MAX_BIT_RATE_DONW_LINK,
                  PS_QOS_PROFILE_DEFAULT_REQ_EXT_GUARANTEED_BIT_RATE_DONW_LINK,
                  PS_QOS_PROFILE_DEFAULT_REQ_EXT_MAX_BIT_RATE_UP_LINK,
                  PS_QOS_PROFILE_DEFAULT_REQ_EXT_GUARANTEED_BIT_RATE_UP_LINK,

                  //0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  //0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  //0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // min qos
                  PS_QOS_PROFILE_DEFAULT_MIN_LENGTH,
                  PS_QOS_PROFILE_DEFAULT_MIN_UNUSED_1,
                  PS_QOS_PROFILE_DEFAULT_MIN_DELAY_CLASS,
                  PS_QOS_PROFILE_DEFAULT_MIN_RELIABILITY_CLASS,
                  PS_QOS_PROFILE_DEFAULT_MIN_PEAK_THROUGHPUT,
                  PS_QOS_PROFILE_DEFAULT_MIN_UNUSED_2,
                  PS_QOS_PROFILE_DEFAULT_MIN_PRECEDENCE_CLASS,
                  PS_QOS_PROFILE_DEFAULT_MIN_UNUSED_3,
                  PS_QOS_PROFILE_DEFAULT_MIN_MEAN_THROUGHPUT,
                  PS_QOS_PROFILE_DEFAULT_MIN_TRAFFIC_CLASS,
                  PS_QOS_PROFILE_DEFAULT_MIN_DELIVERY_ORDER,
                  PS_QOS_PROFILE_DEFAULT_MIN_DELIVERY_OF_ERR_SDU,
                  PS_QOS_PROFILE_DEFAULT_MIN_MAX_SDU_SIZE,
                  PS_QOS_PROFILE_DEFAULT_MIN_MAX_BIT_RATE_UPLINK,
                  PS_QOS_PROFILE_DEFAULT_MIN_MAX_BIT_RATE_DOWNLINK,
                  PS_QOS_PROFILE_DEFAULT_MIN_RESIDUAL_BIT_ERROR_RATE,
                  PS_QOS_PROFILE_DEFAULT_MIN_SDU_ERROR_RATIO,
                  PS_QOS_PROFILE_DEFAULT_MIN_TRANSFER_DELAY,
                  PS_QOS_PROFILE_DEFAULT_MIN_TRAFFIC_HNDL_PRIORITY,
                  PS_QOS_PROFILE_DEFAULT_MIN_GUARANTEED_BIT_RATE_UPLINK,
                  PS_QOS_PROFILE_DEFAULT_MIN_GUARANTEED_BIT_RATE_DOWNLINK,
                  PS_QOS_PROFILE_DEFAULT_MIN_UNUSED_4,
                  PS_QOS_PROFILE_DEFAULT_MIN_SIGNALING_INDICATION,
                  PS_QOS_PROFILE_DEFAULT_MIN_SOURCE_STAT_DESCPTOR,
                  PS_QOS_PROFILE_DEFAULT_MIN_EXT_MAX_BIT_RATE_DONW_LINK,
                  PS_QOS_PROFILE_DEFAULT_MIN_EXT_GUARANTEED_BIT_RATE_DONW_LINK,
                  PS_QOS_PROFILE_DEFAULT_MIN_EXT_MAX_BIT_RATE_UP_LINK,
                  PS_QOS_PROFILE_DEFAULT_MIN_EXT_GUARANTEED_BIT_RATE_UP_LINK,

                  0x08,

                  0x69, 0x6E, 0x74, 0x65, 0x72, 0x6E, 0x65, 0x74, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

                  0x02, 0x02, 0x00, 0x00, 0x01,
                  0xAC, 0x15, 0x78, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00,
                  0x00, 0x00,

                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00,

                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

                  0xDB, // 1101 1011, the 0 at 1101 is to disable the TCM_CGDCONT_IPV4_ALLOC_VIA_DHCP, and the 0 at 1011 is to disable TCM_CGQREQ_DEFINED
                  0x00, 0x00 // N201U value 1520=(0xF0, 0x05) //erica 20070112
};
#endif /* __PS_SERVICE__*/

#if !defined(__CUSTOMIZED_PORT_SETTING__)
static port_setting_struct const NVRAM_EF_PORT_SETTING_DEFAULT[]=
{
    {
    #if defined (WISDOM_MMI) || defined(NEPTUNE_MMI)
        uart_port1,   /* tst-ps uses uart_port1(value is 0) */
        uart_port2,   /* APP uses uart_port1 (value is 0) */
    #elif defined(__DUAL_TALK_MODEM_SUPPORT__)
        uart_port1,   /* tst-ps uses uart_port1 */
        uart_port2,   /* APP uses uart_port2 */
    #elif defined(__USB_MULTIPLE_COMPORT_SUPPORT__) && defined(__L4_INIT_MULTIUSB_COM__)
        uart_port1,   /* TST-PS */
        uart_port_usb3,   /* PS-ATCI */
    #elif defined(__MINI_LOG_SUPPORT__)
	    uart_port_mini_log,
	    uart_port1,
    #else
        uart_port_null,   /* tst-ps uses uart_port_null(value is 99) */
        uart_port1,   /* APP uses uart_port1 (value is 0) */
    #endif

    #if defined(EMPTY_MMI)
        921600, /* tst default baud rate for project without MMI */
    #elif defined (WISDOM_MMI)
/* under construction !*/
	#elif defined(__USB_MULTIPLE_COMPORT_SUPPORT__) && defined(__L4_INIT_MULTIUSB_COM__)
		921600, /* TST-PS baud uses 921600 */
    #else
        115200, /* tst default baud rate base = 115200 = 0x0001C200 */
    #endif

    #if defined (__PS_SERVICE__)
        115200, /* ps default baud rate base = 115200 = 0x0001C200 */
    #else
        57600, /* ps default baud rate base =   57600 = 0x0000E100 */
    #endif

        KAL_FALSE,                   /* High SpeedSIM */
        0,                           /* SWDBG */
    #if defined(__ONLY_ONE_UART__)
        1,                           /* uart power setting (0x03) */
    #else
        3,
    #endif

        uart_port_null,                          /* CTI uart port: uart_null (value is 0x63 (99) */
        0,                           /* CTI baud rate: auto*/

    #if defined (WISDOM_MMI) || defined(NEPTUNE_MMI)
        uart_port1,
    #elif defined(__DUAL_TALK_MODEM_SUPPORT__)
        uart_port1,
    #elif defined(__USB_MULTIPLE_COMPORT_SUPPORT__) && defined(__L4_INIT_MULTIUSB_COM__)
        uart_port1, /* TST-L1 */
    #elif defined(__MINI_LOG_SUPPORT__)
	    uart_port_mini_log,
    #else
        uart_port_null,                           /* tst-l1 uart port, same as tst-ps*/
    #endif

    #if defined(EMPTY_MMI)
        921600, /* tst default baud rate for project without MMI */
    #elif defined (WISDOM_MMI)
/* under construction !*/
    #elif defined(__USB_MULTIPLE_COMPORT_SUPPORT__) && defined(__L4_INIT_MULTIUSB_COM__)
		921600, /* TST-L1 baud uses 921600 */
    #else
        115200, /* tst default baud rate base = 115200 = 0x0001C200 */
    #endif

        0,                           /* tst output mode*/
#if !defined( __UL1_STANDALONE__ )
        0,                            /* USB logging mode */
#else
    #if defined(__MODEM_3G_LOGGING__) && defined(_DSPIRDBG__)
        2,
    #else
        1,
    #endif /* defined(__MODEM_3G_LOGGING__) && defined(_DSPIRDBG__) */
#endif /*  __UL1_STANDALONE__  */

        uart_port_null,  										//TST-DSP
        921600,									//TST-DSP baudrate

        0,       // USB CD-ROM config,  0:CD-ROM , 1: COM
        uart_port_usb4, // Speech port
        0       // NDIS port
    },
    {
        uart_port1,  /* tst-ps uses uart_port_null(value is 0) */
        uart_port_at_ccci,   /* APP uses uart_port_usb (value is 4) */

        921600, /* tst default baud rate for project without MMI */

    #if defined (__PS_SERVICE__)
        115200, /* ps default baud rate base = 115200 = 0x0001C200 */
    #else
        57600, /* ps default baud rate base =   57600 = 0x0000E100 */
    #endif

        KAL_FALSE,                   /* High SpeedSIM */
        0,                           /* SWDBG */
    #if defined(__ONLY_ONE_UART__)
        1,                           /* uart power setting (0x03) */
    #else
        3,
    #endif

        99,                          /* CTI uart port: uart_null (value is 0x63 (99) */
        0,                           /* CTI baud rate: auto*/

        uart_port1, /* tst-l1 uart port, same as tst-ps*/

        921600, /* tst default baud rate for project without MMI */

        0,                           /* tst output mode*/
#if !defined( __UL1_STANDALONE__ )
        0,                            /* USB logging mode */
#else
    #if defined(__MODEM_3G_LOGGING__) && defined(_DSPIRDBG__)
        2,
    #else
        1,
    #endif /* defined(__MODEM_3G_LOGGING__) && defined(_DSPIRDBG__) */
#endif /*  __UL1_STANDALONE__  */

        99,  										//TST-DSP
        921600,									//TST-DSP baudrate
        0,       // USB CD-ROM config,  0:CD-ROM , 1: COM
        uart_port_usb4, // Speech port
        0       // NDIS port
    },
};
#endif /* !defined(__CUSTOMIZED_PORT_SETTING__) */

#if !defined(__SMS_STORAGE_BY_MMI__) && (SMS_PHONE_ENTRY > 0)
static kal_uint8 const NVRAM_EF_SMSAL_SMS_DEFAULT[] = {
    0xfe,                            /* status */
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF
};
#endif

#ifndef __CB_CHANNEL_ONLY_STORED_IN_NVRAM__
/* Cell Broadcast Setting. */
/* The channels set will shown in MMI */
/* This setting may be changed by customer. DON'T remove it. */
static kal_uint8 const COMMON_NVRAM_EF_CB_CH_INFO_DEFAULT[] =
{
    0xFF, 0xFF, 0xFF, 0xFF, /* cbmir_mask, default all cbmir turn on */ 
    0xFF, 0xFF, 0xFF, 0xFF, /* cbmir_me_mask, default all cbmir turn on */
    0xFF, 0xFF, 0xFF, 0xFF, /* dcs_mask, default all dcs turn on */
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, /* dcs[0] ~ dcs[4] */
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, /* dcs[5] ~ dcs[9] */
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, /* dcs[10] ~ dcs[14] */
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, /* dcs[15] ~ dcs[19] */
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, /* dcs[20] ~ dcs[24] */
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, /* dcs[25] ~ dcs[29] */
    0xFF, 0xFF, 0xFF, /* cbmi_me_mask, default all ME cbmi turn on */ 
    0xFF, 0xFF, 0xFF, /* cbmi_sim_mask, default all SIM cbmi turn on */
#ifndef __CMAS__
    0xFF, 0xFF, /* CH 1 , for example:  chanel 50 is 0x00, 0x32 */
    0xFF, 0xFF, /* CH 2  */
    0xFF, 0xFF, /* CH 3  */
    0xFF, 0xFF, /* CH 4  */
    0xFF, 0xFF, /* CH 5  */
    0xFF, 0xFF, /* CH 6  */
    0xFF, 0xFF, /* CH 7  */
    0xFF, 0xFF, /* CH 8  */
    0xFF, 0xFF, /* CH 9  */
    0xFF, 0xFF, /* CH 10 */
    0xFF, 0xFF, /* CH 11 */
    0xFF, 0xFF, /* CH 12 */
    0xFF, 0xFF, /* CH 13 */
#else
    0x11, 0x12, /* CH 1 , for example:  chanel 50 is 0x00, 0x32 */
    0x11, 0x13, /* CH 2  */
    0x11, 0x14, /* CH 3  */
    0x11, 0x15, /* CH 4  */
    0x11, 0x16, /* CH 5  */
    0x11, 0x17, /* CH 6  */
    0x11, 0x18, /* CH 7  */
    0x11, 0x19, /* CH 8  */
    0x11, 0x1A, /* CH 9  */
    0x11, 0x1B, /* CH 10 */
    0x11, 0x1C, /* CH 11 */
    0x11, 0x1D, /* CH 12 */
    0x11, 0x1E, /* CH 13 */
#endif
    0xFF, 0xFF, /* CH 14 */
    0xFF, 0xFF, /* CH 15 */
    0xFF, 0xFF, /* CH 16 */
    0xFF, 0xFF, /* CH 17 */
    0xFF, 0xFF, /* CH 18 */
    0xFF, 0xFF, /* CH 19 */
    0xFF, 0xFF, /* CH 20 */
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 1*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 2*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 3*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 4*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 5*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 6*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 7*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 8*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 9*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 10*/
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 11*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 12*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 13*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 14*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 15*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 16*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 17*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 18*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 19*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 20*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 21*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 22*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 23*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 24*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 25*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 26*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 27*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 28*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 29*/ 
    0xFF, 0xFF, 0xFF, 0xFF  /*Range 30*/ 
};
#else
static kal_uint8 const COMMON_NVRAM_EF_CB_CH_INFO_DEFAULT[] =
{
    0xFF, 0xFF, 0xFF, 0xFF, /* cbmir_mask, default all cbmir turn on */ 
    0xFF, 0xFF, 0xFF, 0xFF, /* cbmir_me_mask, default all cbmir turn on */
    0xFF, 0xFF, 0xFF, 0xFF, /* dcs_mask, default all dcs turn on */
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, /* dcs[0] ~ dcs[4] */
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, /* dcs[5] ~ dcs[9] */
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, /* dcs[10] ~ dcs[14] */
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, /* dcs[15] ~ dcs[19] */
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, /* dcs[20] ~ dcs[24] */
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, /* dcs[25] ~ dcs[29] */
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF,/* cbmi_me_mask, default all ME cbmi turn on */ 
    0xFF, 0xFF, 0xFF, /* cbmi_sim_mask, default all SIM cbmi turn on */
#ifndef __CMAS__
    0xFF, 0xFF, /* CH 1 , for example:  chanel 50 is 0x00, 0x32 */
    0xFF, 0xFF, /* CH 2  */
    0xFF, 0xFF, /* CH 3  */
    0xFF, 0xFF, /* CH 4  */
    0xFF, 0xFF, /* CH 5  */
    0xFF, 0xFF, /* CH 6  */
    0xFF, 0xFF, /* CH 7  */
    0xFF, 0xFF, /* CH 8  */
    0xFF, 0xFF, /* CH 9  */
    0xFF, 0xFF, /* CH 10 */
    0xFF, 0xFF, /* CH 11 */
    0xFF, 0xFF, /* CH 12 */
    0xFF, 0xFF, /* CH 13 */
#else
    0x11, 0x12, /* CH 1 , for example:  chanel 50 is 0x00, 0x32 */
    0x11, 0x13, /* CH 2  */
    0x11, 0x14, /* CH 3  */
    0x11, 0x15, /* CH 4  */
    0x11, 0x16, /* CH 5  */
    0x11, 0x17, /* CH 6  */
    0x11, 0x18, /* CH 7  */
    0x11, 0x19, /* CH 8  */
    0x11, 0x1A, /* CH 9  */
    0x11, 0x1B, /* CH 10 */
    0x11, 0x1C, /* CH 11 */
    0x11, 0x1D, /* CH 12 */
    0x11, 0x1E, /* CH 13 */
#endif
    0xFF, 0xFF, /* CH 14 */
    0xFF, 0xFF, /* CH 15 */
    0xFF, 0xFF, /* CH 16 */
    0xFF, 0xFF, /* CH 17 */
    0xFF, 0xFF, /* CH 18 */
    0xFF, 0xFF, /* CH 19 */
    0xFF, 0xFF, /* CH 20 */
    0xFF, 0xFF, /* CH 21 */
    0xFF, 0xFF, /* CH 22 */
    0xFF, 0xFF, /* CH 23 */
    0xFF, 0xFF, /* CH 24 */
    0xFF, 0xFF, /* CH 25 */
    0xFF, 0xFF, /* CH 26 */
    0xFF, 0xFF, /* CH 27 */
    0xFF, 0xFF, /* CH 28 */
    0xFF, 0xFF, /* CH 29 */
    0xFF, 0xFF, /* CH 30 */
    0xFF, 0xFF, /* CH 31 */
    0xFF, 0xFF, /* CH 32 */
    0xFF, 0xFF, /* CH 33 */
    0xFF, 0xFF, /* CH 34 */
    0xFF, 0xFF, /* CH 35 */
    0xFF, 0xFF, /* CH 36 */
    0xFF, 0xFF, /* CH 37 */
    0xFF, 0xFF, /* CH 38 */
    0xFF, 0xFF, /* CH 39 */
    0xFF, 0xFF, /* CH 40 */
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 1*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 2*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 3*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 4*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 5*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 6*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 7*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 8*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 9*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 10*/
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 11*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 12*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 13*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 14*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 15*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 16*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 17*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 18*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 19*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 20*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 21*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 22*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 23*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 24*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 25*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 26*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 27*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 28*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 29*/ 
    0xFF, 0xFF, 0xFF, 0xFF  /*Range 30*/ 
};
#endif

/* UEM*/
static kal_uint8 const NVRAM_EF_UEM_MANUFACTURE_DATA_DEFAULT[] = {
                   'M',  'T',  'K',  '1', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
#ifdef __DM_MO_SUPPORT__
                   'M',  'T',  'K',  '3', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
#else
                   'M',  'T',  'K',  '2', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
#endif
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                   'M',  'T',  'K',  '3', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                   'M',  'T',  'K',  '4', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                   'M',  'T',  'K',  '5', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

                   'M',  'T',  'K',  '6', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                   'M',  'T',  'K',  '7', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                  };





static kal_uint8 const NVRAM_EF_PS_CONFORMANCE_TESTMODE_DEFAULT[] ={
    /* High 8 bit stores Test mode. Eg. CTA/FTA/IOT...   
         * And the value follow the rule like this:
         * 0x00  ==> Real NW
         * 0x01  ==> CTA
         * 0x02  ==> FTA
         * 0x03  ==> IOT
         * 0x04  ==> OPERATOR
         * ...
         */
    0x00,   
    /* Low 24 bit store the Special setting according to each MODE
         */
    0x00,0x00,0x00

};

/* default value for SBP feature
   refer to sbp_md_feature_enum for modem configurable features
*/
static nvram_ef_sbp_modem_config_struct NVRAM_EF_SBP_MODEM_CONFIG_DEFAULT[] = {
{
    0x00000000, //0: disable SBP
    /* below are bitmap for modem feature */
    {
    //byte 0
#if defined(__PERMANENT_AUTO_SEL_MODE__)
    0x01 |
#endif
#if defined(__3G_CB_OFF__)
    0x02 |
#endif
#if defined(__MM_TRY_ABNORMAL_LAI_ONCE_MORE__)
    0x04 |
#endif
#if defined(__MM_DISABLE_RETRY_ABNORMAL_LAI__)
    0x08 |
#endif
#if defined(__DISABLE_AUTO_RETURN_PRE_RPLMN__)
    0x10 |
#endif
#if defined(__MM_HPPLMN_1ST_ATTEMPT_ENHANCE__)
    0x20 |
#endif
#if defined(__OOS_EARLY_IND__)
    0x40 |
#endif
#if defined(__L2_RANDOM_FILL_BIT__)
    0x80 |
#endif
    0x00 ,

    //byte 1
#if defined(__U_CSP_SUPPORT__)
    0x01 |
#endif
#if defined(__SAT_NO_EVDL_IN_SESSION__)
    0x02 |
#endif
#if defined(__IMEI_LOCK_SUPPORT__)
    0x04 |
#endif
#if defined(__ENS__)
    0x08 |
#endif
#if defined(__DOCOMO_IOT_CC__)
    0x10 |
#endif
#if defined(__AT_ME_IDENTIFICATION_WITHOUT_HEADER__)
    0x20 |
#endif
#if defined(__STAR_SHORT_STRING_AS_CALL__)
    0x40 |
#endif
#if defined(__CUSTOMIZED_IDLE_STRING_AS_CALL__)
    0x80 |
#endif
    0x00 ,

    //byte 2
#if defined(__HPPLMN_REGARDLESS_ANY_MCC__)
    0x01 |
#endif
#if defined(__DISABLE_RPLMN_FROM_GLOCI__)
    0x02 |
#endif
#if defined(__ORANGE_H_PLUS__)
    0x04 |
#endif
#if defined(__ENS_RAT_BALANCING__)
    0x08 |
#endif
#if defined(__MM_INTERNATIONAL_HPPLMN_SEARCH__)
    0x10 |
#endif
#if defined(__ATNT_HPPLMN_SEARCH__)
    0x20 |
#endif
#if defined(__DISABLE_PLMNSEL_OPLMN_COEXIST__)
    0x40 |
#endif
#if defined(__DISABLE_DISPLAY_ROAMING_HPLMN_IN_EPLMN__)
    0x80 |
#endif
    0x00,

    //byte 3
#if defined(__TMO_ECC_NOTIFICATION_ENABLE__)
    0x01 |
#endif
#if defined(__RPLMN_HPLMN_COMBINED_SEARCH__)
    0x02 |
#endif
#if defined(__MM_SEARCH_HPLMN_BEFORE_RPLMN__)
    0x04 |
#endif
#if defined(__DISABLE_PLMN_SEL_WHEN_ACCESS_BARRED__)
    0x08 |
#endif
#if defined(__TMO_PLMN_MATCHING__)
    0x10 |
#endif
#if defined(__MM_NOT_TRY_ANOTHER_RAT_FOR_LU_ABNORMAL__)
    0x20 |
#endif
#if defined(__MM_PERFORM_PLMN_SEARCH_AFTER_LU_ABNORMAL__)
    0x40 |
#endif
#if defined(__MM_IGNORE_EQPLMN_IN_AUTO_MODE__)
    0x80 |
#endif
    0x00,

    //byte 4
#if defined(__USE_SM_QOS_SUBSCRIBED__)
    0x01 |
#endif
#if defined(__MM_IGNORE_EQPLMN_IN_MANUAL_MODE__)
    0x02 |
#endif
#if defined(__MM_IGNORE_YOIGO_EQPLMN__)
    0x04 |
#endif
#if defined(__MM_IGNORE_PLAY_EQPLMN__)
    0x08 |
#endif
#if defined(__MM_ILL_MS_ME_CAUSE_PS_INVALID_SIM__)
    0x10 |
#endif
#if defined(__NO_SUPPORT_A5_3__)
    0x20 |
#endif
#if defined (__MM_DISABLE_PREVIOUS_RPLMN_FROM_NVRAM__)
    0x40 |  
#endif
    0x00,

    // byte 5~9
    0x00,0x00,0x00,0x00,0x00}
}
};

/* default value for SBP feature data
   refer to sbp_md_feature_data_enum for modem configurable features
*/
static nvram_ef_sbp_modem_data_config_struct NVRAM_EF_SBP_MODEM_DATA_CONFIG_DEFAULT[] = {
{
    0x00000000, {
    //VAMOS
#if defined(__VAMOS_2__)
    0x02
#elif defined(__VAMOS_1__)
    0x01
#else
    0x00
#endif
    }
}
};

/**
 * Step 4:
 * The logical data item table.
 * Note:
 * Each logical data item must be:
 * 1> Size must be EVEN
 * 2> Size of default value must be equal to the logical data item's size.
 *
 * The last LID in the MT reign now is MT1k
 */
ltable_entry_struct logical_data_item_table_core[] =
{
    {
        NVRAM_EF_SYS_STATISTICS_LID,
        NVRAM_EF_SYS_STATISTICS_TOTAL,
        NVRAM_EF_SYS_STATISTICS_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT04",
        VER(NVRAM_EF_SYS_STATISTICS_LID)
    },
    

#if defined(__2G_RF_CUSTOM_TOOL_SUPPORT__)
    {
        NVRAM_EF_L1_2G_RF_PARAMETER_LID,
        NVRAM_EF_L1_2G_RF_PARAMETER_TOTAL,
        NVRAM_EF_L1_2G_RF_PARAMETER_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),//NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),//NVRAM_NORMAL_NOT_ZIP((void*)&RF_custom_input_data),//NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),//NVRAM_NORMAL_NOT_ZIP(RF_custom_input_data),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
   #if  defined(__UMTS_FDD_MODE__)
        "MT9W",
   #elif  defined(__UMTS_TDD128_MODE__)
        "MT0W",
   #else
        "MT0W", 
   #endif
        VER(NVRAM_EF_L1_2G_RF_PARAMETER_LID)
    },
#endif


    {
        NVRAM_EF_BAND_INFO_LID,
        NVRAM_EF_BAND_INFO_TOTAL,
        NVRAM_EF_BAND_INFO_SIZE,
        NVRAM_NORMAL(NVRAM_EF_BAND_INFO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIPLE,
        "MT0X",
        VER(NVRAM_EF_BAND_INFO_LID)
    },
    
    {
        NVRAM_EF_TST_FILTER_LID,
        NVRAM_EF_TST_FILTER_TOTAL,
        NVRAM_EF_TST_FILTER_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT0Y",
        VER(NVRAM_EF_TST_FILTER_LID)
    },

    {
        NVRAM_EF_PORT_SETTING_LID,
        NVRAM_EF_PORT_SETTING_TOTAL,
        NVRAM_EF_PORT_SETTING_SIZE,
    #if defined(__CUSTOMIZED_PORT_SETTING__) && !defined(NVRAM_AUTO_GEN)
        NVRAM_NORMAL(NVRAM_EF_CUSTOM_PORT_SETTING_DEFAULT),
    #else
        NVRAM_NORMAL(NVRAM_EF_PORT_SETTING_DEFAULT),
    #endif
        NVRAM_CATEGORY_USER,
        #if defined(MT6280) && defined(__MODEM_CCCI_EXIST__)
        NVRAM_ATTR_MULTI_DEFAULT |
        #endif
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
        "MT0Z",
        VER(NVRAM_EF_PORT_SETTING_LID)
    },

#if !defined(__SMS_STORAGE_BY_MMI__) && (SMS_PHONE_ENTRY > 0)
    {
        NVRAM_EF_SMSAL_SMS_LID,
        NVRAM_EF_SMSAL_SMS_TOTAL,
        NVRAM_EF_SMSAL_SMS_SIZE,
        NVRAM_NORMAL(NVRAM_EF_SMSAL_SMS_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIREC_READ,
        "MT40",
        VER(NVRAM_EF_SMSAL_SMS_LID)
    },
#endif

#if !defined(EXTERNAL_MMI)
    {
        NVRAM_EF_SMSAL_MAILBOX_ADDR_LID,
        NVRAM_EF_SMSAL_MAILBOX_ADDR_TOTAL,
        NVRAM_EF_SMSAL_MAILBOX_ADDR_SIZE,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_SMSAL_MAILBOX_ADDR_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
        NVRAM_ATTR_AVERAGE,
        "MT41",
        VER(NVRAM_EF_SMSAL_MAILBOX_ADDR_LID)
    },
#endif

    {
        NVRAM_EF_SMSAL_COMMON_PARAM_LID,
        NVRAM_EF_SMSAL_COMMON_PARAM_TOTAL,
        NVRAM_EF_SMSAL_COMMON_PARAM_SIZE,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_SMSAL_COMMON_PARAM_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
        NVRAM_ATTR_FACTORY_RESET,
        "MT42",
        VER(NVRAM_EF_SMSAL_COMMON_PARAM_LID)
    },

    {
        NVRAM_EF_SMSAL_SMSP_LID,
        NVRAM_EF_SMSAL_SMSP_TOTAL,
        NVRAM_EF_SMSAL_SMSP_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTIREC_READ,
        "MT43",
        VER(NVRAM_EF_SMSAL_SMSP_LID)
    },

    {
        NVRAM_EF_SMSAL_MWIS_LID,
        NVRAM_EF_SMSAL_MWIS_TOTAL,
        NVRAM_EF_SMSAL_MWIS_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT44",
        VER(NVRAM_EF_SMSAL_MWIS_LID)
    },

    {
        NVRAM_EF_CB_DEFAULT_CH_LID,
        NVRAM_EF_CB_DEFAULT_CH_TOTAL,
        NVRAM_EF_CB_DEFAULT_CH_SIZE,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_CB_DEFAULT_CH_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
        NVRAM_ATTR_FACTORY_RESET,
        "MT45",
        VER(NVRAM_EF_CB_DEFAULT_CH_LID)
    },

    {
        NVRAM_EF_CB_CH_INFO_LID,
        NVRAM_EF_CB_CH_INFO_TOTAL,
        NVRAM_EF_CB_CH_INFO_SIZE,
        NVRAM_NORMAL(COMMON_NVRAM_EF_CB_CH_INFO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_FACTORY_RESET,
        "MT46",
        VER(NVRAM_EF_CB_CH_INFO_LID)
    },

#if (( (!defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)) && (!defined(__MSG_ID_MMI_PS_GET_GPRS_DATA_COUNTER_REQ_PHASE_OUT__)) ) || (defined(__TCM_UT__)))
    {
        NVRAM_EF_TCM_STATISTICS_LID,
        NVRAM_EF_TCM_STATISTICS_TOTAL,
        NVRAM_EF_TCM_STATISTICS_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT47",
        VER(NVRAM_EF_TCM_STATISTICS_LID)
    },
#endif // ~ #if ( (!defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)) && (!defined(__MSG_ID_MMI_PS_GET_GPRS_DATA_COUNTER_REQ_PHASE_OUT__)) )

#if defined (__PS_SERVICE__) && defined (__MOD_TCM__) && defined (__EXT_PDP_CONTEXT_ON__)
    {
        NVRAM_EF_TCM_PDP_PROFILE_LID,
        NVRAM_EF_TCM_PDP_PROFILE_TOTAL,
        NVRAM_EF_TCM_PDP_PROFILE_SIZE,
        NVRAM_NORMAL(NVRAM_EF_TCM_PDP_PROFILE_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT48",
        VER(NVRAM_EF_TCM_PDP_PROFILE_LID)
    },
#endif // ~ #if defined (__PS_SERVICE__) && defined (__MOD_TCM__) && defined (__EXT_PDP_CONTEXT_ON__)

    {
        NVRAM_EF_CFU_FLAG_LID,
        NVRAM_EF_CFU_FLAG_TOTAL,
        NVRAM_EF_CFU_FLAG_SIZE,
        NVRAM_NORMAL(NVRAM_EF_CFU_FLAG_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT49",
        VER(NVRAM_EF_CFU_FLAG_LID)
    },

    {
        NVRAM_EF_MM_EQPLMN_LOCIGPRS_LID,
        NVRAM_EF_MM_EQPLMN_LOCIGPRS_TOTAL,
        NVRAM_EF_MM_EQPLMN_LOCIGPRS_SIZE,
        NVRAM_NORMAL(NVRAM_EF_MM_EQPLMN_LOCIGPRS_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
#ifdef __UMTS_FDD_MODE__          
        "MT4A",
#else
        "MT4E",
#endif
        VER(NVRAM_EF_MM_EQPLMN_LOCIGPRS_LID)
    },
    
#if defined (__CPHS__) || defined (__CCM_NO_RESET__)
    {
        NVRAM_EF_ALS_LINE_ID_LID,
        NVRAM_EF_ALS_LINE_ID_TOTAL,
        NVRAM_EF_ALS_LINE_ID_SIZE,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_ALS_LINE_ID_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
        NVRAM_ATTR_AVERAGE,
        "MT4C",
        VER(NVRAM_EF_ALS_LINE_ID_LID)
    },
#endif/* (__CPHS__) || (__CCM_NO_RESET__)*/

    {
        NVRAM_EF_MSCAP_LID,
        NVRAM_EF_MSCAP_TOTAL,
        NVRAM_EF_MSCAP_SIZE,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_MSCAP_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
        NVRAM_ATTR_WRITEPROTECT | NVRAM_ATTR_MULTIPLE,
#ifdef __UMTS_FDD_MODE__ 
        "MT4D",
#else
        "MT4F",
#endif
        VER(NVRAM_EF_MSCAP_LID)
    },
    
    {
        NVRAM_EF_CLASSMARK_RACAP_LID,
        NVRAM_EF_CLASSMARK_RACAP_TOTAL,
        NVRAM_EF_CLASSMARK_RACAP_SIZE,
        NVRAM_NORMAL(NVRAM_EF_CLASSMARK_RACAP_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_WRITEPROTECT | NVRAM_ATTR_MULTIPLE,
        "MT17",
        VER(NVRAM_EF_CLASSMARK_RACAP_LID)
    },
    
    {
        NVRAM_EF_SIM_ASSERT_LID,
        NVRAM_EF_SIM_ASSERT_TOTAL,
        NVRAM_EF_SIM_ASSERT_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_RING,
        "MT18",
        VER(NVRAM_EF_SIM_ASSERT_LID)
    },
        
    {
        NVRAM_EF_RTC_DATA_LID,
        NVRAM_EF_RTC_DATA_TOTAL,
        NVRAM_EF_RTC_DATA_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT19",
        VER(NVRAM_EF_RTC_DATA_LID)
    },
    
#if defined(__UMTS_RAT__) || defined(__STORED_CELL_SELECTION_INFO__)
    {
        NVRAM_EF_NET_PAR_LID,
        NVRAM_EF_NET_PAR_TOTAL,
        NVRAM_EF_NET_PAR_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
#if (!defined(__UMTS_RAT__) && defined(__STORED_CELL_SELECTION_INFO__)) || defined(__UMTS_FDD_MODE__)
        "MT1A",
#endif
#ifdef __UMTS_TDD128_MODE__
        "MT3A",
#endif
        VER(NVRAM_EF_NET_PAR_LID)
    },
#endif

//#ifdef __BAND_PRIORITY_SEARCH__
#if defined(__UMTS_RAT__) && defined(__UMTS_FDD_MODE__)
    {
        NVRAM_EF_UMTS_BAND_PRIORITY_LID,
        NVRAM_EF_UMTS_BAND_PRIORITY_TOTAL,
        NVRAM_EF_UMTS_BAND_PRIORITY_SIZE,
        NVRAM_NORMAL(NVRAM_EF_UMTS_BAND_PRIORITY_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT12",
        VER(NVRAM_EF_UMTS_BAND_PRIORITY_LID)
    },
#endif /* __UMTS_RAT__ && __UMTS_FDD_MODE_ */
//#endif /* __BAND_PRIORITY_SEARCH__ */

#ifdef __UMTS_RAT__
/* currently useless
    {
        NVRAM_EF_UMTS_PLMN_LID,
        NVRAM_EF_UMTS_PLMN_TOTAL,
        NVRAM_EF_UMTS_PLMN_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "UM01",
        VER(NVRAM_EF_UMTS_PLMN_LID)
    },
*/
    {
        NVRAM_EF_UMTS_IMSI_LID,
        NVRAM_EF_UMTS_IMSI_TOTAL,
        NVRAM_EF_UMTS_IMSI_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_CONFIDENTIAL,
        "UM02",
        VER(NVRAM_EF_UMTS_IMSI_LID)
    },
    
    {
        NVRAM_EF_UMTS_START_HFN_LID,
        NVRAM_EF_UMTS_START_HFN_TOTAL,
        NVRAM_EF_UMTS_START_HFN_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "UM03",
        VER(NVRAM_EF_UMTS_START_HFN_LID)
    },
    
    {
        NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_LID,
        NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_TOTAL,
        NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_SIZE,
        NVRAM_NORMAL(NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
#ifdef __UMTS_FDD_MODE__
        "UM04",
#endif
#ifdef __UMTS_TDD128_MODE__
         "UM05",
#endif
        VER(NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_LID)
    },
    
    {
        NVRAM_EF_UMTS_FREQUENCY_REPOSITORY_LID,
        NVRAM_EF_UMTS_FREQUENCY_REPOSITORY_TOTAL,
        NVRAM_EF_UMTS_FREQUENCY_REPOSITORY_SIZE,
        NVRAM_NORMAL(NVRAM_EF_UMTS_FREQUENCY_REPOSITORY_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
#ifdef __UMTS_FDD_MODE__
        "UM06",
#endif
#ifdef __UMTS_TDD128_MODE__
         "UM07",
#endif
        VER(NVRAM_EF_UMTS_FREQUENCY_REPOSITORY_LID)
    },
#if (defined(__UMTS_TDD128_MODE__) && defined(__UMTS_R7__)) || (defined(__SEARCH_ALL_EHPLMN_TOGETHER__))
   {
        NVRAM_EF_UMTS_URR_CONFIGURATION_LID,
        NVRAM_EF_UMTS_URR_CONFIGURATION_TOTAL,
        NVRAM_EF_UMTS_URR_CONFIGURATION_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "UM08",
        VER(NVRAM_EF_UMTS_URR_CONFIGURATION_LID)
    },
#endif

#endif /* __UMTS_RAT__ */
#if defined(__MA_L1__) || defined(__UMTS_RAT__)
    {
        NVRAM_EF_L1_3G_CAL_DATA_LID,
        NVRAM_EF_L1_3G_CAL_DATA_TOTAL,
        NVRAM_EF_L1_3G_CAL_DATA_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT1B",
        VER(NVRAM_EF_L1_3G_CAL_DATA_LID)
    },
#endif

#if 0
#if !defined(__LOW_COST_SUPPORT_COMMON__) && defined(__FLC_SUPPORT__ )&& defined(__MTK_INTERNAL__)
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
#endif /* !__LOW_COST_SUPPORT_COMMON__&&__MTK_INTERNAL__ && __FLC_SUPPORT__ */
#endif

#if defined (__E_COMPASS_SENSOR_SUPPORT__)
    {
        NVRAM_EF_ECOMPASS_DATA_LID,
        NVRAM_EF_ECOMPASS_DATA_TOTAL,
        NVRAM_EF_ECOMPASS_DATA_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT1D",
        VER(NVRAM_EF_ECOMPASS_DATA_LID)
    },
#endif  /* __E_COMPASS_SENSOR_SUPPORT__ */

#ifdef __BAND_BLOCK__
    {
        NVRAM_EF_BAND_BLOCK_LID,
        NVRAM_EF_BAND_BLOCK_TOTAL,
        NVRAM_EF_BAND_BLOCK_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIPLE,
        "MT1E",
        VER(NVRAM_EF_BAND_BLOCK_LID),
    },
#endif /* __BAND_BLOCK__ */


#ifdef  __BTMODULE_RFMD3500__
    {
        NVRAM_EF_BTRADIO_RFMD3500_LID,
        NVRAM_EF_BTRADIO_RFMD3500_TOTAL,
        NVRAM_EF_BTRADIO_RFMD3500_SIZE,
        NVRAM_NORMAL(NVRAM_EF_BTRADIO_RFMD3500_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT1G",
        VER(NVRAM_EF_BTRADIO_RFMD3500_LID)
    },
#endif





#if defined(__ATCMD_ONOFF_CHECK__)
    {
        NVRAM_EF_ATCMD_ON_OFF_CHECK_LID,
        NVRAM_EF_ATCMD_ON_OFF_CHECK_TOTAL,
        NVRAM_EF_ATCMD_ON_OFF_CHECK_SIZE,
        NVRAM_NORMAL(&NVRAM_EF_ATCMD_ONOFF_CHECK_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MSP | NVRAM_ATTR_CONFIDENTIAL,
        "MT30",
        VER(NVRAM_EF_ATCMD_ON_OFF_CHECK_LID)
    },
#endif

#if defined(__TST_DNT_LOGGING__)
    {
        NVRAM_EF_PS_L2COPRO_FILTER_SETTINGS_LID,
        NVRAM_EF_PS_L2COPRO_FILTER_SETTINGS_TOTAL,
        NVRAM_EF_PS_L2COPRO_FILTER_SETTINGS_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT31",
        VER(NVRAM_EF_PS_L2COPRO_FILTER_SETTINGS_LID)
    },
#endif  //#if defined(__TST_DNT_LOGGING__)

#if defined(__ETWS_SUPPORT__)
    {
            NVRAM_EF_ETWS_SETTING_LID,
            NVRAM_EF_ETWS_SETTING_TOTAL,
            NVRAM_EF_ETWS_SETTING_SIZE,
            NVRAM_NORMAL(&NVRAM_EF_ETWS_SETTING_DEFAULT),
            NVRAM_CATEGORY_USER,
            NVRAM_ATTR_AVERAGE,
            "MT32",
            VER(NVRAM_EF_ETWS_SETTING_LID)
    },
#endif

    {
            NVRAM_EF_CSM_ESSP_LID,
            NVRAM_EF_CSM_ESSP_TOTAL,
            NVRAM_EF_CSM_ESSP_SIZE,
            NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
            NVRAM_CATEGORY_USER,
            NVRAM_ATTR_AVERAGE,
            "MT35",
            VER(NVRAM_EF_CSM_ESSP_LID)
    },

/* UEM*/
    {
        NVRAM_EF_CUST_HW_LEVEL_TBL_LID,
        NVRAM_EF_CUST_HW_LEVEL_TBL_TOTAL,
        NVRAM_EF_CUST_HW_LEVEL_TBL_SIZE,
    #if defined(__MMI_FMI__)        
        NVRAM_NORMAL((const kal_uint8 *)NVRAM_EF_CUST_HW_LEVEL_TBL_DEFAULT),
    #else
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
    #endif
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_SW_VERNO_RESET | NVRAM_ATTR_ZIP_DEFAULT,
        "MT67",
        VER(NVRAM_EF_CUST_HW_LEVEL_TBL_LID)
    },
    
    {
        NVRAM_EF_UEM_MANUFACTURE_DATA_LID,
        NVRAM_EF_UEM_MANUFACTURE_DATA_TOTAL,
        NVRAM_EF_UEM_MANUFACTURE_DATA_SIZE,
        NVRAM_NORMAL(NVRAM_EF_UEM_MANUFACTURE_DATA_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_ZIP_DEFAULT,
        "MT68",
        VER(NVRAM_EF_UEM_MANUFACTURE_DATA_LID)
    },
    
    {
        NVRAM_EF_UEM_RMI_DATA_LID,
        NVRAM_EF_UEM_RMI_DATA_TOTAL,
        NVRAM_EF_UEM_RMI_DATA_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_ZIP_DEFAULT,
        "MT69",
        VER(NVRAM_EF_UEM_RMI_DATA_LID)
    },

#ifdef __GPS_SUPPORT__
    {
        NVRAM_EF_GPS_SETTING_DATA_LID,
        NVRAM_EF_GPS_SETTING_DATA_TOTAL,
        NVRAM_EF_GPS_SETTING_DATA_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT6D",
        VER(NVRAM_EF_GPS_SETTING_DATA_LID)
    },
#endif /* __GPS_SUPPORT__ */

#if defined(__GPS_SUPPORT__) && defined(__MNL_SUPPORT__)
    {
        NVRAM_EF_MNL_SETTING_DATA_LID,
        NVRAM_EF_MNL_SETTING_DATA_TOTAL,
        NVRAM_EF_MNL_SETTING_DATA_SIZE,
        NVRAM_NORMAL(NVRAM_EF_MNL_SETTING_DATA_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT6E",
        VER(NVRAM_EF_MNL_SETTING_DATA_LID)
    },
#endif /* __GPS_SUPPORT__ & __MNL_SUPPORT__ */

#if defined(__WIFI_BT_SINGLE_ANTENNA_SUPPORT__)
    {
        NVRAM_EF_BWCS_SETTING_DATA_LID,
        NVRAM_EF_BWCS_SETTING_DATA_TOTAL,
        NVRAM_EF_BWCS_SETTING_DATA_SIZE,
        NVRAM_NORMAL(NVRAM_EF_BWCS_SETTING_DATA_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT6F",
        VER(NVRAM_EF_BWCS_SETTING_DATA_LID)
    },
#endif /* __WIFI_BT_SINGLE_ANTENNA_SUPPORT__ */


    {
        NVRAM_EF_MS_SECURITY_LID,
        NVRAM_EF_MS_SECURITY_TOTAL,
        NVRAM_EF_MS_SECURITY_SIZE,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_MS_SECURITY_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
    #ifdef __TC01__
/* under construction !*/
    #else
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_CONFIDENTIAL,
    #endif
        "MT6G",
        VER(NVRAM_EF_MS_SECURITY_LID)
    },

#if !defined(__PHB_NO_CALL_LOG__) & !defined(__L1_STANDALONE__)
    {
          NVRAM_EF_PHB_LN_ENTRY_LID,
          NVRAM_EF_PHB_LN_ENTRY_TOTAL,
          NVRAM_EF_PHB_LN_ENTRY_SIZE,
          NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
          NVRAM_CATEGORY_USER,
          NVRAM_ATTR_AVERAGE,
          "MT6H",
          VER(NVRAM_EF_PHB_LN_ENTRY_LID)
    },

    {
          NVRAM_EF_PHB_LN_TYPE_SEQ_LID,
          NVRAM_EF_PHB_LN_TYPE_SEQ_TOTAL,
          NVRAM_EF_PHB_LN_TYPE_SEQ_SIZE,
          NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
          NVRAM_CATEGORY_USER,
          NVRAM_ATTR_AVERAGE,
          "MT6I",
          VER(NVRAM_EF_PHB_LN_TYPE_SEQ_LID)
    },

#endif /* !defined(__PHB_NO_CALL_LOG__) & !defined(__L1_STANDALONE__) */





    {
        NVRAM_EF_SYS_CACHE_OCTET_LID,
        NVRAM_EF_SYS_CACHE_OCTET_TOTAL,
        NVRAM_EF_SYS_CACHE_OCTET_SIZE,
        NVRAM_NORMAL_NOT_GEN(NVRAM_EF_SYS_CACHE_OCTET_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTI_DEFAULT | NVRAM_ATTR_NOT_ZIP_DEFAULT,
        "MT6K",
        VER(NVRAM_EF_SYS_CACHE_OCTET_LID)
    },

#ifdef __DRM_V02__
    {
        NVRAM_EF_DRM_SETTING_LID,
        NVRAM_EF_DRM_SETTING_TOTAL,
        NVRAM_EF_DRM_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_CONFIDENTIAL,
        "MT6L",
        VER(NVRAM_EF_DRM_SETTING_LID)
    },
    
    {
        NVRAM_EF_DRM_STIME_LID,
        NVRAM_EF_DRM_STIME_TOTAL,
        NVRAM_EF_DRM_STIME_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_CONFIDENTIAL,
        "MT6M",
        VER(NVRAM_EF_DRM_STIME_LID)
    },
    
    {
        NVRAM_EF_DRM_CERPATH_LID,
        NVRAM_EF_DRM_CERPATH_TOTAL,
        NVRAM_EF_DRM_CERPATH_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT6N",
        VER(NVRAM_EF_DRM_CERPATH_LID)
    },
#endif /* __DRM_V02__ */


    {
        NVRAM_EF_RAC_PREFERENCE_LID,
        NVRAM_EF_RAC_PREFERENCE_TOTAL,
        NVRAM_EF_RAC_PREFERENCE_SIZE,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_RAC_PREFERENCE_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
#ifdef __UMTS_FDD_MODE__        
        "MT6S",
#else
        "MT6Z",
#endif
        VER(NVRAM_EF_RAC_PREFERENCE_LID)
    },

#ifdef __TC02_SECURITY_REQUIREMENT__
    {                                                                   
        NVRAM_EF_MM_IMSI_LOCI_GLOCI_LID,
        NVRAM_EF_MM_IMSI_LOCI_GLOCI_TOTAL,
        NVRAM_EF_MM_IMSI_LOCI_GLOCI_SIZE,
        NVRAM_SECUPACK(NVRAM_EF_MM_IMSI_LOCI_GLOCI_DEFAULT),
        NVRAM_CATEGORY_SECUPACK,
        NVRAM_ATTR_MSP | NVRAM_ATTR_CONFIDENTIAL,
        "MT6T", 
        VER(NVRAM_EF_MM_IMSI_LOCI_GLOCI_LID)
    },
#endif  /* __TC02_SECURITY_REQUIREMENT__ */    

    {
        NVRAM_EF_PS_CONFORMANCE_TESTMODE_LID,
        NVRAM_EF_PS_CONFORMANCE_TESTMODE_TOTAL,
        NVRAM_EF_PS_CONFORMANCE_TESTMODE_SIZE,
//#ifdef __SEARCH_ALL_EHPLMN_TOGETHER__        
//        NVRAM_NORMAL(NVRAM_EF_PS_CONFORMANCE_TESTMODE_DEFAULT),
//#else
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
//#endif
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT6U",
        VER(NVRAM_EF_PS_CONFORMANCE_TESTMODE_LID)
    },

#if !defined(L4_NOT_PRESENT)
#ifndef __PHB_STORAGE_BY_MMI__
    {
        NVRAM_EF_PHB_LID,
        NVRAM_EF_PHB_TOTAL,
        NVRAM_EF_PHB_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIREC_READ,
        "MT6V",
        VER(NVRAM_EF_PHB_LID)
    },
#endif
#endif

//__MOBILE_BROADBAND_PROVISION_CONTEXT__
#ifdef __MOBILE_BROADBAND_PROVISION_CONTEXT__
    {
        NVRAM_EF_MOBILE_BROADBAND_PROVISION_CONTEXT_LID,
        NVRAM_EF_MOBILE_BROADBAND_PROVISION_CONTEXT_TOTAL,
        NVRAM_EF_MOBILE_BROADBAND_PROVISION_CONTEXT_SIZE,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_MOBILE_BROADBAND_PROVISION_CONTEXT_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTI_DEFAULT,
        "MT70",
        VER(NVRAM_EF_MOBILE_BROADBAND_PROVISION_CONTEXT_LID)
        //"MB PROVISION CONTEXT",
        //NVRAM_APP_RESERVED
    },        
#endif /* __MOBILE_BROADBAND_PROVISION_CONTEXT__ */

#ifdef __MINI_LOG_SUPPORT__
	{
		NVRAM_EF_MINI_LOG_01_LID,
		NVRAM_EF_MINI_LOG_TOTAL,
		NVRAM_EF_MINI_LOG_SIZE,		
		NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),		
		NVRAM_CATEGORY_USER,
		NVRAM_ATTR_AVERAGE,
		"TR01",
		VER(NVRAM_EF_MINI_LOG_01_LID)
	},
	{
		NVRAM_EF_MINI_LOG_02_LID,
		NVRAM_EF_MINI_LOG_TOTAL,
		NVRAM_EF_MINI_LOG_SIZE,		
		NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),		
		NVRAM_CATEGORY_USER,
		NVRAM_ATTR_AVERAGE,
		"TR02",
		VER(NVRAM_EF_MINI_LOG_02_LID)
	},
	{
		NVRAM_EF_MINI_LOG_03_LID,
		NVRAM_EF_MINI_LOG_TOTAL,
		NVRAM_EF_MINI_LOG_SIZE,		
		NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),		
		NVRAM_CATEGORY_USER,
		NVRAM_ATTR_AVERAGE,
		"TR03",
		VER(NVRAM_EF_MINI_LOG_03_LID)
	},
	{
		NVRAM_EF_MINI_LOG_04_LID,
		NVRAM_EF_MINI_LOG_TOTAL,
		NVRAM_EF_MINI_LOG_SIZE,		
		NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),		
		NVRAM_CATEGORY_USER,
		NVRAM_ATTR_AVERAGE,
		"TR04",
		VER(NVRAM_EF_MINI_LOG_04_LID)
	},
	{
		NVRAM_EF_MINI_LOG_05_LID,
		NVRAM_EF_MINI_LOG_TOTAL,
		NVRAM_EF_MINI_LOG_SIZE,		
		NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),		
		NVRAM_CATEGORY_USER,
		NVRAM_ATTR_AVERAGE,
		"TR05",
		VER(NVRAM_EF_MINI_LOG_05_LID)
	},
#endif

  {
        NVRAM_EF_TST_CONFIG_LID,
        NVRAM_EF_TST_CONFIG_TOTAL,
        NVRAM_EF_TST_CONFIG_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
        "MT72",
        VER(NVRAM_EF_TST_CONFIG_LID)
    },

#ifdef __SYSSEL_SUPPORT__
    {
        NVRAM_EF_SYSSEL_SETTING_LID,
        NVRAM_EF_SYSSEL_SETTING_TOTAL,
        NVRAM_EF_SYSSEL_SETTING_SIZE,
        NVRAM_NORMAL((const kal_uint8 *)NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT73",
        VER(NVRAM_EF_SYSSEL_SETTING_LID),
    },
#endif /* __SYSSEL_SUPPORT__ */

//__MEDIATEK_SMART_QOS__
#ifdef __MEDIATEK_SMART_QOS__
    {
        NVRAM_EF_MSQ_LIST_LID,
        NVRAM_EF_MSQ_LIST_TOTAL,
        NVRAM_EF_MSQ_LIST_SIZE,
        NVRAM_NORMAL(NVRAM_EF_MSQ_LIST_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT74",
        VER(NVRAM_EF_MSQ_LIST_LID)
    },
#endif /* __MEDIATEK_SMART_QOS__ */
#ifdef __AST_TL1_TDD_RF_PARAMETER_SUPPORT__
	{
		NVRAM_EF_AST_TL1_RF_PARAM_LID,
		NVRAM_EF_AST_TL1_RF_PARAM_TOTAL,
		NVRAM_EF_AST_TL1_RF_PARAM_SIZE,
		NVRAM_NORMAL(AST_TL1_RF_PARAMETER_DEFAULT),
		NVRAM_CATEGORY_USER, /// this is auto calibrated in first time mcu power on (or the data loss case), don't need backup & restore
		NVRAM_ATTR_AVERAGE,
		"TL10", 
		VER(NVRAM_EF_AST_TL1_RF_PARAM_LID)
	},				
#endif	
    {
        NVRAM_EF_REGIONAL_PHONE_MODE_LID,
        NVRAM_EF_REGIONAL_PHONE_MODE_TOTAL,
        NVRAM_EF_REGIONAL_PHONE_MODE_SIZE,
    #ifdef __REGIONAL_PHONE__
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
    #else
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
    #endif
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_FACTORY_RESET,
        "MT75",
        VER(NVRAM_EF_REGIONAL_PHONE_MODE_LID),
    },
    {
        NVRAM_EF_SBP_MODEM_CONFIG_LID,
        NVRAM_EF_SBP_MODEM_CONFIG_TOTAL,
        NVRAM_EF_SBP_MODEM_CONFIG_SIZE,
        NVRAM_NORMAL(NVRAM_EF_SBP_MODEM_CONFIG_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_CONFIDENTIAL | NVRAM_ATTR_MSP,
        "MT80",
        VER(NVRAM_EF_SBP_MODEM_CONFIG_LID)
    },
    {
        NVRAM_EF_SBP_MODEM_DATA_CONFIG_LID,
        NVRAM_EF_SBP_MODEM_DATA_CONFIG_TOTAL,
        NVRAM_EF_SBP_MODEM_DATA_CONFIG_SIZE,
        NVRAM_NORMAL(NVRAM_EF_SBP_MODEM_DATA_CONFIG_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_CONFIDENTIAL | NVRAM_ATTR_MSP,
        "MT81",
        VER(NVRAM_EF_SBP_MODEM_DATA_CONFIG_LID)
    },
};

/* Configure NVRAM_EF_SYS_CACHE_OCTET_LID begin */
#ifdef NVRAM_AUTO_GEN
nvram_sys_cache_entry nvram_sys_cache[] =
{
    SYS_CACHE_ENTRY(NVRAM_SYS_CACHE_BEGIN,
                    NVRAM_APP_RESERVED,
                    KAL_FALSE,
                    "Record system cache will be restore or not",
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),

    SYS_CACHE_ENTRY(NVRAM_SYS_FLIGHTMODE_STATE,
                    NVRAM_APP_RESERVED,
                    KAL_TRUE,
                    "NVRAM_SYS_FLIGHTMODE_STATE",
                #if (GEMINI_PLUS == 4)
                    0x00, 0x00, 0x0F, 0x00, 0x01, 0x00, 0x00, 0x00),
                #elif (GEMINI_PLUS == 3)
                    0x00, 0x00, 0x07, 0x00, 0x01, 0x00, 0x00, 0x00),
                #elif (GEMINI_PLUS == 2)
                    0x00, 0x00, 0x03, 0x00, 0x01, 0x00, 0x00, 0x00),
                #else
                    0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00),
                #endif
    SYS_CACHE_ENTRY(NVRAM_SYS_DSP_PATCH,
                    NVRAM_APP_RESERVED,
                    KAL_FALSE,
                    "NVRAM_SYS_DSP_PATCH",
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),
    SYS_CACHE_ENTRY(NVRAM_SYS_SIM_PLUS_SETTING,
                    NVRAM_APP_RESERVED,
                    KAL_TRUE,
                    "NVRAM_SYS_SIM_PLUS_SETTING",
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),
    SYS_CACHE_ENTRY(NVRAM_SYS_FIXED_GAIN_MECH_FOR_HELIOS2,
                    NVRAM_APP_RESERVED,
                    KAL_FALSE,
                    "NVRAM_SYS_FIXED_GAIN_MECH_FOR_HELIOS2",
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),
    SYS_CACHE_ENTRY(NVRAM_SYS_FACTORY_FLAG,
                    NVRAM_APP_RESERVED,
                    KAL_TRUE,
                    "NVRAM_SYS_FACTORY_FLAG",
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),
    SYS_CACHE_ENTRY(NVRAM_SYS_LAST_FAT_STATUS,
                    NVRAM_APP_RESERVED,
                    KAL_TRUE,
                    "NVRAM_SYS_LAST_FAT_STATUS",
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),
    SYS_CACHE_ENTRY(NVRAM_SYS_INFO,
                    NVRAM_APP_RESERVED,
                    KAL_FALSE,
                    "NVRAM_SYS_INFO",
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),
#if defined(NEPTUNE_MMI)
    SYS_CACHE_ENTRY(NVRAM_SYS_PHB_COMPARE_DIGIT,
                    NVRAM_APP_RESERVED,
                    KAL_FALSE,
                    "NVRAM_SYS_PHB_COMPARE_DIGIT",
                    0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),
#else
    SYS_CACHE_ENTRY(NVRAM_SYS_PHB_COMPARE_DIGIT,
                    NVRAM_APP_RESERVED,
                    KAL_FALSE,
                    "NVRAM_SYS_PHB_COMPARE_DIGIT",
                    0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),
#endif
    SYS_CACHE_ENTRY(NVRAM_SYS_SVN,
                    NVRAM_APP_RESERVED,
                    KAL_FALSE,
                    "NVRAM_SYS_SVN",
                    0x87, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),
    SYS_CACHE_ENTRY(NVRAM_SYS_USB_BOOT_MODE,
                    NVRAM_APP_RESERVED,
                    KAL_FALSE,
                    "NVRAM_SYS_USB_BOOT_MODE\0",
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),
    SYS_CACHE_ENTRY(NVRAM_SYS_USB_TETHERING_MODE,
                    NVRAM_APP_RESERVED,
                    KAL_FALSE,
                    "NVRAM_SYS_USB_TETHERING_MODE\0",
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),                    
    SYS_CACHE_ENTRY(NVRAM_SYS_AUTO_TEST,
                    NVRAM_APP_RESERVED,
                    KAL_FALSE,
                    "NVRAM_SYS_AUTO_TEST\0",
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),
    SYS_CACHE_ENTRY(NVRAM_SYS_MINI_LOG_IDX,
                    NVRAM_APP_RESERVED,
                    KAL_FALSE,
                    "NVRAM_SYS_MINI_LOG_IDX\0",
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),       
     SYS_CACHE_ENTRY(NVRAM_SYS_SWLA,
                    NVRAM_APP_RESERVED,
                    KAL_FALSE,
                    "NVRAM_SYS_SWLA\0",
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),             

    /* !!Add a entry above this line by using SYS_CACHE_ENTRY macro */
    SYS_CACHE_ENTRY(NVRAM_SYS_CACHE_MAX,
                    NVRAM_APP_RESERVED,
                    KAL_FALSE,
                    "The last record of system cache",
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),
};
#endif
/* Configure NVRAM_EF_SYS_CACHE_OCTET_LID end */

#endif /* NVRAM_NOT_PRESENT */
