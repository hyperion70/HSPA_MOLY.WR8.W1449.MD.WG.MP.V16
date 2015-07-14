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
 *    kbd_jogball.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the keypad jogball feature
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
  *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

//#include 	"kal_release.h"
//#include    "keypad_sw.h"
#include    "intrCtrl.h"
#include   "eint.h"
//#include    "drv_trc.h"
#include    "kbd_table.h"  
//#include "kal_non_specific_general_types.h"
    #include "kal_general_types.h"
#include    "keypad.h"
#if !defined(DRV_KBD_NOT_EXIST)

#if !defined(__KBD_JOYSTICK_SUPPORT__)

#if defined(JOGBALL_SUPPORT)

extern kbd_struct KBD;

kal_uint8 eint_chans_up;
kal_uint8 eint_chans_down;
kal_uint8 eint_chans_left;
kal_uint8 eint_chans_right;
kbd_task_event JBXY;

#if defined(__DRV_EINT_EDGE_TRIGGER_NOT_UNMASK__)
kal_bool  jogball_up_state = LEVEL_LOW;
kal_bool  jogball_down_state = LEVEL_LOW;
kal_bool  jogball_left_state = LEVEL_LOW;
kal_bool  jogball_right_state = LEVEL_LOW;

/*****************************************************************************
 * FUNCTION
 *  JogBall_UP_HISR
 * DESCRIPTION
 *  Register the call back functions
 *  
 *  
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void JogBall_UP_HISR(void)
{	
   jogball_up_state = !jogball_up_state;
   EINT_Set_Polarity(eint_chans_up,jogball_up_state); 
   if (jogball_up_state == LEVEL_LOW)
   {
      if(JBXY == KEY_UP_EVENT)
      {
         kbd_SendKey(DEVICE_KEY_UP);
         JBXY = KEY_DIRECTION_EVENT_NUll;
      }
      else
      {
         JBXY=KEY_UP_EVENT;
      }
   }
}
/*****************************************************************************
FUNCTION
JogBall_DOWN_HISR
DESCRIPTION
Register the call back functions

  *	
  * PARAMETERS
  *	void
  * RETURNS
  *	void
******************************************************************************/

void JogBall_DOWN_HISR(void)
{		
   jogball_down_state= !jogball_down_state;
   EINT_Set_Polarity(eint_chans_down,jogball_down_state); 
   if (jogball_down_state == LEVEL_LOW)
   {
      if(JBXY == KEY_DOWN_EVENT)
      {
         kbd_SendKey(DEVICE_KEY_DOWN);
         JBXY=KEY_DIRECTION_EVENT_NUll;
      }
      else
      {
         JBXY=KEY_DOWN_EVENT;
      }
   }
}
/*****************************************************************************
* FUNCTION
*  JogBall_LEFT_HISR
* DESCRIPTION
*  Register the call back functions
*  
*  
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void JogBall_LEFT_HISR(void)
{		
   jogball_left_state = !jogball_left_state;
   EINT_Set_Polarity(eint_chans_left,jogball_left_state); 
   if (jogball_left_state == LEVEL_LOW)
   {
      if(JBXY == KEY_LEFT_EVENT)
      {
         kbd_SendKey(DEVICE_KEY_LEFT);
         JBXY=KEY_DIRECTION_EVENT_NUll;
      }
   		else
      {
         JBXY=KEY_LEFT_EVENT;
      }
   }
}
/****************************************************************************
* FUNCTION
*  JogBall_RIGHT_HISR
* DESCRIPTION
*  Register the call back functions
*  
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void JogBall_RIGHT_HISR(void)
{		
   jogball_right_state = !jogball_right_state;
   EINT_Set_Polarity(eint_chans_right,jogball_right_state); 
   if (jogball_right_state == LEVEL_LOW)
   {
      if(JBXY == KEY_RIGHT_EVENT)
      {
         kbd_SendKey(DEVICE_KEY_RIGHT);
         JBXY=KEY_DIRECTION_EVENT_NUll;
      }
   		else
      {
         JBXY=KEY_RIGHT_EVENT;
      }
   }
}
#else //#if defined(__DRV_EINT_EDGE_TRIGGER_NOT_UNMASK__)
/*****************************************************************************
* FUNCTION
*  JogBall_UP_HISR
* DESCRIPTION
*  Register the call back functions
*  
*  
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void JogBall_UP_HISR(void)
{	
   EINT_Mask(eint_chans_up);
   if(JBXY == KEY_UP_EVENT)
   {
     kbd_SendKey(DEVICE_KEY_UP);
      JBXY=KEY_DIRECTION_EVENT_NUll;
   }
   else
   {
      JBXY=KEY_UP_EVENT;
   }
   EINT_UnMask(eint_chans_up);
}
/*****************************************************************************
 FUNCTION
	JogBall_DOWN_HISR
 DESCRIPTION
	Register the call back functions
	
*	
* PARAMETERS
*	void
* RETURNS
*	void
******************************************************************************/

void JogBall_DOWN_HISR(void)
{		
   EINT_Mask(eint_chans_down);		 
   if(JBXY == KEY_DOWN_EVENT)
   {
        kbd_SendKey(DEVICE_KEY_DOWN);
        JBXY=KEY_DIRECTION_EVENT_NUll;
   }
   else
   {
      JBXY=KEY_DOWN_EVENT;
   }
   EINT_UnMask(eint_chans_down);
}
/*****************************************************************************
 * FUNCTION
 *  JogBall_LEFT_HISR
 * DESCRIPTION
 *  Register the call back functions
 *  
 *  
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void JogBall_LEFT_HISR(void)
{		
   EINT_Mask(eint_chans_left);
   if(JBXY == KEY_LEFT_EVENT)
   {
      kbd_SendKey(DEVICE_KEY_LEFT);
      JBXY=KEY_DIRECTION_EVENT_NUll;
   }
   else
   {
      JBXY=KEY_LEFT_EVENT;
   }
   EINT_UnMask(eint_chans_left);
}
/****************************************************************************
 * FUNCTION
 *  JogBall_RIGHT_HISR
 * DESCRIPTION
 *  Register the call back functions
 *  
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void JogBall_RIGHT_HISR(void)
{		
   EINT_Mask(eint_chans_right);
   if(JBXY == KEY_RIGHT_EVENT)
   {
      kbd_SendKey(DEVICE_KEY_RIGHT);
      JBXY=KEY_DIRECTION_EVENT_NUll;
   }
   else
   {
      JBXY=KEY_RIGHT_EVENT;
   }
   EINT_UnMask(eint_chans_right);	 
}

#endif //#if defined(__DRV_EINT_EDGE_TRIGGER_NOT_UNMASK__)

void Jogball_Reset(void)
{
   JBXY=KEY_DIRECTION_EVENT_NUll;
}


void Jogball_Init(void)
{
   /*****we will register the EINT interrupt callback functions****************************************/
   
   eint_chans_up=custom_eint_get_channel(jogball_up_eint_chann);
   EINT_Registration(eint_chans_up,KAL_FALSE,0,JogBall_UP_HISR, KAL_TRUE);	
   EINT_Set_Sensitivity(eint_chans_up, EDGE_SENSITIVE);/*******we should set the trigger by EDGE********/
   EINT_Set_Polarity(eint_chans_up, KAL_FALSE); //false -> 0, negative polarity   
   
   eint_chans_down=custom_eint_get_channel(jogball_down_eint_chann);
   EINT_Registration(eint_chans_down,KAL_FALSE,0,JogBall_DOWN_HISR, KAL_TRUE);
   EINT_Set_Sensitivity(eint_chans_down, EDGE_SENSITIVE);
   EINT_Set_Polarity(eint_chans_down, KAL_FALSE); //false -> 0, negative polarity
   
   eint_chans_left=custom_eint_get_channel(jogball_left_eint_chann);
   EINT_Registration(eint_chans_left,KAL_FALSE,0,JogBall_LEFT_HISR, KAL_TRUE);	
   EINT_Set_Sensitivity(eint_chans_left, EDGE_SENSITIVE);
   EINT_Set_Polarity(eint_chans_left, KAL_FALSE); //false -> 0, negative polarity
   
   eint_chans_right=custom_eint_get_channel(jogball_right_eint_chann);
   EINT_Registration(eint_chans_right,KAL_FALSE,0,JogBall_RIGHT_HISR, KAL_TRUE);
   EINT_Set_Sensitivity(eint_chans_right, EDGE_SENSITIVE);
   EINT_Set_Polarity(eint_chans_right, KAL_FALSE); //false -> 0, negative polarity
}
#endif //#if defined(JOGBALL_SUPPORT)


#endif /*!defined(__KBD_JOYSTICK_SUPPORT__)*/

#endif // #if !defined(DRV_KBD_NOT_EXIST)
