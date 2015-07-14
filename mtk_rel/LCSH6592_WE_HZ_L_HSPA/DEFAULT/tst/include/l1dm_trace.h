#ifndef L1TRC_L1DM_DEF_H
#define L1TRC_L1DM_DEF_H

/******************************/
/* String category definition */
/******************************/
#define L1DM_Str_Bool(v1)  (unsigned char)(v1+0)
#define L1DM_Str_GAPServiceType(v1)  (unsigned char)(v1+2)
#define L1DM_Str_DMState(v1)  (unsigned char)(v1+8)
#define L1DM_Str_3g_resel_type(v1)  (unsigned char)(v1+14)
#define L1DM_Str_2g_resel_mode(v1)  (unsigned char)(v1+18)
#define L1DM_Str_switch_2G_resel_mode_when(v1)  (unsigned char)(v1+20)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_SB(v1, v2, v3) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x000D, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1DM_MSG_SB(v1, v2, v3)
#endif
#define L1DM_MSG_SB_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x000D, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_FB(v1, v2) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x010D, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1DM_MSG_FB(v1, v2)
#endif
#define L1DM_MSG_FB_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x010D, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_IRATSYNC(v1, v2) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x020D, (short)(v2)), (long)(v1));\
	} while(0)
#else
	#define L1DM_MSG_IRATSYNC(v1, v2)
#endif
#define L1DM_MSG_IRATSYNC_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x020D, (short)(v2)), (long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_PMCell(v1) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x030D, (short)(v1)));\
	} while(0)
#else
	#define L1DM_MSG_PMCell(v1)
#endif
#define L1DM_MSG_PMCell_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x030D, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_3GGap(v1, v2, v3, v4, v5) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x040D, (short)(v2)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD), (long)(v1), (long)(v3));\
	} while(0)
#else
	#define L1DM_MSG_3GGap(v1, v2, v3, v4, v5)
#endif
#define L1DM_MSG_3GGap_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x040D, (short)(v2)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD), (long)(v1), (long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_AbortBSIC() do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x050D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1DM_MSG_AbortBSIC()
#endif
#define L1DM_MSG_AbortBSIC_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x050D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_DRXTick(v1) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x060D, (short)(v1)));\
	} while(0)
#else
	#define L1DM_MSG_DRXTick(v1)
#endif
#define L1DM_MSG_DRXTick_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x060D, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_2GGap(v1, v2, v3, v4) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x070D, (short)(v2)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v3));\
	} while(0)
#else
	#define L1DM_MSG_2GGap(v1, v2, v3, v4)
#endif
#define L1DM_MSG_2GGap_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x070D, (short)(v2)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_2GGapStop(v1, v2) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x080D, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1DM_MSG_2GGapStop(v1, v2)
#endif
#define L1DM_MSG_2GGapStop_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x080D, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_480msTick() do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x090D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1DM_MSG_480msTick()
#endif
#define L1DM_MSG_480msTick_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x090D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_3GGapPriority(v1) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x0A0D, (short)(v1)));\
	} while(0)
#else
	#define L1DM_MSG_3GGapPriority(v1)
#endif
#define L1DM_MSG_3GGapPriority_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x0A0D, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_3GGapServiceType(v1, v2, v3) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0B0D, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1DM_MSG_3GGapServiceType(v1, v2, v3)
#endif
#define L1DM_MSG_3GGapServiceType_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0B0D, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_3GGapServiceUpdate(v1, v2) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0C0D, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1DM_MSG_3GGapServiceUpdate(v1, v2)
#endif
#define L1DM_MSG_3GGapServiceUpdate_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0C0D, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_StopGapSchedule(v1) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x0D0D, (short)(v1)));\
	} while(0)
#else
	#define L1DM_MSG_StopGapSchedule(v1)
#endif
#define L1DM_MSG_StopGapSchedule_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x0D0D, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_GapScheduleDone(v1, v2, v3, v4) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0E0D, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (unsigned char)(v3), (unsigned char)(v4)));\
	} while(0)
#else
	#define L1DM_MSG_GapScheduleDone(v1, v2, v3, v4)
#endif
#define L1DM_MSG_GapScheduleDone_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0E0D, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (unsigned char)(v3), (unsigned char)(v4)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_FMOLock(v1) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0F0D, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1DM_MSG_FMOLock(v1)
#endif
#define L1DM_MSG_FMOLock_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0F0D, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_CancelGap() do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x100D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1DM_MSG_CancelGap()
#endif
#define L1DM_MSG_CancelGap_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x100D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_Lock2G(v1) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x110D, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1DM_MSG_Lock2G(v1)
#endif
#define L1DM_MSG_Lock2G_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x110D, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_DMState(v1) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x120D, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1DM_MSG_DMState(v1)
#endif
#define L1DM_MSG_DMState_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x120D, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_PMTick(v1) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x130D, (short)(v1)));\
	} while(0)
#else
	#define L1DM_MSG_PMTick(v1)
#endif
#define L1DM_MSG_PMTick_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x130D, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_PMTick_HPSearch(v1) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x140D, (short)(v1)));\
	} while(0)
#else
	#define L1DM_MSG_PMTick_HPSearch(v1)
#endif
#define L1DM_MSG_PMTick_HPSearch_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x140D, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_PMDone(v1, v2, v3) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x150D, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define L1DM_MSG_PMDone(v1, v2, v3)
#endif
#define L1DM_MSG_PMDone_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x150D, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_DeleteGap() do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x160D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1DM_MSG_DeleteGap()
#endif
#define L1DM_MSG_DeleteGap_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x160D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_GapSession_TD(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x170D, (short)(v1)), TRC_MERGE_2S((short)(v4), (short)(v7)), TRC_MERGE_1S2C((short)(v10), (unsigned char)(v2), TRC_BOXSTER_PAD), (long)(v3), (long)(v5), (long)(v6), (long)(v8), (long)(v9), (long)(v11));\
	} while(0)
#else
	#define L1DM_MSG_GapSession_TD(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11)
#endif
#define L1DM_MSG_GapSession_TD_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) TRC_SEND_9_DATA(TRC_MERGE_2S(0x170D, (short)(v1)), TRC_MERGE_2S((short)(v4), (short)(v7)), TRC_MERGE_1S2C((short)(v10), (unsigned char)(v2), TRC_BOXSTER_PAD), (long)(v3), (long)(v5), (long)(v6), (long)(v8), (long)(v9), (long)(v11))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_GapType_TD(v1, v2, v3, v4) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x180D, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_4C((unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1DM_MSG_GapType_TD(v1, v2, v3, v4)
#endif
#define L1DM_MSG_GapType_TD_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x180D, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_4C((unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_SetGap_TD(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x190D, (short)(v1)), TRC_MERGE_2S((short)(v4), (short)(v7)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v6), (unsigned char)(v9), TRC_BOXSTER_PAD), (long)(v2), (long)(v5), (long)(v8));\
	} while(0)
#else
	#define L1DM_MSG_SetGap_TD(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define L1DM_MSG_SetGap_TD_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_6_DATA(TRC_MERGE_2S(0x190D, (short)(v1)), TRC_MERGE_2S((short)(v4), (short)(v7)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v6), (unsigned char)(v9), TRC_BOXSTER_PAD), (long)(v2), (long)(v5), (long)(v8))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_BSICSchedule_TD(v1, v2, v3, v4, v5) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1A0D, (short)(v1)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v2), (unsigned char)(v3)), (long)(v5));\
	} while(0)
#else
	#define L1DM_MSG_BSICSchedule_TD(v1, v2, v3, v4, v5)
#endif
#define L1DM_MSG_BSICSchedule_TD_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1A0D, (short)(v1)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v2), (unsigned char)(v3)), (long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_PMLock_TD(v1) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1B0D, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1DM_MSG_PMLock_TD(v1)
#endif
#define L1DM_MSG_PMLock_TD_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1B0D, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_PMPeriod(v1, v2) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1C0D, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1DM_MSG_PMPeriod(v1, v2)
#endif
#define L1DM_MSG_PMPeriod_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1C0D, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_ReselMode_Standby(v1, v2) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1D0D, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define L1DM_MSG_ReselMode_Standby(v1, v2)
#endif
#define L1DM_MSG_ReselMode_Standby_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1D0D, (unsigned char)(v1), (unsigned char)(v2)))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char L1DM_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_L1DM_MSG_SB(short v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_L1DM_MSG_FB(short v1, short v2);
void L1TRC_Send_L1DM_MSG_IRATSYNC(long v1, short v2);
void L1TRC_Send_L1DM_MSG_PMCell(short v1);
void L1TRC_Send_L1DM_MSG_3GGap(long v1, short v2, long v3, short v4, unsigned char v5);
void L1TRC_Send_L1DM_MSG_AbortBSIC(void);
void L1TRC_Send_L1DM_MSG_DRXTick(short v1);
void L1TRC_Send_L1DM_MSG_2GGap(long v1, short v2, long v3, short v4);
void L1TRC_Send_L1DM_MSG_2GGapStop(short v1, short v2);
void L1TRC_Send_L1DM_MSG_480msTick(void);
void L1TRC_Send_L1DM_MSG_3GGapPriority(short v1);
void L1TRC_Send_L1DM_MSG_3GGapServiceType(unsigned char v1, unsigned char v2, short v3);
void L1TRC_Send_L1DM_MSG_3GGapServiceUpdate(unsigned char v1, short v2);
void L1TRC_Send_L1DM_MSG_StopGapSchedule(short v1);
void L1TRC_Send_L1DM_MSG_GapScheduleDone(short v1, short v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_L1DM_MSG_FMOLock(unsigned char v1);
void L1TRC_Send_L1DM_MSG_CancelGap(void);
void L1TRC_Send_L1DM_MSG_Lock2G(unsigned char v1);
void L1TRC_Send_L1DM_MSG_DMState(unsigned char v1);
void L1TRC_Send_L1DM_MSG_PMTick(short v1);
void L1TRC_Send_L1DM_MSG_PMTick_HPSearch(short v1);
void L1TRC_Send_L1DM_MSG_PMDone(short v1, short v2, short v3);
void L1TRC_Send_L1DM_MSG_DeleteGap(void);
void L1TRC_Send_L1DM_MSG_GapSession_TD(short v1, unsigned char v2, long v3, short v4, long v5, long v6, short v7, long v8, long v9, short v10, long v11);
void L1TRC_Send_L1DM_MSG_GapType_TD(short v1, short v2, short v3, unsigned char v4);
void L1TRC_Send_L1DM_MSG_SetGap_TD(short v1, long v2, unsigned char v3, short v4, long v5, unsigned char v6, short v7, long v8, unsigned char v9);
void L1TRC_Send_L1DM_MSG_BSICSchedule_TD(short v1, unsigned char v2, unsigned char v3, short v4, long v5);
void L1TRC_Send_L1DM_MSG_PMLock_TD(unsigned char v1);
void L1TRC_Send_L1DM_MSG_PMPeriod(short v1, short v2);
void L1TRC_Send_L1DM_MSG_ReselMode_Standby(unsigned char v1, unsigned char v2);

void Set_L1DM_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_L1DM()	(L1DM_Trace_Filter[0]==1)
#define ChkL1ClsFltr_L1DM_DMBSIC_M()	(ChkL1ModFltr_L1DM()&&((L1DM_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_L1DM_DMSYNC_M()	(ChkL1ModFltr_L1DM()&&((L1DM_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_L1DM_DMPM_M()	(ChkL1ModFltr_L1DM()&&((L1DM_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_L1DM_DMGAP_M()	(ChkL1ModFltr_L1DM()&&((L1DM_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_L1DM_DMTick_M()	(ChkL1ModFltr_L1DM()&&((L1DM_Trace_Filter[1]&0x10)!=0))
#define ChkL1MsgFltr_L1DM_MSG_SB()	ChkL1ClsFltr_L1DM_DMBSIC_M()
#define ChkL1MsgFltr_L1DM_MSG_FB()	ChkL1ClsFltr_L1DM_DMBSIC_M()
#define ChkL1MsgFltr_L1DM_MSG_IRATSYNC()	ChkL1ClsFltr_L1DM_DMSYNC_M()
#define ChkL1MsgFltr_L1DM_MSG_PMCell()	ChkL1ClsFltr_L1DM_DMPM_M()
#define ChkL1MsgFltr_L1DM_MSG_3GGap()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_AbortBSIC()	ChkL1ClsFltr_L1DM_DMBSIC_M()
#define ChkL1MsgFltr_L1DM_MSG_DRXTick()	ChkL1ClsFltr_L1DM_DMTick_M()
#define ChkL1MsgFltr_L1DM_MSG_2GGap()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_2GGapStop()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_480msTick()	ChkL1ClsFltr_L1DM_DMTick_M()
#define ChkL1MsgFltr_L1DM_MSG_3GGapPriority()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_3GGapServiceType()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_3GGapServiceUpdate()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_StopGapSchedule()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_GapScheduleDone()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_FMOLock()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_CancelGap()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_Lock2G()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_DMState()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_PMTick()	ChkL1ClsFltr_L1DM_DMPM_M()
#define ChkL1MsgFltr_L1DM_MSG_PMTick_HPSearch()	ChkL1ClsFltr_L1DM_DMPM_M()
#define ChkL1MsgFltr_L1DM_MSG_PMDone()	ChkL1ClsFltr_L1DM_DMPM_M()
#define ChkL1MsgFltr_L1DM_MSG_DeleteGap()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_GapSession_TD()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_GapType_TD()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_SetGap_TD()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_BSICSchedule_TD()	ChkL1ClsFltr_L1DM_DMBSIC_M()
#define ChkL1MsgFltr_L1DM_MSG_PMLock_TD()	ChkL1ClsFltr_L1DM_DMPM_M()
#define ChkL1MsgFltr_L1DM_MSG_PMPeriod()	ChkL1ClsFltr_L1DM_DMPM_M()
#define ChkL1MsgFltr_L1DM_MSG_ReselMode_Standby()	ChkL1ClsFltr_L1DM_DMGAP_M()


#endif
