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
 *   pdn.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the power down management
 *
 * Author:
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*******************************************************************************
 * Include files
 *******************************************************************************/

#include "drv_comm.h"
#include "drvpdn.h"
#include "lpwr.h"

#include "kal_general_types.h"
#include "kal_public_api.h"

#include "intrCtrl.h"

#define __LPWR_SLIM_SUPPORT__

#if !defined(__OLD_PDN_ARCH__)

/*******************************************************************************
 * Define global data
 *******************************************************************************/
#if !defined(__LPWR_SLIM_SUPPORT__) /* removed, LPWR should be phased out @W1249 */

LPWR_STRUCT LPWR_DEV[PDN_MAX_DEV];

/* PDN_DEVICE and PDNID_2_DEVI must be synchronized (1-to-1 mapping) */
const DEVICE_ID_ENUM PDNID_2_DEVI[PDN_MAX_DEV + 1] = 
{
#define X_PDN_USER(a, b, c, d, e, f) DEV_##a,
#define X_PDN_CONST(a, b, c, d, e, f)
#include "pdn_def.h"
#undef X_PDN_USER
#undef X_PDN_CONST
   DEV_NULL_ID                                   
};

const kal_uint32 pdn_set_addr[PDN_MAX_DEV] =
{
#define X_PDN_USER(a, b, c, d, e, f) c,
#define X_PDN_CONST(a, b, c, d, e, f)
#include "pdn_def.h"
#undef X_PDN_USER
#undef X_PDN_CONST
};

const kal_uint32 pdn_clr_addr[PDN_MAX_DEV] =
{
#define X_PDN_USER(a, b, c, d, e, f) d,
#define X_PDN_CONST(a, b, c, d, e, f)
#include "pdn_def.h"
#undef X_PDN_USER
#undef X_PDN_CONST
};

const kal_uint32 pdn_ctrl_addr[PDN_MAX_DEV] =
{
#define X_PDN_USER(a, b, c, d, e, f) b,
#define X_PDN_CONST(a, b, c, d, e, f)
#include "pdn_def.h"
#undef X_PDN_USER
#undef X_PDN_CONST
};

const kal_uint32 pdn_bits[PDN_MAX_DEV] =
{
#define X_PDN_USER(a, b, c, d, e, f) e,
#define X_PDN_CONST(a, b, c, d, e, f)
#include "pdn_def.h"
#undef X_PDN_USER
#undef X_PDN_CONST
};

const kal_uint8 pdn_options[PDN_MAX_DEV] =
{
#define X_PDN_USER(a, b, c, d, e, f) f,
#define X_PDN_CONST(a, b, c, d, e, f)
#include "pdn_def.h"
#undef X_PDN_USER
#undef X_PDN_CONST
};

volatile kal_uint32 drvpdn_initial_state = DRVPDN_NOT_INITIALIZED;

/*************************************************************************
* FUNCTION
*  pdn_set_callback
*
* DESCRIPTION
*  callback function of lpwr to set PDN registers
*
* PARAMETERS
*  paramter   -   pointer to a pdn_data structure
*
* RETURNS
*  none
*
*************************************************************************/                                
void pdn_set_callback(void *parameter)          
{
    PDN_INPUT *pdn_data = (PDN_INPUT *)parameter;
    register kal_uint32 reg_val = 0;
    register kal_uint32 mask = 0;

    if(DUMMY_PDN_SET_REGISTER == pdn_data->addr)
    {
        mask = SaveAndSetIRQMask();
        if (pdn_data->options & PDN_OPT_32BIT_REG) {
            reg_val = *(volatile kal_uint32 *)(pdn_data->ctrl);
            if (pdn_data->options & PDN_OPT_INVERSED_POLARITY) {
                reg_val &= ~(pdn_data->code);
            }
            else {
            reg_val |= pdn_data->code;
            }
            *(volatile kal_uint32 *)(pdn_data->ctrl) = reg_val;
        } else if (pdn_data->options & PDN_OPT_16BIT_REG) {
            reg_val = *(volatile kal_uint16 *)(pdn_data->ctrl);
            if (pdn_data->options & PDN_OPT_INVERSED_POLARITY) {
                reg_val &= ~(pdn_data->code);
            }
            else {
            reg_val |= pdn_data->code;
            }
            *(volatile kal_uint16 *)(pdn_data->ctrl) = reg_val;
        } else {
            ASSERT(0);
        }
        RestoreIRQMask(mask);
    }
    else
    {
        if (pdn_data->options & PDN_OPT_32BIT_REG) {
            *(volatile kal_uint32 *)(pdn_data->addr) = pdn_data->code;
        } else if (pdn_data->options & PDN_OPT_16BIT_REG) {
            *(volatile kal_uint16 *)(pdn_data->addr) = pdn_data->code;
        } else {
            ASSERT(0);
        }
    }
}

/*************************************************************************
* FUNCTION
*  pdn_clr_callback
*
* DESCRIPTION
*  callback function of lpwr to clear PDN registers
*
* PARAMETERS
*  paramter   -   pointer to a pdn_data structure
*
* RETURNS
*  none
*
*************************************************************************/                                
void pdn_clr_callback(void *parameter)          
{
    PDN_INPUT *pdn_data = (PDN_INPUT *)parameter;
    register kal_uint32 reg_val = 0;
    register kal_uint32 mask = 0;

    if(DUMMY_PDN_CLR_REGISTER == pdn_data->addr)
    {
        mask = SaveAndSetIRQMask();
        if (pdn_data->options & PDN_OPT_32BIT_REG) {
            reg_val = *(volatile kal_uint32 *)(pdn_data->ctrl);
            if (pdn_data->options & PDN_OPT_INVERSED_POLARITY) {
                reg_val |= pdn_data->code;
            }
            else {
            reg_val &= ~(pdn_data->code);
            }
            *(volatile kal_uint32 *)(pdn_data->ctrl) = reg_val;
        } else if (pdn_data->options & PDN_OPT_16BIT_REG) {
            reg_val = *(volatile kal_uint16 *)(pdn_data->ctrl);
            if (pdn_data->options & PDN_OPT_INVERSED_POLARITY) {
                reg_val |= pdn_data->code;
            }
            else {
            reg_val &= ~(pdn_data->code);
            }
            *(volatile kal_uint16 *)(pdn_data->ctrl) = reg_val;
        } else {
            ASSERT(0);
        }
        RestoreIRQMask(mask);
    }
    else
    {
        if (pdn_data->options & PDN_OPT_32BIT_REG) {
            *(volatile kal_uint32 *)(pdn_data->addr) = pdn_data->code;
        } else if (pdn_data->options & PDN_OPT_16BIT_REG) {
            *(volatile kal_uint16 *)(pdn_data->addr) = pdn_data->code;
        } else {
            ASSERT(0);
        }
    }
}

/*************************************************************************
* FUNCTION
*  DRVPDN_ini
*
* DESCRIPTION
*  initialize PDN control
*
* PARAMETERS
*  none
*
* RETURNS
*  none
*
*************************************************************************/ 
void DRVPDN_ini(void)
{
    kal_uint32 index;
    kal_uint32 irq_mask;
    
    irq_mask = SaveAndSetIRQMask();

    if( DRVPDN_NOT_INITIALIZED == drvpdn_initial_state )
    {
        drvpdn_initial_state = DRVPDN_INITIALIZING;
        RestoreIRQMask(irq_mask); //SHENGKAI

        for (index =0; index < PDN_MAX_DEV; index++) {
            ASSERT(PDNID_2_DEVI[index] != DEV_NULL_ID);
            if (pdn_options[index] & PDN_OPT_NEVER_OFF) {
                lpwr_module_open(&LPWR_DEV[index], PDNID_2_DEVI[index], NULL, NULL);
            } else {
                lpwr_module_open(&LPWR_DEV[index], PDNID_2_DEVI[index], pdn_set_callback, pdn_clr_callback);
            }
        }

        irq_mask = SaveAndSetIRQMask();
        drvpdn_initial_state = DRVPDN_INITIALIZED;
        RestoreIRQMask(irq_mask);//shengkai
    }
    else if( (DRVPDN_INITIALIZED != drvpdn_initial_state) && (DRVPDN_INITIALIZING !=drvpdn_initial_state) )
    {
        RestoreIRQMask(irq_mask); //shengkai
        /* memory corruption on DRVPDN initialization state */
        EXT_ASSERT(0, drvpdn_initial_state, (kal_uint32)&drvpdn_initial_state, 0);
    }
    else
    {
        RestoreIRQMask(irq_mask);//shengkai
    }
}

/*************************************************************************
* FUNCTION
*  DRVPDN_Enable
*
* DESCRIPTION
*  Power down device.
*
* PARAMETERS
*  pdn_id   -   PDN ID for the target device
*
* RETURNS
*  none
*
*************************************************************************/
void DRVPDN_Enable(PDN_DEVICE pdn_id)
{
    PDN_INPUT pdn_data;

    pdn_data.addr = pdn_set_addr[pdn_id];
    pdn_data.code = pdn_bits[pdn_id];
    pdn_data.ctrl = pdn_ctrl_addr[pdn_id];
    pdn_data.options = pdn_options[pdn_id];
    lpwr_main_enable(&LPWR_DEV[pdn_id], &pdn_data);
}

/*************************************************************************
* FUNCTION
*  DRVPDN_Disable
*
* DESCRIPTION
*  Power up device.
*
* PARAMETERS
*  pdn_id   -   PDN ID for the target device
*
* RETURNS
*  none
*
*************************************************************************/
void DRVPDN_Disable(PDN_DEVICE pdn_id)
{
    PDN_INPUT pdn_data;

    pdn_data.addr = pdn_clr_addr[pdn_id];
    pdn_data.code = pdn_bits[pdn_id];
    pdn_data.ctrl = pdn_ctrl_addr[pdn_id];
    pdn_data.options = pdn_options[pdn_id];
    lpwr_main_disable(&LPWR_DEV[pdn_id], &pdn_data);
}
#endif //#if !defined(__LPWR_SLIM_SUPPORT__) /* removed, LPWR should be phased out @W1249 */

#endif  /* !__OLD_PDN_ARCH__ */

