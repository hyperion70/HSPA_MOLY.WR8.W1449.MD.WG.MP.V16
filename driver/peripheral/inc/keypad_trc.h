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

/*******************************************************************************
 * Filename:
 * ---------
 *   keypad_trc.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is trace map definition for keypad driver
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
#ifndef _KEYPAD_TRC_H
#define _KEYPAD_TRC_H


#ifndef GEN_FOR_PC

   #ifndef _STACK_CONFIG_H
   #error "stack_config.h should be included before tst_config.h"
   #endif

#else
   #include "kal_trace.h"
#endif /* GEN_FOR_PC */


#ifndef _KAL_TRACE_H
   #error "kal_trace.h should be included before tst_trace.h"
#endif

#if !defined(GEN_FOR_PC)
#if defined(__TST_MODULE__) || defined(__CUSTOM_RELEASE__)
    #include "keypad_trc_gen.h"
#endif /* TST Trace Defintion */
#endif
BEGIN_TRACE_MAP(MOD_DRVKBD)

   TRC_MSG(KBD_REPEAT_HANDLER_NO_ROOM,"KBD repeat handler: no room for repeated event")
   TRC_MSG(KBD_LONGPRESS_HANDLER_NO_ROOM,"KBD longpress handler: no room for longpress event")
   TRC_MSG(KBD_2STEP_KEY_HANDLER_NO_ROOM,"KBD 2-step key handler: no room for 2-step key event")
   TRC_MSG(KBD_PUT_DATA_TO_BUFFER,"KBD put data to ring buffer: event: %d, data: %d")
   TRC_MSG(KBD_PUT_TWO_DATA_TO_BUFFER,"KBD put data to ring buffer: event: %d, data1: %d, data2: %d")
   TRC_MSG(KBD_GET_TWO_KEY_DATA,"KBD get two key: event: %d, data1: %d, data2: %d")
   TRC_MSG(KBD_GET_ONE_KEY_DATA,"KBD get one key: event: %d, data: %d")
   TRC_MSG(KBD_DETECT_MODE_SWITCH,"KBD detect mode switch to %d")
   TRC_MSG(KBD_DETECT_MODE_SWITCH_NOT_SUPPORT,"KBD detect mode switch not supported")
   TRC_MSG(KBD_EXT_A_B_KEY_SUPPORT,"KBD extra A, B key support")
   TRC_MSG(KBD_EXT_2STEP_KEY_SUPPORT,"KBD 2-step key support")
   TRC_MSG(KBD_MULTIPLE_KEY,"KBD %d is a multiple key")
   TRC_MSG(KBD_NOT_MULTIPLE_KEY,"KBD %d is NOT a multiple key")
   TRC_MSG(KBD_2STEP_KEY_QUERY,"KBD 2-step key: %d")
   TRC_MSG(KBD_KEY_QUERY_SUPPORTED,"KBD key: %d is supported")
   TRC_MSG(KBD_KEY_QUERY_NOT_SUPPORTED,"KBD key: %d is NOT supported")
   
   

	
END_TRACE_MAP(MOD_DRVKBD)

#endif /* _TP_TRC_H */


