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
 * tst_coresight_control.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file delares the Coresight control methods
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if defined(__TST_DNT_LOGGING__) || defined(USE_DNT_LOGGING) 
 
#ifndef __TST_CORESIGHT_CONTROL_H__
#define __TST_CORESIGHT_CONTROL_H__

#if defined(__MTK_TARGET__)
  #include "reg_base.h"  
#else //__MTK_TARGET__
  #if defined(MT6276) || defined(BB_MT6276)
    #define DEM_base (0x6800A000)  
  #elif defined(MT6573) || defined(BB_MT6573) 
    #define DEM_base (0x700FA000)
  #elif defined(TK6280) || defined(BB_TK6280) 
    #define DEM_base (0x7109A000)	
  #elif defined(MT6280) || defined(BB_MT6280) 
    #define DEM_base (0xA00AA000)		
  #endif  //#if defined(MT6276) || defined(BB_MT6276)
#endif  //__MTK_TARGET__


#define DEBUG_APB_BASE_ADDRESS (DAPROM_base)
#define TRACE_FUNNEL_1     (DEBUG_APB_BASE_ADDRESS+0x4000)
#define TRACE_FUNNEL_2     (DEBUG_APB_BASE_ADDRESS+0x5000)
#define TPIU_BASE_ADDRESS  (DEBUG_APB_BASE_ADDRESS+0x3000)
#define ETB_BASE_ADDRESS   (DEBUG_APB_BASE_ADDRESS+0x1000)
#define STP_BASE_ADDRESS   (DEBUG_APB_BASE_ADDRESS+0x9000)
#define DEM_BASEADDR                    DEM_base    // DEM (debugsys)	
#define SERDES_BASEADDR                 (DEBUG_APB_BASE_ADDRESS+0xB000)
#define CTI_0_BASE_ADDR (DEBUG_APB_BASE_ADDRESS+0x2000)
#define CTI_1_BASE_ADDR (DEBUG_APB_BASE_ADDRESS+0x6000)
#define CTI_2_BASE_ADDR (DEBUG_APB_BASE_ADDRESS+0x7000)

#if defined(MT6276) || defined(BB_MT6276)
  #if !defined(__FCORE__)
    #define DEBUG_SYS_POWER_CONTROL (CONFIG_base+0x033C)
  #else //#if !defined(__FCORE__)
    #define DEBUG_SYS_POWER_CONTROL (MD_ARM_CONFIG_base +0x033C)
  #endif  //#if !defined(__FCORE__)    
  #define SERDES_ANALOG_CLOCK_UP          (MIX_ABB_base+0x0108)
  #define SERDES_ANALOG_CLOCK_CONFIG_SEQ   (0x10)
#elif defined(MT6573) || defined(BB_MT6573) //#ifdef MT6276
  #if !defined(__FCORE__)    
    #define DEBUG_SYS_POWER_CONTROL (AP_CONFIG_base+0x6320)
  #else   //#if !defined(__FCORE__)
    #define DEBUG_SYS_POWER_CONTROL (AP_ARM_CONFIG_base+0x033C)
  #endif  //#if !defined(__FCORE__)    
  #define SERDES_ANALOG_CLOCK_UP          (MIX_ABB_base+0xE108)
  #define SERDES_ANALOG_CLOCK_CONFIG_SEQ   (0x100)  
#elif defined(TK6280) || defined(BB_TK6280) //#ifdef MT6276
   #if !defined(__FCORE__)
    #define DEBUG_SYS_POWER_CONTROL (CONFIG_base+0x033C)
  #else //#if !defined(__FCORE__)
    #define DEBUG_SYS_POWER_CONTROL (MD_ARM_CONFIG_base +0x033C)
  #endif  //#if !defined(__FCORE__)    
  #define __TST_MPX_ONLY_FOR_SDP__
  #define SERDES_ANALOG_CLOCK_UP          (0)
  #define SERDES_ANALOG_CLOCK_CONFIG_SEQ   (0) 
#elif defined(MT6280) || defined(BB_MT6280) //#ifdef MT6280
   //Note that in MT6280 there's MD and AP side
   #if !defined(__FCORE__)
    #define DEBUG_SYS_POWER_CONTROL (CONFIG_base+0xA8)
  #else //#if !defined(__FCORE__)
    #define DEBUG_SYS_POWER_CONTROL (MD_ARM_CONFIG_base+0xA8)
  #endif  //#if !defined(__FCORE__)    
    #define DEBUG_SYS_POWER_CONTROL_AP_SIDE (AP_CONFIG_base+0x08)
  #define __TST_MPX_ONLY_FOR_SDP__
  #define SERDES_ANALOG_CLOCK_UP          (0)
  #define SERDES_ANALOG_CLOCK_CONFIG_SEQ   (0)   
#else //#ifdef MT6276
  #error "Unsupported platforms. Should define Debug Sys Address"  
#endif  //#ifdef MT6276

#define ETB_CONTROL_REG    ( ETB_BASE_ADDRESS + 0x020 )
#define ETB_STATUS_REG     ( ETB_BASE_ADDRESS + 0x00C )
#define ETB_RAMDEPTH_REG   ( ETB_BASE_ADDRESS + 0x004 )
#define ETB_READDATA_REG   ( ETB_BASE_ADDRESS + 0x010 )
#define ETB_READPOS_REG    ( ETB_BASE_ADDRESS + 0x014 )
#define ETB_WRITEPOS_REG   ( ETB_BASE_ADDRESS + 0x018 )
#define ETB_WRITEDATA_REG   ( ETB_BASE_ADDRESS + 0x024 )
#define ETB_FFSR_REG		( ETB_BASE_ADDRESS + 0x300 )
#define ETB_FFCR_REG		( ETB_BASE_ADDRESS + 0x304 )
#define ETB_TRG_REG			( ETB_BASE_ADDRESS + 0x01C )

#define CORESIGHT_LOCK_AC_REG    0xFB0
#define CORESIGHT_LOCK_ST_REG    0xFB4

#define CORESIGHT_CONST_KEYLOCK  0x0
#define CORESIGHT_CONST_KEYRELE  0xC5ACCE55
#define CORESIGHT_CONST_UNLOCK   0x0
#define CORESIGHT_CONST_LOCKED   0x2
#define CORESIGHT_MASK_LOCK      0x00000002

#define FORMATTER_BYPASS_MODE 0
#define FORMATTER_NORMAL_MODE 1

//**********************************************************************************
//  STP Registers
//**********************************************************************************
	
#define STP_CONTROL_REG    ( STP_BASE_ADDRESS + 0x00 )
#define STP_LINK_COUNT     ( STP_BASE_ADDRESS + 0x04 )
#define STP_LINK_TCODE_0   ( STP_BASE_ADDRESS + 0x0C )
#define STP_LINK_TINT      ( STP_BASE_ADDRESS + 0x14 )
#define STP_FLUSHTH        ( STP_BASE_ADDRESS + 0x18 )
#define STP_PG_TEST_0      ( STP_BASE_ADDRESS + 0x40 )
#define STP_PG_TEST_1      ( STP_BASE_ADDRESS + 0x44 )
#define STP_PG_TEST_2      ( STP_BASE_ADDRESS + 0x48 )
#define STP_PG_TEST_3      ( STP_BASE_ADDRESS + 0x4C )

#define STP_SetFlushCount(count) do{*(volatile int*)STP_FLUSHTH = (count&0xFFF);}while(0)

//*********************************************************************************
//  TPIU registers
//*********************************************************************************
#define TPIU_FFCR_REG		( TPIU_BASE_ADDRESS + 0x304 )
#define TPIU_CURRENT_PORT_SIZE_REG ( TPIU_BASE_ADDRESS + 0x004)


#define PRINT_7WORD_SHORTMSG_DATA_TO_HSL(src_ary) do{\
                                                  int access_port=(LMU_AXI_BASE_ADDRESS+LMU_SHORT_DATA_REG);\
                                                  __asm\
                                                  { \
                                                    mov r0, src_ary;\
                                                    mov r1, access_port;\
                                                    ldmia R0!, {r4-r10};\
                                                    stmia r1!, {r4-r10};\
                                                  }\
                                                }while(0)
												
//*********************************************************************************
//  Trace funnel settings
//*********************************************************************************
#define TRACE_FUNNEL_1_MINIAL_HOLD_CYCLE 0xe00
#define TRACE_FUNNEL_2_MINIAL_HOLD_CYCLE 0xe00

#if defined(MT6276) || defined(BB_MT6276)
  #if defined(MT6276_S00)
    //funnel 1
    #define TF_PORT_3G 0x1
    #define TF_PORT_L2_HSUPA 0x2
    #define TF_PORT_LMU_MD_ARM  0x4
    #define TF_PORT_LMU_DPS 0x8
    #define TF_PORT_L2_HSDPA 0x20
    #define TF_PORT_2G_LOGGER 0x40
    #define TF_PORT_MM 0x80
    //funnel 2
    #define TF_PORT_TF1 0x100
    #define TF_PORT_LGA0 0x200
    #define TF_PORT_LGA1 0x400
    #define TF_PORT_DSP_HSL 0x2000
    #define TF_PORT_FLUSH 0x8000  
  #else //#if defined(MT6276_S00)
    //funnel 1
    #define TF_PORT_3G 0x1
    #define TF_PORT_L2_HSUPA 0x2    //L2 COPRO
    #define TF_PORT_LMU_MD_ARM  0x4
    #define TF_PORT_LMU_DPS 0x8
    #define TF_PORT_L2_HSDPA 0x2  //L2 COPRO
    #define TF_PORT_2G_LOGGER 0x10
    #define TF_PORT_MM 0x20    
    #define TF_PORT_DSP_HSL 0x40
    #define TF_PORT_FLUSH 0x80  
  #endif  //#if defined(MT6276_S00)
#elif defined(MT6573) || defined(BB_MT6573)  
  //funnel 1
  #define TF_PORT_3G 0x1
  #define TF_PORT_L2_HSUPA 0x2
  #define TF_PORT_LMU_AP_ARM  0x4
  #define TF_PORT_LMU_DPS 0x8
  #define TF_PORT_LMU_MD_ARM  0x10
  #define TF_PORT_L2_HSDPA 0x20
  #define TF_PORT_2G_LOGGER 0x40
  #define TF_PORT_MM 0x80
  //funnel 2
  #define TF_PORT_TF1 0x100
  #define TF_PORT_LGA0 0x200
  #define TF_PORT_LGA1 0x400
  #define TF_PORT_ARM_ETM 0x800
  #define TF_PORT_DSP_HSL 0x2000
  #define TF_PORT_FLUSH 0x8000  
  
#elif defined(TK6280) || defined(BB_TK6280) || defined(MT6280) || defined(BB_MT6280) 
    //Only funnel 1
    #define TF_PORT_LMU_MD_ARM  0x4
	#define TF_PORT_LMU_DPS 0x8	
    #define TF_PORT_FLUSH 0x80    	
#else	//#if defined(MT6276)
	#error "Please define trace funnel definitions."
#endif	//#if defined(MT6276)

//debug sys general controls
#define DEM_AHBAP_EN                (DEM_BASEADDR+0x0040)
#define DEM_APBAP_EN                (DEM_BASEADDR+0x0044)
#define DEM_AHBAP_EN_LOCK           (DEM_BASEADDR+0x0048)
#define DEM_APBAP_EN_LOCK           (DEM_BASEADDR+0x004C)

#define AHBAP_EN                    0x00000001
#define APBAP_EN                    0x00000001
#define AHBAP_EN_LOCK               0x00000001
#define APBAP_EN_LOCK               0x00000001	

//Common utilities
#if !defined(SYS_SYNC)
  #ifdef __TST_ON_AOS__
    #define SYS_SYNC() asm volatile("ssync;")
  #else //#ifdef __TST_ON_AOS__    
    #define SYS_SYNC()
  #endif  //#ifdef __TST_ON_AOS__
#endif  //#if !defined(SYS_SYNC)


//*********************************************************************************
//  Serdes settings
//*********************************************************************************
#if defined(MT6280) || defined(BB_MT6280) //MT6280 implements new SDP macro
	#define SERDES_REG_ANA_CTRL      (SERDES_BASEADDR)
	#define SERDES_REG_TXVCO_CTRL0   (SERDES_BASEADDR+0x04)	
	#define SERDES_REG_TXVCO_CTRL1   (SERDES_BASEADDR+0x08)	
	#define SERDES_REG_TXVCO_PWD     (SERDES_BASEADDR+0x0C)	
	#define SERDES_REG_CPLL_CTRL     (SERDES_BASEADDR+0x10)
	#define SERDES_REG_BIAS_IMP_CTRL (SERDES_BASEADDR+0x50)	
	#define SERDES_REG_TXPLL_CTRL    (SERDES_BASEADDR+0x54)
	#define SERDES_REG_TXFBDIV_CTRL  (SERDES_BASEADDR+0x58)
	#define SERDES_REG_DSS_CTRL      (SERDES_BASEADDR+0x5C)
	#define SERDES_REG_TXVCOCAL_CTRL (SERDES_BASEADDR+0x74)
	#define SERDES_LOCK_ACCESS 		 (SERDES_BASEADDR+0xFB0)
	#define SERDES_LOCK_STATUS 		 (SERDES_BASEADDR+0xFB4)	
	#define SERDES_REG_TST_CTRL1 (SERDES_BASEADDR+0x20)
	#define SERDES_REG_TST_CTRL2 (SERDES_BASEADDR+0x24)	
	#define SERDES_REG_TST_CTRL0 (SERDES_BASEADDR+0x1c)
	#define SERDES_REG_SERDES_BIST (SERDES_BASEADDR+0x18)
#else
	#define SERDES_REG_ANA_CTRL (SERDES_BASEADDR)
	#define SERDES_REG_TXVCO_CTRL0 (SERDES_BASEADDR+0x4)
	#define SERDES_REG_TXVCO_CTRL1 (SERDES_BASEADDR+0x8)
	#define SERDES_REG_TXVCO_PWD (SERDES_BASEADDR+0xc)
	#define SERDES_REG_CPLL_CTRL (SERDES_BASEADDR+0x10)
	#define SERDES_REG_TXVCOSTA (SERDES_BASEADDR+0x14)
	#define SERDES_REG_SERDES_BIST (SERDES_BASEADDR+0x18)
	#define SERDES_REG_TST_CTRL0 (SERDES_BASEADDR+0x1c)
	#define SERDES_REG_TST_CTRL1 (SERDES_BASEADDR+0x20)
	#define SERDES_REG_TST_CTRL2 (SERDES_BASEADDR+0x24)
	#define SERDES_REG_RW_DMY_REG (SERDES_BASEADDR+0x28)
	#define SERDES_REG_RO_DMY_REG (SERDES_BASEADDR+0x2C)
	#define SERDES_REG_SDW_CK_DIV2 (SERDES_BASEADDR+0x3C)
	#if defined(MT6276_S00)
		  #define SERDES_LOCK_ACCESS (SERDES_BASEADDR+0xF8)
		  #define SERDES_LOCK_STATUS (SERDES_BASEADDR+0xFC)
	#else  //#if defined(MT6276_S00)
		  #define SERDES_LOCK_ACCESS (SERDES_BASEADDR+0xFB0)
		  #define SERDES_LOCK_STATUS (SERDES_BASEADDR+0xFB4)
	#endif  //#if defined(MT6276_S00)
#endif

#define SERDES_PLL_CLOCK_301_6M (5)
#define SERDES_PLL_CLOCK_291_2M (4)
#define SERDES_PLL_CLOCK_280_8M (3)
#define SERDES_PLL_CLOCK_270_4M (2)
#define SERDES_PLL_CLOCK_260_0M (1)
#define SERDES_PLL_CLOCK_249_6M (0)
#define SERDES_MAX_AMP_LEVEL (16)
#define SERDES_MAX_SLEW_LEVEL (4)

#define SERDES_BIST_PRBS (0)
#define SERDES_BIST_HFTP (5)  //0101

#define Serdes_Set_Slew_Rate(rate) do{*(volatile int*)SERDES_REG_TXVCO_CTRL1 &= 0xFFFFE7FF; *(volatile int*)SERDES_REG_TXVCO_CTRL1 |= ((rate&3)<<11);}while(0)
#define Serdes_Set_PLL(clock_rate) do{*(volatile int*)SERDES_REG_TXVCO_CTRL0 &= 0xFFE3FFFF; *(volatile int*)SERDES_REG_TXVCO_CTRL0 |= ((clock_rate)<<18);}while(0)
#define Serdea_Set_Amp(amp) do{*(volatile int*)SERDES_REG_TXVCO_CTRL1&= 0xFFFFFFF0; *(volatile int*)SERDES_REG_TXVCO_CTRL1 |= (amp&0xF);}while(0)
#define Serdes_Set_TEST_PATTERN(pattern) do{\
                                            *(volatile int*)SERDES_REG_TST_CTRL2 &= ~(1<<16);\
                                            *(volatile int*)SERDES_REG_SERDES_BIST |= (1<<4);\
											*(volatile int*)SERDES_REG_SERDES_BIST &= 0xFFFFFFF0;\
                                            *(volatile int*)SERDES_REG_SERDES_BIST |= (pattern&0xF);\
                                           }while(0)



//*********************************************************************************
//  ATID settings
//*********************************************************************************
#if defined(MT6276) || defined(BB_MT6276) || defined(MT6573) || defined(BB_MT6573) || defined(TK6280) || defined(BB_TK6280) || defined(MT6280) || defined(BB_MT6280)
  #define ATID_LMU_MDARM                (0x10)
  #define ATID_LMU_FCore4               (0x11)
  #define ATID_LMU_APARM                (0x12)
  #define ATID_LogAcc0                  (0x18)
  #define ATID_LogAcc1                  (0x19)
  #define ATID_Flush_Master             (0x1F)
  #define ATID_2G_Modem_RXBUF           (0x20)
  #define ATID_2G_Modem_EQRAM1          (0x21)
  #define ATID_2G_Modem_EQRAM2          (0x22)
  #define ATID_3G_Modem_MODEM0          (0x30)
  #define ATID_3G_Modem_MODEM1          (0x31)
  #define ATID_3G_Modem_EXTRT           (0x32)
  #define ATID_3G_Modem_SCALER          (0x33)
  #define ATID_L2Copro_DPA_MAC          (0x40)
  #define ATID_L2Copro_DPA_RLC_IM       (0x41)
  #define ATID_L2Copro_DPA_RLC_RO       (0x42)
  #define ATID_L2Copro_DPA_RLC_CTRL     (0x43)
  #define ATID_L2Copro_DPA_RLC_SDU      (0x44)
  #define ATID_L2Copro_UPA_MAC          (0x45)
  #define ATID_L2Copro_UPA_RLC          (0x46)
  //For L2Copro E2
  #define ATID_L2Copro_DPA_RLC_DROP     (0x47)
  #define ATID_L2Copro_DPA_MAC_HS       ATID_L2Copro_DPA_MAC
  #define ATID_L2Copro_DPA_MAC_HS_DROP  (0x48)
  #define ATID_L2Copro_DPA_MAC_D        (0x49)
  #define ATID_L2Copro_DPA_MAC_D_DROP   (0x4A)
  #define ATID_L2Copro_DPA_TS           (0x4B)
  #define ATID_L2Copro_UPA_RLC_AMD      ATID_L2Copro_UPA_RLC
  #define ATID_L2Copro_UPA_RLC_UMD      (0x4C)
  #define ATID_L2Copro_UPA_MAC_SAD      (0x4D)
  #define ATID_L2Copro_UPA_TS           (0x4E)
  #define ATID_ETM_MDARM                (0x50)
  #define ATID_FCore4_HSL_PC            (0x51)
  #define ATID_ETM_APARM                (0x52)
  #define ATID_FCore4_HSL_DATA          (0x53)
  #define ATID_MMSYS                    (0x60)
#else //#if defined(MT6276) || defined(BB_MT6276) || defined(MT6573) || defined(BB_MT6573) || defined(TK6280) || defined(BB_TK6280) || defined(MT6280) || defined(BB_MT6280)
  #error "Please define proper ATID for this platforms"
#endif  //#if defined(MT6276) || defined(BB_MT6276) || defined(MT6573) || defined(BB_MT6573) || defined(TK6280) || defined(BB_TK6280) || defined(MT6280) || defined(BB_MT6280)


//*********************************************************************************
//  CTI settings
//*********************************************************************************
#define CTI_CONTROL_OFFSET           0x0000
#define CTI_IN_EN_7_OFFSET           0x003C
#define CTI_OUT_EN_2_OFFSET          0x00A8

//*********************************************************************************
//  Function declaration
//*********************************************************************************
void CoreSight_Enable_LMU_ACCESS(void);
int STP_Configuration(void);
int CoreSight_TPIU_SW_Configure(void);
void CoreSight_Set_TraceFunnel(unsigned int settings);

int MISC_CoreSight_Module_Unlock_By_Addr(unsigned int lock_access_addr, unsigned int lock_status_addr);
int MISC_CoreSight_Module_Unlock_By_Addr(unsigned int lock_access_addr, unsigned int lock_status_addr);
int MISC_CoreSight_Module_Lock(unsigned int addr);
int MISC_CoreSight_Module_Unlock(unsigned int addr);

#endif  //__TST_CORESIGHT_CONTROL_H__
#endif  //#if defined(__TST_DNT_LOGGING__) || defined(USE_DNT_LOGGING) 
