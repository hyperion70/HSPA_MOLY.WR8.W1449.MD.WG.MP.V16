#ifndef L1TRC_UL1D_HSPA_THIRD_DEF_H
#define L1TRC_UL1D_HSPA_THIRD_DEF_H

/******************************/
/* String category definition */
/******************************/
#define UL1D_TRC_STR_TXUPC_DBG(v1)  (unsigned char)(v1+0)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_TXUPC_POW_STA_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x0019, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_POW_STA_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_POW_STA_INT16_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x0019, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_TXUPC_POW_STA_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x0119, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_POW_STA_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_POW_STA_INT16X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x0119, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_POW_STA_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x0219, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_POW_STA_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_POW_STA_INT32_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x0219, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HS_DPCCH_SYM_OFFSET(v1) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x0319, (short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_HS_DPCCH_SYM_OFFSET(v1)
#endif
#define UL1D_TRC_HS_DPCCH_SYM_OFFSET_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x0319, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_TXUPC_POW_CHECK_INT16(v1, v2, v3, v4, v5) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0419, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_POW_CHECK_INT16(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_TXUPC_POW_CHECK_INT16_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0419, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_TXUPC_POW_CHECK_ISSUE() do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0519, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_POW_CHECK_ISSUE()
#endif
#define UL1D_TRC_TXUPC_POW_CHECK_ISSUE_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0519, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_TXUPC_POW_CHECK_PRF_CAL(v1, v2) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0619, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_POW_CHECK_PRF_CAL(v1, v2)
#endif
#define UL1D_TRC_TXUPC_POW_CHECK_PRF_CAL_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0619, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_ADDSC_STA_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x0719, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_ADDSC_STA_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_ADDSC_STA_INT16_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x0719, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_ADDSC_STA_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x0819, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_ADDSC_STA_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_ADDSC_STA_INT16X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x0819, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_ADDSC_STA_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x0919, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_ADDSC_STA_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_ADDSC_STA_INT32_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x0919, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_TXUPC_UPC_STA_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x0A19, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_UPC_STA_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_UPC_STA_INT16_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x0A19, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_UPC_STA_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x0B19, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_UPC_STA_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_UPC_STA_INT16X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x0B19, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_TXUPC_UPC_STA_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x0C19, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_UPC_STA_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_UPC_STA_INT32_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x0C19, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_TXUPC_RF_BSI_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x0D19, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_RF_BSI_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_RF_BSI_INT16_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x0D19, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_TXUPC_RF_BSI_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x0E19, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_RF_BSI_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_RF_BSI_INT16X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x0E19, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_RF_BSI_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x0F19, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_RF_BSI_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_RF_BSI_INT32_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x0F19, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_RF_BSI_L_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x1019, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_RF_BSI_L_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_RF_BSI_L_INT16_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x1019, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_IQDC_COMP_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x1119, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_IQDC_COMP_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_IQDC_COMP_INT16_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x1119, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_IQDC_COMP_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x1219, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_IQDC_COMP_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_IQDC_COMP_INT16X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x1219, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_IQDC_COMP_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x1319, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_IQDC_COMP_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_IQDC_COMP_INT32_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x1319, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_PA_BSI_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x1419, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_PA_BSI_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_PA_BSI_INT16_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x1419, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_PA_BSI_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x1519, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_PA_BSI_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_PA_BSI_INT16X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x1519, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_PA_BSI_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x1619, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_PA_BSI_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_PA_BSI_INT32_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x1619, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_PA_STA_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x1719, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_PA_STA_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_PA_STA_INT16_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x1719, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_PA_STA_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x1819, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_PA_STA_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_PA_STA_INT16X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x1819, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_PA_STA_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x1919, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_PA_STA_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_PA_STA_INT32_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x1919, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_MPR_STA_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x1A19, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_MPR_STA_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_MPR_STA_INT16_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x1A19, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_MPR_STA_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x1B19, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_MPR_STA_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_MPR_STA_INT16X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x1B19, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_MPR_STA_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x1C19, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_MPR_STA_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_MPR_STA_INT32_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x1C19, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_AUX_STA_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x1D19, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_AUX_STA_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_AUX_STA_INT16_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x1D19, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_AUX_STA_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x1E19, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_AUX_STA_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_AUX_STA_INT16X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x1E19, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_AUX_STA_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x1F19, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_AUX_STA_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_AUX_STA_INT32_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x1F19, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_GAIN_STA_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x2019, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_GAIN_STA_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_GAIN_STA_INT16_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x2019, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_GAIN_STA_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x2119, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_GAIN_STA_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_GAIN_STA_INT16X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x2119, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_GAIN_STA_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x2219, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_GAIN_STA_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_GAIN_STA_INT32_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x2219, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_DELTA_STA_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x2319, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_DELTA_STA_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_DELTA_STA_INT16_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x2319, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_DELTA_STA_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x2419, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_DELTA_STA_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_DELTA_STA_INT16X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x2419, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_DELTA_STA_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x2519, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_DELTA_STA_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_DELTA_STA_INT32_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x2519, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_RTR_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x01)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x2619, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_RTR_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_RTR_INT16_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x2619, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_RTR_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x01)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x2719, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_RTR_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_RTR_INT16X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x2719, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_RTR_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x01)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x2819, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_RTR_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_RTR_INT32_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x2819, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_DBG_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x2919, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_DBG_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_DBG_INT16_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x2919, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_DBG_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x2A19, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_DBG_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_DBG_INT16X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x2A19, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_DBG_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x2B19, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_DBG_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_DBG_INT32_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x2B19, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_GENERAL_DEBUG(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x2C19, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define UL1D_TRC_GENERAL_DEBUG(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_GENERAL_DEBUG_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_5_DATA(TRC_MERGE_2S(0x2C19, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_LOW_POWER_DEBUG(v1, v2, v3, v4, v5) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x2D19, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define UL1D_TRC_LOW_POWER_DEBUG(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_LOW_POWER_DEBUG_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_2S(0x2D19, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TIME_MAC_R99_DBG(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2E19, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TIME_MAC_R99_DBG(v1, v2, v3, v4)
#endif
#define UL1D_TRC_TIME_MAC_R99_DBG_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2E19, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TIME_MAC_R6_DBG(v1, v2) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2F19, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TIME_MAC_R6_DBG(v1, v2)
#endif
#define UL1D_TRC_TIME_MAC_R6_DBG_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2F19, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_ETXCRP_TICK_INFO(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x3019, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v7));\
	} while(0)
#else
	#define UL1D_TRC_ETXCRP_TICK_INFO(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1D_TRC_ETXCRP_TICK_INFO_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_5_DATA(TRC_MERGE_2S(0x3019, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v7))

#if defined(L1_CATCHER)
	#define UL1D_TRC_ETXCRP_RESTRIC_ETFC_INFO(v1, v2, v3) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3119, (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_ETXCRP_RESTRIC_ETFC_INFO(v1, v2, v3)
#endif
#define UL1D_TRC_ETXCRP_RESTRIC_ETFC_INFO_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3119, (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_ETXCRP_RV_INDEX(v1) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3219, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_ETXCRP_RV_INDEX(v1)
#endif
#define UL1D_TRC_ETXCRP_RV_INDEX_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3219, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_ETXBRP_TIMING(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[4]&0x08)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x3319, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_ETXBRP_TIMING(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_ETXBRP_TIMING_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x3319, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_ETXBRP_ENCODE_TIME(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x3419, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_ETXBRP_ENCODE_TIME(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_ETXBRP_ENCODE_TIME_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_5_DATA(TRC_MERGE_2S(0x3419, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_ERX_AG_RSLT(v1, v2) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3519, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_ERX_AG_RSLT(v1, v2)
#endif
#define UL1D_TRC_ERX_AG_RSLT_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3519, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_ERX_HI_RSLT(v1, v2, v3) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[4]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3619, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_ERX_HI_RSLT(v1, v2, v3)
#endif
#define UL1D_TRC_ERX_HI_RSLT_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3619, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_ERX_RG_RSLT(v1, v2) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[4]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3719, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_ERX_RG_RSLT(v1, v2)
#endif
#define UL1D_TRC_ERX_RG_RSLT_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3719, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_ERX_RG_LOW_INT() do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[4]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3819, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_ERX_RG_LOW_INT()
#endif
#define UL1D_TRC_ERX_RG_LOW_INT_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3819, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_ERX_HI_SOFT_DEBUG(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[4]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3919, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_ERX_HI_SOFT_DEBUG(v1, v2, v3, v4)
#endif
#define UL1D_TRC_ERX_HI_SOFT_DEBUG_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3919, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_ERX_HI_INT_DEBUG(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[4]&0x40)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x3A19, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_ERX_HI_INT_DEBUG(v1, v2, v3, v4)
#endif
#define UL1D_TRC_ERX_HI_INT_DEBUG_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x3A19, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_ERX_RG_DEBUG(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[4]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3B19, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_ERX_RG_DEBUG(v1, v2, v3, v4)
#endif
#define UL1D_TRC_ERX_RG_DEBUG_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3B19, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_ERX_RG_INT_DEBUG(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[4]&0x20)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x3C19, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_ERX_RG_INT_DEBUG(v1, v2, v3, v4)
#endif
#define UL1D_TRC_ERX_RG_INT_DEBUG_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x3C19, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define UL1D_TRC_ERX_HI_NACK_BOOST(v1, v2) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3D19, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_ERX_HI_NACK_BOOST(v1, v2)
#endif
#define UL1D_TRC_ERX_HI_NACK_BOOST_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3D19, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_ERX_E2_HIRG_MIC_RLS(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[4]&0x20)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x3E19, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_ERX_E2_HIRG_MIC_RLS(v1, v2, v3, v4)
#endif
#define UL1D_TRC_ERX_E2_HIRG_MIC_RLS_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x3E19, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_ERX_E2_HIRG_PACK_FABIAS(v1, v2, v3) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[4]&0x20)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x3F19, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_ERX_E2_HIRG_PACK_FABIAS(v1, v2, v3)
#endif
#define UL1D_TRC_ERX_E2_HIRG_PACK_FABIAS_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x3F19, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_ERX_E2_RG_TH(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[4]&0x20)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x4019, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_ERX_E2_RG_TH(v1, v2, v3, v4)
#endif
#define UL1D_TRC_ERX_E2_RG_TH_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x4019, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_FRAMERATE_INFO(v1, v2, v3, v4, v5) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4119, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define UL1D_TRC_FRAMERATE_INFO(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_FRAMERATE_INFO_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4119, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_FRAMERATE_RTR_INFO(v1, v2) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4219, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_FRAMERATE_RTR_INFO(v1, v2)
#endif
#define UL1D_TRC_FRAMERATE_RTR_INFO_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4219, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_UL_DCH_POW_IND_INT32(v1, v2, v3) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4319, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_UL_DCH_POW_IND_INT32(v1, v2, v3)
#endif
#define UL1D_TRC_UL_DCH_POW_IND_INT32_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4319, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_UL_DCH_DPCCH_BITMAP_INT32(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x4419, (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_4C((unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_UL_DCH_DPCCH_BITMAP_INT32(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_UL_DCH_DPCCH_BITMAP_INT32_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_5_DATA(TRC_MERGE_2S(0x4419, (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_4C((unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_UL_DCH_EDCH_BITMAP_INT32(v1, v2, v3) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4519, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_UL_DCH_EDCH_BITMAP_INT32(v1, v2, v3)
#endif
#define UL1D_TRC_UL_DCH_EDCH_BITMAP_INT32_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4519, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char UL1D_HSPA_THIRD_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_UL1D_TRC_TXUPC_POW_STA_INT16(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_POW_STA_INT16X(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10, unsigned short v11, unsigned short v12, unsigned short v13, unsigned short v14, unsigned short v15, unsigned short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_POW_STA_INT32(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15, unsigned long v16);
void L1TRC_Send_UL1D_TRC_HS_DPCCH_SYM_OFFSET(short v1);
void L1TRC_Send_UL1D_TRC_TXUPC_POW_CHECK_INT16(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_UL1D_TRC_TXUPC_POW_CHECK_ISSUE(void);
void L1TRC_Send_UL1D_TRC_TXUPC_POW_CHECK_PRF_CAL(char v1, char v2);
void L1TRC_Send_UL1D_TRC_TXUPC_ADDSC_STA_INT16(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_ADDSC_STA_INT16X(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10, unsigned short v11, unsigned short v12, unsigned short v13, unsigned short v14, unsigned short v15, unsigned short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_ADDSC_STA_INT32(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15, unsigned long v16);
void L1TRC_Send_UL1D_TRC_TXUPC_UPC_STA_INT16(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_UPC_STA_INT16X(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10, unsigned short v11, unsigned short v12, unsigned short v13, unsigned short v14, unsigned short v15, unsigned short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_UPC_STA_INT32(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15, unsigned long v16);
void L1TRC_Send_UL1D_TRC_TXUPC_RF_BSI_INT16(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_RF_BSI_INT16X(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10, unsigned short v11, unsigned short v12, unsigned short v13, unsigned short v14, unsigned short v15, unsigned short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_RF_BSI_INT32(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15, unsigned long v16);
void L1TRC_Send_UL1D_TRC_TXUPC_RF_BSI_L_INT16(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_IQDC_COMP_INT16(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_IQDC_COMP_INT16X(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10, unsigned short v11, unsigned short v12, unsigned short v13, unsigned short v14, unsigned short v15, unsigned short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_IQDC_COMP_INT32(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15, unsigned long v16);
void L1TRC_Send_UL1D_TRC_TXUPC_PA_BSI_INT16(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_PA_BSI_INT16X(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10, unsigned short v11, unsigned short v12, unsigned short v13, unsigned short v14, unsigned short v15, unsigned short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_PA_BSI_INT32(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15, unsigned long v16);
void L1TRC_Send_UL1D_TRC_TXUPC_PA_STA_INT16(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_PA_STA_INT16X(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10, unsigned short v11, unsigned short v12, unsigned short v13, unsigned short v14, unsigned short v15, unsigned short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_PA_STA_INT32(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15, unsigned long v16);
void L1TRC_Send_UL1D_TRC_TXUPC_MPR_STA_INT16(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_MPR_STA_INT16X(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10, unsigned short v11, unsigned short v12, unsigned short v13, unsigned short v14, unsigned short v15, unsigned short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_MPR_STA_INT32(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15, unsigned long v16);
void L1TRC_Send_UL1D_TRC_TXUPC_AUX_STA_INT16(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_AUX_STA_INT16X(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10, unsigned short v11, unsigned short v12, unsigned short v13, unsigned short v14, unsigned short v15, unsigned short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_AUX_STA_INT32(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15, unsigned long v16);
void L1TRC_Send_UL1D_TRC_TXUPC_GAIN_STA_INT16(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_GAIN_STA_INT16X(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10, unsigned short v11, unsigned short v12, unsigned short v13, unsigned short v14, unsigned short v15, unsigned short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_GAIN_STA_INT32(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15, unsigned long v16);
void L1TRC_Send_UL1D_TRC_TXUPC_DELTA_STA_INT16(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_DELTA_STA_INT16X(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10, unsigned short v11, unsigned short v12, unsigned short v13, unsigned short v14, unsigned short v15, unsigned short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_DELTA_STA_INT32(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15, unsigned long v16);
void L1TRC_Send_UL1D_TRC_TXUPC_RTR_INT16(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_RTR_INT16X(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10, unsigned short v11, unsigned short v12, unsigned short v13, unsigned short v14, unsigned short v15, unsigned short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_RTR_INT32(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15, unsigned long v16);
void L1TRC_Send_UL1D_TRC_TXUPC_DBG_INT16(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_DBG_INT16X(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10, unsigned short v11, unsigned short v12, unsigned short v13, unsigned short v14, unsigned short v15, unsigned short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_DBG_INT32(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15, unsigned long v16);
void L1TRC_Send_UL1D_TRC_GENERAL_DEBUG(short v1, short v2, short v3, short v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_UL1D_TRC_LOW_POWER_DEBUG(short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_UL1D_TRC_TIME_MAC_R99_DBG(short v1, short v2, short v3, short v4);
void L1TRC_Send_UL1D_TRC_TIME_MAC_R6_DBG(short v1, short v2);
void L1TRC_Send_UL1D_TRC_ETXCRP_TICK_INFO(unsigned char v1, short v2, short v3, short v4, short v5, short v6, long v7);
void L1TRC_Send_UL1D_TRC_ETXCRP_RESTRIC_ETFC_INFO(char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_ETXCRP_RV_INDEX(unsigned char v1);
void L1TRC_Send_UL1D_TRC_ETXBRP_TIMING(short v1, short v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_UL1D_TRC_ETXBRP_ENCODE_TIME(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, short v7, short v8);
void L1TRC_Send_UL1D_TRC_ERX_AG_RSLT(unsigned char v1, unsigned char v2);
void L1TRC_Send_UL1D_TRC_ERX_HI_RSLT(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_ERX_RG_RSLT(unsigned char v1, unsigned char v2);
void L1TRC_Send_UL1D_TRC_ERX_RG_LOW_INT(void);
void L1TRC_Send_UL1D_TRC_ERX_HI_SOFT_DEBUG(short v1, short v2, short v3, short v4);
void L1TRC_Send_UL1D_TRC_ERX_HI_INT_DEBUG(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_UL1D_TRC_ERX_RG_DEBUG(short v1, short v2, short v3, short v4);
void L1TRC_Send_UL1D_TRC_ERX_RG_INT_DEBUG(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_UL1D_TRC_ERX_HI_NACK_BOOST(unsigned char v1, unsigned char v2);
void L1TRC_Send_UL1D_TRC_ERX_E2_HIRG_MIC_RLS(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_UL1D_TRC_ERX_E2_HIRG_PACK_FABIAS(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_UL1D_TRC_ERX_E2_RG_TH(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_UL1D_TRC_FRAMERATE_INFO(unsigned short v1, unsigned short v2, short v3, short v4, short v5);
void L1TRC_Send_UL1D_TRC_FRAMERATE_RTR_INFO(unsigned short v1, unsigned short v2);
void L1TRC_Send_UL1D_TRC_UL_DCH_POW_IND_INT32(unsigned long v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_UL1D_TRC_UL_DCH_DPCCH_BITMAP_INT32(unsigned long v1, unsigned long v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned char v6);
void L1TRC_Send_UL1D_TRC_UL_DCH_EDCH_BITMAP_INT32(unsigned long v1, unsigned short v2, unsigned short v3);

void Set_UL1D_HSPA_THIRD_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_UL1D_HSPA_THIRD()	(UL1D_HSPA_THIRD_Trace_Filter[0]==1)
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_DBG_TXUPC_M()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_DBG_TXUPC_DUMP_M()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_DBG_RXBRP_M()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_POW_STA_M()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_POW_CHECK_M()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_ADDSC_STA_L()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_UPC_STA_M()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_RF_BSI_M()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_RF_BSI_L()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_IQDC_COMP_L()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_PA_BSI_L()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_PA_STA_L()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[2]&0x08)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_MPR_STA_L()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[2]&0x10)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_AUX_STA_L()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[2]&0x20)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_GAIN_STA_L()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[2]&0x40)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_DELTA_STA_L()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[2]&0x80)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_RTR_L()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[3]&0x01)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_DBG_L()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[3]&0x02)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_RXBRP_DBG_M()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[3]&0x04)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_RXBRP_DBG_L()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[3]&0x08)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_DBG_M()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[3]&0x10)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_MAC_TIME_L()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[3]&0x20)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_MAC_TIME_M()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[3]&0x40)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_ETXCRP_H()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[3]&0x80)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_ETXCRP_M()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[4]&0x01)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_ETXCRP_L()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[4]&0x02)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_ETXBRP_M()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[4]&0x04)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_ETXBRP_L()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[4]&0x08)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_ERX_H()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[4]&0x10)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_ERX_M()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[4]&0x20)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_ERX_L()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[4]&0x40)!=0))
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_POW_STA_INT16()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_POW_STA_M()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_POW_STA_INT16X()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_POW_STA_M()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_POW_STA_INT32()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_DBG_L()
#define ChkL1MsgFltr_UL1D_TRC_HS_DPCCH_SYM_OFFSET()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_POW_STA_M()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_POW_CHECK_INT16()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_POW_CHECK_M()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_POW_CHECK_ISSUE()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_POW_CHECK_M()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_POW_CHECK_PRF_CAL()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_POW_CHECK_M()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_ADDSC_STA_INT16()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_ADDSC_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_ADDSC_STA_INT16X()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_ADDSC_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_ADDSC_STA_INT32()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_ADDSC_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_UPC_STA_INT16()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_UPC_STA_M()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_UPC_STA_INT16X()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_DBG_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_UPC_STA_INT32()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_UPC_STA_M()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_RF_BSI_INT16()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_RF_BSI_M()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_RF_BSI_INT16X()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_RF_BSI_M()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_RF_BSI_INT32()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_DBG_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_RF_BSI_L_INT16()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_RF_BSI_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_IQDC_COMP_INT16()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_IQDC_COMP_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_IQDC_COMP_INT16X()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_IQDC_COMP_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_IQDC_COMP_INT32()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_IQDC_COMP_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_PA_BSI_INT16()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_PA_BSI_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_PA_BSI_INT16X()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_PA_BSI_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_PA_BSI_INT32()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_PA_BSI_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_PA_STA_INT16()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_PA_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_PA_STA_INT16X()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_PA_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_PA_STA_INT32()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_PA_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_MPR_STA_INT16()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_MPR_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_MPR_STA_INT16X()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_MPR_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_MPR_STA_INT32()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_MPR_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_AUX_STA_INT16()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_AUX_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_AUX_STA_INT16X()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_AUX_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_AUX_STA_INT32()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_AUX_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_GAIN_STA_INT16()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_GAIN_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_GAIN_STA_INT16X()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_GAIN_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_GAIN_STA_INT32()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_GAIN_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_DELTA_STA_INT16()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_DELTA_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_DELTA_STA_INT16X()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_DELTA_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_DELTA_STA_INT32()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_DELTA_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_RTR_INT16()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_RTR_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_RTR_INT16X()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_RTR_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_RTR_INT32()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_RTR_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_DBG_INT16()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_DBG_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_DBG_INT16X()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_DBG_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_DBG_INT32()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_DBG_L()
#define ChkL1MsgFltr_UL1D_TRC_GENERAL_DEBUG()	ChkL1ClsFltr_UL1D_HSPA_THIRD_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_LOW_POWER_DEBUG()	ChkL1ClsFltr_UL1D_HSPA_THIRD_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_TIME_MAC_R99_DBG()	ChkL1ClsFltr_UL1D_HSPA_THIRD_MAC_TIME_L()
#define ChkL1MsgFltr_UL1D_TRC_TIME_MAC_R6_DBG()	ChkL1ClsFltr_UL1D_HSPA_THIRD_MAC_TIME_L()
#define ChkL1MsgFltr_UL1D_TRC_ETXCRP_TICK_INFO()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ETXCRP_M()
#define ChkL1MsgFltr_UL1D_TRC_ETXCRP_RESTRIC_ETFC_INFO()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ETXCRP_H()
#define ChkL1MsgFltr_UL1D_TRC_ETXCRP_RV_INDEX()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ETXCRP_L()
#define ChkL1MsgFltr_UL1D_TRC_ETXBRP_TIMING()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ETXBRP_L()
#define ChkL1MsgFltr_UL1D_TRC_ETXBRP_ENCODE_TIME()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ETXBRP_M()
#define ChkL1MsgFltr_UL1D_TRC_ERX_AG_RSLT()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ERX_H()
#define ChkL1MsgFltr_UL1D_TRC_ERX_HI_RSLT()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ERX_M()
#define ChkL1MsgFltr_UL1D_TRC_ERX_RG_RSLT()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ERX_M()
#define ChkL1MsgFltr_UL1D_TRC_ERX_RG_LOW_INT()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ERX_M()
#define ChkL1MsgFltr_UL1D_TRC_ERX_HI_SOFT_DEBUG()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ERX_M()
#define ChkL1MsgFltr_UL1D_TRC_ERX_HI_INT_DEBUG()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ERX_L()
#define ChkL1MsgFltr_UL1D_TRC_ERX_RG_DEBUG()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ERX_M()
#define ChkL1MsgFltr_UL1D_TRC_ERX_RG_INT_DEBUG()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ERX_M()
#define ChkL1MsgFltr_UL1D_TRC_ERX_HI_NACK_BOOST()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ERX_H()
#define ChkL1MsgFltr_UL1D_TRC_ERX_E2_HIRG_MIC_RLS()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ERX_M()
#define ChkL1MsgFltr_UL1D_TRC_ERX_E2_HIRG_PACK_FABIAS()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ERX_M()
#define ChkL1MsgFltr_UL1D_TRC_ERX_E2_RG_TH()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ERX_M()
#define ChkL1MsgFltr_UL1D_TRC_FRAMERATE_INFO()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_DBG_L()
#define ChkL1MsgFltr_UL1D_TRC_FRAMERATE_RTR_INFO()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_DBG_L()
#define ChkL1MsgFltr_UL1D_TRC_UL_DCH_POW_IND_INT32()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_UPC_STA_M()
#define ChkL1MsgFltr_UL1D_TRC_UL_DCH_DPCCH_BITMAP_INT32()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_UPC_STA_M()
#define ChkL1MsgFltr_UL1D_TRC_UL_DCH_EDCH_BITMAP_INT32()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_UPC_STA_M()


#endif
