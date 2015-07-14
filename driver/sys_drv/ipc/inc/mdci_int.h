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
 *   mdif.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Header file of MDIF.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __MDIF_INT_H__
#define __MDIF_INT_H__

/*******************************************************************************
 * Include header files
 *******************************************************************************/
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "reg_base.h"
#include "intrCtrl.h"


/*************************************************************************
 * Define data structure
 *************************************************************************/

#if defined(__DSP_FCORE4__)

#ifdef __IVP__
#define kal_mem_cpy memcpy
#define kal_taskid kal_uint32
#define kal_eventgrpid kal_uint32
#define kal_if_lisr() 0
#define kal_mem_set memset
#define ust_busy_wait
#define IRQSensitivity SAL_IRQ_Code_Sens
#endif /* __IVP__ */


#define IRQ_MDIF_CODE IRQ_MDIF_CH_2MCU_CODE



#define MDMDIF_BASE (MDIF_base + 0x60)
#define MDMDIF_SRAM BFMDIF_base
#define MDMDIF_SRAM_OFFSET  0x800
#define MDMDIF_SRAM_SIZE 256
#define MDMDIF_SRAM_INITDATA_OFFSET 64

/* define HW register */
#define MDMDIF_CON      ((volatile unsigned int *)(MDMDIF_BASE + 0x0000))
#define MDMDIF_BUSY     ((volatile unsigned int *)(MDMDIF_BASE + 0x0004))
#define MDMDIF_START    ((volatile unsigned int *)(MDMDIF_BASE + 0x0008))
#define MDMDIF_TCHNUM   ((volatile unsigned int *)(MDMDIF_BASE + 0x000C))
#define MDMDIF_RCHNUM   ((volatile unsigned int *)(MDMDIF_BASE + 0x0010))
#define MDMDIF_ACK      ((volatile unsigned int *)(MDMDIF_BASE + 0x0014))
/* for CHDATA, the first half space belongs to AP and the remaining space belongs to MD */


#define MDMDIF_TXCHDATA ((volatile unsigned int *)(MDMDIF_SRAM + MDMDIF_SRAM_OFFSET + 128))
#define MDMDIF_RXCHDATA ((volatile unsigned int *)(MDMDIF_SRAM + MDMDIF_SRAM_OFFSET))
#define MDMDIF_INITDATA ((volatile unsigned int *)(MDMDIF_SRAM + MDMDIF_SRAM_OFFSET + MDMDIF_SRAM_INITDATA_OFFSET))

/* define alias */
#define MDIF_CON MDMDIF_CON
#define MDIF_BUSY MDMDIF_BUSY
#define MDIF_TCHNUM MDMDIF_TCHNUM
#define MDIF_RCHNUM MDMDIF_RCHNUM
#define MDIF_ACK MDMDIF_ACK
#define MDIF_TXCHDATA MDMDIF_TXCHDATA
#define MDIF_RXCHDATA MDMDIF_RXCHDATA


/* define constant */
#define MDIF_CON_SEQ 0x00 /* sequencial */
#define MDIF_CON_ARB 0x01 /* arbitrate */
#define MDIF_MAX_PHY 8


/*******************************************************************************
 * Define data structure.
 *******************************************************************************/




/* MDIF RunTime Data structure */
/*      NOTICE: Negotiations With AP Owner Before Modification */

#define NORMAL_BOOT_ID 0
#define META_BOOT_ID 1

#define DSP_SHARE_REG_NONCACHEABLE 0
#define DSP_SHARE_REG_CACHEABLE 1
#define DSP_MAX_SHARE_REG_COUNT 6
typedef struct DSP_SHARE_MEM_INFO_T{
    kal_uint32  addr[DSP_MAX_SHARE_REG_COUNT];
    kal_uint32  len[DSP_MAX_SHARE_REG_COUNT];
    kal_uint8   reg_count;
    kal_uint8   attribute[DSP_MAX_SHARE_REG_COUNT];
    kal_uint8   reserve[1];
}DSP_SHARE_MEM_INFO;
typedef struct DSP_RUNTIME_DATA_T{

    kal_uint8    Prefix[4];        //"MDIF"
    kal_uint8    Platform[8];      
    kal_uint32   DriverVersion;
    kal_uint32   WakeUpEINT;       
    kal_uint32   MailboxPortNum;
    kal_uint32   BootChannel;          //Channel to ACK AP with boot ready
    kal_uint32   BootingStartID;       //MD is booting.
    kal_uint32   BootReadyID;          //Boot ready 
    kal_uint32   Is_MCU_Debug;
    kal_uint32   MdlogShareMemBase;
    kal_uint32   MdlogShareMemSize;
    kal_uint32   Reserved3;   
    DSP_SHARE_MEM_INFO   ShareMemInfo;
    kal_uint32	 CheckSum;
    kal_uint8    Postfix[4];       //"MDIF"
    
}DSP_RUNTIME_DATA;





/*******************************************************************************
 * define global variable
 *******************************************************************************/
#define MDCI_BOOT_CHECK_ID       0x5555FFFF /* magic id : Placed on reserved field */
#define MDCI_EXCEPTION_CHECK_ID  0x45584350 /* EXCP     : Placed on reserved field */
#define MDUD_SYNC_VALUE     0x4455434D /* MCUD     :                          */
#define MDCI_WAIT_MAX_TIME  4615




#endif /* #if defined(__DSP_FCORE4__) */

#endif  /* !__MDIF_INT_H__ */


