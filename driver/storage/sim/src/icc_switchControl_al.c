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
 * switchControl_al.c(originally named sim_ctrl_al.c)
 *
 * Project:
 * --------
 *   Gemini
 *
 * Description:
 * ------------
 *   this file to handle original SIM task APIs on multiple SIM interface
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
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef DRV_SIM_OFF
#include 	"kal_public_api.h"
#include  	"drv_comm.h"
 #ifdef __SIM_DRV_MULTI_DRV_ARCH__
#include 	"reg_base.h"
#include 	"intrCtrl.h"
#include    "sim_al.h"
#include    "sim_hw_mtk.h"
#include 		"dma_sw.h"
#include    "sim_sw_comm.h"
#include    "dma_hw.h"
#include    "multi_icc_custom.h"
//#include		"gpt_sw.h"
//#include		"gpio_sw.h"
#include		"drv_hisr.h"

#ifdef MT6318
#include 	"pmic6318_sw.h"
#endif   /*MT6318*/

#include	"usim_MT6302.h"

#if defined(MT6223P)
#include "pmu_sw.h"
#endif

#include "sim_ctrl_al.h"

#ifdef DCL_SIM_INTERFACE
#include "dcl.h"
#endif

#if defined(__SIM_HOT_SWAP_POLL_TIMER__) && defined(__SIM_HOT_SWAP_SUPPORT__)
#include "sim_public_enum.h"
extern void sim_hot_swap_poll_timer_rollback(kal_uint32 which_sim);
extern SIM_ICC_HOT_PLUG iccHotPlugTable[];
#endif

#if	!defined( __MAUI_BASIC__)
#include"kal_trace.h"
#else
extern void dbg_print(char *fmt,...);
#endif
#include "kal_debug.h"
#if defined (LPWR_SLIM)
#include    "l1sm_public.h"
#endif


//#ifdef DRV_MULTIPLE_SIM //DRV_2_SIM_CONTROLLER
#if (defined(DRV_SIM_ALL_SOLUTION_BUILT) || defined(DRV_MULTIPLE_SIM))


extern sim_ctrlDriver sim_ctrlDriver_MT6302;
extern sim_ctrlDriver sim_ctrlDriver_MTK;
//static usim_dcb_struct usim_cb[DRV_SIM_MAX_LOGICAL_INTERFACE];

kal_uint32	hwCbArray[DRV_SIM_MAX_LOGICAL_INTERFACE]; //from logical number to sim_HW_cb

/*default driver used in pre-defined macro, customer can call sim_hookCtrlDriver to relpace what they want*/
#if defined(DRV_2_SIM_MT6302)
sim_ctrlDriver *sim_driverTable[DRV_SIM_MAX_LOGICAL_INTERFACE] = {&sim_ctrlDriver_MT6302, &sim_ctrlDriver_MT6302};
#elif defined(DRV_2_SIM_CONTROLLER)
sim_ctrlDriver *sim_driverTable[DRV_SIM_MAX_LOGICAL_INTERFACE] = {&sim_ctrlDriver_MTK, &sim_ctrlDriver_MTK};
#else
sim_ctrlDriver *sim_driverTable[DRV_SIM_MAX_LOGICAL_INTERFACE] = {&sim_ctrlDriver_MT6302, &sim_ctrlDriver_MT6302};
#endif

kal_bool	sim_physicalSlotChanged;


extern kal_uint8 is_HW_VERIFICATION_enabled(void);
extern kal_int32 IPC_RPC_EINT_GetAttribute (kal_uint8 *EintName, kal_uint32 EintNameLength, kal_uint32 queryType, void *result, kal_uint32 resultLength);
extern kal_char sim_dbg_str[];

//extern kal_taskid kal_get_current_thread_ID(void);

#define	SIM_AL_ACTION_RESET		0x000F0001
#define	SIM_AL_ACTION_POWOFF		0x000F0002
#define	SIM_AL_ACTION_COMMAND	0x000F0003
#define	SIM_AL_ACTION_EOC			0x000F0004


kal_bool sim_switchPhysicalSlotMapping(kal_bool inverse)
{
	kal_uint32 maskValue;

	maskValue = SaveAndSetIRQMask();
	sim_physicalSlotChanged = inverse;
	RestoreIRQMask(maskValue);

	if(KAL_FALSE == maskValue)
    {
#if	!defined( __MAUI_BASIC__)
       tst_sys_trace("SIM slots mapping is default mapping now");
#else
	   dbg_print("SIM slots mapping is default mapping now");
#endif
    }
	else
    {
#if	!defined( __MAUI_BASIC__)
       tst_sys_trace("SIM slots mapping is inverse mapping now");
#else
	   dbg_print("SIM slots mapping is inverse mapping now");
#endif
    }


	return sim_physicalSlotChanged;
}

/*this is just adaption layer, protections, project dependent work arounds should not be implemented here*/
void sim_hookCtrlDriver(kal_uint32 simInterface, sim_ctrlDriver *driver)
{

	if(KAL_TRUE == sim_physicalSlotChanged)
		simInterface = DRV_SIM_MAX_LOGICAL_INTERFACE -simInterface;


	if(0 != simInterface)
		ASSERT(0);
	sim_driverTable[simInterface] = driver;
}


usim_status_enum L1sim_Reset_All(sim_power_enum ExpectVolt, sim_power_enum *ResultVolt, kal_bool warm, SIM_ICC_APPLICATION application)
{
	sim_ctrlDriver *simDriver;
	usim_status_enum status;
	kal_uint32 simInterface;
#ifdef __SIM_HOT_SWAP_SUPPORT__
	kal_int32 ipcStatus;
#if defined (__MD1__) || defined (__SIM_HOT_PLUG_SINGLE_MD_QUERY_STR__)
	kal_uint8 *query, querystring[25] = "MD1_SIM1_HOT_PLUG_EINT";
#elif defined (__MD2__)
	kal_uint8 *query, querystring[25] = "MD2_SIM1_HOT_PLUG_EINT";
#else
	kal_uint8 *query, querystring[20] = "SIM1_HOT_PLUG_EINT";
#endif
	SIM_ICC_HOT_PLUG iccHotPlug = {KAL_FALSE, KAL_FALSE, KAL_FALSE, 0, 0, 0, 0, 0, 0, NULL, NULL};
	query = &querystring[0];
#endif
#ifdef SIM_4_CARD_SMT_TEST
	SIM_ICC_APPLICATION anotherApplication;
	kal_uint32 anotherSimInterface;
	sim_power_enum anotherResultVolt;
	sim_ctrlDriver *anotherSimDriver;
	usim_status_enum anotherStatus;
#endif 
   sim_HW_cb *hw_cb;

	simInterface = sim_get_logicalNum_from_app(application);
	hw_cb = (sim_HW_cb *)(hwCbArray[simInterface]);	
#ifdef SIM_4_CARD_SMT_TEST
	if(SIM_ICC_APPLICATION_PHONE1 == application)
		anotherApplication = SIM_ICC_APPLICATION_PHONE3;
	else if(SIM_ICC_APPLICATION_PHONE2 == application)
		anotherApplication = SIM_ICC_APPLICATION_PHONE4;
	else
		ASSERT(0);
	anotherSimInterface = sim_get_logicalNum_from_app(anotherApplication);
#endif

	if(DRV_SIM_MAX_LOGICAL_INTERFACE <= simInterface)
		ASSERT(0);
#ifdef SIM_4_CARD_SMT_TEST
	if(DRV_SIM_MAX_LOGICAL_INTERFACE <= anotherSimInterface)
		ASSERT(0);
#endif


	if(KAL_TRUE == sim_physicalSlotChanged){
#if	!defined( __MAUI_BASIC__)
       tst_sys_trace("[SIM]:sim interface inversed!!");
#else
	   dbg_print("[SIM]:sim interface inversed!!");
#endif
		simInterface = 1-simInterface;
		application = 1-application;  // need to switch to get correct hwcb and SIMIF number
	}


	if(0x0 == ResultVolt)
		ASSERT(0);

#if defined (LPWR_SLIM)
	L1SM_SleepDisable(hw_cb->smHandler); //lock sleep mode		
#endif

#ifdef __CUSTOMER_HW_VERIFICATION__
	simInterface = 0;
	/*find out the hooked function table*/
	simDriver = sim_driverTable[simInterface];
	ASSERT(0 != simDriver);
	sim_MT6302_addMsg(SIM_MT6302_ACTION_RESET, simInterface, 0, 0);
	status = simDriver->reset(ExpectVolt, ResultVolt, warm, (sim_HW_cb *)(hwCbArray[simInterface]));
	sim_MT6302_addMsg(SIM_MT6302_ACTION_EOC, simInterface, drv_get_current_time(), 0);
	simDriver->EOC((sim_HW_cb *)(hwCbArray[simInterface]));

	simInterface = 1;
	/*find out the hooked function table*/
	simDriver = sim_driverTable[simInterface];
	ASSERT(0 != simDriver);
	sim_MT6302_addMsg(SIM_MT6302_ACTION_RESET, simInterface, 0, 0);
	/*when we release single SIM MMI, we only release SIM1 MMI, cusrtomer won't get SIM2 MMI, SIM1 is what MMI need*/
	//status = simDriver->reset(ExpectVolt, ResultVolt, warm, simInterface);
	sim_MT6302_addMsg(SIM_MT6302_ACTION_EOC, simInterface, drv_get_current_time(), 0);
	simDriver->EOC(simInterface);
#else
	/*find out the hooked function table*/
	simDriver = sim_driverTable[simInterface];
	ASSERT(0 != simDriver);
	simDriver->addMessage(SIM_AL_ACTION_RESET, simInterface, (kal_uint32)kal_get_current_thread_ID(), 0);
	status = simDriver->reset(ExpectVolt, ResultVolt, warm, (sim_HW_cb *)(hwCbArray[simInterface]));
#ifdef __SIM_HOT_SWAP_SUPPORT__
   /* we should always register eint. If we bootup without plugin simcard, status will display NO_CARD.
   we will never get insert event because eint is not registered */
#if defined (__MD1__) || defined (__SIM_HOT_PLUG_SINGLE_MD_QUERY_STR__)
      if (application == SIM_ICC_APPLICATION_PHONE2)
         query = (kal_uint8 *)"MD1_SIM2_HOT_PLUG_EINT";
#elif defined (__MD2__)
      if (application == SIM_ICC_APPLICATION_PHONE2)
         query = (kal_uint8 *)"MD2_SIM2_HOT_PLUG_EINT";
#else
      if (application == SIM_ICC_APPLICATION_PHONE2)
         query = (kal_uint8 *)"SIM2_HOT_PLUG_EINT";
#endif         
      /* if any rpc error happens, we should leave register eint */   
#if defined (__MD1__) || defined (__MD2__) || defined (__SIM_HOT_PLUG_SINGLE_MD_QUERY_STR__)
      ipcStatus = IPC_RPC_EINT_GetAttribute(query, 23, SIM_HOT_PLUG_EINT_NUMBER, (void *)&iccHotPlug.eintNo, 4);
#else
      ipcStatus = IPC_RPC_EINT_GetAttribute(query, 19, SIM_HOT_PLUG_EINT_NUMBER, (void *)&iccHotPlug.eintNo, 4);
#endif
      if (ipcStatus < 0)
      { 
         kal_sprintf(sim_dbg_str,"get eint no fail %d %d, please request HW to check ALPS DWS setting.", ipcStatus, iccHotPlug.eintNo);
#if	!defined( __MAUI_BASIC__)
         tst_sys_trace(sim_dbg_str);
#else
	      dbg_print(sim_dbg_str);
#endif
         goto LEAVE_REG_EINT;
      }
#if defined (__MD1__) || defined (__MD2__) || defined (__SIM_HOT_PLUG_SINGLE_MD_QUERY_STR__)
      ipcStatus = IPC_RPC_EINT_GetAttribute(query, 23, SIM_HOT_PLUG_EINT_DEBOUNCETIME, (void *)&iccHotPlug.debounceTime, 4);
#else
      ipcStatus = IPC_RPC_EINT_GetAttribute(query, 19, SIM_HOT_PLUG_EINT_DEBOUNCETIME, (void *)&iccHotPlug.debounceTime, 4);
#endif      
      if (ipcStatus < 0)
      { 
         kal_sprintf(sim_dbg_str,"get debounce fail %d %d, please request HW to check ALPS DWS setting.", ipcStatus, iccHotPlug.debounceTime);
#if	!defined( __MAUI_BASIC__)
         tst_sys_trace(sim_dbg_str);
#else
	      dbg_print(sim_dbg_str);
#endif
         goto LEAVE_REG_EINT;
      }
#if defined (__MD1__) || defined (__MD2__) || defined (__SIM_HOT_PLUG_SINGLE_MD_QUERY_STR__)
      ipcStatus = IPC_RPC_EINT_GetAttribute(query, 23, SIM_HOT_PLUG_EINT_POLARITY, (void *)&iccHotPlug.polarity, 4);
#else
      ipcStatus = IPC_RPC_EINT_GetAttribute(query, 19, SIM_HOT_PLUG_EINT_POLARITY, (void *)&iccHotPlug.polarity, 4);
#endif      
      if (ipcStatus < 0)
      { 
         kal_sprintf(sim_dbg_str,"get polarity fail %d %d, please request HW to check ALPS DWS setting.", ipcStatus, iccHotPlug.polarity);
#if	!defined( __MAUI_BASIC__)
         tst_sys_trace(sim_dbg_str);
#else
	      dbg_print(sim_dbg_str);
#endif
         goto LEAVE_REG_EINT;
      }
#if defined (__MD1__) || defined (__MD2__) || defined (__SIM_HOT_PLUG_SINGLE_MD_QUERY_STR__)
      ipcStatus = IPC_RPC_EINT_GetAttribute(query, 23, SIM_HOT_PLUG_EINT_SENSITIVITY, (void *)&iccHotPlug.sensitivity, 4);
#else
      ipcStatus = IPC_RPC_EINT_GetAttribute(query, 19, SIM_HOT_PLUG_EINT_SENSITIVITY, (void *)&iccHotPlug.sensitivity, 4);
#endif
      
      if (ipcStatus < 0)
      { 
         kal_sprintf(sim_dbg_str,"get sensitivity fail %d %d, please request HW to check ALPS DWS setting.", ipcStatus, iccHotPlug.sensitivity);
#if	!defined( __MAUI_BASIC__)
         tst_sys_trace(sim_dbg_str);
#else
	      dbg_print(sim_dbg_str);
#endif
         goto LEAVE_REG_EINT;
      }
#if defined (__MD1__) || defined (__MD2__) || defined (__SIM_HOT_PLUG_SINGLE_MD_QUERY_STR__)
      ipcStatus = IPC_RPC_EINT_GetAttribute(query, 23, SIM_HOT_PLUG_EINT_SOCKETTYPE, (void *)&iccHotPlug.socketType, 4);
#else
      ipcStatus = IPC_RPC_EINT_GetAttribute(query, 19, SIM_HOT_PLUG_EINT_SOCKETTYPE, (void *)&iccHotPlug.socketType, 4);
#endif
      
      if (ipcStatus < 0)
      { 
         kal_sprintf(sim_dbg_str,"get socket fail %d %d, please request HW to check ALPS DWS setting.", ipcStatus, iccHotPlug.socketType);
#if	!defined( __MAUI_BASIC__)
         tst_sys_trace(sim_dbg_str);
#else
	      dbg_print(sim_dbg_str);
#endif
         goto LEAVE_REG_EINT;
      }
      sim_reg_hot_plug_eint(application, iccHotPlug.eintNo, iccHotPlug.debounceTime, iccHotPlug.polarity, iccHotPlug.sensitivity, iccHotPlug.socketType);
      
LEAVE_REG_EINT:
	   kal_sprintf(sim_dbg_str,"[SIM_DRV]EINT: %d, %d %d %d %d %d %d", application, ipcStatus, iccHotPlug.eintNo, iccHotPlug.debounceTime, iccHotPlug.polarity, iccHotPlug.sensitivity, iccHotPlug.socketType);
#if	!defined( __MAUI_BASIC__)
         tst_sys_trace(sim_dbg_str);
#else
	      dbg_print(sim_dbg_str);
#endif
	   kal_sprintf(sim_dbg_str,"[SIM_DRV]EINT: %s", query);
#if	!defined( __MAUI_BASIC__)
         tst_sys_trace(sim_dbg_str);
#else
	      dbg_print(sim_dbg_str);
#endif	
#endif /* End of #ifdef __SIM_HOT_SWAP_SUPPORT__ */
	simDriver->addMessage(SIM_AL_ACTION_EOC, simInterface, 0, 0);
	simDriver->EOC((sim_HW_cb *)(hwCbArray[simInterface]));

#ifdef SIM_4_CARD_SMT_TEST
	/*find out the hooked function table*/
	anotherSimDriver = sim_driverTable[anotherSimInterface];
	ASSERT(0 != anotherSimDriver);
	anotherSimDriver->addMessage(SIM_AL_ACTION_RESET, anotherSimInterface, (kal_uint32)kal_get_current_thread_ID(), 0);
	anotherStatus = anotherSimDriver->reset(UNKNOWN_POWER_CLASS, &anotherResultVolt, warm, (sim_HW_cb *)(hwCbArray[anotherSimInterface]));
	if(USIM_NO_ERROR == anotherStatus)
    {
#if	!defined( __MAUI_BASIC__)
       tst_sys_trace("another SIM card found!!");
#else
	   dbg_print("another SIM card found!!");
#endif
    }
	else
    { 
#if	!defined( __MAUI_BASIC__)
       tst_sys_trace("another SIM card not found!!");
#else
	   dbg_print("another SIM card not found!!");
#endif
    }
	anotherSimDriver->addMessage(SIM_AL_ACTION_EOC, anotherSimInterface, 0, 0);
	anotherSimDriver->EOC((sim_HW_cb *)(hwCbArray[anotherSimInterface]));
#endif

#endif
#if defined (LPWR_SLIM)
	L1SM_SleepEnable(hw_cb->smHandler);  //unlock sleep mode 	
#endif
	return status;
}

#ifndef __MAUI_BASIC__
#ifdef NO_SLIM_DEF
/*	this function is called by SIM task in single MMI load to help customer verify their HW
	the mainly difference to L1sim_reset_all is to reset both interface twice to test that HW layout to both cards work
*/
usim_status_enum L1sim_Reset_All_HW_verification(sim_power_enum ExpectVolt, sim_power_enum *ResultVolt, kal_bool warm, kal_uint32 simInterface)
{
	usim_status_enum statusWeWant = USIM_NO_ERROR;
#ifdef SIM_HW_TEST
	sim_ctrlDriver *simDriver;
	usim_status_enum status = USIM_NO_ERROR;
	kal_uint32 interfaceWeWant;

	/*This function should be only called when SIM task call is_HW_VERIFICATION_enabled and it return 1 or 2*/
	if(1 != is_HW_VERIFICATION_enabled() && 2 != is_HW_VERIFICATION_enabled())
		ASSERT(0);

	interfaceWeWant = simInterface;
	simInterface = 0;
	/*find out the hooked function table*/
	simDriver = sim_driverTable[simInterface];
	ASSERT(0 != simDriver);
	simDriver->addMessage(SIM_AL_ACTION_RESET, simInterface, 0, 0);
	status = simDriver->reset(ExpectVolt, ResultVolt, warm, (sim_HW_cb *)(hwCbArray[simInterface]));
	if(0 == interfaceWeWant)
		statusWeWant = status;
	simDriver->addMessage(SIM_AL_ACTION_EOC, simInterface, 0, 0);
	simDriver->EOC((sim_HW_cb *)(hwCbArray[simInterface]));

	simInterface = 1;
	/*find out the hooked function table*/
	simDriver = sim_driverTable[simInterface];
	ASSERT(0 != simDriver);
	simDriver->addMessage(SIM_AL_ACTION_RESET, simInterface, 0, 0);
	status = simDriver->reset(ExpectVolt, ResultVolt, warm, (sim_HW_cb *)(hwCbArray[simInterface]));
	if(1 == interfaceWeWant)
		statusWeWant = status;
	simDriver->addMessage(SIM_AL_ACTION_EOC, simInterface, 0, 0);
	simDriver->EOC((sim_HW_cb *)(hwCbArray[simInterface]));

	return statusWeWant;
#else
	ASSERT(0);
#endif
   return statusWeWant;
}
#endif
#endif

sim_status L1sim_Cmd_All(kal_uint8  *txData,kal_uint32  *txSize,kal_uint8  *rxData, kal_uint32  *rxSize, SIM_ICC_APPLICATION application)
{
	sim_ctrlDriver *simDriver;
	sim_status status;

	kal_uint32 simInterface;
   sim_HW_cb *hw_cb;
#if defined(__SIM_HOT_SWAP_POLL_TIMER__) && defined(__SIM_HOT_SWAP_SUPPORT__)
	Sim_Card *SimCard;
	usim_dcb_struct *usim_dcb;
#endif
	simInterface = sim_get_logicalNum_from_app(application);
	hw_cb = (sim_HW_cb *)(hwCbArray[simInterface]);	
#if defined (LPWR_SLIM)
	L1SM_SleepDisable(hw_cb->smHandler); //lock sleep mode		
#endif

	if(DRV_SIM_MAX_LOGICAL_INTERFACE <= simInterface)
		ASSERT(0);

	if(KAL_TRUE == sim_physicalSlotChanged)
		simInterface = 1-simInterface;


	if(0x0 == txData || 0x0 == txSize || 0x0 == rxSize)
		ASSERT(0);

	/*find out the hooked function table*/
	simDriver = sim_driverTable[simInterface];
	ASSERT(0 != simDriver);
	simDriver->addMessage(SIM_AL_ACTION_COMMAND, simInterface, (kal_uint32)kal_get_current_thread_ID(), 0);
	status = simDriver->command(txData, txSize, rxData, rxSize, (sim_HW_cb *)(hwCbArray[simInterface]));
	simDriver->addMessage(SIM_AL_ACTION_EOC, simInterface, 0, 0);
	simDriver->EOC((sim_HW_cb *)(hwCbArray[simInterface]));
#if defined (LPWR_SLIM)
	L1SM_SleepEnable(hw_cb->smHandler);  //unlock sleep mode 	
#endif	
#if defined(__SIM_HOT_SWAP_POLL_TIMER__) && defined(__SIM_HOT_SWAP_SUPPORT__)
	SimCard = GET_SIM_CB(hw_cb->simInterface);
	usim_dcb = GET_USIM_CB(hw_cb->simInterface);
	if(SimCard->poll_sim_2s || usim_dcb->poll_sim_2s) 
	{
		sim_hot_swap_poll_timer_rollback(application);
		SimCard->poll_sim_2s = KAL_FALSE;
		usim_dcb->poll_sim_2s = KAL_FALSE;
#if	!defined( __MAUI_BASIC__)
       tst_sys_trace("[SIM DRV]stop timer\n\r");
#else
	   dbg_print("[SIM DRV]stop timer\n\r");
#endif
		if(status == 0x0000)
		{
#ifdef __SIM_HOT_SWAP_SUPPORT__
			iccHotPlugTable[simInterface].plugOutcb(simInterface);
#endif
#if	!defined( __MAUI_BASIC__)
       tst_sys_trace("[SIM DRV]real hot plug\n\r");
#else
	   dbg_print("[SIM DRV]real hot plug\n\r");
#endif
		}
	}
#endif

	return status;
}

void L1sim_PowerOff_All(SIM_ICC_APPLICATION application)
{
	sim_ctrlDriver *simDriver;
	kal_uint32 simInterface;
   sim_HW_cb *hw_cb;

	simInterface = sim_get_logicalNum_from_app(application);
	hw_cb = (sim_HW_cb *)(hwCbArray[simInterface]); 
#if defined (LPWR_SLIM)
	L1SM_SleepDisable(hw_cb->smHandler); //lock sleep mode		
#endif

	if(DRV_SIM_MAX_LOGICAL_INTERFACE <= simInterface)
		ASSERT(0);

	if(KAL_TRUE == sim_physicalSlotChanged)
		simInterface = 1-simInterface;


	/*find out the hooked function table*/
	simDriver = sim_driverTable[simInterface];
	ASSERT(0 != simDriver);
	simDriver->addMessage(SIM_AL_ACTION_POWOFF, simInterface, (kal_uint32)kal_get_current_thread_ID(), 0);
	simDriver->powerOff((sim_HW_cb *)(hwCbArray[simInterface]));
	simDriver->addMessage(SIM_AL_ACTION_EOC, simInterface, 0, 0);
	simDriver->EOC((sim_HW_cb *)(hwCbArray[simInterface]));
#if defined (LPWR_SLIM)
	L1SM_SleepEnable(hw_cb->smHandler);  //unlock sleep mode 	
#endif
}

void L1sim_Get_Card_Info_All(sim_info_struct *info, SIM_ICC_APPLICATION application)
{
	sim_ctrlDriver *simDriver;
	kal_uint32 simInterface;

	simInterface = sim_get_logicalNum_from_app(application);


	if(DRV_SIM_MAX_LOGICAL_INTERFACE <= simInterface)
		ASSERT(0);

	if(KAL_TRUE == sim_physicalSlotChanged)
		simInterface = 1-simInterface;


	/*find out the hooked function table*/
	simDriver = sim_driverTable[simInterface];
	ASSERT(0 != simDriver);
	simDriver->getCardInfo(info, (sim_HW_cb *)(hwCbArray[simInterface]));
}

void L1sim_Enable_Enhanced_Speed_All(kal_bool enable, SIM_ICC_APPLICATION application)
{
#ifdef NO_SLIM_DEF
	sim_ctrlDriver *simDriver;
	kal_uint32 simInterface;

	simInterface = sim_get_logicalNum_from_app(application);

	if(DRV_SIM_MAX_LOGICAL_INTERFACE <= simInterface)
		ASSERT(0);

	if(KAL_TRUE == sim_physicalSlotChanged)
		simInterface = 1-simInterface;


	/*find out the hooked function table*/
	simDriver = sim_driverTable[simInterface];
	ASSERT(0 != simDriver);
	simDriver->enableEnhancedSpeed(enable, (sim_HW_cb *)(hwCbArray[simInterface]));
#endif	
}

void L1sim_Select_Prefer_PhyLayer_All(sim_protocol_phy_enum T, SIM_ICC_APPLICATION application)
{
	sim_ctrlDriver *simDriver;
	kal_uint32 simInterface;

	simInterface = sim_get_logicalNum_from_app(application);

	if(DRV_SIM_MAX_LOGICAL_INTERFACE <= simInterface)
		ASSERT(0);

	if(KAL_TRUE == sim_physicalSlotChanged)
		simInterface = 1-simInterface;


	/*find out the hooked function table*/
	simDriver = sim_driverTable[simInterface];
	ASSERT(0 != simDriver);
	simDriver->selectPreferPhyLayer(T, (sim_HW_cb *)(hwCbArray[simInterface]));
}

kal_bool L1sim_Set_ClockStopMode_All(sim_clock_stop_enum mode, SIM_ICC_APPLICATION application)
{
	sim_ctrlDriver *simDriver;
	kal_bool status;
	kal_uint32 simInterface;
   sim_HW_cb *hw_cb;

	simInterface = sim_get_logicalNum_from_app(application);
	hw_cb = (sim_HW_cb *)(hwCbArray[simInterface]); 
#if defined (LPWR_SLIM)
	L1SM_SleepDisable(hw_cb->smHandler); //lock sleep mode		
#endif

	if(DRV_SIM_MAX_LOGICAL_INTERFACE <= simInterface)
		ASSERT(0);

	if(KAL_TRUE == sim_physicalSlotChanged)
		simInterface = 1-simInterface;


	/*find out the hooked function table*/
	simDriver = sim_driverTable[simInterface];
	ASSERT(0 != simDriver);
	status = simDriver->setClockStopMode(mode, (sim_HW_cb *)(hwCbArray[simInterface]));
#if defined (LPWR_SLIM)
	L1SM_SleepEnable(hw_cb->smHandler);  //unlock sleep mode 	
#endif
	return status;
}

#ifdef NO_SLIM_DEF
/*for specific purpose, SIM task should not call this */
void sim_releaseOwner(SIM_ICC_APPLICATION application)
{
	usim_dcb_struct *usim_dcb;
	kal_uint32 simInterface;

	simInterface = sim_get_logicalNum_from_app(application);

	usim_dcb = GET_USIM_CB(simInterface);

	if(DRV_SIM_MAX_LOGICAL_INTERFACE <= simInterface)
		ASSERT(0);

	if(KAL_TRUE == sim_physicalSlotChanged)
		simInterface = 1-simInterface;


	usim_dcb->ownerTask = 0;
}
#endif
/*following are pure SW query, no matter of different driver solutions*/
sim_card_speed_type L1sim_Get_CardSpeedType(SIM_ICC_APPLICATION application)
{
	Sim_Card *SimCard;
	kal_uint32 simInterface;

	simInterface = sim_get_logicalNum_from_app(application);

	SimCard = GET_SIM_CB(simInterface);

   return SimCard->sim_card_speed;
}

kal_bool sim_queryGet9000WhenSelect(SIM_ICC_APPLICATION application)
{
	Sim_Card *SimCard;
	kal_uint32 simInterface;

	simInterface = sim_get_logicalNum_from_app(application);
	SimCard = GET_SIM_CB(simInterface);

	return SimCard->get9000WhenSelect;
}

void sim_toutTest_al(kal_uint32 toutValue, SIM_ICC_APPLICATION application)
{
#ifdef SIM_HW_TEST
	sim_ctrlDriver *simDriver;	
	kal_uint32 simInterface;

	simInterface = sim_get_logicalNum_from_app(application);

	if(DRV_SIM_MAX_LOGICAL_INTERFACE <= simInterface)
		ASSERT(0);

	if(KAL_TRUE == sim_physicalSlotChanged)
		simInterface = 1-simInterface;


	/*find out the hooked function table*/
	simDriver = sim_driverTable[simInterface];
	ASSERT(0 != simDriver);
	simDriver->toutTest(toutValue, (sim_HW_cb *)(hwCbArray[simInterface]));

#endif
}
#endif

#ifdef DCL_SIM_INTERFACE
/*dcl add new api : 1. fill table*/
DCL_SIMDriver_t sim_ctrlDriver_All = {
	(DCL_SIM_RST)L1sim_Reset_All,
	(DCL_SIM_CMD)L1sim_Cmd_All,
	(DCL_SIM_PWOFF)L1sim_PowerOff_All,
	(DCL_SIM_GET_CARD_INFO)L1sim_Get_Card_Info_All,
	(DCL_SIM_SET_MAX_SPEED)L1sim_Enable_Enhanced_Speed_All,
	(DCL_SIM_SET_PREFER_PROTOCOL)L1sim_Select_Prefer_PhyLayer_All,
	(DCL_SIM_SET_CLK_STOP_MODE)L1sim_Set_ClockStopMode_All,
	(DCL_SIM_TOUT_TEST)sim_toutTest_al,
	NULL,
	(DCL_SIM_GAT_CARD_SPEED)L1sim_Get_CardSpeedType,
	(DCL_SIM_QUERY_GET_9000_WHEN_SELECT)sim_queryGet9000WhenSelect
};
#endif //DCL_SIM_INTERFACE

#endif /*__SIM_DRV_MULTI_DRV_ARCH__*/

#else //DRV_SIM_OFF
#include  	"drv_comm.h"

#ifdef DCL_SIM_INTERFACE
#include "dcl.h"
void sim_dummyAPI(void){}
DCL_SIMDriver_t sim_ctrlDriver_All = {
	(DCL_SIM_RST)sim_dummyAPI,
	(DCL_SIM_CMD)sim_dummyAPI,
	(DCL_SIM_PWOFF)sim_dummyAPI,
	(DCL_SIM_GET_CARD_INFO)sim_dummyAPI,
	(DCL_SIM_SET_MAX_SPEED)sim_dummyAPI,
	(DCL_SIM_SET_PREFER_PROTOCOL)sim_dummyAPI,
	(DCL_SIM_SET_CLK_STOP_MODE)sim_dummyAPI,
	NULL,
	(DCL_SIM_GAT_CARD_SPEED)sim_dummyAPI,
	(DCL_SIM_QUERY_GET_9000_WHEN_SELECT)sim_dummyAPI
};
#endif //DCL_SIM_INTERFACE

#endif //DRV_SIM_OFF

