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
 *    keypad_bl.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the keypad task
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************
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
 *    kbdmain.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the keypad task
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
//#include 	"kal_release.h"

#include 	"drv_comm.h"
#include    "reg_base.h"
#include    "keypad_hw.h"
//#include    "keypad_sw.h"
//#include    "kbd_table.h"   
//#include    "drv_hisr.h"
//#include    "gpio_sw.h"
//#include   "eint.h"
//#include    "drv_trc.h"
//#include "kal_non_specific_general_types.h"
    #include "keypad.h"
    #include "kal_general_types.h"
    
#if !defined(DRV_KBD_NOT_EXIST)

const keypad_customize_function_struct *keypadCustomFunc;
const keypad_struct *keypad_comm_def;
extern const keypad_customize_function_struct *keypad_GetFunc(void);

extern kal_uint8 usbdlkey_position;

extern kal_bool USBDLKey_Pressed(void);
kal_bool kbd_IsKeyPressed(kal_uint8 key);
//define in bl_Init.c
extern kal_bool isGPTTImer3Started(void);
extern void startGPTTImer3(void);
extern kal_uint16 getGPTTImer3Value(void);
extern kal_uint32 INT_GetCurrentTime(void);

void keypad_customize_init(void)
{
   keypadCustomFunc=keypad_GetFunc();
   keypad_comm_def = keypadCustomFunc->keypad_Get_Data();
}   

/*************************************************************************
* FUNCTION                                                            
*	kbd_IsKeyPressed
*
* DESCRIPTION                                                           
*	
*	This function queries if a specific key is Pressed
*
* PARAMETERS
*  key        - Key ID to query
*
* RETURNS
*  KAL_TRUE   - The specific key is pressed
*  KAL_FALSE  - The specific key is NOT pressed or NOT supported
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool kbd_IsKeyPressed(kal_uint8 key)
{
	 kal_uint32 num_key, i;
   kal_uint16 u4KeyReg = 0;
   kal_bool fgKeyPressed = KAL_FALSE;
#if defined(__EXTEND_QWERTY_KEYPAD__) //assume it only support fot 32 key above
   kal_bool btmp = KAL_TRUE;
   kal_uint32 j, k;
   kal_uint16 reg, checkRow, bit;
   kal_uint8      key_bit_map[kbd_allkeys+KBD_COLUMN*2] = {0};
#endif //#if defined(__EXTEND_QWERTY_KEYPAD__) //assume it only support fot 32 key above
   
   num_key = sizeof(keypad_comm_def->keypad)/sizeof(kal_uint8);
   for (i=0;i<num_key;i++){
      if ( key == keypad_comm_def->keypad[i] ){ //key supported
#if defined(__EXTEND_QWERTY_KEYPAD__) //assume it only support fot 32 key above
         if(i >= kbd_allkeys) //GPO or GND
         {
            for(k=0; k<kbd_allkeys; ) //i already ++ in inner loop
            {
               // base on key register offset = 4 sequentially
               reg = DRV_KBD_Reg(KP_LOW_KEY + ((k>>4) <<2) );//  i/16 --> n-th register,  *4 --> register offset.
               for(j=0; j<16 && k<kbd_allkeys; j++, k++)
               {
                  bit = (reg >> (k&0xF) ) & 0x1; // select (i&0xF)-th bit in this register
                  if(key_bit_map[k] != bit)
                  {
                     key_bit_map[k] = bit; // put this bit into array
                  }
               }
            }
            // check which column is all low
            for(checkRow=0; checkRow<KBD_ROW; checkRow++)
            {
               btmp = btmp & ((key_bit_map[checkRow*KBD_COLUMN + (i%KBD_COLUMN) ] == 1) ? KAL_FALSE : KAL_TRUE); //if one key not press, we know this column not all low.
            }
            if(btmp == KAL_TRUE)
            {
               fgKeyPressed = KAL_TRUE; 
            }
            
           if(fgKeyPressed)
         {
            return KAL_TRUE;
         }
         else
         {
            return KAL_FALSE;
         }
         }
#endif
         // don't need to take care of key number define, num_key has information in it.
         if(i < 16) // key pressed
         {
            u4KeyReg = DRV_KBD_Reg(KP_LOW_KEY);
         }
         else if(i < 32)
         {
            i -= 16;
            u4KeyReg = DRV_KBD_Reg(KP_LOW_KEY + 0x4);
         }
         else if(i < 48)
         {
            i -= 32;
            u4KeyReg = DRV_KBD_Reg(KP_LOW_KEY + 0x8);
         }
         else if(i < 64)
         {
            i -= 48;
            u4KeyReg = DRV_KBD_Reg(KP_LOW_KEY + 0xC);
         }
         else
         {
            i -= 64;
            u4KeyReg = DRV_KBD_Reg(KP_LOW_KEY + 0x10);
         }
         
         if( (u4KeyReg & (1 << i)) == 0)
         {
            fgKeyPressed = KAL_TRUE;
         }
         
         if(fgKeyPressed)
         {
            return KAL_TRUE;
         }
         else
         {
            break;
         }
      }
   }
   return KAL_FALSE;	
}

kal_bool BL_kbd_IsKeyPressed(kal_uint8 key)
{
   static kal_bool first = KAL_TRUE;
   kal_uint32 n;
   kal_uint32 key_press_delay_start=0;
   kal_uint32 elapsed;
   kal_uint16 key_press_delay=6554;//   26/128Hz=200ms

   if(first)
   {
      first = KAL_FALSE;
      keypad_customize_init();

   
      key_press_delay_start=INT_GetCurrentTime();
      for(n=0; n<6000000; n++)
      {
         elapsed=INT_GetCurrentTime()-key_press_delay_start;
         if(elapsed>=key_press_delay)
	           break;
      }
   }
   return kbd_IsKeyPressed(key);
   
}

kal_bool BL_PowerKey_Press(void)
{
   return BL_kbd_IsKeyPressed(keypad_comm_def->powerkey_position);	
}

    
kal_bool USBDLKey_Pressed(void)
{
   return BL_kbd_IsKeyPressed(usbdlkey_position);
}

#else
void keypad_customize_init(void){;}
kal_bool USBDLKey_Pressed(void){return KAL_FALSE;}
#endif

