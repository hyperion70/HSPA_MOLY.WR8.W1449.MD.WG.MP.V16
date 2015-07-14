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
 *   bus_drv.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intended for BUS driver.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __SPV_UTILITY_H_
#define __SPV_UTILITY_H_

#include "kal_general_types.h"
#include "bus_hw.h"


/*******************************************************************************
 * The Following is ONLY for SPV
 *******************************************************************************/
 
//#define __MD_SPV_UTILITIES__

#if defined(__MD_SPV_UTILITIES__)

/**********************************
 * MT6589 SPV Begin
 **********************************/ 
#if defined(MT6589)

// if EMI DCM is enabled, EMI APB only take affect after there is any EMI transaction
#define EBM_Start() \
    do {\
        *AP_EMIDCM_CON = 0x00000001;\
        *EMI_BMEN = 0x00080031;\
    } while (0)

#define EBM_Pause() \
    do {\
        *EMI_BMEN = 0x00080033;\
    } while (0)

#define EBM_Stop() \
    do {\
        *EMI_BMEN = 0x00080030;\
    } while (0)

//#define EBM_GET_WSCT() (*EMI_WSCT)


// SET EMI BW Limiter
// default  ARBA = 0x4010_5813
//          ARBC = 0x0000_7801 (ARM9)
//          ARBD = 0x030F_D808 (CR4)

#if defined(__MD1__)
    #define EMI_SET_BW_LIMTER(c) \
        do {\
            *AP_EMIDCM_CON = 0x00000001;\
            *EMI_ARBA = 0x40105013;\
            *EMI_ARBD = 0x030f1000 | (c) ;\
        } while (0)
#elif defined(__MD2__)
    #define EMI_SET_BW_LIMTER(c) \
        do {\
            *AP_EMIDCM_CON = 0x00000001;\
            *EMI_ARBA = 0x40105013;\
            *EMI_ARBC = 0x00001800 | (c) ;\
        } while (0)
#endif

#endif /* MT6589 */

/**********************************
 * MT6589 SPV End
 **********************************/ 


/**********************************
 * MT6572 SPV Begin
 **********************************/ 

#if defined(MT6572)

// Profile EBM
// Example:
//
//      kal_uint32 tcnt, wcnt, bcnt;
//
//      EBM_Stop();
//      EBM_Start();
//
//      [... your test code ...]
//
//      EBM_PAUSE();
//      tcnt = *EMI_TSCT;
//      wcnt = *EMI_WSCT;
//      bcnt = *EMI_BSCT;

#define EBM_Start() \
    do {\
        *EMI_BMEN = 0x00080081;\
    } while (0)

#define EBM_Pause() \
    do {\
        *EMI_BMEN = 0x00080083;\
    } while (0)

#define EBM_Stop() \
    do {\
        *EMI_BMEN = 0x00080080;\
    } while (0)

// Extend MD EMI latency
// M3: MDMCU
#define EMI_FORCE_LATENCY(r, w) \
    do {\
        *EMI_ARBD = 0x00001200 | (r<<16) | (w<<24);\
        *EMI_SLCT |= 0x00080000;\
    } while (0)

#endif /* MT6572 */

/**********************************
 * MT6572 SPV End
 **********************************/ 

/**********************************
 * MT6582 SPV Begin
 **********************************/ 

#if defined(MT6582)

// Profile EBM
// Example:
//
//      kal_uint32 tcnt, wcnt, bcnt;
//
//      EBM_Stop();
//      EBM_Start();
//
//      [... your test code ...]
//
//      EBM_PAUSE();
//      tcnt = *EMI_TSCT;
//      wcnt = *EMI_WSCT;
//      bcnt = *EMI_BSCT;

#define EBM_Start() \
    do {\
        *EMI_BMEN = 0x00080001;\
    } while (0)

#define EBM_Pause() \
    do {\
        *EMI_BMEN = 0x00080003;\
    } while (0)

#define EBM_Stop() \
    do {\
        *EMI_BMEN = 0x00080000;\
    } while (0)

// Extend MD EMI latency
// M3: MDMCU
#define EMI_FORCE_LATENCY(r, w) \
    do {\
        while (*MD2EMI_ULTRA_HIGH_STATUS0 & 0x3) {*MD2EMI_ULTRA_HIGH_CLR0 = 0x00000003;} \
        *EMI_MDCT = 0x23110000;\
        *EMI_ARBD = 0x00003040 | (r<<16) | (w<<24);\
        *EMI_SLCT = 0x1F011700;\
    } while (0)

#endif /* MT6582 */

/**********************************
 * MT6582 SPV End
 **********************************/ 


#endif /* __MD_SPV_UTILITIES__ */

#endif  /* !__SPV_UTILITY_H_ */

