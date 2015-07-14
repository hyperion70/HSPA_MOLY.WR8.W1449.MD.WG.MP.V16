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
 *    rwg.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intended for Random Waveform Generator (Enhaced PWM) driver.
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
 *
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
#include "drv_features_pwm.h"
#include "drv_comm.h"

#if defined(DRV_PWM_RWG)

#ifndef DRV_PWM_OFF
#include "reg_base.h"
//#include "config_hw.h"
#include "rwg_hw.h"
#include "rwg_sw.h"
#include "drvpdn.h"
#include	"intrCtrl.h"
#include "drv_hisr.h"
#include "custom_hw_default.h"
//#include "swdbg_sw.h"
// MT6238/MT6235 D-cache plan phase #1 begin
#include "cache_sw.h"
//#include "init.h"
#include "kal_general_types.h"
#include "hisr_config.h"
#include "kal_trace.h"
#include "kal_public_api.h"
#include "drv_features.h"
#include "dcl.h"

// MT6238/MT6235 D-cache plan phase #1 end
/*
   This is a "register access" bug of rwg module
   However, turn on PWM main power won't consume too much power, 
   Some registers can NOT be configured before PWM power is turned on (CG/PDN bit is cleared)
*/
#if defined(DRV_PWM_RWG_MAIN_POWER_BEFORE_ACCESS)
#define __PWM_NEED_MAIN_POWER_BEFORE_ACCESS__
#endif // #if defined(DRV_PWM_RWG_MAIN_POWER_BEFORE_ACCESS)

/* __PWM456_SUPPORT_OLD_PWM_API__
   Define for PWM port 4, 5, 6 to support OLD PWM API
   This is for backward compatible, once a platform use port 4 or 5 or 6 to as previous PWM function,
   the upper layer APP or middle layer won't need to change to new PWM interface
*/
#define __PWM456_SUPPORT_OLD_PWM_API__		
														
#if defined DRV_MISC_CLOCK_BASE_1536
   #define RWG_BLOCK_CLOCK		66140000
#else // #if defined DRV_MISC_CLOCK_BASE_1536
   // Non 15.36 Mhz based clock
   #define RWG_BLOCK_CLOCK		52000000
#endif // #if defined DRV_MISC_CLOCK_BASE_1536

#define __DCL_PWM_INTERFACE__
														
#ifdef __DCL_PWM_INTERFACE__

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
#endif
// PWM port 4, 5, 6 support for OLD PWM
#if defined(__PWM456_SUPPORT_OLD_PWM_API__)
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
#endif
kal_uint8 PWM_LEVEL_SAVE[6];
kal_uint32 PWM_FRE_SAVE[6];
kal_uint8  PWM_DUTY_SAVE[6];

#else
kal_uint8 PWM_LEVEL_SAVE[3];
kal_uint32 PWM_FRE_SAVE[3];
kal_uint8  PWM_DUTY_SAVE[3];

#endif // if defined(__PWM456_SUPPORT_OLD_PWM_API__)
// PWM port 4, 5, 6 support for OLD PWM
#else
static kal_uint8  PWM1_LEVEL_SAVE;   /*for MMI usage*/
static kal_uint8  PWM2_LEVEL_SAVE;   /*for MMI usage*/
static kal_uint32 PWM1_FRE_SAVE;   /*for MMI usage*/
static kal_uint32 PWM2_FRE_SAVE;   /*for MMI usage*/
static kal_uint8  PWM1_DUTY_SAVE;   /*for MMI usage*/
static kal_uint8  PWM2_DUTY_SAVE;   /*for MMI usage*/
#ifdef __PWM3_FOR_MMI__
static kal_uint8  PWM3_LEVEL_SAVE;   /*for MMI usage*/
static kal_uint32 PWM3_FRE_SAVE;   /*for MMI usage*/
static kal_uint8  PWM3_DUTY_SAVE;   /*for MMI usage*/
#endif /*__PWM3_FOR_MMI__*/

// PWM port 4, 5, 6 support for OLD PWM
#if defined(__PWM456_SUPPORT_OLD_PWM_API__)
static kal_uint8  PWM4_LEVEL_SAVE;   /*for MMI usage*/
static kal_uint32 PWM4_FRE_SAVE;   /*for MMI usage*/
static kal_uint8  PWM4_DUTY_SAVE;   /*for MMI usage*/
static kal_uint8  PWM5_LEVEL_SAVE;   /*for MMI usage*/
static kal_uint32 PWM5_FRE_SAVE;   /*for MMI usage*/
static kal_uint8  PWM5_DUTY_SAVE;   /*for MMI usage*/
static kal_uint8  PWM6_LEVEL_SAVE;   /*for MMI usage*/
static kal_uint32 PWM6_FRE_SAVE;   /*for MMI usage*/
static kal_uint8  PWM6_DUTY_SAVE;   /*for MMI usage*/
#endif // if defined(__PWM456_SUPPORT_OLD_PWM_API__)

#endif
void PWM_Config_Old(kal_uint8 owner, kal_uint32 pwm_num, kal_uint32 freq, kal_uint8 duty);
#if defined(__PWM456_SUPPORT_OLD_PWM_API__)
void PWM456_Configure_OLD_PWM(kal_uint32 pwm_num, kal_uint32 freq, kal_uint8 duty);
#endif


typedef void (*pwm_cb_fx)(kal_uint32 pwm_num);
typedef void (*pwm_invalid_cb_fx)(kal_uint32 pwm_num, kal_uint8 buf_num);

typedef struct 
{
   kal_uint8 owner;
   kal_uint8 mode;
   kal_bool  is_start;
   pwm_cb_fx pwm_cb;
   pwm_invalid_cb_fx pwm_invalid_cb;
} pwm_handle_s;

static kal_bool pwm_seq_mode_on;
static kal_uint8 pwm_seq_owner;
static pwm_handle_s pwm_handle_array[PWM_COUNT];


#if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__) && !defined(__UBL__)
static kal_uint8 PWM_PDNhandle;
static kal_uint16 PWM_52M_USED_MASK;
static kal_bool   PWM_52M_ENABLE;
#endif

void PWM_Config_Freq_Steps(kal_uint8 owner, kal_uint32 pwm_num, kal_uint32 freq, kal_uint16 steps);
void PWM_Set_Duty(kal_uint8 owner, kal_uint32 pwm_num, kal_uint16 duty);
//void (*pwm_start[6])(void)={PWM1_Start,PWM2_Start,PWM3_Start,PWM4_Start,PWM5_Start,PWM6_Start};
//void (*pwm_stop[6])(void)={PWM1_Stop,PWM2_Stop,PWM3_Stop,PWM4_Stop,PWM5_Stop,PWM6_Stop};
//kal_uint8 (*pwm_get_current_level[6])(void)={PWM1_GetCurrentLevel,PWM2_GetCurrentLevel,PWM3_GetCurrentLevel,PWM4_GetCurrentLevel,PWM5_GetCurrentLevel,PWM6_GetCurrentLevel};
//kal_uint8 (*pwm_get_current_duty[6])(void)={PMW1_GetCurrentDuty,PMW2_GetCurrentDuty,PMW3_GetCurrentDuty,PMW4_GetCurrentDuty,PMW5_GetCurrentDuty,PMW6_GetCurrentDuty};
//kal_uint32 (*pwm_get_current_freq[6])(void)={PMW1_GetCurrentFreq,PMW2_GetCurrentFreq,PMW3_GetCurrentFreq,PMW4_GetCurrentFreq,PMW5_GetCurrentFreq,PMW6_GetCurrentFreq};
//void (*pwm_configOld[6])(kal_uint32,kal_uint8)={PWM1_Configure,PWM2_Configure,PWM3_Configure,PWM4_Configure,PWM5_Configure,PWM6_Configure};


PWMDriver_t rwg_driver=
{
   (DCL_PWM_INIT)PWM_Init,
   (DCL_PWM_CLK_INIT)PWM_CLK_Init,
   (DCL_PWM_START)DCL_PWM_Start,
   (DCL_PWM_STOP)DCL_PWM_Stop,
   (DCL_PWM_GETCURRENT_LEVEL)DCL_PWM_GetCurrent_Level,
   (DCL_PWM_GETCURRENT_FREQ)DCL_PWM_GetCurrentFreq,
   (DCL_PWM_GETCURRENT_DUTY)DCL_PWM_GetCurrentDuty,
   (DCL_PWM_CONFIG_OLD)DCL_PWM_ConfigOld,
   (DCL_PWM_TEST_SELECT)PWM_Test_Select,
   (DCL_PWM_CONFIGURE)PWM_Configure,
   (DCL_PWM_OPEN)PWM_Open,
   (DCL_PWM_CLOSE)PWM_Close,
   (DCL_PWM_SET_BUF_VALID)PWM_Set_Buf_Valid,
   (DCL_PWM_SET_DELAY)PMW_Set_Delay,
   (DCL_PWM_SEQ_OPEN)PWM_Seq_Open,
   (DCL_PWM_SEQ_START)PWM_Seq_Start,
   (DCL_PWM_SEQ_STOP)PWM_Seq_Stop,
   (DCL_PWM_SEQ_CLOSE)PWM_Seq_Close,
   (DCL_PWM_CONFIG_FREQ_STEPS)PWM_Config_Freq_Steps,
   (DCL_PWM_SET_DUTY)PWM_Set_Duty
};

void DCL_PWM_ConfigOld(kal_uint8 owner, kal_uint32 pwm_num, kal_uint32 freq, kal_uint8 duty)
{
 //  pwm_configOld[pwm_num](freq,duty);
    pwm_handle_s   *handle;
if(pwm_num<=PWM3)
{
   handle = pwm_handle_array+(kal_uint32)pwm_num;
   ASSERT(handle->owner != (kal_uint8)PWM_OWNER_NONE);
   PWM_FRE_SAVE[pwm_num]=freq;
   PWM_DUTY_SAVE[pwm_num]=duty;
   PWM_Config_Old(handle->owner, (kal_uint32)pwm_num, freq, duty);
}
else
{
	PWM456_Configure_OLD_PWM((kal_uint32)pwm_num, freq, duty);
	PWM_FRE_SAVE[pwm_num]=freq;
	PWM_DUTY_SAVE[pwm_num]=duty;
}
}

void DCL_PWM_Start(kal_uint8 owner, kal_uint32 pwm_num)
{
 //  pwm_start[pwm_num]();
    pwm_handle_s   *handle;

   handle = pwm_handle_array+(kal_uint32)pwm_num;
   ASSERT(handle->owner != (kal_uint8)PWM_OWNER_NONE);
   PWM_Start(handle->owner, (kal_uint32)pwm_num);
}

void DCL_PWM_Stop(kal_uint8 owner, kal_uint32 pwm_num)
{
//   pwm_stop[pwm_num]();
pwm_handle_s   *handle;

handle = pwm_handle_array+(kal_uint32)pwm_num;
ASSERT(handle->owner != (kal_uint8)PWM_OWNER_NONE);
PWM_Stop(handle->owner, (kal_uint32)pwm_num);

}

kal_uint8 DCL_PWM_GetCurrent_Level(kal_uint8 pwm_num)
{
   return PWM_LEVEL_SAVE[pwm_num];
}

kal_uint8 DCL_PWM_GetCurrentDuty(kal_uint8 pwm_num)
{
  return PWM_DUTY_SAVE[pwm_num];
}

kal_uint32 DCL_PWM_GetCurrentFreq(kal_uint8 pwm_num)
{
  return PWM_FRE_SAVE[pwm_num];
}

static PWM_PDN_Enable(kal_uint32 pwm_num)
{
#if defined(__OLD_PDN_ARCH__)
   #if defined(__APPLICATION_PROCESSOR__)//MT6516 AP btmt
   if (pwm_num == (kal_uint32)PWM1)
   {
      DRV_RWG_WriteReg(CG_CLR0,CG_CON0_PWM1);
   }
   else if (pwm_num == PWM2)
   {
      DRV_RWG_WriteReg(CG_CLR0,CG_CON0_PWM2);
   }
   else
   {
      DRV_RWG_WriteReg(CG_CLR0,CG_CON0_PWM3);
   }
   #else
      #ifndef DRV_PWM_RWG_ONLY_ONE_POWER_BIT
      if (pwm_num == (kal_uint32)PWM1)
      {
         DRV_RWG_WriteReg(DRVPDN_CON1_CLR,DRVPDN_CON1_PWM1);
      }
      else if (pwm_num == PWM2)
      {
         DRV_RWG_WriteReg(DRVPDN_CON1_CLR,DRVPDN_CON1_PWM2);
      }
      else
      {
         DRV_RWG_WriteReg(DRVPDN_CON0_CLR,DRVPDN_CON0_PWM3);
      }
      #endif // #ifndef DRV_PWM_RWG_ONLY_ONE_POWER_BIT
   #endif //#if defined(__APPLICATION_PROCESSOR__)
#else //#if defined(__OLD_PDN_ARCH__)
   #ifdef DRV_PWM_RWG_ONLY_ONE_POWER_BIT
      PDN_CLR(PDN_PWM);
   #else //#ifdef DRV_PWM_RWG_ONLY_ONE_POWER_BIT
      if (pwm_num == (kal_uint32)PWM1){
         PDN_CLR(PDN_PWM);
      }else if (pwm_num == PWM2){
         PDN_CLR(PDN_PWM2);
      }else if (pwm_num == PWM3){
         PDN_CLR(PDN_PWM3);
	   }
   #endif //#ifdef DRV_PWM_RWG_ONLY_ONE_POWER_BIT
#endif //#if defined(__OLD_PDN_ARCH__)
}


/*-----------------------------------------------------------------------
* FUNCTION
*  PWM_Check_Buf_Valid
*
* DESCRIPTION
*   Check which buffer is invalid under the Random mode
*
*
* PARAMETERS
*  pwm_num : ID of the PWM channel
* 
* RETURNS
*  the invalid buffer id of the dual buffer
*
*------------------------------------------------------------------------*/
static kal_uint32 PWM_Check_Buf_Valid(kal_uint32 pwm_num)
{
   kal_uint32 tmp;
   kal_uint32 base_addr;
   kal_uint32 ret_value = 0;

   if (pwm_num <= (kal_uint32)PWM3)
      base_addr = PWM1_VALID + 0x40*pwm_num;
   else
      base_addr = PWM4_VALID + 0x40*(pwm_num-(kal_uint32)PWM4);
   tmp = DRV_RWG_Reg32(base_addr);
   if( !(tmp & PWM_BUF0_VALID_MASK))
   {
      ret_value = (kal_uint32)PWM_BUF_0_INVALID;
   }
   else //if (!(tmp & PWM_BUF1_VALID_MASK))
      ret_value = (kal_uint32)PWM_BUF_1_INVALID;

   return ret_value;
}

/*-----------------------------------------------------------------------
* FUNCTION
*  PWM_Set_Buf_Valid
*
* DESCRIPTION
*   Set buffer status to be valid and update the buffer data.the function is called 
*   when receiving the finish interrupt under the random mode.it is responsible to 
*   call the function to update the buffer of the user.
*
*
* PARAMETERS
*  owner   : the module id of the PWM channel
*  pwm_num : ID of the PWM channel
*  buf_addr: the buffer address of the update data.
*  buf_size: the buffer size.
*  is_buf0 : the flag indicates whether buffer 0 is to be update
* 
* RETURNS
*  None
*
*------------------------------------------------------------------------*/
void PWM_Set_Buf_Valid(kal_uint8 owner, kal_uint32 pwm_num, kal_uint32 *buf_addr, kal_uint16 buf_size, kal_bool is_buf0)
{
   kal_uint32 tmp;
   kal_uint32 base_addr;
   kal_uint32 savedMask;
   pwm_handle_s   *handle;

   handle = pwm_handle_array+pwm_num;
   if ((pwm_num >= (kal_uint32)PWM_COUNT) || (handle->owner!=owner))
   {
      ASSERT(0);
      return;
   }
   if ((handle->mode!=(kal_uint8)PWM_RANDOM_MODE))
   {
      ASSERT(0);
      return;
   }

   // MT6238/MT6235 D-cache plan phase #1 begin
   // Check if ring buffer is cacheable or NOT
   if ( INT_QueryIsCachedRAM((kal_uint32)buf_addr, (kal_uint32)buf_size) ) 
   {
      EXT_ASSERT(0, (kal_uint32)buf_addr, (kal_uint32)buf_size, 0);
   }
   // MT6238/MT6235 D-cache plan phase #1 end

   if (is_buf0)
   {
      if ((0 != buf_addr) && (0 != buf_size))
      {
         base_addr = PWM1_BUF0_BASE_ADDR + 0x40*pwm_num;
         DRV_RWG_WriteReg32(base_addr, buf_addr);
         base_addr = PWM1_BUF0_SIZE + 0x40*pwm_num;
         DRV_RWG_WriteReg32(base_addr, buf_size);
      }
      if (pwm_num <= (kal_uint32)PWM3)
      {
         base_addr = PWM1_VALID + 0x40*pwm_num;
      }
      else
      {
         base_addr = PWM4_VALID + 0x40*(pwm_num-(kal_uint32)PWM4);
      }
      savedMask = SaveAndSetIRQMask();
      tmp = DRV_RWG_Reg32(base_addr);
      tmp |= (PWM_BUF0_VALID_WENABLE|PWM_BUF0_VALID);
      DRV_RWG_WriteReg32(base_addr, tmp);
      RestoreIRQMask(savedMask);
   }
   else
   {
      if ((0 != buf_addr) && (0 != buf_size))
      {
         base_addr = PWM1_BUF1_BASE_ADDR + 0x40*pwm_num;
         DRV_RWG_WriteReg32(base_addr, buf_addr);
         base_addr = PWM1_BUF1_SIZE + 0x40*pwm_num;
         DRV_RWG_WriteReg32(base_addr, buf_size);
      }
      if (pwm_num <= (kal_uint32)PWM3)
      {
         base_addr = PWM1_VALID + 0x40*pwm_num;
      }
      else
      {
         base_addr = PWM4_VALID + 0x40*(pwm_num-(kal_uint32)PWM4);
      }
      savedMask = SaveAndSetIRQMask();
      tmp = DRV_RWG_Reg32(base_addr);
      tmp |= (PWM_BUF1_VALID_WENABLE|PWM_BUF1_VALID);
      DRV_RWG_WriteReg32(base_addr, tmp);
      RestoreIRQMask(savedMask);
   }
}

/*
static void pwm_random_finish_cb(kal_uint32 pwm_num)
{
   kal_uint32 tmp;
   kal_uint32 base_addr;
   kal_uint32 count = 0;

   if (pwm_invalid_cb_array[pwm_num] != NULL)
   {
      if (PWM_BUF_0_INVALID == PWM_Check_Buf_Valid(pwm_num))
         (pwm_invalid_cb_array[pwm_num])(pwm_num, PWM_BUF_0_INVALID);
      else
         (pwm_invalid_cb_array[pwm_num])(pwm_num, PWM_BUF_1_INVALID);
   }
}
*/

/*-----------------------------------------------------------------------
* FUNCTION
*  PWM_LISR
*
* DESCRIPTION
*   The function is the PWM interrupt LISR entry function.
*
*
* PARAMETERS
* None
* 
* RETURNS
*  the invalid buffer id of the dual buffers
*
*------------------------------------------------------------------------*/
void PWM_LISR(void)
{
   IRQMask(IRQ_PWM_CODE);
   drv_active_hisr(DRV_PWM_HISR_ID);
}


/*-----------------------------------------------------------------------
* FUNCTION
*  PWM_HISR
*
* DESCRIPTION
*   the PWM module HISR entry function. there are two possible interrupt type:finish interrupt 
*   or underflow interrupt in PWM module.
*
* PARAMETERS
*  
* 
* RETURNS
*  None
*
*------------------------------------------------------------------------*/
void PWM_HISR(void)
{
   kal_uint32  int_status;
   kal_uint32  index;
   kal_uint32  mask;

   int_status = DRV_RWG_Reg32(PWM_INT_STATUS);
   index = (kal_uint32)PWM1;
   mask = 1;
   while (index < (kal_uint32)PWM_COUNT)
   {
      pwm_handle_s   *handle;
      handle = pwm_handle_array+index;

      if (int_status & mask)
      {
         if (handle->mode==(kal_uint8)PWM_RANDOM_MODE)
         {
            if (handle->pwm_invalid_cb!=NULL)
               handle->pwm_invalid_cb(index, PWM_Check_Buf_Valid(index));
         }
         else
         {
            if (handle->pwm_cb!=NULL)
               handle->pwm_cb(index);
            handle->is_start = KAL_FALSE;
         }
      }
      mask = (mask<<1);
      if (int_status & mask)
      {
         if (handle->mode==(kal_uint8)PWM_RANDOM_MODE)
         {
            if (handle->pwm_cb!=NULL)
               handle->pwm_cb(index);
            handle->is_start = KAL_FALSE;
         }
      }
      mask = (mask<<1);
      index++;
   }
   DRV_RWG_WriteReg32(PWM_INT_ACK, int_status);
   IRQClearInt(IRQ_PWM_CODE);
   IRQUnmask(IRQ_PWM_CODE);

   /*
   if (int_status & PWM1_INT_FINISH_EN_ST)
   {
   }
   if (int_status & PWM2_INT_FINISH_EN_ST)
   {
   }
   if (int_status & PWM3_INT_FINISH_EN_ST)
   {
   }
   if (int_status & PWM4_INT_FINISH_EN_ST)
   {
   }
   if (int_status & PWM5_INT_FINISH_EN_ST)
   {
   }
   if (int_status & PWM6_INT_FINISH_EN_ST)
   {
   }
   if (int_status & PWM1_INT_UNDERFLOW_EN_ST)
   {
   }
   if (int_status & PWM2_INT_UNDERFLOW_EN_ST)
   {
   }
   if (int_status & PWM3_INT_UNDERFLOW_EN_ST)
   {
   }
   if (int_status & PWM4_INT_UNDERFLOW_EN_ST)
   {
   }
   if (int_status & PWM5_INT_UNDERFLOW_EN_ST)
   {
   }
   if (int_status & PWM6_INT_UNDERFLOW_EN_ST)
   {
   }*/
}

/*-----------------------------------------------------------------------
* FUNCTION
*  PWM_Init
*
* DESCRIPTION
*   The PWM driver initialization function. it should be called during Drv_Init stage.
*
* PARAMETERS
*  
* 
* RETURNS
*  None
*
*------------------------------------------------------------------------*/
void PWM_Init(void)
{
   kal_uint8 index;

   for (index=(kal_uint8)PWM1; index < (kal_uint8)PWM_COUNT; index++)
   {
      pwm_handle_s   *handle;

      handle = pwm_handle_array+index;
      handle->owner = (kal_uint8)PWM_OWNER_NONE;
      handle->mode = (kal_uint8)PWM_MODE_COUNT;
      handle->is_start = KAL_FALSE;
      handle->pwm_cb = NULL;
      handle->pwm_invalid_cb = NULL;
   }
 
   #if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__) && !defined(__UBL__)
   PWM_PDNhandle = L1SM_GetHandle();;
   PWM_52M_USED_MASK = 0;
   PWM_52M_ENABLE = KAL_FALSE;
   #endif
   
   pwm_seq_mode_on = KAL_FALSE;
   pwm_seq_owner = (kal_uint8)PWM_OWNER_NONE;
   DRV_Register_HISR(DRV_PWM_HISR_ID, PWM_HISR);
   IRQ_Register_LISR(IRQ_PWM_CODE, PWM_LISR,"PWM handler");
   IRQSensitivity(IRQ_PWM_CODE,LEVEL_SENSITIVE);
   IRQUnmask(IRQ_PWM_CODE);
}

/*-----------------------------------------------------------------------
* FUNCTION
*  PWM_CLK_Init
*
* DESCRIPTION
*   The function is to set the PWM clock source and PWM module clock through the clk_div.
*   
*
* PARAMETERS
*  owner   : the module id of the PWM channel
*  pwm_num : ID of the PWM channel
*  clk_sel : the Clock source of the PWM module.
*  clk_div : The Clock Divisor value.
* 
* RETURNS
*  None
*
* NOTE
*  Before the function is called, the PWM_Open function must be called. 
*------------------------------------------------------------------------*/
void PWM_CLK_Init(kal_uint8 owner, kal_uint32 pwm_num, kal_uint32 clk_sel, kal_uint32 clk_div)
{
   kal_uint32 tmp;
   kal_uint32 base_addr;
   kal_uint32 savedMask;
   pwm_handle_s   *handle;

   handle = pwm_handle_array+pwm_num;
   if ((pwm_num >= (kal_uint32)PWM_COUNT) || (handle->owner!=owner))
   {
      ASSERT(0);
      return;
   }
   if (handle->is_start==KAL_TRUE)
   {
      //ASSERT(0);
      return;
   }
   base_addr = PWM1_CON + 0x40*pwm_num;
   savedMask = SaveAndSetIRQMask();
   
   tmp = DRV_RWG_Reg32(base_addr);
   tmp &= ~(PWM_CON_CLKDIV_MASK|PWM_CON_CLKSEL_MASK);
   tmp |= (PWM_CON_CLKDIV_MASK&(clk_div<<PWM_CON_CLKDIV_SHIFT));
   tmp |= (PWM_CON_CLKSEL_MASK&(clk_sel<<PWM_CON_CLKSEL_SHIFT));
   DRV_RWG_WriteReg32(base_addr,tmp);
   
   #if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__) && !defined(__UBL__)
   if (clk_sel == (kal_uint32)PWM_CLK_SEL_52M)
      PWM_52M_USED_MASK |= (0x0001 << pwm_num);
   else
      PWM_52M_USED_MASK &= (~(0x0001 << pwm_num));
   #endif
   RestoreIRQMask(savedMask);
}

/*-----------------------------------------------------------------------
* FUNCTION
*  PWM_Configure
*
* DESCRIPTION
*   The function is to configure the PWM channel working mode and setting the accoring mode parameter.
*
* PARAMETERS
*  owner   : the module id of the PWM channel
*  pwm_num : ID of the PWM channel
*  mode    : Set the work mode of the PWM channel.
*  para    : The mode parameter.
* 
* RETURNS
*  KAL_FALSE : The configuration is faied
*  KAL_TRUE  : The configuration succeeds
*------------------------------------------------------------------------*/
kal_bool PWM_Configure(kal_uint8 owner, kal_uint32 pwm_num, kal_uint32 mode, void *para)
{
   kal_uint32 tmp;
   kal_uint32 base_addr;
   pwm_handle_s   *handle;
   kal_uint32 savedMask;

   handle = pwm_handle_array+pwm_num;
   if ((pwm_num >= (kal_uint32)PWM_COUNT) || (handle->owner!=owner))
   {
      ASSERT(0);
      return KAL_FALSE;
   }

   PWM_PDN_Enable(pwm_num);

   base_addr = PWM1_CON + 0x40*pwm_num;
   savedMask = SaveAndSetIRQMask();
   tmp = DRV_RWG_Reg32(base_addr);
   switch(mode)
   {
      case PWM_FIFO_MODE:
      {
         pwm_fifo_para_s   *fifo_para;

         fifo_para = (pwm_fifo_para_s *)para;
         if ((fifo_para->high_dur==0) || (fifo_para->low_dur==0)/* || (fifo_para->guard_dur==0)*/)
         {
            RestoreIRQMask(savedMask);
            ASSERT(0);
            return KAL_FALSE;
         }
         tmp &= ~(PWM_CON_SRCSEL_MASK|PWM_CON_MODE_MASK|PWM_CON_IDLE_VALUE_MASK|PWM_CON_GUARD_VALUE_MASK|
                  PWM_CON_STOP_BITPOS_MASK|PWM_CON_OLD_PWM_MODE_MASK);
         tmp |= (PWM_CON_SRCSEL_FIFO |
                 PWM_CON_MODE_PERIODIC |
                 ((fifo_para->idle_output<<PWM_CON_IDLE_VALUE_SHIFT)&PWM_CON_IDLE_VALUE_MASK) |
                 ((fifo_para->guard_output<<PWM_CON_GUARD_VALUE_SHIFT)&PWM_CON_GUARD_VALUE_MASK) |
                 ((fifo_para->stop_bitpos<<PWM_CON_STOP_BITPOS_SHIFT)&PWM_CON_STOP_BITPOS_MASK) |
                 PWM_CON_NEW_PWM_MODE);
         DRV_RWG_WriteReg32(base_addr, tmp);
         RestoreIRQMask(savedMask);
         base_addr = PWM1_SEND_DATA0 + 0x40*pwm_num;
         DRV_RWG_WriteReg32(base_addr, fifo_para->data0);
         base_addr = PWM1_SEND_DATA1 + 0x40*pwm_num;
         DRV_RWG_WriteReg32(base_addr, fifo_para->data1);
         base_addr = PWM1_WAVE_NUM + 0x40*pwm_num;
         DRV_RWG_WriteReg32(base_addr, fifo_para->repeat_count);
         base_addr = PWM1_HDURATION + 0x40*pwm_num;
         DRV_RWG_WriteReg32(base_addr, fifo_para->high_dur);
         base_addr = PWM1_LDURATION + 0x40*pwm_num;
         DRV_RWG_WriteReg32(base_addr, fifo_para->low_dur);
         base_addr = PWM1_GDURATION + 0x40*pwm_num;
         DRV_RWG_WriteReg32(base_addr, fifo_para->guard_dur);
         savedMask = SaveAndSetIRQMask();
         tmp = DRV_RWG_Reg32(PWM_INT_ENABLE);
         tmp &= ~((PWM1_INT_FINISH_EN_MASK|PWM1_INT_UNDERFLOW_EN_MASK) << (pwm_num*2));
         if (fifo_para->pwm_callback != 0)
         {
            tmp |= ((PWM1_INT_FINISH_ENABLE|PWM1_INT_UNDERFLOW_DISABLE) << (pwm_num*2));
         }
         handle->mode = (kal_uint8)PWM_FIFO_MODE;
         handle->pwm_cb = fifo_para->pwm_callback;
         handle->pwm_invalid_cb = NULL;
         DRV_RWG_WriteReg32(PWM_INT_ENABLE, tmp);
         RestoreIRQMask(savedMask);
         //pwm_cb_array[pwm_num*2] = fifo_para->pwm_callback;
         //pwm_cb_array[pwm_num*2+1] = 0;
      }
      break;
   case PWM_MEMO_MODE:
   {
      pwm_memo_para_s   *mem_para;

      mem_para = (pwm_memo_para_s *)para;
      if ((mem_para->high_dur==0) || (mem_para->low_dur==0)/* || (mem_para->guard_dur==0)*/)
      {
         RestoreIRQMask(savedMask);
         return KAL_FALSE;
      }
      //[hardware bug]In memory mode, if input data size is less than 3-32bit, the pwm hardware work abnormal.
      // If use want use less than 3-32bit data, they may use FIFO mode.
      if(mem_para->buf_size <=2)
      {
         ASSERT(0);
      }
        
      // MT6238/MT6235 D-cache plan phase #1 begin
      // Check if ring buffer is cacheable or NOT
	   if ( INT_QueryIsCachedRAM((kal_uint32)mem_para->buf_addr, (kal_uint32)mem_para->buf_size) ) 
      {
         EXT_ASSERT(0, (kal_uint32)mem_para->buf_addr, (kal_uint32)mem_para->buf_size, 0);
      }
      
      // MT6238/MT6235 D-cache plan phase #1 end   
      tmp &= ~(PWM_CON_SRCSEL_MASK|PWM_CON_MODE_MASK|PWM_CON_IDLE_VALUE_MASK|PWM_CON_GUARD_VALUE_MASK|
                  PWM_CON_STOP_BITPOS_MASK|PWM_CON_OLD_PWM_MODE_MASK);
      tmp |= (PWM_CON_SRCSEL_MEM |
              PWM_CON_MODE_PERIODIC |
              ((mem_para->idle_output<<PWM_CON_IDLE_VALUE_SHIFT)&PWM_CON_IDLE_VALUE_MASK) |
              ((mem_para->guard_output<<PWM_CON_GUARD_VALUE_SHIFT)&PWM_CON_GUARD_VALUE_MASK) |
              ((mem_para->stop_bitpos<<PWM_CON_STOP_BITPOS_SHIFT)&PWM_CON_STOP_BITPOS_MASK) |
              PWM_CON_NEW_PWM_MODE);
      DRV_RWG_WriteReg32(base_addr, tmp);
      RestoreIRQMask(savedMask);
      base_addr = PWM1_BUF0_BASE_ADDR + 0x40*pwm_num;
      DRV_RWG_WriteReg32(base_addr, mem_para->buf_addr);
      base_addr = PWM1_BUF0_SIZE + 0x40*pwm_num;
      DRV_RWG_WriteReg32(base_addr, mem_para->buf_size);
      base_addr = PWM1_WAVE_NUM + 0x40*pwm_num;
      DRV_RWG_WriteReg32(base_addr, mem_para->repeat_count);
      base_addr = PWM1_HDURATION + 0x40*pwm_num;
      DRV_RWG_WriteReg32(base_addr, mem_para->high_dur);
      base_addr = PWM1_LDURATION + 0x40*pwm_num;
      DRV_RWG_WriteReg32(base_addr, mem_para->low_dur);
      base_addr = PWM1_GDURATION + 0x40*pwm_num;
      DRV_RWG_WriteReg32(base_addr, mem_para->guard_dur);
      savedMask = SaveAndSetIRQMask();
      
      tmp = DRV_RWG_Reg32(PWM_INT_ENABLE);
      tmp &= ~((PWM1_INT_FINISH_EN_MASK|PWM1_INT_UNDERFLOW_EN_MASK) << (pwm_num*2));
      if (mem_para->pwm_callback != 0)
      {
         tmp |= ((PWM1_INT_FINISH_ENABLE|PWM1_INT_UNDERFLOW_DISABLE) << (pwm_num*2));
      }
      handle->mode = (kal_uint8)PWM_MEMO_MODE;
      handle->pwm_cb = mem_para->pwm_callback;
      handle->pwm_invalid_cb = NULL;
      DRV_RWG_WriteReg32(PWM_INT_ENABLE, tmp);
      RestoreIRQMask(savedMask);
   }
   break;
   case PWM_OLD_MODE:
   {
      pwm_old_para_s   *old_para;

      if (pwm_num > (kal_uint32)PWM3)
      {
         RestoreIRQMask(savedMask);
         return KAL_FALSE;
      }
      old_para = (pwm_old_para_s *)para;

      tmp &= ~(PWM_CON_IDLE_VALUE_MASK|PWM_CON_GUARD_VALUE_MASK|PWM_CON_OLD_PWM_MODE_MASK);
      tmp |= (((old_para->idle_output<<PWM_CON_IDLE_VALUE_SHIFT)&PWM_CON_IDLE_VALUE_MASK) |
             ((old_para->guard_output<<PWM_CON_GUARD_VALUE_SHIFT)&PWM_CON_GUARD_VALUE_MASK) |
             PWM_CON_OLD_PWM_MODE);
      DRV_RWG_WriteReg32(base_addr, tmp);
      RestoreIRQMask(savedMask);
      base_addr = PWM1_DATA_WIDTH + 0x40*pwm_num;
      DRV_RWG_WriteReg32(base_addr, old_para->data_width);
      base_addr = PWM1_THRESH + 0x40*pwm_num;
      DRV_RWG_WriteReg32(base_addr, old_para->threshold);
      base_addr = PWM1_WAVE_NUM + 0x40*pwm_num;
      DRV_RWG_WriteReg32(base_addr, old_para->repeat_count);
      base_addr = PWM1_GDURATION + 0x40*pwm_num;
      DRV_RWG_WriteReg32(base_addr, old_para->guard_dur);
      savedMask = SaveAndSetIRQMask();
      tmp = DRV_RWG_Reg32(PWM_INT_ENABLE);
      tmp &= ~((PWM1_INT_FINISH_EN_MASK|PWM1_INT_UNDERFLOW_EN_MASK) << (pwm_num*2));
      if (old_para->pwm_callback != 0)
      {
         tmp |= ((PWM1_INT_FINISH_ENABLE|PWM1_INT_UNDERFLOW_DISABLE) << (pwm_num*2));
      }
      handle->mode = (kal_uint8)PWM_OLD_MODE;
      handle->pwm_cb = old_para->pwm_callback;
      handle->pwm_invalid_cb = NULL;
      DRV_RWG_WriteReg32(PWM_INT_ENABLE, tmp);
      RestoreIRQMask(savedMask);
   }
   break;
   case PWM_RANDOM_MODE:
   {
      pwm_random_para_s   *random_para;

      random_para = (pwm_random_para_s *)para;
      //[hardware bug]In memory mode, if input data size is less than 3-32bit, the pwm hardware work abnormal.
      // If use want use less than 3-32bit data, they may use FIFO mode.
      if(random_para->buf0_size <=2 && random_para->buf1_size <=2)
      {
         ASSERT(0);
      }
         
      // MT6238/MT6235 D-cache plan phase #1 begin
      // Check if ring buffer is cacheable or NOT
      if ( INT_QueryIsCachedRAM((kal_uint32)random_para->buf0_addr, (kal_uint32)random_para->buf0_size) ) 
      {
         EXT_ASSERT(0, (kal_uint32)random_para->buf0_addr, (kal_uint32)random_para->buf0_size, 0);
      }
      if ( INT_QueryIsCachedRAM((kal_uint32)random_para->buf1_addr, (kal_uint32)random_para->buf1_size) )
      {
         EXT_ASSERT(0, (kal_uint32)random_para->buf1_addr, (kal_uint32)random_para->buf1_size, 0);
      }
      
      // MT6238/MT6235 D-cache plan phase #1 end   
      if ((random_para->high_dur==0) || (random_para->low_dur==0) 
         || (random_para->buf0_size==0)|| (random_para->buf1_size==0))
      {
         RestoreIRQMask(savedMask);
         return KAL_FALSE;
      }
      
      tmp &= ~(PWM_CON_SRCSEL_MASK|PWM_CON_MODE_MASK|PWM_CON_IDLE_VALUE_MASK|PWM_CON_OLD_PWM_MODE_MASK);
      tmp |= (PWM_CON_SRCSEL_MEM |
              PWM_CON_MODE_RANDOM |
              ((random_para->idle_output<<PWM_CON_IDLE_VALUE_SHIFT)&PWM_CON_IDLE_VALUE_MASK) |
              PWM_CON_NEW_PWM_MODE);
      DRV_RWG_WriteReg32(base_addr, tmp);
      RestoreIRQMask(savedMask);
      base_addr = PWM1_BUF0_BASE_ADDR + 0x40*pwm_num;
      DRV_RWG_WriteReg32(base_addr, random_para->buf0_addr);
      base_addr = PWM1_BUF0_SIZE + 0x40*pwm_num;
      DRV_RWG_WriteReg32(base_addr, random_para->buf0_size);
      base_addr = PWM1_BUF1_BASE_ADDR + 0x40*pwm_num;
      DRV_RWG_WriteReg32(base_addr, random_para->buf1_addr);
      base_addr = PWM1_BUF1_SIZE + 0x40*pwm_num;
      DRV_RWG_WriteReg32(base_addr, random_para->buf1_size);
      base_addr = PWM1_HDURATION + 0x40*pwm_num;
      DRV_RWG_WriteReg32(base_addr, random_para->high_dur);
      base_addr = PWM1_LDURATION + 0x40*pwm_num;
      DRV_RWG_WriteReg32(base_addr, random_para->low_dur);
      if (pwm_num <= (kal_uint32)PWM3)
         base_addr = PWM1_VALID + 0x40*pwm_num;
      else
         base_addr = PWM4_VALID + 0x40*(pwm_num-(kal_uint32)PWM4);
      tmp = (PWM_BUF0_VALID|PWM_BUF0_VALID_WENABLE|PWM_BUF1_VALID|PWM_BUF1_VALID_WENABLE);
      DRV_RWG_WriteReg32(base_addr, tmp);
      savedMask = SaveAndSetIRQMask();
      tmp = DRV_RWG_Reg32(PWM_INT_ENABLE);
      tmp &= ~((PWM1_INT_FINISH_EN_MASK|PWM1_INT_UNDERFLOW_EN_MASK) << (pwm_num*2));
      if (random_para->pwm_invalid_cb != 0)
         tmp |= (PWM1_INT_FINISH_ENABLE << (pwm_num*2));
      if (random_para->pwm_underflow_cb != 0)
         tmp |= (PWM1_INT_UNDERFLOW_ENABLE << (pwm_num*2));
      handle->mode = (kal_uint8)PWM_RANDOM_MODE;
      handle->pwm_cb = random_para->pwm_underflow_cb;
      handle->pwm_invalid_cb = random_para->pwm_invalid_cb;
      DRV_RWG_WriteReg32(PWM_INT_ENABLE, tmp);
      RestoreIRQMask(savedMask);
         //pwm_cb_array[pwm_num*2] = pwm_random_finish_cb;
         //pwm_invalid_cb_array[pwm_num] = random_para->pwm_invalid_cb;
         //pwm_cb_array[pwm_num*2+1] = random_para->pwm_underflow_cb;
   }
   break;
   default:
      RestoreIRQMask(savedMask);
      return KAL_FALSE;
   }
   return KAL_TRUE;
}

/*-----------------------------------------------------------------------
* FUNCTION
*  PWM_Start
*
* DESCRIPTION
*   The function is to Start the PWM channel output.It is called after all the configuration finished
*
* PARAMETERS
*  owner   : the module id of the PWM channel
*  pwm_num : ID of the PWM channel
* 
* RETURNS
* None
*
*------------------------------------------------------------------------*/
void PWM_Start(kal_uint8 owner, kal_uint32 pwm_num)
{
   kal_uint32 tmp;
   pwm_handle_s   *handle;
   kal_uint32 savedMask;

   handle = pwm_handle_array+pwm_num;
   if ( (handle->owner!=owner) || 
      ((pwm_seq_mode_on==KAL_FALSE) && (pwm_num >= (kal_uint32)PWM_COUNT)) || 
      ((pwm_seq_mode_on==KAL_TRUE) && (pwm_num >= (kal_uint32)PWM3)) )
   {
      ASSERT(0);
      return;
   }
   if (handle->is_start==KAL_TRUE)
   {
      //ASSERT(0);
      return ;
   }
   
   PWM_PDN_Enable(pwm_num);
   //Power on?
   savedMask = SaveAndSetIRQMask();
   handle->is_start=KAL_TRUE;
   tmp = DRV_RWG_Reg32(PWM_ENABLE);
   
   if (!(tmp & 0x003f)){
   #if defined(__OLD_PDN_ARCH__)
      #if defined(__OLD_PDN_DEFINE__)
      DRV_RWG_WriteReg(DRVPDN_CON0_CLR,DRVPDN_CON0_PWM);
      #elif defined(__APPLICATION_PROCESSOR__)//MT6516 AP btmt
      DRV_RWG_WriteReg(CG_CLR0,CG_CON0_PWM);
      #else // #if defined(__OLD_PDN_DEFINE__)
      DRV_RWG_WriteReg(CG_CLR0,CG_CON0_PWM);
      #endif // #if defined(__OLD_PDN_DEFINE__)
   #endif //#if defined(__OLD_PDN_ARCH__)
   // MT6253 do not have PWM PDN bit.
   }

   tmp &= ~(PWM1_ENABLE_MASK << pwm_num);
   tmp |= (PWM1_ENABLE << pwm_num);
   // Disable sleep mode before we really enable PWM functionality
   #if (defined(MTK_SLEEP_ENABLE) && !defined(__FUE__) && !defined(__UBL__))
   if ((PWM_52M_ENABLE == KAL_FALSE) && (tmp & PWM_52M_USED_MASK))
   {
      PWM_52M_ENABLE = KAL_TRUE;
      L1SM_SleepDisable(PWM_PDNhandle);
   }
   #endif
   DRV_RWG_WriteReg32(PWM_ENABLE, tmp);
   RestoreIRQMask(savedMask);
}
/*-----------------------------------------------------------------------
* FUNCTION
*  PWM_Stop
*
* DESCRIPTION
*   The function is to stop the PWM channel output.
*
* PARAMETERS
*  owner   : the module id of the PWM channel
*  pwm_num : ID of the PWM channel
* 
* RETURNS
* None
*
*------------------------------------------------------------------------*/
void PWM_Stop(kal_uint8 owner, kal_uint32 pwm_num)
{
   kal_uint32 tmp;
   pwm_handle_s   *handle;
   kal_uint32 savedMask;

   handle = pwm_handle_array+pwm_num;
   if ( (handle->owner!=owner) || 
      ((pwm_seq_mode_on==KAL_FALSE) && (pwm_num >= (kal_uint32)PWM_COUNT)) || 
      ((pwm_seq_mode_on==KAL_TRUE) && (pwm_num >= (kal_uint32)PWM3)) )
   {
      ASSERT(0);
      return;
   }
   savedMask = SaveAndSetIRQMask();
   handle->is_start=KAL_FALSE;
   tmp = DRV_RWG_Reg32(PWM_ENABLE);
   tmp &= ~(PWM1_ENABLE_MASK << pwm_num);
   tmp |= (PWM1_DISABLE << pwm_num);
   DRV_RWG_WriteReg32(PWM_ENABLE, tmp);

   #if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__) && !defined(__UBL__)
   if ((PWM_52M_ENABLE == KAL_TRUE) && !(tmp & PWM_52M_USED_MASK))
   {
      PWM_52M_ENABLE = KAL_FALSE;
      L1SM_SleepEnable(PWM_PDNhandle);
   }
   #endif
   RestoreIRQMask(savedMask);

   #if !defined(IC_BURNIN_TEST) && !defined(IC_MODULE_TEST) //BTMT may not have TDMA timer
   if ( !(tmp & 0x003c) || pwm_num == (kal_uint32)PWM1 || pwm_num == (kal_uint32)PWM2)
   {
      // PWM need delay to finish the pulse after set disable, 
      // otherwise power down may cause PWM stay in error idle status
      // in others words, 
      // if pulse status in high and power down in the same time, status will keep in high afterward.
      // it is due to PWM may use 32K to create pulse and also use 32K to update status.
      // but PDN_CON command working in 52M domain, it may cut the disable sequence.
      #if !defined(__FUE__) && !defined(__UBL__)
      //FOTA do not have drv_get_duration_tick( )
      kal_uint32 cnt1, delay=0;
      cnt1 = drv_get_current_time();
      while(drv_get_duration_tick(cnt1, drv_get_current_time()) < 6)
      {
         delay++;
         if(delay==0xFFFF)
            break;
      }
      #else
      kal_uint32 tqcnt1, tqcnt2;
      tqcnt1 = DRV_RWG_Reg(TDMA_base); //*(volatile kal_uint16 *)(TDMA_base + 0x00);
      tqcnt2 = tqcnt1;
      while( (kal_uint32)(tqcnt2 - tqcnt1) < 180) 
      {  
         // even ticks2 overflow still work on unsigned operation
         tqcnt2 = DRV_RWG_Reg(TDMA_base); //*(volatile kal_uint16 *)(TDMA_base + 0x00);
      }
      #endif //#if !defined(__FUE__) && !defined(__UBL__)
   }
   #endif //#if !defined(IC_BURNIN_TEST) && !defined(IC_MODULE_TEST)
   
   #ifndef __PWM_NEED_MAIN_POWER_BEFORE_ACCESS__
   if (!(tmp & 0x003f))
   {
      #if defined(__OLD_PDN_ARCH__)
      #if defined(__OLD_PDN_DEFINE__)
      DRV_RWG_WriteReg(DRVPDN_CON0_SET,DRVPDN_CON0_PWM);
      #else // #if defined(__OLD_PDN_DEFINE__)
      DRV_RWG_WriteReg(CG_SET0,CG_CON0_PWM);
      #endif // #if defined(__OLD_PDN_DEFINE__)
      #endif  //#if defined(__OLD_PDN_ARCH__)
   }
   #endif // #ifndef __PWM_NEED_MAIN_POWER_BEFORE_ACCESS__

   #if defined(DRV_PWM_RWG_ONLY_ONE_POWER_BIT)
   #if !defined(__OLD_PDN_ARCH__)
   savedMask = SaveAndSetIRQMask();
   tmp = DRV_RWG_Reg32(PWM_ENABLE);
   if (!(tmp & 0x003F))
      PDN_SET(PDN_PWM);
   RestoreIRQMask(savedMask);
   #endif //#if !defined(__OLD_PDN_ARCH__)
   #else //#if defined(DRV_PWM_RWG_ONLY_ONE_POWER_BIT)
   savedMask = SaveAndSetIRQMask();
   tmp = DRV_RWG_Reg32(PWM_ENABLE);
   if ((pwm_num >= (kal_uint32)PWM3) && (!(tmp & 0x003c)))
   {
      #if defined(__OLD_PDN_ARCH__)
      #if defined(__APPLICATION_PROCESSOR__)//MT6516 AP btmt
      DRV_RWG_WriteReg(CG_SET0,CG_CON0_PWM3);
      #else
      DRV_RWG_WriteReg(DRVPDN_CON0_SET,DRVPDN_CON0_PWM3);
      #endif//#if defined(__APPLICATION_PROCESSOR__)//MT6516 AP btmt
      #else //#if defined(__OLD_PDN_ARCH__)
      PDN_SET(PDN_PWM3);
      #endif //#if defined(__OLD_PDN_ARCH__)
   }
   RestoreIRQMask(savedMask);
   //Power off?
   #if defined(__OLD_PDN_ARCH__)
   #if defined(__APPLICATION_PROCESSOR__)//MT6516 AP btmt
   if (pwm_num == (kal_uint32)PWM1)
   {
      DRV_RWG_WriteReg(CG_SET0,CG_CON0_PWM1);
   }
   else if (pwm_num == (kal_uint32)PWM2)
   {
      DRV_RWG_WriteReg(CG_SET0,CG_CON0_PWM2);
   }
   #else
   if (pwm_num == (kal_uint32)PWM1)
   {
      DRV_RWG_WriteReg(DRVPDN_CON1_SET,DRVPDN_CON1_PWM1);
   }
   else if (pwm_num == (kal_uint32)PWM2)
   {
      DRV_RWG_WriteReg(DRVPDN_CON1_SET,DRVPDN_CON1_PWM2);
   }
   #endif//#if defined(__APPLICATION_PROCESSOR__)//MT6516 AP btmt
   #else //#if defined(__OLD_PDN_ARCH__)
   if (pwm_num == (kal_uint32)PWM1)
   {
      PDN_SET(PDN_PWM1);
   }
   else if (pwm_num == (kal_uint32)PWM2)
   {
      PDN_SET(PDN_PWM2);
   }
   #endif //#if defined(__OLD_PDN_ARCH__)
   #endif // #if defined(DRV_PWM_RWG_ONLY_ONE_POWER_BIT)
}

/*-----------------------------------------------------------------------
* FUNCTION
*  PMW_Set_Delay
*
* DESCRIPTION
*   The function is to set the delay time during the adjacent channels under the Sequential mode.
*
* PARAMETERS
*  owner   : the module id of the PWM channel
*  pwm_num : ID of the PWM channel
*  clk_sel : the clock unit of the delay_cnt
*  delay_cnt: the delay clock count of the two channels.
*
* RETURNS
* None
*
*------------------------------------------------------------------------*/
void PMW_Set_Delay(kal_uint8 owner, kal_uint32 pwm_num, kal_uint32 clk_sel, kal_uint16 delay_cnt)
{
   kal_uint32 clk_delay_sel;

   if ((owner!=pwm_seq_owner) || (pwm_seq_mode_on==KAL_FALSE))
   {
      ASSERT(0);
      return;
   }
   if ((pwm_num < PWM4) || (pwm_num >= (kal_uint32)PWM_COUNT))
      return;
   
   clk_delay_sel = (clk_sel==(kal_uint32)PWM_CLK_SEL_52M) ? PWM_DELAY_CLKSEL_52M : PWM_DELAY_CLKSEL_32K;
   DRV_RWG_WriteReg32((PWM4_DELAY+(pwm_num-(kal_uint32)PWM4)*4), (clk_delay_sel| (delay_cnt&PWM_DELAY_DURATON_MASK)));
}

/*-----------------------------------------------------------------------
* FUNCTION
*  PWM_Seq_Start
*
* DESCRIPTION
*   The function is to enable PWM output under the Sequential mode.
*
* PARAMETERS
*  owner   : the module id of the PWM channel
*  en_cnt  : the PWM Channel Group of the Sequential mode
*
* RETURNS
* None
*
*------------------------------------------------------------------------*/
void PWM_Seq_Start(kal_uint8 owner, kal_uint8 en_cnt)
{
   kal_uint32 en_reg;
   kal_uint32 saved_en_reg;
   kal_uint32 savedMask;
   pwm_handle_s   *handle;

   if ((owner!=pwm_seq_owner) || (pwm_seq_mode_on==KAL_FALSE))
   {
      ASSERT(0);
      return;
   }
   ASSERT(en_cnt&0x01);
   savedMask = SaveAndSetIRQMask();
   en_reg = DRV_RWG_Reg32(PWM_ENABLE);
   saved_en_reg = en_reg;
   en_reg &= (PWM1_ENABLE_MASK|PWM2_ENABLE_MASK);
   handle = pwm_handle_array+(kal_uint32)PWM3;
   if (en_cnt&0x01)
   {
      en_reg |= PWM3_ENABLE;
      handle->is_start=KAL_TRUE;
   }
   else
      handle->is_start=KAL_FALSE;
   handle++;
   if (en_cnt&0x02)
   {
      en_reg |= PWM4_ENABLE;
      handle->is_start=KAL_TRUE;
   }
   else
      handle->is_start=KAL_FALSE;
   handle++;
   if (en_cnt&0x04)
   {
      en_reg |= PWM5_ENABLE;
      handle->is_start=KAL_TRUE;
   }
   else
      handle->is_start=KAL_FALSE;
   handle++;
   if (en_cnt&0x08)
   {
      en_reg |= PWM6_ENABLE;
      handle->is_start=KAL_TRUE;
   }
   else
      handle->is_start=KAL_FALSE;
   #if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__) && !defined(__UBL__)
   if ((PWM_52M_ENABLE == KAL_FALSE) && (en_reg & PWM_52M_USED_MASK))
   {
      PWM_52M_ENABLE = KAL_TRUE;
      L1SM_SleepDisable(PWM_PDNhandle);
   }
   #endif
   if (!(saved_en_reg & 0x003f))
   {
      #if defined(__OLD_PDN_ARCH__)
      #if defined(__OLD_PDN_DEFINE__)
      DRV_RWG_WriteReg(DRVPDN_CON0_CLR,DRVPDN_CON0_PWM);
      #else // #if defined(__OLD_PDN_DEFINE__)
      DRV_RWG_WriteReg(CG_CLR0,CG_CON0_PWM);
      #endif // #if defined(__OLD_PDN_DEFINE__)
      #endif //#if defined(__OLD_PDN_ARCH__)
   }

   #ifndef DRV_PWM_RWG_ONLY_ONE_POWER_BIT
   #if defined(__OLD_PDN_ARCH__)
   #if defined(__APPLICATION_PROCESSOR__)//MT6516 AP btmt
      DRV_RWG_WriteReg(CG_CLR0,CG_CON0_PWM3);
   #else
      DRV_RWG_WriteReg(DRVPDN_CON0_CLR,DRVPDN_CON0_PWM3);
   #endif //#if defined(__APPLICATION_PROCESSOR__)//MT6516 AP btmt
   #else //#if defined(__OLD_PDN_ARCH__)
      PDN_CLR(PDN_PWM3);
   #endif //#if defined(__OLD_PDN_ARCH__)
   #endif // #ifndef DRV_PWM_RWG_ONLY_ONE_POWER_BIT

   DRV_RWG_WriteReg32(PWM_ENABLE, (en_reg|PWM_SEQ_MODE_ON));
   RestoreIRQMask(savedMask);
}

/*-----------------------------------------------------------------------
* FUNCTION
*  PWM_Seq_Stop
*
* DESCRIPTION
*   The function is to stop PWM output under the Sequential mode.
*
* PARAMETERS
*  owner   : the module id of the PWM channel
*
* RETURNS
* None
*
*------------------------------------------------------------------------*/
void PWM_Seq_Stop(kal_uint8 owner)
{
   kal_uint32 savedMask;
   kal_uint32 en_reg;
   pwm_handle_s   *handle;
   kal_uint8   index;

   if ((owner!=pwm_seq_owner) || (pwm_seq_mode_on==KAL_FALSE))
   {
      ASSERT(0);
      return;
   }
   savedMask = SaveAndSetIRQMask();
   en_reg = DRV_RWG_Reg32(PWM_ENABLE);
   en_reg &= (PWM1_ENABLE_MASK|PWM2_ENABLE_MASK);
   DRV_RWG_WriteReg32(PWM_ENABLE, (en_reg|PWM3_DISABLE|PWM4_DISABLE|PWM5_DISABLE|PWM6_DISABLE|PWM_SEQ_MODE_OFF));
   for (index=(kal_uint8)PWM3; index <= (kal_uint8)PWM6; index++)
   {
      handle = pwm_handle_array+index;
      handle->is_start=KAL_FALSE;
   }
   
   #ifndef __PWM_NEED_MAIN_POWER_BEFORE_ACCESS__
   if (!(en_reg & 0x003f))
   {
      #if defined(__OLD_PDN_ARCH__)
      #if defined(__OLD_PDN_DEFINE__)
      DRV_RWG_WriteReg(DRVPDN_CON0_SET,DRVPDN_CON0_PWM);
      #else // #if defined(__OLD_PDN_DEFINE__)
      DRV_RWG_WriteReg(CG_SET0,CG_CON0_PWM);
      #endif // #if defined(__OLD_PDN_DEFINE__)
      #endif //#if defined(__OLD_PDN_ARCH__)
   }
   #endif // #ifndef __PWM_NEED_MAIN_POWER_BEFORE_ACCESS__

   #ifndef DRV_PWM_RWG_ONLY_ONE_POWER_BIT
   #if defined(__OLD_PDN_ARCH__)
   #if defined(__APPLICATION_PROCESSOR__)//MT6516 AP btmt
      DRV_RWG_WriteReg(CG_SET0,CG_CON0_PWM3);
   #else
      DRV_RWG_WriteReg(DRVPDN_CON0_SET,DRVPDN_CON0_PWM3);
   #endif //#if defined(__APPLICATION_PROCESSOR__)//MT6516 AP btmt
   #else //#if defined(__OLD_PDN_ARCH__)
      PDN_SET(PDN_PWM3);
   #endif //#if defined(__OLD_PDN_ARCH__)
   #endif // #ifndef DRV_PWM_RWG_ONLY_ONE_POWER_BIT

   #if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__) && !defined(__UBL__)
   if ((PWM_52M_ENABLE == KAL_TRUE) && !(en_reg & PWM_52M_USED_MASK))
   {
      PWM_52M_ENABLE = KAL_FALSE;
      L1SM_SleepEnable(PWM_PDNhandle);
   }
   #endif
   RestoreIRQMask(savedMask);
}

/*-----------------------------------------------------------------------
* FUNCTION
*  PWM_Open
*
* DESCRIPTION
*   The function is to Open PWM channel.
*
* PARAMETERS
*  owner   : the module id of the PWM channel
*  pwm_num : the ID of the PWM channel
* RETURNS
*  The return value indicates the result of the operation.
* 
* NOTE
*  the function should be called before any other configuration function.
*
*------------------------------------------------------------------------*/
kal_bool PWM_Open(kal_uint8 owner, kal_uint32 pwm_num)
{
   pwm_handle_s   *handle;

   #ifdef __PWM_NEED_MAIN_POWER_BEFORE_ACCESS__
   /* For register access bug, we have to turn on the PWM main power first. 
      Should be remove afterward. */
   #if defined(__OLD_PDN_ARCH__)
   #if defined(__OLD_PDN_DEFINE__)
   DRV_RWG_WriteReg(DRVPDN_CON0_CLR,DRVPDN_CON0_PWM);
   #else // #if defined(__OLD_PDN_DEFINE__)
   DRV_RWG_WriteReg(CG_CLR0,CG_CON0_PWM);
   #endif // #if defined(__OLD_PDN_DEFINE__)
   #endif //#if defined(__OLD_PDN_ARCH__)
   #endif // #ifndef __PWM_NEED_MAIN_POWER_BEFORE_ACCESS__

   handle = pwm_handle_array+pwm_num;
   if ((pwm_num >= (kal_uint32)PWM_COUNT) || (handle->owner!=(kal_uint8)PWM_OWNER_NONE))
   {
      ASSERT(0);
      return KAL_FALSE;
   }
   handle->owner = owner;
   handle->mode = (kal_uint8)PWM_MODE_COUNT;
   handle->is_start = KAL_FALSE;
   handle->pwm_cb = NULL;
   handle->pwm_invalid_cb = NULL;
   return KAL_TRUE;
}

/*-----------------------------------------------------------------------
* FUNCTION
*  PWM_Close
*
* DESCRIPTION
*   The function is to close the PWM channel.it should be called after stop the PWM channel.
*
* PARAMETERS
*  owner   : the module id of the PWM channel
*  pwm_num : the ID of the PWM channel
* 
* RETURNS
*  The return value indicates the result of the operation.
* 
*
*------------------------------------------------------------------------*/
kal_bool PWM_Close(kal_uint8 owner, kal_uint32 pwm_num)
{
   pwm_handle_s   *handle;

   /*
      Do NOT need to turn off main power at this stage
      main power should be turned off at PWM_Stop stage if no PWM channel is running
   */
   handle = pwm_handle_array+pwm_num;
   if ((pwm_num >= (kal_uint32)PWM_COUNT) || (handle->owner!=owner))
   {
      ASSERT(0);
      return KAL_FALSE;
   }
   if (handle->is_start == KAL_TRUE)
   {
      PWM_Stop(owner, pwm_num);
      handle->is_start = KAL_FALSE;
   }
   handle->owner = (kal_uint8)PWM_OWNER_NONE;
   handle->mode = (kal_uint8)PWM_MODE_COUNT;
   handle->pwm_cb = NULL;
   handle->pwm_invalid_cb = NULL;
   return KAL_TRUE;
}

/*-----------------------------------------------------------------------
* FUNCTION
*  PWM_Seq_Open
*
* DESCRIPTION
*   The function is to open the PWM channel under the Sequential mode.
*
* PARAMETERS
*  owner   : the user module id of the PWM channel
* 
* RETURNS
*  The return value indicates the result of the operation.
* 
*
*------------------------------------------------------------------------*/
kal_bool PWM_Seq_Open(kal_uint8 owner)
{
   kal_uint32     idx;
   pwm_handle_s   *handle;

   if (pwm_seq_owner!=(kal_uint8)PWM_OWNER_NONE)
   {
      ASSERT(0);
      return KAL_FALSE;
   }
   
   #ifdef __PWM_NEED_MAIN_POWER_BEFORE_ACCESS__
   /* For register access bug, we have to turn on the PWM main power first. 
      Should be remove afterward. */
   #if defined(__OLD_PDN_ARCH__)
   #if defined(__OLD_PDN_DEFINE__)
   DRV_RWG_WriteReg(DRVPDN_CON0_CLR,DRVPDN_CON0_PWM);
   #else // #if defined(__OLD_PDN_DEFINE__)
   DRV_RWG_WriteReg(CG_CLR0,CG_CON0_PWM);
   #endif // #if defined(__OLD_PDN_DEFINE__)
   #endif //#if defined(__OLD_PDN_ARCH__)
   #endif // #ifndef __PWM_NEED_MAIN_POWER_BEFORE_ACCESS__
   
   handle = pwm_handle_array+(kal_uint32)PWM3;
   for (idx=(kal_uint32)PWM3; idx < (kal_uint32)PWM_COUNT; idx++)
   {
      handle->owner = owner;
      handle->mode = (kal_uint8)PWM_MODE_COUNT;
      handle->is_start = KAL_FALSE;
      handle->pwm_cb = NULL;
      handle->pwm_invalid_cb = NULL;
      handle++;
   }
   pwm_seq_owner = owner;
   pwm_seq_mode_on = KAL_TRUE;
   return KAL_TRUE;
}
/*-----------------------------------------------------------------------
* FUNCTION
*  PWM_Seq_Close
*
* DESCRIPTION
*   The function is to Close the PWM channel under the Sequential mode.
*
* PARAMETERS
*  owner   : the user module id of the PWM channel
* 
* RETURNS
*  The return value indicates the result of the operation.
* 
* NOTE
* The function should be used under the sequential mode not the normal mode.
*
*------------------------------------------------------------------------*/
kal_bool PWM_Seq_Close(kal_uint8 owner)
{
   kal_uint32     idx;
   pwm_handle_s   *handle;

   /*
      Do NOT need to turn off main power at this stage
      main power should be turned off at PWM_Stop stage if no PWM channel is running
   */
   if (pwm_seq_owner!=owner)
   {
      ASSERT(0);
      return KAL_FALSE;
   }
   handle = pwm_handle_array+(kal_uint32)PWM3;
   for (idx=(kal_uint32)PWM3; idx < (kal_uint32)PWM_COUNT; idx++)
   {
      if (handle->is_start == KAL_TRUE)
      {
         PWM_Stop(owner, idx);
         handle->is_start = KAL_FALSE;
      }
      handle->owner = (kal_uint8)PWM_OWNER_NONE;
      handle->mode = (kal_uint8)PWM_MODE_COUNT;
      handle->pwm_cb = NULL;
      handle->pwm_invalid_cb = NULL;
      handle++;
   }
   pwm_seq_owner = (kal_uint8)PWM_OWNER_NONE;
   pwm_seq_mode_on = KAL_FALSE;
   return KAL_TRUE;
}

/*-----------------------------------------------------------------------
* FUNCTION
*  PWM_Config_Old
*
* DESCRIPTION
*   The function is to configure the PWM channel working under the old mode.
*
* PARAMETERS
*  owner   : the user module id of the PWM channel
*  pwm_num : the id of the PWM channel
*  freq    : the PWM channel output frequency.
*  duty    : the duty cycle of the high level under the periodical output.
*
* RETURNS
*  none
* 
* NOTE
* the duty 50 indicates 50% high level occupied the entire period output.
*
*------------------------------------------------------------------------*/
void PWM_Config_Old(kal_uint8 owner, kal_uint32 pwm_num, kal_uint32 freq, kal_uint8 duty)
{
   kal_uint32 clock;
   kal_uint32 tmp;
   kal_uint16 clkdiv;
   kal_uint16 reg;
   pwm_old_para_s   old_para;
   pwm_old_para_s   *old_para_p;
      
   old_para_p = &old_para;
   ASSERT(duty <= 100);
   reg = DRV_RWG_Reg(PWM1_CON+0x40*pwm_num);
   clkdiv = (1 << ((reg & PWM_CON_CLKDIV_MASK)>>PWM_CON_CLKDIV_SHIFT));
   
   if (reg & PWM_CON_CLKSEL_MASK)
      clock = 32000;
   else
      clock = RWG_BLOCK_CLOCK;
   
   clock = clock/clkdiv;

   if(0==freq)
      tmp = clock/(freq+1);
   else 
      tmp = clock/(freq); 
   
   tmp--;
   old_para_p->data_width = tmp;
   tmp = ((tmp+1)*duty)/100;
   old_para_p->threshold = tmp;
   old_para_p->repeat_count = 0;
   old_para_p->guard_dur = 0;
   old_para_p->idle_output =  PWM_OUTPUT_LOW;
   old_para_p->guard_output = PWM_OUTPUT_LOW;
   old_para_p->pwm_callback = 0;
   
   PWM_Configure(owner, pwm_num, (kal_uint32)PWM_OLD_MODE, (void *)old_para_p);
}

/*-----------------------------------------------------------------------
* FUNCTION
*  PWM1_Configure
*
* DESCRIPTION
*   The function is to configure the PWM1 output frequency and duty cycle.the function is to 
*   generate the simpliest periodical output signal.
*
* PARAMETERS
*  freq    : the PWM channel output frequency.
*  duty    : the duty cycle of the high level under the periodical output.
*
* RETURNS
*  none
* 
* NOTE
*  the function is used in order to keep the compatible with the old PWM interface.
*  duty=50 ==> 50%
*------------------------------------------------------------------------*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #ifdef __PWM3_FOR_MMI__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif /*__PWM3_FOR_MMI__*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #ifdef __PWM3_FOR_MMI__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif /*__PWM3_FOR_MMI__*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #ifdef __PWM3_FOR_MMI__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif /*__PWM3_FOR_MMI__*/
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

/*-----------------------------------------------------------------------
* FUNCTION
*  PWM_level
*
* DESCRIPTION
*   The function is to generate different PWM1 output according to the different level.The every level indicates
*   certain frequency and duty which can be defined through the customization.
*
* PARAMETERS
*  level: the level value.its defination can be found under the fie:custom_hw_defalut.c.
* 
* RETURNS
*  none
*  
* NOTE
* level = 0; indicates close the PWM1 output.
* level = 1~5, level = 0, close PWM
*------------------------------------------------------------------------*/
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
/* under construction !*/
#ifdef __PWM3_FOR_MMI__
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
#endif /*__PWM3_FOR_MMI__*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/* For PWM3~PMW6 general frequncey and duty waveform. */
typedef struct {
   kal_uint32  freq;
   kal_uint16  steps;
} pwm_freq_steps;

static pwm_freq_steps   pwm_freq_steps_array[(kal_uint32)PWM_COUNT-(kal_uint32)PWM2];

/*-----------------------------------------------------------------------
* FUNCTION
*  PWM_Config_Freq_Steps
*
* DESCRIPTION
*   The function is to set the output frequency and the steps.it is used by the Camera AF lens driver
*
* PARAMETERS
*  owner   :  the user module id of the PWM channel.
*  pwm_num :  the id of the PWM channel
*  freq    :  the output frequency.
*  steps   :  the lens driver steps.
*
* RETURNS
*  None
*  
*  NOTE
*  the PWM channel just contains PWM3-PWM6.
*------------------------------------------------------------------------*/
void PWM_Config_Freq_Steps(kal_uint8 owner, kal_uint32 pwm_num, kal_uint32 freq, kal_uint16 steps)
{
   pwm_handle_s   *handle;

   handle = pwm_handle_array+pwm_num;
   if ((pwm_num <= (kal_uint32)PWM2) || (pwm_num > (kal_uint32)PWM6) || (handle->owner!=owner))
   {
      ASSERT(0);
      return;
   }
   pwm_freq_steps_array[pwm_num-(kal_uint32)PWM3].freq = freq;
   pwm_freq_steps_array[pwm_num-(kal_uint32)PWM3].steps = steps;
}

/*-----------------------------------------------------------------------
* FUNCTION
*  PWM_Set_Duty
*
* DESCRIPTION
*   The function is to set the output duty value, it should not larger than the Steps in the above function.
*
* PARAMETERS
*  owner   :  the user module id of the PWM channel.
*  pwm_num :  the id of the PWM channel.it should be PWM3~PWM6.
*  duty    :  the output duty value (0~steps).
*
* RETURNS
*  None
*  
*------------------------------------------------------------------------*/
void PWM_Set_Duty(kal_uint8 owner, kal_uint32 pwm_num, kal_uint16 duty)
{
   kal_uint32 clock;
   kal_uint32 tmp;
   kal_uint16 clkdiv;
   kal_uint16 reg;
   pwm_fifo_para_s   fifo_para;
   pwm_fifo_para_s   *fifo_para_p;
   pwm_freq_steps    *freq_steps_p;
   pwm_handle_s      *handle;
      
   handle = pwm_handle_array+pwm_num;
   if ((pwm_num <= (kal_uint32)PWM2) || (pwm_num > (kal_uint32)PWM6) || (handle->owner!=owner))
   {
      ASSERT(0);
      return;
   }
   freq_steps_p = pwm_freq_steps_array+(pwm_num-(kal_uint32)PWM3);
   if (duty > freq_steps_p->steps)
   {
      ASSERT(0);
      return;
   }
   
   fifo_para_p = &fifo_para;
   reg = DRV_RWG_Reg(PWM1_CON+0x40*pwm_num);
   clkdiv = (1 << ((reg & PWM_CON_CLKDIV_MASK)>>PWM_CON_CLKDIV_SHIFT));
   
   if (reg & PWM_CON_CLKSEL_MASK)
      clock = 32000;
   else
      clock = RWG_BLOCK_CLOCK;
   
   clock = clock/clkdiv;
   
   if(0==freq_steps_p->freq)
      freq_steps_p->freq++;
   tmp = clock/freq_steps_p->freq;
   if (duty == freq_steps_p->steps)
      fifo_para_p->data0 = 0xffffffff;
   else if (duty == 0)
      fifo_para_p->data0 = 0;
   else
      fifo_para_p->data0 = 0x55555555;

   fifo_para_p->data1 = 0;
   fifo_para_p->repeat_count = 0;
   fifo_para_p->stop_bitpos = 31;
   fifo_para_p->high_dur = tmp*duty/freq_steps_p->steps;  
   fifo_para_p->low_dur = tmp*(freq_steps_p->steps-duty)/freq_steps_p->steps;
   if (fifo_para_p->high_dur > 1)
   {
      fifo_para_p->high_dur--;
   }
   else if (fifo_para_p->high_dur==0)
   {
      fifo_para_p->high_dur++;
   }
   if (fifo_para_p->low_dur > 1)
   {
      fifo_para_p->low_dur--;
   }
   else if (fifo_para_p->low_dur==0)
   {
      fifo_para_p->low_dur++;
   }
   fifo_para_p->guard_dur = 0;
   fifo_para_p->idle_output = PWM_OUTPUT_LOW;
   fifo_para_p->guard_output = PWM_OUTPUT_LOW;
   fifo_para_p->pwm_callback = NULL;

   PWM_Configure(owner, pwm_num, (kal_uint32)PWM_FIFO_MODE, (void *)fifo_para_p);
}

// Configure PWM4,5,6 port generate old PWM waveform
#if defined(__PWM456_SUPPORT_OLD_PWM_API__)
void PWM456_Configure_OLD_PWM(kal_uint32 pwm_num, kal_uint32 freq, kal_uint8 duty)
{
	kal_uint32 clock;
	kal_uint32 tmp;
	kal_uint16 clkdiv;
	kal_uint16 reg;
	pwm_fifo_para_s   fifo_para;
	pwm_handle_s   *handle;
	kal_uint8 owner;
	kal_uint32 high_duration;
	
	ASSERT(duty <= 100);
	ASSERT((pwm_num>=(kal_uint32)PWM4)&&(pwm_num<=(kal_uint32)PWM6));
	
   /*lint -e661*/
   // already add ASSERT to check >=4 && <=6
   handle = pwm_handle_array+pwm_num;
   ASSERT(handle->owner != (kal_uint8)PWM_OWNER_NONE);
   owner = handle->owner;
   /*lint +e661*/	
   
   reg = DRV_RWG_Reg(PWM1_CON+0x40*pwm_num);
   clkdiv = (1 << ((reg & PWM_CON_CLKDIV_MASK)>>PWM_CON_CLKDIV_SHIFT));

   clock = RWG_BLOCK_CLOCK;
	
   if (reg & PWM_CON_CLKSEL_MASK)
   {
      clock = clock/1625;
   }
   
   // Calculate clock scale	
   clock = clock/clkdiv;

   // tmp is the real clock count per PWM cycle
   if(0==freq)
      tmp = clock/(freq+1);
   else 
      tmp = clock/(freq); 		
	
   // The clock count in 1 cycle when output HIGH
   high_duration = ((tmp)*duty)/100;
	
   fifo_para.data0 = 0x1; /* Bit0 = 1, Bit1 = 0*/
   fifo_para.data1 = 0;
   fifo_para.repeat_count = 0; /* 0 means endless repeat */
   fifo_para.stop_bitpos = 1; /* 0~63*/ // Only 1 and 0 for old PWM mode
   if (duty > 90)
   {
      // Duty > 90%
      fifo_para.high_dur = tmp - 3; /* must>0. When set to N, the duration is N+1 clocks. */
      fifo_para.low_dur = tmp - (fifo_para.high_dur+1) - 1; /* must>0. When set to N, the duration is N+1 clocks. */
      // Set stop bit position to 0
   }
   else if (duty < 10)
   {
      // Duty < 90%
      fifo_para.low_dur = tmp - 3; /* must>0. When set to N, the duration is N+1 clocks. */
      fifo_para.high_dur = tmp - (fifo_para.low_dur+1) - 1; /* must>0. When set to N, the duration is N+1 clocks. */
   }
   else
   {
      fifo_para.high_dur = high_duration - 1; /* must>0. When set to N, the duration is N+1 clocks. */
      fifo_para.low_dur = tmp - high_duration - 1 ; /* must>0. When set to N, the duration is N+1 clocks. */
   }

   fifo_para.guard_dur = 0; /* must>0. When set to N, the duration is N+1 clocks. */
   fifo_para.idle_output = PWM_OUTPUT_LOW; /* PWM_OUTPUT_LOW or PWM_OUTPUT_HIGH */
   fifo_para.guard_output = PWM_OUTPUT_LOW; /* PWM_OUTPUT_LOW or PWM_OUTPUT_HIGH */
   fifo_para.pwm_callback = 0;	/* Callback function */

   PWM_Configure(owner, pwm_num, (kal_uint32)PWM_FIFO_MODE, (void *)&fifo_para);
}

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

#endif // #if defined(__PWM456_SUPPORT_OLD_PWM_API__)

/*************************************************************************
* FUNCTION
*  PWM_Test_Select
*
* DESCRIPTION
*   The function is mainly for the DVT (Device Test) to test the PWM1 and PWM2 output signal and not exported to the user.
*
* PARAMETERS
*  sel  : 0 indicates to select the output of pwm unit5 and pwm unit6. 
*         1 indicates that the output of pwm unit1 will be selected instead of pwm unit5, 
*         and the output of pwm unit2 will be selected instead of pwm unit6. 
*
* RETURNS
*  None
*  
*************************************************************************/
void PWM_Test_Select(kal_bool sel)
{
   kal_uint32 en_reg;

   en_reg = DRV_RWG_Reg32(PWM_ENABLE);

   if(sel)
   {
      en_reg |= PWM_TEST_SEL;
   }
   else
   {
      en_reg &= ~PWM_TEST_SEL;
   }	
   DRV_RWG_WriteReg32(PWM_ENABLE, en_reg);
}

#else  // DRV_PWM_OFF

void PWM_Init(void){}
kal_bool PWM_Open(kal_uint8 owner, kal_uint32 pwm_num){return KAL_TRUE;}
kal_bool PWM_Seq_Open(kal_uint8 owner){return KAL_TRUE;}
kal_bool PWM_Close(kal_uint8 owner, kal_uint32 pwm_num){return KAL_TRUE;}
kal_bool PWM_Seq_Close(kal_uint8 owner){return KAL_TRUE;}
void PWM_CLK_Init(kal_uint8 owner, kal_uint32 pwm_num, kal_uint32 clk_sel, kal_uint32 clk_div){}
kal_bool PWM_Configure(kal_uint8 owner, kal_uint32 pwm_num, kal_uint32 mode, void *para){return KAL_TRUE;}
void PWM_Start(kal_uint8 owner, kal_uint32 pwm_num){}
void PWM_Stop(kal_uint8 owner, kal_uint32 pwm_num){}
void PMW_Set_Delay(kal_uint8 owner, kal_uint32 pwm_num, kal_uint32 clk_sel, kal_uint16 delay_cnt){}
void PWM_Seq_Start(kal_uint8 owner, kal_uint8 en_cnt){}
void PWM_Seq_Stop(kal_uint8 owner){}
void PWM_Set_Buf_Valid(kal_uint8 owner, kal_uint32 pwm_num, kal_uint32 *buf_addr, kal_uint16 buf_size, kal_bool is_buf0){}
void PWM3_Configure(kal_uint32 freq, kal_uint8 duty){}
void PWM3_Start(void){}
void PWM3_Stop(void){}
void PWM4_Configure(kal_uint32 freq, kal_uint8 duty){}
void PWM5_Configure(kal_uint32 freq, kal_uint8 duty){}
void PWM6_Configure(kal_uint32 freq, kal_uint8 duty){}
void PWM4_Start(void){}
void PWM5_Start(void){}
void PWM6_Start(void){}
void PWM4_Stop(void){}
void PWM5_Stop(void){}
void PWM6_Stop(void){}
kal_uint8  PMW4_GetCurrentDuty(void){return 0;}
kal_uint32 PMW4_GetCurrentFreq(void){return 0;}
kal_uint8  PMW5_GetCurrentDuty(void){return 0;}
kal_uint32 PMW5_GetCurrentFreq(void){return 0;}
kal_uint8  PMW6_GetCurrentDuty(void){return 0;}
kal_uint32 PMW6_GetCurrentFreq(void){return 0;}
kal_uint8  PMW1_GetCurrentDuty(void){return 0;}
kal_uint32 PMW1_GetCurrentFreq(void){return 0;}
kal_uint8  PMW2_GetCurrentDuty(void){return 0;}
kal_uint32 PMW2_GetCurrentFreq(void){return 0;}
void PWM_Test_Select(kal_bool sel){}

#endif // DRV_PWM_OFF

#endif  /* defined(DRV_PWM_RWG) */
