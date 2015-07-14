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
 *    dcl_15_segment.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines DCL (Driver Common Layer) of the GPIO driver.
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "dcl_pmu.h"
#include "dcl_15_segment.h"

#include "drv_features_gpio.h"
#include "drv_comm.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
//#include "kal_release.h"
#include "gpio_sw.h"
#include "dcl.h"


#if defined(__MTK_TARGET__) //&& defined(DRV_GPIO_FOR_LED_AND_15_SEGMENT)

#define GPIO_NUMBER_FOR_LED1 61
#define GPIO_NUMBER_FOR_LED2 66

static kal_bool Is_Led1_On = KAL_FALSE,Is_Led2_On = KAL_FALSE;
static DCL_HANDLE led1_handle = 0,led2_handle = 0;
static kal_timerid led1_timer = NULL,led2_timer = NULL;

#if defined(DRV_GPIO_FOR_LED_AND_15_SEGMENT)

static DCL_HANDLE debug1_Handle = 0,debug2_Handle = 0,debug3_Handle = 0,debug4_Handle = 0;
static kal_timerid fifteen_segment_timer = NULL;
static char_to_display *word_to_display = NULL;
static kal_uint32 table_count = 0;
//static LED_NUM led_number;
#endif

static void led_brighting(LED_NUM led_num);
static void led_Dimming(LED_NUM led_num);
static void led1_flicker(void);
static void led2_flicker(void);

#if defined(DRV_GPIO_FOR_LED_AND_15_SEGMENT)
static DCL_STATUS gpio_15_segment_display(void);
#endif



#if defined(DRV_GPIO_FOR_LED_AND_15_SEGMENT)


//{2, null}
char_to_display char_to_display_table1[]={
			{0,0,0,0},
			{0,0,0,1},
			{0,1,1,1},
			{0,1,1,0},
			{0,1,0,0},
			{0,0,1,1}
};
//{6,null}
char_to_display char_to_display_table2[]={
			{0,0,0,0},
			{0,1,0,1},
			{0,1,0,0},
			{0,0,1,1},
			{0,0,1,0},
			{0,1,1,1},
			{0,1,1,0}
};
//{6,1}
char_to_display char_to_display_table3[]={
			{0,0,0,0},
			{0,1,0,1},
			{0,1,0,0},
			{0,0,1,1},
			{0,0,1,0},
			{0,1,1,1},
			{0,1,1,0},
			{1,1,1,0}
};
//{E,null}
char_to_display char_to_display_table4[]={
			{0,0,0,0},
			{0,1,0,1},
			{0,1,0,0},
			{0,0,1,1},
			{0,1,1,0},
			{0,1,1,1}
};
//{E,1}
char_to_display char_to_display_table5[]={
			{0,0,0,0},
			{0,1,0,1},
			{0,1,0,0},
			{0,0,1,1},
			{0,1,1,0},
			{0,1,1,1},
			{1,1,1,0}
};
//{3,null}
char_to_display char_to_display_table6[]={
			{0,0,0,0},
			{0,0,0,1},
			{0,0,1,0},
			{0,0,1,1},
			{0,1,1,0},
			{0,1,1,1}
			
};
//{3,1}
char_to_display char_to_display_table7[]={
			{0,0,0,0},
			{0,0,0,1},
			{0,0,1,0},
			{0,0,1,1},
			{0,1,1,0},
			{0,1,1,1},
			{1,1,1,0}
};
//{h,null}
char_to_display char_to_display_table8[]={
			{0,0,1,0},
			{0,1,0,0},
			{0,1,0,1},
			{0,1,1,0},
			{0,1,1,1}
};
//{h,1}
char_to_display char_to_display_table9[]={
			{0,0,1,0},
			{0,1,0,0},
			{0,1,0,1},
			{0,1,1,0},
			{0,1,1,1},
			{1,1,1,0}
};
//{H,null}
char_to_display char_to_display_table10[]={
			{0,0,0,1},
			{0,0,1,0},
			{0,1,0,0},
			{0,1,0,1},
			{0,1,1,0},
			{0,1,1,1}
};
//{H,1}
char_to_display char_to_display_table11[]={
			{0,0,0,1},
			{0,0,1,0},
			{0,1,0,0},
			{0,1,0,1},
			{0,1,1,0},
			{0,1,1,1},
			{1,1,1,0}
};
//{d,1}
char_to_display char_to_display_table12[]={
			{0,0,0,1},
			{0,0,1,0},
			{0,0,1,1},
			{0,1,0,0},
			{0,1,1,0},
			{0,1,1,1},
			{1,1,1,0}
};
//{X,null}
char_to_display char_to_display_table13[]={
			{1,0,0,0},
			{1,0,1,0},
			{1,0,1,1},
			{1,1,0,1}
};
//{null,null}
char_to_display char_to_display_table14[]={
			{1,1,1,1}
};
//{L,null}
char_to_display char_to_display_table15[]={
			{0,0,1,1},
			{0,1,0,0},
			{0,1,0,1}
};
//{N,null}
char_to_display char_to_display_table16[]={
			{0,0,0,1},
			{0,0,1,0},
			{0,1,0,0},
			{0,1,0,1},
			{1,0,0,0},
			{1,0,1,1}
};
//{I,null}
char_to_display char_to_display_table17[]={
			{0,0,0,0},
			{0,0,1,1},
			{1,0,0,1},
			{1,1,0,0}
};

#endif

DCL_STATUS gpio_led_init()
{
	#if defined(GPIO_NUMBER_FOR_LED1)
	led1_handle = DclGPIO_Open(DCL_GPIO,GPIO_NUMBER_FOR_LED1);
	DclGPIO_Control(led1_handle,GPIO_CMD_SET_MODE_0,0);
	DclGPIO_Control(led1_handle,GPIO_CMD_SET_DIR_OUT,0);
	DclGPIO_Control(led1_handle,GPIO_CMD_WRITE_LOW,0);
	if(led1_timer == NULL)
	led1_timer = kal_create_timer("LED1_TIMER");
	#endif
	#if defined(GPIO_NUMBER_FOR_LED2)
	led2_handle = DclGPIO_Open(DCL_GPIO,GPIO_NUMBER_FOR_LED2);
	DclGPIO_Control(led2_handle,GPIO_CMD_SET_MODE_0,0);
	DclGPIO_Control(led2_handle,GPIO_CMD_SET_DIR_OUT,0);
	DclGPIO_Control(led2_handle,GPIO_CMD_WRITE_LOW,0);//low level means led do not light
	if(led2_timer == NULL)
	led2_timer = kal_create_timer("LED2_TIMER");
	#endif
	return STATUS_OK;
}

void led_brighting(LED_NUM led_num)
{
	
		
	if(led_num == GPIO_LED1)
		{
			kal_cancel_timer(led1_timer);
		    DclGPIO_Control(led1_handle,GPIO_CMD_WRITE_HIGH,0);
		}
	else
		{
		kal_cancel_timer(led2_timer);
		DclGPIO_Control(led2_handle,GPIO_CMD_WRITE_HIGH,0);
		}
}

void led_Dimming(LED_NUM led_num)
{
	if(led_num == GPIO_LED1)
			{
			kal_cancel_timer(led1_timer);
			DclGPIO_Control(led1_handle,GPIO_CMD_WRITE_LOW,0);
			}
		else
			{
			kal_cancel_timer(led2_timer);
			DclGPIO_Control(led2_handle,GPIO_CMD_WRITE_LOW,0);
			}

}
void led1_flicker(void)
{
	
	if(Is_Led1_On == KAL_FALSE)
	{
		DclGPIO_Control(led1_handle,GPIO_CMD_WRITE_HIGH,0);
		Is_Led1_On = KAL_TRUE;
	}
	else
	{
		DclGPIO_Control(led1_handle,GPIO_CMD_WRITE_LOW,0);
		Is_Led1_On = KAL_FALSE;
	}
}
void led2_flicker(void)
{

	if(Is_Led2_On == KAL_FALSE)
	{
		DclGPIO_Control(led2_handle,GPIO_CMD_WRITE_HIGH,0);
		Is_Led2_On = KAL_TRUE;
	}
	else
	{
		DclGPIO_Control(led2_handle,GPIO_CMD_WRITE_LOW,0);
		Is_Led2_On = KAL_FALSE;
	}
}

DCL_STATUS gpio_led_control(LED_NUM led_num, LED_CTRL_CMD cmd, kal_uint16 freq)
{
	#if defined(DRV_GPIO_FOR_LED_AND_15_SEGMENT)
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_EN val;
	PMU_CTRL_LDO_BUCK_SET_VOLTAGE val1;
	val1.voltage = PMU_VOLT_02_800000_V;
	val1.mod = VMC;
	handle = DclPMU_Open(DCL_PMU,FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE,(DCL_CTRL_DATA_T *)&val1);

	val.enable = DCL_TRUE;
	val.mod = VMC;
	DclPMU_Control(handle, LDO_BUCK_SET_EN,(DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
	#endif
	
	#if defined(GPIO_NUMBER_FOR_LED1)
	if(led1_handle == 0)
	{
		ASSERT(0);
	}
	#endif
	
	#if defined(GPIO_NUMBER_FOR_LED2)
	if(led2_handle == 0)
	{
		ASSERT(0);
	}
	#endif
	switch(cmd)
	{
		case LED_CMD_FLICKER:
		{
			if(led_num == GPIO_LED1)
				{
				
				kal_set_timer(led1_timer, (kal_timer_func_ptr)led1_flicker, NULL, freq, freq);
				}
			else
				{
			
				kal_set_timer(led2_timer, (kal_timer_func_ptr)led2_flicker, NULL, freq, freq);
				}
			
			
			break;
		}
		case LED_CMD_DIMMING:
		{
			led_Dimming(led_num);//always diming
			break;
		}
		case LED_CMD_BRIGHTING:
		{
			led_brighting(led_num);//always lighting
			break;
		}
		default:
		{
            ASSERT(0);
            return STATUS_INVALID_CMD;
		}
	}
	return STATUS_OK;
}

DCL_STATUS gpio_15_segment_led_init()
{
#if defined(DRV_GPIO_FOR_LED_AND_15_SEGMENT)
	debug1_Handle = DclGPIO_Open(DCL_GPIO,62);
	debug2_Handle = DclGPIO_Open(DCL_GPIO,63);
	debug3_Handle = DclGPIO_Open(DCL_GPIO,64);
	debug4_Handle = DclGPIO_Open(DCL_GPIO,65);
	
	DclGPIO_Control(debug1_Handle,GPIO_CMD_SET_MODE_0,0);
	DclGPIO_Control(debug1_Handle,GPIO_CMD_SET_DIR_OUT,0);
	DclGPIO_Control(debug1_Handle,GPIO_CMD_WRITE_HIGH,0);


	DclGPIO_Control(debug2_Handle,GPIO_CMD_SET_MODE_0,0);
	DclGPIO_Control(debug2_Handle,GPIO_CMD_SET_DIR_OUT,0);
	DclGPIO_Control(debug2_Handle,GPIO_CMD_WRITE_HIGH,0);


	DclGPIO_Control(debug3_Handle,GPIO_CMD_SET_MODE_0,0);
	DclGPIO_Control(debug3_Handle,GPIO_CMD_SET_DIR_OUT,0);
	DclGPIO_Control(debug3_Handle,GPIO_CMD_WRITE_HIGH,0);


	DclGPIO_Control(debug4_Handle,GPIO_CMD_SET_MODE_0,0);
	DclGPIO_Control(debug4_Handle,GPIO_CMD_SET_DIR_OUT,0);
	DclGPIO_Control(debug4_Handle,GPIO_CMD_WRITE_HIGH,0);
	if(fifteen_segment_timer == NULL)
	fifteen_segment_timer = kal_create_timer("15_segment_TIMER");
	return STATUS_OK;
#else
	return STATUS_FAIL;
#endif
		
}

#if defined(DRV_GPIO_FOR_LED_AND_15_SEGMENT)
DCL_STATUS gpio_15_segment_display(void)
{
	kal_uint8 j;
	static kal_uint8 i = 0;

		i = i%table_count;
		
		if(word_to_display[i].Char_A == 1)
			DclGPIO_Control(debug1_Handle,GPIO_CMD_WRITE_HIGH,0);
		else
			DclGPIO_Control(debug1_Handle,GPIO_CMD_WRITE_LOW,0);
		if(word_to_display[i].Char_B == 1)
			DclGPIO_Control(debug2_Handle,GPIO_CMD_WRITE_HIGH,0);
		else
			DclGPIO_Control(debug2_Handle,GPIO_CMD_WRITE_LOW,0);
		if(word_to_display[i].Char_C == 1)
			DclGPIO_Control(debug3_Handle,GPIO_CMD_WRITE_HIGH,0);
		else
			DclGPIO_Control(debug3_Handle,GPIO_CMD_WRITE_LOW,0);
		if(word_to_display[i].Char_D == 1)
			DclGPIO_Control(debug4_Handle,GPIO_CMD_WRITE_HIGH,0);
		else
			DclGPIO_Control(debug4_Handle,GPIO_CMD_WRITE_LOW,0);

		i++;

	
		return STATUS_OK;
}
#endif

DCL_STATUS gpio_15_segment_led_control(kal_uint8 word1, kal_uint8 word2)
{
#if defined(DRV_GPIO_FOR_LED_AND_15_SEGMENT)
	kal_uint32 savedMask;
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_EN val;
	PMU_CTRL_LDO_BUCK_SET_VOLTAGE val1;
	val1.voltage = PMU_VOLT_02_800000_V;
	val1.mod = VMC;
	handle = DclPMU_Open(DCL_PMU,FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE,(DCL_CTRL_DATA_T *)&val1);

	val.enable = DCL_TRUE;
	val.mod = VMC;
	DclPMU_Control(handle, LDO_BUCK_SET_EN,(DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
	if(debug1_Handle == 0 || debug2_Handle == 0 || debug3_Handle == 0 || debug4_Handle == 0)
	{
		debug1_Handle = DclGPIO_Open(DCL_GPIO,62);
		debug2_Handle = DclGPIO_Open(DCL_GPIO,63);
		debug3_Handle = DclGPIO_Open(DCL_GPIO,64);
		debug4_Handle = DclGPIO_Open(DCL_GPIO,65);
	}
	if(fifteen_segment_timer == NULL)
		fifteen_segment_timer = kal_create_timer("15_segment_TIMER");
	
	switch(word1)
	{
		case '2':
		{
			savedMask = SaveAndSetIRQMask();
			word_to_display = char_to_display_table1;
			table_count = 6;
			RestoreIRQMask(savedMask);
			kal_set_timer(fifteen_segment_timer,(kal_timer_func_ptr) gpio_15_segment_display, NULL, 1, 1);
			break;
		}
		case '3':
		{
			if(word2 == 1)
			{
				savedMask = SaveAndSetIRQMask();
				word_to_display = char_to_display_table7;
				table_count = 7;
				RestoreIRQMask(savedMask);
				kal_set_timer(fifteen_segment_timer,(kal_timer_func_ptr) gpio_15_segment_display, NULL, 1, 1);
			}
			else
			{
				savedMask = SaveAndSetIRQMask();
				word_to_display = char_to_display_table6;
				table_count = 6;
				RestoreIRQMask(savedMask);
				kal_set_timer(fifteen_segment_timer, (kal_timer_func_ptr)gpio_15_segment_display,NULL, 1, 1);
			}
			break;
		}
		case '6':
		{
			if(word2 == 1)
				{
				savedMask = SaveAndSetIRQMask();
				word_to_display = char_to_display_table3;
				table_count = 8;
				RestoreIRQMask(savedMask);
				kal_set_timer(fifteen_segment_timer, (kal_timer_func_ptr)gpio_15_segment_display, NULL, 1, 1);
				}
			else
				{
				savedMask = SaveAndSetIRQMask();
				word_to_display = char_to_display_table2;
				table_count = 7;
				RestoreIRQMask(savedMask);
				kal_set_timer(fifteen_segment_timer,(kal_timer_func_ptr) gpio_15_segment_display, NULL, 1, 1);
				}
			break;
		}
		case 'd':
		{
			savedMask = SaveAndSetIRQMask();
			word_to_display = char_to_display_table12;
			table_count = 7;
			RestoreIRQMask(savedMask);
			kal_set_timer(fifteen_segment_timer,(kal_timer_func_ptr) gpio_15_segment_display, NULL, 1, 1);
			break;
		}
		case 'E':
		{
			if(word2 == 1)
				{
				savedMask = SaveAndSetIRQMask();
				word_to_display = char_to_display_table5;
				table_count = 7;
				RestoreIRQMask(savedMask);
				kal_set_timer(fifteen_segment_timer, (kal_timer_func_ptr)gpio_15_segment_display, NULL, 1, 1);
				}
			else
				{
				savedMask = SaveAndSetIRQMask();
				word_to_display = char_to_display_table4;
				table_count = 6;
				RestoreIRQMask(savedMask);
				kal_set_timer(fifteen_segment_timer,(kal_timer_func_ptr) gpio_15_segment_display, NULL, 1, 1);
				}
			break;
		}
		case 'h':
		{
			if(word2 == 1)
				{
				savedMask = SaveAndSetIRQMask();
				word_to_display = char_to_display_table9;
				table_count = 6;
				RestoreIRQMask(savedMask);
				kal_set_timer(fifteen_segment_timer, (kal_timer_func_ptr)gpio_15_segment_display, NULL, 1, 1);
				}
			else
				{
				savedMask = SaveAndSetIRQMask();
				word_to_display = char_to_display_table8;
				table_count = 5;
				RestoreIRQMask(savedMask);
				kal_set_timer(fifteen_segment_timer, (kal_timer_func_ptr)gpio_15_segment_display, NULL, 1, 1);
				}
			break;
		}
		case 'H':
		{
			if(word2 == 1)
				{
				savedMask = SaveAndSetIRQMask();
				word_to_display = char_to_display_table11;
				table_count = 7;
				RestoreIRQMask(savedMask);
				kal_set_timer(fifteen_segment_timer, (kal_timer_func_ptr)gpio_15_segment_display, NULL, 1, 1);
				}
			else
				{
				savedMask = SaveAndSetIRQMask();
				word_to_display = char_to_display_table10;
				table_count = 6;
				RestoreIRQMask(savedMask);
				kal_set_timer(fifteen_segment_timer,(kal_timer_func_ptr) gpio_15_segment_display, NULL, 1, 1);
				}
			break;
		}
		case 'I':
		{
			savedMask = SaveAndSetIRQMask();
			word_to_display = char_to_display_table17;
			table_count = 4;
			RestoreIRQMask(savedMask);
			kal_set_timer(fifteen_segment_timer, (kal_timer_func_ptr)gpio_15_segment_display, NULL, 1, 1);
			break;
		}
		case 'L':
		{
			savedMask = SaveAndSetIRQMask();
			word_to_display = char_to_display_table15;
			table_count = 3;
			RestoreIRQMask(savedMask);
			kal_set_timer(fifteen_segment_timer,(kal_timer_func_ptr) gpio_15_segment_display, NULL, 1, 1);
			break;
		}
		case 'N':
		{
			savedMask = SaveAndSetIRQMask();
			word_to_display = char_to_display_table16;
			table_count = 6;
			RestoreIRQMask(savedMask);
			kal_set_timer(fifteen_segment_timer,(kal_timer_func_ptr) gpio_15_segment_display, NULL, 1, 1);
			break;
		}
		case 'X':
		{
			savedMask = SaveAndSetIRQMask();
			word_to_display = char_to_display_table13;
			table_count = 4;
			RestoreIRQMask(savedMask);
			kal_set_timer(fifteen_segment_timer,(kal_timer_func_ptr) gpio_15_segment_display, NULL, 1, 1);
			break;
		}
		case 0:
		{
			kal_cancel_timer(fifteen_segment_timer);
			DclGPIO_Control(debug1_Handle,GPIO_CMD_WRITE_HIGH,0);
			DclGPIO_Control(debug2_Handle,GPIO_CMD_WRITE_HIGH,0);
			DclGPIO_Control(debug3_Handle,GPIO_CMD_WRITE_HIGH,0);
			DclGPIO_Control(debug4_Handle,GPIO_CMD_WRITE_HIGH,0);
			break;
		}
		default:
		{
			ASSERT(0);
			return STATUS_INVALID_CTRL_DATA;
		}
	}

	return STATUS_OK;
#else
	return STATUS_FAIL;
#endif
}

#else   //#if defined(DRV_GPIO_FOR_LED_AND_15_segment) && defined(__MTK_TARGET__)

DCL_STATUS gpio_led_init()
{
	return STATUS_FAIL;
}
void led_brighting(LED_NUM led_num)
{
	
}

void led_Dimming(LED_NUM led_num)
{

}
void led1_flicker(void)
{
	
}
void led2_flicker(void)
{
	
}

DCL_STATUS gpio_led_control(LED_NUM led_num, LED_CTRL_CMD cmd, kal_uint16 freq)
{
	return STATUS_FAIL;
}

DCL_STATUS gpio_15_segment_led_init()
{
	
	return STATUS_FAIL;
}

DCL_STATUS gpio_15_segment_display(void)
{
	return STATUS_FAIL;
}

DCL_STATUS gpio_15_segment_led_control(kal_uint8 word1, kal_uint8 word2)
{
	return STATUS_FAIL;
}

#endif   //#if defined(DRV_GPIO_FOR_LED_AND_15_segment)


