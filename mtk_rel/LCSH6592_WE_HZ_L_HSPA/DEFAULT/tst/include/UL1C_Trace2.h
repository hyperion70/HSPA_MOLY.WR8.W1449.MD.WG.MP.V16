#ifndef L1TRC_UL1C_PRI2_DEF_H
#define L1TRC_UL1C_PRI2_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define UL1I_TRC_CTCH_Start(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x001C, (short)(v1)), TRC_MERGE_2S((short)(v3), (short)(v4)), (long)(v2));\
	} while(0)
#else
	#define UL1I_TRC_CTCH_Start(v1, v2, v3, v4)
#endif
#define UL1I_TRC_CTCH_Start_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x001C, (short)(v1)), TRC_MERGE_2S((short)(v3), (short)(v4)), (long)(v2))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CTCH_Next_L1(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x011C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1I_TRC_CTCH_Next_L1(v1, v2, v3)
#endif
#define UL1I_TRC_CTCH_Next_L1_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x011C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CTCH_BS_Start(v1, v2, v3, v4, v5, v6) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x021C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v5), (short)(v6)), (long)(v4));\
	} while(0)
#else
	#define UL1I_TRC_CTCH_BS_Start(v1, v2, v3, v4, v5, v6)
#endif
#define UL1I_TRC_CTCH_BS_Start_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x021C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v5), (short)(v6)), (long)(v4))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CTCH_Rx_Status(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x031C, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CTCH_Rx_Status(v1, v2)
#endif
#define UL1I_TRC_CTCH_Rx_Status_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x031C, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CTCH_L2_BP(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x041C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v4)), (long)(v3));\
	} while(0)
#else
	#define UL1I_TRC_CTCH_L2_BP(v1, v2, v3, v4)
#endif
#define UL1I_TRC_CTCH_L2_BP_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x041C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v4)), (long)(v3))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Timer(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x051C, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_Timer(v1, v2, v3)
#endif
#define UL1I_TRC_Timer_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x051C, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_LeaveConfig(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x061C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_LeaveConfig(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1I_TRC_LeaveConfig_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_5_DATA(TRC_MERGE_2S(0x061C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_EnterConfig(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x071C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1I_TRC_EnterConfig(v1, v2, v3)
#endif
#define UL1I_TRC_EnterConfig_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x071C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_AbortConfig(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x081C, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_AbortConfig(v1)
#endif
#define UL1I_TRC_AbortConfig_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x081C, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SuspendCNF(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x091C, (short)(v3)), TRC_MERGE_4C((char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_SuspendCNF(v1, v2, v3)
#endif
#define UL1I_TRC_SuspendCNF_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x091C, (short)(v3)), TRC_MERGE_4C((char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_BCH_CCM_SIB_STATUS(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0A1C, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_BCH_CCM_SIB_STATUS(v1, v2)
#endif
#define UL1I_TRC_BCH_CCM_SIB_STATUS_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0A1C, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_BCH_CCM_SFN_STATUS(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0B1C, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_BCH_CCM_SFN_STATUS(v1, v2)
#endif
#define UL1I_TRC_BCH_CCM_SFN_STATUS_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0B1C, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_EnterMode(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0C1C, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_EnterMode(v1)
#endif
#define UL1I_TRC_EnterMode_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0C1C, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_EnterDCH(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x0D1C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v5)), TRC_MERGE_1S2C((short)(v10), (char)(v3), (char)(v6)), TRC_MERGE_4C((char)(v7), (char)(v8), (char)(v9), TRC_BOXSTER_PAD), (long)(v4));\
	} while(0)
#else
	#define UL1I_TRC_EnterDCH(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define UL1I_TRC_EnterDCH_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_5_DATA(TRC_MERGE_2S(0x0D1C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v5)), TRC_MERGE_1S2C((short)(v10), (char)(v3), (char)(v6)), TRC_MERGE_4C((char)(v7), (char)(v8), (char)(v9), TRC_BOXSTER_PAD), (long)(v4))

#if defined(L1_CATCHER)
	#define UL1I_TRC_EnterPCH(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0E1C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v5)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v4));\
	} while(0)
#else
	#define UL1I_TRC_EnterPCH(v1, v2, v3, v4, v5)
#endif
#define UL1I_TRC_EnterPCH_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0E1C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v5)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v4))

#if defined(L1_CATCHER)
	#define UL1I_TRC_EnterFACH(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0F1C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v5)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v4));\
	} while(0)
#else
	#define UL1I_TRC_EnterFACH(v1, v2, v3, v4, v5)
#endif
#define UL1I_TRC_EnterFACH_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0F1C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v5)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v4))

#if defined(L1_CATCHER)
	#define UL1I_TRC_EnterNull(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x101C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_EnterNull(v1, v2, v3)
#endif
#define UL1I_TRC_EnterNull_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x101C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CCM_SetFN(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x111C, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_CCM_SetFN(v1)
#endif
#define UL1I_TRC_CCM_SetFN_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x111C, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_StartDLDCH(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x121C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_StartDLDCH(v1, v2)
#endif
#define UL1I_TRC_StartDLDCH_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x121C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_TTI(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x131C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_TTI(v1, v2)
#endif
#define UL1I_TRC_TTI_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x131C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CCM_State(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x141C, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CCM_State(v1)
#endif
#define UL1I_TRC_CCM_State_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x141C, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_SFN_Stop() do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x151C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_SFN_Stop()
#endif
#define UL1T_TRC_SFN_Stop_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x151C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_SFN_Start(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x161C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3));\
	} while(0)
#else
	#define UL1T_TRC_SFN_Start(v1, v2, v3)
#endif
#define UL1T_TRC_SFN_Start_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x161C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SFN_Rx(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x171C, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_SFN_Rx(v1, v2)
#endif
#define UL1I_TRC_SFN_Rx_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x171C, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SFN_State(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x181C, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_SFN_State(v1)
#endif
#define UL1I_TRC_SFN_State_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x181C, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_SFN_Data(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x191C, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_SFN_Data(v1, v2)
#endif
#define UL1T_TRC_SFN_Data_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x191C, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SFN_Report(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1A1C, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_SFN_Report(v1, v2, v3)
#endif
#define UL1I_TRC_SFN_Report_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1A1C, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SFN_InternalStop(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1B1C, (short)(v3)), TRC_MERGE_4C((char)(v1), (char)(v2), (char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_SFN_InternalStop(v1, v2, v3, v4)
#endif
#define UL1I_TRC_SFN_InternalStop_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1B1C, (short)(v3)), TRC_MERGE_4C((char)(v1), (char)(v2), (char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SFN_Compensation(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1C1C, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_SFN_Compensation(v1)
#endif
#define UL1I_TRC_SFN_Compensation_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1C1C, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SFN_Avail_Dec_Frms(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1D1C, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_SFN_Avail_Dec_Frms(v1)
#endif
#define UL1I_TRC_SFN_Avail_Dec_Frms_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1D1C, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_SIB_Start(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x1E1C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v6)), TRC_MERGE_4C((char)(v7), (char)(v8), (char)(v9), TRC_BOXSTER_PAD), (long)(v5));\
	} while(0)
#else
	#define UL1T_TRC_SIB_Start(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define UL1T_TRC_SIB_Start_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_5_DATA(TRC_MERGE_2S(0x1E1C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v6)), TRC_MERGE_4C((char)(v7), (char)(v8), (char)(v9), TRC_BOXSTER_PAD), (long)(v5))

#if defined(L1_CATCHER)
	#define UL1T_TRC_SIB_Reconfig(v1, v2, v3, v4, v5, v6) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1F1C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (char)(v3), (char)(v4)), TRC_MERGE_4C((char)(v5), (char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_SIB_Reconfig(v1, v2, v3, v4, v5, v6)
#endif
#define UL1T_TRC_SIB_Reconfig_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1F1C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (char)(v3), (char)(v4)), TRC_MERGE_4C((char)(v5), (char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SIB_Rx(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x201C, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_SIB_Rx(v1)
#endif
#define UL1I_TRC_SIB_Rx_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x201C, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SIB_State(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x211C, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_SIB_State(v1)
#endif
#define UL1I_TRC_SIB_State_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x211C, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SIB_Rpt(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x221C, (short)(v1)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_SIB_Rpt(v1, v2)
#endif
#define UL1I_TRC_SIB_Rpt_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x221C, (short)(v1)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_SIB_CM(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x231C, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_1S2C((short)(v5), (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_SIB_CM(v1, v2, v3, v4, v5)
#endif
#define UL1T_TRC_SIB_CM_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x231C, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_1S2C((short)(v5), (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1T_TRC_ConfigBAList(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x241C, (short)(v4)), TRC_MERGE_4C((char)(v1), (char)(v2), (char)(v3), (char)(v5)), TRC_MERGE_4C((char)(v6), (char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_ConfigBAList(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1T_TRC_ConfigBAList_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_3_DATA(TRC_MERGE_2S(0x241C, (short)(v4)), TRC_MERGE_4C((char)(v1), (char)(v2), (char)(v3), (char)(v5)), TRC_MERGE_4C((char)(v6), (char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CellInfo(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x251C, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3));\
	} while(0)
#else
	#define UL1T_TRC_CellInfo(v1, v2, v3)
#endif
#define UL1T_TRC_CellInfo_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x251C, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CellInfo_1(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x261C, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_CellInfo_1(v1, v2, v3, v4)
#endif
#define UL1T_TRC_CellInfo_1_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x261C, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_ConfigDetectedCell(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x271C, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1T_TRC_ConfigDetectedCell(v1, v2)
#endif
#define UL1T_TRC_ConfigDetectedCell_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x271C, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1T_TRC_BA_Mapping(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x281C, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), (char)(v8), (char)(v9), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_BA_Mapping(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define UL1T_TRC_BA_Mapping_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x281C, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), (char)(v8), (char)(v9), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CM_Alloc_CMM_Report(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x291C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1T_TRC_CM_Alloc_CMM_Report(v1, v2, v3)
#endif
#define UL1T_TRC_CM_Alloc_CMM_Report_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x291C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CM_DCH_1st_Tick(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2A1C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1T_TRC_CM_DCH_1st_Tick(v1, v2, v3)
#endif
#define UL1T_TRC_CM_DCH_1st_Tick_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2A1C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CM_Prepare_BA_status(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2B1C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1T_TRC_CM_Prepare_BA_status(v1, v2, v3)
#endif
#define UL1T_TRC_CM_Prepare_BA_status_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2B1C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CM_DeleteBA(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2C1C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1T_TRC_CM_DeleteBA(v1, v2, v3)
#endif
#define UL1T_TRC_CM_DeleteBA_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2C1C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CM_Protected_in_DCH(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2D1C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1T_TRC_CM_Protected_in_DCH(v1, v2, v3)
#endif
#define UL1T_TRC_CM_Protected_in_DCH_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2D1C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CM_EvaluateReq(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2E1C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1T_TRC_CM_EvaluateReq(v1, v2, v3)
#endif
#define UL1T_TRC_CM_EvaluateReq_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2E1C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CM_Trigger_EnhancedCM(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2F1C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1T_TRC_CM_Trigger_EnhancedCM(v1, v2, v3)
#endif
#define UL1T_TRC_CM_Trigger_EnhancedCM_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2F1C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CM_DetectedCell_InvalidTM(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x301C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1T_TRC_CM_DetectedCell_InvalidTM(v1, v2, v3)
#endif
#define UL1T_TRC_CM_DetectedCell_InvalidTM_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x301C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CM_freq_not_existed(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x311C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1T_TRC_CM_freq_not_existed(v1, v2, v3)
#endif
#define UL1T_TRC_CM_freq_not_existed_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x311C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CM_ConfigBA_by_CCM(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x321C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1T_TRC_CM_ConfigBA_by_CCM(v1, v2, v3)
#endif
#define UL1T_TRC_CM_ConfigBA_by_CCM_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x321C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CM_Restore_CM_result(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x331C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1T_TRC_CM_Restore_CM_result(v1, v2, v3)
#endif
#define UL1T_TRC_CM_Restore_CM_result_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x331C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CM_Compensate_CMCS(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x341C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1T_TRC_CM_Compensate_CMCS(v1, v2, v3)
#endif
#define UL1T_TRC_CM_Compensate_CMCS_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x341C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CM_AlarmTimeoutForInterF(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x351C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1T_TRC_CM_AlarmTimeoutForInterF(v1, v2, v3)
#endif
#define UL1T_TRC_CM_AlarmTimeoutForInterF_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x351C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CM_BANum_Err_in_FACH(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x361C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CM_BANum_Err_in_FACH(v1, v2)
#endif
#define UL1I_TRC_CM_BANum_Err_in_FACH_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x361C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CM_BANum_Err_in_NULL(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x371C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CM_BANum_Err_in_NULL(v1, v2)
#endif
#define UL1I_TRC_CM_BANum_Err_in_NULL_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x371C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CMHalt(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x381C, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_CMHalt(v1)
#endif
#define UL1I_TRC_CMHalt_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x381C, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_ConfigCell(v1, v2, v3, v4, v5, v6) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x391C, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_1S2C((short)(v6), (char)(v1), TRC_BOXSTER_PAD), (long)(v5));\
	} while(0)
#else
	#define UL1T_TRC_ConfigCell(v1, v2, v3, v4, v5, v6)
#endif
#define UL1T_TRC_ConfigCell_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x391C, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_1S2C((short)(v6), (char)(v1), TRC_BOXSTER_PAD), (long)(v5))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CMResult(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3A1C, (unsigned short)(v3)), TRC_MERGE_1S2C((short)(v4), (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_CMResult(v1, v2, v3, v4)
#endif
#define UL1I_TRC_CMResult_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3A1C, (unsigned short)(v3)), TRC_MERGE_1S2C((short)(v4), (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CMResult_RXD(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3B1C, (unsigned short)(v3)), TRC_MERGE_1S2C((short)(v4), (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_CMResult_RXD(v1, v2, v3, v4)
#endif
#define UL1I_TRC_CMResult_RXD_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3B1C, (unsigned short)(v3)), TRC_MERGE_1S2C((short)(v4), (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CMDone(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3C1C, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CMDone(v1, v2, v3)
#endif
#define UL1I_TRC_CMDone_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3C1C, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CMStart(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3D1C, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_CMStart(v1)
#endif
#define UL1T_TRC_CMStart_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3D1C, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_PrioCMCS(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3E1C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_PrioCMCS(v1, v2, v3)
#endif
#define UL1I_TRC_PrioCMCS_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3E1C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CMStart(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3F1C, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_CMStart(v1, v2)
#endif
#define UL1I_TRC_CMStart_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3F1C, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CMStop(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x401C, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_CMStop(v1)
#endif
#define UL1T_TRC_CMStop_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x401C, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CMReportStop() do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x411C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_CMReportStop()
#endif
#define UL1T_TRC_CMReportStop_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x411C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CMStop(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x421C, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_CMStop(v1, v2)
#endif
#define UL1I_TRC_CMStop_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x421C, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1T_TRC_CMAlphaFilter(v1, v2, v3, v4, v5, v6) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x431C, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_CMAlphaFilter(v1, v2, v3, v4, v5, v6)
#endif
#define UL1T_TRC_CMAlphaFilter_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x431C, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CMReport(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x441C, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_CMReport(v1, v2, v3)
#endif
#define UL1T_TRC_CMReport_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x441C, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CMAverager(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x451C, (short)(v3)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_1S2C((short)(v7), (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_CMAverager(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1T_TRC_CMAverager_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x451C, (short)(v3)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_1S2C((short)(v7), (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CMAverager_RXD(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x461C, (short)(v3)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_1S2C((short)(v7), (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_CMAverager_RXD(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1T_TRC_CMAverager_RXD_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x461C, (short)(v3)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_1S2C((short)(v7), (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CMAverager_MAX(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x471C, (short)(v3)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_1S2C((short)(v7), (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_CMAverager_MAX(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1T_TRC_CMAverager_MAX_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x471C, (short)(v3)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_1S2C((short)(v7), (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CMAverager2(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x481C, (short)(v3)), TRC_MERGE_4C((char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_CMAverager2(v1, v2, v3)
#endif
#define UL1T_TRC_CMAverager2_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x481C, (short)(v3)), TRC_MERGE_4C((char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CMAverager2_RXD(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x491C, (short)(v3)), TRC_MERGE_4C((char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_CMAverager2_RXD(v1, v2, v3)
#endif
#define UL1T_TRC_CMAverager2_RXD_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x491C, (short)(v3)), TRC_MERGE_4C((char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_CMAVG_Put(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4A1C, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CMAVG_Put(v1, v2, v3)
#endif
#define UL1I_TRC_CMAVG_Put_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4A1C, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_CMAVG_Apply(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4B1C, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_CMAVG_Apply(v1, v2)
#endif
#define UL1I_TRC_CMAVG_Apply_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4B1C, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_CMAVG_Apply_RXD(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4C1C, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_CMAVG_Apply_RXD(v1, v2)
#endif
#define UL1I_TRC_CMAVG_Apply_RXD_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4C1C, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1T_TRC_CMAVG_LINValue(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4D1C, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_CMAVG_LINValue(v1, v2, v3)
#endif
#define UL1T_TRC_CMAVG_LINValue_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4D1C, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1T_TRC_CMAVG_DBG(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4E1C, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_CMAVG_DBG(v1)
#endif
#define UL1T_TRC_CMAVG_DBG_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4E1C, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1_TRC_CMTreselection(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4F1C, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1_TRC_CMTreselection(v1, v2)
#endif
#define UL1_TRC_CMTreselection_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4F1C, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CSDone(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x501C, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_CSDone(v1, v2)
#endif
#define UL1I_TRC_CSDone_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x501C, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_CSResult(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x511C, (short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CSResult(v1, v2, v3)
#endif
#define UL1I_TRC_CSResult_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x511C, (short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CSStart(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x521C, (short)(v2)), TRC_MERGE_4C((char)(v1), (char)(v3), (char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CSStart(v1, v2, v3, v4)
#endif
#define UL1I_TRC_CSStart_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x521C, (short)(v2)), TRC_MERGE_4C((char)(v1), (char)(v3), (char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CS_Stop(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x531C, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CS_Stop(v1)
#endif
#define UL1I_TRC_CS_Stop_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x531C, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Unlock_gapStopCnf(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x541C, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_Unlock_gapStopCnf(v1)
#endif
#define UL1I_TRC_Unlock_gapStopCnf_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x541C, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_DMStopGap() do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x551C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_DMStopGap()
#endif
#define UL1T_TRC_DMStopGap_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x551C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_DM_SetGap(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x561C, (short)(v6)), TRC_MERGE_4C((char)(v4), (char)(v5), (char)(v7), (char)(v8)), TRC_MERGE_4C((char)(v9), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define UL1T_TRC_DM_SetGap(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define UL1T_TRC_DM_SetGap_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_6_DATA(TRC_MERGE_2S(0x561C, (short)(v6)), TRC_MERGE_4C((char)(v4), (char)(v5), (char)(v7), (char)(v8)), TRC_MERGE_4C((char)(v9), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define UL1T_TRC_DM_DRXTick(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x571C, (short)(v2)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_4C((char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_DM_DRXTick(v1, v2, v3, v4, v5)
#endif
#define UL1T_TRC_DM_DRXTick_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x571C, (short)(v2)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_4C((char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_DM_SetGSM_Mode(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x581C, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_DM_SetGSM_Mode(v1)
#endif
#define UL1T_TRC_DM_SetGSM_Mode_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x581C, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DM_AssignGAP(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x591C, (short)(v1)), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define UL1I_TRC_DM_AssignGAP(v1, v2, v3)
#endif
#define UL1I_TRC_DM_AssignGAP_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x591C, (short)(v1)), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Start_GAP_Timer1(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x5A1C, (short)(v2)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v3), (long)(v5));\
	} while(0)
#else
	#define UL1I_TRC_Start_GAP_Timer1(v1, v2, v3, v4, v5)
#endif
#define UL1I_TRC_Start_GAP_Timer1_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_2S(0x5A1C, (short)(v2)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v3), (long)(v5))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Start_GAP_Timer2(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x5B1C, (short)(v3)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define UL1I_TRC_Start_GAP_Timer2(v1, v2, v3)
#endif
#define UL1I_TRC_Start_GAP_Timer2_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x5B1C, (short)(v3)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DM_TimeSyncStart(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x5C1C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2));\
	} while(0)
#else
	#define UL1I_TRC_DM_TimeSyncStart(v1, v2)
#endif
#define UL1I_TRC_DM_TimeSyncStart_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x5C1C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2))

#if defined(L1_CATCHER)
	#define UL1T_TRC_DM_Cancel_ActiveGAP() do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5D1C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_DM_Cancel_ActiveGAP()
#endif
#define UL1T_TRC_DM_Cancel_ActiveGAP_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5D1C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DM_Cancel_2G_GAP_Cnf() do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5E1C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_DM_Cancel_2G_GAP_Cnf()
#endif
#define UL1I_TRC_DM_Cancel_2G_GAP_Cnf_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5E1C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DM_Query_GAP(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5F1C, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_DM_Query_GAP(v1, v2)
#endif
#define UL1I_TRC_DM_Query_GAP_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5F1C, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DM_Query_GAP_SM(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x601C, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_DM_Query_GAP_SM(v1, v2)
#endif
#define UL1I_TRC_DM_Query_GAP_SM_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x601C, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DM_Query_PSEUDO() do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x611C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_DM_Query_PSEUDO()
#endif
#define UL1I_TRC_DM_Query_PSEUDO_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x611C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DM_Sleep_Ind(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_2S(0x621C, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v9), (char)(v6), TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v7), (long)(v8));\
	} while(0)
#else
	#define UL1I_TRC_DM_Sleep_Ind(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define UL1I_TRC_DM_Sleep_Ind_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_7_DATA(TRC_MERGE_2S(0x621C, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v9), (char)(v6), TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v7), (long)(v8))

#if defined(L1_CATCHER)
	#define UL1I_TRC_RTB_Timer(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x631C, (short)(v2)), TRC_MERGE_4C((char)(v1), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3));\
	} while(0)
#else
	#define UL1I_TRC_RTB_Timer(v1, v2, v3, v4)
#endif
#define UL1I_TRC_RTB_Timer_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x631C, (short)(v2)), TRC_MERGE_4C((char)(v1), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3))

#if defined(L1_CATCHER)
	#define UL1I_TRC_AGPS_INFO(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x641C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define UL1I_TRC_AGPS_INFO(v1, v2, v3, v4, v5)
#endif
#define UL1I_TRC_AGPS_INFO_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x641C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_BAStatusUpdateInfo(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x651C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1T_TRC_BAStatusUpdateInfo(v1, v2, v3)
#endif
#define UL1T_TRC_BAStatusUpdateInfo_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x651C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CTCH_ADJUSTMENT_STATUS(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x661C, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CTCH_ADJUSTMENT_STATUS(v1)
#endif
#define UL1I_TRC_CTCH_ADJUSTMENT_STATUS_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x661C, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CTCH_ADJUSTMENT_SUSPEND(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x671C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CTCH_ADJUSTMENT_SUSPEND(v1, v2)
#endif
#define UL1I_TRC_CTCH_ADJUSTMENT_SUSPEND_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x671C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CTCH_Resume(v1, v2, v3, v4, v5, v6) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x681C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CTCH_Resume(v1, v2, v3, v4, v5, v6)
#endif
#define UL1I_TRC_CTCH_Resume_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x681C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char UL1C_PRI2_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_UL1I_TRC_CTCH_Start(short v1, long v2, short v3, short v4);
void L1TRC_Send_UL1I_TRC_CTCH_Next_L1(short v1, short v2, short v3);
void L1TRC_Send_UL1I_TRC_CTCH_BS_Start(short v1, short v2, short v3, long v4, short v5, short v6);
void L1TRC_Send_UL1I_TRC_CTCH_Rx_Status(char v1, short v2);
void L1TRC_Send_UL1I_TRC_CTCH_L2_BP(short v1, short v2, long v3, short v4);
void L1TRC_Send_UL1I_TRC_Timer(char v1, char v2, char v3);
void L1TRC_Send_UL1I_TRC_LeaveConfig(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8);
void L1TRC_Send_UL1I_TRC_EnterConfig(short v1, short v2, short v3);
void L1TRC_Send_UL1I_TRC_AbortConfig(char v1);
void L1TRC_Send_UL1I_TRC_SuspendCNF(char v1, char v2, short v3);
void L1TRC_Send_UL1I_TRC_BCH_CCM_SIB_STATUS(char v1, char v2);
void L1TRC_Send_UL1I_TRC_BCH_CCM_SFN_STATUS(char v1, char v2);
void L1TRC_Send_UL1I_TRC_EnterMode(char v1);
void L1TRC_Send_UL1I_TRC_EnterDCH(short v1, short v2, char v3, long v4, short v5, char v6, char v7, char v8, char v9, short v10);
void L1TRC_Send_UL1I_TRC_EnterPCH(short v1, short v2, char v3, long v4, short v5);
void L1TRC_Send_UL1I_TRC_EnterFACH(short v1, short v2, char v3, long v4, short v5);
void L1TRC_Send_UL1I_TRC_EnterNull(short v1, short v2, char v3);
void L1TRC_Send_UL1I_TRC_CCM_SetFN(short v1);
void L1TRC_Send_UL1I_TRC_StartDLDCH(short v1, short v2);
void L1TRC_Send_UL1I_TRC_TTI(short v1, short v2);
void L1TRC_Send_UL1I_TRC_CCM_State(char v1);
void L1TRC_Send_UL1T_TRC_SFN_Stop(void);
void L1TRC_Send_UL1T_TRC_SFN_Start(short v1, short v2, long v3);
void L1TRC_Send_UL1I_TRC_SFN_Rx(char v1, short v2);
void L1TRC_Send_UL1I_TRC_SFN_State(char v1);
void L1TRC_Send_UL1T_TRC_SFN_Data(char v1, short v2);
void L1TRC_Send_UL1I_TRC_SFN_Report(char v1, char v2, char v3);
void L1TRC_Send_UL1I_TRC_SFN_InternalStop(char v1, char v2, short v3, char v4);
void L1TRC_Send_UL1I_TRC_SFN_Compensation(char v1);
void L1TRC_Send_UL1I_TRC_SFN_Avail_Dec_Frms(short v1);
void L1TRC_Send_UL1T_TRC_SIB_Start(short v1, short v2, short v3, short v4, long v5, short v6, char v7, char v8, char v9);
void L1TRC_Send_UL1T_TRC_SIB_Reconfig(short v1, short v2, char v3, char v4, char v5, char v6);
void L1TRC_Send_UL1I_TRC_SIB_Rx(short v1);
void L1TRC_Send_UL1I_TRC_SIB_State(char v1);
void L1TRC_Send_UL1I_TRC_SIB_Rpt(short v1, char v2);
void L1TRC_Send_UL1T_TRC_SIB_CM(char v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_UL1T_TRC_ConfigBAList(char v1, char v2, char v3, short v4, char v5, char v6, char v7);
void L1TRC_Send_UL1T_TRC_CellInfo(char v1, short v2, long v3);
void L1TRC_Send_UL1T_TRC_CellInfo_1(char v1, char v2, char v3, char v4);
void L1TRC_Send_UL1T_TRC_ConfigDetectedCell(char v1, char v2);
void L1TRC_Send_UL1T_TRC_BA_Mapping(char v1, char v2, char v3, char v4, char v5, char v6, char v7, char v8, char v9);
void L1TRC_Send_UL1T_TRC_CM_Alloc_CMM_Report(short v1, short v2, short v3);
void L1TRC_Send_UL1T_TRC_CM_DCH_1st_Tick(short v1, short v2, short v3);
void L1TRC_Send_UL1T_TRC_CM_Prepare_BA_status(short v1, short v2, short v3);
void L1TRC_Send_UL1T_TRC_CM_DeleteBA(short v1, short v2, short v3);
void L1TRC_Send_UL1T_TRC_CM_Protected_in_DCH(short v1, short v2, short v3);
void L1TRC_Send_UL1T_TRC_CM_EvaluateReq(short v1, short v2, short v3);
void L1TRC_Send_UL1T_TRC_CM_Trigger_EnhancedCM(short v1, short v2, short v3);
void L1TRC_Send_UL1T_TRC_CM_DetectedCell_InvalidTM(short v1, short v2, short v3);
void L1TRC_Send_UL1T_TRC_CM_freq_not_existed(short v1, short v2, short v3);
void L1TRC_Send_UL1T_TRC_CM_ConfigBA_by_CCM(short v1, short v2, short v3);
void L1TRC_Send_UL1T_TRC_CM_Restore_CM_result(short v1, short v2, short v3);
void L1TRC_Send_UL1T_TRC_CM_Compensate_CMCS(short v1, short v2, short v3);
void L1TRC_Send_UL1T_TRC_CM_AlarmTimeoutForInterF(short v1, short v2, short v3);
void L1TRC_Send_UL1I_TRC_CM_BANum_Err_in_FACH(short v1, short v2);
void L1TRC_Send_UL1I_TRC_CM_BANum_Err_in_NULL(short v1, short v2);
void L1TRC_Send_UL1I_TRC_CMHalt(short v1);
void L1TRC_Send_UL1T_TRC_ConfigCell(char v1, short v2, short v3, short v4, long v5, short v6);
void L1TRC_Send_UL1I_TRC_CMResult(char v1, char v2, unsigned short v3, short v4);
void L1TRC_Send_UL1I_TRC_CMResult_RXD(char v1, char v2, unsigned short v3, short v4);
void L1TRC_Send_UL1I_TRC_CMDone(char v1, char v2, char v3);
void L1TRC_Send_UL1T_TRC_CMStart(char v1);
void L1TRC_Send_UL1I_TRC_PrioCMCS(short v1, short v2, char v3);
void L1TRC_Send_UL1I_TRC_CMStart(char v1, char v2);
void L1TRC_Send_UL1T_TRC_CMStop(char v1);
void L1TRC_Send_UL1T_TRC_CMReportStop(void);
void L1TRC_Send_UL1I_TRC_CMStop(char v1, char v2);
void L1TRC_Send_UL1T_TRC_CMAlphaFilter(char v1, short v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_UL1T_TRC_CMReport(char v1, char v2, char v3);
void L1TRC_Send_UL1T_TRC_CMAverager(char v1, char v2, short v3, char v4, short v5, short v6, short v7);
void L1TRC_Send_UL1T_TRC_CMAverager_RXD(char v1, char v2, short v3, char v4, short v5, short v6, short v7);
void L1TRC_Send_UL1T_TRC_CMAverager_MAX(char v1, char v2, short v3, char v4, short v5, short v6, short v7);
void L1TRC_Send_UL1T_TRC_CMAverager2(char v1, char v2, short v3);
void L1TRC_Send_UL1T_TRC_CMAverager2_RXD(char v1, char v2, short v3);
void L1TRC_Send_UL1I_TRC_CMAVG_Put(char v1, short v2, short v3);
void L1TRC_Send_UL1I_TRC_CMAVG_Apply(char v1, char v2);
void L1TRC_Send_UL1I_TRC_CMAVG_Apply_RXD(char v1, char v2);
void L1TRC_Send_UL1T_TRC_CMAVG_LINValue(char v1, char v2, char v3);
void L1TRC_Send_UL1T_TRC_CMAVG_DBG(char v1);
void L1TRC_Send_UL1_TRC_CMTreselection(char v1, char v2);
void L1TRC_Send_UL1I_TRC_CSDone(char v1, char v2);
void L1TRC_Send_UL1I_TRC_CSResult(char v1, short v2, unsigned short v3);
void L1TRC_Send_UL1I_TRC_CSStart(char v1, short v2, char v3, char v4);
void L1TRC_Send_UL1I_TRC_CS_Stop(char v1);
void L1TRC_Send_UL1I_TRC_Unlock_gapStopCnf(char v1);
void L1TRC_Send_UL1T_TRC_DMStopGap(void);
void L1TRC_Send_UL1T_TRC_DM_SetGap(long v1, long v2, long v3, char v4, char v5, short v6, char v7, char v8, char v9);
void L1TRC_Send_UL1T_TRC_DM_DRXTick(char v1, short v2, char v3, short v4, short v5);
void L1TRC_Send_UL1T_TRC_DM_SetGSM_Mode(char v1);
void L1TRC_Send_UL1I_TRC_DM_AssignGAP(short v1, long v2, long v3);
void L1TRC_Send_UL1I_TRC_Start_GAP_Timer1(long v1, short v2, long v3, short v4, long v5);
void L1TRC_Send_UL1I_TRC_Start_GAP_Timer2(char v1, long v2, short v3);
void L1TRC_Send_UL1I_TRC_DM_TimeSyncStart(long v1, long v2);
void L1TRC_Send_UL1T_TRC_DM_Cancel_ActiveGAP(void);
void L1TRC_Send_UL1I_TRC_DM_Cancel_2G_GAP_Cnf(void);
void L1TRC_Send_UL1I_TRC_DM_Query_GAP(char v1, short v2);
void L1TRC_Send_UL1I_TRC_DM_Query_GAP_SM(char v1, short v2);
void L1TRC_Send_UL1I_TRC_DM_Query_PSEUDO(void);
void L1TRC_Send_UL1I_TRC_DM_Sleep_Ind(long v1, long v2, short v3, short v4, short v5, char v6, long v7, long v8, short v9);
void L1TRC_Send_UL1I_TRC_RTB_Timer(char v1, short v2, long v3, char v4);
void L1TRC_Send_UL1I_TRC_AGPS_INFO(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_UL1T_TRC_BAStatusUpdateInfo(short v1, short v2, short v3);
void L1TRC_Send_UL1I_TRC_CTCH_ADJUSTMENT_STATUS(char v1);
void L1TRC_Send_UL1I_TRC_CTCH_ADJUSTMENT_SUSPEND(short v1, short v2);
void L1TRC_Send_UL1I_TRC_CTCH_Resume(short v1, short v2, short v3, short v4, short v5, short v6);

void Set_UL1C_PRI2_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_UL1C_PRI2()	(UL1C_PRI2_Trace_Filter[0]==1)
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_L()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_TIMER_L()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_SIB_L()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_SFN_L()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_CTCH_L()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_L()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_AVG_L()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_CS_L()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_L()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_RTB_L()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_M()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_TIMER_M()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[2]&0x08)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_SIB_M()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[2]&0x10)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_SFN_M()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[2]&0x20)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_CTCH_M()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[2]&0x40)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_M()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[2]&0x80)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_AVG_M()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[3]&0x01)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_CS_M()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[3]&0x02)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_M()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[3]&0x04)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_RTB_M()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[3]&0x08)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[3]&0x10)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_TIMER_H()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[3]&0x20)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_SIB_H()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[3]&0x40)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_SFN_H()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[3]&0x80)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_CTCH_H()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[4]&0x01)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[4]&0x02)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_AVG_H()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[4]&0x04)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_CS_H()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[4]&0x08)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[4]&0x10)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_RTB_H()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[4]&0x20)!=0))
#define ChkL1MsgFltr_UL1I_TRC_CTCH_Start()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CTCH_H()
#define ChkL1MsgFltr_UL1I_TRC_CTCH_Next_L1()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CTCH_H()
#define ChkL1MsgFltr_UL1I_TRC_CTCH_BS_Start()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CTCH_H()
#define ChkL1MsgFltr_UL1I_TRC_CTCH_Rx_Status()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CTCH_H()
#define ChkL1MsgFltr_UL1I_TRC_CTCH_L2_BP()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CTCH_H()
#define ChkL1MsgFltr_UL1I_TRC_Timer()	ChkL1ClsFltr_UL1C_PRI2_UL1C_TIMER_H()
#define ChkL1MsgFltr_UL1I_TRC_LeaveConfig()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_EnterConfig()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_AbortConfig()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_SuspendCNF()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_BCH_CCM_SIB_STATUS()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_BCH_CCM_SFN_STATUS()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_EnterMode()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_EnterDCH()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_EnterPCH()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_EnterFACH()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_EnterNull()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_CCM_SetFN()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_StartDLDCH()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_TTI()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_CCM_State()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1T_TRC_SFN_Stop()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SFN_H()
#define ChkL1MsgFltr_UL1T_TRC_SFN_Start()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SFN_H()
#define ChkL1MsgFltr_UL1I_TRC_SFN_Rx()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SFN_H()
#define ChkL1MsgFltr_UL1I_TRC_SFN_State()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SFN_H()
#define ChkL1MsgFltr_UL1T_TRC_SFN_Data()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SFN_H()
#define ChkL1MsgFltr_UL1I_TRC_SFN_Report()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SFN_H()
#define ChkL1MsgFltr_UL1I_TRC_SFN_InternalStop()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SFN_H()
#define ChkL1MsgFltr_UL1I_TRC_SFN_Compensation()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SFN_H()
#define ChkL1MsgFltr_UL1I_TRC_SFN_Avail_Dec_Frms()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SFN_H()
#define ChkL1MsgFltr_UL1T_TRC_SIB_Start()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SIB_H()
#define ChkL1MsgFltr_UL1T_TRC_SIB_Reconfig()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SIB_H()
#define ChkL1MsgFltr_UL1I_TRC_SIB_Rx()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SIB_H()
#define ChkL1MsgFltr_UL1I_TRC_SIB_State()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SIB_H()
#define ChkL1MsgFltr_UL1I_TRC_SIB_Rpt()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SIB_H()
#define ChkL1MsgFltr_UL1T_TRC_SIB_CM()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SIB_H()
#define ChkL1MsgFltr_UL1T_TRC_ConfigBAList()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_M()
#define ChkL1MsgFltr_UL1T_TRC_CellInfo()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CellInfo_1()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_ConfigDetectedCell()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_BA_Mapping()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_M()
#define ChkL1MsgFltr_UL1T_TRC_CM_Alloc_CMM_Report()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CM_DCH_1st_Tick()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CM_Prepare_BA_status()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CM_DeleteBA()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CM_Protected_in_DCH()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CM_EvaluateReq()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CM_Trigger_EnhancedCM()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CM_DetectedCell_InvalidTM()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CM_freq_not_existed()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CM_ConfigBA_by_CCM()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CM_Restore_CM_result()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CM_Compensate_CMCS()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CM_AlarmTimeoutForInterF()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1I_TRC_CM_BANum_Err_in_FACH()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1I_TRC_CM_BANum_Err_in_NULL()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1I_TRC_CMHalt()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_ConfigCell()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1I_TRC_CMResult()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1I_TRC_CMResult_RXD()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1I_TRC_CMDone()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CMStart()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1I_TRC_PrioCMCS()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1I_TRC_CMStart()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CMStop()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CMReportStop()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1I_TRC_CMStop()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CMAlphaFilter()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_L()
#define ChkL1MsgFltr_UL1T_TRC_CMReport()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CMAverager()	ChkL1ClsFltr_UL1C_PRI2_UL1C_AVG_H()
#define ChkL1MsgFltr_UL1T_TRC_CMAverager_RXD()	ChkL1ClsFltr_UL1C_PRI2_UL1C_AVG_H()
#define ChkL1MsgFltr_UL1T_TRC_CMAverager_MAX()	ChkL1ClsFltr_UL1C_PRI2_UL1C_AVG_H()
#define ChkL1MsgFltr_UL1T_TRC_CMAverager2()	ChkL1ClsFltr_UL1C_PRI2_UL1C_AVG_H()
#define ChkL1MsgFltr_UL1T_TRC_CMAverager2_RXD()	ChkL1ClsFltr_UL1C_PRI2_UL1C_AVG_H()
#define ChkL1MsgFltr_UL1I_TRC_CMAVG_Put()	ChkL1ClsFltr_UL1C_PRI2_UL1C_AVG_L()
#define ChkL1MsgFltr_UL1I_TRC_CMAVG_Apply()	ChkL1ClsFltr_UL1C_PRI2_UL1C_AVG_L()
#define ChkL1MsgFltr_UL1I_TRC_CMAVG_Apply_RXD()	ChkL1ClsFltr_UL1C_PRI2_UL1C_AVG_L()
#define ChkL1MsgFltr_UL1T_TRC_CMAVG_LINValue()	ChkL1ClsFltr_UL1C_PRI2_UL1C_AVG_L()
#define ChkL1MsgFltr_UL1T_TRC_CMAVG_DBG()	ChkL1ClsFltr_UL1C_PRI2_UL1C_AVG_L()
#define ChkL1MsgFltr_UL1_TRC_CMTreselection()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1I_TRC_CSDone()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CS_H()
#define ChkL1MsgFltr_UL1I_TRC_CSResult()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CS_L()
#define ChkL1MsgFltr_UL1I_TRC_CSStart()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CS_H()
#define ChkL1MsgFltr_UL1I_TRC_CS_Stop()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CS_H()
#define ChkL1MsgFltr_UL1I_TRC_Unlock_gapStopCnf()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1T_TRC_DMStopGap()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1T_TRC_DM_SetGap()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1T_TRC_DM_DRXTick()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1T_TRC_DM_SetGSM_Mode()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_DM_AssignGAP()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_Start_GAP_Timer1()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_Start_GAP_Timer2()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_DM_TimeSyncStart()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1T_TRC_DM_Cancel_ActiveGAP()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_DM_Cancel_2G_GAP_Cnf()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_DM_Query_GAP()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_DM_Query_GAP_SM()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_DM_Query_PSEUDO()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_DM_Sleep_Ind()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_RTB_Timer()	ChkL1ClsFltr_UL1C_PRI2_UL1C_RTB_H()
#define ChkL1MsgFltr_UL1I_TRC_AGPS_INFO()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1T_TRC_BAStatusUpdateInfo()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1I_TRC_CTCH_ADJUSTMENT_STATUS()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CTCH_H()
#define ChkL1MsgFltr_UL1I_TRC_CTCH_ADJUSTMENT_SUSPEND()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CTCH_H()
#define ChkL1MsgFltr_UL1I_TRC_CTCH_Resume()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CTCH_H()


#endif
