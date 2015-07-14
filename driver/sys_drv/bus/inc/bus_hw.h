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
 *   bus_hw.h
 *
 * Project:
 * --------
 *   Moly_Software
 *
 * Description:
 * ------------
 *   This file is intended for BUS Control
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
 *
  *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __BUS_HW_H__
#define __BUS_HW_H__

#include "reg_base.h"

#if defined(MT6589) || defined(MT6572) || defined(MT6582) || defined(MT6592) || defined(MT6571) || defined(MT6580)

// EMI Latency Monitor
// MT6589 CONFIG_base: 0x80000000
#define MD_MCU_ELM_CON           (volatile kal_uint32 *)(CONFIG_base + 0x0220)

#if defined(MT6571) || defined(MT6580)
// New ELM status register after MT6571
#define MD_MCU_ELM_STATUS0        (volatile kal_uint32 *)(CONFIG_base + 0x0224)
#define MD_MCU_ELM_STATUS1        (volatile kal_uint32 *)(CONFIG_base + 0x0228)
#define MD_MCU_ELM_STATUS2        (volatile kal_uint32 *)(CONFIG_base + 0x022c)
#define MD_MCU_ELM_STATUS3        (volatile kal_uint32 *)(CONFIG_base + 0x0230)
#define MD_MCU_ELM_STATUS4        (volatile kal_uint32 *)(CONFIG_base + 0x0234)
#else // 89,72,82,92
#define MD_MCU_ELM_STATUS        (volatile kal_uint32 *)(CONFIG_base + 0x0228)
#endif


#define MD2EMI_ULTRA_HIGH_STATUS0   (volatile kal_uint32 *)(CONFIG_base + 0x0400)
#define MD2EMI_ULTRA_HIGH_SET0   (volatile kal_uint32 *)(CONFIG_base + 0x0404)
#define MD2EMI_ULTRA_HIGH_CLR0   (volatile kal_uint32 *)(CONFIG_base + 0x0408)
#define MD2EMI_ULTRA_HIGH_STATUS1   (volatile kal_uint32 *)(CONFIG_base + 0x0410)
#define MD2EMI_ULTRA_HIGH_SET1   (volatile kal_uint32 *)(CONFIG_base + 0x0414)
#define MD2EMI_ULTRA_HIGH_CLR1   (volatile kal_uint32 *)(CONFIG_base + 0x0418)

#define MD_MCU_CON0              (volatile kal_uint32 *)(CONFIG_base + 0x0100)
#define MD_MCU_CON2              (volatile kal_uint32 *)(CONFIG_base + 0x0108)
#define MD_MCU2EMI_CON0          (volatile kal_uint32 *)(CONFIG_base + 0x0200)
#define MD_MCU2EMI_STATUS0       (volatile kal_uint32 *)(CONFIG_base + 0x0204)
#define MD_BUS_CON0              (volatile kal_uint32 *)(CONFIG_base + 0x0420)
#define MD_BUS_STATUS0           (volatile kal_uint32 *)(CONFIG_base + 0x0430)


// ARBA: AP
// ARBC: ARM9
// ARBD: CR4
// ARBE: MDHW
#define EMI_ARBA      (volatile kal_uint32 *)(AP_EMI_base + 0x0100)
#define EMI_ARBB      (volatile kal_uint32 *)(AP_EMI_base + 0x0108)
#define EMI_ARBC      (volatile kal_uint32 *)(AP_EMI_base + 0x0110)
#define EMI_ARBD      (volatile kal_uint32 *)(AP_EMI_base + 0x0118)
#define EMI_ARBE      (volatile kal_uint32 *)(AP_EMI_base + 0x0120)

#define EMI_BMEN      (volatile kal_uint32 *)(AP_EMI_base + 0x0400)

#define EMI_TSCT      (volatile kal_uint32 *)(AP_EMI_base + 0x0418)
#define EMI_WSCT      (volatile kal_uint32 *)(AP_EMI_base + 0x0428)
#define EMI_BSCT      (volatile kal_uint32 *)(AP_EMI_base + 0x0438)
#define EMI_MSEL      (volatile kal_uint32 *)(AP_EMI_base + 0x0440)
#define EMI_TSCT2     (volatile kal_uint32 *)(AP_EMI_base + 0x0448)
#define EMI_WSCT2     (volatile kal_uint32 *)(AP_EMI_base + 0x0458)


#if defined(MT6589)
// MT6589 AP_EMI_base: 0xA0203000
#define EMI_TESTB     (volatile kal_uint32 *)(AP_EMI_base + 0x00E8)
// AP_INFRACFG_AO_base: 0xA0001000
#define AP_EMIDCM_CON (volatile kal_uint32 *)(AP_INFRACFG_AO_base + 0x0050)
#endif /* MT6589 */

#if defined(MT6572)
#define EMI_SLCT      (volatile kal_uint32 *)(AP_EMI_base + 0x0150)
#define EMI_BSCT2     (volatile kal_uint32 *)(AP_EMI_base + 0x05A8)
#endif /* MT6572 */

#if defined(MT6582)
#define EMI_MDCT      (volatile kal_uint32 *)(AP_EMI_base + 0x0078)
#define EMI_SLCT      (volatile kal_uint32 *)(AP_EMI_base + 0x0158)
#endif /* MT6582 */

#endif /* MT6589 || MT6572 || MT6582 */

#endif  /* !__BUS_HW_H__ */

