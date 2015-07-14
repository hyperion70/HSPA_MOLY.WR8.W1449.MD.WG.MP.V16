/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   ccci_int.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Header file of CCIF.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __CCCI_INT_H__
#define __CCCI_INT_H__

#if defined(__MODEM_CCCI_EXIST__)

//- include for CCIF mask time check
#include "us_timer.h"

/*******************************************************************************
 * Define data structure.
 *******************************************************************************/
//- Structure for Excep DBG Logging
typedef struct {
    kal_uint32 magic_number_l;
    kal_uint32 magic_number_h;
    kal_uint32 last_write_index;
    kal_uint32 reserved;
} ccci_excep_dbg_hdr_t;

/*******************************************************************************
 * Define Internal Definition.
 *******************************************************************************/
//- ITCM of ARM9 is small. Move function to external RAM in ARM9 projects
#if defined(__ARM9_MMU__)
#define CCCI_CODE_EXT_RAM
#endif

#define CCCI_SEND_RETRY_DEFAULT    (100 * 1000) //- 100ms

/* CCIF mask time check related definition */
#if defined(__HW_US_TIMER_SUPPORT__)

#define CCCI_RX_MAX_DELAY          (100 * 1000) //- 100ms
#define CCIF_GET_CURRENT_TIME(time)    do { \
        time = ust_get_current_time(); \
    } while (0)

#define CCIF_GET_TIME_DURATION(start_time, end_time, duration)    do { \
        duration = (end_time > start_time)?(end_time - start_time):(0xFFFFFFFF - start_time + end_time); \
    } while(0)

#else    //- __HW_US_TIMER_SUPPORT__
  #error "CCIF Err MSG - CCIF mask time check need USC"
#endif    //- __HW_US_TIMER_SUPPORT__

//- Size of EXCEP memory may be 512 or 2048 bytes.
//- CCCI Excep Log use last 512 or 1024 bytes according to the EXCEP memory size is larger than 2048 bytes or not.
#define CCCI_EXCEP_DBG_LOG_SIZE_BOUNDARY    2048
#define CCCI_EXCEP_DBG_LOG_LARGE_SIZE       1024
#define CCCI_EXCEP_DBG_LOG_SMALL_SIZE       512
//for hs2 dbg info usage
#define CCCI_EXCEP_DBG_LOG_LARGE_SIZE_HS2   128
#define CCCI_EXCEP_DBG_LOG_SMALL_SIZE_HS2   64



/* Bootup trace value in CCIF SRAM. */
#define CCCI_HW_INIT_OK          0x57485F43    /* "C_HW" */
#define CCCI_HS1_WRITE_RESULT    0x58545F43    /* "C_TX" */
#define CCCI_HS1_DONE            0x4B4F5F43    /* "C_OK" */

/* CCCI EXCEP DBG Log magic number */
#define CCCI_EXCEP_DBG_INDICATOR_L 0x49434343    /* "CCCI" */
#define CCCI_EXCEP_DBG_INDICATOR_H 0x47424445    /* "EDBG" */

/*******************************************************************************
 * Declare function prototype.
 * Internal APIs
 *******************************************************************************/
extern kal_int32 ccci_fill_idle_task_state(kal_uint32 log_type, kal_uint32 state_info);

#endif /* #if __MODEM_CCCI_EXIST__ */

#endif  /* __CCCI_INT_H__ */

