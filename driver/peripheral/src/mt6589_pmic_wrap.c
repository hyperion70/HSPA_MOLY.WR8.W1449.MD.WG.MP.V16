/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *  mt6589_pmic_wrap.c
 *
 * Project:
 * --------
 *  Maui_Software
 *
 * Description:
 * ------------
 *	This is mt6589 pmic wrapper driver
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
#if defined(FPGA_CTP)
#include <common.h>
#endif

#include "dcl.h" 
#include "pmic_wrap.h"
#include "dcl_pmu_sw.h"
#include "kal_public_api.h"
#include "syscomp_config.h"

#if defined(DRV_PMIC_WRAP_6589_REG)
#define PMIC_WRAP_TIMEOUT               60
#elif defined(DRV_PMIC_WRAP_6572_REG) || defined(DRV_PMIC_WRAP_6582_REG)
#define PMIC_WRAP_TIMEOUT               320 // APB Bus Latency
#endif

#if !defined(DRV_PMIC_OFF)

#if defined(FPGA_CTP)
extern kal_uint32 drv_get_current_time(void);
extern kal_uint32 drv_get_duration_tick(kal_uint32 previous_time, kal_uint32 current_time);
kal_uint32 drv_get_current_time(void)
{
    return 10;
}
kal_uint32 drv_get_duration_tick(kal_uint32 previous_time, kal_uint32 current_time)
{
    return 1;
}

#endif // End of #if !defind(FPGA_CTP)

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
static inline kal_uint32 wait_for_wacs_fsm_idle(kal_uint32 x)
{
    // Current WACS FSM state is IDLE State
    return (GET_WACS_FSM(x) != WACS_FSM_IDLE_STATE);
}

static inline kal_uint32 wait_for_wacs_fsm_wfvldclr(kal_uint32 x)
{
    // WFVLDCLR, wait for valid flag clearing
    return (GET_WACS_FSM(x) != WACS_FSM_WFVLDCLR_STATE); 
}

static inline kal_uint32 wait_for_man_wfvldclr(kal_uint32 x)
{
    // WFVLDCLR (wait for valid flag clearing)
    return  (GET_MAN_FSM(x) != MAN_FSM_WFVLDCLR_STATE) ;
}

static inline kal_uint32 wait_for_man_idle_and_noreq(kal_uint32 x)
{
    // No MAN request is awaiting grant, Current MAN FSM state is IDLE.
    return ((GET_MAN_REQ(x) != 0x00) || (GET_MAN_FSM(x) != MAN_FSM_IDLE_STATE));
}

static inline kal_uint32 wait_for_wacs_fsm_idle_and_sync_idle(kal_uint32 x)
{
    // Wait until SYNC module is IDLE and FSM state is IDLE
    return ((GET_WACS_FSM(x) != WACS_FSM_IDLE_STATE) || (GET_SYNC_IDLE(x) != WACS_SYNC_MODULE_IDLE));
}

static inline kal_uint32 wait_for_wrap_fsm_idle_and_spi_read_data_counter_zero(kal_uint32 x)
{
    // Wrapper FSM state is IDLE, Remaining SPI read data counter for wrapper is zero.
    return ((GET_WRAP_FSM(x) != WRAP_FSM_IDLE_STATE) || (GET_WRAP_CH_DLE_RESTCNT(x) != 0x0));
}

static inline kal_uint32 wait_for_cipher_ready(kal_uint32 x)
{
    // Wait until CIPHER Data Ready (Data should be ready before enable CIPHER_MODE)
    return (x != 0x01) ;
}

static inline kal_uint32 wait_for_sync_idle(kal_uint32 x)
{
    // Wait until SYNC module is IDLE
    return (GET_SYNC_IDLE(x) != WACS_SYNC_MODULE_IDLE);
}

static inline kal_uint32 wait_for_staupd_idle(kal_uint32 x)
{
    // Current STAUPD FSM is IDLE State
    return (GET_STAUPD_FSM(x) != STAUPD_FSM_IDLE_STATE) ;
}

static inline kal_uint32 wait_for_wrap_req_counter_zero(kal_uint32 x)
{
    // Remaining WRAP request counter for wrapper is zero
    return (GET_WRAP_AG_DLE_RESTCNT(x) != 0) ;
}

static inline kal_uint32 wait_for_state_ready_init(loop_condition_fp fp, kal_uint32 timeout_us, kal_uint32 pmic_wrap_register, kal_uint32 *read_reg)
{
//    kal_uint32 start_time_ns = 0, timeout_ns = 0;
    kal_uint32 reg_rdata = 0x0;
    kal_uint32 saved_current_time = 0;
    kal_uint32 time_out32k = 0;
    time_out32k = (timeout_us >> 5) + 1;
#if defined(FPGA_CTP)    
    //dbg_print("[PMIC_WRAP_MD] time_out32k =%d \n", time_out32k);          
#endif

    saved_current_time = drv_get_current_time();
    // start_time_ns = _pwrap_get_current_time();
    // timeout_ns = _pwrap_time2ns(timeout_us);
    do
    {
        reg_rdata = PMIC_WRAP_DRV_Reg32(pmic_wrap_register);

        //if (_pwrap_timeout_ns(start_time_ns, timeout_ns))
        if(drv_get_duration_tick(saved_current_time, drv_get_current_time()) > time_out32k) // NEED TO CHECK (64us)
        {
            ASSERT(0);
            return PMIC_WRAP_TIME_OUT_FAIL;
        }
    }while(fp(reg_rdata));
    
    if(read_reg)
    {
        *read_reg = reg_rdata;
    }
    return 0;
}


static inline kal_uint32 wait_for_state_ready(loop_condition_fp fp, kal_uint32 timeout_us, kal_uint32 pmic_wrap_register, kal_uint32 *read_reg)
{
//    kal_uint32 start_time_ns = 0, timeout_ns = 0;
    kal_uint32 reg_rdata;
    kal_uint32 saved_current_time = 0;
    kal_uint32 time_out32k = 0;
    time_out32k = (timeout_us >> 5) + 1;
    saved_current_time = drv_get_current_time();
    // struct pmic_wrap_obj *pwrap_obj = g_pmic_wrap_obj;
    // start_time_ns = _pwrap_get_current_time();
    // timeout_ns = _pwrap_time2ns(timeout_us);
    do
    {
        reg_rdata = PMIC_WRAP_DRV_Reg32(pmic_wrap_register);
        if(GET_INIT_DONE0( reg_rdata ) != WACS_INIT_DONE_FINISHED)
        {
            ASSERT(0);
            return PMIC_WRAP_NOT_INIT_DONE;
        }

        //if (_pwrap_timeout_ns(start_time_ns, timeout_ns))
        if(drv_get_duration_tick(saved_current_time, drv_get_current_time()) > time_out32k) // NEED TO CHECK (64us)
        {
            ASSERT(0);
            return PMIC_WRAP_TIME_OUT_FAIL;
        }        
    }while(fp(reg_rdata));
    if(read_reg)
    {
        *read_reg = reg_rdata;
    }
    return 0;
}

//--------------------------------------------------------
//    Function : DrvPWRAP_Init(void)
// Description : Initialize PMIC_WRAP, PPB, PMIC_DEWRAP
//   Parameter : None
//      Return : 
//--------------------------------------------------------
kal_uint32 DrvPWRAP_Init(void)
{
    kal_uint32 sub_return;
    kal_uint32 rdata;
#if defined(DRV_PMIC_WRAP_6572_REG)
    kal_uint32 cg_mask;
    kal_uint32 backup1;
#endif

    //###############################
    // Reset related modules
    // PMIC_WRAP, PERI_PWRAP_BRIDGE, PWRAP_SPICTL
    //###############################
#if defined(DRV_PMIC_WRAP_6589_REG)
    PMIC_WRAP_DRV_SetBits32(INFRA_GLOBALCON_RST0, 0x80); // Reset PMIC_WRAP
    PMIC_WRAP_DRV_SetBits32(PERI_GLOBALCON_RST1, 0x04); // Reset PERI_PWRAP_BRIDGE

    // *WDT_SWSYSRST = 0x88000000 | (*WDT_SWSYSRST | (0x1 << 11) & 0x00ffffff );
    rdata = PMIC_WRAP_DRV_Reg32(WDT_SWSYSRST);
    PMIC_WRAP_DRV_WriteReg32(WDT_SWSYSRST, 0x88000000 | ((rdata | (0x1 << 11)) & 0x00FFFFFF));
    
    //###############################
    // Toggle PERI_PWRAP_BRIDGE reset
    //###############################
    PMIC_WRAP_DRV_ClearBits32(INFRA_GLOBALCON_RST0, 0x80); // Reset PMIC_WRAP
    PMIC_WRAP_DRV_ClearBits32(PERI_GLOBALCON_RST1, 0x04); // Reset PERI_PWRAP_BRIDGE
    // *WDT_SWSYSRST = 0x88000000 | (*WDT_SWSYSRST & ~(0x1 << 11) & 0x00ffffff );
    rdata = PMIC_WRAP_DRV_Reg32(WDT_SWSYSRST);
    PMIC_WRAP_DRV_WriteReg32(WDT_SWSYSRST, 0x88000000 | ((rdata & ~(0x1 << 11)) & 0x00FFFFFF));
    
#elif defined(DRV_PMIC_WRAP_6582_REG)
    //###############################
    // Toggle PMIC_WRAP and pwrap_spictl reset
    //###############################
    PMIC_WRAP_DRV_SetBits32(INFRA_GLOBALCON_RST0, 0x80); // Reset PMIC_WRAP
    PMIC_WRAP_DRV_ClearBits32(INFRA_GLOBALCON_RST0, 0x80); // Reset PMIC_WRAP
    PMIC_WRAP_DRV_WriteReg32(CLK_CFG_4_CLR, 0xf); // 26MHz
#elif defined(DRV_PMIC_WRAP_6572_REG)
    // Turn off module clock
    cg_mask = (1 << 20) | (1 << 27) | (1 << 28) | (1 << 29);
    rdata = PMIC_WRAP_DRV_Reg32(CLK_SWCG_1);
    backup1 = ~rdata & cg_mask; // backup for later turn on after reset
    PMIC_WRAP_DRV_WriteReg32(CLK_SETCG_1, cg_mask);
    rdata = PMIC_WRAP_DRV_Reg32(PMIC_WRAP_SWRST); // dummy read to add latency (to wait clock turning off)

    // Toggle module reset
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_SWRST, 0x01);
    rdata = PMIC_WRAP_DRV_Reg32(WDT_SWSYSRST);
    PMIC_WRAP_DRV_WriteReg32(WDT_SWSYSRST, (rdata | 0x00000800) | (0x88 << 24));
    PMIC_WRAP_DRV_WriteReg32(WDT_SWSYSRST, (rdata & 0xfffff7ff) | (0x88 << 24));    
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_SWRST, 0x00);
  
    // Turn on module clock
    PMIC_WRAP_DRV_WriteReg32(CLK_CLRCG_1, backup1 | (1 << 20)); // Ensure cg for AP is off;

    // Turn on module clock dcm (in global_con)
    PMIC_WRAP_DRV_WriteReg32(CLK_SETCG_3, 0x06);    
    rdata = PMIC_WRAP_DRV_Reg32(CLK_SEL_0);
    PMIC_WRAP_DRV_WriteReg32(CLK_SEL_0, rdata | (0x3 << 24));
#endif

    //###############################
    // Enable DCM
    //###############################
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_DCM_EN, 0x01); // Enable internal DCM. When PMIC_WRAP is in idle state, clock will be gated.
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_DCM_DBC_PRD, 0x00); // Disable Debounce Period at Entering DCM Mode.

    //###############################
    // Enable 6320 option
    //###############################
#if defined(DRV_PMIC_WRAP_V2) && defined(MT6320)
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_OP_TYPE, 0x01); // Output type selection for read dummy state (0: OP_CK, 1: OP_CSL)
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_MSB_FIRST, 0x00); // Output data in LSB order
#endif

    //###############################
    // Reset SPISLV
    //###############################
    DrvPWRAP_ResetSPISLV();

    //###############################
    // Enable WACS2
    //###############################
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_WRAP_EN, 0x01); // Wrapper circuit is enable, and new request can be accepted once wrapper is available.
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_HIPRIO_ARB_EN, 0x08); // HIPRIO_ARB enable for each source. (Set WACS2 highest priority)
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_WACS2_EN, 0x01); // Wrapper Access (#2) enable.

#if defined(DRV_PMIC_WRAP_V1)
    //###############################
    // TBD: Set SPI_CK freq = 66MHz
    //###############################
    // *CLK_CFG_8 = (*CLK_CFG_8 & ~0x7) | 0x5;
//	PMIC_WRAP_DRV_WriteReg32(CLK_CFG_8, 0x01); // Set SPI_CK freq = 69Mhz
    rdata = PMIC_WRAP_DRV_Reg32(CLK_CFG_8);
    PMIC_WRAP_DRV_WriteReg32(CLK_CFG_8, (rdata & ~0x7) | 0x5); // Set SPI_CK freq = 69Mhz

    //###############################
    // SIDLY setting
    //###############################
    sub_return = DrvPWRAP_InitSIDLY();
    if( sub_return != 0 )  {
        ASSERT(0);
        /* TERR="[SetSIDLY] DrvPWRAP_SetSIDLY() fail, return=%x, exp=0", sub_return */
        return PMIC_WRAP_INIT_SIDLY_FAIL;
    }
    
#elif defined(DRV_PMIC_WRAP_V2)
    //###############################
    // Set Dummy cycle to make the cycle is the same at both AP and PMIC sides
    //###############################
#if defined(MT6323)
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_RDDMY, 0x0F); // Apply (1+RDDMY[3:0])T of dummy read cycles before read data phase. This setting sould be in accordance with the one in slave.
#endif

    //###############################
    //  Input data calibration flow
    //###############################
    sub_return = DrvPWRAP_InitSiStrobe();
    if( sub_return != 0 )  {
        /* TERR="[SetSIDLY] DrvPWRAP_InitSiStrobe() fail, return=%x, exp=0", sub_return */
        return PMIC_WRAP_INIT_SIDLY_FAIL;
    }    
    
#endif

    //###############################
    // SPI Waveform Configuration
    //###############################
//    sub_return = DrvPWRAP_InitRegClk(PMIC_WRAP_REG_CLOCK_36MHZ); // 0:safe mode, 1:18MHz, 2:36MHz
#if defined(DRV_PMIC_WRAP_V1)
    sub_return = DrvPWRAP_InitRegClk(PMIC_WRAP_REG_CLOCK_36MHZ); // 0:safe mode, 1:18MHz, 2:36MHz
#elif defined(DRV_PMIC_WRAP_V2)
    // 0:safe mode, 1:6MHz, 2:12MHz => no support 6MHz since the clock is too slow to transmit data (due to RDDMY's limit -> only 4'hf)
    sub_return = DrvPWRAP_InitRegClk(PMIC_WRAP_REG_CLOCK_12MHZ);
#endif    

    if(sub_return != 0)  {
        ASSERT(0);
        /* TERR="Error: [DrvPWRAP_InitRegClk] fail, sub_return=%x", sub_return*/
        return PMIC_WRAP_INIT_REG_CLK_FAIL;
    }

    //###############################
    // Enable PMIC Dewrapper (Only for MT6320)
    // (May not be necessary, depending on S/W partition)
    //###############################
#if defined(MT6320)    
    DrvPWRAP_WACS2_NoChk(PMIC_WRAP_WRITE, WRP_CKPDN, 0x00, &rdata); // Set WRAPPER CKPDN register no power down
    DrvPWRAP_WACS2_NoChk(PMIC_WRAP_WRITE, WRP_RST_CON, 0x00, &rdata); // Disable Reset, let module work
#endif    

    //###############################
    // Enable DIO mode
    //###############################
    sub_return = DrvPWRAP_InitDio(KAL_TRUE); // Enable SPI dual I/O mode.
    if(sub_return != 0)  {
        ASSERT(0);
        /* TERR="Error: [EnableDIO] DrvPWRAP_InitDio(1) fail, return=%x, exp=0", sub_return */
        return PMIC_WRAP_INIT_DUAL_MODE_FAIL;
    }

    //###############################
    // Enable Encryption
    //###############################
    sub_return = DrvPWRAP_InitCIPHER(); // Initial CIPHER
    if(sub_return != 0)  {
        ASSERT(0);        
        /* TERR="Error: [EnableEncryption] DrvPWRAP_InitCIPHER fail, return=%x, exp=0", sub_return */
        return PMIC_WRAP_INIT_CIPHER_FAIL;
    }

    //###############################
    // Write test using WACS2
    //###############################
    DrvPWRAP_WACS2_NoChk(PMIC_WRAP_WRITE, DEW_WRITE_TEST, DEW_WRITE_TEST_VALUE, &rdata); // Write Test
    DrvPWRAP_WACS2_NoChk(PMIC_WRAP_READ, DEW_WRITE_TEST, 0x00, &rdata);
    if(rdata != DEW_WRITE_TEST_VALUE)  {
        /* TERR="Error: [WriteTest] fail, rdata=%x, exp=0xa55a", rdata*/
        ASSERT(0);        
        return PMIC_WRAP_WRITE_TEST_FAIL;
    }

    //###############################
    // Signature Checking - Using Write Test Register
    // should be the last to modify WRITE_TEST
    //###############################
    //DrvPWRAP_WACS2_NoChk(PMIC_WRAP_WRITE, DEW_WRITE_TEST, DEW_WRITE_TEST_VALUE, &rdata);
    //PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_SIG_ADR, DEW_WRITE_TEST);
    //PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_SIG_VALUE, DEW_WRITE_TEST_VALUE);
    //PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_SIG_MODE, 0x01);

    //###############################
    // Signature Checking - Using CRC
    // should be the last to modify WRITE_TEST
    //###############################
    DrvPWRAP_WACS2_NoChk(PMIC_WRAP_WRITE, DEW_CRC_EN, 0x01, &rdata); // Enable CRC calculation circuit.
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CRC_EN, 0x01); // Enable CRC calculation circuit
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_SIG_MODE, 0x00); // Check CRC value
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_SIG_ADR, DEW_CRC_VAL); // The signature address @PMIC side to be automatically checked. STAUPD circuit will fetch from address every STAUPD_PRD time.

    //###############################
    // PMIC_WRAP enables
    //###############################
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_HIPRIO_ARB_EN, HARB_HPRIO_ALL); // HIPRIO_ARB enable for each source
#if defined(DRV_PMIC_WRAP_V1)    
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_RRARB_EN, 0x07); // HIPRIO_ARB enable for each source (2:Reserved, 1:KP, 0:EINT)
#endif    
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_WACS0_EN, 0x01);
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_WACS1_EN, 0x01);
    //PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_WACS2_EN, 0x01);  // Already enabled
#if defined(DRV_PMIC_WRAP_V1)
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_EVENT_IN_EN, 0x01); // Enable switch for event input processing circuit.
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_EVENT_DST_EN, 0xFFFF); // Enable switch for each event destination output.
#endif    
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_STAUPD_PRD, 0x05);  // Periodic status update timing (period) selection 98.5us
    //PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_STAUPD_PRD, 0x01); // 20us
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_STAUPD_GRPEN, 0xFF); // Enable switch for each status update group.
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_WDT_UNIT, 0x0F); // Watch Dog timer unit selection. (5ms ~ 7.5ms)
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_WDT_SRC_EN, 0xFFFFFFFF); // Watch dog timer source enable. (ALL)
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_TIMER_EN, 0x01); // Timer clock enable.
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_INT_EN, 0x7FFFFFFF); // Interrupt enable for each source, except for [31] debug_int.

#if defined(DRV_PMIC_WRAP_V1)
    //###############################
    // PERI_PWRAP_BRIDGE enables
    //###############################
    PMIC_WRAP_DRV_WriteReg32(PERI_PWRAP_BRIDGE_IORD_ARB_EN, 0x7F); // INORDER_ARB enable for each source
    PMIC_WRAP_DRV_WriteReg32(PERI_PWRAP_BRIDGE_WACS3_EN, 0x01);
    PMIC_WRAP_DRV_WriteReg32(PERI_PWRAP_BRIDGE_WACS4_EN, 0x01);
    PMIC_WRAP_DRV_WriteReg32(PERI_PWRAP_BRIDGE_WDT_UNIT, 0x0F); // Watch Dog timer unit selection. (5ms ~ 7.5ms)
    PMIC_WRAP_DRV_WriteReg32(PERI_PWRAP_BRIDGE_WDT_SRC_EN, 0xFFFF); // Watch dog timer source enable. (ALL)
    PMIC_WRAP_DRV_WriteReg32(PERI_PWRAP_BRIDGE_TIMER_EN, 0x01); // Timer clock enable.
    PMIC_WRAP_DRV_WriteReg32(PERI_PWRAP_BRIDGE_INT_EN, 0x7FF); // Interrupt enable for each source, except for [11] debug_int. (NEED TO CHECK)

    //###############################
    // PMIC_DEWRAP enables
    //###############################
    DrvPWRAP_WACS2_NoChk(PMIC_WRAP_WRITE, DEW_EVENT_OUT_EN, 0x01, &rdata); // Enable EVENT output.
    DrvPWRAP_WACS2_NoChk(PMIC_WRAP_WRITE, DEW_EVENT_SRC_EN, 0xFFFF, &rdata); // Enable each EVENT source respectively.
#endif // End of #if defined(DRV_PMIC_WRAP_V1)

    //###############################
    // GPS_INTF initialization
    //###############################
#if defined(MT6323)
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_ADC_CMD_ADDR, AUXADC_CON21);
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_PWRAP_ADC_CMD, 0x8000);
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_ADC_RDY_ADDR, AUXADC_ADC12);
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_ADC_RDATA_ADDR1, AUXADC_ADC13);
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_ADC_RDATA_ADDR2, AUXADC_ADC14);
#endif  

    //###############################
    // Initialization Done
    //###############################
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_INIT_DONE0, 0x01); // Initialization is finished.
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_INIT_DONE1, 0x01); // Initialization is finished.
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_INIT_DONE2, 0x01); // Initialization is finished.
            
    //###############################
    // Should be configured by MD MCU
    //###############################  
    // PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_INIT_DONE0, 0x01);
    // PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_INIT_DONE1, 0x01);
    // PMIC_WRAP_DRV_WriteReg32(PERI_PWRAP_BRIDGE_INIT_DONE3, 0x01);
    // PMIC_WRAP_DRV_WriteReg32(PERI_PWRAP_BRIDGE_INIT_DONE4, 0x01);
#if defined(FPGA_CTP)    
	{
	    DrvPWRAP_WACS2_NoChk(PMIC_WRAP_WRITE, DEW_WRITE_TEST, DEW_WRITE_TEST_VALUE, &rdata); // Write Test
	    DrvPWRAP_WACS2_NoChk(PMIC_WRAP_READ, DEW_WRITE_TEST, 0x00, &rdata);
	    if(rdata != DEW_WRITE_TEST_VALUE)  {
	        /* TERR="Error: [WriteTest] fail, rdata=%x, exp=0xa55a", rdata*/
	        // ASSERT(0);        
	        dbg_print("[PMIC_WRAP_MD] Write Test Fail\n");        
	    }
     	else
        {
            dbg_print("[PMIC_WRAP_MD] Write Test Pass\n");   
        }	    		
	}
    {
        kal_uint32 Address;
        kal_uint32 Write_Data;
        DCL_HANDLE handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
        PMU_CTRL_MISC_SET_REGISTER_VALUE SetVal;
        PMU_CTRL_MISC_GET_REGISTER_VALUE GetVal;
        DclPMU_Initialize();
        SetVal.offset = DEW_WRITE_TEST;
        GetVal.offset = DEW_WRITE_TEST;
        SetVal.value = 0xa55a;
        DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&SetVal);
        DclPMU_Control(handle, MISC_GET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&GetVal);
        if(0xa55a == GetVal.value)
        {
            dbg_print("[PMIC_WRAP_MD] dcl interface [R/W] Pass, rdata=%x\n", GetVal.value);
        }
        else
        {
            dbg_print("[PMIC_WRAP_MD] dcl interface [R/W] Fail, rdata=%x\n", GetVal.value);        
        }
#if 0       
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif        
    }
#endif // End of #if defined(FPGA_CTP)  

    return 0;
}


//--------------------------------------------------------
//    Function : DrvPWRAP_WACS2_NoChk()
// Description : 
//   Parameter : 
//      Return : 
//--------------------------------------------------------
kal_uint32 DrvPWRAP_WACS2_NoChk(kal_uint32 write, kal_uint32 adr, kal_uint32 wdata, kal_uint32 *rdata) // No check INIT DONE, for INIT usage
{
    kal_uint32 reg_rdata;
    kal_uint32 wacs_write;
    kal_uint32 wacs_adr;
    kal_uint32 return_value;

    // Check argument validation
    if((write & ~(0x1))    != 0)  return PMIC_WRAP_INVALID_RW; // Write should be 1 bit
    if((adr   & ~(0xffff)) != 0)  return PMIC_WRAP_INVALID_ADDR; // Address should no larger than 0xFFFF
    if((wdata & ~(0xffff)) != 0)  return PMIC_WRAP_INVALID_WDATA; // Write DATA should be no larger than 0xFFFF
    if(NULL == rdata) return PMIC_WRAP_INVALID_ARGUMENT;
    
    // Argument process
    wacs_write  = write << 31;
    wacs_adr    = (adr >> 1) << 16; // Wrapper Access: address[15:1]

    // Check IDLE & INIT_DONE in advance
    return_value = wait_for_state_ready_init(wait_for_wacs_fsm_idle, PMIC_WRAP_TIMEOUT, PMIC_WRAP_WACS2_RDATA, 0);
    if(return_value != 0)
    {
        ASSERT(0);
        return return_value;
    }

    // Send Command
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_WACS2_CMD, wacs_write | wacs_adr | wdata);
    if(write == PMIC_WRAP_READ) // Read
    {
        return_value = wait_for_state_ready_init(wait_for_wacs_fsm_wfvldclr, PMIC_WRAP_TIMEOUT, PMIC_WRAP_WACS2_RDATA, &reg_rdata);
        if(return_value != 0)
        {
            ASSERT(0);            
            return return_value;
        }
        
        *rdata = GET_WACS2_RDATA(reg_rdata); // Read Data
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_WACS2_VLDCLR, 0x01); // Write 1 to clear valid flag.
    }

    return 0;
}

//--------------------------------------------------------
//    Function : DrvPWRAP_WACS0()
// Description : 
//   Parameter : 
//      Return : 
//--------------------------------------------------------
//kal_uint32 DrvPWRAP_WACS0(kal_uint32 write, kal_uint32 adr, kal_uint32 wdata, kal_uint32 *rdata)
kal_uint32 DrvPWRAP_WACS0(kal_uint32 write, kal_uint32 adr, kal_uint32 wdata, kal_uint16 *rdata)
{
    kal_uint32 reg_rdata;
    kal_uint32 wacs_write;
    kal_uint32 wacs_adr;
    kal_uint32 return_value;

    // Check argument validation
    if((write & ~(0x1))    != 0)  return PMIC_WRAP_INVALID_RW; // Write should be 1 bit
    if((adr   & ~(0xffff)) != 0)  return PMIC_WRAP_INVALID_ADDR; // Address should no larger than 0xFFFF
    if((wdata & ~(0xffff)) != 0)  return PMIC_WRAP_INVALID_WDATA; // Write DATA should be no larger than 0xFFFF
    
    // Argument process
    wacs_write  = write << 31;
    wacs_adr    = (adr >> 1) << 16;
    
    // Check IDLE & INIT_DONE in advance
    return_value = wait_for_state_ready(wait_for_wacs_fsm_idle, PMIC_WRAP_TIMEOUT, PMIC_WRAP_WACS0_RDATA, 0);
    if(return_value != 0)
    {
        ASSERT(0);
        return return_value;
    }    

    // Send Command
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_WACS0_CMD, wacs_write | wacs_adr | wdata);
    if(write == PMIC_WRAP_READ) // Read
    {
        return_value = wait_for_state_ready(wait_for_wacs_fsm_wfvldclr, PMIC_WRAP_TIMEOUT, PMIC_WRAP_WACS0_RDATA, &reg_rdata);
        if(return_value != 0)
        {
            ASSERT(0);
            return return_value;
        }    
        
        *rdata = (kal_uint16)GET_WACS0_RDATA(reg_rdata); // Read Data
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_WACS0_VLDCLR, 0x01); // Write 1 to clear valid flag.
    }

    return 0;
}


//--------------------------------------------------------
//    Function : DrvPWRAP_WACS1()
// Description : 
//   Parameter : 
//      Return : 
//--------------------------------------------------------
//kal_uint32 DrvPWRAP_WACS1(kal_uint32 write, kal_uint32 adr, kal_uint32 wdata, kal_uint32 *rdata)
kal_uint32 DrvPWRAP_WACS1(kal_uint32 write, kal_uint32 adr, kal_uint32 wdata, kal_uint16 *rdata)
{
    kal_uint32 reg_rdata;
    kal_uint32 wacs_write;
    kal_uint32 wacs_adr;
    kal_uint32 return_value;

    // Check argument validation
    if((write & ~(0x1))    != 0)  return PMIC_WRAP_INVALID_RW; // Write should be 1 bit
    if((adr   & ~(0xffff)) != 0)  return PMIC_WRAP_INVALID_ADDR; // Address should no larger than 0xFFFF
    if((wdata & ~(0xffff)) != 0)  return PMIC_WRAP_INVALID_WDATA; // Write DATA should be no larger than 0xFFFF

    // Argument process
    wacs_write  = write << 31;
    wacs_adr    = (adr >> 1) << 16;
    
    // Check IDLE & INIT_DONE in advance   
    return_value = wait_for_state_ready(wait_for_wacs_fsm_idle, PMIC_WRAP_TIMEOUT, PMIC_WRAP_WACS1_RDATA, 0);
    if(return_value != 0)
    {
        ASSERT(0);
        return return_value;
    }    
    
    // Send Command
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_WACS1_CMD, wacs_write | wacs_adr | wdata);
    if(write == PMIC_WRAP_READ) // Read
    {
        return_value = wait_for_state_ready(wait_for_wacs_fsm_wfvldclr, PMIC_WRAP_TIMEOUT, PMIC_WRAP_WACS1_RDATA, &reg_rdata);
        if(return_value != 0)
        {
            ASSERT(0);
            return return_value;
        }          

        *rdata = (kal_uint16)GET_WACS1_RDATA(reg_rdata); // Read Data
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_WACS1_VLDCLR, 0x01); // Write 1 to clear valid flag.
    }    
    
    return 0;
}

//--------------------------------------------------------
//    Function : DrvPWRAP_WACS2()
// Description : 
//   Parameter : 
//      Return : 
//--------------------------------------------------------
kal_uint32 DrvPWRAP_WACS2(kal_uint32 write, kal_uint32 adr, kal_uint32 wdata, kal_uint32 *rdata)
{
    kal_uint32 reg_rdata;
    kal_uint32 wacs_write;
    kal_uint32 wacs_adr;
    kal_uint32 return_value;
    kal_uint32 savedMask = 0;
    
    // Check argument validation
    if((write & ~(0x1))    != 0)  return PMIC_WRAP_INVALID_RW; // Write should be 1 bit
    if((adr   & ~(0xffff)) != 0)  return PMIC_WRAP_INVALID_ADDR; // Address should no larger than 0xFFFF
    if((wdata & ~(0xffff)) != 0)  return PMIC_WRAP_INVALID_WDATA; // Write DATA should be no larger than 0xFFFF

#if !defined(__UBL__) && !defined(__FUE__)
	savedMask = SaveAndSetIRQMask();
#endif //#if !defined(__UBL__) && !defined(__FUE__)

    // Argument process
    wacs_write  = write << 31;
    wacs_adr    = (adr >> 1) << 16;
    
    // Check IDLE & INIT_DONE in advance
    return_value = wait_for_state_ready(wait_for_wacs_fsm_idle, PMIC_WRAP_TIMEOUT, PMIC_WRAP_WACS2_RDATA, 0);
    if(return_value != 0)
    {
        ASSERT(0);
        // GuoXin Add
        #if !defined(__UBL__) && !defined(__FUE__)	
        RestoreIRQMask(savedMask);
        #endif //#if !defined(__UBL__) && !defined(__FUE__)	
        return return_value;
    }        

    // Send Command
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_WACS2_CMD, wacs_write | wacs_adr | wdata);
    if(write == PMIC_WRAP_READ) // Read
    {
        return_value = wait_for_state_ready(wait_for_wacs_fsm_wfvldclr, PMIC_WRAP_TIMEOUT, PMIC_WRAP_WACS2_RDATA, &reg_rdata);
        if(return_value != 0)
        {
            ASSERT(0);
            // GuoXin Add
            #if !defined(__UBL__) && !defined(__FUE__)	
            RestoreIRQMask(savedMask);
            #endif //#if !defined(__UBL__) && !defined(__FUE__)	
            return return_value;
        }          

        *rdata = GET_WACS2_RDATA(reg_rdata); // Read Data
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_WACS2_VLDCLR, 0x01); // Write 1 to clear valid flag.
    }    

#if !defined(__UBL__) && !defined(__FUE__)	
    RestoreIRQMask(savedMask);
#endif //#if !defined(__UBL__) && !defined(__FUE__)		

    return 0; 
}

#if defined(DRV_PMIC_WRAP_V1)
//--------------------------------------------------------
//    Function : DrvPWRAP_WACS3()
// Description : 
//   Parameter : 
//      Return : 
//--------------------------------------------------------
kal_uint32 DrvPWRAP_WACS3(kal_uint32 write, kal_uint32 adr, kal_uint32 wdata, kal_uint32 *rdata)
{
    kal_uint32 reg_rdata;
    kal_uint32 wacs_write;
    kal_uint32 wacs_adr;
    kal_uint32 return_value;

    // Check argument validation
    if((write & ~(0x1))    != 0)  return PMIC_WRAP_INVALID_RW; // Write should be 1 bit
    if((adr   & ~(0xffff)) != 0)  return PMIC_WRAP_INVALID_ADDR; // Address should no larger than 0xFFFF
    if((wdata & ~(0xffff)) != 0)  return PMIC_WRAP_INVALID_WDATA; // Write DATA should be no larger than 0xFFFF
    
    // Argument process
    wacs_write  = write << 31;
    wacs_adr    = (adr >> 1) << 16;
    
    // Check IDLE & INIT_DONE in advance
    return_value = wait_for_state_ready(wait_for_wacs_fsm_idle, PMIC_WRAP_TIMEOUT, PERI_PWRAP_BRIDGE_WACS3_RDATA, 0);
    if(return_value != 0)
    {
        ASSERT(0);
        return return_value;
    }  

    // Send Command
    PMIC_WRAP_DRV_WriteReg32(PERI_PWRAP_BRIDGE_WACS3_CMD, wacs_write | wacs_adr | wdata);
    if(write == PMIC_WRAP_READ) // Read
    {
        return_value = wait_for_state_ready(wait_for_wacs_fsm_wfvldclr, PMIC_WRAP_TIMEOUT, PERI_PWRAP_BRIDGE_WACS3_RDATA, &reg_rdata);
        if(return_value != 0)
        {
            ASSERT(0);            
            return return_value;
        }

        *rdata = GET_WACS3_RDATA(reg_rdata); // Read Data
        PMIC_WRAP_DRV_WriteReg32(PERI_PWRAP_BRIDGE_WACS3_VLDCLR, 0x01); // Write 1 to clear valid flag.
    }    
    
    return 0; 
}

//--------------------------------------------------------
//    Function : DrvPWRAP_WACS4()
// Description : 
//   Parameter : 
//      Return : 
//--------------------------------------------------------
kal_uint32 DrvPWRAP_WACS4(kal_uint32 write, kal_uint32 adr, kal_uint32 wdata, kal_uint32 *rdata)
{
    kal_uint32 reg_rdata;
    kal_uint32 wacs_write;
    kal_uint32 wacs_adr;
    kal_uint32 return_value;

    // Check argument validation
    if((write & ~(0x1))    != 0)  return PMIC_WRAP_INVALID_RW; // Write should be 1 bit
    if((adr   & ~(0xffff)) != 0)  return PMIC_WRAP_INVALID_ADDR; // Address should no larger than 0xFFFF
    if((wdata & ~(0xffff)) != 0)  return PMIC_WRAP_INVALID_WDATA; // Write DATA should be no larger than 0xFFFF
    
    // Argument process
    wacs_write  = write << 31;
    wacs_adr    = (adr >> 1) << 16;
    
    // Check IDLE & INIT_DONE in advance
    return_value = wait_for_state_ready(wait_for_wacs_fsm_idle, PMIC_WRAP_TIMEOUT, PERI_PWRAP_BRIDGE_WACS4_RDATA, 0);
    if(return_value != 0)
    {
        ASSERT(0);        
        return return_value;
    }

    // Send Command
    PMIC_WRAP_DRV_WriteReg32(PERI_PWRAP_BRIDGE_WACS4_CMD, wacs_write | wacs_adr | wdata);
    if(write == PMIC_WRAP_READ) // Read
    {
        return_value = wait_for_state_ready(wait_for_wacs_fsm_wfvldclr, PMIC_WRAP_TIMEOUT, PERI_PWRAP_BRIDGE_WACS4_RDATA, &reg_rdata);
        if(return_value != 0)
        {
            ASSERT(0);            
            return return_value;
        }
        
        *rdata = GET_WACS4_RDATA(reg_rdata); // Read Data
        PMIC_WRAP_DRV_WriteReg32(PERI_PWRAP_BRIDGE_WACS4_VLDCLR, 0x01); // Write 1 to clear valid flag.
    }    
    
    return 0; 
}
#endif // End of #if defined(DRV_PMIC_WRAP_V1)

//--------------------------------------------------------
//    Function : DrvPWRAP_InitDio()
// Description : 
//   Parameter : 
//      Return : 
//--------------------------------------------------------
kal_uint32 DrvPWRAP_InitDio(kal_bool dio_en)
{
    kal_uint32 arb_en_backup;
    kal_uint32 rdata;
    kal_uint32 return_value;

    arb_en_backup = PMIC_WRAP_DRV_Reg32(PMIC_WRAP_HIPRIO_ARB_EN); // Backup HIPRIO_ARB enable bitmap

    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_HIPRIO_ARB_EN, HARB_HPRIO_WACS2); // HIPRIO_ARB enable for each source. (Set WACS2 highest priority)
    DrvPWRAP_WACS2_NoChk(PMIC_WRAP_WRITE, DEW_DIO_EN, dio_en, &rdata); // Enable dual I/O mode for SPI slave.

    return_value = wait_for_state_ready_init(wait_for_wacs_fsm_idle_and_sync_idle, PMIC_WRAP_TIMEOUT, PMIC_WRAP_WACS2_RDATA, 0);
    if(return_value != 0)
    {
        ASSERT(0);
        return return_value;
    }  

    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_DIO_EN, dio_en); // Eable / Disable SPI dual I/O mode
    // Read Test
    DrvPWRAP_WACS2_NoChk(PMIC_WRAP_READ, DEW_READ_TEST, 0x00, &rdata);
    if(rdata != DEW_READ_TEST_VALUE)
    {
        ASSERT(0);        
        /* TERR="Error: [DrvPWRAP_InitDio][Read Test] fail, dio_en = %x, READ_TEST rdata=%x, exp=0x5aa5", dio_en, rdata */
        return PMIC_WRAP_READ_TEST_FAIL;
    }

    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_HIPRIO_ARB_EN, arb_en_backup); // Restore HIPRIO_ARB enable bitmap
    return 0;
}


//--------------------------------------------------------
//    Function : DrvPWRAP_SwitchDio()
// Description : 
//   Parameter : 
//      Return : 
//--------------------------------------------------------
kal_uint32 DrvPWRAP_SwitchDio(kal_bool dio_en)
{
    kal_uint32 arb_en_backup;
    kal_uint32 rdata;
    kal_uint32 sub_return;
    kal_uint32 return_value;

    arb_en_backup = PMIC_WRAP_DRV_Reg32(PMIC_WRAP_HIPRIO_ARB_EN); // Backup HIPRIO_ARB enable bitmap
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_HIPRIO_ARB_EN, HARB_HPRIO_WACS2); // HIPRIO_ARB enable for each source. (Set WACS2 highest priority)  
    sub_return = DrvPWRAP_WACS2(PMIC_WRAP_WRITE, DEW_DIO_EN, dio_en, &rdata); // Disable / Enable dual I/O mode for SPI slave.
  
    if(sub_return != 0)  {
        /* TERR="Error: [DrvPWRAP_SwitchDio][Set DEW_DIO_EN] DrvPWRAP_WACS2 fail, return=%x, exp=0x0", sub_return*/
        ASSERT(0);        
        return PMIC_WRAP_SWITCH_DIO_FAIL;    
    }

    return_value = wait_for_state_ready(wait_for_wacs_fsm_idle_and_sync_idle, PMIC_WRAP_TIMEOUT, PMIC_WRAP_WACS2_RDATA, 0);
    if(return_value != 0)
    {
        ASSERT(0);        
        return return_value;
    }  

    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_DIO_EN, dio_en); // Eable / Disable SPI dual I/O mode
    // Read Test
    sub_return = DrvPWRAP_WACS2(PMIC_WRAP_READ, DEW_READ_TEST, 0, &rdata);
    if((sub_return != 0) || (rdata != DEW_READ_TEST_VALUE)){
        /* TERR="Error: [DrvPWRAP_SwitchDio][Read Test] DrvPWRAP_WACS2() fail, dio_en = %x, return=%x, exp=0, rdata=%x, exp=0x5aa5", dio_en, sub_return, rdata */
        ASSERT(0);        
        return PMIC_WRAP_READ_TEST_FAIL;
    }

    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_HIPRIO_ARB_EN, arb_en_backup); // Restore HIPRIO_ARB enable bitmap

    return 0;
}


//--------------------------------------------------------
//    Function : DrvPWRAP_SwitchMux()
// Description : 
//   Parameter : 
//      Return : 
//--------------------------------------------------------
void DrvPWRAP_SwitchMux(kal_uint8 mux_sel_new )
{
    kal_uint8 mux_sel_old;
//    kal_uint32 rdata;
    kal_uint32 return_value;

    // Return if no change is necessary
    mux_sel_old = PMIC_WRAP_DRV_Reg32(PMIC_WRAP_MUX_SEL); // Read SPI controller source selection
    if(mux_sel_new == mux_sel_old)
    {  
        return;
    }
  
    // Disable OLD, wait OLD finish
    // Switch MUX, then enable NEW
    if(mux_sel_new == SPI_MANUAL_MODE)
    {
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_WRAP_EN, 0x00); // Wrapper circuit is disabled, but the current transaction will be finished.
        return_value = wait_for_state_ready(wait_for_man_idle_and_noreq, PMIC_WRAP_TIMEOUT, PMIC_WRAP_WRAP_STA, 0);
        // NEED TO CHECK
        if(return_value != 0)
        {
            ASSERT(0);
        } 
        
        
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_MUX_SEL, SPI_MANUAL_MODE); // SPI is controlled in manual mode.
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_MAN_EN, 0x01); // Manual mode circuit is enable
    }
    else
    {
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_MAN_EN, 0x00); // Manual mode circuit is disabled
        return_value = wait_for_state_ready(wait_for_man_idle_and_noreq, PMIC_WRAP_TIMEOUT, PMIC_WRAP_MAN_RDATA, 0);
        // NEED TO CHECK        
        if(return_value != 0)
        {
            ASSERT(0);
        }         

        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_MUX_SEL, SPI_AUTO_MODE); // SPI is controlled by automatic wrapper
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_WRAP_EN, 0x01); // Wrapper circuit is enable, and new request can be accepted once wrapper is available
    }

    return ;
}


//--------------------------------------------------------
//    Function : DrvPWRAP_InitCIPHER()
// Description : 
//   Parameter : 
//      Return : 
//--------------------------------------------------------
kal_uint32 DrvPWRAP_InitCIPHER( void )
{
    kal_uint32 arb_en_backup;
    kal_uint32 rdata;
    kal_uint32 return_value;

    arb_en_backup = PMIC_WRAP_DRV_Reg32(PMIC_WRAP_HIPRIO_ARB_EN); // Backup HIPRIO_ARB enable bitmap

    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_HIPRIO_ARB_EN, HARB_HPRIO_WACS2); // HIPRIO_ARB enable for each source. (Set WACS2 highest priority)


    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CIPHER_SWRST, 0x01); // Enable CIPHER Soft Reset
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CIPHER_SWRST, 0x00); // Disble CIPHER Soft Reset
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CIPHER_KEY_SEL, 0x01); // All keys are hard-wired
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CIPHER_IV_SEL, 0x02); // Set 0 to choose manual initial vector, otherwise, choose other Hard-wired initial vectors.
#if defined(DRV_PMIC_WRAP_V1)    
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CIPHER_LOAD, 0x01); // CIPHER Load Key & IV
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CIPHER_START, 0x01); // CIPHER Engine Start
#elif defined(DRV_PMIC_WRAP_V2)        
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CIPHER_EN, 0x01); // CIPHER Engine Enable
#endif

    // Config CIPHER @ PMIC
    DrvPWRAP_WACS2_NoChk(PMIC_WRAP_WRITE, DEW_CIPHER_SWRST,   0x01,  &rdata); // Enabl CIPHER Soft Reset
    DrvPWRAP_WACS2_NoChk(PMIC_WRAP_WRITE, DEW_CIPHER_SWRST,   0x00,  &rdata); // Disble CIPHER Soft Reset
    DrvPWRAP_WACS2_NoChk(PMIC_WRAP_WRITE, DEW_CIPHER_KEY_SEL, 0x01,  &rdata); // All keys are hard-wired
    DrvPWRAP_WACS2_NoChk(PMIC_WRAP_WRITE, DEW_CIPHER_IV_SEL,  0x02,  &rdata); // Set 0 to choose manual initial vector, otherwise, choose other Hard-wired initial vectors.
#if defined(MT6320)
    DrvPWRAP_WACS2_NoChk(PMIC_WRAP_WRITE, DEW_CIPHER_LOAD,    0x01,  &rdata); // CIPHER Load Key & IV
    DrvPWRAP_WACS2_NoChk(PMIC_WRAP_WRITE, DEW_CIPHER_START,   0x01,  &rdata); // CIPHER Engine Start
#elif defined(MT6323)
    DrvPWRAP_WACS2_NoChk(PMIC_WRAP_WRITE, DEW_CIPHER_EN,   0x01,  &rdata); // CIPHER Engine Enable
#endif

    return_value = wait_for_state_ready_init(wait_for_cipher_ready, PMIC_WRAP_TIMEOUT, PMIC_WRAP_CIPHER_RDY, 0);
    if(return_value != 0)
    {
        ASSERT(0);        
        return return_value;
    } 
 
    do
    {
        DrvPWRAP_WACS2_NoChk(PMIC_WRAP_READ, DEW_CIPHER_RDY, 0x00, &rdata); // Wait until CIPHER Data Ready (Data should be ready before enable CIPHER_MODE)
        #if 0 // NEED TO CHECK       
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
    }while(rdata != 0x1); // Cipher_ready

    DrvPWRAP_WACS2_NoChk(PMIC_WRAP_WRITE, DEW_CIPHER_MODE, 0x01, &rdata); // CIPHER Mode Enable

    return_value = wait_for_state_ready_init(wait_for_wacs_fsm_idle_and_sync_idle, PMIC_WRAP_TIMEOUT, PMIC_WRAP_WACS2_RDATA, 0);
    if(return_value != 0)
    {
        ASSERT(0);        
        return return_value;
    } 
    
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CIPHER_MODE, 0x01); // CIPHER Mode Enable

    // Read Test
    DrvPWRAP_WACS2_NoChk(PMIC_WRAP_READ, DEW_READ_TEST, 0x00, &rdata);
    if(rdata != DEW_READ_TEST_VALUE)
    {
        /* TERR="Error: [DrvPWRAP_InitCIPHER][Read Test] fail, READ_TEST rdata=%x, exp=0x5aa5", rdata */
        ASSERT(0);        
        return PMIC_WRAP_READ_TEST_FAIL;
    }

    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_HIPRIO_ARB_EN, arb_en_backup); // Restore HIPRIO_ARB enable bitmap
    return 0;
}

//--------------------------------------------------------
//    Function : DrvPWRAP_EnableCIPHER()
// Description : 
//   Parameter : 
//      Return : 
//--------------------------------------------------------
kal_uint32 DrvPWRAP_EnableCIPHER( void )
{
    kal_uint32 arb_en_backup;
    kal_uint32 rdata;
    kal_uint32 return_value;

    arb_en_backup = PMIC_WRAP_DRV_Reg32(PMIC_WRAP_HIPRIO_ARB_EN); // Backup HIPRIO_ARB enable bitmap

    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_HIPRIO_ARB_EN, HARB_HPRIO_WACS2); // HIPRIO_ARB enable for each source. (Set WACS2 highest priority)

#if defined(MT6320)
    // Make sure CIPHER engine is idle
    DrvPWRAP_WACS2(PMIC_WRAP_WRITE, DEW_CIPHER_START, 0x00, &rdata); // CIPHER Engine Stop
#elif defined(MT6323)
    DrvPWRAP_WACS2(PMIC_WRAP_WRITE, DEW_CIPHER_EN, 0x00, &rdata); // CIPHER Engine Disable
#endif    

#if defined(DRV_PMIC_WRAP_V1)
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CIPHER_START, 0x00); // CIPHER Engine Stop
#elif defined(DRV_PMIC_WRAP_V2)
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CIPHER_EN, 0x00); // CIPHER Engine Disable
#endif

    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CIPHER_MODE, 0x00); // CIPHER Mode Disable
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CIPHER_SWRST, 0x01); // Enable CIPHER Soft Reset
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CIPHER_SWRST, 0x00); // Disble CIPHER Soft Reset
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CIPHER_KEY_SEL, 0x01); // All keys are hard-wired
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CIPHER_IV_SEL, 0x02); // Set 0 to choose manual initial vector, otherwise, choose other Hard-wired initial vectors.
#if defined(DRV_PMIC_WRAP_V1)    
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CIPHER_LOAD, 0x01); // CIPHER Load Key & IV
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CIPHER_START, 0x01); // CIPHER Engine Start
#elif defined(DRV_PMIC_WRAP_V2)
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CIPHER_EN, 0x01); // CIPHER Engine Enable
#endif    

    // Config CIPHER @ PMIC
    DrvPWRAP_WACS2(PMIC_WRAP_WRITE, DEW_CIPHER_SWRST,   0x01,  &rdata); // Enable CIPHER Soft Reset
    DrvPWRAP_WACS2(PMIC_WRAP_WRITE, DEW_CIPHER_SWRST,   0x00,  &rdata); // Disble CIPHER Soft Reset
    DrvPWRAP_WACS2(PMIC_WRAP_WRITE, DEW_CIPHER_KEY_SEL, 0x01,  &rdata); // All keys are hard-wired
    DrvPWRAP_WACS2(PMIC_WRAP_WRITE, DEW_CIPHER_IV_SEL,  0x02,  &rdata); // Set 0 to choose manual initial vector, otherwise, choose other Hard-wired initial vectors.
#if defined(MT6320)    
    DrvPWRAP_WACS2(PMIC_WRAP_WRITE, DEW_CIPHER_LOAD,    0x01,  &rdata); // CIPHER Load Key & IV
    DrvPWRAP_WACS2(PMIC_WRAP_WRITE, DEW_CIPHER_START,   0x01,  &rdata); // CIPHER Engine Start
#elif defined(MT6323)
    DrvPWRAP_WACS2(PMIC_WRAP_WRITE, DEW_CIPHER_EN,      0x01,  &rdata); // CIPHER Engine Enable
#endif    

    return_value = wait_for_state_ready_init(wait_for_cipher_ready, PMIC_WRAP_TIMEOUT, PMIC_WRAP_CIPHER_RDY, 0);
    if(return_value != 0)
    {
        ASSERT(0);        
        return return_value;
    } 
    
    do
    {
        DrvPWRAP_WACS2(PMIC_WRAP_READ, DEW_CIPHER_RDY, 0x00, &rdata); // Wait until CIPHER Data Ready (Data should be ready before enable CIPHER_MODE)
        #if 0 // NEED TO CHECK       
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif        
    }while(rdata != 0x01); // Cipher_ready

    DrvPWRAP_WACS2(PMIC_WRAP_WRITE, DEW_CIPHER_MODE, 0x01, &rdata); // CIPHER Mode Enable

    return_value = wait_for_state_ready_init(wait_for_wacs_fsm_idle_and_sync_idle, PMIC_WRAP_TIMEOUT, PMIC_WRAP_WACS2_RDATA, 0);
    if(return_value != 0)
    {
        ASSERT(0);        
        return return_value;
    } 
    
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CIPHER_MODE, 0x01); // CIPHER Mode Enable

    // Read Test
    DrvPWRAP_WACS2(PMIC_WRAP_READ, DEW_READ_TEST, 0x00, &rdata);
    if(rdata != DEW_READ_TEST_VALUE)
    {
        /* TERR="Error: [DrvPWRAP_EnableCIPHER][Read Test] fail, READ_TEST rdata=%x, exp=0x5aa5", rdata */
        ASSERT(0);        
        return PMIC_WRAP_READ_TEST_FAIL;
    }

    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_HIPRIO_ARB_EN, arb_en_backup); // Restore HIPRIO_ARB enable bitmap
    return 0;
}


//--------------------------------------------------------
//    Function : DrvPWRAP_DisableCIPHER()
// Description : 
//   Parameter : 
//      Return : 
//--------------------------------------------------------
kal_uint32 DrvPWRAP_DisableCIPHER(void)
{
    kal_uint32 arb_en_backup;
    kal_uint32 rdata;
    kal_uint32 return_value;

    arb_en_backup = PMIC_WRAP_DRV_Reg32(PMIC_WRAP_HIPRIO_ARB_EN); // Backup HIPRIO_ARB enable bitmap

    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_HIPRIO_ARB_EN, HARB_HPRIO_WACS2); // HIPRIO_ARB enable for each source. (Set WACS2 highest priority)

    //Disable CIPHER MODE
    DrvPWRAP_WACS2(PMIC_WRAP_WRITE, DEW_CIPHER_MODE, 0x00, &rdata); // CIPHER MODE Disable

    return_value = wait_for_state_ready_init(wait_for_wacs_fsm_idle_and_sync_idle, PMIC_WRAP_TIMEOUT, PMIC_WRAP_WACS2_RDATA, 0);
    if(return_value != 0)
    {
        ASSERT(0);        
        return return_value;
    } 

    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CIPHER_MODE, 0x00); // CIPHER Mode Disable
#if defined(DRV_PMIC_WRAP_V1)        
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CIPHER_START, 0x00); // CIPHER Engine Stop
#elif defined(DRV_PMIC_WRAP_V2)        
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CIPHER_EN, 0x00); // CIPHER Engine Disable
#endif    
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CIPHER_SWRST, 0x01); // Enable CIPHER Soft Reset
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CIPHER_SWRST, 0x00); // Disble CIPHER Soft Reset 

    // Read Test
    DrvPWRAP_WACS2(PMIC_WRAP_READ, DEW_READ_TEST, 0x00, &rdata);
    if(rdata != DEW_READ_TEST_VALUE)
    {
        /* TERR="Error: [DrvPWRAP_DisableCIPHER][Read Test] fail, READ_TEST rdata=%x, exp=0x5aa5", rdata */
        ASSERT(0);        
        return PMIC_WRAP_READ_TEST_FAIL;
    }

    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_HIPRIO_ARB_EN, arb_en_backup); // Restore HIPRIO_ARB enable bitmap
    return 0;
}

#if defined(DRV_PMIC_WRAP_V1)
//--------------------------------------------------------
//    Function : DrvPWRAP_InitSIDLY()
// Description : 
//   Parameter : 
//      Return : 
//--------------------------------------------------------
kal_uint32 DrvPWRAP_InitSIDLY(void) // Init SPI Input Data Stobe timing
{
    kal_uint32 arb_en_backup;
    kal_uint32 rdata;
    kal_uint32 ind;
    kal_uint32 result;
    kal_uint32 result_faulty;

    arb_en_backup = PMIC_WRAP_DRV_Reg32(PMIC_WRAP_HIPRIO_ARB_EN); // Backup HIPRIO_ARB enable bitmap

    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_HIPRIO_ARB_EN, HARB_HPRIO_WACS2); // HIPRIO_ARB enable for each source. (Set WACS2 highest priority)

    // Scan all SIDLY by Read Test
    result = 0;
    for(ind = 0 ; ind < 4 ; ind++)
    {
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_SIDLY, ind); // SPI input data strobe timing control.
        // DEW_READ_TEST: This is a dummy register used to test read access.
        DrvPWRAP_WACS2_NoChk(PMIC_WRAP_READ, DEW_READ_TEST, 0x00, &rdata);
        if(rdata == DEW_READ_TEST_VALUE)
        {
            /* TINFO="[DrvPWRAP_InitSIDLY][Read Test] pass, SIDLY=%x", ind */
            // Record pass SI delay
            result |= (0x1 << ind);
        }
    }

    // Config SIDLY according to result
    result_faulty = 0;
    switch(result)
    {
        // Only 1 pass, choose it
        case 0x1:
            PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_SIDLY, 0x00); // SPI input data strobe timing control.
        break;
        
        case 0x2:
            PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_SIDLY, 0x01);
        break;
        
        case 0x4:
            PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_SIDLY, 0x02);
        break;
        
        case 0x8:
            PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_SIDLY, 0x03);
        break;

        // Two pass, choose the one on SIDLY boundary
        case 0x3:
            PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_SIDLY, 0x00);
        break;
        
        case 0x6:
            PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_SIDLY, 0x01); // No boundary, choose smaller one
        break;
        
        case 0xc:
            PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_SIDLY, 0x03);
        break;

        // Three pass, choose the middle one
        case 0x7:
            PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_SIDLY, 0x01);
        break;
        
        case 0xe:
            PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_SIDLY, 0x02);
        break;
        
        // Four pass, choose the smaller middle one
        case 0xf:
            PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_SIDLY, 0x01);
        break;

        // pass range not continuous, should not happen
        default:
            PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_SIDLY, 0x00);
            result_faulty = 0x1;
        break;
    }

    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_HIPRIO_ARB_EN, arb_en_backup); // Restore HIPRIO_ARB enable bitmap

    if(result_faulty == 0)
    {
        return 0;
    }
    else
    {
        /* TERR="Error: [DrvPWRAP_InitSIDLY] Fail, result=%x", result */
        ASSERT(0);
        return result_faulty;
    }
}

#elif defined(DRV_PMIC_WRAP_V2)
//--------------------------------------------------------
//    Function : DrvPWRAP_InitSiStrobe()
// Description : Initialize SI_CK_CON and SIDLY
//   Parameter : 
//      Return : 
//--------------------------------------------------------
kal_uint32 DrvPWRAP_InitSiStrobe( void )
{
    kal_uint32 arb_en_backup;
    kal_uint32 rdata;
    kal_uint32 tmp1, tmp2;
    kal_uint32 result;
    kal_uint32 result_faulty;
    kal_uint32 leading_one, tailing_one;
    kal_int32 ind;    

    arb_en_backup = PMIC_WRAP_DRV_Reg32(PMIC_WRAP_HIPRIO_ARB_EN); // Backup HIPRIO_ARB enable bitmap

    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_HIPRIO_ARB_EN, HARB_HPRIO_WACS2); // HIPRIO_ARB enable for each source. (Set WACS2 highest priority)  

    //---------------------------------------------------------------------
    // Scan all possible input strobe by READ_TEST
    //---------------------------------------------------------------------
    result = 0;
    result_faulty = 0;
    // SI_EN_SEL: 0T, 1T, 2T; SI_CK_SEL: SPI CLK, Inverted SPI CLK
    // SIDLY: 0ns, 2.5ns, 5ns, 7.5 ns
    // 4(SIDLY) *  3(SI_EN_SEL) * 2(SPI_CK_SEL) = 24
    for(ind = 0; ind < 24; ind++) // 24 sampling clock edge
    {  
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_SI_CK_CON, (ind >> 2) & 0x7); // Configure SI_EN_SEL & SI_CK_SEL
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_SIDLY, 0x3 - (ind & 0x3)); // Configure SIDLY
        DrvPWRAP_WACS2_NoChk(PMIC_WRAP_READ, DEW_READ_TEST, 0, &rdata);
        if(rdata == DEW_READ_TEST_VALUE)
        {
            /* TINFO="[DrvPWRAP_InitSiStrobe][Read Test] pass, ind=%x", ind */
            // Record pass SI delay
#if defined(FPGA_CTP)            
            dbg_print("[PMIC_WRAP_MD] DrvPWRAP_InitSiStrobe [Read Test] Pass, index=%d rdata=%x\n", ind, rdata);
#endif
            result |= (0x1 << ind);            
        }
        else
        {
#if defined(FPGA_CTP)                
            dbg_print("[PMIC_WRAP_MD] DrvPWRAP_InitSiStrobe [Read Test] Fail, index=%d rdata=%x\n", ind, rdata);
#endif
    }
    }
#if defined(FPGA_CTP)     
    dbg_print("[PMIC_WRAP_MD] index=%d result=%x\n", ind, result);
#endif
    //---------------------------------------------------------------------
    // Locate the leading one and trailing one
    //---------------------------------------------------------------------
    for(ind = 23 ; ind >= 0; ind--)
    {
        if(result & (0x1 << ind)) 
        {
            break;
        }
    }
    leading_one = ind;

    for(ind=0 ; ind<24 ; ind++ )
    {
        if(result & (0x1 << ind))
        {
            break;
        }
    }
    tailing_one = ind;

    //---------------------------------------------------------------------
    // Check the continuity of pass range
    //---------------------------------------------------------------------
    tmp1 = (0x1 << (leading_one + 1)) - 1;
    tmp2 = (0x1 << tailing_one) - 1;
    if((tmp1 - tmp2) != result)
    {
        /*TERR = "[DrvPWRAP_InitSiStrobe] Fail, tmp1:%d, tmp2:%d", tmp1, tmp2*/
        result_faulty = 0x1;
    }

    //---------------------------------------------------------------------
    // Config SICK and SIDLY to the middle point of pass range
    //---------------------------------------------------------------------
    ind = (leading_one + tailing_one) >> 1;
#if defined(FPGA_CTP)     
    dbg_print("[PMIC_WRAP_MD] final ind = %d\n", ind);
#endif
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_SI_CK_CON, (ind >> 2) & 0x7); // Configure SI_EN_SEL & SI_CK_SEL
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_SIDLY, 0x3 - (ind & 0x3)); // Configure SIDLY    

    //---------------------------------------------------------------------
    // Restore
    //---------------------------------------------------------------------
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_HIPRIO_ARB_EN, arb_en_backup); // Restore HIPRIO_ARB enable bitmap    

    if(result_faulty == 0)
    {
        return 0;
    }
    else
    {
        /*TERR = "[DrvPWRAP_InitSiStrobe] Fail, result = %x", result*/
        ASSERT(0);
#if defined(FPGA_CTP)   
        dbg_print("[PMIC_WRAP_MD] DrvPWRAP_InitSiStrobe Fail!!");
#endif
        return result_faulty;
    }  
}

#endif // End of #if defined(DRV_PMIC_WRAP_V1)

//--------------------------------------------------------
//    Function : DrvPWRAP_ResetSPISLV()
// Description : 
//   Parameter : 
//      Return : 
//--------------------------------------------------------
void DrvPWRAP_ResetSPISLV(void) // Reset SPI Slave
{
//    kal_uint32 rdata;
    kal_uint32 return_value;

    // This driver does not using DrvPWRAP_SwitchMux
    // because the remaining requests are expected to fail anyway
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_HIPRIO_ARB_EN, 0x00); // HIPRIO_ARB disable for each source.
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_WRAP_EN, 0x00); // Wrapper circuit is disabled, but the current transcation will be finished.
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_MUX_SEL, 0x01); // SPI is controlled in manual mode.
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_MAN_EN, 0x01); // Manual mode circuit is enable.
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_DIO_EN, 0x00); // SPI dual I/O mode is disable.

    /* SPI Reset Pattern */
    // Pull CS to low, CS will keep low  for at least (1.5+WDATA[3:0])TSPI_CK before next OP command is executed.
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_MAN_CMD, (OP_WR << 13) | (OP_CSL  << 8)); // Write OP_CSL, 
    // Output 1 byte in single mode
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_MAN_CMD, (OP_WR << 13) | (OP_OUTS << 8)); // Write OP_OUTS to reset counter
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_MAN_CMD, (OP_WR << 13) | (OP_CSH  << 8)); // Write OP_CSH
    // Output 1 byte in single mode
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_MAN_CMD, (OP_WR << 13) | (OP_OUTS << 8)); // Write OP_OUTS
    // Output 1 byte in single mode
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_MAN_CMD, (OP_WR << 13) | (OP_OUTS << 8)); // Write OP_OUTS
    // Output 1 byte in single mode
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_MAN_CMD, (OP_WR << 13) | (OP_OUTS << 8)); // Write OP_OUTS
    // Output 1 byte in single mode  
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_MAN_CMD, (OP_WR << 13) | (OP_OUTS << 8)); // Write OP_OUTS
   
    return_value = wait_for_state_ready_init(wait_for_sync_idle, PMIC_WRAP_TIMEOUT, PMIC_WRAP_WACS2_RDATA, 0);
    // NEED TO CHECK
    if(return_value != 0)
    {
        ASSERT(0);
    }
    
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_MAN_EN, 0x00); // Manual mode circuit is disable.
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_MUX_SEL, 0x00); // SPI is controlled by automatic wrapper.
}

#if defined(DRV_PMIC_WRAP_V1)
//--------------------------------------------------------
//    Function : DrvPWRAP_EventTest()
// Description : 
//   Parameter : 
//      Return : 
//--------------------------------------------------------
kal_uint32 DrvPWRAP_EventTest( void )
{
    kal_uint32 rdata;
    kal_uint32 sub_return;

    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_EVENT_STACLR, 0xFFFF); // Write 1 to clear corresponding EVENT_STA bit.

    sub_return = DrvPWRAP_WACS2(PMIC_WRAP_WRITE, DEW_EVENT_TEST, 0x01, &rdata); // Write 1 to generate an EVENT.
    if(sub_return != 0)
    {  
        /* TERR="Error: [DrvPWRAP_EventTest][DrvPWRAP_WACS2] fail, return=%x, exp=0x0", sub_return*/
        ASSERT(0);
        return PMIC_WRAP_WRITE_FAIL;    
    }

    // Delay 10us (NEED TO CHECK) delay at least 2us
    #ifndef FPGA_6320
    #if 0 // Anderson 2012/07/22
/* under construction !*/
/* under construction !*/
    #endif
    #else
        for(i = 0 ; i< 0x20 ; i++);
    #endif

    rdata = PMIC_WRAP_DRV_Reg32(PMIC_WRAP_EVENT_STA); // When a EVENT has been received, the corresponding EVENT_STA will be asserted. (For debug)
    if((rdata & 0x8000) != 0x8000) // Check Debug Event
    {
        /* TERR="Error: [DrvPWRAP_EventTest] fail, PMIC_WRAP_EVENT_STA rdata=%x, exp=0x8000", rdata */
        ASSERT(0);        
        return PMIC_WRAP_DEW_EVENT_TEST_FAIL;
    }

    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_EVENT_STACLR, 0xFFFF); // Write 1 to clear corresponding EVENT_STA bit.
    return 0;
}
#endif // End of #if defined(DRV_PMIC_WRAP_V1)

//--------------------------------------------------------
//    Function : DrvPWRAP_Man()
// Description : 
//   Parameter : 
//      Return : 
//--------------------------------------------------------
kal_uint32 DrvPWRAP_Man(kal_uint32 write, kal_uint32 op, kal_uint32 wdata, kal_uint32 *rdata)
{
    kal_uint32 reg_rdata;
    kal_uint32 man_write;
    kal_uint32 man_op;
    kal_uint32 return_value;

    reg_rdata = PMIC_WRAP_DRV_Reg32(PMIC_WRAP_MAN_RDATA); // Manual Read Data
    if(GET_MAN_FSM( reg_rdata) != MAN_FSM_IDLE_STATE) //IDLE State
    {
        ASSERT(0);
        return PMIC_WRAP_MANUAL_MODE_NOT_IDLE;
    }

    // Check argument validation
    if((write & ~(0x1))    != 0)  return PMIC_WRAP_INVALID_RW; // Write should be 1 bit
    if((op   & ~(0x1f)) != 0)  return PMIC_WRAP_INVALID_OP; // OP should no larger than 0xFFFF
    if((wdata & ~(0xff)) != 0)  return PMIC_WRAP_INVALID_WDATA; // Write DATA should be no larger than 0xFF    

    man_write = write << 13;
    man_op    = op << 8;
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_MAN_CMD, man_write | man_op | wdata);

    if(write == OP_RD)
    {
        return_value = wait_for_state_ready_init(wait_for_man_wfvldclr, PMIC_WRAP_TIMEOUT, PMIC_WRAP_MAN_RDATA, &reg_rdata);
        if(return_value != 0)
        {
            ASSERT(0);            
            return return_value;
        }         
 
        *rdata = GET_MAN_RDATA(reg_rdata);
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_MAN_VLDCLR, 0x01);        
    }

    return 0;
}

//--------------------------------------------------------
//    Function : DrvPWRAP_ManAccess()
// Description : 
//   Parameter : 
//      Return : 
//--------------------------------------------------------
kal_uint32 DrvPWRAP_ManAccess(kal_uint32 write, kal_uint32 adr, kal_uint32 wdata, kal_uint32 *rdata )
{
    kal_uint32 man_wdata;
    kal_uint32 man_rdata;

    // Check argument validation
    if((write & ~(0x1))    != 0)  return PMIC_WRAP_INVALID_RW; // Write should be 1 bit
    if((adr   & ~(0xffff)) != 0)  return PMIC_WRAP_INVALID_ADDR; // Address should no larger than 0xFFFF
    if((wdata & ~(0xffff)) != 0)  return PMIC_WRAP_INVALID_WDATA; // Write DATA should be no larger than 0xFFFF  

    DrvPWRAP_SwitchMux(SPI_MANUAL_MODE); // Switch to Manual Mode
    DrvPWRAP_Man(OP_WR,  OP_CSH,  0x00, &man_rdata);
    DrvPWRAP_Man(OP_WR,  OP_CSL,  0x00, &man_rdata);
#if defined(MT6320)    
    man_wdata = adr >> 1;
    DrvPWRAP_Man(OP_WR,  OP_OUTD, (man_wdata & 0xff), &man_rdata);
    man_wdata = (adr >> 9) | (write << 7);
    DrvPWRAP_Man(OP_WR,  OP_OUTD, (man_wdata & 0xff), &man_rdata);
#elif defined(MT6323)
    man_wdata = (adr >> 9) | (write << 7);
    DrvPWRAP_Man(OP_WR,  OP_OUTD, (man_wdata & 0xff), &man_rdata);
    man_wdata = adr >> 1;
    DrvPWRAP_Man(OP_WR,  OP_OUTD, (man_wdata & 0xff), &man_rdata);
#endif

#if defined(DRV_PMIC_WRAP_V1)
    DrvPWRAP_Man(OP_WR,  OP_CSH,  0x00, &man_rdata);
    DrvPWRAP_Man(OP_WR,  OP_CSL,  0x00, &man_rdata);
#endif    
    
    if(write == PMIC_WRAP_WRITE)
    {
#if defined(MT6320)        
        man_wdata = wdata;
        DrvPWRAP_Man(OP_WR,  OP_OUTD, (man_wdata & 0xff), &man_rdata);
        man_wdata = wdata >> 8;
        DrvPWRAP_Man(OP_WR,  OP_OUTD, (man_wdata & 0xff), &man_rdata);      
#elif defined(MT6323)
        man_wdata = wdata >> 8;
        DrvPWRAP_Man(OP_WR,  OP_OUTD, (man_wdata & 0xff), &man_rdata);
        man_wdata = wdata;
        DrvPWRAP_Man(OP_WR,  OP_OUTD, (man_wdata & 0xff), &man_rdata);
#endif
    }
    else
    {
#if defined(MT6320)
#if defined(DRV_PMIC_WRAP_V2)
        DrvPWRAP_Man(OP_WR,  OP_CSL, 2, &man_rdata);
#endif
        DrvPWRAP_Man(OP_RD,  OP_IND, 0, &man_rdata);
        *rdata = GET_MAN_RDATA(man_rdata);
        DrvPWRAP_Man(OP_RD,  OP_IND, 0, &man_rdata);
        *rdata |= (GET_MAN_RDATA(man_rdata) << 8);  
#elif defined(MT6323)
        DrvPWRAP_Man(OP_WR,  OP_CK,  8, &man_rdata);
        DrvPWRAP_Man(OP_RD,  OP_IND, 0, &man_rdata);    
        *rdata = GET_MAN_RDATA( man_rdata ) << 8;
        DrvPWRAP_Man(OP_RD,  OP_IND, 0, &man_rdata);
        *rdata |= GET_MAN_RDATA( man_rdata );
#endif
    }
#if defined(DRV_PMIC_WRAP_V2)
    DrvPWRAP_Man(OP_WR,  OP_CSL,  0, &man_rdata);
#endif    
    DrvPWRAP_Man(OP_WR, OP_CSH, 0, &man_rdata);

    return 0;
}

//--------------------------------------------------------
//    Function : DrvPWRAP_StaUpdTrig()
// Description : 
//   Parameter : 
//      Return : 
//--------------------------------------------------------
kal_uint32 DrvPWRAP_StaUpdTrig(kal_uint32 mode) // NEED TO CHECK (WHAT Purpose? MODE:0->? 1->?) // No Need Implement
{
    // kal_uint32 man_rdata;
    kal_uint32 return_value;

    // Wait for FSM to be IDLE
    return_value = wait_for_state_ready_init(wait_for_staupd_idle, PMIC_WRAP_TIMEOUT, PMIC_WRAP_STAUPD_STA, 0);
    if(return_value != 0)
    {
        ASSERT(0);        
        return return_value;
    }       

    // Trigger FSM
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_STAUPD_MAN_TRIG, 0x01); // Set 1 to manually trigger Status Update Circuit

    // Check if FSM is in REQ
    if(GET_STAUPD_FSM(PMIC_WRAP_DRV_Reg32(PMIC_WRAP_STAUPD_STA)) != STAUPD_FSM_REQ_STATE) // Current STAUPD FSM is REQ State
    {
        ASSERT(0);
        return PMIC_WRAP_STAUPD_FSM_NOT_IDLE;
    }

    // If mode==1, only return after new status is updated.
    if(mode == 1)
    {
        return_value = wait_for_state_ready_init(wait_for_staupd_idle, PMIC_WRAP_TIMEOUT, PMIC_WRAP_STAUPD_STA, 0);
        if(return_value != 0)
        {
            ASSERT(0);            
            return return_value;
        } 
    }

    return 0;
}

//--------------------------------------------------------
//    Function : DrvPWRAP_AlignCRC()
// Description : 
//   Parameter : 
//      Return : 
//--------------------------------------------------------
void DrvPWRAP_AlignCRC(void)
{
    kal_uint32 rdata;
//    kal_uint32 reg_rdata;
    kal_uint32 arb_en_backup;
    kal_uint32 staupd_prd_backup;
    kal_uint32 return_value;

    // Backup Configuration & Set New Ones
    arb_en_backup = PMIC_WRAP_DRV_Reg32(PMIC_WRAP_HIPRIO_ARB_EN); // Backup HIPRIO_ARB enable bitmap
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_HIPRIO_ARB_EN, HARB_HPRIO_WACS2); // HIPRIO_ARB enable for each source. (Set WACS2 highest priority)
    staupd_prd_backup = PMIC_WRAP_DRV_Reg32(PMIC_WRAP_STAUPD_PRD);
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_STAUPD_PRD, 0x00); // Disable Periodic status update timing (period) selection.

    // Reset CRC
#if defined(MT6320)    
    DrvPWRAP_WACS2(PMIC_WRAP_WRITE, DEW_CRC_EN, 0x00, &rdata); // Disable CRC calculation circuit.
#elif defined(MT6323)
    DrvPWRAP_WACS2(PMIC_WRAP_WRITE, DEW_CRC_SWRST, 0x01, &rdata); // Set 1 to reset CRC calculation circuit.
#endif
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CRC_EN, 0x00); // Disable CRC calculation circuit.

    return_value = wait_for_state_ready_init(wait_for_wrap_req_counter_zero, PMIC_WRAP_TIMEOUT, PMIC_WRAP_WRAP_STA, 0);
    //  NEED TO CHECK
    if(return_value != 0)
    {
        ASSERT(0);
    }

    // Enable CRC
#if defined(MT6320)      
    DrvPWRAP_WACS2(PMIC_WRAP_WRITE, DEW_CRC_EN, 0x01, &rdata); // Enable CRC calculation circuit.
#elif defined(MT6323)
    DrvPWRAP_WACS2(PMIC_WRAP_WRITE, DEW_CRC_SWRST, 0x0, &rdata); // Set 0 to release reset CRC calculation circuit.
#endif
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CRC_EN, 0x01); // Enable CRC calculation circuit.

    //restore Configuration
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_STAUPD_PRD, staupd_prd_backup);
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_HIPRIO_ARB_EN, arb_en_backup); // Restore HIPRIO_ARB enable bitmap
}

//--------------------------------------------------------
//    Function : DrvPWRAP_InitRegClk()
// Description : 1: reg_max_ck / 2; 2: reg_max_ck
//   Parameter : int regck_sel
//      Return : 
//--------------------------------------------------------
kal_uint32 DrvPWRAP_InitRegClk(kal_uint32 regck_sel) // 0:safe mode, 1:18MHz, 2:36MHz
{
    kal_uint32 wdata;
    kal_uint32 rdata;

    // Set reg clk freq
#if defined(MT6320)    
    DrvPWRAP_WACS2_NoChk(PMIC_WRAP_READ, TOP_CKCON2, 0x00, &rdata); // Read Top clock control register 2 
    if(regck_sel == PMIC_WRAP_REG_CLOCK_18MHZ)  
    {
//		wdata = rdata | 0x8000; // 32K
        wdata = (rdata & ~(0x3 << 10)) | (0x1 << 10); // / 2
    }
    else
    {
//        wdata = rdata & ~(0x8000); // 26Mhz
        wdata = (rdata & ~(0x3 << 10)); // /1
    } 
    
    DrvPWRAP_WACS2_NoChk(PMIC_WRAP_WRITE, TOP_CKCON2, wdata, &rdata); // Write RG_FQMTR_CKSEL (FQMTR clock source select)
    DrvPWRAP_WACS2_NoChk(PMIC_WRAP_READ, TOP_CKCON2, 0x00, &rdata); // Read again    
    
    if(rdata != wdata) 
    {
        /* TERR="Error: [DrvPWRAP_InitRegClk] TOP_CKCON2 Write [15]=1 Fail, rdata=%x", rdata*/
        ASSERT(0);        
        return PMIC_WRAP_WRITE_FAIL;
    }    
#elif defined(MT6323) 
    
    if(regck_sel == PMIC_WRAP_REG_CLOCK_18MHZ)  
    {
        return PMIC_WRAP_WRITE_FAIL; // Not support in 6323!!
    }
    else
    {
        wdata = 0x3;
    }

    DrvPWRAP_WACS2_NoChk(PMIC_WRAP_WRITE, TOP_CKCON1_CLR, wdata, &rdata); // Top clock control register 1 CLR, to let register clock full speed
    DrvPWRAP_WACS2_NoChk(PMIC_WRAP_READ, TOP_CKCON1, 0x00, &rdata); // Read again   

    if((rdata & 0x3) != 0) 
    {
        /* TERR="Error: [DrvPWRAP_InitRegClk] TOP_CKCON1 Write [15]=1 Fail, rdata=%x", rdata*/
        ASSERT(0);        
        return PMIC_WRAP_WRITE_FAIL;
    }  

#endif // End of #if defined(MT6320)

#if defined(DRV_PMIC_WRAP_V2)  
#if defined(MT6320)
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_RDDMY, 0x05);
#elif defined(MT6323)
    DrvPWRAP_WACS2_NoChk(PMIC_WRAP_WRITE, DEW_RDDMY_NO, 0x08, &rdata);
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_RDDMY, 0x08);
#endif
#endif

    // Config SPI Waveform according to reg clk
    if(regck_sel == PMIC_WRAP_REG_CLOCK_18MHZ) // 6MHz in 6323  => no support ; 18MHz in 6320
    { 
        // 18MHz
#if defined(DRV_PMIC_WRAP_V1)
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CSHEXT, 0x0C); // Extend CS high time to be at least (1+CSHEXT[3:0])T of SPI CLK.
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CSHEXT_WRITE, 0x04); // Extend CS high time to be at least (1+CSHEXT_WRITE[3:0])T of SPI CLK.
        // For 6320, slave need enough time to back idle state
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CSHEXT_READ, 0x0C); // Extend CS high time to be at least (1+CSHEXT_READ[3:0])T of SPI CLK       
#elif defined(DRV_PMIC_WRAP_V2)  
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CSHEXT_WRITE, 0x04); // Extend CS high time to be at least (1+CSHEXT_WRITE[3:0])T of SPI CLK.
        // For 6320, slave need enough time to back idle state
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CSHEXT_READ, 0x05); // Extend CS high time to be at least (1+CSHEXT_READ[3:0])T of SPI CLK               
#endif        
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CSLEXT_START, 0x00); // Extend CS low time after CSL command to be at least (1.5+CSLEXT_START[3:0])T of SPI CLK
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CSLEXT_END, 0x00); // Extend CS low time before CSH command to be at least (1.5+CSLEXT_END[3:0])T of SPI CLK
    }else if(regck_sel == PMIC_WRAP_REG_CLOCK_36MHZ) // 12MHz in 6323; 36MHz in 6320
    { 
        // 36MHz    
#if defined(DRV_PMIC_WRAP_V1)
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CSHEXT, 0x04); // Extend CS high time to be at least (1+CSHEXT[3:0])T of SPI CLK.
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CSHEXT_WRITE, 0x00); // Extend CS high time to be at least (1+CSHEXT_WRITE[3:0])T of SPI CLK.
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CSHEXT_READ, 0x04); // Extend CS high time to be at least (1+CSHEXT_READ[3:0])T of SPI CLK        
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CSLEXT_START, 0x00); // Extend CS low time after CSL command to be at least (1.5+CSLEXT_START[3:0])T of SPI CLK
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CSLEXT_END, 0x00); // Extend CS low time before CSH command to be at least (1.5+CSLEXT_END[3:0])T of SPI CLK
#elif defined(DRV_PMIC_WRAP_V2)  
#if defined(MT6320)
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CSHEXT_READ, 0x02); // Extend CS high time to be at least (1+CSHEXT_READ[3:0])T of SPI CLK                
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CSHEXT_WRITE, 0x02); // Extend CS high time to be at least (1+CSHEXT_WRITE[3:0])T of SPI CLK.
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_RDDMY, 0x02);
#elif defined(MT6323)
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CSHEXT_READ, 0x00); // Extend CS high time to be at least (1+CSHEXT_READ[3:0])T of SPI CLK
        // Wait data written into register => 3T_PMIC: consists of CSLEXT_END(1T) + CSHEXT(6T)        
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CSHEXT_WRITE, 0x05); // Extend CS high time to be at least (1+CSHEXT_WRITE[3:0])T of SPI CLK.        
#endif
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CSLEXT_START, 0x00); // Extend CS low time after CSL command to be at least (1.5+CSLEXT_START[3:0])T of SPI CLK
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CSLEXT_END, 0x00); // Extend CS low time before CSH command to be at least (1.5+CSLEXT_END[3:0])T of SPI CLK
#endif
    }else 
    { 
        // Safe mode
#if defined(DRV_PMIC_WRAP_V1)        
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CSHEXT, 0x0F); // Extend CS high time to be at least (1+CSHEXT[3:0])T of SPI CLK.
#endif        
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CSHEXT_WRITE, 0x0F); // Extend CS high time to be at least (1+CSHEXT_WRITE[3:0])T of SPI CLK.
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CSHEXT_READ, 0x0F); // Extend CS high time to be at least (1+CSHEXT_READ[3:0])T of SPI CLK
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CSLEXT_START, 0x0F); // Extend CS low time after CSL command to be at least (1.5+CSLEXT_START[3:0])T of SPI CLK
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CSLEXT_END, 0x0F); // Extend CS low time before CSH command to be at least (1.5+CSLEXT_END[3:0])T of SPI CLK
    }

    return 0;
}
#endif // End of #if !defined(DRV_PMIC_OFF)
