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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef TASK_PRIORITY_MACRO
/*Put tasks for debug and test purpose only together to save priority*/
/*if debug_leak*/
#define TASK_PRIORITY_SSDEBUG      (KAL_PRIORITY_CLASS0+5)
#if defined(__RTL_SIMULATION_FOR_60QBIT__)
#define TASK_PRIORITY_SIM60QBIT         (KAL_PRIORITY_CLASS0 + 5)
#endif  /* __RTL_SIMULATION_FOR_60QBIT__ */

#ifdef MTK_SYSSERV_DEBUG
#define TASK_PRIORITY_SSDBG1        KAL_PRIORITY_CLASS5
#define TASK_PRIORITY_SSDBG2        KAL_PRIORITY_CLASS5
#endif /* MTK_SYSSERV_DEBUG */


#if defined(__MEUT__)
#define TASK_PRIORITY_MEUT              KAL_PRIORITY_CLASS5
#define TASK_PRIORITY_COMMTASK          (KAL_PRIORITY_CLASS5+2)
#define TASK_PRIORITY_SEQTASK           (KAL_PRIORITY_CLASS6+3)
#define TASK_PRIORITY_DVT_GPT           (KAL_PRIORITY_CLASS6+3)
#define TASK_PRIORITY_TST_PWM	        (KAL_PRIORITY_CLASS6+3)
#define TASK_PRIORITY_DVT_RTC		    (KAL_PRIORITY_CLASS6+3)
#define TASK_PRIORITY_DVT_I2C	        (KAL_PRIORITY_CLASS6+3)
#define TASK_PRIORITY_DVT_SIM		    (KAL_PRIORITY_CLASS6+3)
#define TASK_PRIORITY_TST_RGU	        (KAL_PRIORITY_CLASS6+3)
#define TASK_PRIORITY_DVT_TS		    (KAL_PRIORITY_CLASS6+3)
#define TASK_PRIORITY_DVT_ADC		    (KAL_PRIORITY_CLASS6+3)
#define TASK_PRIORITY_DVT_UART          (KAL_PRIORITY_CLASS6+3)
#define TASK_PRIORITY_DVT_USB	        (KAL_PRIORITY_CLASS6+3)
#define TASK_PRIORITY_DVT_PMU           (KAL_PRIORITY_CLASS6+3)
#endif  /* __MEUT__ */
/*Put tasks for debug and test purpose only together to save priority*/

#define TASK_PRIORITY_FT           (KAL_PRIORITY_CLASS0 + 6)


#if !defined(__VT_TRANSPORT_SUPPORT__)
#define TASK_PRIORITY_VT           (KAL_PRIORITY_CLASS6 + 2)
#endif

#if defined(__VT_TRANSPORT_SUPPORT__)
#define TASK_PRIORITY_VT           (KAL_PRIORITY_CLASS7 + 7)
#endif


#define TASK_PRIORITY_FTA          (KAL_PRIORITY_CLASS8 + 2)

#define TASK_PRIORITY_FTC          (KAL_PRIORITY_CLASS8 + 4)
/* L4 & FTC run in different boot mode */
#define TASK_PRIORITY_LBS          (KAL_PRIORITY_CLASS10 + 6)


#define TASK_PRIORITY_UPS          (KAL_PRIORITY_CLASS21 + 4)
#define TASK_PRIORITY_PPP          (KAL_PRIORITY_CLASS22 + 2)
#define TASK_PRIORITY_PPP_GPRS      TASK_PRIORITY_PPP


#else
/*module id are divided into 3 parts. 
 * 1: module id that maps to task
 * 2: module id that maps to no task but can be used as src module id
 * to allocate ilm, like HISR's module id
 * 3: module id that is used to print trace only.  * */

/*************************Task CFG Begin****************/
/*task_indx_type*/

/* this is a fake task for task id grouping*/
task_index(INDX_MW_START = TASK_ID_MW_CODE_BEGIN)
/*module_type and mod_task_g*/
task_module_map(INDX_MW_START, MOD_MW_DUMMY_BEGIN = MOD_ID_MIDDLEWARE_CODE_BEGIN)
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

/*************************Task CFG Begin****************/
/*task_indx_type*/
task_index(INDX_PPP) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_PPP,MOD_DUMMY_PPP)
/*module_type and mod_task_g*/
task_module_map(INDX_PPP, MOD_PPP)

/*task's parameters*/
task_name("PPP")
task_queue_name("PPP Q")
task_priority(TASK_PRIORITY_PPP , KAL_TASK_INITIAL_PRIORITY )
#if defined(__3G_NEW_DATA_PLANE_ARCH__)
task_stack_size(2340)
#else
task_stack_size(1340)
#endif
#if !defined(PPP_NOT_PRESENT)
task_create_function(ppp_create)
#else
null_task_create_entry(NULL)    
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(100)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
/*task_indx_type*/
/*ups is a new design of data path in Andorid modem project. The PS data 
 * patch handling is divided from cmux into ups for better efficiency. 
 * Now ups only interacts with TCM and CCCI uart interfaces*/
task_index(INDX_UPS)            /*WAP ps task*/ 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_UPS,MOD_DUMMY_UPS)
/*module_type and mod_task_g*/
task_module_map(INDX_UPS, MOD_UPS)

#ifdef __MBIM_SUPPORT__
task_module_map(INDX_UPS, MOD_MBIM)
#endif

/*task's parameters*/
task_name("UPS")
task_queue_name("UPS Q")
task_priority(TASK_PRIORITY_UPS , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(1228)
#if defined(__UPS_SUPPORT__) || defined(__MBIM_SUPPORT__)
task_create_function(ups_create)
#else
null_task_create_entry(NULL)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(100)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#ifdef MTK_SYSSERV_DEBUG
/*task_indx_type*/
task_index(INDX_SSDBG1) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_SSDBG1,MOD_DUMMY_SSDBG1)
#ifdef MTK_SYSSERV_DEBUG
//this is for codegen
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_SSDBG2,MOD_DUMMY_SSDBG2)
#endif

/*module_type and mod_task_g*/
task_module_map(INDX_SSDBG1, MOD_SSDBG1)

/*task's parameters*/
task_name("SSDBG1")
task_queue_name("SSDBG1 Q")
task_priority(TASK_PRIORITY_SSDBG1 , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(1536)
task_create_function(ssdbg1_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#ifdef MTK_SYSSERV_DEBUG
/*task_indx_type*/
task_index(INDX_SSDBG2) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
//task_module_map(INDX_SSDBG2,MOD_DUMMY_SSDBG2)
/*module_type and mod_task_g*/
task_module_map(INDX_SSDBG2, MOD_SSDBG2)

/*task's parameters*/
task_name("SSDBG2")
task_queue_name("SSDBG2 Q")
#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__NANDFDM_MULTI_INSTANCE__) \
        && defined(__NAND_FDM_50__) )
task_priority(TASK_PRIORITY_SSDBG1 + 1 , KAL_TASK_INITIAL_PRIORITY )
#else
task_priority(TASK_PRIORITY_SSDBG2 , KAL_TASK_INITIAL_PRIORITY )
#endif
task_stack_size(1536)
#if (defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__NANDFDM_MULTI_INSTANCE__) && \
         defined(__NAND_FDM_50__)) \
    || (!defined (__NAND_FLASH_HARDWARE_TEST__) && !defined (__NOR_FLASH_HARDWARE_TEST__))
task_create_function(ssdbg2_create)
#else
null_task_create_entry(NULL)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#if defined(__MEUT__)
/*task_indx_type*/
task_index(INDX_MEUT) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_MEUT,MOD_DUMMY_MEUT)
/*module_type and mod_task_g*/
task_module_map(INDX_MEUT, MOD_MEUT)

/*task's parameters*/
task_name("MEUT")
task_queue_name("MEUT Q")
task_priority(TASK_PRIORITY_MEUT , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(1024)
task_create_function(meut_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#if defined(__MEUT__)
/*task_indx_type*/
task_index(INDX_COMMTASK) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_COMMTASK,MOD_DUMMY_COMMTASK)
/*module_type and mod_task_g*/
task_module_map(INDX_COMMTASK, MOD_COMMTASK)

/*task's parameters*/
task_name("COMMTASK")
task_queue_name("COMMTASK Q")
task_priority(TASK_PRIORITY_COMMTASK , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(2048)
task_create_function(commtask_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(30)
task_internal_queue_size(10)
task_boot_mode(NORMAL_M)
#endif
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#if defined(__MEUT__)
/*task_indx_type*/
task_index(INDX_SEQTASK) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_SEQTASK,MOD_DUMMY_SEQTASK)
/*module_type and mod_task_g*/
task_module_map(INDX_SEQTASK, MOD_SEQTASK)

/*task's parameters*/
task_name("SEQTASK")
task_queue_name("SEQTASK Q")
task_priority(TASK_PRIORITY_SEQTASK , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(2048)
task_create_function(seqtask_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(30)
task_internal_queue_size(10)
task_boot_mode(NORMAL_M)
#endif
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#if defined(__MEUT__)
/*task_indx_type*/
task_index(INDX_DVT_GPT) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_DVT_GPT,MOD_DUMMY_DVT_GPT)
/*module_type and mod_task_g*/
task_module_map(INDX_DVT_GPT, MOD_DVT_GPT)

/*task's parameters*/
task_name("DVT_GPT_TASK")
task_queue_name("DVT_GPT_TASK Q")
task_priority(TASK_PRIORITY_DVT_GPT , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(1024)
task_create_function(fgDVT_GPT_TaskCreate)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#if defined(__MEUT__)
/*task_indx_type*/
task_index(INDX_TST_PWM) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_TST_PWM,MOD_DUMMY_TST_PWM)
/*module_type and mod_task_g*/
task_module_map(INDX_TST_PWM, MOD_DCLTPWM)

/*task's parameters*/
task_name("PWM_TST_TASK")
task_queue_name("PWM_TST_TASK Q")
task_priority(TASK_PRIORITY_TST_PWM , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(1024)
task_create_function(bPWM_tst_task_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#if defined(__MEUT__)
/*task_indx_type*/
task_index(INDX_DVT_RTC) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_DVT_RTC,MOD_DUMMY_DVT_RTC)
/*module_type and mod_task_g*/
task_module_map(INDX_DVT_RTC, MOD_DVT_RTC)

/*task's parameters*/
task_name("RTCTASK")
task_queue_name("RTCTASK Q")
task_priority(TASK_PRIORITY_DVT_RTC , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(1024)
task_create_function(fgdvt_rtc_task_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#if defined(__MEUT__)
/*task_indx_type*/
task_index(INDX_DVT_I2C) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_DVT_I2C,MOD_DUMMY_DVT_I2C)
/*module_type and mod_task_g*/
task_module_map(INDX_DVT_I2C, MOD_DVT_I2C)

/*task's parameters*/
task_name("DVT_I2C_TASK")
task_queue_name("DVT_I2C_TASK Q")
task_priority(TASK_PRIORITY_DVT_I2C , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(1024)
task_create_function(fgDVT_I2C_TaskCreate)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#if defined(__MEUT__)
/*task_indx_type*/
task_index(INDX_DVT_TST_SIM) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_DVT_TST_SIM,MOD_DUMMY_DVT_TST_SIM)
/*module_type and mod_task_g*/
task_module_map(INDX_DVT_TST_SIM, MOD_DVTSIM)

/*task's parameters*/
task_name("SIM_TST_TASK")
task_queue_name("SIM_TST_TASK Q")
task_priority(TASK_PRIORITY_DVT_SIM , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(2048)
task_create_function(bSim_Testtask_Create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#if defined(__MEUT__)
/*task_indx_type*/
task_index(INDX_TST_RGU) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_TST_RGU,MOD_DUMMY_TST_RGU)
/*module_type and mod_task_g*/
task_module_map(INDX_TST_RGU, MOD_DCLTRGU)

/*task's parameters*/
task_name("RGU_TST_TASK")
task_queue_name("RGU_TST_TASK Q")
task_priority(TASK_PRIORITY_TST_RGU , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(512)
task_create_function(bRGU_tst_task_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif
/*************************Task CFG END******************/


/*************************Task CFG Begin****************/
#if defined(__MEUT__)
/*task_indx_type*/
task_index(INDX_DVT_TS) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_DVT_TS,MOD_DUMMY_DVT_TS)
/*module_type and mod_task_g*/
task_module_map(INDX_DVT_TS, MOD_DVT_TS)

/*task's parameters*/
task_name("DVT_TS_TASK")
task_queue_name("DVT_TS_TASK Q")
task_priority(TASK_PRIORITY_DVT_TS , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(1024)
task_create_function(bDVT_TS_Task_Create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(10)
task_boot_mode(NORMAL_M)
#endif
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#if defined(__MEUT__)
/*task_indx_type*/
task_index(INDX_DVT_ADC) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_DVT_ADC,MOD_DUMMY_DVT_ADC)
/*module_type and mod_task_g*/
task_module_map(INDX_DVT_ADC, MOD_DVT_ADC)

/*task's parameters*/
task_name("DVT_ADC_TASK")
task_queue_name("DVT_ADC_TASK Q")
task_priority(TASK_PRIORITY_DVT_ADC , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(1024)
task_create_function(fgdvt_adc_task_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(10)
task_boot_mode(NORMAL_M)
#endif
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#if defined(__MEUT__)
/*task_indx_type*/
task_index(INDX_DVT_UART) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_DVT_UART,MOD_DUMMY_DVT_UART)
/*module_type and mod_task_g*/
task_module_map(INDX_DVT_UART, MOD_DVT_UART)

/*task's parameters*/
task_name("DVT_UART_TASK")
task_queue_name("DVT_UART_TASK Q")
task_priority(TASK_PRIORITY_DVT_UART , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(1024)
task_create_function(fgDVT_UART_TaskCreate)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#if defined(__MEUT__)
/*task_indx_type*/
task_index(INDX_DVT_USB) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_DVT_USB,MOD_DUMMY_DVT_USB)
/*module_type and mod_task_g*/
task_module_map(INDX_DVT_USB, MOD_DVT_USB)

/*task's parameters*/
task_name("USB_TST_TASK")
task_queue_name("USB_TST_TASK Q")
task_priority(TASK_PRIORITY_DVT_USB , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(512)
task_create_function(usb_task_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif
/*************************Task CFG END******************/



/*************************Task CFG Begin****************/
#if defined(__MEUT__)
/*task_indx_type*/
task_index(INDX_DVT_PMU) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_DVT_PMU,MOD_DUMMY_DVT_PMU)
/*module_type and mod_task_g*/
task_module_map(INDX_DVT_PMU, MOD_DVT_PMU)

/*task's parameters*/
task_name("DVT_PMU_TASK")
task_queue_name("PMU Q")
task_priority(TASK_PRIORITY_DVT_PMU , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(1024)
task_create_function(fgDVT_PMU_Task_Create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#if defined(__RTL_SIMULATION_FOR_60QBIT__)
/*task_indx_type*/
task_index(INDX_SIM60QBIT) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_SIM60QBIT,MOD_DUMMY_SIM60QBIT)
/*module_type and mod_task_g*/
task_module_map(INDX_SIM60QBIT, MOD_SIM60QBIT)

/*task's parameters*/
task_name("SIM60QBIT")
task_queue_name("SIM60QBIT Q")
task_priority(TASK_PRIORITY_SIM60QBIT , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(4096)
task_create_function(sim60qbit_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
/*task_indx_type*/
task_index(INDX_SYSDEBUG) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_SYSDEBUG,MOD_DUMMY_SYSDEBUG)
/*module_type and mod_task_g*/
task_module_map(INDX_SYSDEBUG, MOD_SYSDEBUG)

/*task's parameters*/
task_name("SYSDEBUG")
task_queue_name("SYSDEBUG Q")
task_priority(TASK_PRIORITY_SSDEBUG , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(1024)
#ifdef DEBUG_LEAK
task_create_function(sysdebug_create)
#else
null_task_create_entry(NULL)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
/*task_indx_type*/
task_index(INDX_VT) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_VT,MOD_DUMMY_VT)
/*module_type and mod_task_g*/
task_module_map(INDX_VT, MOD_VT)
/*task's parameters*/
task_name("VT")
task_queue_name("VT Q")
task_priority(TASK_PRIORITY_VT , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(1172)
#ifdef __VIDEO_CALL_SUPPORT__
task_create_function(vt_create)
#else
null_task_create_entry(NULL)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(50)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
/*task_indx_type*/
task_index(INDX_FT) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_FT,MOD_DUMMY_FT)
/*module_type and mod_task_g*/
task_module_map(INDX_FT, MOD_FT)
/*task's parameters*/
task_name("FT")
task_queue_name("FT Q")
task_priority(TASK_PRIORITY_FT , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(3072)
#if defined(__MTK_TARGET__)  && !defined(__MAUI_BASIC__)
task_create_function(ft_create)
#else
null_task_create_entry(NULL)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(FACTORY_M)
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
/*task_indx_type*/
task_index(INDX_FTC) 
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_FTC,MOD_DUMMY_FTC)

/*module_type and mod_task_g*/
task_module_map(INDX_FTC, MOD_FTC)

/*task's parameters*/
task_name("FTC")
task_queue_name("FTC Q")
task_priority(TASK_PRIORITY_FTC , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(884)
#if defined(__MTK_TARGET__) && !defined(__MAUI_BASIC__)
task_create_function(ftc_create)
#else
null_task_create_entry(NULL)
#endif 
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(FACTORY_M)
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#if defined(__UMTS_TDD128_MODE__) && defined(__AST_TL1_TDD__)
/*task_indx_type*/
task_index(INDX_FTA)
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_FTA,MOD_DUMMY_FTA)
/*module_type and mod_task_g*/
task_module_map(INDX_FTA, MOD_FTA)
/*task's parameters*/
task_name("FTA")
task_queue_name("FTA Q")
task_priority(TASK_PRIORITY_FTA , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(3072)
#if defined(__MTK_TARGET__)
task_create_function(fta_create)
#else
null_task_create_entry(NULL)
#endif 
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(40)
task_internal_queue_size(0)
task_boot_mode(FACTORY_M)
#endif
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
/*task_indx_type*/
task_index(INDX_LBS)  
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
task_module_map(INDX_LBS,MOD_DUMMY_LBS)
/*module_type and mod_task_g*/
task_module_map(INDX_LBS, MOD_GPS)
task_module_map(INDX_LBS, MOD_LBS)

/*task's parameters*/
task_name("LBS")
task_queue_name("LBS Q")
task_priority(TASK_PRIORITY_LBS , KAL_TASK_INITIAL_PRIORITY )
task_stack_size(8192)
#if (defined(__GPS_SUPPORT__)||defined(__BT_GPS_SUPPORT__)) && !defined(__GPS_TASK_DISABLE__)
task_create_function(lbs_create)
#else
null_task_create_entry(NULL)
#endif
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(30)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
/*************************Task CFG END******************/



/**** customer added task or module id is started  *****/

/**** customer added task or module id is ended    *****/


/*************************Task CFG Begin****************/
/*task_indx_type*/
/* this is a fake task for task id grouping*/
task_index(TASK_ID_MW_CODE_TAIL)
/*module_type and mod_task_g*/
task_module_map(TASK_ID_MW_CODE_TAIL, MODULE_TAG_MW_DUMMY_TAIL)
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
