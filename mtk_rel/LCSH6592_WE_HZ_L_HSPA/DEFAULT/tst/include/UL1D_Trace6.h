#ifndef L1TRC_UL1D_SEVENTH_DEF_H
#define L1TRC_UL1D_SEVENTH_DEF_H

/******************************/
/* String category definition */
/******************************/
#define UL1D_TRC_STR_TCS_ACTION(v1)  (unsigned char)(v1+0)
#define UL1D_TRC_STR_DCXO_ACTION(v1)  (unsigned char)(v1+4)
#define UL1D_TRC_STR_DLDPCH_TXTD(v1)  (unsigned char)(v1+6)
#define UL1D_TRC_STR_DFTC_ADV_RET(v1)  (unsigned char)(v1+10)
#define UL1D_TRC_STR_DFTC_MS3_CONB(v1)  (unsigned char)(v1+14)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_TXTD_DLDPCH(v1, v2, v3) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0016, (short)(v1)), TRC_MERGE_4C((char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXTD_DLDPCH(v1, v2, v3)
#endif
#define UL1D_TRC_TXTD_DLDPCH_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0016, (short)(v1)), TRC_MERGE_4C((char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_CS_STOP_TM_DBG(v1, v2) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0116, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_CS_STOP_TM_DBG(v1, v2)
#endif
#define UL1D_TRC_CS_STOP_TM_DBG_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0116, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_CS_STC_TM_DBG(v1, v2) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0216, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_CS_STC_TM_DBG(v1, v2)
#endif
#define UL1D_TRC_CS_STC_TM_DBG_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0216, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_CS_ST_EN(v1, v2, v3) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0316, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_CS_ST_EN(v1, v2, v3)
#endif
#define UL1D_TRC_CS_ST_EN_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0316, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_CS_DCXO_ACTION(v1) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0416, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_CS_DCXO_ACTION(v1)
#endif
#define UL1D_TRC_CS_DCXO_ACTION_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0416, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_CS_OFFSET_ADJ(v1, v2) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0516, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_CS_OFFSET_ADJ(v1, v2)
#endif
#define UL1D_TRC_CS_OFFSET_ADJ_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0516, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_CS_PEAK_PWR_IFNO(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0616, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_CS_PEAK_PWR_IFNO(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_CS_PEAK_PWR_IFNO_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0616, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_CS_PEAK_POS_IFNO(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0716, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)));\
	} while(0)
#else
	#define UL1D_TRC_CS_PEAK_POS_IFNO(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_CS_PEAK_POS_IFNO_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0716, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_CS_CLIPPED_BIN_ROATE_FREQ(v1) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0816, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_CS_CLIPPED_BIN_ROATE_FREQ(v1)
#endif
#define UL1D_TRC_CS_CLIPPED_BIN_ROATE_FREQ_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0816, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_CS_DCXO_DD_LOST() do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0916, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_CS_DCXO_DD_LOST()
#endif
#define UL1D_TRC_CS_DCXO_DD_LOST_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0916, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_CS3_PEAK_PWR_IFNO(v1, v2, v3, v4) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0A16, (short)(v2)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_CS3_PEAK_PWR_IFNO(v1, v2, v3, v4)
#endif
#define UL1D_TRC_CS3_PEAK_PWR_IFNO_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0A16, (short)(v2)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_CS12_PEAK_IFNO(v1, v2, v3) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0B16, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_CS12_PEAK_IFNO(v1, v2, v3)
#endif
#define UL1D_TRC_CS12_PEAK_IFNO_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0B16, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_CS_MBD_CS3_RESULT(v1, v2, v3, v4, v5) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0C16, (unsigned short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v3), (char)(v4)));\
	} while(0)
#else
	#define UL1D_TRC_CS_MBD_CS3_RESULT(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_CS_MBD_CS3_RESULT_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0C16, (unsigned short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v3), (char)(v4)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_MQC_RF_ACT(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0D16, (short)(v3)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v5), (char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MQC_RF_ACT(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_MQC_RF_ACT_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0D16, (short)(v3)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v5), (char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_MQC_TX_DAC(v1, v2, v3, v4, v5) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0E16, (short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v5));\
	} while(0)
#else
	#define UL1D_TRC_MQC_TX_DAC(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_MQC_TX_DAC_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0E16, (short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_MQC_NEXT_ACT(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0F16, (short)(v2)), TRC_MERGE_2S((unsigned short)(v4), (short)(v6)), TRC_MERGE_1S2C((short)(v7), (unsigned char)(v1), (char)(v3)), TRC_MERGE_4C((char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MQC_NEXT_ACT(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1D_TRC_MQC_NEXT_ACT_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0F16, (short)(v2)), TRC_MERGE_2S((unsigned short)(v4), (short)(v6)), TRC_MERGE_1S2C((short)(v7), (unsigned char)(v1), (char)(v3)), TRC_MERGE_4C((char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_MQC_CURRENT_ACT(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1016, (short)(v2)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v1), (char)(v3)), TRC_MERGE_4C((char)(v5), (char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MQC_CURRENT_ACT(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_MQC_CURRENT_ACT_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1016, (short)(v2)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v1), (char)(v3)), TRC_MERGE_4C((char)(v5), (char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_MQC_EXE_TIME_PLUS_PD(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1116, (char)(v3), (char)(v5)), TRC_MERGE_4C((char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_MQC_EXE_TIME_PLUS_PD(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_MQC_EXE_TIME_PLUS_PD_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1116, (char)(v3), (char)(v5)), TRC_MERGE_4C((char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (long)(v4))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DCXO_STATUS(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x1216, (short)(v1)), TRC_MERGE_4C((unsigned char)(v9), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2), (unsigned long)(v3), (long)(v4), (unsigned long)(v5), (long)(v6), (long)(v7), (unsigned long)(v8));\
	} while(0)
#else
	#define UL1D_TRC_DCXO_STATUS(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define UL1D_TRC_DCXO_STATUS_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_9_DATA(TRC_MERGE_2S(0x1216, (short)(v1)), TRC_MERGE_4C((unsigned char)(v9), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2), (unsigned long)(v3), (long)(v4), (unsigned long)(v5), (long)(v6), (long)(v7), (unsigned long)(v8))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DCXO_INI(v1, v2, v3, v4) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1316, (unsigned char)(v1), (unsigned char)(v4)), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_DCXO_INI(v1, v2, v3, v4)
#endif
#define UL1D_TRC_DCXO_INI_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1316, (unsigned char)(v1), (unsigned char)(v4)), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define UL1D_TRC_HW_REG(v1, v2, v3, v4) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x1416, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_HW_REG(v1, v2, v3, v4)
#endif
#define UL1D_TRC_HW_REG_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x1416, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define UL1D_DFTC_PAC_PLUS_X(v1, v2, v3, v4) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x1516, (char)(v3), TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (long)(v4));\
	} while(0)
#else
	#define UL1D_DFTC_PAC_PLUS_X(v1, v2, v3, v4)
#endif
#define UL1D_DFTC_PAC_PLUS_X_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x1516, (char)(v3), TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (long)(v4))

#if defined(L1_CATCHER)
	#define UL1D_DFTC_RX_TAG(v1, v2, v3, v4, v5) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x1616, (unsigned short)(v4)), TRC_MERGE_4C((char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v5));\
	} while(0)
#else
	#define UL1D_DFTC_RX_TAG(v1, v2, v3, v4, v5)
#endif
#define UL1D_DFTC_RX_TAG_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x1616, (unsigned short)(v4)), TRC_MERGE_4C((char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v5))

#if defined(L1_CATCHER)
	#define UL1D_DFTC_TX_TAG(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x1716, (short)(v4)), (long)(v1), (long)(v2), (unsigned long)(v3), (long)(v5), (long)(v6));\
	} while(0)
#else
	#define UL1D_DFTC_TX_TAG(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_DFTC_TX_TAG_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_6_DATA(TRC_MERGE_2S(0x1716, (short)(v4)), (long)(v1), (long)(v2), (unsigned long)(v3), (long)(v5), (long)(v6))

#if defined(L1_CATCHER)
	#define UL1D_DFTC_TRX_DIFF_UPDATE(v1, v2, v3, v4, v5) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x1816, (short)(v4)), TRC_MERGE_1S2C((short)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define UL1D_DFTC_TRX_DIFF_UPDATE(v1, v2, v3, v4, v5)
#endif
#define UL1D_DFTC_TRX_DIFF_UPDATE_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_2S(0x1816, (short)(v4)), TRC_MERGE_1S2C((short)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define UL1D_DFTC_TX_TXCRP(v1, v2, v3, v4) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1916, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_DFTC_TX_TXCRP(v1, v2, v3, v4)
#endif
#define UL1D_DFTC_TX_TXCRP_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1916, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define UL1D_DFTC_RXDFE_DEBUG0(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x1A16, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define UL1D_DFTC_RXDFE_DEBUG0(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_DFTC_RXDFE_DEBUG0_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x1A16, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER)
	#define UL1D_DFTC_OFFLINE_PAC_SYNC(v1, v2, v3, v4) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1B16, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (short)(v4)), (long)(v3));\
	} while(0)
#else
	#define UL1D_DFTC_OFFLINE_PAC_SYNC(v1, v2, v3, v4)
#endif
#define UL1D_DFTC_OFFLINE_PAC_SYNC_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1B16, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (short)(v4)), (long)(v3))

#if defined(L1_CATCHER)
	#define UL1D_DFTC_OFFLINE_DCXOADJ(v1, v2, v3) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1C16, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)));\
	} while(0)
#else
	#define UL1D_DFTC_OFFLINE_DCXOADJ(v1, v2, v3)
#endif
#define UL1D_DFTC_OFFLINE_DCXOADJ_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1C16, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)))

#if defined(L1_CATCHER)
	#define UL1D_DFTC_OFFLINE_X_MAPPING(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x1D16, (short)(v1)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), (unsigned long)(v2), (unsigned long)(v7), (unsigned long)(v8));\
	} while(0)
#else
	#define UL1D_DFTC_OFFLINE_X_MAPPING(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_DFTC_OFFLINE_X_MAPPING_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_6_DATA(TRC_MERGE_2S(0x1D16, (short)(v1)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), (unsigned long)(v2), (unsigned long)(v7), (unsigned long)(v8))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_DFTC_ADV_RET(v1, v2, v3, v4) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1E16, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_DFTC_ADV_RET(v1, v2, v3, v4)
#endif
#define UL1D_DFTC_ADV_RET_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1E16, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_DFTC_ADV_RET_EVENT(v1) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1F16, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_DFTC_ADV_RET_EVENT(v1)
#endif
#define UL1D_DFTC_ADV_RET_EVENT_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1F16, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_DFTC_WIN_TRK_PAC_ADDR(v1, v2, v3, v4, v5) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2016, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_DFTC_WIN_TRK_PAC_ADDR(v1, v2, v3, v4, v5)
#endif
#define UL1D_DFTC_WIN_TRK_PAC_ADDR_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2016, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_DFTC_WIN_TRK_EVENT(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2116, (short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_4C((char)(v4), (char)(v5), (char)(v6), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_DFTC_WIN_TRK_EVENT(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_DFTC_WIN_TRK_EVENT_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2116, (short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_4C((char)(v4), (char)(v5), (char)(v6), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_DFTC_TX_OFFSET1(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x2216, (char)(v5), (unsigned char)(v6)), (long)(v1), (long)(v2), (long)(v3), (unsigned long)(v4), (long)(v7));\
	} while(0)
#else
	#define UL1D_DFTC_TX_OFFSET1(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1D_DFTC_TX_OFFSET1_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x2216, (char)(v5), (unsigned char)(v6)), (long)(v1), (long)(v2), (long)(v3), (unsigned long)(v4), (long)(v7))

#if defined(L1_CATCHER)
	#define UL1D_DFTC_TX_OFFSET2(v1, v2, v3, v4) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x2316, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define UL1D_DFTC_TX_OFFSET2(v1, v2, v3, v4)
#endif
#define UL1D_DFTC_TX_OFFSET2_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x2316, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (long)(v3), (long)(v4))

#if defined(L1_CATCHER)
	#define UL1D_DFTC_TX_OFFSET3(v1, v2, v3, v4, v5) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x2416, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (unsigned long)(v2), (long)(v3), (long)(v4), (long)(v5));\
	} while(0)
#else
	#define UL1D_DFTC_TX_OFFSET3(v1, v2, v3, v4, v5)
#endif
#define UL1D_DFTC_TX_OFFSET3_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x2416, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (unsigned long)(v2), (long)(v3), (long)(v4), (long)(v5))

#if defined(L1_CATCHER)
	#define UL1D_DFTC_TX_OFFSET4(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x2516, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define UL1D_DFTC_TX_OFFSET4(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_DFTC_TX_OFFSET4_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x2516, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER)
	#define UL1D_DFTC_TX_OFFSET5(v1, v2, v3, v4) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x2616, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define UL1D_DFTC_TX_OFFSET5(v1, v2, v3, v4)
#endif
#define UL1D_DFTC_TX_OFFSET5_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x2616, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4))

#if defined(L1_CATCHER)
	#define UL1D_DFTC_TX_OFFSET6(v1, v2, v3, v4) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x2716, (short)(v1)), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define UL1D_DFTC_TX_OFFSET6(v1, v2, v3, v4)
#endif
#define UL1D_DFTC_TX_OFFSET6_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x2716, (short)(v1)), (long)(v2), (long)(v3), (long)(v4))

#if defined(L1_CATCHER)
	#define UL1D_DFTC_RXRTR(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x2816, (char)(v7), TRC_BOXSTER_PAD), (long)(v1), (unsigned long)(v2), (long)(v3), (unsigned long)(v4), (long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define UL1D_DFTC_RXRTR(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1D_DFTC_RXRTR_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x2816, (char)(v7), TRC_BOXSTER_PAD), (long)(v1), (unsigned long)(v2), (long)(v3), (unsigned long)(v4), (long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER)
	#define UL1D_DFTC_TX_MNTR(v1, v2) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2916, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (long)(v2));\
	} while(0)
#else
	#define UL1D_DFTC_TX_MNTR(v1, v2)
#endif
#define UL1D_DFTC_TX_MNTR_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2916, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (long)(v2))

#if defined(L1_CATCHER)
	#define UL1D_DFTC_DEBUG(v1, v2, v3, v4, v5) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x2A16, (short)(v1)), (long)(v2), (long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define UL1D_DFTC_DEBUG(v1, v2, v3, v4, v5)
#endif
#define UL1D_DFTC_DEBUG_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_2S(0x2A16, (short)(v1)), (long)(v2), (long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER)
	#define UL1D_DFTC_SET_INIT_ON(v1, v2, v3, v4) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2B16, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_DFTC_SET_INIT_ON(v1, v2, v3, v4)
#endif
#define UL1D_DFTC_SET_INIT_ON_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2B16, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_DFTC_INIT_SETTING(v1, v2, v3) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2C16, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1D_DFTC_INIT_SETTING(v1, v2, v3)
#endif
#define UL1D_DFTC_INIT_SETTING_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2C16, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_DFTC_CELL_TM(v1, v2, v3, v4) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2D16, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (char)(v1), TRC_BOXSTER_PAD), (long)(v4));\
	} while(0)
#else
	#define UL1D_DFTC_CELL_TM(v1, v2, v3, v4)
#endif
#define UL1D_DFTC_CELL_TM_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2D16, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (char)(v1), TRC_BOXSTER_PAD), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_DFTC_MS3_PEAK(v1, v2) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2E16, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_DFTC_MS3_PEAK(v1, v2)
#endif
#define UL1D_DFTC_MS3_PEAK_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2E16, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_DFTC_DD_START_TIME(v1, v2, v3) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2F16, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define UL1D_DFTC_DD_START_TIME(v1, v2, v3)
#endif
#define UL1D_DFTC_DD_START_TIME_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2F16, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_DFTC_DD_PROCESS_TIME(v1, v2, v3, v4) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3016, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v1), (char)(v3)));\
	} while(0)
#else
	#define UL1D_DFTC_DD_PROCESS_TIME(v1, v2, v3, v4)
#endif
#define UL1D_DFTC_DD_PROCESS_TIME_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3016, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v1), (char)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_DFTC_CSIRQ_TIME(v1, v2, v3, v4) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3116, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v3), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_DFTC_CSIRQ_TIME(v1, v2, v3, v4)
#endif
#define UL1D_DFTC_CSIRQ_TIME_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3116, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v3), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_DFTC_MS3_CONB(v1, v2, v3, v4, v5) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3216, (unsigned char)(v1), (char)(v3)), TRC_MERGE_4C((char)(v4), (char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_DFTC_MS3_CONB(v1, v2, v3, v4, v5)
#endif
#define UL1D_DFTC_MS3_CONB_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3216, (unsigned char)(v1), (char)(v3)), TRC_MERGE_4C((char)(v4), (char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_DFTC_DD_ERROR() do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3316, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_DFTC_DD_ERROR()
#endif
#define UL1D_DFTC_DD_ERROR_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3316, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_DFTC_MS3_STATUS(v1, v2, v3, v4) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3416, (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_DFTC_MS3_STATUS(v1, v2, v3, v4)
#endif
#define UL1D_DFTC_MS3_STATUS_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3416, (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_DFTC_MS3_CON0(v1, v2, v3) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x3516, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1D_DFTC_MS3_CON0(v1, v2, v3)
#endif
#define UL1D_DFTC_MS3_CON0_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x3516, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_DFTC_MS3_CON1(v1, v2, v3) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x3616, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1D_DFTC_MS3_CON1(v1, v2, v3)
#endif
#define UL1D_DFTC_MS3_CON1_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x3616, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_DFTC_MS3_CON2(v1, v2, v3) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x3716, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1D_DFTC_MS3_CON2(v1, v2, v3)
#endif
#define UL1D_DFTC_MS3_CON2_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x3716, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_DFTC_MS3_DBG(v1, v2, v3, v4) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x3816, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_DFTC_MS3_DBG(v1, v2, v3, v4)
#endif
#define UL1D_DFTC_MS3_DBG_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x3816, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_DFTC_DD_STATUS(v1, v2, v3, v4) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x3916, (unsigned short)(v4)), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1D_DFTC_DD_STATUS(v1, v2, v3, v4)
#endif
#define UL1D_DFTC_DD_STATUS_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x3916, (unsigned short)(v4)), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_DFTC_STC_STATUS(v1, v2, v3, v4) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x3A16, (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_DFTC_STC_STATUS(v1, v2, v3, v4)
#endif
#define UL1D_DFTC_STC_STATUS_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x3A16, (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_DFTC_STC_SW(v1) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x3B16, (unsigned short)(v1)));\
	} while(0)
#else
	#define UL1D_DFTC_STC_SW(v1)
#endif
#define UL1D_DFTC_STC_SW_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x3B16, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_STA_DET_MAIN_PATH(v1, v2, v3) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3C16, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1D_TRC_STA_DET_MAIN_PATH(v1, v2, v3)
#endif
#define UL1D_TRC_STA_DET_MAIN_PATH_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3C16, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_STA_DET_SUB_PATH(v1, v2, v3) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3D16, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1D_TRC_STA_DET_SUB_PATH(v1, v2, v3)
#endif
#define UL1D_TRC_STA_DET_SUB_PATH_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3D16, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_STA_DET_CHECK(v1) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x3E16, (short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_STA_DET_CHECK(v1)
#endif
#define UL1D_TRC_STA_DET_CHECK_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x3E16, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_GEMI2_SUSPEND_BIT_MASK(v1, v2) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3F16, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_GEMI2_SUSPEND_BIT_MASK(v1, v2)
#endif
#define UL1D_TRC_GEMI2_SUSPEND_BIT_MASK_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3F16, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_GEMI2_SIM2_PREEMPT_COUNT(v1, v2) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4016, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_GEMI2_SIM2_PREEMPT_COUNT(v1, v2)
#endif
#define UL1D_TRC_GEMI2_SIM2_PREEMPT_COUNT_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4016, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_GEMI2_RX_SUSPEND(v1, v2, v3, v4, v5) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4116, (short)(v1)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_GEMI2_RX_SUSPEND(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_GEMI2_RX_SUSPEND_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4116, (short)(v1)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_GEMI2_TX_SUSPEND(v1, v2, v3, v4, v5) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4216, (short)(v1)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_GEMI2_TX_SUSPEND(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_GEMI2_TX_SUSPEND_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4216, (short)(v1)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_GEMI2_HSDSCH_GAP_BITMAP(v1, v2) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4316, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_GEMI2_HSDSCH_GAP_BITMAP(v1, v2)
#endif
#define UL1D_TRC_GEMI2_HSDSCH_GAP_BITMAP_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4316, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_GEMI2_USIM_RX_BYPASS_CHECK(v1, v2) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4416, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_GEMI2_USIM_RX_BYPASS_CHECK(v1, v2)
#endif
#define UL1D_TRC_GEMI2_USIM_RX_BYPASS_CHECK_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4416, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_GEMI2_USIM_HSRX_FORCE_GAP(v1) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4516, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_GEMI2_USIM_HSRX_FORCE_GAP(v1)
#endif
#define UL1D_TRC_GEMI2_USIM_HSRX_FORCE_GAP_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4516, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_GEMI2_USIM_HSTX_HAQ_FORCE_GAP(v1) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4616, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_GEMI2_USIM_HSTX_HAQ_FORCE_GAP(v1)
#endif
#define UL1D_TRC_GEMI2_USIM_HSTX_HAQ_FORCE_GAP_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4616, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_GEMI2_USIM_HSTX_CQI_FORCE_GAP(v1) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4716, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_GEMI2_USIM_HSTX_CQI_FORCE_GAP(v1)
#endif
#define UL1D_TRC_GEMI2_USIM_HSTX_CQI_FORCE_GAP_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4716, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_GEMI2_RACH_GAP_BITMAP(v1, v2, v3) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4816, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_GEMI2_RACH_GAP_BITMAP(v1, v2, v3)
#endif
#define UL1D_TRC_GEMI2_RACH_GAP_BITMAP_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4816, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_GEMI2_CPC_ULDPCCH_FDPCH_INFO(v1, v2) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4916, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_GEMI2_CPC_ULDPCCH_FDPCH_INFO(v1, v2)
#endif
#define UL1D_TRC_GEMI2_CPC_ULDPCCH_FDPCH_INFO_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4916, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_GEMI2_EFACH_DELAY_RECEIVE_CNT(v1) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x4A16, (short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_GEMI2_EFACH_DELAY_RECEIVE_CNT(v1)
#endif
#define UL1D_TRC_GEMI2_EFACH_DELAY_RECEIVE_CNT_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x4A16, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_GEMI2_STS_HSDSCH_RESET(v1) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4B16, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_GEMI2_STS_HSDSCH_RESET(v1)
#endif
#define UL1D_TRC_GEMI2_STS_HSDSCH_RESET_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4B16, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_GEMI2_STS_HSDSCH_NUMBER(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_8_DATA(TRC_MERGE_1S2C(0x4C16, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8));\
	} while(0)
#else
	#define UL1D_TRC_GEMI2_STS_HSDSCH_NUMBER(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_GEMI2_STS_HSDSCH_NUMBER_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_8_DATA(TRC_MERGE_1S2C(0x4C16, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_GEMI2_STS_EDCH_RESET() do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4D16, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_GEMI2_STS_EDCH_RESET()
#endif
#define UL1D_TRC_GEMI2_STS_EDCH_RESET_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4D16, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_GEMI2_STS_EDCH_NUMBER(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x4E16, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8));\
	} while(0)
#else
	#define UL1D_TRC_GEMI2_STS_EDCH_NUMBER(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_GEMI2_STS_EDCH_NUMBER_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x4E16, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MTCMOS_STATUS(v1, v2) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4F16, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_MTCMOS_STATUS(v1, v2)
#endif
#define UL1D_TRC_MTCMOS_STATUS_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4F16, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MTCMOS_EVENT(v1, v2) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5016, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MTCMOS_EVENT(v1, v2)
#endif
#define UL1D_TRC_MTCMOS_EVENT_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5016, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MTCMOS_DBG(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_SEVENTH_Trace_Filter[0]==1 && (UL1D_SEVENTH_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x5116, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define UL1D_TRC_MTCMOS_DBG(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_MTCMOS_DBG_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x5116, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char UL1D_SEVENTH_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_UL1D_TRC_TXTD_DLDPCH(short v1, char v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_CS_STOP_TM_DBG(unsigned long v1, unsigned long v2);
void L1TRC_Send_UL1D_TRC_CS_STC_TM_DBG(unsigned long v1, unsigned long v2);
void L1TRC_Send_UL1D_TRC_CS_ST_EN(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_CS_DCXO_ACTION(unsigned char v1);
void L1TRC_Send_UL1D_TRC_CS_OFFSET_ADJ(short v1, short v2);
void L1TRC_Send_UL1D_TRC_CS_PEAK_PWR_IFNO(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6);
void L1TRC_Send_UL1D_TRC_CS_PEAK_POS_IFNO(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6);
void L1TRC_Send_UL1D_TRC_CS_CLIPPED_BIN_ROATE_FREQ(long v1);
void L1TRC_Send_UL1D_TRC_CS_DCXO_DD_LOST(void);
void L1TRC_Send_UL1D_TRC_CS3_PEAK_PWR_IFNO(unsigned char v1, short v2, unsigned long v3, unsigned short v4);
void L1TRC_Send_UL1D_TRC_CS12_PEAK_IFNO(unsigned char v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_UL1D_TRC_CS_MBD_CS3_RESULT(unsigned char v1, char v2, char v3, char v4, unsigned short v5);
void L1TRC_Send_UL1D_TRC_MQC_RF_ACT(unsigned char v1, char v2, short v3, short v4, char v5, char v6);
void L1TRC_Send_UL1D_TRC_MQC_TX_DAC(short v1, char v2, unsigned short v3, unsigned short v4, unsigned long v5);
void L1TRC_Send_UL1D_TRC_MQC_NEXT_ACT(unsigned char v1, short v2, char v3, unsigned short v4, char v5, short v6, short v7);
void L1TRC_Send_UL1D_TRC_MQC_CURRENT_ACT(unsigned char v1, short v2, char v3, unsigned short v4, char v5, char v6);
void L1TRC_Send_UL1D_TRC_MQC_EXE_TIME_PLUS_PD(unsigned long v1, unsigned long v2, char v3, long v4, char v5, char v6);
void L1TRC_Send_UL1D_TRC_DCXO_STATUS(short v1, long v2, unsigned long v3, long v4, unsigned long v5, long v6, long v7, unsigned long v8, unsigned char v9);
void L1TRC_Send_UL1D_TRC_DCXO_INI(unsigned char v1, long v2, long v3, unsigned char v4);
void L1TRC_Send_UL1D_TRC_HW_REG(short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_UL1D_DFTC_PAC_PLUS_X(unsigned long v1, unsigned long v2, char v3, long v4);
void L1TRC_Send_UL1D_DFTC_RX_TAG(long v1, char v2, unsigned char v3, unsigned short v4, long v5);
void L1TRC_Send_UL1D_DFTC_TX_TAG(long v1, long v2, unsigned long v3, short v4, long v5, long v6);
void L1TRC_Send_UL1D_DFTC_TRX_DIFF_UPDATE(long v1, long v2, long v3, short v4, short v5);
void L1TRC_Send_UL1D_DFTC_TX_TXCRP(unsigned long v1, unsigned long v2, long v3, unsigned long v4);
void L1TRC_Send_UL1D_DFTC_RXDFE_DEBUG0(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_UL1D_DFTC_OFFLINE_PAC_SYNC(unsigned short v1, unsigned short v2, long v3, short v4);
void L1TRC_Send_UL1D_DFTC_OFFLINE_DCXOADJ(unsigned short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_UL1D_DFTC_OFFLINE_X_MAPPING(short v1, unsigned long v2, short v3, short v4, short v5, short v6, unsigned long v7, unsigned long v8);
void L1TRC_Send_UL1D_DFTC_ADV_RET(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_UL1D_DFTC_ADV_RET_EVENT(unsigned char v1);
void L1TRC_Send_UL1D_DFTC_WIN_TRK_PAC_ADDR(unsigned short v1, unsigned short v2, char v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_UL1D_DFTC_WIN_TRK_EVENT(short v1, unsigned short v2, unsigned short v3, char v4, char v5, char v6);
void L1TRC_Send_UL1D_DFTC_TX_OFFSET1(long v1, long v2, long v3, unsigned long v4, char v5, unsigned char v6, long v7);
void L1TRC_Send_UL1D_DFTC_TX_OFFSET2(unsigned char v1, unsigned long v2, long v3, long v4);
void L1TRC_Send_UL1D_DFTC_TX_OFFSET3(long v1, unsigned long v2, long v3, long v4, long v5);
void L1TRC_Send_UL1D_DFTC_TX_OFFSET4(long v1, long v2, long v3, long v4, long v5, unsigned long v6);
void L1TRC_Send_UL1D_DFTC_TX_OFFSET5(long v1, long v2, long v3, long v4);
void L1TRC_Send_UL1D_DFTC_TX_OFFSET6(short v1, long v2, long v3, long v4);
void L1TRC_Send_UL1D_DFTC_RXRTR(long v1, unsigned long v2, long v3, unsigned long v4, long v5, unsigned long v6, char v7);
void L1TRC_Send_UL1D_DFTC_TX_MNTR(unsigned long v1, long v2);
void L1TRC_Send_UL1D_DFTC_DEBUG(short v1, long v2, long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_UL1D_DFTC_SET_INIT_ON(short v1, short v2, short v3, short v4);
void L1TRC_Send_UL1D_DFTC_INIT_SETTING(short v1, short v2, short v3);
void L1TRC_Send_UL1D_DFTC_CELL_TM(char v1, short v2, short v3, long v4);
void L1TRC_Send_UL1D_DFTC_MS3_PEAK(short v1, short v2);
void L1TRC_Send_UL1D_DFTC_DD_START_TIME(unsigned long v1, unsigned char v2, unsigned short v3);
void L1TRC_Send_UL1D_DFTC_DD_PROCESS_TIME(unsigned char v1, unsigned short v2, char v3, unsigned short v4);
void L1TRC_Send_UL1D_DFTC_CSIRQ_TIME(unsigned short v1, unsigned long v2, unsigned char v3, unsigned short v4);
void L1TRC_Send_UL1D_DFTC_MS3_CONB(unsigned char v1, unsigned long v2, char v3, char v4, char v5);
void L1TRC_Send_UL1D_DFTC_DD_ERROR(void);
void L1TRC_Send_UL1D_DFTC_MS3_STATUS(unsigned char v1, unsigned long v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_UL1D_DFTC_MS3_CON0(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_UL1D_DFTC_MS3_CON1(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_UL1D_DFTC_MS3_CON2(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_UL1D_DFTC_MS3_DBG(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_UL1D_DFTC_DD_STATUS(unsigned long v1, unsigned long v2, unsigned long v3, unsigned short v4);
void L1TRC_Send_UL1D_DFTC_STC_STATUS(unsigned long v1, unsigned long v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_UL1D_DFTC_STC_SW(unsigned short v1);
void L1TRC_Send_UL1D_TRC_STA_DET_MAIN_PATH(short v1, short v2, short v3);
void L1TRC_Send_UL1D_TRC_STA_DET_SUB_PATH(short v1, short v2, short v3);
void L1TRC_Send_UL1D_TRC_STA_DET_CHECK(short v1);
void L1TRC_Send_UL1D_TRC_GEMI2_SUSPEND_BIT_MASK(unsigned char v1, unsigned short v2);
void L1TRC_Send_UL1D_TRC_GEMI2_SIM2_PREEMPT_COUNT(unsigned short v1, unsigned short v2);
void L1TRC_Send_UL1D_TRC_GEMI2_RX_SUSPEND(short v1, unsigned char v2, unsigned char v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_UL1D_TRC_GEMI2_TX_SUSPEND(short v1, unsigned char v2, unsigned char v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_UL1D_TRC_GEMI2_HSDSCH_GAP_BITMAP(unsigned long v1, unsigned long v2);
void L1TRC_Send_UL1D_TRC_GEMI2_USIM_RX_BYPASS_CHECK(unsigned char v1, short v2);
void L1TRC_Send_UL1D_TRC_GEMI2_USIM_HSRX_FORCE_GAP(unsigned char v1);
void L1TRC_Send_UL1D_TRC_GEMI2_USIM_HSTX_HAQ_FORCE_GAP(unsigned char v1);
void L1TRC_Send_UL1D_TRC_GEMI2_USIM_HSTX_CQI_FORCE_GAP(unsigned char v1);
void L1TRC_Send_UL1D_TRC_GEMI2_RACH_GAP_BITMAP(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_GEMI2_CPC_ULDPCCH_FDPCH_INFO(unsigned short v1, unsigned short v2);
void L1TRC_Send_UL1D_TRC_GEMI2_EFACH_DELAY_RECEIVE_CNT(short v1);
void L1TRC_Send_UL1D_TRC_GEMI2_STS_HSDSCH_RESET(unsigned char v1);
void L1TRC_Send_UL1D_TRC_GEMI2_STS_HSDSCH_NUMBER(unsigned char v1, long v2, long v3, long v4, long v5, long v6, long v7, long v8);
void L1TRC_Send_UL1D_TRC_GEMI2_STS_EDCH_RESET(void);
void L1TRC_Send_UL1D_TRC_GEMI2_STS_EDCH_NUMBER(long v1, long v2, long v3, long v4, long v5, long v6, long v7, long v8);
void L1TRC_Send_UL1D_TRC_MTCMOS_STATUS(unsigned long v1, unsigned long v2);
void L1TRC_Send_UL1D_TRC_MTCMOS_EVENT(char v1, short v2);
void L1TRC_Send_UL1D_TRC_MTCMOS_DBG(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6);

void Set_UL1D_SEVENTH_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_UL1D_SEVENTH()	(UL1D_SEVENTH_Trace_Filter[0]==1)
#define ChkL1ClsFltr_UL1D_SEVENTH_TXTD_M()	(ChkL1ModFltr_UL1D_SEVENTH()&&((UL1D_SEVENTH_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_UL1D_SEVENTH_CS_M()	(ChkL1ModFltr_UL1D_SEVENTH()&&((UL1D_SEVENTH_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_UL1D_SEVENTH_MQC_L()	(ChkL1ModFltr_UL1D_SEVENTH()&&((UL1D_SEVENTH_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_UL1D_SEVENTH_DFTC_H()	(ChkL1ModFltr_UL1D_SEVENTH()&&((UL1D_SEVENTH_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_UL1D_SEVENTH_DFTC_M()	(ChkL1ModFltr_UL1D_SEVENTH()&&((UL1D_SEVENTH_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_UL1D_SEVENTH_DFTC_MS3_L()	(ChkL1ModFltr_UL1D_SEVENTH()&&((UL1D_SEVENTH_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_UL1D_SEVENTH_GEMINI_2_0_H()	(ChkL1ModFltr_UL1D_SEVENTH()&&((UL1D_SEVENTH_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_UL1D_SEVENTH_GEMINI_2_0_M()	(ChkL1ModFltr_UL1D_SEVENTH()&&((UL1D_SEVENTH_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_UL1D_SEVENTH_GEMINI_2_0_L()	(ChkL1ModFltr_UL1D_SEVENTH()&&((UL1D_SEVENTH_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_UL1D_SEVENTH_G2_STS_H()	(ChkL1ModFltr_UL1D_SEVENTH()&&((UL1D_SEVENTH_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_UL1D_SEVENTH_G2_STS_M()	(ChkL1ModFltr_UL1D_SEVENTH()&&((UL1D_SEVENTH_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_UL1D_SEVENTH_G2_STS_L()	(ChkL1ModFltr_UL1D_SEVENTH()&&((UL1D_SEVENTH_Trace_Filter[2]&0x08)!=0))
#define ChkL1ClsFltr_UL1D_SEVENTH_MTCMOS_M()	(ChkL1ModFltr_UL1D_SEVENTH()&&((UL1D_SEVENTH_Trace_Filter[2]&0x10)!=0))
#define ChkL1ClsFltr_UL1D_SEVENTH_STA_DET_M()	(ChkL1ModFltr_UL1D_SEVENTH()&&((UL1D_SEVENTH_Trace_Filter[2]&0x20)!=0))
#define ChkL1MsgFltr_UL1D_TRC_TXTD_DLDPCH()	ChkL1ClsFltr_UL1D_SEVENTH_TXTD_M()
#define ChkL1MsgFltr_UL1D_TRC_CS_STOP_TM_DBG()	ChkL1ClsFltr_UL1D_SEVENTH_CS_M()
#define ChkL1MsgFltr_UL1D_TRC_CS_STC_TM_DBG()	ChkL1ClsFltr_UL1D_SEVENTH_CS_M()
#define ChkL1MsgFltr_UL1D_TRC_CS_ST_EN()	ChkL1ClsFltr_UL1D_SEVENTH_CS_M()
#define ChkL1MsgFltr_UL1D_TRC_CS_DCXO_ACTION()	ChkL1ClsFltr_UL1D_SEVENTH_CS_M()
#define ChkL1MsgFltr_UL1D_TRC_CS_OFFSET_ADJ()	ChkL1ClsFltr_UL1D_SEVENTH_CS_M()
#define ChkL1MsgFltr_UL1D_TRC_CS_PEAK_PWR_IFNO()	ChkL1ClsFltr_UL1D_SEVENTH_CS_M()
#define ChkL1MsgFltr_UL1D_TRC_CS_PEAK_POS_IFNO()	ChkL1ClsFltr_UL1D_SEVENTH_CS_M()
#define ChkL1MsgFltr_UL1D_TRC_CS_CLIPPED_BIN_ROATE_FREQ()	ChkL1ClsFltr_UL1D_SEVENTH_CS_M()
#define ChkL1MsgFltr_UL1D_TRC_CS_DCXO_DD_LOST()	ChkL1ClsFltr_UL1D_SEVENTH_CS_M()
#define ChkL1MsgFltr_UL1D_TRC_CS3_PEAK_PWR_IFNO()	ChkL1ClsFltr_UL1D_SEVENTH_CS_M()
#define ChkL1MsgFltr_UL1D_TRC_CS12_PEAK_IFNO()	ChkL1ClsFltr_UL1D_SEVENTH_CS_M()
#define ChkL1MsgFltr_UL1D_TRC_CS_MBD_CS3_RESULT()	ChkL1ClsFltr_UL1D_SEVENTH_CS_M()
#define ChkL1MsgFltr_UL1D_TRC_MQC_RF_ACT()	ChkL1ClsFltr_UL1D_SEVENTH_MQC_L()
#define ChkL1MsgFltr_UL1D_TRC_MQC_TX_DAC()	ChkL1ClsFltr_UL1D_SEVENTH_MQC_L()
#define ChkL1MsgFltr_UL1D_TRC_MQC_NEXT_ACT()	ChkL1ClsFltr_UL1D_SEVENTH_MQC_L()
#define ChkL1MsgFltr_UL1D_TRC_MQC_CURRENT_ACT()	ChkL1ClsFltr_UL1D_SEVENTH_MQC_L()
#define ChkL1MsgFltr_UL1D_TRC_MQC_EXE_TIME_PLUS_PD()	ChkL1ClsFltr_UL1D_SEVENTH_MQC_L()
#define ChkL1MsgFltr_UL1D_TRC_DCXO_STATUS()	ChkL1ClsFltr_UL1D_SEVENTH_DFTC_H()
#define ChkL1MsgFltr_UL1D_TRC_DCXO_INI()	ChkL1ClsFltr_UL1D_SEVENTH_DFTC_H()
#define ChkL1MsgFltr_UL1D_TRC_HW_REG()	ChkL1ClsFltr_UL1D_SEVENTH_DFTC_H()
#define ChkL1MsgFltr_UL1D_DFTC_PAC_PLUS_X()	ChkL1ClsFltr_UL1D_SEVENTH_DFTC_H()
#define ChkL1MsgFltr_UL1D_DFTC_RX_TAG()	ChkL1ClsFltr_UL1D_SEVENTH_DFTC_H()
#define ChkL1MsgFltr_UL1D_DFTC_TX_TAG()	ChkL1ClsFltr_UL1D_SEVENTH_DFTC_H()
#define ChkL1MsgFltr_UL1D_DFTC_TRX_DIFF_UPDATE()	ChkL1ClsFltr_UL1D_SEVENTH_DFTC_H()
#define ChkL1MsgFltr_UL1D_DFTC_TX_TXCRP()	ChkL1ClsFltr_UL1D_SEVENTH_DFTC_H()
#define ChkL1MsgFltr_UL1D_DFTC_RXDFE_DEBUG0()	ChkL1ClsFltr_UL1D_SEVENTH_DFTC_H()
#define ChkL1MsgFltr_UL1D_DFTC_OFFLINE_PAC_SYNC()	ChkL1ClsFltr_UL1D_SEVENTH_DFTC_H()
#define ChkL1MsgFltr_UL1D_DFTC_OFFLINE_DCXOADJ()	ChkL1ClsFltr_UL1D_SEVENTH_DFTC_H()
#define ChkL1MsgFltr_UL1D_DFTC_OFFLINE_X_MAPPING()	ChkL1ClsFltr_UL1D_SEVENTH_DFTC_H()
#define ChkL1MsgFltr_UL1D_DFTC_ADV_RET()	ChkL1ClsFltr_UL1D_SEVENTH_DFTC_M()
#define ChkL1MsgFltr_UL1D_DFTC_ADV_RET_EVENT()	ChkL1ClsFltr_UL1D_SEVENTH_DFTC_M()
#define ChkL1MsgFltr_UL1D_DFTC_WIN_TRK_PAC_ADDR()	ChkL1ClsFltr_UL1D_SEVENTH_DFTC_M()
#define ChkL1MsgFltr_UL1D_DFTC_WIN_TRK_EVENT()	ChkL1ClsFltr_UL1D_SEVENTH_DFTC_M()
#define ChkL1MsgFltr_UL1D_DFTC_TX_OFFSET1()	ChkL1ClsFltr_UL1D_SEVENTH_DFTC_H()
#define ChkL1MsgFltr_UL1D_DFTC_TX_OFFSET2()	ChkL1ClsFltr_UL1D_SEVENTH_DFTC_H()
#define ChkL1MsgFltr_UL1D_DFTC_TX_OFFSET3()	ChkL1ClsFltr_UL1D_SEVENTH_DFTC_H()
#define ChkL1MsgFltr_UL1D_DFTC_TX_OFFSET4()	ChkL1ClsFltr_UL1D_SEVENTH_DFTC_H()
#define ChkL1MsgFltr_UL1D_DFTC_TX_OFFSET5()	ChkL1ClsFltr_UL1D_SEVENTH_DFTC_H()
#define ChkL1MsgFltr_UL1D_DFTC_TX_OFFSET6()	ChkL1ClsFltr_UL1D_SEVENTH_DFTC_H()
#define ChkL1MsgFltr_UL1D_DFTC_RXRTR()	ChkL1ClsFltr_UL1D_SEVENTH_DFTC_H()
#define ChkL1MsgFltr_UL1D_DFTC_TX_MNTR()	ChkL1ClsFltr_UL1D_SEVENTH_DFTC_H()
#define ChkL1MsgFltr_UL1D_DFTC_DEBUG()	ChkL1ClsFltr_UL1D_SEVENTH_DFTC_H()
#define ChkL1MsgFltr_UL1D_DFTC_SET_INIT_ON()	ChkL1ClsFltr_UL1D_SEVENTH_DFTC_H()
#define ChkL1MsgFltr_UL1D_DFTC_INIT_SETTING()	ChkL1ClsFltr_UL1D_SEVENTH_DFTC_H()
#define ChkL1MsgFltr_UL1D_DFTC_CELL_TM()	ChkL1ClsFltr_UL1D_SEVENTH_DFTC_MS3_L()
#define ChkL1MsgFltr_UL1D_DFTC_MS3_PEAK()	ChkL1ClsFltr_UL1D_SEVENTH_DFTC_MS3_L()
#define ChkL1MsgFltr_UL1D_DFTC_DD_START_TIME()	ChkL1ClsFltr_UL1D_SEVENTH_DFTC_MS3_L()
#define ChkL1MsgFltr_UL1D_DFTC_DD_PROCESS_TIME()	ChkL1ClsFltr_UL1D_SEVENTH_DFTC_MS3_L()
#define ChkL1MsgFltr_UL1D_DFTC_CSIRQ_TIME()	ChkL1ClsFltr_UL1D_SEVENTH_DFTC_MS3_L()
#define ChkL1MsgFltr_UL1D_DFTC_MS3_CONB()	ChkL1ClsFltr_UL1D_SEVENTH_DFTC_MS3_L()
#define ChkL1MsgFltr_UL1D_DFTC_DD_ERROR()	ChkL1ClsFltr_UL1D_SEVENTH_DFTC_MS3_L()
#define ChkL1MsgFltr_UL1D_DFTC_MS3_STATUS()	ChkL1ClsFltr_UL1D_SEVENTH_DFTC_MS3_L()
#define ChkL1MsgFltr_UL1D_DFTC_MS3_CON0()	ChkL1ClsFltr_UL1D_SEVENTH_DFTC_MS3_L()
#define ChkL1MsgFltr_UL1D_DFTC_MS3_CON1()	ChkL1ClsFltr_UL1D_SEVENTH_DFTC_MS3_L()
#define ChkL1MsgFltr_UL1D_DFTC_MS3_CON2()	ChkL1ClsFltr_UL1D_SEVENTH_DFTC_MS3_L()
#define ChkL1MsgFltr_UL1D_DFTC_MS3_DBG()	ChkL1ClsFltr_UL1D_SEVENTH_DFTC_MS3_L()
#define ChkL1MsgFltr_UL1D_DFTC_DD_STATUS()	ChkL1ClsFltr_UL1D_SEVENTH_DFTC_MS3_L()
#define ChkL1MsgFltr_UL1D_DFTC_STC_STATUS()	ChkL1ClsFltr_UL1D_SEVENTH_DFTC_MS3_L()
#define ChkL1MsgFltr_UL1D_DFTC_STC_SW()	ChkL1ClsFltr_UL1D_SEVENTH_DFTC_MS3_L()
#define ChkL1MsgFltr_UL1D_TRC_STA_DET_MAIN_PATH()	ChkL1ClsFltr_UL1D_SEVENTH_STA_DET_M()
#define ChkL1MsgFltr_UL1D_TRC_STA_DET_SUB_PATH()	ChkL1ClsFltr_UL1D_SEVENTH_STA_DET_M()
#define ChkL1MsgFltr_UL1D_TRC_STA_DET_CHECK()	ChkL1ClsFltr_UL1D_SEVENTH_STA_DET_M()
#define ChkL1MsgFltr_UL1D_TRC_GEMI2_SUSPEND_BIT_MASK()	ChkL1ClsFltr_UL1D_SEVENTH_GEMINI_2_0_M()
#define ChkL1MsgFltr_UL1D_TRC_GEMI2_SIM2_PREEMPT_COUNT()	ChkL1ClsFltr_UL1D_SEVENTH_GEMINI_2_0_M()
#define ChkL1MsgFltr_UL1D_TRC_GEMI2_RX_SUSPEND()	ChkL1ClsFltr_UL1D_SEVENTH_GEMINI_2_0_M()
#define ChkL1MsgFltr_UL1D_TRC_GEMI2_TX_SUSPEND()	ChkL1ClsFltr_UL1D_SEVENTH_GEMINI_2_0_M()
#define ChkL1MsgFltr_UL1D_TRC_GEMI2_HSDSCH_GAP_BITMAP()	ChkL1ClsFltr_UL1D_SEVENTH_GEMINI_2_0_L()
#define ChkL1MsgFltr_UL1D_TRC_GEMI2_USIM_RX_BYPASS_CHECK()	ChkL1ClsFltr_UL1D_SEVENTH_GEMINI_2_0_M()
#define ChkL1MsgFltr_UL1D_TRC_GEMI2_USIM_HSRX_FORCE_GAP()	ChkL1ClsFltr_UL1D_SEVENTH_GEMINI_2_0_M()
#define ChkL1MsgFltr_UL1D_TRC_GEMI2_USIM_HSTX_HAQ_FORCE_GAP()	ChkL1ClsFltr_UL1D_SEVENTH_GEMINI_2_0_M()
#define ChkL1MsgFltr_UL1D_TRC_GEMI2_USIM_HSTX_CQI_FORCE_GAP()	ChkL1ClsFltr_UL1D_SEVENTH_GEMINI_2_0_M()
#define ChkL1MsgFltr_UL1D_TRC_GEMI2_RACH_GAP_BITMAP()	ChkL1ClsFltr_UL1D_SEVENTH_GEMINI_2_0_M()
#define ChkL1MsgFltr_UL1D_TRC_GEMI2_CPC_ULDPCCH_FDPCH_INFO()	ChkL1ClsFltr_UL1D_SEVENTH_GEMINI_2_0_M()
#define ChkL1MsgFltr_UL1D_TRC_GEMI2_EFACH_DELAY_RECEIVE_CNT()	ChkL1ClsFltr_UL1D_SEVENTH_GEMINI_2_0_M()
#define ChkL1MsgFltr_UL1D_TRC_GEMI2_STS_HSDSCH_RESET()	ChkL1ClsFltr_UL1D_SEVENTH_G2_STS_M()
#define ChkL1MsgFltr_UL1D_TRC_GEMI2_STS_HSDSCH_NUMBER()	ChkL1ClsFltr_UL1D_SEVENTH_G2_STS_M()
#define ChkL1MsgFltr_UL1D_TRC_GEMI2_STS_EDCH_RESET()	ChkL1ClsFltr_UL1D_SEVENTH_G2_STS_M()
#define ChkL1MsgFltr_UL1D_TRC_GEMI2_STS_EDCH_NUMBER()	ChkL1ClsFltr_UL1D_SEVENTH_G2_STS_M()
#define ChkL1MsgFltr_UL1D_TRC_MTCMOS_STATUS()	ChkL1ClsFltr_UL1D_SEVENTH_MTCMOS_M()
#define ChkL1MsgFltr_UL1D_TRC_MTCMOS_EVENT()	ChkL1ClsFltr_UL1D_SEVENTH_MTCMOS_M()
#define ChkL1MsgFltr_UL1D_TRC_MTCMOS_DBG()	ChkL1ClsFltr_UL1D_SEVENTH_MTCMOS_M()


#endif
