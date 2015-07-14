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
 * custom_port_setting.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains project specific customized default port setting stored 
 *   in NVRAM, and is used by nvram_data_items.c 
 *
 * Author:
 * -------
 * 
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef NVRAM_NOT_PRESENT

#include "dcl.h"

port_setting_struct const NVRAM_EF_CUSTOM_PORT_SETTING_DEFAULT[]=
{
    {
    #if defined(__SMART_PHONE_MODEM__)
        uart_port_null, /* tst-ps uses null */
        uart_port_at_ccci, /* APP uses uart_port_at_ccci */
    #elif defined(__MINI_LOG_SUPPORT__)
	    uart_port_mini_log, /* to prevent TST from idle if TST Port is NULL */
	    uart_port1,
    #else
        uart_port1, /* tst-ps uses NULL */
        uart_port_null, /* APP uses uart_port1 (value is 0) */
    #endif

#if defined(EMPTY_MMI)
        921600, /* tst default baud rate for project without MMI */
#else
        115200, /* tst default baud rate base = 115200 = 0x0001C200 */
#endif
    
    #if defined (__GPRS_MODE__)                  
        115200, /* ps default baud rate base = 115200 = 0x0001C200 */
    #else
        57600, /* ps default baud rate base =   57600 = 0x0000E100 */
    #endif                  
    
        0,                           /* High SpeedSIM */
        0,                           /* SWDBG */  
        3,                           /* uart power setting (0x03) */
    
        uart_port_null,                          /* CTI uart port: uart_null (value is 0x63 (99) */
        0,                           /* CTI baud rate: auto*/

        uart_port_null,                           /* tst-l1 uart port, same as tst-ps*/

#if defined(EMPTY_MMI)
        921600, /* tst-l1 baud rate for project without MMI */
#else
        115200, /* tst-l1 baud rate base = 115200 = 0x0001C200 */
#endif

        0,                           /* tst output mode*/
#if !defined( __UL1_STANDALONE__ )
        0,                            /* USB logging mode */
#else
    #if defined(__MODEM_3G_LOGGING__) && defined(_DSPIRDBG__)
        2,
    #else
        1,
    #endif /* defined(__MODEM_3G_LOGGING__) && defined(_DSPIRDBG__) */
#endif /*  __UL1_STANDALONE__  */

        uart_port_null,  										//TST-DSP
        921600									//TST-DSP baudrate

    },
};

#endif /* NVRAM_NOT_PRESENT */

