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
 *    serial_interface.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines Touch Panel Interface.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef TOUCH_PANEL__H
#define TOUCH_PANEL__H
#include "eint.h"
#include "intrCtrl.h"
#include "dcl_hts.h"
#include "kal_public_api.h"

#if defined(__TOUCH_PANEL_CAPACITY__)
#define   TOUCH_PANEL_BUFFER_SIZE 512*16 //size MUST be exponential of 2
#define   CTP_SUPPORT_POINTS 5
#define     CTP_EVENT_HEADER 8
#define   BASIC_EVENT_UNIT   CTP_EVENT_HEADER + 40 // size of TouchPanelMultipleEventStruct

#else
#define   TOUCH_PANEL_BUFFER_SIZE 512
#define   BASIC_EVENT_UNIT   13 // 5 -> 7, for 2 more time stamp.
#endif//#if defined(__TOUCH_PANEL_CAPACITY__)

#define   TOUCH_PANEL_BUFFER_HIGH_THRES TOUCH_PANEL_BUFFER_SIZE*90/100
#define   TOUCH_PANEL_BUFFER_LOW_THRES TOUCH_PANEL_BUFFER_SIZE*80/100
#define   HAND_WRITING_AREA_NUM  3

#if !defined(DRV_TOUCH_PANEL_CUSTOMER_PARAMETER)
#define   MIN_PEN_MOVE_OFFSET 5
#define   HAND_WRITING_MAX_OFFSET 50
#define   NONHAND_WRITING_MAX_OFFSET 100
#define   MAX_STROKE_MOVE_OFFSET 1

#if defined(TRULY_HVGA_LCM)
#define   TOUCH_PANEL_CALI_CHECK_OFFSET  12
#else
#define   TOUCH_PANEL_CALI_CHECK_OFFSET  6
#endif //#if defined(TRULY_HVGA_LCM)
#endif //#if !defined(DRV_TOUCH_PANEL_CUSTOMER_PARAMETER)

#define   MAX_ADC_VALUE 4095 

#define   touch_down_level   LEVEL_LOW   /*touch down level*/
#define   touch_up_level     LEVEL_HIGH  /*touch up level*/

#if !defined(IRQ_TS_CODE)
#if defined(DRV_TP_6516_AP_SETTING)
#define IRQ_TS_CODE IRQ_TOUCHSCREEN_CODE
#elif defined(DRV_TP_IRQ_TPC)
#define IRQ_TS_CODE IRQ_TPC_CODE
#else
#define IRQ_TS_CODE IRQ_AUXADC_CODE
#endif
#endif//#if !defined(IRQ_TS_CODE)

#define CTP_PATTERN 0xAA

typedef enum {
  CTP_NO_POINT,
  CTP_GESTURE, //save the gesture information in one point event
  CTP_1POINT=1,
  CTP_2POINTS,
  CTP_3POINTS,
  CTP_4POINTS,
  CTP_5POINTS,
  CTP_6POINTS,
  CTP_7POINTS,
  CTP_8POINTS,
  CTP_9POINTS,
  CTP_10POINTS,
  //add new detection type before unknown
  CTP_UNKNOWN
} CTP_EVENT_NUMBER_ENUM;

typedef struct
{
   // Touch_Panel_Event_enum
   kal_uint16 event; 
   /*coordinate point, not diff*/
   kal_uint16 x;  
   kal_uint16 y;
   kal_uint16 z; //resistance TP: presure,  capacitive TP: area
} TP_SINGLE_EVENT_T;

typedef enum {
      UP,
      DOWN
} Touch_Panel_PenState_enum;

typedef enum {
      CTP_LAST_EVENT_GET,
      CTP_LAST_EVENT_SET
} Touch_Panel_Handle_LastEvent_enum;

typedef enum {
      HAND_WRITING,
      NON_HAND_WRITING
} Touch_Panel_Area_enum;
typedef enum {
      PEN_DOWN,    /*0*/  
      PEN_UP,      /*1*/
      PEN_MOVE,    /*2*/
      PEN_LONGTAP, /*3*/     
      PEN_REPEAT,  /*4*/ 
      PEN_ABORT,   /*5*/ 
      TP_UNKNOWN_EVENT,/*6*/
      STROKE_MOVE,     /*7*/
      STROKE_STATICAL, /*8*/
      STROKE_HOLD, /*9*/
      PEN_LONGTAP_HOLD, /*10*/
      PEN_REPEAT_HOLD,  /*11*/ 
      STROKE_DOWN_, /*12*/
      STROKE_LONGTAP_,   /*13*/
      STROKE_UP_,/*14*/
      STROKE_DOWN=0xc0, /*0*/        /*1*/
      STROKE_LONGTAP=0x7e,   /*8*/
      STROKE_UP=0x7f/*127*/
} Touch_Panel_Event_enum;
typedef kal_uint16 (*CTP_FUNC)(kal_int16 x_diff, kal_int16 y_diff, kal_uint16 count);

typedef struct
{   
   kal_int16 x;  /*x coordinate*/
   kal_int16 y;  /*y coordinate*/ 
}TouchPanelCoordStruct; 
typedef struct
{  
   TouchPanelCoordStruct min;
   TouchPanelCoordStruct max;
}TouchPanelHandAreaStruct; 

typedef struct
{  
   /*x*/ 
   double x_slope;
   double x_offset; 
   /*y*/   
   double y_slope;
   double y_offset; 
}TouchPanelCaliStruct ; 
typedef void (*TP_EVENT_FUNC)(void *parameter, Touch_Panel_Event_enum state) ; 
typedef struct
{   
   kal_eventgrpid    event;               /*event id*/
   kal_uint8         gpthandle;           /*gpt handle*/
   kal_uint8         eint_chan;
   kal_uint32        longtap_cnt;         /*LongTap cnt*/
   kal_uint32        handwriting_longtap_cnt;         /*LongTap cnt*/
   kal_uint32        repeat_cnt;          /*Repeat cnt*/
   kal_uint32        low_sample_period;
   kal_uint32        high_sample_period;
   TouchPanelHandAreaStruct handarea[HAND_WRITING_AREA_NUM];    /*hand area*/
   TouchPanelHandAreaStruct ext_handarea;     /*extended area*/
   kal_uint16               hand_num;   
   kal_bool                 ext_enable;   /*extended stroke or not*/
   TouchPanelCoordStruct cur;             /*current point coord.*/
   TouchPanelCoordStruct pre;             /*previous point coord.*/
   TouchPanelCoordStruct temp;             /*previous point coord.*/      
   TouchPanelCoordStruct begin;             /*the first down point coord.*/      
   TP_EVENT_FUNC touch_panel_event_cb;
   void     *cb_para;
   Touch_Panel_Area_enum area;            /*(non)handwriting*/  
   Touch_Panel_PenState_enum      state;  /*Down or UP*/  
   kal_bool  skip_unrelease_enable;
   kal_bool  skip_unrelease_state;   
   kal_bool  is_buff_full;
   kal_bool  wait_next_down;      /*inidcate if the down point reasonable*/
   kal_uint16 pen_offset;         /*pen move offset*/
   kal_uint16 longtap_pen_offset;/*longtap pen move offset*/
   kal_uint16 longtap_stroke_offset; /*longtap stroke move offset*/
   kal_uint16 storke_offset;     /*stroke offset*/
   kal_bool   longtap_state;     /*wait longtap timeout or not*/
#if defined(DRV_TOUCH_PANEL_PAIR_GUARANTEE)
   Touch_Panel_Event_enum buffer_push_stat;
   TouchPanelCoordStruct  buffer_push_point;             /*previous point coord.*/   
#endif //#if defined(DRV_TOUCH_PANEL_PAIR_GUARANTEE)

   DCL_HANDLE hts_handle;
   PFN_DCL_CALLBACK tp_down_cb;
   void *	tp_down_cb_para;
   PFN_DCL_CALLBACK tp_up_cb;
   void *   tp_up_cb_para;

}TouchPanelDataStruct;

typedef struct
{
   kal_int16     x_adc;
   kal_int16     y_adc;
   Touch_Panel_Event_enum event;
   kal_uint16   time_stamp;		// unit: system tick
}TouchPanelEventStruct;

typedef struct
{
   kal_uint16   model; // Single/Dual/Triple/Four/Five/All gesture 
   kal_uint16   padding; //currently use for check the structure format correctness, 0xAA
   kal_uint32  time_stamp;
   TP_SINGLE_EVENT_T points[5];
} TouchPanelMultipleEventStruct;


typedef struct
{
   kal_uint8      touch_panel_data[TOUCH_PANEL_BUFFER_SIZE];
   kal_uint16      touch_buffer_rindex;
   kal_uint16      touch_buffer_windex;
#if defined(__TOUCH_PANEL_CAPACITY__)
   kal_uint16      touch_buffer_last_rindex;
   kal_uint16      touch_buffer_last_windex;
#endif
}TouchPanelBufferStruct;

typedef struct {
#if defined(DRV_TOUCH_PANEL_CUSTOMER_PARAMETER)
   kal_uint32 ts_debounce_time; //TS_DEBOUNCE_TIME
   kal_uint32 touch_panel_cali_check_offset;
   kal_uint32 min_pen_move_offset;//  MIN_PEN_MOVE_OFFSET = 10;
   kal_uint32 hand_writing_max_offset;//  HAND_WRITING_MAX_OFFSET = 50;
   kal_uint32 nonhand_writing_max_offset;//  NONHAND_WRITING_MAX_OFFSET = 100;
   kal_uint32 max_stroke_move_offset;//  MAX_STROKE_MOVE_OFFSET = 1;
   kal_uint32 touch_pressure_threshold_high;// TOUCH_PRESSURE_THRESHOLD_HIGH=6000;
#if defined(DRV_TOUCH_PANEL_MULTIPLE_PICK)
   kal_uint32 multiple_point_selection;//  MULTIPLE_POINT_SELECTION= 3;
#endif //#if defined(DRV_TOUCH_PANEL_MULTIPLE_PICK)
#if defined(__DRV_TP_DISCARD_SHIFTING__)
   kal_uint32 pressure_check_boundary;//  PRESSURE_CHECK_BOUNDARY = 2000;
   kal_uint32 pressure_shifting_boundary;//  PRESSURE_SHIFTING_BOUNDARY = 800;
#endif //#if defined(__DRV_TP_DISCARD_SHIFTING__)
#endif //#if defined(DRV_TOUCH_PANEL_CUSTOMER_PARAMETER)
   kal_int32 touch_panel_filter_thresold;
   /*ADC*/
   kal_int32 x_adc_start;
   kal_int32 x_adc_end;
   kal_int32 y_adc_start;
   kal_int32 y_adc_end;
   /*Coord.*/
   kal_int32 x_coord_start;
   kal_int32 x_coord_end;
   kal_int32 y_coord_start;
   kal_int32 y_coord_end;
   /*Size.*/
   kal_int32 x_millimeter;
   kal_int32 y_millimeter;
   /*EINT*/
   kal_uint8  eint_down_level;	
} TouchPanel_custom_data_struct;

typedef struct {  
   TouchPanel_custom_data_struct * (*tp_get_data)(void);
   void (*tp_read_adc)(kal_uint16 *x, kal_uint16 *y);
#ifdef TOUCH_PANEL_PRESSURE
   kal_bool (*tp_pressure_check)(void);
#endif
   void (*tp_irq_enable)(kal_bool on);
}TouchPanel_customize_function_struct;  

typedef enum {
      CTP_PARA_START,
      CTP_PARA_RESOLUTION=1,
      CTP_PARA_THRESHOLD=2,
      CTP_PARA_REPORT_INTVAL=4,
      CTP_PARA_IDLE_INTVAL=8,
      CTP_PARA_SLEEP_INTVAL=0x10,
      CTP_PARA_END
} CTP_parameters_enum;

typedef struct
{
	kal_uint16 resolution; // CTP_RESOLTION, 
	kal_uint16 threshold; //  CTP_THRESHOLD, 
	kal_uint16 Report_interval;
	kal_uint16 Idle_time_interval;
	kal_uint16 sleep_time_interval;
	kal_uint16 gesture_active_distance;
	kal_uint16 MS_calibration[128];
}CTP_parameters_struct;// ctp_get_set_enum 

typedef struct
{   
   char	vendor[8];
   char	product[8];
   char	FirmwareVersion[8];
}CTP_custom_information_struct;

typedef enum {
	CTP_ACTIVE_MODE,
	CTP_IDLE_MODE,
	CTP_SLEEP_MODE,
	CTP_GESTURE_DETECTION_MODE,
	CTP_MULTIPLE_POINT_MODE,
	CTP_FIRMWARE_UPDATE,
	CTP_FM_ENABLE,
	CTP_FM_DISABLE
}ctp_device_mode_enum;

typedef struct{
	kal_bool (*ctp_init)(void);
	kal_bool (*ctp_set_device_mode)(ctp_device_mode_enum);
	Touch_Panel_PenState_enum (*ctp_hisr)(void); 
	kal_bool (*ctp_get_data)(TouchPanelMultipleEventStruct *);
	kal_bool (*ctp_parameters)(CTP_parameters_struct *, kal_uint32, kal_uint32);
	void (*ctp_power_on)(kal_bool);
	kal_uint32 (*ctp_command)(kal_uint32, void *, void *);
}CTP_customize_function_struct;

/********************Function Declaration********************/
/********************For upper layer*************************/
void Touch_Panel_Ctrl_Param(DCL_CTRL_CUSTOM_PARAM_T param);
void Touch_Panel_Ctrl_Param_Range(DCL_CTRL_CUSTOM_PARAM_RANGE_T param);
void Touch_Panel_MicronMeter_To_Coord(DCL_CTRL_MICRONMETER_COORD_T* pparam);
void Touch_Panel_Coord_To_MicronMeter(DCL_CTRL_MICRONMETER_COORD_T* pparam ); 


void touch_panel_enable_(kal_bool enable);/*enable/disable touch panel*/
kal_bool touch_panel_get_event_(TouchPanelMultipleEventStruct *touch_data);/*get touch event*/
void touch_panle_conf_timeout_period_(kal_uint32 longtap, 
                                     kal_uint32 repeat,
                                     kal_uint32 handwriting_longtap);
void touch_panle_conf_sample_period_(kal_uint32 low, kal_uint32 high);
void touch_panel_flush_(void);/*flsuh data in ring buffer*/
void touch_panel_start_cali_(TouchPanelCoordStruct *point, kal_uint16 num);
void touch_panel_stop_cali_(void);
void touch_panel_read_cali_(TouchPanelCaliStruct *cali);
void touch_panel_set_cali_(TouchPanelCaliStruct cali);
void touch_panel_reset_(kal_bool skip_unrelease_enable);
void touch_panel_reset_handwriting_(void);
void touch_panel_conf_move_offset_(kal_uint16 pen_offset, kal_uint16 stroke_offset, 
                                  kal_uint16 longtap_pen_offset,
                                  kal_uint16 longtap_stroke_offset);
void touch_panel_conf_handwriting_(TouchPanelHandAreaStruct *area, kal_uint16 n, 
                              TouchPanelHandAreaStruct  *ext_area);
void touch_panel_cb_registration_ (TP_EVENT_FUNC function, void *parameter);
void Touch_Panel_Pixel_To_MicronMeter(DCL_CTRL_MICRONMETER_COORD_T* pparam);
void Touch_Panel_MicronMeter_To_Coord(DCL_CTRL_MICRONMETER_COORD_T* pparam);
#if defined(__TOUCH_PANEL_CAPACITY__)
void touch_panel_capacitive_up_hdr(DCL_EVENT event);
void touch_panel_capacitive_down_hdr(DCL_EVENT event);
void touch_panel_capacitive_power_on(kal_bool on);
kal_bool touch_panel_capacitive_set_device(ctp_device_mode_enum mode);
kal_uint32 touch_panel_capacitive_command(kal_uint32 cmd, void *p1, void*p2);
#endif //#if defined(__TOUCH_PANEL_CAPACITY__)
/********************For touch panel driver only*************/
// MoDIS parser skip start
// The following are private APIs
#ifdef TOUCH_PANEL_PRESSURE
kal_bool tp_level(void);
kal_bool tp_level_pressure(kal_uint32 *pressure);
kal_uint32 tp_pressure_value(void);
kal_bool tp_pressure_check(void);
kal_bool tp_pressure_check_value(kal_uint32 *pressure);
#endif //#ifdef TOUCH_PANEL_PRESSURE

void touch_panel_read_adc(kal_uint16 *x, kal_uint16 *y);
kal_bool touch_panel_adc_to_coordinate(kal_uint16 *x, kal_uint16 *y);/*tranlate*/
void touch_panel_event_cb(void *parameter);
void touch_panel_repeat_cb(void *parameter);
void touch_panel_longtap_cb(void *parameter);
void touch_panel_stroke_cb(void *parameter);
void touch_panel_up_hdr(DCL_EVENT event);
void touch_panel_down_hdr(DCL_EVENT event);
void touch_panel_event_hdr(void);
void touch_start_longtap(void);
void touch_panel_stroke_hdr(void);
void touch_excute_cali(kal_uint16 x_adc, kal_uint16 y_adc);
void touch_panel_sendilm(void *para, Touch_Panel_Event_enum state);
void tp_data_pop(Touch_Panel_Event_enum event, kal_int16 x, kal_int16 y);
void tp_data_push(TP_SINGLE_EVENT_T* push_event);

void touch_panel_init(void);
void touch_start_handwriting_longtap(void);
// MoDIS parser skip end
/*variable*/
extern TouchPanelDataStruct TP;
extern Touch_Panel_Event_enum touch_panel_track_stauts; /*pen/stroke status*/
extern TouchPanelBufferStruct    touch_panel_data_buffer;
extern TouchPanelCoordStruct pre_coord;
extern TouchPanelCoordStruct tp_stroke_pre;

#if defined(__DRV_COMM_REG_DBG__) && defined(__DRV_TP_REG_DBG__)
#define DRV_TP_WriteReg(addr,data)              DRV_DBG_WriteReg(addr,data)
#define DRV_TP_Reg(addr)                        DRV_DBG_Reg(addr)                      
#define DRV_TP_WriteReg32(addr,data)            DRV_DBG_WriteReg32(addr,data)          
#define DRV_TP_Reg32(addr)                      DRV_DBG_Reg32(addr)                    
#define DRV_TP_WriteReg8(addr,data)             DRV_DBG_WriteReg8(addr,data)           
#define DRV_TP_Reg8(addr)                       DRV_DBG_Reg8(addr)                     
#define DRV_TP_ClearBits(addr,data)             DRV_DBG_ClearBits(addr,data)           
#define DRV_TP_SetBits(addr,data)               DRV_DBG_SetBits(addr,data)             
#define DRV_TP_SetData(addr, bitmask, value)    DRV_DBG_SetData(addr, bitmask, value)  
#define DRV_TP_ClearBits32(addr,data)           DRV_DBG_ClearBits32(addr,data)         
#define DRV_TP_SetBits32(addr,data)             DRV_DBG_SetBits32(addr,data)           
#define DRV_TP_SetData32(addr, bitmask, value)  DRV_DBG_SetData32(addr, bitmask, value)
#define DRV_TP_ClearBits8(addr,data)            DRV_DBG_ClearBits8(addr,data)          
#define DRV_TP_SetBits8(addr,data)              DRV_DBG_SetBits8(addr,data)            
#define DRV_TP_SetData8(addr, bitmask, value)   DRV_DBG_SetData8(addr, bitmask, value) 
#else
#define DRV_TP_WriteReg(addr,data)              DRV_WriteReg(addr,data)
#define DRV_TP_Reg(addr)                        DRV_Reg(addr)                      
#define DRV_TP_WriteReg32(addr,data)            DRV_WriteReg32(addr,data)          
#define DRV_TP_Reg32(addr)                      DRV_Reg32(addr)                    
#define DRV_TP_WriteReg8(addr,data)             DRV_WriteReg8(addr,data)           
#define DRV_TP_Reg8(addr)                       DRV_Reg8(addr)                     
#define DRV_TP_ClearBits(addr,data)             DRV_ClearBits(addr,data)           
#define DRV_TP_SetBits(addr,data)               DRV_SetBits(addr,data)             
#define DRV_TP_SetData(addr, bitmask, value)    DRV_SetData(addr, bitmask, value)  
#define DRV_TP_ClearBits32(addr,data)           DRV_ClearBits32(addr,data)         
#define DRV_TP_SetBits32(addr,data)             DRV_SetBits32(addr,data)           
#define DRV_TP_SetData32(addr, bitmask, value)  DRV_SetData32(addr, bitmask, value)
#define DRV_TP_ClearBits8(addr,data)            DRV_ClearBits8(addr,data)          
#define DRV_TP_SetBits8(addr,data)              DRV_SetBits8(addr,data)            
#define DRV_TP_SetData8(addr, bitmask, value)   DRV_SetData8(addr, bitmask, value) 
#endif //#if defined(__DRV_COMM_REG_DBG__) && defined(__DRV_TP_REG_DBG__)
#if defined(__MTK_INTERNAL__) && !defined(LOW_COST_SUPPORT) && !defined(__MAUI_BASIC__) && defined(__DRV_DBG_MEMORY_TRACE_SUPPORT__) && defined(__DRV_TP_MEMORY_TRACE__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else //#if defined(__MTK_INTERNAL__) && !defined(LOW_COST_SUPPORT)
#define TP_DBG(a,b,c,d) ;
#endif //#if defined(__MTK_INTERNAL__) && !defined(LOW_COST_SUPPORT)
#endif

