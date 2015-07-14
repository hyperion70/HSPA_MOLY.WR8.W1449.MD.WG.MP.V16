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
 *   touch_panel_trc.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is trace map definition for touch panel driver
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
#ifndef _TP_TRC_H
#define _TP_TRC_H


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
    #include "touch_panel_trc_gen.h"
#endif /* TST Trace Defintion */
#endif
BEGIN_TRACE_MAP(MOD_TP_TASK)

   TRC_MSG(TP_HISR_DOWN,"TP HISR Down")
   TRC_MSG(TP_HISR_UP,"TP HISR UP")
   TRC_MSG(TP_DOWN_HDR,"TP down handler")
   TRC_MSG(TP_UP_HDR,"TP up handler")
   TRC_MSG(TP_STAT,"TP stat: %d")
   
   TRC_MSG(TP_UP_INTR_LOST,"TP up intr lost")
   TRC_MSG(TP_DOWN_INTR_LOST,"TP down intr lost")
   
   TRC_MSG(TP_PRESSURE_RESULT,"TP pressure result: %d")
   TRC_MSG(TP_PRESSURE_VALUE,"TP pressure value: pressure: %d, x: %d, z1: %d, z2: %d")
   
   TRC_MSG(TP_ADC_VALUE,"TP ADC value: x: %d, y: %d")
   TRC_MSG(TP_VALID_COORD_VALUE,"TP valid coord value: x: %d, y: %d")
   TRC_MSG(TP_CUSTOM_SETTING,"TP custom setting: ADC_X_Start: %d, ADC_X_End: %d, ADC_Y_Start: %d, ADC_Y_End: %d, ScreenX_Start: %d, ScreenX_End: %d, ScreenY_Start: %d, ScreenY_End: %d")
   TRC_MSG(TP_INVALID_COORD_VALUE,"TP invalid coord value: ScreenX_Start: %d, ScreenX_End: %d, ScreenY_Start: %d, ScreenY_End: %d, x: %d, y: %d")
   TRC_MSG(TP_WAIT_NEXT_TRUE,"TP wait next is TRUE, just return")
   TRC_MSG(TP_WAIT_NEXT_SET_TRUE,"TP wait next is set to TRUE!!!!")
   TRC_MSG(TP_FLUSH,"TP flush all data")
   TRC_MSG(TP_RESET,"TP reset")
   TRC_MSG(TP_EXCEED_PENMOVE,"TP exceed penmove: %d")
   
   TRC_MSG(TP_CONF_SAMPLE_PERIOD,"TP config sample period: low: %d, high: %d")
   TRC_MSG(TP_CONF_TIMEOUT_PERIOD,"TP config timeout period: longtap: %d, repeat: %d, handwriting_longtap: %d")
   TRC_MSG(TP_CONF_MOVE_OFFSET,"TP config move offset: pen_offset: %d, stroke_offset: %d, longtap_pen_offset: %d, longtap_stroke_offset: %d")
   
   TRC_MSG(TP_GET_EVENT,"TP get_event: event: %d, x: %d, y: %d")
   TRC_MSG(TP_PEEK_EVENT,"TP get_event: event: %d, x: %d, y: %d")
   
   // Stroke
   TRC_MSG(TP_STROKE_UP,"TP stroke up")
   TRC_MSG(TP_STROKE_MOVE,"TP stroke move x: %d, y: %d")
   
   // Pen
   TRC_MSG(TP_PEN_UP,"TP pen up")
   TRC_MSG(TP_PEN_LONGTAP,"TP longtap x: %d, y: %d")
   TRC_MSG(TP_PEN_REPEAT,"TP repeat x: %d, y: %d")
   TRC_MSG(TP_PEN_MOVE,"TP move x: %d, y: %d")
   
   
   
   // Calibration messages
   TRC_MSG(TP_CALI_FORCE_VALID_COORD_VALUE,"TP cali mode force validate coord value")
   TRC_MSG(TP_CALI_ADC_DIFF,"TP cali ADC diff: x_diff: %d, x_diff_high: %d, x_diff_low: %d, y_diff: %d, y_diff_high: %d, y_diff_low: %d")
   TRC_MSG(TP_CALI_1ST_ADC,"TP 1st adc: x: %d, y: %d")
   TRC_MSG(TP_CALI_2ND_ADC,"TP 2nd adc: x: %d, y: %d")
   TRC_MSG(TP_CALI_RESULT,"TP cali formula: x_slope: %d, x_offset: %d, y_slope: %d, y_offset: %d, result: %d")

	
END_TRACE_MAP(MOD_TP_TASK)

#endif /* _TP_TRC_H */


