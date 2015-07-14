/*******************************************************************************
*  Modification Notice:
*  --------------------------
*  This software is modified by MediaTek Inc. and the information contained
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
*******************************************************************************/


 /*******************************************************************************
 * Filename:
 * ---------
 *   l1_types_public.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Layer1 global types
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Revision:   1.21  $
 * $Modtime:   Aug 05 2005 10:12:46  $
 * $Log:   //mtkvs01/vmdata/Maui_sw/archives/mcu/l1/common/l1_types_public.h-arc  $
 *
 * 10 14 2013 rick.wu
 * [MOLY00041060] [MT6571] Feature for Crystal Thermal Change Improvement
 * .
 *
 * 03 08 2013 samuel.yang
 * [MOLY00011583] [L1TST][Modify] Resize UTS steps for 2G only project
 * .
 *
 * 01 29 2013 samuel.yang
 * [MOLY00009391] [L1TST][Modify] FHC enhancement interface for combining multi-bands to decrease calibration time
 * .
 * 
 * 09 07 2012 samuel.yang
 * [MOLY00002639] [L1D][Modify] Separate l1d_reg.h into two parts of "for l1 internal use" and "for other module use"
 * .
 * 
 * 08 15 2012 sy.yeh
 * [MOLY00001800] [GL1][LL1] R8 APBCR check in
 * . remove __GERAN_R8__ from l1_types_public.h since it is a modem internal option.
 *
 * 01 06 2012 sy.yeh
 * removed!
 * .
 *
 * 12 02 2011 victo.chen
 * removed!
 * .
 *
 * 06 08 2011 samuel.yang
 * removed!
 * .
 *
 *******************************************************************************/

#ifndef l1_types_public_h
#define l1_types_public_h

#include "l1_option.h"
#include "mph_types.h"
#include "kal_general_types.h"

typedef kal_int8   int8;
typedef kal_int16  int16;
typedef kal_int32  int32;
typedef kal_int64  int64;
typedef kal_int32  intx;
typedef kal_uint8  uint8;
typedef kal_uint16 uint16;
typedef kal_uint32 uint32;
typedef kal_uint32 uintx;
typedef kal_bool   bool;

#define false KAL_FALSE
#define true  KAL_TRUE


/* --- GSM primitive types ------------------------------------------------- */

typedef int16  Gain; /* in 0.125 dB *//* !!important: please update the copy in m12194.c */
typedef uint32 TimeStamp; /* redefine in l1-CORE_PRIVATE.H */

typedef enum
{
   FrequencyBand400,
   FrequencyBand850,
   FrequencyBand900,
   FrequencyBand1800,
   FrequencyBand1900,

   FrequencyBandCount
} FrequencyBand;

/*
@enum ReportType_FT | Type of a report for factory testing.
*/
typedef enum
{
   ReportFTNone,             /* @emem No valid report. */
   ReportFTReportPeriodDone, /* @emem End of report period. */
   ReportFTPowerScanDone,    /* @emem Power scan results. */
   ReportFTFCCh,             /* @emem FCCh result. */
#if MD_DRV_IS_FHC_SUPPORT
   ReportFTDTS,
   ReportFTUTS,
#endif
#if MD_DRV_IS_NSFT_SUPPORT
   ReportFTNSFT,
#endif
   ReportFTEnd               /* @emem No valid report. Marks end of <t ReportType> enumeration */
} ReportType_FT;

/* For Gemini*/
typedef enum
{
    L1C_SIM1    = 0x00
#if __GEMINI_GSM__
    ,L1C_SIM2    = 0x01
#endif    
#if (GEMINI_PLUS_GSM >= 3)
    ,L1C_SIM3    = 0x02
#endif    
#if (GEMINI_PLUS_GSM >= 4)
    ,L1C_SIM4    = 0x03
#endif
    ,L1C_SIM_NUM
} l1c_sim_mode_enum;

/*
@struct Time | GSM time.
*/
typedef struct
{
   FrameNumber frame; /* @field Frame number */
   intx        ebits; /* @field Eighth bits */
} Time;

typedef struct MeasurementsStruct Measurements;
struct MeasurementsStruct
{
/* --- must be initialised by called of L1I_StartMeasurements() --- */

   /* not changed by measurement manager */

   ARFCN       ( *get )( Measurements* meas, int index );
   void        ( *put )( Measurements* meas, int index, Power power );
   void        ( *done )( Measurements* meas, intx measurementsDone );

   intx           indexCount;
   intx           measurementCount; /* number of measurements to be performed */

/* --- private data of measurement manager --- */

   intx           started;      /* total number of measurements started */
   intx           finished;     /* total number of measurements completed */
   intx           sessionLimit; /* total number of measurments to be done before session ends */
   intx           startIndex;
   intx           resultIndex;
   bool           is_stopped;
#ifdef __GEMINI_GSM__
   l1c_sim_mode_enum  sim_mode;
#endif
};

#if MD_DRV_IS_FHC_SUPPORT

#define L1_MAX_DTS_STEP_CNT  100
   #if defined(__UMTS_RAT__)
#define L1_MAX_UTS_STEP_CNT  100
   #else
#define L1_MAX_UTS_STEP_CNT   50
   #endif

typedef struct
{
    int32         power[L1_MAX_DTS_STEP_CNT-2];
    int16         valid_sample[L1_MAX_DTS_STEP_CNT-2];
    bool          ok;
} ResultDSSPL;

typedef struct
{
    int32         freq_offset[33];  // only valid when 33 stage calibration is True
    int32         deviation[33];    // only valid when 33 stage calibration is True
    int16         fcb_ok_number[33];
    int32         capid;            // only valid when capid calibration is True
    int16         init_dac_value;   // only valid when 33 stage calibration is False
    int32         slope;            // only valid when 33 stage calibration is False
    bool          ok;
} ResultDSSAfc;

typedef struct
{
    int32         cload_freq_offset;
    bool          ok;
    bool          is_perform_cal;
} ResultDSSLPM;

typedef struct
{
    ResultDSSPL   PLResult;
    ResultDSSAfc  AfcResult;
    ResultDSSLPM  LPMResult;
//  bool          ok;
} ResultDTS;
#endif

/*
@struct SChData | Report data for sync burst reporting.
*/
typedef struct
{
   ARFCN     arfcn;
   bool      ok;            /* @field Sync burst status. Set by the baseband driver.
                               @flag false | Burst was bad. Other fields in this structure are invalid.
                               @flag true | Burst was OK. Other fields in this structure are valid. */
   bool      fcb_ok;
   intx      frameDelay;    /* @field Frame where sync burst has been received relative to the frame where <f L1T_FCChStart> was called. . Set by the baseband driver. */
   intx      ebitDelay;     /* @field Position of sync burst relative to current frame start in eighth bits. Set by the baseband driver. */
   BlockData data[ 4 ];     /* @field Sync burst data. Set by the baseband driver. */

   Time      bsTimingOffset; /* @field Timing offset of the base station relative to the mobiles current
                                       synchronisation. Calculated by layer1 */
   FrameNumber bsFrame;      /* @field Frame number decoded from the sync burst. Calculated by layer1. */
   BSIC      bsic;           /* @field BSIC number decoded from the sync burst. Calculated by layer1. */
   Time      rxTime;         /* @field Time the sync burst has been received. Calculated by layer1. */

   bool      hardwareUnavailable; /* special flag returned by SChT only if SCh was aborted because hardware
                                     was occupied by higher priority operation */
   bool      extBsic;        /* @field A flag to indicate if Extended measurement BSIC */
   bool      manual;         /* @distinguish manual or surrounding */
   bool      enhancePM;      /* default value is false*/
                             /* Set true for usage enhanced power measurement to update AGC ahead of FB/SB search in blind handover*/
   bool      isThermalSB; 	  /* The SB is used for crystal thermal change issue*/

/* Tier-1 Modem */  int16     snr;
/* Tier-1 Modem */  intx      bitErrorCount;

  uint8 bsic_tid; /* for distinguish from different transaction  */

#ifdef __UMTS_RAT__
   bool      ready_to_report;   /* True if L1C is ready to report SCh result to L1A, false otherwise. */
   TimeStamp timeStamp; 
#endif
} SChData;

typedef struct
{
   int32              power;
   int32              iOffset;
   int32              qOffset;
   int32              deviation;
   int32              validSamples;
   Gain               usedGain;
   Measurements       meas;
} PM_TST_Data;

/*
@union ReportData | Contains report information for factory testing
*/
typedef union
{
   SChData                *sch;          /* @field Results of FCB and SB search */
   PM_TST_Data            *pm_tst;       /* @field power meas results in test mode */
#if MD_DRV_IS_FHC_SUPPORT
   ResultDTS              *dts_result;
#endif
} ReportData_FT;

/*
@struct Report | Results of operations for factory testing.
*/
typedef struct
{
   ReportType_FT  type; /* @field Type of report */
   ReportData_FT  data; /* @field Contains information dependent on the <e Report.type> field */
} Report_FT;

/*
@struct sBBTXCfg | used to set/get run-time BBTX param
*/
typedef struct
{
   int8   TxTrimI;
   int8   TxTrimQ;
   int8   TxOffsetI;
   int8   TxOffsetQ;
   int8   TxCalbias;
   int8   TxIQSwap;
   int8   TxCMV;
   int8   TxGain;
   int8   TxCalrcsel;
   int8   TxPhasesel;
   int8   TxDccoarseI;
   int8   TxDccoarseQ;
} sBBTXCfg;

#endif
