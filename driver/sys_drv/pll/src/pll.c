
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
 *   init.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the HW initialization.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*******************************************************************************
 * Include header files
 *******************************************************************************/

#include "kal_general_types.h"
#include "reg_base.h"
#include "config_hw.h"
#include "drv_comm.h"
#include "pll.h"
#include "init.h"
#include "intrCtrl.h"
#include "drvpdn.h"
#include "custom_EMI_release.h"
#include "flash_sfi_release.h"
#include "kal_internal_api.h"
#include "kal_public_api.h"

#ifdef __MTK_TARGET__ /* should NOT be compiled on MODIS */

extern ECO_VERSION eco_version; /* only used in PLL setup */

extern int custom_DynamicClockSwitch(mcu_clock_enum clock);
extern kal_uint32 SaveAndSetIRQMask(void);
extern void RestoreIRQMask(kal_uint32);
extern kal_uint32 LockIRQ(void);
extern void RestoreIRQ(kal_uint32);

/*
 * Global variables
 */
#if !defined(__UBL__)
__PLL_TCM_BSS__ kal_uint32 pll_int_stack_pool[EPLL_FREQ_SWITCH_STACK_SIZE>>2];
__PLL_TCM_BSS__ pll_dfs_ctrl_t pll_dfs_state;
#else /* __UBL__ */
__PLL_EMIINIT_BSS__ pll_dfs_ctrl_t pll_dfs_state;
#endif /* !__UBL__ */


/*
 * NoteXXX:
 *    Please DO NOT place your code in the execution region EMIINITCODE.
 *    Code in this region is used for EMI/PLL initialization, and will be
 *    OVERWRITTEN after INT_InitRegions.
 */
#ifdef __MTK_TARGET__
//#pragma arm section code = "EMIINITCODE"
#endif /* __MTK_TARGET__ */

/*************************************************************************
* FUNCTION
*  INT_SetPLL
*
* DESCRIPTION
*  This function dedicates for PLL setting.
*
* CALLS
*  Non
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void INT_SetPLL(pll_init_mode mode)
{

#if defined(MT6575) || defined(MT6577)

   /**
     * For BUS_GATED_EN,
     * 1. Enable Infrasys bus clock, peripheral sys master bus clock, peripheral sys slave bus clock, ARM sys bus clock, Fcore sys bus clock, MD2G sys bus lock, HSPA sys bus clock, MM sys bus clock, and audio sys bus's gating.
     * For ARMSYS_CON,
     */  
   //*(volatile kal_uint32 *)0x810D0558 = 0xffffffff;
   *PLL_BUS_GATED_EN = 0xffffffff;

   /*
    * modem clock switch setting
    */
   *PLL_CLKSW_CON0 = 0x1457; // set freq. divider for mcu/dsp/gsm clock
   //*(volatile kal_uint16 *)0x810D0910 = 0x1457; // set freq. divider for mcu/dsp/gsm clock
   *PLL_CLKSW_CON2 = 0x0555; // set clock mux to divider out
   //*(volatile kal_uint16 *)0x810D0918 = 0x0555; // set clock mux to divider out

#endif

#if defined(TK6280)
{

   if(mode == PLL_MODE_MAUI)
   {
       volatile kal_uint32 i;

       // DCM settings for CR4 clock and bus clock (sec 2.1)
       *PLL_MCUCLK_CON = 0x7de7;
       // DCM settings for AP-ARM9 clock (sec 2.1)
       *PLL_APMCUCLK_CON = 0x1f;
       // 0x7114_0400: Change MPLL_VCOBAND[2:0] to 0x101 and Turn MPLL_VCOCAL_EN off..
       *PLL_MPLL_CON0 = *PLL_MPLL_CON0&0xf0ff|(0x5<<8);
       // 0x7114_0010 Power on UPLL & MPLL: [4]UPLL_PWDB=1, [2]MPLL_PWDB=1
       *PLL_PDN_CON = *PLL_PDN_CON | 0x0014;
       // 0x7114_0304: Reset UPLL first: [0]UPLL_RST=1
       *PLL_UPLL_CON1 = *PLL_UPLL_CON1 | 0x0001;
       // 0x7114_0304: Relase UPLL Reset [0]UPLL_RST=0
       *PLL_UPLL_CON1 = *PLL_UPLL_CON1 & 0xfffe;

       // wait for UPLL stable (about 20uS @ 26Mhz)
       for (i=0;i<20000/(1000/26);i++);

       // 0x7114_0408: Set MPLL output frequency to 491Mhz
       *PLL_MPLL_CON2 = 0x007E;
       // 0x7114_0404: Reset MPLL first: [0]MPLL_RST=1
       *PLL_MPLL_CON1 = *PLL_MPLL_CON1 | 0x0001;
       // 0x7114_0404: Relase MPLL Reset [0]MPLL_RST=0
       *PLL_MPLL_CON1 = *PLL_MPLL_CON1 & 0xfffe;

       // wait for MPLL stable (about 20uS @ 26Mhz)
       for (i=0;i<20000/(1000/26);i++);

      // 0x7114_0014: UPLL & MPLL output select: [5:4]GSM_PLLSEL=10, [3:2]MCU_PLLSEL=10,[1:0]ARM_PLLSEL=10
      *PLL_CLK_CON = *PLL_CLK_CON | 0x002A;
    }

}
#endif /* TK6280 */

#if defined(MT6280)
{
    volatile kal_uint32 i = 0, reg_val = 0;

    if(mode == PLL_MODE_MAUI)
    {
        //wait  3us  for CLKSQ settle (in 26Mh)
        for(i  = 0 ; i < 39 ; i++);

        // force 26M and PLL on
        *PLL_DFS_CON7= 0x003F;  // 0xA00C00AC, bit 0~5 set to 1 to force 26M and PLL on

        // enable TOPSM control 
        *PLL_PLL_CON2 = 0x0000; // 0xA00C0048, bit 12, 10, 8, 6 and 2 set to 0 to enable TOPSM control
        *PLL_PLL_CON3 = 0x0000; // 0xA00C004C, bit 12, 10, 8, 6 and 2 set to 0 to enable TOPSM control

        // enable delay control 
        *PLL_PLLTD_CON0 = 0x0010; //0x A00C0700, bit 0 set to 0 to enable delay control

        //wait for 3us for TOPSM and delay (HW) control signal stable
        for(i  = 0 ; i < 39 ; i++);

        //enable UPLL 
        *PLL_UPLL_CON0 = 0x1710 ; //0xA00C0140, bit 0 set to 0 to enable UPLL and generate reset of UPLL

        //enable MDDS clock source path of MPLL
        *PLL_MPLL_CON0 = 0x2451; //0xA00C0100, bit 2 set to 0 to enable reference clock from DDS

        // configure EPLL according to EMI clock requirement
        #if defined(__EMI_CLK_200MHZ__)
        *PLL_EPLL_CON0 &= ~(0x7FF0);
        *PLL_EPLL_CON0 |= 0x0E10; //0xA00C0200, FBKDIV set to 0xE, FBKSEL set to 0x1, and FBDIV set to 0x0 for 390Mhz
        *PLL_EPLL_CON1 &= ~(0xFFFE);
        *PLL_EPLL_CON1 |= 0x4000; //0xA00C0204, POSDIV set to 0x1 for 390Mhz
        #elif defined(__EMI_CLK_166MHZ__)
        *PLL_EPLL_CON0 &= ~(0x7FF0);
        *PLL_EPLL_CON0 |= 0x1810; //0xA00C0200, FBKDIV set to 0x18, FBKSEL set to 0x1, and FBDIV set to 0x0 for 325Mhz
        *PLL_EPLL_CON1 &= ~(0xFFFE);
        *PLL_EPLL_CON1 |= 0x8000; //0xA00C0204, POSDIV set to 0x2 for 325Mhz
        #elif defined(__EMI_CLK_125MHZ__)
        *PLL_EPLL_CON0 &= ~(0x7FF0);
        *PLL_EPLL_CON0 |= 0x1110; //0xA00C0200, FBKDIV set to 0x11, FBKSEL set to 0x1, and FBDIV set to 0x0 for 234Mhz
        *PLL_EPLL_CON1 &= ~(0xFFFE); 
        *PLL_EPLL_CON1 |= 0x8000; //0xA00C0204, POSDIV set to 0x2 for 234Mhz
        #endif

        //enable EDDS clock source path of EPLL
        *PLL_EPLL_CON0 &= ~(0x0004); //0xA00C0200, bit 2 set to 0 to enable reference clock from DDS

        //enable WHPLL
        *PLL_WHPLL_CON0 = 0x4CD4; // 0xA00C0600, bit 0 set to 0 to enable WHPLL

        //enable LPF of BIAS
        *PLL_PLL_CON1 = 0x0004; // 0xA00C0044, bit 2 set to 1 to enable bias low pass filter of bias 

        //enable WDIV
        *PLL_WPLL_CON2 = 0x0001; // 0xA00C01C8, bit 0 set to 1 to enable frequency divider of WPLL

        //enable WPLL
        *PLL_WPLL_CON0 = 0x7F10; // 0xA00C01C0, bit 0 set to 0 to enable WPLL

        //enable MDDS
        *PLL_MDDS_CON0 = 0xEC21; //0xA00C0640, bit 0 set to 1 to enable MDDS
        //enable EDDS
        *PLL_EDDS_CON0 = 0xEC21; //0x A00C0670, bit 0 set to 1 to enable EDDS

        //enable MPLL
        *PLL_MPLL_CON0 = 0x2450; // 0xA00C0100, bit 0 set to 0 to enable MPLL 

        //enable EPLL 
        *PLL_EPLL_CON0 &= ~(0x0001); //0xA00C0200, bit 0 set to 0 to enable EPLL

        //wait for 50~70us for UPLL stable and MDDS, EDDS enable (in 26Mhz)
        for(i  = 0 ; i < 910 ; i++);

        //reset MDDS
        *PLL_MDDS_CON0 = 0xEC23; //0xA00C0640, bit 1 set to 1 to reset MDDS
        //reset EDDS
        *PLL_EDDS_CON0 = 0xEC23; //0xA00C0670, bit 1 set to 1 to reset EDDS
        
        //sample MDDS FH code 
        *PLL_MDDS_CON2 = 0x8B00; //0xA00C0648, bit 15 set to 1 to sample MDDS FH code
        //enable EDDS FH code
        *PLL_EDDS_CON2 = 0x8B00; //0xA00C0678, bit 15 set to 1 to sample EDDS FH code

        //enable MDDS digital control
        *PLL_MDDS_CON1 = 0x1100; //0xA00C0644, bit 12 and 8 set to 1 to enable MDDS control
        //enable EDDS digital control
        *PLL_EDDS_CON1 = 0x1100; //0xA00C0674, bit 12 and 8 set to 1 to enable EDDS control

        //wait  50~70us  for WDIV, MDDS, EDDS, WHPLL, WPLL, EPLL and MPLL settle (in 26Mhz)
        for(i  = 0 ; i < 910 ; i++);

        // enable FH delay control 
        *PLL_PLLTD_CON0= 0x0000; //0xA00C0700, bit 4 set to 0 to enable FH delay control

        //Sequence to switch to PLL clocks as below:
        //Select MD and AP bus clock to PLL for DCM since AP clock uses DCM divider
        *PLL_MD_PWR_GLOBAL_CON1 = 0x20008510;
        *PLL_AP_DCM_CON_0 = 0x00010000;

        //Switch CR4 clock to 480Mhz (please program FDIV first, than program CKSEL)
        reg_val = *PLL_CLKSW_FDIV0;
        reg_val &= 0x0FFF;
        reg_val |= 0x2000;           // MPLL DIGDIV1 divided by 2 
        *PLL_CLKSW_FDIV0 = reg_val;
        
        *PLL_CLKSW_FDIV6 |= 0x10;
        *PLL_CLKSW_FDIV6 |= 0x400;
        *PLL_CLKSW_FDIV6 &= 0xFBFF; // toggle MPLL divider
        
        reg_val = *PLL_CLKSW_CKSEL0;
        reg_val &= 0x0FFF;
        reg_val |= 0x2000;
        *PLL_CLKSW_CKSEL0 = reg_val; // MDMCU clock from MPLL clkout 1

        //Switch MD bus clock to PLL
        reg_val = *PLL_CLKSW_FDIV0;
        reg_val &= 0xFF0F;
        reg_val |= 0x0080;
        *PLL_CLKSW_FDIV0 = reg_val; // MPLL DIGDIV3 divided by 8
        
        *PLL_CLKSW_FDIV6 |= 0x10;
        *PLL_CLKSW_FDIV6 |= 0x400;
        *PLL_CLKSW_FDIV6 &= 0xFBFF; // toggle MPLL divider

        *PLL_MD_PWR_GLOBAL_CON1 = 0x00044110;  //32'b0000_0000_0000_0100_0100_0001_0001_0000;
        *PLL_MD_PWR_GLOBAL_CON1 = 0x20044110;  //32'b0010_0000_0000_0100_0100_0001_0001_0000;

        reg_val = *PLL_CLKSW_CKSEL1;
        reg_val &= 0x0FFF;
        reg_val |= 0x2000;
        *PLL_CLKSW_CKSEL1 = reg_val; // MD bus clock from MPLL clkout 3

        //Switch DSP clock to PLL
        reg_val = *PLL_CLKSW_FDIV0;
        reg_val &= 0xFFF0;
        reg_val |= 0x0004;
        *PLL_CLKSW_FDIV0 = reg_val; // MPLL DIGDIV4 divided by 4

        *PLL_CLKSW_FDIV6 |= 0x10;
        *PLL_CLKSW_FDIV6 |= 0x400;
        *PLL_CLKSW_FDIV6 &= 0xFBFF;

        reg_val = *PLL_CLKSW_CKSEL0;
        reg_val &= 0xFF0F;
        reg_val |= 0x0020;
        *PLL_CLKSW_CKSEL0 = reg_val;

        //Switch AP bus clock to PLL
        /* MPLL divider2 is always configured as 3
          1) Dongle:  
             APMCU normal clock is divided by 4 : 320/4=80Mhz; 
             APBUS is divided by 1 : 80/1=80Mhz;
          2)WIFI route:  
             APMCU normal clock is divided by 1 : 320/1=320Mhz; 
             APBUS is divided by 4 : 320/4=80Mhz;
         */
        reg_val = *PLL_CLKSW_FDIV0;
        reg_val &= 0xF0FF;
        reg_val |= 0x0300;
        *PLL_CLKSW_FDIV0 = reg_val; // MPLL DIGDIV2 divided by 3
        
        *PLL_CLKSW_FDIV6 |= 0x10;
        *PLL_CLKSW_FDIV6 |= 0x400;
        *PLL_CLKSW_FDIV6 &= 0xFBFF; // toggle MPLL divider

        reg_val = *PLL_CLKSW_CKSEL0;
        reg_val &= 0xF0FF;
        reg_val |= 0x0200;
        *PLL_CLKSW_CKSEL0 = reg_val; // APMCU clock from MPLL clkout 2

        //Switch SFI clock to PLL
        reg_val = *PLL_CLKSW_FDIV1;
        reg_val &= 0xFF0F;
        reg_val |= 0x00C0;
        *PLL_CLKSW_FDIV1 = reg_val; // MPLL DIGDIV2 divided by 12
        
        *PLL_CLKSW_FDIV6 |= 0x10;
        *PLL_CLKSW_FDIV6 |= 0x400;
        *PLL_CLKSW_FDIV6 &= 0xFBFF; // toggle MPLL divider

        reg_val = *PLL_CLKSW_CKSEL2;
        reg_val &= 0xFFF0;
        #if defined(__SERIAL_FLASH_STT_EN__)
        reg_val |= 0x0001; // SFI clock from SYSCLK (26Mhz) 
        #else /* !__SERIAL_FLASH_STT_EN__ */
        reg_val |= 0x0002; // SFI clock from MPLL clkout 7
        #endif /* __SERIAL_FLASH_STT_EN__ */
        *PLL_CLKSW_CKSEL2 = reg_val; 
        
        //switch EMI to EPLL
        reg_val = *PLL_CLKSW_CKSEL1;
        reg_val &= 0xF0FF;
        reg_val |= 0x0200;
        *PLL_CLKSW_CKSEL1 = reg_val; // EMI clock from EPLL
        
        // WPLL DIV setting
        reg_val = *PLL_CLKSW_FDIV3;
        reg_val &= 0xF0F0;
        reg_val |= 0x0306;
        *PLL_CLKSW_FDIV3 = reg_val;

        reg_val = *PLL_CLKSW_FDIV4;
        reg_val &= 0xFF00;
        reg_val |= 0x0022;
        *PLL_CLKSW_FDIV4 = reg_val;
        
        reg_val = *PLL_CLKSW_FDIV5;
        reg_val &= 0x0FFF;
        reg_val |= 0x2000;
        *PLL_CLKSW_FDIV5 = reg_val;
        
        *PLL_CLKSW_FDIV6 |= 0x1;
        *PLL_CLKSW_FDIV6 |= 0x40;
        *PLL_CLKSW_FDIV6 &= 0xFFBF; // toggle WPLL divider

        *PLL_CLKSW_FDIV6 |= 0x4;
        *PLL_CLKSW_FDIV6 |= 0x100;
        *PLL_CLKSW_FDIV6 &= 0xFEFF; // toggle UPLL divider

        reg_val = *PLL_CLKSW_CKSEL2;
        reg_val &= 0x000F;
        reg_val |= 0x2220;
        *PLL_CLKSW_CKSEL2 = reg_val; // FX64W from WPLL clkout 5, FX16G from UPLL clkout 6, HX64W from WPLL clkout 4

        //switch UART clock to PLL
        *PLL_MD_TOP_CON |= 0x00010001;

        // Disable Force on DPM PLL control for PLL
        *PLL_DFS_CON7 = 0x0000;
    }
    else
    {
        // configure EPLL according to EMI clock requirement
        #if defined(__EMI_CLK_200MHZ__)
        *PLL_EPLL_CON0 &= ~(0x7FF0);
        *PLL_EPLL_CON0 |= 0x0E10; //0xA00C0200, FBKDIV set to 0xE, FBKSEL set to 0x1, and FBDIV set to 0x0 for 390Mhz
        *PLL_EPLL_CON1 &= ~(0xFFFE);
        *PLL_EPLL_CON1 |= 0x4000; //0xA00C0204, POSDIV set to 0x1 for 390Mhz
        #elif defined(__EMI_CLK_166MHZ__)
        *PLL_EPLL_CON0 &= ~(0x7FF0);
        *PLL_EPLL_CON0 |= 0x1810; //0xA00C0200, FBKDIV set to 0x18, FBKSEL set to 0x1, and FBDIV set to 0x0 for 325Mhz
        *PLL_EPLL_CON1 &= ~(0xFFFE);
        *PLL_EPLL_CON1 |= 0x8000; //0xA00C0204, POSDIV set to 0x2 for 325Mhz
        #elif defined(__EMI_CLK_125MHZ__)
        *PLL_EPLL_CON0 &= ~(0x7FF0);
        *PLL_EPLL_CON0 |= 0x1110; //0xA00C0200, FBKDIV set to 0x11, FBKSEL set to 0x1, and FBDIV set to 0x0 for 234Mhz
        *PLL_EPLL_CON1 &= ~(0xFFFE); 
        *PLL_EPLL_CON1 |= 0x8000; //0xA00C0204, POSDIV set to 0x2 for 234Mhz
        #endif

        //enable EPLL 
        *PLL_EPLL_CON0 &= ~(0x0001); //0xA00C0200, bit 0 set to 0 to enable EPLL
        //wait for 50~70us for UPLL stable and MDDS, EDDS enable (in 480Mhz)
        for(i  = 0 ; i < 16826 ; i++);

        //enable WHPLL
        *PLL_WHPLL_CON0 = 0x4CD4; // 0xA00C0600, bit 0 set to 0 to enable WHPLL

        //enable WDIV
        *PLL_WPLL_CON2 = 0x0001; // 0xA00C01C8, bit 0 set to 1 to enable frequency divider of WPLL

        //enable WPLL
        *PLL_WPLL_CON0 = 0x7F10; // 0xA00C01C0, bit 0 set to 0 to enable WPLL

        //wait for 50~70us for WPLL and WHPLL stable (in 480Mhz)
        for(i  = 0 ; i < 16826 ; i++);

        //switch EMI to EPLL
        reg_val = *PLL_CLKSW_CKSEL1;
        reg_val &= 0xF0FF;
        reg_val |= 0x0200;
        *PLL_CLKSW_CKSEL1 = reg_val; // EMI clock from EPLL

        //Switch SFI clock to PLL
        reg_val = *PLL_CLKSW_FDIV1;
        reg_val &= 0xFF0F;
        reg_val |= 0x00C0;
        *PLL_CLKSW_FDIV1 = reg_val; // MPLL DIGDIV2 divided by 12
        
        *PLL_CLKSW_FDIV6 |= 0x10;
        *PLL_CLKSW_FDIV6 |= 0x400;
        *PLL_CLKSW_FDIV6 &= 0xFBFF; // toggle MPLL divider

        reg_val = *PLL_CLKSW_CKSEL2;
        reg_val &= 0xFFF0;
        reg_val |= 0x0002;
        *PLL_CLKSW_CKSEL2 = reg_val; // SFI clock from MPLL clkout 7

        //Switch DSP clock to PLL
        reg_val = *PLL_CLKSW_FDIV0;
        reg_val &= 0xFFF0;
        reg_val |= 0x0004;
        *PLL_CLKSW_FDIV0 = reg_val; // MPLL DIGDIV4 divided by 4

        *PLL_CLKSW_FDIV6 |= 0x10;
        *PLL_CLKSW_FDIV6 |= 0x400;
        *PLL_CLKSW_FDIV6 &= 0xFBFF;

        reg_val = *PLL_CLKSW_CKSEL0;
        reg_val &= 0xFF0F;
        reg_val |= 0x0020;
        *PLL_CLKSW_CKSEL0 = reg_val;

        // WPLL DIV setting
        reg_val = *PLL_CLKSW_FDIV3;
        reg_val &= 0xF0F0;
        reg_val |= 0x0306;
        *PLL_CLKSW_FDIV3 = reg_val;

        reg_val = *PLL_CLKSW_FDIV4;
        reg_val &= 0xFF00;
        reg_val |= 0x0022;
        *PLL_CLKSW_FDIV4 = reg_val;
        
        reg_val = *PLL_CLKSW_FDIV5;
        reg_val &= 0x0FFF;
        reg_val |= 0x2000;
        *PLL_CLKSW_FDIV5 = reg_val;
        
        *PLL_CLKSW_FDIV6 |= 0x1;
        *PLL_CLKSW_FDIV6 |= 0x40;
        *PLL_CLKSW_FDIV6 &= 0xFFBF; // toggle WPLL divider

        *PLL_CLKSW_FDIV6 |= 0x4;
        *PLL_CLKSW_FDIV6 |= 0x100;
        *PLL_CLKSW_FDIV6 &= 0xFEFF; // toggle UPLL divider

        reg_val = *PLL_CLKSW_CKSEL2;
        reg_val &= 0x000F;
        reg_val |= 0x2220;
        *PLL_CLKSW_CKSEL2 = reg_val; // FX64W from WPLL clkout 5, FX16G from UPLL clkout 6, HX64W from WPLL clkout 4

        //switch UART clock to PLL
        *PLL_MD_TOP_CON |= 0x00010001;
    }
}
#endif /* MT6280 */

#if defined(MT6589)
{
    volatile kal_uint32 i = 0, reg_val = 0;
    /* __MD1__ and __MD2__ both use the same PLL init flow */

    // Sequence to enable PLL
    //wait 100us for CLKSQ and BIAS_LPF enable settle, but no need to wait when boot up

    // force 26M and PLL on
    *PLL_DFS_CON7 = 0x003F;  // 0x801200AC, bit 0~5 set to 1 to force 26M and PLL on

    // enable MTCMOS control 
   *PLL_PLL_CON3 = 0x8100; // 0x8012004C, bit 12, 4 set to 0 to enable MTCMOS control

    //wait 1us for MTCMOS isolation enable settle
    for( i = 0 ; i < 27 ; i++) // in 26Mhz
    
    // enable MTCMOS and TOPSM control 
    *PLL_PLL_CON3 = 0x0000; // 0x8012004C, bit 15, 8, 1 and 0 set to 0 to enable MTCMOS control

    // enable TOPSM control 
    *PLL_PLL_CON2 = 0x0000; // 0x80120048, bit 12, 10, 8, 6 and 2 set to 0 to enable TOPSM control

    // enable delay control 
    *PLL_PLLTD_CON0 = 0x0010; //0x80120700, bit 0 set to 0 to enable delay control

    //wait for 3us for mode change signal stable
    for( i = 0 ; i < 79 ; i++) // in 26Mhz

    //enable MDPLL and MDPLL2
    reg_val = *PLL_MDPLL_CON0;
    reg_val |= 0x8000;
    *PLL_MDPLL_CON0  = reg_val ; //0x80120100, bit 15 set to 1 to enable MDPLL and MDPLL2

    //enable MCUPLL and MCUPLL2
    reg_val = *PLL_MCUPLL_CON0;
    reg_val |= 0x8000;
    *PLL_MCUPLL_CON0  = reg_val ; //0x80120140, bit 15 set to 1 to enable MCUPLL1 and MCUPLL2

    //enable WPLL
    reg_val = *PLL_WPLL_CON0;
    reg_val |= 0x8000;
    *PLL_WPLL_CON0  = reg_val ; //0x801201C0, bit 15 set to 1 to enable WPLL 

    //enable WHPLL
    reg_val = *PLL_WHPLL_CON0;
    reg_val |= 0x8000;
    *PLL_WHPLL_CON0 = reg_val ; //0x80120200, bit 15 set to 1 to enable WHPLL 

    //wait 100us for MCUPLL, MCUPLL2, MDPLL, MDPLL2, WPLL and WHPLL settle 
    for( i = 0 ; i < 2631 ; i++) // in 26Mhz

    // enable FH delay control 
    *PLL_PLLTD_CON0= 0x0000; //0x80120700, bit 4 set to 0 to enable FH delay control

    //wait 1us for MDPLL, MDPLL2 calibration data save
    for( i = 0 ; i < 27 ; i++) // in 26Mhz

/* To disable "disable AUTOK", 
 * for workaround of HW issue that MDPLL fbdiv will sync a temperorily unstable value at reset.
 * Using AUTOK for each reset, to avoid this unstablibility.
 */
#if 0	
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //#if 0	

    // Sequence to switch to PLL clocks as below:
    //Switch CR4 clock to 481MHz
    reg_val = *PLL_CLKSW_CKSEL0; // 0x80120060
    reg_val &= 0x0FFF;
    reg_val |= 0x2000;
    *PLL_CLKSW_CKSEL0 = reg_val;
    
    // Set ghmdbus_pllck_sel
    reg_val = *PLL_MD_GLOBAL_CON1; // 0x8000045C
    reg_val |= 0x20000000;
    *PLL_MD_GLOBAL_CON1 = reg_val;

    //Switch MD bus clock to PLL
    reg_val = *PLL_CLKSW_FDIV0; // 0x80120070
    reg_val &= 0xF0FF;
    reg_val |= 0x0400;
    *PLL_CLKSW_FDIV0 = reg_val;
    *PLL_CLKSW_FDIV6 |= 0x10; // 0x80120088
    *PLL_CLKSW_FDIV6 |= 0x400;
    *PLL_CLKSW_FDIV6 &= 0xFBFF;

    reg_val = *PLL_CLKSW_CKSEL1; // 0x80120064
    reg_val &= 0x0FFF;
    reg_val |= 0x2000;
    *PLL_CLKSW_CKSEL1 = reg_val;

    //Switch DSP clock to 240.5MHz from MCUPLL
    reg_val = *PLL_CLKSW_FDIV0;
    reg_val &= 0xFF0F;
    reg_val |= 0x0020;
    *PLL_CLKSW_FDIV0 = reg_val;
    *PLL_CLKSW_FDIV6 |= 0x10;
    *PLL_CLKSW_FDIV6 |= 0x400;
    *PLL_CLKSW_FDIV6 &= 0xFBFF;
    reg_val = *PLL_CLKSW_CKSEL0;
    reg_val &= 0xFF0F;
    reg_val |= 0x0020;
    *PLL_CLKSW_CKSEL0 = reg_val;

    //Switch MODEMSYS clock to 208MHz from MDPLL
    reg_val = *PLL_CLKSW_FDIV2; // 0x80120078
    reg_val &= 0xFF0F;
    reg_val |= 0x0020;
    *PLL_CLKSW_FDIV2 = reg_val;
    *PLL_CLKSW_FDIV6 |= 0x4;
    *PLL_CLKSW_FDIV6 |= 0x100;
    *PLL_CLKSW_FDIV6 &= 0xFEFF;

    reg_val = *PLL_CLKSW_CKSEL2;
    reg_val &= 0xF0FF;
    reg_val |= 0x0200;
    *PLL_CLKSW_CKSEL2 = reg_val;

    //Switch WPLL clock to 245.76MHz(WPLL)
    reg_val = *PLL_CLKSW_CKSEL2;
    reg_val &= 0x0FFF;
    reg_val |= 0x2000;
    *PLL_CLKSW_CKSEL2 = reg_val;

    //Switch MCUPLL clock to 250.25MHz(WHPLL)
    reg_val = *PLL_CLKSW_CKSEL2;
    reg_val &= 0xFF0F;
    reg_val |= 0x0040;
    *PLL_CLKSW_CKSEL2 = reg_val;

    // Disable Force on DPM PLL control for PLL
    *PLL_DFS_CON7 = 0x0000;
}
#endif /* MT6589 */

/* #define WHPLL_TDD_MODE // if unset, working as FDD mode..*/
/* #define MCUPLL_ON */
/* #define WHPLL_ON */
#if defined(MT6572) || defined(MT6582) || defined (MT6592)
{
/* MT6572, MT6582, and MT6592 use MCUPLL for BPI/BSI */
#define MCUPLL_ON

    volatile kal_uint32 loop_var  = 0;

	// Sequence to enable PLL
	//wait  100us  for CLKSQ and BIAS_LPF enable settle, but no need to wait when boot up

	// force 26M and PLL on
	*PLL_DFS_CON7= 0x003F;  // 0x801200AC, bit 0~5 set to 1 to force 26M and PLL on

	// enable MTCMOS control
	*PLL_PLL_CON3 = 0x8300; // 0x8012004C, bit 12, 4 set to 0 to enable MTCMOS control

	// enable MTCMOS and TOPSM control
	*PLL_PLL_CON3 = 0x0000; // 0x8012004C, bit 15, 8, 1 and 0 set to 0 to enable MTCMOS control

	// enable TOPSM control
	*PLL_PLL_CON2 = 0x0000; // 0x80120048, bit 12, 10, 8, 6 and 2 set to 0 to enable TOPSM control

	// enable delay control
	*PLL_PLLTD_CON0= 0x0010; //0x80120700, bit 0 set to 0 to enable delay control

#if defined (WHPLL_TDD_MODE)
	*PLL_WHPLL_CON2  = 0x8028 ; //0x80120200, bit 15 set to 1 to enable WHPLL
	*PLL_WHPLL_CON3  = 0x0000 ; //13-0 fractional set to 0
#endif //#if defined (WHPLL_TDD_MODE)

	//change MDPLL_BC to got better performance
	*PLL_MDPLL_CON1 = (*PLL_MDPLL_CON1 & ~0x03) | 0x2; //

	//enable MDPLL
	*PLL_MDPLL_CON0 |= 0x8000; //0x80120100, bit 15 set to 1 to enable MDPLL

	//enable MCUPLL
	*PLL_MCUPLL_CON0 |= 0x8000; //0x80120140, bit 15 set to 1 to enable MCUPLL1

	//enable WPLL
	*PLL_WPLL_CON0 |= 0x8000; //0x801201C0, bit 15 set to 1 to enable WPLL

	//enable WHPLL
	*PLL_WHPLL_CON0 |= 0x8000; //0x80120200, bit 15 set to 1 to enable WHPLL


	for(loop_var=0; loop_var<20; loop_var++);
	// enable FH delay control
	*PLL_PLLTD_CON0= 0x0000; //0x80120700, bit 4 set to 0 to enable FH delay control
	for(loop_var=0; loop_var<5; loop_var++);

/* To disable "disable AUTOK",
 * for workaround of HW issue that MDPLL fbdiv will sync a temperorily unstable value at reset.
 * Using AUTOK for each reset, to avoid this unstablibility.
 */
	/*     //Disable AUTOK of MDPLL  */
	/* temp_reg = * MDPLL_CON4; */
	/*       temp_reg  &= 0xFFFE; */
	/*       *MDPLL_CON4  = temp_reg ; //0x80120110, bit 0 set to 0 to disable AUTOK of MDPLL to reduce calibration time */

#ifdef MCUPLL_ON
	*PLL_FH_CON5 = 0x0076;
	*PLL_FH_CON4 = 0xA455;
#endif //#ifdef MCUPLL_ON
#ifdef WHPLL_TDD_MODE
	*PLL_FH_CON7 = 0x0080;
	*PLL_FH_CON6 = 0xA455;
#endif //#ifdef WHPLL_TDD_MODE

	for (loop_var=0; loop_var < 60; loop_var++);
	*PLL_MDPLL_CON0 &= 0x7FFF;
	*PLL_MDPLL_CON4 &= 0xFFFE;
	for(loop_var=0; loop_var<1; loop_var++);
	*PLL_MDPLL_CON0 |= 0x8000;

///	*PLL_PLLTD_CON2 = 0x0514;  //removed @ programming_note.v3
	for(loop_var=0; loop_var<15; loop_var++);   //added @ programming_note.v4


#ifdef PLL_DIV
	*PLL_CLKSW_FDIV0 = 0x0420;
	*PLL_CLKSW_FDIV2 = 0x0020;
	*PLL_CLKSW_FDIV6 |= 0x0017;
	*PLL_CLKSW_FDIV6 |= 0x05C0;
	*PLL_CLKSW_FDIV6 &= 0xFA3F;
#endif //#ifdef PLL_DIV
	*PLL_CLKSW_FDIV7 = 0xC100;
	*PLL_MD_GLOBAL_CON1 |= 0x20000000;
	//*PLL_MD_GLOBAL_CON1; //dummy read to avoid 1-clock-lost while switching 26M to pll.

#ifndef SIM_26M
	*PLL_CLKSW_CKSEL0 = 0x2020;
	*PLL_CLKSW_CKSEL1 = 0x2000;
#ifdef WHPLL_ON
	*PLL_CLKSW_CKSEL2 = 0x2240;
#else //#ifdef WHPLL_ON
	*PLL_CLKSW_CKSEL2 = 0x2220;
#endif //#ifdef WHPLL_ON
#ifdef MCUPLL_ON
	*PLL_CLKSW_CKSEL3 = 0x0113;
#endif //#ifdef MCUPLL_ON
#endif //#ifndef SIM_26M

#ifndef MCUPLL_ON
	*PLL_PLL_CON2 |=0x0100;
	*PLL_MCUPLL_CON0 &= ~0x8000;
#endif //#ifndef MCUPLL_ON
#ifndef WHPLL_ON
	*PLL_PLL_CON2 |=0x0001;
	*PLL_WHPLL_CON0 &= ~0x8000;
#endif //#ifndef WHPLL_ON

	// Disable Force on DPM PLL control for PLL
    *PLL_DFS_CON7 = 0x0000;
}
#endif //#if defined(MT6572) || defined(MT6582)

#if defined(MT6571) || defined(MT6580)
{
    #define MCUPLL_ON         // Use MCUPLL for BPI/BSI (desense)
    /* #define WHPLL_TDD_MODE // if unset, working as FDD mode.. */
    /* #define WHPLL_ON                                          */
    /* #define SHARE_MCUPLL                                      */
    #define SHARE_WHPLL
    /* #define SHARE_WPLL                                        */

    // Sequence to enable PLL
    // wait  100us  for CLKSQ and BIAS_LPF enable settle, but no need to wait when boot up
    volatile kal_uint32 temp_reg = 0, loop_var = 0;

    // force 26M and PLL on
    *PLL_DFS_CON7= 0x003F;  // 0x801200AC, bit 0~5 set to 1 to force 26M and PLL on

    // enable MTCMOS control
    *PLL_PLL_CON3 = 0x8300; // 0x8012004C, bit 12, 4 set to 0 to enable MTCMOS control

    // enable MTCMOS and TOPSM control
    *PLL_PLL_CON3 = 0x0000; // 0x8012004C, bit 15, 8, 1 and 0 set to 0 to enable MTCMOS control

    // enable TOPSM control
    *PLL_PLL_CON2 = 0x0000; // 0x80120048, bit 12, 10, 8, 6 and 2 set to 0 to enable TOPSM control

    // enable delay control
    *PLL_PLLTD_CON0= 0x0010; //0x80120700, bit 0 set to 0 to enable delay control

#ifdef WHPLL_TDD_MODE
    *PLL_WHPLL_CON2  = 0x8028 ; //0x80120200, bit 15 set to 1 to enable WHPLL
    *PLL_WHPLL_CON3  = 0x0000 ; //13-0 fractional set to 0
#endif

    //enable MDPLL
    temp_reg = *PLL_MDPLL_CON0;
    temp_reg  |= 0x8000;
    *PLL_MDPLL_CON0  = temp_reg ; //0x80120100, bit 15 set to 1 to enable MDPLL1

    //enable MCUPLL
    temp_reg = * PLL_MCUPLL_CON0;
    temp_reg  |= 0x8000;
    *PLL_MCUPLL_CON0  = temp_reg ; //0x80120140, bit 15 set to 1 to enable MCUPLL

    //enable WPLL
    temp_reg = * PLL_WPLL_CON0;
    temp_reg  |= 0x8000;
    *PLL_WPLL_CON0  = temp_reg ; //0x801201C0, bit 15 set to 1 to enable WPLL

    //enable WHPLL
    temp_reg = * PLL_WHPLL_CON0;
    temp_reg  |= 0x8000;
    *PLL_WHPLL_CON0  = temp_reg ; //0x80120200, bit 15 set to 1 to enable WHPLL

    //wait  20us  for MCUPLL, WPLL and  WHPLL settle

    for(loop_var=0; loop_var<20; loop_var++);
    // enable FH delay control
    *PLL_PLLTD_CON0= 0x0000; //0x80120700, bit 4 set to 0 to enable FH delay control
    for(loop_var=0; loop_var<5; loop_var++);

#ifdef MCUPLL_ON
    *PLL_FH_CON5 = 0x0076;
    *PLL_FH_CON4 = 0xA455;
#endif
#ifdef WHPLL_TDD_MODE
    *PLL_FH_CON7 = 0x0080;
    *PLL_FH_CON6 = 0xA455;
#endif

    //wait  80us (total 100us)  for MDPLL1 settle
    for (loop_var=0; loop_var < 80; loop_var++);
    *PLL_MDPLL_CON0 &= 0x7FFF;
    for(loop_var=0; loop_var<1;loop_var++);
    *PLL_MDPLL_CON4 &= 0xFFFE;
    for(loop_var=0; loop_var<1;loop_var++);
    *PLL_MDPLL_CON0 |= 0x8000;

#ifdef PLL_DIV
    *PLL_CLKSW_FDIV0 = 0x0420;
    *PLL_CLKSW_FDIV2 = 0x0020;
    *PLL_CLKSW_FDIV6 |= 0x0017;
    *PLL_CLKSW_FDIV6 |= 0x0x5C0;
#endif
    *PLL_CLKSW_FDIV7 = 0xC100;
    *PLL_MD_GLOBAL_CON1 |= 0x20000000;

#ifndef SIM_26M
    *PLL_CLKSW_CKSEL0=0x2020;
    *PLL_CLKSW_CKSEL1 = 0x2000;
#ifdef WHPLL_ON
    *PLL_CLKSW_CKSEL2=0x2240;
#else
    *PLL_CLKSW_CKSEL2=0x2220;
#endif
#ifdef MCUPLL_ON
    *PLL_CLKSW_CKSEL3=0x0113;
#endif
#endif

#ifdef SHARE_MCUPLL
    *PLL_PLL_CON3 |=0x9000;
#endif
#ifdef SHARE_WHPLL
    *PLL_PLL_CON3 |=0x0220;
#endif
#ifdef SHARE_WPLL
    *PLL_PLL_CON3 |=0x0110;
#endif

#ifndef MCUPLL_ON
    *PLL_PLL_CON2 |=0x0100;
    *PLL_MCUPLL_CON0 &= ~0x8000;
#endif
#ifndef WHPLL_ON
    *PLL_PLL_CON2 |=0x0001;
    *PLL_WHPLL_CON0 &= ~0x8000;
#endif

    // Disable Force on DPM PLL control for PLL
    *PLL_DFS_CON7 = 0x0000;
}
#endif //#if defined(MT6571)

}

#ifdef __MTK_TARGET__
//#pragma arm section code
#endif /* __MTK_TARGET__ */

/*************************************************************************
* FUNCTION
*  INT_SetEPLLFreq
*
* DESCRIPTION
*   This function intended for changing EPLL frequency
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
#if defined(__UBL__)
__PLL_EMIINIT_LOCAL_FUNC__ void SetEMIPLLFreq_internal(emi_pll_enum emi_pll)
#else /* MAUI */
__PLL_TCM_LOCAL_FUNC__ void SetEMIPLLFreq_internal(emi_pll_enum emi_pll)
#endif
{
    kal_uint32 irq_mask = 0;

    INT_PLL_DISABLE_IRQ(irq_mask)

    if(EMI_PLL_26MHZ == pll_dfs_state.epll_freq)
    {
        if(EMI_PLL_26MHZ == emi_pll)
        {
            /* switch EMI clock to CLKSQ -- do nothing the target frequency is the same as present one. */
        }
        else
        {
            PLL_EMI_PLL_SWITCH_FREQ_TO(emi_pll);
            PLL_EMI_SWITCH_TO_PLL(emi_pll);
            pll_dfs_state.epll_freq = emi_pll;
        }
    }
    else if(emi_pll != pll_dfs_state.epll_freq)
    {
        /* switch EMI clock to CLKSQ before changing EMI PLL frequency */
        PLL_EMI_SWITCH_TO_CLKSQ;

        if(EMI_PLL_26MHZ == emi_pll)
        {
            /* switch EMI clock to CLKSQ -- already done at beggining */
        }
        else
        {
            PLL_EMI_PLL_SWITCH_FREQ_TO(emi_pll);
            PLL_EMI_SWITCH_TO_PLL(emi_pll);
        }
        pll_dfs_state.epll_freq = emi_pll;
    }
    else
    {
        /* do nothing since the target frequency is the same as present one. */
    }

    INT_PLL_ENABLE_IRQ(irq_mask)
}

#endif /* should NOT be compiled on MODIS */
