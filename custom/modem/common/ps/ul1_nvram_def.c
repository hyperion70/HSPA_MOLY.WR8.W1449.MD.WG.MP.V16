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
 * ul1_nvram_def.c
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
 * 
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef NVRAM_NOT_PRESENT

/* In case of that not to build this file in 2G projects or 3G TDD projects */
#if defined (__MTK_UL1_FDD__)


/*
 *   Include Headers
 */

#include "kal_general_types.h"

/*
 *   NVRAM Basic Headers
 */
#ifdef NVRAM_AUTO_GEN
#include "nvram_auto_gen.h"
#endif

#include "nvram_enums.h"
#include "nvram_defs.h"
#include "nvram_data_items.h"

/*
 *   User Headers
 */
#include "ul1_nvram_def.h"

/*
 *   Default value
 */
/* Custpack LIDs' default value should left in nvram_cust_pack.c */ 
#if (defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__))
    extern U_sUl1dRfCustomInputData COMMON_NVRAM_EF_UL1_3G_RF_PARAMETER_DEFAULT[];
#endif

#if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__)
    extern U_sUl1IotCustomSupportStruct COMMON_NVRAM_EF_UL1_IOT_CUSTOMIZATION_DEFAULT[];
#endif

#if defined (__UL1_HS_PLUS_PLATFORM__) || defined (__UL1_HS_PLATFORM__)
    extern nvram_ef_ul1_hspa_category_struct COMMON_NVRAM_EF_UL1_HSPA_CATEGORY_DEFAULT[];
#endif

#if defined (__UL1_PLATFORM__)
	#if defined (__MTK_UL1_FDD__)
		extern nvram_ef_ul1_rf_custpack_data_select_struct COMMON_NVRAM_EF_UL1_RF_CUSTPACK_DATA_SELECT_DEFAULT[];
		extern nvram_ef_ul1_rf_custom_data_struct COMMON_NVRAM_EF_UL1_RF_CUSTOM_DATA_DEFAULT[];
	#endif
#endif

/*
 *   Function extern
 */
extern void nvram_get_uL1_default_value_to_write(nvram_lid_enum lid, kal_uint8 * buffer, kal_uint16 buffer_size);

/*
 *   LID table
 */

ltable_entry_struct logical_data_item_table_ul1[] =
{
#if defined (__UL1_PLATFORM__)
    {
        NVRAM_EF_UL1_RF_CUSTPACK_DATA_SELECT_LID,
        NVRAM_EF_UL1_RF_CUSTPACK_DATA_SELECT_TOTAL,
        NVRAM_EF_UL1_RF_CUSTPACK_DATA_SELECT_SIZE,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_UL1_RF_CUSTPACK_DATA_SELECT_DEFAULT),
        NVRAM_CATEGORY_USER| NVRAM_CATEGORY_CUSTPACK,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTI_DEFAULT,
        "MT2Q",
        VER(NVRAM_EF_UL1_RF_CUSTPACK_DATA_SELECT_LID)
    },

    {
        NVRAM_EF_UL1_RF_CUSTOM_DATA_LID,
        NVRAM_EF_UL1_RF_CUSTOM_DATA_TOTAL,
        NVRAM_EF_UL1_RF_CUSTOM_DATA_SIZE,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_UL1_RF_CUSTOM_DATA_DEFAULT),
        NVRAM_CATEGORY_USER| NVRAM_CATEGORY_CUSTPACK,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTI_DEFAULT,
        "MT2R",
        VER(NVRAM_EF_UL1_RF_CUSTOM_DATA_LID)
    },
#endif /* #if defined (__UL1_PLATFORM__) */

#if (defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__))
    {
        NVRAM_EF_UL1_3G_RF_PARAMETER_LID,
        NVRAM_EF_UL1_3G_RF_PARAMETER_TOTAL,
        NVRAM_EF_UL1_3G_RF_PARAMETER_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTI_DEFAULT,
        "MT2S",
        VER(NVRAM_EF_UL1_3G_RF_PARAMETER_LID)
    },
#endif /* #if (defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__)) */

#if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__)
    {
        NVRAM_EF_UL1_IOT_CUSTOMIZATION_LID,
        NVRAM_EF_UL1_IOT_CUSTOMIZATION_TOTAL,
        NVRAM_EF_UL1_IOT_CUSTOMIZATION_SIZE,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_UL1_IOT_CUSTOMIZATION_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTI_DEFAULT,
        "MT2T",
        VER(NVRAM_EF_UL1_IOT_CUSTOMIZATION_LID)
    },
#endif /* #if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__) */

#if defined (__UL1_HS_PLUS_PLATFORM__) || defined (__UL1_HS_PLATFORM__)
   {
       NVRAM_EF_UL1_HSPA_CATEGORY_LID,
       NVRAM_EF_UL1_HSPA_CATEGORY_TOTAL,
       NVRAM_EF_UL1_HSPA_CATEGORY_SIZE,
       NVRAM_CUSTPACK(COMMON_NVRAM_EF_UL1_HSPA_CATEGORY_DEFAULT),
       NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
       NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTI_DEFAULT,
       "MT2U",
       VER(NVRAM_EF_UL1_HSPA_CATEGORY_LID)
    },
#endif
#if defined (__UL1_HS_PLUS_PLATFORM__) || defined (__UL1_HS_PLATFORM__)
    {
        NVRAM_EF_UL1_CUSTOM_DYNAMIC_INIT_DEBUG_LID,
        NVRAM_EF_UL1_CUSTOM_DYNAMIC_INIT_DEBUG_TOTAL,
        NVRAM_EF_UL1_CUSTOM_DYNAMIC_INIT_DEBUG_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT), // NVRAM_NORMAL for data not in secupack and custpack
        NVRAM_CATEGORY_USER,
        /* Attribute NVRAM_ATTR_MULTIPLE for double copy on flash */
        NVRAM_ATTR_AVERAGE,
        /* Category NVRAM_CATEGORY_CUSTPACK for using default value from custpack */
        "MT2V",
        VER(NVRAM_EF_UL1_CUSTOM_DYNAMIC_INIT_DEBUG_LID)
        //"UL1 Custom Dynamic Init Debug",
        //NVRAM_APP_RESERVED
    }
#endif

};

#endif /* #if defined (__MTK_UL1_FDD__) */

#endif /* NVRAM_NOT_PRESENT */
