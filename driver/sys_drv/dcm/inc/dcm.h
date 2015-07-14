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
 *   dcm.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file defines device information related stuff
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *s
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "dma_hw.h"
#include "config_hw.h"
#include "drvpdn.h"
#include "reg_base.h"
#include "l1_interface.h"

#ifndef _DCM_H
#define _DCM_H

#define reg_or(regval, oval) ((regval) | (oval))
#define reg_and(regval, aval) ((regval) & (aval))
#define reg_aor(regval, aval, oval) reg_or(reg_and(regval, aval), oval)

#define DRV_Reg16(addr)               (*(volatile kal_uint16 *)(addr))
#define DRV_Reg32(addr)               (*(volatile kal_uint32 *)(addr))
#define DRV_Reg8(addr)                (*(volatile kal_uint8 *)(addr))

#if defined(MT6516)
/*Check power down: DMA1,4,5, IRDMA, and ARMCLK in 104MHz */
/* MCU_CLK only have 104Mhz or gating status, MCUCLK_CON is only a information for AHB/APB speed change, not MCU speed information */
/* *MCUCLK_CON initial value should be set as 0x0007 */
#define DCM_ENABLE_CHECK ((DRV_Reg32(DMA_GLBSTA) & 0x00000141)==0) && \
	                     (DRV_Reg16(GCG_CON0) & 0x0002)  &&          \
	                     ((DRV_Reg16(MCUCLK_CON)&0xF) == 0x0007)

#elif defined(TK6516)
/*Check power down: DMA1,4,5, ICE, IRDMA, and ARMCLK in 104MHz */
/* MCU_CLK only have 104Mhz or gating status, MCUCLK_CON is only a information for AHB/APB speed change, not MCU speed information */
/* *MCUCLK_CON initial value should be set as 0x0007 */
#define DCM_ENABLE_CHECK ((DRV_Reg32(DMA_GLBSTA) & 0x00000141)==0) && \
	                     (DRV_Reg16(DRVPDN_CON1) & 0x80000000)  &&       \
	                     (DRV_Reg16(DRVPDN_CON2) & 0x0002)  &&           \
	                     (DRV_Reg16(MCUCLK_CON) == 0x0007)
#elif defined(MT6253) || defined(MT6253T)
/*Check power down: DMA1~11, IRDMA1, PPP, CHE, WAVETABLE, LCD, GMC, and  MODEMCLK,ARMCLK,SRCCLK,MCUCLK, 52M 104M xM 52M*/
#define DCM_ENABLE_CHECK ((DRV_Reg32(DMA_GLBSTA) & 0x00155555)==0) &&  \
                         ((DRV_Reg16(DRVPDN_CON0) & 0x0048) == 0x0048) && \
	                     (DRV_Reg16(DRVPDN_CON1) & 0x0080) &&             \
                         ((DRV_Reg16(DRVPDN_CON3) & 0x1805) == 0x1805) && \
                         ((DRV_Reg16(MCUCLK_CON )& 0xFF7F) ==0x3703)
#elif defined(MT6229) || defined(MT6230)
/* Check power down: Check DMA1~10, IRDMA, PPP, CHE, WAVETABLE, LCD, GMC */
#define DCM_ENABLE_CHECK ((DRV_Reg32(DMA_GLBSTA) & 0x00055555)==0) &&    \
                         ((DRV_Reg16(DRVPDN_CON0) & 0x0078) == 0x0078) &&   \
                         (DRV_Reg16(DRVPDN_CON1) & 0x0080) &&               \
                         (DRV_Reg16(DRVPDN_CON3) == 0xFFFF) &&              \
                         (DRV_Reg16(MCUCLK_CON) == 0x0703)                                     
#elif defined(MT6238) || defined(MT6239) || defined(MT6235) || defined(MT6235B)
/* Check power down: Check DMA1~10, IRDMA, PPP, CHE, WAVETABLE, LCD, SPI, GMC and EMICLK,ARMCLK,AHBX4CLK,AHBX8CLK,104,208,52,104*/
#define DCM_ENABLE_CHECK ((DRV_Reg32(DMA_GLBSTA) & 0x00055555)==0) &&  \
                         ((DRV_Reg16(DRVPDN_CON0) & 0x0878) == 0x0878) && \
                         ((DRV_Reg16(DRVPDN_CON1) & 0x2080) == 0x2080) && \
                         (DRV_Reg16(DRVPDN_CON3) == 0xFFFF) &&            \
                         (DRV_Reg16(MCUCLK_CON) == 0x7F37)  
#elif defined(MT6228)
/* Check power down: Check DMA1~10, IRDMA, PPP, CHE, WAVETABLE, LCD, and GMC*/
#define DCM_ENABLE_CHECK ((DRV_Reg32(DMA_GLBSTA) & 0x00055555)==0) &&  \
                         ((DRV_Reg16(DRVPDN_CON0) & 0x0038) == 0x0038) &&  \
                         (DRV_Reg16(DRVPDN_CON1) & 0x0080) &&              \
                         (DRV_Reg16(DRVPDN_CON3) == 0xFFFF) &&             \
                         (DRV_Reg16(MCUCLK_CON) == 0x0703)
#elif defined(MT6223) || defined(MT6223P)
/* Check power down: Check DMA1~10, IRDMA, PPP, CHE, WAVETABLE, LCD, and GMC*/
#define DCM_ENABLE_CHECK ((DRV_Reg32(DMA_GLBSTA) & 0x00055555)==0) &&  \
                         ((DRV_Reg16(DRVPDN_CON0) & 0x0048) == 0x0048) &&  \
                         (DRV_Reg16(DRVPDN_CON1) & 0x0080) &&              \
                         (DRV_Reg16(DRVPDN_CON3) == 0x0001) &&             \
                         (DRV_Reg16(MCUCLK_CON)== 0x0303)
#elif defined(MT6225) 
/* Check power down: Check DMA1~10, IRDMA, PPP, CHE, WAVETABLE, LCD, and GMC*/
#define DCM_ENABLE_CHECK ((DRV_Reg32(DMA_GLBSTA) & 0x00055555)==0) &&  \
                         ((DRV_Reg16(DRVPDN_CON0) & 0x0048) == 0x0048) &&  \
                         (DRV_Reg16(DRVPDN_CON1) & 0x0080) &&              \
                         (DRV_Reg16(DRVPDN_CON3) == 0x1801) &&             \
                         (DRV_Reg16(MCUCLK_CON)== 0x0703)             
#elif defined(MT6226) || defined(MT6227) || defined(MT6226M) || defined(MT6226D) || defined(MT6227D) || defined(MT6226DS) || defined(MT6227DS)
/* Check power down: Check DMA1~10, WAVETABLE, LCD, and GMC (valid:0x7F91) */
#define DCM_ENABLE_CHECK ((DRV_Reg32(DMA_GLBSTA) & 0x00055555)==0) &&  \
                         (DRV_Reg16(DRVPDN_CON0) & 0x0008) &&              \
                         (DRV_Reg16(DRVPDN_CON1) & 0x0080) &&              \
                         ((DRV_Reg16(DRVPDN_CON3) & 0x7F91) == 0x7F91)&&   \
                         (DRV_Reg16(MCUCLK_CON) == 0x0003)
#elif defined(MT6268) ||  defined(MT6268A)
/*Check power down: DMA1~10,CHE(SEJ), IRDMA, WAVETABLE and GMC(except for sysram) or MMsys )*/
#define DCM_ENABLE_CHECK ((DRV_Reg32(DMA_GLBSTA) & 0x00055555) == 0) &&  \
                         ((DRV_Reg16(CG_CON0) & 0x0010) == 0x0010) &&  \
                         ((DRV_Reg16(GCG_CON0) & 0x0048) == 0x0048) && \
                         ((DRV_Reg32(MMCG_CON0) & 0x000FFFFF) == 0x000FFFFF || (DRV_Reg16(PWR_CON) & 0x0004) == 0) && \
                         (DRV_Reg16(MCUCLK_CON) == 0x7DE7)
#elif defined(MT6236) || defined(MT6236B)
#define DCM_ENABLE_CHECK ((DRV_Reg32(MCUSYS_PDN_CON0) & 0x00070000 ) == 0x00070000) && \
	                     ((DRV_Reg32(DMA_GLBSTA) & 0x00055555)==0) &&  \
	                     (DRV_Reg16(MCUCLK_CON) == 0x2000)
/* Check power donw: DMA1~11, SEJ, GMC, MMsys */
#elif defined(MT6251)
/* check power down: DMA, LCD, IR, IRDBG1/2, Wavetable, SEJ */
#define DCM_PLL_CON3     ((volatile UINT16P)(PLL_base+0x010C))
#define DCM_PLL_CON5     ((volatile UINT16P)(PLL_base+0x0114))
#define DCM_PLL_CON6     ((volatile UINT16P)(PLL_base+0x0118))

#define DCM_ENABLE_CHECK ((DRV_Reg32(DMA_GLBSTA) & 0x00555555)==0) &&  \
	                     (DRV_Reg16(DRVPDN_CON3) & 0x0004) &&  \
	                     ((DRV_Reg16(MD2GSYS_CG_CON0) & 0x3048) == 0x3048) && \
	                     (DRV_Reg16(MMSYS_CG_CON) & 0x0001) && \
	                     ((DRV_Reg16(DCM_PLL_CON6) & 0x3000) == 0x0000)
#elif defined(MT6589)
#define __HW_DCM__
#define DCM_ENABLE_CHECK (KAL_TRUE)
#undef DCM_LPM_ENABLE  //disabled, due to buggy LPM HW design.

#define MD_GLOBAL_CON0 				((volatile UINT32P)(CONFIG_base+0x0450))
#define MD_GLOBAL_CON0_CLR			((volatile UINT32P)(CONFIG_base+0x0458))
#define MD_GLOBAL_CON1 				((volatile UINT32P)(CONFIG_base+0x045c))
#define MD_TOP_MDMCU_DCM_CON0		((volatile UINT32P)(CONFIG_base+0x0510))
#define MD_TOP_MDMCU_DCM_CON1		((volatile UINT32P)(CONFIG_base+0x0514))
#define MD_TOP_MDBUS_DCM_CON0		((volatile UINT32P)(CONFIG_base+0x0518))
#define MD_TOP_MDBUS_DCM_CON1		((volatile UINT32P)(CONFIG_base+0x051C))
#define MD_AP_RES_ACK 				((volatile UINT32P)(CONFIG_base+0x0520)) //this register is undocumented.

#define MD_TOP_DCM_DEBUG_CON0 		((volatile UINT32P)(CONFIG_base+0x0470))
#define MD_TOP_DCM_DEBUG_STATUS0 	((volatile UINT32P)(CONFIG_base+0x0478))
#define MD_TOP_DCM_DEBUG_STATUS1	((volatile UINT32P)(CONFIG_base+0x047C))
#define MD_TOP_DCM_DEBUG_STATUS2 	((volatile UINT32P)(CONFIG_base+0x0480))
#define MD_TOP_DCM_DEBUG_STATUS3 	((volatile UINT32P)(CONFIG_base+0x0484))
#define MD_TOP_DCM_DEBUG_STATUS4	((volatile UINT32P)(CONFIG_base+0x0488))
#define MD_TOP_DCM_DEBUG_STATUS5	((volatile UINT32P)(CONFIG_base+0x048C))


#elif defined(MT6572) || defined (MT6582) || defined (MT6592) || defined (MT6571) || defined(MT6580)
#define __HW_DCM__
#define DCM_ENABLE_CHECK (KAL_TRUE)
#undef DCM_LPM_ENABLE  //disabled as default, due to LP golden setting check.

#define MD_GLOBAL_CON0 				((volatile UINT32P)(CONFIG_base+0x0450))
#define MD_GLOBAL_SET0	    		((volatile UINT32P)(CONFIG_base+0x0454))
#define MD_GLOBAL_CLR0  			((volatile UINT32P)(CONFIG_base+0x0458))
#define MD_GLOBAL_CON0_CLR 			((volatile UINT32P)(CONFIG_base+0x0458))   //alias 
#define MD_GLOBAL_CON1 				((volatile UINT32P)(CONFIG_base+0x045c))
#define MD_TOP_MDMCU_DCM_CON0		((volatile UINT32P)(CONFIG_base+0x0510))
#define MD_TOP_MDMCU_DCM_CON1		((volatile UINT32P)(CONFIG_base+0x0514))
#define MD_TOP_MDBUS_DCM_CON0		((volatile UINT32P)(CONFIG_base+0x0518))
#define MD_TOP_MDBUS_DCM_CON1		((volatile UINT32P)(CONFIG_base+0x051C))
#define MD_AP_RES_ACK 				((volatile UINT32P)(CONFIG_base+0x0520)) 

#define MD_TOP_DCM_DEBUG_CON0 		((volatile UINT32P)(CONFIG_base+0x0530))
#define MD_TOP_DCM_DEBUG_STATUS0 	((volatile UINT32P)(CONFIG_base+0x0538))
#define MD_TOP_DCM_DEBUG_STATUS1	((volatile UINT32P)(CONFIG_base+0x053C))
#define MD_TOP_DCM_DEBUG_STATUS2	((volatile UINT32P)(CONFIG_base+0x0540))
#define MD_TOP_DCM_DEBUG_STATUS3 	((volatile UINT32P)(CONFIG_base+0x0544))
#define MD_TOP_DCM_DEBUG_STATUS4	((volatile UINT32P)(CONFIG_base+0x0548))
#define MD_TOP_DCM_DEBUG_STATUS5	((volatile UINT32P)(CONFIG_base+0x054C))


#define MD_INFRA_DCM_DEBUG_CON0		((volatile UINT32P)(CONFIG_base+0x0470))
#define MD_INFRA_DCM_DEBUG_STATUS0 	((volatile UINT32P)(CONFIG_base+0x0478))
#define MD_INFRA_DCM_DEBUG_STATUS1	((volatile UINT32P)(CONFIG_base+0x047C))
#define MD_INFRA_DCM_DEBUG_STATUS2 	((volatile UINT32P)(CONFIG_base+0x0480))
#define MD_INFRA_DCM_DEBUG_STATUS3 	((volatile UINT32P)(CONFIG_base+0x0484))
#define MD_INFRA_DCM_DEBUG_STATUS4	((volatile UINT32P)(CONFIG_base+0x0488))
#define MD_INFRA_DCM_DEBUG_STATUS5	((volatile UINT32P)(CONFIG_base+0x048C))




#elif defined(MT6280)
#define __HW_DCM__
#define DCM_ENABLE_CHECK (KAL_TRUE)


#define PLL_CLKSW_FDIV0    			((volatile kal_uint16*)(MIX_ABB_base+0x0070))
#define AP_CG_CON                   ((volatile UINT32P)(AP_CONFIG_base+0x0000))
#define AP_CG_SET                   ((volatile UINT32P)(AP_CONFIG_base+0x0004))
#define AP_CG_CLR                   ((volatile UINT32P)(AP_CONFIG_base+0x0008))
#define AP_F32K_SEL                 ((volatile UINT32P)(AP_CONFIG_base+0x000C))
#define MDMCU_DCM_CON_0             ((volatile UINT32P)(AP_CONFIG_base+0x0010))
#define MDMCU_DCM_CON_1             ((volatile UINT32P)(AP_CONFIG_base+0x0014))
#define APMCU_DCM_CON_0             ((volatile UINT32P)(AP_CONFIG_base+0x0018))
#define APMCU_DCM_CON_1             ((volatile UINT32P)(AP_CONFIG_base+0x001C))
#define EMI_DCM_CON_0               ((volatile UINT32P)(AP_CONFIG_base+0x0020))
#define EMI_DCM_CON_1               ((volatile UINT32P)(AP_CONFIG_base+0x0024))
#define MDBUS_DCM_CON_0             ((volatile UINT32P)(AP_CONFIG_base+0x0028))
#define MDBUS_DCM_CON_1             ((volatile UINT32P)(AP_CONFIG_base+0x002C))
#define MDDSP_DCM_CON_0             ((volatile UINT32P)(AP_CONFIG_base+0x0030))
#define MDDSP_DCM_CON_1             ((volatile UINT32P)(AP_CONFIG_base+0x0034))
#define TOP_CLOCK_CON               ((volatile UINT32P)(AP_CONFIG_base+0x0038))
#define D_FUNC_MODE_CON             ((volatile UINT32P)(AP_CONFIG_base+0x003C))
#define AP_DCM_CON_0                ((volatile UINT32P)(AP_CONFIG_base+0x0040))
#define AP_DCM_CON_1                ((volatile UINT32P)(AP_CONFIG_base+0x0044))
#define DBG_BUS_SEL                 ((volatile UINT32P)(AP_CONFIG_base+0x0048))
#define AP_DBG_BUS_SEL              ((volatile UINT32P)(AP_CONFIG_base+0x004C))
#define AP_ARM9_DBGEN               ((volatile UINT32P)(AP_CONFIG_base+0x0050))
#define AP_ARM9_DBGEN_LOCK          ((volatile UINT32P)(AP_CONFIG_base+0x0054))
#define AP_NONPWR_DCM_DEBUG_CON0    ((volatile UINT32P)(AP_CONFIG_base+0x0060))
#define AP_NONPWR_DCM_DEBUG_CON1    ((volatile UINT32P)(AP_CONFIG_base+0x0064))
#define AP_NONPWR_DCM_DEBUG_SEL     ((volatile UINT32P)(AP_CONFIG_base+0x0068))
#define AP_NONPWR_DCM_DEBUG_OUT     ((volatile UINT32P)(AP_CONFIG_base+0x006C))
#define AP_PWR_DCM_DEBUG_CON0       ((volatile UINT32P)(AP_CONFIG_base+0x0070))
#define AP_PWR_DCM_DEBUG_CON1       ((volatile UINT32P)(AP_CONFIG_base+0x0074))
#define AP_PWR_DCM_DEBUG_SEL        ((volatile UINT32P)(AP_CONFIG_base+0x0078))
#define AP_PWR_DCM_DEBUG_OUT        ((volatile UINT32P)(AP_CONFIG_base+0x007C))
#define AP_BUS_IDLE_CON_1           ((volatile UINT32P)(AP_CONFIG_base+0x0204))

#define PWR_GLOBAL_CON0             ((volatile UINT32P)(CONFIG_base+0x00A0))
#define PWR_GLOBAL_SET0             ((volatile UINT32P)(CONFIG_base+0x00A4))
#define PWR_GLOBAL_CLR0             ((volatile UINT32P)(CONFIG_base+0x00A8))
#define PWR_GLOBAL_CON1             ((volatile UINT32P)(CONFIG_base+0x00AC))
#define PWR_GLOBAL_CON2             ((volatile UINT32P)(CONFIG_base+0x00B0))
#define PWR_GLOBAL_STATUS0          ((volatile UINT32P)(CONFIG_base+0x00B8))
#define PWR_GLOBAL_STATUS1          ((volatile UINT32P)(CONFIG_base+0x00BC))
#define NONPWR_GLOBAL_CON0          ((volatile UINT32P)(CONFIG_base+0x00C0))
#define NONPWR_GLOBAL_SET0          ((volatile UINT32P)(CONFIG_base+0x00C4))
#define NONPWR_GLOBAL_CLR0          ((volatile UINT32P)(CONFIG_base+0x00C8))
#define PWR_DCM_DEBUG_CON0          ((volatile UINT32P)(CONFIG_base+0x0100))
#define PWR_DCM_DEBUG_CON1          ((volatile UINT32P)(CONFIG_base+0x0104))
#define PWR_DCM_DEBUG_STATUS0       ((volatile UINT32P)(CONFIG_base+0x0108))
#define PWR_DCM_DEBUG_STATUS1       ((volatile UINT32P)(CONFIG_base+0x010C))
#define PWR_DCM_DEBUG_STATUS2       ((volatile UINT32P)(CONFIG_base+0x0110))
#define PWR_DCM_DEBUG_STATUS3       ((volatile UINT32P)(CONFIG_base+0x0114))
#define PWR_DCM_DEBUG_STATUS4       ((volatile UINT32P)(CONFIG_base+0x0118))
#define PWR_DCM_DEBUG_STATUS5       ((volatile UINT32P)(CONFIG_base+0x011C))
#define NONPWR_DCM_DEBUG_CON0       ((volatile UINT32P)(CONFIG_base+0x0120))
#define NONPWR_DCM_DEBUG_CON1       ((volatile UINT32P)(CONFIG_base+0x0124))
#define NONPWR_DCM_DEBUG_STATUS0    ((volatile UINT32P)(CONFIG_base+0x0128))
#define NONPWR_DCM_DEBUG_STATUS1    ((volatile UINT32P)(CONFIG_base+0x012C))
#define NONPWR_DCM_DEBUG_STATUS2    ((volatile UINT32P)(CONFIG_base+0x0130))
#define NONPWR_DCM_DEBUG_STATUS3    ((volatile UINT32P)(CONFIG_base+0x0134))
#define NONPWR_DCM_DEBUG_STATUS4    ((volatile UINT32P)(CONFIG_base+0x0138))
#define NONPWR_DCM_DEBUG_STATUS5    ((volatile UINT32P)(CONFIG_base+0x013C))
#define NONPWR_DCM_DEBUG_CON2       ((volatile UINT32P)(CONFIG_base+0x0140))
#define DEBUG_CON                   ((volatile UINT32P)(CONFIG_base+0x0160))
/* SEJ base */
#define SEJ_CON                     ((volatile UINT32P)(SEJ_base+0x0))


#elif defined(MT6276)
/* check power down: DMA, SEJ, MM sys, log_2G, */
#define __HW_DCM__

#if defined(MT6276_S00)
#define EMI_DCM_FREQ     (0xF)
#define DMA_RUNNING_MASK (0x000001FF)
#else /* MT6276_S01 or latter */
#define EMI_DCM_FREQ     (0x1F)
#define DMA_RUNNING_MASK (0x00000FFF)
#endif

#define DCM_WAIT_FOR_DSP_COMPLETE  (6666)

#define DCM_ARM_PERI_MASK     (0x0800)
#define DCM_DSP_PERI_MASK     (0x0400)
#define DCM_3G_PERI_MASK      (0x0200)
#define DCM_2G_PERI_MASK      (0x0100)
#define DCM_ARM_SLEEP_BACKUP  ((volatile UINT16P)(CONFIG_base+0x10))
#define DCM_DSP_SLEEP_BACKUP  ((volatile UINT16P)(CONFIG_base+0x14))

#define DCM_HW_MISC0     ((volatile UINT32P)(CONFIG_base+0x900))
#define MMSYS_PWR_CON    (TOPSM_base+0x80C)
#define DCM_BUS_GATED_EN ((volatile UINT16P)(CONFIG_base+0x558))
#define DCM_RG_CK_ALW_ON ((volatile UINT16P)(CONFIG_base+0x824))
#define DCM_RG_CK_DCM_EN1 ((volatile UINT16P)(CONFIG_base+0x828))
#define DCM_RG_CK_DCM_EN2 ((volatile UINT16P)(CONFIG_base+0x834))
#define MD2G_CG_CON0     (MD2G_CFG_base+0x300)
#define MD2G_CG_CON1     (MD2G_CFG_base+0x304)
#define MD2G_CG_CON2     (MD2G_CFG_base+0x308)
#define DCM_RM_PERI_CON  ((volatile UINT32P)(TOPSM_base+0x30))

#define DCM_F32K_CNT     ((volatile UINT32P)(TOPSM_base+0x104))
#define DCM_RM_TMR_SSTA  ((volatile UINT32P)(TOPSM_base+0x40))
#define DCM_CCF_CLK_CON  ((volatile UINT32P)(TOPSM_base+0x200))

#define DCM_ENABLE_CHECK ((DRV_Reg16(DRVPDN_CON0) & 0x0010) == 0x0010) && \
	                     ((DRV_Reg32(DMA_GLBST_RUNNING) & DMA_RUNNING_MASK) == 0) && \
	                     ((DRV_Reg32(MMSYS_PWR_CON) & 0x00000004) == 0) && \
	                     ( ((MD2G_SLEEP_STATUS() & 0x1) == 0x1)?\
	                       ((DRV_Reg16(MD2G_CG_CON0) & 0x4000) == 0x4000):1 )

#elif defined(MT6256)
/* Check power down: DMA1~10, LCD, NFI, MM sys, MD2G sys */
#define __HW_DCM__                      /* Use HWDCM for MT6256 */
#define __USE_HW_DCM_CYCLE_COUNTER__    /* Use HW DCM cycle counter */
#define __ENABLE_EMI_DCM_AT_IDLE__       /* enable HW DCM only when idle task is running to reduce EMI access latency */
#define DCM_PLL_CON1     ((volatile UINT16P)(PLL_base+0x104))
#define DCM_PLL_CON2        ((volatile UINT16P)(PLL_base+0x108))
#define DCM_PLL_CON3     ((volatile UINT16P)(PLL_base+0x10C))
#define DCM_PLL_CON4        ((volatile UINT16P)(PLL_base+0x110))
#define DCM_PLL_CON5     ((volatile UINT16P)(PLL_base+0x114))
#define DCM_PLL_CON6     ((volatile UINT16P)(PLL_base+0x118))
#define DCM_PLL_CON7        ((volatile UINT16P)(PLL_base+0x11C))
#define DCM_PLL_CON8        ((volatile UINT16P)(PLL_base+0x120))
#define DCM_PLL_CON9        ((volatile UINT16P)(PLL_base+0x124))
#define DCM_ARMSYS_SYNC_CON ((volatile UINT16P)(CONFIG_base+0x440))
#define DCM_MCUCLK_CON   ((volatile UINT16P)(CONFIG_base+0x204))
#define DCM_MCUSYS_DCM_EN0  ((volatile UINT16P)(CONFIG_base+0x738))
#define DCM_MCUSYS_DCM_EN1  ((volatile UINT16P)(CONFIG_base+0x73C))
#define DCM_MCUSYS_DCM_EN2  ((volatile UINT16P)(CONFIG_base+0x740))
#define DCM_MM_DCM_EN       ((volatile UINT32P)(CONFIG_base+0x744))
#define DCM_MD2G_DCM_EN     ((volatile UINT32P)(CONFIG_base+0x748))
#define DCM_MCUSYS_PDN_CON0 ((volatile UINT32P)(CONFIG_base+0x700))
#define DCM_MCUSYS_PDN_CON1 ((volatile UINT16P)(CONFIG_base+0x704))
#define DCM_MCUSYS_PDN_CON2 ((volatile UINT16P)(CONFIG_base+0x708))
#define DCM_MCUSYS_PDN_CLR1 ((volatile UINT16P)(CONFIG_base+0x724))
#define DCM_MCUSYS_PDN_SET1 ((volatile UINT16P)(CONFIG_base+0x714))
#define DCM_MCUSYS_PDN_SET1 ((volatile UINT16P)(CONFIG_base+0x714))
#define DCM_MD2GSYS_CG_CON0 ((volatile UINT16P)(MD2GCONFG_base+0x0))
#define DCM_MD2GSYS_CG_CON2 ((volatile UINT16P)(MD2GCONFG_base+0x0008))
#define DCM_MD2GSYS_CG_CON4 ((volatile UINT16P)(MD2GCONFG_base+0x0030))
#define DCM_MMSYS_CG_CON    ((volatile UINT32P)(MMCONFG_base+0x0))
#define DCM_FQMTR_CON0      ((volatile UINT16P)(PLL_base+0x1080))
#define DCM_FQMTR_CON1      ((volatile UINT16P)(PLL_base+0x1084))
#define DCM_FQMTR_CON2      ((volatile UINT16P)(PLL_base+0x1088))

#if defined(MT6256_S00)
#define DCM_ENABLE_CHECK ((DRV_Reg32(MCUSYS_PDN_CON0) & 0x00070000 ) == 0x00070000) && \
	                     ((DRV_Reg16(MCUSYS_PDN_CON1) & 0x1000 ) == 0x1000)         && \
	                     ((DRV_Reg32(DMA_GLBST_RUNNING) & 0x00001FF)==0)            &&\
	                     ((DRV_Reg16(DCM_PLL_CON6) & 0x3000) == 0x0000)	                     
#else
    /* For E2 the SWDCM is only used with LP Audio mode, which is combined with system sleep
       mode so we don't need to check the modules status */
    #define DCM_ENABLE_CHECK (KAL_TRUE)	      
#endif
#elif defined(MT6253E) || defined(MT6253L) || defined(MT6252) || defined(MT6252H)
/*Check power down: DMA1~11, PPP, CHE, WAVETABLE, LCD, GMC, and  MODEMCLK,ARMCLK,SRCCLK,MCUCLK, 52M 104M xM 52M*/
#define DCM_ENABLE_CHECK ((DRV_Reg32(DMA_GLBSTA) & 0x00015555)==0) &&  \
                         ((DRV_Reg16(DRVPDN_CON0) & 0x0008) == 0x0008) && \
	                     (DRV_Reg16(DRVPDN_CON1) & 0x0080) &&             \
                         (DRV_Reg16(DRVPDN_CON3) == 0xF807) &&            \
                         ((DRV_Reg16(MCUCLK_CON )& 0xFF7F) ==0x3703)
#elif defined(MT6573)
#define __HW_DCM__
#define DCM_BUS_GATED_EN       ((volatile UINT16P)(AP_CONFIG_base+0x50))
#define DCM_RG_CK_ALW_ON       ((volatile UINT16P)(AP_CONFIG_base+0x124))
#define DCM_RG_CK_DCM_EN       ((volatile UINT16P)(AP_CONFIG_base+0x128))
#define DCM_MDARM_CCTL         ((volatile UINT16P)(CONFIG_base+0x100))
#define DCM_MDARM_DCM_EN       ((volatile UINT16P)(CONFIG_base+0x104))
#define DCM_RG_CK_DCM_DSP_EN   ((volatile UINT16P)(CONFIG_base+0x108))
#define DCM_MDPER_SLP_CON      ((volatile UINT16P)(CONFIG_base+0x438))

#define MD2G_CG_CON0           (MD2G_CFG_base+0x300)
#define MD2G_CG_CON1           (MD2G_CFG_base+0x304)
#define MD2G_CG_CON2           (MD2G_CFG_base+0x308)

#define DCM_ENABLE_CHECK ( ((MD2G_SLEEP_STATUS() & 0x1) == 0x1)? \
                           ((DRV_Reg16(MD2G_CG_CON0) & 0x4000) == 0x4000):1 )
#elif defined(MT6575) || defined(MT6577)

#define __HW_DCM__
#define DCM_ENABLE_CHECK  (1) /* MT6575 use HW_DCM */

#define DCM_PERI_BUS_CON0            ((volatile UINT32P)(CONFIG_base+0x0550))
#define DCM_BUS_GATED_EN             ((volatile UINT32P)(CONFIG_base+0x0558))
#define DCM_DSP_IDLE_FSEL            ((volatile UINT32P)(CONFIG_base+0x0814))
#define DCM_FBUS_IDLE_FSEL           ((volatile UINT32P)(CONFIG_base+0x081C))
#define DCM_SBUS_IDLE_FSEL           ((volatile UINT32P)(CONFIG_base+0x0820))
#define DCM_RG_CK_ALW_ON             ((volatile UINT32P)(CONFIG_base+0x0824))
#define DCM_RG_CK_DCM_EN             ((volatile UINT32P)(CONFIG_base+0x0828))
#define DCM_RG_CK_DCM_DSP_EN         ((volatile UINT32P)(CONFIG_base+0x0834))
#define DCM_RG_GLOBALCON_CON         ((volatile UINT32P)(CONFIG_base+0x0838))
#define DCM_HW_MISC0                 ((volatile UINT32P)(CONFIG_base+0x0900))
#define DCM_ARM_BUS_ACCESS_CON       ((volatile UINT32P)(CONFIG_base+0x09A0))

#define DCM_INFRA_TOPCKGEN_DCMCTL    ((volatile UINT32P)(AP_INFRACFG_base+0x010))
#define DCM_INFRA_TOPCKGEN_DCMFSEL   ((volatile UINT32P)(AP_INFRACFG_base+0x018))
#define DCM_INFRA_GLOBALCON_DCMCTL   ((volatile UINT32P)(AP_INFRACFG_base+0x050))
#define DCM_INFRA_GLOBALCON_DCMFSEL  ((volatile UINT32P)(AP_INFRACFG_base+0x058))

#define DCM_PERI_GLOBALCON_DCMCTL    ((volatile UINT32P)(PERISYS_CONFG_base+0x020))
#define DCM_PERI_GLOBALCON_DCMFSEL   ((volatile UINT32P)(PERISYS_CONFG_base+0x028))

#define DCM_MMSYS2_GLOBALCON_DCMCTL  ((volatile UINT32P)(MMSYS2_CONFG_base+0x320))
#define DCM_MMSYS2_GLOBALCON_DCMFSEL ((volatile UINT32P)(MMSYS2_CONFG_base+0x328))

#define DCM_RM_PWR_STA               ((volatile UINT16P)(TOPSM_base+0x820))
#define DCM_RM_PWR_STA_ARM_PWR_ACK   (0x80)
#define DCM_BOOT_JUMP_ADDR           ((volatile UINT32P)(CONFIG_base+0x0980))

#elif defined(MT6255)
/* Check power down: DMA1~10, LCD, NFI, MM sys, MD2G sys */
#define __HW_DCM__                      /* Use HWDCM for MT6256 */
#define __USE_HW_DCM_CYCLE_COUNTER__    /* Use HW DCM cycle counter */
///AST, 6255 does not need this workaround. 
///#define __ENABLE_EMI_DCM_AT_IDLE__       /* enable HW DCM only when idle task is running to reduce EMI access latency */
#define DCM_PLL_CON1     ((volatile UINT16P)(PLL_base+0x104))
#define DCM_PLL_CON2        ((volatile UINT16P)(PLL_base+0x108))
#define DCM_PLL_CON3     ((volatile UINT16P)(PLL_base+0x10C))
#define DCM_PLL_CON4        ((volatile UINT16P)(PLL_base+0x110))
#define DCM_PLL_CON5     ((volatile UINT16P)(PLL_base+0x114))
#define DCM_PLL_CON6     ((volatile UINT16P)(PLL_base+0x118))
#define DCM_PLL_CON7        ((volatile UINT16P)(PLL_base+0x11C))
#define DCM_PLL_CON8        ((volatile UINT16P)(PLL_base+0x120))
#define DCM_PLL_CON9        ((volatile UINT16P)(PLL_base+0x124))
//#define DCM_ARMSYS_SYNC_CON ((volatile UINT16P)(CONFIG_base+0x440))
#define DCM_MCUCLK_CON   ((volatile UINT16P)(CONFIG_base+0x204))
#define DCM_MCUSYS_DCM_EN0  ((volatile UINT16P)(CONFIG_base+0x738))
#define DCM_MCUSYS_DCM_EN1  ((volatile UINT16P)(CONFIG_base+0x73C))
#define DCM_MCUSYS_DCM_EN2  ((volatile UINT16P)(CONFIG_base+0x740))
#define DCM_MM_DCM_EN       ((volatile UINT32P)(CONFIG_base+0x744))
#define DCM_MD2G_DCM_EN     ((volatile UINT32P)(CONFIG_base+0x748))
#define DCM_MCUSYS_PDN_CON0 ((volatile UINT32P)(CONFIG_base+0x700))
#define DCM_MCUSYS_PDN_CON1 ((volatile UINT16P)(CONFIG_base+0x704))
#define DCM_MCUSYS_PDN_CON2 ((volatile UINT16P)(CONFIG_base+0x708))
#define DCM_MCUSYS_PDN_CLR1 ((volatile UINT16P)(CONFIG_base+0x724))
//#define DCM_MCUSYS_PDN_SET0 ((volatile UINT16P)(CONFIG_base+0x710))
#define DCM_MCUSYS_PDN_SET1 ((volatile UINT16P)(CONFIG_base+0x714))
#define DCM_MD2GSYS_CG_CON0 ((volatile UINT16P)(MD2GCONFG_base+0x0))
#define DCM_MD2GSYS_CG_CON2 ((volatile UINT16P)(MD2GCONFG_base+0x0008))
#define DCM_MD2GSYS_CG_CON4 ((volatile UINT16P)(MD2GCONFG_base+0x0030))
#define DCM_MMSYS_CG_CON    ((volatile UINT32P)(MMCONFG_base+0x0))
#define DCM_FQMTR_CON0      ((volatile UINT16P)(PLL_base+0x1080))
#define DCM_FQMTR_CON1      ((volatile UINT16P)(PLL_base+0x1084))
#define DCM_FQMTR_CON2      ((volatile UINT16P)(PLL_base+0x1088))

#if defined (__HW_DCM__)
#define DCM_ENABLE_CHECK  (KAL_TRUE)
#else
#define DCM_ENABLE_CHECK (((DRV_Reg32(DMA_GLBST_RUNNING) & 0x0000077D)== 0) && \
                          ((DRV_Reg16(DCM_PLL_CON8) & 0x50) == 0x50) && \
                          ((DRV_Reg32(DCM_MCUSYS_PDN_CON0) & 0x44602) == 0x44602) && \
                          ((DRV_Reg16(DCM_MCUSYS_PDN_CON1) & 0x1210) == 0x1210) && \
                          ((DRV_Reg16(DCM_MCUSYS_PDN_CON2) & 0x0300) == 0x0300)) 

#endif

#endif                         

/* 
 * PLL save mode implementation
 */
#if defined(MT6276)

#if defined(MT6276_S00)
#define DCM_PLL_CON0                (MIX_ABB_base+0x100)
#define DCM_PLL_CON1                (MIX_ABB_base+0x104)
#define DCM_PLL_CON2                (MIX_ABB_base+0x108)
#define DCM_PLL_CON3                (MIX_ABB_base+0x10C)
#define DCM_PLL_CON4                (MIX_ABB_base+0x110)
#define DCM_PLL_CON5                (MIX_ABB_base+0x114)

#define DCM_CLKSW_PLLDIV_CON0       (MIX_ABB_base+0x11C)
#define DCM_CLKSW_PLLDIV_CON1       (MIX_ABB_base+0x120)
#define DCM_CLKSW_PLLDIV_CON2       (MIX_ABB_base+0x124)
#define DCM_CLKSW_PLLDIV_CON3       (MIX_ABB_base+0x128)

#define DCM_CLKSW_PLLCNTEN_CON      (MIX_ABB_base+0x12C)

#define DCM_MPLL_CON0               (MIX_ABB_base+0x140)
#define DCM_MPLL_CON1               (MIX_ABB_base+0x144)
#define DCM_MPLL_CON2               (MIX_ABB_base+0x148)
#define DCM_MPLL_CON3               (MIX_ABB_base+0x14C)

#define DCM_DPLL_CON0               (MIX_ABB_base+0x180)
#define DCM_DPLL_CON1               (MIX_ABB_base+0x184)
#define DCM_DPLL_CON2               (MIX_ABB_base+0x188)
#define DCM_DPLL_CON3               (MIX_ABB_base+0x18C)

#define DCM_EPLL_CON0               (MIX_ABB_base+0x1C0)
#define DCM_EPLL_CON1               (MIX_ABB_base+0x1C4)
#define DCM_EPLL_CON2               (MIX_ABB_base+0x1C8)
#define DCM_EPLL_CON3               (MIX_ABB_base+0x1CC)

#else /* MT6276_S01 or latter */

#define DCM_PLL_CON0                ((volatile UINT32P)(MIX_ABB_base+0x100))
#define DCM_PLL_CON1                ((volatile UINT32P)(MIX_ABB_base+0x104))
#define DCM_PLL_CON2                ((volatile UINT32P)(MIX_ABB_base+0x108))
#define DCM_PLL_CON3                ((volatile UINT32P)(MIX_ABB_base+0x10C))
#define DCM_PLL_CON4                ((volatile UINT32P)(MIX_ABB_base+0x110))
#define DCM_PLL_CON5                ((volatile UINT32P)(MIX_ABB_base+0x114))

#define DCM_CLKSW_PLLDIV_CON0       ((volatile UINT32P)(MIX_ABB_base+0x11C))
#define DCM_CLKSW_PLLDIV_CON1       ((volatile UINT32P)(MIX_ABB_base+0x120))
#define DCM_CLKSW_PLLDIV_CON2       ((volatile UINT32P)(MIX_ABB_base+0x124))
#define DCM_CLKSW_PLLDIV_CON3       ((volatile UINT32P)(MIX_ABB_base+0x128))

#define DCM_CLKSW_PLLCNTEN_CON      ((volatile UINT32P)(MIX_ABB_base+0x12C))

#define DCM_MPLL_CON0               ((volatile UINT32P)(MIX_ABB_base+0x140))
#define DCM_MPLL_CON1               ((volatile UINT32P)(MIX_ABB_base+0x144))
#define DCM_MPLL_CON2               ((volatile UINT32P)(MIX_ABB_base+0x148))
#define DCM_MPLL_CON3               ((volatile UINT32P)(MIX_ABB_base+0x14C))

#define DCM_DPLL_CON0               ((volatile UINT32P)(MIX_ABB_base+0x180))
#define DCM_DPLL_CON1               ((volatile UINT32P)(MIX_ABB_base+0x184))
#define DCM_DPLL_CON2               ((volatile UINT32P)(MIX_ABB_base+0x188))
#define DCM_DPLL_CON3               ((volatile UINT32P)(MIX_ABB_base+0x18C))

#define DCM_EPLL_CON0               ((volatile UINT32P)(MIX_ABB_base+0x1C0))
#define DCM_EPLL_CON1               ((volatile UINT32P)(MIX_ABB_base+0x1C4))
#define DCM_EPLL_CON2               ((volatile UINT32P)(MIX_ABB_base+0x1C8))
#define DCM_EPLL_CON3               ((volatile UINT32P)(MIX_ABB_base+0x1CC))

#define DCM_FPLL_CON0               ((volatile UINT32P)(MIX_ABB_base+0x2C0))
#define DCM_FPLL_CON1               ((volatile UINT32P)(MIX_ABB_base+0x2C4))

#define DCM_FHCTL_CLKSEL_CON0       ((volatile UINT32P)(MIX_ABB_base+0x130))
#define DCM_FHCTL_CLKSEL_CON1       ((volatile UINT32P)(MIX_ABB_base+0x134))

#endif

typedef enum {
    MCU_PLL = 0xFF00,
    DSP_PLL,
    EMI_PLL,
    GSM_PLL,
    WCDMA_PLL,
    BASE_26MHZ
} pll_source_t;

typedef enum {
    MCU_PLL_650MHZ = 0xF000,
    MCU_PLL_624MHZ,
    MCU_PLL_598MHZ
} mcu_pll_speed_t;

#endif /* MT6276 */

typedef enum {
    DSP_PLL_312MHZ = 0xFE00,
    DSP_PLL_260MHZ,
    DSP_PLL_208MHZ
} dsp_pll_speed_t;

typedef enum {
    PLL_2G_TALKING = 0xFD00,
    PLL_3G_TALKING,
    PLL_VIDEO_PLAY
} pll_use_scenario_t;

void enter_PLL_save_mode(pll_use_scenario_t pll_scenario);
void leave_PLL_save_mode(pll_use_scenario_t pll_scenario);

kal_int32 arm_enter_standby_mode(kal_int32);

/** 
 * Here is a section of definition to wrap DCM supported features as internal specified option.
 **/
#if defined (__AUDIO_DSP_LOWPOWER_V2__)
#if defined (MT6256)
#define DCM_AUDIO_DSP_LOWPOWER_V2_SUPPORT 1
#endif // #if defined (MT6256)
#endif  // #if defined (__AUDIO_DSP_LOWPOWER_V2__)

#if defined (MT6255) || defined (MT6256)
/**
 * to fix HW BUG that 
 * 1. bridge will postpond write transaction, and
 * 2. slave device responces in a long latency.
 * APB_DUMMY_READY() will push write transaction and make a delay.
 **/
#undef APB_PLL_DUMMY_READ
#define APB_PLL_DUMMY_READ() do { *(volatile long *)(PLL_base); } while(0)
#undef APB_CONFIG_DUMMY_READ
#define APB_CONFIG_DUMMY_READ() do { *(volatile long *)(CONFIG_base); } while(0)
#else //#if defined (MT6255) || defined (MT6256)
#define APB_PLL_DUMMY_READ() do {  } while(0)
#define APB_CONFIG_DUMMY_READ() do {  } while(0)
#endif //#if defined (MT6255) || defined (MT6256)


#endif /* _DCM_H */
