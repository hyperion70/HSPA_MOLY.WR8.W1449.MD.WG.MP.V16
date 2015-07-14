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
 * ul1_nvram_def.h
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
#ifndef __UL1_NVRAM_DEF_H__
#define __UL1_NVRAM_DEF_H__

/* In case of that not to build this file in 2G projects or 3G TDD projects */
#if defined (__MTK_UL1_FDD__)

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

/*
 *   Include Headers
 */
 

/*
 *   NVRAM Basic Headers
 */
#include "nvram_data_items.h"
#include "nvram_defs.h"


/*
 *   User Headers
 */
 
 
 


/*
 *   LID Enums
 */
 
typedef enum
{
    NVRAM_EF_UL1_RF_CUSTPACK_DATA_SELECT_LID        = NVRAM_LID_GRP_UL1(0),
    NVRAM_EF_UL1_RF_CUSTOM_DATA_LID                 = NVRAM_LID_GRP_UL1(1),
    NVRAM_EF_UL1_3G_RF_PARAMETER_LID                = NVRAM_LID_GRP_UL1(2),
    NVRAM_EF_UL1_IOT_CUSTOMIZATION_LID              = NVRAM_LID_GRP_UL1(3),
    NVRAM_EF_UL1_HSPA_CATEGORY_LID                  = NVRAM_LID_GRP_UL1(4),

/*
 *  Last LID of uL1 Group
 */
    NVRAM_EF_UL1_3G_LAST_LID                        = NVRAM_LID_GRP_UL1(255)
}nvram_lid_ul1_enum;



typedef enum
{
   NVRAM_EF_UL1_TEMP_DAC_LID                                                           = NVRAM_LID_GRP_UL1_CALIBRATION1(0),
   NVRAM_EF_UL1_PATHLOSS_START,
   NVRAM_EF_UL1_PATHLOSS_BAND1_LID = NVRAM_EF_UL1_PATHLOSS_START,                 
   NVRAM_EF_UL1_PATHLOSS_BAND2_LID,
   NVRAM_EF_UL1_PATHLOSS_BAND3_LID,
   NVRAM_EF_UL1_PATHLOSS_BAND4_LID,
   NVRAM_EF_UL1_PATHLOSS_BAND5_LID,
   NVRAM_EF_UL1_PATHLOSS_BAND6_LID,
   NVRAM_EF_UL1_PATHLOSS_BAND7_LID,
   NVRAM_EF_UL1_PATHLOSS_BAND8_LID,
   NVRAM_EF_UL1_PATHLOSS_BAND9_LID,
   NVRAM_EF_UL1_PATHLOSS_BAND10_LID,
   NVRAM_EF_UL1_PATHLOSS_BAND11_LID,
   NVRAM_EF_UL1_PATHLOSS_BAND12_LID,
   NVRAM_EF_UL1_PATHLOSS_BAND13_LID,
   NVRAM_EF_UL1_PATHLOSS_BAND14_LID,
   NVRAM_EF_UL1_PATHLOSS_BAND15_LID,
   NVRAM_EF_UL1_PATHLOSS_BAND16_LID,
   NVRAM_EF_UL1_PATHLOSS_BAND17_LID,
   NVRAM_EF_UL1_PATHLOSS_BAND18_LID,
   NVRAM_EF_UL1_PATHLOSS_BAND19_LID,
   NVRAM_EF_UL1_PATHLOSS_END = NVRAM_EF_UL1_PATHLOSS_BAND19_LID,
   NVRAM_EF_UL1_TXDAC_START,
   NVRAM_EF_UL1_TXDAC_BAND1_LID = NVRAM_EF_UL1_TXDAC_START,
   NVRAM_EF_UL1_TXDAC_BAND2_LID,
   NVRAM_EF_UL1_TXDAC_BAND3_LID,
   NVRAM_EF_UL1_TXDAC_BAND4_LID,
   NVRAM_EF_UL1_TXDAC_BAND5_LID,
   NVRAM_EF_UL1_TXDAC_BAND6_LID,
   NVRAM_EF_UL1_TXDAC_BAND7_LID,
   NVRAM_EF_UL1_TXDAC_BAND8_LID,
   NVRAM_EF_UL1_TXDAC_BAND9_LID,
   NVRAM_EF_UL1_TXDAC_BAND10_LID,
   NVRAM_EF_UL1_TXDAC_BAND11_LID,
   NVRAM_EF_UL1_TXDAC_BAND12_LID,
   NVRAM_EF_UL1_TXDAC_BAND13_LID,
   NVRAM_EF_UL1_TXDAC_BAND14_LID,
   NVRAM_EF_UL1_TXDAC_BAND15_LID,
   NVRAM_EF_UL1_TXDAC_BAND16_LID,
   NVRAM_EF_UL1_TXDAC_BAND17_LID,
   NVRAM_EF_UL1_TXDAC_BAND18_LID,
   NVRAM_EF_UL1_TXDAC_BAND19_LID,
   NVRAM_EF_UL1_TXDAC_END = NVRAM_EF_UL1_TXDAC_BAND19_LID,
   NVRAM_EF_UL1_TXPAOCTLEV_START,
   NVRAM_EF_UL1_TXPAOCTLEV_BAND1_LID = NVRAM_EF_UL1_TXPAOCTLEV_START,
   NVRAM_EF_UL1_TXPAOCTLEV_BAND2_LID,
   NVRAM_EF_UL1_TXPAOCTLEV_BAND3_LID,
   NVRAM_EF_UL1_TXPAOCTLEV_BAND4_LID,
   NVRAM_EF_UL1_TXPAOCTLEV_BAND5_LID,
   NVRAM_EF_UL1_TXPAOCTLEV_BAND6_LID,
   NVRAM_EF_UL1_TXPAOCTLEV_BAND7_LID,
   NVRAM_EF_UL1_TXPAOCTLEV_BAND8_LID,
   NVRAM_EF_UL1_TXPAOCTLEV_BAND9_LID,
   NVRAM_EF_UL1_TXPAOCTLEV_BAND10_LID,
   NVRAM_EF_UL1_TXPAOCTLEV_BAND11_LID,
   NVRAM_EF_UL1_TXPAOCTLEV_BAND12_LID,
   NVRAM_EF_UL1_TXPAOCTLEV_BAND13_LID,
   NVRAM_EF_UL1_TXPAOCTLEV_BAND14_LID,
   NVRAM_EF_UL1_TXPAOCTLEV_BAND15_LID,
   NVRAM_EF_UL1_TXPAOCTLEV_BAND16_LID,
   NVRAM_EF_UL1_TXPAOCTLEV_BAND17_LID,
   NVRAM_EF_UL1_TXPAOCTLEV_BAND18_LID,
   NVRAM_EF_UL1_TXPAOCTLEV_BAND19_LID,
   NVRAM_EF_UL1_TXPAOCTLEV_END = NVRAM_EF_UL1_TXPAOCTLEV_BAND19_LID,
   //For RXD, add by Jay
   NVRAM_EF_UL1_PATHLOSS2_START,        
   NVRAM_EF_UL1_PATHLOSS2_BAND1_LID = NVRAM_EF_UL1_PATHLOSS2_START,
   NVRAM_EF_UL1_PATHLOSS2_BAND2_LID,
   NVRAM_EF_UL1_PATHLOSS2_BAND3_LID,
   NVRAM_EF_UL1_PATHLOSS2_BAND4_LID,
   NVRAM_EF_UL1_PATHLOSS2_BAND5_LID,
   NVRAM_EF_UL1_PATHLOSS2_BAND6_LID,
   NVRAM_EF_UL1_PATHLOSS2_BAND7_LID,
   NVRAM_EF_UL1_PATHLOSS2_BAND8_LID,
   NVRAM_EF_UL1_PATHLOSS2_BAND9_LID,
   NVRAM_EF_UL1_PATHLOSS2_BAND10_LID,
   NVRAM_EF_UL1_PATHLOSS2_BAND11_LID,
   NVRAM_EF_UL1_PATHLOSS2_BAND12_LID,
   NVRAM_EF_UL1_PATHLOSS2_BAND13_LID,
   NVRAM_EF_UL1_PATHLOSS2_BAND14_LID,
   NVRAM_EF_UL1_PATHLOSS2_BAND15_LID,
   NVRAM_EF_UL1_PATHLOSS2_BAND16_LID,
   NVRAM_EF_UL1_PATHLOSS2_BAND17_LID,
   NVRAM_EF_UL1_PATHLOSS2_BAND18_LID,
   NVRAM_EF_UL1_PATHLOSS2_BAND19_LID,
   NVRAM_EF_UL1_PATHLOSS2_END = NVRAM_EF_UL1_PATHLOSS2_BAND19_LID,
   //For PA drift compensation , add by Wilson
   NVRAM_EF_UL1_TXPADRIFTCOMP_START,        
   NVRAM_EF_UL1_TXPADRIFTCOMP_BAND1_LID = NVRAM_EF_UL1_TXPADRIFTCOMP_START,
   NVRAM_EF_UL1_TXPADRIFTCOMP_BAND2_LID,
   NVRAM_EF_UL1_TXPADRIFTCOMP_BAND3_LID,
   NVRAM_EF_UL1_TXPADRIFTCOMP_BAND4_LID,
   NVRAM_EF_UL1_TXPADRIFTCOMP_BAND5_LID,
   NVRAM_EF_UL1_TXPADRIFTCOMP_BAND6_LID,
   NVRAM_EF_UL1_TXPADRIFTCOMP_BAND7_LID,
   NVRAM_EF_UL1_TXPADRIFTCOMP_BAND8_LID,
   NVRAM_EF_UL1_TXPADRIFTCOMP_BAND9_LID,
   NVRAM_EF_UL1_TXPADRIFTCOMP_BAND10_LID,
   NVRAM_EF_UL1_TXPADRIFTCOMP_BAND11_LID,
   NVRAM_EF_UL1_TXPADRIFTCOMP_BAND12_LID,
   NVRAM_EF_UL1_TXPADRIFTCOMP_BAND13_LID,
   NVRAM_EF_UL1_TXPADRIFTCOMP_BAND14_LID,
   NVRAM_EF_UL1_TXPADRIFTCOMP_BAND15_LID,
   NVRAM_EF_UL1_TXPADRIFTCOMP_BAND16_LID,
   NVRAM_EF_UL1_TXPADRIFTCOMP_BAND17_LID,
   NVRAM_EF_UL1_TXPADRIFTCOMP_BAND18_LID,
   NVRAM_EF_UL1_TXPADRIFTCOMP_BAND19_LID,
   NVRAM_EF_UL1_TXPADRIFTCOMP_END = NVRAM_EF_UL1_TXPADRIFTCOMP_BAND19_LID,
   // PRACH temperature compesation
   NVRAM_EF_UL1_TXPRACHTMCOMP_START,
   NVRAM_EF_UL1_TXPRACHTMCOMP_BAND1_LID = NVRAM_EF_UL1_TXPRACHTMCOMP_START,
   NVRAM_EF_UL1_TXPRACHTMCOMP_BAND2_LID,
   NVRAM_EF_UL1_TXPRACHTMCOMP_BAND3_LID,
   NVRAM_EF_UL1_TXPRACHTMCOMP_BAND4_LID,
   NVRAM_EF_UL1_TXPRACHTMCOMP_BAND5_LID,
   NVRAM_EF_UL1_TXPRACHTMCOMP_BAND6_LID,
   NVRAM_EF_UL1_TXPRACHTMCOMP_BAND7_LID,
   NVRAM_EF_UL1_TXPRACHTMCOMP_BAND8_LID,
   NVRAM_EF_UL1_TXPRACHTMCOMP_BAND9_LID,
   NVRAM_EF_UL1_TXPRACHTMCOMP_BAND10_LID,
   NVRAM_EF_UL1_TXPRACHTMCOMP_BAND11_LID,
   NVRAM_EF_UL1_TXPRACHTMCOMP_BAND12_LID,
   NVRAM_EF_UL1_TXPRACHTMCOMP_BAND13_LID,
   NVRAM_EF_UL1_TXPRACHTMCOMP_BAND14_LID,
   NVRAM_EF_UL1_TXPRACHTMCOMP_BAND15_LID,
   NVRAM_EF_UL1_TXPRACHTMCOMP_BAND16_LID,
   NVRAM_EF_UL1_TXPRACHTMCOMP_BAND17_LID,
   NVRAM_EF_UL1_TXPRACHTMCOMP_BAND18_LID,
   NVRAM_EF_UL1_TXPRACHTMCOMP_BAND19_LID,
   NVRAM_EF_UL1_TXPRACHTMCOMP_END = NVRAM_EF_UL1_TXPRACHTMCOMP_BAND19_LID,
   //For 3G Calibration Data End
   NVRAM_EF_UL1_3G_CAL_LAST_LID = NVRAM_LID_GRP_UL1_CALIBRATION1(255)
}nvram_lid_ul1_cal_enum;



/*
 *   Verno
 */
 
#define NVRAM_EF_UL1_RF_CUSTPACK_DATA_SELECT_LID_VERNO       "000"
#define NVRAM_EF_UL1_RF_CUSTOM_DATA_LID_VERNO                "000"
#define NVRAM_EF_UL1_3G_RF_PARAMETER_LID_VERNO               "000"
#define NVRAM_EF_UL1_IOT_CUSTOMIZATION_LID_VERNO             "000"
#define NVRAM_EF_UL1_HSPA_CATEGORY_LID_VERNO                 "000"
#define NVRAM_EF_UL1_CUSTOM_DYNAMIC_INIT_DEBUG_LID_VERNO     "000"


#define NVRAM_EF_UL1_TEMP_DAC_LID_VERNO                      "000"
#define NVRAM_EF_UL1_PATHLOSS_BAND1_LID_VERNO                "000"
#define NVRAM_EF_UL1_PATHLOSS_BAND2_LID_VERNO                "000"
#define NVRAM_EF_UL1_PATHLOSS_BAND3_LID_VERNO                "000"
#define NVRAM_EF_UL1_PATHLOSS_BAND4_LID_VERNO                "000"
#define NVRAM_EF_UL1_PATHLOSS_BAND5_LID_VERNO                "000"
#define NVRAM_EF_UL1_PATHLOSS_BAND6_LID_VERNO                "000"
#define NVRAM_EF_UL1_PATHLOSS_BAND7_LID_VERNO                "000"
#define NVRAM_EF_UL1_PATHLOSS_BAND8_LID_VERNO                "000"
#define NVRAM_EF_UL1_PATHLOSS_BAND9_LID_VERNO                "000"
#define NVRAM_EF_UL1_PATHLOSS_BAND10_LID_VERNO               "000"
#define NVRAM_EF_UL1_PATHLOSS_BAND11_LID_VERNO               "000"
#define NVRAM_EF_UL1_PATHLOSS_BAND19_LID_VERNO               "000"
#define NVRAM_EF_UL1_TXDAC_BAND1_LID_VERNO                   "000"
#define NVRAM_EF_UL1_TXDAC_BAND2_LID_VERNO                   "000"
#define NVRAM_EF_UL1_TXDAC_BAND3_LID_VERNO                   "000"
#define NVRAM_EF_UL1_TXDAC_BAND4_LID_VERNO                   "000"
#define NVRAM_EF_UL1_TXDAC_BAND5_LID_VERNO                   "000"
#define NVRAM_EF_UL1_TXDAC_BAND6_LID_VERNO                   "000"
#define NVRAM_EF_UL1_TXDAC_BAND7_LID_VERNO                   "000"
#define NVRAM_EF_UL1_TXDAC_BAND8_LID_VERNO                   "000"
#define NVRAM_EF_UL1_TXDAC_BAND9_LID_VERNO                   "000"
#define NVRAM_EF_UL1_TXDAC_BAND10_LID_VERNO                  "000"
#define NVRAM_EF_UL1_TXDAC_BAND11_LID_VERNO                  "000"
#define NVRAM_EF_UL1_TXDAC_BAND19_LID_VERNO                  "000"
#if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__) 
#define NVRAM_EF_UL1_TXPAOCTLEV_BAND1_LID_VERNO              "000"
#define NVRAM_EF_UL1_TXPAOCTLEV_BAND2_LID_VERNO              "000"
#define NVRAM_EF_UL1_TXPAOCTLEV_BAND3_LID_VERNO              "000"
#define NVRAM_EF_UL1_TXPAOCTLEV_BAND4_LID_VERNO              "000"
#define NVRAM_EF_UL1_TXPAOCTLEV_BAND5_LID_VERNO              "000"
#define NVRAM_EF_UL1_TXPAOCTLEV_BAND6_LID_VERNO              "000"
#define NVRAM_EF_UL1_TXPAOCTLEV_BAND7_LID_VERNO              "000"
#define NVRAM_EF_UL1_TXPAOCTLEV_BAND8_LID_VERNO              "000"
#define NVRAM_EF_UL1_TXPAOCTLEV_BAND9_LID_VERNO              "000"
#define NVRAM_EF_UL1_TXPAOCTLEV_BAND10_LID_VERNO             "000"
#define NVRAM_EF_UL1_TXPAOCTLEV_BAND11_LID_VERNO             "000"
#define NVRAM_EF_UL1_TXPAOCTLEV_BAND19_LID_VERNO             "000"
#endif
/* RXD & PA drift Comp (MT6280) */
#if defined(__UMTS_R8__)
#define NVRAM_EF_UL1_PATHLOSS2_BAND1_LID_VERNO                "000"
#define NVRAM_EF_UL1_PATHLOSS2_BAND2_LID_VERNO                "000"
#define NVRAM_EF_UL1_PATHLOSS2_BAND3_LID_VERNO                "000"
#define NVRAM_EF_UL1_PATHLOSS2_BAND4_LID_VERNO                "000"
#define NVRAM_EF_UL1_PATHLOSS2_BAND5_LID_VERNO                "000"
#define NVRAM_EF_UL1_PATHLOSS2_BAND6_LID_VERNO                "000"
#define NVRAM_EF_UL1_PATHLOSS2_BAND7_LID_VERNO                "000"
#define NVRAM_EF_UL1_PATHLOSS2_BAND8_LID_VERNO                "000"
#define NVRAM_EF_UL1_PATHLOSS2_BAND9_LID_VERNO                "000"
#define NVRAM_EF_UL1_PATHLOSS2_BAND10_LID_VERNO               "000"
#define NVRAM_EF_UL1_PATHLOSS2_BAND11_LID_VERNO               "000"
#define NVRAM_EF_UL1_PATHLOSS2_BAND19_LID_VERNO               "000"

#define NVRAM_EF_UL1_TXPADRIFTCOMP_BAND1_LID_VERNO            "000"
#define NVRAM_EF_UL1_TXPADRIFTCOMP_BAND2_LID_VERNO            "000"
#define NVRAM_EF_UL1_TXPADRIFTCOMP_BAND3_LID_VERNO            "000"
#define NVRAM_EF_UL1_TXPADRIFTCOMP_BAND4_LID_VERNO            "000"
#define NVRAM_EF_UL1_TXPADRIFTCOMP_BAND5_LID_VERNO            "000"
#define NVRAM_EF_UL1_TXPADRIFTCOMP_BAND6_LID_VERNO            "000"
#define NVRAM_EF_UL1_TXPADRIFTCOMP_BAND7_LID_VERNO            "000"
#define NVRAM_EF_UL1_TXPADRIFTCOMP_BAND8_LID_VERNO            "000"
#define NVRAM_EF_UL1_TXPADRIFTCOMP_BAND9_LID_VERNO            "000"
#define NVRAM_EF_UL1_TXPADRIFTCOMP_BAND10_LID_VERNO           "000"
#define NVRAM_EF_UL1_TXPADRIFTCOMP_BAND11_LID_VERNO           "000"
#define NVRAM_EF_UL1_TXPADRIFTCOMP_BAND19_LID_VERNO           "000"
#endif

// PRACH temperature compensation
#define NVRAM_EF_UL1_TXPRACHTMCOMP_BAND1_LID_VERNO            "000"
#define NVRAM_EF_UL1_TXPRACHTMCOMP_BAND2_LID_VERNO            "000"
#define NVRAM_EF_UL1_TXPRACHTMCOMP_BAND3_LID_VERNO            "000"
#define NVRAM_EF_UL1_TXPRACHTMCOMP_BAND4_LID_VERNO            "000"
#define NVRAM_EF_UL1_TXPRACHTMCOMP_BAND5_LID_VERNO            "000"
#define NVRAM_EF_UL1_TXPRACHTMCOMP_BAND6_LID_VERNO            "000"
#define NVRAM_EF_UL1_TXPRACHTMCOMP_BAND7_LID_VERNO            "000"
#define NVRAM_EF_UL1_TXPRACHTMCOMP_BAND8_LID_VERNO            "000"
#define NVRAM_EF_UL1_TXPRACHTMCOMP_BAND9_LID_VERNO            "000"
#define NVRAM_EF_UL1_TXPRACHTMCOMP_BAND10_LID_VERNO           "000"
#define NVRAM_EF_UL1_TXPRACHTMCOMP_BAND11_LID_VERNO           "000"
#define NVRAM_EF_UL1_TXPRACHTMCOMP_BAND19_LID_VERNO           "000"

/*
 * Record Size/Total Records
 */

#define NVRAM_EF_UL1_RF_CUSTPACK_DATA_SELECT_SIZE    (sizeof(nvram_ef_ul1_rf_custpack_data_select_struct))
#define NVRAM_EF_UL1_RF_CUSTPACK_DATA_SELECT_TOTAL   (1) /* Should not be modified */

#define NVRAM_EF_UL1_RF_CUSTOM_DATA_SIZE             (sizeof(nvram_ef_ul1_rf_custom_data_struct))
#define NVRAM_EF_UL1_RF_CUSTOM_DATA_TOTAL            (4) /* Only one default value for run-time usage is enough */

#define NVRAM_EF_UL1_3G_RF_PARAMETER_SIZE            (sizeof(U_sUl1dRfCustomInputData))
#define NVRAM_EF_UL1_3G_RF_PARAMETER_TOTAL           (1)

#define NVRAM_EF_UL1_IOT_CUSTOMIZATION_SIZE          (sizeof(U_sUl1IotCustomSupportStruct))
#define NVRAM_EF_UL1_IOT_CUSTOMIZATION_TOTAL         (1)

#define NVRAM_EF_UL1_HSPA_CATEGORY_SIZE              (sizeof(nvram_ef_ul1_hspa_category_struct))
#define NVRAM_EF_UL1_HSPA_CATEGORY_TOTAL             (1)

/* For Single Software Load for Multiple Components Compatible */
#define NVRAM_EF_UL1_CUSTOM_DYNAMIC_INIT_DEBUG_SIZE   (sizeof(Ul1CustomDynamicInitDebug))
#define NVRAM_EF_UL1_CUSTOM_DYNAMIC_INIT_DEBUG_TOTAL  (1)



#if defined(__UMTS_RAT__) && defined(__MTK_UL1_FDD__)
#define NVRAM_EF_UL1_TEMP_DAC_SIZE    sizeof(ul1cal_tempdacData_T)
#define NVRAM_EF_UL1_TEMP_DAC_TOTAL   1

#define NVRAM_EF_UL1_PATHLOSS_BAND_SIZE    sizeof(ul1cal_pathlossData_T)
#define NVRAM_EF_UL1_PATHLOSS_BAND_TOTAL   1

#define NVRAM_EF_UL1_TXDAC_BAND_SIZE    sizeof(ul1cal_txdacData_T)
#define NVRAM_EF_UL1_TXDAC_BAND_TOTAL   1

/* PA 8-level control (For MT6276, MT6573) */
#if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__) 
#define NVRAM_EF_UL1_TXPAOCTLEV_BAND_SIZE sizeof(ul1cal_txPaOctLevData_T)
#define NVRAM_EF_UL1_TXPAOCTLEV_BAND_TOTAL 1
#endif /* #if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__) */

#define NVRAM_EF_UL1_TXPRACHTMCOMP_BAND_SIZE    sizeof(ul1cal_txPrachTmCompData_T)
#define NVRAM_EF_UL1_TXPRACHTMCOMP_BAND_TOTAL   1

#if defined(__UMTS_R8__)
#define NVRAM_EF_UL1_PATHLOSS2_BAND_SIZE    sizeof(ul1cal_pathlossRxdData_T)
#define NVRAM_EF_UL1_PATHLOSS2_BAND_TOTAL   1

#define NVRAM_EF_UL1_TXPADRIFTCOMP_BAND_SIZE    sizeof(ul1cal_txPaDriftCompData_T)
#define NVRAM_EF_UL1_TXPADRIFTCOMP_BAND_TOTAL   1
#endif

#endif /* __UMTS_RAT__ && __MTK_UL1_FDD__ */



/*
 *   Data Structure
 */
#if defined(__UL1_PLATFORM__)

typedef struct
{
    kal_uint16 ul1_rf_custpack_data_selector;
} nvram_ef_ul1_rf_custpack_data_select_struct;

typedef struct
{
    /* Timing advance and postpone of RF window */
    kal_uint16 maxRxStartOffset;
    kal_uint16 maxTxStartOffset;
    kal_uint16 minRxEndOffset;
    kal_uint16 minTxEndOffset;

    /* Timing of PA control */    
    kal_uint8  maxOffset;
    kal_uint8  vmOffset;
    kal_uint8  vbiasOffset;
    kal_uint8  dc2dcOffset;
    kal_uint8  vgaOffset;

    /* PA section usage */
    kal_uint8  paSection;

    /* RF T/RX timing offset table */
    kal_int16  umtsRxStartTqTable[UMTS_RF_RX_START_TIMING_ARRAY_LENGTH];
    kal_int16  umtsRxEndTqTable[UMTS_RF_RX_END_TIMING_ARRAY_LENGTH];
    kal_int16  umtsTxStartTqTable[UMTS_RF_TX_START_TIMING_ARRAY_LENGTH];
    kal_int16  umtsTxEndTqTable[UMTS_RF_TX_END_TIMING_ARRAY_LENGTH];

    /* BPI data allocation */
    kal_int16  umtsPdataTable[UMTS_RF_BPI_DATA_TABLE_NUM_OF_BANDS][UMTS_RF_BPI_DATA_TABLE_NUM_OF_WINDOWS][UMTS_RF_BPI_DATA_TABLE_NUM_OF_EVENTS];

    /* DC2DC level and VM setting table */
    kal_uint8 DC2DC[UMTS_RF_MAX_PA_SECTIONS];
    kal_uint8 VM_data[UMTS_RF_MAX_PA_SECTIONS];

    /* RF Hign-band and Low-band receivers configurations */
    UMTSBand HB1;
    UMTSBand HB2;
    UMTSBand LB1;
#if defined (MT6162_RF) // MT6162 has two low band receivers
    UMTSBand LB2;    
#endif

} nvram_ef_ul1_rf_custom_data_struct;


#endif /* #if defined (__UL1_PLATFORM__) */

typedef struct
{
   kal_uint8 dpa_cat;
   kal_uint8 upa_cat;
} nvram_ef_ul1_hspa_category_struct;

//#if defined (__UL1_HS_PLATFORM__)

#include "ul1cal.h"


//#endif /* #if defined (__UL1_HS_PLATFORM__)

#include "ul1d_rf_common.h"

#ifdef __MTK_UL1_FDD__    
    extern nvram_ltable_entry_struct logical_data_item_table_ul1[];
#endif  /* __MTK_UL1_FDD__ */

#ifdef __cplusplus
}
#endif 

#endif /* #if defined (__MTK_UL1_FDD__) */

#endif /* __UL1_NVRAM_DEF_H__ */ 
