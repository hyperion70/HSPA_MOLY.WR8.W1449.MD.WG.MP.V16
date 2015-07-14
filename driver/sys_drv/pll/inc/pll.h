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
 *   init.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _PLL_H
#define _PLL_H

#include "kal_general_types.h"
#include "reg_base.h"

/*************************************************************************
 * Define data structure
 *************************************************************************/

/* MCU clock */
typedef enum mcu_clock_enum_t {
   MCU_13MHZ = 0x0000,
   MCU_15_36MHZ = 0x0000,
   MCU_20_3125MHZ = 0x0000,
   MCU_26MHZ = 0x0001,
   MCU_30_72MHZ = 0x0001,
   MCU_39MHZ = 0x0002,
   MCU_52MHZ = 0x0003,
   MCU_61_44MHZ = 0x0003,
   MCU_65MHZ = 0x0004,
   MCU_78MHZ = 0x0005,
   MCU_91MHZ = 0x0006,
   MCU_104MHZ = 0x0007,
   MCU_122_88MHZ = 0x0007,
   MCU_208MHZ = 0x0008,
   MCU_245_76MHZ = 0x0009,
   MCU_152MHZ = 0x000A,
   MCU_312MHZ = 0x000B,
   MCU_520MHZ = 0x000C,   
   MCU_650MHZ = 0x000D,
   MCU_416MHZ = 0x000E,
   MCU_260MHZ = 0x000F,
   MCU_480MHZ = 0x0010,

   SSC_NORMAL = 0xFFF0,
   SSC_IDLE = 0xFFF1,
   SSC_MCU_LOW_SPEED1 = 0xFFF2,
   SSC_DSP_LOW_SPEED1 = 0xFFF3,
   SSC_BUS_LOW_SPEED1 = 0xFFF4,
   SSC_EMI_LOW_SPEED1 = 0xFFF5,
   SSC_COMBINATION = 0xFFF6,
   SSC_MCU_LOW_SPEED2 = 0xFFF7,
   SSC_EMI_NON_EPLL = 0xFFF8,
   SSC_EMI_EPLL = 0xFFF9,
} mcu_clock_enum;

/* PLL initialization mode */
typedef enum {
    PLL_MODE_MAUI,
    PLL_MODE_USB_META
} pll_init_mode;

/* PLL selection */
typedef enum {
    SYS_DPLL = 0xDEF0,
    SYS_EPLL,
    SYS_FPLL,
    SYS_GPLL,
    SYS_MPLL,
    SYS_NPLL,
    SYS_UPLL,
    SYS_WPLL,
} sys_pll_enum;

/* EMI PLL frequency selection */
typedef enum {
    EMI_PLL_26MHZ = 0xEF0026,
    EMI_PLL_97_5MHZ = 0xEF0097,
    EMI_PLL_104MHZ = 0xEF0104,
    EMI_PLL_208MHZ = 0xEF0208,
    EMI_PLL_250MHZ = 0xEF0250,
    EMI_PLL_266MHZ = 0xEF0266,
    EMI_PLL_333MHZ = 0xEF0333,
    EMI_PLL_400MHZ = 0xEF0400,
} emi_pll_enum;

/* PLL DFS control structure */
typedef struct {
    emi_pll_enum  epll_freq;
} pll_dfs_ctrl_t;


/*************************************************************************
 * Define HW register
 *************************************************************************/
#if defined(MT6575) || defined(MT6577)
#define PLL_CLKSW_CON0 ((volatile kal_uint32*)(CONFIG_base+0x0910))
#define PLL_CLKSW_CON2 ((volatile kal_uint32*)(CONFIG_base+0x0918))

#define PLL_BUS_GATED_EN ((volatile kal_uint32*)(CONFIG_base+0x0558))

#elif defined(TK6280)

#define PLL_MPLL_CON0  ((volatile kal_uint16*)(MIXED_base+0x400))
#define PLL_MPLL_CON1  ((volatile kal_uint16*)(MIXED_base+0x404))
#define PLL_MPLL_CON2  ((volatile kal_uint16*)(MIXED_base+0x408))
#define PLL_UPLL_CON1  ((volatile kal_uint16*)(MIXED_base+0x304))
#define PLL_PDN_CON    ((volatile kal_uint16*)(MIXED_base+0x010))
#define PLL_CLK_CON    ((volatile kal_uint16*)(MIXED_base+0x014))
#define PLL_MCUCLK_CON    ((volatile kal_uint16*)(CONFIG_base+0x118))
#define PLL_APMCUCLK_CON  ((volatile kal_uint16*)(CONFIG_base+0x140))

#elif defined(MT6280)

#define PLL_CLKSQ_CON0     ((volatile kal_uint16*)(MIX_ABB_base+0x0020))
#define PLL_PLL_CON1       ((volatile kal_uint16*)(MIX_ABB_base+0x0044))
#define PLL_PLL_CON2       ((volatile kal_uint16*)(MIX_ABB_base+0x0048))
#define PLL_PLL_CON3       ((volatile kal_uint16*)(MIX_ABB_base+0x004C))
#define PLL_PLL_CON4       ((volatile kal_uint16*)(MIX_ABB_base+0x0050))
#define PLL_PLL_CON5       ((volatile kal_uint16*)(MIX_ABB_base+0x0054))
#define PLL_PLL_CON6       ((volatile kal_uint16*)(MIX_ABB_base+0x0058))
#define PLL_PLL_CON7       ((volatile kal_uint16*)(MIX_ABB_base+0x005C))

#define PLL_CLKSW_CKSEL0   ((volatile kal_uint16*)(MIX_ABB_base+0x0060))
#define PLL_CLKSW_CKSEL1   ((volatile kal_uint16*)(MIX_ABB_base+0x0064))
#define PLL_CLKSW_CKSEL2   ((volatile kal_uint16*)(MIX_ABB_base+0x0068))

#define PLL_CLKSW_FDIV0    ((volatile kal_uint16*)(MIX_ABB_base+0x0070))
#define PLL_CLKSW_FDIV1    ((volatile kal_uint16*)(MIX_ABB_base+0x0074))
#define PLL_CLKSW_FDIV2    ((volatile kal_uint16*)(MIX_ABB_base+0x0078))
#define PLL_CLKSW_FDIV3    ((volatile kal_uint16*)(MIX_ABB_base+0x007C))
#define PLL_CLKSW_FDIV4    ((volatile kal_uint16*)(MIX_ABB_base+0x0080))
#define PLL_CLKSW_FDIV5    ((volatile kal_uint16*)(MIX_ABB_base+0x0084))
#define PLL_CLKSW_FDIV6    ((volatile kal_uint16*)(MIX_ABB_base+0x0088))

#define PLL_DFS_CON0       ((volatile kal_uint16*)(MIX_ABB_base+0x0090))
#define PLL_DFS_CON1       ((volatile kal_uint16*)(MIX_ABB_base+0x0094))
#define PLL_DFS_CON2       ((volatile kal_uint16*)(MIX_ABB_base+0x0098))
#define PLL_DFS_CON3       ((volatile kal_uint16*)(MIX_ABB_base+0x009C))
#define PLL_DFS_CON4       ((volatile kal_uint16*)(MIX_ABB_base+0x00A0))
#define PLL_DFS_CON5       ((volatile kal_uint16*)(MIX_ABB_base+0x00A4))
#define PLL_DFS_CON6       ((volatile kal_uint16*)(MIX_ABB_base+0x00A8))
#define PLL_DFS_CON7       ((volatile kal_uint16*)(MIX_ABB_base+0x00AC))
#define PLL_DFS_CON8       ((volatile kal_uint16*)(MIX_ABB_base+0x00B0))
#define PLL_DFS_CON9       ((volatile kal_uint16*)(MIX_ABB_base+0x00B4))
#define PLL_DFS_CON10      ((volatile kal_uint16*)(MIX_ABB_base+0x00B8))
#define PLL_DFS_CON11      ((volatile kal_uint16*)(MIX_ABB_base+0x00BC))

#define PLL_MPLL_CON0      ((volatile kal_uint16*)(MIX_ABB_base+0x0100))
#define PLL_MPLL_CON1      ((volatile kal_uint16*)(MIX_ABB_base+0x0104))
#define PLL_MPLL_CON2      ((volatile kal_uint16*)(MIX_ABB_base+0x0108))
#define PLL_MPLL_CON3      ((volatile kal_uint16*)(MIX_ABB_base+0x010C))

#define PLL_UPLL_CON0      ((volatile kal_uint16*)(MIX_ABB_base+0x0140))
#define PLL_UPLL_CON1      ((volatile kal_uint16*)(MIX_ABB_base+0x0144))
#define PLL_UPLL_CON2      ((volatile kal_uint16*)(MIX_ABB_base+0x0148))
#define PLL_UPLL_CON3      ((volatile kal_uint16*)(MIX_ABB_base+0x014C))

#define PLL_WPLL_CON0      ((volatile kal_uint16*)(MIX_ABB_base+0x01C0))
#define PLL_WPLL_CON1      ((volatile kal_uint16*)(MIX_ABB_base+0x01C4))
#define PLL_WPLL_CON2      ((volatile kal_uint16*)(MIX_ABB_base+0x01C8))
#define PLL_WPLL_CON3      ((volatile kal_uint16*)(MIX_ABB_base+0x01CC))

#define PLL_EPLL_CON0      ((volatile kal_uint16*)(MIX_ABB_base+0x0200))
#define PLL_EPLL_CON1      ((volatile kal_uint16*)(MIX_ABB_base+0x0204))
#define PLL_EPLL_CON2      ((volatile kal_uint16*)(MIX_ABB_base+0x0208))
#define PLL_EPLL_CON3      ((volatile kal_uint16*)(MIX_ABB_base+0x020C))

#define PLL_WHPLL_CON0     ((volatile kal_uint16*)(MIX_ABB_base+0x0600))
#define PLL_WHPLL_CON1     ((volatile kal_uint16*)(MIX_ABB_base+0x0604))
#define PLL_WHPLL_CON2     ((volatile kal_uint16*)(MIX_ABB_base+0x0608))
#define PLL_WHPLL_CON3     ((volatile kal_uint16*)(MIX_ABB_base+0x060C))

#define PLL_MDDS_CON0      ((volatile kal_uint16*)(MIX_ABB_base+0x0640))
#define PLL_MDDS_CON1      ((volatile kal_uint16*)(MIX_ABB_base+0x0644))
#define PLL_MDDS_CON2      ((volatile kal_uint16*)(MIX_ABB_base+0x0648))
#define PLL_MDDS_CON3      ((volatile kal_uint16*)(MIX_ABB_base+0x064C))
#define PLL_MDDS_CON4      ((volatile kal_uint16*)(MIX_ABB_base+0x0650))
#define PLL_MDDS_CON5      ((volatile kal_uint16*)(MIX_ABB_base+0x0654))
#define PLL_MDDS_CON6      ((volatile kal_uint16*)(MIX_ABB_base+0x0658))
#define PLL_MDDS_CON7      ((volatile kal_uint16*)(MIX_ABB_base+0x065C))

#define PLL_EDDS_CON0      ((volatile kal_uint16*)(MIX_ABB_base+0x0670))
#define PLL_EDDS_CON1      ((volatile kal_uint16*)(MIX_ABB_base+0x0674))
#define PLL_EDDS_CON2      ((volatile kal_uint16*)(MIX_ABB_base+0x0678))
#define PLL_EDDS_CON3      ((volatile kal_uint16*)(MIX_ABB_base+0x067C))
#define PLL_EDDS_CON4      ((volatile kal_uint16*)(MIX_ABB_base+0x0680))
#define PLL_EDDS_CON5      ((volatile kal_uint16*)(MIX_ABB_base+0x0684))
#define PLL_EDDS_CON6      ((volatile kal_uint16*)(MIX_ABB_base+0x0688))
#define PLL_EDDS_CON7      ((volatile kal_uint16*)(MIX_ABB_base+0x068C))

#define PLL_PLLTD_CON0     ((volatile kal_uint16*)(MIX_ABB_base+0x0700))
#define PLL_PLLTD_CON1     ((volatile kal_uint16*)(MIX_ABB_base+0x0704))
#define PLL_PLLTD_CON2     ((volatile kal_uint16*)(MIX_ABB_base+0x0708))
#define PLL_PLLTD_CON3     ((volatile kal_uint16*)(MIX_ABB_base+0x070C))
#define PLL_PLLTD_CON4     ((volatile kal_uint16*)(MIX_ABB_base+0x0710))
#define PLL_PLLTD_CON5     ((volatile kal_uint16*)(MIX_ABB_base+0x0714))
#define PLL_PLLTD_CON6     ((volatile kal_uint16*)(MIX_ABB_base+0x0718))
#define PLL_PLLTD_CON7     ((volatile kal_uint16*)(MIX_ABB_base+0x071C))

#define PLL_MD_PWR_GLOBAL_CON0 ((volatile kal_uint32*)(CONFIG_base+0x00A0))
#define PLL_MD_PWR_GLOBAL_CON1 ((volatile kal_uint32*)(CONFIG_base+0x00AC))

#define PLL_MD_TOP_CON         ((volatile kal_uint32*)(CONFIG_base+0x001C))

#define PLL_AP_DCM_CON_0       ((volatile kal_uint32*)(AP_CONFIG_base+0x0040))

#elif defined(MT6589)

#define PLL_PLL_CON1           ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x044))
#define PLL_PLL_CON2           ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x048))
#define PLL_PLL_CON3           ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x04C))

#define PLL_CLKSW_CKSEL0       ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x060))
#define PLL_CLKSW_CKSEL1       ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x064))
#define PLL_CLKSW_CKSEL2       ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x068))

#define PLL_CLKSW_FDIV0        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x070))
#define PLL_CLKSW_FDIV1        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x074))
#define PLL_CLKSW_FDIV2        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x078))
#define PLL_CLKSW_FDIV3        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x07C))
#define PLL_CLKSW_FDIV4        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x080))
#define PLL_CLKSW_FDIV5        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x084))
#define PLL_CLKSW_FDIV6        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x088))

#define PLL_DFS_CON7           ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x0AC))
#define PLL_DFS_CON8           ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x0B0))
#define PLL_DFS_CON9           ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x0B4))

#define PLL_MDPLL_CON0         ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x100))
#define PLL_MDPLL_CON1         ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x104))
#define PLL_MDPLL_CON2         ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x108))
#define PLL_MDPLL_CON3         ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x10C))
#define PLL_MDPLL_CON4         ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x110))

#define PLL_MCUPLL_CON0        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x140))
#define PLL_MCUPLL_CON1        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x144))
#define PLL_MCUPLL_CON2        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x148))
#define PLL_MCUPLL_CON3        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x14C))

#define PLL_WPLL_CON0          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x1C0))
#define PLL_WPLL_CON1          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x1C4))
#define PLL_WPLL_CON2          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x1C8))
#define PLL_WPLL_CON3          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x1CC))

#define PLL_WHPLL_CON0          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x200))
#define PLL_WHPLL_CON1          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x204))

#define PLL_PLLTD_CON0          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x700))
#define PLL_PLLTD_CON1          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x704))
#define PLL_PLLTD_CON2          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x708))
#define PLL_PLLTD_CON3          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x70C))
#define PLL_PLLTD_CON4          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x710))
#define PLL_PLLTD_CON5          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x714))
#define PLL_PLLTD_CON6          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x718))
#define PLL_PLLTD_CON7          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x71C))

#define PLL_MD_GLOBAL_CON1      ((volatile kal_uint32*)(CONFIG_base+0x45C))

#elif defined(MT6572) || defined (MT6582) || defined (MT6592)

#define PLL_PLL_CON1           ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x044))
#define PLL_PLL_CON2           ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x048))
#define PLL_PLL_CON3           ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x04C))

#define PLL_CLKSW_CKSEL0       ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x060))
#define PLL_CLKSW_CKSEL1       ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x064))
#define PLL_CLKSW_CKSEL2       ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x068))
#define PLL_CLKSW_CKSEL3       ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x06C))

#define PLL_CLKSW_FDIV0        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x070))
#define PLL_CLKSW_FDIV1        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x074))
#define PLL_CLKSW_FDIV2        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x078))
#define PLL_CLKSW_FDIV3        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x07C))
#define PLL_CLKSW_FDIV4        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x080))
#define PLL_CLKSW_FDIV5        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x084))
#define PLL_CLKSW_FDIV6        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x088))
#define PLL_CLKSW_FDIV7        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x08C))

#define PLL_CLKSW_CONN_CON0    ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x090))

#define PLL_DFS_CON7           ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x0AC))
#define PLL_DFS_CON8           ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x0B0))
#define PLL_DFS_CON9           ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x0B4))

#define PLL_MDPLL_CON0         ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x100))
#define PLL_MDPLL_CON1         ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x104))
#define PLL_MDPLL_CON2         ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x108))
#define PLL_MDPLL_CON3         ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x10C))
#define PLL_MDPLL_CON4         ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x110))

#define PLL_MCUPLL_CON0        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x140))
#define PLL_MCUPLL_CON1        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x144))
#define PLL_MCUPLL_CON2        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x148))
#define PLL_MCUPLL_CON3        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x14C))

#define PLL_WPLL_CON0          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x1C0))
#define PLL_WPLL_CON1          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x1C4))
#define PLL_WPLL_CON2          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x1C8))
#define PLL_WPLL_CON3          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x1CC))

#define PLL_WHPLL_CON0          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x200))
#define PLL_WHPLL_CON1          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x204))
#define PLL_WHPLL_CON2          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x208))
#define PLL_WHPLL_CON3          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x20C))
#define PLL_WHPLL_CON4	        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x210))

#define PLL_RSV_CON0	        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x360))

#define PLL_PLLTD_CON0          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x700))
#define PLL_PLLTD_CON1          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x704))
#define PLL_PLLTD_CON2          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x708))
#define PLL_PLLTD_CON3          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x70C))
#define PLL_PLLTD_CON4          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x710))
#define PLL_PLLTD_CON5          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x714))
#define PLL_PLLTD_CON6          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x718))
#define PLL_PLLTD_CON7          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x71C))

#define PLL_FH_CON4          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x510))
#define PLL_FH_CON5          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x514))
#define PLL_FH_CON6          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x518))
#define PLL_FH_CON7          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x51C))


#define PLL_MD_GLOBAL_CON1      ((volatile kal_uint32*)(CONFIG_base+0x45C))

#elif defined(MT6571) || defined(MT6580)

#define PLL_PLL_CON1            ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x044))
#define PLL_PLL_CON2            ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x048))
#define PLL_PLL_CON3            ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x04C))

#define PLL_CLKSW_CKSEL0        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x060))
#define PLL_CLKSW_CKSEL1        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x064))
#define PLL_CLKSW_CKSEL2        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x068))
#define PLL_CLKSW_CKSEL3        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x06C))

#define PLL_CLKSW_FDIV0         ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x070))
#define PLL_CLKSW_FDIV1         ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x074))
#define PLL_CLKSW_FDIV2         ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x078))
#define PLL_CLKSW_FDIV3         ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x07C))
#define PLL_CLKSW_FDIV4         ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x080))
#define PLL_CLKSW_FDIV5         ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x084))
#define PLL_CLKSW_FDIV6         ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x088))
#define PLL_CLKSW_FDIV7         ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x08C))

#define PLL_CLKSW_CONN_CON0     ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x090))

#define PLL_DFS_CON7            ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x0AC))
#define PLL_DFS_CON8            ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x0B0))
#define PLL_DFS_CON9            ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x0B4))

#define PLL_MDPLL_CON0          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x100))
#define PLL_MDPLL_CON1          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x104))
#define PLL_MDPLL_CON2          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x108))
#define PLL_MDPLL_CON3          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x10C))
#define PLL_MDPLL_CON4          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x110))

#define PLL_MCUPLL_CON0         ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x140))
#define PLL_MCUPLL_CON1         ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x144))
#define PLL_MCUPLL_CON2         ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x148))
#define PLL_MCUPLL_CON3         ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x14C))

#define PLL_WPLL_CON0           ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x1C0))
#define PLL_WPLL_CON1           ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x1C4))
#define PLL_WPLL_CON2           ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x1C8))
#define PLL_WPLL_CON3           ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x1CC))

#define PLL_WHPLL_CON0          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x200))
#define PLL_WHPLL_CON1          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x204))
#define PLL_WHPLL_CON2          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x208))
#define PLL_WHPLL_CON3          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x20C))
#define PLL_WHPLL_CON4	        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x210))

#define PLL_RSV_CON0	        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x360))

#define PLL_PLLTD_CON0          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x700))
#define PLL_PLLTD_CON1          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x704))
#define PLL_PLLTD_CON2          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x708))
#define PLL_PLLTD_CON3          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x70C))
#define PLL_PLLTD_CON4          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x710))
#define PLL_PLLTD_CON5          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x714))
#define PLL_PLLTD_CON6          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x718))
#define PLL_PLLTD_CON7          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x71C))

#define PLL_FH_CON4             ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x510))
#define PLL_FH_CON5             ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x514))
#define PLL_FH_CON6             ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x518))
#define PLL_FH_CON7             ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x51C))


#define PLL_MD_GLOBAL_CON1      ((volatile kal_uint32*)(CONFIG_base+0x45C))

#endif
 
/*************************************************************************
  * Define constant macros.
 *************************************************************************/
#define PLL_SWITCH_STACK_SIZE        (512)
#define EPLL_FREQ_SWITCH_STACK_SIZE  (512)

/* /\************************************************************************* */
/*  * Define imported function prototype */
/*  *************************************************************************\/ */
/* extern kal_uint32 INT_SwitchStackToRun(void *stack_start, kal_uint32 stack_size, kal_func_ptr func, kal_uint32 argc, ...); */

/*************************************************************************
 * Define exported function prototype
 *************************************************************************/
extern void INT_SetPLL(pll_init_mode mode);
/* extern kal_bool INT_SwitchMCUClock(mcu_clock_enum inputclk); */
/* extern kal_bool INT_DynamicSwitchDDS(sys_pll_enum inputpll, kal_bool ddson); */

/*************************************************************************
  * Define function macros.
 *************************************************************************/
extern kal_uint32 pll_int_stack_pool[];
extern void SetEMIPLLFreq_internal(emi_pll_enum emi_pll);

#if defined(__UBL__)
#define INT_SetEMIPLLFreq(x) SetEMIPLLFreq_internal(x);
#define INT_PLL_DISABLE_IRQ(x) x++;
#define INT_PLL_ENABLE_IRQ(x)  x--;

#else // MAUI
#define INT_SetEMIPLLFreq(x)   INT_SwitchStackToRun(pll_int_stack_pool, EPLL_FREQ_SWITCH_STACK_SIZE, (kal_func_ptr)SetEMIPLLFreq_internal, 1, x);
#define INT_PLL_DISABLE_IRQ(x)  \
do {                            \
       x = SaveAndSetIRQMask(); \
}while(0);

#define INT_PLL_ENABLE_IRQ(x)  RestoreIRQMask(x);

#endif

#if defined(MT6280)
#define PLL_EMI_SWITCH_TO_CLKSQ \
do { \
        kal_uint32 reg_val = 0; \
        reg_val = *PLL_CLKSW_CKSEL1; \
        reg_val &= 0xF0FF; \
        reg_val |= 0x0100; \
        *PLL_CLKSW_CKSEL1 = reg_val; \
} while(0)

#define PLL_EMI_PLL_SWITCH_FREQ_TO(x) \
do { \
        volatile kal_uint32 i = 0;            \
        /*disable EPLL*/                      \
        *PLL_EPLL_CON0 |= 0x0001;             \
        switch(x)                             \
        {                                     \
            case EMI_PLL_250MHZ:              \
                *PLL_EPLL_CON0 &= ~(0x7FF0);  \
                *PLL_EPLL_CON0 |= 0x1110;     \
                *PLL_EPLL_CON1 &= ~(0xFFFE);  \
                *PLL_EPLL_CON1 |= 0x8000;     \
            break;                            \
            case EMI_PLL_333MHZ:              \
                *PLL_EPLL_CON0 &= ~(0x7FF0);  \
                *PLL_EPLL_CON0 |= 0x1810;     \
                *PLL_EPLL_CON1 &= ~(0xFFFE);  \
                *PLL_EPLL_CON1 |= 0x8000;     \
            break;                            \
            case EMI_PLL_400MHZ:              \
                *PLL_EPLL_CON0 &= ~(0x7FF0);  \
                *PLL_EPLL_CON0 |= 0x0E10;     \
                *PLL_EPLL_CON1 &= ~(0xFFFE);  \
                *PLL_EPLL_CON1 |= 0x4000;     \
            break;                            \
            default:                          \
            /* unsupported frequency */       \
            ASSERT(0);                        \
            break;                            \
        };                                    \
        /*enable EPLL*/                       \
        *PLL_EPLL_CON0 &= ~(0x0001);          \
        /*wait for 50~70us for UPLL stable and MDDS, EDDS enable (in 480Mhz)*/ \
        for(i  = 0 ; i < 16826 ; i++);        \
} while(0)

#define PLL_EMI_SWITCH_TO_PLL(x) \
do { \
        kal_uint32 reg_val = 0; \
        reg_val = *PLL_CLKSW_CKSEL1; \
        reg_val &= 0xF0FF; \
        reg_val |= 0x0200; \
        *PLL_CLKSW_CKSEL1 = reg_val; \
} while(0)

#else // no matched chip

#define PLL_EMI_SWITCH_TO_CLKSQ 
#define PLL_EMI_PLL_SWITCH_FREQ_TO(x) 
#define PLL_EMI_SWITCH_TO_PLL(x) 
#endif

/*************************************************************************
  * Define attribute macros.
 *************************************************************************/
#if defined(__MTK_TARGET__)
#define __SECTION__(S) __attribute__ ((__section__(#S)))
#define __ZI__          __attribute__ ((zero_init))
#if defined(__GNUC__)
#define __Long_Call__ __attribute__((long_call))
#else /*! __GNUC__ */
#define __Long_Call__ 
#endif /* __GNUC__ */

#define __PLL_TCM_DATA__ __SECTION__(INTSRAM_RW)
#define __PLL_TCM_BSS__ __SECTION__(INTSRAM_ZI) __ZI__ 
#define __PLL_TCM_CONST__ __SECTION__(INTSRAM_RODATA)
#define __PLL_TCM_FUNC__ __Long_Call__  __SECTION__(INTSRAM_ROCODE)
#define __PLL_TCM_LOCAL_FUNC__ __SECTION__(INTSRAM_ROCODE)

#define __PLL_EMIINIT_DATA__ __SECTION__(EMIINITRW)
#define __PLL_EMIINIT_BSS__ __SECTION__(EMIINITZI) __ZI__
#define __PLL_EMIINIT_CONST__ __SECTION__(EMIINITCONST)
#define __PLL_EMIINIT_FUNC__ __Long_Call__  __SECTION__(EMIINITCODE)
#define __PLL_EMIINIT_LOCAL_FUNC__ __SECTION__(EMIINITCODE)

#else

#define __PLL_TCM_DATA__  
#define __PLL_TCM_BSS__  
#define __PLL_TCM_CONST__  
#define __PLL_TCM_FUNC__  
#define __PLL_TCM_LOCAL_FUNC__  

#define __PLL_EMIINIT_DATA__  
#define __PLL_EMIINIT_BSS__  
#define __PLL_EMIINIT_CONST__  
#define __PLL_EMIINIT_FUNC__  
#define __PLL_EMIINIT_LOCAL_FUNC__  

#endif /* __MTK_TARGET__ */


#endif  /* !_PLL_H */

