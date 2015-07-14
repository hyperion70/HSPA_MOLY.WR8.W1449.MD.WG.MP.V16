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
 ****************************************************************************/
#include "kal_public_defs.h" //MSBB change #include 	"stack_msgs.h"
#include 	"syscomp_config.h"
#include 	"drv_comm.h"
#include    "keypad_hw.h"
#include "drv_features.h"
#include    "keypad.h"
#include    "dcl.h"
#include    "gpt_sw.h"
#include    "intrCtrl.h"
#include    "kbd_table.h"   
#include	"l4_msgid.h"
#if defined(TOUCH_PAD_SUPPORT)
#include "touchpad_custom.h"
#endif
//#include   "eint.h"
#include    "drv_trc.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "kal_trace.h"

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_public_defs.h"

    
//#ifndef DRV_KP_OFF
#if !defined(DRV_KBD_NOT_EXIST)

#if !defined(__KBD_JOYSTICK_SUPPORT__)
kbd_struct KBD;

#if defined(DRV_WDT_RESET_PKEY_RELEASE)
extern void DRV_RESET(void);
extern kal_uint8  TargetReset;
#endif   /*DRV_WDT_RESET_PKEY_RELEASE*/
    

/*************************************************************************
* Function declaration
 *************************************************************************/
kal_bool 	         kbd_create(comptask_handler_struct **handle);
kal_bool             send_kbdilm = KAL_TRUE;

kal_bool             kbd_push_assert = KAL_FALSE;
kal_bool             kbd_pop_assert = KAL_FALSE;

kbd_buffer_struct    kbd_buffer;
static kal_uint8     kbd_press_event_count;


static kal_uint8     kbd_saved_pressed_key[KBD_KEY_DETECTION_CNT];
   #ifdef __KBD_2STEP_KEY_SUPPORT__
   static kal_bool     kbd_is_2steps_key;
   #endif
   static kal_uint8     kbd_ext_press_event_count;

//static DCL_HANDLE kbd_handle;

static void kbd_task_main(task_entry_struct *task_entry_ptr);
static kal_bool	kbd_task_reset(void);


#define KEY_INVALID		0xFF

/* To store keypad mode it is now. */
 kal_uint8  kbd_key_detection_mode = (kal_uint8)kbd_1_key_det_mode;
 kal_uint8  kbd_key_detection_new_mode = (kal_uint8)kbd_1_key_det_mode;

#if defined(TOUCH_PAD_SUPPORT)
kal_uint8 kbd_owner_stat = KBD_OWNER_NONE;
#endif

/*customize */
extern const keypad_customize_function_struct *keypad_GetFunc(void);
const keypad_customize_function_struct *keypadCustomFunc = NULL;
const keypad_struct *keypad_comm_def =NULL;

#if defined(TOUCH_PAD_SUPPORT)
kal_uint8 kbd_owner_stat = KBD_OWNER_NONE;
#endif
#if defined(__EXTEND_QWERTY_KEYPAD__)
#if defined(__CUST_NEW__)
extern char gpio_kbd_extend_QWERTY_pin;
#else//#if defined(__CUST_NEW__)
char gpio_kbd_extend_QWERTY_pin;
#endif//#if defined(__CUST_NEW__)
#endif //#if defined(__EXTEND_QWERTY_KEYPAD__)


#if defined(DRV_KBD_MEMORY_TRACE)
KBD_DRV_DBG_STRUCT KBD_DRV_DBG_INFO_DATA;
void kbd_drv_dbg_trace(kal_uint16 index, kal_uint32 time, kal_uint32 data1, kal_uint32 data2)
{
   kal_uint32        savedMask;
   savedMask = SaveAndSetIRQMask();
   {
      KBD_DRV_DBG_INFO_DATA.dbg_data[KBD_DRV_DBG_INFO_DATA.dbg_data_idx&(MAX_KBD_DRV_DBG_INFO_SIZE-1)].tag = index;
      KBD_DRV_DBG_INFO_DATA.dbg_data[KBD_DRV_DBG_INFO_DATA.dbg_data_idx&(MAX_KBD_DRV_DBG_INFO_SIZE-1)].time = time;
      KBD_DRV_DBG_INFO_DATA.dbg_data[KBD_DRV_DBG_INFO_DATA.dbg_data_idx&(MAX_KBD_DRV_DBG_INFO_SIZE-1)].data1 = data1;
      KBD_DRV_DBG_INFO_DATA.dbg_data[KBD_DRV_DBG_INFO_DATA.dbg_data_idx&(MAX_KBD_DRV_DBG_INFO_SIZE-1)].data2 = data2;
      KBD_DRV_DBG_INFO_DATA.dbg_data_idx++;
   }
   RestoreIRQMask(savedMask);
}
#endif //#if defined(DRV_KBD_MEMORY_TRACE)

static kal_bool KBD_GPTI_StartItem(DCL_HANDLE handle,kal_uint16 tick,void (*gptimer_func)(void *),void *parameter);
static kal_uint8 KBD_GPTI_GetHandle(DCL_HANDLE* handle);
static void KBD_GPTI_StopItem(DCL_HANDLE handle);
//static kal_uint8 KBD_GPTI_ReleaseHandle(DCL_HANDLE *handle);

static void kbd_push_onekey_to_kbdbuffer(kbd_event event,kal_uint8 key)  
{
     ASSERT(kbd_push_assert == KAL_FALSE);
   kbd_push_assert = KAL_TRUE;
   kbd_buffer.kbd_data_buffer[kbd_buffer.kbd_data_buffer_windex].Keyevent = event;
   kbd_buffer.kbd_data_buffer[kbd_buffer.kbd_data_buffer_windex].Keydata[0] = key;
   kbd_push_time_stamp();
   kbd_buffer.kbd_data_buffer_windex++;
   kbd_buffer.kbd_data_buffer_windex &= (kbd_buffer_size-1);
   kbd_push_assert = KAL_FALSE;
}

#if defined(__WISDOM__) && !defined(L4_NOT_PRESENT)
static void  kbd_push_onekey_to_kbdbuffer_ilm(kbd_event event,kal_uint8 key)
{
	#ifndef L4_NOT_PRESENT
    ilm_struct  *Kp_ilm;

    kbd_push_onekey_to_kbdbuffer(event,key);
    
   DRV_BuildPrimitive(Kp_ilm, MOD_DRVKBD, MOD_UEM, MSG_ID_DRVUEM_KEYPAD_IND, NULL);
   msg_send(Kp_ilm);
 #endif
 
}
#endif //#if defined(__WISDOM__) && !defined(L4_NOT_PRESENT)

 void kbdbuffer_get_roomleft_(kal_uint8* pleft)
{
     if ( kbd_buffer.kbd_data_buffer_rindex <= kbd_buffer.kbd_data_buffer_windex ) 
	{
        *pleft = kbd_buffer_size - kbd_buffer.kbd_data_buffer_windex + kbd_buffer.kbd_data_buffer_rindex - 1;
	}
	else
	{
		*pleft = kbd_buffer.kbd_data_buffer_rindex - kbd_buffer.kbd_data_buffer_windex - 1;
	}
}

static void kbd_pop_onekey_from_kbdbuffer( kbd_data* key_data) 
{
      ASSERT(kbd_pop_assert == KAL_FALSE);
      kbd_pop_assert = KAL_TRUE;
      key_data->Keyevent = kbd_buffer.kbd_data_buffer[kbd_buffer.kbd_data_buffer_rindex].Keyevent;
      key_data->Keydata[0] = kbd_buffer.kbd_data_buffer[kbd_buffer.kbd_data_buffer_rindex].Keydata[0];
     kbd_pop_time_stamp(key_data);
      kbd_buffer.kbd_data_buffer_rindex++;
      kbd_buffer.kbd_data_buffer_rindex &= (kbd_buffer_size-1);
      kbd_pop_assert = KAL_FALSE;
}

static void kbd_peek_onekey_from_kbdbuffer_index(kbd_data* key_data,kal_int8 index)
{
      ASSERT(index != kbd_buffer_size);
      key_data->Keyevent = kbd_buffer.kbd_data_buffer[index].Keyevent;
      key_data->Keydata[0] = kbd_buffer.kbd_data_buffer[index].Keydata[0];
}




   
#if defined(__EXTEND_QWERTY_KEYPAD__)
static void KBD_GPIO_WriteIO(char data, char port)
{
	DCL_HANDLE handle;
	handle=DclGPIO_Open(DCL_GPIO,port);	
	if(0==data)
		DclGPIO_Control(handle,GPIO_CMD_WRITE_LOW,0);
	else if(1==data)
		DclGPIO_Control(handle,GPIO_CMD_WRITE_HIGH,0);
	DclGPIO_Close(handle);	
}
#endif //#if defined(__EXTEND_QWERTY_KEYPAD__)

static kal_bool KBD_GPTI_StartItem(DCL_HANDLE handle,kal_uint16 tick,void (*gptimer_func)(void *),void *parameter)
{
	DCL_STATUS status;
	SGPT_CTRL_START_T start;
	start.u2Tick=tick;
	start.pfCallback=gptimer_func;
	start.vPara=parameter;
	
	status=DclSGPT_Control(handle,SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);
	
	if(STATUS_OK==status)
		return KAL_TRUE;
	else
		return KAL_FALSE;

}

static kal_uint8 KBD_GPTI_GetHandle(DCL_HANDLE* handle)
{
	*handle=DclSGPT_Open(DCL_GPT_CB, 0);
	return KAL_TRUE;
}
static void KBD_GPTI_StopItem(DCL_HANDLE handle)
{
	DclSGPT_Control(handle,SGPT_CMD_STOP,0);

}
/*
static kal_uint8 KBD_GPTI_ReleaseHandle(DCL_HANDLE *handle)
{
	DCL_HANDLE gpt_handle;
	DCL_STATUS status;
	status=DclSGPT_Close(&gpt_handle);
	
	//this is for return type transfer between new and old API.
	*handle=gpt_handle;
	if(STATUS_OK==status)
		return KAL_TRUE;
	else
		return KAL_FALSE;

}
*/
#if !defined(__WISDOM__) || defined(L4_NOT_PRESENT)
#define KBD_PUSH_ONEKEY_TO_KBDBUFFER kbd_push_onekey_to_kbdbuffer
#define KBD_GPTI_STARTITEM(a,b,c,d) KBD_GPTI_StartItem(a,b,c,d)
#define KBD_GPTI_GETHANDLE(a) KBD_GPTI_GetHandle(a)
#define KBD_GPTI_STOPITEM(a) KBD_GPTI_StopItem(a)
//#define KBD_GPTI_RELEASEHANDLE(a) KBD_GPTI_ReleaseHandle(a)
#else
#define DRV_KBD_ONLY_UP_DOWN_KEY
#define KBD_PUSH_ONEKEY_TO_KBDBUFFER kbd_push_onekey_to_kbdbuffer_ilm
#define KBD_GPTI_STARTITEM(a,b,c,d) 0
#define KBD_GPTI_GETHANDLE(a)       0
#define KBD_GPTI_STOPITEM(a)        ;
//#define KBD_GPTI_RELEASEHANDLE(a) ;
#endif  //#if !defined(WISDOM_MMI) || defined(L4_NOT_PRESENT)

/*************************************************************************
* FUNCTION                                                            
*	kbd_create
*
* DESCRIPTION                                                           
*	This function implements xyz entity's create handler.
*
* PARAMETERS
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool
kbd_create(comptask_handler_struct **handle)
{
#if defined(__MEUT__)
	return KAL_FALSE;
#else
	static const comptask_handler_struct kbd_handler_info = 
	{
		kbd_task_main,			/* task entry function */
		NULL,		  	/* task initialization function */
		NULL, 	/* task configuration function */
		kbd_task_reset,		/* task reset handler */
		kbd_task_end			/* task termination handler */
	};

	*handle = (comptask_handler_struct *)&kbd_handler_info;
	return KAL_TRUE;
#endif
}



kal_bool kbd_IsExtendQwertyKey(kal_uint8 key)
{
    #if defined(__EXTEND_QWERTY_KEYPAD__) //assume it only support fot 32 key above
    kal_uint32 num_key, i;
    num_key = sizeof(keypad_comm_def->keypad)/sizeof(kal_uint8);
    for(i = 0; i < num_key; i++)
        {
               if ( key == keypad_comm_def->keypad[i] )//key supported
                {
                    if(i >= kbd_allkeys)
                        return KAL_TRUE;
                }
        }
    
    return KAL_FALSE;
    
    #else
    return KAL_FALSE;
    #endif
    
}
/*************************************************************************
* FUNCTION															  
*	kbd_IsKeyButtonSupported
*
* DESCRIPTION															
*	
*	This function queries if a specific key is supported or NOT
*  This function exists whether we support joystick or not
*
* PARAMETERS
*  key		  - Key ID to query
*
* RETURNS
*  KAL_TRUE   - The specific key is supported in this phone
*  KAL_FALSE  - The specific key is NOT supported in this phone
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool kbd_IsKeySupported(kal_uint8 key)
{
	kal_uint32 num_key, i;
	kal_bool ret = KAL_FALSE;	
	num_key = sizeof(keypad_comm_def->keypad)/sizeof(kal_uint8);
	for (i=0;i<num_key;i++){
		if ( key == keypad_comm_def->keypad[i] ){
#if !defined(LOW_COST_SUPPORT)
			drv_trace1(TRACE_GROUP_10, KBD_KEY_QUERY_SUPPORTED, key);
#endif // #if !defined(LOW_COST_SUPPORT)
			return KAL_TRUE;
		}
	}
#if !defined(LOW_COST_SUPPORT)
	drv_trace1(TRACE_GROUP_10, KBD_KEY_QUERY_NOT_SUPPORTED, key);
#endif // #if !defined(LOW_COST_SUPPORT)
	return ret;
}


kal_uint32 kbd_SendKey(kal_uint8 key)
{
    kal_uint32 result = 0;
    
    if(DEVICE_KEY_UP == key)
        kal_set_eg_events(KBD.event,KEY_UP_EVENT,KAL_OR);
    else if (DEVICE_KEY_DOWN == key)
         kal_set_eg_events(KBD.event,KEY_DOWN_EVENT,KAL_OR);
    else if (DEVICE_KEY_LEFT == key)
        kal_set_eg_events(KBD.event,KEY_LEFT_EVENT,KAL_OR);
    else if (DEVICE_KEY_RIGHT == key)
        kal_set_eg_events(KBD.event,KEY_RIGHT_EVENT,KAL_OR);
    else
        {;}

    return result;
}

static void kbd_SendMsg_To_UEM(void)
{

#if !defined(DRV_KBD_ONLY_UP_DOWN_KEY)
		 ilm_struct  *Kp_ilm;
#ifndef L4_NOT_PRESENT
		 //kal_bool 	  btmp;
#endif   /*L4_NOT_PRESENT*/
		 
		 if (send_kbdilm)
		 {
			send_kbdilm = KAL_FALSE;
#ifndef L4_NOT_PRESENT
			DRV_BuildPrimitive(Kp_ilm,
			   MOD_DRVKBD,
			   MOD_UEM,
			   MSG_ID_DRVUEM_KEYPAD_IND,
			   NULL);
			//btmp = msg_send_ext_queue(Kp_ilm);
			msg_send(Kp_ilm);
#endif   /*L4_NOT_PRESENT*/
		 }
#endif /*!defined(DRV_KBD_ONLY_UP_DOWN_KEY)*/

}
void Kbd_Initiaze(void)
{
  kal_uint8 index;
   for (index = 0; index < KBD_KEY_DETECTION_CNT; index++)
   {
      KBD_GPTI_GETHANDLE(&KBD.gpthandle[index]);
   }
#ifdef __EXTRA_A_B_KEY_SUPPORT__
#if !defined(LOW_COST_SUPPORT)
         drv_trace0(TRACE_GROUP_10, KBD_EXT_A_B_KEY_SUPPORT);
#endif // #if !defined(LOW_COST_SUPPORT)
        KBD_GPTI_GETHANDLE(&KBD.gpthandle[KBD_KEY_DETECTION_CNT]);
         KBD_GPTI_GETHANDLE(&KBD.gpthandle[KBD_KEY_DETECTION_CNT+1]);
 #endif
	  
   kbd_ext_press_event_count = 0;

#ifdef __KBD_2STEP_KEY_SUPPORT__
#if !defined(LOW_COST_SUPPORT)
   drv_trace0(TRACE_GROUP_10, KBD_EXT_2STEP_KEY_SUPPORT);
#endif // #if !defined(LOW_COST_SUPPORT)
   KBD_GPTI_GETHANDLE(&KBD.kbd_2key_handle);
   #endif

#if defined(__EXTEND_QWERTY_KEYPAD__)
	  KBD.polling_timeout = 10; /*0.1s*/
	  KBD_GPTI_GETHANDLE(&KBD.kbd_extend_gpthandle);
#endif //#if defined(__EXTEND_QWERTY_KEYPAD__)

  
    KBD.longpress_timeout = 200; /*2s*/
   KBD.repeat_time = 100;  /*1s*/   

if (KBD.event == NULL)
	KBD.event = kal_create_event_group("KBDEVT");

if(keypad_comm_def == NULL)
{ 
	keypadCustomFunc=keypad_GetFunc();
   keypad_comm_def = keypadCustomFunc->keypad_Get_Data();
   
#if defined(__EXTEND_QWERTY_KEYPAD__)
#if !defined(__CUST_NEW__)
	  gpio_kbd_extend_QWERTY_pin = keypad_comm_def->kbd_extend_row_GPO;
#endif//#if defined(__CUST_NEW__)
#endif //#if defined(__EXTEND_QWERTY_KEYPAD__)
}

#if defined(DRV_KBD_GPIO_DRIVING_2MA)
	DRV_KBD_SetData(CONFG_base+0x700, 0xE000, 0x8000);
#endif//#if defined(DRV_KBD_GPIO_DRIVING_2MA)

//KBD.Kbd_event_func_cb = kbd_SendMsg_To_UEM;

}

kal_bool Kbd_GetKeyDatas(kbd_data *keydata)
{
   kal_bool result;

   #ifdef __EXTRA_A_B_KEY_SUPPORT__
   EINT_Mask(EINT_A_KEY);
   EINT_Mask(EINT_B_KEY);
   #endif
   IRQMask(IRQ_GPT_CODE);

 //  IRQMask(IRQ_KPAD_CODE);
   KBD_MASKIRQ;
 
   if (kbd_buffer.kbd_data_buffer_rindex != kbd_buffer.kbd_data_buffer_windex)
   {
      #ifdef TWO_KEY_ENABLE
         kbd_pop_twokey_from_kbdbuffer(keydata);  
         drv_trace4(TRACE_GROUP_10, KBD_GET_TWO_KEY_DATA, keydata->Keyevent, keydata->Keydata[0], keydata->Keydata[1], 0);
      #else /*!TWO_KEY_ENABLE*/
         kbd_pop_onekey_from_kbdbuffer(keydata);
 
         drv_trace2(TRACE_GROUP_10, KBD_GET_ONE_KEY_DATA, keydata->Keyevent, keydata->Keydata[0]);
      #endif   /*TWO_KEY_ENABLE*/
      result = KAL_TRUE;
   }
   else
   {
   	drv_trace0(TRACE_GROUP_10, KBD_NO_KEY_DATA);
#if defined(DRV_KBD_ONLY_UP_DOWN_KEY)
      send_kbdilm = KAL_FALSE; //always false, send ilm every key up/down action
#else
      send_kbdilm = KAL_TRUE;
#endif //#if defined(DRV_KBD_ONLY_UP_DOWN_KEY)
      result = KAL_FALSE;
   }
   
   KBD_UNMASKIRQ;
   IRQUnmask(IRQ_GPT_CODE);
   #ifdef __EXTRA_A_B_KEY_SUPPORT__
   EINT_UnMask(EINT_A_KEY);
   EINT_UnMask(EINT_B_KEY);
   #endif
   return result;
}


/*************************************************************************
* FUNCTION                                                            
*	Kbd_PeekBuffer
*
* DESCRIPTION                                                           
*	This function implements to peek a key event from the buffer.
* 
* PARAMETERS
*
* RETURNS
*	KAL_TRUE  - get the key event sucessfully.
* KAL_FALSE - there is no key event in the buffer
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool Kbd_PeekKeyDatas(kbd_data *keydata, kal_bool specify_read, 
                                            kal_uint32 read_pointer,kal_uint32* current_read_pointer)
{
      kal_bool result;
   
#ifdef __EXTRA_A_B_KEY_SUPPORT__
   EINT_Mask(EINT_A_KEY);
   EINT_Mask(EINT_B_KEY);
#endif
   IRQMask(IRQ_GPT_CODE);
   KBD_MASKIRQ;

   if (kbd_buffer.kbd_data_buffer_rindex != kbd_buffer.kbd_data_buffer_windex)
   {
        if(!specify_read)   // the L4C not specify the read postion, default send the read pointer data to L4C
        {
            kbd_peek_onekey_from_kbdbuffer_index(keydata, kbd_buffer.kbd_data_buffer_rindex);

            *current_read_pointer = kbd_buffer.kbd_data_buffer_rindex; // return the current read position
             result = KAL_TRUE;
        }
        else  // the L4C specify which position need to be read
        {
                    kbd_peek_onekey_from_kbdbuffer_index(keydata, read_pointer%kbd_buffer_size);

            *current_read_pointer = kbd_buffer.kbd_data_buffer_rindex;
             result = KAL_TRUE;
        }

   }
   else
   {
      result = KAL_FALSE;
   }
    
    KBD_UNMASKIRQ;
    IRQUnmask(IRQ_GPT_CODE);
#ifdef __EXTRA_A_B_KEY_SUPPORT__
    EINT_UnMask(EINT_A_KEY);
    EINT_UnMask(EINT_B_KEY);
#endif
   
   return result;
    
}



void KBDRepeatHandler(void *parameter)
{
   kal_uint8      roomleft;
   kal_uint32      handle;
   kal_uint32      index;
   kal_uint8      key_event;

   KBD_MASKIRQ;
   
   kbdbuffer_get_roomleft(roomleft);
 
   index = (kal_uint32)parameter;
   handle = KBD.gpthandle[index];
   
   #ifndef KBD_DBGMODE
      if (roomleft <= (kbd_press_event_count+kbd_ext_press_event_count))
      {
#if !defined(LOW_COST_SUPPORT)
      	drv_trace0(TRACE_GROUP_9, KBD_REPEAT_HANDLER_NO_ROOM);
#endif // #if !defined(LOW_COST_SUPPORT)

         KBD_GPTI_STARTITEM(handle,
                  KBD.repeat_time,
                  KBDRepeatHandler,
                  parameter);

      KBD_UNMASKIRQ;
      
         return;
      }
   #endif
   #ifdef __EXTRA_A_B_KEY_SUPPORT__
   if (index < KBD_KEY_DETECTION_CNT)
   {
   #endif
      key_event = kbd_saved_pressed_key[index];
   #ifdef __EXTRA_A_B_KEY_SUPPORT__
   }
   else
   {
      key_event = (index==KBD_KEY_DETECTION_CNT) ? DEVICE_KEY_EXT_A: DEVICE_KEY_EXT_B;
   }
   #endif
#if !defined(LOW_COST_SUPPORT)
   drv_trace2(TRACE_GROUP_10, KBD_PUT_DATA_TO_BUFFER, kbd_onekey_repeated, key_event);
#endif // #if !defined(LOW_COST_SUPPORT)
   KBD_PUSH_ONEKEY_TO_KBDBUFFER(kbd_onekey_repeated, key_event);
 
   kbd_SendMsg_To_UEM( );


   KBD_GPTI_STARTITEM(handle,
                  KBD.repeat_time,
                  KBDRepeatHandler,
                  parameter);
   
   KBD_DBG(__LINE__, KBD_GetTimeStamp(), ust_get_current_time(),0);
   
   KBD_UNMASKIRQ;
}


#if defined(__EXTEND_QWERTY_KEYPAD__)
void KBDPollingHandler(void *parameter)
{
   KBD_DBG(__LINE__, KBD_GetTimeStamp(), ust_get_current_time(),0);
   /*lint -e(534)*/kal_set_eg_events(KBD.event,KBD_STATUS_CHANGE_EVENT,KAL_OR);
}
#endif

void KBDTimeOutHandler(void *parameter)
{
   kal_uint8      roomleft;
   kal_uint32      handle;
   kal_uint32      index;
   kal_uint8      key_event;

 KBD_MASKIRQ;

   kbdbuffer_get_roomleft(roomleft);
   #ifdef KBD_DBGMODE
      ASSERT(roomleft != 0);
   #endif

   index = (kal_uint32)parameter;
   handle = KBD.gpthandle[index];
   #ifndef KBD_DBGMODE
      if (roomleft <= (kbd_press_event_count+kbd_ext_press_event_count))
      {
#if !defined(LOW_COST_SUPPORT)
      	drv_trace0(TRACE_GROUP_9, KBD_LONGPRESS_HANDLER_NO_ROOM);
#endif // #if !defined(LOW_COST_SUPPORT)
         //btmp = KBD_GPTI_STARTITEM(handle,
         KBD_GPTI_STARTITEM(handle,
                  KBD.repeat_time,
                  KBDTimeOutHandler,
                  parameter);

         //KBD_IRQUnmask(IRQ_KPAD_CODE);
         KBD_UNMASKIRQ;
         return;
      }
   #endif
   #ifdef __EXTRA_A_B_KEY_SUPPORT__
   if (index < KBD_KEY_DETECTION_CNT)
   {
   #endif
      key_event = kbd_saved_pressed_key[index];
   #ifdef __EXTRA_A_B_KEY_SUPPORT__
   }
   else
   {
      key_event = (index==KBD_KEY_DETECTION_CNT) ? DEVICE_KEY_EXT_A: DEVICE_KEY_EXT_B;
   }
   #endif
#if !defined(LOW_COST_SUPPORT)
   drv_trace2(TRACE_GROUP_10, KBD_PUT_DATA_TO_BUFFER, kbd_onekey_longpress, key_event);
#endif // #if !defined(LOW_COST_SUPPORT)
   KBD_PUSH_ONEKEY_TO_KBDBUFFER(kbd_onekey_longpress, key_event);
    
   kbd_SendMsg_To_UEM( );


   KBD_GPTI_STARTITEM(handle,
                  KBD.repeat_time,
                  KBDRepeatHandler,
                  parameter);

   KBD_UNMASKIRQ;
   
}

#ifdef __KBD_2STEP_KEY_SUPPORT__
void KBD2KeyHandler(void *parameter)
{
   kal_uint8      roomleft;
    KBD_MASKIRQ;
   ASSERT((keypadCustomFunc->keypad_check_fullpress)!=NULL);
   if(keypadCustomFunc->keypad_check_fullpress())
   {
      kbdbuffer_get_roomleft(roomleft);
      #ifdef KBD_DBGMODE
         ASSERT(roomleft != 0);
      #else
         if (roomleft <= (kbd_press_event_count+kbd_ext_press_event_count+1))
         {
#if !defined(LOW_COST_SUPPORT)
         	drv_trace0(TRACE_GROUP_9, KBD_2STEP_KEY_HANDLER_NO_ROOM);
#endif // #if !defined(LOW_COST_SUPPORT)
       
            KBD_GPTI_STARTITEM(KBD.gpthandle[0],
                           10,
                           KBD2KeyHandler,
                           NULL);

         KBD_UNMASKIRQ;
            return;
         }
      #endif   /*KBD_DBGMODE*/
      

#if !defined(LOW_COST_SUPPORT)
         drv_trace2(TRACE_GROUP_10, KBD_PUT_DATA_TO_BUFFER, kbd_onekey_fullpress, kbd_saved_pressed_key[0]);
#endif // #if !defined(LOW_COST_SUPPORT)
         KBD_PUSH_ONEKEY_TO_KBDBUFFER(kbd_onekey_fullpress,kbd_saved_pressed_key[0]);
         /* start longpress timer after full press. */
		
		   KBD_GPTI_STARTITEM(KBD.gpthandle[0],
                        KBD.longpress_timeout,
                        KBDTimeOutHandler,
                        0);
      
      kbd_SendMsg_To_UEM();
      
      KBD_GPTI_STOPITEM(KBD.kbd_2key_handle);                  
   }
   else
   {
   
      KBD_GPTI_STARTITEM(KBD.kbd_2key_handle,
                  10,
                  KBD2KeyHandler,
                  NULL);   
   }   
   
  KBD_UNMASKIRQ;
}
#endif

 /*************************************************************************
   * FUNCTION                                                            
   *	kbd_get_keypad_status_reg
   *
   * DESCRIPTION                                                           
   *	
   *	This function is to get the keypad mapping register value
   *
   * PARAMETERS
   *  pkeypad_status        - pointer to the keypad mapping register
   *
   *  RETURNS
   *  None
   *  
   *
   * Local AFFECTED
   *
   *************************************************************************/
   
static void kbd_get_keypad_status_reg(kbd_map_reg_struct *pkeypad_status)
  {
  	 DCL_HANDLE kbdhandle;
	 DCL_CTRL_DATA_T reg;
	 kbdhandle = DclHKBD_Open(DCL_KBD, MOD_DRVKBD);
	 DclHKBD_Control(kbdhandle, HKBD_CMD_GET_KEY_STA_MAP, (DCL_CTRL_DATA_T*)&reg);	 
	 pkeypad_status->kbdmap_reg = reg.rKBDCtrlStaMap.kbdmap_reg;
	 pkeypad_status->kbdmap_reg1= reg.rKBDCtrlStaMap.kbdmap_reg1;
	 pkeypad_status->kbdmap_reg2= reg.rKBDCtrlStaMap.kbdmap_reg2;
   }

   /*************************************************************************
   * FUNCTION                                                            
   *	Kbd_Jogball_EventHandler
   *
   * DESCRIPTION                                                           
   *	
   *	This function is to handler the event of Jogball HISR.
   *
   * PARAMETERS
   *  event_group        - the current event id.
   *
   *  RETURNS
   *  None
   *  
   *
   * Local AFFECTED
   *
   *************************************************************************/
   
   static void Kbd_Jogball_EventHandler(kal_uint32 event_group)
   {
        if(event_group & KEY_UP_EVENT)
        {
            KBD_PUSH_ONEKEY_TO_KBDBUFFER(kbd_onekey_press,DEVICE_KEY_UP);      
            KBD_PUSH_ONEKEY_TO_KBDBUFFER(kbd_onekey_release,DEVICE_KEY_UP);
        }
        else if(event_group & KEY_DOWN_EVENT)
        {
            KBD_PUSH_ONEKEY_TO_KBDBUFFER(kbd_onekey_press,DEVICE_KEY_DOWN);      
            KBD_PUSH_ONEKEY_TO_KBDBUFFER(kbd_onekey_release,DEVICE_KEY_DOWN);
        }
        else if(event_group & KEY_LEFT_EVENT)
        {
            KBD_PUSH_ONEKEY_TO_KBDBUFFER(kbd_onekey_press,DEVICE_KEY_LEFT);      
            KBD_PUSH_ONEKEY_TO_KBDBUFFER(kbd_onekey_release,DEVICE_KEY_LEFT);
        }
        else if(event_group & KEY_RIGHT_EVENT)
        {
            KBD_PUSH_ONEKEY_TO_KBDBUFFER(kbd_onekey_press,DEVICE_KEY_RIGHT);      
            KBD_PUSH_ONEKEY_TO_KBDBUFFER(kbd_onekey_release,DEVICE_KEY_RIGHT);
        }
        else
            return;

        kbd_SendMsg_To_UEM();
   }

   
   /*************************************************************************
   * FUNCTION                                                            
   *	kbd_SwitchMode_EventHandler
   *
   * DESCRIPTION                                                           
   *	
   *	This function is to handler the event of switch detection mode.
   *
   * PARAMETERS
   *  pbuf_full        - pointer to the 
   *
   *  RETURNS
   *  None
   *  
   *
   * Local AFFECTED
   *
   *************************************************************************/
   
   static void kbd_SwitchMode_EventHandler(kal_bool *pbuf_full, keypad_status_struct* pkbd_status_Saved)
   {
      kal_uint8      key_index;
      kal_uint8      roomleft;
#if defined(__EXTEND_QWERTY_KEYPAD__) 
      kal_uint8      checkCol;
#endif //#if defined(__EXTEND_QWERTY_KEYPAD__) 
      //kal_bool       btmp;
      ASSERT(pbuf_full != NULL);
#ifdef __EXTRA_A_B_KEY_SUPPORT__
      EINT_Mask(EINT_A_KEY);
      EINT_Mask(EINT_B_KEY);
#endif
      /* Stop all longpress or repeated timer. */
      for (key_index = 0; key_index < KBD_GPT_HDL_CNT; key_index++)
      {
         KBD_GPTI_STOPITEM(KBD.gpthandle[key_index]);
      }
#ifdef __KBD_2STEP_KEY_SUPPORT__
      KBD_GPTI_STOPITEM(KBD.kbd_2key_handle);
      kbd_is_2steps_key = KAL_FALSE;
#endif
      kbdbuffer_get_roomleft(roomleft);
#ifdef KBD_DBGMODE
      ASSERT(roomleft >= (kbd_press_event_count+kbd_ext_press_event_count+1));
#else  /*KBD_DBGMODE*/
      /* Buffer room left should more than reserved release key events and plus one 
      switch mode event. */
      if (roomleft <= (kbd_press_event_count+kbd_ext_press_event_count+1))
      {
         /* Not enough room, should wait. */
         //  buf_full = KAL_TRUE;
         *pbuf_full = KAL_TRUE;
      }
      else
      {
         //buf_full = KAL_FALSE;
         *pbuf_full = KAL_FALSE;
#endif   /*KBD_DBGMODE*/

#if defined(__EXTEND_QWERTY_KEYPAD__)
        pkbd_status_Saved->extend_switch_mode_key = KAL_FALSE;
        pkbd_status_Saved->extend_key_switch_pressed_num = 0;
        for(key_index = 0; key_index < KBD_KEY_DETECTION_CNT; key_index++)
        {
            pkbd_status_Saved->kbd_switch_mode_extend_press_key[key_index] = KEY_INVALID;
        }
#endif

         /* Compel to send key release event before mode switch. */
         for (key_index = 0; key_index < KBD_KEY_DETECTION_CNT; key_index++)
         {
            if (kbd_saved_pressed_key[key_index] != KEY_INVALID)
            {
               // power key should not send release event and we should keep the long press event in order to power off
               if(kbd_saved_pressed_key[key_index] != keypad_comm_def->powerkey_position) 
               {
#if !defined(LOW_COST_SUPPORT)
                  drv_trace2(TRACE_GROUP_8, KBD_PUT_DATA_TO_BUFFER, kbd_onekey_release, kbd_saved_pressed_key[key_index]);
#endif // #if !defined(LOW_COST_SUPPORT)
#if defined(__EXTEND_QWERTY_KEYPAD__)
                  if(kbd_IsExtendQwertyKey(kbd_saved_pressed_key[key_index]) == KAL_TRUE)
                    {
                        kal_prompt_trace(MOD_DRVKBD, "extend key pressed during mode switch");
                        
                        pkbd_status_Saved->extend_switch_mode_key = KAL_TRUE;
                        pkbd_status_Saved->extend_key_switch_pressed_num++;
                        pkbd_status_Saved->kbd_switch_mode_extend_press_key[key_index] = kbd_saved_pressed_key[key_index];
                    }
#endif
                  KBD_PUSH_ONEKEY_TO_KBDBUFFER(kbd_onekey_release,kbd_saved_pressed_key[key_index]);
                  kbd_saved_pressed_key[key_index] = KEY_INVALID;
               } 
            }
         }
#ifdef __EXTRA_A_B_KEY_SUPPORT__
         if (kbd_key_detection_mode != kbd_1_key_det_mode)
         {
            if (KBD.ext_status[0] == LEVEL_LOW){
#if !defined(LOW_COST_SUPPORT)
               drv_trace2(TRACE_GROUP_8, KBD_PUT_DATA_TO_BUFFER, kbd_onekey_release, DEVICE_KEY_EXT_A);
#endif // #if !defined(LOW_COST_SUPPORT)
               KBD_PUSH_ONEKEY_TO_KBDBUFFER(kbd_onekey_release,DEVICE_KEY_EXT_A);
            }
            if (KBD.ext_status[1] == LEVEL_LOW)
            {
#if !defined(LOW_COST_SUPPORT)
               drv_trace2(TRACE_GROUP_8, KBD_PUT_DATA_TO_BUFFER, kbd_onekey_release, DEVICE_KEY_EXT_B);
#endif // #if !defined(LOW_COST_SUPPORT)
               KBD_PUSH_ONEKEY_TO_KBDBUFFER(kbd_onekey_release,DEVICE_KEY_EXT_B);
            }
         }
         KBD.ext_status[0] = LEVEL_HIGH;
         KBD.ext_status[1] = LEVEL_HIGH;
#endif
         /* Reset all key status. */
         kbd_press_event_count = 0;
         kbd_ext_press_event_count = 0;
#if defined(__EXTEND_QWERTY_KEYPAD__) 

		  for(checkCol=0; checkCol<KBD_COLUMN; checkCol++)
		    { //restore to saved status, it need current status for reference
		        pkbd_status_Saved->key_column_all_low_GND[checkCol] = KAL_FALSE; //clear temp
		        pkbd_status_Saved->key_column_all_low_GPO[checkCol]= KAL_FALSE; //clear temp
		    }
#endif	  

		 
         // if power key is pressed, we should keep the long press timer for the long press event.	
         for (key_index = 0; key_index < KBD_KEY_DETECTION_CNT; key_index++)
         {
            if( kbd_saved_pressed_key[key_index] == keypad_comm_def->powerkey_position)
            {
               kbd_saved_pressed_key[key_index] = KEY_INVALID;
               kbd_press_event_count = 1;
               kbd_saved_pressed_key[0] = keypad_comm_def->powerkey_position;
               /* Start the longpress timer for power key. */
               //btmp = KBD_GPTI_STARTITEM(KBD.gpthandle[0],
               KBD_GPTI_STARTITEM(KBD.gpthandle[0],
                  KBD.longpress_timeout,
                  KBDTimeOutHandler,
                  (void *)0);
               break;
            } 
         }
         /* Push two key detection enable/disable event to key buffer. */
         if (kbd_key_detection_new_mode == (kal_uint8)kbd_1_key_det_mode)
         {
#if !defined(LOW_COST_SUPPORT)
            drv_trace2(TRACE_GROUP_8, KBD_PUT_DATA_TO_BUFFER, kbd_multikey_detection_disable, 0);
#endif // #if !defined(LOW_COST_SUPPORT)
            KBD_PUSH_ONEKEY_TO_KBDBUFFER(kbd_multikey_detection_disable,0);
         }
         else if (kbd_key_detection_new_mode == (kal_uint8)kbd_2_keys_det_mode)
         {
#if !defined(LOW_COST_SUPPORT)
            drv_trace2(TRACE_GROUP_8, KBD_PUT_DATA_TO_BUFFER, kbd_twokey_detection_enable, 0);
#endif // #if !defined(LOW_COST_SUPPORT)
            KBD_PUSH_ONEKEY_TO_KBDBUFFER(kbd_twokey_detection_enable,0);
#ifdef __EXTRA_A_B_KEY_SUPPORT__
            EINT_Set_Polarity(EINT_A_KEY, LEVEL_LOW);
            EINT_Set_Polarity(EINT_B_KEY, LEVEL_LOW);
#endif
         }
#ifdef __THREE_KEY_DETECTION_SWITCHABLE__
         else if (kbd_key_detection_new_mode == kbd_3_keys_det_mode)
         {
#if !defined(LOW_COST_SUPPORT)
            drv_trace2(TRACE_GROUP_8, KBD_PUT_DATA_TO_BUFFER, kbd_threekey_detection_enable, 0);
#endif // #if !defined(LOW_COST_SUPPORT)
            KBD_PUSH_ONEKEY_TO_KBDBUFFER(kbd_threekey_detection_enable,0);
#ifdef __EXTRA_A_B_KEY_SUPPORT__
            EINT_Set_Polarity(EINT_A_KEY, LEVEL_LOW);
            EINT_Set_Polarity(EINT_B_KEY, LEVEL_LOW);
#endif
         }
#endif
         kbd_key_detection_mode = kbd_key_detection_new_mode;
#ifndef KBD_DBGMODE
      } /* if (roomleft >= (kbd_press_event_count+1)) */
#endif
#ifdef __EXTRA_A_B_KEY_SUPPORT__
      EINT_UnMask(EINT_A_KEY);
      EINT_UnMask(EINT_B_KEY);
#endif
}

/*************************************************************************
* FUNCTION                                                            
*	kbd_Detect_Key
*
* DESCRIPTION                                                           
*	
*	This function is to detect one key status and store the detect result.
*
* PARAMETERS
*  pkey_info        		- pointer to one key current related information.
*  pkbd_detect_info 	- pointer to the structure which is to store the detect result(press keys and release keys).
*
*  RETURNS
*  None
*  
*
* Local AFFECTED
*
*************************************************************************/

void kbd_Detect_Key(keypad_key_info* pkey_info, keypad_detect_info_struct* pkbd_detect_info, keypad_status_struct* pkbd_status_Saved)
{
   
#if defined(__EXTEND_QWERTY_KEYPAD__) 
   keypad_Ext_QwertyKey_detect_info_struct* pkbd_Qwerty_info = (keypad_Ext_QwertyKey_detect_info_struct*)&(pkbd_detect_info->kbd_Ext_Qwerty_key_info);
#endif
   
   if(!pkey_info->bKeyStatus) //the key is pressed: keystatus==0
   {
      if (pkbd_detect_info->key_presscount == 0)
      {
         /* Record the 1st pressed key event. */
         pkbd_detect_info->kbd_press_key[0] = pkey_info->key_index;
         
#if defined(__EXTEND_QWERTY_KEYPAD__) 
         switch(pkey_info->Row_Type)
         {
         case Ext_GPO_ROW:
            pkbd_Qwerty_info->kbd_press_GPO_column[0] = pkey_info->key_column;
            break;
         case Ext_GND_ROW:
            pkbd_Qwerty_info->kbd_press_GND_column[0] = pkey_info->key_column;
            break;
         case Normal_ROW:
            break;
         default:
            break;    
         }
#endif
         pkbd_detect_info->key_presscount = 1;
         
      }
      else if (pkbd_detect_info->key_presscount == 1)
      {
         if (/*lint -e(644)*/pkbd_detect_info->kbd_press_key[0] != pkey_info->key_index)
         {
            /* Record the 2nd pressed key event. */
            if (kbd_key_detection_mode != (kal_uint8)kbd_1_key_det_mode)
            {
               pkbd_detect_info->kbd_press_key[1] = pkey_info->key_index;
               pkbd_detect_info->key_presscount = 2;
#if defined(__EXTEND_QWERTY_KEYPAD__) 
               switch(pkey_info->Row_Type)
               {
               case Ext_GPO_ROW:
                  pkbd_Qwerty_info->kbd_press_GPO_column[1] = pkey_info->key_column;
                  break;
               case Ext_GND_ROW:
                  pkbd_Qwerty_info->kbd_press_GND_column[1] = pkey_info->key_column;
                  break;
               case Normal_ROW:
                  break;
               default:
                  break;    
               }
#endif
            }
            else
            {
                #if defined(__EXTEND_QWERTY_KEYPAD__) 
               switch(pkey_info->Row_Type)
               {
               case Normal_ROW:
                    pkbd_detect_info->key_presscount = 2;
                  break;
               default:
                  break;    
               }
               #else
            pkbd_detect_info->key_presscount = 2;
                #endif
            }
            
           // pkbd_detect_info->key_presscount = 2;
         }
      }
      else if ((kbd_key_detection_mode != (kal_uint8)kbd_1_key_det_mode) && (pkbd_detect_info->key_presscount == 2))
      {
         /* More than 2 keys are pressed. */
         if ((pkbd_detect_info->kbd_press_key[0] != pkey_info->key_index)
            && (pkbd_detect_info->kbd_press_key[1] != pkey_info->key_index))
         {
#ifdef __THREE_KEY_DETECTION_SWITCHABLE__
            /* Record the 3rd pressed key event if in 3 keys detection mode. */
            if (kbd_key_detection_mode == kbd_3_keys_det_mode)
            {
               pkbd_detect_info->kbd_press_key[2] = pkey_info->key_index;
               pkbd_detect_info->key_presscount = 3;
#if defined(__EXTEND_QWERTY_KEYPAD__) 
               switch(pkey_info->Row_Type)
               {
               case Ext_GPO_ROW:
                  pkbd_Qwerty_info->kbd_press_GPO_column[2] = pkey_info->key_column;
                  break;
               case Ext_GND_ROW:
                  pkbd_Qwerty_info->kbd_press_GND_column[2] = pkey_info->key_column;
                  break;
               case Normal_ROW:
                  break;
               default:
                  break;    
               }
#endif
            }
         else
            {
                #if defined(__EXTEND_QWERTY_KEYPAD__) 
               switch(pkey_info->Row_Type)
               {
               case Normal_ROW:
                    pkbd_detect_info->key_presscount = 3;
                  break;
               default:
                  break;    
               }
               #else
            pkbd_detect_info->key_presscount = 3;
                #endif
         }

#else

#if defined(__EXTEND_QWERTY_KEYPAD__) 
       switch(pkey_info->Row_Type)
       {
       case Normal_ROW:
    pkbd_detect_info->key_presscount = 3;
          break;
       default:
          break;    
       }
#else
    pkbd_detect_info->key_presscount = 3;
#endif
   
#endif
          //  pkbd_detect_info->key_presscount = 3;
         }
        
      }
#ifdef __THREE_KEY_DETECTION_SWITCHABLE__
      else if ((kbd_key_detection_mode == kbd_3_keys_det_mode) && (pkbd_detect_info->key_presscount == 3))
      {
         /* More than 2 keys are pressed. */
         if ((pkbd_detect_info->kbd_press_key[0] !=pkey_info->key_index)
            && (pkbd_detect_info->kbd_press_key[1] != pkey_info->key_index)
            && (pkbd_detect_info->kbd_press_key[2] != pkey_info->key_index))
            {
            #if defined(__EXTEND_QWERTY_KEYPAD__) 
               switch(pkey_info->Row_Type)
               {
               case Normal_ROW:
            pkbd_detect_info->key_presscount = 4;
                  break;
               default:
                  break;    
               }
               #else
                    pkbd_detect_info->key_presscount = 4;
                #endif
              //  pkbd_detect_info->key_presscount = 4;
            }
            
          //  pkbd_detect_info->key_presscount = 4;
      }
#endif
#if defined(__EXTEND_QWERTY_KEYPAD__) 
      KBD_DBG(__LINE__, pkbd_detect_info->key_presscount, pkey_info->key_index,pkey_info->key_column);
#endif
   }//if(key_column_all_low_GND[j] && (key_presscount < KBD_KEY_DETECTION_CNT))
   else//  if(!key_info.bKeyStatus) //release
   {
#if defined(__EXTEND_QWERTY_KEYPAD__) 
      KBD_DBG(__LINE__, KBD_GetTimeStamp(), pkey_info->key_index,pkey_info->key_column);
#endif
      
      /* Only deal with those keys that we've recorded as pressed. */
      if ((KEY_INVALID != kbd_saved_pressed_key[0]) && (kbd_saved_pressed_key[0] == pkey_info->key_index))
      {
         /* Record the released key event. */
         if(pkbd_detect_info->key_releasecount < KBD_KEY_DETECTION_CNT)
         {
            pkbd_detect_info->kbd_release_key[pkbd_detect_info->key_releasecount] = kbd_saved_pressed_key[0];
         }
         pkbd_detect_info->key_releasecount++;
         
#ifdef __KBD_2STEP_KEY_SUPPORT__
         /* Note that 2-steps key is only enable when 2 key detection is disable. */
         if (kbd_is_2steps_key == KAL_TRUE)
         {
            KBD_GPTI_STOPITEM(KBD.kbd_2key_handle);
            kbd_is_2steps_key = KAL_FALSE;
         }
#endif /*__KBD_2STEP_KEY_SUPPORT__*/
         /* Stop the longpress/repeate timer for this key. */
         KBD_GPTI_STOPITEM(KBD.gpthandle[0]);
         kbd_saved_pressed_key[0] = KEY_INVALID;
         
#if defined(__EXTEND_QWERTY_KEYPAD__) 
         if( Ext_GPO_ROW == pkey_info->Row_Type)
            pkbd_status_Saved->key_column_all_low_GPO[pkey_info->key_column] = KAL_FALSE;
         else if(Ext_GND_ROW == pkey_info->Row_Type )
            pkbd_status_Saved->key_column_all_low_GND[pkey_info->key_column] = KAL_FALSE;
#endif
         
         kbd_press_event_count--;
      }
      /* Only if 2key or 3key detection is enable, 2nd key may have been recorded as pressed. */
      else if (kbd_key_detection_mode != (kal_uint8)kbd_1_key_det_mode)
      {
         if((KEY_INVALID != kbd_saved_pressed_key[1]) && (kbd_saved_pressed_key[1] == pkey_info->key_index))
         {
            /* Record the released key event. */
            if(pkbd_detect_info->key_releasecount < KBD_KEY_DETECTION_CNT)
            {
               pkbd_detect_info->kbd_release_key[pkbd_detect_info->key_releasecount] = kbd_saved_pressed_key[1];
            }
            pkbd_detect_info->key_releasecount++;
            
            /* Stop the longpress/repeate timer for this key. */
            KBD_GPTI_STOPITEM(KBD.gpthandle[1]);
            kbd_saved_pressed_key[1] = KEY_INVALID;
            
#if defined(__EXTEND_QWERTY_KEYPAD__) 
            if( Ext_GPO_ROW == pkey_info->Row_Type)
               pkbd_status_Saved->key_column_all_low_GPO[pkey_info->key_column] = KAL_FALSE;
            else if(Ext_GND_ROW == pkey_info->Row_Type )
               pkbd_status_Saved->key_column_all_low_GND[pkey_info->key_column] = KAL_FALSE;
#endif
            
            kbd_press_event_count--;
         }
#ifdef __THREE_KEY_DETECTION_SWITCHABLE__
         /* Only if 3key detection is enable, 2nd key may have been recorded as pressed. */
         else if (kbd_key_detection_mode == kbd_3_keys_det_mode)
         {
            if((KEY_INVALID != kbd_saved_pressed_key[2]) && (kbd_saved_pressed_key[2] == pkey_info->key_index))
            {
               /* Record the released key event. */
               if(pkbd_detect_info->key_releasecount < KBD_KEY_DETECTION_CNT)
               {
                  pkbd_detect_info->kbd_release_key[pkbd_detect_info->key_releasecount] = kbd_saved_pressed_key[2];
               }
               pkbd_detect_info->key_releasecount++;
               /* Stop the longpress/repeate timer for this key. */
               KBD_GPTI_STOPITEM(KBD.gpthandle[2]);
               kbd_saved_pressed_key[2] = KEY_INVALID;
               
#if defined(__EXTEND_QWERTY_KEYPAD__) 
               if( Ext_GPO_ROW == pkey_info->Row_Type)
                  pkbd_status_Saved->key_column_all_low_GPO[pkey_info->key_column] = KAL_FALSE;
               else if(Ext_GND_ROW == pkey_info->Row_Type )
                  pkbd_status_Saved->key_column_all_low_GND[pkey_info->key_column] = KAL_FALSE;
#endif
               kbd_press_event_count--;
            }
         }//else if (kbd_key_detection_mode == kbd_3_keys_det_mode)
#endif
      }//if ((KEY_INVALID != kbd_saved_pressed_key[0]) && (kbd_saved_pressed_key[0] == keypad_comm_def->keypad[key_index]))
#if defined(__EXTEND_QWERTY_KEYPAD__) 
      //     KBD_DBG(__LINE__, KBD_GetTimeStamp(), ust_get_current_time(), pkbd_detect_info->key_releasecount);
#endif
   }//if(!key_column_all_low_GPO[checkCol]) //release
}


/*************************************************************************
* FUNCTION                                                            
*   Kbd_Process_Detected_Keys
*
* DESCRIPTION                                                           
*   
*   This function is to detect one key status and store the detect result.
*
* PARAMETERS
*  pkbd_detect_info        - pointer to the current detection key information
*  pkbd_status_Saved     - pointer to the keypad key status last time saved
*  pkbd_map_reg_current -  pointer to the keypad map register currently
*
*  RETURNS
*  None
*  
*
* Local AFFECTED
*
*************************************************************************/
void Kbd_Process_Detected_Keys(keypad_detect_info_struct* pkbd_detect_info, keypad_status_struct* pkbd_status_Saved,  kbd_map_reg_struct* pkbd_map_reg_current)
{
   
   kal_uint8      roomleft;
   kal_uint8      key_index;
   kal_uint8      key_releasecount;
   kal_uint8      key_presscount;
   kal_uint8      key_total_count;
   //kal_bool       btmp;
   kbd_map_reg_struct*   pKeypad_map_reg_saved; // the saved keypad mapping register last time
   
#if defined(__EXTEND_QWERTY_KEYPAD__) 
   kal_uint8 checkcol,i;
   kal_bool Is_KeyMatched = KAL_FALSE;
   
   keypad_Ext_QwertyKey_detect_info_struct* pkbd_Qwerty_info = &pkbd_detect_info->kbd_Ext_Qwerty_key_info;
#endif
   
   pKeypad_map_reg_saved = &pkbd_status_Saved->kbd_map_reg;
   key_releasecount = pkbd_detect_info->key_releasecount;
   key_presscount  =   pkbd_detect_info->key_presscount;
   key_total_count = 0;
   
   /* Process the release key first. */
   if (key_releasecount > 0 && key_releasecount <= KBD_KEY_DETECTION_CNT)
   {
#ifdef __EXTRA_A_B_KEY_SUPPORT__
      if (kbd_key_detection_mode != kbd_1_key_det_mode)
      {
         EINT_Mask(EINT_A_KEY);
         EINT_Mask(EINT_B_KEY);
         IRQMask(IRQ_GPT_CODE);
      }
#endif
      kbdbuffer_get_roomleft(roomleft);
#ifdef KBD_DBGMODE
      ASSERT(roomleft>key_releasecount);
#else
      /* Check if buffer room is enough or not. Note there should be one buffer left for 
      2key detection enable/disable event. */
      if (roomleft <= key_releasecount)
      {
         kal_uint8   count;
         
#ifdef __EXTRA_A_B_KEY_SUPPORT__
         if (kbd_key_detection_mode != kbd_1_key_det_mode)
         {
            EINT_UnMask(EINT_A_KEY);
            EINT_UnMask(EINT_B_KEY);
            IRQUnmask(IRQ_GPT_CODE);
         }
#endif
         /* Not enough room. So we recover saved press key event. */
         for (key_index = 0, count = 0; key_index < KBD_KEY_DETECTION_CNT; key_index++)
         {
            if (kbd_saved_pressed_key[key_index] == KEY_INVALID)
            {
               kbd_saved_pressed_key[key_index] = /*lint -e(644)*/pkbd_detect_info->kbd_release_key[count];
               count++;
               if (count >= key_releasecount)
                  break;
            }
         }
         kbd_press_event_count += key_releasecount;
         return;
      }
#endif
#if defined(DRV_WDT_RESET_PKEY_RELEASE)
      if (TargetReset)
         DRV_RESET();
#endif   /*DRV_WDT_RESET_PKEY_RELEASE*/
      for (key_index = 0; key_index < key_releasecount; key_index++)
      {

#if defined(__EXTEND_QWERTY_KEYPAD__)
if(pkbd_status_Saved->extend_key_switch_pressed_num != 0)
{
    Is_KeyMatched = KAL_FALSE;
    for(i = 0; i < KBD_KEY_DETECTION_CNT; i++)
        {
            if(pkbd_status_Saved->kbd_switch_mode_extend_press_key[i] == pkbd_detect_info->kbd_release_key[key_index])
                {
                       Is_KeyMatched = KAL_TRUE;
                       pkbd_status_Saved->kbd_switch_mode_extend_press_key[i] = KEY_INVALID;
                        if(pkbd_status_Saved->extend_key_switch_pressed_num > 0)
                                    pkbd_status_Saved->extend_key_switch_pressed_num--;
                       break;
                }
             
        }
}
if(Is_KeyMatched == KAL_FALSE)
        {
         drv_trace2(TRACE_GROUP_8, KBD_PUT_DATA_TO_BUFFER, kbd_onekey_release, pkbd_detect_info->kbd_release_key[key_index]);
         KBD_PUSH_ONEKEY_TO_KBDBUFFER(kbd_onekey_release,pkbd_detect_info->kbd_release_key[key_index]);
      }
          
#else
KBD_PUSH_ONEKEY_TO_KBDBUFFER(kbd_onekey_release,pkbd_detect_info->kbd_release_key[key_index]);
#endif

 }

#if defined(__EXTEND_QWERTY_KEYPAD__)

if(pkbd_status_Saved->extend_key_switch_pressed_num == 0)
{
  pkbd_status_Saved->extend_switch_mode_key = KAL_FALSE;
}

#endif
#ifdef __EXTRA_A_B_KEY_SUPPORT__
      if (kbd_key_detection_mode != kbd_1_key_det_mode)
      {
        	EINT_UnMask(EINT_A_KEY);
        	EINT_UnMask(EINT_B_KEY);
        	IRQUnmask(IRQ_GPT_CODE);
      }
#endif
   }//if (key_releasecount > 0 && key_releasecount <= KBD_KEY_DETECTION_CNT)
   
   /* Update the keypad scan registers for release keys here. */
   pKeypad_map_reg_saved->kbdmap_reg |= pkbd_map_reg_current->kbdmap_reg;
#if defined(DRV_KBD_32KEYS_ABOVE) || defined(DRV_KBD_48KEYS_ABOVE) || defined(DRV_KBD_64KEYS_ABOVE)
   pKeypad_map_reg_saved->kbdmap_reg1 |= pkbd_map_reg_current->kbdmap_reg1;
#endif
#if defined(DRV_KBD_64KEYS_ABOVE)
   pKeypad_map_reg_saved->kbdmap_reg2 |= pkbd_map_reg_current->kbdmap_reg2;
#endif
   
   /* Calculate the total press keys count now. */
   key_total_count = kbd_press_event_count + key_presscount;

#if !defined(LOW_COST_SUPPORT)
drv_trace4(TRACE_GROUP_8, KBD_KEY_DETECT_RESULT, key_total_count, kbd_press_event_count,key_releasecount, 0 );
#endif

#if defined(__EXTEND_QWERTY_KEYPAD__)
   if(key_total_count > 0)
   {
      KBD_GPTI_STARTITEM(KBD.kbd_extend_gpthandle,
         KBD.polling_timeout,
         KBDPollingHandler,
         NULL);
      kal_prompt_trace(MOD_DRVKBD, "total count=%x", key_total_count);
   }
   else
   {
      
      //Only when all key released, unmask irq to wait next key event.
    //  IRQUnmask(IRQ_KPAD_CODE);
    KBD_UNMASKIRQ;
      kal_prompt_trace(MOD_DRVKBD, "IRQUnmask(IRQ_KPAD_CODE)");
   }
#endif//#if defined(__EXTEND_QWERTY_KEYPAD__)
   
   /* Check if the total press keys count exceeds the limitation. */
   if (((kbd_key_detection_mode == (kal_uint8)kbd_1_key_det_mode) && (key_total_count > 1))
      || ((kbd_key_detection_mode == (kal_uint8)kbd_2_keys_det_mode) && (key_total_count > 2))
      || ((kbd_key_detection_mode == (kal_uint8)kbd_3_keys_det_mode) && (key_total_count > 3)))
   {
      /* Exceed the press key count so we don't process the newly pressed keys. */
      if (key_releasecount == 0)
         return;
   }
   else
   {
      if (key_presscount > 0 && key_presscount <= KBD_KEY_DETECTION_CNT)
      {
         kal_uint8 count;
         
#ifdef __EXTRA_A_B_KEY_SUPPORT__
         if (kbd_key_detection_mode != kbd_1_key_det_mode)
         {
            EINT_Mask(EINT_A_KEY);
            EINT_Mask(EINT_B_KEY);
            IRQMask(IRQ_GPT_CODE);
         }
#endif
         kbdbuffer_get_roomleft(roomleft);
#ifdef KBD_DBGMODE
         ASSERT(roomleft >= (key_presscount*2+kbd_press_event_count+kbd_ext_press_event_count+1));
#endif
         /* Note the left buffer room should more than the sum of
    		   1. kbd_press_event_count: for release key events later. 
            2. newly press keys x 2 . (1 for press, 1 for release later).
            3. 1: multi key detection enable/disable event. 
    		   4. External A/B pressed keys: for release key events later */
         if (roomleft < (key_presscount*2+kbd_press_event_count+kbd_ext_press_event_count+1))
         {
#ifdef __EXTRA_A_B_KEY_SUPPORT__
            if (kbd_key_detection_mode != kbd_1_key_det_mode)
            {
               EINT_UnMask(EINT_A_KEY);
               EINT_UnMask(EINT_B_KEY);
               IRQUnmask(IRQ_GPT_CODE);
            }
#endif
         }
         else
         {
#ifdef KBD_DBGMODE
            //ASSERT(kbd_saved_pressed_key[0] == KEY_INVALID);
            //ASSERT(kbd_saved_pressed_key[1] == KEY_INVALID);
#endif   /*KBD_DBGMODE*/
            /* Store the press key event. */
            for (key_index = 0, count = 0; key_index < KBD_KEY_DETECTION_CNT; key_index++)
            {
               if (kbd_saved_pressed_key[key_index] == KEY_INVALID)
               {
#if defined(__EXTEND_QWERTY_KEYPAD__)
                  if(pkbd_Qwerty_info->kbd_press_GPO_column[count] != 0xFF) //it's a GPO press
                  {
                     checkcol = pkbd_Qwerty_info->kbd_press_GPO_column[count];
                     pkbd_status_Saved->key_column_all_low_GPO[checkcol] = KAL_TRUE;
                  }
                  else if(pkbd_Qwerty_info->kbd_press_GND_column[count] != 0xFF) //it's a GND press
                  {
                     checkcol = pkbd_Qwerty_info->kbd_press_GND_column[count];
                     pkbd_status_Saved->key_column_all_low_GND[checkcol] = KAL_TRUE;
                  }
          Is_KeyMatched = KAL_FALSE;
                     if((pkbd_status_Saved->extend_key_switch_pressed_num != 0)||(pkbd_status_Saved->extend_switch_mode_key == KAL_TRUE))
                    {
                        for(i = 0 ;i < pkbd_status_Saved->extend_key_switch_pressed_num; i++)
                            {
                                if(pkbd_status_Saved->kbd_switch_mode_extend_press_key[i] ==pkbd_detect_info->kbd_press_key[count])
                                    {
                                         Is_KeyMatched = KAL_TRUE;
                                    }
                            }
                    }
#endif //#if defined(__EXTEND_QWERTY_KEYPAD__)
                  
                  kbd_saved_pressed_key[key_index] = pkbd_detect_info->kbd_press_key[count];
#if defined(__EXTEND_QWERTY_KEYPAD__)
                 if(Is_KeyMatched == KAL_FALSE)
  #endif
                    {
                  drv_trace2(TRACE_GROUP_8, KBD_PUT_DATA_TO_BUFFER, kbd_onekey_press, pkbd_detect_info->kbd_press_key[count]);

                  KBD_PUSH_ONEKEY_TO_KBDBUFFER(kbd_onekey_press,pkbd_detect_info->kbd_press_key[count]);
                  /* Start the longpress timer for this key. */
#ifdef __KBD_2STEP_KEY_SUPPORT__
                  /* Check if it's 2-steps key. Note that 2-steps key is disable in multi-keys detection mode. */
                  ASSERT((keypadCustomFunc->keypad_is_fullpress) != NULL);
                  if((kbd_key_detection_mode == (kal_uint8)kbd_1_key_det_mode) 
                     && keypadCustomFunc->keypad_is_fullpress(pkbd_detect_info->kbd_press_key[count]))
                  {
                     kbd_is_2steps_key = KAL_TRUE;
                     //btmp = KBD_GPTI_STARTITEM(KBD.kbd_2key_handle,
                     KBD_GPTI_STARTITEM(KBD.kbd_2key_handle,
                        10,
                        KBD2KeyHandler,
                        NULL);
                  }
                  else
                  {
#endif /*__KBD_2STEP_KEY_SUPPORT__*/
                     /* Start the longpress timer for this. */
                     //btmp = KBD_GPTI_STARTITEM(KBD.gpthandle[key_index],
                     KBD_GPTI_STARTITEM(KBD.gpthandle[key_index],
                        KBD.longpress_timeout,
                        KBDTimeOutHandler,
                        (void *)key_index);
#ifdef __KBD_2STEP_KEY_SUPPORT__
                  }
#endif /*__KBD_2STEP_KEY_SUPPORT__*/
                  }

                  count++;
                  if (count >= key_presscount)
                     break;
               }
            }
            kbd_press_event_count+=key_presscount;
            
#ifdef __EXTRA_A_B_KEY_SUPPORT__
            if (kbd_key_detection_mode != kbd_1_key_det_mode)
            {
               EINT_UnMask(EINT_A_KEY);
               EINT_UnMask(EINT_B_KEY);
               IRQUnmask(IRQ_GPT_CODE);
            }
#endif
            
            /* Update the keypad scan registers for press keys here. */
            pKeypad_map_reg_saved->kbdmap_reg &= pkbd_map_reg_current->kbdmap_reg;
#if defined(DRV_KBD_32KEYS_ABOVE) || defined(DRV_KBD_48KEYS_ABOVE) || defined(DRV_KBD_64KEYS_ABOVE)
            pKeypad_map_reg_saved->kbdmap_reg1 &= pkbd_map_reg_current->kbdmap_reg1;
#endif   /*DRV_KBD_32KEYS_ABOVE*/
#if defined(DRV_KBD_64KEYS_ABOVE)
            pKeypad_map_reg_saved->kbdmap_reg2 &= pkbd_map_reg_current->kbdmap_reg2;
#endif   /*DRV_KBD_32KEYS_ABOVE*/
         }// else //if (roomleft < (key_presscount*2+kbd_press_event_count+kbd_ext_press_event_count+1))
            }// else //if (key_presscount > 0 && key_presscount <= KBD_KEY_DETECTION_CNT)
      }//if (((kbd_key_detection_mode == (kal_uint8)kbd_1_key_det_mode) && (key_total_count > 1))
#if defined(TOUCH_PAD_SUPPORT)
      kbd_owner_stat = (kbd_press_event_count > 0) ? KBD_OWNER_KEYPAD: KBD_OWNER_NONE;
#endif /*TOUCH_PAD_SUPPORT*/
      
      kbd_SendMsg_To_UEM(); 
 }
 
#if defined(__EXTEND_QWERTY_KEYPAD__)
 
static void kbd_get_key_bitmap(kal_uint8* pArray, kal_uint8 ArrayCnt)
{
	  kal_uint32 i, j, reg,bit;

  for(i=0; i<kbd_allkeys; )  //i already ++ in inner loop 
    { 
       // base on key register offset = 4 sequentially
       reg = DRV_KBD_Reg(KP_LOW_KEY + ((i>>4) <<2) ); //  i/16 --> n-th register,  *4 --> register offset.
       for(j=0; j<16 && i<kbd_allkeys; j++, i++) 
       {
          bit = (reg >> (i&0xF) ) & 0x1;  // select (i&0xF)-th bit in this register
          if(pArray[i] != bit) 
          { 
             pArray[i] = bit; // put this bit into array
          } 
       } 
    } 
    
}
 
 /*************************************************************************
 * FUNCTION                                                            
 *   kbd_Detect_Ext_QwertyKey
 *
 * DESCRIPTION                                                           
 *   
 *   this function is to detect Extend Qwerty keys.
 *
 * PARAMETERS
 *  pkbd_Status_Saved                         - pointer to the  keys status last time
 *  pkbd_detect_info                            - keypad detection key information filled in it                            
 *  pkbd_map_reg_sync                        - the map register 
 *
 *  RETURNS
 *  None
 *  
 *
 * Local AFFECTED
 *
 *************************************************************************/
 
 static void kbd_Detect_Ext_QwertyKey(keypad_status_struct* pkbd_Status_Saved, 
    keypad_detect_info_struct* pkbd_detect_info, kbd_map_reg_struct* pkbd_map_reg_sync)
 {
    kal_uint32     i,j;
    kal_uint32     checkRow, checkCol, keytmp;
    kal_uint8      key_bit_map[kbd_allkeys+KBD_COLUMN*2];
    kal_bool       bPressed = KAL_FALSE;
    keypad_key_info key_info;
    kal_bool       btmp;
    
    keypad_Ext_QwertyKey_detect_info_struct* pQwerty_detect_info = &pkbd_detect_info->kbd_Ext_Qwerty_key_info;
    
    KBD_DBG(__LINE__, KBD_GetTimeStamp(), ust_get_current_time(),0);
    
    kbd_get_keypad_status_reg(pkbd_map_reg_sync);
    
    for(checkCol=0; checkCol<KBD_COLUMN; checkCol++)
    { //restore to saved status, it need current status for reference
       pQwerty_detect_info->key_column_all_low_GND[checkCol] = pkbd_Status_Saved->key_column_all_low_GND[checkCol]; //clear temp
       pQwerty_detect_info->key_column_all_low_GPO[checkCol] = pkbd_Status_Saved->key_column_all_low_GPO[checkCol]; //clear temp
    }
    
    for (i = 0; i < kbd_allkeys+KBD_COLUMN*2; i++)
    {
    	key_bit_map[i] = 1;
    }
    for (i = 0; i < KBD_KEY_DETECTION_CNT; i++) //store which column pressed/released
    {
       pQwerty_detect_info->kbd_press_GPO_column[i] = 0xFF;
       pQwerty_detect_info->kbd_press_GND_column[i] = 0xFF;
       pkbd_detect_info->kbd_press_key[i] = DEVICE_KEY_NONE;
       pkbd_detect_info->kbd_release_key[i] = DEVICE_KEY_NONE;
    }
    
  kbd_get_key_bitmap(&key_bit_map[0],  kbd_allkeys);
    
    if(gpio_kbd_extend_QWERTY_pin != 0xFF)
    {
       bPressed = KAL_FALSE;
       for(checkCol=0; checkCol<(KBD_COLUMN-1); checkCol++)
       {
          // check which column is all low
          btmp = KAL_TRUE;
          keytmp = kbd_allkeys+KBD_COLUMN+checkCol; //1:power key column, from extra GND column.
          for(checkRow=0; checkRow<KBD_ROW; checkRow++)
          {
             btmp = (kal_bool)(btmp & ((key_bit_map[checkRow*KBD_COLUMN + checkCol] == 1) ? KAL_FALSE : KAL_TRUE)); //if one key not press, we know this column not all low.
          }
            if ( btmp == KAL_TRUE )  
                    bPressed = KAL_TRUE;   // when GPO detection, one column is pressed, then the flag should be set, during GND detection, according to the flag, to disable GPO.
          
          if(pkbd_Status_Saved->key_column_all_low_GPO[checkCol] != btmp) ////if status does not equal to last status.
          {
             
             KBD_DBG(__LINE__, KBD_GetTimeStamp(), btmp, checkCol);
             
             pQwerty_detect_info->key_column_all_low_GPO[checkCol] = btmp;  // save the current column status
       //      bPressed = btmp;
             
             key_info.bKeyStatus = ((btmp == KAL_TRUE)? KAL_FALSE : KAL_TRUE); // "0" indicates pressed; "1"indicates release
             key_info.key_index = keypad_comm_def->keypad[keytmp];
             key_info.key_column = checkCol;
             key_info.Row_Type = Ext_GPO_ROW;
             
             kbd_Detect_Key(&key_info, pkbd_detect_info, pkbd_Status_Saved);       // Fill the key detect result 
             
             kbd_get_keypad_status_reg(pkbd_map_reg_sync);   
             
          }//if(key_column_all_low_GND[j] != btmp)
       }//for(checkCol=0; checkCol<KBD_COLUMN; checkCol++)
       
       if(bPressed) //check GPO or GND pressed.
       {
          KBD_GPIO_WriteIO(KAL_TRUE, keypad_comm_def->kbd_extend_row_GPO); //disable GPO for check GND
          KBD_DBG(__LINE__, KBD_GetTimeStamp(), ust_get_current_time(),0);
          kal_sleep_task(DRV_KBD_Reg(KP_DEBOUNCE)/136 + 5); //4.615/(1/32k) ~= 136 //5 --> Need additional delay for keypad HW debounce
       }
    }//if(keypad_comm_def->kbd_extend_row_GPO != 0xFF)
    
    KBD_DBG(__LINE__, pkbd_detect_info->key_total_count, pkbd_detect_info->key_presscount,pkbd_detect_info->key_releasecount);
    
  kbd_get_key_bitmap(&key_bit_map[0],  kbd_allkeys);
    
    // check which column is all low
    for(checkCol=0; checkCol<(KBD_COLUMN-1); checkCol++)
    {
       btmp = KAL_TRUE;
       keytmp = kbd_allkeys+checkCol;
       for(checkRow=0; checkRow<KBD_ROW; checkRow++)
       {
          btmp = (kal_bool)(btmp & ((key_bit_map[checkRow*KBD_COLUMN + checkCol] == 1) ? KAL_FALSE : KAL_TRUE)); //if one key not press, we know this column not all low.
       }
             if((btmp == KAL_TRUE) && (KAL_TRUE == pQwerty_detect_info->key_column_all_low_GPO[checkCol]))
              {     
                    //GND pressed, replace GPO pressed record
                      pQwerty_detect_info->key_column_all_low_GPO[checkCol] = KAL_FALSE;
 
                     for(i=0; i<KBD_KEY_DETECTION_CNT; i++)
                    {
                       //also check column number is correct or not. otherwise if GPO has some keys define the same value, it causes error.
                       if( (pkbd_detect_info->kbd_press_key[i] == keypad_comm_def->keypad[keytmp+KBD_COLUMN]) 
                         &&(checkCol == pQwerty_detect_info->kbd_press_GPO_column[i])) //check GPO, 
                       { 
                           //restore false alarm GPO
                           pkbd_detect_info->key_presscount--; //because maybe GND already pressed last time.

                            if(i == (KBD_KEY_DETECTION_CNT-1))  //yali:  indicate the array last one
                                {
                                    pkbd_detect_info->kbd_press_key[i] = DEVICE_KEY_NONE;
                                    pQwerty_detect_info->kbd_press_GPO_column[i] = 0xFF;
                                }
                                else
                                {
                                   for(j=i;j<(KBD_KEY_DETECTION_CNT-1);j++)
                                      {//shift the press key
                                         pkbd_detect_info->kbd_press_key[j] = pkbd_detect_info->kbd_press_key[j+1];
                                         pQwerty_detect_info->kbd_press_GPO_column[j] = pQwerty_detect_info->kbd_press_GPO_column[j+1];
                                         pkbd_detect_info->kbd_press_key[j+1] = DEVICE_KEY_NONE;
                                         pQwerty_detect_info->kbd_press_GPO_column[j+1] = 0xFF; // yali
                                      }
                                }
                       
                          break;

                          
                       }
                    }//for(i=0; i<KBD_KEY_DETECTION_CNT; i++)
                    
               kbd_get_keypad_status_reg(pkbd_map_reg_sync);
                      
              }
        }

    
    // check which column is all low
    for(checkCol=0; checkCol<(KBD_COLUMN-1); checkCol++)
    {
       btmp = KAL_TRUE;
       keytmp = kbd_allkeys+checkCol;
       for(checkRow=0; checkRow<KBD_ROW; checkRow++)
       {
          btmp = (kal_bool)(btmp & ((key_bit_map[checkRow*KBD_COLUMN + checkCol] == 1) ? KAL_FALSE : KAL_TRUE)); //if one key not press, we know this column not all low.
       }
       
       if(pkbd_Status_Saved->key_column_all_low_GND[checkCol] != btmp) ////if status does not equal to last time.
       {
          pQwerty_detect_info->key_column_all_low_GND[checkCol] = btmp;
          
          key_info.bKeyStatus = ((btmp == KAL_TRUE)? KAL_FALSE : KAL_TRUE); // "0" indicates pressed; "1"indicates release
          key_info.key_index = keypad_comm_def->keypad[keytmp];
          key_info.key_column = checkCol;
          key_info.Row_Type = Ext_GND_ROW;
          kbd_Detect_Key(&key_info, pkbd_detect_info, pkbd_Status_Saved);
          
          kbd_get_keypad_status_reg(pkbd_map_reg_sync);
          
       }//if(key_column_all_low_GND[j] != btmp)
       
    }//for(j=0; j<KBD_COLUMN; j++)
       if(bPressed)
         {
    KBD_DBG(__LINE__, KBD_GetTimeStamp(), ust_get_current_time(), pkbd_detect_info->key_releasecount);  
    KBD_GPIO_WriteIO(KAL_FALSE, keypad_comm_def->kbd_extend_row_GPO); //enable GPO for check GPO again.
    KBD_DBG(__LINE__,pkbd_detect_info->key_total_count,pkbd_detect_info->key_presscount,pkbd_detect_info->key_releasecount);
    kal_sleep_task(DRV_KBD_Reg(KP_DEBOUNCE)/136 + 5); //4.615/(1/32k) ~= 136  //5 --> Need additional delay for keypad HW debounce
        }
    
    // double check the GPO
    // Because when detect GPO pressed that actually has two possibility.
    // 1. GPO pressed
    // 2. GND pressed when process GPO detection then GND released when process GND detection --> never press GPO
    // However this double check still can not cover all scenario
    // keypad debounce need 2x ms, user maybe press GPO again when double check.
    if( (keypad_comm_def->kbd_extend_row_GPO != 0xFF) && bPressed )
    {
      
       kbd_get_key_bitmap(&key_bit_map[0],  kbd_allkeys);
       for(checkCol=0; checkCol<(KBD_COLUMN-1); checkCol++)
       {
          if(pQwerty_detect_info->key_column_all_low_GPO[checkCol] == KAL_FALSE)
             continue;
          // check which column is all low
          btmp = KAL_TRUE;
          keytmp = kbd_allkeys+KBD_COLUMN+checkCol; //1:power key column, from extra GND column.
          for(checkRow=0; checkRow<KBD_ROW; checkRow++)
          {
             btmp = (kal_bool)(btmp & ((key_bit_map[checkRow*KBD_COLUMN + checkCol] == 1) ? KAL_FALSE : KAL_TRUE)); //if one key not press, we know this column not all low.
          }
          KBD_DBG(__LINE__, checkCol, pkbd_Status_Saved->key_column_all_low_GPO[checkCol], btmp);
          
          if ( btmp == KAL_FALSE )// pressed in first check GPO. but released in 2nd check GPO
          {
             pQwerty_detect_info->key_column_all_low_GPO[checkCol] = KAL_FALSE;
             for(i=0; i<KBD_KEY_DETECTION_CNT; i++)
             {
                //also check column number is correct or not. otherwise if GPO has
                if((pkbd_detect_info->kbd_press_key[i] == keypad_comm_def->keypad[keytmp])
                   && (checkCol == pQwerty_detect_info->kbd_press_GPO_column[i])) //check GPO
                { //restore false alarm GPO
                   pkbd_detect_info->key_presscount--; //because maybe GND already pressed last time.
                   
                    if(i == (KBD_KEY_DETECTION_CNT-1)) //yali: the for loop is dothing for last one
                    {
                        pkbd_detect_info->kbd_press_key[i] = DEVICE_KEY_NONE;
                        pQwerty_detect_info->kbd_press_GPO_column[i] = 0xFF;
                        pQwerty_detect_info->kbd_press_GND_column[i] = 0xFF;
                    }
                     else
                    {
                   for(j=i;j<KBD_KEY_DETECTION_CNT-1;j++)
                   {//shift the press key
                      pkbd_detect_info->kbd_press_key[j] = pkbd_detect_info->kbd_press_key[j+1];
                      pQwerty_detect_info->kbd_press_GPO_column[j] = pQwerty_detect_info->kbd_press_GPO_column[j+1];
                             pQwerty_detect_info->kbd_press_GND_column[j] =  pQwerty_detect_info->kbd_press_GND_column[j+1];  // yali: it is possible here is a GND key 
                             pQwerty_detect_info->kbd_press_GPO_column[j+1] = 0xFF; // yali
                             pQwerty_detect_info->kbd_press_GND_column[j+1] = 0xFF;   
                            pkbd_detect_info->kbd_press_key[j+1] = DEVICE_KEY_NONE;
                         }
                   }
                   break;
                }
             }//for(i=0; i<KBD_KEY_DETECTION_CNT; i++)
             
             KBD_DBG(__LINE__,pkbd_detect_info->key_total_count,keypad_comm_def->keypad[keytmp],checkCol);
             
             kbd_get_keypad_status_reg(pkbd_map_reg_sync);
             
          }
       }//for(checkCol=0; checkCol<KBD_COLUMN; checkCol++)
    }//if(keypad_comm_def->kbd_extend_row_GPO != 0xFF)
}
#endif


/*************************************************************************
* FUNCTION                                                            
*   kbd_KeyEventHandler
*
* DESCRIPTION                                                           
*   
*   This function is to handler the key event
*
* PARAMETERS
*  pkbd_status_Saved        - pointer to the key inforamtion last time 
*
*  RETURNS
*  None
*  
*
* Local AFFECTED
*
*************************************************************************/

static void kbd_KeyEventHandler(keypad_status_struct* pkbd_status_Saved)
{
   kal_uint8  key_index, loop_cnt;
   keypad_detect_info_struct keypad_detect_info;
   keypad_key_info key_info;
   kal_uint32 reg_save, reg_tmp;
   kbd_map_reg_struct kbd_map_reg;
   kbd_map_reg_struct* pkbd_map_reg_Saved;
   
#if defined(__EXTEND_QWERTY_KEYPAD__)
   kal_uint8       i, checkCol,j,switch_key_num;
   kbd_map_reg_struct kbd_map_reg_sync;
   kal_uint32     key_array_count=0;
   kal_bool Is_Matched = KAL_FALSE;
   static kal_bool Key_IsFirstPolling = KAL_FALSE;
#endif
   
   // Init the key detection result
   keypad_detect_info.key_presscount = 0;
   keypad_detect_info.key_releasecount = 0;
   keypad_detect_info.key_total_count = 0;
   reg_save = 0xFFFFFFFF;
   reg_tmp = 0xFFFFFFFF;
   
   
   pkbd_map_reg_Saved = (kbd_map_reg_struct*)&pkbd_status_Saved->kbd_map_reg;
 
   // Extention qwerty key detection
#if defined(__EXTEND_QWERTY_KEYPAD__)  
   kbd_Detect_Ext_QwertyKey(pkbd_status_Saved, &keypad_detect_info, &kbd_map_reg_sync);
// if after switch mode, the next polling result is key up;then reset the switch mode key information
    switch_key_num = pkbd_status_Saved->extend_key_switch_pressed_num;
    if(switch_key_num == 0)
        Key_IsFirstPolling = KAL_FALSE;
    
    if((switch_key_num != 0)&&(Key_IsFirstPolling == KAL_FALSE))
        {
           
            kal_prompt_trace(MOD_DRVKBD,"qwerty key has pressed:switch_key_num = %d, key_presscount = %d, key_relase = %d", switch_key_num,keypad_detect_info.key_presscount, keypad_detect_info.key_releasecount);
            for(j = 0; j <switch_key_num;j++)
                {
                    Is_Matched = KAL_FALSE;
                    for(i = 0; i < keypad_detect_info.key_presscount; i++)
                        {
                             if(keypad_detect_info.kbd_press_key[i] == pkbd_status_Saved->kbd_switch_mode_extend_press_key[j])
                                Is_Matched = KAL_TRUE;
                        }
                    
                        if((Is_Matched == KAL_FALSE)&&(pkbd_status_Saved->kbd_switch_mode_extend_press_key[j] != KEY_INVALID)) // the switch mode pressed key has release
                            {
                                pkbd_status_Saved->kbd_switch_mode_extend_press_key[j] = KEY_INVALID;
                                if(pkbd_status_Saved->extend_key_switch_pressed_num > 0)
                                       pkbd_status_Saved->extend_key_switch_pressed_num--;
                            }
                }

           Key_IsFirstPolling = KAL_TRUE;
        }
#endif
   
   //Read the keypad map register from HW.
   kbd_get_keypad_status_reg(&kbd_map_reg);
   
#if !defined(LOW_COST_SUPPORT)
    #if defined(DRV_KBD_64KEYS_ABOVE)
         drv_trace4(TRACE_GROUP_8, KBD_KEY_STATUS, kbd_map_reg.kbdmap_reg, kbd_map_reg.kbdmap_reg1,kbd_map_reg.kbdmap_reg2, 0);
    #elif defined(DRV_KBD_48KEYS_ABOVE)
        drv_trace4(TRACE_GROUP_8, KBD_KEY_STATUS, kbd_map_reg.kbdmap_reg, kbd_map_reg.kbdmap_reg1,0, 0);
    #elif defined(DRV_KBD_32KEYS_ABOVE)
          drv_trace4(TRACE_GROUP_8, KBD_KEY_STATUS, kbd_map_reg.kbdmap_reg, 0,0, 0);
    #elif defined(DRV_KBD_32KEYS_EQ_BELOW)
        drv_trace4(TRACE_GROUP_8, KBD_KEY_STATUS, kbd_map_reg.kbdmap_reg, 0,0, 0);
    #endif
#endif // #if !defined(LOW_COST_SUPPORT)

   
#if defined(TOUCH_PAD_SUPPORT)
#if defined(TOUCH_PAD_USE_KEY_COLUMN)
#if defined(TOUCHPAD_DEBUG)	
   kal_prompt_trace(MOD_DRVKBD, "kbd_map_temp_reg=%x",kbd_map_reg.kbdmap_reg);
#if defined(DRV_KBD_32KEYS_ABOVE) || defined(DRV_KBD_48KEYS_ABOVE) || defined(DRV_KBD_64KEYS_ABOVE)
   kal_prompt_trace(MOD_DRVKBD, "kbd_map_temp_reg=%x,kbd_map_temp_reg1=%x",kbd_map_reg.kbdmap_reg, kbd_map_reg.kbdmap_reg1);
#endif
#endif
   // if some keypad key is pressed, the corresponding bit of key 
   // status register is changed from 1 to 0
   if (((kbd_map_reg.kbdmap_reg >> TOUCH_PAD_KEY_COLUMN_NUM) & 0x00000001) == 0) 
   {
      // reset each key status bit corresponding to the keypad column to 1 to 
      // prevent keypad status to be processed in the following general key press
      if (kbd_owner_stat == KBD_OWNER_KEYPAD)
      {
         kbd_map_reg.kbdmap_reg |= KEYPAD_SCANNER_REG;
#if defined(DRV_KBD_32KEYS_ABOVE) || defined(DRV_KBD_48KEYS_ABOVE) || defined(DRV_KBD_64KEYS_ABOVE)
         kbd_map_reg.kbdmap_reg1|= KEYPAD_SCANNER_REG1;
#if defined(DRV_KBD_64KEYS_ABOVE)
         kbd_map_reg.kbdmap_reg2|= KEYPAD_SCANNER_REG2;
#endif
#endif
      }
      TOUCHPAD_UART_PutBytes(TOUCHPAD_UART_PORT, 0x50);
      if (kbd_owner_stat != KBD_OWNER_KEYPAD)
      {
         if (kbd_owner_stat == KBD_OWNER_NONE)
            kbd_owner_stat = KBD_OWNER_TOUCHPAD;
         return;
      }
   }
   else if (kbd_owner_stat == KBD_OWNER_TOUCHPAD)
      return;
   
#if defined(TOUCHPAD_DEBUG)
#if defined(DRV_KBD_32KEYS_ABOVE) || defined(DRV_KBD_48KEYS_ABOVE) || defined(DRV_KBD_64KEYS_ABOVE)
   kal_prompt_trace(MOD_DRVKBD, "after change: kbd_map_temp_reg=%x,kbd_map_temp_reg1=%x", kbd_map_reg.kbdmap_reg, kbd_map_reg.kbdmap_reg1);
#endif
#endif
#endif  /*  TOUCH_PAD_USE_KEY_COLUMN    */
#endif  /*  TOUCH_PAD_SUPPORT   */
   
   
#if defined(__EXTEND_QWERTY_KEYPAD__)//all register may the same with last record, but GPO pressed.
   
#if defined(DRV_KBD_32KEYS_ABOVE) || defined(DRV_KBD_48KEYS_ABOVE) || defined(DRV_KBD_64KEYS_ABOVE)
   kbd_map_reg.kbdmap_reg = kbd_map_reg_sync.kbdmap_reg;
#if defined(DRV_KBD_32KEYS_ABOVE)
   kbd_map_reg.kbdmap_reg1 = kbd_map_reg_sync.kbdmap_reg1;
#elif defined(DRV_KBD_48KEYS_ABOVE)
   kbd_map_reg.kbdmap_reg1 = kbd_map_reg_sync.kbdmap_reg1;
#elif defined(DRV_KBD_64KEYS_ABOVE)
   kbd_map_reg.kbdmap_reg1 = kbd_map_reg_sync.kbdmap_reg1;
   kbd_map_reg.kbdmap_reg2 = kbd_map_reg_sync.kbdmap_reg2;
#endif//#if defined(DRV_KBD_32KEYS_ABOVE)
#endif//#if defined(DRV_KBD_32KEYS_ABOVE) || defined(DRV_KBD_48KEYS_ABOVE) || defined(DRV_KBD_64KEYS_ABOVE)
   
   //release all normal key, if the column is pressed.
   // restore normal key as non pressed
   for(checkCol=0; checkCol<(KBD_COLUMN-1); checkCol++)
   {
      if(keypad_detect_info.kbd_Ext_Qwerty_key_info.key_column_all_low_GND[checkCol] ||keypad_detect_info.kbd_Ext_Qwerty_key_info.key_column_all_low_GPO[checkCol])
      {
         for(i=0; i<KBD_ROW+2; i++) //restore additional GND and GPO row
         {
            key_array_count = KBD_COLUMN*i+checkCol;
            if( key_array_count < 32)
            {
               KBD_DBG(__LINE__, kbd_map_reg.kbdmap_reg , key_array_count, checkCol);
               kbd_map_reg.kbdmap_reg  |= 1<<key_array_count;
               KBD_DBG(__LINE__, kbd_map_reg.kbdmap_reg , key_array_count, checkCol);
            }
#if defined(DRV_KBD_32KEYS_ABOVE) || defined(DRV_KBD_48KEYS_ABOVE) || defined(DRV_KBD_64KEYS_ABOVE)
            else if(key_array_count < 64)
            {
               KBD_DBG(__LINE__, kbd_map_reg.kbdmap_reg1 , key_array_count, checkCol);
               kbd_map_reg.kbdmap_reg1|= 1<<(key_array_count-32);
               KBD_DBG(__LINE__, kbd_map_reg.kbdmap_reg1, key_array_count, checkCol);
            }
#endif//#if defined(DRV_KBD_32KEYS_ABOVE) || defined(DRV_KBD_48KEYS_ABOVE) || defined(DRV_KBD_64KEYS_ABOVE)
#if defined(DRV_KBD_64KEYS_ABOVE)
            else
            {
               KBD_DBG(__LINE__, kbd_map_reg.kbdmap_reg2, key_array_count, checkCol);
               kbd_map_reg.kbdmap_reg2 |= 1<<(key_array_count-64);
               KBD_DBG(__LINE__, kbd_map_reg.kbdmap_reg2, key_array_count, checkCol);
            }
#endif//#if defined(DRV_KBD_64KEYS_ABOVE)
         }//for(i=0; i<KBD_ROW+2; i++) //restore additional GND and GPO row
      }//if(key_column_all_low_GND[checkCol] || key_column_all_low_GPO[checkCol])
   }//for(checkCol=0; checkCol<KBD_COLUMN; checkCol++)
   
#else  // #if defined(__EXTEND_QWERTY_KEYPAD__)
   
   // compare the current keypad map register with last time saved, if not equal with last time, then detect the keypad
#if defined(DRV_KBD_32KEYS_EQ_BELOW) || defined(FPGA)
   if (pkbd_map_reg_Saved->kbdmap_reg != kbd_map_reg.kbdmap_reg)
#elif defined(DRV_KBD_32KEYS_ABOVE) || defined(DRV_KBD_48KEYS_ABOVE)
      if ((pkbd_map_reg_Saved->kbdmap_reg != kbd_map_reg.kbdmap_reg) || (pkbd_map_reg_Saved->kbdmap_reg1 != kbd_map_reg.kbdmap_reg1))
#elif defined(DRV_KBD_64KEYS_ABOVE)
         if ((pkbd_map_reg_Saved->kbdmap_reg !=  kbd_map_reg.kbdmap_reg) || (pkbd_map_reg_Saved->kbdmap_reg1 != kbd_map_reg.kbdmap_reg1 ) || (pkbd_map_reg_Saved->kbdmap_reg2 != kbd_map_reg.kbdmap_reg2))
#endif
            
#endif  //#if defined(__EXTEND_QWERTY_KEYPAD__)
         {
            for(key_index = 0; key_index < kbd_allkeys; ) // compare all the key status with last time recorded
            {
               if(key_index < 32) // the first internal loop for the first 32-bit register
               {
                  reg_save = pkbd_map_reg_Saved->kbdmap_reg;
                  reg_tmp = kbd_map_reg.kbdmap_reg;
               }
#if  defined(DRV_KBD_32KEYS_ABOVE) || defined(DRV_KBD_48KEYS_ABOVE) || defined(DRV_KBD_64KEYS_ABOVE)
               else if (key_index < 64)  // the second loop for the 2nd 32-bit register
               {
                  reg_save = pkbd_map_reg_Saved->kbdmap_reg1;
                  reg_tmp = kbd_map_reg.kbdmap_reg1;
               }
#endif
#if defined(DRV_KBD_64KEYS_ABOVE)
               else
               {
                  reg_save = pkbd_map_reg_Saved->kbdmap_reg2;
                  reg_tmp = kbd_map_reg.kbdmap_reg2;
               }
#endif
               for(loop_cnt = 0; (loop_cnt < 32)&&(key_index < kbd_allkeys); loop_cnt++, key_index++) // internal loop for the 32bit register
               {
                  if((reg_save&(1<<loop_cnt)) != (reg_tmp&(1<<loop_cnt))) // key status not equal to the last time
                  {
                     if(!(reg_tmp&(1<<loop_cnt)))
                        key_info.bKeyStatus = KAL_FALSE; //pressed
                     else
                        key_info.bKeyStatus = KAL_TRUE;  //released
                     key_info.key_index = keypad_comm_def->keypad[key_index];
                     
#if defined(__EXTEND_QWERTY_KEYPAD__)
                     key_info.Row_Type = Normal_ROW;
#endif
                     
                     kbd_Detect_Key(&key_info, &keypad_detect_info, pkbd_status_Saved); // fill the new key information into the keypad_detect_info
                  }
               }
            }
            
            // process the detected keys
            Kbd_Process_Detected_Keys(&keypad_detect_info,pkbd_status_Saved, &kbd_map_reg);
         }
         
}


/*************************************************************************
* FUNCTION                                                            
*	kbd_key_det_mode_switch
*
* DESCRIPTION                                                           
*	This function is to switch to the one, two, or three keys detction mode.
*
* PARAMETERS
*  mode   - The mode to switch to
*
* RETURNS
*  KAL_TRUE   - Enable or disable two key dection mode successfully.
*  KAL_FALSE  - Already in the mode. No need to set. 
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool kbd_SetDetectionMode(kbd_key_det_mode mode)
{
#if defined(__TWO_KEY_DETECTION_SWITCHABLE__)||defined(__THREE_KEY_DETECTION_SWITCHABLE__)
   
   if ((kal_uint8)mode == kbd_key_detection_mode)
      return KAL_FALSE;
#if defined(__TWO_KEY_DETECTION_SWITCHABLE__)
   if (mode > kbd_2_keys_det_mode)
      return KAL_FALSE;
#elif defined(__THREE_KEY_DETECTION_SWITCHABLE__)
   if (mode > kbd_3_keys_det_mode)
      return KAL_FALSE;
#endif
   kbd_key_detection_new_mode = (kal_uint8)mode;
   
#if !defined(LOW_COST_SUPPORT)
   drv_trace1(TRACE_GROUP_10, KBD_DETECT_MODE_SWITCH, mode);
#endif // #if !defined(LOW_COST_SUPPORT)
   
   /* Set event to keypad task. */
   /*lint -e(534)*/kal_set_eg_events(KBD.event,KBD_SWITCH_DETCTION_MODE_EVENT,KAL_OR);
   return KAL_TRUE;
   
#else
   
#if !defined(LOW_COST_SUPPORT)
   drv_trace0(TRACE_GROUP_10, KBD_DETECT_MODE_SWITCH_NOT_SUPPORT);
#endif // #if !defined(LOW_COST_SUPPORT)
   return KAL_FALSE;
   
#endif
}

void kbd_task_main( task_entry_struct * task_entry_ptr )
{
   kal_uint32     event_group;
   kal_uint32     key_index;
   kal_bool       buf_full;
   kal_uint8      roomleft;
   keypad_status_struct    kbd_status_Saved; // the status will record the keypad map register value and referenced every time new key event coming
   
#if defined(__EXTEND_QWERTY_KEYPAD__)
   kal_uint8      i;
   
   // Init the qwerty key column status
   for(i = 0; i < KBD_COLUMN; i++)
   {
      kbd_status_Saved.key_column_all_low_GND[i] = KAL_FALSE;
      kbd_status_Saved.key_column_all_low_GPO[i] = KAL_FALSE;
   }

   kbd_status_Saved.extend_switch_mode_key = KAL_FALSE;
   kbd_status_Saved.extend_key_switch_pressed_num = 0;
   for(i = 0; i < KBD_KEY_DETECTION_CNT; i++)
    {
        kbd_status_Saved.kbd_switch_mode_extend_press_key[i]=KEY_INVALID;
        
    }
   
#endif
   
   kbd_get_keypad_status_reg(&kbd_status_Saved.kbd_map_reg); // Get the initial keypad register value
   
   // initialize the value of the saved pressed key
   for (key_index = 0; key_index < KBD_KEY_DETECTION_CNT; key_index++) 
   {
      kbd_saved_pressed_key[key_index] = KEY_INVALID;
   }
#ifdef __KBD_2STEP_KEY_SUPPORT__
   kbd_is_2steps_key = KAL_FALSE;
#endif
   kbd_press_event_count = 0;
   buf_full = KAL_FALSE;
   
   while(1)
   {
      /*lint -e(534)*/kal_retrieve_eg_events(KBD.event,EVENT_REQUESTED,KAL_OR_CONSUME,&event_group,KAL_SUSPEND);
#if defined(__MTK_INTERNAL__)
/* under construction !*/
#endif
      
      /* Check if there's swtich mode request. */
#ifdef KBD_DBGMODE
      if (event_group & KBD_SWITCH_DETCTION_MODE_EVENT)
#else  /*KBD_DBGMODE*/
         if ((event_group & KBD_SWITCH_DETCTION_MODE_EVENT) || (buf_full == KAL_TRUE))
#endif  /*KBD_DBGMODE*/
         {
            kbd_SwitchMode_EventHandler(&buf_full,&kbd_status_Saved );
         }
         
         if(event_group&KEY_DIRECTION_EVENT_ALL)
         {
            kbdbuffer_get_roomleft(roomleft);
            // roomleft must large than reserve for release and 2 additional jogball event.
            if( (roomleft > (kbd_press_event_count+kbd_ext_press_event_count+2)) &&
               (kbd_press_event_count <= kbd_key_detection_mode))
            {
               Kbd_Jogball_EventHandler(event_group);
            }
         }
         
         /* Skip the codes beblow, if there's no any key detection interrupt. */
         if (event_group & KBD_STATUS_CHANGE_EVENT)
            kbd_KeyEventHandler(&kbd_status_Saved);
   }
}


/*************************************************************************
* FUNCTION                                                            
*	kbd_task_reset
*
* DESCRIPTION
*	This function implements xyz's reset handler
*
* PARAMETERS 
*	task_index	-	task's index
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool 
kbd_task_reset(void)
{
  	/* Do task's reset here.
	 * Notice that: shouldn't execute modules reset handler since 
	 * stack_task_reset() will do. */
	return KAL_TRUE;
}

#if !defined(KBD_DETECT_ONLY_ONE_KEY) && defined(__EXTRA_A_B_KEY_SUPPORT__)
void EXT_A_EINT_HISR(void)
{
   ilm_struct     *Kp_ilm;
   //kal_bool       btmp;

   if (KAL_FALSE == kbd_twokey_detection_enable)
      return;
   /* LEVEL_HIGH: Original up, now down.*/
   if (KBD.ext_status[0] == LEVEL_HIGH)
   {
#if !defined(LOW_COST_SUPPORT)
   	drv_trace2(TRACE_GROUP_8, KBD_PUT_DATA_TO_BUFFER, kbd_onekey_press, DEVICE_KEY_EXT_A);
#endif // #if !defined(LOW_COST_SUPPORT)
      KBD_PUSH_ONEKEY_TO_KBDBUFFER(kbd_onekey_press, DEVICE_KEY_EXT_A);
      kbd_ext_press_event_count++;

      KBD_GPTI_STARTITEM(KBD.gpthandle[KBD_KEY_DETECTION_CNT], KBD.longpress_timeout, KBDTimeOutHandler, (void *)KBD_KEY_DETECTION_CNT);
   }
   /* LEVEL_LOW: Original down, now up.*/
   else
   {
      KBD_GPTI_STOPITEM(KBD.gpthandle[KBD_KEY_DETECTION_CNT]); 
#if !defined(LOW_COST_SUPPORT)
      drv_trace2(TRACE_GROUP_8, KBD_PUT_DATA_TO_BUFFER, kbd_onekey_release, DEVICE_KEY_EXT_A);
#endif // #if !defined(LOW_COST_SUPPORT)
      KBD_PUSH_ONEKEY_TO_KBDBUFFER(kbd_onekey_release, DEVICE_KEY_EXT_A);
      kbd_ext_press_event_count--;
   }
   EINT_Set_Polarity(EINT_A_KEY, KBD.ext_status[0]);
   KBD.ext_status[0] = !(KBD.ext_status[0]);
   kbd_SendMsg_To_UEM();
}


void EXT_B_EINT_HISR(void)
{
   ilm_struct     *Kp_ilm;

   if (KAL_FALSE == kbd_2key_detection_enable)
      return;
   /* LEVEL_HIGH: Original up, now down.*/
   if (KBD.ext_status[1] == LEVEL_HIGH)
   {
#if !defined(LOW_COST_SUPPORT)
   	drv_trace2(TRACE_GROUP_8, KBD_PUT_DATA_TO_BUFFER, kbd_onekey_press, DEVICE_KEY_EXT_B);
#endif // #if !defined(LOW_COST_SUPPORT)
      KBD_PUSH_ONEKEY_TO_KBDBUFFER(kbd_onekey_press, DEVICE_KEY_EXT_B);
      kbd_ext_press_event_count++;
      KBD_GPTI_STARTITEM(KBD.gpthandle[KBD_KEY_DETECTION_CNT+1], KBD.longpress_timeout, KBDTimeOutHandler, (void *)(KBD_KEY_DETECTION_CNT+1));
   }
   /* LEVEL_LOW: Original down, now up.*/
   else
   {
      KBD_GPTI_STOPITEM(KBD.gpthandle[KBD_KEY_DETECTION_CNT+1]); 
#if !defined(LOW_COST_SUPPORT)
      drv_trace2(TRACE_GROUP_8, KBD_PUT_DATA_TO_BUFFER, kbd_onekey_release, DEVICE_KEY_EXT_B);
#endif // #if !defined(LOW_COST_SUPPORT)
      KBD_PUSH_ONEKEY_TO_KBDBUFFER(kbd_onekey_release, DEVICE_KEY_EXT_B);
      kbd_ext_press_event_count--;
   }
   EINT_Set_Polarity(EINT_B_KEY, KBD.ext_status[1]);
   KBD.ext_status[1] = !(KBD.ext_status[1]);

   kbd_SendMsg_To_UEM();
}
#endif

/*
* FUNCTION
*	   kbd_is_mutiple_key
*
* DESCRIPTION
*   	This function is to check if the key is multi-defined
*
* CALLS
*
* PARAMETERS
*	   kal_uint8 key
*
* RETURNS
*	   kal_bool
*
* GLOBALS AFFECTED
*     None
*/

kal_bool kbd_IsKeymutiple(kal_uint8 key)
{
   kal_uint8 i, key_count=0;
   kal_uint32 num_key;
   
   num_key = sizeof(keypad_comm_def->keypad)/sizeof(kal_uint8);
   for(i=0;i<num_key;i++)
   {
      if(keypad_comm_def->keypad[i]==key)
      {        
         key_count++;
            if(key_count>=2){
#if !defined(LOW_COST_SUPPORT)
            	drv_trace1(TRACE_GROUP_8, KBD_MULTIPLE_KEY, key);
#endif // #if !defined(LOW_COST_SUPPORT)
               return KAL_TRUE;            
             }
      }
   }
   
   
#if !defined(LOW_COST_SUPPORT)
   drv_trace1(TRACE_GROUP_8, KBD_NOT_MULTIPLE_KEY, key);
#endif // #if !defined(LOW_COST_SUPPORT)
   return KAL_FALSE;    
}      
/*
* FUNCTION
*	   kbd_find_2step
*
* DESCRIPTION
*   	This function is to find who are 2 step key
*
* CALLS
*
* PARAMETERS
*	   *number: number of 2 step keys 
*		*two_step: 2 step key definition
*
* RETURNS
*	   none
*
* GLOBALS AFFECTED
*     None
*/
void kbd_find_2step(kal_uint32 *number, kal_uint8 *two_step)
{
	#ifdef __KBD_2STEP_KEY_SUPPORT__
	*number=1;
	*two_step=DEVICE_KEY_FUNCTION;
	#else
	*number=0;
	#endif
#if !defined(LOW_COST_SUPPORT)
	drv_trace2(TRACE_GROUP_10, KBD_2STEP_KEY_QUERY, *two_step, *number);
#endif // #if !defined(LOW_COST_SUPPORT)
}	

	
#else /*!defined(__KBD_JOYSTICK_SUPPORT__)*/

kal_bool kbd_key_det_mode_switch(kbd_key_det_mode mode)
{
   return KAL_FALSE;
}

#endif /*!defined(__KBD_JOYSTICK_SUPPORT__)*/

#else //#if !defined(DRV_KBD_NOT_EXIST)
void keypad_customize_init(void){;}
//kal_bool kbd_IsKeyPress(kal_uint8 key){return KAL_FALSE;}

#endif // #if !defined(DRV_KBD_NOT_EXIST)

