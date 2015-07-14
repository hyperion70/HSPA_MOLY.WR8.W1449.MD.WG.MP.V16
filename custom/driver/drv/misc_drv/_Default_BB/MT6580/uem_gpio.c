/* This file can be deleted */
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
 *   uem_gpio.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   The file contains definition of custom component module configuration
 *   variables, and routines handle for equipment device.
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
#ifdef __CUST_NEW__
#ifndef __L1_STANDALONE__

/*
**   Includes
*/
#include "kal_public_api.h" //MSBB change #include "kal_release.h"
#include "stack_types.h"
#include "syscomp_config.h"
//MSBB remove #include "custom_config.h"
#include "stack_buff_pool.h"
#include "ctrl_buff_pool.h"
#include "dcl.h"
#include "device.h"
#include "custom_equipment.h"
#include "custom_hw_default.h"
#include "custom_em.h"

#ifdef LQT_SUPPORT /* Please don't remove LQT code segments */
#include "lcd_lqt.h"
extern kal_uint8 lcd_at_mode;
#endif /* LQT_SUPPORT */

/*
**   Typedefs
*/

/*
**   Defines
*/

/*
**   Extern Functions
*/
extern void GPIO_WriteIO(char data, char port);
extern void GPIO_WriteIO_FAST(char data, char port);
extern void PWM_level(kal_uint8 level);
extern void PWM2_level(kal_uint8 level);
extern void PWM3_level(kal_uint8 level);
#if (defined(TOUCH_PAD_SUPPORT) && defined(__MTK_TARGET__))
extern void Touchpad_PowerOn(const kal_bool bOn);
#endif

/*
**   Extern Varibales
*/
extern const char gpio_led_mainbl_en_pin;
//extern const char gpio_led_keybl_en_pin;
//extern const char gpio_led_keybl2_en_pin;
//extern const char gpio_vibrator_en_pin;

/*
**   Globol Varibales
*/

/*
**   Local Functions
*/

/*
**   Local Variables
*/
/***********************************************************
  **
  **  GPIO SETTTING
  **
  ***********************************************************/

kal_bool custom_cfg_gpio_set_level(kal_uint8 gpio_dev_type, kal_uint8 gpio_dev_level)
{
	return KAL_TRUE;
}

void custom_start_flashlight(kal_uint8 red_level, kal_uint8 green_level, kal_uint8 blue_level, kal_uint8 duty)
{
	DCL_HANDLE pwm_handle;
	PWM_CMD_CONFIG_OLD_T old_config;

	custom_cfg_gpio_set_level(GPIO_DEV_LED_STATUS_1, ((red_level>0) ? LED_LIGHT_LEVEL5 : LED_LIGHT_LEVEL0));
	custom_cfg_gpio_set_level(GPIO_DEV_LED_STATUS_2, ((green_level>0) ? LED_LIGHT_LEVEL5 : LED_LIGHT_LEVEL0));
	custom_cfg_gpio_set_level(GPIO_DEV_LED_STATUS_3, ((blue_level>0) ? LED_LIGHT_LEVEL5 : LED_LIGHT_LEVEL0));

	pwm_handle = DclPWM_Open(DCL_PWM2,MOD_UEM);
	old_config.freq = PWM2_Level_Info[0][0];
	old_config.duty = duty;
	DclPWM_Control(pwm_handle, PWM_CMD_CONFIG_OLD, (DCL_CTRL_DATA_T*)&old_config);
	DclPWM_Control(pwm_handle, PWM_CMD_START,0);
	DclPWM_Close(pwm_handle);
}

void custom_stop_flashlight(void)
{ 
	DCL_HANDLE pwm_handle;

	custom_cfg_gpio_set_level(GPIO_DEV_LED_STATUS_1, LED_LIGHT_LEVEL0);
	custom_cfg_gpio_set_level(GPIO_DEV_LED_STATUS_2, LED_LIGHT_LEVEL0);
	custom_cfg_gpio_set_level(GPIO_DEV_LED_STATUS_3, LED_LIGHT_LEVEL0);

	pwm_handle = DclPWM_Open(DCL_PWM2, MOD_UEM);
	DclPWM_Control(pwm_handle, PWM_CMD_STOP, 0);
	DclPWM_Close(pwm_handle);
}

#endif /* !__L1_STANDALONE__ */

#endif /* __CUST_NEW__ */
