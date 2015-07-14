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
 *   stack_config.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file provides the task index and module index configuration.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef TASK_PRIORITY_MACRO

#define TASK_PRIORITY_L1           (KAL_PRIORITY_CLASS0 + 6)

/* L1 & FT run in different boot mode */
#ifdef  __UMTS_RAT__
#define TASK_PRIORITY_UL1DATA      (KAL_PRIORITY_CLASS0 + 8)
#define TASK_PRIORITY_TL1DATA      (KAL_PRIORITY_CLASS0 + 5)
#define TASK_PRIORITY_UL1C         (KAL_PRIORITY_CLASS1 + 0)
#define TASK_PRIORITY_UL1          (KAL_PRIORITY_CLASS1 + 2)
#define TASK_PRIORITY_TL1          (KAL_PRIORITY_CLASS1 + 3)
#define TASK_PRIORITY_UL2          (KAL_PRIORITY_CLASS1 + 4)
#endif
#ifdef __MTK_UL1_FDD__
#define TASK_PRIORITY_UL1TST       (KAL_PRIORITY_CLASS1 + 2)
#endif
#ifdef  __UMTS_RAT__
#define TASK_PRIORITY_UL2D         (KAL_PRIORITY_CLASS1 + 6)
#endif /* __UMTS_RAT__ */
#if defined(__GEMINI__)
#define TASK_PRIORITY_RSVA         (KAL_PRIORITY_CLASS1 + 8)
#endif
#ifdef __UE_SIMULATOR__
#define TASK_PRIORITY_L2ACCSIM     (KAL_PRIORITY_CLASS1 + 3)  
#define TASK_PRIORITY_L2HWREASMSIM (KAL_PRIORITY_CLASS1 + 5)  
#endif /*__UE_SIMULATOR__*/

#ifdef  __UMTS_RAT__
#define TASK_PRIORITY_URR          (KAL_PRIORITY_CLASS2 + 0)
#define TASK_PRIORITY_UL2D_2ND     (TASK_PRIORITY_URR + 1)
#endif

#define TASK_PRIORITY_DUMMYMPAL    (KAL_PRIORITY_CLASS2 + 2)

#define TASK_PRIORITY_RR           (KAL_PRIORITY_CLASS2 + 4)
#define TASK_PRIORITY_DUMMYRR      (KAL_PRIORITY_CLASS2 + 4)

#define TASK_PRIORITY_ULCS         (KAL_PRIORITY_CLASS3 + 0)
#define TASK_PRIORITY_REASM        (KAL_PRIORITY_CLASS3 + 2)
#define TASK_PRIORITY_RRLP         (KAL_PRIORITY_CLASS3 + 3)
#define TASK_PRIORITY_RATCM        (KAL_PRIORITY_CLASS3 + 4)
#define TASK_PRIORITY_MM           (KAL_PRIORITY_CLASS4 + 2)
#define TASK_PRIORITY_SIM          (KAL_PRIORITY_CLASS4 + 4)
#define TASK_PRIORITY_CC           (KAL_PRIORITY_CLASS4 + 6)
#define TASK_PRIORITY_SM           (KAL_PRIORITY_CLASS4 + 8)
#define TASK_PRIORITY_DATA         (KAL_PRIORITY_CLASS5 + 0)
#define TASK_PRIORITY_LLC          (KAL_PRIORITY_CLASS5 + 2)

#define TASK_PRIORITY_CISS         (KAL_PRIORITY_CLASS6 + 6)

#define TASK_PRIORITY_SMS          (KAL_PRIORITY_CLASS7 + 2)
#define TASK_PRIORITY_SNDCP        (KAL_PRIORITY_CLASS7 + 4)

/* GSM+CDMA external modem Project */
#define TASK_PRIORITY_EXT_MODEM    (KAL_PRIORITY_CLASS7 + 8)

#define TASK_PRIORITY_RATDM        (KAL_PRIORITY_CLASS8 + 2)

/* J2ME & FTA run in different boot mode */
#define TASK_PRIORITY_L4           (KAL_PRIORITY_CLASS8 + 4)

#ifdef __DT_SUPPORT__
#define TASK_PRIORITY_DT           (KAL_PRIORITY_CLASS22+ 4)
#endif   /* __DT_SUPPORT__ */


#else
/*module id are divided into 3 parts. 
 * 1: module id that maps to task
 * 2: module id that maps to no task but can be used as src module id
 *  to allocate ilm, like HISR's module id
 * 3: module id that is used to print trace only.  * */



/*******************  Modem 2G3G start  **********************/
/*************************Task CFG Begin****************/
/*task_indx_type*/
/* this is a fake task for task id grouping*/
task_index(INDX_MODEM_START = TASK_ID_MODEM_2G3G_CODE_BEGIN)
//task_index(INDX_MODEM_START)

/*module_type and mod_task_g*/
task_module_map(INDX_MODEM_START, MOD_MODEM_DUMMY_BEGIN = MOD_ID_MODEM_2G3G_CODE_BEGIN)
/*task's parameters*/
task_name("")
task_queue_name("")
task_priority(0 , KAL_TASK_INITIAL_PRIORITY)
task_stack_size(0)
null_task_create_entry(NULL)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(0)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
/*************************Task CFG END******************/


/*********************    Modem Start    ********************/
/*************************Task CFG Begin****************/
#if defined __RRLP_SUPPORT__
/*task_indx_type*/
task_index(INDX_RRLP)  
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_RRLP,MOD_DUMMY_RRLP)
/*module_type and mod_task_g*/
task_module_map(INDX_RRLP, MOD_RRLP)
/*task's parameters*/
task_name("RRLP")
task_queue_name("RRLP Q")
task_priority(TASK_PRIORITY_RRLP , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(2156)
task_create_function(rrlp_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(30)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#ifdef __DT_SUPPORT__
/*For data transfer between target and host*/
/*task_indx_type*/
task_index(INDX_DT)            /*WAP ps task*/ 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_DT,MOD_DUMMY_DT)
/*module_type and mod_task_g*/
task_module_map(INDX_DT, MOD_DT)

/*task's parameters*/
task_name("DT")
task_queue_name("DT Q")
task_priority(TASK_PRIORITY_DT , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(3600)
task_create_function(dt_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif
/*************************Task CFG END******************/

/*************************Task CFG Begin******************/
/*task_indx_type*/
task_index(INDX_RATCM) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_RATCM,MOD_DUMMY_RATCM)
/*module_type and mod_task_g*/
task_module_map(INDX_RATCM, MOD_RATCM)
#ifdef __GEMINI__
task_module_map(INDX_RATCM, MOD_RATCM_2)
#if (GEMINI_PLUS >= 3)
task_module_map(INDX_RATCM, MOD_RATCM_3)
#if (GEMINI_PLUS >= 4)
task_module_map(INDX_RATCM, MOD_RATCM_4)
#endif /* GEMINI_PLUS >= 4 */
#endif /* GEMINI_PLUS >= 3 */
#endif /* __GEMINI__ */

//task's parameters
#ifdef __UMTS_TDD128_MODE__
    task_name("RATCM_TDD")
#else
    task_name("RATCM_FDD")
#endif
task_queue_name("RATCM Q")
task_priority(TASK_PRIORITY_RATCM , KAL_TASK_INITIAL_PRIORITY )
#if defined(__LOW_COST_SUPPORT_ULC__)
task_stack_size(768)
#else
task_stack_size(1088)
#endif

#if defined(RATCM_NOT_PRESENT)
null_task_create_entry(NULL)
#else 
task_create_function(ratcm_create)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(30)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
/*************************Task CFG END******************/

/*************************Task CFG Begin******************/
/*task_indx_type*/
task_index(INDX_RATDM) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_RATDM,MOD_DUMMY_RATDM)
/*module_type and mod_task_g*/
task_module_map(INDX_RATDM, MOD_RATDM)
#ifdef __GEMINI__
task_module_map(INDX_RATDM, MOD_RATDM_2)
#if (GEMINI_PLUS >= 3)
task_module_map(INDX_RATDM, MOD_RATDM_3)
#if (GEMINI_PLUS >= 4)
task_module_map(INDX_RATDM, MOD_RATDM_4)
#endif /* GEMINI_PLUS >= 4 */
#endif /* GEMINI_PLUS >= 3 */
#endif /* __GEMINI__ */

//task's parameters
task_name("RATDM")
task_queue_name("RATDM Q")
task_priority(TASK_PRIORITY_RATDM , KAL_TASK_INITIAL_PRIORITY )
#ifdef __3G_NEW_DATA_PLANE_ARCH__
task_stack_size(1280)
#else // #ifdef __3G_NEW_DATA_PLANE_ARCH__
task_stack_size(1360)
#endif // ~ #ifdef __3G_NEW_DATA_PLANE_ARCH__

#if defined(RATDM_NOT_PRESENT)
null_task_create_entry(NULL)
#else 
task_create_function(ratdm_create)
#endif
task_stack_internalRAM(KAL_FALSE)
#if defined(__UMTS_RAT__)
task_external_queue_size(60)
#else
task_external_queue_size(30)
#endif
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
/*************************Task CFG END******************/

#ifdef __UE_SIMULATOR__
task_index(INDX_L2HWACCSIM) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_L2HWACCSIM,MOD_DUMMY_L2HWACCSIM)
task_module_map(INDX_L2HWACCSIM, MOD_L2HWACCSIM)
task_name("L2HWACCSIM")
task_queue_name("L2HWACCSIM Q")
task_priority(TASK_PRIORITY_L2ACCSIM , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(2480)
task_create_function(l2_hw_acc_sim_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)

task_index(INDX_L2HWREASMSIM) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_L2HWREASMSIM,MOD_DUMMY_L2HWREASMSIM)
task_module_map(INDX_L2HWREASMSIM, MOD_L2HWREASMSIM)
task_name("L2HWACCSIM")
task_queue_name("L2HWACCSIM Q")
task_priority(TASK_PRIORITY_L2HWREASMSIM , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(2480)
task_create_function(l2_hw_reasm_sim_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif /*__UE_SIMULATOR__*/

/*************************Task CFG Begin****************/
/*task_indx_type*/
#ifdef  __UMTS_RAT__
task_index(INDX_URR) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_URR,MOD_DUMMY_URR)
/*module_type and mod_task_g*/
#ifndef DUMMY_PROTOCOL
task_module_map(INDX_URR, MOD_MEME)
task_module_map(INDX_URR, MOD_CSE)
task_module_map(INDX_URR, MOD_CSCE)
task_module_map(INDX_URR, MOD_SIBE)
task_module_map(INDX_URR, MOD_USIME)
task_module_map(INDX_URR, MOD_RRCE)
task_module_map(INDX_URR, MOD_SLCE)
task_module_map(INDX_URR, MOD_ADR)
task_module_map(INDX_URR, MOD_URR)
task_module_map(INDX_URR, MOD_DB)
#else
task_module_map(INDX_DUMMYURR, MOD_MEME)
compatible_code(MOD_DUMMYMEME=MOD_MEME)
task_module_map(INDX_DUMMYURR, MOD_CSE)
compatible_code(MOD_DUMMYCSE=MOD_CSE )
task_module_map(INDX_DUMMYURR, MOD_CSCE)
compatible_code(MOD_DUMMYCSCE=MOD_CSCE )
task_module_map(INDX_DUMMYURR, MOD_SIBE)
compatible_code(MOD_DUMMYSIBE=MOD_SIBE )
task_module_map(INDX_DUMMYURR, MOD_USIME)
compatible_code(MOD_DUMMYUSIME=MOD_USIME)
task_module_map(INDX_DUMMYURR, MOD_RRCE)
compatible_code(MOD_DUMMYRRCE=MOD_RRCE)
task_module_map(INDX_DUMMYURR, MOD_SLCE)
compatible_code(MOD_DUMMYSLCE=MOD_SLCE)
task_module_map(INDX_DUMMYURR, MOD_ADR)
compatible_code(MOD_DUMMYADR=MOD_ADR)
task_module_map(INDX_DUMMYURR, MOD_URR)
compatible_code(MOD_DUMMYURR=MOD_URR)
task_module_map(INDX_DUMMYURR, MOD_DB)
compatible_code(MOD_DUMMYDB=MOD_DB)
#endif
/*task's parameters*/
#ifdef __UMTS_TDD128_MODE__
    task_name("URR_TDD")
#else
    task_name("URR_FDD")
#endif
task_queue_name("URR Q")
task_priority(TASK_PRIORITY_URR , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(3048)
#ifdef URR_NOT_PRESENT
null_task_create_entry(NULL)
#else
task_create_function(urr_create)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(20)
task_internal_queue_size(40)
task_boot_mode(NORMAL_M)
#endif
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
/*task_indx_type*/
#ifdef  __UMTS_RAT__
task_index(INDX_UL2) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_UL2,MOD_DUMMY_UL2)
/*module_type and mod_task_g*/
#ifndef DUMMY_PROTOCOL
task_module_map(INDX_UL2, MOD_URLC)
task_module_map(INDX_UL2, MOD_UMAC)
task_module_map(INDX_UL2, MOD_UL2)
task_module_map(INDX_UL2, MOD_SEQ)
#else
task_module_map(INDX_DUMMYURR, MOD_URLC)
compatible_code(MOD_DUMMYURLC=MOD_URLC)
task_module_map(INDX_DUMMYURR, MOD_UMAC)
compatible_code(MOD_DUMMYUMAC=MOD_UMAC)
task_module_map(INDX_DUMMYURR, MOD_UL2)
compatible_code(MOD_DUMMYUL2=MOD_UL2)
task_module_map(INDX_DUMMYURR, MOD_SEQ)
compatible_code(MOD_DUMMYSEQ=MOD_SEQ)
#endif

/*task's parameters*/
#ifdef __UMTS_TDD128_MODE__
    task_name("UL2_TDD")
#else
    task_name("UL2_FDD")
#endif
task_queue_name("UL2 Q")
task_priority(TASK_PRIORITY_UL2 , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(3280)
#ifdef URR_NOT_PRESENT
null_task_create_entry(NULL)
#else
task_create_function(ul2_create)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(40)
task_internal_queue_size(30)
task_boot_mode(NORMAL_M)
#endif
/*************************Task CFG END******************/
/*************************Task CFG Begin****************/
#if defined(__UMTS_RAT__) && defined(DUMMY_PROTOCOL)
/*task_indx_type*/
task_index(INDX_DUMMYURR) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_DUMMYURR,MOD_DUMMY_DUMMYURR)
/*module_type and mod_task_g*/
 
/*task's parameters*/
task_name("DUMMYURR")
task_queue_name("DUMMYURR Q")
task_priority(TASK_PRIORITY_URR , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(31*1024)
task_create_function(dummyurr_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(35)
task_boot_mode(NORMAL_M)
#endif
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#ifdef  __UMTS_RAT__
/*task_indx_type*/
task_index(INDX_UL2D) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_UL2D,MOD_DUMMY_UL2D)
/*module_type and mod_task_g*/
task_module_map(INDX_UL2D, MOD_DRLC)
task_module_map(INDX_UL2D, MOD_BMC)
task_module_map(INDX_UL2D, MOD_PDCP)
task_module_map(INDX_UL2D, MOD_RABM)
task_module_map(INDX_UL2D, MOD_CSR)
task_module_map(INDX_UL2D, MOD_UL2D)
    
/*task's parameters*/
#ifdef __UMTS_TDD128_MODE__
    task_name("UL2D_TDD")
#else
    task_name("UL2D_FDD")
#endif
task_queue_name("UL2D Q")
task_priority(TASK_PRIORITY_UL2D , TASK_PRIORITY_UL2D_2ND)
task_stack_size(2856)
#ifdef UL2D_NOT_PRESENT
null_task_create_entry(NULL)
#else
task_create_function(ul2d_create)
#endif
task_stack_internalRAM(KAL_FALSE)
#ifdef __RLC_HSDPA_COPRO__
task_external_queue_size(100)
#else
task_external_queue_size(40)
#endif
task_internal_queue_size(INT_Q_LEN)
task_boot_mode(NORMAL_M)
#endif
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#if defined(__UMTS_RAT__) && defined(__UMTS_FDD_MODE__)
/*task_indx_type*/
task_index(INDX_UL1) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_UL1,MOD_DUMMY_UL1)
/*module_type and mod_task_g*/
task_module_map(INDX_UL1, MOD_UL1)
#if !defined(__MTK_TARGET__)
task_module_map(INDX_UL1, MOD_UL1D)
#endif

/*task's parameters*/
#if !defined(DUMMYL1)
task_name("UL1")
task_queue_name("UL1 Q")
#else
task_name("DUMMYUL1")
task_queue_name("DUMMYUL1 Q")
#endif
task_priority(TASK_PRIORITY_UL1 , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(2800)
#ifdef UL1_NOT_PRESENT
null_task_create_entry(NULL)
#else
task_create_function(ul1_create)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(10)
task_boot_mode(NORMAL_M)
#endif
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#if defined(__UMTS_RAT__) && defined(__UMTS_FDD_MODE__) \
&& !defined(__MTK_TARGET__) && !defined(__UE_SIMULATOR__)
/*task_indx_type*/
task_index(INDX_UL1C) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_UL1C,MOD_DUMMY_UL1C)
/*module_type and mod_task_g*/
task_module_map(INDX_UL1C, MOD_UL1C)

/*task's parameters*/
task_name("UL1C")
task_queue_name("UL1C Q")
task_priority(TASK_PRIORITY_UL1C , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(25*1024)
#if defined(DUMMYL1) && !defined(__UL1_ON_MNT__)
null_task_create_entry(NULL)
#else
task_create_function(ul1c_create)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#if defined(__UMTS_RAT__) && defined(__UMTS_TDD128_MODE__)
/*task_indx_type*/
task_index(INDX_TL1) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_TL1,MOD_DUMMY_TL1)
/*module_type and mod_task_g*/
task_module_map(INDX_TL1, MOD_TL1)

/*task's parameters*/
task_name("TL1")
task_queue_name("TL1 Q")
task_priority(TASK_PRIORITY_TL1 , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(2832)
#if defined(__DUMMY_TL1__)
task_create_function(dummytl1_create)
#else
task_create_function(tl1_create)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(20)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M | FACTORY_M | USB_M)
#endif
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#if defined(__UMTS_RAT__) && defined(__UMTS_TDD128_MODE__)
/*task_indx_type*/
task_index(INDX_TL1DATA) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_TL1DATA,MOD_DUMMY_TL1DATA)
/*module_type and mod_task_g*/
task_module_map(INDX_TL1DATA, MOD_TL1DATA)

/*task's parameters*/
task_name("TL1DATA")
task_queue_name("TL1DATA Q")
task_priority(TASK_PRIORITY_TL1DATA , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(2832)
#if defined(__DUMMY_TL1__)
task_create_function(dummytl1data_create)
#else
task_create_function(tl1data_create)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M | FACTORY_M | USB_M)
#endif
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#if defined(__GEMINI__)
/*task_indx_type*/
task_index(INDX_RSVA) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_RSVA,MOD_DUMMY_RSVA)
/*module_type and mod_task_g*/
task_module_map(INDX_RSVA, MOD_RSVAS)
#if defined(__UMTS_RAT__)
task_module_map(INDX_RSVA, MOD_RSVAK)
task_module_map(INDX_RSVA, MOD_RSVAU)
#ifdef  __GSM_RAT__
task_module_map(INDX_RSVA, MOD_RSVAG)
#endif
#endif

/*task's parameters*/
task_name("RSVA")
task_queue_name("RSVA Q")
task_priority(TASK_PRIORITY_RSVA , KAL_TASK_INITIAL_PRIORITY )
#if defined(__UMTS_RAT__)
task_stack_size(2500)
#else
task_stack_size(858)
#endif

#if defined(__RSVA_NOT_PRESENT__)
null_task_create_entry(NULL)
#else
task_create_function(rsva_create)
#endif
task_stack_internalRAM(KAL_FALSE)
#if defined(__UMTS_RAT__) 
task_external_queue_size(20)
task_internal_queue_size(35)
#else
task_external_queue_size(10)
task_internal_queue_size(0)
#endif
task_boot_mode(NORMAL_M)
#endif
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
/*task_indx_type*/
task_index(INDX_MM) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_MM,MOD_DUMMY_MM)
/*module_type and mod_task_g*/
task_module_map(INDX_MM, MOD_MM)
#ifdef __GEMINI__
task_module_map(INDX_MM, MOD_MM_2)
#if (GEMINI_PLUS >= 3)
task_module_map(INDX_MM, MOD_MM_3)
#if (GEMINI_PLUS >= 4)
task_module_map(INDX_MM, MOD_MM_4)
#endif /* GEMINI_PLUS >= 4 */
#endif /* GEMINI_PLUS >= 3 */
#endif /* __GEMINI__ */

/*task's parameters*/
#ifdef __UMTS_TDD128_MODE__
    task_name("MM_TDD")
#else
    task_name("MM_FDD")
#endif
task_queue_name("MM Q")
task_priority(TASK_PRIORITY_MM , KAL_TASK_INITIAL_PRIORITY )
#if defined(__LOW_COST_SUPPORT_ULC__)
task_stack_size(1280)
#else
task_stack_size(1672)
#endif
#ifdef MM_NOT_PRESENT
null_task_create_entry(NULL)
#else
task_create_function(mm_create)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(20)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
/*task_indx_type*/
task_index(INDX_CC) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_CC,MOD_DUMMY_CC)
/*module_type and mod_task_g*/
task_module_map(INDX_CC, MOD_CC)
#ifdef __GEMINI__
task_module_map(INDX_CC, MOD_CC_2)
#if (GEMINI_PLUS >= 3)
task_module_map(INDX_CC, MOD_CC_3)
#if (GEMINI_PLUS >= 4)
task_module_map(INDX_CC, MOD_CC_4)
#endif /* GEMINI_PLUS >= 4 */
#endif /* GEMINI_PLUS >= 3 */
#endif /* __GEMINI__ */

/*task's parameters*/
#ifdef __UMTS_TDD128_MODE__
    task_name("CC_TDD")
#else
    task_name("CC_FDD")
#endif
task_queue_name("CC Q")
task_priority(TASK_PRIORITY_CC , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(1080)
#ifdef CC_NOT_PRESENT
null_task_create_entry(NULL)
#else
task_create_function(cc_create)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
/*task_indx_type*/
task_index(INDX_CISS) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_CISS,MOD_DUMMY_CISS)
/*module_type and mod_task_g*/
task_module_map(INDX_CISS, MOD_CISS)
#ifdef __GEMINI__
task_module_map(INDX_CISS, MOD_CISS_2)
#if (GEMINI_PLUS >= 3)
task_module_map(INDX_CISS, MOD_CISS_3)
#if (GEMINI_PLUS >= 4)
task_module_map(INDX_CISS, MOD_CISS_4)
#endif /* GEMINI_PLUS >= 4 */
#endif /* GEMINI_PLUS >= 3 */
#endif /* __GEMINI__ */

/*task's parameters*/
task_name("CISS")
task_queue_name("CISS Q")
task_priority(TASK_PRIORITY_CISS , KAL_TASK_INITIAL_PRIORITY )

task_stack_size(1024)

#ifdef CISS_NOT_PRESENT
null_task_create_entry(NULL)
#else
task_create_function(ciss_create)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
/*task_indx_type*/
task_index(INDX_SMS) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_SMS,MOD_DUMMY_SMS)
/*module_type and mod_task_g*/
task_module_map(INDX_SMS, MOD_SMS)
#ifdef __GEMINI__
task_module_map(INDX_SMS, MOD_SMS_2)
#if (GEMINI_PLUS >= 3)
task_module_map(INDX_SMS, MOD_SMS_3)
#if (GEMINI_PLUS >= 4)
task_module_map(INDX_SMS, MOD_SMS_4)
#endif /* GEMINI_PLUS >= 4 */
#endif /* GEMINI_PLUS >= 3 */
#endif /* __GEMINI__ */

/*task's parameters*/
#ifdef __UMTS_TDD128_MODE__
    task_name("SMS_TDD")
#else
    task_name("SMS_FDD")
#endif
task_queue_name("SMS Q")
task_priority(TASK_PRIORITY_SMS , KAL_TASK_INITIAL_PRIORITY )

task_stack_size(1136)

#ifdef SMS_NOT_PRESENT
null_task_create_entry(NULL)
#else
task_create_function(sms_create)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
/*task_indx_type*/
task_index(INDX_SIM) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_SIM,MOD_DUMMY_SIM)

//this is for code gen 
#if defined(__GEMINI__) && !defined(__LOWCOST_MERGE_TASK__)
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_SIM_2,MOD_DUMMY_SIM_2)
#if (GEMINI_PLUS >= 3)
task_module_map(INDX_SIM_2,MOD_DUMMY_SIM_3)
#endif
#if (GEMINI_PLUS >= 4)
task_module_map(INDX_SIM_2,MOD_DUMMY_SIM_4)
#endif
#endif

/*module_type and mod_task_g*/
task_module_map(INDX_SIM, MOD_SIM)
#if defined(__GEMINI__) && defined(__LOWCOST_MERGE_TASK__)
task_module_map(INDX_SIM, MOD_SIM_2)
#if (GEMINI_PLUS >= 3)
task_module_map(INDX_SIM, MOD_SIM_3)
#if (GEMINI_PLUS >= 4)
task_module_map(INDX_SIM, MOD_SIM_4)
#endif /* GEMINI_PLUS >= 4 */
#endif /* GEMINI_PLUS >= 3 */
#endif /* __GEMINI__ && __LOWCOST_MERGE_TASK__ */

/*task's parameters*/
#ifdef __UMTS_TDD128_MODE__
    task_name("SIM_TDD")
#else
    task_name("SIM_FDD")
#endif
task_queue_name("SIM Q")
task_priority(TASK_PRIORITY_SIM , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(2300)
#ifdef SIM_NOT_PRESENT
null_task_create_entry(NULL)
#else
task_create_function(sim_create)
#endif
task_stack_internalRAM(KAL_FALSE)
#ifdef __GEMINI__
task_external_queue_size(40)
#else
task_external_queue_size(20)
#endif
task_internal_queue_size(3)
task_boot_mode(NORMAL_M | FACTORY_M | USB_M)
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#if defined(__GEMINI__) && !defined(__LOWCOST_MERGE_TASK__)
/*task_indx_type*/
task_index(INDX_SIM_2) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
//task_module_map(INDX_SIM_2,MOD_DUMMY_SIM_2)
/*module_type and mod_task_g*/
task_module_map(INDX_SIM_2, MOD_SIM_2)

/*task's parameters*/
#ifdef __UMTS_TDD128_MODE__
    task_name("SIM_2_TDD")
#else
    task_name("SIM_2_FDD")
#endif
task_queue_name("SIM_2 Q")
task_priority(TASK_PRIORITY_SIM , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(2300)
#if !defined(SIM_NOT_PRESENT) && !defined(__GEMINI_L1_ONLY__)
    /*XXX FIXME sim_create_2 to sim_create when check in*/
task_create_function(sim_create)
#else
null_task_create_entry(NULL)
#endif

task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(40)
task_internal_queue_size(3)
task_boot_mode(NORMAL_M | FACTORY_M)
#endif  /*__GEMINI__  __LOWCOST_MERGE_TASK__ */
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#if defined(__GEMINI__) && !defined(__LOWCOST_MERGE_TASK__)
#if (GEMINI_PLUS >= 3)
/*task_indx_type*/
task_index(INDX_SIM_3) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
//task_module_map(INDX_SIM_3,MOD_DUMMY_SIM_3)
/*module_type and mod_task_g*/
task_module_map(INDX_SIM_3, MOD_SIM_3)

/*task's parameters*/
task_name("SIM_3")
task_queue_name("SIM_3 Q")
task_priority(TASK_PRIORITY_SIM , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(2300)
#if !defined(SIM_NOT_PRESENT) && !defined(__GEMINI_L1_ONLY__)
    /*XXX FIXME sim_create_3 to sim_create when check in*/
task_create_function(sim_create)
#else
null_task_create_entry(NULL)
#endif

task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(40)
task_internal_queue_size(3)
task_boot_mode(NORMAL_M | FACTORY_M)
#endif
#endif /*__GEMINI__  __LOWCOST_MERGE_TASK__  GEMINI_PLUS >= 3*/
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#if defined(__GEMINI__) && !defined(__LOWCOST_MERGE_TASK__)
#if (GEMINI_PLUS >= 4)
/*task_indx_type*/
task_index(INDX_SIM_4) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
//task_module_map(INDX_SIM_4,MOD_DUMMY_SIM_4)
/*module_type and mod_task_g*/
task_module_map(INDX_SIM_4, MOD_SIM_4)

/*task's parameters*/
task_name("SIM_4")
task_queue_name("SIM_4 Q")
task_priority(TASK_PRIORITY_SIM , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(2300)
#if !defined(SIM_NOT_PRESENT) && !defined(__GEMINI_L1_ONLY__)
 /*XXX FIXME sim_create_3 to sim_create when check in*/
task_create_function(sim_create)
#else
null_task_create_entry(NULL)
#endif

task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(40)
task_internal_queue_size(3)
task_boot_mode(NORMAL_M)
#endif
#endif /*__GEMINI__  __LOWCOST_MERGE_TASK__  GEMINI_PLUS >= 3*/
/*************************Task CFG END******************/
/*************************Task CFG Begin****************/
/*task_indx_type*/
task_index(INDX_L4) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_L4,MOD_DUMMY_L4)

/*module_type and mod_task_g*/
task_module_map(INDX_L4, MOD_ATCI)
#ifdef __GEMINI__
task_module_map(INDX_L4, MOD_ATCI_2)
#if (GEMINI_PLUS >= 3)
task_module_map(INDX_L4, MOD_ATCI_3)
#if (GEMINI_PLUS >= 4)
task_module_map(INDX_L4, MOD_ATCI_4)
#endif /* GEMINI_PLUS >= 4 */
#endif /* GEMINI_PLUS >= 3 */
#endif /* __GEMINI__ */

/*module_type and mod_task_g*/
task_module_map(INDX_L4, MOD_MBCI)
#ifdef __GEMINI__
task_module_map(INDX_L4, MOD_MBCI_2)
#if (GEMINI_PLUS >= 3)
task_module_map(INDX_L4, MOD_MBCI_3)
#if (GEMINI_PLUS >= 4)
task_module_map(INDX_L4, MOD_MBCI_4)
#endif /* GEMINI_PLUS >= 4 */
#endif /* GEMINI_PLUS >= 3 */
#endif /* __GEMINI__ */

/*module_type and mod_task_g*/
task_module_map(INDX_L4, MOD_L4C)
#ifdef __GEMINI__
task_module_map(INDX_L4, MOD_L4C_2)
#if (GEMINI_PLUS >= 3)
task_module_map(INDX_L4, MOD_L4C_3)
#if (GEMINI_PLUS >= 4)
task_module_map(INDX_L4, MOD_L4C_4)
#endif /* GEMINI_PLUS >= 4 */
#endif /* GEMINI_PLUS >= 3 */
#endif /* __GEMINI__ */

task_module_map(INDX_L4, MOD_TCM)
#ifdef __GEMINI__
task_module_map(INDX_L4, MOD_TCM_2)
#if (GEMINI_PLUS >= 3)
task_module_map(INDX_L4, MOD_TCM_3)
#if (GEMINI_PLUS >= 4)
task_module_map(INDX_L4, MOD_TCM_4)
#endif /* GEMINI_PLUS >= 4 */
#endif /* GEMINI_PLUS >= 3 */
#endif

/*module_type and mod_task_g*/
task_module_map(INDX_L4, MOD_SMSAL)
#ifdef __GEMINI__
task_module_map(INDX_L4, MOD_SMSAL_2)
#if (GEMINI_PLUS >= 3)
task_module_map(INDX_L4, MOD_SMSAL_3)
#if (GEMINI_PLUS >= 4)
task_module_map(INDX_L4, MOD_SMSAL_4)
#endif /* GEMINI_PLUS >= 4 */
#endif /* GEMINI_PLUS >= 3 */
#endif /* __GEMINI__ */

task_module_map(INDX_L4, MOD_UEM)

/*module_type and mod_task_g*/
task_module_map(INDX_L4, MOD_RAC)
#ifdef __GEMINI__
task_module_map(INDX_L4, MOD_RAC_2)
#if (GEMINI_PLUS >= 3)
task_module_map(INDX_L4, MOD_RAC_3)
#if (GEMINI_PLUS >= 4)
task_module_map(INDX_L4, MOD_RAC_4)
#endif /* GEMINI_PLUS >= 4 */
#endif /* GEMINI_PLUS >= 3 */
#endif /* __GEMINI__ */

/*module_type and mod_task_g*/
task_module_map(INDX_L4, MOD_SMU)
#ifdef __GEMINI__
task_module_map(INDX_L4, MOD_SMU_2)
#if (GEMINI_PLUS >= 3)
task_module_map(INDX_L4, MOD_SMU_3)
#if (GEMINI_PLUS >= 4)
task_module_map(INDX_L4, MOD_SMU_4)
#endif /* GEMINI_PLUS >= 4 */
#endif /* GEMINI_PLUS >= 3 */
#endif /* __GEMINI__ */ 

task_module_map(INDX_L4, MOD_USAT)

/*module_type and mod_task_g*/
task_module_map(INDX_L4, MOD_CSM)
#ifdef __GEMINI__
task_module_map(INDX_L4, MOD_CSM_2)
#if (GEMINI_PLUS >= 3)
task_module_map(INDX_L4, MOD_CSM_3)
#if (GEMINI_PLUS >= 4)
task_module_map(INDX_L4, MOD_CSM_4)
#endif /* GEMINI_PLUS >= 4 */
#endif /* GEMINI_PLUS >= 3 */
#endif /* __GEMINI__ */ 

/*module_type and mod_task_g*/
task_module_map(INDX_L4, MOD_ENG)
#ifdef __GEMINI__
task_module_map(INDX_L4, MOD_ENG_2)
#endif

/*module_type and mod_task_g*/
task_module_map(INDX_L4, MOD_PHB)
#ifdef __GEMINI__
task_module_map(INDX_L4, MOD_PHB_2)
#if (GEMINI_PLUS >= 3)
task_module_map(INDX_L4, MOD_PHB_3)
#if (GEMINI_PLUS >= 4)
task_module_map(INDX_L4, MOD_PHB_4)
#endif /* GEMINI_PLUS >= 4 */
#endif /* GEMINI_PLUS >= 3 */
#endif /* __GEMINI__ */ 

/*task's parameters*/
task_name("L4")
task_queue_name("L4 Q")
task_priority(TASK_PRIORITY_L4 , KAL_TASK_INITIAL_PRIORITY )
#if defined(__LOW_COST_SUPPORT_ULC__)
task_stack_size(3584)
#else
task_stack_size(4448)
#endif
#ifdef L4_NOT_PRESENT
null_task_create_entry(NULL)
#else
task_create_function(l4_create)   
#endif
task_stack_internalRAM(KAL_FALSE)
#if defined(__UMTS_RAT__)
#ifdef __WISDOM_EM__
task_external_queue_size(80) //55 + 14(RR) + 4(SM) + 2(reserve)
#else
task_external_queue_size(60)
#endif /*__WISDOM_EM__*/
#elif defined(__EGPRS_MODE__)|| defined(__WIFI_SUPPORT__)  || (GEMINI_PLUS >= 3) 
#ifdef __WISDOM_EM__
task_external_queue_size(60) //35 + 14(RR) + 4(SM) + 2(reserve)
#else
task_external_queue_size(40)
#endif
#else   /* __EGPRS_MODE__ */
#ifdef __WISDOM_EM__
task_external_queue_size(50) //25 + 14(RR) + 4(SM) + 2(reserve)
#else
task_external_queue_size(30)
#endif            
#endif   /* __UMTS_RAT__ */
task_internal_queue_size(INT_Q_LEN)
task_boot_mode(NORMAL_M | USB_M | FACTORY_M)
/*************************Task CFG END******************/

/************************Task CFG Begin****************/
  /*task_indx_type*/
task_index(INDX_RR) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_RR,MOD_DUMMY_RR)
    /*module_type and mod_task_g*/
task_module_map(INDX_RR, MOD_RRM)
compatible_code(MOD_GAS = MOD_RRM)
compatible_code(MOD_AS = MOD_RRM)
compatible_code(MOD_RMPC = MOD_RRM)
#ifdef __GEMINI__
task_module_map(INDX_RR, MOD_RRM_2)
compatible_code(MOD_GAS_2 = MOD_RRM_2)
compatible_code(MOD_AS_2 = MOD_RRM_2)
compatible_code(MOD_RMPC_2 = MOD_RRM_2)
#if (GEMINI_PLUS >= 3)
task_module_map(INDX_RR, MOD_RRM_3)
compatible_code(MOD_GAS_3 = MOD_RRM_3)
compatible_code(MOD_AS_3 = MOD_RRM_3)
compatible_code(MOD_RMPC_3 = MOD_RRM_3)
#if (GEMINI_PLUS >= 4)
task_module_map(INDX_RR, MOD_RRM_4)
compatible_code(MOD_GAS_4 = MOD_RRM_4)
compatible_code(MOD_AS_4 = MOD_RRM_4)
compatible_code(MOD_RMPC_4 = MOD_RRM_4)
#endif /* GEMINI_PLUS >= 4 */
#endif /* GEMINI_PLUS >= 3 */
#endif /* __GEMINI__ */

#if !defined(DUMMY_PROTOCOL)
task_module_map(INDX_RR, MOD_RLC)
#ifdef __GEMINI__
task_module_map(INDX_RR, MOD_RLC_2)
#if (GEMINI_PLUS >= 3)
task_module_map(INDX_RR, MOD_RLC_3)
#if (GEMINI_PLUS >= 4)
task_module_map(INDX_RR, MOD_RLC_4)
#endif /* GEMINI_PLUS >= 4 */
#endif /* GEMINI_PLUS >= 3 */
#endif /* __GEMINI__ */ 
#else
 task_module_map(INDX_DUMMYRR, MOD_RLC)
#ifdef __GEMINI__
task_module_map(INDX_DUMMYRR, MOD_RLC_2)
#if (GEMINI_PLUS >= 3)
task_module_map(INDX_DUMMYRR, MOD_RLC_3)
#if (GEMINI_PLUS >= 4)
task_module_map(INDX_DUMMYRR, MOD_RLC_4)
#endif /* GEMINI_PLUS >= 4 */
#endif /* GEMINI_PLUS >= 3 */
#endif /* __GEMINI__ */ 
#endif

task_module_map(INDX_RR, MOD_MAC)
#ifdef __GEMINI__
task_module_map(INDX_RR, MOD_MAC_2)
#if (GEMINI_PLUS >= 3)
task_module_map(INDX_RR, MOD_MAC_3)
#if (GEMINI_PLUS >= 4)
task_module_map(INDX_RR, MOD_MAC_4)
#endif /* GEMINI_PLUS >= 4 */
#endif /* GEMINI_PLUS >= 3 */
#endif /* __GEMINI__ */

task_module_map(INDX_RR, MOD_LAPDM)
#ifdef __GEMINI__
task_module_map(INDX_RR, MOD_LAPDM_2)
#if (GEMINI_PLUS >= 3)
task_module_map(INDX_RR, MOD_LAPDM_3)
#if (GEMINI_PLUS >= 4)
task_module_map(INDX_RR, MOD_LAPDM_4)
#endif /* GEMINI_PLUS >= 4 */
#endif /* GEMINI_PLUS >= 3 */
#endif /* __GEMINI__ */

#if !(defined(DUMMY_PROTOCOL) && defined(__GSM_RAT__))
task_module_map(INDX_RR, MOD_MPAL)
#ifdef __GEMINI__
task_module_map(INDX_RR, MOD_MPAL_2)
#if (GEMINI_PLUS >= 3)
task_module_map(INDX_RR, MOD_MPAL_3)
#if (GEMINI_PLUS >= 4)
task_module_map(INDX_RR, MOD_MPAL_4)
#endif /* GEMINI_PLUS >= 4 */
#endif /* GEMINI_PLUS >= 3 */
#endif /* __GEMINI__ */
#endif
    
/*task's parameters*/
#ifdef __UMTS_TDD128_MODE__
    task_name("RR_TDD")
#else
    task_name("RR_FDD")
#endif
task_queue_name("RR Q")
task_priority(TASK_PRIORITY_RR , KAL_TASK_INITIAL_PRIORITY )

#if defined(__EGPRS_MODE__)
task_stack_size(2364)
#elif defined(__PS_SERVICE__)
task_stack_size(1800)
#else
#if defined(__LOW_COST_SUPPORT_ULC__)
task_stack_size(1400)
#else /* __LOW_COST_SUPPORT_ULC__ */
task_stack_size(1536)
#endif /* __LOW_COST_SUPPORT_ULC__ */
#endif

#ifdef RR_NOT_PRESENT
null_task_create_entry(NULL)
#else
task_create_function(rr_create)
#endif

task_stack_internalRAM(KAL_FALSE)

    /* external Q size */
#if defined(__EGPRS_MODE__) || defined(__PS_SERVICE__) || (GEMINI_PLUS_GSM >= 4)
task_external_queue_size(40)
#else
task_external_queue_size(20)
#endif
    /* internal Q size */
#if defined(__UMTS_RAT__) && defined(__GEMINI_MONITOR_PAGE_DURING_TRANSFER__)
task_internal_queue_size(50)
#else
task_internal_queue_size(INT_Q_LEN)
#endif
task_boot_mode(NORMAL_M)
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
/*task_indx_type*/
task_index(INDX_REASM) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_REASM,MOD_DUMMY_REASM)
/*module_type and mod_task_g*/
task_module_map(INDX_REASM, MOD_REASM)
#ifdef __GEMINI__
task_module_map(INDX_REASM, MOD_REASM_2)
#if (GEMINI_PLUS >= 3)
task_module_map(INDX_REASM, MOD_REASM_3)
#if (GEMINI_PLUS >= 4)
task_module_map(INDX_REASM, MOD_REASM_4)
#endif /* GEMINI_PLUS >= 4 */
#endif /* GEMINI_PLUS >= 3 */
#endif /* __GEMINI__ */
/*task's parameters*/
#ifdef __UMTS_TDD128_MODE__
    task_name("REASM_TDD")
#else
    task_name("REASM_FDD")
#endif
task_queue_name("REASM Q")
task_priority(TASK_PRIORITY_REASM , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(1356)
#ifdef REASM_NOT_PRESENT
null_task_create_entry(NULL)
#else
task_create_function(rlc_reasm_create)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
/*task_indx_type*/
task_index(INDX_SNDCP) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_SNDCP,MOD_DUMMY_SNDCP)
/*module_type and mod_task_g*/
task_module_map(INDX_SNDCP, MOD_SNDCP)
#ifdef __GEMINI__
task_module_map(INDX_SNDCP, MOD_SNDCP_2)
#if (GEMINI_PLUS >= 3)
task_module_map(INDX_SNDCP, MOD_SNDCP_3)
#if (GEMINI_PLUS >= 4)
task_module_map(INDX_SNDCP, MOD_SNDCP_4)
#endif /* GEMINI_PLUS >= 4 */
#endif /* GEMINI_PLUS >= 3 */
#endif /* __GEMINI__ */
/*task's parameters*/
task_name("SNDCP")
task_queue_name("SNDCP Q")
task_priority(TASK_PRIORITY_SNDCP , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(1432)
#ifdef SNDCP_NOT_PRESENT
null_task_create_entry(NULL)
#else
task_create_function(snd_create)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(50)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
/*task_indx_type*/
task_index(INDX_SM) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_SM,MOD_DUMMY_SM)
/*module_type and mod_task_g*/
task_module_map(INDX_SM, MOD_SM)
#ifdef __GEMINI__
task_module_map(INDX_SM, MOD_SM_2)
#if (GEMINI_PLUS >= 3)
task_module_map(INDX_SM, MOD_SM_3)
#if (GEMINI_PLUS >= 4)
task_module_map(INDX_SM, MOD_SM_4)
#endif /* GEMINI_PLUS >= 4 */
#endif /* GEMINI_PLUS >= 3 */
#endif /* __GEMINI__ */
/*task's parameters*/
#ifdef __UMTS_TDD128_MODE__
task_name("SM_TDSCDMA")
#else
task_name("SM_WCDMA")
#endif
task_queue_name("SM Q")
task_priority(TASK_PRIORITY_SM , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(1412)
#ifdef SM_NOT_PRESENT
null_task_create_entry(NULL)
#else
task_create_function(sm_create)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
/*task_indx_type*/
task_index(INDX_LLC) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_LLC,MOD_DUMMY_LLC)
/*module_type and mod_task_g*/
task_module_map(INDX_LLC, MOD_LLC)
#ifdef __GEMINI__
task_module_map(INDX_LLC, MOD_LLC_2)
#if (GEMINI_PLUS >= 3)
task_module_map(INDX_LLC, MOD_LLC_3)
#if (GEMINI_PLUS >= 4)
task_module_map(INDX_LLC, MOD_LLC_4)
#endif /* GEMINI_PLUS >= 4 */
#endif /* GEMINI_PLUS >= 3 */
#endif /* __GEMINI__ */
/*task's parameters*/
task_name("LLC")
task_queue_name("LLC Q")
task_priority(TASK_PRIORITY_LLC , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(1964)
#ifdef LLC_NOT_PRESENT
null_task_create_entry(NULL)
#else
task_create_function(llc_create)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(70)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
/*task_indx_type*/
task_index(INDX_DATA) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_DATA,MOD_DUMMY_DATA)
/*module_type and mod_task_g*/
task_module_map(INDX_DATA, MOD_TDT)
#ifdef __GEMINI__
task_module_map(INDX_DATA, MOD_TDT_2)
#if (GEMINI_PLUS >= 3)
task_module_map(INDX_DATA, MOD_TDT_3)
#if (GEMINI_PLUS >= 4)
task_module_map(INDX_DATA, MOD_TDT_4)
#endif /* GEMINI_PLUS >= 4 */
#endif /* GEMINI_PLUS >= 3 */
#endif /* __GEMINI__ */

task_module_map(INDX_DATA, MOD_RLP)
#ifdef __GEMINI__
task_module_map(INDX_DATA, MOD_RLP_2)
#if (GEMINI_PLUS >= 3)
task_module_map(INDX_DATA, MOD_RLP_3)
#if (GEMINI_PLUS >= 4)
task_module_map(INDX_DATA, MOD_RLP_4)
#endif /* GEMINI_PLUS >= 4 */
#endif /* GEMINI_PLUS >= 3 */
#endif /* __GEMINI__ */

task_module_map(INDX_DATA, MOD_L2R)
#ifdef __GEMINI__
task_module_map(INDX_DATA, MOD_L2R_2)
#if (GEMINI_PLUS >= 3)
task_module_map(INDX_DATA, MOD_L2R_3)
#if (GEMINI_PLUS >= 4)
task_module_map(INDX_DATA, MOD_L2R_4)
#endif /* GEMINI_PLUS >= 4 */
#endif /* GEMINI_PLUS >= 3 */
#endif /* __GEMINI__ */

task_module_map(INDX_DATA, MOD_T30)
#ifdef __GEMINI__
task_module_map(INDX_DATA, MOD_T30_2)
#if (GEMINI_PLUS >= 3)
task_module_map(INDX_DATA, MOD_T30_3)
#if (GEMINI_PLUS >= 4)
task_module_map(INDX_DATA, MOD_T30_4)
#endif /* GEMINI_PLUS >= 4 */
#endif /* GEMINI_PLUS >= 3 */
#endif /* __GEMINI__ */

task_module_map(INDX_DATA, MOD_FA)
#ifdef __GEMINI__
task_module_map(INDX_DATA, MOD_FA_2)
#if (GEMINI_PLUS >= 3)
task_module_map(INDX_DATA, MOD_FA_3)
#if (GEMINI_PLUS >= 4)
task_module_map(INDX_DATA, MOD_FA_4)
#endif /* GEMINI_PLUS >= 4 */
#endif /* GEMINI_PLUS >= 3 */
#endif /* __GEMINI__ */


/*task's parameters*/
task_name("DATA")
task_queue_name("DATA Q")
task_priority(TASK_PRIORITY_DATA , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(1024)
#if !defined(CSD_SUPPORT) || defined(IC_BURNIN_TEST) || defined(DATA_NOT_PRESENT)
null_task_create_entry(NULL)
#else
task_create_function(data_create)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(90)
task_internal_queue_size(INT_Q_LEN)
task_boot_mode(NORMAL_M)
/*************************Task CFG END******************/


/*************************Task CFG Begin****************/
#if defined(DUMMY_PROTOCOL) && defined(__GSM_RAT__)
/*task_indx_type*/
task_index(INDX_DUMMYMPAL) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_DUMMYMPAL,MOD_DUMMY_DUMMYMPAL)
/*module_type and mod_task_g*/
task_module_map(INDX_DUMMYMPAL, MOD_DUMMYMPAL)
/*task's parameters*/
task_name("DUMMYMPAL")
task_queue_name("DUMMYMPAL Q")
task_priority(TASK_PRIORITY_DUMMYMPAL , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(4096)
task_create_function(DummyMPAL_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#if defined(DUMMY_PROTOCOL) && defined(__GSM_RAT__)
/*task_indx_type*/
task_index(INDX_DUMMYRR) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_DUMMYRR,MOD_DUMMY_DUMMYRR)
/*module_type and mod_task_g*/
task_module_map(INDX_DUMMYRR, MOD_DUMMYRR)
/*task's parameters*/
task_name("DUMMYRR")
task_queue_name("DUMMYRR Q")
task_priority(TASK_PRIORITY_DUMMYRR , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(4096)
task_create_function(DummyRR_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
/*task_indx_type*/
#ifdef DUMMYL1
task_index(INDX_DUMMYL1) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_DUMMYL1,MOD_DUMMY_DUMMYL1)
//this is for codegen
#if  defined(DUMMYL1) && defined(__GEMINI_GSM__)
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_DUMMYL1_2,MOD_DUMMY_DUMMYL1_2)
#if (GEMINI_PLUS_GSM >= 3)
task_module_map(INDX_DUMMYL1_3,MOD_DUMMY_DUMMYL1_3)
#endif
#if (GEMINI_PLUS_GSM >= 4)
task_module_map(INDX_DUMMYL1_4,MOD_DUMMY_DUMMYL1_4)
#endif
#endif

/*task's parameters*/
task_name("DUMMYL1")
task_queue_name("DUMMYL1 Q")
task_priority(TASK_PRIORITY_L1 , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(1024)
task_create_function(dummyl1_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif
/*************************Task CFG END******************/
/*************************Task CFG Begin****************/
/*task_indx_type*/
#if  defined(DUMMYL1) && defined(__GEMINI_GSM__)
task_index(INDX_DUMMYL1_2) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
//task_module_map(INDX_DUMMYL1_2,MOD_DUMMY_DUMMYL1_2)

/*task's parameters*/
task_name("DUMMYL1_2")
task_queue_name("DUMMYL1_2 Q")
task_priority(TASK_PRIORITY_L1 , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(1024)
task_create_function(dummyl1_create_2)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif
/*************************Task CFG END******************/
/*************************Task CFG Begin****************/
/*task_indx_type*/
#if defined(DUMMYL1) && defined(__GEMINI_GSM__)
#if (GEMINI_PLUS_GSM >= 3)
task_index(INDX_DUMMYL1_3) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
//task_module_map(INDX_DUMMYL1_3,MOD_DUMMY_DUMMYL1_3)

/*task's parameters*/
task_name("DUMMYL1_3")
task_queue_name("DUMMYL1_3 Q")
task_priority(TASK_PRIORITY_L1 , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(1024)
task_create_function(dummyl1_create_3)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif
#endif
/*************************Task CFG END******************/
/*************************Task CFG Begin****************/
/*task_indx_type*/
#if defined(DUMMYL1) && defined(__GEMINI_GSM__)
#if (GEMINI_PLUS_GSM >= 4)
task_index(INDX_DUMMYL1_4) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
//task_module_map(INDX_DUMMYL1_4,MOD_DUMMY_DUMMYL1_4)

/*task's parameters*/
task_name("DUMMYL1_4")
task_queue_name("DUMMYL1_4 Q")
task_priority(TASK_PRIORITY_L1 , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(1024)
task_create_function(dummyl1_create_4)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif
#endif
/*************************Task CFG END******************/


/*************************Task CFG Begin****************/
/*task_indx_type*/
task_index(INDX_L1) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_L1,MOD_DUMMY_L1)
/*module_type and mod_task_g*/
#ifdef __GEMINI_GSM__
//this is for codegen
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_L1_2,MOD_DUMMY_L1_2)
#if (GEMINI_PLUS_GSM >= 3)
task_module_map(INDX_L1_2,MOD_DUMMY_L1_3)
#endif
#if (GEMINI_PLUS_GSM >= 4)
task_module_map(INDX_L1_2,MOD_DUMMY_L1_4)
#endif
#endif

#ifdef DUMMYL1
task_module_map(INDX_DUMMYL1, MOD_L1)
#else
task_module_map(INDX_L1, MOD_L1)
#endif
#ifdef L1A_SIM
task_module_map(INDX_L1, MOD_L1C)
#endif
/*task's parameters*/
task_name("L1")
task_queue_name("L1 Q")
task_priority(TASK_PRIORITY_L1 , KAL_TASK_INITIAL_PRIORITY )
#if defined(__UMTS_RAT__)
task_stack_size(1536)
#else   /* __UMTS_RAT__ */
task_stack_size(1024)
#endif   /* __UMTS_RAT__ */
#ifdef L1_NOT_PRESENT
null_task_create_entry(NULL)
#else
task_create_function(l1_create)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M | USB_M)
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#ifdef __GEMINI_GSM__
 /*task_indx_type*/
task_index(INDX_L1_2) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
//task_module_map(INDX_L1_2,MOD_DUMMY_L1_2)
/*module_type and mod_task_g*/
#ifdef DUMMYL1
task_module_map(INDX_DUMMYL1_2, MOD_L1_2)
#else
task_module_map(INDX_L1_2, MOD_L1_2)
#endif
#ifdef L1A_SIM
task_module_map(INDX_L1_2, MOD_L1C_2)
#endif
/*task's parameters*/
task_name("L1_2")
task_queue_name("L1_2 Q")
task_priority(TASK_PRIORITY_L1 , KAL_TASK_INITIAL_PRIORITY )
#if defined(__UMTS_RAT__)
task_stack_size(1536)
#else   /* __UMTS_RAT__ */
task_stack_size(1024)
#endif   /* __UMTS_RAT__ */
#ifdef L1_NOT_PRESENT
null_task_create_entry(NULL)
#else
task_create_function(l1_create_2)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#ifdef __GEMINI_GSM__
#if (GEMINI_PLUS_GSM >= 3)
/*task_indx_type*/
task_index(INDX_L1_3) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
//task_module_map(INDX_L1_3,MOD_DUMMY_L1_3)
/*module_type and mod_task_g*/
#ifdef DUMMYL1
task_module_map(INDX_DUMMYL1_3, MOD_L1_3)
#else
task_module_map(INDX_L1_3, MOD_L1_3)
#endif

#ifdef L1A_SIM
task_module_map(INDX_L1_3, MOD_L1C_3)
#endif
/*task's parameters*/
task_name("L1_3")
task_queue_name("L1_3 Q")
task_priority(TASK_PRIORITY_L1 , KAL_TASK_INITIAL_PRIORITY )
#if defined(__UMTS_RAT__)
task_stack_size(1536)
#else   /* __UMTS_RAT__ */
task_stack_size(1024)
#endif   /* __UMTS_RAT__ */
#ifdef L1_NOT_PRESENT
null_task_create_entry(NULL)
#else
task_create_function(l1_create_3)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif
#endif
/*************************Task CFG END******************/


/*************************Task CFG Begin****************/
#ifdef __GEMINI_GSM__
#if (GEMINI_PLUS_GSM >= 4)
/*task_indx_type*/
task_index(INDX_L1_4) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
//task_module_map(INDX_L1_4,MOD_DUMMY_L1_4)
/*module_type and mod_task_g*/
#ifdef DUMMYL1
task_module_map(INDX_DUMMYL1_4, MOD_L1_4)
#else
task_module_map(INDX_L1_4, MOD_L1_4)
#endif
#ifdef L1A_SIM
task_module_map(INDX_L1_4, MOD_L1C_4)
#endif
/*task's parameters*/
task_name("L1_4")
task_queue_name("L1_4 Q")
task_priority(TASK_PRIORITY_L1 , KAL_TASK_INITIAL_PRIORITY )
#if defined(__UMTS_RAT__)
task_stack_size(1536)
#else   /* __UMTS_RAT__ */
task_stack_size(1024)
#endif   /* __UMTS_RAT__ */
#ifdef L1_NOT_PRESENT
null_task_create_entry(NULL)
#else
task_create_function(l1_create_4)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif
#endif
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
/*task_indx_type*/
task_index(INDX_EXT_MODEM)       /* GSM+CDMA external modem Project */
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_EXT_MODEM,MOD_DUMMY_EXT_MODEM)
/*module_type and mod_task_g*/
task_module_map(INDX_EXT_MODEM, MOD_EXT_MODEM)

/*task's parameters*/
task_name("EXT_MODEM")
task_queue_name("EXT_MODEM Q")
task_priority(TASK_PRIORITY_EXT_MODEM , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(1024)
#ifdef __EXT_MODEM__
task_create_function(ext_modem_create)
#else
null_task_create_entry(NULL)
#endif

task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(90)
task_internal_queue_size(INT_Q_LEN)
task_boot_mode(NORMAL_M)
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#if defined(__MTK_UL1_FDD__)
/*task_indx_type*/
task_index(INDX_UL1TST) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_UL1TST,MOD_DUMMY_UL1TST)
/*module_type and mod_task_g*/
task_module_map(INDX_UL1TST, MOD_UL1TST)

/*task's parameters*/
task_name("UL1TST")
task_queue_name("UL1TST Q")

task_priority(TASK_PRIORITY_UL1TST , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(3072)
#if defined(__MTK_TARGET__)
task_create_function(ul1tst_create)
#else
null_task_create_entry(NULL)
#endif 
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(FACTORY_M)
#endif
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#if defined(__UAGPS_UP_SUPPORT__) || defined(__UAGPS_CP_SUPPORT__)
    /*task_indx_type*/
task_index(INDX_ULCS)            /*3G AGPS position location*/ 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_ULCS,MOD_DUMMY_ULCS)
/*module_type and mod_task_g*/
task_module_map(INDX_ULCS, MOD_UAGPS)
#if defined __UAGPS_UP_SUPPORT__
task_module_map(INDX_ULCS, MOD_UAGPS_UP)
#endif
#if defined __UAGPS_CP_SUPPORT__ 
task_module_map(INDX_ULCS, MOD_UAGPS_CP)
#endif
/*task's parameters*/
task_name("ULCS")
task_queue_name("ULCS Q")
task_priority(TASK_PRIORITY_ULCS , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(3112)
task_create_function(ulcs_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(20)
task_internal_queue_size(10)
task_boot_mode(NORMAL_M)
#endif
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#if defined(__UE_SIMULATOR__)
#if defined(__MTK_UL1_FDD__)
/*task_indx_type*/
task_index(INDX_L1SIM_MAIN_TASK) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_L1SIM_MAIN_TASK,MOD_DUMMY_L1SIM_MAIN_TASK)
/*module_type and mod_task_g*/
task_module_map(INDX_L1SIM_MAIN_TASK, MOD_L1SIM_MAIN_TASK)

/*task's parameters*/
task_name("L1SIM_MAIN_TASK")
task_queue_name("L1SIM_MAIN_TASK Q")

task_priority(KAL_PRIORITY_CLASS0+4 , KAL_TASK_INITIAL_PRIORITY )  /* check !!!! */
task_stack_size(1024)
task_create_function(L1SIM_main_Task_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(20)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif
#endif /* __UE_SIMULATOR__ */
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#if defined(__UE_SIMULATOR__)
#if defined(__MTK_UL1_FDD__)
/*task_indx_type*/
task_index(INDX_PROCCPU_TASK) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_PROCCPU_TASK,MOD_DUMMY_PROCCPU_TASK)
/*module_type and mod_task_g*/
task_module_map(INDX_PROCCPU_TASK, MOD_PROCCPU_TASK)

/*task's parameters*/
task_name("PROCCPU_TASK")
task_queue_name("PROCCPU_TASK Q")

task_priority(KAL_PRIORITY_CLASS0+5 , KAL_TASK_INITIAL_PRIORITY )  /* check !!!! */
task_stack_size(1024)
task_create_function(ProcCPU_Task_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(20)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif
#endif /* __UE_SIMULATOR__ */
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#if defined(__UE_SIMULATOR__)
#if defined(__MTK_UL1_FDD__)
/*task_indx_type*/
task_index(INDX_UEGW_TASK) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_UEGW_TASK,MOD_DUMMY_UEGW_TASK)
/*module_type and mod_task_g*/
task_module_map(INDX_UEGW_TASK, MOD_UEGW_TASK)

/*task's parameters*/
task_name("UEGW_TASK")
task_queue_name("UEGW_TASK Q")

task_priority( KAL_PRIORITY_CLASS23 , KAL_TASK_INITIAL_PRIORITY )  /* check !!!! */
task_stack_size(1024)
task_create_function(Uegw_Task_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(20)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif
#endif /* __UE_SIMULATOR__ */
/*************************Task CFG END******************/



#if defined(__UMTS_RAT__) && defined(__MTK_UL1_FDD__)
MODULE_ID_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM(MOD_UL1HISR)
#endif 
#if !defined(__GEMINI__) && defined(L1A_SIM)
MODULE_ID_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM(MOD_RSVAS)
#endif

#ifdef __UE_SIMULATOR__
MODULE_ID_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM(MOD_HWSIM_HISR)
MODULE_ID_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM(MOD_MTECMD_HISR)
#endif

MODULE_ID_FOR_PRINT_TRACE(MOD_RFC2507)


/**** customer added task or module id is started  *****/

/**** customer added task or module id is ended    *****/


/*************************Task CFG Begin****************/
/*task_indx_type*/
/* this is a fake task for task id grouping*/
task_index(TASK_ID_MODEM_2G3G_CODE_TAIL)
/*module_type and mod_task_g*/
task_module_map(TASK_ID_MODEM_2G3G_CODE_TAIL, MODULE_TAG_MODEM_DUMMY_TAIL)
/*task's parameters*/
task_name("")
task_queue_name("")
task_priority(0 , KAL_TASK_INITIAL_PRIORITY)
task_stack_size(0)
null_task_create_entry(NULL)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(0)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
/*************************Task CFG END******************/
/**********************   Modem End   ********************/  

#endif /*TASK_PRIORITY_MACRO*/
