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
 *   bus_elm_mt6571_series.h
 *
 * Project:
 * --------
 *   Moly_Software
 *
 * Description:
 * ------------
 *   This file is intended for control of EMI Latency Monitor 
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
 *
  *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __BUS_ELM_MT6571_SERIES_H__
#define __BUS_ELM_MT6571_SERIES_H__

#include "kal_general_types.h"
#include "bus_hw.h"

/*******************************************************************************
 * Define data structures
 *******************************************************************************/

/* data structure for EMI transaction counts */
typedef struct _ELM_LOG_T
{
    kal_uint32 w_trans;
    kal_uint32 w_latency;
    kal_uint32 r_trans;
    kal_uint32 r_latency;
} ELM_LOG_T;

/*******************************************************************************
 * Macro
 *******************************************************************************/

// ELM Software Mode Start/Pause/Stop
#define ELM_SM_Start() \
        {\
        	*MD_MCU_ELM_CON = 0x00000001;\
        }

#define ELM_SM_Pause() \
        {\
        	*MD_MCU_ELM_CON = 0x00000003;\
        }

#define ELM_SM_Stop() \
        {\
        	*MD_MCU_ELM_CON = 0x00000000;\
        }

// Get counter
#define ELM_GET_LOG(c, l)   \
        do {    \
        	(l).w_trans = *MD_MCU_ELM_STATUS0;    \
        	(l).w_latency = *MD_MCU_ELM_STATUS1;  \
        	(l).r_trans = *MD_MCU_ELM_STATUS2;    \
        	(l).r_latency = *MD_MCU_ELM_STATUS3;  \
        } while (0)


#endif  /* !__BUS_ELM_MT6571_SERIES_H__ */
