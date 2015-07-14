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
 *    pdn_hw_mt6575_series.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "reg_base.h"

#ifndef __PDN_HW_MT6575_SERIES_H__
#define __PDN_HW_MT6575_SERIES_H__

/* INFRASYS */
#define DRVPDN_CON0              (CONFG_base+0x0300)
#define DRVPDN_CON1              (CONFG_base+0x0304)
#define DRVPDN_CON2              (CONFG_base+0x0308)
#define DRVPDN_CON3              (CONFG_base+0x030C)
#define DRVPDN_CON4              (CONFG_base+0x0330)

#define DRVPDN_CON0_SET          (CONFG_base+0x0310)
#define DRVPDN_CON1_SET          (CONFG_base+0x0314)
#define DRVPDN_CON2_SET          (CONFG_base+0x0318)
#define DRVPDN_CON3_SET          (CONFG_base+0x031C)
#define DRVPDN_CON4_SET          (CONFG_base+0x0334)

#define DRVPDN_CON0_CLR          (CONFG_base+0x0320)
#define DRVPDN_CON1_CLR          (CONFG_base+0x0324)
#define DRVPDN_CON2_CLR          (CONFG_base+0x0328)
#define DRVPDN_CON3_CLR          (CONFG_base+0x032C)
#define DRVPDN_CON4_CLR          (CONFG_base+0x0338)

#define DRVPDN_CON0_MDDMA           0x00000001

#define DRVPDN_CON1_LOGACC          0x00000001
#define DRVPDN_CON1_MDUART1         0x00000008
#define DRVPDN_CON1_MDUART2         0x00000100

#define DRVPDN_CON2_TDMA            0x00000001
#define DRVPDN_CON2_BSI2GPRE        0x00000004
#define DRVPDN_CON2_BPI2GPRE        0x00000008
#define DRVPDN_CON2_AFC2GPRE        0x00000010
#define DRVPDN_CON2_BSI3G           0x00000040
#define DRVPDN_CON2_BPI3G           0x00000100
#define DRVPDN_CON2_MDMIXED_SYS     0x00000200
#define DRVPDN_CON2_WCDMATIMER      0x00000400
#define DRVPDN_CON2_DIVIDER         0x00000800
#define DRVPDN_CON2_AFC3G           0x00001000

#define DRVPDN_CON3_OSTIMERMDARM    0x00000004
#define DRVPDN_CON3_OSTIMERFCORE4   0x00000008
#define DRVPDN_CON3_PFC             0x00000040
#define DRVPDN_CON3_MDIF            0x00000100
#define DRVPDN_CON3_FCS             0x00002000
#define DRVPDN_CON3_GCU             0x00004000

#define DRVPDN_CON4_BSI2G           0x00000004
#define DRVPDN_CON4_BPI2G           0x00000008
#define DRVPDN_CON4_AFC2G           0x00000010

#define AP_DRVPDN_CON0              (PERISYS_CONFG_base+0x18)
#define AP_DRVPDN_CON1              (PERISYS_CONFG_base+0x1C)

#define AP_DRVPDN_CON0_SET          (DUMMY_PDN_SET_REGISTER)
#define AP_DRVPDN_CON1_SET          (DUMMY_PDN_SET_REGISTER)

#define AP_DRVPDN_CON0_CLR          (DUMMY_PDN_CLR_REGISTER)
#define AP_DRVPDN_CON1_CLR          (DUMMY_PDN_CLR_REGISTER)

#define AP_DRVPDN_CON0_NFI           0x00000001
#define AP_DRVPDN_CON0_THERM         0x00000002
#define AP_DRVPDN_CON0_PWM1          0x00000004
#define AP_DRVPDN_CON0_PWM2          0x00000008
#define AP_DRVPDN_CON0_PWM3          0x00000010
#define AP_DRVPDN_CON0_PWM456        0x00000020
#define AP_DRVPDN_CON0_PWM7          0x00000040
#define AP_DRVPDN_CON0_SIMIF0        0x00000080
#define AP_DRVPDN_CON0_SIMIF1        0x00000100
#define AP_DRVPDN_CON0_USB           0x00000200
#define AP_DRVPDN_CON0_USB11         0x00000400
#define AP_DRVPDN_CON0_CCIF          0x00000800
#define AP_DRVPDN_CON0_APDMA         0x00001000
#define AP_DRVPDN_CON0_APXTIMER      0x00002000
#define AP_DRVPDN_CON0_KP            0x00004000
#define AP_DRVPDN_CON0_MSDC          0x00008000
#define AP_DRVPDN_CON0_MSDC1         0x00010000
#define AP_DRVPDN_CON0_MSDC2         0x00020000
#define AP_DRVPDN_CON0_MSDC3         0x00040000
#define AP_DRVPDN_CON0_APHIF         0x00080000
#define AP_DRVPDN_CON0_MDHIF         0x00100000
#define AP_DRVPDN_CON0_NLIARB        0x00200000
#define AP_DRVPDN_CON0_ACCDET        0x00400000
#define AP_DRVPDN_CON0_IRDAFRAMER    0x00800000
#define AP_DRVPDN_CON0_APUART1       0x01000000
#define AP_DRVPDN_CON0_APUART2       0x02000000
#define AP_DRVPDN_CON0_APUART3       0x04000000
#define AP_DRVPDN_CON0_APUART4       0x08000000
#define AP_DRVPDN_CON0_I2C           0x10000000
#define AP_DRVPDN_CON0_I2C2          0x20000000
#define AP_DRVPDN_CON0_I2CDUAL       0x40000000
#define AP_DRVPDN_CON0_AUXADC        0x80000000

#define AP_DRVPDN_CON1_SEJ           0x00000001
#define AP_DRVPDN_CON1_TRNG          0x00000002


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
#define MD2GSYS_CG_CON0_DEINTDMA 0x8000

#define MD2GSYS_CG_CON1_IRDMA    0x0002
#define MD2GSYS_CG_CON1_APCPRE   0x0040
#define MD2GSYS_CG_CON1_BFE      0x0400
#define MD2GSYS_CG_CON1_GCCTX    0x0800
#define MD2GSYS_CG_CON1_GCCRX    0x1000

#define MD2GSYS_CG_CON2_APC      0x0040


/* MMSYS1 MMSYS_CONFG_base */

#define MMSYS_CG_CON0          (MMSYS1_CONFG_base +0x0000)
#define MMSYS_CG_CON1          (MMSYS1_CONFG_base +0x0004)
#define MMSYS_CG_CON2          (MMSYS1_CONFG_base +0x0008)

#define MMSYS_CG_SET0          (MMSYS1_CONFG_base +0x0010)
#define MMSYS_CG_SET1          (MMSYS1_CONFG_base +0x0014)
#define MMSYS_CG_SET2          (MMSYS1_CONFG_base +0x0018)

#define MMSYS_CG_CLR0          (MMSYS1_CONFG_base +0x0020)
#define MMSYS_CG_CLR1          (MMSYS1_CONFG_base +0x0024)
#define MMSYS_CG_CLR2          (MMSYS1_CONFG_base +0x0028)

#define MMSYS_CG_CON0_EMI_SMI_LARB2     0x00000001
#define MMSYS_CG_CON0_EMI_ACP_SMI_LARB2 0x00000002
#define MMSYS_CG_CON0_EMI_SMI_LARB1     0x00000004
#define MMSYS_CG_CON0_EMI_SMI_LARB0     0x00000008
#define MMSYS_CG_CON0_VBUF              0x00000010
#define MMSYS_CG_CON0_VDEC              0x00000020
#define MMSYS_CG_CON0_VENC              0x00000040
#define MMSYS_CG_CON0_ACP_SMI_LARB2     0x00000080
#define MMSYS_CG_CON0_SMI_LARB2         0x00000100

#define MMSYS_CG_CON1_VRZ1         0x00000001
#define MMSYS_CG_CON1_CSI2         0x00000002
#define MMSYS_CG_CON1_FD           0x00000004
#define MMSYS_CG_CON1_RESZLB       0x00000008
#define MMSYS_CG_CON1_TVROT        0x00000010
#define MMSYS_CG_CON1_LCD          0x00000020
#define MMSYS_CG_CON1_RGB_ROT2     0x00000040
#define MMSYS_CG_CON1_PRZ1         0x00000080
#define MMSYS_CG_CON1_RDMA1        0x00000100
#define MMSYS_CG_CON1_VDO_ROT1     0x00000200
#define MMSYS_CG_CON1_RGB_ROT1     0x00000400
#define MMSYS_CG_CON1_VRZ          0x00000800
#define MMSYS_CG_CON1_RGB_ROT0     0x00001000
#define MMSYS_CG_CON1_PRZ0_MOUT    0x00002000
#define MMSYS_CG_CON1_PRZ0         0x00004000
#define MMSYS_CG_CON1_VDO_ROT0     0x00008000
#define MMSYS_CG_CON1_MOUT         0x00010000
#define MMSYS_CG_CON1_OVL_DMA_MIMO 0x00020000
#define MMSYS_CG_CON1_OVL_DMA_BPS  0x00040000
#define MMSYS_CG_CON1_OVL_DMA      0x00080000
#define MMSYS_CG_CON1_IPP_MOUT     0x00100000
#define MMSYS_CG_CON1_IPP          0x00200000
#define MMSYS_CG_CON1_EIS          0x00400000
#define MMSYS_CG_CON1_CRZ          0x00800000
#define MMSYS_CG_CON1_JPG_DMA      0x01000000
#define MMSYS_CG_CON1_BRZ_MOUT     0x02000000
#define MMSYS_CG_CON1_BRZ          0x04000000
#define MMSYS_CG_CON1_JPG_DEC      0x08000000
#define MMSYS_CG_CON1_JPG_ENC      0x10000000
#define MMSYS_CG_CON1_RDMA0_MOUT   0x20000000
#define MMSYS_CG_CON1_RDMA0        0x40000000
#define MMSYS_CG_CON1_CAM          0x80000000

#define MMSYS_CG_CON2_SCAM         0x00000001
#define MMSYS_CG_CON2_SPI          0x00000002
#define MMSYS_CG_CON2_TVC          0x00000004
#define MMSYS_CG_CON2_TVE          0x00000008
#define MMSYS_CG_CON2_DPI          0x00000010
#define MMSYS_CG_CON2_DSI          0x00000020
#define MMSYS_CG_CON2_H_SMI_LARB0  0x00000040
#define MMSYS_CG_CON2_H_SMI_LARB1  0x00000080
#define MMSYS_CG_CON2_H_SMI_LARB2  0x00000100

/* MMSYS2 MMSYS_CONFG_base */

#define MMSYS2_CG_CON0          (MMSYS2_CONFG_base +0x0300)

#define MMSYS2_CG_SET0          (MMSYS2_CONFG_base +0x0304)

#define MMSYS2_CG_CLR0          (MMSYS2_CONFG_base +0x0308)


#define MMSYS2_CG_CON0_SMI_LARB3    0x00000001
#define MMSYS2_CG_CON0_SMI_G2D      0x00000008
#define MMSYS2_CG_CON0_MFG          0x00000010
#define MMSYS2_CG_CON0_G3D          0x00004000
#define MMSYS2_CG_CON0_F26M         0x00008000
#define MMSYS2_CG_CON0_GDC          0x00010000
#define MMSYS2_CG_CON0_H_SMI_LARB3  0x00020000
#define MMSYS2_CG_CON0_H_MFG        0x00080000

#endif  /* !__PDN_HW_MT6575_SERIES_H__ */
