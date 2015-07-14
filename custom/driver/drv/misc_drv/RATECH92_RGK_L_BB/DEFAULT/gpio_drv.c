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
 *    gpio.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the GPIO driver.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_comm.h"
#include "reg_base.h"
#include "gpio_hw.h"
#include "gpio_sw.h"

#ifdef __CUST_NEW__
extern void GPIO_setting_init(void);
kal_bool   gpio_debug_enable = KAL_FALSE;
#endif



/*
* FUNCTION                                                            
*	GPIO_init
*
* DESCRIPTION                                                           
*   	This function is to initialize the GPIO pins as all GPIO,
*	and configure them as output.
*
* CALLS  
*	None
*
* PARAMETERS
*	None
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void GPIO_init(void)
{

#ifdef __CUST_NEW__
   GPIO_setting_init();

//for LED and 15_segment init
#if defined(__MTK_TARGET__) && defined(DRV_GPIO_FOR_LED_AND_15_SEGMENT)

GPIO_ModeSetup(61, 0);//set mode 0
GPIO_ModeSetup(62, 0);
GPIO_ModeSetup(63, 0);
GPIO_ModeSetup(64, 0);
GPIO_ModeSetup(65, 0);
GPIO_ModeSetup(66, 0);

GPIO_InitIO(1, 61);//set direction output
GPIO_InitIO(1, 62);
GPIO_InitIO(1, 63);
GPIO_InitIO(1, 64);
GPIO_InitIO(1, 65);
GPIO_InitIO(1, 66);

GPIO_WriteIO(0, 61); //set output 1
GPIO_WriteIO(1, 62);
GPIO_WriteIO(1, 63);
GPIO_WriteIO(1, 64);
GPIO_WriteIO(1, 65);
GPIO_WriteIO(0, 66);
#endif

#else /* __CUST_NEW__ */
   DRV_WriteReg(GPIO_MODE1,0x4000);
   DRV_WriteReg(GPIO_MODE2,0x5a55);
   DRV_WriteReg(GPIO_MODE3,0x5555);
   DRV_WriteReg(GPIO_MODE4,0x1555);
   //DRV_WriteReg(GPIO_MODE5,0x5555);
   //DRV_WriteReg(GPIO_MODE6,0x0055);
   //DRV_WriteReg(GPIO_MODE7,0x1505);

   // Add by GuoXin for MT6268A init boot (Should be removed after boot ready)
   // Set Bit[9..8] = 0x01, GPIO_52, UART2 RX
   // Set Bit[11..10] = 0x01, GPIO_53, UART2 TX
   DRV_WriteReg(GPIO_MODE7,0x0555);
   /* set GPIO for LCD */
   //*(volatile kal_uint16 *)0x84021a00 = 0x01460;
   DRV_WriteReg(GPIO_MODEB,0x01460);
   
   // Add by Morse for MT6268A Testing
   // Set Bit[13..12] = 0x01, GPIO_93, UART3 RX
   // Set Bit[11..10] = 0x01, GPIO_94, UART3 TX
   DRV_WriteReg(GPIO_MODEC,0x1540);

#ifdef  __BTMODULE_RFMD3500__ //add by shine, 2006/06/17
   GPIO_InitIO(1, 2);  // set GPIO2 as the output
   GPIO_InitIO(1, 3);  // set GPIO2 as the output
   GPIO_WriteIO(0,2);
   GPIO_WriteIO(0,3);
#endif

#ifdef __OTG_ENABLE__
   /* GPIO84 is for USB 20 IP drive chagre pump */
   GPIO_ModeSetup(84, 1);
#endif	/*__USB_ENABLE__*/

#endif /* __CUST_NEW__ */

}


