#include "dcl_hts.h"
#include "ts_hw.h"
#include "touch_panel_.h"

//this variable is to record touch_panel debounce time of custom setting
#if defined(DRV_TOUCH_PANEL_CUSTOMER_PARAMETER)
kal_uint32   TS_DEBOUNCE_TIME;
#endif //#if defined(DRV_TOUCH_PANEL_CUSTOMER_PARAMETER)

#if defined(DRV_ADC_TOUCH_SCREEN) && !defined(DRV_HTS_OFF)
//#define DCL_HTS_MAGIC_NUM  0x40000000 /* Defined in dcl_ts.h  */
#define DCL_HTS_IS_HANDLE_MAGIC(handle_) ((handle_)& DCL_HTS_MAGIC_NUM)
#define DCL_HTS_GET_DEV(handle_) ((handle_) & (~DCL_HTS_MAGIC_NUM))

//whether touch panel driver is open or init.
static kal_bool fgHTSInit = KAL_FALSE;
//static kal_bool fgHTSOpen = KAL_FALSE;

PFN_DCL_CALLBACK DclHTS_DownHandler_cb;
PFN_DCL_CALLBACK DclHTS_UpHandler_cb;

DCL_STATUS DclHTS_Close(DCL_HANDLE handle)
{
   return STATUS_OK;
}



DCL_STATUS DclHTS_Control(DCL_HANDLE handle, HTS_CMD cmd, HTS_CTRL_DATA_T *data)
{
   HTS_DEV  eDev;

   if (!DCL_HTS_IS_HANDLE_MAGIC(handle))
   {
      ASSERT(0);
      return STATUS_INVALID_DCL_HANDLE;
   }
   eDev = DCL_HTS_GET_DEV(handle);
   switch(eDev)
   	{
   	   case TOUCH_PANEL_R:
	   	{
			extern kal_bool tp_level(void);
			extern kal_bool tp_level_pressure(kal_uint32 *pressure);
			extern void TPUpdateNotify(void);
			extern void tp_read_adc(kal_uint16 *x, kal_uint16 *y);
			extern kal_uint16  ts_read_adc(kal_uint16 pos, kal_bool IsPressure);
			extern void tp_set_cmd_para(kal_uint32 sr, kal_uint32 ms);
			#ifdef TOUCH_PANEL_PRESSURE
   			extern kal_bool tp_pressure_check(void);
   			extern kal_uint32 tp_pressure_value(void);
			#endif
				
			switch(cmd)
			{
			    //kal_bool tp_level(void)
				case HTS_CMD_GET_TP_LEVEL:
				  {
					 HTS_CTRL_TL_T  *prCtrlTL;  
      				 prCtrlTL = &(data->rTSCtrlTL);
      				 prCtrlTL->fgIsUP = tp_level();
				  }
				  break;
				//kal_bool tp_level_pressure(kal_uint32 *pressure)
				case HTS_CMD_GET_TP_LEVEL_PRESSURE:
				  {
				  	 HTS_CTRL_TL_T  *prCtrlTL;  
      				 prCtrlTL = &(data->rTSCtrlTL);
					 prCtrlTL->fgIsUP =tp_level_pressure((kal_uint32 *)&(prCtrlTL->pressure_value));
				  }
				  break;
				//void TPUpdateNotify(void)
				case HTS_CMD_TP_UPDATENOTIFY:	
				  {
				  	TPUpdateNotify();
				  }
				  break;
				//void tp_read_adc(kal_uint16 *x, kal_uint16 *y)
				case HTS_CMD_GET_TP_ADC:
				  {
				  	HTS_CTRL_TPRA_T  *prCtrlTPRA;  
			        prCtrlTPRA = &(data->rTSCtrlTPRA);
      				tp_read_adc((kal_uint16 *)(prCtrlTPRA->pi2x), (kal_uint16 *)(prCtrlTPRA->pi2y) );
				  }
				  break;
		#ifdef TOUCH_PANEL_PRESSURE
				//extern kal_bool tp_pressure_check(void);
				case HTS_CMD_GET_TP_PRESSURE:
				  {
				  	 HTS_CTRL_TPP_T  *prCtrlTPP;  
      				 prCtrlTPP = &(data->rTSCtrlTPP);
      				 prCtrlTPP->fgIsPressed = tp_pressure_check();
				  }
					break;
				//extern kal_uint32 tp_pressure_value(void);	
				case HTS_CMD_TP_PRESSURE_VALUE:
				 {
				 	HTS_CTRL_TPPV_T  *prCtrlTPPV;  
				    prCtrlTPPV = &(data->rTSCtrlTPPV);
      				prCtrlTPPV->fgPressureValue = tp_pressure_value();
				 }
					break;
		#endif			
				case HTS_CMD_TS_READ_ADC:
				 {
				 	HTS_CTRL_TSRA_T  *prCtrlTSRA;  
 			        prCtrlTSRA = &(data->rTSCtrlTSRA);  	  
 			        switch(prCtrlTSRA->uCoord)
 			        {
	 			        case 	TS_COORD_HTS_ADDR_Y:
	 			         prCtrlTSRA->i2AdcValue = ts_read_adc(TS_CMD_ADDR_Y, KAL_TRUE);
	 			         break;
	 			        case 	TS_COORD_HTS_ADDR_Z1:
	 			         prCtrlTSRA->i2AdcValue = ts_read_adc(TS_CMD_ADDR_Z1,KAL_TRUE);
	 			         break;
	 			        case 	TS_COORD_HTS_ADDR_Z2:
	 			         prCtrlTSRA->i2AdcValue = ts_read_adc(TS_CMD_ADDR_Z2,KAL_TRUE);
	 			         break;
	 			        case 	TS_COORD_HTS_ADDR_X:
	 			         prCtrlTSRA->i2AdcValue = ts_read_adc(TS_CMD_ADDR_X, KAL_TRUE);
	 			         break;
	 			        default:
	 			         return STATUS_FAIL;
 			        }   	
				 }
					break;
				//this is for C-type multi read.
				case HTS_CMD_GET_TP_POINT:
					break;
				case HTS_CMD_GET_TP_POINT_NUM:
					break;
				
				case HTS_CMD_GET_TP_TYPE:
					break;
				//we don't do calibrition in hardware layer ,so this is no use.
				case HTS_CMD_SET_CALI_VALUE:
					break;
				case HTS_CMD_GET_CALI_VALUE:
					break;
			case 	HTS_CMD_SET_DEBOUNCE_TIME:
                                    {
                                             HTS_CTRL_DT_T* pData;
                                             pData = &(data->rTSCtrlDebouncetime);
                                             TS_DEBOUNCE_TIME = pData->u4DebounceTime;
                                              DRV_TP_WriteReg(AUX_TS_DEBT, TS_DEBOUNCE_TIME);
                                    }
                                break;
	                    case HTS_CMD_GET_DEBOUNCE_TIME:
                                {
                                    HTS_CTRL_DT_T* pData;
                                    pData = &(data->rTSCtrlDebouncetime);
                                    pData->u4DebounceTime = TS_DEBOUNCE_TIME;
                                    
                                }
                            break;
				//for expore all hardware funciton, we should add command to set all register.
				case HTS_CMD_SET_CONFIG:
				  {
				  	DCL_INT32	  u4sr;
 					DCL_INT32	  u4ms;
					HTS_CTRL_CONFIG_T  *prTSCtrlConfig;
					prTSCtrlConfig =&(data->rTSCtrlConfig);
					switch(prTSCtrlConfig->u4SampleResolution)
					{
					case DCL_TS_CMD_DIFFERENTIAL:
					   u4sr = TS_CMD_DIFFERENTIAL;
					   break;
					case DCL_TS_CMD_SINGLE_END:
					   u4sr = TS_CMD_SINGLE_END;
					   break;
					default:
					   ASSERT(0);
					   return STATUS_INVALID_CONFIGURATION;
					}
					switch(prTSCtrlConfig->u4ModeSelection)
					{
					case DCL_TS_CMD_MODE_10BIT:
					   u4ms = TS_CMD_MODE_10BIT;
					   break;
					case DCL_TS_CMD_MODE_8BIT:
					   u4ms = TS_CMD_MODE_8BIT;
					   break;
					default:
					   ASSERT(0);
					   return STATUS_INVALID_CONFIGURATION;
					}
					tp_set_cmd_para(u4sr,u4ms);
				  }
				  break;
				case HTS_CMD_SET_SPL_NUM:
					{
						HTS_CTRL_SN_T* pData;
						if(AUX_SPL_NUM == 0)
							break;
						pData = &(data->rTSCtrlSPLNum);
						pData->u4SPLNum = (pData->u4SPLNum<<AUX_SPL_NUM_SHIFT) | (DRV_TP_Reg(AUX_SPL_NUM)&(~AUX_SPL_NUM_MASK));
						DRV_TP_WriteReg(AUX_SPL_NUM, pData->u4SPLNum);
					}
					break;
				case HTS_CMD_GET_SPL_NUM:
					{
						HTS_CTRL_SN_T* pData;
						if(AUX_SPL_NUM == 0)
							break;
						pData = &(data->rTSCtrlSPLNum);
						pData->u4SPLNum = (DRV_TP_Reg(AUX_SPL_NUM)&AUX_SPL_NUM_MASK)>>AUX_SPL_NUM_SHIFT;
					}
					break;
				default:
					ASSERT(0);
					return STATUS_INVALID_DCL_HANDLE;
			}
		}
	   break;
	   default:
	   	  ASSERT(0);
      	  return STATUS_INVALID_DCL_HANDLE;
	   	
   	}
   return STATUS_OK;
   
}

DCL_STATUS DclHTS_Initialize(void)
{
	extern void ts_drv_init(void);
	extern TouchPanel_customize_function_struct *tp_GetFunc(void);
	//get customlize parameter.
	TouchPanel_customize_function_struct * htp_fun_ptr;
 	TouchPanel_custom_data_struct *tp_data;
	
    htp_fun_ptr=tp_GetFunc();
    tp_data = htp_fun_ptr->tp_get_data(); 
	#if defined(DRV_TOUCH_PANEL_CUSTOMER_PARAMETER)  
		
	   		TS_DEBOUNCE_TIME = tp_data->ts_debounce_time;

     if(TS_DEBOUNCE_TIME > 0x3FFF)//HW register upper bound.
        TS_DEBOUNCE_TIME = 0x3FFF;
   #endif //#if defined(DRV_TOUCH_PANEL_CUSTOMER_PARAMETER)

   if(fgHTSInit == KAL_FALSE) 
   {
      ts_drv_init();
      fgHTSInit = KAL_TRUE;
   }
   return STATUS_OK;
}

DCL_HANDLE DclHTS_Open(HTS_DEV dev, DCL_FLAGS flags)
{
   if(dev != TOUCH_PANEL_R )
	   {
	      return DCL_HANDLE_INVALID;
	   }
   else
	   {
		  return (DCL_HANDLE)DCL_HTS_MAGIC_NUM|TOUCH_PANEL_R;
	   }
}

DCL_STATUS DclHTS_RegisterCallback(DCL_HANDLE handle, HTS_EVENT event, PFN_DCL_CALLBACK callback)
{
   HTS_DEV  eDev;
//check if handle is valid
   if (!DCL_HTS_IS_HANDLE_MAGIC(handle))
   {
      ASSERT(0);
      return STATUS_INVALID_DCL_HANDLE;
   }
   eDev = DCL_HTS_GET_DEV(handle);
//check valid done.

//register callback function according to touch panel type and event.
   switch(eDev)
   {
   	case TOUCH_PANEL_R:
	 {


		if(event == DCL_EVENT_HTS_PEN_DOWN)
          {
              DclHTS_DownHandler_cb = callback;
          }
        else if(event == DCL_EVENT_HTS_PEN_UP)
          {
             DclHTS_UpHandler_cb = callback;
          }
        else
          {
			 ASSERT(0);
			 return STATUS_FAIL;
          }  
   	}	
	break;
   default:
      ASSERT(0);
      return STATUS_INVALID_DCL_HANDLE;
   }
//register callback function done.   
   return STATUS_OK;
}
#else
DCL_HANDLE DclHTS_Open(HTS_DEV dev, DCL_FLAGS flags)
{
    return STATUS_UNSUPPORTED;
}
DCL_STATUS DclHTS_RegisterCallback(DCL_HANDLE handle, HTS_EVENT event, PFN_DCL_CALLBACK callback)
{
   return STATUS_UNSUPPORTED;
}
DCL_STATUS DclHTS_Control(DCL_HANDLE handle, HTS_CMD cmd, HTS_CTRL_DATA_T *data)
{
	  return STATUS_UNSUPPORTED;
}
DCL_STATUS DclHTS_Close(DCL_HANDLE handle)
{
   return STATUS_UNSUPPORTED;
}
#endif























