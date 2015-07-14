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
 *   intrCtrl.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Common type and structure definition for MediaTek GSM/GPRS software
 *
 * Author:
 * -------
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _INTRCTRL_H
#define _INTRCTRL_H

/*******************************************************************************
 * Include header files
 *******************************************************************************/
#include "kal_general_types.h"

/*******************************************************************************
 * Single Core Platforms
 *******************************************************************************/
#if defined(MT6575)
   #include "intrCtrl_MT6575.h"
#endif

#if defined(TK6280)
   #include "intrCtrl_TK6280.h" 
#endif

#if defined(MT6280)
   #include "intrCtrl_MT6280.h" 
#endif

#if defined(MT6577)
   #include "intrCtrl_MT6577.h"
#endif

#if defined(MT6589)
   #include "intrCtrl_MT6589.h"
#endif

#if defined(MT6572)
   #include "intrCtrl_MT6572.h"
#endif

#if defined(MT6582)
   #include "intrCtrl_MT6582.h"
#endif

#if defined(MT6571)
   #include "intrCtrl_MT6571.h"
#endif

#if defined(MT6592)
   #include "intrCtrl_MT6592.h"
#endif

#if defined(MT6580)
   #include "intrCtrl_MT6580.h"
#endif


/*******************************************************************************
 * Declarations and Definitions
 *******************************************************************************/
 
#define EDGE_SENSITIVE           KAL_TRUE
#define LEVEL_SENSITIVE          KAL_FALSE

#define IRQ_NOT_LISR_CONTEXT     (0xFFFF)

#if defined(__CIRQ_MASK_REG_NR_1_NEW__) || defined(__CIRQ_MASK_REG_NR_2_NEW__)  || defined(__CIRQ_MASK_REG_NR_3_NEW__) || defined(__CIRQ_MASK_REG_NR_4_NEW__) || defined(__CIRQ_MASK_REG_NR_5_NEW__)
#define __CIRQ_DESIGN_NEW__
#endif

typedef struct IRQ_MASK_VALUE_STRUCT
{
#if defined(__CIRQ_MASK_REG_NR_1_NEW__)
   kal_uint32 irq_mask0;
#elif defined(__CIRQ_MASK_REG_NR_2_NEW__)
   kal_uint32 irq_mask0;
   kal_uint32 irq_mask1;
#elif defined(__CIRQ_MASK_REG_NR_3_NEW__)
   kal_uint32 irq_mask0;
   kal_uint32 irq_mask1;
   kal_uint32 irq_mask2;
#elif defined(__CIRQ_MASK_REG_NR_4_NEW__)
   kal_uint32 irq_mask0;
   kal_uint32 irq_mask1;
   kal_uint32 irq_mask2;
   kal_uint32 irq_mask3;
#elif defined(__CIRQ_MASK_REG_NR_5_NEW__)
   kal_uint32 irq_mask0;
   kal_uint32 irq_mask1;
   kal_uint32 irq_mask2;
   kal_uint32 irq_mask3;
   kal_uint32 irq_mask4;
#elif defined(__CIRQ_MASK_REG_NR_2__)
   kal_uint32 irq_maskl;
   kal_uint32 irq_maskh;
#elif defined(__CIRQ_MASK_REG_NR_3__)
   kal_uint32 irq_maskl;
   kal_uint32 irq_maskm;
   kal_uint32 irq_maskh;
#else
   kal_uint32 irq_maskl;
   kal_uint32 irq_maskh;
#endif
} IRQ_MASK_VALUE_T;

/* To enable SW Trigger Interrupt for new BB chips
   Need to modify 3 files
   1. add a file intrCtrl_MTxxxx_SW_Handler.h
   2. add an entry on intrCtrl_SW_Handler.h 
   3. modify IRQ_SetSWRegister & IRQ_ResetSWRegister to support BB Chips on intrCtrl.c  */
#if defined(__ENABLE_SW_TRIGGER_INTERRUPT__)
typedef enum 
{
#define X_SW_HANDLE_CONST(a, b, c) a=(b),
   #include "intrCtrl_SW_Handle.h"
#undef X_SW_HANDLE_CONST
   SW_HANDLE_END
}SW_CODE_HANDLE;

extern void Activate_LISR(SW_CODE_HANDLE code);
extern void Deactivate_LISR(SW_CODE_HANDLE code);
extern const kal_uint8 SW_Code_Handle2Code[SW_HANDLE_END-NUM_IRQ_SOURCES];

/* Use to translate the mapping between software handler to hardware interrupt code */
#define SW_code_handle2code(a)  (SW_Code_Handle2Code[(a)-NUM_IRQ_SOURCES])

extern kal_uint32 SW_INT_Counter[SW_HANDLE_END-NUM_IRQ_SOURCES];

#endif /* __ENABLE_SW_TRIGGER_INTERRUPT__ */

/* should move to cirq_internal.h */
#if defined(__SSDVT_TEST__)
extern kal_uint8 irqLine[NUM_IRQ_SOURCES];
#else
extern const kal_uint8 irqLine[NUM_IRQ_SOURCES];
#endif

extern kal_uint8 IRQCode2Line[NUM_IRQ_SOURCES];

extern kal_uint32 SaveAndSetIRQMask(void);
extern void RestoreIRQMask(kal_uint32);

extern void IRQClearInt(kal_uint8);
extern void IRQMask(kal_uint8);
extern void IRQMaskAll(void);
extern void IRQUnmask(kal_uint8);
extern void CTIRQ1_2_MaskAll(IRQ_MASK_VALUE_T *val);
extern void CTIRQ1_2_Restore(IRQ_MASK_VALUE_T *val);
extern void IRQSensitivity(kal_uint8, kal_bool);
extern void FIQSensitivity(kal_bool);
extern void initINTR(void);
extern kal_uint16 INT_BootMode(void);
extern kal_uint32 IRQMask_Status(kal_uint8 code);
extern kal_uint32 IRQ_Status(void);
extern kal_uint32 FIQ_isValid(void);

extern void IRQ_Register_LISR(kal_uint32 code, void (*reg_lisr)(void), char* description);
extern kal_uint32 CheckIRQLock(void);
extern kal_uint16 IRQ_Current_LISR(void);

extern void SetINTMask(kal_uint8 code);
extern void RestoreINTMask(kal_uint8 code);

/* Hardware register write during interrupts disabled */
#define REG_WRITE(reg_addr, value)  { \
   kal_uint32 _savedMask; \
   _savedMask = SaveAndSetIRQMask(); \
   *(volatile kal_uint16*)(reg_addr) = (kal_uint16)(value); \
   RestoreIRQMask(_savedMask); \
}

/* Hardware register read during interrupts disabled */
#define REG_READ(reg_addr, value) { \
   kal_uint32 _savedMask; \
   _savedMask = SaveAndSetIRQMask(); \
   (kal_uint16)(value) = *(volatile kal_uint16*)(reg_addr); \
   RestoreIRQMask(_savedMask); \
}

#endif /* _INTRCTRL_H */

