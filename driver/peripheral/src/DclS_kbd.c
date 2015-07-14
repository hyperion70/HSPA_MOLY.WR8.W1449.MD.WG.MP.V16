/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   dcl_kbd.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Header file of DCL (Driver Common Layer) for KBD.
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
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
//#include 	"kal_release.h"
#include    "kbd_table.h"  
#include "dcl.h"
#include "keypad.h"
#include "keypad_sw.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_public_defs.h"
#include    "drv_trc.h"



#ifndef DRV_KP_OFF
#if !defined(DRV_KBD_NOT_EXIST)

extern kal_uint8  kbd_key_detection_mode;
extern kbd_struct KBD;
extern kbd_buffer_struct    kbd_buffer;


static void Kbd_hw_event_Callback(DCL_EVENT  event, kal_uint8 key);


DCL_STATUS DclSKBD_Initialize(void)
{
	DCL_HANDLE handle ;

	DclHKBD_Initialize();
	handle = DclHKBD_Open(DCL_KBD, 0);
	
	DclHKBD_RegisterCallback(handle, DCL_EVENT_HKBD_STATUS_CHANGE, (KBDH_EVENT_FUNC)&Kbd_hw_event_Callback);
	Kbd_Initiaze();
	
	return STATUS_OK;
}

DCL_HANDLE DclSKBD_Open(DCL_DEV dev, DCL_FLAGS flags)
{
	 if( ( dev != DCL_KBD ))
	 	ASSERT(0);
	 
	 return (DCL_HKBD_MAGIC_NUM |flags);
}

 

static void Kbd_hw_event_Callback(DCL_EVENT  event, kal_uint8 key)
{
	
if(DCL_EVENT_HKBD_STATUS_CHANGE == event)
{
kal_set_eg_events(KBD.event,KBD_STATUS_CHANGE_EVENT,KAL_OR);   
}		
}
			
DCL_STATUS DclSKBD_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
   switch (cmd)
   {
	case KBD_CMD_SET_LONG_PRESS_TIME:
		{
			SKBD_CTRL_TIME_T* prCtrlSLP;
			prCtrlSLP = &(data->rKBDCtrTime);
                   KBD.longpress_timeout = prCtrlSLP->u4Tick;
			break;
		}
	
	case KBD_CMD_SET_REPEAT_PRESS_TIME:
		{
			SKBD_CTRL_TIME_T* prCtrlTime ;
			prCtrlTime = &(data->rKBDCtrTime);
                   KBD.repeat_time = prCtrlTime->u4Tick;
			break;
		}
	
	case KBD_CMD_SET_DETECTION_MODE:
		{
			SKBD_CTRL_MODE_T* prCtrlMode;
			prCtrlMode = &(data->rKBDCtrMode);
			prCtrlMode->bFlag = (DCL_BOOL)kbd_SetDetectionMode((kbd_key_det_mode)prCtrlMode->Det_Mode);
			break;
		}
	
	case KBD_CMD_GET_KEY_DATA:
		{
			kal_bool fg ;
			//kbd_data keydata;
			SKBD_CTRL_KEYDATA_T* prCtrlData ;
			prCtrlData = &(data->rKBDCtrGetData);
			fg = Kbd_GetKeyDatas((kbd_data*)prCtrlData);
			
			if(KAL_FALSE == fg)
				return STATUS_BUFFER_EMPTY;
			break;
		}

	
	case KBD_CMD_PEEK_KEY_DATA:
		{
			kal_bool fg;
			SKBD_CTRL_PEEKDATA_T* prCtrlData1;
			prCtrlData1 = &(data->rKBDCtrPeekData);
			fg = Kbd_PeekKeyDatas((kbd_data*)prCtrlData1->keydata, (kal_bool)prCtrlData1->specify_read, (kal_uint32)prCtrlData1->read_pointer,  (kal_uint32*)prCtrlData1->current_read_pointer);
			if(KAL_FALSE == fg)
			return STATUS_BUFFER_EMPTY;
			break;
		}
	
	case KBD_CMD_GET_DETECTION_MODE:
		{
			SKBD_CTRL_MODE_T* prCtrlMode1;
			prCtrlMode1 = &(data->rKBDCtrMode);
                    prCtrlMode1->Det_Mode = kbd_key_detection_mode;
			break;
		}

	case KBD_CMD_CTRL_KEY_SUPPORT:
		{
			SKBD_CTRL_KEYSUPPORT_T* pCtrl = &(data->rKBDCtrlKeySupport);
			pCtrl->fgIKBS =  kbd_IsKeySupported(pCtrl->uKey);
			break;
		}
	case KBD_CMD_CTRL_KEY_MULTIPLE:
		{
			SKBD_CTRL_MULTIKEY_T* pCtrl = &(data->rKBDCtrlMultiple);
			pCtrl->fgIMK =  kbd_IsKeymutiple(pCtrl->uKey);
			
			break;
		}
	case KBD_CMD_GET_KEY_EVENT_CNT:
		{
                    kal_uint8 left;
			SKBD_CTRL_KEY_CNT_T* pCtrl = &(data->rKBDCtrkeyCnt);
			kbdbuffer_get_roomleft(left);
                   pCtrl->keycnt = (kbd_buffer_size - left - 1);

			break;
		}
	case KBD_CMD_PUT_KEY_DATA:
		{
			SKBD_CTRL_PUTKEY_T* PtrlData;
			PtrlData = &(data->rKBDCtrPutKey);
		        kbd_SendKey(PtrlData->keydata);
			break;
		}
	case KBD_CMD_FIND_TWO_STEP:
		{
			SKBD_CTRL_FIND_TWO_STEP_T* pctrldata;
			pctrldata = &(data->rKBDCtrlFindTwoStepKey);
			#ifdef __KBD_2STEP_KEY_SUPPORT__
                  *(pctrldata->number)=1;
                *(pctrldata->two_step)=DEVICE_KEY_FUNCTION;
#else
                *(pctrldata->two_step)=0;
#endif
#if !defined(LOW_COST_SUPPORT)
                drv_trace2(TRACE_GROUP_10, KBD_2STEP_KEY_QUERY, *(pctrldata->two_step),  *(pctrldata->number));
#endif // #if !defined(LOW_COST_SUPPORT)
		}
	     break;
	
		default:
			break;
}
   	return STATUS_OK;
}
	 DCL_STATUS DclSKBD_Close(DCL_HANDLE handle){return STATUS_OK;}

#else

DCL_STATUS DclSKBD_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event,PFN_DCL_CALLBACK callback){return STATUS_OK;}
DCL_STATUS DclSKBD_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data){return STATUS_INVALID_CMD;}
DCL_STATUS DclSKBD_Initialize(void){return STATUS_OK;}
DCL_HANDLE DclSKBD_Open(DCL_DEV dev, DCL_FLAGS flags){return STATUS_UNSUPPORTED;}
DCL_STATUS DclSKBD_Close(DCL_HANDLE handle){return STATUS_OK;}

#endif

#endif
