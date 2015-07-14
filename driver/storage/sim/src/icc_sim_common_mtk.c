#ifndef DRV_SIM_OFF
#include "kal_public_api.h"
#include "drv_comm.h"
#ifdef __SIM_DRV_MULTI_DRV_ARCH__
#include "dma_sw.h"
#include 	"intrCtrl.h"
#include    "sim_reg_adp.h"

#include "sim_hw.h"
#include "sim_al.h"
#include "sim_sw_comm.h"
#include "multi_icc_custom.h"
#include "dcl.h"
#if defined (LPWR_SLIM)
#include "drvpdn.h"
#include "l1sm_public.h"
#endif
#include "sim_drv_trc.h"

#include "kal_debug.h"

#if defined(__SIM_HOT_SWAP_POLL_TIMER__) && defined(__SIM_HOT_SWAP_SUPPORT__)
#include "sim_public_enum.h"
extern void sim_hot_swap_poll_timer_set(kal_uint32 which_sim);
#endif

#ifdef __CLKG_DEFINE__
#if (defined(DRVPDN_CON1) || defined(DRVPDN_CON0))
#error "__CLKG_DEFINE__ & DRVPDN_CON1 are all defined"
#else /*(defined(DRVPDN_CON1) || defined(DRVPDN_CON0))*/

#ifdef SIM_PDN_REG_VERSION_3
#define DRVPDN_CON1		CG_CON0
#else /*SIM_PDN_REG_VERSION_3*/
#define DRVPDN_CON1		CG_CON1
#endif /*SIM_PDN_REG_VERSION_3*/

#ifdef SIM_PDN_REG_VERSION_3
/*MT6516 E2 has SIM2 PDN bit on MD side, we have to access CG_CON0 directly*/
#define DRVPDN_CON0		CG_CON0
#else /*SIM_PDN_REG_VERSION_3*/
#define DRVPDN_CON0		CG_CON0
#endif /*SIM_PDN_REG_VERSION_3*/

#endif /*(defined(DRVPDN_CON1) || defined(DRVPDN_CON0))*/

#if (defined(DRVPDN_CON1_SIM) || defined(DRVPDN_CON0_SIM2))
#error "__CLKG_DEFINE__ & DRVPDN_CON1_SIM are all defined"
#else /*(defined(DRVPDN_CON1_SIM) || defined(DRVPDN_CON0_SIM2))*/


#ifdef SIM_PDN_REG_VERSION_3
#define DRVPDN_CON1_SIM	CG_CON0_SIM
#else /*SIM_PDN_REG_VERSION_3*/
#define DRVPDN_CON1_SIM	CG_CON1_SIM
#endif /*SIM_PDN_REG_VERSION_3*/

#ifdef SIM_PDN_REG_VERSION_3
/*MT6516 E2 has SIM2 PDN bit on MD side, we have to access this bit*/
#define DRVPDN_CON0_SIM2	CG_CON0_SIM2
#else /*SIM_PDN_REG_VERSION_3*/
#define DRVPDN_CON0_SIM2	CG_CON0_SIM2
#endif /*SIM_PDN_REG_VERSION_3*/


#endif /*(defined(DRVPDN_CON1_SIM) || defined(DRVPDN_CON0_SIM2))*/
#endif /*__CLKG_DEFINE__*/



static Sim_Card SimCard_cb[DRV_SIM_MAX_LOGICAL_INTERFACE];
static usim_dcb_struct usim_cb[DRV_SIM_MAX_LOGICAL_INTERFACE];
kal_char sim_dbg_str[200];
sim_HW_cb	simHWCbArray[DRV_SIM_MAX_LOGICAL_INTERFACE];
sim_PMIC_HW_cb	simPMICHWCbArray[DRV_SIM_MAX_LOGICAL_INTERFACE];
extern kal_uint32	hwCbArray[];
extern sim_ctrlDriver sim_ctrlDriver_MT6302, sim_ctrlDriver_MTK, sim_ctrlDriver_Single, sim_ctrlDriver_MT6306, sim_ctrlDriver_AW6314;
extern sim_ctrlDriver *sim_driverTable[];
kal_uint32	sim_mtkIf2Logical[SIM_DRV_MTK_INTERFACE_NUM];
extern kal_bool	sim_physicalSlotChanged;
kal_uint32 SIM_drv_ts_INT, SIM_drv_ts_GPT, SIM_drv_ts_ASSERT, SIM_drv_ts_deact;

/*PMU related*/
DCL_HANDLE simPmuHandle;

#ifdef SIM_CACHED_SUPPORT
__attribute__ ((section ("NONCACHEDZI"))) kal_uint32	sim_uncachedTxBuffer0[128];
__attribute__ ((section ("NONCACHEDZI"))) kal_uint32	sim_uncachedRxBuffer0[128];
__attribute__ ((section ("NONCACHEDZI"))) kal_uint32	sim_uncachedTxBuffer1[128];
__attribute__ ((section ("NONCACHEDZI"))) kal_uint32	sim_uncachedRxBuffer1[128];
__attribute__ ((section ("NONCACHEDZI"))) kal_uint8		uncachedDmaBuffer0[260];
__attribute__ ((section ("NONCACHEDZI"))) kal_uint8		uncachedDmaBuffer1[260];


#endif

#ifdef SIM_REMOVE_ATR_ASSERT
#define SIM_FATAL_ERROR_REPORT_PERIOD	1000 /*uint is 10ms*/

typedef struct{
	sim_HW_cb *hw_cb;
	kal_uint32 gptHandle;
} sim_fatalErrorReport;

sim_fatalErrorReport sim_fatalReportArray[DRV_SIM_MAX_LOGICAL_INTERFACE];
#endif

extern kal_uint32 sim_get_logicalNum_from_app(SIM_ICC_APPLICATION application);
extern void sim_MT6306_init(void);
extern void sim_AW6314_init(void);

/*
	functions here are those the same in single SIM, MT6302 and dual controller solutiions.
	I put them in the same place so that we won't have multiply defined error.
	We should not use solution option here and should do the same thing in different solutions.
*/

#ifdef __SIM_HOT_SWAP_SUPPORT__
void SIM_RegHotPlugCb(SIM_ICC_APPLICATION application, 
                      DCL_SIM_PLUG_IN_CALLBACK hotPlugInCb, 
                      DCL_SIM_PLUG_OUT_CALLBACK hotPlugOutCb)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
   /* register sim task hot plug call back function to customer files */
   if(sim_physicalSlotChanged == KAL_TRUE)
   {
      application = 1-application; // need to switch to get correct hwcb and SIMIF number
   }
   sim_reg_hot_plug_cb(application, hotPlugInCb, hotPlugOutCb);
}
#ifdef SIM_HOT_SWAP_V2
void SIM_PlugEvent_Cb(SIM_ICC_APPLICATION app)
{
	Sim_Card *SimCard;
	sim_HW_cb *hw_cb;
        usim_dcb_struct *usim_dcb;

   if(sim_physicalSlotChanged == KAL_TRUE)
   {
      app = 1-app; // need to switch to get correct hwcb and SIMIF number
   }
	/*logical SIM 1 not exactly work on physical SIM1 interface, we only know interrrupt comes from SIM1, have to find its logical */
	hw_cb = (sim_HW_cb *)(hwCbArray[sim_get_logical_from_SIMIF(app)]);
	SimCard = GET_SIM_CB(hw_cb->simInterface);
        usim_dcb = GET_USIM_CB(hw_cb->simInterface);

	if (SimCard->sim_nullByteIssueGPT != NULL)
	{
		/* Stop gpt timer for null byte */
		SimCard->sim_nullByteIssueNullCount = 0;
		DRV_ICC_GPTI_StopItem(SimCard->sim_nullByteIssueGPT);
		/*must change magic after we confirm GPT won't trigger, since this code run in task context, we can run this code means GPT won't trigger*/
		SimCard->simMagic1 ++;
		SimCard->simMagic2 = SimCard->simMagic1;
	}

   /* State maybe at 1. power off state */
	if((SimCard->State == SIM_PROCESSCMD) && (SimCard->EvtFlag == SIM_EVT_CMD_END))
	{
		/* Stop CMD timer */
	   USIM_DISABLE_TOUT();
		SimCard->timeout = KAL_TRUE;
                usim_dcb->present = KAL_FALSE;
		SIM_SetEvent_MTK(SimCard,SIM_NULLTIMEOUT,hw_cb);
           USIM_SET_EVENT_Multiple(usim_dcb);
	   DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC64, app, SimCard->simMagic2, drv_get_current_time(),SimCard->State,SimCard->EvtFlag);	
   }
}
#endif
#endif

#if defined(__SIM_HOT_SWAP_POLL_TIMER__) && defined(__SIM_HOT_SWAP_SUPPORT__)
void SIM_PlugEvent_Poll_Timer_Cb(SIM_ICC_APPLICATION app)
{
	Sim_Card *SimCard;
	sim_HW_cb *hw_cb;
	usim_dcb_struct *usim_dcb;

	if(sim_physicalSlotChanged == KAL_TRUE)
	{
		hw_cb = (sim_HW_cb *)(hwCbArray[sim_get_logical_from_SIMIF(app-1)]);
	} else
	{
		hw_cb = (sim_HW_cb *)(hwCbArray[sim_get_logical_from_SIMIF(app)]);
	}
	// logical SIM 1 not exactly work on physical SIM1 interface, we only know interrrupt comes from SIM1, have to find its logical
	SimCard = GET_SIM_CB(hw_cb->simInterface);
	usim_dcb = GET_USIM_CB(hw_cb->simInterface);

	SimCard->poll_sim_2s = KAL_TRUE;
	usim_dcb->poll_sim_2s = KAL_TRUE;
	sim_hot_swap_poll_timer_set(app);
#if	!defined( __MAUI_BASIC__)
       tst_sys_trace("[SIM DRV]start timer\n\r");
#else
	   dbg_print("[SIM DRV]start timer\n\r");
#endif

	return;
}
#endif

void DRV_ICC_print(sim_printEnum messageType, kal_uint32 value1, kal_uint32 value2, kal_uint32 value3, kal_uint32 value4, kal_uint32 value5)
{
	kal_sprintf(sim_dbg_str,"[SIM_DRV] %d : %x, %x, %x, %x, %x",messageType, value1, value2, value3, value4, value5);
#if	!defined( __MAUI_BASIC__)
    tst_sys_trace(sim_dbg_str);
#else
    dbg_print(sim_dbg_str);
#endif	
}

#ifdef SIM_TOUT_REG_V2
#ifdef SIM_TOUT_REG_V3
void SIM_SetTOUT(kal_uint32 TOUT, sim_HW_cb *hw_cb)    
{
   SIM_ClearBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_CONF_TOUTEN);
   if (TOUT < 0xffffff)
   	SIM_WriteReg32((SIM0_BASE_ADDR_MTK + SIM_TOUT_MTK), ((TOUT)/4));
   else
   	SIM_WriteReg32((SIM0_BASE_ADDR_MTK + SIM_TOUT_MTK), 0xffffff);
   SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_STS_MTK);
   SIM_SetBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_CONF_TOUTEN);
}
#else
void SIM_SetTOUT(kal_uint32 TOUT, sim_HW_cb *hw_cb)    
{
   SIM_ClearBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_CONF_TOUTEN);
   if (TOUT < 0xffffff)
   	SIM_WriteReg32((SIM0_BASE_ADDR_MTK + SIM_TOUT_MTK), TOUT);
   else
   	SIM_WriteReg32((SIM0_BASE_ADDR_MTK + SIM_TOUT_MTK), 0xffffff);
   SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_STS_MTK);
   SIM_SetBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_CONF_TOUTEN);
}
#endif
#else
void SIM_SetTOUT(kal_uint32 TOUT, sim_HW_cb *hw_cb)    
{
   SIM_ClearBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_CONF_TOUTEN);
   if (TOUT < 0xffff)
   	SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_TOUT_MTK), TOUT);
   else
   	SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_TOUT_MTK), 0xffff);
   SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_STS_MTK);
   SIM_SetBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_CONF_TOUTEN);
}
#endif

void SIM_SetRXRetry(sim_HW_cb *hw_cb, kal_uint16 RXRetry)
{
	kal_uint16 Retry;
	Retry = SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_RETRY_MTK);
	Retry &= ~SIM_RETRY_RXMASK;
	Retry |= RXRetry;
	SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_RETRY_MTK), Retry);
}

void SIM_SetTXRetry(sim_HW_cb *hw_cb, kal_uint16 TXRetry) 
{
	kal_uint16 	Retry;
	Retry = SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_RETRY_MTK);
	Retry &= ~SIM_RETRY_TXMASK;
	Retry |= (TXRetry<<8);
	SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_RETRY_MTK), Retry);
}

#ifdef SIM_REMOVE_ATR_ASSERT
void SIM_fatalErrorReporter(void *param)
{
    extern kal_bool DRV_ICC_GPTI_StartItem(kal_uint32 handle,kal_uint16 tick,void (*gptimer_func)(void *),void *parameter);
	sim_fatalErrorReport *report;
	report = param;

	kal_sprintf(sim_dbg_str,"[SIM]:sim fatal error on interface %d, this card is broken",report->hw_cb->simInterface);
#if	!defined( __MAUI_BASIC__)
       tst_sys_trace(sim_dbg_str);
#else
	   dbg_print(sim_dbg_str);
#endif
	DRV_ICC_GPTI_StartItem(report->gptHandle, SIM_FATAL_ERROR_REPORT_PERIOD, SIM_fatalErrorReporter, report);
}

void SIM_StartFaltalReport(sim_HW_cb *hw_cb)
{
    extern kal_bool DRV_ICC_GPTI_StartItem(kal_uint32 handle,kal_uint16 tick,void (*gptimer_func)(void *),void *parameter);
    extern void DRV_ICC_GPTI_StopItem(kal_uint32 handle);
	sim_fatalErrorReport *report;
	kal_uint32	gptHandle;
	Sim_Card *SimCard;

	SimCard = GET_SIM_CB(hw_cb->simInterface);

	SimCard->keepAtrFatal = KAL_TRUE;
#ifndef __MAUI_BASIC__   
#if !defined(__L1_STANDALONE__)
	drv_trace8(TRACE_GROUP_4, SIM_GEMINI_GEN1, 4, __LINE__,
		SimCard->keepAtrFatal , SimCard->State, 0, 0,
		0, 0);
#endif
#endif
	/*
		We trigger a gpt timer to alarm this error periodically. Since this SIM card is abnormal and GPT for null-byte
		will not be used, we can use it.
	*/
	report = &sim_fatalReportArray[hw_cb->simInterface];
	gptHandle = SimCard->sim_nullByteIssueGPT;

	DRV_ICC_GPTI_StopItem(gptHandle);
	report->gptHandle = gptHandle;
	report->hw_cb = hw_cb;
	DRV_ICC_GPTI_StartItem(report->gptHandle, SIM_FATAL_ERROR_REPORT_PERIOD, SIM_fatalErrorReporter, report);

	return;
}
#endif

kal_uint32 SIM_GetCurrentTime(void)
{
   return drv_get_current_time();
#if 0
#ifdef DRV_MISC_TDMA_L1_MACRO
/* under construction !*/
#else
/* under construction !*/
#endif
#endif
}
#ifdef NO_SLIM_DEF
kal_uint32 SIM_GetDurationTick(kal_uint32 previous_time, kal_uint32 current_time)
{
	return drv_get_duration_tick(previous_time, current_time);
}
#endif
void SIM_SetRXTIDE(kal_uint16 RXTIDE, sim_HW_cb *hw_cb)
{
	kal_uint16 TIDE;
	TIDE = SIM_Reg((SIM0_BASE_ADDR_MTK + SIM_TIDE_MTK));
	TIDE &= ~SIM_TIDE_RXMASK;
	TIDE |= (RXTIDE-1);
	SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_TIDE_MTK),TIDE);
}

void SIM_SetTXTIDE(kal_uint16 _TXTIDE, sim_HW_cb *hw_cb)
{
	kal_uint16 TIDE;
	TIDE = SIM_Reg((SIM0_BASE_ADDR_MTK + SIM_TIDE_MTK));
	TIDE &= ~SIM_TIDE_TXMASK;
	TIDE |= ((_TXTIDE+1) <<8);
	SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_TIDE_MTK),TIDE);
}

#ifdef NO_SLIM_DEF
/*
* FUNCTION
*	L1sim_Enable_Enhanced_Speed
*
* DESCRIPTION
*   	The function must call before L1sim_Reset. Otherwise, enhance speed is disable.
*     This function can enable enhance speed mode or not.
*
* CALLS
*
* PARAMETERS
*	enable: KAL_TRUE: enable enhanced speed. KAL_FALSE: disable it.
*
* RETURNS
*	NULL
*
* GLOBALS AFFECTED
*   external_global
*/
void L1sim_Enable_Enhanced_Speed(kal_bool enable, sim_HW_cb *hw_cb)
{
	Sim_Card *SimCard;

	SimCard = GET_SIM_CB(hw_cb->simInterface);

   SimCard->PTS_check = enable;
}
#endif
/*
* FUNCTION
*	L1sim_Cmd
*
* DESCRIPTION
*   	The function is used to implement re-try command mechanism.
*
* CALLS
*
* PARAMETERS
*	txData: Pointer to the transmitted command and data.
*	txSize:	The size of the transmitted command and data from AL to driver.
*	expSize: The size of expected data from SIM
*	result: Pointer to received data
* 	rcvSize: Pointer to the size of data received
*	parityError: 1 (parity error) or 0(no parity error)
*
* RETURNS
*	status(high byte:sw1 low byte: sw2)
*
* GLOBALS AFFECTED
*   external_global
*/
#ifdef NO_SLIM_DEF
sim_card_speed_type L1sim_Get_CardSpeedType(sim_HW_cb *hw_cb)
{
	Sim_Card *SimCard;

	SimCard = GET_SIM_CB(hw_cb->simInterface);

   return SimCard->sim_card_speed;
}
#endif




void *sim_get_sim_cb(kal_uint32 simInterface)
{

	return &SimCard_cb[simInterface];
}


void *sim_get_usim_cb(kal_uint32 simInterface)
{
	return &usim_cb[simInterface];
}

/*below is the adaptation to GPT driver*/
kal_uint8 DRV_ICC_GPTI_GetHandle(kal_uint32 *handle)
{
	*handle = DclSGPT_Open(DCL_GPT_CB, 0);
	return 0;
}

void DRV_ICC_GPTI_StopItem(kal_uint32 handle)
{
	DclSGPT_Control(handle, SGPT_CMD_STOP, 0);
}

kal_bool DRV_ICC_GPTI_StartItem(kal_uint32 handle,kal_uint16 tick,void (*gptimer_func)(void *),void *parameter)
{
	SGPT_CTRL_START_T ctrlVariable;
	DCL_STATUS status;
	
	ctrlVariable.u2Tick = tick;
	ctrlVariable.pfCallback = gptimer_func;
	ctrlVariable.vPara = parameter;
	status = DclSGPT_Control(handle, SGPT_CMD_START, (DCL_CTRL_DATA_T *)&ctrlVariable);
	if(STATUS_OK == status)
		return KAL_TRUE;
	else
		return KAL_FALSE;
}

/*below is the adaptation to PMU driver*/
void DRV_ICC_PMU_INIT()
{
	simPmuHandle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
}

void DRV_ICC_PMU_setVolt(kal_uint32 hwInterfaceNo, usim_power_enum volt)
{
	PMU_CTRL_LDO_BUCK_SET_VOLTAGE_EN val;

	switch(volt)
	{
		case CLASS_B_30V:
			val.voltage=PMU_VOLT_03_000000_V;
			break;
		case CLASS_C_18V:
			val.voltage=PMU_VOLT_01_800000_V;
			break;
		default:
			ASSERT(0);
			break;
	}
#ifdef CDMA_USE_MTK_BB_PMU	
	if (hwInterfaceNo == 0x0)
	   val.voltage=PMU_VOLT_03_000000_V;
#endif
	/*select corresponding VSIM module according to hwInterfaceNo*/
	if(0 == hwInterfaceNo){
		val.mod=VSIM;
	}
	else if(1 == hwInterfaceNo)
	{
		val.mod=VSIM2;
	}

	/*select corresponding cmd according to platform characteristic*/
#ifdef DUAL_MCU_SIM_V1
	DclPMU_Control(simPmuHandle, LDO_BUCK_SET_VOLTAGE_EN, (DCL_CTRL_DATA_T *)&val);
#else
	DclPMU_Control(simPmuHandle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&val);
#endif
}


void DRV_ICC_PMU_switch(kal_uint32 hwInterfaceNo, kal_bool enable)
{
	PMU_CTRL_LDO_BUCK_SET_EN val;
	val.enable=enable;
#ifdef CDMA_USE_MTK_BB_PMU	
	if (hwInterfaceNo == 0x0)
	{
	   val.enable = KAL_TRUE;
	   enable =  KAL_TRUE;
   }
#endif
	/*select corresponding VSIM module according to hwInterfaceNo*/
	if(0 == hwInterfaceNo){
		val.mod=VSIM;
	}
	else if(1 == hwInterfaceNo)
	{
		val.mod=VSIM2;
	}

	/*select corresponding cmd according to platform characteristic*/
#ifdef DUAL_MCU_SIM_V1
	/*in DUAL_MCU_SIM_V1, LDO has been enable when setting voltage, just need to handle switch off case */
	if(KAL_FALSE == enable)
		DclPMU_Control(simPmuHandle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
#else
	DclPMU_Control(simPmuHandle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
#endif

}

void DRV_ICC_PMU_SetGPIO(kal_uint32 hwInterfaceNo, kal_uint32 addr, kal_uint16 data)
{
   PMU_CTRL_MISC_SET_REGISTER_VALUE val;
   kal_uint32 Address;
   Address = addr | 0xc000; //PMIC GPIO reg base should define at dcl_Pmic632x_hw.h
   val.offset = (0 << 31) | Address;
   val.value = data;
	/*select corresponding cmd according to platform characteristic*/
#ifdef DUAL_MCU_SIM_V1
	/*in DUAL_MCU_SIM_V1, LDO has been enable when setting voltage, just need to handle switch off case */
	if(KAL_FALSE == enable)
		DclPMU_Control(simPmuHandle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&val);
#else
	DclPMU_Control(simPmuHandle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&val);
#endif
}

kal_uint16 DRV_ICC_PMU_GetGPIO(kal_uint32 hwInterfaceNo, kal_uint32 addr)
{
   PMU_CTRL_MISC_GET_REGISTER_VALUE val;
   kal_uint32 Address;
   Address = addr | 0xc000; //PMIC GPIO reg base should define at dcl_Pmic632x_hw.h
   val.offset = (0 << 31) | Address;
	/*select corresponding cmd according to platform characteristic*/
#ifdef DUAL_MCU_SIM_V1
	/*in DUAL_MCU_SIM_V1, LDO has been enable when setting voltage, just need to handle switch off case */
	if(KAL_FALSE == enable)
		DclPMU_Control(simPmuHandle, MISC_GET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&val);
#else
	DclPMU_Control(simPmuHandle, MISC_GET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&val);
#endif
   return val.value;

}
kal_uint16 DRV_ICC_PMU_Getmisc(kal_uint32 hwInterfaceNo, kal_uint32 addr)
{
   PMU_CTRL_MISC_GET_REGISTER_VALUE val;
//   Address = addr | 0xc000; //PMIC GPIO reg base should define at dcl_Pmic632x_hw.h
   val.offset = addr;
	/*select corresponding cmd according to platform characteristic*/
#ifdef DUAL_MCU_SIM_V1
	/*in DUAL_MCU_SIM_V1, LDO has been enable when setting voltage, just need to handle switch off case */
	if(KAL_FALSE == enable)
		DclPMU_Control(simPmuHandle, MISC_GET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&val);
#else
	DclPMU_Control(simPmuHandle, MISC_GET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&val);
#endif
   return val.value;

}

void DRV_ICC_PMU_SetSIMRST(kal_uint32 hwInterfaceNo, kal_bool enable)
{
	PMU_CTRL_SIMRST_SET_GPIO_SET setval;
	PMU_CTRL_SIMRST_SET_GPIO_CLR clrval;

	/*select corresponding VSIM module according to hwInterfaceNo*/
    if (enable == KAL_TRUE)
    {
	if(0 == hwInterfaceNo){
			setval.vsimIdx=PMIC_VSIM1;
	}
	else if(1 == hwInterfaceNo)
	{
			setval.vsimIdx=PMIC_VSIM2;
		}
    }
	else
	{
		if(0 == hwInterfaceNo){
			clrval.vsimIdx=PMIC_VSIM1;
		}
		else if(1 == hwInterfaceNo)
		{
			clrval.vsimIdx=PMIC_VSIM2;
		}
	}

    if (enable == KAL_TRUE)
	   DclPMU_Control(simPmuHandle, SIMRST_SET_GPIO_SET, (DCL_CTRL_DATA_T *)&setval);
	else
       DclPMU_Control(simPmuHandle, SIMRST_SET_GPIO_CLR, (DCL_CTRL_DATA_T *)&clrval);
}

void DRV_ICC_PMU_setSTBMode(kal_uint32 hwInterfaceNo, kal_bool swEnable)
{
	PMU_CTRL_SIM_SET_STB_SIO_MODE val;
	/*select corresponding VSIM module according to hwInterfaceNo*/
	if(0 == hwInterfaceNo){
		val.vsimIdx = PMIC_VSIM1;
	}
	else if(1 == hwInterfaceNo)
	{
		val.vsimIdx = PMIC_VSIM2;
	}
    if (swEnable == KAL_TRUE)		
	   val.mode = SW_ENABLE; // SW_ENABLE / HW_ENABLE
	else
	   val.mode = HW_ENABLE; // SW_ENABLE / HW_ENABLE
	DclPMU_Control(simPmuHandle, SIM_SET_STB_SIO_MODE, (DCL_CTRL_DATA_T *)&val);
}


void DRV_ICC_PMU_SelSRCLKEN(kal_uint32 hwInterfaceNo, kal_uint8 srcLkEn)
{
	PMU_CTRL_LDO_BUCK_SET_SRCLKEN_SEL val;
	val.SrclkenSel = SRCVOLTEN_OR_SRCLKEN_PERI_OR_SRCLKEN_MD2;  
	/* (SRCVOLTEN / SRCLKEN_PERI / SRCVOLTEN_OR_SRCLKEN_PERI / 
	SRCVOLTEN_OR_SRCLKEN_MD2 /  SRCLKEN_PERI_OR_SRCLKEN_MD2 /		  
	SRCVOLTEN_OR_SRCLKEN_PERI_OR_SRCLKEN_MD2) */

	/*select corresponding VSIM module according to hwInterfaceNo*/
	if(0 == hwInterfaceNo){
		val.mod=VSIM;
	}
	else if(1 == hwInterfaceNo)
	{
		val.mod=VSIM2;
	}

	/*select corresponding cmd according to platform characteristic*/
#ifdef DUAL_MCU_SIM_V1
   DclPMU_Control(simPmuHandle, LDO_BUCK_SET_SRCLKEN_SEL, (DCL_CTRL_DATA_T *)&val);

#else
	DclPMU_Control(simPmuHandle, LDO_BUCK_SET_SRCLKEN_SEL, (DCL_CTRL_DATA_T *)&val);	
#endif
}

void DRV_ICC_PMU_SetLpSel(kal_uint32 hwInterfaceNo, kal_bool isSwControl)
{
	PMU_CTRL_LDO_BUCK_SET_LP_SEL val;
	val.onSel = SRCLKEN_CONTROL; // (SW_CONTROL / SRCLKEN_CONTROL)

	/*select corresponding VSIM module according to hwInterfaceNo*/
	if(0 == hwInterfaceNo){
		val.mod=VSIM;
	}
	else if(1 == hwInterfaceNo)
	{
		val.mod=VSIM2;
	}

	/*select corresponding cmd according to platform characteristic*/
#ifdef DUAL_MCU_SIM_V1
   DclPMU_Control(simPmuHandle, LDO_BUCK_SET_LP_SEL, (DCL_CTRL_DATA_T *)&val);

#else
	DclPMU_Control(simPmuHandle, LDO_BUCK_SET_LP_SEL, (DCL_CTRL_DATA_T *)&val);	
#endif
}
kal_uint8 DRV_ICC_makeCLA(kal_uint8 CLAHighBits, kal_uint8 CLAFromApdu)
{
/*
	CLA has different combinations on different spec version, especiaaly from release 7.
	We should compose different CLA according to the CLA from SIM task APDU.
	We plan to implement as following, but currently we only implement the part before R7, and assert the case after R7.
	
	If(b7 == 0) //before release 7
	{
		//CLA of GET RESPONSE could be 0x0X
		
		Copy b4~b1 of previous command
		Bitwise OR with 0x0X to get CLA of GET RESPONSE
		
	}
	Else if(b7 ==1) //release 7 or later
	{
		//CLA of GET RESPONSE could be 0x4X, 0x6X
		
		Copy b6, b4~b1 of previous command
		Bitwise OR with 0x4X to get CLA of GET RESPONSE
		
	}
	Else //should not happen in current release
	{
		ASSERT(0);
	}
*/
	if(0 == (CLAFromApdu & 0x40)){ //before release 7
		return ((CLAHighBits & 0xf0) | (CLAFromApdu & 0x03)); // for CMCC NFC
	}
	else if(1 == (CLAFromApdu & 0x40)){//release 7 or later
		ASSERT(0);
	}
	else{
		ASSERT(0);
	}
	return 0;
}

void DRV_ICC_interface_init(SIM_ICC_APPLICATION application)
{
	sim_HW_cb	*hw_cb;
	kal_uint32 simInterface;
	kal_uint32 MT6302Info;
	simInterface = sim_get_logicalNum_from_app(application);
   

	hw_cb = &simHWCbArray[simInterface];
	hwCbArray[simInterface] = (kal_uint32)hw_cb;
	/* add pmic hw pointer */
	hw_cb->simPmicHwCb = &simPMICHWCbArray[simInterface];
#if defined (MT6589)
   SIM_SetData32(0xA0005510, 0x60000, 0x0);   
#endif

	if(MTK_SIMIF0 == sim_get_hwCtrl_from_logicalNum(simInterface)){
		hw_cb->mtk_baseAddr = SIM_base;
#ifdef __OLD_PDN_ARCH__
		hw_cb->mtk_pdnAddr = DRVPDN_CON1;
		hw_cb->mtk_pdnBit = DRVPDN_CON1_SIM;
#endif
#if defined (LPWR_SLIM)
		hw_cb->mtk_pdnDevice = PDN_DEV_SIM;
#else
		hw_cb->mtk_pdnDevice = PDN_SIM;
#endif
		hw_cb->mtk_dmaMaster = DMA_SIM;
		hw_cb->mtk_lisrCode = IRQ_SIM_CODE;
#if defined (LPWR_SLIM)
		hw_cb->smHandler = L1SM_GetHandle();
#endif
#if defined (__SIM_DRV_ENABLE_SWRST__) || defined (SIM_PMIC_GPIO_POLLING_MODE)
		hw_cb->simPmicHwCb->gpio_dir_base = SIM1_PMIC_GPIO_RST_DIR_OFFSET;
		hw_cb->simPmicHwCb->gpio_dir_base_bit_offset = SIM1_PMIC_GPIO_DIR;
		hw_cb->simPmicHwCb->gpio_mode_base = SIM1_PMIC_GPIO_RST_MODE_OFFSET;
		hw_cb->simPmicHwCb->gpio_mode_base_bit_offset = SIM1_PMIC_GPIO_MODE;
		hw_cb->simPmicHwCb->gpio_dout_base = SIM1_PMIC_GPIO_RST_DOUT_OFFSET;
		hw_cb->simPmicHwCb->gpio_dout_base_bit_offset = SIM1_PMIC_GPIO_DOUT;
		hw_cb->simPmicHwCb->gpio_ap_mode_base = SIM1_PMIC_GPIO_RST_AP_MODE_OFFSET;
		hw_cb->simPmicHwCb->gpio_ap_mode_base_bit_offset = SIM1_PMIC_GPIO_AP_MODE;
#endif
      /* set low power mode */
	   DRV_ICC_PMU_SelSRCLKEN(0, 6); //simInterface:0, SRCVOLTEN_OR_SRCLKEN_PERI_OR_SRCLKEN_MD2:6
	   DRV_ICC_PMU_SetLpSel(0,KAL_FALSE);//simInterface:0, KAL_FALSE: HW_SCRLKEN_CONTROL

	}
	else if (MTK_SIMIF1 == sim_get_hwCtrl_from_logicalNum(simInterface)){
#if (2 == SIM_DRV_MTK_INTERFACE_NUM)
		hw_cb->mtk_baseAddr = SIM2_base;
#ifdef __OLD_PDN_ARCH__
		hw_cb->mtk_pdnAddr = DRVPDN_CON0;
		hw_cb->mtk_pdnBit = DRVPDN_CON0_SIM2;
#endif
#if defined (LPWR_SLIM)
		hw_cb->mtk_pdnDevice = PDN_DEV_SIM2;
#else
		hw_cb->mtk_pdnDevice = PDN_SIM2;
#endif
		hw_cb->mtk_dmaMaster = DMA_SIM2;
		hw_cb->mtk_lisrCode = IRQ_SIM2_CODE;
#if defined (LPWR_SLIM)
		hw_cb->smHandler = L1SM_GetHandle();
#endif
#else
		/*for the platform that has single SIM controller, we shouldn't uses MTK_SIMIF1*/
		ASSERT(0);
#endif
#if defined (__SIM_DRV_ENABLE_SWRST__) || defined (SIM_PMIC_GPIO_POLLING_MODE)
		hw_cb->simPmicHwCb->gpio_dir_base = SIM2_PMIC_GPIO_RST_DIR_OFFSET;
		hw_cb->simPmicHwCb->gpio_dir_base_bit_offset = SIM2_PMIC_GPIO_DIR;
		hw_cb->simPmicHwCb->gpio_mode_base = SIM2_PMIC_GPIO_RST_MODE_OFFSET;
		hw_cb->simPmicHwCb->gpio_mode_base_bit_offset = SIM2_PMIC_GPIO_MODE;
		hw_cb->simPmicHwCb->gpio_dout_base = SIM2_PMIC_GPIO_RST_DOUT_OFFSET;
		hw_cb->simPmicHwCb->gpio_dout_base_bit_offset = SIM2_PMIC_GPIO_DOUT;
		hw_cb->simPmicHwCb->gpio_ap_mode_base = SIM2_PMIC_GPIO_RST_AP_MODE_OFFSET;
		hw_cb->simPmicHwCb->gpio_ap_mode_base_bit_offset = SIM2_PMIC_GPIO_AP_MODE;
#endif
      /* set low power mode */
      DRV_ICC_PMU_SelSRCLKEN(1, 6); //simInterface:1, SRCVOLTEN_OR_SRCLKEN_PERI_OR_SRCLKEN_MD2:6
      DRV_ICC_PMU_SetLpSel(1,KAL_FALSE);//simInterface:1, KAL_FALSE: HW_SCRLKEN_CONTROL
	}
	hw_cb->simInterface = simInterface;

		MT6302Info = sim_get_MT6302_from_logicalNum(simInterface);
		if(SIM_ICC_MT6302_NONE == MT6302Info){
			sim_driverTable[simInterface] = &sim_ctrlDriver_MTK;
			hw_cb->MT6302ChipNo = SIM_MT6302_INFO_UDF;
			hw_cb->MT6302PortNo = SIM_MT6302_INFO_UDF;
			hw_cb->MT6302PeerInterfaceCb = 0x0;
			/*
				this driver need to know which logical interface he is service to, so we have to create a shortcut from hw to logical interface.
				Since this information will be used in HISR and if we don't create the shortchut, we will take lots time search custom table.
			*/
			sim_mtkIf2Logical[sim_get_hwCtrl_from_logicalNum(simInterface)] = simInterface;
		}
		else if ((MT6302Info >> 16) > KAL_TRUE)
		{
		   /* Judge if support 6306 or 6314 */
			switch((MT6302Info >> 16) & 0x000000ff)
			{
				case 2://SIM_SWITCH_6306:
				{
#ifdef SIM_DRV_SWITCH_MT6306
					kal_uint32 peerInterface;

					sim_driverTable[simInterface] = &sim_ctrlDriver_MT6306;
					hw_cb->simSwitchChipNo = ((MT6302Info >> 8) & 0x000000ff);
					hw_cb->simSwitchPortNo = (MT6302Info & 0x000000ff);
					peerInterface = sim_get_MT6302PeerInterface(hw_cb->simSwitchChipNo, 1 - hw_cb->simSwitchPortNo);
					hw_cb->simSwitchPeerInterfaceCb = &simHWCbArray[peerInterface];
					sim_MT6306_init();
#endif
					break;
				}
				case 3://SIM_SWITCH_6314:
#ifdef SIM_DRV_SWITCH_MT6314
					sim_driverTable[simInterface] = &sim_ctrlDriver_AW6314;
					hw_cb-> simSwitchChipNo = ((MT6302Info >>8)	& 0x000000ff);
					hw_cb-> simSwitchPortNo = (MT6302Info & 0x000000ff);
					sim_AW6314_init();
#endif
					break;
				default:
					break;
			}
		}
		else{
#ifdef SIM_DRV_SWITCH_MT6302
			kal_uint32 peerInterface;
			
			sim_driverTable[simInterface] = &sim_ctrlDriver_MT6302;
			hw_cb->MT6302ChipNo = ((MT6302Info >>8)  & 0x000000ff);
			hw_cb->MT6302PortNo = (MT6302Info & 0x000000ff);
			peerInterface = sim_get_MT6302PeerInterface( MT6302Info>>8, 1 - (MT6302Info & 0x000000ff));
			hw_cb->MT6302PeerInterfaceCb = &simHWCbArray[peerInterface];

			sim_MT6302_init();
#endif
		}
#if defined (SIM_PMIC_GPIO_POLLING_MODE)
		//PMIC_DRV_SetGpioData(0x0012,0xFFFF,0x4000,0x0);
		DRV_ICC_PMU_SetGPIO(simInterface, hw_cb->simPmicHwCb->gpio_dir_base + SIM_PMIC_GPIO_SET_OFFSET, 1 << hw_cb->simPmicHwCb->gpio_dir_base_bit_offset);
		//PMIC_DRV_SetGpioData(0x010C,0xFFFF,0x0008,0x0);
		DRV_ICC_PMU_SetGPIO(simInterface, hw_cb->simPmicHwCb->gpio_mode_base + SIM_PMIC_GPIO_CLR_OFFSET,1 << hw_cb->simPmicHwCb->gpio_mode_base_bit_offset);

		//PMIC_DRV_SetGpioData(0x0104,0xFFFF,0x0040,0x0);
		DRV_ICC_PMU_SetGPIO(simInterface, hw_cb->simPmicHwCb->gpio_ap_mode_base + SIM_PMIC_GPIO_CLR_OFFSET,1 << hw_cb->simPmicHwCb->gpio_ap_mode_base_bit_offset); 			 
	   /* Set PMIC SIM2CLK to SIM mode */
		DRV_ICC_PMU_SetGPIO(simInterface, hw_cb->simPmicHwCb->gpio_mode_base + SIM_PMIC_GPIO_SET_OFFSET,1 << SIM2_PMIC_GPIO_MODE_CLK);
#endif	/*End of #if 0 */
#if defined (__SIM_DRV_ENABLE_SWRST__) || defined (SIM_PMIC_GPIO_POLLING_MODE)
     /* PMIC driver did not implement PMIC GPIO interface correctly, need to set SIM GPIO mode by sim driver */
	  /* Set PMIC SIMRST to GPIO output mode */
     DRV_ICC_PMU_SetGPIO(simInterface, hw_cb->simPmicHwCb->gpio_dir_base + SIM_PMIC_GPIO_SET_OFFSET,1 << hw_cb->simPmicHwCb->gpio_dir_base_bit_offset);
	  /* Set PMIC SIMRST to GPIO mode */
	  DRV_ICC_PMU_SetGPIO(simInterface, hw_cb->simPmicHwCb->gpio_mode_base + SIM_PMIC_GPIO_CLR_OFFSET,1 << hw_cb->simPmicHwCb->gpio_mode_base_bit_offset);
#endif
}

kal_uint32 sim_get_logical_from_SIMIF(kal_uint32 HWIf)
{
	return sim_mtkIf2Logical[HWIf];
}

void sim_set_logical_to_SIMIF(kal_uint32 HWIf, kal_uint32 logical)
{
	if(SIM_DRV_MTK_INTERFACE_NUM <= HWIf)
		ASSERT(0);
	if(DRV_SIM_MAX_LOGICAL_INTERFACE <= logical)
		ASSERT(0);

	sim_mtkIf2Logical[HWIf] = logical;
}

sim_HW_cb *sim_get_hwCb(kal_uint32 simInterface)
{
	return &simHWCbArray[simInterface];
}

void sim_init_hwCb(void)
{
	kal_uint32 loopIndex;
	for(loopIndex = 0; DRV_SIM_MAX_LOGICAL_INTERFACE > loopIndex; loopIndex++){
		simHWCbArray[loopIndex].head = SIM_HW_CB_HEAD;
		simHWCbArray[loopIndex].tail= SIM_HW_CB_TAIL;
	}
}

void sim_dbg_print(char *fmt,...)
{
#if	!defined( __MAUI_BASIC__)
    tst_sys_trace(fmt);
#else
	dbg_print(fmt);
#endif	
}

#ifdef IC_MODULE_TEST
typedef enum
{
	SIM_SLT_UNTEST,
	SIM_SLT_FAIL,
	SIM_SLT_PASS,
}sim_slt_rlt_enum;
sim_slt_rlt_enum sltRlt[DRV_SIM_MAX_LOGICAL_INTERFACE] = {SIM_SLT_UNTEST, SIM_SLT_UNTEST,
                                                          SIM_SLT_UNTEST, SIM_SLT_UNTEST};
kal_bool isSimSltFailSet[DRV_SIM_MAX_LOGICAL_INTERFACE] = {KAL_FALSE, KAL_FALSE,
                                                           KAL_FALSE, KAL_FALSE};
extern void module_test_print(char *fmt,...);
void L1sim_Set_Slt_Rlt(kal_bool rlt, SIM_ICC_APPLICATION application)
{
	kal_uint32 simInterface;
	simInterface = sim_get_logicalNum_from_app(application);

   /* If any time slt test result is fail, keep fail result */
	if (isSimSltFailSet[simInterface] == KAL_TRUE)
	   return;

   if (rlt == KAL_FALSE)
   {
      sltRlt[simInterface] = SIM_SLT_FAIL;
      isSimSltFailSet[simInterface] = KAL_TRUE;
//		module_test_print("\r\n");
//		module_test_print("MT6256 SLT Test 8 FALSE\r\n");

   }
   else
   {
      sltRlt[simInterface] = SIM_SLT_PASS;
//		module_test_print("\r\n");
//		module_test_print("MT6256 SLT Test 8 TRUE\r\n");

   }
}

kal_bool SIM_ModuleTest_Report(void)
{
   kal_uint8 i;
   kal_bool rlt = KAL_TRUE;

   for (i = 0;i < sim_get_ToalInterfaceCount(); i++)
   {
      /* If any interface slt result is fail, just return fail */
		if (sltRlt[i] != SIM_SLT_PASS)
		{
		   rlt = KAL_FALSE;
		   break;
		}
	}
	return rlt;
}
#endif

/*
* FUNCTION
*	DRV_ICC_Calc_WWT
*
* DESCRIPTION
*   	The function is used to calc WWT.
*
* CALLS
*
* PARAMETERS
*	Fi: value of the clock rate conversion integer
*	Di: value of baud rate adjustment integer
*	Wi: waiting time integer
*	*WWT: work waiting time
*
* RETURNS
*	void
*
* GLOBALS AFFECTED
*   external_global
*/
void DRV_ICC_Calc_WWT(kal_uint16 Fi, kal_uint8 Di,  kal_uint8 Wi, kal_uint32 *WWT)
{
   switch(Fi)
   {
      case 372:
		   /*  400*Wi to cover some slow card, margin: 3% */
		   *WWT = (960*Wi+400*Wi)*Di;
         break;
      default:
		   /*  40*Wi to cover some slow card, margin: 4% */
		   *WWT = (960*Wi+40*Wi)*Di;
	      break;
	}
}
#if defined(DRV_SIM_DBG_LOW_COST_ULC)
#define	SIM_MSG_NUM	1
#elif defined(DRV_SIM_DBG_LOW_COST_COMMON)
#define	SIM_MSG_NUM	256
#else
#define				SIM_MSG_NUM	1024
#endif

sim_msg				sim_msgArray[SIM_MSG_NUM];
kal_uint32			sim_msgIndex;
void sim_addMsg(kal_uint32 tag, kal_uint32 event, kal_uint32 data1, kal_uint32 data2)
{
	sim_msg *msgPtr;
	kal_uint32	savedMask;

	savedMask = SaveAndSetIRQMask();
	msgPtr = &sim_msgArray[sim_msgIndex];
	msgPtr->tag = (sim_msgTag)tag;
	msgPtr->event = event;
	msgPtr->data1 = data1;
	msgPtr->data2 = data2;
	msgPtr->time = drv_get_current_time();
	sim_msgIndex = (sim_msgIndex + 1) & (SIM_MSG_NUM -1);
	RestoreIRQMask(savedMask);
}
#endif /*__SIM_DRV_MULTI_DRV_ARCH__*/

#else //DRV_SIM_OFF
/*following is dummy API*/
void sim_init_hwCb(void){}
void DRV_ICC_interface_init(void){}
#endif //DRV_SIM_OFF

