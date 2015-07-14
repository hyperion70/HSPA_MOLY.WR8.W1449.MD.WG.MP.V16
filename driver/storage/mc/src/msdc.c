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
 *   msdc.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   driver functons for MSDC controller
 *
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
#include "drv_features.h"
#ifndef DRV_MSDC_OFF
#include "kal_public_api.h" //MSBB change #include "kal_release.h"
#include "md_drv_sap.h"
#include "drv_msgid.h"
//RHR ADD
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "kal_debug.h"
#include "hisr_config.h"
#include "config_hw.h"
#include "init.h"
//RHR REMOVE
/*
//MSBB remove #include "kal_non_specific_general_types.h"
//MSBB remove #include "kal_active_module.h"
#include "syscomp_config.h"
#include "task_config.h"
#include "stacklib.h"
#include "eint.h"
#include "fat_fs.h"
//#include "gpio_hw.h"
#ifdef __MULTI_BOOT__
#include "syscomp_config.h"
#include "multiboot_config.h"
#endif//__MULTI_BOOT__
#include "pmu_sw.h"
#if defined(KAL_ON_NUCLEUS)
#include "nucleus.h"
#include "ev_defs.h"
#endif
*/
//RHR
#include "kal_trace.h"
#include "dcl.h"
#include "kal_public_defs.h" //MSBB change #include "stack_common.h"  
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "kal_public_api.h"
#include "kal_public_api.h" //MSBB change #include "app_ltlcom.h"       /* Task message communiction */
#include "intrCtrl.h"
#include "reg_base.h"
#include "drvpdn.h"
#include "drv_features.h"
#include "drv_comm.h"
#include "msdc_reg_adap.h"
#include "dma_hw.h"
#include "dma_sw.h"
#include "drv_hisr.h"
//sleep mode
#include "drvpdn.h"
#include "l1sm_public.h"
#if !defined(__UBL__) || defined(__CARD_DOWNLOAD__) || defined(__EMMC_BOOTING__)
#include "msdc_api.h"
#include "msdc_def.h"
#include "sd_def.h"

//! EMB
#include "FTL.h"

#if defined(__MSDC_SD_MMC__)&&defined(__MSDC_SD_SDIO__)
#include "sdio_sw.h"
#endif
#if defined(__MSDC_MS__)
#include "ms_def.h"
#elif defined(__MSDC_MSPRO__)
#include "mspro_def.h"
#endif
#include "upll_ctrl.h"
//#include "gpio_sw.h"
#include "drv_trc.h"
#if defined(__AUDIO_DSP_LOWPOWER__)
#include "audlp_exp.h"
#endif

#ifdef DRV_LSD
#include "msdc_lsd.h"
#endif

#ifdef __CLKG_DEFINE__
#ifdef DRVPDN_CON1
#error "__CLKG_DEFINE__ & DRVPDN_CON1 are all defined"
#else
#define DRVPDN_CON1		CG_CON1
#endif

#ifdef DRVPDN_CON1_SIM
#error "__CLKG_DEFINE__ & DRVPDN_CON1_SIM are all defined"
#else
#define DRVPDN_CON1_SIM	CG_CON1_SIM
#endif

#ifndef MSDC_TEST_MSDC2_FROM_MSDC1_CODE

#ifdef DRVPDN_CON1_MSDC
#error "__CLKG_DEFINE__ & DRVPDN_CON1_MSDC are all defined"
#else
#define DRVPDN_CON1_MSDC	CG_CON1_MSDC
#endif

#ifdef DRVPDN_CON1_CLR
#error "__CLKG_DEFINE__ & DRVPDN_CON1_CLR are all defined"
#else
#define DRVPDN_CON1_CLR	CG_CLR1
#endif

#ifdef DRVPDN_CON1_SET
#error "__CLKG_DEFINE__ & DRVPDN_CON1_SET are all defined"
#else
#define DRVPDN_CON1_SET	CG_SET1
#endif

#else /*when MSDC_TEST_MSDC2_FROM_MSDC1_CODE is defined, we direct CON1 related macro to CON0 related*/

#ifdef DRVPDN_CON1_MSDC
#error "__CLKG_DEFINE__ & DRVPDN_CON1_MSDC are all defined"
#else
#define DRVPDN_CON1_MSDC	CG_CON0_MSDC2
#endif

#ifdef DRVPDN_CON1_CLR
#error "__CLKG_DEFINE__ & DRVPDN_CON1_CLR are all defined"
#else
#define DRVPDN_CON1_CLR	CG_CLR0
#endif

#ifdef DRVPDN_CON1_SET
#error "__CLKG_DEFINE__ & DRVPDN_CON1_SET are all defined"
#else
#define DRVPDN_CON1_SET	CG_SET0
#endif
#endif//MSDC_TEST_MSDC2_FROM_MSDC1_CODE

#endif




/*
#if !(defined __MSDC_NOT_SUPPORT_HOT_PLUG__)
#if defined(MT6218B_FN) || defined(MT6219_EV) ||defined(MT6217)||defined(MT6227)||defined(MT6226)||defined(MT6226M)\
		|| defined(MT6225)
#define USE_INT26_CARD_DETECTION
#endif
#endif
*/


#if defined (WISDOM35B_DEMO_BB)
extern const char gpio_SD_det_pin;
#endif

// global variable
MSDC_HANDLE MSDC_Blk[SD_NUM];


#if defined(DRV_MSDC_LATCH_MT6276_SERIES)
#if defined(MT6256)
kal_uint32 gMsdcClksrcRate[MSDC_CLKSRC_NUM] = {94500, 86600, 74200, 65000};
#elif defined(MT6255)
kal_uint32 gMsdcClksrcRate[MSDC_CLKSRC_NUM] = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
#elif defined(MT6250)
kal_uint32 gMsdcClksrcRate[MSDC_CLKSRC_NUM] = {97500, 86600, 78000, 65000};
#elif defined(MT6280)
kal_uint32 gMsdcClksrcRate[MSDC_CLKSRC_NUM] = {96000, 80000, 68600, 60000};
#else
kal_uint32 gMsdcClksrcRate[MSDC_CLKSRC_NUM] = {122200, 101800, 87200, 76300}; // KHz
#endif
#endif


#if (defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__)|| defined(__MSDC_MSPRO__)) || defined(__MSDC_SD_SDIO__)
MSDC_HANDLE	*gMSDC_Handle = &(MSDC_Blk[0]);

#if defined(__UBL__) && defined(__EMMC_BOOTING__)
__attribute__ ((zero_init, section ("EXT_UN_INIT_ZI")))kal_uint32 MSDC_Sector[128];
#if defined(MSDC_MMC40_SUPPORT)
__attribute__ ((zero_init, section ("EXT_UN_INIT_ZI")))kal_uint32 MSDC_eCSD[128];
#endif
#ifdef MSDC_CACHED_SUPPORT
__attribute__ ((zero_init, section ("EXT_UN_INIT_ZI")))kal_uint32	msdc_uncachedBuf[MSDC_UNCACHED_BUF_SIZE / 4];
#endif
#else
__attribute__ ((zero_init, section ("NONCACHEDZI")))kal_uint32 MSDC_Sector[128];
#if defined(MSDC_MMC40_SUPPORT)
__attribute__ ((zero_init, section ("NONCACHEDZI")))kal_uint32 MSDC_eCSD[128];
#endif
#ifdef MSDC_CACHED_SUPPORT
__attribute__ ((zero_init, section ("NONCACHEDZI")))kal_uint32	msdc_uncachedBuf[MSDC_UNCACHED_BUF_SIZE / 4];
#endif
#endif
//Light 120907
#define MSDC_DMA_BURSTLEN_LIMIT 65024

kal_bool MSDC_useDMA4ByteBurst = KAL_FALSE;

#ifdef  __TST_WRITE_TO_FILE__
/*error recording: add this additional global variable to use when in error recording*/
MSDC_HANDLE MSDC_ErrorRecordingBlk;
#endif

#if defined(DRV_MSDC_SHARE_BY_SWITCH)
sd_select_enum current_card; // active card
#if !defined(__CUST_NEW__)
extern kal_char MSDC_GetLDO_GPIO(void);
extern kal_char MSDC_GetSwitch_GPIO(void);
extern kal_char MSDC_GetEXTLDO_GPIO(void);
extern kal_char MSDC_GetSwitchDirection(void);
kal_char gpio_simplug_ldo_switch;
kal_char gpio_ext_sd_ldo_switch;
kal_char gpio_sim_msdc_switch;
#endif
#endif

#if !defined(LOW_COST_SUPPORT) && !defined(DRV_LSD) && defined(__DRV_DBG_MEMORY_TRACE_SUPPORT__) && !defined(__UBL__)
msdc_debugMessage msdc_msgArray[MSDC_DBG_ARRAY_SIZE];
kal_uint32 msdc_msdIndex;
#endif

// system control blocks

// function predeclaration
void MSDC_DMAInit(void);
void MSDC_INT_Init(void);
void MSDC_DMA_Callback(void);
void MSDC_EINT_Handler(void);
void MSDC_turnOnVMC(kal_bool turnOnLdo);
#ifdef R1B_INTERRUPT_MODE
static void MSDC_R1B_Init();
#endif


extern void GPIO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada);
extern boot_mode_type kal_query_boot_mode(void);
extern kal_bool INT_USBBoot(void);
extern kal_int8 MSDC_GetDLTFromOPCLK(kal_uint32 opClk, kal_uint8 *setRED);
extern void SD_Sleep4Wait(kal_int32 sleep_tick);

#ifdef __CARD_DOWNLOAD__
extern kal_bool MSDC_QueryIsPowerControllable(void);
extern void MSDC_SetPower(kal_bool enable);
#endif

#ifdef __MSDC_CD_EINT__

#if defined(__MSDC_NOT_SUPPORT_HOT_PLUG__)
#error "__MSDC_NOT_SUPPORT_HOT_PLUG__ shouldn't be defined."
#endif
extern const unsigned char MSDC_EINT_NO;
static kal_uint32 MSDC_debounceTime;
static kal_bool cardDetectionEINTPolarity;
#endif
#if defined(__UBL__) || defined(__FUE__)
kal_bool MSDC_START_TIMER(kal_uint16 x)
{
    gMSDC_Handle->is_timeout = KAL_FALSE;
}
#else// defined(__UBL__) || defined(__FUE__)

kal_bool MSDC_START_TIMER(kal_uint16 x)
{
    //DCL_HANDLE gpt_handle;
    DCL_STATUS status;
    SGPT_CTRL_START_T start;

#if defined(MSDC_DEBUG_INFO)
    strcpy(gMSDC_Handle->msdc_fname, __FILE__);
    gMSDC_Handle->msdc_lines = __LINE__;
#endif

    gMSDC_Handle->is_timeout = KAL_FALSE;
    start.u2Tick = x;
    start.pfCallback = MSDC_TimeOutHandler;
    start.vPara = NULL;
    //gpt_handle= module |MSDC_GPT_CB_MAGIC_NUM;
    status = DclSGPT_Control(MSDC_Blk[0].gpt_handle, SGPT_CMD_START, (DCL_CTRL_DATA_T*)&start);

    if (STATUS_OK == status)
        return KAL_TRUE;
    else
        return KAL_FALSE;
}
#endif// defined(__UBL__) || defined(__FUE__)

#if defined(__UBL__) || defined(__FUE__)
kal_bool MSDC_STOP_TIMER()
{
    return KAL_TRUE;
}
#else// defined(__UBL__) || defined(__FUE__)
kal_bool MSDC_STOP_TIMER()
{
    if (!gMSDC_Handle->mIsPresent )
    {
        kal_set_eg_events(gMSDC_Handle->MSDC_Events, 0, KAL_AND);
        return KAL_FALSE;
    }

    //MSDC_GPTI_StopItem(gMSDC_Handle->gpt_handle);
    DclSGPT_Control(MSDC_Blk[0].gpt_handle, SGPT_CMD_STOP, 0);

    if (gMSDC_Handle->is_timeout)
    {
        kal_set_eg_events(gMSDC_Handle->MSDC_Events, 0, KAL_AND);
    }

    return KAL_TRUE;
}
#endif// defined(__UBL__) || defined(__FUE__)

#if !defined(__FUE__) && !defined(__UBL__)
void MSDC_GPTI_BusyWait(kal_uint16 len)
{
    DCL_HANDLE gpt_handle;
    DCL_CTRL_DATA_T data;
    gpt_handle = DclSGPT_Open(DCL_GPT_BusyWait, 0);
    data.uBusyWaitcount = len;
    DclSGPT_Control(gpt_handle, SGPT_CMD_BUSYWAIT, &data);
    DclSGPT_Close(&gpt_handle);
}

kal_uint8 MSDC_GPTI_GetHandle(DCL_HANDLE *handle)
{
    //DCL_HANDLE gpt_handle;
    *handle = DclSGPT_Open(DCL_GPT_CB, 0);

    //*handle = 0xFF & gpt_handle;

    return KAL_TRUE;
}

#endif//!defined(__FUE__) && !defined(__UBL__)

/*************************************************************************
* FUNCTION
*  MSDC_SetClock
*
* DESCRIPTION
*
* PARAMETERS
*	clock: the desired operating clock rate in the unit of kHz
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void MSDC_SetClock(kal_uint32 clock)
{
    kal_uint32 cfg;

    if (clock == 0)
        return;

    MSDC_LSD_ClearBits32(SDC_CFG, SDC_CFG_SIEN);
    cfg = ((gMSDC_Handle->msdc_clock + clock - 1) / clock);

    if (cfg <= 2 )
    {
        cfg = 0;
        gMSDC_Handle->op_clock = gMSDC_Handle->msdc_clock / 2;
    }
    else
    {
        //I change , cfg = (cfg >> 2) + (cfg&3 != 0); , to following line for Lint wrning
        cfg = (cfg >> 2) + (((cfg & 3) != 0) ? 1 : 0);

        if (0 != cfg)
        {
            gMSDC_Handle->op_clock = gMSDC_Handle->msdc_clock / (4 * cfg);
        }
        else
        {
            ASSERT(0);
        }
    }

    BitFieldWrite32((kal_uint32*)MSDC_CFG, (kal_uint32)cfg, MSDC_CFG_SCLKF);
    MSDC_LSD_SetBits32(SDC_CFG, SDC_CFG_SIEN);

}

/*************************************************************************
* FUNCTION
*  MSDC_SetClockSource
*
* DESCRIPTION
*
* PARAMETERS
*	type: the desired operating clock source
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void MSDC_SetClockSource(T_MSDC_CLK_TYPE type)
{
    switch (type)
    {
        case MSDC_CLOCK_MCU:
#if defined(DRV_MSDC_CLK_MT6251_SERIES)
            MSDC_LSD_SetBits32(MSDC_CFG, MSDC_CFG_CLKSRC);
#else
            MSDC_LSD_ClearBits32(MSDC_CFG, MSDC_CFG_CLKSRC);
#endif
            break;

        case MSDC_CLOCK_MCPLL:
#if defined(DRV_MSDC_CLK_MT6251_SERIES)
            MSDC_LSD_ClearBits32(MSDC_CFG, MSDC_CFG_CLKSRC);
#else
            MSDC_LSD_SetBits32(MSDC_CFG, MSDC_CFG_CLKSRC);
#endif
            break;

        default:
            ASSERT(0);
    }
}
/*************************************************************************
* FUNCTION
*  MSDC_Check_Card_Present
*
* DESCRIPTION
*	c
*
* PARAMETERS
*	ON: turn on power saving or not
*
* RETURNS
*
* GLOBALS AFFECTED
*
*
*************************************************************************/
kal_bool MSDC_Check_Card_Present(void)
{
#if !defined(__MSDC_NOT_SUPPORT_HOT_PLUG__)
    return gMSDC_Handle->mIsPresent;
#else
    return KAL_TRUE;
#endif
}
/*************************************************************************
* FUNCTION
*  MSDC_PDNControl
*
* DESCRIPTION
*	Enable power saving or not.
*
* PARAMETERS
*	ON: turn on power saving or not
*
* RETURNS
*
* GLOBALS AFFECTED
*
*
*************************************************************************/
#define MSDC_SLEEP_MODE_INVALID_HANDLE 0xFF
static kal_uint8 MSDC_sm_handler = MSDC_SLEEP_MODE_INVALID_HANDLE;
void MSDC_PDNControl(kal_bool ON)
{
    gMSDC_Handle->mIsPWDown = ON;
#ifndef DRV_LSD
    if(MSDC_SLEEP_MODE_INVALID_HANDLE == MSDC_sm_handler)//
    {
        MSDC_sm_handler = L1SM_GetHandle();
    }
    if (ON)
    {
        // OFF
#if defined(__UBL__) || defined(__FUE__)
        //ASSERT(0);
#else//defined(__UBL__) || defined(__FUE__)
        // clear all pending IRQ
        MSDC_CLR_INT();
        MSDC_CLR_INT();
#if 0 //!defined(MSDC_USE_INT)
/* under construction !*/
#endif
#if defined(MSDC_USE_USB_CLK) && defined(__MSDC_SD_MMC__)

        if (gSD->flags & SD_FLAG_USE_USB_CLK)
            UPLL_Disable(UPLL_OWNER_MSDC);

#ifdef MSDC2_SDIO_TEST

        if (gSD->flags & SD_FLAG_USE_USB_CLK)
            UPLL_Disable(UPLL_OWNER_MSDC2);//guilin

#endif
#endif
#ifdef __OLD_PDN_ARCH__
        DRVPDN_Enable(DRVPDN_CON1, DRVPDN_CON1_MSDC, PDN_MSDC);
#else
        //DRVPDN_Enable(PDN_MSDC);
        PDN_SET(PDN_MSDC); //power down dev
	    L1SM_SleepEnable(MSDC_sm_handler);  //unlock sleep mode
#ifdef MSDC2_SDIO_TEST
        //DRVPDN_Enable(PDN_MSDC2);//guilin
        PDN_SET(PDN_MSDC2); //power down dev
	    L1SM_SleepEnable(MSDC_sm_handler);  //unlock sleep mode
#endif
#if defined(MT6250)

        if (INT_SW_SecVersion() == SW_SEC_0)
        {
            PDN_SET(PDN_SW_MSDC);
        }

#endif
#endif
#endif//defined(__UBL__) || defined(__FUE__)
    }
    else
    {
        // ON
#if 0 // !defined(MSDC_USE_INT)
/* under construction !*/
#endif
#if defined(__UBL__) || defined(__FUE__)
#if 1
#ifdef __OLD_PDN_ARCH__
#if defined(__OLD_PDN_DEFINE__)
        DRVPDN_ON(DRVPDN_CON1, DRVPDN_CON1_MSDC, PDN_MSDC);
#elif defined(__CLKG_DEFINE__)
        DRVPDN_ON(CG_CON1, CG_CON1_MSDC, PDN_MSDC);
#endif
#else
       //DRVPDN_Disable(PDN_MSDC);
        PDN_CLR(PDN_MSDC);
		L1SM_SleepDisable(MSDC_sm_handler); //lock sleep mode
#if defined(MT6250)

        if (INT_SW_SecVersion() == SW_SEC_0)
        {
            PDN_CLR(PDN_SW_MSDC);
        }

#endif
        //DRVPDN_ON(DRVPDN_CON1, DRVPDN_CON1_MSDC, PDN_MSDC);	// Kirk's TODO
        //DRVPDN_ON(MCUSYS_PDN_CON1, DRVPDN_CON1_MSDC, PDN_MSDC); // dedicate for MT6236 (Kirk)
        //DRVPDN_ON(MCUSYS_PDN_CON1, MCUSYS_PDN_CON1_MSDC, PDN_MSDC); // introduced in eMMC Boot
#endif
#else
#ifdef __OLD_PDN_ARCH__
/* under construction !*/
#else
/* under construction !*/
#endif
#endif
#else//defined(__UBL__) || defined(__FUE__)
#ifdef __OLD_PDN_ARCH__
        DRVPDN_Disable(DRVPDN_CON1, DRVPDN_CON1_MSDC, PDN_MSDC);
#else
        //DRVPDN_Disable(PDN_MSDC);
        PDN_CLR(PDN_MSDC);
		L1SM_SleepDisable(MSDC_sm_handler); //lock sleep mode
#ifdef MSDC2_SDIO_TEST
        //DRVPDN_Disable(PDN_MSDC2);//guilin
        PDN_CLR(PDN_MSDC2);
		L1SM_SleepDisable(MSDC_sm_handler); //lock sleep mode
#endif
#if defined(MT6250)

        if (INT_SW_SecVersion() == SW_SEC_0)
        {
            PDN_CLR(PDN_SW_MSDC);
        }

#endif
#endif
#endif//__UBL__//__CARD_DOWNLOAD__
#if defined(MSDC_USE_USB_CLK) && defined(__MSDC_SD_MMC__)

        if (gSD->flags & SD_FLAG_USE_USB_CLK)
        {
#if defined(__UBL__) || defined(__FUE__)
            USBDL_CLK_ON(KAL_TRUE);
#else//defined(__UBL__) || defined(__FUE__)
            UPLL_Enable(UPLL_OWNER_MSDC);
#ifdef MSDC2_SDIO_TEST
            UPLL_Enable(UPLL_OWNER_MSDC2);//guilin
#endif
#endif//defined(__UBL__) || defined(__FUE__)
        }

#endif
    }

    // turn on MSDC_PDN bit always recently to cover sleep mode card detection
#if 0 // !defined(USE_INT26_CARD_DETECTION)
/* under construction !*/
#endif
#else
    LSD_PDNControl(ON);
#endif

}
/*************************************************************************
* FUNCTION
*  MSDC_TimeOutHandler
*
* DESCRIPTION
*	Callback function of gpt timer, and launched while MSDC busy for a while

*
* PARAMETERS
*
*
* RETURNS
*
* GLOBALS AFFECTED
*
*
*************************************************************************/
void MSDC_TimeOutHandler(void *parameter)
{
	tst_sys_trace("MSDC_TimeOutHandler");
#if defined(MSDC_TRACE_LEVEL3)
    MSDC_add_dbg_msg(msdc_dbg_event_GPT_timeout, MSDC_Reg(DMA_RLCT(gMSDC_Handle->msdc_dmaport)), MSDC_Reg(SDC_STA));
#endif

    gMSDC_Handle->is_timeout = KAL_TRUE;
#if defined(__MSDC_MS__)||defined(__MSDC_MSPRO__)
    kal_set_eg_events(gMSDC_Handle->MSDC_Events,
                      (EVENT_MSIFIRQ | EVENT_DMAIRQ | EVENT_MSRDYIRQ),
                      KAL_OR);
#else
    kal_set_eg_events(gMSDC_Handle->MSDC_Events,
                      (EVENT_SDCMDIRQ | EVENT_SDDATIRQ | EVENT_SDMCIRQ | EVENT_SDR1BIRQ | EVENT_DMAIRQ),
                      KAL_OR);
#endif
}

/*************************************************************************
* FUNCTION
*  MSDC_GetCardStatus
*
* DESCRIPTION
*	Check currently card is present or not.
*
* PARAMETERS
*
*
* RETURNS
*
* GLOBALS AFFECTED
*	msdc_eint_state
*
*
*************************************************************************/
int MSDC_GetCardStatus(void * DriveData, int AckType)
{
    MSDC_HANDLE *msdc = (MSDC_HANDLE *)DriveData;;

#if defined(__AUDIO_DSP_LOWPOWER__)
    AUDMA_LOCK(AUDMA_ID_MSDC);
#endif

    // a debounce mechanism
    if (kal_query_systemInit() == KAL_FALSE && KAL_FALSE == INT_QueryExceptionStatus()
            && msdc->mIsPresent == KAL_TRUE)
    {
#if !defined(__UBL__) && !defined(__FUE__)
        kal_sleep_task(100);
#endif
    }

    ENTER_CRITICAL();
    msdc->send_ilm = KAL_TRUE;
    EXIT_CRITICAL();

#if defined(__SIM_PLUS__) || defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)

    /*since in SIM plus solution, only SD_EXT support hot plug. we only power down MSDC here*/
    if (!msdc->mIsPresent && current_card == SD_EXT)
        MSDC_PDNControl(KAL_TRUE);

#else

    if (!msdc->mIsPresent)
        MSDC_PDNControl(KAL_TRUE);

#endif

#if defined(__AUDIO_DSP_LOWPOWER__)
    AUDMA_UNLOCK(AUDMA_ID_MSDC);
#endif
    return 0;
}
/*************************************************************************
* FUNCTION
*  MSDC_SendCardInd
*
* DESCRIPTION
*	Send card indication to the specified module.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*
*************************************************************************/
void MSDC_SendCardInd(module_type dest_id, sd_select_enum sel, kal_uint32 msg_id)
{
    module_type module_id;

#if defined(__MSDC_SD_SDIO__)|| defined(__MSDC2_SD_SDIO__)
    kal_uint32 custom;

    custom =  MSDC_GetCustom();

    // only send the ilm while memroy card is plugged in
    if (((sel == SD_MSDC1) && (custom & MSDC_SDIO4_SD1))
#ifdef	DRV_MSDC_MT6238_SERIES
            || ((sel == SD_MSDC2) && (custom & MSDC_SD4_SDIO1))
#endif
       )
        return;

#endif // __MSDC_SD_SDIO__

#ifdef	__DRV_MSDC_FAST_FORMAT__

    /*	in fast format, there is chance to plug out card when task is waiting for
    	DMA or timeout event from large number of DMA transfer,
    */
    if (KAL_TRUE == MSDC_Blk[sel].MSDC_fastFormat)
    {
        if (KAL_FALSE == MSDC_Blk[sel].is_timeout)
        {
            DclSGPT_Control(MSDC_Blk[0].gpt_handle, SGPT_CMD_STOP, 0);
            MSDC_Blk[sel].is_timeout = KAL_TRUE;
            kal_set_eg_events(MSDC_Blk[sel].MSDC_Events, EVENT_DMAIRQ, KAL_OR);
        }
    }

#endif

#ifdef MSDC_TRACE_LEVEL1
    drv_trace2(TRACE_GROUP_6, MSDC_INFORM_HOTPLUGILM, sel, MSDC_Blk[sel].send_ilm);
#endif


    //in current design, only SIM plus solution need two card indication.
#if defined(__SIM_PLUS__) || defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH) //xuehui ye

    if (MSDC_Blk[sel].send_ilm || sel == SD_EXT) //SD_SIM)
#else
    if (MSDC_Blk[sel].send_ilm)
#endif
    {
        ilm_struct *msdc_ilm = NULL;
        msdc_card_detect_ind_struct *local = NULL;

        local = (msdc_card_detect_ind_struct*)
                construct_local_para(sizeof(msdc_card_detect_ind_struct), TD_CTRL);
        local->media_size = 1;
        local->media_index = sel;
#if defined(__MSDC_DUAL_CARD_SWITCH__) && !defined(__MSDC_NOT_SUPPORT_HOT_PLUG__)
        local->media_size = 1;
        local->media_status = MSDC_Blk[sel].mIsPresent;
        local->media_array_size = sizeof(MSDC_Blk[sel]);
        local->media_index = 1;
#endif
#if defined(__SIM_PLUS__) || defined(__MSDC2_SD_MMC__) || defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH) //xuehui ye
        local->media_array = &MSDC_Blk[sel];
#else
        local->media_array = &MSDC_Blk[0];
#endif

        if (kal_if_hisr())
        {
            //msdc_ilm = allocate_ilm(MOD_DRV_HISR);
            msdc_ilm->src_mod_id = MOD_DRV_HISR;
            
        }
        else
        {
            module_id = kal_get_active_module_id();
            //msdc_ilm = allocate_ilm(module_id);
            msdc_ilm->src_mod_id = module_id;
			tst_sys_trace("[MSDC]msg send in task");
        }

#if defined(__SIM_PLUS__) || defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH) //xuehui ye

        if (sel == SD_EXT)
        {
            //msdc_ilm->msg_id = MSG_ID_MSDC_CARD_DETECT_IND;
            msdc_ilm->msg_id = msg_id;
            MSDC_Blk[sel].send_ilm = KAL_FALSE;
        }
        else
        {
            //msdc_ilm->msg_id = MSG_ID_SIM_PLUS_DETECT_IND;
            msdc_ilm->msg_id = msg_id;
        }

#else
        //msdc_ilm->msg_id = MSG_ID_MSDC_CARD_DETECT_IND;
        msdc_ilm->msg_id = msg_id;
        MSDC_Blk[sel].send_ilm = KAL_FALSE;
#endif

        msdc_ilm->sap_id = DRIVER_PS_SAP;
        msdc_ilm->local_para_ptr = (local_para_struct *)local;
        msdc_ilm->peer_buff_ptr = NULL;
        msdc_ilm->dest_mod_id = dest_id;
        //msg_send_ext_queue(msdc_ilm);
        msg_send5(msdc_ilm->src_mod_id, msdc_ilm->dest_mod_id, msdc_ilm->sap_id, msdc_ilm->msg_id, (local_para_struct*)local);

        if (msg_id == MSG_ID_MSDC_CARD_DISPLAY_IND)
            MSDC_Blk[sel].send_ilm = KAL_TRUE;
        else
            MSDC_Blk[sel].send_ilm = KAL_FALSE;
    }
}
/*************************************************************************
* FUNCTION
*  MSDC_GetMediaChanged
*
* DESCRIPTION
*	Check if the media is changed, and clear the status after function call
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*
*************************************************************************/
kal_bool MSDC_GetMediaChanged(sd_select_enum sel)
{
    kal_bool ret;

    ENTER_CRITICAL();
    ret = (MSDC_Blk[sel].mIsChanged ) ? (KAL_TRUE) : (KAL_FALSE);
    MSDC_Blk[sel].mIsChanged = KAL_FALSE;
    EXIT_CRITICAL();

    return ret;
}
/*************************************************************************
* FUNCTION
*  MSDC_InvertN
*
* DESCRIPTION
* 	Invert the order of bytes eg,
* 	src: 0x01 0x02, len: 2 => dest: 0x02 0x01
*
* PARAMETERS
*	1. dest: used for store inverted result
*	2. src: source for inverting
*	3. len: bytes for inverting
*
* RETURNS
*
* GLOBALS AFFECTED
*
* NOTE
*	1. make sure dest has the same size with src.
*************************************************************************/
void MSDC_InvertN(kal_uint8 *dest, kal_uint8 *src, kal_uint8 len)
{
    int i;

    for (i = 0; i < len; i++)
        *(dest + len - 1 - i) = *(src + i);

}
/*************************************************************************
* FUNCTION
*  MSDC_Config_INS_WP
*
* DESCRIPTION
* 	Configure the pull up or pull down status for INS and WP pin
*
* PARAMETERS
*	1. ins: MSDC_IOCTRL_PULL_DOWN, MSDC_IOCTRL_PULL_UP
*	2. wp: MSDC_IOCTRL_PULL_DOWN, MSDC_IOCTRL_PULL_UP
*
* RETURNS
*
* GLOBALS AFFECTED
*
* NOTE
*	1. MT6219 can not be configured to PULL up or down. They are all pulled up by IO.
*	2. MT6218B and MT6217, WP is configured with data lines.
*************************************************************************/
void MSDC_Config_INS_WP(msdc_ioctrl_enum ins, msdc_ioctrl_enum wp)
{
#if defined(DRV_MSDC_INSWP_MT6219_SERIES)
    DCL_HANDLE handle;
#endif

#if defined(DRV_MSDC_INSWP_MT6218B_SERIES)
//    kal_uint32 msdc_cfg;
#elif defined(DRV_MSDC_INSWP_MT6219_SERIES)
#else
//    kal_uint32 msdc_cfg;
//    kal_uint32 iocon;
#endif

    gMSDC_Handle->ins_level = ins;
    //#if defined(MT6218B) || defined(MT6217)
#if defined(DRV_MSDC_INSWP_MT6218B_SERIES)
    // INS use PRCFG0, WP use PRCFG2 together with data line (must pull high)
    MSDC_SetData32(MSDC_CFG,  MSDC_CFG_PRCFG0, (ins << 22));
    //#elif defined(MT6219)||defined(MT6227)||defined(MT6226)||defined(MT6226M) || defined(MT6225)
#elif defined(DRV_MSDC_INSWP_MT6219_SERIES)
#ifndef __CUST_NEW__
    //GPIO_ModeSetup(MSDC_GPIO_MCINS,1); // enable card insertion signal (replaced by DCL)
    handle = DclGPIO_Open(DCL_GPIO, MSDC_GPIO_MCINS);
    DclGPIO_Control(handle, GPIO_CMD_SET_MODE_1, 0);
    DclGPIO_Close(handle);
    //GPIO_ModeSetup(MSDC_GPIO_WP,1); // enable write protection signal	(replaced by DCL)
    handle = DclGPIO_Open(DCL_GPIO, MSDC_GPIO_WP);
    DclGPIO_Control(handle, GPIO_CMD_SET_MODE_1, 0);
    DclGPIO_Close(handle);
#endif /* __CUST_NEW__ */

    if (ins == MSDC_IOCTRL_PULL_DOWN)
    {
        //GPIO_PullenSetup(MSDC_GPIO_MCINS, KAL_FALSE); // replaced by DCL
        handle = DclGPIO_Open(DCL_GPIO, MSDC_GPIO_MCINS);
        DclGPIO_Control(handle, GPIO_CMD_DISABLE_PULL, 0);
        DclGPIO_Close(handle);
    }

    //#elif defined(MT6228)||defined(MT6229)||defined(MT6227)||defined(MT6226)||defined(MT6226M)
#else
#if defined(DRV_MSDC_IOCON_V2)

    if (wp == MSDC_IOCTRL_PULL_DOWN)
    {
        BitFieldWrite32((kal_uint32*)MSDC_IOCON1, (kal_uint32)1, MSDC_IOCON1_PRCFG_RST_WP);
        BitFieldWrite32((kal_uint32*)MSDC_IOCON1, (kal_uint32)2, MSDC_IOCON1_PRVAL_RST_WP);
    }
    else
    {
        BitFieldWrite32((kal_uint32*)MSDC_IOCON1, (kal_uint32)0, MSDC_IOCON1_PRCFG_RST_WP);
        BitFieldWrite32((kal_uint32*)MSDC_IOCON1, (kal_uint32)wp, MSDC_IOCON1_PRVAL_RST_WP);
    }

    if (ins == MSDC_IOCTRL_PULL_DOWN)
    {
        BitFieldWrite32((kal_uint32*)MSDC_IOCON1, (kal_uint32)1, MSDC_IOCON1_PRCFG_INS);
        BitFieldWrite32((kal_uint32*)MSDC_IOCON1, (kal_uint32)2, MSDC_IOCON1_PRVAL_INS);
    }
    else
    {
        BitFieldWrite32((kal_uint32*)MSDC_IOCON1, (kal_uint32)0, MSDC_IOCON1_PRCFG_INS);
        BitFieldWrite32((kal_uint32*)MSDC_IOCON1, (kal_uint32)wp, MSDC_IOCON1_PRVAL_INS);
    }

#else
    // INS use PRCFG3, WP use PRCFG0
    MSDC_SetData32(MSDC_CFG,  MSDC_CFG_PRCFG0, (wp << 22));
    MSDC_SetData32(MSDC_IOCON,  MSDC_IOCON_PRCFG3, (ins << 8));
#endif//#if defined(DRV_MSDC_IOCON_V2)
#endif

    /*busy loop to wait msdc controller recharge*/
    MSDC_GPTI_BusyWait(1);
}

void MSDC_InitializeSwitchGpio()
{


#if defined(__SIM_PLUS__) || defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
	DCL_HANDLE handle;
#if !defined(__CUST_NEW__)
    GPIO_LDO_SWITCH = MSDC_GetLDO_GPIO();
    GPIO_EXT_SD_LDO_SWITCH = MSDC_GetEXTLDO_GPIO();
    GPIO_SIM_MSDC_SWITCH = MSDC_GetSwitch_GPIO();
#endif
    //GPIO_ModeSetup(GPIO_SIM_MSDC_SWITCH, 0); // gpio mode (replaced by DCL)
    handle = DclGPIO_Open(DCL_GPIO, GPIO_SIM_MSDC_SWITCH);
    DclGPIO_Control(handle, GPIO_CMD_SET_MODE_0, 0);
    DclGPIO_Close(handle);
    //GPIO_InitIO(OUTPUT, GPIO_SIM_MSDC_SWITCH); // replaced by DCL
    handle = DclGPIO_Open(DCL_GPIO, GPIO_SIM_MSDC_SWITCH);
    DclGPIO_Control(handle, GPIO_CMD_SET_DIR_OUT, 0);
    DclGPIO_Close(handle);
    /*bewlow comes after JRD SIM+ issue on 2007_03_08, use custom setting instead of fix value*/
    //GPIO_WriteIO(MSDC_GetSwitchDirection(), GPIO_SIM_MSDC_SWITCH); // replaced by DCL
    handle = DclGPIO_Open(DCL_GPIO, GPIO_SIM_MSDC_SWITCH);

    if (0 == MSDC_GetSwitchDirection())
        DclGPIO_Control(handle, GPIO_CMD_WRITE_LOW, 0);
    else if (1 == MSDC_GetSwitchDirection())
        DclGPIO_Control(handle, GPIO_CMD_WRITE_HIGH, 0);
    else
    {
        DclGPIO_Close(handle);
        ASSERT(0);
    }

    DclGPIO_Close(handle);
    /*end of changes of JRD SIM+ issue on 2007_03_08*/
#endif
}

#ifdef __MSDC_CD_EINT__
#if defined(__MSDC_TFLASH_DAT3_1BIT_HOT_PLUG__)
kal_bool EINT_DefaultPolarity = KAL_FALSE;
#else
kal_bool EINT_DefaultPolarity = KAL_TRUE;
#endif
void MSDC_EINT_Registration()
{
    cardDetectionEINTPolarity = EINT_DefaultPolarity;
    MSDC_debounceTime = 30;

    EINT_Mask(MSDC_EINT_NO);
    EINT_Registration(MSDC_EINT_NO, KAL_TRUE, cardDetectionEINTPolarity, MSDC_HISR_Entry, KAL_TRUE); //PMU_CHR_EINT_PIN=8
    EINT_SW_Debounce_Modify(MSDC_EINT_NO, MSDC_debounceTime);    // 32768Hz
    EINT_UnMask(MSDC_EINT_NO);

}
#endif

/*************************************************************************
* FUNCTION
*  MSDC_Initialize
*
* DESCRIPTION
*	Initialize the MS/SD host controller, called only once at drv_init
*
* PARAMETERS*
*
* RETURNS
*  1: initailized failed
*  0: successful
*
* GLOBALS AFFECTED
*	gMSDC_Handle
*
*************************************************************************/
extern kal_semid dualMsdcArb;

void MSDC_Initialize(void)
{
    
#if !defined(__CARD_DOWNLOAD__)&&defined(__DRV_MSDC_VMC_FROM_PMIC__)&&(defined(PMIC_6318_REG_API)||defined(PMIC_6235_REG_API)||defined(PMIC_6238_REG_API))
    PMU_CTRL_LDO_BUCK_SET_EN val;
	DCL_HANDLE handle;
#endif
#ifdef MT6253T_EVB
    DCL_HANDLE gpio_handle = 0;
#endif

#if defined(MT6255)

    //
    // 6255E1 clock has four sources: /5.5, /6, /7, /8.
    // 6255E2 or later has differ four sources: /4.5, /5.5, /6, /7
    //
    switch (INT_SW_SecVersion())
    {

            // 6255_E1
        case SW_SEC_0:
        {
            gMsdcClksrcRate[0] = 75600; // 416/5.5
            gMsdcClksrcRate[1] = 69300; // 416/6
            gMsdcClksrcRate[2] = 59400; // 416/7
            gMsdcClksrcRate[3] = 52000; // 416/8
        }
        break;

        // 6255_E2,E3,E4 or later
        default:
        {
            gMsdcClksrcRate[0] = 92400; // 416/4.5
            gMsdcClksrcRate[1] = 75600; // 416/5.5
            gMsdcClksrcRate[2] = 69300; // 416/6
            gMsdcClksrcRate[3] = 59400; // 416/7
        }
        break;

    };

#endif
    if (gMSDC_Handle->mIsInitMSDC)
        return;

    kal_mem_set(gSD, 0, sizeof(T_SDC_HANDLE));

#if defined(MT6276)
    DRV_SetBits(WPLL_CON0, 0x80);	// WPLL_CON0: bit MSDC_CLK_EN
#elif defined(MT6256) || defined(MT6255)
#if defined(MSDC_TEST_MSDC2_FROM_MSDC1_CODE)
    DRV_SetBits((PLL_base + 0x0104), 0x8040);
#else
    DRV_SetBits((PLL_base + 0x0104), 0x8080);
#endif

#elif defined(MT6280)

    //
    // CLKSW_CKSEL1. MSDC clock source selection.
    // [7:4]=2, MPLL
    // [7:4]=1, system 26M
    //
    BitFieldWrite32((kal_uint32 *)CLKSW_CKSEL1, 2, 0xF0);
    //
    // CLKSW_FDIV1.
    // [11:8]=0, 1 => clock gating.
    // [11:8]=2, => divid by 2.
    //
    BitFieldWrite32((kal_uint32 *)CLKSW_FDIV1, 2, 0xF00);

    //
    // CLKSW_FDIV6.
    // b'10 = 0->1->0.
    //
    BitFieldWrite32((kal_uint32 *)CLKSW_FDIV6, 0, 0x400);
    BitFieldWrite32((kal_uint32 *)CLKSW_FDIV6, 1, 0x400);
    BitFieldWrite32((kal_uint32 *)CLKSW_FDIV6, 0, 0x400);
#endif

#ifdef MT6253T_EVB
    /*
    	MT6253T need a GPIO to control card's LDO.
    	We should add customer function to get this GPIO.
    	Before that, hardcoding under MT6253T_EVB option here.
    */
    /*we will configure GPIO later and have to enable GPIO's power now*/
    //MSDC_SetBits(0x80010324, 0x4);
    MSDC_SetBits(DRVPDN_CON1_CLR, 0x4);
    gpio_handle = DclGPIO_Open(DCL_GPIO, 73);
    DclGPIO_Control(gpio_handle, GPIO_CMD_SET_DIR_OUT, 0);
    DclGPIO_Control(gpio_handle, GPIO_CMD_WRITE_HIGH, 0);
    DclGPIO_Control(gpio_handle, GPIO_CMD_SET_MODE_0, 0);
    DclGPIO_Close(gpio_handle);

    /*to enable the VMC LDO, in MT6253_EVB, the LDO is controlled by GPIO73*/
    /*set to output mode*/
    //MSDC_SetBits(0x80020040, 0x200);
    /*output 1*/
    //MSDC_SetBits(0x80020130, 0x200);
    /*set to GPIO mode*/
    //MSDC_ClearBits(0x80020220, 0xC);
#endif

#ifdef DRV_MSDC_SD_SDIO_SHARE_BY_SWITCH
    MSDC_Switch_init();
    MSDC_Blk[SD_SDIO].setting_MSDC_CFG = 0x15a00021;
    MSDC_Blk[SD_SDIO].setting_MSDC_IOCON = 0x010002d2;
    MSDC_Blk[SD_SDIO].setting_SDC_CFG = 0x28038200;
    MSDC_Blk[SD_SDIO].mMSDC_type = SD_CARD;
    MSDC_Blk[SD_SDIO].mIsPresent = KAL_TRUE;
    /*SD card will be used in very early state, change to SD card first*/
    MSDC_Switch(0);
#endif
#if defined(__MSDC_DUAL_CARD_SWITCH__) && !defined(__MSDC_NOT_SUPPORT_HOT_PLUG__)
    dualMsdcArb = kal_create_sem("MSDC1_lock", 1);
#endif

    //jinxing remove this.
#if 0
#ifdef DRV_MSDC_DUAL_TCARD_BY_SWITCH
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif
#ifdef DRV_MSDC_4_BYTE_BURST
    MSDC_useDMA4ByteBurst = KAL_TRUE;
#endif

    // turn on the power of controler
#ifndef DRV_LSD
MSDC_PDNControl(KAL_FALSE);
#if 0
#if defined(__UBL__) || defined(__FUE__)
#if 1
#ifdef __OLD_PDN_ARCH__
#if defined(__OLD_PDN_DEFINE__)
/* under construction !*/
#elif defined(__CLKG_DEFINE__)
/* under construction !*/
#endif
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#else
#ifdef __OLD_PDN_ARCH__
/* under construction !*/
#else
/* under construction !*/
#endif
#endif
#else//defined(__UBL__) || defined(__FUE__)
#ifdef __OLD_PDN_ARCH__
/* under construction !*/
#else
/* under construction !*/
#endif
#endif
#endif//defined(__UBL__) || defined(__FUE__)
#else
    ASSERT(LSD_Support());
    LSD_Reset();
    LSD_PDNControl(KAL_FALSE);
#endif

#ifdef DRV_MSDC_ENHANCED_PULL_CTRL
#if defined(__MSDC_SD_MMC__)
    MSDC_SetBits(0x80020280, 0xF8);
    MSDC_ClearBits(0x8001070c, 0x7000);
#elif defined(__MSDC_MSPRO__)
    MSDC_ClearBits(0x80020280, 0xF8);
    MSDC_SetBits(0x8001070c, 0x7000);
#else
    /*to make compile error*/
    a
#endif
#endif

#if defined(__MSDC_MS__)
    MSDC_LSD_ClearBits32(MSDC_CFG, MSDC_CFG_MSDC);
    //gMSDC_Handle->mMSDC_type = MS_CARD;	// removed during EMMC_BOOTING
#elif defined(__MSDC_MSPRO__)
    MSDC_LSD_ClearBits32(MSDC_CFG, MSDC_CFG_MSDC);
    //gMSDC_Handle->mMSDC_type = MSPRO_CARD;// removed during EMMC_BOOTING
    FS_MspDrvAll = FS_MspDrv;
#elif defined(__MSDC_SD_MMC__)
    MSDC_LSD_SetBits32(MSDC_CFG, MSDC_CFG_MSDC)	;
    //gMSDC_Handle->mMSDC_type = SD_CARD;	// removed during EMMC_BOOTING

    // set pull up the data and cmd
    /*
    move from sd init to msdc init, so that we reduce the power consumption
    of the case without card inserted
    */
#if defined(DRV_MSDC_IOCON_V2)
    BitFieldWrite32((kal_uint32*)MSDC_IOCON1, (kal_uint32)0, MSDC_IOCON1_PRCFG_RST_WP);
    BitFieldWrite32((kal_uint32*)MSDC_IOCON1, (kal_uint32)2, MSDC_IOCON1_PRVAL_RST_WP);
    BitFieldWrite32((kal_uint32*)MSDC_IOCON1, (kal_uint32)0, MSDC_IOCON1_PRCFG_CM);
    BitFieldWrite32((kal_uint32*)MSDC_IOCON1, (kal_uint32)2, MSDC_IOCON1_PRVAL_CM);
    BitFieldWrite32((kal_uint32*)MSDC_IOCON1, (kal_uint32)0, MSDC_IOCON1_PRCFG_DA);
    BitFieldWrite32((kal_uint32*)MSDC_IOCON1, (kal_uint32)2, MSDC_IOCON1_PRVAL_DA);
#else
    BitFieldWrite32((kal_uint32*)MSDC_CFG, (kal_uint32)2, MSDC_CFG_PRCFG0);
    BitFieldWrite32((kal_uint32*)MSDC_CFG, (kal_uint32)2, MSDC_CFG_PRCFG1);
    BitFieldWrite32((kal_uint32*)MSDC_CFG, (kal_uint32)2, MSDC_CFG_PRCFG2);
#endif//#if defined(DRV_MSDC_IOCON_V2)
#endif
    gMSDC_Handle->msdc_clock = MSDC_CLOCK;

    if (gMSDC_Handle->gpt_handle == 0)
        MSDC_GPTI_GetHandle(&gMSDC_Handle->gpt_handle);

    if (gMSDC_Handle->msdc_custom_handle.Init)
        gMSDC_Handle->msdc_custom_handle.Init();

#ifndef DRV_LSD
#if !defined(__MSDC_TFLASH_DAT3_1BIT_HOT_PLUG__)
    MSDC_Config_INS_WP(MSDC_IOCTRL_PULL_UP, MSDC_IOCTRL_PULL_UP);
#else
    MSDC_Config_INS_WP(MSDC_IOCTRL_DISABLE, MSDC_IOCTRL_PULL_UP); // using external PD resistor
    // first time if card is present, no card insertion interrupt generated
    gMSDC_Handle->mIsPresent = KAL_TRUE;
#endif
#endif
    // turn on the power of memory card
    MSDC_LSD_SetBits32(MSDC_CFG, MSDC_CFG_VDDPD);

#ifdef __CARD_DOWNLOAD__

    if (MSDC_QueryIsPowerControllable())
        MSDC_SetPower(KAL_TRUE);

#else//__CARD_DOWNLOAD__

#ifdef __DRV_MSDC_VMC_FROM_PMIC__
#ifdef PMIC_6318_REG_API
    //pmic_vmc_enable(KAL_TRUE); // replaced by DCL
    val.enable = KAL_TRUE;
    val.mod = VBT;
    handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
    DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
    DclPMU_Close(handle);
#endif
#if defined(PMIC_6235_REG_API)||defined(PMIC_6238_REG_API)
    //pmu_set_vmc_en(KAL_TRUE);
    // Add by GuoXin
    // vmc is renamed as vbt
    //pmu_set_vbt_en(KAL_TRUE); // replaced by DCL
    val.enable = KAL_TRUE;
    val.mod = VBT;
    handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
    DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
    DclPMU_Close(handle);
    // Add by GuoXin
#endif
#endif
#if defined(AVANTECH6239_DEMO_BB)
    GPIO_WriteIO(1, GPIO_EXT_SD_LDO_SWITCH);
#endif

#endif//__CARD_DOWNLOAD__

#ifndef DRV_LSD
    MSDC_SET_FIFO(1);
#endif

#ifdef DRV_MSDC_SHARE_BY_SWITCH
    MSDC_InitializeSwitchGpio();
#endif

#if defined(__SIM_PLUS__)

    /*
    	in USB boot mode, SIM task will do nothing, so we have to deal with items done in SIM task context.
    */
    if (INT_USBBoot() == KAL_TRUE)
    {
#if defined(__UBL__) || defined(__FUE__)
        ASSERT(0);
#else//defined(__UBL__) || defined(__FUE__)
#ifdef __OLD_PDN_ARCH__
        DRVPDN_Disable(DRVPDN_CON1, DRVPDN_CON1_SIM, PDN_SIM);
#else
        DRVPDN_Disable(PDN_SIM);
#endif
#endif//defined(__UBL__) || defined(__FUE__)
        MSDC_SetBits(SIM_CONF, SIM_CONF_SIMSEL);
        MSDC_SetBits(SIM_CTRL, SIM_CTRL_SIMON);
#if defined(__UBL__) || defined(__FUE__)
        ASSERT(0);
#else//defined(__UBL__) || defined(__FUE__)
#ifdef __OLD_PDN_ARCH__
        DRVPDN_Enable(DRVPDN_CON1, DRVPDN_CON1_SIM, PDN_SIM);
#else
        DRVPDN_Enable(PDN_SIM);
#endif
#endif//defined(__UBL__) || defined(__FUE__)
        GPIO_ModeSetup(GPIO_LDO_SWITCH, 0); // gpio mode
        GPIO_InitIO(OUTPUT, GPIO_LDO_SWITCH);
        MSDC_Blk[SD_SIM].mIsPresent = KAL_TRUE;
        MSDC_Blk[SD_SIM].mIsChanged = KAL_TRUE;
    }

#endif // SIM_PLUS

#ifdef DRV_MSDC_DUAL_TCARD_BY_SWITCH
    /*2nd T-card always does not support hot plug, so set it present in initialization*/
    MSDC_Blk[SD_T_CARD_2].mIsPresent = KAL_TRUE;
    MSDC_Blk[SD_T_CARD_2].mIsChanged = KAL_TRUE;
    current_card = SD_EXT;
#endif

#ifndef DRV_LSD
//	#if defined(__MSDC_NOT_SUPPORT_HOT_PLUG__)
    gMSDC_Handle->mIsPresent = KAL_TRUE;
//	#else
    // enable card detection
#if !defined(__MSDC_TFLASH_DAT3_1BIT_HOT_PLUG__)
    MSDC_WriteReg32(MSDC_PS, MSDC_PS_CDEN | MSDC_PS_PIEN0 | MSDC_PS_POEN0);
#endif

/*
#if defined (WISDOM35B_DEMO_BB)

    if (!(MSDC_Reg(MSDC_PS) & MSDC_PS_PIN0))
#else
    if (MSDC_Reg(MSDC_PS) & MSDC_PS_PIN0)
#endif
    {
        if (gMSDC_Handle->ins_level == MSDC_IOCTRL_PULL_UP)
            gMSDC_Handle->mIsPresent = KAL_FALSE;
        else
            gMSDC_Handle->mIsPresent = KAL_TRUE;
    }
    else
    {
        if (gMSDC_Handle->ins_level == MSDC_IOCTRL_PULL_UP)
            gMSDC_Handle->mIsPresent = KAL_TRUE;
        else
            gMSDC_Handle->mIsPresent = KAL_FALSE;
*/

#if defined (WISDOM35B_DEMO_BB)

    if (gMSDC_Handle->mIsPresent)
        GPIO_WriteIO(0, gpio_SD_det_pin);
    else
        GPIO_WriteIO(1, gpio_SD_det_pin);

#endif

//	#endif //__MSDC_NOT_SUPPORT_HOT_PLUG__

#ifdef DRV_MSDC_VMC_CTRL
    MSDC_turnOnVMC(gMSDC_Handle->mIsPresent);
#endif

#else
    gMSDC_Handle->mIsPresent = KAL_TRUE;
#endif

#if defined(__SIM_PLUS__)

    /*bewlow comes after JRD SIM+ issue on 2007_03_08, give power, this should be temperary solution for jrd*/
    /*if there is GPIO_EXT_SD_LDO_SWITCH GPIO, turn on it*/
    if (MSDC_NO_EXT_LDO != GPIO_EXT_SD_LDO_SWITCH)
    {
        if (KAL_TRUE == gMSDC_Handle->mIsPresent)
            GPIO_WriteIO(1, GPIO_EXT_SD_LDO_SWITCH);
        else if (KAL_FALSE == gMSDC_Handle->mIsPresent)
            GPIO_WriteIO(0, GPIO_EXT_SD_LDO_SWITCH);
    }

    /*end of changes of JRD SIM+ issue on 2007_03_08*/
#endif

#if !defined(__MSDC_NOT_SUPPORT_HOT_PLUG__) && !defined(USE_INT26_CARD_DETECTION)
    MSDC_LSD_SetBits32(MSDC_CFG, MSDC_CFG_PINEN);
#endif

//#ifdef MSDC_INT || R1B_INTERRUPT_MODE
#if defined(MSDC_INT)||defined(R1B_INTERRUPT_MODE)
    MSDC_INT_Init();
#endif	// end of MSDC_INT
#ifdef MSDC_DMA
    MSDC_DMAInit();
#endif
#ifdef R1B_INTERRUPT_MODE
    MSDC_R1B_Init();
#endif

#ifdef __MSDC_CD_EINT__
    MSDC_EINT_Registration();
#endif

#ifdef __MULTI_BOOT__

    if (kal_query_boot_mode() != NORMAL_BOOT)
        gMSDC_Handle->send_ilm = KAL_FALSE;
    else
        gMSDC_Handle->send_ilm = KAL_TRUE;

#else
    gMSDC_Handle->send_ilm = KAL_FALSE;
#endif

#ifdef DRV_MSDC_CLK_SEARCH
    gMSDC_Handle->msdc_clkTuneUpperBund = MSDC_CLOCK / 2;
#ifdef DRV_MSDC_DUAL_TCARD_BY_SWITCH
    MSDC_Blk[SD_T_CARD_2].msdc_clkTuneUpperBund = MSDC_CLOCK / 2;
#endif
#endif

#ifdef DRV_MSDC_DUAL_TCARD_BY_SWITCH

    /*we will initialize MSDC setting for card1, but for card 2, we have to init its setting in its context*/
    MSDC_Blk[SD_T_CARD_2].setting_MSDC_CFG =  MSDC_Reg32(MSDC_CFG); //xuehui change it 0x1;
    MSDC_Blk[SD_T_CARD_2].setting_MSDC_IOCON = MSDC_Reg32(MSDC_IOCON); //xuehui change it  0x0;
    MSDC_Blk[SD_T_CARD_2].setting_SDC_CFG =  MSDC_Reg32(SDC_CFG); //xuehui change it 0x0;
    MSDC_Blk[SD_T_CARD_2].mMSDC_type = SD_CARD;
    MSDC_WriteReg32(MSDC_IRQMASK0, 0xffffffff);
#endif

    MSDC_PDNControl(KAL_TRUE);
#if 0
#ifndef DRV_LSD
#if !defined(__UBL__) && !defined(__FUE__)
#ifdef __OLD_PDN_ARCH__
/* under construction !*/
#else
/* under construction !*/
#endif
#endif//!defined(__UBL__) && !defined(__FUE__)
#else
/* under construction !*/
#endif
#endif
    gMSDC_Handle->mIsInitMSDC = KAL_TRUE;
}

/*************************************************************************
* FUNCTION
*  MSDC_DeInit
*
* DESCRIPTION
*	De-initialize the MS/SD host controller, called only once at drv_init
*
* PARAMETERS*
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void MSDC_DeInit(void)
{
    DMA_FreeChannel(gMSDC_Handle->msdc_dmaport);

    gMSDC_Handle->mIsInitMSDC = KAL_FALSE;

    //
    // Patch for GPIO re-setting after LCDinit in card download flow.
    // After re-setting GPIO, we need to do SD_Initialize again.
    //
    gMSDC_Handle->mIsInitialized = KAL_FALSE;
}


#ifdef  __TST_WRITE_TO_FILE__
/*error recording: add this function to do MSDC reset when error recording*/
void MSDC_ErrorRecordingReset()
{

   	if (0 != gMSDC_Handle->msdc_dmaport)
    {
#ifdef MSDC_3538_DMA_STOP_ISSUE
        /*disable MSDC's DMA before turning off DMA channel*/
        DisableMSDC_DMA();
        RESET_MSDC();
        MSDC_SetBits32(MSDC_CFG, MSDC_CFG_FIFOTHD);
#endif
        DMA_Stop(gMSDC_Handle->msdc_dmaport);
#ifdef MSDC_3538_DMA_STOP_ISSUE
        MSDC_ClearBits32(MSDC_CFG, MSDC_CFG_FIFOTHD);
        MSDC_SetBits32(MSDC_CFG, MSDC_CFG_FIFOTHD_1);
#endif
    }

    //this is a temp soluction for tst write to sd card features.
    /*
    	MSDC_ErrorRecordingBlk.gpt_handle = gMSDC_Handle->gpt_handle;
    	MSDC_ErrorRecordingBlk.MSDC_Events = gMSDC_Handle->MSDC_Events;
    	MSDC_ErrorRecordingBlk.msdc_dmaport = gMSDC_Handle->msdc_dmaport;
    	gMSDC_Handle = &MSDC_ErrorRecordingBlk;
    	MSDC_Initialize();
    */
    memcpy(&MSDC_ErrorRecordingBlk, gMSDC_Handle, sizeof(MSDC_ErrorRecordingBlk));
}
#endif

#ifndef DRV_LSD
/*************************************************************************
* FUNCTION
*  BitFieldWrite32
*
* DESCRIPTION
*	Write src to dest at mask position
*
* PARAMETERS
*	dest: destination to be update
*	src: value to be written
*	mask: bit mask
* RETURNS
*
* GLOBALS AFFECTED
*
*
*************************************************************************/
// Note: mask must be a continuous area during 32bits. eg,
// dest : 00A30000 , src : BF, mask : 0000BF00.
// after BitFieldCpy, dest : 00A3BF00, copy src to dest at mask position.
void BitFieldWrite32(kal_uint32 * dest, kal_uint32 src, kal_uint32 mask)
{
    kal_uint8 bit_pos;
    kal_uint32 tmp;

    bit_pos = 0;
    tmp = MSDC_Reg32(dest);

    // get bit positoin
    while (!((mask >> bit_pos++) & 1));

    //use mask clear the corresponding area
    tmp &= ~mask;
    //shift src to the corresponding positiion
    src <<= (bit_pos - 1);
    //copy src into destination
    tmp |= src;
    MSDC_WriteReg32(dest, tmp);
}
#endif

#ifdef MSDC_USED_STUFF
/*************************************************************************
* FUNCTION
*  BitFieldRead32
*
* DESCRIPTION
*	read src to dest at mask position
*
* PARAMETERS
*	dest: destination to store
*	src: value to be written
*	mask: bit mask
* RETURNS
*
* GLOBALS AFFECTED
*
*
*************************************************************************/

// Note: mask must ve continuous area during 32 bits.eg,
// src : 00A3BF00, mask : 00FF0000
// after BitFieldRead, dest : A3
void BitFieldRead32(kal_uint32 * dest, kal_uint32 src, kal_uint32 mask)
{
    kal_uint8 bit_pos = 0;

    while (!((mask >> bit_pos++) & 1));

    src &= mask;
    *(kal_uint32 *)dest = src >> (bit_pos - 1);
}
#endif//MSDC_USED_STUFF

// get the bit field value of start_bit with width bits
// note 1) start_bit start from bit 0
//		2) prepare dest with initialized with zeros
//		3) width must less than 32 if using the retrun value as a result
// eg,
// src:00110110, start_bit:2,width:3 => dest:101
void GetBitFieldN(kal_uint8* dest, kal_uint8* src, kal_uint16 start_bit, kal_uint16 width)
{
    int i;
    kal_uint16 bytes, bits;

    //kal_mem_set(dest,0,width/8+1);
    kal_mem_set(dest, 0, (width / 8) + (0 == (width % 8) ? 0 : 1));

    for ( i = 0; i < width; i++)
    {
        bytes = (start_bit + i) / 8;
        bits  = (start_bit + i) % 8;
        *(dest + i / 8) |= (kal_uint8)(((*(src + bytes) >> bits) & 1) << (i % 8));
    }

    /*in MT6238, address of kal_uint32 is checked strictly, and we don't need the return value of this function*/
    /*change it's return type to void*/
    return ;
}

#if defined(DRV_MSDC_LATCH_MT6276_SERIES)
void MSDC_SetLatchTuning(void)
{
    if (gMSDC_Handle->op_clock < MSDC_OP_CLOCK)
    {
        // feedback clock from pad is used to latch data from card
        BitFieldWrite32((kal_uint32*)MSDC_CLKACB_CFG, 0, MSDC_CLKACB_CFG_CLK_LATCH);
        return;
    }

    // DIV 8
    BitFieldWrite32((kal_uint32*)MSDC_CFG, 2, MSDC_CFG_SCLKF);
    // DIV 5
    BitFieldWrite32((kal_uint32*)MSDC_CFG, 3, MSDC_CFG_CLKSRC);
    // feedback clock from pad is used to latch data from card
    BitFieldWrite32((kal_uint32*)MSDC_CLKACB_CFG, 0, MSDC_CLKACB_CFG_CLK_LATCH);
}
#else
void MSDC_SetIOCONRegDLT(void)
{
#if defined(DRV_MSDC_MT6225_SERIES)
    kal_uint32 factor;
#ifdef __DRV_MSDC_LAYOUT_DEFECT__
    kal_uint8	setRED;
    /*set DLT field according to SCLKF seeting*/
    factor = gMSDC_Handle->msdc_clock / gMSDC_Handle->op_clock;
    BitFieldWrite32((kal_uint32*)MSDC_IOCON, MSDC_GetDLTFromOPCLK(gMSDC_Handle->op_clock, &setRED), MSDC_IOCON_DLT);
    BitFieldWrite32((kal_uint32*)MSDC_CFG, setRED, MSDC_CFG_CRED);
#else
    /*set DLT field according to SCLKF seeting*/
    factor = gMSDC_Handle->msdc_clock / gMSDC_Handle->op_clock;

    if (2 == factor)
        BitFieldWrite32((kal_uint32*)MSDC_IOCON, 0x1, MSDC_IOCON_DLT);
    else if (0xff < (factor / 2))
        BitFieldWrite32((kal_uint32*)MSDC_IOCON, 0xff, MSDC_IOCON_DLT);
    else
        BitFieldWrite32((kal_uint32*)MSDC_IOCON, (kal_uint32)(factor / 2), MSDC_IOCON_DLT);

#endif
#endif
}
#endif//#if defined(DRV_MSDC_LATCH_MT6276_SERIES)

#ifdef MSDC_DMA
extern kal_uint8 DMA_GetChannel(DMA_Master DMA_CODE);
/*************************************************************************
* FUNCTION
*  MSDC_DMAInit
*
* DESCRIPTION
*	Initialize MSDC's DMA
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*
*************************************************************************/
void MSDC_DMAInit(void)
{
#ifdef  __TST_WRITE_TO_FILE_ONLY__
    a
#endif

#ifndef MSDC_TEST_MSDC2_FROM_MSDC1_CODE
#ifdef  __TST_WRITE_TO_FILE__

    /*error recording: it mens this functions is called twice, just skip*/
    if (KAL_FALSE == INT_QueryExceptionStatus())
#endif
#if defined(MT6250)

        //
        // MT6250E1. DMA bug needs sw workaround.
        //
        if (INT_SW_SecVersion() == SW_SEC_0)
            gMSDC_Handle->msdc_dmaport = DMA_FullSize_GetChannel(DMA_SW);
        else
#endif
            gMSDC_Handle->msdc_dmaport = DMA_GetChannel(DMA_MSDC);

#else
    gMSDC_Handle->msdc_dmaport = DMA_GetChannel(DMA_MSDC2);
#endif

#if defined(MT6250)

    //
    // MT6250E1. DMA bug needs sw workaround.
    //
    if (INT_SW_SecVersion() == SW_SEC_0)
    {
        gMSDC_Handle->full_menu.source = 0;
        gMSDC_Handle->full_menu.destination = 0;
        gMSDC_Handle->full_menu.TMOD.burst_mode = KAL_TRUE;
        gMSDC_Handle->full_menu.TMOD.cycle = 0x4;

#ifndef MSDC_TEST_MSDC2_FROM_MSDC1_CODE
        gMSDC_Handle->full_menu.master = DMA_MSDC;
#else
        gMSDC_Handle->full_menu.master = DMA_MSDC2;
#endif

        gMSDC_Handle->msdc_input.menu = &gMSDC_Handle->full_menu;

    }
    else
#endif
    {
      	gMSDC_Handle->msdc_menu.addr = 0;
        gMSDC_Handle->msdc_menu.TMOD.burst_mode = KAL_TRUE;
        gMSDC_Handle->msdc_menu.TMOD.cycle = 0x4;

#ifndef MSDC_TEST_MSDC2_FROM_MSDC1_CODE
        gMSDC_Handle->msdc_menu.master = DMA_MSDC;
#else
        gMSDC_Handle->msdc_menu.master = DMA_MSDC2;
#endif

        gMSDC_Handle->msdc_input.menu = &gMSDC_Handle->msdc_menu;
    }

    gMSDC_Handle->msdc_input.type = DMA_HWRX;
    gMSDC_Handle->msdc_input.size = DMA_LONG;
    gMSDC_Handle->msdc_input.count = 0;


#if defined(__SIM_PLUS__)
    MSDC_Blk[SD_SIM].msdc_dmaport = MSDC_Blk[SD_EXT].msdc_dmaport;
    MSDC_Blk[SD_SIM].msdc_menu.TMOD.burst_mode = KAL_TRUE;
    MSDC_Blk[SD_SIM].msdc_menu.TMOD.cycle = 0x4;
    MSDC_Blk[SD_SIM].msdc_menu.master = DMA_MSDC;
    MSDC_Blk[SD_SIM].msdc_menu.addr = NULL;

    MSDC_Blk[SD_SIM].msdc_input.type = DMA_HWRX;
    MSDC_Blk[SD_SIM].msdc_input.size = DMA_LONG;
    MSDC_Blk[SD_SIM].msdc_input.count = 0;
    MSDC_Blk[SD_SIM].msdc_input.menu = &MSDC_Blk[SD_SIM].msdc_menu;
    //MSDC_Blk[SD_SIM].msdc_menu = MSDC_Blk[SD_EXT].msdc_menu;
    //MSDC_Blk[SD_SIM].msdc_input = MSDC_Blk[SD_EXT].msdc_input	;
#elif defined(DRV_MSDC_SD_SDIO_SHARE_BY_SWITCH)
    MSDC_Blk[SD_SDIO].msdc_dmaport = MSDC_Blk[SD_EXT].msdc_dmaport;
    MSDC_Blk[SD_SDIO].msdc_menu.TMOD.burst_mode = KAL_TRUE;
    MSDC_Blk[SD_SDIO].msdc_menu.TMOD.cycle = 0x4;
    MSDC_Blk[SD_SDIO].msdc_menu.master = DMA_MSDC;
    MSDC_Blk[SD_SDIO].msdc_menu.addr = NULL;

    MSDC_Blk[SD_SDIO].msdc_input.type = DMA_HWRX;
    MSDC_Blk[SD_SDIO].msdc_input.size = DMA_LONG;
    MSDC_Blk[SD_SDIO].msdc_input.count = 0;
    MSDC_Blk[SD_SDIO].msdc_input.menu = &MSDC_Blk[SD_SDIO].msdc_menu;
    //MSDC_Blk[SD_SIM].msdc_menu = MSDC_Blk[SD_EXT].msdc_menu;
    //MSDC_Blk[SD_SIM].msdc_input = MSDC_Blk[SD_EXT].msdc_input	;
#elif defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
    MSDC_Blk[SD_T_CARD_2].msdc_dmaport = MSDC_Blk[SD_EXT].msdc_dmaport;
    MSDC_Blk[SD_T_CARD_2].msdc_menu.TMOD.burst_mode = KAL_TRUE;
    MSDC_Blk[SD_T_CARD_2].msdc_menu.TMOD.cycle = 0x4;
    MSDC_Blk[SD_T_CARD_2].msdc_menu.master = DMA_MSDC;
    MSDC_Blk[SD_T_CARD_2].msdc_menu.addr = NULL;

    MSDC_Blk[SD_T_CARD_2].msdc_input.type = DMA_HWRX;
    MSDC_Blk[SD_T_CARD_2].msdc_input.size = DMA_LONG;
    MSDC_Blk[SD_T_CARD_2].msdc_input.count = 0;
    MSDC_Blk[SD_T_CARD_2].msdc_input.menu = &MSDC_Blk[SD_T_CARD_2].msdc_menu;
    //MSDC_Blk[SD_SIM].msdc_menu = MSDC_Blk[SD_EXT].msdc_menu;
    //MSDC_Blk[SD_SIM].msdc_input = MSDC_Blk[SD_EXT].msdc_input	;
#endif

    #if defined(MSDC_START_DMA_IN_CALLBACK)
    gMSDC_Handle->msdc_uncachedBufs[0]=&msdc_uncachedBuf[0];
    gMSDC_Handle->msdc_uncachedBufs[1]=&msdc_uncachedBuf[MSDC_UNCACHED_BUF_SIZE/4/2];
    #endif
    //msdc_input.callback = MSDC_DMA_Callback;
}
/************************************************************************
* FUNCTION
*  MSDC_DMATransferFinal_In_Callback
*
* DESCRIPTION
*	Initialize MSDC's DMA
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*
*************************************************************************/
#if defined(MSDC_START_DMA_IN_CALLBACK)

void MSDC_DMATransferFinal_In_Callback(void)
{
#ifndef DRV_LSD
    #ifdef MSDC_CACHED_SUPPORT
    kal_uint32  msdc_input_prev=0;
    kal_uint32  msdc_input_next=gMSDC_Handle->msdc_input_next;
    #endif
	kal_uint32 total_count = gMSDC_Handle->total_count;
	kal_bool is_aligned = gMSDC_Handle->is_aligned;
	
	#if defined(MT6250)
	SW_SECVERSION sw_version=INT_SW_SecVersion();
	#endif

	MSDC_STOP_TIMER();

    total_count -= gMSDC_Handle->msdc_input.count;
	
    gMSDC_Handle->total_count = total_count;
	if ( total_count==0 ) {
		kal_set_eg_events(gMSDC_Handle->MSDC_Events,EVENT_DMAIRQ,KAL_OR);
		return;
    }

	/*copy data here if we need to do further transfer*/
    #ifdef MSDC_CACHED_SUPPORT
        if(KAL_TRUE == gMSDC_Handle->isCachedBuf){
    	    //have do memory copy stuff here
    	    if (DMA_HWTX == gMSDC_Handle->msdc_input.type )  {
        		kal_mem_cpy(msdc_uncachedBuf, (void *)gMSDC_Handle->cachedBufCopyPtr, 4 * msdc_input_next);
        		msdc_input_prev=4 * msdc_input_next;
        		//dbg_print("NC write copy %d\n\r", msdc_input_next);
    	    } else  
            if (DMA_HWRX == gMSDC_Handle->msdc_input.type ) {
                gMSDC_Handle->msdc_uncachedBufs_idx^=1;
                msdc_input_prev = 4 * gMSDC_Handle->msdc_input.count;
                gMSDC_Handle->msdc_menu.addr = (kal_uint32)gMSDC_Handle->msdc_uncachedBufs[gMSDC_Handle->msdc_uncachedBufs_idx];
            }
        }
    #endif

	if(is_aligned)
	{
        gMSDC_Handle->msdc_input.count = msdc_input_next;

        #if defined(__DRV_MSDC_FAST_FORMAT__) && defined(__DMA_API_V2__)
	        if ((KAL_TRUE == gMSDC_Handle->MSDC_fastFormat) && (gMSDC_Handle->mIsInitialized==KAL_TRUE))
                gMSDC_Handle->msdc_menu.addr = 0; // DMA FIX_PATTERN = 0;
        #endif

        #if defined(MT6250)
		if (sw_version == SW_SEC_0)
			DMA_FullSize_Config(gMSDC_Handle->msdc_dmaport,&gMSDC_Handle->msdc_input,KAL_TRUE);
        else
        #endif
		    DMA_Config_B2W(gMSDC_Handle->msdc_dmaport,&gMSDC_Handle->msdc_input,KAL_TRUE,KAL_FALSE);

        #if defined(__DRV_MSDC_FAST_FORMAT__) && !defined(__DMA_API_V2__)
		    if ((KAL_TRUE == gMSDC_Handle->MSDC_fastFormat) && (gMSDC_Handle->mIsInitialized==KAL_TRUE))
			{
				MSDC_ClearBits32(DMA_CON(gMSDC_Handle->msdc_dmaport), DMA_CON_SINC);
			}
			else
        #endif
			{
                #ifdef MSDC_CACHED_SUPPORT
				/*we don't need to increase the addr when encounter cached buffer, since we only have a fix size uncached buffer to use*/
				if(KAL_FALSE == gMSDC_Handle->isCachedBuf)
                #endif
			    {
				    gMSDC_Handle->msdc_menu.addr += gMSDC_Handle->msdc_input.count*4;
			    }
		    }
	}
	else
	{ //not aligned
        #ifdef MSDC_CACHED_SUPPORT
			if(KAL_TRUE == gMSDC_Handle->isCachedBuf)
				ASSERT(0);
        #endif

        #if defined(__DRV_MSDC_FAST_FORMAT__) && defined(__DMA_API_V2__)
	    if ((KAL_TRUE == gMSDC_Handle->MSDC_fastFormat) && (gMSDC_Handle->mIsInitialized==KAL_TRUE))
            gMSDC_Handle->msdc_menu.addr = 0; // DMA FIX_PATTERN = 0;
        #endif
        gMSDC_Handle->msdc_input.count = (total_count > MSDC_DMA_BURSTLEN_LIMIT)?(MSDC_DMA_BURSTLEN_LIMIT):(total_count);

        #if defined(MT6250)
		if (sw_version == SW_SEC_0)
			DMA_FullSize_Config(gMSDC_Handle->msdc_dmaport,&gMSDC_Handle->msdc_input,KAL_TRUE);
        else
        #endif
		    DMA_Config_B2W(gMSDC_Handle->msdc_dmaport,&gMSDC_Handle->msdc_input,KAL_TRUE,KAL_TRUE);

		gMSDC_Handle->msdc_menu.addr += gMSDC_Handle->msdc_input.count;
	}

	gMSDC_Handle->timeout_period = (50 + (gMSDC_Handle->msdc_input.count>>5));

	if(gMSDC_Handle->msdc_input.type == DMA_HWTX)
		gMSDC_Handle->timeout_period <<= 2 ;
	if(gMSDC_Handle->mMSDC_type == MMC_CARD)
		gMSDC_Handle->timeout_period <<= 1;

    if(gMSDC_Handle->timeout_period > MSDC_TIMEOUT_PERIOD_DAT)
	    gMSDC_Handle->timeout_period = MSDC_TIMEOUT_PERIOD_DAT;

    #ifdef __DRV_MSDC_FAST_FORMAT__
    	if((KAL_TRUE == gMSDC_Handle->MSDC_fastFormat) && (gMSDC_Handle->mIsInitialized==KAL_TRUE))
    		gMSDC_Handle->timeout_period = gMSDC_Handle->timeout_period<<3;
    #endif

	MSDC_START_TIMER(gMSDC_Handle->timeout_period);

    #ifdef MSDC_CACHED_SUPPORT
		if (KAL_TRUE == gMSDC_Handle->isCachedBuf) {
		    if(DMA_HWTX == gMSDC_Handle->msdc_input.type)
			    msdc_input_next = ((total_count-msdc_input_next) > MSDC_UNCACHED_TRASNFER_SIZE)?(MSDC_UNCACHED_TRASNFER_SIZE):(total_count-msdc_input_next);
			else
			    msdc_input_next = ((total_count-msdc_input_next) > MSDC_UNCACHED_TRASNFER_SIZE/2)?(MSDC_UNCACHED_TRASNFER_SIZE/2):(total_count-msdc_input_next);
		} else
    #endif
		    msdc_input_next = ((total_count-msdc_input_next) > MSDC_DMA_BURSTLEN_LIMIT)?(MSDC_DMA_BURSTLEN_LIMIT):(total_count-msdc_input_next);
        gMSDC_Handle->msdc_input_next=msdc_input_next;

	/*copy data here if we need to do further transfer*/
    #ifdef MSDC_CACHED_SUPPORT
        if(KAL_TRUE == gMSDC_Handle->isCachedBuf){
            if(MSDC_UNCACHED_BUF_SIZE < (4 * gMSDC_Handle->msdc_input.count))
    			ASSERT(0);
    
    	    if (DMA_HWRX == gMSDC_Handle->msdc_input.type) {
    		    /*copy to upper application's buffer*/
    		    kal_mem_cpy((void *)gMSDC_Handle->cachedBufCopyPtr, gMSDC_Handle->msdc_uncachedBufs[gMSDC_Handle->msdc_uncachedBufs_idx^1], msdc_input_prev);
    		    //dbg_print("NC read copy %d\n\r", msdc_input_prev);
    
    	    }
    	    //Shall be msdc_input_next for TX. However, it does not harm since they can be different only in final DMA segment
    	    gMSDC_Handle->cachedBufCopyPtr += msdc_input_prev; 
        }
    #endif

#else
    kal_set_eg_events(gMSDC_Handle->MSDC_Events,EVENT_DMAIRQ,KAL_OR);
#endif
}

kal_uint32 MSDC_DMATransferFinal(void)
{
#ifndef DRV_LSD
//	kal_uint32 total_count = gMSDC_Handle->total_count, t1;
	kal_uint32 t1;
	kal_bool is_poll = gMSDC_Handle->is_poll;
//	kal_bool is_aligned = gMSDC_Handle->is_aligned;
	kal_uint32 flags;

	flags = 0;
	
	gMSDC_Handle->msdc_uncachedBufs_idx=0;

	// wait until running bit clr
	if(gMSDC_Handle->msdc_input.type == DMA_HWTX)
		gMSDC_Handle->timeout_period <<= 2 ;
	if(gMSDC_Handle->mMSDC_type == MMC_CARD)
		gMSDC_Handle->timeout_period <<= 1;

    if(gMSDC_Handle->timeout_period > MSDC_TIMEOUT_PERIOD_DAT)
	    gMSDC_Handle->timeout_period = MSDC_TIMEOUT_PERIOD_DAT;

#ifdef __DRV_MSDC_FAST_FORMAT__
	if((KAL_TRUE == gMSDC_Handle->MSDC_fastFormat) && (gMSDC_Handle->mIsInitialized==KAL_TRUE))
		gMSDC_Handle->timeout_period = gMSDC_Handle->timeout_period<<3;
#endif

	t1 = drv_get_current_time();
	MSDC_START_TIMER(gMSDC_Handle->timeout_period);

/*#ifndef __MEUT__
	drv_trace2(TRACE_GROUP_7, MSDC_EVENTGP_MONITOR, ((EV_GCB *)gMSDC_Handle->MSDC_Events)->ev_current_events, __LINE__);
#endif*/
	#if defined(MSDC_TRACE_LEVEL3)
	MSDC_add_dbg_msg(msdc_dbg_event_DMA_RLCT_Monitor, MSDC_Reg(DMA_RLCT(gMSDC_Handle->msdc_dmaport)), MSDC_Reg(DMA_COUNT(gMSDC_Handle->msdc_dmaport)));
	#endif

	if(is_poll)
	{
		while(IS_MSDC_DMA_RUN(gMSDC_Handle->msdc_dmaport) && MSDC_Check_Card_Present() && !gMSDC_Handle->is_timeout)
		{
			if(drv_get_duration_ms(t1) > gMSDC_Handle->timeout_period*11)
				gMSDC_Handle->is_timeout = KAL_TRUE;
            else if(drv_get_duration_ms(t1)>10)
                    SD_Sleep4Wait(1);
		}
		#if defined(MSDC_TRACE_LEVEL3)
		MSDC_add_dbg_msg(msdc_dbg_event_SD_transfer_poll_end2, MSDC_Reg(DMA_RLCT(gMSDC_Handle->msdc_dmaport)), 0);
		#endif
		gMSDC_Handle->total_count-= gMSDC_Handle->msdc_input.count;
	}
	else
	{
#if defined(__UBL__) || defined(__FUE__)
	    ASSERT(0);
#endif
        
		kal_retrieve_eg_events(gMSDC_Handle->MSDC_Events,(EVENT_DMAIRQ),KAL_OR_CONSUME,&flags,KAL_SUSPEND);
		#if defined(MSDC_TRACE_LEVEL3)
		MSDC_add_dbg_msg(msdc_dbg_event_SD_transfer_event_retreived2, MSDC_Reg(DMA_RLCT(gMSDC_Handle->msdc_dmaport)), 0);
		#endif
	}
	MSDC_STOP_TIMER();

/*#ifndef __MEUT__
	drv_trace2(TRACE_GROUP_7, MSDC_EVENTGP_MONITOR, ((EV_GCB *)gMSDC_Handle->MSDC_Events)->ev_current_events, __LINE__);
#endif*/

    if (IS_MSDC_DMA_RUN(gMSDC_Handle->msdc_dmaport))
        return MSDC_GPT_TIMEOUT_ERR;

    /*copy data here if we need to do further transfer*/
    #ifdef MSDC_CACHED_SUPPORT
    	if(KAL_TRUE == gMSDC_Handle->isCachedBuf){
    		if(DMA_HWRX == gMSDC_Handle->msdc_input.type){
    			//copy to upper application's buffer
    			if(MSDC_UNCACHED_BUF_SIZE < (4 * gMSDC_Handle->msdc_input.count))
    				ASSERT(0);
    			kal_mem_cpy((void *)gMSDC_Handle->cachedBufCopyPtr, gMSDC_Handle->msdc_uncachedBufs[gMSDC_Handle->msdc_uncachedBufs_idx], 4 * gMSDC_Handle->msdc_input.count);
    		}
    	}
    #endif

    //if (gMSDC_Handle->total_count == 0) return MSDC_NOERROR;

	return MSDC_NOERROR; //FIX ME
#else
	return MSDC_NOERROR;
#endif
}
#endif
/*************************************************************************
* FUNCTION
*  MSDC_DMATransfer
*
* DESCRIPTION
*	MSDC using DAM for data transfer
*
* PARAMETERS
*	adrs: data buffer
*	count: bytes to be transfered
*	isTx: ture for move data from MSDC to data buffer and vise versa
*
* RETURNS
*
* GLOBALS AFFECTED
*
*
*************************************************************************/
extern kal_bool FTL_isPollingMode();
void MSDC_DMATransferFirst(kal_uint32 adrs, kal_uint32 count, kal_bool isTx)
{
#ifndef DRV_LSD
    kal_uint32 total_count;
    kal_bool is_aligned, is_poll;
	#if defined(MSDC_START_DMA_IN_CALLBACK)
	kal_uint32 msdc_input_next;
	#endif
	
	#if defined(MT6250)
	SW_SECVERSION sw_version=INT_SW_SecVersion();
	#endif

    DMA_Stop(gMSDC_Handle->msdc_dmaport);
    kal_set_eg_events(gMSDC_Handle->MSDC_Events, 0, KAL_AND);
#ifdef MSDC_CACHED_SUPPORT

    if (KAL_TRUE == gMSDC_Handle->isCachedBuf)
	    //BEGIN Light 120907
	    #if defined(MSDC_START_DMA_IN_CALLBACK)
	    //msdc_uncachedBufs_idx=0;
	    //msdc_uncachedBuf=gMSDC_Handle->msdc_uncachedBufs[0];
	    #endif
	    //END Light
    {

#if defined(MT6250)

        //
        // MT6250E1. DMA bug needs sw workaround.
        //
		if (sw_version == SW_SEC_0) 
        {

            if (isTx)
            {
                gMSDC_Handle->full_menu.source = (kal_uint32)msdc_uncachedBuf;
                gMSDC_Handle->full_menu.destination = MSDC_DAT;
            }
            else
            {
                gMSDC_Handle->full_menu.source = MSDC_DAT;
                gMSDC_Handle->full_menu.destination = (kal_uint32)msdc_uncachedBuf;
            }
        }
        else
#endif
            gMSDC_Handle->msdc_menu.addr = (kal_uint32)msdc_uncachedBuf;


        gMSDC_Handle->cachedBufCopyPtr = adrs;

#if defined(MT6250)

        if (sw_version == SW_SEC_0)
            adrs = (kal_uint32)msdc_uncachedBuf;

#endif
    }
    else
#endif
    {
#if defined(MT6250)

        if (sw_version == SW_SEC_0) 
        {
            if (isTx)
            {
                gMSDC_Handle->full_menu.source = adrs;
                gMSDC_Handle->full_menu.destination = MSDC_DAT;
            }
            else
            {
                gMSDC_Handle->full_menu.source = MSDC_DAT;
                gMSDC_Handle->full_menu.destination = adrs;
            }
        }
        else
#endif
            gMSDC_Handle->msdc_menu.addr = adrs;

    }

    if (isTx)
    {
        gMSDC_Handle->timeout_period = (50 + (count >> 5));
        gMSDC_Handle->msdc_input.type = DMA_HWTX;
#if defined(__UBL__) || defined(__FUE__)
        {
            gMSDC_Handle->msdc_input.callback = NULL;
            is_poll = KAL_TRUE;
        }
#else//defined(__UBL__) || defined(__FUE__)

        if (count <= MSDC_WRITE_THD_POLL)
            //if(0)
        {
            gMSDC_Handle->msdc_input.callback = NULL;
            is_poll = KAL_TRUE;
        }
        else
        {
            gMSDC_Handle->msdc_input.callback = MSDC_DMA_Callback;
            is_poll = KAL_FALSE;
        }

#endif//defined(__UBL__) || defined(__FUE__)
    }
    else
    {
        gMSDC_Handle->timeout_period = (50 + (count >> 7));
        gMSDC_Handle->msdc_input.type = DMA_HWRX;
#if defined(__UBL__) || defined(__FUE__)
        {
            gMSDC_Handle->msdc_input.callback = NULL;
            is_poll = KAL_TRUE;
        }
#else//defined(__UBL__) || defined(__FUE__)

        if (count <= MSDC_READ_THD_POLL)
            //if(0)
        {
            gMSDC_Handle->msdc_input.callback = NULL;
            is_poll = KAL_TRUE;
        }
        else
        {
            gMSDC_Handle->msdc_input.callback = MSDC_DMA_Callback;
            is_poll = KAL_FALSE;
        }

#endif//defined(__UBL__) || defined(__FUE__)
    }

    if (kal_query_systemInit() == KAL_TRUE
#ifdef  __TST_WRITE_TO_FILE__	/*error recording: considering error recording additionally*/
            || (KAL_TRUE == INT_QueryExceptionStatus())
#endif
            || (KAL_TRUE == FTL_isPollingMode())
       )
    {
        gMSDC_Handle->msdc_input.callback = NULL;
        is_poll = KAL_TRUE;
    }

    #if defined(MSDC_START_DMA_IN_CALLBACK)
    //Since no user claim to use cacheable buffer, use this check to verify if any user still use cacheable buffer
    if (KAL_TRUE == gMSDC_Handle->isCachedBuf) {
		kal_uint32 owner;
        if(isTx) {
            if (count>MSDC_WRITE_THD_POLL)
            	{
            		owner = (kal_uint32)kal_get_current_thread_ID();
					//dbg_print("count>MSDC_WRITE_THD_POLL,count=%d,threadID=%d",count,owner);
					drv_trace2(TRACE_GROUP_6, MSDC_INFORM_DMA_TRANSFER_CACHED_WRITE, count, owner);
					//drv_trace2(TRACE_GROUP_6, MSDC_INFORM_DMA_TRANSFER_CACHED_WRITE, total_count, owner);
                }
        } else {
            if (count>MSDC_READ_THD_POLL)
                {
            		owner = (kal_uint32)kal_get_current_thread_ID();
					//dbg_print("count>MSDC_READ_THD_POLL,count=%d,threadID=%d",count,owner);
					drv_trace2(TRACE_GROUP_6, MSDC_INFORM_DMA_TRANSFER_CACHED_READ, count, owner);
					//drv_trace2(TRACE_GROUP_6, MSDC_INFORM_DMA_TRANSFER_CACHED_READ, total_count, owner);
        }
    }
    }
    #endif
#ifndef MSDC_CACHED_SUPPORT

    if (adrs % 4 == 0)
    {
        is_aligned = KAL_TRUE;
        total_count = count;
    }
    else
    {
        is_aligned = KAL_FALSE;
        total_count = count << 2;
    }

#else

    if (adrs % 4 == 0 || KAL_TRUE == gMSDC_Handle->isCachedBuf)
    {
        is_aligned = KAL_TRUE;
        total_count = count;
    }
    else
    {
        is_aligned = KAL_FALSE;
        total_count = count << 2;
    }

#endif
    gMSDC_Handle->total_count = total_count;// this put lasting length to be transferred in this session
    gMSDC_Handle->is_poll = is_poll;
    gMSDC_Handle->is_aligned = is_aligned;
    {
        if (is_aligned)
        {
            if (KAL_TRUE == MSDC_useDMA4ByteBurst)
            {
                MSDC_SET_FIFO(4);

#if defined(MT6250)

                if (sw_version == SW_SEC_0)
                    gMSDC_Handle->full_menu.TMOD.burst_mode = KAL_TRUE;
                else
#endif

                    gMSDC_Handle->msdc_menu.TMOD.burst_mode = KAL_TRUE;

#if defined(DRV_MSDC_IOCON_MT6255_SERIES)
                BitFieldWrite32((kal_uint32*)MSDC_IOCON, (kal_uint32)1, MSDC_IOCON_DMABURST);
#endif
            }
            else
            {
                MSDC_SET_FIFO(1);

#if defined(MT6250)

                if (sw_version == SW_SEC_0)
                    gMSDC_Handle->full_menu.TMOD.burst_mode = KAL_FALSE;
                else
#endif

                    gMSDC_Handle->msdc_menu.TMOD.burst_mode = KAL_FALSE;

#if defined(DRV_MSDC_IOCON_MT6255_SERIES)
                BitFieldWrite32((kal_uint32*)MSDC_IOCON, (kal_uint32)0, MSDC_IOCON_DMABURST);
#endif
            }

#ifdef MSDC_CACHED_SUPPORT

            if (KAL_TRUE == gMSDC_Handle->isCachedBuf)
                gMSDC_Handle->msdc_input.count = (total_count > MSDC_UNCACHED_TRASNFER_SIZE) ? (MSDC_UNCACHED_TRASNFER_SIZE) : (total_count);
            else
#endif
			        gMSDC_Handle->msdc_input.count = (total_count > MSDC_DMA_BURSTLEN_LIMIT)?(MSDC_DMA_BURSTLEN_LIMIT):(total_count);

#ifdef MSDC_CACHED_SUPPORT

            if (KAL_TRUE == gMSDC_Handle->isCachedBuf)
            {
                /*have do memory copy stuff here*/
                if (DMA_HWTX == gMSDC_Handle->msdc_input.type)
                {
                    if (MSDC_UNCACHED_BUF_SIZE < (4 * gMSDC_Handle->msdc_input.count))
                        ASSERT(0);

                    /*copy from upper application buffer*/
                    kal_mem_cpy(msdc_uncachedBuf, (void *)gMSDC_Handle->cachedBufCopyPtr, 4 * gMSDC_Handle->msdc_input.count);
                    gMSDC_Handle->cachedBufCopyPtr += gMSDC_Handle->msdc_input.count * 4;
                }
            		#if defined(MSDC_START_DMA_IN_CALLBACK)
            		else { // DMA_HWRX == gMSDC_Handle->msdc_input.type
            		    if ( total_count>MSDC_UNCACHED_TRASNFER_SIZE )
                            gMSDC_Handle->msdc_input.count=MSDC_UNCACHED_TRASNFER_SIZE/2;
            	    }
            		#endif
            	}
#endif
            gMSDC_Handle->msdc_input.size = DMA_LONG;
#if defined(__DRV_MSDC_FAST_FORMAT__) && defined(__DMA_API_V2__)

            if ((KAL_TRUE == gMSDC_Handle->MSDC_fastFormat) && (gMSDC_Handle->mIsInitialized == KAL_TRUE))
            {
                gMSDC_Handle->msdc_input.fixed_pattern = KAL_TRUE; // enable DMA FIX_EN
                gMSDC_Handle->msdc_menu.addr = 0; // DMA FIX_PATTERN = 0;
            }
            else
                gMSDC_Handle->msdc_input.fixed_pattern = KAL_FALSE;

#endif
#if defined(MT6250)

            if (sw_version == SW_SEC_0)
                DMA_FullSize_Config(gMSDC_Handle->msdc_dmaport, &gMSDC_Handle->msdc_input, KAL_TRUE);
            else
#endif
                DMA_Config_B2W(gMSDC_Handle->msdc_dmaport, &gMSDC_Handle->msdc_input, KAL_TRUE, KAL_FALSE);


#if defined(__DRV_MSDC_FAST_FORMAT__) && !defined(__DMA_API_V2__)

            if ((KAL_TRUE == gMSDC_Handle->MSDC_fastFormat) && (gMSDC_Handle->mIsInitialized == KAL_TRUE))
            {
                MSDC_ClearBits32(DMA_CON(gMSDC_Handle->msdc_dmaport), DMA_CON_SINC);
            }
            //if (KAL_FALSE== gMSDC_Handle->MSDC_fastFormat)
            else //jinxing modify
#endif
            {
#ifdef MSDC_CACHED_SUPPORT

                /*we don't need to increase the addr when encounter cached buffer, since we only have a fix size uncached buffer to use*/
                if (KAL_FALSE == gMSDC_Handle->isCachedBuf)
#endif
                {
#if defined(MT6250)

                    if (sw_version == SW_SEC_0) 
                    {
                        if (isTx)
                        {
                            gMSDC_Handle->full_menu.source += gMSDC_Handle->msdc_input.count * 4;
                        }
                        else
                        {
                            gMSDC_Handle->full_menu.destination += gMSDC_Handle->msdc_input.count * 4;
                        }
                    }
                    else
#endif
                        gMSDC_Handle->msdc_menu.addr += gMSDC_Handle->msdc_input.count * 4;

                }
            }
        }
        else /*not aligned*/
        {
#ifdef MSDC_CACHED_SUPPORT

            if (KAL_TRUE == gMSDC_Handle->isCachedBuf)
                ASSERT(0);

#endif
            MSDC_SET_FIFO(1);

#if defined(DRV_MSDC_IOCON_MT6255_SERIES)
            BitFieldWrite32((kal_uint32*)MSDC_IOCON, (kal_uint32)0, MSDC_IOCON_DMABURST);
#endif

#if defined(MT6250)

            if (sw_version == SW_SEC_0)
                gMSDC_Handle->full_menu.TMOD.burst_mode = KAL_TRUE;
            else
#endif
                gMSDC_Handle->msdc_menu.TMOD.burst_mode = KAL_TRUE;

			gMSDC_Handle->msdc_input.count = (total_count > MSDC_DMA_BURSTLEN_LIMIT)?(MSDC_DMA_BURSTLEN_LIMIT):(total_count);
            gMSDC_Handle->msdc_input.size = DMA_BYTE;
#if defined(__DRV_MSDC_FAST_FORMAT__) && defined(__DMA_API_V2__)

            if ((KAL_TRUE == gMSDC_Handle->MSDC_fastFormat) && (gMSDC_Handle->mIsInitialized == KAL_TRUE))
            {
                gMSDC_Handle->msdc_input.fixed_pattern = KAL_TRUE; // enable DMA FIX_EN
                gMSDC_Handle->msdc_menu.addr = 0; // DMA FIX_PATTERN = 0;
            }
            else
                gMSDC_Handle->msdc_input.fixed_pattern = KAL_FALSE;

#endif
#if defined(MT6250)

			if (sw_version == SW_SEC_0)
                DMA_FullSize_Config(gMSDC_Handle->msdc_dmaport, &gMSDC_Handle->msdc_input, KAL_TRUE);
            else
#endif
                DMA_Config_B2W(gMSDC_Handle->msdc_dmaport, &gMSDC_Handle->msdc_input, KAL_TRUE, KAL_TRUE);


#if defined(MT6250)

            if (sw_version == SW_SEC_0) 
            {
                if (isTx)
                {
                    gMSDC_Handle->full_menu.source += gMSDC_Handle->msdc_input.count;
                }
                else
                {
                    gMSDC_Handle->full_menu.destination += gMSDC_Handle->msdc_input.count;
                }
            }
            else
#endif
                gMSDC_Handle->msdc_menu.addr += gMSDC_Handle->msdc_input.count;
        }

    }
#endif
    #ifdef MSDC_CACHED_SUPPORT
		if (KAL_TRUE == gMSDC_Handle->isCachedBuf) {
		    if(DMA_HWTX == gMSDC_Handle->msdc_input.type)
		        msdc_input_next = ((total_count-gMSDC_Handle->msdc_input.count) > MSDC_UNCACHED_TRASNFER_SIZE)?(MSDC_UNCACHED_TRASNFER_SIZE):(total_count-gMSDC_Handle->msdc_input.count);
		    else
			    msdc_input_next = ((total_count-gMSDC_Handle->msdc_input.count) > MSDC_UNCACHED_TRASNFER_SIZE/2)?(MSDC_UNCACHED_TRASNFER_SIZE/2):(total_count-gMSDC_Handle->msdc_input.count);
		} else
    #endif
		    msdc_input_next = ((total_count-gMSDC_Handle->msdc_input.count) > MSDC_DMA_BURSTLEN_LIMIT)?(MSDC_DMA_BURSTLEN_LIMIT):(total_count-gMSDC_Handle->msdc_input.count);
        gMSDC_Handle->msdc_input_next=msdc_input_next;
        
    //dbg_print("Total %d, current %d, next %d\n\r", total_count, gMSDC_Handle->msdc_input.count, msdc_input_next);
}
#if !defined(MSDC_START_DMA_IN_CALLBACK)
kal_uint32 MSDC_DMATransferFinal(void)
{
#ifndef DRV_LSD
    kal_uint32 total_count = gMSDC_Handle->total_count, t1;
    kal_bool is_poll = gMSDC_Handle->is_poll;
    kal_bool is_aligned = gMSDC_Handle->is_aligned;
    kal_uint32 flags;
	#if defined(MT6250)
	SW_SECVERSION sw_version=INT_SW_SecVersion();
	#endif

    flags = 0;

    while (1)
    {

        // wait until running bit clr
        if (gMSDC_Handle->msdc_input.type == DMA_HWTX)
            gMSDC_Handle->timeout_period <<= 2 ;

        if (gMSDC_Handle->mMSDC_type == MMC_CARD)
            gMSDC_Handle->timeout_period <<= 1;

        //if (gMSDC_Handle->timeout_period > MSDC_TIMEOUT_PERIOD_DAT)
        //    gMSDC_Handle->timeout_period = MSDC_TIMEOUT_PERIOD_DAT;
        //timeout max = 3S
        if (gMSDC_Handle->timeout_period > 300)
            gMSDC_Handle->timeout_period = 300;

#ifdef __DRV_MSDC_FAST_FORMAT__

        if ((KAL_TRUE == gMSDC_Handle->MSDC_fastFormat) && (gMSDC_Handle->mIsInitialized == KAL_TRUE))
            gMSDC_Handle->timeout_period = gMSDC_Handle->timeout_period << 3;

#endif

        t1 = drv_get_current_time();
        MSDC_START_TIMER(gMSDC_Handle->timeout_period);


#if defined(MSDC_TRACE_LEVEL3)
        MSDC_add_dbg_msg(msdc_dbg_event_DMA_RLCT_Monitor, MSDC_Reg(DMA_RLCT(gMSDC_Handle->msdc_dmaport)), MSDC_Reg(DMA_COUNT(gMSDC_Handle->msdc_dmaport)));
#endif

        if (is_poll)
        {
            while (IS_MSDC_DMA_RUN(gMSDC_Handle->msdc_dmaport) && MSDC_Check_Card_Present() && !gMSDC_Handle->is_timeout)
            {
                if (drv_get_duration_ms(t1) > gMSDC_Handle->timeout_period * 11)
                    gMSDC_Handle->is_timeout = KAL_TRUE;
                else if(drv_get_duration_ms(t1)>10)
                    SD_Sleep4Wait(2);
            }

#if defined(MSDC_TRACE_LEVEL3)
            MSDC_add_dbg_msg(msdc_dbg_event_SD_transfer_poll_end2, MSDC_Reg(DMA_RLCT(gMSDC_Handle->msdc_dmaport)), 0);
#endif
        }
        else
        {
#if defined(__UBL__) || defined(__FUE__)
            ASSERT(0);
#endif
            kal_retrieve_eg_events(gMSDC_Handle->MSDC_Events, (EVENT_DMAIRQ), KAL_OR_CONSUME, &flags, KAL_SUSPEND);
#if defined(MSDC_TRACE_LEVEL3)
            MSDC_add_dbg_msg(msdc_dbg_event_SD_transfer_event_retreived2, MSDC_Reg(DMA_RLCT(gMSDC_Handle->msdc_dmaport)), 0);
#endif
        }

        MSDC_STOP_TIMER();

        if (IS_MSDC_DMA_RUN(gMSDC_Handle->msdc_dmaport) && gMSDC_Handle->is_timeout)
            return MSDC_GPT_TIMEOUT_ERR;

        total_count -= gMSDC_Handle->msdc_input.count;

        /*copy data here if we need to do further transfer*/
#ifdef MSDC_CACHED_SUPPORT

        if (KAL_TRUE == gMSDC_Handle->isCachedBuf)
        {
            /*have do memory copy stuff here*/
            if (DMA_HWTX == gMSDC_Handle->msdc_input.type)
            {

                if ( total_count != 0 ) //Light 2012/02/01
                {

                    /*copy from upper application buffer*/
                    if (MSDC_UNCACHED_BUF_SIZE < (4 * gMSDC_Handle->msdc_input.count))
                        ASSERT(0);

                    //! fix unexpected memory access during MSDC_DMATransferFinal() in TX
                    kal_mem_cpy(
                        msdc_uncachedBuf,
                        (void *)gMSDC_Handle->cachedBufCopyPtr,
                        4 * ((total_count > MSDC_UNCACHED_TRASNFER_SIZE) ? (MSDC_UNCACHED_TRASNFER_SIZE) : (total_count)));
                    //kal_mem_cpy(msdc_uncachedBuf, (void *)gMSDC_Handle->cachedBufCopyPtr, 4 * gMSDC_Handle->msdc_input.count);
                }

            }
            else
            {
                /*copy to upper application's buffer*/
                if (MSDC_UNCACHED_BUF_SIZE < (4 * gMSDC_Handle->msdc_input.count))
                    ASSERT(0);

                kal_mem_cpy((void *)gMSDC_Handle->cachedBufCopyPtr, msdc_uncachedBuf, 4 * gMSDC_Handle->msdc_input.count);
            }

            gMSDC_Handle->cachedBufCopyPtr += gMSDC_Handle->msdc_input.count * 4;
        }

#endif

        if (total_count == 0) break;

        //Comment out Light 120628
        //if (IS_MSDC_DMA_RUN(gMSDC_Handle->msdc_dmaport))
        //    return MSDC_GPT_TIMEOUT_ERR;

        if (is_aligned)
        {
            if (KAL_TRUE == MSDC_useDMA4ByteBurst)
            {
                MSDC_SET_FIFO(4);

#if defined(MT6250)

                if (sw_version == SW_SEC_0)
                    gMSDC_Handle->full_menu.TMOD.burst_mode = KAL_TRUE;
                else
#endif

                    gMSDC_Handle->msdc_menu.TMOD.burst_mode = KAL_TRUE;

#if defined(DRV_MSDC_IOCON_MT6255_SERIES)
                BitFieldWrite32((kal_uint32*)MSDC_IOCON, (kal_uint32)1, MSDC_IOCON_DMABURST);
#endif
            }
            else
            {
                MSDC_SET_FIFO(1);

#if defined(MT6250)

                if (sw_version == SW_SEC_0)
                    gMSDC_Handle->full_menu.TMOD.burst_mode = KAL_FALSE;
                else
#endif

                    gMSDC_Handle->msdc_menu.TMOD.burst_mode = KAL_FALSE;

#if defined(DRV_MSDC_IOCON_MT6255_SERIES)
                BitFieldWrite32((kal_uint32*)MSDC_IOCON, (kal_uint32)0, MSDC_IOCON_DMABURST);
#endif
            }

            /*if this is cached transfer and this is last read transfer, we have to do copy*/
#ifdef MSDC_CACHED_SUPPORT

            if (KAL_TRUE == gMSDC_Handle->isCachedBuf)
                gMSDC_Handle->msdc_input.count = (total_count > MSDC_UNCACHED_TRASNFER_SIZE) ? (MSDC_UNCACHED_TRASNFER_SIZE) : (total_count);
            else
#endif
			gMSDC_Handle->msdc_input.count = (total_count > MSDC_DMA_BURSTLEN_LIMIT)?(MSDC_DMA_BURSTLEN_LIMIT):(total_count);

            gMSDC_Handle->msdc_input.size = DMA_LONG;
#if defined(__DRV_MSDC_FAST_FORMAT__) && defined(__DMA_API_V2__)

            if ((KAL_TRUE == gMSDC_Handle->MSDC_fastFormat) && (gMSDC_Handle->mIsInitialized == KAL_TRUE))
            {
                gMSDC_Handle->msdc_input.fixed_pattern = KAL_TRUE; // enable DMA FIX_EN
                gMSDC_Handle->msdc_menu.addr = 0; // DMA FIX_PATTERN = 0;
            }
            else
                gMSDC_Handle->msdc_input.fixed_pattern = KAL_FALSE;

#endif
#if defined(MT6250)

			if (sw_version == SW_SEC_0)
                DMA_FullSize_Config(gMSDC_Handle->msdc_dmaport, &gMSDC_Handle->msdc_input, KAL_TRUE);
            else
#endif
                DMA_Config_B2W(gMSDC_Handle->msdc_dmaport, &gMSDC_Handle->msdc_input, KAL_TRUE, KAL_FALSE);

#if defined(__DRV_MSDC_FAST_FORMAT__) && !defined(__DMA_API_V2__)

            if ((KAL_TRUE == gMSDC_Handle->MSDC_fastFormat) && (gMSDC_Handle->mIsInitialized == KAL_TRUE))
            {
                MSDC_ClearBits32(DMA_CON(gMSDC_Handle->msdc_dmaport), DMA_CON_SINC);
            }
            //if (KAL_FALSE== gMSDC_Handle->MSDC_fastFormat)
            else
#endif
            {
#ifdef MSDC_CACHED_SUPPORT

                /*we don't need to increase the addr when encounter cached buffer, since we only have a fix size uncached buffer to use*/
                if (KAL_FALSE == gMSDC_Handle->isCachedBuf)
#endif
                {
                    gMSDC_Handle->msdc_menu.addr += gMSDC_Handle->msdc_input.count * 4;
                }
            }

            //gMSDC_Handle->timeout_period = (50 + (gMSDC_Handle->msdc_input.count>>5));
        }
        else
        {
#ifdef MSDC_CACHED_SUPPORT

            if (KAL_TRUE == gMSDC_Handle->isCachedBuf)
                ASSERT(0);

#endif
            MSDC_SET_FIFO(1);
            gMSDC_Handle->msdc_menu.TMOD.burst_mode = KAL_TRUE;

			gMSDC_Handle->msdc_input.count = (total_count > MSDC_DMA_BURSTLEN_LIMIT)?(MSDC_DMA_BURSTLEN_LIMIT):(total_count);
            gMSDC_Handle->msdc_input.size = DMA_BYTE;
#if defined(__DRV_MSDC_FAST_FORMAT__) && defined(__DMA_API_V2__)

            if ((KAL_TRUE == gMSDC_Handle->MSDC_fastFormat) && (gMSDC_Handle->mIsInitialized == KAL_TRUE))
            {
                gMSDC_Handle->msdc_input.fixed_pattern = KAL_TRUE; // enable DMA FIX_EN
                gMSDC_Handle->msdc_menu.addr = 0; // DMA FIX_PATTERN = 0;
            }
            else
                gMSDC_Handle->msdc_input.fixed_pattern = KAL_FALSE;

#endif
#if defined(MT6250)

			if (sw_version == SW_SEC_0)
                DMA_FullSize_Config(gMSDC_Handle->msdc_dmaport, &gMSDC_Handle->msdc_input, KAL_TRUE);
            else
#endif
                DMA_Config_B2W(gMSDC_Handle->msdc_dmaport, &gMSDC_Handle->msdc_input, KAL_TRUE, KAL_TRUE);

            gMSDC_Handle->msdc_menu.addr += gMSDC_Handle->msdc_input.count;
            //gMSDC_Handle->timeout_period = (50 + (gMSDC_Handle->msdc_input.count>>5));
        }

        gMSDC_Handle->timeout_period = (50 + (gMSDC_Handle->msdc_input.count >> 5));

    }

    return MSDC_NOERROR;
#else
    return MSDC_NOERROR;
#endif
}
#endif //!defined(MSDC_START_DMA_IN_CALLBACK)

#endif // DMA

void* GetMsdcHandle(kal_uint8 id)
{
    return (void*)&MSDC_Blk[id];
}

#ifdef R1B_INTERRUPT_MODE
static void MSDC_R1B_Init()
{
    //close all the Interrupt source except R1b Interrupt.
    //	MSDC_SetBits32(MSDC_CFG, MSDC_CFG_DIRQE);
    //[DIRQ]disable Data Request Interrupt.
    MSDC_ClearBits32(MSDC_CFG, MSDC_CFG_DIRQE);

    //[PINIRQ]
    //this interrpt is set or clear before enter this function.

    //[SDCMDIRQ]
    //[SDDATIRQ]
    MSDC_WriteReg32(MSDC_IRQMASK0, 0xffffffff);
    //[SDMCIRQ]
    //[MSIFIRQ]
    //Memory Stick Interrupt was disable.
    MSDC_CLR_INT();
    MSDC_ENABLE_INT();// (deactive)
    IRQUnmask(IRQ_MSDC_CODE);
}
#endif

// ===========================================================
//     MSDC common lock
// ===========================================================

#if !defined(__FUE__) && !defined(__UBL__)

void init_MSDC_lock(PMSDC_LOCK_TAG lock, const kal_char *str)
{
    if (lock->mtd_mutex == NULL)
    {
        strcpy((char *)lock->name, str);
        lock->mtd_mutex = kal_create_mutex((kal_char *)lock->name);
        lock->lock_count = 0;
        lock->owner_id = NULL;
    }
}

static kal_uint8 msdc_lock_user = 0;

void get_MSDC_lock(PMSDC_LOCK_TAG lock)
{
    if (msdc_lock_user > 0)
        ;//ASSERT(0); // init debugging purpose
    else
        msdc_lock_user ++;

    if ( kal_query_systemInit() || INT_QueryExceptionStatus() )
        return;

    if (kal_if_hisr() == KAL_TRUE || kal_if_lisr() == KAL_TRUE)
    {
        kal_uint32 retaddr0 = 0;
        GET_RETURN_ADDRESS(retaddr0);
        EXT_ASSERT(0, retaddr0, 0, 0);
    }

    if ( kal_get_current_task() == lock->owner_id )
    {
        force_ASSERT(0 != lock->lock_count, lock->lock_count, (kal_uint32)lock->owner_id, (kal_uint32)lock->mtd_mutex);
        lock->lock_count++;
    }
    else
    {
        if (lock->mtd_mutex == NULL)
        {
            init_MSDC_lock(lock, (const kal_char *)lock->name);
        }

        kal_take_mutex(lock->mtd_mutex);
     //   lock->owner_id = kal_get_task_self_id();
     		lock->owner_id = kal_get_current_task();
        lock->lock_count++;
    }
}

void free_MSDC_lock(PMSDC_LOCK_TAG lock)
{
    if (msdc_lock_user != 1)
        ;//ASSERT(0); // init debugging purpose
    else
        msdc_lock_user --;

    if ( kal_query_systemInit() || INT_QueryExceptionStatus() )
        return;

    if ( kal_get_current_task() == lock->owner_id )
    {
        force_ASSERT(lock->lock_count > 0, lock->lock_count, (kal_uint32)lock->owner_id, (kal_uint32)lock->mtd_mutex);
        lock->lock_count--;

        if (0 == lock->lock_count)
        {
            lock->owner_id = NULL;

            if (lock->mtd_mutex != NULL)
                kal_give_mutex(lock->mtd_mutex);
        }
    }
    else
    {
        force_ASSERT(0, (kal_uint32)lock->owner_id, (kal_uint32)kal_get_current_task(), (kal_uint32)lock->mtd_mutex);
    }
}

#else /* __FUE__, __UBL__ */

//#define init_MSDC_lock(x)

//#define get_MSDC_lock(x)

//#define free_MSDC_lock(x)

#endif /* !defined(__FUE__) && !defined(__UBL__) */

#ifdef MSDC_INT

#ifdef USE_INT26_CARD_DETECTION
void MSDC_CardDetect_LISR(void)
{
    IRQMask(IRQ_MSDC_CD_CODE);
    gMSDC_Handle->mIsChanged = KAL_TRUE;
    drv_active_hisr(DRV_MSDC_HISR_ID);
}
#endif //USE_INT26_CARD_DETECTION


#ifdef DRV_LSD
kal_uint32 MSDC_CARD_INSERT_COUNTER, MSDC_CARD_REMOVE_COUNTER;
kal_uint32 notifiedFMT;//this variable is to sync the state, since we only allow FMT get disk infor to be the first operation that access SD


void MSDC_LSD_HISR(void)
{
    static kal_bool pre_IsPresent = KAL_TRUE; // it works only at first time

    if (pre_IsPresent)
        pre_IsPresent = gMSDC_Handle->mIsPresent;

    if (LSD_cardInsertion == LSD_cardDetection())
    {
        gMSDC_Handle->mIsPresent = KAL_TRUE;
        MSDC_CARD_INSERT_COUNTER ++;
    }
    else if (LSD_cardRemoval == LSD_cardDetection())
    {
        gMSDC_Handle->mIsPresent = KAL_FALSE;
        MSDC_CARD_REMOVE_COUNTER++;
    }
    else
        ASSERT(0);

    // if the card is present during power on, then the
    // card detection interrup of INT26 will always generated. This interrupt should be ignored.
    if (pre_IsPresent && gMSDC_Handle->mIsPresent && gMSDC_Handle->mIsInitialized )
    {
        pre_IsPresent = KAL_FALSE;
        gMSDC_Handle->mIsInitialized = KAL_TRUE;
        return;
    }
    else
        gMSDC_Handle->mIsInitialized = KAL_FALSE;

    if (gMSDC_Handle->mIsPresent == KAL_FALSE)
    {
        MSDC_CLR_FIFO();
        MSDC_CLR_INT();
        MSDC_CLR_INT();
        //TurnOffMSDC();
    }

    if (gMSDC_Handle->mIsPresent)
    {
        notifiedFMT = 0;
    }

#if !defined(FMT_NOT_PRESENT)
    MSDC_SendCardInd(MOD_FMT, SD_EXT, MSG_ID_MSDC_CARD_DETECT_IND);
#endif
    /*
    if(LSD_cardInsertion == LSD_cardDetection()){
    	MSDC_CARD_INSERT_COUNTER ++;
    }
    else if(LSD_cardRemoval == LSD_cardDetection()){
    	MSDC_CARD_REMOVE_COUNTER++;
    }
    else
    	ASSERT(0);
    */
}


/*this function will be called once by FMT while booting up, used to let FMT send meesage to itself*/
void NotifyFMTWhenCardPresent(void)
{
    /*in LSD solution, mIsPresent is true without card plugging out, so we aslo have to check initialied*/
    if (gMSDC_Handle->mIsPresent && gMSDC_Handle->mIsInitialized)
    {
        gMSDC_Handle->send_ilm = KAL_TRUE;
#if !defined(FMT_NOT_PRESENT)
        MSDC_SendCardInd(MOD_FMT, SD_EXT, MSG_ID_MSDC_CARD_DETECT_IND);
#endif
    }

}

void MSDC_unsealMountOperation(void)
{
    /*notifiedFMT may be modified by FMT and MMI tasks, but it is no need to protect this, any task that preempt FMT just get mount fail*/
    if (1 == notifiedFMT) /*FMT may call this function no matter card exits or not*/
    {
        notifiedFMT = 2;
    }

}
#endif

/*************************************************************************
* FUNCTION
*  MSDC_INT_Init
*
* DESCRIPTION
*	Initialize MSDC's interrupt
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*
*************************************************************************/
void MSDC_INT_Init(void)
{
#ifdef  __TST_WRITE_TO_FILE__

    /*error recording: it mens this functions is called twice, just return*/
    if (KAL_TRUE == INT_QueryExceptionStatus())
        return;

#endif
    gMSDC_Handle->MSDC_Events = kal_create_event_group("MSDC Events");

#if defined( __SIM_PLUS__)
    MSDC_Blk[SD_SIM].MSDC_Events = gMSDC_Handle->MSDC_Events;
#elif defined( DRV_MSDC_SD_SDIO_SHARE_BY_SWITCH)
    MSDC_Blk[SD_SDIO].MSDC_Events = gMSDC_Handle->MSDC_Events;
#elif defined( DRV_MSDC_DUAL_TCARD_BY_SWITCH)
    MSDC_Blk[SD_T_CARD_2].MSDC_Events = gMSDC_Handle->MSDC_Events;
#endif

#ifndef DRV_LSD
    DRV_Register_HISR(DRV_MSDC_HISR_ID, MSDC_HISR_Entry);
#ifndef MSDC_TEST_MSDC2_FROM_MSDC1_CODE
    IRQ_Register_LISR(IRQ_MSDC_CODE, MSDC_LISR, "MSDC ISR");
    IRQSensitivity(IRQ_MSDC_CODE, LEVEL_SENSITIVE);
    IRQUnmask(IRQ_MSDC_CODE);
#else
    IRQ_Register_LISR(IRQ_MSDC2_CODE, MSDC_LISR, "MSDC ISR");
    IRQSensitivity(IRQ_MSDC2_CODE, LEVEL_SENSITIVE);
    IRQUnmask(IRQ_MSDC2_CODE);
#endif
    // enable MSDC interrupt
    MSDC_CLR_INT();
#if !defined(MSDC_USE_INT)
    MSDC_DISABLE_INT();// (active)turn off other interrupt event except pin interrupt
#else
    MSDC_ENABLE_INT();// (deactive)
#endif

#ifdef USE_INT26_CARD_DETECTION
    // for card detection
    IRQ_Register_LISR(IRQ_MSDC_CD_CODE, MSDC_CardDetect_LISR, "MSDC CD ISR");
    IRQSensitivity(IRQ_MSDC_CD_CODE, EDGE_SENSITIVE);
    IRQUnmask(IRQ_MSDC_CD_CODE);
#if !defined(MSDC_USE_INT)
    IRQMask(IRQ_MSDC_CODE);
#endif
#endif //USE_INT26_CARD_DETECTION
#else
#ifndef __MSDC_NOT_SUPPORT_HOT_PLUG__
    LSD_HISR_Registration();
#endif
#endif
}
void MSDC_LISR(void)
{
#ifndef DRV_LSD
    //mask IRQ.
#ifndef MSDC_TEST_MSDC2_FROM_MSDC1_CODE
    IRQMask(IRQ_MSDC_CODE);
#else
    IRQMask(IRQ_MSDC2_CODE);
#endif
    //this is debug information.
#ifdef R1B_DEBUG
    gMSDC_Handle->LISR_Entry_Count++;
#endif

    //IRQMask(IRQ_MSDC_CODE);
    gMSDC_Handle->msdc_int = MSDC_Reg(MSDC_INTR);

    if (gMSDC_Handle->msdc_int & MSDC_INT_PINIRQ)
    {
#ifdef DRV_MSDC_CLK_SEARCH
        gMSDC_Handle->msdc_clkTuneUpperBund = MSDC_CLOCK / 2;
        MSDC_ClearBits32(MSDC_IOCON, MSDC_IOCON_CMDRE);
#endif
    }

    drv_active_hisr(DRV_MSDC_HISR_ID);

#endif
}
/*************************************************************************
* FUNCTION
*  MSDC_HISR_Entry
*
* DESCRIPTION
*	Set corresponding enevt and wake up waiting task.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*
*************************************************************************/
void MSDC_HISR_Entry(void)
{
    //register kal_uint16 msdc_int = 0;
    kal_uint16 msdc_ps = 0;
#if !defined(USE_INT26_CARD_DETECTION)&&(defined(__SIM_PLUS__)|| defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH))
    kal_bool previos_present = KAL_FALSE;
#endif

#if defined(MT6250)
    DCL_HANDLE handle;
    PMU_CTRL_LDO_BUCK_SET_STB_EN ldo_buck_set_stb_en;
#endif

#if defined(__MSDC_MS__)||defined(__MSDC_MSPRO__)
    kal_uint16 msc_sta;

    FS_MspDrvAll = FS_MspDrv;
#if defined (USE_INT26_CARD_DETECTION)

    if (gMSDC_Handle->mIsChanged == KAL_TRUE)
    {
        static kal_bool pre_IsPresent = KAL_TRUE; // it works only at first time

        if (pre_IsPresent)
            pre_IsPresent = gMSDC_Handle->mIsPresent;

#if defined(MSDC_USE_INT)
        kal_set_eg_events(gMSDC_Handle->MSDC_Events,
                          (EVENT_SDCMDIRQ | EVENT_SDDATIRQ | EVENT_SDMCIRQ | EVENT_SDR1BIRQ | EVENT_DMAIRQ),
                          KAL_OR);
#endif//defined(MSDC_USE_INT)
        //TurnOnMSDC();
        MSDC_PDNControl(KAL_FALSE);

        if (MSDC_Reg(MSDC_PS) & MSDC_PS_PIN0)
        {
            if (gMSDC_Handle->ins_level == MSDC_IOCTRL_PULL_UP)
                gMSDC_Handle->mIsPresent = KAL_FALSE;
            else
                gMSDC_Handle->mIsPresent = KAL_TRUE;
        }
        else
        {
            if (gMSDC_Handle->ins_level == MSDC_IOCTRL_PULL_UP)
                gMSDC_Handle->mIsPresent = KAL_TRUE;
            else
                gMSDC_Handle->mIsPresent = KAL_FALSE;
        }

        // use INT26 as the card detection, if the card is present during power on, then the
        // card detection interrup of INT26 will always generated. This interrupt should be ignored.
        if (pre_IsPresent && gMSDC_Handle->mIsPresent && gMSDC_Handle->mIsInitialized )
        {
            pre_IsPresent = KAL_FALSE;
            gMSDC_Handle->mIsInitialized = KAL_TRUE;
            IRQUnmask(IRQ_MSDC_CD_CODE);
            return;
        }
        else
            gMSDC_Handle->mIsInitialized = KAL_FALSE;

        if (gMSDC_Handle->mIsPresent == KAL_FALSE)
        {
            MSDC_CLR_FIFO();
            MSDC_CLR_INT();
            MSDC_CLR_INT();
            //TurnOffMSDC();
            DMA_Stop(gMSDC_Handle->msdc_dmaport);
        }

#if !defined(FMT_NOT_PRESENT)
        MSDC_SendCardInd(MOD_FMT, SD_EXT, MSG_ID_MSDC_CARD_DETECT_IND);
#endif//!defined(FMT_NOT_PRESENT)
        IRQUnmask(IRQ_MSDC_CD_CODE);
        return;
    }

#endif//defined (USE_INT26_CARD_DETECTION)
    //TurnOnMSDC();
    MSDC_PDNControl(KAL_FALSE);
    msc_sta = MSDC_Reg(MSC_STA);

    if (msc_sta & MSC_STA_SIF)
        kal_set_eg_events(gMSDC_Handle->MSDC_Events, EVENT_MSIFIRQ, KAL_OR);
    else
        kal_set_eg_events(gMSDC_Handle->MSDC_Events, EVENT_MSRDYIRQ, KAL_OR);

    msdc_int = MSDC_Reg(MSDC_INTR);
#if !defined(USE_INT26_CARD_DETECTION)

    if (msdc_int & MSDC_INT_PINIRQ)
    {
        gMSDC_Handle->mIsInitialized = KAL_FALSE;
        gMSDC_Handle->mIsChanged = KAL_TRUE;
        kal_set_eg_events(gMSDC_Handle->MSDC_Events,
                          (EVENT_MSIFIRQ | EVENT_DMAIRQ | EVENT_MSRDYIRQ),
                          KAL_OR);

        if (MSDC_Reg(MSDC_PS) & MSDC_PS_PIN0)
        {
            if (gMSDC_Handle->ins_level == MSDC_IOCTRL_PULL_UP)
                gMSDC_Handle->mIsPresent = KAL_FALSE;
            else
                gMSDC_Handle->mIsPresent = KAL_TRUE;
        }
        else
        {
            if (gMSDC_Handle->ins_level == MSDC_IOCTRL_PULL_UP)
                gMSDC_Handle->mIsPresent = KAL_TRUE;
            else
                gMSDC_Handle->mIsPresent = KAL_FALSE;
        }

#ifdef MSDC_MUST_RECORD_PLUGOUT

        if (KAL_FALSE == gMSDC_Handle->mIsPresent)
            gMSDC_Handle->MSDC_everPlugOut = KAL_TRUE;

#endif

        if (gMSDC_Handle->mIsPresent == KAL_FALSE)
        {
            MSDC_CLR_FIFO();
            MSDC_CLR_INT();
            MSDC_CLR_INT();
            //TurnOffMSDC();
            DMA_Stop(gMSDC_Handle->msdc_dmaport);
        }		//dbg_print("MSDC_HISR present %d \r\n",gMSDC_Handle->mIsPresent);

#if !defined(FMT_NOT_PRESENT)
        MSDC_SendCardInd(MOD_FMT, SD_EXT, MSG_ID_MSDC_CARD_DETECT_IND);
#endif//!defined(FMT_NOT_PRESENT)
        //MSDC_PDNControl(KAL_TRUE);
    }

#endif//!defined(USE_INT26_CARD_DETECTION)
#else//defined(__MSDC_MS__)||defined(__MSDC_MSPRO__)
#if defined (USE_INT26_CARD_DETECTION)
#if defined(__SIM_PLUS__)
    {
        MSDC_Blk[SD_EXT].mIsInitialized = KAL_FALSE;
        MSDC_Blk[SD_EXT].mIsChanged = KAL_TRUE;

        if (MSDC_Reg(MSDC_PS) & MSDC_PS_PIN0)
        {
            if (MSDC_Blk[SD_EXT].ins_level == MSDC_IOCTRL_PULL_UP)
                MSDC_Blk[SD_EXT].mIsPresent = KAL_FALSE;
            else
                MSDC_Blk[SD_EXT].mIsPresent = KAL_TRUE;
        }
        else
        {
            if (MSDC_Blk[SD_EXT].ins_level == MSDC_IOCTRL_PULL_UP)
                MSDC_Blk[SD_EXT].mIsPresent = KAL_TRUE;
            else
                MSDC_Blk[SD_EXT].mIsPresent = KAL_FALSE;
        }

        /*bewlow comes after JRD SIM+ issue on 2007_03_08, give power, this should be temperary solution for jrd*/
        if (MSDC_NO_EXT_LDO != GPIO_EXT_SD_LDO_SWITCH)
        {
            if (KAL_TRUE == gMSDC_Handle->mIsPresent)
                GPIO_WriteIO(1, GPIO_EXT_SD_LDO_SWITCH);
            else if (KAL_FALSE == gMSDC_Handle->mIsPresent)
                GPIO_WriteIO(0, GPIO_EXT_SD_LDO_SWITCH);
        }

        /*end of changes of JRD SIM+ issue on 2007_03_08*/
        if (MSDC_Blk[SD_EXT].mIsPresent == KAL_FALSE && current_card == SD_EXT)
        {
            MSDC_CLR_FIFO();
            MSDC_CLR_INT();
            MSDC_CLR_INT();
            DMA_Stop(gMSDC_Handle->msdc_dmaport);
        }

#if !defined(FMT_NOT_PRESENT)
        MSDC_SendCardInd(MOD_FMT, SD_EXT, MSG_ID_MSDC_CARD_DETECT_IND);
#endif

#else//defined(__SIM_PLUS__)

    if (gMSDC_Handle->mIsChanged == KAL_TRUE)
    {
        static kal_bool pre_IsPresent = KAL_TRUE; // it works only at first time

        if (pre_IsPresent)
            pre_IsPresent = gMSDC_Handle->mIsPresent;

#if defined(MSDC_USE_INT)
        kal_set_eg_events(gMSDC_Handle->MSDC_Events,
                          (EVENT_SDCMDIRQ | EVENT_SDDATIRQ | EVENT_SDMCIRQ | EVENT_SDR1BIRQ | EVENT_DMAIRQ),
                          KAL_OR);
#endif
        //TurnOnMSDC();
        MSDC_PDNControl(KAL_FALSE);

        if (MSDC_Reg(MSDC_PS) & MSDC_PS_PIN0)
        {
            if (gMSDC_Handle->ins_level == MSDC_IOCTRL_PULL_UP)
                gMSDC_Handle->mIsPresent = KAL_FALSE;
            else
                gMSDC_Handle->mIsPresent = KAL_TRUE;
        }
        else
        {
            if (gMSDC_Handle->ins_level == MSDC_IOCTRL_PULL_UP)
                gMSDC_Handle->mIsPresent = KAL_TRUE;
            else
                gMSDC_Handle->mIsPresent = KAL_FALSE;
        }

        // use INT26 as the card detection, if the card is present during power on, then the
        // card detection interrup of INT26 will always generated. This interrupt should be ignored.
        if (pre_IsPresent && gMSDC_Handle->mIsPresent && gMSDC_Handle->mIsInitialized )
        {
            pre_IsPresent = KAL_FALSE;
            gMSDC_Handle->mIsInitialized = KAL_TRUE;
            IRQUnmask(IRQ_MSDC_CD_CODE);
            return;
        }
        else
            gMSDC_Handle->mIsInitialized = KAL_FALSE;

#ifdef MSDC_MUST_RECORD_PLUGOUT

        if (KAL_FALSE == gMSDC_Handle->mIsPresent)
            gMSDC_Handle->MSDC_everPlugOut = KAL_TRUE;

#endif

        if (gMSDC_Handle->mIsPresent == KAL_FALSE)
        {
            MSDC_CLR_FIFO();
            MSDC_CLR_INT();
            MSDC_CLR_INT();
            //TurnOffMSDC();
            DMA_Stop(gMSDC_Handle->msdc_dmaport);
        }

#if !defined(FMT_NOT_PRESENT)
        MSDC_SendCardInd(MOD_FMT, SD_EXT, MSG_ID_MSDC_CARD_DETECT_IND);
#endif
#endif//defined(__SIM_PLUS__)
        IRQUnmask(IRQ_MSDC_CD_CODE);
        return;
    }

#endif//defined (USE_INT26_CARD_DETECTION)
    //TurnOnMSDC();
    MSDC_PDNControl(KAL_FALSE);
    //msdc_int = MSDC_Reg(MSDC_INTR);
#if defined(MSDC_USE_INT) || defined(R1B_INTERRUPT_MODE)

    if (gMSDC_Handle->msdc_int & MSDC_INT_SDCMDIRQ)
    {
#ifdef R1B_DEBUG
        gMSDC_Handle->SDCMDIRQ_Entry_Count++;
#endif
        kal_set_eg_events(gMSDC_Handle->MSDC_Events, EVENT_SDCMDIRQ, KAL_OR);
    }

    if (gMSDC_Handle->msdc_int & MSDC_INT_SDDATIRQ)
    {
#ifdef R1B_DEBUG
        gMSDC_Handle->SDDATIRQ_Entry_Count++;
#endif
        kal_set_eg_events(gMSDC_Handle->MSDC_Events, EVENT_SDDATIRQ, KAL_OR);

    }

    if (gMSDC_Handle->msdc_int & MSDC_INT_SDMCIRQ)
    {
#ifdef R1B_DEBUG
        gMSDC_Handle->SDMCIRQ_Entry_Count++;
#endif
        kal_set_eg_events(gMSDC_Handle->MSDC_Events, EVENT_SDMCIRQ, KAL_OR);

    }

    if (gMSDC_Handle->msdc_int & MSDC_INT_SDR1BIRQ)
    {
#ifdef R1B_DEBUG
        gMSDC_Handle->SDR1bIRQ_Entry_count++;
#endif
        kal_set_eg_events(gMSDC_Handle->MSDC_Events, EVENT_SDR1BIRQ, KAL_OR);
    }

#endif//defined(MSDC_USE_INT)

#if defined(__MSDC_SD_MMC__)&&defined(__MSDC_SD_SDIO__)

    /*SDIO*/
    if (gMSDC_Handle->msdc_int & MSDC_INT_SDIOIRQ)
    {
#ifdef R1B_DEBUG
        gMSDC_Handle->SDIOIRQ_Entry_Count++;
#endif
        SDIO_HISR_Entry();
    }

#endif//defined(__MSDC_SD_MMC__)&&defined(__MSDC_SD_SDIO__)

#if !defined(USE_INT26_CARD_DETECTION)
#if defined(__SIM_PLUS__)|| defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)

    if (gMSDC_Handle->msdc_int & MSDC_INT_PINIRQ)
    {
        previos_present = MSDC_Blk[SD_EXT].mIsPresent;
        MSDC_Blk[SD_EXT].mIsInitialized = KAL_FALSE;
        MSDC_Blk[SD_EXT].mIsChanged = KAL_TRUE;

        if (MSDC_Reg(MSDC_PS) & MSDC_PS_PIN0)
        {
            if (MSDC_Blk[SD_EXT].ins_level == MSDC_IOCTRL_PULL_UP)
                MSDC_Blk[SD_EXT].mIsPresent = KAL_FALSE;
            else
                MSDC_Blk[SD_EXT].mIsPresent = KAL_TRUE;
        }
        else
        {
            if (MSDC_Blk[SD_EXT].ins_level == MSDC_IOCTRL_PULL_UP)
                MSDC_Blk[SD_EXT].mIsPresent = KAL_TRUE;
            else
                MSDC_Blk[SD_EXT].mIsPresent = KAL_FALSE;
        }

        /*bewlow comes after JRD SIM+ issue on 2007_03_08, give power, this should be temperary solution for jrd*/
#if defined(__SIM_PLUS__)

        if (MSDC_NO_EXT_LDO != GPIO_EXT_SD_LDO_SWITCH)
        {
            if (KAL_TRUE == gMSDC_Handle->mIsPresent)
                GPIO_WriteIO(1, GPIO_EXT_SD_LDO_SWITCH);
            else if (KAL_FALSE == gMSDC_Handle->mIsPresent)
                GPIO_WriteIO(0, GPIO_EXT_SD_LDO_SWITCH);
        }

#endif

        /*end of changes of JRD SIM+ issue on 2007_03_08*/
        //if(MSDC_Blk[SD_EXT].mIsPresent == KAL_FALSE && current_card == SD_EXT)
        if (MSDC_Blk[SD_EXT].mIsPresent == KAL_FALSE)
        {
#if 0
#ifdef MSDC_3538_DMA_STOP_ISSUE
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef MSDC_3538_DMA_STOP_ISSUE
/* under construction !*/
/* under construction !*/
#endif
#endif
#if defined(__MSDC_DUAL_CARD_SWITCH__) && !defined(__MSDC_NOT_SUPPORT_HOT_PLUG__)

            if (previos_present != MSDC_Blk[SD_EXT].mIsPresent)
                MSDC_SendCardInd(MOD_MMI, SD_EXT, MSG_ID_MSDC_CARD_DETECT_IND);

#endif
        }
        else
        {
#if !defined(FMT_NOT_PRESENT)
#if defined(__MSDC_DUAL_CARD_SWITCH__) && !defined(__MSDC_NOT_SUPPORT_HOT_PLUG__)

            if (previos_present != MSDC_Blk[SD_EXT].mIsPresent)
            {
                MSDC_SendCardInd(MOD_MMI, SD_EXT, MSG_ID_MSDC_CARD_DISPLAY_IND);
                MSDC_SendCardInd(MOD_MMI, SD_EXT, MSG_ID_MSDC_CARD_DETECT_IND);
            }

#endif
#endif
        }

        drv_trace4(TRACE_GROUP_6, MSDC_INFORM_HOTPLUG, gMSDC_Handle->msdc_int, msdc_ps, MSDC_Blk[SD_EXT].mIsPresent, drv_get_current_time());


        /*
	#if !defined(FMT_NOT_PRESENT)
	#if defined(__MSDC_DUAL_CARD_SWITCH__) && !defined(__MSDC_NOT_SUPPORT_HOT_PLUG__)
                // in dual T-card support hot-plug in feature.
                // Message was transmit by MMI to FMI.
                // MMI will remove plug-in / plug-out message in pairs.
                //so we should make sure not send Message(with same status) twice.
                // very seldom, this Interrupt was trigger by mechanism. [MAUI_03013157]
        		//if(previos_present!=MSDC_Blk[SD_EXT].mIsPresent) {
        		//MSDC_SendCardInd(MOD_MMI, SD_EXT, MSG_ID_MSDC_CARD_DISPLAY_IND);
        		//MSDC_SendCardInd(MOD_MMI, SD_EXT);
        		MSDC_SendCardInd(MOD_MMI, SD_EXT, MSG_ID_MSDC_CARD_DETECT_IND);
        	    //}
	#else
        	    //MSDC_SendCardInd(MOD_MMI, SD_EXT, MSG_ID_MSDC_CARD_DISPLAY_IND);
        		//MSDC_SendCardInd(MOD_FMT, SD_EXT, MSG_ID_MSDC_CARD_DETECT_IND);
	#endif
	#endif	
        */
#else // __SIM_PLUS__

    msdc_ps = MSDC_Reg(MSDC_PS);
#ifdef __MSDC_CD_EINT__
    drv_trace4(TRACE_GROUP_6, MSDC_INFORM_HOTPLUG, gMSDC_Handle->msdc_int, cardDetectionEINTPolarity, gMSDC_Handle->mIsPresent, drv_get_current_time());

    //
    // To-do how to check it is EINT int.
    //
    if (!gMSDC_Handle->msdc_int)
    {
        EINT_Mask(MSDC_EINT_NO);

#else

    if (gMSDC_Handle->msdc_int & MSDC_INT_PINIRQ)
    {
#endif
#ifdef R1B_DEBUG
        gMSDC_Handle->SDPINIRQ_Entry_Count++;
#endif
#ifdef MSDC_TRACE_LEVEL1
        drv_trace4(TRACE_GROUP_6, MSDC_INFORM_HOTPLUG, gMSDC_Handle->msdc_int, msdc_ps, gMSDC_Handle->mIsPresent, drv_get_current_time());
#endif
        gMSDC_Handle->mIsInitialized = KAL_FALSE;
        gMSDC_Handle->mIsChanged = KAL_TRUE;
#if defined(MSDC_USE_INT) || defined(R1B_INTERRUPT_MODE)
        kal_set_eg_events(gMSDC_Handle->MSDC_Events,
                          (EVENT_SDCMDIRQ | EVENT_SDDATIRQ | EVENT_SDMCIRQ | EVENT_SDR1BIRQ | EVENT_DMAIRQ),
                          KAL_OR);
#endif//defined(MSDC_USE_INT)

#ifdef __MSDC_CD_EINT__

        if (EINT_DefaultPolarity == KAL_TRUE)
        {
            gMSDC_Handle->mIsPresent = ((cardDetectionEINTPolarity) ? KAL_FALSE : KAL_TRUE);
        }
        else
        {
            gMSDC_Handle->mIsPresent = ((cardDetectionEINTPolarity) ? KAL_TRUE : KAL_FALSE);
        }

#else
#if defined (WISDOM35B_DEMO_BB)

        if (!(msdc_ps & MSDC_PS_PIN0))
#else//defined (WISDOM35B_DEMO_BB)
        if (msdc_ps & MSDC_PS_PIN0)
#endif//defined (WISDOM35B_DEMO_BB)
        {
            if (gMSDC_Handle->ins_level == MSDC_IOCTRL_PULL_UP)
                gMSDC_Handle->mIsPresent = KAL_FALSE;
            else
                gMSDC_Handle->mIsPresent = KAL_TRUE;
        }
        else
        {
            if (gMSDC_Handle->ins_level == MSDC_IOCTRL_PULL_UP)
                gMSDC_Handle->mIsPresent = KAL_TRUE;
            else
                gMSDC_Handle->mIsPresent = KAL_FALSE;
        }

#endif

#ifdef __MSDC_CD_EINT__
        //cardDetectionEINTPolarity = gMSDC_Handle->mIsPresent;
        cardDetectionEINTPolarity = ((cardDetectionEINTPolarity) ? KAL_FALSE : KAL_TRUE);
        EINT_Set_Polarity(MSDC_EINT_NO, cardDetectionEINTPolarity);
        EINT_UnMask(MSDC_EINT_NO);
#endif

#if defined (WISDOM35B_DEMO_BB)

        if (gMSDC_Handle->mIsPresent)
            GPIO_WriteIO(0, gpio_SD_det_pin);
        else
            GPIO_WriteIO(1, gpio_SD_det_pin);

#endif//defined (WISDOM35B_DEMO_BB)

        if (gMSDC_Handle->mIsPresent == KAL_FALSE)
        {
            if (gMSDC_Handle->msdc_custom_handle.PowerCtrl)
                gMSDC_Handle->msdc_custom_handle.PowerCtrl(KAL_FALSE);
        }

#ifdef MSDC_MUST_RECORD_PLUGOUT

        if (KAL_FALSE == gMSDC_Handle->mIsPresent)
            gMSDC_Handle->MSDC_everPlugOut = KAL_TRUE;

#endif//MSDC_MUST_RECORD_PLUGOUT

        if (gMSDC_Handle->mIsPresent == KAL_FALSE)
        {
#ifdef MSDC_3538_DMA_STOP_ISSUE
            /*7/7, disable MSDC's DMA before turning off DMA channel*/
            DisableMSDC_DMA();
            RESET_MSDC();
            MSDC_SetBits32(MSDC_CFG, MSDC_CFG_FIFOTHD);
#endif//MSDC_3538_DMA_STOP_ISSUE

            MSDC_CLR_FIFO();
            MSDC_CLR_INT();
            MSDC_CLR_INT();
            //TurnOffMSDC();
            DMA_Stop(gMSDC_Handle->msdc_dmaport);
#ifdef MSDC_3538_DMA_STOP_ISSUE
            MSDC_ClearBits32(MSDC_CFG, MSDC_CFG_FIFOTHD);
            MSDC_SetBits32(MSDC_CFG, MSDC_CFG_FIFOTHD_1);
#endif//MSDC_3538_DMA_STOP_ISSUE

#if defined(MT6250)

            if (INT_SW_SecVersion() == SW_SEC_0)
            {
                handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
                ldo_buck_set_stb_en.mod = VMC;
                ldo_buck_set_stb_en.enable = DCL_TRUE;
                DclPMU_Control(handle, LDO_BUCK_SET_STB_EN, (DCL_CTRL_DATA_T *)&ldo_buck_set_stb_en);
                DclPMU_Close(handle);
            }

#endif
						MSDC_turnOnVMC(gMSDC_Handle->mIsPresent);
						MSDC_PDNControl(KAL_TRUE);
        }
        else
        {
#if !defined(MT6250) && !defined(MSDC_SD_BITS4_BUS) && !defined(FMT_NOT_PRESENT)
            MSDC_SendCardInd(MOD_MMI, SD_EXT, MSG_ID_MSDC_CARD_DISPLAY_IND);
#endif
        }

#if !defined(FMT_NOT_PRESENT)

        if (gMSDC_Handle->msdc_custom_handle.IsCardInd)
        {
            if (gMSDC_Handle->msdc_custom_handle.IsCardInd())
                MSDC_SendCardInd(MOD_FMT, SD_EXT, MSG_ID_MSDC_CARD_DETECT_IND);
        }
        else
        {
            MSDC_SendCardInd(MOD_FMT, SD_EXT, MSG_ID_MSDC_CARD_DETECT_IND);
        }

#endif//!defined(FMT_NOT_PRESENT)

#endif//defined(__SIM_PLUS__)
        // Set the power down bit too fast will cause MSDC failed to detect next card plug in/out
        // So, move it to GetCardStatus
        //MSDC_PDNControl(KAL_TRUE);
    }

#endif//!defined(USE_INT26_CARD_DETECTION)

#endif//defined(__MSDC_MS__)||defined(__MSDC_MSPRO__)

#ifndef DRV_LSD
#ifndef MSDC_TEST_MSDC2_FROM_MSDC1_CODE
    IRQUnmask(IRQ_MSDC_CODE);
#else
    IRQUnmask(IRQ_MSDC2_CODE);
#endif
#endif
}

/*************************************************************************
* FUNCTION
*  MSDC_DMA_Callback
*
* DESCRIPTION
*	Call back while DMA has done the data transfer.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*
*************************************************************************/
void MSDC_DMA_Callback(void)
{
#if defined(MSDC_TRACE_LEVEL3)
    MSDC_add_dbg_msg(msdc_dbg_event_DMA_done, MSDC_Reg(DMA_RLCT(gMSDC_Handle->msdc_dmaport)), 0);
#endif

    #if !defined(MSDC_START_DMA_IN_CALLBACK)	
    kal_set_eg_events(gMSDC_Handle->MSDC_Events, EVENT_DMAIRQ, KAL_OR);
	#else
	    MSDC_DMATransferFinal_In_Callback();
	#endif
}

#ifdef DRV_MSDC_SHARE_BY_SWITCH
MSDC_changeSwContext(sd_select_enum sel)
{
    gMSDC_Handle = &MSDC_Blk[sel];
    gSD = &gSD_blk[sel];
}

/*
	this function do not consider race condition issue, caller should make sure this function is called without risk
	currently, this function is called in sdio_drv.c and sd_drv.c
*/
MSDC_backupHwSetting()
{
    /*backup MSDC_CFG, MSDC_IOCON, SDC_CFG*/
    gMSDC_Handle->setting_MSDC_CFG = MSDC_Reg32(MSDC_CFG);
    gMSDC_Handle->setting_MSDC_IOCON = MSDC_Reg32(MSDC_IOCON);
    gMSDC_Handle->setting_SDC_CFG = MSDC_Reg32(SDC_CFG);
}

MSDC_retreiveHwSetting()
{
    MSDC_WriteReg32(MSDC_CFG, gMSDC_Handle->setting_MSDC_CFG);
    MSDC_WriteReg32(MSDC_IOCON, gMSDC_Handle->setting_MSDC_IOCON);
    MSDC_WriteReg32(SDC_CFG, gMSDC_Handle->setting_SDC_CFG);
}
#endif

#if defined(__SIM_PLUS__) || defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
void MSDC_Switch_Card(sd_select_enum sel)
{
    DCL_HANDLE handle;

    if (current_card == sel)
        return;

    ENTER_CRITICAL();
    current_card = sel;

    /*bewlow comes after JRD SIM+ issue on 2007_03_08, use custom setting instead of fix value*/
    if (GPIO_SELECT_MSDC == sel)
    {
        //GPIO_WriteIO(MSDC_GetSwitchDirection(), GPIO_SIM_MSDC_SWITCH); // replaced by DCL
        handle = DclGPIO_Open(DCL_GPIO, GPIO_SIM_MSDC_SWITCH);

        if (0 == MSDC_GetSwitchDirection())
            DclGPIO_Control(handle, GPIO_CMD_WRITE_LOW, 0);
        else if (1 == MSDC_GetSwitchDirection())
            DclGPIO_Control(handle, GPIO_CMD_WRITE_HIGH, 0);
        else
        {
            DclGPIO_Close(handle);
            ASSERT(0);
        }

        DclGPIO_Close(handle);
    }
    else if (GPIO_SELECT_SIM == sel)
    {
        //GPIO_WriteIO(1-MSDC_GetSwitchDirection(), GPIO_SIM_MSDC_SWITCH); // replaced by DCL
        handle = DclGPIO_Open(DCL_GPIO, GPIO_SIM_MSDC_SWITCH);

        if (0 == (1 - MSDC_GetSwitchDirection()))
            DclGPIO_Control(handle, GPIO_CMD_WRITE_LOW, 0);
        else if (1 == (1 - MSDC_GetSwitchDirection()))
            DclGPIO_Control(handle, GPIO_CMD_WRITE_HIGH, 0);
        else
        {
            DclGPIO_Close(handle);
            ASSERT(0);
        }

        DclGPIO_Close(handle);
    }
    else
        ASSERT(0);

    /*end of changes of JRD SIM+ issue on 2007_03_08*/

    MSDC_changeSwContext(sel);
    EXIT_CRITICAL();

#if defined(__SIM_PLUS__)

    if (MSDC_Blk[SD_EXT].mIsInitialized || MSDC_Blk[SD_SIM].mIsInitialized)
    {
        //MSDC_SetClock(gMSDC_Handle->op_clock);
        if (gSD->bus_width == 4)
        {
            MSDC_LSD_SetBits32(SDC_CFG, SDC_CFG_MDLEN);
        }
        else
        {
            MSDC_LSD_ClearBits32(SDC_CFG, SDC_CFG_MDLEN);
        }
    }

#elif defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)

    MSDC_retreiveHwSetting();
    /*
    	if(MSDC_Blk[SD_EXT].mIsInitialized || MSDC_Blk[SD_T_CARD_2].mIsInitialized)
    	{
    		if(gSD->bus_width == 4){
    			MSDC_LSD_SetBits32(SDC_CFG,SDC_CFG_MDLEN);
    		}
    		else{
    			MSDC_LSD_ClearBits32(SDC_CFG,SDC_CFG_MDLEN);
    		}

    	}
    */
#endif
}
#endif

#endif //end of MSDC_INT


void MSDC_turnOnVMC(kal_bool turnOnLdo)
{
    DCL_HANDLE handle;
    PMU_CTRL_LDO_BUCK_SET_EN val;
#if defined(MT6256)||defined(MT6255)||((defined(__UBL__) || defined(__FUE__)) && defined(MT6236))
    PMU_CTRL_LDO_BUCK_SET_VOLTAGE val1;
#endif
#ifdef DRV_MSDC_VMC_CTRL
    /*
    	currently, we just call the PMIC API to control the LDO.
    	We have to add debug information here so that we can assert on race conditions.
    */
#if (defined(__UBL__) || defined(__FUE__)) && defined(MT6236)
    //pmu6236_vmc_enable(turnOnLdo); // replaced by DCL
    handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
    val1.voltage = PMU_VOLT_03_300000_V;
    val1.mod = VMC;
    DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&val1);

    val.enable = turnOnLdo;
    val.mod = VMC;
    DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
    DclPMU_Close(handle);
#else
    //pmic_adpt_vmc_enable(turnOnLdo); // replaced by DCL
    val.enable = turnOnLdo;
    val.mod = VMC;
    handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
    DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
    DclPMU_Close(handle);
#endif
#if defined(MT6256)||defined(MT6255)//||defined(MT6280)
    val1.voltage = PMU_VOLT_03_300000_V;
    val1.mod = VMC;
    handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
    DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&val1);

    val.enable = turnOnLdo;
    val.mod = VMC;
    DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
    DclPMU_Close(handle);

#endif

#endif
}

#if defined(MSDC_TRACE_LEVEL3)
void MSDC_add_dbg_msg( msdc_dbg_Event event, kal_uint32 data1, kal_uint32 data2)
{
#if !defined(LOW_COST_SUPPORT) && !defined(DRV_LSD) && defined(__DRV_DBG_MEMORY_TRACE_SUPPORT__) && !defined(__UBL__)
    kal_uint32 bufIndex;
    msdc_debugMessage *msg;

    if (0 == msdc_msgArray)
        ASSERT(0);

    ENTER_CRITICAL();
    bufIndex = msdc_msdIndex;

    if (MSDC_DBG_ARRAY_MASK == msdc_msdIndex)
        msdc_msdIndex = 0;
    else
        msdc_msdIndex ++;

    EXIT_CRITICAL();
    msg = &msdc_msgArray[bufIndex];

    msg->event = event;
    msg->data32_0 = data1;
    msg->data32_1 = data2;
    msg->time = drv_get_current_time();
#endif
}
#endif

#ifdef DRV_MSDC_SD_SDIO_SHARE_BY_SWITCH
void MSDC_Switch_SDIO(sd_select_enum sel)
{
    if (sel == current_card)
    {
        return;
    }

    /*1. switch SW context*/
    ENTER_CRITICAL();
    current_card = sel;
    MSDC_changeSwContext(sel);
    EXIT_CRITICAL();

    /*2. MSDC setting: MSDC_CFG, MSDC_IOCON, SDC_CFG according to SW context*/
    MSDC_retreiveHwSetting();


    /*3. control HW switch GPIO*/
    MSDC_Switch(sel);

}
#endif

#ifdef DRV_MSDC_SD_SDIO_SHARE_BY_SWITCH

/*following should be the value defined in custom files*/
#define MSDC_SWITCH_2_SD		1
#define MSDC_SWITCH_2_SDIO	0
#define MSDC_SWITCH_GPIO		20
typedef enum
{
    MSDC_SWITCH_DIRECTION_SD,
    MSDC_SWITCH_DIRECTION_SDIO
} MSDC_SWITCH_DIRECTION;


MSDC_Switch_init()
{
    DCL_HANDLE handle;

    //GPIO_WriteIO(0, MSDC_SWITCH_GPIO); // replaced by DCL
    handle = DclGPIO_Open(DCL_GPIO, MSDC_SWITCH_GPIO);
    DclGPIO_Control(handle, GPIO_CMD_WRITE_LOW, 0);
    DclGPIO_Close(handle);
    //GPIO_ModeSetup(MSDC_SWITCH_GPIO, 0); // replaced by DCL
    handle = DclGPIO_Open(DCL_GPIO, MSDC_SWITCH_GPIO);
    DclGPIO_Control(handle, GPIO_CMD_SET_MODE_0, 0);
    DclGPIO_Close(handle);
    //GPIO_InitIO(OUTPUT,MSDC_SWITCH_GPIO); // replaced by DCL
    handle = DclGPIO_Open(DCL_GPIO, MSDC_SWITCH_GPIO);
    DclGPIO_Control(handle, GPIO_CMD_SET_DIR_OUT, 0);
    DclGPIO_Close(handle);
}

/*
	direction:
		0 :	cmmb
		1 :	sd card
*/

MSDC_Switch(sd_select_enum direction)
{
    DCL_HANDLE handle;

    if (SD_EXT == direction)
    {
        //GPIO_WriteIO(MSDC_SWITCH_2_SD, MSDC_SWITCH_GPIO); // replaced by DCL
        handle = DclGPIO_Open(DCL_GPIO, MSDC_SWITCH_GPIO);
        DclGPIO_Control(handle, GPIO_CMD_WRITE_HIGH, 0);
        DclGPIO_Close(handle);
    }
    else if (SD_SDIO == direction)
    {
        //GPIO_WriteIO(MSDC_SWITCH_2_SDIO, MSDC_SWITCH_GPIO); // replaced by DCL
        handle = DclGPIO_Open(DCL_GPIO, MSDC_SWITCH_GPIO);
        DclGPIO_Control(handle, GPIO_CMD_WRITE_LOW, 0);
        DclGPIO_Close(handle);
    }
    else
        ASSERT(0);
}
#endif


#else
#ifdef DRV_LSD
void MSDC_LSD_HISR(void)
{
}
#endif
#endif // end of  (defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__))
#endif//!defined(__UBL__) || defined(__CARD_DOWNLOAD__) || defined(__EMMC_BOOTING__)

#else //DRV_MSDC_OFF
#include "kal_public_api.h" //MSBB change #include "kal_release.h"
#include "msdc_def.h"

/*
#include "kal_public_api.h" //MSBB change #include "kal_release.h"
//RHR REMOVE
#include "syscomp_config.h"
#include "task_config.h"
#include "stacklib.h"
#include "eint.h"
#include "fat_fs.h"
*/
//RHR
#include "kal_public_defs.h" //MSBB change #include "stack_common.h"  
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "kal_public_api.h" //MSBB change #include "app_ltlcom.h"     
#include "intrCtrl.h"
#include "reg_base.h"
#include "drvpdn.h"
//#include "gpt_sw.h"
#include "drv_comm.h"
#include "dma_hw.h"
#include "dma_sw.h"
#include "drv_hisr.h"
#include "msdc_def.h"

/*here are dummy API*/
void MSDC_Initialize(void) {}
void MSDC_PDNControl(kal_bool ON) {}
int MSDC_GetCardStatus(void * DriveData, int AckType) {return 0;}
//kal_bool MSDC_GetMediaChanged(void * id) {}
kal_bool MSDC_GetMediaChanged(sd_select_enum id) {return 0;}
MSDC_HANDLE MSDC_Blk[SD_NUM];
MSDC_HANDLE	*gMSDC_Handle = &(MSDC_Blk[0]);
//kal_bool MSDC_everPlugOut;


#endif //DRV_MSDC_OFF
