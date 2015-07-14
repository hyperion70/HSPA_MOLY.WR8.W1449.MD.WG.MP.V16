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
 * atb_limiter_hw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file declares the register map and the control macros for ATB BW limiter
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __ATB_LIMITER_HW_H__ 
#define __ATB_LIMITER_HW_H__

//No ATB BW Limiter on TK6280
#if defined(TK6280) || defined(BB_TK6280) 
	#define __TST_NO_ATB_BW_LIMITER__ 
#endif

#ifndef __TST_NO_ATB_BW_LIMITER__
#define ATB_LIMITER_BASE_ADDR ATBBWL_base

//define ATB BW Limiter control registers
#define ATBBWL_EN_REG_ADDR (ATB_LIMITER_BASE_ADDR)
#define ATBBWL_CON_REG_ADDR (ATB_LIMITER_BASE_ADDR+0x4)
#define ATBBWL_PRI0_REG_ADDR (ATB_LIMITER_BASE_ADDR+0x8)
#define ATBBWL_PRI1_REG_ADDR (ATB_LIMITER_BASE_ADDR+0xc)
#define ATBBWL_PRI_INTERVAL (4)
#define ATBBWL_THRES0_REG_ADDR (ATB_LIMITER_BASE_ADDR+0x10)
#define ATBBWL_THRES1_REG_ADDR (ATB_LIMITER_BASE_ADDR+0x14)
#define ATBBWL_THRES2_REG_ADDR (ATB_LIMITER_BASE_ADDR+0x18)
#define ATBBWL_THRES3_REG_ADDR (ATB_LIMITER_BASE_ADDR+0x1c)
#define ATBBWL_THRES_INTERVAL (4)
#define ATBBWL_DBGCON_REG_ADDR (ATB_LIMITER_BASE_ADDR+0x20)
#define ATBBWL_DBGCLR_REG_ADDR (ATB_LIMITER_BASE_ADDR+0x24)
#define ATBBWL_CYCCNT_REG_ADDR (ATB_LIMITER_BASE_ADDR+0x28)
#define ATBBWL_PRTTRANS_REG_ADDR (ATB_LIMITER_BASE_ADDR+0x2c)
#define ATBBWL_EXDEN_REG_ADDR (ATB_LIMITER_BASE_ADDR+0x30)

//define useful typedefs
typedef enum
{
  ATBBWL_Window_512T = 0,  
  ATBBWL_Window_1024T = 1,
  ATBBWL_Window_2048T = 2,
  ATBBWL_Window_4096T = 3  
}
ATBBWL_Windows_Duration_Enum_t;

typedef enum
{
  ATB_PORT0 = 0,
  ATB_PORT1 = 1,
  ATB_PORT2 = 2,
  ATB_PORT3 = 3,
  ATB_PORT4 = 4,
  ATB_PORT5 = 5,
  ATB_PORT6 = 6,
  ATB_PORT7 = 7,
  ATB_PORT8 = 8,
  ATB_PORT9 = 9,
  ATB_PORT10 = 10,
  ATB_PORT11 = 11,
  ATB_PORT12 = 12,
  ATB_PORT13 = 13,
  ATB_PORT14 = 14,
  ATB_PORT15 = 15,
  ATB_PORT_NOT_CONNECTED = 16,

}
ATBBWL_ATB_Port_Enum_t;

typedef enum
{
  ATB_BW_Threshold_1_128th=1,
  ATB_BW_Threshold_1_64th=0x2,
  ATB_BW_Threshold_1_32nd=0x4,
  ATB_BW_Threshold_1_16th=0x8,
  ATB_BW_Threshold_1_8th=0x10,
  ATB_BW_Threshold_1_4th=0x20,
  ATB_BW_Threshold_1_2nd=0x40,
  ATB_BW_Threshold_1_1st=0x80  
}
ATBBWL_BW_Threshold_t;

#if defined(MT6276) || defined(BB_MT6276)
  #if defined(MT6276_S00)
    #define ATBBWL_PORT_3G ATB_PORT0 //port 0
    #define ATBBWL_PORT_HSUPA ATB_PORT1  //port 1
    #define ATBBWL_PORT_LMU_MDARM ATB_PORT2 //port 2
    #define ATBBWL_PORT_LMU_FCORE4 ATB_PORT3  //port 3
    #define ATBBWL_PORT_HSDPA ATB_PORT5
    #define ATBBWL_PORT_2G ATB_PORT6
    #define ATBBWL_PORT_MM ATB_PORT7
    #define ATBBWL_PORT_LGA1 ATB_PORT8
    #define ATBBWL_PORT_LGA2 ATB_PORT9
    #define ATBBWL_PORT_HSL ATB_PORT12
    #define ATBBWL_PORT_FLUSH ATB_PORT14
  #else //#if defined(MT6276_S00)
    #define ATBBWL_PORT_3G ATB_PORT0 //port 0
    #define ATBBWL_PORT_HSUPA ATB_PORT1  //port 1
    #define ATBBWL_PORT_LMU_MDARM ATB_PORT2 //port 2
    #define ATBBWL_PORT_LMU_FCORE4 ATB_PORT3  //port 3
    #define ATBBWL_PORT_HSDPA ATB_PORT1
    #define ATBBWL_PORT_2G ATB_PORT4
    #define ATBBWL_PORT_MM ATB_PORT5
    #define ATBBWL_PORT_HSL ATB_PORT6
    #define ATBBWL_PORT_FLUSH ATB_PORT7
  #endif  //#if defined(MT6276_S00)
#elif defined(MT6573) || defined(BB_MT6573)
  #define ATBBWL_PORT_3G ATB_PORT0 //port 0
  #define ATBBWL_PORT_HSUPA ATB_PORT1  //port 1
  #define ATBBWL_PORT_LMU_APARM ATB_PORT2 //port 2
  #define ATBBWL_PORT_LMU_FCORE4 ATB_PORT3  //port 3
  #define ATBBWL_PORT_LMU_MDARM ATB_PORT4 //port 4
  #define ATBBWL_PORT_HSDPA ATB_PORT5
  #define ATBBWL_PORT_2G ATB_PORT6
  #define ATBBWL_PORT_MM ATB_PORT7
  #define ATBBWL_PORT_LGA1 ATB_PORT8
  #define ATBBWL_PORT_LGA2 ATB_PORT9
  #define ATBBWL_PORT_ETM ATB_PORT10
  #define ATBBWL_PORT_HSL ATB_PORT12
  #define ATBBWL_PORT_FLUSH ATB_PORT14  
#elif defined(MT6280) || defined(BB_MT6280)
    #define ATBBWL_PORT_3G ATB_PORT0 //port 0
    #define ATBBWL_PORT_HSUPA ATB_PORT1  //port 1
    #define ATBBWL_PORT_LMU_MDARM ATB_PORT2 //port 2
    #define ATBBWL_PORT_LMU_FCORE4 ATB_PORT3  //port 3
    #define ATBBWL_PORT_HSDPA ATB_PORT1
    #define ATBBWL_PORT_2G ATB_PORT4
    #define ATBBWL_PORT_MM ATB_PORT5
    #define ATBBWL_PORT_HSL ATB_PORT6
    #define ATBBWL_PORT_FLUSH ATB_PORT7
#else //#if defined(MT6276)
  #error "Please define proper ATBBWL Port mapping!"
#endif  //#if defined(MT6276)

//define USEFUL MACROS
#define ATBBWL_Set_Bypass_Mode() do{*(volatile int*)ATBBWL_EN_REG_ADDR = 0;}while(0)
#define ATBBWL_Enable() do{*(volatile int*)ATBBWL_EN_REG_ADDR = 1;}while(0)

#define ATBBWL_Set_Timing_Window(duration) do{*(volatile unsigned int*)ATBBWL_CON_REG_ADDR |= (((unsigned int)duration&0x3)<<17); }while(0)
#define ATBBWL_Enable_Soft_Mode() do{*(volatile unsigned int*)ATBBWL_CON_REG_ADDR |= 0x10000; }while(0)
#define ATBBWL_Disable_Soft_Mode() do{*(volatile unsigned int*)ATBBWL_CON_REG_ADDR &= 0xFFFEFFFF; }while(0)
#define ATBBWL_Enable_All_ATB_Master() do{*(volatile unsigned int*)ATBBWL_CON_REG_ADDR |= 0xFFFF; }while(0)
#define ATBBWL_Disable_All_ATB_Master() do{*(volatile unsigned int*)ATBBWL_CON_REG_ADDR &= 0xFFFF0000; }while(0)
#define ATBBWL_Enable_ATB_Master(port) do{*(volatile unsigned int*)ATBBWL_CON_REG_ADDR |= (1 << (port&0xF)); }while(0)
#define ATBBWL_Disable_ATB_Master(port) do{*(volatile unsigned int*)ATBBWL_CON_REG_ADDR &= (0xFF - (1 << (port&0xF))); }while(0)

#define ATBBWL_Set_Port_Priority(port,priority) do{\
                                                    *(volatile unsigned int*) (ATBBWL_PRI0_REG_ADDR+ATBBWL_PRI_INTERVAL*(4*port/32) ) &= ~(0xF << (4*port%32));\
                                                    *(volatile unsigned int*) (ATBBWL_PRI0_REG_ADDR+ATBBWL_PRI_INTERVAL*(4*port/32) ) |= (priority << (4*port%32));\
                                                }while(0)


#define ATBBWL_Set_Port_Threshold(port,threshold) do{\
                                                    *(volatile unsigned int*)( ATBBWL_THRES0_REG_ADDR+ ATBBWL_THRES_INTERVAL*(8*port/32) ) &= ~(0xFF << (8*port%32));\
                                                    *(volatile unsigned int*)( ATBBWL_THRES0_REG_ADDR+ ATBBWL_THRES_INTERVAL*(8*port/32) ) |= (threshold << (8*port%32));\
                                                  }while(0)
 
#define ATBBWL_Enable_Monitor_Function() do{ *(volatile unsigned int*) ATBBWL_DBGCON_REG_ADDR |= 1;}while(0)
#define ATBBWL_Disable_Monitor_Function() do{ *(volatile unsigned int*) ATBBWL_DBGCON_REG_ADDR &= 0xfffffffe;}while(0)


#define ATBBWL_Enable_Monitor_Port(port) do{*(volatile unsigned int*) ATBBWL_DBGCON_REG_ADDR |= (1<<(port+16));}while(0)

#define ATBBWL_Disable_Monitor_Port(port) do{*(volatile unsigned int*) ATBBWL_DBGCON_REG_ADDR &= ~(1<<(port+16));}while(0)
#define ATBBWL_Disable_All_Monitor_Port() do{*(volatile unsigned int*) ATBBWL_DBGCON_REG_ADDR &= 0x0000ffff;}while(0)

#define ATBBWL_Clear_Monitor_Data() do{*(volatile unsigned int*) ATBBWL_DBGCLR_REG_ADDR = 1;}while(0)

//	Once DBGEN asserts, CYCLE_CNT starts to count
#define ATBBWL_Get_ATB_Cycles(cycle) do{cycle = *(volatile unsigned int*) ATBBWL_CYCCNT_REG_ADDR;}while(0)

#define ATBBWL_Get_ATB_Transaction_Count(count) do{count = *(volatile unsigned int*) ATBBWL_PRTTRANS_REG_ADDR; }while(0)

#define ATBBWL_Enable_Power_Down_Ext() do{ *(volatile unsigned int*)ATBBWL_EXDEN_REG_ADDR = 1; }while(0)
#define ATBBWL_Disable_Power_Down_Ext() do{ *(volatile unsigned int*)ATBBWL_EXDEN_REG_ADDR = 0; }while(0)
#endif  //__TST_NO_ATB_BW_LIMITER__

#endif  //__ATB_LIMITER_HW_H__ 
 
