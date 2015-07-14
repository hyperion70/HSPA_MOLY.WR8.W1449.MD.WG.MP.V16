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
 *    rwg_test.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intended for testing Random Waveform Generator (Enhaced PWM) driver.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "drv_features_pwm.h"
#include "drv_comm.h"
#include "reg_base.h"
#include "rwg_hw.h"
#include "rwg_sw.h"
#include "drvpdn.h"
#include	"intrCtrl.h"
#include "drv_hisr.h"
#include "custom_hw_default.h"
#include "swdbg_sw.h"
#ifdef DRV_PWM_RWG
//#include "pmu_sw.h"   //remove the file which is empty
#endif



//#define __CLOCK_13M__
//#define __CLOCK_26M__

#define data55  0x55555555
#define dataAA  0xAAAAAAAA
#define data11  0x11111111
#define dataEE  0xEEEEEEEE
#define data76  0x76543210
#define dataFE  0xFEDCBA98



kal_uint8 test_owner = 0;
typedef void (*pwm_cb_fx)(kal_uint32 pwm_num);
static pwm_cb_fx  pwm_cb_array[PWM_COUNT*2] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static pwm_fifo_para_s f_para = {
   data55,
   dataAA,
   0,
   63,
   1,
   1,
   0,
   PWM_OUTPUT_LOW,
   PWM_OUTPUT_LOW,
   0
};

kal_uint32 memo_data[] = {
   data55, dataAA, data11, dataEE,data76, dataFE
};
#define MEMO_DATA_SIZE   (sizeof(memo_data)/sizeof(kal_uint32))
static pwm_memo_para_s m_para = {
   memo_data,
   (MEMO_DATA_SIZE-1),
   0,
   31,
   1,
   1,
   0,
   PWM_OUTPUT_LOW,
   PWM_OUTPUT_LOW,
   0
};
static pwm_old_para_s  o_para = {
   100,
   50,
   0,
   0,
   PWM_OUTPUT_LOW,
   PWM_OUTPUT_LOW,
   0
};

#define RANDOM_BUF0_SIZE   (1024)
kal_uint32 random_buf0[RANDOM_BUF0_SIZE];

#define RANDOM_BUF1_SIZE   (1024)
kal_uint32 random_buf1[RANDOM_BUF1_SIZE];

static pwm_random_para_s r_para = {
   random_buf0,
   random_buf1,
   (RANDOM_BUF0_SIZE-1),
   (RANDOM_BUF1_SIZE-1),
   1,
   1,
   PWM_OUTPUT_LOW,
   0,
   0
};

volatile kal_uint8 pwm_fifo_finish[PWM_COUNT];
void pwm_fifo_finish_cb(kal_uint32 pwm_num)
{
   pwm_fifo_finish[pwm_num] = 1;
}

volatile kal_uint8 pwm_memo_finish[PWM_COUNT];
void pwm_memo_finish_cb(kal_uint32 pwm_num)
{
   pwm_memo_finish[pwm_num] = 1;
}

volatile kal_uint8 pwm_old_finish[PWM_COUNT];
void pwm_old_finish_cb(kal_uint32 pwm_num)
{
   pwm_old_finish[pwm_num] = 1;
}

kal_uint16 repeat_count = 0;
volatile kal_uint32 pwm_random_finish[PWM_COUNT];
kal_uint32 pwm_random_finish_buf0;
kal_uint32 pwm_random_finish_buf1;
void pwm_random_invalid_cb(kal_uint32 pwm_num, kal_uint8 buf_num)
{
	kal_uint32 tmp;
	kal_uint32 base_addr;
   kal_uint32 count = 0;

   if ((repeat_count==0xffff) || (pwm_random_finish[pwm_num] < repeat_count))
   {
      /*if (pwm_num <= PWM3)
         base_addr = PWM1_VALID + 0x40*pwm_num;
      else
         base_addr = PWM4_VALID + 0x40*(pwm_num-PWM4);
      tmp = DRV_Reg32(base_addr);*/
      //if (PWM_BUF0_INVALID == (tmp & PWM_BUF0_VALID_MASK))
      //if (!(tmp & PWM_BUF0_VALID_MASK))
      if (buf_num == PWM_BUF_0_INVALID)
      {
         //tmp |= (PWM_BUF0_VALID_WENABLE|PWM_BUF0_VALID);
         PWM_Set_Buf_Valid(test_owner, pwm_num, 0, 0, KAL_TRUE);
         pwm_random_finish_buf0++;
      }
      //if (PWM_BUF1_INVALID == (tmp & PWM_BUF1_VALID_MASK))
      //if (!(tmp & PWM_BUF1_VALID_MASK))
      if (buf_num == PWM_BUF_1_INVALID)
      {
         //tmp |= (PWM_BUF1_VALID_WENABLE|PWM_BUF1_VALID);
         PWM_Set_Buf_Valid(test_owner, pwm_num, 0, 0, KAL_FALSE);
         pwm_random_finish_buf1++;
      }
      //DRV_WriteReg32(base_addr, tmp);
      pwm_random_finish[pwm_num] += 1;
   }
}

volatile kal_uint8 pwm_random_underflow[PWM_COUNT];
void pwm_random_underflow_cb(kal_uint32 pwm_num)
{
   pwm_random_underflow[pwm_num] = 1;
}

/***************************************
#if 0
void PWM_LISR(void)
{
   kal_uint32  int_status;
   kal_uint32  index;

   int_status = DRV_Reg32(PWM_INT_STATUS);
   index = 0;
   while (index < PWM_COUNT*2)
   {
      kal_uint32 mask;

      mask = (0x00000001<<index);
      if ((int_status & (mask)) && (pwm_cb_array[index] != 0))
      {
         (pwm_cb_array[index])(index>>1);
         DRV_WriteReg32(PWM_INT_ACK, mask);
      }
      index++;
   }
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
   }
}

void PWM_CLK_Init(kal_uint32 num, kal_uint32 clk_sel, kal_uint32 clk_div)
{
	kal_uint32 tmp;
	kal_uint32 base_addr;

   base_addr = PWM1_CON + 0x40*num;
	tmp = DRV_Reg32(base_addr);
   tmp &= ~(PWM_CON_CLKDIV_MASK|PWM_CON_CLKSEL_MASK);
   tmp |= (PWM_CON_CLKDIV_MASK&(clk_div<<PWM_CON_CLKDIV_SHIFT));
   tmp |= (PWM_CON_CLKSEL_MASK&(clk_sel<<PWM_CON_CLKSEL_SHIFT));
	DRV_WriteReg32(base_addr,tmp);
}

void PWM_Configure(kal_uint32 pwm_num, kal_uint32 mode, void *para)
{
	kal_uint32 tmp;
	kal_uint32 base_addr;

   if (pwm_num > PWM6)
      return;
   base_addr = PWM1_CON + 0x40*pwm_num;
	tmp = DRV_Reg32(base_addr);
   switch(mode)
   {
   case PWM_FIFO_MODE:
      {
         pwm_fifo_para_s   *fifo_para;

         fifo_para = (pwm_fifo_para_s *)para;
         tmp &= ~(PWM_CON_SRCSEL_MASK|PWM_CON_MODE_MASK|PWM_CON_IDLE_VALUE_MASK|PWM_CON_GUARD_VALUE_MASK|
                  PWM_CON_STOP_BITPOS_MASK|PWM_CON_OLD_PWM_MODE_MASK);
         tmp |= (PWM_CON_SRCSEL_FIFO |
                 PWM_CON_MODE_PERIODIC |
                 ((fifo_para->idle_output<<PWM_CON_IDLE_VALUE_SHIFT)&PWM_CON_IDLE_VALUE_MASK) |
                 ((fifo_para->guard_output<<PWM_CON_GUARD_VALUE_SHIFT)&PWM_CON_GUARD_VALUE_MASK) |
                 ((fifo_para->stop_bitpos<<PWM_CON_STOP_BITPOS_SHIFT)&PWM_CON_STOP_BITPOS_MASK) |
                 PWM_CON_NEW_PWM_MODE);
   	   DRV_WriteReg32(base_addr, tmp);
         base_addr = PWM1_SEND_DATA0 + 0x40*pwm_num;
   	   DRV_WriteReg32(base_addr, fifo_para->data0);
         base_addr = PWM1_SEND_DATA1 + 0x40*pwm_num;
   	   DRV_WriteReg32(base_addr, fifo_para->data1);
         base_addr = PWM1_WAVE_NUM + 0x40*pwm_num;
   	   DRV_WriteReg32(base_addr, fifo_para->repeat_count);
         base_addr = PWM1_HDURATION + 0x40*pwm_num;
   	   DRV_WriteReg32(base_addr, fifo_para->high_dur);
         base_addr = PWM1_LDURATION + 0x40*pwm_num;
   	   DRV_WriteReg32(base_addr, fifo_para->low_dur);
         base_addr = PWM1_GDURATION + 0x40*pwm_num;
   	   DRV_WriteReg32(base_addr, fifo_para->guard_dur);
         tmp = DRV_Reg32(PWM_INT_ENABLE);
         tmp &= ~((PWM1_INT_FINISH_EN_MASK|PWM1_INT_UNDERFLOW_EN_MASK) << (pwm_num*2));
         if (fifo_para->pwm_callback != 0)
         {
            tmp |= ((PWM1_INT_FINISH_ENABLE|PWM1_INT_UNDERFLOW_DISABLE) << (pwm_num*2));
         }
         DRV_WriteReg32(PWM_INT_ENABLE, tmp);
         pwm_cb_array[pwm_num*2] = fifo_para->pwm_callback;
         pwm_cb_array[pwm_num*2+1] = 0;
      }
      break;
   case PWM_MEMO_MODE:
      {
         pwm_memo_para_s   *mem_para;

         mem_para = (pwm_memo_para_s *)para;
         tmp &= ~(PWM_CON_SRCSEL_MASK|PWM_CON_MODE_MASK|PWM_CON_IDLE_VALUE_MASK|PWM_CON_GUARD_VALUE_MASK|
                  PWM_CON_STOP_BITPOS_MASK|PWM_CON_OLD_PWM_MODE_MASK);
         tmp |= (PWM_CON_SRCSEL_MEM |
                 PWM_CON_MODE_PERIODIC |
                 ((mem_para->idle_output<<PWM_CON_IDLE_VALUE_SHIFT)&PWM_CON_IDLE_VALUE_MASK) |
                 ((mem_para->guard_output<<PWM_CON_GUARD_VALUE_SHIFT)&PWM_CON_GUARD_VALUE_MASK) |
                 ((mem_para->stop_bitpos<<PWM_CON_STOP_BITPOS_SHIFT)&PWM_CON_STOP_BITPOS_MASK) |
                 PWM_CON_NEW_PWM_MODE);
   	   DRV_WriteReg32(base_addr, tmp);
         base_addr = PWM1_BUF0_BASE_ADDR + 0x40*pwm_num;
   	   DRV_WriteReg32(base_addr, mem_para->buf_addr);
         base_addr = PWM1_BUF0_SIZE + 0x40*pwm_num;
   	   DRV_WriteReg32(base_addr, mem_para->buf_size);
         base_addr = PWM1_WAVE_NUM + 0x40*pwm_num;
   	   DRV_WriteReg32(base_addr, mem_para->repeat_count);
         base_addr = PWM1_HDURATION + 0x40*pwm_num;
   	   DRV_WriteReg32(base_addr, mem_para->high_dur);
         base_addr = PWM1_LDURATION + 0x40*pwm_num;
   	   DRV_WriteReg32(base_addr, mem_para->low_dur);
         base_addr = PWM1_GDURATION + 0x40*pwm_num;
   	   DRV_WriteReg32(base_addr, mem_para->guard_dur);
         tmp = DRV_Reg32(PWM_INT_ENABLE);
         tmp &= ~((PWM1_INT_FINISH_EN_MASK|PWM1_INT_UNDERFLOW_EN_MASK) << (pwm_num*2));
         if (mem_para->pwm_callback != 0)
         {
            tmp |= ((PWM1_INT_FINISH_ENABLE|PWM1_INT_UNDERFLOW_DISABLE) << (pwm_num*2));
         }
         DRV_WriteReg32(PWM_INT_ENABLE, tmp);
         pwm_cb_array[pwm_num*2] = mem_para->pwm_callback;
         pwm_cb_array[pwm_num*2+1] = 0;
      }
      break;
   case PWM_OLD_MODE:
      {
         pwm_old_para_s   *old_para;

         if (pwm_num > PWM3)
            return;

         old_para = (pwm_old_para_s *)para;
         tmp &= ~(PWM_CON_IDLE_VALUE_MASK|PWM_CON_GUARD_VALUE_MASK|PWM_CON_OLD_PWM_MODE_MASK);
         tmp |= (((old_para->idle_output<<PWM_CON_IDLE_VALUE_SHIFT)&PWM_CON_IDLE_VALUE_MASK) |
                 ((old_para->guard_output<<PWM_CON_GUARD_VALUE_SHIFT)&PWM_CON_GUARD_VALUE_MASK) |
                 PWM_CON_OLD_PWM_MODE);
   	   DRV_WriteReg32(base_addr, tmp);
         base_addr = PWM1_DATA_WIDTH + 0x40*pwm_num;
   	   DRV_WriteReg32(base_addr, old_para->data_width);
         base_addr = PWM1_THRESH + 0x40*pwm_num;
   	   DRV_WriteReg32(base_addr, old_para->threshold);
         base_addr = PWM1_WAVE_NUM + 0x40*pwm_num;
   	   DRV_WriteReg32(base_addr, old_para->repeat_count);
         base_addr = PWM1_GDURATION + 0x40*pwm_num;
   	   DRV_WriteReg32(base_addr, old_para->guard_dur);
         tmp = DRV_Reg32(PWM_INT_ENABLE);
         tmp &= ~((PWM1_INT_FINISH_EN_MASK|PWM1_INT_UNDERFLOW_EN_MASK) << (pwm_num*2));
         if (old_para->pwm_callback != 0)
         {
            tmp |= ((PWM1_INT_FINISH_ENABLE|PWM1_INT_UNDERFLOW_DISABLE) << (pwm_num*2));
         }
         DRV_WriteReg32(PWM_INT_ENABLE, tmp);
         pwm_cb_array[pwm_num*2] = old_para->pwm_callback;
         pwm_cb_array[pwm_num*2+1] = 0;
      }
      break;
   case PWM_RANDOM_MODE:
      {
         pwm_random_para_s   *random_para;

         random_para = (pwm_random_para_s *)para;
         tmp &= ~(PWM_CON_SRCSEL_MASK|PWM_CON_MODE_MASK|PWM_CON_IDLE_VALUE_MASK|PWM_CON_OLD_PWM_MODE_MASK);
         tmp |= (PWM_CON_SRCSEL_MEM |
                 PWM_CON_MODE_RANDOM |
                 ((random_para->idle_output<<PWM_CON_IDLE_VALUE_SHIFT)&PWM_CON_IDLE_VALUE_MASK) |
                 PWM_CON_NEW_PWM_MODE);
   	   DRV_WriteReg32(base_addr, tmp);
         base_addr = PWM1_BUF0_BASE_ADDR + 0x40*pwm_num;
   	   DRV_WriteReg32(base_addr, random_para->buf0_addr);
         base_addr = PWM1_BUF0_SIZE + 0x40*pwm_num;
   	   DRV_WriteReg32(base_addr, random_para->buf0_size);
         base_addr = PWM1_BUF1_BASE_ADDR + 0x40*pwm_num;
   	   DRV_WriteReg32(base_addr, random_para->buf1_addr);
         base_addr = PWM1_BUF1_SIZE + 0x40*pwm_num;
   	   DRV_WriteReg32(base_addr, random_para->buf1_size);
         base_addr = PWM1_HDURATION + 0x40*pwm_num;
   	   DRV_WriteReg32(base_addr, random_para->high_dur);
         base_addr = PWM1_LDURATION + 0x40*pwm_num;
   	   DRV_WriteReg32(base_addr, random_para->low_dur);
         if (pwm_num <= PWM3)
            base_addr = PWM1_VALID + 0x40*pwm_num;
         else
            base_addr = PWM4_VALID + 0x40*(pwm_num-PWM4);
         tmp = (PWM_BUF0_VALID|PWM_BUF0_VALID_WENABLE|PWM_BUF1_VALID|PWM_BUF1_VALID_WENABLE);
   	   DRV_WriteReg32(base_addr, tmp);
         tmp = DRV_Reg32(PWM_INT_ENABLE);
         tmp &= ~((PWM1_INT_FINISH_EN_MASK|PWM1_INT_UNDERFLOW_EN_MASK) << (pwm_num*2));
         if (random_para->pwm_finish_cb != 0)
            tmp |= (PWM1_INT_FINISH_ENABLE << (pwm_num*2));
         if (random_para->pwm_finish_cb != 0)
            tmp |= (PWM1_INT_UNDERFLOW_ENABLE << (pwm_num*2));
         DRV_WriteReg32(PWM_INT_ENABLE, tmp);
         pwm_cb_array[pwm_num*2] = random_para->pwm_finish_cb;
         pwm_cb_array[pwm_num*2+1] = random_para->pwm_underflow_cb;
      }
      break;
   default:
      break;
   }
}

void PWM_Start(kal_uint32 pwm_num)
{
	kal_uint32 tmp;

   if (pwm_num > PWM6)
      return;
   //Power on?
	tmp = DRV_Reg32(PWM_ENABLE);
   tmp &= ~(PWM1_ENABLE_MASK << pwm_num);
   tmp |= (PWM1_ENABLE << pwm_num);
   DRV_WriteReg32(PWM_ENABLE, tmp);
}

void PWM_Stop(kal_uint32 pwm_num)
{
	kal_uint32 tmp;

   if (pwm_num > PWM6)
      return;
	tmp = DRV_Reg32(PWM_ENABLE);
   tmp &= ~(PWM1_ENABLE_MASK << pwm_num);
   tmp |= (PWM1_DISABLE << pwm_num);
   DRV_WriteReg32(PWM_ENABLE, tmp);
   //Power off?
}
#endif //0
****************************/
/************** For AF test APIs: Begin *****************/
void AF_waveform_init(void)
{
   PWM_Seq_Open(test_owner);
   PWM_CLK_Init(test_owner, PWM3, PWM_CLK_SEL_52M, PWM_CLK_DIV_NONE);
   PWM_CLK_Init(test_owner, PWM4, PWM_CLK_SEL_52M, PWM_CLK_DIV_NONE);
}

void AF_waveform_A_start(kal_uint32 count)
{
   pwm_fifo_para_s fifo_para;

   fifo_para.data0 = 0x000001FE;
   fifo_para.data1 = 0;
   fifo_para.repeat_count = count;
   fifo_para.stop_bitpos = 8; //9 bits
   fifo_para.high_dur = 25;
   fifo_para.low_dur = 25;
   fifo_para.guard_dur = 0;
   fifo_para.idle_output = PWM_OUTPUT_HIGH;
   fifo_para.guard_output = PWM_OUTPUT_HIGH;
   fifo_para.pwm_callback = 0;
   PWM_Configure(test_owner, PWM3, PWM_FIFO_MODE, (void *)&fifo_para);
   fifo_para.data0 = 0x00000101;
   fifo_para.data1 = 0;
   fifo_para.repeat_count = count;
   fifo_para.stop_bitpos = 8; //9 bits
   fifo_para.high_dur = 25;
   fifo_para.low_dur = 25;
   fifo_para.guard_dur = 0;
   fifo_para.idle_output = PWM_OUTPUT_HIGH;
   fifo_para.guard_output = PWM_OUTPUT_HIGH;
   fifo_para.pwm_callback = 0;
   PWM_Configure(test_owner, PWM4, PWM_FIFO_MODE, (void *)&fifo_para);
  	//DRV_WriteReg32(PWM4_DELAY, (PWM_DELAY_CLKSEL_52M | (4&PWM_DELAY_DURATON_MASK)));
   PMW_Set_Delay(test_owner, PWM4, PWM_CLK_SEL_52M, 4);
   //DRV_WriteReg32(PWM_ENABLE, (PWM3_ENABLE|PWM4_ENABLE|PWM5_DISABLE|PWM6_DISABLE|PWM_SEQ_MODE_ON));
   PWM_Seq_Start(test_owner, PWM_SEQ_EN_PWM34);
}

void AF_waveform_B_start(kal_uint32 count)
{
   pwm_fifo_para_s fifo_para;

   fifo_para.data0 = 0x00000003;
   fifo_para.data1 = 0;
   fifo_para.repeat_count = 0;
   fifo_para.stop_bitpos = 8; //9 bits
   fifo_para.high_dur = 25;
   fifo_para.low_dur = 25;
   fifo_para.guard_dur = 0;
   fifo_para.idle_output = PWM_OUTPUT_HIGH;
   fifo_para.guard_output = PWM_OUTPUT_HIGH;
   fifo_para.pwm_callback = 0;
   PWM_Configure(test_owner, PWM3, PWM_FIFO_MODE, (void *)&fifo_para);
   fifo_para.data0 = 0x000001FE;
   fifo_para.data1 = 0;
   fifo_para.repeat_count = 0;
   fifo_para.stop_bitpos = 8; //9 bits
   fifo_para.high_dur = 25;
   fifo_para.low_dur = 25;
   fifo_para.guard_dur = 0;
   fifo_para.idle_output = PWM_OUTPUT_HIGH;
   fifo_para.guard_output = PWM_OUTPUT_HIGH;
   fifo_para.pwm_callback = 0;
   PWM_Configure(test_owner, PWM4, PWM_FIFO_MODE, (void *)&fifo_para);
  	//DRV_WriteReg32(PWM4_DELAY, (PWM_DELAY_CLKSEL_52M | (22&PWM_DELAY_DURATON_MASK)));
   PMW_Set_Delay(test_owner, PWM4, PWM_CLK_SEL_52M, 22);
   //DRV_WriteReg32(PWM_ENABLE, (PWM3_ENABLE|PWM4_ENABLE|PWM5_DISABLE|PWM6_DISABLE|PWM_SEQ_MODE_ON));
   PWM_Seq_Start(test_owner, PWM_SEQ_EN_PWM34);
}

void AF_waveform_stop(void)
{
 	//DRV_WriteReg32(PWM_ENABLE, 0);
   PWM_Seq_Stop(test_owner);
}
/************** For AF test APIs: End *****************/
void rwg_test_init(void)
{
#ifdef DRV_PWM_RWG
   pmu_set_kpled(KAL_TRUE); // For PWM1
   pmu_set_vibr(KAL_TRUE); // For PWM2
#endif
}
void rwg_test_main(kal_uint8 test_case)
{
   kal_uint32 pwm_index;
   kal_uint8 loop;

   //IRQSensitivity(IRQ_PWM_CODE,EDGE_SENSITIVE);
   //IRQSensitivity(IRQ_PWM_CODE,LEVEL_SENSITIVE);
   //IRQUnmask(IRQ_PWM_CODE);
   switch(test_case)
   {
   case 0:
      /* Test PWM1~PWM6 FIFO mode. */
      pwm_index = PWM1;
      while(pwm_index < PWM_COUNT)
      {
         PWM_Open(test_owner, pwm_index);
         loop = 0;
         while (loop < 2)
         {
            pwm_fifo_para_s   fifo_para;
            kal_uint32     clk_sel;
            kal_uint32     clk_div;

            fifo_para = f_para;
            PWM_Stop(test_owner, pwm_index);
            if (loop == 0)
               clk_sel = PWM_CLK_SEL_52M;
            else
               clk_sel = PWM_CLK_SEL_32K;
            for (clk_div = PWM_CLK_DIV_NONE; clk_div <= PWM_CLK_DIV_128; clk_div++) 
            {
               PWM_CLK_Init(test_owner, pwm_index, clk_sel, clk_div);

               PWM_Configure(test_owner, pwm_index, PWM_FIFO_MODE, (void *)&fifo_para);
               PWM_Start(test_owner, pwm_index);
               PWM_Stop(test_owner, pwm_index);// JTAG stop here. Check the waveform.
            }

            PWM_CLK_Init(test_owner, pwm_index, clk_sel, PWM_CLK_DIV_NONE);
            fifo_para.stop_bitpos = 31;
            PWM_Configure(test_owner, pwm_index, PWM_FIFO_MODE, (void *)&fifo_para);
            PWM_Start(test_owner, pwm_index);
            PWM_Stop(test_owner, pwm_index);// JTAG stop here. Check the waveform: Stop bits.

            fifo_para.stop_bitpos = 63;
            fifo_para.high_dur = 9; /* 9 = 10-1, duration 10 */
            fifo_para.low_dur = 4; /* 4 = 5-1, duration 5 */
            PWM_Configure(test_owner, pwm_index, PWM_FIFO_MODE, (void *)&fifo_para);
            PWM_Start(test_owner, pwm_index);
            PWM_Stop(test_owner, pwm_index);// JTAG stop here. Check the waveform: High/Low duration.

            fifo_para.high_dur = 1;
            fifo_para.low_dur = 1;
            fifo_para.guard_dur = 31;
            PWM_Configure(test_owner, pwm_index, PWM_FIFO_MODE, (void *)&fifo_para);
            PWM_Start(test_owner, pwm_index);
            PWM_Stop(test_owner, pwm_index);// JTAG stop here. Check the waveform: Guard duration.

            fifo_para.guard_output = PWM_OUTPUT_HIGH;
            fifo_para.idle_output = PWM_OUTPUT_HIGH;
            PWM_Configure(test_owner, pwm_index, PWM_FIFO_MODE, (void *)&fifo_para);
            PWM_Start(test_owner, pwm_index);
            PWM_Stop(test_owner, pwm_index);// JTAG stop here. Check the waveform: Guard output high.

            fifo_para.repeat_count = 100; //JTAG stop here. Check the waveform: Idle output high.
            fifo_para.pwm_callback = pwm_fifo_finish_cb;
            PWM_Configure(test_owner, pwm_index, PWM_FIFO_MODE, (void *)&fifo_para);
            pwm_fifo_finish[pwm_index] = 0;
            PWM_Start(test_owner, pwm_index);
            while (((volatile kal_uint8)pwm_fifo_finish[pwm_index]) == 0)
            {
            }
            PWM_Stop(test_owner, pwm_index);// JTAG breakpoint here. If the breakpoint is hit, means interrupt happened.
            loop++;
         }
         PWM_Close(test_owner, pwm_index);
         pwm_index++;
      }
      break;
   case 1:
      /* Test PWM1~PWM6 MEMO mode. */
      pwm_index = PWM1;
      while(pwm_index < PWM_COUNT)
      {
         PWM_Open(test_owner, pwm_index);
         loop = 0;
         while (loop < 2)
         {
            pwm_memo_para_s   memo_para;
            kal_uint32     clk_sel;
            kal_uint32     clk_div;

            memo_para = m_para;
/*************************************************************
#if 0
            memo_para.buf_addr = (kal_uint32 *)0x40000000;
            DRV_WriteReg32(0x40000000, data55);
            DRV_WriteReg32(0x40000004, dataAA);
            DRV_WriteReg32(0x40000008, data11);
            DRV_WriteReg32(0x4000000C, dataEE);
            DRV_WriteReg32(0x40000010,data76);
            DRV_WriteReg32(0x40000014, dataFE);
#endif
*************************************************************/
            PWM_Stop(test_owner, pwm_index);
            if (loop == 0)
               clk_sel = PWM_CLK_SEL_52M;
            else
               clk_sel = PWM_CLK_SEL_32K;
            for (clk_div = PWM_CLK_DIV_NONE; clk_div <= PWM_CLK_DIV_128; clk_div++) 
            {
               PWM_CLK_Init(test_owner, pwm_index, clk_sel, clk_div);

               PWM_Configure(test_owner, pwm_index, PWM_MEMO_MODE, (void *)&memo_para);
               PWM_Start(test_owner, pwm_index);
               PWM_Stop(test_owner, pwm_index);// JTAG stop here. Check the waveform.
            }

            PWM_CLK_Init(test_owner, pwm_index, clk_sel, PWM_CLK_DIV_NONE);
            memo_para.stop_bitpos = 15;
            PWM_Configure(test_owner, pwm_index, PWM_MEMO_MODE, (void *)&memo_para);
            PWM_Start(test_owner, pwm_index);
            PWM_Stop(test_owner, pwm_index);// JTAG stop here. Check the waveform: Stop bits.

            memo_para.stop_bitpos = 31;
            memo_para.high_dur = 9; /* 9 = 10-1, duration 10 */
            memo_para.low_dur = 4; /* 4 = 5-1, duration 5 */
            PWM_Configure(test_owner, pwm_index, PWM_MEMO_MODE, (void *)&memo_para);
            PWM_Start(test_owner, pwm_index);
            PWM_Stop(test_owner, pwm_index);// JTAG stop here. Check the waveform: High/Low duration.

            memo_para.high_dur = 1;
            memo_para.low_dur = 1;
            memo_para.guard_dur = 31;
            PWM_Configure(test_owner, pwm_index, PWM_MEMO_MODE, (void *)&memo_para);
            PWM_Start(test_owner, pwm_index);
            PWM_Stop(test_owner, pwm_index);// JTAG stop here. Check the waveform: Guard duration.

            memo_para.guard_output = PWM_OUTPUT_HIGH;
            memo_para.idle_output = PWM_OUTPUT_HIGH;
            PWM_Configure(test_owner, pwm_index, PWM_MEMO_MODE, (void *)&memo_para);
            PWM_Start(test_owner, pwm_index);
            PWM_Stop(test_owner, pwm_index);// JTAG stop here. Check the waveform: Guard output high.

            memo_para.repeat_count = 100; //JTAG stop here. Check the waveform: Idle output high.
            memo_para.pwm_callback = pwm_memo_finish_cb;
            PWM_Configure(test_owner, pwm_index, PWM_MEMO_MODE, (void *)&memo_para);
            pwm_memo_finish[pwm_index] = 0;
            PWM_Start(test_owner, pwm_index);
            while (((volatile kal_uint8)pwm_memo_finish[pwm_index]) == 0)
            {
            }
            PWM_Stop(test_owner, pwm_index);// JTAG breakpoint here. If the breakpoint is hit, means interrupt happened.
            loop++;
         }
         PWM_Close(test_owner, pwm_index);
         pwm_index++;
      }
      break;
   case 2:
      /* Test PWM1~PWM3 OLD mode. */
      pwm_index = PWM1;
      while(pwm_index <= PWM3)
      {
         PWM_Open(test_owner, pwm_index);
         loop = 0;
         while (loop < 2)
         {
            pwm_old_para_s   old_para;
            kal_uint32     clk_sel;
            kal_uint32     clk_div;

            old_para = o_para;
            PWM_Stop(test_owner, pwm_index);
            if (loop == 0)
               clk_sel = PWM_CLK_SEL_52M;
            else
               clk_sel = PWM_CLK_SEL_32K;
            for (clk_div = PWM_CLK_DIV_NONE; clk_div <= PWM_CLK_DIV_128; clk_div++) 
            {
               PWM_CLK_Init(test_owner, pwm_index, clk_sel, clk_div);

               PWM_Configure(test_owner, pwm_index, PWM_OLD_MODE, (void *)&old_para);
               PWM_Start(test_owner, pwm_index);
               PWM_Stop(test_owner, pwm_index);// JTAG stop here. Check the waveform.
            }

            PWM_CLK_Init(test_owner, pwm_index, clk_sel, PWM_CLK_DIV_NONE);
            old_para.threshold = 75;
            PWM_Configure(test_owner, pwm_index, PWM_OLD_MODE, (void *)&old_para);
            PWM_Start(test_owner, pwm_index);
            PWM_Stop(test_owner, pwm_index);// JTAG stop here. Check the waveform: Threshold.

            old_para.threshold = 25;
            PWM_Configure(test_owner, pwm_index, PWM_OLD_MODE, (void *)&old_para);
            PWM_Start(test_owner, pwm_index);
            PWM_Stop(test_owner, pwm_index);// JTAG stop here. Check the waveform: Threshold.

            old_para.threshold = 50;
            PWM_Configure(test_owner, pwm_index, PWM_OLD_MODE, (void *)&old_para);
            PWM_Start(test_owner, pwm_index);
            PWM_Stop(test_owner, pwm_index);// JTAG stop here. Check the waveform: Data Width.

            old_para.guard_dur = 25;
            PWM_Configure(test_owner, pwm_index, PWM_OLD_MODE, (void *)&old_para);
            PWM_Start(test_owner, pwm_index);
            PWM_Stop(test_owner, pwm_index);// JTAG stop here. Check the waveform: Guard duration.

            old_para.guard_output = PWM_OUTPUT_HIGH;
            old_para.idle_output = PWM_OUTPUT_HIGH;
            PWM_Configure(test_owner, pwm_index, PWM_OLD_MODE, (void *)&old_para);
            PWM_Start(test_owner, pwm_index);
            PWM_Stop(test_owner, pwm_index);// JTAG stop here. Check the waveform: Guard output high.

            old_para.repeat_count = 100; //JTAG stop here. Check the waveform: Idle output high.
            old_para.pwm_callback = pwm_old_finish_cb;
            PWM_Configure(test_owner, pwm_index, PWM_OLD_MODE, (void *)&old_para);
            pwm_old_finish[pwm_index] = 0;
            PWM_Start(test_owner, pwm_index);
            while (((volatile kal_uint8)pwm_old_finish[pwm_index]) == 0)
            {
            }
            PWM_Stop(test_owner, pwm_index);// JTAG breakpoint here. If the breakpoint is hit, means interrupt happened.
            loop++;
         }
         PWM_Close(test_owner, pwm_index);
         pwm_index++;
      }
      break;
   case 3:
      /* Test PWM1~PWM6 Random mode. */
      pwm_index = PWM1;
      while(pwm_index < PWM_COUNT)
      {
         PWM_Open(test_owner, pwm_index);
         loop = 0;
         while (loop < 2)
         {
            pwm_random_para_s   random_para;
            kal_uint32     clk_sel;
            kal_uint32     clk_div;
            kal_uint32     idx;
            kal_uint32     *ptr;

            random_para = r_para;
/*************************************************************
#if 0
            random_para.buf0_addr = (kal_uint32 *)0x40000000;
            ptr =  (kal_uint32 *)0x40000000;
#endif
*************************************************************/
            ptr = random_para.buf0_addr;
            random_para.buf0_size = (loop == 0) ? 1023 : 15;
            for (idx = 0; idx < 1023; idx++)
            {
               *ptr = data55;
               ptr++;
            }
/*************************************************************
#if 0
            random_para.buf1_addr = (kal_uint32 *)0x40002000;
            ptr =  (kal_uint32 *)0x40002000;
#endif
*************************************************************/
            ptr = random_para.buf1_addr;
            random_para.buf1_size =  (loop == 0) ? 1023 : 15;
            for (idx = 0; idx < 1023; idx++)
            {
               *ptr = data11;
               ptr++;
            }
            PWM_Stop(test_owner, pwm_index);
            if (loop == 0)
               clk_sel = PWM_CLK_SEL_52M;
            else
               clk_sel = PWM_CLK_SEL_32K;
            for (clk_div = PWM_CLK_DIV_NONE; clk_div <= PWM_CLK_DIV_128; clk_div++) 
            {
               repeat_count = (loop == 0) ? (4096 >> clk_div) : (((128 >> clk_div)+4));
               PWM_CLK_Init(test_owner, pwm_index, clk_sel, clk_div);
               pwm_random_finish_buf0 = 0;
               pwm_random_finish_buf1 = 0;
               pwm_random_finish[pwm_index] = 0;
               pwm_random_underflow[pwm_index] = 0;
               //random_para.pwm_finish_cb = pwm_random_finish_cb;
               random_para.pwm_invalid_cb = pwm_random_invalid_cb;
               random_para.pwm_underflow_cb = pwm_random_underflow_cb;
               PWM_Configure(test_owner, pwm_index, PWM_RANDOM_MODE, (void *)&random_para);
               PWM_Start(test_owner, pwm_index);
               while (((volatile kal_uint8)pwm_random_underflow[pwm_index]) == 0)
               {
               }
               PWM_Stop(test_owner, pwm_index);/* JTAG breakpoint here. If the breakpoint is hit, means underflow happended.
                                      Then check whether pwm_random_finish[pwm_index] == repeat_count. If yes, means
                                      the random mode works well (double buffer togglling). */
            }

            repeat_count = (loop == 0) ? (4096) : (128);
            PWM_CLK_Init(test_owner, pwm_index, clk_sel, PWM_CLK_DIV_NONE);

            random_para.high_dur = 9; /* 9 = 10-1, duration 10 */
            random_para.low_dur = 4; /* 4 = 5-1, duration 10 */
            random_para.idle_output = PWM_OUTPUT_HIGH;
            pwm_random_finish_buf0 = 0;
            pwm_random_finish_buf1 = 0;
            pwm_random_finish[pwm_index] = 0;
            pwm_random_underflow[pwm_index] = 0;
            PWM_Configure(test_owner, pwm_index, PWM_RANDOM_MODE, (void *)&random_para);
            PWM_Start(test_owner, pwm_index); // Don't use JTAG break and check the waveform: High/Low duration.
            while (((volatile kal_uint8)pwm_random_underflow[pwm_index]) == 0)
            {
            }
            PWM_Stop(test_owner, pwm_index);// JTAG break here. Check the waveform: Idle output high.

            loop++;
         }
         PWM_Close(test_owner, pwm_index);
         pwm_index++;
      }
      break;
   case 4:
      /* Test PWM3 ~ PWM6 sequence mode. */
      PWM_Seq_Open(test_owner);
      loop = 0;
      while (loop < 2)
      {
         kal_uint32     clk_sel1;
         kal_uint32     clk_sel2;
         pwm_random_para_s   random_para;
         pwm_memo_para_s   memo_para;
         kal_uint32     idx;
         kal_uint32     *ptr;

         memo_para = m_para;

/***********************************************************
#if 0
         memo_para.buf_addr = (kal_uint32 *)0x40000000;
         DRV_WriteReg32(0x40000000, data55);
         DRV_WriteReg32(0x40000004, dataAA);
         DRV_WriteReg32(0x40000008, data11);
         DRV_WriteReg32(0x4000000C, dataEE);
         DRV_WriteReg32(0x40000010,data76);
         DRV_WriteReg32(0x40000014, dataFE);
#endif
 ************************************************************/
         random_para = r_para;
/*************************************************************
#if 0
         random_para.buf0_addr = (kal_uint32 *)0x40000000;
         ptr =  (kal_uint32 *)0x40000000;
#endif
****************************************************************/
         ptr = random_para.buf0_addr;
         random_para.buf0_size = (loop == 0) ? 1023 : 15;
         for (idx = 0; idx < 1023; idx++)
         {
            *ptr = data55;
            ptr++;
         }
/*************************************************************
#if 0
         random_para.buf1_addr = (kal_uint32 *)0x40002000;
         ptr =  (kal_uint32 *)0x40002000;
#endif
****************************************************************/
         ptr = random_para.buf1_addr;
         random_para.buf1_size =  (loop == 0) ? 1023 : 15;
         for (idx = 0; idx < 1023; idx++)
         {
            *ptr = data11;
            ptr++;
         }
    	   //DRV_WriteReg32(PWM_ENABLE, 0);
         PWM_Seq_Stop(test_owner);
         if (loop == 0)
         {
            clk_sel1 = PWM_CLK_SEL_52M;
            clk_sel2 = PWM_CLK_SEL_32K;
         }
         else
         {
            clk_sel1 = PWM_CLK_SEL_32K;
            clk_sel2 = PWM_CLK_SEL_52M;
         }
         PWM_CLK_Init(test_owner, PWM3, clk_sel1, PWM_CLK_DIV_128);
         PWM_Configure(test_owner, PWM3, PWM_FIFO_MODE, (void *)&f_para);
         PWM_CLK_Init(test_owner, PWM4, clk_sel2, PWM_CLK_DIV_4);
         PWM_Configure(test_owner, PWM4, PWM_MEMO_MODE, (void *)&memo_para);
         PWM_CLK_Init(test_owner, PWM5, clk_sel1, PWM_CLK_DIV_64);
         PWM_Configure(test_owner, PWM5, PWM_FIFO_MODE, (void *)&f_para);
         repeat_count = 0xffff;
         pwm_random_finish_buf0 = 0;
         pwm_random_finish_buf1 = 0;
         pwm_random_finish[PWM6] = 0;
         pwm_random_underflow[PWM6] = 0;
         //random_para.pwm_finish_cb = pwm_random_finish_cb;
         random_para.pwm_invalid_cb = pwm_random_invalid_cb;
         random_para.pwm_underflow_cb = pwm_random_underflow_cb;
         PWM_CLK_Init(test_owner, PWM6, clk_sel2, PWM_CLK_DIV_16);
         PWM_Configure(test_owner, PWM6, PWM_RANDOM_MODE, (void *)&random_para);

      	//DRV_WriteReg32(PWM4_DELAY, (PWM_DELAY_CLKSEL_32K | (8&PWM_DELAY_DURATON_MASK)));
      	//DRV_WriteReg32(PWM5_DELAY, (PWM_DELAY_CLKSEL_52M | (16000&PWM_DELAY_DURATON_MASK)));
      	//DRV_WriteReg32(PWM6_DELAY, (PWM_DELAY_CLKSEL_32K | (16&PWM_DELAY_DURATON_MASK)));
         PMW_Set_Delay(test_owner, PWM4, PWM_CLK_SEL_32K, 8);
         PMW_Set_Delay(test_owner, PWM5, PWM_CLK_SEL_52M, 16000);
         PMW_Set_Delay(test_owner, PWM6, PWM_CLK_SEL_32K, 16);

         //DRV_WriteReg32(PWM_ENABLE, (PWM3_ENABLE|PWM4_ENABLE|PWM5_ENABLE|PWM6_ENABLE|PWM_SEQ_MODE_ON));
         PWM_Seq_Start(test_owner, PWM_SEQ_EN_PWM3456);
         while (((volatile kal_uint8)pwm_random_underflow[PWM6]) == 0)
         {
         }
       	//DRV_WriteReg32(PWM_ENABLE, 0);
         PWM_Seq_Stop(test_owner);

         //DRV_WriteReg32(PWM_ENABLE, (PWM3_ENABLE|PWM4_ENABLE|PWM5_DISABLE|PWM6_ENABLE|PWM_SEQ_MODE_ON));
         pwm_random_finish_buf0 = 0;
         pwm_random_finish_buf1 = 0;
         pwm_random_finish[PWM6] = 0;
         pwm_random_underflow[PWM6] = 0;
         PWM_Configure(test_owner, PWM6, PWM_RANDOM_MODE, (void *)&random_para);
         PWM_Seq_Start(test_owner, PWM_SEQ_EN_PWM346);
         while (((volatile kal_uint8)pwm_random_underflow[PWM6]) == 0)
         {
         }
       	//DRV_WriteReg32(PWM_ENABLE, 0);
         PWM_Seq_Stop(test_owner);

         //DRV_WriteReg32(PWM_ENABLE, (PWM3_ENABLE|PWM4_DISABLE|PWM5_DISABLE|PWM6_ENABLE|PWM_SEQ_MODE_ON));
         pwm_random_finish_buf0 = 0;
         pwm_random_finish_buf1 = 0;
         pwm_random_finish[PWM6] = 0;
         pwm_random_underflow[PWM6] = 0;
         PWM_Configure(test_owner, PWM6, PWM_RANDOM_MODE, (void *)&random_para);
         PWM_Seq_Start(test_owner, PWM_SEQ_EN_PWM36);
         while (((volatile kal_uint8)pwm_random_underflow[PWM6]) == 0)
         {
         }
       	//DRV_WriteReg32(PWM_ENABLE, 0);
         PWM_Seq_Stop(test_owner);
         loop++;
      }
      PWM_Seq_Close(test_owner);
      break;
   case 5:
      AF_waveform_init();
      AF_waveform_A_start(20);
      AF_waveform_stop();
      AF_waveform_B_start(20);
      AF_waveform_stop();
      break;
   case 6:
      break;
   case 7:
      break;
   case 8:
      break;
   case 9:
      break;
   case 10:
      break;
   case 11:
      break;
   case 12:
      break;
   case 13:
      break;
   case 14:
      break;
   }
}

