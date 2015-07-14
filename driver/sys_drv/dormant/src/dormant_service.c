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
 *   dcm.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file provides APIs to get device information 
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

#ifdef __MTK_TARGET__

#include "kal_general_types.h"
#include "cp15.h"
#include "dormant_mode.h"
#include "SST_sla.h"
#include "bus_drv.h"
#include "us_timer.h"
#include "config_hw.h"

#if defined(__MCU_DORMANT_MODE__)
__DOR_TCM_BSS__ __attribute__((aligned(8))) volatile kal_uint32 dormant_mode_storage[DORMANT_TCM_STORAGE_SIZE>>2];

/*
 * Following variables are expected to locate on EMI space.
 */
/* variable to keep information of dormant mode entry and exit procedure */
__DOR_NONCACHED_BSS__ __attribute__((aligned(8))) volatile kal_uint32 dormant_tcm_storage[DORMANT_EMI_STORAGE_SIZE>>2];
__DOR_NONCACHED_BSS__ __attribute__((aligned(8))) volatile kal_uint32 dormant_mode_stack_pool[DORMANT_STACK_SIZE>>2];
__DOR_NONCACHED_DATA__ volatile kal_uint32 dormant_reset_pwr_ack;
__DOR_NONCACHED_DATA__ volatile kal_uint32 dormant_reset_frc;
__DOR_NONCACHED_DATA__ volatile kal_uint32 dormant_leave_frc;
__DOR_NONCACHED_DATA__ volatile kal_uint32 dormant_enter_frc;
__DOR_NONCACHED_DATA__ volatile kal_uint32 dormant_standby_frc;
__DOR_NONCACHED_DATA__ volatile kal_uint32 dormant_abort_frc;
__DOR_NONCACHED_DATA__ volatile kal_uint32 dormant_reset_count;
__DOR_NONCACHED_DATA__ volatile kal_uint32 dormant_abort_count;
__DOR_NONCACHED_DATA__ volatile kal_uint32 dormant_restore_begin;
__DOR_NONCACHED_DATA__ volatile kal_uint32 dormant_tcm_restore_begin;
__DOR_NONCACHED_DATA__ volatile kal_uint32 dormant_mode_stack;
__DOR_NONCACHED_DATA__ volatile kal_uint32 dormant_dma0_status;
__DOR_NONCACHED_DATA__ volatile kal_uint32 dormant_dma1_status;
__DOR_NONCACHED_DATA__ volatile kal_uint32 dormant_ctrl_backup;
__DOR_NONCACHED_DATA__ volatile kal_uint32 dormant_coproc_acc_ctrl;
__DOR_NONCACHED_DATA__ volatile kal_uint32 dormant_power_on_reset_handler;
__DOR_NONCACHED_BSS__ volatile kal_uint32 dormant_incomp_reset_count;

volatile kal_uint32 dormant_dummy_wb_variable;

/* variable to keep chip dependent register definition. */
const kal_uint32 dormant_status_reg = (kal_uint32)DORMANT_RM_PWR_STA;
const kal_uint32 dormant_power_ack_mask = (kal_uint32)DORMANT_RM_PWR_STA_ARM_PWR_ACK;
const kal_uint32 dormant_frc_val = (kal_uint32)DORMANT_FRC_VAL_R;
const kal_uint32 dormant_remapping_val = (kal_uint32)DORMANT_MD_REMAPPING_CON;

/**********************************************************
Description : dormant mode init
Input       : Non
Output      : Non
***********************************************************/
void dormant_mode_init(void)
{
    /* init dormant mode stack */
    dormant_mode_stack_pool[0] = 0x43415453;
    dormant_mode_stack_pool[1] = 0x444E454B;

    /* set stack start address - 8 byte aligned address */
    dormant_mode_stack = (kal_uint32)&dormant_mode_stack_pool[(DORMANT_STACK_SIZE>>2)-2];
}

/**********************************************************
Description : trigger dormant mode procedure
Input       : Non
Output      : Non
***********************************************************/
__DOR_TCM_LOCAL_FUNC__ void dormant_mode_activate(void)
{
#if !(defined(MT6589) && defined(__MD1__))
    kal_uint32 orig_reset = 0;
#endif //#if !(defined(MT6589) && defined(__MD1__))

    SLA_CustomLogging("DOR", SA_start);

#if defined(MT6575) || defined(MT6577) || defined(MT6280) || (defined(MT6589) && defined(__MD1__)) || defined (MT6572) || defined (MT6582) || defined (MT6592) || defined (MT6571) || defined(MT6580)

    #if (defined(MT6589) && defined(__MD1__)) || defined(MT6572) || defined(MT6582) || defined(MT6592) || defined(MT6571) || defined(MT6580)
    *BOOT_VECTOR_KEY = BOOT_VECTOR_KEY_VAL;
    *DORMANT_BOOT_JUMP_ADDR = (unsigned int)arm_dormant_reset_handler; /* set to dormant reset handler */
    *BOOT_VECTOR_ENABLE = BOOT_VECTOR_ENABLE_VAL;
    #else //#if (defined(MT6589) && defined(__MD1__)) || defined(MT6572) || defined(MT6582) || defined(MT6592) || defined(MT6571) || defined(MT6580)
    orig_reset = *DORMANT_BOOT_JUMP_ADDR;
    *DORMANT_BOOT_JUMP_ADDR = (unsigned int)arm_dormant_reset_handler | BOOT_VECTOR_ENABLE;
    #endif //    #if (defined(MT6589) && defined(__MD1__)) || defined(MT6572) || defined(MT6582) || defined(MT6592) || defined(MT6571) || defined(MT6580)


    dormant_enter_frc = ust_get_current_time();

    //cp15_clean_dcache();
    //cp15_invalidate_dcache();
    //cp15_disable_dcache();
    //cp15_disable_icache();

    enter_dormant_mode();

    //cp15_enable_icache();
    //cp15_enable_dcache();

    dormant_leave_frc = ust_get_current_time();
    cp15_enter_low_pwr_state();

    #if (defined(MT6589) && defined(__MD1__)) || defined (MT6572) || defined (MT6582) || defined (MT6592) || defined (MT6571) || defined(MT6580)
    *BOOT_VECTOR_KEY = BOOT_VECTOR_KEY_VAL;
    *DORMANT_BOOT_JUMP_ADDR = (unsigned int)dormant_power_on_reset_handler; /* restore to original reset handler */
    *BOOT_VECTOR_ENABLE = BOOT_VECTOR_ENABLE_VAL;
    #else //#if (defined(MT6589) && defined(__MD1__)) || defined (MT6572) || defined (MT6582) || defined (MT6592) || defined (MT6571) || defined(MT6580)
    *DORMANT_BOOT_JUMP_ADDR = orig_reset | BOOT_VECTOR_ENABLE;
    #endif //#if (defined(MT6589) && defined(__MD1__)) || defined (MT6572) || defined (MT6582) || defined (MT6592) || defined (MT6571) || defined(MT6580)

#else /* !MT6575 && !MT6577 && !MT6280 */

    cp15_enter_low_pwr_state();

#endif /* MT6575 || MT6577 || MT6280 */

    SLA_CustomLogging("DOR", SA_stop);

    return ;
}

/**********************************************************
Description : mark a flag to indicate that entry to dormant mode is abort
Input       : Non
Output      : Non
***********************************************************/
__DOR_TCM_LOCAL_FUNC__ void dormant_mode_abort_entry(void)
{
    SLA_CustomLogging("dab", SA_label);
}

/**********************************************************
Description : mark a flag to indicate that dormant mode reset is abort
Input       : Non
Output      : Non
***********************************************************/
__DOR_TCM_LOCAL_FUNC__ void dormant_mode_abort_reset(void)
{
    SLA_CustomLogging("dra", SA_label);
}

#else /* !__MCU_DORMANT_MODE__ */

/**********************************************************
Description : dormant mode init
Input       : Non
Output      : Non
***********************************************************/
void dormant_mode_init(void)
{
    /* do nothing */
}

/**********************************************************
Description : trigger dormant mode procedure
Input       : Non
Output      : Non
***********************************************************/
void dormant_mode_activate(void)
{
    /* do nothing */
}

#endif /* __MCU_DORMANT_MODE__ */

#endif /* __MTK_TARGET__ */
