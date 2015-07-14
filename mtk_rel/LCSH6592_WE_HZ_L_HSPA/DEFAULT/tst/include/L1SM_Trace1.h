#ifndef L1TRC_L1SM_1_DEF_H
#define L1TRC_L1SM_1_DEF_H

/******************************/
/* String category definition */
/******************************/
#define L1D_Trace_Str_TM_Sync_State(v1)  (unsigned char)(v1+0)
#define L1SM_Str_Wakeup(v1)  (unsigned char)(v1+2)
#define L1SM_Str_Bool(v1)  (unsigned char)(v1+13)
#define L1SM_Disable_Bool(v1)  (unsigned char)(v1+15)
#define L1SM_Str_Lpm_Changed(v1)  (unsigned char)(v1+17)
#define L1SM_UPDATE_R32K_Str(v1)  (unsigned char)(v1+19)
#define DCXO_MODE_Str(v1)  (unsigned char)(v1+26)
#define L1SM_ENTER_26M_FPM_Str(v1)  (unsigned char)(v1+28)
#define OSTD_TIMER_TYPE_Str(v1)  (unsigned char)(v1+31)
#define L1SM_Str_Sleep_FRC(v1)  (unsigned char)(v1+33)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define L1SM_DBG_CALI_START() do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0028, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1SM_DBG_CALI_START()
#endif
#define L1SM_DBG_CALI_START_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0028, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1SM_DBG_CALI_DONE(v1, v2) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0128, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define L1SM_DBG_CALI_DONE(v1, v2)
#endif
#define L1SM_DBG_CALI_DONE_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0128, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define L1SM_DBG_3G_PASS_2G(v1, v2) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0228, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define L1SM_DBG_3G_PASS_2G(v1, v2)
#endif
#define L1SM_DBG_3G_PASS_2G_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0228, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define L1SM_DBG_SW_WAKEUP(v1) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0328, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1SM_DBG_SW_WAKEUP(v1)
#endif
#define L1SM_DBG_SW_WAKEUP_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0328, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1SM_DBG_CAL_SLEEP(v1, v2, v3, v4) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0428, (unsigned short)(v3)), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v4));\
	} while(0)
#else
	#define L1SM_DBG_CAL_SLEEP(v1, v2, v3, v4)
#endif
#define L1SM_DBG_CAL_SLEEP_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0428, (unsigned short)(v3)), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define L1SM_DBG_CAL_HW_SLEEP(v1, v2) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0528, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1SM_DBG_CAL_HW_SLEEP(v1, v2)
#endif
#define L1SM_DBG_CAL_HW_SLEEP_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0528, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1SM_DBG_CHECK_SLEEP_F(v1, v2) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0628, (unsigned short)(v2)), (unsigned long)(v1));\
	} while(0)
#else
	#define L1SM_DBG_CHECK_SLEEP_F(v1, v2)
#endif
#define L1SM_DBG_CHECK_SLEEP_F_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0628, (unsigned short)(v2)), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1SM_DBG_CHECK_HW_DEBOUNCE(v1) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0728, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define L1SM_DBG_CHECK_HW_DEBOUNCE(v1)
#endif
#define L1SM_DBG_CHECK_HW_DEBOUNCE_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0728, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define L1SM_DBG_CHECK_SLEEP_C(v1, v2, v3, v4, v5) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0828, (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1SM_DBG_CHECK_SLEEP_C(v1, v2, v3, v4, v5)
#endif
#define L1SM_DBG_CHECK_SLEEP_C_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0828, (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1SM_DBG_CHECK_SLEEP_TASK(v1) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0928, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define L1SM_DBG_CHECK_SLEEP_TASK(v1)
#endif
#define L1SM_DBG_CHECK_SLEEP_TASK_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0928, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define L1SM_DBG_CHECK_SLEEP_OS(v1, v2, v3, v4) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0A28, (short)(v2)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v1), (unsigned char)(v3)));\
	} while(0)
#else
	#define L1SM_DBG_CHECK_SLEEP_OS(v1, v2, v3, v4)
#endif
#define L1SM_DBG_CHECK_SLEEP_OS_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0A28, (short)(v2)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v1), (unsigned char)(v3)))

#if defined(L1_CATCHER)
	#define L1SM_DBG_BEFORE_SLEEP(v1, v2, v3, v4) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0B28, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define L1SM_DBG_BEFORE_SLEEP(v1, v2, v3, v4)
#endif
#define L1SM_DBG_BEFORE_SLEEP_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0B28, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define L1SM_DBG_SLEEP_FRC(v1, v2, v3, v4) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0C28, (unsigned char)(v1), (unsigned char)(v3)), (unsigned long)(v2), (unsigned long)(v4));\
	} while(0)
#else
	#define L1SM_DBG_SLEEP_FRC(v1, v2, v3, v4)
#endif
#define L1SM_DBG_SLEEP_FRC_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0C28, (unsigned char)(v1), (unsigned char)(v3)), (unsigned long)(v2), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define L1SM_TRC_DEBUG(v1, v2, v3) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0D28, (unsigned short)(v1)), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define L1SM_TRC_DEBUG(v1, v2, v3)
#endif
#define L1SM_TRC_DEBUG_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0D28, (unsigned short)(v1)), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define L1SM_TRC_DEBUG_HEX(v1, v2, v3) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0E28, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define L1SM_TRC_DEBUG_HEX(v1, v2, v3)
#endif
#define L1SM_TRC_DEBUG_HEX_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0E28, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define L1SM_DBG_CHECK_SM_CALLER(v1, v2, v3, v4, v5) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x0F28, (short)(v3)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define L1SM_DBG_CHECK_SM_CALLER(v1, v2, v3, v4, v5)
#endif
#define L1SM_DBG_CHECK_SM_CALLER_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_2S(0x0F28, (short)(v3)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER)
	#define L1SM_DBG_CHECK_SM_LOCKER(v1, v2) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1028, (short)(v1)), (unsigned long)(v2));\
	} while(0)
#else
	#define L1SM_DBG_CHECK_SM_LOCKER(v1, v2)
#endif
#define L1SM_DBG_CHECK_SM_LOCKER_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1028, (short)(v1)), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DUAL_OS_TICK_2G_COMMON(v1, v2) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1128, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define DUAL_OS_TICK_2G_COMMON(v1, v2)
#endif
#define DUAL_OS_TICK_2G_COMMON_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1128, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DUAL_OS_TICK_2G_RECOVER(v1) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1228, (unsigned short)(v1)));\
	} while(0)
#else
	#define DUAL_OS_TICK_2G_RECOVER(v1)
#endif
#define DUAL_OS_TICK_2G_RECOVER_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1228, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DUAL_OS_TICK_INITIAL(v1, v2, v3) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1328, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DUAL_OS_TICK_INITIAL(v1, v2, v3)
#endif
#define DUAL_OS_TICK_INITIAL_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1328, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DUAL_OS_TICK_3G_COMMON(v1, v2) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1428, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define DUAL_OS_TICK_3G_COMMON(v1, v2)
#endif
#define DUAL_OS_TICK_3G_COMMON_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1428, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DUAL_OS_TICK_3G_RECOVER(v1) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1528, (unsigned short)(v1)));\
	} while(0)
#else
	#define DUAL_OS_TICK_3G_RECOVER(v1)
#endif
#define DUAL_OS_TICK_3G_RECOVER_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1528, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DUAL_OS_TICK_3G_DBG(v1, v2) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1628, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define DUAL_OS_TICK_3G_DBG(v1, v2)
#endif
#define DUAL_OS_TICK_3G_DBG_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1628, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define OSTD_TRC_DEBUG1(v1, v2, v3) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1728, (unsigned short)(v1)), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define OSTD_TRC_DEBUG1(v1, v2, v3)
#endif
#define OSTD_TRC_DEBUG1_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1728, (unsigned short)(v1)), (long)(v2), (long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define OSTD_TRC_DEBUG2(v1, v2, v3) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1828, (unsigned short)(v1)), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define OSTD_TRC_DEBUG2(v1, v2, v3)
#endif
#define OSTD_TRC_DEBUG2_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1828, (unsigned short)(v1)), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define OSTD_SM_STATUS(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_8_DATA(TRC_MERGE_2S(0x1928, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8));\
	} while(0)
#else
	#define OSTD_SM_STATUS(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define OSTD_SM_STATUS_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_8_DATA(TRC_MERGE_2S(0x1928, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8))

#if defined(L1_CATCHER)
	#define OSTD_DBG_COCLK_UPDATE_FMRESULT(v1, v2, v3, v4) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x1A28, (unsigned short)(v1)), (unsigned long)(v2), (long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define OSTD_DBG_COCLK_UPDATE_FMRESULT(v1, v2, v3, v4)
#endif
#define OSTD_DBG_COCLK_UPDATE_FMRESULT_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x1A28, (unsigned short)(v1)), (unsigned long)(v2), (long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define OSTD_TRC_CALIBRATION(v1, v2, v3) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1B28, (unsigned short)(v1)), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define OSTD_TRC_CALIBRATION(v1, v2, v3)
#endif
#define OSTD_TRC_CALIBRATION_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1B28, (unsigned short)(v1)), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define OSTD_TRC_INF_SLEEP_TRG() do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1C28, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define OSTD_TRC_INF_SLEEP_TRG()
#endif
#define OSTD_TRC_INF_SLEEP_TRG_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1C28, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define OSTD_TRC_INF_SLEEP_TIMER_CB(v1, v2) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1D28, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define OSTD_TRC_INF_SLEEP_TIMER_CB(v1, v2)
#endif
#define OSTD_TRC_INF_SLEEP_TIMER_CB_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1D28, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define DUAL_OS_TICK_ReSync() do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1E28, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DUAL_OS_TICK_ReSync()
#endif
#define DUAL_OS_TICK_ReSync_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1E28, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DUAL_OS_RTC(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_10_DATA(TRC_MERGE_2S(0x1F28, (unsigned short)(v6)), TRC_MERGE_1S2C((unsigned short)(v11), (unsigned char)(v1), (unsigned char)(v9)), TRC_MERGE_4C((unsigned char)(v10), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (long)(v5), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v12));\
	} while(0)
#else
	#define DUAL_OS_RTC(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12)
#endif
#define DUAL_OS_RTC_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) TRC_SEND_10_DATA(TRC_MERGE_2S(0x1F28, (unsigned short)(v6)), TRC_MERGE_1S2C((unsigned short)(v11), (unsigned char)(v1), (unsigned char)(v9)), TRC_MERGE_4C((unsigned char)(v10), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (long)(v5), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v12))

#if defined(L1_CATCHER)
	#define L1SM_Trace_SW1(v1, v2, v3) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x2028, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define L1SM_Trace_SW1(v1, v2, v3)
#endif
#define L1SM_Trace_SW1_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x2028, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define L1SM_Trace_SW2(v1) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x2128, (short)(v1)));\
	} while(0)
#else
	#define L1SM_Trace_SW2(v1)
#endif
#define L1SM_Trace_SW2_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x2128, (short)(v1)))

#if defined(L1_CATCHER)
	#define L1SM_Trace_SW3(v1) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2228, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define L1SM_Trace_SW3(v1)
#endif
#define L1SM_Trace_SW3_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2228, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define L1SM_Trace_SW4(v1, v2, v3, v4, v5, v6) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x2328, (unsigned char)(v1), (unsigned char)(v4)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define L1SM_Trace_SW4(v1, v2, v3, v4, v5, v6)
#endif
#define L1SM_Trace_SW4_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x2328, (unsigned char)(v1), (unsigned char)(v4)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER)
	#define L1SM_Trace_SW5(v1, v2, v3, v4) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x2428, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define L1SM_Trace_SW5(v1, v2, v3, v4)
#endif
#define L1SM_Trace_SW5_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x2428, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define L1SM_DBG_R_32K_UPDATE(v1, v2) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2528, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define L1SM_DBG_R_32K_UPDATE(v1, v2)
#endif
#define L1SM_DBG_R_32K_UPDATE_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2528, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define L1I_Msg_AvgTAC(v1, v2) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2628, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Msg_AvgTAC(v1, v2)
#endif
#define L1I_Msg_AvgTAC_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2628, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1SM_DBG_32KLESS_WAKEUP(v1, v2) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2728, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1SM_DBG_32KLESS_WAKEUP(v1, v2)
#endif
#define L1SM_DBG_32KLESS_WAKEUP_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2728, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1SM_DBG_32KLESS_FORCE_REPORT() do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2828, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1SM_DBG_32KLESS_FORCE_REPORT()
#endif
#define L1SM_DBG_32KLESS_FORCE_REPORT_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2828, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1SM_DBG_STABLE_PARAM(v1, v2, v3, v4) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2928, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1SM_DBG_STABLE_PARAM(v1, v2, v3, v4)
#endif
#define L1SM_DBG_STABLE_PARAM_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2928, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1SM_DBG_32KLESS_UPDATE_LPM(v1, v2, v3, v4, v5, v6) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2A28, (short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v5), (unsigned char)(v6)));\
	} while(0)
#else
	#define L1SM_DBG_32KLESS_UPDATE_LPM(v1, v2, v3, v4, v5, v6)
#endif
#define L1SM_DBG_32KLESS_UPDATE_LPM_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2A28, (short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v5), (unsigned char)(v6)))

#if defined(L1_CATCHER)
	#define DCXO_DIV_DBG_UPDATE_R32K(v1, v2, v3, v4, v5) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2B28, (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DCXO_DIV_DBG_UPDATE_R32K(v1, v2, v3, v4, v5)
#endif
#define DCXO_DIV_DBG_UPDATE_R32K_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2B28, (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define DCXO_DIV_DBG_ENTER_26MHz_FPM(v1, v2, v3) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2C28, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DCXO_DIV_DBG_ENTER_26MHz_FPM(v1, v2, v3)
#endif
#define DCXO_DIV_DBG_ENTER_26MHz_FPM_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2C28, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define DCXO_DIV_DBG_UPDATE(v1, v2, v3) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2D28, (unsigned short)(v1)), TRC_MERGE_1S2C((short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define DCXO_DIV_DBG_UPDATE(v1, v2, v3)
#endif
#define DCXO_DIV_DBG_UPDATE_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2D28, (unsigned short)(v1)), TRC_MERGE_1S2C((short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER)
	#define DCXO_DIV_DBG_Check(v1, v2) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2E28, (unsigned short)(v1)), (long)(v2));\
	} while(0)
#else
	#define DCXO_DIV_DBG_Check(v1, v2)
#endif
#define DCXO_DIV_DBG_Check_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2E28, (unsigned short)(v1)), (long)(v2))

#if defined(L1_CATCHER)
	#define DCXO_DIV_DBG_UPDATE_UNLOCK(v1, v2, v3, v4) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2F28, (unsigned short)(v2)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v3));\
	} while(0)
#else
	#define DCXO_DIV_DBG_UPDATE_UNLOCK(v1, v2, v3, v4)
#endif
#define DCXO_DIV_DBG_UPDATE_UNLOCK_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2F28, (unsigned short)(v2)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v3))

#if defined(L1_CATCHER)
	#define DCXO_DIV_LPM_CNT_UPDATE(v1, v2, v3) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x3028, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define DCXO_DIV_LPM_CNT_UPDATE(v1, v2, v3)
#endif
#define DCXO_DIV_LPM_CNT_UPDATE_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x3028, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define DCXO_DIV_LPM_CNT_END(v1, v2, v3, v4) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x3128, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define DCXO_DIV_LPM_CNT_END(v1, v2, v3, v4)
#endif
#define DCXO_DIV_LPM_CNT_END_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x3128, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define DCXO_DIV_LPM_CNT_END_Delay(v1, v2, v3, v4, v5, v6) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x3228, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define DCXO_DIV_LPM_CNT_END_Delay(v1, v2, v3, v4, v5, v6)
#endif
#define DCXO_DIV_LPM_CNT_END_Delay_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x3228, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER)
	#define DCXO_DIV_PCM_CNT(v1, v2) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3328, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define DCXO_DIV_PCM_CNT(v1, v2)
#endif
#define DCXO_DIV_PCM_CNT_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3328, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define L1SM_DBG_Timing_Profile(v1, v2, v3, v4, v5, v6) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x3428, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6));\
	} while(0)
#else
	#define L1SM_DBG_Timing_Profile(v1, v2, v3, v4, v5, v6)
#endif
#define L1SM_DBG_Timing_Profile_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_6_DATA(TRC_MERGE_2S(0x3428, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6))

#if defined(L1_CATCHER)
	#define L1SM_DBG_TP_A(v1, v2, v3, v4) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x3528, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2), (long)(v4));\
	} while(0)
#else
	#define L1SM_DBG_TP_A(v1, v2, v3, v4)
#endif
#define L1SM_DBG_TP_A_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x3528, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2), (long)(v4))

#if defined(L1_CATCHER)
	#define L1SM_DBG_TP_B(v1, v2, v3, v4, v5) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x3628, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2), (long)(v4), (long)(v5));\
	} while(0)
#else
	#define L1SM_DBG_TP_B(v1, v2, v3, v4, v5)
#endif
#define L1SM_DBG_TP_B_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_2S(0x3628, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2), (long)(v4), (long)(v5))

#if defined(L1_CATCHER)
	#define L1SM_DBG_TP_C(v1, v2, v3, v4, v5) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x3728, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2), (long)(v4), (long)(v5));\
	} while(0)
#else
	#define L1SM_DBG_TP_C(v1, v2, v3, v4, v5)
#endif
#define L1SM_DBG_TP_C_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_2S(0x3728, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2), (long)(v4), (long)(v5))

#if defined(L1_CATCHER)
	#define L1SM_DBG_Timing_Profile_Best_Region(v1, v2, v3) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3828, (unsigned short)(v1)), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define L1SM_DBG_Timing_Profile_Best_Region(v1, v2, v3)
#endif
#define L1SM_DBG_Timing_Profile_Best_Region_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3828, (unsigned short)(v1)), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define L1SM_DBG_Timing_Profile_Worst_Region(v1, v2, v3) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3928, (unsigned short)(v1)), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define L1SM_DBG_Timing_Profile_Worst_Region(v1, v2, v3)
#endif
#define L1SM_DBG_Timing_Profile_Worst_Region_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3928, (unsigned short)(v1)), (long)(v2), (long)(v3))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char L1SM_1_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_L1SM_DBG_CALI_START(void);
void L1TRC_Send_L1SM_DBG_CALI_DONE(unsigned long v1, unsigned long v2);
void L1TRC_Send_L1SM_DBG_3G_PASS_2G(unsigned long v1, unsigned long v2);
void L1TRC_Send_L1SM_DBG_SW_WAKEUP(unsigned char v1);
void L1TRC_Send_L1SM_DBG_CAL_SLEEP(unsigned long v1, unsigned long v2, unsigned short v3, unsigned long v4);
void L1TRC_Send_L1SM_DBG_CAL_HW_SLEEP(unsigned short v1, unsigned short v2);
void L1TRC_Send_L1SM_DBG_CHECK_SLEEP_F(unsigned long v1, unsigned short v2);
void L1TRC_Send_L1SM_DBG_CHECK_HW_DEBOUNCE(unsigned long v1);
void L1TRC_Send_L1SM_DBG_CHECK_SLEEP_C(unsigned char v1, unsigned char v2, unsigned short v3, unsigned short v4, unsigned char v5);
void L1TRC_Send_L1SM_DBG_CHECK_SLEEP_TASK(unsigned long v1);
void L1TRC_Send_L1SM_DBG_CHECK_SLEEP_OS(unsigned char v1, short v2, unsigned char v3, short v4);
void L1TRC_Send_L1SM_DBG_BEFORE_SLEEP(unsigned short v1, unsigned short v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_L1SM_DBG_SLEEP_FRC(unsigned char v1, unsigned long v2, unsigned char v3, unsigned long v4);
void L1TRC_Send_L1SM_TRC_DEBUG(unsigned short v1, long v2, long v3);
void L1TRC_Send_L1SM_TRC_DEBUG_HEX(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_L1SM_DBG_CHECK_SM_CALLER(unsigned long v1, unsigned char v2, short v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_L1SM_DBG_CHECK_SM_LOCKER(short v1, unsigned long v2);
void L1TRC_Send_DUAL_OS_TICK_2G_COMMON(unsigned long v1, unsigned long v2);
void L1TRC_Send_DUAL_OS_TICK_2G_RECOVER(unsigned short v1);
void L1TRC_Send_DUAL_OS_TICK_INITIAL(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_DUAL_OS_TICK_3G_COMMON(unsigned long v1, unsigned long v2);
void L1TRC_Send_DUAL_OS_TICK_3G_RECOVER(unsigned short v1);
void L1TRC_Send_DUAL_OS_TICK_3G_DBG(unsigned char v1, unsigned char v2);
void L1TRC_Send_OSTD_TRC_DEBUG1(unsigned short v1, long v2, long v3);
void L1TRC_Send_OSTD_TRC_DEBUG2(unsigned short v1, long v2, long v3);
void L1TRC_Send_OSTD_SM_STATUS(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8);
void L1TRC_Send_OSTD_DBG_COCLK_UPDATE_FMRESULT(unsigned short v1, unsigned long v2, long v3, unsigned long v4);
void L1TRC_Send_OSTD_TRC_CALIBRATION(unsigned short v1, long v2, long v3);
void L1TRC_Send_OSTD_TRC_INF_SLEEP_TRG(void);
void L1TRC_Send_OSTD_TRC_INF_SLEEP_TIMER_CB(unsigned char v1, unsigned char v2);
void L1TRC_Send_DUAL_OS_TICK_ReSync(void);
void L1TRC_Send_DUAL_OS_RTC(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, long v5, unsigned short v6, unsigned long v7, unsigned long v8, unsigned char v9, unsigned char v10, unsigned short v11, unsigned long v12);
void L1TRC_Send_L1SM_Trace_SW1(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_L1SM_Trace_SW2(short v1);
void L1TRC_Send_L1SM_Trace_SW3(unsigned long v1);
void L1TRC_Send_L1SM_Trace_SW4(unsigned char v1, unsigned long v2, unsigned long v3, unsigned char v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_L1SM_Trace_SW5(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_L1SM_DBG_R_32K_UPDATE(unsigned long v1, unsigned long v2);
void L1TRC_Send_L1I_Msg_AvgTAC(unsigned char v1, short v2);
void L1TRC_Send_L1SM_DBG_32KLESS_WAKEUP(unsigned short v1, unsigned short v2);
void L1TRC_Send_L1SM_DBG_32KLESS_FORCE_REPORT(void);
void L1TRC_Send_L1SM_DBG_STABLE_PARAM(short v1, short v2, short v3, short v4);
void L1TRC_Send_L1SM_DBG_32KLESS_UPDATE_LPM(short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned char v5, unsigned char v6);
void L1TRC_Send_DCXO_DIV_DBG_UPDATE_R32K(unsigned char v1, unsigned char v2, unsigned char v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_DCXO_DIV_DBG_ENTER_26MHz_FPM(unsigned char v1, unsigned char v2, short v3);
void L1TRC_Send_DCXO_DIV_DBG_UPDATE(unsigned short v1, long v2, short v3);
void L1TRC_Send_DCXO_DIV_DBG_Check(unsigned short v1, long v2);
void L1TRC_Send_DCXO_DIV_DBG_UPDATE_UNLOCK(unsigned char v1, unsigned short v2, long v3, short v4);
void L1TRC_Send_DCXO_DIV_LPM_CNT_UPDATE(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_DCXO_DIV_LPM_CNT_END(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_DCXO_DIV_LPM_CNT_END_Delay(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_DCXO_DIV_PCM_CNT(unsigned long v1, unsigned long v2);
void L1TRC_Send_L1SM_DBG_Timing_Profile(unsigned short v1, long v2, long v3, long v4, long v5, long v6);
void L1TRC_Send_L1SM_DBG_TP_A(unsigned short v1, long v2, unsigned short v3, long v4);
void L1TRC_Send_L1SM_DBG_TP_B(unsigned short v1, long v2, unsigned short v3, long v4, long v5);
void L1TRC_Send_L1SM_DBG_TP_C(unsigned short v1, long v2, unsigned short v3, long v4, long v5);
void L1TRC_Send_L1SM_DBG_Timing_Profile_Best_Region(unsigned short v1, long v2, long v3);
void L1TRC_Send_L1SM_DBG_Timing_Profile_Worst_Region(unsigned short v1, long v2, long v3);

void Set_L1SM_1_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_L1SM_1()	(L1SM_1_Trace_Filter[0]==1)
#define ChkL1ClsFltr_L1SM_1_GSM_SM_M()	(ChkL1ModFltr_L1SM_1()&&((L1SM_1_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_L1SM_1_GSM_SM_L()	(ChkL1ModFltr_L1SM_1()&&((L1SM_1_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_L1SM_1_SM_LOCKER_H()	(ChkL1ModFltr_L1SM_1()&&((L1SM_1_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_L1SM_1_DUAL_OS_L()	(ChkL1ModFltr_L1SM_1()&&((L1SM_1_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_L1SM_1_DUAL_OS_DBG_H()	(ChkL1ModFltr_L1SM_1()&&((L1SM_1_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_L1SM_1_OSTD_DBG_L()	(ChkL1ModFltr_L1SM_1()&&((L1SM_1_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_L1SM_1_OSTD_SM_H()	(ChkL1ModFltr_L1SM_1()&&((L1SM_1_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_L1SM_1_GSM_SM_H()	(ChkL1ModFltr_L1SM_1()&&((L1SM_1_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_L1SM_1_GSM_32K_H()	(ChkL1ModFltr_L1SM_1()&&((L1SM_1_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_L1SM_1_GSM_32K_M()	(ChkL1ModFltr_L1SM_1()&&((L1SM_1_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_L1SM_1_OSTD_IS_H()	(ChkL1ModFltr_L1SM_1()&&((L1SM_1_Trace_Filter[2]&0x04)!=0))
#define ChkL1MsgFltr_L1SM_DBG_CALI_START()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_CALI_DONE()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_3G_PASS_2G()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_SW_WAKEUP()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_CAL_SLEEP()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_CAL_HW_SLEEP()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_CHECK_SLEEP_F()	ChkL1ClsFltr_L1SM_1_GSM_SM_L()
#define ChkL1MsgFltr_L1SM_DBG_CHECK_HW_DEBOUNCE()	ChkL1ClsFltr_L1SM_1_GSM_SM_L()
#define ChkL1MsgFltr_L1SM_DBG_CHECK_SLEEP_C()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_CHECK_SLEEP_TASK()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_CHECK_SLEEP_OS()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_BEFORE_SLEEP()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_SLEEP_FRC()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_TRC_DEBUG()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_TRC_DEBUG_HEX()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_CHECK_SM_CALLER()	ChkL1ClsFltr_L1SM_1_SM_LOCKER_H()
#define ChkL1MsgFltr_L1SM_DBG_CHECK_SM_LOCKER()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_DUAL_OS_TICK_2G_COMMON()	ChkL1ClsFltr_L1SM_1_DUAL_OS_L()
#define ChkL1MsgFltr_DUAL_OS_TICK_2G_RECOVER()	ChkL1ClsFltr_L1SM_1_DUAL_OS_L()
#define ChkL1MsgFltr_DUAL_OS_TICK_INITIAL()	ChkL1ClsFltr_L1SM_1_DUAL_OS_L()
#define ChkL1MsgFltr_DUAL_OS_TICK_3G_COMMON()	ChkL1ClsFltr_L1SM_1_DUAL_OS_L()
#define ChkL1MsgFltr_DUAL_OS_TICK_3G_RECOVER()	ChkL1ClsFltr_L1SM_1_DUAL_OS_L()
#define ChkL1MsgFltr_DUAL_OS_TICK_3G_DBG()	ChkL1ClsFltr_L1SM_1_DUAL_OS_L()
#define ChkL1MsgFltr_OSTD_TRC_DEBUG1()	ChkL1ClsFltr_L1SM_1_OSTD_DBG_L()
#define ChkL1MsgFltr_OSTD_TRC_DEBUG2()	ChkL1ClsFltr_L1SM_1_OSTD_DBG_L()
#define ChkL1MsgFltr_OSTD_SM_STATUS()	ChkL1ClsFltr_L1SM_1_OSTD_SM_H()
#define ChkL1MsgFltr_OSTD_DBG_COCLK_UPDATE_FMRESULT()	ChkL1ClsFltr_L1SM_1_OSTD_SM_H()
#define ChkL1MsgFltr_OSTD_TRC_CALIBRATION()	ChkL1ClsFltr_L1SM_1_OSTD_SM_H()
#define ChkL1MsgFltr_OSTD_TRC_INF_SLEEP_TRG()	ChkL1ClsFltr_L1SM_1_OSTD_IS_H()
#define ChkL1MsgFltr_OSTD_TRC_INF_SLEEP_TIMER_CB()	ChkL1ClsFltr_L1SM_1_OSTD_IS_H()
#define ChkL1MsgFltr_DUAL_OS_TICK_ReSync()	ChkL1ClsFltr_L1SM_1_DUAL_OS_DBG_H()
#define ChkL1MsgFltr_DUAL_OS_RTC()	ChkL1ClsFltr_L1SM_1_DUAL_OS_L()
#define ChkL1MsgFltr_L1SM_Trace_SW1()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_Trace_SW2()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_Trace_SW3()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_Trace_SW4()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_Trace_SW5()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_R_32K_UPDATE()	ChkL1ClsFltr_L1SM_1_GSM_32K_H()
#define ChkL1MsgFltr_L1I_Msg_AvgTAC()	ChkL1ClsFltr_L1SM_1_GSM_32K_H()
#define ChkL1MsgFltr_L1SM_DBG_32KLESS_WAKEUP()	ChkL1ClsFltr_L1SM_1_GSM_32K_H()
#define ChkL1MsgFltr_L1SM_DBG_32KLESS_FORCE_REPORT()	ChkL1ClsFltr_L1SM_1_GSM_32K_M()
#define ChkL1MsgFltr_L1SM_DBG_STABLE_PARAM()	ChkL1ClsFltr_L1SM_1_GSM_32K_M()
#define ChkL1MsgFltr_L1SM_DBG_32KLESS_UPDATE_LPM()	ChkL1ClsFltr_L1SM_1_GSM_32K_H()
#define ChkL1MsgFltr_DCXO_DIV_DBG_UPDATE_R32K()	ChkL1ClsFltr_L1SM_1_GSM_32K_H()
#define ChkL1MsgFltr_DCXO_DIV_DBG_ENTER_26MHz_FPM()	ChkL1ClsFltr_L1SM_1_GSM_32K_M()
#define ChkL1MsgFltr_DCXO_DIV_DBG_UPDATE()	ChkL1ClsFltr_L1SM_1_GSM_32K_H()
#define ChkL1MsgFltr_DCXO_DIV_DBG_Check()	ChkL1ClsFltr_L1SM_1_GSM_32K_H()
#define ChkL1MsgFltr_DCXO_DIV_DBG_UPDATE_UNLOCK()	ChkL1ClsFltr_L1SM_1_GSM_32K_H()
#define ChkL1MsgFltr_DCXO_DIV_LPM_CNT_UPDATE()	ChkL1ClsFltr_L1SM_1_GSM_32K_H()
#define ChkL1MsgFltr_DCXO_DIV_LPM_CNT_END()	ChkL1ClsFltr_L1SM_1_GSM_32K_H()
#define ChkL1MsgFltr_DCXO_DIV_LPM_CNT_END_Delay()	ChkL1ClsFltr_L1SM_1_GSM_32K_H()
#define ChkL1MsgFltr_DCXO_DIV_PCM_CNT()	ChkL1ClsFltr_L1SM_1_GSM_32K_H()
#define ChkL1MsgFltr_L1SM_DBG_Timing_Profile()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_TP_A()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_TP_B()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_TP_C()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_Timing_Profile_Best_Region()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_Timing_Profile_Worst_Region()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()


#endif
