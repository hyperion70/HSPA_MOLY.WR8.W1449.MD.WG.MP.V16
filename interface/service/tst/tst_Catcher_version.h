/*******************************************************************************
*  Modification Notice:
*  --------------------------
*  This software is modified by MediaTek Inc. and the information contained
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
*******************************************************************************/


/*****************************************************************************
 *
 * Filename:
 * ---------
 * tst_Catcher_version.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains the version Info of Catcher
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __TST_CATCHER_VERSION_H__
#define __TST_CATCHER_VERSION_H__

#include "swtr.h"	// for __MAUI_SOFTWARE_TRACER__ definition
#include "us_timer.h"   // for __HW_US_TIMER_SUPPORT__ definition
 
#if defined(GEN_FOR_PC)

//This structure is for Catcher usage only
//Catcher owners should update these enum if they would like keep some information into the database.

typedef enum
{
 Catcher_Info_Enum_Begin,
 //Please add content here
 
 //Common indications
 CATCHER_NEW_DESCR_INFO_STRUCT,
 CATCHER_TST_END_REDUMP_TRACE,
 CATCHER_DB_ON_MD_ARM,

 //General Optional indications
 CATCHER_L1_TIMESTAMP,                  // support timestamp packed in all L1 frames 

#ifndef LOW_COST_SUPPORT 
 CATCHER_STATISTICS_STRING_REPLACING,   // support Statistics and FLC string replacing
#endif  //#ifndef LOW_COST_SUPPORT 

#ifdef __EM_MODE__
 CATCHER_ENGINEERING_MODE_INDEPENDENT_UPDATE,
#endif  //#ifdef __EM_MODE__


#if defined(MTK_SLEEP_ENABLE) 
#if defined(__EGPRS_MODE__)||defined(__SMART_PHONE_MODEM__)||defined(__UMTS_RAT__)
 FORCE_CATCHER_XON,
#endif  //#if defined(__EGPRS_MODE__)||defined(__SMART_PHONE_MODEM__)||defined(__UMTS_RAT__)
#endif  //#if defined(MTK_SLEEP_ENABLE)  

#if defined(__UMTS_RAT__)
 CATCHER_UL1_TIMESTAMP,                  // support RTOS_TimeStamp in UL1 Time Trace 
#else 
 CATCHER_L1_TIMESTAMP_SIM1, 
#endif  //#if defined(__UMTS_RAT__)  


#if defined(__MAUI_SOFTWARE_TRACER__)
 CATCHER_SW_TRACER_ENABLE,
#else	//#if defined(__MAUI_SOFTWARE_TRACER__)
 CATCHER_SW_TRACER_DISABLE,
#endif	//#if defined(__MAUI_SOFTWARE_TRACER__)

 //MTK Internal Optional indications
#if defined(__MTK_TARGET__) && !defined(__MAUI_BASIC__)
 CATCHER_SWLA_SWTR_DYNAMIC_ENABLE,

#if defined(__HW_US_TIMER_SUPPORT__)
 CATCHER_SWLA_NEW_CLOCK_ENABLE,
#endif  //#if defined(__HW_US_TIMER_SUPPORT__)
 CATCHER_SWLA_SWTR_DYNAMIC_DISABLE,
 CATCHER_SWLA_EMI_QUERY_ENABLE,

#endif  //#if defined(__MTK_TARGET__) && !defined(__MAUI_BASIC__)
#if defined(__DSP_FCORE4__) && !defined(UNIT_TEST)
  CATCHER_FCORE_MEMORY_DUMP_ENABLE,
#endif  //#if defined(MT6270A) || defined(MT6276) || defined(MT6573)
 CATCHER_R5R6_CPHY_CONTAINER_STRUCT, 
#if defined(__UMTS_R7__) 
 CATCHER_R7_CPHY_CONTAINER_STRUCT,
#endif  //#if defined(__UMTS_R7__) 
 CATCHER_GDI_LAYER_BYTES_PER_PIXEL_INFO,
#if defined(__AST_TL1_TDD__) && !defined(UNIT_TEST)
 CATCHER_AST_MEMORY_DUMP_ENABLE,
#endif  //#if defined(__AST_TL1_TDD__) && !defined(UNIT_TEST) 

#if defined( __UMTS_TDD128_MODE__)
 CATCHER_DB_FOR_TDD,
#endif  //#if defined( __UMTS_TDD128_MODE__)

#if defined(__AST_TL1_TDD__)
 CATCHER_AST_FAST_MEMORY_DUMP,
#endif  //#if defined(__AST_TL1_TDD__)

 CATCHER_EM_MULTIPLE_SIM_ENABLE,
 CATCHER_SIM_READ_MULTIPLE_SIM_ENABLE,
 CATCHER_PS_NO_FN, //Indicate PS log won't send out FNs.
 
#if defined(__SMART_PHONE_MODEM__) || defined(__MINI_LOG_SUPPORT__) || defined(__TST_LOG_WITH_DMA__) || defined(__TST_MALMO_SUPPORT__)
 CATCHER_PS_NO_CHECK_SUM_ENABLED, //Support 0x58 and 0x59
 CATCHER_L1_NO_CHECK_SUM_ENABLED, //Support 0xA6
#endif 
 CATCHER_MEMORY_DUMP_DIAGNOSIS,
#if defined(__MINI_LOG_SUPPORT__)
 CATCHER_MINI_LOG_SUPPORT,
#endif
 
 CATCHER_ASSERT_CALLBACK_ENABLE,
 CATCHER_TCL_FILTER_NOT_SAVE_NVRAM, //Don't save filter into NVRAM

#ifdef __TST_MALMO_SUPPORT__
 CATCHER_MALMO_ENABLED,               //for MALMO
 
 #ifdef MT6280_S00
 CATCHER_BUS_MONITOR_WORKAROUND,      //E
 #endif //MT6280_S00

#ifdef __TST_ASM_SUPPORT__
 CATCHER_MALMO_RAM_SWLA_SWITCH,
#ifdef __MALMO_ASM_BUSMONITOR__
 CATCHER_MALMO_BUS_MONITOR,
#endif //#ifdef __MALMO_ASM_BUSMONITOR__

#ifdef __MALMO_ASM_SWTR__
 CATCHER_MALMO_SWTR_HEADER,
#endif //__MALMO_ASM_SWTR__

#endif //__TST_ASM_SUPPORT__

#endif  //__TST_MALMO_SUPPORT__

#if defined(__SMART_PHONE_MODEM__)
 CATCHER_SP_CONFIG_SUPPORT,
#endif

#if defined(__L1BOXSTER__)  
 CATCHER_L1BOXSTER,
#endif

CATCHER_SWTR_NEW_TIME_SCALE,  // change SWTR time scale from 1/16 to 1/1024

 Catcher_Info_Enum_End
}Catcher_Version_Info_Enum;

typedef enum
{
  SWLA_Clock_Origin_Wrap = 5000,
  SWLA_Clock_Origin_Rate = 1083000,   //1.083MHZ  
#ifdef MT6268  
  SWLA_Clock_Rate = 3250000,   //3.25MHZ
  SWLA_Clock_Wrap = 0x0FFFFFFF,  
#elif defined(MT6270A) || defined(MT6276) || defined(MT6573) || defined(MT6575) || defined(TK6280) || defined(MT6280) || defined(__HW_US_TIMER_SUPPORT__)
  SWLA_Clock_Rate = 1000000,   //1MHZ
  SWLA_Clock_Wrap = 0xFFFFFFFF,    
#endif  
  SWLA_TimeStamp_Ratio = 4615,  // For LMU-based SWLA to convert us to frame
  SWLA_CLOCK_END 
}Catcher_SWLA_Clock;

#ifdef NUM_OF_SIM
  #define CATCHER_NUM_OF_SIM NUM_OF_SIM
  #undef NUM_OF_SIM
#endif  //NUM_OF_SIM

//workaround
#if defined(__GEMINI__) && !defined(GEMINI_PLUS)
  #define GEMINI_PLUS 2
#endif  //GEMINI_PLUS

typedef enum
{
  //UMTS SIMs
#if defined(__UMTS_RAT__)
  NUM_OF_UMTS_SIM = 1,
#else
  NUM_OF_UMTS_SIM = 0,
#endif  

  //GSM SIMs
#if !defined(__GEMINI__)
  NUM_OF_GSM_SIM = 1,
#else
  NUM_OF_GSM_SIM = GEMINI_PLUS,
#endif    
  
  //total SIM number
#if !defined(__GEMINI__)  
  NUM_OF_SIM = 1
#else //__GEMINI__
  NUM_OF_SIM = GEMINI_PLUS
#endif  //__GEMINI__

}
sim_info_enum;

#ifdef CATCHER_NUM_OF_SIM
  #define NUM_OF_SIM CATCHER_NUM_OF_SIM
#endif  //NUM_OF_SIM

//Catcher version checking
typedef enum
{
  v3_1105_00 
}
catcher_min_version;

typedef enum
{
  PS_11A  
#if defined(__AST_TL1_TDD__) || defined(__UMTS_TDD128_MODE__)
  ,TDD_11A
#endif  
}
catcher_default_filter_info;

#endif //#if defined(GEN_FOR_PC) 
 
#endif //__TST_CATCHER_VERSION_H__
