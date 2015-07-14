#ifndef L1TRC_L1C_GPRS2_DEF_H
#define L1TRC_L1C_GPRS2_DEF_H

/******************************/
/* String category definition */
/******************************/
#define L1C_Str_Bool(v1)  (unsigned char)(v1+0)
#define RTB_Str_RAT(v1)  (unsigned char)(v1+2)
#define RTB_Str_MODE(v1)  (unsigned char)(v1+6)
#define RTB_Str_BLCOK(v1)  (unsigned char)(v1+8)
#define RTB_Str_Protect(v1)  (unsigned char)(v1+10)
#define RTB_Str_SIM(v1)  (unsigned char)(v1+13)
#define RTB_Str_Channel_Protect(v1)  (unsigned char)(v1+17)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define RTB_Trace_1_GSM(v1, v2, v3, v4, v5, v6) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x0026, (unsigned char)(v1), (unsigned char)(v6)), (long)(v2), (long)(v3), (long)(v4), (long)(v5));\
	} while(0)
#else
	#define RTB_Trace_1_GSM(v1, v2, v3, v4, v5, v6)
#endif
#define RTB_Trace_1_GSM_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x0026, (unsigned char)(v1), (unsigned char)(v6)), (long)(v2), (long)(v3), (long)(v4), (long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define RTB_Trace_1_UMTS(v1, v2, v3, v4, v5, v6) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x0126, (unsigned char)(v1), (unsigned char)(v6)), (long)(v2), (long)(v3), (long)(v4), (long)(v5));\
	} while(0)
#else
	#define RTB_Trace_1_UMTS(v1, v2, v3, v4, v5, v6)
#endif
#define RTB_Trace_1_UMTS_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x0126, (unsigned char)(v1), (unsigned char)(v6)), (long)(v2), (long)(v3), (long)(v4), (long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RTB_Trace_3_GSM(v1, v2, v3, v4, v5, v6, v7) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0226, (short)(v5)), TRC_MERGE_1S2C((short)(v6), (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v7));\
	} while(0)
#else
	#define RTB_Trace_3_GSM(v1, v2, v3, v4, v5, v6, v7)
#endif
#define RTB_Trace_3_GSM_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0226, (short)(v5)), TRC_MERGE_1S2C((short)(v6), (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v7))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RTB_Trace_3_UMTS(v1, v2, v3, v4, v5, v6, v7) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0326, (short)(v5)), TRC_MERGE_1S2C((short)(v6), (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v7));\
	} while(0)
#else
	#define RTB_Trace_3_UMTS(v1, v2, v3, v4, v5, v6, v7)
#endif
#define RTB_Trace_3_UMTS_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0326, (short)(v5)), TRC_MERGE_1S2C((short)(v6), (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v7))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define RTB_Trace_5_GSM(v1, v2, v3, v4) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0426, (unsigned char)(v2), TRC_BOXSTER_PAD), (long)(v1), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define RTB_Trace_5_GSM(v1, v2, v3, v4)
#endif
#define RTB_Trace_5_GSM_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0426, (unsigned char)(v2), TRC_BOXSTER_PAD), (long)(v1), (long)(v3), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define RTB_Trace_5_UMTS(v1, v2, v3, v4) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0526, (unsigned char)(v2), TRC_BOXSTER_PAD), (long)(v1), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define RTB_Trace_5_UMTS(v1, v2, v3, v4)
#endif
#define RTB_Trace_5_UMTS_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0526, (unsigned char)(v2), TRC_BOXSTER_PAD), (long)(v1), (long)(v3), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RTB_Trace_6_GSM(v1, v2, v3) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0626, (char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define RTB_Trace_6_GSM(v1, v2, v3)
#endif
#define RTB_Trace_6_GSM_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0626, (char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RTB_Trace_6_UMTS(v1, v2, v3) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0726, (char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define RTB_Trace_6_UMTS(v1, v2, v3)
#endif
#define RTB_Trace_6_UMTS_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0726, (char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define RTB_Trace_7_GSM(v1, v2) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0826, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2));\
	} while(0)
#else
	#define RTB_Trace_7_GSM(v1, v2)
#endif
#define RTB_Trace_7_GSM_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0826, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define RTB_Trace_7_UMTS(v1, v2) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0926, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2));\
	} while(0)
#else
	#define RTB_Trace_7_UMTS(v1, v2)
#endif
#define RTB_Trace_7_UMTS_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0926, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define RTB_Trace_9_GSM(v1, v2, v3) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0A26, (unsigned char)(v1), (char)(v2)), (long)(v3));\
	} while(0)
#else
	#define RTB_Trace_9_GSM(v1, v2, v3)
#endif
#define RTB_Trace_9_GSM_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0A26, (unsigned char)(v1), (char)(v2)), (long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define RTB_Trace_9_UMTS(v1, v2, v3) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0B26, (unsigned char)(v1), (char)(v2)), (long)(v3));\
	} while(0)
#else
	#define RTB_Trace_9_UMTS(v1, v2, v3)
#endif
#define RTB_Trace_9_UMTS_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0B26, (unsigned char)(v1), (char)(v2)), (long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define RTB_Trace_11_GSM(v1, v2) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0C26, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define RTB_Trace_11_GSM(v1, v2)
#endif
#define RTB_Trace_11_GSM_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0C26, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define RTB_Trace_11_UMTS(v1, v2) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0D26, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define RTB_Trace_11_UMTS(v1, v2)
#endif
#define RTB_Trace_11_UMTS_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0D26, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define RTB_Trace_13(v1, v2) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0E26, (char)(v1), TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define RTB_Trace_13(v1, v2)
#endif
#define RTB_Trace_13_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0E26, (char)(v1), TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define RTB_Trace_14_UMTS(v1, v2) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0F26, (char)(v1), TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define RTB_Trace_14_UMTS(v1, v2)
#endif
#define RTB_Trace_14_UMTS_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0F26, (char)(v1), TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define RTB_Trace_15(v1, v2, v3, v4) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1026, (short)(v2)), TRC_MERGE_1S2C((short)(v4), (char)(v1), (char)(v3)));\
	} while(0)
#else
	#define RTB_Trace_15(v1, v2, v3, v4)
#endif
#define RTB_Trace_15_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1026, (short)(v2)), TRC_MERGE_1S2C((short)(v4), (char)(v1), (char)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define RTB_Trace_20_UMTS(v1) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1126, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define RTB_Trace_20_UMTS(v1)
#endif
#define RTB_Trace_20_UMTS_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1126, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define RTB_Trace_22_GSM(v1, v2, v3, v4, v5, v6, v7) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1226, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v4), (unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v5), (long)(v7));\
	} while(0)
#else
	#define RTB_Trace_22_GSM(v1, v2, v3, v4, v5, v6, v7)
#endif
#define RTB_Trace_22_GSM_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1226, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v4), (unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v5), (long)(v7))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define RTB_Trace_22_UMTS(v1, v2, v3, v4, v5, v6, v7) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1326, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v4), (unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v5), (long)(v7));\
	} while(0)
#else
	#define RTB_Trace_22_UMTS(v1, v2, v3, v4, v5, v6, v7)
#endif
#define RTB_Trace_22_UMTS_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1326, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v4), (unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v5), (long)(v7))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define RTB_Trace_24_UMTS(v1, v2) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1426, (unsigned char)(v2), TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define RTB_Trace_24_UMTS(v1, v2)
#endif
#define RTB_Trace_24_UMTS_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1426, (unsigned char)(v2), TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define RTB_Trace_25_GSM(v1, v2) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1526, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define RTB_Trace_25_GSM(v1, v2)
#endif
#define RTB_Trace_25_GSM_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1526, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define RTB_Trace_25_UMTS(v1, v2, v3) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1626, (unsigned char)(v1), (char)(v3)), (long)(v2));\
	} while(0)
#else
	#define RTB_Trace_25_UMTS(v1, v2, v3)
#endif
#define RTB_Trace_25_UMTS_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1626, (unsigned char)(v1), (char)(v3)), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RTB_Trace_27_GSM(v1) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1726, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define RTB_Trace_27_GSM(v1)
#endif
#define RTB_Trace_27_GSM_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1726, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RTB_Trace_27_UMTS(v1) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1826, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define RTB_Trace_27_UMTS(v1)
#endif
#define RTB_Trace_27_UMTS_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1826, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define RTB_Trace_28_GSM(v1, v2, v3, v4) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1926, (short)(v3)), TRC_MERGE_4C((char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v4));\
	} while(0)
#else
	#define RTB_Trace_28_GSM(v1, v2, v3, v4)
#endif
#define RTB_Trace_28_GSM_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1926, (short)(v3)), TRC_MERGE_4C((char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define RTB_Trace_28_UMTS(v1, v2, v3, v4) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1A26, (short)(v3)), TRC_MERGE_4C((char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v4));\
	} while(0)
#else
	#define RTB_Trace_28_UMTS(v1, v2, v3, v4)
#endif
#define RTB_Trace_28_UMTS_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1A26, (short)(v3)), TRC_MERGE_4C((char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define RTB_Trace_29_GSM(v1) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1B26, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define RTB_Trace_29_GSM(v1)
#endif
#define RTB_Trace_29_GSM_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1B26, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define RTB_Trace_29_UMTS(v1) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1C26, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define RTB_Trace_29_UMTS(v1)
#endif
#define RTB_Trace_29_UMTS_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1C26, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define RTB_Trace_34_GSM(v1) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1D26, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define RTB_Trace_34_GSM(v1)
#endif
#define RTB_Trace_34_GSM_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1D26, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define RTB_Trace_34_UMTS(v1) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1E26, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define RTB_Trace_34_UMTS(v1)
#endif
#define RTB_Trace_34_UMTS_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1E26, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define RTB_Trace_35(v1, v2) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1F26, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2));\
	} while(0)
#else
	#define RTB_Trace_35(v1, v2)
#endif
#define RTB_Trace_35_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1F26, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define RTB_Trace_36(v1, v2, v3, v4) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2026, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define RTB_Trace_36(v1, v2, v3, v4)
#endif
#define RTB_Trace_36_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2026, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define RTB_Trace_38_UMTS(v1, v2, v3) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2126, (unsigned char)(v3), TRC_BOXSTER_PAD), (long)(v1), (long)(v2));\
	} while(0)
#else
	#define RTB_Trace_38_UMTS(v1, v2, v3)
#endif
#define RTB_Trace_38_UMTS_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2126, (unsigned char)(v3), TRC_BOXSTER_PAD), (long)(v1), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define RTB_Trace_39_GSM(v1, v2) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2226, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define RTB_Trace_39_GSM(v1, v2)
#endif
#define RTB_Trace_39_GSM_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2226, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define RTB_Trace_39_UMTS(v1, v2) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2326, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define RTB_Trace_39_UMTS(v1, v2)
#endif
#define RTB_Trace_39_UMTS_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2326, (unsigned char)(v1), (char)(v2)))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char L1C_GPRS2_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_RTB_Trace_1_GSM(unsigned char v1, long v2, long v3, long v4, long v5, unsigned char v6);
void L1TRC_Send_RTB_Trace_1_UMTS(unsigned char v1, long v2, long v3, long v4, long v5, unsigned char v6);
void L1TRC_Send_RTB_Trace_3_GSM(char v1, unsigned char v2, char v3, unsigned char v4, short v5, short v6, long v7);
void L1TRC_Send_RTB_Trace_3_UMTS(char v1, unsigned char v2, char v3, unsigned char v4, short v5, short v6, long v7);
void L1TRC_Send_RTB_Trace_5_GSM(long v1, unsigned char v2, long v3, long v4);
void L1TRC_Send_RTB_Trace_5_UMTS(long v1, unsigned char v2, long v3, long v4);
void L1TRC_Send_RTB_Trace_6_GSM(char v1, long v2, long v3);
void L1TRC_Send_RTB_Trace_6_UMTS(char v1, long v2, long v3);
void L1TRC_Send_RTB_Trace_7_GSM(long v1, long v2);
void L1TRC_Send_RTB_Trace_7_UMTS(long v1, long v2);
void L1TRC_Send_RTB_Trace_9_GSM(unsigned char v1, char v2, long v3);
void L1TRC_Send_RTB_Trace_9_UMTS(unsigned char v1, char v2, long v3);
void L1TRC_Send_RTB_Trace_11_GSM(unsigned char v1, char v2);
void L1TRC_Send_RTB_Trace_11_UMTS(unsigned char v1, char v2);
void L1TRC_Send_RTB_Trace_13(char v1, long v2);
void L1TRC_Send_RTB_Trace_14_UMTS(char v1, long v2);
void L1TRC_Send_RTB_Trace_15(char v1, short v2, char v3, short v4);
void L1TRC_Send_RTB_Trace_20_UMTS(char v1);
void L1TRC_Send_RTB_Trace_22_GSM(unsigned char v1, char v2, long v3, unsigned char v4, long v5, unsigned char v6, long v7);
void L1TRC_Send_RTB_Trace_22_UMTS(unsigned char v1, char v2, long v3, unsigned char v4, long v5, unsigned char v6, long v7);
void L1TRC_Send_RTB_Trace_24_UMTS(long v1, unsigned char v2);
void L1TRC_Send_RTB_Trace_25_GSM(unsigned char v1, char v2);
void L1TRC_Send_RTB_Trace_25_UMTS(unsigned char v1, long v2, char v3);
void L1TRC_Send_RTB_Trace_27_GSM(long v1);
void L1TRC_Send_RTB_Trace_27_UMTS(long v1);
void L1TRC_Send_RTB_Trace_28_GSM(char v1, unsigned char v2, short v3, long v4);
void L1TRC_Send_RTB_Trace_28_UMTS(char v1, unsigned char v2, short v3, long v4);
void L1TRC_Send_RTB_Trace_29_GSM(long v1);
void L1TRC_Send_RTB_Trace_29_UMTS(long v1);
void L1TRC_Send_RTB_Trace_34_GSM(long v1);
void L1TRC_Send_RTB_Trace_34_UMTS(long v1);
void L1TRC_Send_RTB_Trace_35(long v1, long v2);
void L1TRC_Send_RTB_Trace_36(unsigned char v1, char v2, char v3, unsigned char v4);
void L1TRC_Send_RTB_Trace_38_UMTS(long v1, long v2, unsigned char v3);
void L1TRC_Send_RTB_Trace_39_GSM(unsigned char v1, char v2);
void L1TRC_Send_RTB_Trace_39_UMTS(unsigned char v1, char v2);

void Set_L1C_GPRS2_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_L1C_GPRS2()	(L1C_GPRS2_Trace_Filter[0]==1)
#define ChkL1ClsFltr_L1C_GPRS2_RTB_M()	(ChkL1ModFltr_L1C_GPRS2()&&((L1C_GPRS2_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_L1C_GPRS2_RTB_L()	(ChkL1ModFltr_L1C_GPRS2()&&((L1C_GPRS2_Trace_Filter[1]&0x02)!=0))
#define ChkL1MsgFltr_RTB_Trace_1_GSM()	ChkL1ClsFltr_L1C_GPRS2_RTB_M()
#define ChkL1MsgFltr_RTB_Trace_1_UMTS()	ChkL1ClsFltr_L1C_GPRS2_RTB_M()
#define ChkL1MsgFltr_RTB_Trace_3_GSM()	ChkL1ClsFltr_L1C_GPRS2_RTB_L()
#define ChkL1MsgFltr_RTB_Trace_3_UMTS()	ChkL1ClsFltr_L1C_GPRS2_RTB_L()
#define ChkL1MsgFltr_RTB_Trace_5_GSM()	ChkL1ClsFltr_L1C_GPRS2_RTB_M()
#define ChkL1MsgFltr_RTB_Trace_5_UMTS()	ChkL1ClsFltr_L1C_GPRS2_RTB_M()
#define ChkL1MsgFltr_RTB_Trace_6_GSM()	ChkL1ClsFltr_L1C_GPRS2_RTB_L()
#define ChkL1MsgFltr_RTB_Trace_6_UMTS()	ChkL1ClsFltr_L1C_GPRS2_RTB_L()
#define ChkL1MsgFltr_RTB_Trace_7_GSM()	ChkL1ClsFltr_L1C_GPRS2_RTB_M()
#define ChkL1MsgFltr_RTB_Trace_7_UMTS()	ChkL1ClsFltr_L1C_GPRS2_RTB_M()
#define ChkL1MsgFltr_RTB_Trace_9_GSM()	ChkL1ClsFltr_L1C_GPRS2_RTB_M()
#define ChkL1MsgFltr_RTB_Trace_9_UMTS()	ChkL1ClsFltr_L1C_GPRS2_RTB_M()
#define ChkL1MsgFltr_RTB_Trace_11_GSM()	ChkL1ClsFltr_L1C_GPRS2_RTB_M()
#define ChkL1MsgFltr_RTB_Trace_11_UMTS()	ChkL1ClsFltr_L1C_GPRS2_RTB_M()
#define ChkL1MsgFltr_RTB_Trace_13()	ChkL1ClsFltr_L1C_GPRS2_RTB_M()
#define ChkL1MsgFltr_RTB_Trace_14_UMTS()	ChkL1ClsFltr_L1C_GPRS2_RTB_M()
#define ChkL1MsgFltr_RTB_Trace_15()	ChkL1ClsFltr_L1C_GPRS2_RTB_M()
#define ChkL1MsgFltr_RTB_Trace_20_UMTS()	ChkL1ClsFltr_L1C_GPRS2_RTB_M()
#define ChkL1MsgFltr_RTB_Trace_22_GSM()	ChkL1ClsFltr_L1C_GPRS2_RTB_M()
#define ChkL1MsgFltr_RTB_Trace_22_UMTS()	ChkL1ClsFltr_L1C_GPRS2_RTB_M()
#define ChkL1MsgFltr_RTB_Trace_24_UMTS()	ChkL1ClsFltr_L1C_GPRS2_RTB_M()
#define ChkL1MsgFltr_RTB_Trace_25_GSM()	ChkL1ClsFltr_L1C_GPRS2_RTB_M()
#define ChkL1MsgFltr_RTB_Trace_25_UMTS()	ChkL1ClsFltr_L1C_GPRS2_RTB_M()
#define ChkL1MsgFltr_RTB_Trace_27_GSM()	ChkL1ClsFltr_L1C_GPRS2_RTB_L()
#define ChkL1MsgFltr_RTB_Trace_27_UMTS()	ChkL1ClsFltr_L1C_GPRS2_RTB_L()
#define ChkL1MsgFltr_RTB_Trace_28_GSM()	ChkL1ClsFltr_L1C_GPRS2_RTB_M()
#define ChkL1MsgFltr_RTB_Trace_28_UMTS()	ChkL1ClsFltr_L1C_GPRS2_RTB_M()
#define ChkL1MsgFltr_RTB_Trace_29_GSM()	ChkL1ClsFltr_L1C_GPRS2_RTB_M()
#define ChkL1MsgFltr_RTB_Trace_29_UMTS()	ChkL1ClsFltr_L1C_GPRS2_RTB_M()
#define ChkL1MsgFltr_RTB_Trace_34_GSM()	ChkL1ClsFltr_L1C_GPRS2_RTB_M()
#define ChkL1MsgFltr_RTB_Trace_34_UMTS()	ChkL1ClsFltr_L1C_GPRS2_RTB_M()
#define ChkL1MsgFltr_RTB_Trace_35()	ChkL1ClsFltr_L1C_GPRS2_RTB_M()
#define ChkL1MsgFltr_RTB_Trace_36()	ChkL1ClsFltr_L1C_GPRS2_RTB_M()
#define ChkL1MsgFltr_RTB_Trace_38_UMTS()	ChkL1ClsFltr_L1C_GPRS2_RTB_M()
#define ChkL1MsgFltr_RTB_Trace_39_GSM()	ChkL1ClsFltr_L1C_GPRS2_RTB_M()
#define ChkL1MsgFltr_RTB_Trace_39_UMTS()	ChkL1ClsFltr_L1C_GPRS2_RTB_M()


#endif
