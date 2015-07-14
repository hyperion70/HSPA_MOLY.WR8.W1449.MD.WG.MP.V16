/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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

/*******************************************************************************
 * Filename:
 * ---------
 * gpsmtk_config.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is used to describe the configuration of GPIO pins to control bluetooth module.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *==============================================================================
 *******************************************************************************/

#include "gps_common_config.h"
/*******************************************************************************
*
*  I/O Related Functions
*
*******************************************************************************/

#define GPIO_GPS_POWER_PIN    29     // power on : pin(if use GPO, please plus 100)
#define GPIO_GPS_POWER_POL    1      
#define GPIO_GPS_STANDBY_PIN  0xff   // standby : pin(if use GPO, please plus 100) 
#define GPIO_GPS_STANDBY_POL  0            
#define GPIO_GPS_SYNC_PIN     33     // sync : pin(if use GPO, please plus 100) 
#define GPIO_GPS_SYNC_POL     0            
#define GPIO_GPS_32K_PIN      0xff   // 32k clk  : pin(if use GPO, please plus 100)     
#define GPIO_GPS_URXD_PIN     37     // rxd2(37)                         
#define GPIO_GPS_UTXD_PIN     38     // txd2(38)                         
#define GPIO_GPS_UCTS_PIN     0xff   // cts2(41) 
#define GPIO_GPS_URTS_PIN     0xff   // rtx2(42)     

const unsigned char gps_gpio_setting[11] =
{   
   GPIO_GPS_POWER_PIN,   GPIO_GPS_POWER_POL,      // power on : pin(if use GPO, please plus 100), pol
   GPIO_GPS_STANDBY_PIN, GPIO_GPS_STANDBY_POL,    // standby : pin(if use GPO, please plus 100), pol
   GPIO_GPS_SYNC_PIN,    GPIO_GPS_SYNC_POL,       // sync : pin(if use GPO, please plus 100), pol
   GPIO_GPS_32K_PIN,                                                  // 32k clk  : pin(if use GPO, please plus 100)
   GPIO_GPS_URXD_PIN,    GPIO_GPS_UTXD_PIN,       // rxd2(37), txd2(38)
   GPIO_GPS_UCTS_PIN,    GPIO_GPS_URTS_PIN,       // cts2(41), rtx2(42)  
};

const unsigned char gps_uart_port_setting = 1;        // uart port number(uart2: 1, uart3: 2)
