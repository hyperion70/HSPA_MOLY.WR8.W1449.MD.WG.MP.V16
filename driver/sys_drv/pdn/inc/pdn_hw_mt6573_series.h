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
 *    pdn_hw_mt6573_series.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines PDN HW registers for MT6573 series chips.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "reg_base.h"

#ifndef __PDN_HW_MT6573_SERIES_H__
#define __PDN_HW_MT6573_SERIES_H__

/* INFRASYS */
#define DRVPDN_CON0              (CONFG_base+0x0300)
#define DRVPDN_CON1              (CONFG_base+0x0310)

#define DRVPDN_CON0_SET          (CONFG_base+0x0304)
#define DRVPDN_CON1_SET          (CONFG_base+0x0314)

#define DRVPDN_CON0_CLR          (CONFG_base+0x0308)
#define DRVPDN_CON1_CLR          (CONFG_base+0x0318)

#define DRVPDN_CON0_DIVIDER         0x00000001
#define DRVPDN_CON0_MDDMA           0x00000002
#define DRVPDN_CON0_OSTIMERMDARM    0x00000004
#define DRVPDN_CON0_OSTIMERFCORE4   0x00000008
#define DRVPDN_CON0_AFC2G           0x00000010
#define DRVPDN_CON0_BPI2G           0x00000020
#define DRVPDN_CON0_BSI2G           0x00000040
#define DRVPDN_CON0_TDMA            0x00000080
#define DRVPDN_CON0_WCDMATIMER      0x00000100
#define DRVPDN_CON0_PFC             0x00000200
#define DRVPDN_CON0_LOGACC          0x00000400
#define DRVPDN_CON0_AFC3G           0x00000800
#define DRVPDN_CON0_BPI3G           0x00001000
#define DRVPDN_CON0_BSI3G           0x00002000
#define DRVPDN_CON0_MDIF            0x00004000

#define DRVPDN_CON1_AFC2GPRE        0x00000010
#define DRVPDN_CON1_BPI2GPRE        0x00000020
#define DRVPDN_CON1_BSI2GPRE        0x00000040

#define AP_DRVPDN_CON0              (APCONFIG_base+0x300)
#define AP_DRVPDN_CON1              (APCONFIG_base+0x310)

#define AP_DRVPDN_CON0_SET          (APCONFIG_base+0x304)
#define AP_DRVPDN_CON1_SET          (APCONFIG_base+0x314)

#define AP_DRVPDN_CON0_CLR          (APCONFIG_base+0x308)
#define AP_DRVPDN_CON1_CLR          (APCONFIG_base+0x318)

#define AP_DRVPDN_CON0_MSDC          0x00000001
#define AP_DRVPDN_CON0_MSDC2         0x00000002
#define AP_DRVPDN_CON0_MSDC3         0x00000004
#define AP_DRVPDN_CON0_MSDC4         0x00000008
#define AP_DRVPDN_CON0_AUXADC2G      0x00000010
#define AP_DRVPDN_CON0_TP            0x00000020
#define AP_DRVPDN_CON0_2GTX          0x00000040
#define AP_DRVPDN_CON0_USB           0x00000080
#define AP_DRVPDN_CON0_USB11         0x00000100
#define AP_DRVPDN_CON0_UART1         0x00000200
#define AP_DRVPDN_CON0_UART2         0x00000400
#define AP_DRVPDN_CON0_UART3         0x00000800
#define AP_DRVPDN_CON0_UART4         0x00001000
#define AP_DRVPDN_CON0_AUXADC3G      0x00002000

#define AP_DRVPDN_CON1_OSTIMERAPARM  0x00000001
#define AP_DRVPDN_CON1_SIMIF0        0x00000002
#define AP_DRVPDN_CON1_SIMIF1        0x00000004
#define AP_DRVPDN_CON1_IRDAFRAMER    0x00000008
#define AP_DRVPDN_CON1_APDMA         0x00000010
#define AP_DRVPDN_CON1_PWM           0x00000020
#define AP_DRVPDN_CON1_MIXEDSYS      0x00000040
#define AP_DRVPDN_CON1_NFI           0x00000080
#define AP_DRVPDN_CON1_I2C           0x00000100
#define AP_DRVPDN_CON1_I2C2          0x00000200
#define AP_DRVPDN_CON1_SEJ           0x00000400
#define AP_DRVPDN_CON1_HDQONEWIRE    0x00000800
#define AP_DRVPDN_CON1_TRNG          0x00001000


/* MD2GSYS */

#define MD2GSYS_CG_CON0          (MD2G_CFG_base+0x0300)
#define MD2GSYS_CG_CON1          (MD2G_CFG_base+0x0304)
#define MD2GSYS_CG_CON2          (MD2G_CFG_base+0x0308)

#define MD2GSYS_CG_SET0          (MD2G_CFG_base+0x0310)
#define MD2GSYS_CG_SET1          (MD2G_CFG_base+0x0314)
#define MD2GSYS_CG_SET2          (MD2G_CFG_base+0x0318)

#define MD2GSYS_CG_CLR0          (MD2G_CFG_base+0x0320)
#define MD2GSYS_CG_CLR1          (MD2G_CFG_base+0x0324)
#define MD2GSYS_CG_CLR2          (MD2G_CFG_base+0x0328)

#define MD2GSYS_CG_CON0_EQ       0x0001
#define MD2GSYS_CG_CON0_PREEQ    0x0002
#define MD2GSYS_CG_CON0_SEQRX    0x0004
#define MD2GSYS_CG_CON0_SEQTX    0x0008
#define MD2GSYS_CG_CON0_CONV     0x0010
#define MD2GSYS_CG_CON0_FIRE     0x0020
#define MD2GSYS_CG_CON0_CRC      0x0040
#define MD2GSYS_CG_CON0_ECRCE    0x0080
#define MD2GSYS_CG_CON0_ECRCD    0x0100
#define MD2GSYS_CG_CON0_ECONV    0x0200
#define MD2GSYS_CG_CON0_PUNC     0x0400
#define MD2GSYS_CG_CON0_VITERBI  0x0800
#define MD2GSYS_CG_CON0_EAPG     0x1000
#define MD2GSYS_CG_CON0_ADDRGEN  0x2000
#define MD2GSYS_CG_CON0_LOG2G    0x4000
#define MD2GSYS_CG_CON0_DEINTDMA 0x8000

#define MD2GSYS_CG_CON1_GCU      0x0001
#define MD2GSYS_CG_CON1_IRDMA    0x0002
#define MD2GSYS_CG_CON1_APCPRE   0x0040
#define MD2GSYS_CG_CON1_FCS      0x0080
#define MD2GSYS_CG_CON1_BFE      0x0400
#define MD2GSYS_CG_CON1_GCCTX    0x0800
#define MD2GSYS_CG_CON1_GCCRX    0x1000

#define MD2GSYS_CG_CON2_APC      0x0040


/* MMSYS1 MMSYS_CONFG_base */

#define MMSYS_CG_CON0          (MMSYS1_CONFG_base +0x0300)
#define MMSYS_CG_CON1          (MMSYS1_CONFG_base +0x0304)

#define MMSYS_CG_SET0          (MMSYS1_CONFG_base +0x0320)
#define MMSYS_CG_SET1          (MMSYS1_CONFG_base +0x0324)

#define MMSYS_CG_CLR0          (MMSYS1_CONFG_base +0x0340)
#define MMSYS_CG_CLR1          (MMSYS1_CONFG_base +0x0344)

#define MMSYS_CG_CON0_GMC1      0x00000001
#define MMSYS_CG_CON0_G2D       0x00000002
#define MMSYS_CG_CON0_GCMQ      0x00000004
#define MMSYS_CG_CON0_JPGENC    0x00000008
#define MMSYS_CG_CON0_IDPMOUT0  0x00000010
#define MMSYS_CG_CON0_JPGDEC    0x00000020
#define MMSYS_CG_CON0_JPEGDMA   0x00000040
#define MMSYS_CG_CON0_IDPMOUT1  0x00000080
#define MMSYS_CG_CON0_OVL       0x00000100
#define MMSYS_CG_CON0_ROTDMA2   0x00000200
#define MMSYS_CG_CON0_ISP       0x00000400
#define MMSYS_CG_CON0_IPP       0x00000800
#define MMSYS_CG_CON0_PRZ       0x00001000
#define MMSYS_CG_CON0_CRZ       0x00002000
#define MMSYS_CG_CON0_VRZ       0x00004000
#define MMSYS_CG_CON0_EIS       0x00008000
#define MMSYS_CG_CON0_GIF       0x00010000
#define MMSYS_CG_CON0_RDMA      0x00020000
#define MMSYS_CG_CON0_RDMA1     0x00040000
#define MMSYS_CG_CON0_PNG       0x00080000
#define MMSYS_CG_CON0_ROTDMA0   0x00100000
#define MMSYS_CG_CON0_ROTDMA1   0x00200000
#define MMSYS_CG_CON0_RESZLB    0x00400000
#define MMSYS_CG_CON0_LCD       0x00800000
#define MMSYS_CG_CON0_DPI       0x01000000
#define MMSYS_CG_CON0_CSI2      0x02000000
#define MMSYS_CG_CON0_OVLBPS    0x04000000
#define MMSYS_CG_CON0_FDVT      0x08000000
#define MMSYS_CG_CON0_DSI       0x10000000
#define MMSYS_CG_CON0_RDMA1BPS  0x20000000
#define MMSYS_CG_CON0_MMLMU     0x40000000
#define MMSYS_CG_CON0_BRZ       0x80000000

#define MMSYS_CG_CON1_PRZ1      0x00000001
#define MMSYS_CG_CON1_ROTDMA3   0x00000002
#define MMSYS_CG_CON1_IDPMOUT2  0x00000004
#define MMSYS_CG_CON1_IDPMOUT3  0x00000008
#define MMSYS_CG_CON1_TVC       0x00000010
#define MMSYS_CG_CON1_TVE       0x00000020
#define MMSYS_CG_CON1_TVROT     0x00000040
#define MMSYS_CG_CON1_HIF       0x00000080
#define MMSYS_CG_CON1_GMC1E     0x00000100
#define MMSYS_CG_CON1_GMC1SLV   0x00000200

/* MMSYS2 MMSYS_CONFG_base */

#define MMSYS2_CG_CON0          (MMSYS2_CONFG_base +0x0300)

#define MMSYS2_CG_SET0          (MMSYS2_CONFG_base +0x0320)

#define MMSYS2_CG_CLR0          (MMSYS2_CONFG_base +0x0340)

#define MMSYS2_CG_CON0_GMC2      0x00000001
#define MMSYS2_CG_CON0_MFV       0x00000002
#define MMSYS2_CG_CON0_MFGCORE   0x00000004
#define MMSYS2_CG_CON0_MFGMEM    0x00000008
#define MMSYS2_CG_CON0_MFGSYS    0x00000010
#define MMSYS2_CG_CON0_SPI       0x00000020
#define MMSYS2_CG_CON0_GMC2E     0x00000040

#endif  /* !__PDN_HW_MT6573_SERIES_H__ */
