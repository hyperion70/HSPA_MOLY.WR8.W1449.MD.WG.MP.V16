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
 * MalmoDriver.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file defines Malmo drivers interface
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __TST_MALMO_SUPPORT__

#ifndef __MALMODRIVER_H__
#define __MALMODRIVER_H__

#include "kal_general_types.h"
#include "reg_base.h"  

//MALMO ASM Related Definition
#if defined(MT6280_S00)

    #define MALLMO_ASM_MONITOR_FILTER_WIDTH (16) //By chip
    #define MALMO_ASM_EXTRA_INFO_NUM (4) //By chip

    #define MALMO_ASM_ERR_CODE_ERROR (0)
    #define MALMO_ASM_ERR_CODE_NO_ERROR (1)

    typedef enum {
	MALMO_ASM_MCU_PC, 
	MALMO_ASM_CONTEXT_ID, 
	MALMO_ASM_PMC0, 
	MALMO_ASM_PMC1, 
	MALMO_ASM_PMC2,
	MALMO_ASM_CYCLE_CNT, 
	MALMO_ASM_EMI_BCNT, 
	MALMO_ASM_EMI_BACT, 
	MALMO_ASM_EMI_BSCT, 
	MALMO_ASM_EMI_BSCT2,
	MALMO_ASM_EMI_BSCT3, 
	MALMO_ASM_TIMESTAMP, 

	MALMO_ASM_EXTRA_BASE = 0x1000,
	MALMO_ASM_EXTRA0, 
	MALMO_ASM_EXTRA1, 
	MALMO_ASM_EXTRA2,
	MALMO_ASM_EXTRA3
    } MALMO_ASM_MONITORED_REGISTERS;
#else
    #define MALLMO_ASM_MONITOR_FILTER_WIDTH (16+8) //By chip
    #define MALMO_ASM_EXTRA_INFO_NUM (4+8) //By chip

    #define MALMO_ASM_ERR_CODE_ERROR (0)
    #define MALMO_ASM_ERR_CODE_NO_ERROR (1)

    typedef enum {
	MALMO_ASM_MCU_PC, 
	MALMO_ASM_CONTEXT_ID, 
	MALMO_ASM_PMC0, 
	MALMO_ASM_PMC1, 
	MALMO_ASM_PMC2,
	MALMO_ASM_CYCLE_CNT, 
	MALMO_ASM_EMI_BCNT, 
	MALMO_ASM_EMI_BACT, 
	MALMO_ASM_EMI_BSCT, 
	MALMO_ASM_EMI_BSCT2,
	MALMO_ASM_EMI_BSCT3, 
	MALMO_ASM_TIMESTAMP, 

	MALMO_ASM_EXTRA_BASE = 0x1000,
	MALMO_ASM_EXTRA0, 
	MALMO_ASM_EXTRA1, 
	MALMO_ASM_EXTRA2,
	MALMO_ASM_EXTRA3,
	MALMO_ASM_EXTRA4, 
	MALMO_ASM_EXTRA5, 
	MALMO_ASM_EXTRA6,
	MALMO_ASM_EXTRA7,	
	MALMO_ASM_EXTRA8, 
	MALMO_ASM_EXTRA9, 
	MALMO_ASM_EXTRA10,
	MALMO_ASM_EXTRA11		
    } MALMO_ASM_MONITORED_REGISTERS;
#endif  //#if defined(MT6280_S00) || defined(BB_MT6280_S00)

////////////////////////////////////////////////////////////
// MALMO: Chip Dependent Configuration
////////////////////////////////////////////////////////////
#if defined(MT6280)
	// ***Chip Dependent***
	//Be sure to enable ALC, ASM and ADOE clock before accessing them!!!
	#define MALMO_CLOCK_GATING_CONTROL       (CONFIG_base+0xA8)
	#define MALMO_CLOCK_GATING_ENABLE_CODE   (0x000001C0)
		
	#define MALMO_ALC_BUS_WAY_ENABLE_CONTROL (CONFIG_base+0x40)
	#define MALMO_ALC_BUS_WAY_ENABLE_CODE    (0x00004000)
		
    #define ALC_BASEADDR                (ALC_base)
    #define ADOE_BASEADDR               (ADOE_base)  
    #define ASM_BASEADDR                (ASM_base)  	
#else //#if defined(MT6280)
    #error "MALMO unsupported platforms!"  
#endif  //#if defined(MT6280)

////////////////////////////////////////////////////////////

#define MALMO_LOGGING_CHANNEL_ASM    (0)
#define MALMO_LOGGING_CHANNEL_ALC_L1 (1)
#define MALMO_LOGGING_CHANNEL_ALC_PS (2)

////////////////////////////////////////////////////////////
// MALMO: ALC Definition
////////////////////////////////////////////////////////////

//////////////////ALC Registers/////////////////////////////
//ALC Port
#define ALC_CTRL_BSADDR   ( ALC_BASEADDR + 0x0000 )
#define ALC_CSM_BSADDR    ( ALC_BASEADDR + 0x0100 )
#define ALC_REQ_BSADDR    ( ALC_BASEADDR + 0x0200 )
#define ALC_DATA_BSADDR   ( ALC_BASEADDR + 0x0300 )
#define ALC_FIN_BSADDR    ( ALC_BASEADDR + 0x0400 )
#define ALC_BMGR_PROBLEM_BSADDR   ( ALC_BASEADDR + 0x0500 )

//Normal Function Registers
#define ALC_GENERAL_CON     ( ALC_CTRL_BSADDR + 0x00 )
#define ALC_FEATURE_CONTROL ( ALC_CTRL_BSADDR + 0x04 )	
#define ALC_LOGGING_BUF0_BSAD ( ALC_CTRL_BSADDR + 0x08 )
#define ALC_LOGGING_BUF1_BSAD ( ALC_CTRL_BSADDR + 0x0C )
#define ALC_LOGGING_BUF0_SIZE ( ALC_CTRL_BSADDR + 0x10 )
#define ALC_LOGGING_BUF1_SIZE ( ALC_CTRL_BSADDR + 0x14 )
#define ALC_PDI_PATTERN0_BUF0 ( ALC_CTRL_BSADDR + 0x18 )
#define ALC_PDI_PATTERN1_BUF0 ( ALC_CTRL_BSADDR + 0x1C )
#define ALC_PDI_PATTERN0_BUF1 ( ALC_CTRL_BSADDR + 0x20 )
#define ALC_PDI_PATTERN1_BUF1 ( ALC_CTRL_BSADDR + 0x24 )
#define ALC_GROUP_BUL_ACTIVATION_TH_BUF0 ( ALC_CTRL_BSADDR + 0x28 )
#define ALC_GROUP_BUL_ACTIVATION_TH_BUF1 ( ALC_CTRL_BSADDR + 0x2C )
#define ALC_GROUP_BUL_THRESHOLD_G0_BUF0 ( ALC_CTRL_BSADDR + 0x30 )
#define ALC_GROUP_BUL_THRESHOLD_G1_BUF0 ( ALC_CTRL_BSADDR + 0x34 )
#define ALC_GROUP_BUL_THRESHOLD_G2_BUF0 ( ALC_CTRL_BSADDR + 0x38 )
#define ALC_GROUP_BUL_THRESHOLD_G3_BUF0 ( ALC_CTRL_BSADDR + 0x3C )
#define ALC_GROUP_BUL_THRESHOLD_G0_BUF1 ( ALC_CTRL_BSADDR + 0x40 )
#define ALC_GROUP_BUL_THRESHOLD_G1_BUF1 ( ALC_CTRL_BSADDR + 0x44 )
#define ALC_GROUP_BUL_THRESHOLD_G2_BUF1 ( ALC_CTRL_BSADDR + 0x48 )
#define ALC_GROUP_BUL_THRESHOLD_G3_BUF1	( ALC_CTRL_BSADDR + 0x4C ) 
	
//Special Function Registers
#define ALC_CURRENT_CSM ( ALC_CTRL_BSADDR + 0xE0 )
#define ALC_CURRENT_LEFT_LENGTH ( ALC_CTRL_BSADDR + 0xE4 )
	#define ALC_CURRENT_TYPER_OFFSET (24)
	
#define ALC_SW_MANUAL_FLUSH_CSM ( ALC_CTRL_BSADDR + 0xE8 )
#define ALC_SW_MANUAL_FLUSH_VALID ( ALC_CTRL_BSADDR + 0xEC )
#define ALC_DMA_HANDLING ( ALC_CTRL_BSADDR + 0xF0 )
	#define ALC_DMA_DROP_INDICATOR_OFFSET (31)
	#define ALC_DMA_PDI_INDICATOR_OFFSET (30)

//Packet Drop Related
#define	ALC_PDI_BUF0 ( ALC_CTRL_BSADDR + 0xA4 )
#define	ALC_PDI_BUF1 ( ALC_CTRL_BSADDR + 0xA8 )
	#define GP3_PD_OFFSET (19)
	#define GP2_PD_OFFSET (18)
	#define GP1_PD_OFFSET (17)
	#define GP0_PD_OFFSET (16)	
	
#define ALC_PDI_AMOUNT_BUF0 ( ALC_CTRL_BSADDR + 0xAC )
#define ALC_PDI_AMOUNT_BUF1 ( ALC_CTRL_BSADDR + 0xB0 )

//Debugging Function Registers
#define ALC_MAX_LIT_RECORDS_NUM ( ALC_CTRL_BSADDR + 0x80 )
#define	ALC_LAST_CSM ( ALC_CTRL_BSADDR + 0x84 )
#define	ALC_CURRENT_DATA ( ALC_CTRL_BSADDR + 0x88 )
#define	ALC_RSTART_PTR_BUF0 ( ALC_CTRL_BSADDR + 0x8C )
#define	ALC_RSTART_PTR_BUF1 ( ALC_CTRL_BSADDR + 0x90 )
#define	ALC_REND_PTR_BUF0 ( ALC_CTRL_BSADDR + 0x94 )
#define	ALC_REND_PTR_BUF1 ( ALC_CTRL_BSADDR + 0x98 )
#define	ALC_CURRENT_WRITE_PTR_BUF0 ( ALC_CTRL_BSADDR + 0x9C )
#define	ALC_CURRENT_WRITE_PTR_BUF1 ( ALC_CTRL_BSADDR + 0xA0 )

#define ALC_MISC_ERR ( ALC_CTRL_BSADDR + 0xB4 )
	#define ALC_MISC_ERR_LIT_FULL_VALUE (1<<5)
	
#define ALC_DBG_STATES ( ALC_CTRL_BSADDR + 0xB8 )
	
#define ALC_DBG_BUL_BUF0 ( ALC_CTRL_BSADDR + 0xBC )
#define ALC_DBG_BUL_BUF1 ( ALC_CTRL_BSADDR + 0xC0 )
	#define ALC_DBG_BUL_BUF_ACTIVATED_VALUE  (1<<16)
	#define ALC_DBG_BUL_GP3_OVER_LIMIT_VALUE (1<<12)
	#define ALC_DBG_BUL_GP2_OVER_LIMIT_VALUE (1<<8)
	#define ALC_DBG_BUL_GP1_OVER_LIMIT_VALUE (1<<4)
	#define ALC_DBG_BUL_GP0_OVER_LIMIT_VALUE (1<<0)	
	
#define ALC_DBG_SPACE_LEFT_BUF0 ( ALC_CTRL_BSADDR + 0xC4 )
#define ALC_DBG_SPACE_LEFT_BUF1 ( ALC_CTRL_BSADDR + 0xC8 )
#define ALC_DBG_CUR_REQ  ( ALC_CTRL_BSADDR + 0xCC )

/////////////////////////////////////////////////////
#define ALC_TYPE_L1 (0)
#define ALC_TYPE_PS (1)
#define ALC_GROUP_0 (0)
#define ALC_GROUP_1 (1)
#define ALC_GROUP_2 (2)
#define ALC_GROUP_3 (3)


#define ALC_PDI_PATTERN0_L1 (0xAA000CA6)
#define ALC_PDI_PATTERN1_L1 (0x0000C0F9)

#define ALC_PDI_PATTERN0_PS (0x00000859)
#define ALC_PDI_PATTERN1_PS (0x91C00000)

//////////////////ALC Utility Macro///////////////////


#ifndef __TST_ON_AOS_PC__
#define ALC_SEND_CSM(CSM) do{ \
			*((volatile unsigned int*) (ALC_CSM_BSADDR)) = (CSM) ;\
		}while(0)	
				
#define ALC_SEND_REQUEST_CHECKED(TYPE, GROUP, LENGTH) do{ \
			*((volatile unsigned int*) (ALC_REQ_BSADDR)) = ( ((GROUP)&0x00000003) + (((TYPE)&0x00000001)<<3) + (((LENGTH)&0x007FFFFF)<<8)) ;\
		}while(0)
#else //#ifndef __TST_ON_AOS_PC__
  #define ALC_SEND_CSM(CSM) do{alc_sim_write_csm(CSM);}while(0)
  #define ALC_SEND_REQUEST_CHECKED(TYPE, GROUP, LENGTH) do{alc_sim_req_space(TYPE, GROUP, LENGTH);}while(0)
#endif  //#ifndef __TST_ON_AOS_PC__		

#define ALC_SEND_REQUEST_CHECKED_RETURN(TYPE, GROUP, LENGTH, REQ) do{ \
			REQ = ( ((GROUP)&0x00000003) + (((TYPE)&0x00000001)<<3) + (((LENGTH)&0x007FFFFF)<<8)) ;\
			*((volatile unsigned int*) (ALC_REQ_BSADDR)) = REQ ;\
		}while(0)
		
#define ALC_SEND_REQUEST(TYPE, GROUP, LENGTH) do{ \
			*((volatile unsigned int*) (ALC_REQ_BSADDR)) = ( (GROUP) + ((TYPE)<<3) + ((LENGTH)<<8)) ;\
		}while(0)

#ifndef __TST_ON_AOS_PC__
  #define ALC_SEND_DATA(DATA) do{ \
			*((volatile unsigned int*) (ALC_DATA_BSADDR)) = (DATA) ;\
		}while(0)
#else //#ifndef __TST_ON_AOS_PC__
  #define ALC_SEND_DATA(DATA) do{ alc_sim_write_data(DATA);}while(0)
#endif  //#ifndef __TST_ON_AOS_PC__		

//Need to poll BMGR_STATE before sending any FIN
#define ALC_POLL_BMGR_BUSY do{ \
			while( (*((volatile unsigned int*) (ALC_DBG_STATES)) & 0xF) != 0x0 ){};\
		}while(0)
		
#define ALC_SEND_FINISH(CSM) do{ \
			while( (*((volatile unsigned int*) (ALC_DBG_STATES)) & 0xF) != 0x0 ){};\
			*((volatile unsigned int*) (ALC_FIN_BSADDR)) = (CSM) ;\
		}while(0)
		
#define ALC_SEND_FINISH_UNCHECKED(CSM) do{ \
			*((volatile unsigned int*) (ALC_FIN_BSADDR)) = (CSM) ;\
		}while(0)


//ALC_PWR
#define ALC_POWER_UP do{ \
			*((volatile unsigned int*) (ALC_GENERAL_CON)) |= (1) ;\
		}while(0)

#define ALC_POWER_DOWN do{ \
			*((volatile unsigned int*) (ALC_GENERAL_CON)) &= (0xFFFFFFF0) ;\
		}while(0)

//ALC_EN
#define ALC_ENABLE do{ \
			*((volatile unsigned int*) (ALC_GENERAL_CON)) |= (0x10) ;\
		}while(0)

#define ALC_DISABLE do{ \
			*((volatile unsigned int*) (ALC_GENERAL_CON)) &= (0xFFFFFF0F) ;\
		}while(0)

//Do NOT use ALC_RESET alone if you understand what it will happen!
#define ALC_RESET do{ \
			*((volatile unsigned int*) (ALC_GENERAL_CON)) |= (0x100);\
		}while(0)

#define ALC_POLL_BUSY do{ \
			while( (*((volatile unsigned int*) (ALC_GENERAL_CON)) & 0x1000) == 0x1000 ){};\
		}while(0)

//ALC_FEATURE_CONTROL
#define ALC_ACC_ENABLE do{ \
			*((volatile unsigned int*) (ALC_FEATURE_CONTROL)) |= (0x1) ;\
		}while(0)
		
#define ALC_ACC_DISABLE do{ \
			*((volatile unsigned int*) (ALC_FEATURE_CONTROL)) &= (0xFFFFFFF0) ;\
		}while(0)

#define ALC_APDI_ENABLE do{ \
			*((volatile unsigned int*) (ALC_FEATURE_CONTROL)) |= (0x10) ;\
		}while(0)
		
#define ALC_APDI_DISABLE do{ \
			*((volatile unsigned int*) (ALC_FEATURE_CONTROL)) &= (0xFFFFFF0F) ;\
		}while(0)
			
#define ALC_GROUP_BUL_BUF0_ENABLE do{ \
			*((volatile unsigned int*) (ALC_FEATURE_CONTROL)) |= (0x100) ;\
		}while(0)
			
#define ALC_GROUP_BUL_BUF0_DISABLE do{ \
			*((volatile unsigned int*) (ALC_FEATURE_CONTROL)) &= (0xFFFFF0FF) ;\
		}while(0)
		
#define ALC_GROUP_BUL_BUF1_ENABLE do{ \
			*((volatile unsigned int*) (ALC_FEATURE_CONTROL)) |= (0x1000) ;\
		}while(0)
				
#define ALC_GROUP_BUL_BUF1_DISABLE do{ \
			*((volatile unsigned int*) (ALC_FEATURE_CONTROL)) &= (0xFFFF0FFF) ;\
		}while(0)
		
#define ALC_SET_EXTRA_WAIT_WORKAROUND_DISABLE do{ \
			*((volatile unsigned int*) (ALC_FEATURE_CONTROL)) |= (0x80000000) ;\
		}while(0)
		
//ALC Set MACRO
#define ALC_SET_LOGGING_BUF0_BSAD(BSAD) do{ \
			*(volatile unsigned int*) (ALC_LOGGING_BUF0_BSAD) = (BSAD) ;\
		}while(0)
		
#define ALC_SET_LOGGING_BUF1_BSAD(BSAD) do{ \
			*(volatile unsigned int*) (ALC_LOGGING_BUF1_BSAD) = (BSAD) ;\
		}while(0)	

#define ALC_SET_LOGGING_BUF0_SIZE(SIZE) do{ \
			*(volatile unsigned int*) (ALC_LOGGING_BUF0_SIZE) = (SIZE) ;\
		}while(0)
		
#define ALC_SET_LOGGING_BUF1_SIZE(SIZE) do{ \
			*(volatile unsigned int*) (ALC_LOGGING_BUF1_SIZE) = (SIZE) ;\
		}while(0)		

#define ALC_SET_GROUP_BUL_ACT_TH_BUF1(ACT_TH) do{ \
			*(volatile unsigned int*) (ALC_GROUP_BUL_ACTIVATION_TH_BUF1) = (ACT_TH) ;\
		}while(0)
				
#define ALC_SET_GROUP_BUL_ACT_TH_BUF0(ACT_TH) do{ \
			*(volatile unsigned int*) (ALC_GROUP_BUL_ACTIVATION_TH_BUF0) = (ACT_TH) ;\
		}while(0)
		
#define ALC_SET_GROUP_BUL_ACT_TH_BUF1(ACT_TH) do{ \
			*(volatile unsigned int*) (ALC_GROUP_BUL_ACTIVATION_TH_BUF1) = (ACT_TH) ;\
		}while(0)
		
#define ALC_SET_GROUP_BUL_TH_GP0_BUF0(BUL_TH) do{ \
			*(volatile unsigned int*) (ALC_GROUP_BUL_THRESHOLD_G0_BUF0) = (BUL_TH) ;\
		}while(0)
			
#define ALC_SET_GROUP_BUL_TH_GP1_BUF0(BUL_TH) do{ \
			*(volatile unsigned int*) (ALC_GROUP_BUL_THRESHOLD_G1_BUF0) = (BUL_TH) ;\
		}while(0)

#define ALC_SET_GROUP_BUL_TH_GP2_BUF0(BUL_TH) do{ \
			*(volatile unsigned int*) (ALC_GROUP_BUL_THRESHOLD_G2_BUF0) = (BUL_TH) ;\
		}while(0)
		
#define ALC_SET_GROUP_BUL_TH_GP3_BUF0(BUL_TH) do{ \
			*(volatile unsigned int*) (ALC_GROUP_BUL_THRESHOLD_G3_BUF0) = (BUL_TH) ;\
		}while(0)

#define ALC_SET_GROUP_BUL_TH_GP0_BUF1(BUL_TH) do{ \
			*(volatile unsigned int*) (ALC_GROUP_BUL_THRESHOLD_G0_BUF1) = (BUL_TH) ;\
		}while(0)
			
#define ALC_SET_GROUP_BUL_TH_GP1_BUF1(BUL_TH) do{ \
			*(volatile unsigned int*) (ALC_GROUP_BUL_THRESHOLD_G1_BUF1) = (BUL_TH) ;\
		}while(0)

#define ALC_SET_GROUP_BUL_TH_GP2_BUF1(BUL_TH) do{ \
			*(volatile unsigned int*) (ALC_GROUP_BUL_THRESHOLD_G2_BUF1) = (BUL_TH) ;\
		}while(0)
		
#define ALC_SET_GROUP_BUL_TH_GP3_BUF1(BUL_TH) do{ \
			*(volatile unsigned int*) (ALC_GROUP_BUL_THRESHOLD_G3_BUF1) = (BUL_TH) ;\
		}while(0)
		
#define ALC_SET_MAX_LIT_RECORDS_NUM_TO_0 do{ \
			*(volatile unsigned int*) (ALC_MAX_LIT_RECORDS_NUM) = 1 ;\
		}while(0)

//ALC SPECIAL&DEBUGGING MACRO

//ALC DMA PATH///////////////////
#define ALC_GET_CURRENT_CSM(CURRENT_CSM) do{ \
			CURRENT_CSM = *(volatile unsigned int*) (ALC_CURRENT_CSM) ;\
		}while(0)
			
#define ALC_GET_CURRENT_LEFT_LENGTH_AND_TYPE(LEFT_LENGTH, TYPE) do{ \
			LEFT_LENGTH = ( *(volatile unsigned int*) (ALC_CURRENT_LEFT_LENGTH) )&0x007FFFFF ;\
			TYPE = ( ( *(volatile unsigned int*) (ALC_CURRENT_LEFT_LENGTH) ) >> ALC_CURRENT_TYPER_OFFSET ) &0x1 ;\
		}while(0)

#ifndef __TST_ON_AOS_PC__		
//1: Drop, 0: Accept
  #define ALC_GET_DROP_INFO(PKT_DROP_INFO) do{ \
			PKT_DROP_INFO = (( *(volatile unsigned int*) (ALC_DMA_HANDLING) ) >> ALC_DMA_DROP_INDICATOR_OFFSET)&0x1;\
		}while(0)		
#else
  #define ALC_GET_DROP_INFO(PKT_DROP_INFO) do{ PKT_DROP_INFO = alc_sim_get_drop_info();}while(0)
#endif
		
#define ALC_GET_DMA_INFO(DROP_INDICATOR, PDI_INDICATOR, CURRENT_WS_PTR) do{ \
			DROP_INDICATOR = (( *(volatile unsigned int*) (ALC_DMA_HANDLING) ) >> ALC_DMA_DROP_INDICATOR_OFFSET)&0x1;\
			PDI_INDICATOR = (( *(volatile unsigned int*) (ALC_DMA_HANDLING) ) >> ALC_DMA_PDI_INDICATOR_OFFSET)&0x1;\
			CURRENT_WS_PTR = (( *(volatile unsigned int*) (ALC_DMA_HANDLING) ) )&0x007FFFFF;\
		}while(0)
		
#define ALC_GET_CURRENT_WRITE_PTR_BUF0(PTR) do{ \
			PTR = *(volatile unsigned int*) (ALC_CURRENT_WRITE_PTR_BUF0) ;\
		}while(0)
		
#define ALC_GET_CURRENT_WRITE_PTR_BUF1(PTR) do{ \
			PTR = *(volatile unsigned int*) (ALC_CURRENT_WRITE_PTR_BUF1) ;\
		}while(0)	
		
//SW MANUAL FLUSH///////////////////		
#define ALC_GET_SW_MANUAL_FLUSH_VALID(VALID) do{ \
			VALID = ( *(volatile unsigned int*) (ALC_SW_MANUAL_FLUSH_VALID) )&0x1;\
		}while(0)

#define ALC_GET_SW_MANUAL_FLUSH_CSM(CSM) do{ \
			CSM =  *(volatile unsigned int*) (ALC_SW_MANUAL_FLUSH_CSM)  ;\
		}while(0)

//DEBUGGING///////////////////		
#define ALC_GET_MAX_LIT_RECORDS_NUM(NUM) do{ \
			NUM =  *(volatile unsigned int*) (ALC_MAX_LIT_RECORDS_NUM) ;\
		}while(0)
		
#define ALC_GET_LAST_CSM(LAST_CSM) do{ \
			LAST_CSM = *(volatile unsigned int*) (ALC_LAST_CSM) ;\
		}while(0)	
			
#define ALC_GET_CURRENT_DATA(CURRENT_DATA) do{ \
			CURRENT_DATA = *(volatile unsigned int*) (ALC_CURRENT_DATA) ;\
		}while(0)	

//PDI///////////////////
#define ALC_GET_PDI_BUF0( GP3, GP2, GP1, GP0, NUM ) do{ \
			GP3 = (( *(volatile unsigned int*) (ALC_PDI_BUF0) ) >> GP3_PD_OFFSET )&0x1;\
			GP2 = (( *(volatile unsigned int*) (ALC_PDI_BUF0) ) >> GP2_PD_OFFSET )&0x1;\
			GP1 = (( *(volatile unsigned int*) (ALC_PDI_BUF0) ) >> GP1_PD_OFFSET )&0x1;\
			GP0 = (( *(volatile unsigned int*) (ALC_PDI_BUF0) ) >> GP0_PD_OFFSET )&0x1;\
			NUM =  ( *(volatile unsigned int*) (ALC_PDI_BUF0) ) &0x0000FFFF ;\
		}while(0)

#define ALC_GET_PDI_BUF1( GP3, GP2, GP1, GP0, NUM ) do{ \
			GP3 = (( *(volatile unsigned int*) (ALC_PDI_BUF1) ) >> GP3_PD_OFFSET )&0x1;\
			GP2 = (( *(volatile unsigned int*) (ALC_PDI_BUF1) ) >> GP2_PD_OFFSET )&0x1;\
			GP1 = (( *(volatile unsigned int*) (ALC_PDI_BUF1) ) >> GP1_PD_OFFSET )&0x1;\
			GP0 = (( *(volatile unsigned int*) (ALC_PDI_BUF1) ) >> GP0_PD_OFFSET )&0x1;\
			NUM =  ( *(volatile unsigned int*) (ALC_PDI_BUF1) ) &0x0000FFFF ;\
		}while(0)
		
#define ALC_GET_PDI_ORI_BUF0( PDI ) do{ \
			PDI =  *(volatile unsigned int*) (ALC_PDI_BUF0) ;\
		}while(0)

#define ALC_GET_PDI_ORI_BUF1( PDI ) do{ \
			PDI =  *(volatile unsigned int*) (ALC_PDI_BUF1) ;\
		}while(0)


#define ALC_GET_PDI_AMOUNT_BUF0( AMOUNT ) do{ \
			AMOUNT = ( *(volatile unsigned int*) (ALC_PDI_AMOUNT_BUF0) ) ;\
		}while(0)

#define ALC_GET_PDI_AMOUNT_BUF1( AMOUNT ) do{ \
			AMOUNT = ( *(volatile unsigned int*) (ALC_PDI_AMOUNT_BUF1) ) ;\
		}while(0)
		
#define ALC_GET_DBG_STATES( DBGINFO ) do{ \
			DBGINFO = ( *(volatile unsigned int*) (ALC_DBG_STATES) ) ;\
		}while(0)
		
#define ALC_GET_MISC_ERR( ERR ) do{ \
			ERR = ( *(volatile unsigned int*) (ALC_MISC_ERR) ) ;\
		}while(0)

//Get buffer free size	
#define ALC_GET_DBG_SPACE_LEFT_BUF0( DBGINFO ) do{ \
			DBGINFO = ( *(volatile unsigned int*) (ALC_DBG_SPACE_LEFT_BUF0) ) ;\
		}while(0)
			
#define ALC_GET_DBG_SPACE_LEFT_BUF1( DBGINFO ) do{ \
			DBGINFO = ( *(volatile unsigned int*) (ALC_DBG_SPACE_LEFT_BUF1) ) ;\
		}while(0)


#define ALC_GET_DBG_BUL_BUF0( DBGINFO ) do{ \
			DBGINFO = ( *(volatile unsigned int*) (ALC_DBG_BUL_BUF0) ) ;\
		}while(0)
		
#define ALC_GET_DBG_BUL_BUF1( DBGINFO ) do{ \
			DBGINFO = ( *(volatile unsigned int*) (ALC_DBG_BUL_BUF1) ) ;\
		}while(0)

////////////////////////////////////////////////////////////
// MALMO: ADOE Definition
////////////////////////////////////////////////////////////
#define ADOE_CONFIG  			 		 ( ADOE_BASEADDR + 0x0000 )
#define ADOE_BUFFER_SELECTION_ALGORITHM   ( ADOE_BASEADDR + 0x0004 )
#define ADOE_OUTPUT_BWL_TIMEWINDOW   	 ( ADOE_BASEADDR + 0x0008 )

#define ADOE_LOGGING_BUFFER_BASEADDR_CHN0   ( ADOE_BASEADDR + 0x0010 )
#define ADOE_LOGGING_BUFFER_BASEADDR_CHN1   ( ADOE_BASEADDR + 0x0014 )
#define ADOE_LOGGING_BUFFER_BASEADDR_CHN2   ( ADOE_BASEADDR + 0x0018 )

#define ADOE_LOGGING_BUFFER_SIZE_CHN0   ( ADOE_BASEADDR + 0x0030 )
#define ADOE_LOGGING_BUFFER_SIZE_CHN1   ( ADOE_BASEADDR + 0x0034 )
#define ADOE_LOGGING_BUFFER_SIZE_CHN2   ( ADOE_BASEADDR + 0x0038 )

#define ADOE_OUTPUT_BWL_THRESHOLD_CHN0   ( ADOE_BASEADDR + 0x0050 )
#define ADOE_OUTPUT_BWL_THRESHOLD_CHN1   ( ADOE_BASEADDR + 0x0054 )
#define ADOE_OUTPUT_BWL_THRESHOLD_CHN2   ( ADOE_BASEADDR + 0x0058 )

#define ADOE_USB_SETTX_ADDR          ( ADOE_BASEADDR + 0x00B0 )
#define ADOE_USB_EP_NUM   			 ( ADOE_BASEADDR + 0x00C0 )
#define ADOE_USB_FIFO_BASEADDR   	 ( ADOE_BASEADDR + 0x00C4 )
#define ADOE_USB_MPS   				 ( ADOE_BASEADDR + 0x00C8 )
#define ADOE_USB_BURST_WRITE_LEN  	 ( ADOE_BASEADDR + 0x00D0 )
#define ADOE_EMI_BURST_READ_LEN   	 ( ADOE_BASEADDR + 0x00D4 )
#define ADOE_EMI_BURST_READ_SIZE   	 ( ADOE_BASEADDR + 0x00D8 )
#define ADOE_MODE  					 ( ADOE_BASEADDR + 0x00DC )
#define ADOE_USB_MPS_WORKAROUND_DIS  ( ADOE_BASEADDR + 0x00E0 )

#define ADOE_RD_PTR_CHN0   ( ADOE_BASEADDR + 0x0100 )
#define ADOE_RD_PTR_CHN1   ( ADOE_BASEADDR + 0x0104 )
#define ADOE_RD_PTR_CHN2   ( ADOE_BASEADDR + 0x0108 )

#define ADOE_WR_PTR_CHN0   ( ADOE_BASEADDR + 0x0120 )
#define ADOE_WR_PTR_CHN1   ( ADOE_BASEADDR + 0x0124 )
#define ADOE_WR_PTR_CHN2   ( ADOE_BASEADDR + 0x0128 )

#define ADOE_BUFFER_ALT_THRESHOLD_CHN0   ( ADOE_BASEADDR + 0x0160 )
#define ADOE_BUFFER_ALT_THRESHOLD_CHN1   ( ADOE_BASEADDR + 0x0164 )
#define ADOE_BUFFER_ALT_THRESHOLD_CHN2   ( ADOE_BASEADDR + 0x0168 )

#define ADOE_INT_EN   					( ADOE_BASEADDR + 0x0180 )
#define ADOE_BUFFER_ALT_INT_EN   		( ADOE_BASEADDR + 0x0184)
#define ADOE_BUFFER_ALT_STATUS   		( ADOE_BASEADDR + 0x0188 )
#define ADOE_USB_IDLE_STUCK_INT_EN  	( ADOE_BASEADDR + 0x018C )
#define ADOE_USB_IDLE_STUCK_INT_STATUS  ( ADOE_BASEADDR + 0x0190 )

#define ADOE_OUTPUT_DATA_TOTAL_AMOUNT_CHN0   ( ADOE_BASEADDR + 0x01C0 )
#define ADOE_OUTPUT_DATA_TOTAL_AMOUNT_CHN1   ( ADOE_BASEADDR + 0x01C4 )
#define ADOE_OUTPUT_DATA_TOTAL_AMOUNT_CHN2   ( ADOE_BASEADDR + 0x01C8 )

#define ADOE_MANU_SETTX         ( ADOE_BASEADDR + 0x0220 )
#define ADOE_DBG_STATES         ( ADOE_BASEADDR + 0x0228 )
#define ADOE_DBG_INFO           ( ADOE_BASEADDR + 0x022C )
//Note! For DVT only
#define ADOE_TEST_WR_PTR_CHN0   ( ADOE_BASEADDR + 0x0200 )
#define ADOE_TEST_WR_PTR_CHN1   ( ADOE_BASEADDR + 0x0204 )
#define ADOE_TEST_WR_PTR_CHN2   ( ADOE_BASEADDR + 0x0208 )

#define __TST_ADOE_CHANNEL_INT_ASM_BUF_VAL (1)
#define __TST_ADOE_CHANNEL_INT_L1_BUF_VAL (2)
#define __TST_ADOE_CHANNEL_INT_PS_BUF_VAL (4) 


//////////////////////////ADOE Control Macro///////////////////////////////////
//ADOE_CONFIG
#define ADOE_ENABLE do{ \
			*((volatile unsigned int*) (ADOE_CONFIG)) |= (0x1) ;\
		}while(0)

#define ADOE_DISABLE do{ \
			*((volatile unsigned int*) (ADOE_CONFIG)) &= (0xFFFFFFF0) ;\
		}while(0)

//Be sure to disable all channels before resetting ADOE!
#define ADOE_RESET do{ \
           ADOE_SET_CH0_DISABLED;\
           ADOE_SET_CH1_DISABLED;\
           ADOE_SET_CH2_DISABLED;\
			*((volatile unsigned int*) (ADOE_CONFIG)) |= (0x10) ;\
		}while(0)

#define ADOE_POLL_BUSY do{ \
			while( (*((volatile unsigned int*) (ADOE_CONFIG)) & 0x100) == 0x100 ){};\
		}while(0)

#define ADOE_POLL_TO_BE_IDLE do{ \
			while( *(volatile unsigned int*) (ADOE_DBG_STATES) != 0x00010000 ){};\
		}while(0)
		
#define ADOE_SET_CH0_ENABLED do{ \
			*((volatile unsigned int*) (ADOE_CONFIG)) |= (0x10000) ;\
		}while(0)

#define ADOE_SET_CH1_ENABLED do{ \
			*((volatile unsigned int*) (ADOE_CONFIG)) |= (0x20000) ;\
		}while(0)

#define ADOE_SET_CH2_ENABLED do{ \
			*((volatile unsigned int*) (ADOE_CONFIG)) |= (0x40000) ;\
		}while(0)

#define ADOE_SET_CH0_DISABLED do{ \
			*((volatile unsigned int*) (ADOE_CONFIG)) &= (0xFFFEFFFF) ;\
		}while(0)

#define ADOE_SET_CH1_DISABLED do{ \
			*((volatile unsigned int*) (ADOE_CONFIG)) &= (0xFFFDFFFF) ;\
		}while(0)

#define ADOE_SET_CH2_DISABLED do{ \
			*((volatile unsigned int*) (ADOE_CONFIG)) &= (0xFFFBFFFF) ;\
		}while(0)
/////

//For USB pause
#define ADOE_SET_ALL_CHN_DISABLED do{ \
			*((volatile unsigned int*) (ADOE_CONFIG)) &= (0xFFF0FFFF) ;\
		}while(0)
		
#define ADOE_SET_CHN_ENABLED(VAL) do{ \
			*((volatile unsigned int*) (ADOE_CONFIG)) |= (VAL) ;\
		}while(0)

#define ADOE_GET_CHN_ENABLED_STATUS(VAL) do{ \
			VAL = (*(volatile unsigned int*) (ADOE_CONFIG)) & 0x000F0000 ;\
		}while(0)
/////

//ADOE_BUFFER_SELECTION_ALGORITHM
#define ADOE_SET_BUFFER_SELECTION_ALGORITHM_RR do{ \
			*((volatile unsigned int*) (ADOE_BUFFER_SELECTION_ALGORITHM)) = 0x1 ;\
		}while(0)

////Combined with PM mode
#define ADOE_SET_BUFFER_SELECTION_ALGORITHM_CHN0_TOP_PRIORITY do{ \
			*((volatile unsigned int*) (ADOE_BUFFER_SELECTION_ALGORITHM)) = 0x00 ;\
		}while(0)

#define ADOE_SET_BUFFER_SELECTION_ALGORITHM_CHN1_TOP_PRIORITY do{ \
			*((volatile unsigned int*) (ADOE_BUFFER_SELECTION_ALGORITHM)) = 0x10 ;\
		}while(0)

#define ADOE_SET_BUFFER_SELECTION_ALGORITHM_CHN2_TOP_PRIORITY do{ \
			*((volatile unsigned int*) (ADOE_BUFFER_SELECTION_ALGORITHM)) = 0x20 ;\
		}while(0)

//ADOE_OUTPUT_BWL_TIMEWINDOW, MIN: 0 ms, MAX: 65535 ms
#define ADOE_SET_OUTPUT_BWL_TIMEWINDOW(BWL_TW) do{ \
			*(volatile unsigned int*) (ADOE_OUTPUT_BWL_TIMEWINDOW) = (BWL_TW) ;\
		}while(0)


//ADOE_LOGGING_BUFFER_BASEADDR
#define ADOE_SET_LOGGING_BUFFER_BASEADDR_CHN0(ADDR) do{ \
			*(volatile unsigned int*) (ADOE_LOGGING_BUFFER_BASEADDR_CHN0) = (ADDR) ;\
		}while(0)

#define ADOE_SET_LOGGING_BUFFER_BASEADDR_CHN1(ADDR) do{ \
			*(volatile unsigned int*) (ADOE_LOGGING_BUFFER_BASEADDR_CHN1) = (ADDR) ;\
		}while(0)

#define ADOE_SET_LOGGING_BUFFER_BASEADDR_CHN2(ADDR) do{ \
			*(volatile unsigned int*) (ADOE_LOGGING_BUFFER_BASEADDR_CHN2) = (ADDR) ;\
		}while(0)

//ADOE_LOGGING_BUFFER_SIZE
//Note that in ADOE, it base is in "word"
#define ADOE_SET_LOGGING_BUFFER_SIZE_CHN0(SIZE) do{ \
			*(volatile unsigned int*) (ADOE_LOGGING_BUFFER_SIZE_CHN0) = (SIZE) ;\
		}while(0)

#define ADOE_SET_LOGGING_BUFFER_SIZE_CHN1(SIZE) do{ \
			*(volatile unsigned int*) (ADOE_LOGGING_BUFFER_SIZE_CHN1) = (SIZE) ;\
		}while(0)

#define ADOE_SET_LOGGING_BUFFER_SIZE_CHN2(SIZE) do{ \
			*(volatile unsigned int*) (ADOE_LOGGING_BUFFER_SIZE_CHN2) = (SIZE) ;\
		}while(0)

//ADOE_OUTPUT_BWL_THRESHOLD
#define ADOE_SET_OUTPUT_BWL_THRESHOLD_CHN0(TH) do{ \
			*(volatile unsigned int*) (ADOE_OUTPUT_BWL_THRESHOLD_CHN0) = (TH) ;\
		}while(0)

#define ADOE_SET_OUTPUT_BWL_THRESHOLD_CHN1(TH) do{ \
			*(volatile unsigned int*) (ADOE_OUTPUT_BWL_THRESHOLD_CHN1) = (TH) ;\
		}while(0)

#define ADOE_SET_OUTPUT_BWL_THRESHOLD_CHN2(TH) do{ \
			*(volatile unsigned int*) (ADOE_OUTPUT_BWL_THRESHOLD_CHN2) = (TH) ;\
		}while(0)

//ADOE_USB_EP_NUM: from 1 to 15
#define ADOE_SET_USB_EP_NUM(VAL) do{ \
			*(volatile unsigned int*) (ADOE_USB_EP_NUM) = (VAL) ;\
		}while(0)

//ADOE_USB_FIFO_BASEADDR
#define ADOE_SET_USB_FIFO_BASEADDR(ADDR) do{ \
			*(volatile unsigned int*) (ADOE_USB_FIFO_BASEADDR) = (ADDR) ;\
		}while(0)

//ADOE SetTxPktRdy
#define ADOE_SET_USB_SETTX_ADDR(ADDR) do{ \
			*(volatile unsigned int*) (ADOE_USB_SETTX_ADDR) = (ADDR) ;\
		}while(0)
		
//ADOE_USB_MPS: Value of N where size is: 2^(N+5)
#define ADOE_SET_USB_MPS(VAL) do{ \
			*(volatile unsigned int*) (ADOE_USB_MPS) = (VAL) ;\
		}while(0)
		
//ADOE_USB_BURST_WRITE_LEN: from 0 to 3
#define ADOE_SET_USB_BURST_WRITE_LEN(VAL) do{ \
			*(volatile unsigned int*) (ADOE_USB_BURST_WRITE_LEN) = (VAL) ;\
		}while(0)

//ADOE_EMI_BURST_READ_LEN: from 0 to 3
#define ADOE_SET_EMI_BURST_READ_LEN(VAL) do{ \
			*(volatile unsigned int*) (ADOE_EMI_BURST_READ_LEN) = (VAL) ;\
		}while(0)
		
//ADOE_BURST_READ_SIZE: from 0 to 3
#define ADOE_SET_BURST_READ_SIZE(VAL) do{ \
			*(volatile unsigned int*) (ADOE_EMI_BURST_READ_SIZE) = (VAL) ;\
		}while(0)

//ADOE_MODE
#define ADOE_SET_TO_MANUAL_MODE do{ \
			*(volatile unsigned int*) (ADOE_MODE) = (0x2) ;\
		}while(0)

#define ADOE_SET_TO_AUTO_USB_MODE do{ \
			*(volatile unsigned int*) (ADOE_MODE) = (0x00) ;\
		}while(0)

#define ADOE_SET_TO_AUTO_UART_MODE do{ \
			*(volatile unsigned int*) (ADOE_MODE) = (0x01) ;\
		}while(0)
		
#define ADOE_SET_TO_SPECIAL_VALIDATION_MODE do{ \
			*(volatile unsigned int*) (ADOE_MODE) |= (0x80000000) ;\
		}while(0)

#define ADOE_SET_UART0_TO_CHN0 do{ \
			*(volatile unsigned int*) (ADOE_MODE) &= (0xFFFFFF0F) ;\
			*(volatile unsigned int*) (ADOE_MODE) |= (0x00) ;\
		}while(0)

#define ADOE_SET_UART0_TO_CHN1 do{ \
			*(volatile unsigned int*) (ADOE_MODE) &= (0xFFFFFF0F) ;\
			*(volatile unsigned int*) (ADOE_MODE) |= (0x10) ;\
		}while(0)

#define ADOE_SET_UART0_TO_CHN2 do{ \
			*(volatile unsigned int*) (ADOE_MODE) &= (0xFFFFFF0F) ;\
			*(volatile unsigned int*) (ADOE_MODE) |= (0x20) ;\
		}while(0)

//ADOE_USB_MPS_WORKAROUND_DIS
#define ADOE_SET_USB_MPS_WORKAROUND_ENABLED do{ \
			*(volatile unsigned int*) (ADOE_USB_MPS_WORKAROUND_DIS) = (0x0) ;\
		}while(0)

#define ADOE_SET_USB_MPS_WORKAROUND_DISABLED do{ \
			*(volatile unsigned int*) (ADOE_USB_MPS_WORKAROUND_DIS) = (0x1) ;\
		}while(0)

//ADOE_RD_PTR
#define ADOE_GET_RD_PTR_CHN0(PTR) do{ \
			PTR = (*(volatile unsigned int*) (ADOE_RD_PTR_CHN0)) ;\
		}while(0)

#define ADOE_GET_RD_PTR_CHN1(PTR) do{ \
			PTR = (*(volatile unsigned int*) (ADOE_RD_PTR_CHN1)) ;\
		}while(0)

#define ADOE_GET_RD_PTR_CHN2(PTR) do{ \
			PTR = (*(volatile unsigned int*) (ADOE_RD_PTR_CHN2)) ;\
		}while(0)

#define ADOE_SET_RD_PTR_CHN0(PTR) do{ \
			*(volatile unsigned int*) (ADOE_RD_PTR_CHN0) = (PTR) ;\
		}while(0)

#define ADOE_SET_RD_PTR_CHN1(PTR) do{ \
			*(volatile unsigned int*) (ADOE_RD_PTR_CHN1) = (PTR) ;\
		}while(0)

#define ADOE_SET_RD_PTR_CHN2(PTR) do{ \
			*(volatile unsigned int*) (ADOE_RD_PTR_CHN2) = (PTR) ;\
		}while(0)

#define ADOE_GET_WR_PTR_CHN0(PTR) do{ \
			PTR = (*(volatile unsigned int*) (ADOE_WR_PTR_CHN0)) ;\
		}while(0)

#define ADOE_GET_WR_PTR_CHN1(PTR) do{ \
			PTR = (*(volatile unsigned int*) (ADOE_WR_PTR_CHN1)) ;\
		}while(0)

#define ADOE_GET_WR_PTR_CHN2(PTR) do{ \
			PTR = (*(volatile unsigned int*) (ADOE_WR_PTR_CHN2)) ;\
		}while(0)
		
#define ADOE_GET_DBG_STATES(VAL) do{ \
			VAL = (*(volatile unsigned int*) (ADOE_DBG_STATES)) ;\
	   }while(0)

//Note! This is for DVT only!
#define ADOE_SET_WR_PTR_CHN0(PTR) do{ \
			*(volatile unsigned int*) (ADOE_TEST_WR_PTR_CHN0) = (PTR) ;\
		}while(0)
	
#define ADOE_SET_WR_PTR_CHN1(PTR) do{ \
			*(volatile unsigned int*) (ADOE_TEST_WR_PTR_CHN1) = (PTR) ;\
		}while(0)
	
#define ADOE_SET_WR_PTR_CHN2(PTR) do{ \
			*(volatile unsigned int*) (ADOE_TEST_WR_PTR_CHN2) = (PTR) ;\
		}while(0)

//ADOE_BUFFER_ALT_THRESHOLD
#define ADOE_SET_BUFFER_ALT_THRESHOLD_CHN0(VAL) do{ \
			*(volatile unsigned int*) (ADOE_BUFFER_ALT_THRESHOLD_CHN0) = (VAL) ;\
		}while(0)

#define ADOE_SET_BUFFER_ALT_THRESHOLD_CHN1(VAL) do{ \
			*(volatile unsigned int*) (ADOE_BUFFER_ALT_THRESHOLD_CHN1) = (VAL) ;\
		}while(0)

#define ADOE_SET_BUFFER_ALT_THRESHOLD_CHN2(VAL) do{ \
			*(volatile unsigned int*) (ADOE_BUFFER_ALT_THRESHOLD_CHN2) = (VAL) ;\
		}while(0)

#define ADOE_SET_ENABLE_SW_MANUAL_SET_TX do{ \
			*(volatile unsigned int*) (ADOE_MANU_SETTX) |= (0x1) ;\
		}while(0)

#define ADOE_SET_ENABLE_IGNORE_NEXTBUFRDY do{ \
			*(volatile unsigned int*) (ADOE_MANU_SETTX) |= (0x80000000) ;\
		}while(0)

#define ADOE_SET_DISABLE_SW_MANUAL_SET_TX do{ \
			*(volatile unsigned int*) (ADOE_MANU_SETTX) &= (0xFFFFFFFE) ;\
		}while(0)

#define ADOE_SET_DISABLE_IGNORE_NEXTBUFRDY do{ \
			*(volatile unsigned int*) (ADOE_MANU_SETTX) &= (0x7FFFFFFF) ;\
		}while(0)

//ADOE Interrupt Related
//ADOE_INT_EN
#define ADOE_INT_ENABLE do{ \
		   *(volatile unsigned int*) (ADOE_INT_EN) = (0x1) ;\
	   }while(0)
	   
#define ADOE_INT_DISABLE do{ \
		   *(volatile unsigned int*) (ADOE_INT_EN) = (0x0) ;\
	   }while(0)

//ADOE_BUFFER_ALT_INT_EN
/*
#define ADOE_BUFFER_ALT_INT_ENABLE do{ \
		   *(volatile unsigned int*) (ADOE_BUFFER_ALT_INT_EN) = (0x1) ;\
	   }while(0)
*/

//Enable CHN0, CHN1, CHN2 Buffer Alert Interrupt
#define ADOE_BUFFER_ALT_INT_ALL_ENABLE do{ \
		   *(volatile unsigned int*) (ADOE_BUFFER_ALT_INT_EN) = (0x7) ;\
	   }while(0)	   

#define ADOE_BUFFER_ALT_INT_DISABLE do{ \
		   *(volatile unsigned int*) (ADOE_BUFFER_ALT_INT_EN) = (0x0) ;\
	   }while(0)

//ADOE_BUFFER_ALT_STATUS
#define ADOE_GET_BUFFER_ALT_STATUS(VAL) do{ \
			VAL = (*(volatile unsigned int*) (ADOE_BUFFER_ALT_STATUS)) ;\
		}while(0)

//ADOE_USB_IDLE_STUCK_INT_EN
#define ADOE_USB_IDLE_STUCK_INT_ENABLE do{ \
		   *(volatile unsigned int*) (ADOE_USB_IDLE_STUCK_INT_EN) = (0x1) ;\
	   }while(0)
	   
#define ADOE_USB_IDLE_STUCK_INT_DISABLE do{ \
		   *(volatile unsigned int*) (ADOE_USB_IDLE_STUCK_INT_EN) = (0x0) ;\
	   }while(0)

//ADOE_USB_IDLE_STUCK_INT_STATUS
#define ADOE_GET_USB_IDLE_STUCK_INT_STATUS(VAL) do{ \
			VAL = (*(volatile unsigned int*) (ADOE_USB_IDLE_STUCK_INT_STATUS)) ;\
		}while(0)

//ADOE_OUTPUT_DATA_TOTAL_AMOUNT
#define ADOE_GET_OUTPUT_DATA_TOTAL_AMOUNT_CHN0(VAL) do{ \
			VAL = (*(volatile unsigned int*) (ADOE_OUTPUT_DATA_TOTAL_AMOUNT_CHN0)) ;\
		}while(0)

#define ADOE_GET_OUTPUT_DATA_TOTAL_AMOUNT_CHN1(VAL) do{ \
			VAL = (*(volatile unsigned int*) (ADOE_OUTPUT_DATA_TOTAL_AMOUNT_CHN1)) ;\
		}while(0)

#define ADOE_GET_OUTPUT_DATA_TOTAL_AMOUNT_CHN2(VAL) do{ \
			VAL = (*(volatile unsigned int*) (ADOE_OUTPUT_DATA_TOTAL_AMOUNT_CHN2)) ;\
		}while(0)
    

////////////////////////////////////////////////////////////////////////////////
//SADOE wrapper to ADOE
//***DVT Only!***
//L1 buffer is ADOE_CHN1
//PS buffer is ADOE_CHN2

#define SADOE_GET_BUF0_RD_PTR( PTR ) do{ \
			PTR = (*(volatile unsigned int*) (ADOE_RD_PTR_CHN1)) ;\
		}while(0)
		
#define SADOE_GET_BUF1_RD_PTR( PTR ) do{ \
			PTR = (*(volatile unsigned int*) (ADOE_RD_PTR_CHN2)) ;\
		}while(0)
		
#define SADOE_GET_BUF0_WR_PTR( PTR ) do{ \
			PTR = (*(volatile unsigned int*) (ADOE_WR_PTR_CHN1)) ;\
		}while(0)
		
#define SADOE_GET_BUF1_WR_PTR( PTR ) do{ \
			PTR = (*(volatile unsigned int*) (ADOE_WR_PTR_CHN2)) ;\
		}while(0)
		
#define SADOE_SET_BUF0_RD_PTR( RDPTR ) do{ \
			*(volatile unsigned int*) (ADOE_RD_PTR_CHN1) = RDPTR;\
		}while(0)
		
#define SADOE_SET_BUF1_RD_PTR( RDPTR ) do{ \
			*(volatile unsigned int*) (ADOE_RD_PTR_CHN2) = RDPTR;\
		}while(0)
		
#define SADOE_RESET_BUF0_RD_PTR do{ \
			ADOE_SET_RD_PTR_CHN1(0);\
			ADOE_SET_WR_PTR_CHN1(0);\
		}while(0)
		
#define SADOE_RESET_BUF1_RD_PTR do{ \
			ADOE_SET_RD_PTR_CHN2(0);\
			ADOE_SET_WR_PTR_CHN2(0);\
		}while(0)


////////////////////////////////////////////////////////////
// MALMO: ASM Definition 
////////////////////////////////////////////////////////////

#if defined(MT6280_S00) 
#define ASM_GEN_CONFIG			( ASM_BASEADDR + 0x0000 )
#define ASM_MODE_CONFIG			( ASM_BASEADDR + 0x0004 )
#define ASM_SRAM_FLUSH_TRIG		( ASM_BASEADDR + 0x0008 )
#define ASM_SRAM_MAX_BUF_SIZE   ( ASM_BASEADDR + 0x000C )

#define ASM_BUSY_STATE			( ASM_BASEADDR + 0x001C )
#define ASM_SWLA_TRIG   		( ASM_BASEADDR + 0x0020 )
#define ASM_SWLA_TRACER_SYNC_HEADER_0_ADDR	( ASM_BASEADDR + 0x0024 )
#define ASM_SWLA_TRACER_SYNC_HEADER_1_ADDR	( ASM_BASEADDR + 0x0028 )

#define ASM_SYNC_TRIG			( ASM_BASEADDR + 0x0030 )
#define ASM_SYNC_PATTERN_ADDR   ( ASM_BASEADDR + 0x0034 )
#define ASM_SYNC_HEADER_ADDR	( ASM_BASEADDR + 0x0038 )

#define ASM_TRACER_SAMPLE_RATE	( ASM_BASEADDR + 0x0040 )

#define ASM_PROFILE_EN			( ASM_BASEADDR + 0x0060 )

#define ASM_PROFILE_ADDON_INFO0	( ASM_BASEADDR + 0x0064 )
#define ASM_PROFILE_ADDON_INFO1	( ASM_BASEADDR + 0x0068 )
#define ASM_PROFILE_ADDON_INFO2	( ASM_BASEADDR + 0x006C )
#define ASM_PROFILE_ADDON_INFO3 ( ASM_BASEADDR + 0x0070 )

#define ASM_MON_RANGE_START_0	( ASM_BASEADDR + 0x0084 )
#define ASM_MON_RANGE_END_0 	( ASM_BASEADDR + 0x0088 )
#define ASM_MON_RANGE_START_1   ( ASM_BASEADDR + 0x008C )
#define ASM_MON_RANGE_END_1  	( ASM_BASEADDR + 0x0090 )
#define ASM_MON_RANGE_START_2	( ASM_BASEADDR + 0x0094 )
#define ASM_MON_RANGE_END_2		( ASM_BASEADDR + 0x0098 )
#define ASM_MON_RANGE_START_3	( ASM_BASEADDR + 0x009C )
#define ASM_MON_RANGE_END_3		( ASM_BASEADDR + 0x00A0 )
#define ASM_MON_HEADER 		    ( ASM_BASEADDR + 0x00A4 )

#define ASM_LOG_BUF_BASEADDR	( ASM_BASEADDR + 0x00C0 )
#define ASM_LOG_BUF_SIZE		( ASM_BASEADDR + 0x00C4 )

#define ASM_PDI_HEADER_0   		( ASM_BASEADDR + 0x00E0 )

#define ASM_TIMER_DEBUG			( ASM_BASEADDR + 0x00E4 )
#define ASM_ETM_MCU_PC_ADDR		( ASM_BASEADDR + 0x0100 )
#define ASM_ETM_CONTEXT_ID		( ASM_BASEADDR + 0x0104 )
#define ASM_PMU_PMC0			( ASM_BASEADDR + 0x0108 )

#define ASM_PMU_PMC1			( ASM_BASEADDR + 0x010C )
#define ASM_PMU_PMC2			( ASM_BASEADDR + 0x0110 )
#define ASM_PMU_CYCLE_COUNTER	( ASM_BASEADDR + 0x0114 )

#define ASM_EMI_BCNT			( ASM_BASEADDR + 0x0118 )
#define ASM_EMI_BACT			( ASM_BASEADDR + 0x011C )
#define ASM_EMI_BSCT			( ASM_BASEADDR + 0x0120 )
#define ASM_EMI_BSCT2			( ASM_BASEADDR + 0x0124 )
#define ASM_EMI_BSCT3			( ASM_BASEADDR + 0x0128 )

#define ASM_PERF_BUSY			( ASM_BASEADDR + 0x0184 )
#define ASM_PDI_BUSY			( ASM_BASEADDR + 0x018C )

#else
#define ASM_GEN_CONFIG			( ASM_BASEADDR + 0x0000 )
#define ASM_MODE_CONFIG			( ASM_BASEADDR + 0x0004 )
#define ASM_SRAM_FLUSH_TRIG		( ASM_BASEADDR + 0x0008 )
#define ASM_SRAM_MAX_BUF_SIZE   ( ASM_BASEADDR + 0x000C )

#define ASM_BUSY_STATE			( ASM_BASEADDR + 0x001C )
#define ASM_SWLA_TRIG   		( ASM_BASEADDR + 0x0020 )
#define ASM_SWLA_TRACER_SYNC_HEADER_0_ADDR	( ASM_BASEADDR + 0x0024 )
#define ASM_SWLA_TRACER_SYNC_HEADER_1_ADDR	( ASM_BASEADDR + 0x0028 )

#define ASM_SYNC_TRIG			( ASM_BASEADDR + 0x0030 )
#define ASM_SYNC_PATTERN_ADDR   ( ASM_BASEADDR + 0x0034 )
#define ASM_SYNC_HEADER_ADDR	( ASM_BASEADDR + 0x0038 )

#define ASM_TRACER_SAMPLE_RATE	( ASM_BASEADDR + 0x0040 )

#define ASM_PROFILE_EN			( ASM_BASEADDR + 0x0060 )

#define ASM_PROFILE_ADDON_INFO0	( ASM_BASEADDR + 0x0064 )
#define ASM_PROFILE_ADDON_INFO1	( ASM_BASEADDR + 0x0068 )
#define ASM_PROFILE_ADDON_INFO2	( ASM_BASEADDR + 0x006C )
#define ASM_PROFILE_ADDON_INFO3 ( ASM_BASEADDR + 0x0070 )
#define ASM_PROFILE_ADDON_INFO4	( ASM_BASEADDR + 0x0074 )
#define ASM_PROFILE_ADDON_INFO5	( ASM_BASEADDR + 0x0078 )
#define ASM_PROFILE_ADDON_INFO6	( ASM_BASEADDR + 0x007C )
#define ASM_PROFILE_ADDON_INFO7 ( ASM_BASEADDR + 0x0080 )
#define ASM_PROFILE_ADDON_INFO8	( ASM_BASEADDR + 0x0084 )
#define ASM_PROFILE_ADDON_INFO9	( ASM_BASEADDR + 0x0088 )
#define ASM_PROFILE_ADDON_INFO10 ( ASM_BASEADDR + 0x008C )
#define ASM_PROFILE_ADDON_INFO11 ( ASM_BASEADDR + 0x0090 )

#define ASM_MON_RANGE_START_0	( ASM_BASEADDR + 0x00A4 )
#define ASM_MON_RANGE_END_0 	( ASM_BASEADDR + 0x00A8 )
#define ASM_MON_RANGE_START_1   ( ASM_BASEADDR + 0x00AC )
#define ASM_MON_RANGE_END_1  	( ASM_BASEADDR + 0x00B0 )
#define ASM_MON_RANGE_START_2	( ASM_BASEADDR + 0x00B4 )
#define ASM_MON_RANGE_END_2		( ASM_BASEADDR + 0x00B8 )
#define ASM_MON_RANGE_START_3	( ASM_BASEADDR + 0x00BC )
#define ASM_MON_RANGE_END_3		( ASM_BASEADDR + 0x00C0 )

#define ASM_MON_HEADER 		    ( ASM_BASEADDR + 0x00C4 )

#define ASM_LOG_BUF_BASEADDR	( ASM_BASEADDR + 0x00D0 )
#define ASM_LOG_BUF_SIZE		( ASM_BASEADDR + 0x00D4 )

#define ASM_PDI_HEADER_0   		( ASM_BASEADDR + 0x00E0 )

#define ASM_ETM_MCU_PC_ADDR		( ASM_BASEADDR + 0x0100 )
#define ASM_ETM_CONTEXT_ID		( ASM_BASEADDR + 0x0104 )

#define ASM_PMU_PMC0			( ASM_BASEADDR + 0x0108 )
#define ASM_PMU_PMC1			( ASM_BASEADDR + 0x010C )
#define ASM_PMU_PMC2			( ASM_BASEADDR + 0x0110 )
#define ASM_PMU_CYCLE_COUNTER	( ASM_BASEADDR + 0x0114 )

#define ASM_EMI_BCNT			( ASM_BASEADDR + 0x0118 )
#define ASM_EMI_BACT			( ASM_BASEADDR + 0x011C )
#define ASM_EMI_BSCT			( ASM_BASEADDR + 0x0120 )
#define ASM_EMI_BSCT2			( ASM_BASEADDR + 0x0124 )
#define ASM_EMI_BSCT3			( ASM_BASEADDR + 0x0128 )
#endif

//Just for programming
#define __ASM_HW_SWLA_MODE__ 		(0)
#define __ASM_HW_SW_TRACER_MODE__ 	(1)
#define __ASM_BUS_MONITOR_MODE__ 	(2)

#define __ASM_TIMER_INPUT_FRC__     (0)
#define __ASM_TIMER_INPUT_3G__      (1)

//Configuration for ASM
//MT6280 E1 bug! The Timestamp of Bus Monitor is in LSB
#if defined(MT6280_S00) 
	#define ASM_BUS_MONITOR_FRC_HEADER  (0xC2450000)
	#define ASM_BUS_MONITOR_3G_HEADER   (0xC3450000)
#else
	#define ASM_BUS_MONITOR_FRC_HEADER	(0xC2470000)
	#define ASM_BUS_MONITOR_3G_HEADER	(0xC3470000)
#endif

#define ASM_PDI_HEADER 				(0x0000C547)
#define ASM_SYNC_HEADER 			(0x0000C647)
#define ASM_HW_SW_TRACER_HEADER 	(0x0100C747)
#define ASM_HW_SWLA_HEADER 			(0x0100C847)

#define ASM_SRAM_SIZE_WORD 				(256)
#define ASM_SRAM_FLUSH_TIMEOUT			(0xFF)
   
#define ADOE_ASM_CHN (0)
#define ADOE_L1_CHN (1)
#define ADOE_PS_CHN (2)

//////////////////////////ASM Control Macro///////////////////////////////////
#define ASM_INPUT_ENABLE do{ \
			*((volatile unsigned int*) (ASM_GEN_CONFIG)) |= (0x1) ;\
		}while(0)

#define ASM_INPUT_DISABLE do{ \
			*((volatile unsigned int*) (ASM_GEN_CONFIG)) &= (0xFFFFFFF0) ;\
		}while(0)

#define ASM_RESET do{ \
			*((volatile unsigned int*) (ASM_GEN_CONFIG)) |= (0x10) ;\
		}while(0)

#define ASM_POLL_BUSY do{ \
			while( *((volatile unsigned int*) (ASM_BUSY_STATE) ) == 0x1 ){};\
		}while(0)

#define ASM_POLL_PERF_BUSY do{ \
			while( *((volatile unsigned int*) (ASM_PERF_BUSY) ) != 0 ){};\
		}while(0)

#define ASM_POLL_PDI_BUSY do{ \
			while( *((volatile unsigned int*) (ASM_PDI_BUSY) ) != 0 ){};\
		}while(0)

#define ASM_SET_TIMER_SELECTION_FRC do{ \
			*((volatile unsigned int*) (ASM_GEN_CONFIG)) &= (0xFFF0FFFF) ;\
		}while(0)

#define ASM_SET_TIMER_SELECTION_3G_TIMER do{ \
			*((volatile unsigned int*) (ASM_GEN_CONFIG)) |= (0x10000) ;\
		}while(0)

#define ASM_PDI_ENABLE do{ \
			*((volatile unsigned int*) (ASM_GEN_CONFIG)) |= (0x00000100) ;\
		}while(0)

#define ASM_PDI_DISABLE do{ \
			*((volatile unsigned int*) (ASM_GEN_CONFIG)) &= (0xFFFFF0FF) ;\
		}while(0)

#define ASM_MONITOR_TIMER_ENABLE do{ \
			*((volatile unsigned int*) (ASM_MODE_CONFIG)) |= (0x10) ;\
		}while(0)

#define ASM_MONITOR_TIMER_DISABLE do{ \
			*((volatile unsigned int*) (ASM_GEN_CONFIG)) &= (0xFFFFFFF0) ;\
		}while(0)
		
#define ASM_SET_MODE_TO_HW_SWLA_MODE do{ \
			*((volatile unsigned int*) (ASM_MODE_CONFIG)) = (0x00110) ;\
		}while(0)

#define ASM_SET_MODE_TO_HW_SW_TRACER_MODE do{ \
			*((volatile unsigned int*) (ASM_MODE_CONFIG)) = (0x01110) ;\
		}while(0)

#define ASM_SET_MODE_TO_BUS_MONITOR_MODE do{ \
			*((volatile unsigned int*) (ASM_MODE_CONFIG)) = (0x10010) ;\
		}while(0)

#define ASM_SET_MODE_TO_SYNC_PATTERN_OUTPUT_MODE do{ \
			*((volatile unsigned int*) (ASM_MODE_CONFIG)) &= (0xFFF0F0FF) ;\
		}while(0)

//Once you write out the SYNC PATTERN, the SYNC PACKET will be generated at once
#define ASM_SET_SYNC_PATTERN(VAL) do{ \
			*(volatile unsigned int*) (ASM_SYNC_PATTERN_ADDR) = (VAL) ;\
			ASM_POLL_BUSY;\
		}while(0)

#define ASM_SET_SYNC_HEADER(VAL) do{ \
			*(volatile unsigned int*) (ASM_SYNC_HEADER_ADDR) = (VAL) ;\
		}while(0)

#define ASM_SET_SRAM_FLUSH_TRIGGER do{ \
			*((volatile unsigned int*) (ASM_SRAM_FLUSH_TRIG)) = 1 ;\
			ASM_POLL_BUSY;\
		}while(0)
//The ASM auto-flush feature is not available
#define ASM_SET_SRAM_FLUSH_TIMEOUT(VAL) do{ \
			*(volatile unsigned int*) (ASM_MODE_CONFIG) &= ( 0x000FFFFF ) ;\
		}while(0)		

#define ASM_SET_SRAM_MAX_BUF_SIZE(VAL) do{ \
			*(volatile unsigned int*) (ASM_SRAM_MAX_BUF_SIZE) = (VAL) ;\
		}while(0)

//HW-SWLA
#define ASM_SET_HW_SWLA_TRIGGER do{ \
			*((volatile unsigned int*) (ASM_SWLA_TRIG)) = 1 ;\
		}while(0)

#define ASM_SET_HW_SWLA_ADN_SW_TRACER_HEADER(VAL) do{ \
			*(volatile unsigned int*) (ASM_SWLA_TRACER_SYNC_HEADER_0_ADDR) = (VAL) ;\
		}while(0)

//ASM HW-SW-Tracer
#define ASM_SET_HW_SW_TRACER_SAMPLING_RATE(VAL) do{ \
			*(volatile unsigned int*) (ASM_TRACER_SAMPLE_RATE) = (VAL) ;\
		}while(0)

//ASM Monitoring Filter
#define ASM_SET_HW_MONITOR_FILTER(VAL) do{ \
			*(volatile unsigned int*) (ASM_PROFILE_EN) = (VAL) ;\
		}while(0)

//ASM Extra Addon-info
#define ASM_SET_HW_MONITOR_EXTRA_ADDON_0(VAL) do{ \
			*(volatile unsigned int*) (ASM_PROFILE_ADDON_INFO0) = (VAL) ;\
		}while(0)

#define ASM_SET_HW_MONITOR_EXTRA_ADDON_1(VAL) do{ \
			*(volatile unsigned int*) (ASM_PROFILE_ADDON_INFO1) = (VAL) ;\
		}while(0)

#define ASM_SET_HW_MONITOR_EXTRA_ADDON_2(VAL) do{ \
			*(volatile unsigned int*) (ASM_PROFILE_ADDON_INFO2) = (VAL) ;\
		}while(0)

#define ASM_SET_HW_MONITOR_EXTRA_ADDON_3(VAL) do{ \
			*(volatile unsigned int*) (ASM_PROFILE_ADDON_INFO3) = (VAL) ;\
		}while(0)

//ASM Bus Monitor
#define ASM_SET_BUS_MONITOR_RAGE_0_START(VAL) do{ \
			*(volatile unsigned int*) (ASM_MON_RANGE_START_0) = (VAL) ;\
		}while(0)

#define ASM_SET_BUS_MONITOR_RAGE_0_END(VAL) do{ \
			*(volatile unsigned int*) (ASM_MON_RANGE_END_0) = (VAL) ;\
		}while(0)

#define ASM_SET_BUS_MONITOR_RAGE_1_START(VAL) do{ \
			*(volatile unsigned int*) (ASM_MON_RANGE_START_1) = (VAL) ;\
		}while(0)

#define ASM_SET_BUS_MONITOR_RAGE_1_END(VAL) do{ \
			*(volatile unsigned int*) (ASM_MON_RANGE_END_1) = (VAL) ;\
		}while(0)

#define ASM_SET_BUS_MONITOR_RAGE_2_START(VAL) do{ \
			*(volatile unsigned int*) (ASM_MON_RANGE_START_2) = (VAL) ;\
		}while(0)

#define ASM_SET_BUS_MONITOR_RAGE_2_END(VAL) do{ \
			*(volatile unsigned int*) (ASM_MON_RANGE_END_2) = (VAL) ;\
		}while(0)

#define ASM_SET_BUS_MONITOR_RAGE_3_START(VAL) do{ \
			*(volatile unsigned int*) (ASM_MON_RANGE_START_3) = (VAL) ;\
		}while(0)

#define ASM_SET_BUS_MONITOR_RAGE_3_END(VAL) do{ \
			*(volatile unsigned int*) (ASM_MON_RANGE_END_3) = (VAL) ;\
		}while(0)

#define ASM_SET_BUS_MONITOR_HEADER(VAL) do{ \
			*(volatile unsigned int*) (ASM_MON_HEADER) = (VAL) ;\
		}while(0)

//ASM Logging Buffer
#define ASM_SET_LOG_BUF_BASEADDR(VAL) do{ \
			*(volatile unsigned int*) (ASM_LOG_BUF_BASEADDR) = (VAL) ;\
		}while(0)
////In KB
#define ASM_SET_LOG_BUF_SIZE(VAL) do{ \
			*(volatile unsigned int*) (ASM_LOG_BUF_SIZE) = (VAL) ;\
		}while(0)

//ASM PDI
#define ASM_SET_PDI_HEADER(VAL) do{ \
			*(volatile unsigned int*) (ASM_PDI_HEADER_0) = (VAL) ;\
		}while(0)

//ASM Debugging Info
#define ASM_GET_ETM_MCU_PC_ADDR(VAL) do{ \
			VAL = (*(volatile unsigned int*) (ASM_ETM_MCU_PC_ADDR)) ;\
		}while(0)

#define ASM_GET_ETM_CONTEX_ID(VAL) do{ \
			VAL = (*(volatile unsigned int*) (ASM_ETM_CONTEXT_ID)) ;\
		}while(0)

#define ASM_GET_PMU_PMC0(VAL) do{ \
			VAL = (*(volatile unsigned int*) (ASM_PMU_PMC0)) ;\
		}while(0)

#define ASM_GET_PMU_PMC1(VAL) do{ \
			VAL = (*(volatile unsigned int*) (ASM_PMU_PMC1)) ;\
		}while(0)

#define ASM_GET_PMU_PMC2(VAL) do{ \
			VAL = (*(volatile unsigned int*) (ASM_PMU_PMC2)) ;\
		}while(0)

#define ASM_GET_PMU_CYCLE_COUNTER(VAL) do{ \
			VAL = (*(volatile unsigned int*) (ASM_PMU_CYCLE_COUNTER)) ;\
		}while(0)

#define ASM_GET_EMI_BCNT(VAL) do{ \
			VAL = (*(volatile unsigned int*) (ASM_EMI_BCNT)) ;\
		}while(0)

#define ASM_GET_EMI_BACT(VAL) do{ \
			VAL = (*(volatile unsigned int*) (ASM_EMI_BACT)) ;\
		}while(0)

#define ASM_GET_EMI_BSCT(VAL) do{ \
			VAL = (*(volatile unsigned int*) (ASM_EMI_BSCT)) ;\
		}while(0)

#define ASM_GET_EMI_BSCT2(VAL) do{ \
			VAL = (*(volatile unsigned int*) (ASM_EMI_BSCT2)) ;\
		}while(0)

#define ASM_GET_EMI_BSCT3(VAL) do{ \
			VAL = (*(volatile unsigned int*) (ASM_EMI_BSCT3)) ;\
		}while(0)

#define ASM_GET_EXTRA_INFO0(VAL) do{ \
			VAL = (*(volatile unsigned int*) (ASM_PROFILE_ADDON_INFO0)) ;\
		}while(0)
		
#define ASM_GET_EXTRA_INFO1(VAL) do{ \
			VAL = (*(volatile unsigned int*) (ASM_PROFILE_ADDON_INFO1)) ;\
		}while(0)

#define ASM_GET_EXTRA_INFO2(VAL) do{ \
			VAL = (*(volatile unsigned int*) (ASM_PROFILE_ADDON_INFO2)) ;\
		}while(0)

#define ASM_GET_EXTRA_INFO3(VAL) do{ \
			VAL = (*(volatile unsigned int*) (ASM_PROFILE_ADDON_INFO3)) ;\
		}while(0)

#if !defined(MT6280_S00)

#define ASM_GET_EXTRA_INFO4(VAL) do{ \
			VAL = (*(volatile UINT32*) (ASM_PROFILE_ADDON_INFO4)) ;\
		}while(0)

#define ASM_GET_EXTRA_INFO5(VAL) do{ \
			VAL = (*(volatile UINT32*) (ASM_PROFILE_ADDON_INFO5)) ;\
		}while(0)

#define ASM_GET_EXTRA_INFO6(VAL) do{ \
			VAL = (*(volatile UINT32*) (ASM_PROFILE_ADDON_INFO6)) ;\
		}while(0)

#define ASM_GET_EXTRA_INFO7(VAL) do{ \
			VAL = (*(volatile UINT32*) (ASM_PROFILE_ADDON_INFO7)) ;\
		}while(0)

#define ASM_GET_EXTRA_INFO8(VAL) do{ \
			VAL = (*(volatile UINT32*) (ASM_PROFILE_ADDON_INFO8)) ;\
		}while(0)

#define ASM_GET_EXTRA_INFO9(VAL) do{ \
			VAL = (*(volatile UINT32*) (ASM_PROFILE_ADDON_INFO9)) ;\
		}while(0)


#define ASM_GET_EXTRA_INFO10(VAL) do{ \
			VAL = (*(volatile UINT32*) (ASM_PROFILE_ADDON_INFO10)) ;\
		}while(0)

#define ASM_GET_EXTRA_INFO11(VAL) do{ \
			VAL = (*(volatile UINT32*) (ASM_PROFILE_ADDON_INFO11)) ;\
		}while(0)
#endif



#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
//ALC Burst Access

//**************************************************************
//      Function Declaration
//**************************************************************
void AdoePollSwCanSetTxPktRdy(void);
void AlcFinishAllPacket(void);
void AlcReset(void);
void MalmoHwEnable(void);
char AlcInit(unsigned int *alc_l1_buffer, unsigned int *alc_ps_buffer, unsigned int alc_l1_buffer_length, unsigned int alc_ps_buffer_length);
int AlcCheckLitFull(void);
int AlcSwManualFlush(unsigned int flush_value);
int AlcCheckMiscErr(void);
void AdoeInit(void);
void AlcAndAdoeReset(void);
char AdoeConfigUsbMode(unsigned int usb_ep_num, unsigned int usb_mps, unsigned int usb_base_addr, unsigned int usb_txpktrdy_base_addr);
char AdoeConfigUartMode(int single_channel_to_output);
char AdoeConfigManualMode(char int_enable_val);
char AdoeConfigManualModeNoInterrupt(void);
void AdoeConfigChannel(char single_channel, int base_addr, unsigned int buffer_size);
void AdoeEnableChannel(int channel_num);
void AdoeDisableChannel(int channel_num);
void AdoePauseAllChannels(void);
void AdoeResumeAllChannels(void);
void AdoeSetupBwl(int bwl_timewindow, int bwl_chn0, int bwl_chn1, int bwl_chn2);
void AdoeSetManualModeAltThreshold(int alt_th_chn0, int alt_th_chn1, int alt_th_chn2);
void AdoeGetPtrChn0(unsigned int *rd_ptr, unsigned int *wr_ptr);
void AdoeGetPtrChn1(unsigned int *rd_ptr, unsigned int *wr_ptr);
void AdoeGetPtrChn2(unsigned int *rd_ptr, unsigned int *wr_ptr);
unsigned int AdoeGetWrPtrChn0();
unsigned int AdoeGetWrPtrChn1();
unsigned int AdoeGetWrPtrChn2();
void AdoeUpdateRdPtrChn0(unsigned int rd_ptr);
void AdoeUpdateRdPtrChn1(unsigned int rd_ptr);
void AdoeUpdateRdPtrChn2(unsigned int rd_ptr);
void AdoePollAllChannelBufferAreEmpty(int b_timeout, unsigned int timeout_val);

void ClearAllRwPtr(void);
void AsmSetBusMonitorRange(unsigned int range0_start, unsigned int range0_end, unsigned int range1_start, unsigned int range1_end, unsigned int range2_start, unsigned int range2_end, unsigned int range3_start, unsigned int range3_end);
void AsmSetBusMonitorRangeToGlobalVar(unsigned int range0_start, unsigned int range0_end, unsigned int range1_start, unsigned int range1_end, unsigned int range2_start, unsigned int range2_end, unsigned int range3_start, unsigned int range3_end);
void AsmSetBusMonitorRangeFromGlobalVar(void);
void GeneratePacket(unsigned int alc_csm, unsigned int alc_length, char alc_type, char alc_group);


//For SS team
///////////MALMO_ASM_InitSwlaMode/////////////////
//buffer_baseaddr:
//  MUST-BE 32 bit alignment!!!

//buffer_len:
//  The base is in "KB (256 word) "!
//  Note that the minimum size is 256 (1KB)
//  Ex. 1KB -> 256
//      2KB -> 512

//timestamp_type: 
//  #define __ASM_TIMER_INPUT_FRC__     (0)
//  #define __ASM_TIMER_INPUT_3G__      (1)
kal_uint32 MALMO_ASM_InitSwlaMode( 
	kal_uint32* buffer_baseaddr, kal_uint32 buffer_len, kal_uint32 timestamp_type );


//The parameters are almost the same as MALMO_ASM_InitSwlaMode 
// However you need to assign the sampling rate for SW-Tracer
kal_uint32 MALMO_ASM_InitSwTracerMode( 
	kal_uint32* buffer_baseaddr, 
	kal_uint32 buffer_len, 
	kal_uint32 timestamp_type,
	kal_uint32 filter_mask,
	kal_uint32 asm_swtracer_sampling_rate );

kal_uint32 MALMO_ASM_StopSwTracerMode( void );

kal_uint32 MALMO_ASM_SetMonitorFilter( kal_uint32 bitMask );
kal_uint32 MALMO_ASM_FillExtraData( kal_uint32 *buf, kal_uint32 size );

//Send ASM Packet
kal_uint32 MALMO_ASM_Send( void );

//Send more than one ASM Packet
//  Ex. 
//      1   ->   CALL MALMO_ASM_Send();
//      2   ->   CALL MALMO_ASM_ContinueSend();
//      3   ->   CALL MALMO_ASM_ContinueSend();
kal_uint32 MALMO_ASM_ContinueSend( void );

//Send ASM Packet only one once (For no extra record optimization)
kal_uint32 MALMO_ASM_SendOnlyOnePacket( void );

kal_uint32* MALMO_ASM_GetMonitorFilterInfo( void );


//For ASM Bus Monitor
kal_uint32 MALMO_ASM_InitBusMonitorMode( 
	kal_uint32* buffer_baseaddr, 
	kal_uint32 buffer_len, 
	kal_uint32 timestamp_type, 
	kal_uint32 range0_start, kal_uint32 range0_end,
	kal_uint32 range1_start, kal_uint32 range1_end,
	kal_uint32 range2_start, kal_uint32 range2_end,
	kal_uint32 range3_start, kal_uint32 range3_end );

kal_uint32 MALMO_ASM_StopBusMonitorMode( void );

#endif  //__MALMODRIVER_H__

#endif   //#ifdef __TST_MALMO_SUPPORT__
