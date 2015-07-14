/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *    dcl_sts.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *
 *    This file is the software DCL layer between touch panel Drivers and MMI Frame. 
 *
 *    This file support both RTP and CTP.    
 *
 *
 * Author:
 * -------
 * -------
 *
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#include "drv_features.h"
#include "drv_comm.h"

//#if defined(TOUCH_PANEL_SUPPORT) || defined(HAND_WRITING)
#include "touch_panel_.h"
#include "ts_hw.h"
#include "drv_hisr.h"
#include "dcl.h"
#include "dcl_hts.h"
#include "intrCtrl.h" /* Included here to overcome compilation error */

//#ifdef DCL_TS_INTERFACE
//#if !defined(DRV_TS_OFF)

#if (defined(TOUCH_PANEL_SUPPORT) || defined(HAND_WRITING)) && !defined(DRV_HTS_OFF)



#define DCL_STS_MAGIC_NUM  0x20000000
#define DCL_STS_IS_HANDLE_MAGIC(handl_) ((handl_)& DCL_STS_MAGIC_NUM)
#define DCL_STS_GET_DEV(handle_) ((handle_) & (~DCL_STS_MAGIC_NUM))

/*single open lock*/
static kal_bool fgSTSInit = KAL_FALSE;


//DCL_HANDLE dcl_tp_handle;

extern TouchPanelDataStruct TP;

PFN_DCL_CALLBACK DclSTS_PushBufferCb;

DCL_STATUS DclSTS_Initialize(void)
{
   if(fgSTSInit == KAL_FALSE) 
   {
      touch_panel_init();
      fgSTSInit = KAL_TRUE;
   }
   return STATUS_OK;
}

DCL_HANDLE DclSTS_Open(DCL_DEV dev, DCL_FLAGS flags)
{
   if( ( dev != DCL_TS ) || (fgSTSInit == KAL_FALSE))
   {
      return DCL_HANDLE_INVALID;
   }
   
   return (DCL_HANDLE)(DCL_STS_MAGIC_NUM | DCL_TS);
}

DCL_STATUS DclSTS_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
   return STATUS_UNSUPPORTED;
}

DCL_STATUS DclSTS_Close(DCL_HANDLE handle)
{
   if(DCL_STS_IS_HANDLE_MAGIC(handle) == 0)
   {
      return STATUS_INVALID_ARGUMENT;
   }
   return STATUS_OK;
}

DCL_STATUS DclSTS_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
   return STATUS_UNSUPPORTED;
}

/*
* FUNCTION                                                            
*	DclSTS_PushBufferCbWraper
*
* DESCRIPTION                                                           
*   This function is to wrap the touch panel call back function. (Not an export API)
*
* CALLS  
*	It is called by touch panel SW module to execute call back DclSTS_PushBufferCb()
*
* PARAMETERS
*   Touch panel SW module will feed event in this call back function.
*	
* RETURNS
*
* GLOBALS AFFECTED
*   external_global
*/
void DclSTS_PushBufferCbWraper(void *parameter, Touch_Panel_Event_enum state)
{
   if(DclSTS_PushBufferCb != NULL)
   {
      DclSTS_PushBufferCb((DCL_EVENT)state);
   }
   else
      ASSERT(0);
}
/*
* FUNCTION                                                            
*	DclSTS_RegisterCallback
*
* DESCRIPTION                                                           
*   	This function is to register SW TS call back funciton.
*       Execute call back function when we push ts data into ts ring buffer.
*
* CALLS  
*	It is called to register SW TS call back funciton.
*
* PARAMETERS
*	event - a valid event indicate register which event's call back funciton
*           1. DCL_EVENT_STS_PUSH_BUFF
*
*   callback - a call back funciton
*	
* RETURNS
*	STATUS_OK: command is executed successfully.
*	STATUS_FAIL: command is failed.
*   STATUS_INVALID_CMD: It's a invalid command.
*
* GLOBALS AFFECTED
*   external_global
*/
DCL_STATUS DclSTS_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
   if(DCL_STS_IS_HANDLE_MAGIC(handle) == 0)
   {
      ASSERT(0);
      return STATUS_INVALID_ARGUMENT;
   }
   if(NULL ==callback)
   {
      ASSERT(0);
   }
   if(event == DCL_EVENT_STS_PUSH_BUFF)
   {
      DclSTS_PushBufferCb = callback;
      TP.touch_panel_event_cb = DclSTS_PushBufferCbWraper;
      TP.cb_para=NULL;
   }

   if(DCL_EVENT_STS_UP == event )
   {
      TP.tp_up_cb=callback;
      TP.tp_up_cb_para=NULL;
   }

   if(DCL_EVNET_STS_DOWN ==event)
   {
      TP.tp_down_cb=callback;
      TP.tp_down_cb_para=NULL;
   }
   if(event >= DCL_EVENT_STS_MAX)
   {
      return STATUS_FAIL;
   }
   return STATUS_OK;
}

/*
* FUNCTION                                                            
*	CopyEvent
*
* DESCRIPTION                                                           
*   This function is to copy from MAUI touch panel struct to DCL SW touch panel struct.
*
* CALLS  
*	It is called to copy
*
* PARAMETERS 
*   STS_CTRL_GET_T        - source
*   TouchPanelMultipleEventStruct - destination
*
* RETURNS
*
* GLOBALS AFFECTED
*   external_global
*/
static void CopyEvent(STS_CTRL_GET_T  *prGE, TouchPanelMultipleEventStruct *prTD)
{
   DCL_UINT32 i;
	  
   prGE->uModel = prTD->model;
   prGE->uPadding = prTD->padding;
   prGE->u2Time_stamp = prTD->time_stamp;

   for(i=0;i<prTD->model;i++)
   {
      prGE->rPoints[i].u2x = prTD->points[i].x;
      prGE->rPoints[i].u2y = prTD->points[i].y;
      prGE->rPoints[i].u2z = prTD->points[i].z;
      switch(prTD->points[i].event)
      {
         case PEN_DOWN:
            prGE->rPoints[i].u2Event = DCL_PEN_DOWN;
            break;	
         case PEN_UP:
            prGE->rPoints[i].u2Event = DCL_PEN_UP ;
            break;	
         case PEN_MOVE:
            prGE->rPoints[i].u2Event = DCL_PEN_MOVE;
            break;	
         case PEN_LONGTAP:
            prGE->rPoints[i].u2Event = DCL_PEN_LONGTAP ;
            break;	
         case PEN_REPEAT:
            prGE->rPoints[i].u2Event = DCL_PEN_REPEAT;
            break;	
         case PEN_ABORT:
            prGE->rPoints[i].u2Event = DCL_PEN_ABORT;
            break;	
         case TP_UNKNOWN_EVENT:
            prGE->rPoints[i].u2Event = DCL_TP_UNKNOWN_EVENT;
            break;	
         case STROKE_MOVE:
            prGE->rPoints[i].u2Event = DCL_STROKE_MOVE;
            break;	
         case STROKE_DOWN:
            prGE->rPoints[i].u2Event = DCL_STROKE_DOWN;
            break;	
         case  STROKE_LONGTAP:
            prGE->rPoints[i].u2Event = DCL_STROKE_LONGTAP;
            break;	
         case STROKE_UP:
            prGE->rPoints[i].u2Event = DCL_STROKE_UP;
            break;	
         case STROKE_STATICAL:
            prGE->rPoints[i].u2Event = DCL_STROKE_STATICAL;
            break;	
         case STROKE_HOLD:
            prGE->rPoints[i].u2Event = DCL_STROKE_HOLD;
            break;	
         case PEN_LONGTAP_HOLD:
            prGE->rPoints[i].u2Event = DCL_PEN_LONGTAP_HOLD;
            break;	
         case PEN_REPEAT_HOLD:
            prGE->rPoints[i].u2Event = DCL_PEN_REPEAT_HOLD;
            break;	
         default:
         {
            ASSERT(0);
            break;
         }
      }
   }
}

DCL_STATUS DclSTS_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
   if(DCL_STS_IS_HANDLE_MAGIC(handle) == 0)
   {
      return STATUS_INVALID_ARGUMENT;
   }

   switch(cmd)
   {
      case STS_CMD_GET_EVENT:
      {
         kal_bool  fg;
         TouchPanelMultipleEventStruct prTouchData;
         STS_CTRL_GET_T  *prCtrlGE;  

         prCtrlGE = &(data->rTSCtrlGE);
         fg = touch_panel_get_event_(&prTouchData);

         if(fg!=KAL_FALSE)
      	   CopyEvent(prCtrlGE, &prTouchData); // copy prTouchData to prCtrlGE
         return fg;
      }
      case STS_CMD_PEEK_EVENT:
      {
         extern kal_bool touch_panel_peek_event_(TouchPanelMultipleEventStruct *touch_data);
         kal_bool  fg;
         TouchPanelMultipleEventStruct prTouchData;
         STS_CTRL_GET_T  *prCtrlGE;  
      
         prCtrlGE = &(data->rTSCtrlGE);
         fg = touch_panel_peek_event_(&prTouchData);
         if(fg!=KAL_FALSE)
         {
            CopyEvent(prCtrlGE, &prTouchData); // copy prTouchData to prCtrlPE
         }
         return fg;
      }
      case STS_CMD_ENABLE:
      {
         STS_CTRL_EN_T  *prCtrlEN;  
         prCtrlEN = &(data->rTSCtrlEN);
         touch_panel_enable_((kal_bool)prCtrlEN->fgEnable);/*enable/disable touch panel*/
         break;
      }
      case STS_CMD_FLUSH:
      {
         touch_panel_flush_();/*flsuh data in ring buffer*/
         break;
      }
      case STS_CMD_START_CALI:
      {
         STS_CTRL_SC_T  *prCtrlSC;  
         prCtrlSC = &(data->rTSCtrlSC);
         touch_panel_start_cali_((TouchPanelCoordStruct *)(prCtrlSC->rpPoint), prCtrlSC->u2Num);
         break;
      }
      case STS_CMD_STOP_CALI:
      {
         touch_panel_stop_cali_();
         break;
      }
      case STS_CMD_READ_CALI:
      {
         STS_CTRL_RC_T  *prCtrlRC;  
         TouchPanelCaliStruct rTPCali;
      
         prCtrlRC = &(data->rTSCtrlRC);
         touch_panel_read_cali_(&rTPCali );
         prCtrlRC->rCali.x_slope  = rTPCali.x_slope;
         prCtrlRC->rCali.x_offset = rTPCali.x_offset;
         prCtrlRC->rCali.y_slope  = rTPCali.y_slope;
         prCtrlRC->rCali.y_offset = rTPCali.y_offset;
         
         break;
      }
      case STS_CMD_SET_CALI:
      {
         STS_CTRL_SETC_T  *prCtrlSETC;
         TouchPanelCaliStruct rTPCali;
      
         prCtrlSETC = &(data->rTSCtrlSETC);
         rTPCali.x_slope  = prCtrlSETC->rCali.x_slope;
         rTPCali.x_offset = prCtrlSETC->rCali.x_offset;
         rTPCali.y_slope  = prCtrlSETC->rCali.y_slope;
         rTPCali.y_offset = prCtrlSETC->rCali.y_offset;
         touch_panel_set_cali_(rTPCali);
         break;
      }
      case STS_CMD_RESET:
      {
         STS_CTRL_RESET_T  *prCtrlRESET;  
         prCtrlRESET = &(data->rTSCtrlRESET);
         touch_panel_reset_((kal_bool)prCtrlRESET->fgSkipUnreleaseEnable);
         break;
      }
      case STS_CMD_RESET_HANDWRITING:
      {
         touch_panel_reset_handwriting_();
         break;
      }
      case STS_CMD_CONF_SAMPLE_PERIOD:
      {
         STS_CTRL_CSP_T  *prCtrlCSP;  
         prCtrlCSP = &(data->rTSCtrlCSP);
         touch_panle_conf_sample_period_(prCtrlCSP->u4Low, prCtrlCSP->u4High);
         break;
      }
      case STS_CMD_CONF_MOVE_OFFSET:
      {
         STS_CTRL_CMO_T  *prCtrlCMO;
         prCtrlCMO = &(data->rTSCtrlCMO);
         touch_panel_conf_move_offset_(prCtrlCMO->u2Pen_offset, prCtrlCMO->u2Stroke_offset, 
                                      prCtrlCMO->u2Longtap_pen_offset,
                                      prCtrlCMO->u2Longtap_stroke_offset);
         break;
      }
      case STS_CMD_CONF_HANDWRITING:
      {
         STS_CTRL_CHW_T  *prCtrlCHW; 
         prCtrlCHW = &(data->rTSCtrlCHW);
         touch_panel_conf_handwriting_((TouchPanelHandAreaStruct*)(prCtrlCHW->rArea), prCtrlCHW->u2n, 
                                      (TouchPanelHandAreaStruct*)(prCtrlCHW->rExtArea) );
         break;
      }
      case STS_CMD_CONF_TIMEOUT_PERIOD:
      {
         STS_CTRL_CTP_T  *prCtrlCTP;  
         prCtrlCTP = &(data->rTSCtrlCTP);
         touch_panle_conf_timeout_period_(prCtrlCTP->u4Longtap, prCtrlCTP->u4Repeat,
                                        prCtrlCTP->u4Handwriting_longtap);
         break;
      }
   case STS_CMD_POWER_ON:
   {
#if defined(__TOUCH_PANEL_CAPACITY__)
      STS_CTRL_POWER_ON_T  *prCtrlPO;
      prCtrlPO = &(data->rTSCtrlPO);
      
      touch_panel_capacitive_power_on((kal_bool)prCtrlPO->fgPowerOn);
#endif
      break;
   }
   case STS_CMD_SET_DEVICE:
   {
#if defined(__TOUCH_PANEL_CAPACITY__)
      STS_CTRL_SET_DEVICE_T *prCtrlSD;
      prCtrlSD = &(data->rTSCtrlSD);
      
      touch_panel_capacitive_set_device((ctp_device_mode_enum)prCtrlSD->mode);
#endif
      break;
   }
   case STS_CMD_COMMAND:
   {
#if defined(__TOUCH_PANEL_CAPACITY__)
      STS_CTRL_COMMAND_T *prCtrlCmd;
      prCtrlCmd = &(data->rTSCtrlCmd);
      
      touch_panel_capacitive_command(prCtrlCmd->u4Command, prCtrlCmd->pVoid1, prCtrlCmd->pVoid2);
#endif
      break;
   }
case STS_CMD_CTRL_CUSTOM_PARAM:
        {
            DCL_CTRL_CUSTOM_PARAM_T* prCtrlCCP;
            prCtrlCCP = &(data->rTSCtrlCustomParam);
            Touch_Panel_Ctrl_Param(*prCtrlCCP);
            break;
        }
   case STS_CMD_CTRL_CUSTOM_PARAM_RANGE:
        {
            DCL_CTRL_CUSTOM_PARAM_RANGE_T* prCtrlCPR;
            prCtrlCPR = &(data->rTSCtrlCustomParamRang);
            Touch_Panel_Ctrl_Param_Range(*prCtrlCPR);
            break;
        }
   case STS_CMD_CTRL_MICRONMETER_TO_COORD:
      {
        DCL_CTRL_MICRONMETER_COORD_T* prCtrlCMP;
        prCtrlCMP = &(data->rTSCtrlMicronMeter_Pixel);
        Touch_Panel_MicronMeter_To_Coord(prCtrlCMP);
        
            break;
      }
   case STS_CMD_CTRL_COORD_TO_MICRONMETER:
    {
            DCL_CTRL_MICRONMETER_COORD_T* prCtrlCM;
            prCtrlCM = &(data->rTSCtrlMicronMeter_Pixel);
            Touch_Panel_Pixel_To_MicronMeter(prCtrlCM);
            break;
    }
   case STS_CMD_QUERY_TP_TYPE:
        {
                DCL_TP_TYPE_T* prCtrlTP;
                prCtrlTP = &(data->rTSCtrlTouchPanelType);
                #if defined(__TOUCH_PANEL_CAPACITY__)
                prCtrlTP->TouchPanelType = CTP_Type;
                #else
                 prCtrlTP->TouchPanelType = RTP_Type;
                #endif
                
                break;
        }
      default:
   	{
         return STATUS_INVALID_CMD;
      }
   }
   return STATUS_OK;
}
#else

DCL_STATUS DclSTS_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclSTS_Initialize(void)
{
	return STATUS_UNSUPPORTED;
}

DCL_HANDLE DclSTS_Open(DCL_DEV dev, DCL_FLAGS flags)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclSTS_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
	return STATUS_UNSUPPORTED;
}
DCL_STATUS DclSTS_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	return STATUS_UNSUPPORTED;
}
DCL_STATUS DclSTS_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclSTS_Close(DCL_HANDLE handle)
{
	return STATUS_UNSUPPORTED;
}

#endif //!defined(DRV_TS_OFF)

//#endif	//DCL_TS_INTERFACE




