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
 *   hisr_config_internal.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file provides the HISR config parameter
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
//#include "module_hisrid_range.h"

           /*NO. Enum_Name  Name       priority     stack_size       callback_function     INT/EXT RAM*/
/*service*/
#if !defined(__MAUI_BASIC__) && !defined(__MEUT__) && defined(__MTK_TARGET__)
X_HISR_CONST((HISR_ID_SS_CODE_BEGIN + 1),   TRCPRCHISR,   "TRC_PRC_HISR",1,584,trc_process_HisrEntry,KAL_FALSE)
X_HISR_MOD((HISR_ID_SS_CODE_BEGIN + 1), MOD_TRCPRCHISR)
#endif

#if (defined(__LOGACC_ENABLE__) || defined(__TST_DNT_LOGGING__)) && !defined(__MAUI_BASIC__) && !defined(__MEUT__) && defined(__MTK_TARGET__)
X_HISR_CONST((HISR_ID_SS_CODE_BEGIN + 2),   LGAHISR,   "LGA_HISR",2,1024,Lga_HisrEntry,KAL_FALSE)
X_HISR_MOD((HISR_ID_SS_CODE_BEGIN + 2), MOD_LGAHISR)
#endif

#if defined(__MTK_TARGET__)
#if defined(__NUCLEUS_VERSION_2__)
X_HISR_CONST((HISR_ID_SS_CODE_BEGIN + 3),   TIMER_HISR,   "TIMER_HISR", 2, 768, TMC_Timer_HISR, KAL_FALSE)
#else
X_HISR_CONST((HISR_ID_SS_CODE_BEGIN + 3),   TIMER_HISR,   "TIMER_HISR", 2, 512, TMC_Timer_HISR, KAL_FALSE)
#endif /* __NUCLEUS_VERSION_2__ */
#else
X_HISR_CONST((HISR_ID_SS_CODE_BEGIN + 3),   TIMER_HISR,   "TIMER_HISR", 2, 1024, OSC_Timer_HISR, KAL_FALSE)
#endif
X_HISR_MOD((HISR_ID_SS_CODE_BEGIN + 3), MOD_TIMER_HISR)

#if defined(__IS_BYTECOPY_SUPPORT__) && defined(__MTK_TARGET__)
X_HISR_CONST((HISR_ID_SS_CODE_BEGIN + 4), BC_HISR, "BC_HISR", 1, 2048, bc_isr_hisr, KAL_FALSE)
X_HISR_MOD((HISR_ID_SS_CODE_BEGIN + 4), MOD_BCHISR)
#endif
/* service end */

/* modem start */
#if (defined(__MTK_TARGET__) && !defined(__MAUI_BASIC__)) || defined (__UE_SIMULATOR__)
X_HISR_CONST((HISR_ID_MODEM_CODE_BEGIN + 1),   L1_HISR,   "L1_HISR", 0, 2248, L1I_WakeTask, KAL_FALSE)
#endif
X_HISR_MOD((HISR_ID_MODEM_CODE_BEGIN + 1), MOD_L1HISR)

#if defined(__UMTS_RAT__) && defined(__UMTS_FDD_MODE__) && (defined(__MTK_TARGET__) || defined (__UE_SIMULATOR__))
X_HISR_CONST((HISR_ID_MODEM_CODE_BEGIN + 2),   UMTS_HISR,   "UMTS_HISR", 0, 2048, UL1C_HISR, KAL_FALSE)
X_HISR_MOD((HISR_ID_MODEM_CODE_BEGIN + 2), MOD_UMTS_HISR)
#endif

#if (defined(__UL1_HS_PLATFORM__) || defined(__UL1_HS_PLUS_PLATFORM__))  && defined(__UMTS_FDD_MODE__) && (defined(__MTK_TARGET__) || defined (__UE_SIMULATOR__))
X_HISR_CONST((HISR_ID_MODEM_CODE_BEGIN + 3),   UL1D_REAL_HISR,   "UL1D_REAL_HISR", 0, 1024, UL1D_RealHISR, KAL_FALSE)
X_HISR_MOD((HISR_ID_MODEM_CODE_BEGIN + 3), MOD_UL1_LOW_HISR)

X_HISR_CONST((HISR_ID_MODEM_CODE_BEGIN + 4),   UL2HISR,   "UL2HISR", 0, 2048, UL1D_UL2HISR, KAL_FALSE)
X_HISR_MOD((HISR_ID_MODEM_CODE_BEGIN + 4), MOD_UUL2HISR)
#endif

#if defined(__RLC_HSDPA_COPRO__) && defined(__MTK_TARGET__)
X_HISR_CONST((HISR_ID_MODEM_CODE_BEGIN + 5),   UL2SEQ_HISR, "UL2SEQ_HISR", 1, 1024, seq_isr_hisr, KAL_FALSE)
#endif
#ifdef  __UMTS_RAT__
X_HISR_MOD((HISR_ID_MODEM_CODE_BEGIN + 5), MOD_UL2ACCRXHISR)
#endif /* __UMTS_RAT__ */

#if defined(__HSDPA_SUPPORT__) && defined(__MTK_TARGET__) && !defined(__L1_STANDALONE__) && defined(__UMTS_FDD_MODE__)
X_HISR_CONST((HISR_ID_MODEM_CODE_BEGIN + 6),   UL2BCP_HISR,   "UL2BCP_HISR", 1, 512, bcp_isr_hisr, KAL_FALSE)
X_HISR_MOD((HISR_ID_MODEM_CODE_BEGIN + 6), MOD_UL2BCP_HISR)
#endif

#if defined(__UMTS_TDD128_MODE__) && defined(__AST_TL1_TDD__)
X_HISR_CONST((HISR_ID_MODEM_CODE_BEGIN + 7), TL1_HISR, "TL1_HISR", 0, 760, tl1_m_h_entry, KAL_FALSE)
X_HISR_MOD((HISR_ID_MODEM_CODE_BEGIN + 7), MOD_TL1HISR)
#endif

#if defined(__MTK_TARGET__) && defined(__UMTS_TDD128_MODE__) && defined(__AST_TL1_TDD__)
X_HISR_CONST((HISR_ID_MODEM_CODE_BEGIN + 8), HIF_CB_HISR, "HIF_CB_HISR", 0, 1000, ast_hif_cb_hisr, KAL_FALSE)
X_HISR_MOD((HISR_ID_MODEM_CODE_BEGIN + 8), MOD_HIF_CB_HISR)
#endif
/* modem end */

/* drv start */
#if defined(__MTK_TARGET__)
X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 1),   DRVHISR,   "DRVHISR", 1,           1280,            DRV_HISR,             KAL_FALSE)
#endif
X_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 1), MOD_DRV_HISR)

#if defined(__MTK_TARGET__) && !defined(__MAUI_BASIC__) && !defined(__MEUT__)
X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 2),   L1AUDIO_HISR,   "L1Audio_HISR", 1, 768, L1Audio_HISR, KAL_FALSE)
#endif
X_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 2), MOD_L1SPHISR)

#if !defined(__MTK_TARGET__)
X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 3),   UARTHISR,   "UART_HISR", 2, 512,UART_HISR,KAL_FALSE)
X_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 3), MOD_UARTHISR)
#endif
/* drv end */


