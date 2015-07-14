/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *   custom_l4_utility.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file provides the custom engineer mode declarations
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
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef CUSTOM_L4_UTILITY_H
#define CUSTOM_L4_UTILITY_H

#include "ps_public_enum.h"

typedef enum
{
    SMS_CTRL_BY_SIM,
    CC_CTRL_BY_SIM,
    SS_CTRL_BY_SIM
}cm_ctrl_by_sim_enum;



extern kal_wchar *custom_get_at_audio_download_folder();
extern kal_wchar *custom_get_at_image_download_folder();

#if defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__)
extern kal_uint8 custom_get_fd_monitor_slot(void);
extern kal_uint8 custom_get_fd_timer_id(kal_bool is_screen_on, kal_bool is_r8_fd_support, kal_bool is_cpc_suppot);
extern kal_bool custom_set_fd_timer(kal_uint8 timer_id, kal_uint16 timer_value);
extern kal_uint16 custom_get_fd_timer(kal_uint8 timer_id);
#endif

#if defined(__GEMINI__) && defined(__SIM_ME_LOCK__)
extern kal_bool custom_l4c_root_lock_verify(kal_uint8 updated_sim, 
                                            smu_pending_password_id_enum updated_type, 
                                            smu_pending_password_id_enum *pending_password_tbl,
                                            kal_uint8 *need_unlock_table);
#endif

#ifdef __PPE_INTERFACE_SUPPORT__
void custom_rrc_change_state_ind(umts_rrc_state_enum previous_state, 
                                    umts_rrc_state_enum current_state);
void custom_l4c_report_data_speed(l4c_data_bearer_capablility_enum bearer_capability);
#endif //__PPE_INTERFACE_SUPPORT__        

extern kal_bool custom_fill_ecc_category(void);

extern kal_bool custom_rac_display_searching_when_plmn_loss(void);
extern kal_bool custom_cm_ctrl_by_sim(cm_ctrl_by_sim_enum module);

extern kal_int32 custom_signal_strength_cesq_level_to_raw(l4_cesq_param_enum type, kal_uint8 signal_level);


#endif /* CUSTOM_L4_UTILITY_H */

