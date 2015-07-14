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


#define TASK_PRIORITY_NVRAM        (KAL_PRIORITY_CLASS20 + 6)

#if !defined(KAL_ON_OSCAR)
#define TASK_PRIORITY_TSTR         (KAL_PRIORITY_CLASS11 + 8)
#endif
#define TASK_PRIORITY_EXCEP_TEST   (KAL_PRIORITY_CLASS24 + 6)

#define TASK_PRIORITY_FS           (KAL_PRIORITY_CLASS24 + 0)
#define TASK_PRIORITY_TST_FTRANS   (KAL_PRIORITY_CLASS25 + 1)
#if defined(KAL_ON_OSCAR)
#define TASK_PRIORITY_TST          (KAL_PRIORITY_CLASS25 + 3)
#define TASK_PRIORITY_TSTR         (KAL_PRIORITY_CLASS25 + 4)
#else
#define TASK_PRIORITY_TST          (KAL_PRIORITY_CLASS25 + 3)
#endif /* KAL_ON_OSCAR */


#else
/*module id are divided into 3 parts. 
 * 1: module id that maps to task
 * 2: module id that maps to no task but can be used as src module id
 * to allocate ilm, like HISR's module id
 * 3: module id that is used to print trace only.  * */


/*************************Task CFG Begin****************/
/*task_indx_type*/
task_index(INDX_NIL = TASK_ID_SRV_CODE_BEGIN)
/*module_type and mod_task_g*/
/*task_module_map(INDX_NIL, MOD_NIL=0)*/
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_NIL, MOD_DUMMY_NIL = MOD_ID_SRV_CODE_BEGIN)

/*task's parameters*/
task_name("")
task_queue_name("")
task_priority(0 , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(0)
null_task_create_entry(NULL)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(0)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
/*NVRAM must be the first created task, this is restricted by L1 */
/*task_indx_type*/
task_index(INDX_NVRAM) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_NVRAM,MOD_DUMMY_NVRAM)
/*module_type and mod_task_g*/
task_module_map(INDX_NVRAM, MOD_NVRAM)

/*task's parameters*/
task_name("NVRAM")
task_queue_name("NVRAM Q")
task_priority(TASK_PRIORITY_NVRAM , KAL_TASK_INITIAL_PRIORITY )
#if defined(__LOW_COST_SUPPORT_ULC__)
task_stack_size(1988)
#elif defined(LOW_COST_SUPPORT)
task_stack_size(2876)
#else
task_stack_size(2176)
#endif /* LOW_COST_SUPPORT */

#ifdef NVRAM_NOT_PRESENT  /*XXX Note: It's best to wrap the whole section with this*/
null_task_create_entry(NULL)
#else
task_create_function(nvram_create)
#endif

task_stack_internalRAM(KAL_FALSE)

task_external_queue_size(30)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M | FACTORY_M | USB_M)
/*************************Task CFG END******************/

/*************************Task CFG Begin******************/
#ifdef __TST_MODULE__
/*task_indx_type*/
task_index(INDX_TST) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_TST,MOD_DUMMY_TST)
/*module_type and mod_task_g*/
task_module_map(INDX_TST, MOD_TST)

//task's parameters
task_name("TST")
task_queue_name("TST Q")
task_priority(TASK_PRIORITY_TST , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(908)
task_create_function(tst_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(0)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M | FACTORY_M | USB_M)
#endif /*__TST_MODULE__*/
/*************************Task CFG END******************/

/*************************Task CFG Begin******************/
#ifdef __TST_MODULE__
/*task_indx_type*/
task_index(INDX_TST_READER) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_TST_READER,MOD_DUMMY_TST_READER)
/*module_type and mod_task_g*/
task_module_map(INDX_TST_READER, MOD_TST_READER)
/* fix MOD_TST_READER=3, this is restricted by META tool */

//task's parameters
task_name("TR")
task_queue_name("TR Q")
task_priority(TASK_PRIORITY_TSTR , 1 )
#if defined(LOW_COST_SUPPORT) && !defined(__AUTO_TCL__)
task_stack_size(1920)
#else
task_stack_size(2304)
#endif
task_create_function(tst_reader_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M | FACTORY_M | USB_M)
#endif /*__TST_MODULE__*/
/*************************Task CFG END******************/

/*************************Task CFG Begin******************/
#ifdef __TST_MODULE__ 
 /*task_indx_type*/
task_index(INDX_TST_FTRANS) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_TST_FTRANS,MOD_DUMMY_TST_FTRANS)
/*module_type and mod_task_g*/

task_module_map(INDX_TST_FTRANS, MOD_TST_FTRANS)

//task's parameters
task_name("TFT")
task_queue_name("TFile Q")
task_priority(TASK_PRIORITY_TST_FTRANS , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(2048)
#ifdef  __TST_WRITE_TO_FILE__
task_create_function(tst_file_transferrer_create)
#else
null_task_create_entry(NULL)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif /*__TST_MODULE__*/
/*************************Task CFG END******************/

/******!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!****/
/******!!!!DON NOT add new task before this line !!*****/
/******!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!****/

/*************************Task CFG Begin****************/
/*task_indx_type*/

task_index(INDX_FS)  
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_FS,MOD_DUMMY_FS)
task_module_map(INDX_FS, MOD_FS)
/*task's parameters*/
task_name("FS")
task_queue_name("FS Q")
task_priority(TASK_PRIORITY_FS , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(2500)
#if (defined(__FS_BENCHMARK__) || defined(__FS_ASYNC_SUPPORT__)) && \
    (defined(__MTK_TARGET__) || defined(__FS_MODIS_FDM__))
task_create_function(fst_create)
#else
null_task_create_entry(NULL)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(30)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
/*************************Task CFG END******************/


/*************************Task CFG Begin****************/
/*task_indx_type*/
task_index(INDX_EX_TEST) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_EX_TEST, MOD_DUMMY_EXTEST)
task_module_map(INDX_EX_TEST, MOD_EXTEST)
/*task's parameters*/
task_name("EX_TEST")
task_queue_name("EX_TEST Q")
task_priority(TASK_PRIORITY_EXCEP_TEST, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(2048)
#if defined(__MTK_TARGET__) && defined(__EXCEP_TEST__)
task_create_function(excep_task_create)
#else
null_task_create_entry(NULL)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(20)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
/*************************Task CFG END******************/


#ifndef __TST_MODULE__
MODULE_ID_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM(MOD_TST)
MODULE_ID_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM(MOD_TST_READER)
MODULE_ID_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM(MOD_TST_FTRANS)
#endif
MODULE_ID_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM(MOD_TIMER)

MODULE_ID_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM(MOD_SYSTEM)
MODULE_ID_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM(MOD_EVENT_INFO)

MODULE_ID_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM(MOD_FLC)


// print trace module id is not in mod_task_g 
MODULE_ID_FOR_PRINT_TRACE(MOD_SST_COMMON)


/**** customer added task or module id is started  *****/

/**** customer added task or module id is ended    *****/


/*************************Task CFG Begin****************/
/*task_indx_type*/
/* this is a fake task for task id grouping*/
task_index(TASK_ID_SRV_CODE_TAIL)
/*module_type and mod_task_g*/
task_module_map(TASK_ID_SRV_CODE_TAIL, MODULE_TAG_SRV_TAIL) 

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

#endif /*TASK_PRIORITY_MACRO*/
