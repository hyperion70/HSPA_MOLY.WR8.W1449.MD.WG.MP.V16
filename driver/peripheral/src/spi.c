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
 *    spi.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the SPI driver.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "drv_features.h"
#include "spi_define.h"


//////////////////RHR-ADD//////////////////////
#include "intrCtrl.h"
#include "reg_base.h"
#include "drv_hisr.h"
//#include "Rtfiles.h"
#include "fs_gprot.h"
#include "string.h"
#include "cache_sw.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "init.h"
//////////////////RHR-ADD//////////////////////

//////////////////RHR-REMOVE//////////////////////
//#include <spi_define.h>
//#include "kal_non_specific_general_types.h"
//#include "kal_release.h"
  #include "drvpdn.h"
//#include "kal_common_defs.h"
//#include "stack_utils.h"
//#include "fs_kal.h"
//////////////////////////////////////////////////

#if defined(DRV_SPI_SUPPORT)
/** \file spi.c
 * \author Wei Hu (mtk01333)
 */
/** \mainpage
 *
 * The SPI hardware can be only accessed by one task, so
 * that caller has to get the ownership of the SPI interface
 * first.
 *
 * The spi_init() function has to be called at the system
 * start up time. Before caller can use the SPI interface, he
 * has to call spi_open() first trying to get the
 * ownership. If spi_open() succeed, then caller can get an
 * identifier number through the its parameter. After that,
 * when caller needs to call SPI functions, he may need to
 * provide this identifier number as the first parameter of
 * these functions if needed.
 *
 * If this identifier number is not recognized by the SPI
 * interface, then this means this caller doesn't have the
 * ownership, so that the function call made by this caller
 * this time will not be success.
 *
 * Almost all the SPI interface functions will return a
 * value of type kal_bool. When these functions return a
 * KAL_FALSE, then the caller can use spi_get_error_code() to
 * see what was wrong.
 */
/** \defgroup spi SPI device driver interface
 * \brief
 * This document introduces the data structures and the functions defined
 * in the SPI device driver of MT6238.
 * \dot
 * digraph spi
 * {
 * {
 * rank=same;
 * spi_driver [shape=record, label="{SPI driver | <LISR> SPI_LISR}"];
 * spi_controller [label="SPI controller"];
 * spi_device [shape=record, label="<interface> SPI interface | <device> SPI device"]
 * }
 * {
 * rank=same;
 * callback_func_for_pause [label="Callback func for pause"]
 * callback_func_for_finish [label="Callback func for finish"]
 * }
 * spi_driver -> spi_controller [label="config"];
 * spi_controller -> spi_driver:LISR [label="interrupt"];
 * spi_device:device -> spi_controller [label="interrupt"];
 * spi_device:interface -> spi_controller [label="read data"];
 * spi_controller -> spi_device:interface [label="send data"];
 * spi_driver:LISR->callback_func_for_pause;
 * spi_driver:LISR->callback_func_for_finish;
 * }
 * \enddot
 *
 * The Serial Peripheral Interface Bus or SPI (often
 * pronounced like "spy") bus is a synchronous serial data
 * link standard designed by Motorola that operates in full
 * duplex mode. Devices communicate in master/slave mode
 * where the master device initiates the data
 * frame. Multiple slave devices are allowed with individual
 * select lines.
 * @{
 */

#include <spi.h>
#include <spi_internal.h>

#include "dcl.h"
//#include "mm_power_ctrl.h"

typedef void (*LISR_TYPE)(void);
/* The callback function when a SPI pause interrupt
 * is occured. 
 */
#if defined(SPI_DVT_LOAD)
__attribute__ ((section ("SDRAMRW"))) 
#endif /*#if defined(SPI_DVT_LOAD) */
volatile static LISR_TYPE pause_cb = NULL;
/* The callback function when a SPI finish interrupt
 * is occured. 
 */
#if defined(SPI_DVT_LOAD)
__attribute__ ((section ("SDRAMRW"))) 
#endif /*#if defined(SPI_DVT_LOAD) */
volatile static LISR_TYPE finish_cb = NULL;
#if defined(SPI_DVT_LOAD)
__attribute__ ((section ("SDRAMRW"))) 
#endif /*#if defined(SPI_DVT_LOAD) */
static kal_bool spi_is_used = KAL_FALSE;
#if defined(SPI_DVT_LOAD)
__attribute__ ((zero_init, section ("SDRAMZI"))) 
#endif /*#if defined(SPI_DVT_LOAD) */
static kal_int32 spi_current_passport;
#if defined(SPI_DVT_LOAD)
__attribute__ ((zero_init, section ("SDRAMZI"))) 
#endif /*#if defined(SPI_DVT_LOAD) */
volatile static SPI_ERROR_CODE spi_error_code;
#if defined(SPI_DVT_LOAD)
__attribute__ ((section ("SDRAMRW"))) 
#endif /*#if defined(SPI_DVT_LOAD) */
volatile kal_semid spi_sem_id = NULL;
#define FILENAME_BUF_SIZE (50)
/* The following owner_lineno, owner_filename, and
 * owner_taskid is useful on debugging.
 */
#if defined(SPI_DVT_LOAD)
__attribute__ ((zero_init, section ("SDRAMZI"))) 
#endif /*#if defined(SPI_DVT_LOAD) */
volatile static kal_uint32 owner_lineno;
#if defined(SPI_DVT_LOAD)
__attribute__ ((zero_init, section ("SDRAMZI"))) 
#endif /*#if defined(SPI_DVT_LOAD) */
volatile static char owner_filename[FILENAME_BUF_SIZE];
#if defined(SPI_DVT_LOAD)
__attribute__ ((zero_init, section ("SDRAMZI"))) 
#endif /*#if defined(SPI_DVT_LOAD) */
volatile static kal_taskid owner_taskid;
#if defined(SPI_DVT_LOAD)
__attribute__ ((section ("SDRAMRW"))) 
#endif /*#if defined(SPI_DVT_LOAD) */
volatile kal_eventgrpid spi_event_id = NULL;
#if defined(SPI_DVT_LOAD)
__attribute__ ((zero_init, section ("SDRAMZI"))) 
#endif /*#if defined(SPI_DVT_LOAD) */
volatile kal_uint32 spi_on_mt6276e2 = 0;
#if defined (DRV_SPI_COMMAND)
#define CLEAR_SPI_COMM_REG(bit_pos)             \
  do {                                          \
    SPI_COMM_REG &= (~(1 << bit_pos));          \
  } while (0)
#define SET_SPI_COMM_REG(bit_pos, status)       \
  do {                                          \
    SPI_COMM_REG |= (status << bit_pos);        \
  } while(0)
#elif defined(MT6268)
#define CLEAR_SPI_COMM_REG(bit_pos)                   \
  do {                                                \
    kal_uint32 tmp = SPI_COMM_REG;                    \
    tmp &= (~(1 << bit_pos));                         \
    SPI_COMM_REG = (tmp | (1 << SPI_COMM_BIT_RESET)); \
  } while (0)
#define SET_SPI_COMM_REG(bit_pos, status)                               \
  do {                                                                  \
    SPI_COMM_REG |= ((status << bit_pos) | (1 << SPI_COMM_BIT_RESET));  \
  } while(0)
#else
#error;  //to  do  in MT6280
#endif
/* The HISR of the SPI interface.
 */
#if defined(SPI_DVT_LOAD)
__attribute__ ((section ("SDRAMCODE"))) 
#endif /*#if defined(SPI_DVT_LOAD) */
void SPI_HISR(void) 
{
    kal_uint32 volatile tmp;
    kal_uint32 const savedMask = SaveAndSetIRQMask();
    LISR_TYPE tmp_pause_cb = pause_cb;
    LISR_TYPE tmp_finish_cb = finish_cb;
    RestoreIRQMask(savedMask);
    tmp = SPI_STATUS1_REG;
    if ((tmp & SPI_STATUS1_BIT_PAUSE) && (tmp_pause_cb != NULL)) 
    {
        tmp_pause_cb();
    }
    if ((tmp & SPI_STATUS1_BIT_FINISH) && (tmp_finish_cb != NULL)) 
    {
        tmp_finish_cb();
    }
#if defined(MT6276)
    //set event
    if (spi_on_mt6276e2)
	    kal_set_eg_events(spi_event_id, SPI_EVENT_TRANSFER_COMPLETE, KAL_OR);
#endif
    IRQClearInt(IRQ_SPI_CODE);
    IRQUnmask(IRQ_SPI_CODE);
}
/* The LISR of the SPI interface.
 */
#if defined(SPI_DVT_LOAD)
__attribute__ ((section ("SDRAMCODE"))) 
#endif /*#if defined(SPI_DVT_LOAD) */
void SPI_LISR(void)
{
    IRQMask(IRQ_SPI_CODE);
#if defined(SPI_MAUI_LOAD)
    /* activate driver HISR */
    drv_active_hisr(DRV_SPI_HISR_ID);
#else
    SPI_HISR();
#endif
}
/** \brief Get the error code of the SPI interface.
 * 
 * 
 * 
 * \return The error code of the SPI interface
 */
#if defined(SPI_DVT_LOAD)
__attribute__ ((section ("SDRAMCODE"))) 
#endif /*#if defined(SPI_DVT_LOAD) */
SPI_ERROR_CODE spi_get_error_code(void)
{
    return spi_error_code;
}
/* Caller should NOT call this function directly. */
#ifdef DRV_SPI_HAL
#if defined(SPI_DVT_LOAD)
__attribute__ ((section ("SDRAMCODE"))) 
#endif /*#if defined(SPI_DVT_LOAD) */
kal_bool spi_open_old(kal_int32 * const id,
                      char const * const filename,
                      kal_uint32 const lineno)
#else
kal_bool spi_open(kal_int32 * const id,
                  char const * const filename,
                  kal_uint32 const lineno)
#endif
{
    kal_int32 local_id;
    kal_bool result;
    DCL_HANDLE gpio_handle;
    if (NULL == id)
    {
        spi_error_code = SPI_ERROR_CODE_ID_PTR_CAN_NOT_BE_ZERO;
        return KAL_FALSE;
    }
    if (NULL == filename)
    {
        spi_error_code = SPI_ERROR_CODE_FILENAME_PTR_CAN_NOT_BE_ZERO;
        return KAL_FALSE;
    }
    /* Turn on SPI clock. */
#if defined(__MTK_TARGET__)
#if defined(MT6238) || defined(MT6239)
    *((kal_uint32 volatile *)DRVPDN_CON1_CLR) |= 0x2000;
#elif defined(MT6268A) || defined(MT6268) || defined(MT6516)
#if defined(__OLD_PDN_DEFINE__ )
    DRV_Reg(MMCG_CLR0) = MMCG_CON0_SPI;
#else
    mm_enable_power(MMPWRMGR_SPI);
#endif
#if defined(MT6268)
    // For 6268 GMC & SPI chip select bug.
    // ===================
    // before power on
    // ============================
    // open the clock
    // set gpio_mode[91:90] = 2'b01;
    //GPIO_ModeSetup(45, 1);
    gpio_handle = DclGPIO_Open(DCL_GPIO,45);
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_1,0);
    DclGPIO_Close(gpio_handle);
#endif
#elif defined(DRV_SPI_PDN_ON)
#if defined(__OLD_PDN_ARCH__) && defined(__OLD_PDN_DEFINE__)
#error
#else
   #if defined(DRV_SPI_SYS_PDN)
      PDN_CLR(PDN_SPI);
   #else
    mm_enable_power(MMPWRMGR_SPI);
    #endif
    //mm_enable_clock(MMPWRMGR_SPI);
    //*(volatile kal_uint32*)(0x98000340) = 0x80000;
#endif
#else
#error
#endif
#endif
    /* Switch GPIO register to SPI mode. */
#if defined(MT6238) || defined(MT6239)
    //*((kal_uint32 volatile *)GPIO_MODE5) &= (~0xF000);
    //*((kal_uint32 volatile *)GPIO_MODE5) |= 0x5000;
    //*((kal_uint32 volatile *)GPIO_MODE6) &= (~0xF);
    //*((kal_uint32 volatile *)GPIO_MODE6) |= 0x5;
    //GPIO_ModeSetup(38, 1);
    gpio_handle = DclGPIO_Open(DCL_GPIO,38);
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_1,0);
    DclGPIO_Close(gpio_handle);
    //GPIO_ModeSetup(39, 1);
    gpio_handle = DclGPIO_Open(DCL_GPIO,39);
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_1,0);
    DclGPIO_Close(gpio_handle);
    //GPIO_ModeSetup(40, 1);
    gpio_handle = DclGPIO_Open(DCL_GPIO,40);
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_1,0);
    DclGPIO_Close(gpio_handle);
    //GPIO_ModeSetup(41, 1);
    gpio_handle = DclGPIO_Open(DCL_GPIO,41);
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_1,0);
    DclGPIO_Close(gpio_handle);
#elif defined(MT6516)
    //*((kal_uint32 volatile *)GPIO_MODE11) &= (~0x00FF);
    //*((kal_uint32 volatile *)GPIO_MODE11) |= 0x0055;
    //GPIO_ModeSetup(80, 1);
    gpio_handle = DclGPIO_Open(DCL_GPIO,80);
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_1,0);
    DclGPIO_Close(gpio_handle);
    //GPIO_ModeSetup(81, 1);
    gpio_handle = DclGPIO_Open(DCL_GPIO,81);
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_1,0);
    DclGPIO_Close(gpio_handle);
    //GPIO_ModeSetup(82, 1);
    gpio_handle = DclGPIO_Open(DCL_GPIO,82);
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_1,0);
    DclGPIO_Close(gpio_handle);
    //GPIO_ModeSetup(83, 1);
    gpio_handle = DclGPIO_Open(DCL_GPIO,83);
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_1,0);
    DclGPIO_Close(gpio_handle);
#elif defined(MT6268A)
    //*((kal_uint32 volatile *)GPIO_MODE6) &= (~0x3FC);
    //*((kal_uint32 volatile *)GPIO_MODE6) |= 0x154;
    //GPIO_ModeSetup(43, 1);
    gpio_handle = DclGPIO_Open(DCL_GPIO,43);
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_1,0);
    DclGPIO_Close(gpio_handle);
    //GPIO_ModeSetup(44, 1);
    gpio_handle = DclGPIO_Open(DCL_GPIO,44);
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_1,0);
    DclGPIO_Close(gpio_handle);
    //GPIO_ModeSetup(45, 1);
    gpio_handle = DclGPIO_Open(DCL_GPIO,45);
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_1,0);
    DclGPIO_Close(gpio_handle);
    //GPIO_ModeSetup(46, 1);
    gpio_handle = DclGPIO_Open(DCL_GPIO,46);
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_1,0);
    DclGPIO_Close(gpio_handle);
#elif defined(MT6268)
    //*((kal_uint32 volatile *)GPIO_MODE6) &= (~0xFC00);
    //*((kal_uint32 volatile *)GPIO_MODE6) |= 0x5400;
    //*((kal_uint32 volatile *)GPIO_MODE7) &= (~0x3);
    //*((kal_uint32 volatile *)GPIO_MODE7) |= 0x1;
    //GPIO_ModeSetup(45, 1);
    gpio_handle = DclGPIO_Open(DCL_GPIO,45);
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_1,0);
    DclGPIO_Close(gpio_handle);
    //GPIO_ModeSetup(46, 1);
    gpio_handle = DclGPIO_Open(DCL_GPIO,46);
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_1,0);
    DclGPIO_Close(gpio_handle);
    //GPIO_ModeSetup(47, 1);
    gpio_handle = DclGPIO_Open(DCL_GPIO,47);
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_1,0);
    DclGPIO_Close(gpio_handle);
    //GPIO_ModeSetup(48, 1);
    gpio_handle = DclGPIO_Open(DCL_GPIO,48);
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_1,0);
    DclGPIO_Close(gpio_handle);
#elif defined(MT6236)
    //*((kal_uint32 volatile *)GPIO_MODE2) &= (~0x0FF0);
    //*((kal_uint32 volatile *)GPIO_MODE2) |= 0x0AA0;
    //GPIO_ModeSetup(10, 1);
    gpio_handle = DclGPIO_Open(DCL_GPIO,10);//SPI_CS_N
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_1,0);
    DclGPIO_Close(gpio_handle);
    //GPIO_ModeSetup(11, 1);
    gpio_handle = DclGPIO_Open(DCL_GPIO,11);//SPI_SCK
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_1,0);
    DclGPIO_Close(gpio_handle);
    //GPIO_ModeSetup(12, 1);
    gpio_handle = DclGPIO_Open(DCL_GPIO,12);//SPI_MOSI
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_1,0);
    DclGPIO_Close(gpio_handle);
    //GPIO_ModeSetup(13, 1);
    gpio_handle = DclGPIO_Open(DCL_GPIO,13);//SPI_MISO
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_1,0);
    DclGPIO_Close(gpio_handle);
#elif defined(MT6276)
    gpio_handle = DclGPIO_Open(DCL_GPIO,101);//SPI_CS_N
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_2,0);
    DclGPIO_Close(gpio_handle);
    gpio_handle = DclGPIO_Open(DCL_GPIO,104);//SPI_SCK
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_2,0);
    DclGPIO_Close(gpio_handle);
    gpio_handle = DclGPIO_Open(DCL_GPIO,102);//SPI_MOSI
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_2,0);
    DclGPIO_Close(gpio_handle);
    gpio_handle = DclGPIO_Open(DCL_GPIO,103);//SPI_MISO
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_2,0);
    DclGPIO_Close(gpio_handle);
    
    //for SPI 1
    gpio_handle = DclGPIO_Open(DCL_GPIO,38);//SPI1_CS_N
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_3,0);
    DclGPIO_Close(gpio_handle);
    gpio_handle = DclGPIO_Open(DCL_GPIO,47);//SPI1_SCK
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_3,0);
    DclGPIO_Close(gpio_handle);
    gpio_handle = DclGPIO_Open(DCL_GPIO,39);//SPI1_MOSI
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_3,0);
    DclGPIO_Close(gpio_handle);
#if defined(SPI_DVT_LOAD)
__attribute__ ((section ("SDRAMRW"))) 
#endif /*#if defined(SPI_DVT_LOAD) */
    gpio_handle = DclGPIO_Open(DCL_GPIO,46);//SPI1_MISO
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_3,0);
    DclGPIO_Close(gpio_handle);
#elif defined(MT6256)|| defined(MT6255)
    //GPIO_ModeSetup(10, 1);
    gpio_handle = DclGPIO_Open(DCL_GPIO,3);//SPI_CS_N
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_1,0);
    DclGPIO_Close(gpio_handle);
    //GPIO_ModeSetup(11, 1);
    gpio_handle = DclGPIO_Open(DCL_GPIO,2);//SPI_SCK
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_1,0);
    DclGPIO_Close(gpio_handle);
    //GPIO_ModeSetup(12, 1);
    gpio_handle = DclGPIO_Open(DCL_GPIO,1);//SPI_MISO
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_1,0);
    DclGPIO_Close(gpio_handle);
    //GPIO_ModeSetup(13, 1);
    gpio_handle = DclGPIO_Open(DCL_GPIO,0);//SPI_MOSI
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_1,0);
    DclGPIO_Close(gpio_handle);
#elif defined(MT6250)
   //for SPI0
    gpio_handle = DclGPIO_Open(DCL_GPIO,2);//SPI_CS_N
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_4,0);
    DclGPIO_Close(gpio_handle);

    gpio_handle = DclGPIO_Open(DCL_GPIO,1);//SPI_SCK
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_4,0);
    DclGPIO_Close(gpio_handle);

    gpio_handle = DclGPIO_Open(DCL_GPIO,0);//SPI_MOSI
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_4,0);
    DclGPIO_Close(gpio_handle);

    gpio_handle = DclGPIO_Open(DCL_GPIO,12);//SPI_MISO
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_4,0);
    DclGPIO_Close(gpio_handle);
    
    //for SPI 1

    gpio_handle = DclGPIO_Open(DCL_GPIO,22);//SPI1_CS_N
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_1,0);
    DclGPIO_Close(gpio_handle);

    gpio_handle = DclGPIO_Open(DCL_GPIO,20);//SPI1_SCK
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_1,0);
    DclGPIO_Close(gpio_handle);

    gpio_handle = DclGPIO_Open(DCL_GPIO,9);//SPI1_MOSI
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_2,0);
    DclGPIO_Close(gpio_handle);

    gpio_handle = DclGPIO_Open(DCL_GPIO,19);//SPI1_MISO
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_1,0);
    DclGPIO_Close(gpio_handle);

#elif defined(MT6280)
	
	gpio_handle = DclGPIO_Open(DCL_GPIO,61);//SPI_CS_N
	DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_2,0);
	DclGPIO_Close(gpio_handle);

	gpio_handle = DclGPIO_Open(DCL_GPIO,64);//SPI_SCK
	DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_2,0);
	DclGPIO_Close(gpio_handle);
	
	gpio_handle = DclGPIO_Open(DCL_GPIO,63);//SPI_MISO
	DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_2,0);
	DclGPIO_Close(gpio_handle);

	gpio_handle = DclGPIO_Open(DCL_GPIO,62);//SPI_MOSI
	DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_2,0);
	DclGPIO_Close(gpio_handle);
	
#else

  	#error;  // to  do  ,add  gpio  in  MT6280
#endif
    /* ========================================
    *         Critical section start
    * ======================================== */
    kal_take_sem(spi_sem_id, KAL_INFINITE_WAIT);
    if (KAL_TRUE == spi_is_used)
    {
        spi_error_code = SPI_ERROR_CODE_UNAVAILABLE;
        local_id = 0;
        result = KAL_FALSE;
    }
    else
    {
        spi_is_used = KAL_TRUE;
        /* Only one who get the ownership of the SPI interface
        * can set the 'spi_current_passport'. However, other
        * tasks could read this variable when one task is write
        * this variable, thus I have to protect this variable
        * through a semaphore, too.
        */
        local_id = rand();
        while (0 == local_id)
        {
            /* The passport can not be 0. */
            local_id = rand();
        }
        spi_current_passport = local_id;
        spi_error_code = SPI_NO_ERROR;
        result = KAL_TRUE;
    }
    kal_give_sem(spi_sem_id);
    /* ========================================
    *         Critical section end
    * ======================================== */
    /* copy owner filename */
    memset((void *)owner_filename, 0, FILENAME_BUF_SIZE);
    {
        kal_uint32 const str_len = strlen(filename);
        kal_uint32 copied_len = str_len;
        if (str_len >= FILENAME_BUF_SIZE)
        {
            copied_len = FILENAME_BUF_SIZE - 1;
        }
        memcpy((void *)owner_filename, filename, copied_len);
    }
    /* copy owner line no */
    owner_lineno = lineno;
    /* copy owner task id */
    owner_taskid = kal_get_current_thread_ID();
    /* return the key */
    (*id) = local_id;
    return result;
}
/* \brief Check to see if the SPI interface can be used.
 * 
 * This is an internal function.
 * 
 * \param id The return value of spi_open().
 * 
 * \return 
 * - KAL_TRUE if the SPI interface is available.
 * - KAL_FALSE if the SPI interface is unavailable.
 */
#if defined(SPI_DVT_LOAD)
__attribute__ ((section ("SDRAMCODE"))) 
#endif /*#if defined(SPI_DVT_LOAD) */
static kal_bool spi_can_be_used(kal_int32 const id)
{
    kal_bool result = KAL_TRUE;
    kal_take_sem(spi_sem_id, KAL_INFINITE_WAIT);
    if (KAL_FALSE == spi_is_used)
    {
        result = KAL_FALSE;
    }
    if (id != spi_current_passport)
    {
        result = KAL_FALSE;
    }
    kal_give_sem(spi_sem_id);
    return result;
}
#if defined(SPI_DVT_LOAD)
__attribute__ ((section ("SDRAMCODE"))) 
#endif /*#if defined(SPI_DVT_LOAD) */
kal_bool spi_wait_not_busy(kal_int32 const id)
{
     kal_uint32 volatile tmp=0;
    if (KAL_FALSE == spi_can_be_used(id))
    {
        spi_error_code = SPI_ERROR_CODE_UNAVAILABLE;
        return KAL_FALSE;
    }
    while (KAL_TRUE == spi_is_busy())
    {
    }
    {
        tmp|=0;
        tmp = SPI_STATUS1_REG;
    }
    return KAL_TRUE;
}
/* Caller should NOT call this function directly. */
#ifdef DRV_SPI_HAL
#if defined(SPI_DVT_LOAD)
__attribute__ ((section ("SDRAMCODE"))) 
#endif /*#if defined(SPI_DVT_LOAD) */
kal_bool spi_close_old(kal_int32 const id) 
#else
kal_bool spi_close(kal_int32 const id) 
#endif
{
	    #if defined(MT6268)
    DCL_HANDLE gpio_handle;
      #endif
    if (KAL_FALSE == spi_can_be_used(id))
    {
        spi_error_code = SPI_ERROR_CODE_UNAVAILABLE;
        return KAL_FALSE;
    }
    kal_take_sem(spi_sem_id, KAL_INFINITE_WAIT);
    spi_is_used = KAL_FALSE;
    kal_give_sem(spi_sem_id);
    spi_error_code = SPI_NO_ERROR;
#if defined(__MTK_TARGET__)
#if defined(MT6238) || defined(MT6239)
    *((kal_uint32 volatile *)DRVPDN_CON1_SET) |= 0x2000;
#elif defined(MT6268A) || defined(MT6268) || defined(MT6516)
#if defined(MT6268)
    // For 6268 GMC & SPI chip select bug.
    // ===================
    // before power down
    // ===================
    // set gpio_po[45] = 1
    //GPIO_WriteIO(KAL_TRUE, 45);  
    gpio_handle = DclGPIO_Open(DCL_GPIO,45);
    DclGPIO_Control(gpio_handle,GPIO_CMD_WRITE_HIGH,0);
    DclGPIO_Close(gpio_handle);
    // set gpio[45] as a output mode
    //GPIO_InitIO(OUTPUT, 45);
    gpio_handle = DclGPIO_Open(DCL_GPIO,45);
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_DIR_OUT,0);
    DclGPIO_Close(gpio_handle);
    // set gpio_mode[91:90] = 2'b00
    //GPIO_ModeSetup(45, 0);
#if defined(SPI_DVT_LOAD)
__attribute__ ((section ("SDRAMRW"))) 
#endif /*#if defined(SPI_DVT_LOAD) */
    gpio_handle = DclGPIO_Open(DCL_GPIO,45);
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_0,0);
    DclGPIO_Close(gpio_handle);
    
    // close the clock  
#endif
#if defined(__OLD_PDN_DEFINE__)
    DRV_Reg32(MMCG_SET0) = MMCG_CON0_SPI;
#else //__OLD_PDN_DEFINE__
    mm_disable_power(MMPWRMGR_SPI);
#endif //__OLD_PDN_DEFINE__
#elif defined(DRV_SPI_PDN_ON)
#if defined(__OLD_PDN_ARCH__) && defined(__OLD_PDN_DEFINE__)
#error
#else
     #if defined(DRV_SPI_SYS_PDN)
      PDN_SET(PDN_SPI);
   #else
    mm_disable_power(MMPWRMGR_SPI);
    #endif
#endif
#else
   #error;//to do  ,add  in the condition  MT6280
#endif
#endif
    return KAL_TRUE;
}
/** \brief Init the SPI driver.
 */
#if defined(SPI_DVT_LOAD)
__attribute__ ((section ("SDRAMCODE"))) 
#endif /*#if defined(SPI_DVT_LOAD) */
void spi_init(void)
{
    static kal_bool bSPI_init = KAL_FALSE;
   #if defined(MT6276)
    SW_SECVERSION sw_secversion;
   #endif
    
    if (bSPI_init == KAL_FALSE)
    {
        bSPI_init = KAL_TRUE;
        if (NULL == spi_sem_id)
        {
            spi_sem_id = kal_create_sem("SPI_SEM", 1);
        }
    
        {
            kal_uint32 const savedMask = SaveAndSetIRQMask();
            pause_cb = NULL;
            finish_cb = NULL;
            RestoreIRQMask(savedMask);
        }
    
        IRQ_Register_LISR(IRQ_SPI_CODE, SPI_LISR, "SPI");
    #if defined(SPI_MAUI_LOAD)
        DRV_Register_HISR(DRV_SPI_HISR_ID, SPI_HISR);
    #endif
    #if defined(MT6276)
        sw_secversion = INT_SW_SecVersion();
        if (sw_secversion == SW_SEC_0)
            spi_on_mt6276e2 = 1;
        else
            spi_on_mt6276e2 = 0;
        if (spi_on_mt6276e2)
            spi_event_id=kal_create_event_group("SPI_EVENT");
    #endif
        IRQSensitivity(IRQ_SPI_CODE, LEVEL_SENSITIVE);
        IRQUnmask(IRQ_SPI_CODE);
    }
}
/** \brief Set the callback function of the SPI interrupts.
 *
 * \param id The return value of spi_open().
 * \param type Possible values are:
 * - SPI_INT_PAUSE
 * - SPI_INT_FINISH
 * \param func The new callback function of the specified
 * SPI interrupt type. 
 * \param old Points to a variable where the old callback
 * function of the specified SPI interrupt type will be
 * saved.
 * \return
 * - KAL_TRUE if success.
 * - KAL_FALSE if failure, caller can use spi_get_error_code()
 * to examine what was wrong.
 */
#if defined(SPI_DVT_LOAD)
__attribute__ ((section ("SDRAMCODE"))) 
#endif /*#if defined(SPI_DVT_LOAD) */
kal_bool spi_set_cb(kal_int32 const id,
                    SPI_INT_TYPE const type,
                    spi_cb_func func,
                    spi_cb_func * const old)
{
    spi_cb_func local_old;
    if (KAL_FALSE == spi_can_be_used(id))
    {
        spi_error_code = SPI_ERROR_CODE_UNAVAILABLE;
        return KAL_FALSE;
    }
    switch (type)
    {
    case SPI_INT_PAUSE:
        {
            kal_uint32 const savedMask = SaveAndSetIRQMask();
            local_old = pause_cb;
            pause_cb = func;
            RestoreIRQMask(savedMask);
        }
        break;
    case SPI_INT_FINISH:
        {
            kal_uint32 const savedMask = SaveAndSetIRQMask();
            local_old = finish_cb;
            finish_cb = func;
            RestoreIRQMask(savedMask);
        }
        break;
    default:
        spi_error_code = SPI_ERROR_CODE_UNKNOWN_INT_TYPE;
        return KAL_FALSE;
    }
    if (old != NULL)
    {
        *old = local_old;
    }
    spi_error_code = SPI_NO_ERROR;
    return KAL_TRUE;
}
/** \brief Set the time intervals.
 *
 * Use this function to set the time intervals of SPI
 * interface. The time intervals include:
 * - Setup time
 * - Hold time
 * - Clock rate
 * - Idle time
 *
 * \param id The return value of spi_open().
 * \param type The kind of time intervals, possible values
 * are:
 * - SPI_TIME_SETUP
 * - SPI_TIME_HOLD
 * - SPI_TIME_IDLE
 * \param value The value to be used as the time interval
 * specified by the first parameter.
 * \return
 * - KAL_TRUE if success.
 * - KAL_FALSE if failure, caller can use spi_get_error_code()
 * to examine what was wrong.
 */
#if defined(SPI_DVT_LOAD)
__attribute__ ((section ("SDRAMCODE"))) 
#endif /*#if defined(SPI_DVT_LOAD) */
kal_bool spi_set_time_interval(kal_int32 const id,
                               SPI_TIME_TYPE const type,
                               kal_uint8 const value)
{
    kal_uint8 bit_pos;
    if (KAL_FALSE == spi_can_be_used(id))
    {
        spi_error_code = SPI_ERROR_CODE_UNAVAILABLE;
        return KAL_FALSE;
    }
    switch (type)
    {
    case SPI_TIME_SETUP: bit_pos = 24; goto set_conf0;
    case SPI_TIME_HOLD:  bit_pos = 16; goto set_conf0;
    case SPI_TIME_LOW:   bit_pos = 8;  goto set_conf0;
    case SPI_TIME_HIGH:  bit_pos = 0;  goto set_conf0;
    case SPI_TIME_IDLE:  bit_pos = 0;  goto set_conf1;
    default:
        spi_error_code = SPI_ERROR_CODE_UNKNOWN_TIME_TYPE;
        return KAL_FALSE;
    }
set_conf0:
    SPI_CONF0_REG &= (~(0xFF << bit_pos));
    SPI_CONF0_REG |= (value << bit_pos);
    goto done;
set_conf1:
    SPI_CONF1_REG &= (~(0xFF << 0));
    SPI_CONF1_REG |= (value << 0);
done:
    spi_error_code = SPI_NO_ERROR;
    return KAL_TRUE;
}
/** \brief Enable/disable the interrupts which may generated
 * by the SPI devices.
 *
 * These 2 interrupts will be send by the SPI controller
 * when the transmission is finished (or paused if it is in
 * the pause mode). 
 * 
 * \param id The return value of spi_open().
 * \param type Possible values are:
 * - SPI_INT_PAUSE
 * - SPI_INT_FINISH
 * \param status Possible values are:
 * - SPI_ENABLE
 * - SPI_DISABLE
 * \return
 * - KAL_TRUE if success.
 * - KAL_FALSE if failure, caller can use spi_get_error_code()
 * to examine what was wrong.
 */
#if defined(SPI_DVT_LOAD)
__attribute__ ((section ("SDRAMCODE"))) 
#endif /*#if defined(SPI_DVT_LOAD) */
kal_bool spi_set_interrupt(kal_int32 const id,
                           SPI_INT_TYPE const type,
                           SPI_BIT_STATUS const status)
{
    kal_uint32 bit_pos;
    if (KAL_FALSE == spi_can_be_used(id))
    {
        spi_error_code = SPI_ERROR_CODE_UNAVAILABLE;
        return KAL_FALSE;
    }
    ASSERT(0 == SPI_DISABLE);
    ASSERT(1 == SPI_ENABLE);
    if ((status != SPI_ENABLE) && (status != SPI_DISABLE))
    {
        spi_error_code = SPI_ERROR_CODE_UNKNOWN_BIT_STATUS;
        return KAL_FALSE;
    }
    switch (type)
    {
    case SPI_INT_PAUSE:  bit_pos = SPI_COMM_BIT_PAUSE_IE;  break;
    case SPI_INT_FINISH: bit_pos = SPI_COMM_BIT_FINISH_IE; break;
    default:
        spi_error_code = SPI_ERROR_CODE_UNKNOWN_INT_TYPE;
        return KAL_FALSE;
    }
    CLEAR_SPI_COMM_REG(bit_pos);
    SET_SPI_COMM_REG(bit_pos, status);
    spi_error_code = SPI_NO_ERROR;
    return KAL_TRUE;
}
/** \brief Switch the MSB mode used by the SPI TX/RX
 * operation.
 *
 * \param id The return value of spi_open().
 * \param type Possible values are:
 * - SPI_TX
 * - SPI_RX
 * \param msb Possible values are:
 * - SPI_MSB
 * - SPI_LSB
 * \return
 * - KAL_TRUE if success.
 * - KAL_FALSE if failure, caller can use spi_get_error_code()
 * to examine what was wrong.
 */
#if defined(SPI_DVT_LOAD)
__attribute__ ((section ("SDRAMCODE"))) 
#endif /*#if defined(SPI_DVT_LOAD) */
kal_bool spi_set_msb(kal_int32 const id,
                     SPI_DIRECTION_TYPE const type,
                     SPI_MLSB const msb)
{
    kal_uint32 bit_pos;
    if (KAL_FALSE == spi_can_be_used(id))
    {
        spi_error_code = SPI_ERROR_CODE_UNAVAILABLE;
        return KAL_FALSE;
    }
    ASSERT(0 == SPI_LSB);
    ASSERT(1 == SPI_MSB);
    if ((msb != SPI_MSB) && (msb != SPI_LSB))
    {
        spi_error_code = SPI_ERROR_CODE_UNKNOWN_MSB_LSB_TYPE;
        return KAL_FALSE;
    }
    switch (type)
    {
    case SPI_TX: bit_pos = SPI_COMM_BIT_TX_MSBF; break;
    case SPI_RX: bit_pos = SPI_COMM_BIT_RX_MSBF; break;
    default:
        spi_error_code = SPI_ERROR_CODE_UNKNOWN_TRANSFER_DIRECTION;
        return KAL_FALSE;
    }
    CLEAR_SPI_COMM_REG(bit_pos);
    SET_SPI_COMM_REG(bit_pos, msb);
    spi_error_code = SPI_NO_ERROR;
    return KAL_TRUE;
}
#if defined(SPI_DVT_LOAD)
__attribute__ ((section ("SDRAMCODE"))) 
#endif /*#if defined(SPI_DVT_LOAD) */
kal_bool spi_set_endian_reverse(kal_int32 const id,
                                SPI_DIRECTION_TYPE const type,
                                kal_bool const reverse)
{
    kal_uint32 bit_pos;
    if (KAL_FALSE == spi_can_be_used(id))
    {
        spi_error_code = SPI_ERROR_CODE_UNAVAILABLE;
        return KAL_FALSE;
    }
    switch (type)
    {
    case SPI_TX: bit_pos = SPI_COMM_BIT_TX_ENDIAN; break;
    case SPI_RX: bit_pos = SPI_COMM_BIT_RX_ENDIAN; break;
    default:
        spi_error_code = SPI_ERROR_CODE_UNKNOWN_TRANSFER_DIRECTION;
        return KAL_FALSE;
    }
    CLEAR_SPI_COMM_REG(bit_pos);
    if (KAL_TRUE == reverse)
    {
        SET_SPI_COMM_REG(bit_pos, 1);
    }
    spi_error_code = SPI_NO_ERROR;
    return KAL_TRUE;
}
/** \brief Select mode.
 *
 * SPI controller will read/send data from/to the internal
 * FIFOs in the FIFO mode. On the other hands, it will
 * transfer the data between the memory and the internal
 * FIFOs in the DMA mode. That is to say, in the DMA mode,
 * SPI controller will mode data from memory to the TX FIFO
 * first, and then send the data from the TX FIFO. On the
 * other hands, SPI controller will receive data to the RX
 * FIFO first, and then mode the data from the RX FIFO to
 * the memory.
 *
 * \param id The return value of spi_open().
 * \param type Possible values are:
 * - SPI_TX
 * - SPI_RX
 * \param mode Possible values are:
 * - SPI_MODE_DMA
 * - SPI_MODE_FIFO
 * \return
 * - KAL_TRUE if success.
 * - KAL_FALSE if failure, caller can use spi_get_error_code()
 * to examine what was wrong.
 */
#if defined(SPI_DVT_LOAD)
__attribute__ ((section ("SDRAMCODE"))) 
#endif /*#if defined(SPI_DVT_LOAD) */
kal_bool spi_select_mode(kal_int32 const id,
                         SPI_DIRECTION_TYPE const type,
                         SPI_MODE const mode)
{
    kal_uint32 bit_pos;
    if (KAL_FALSE == spi_can_be_used(id))
    {
        spi_error_code = SPI_ERROR_CODE_UNAVAILABLE;
        return KAL_FALSE;
    }
    ASSERT(0 == SPI_MODE_FIFO);
    ASSERT(1 == SPI_MODE_DMA);
    if ((mode != SPI_MODE_DMA) && (mode != SPI_MODE_FIFO))
    {
        spi_error_code = SPI_ERROR_CODE_UNKNOWN_TRANSFER_TYPE;
        return KAL_FALSE;
    }
    switch (type)
    {
    case SPI_TX: bit_pos = SPI_COMM_BIT_TX_DMA_EN; break;
    case SPI_RX: bit_pos = SPI_COMM_BIT_RX_DMA_EN; break;
    default:
        spi_error_code = SPI_ERROR_CODE_UNKNOWN_TRANSFER_DIRECTION;
        return KAL_FALSE;
    }
    CLEAR_SPI_COMM_REG(bit_pos);
    SET_SPI_COMM_REG(bit_pos, mode);
    spi_error_code = SPI_NO_ERROR;
    return KAL_TRUE;
}
/** \brief Choose the clock polarities supported by the SPI
 * interface. 
 *
 * \param id The return value of spi_open().
 * \param cpol Possible values are:
 * - SPI_CPOL_0
 * - SPI_CPOL_1
 * \return
 * - KAL_TRUE if success.
 * - KAL_FALSE if failure, caller can use spi_get_error_code()
 * to examine what was wrong.
 */
#if defined(SPI_DVT_LOAD)
__attribute__ ((section ("SDRAMCODE"))) 
#endif /*#if defined(SPI_DVT_LOAD) */
kal_bool spi_set_clock_polarity(kal_int32 const id,
                                SPI_CPOL const cpol)
{
    if (KAL_FALSE == spi_can_be_used(id))
    {
        spi_error_code = SPI_ERROR_CODE_UNAVAILABLE;
        return KAL_FALSE;
    }
    ASSERT(0 == SPI_CPOL_0);
    ASSERT(1 == SPI_CPOL_1);
    if ((cpol != SPI_CPOL_0) && (cpol != SPI_CPOL_1)) 
    {
        spi_error_code = SPI_ERROR_CODE_UNKNOWN_CLK_POLARITY;
        return KAL_FALSE;
    }
    CLEAR_SPI_COMM_REG(SPI_COMM_BIT_CPOL);
    SET_SPI_COMM_REG(SPI_COMM_BIT_CPOL, cpol);

    spi_error_code = SPI_NO_ERROR;
    return KAL_TRUE;
}
/** \brief Choose the clock formats supported by the SPI
 * interface.
 *
 * \param id The return value of spi_open().
 * \param cpha Possible values are:
 * - SPI_CPHA_0
 * - SPI_CPHA_1
 * \return
 * - KAL_TRUE if success.
 * - KAL_FALSE if failure, caller can use spi_get_error_code()
 * to examine what was wrong.
 */
kal_bool spi_set_clock_format(kal_int32 const id,
                              SPI_CPHA const cpha)
{
    if (KAL_FALSE == spi_can_be_used(id))
    {
        spi_error_code = SPI_ERROR_CODE_UNAVAILABLE;
        return KAL_FALSE;
    }
    ASSERT(0 == SPI_CPHA_0);
    ASSERT(1 == SPI_CPHA_1);
    if ((cpha != SPI_CPHA_0) && (cpha != SPI_CPHA_1))
    {
        spi_error_code = SPI_ERROR_CODE_UNKNOWN_CLK_FORMAT;
        return KAL_FALSE;
    }
    CLEAR_SPI_COMM_REG(SPI_COMM_BIT_CPHA);
    SET_SPI_COMM_REG(SPI_COMM_BIT_CPHA, cpha);

    spi_error_code = SPI_NO_ERROR;
    return KAL_TRUE;
}
/** \brief Enable/disable the pause mode.
 *
 * In the normal mode, SPI controller will change the chip
 * select line from low to high when the transmission is
 * finished. However, in the pause mode, it will not change
 * the state of the chip select line when the transmission
 * is finished. 
 *
 * The first time to start the transmission when in pause
 * mode is to use "SPI activate", and the successive
 * transmissions have to be started by "SPI resume".
 *
 * The last time to "resume" a transmission, users have to
 * disable the pause mode, and then call "resume".
 *
 * \param id The return value of spi_open().
 * \param status Possible values are:
 * - KAL_TRUE
 * - KAL_FALSE
 * \return
 * - KAL_TRUE if success.
 * - KAL_FALSE if failure, caller can use spi_get_error_code()
 * to examine what was wrong.
 */
#if defined(SPI_DVT_LOAD)
__attribute__ ((section ("SDRAMCODE"))) 
#endif /*#if defined(SPI_DVT_LOAD) */
kal_bool spi_set_pause_mode(kal_int32 const id,
                            kal_bool const status)
{
 #if defined(MT6256)|| defined(MT6255)
  kal_uint32  tmp;
#endif
    if (KAL_FALSE == spi_can_be_used(id))
    {
        spi_error_code = SPI_ERROR_CODE_UNAVAILABLE;
        return KAL_FALSE;
    }
    ASSERT(0 == KAL_FALSE);
    ASSERT(1 == KAL_TRUE);
    CLEAR_SPI_COMM_REG(SPI_COMM_BIT_PAUSE_EN);
    SET_SPI_COMM_REG(SPI_COMM_BIT_PAUSE_EN, status);

    spi_error_code = SPI_NO_ERROR;
 #if defined(MT6256)|| defined(MT6255)
    tmp = SPI_RX_FIFO_REG;  // avoid apb bus lantency  bug
#endif

    return KAL_TRUE;
}
/** \brief Check if the pause mode is enabled.
 *
 * \return
 *  - KAL_TRUE if pause mode is enabled.
 *  - KAL_FALSE if pause mode is disabled.
 */
#if defined(SPI_DVT_LOAD)
__attribute__ ((section ("SDRAMCODE"))) 
#endif /*#if defined(SPI_DVT_LOAD) */
kal_bool spi_is_in_pause_mode(void)
{
    spi_error_code = SPI_NO_ERROR;
    if (SPI_COMM_REG & (1 << SPI_COMM_BIT_PAUSE_EN))
    {
        return KAL_TRUE;
    } 
    else
    {
        return KAL_FALSE;
    }
}
/** \brief Enable/disable the deassert mode.
 *
 * In the normal mode, the SPI controller doesn't change the
 * state of the chip select line during the transmission. On
 * the other hand, the SPI controller will change the state
 * of the chip select line from low to high between each
 * byte during the transmission.
 *
 * \param id The return value of spi_open().
 * \param status Possible values are:
 * - KAL_TRUE
 * - KAL_FALSE
 * \return
 * - KAL_TRUE if success.
 * - KAL_FALSE if failure, caller can use spi_get_error_code()
 * to examine what was wrong.
 */
#if defined(SPI_DVT_LOAD)
__attribute__ ((section ("SDRAMCODE"))) 
#endif /*#if defined(SPI_DVT_LOAD) */
kal_bool spi_set_deassert_mode(kal_int32 const id,
                               kal_bool const status)
{
    if (KAL_FALSE == spi_can_be_used(id))
    {
        spi_error_code = SPI_ERROR_CODE_UNAVAILABLE;
        return KAL_FALSE;
    }
    ASSERT(0 == KAL_FALSE);
    ASSERT(1 == KAL_TRUE);
    CLEAR_SPI_COMM_REG(SPI_COMM_BIT_CS_DEASSERT_EN);
    SET_SPI_COMM_REG(SPI_COMM_BIT_CS_DEASSERT_EN, status);

    spi_error_code = SPI_NO_ERROR;
    return KAL_TRUE;
}
/** \brief Set the desired size to transmit or receive.
 *
 * The max size for the DMA mode transmission is 64k bytes,
 * and the max size for the FIFO mode transmission is 32
 * bytes. 
 *
 * If you want to transmit data more than 64k bytes, you can
 * calculate two numbers, A and B, so that (A*B) < 64k <
 * (A*(B+1)), then setup the pkg_length and pkg_count fields of the
 * SPI controller using A and B, and using the "Pause" mode
 * to transmit the reminder (i.e. 64k - (A*B)).
 *
 * \param id The return value of spi_open().
 * \param pkg_length The desired packet length.
 * \param pkg_count The desired packet count.
 * \return
 * - KAL_TRUE if success.
 * - KAL_FALSE if failure, caller can use spi_get_error_code()
 * to examine what was wrong.
 */
#if defined(SPI_DVT_LOAD)
__attribute__ ((section ("SDRAMCODE"))) 
#endif /*#if defined(SPI_DVT_LOAD) */
kal_bool spi_set_desired_size(kal_int32 const id,
                              kal_uint32 const pkg_length,
                              kal_uint16 const pkg_count)
{
    if (KAL_FALSE == spi_can_be_used(id))
    {
        spi_error_code = SPI_ERROR_CODE_UNAVAILABLE;
        return KAL_FALSE;
    }
    /* The real size is calculated by:
    * ((PACKET_LENGTH + 1) * (PACKET_LOOP_CNT + 1))
    */
    if (pkg_length > SPI_INTERFACE_MAX_PKT_LENGTH_PER_TIMES)
    {
        spi_error_code = SPI_ERROR_CODE_PKT_LENGTH_TOO_LARGE;
        return KAL_FALSE;
    }
    if (pkg_count > SPI_INTERFACE_MAX_PKT_COUNT_PER_TIMES)
    {
        spi_error_code = SPI_ERROR_CODE_PKT_COUNT_TOO_LARGE;
        return KAL_FALSE;
    }
    if (0 == pkg_length)
    {
        spi_error_code = SPI_ERROR_CODE_PKT_LENGTH_CAN_NOT_BE_ZERO;
        return KAL_FALSE;
    }
    if (0 == pkg_count)
    {
        spi_error_code = SPI_ERROR_CODE_PKT_COUNT_CAN_NOT_BE_ZERO;
        return KAL_FALSE;
    }
    /* Set 'PACKET_LOOP_CNT' field. */
    SPI_CONF1_REG &= 0xFFFF00FF;
    SPI_CONF1_REG |= ((pkg_count - 1) << 8);
    /* Set 'PACKET_LENGTH' field. */
    SPI_CONF1_REG &= 0xF000FFFF;
    SPI_CONF1_REG |= ((pkg_length - 1) << 16);

    spi_error_code = SPI_NO_ERROR;
    return KAL_TRUE;
}
#if defined(SPI_DVT_LOAD)
__attribute__ ((section ("SDRAMCODE"))) 
#endif /*#if defined(SPI_DVT_LOAD) */
kal_bool spi_set_get_tick_mode(kal_int32 const id, SPI_GET_TICK_MODE const get_tick)
{
    if (KAL_FALSE == spi_can_be_used(id))
    {
        spi_error_code = SPI_ERROR_CODE_UNAVAILABLE;
        return KAL_FALSE;
    }
#if defined(MT6268) || defined(MT6236) || defined(MT6276)
    switch (get_tick)
    {
    case SPI_NO_GET_TICK_MODE:
        SPI_CONF1_REG &= 0x3FFFFFFF;
        break;
    case SPI_GET_TICK_MODE_DELAY_1:
        // SPI_CONF1_REG
        SPI_CONF1_REG &= 0x3FFFFFFF;
        SPI_CONF1_REG |= 0x40000000;
        break;
    case SPI_GET_TICK_MODE_DELAY_2:
        // SPI_CONF1_REG
        SPI_CONF1_REG &= 0x3FFFFFFF;
        SPI_CONF1_REG |= 0x80000000;
        break;
    default: ASSERT(0); break;
    }
#endif
    spi_error_code = SPI_NO_ERROR;
    return KAL_TRUE;
}
#if defined(SPI_DVT_LOAD)
__attribute__ ((section ("SDRAMCODE"))) 
#endif /*#if defined(SPI_DVT_LOAD) */
kal_bool spi_slow_down_gmc(kal_int32 const id,
                           kal_bool const slow_down_enable,
                           kal_bool const split_burst_enable,
                           kal_uint16 const slow_down_thresh)
{
    if (KAL_FALSE == spi_can_be_used(id))
    {
        spi_error_code = SPI_ERROR_CODE_UNAVAILABLE;
        return KAL_FALSE;
    }
#if defined(MT6236) || defined(MT6276)
    if (KAL_TRUE == slow_down_enable)
    {
        SPI_GMC_SLOW_DOWN_REG |= (1 << SPI_GMC_SLOW_DOWN_ENABLE);
    }
    else
    {
        SPI_GMC_SLOW_DOWN_REG &= ~(1 << SPI_GMC_SLOW_DOWN_ENABLE);
    }
    if (KAL_TRUE == split_burst_enable)
    {
        SPI_GMC_SLOW_DOWN_REG |= (1 << SPI_GMC_SPLIT_BURST_ENABLE);
    }
    else
    {
        SPI_GMC_SLOW_DOWN_REG &= ~(1 << SPI_GMC_SPLIT_BURST_ENABLE);
    }
    SPI_GMC_SLOW_DOWN_REG &= 0xFFFF;
    SPI_GMC_SLOW_DOWN_REG |= (slow_down_thresh << 16);
#endif

    spi_error_code = SPI_NO_ERROR;
    return KAL_TRUE;
}
#if defined(SPI_DVT_LOAD)
__attribute__ ((section ("SDRAMCODE"))) 
#endif /*#if defined(SPI_DVT_LOAD) */
kal_bool spi_set_ultra_high(kal_int32 const id,
                            kal_bool const ultra_high_enable,
                            kal_uint16 const ultra_high_thresh)
{
    if (KAL_FALSE == spi_can_be_used(id))
    {
        spi_error_code = SPI_ERROR_CODE_UNAVAILABLE;
        return KAL_FALSE;
    }
#if defined(MT6236) || defined(MT6276)
    if (KAL_TRUE == ultra_high_enable)
    {
        SPI_ULTRA_HIGH_PRIORITY_REG |= (1 << SPI_ULTRA_HIGH_ENABLE);
    }
    else
    {
        SPI_ULTRA_HIGH_PRIORITY_REG &= ~(1 << SPI_ULTRA_HIGH_ENABLE);
    }
    SPI_ULTRA_HIGH_PRIORITY_REG &= 0xFFFF;
    SPI_ULTRA_HIGH_PRIORITY_REG |= (ultra_high_thresh << 16);
#endif
    spi_error_code = SPI_NO_ERROR;
    return KAL_TRUE;
}
/** \brief Set the source address of the SPI TX operation or
 * the destination address of the SPI RX operation. 
 *
 * \warning The R/W addresses need to be 4-byte alignment.
 *
 * \param id The return value of spi_open().
 * \param type Possible values are:
 * - SPI_TX
 * - SPI_RX
 * \param addr The specified source/destination buffer
 * address.
 * \return
 * - KAL_TRUE if success.
 * - KAL_FALSE if failure, caller can use spi_get_error_code()
 * to examine what was wrong. Possible values are:
 *  - SPI_OK
 *  - SPI_ERROR_ADDR_NOT_4_ALIGN
 */
#if defined(SPI_DVT_LOAD)
__attribute__ ((section ("SDRAMCODE"))) 
#endif /*#if defined(SPI_DVT_LOAD) */
kal_bool spi_set_rwaddr(kal_int32 const id,
                        SPI_DIRECTION_TYPE const type,
                        void * const addr)
{
    if (KAL_FALSE == spi_can_be_used(id))
    {
        spi_error_code = SPI_ERROR_CODE_UNAVAILABLE;
        return KAL_FALSE;
    }
    if ((type != SPI_TX) && (type != SPI_RX))
    {
        spi_error_code = SPI_ERROR_CODE_UNKNOWN_TRANSFER_DIRECTION;
        return KAL_FALSE;
    }
    if (NULL == addr)
    {
        spi_error_code = SPI_ERROR_CODE_DMA_BUF_ADDR_CAT_NOT_BE_ZERO;
        return KAL_FALSE;
    }
    if (((kal_uint32)addr & 0x3) != 0)
    {
        spi_error_code = SPI_ERROR_CODE_ADDR_NOT_4_ALIGN;
        return KAL_FALSE;
    }
/*
    if ((((kal_uint32)addr & 0xF0000000) != 0x00000000) &&

        (((kal_uint32)addr & 0xF0000000) != 0x10000000) &&

        (((kal_uint32)addr & 0xF0000000) != 0x20000000) &&

        (((kal_uint32)addr & 0xF0000000) != 0x30000000))
    {
        // The memory region where SPI can access is dependent
        // on the GMC.
        ASSERT(0);
        return KAL_FALSE;
    }
*/
    if (SPI_TX == type)
    {
        SPI_TX_ADDR_REG = (kal_uint32)addr;
    }
    else
    {
        SPI_RX_ADDR_REG = (kal_uint32)addr; 
    }
    spi_error_code = SPI_NO_ERROR;

    return KAL_TRUE;
}
/** \brief Check if the SPI interface is busy.
 *
 * \return Possible values are:
 * - KAL_TRUE
 * - KAL_FALSE
 */
#if defined(SPI_DVT_LOAD)
__attribute__ ((section ("SDRAMCODE"))) 
#endif /*#if defined(SPI_DVT_LOAD) */
kal_bool spi_is_busy(void)
{
    kal_uint32 const status = SPI_STATUS2_REG;
    spi_error_code = SPI_NO_ERROR;
    if (status & SPI_STATUS2_BIT_BUSY)
    {
        return KAL_FALSE;
    }
    else
    {
        return KAL_TRUE;
    }
}
/** \brief Reset the SPI controller.
 *
 * Resetting the SPI controller will force it to change the
 * chip select line to high, (chip select line is active
 * low), and stop the clock. Normally, after resetting, you
 * should reconfigure the SPI controller.
 *
 * \param id The return value of spi_open().
 * \return
 * - KAL_TRUE if success.
 * - KAL_FALSE if failure, caller can use spi_get_error_code()
 * to examine what was wrong.
 */
#if defined(SPI_DVT_LOAD)
__attribute__ ((section ("SDRAMCODE"))) 
#endif /*#if defined(SPI_DVT_LOAD) */
kal_bool spi_reset(kal_int32 const id)
{
    if (KAL_FALSE == spi_can_be_used(id))
    {
        spi_error_code = SPI_ERROR_CODE_UNAVAILABLE;
        return KAL_FALSE;
    }
#if defined(MT6238) || defined(MT6239) || defined(MT6268A) || defined(MT6236) || defined(MT6516) || defined(MT6276)|| defined(MT6256)|| defined(MT6255) || defined(MT6250) || defined(MT6280)
  SET_SPI_COMM_REG(SPI_COMM_BIT_RESET, 1);
#elif defined(MT6268)
  SPI_COMM_REG = 0;
#else
#error;// to do  in MT6280
#endif
  
  spi_error_code = SPI_NO_ERROR;
  
  return KAL_TRUE;
}
/** \brief Resume the SPI interface.
 *
 * This operation is only useful if the state of the SPI
 * controller is in the pause mode, and at least one
 * activation operation has been issued.
 *
 * \param id The return value of spi_open().
 * \return
 * - KAL_TRUE if success.
 * - KAL_FALSE if failure, caller can use spi_get_error_code()
 * to examine what was wrong.
 */
#if defined(SPI_DVT_LOAD)
__attribute__ ((section ("SDRAMCODE"))) 
#endif /*#if defined(SPI_DVT_LOAD) */
kal_bool spi_resume(kal_int32 const id)
{
  #if defined(MT6256)|| defined(MT6255)
 kal_uint32  tmp;
#endif
    if (KAL_FALSE == spi_can_be_used(id))
    {
        spi_error_code = SPI_ERROR_CODE_UNAVAILABLE;
        return KAL_FALSE;
    }
#if defined(MT6238) || defined(MT6239) || defined(MT6268A) || defined(MT6236) || defined(MT6516) || defined(MT6276)|| defined(MT6256)|| defined(MT6255) || defined(MT6250) || defined(MT6280)
    SPI_COMM_REG |= (1 << SPI_COMM_BIT_RESUME);
#elif defined(MT6268)
    SPI_COMM_REG |= ((1 << SPI_COMM_BIT_RESUME) | (1 << SPI_COMM_BIT_RESET));
#else
  #error;//to  do  in MT6280
#endif

    spi_error_code = SPI_NO_ERROR;
#if defined(MT6256)|| defined(MT6255)
    tmp = SPI_RX_FIFO_REG;
#endif

    return KAL_TRUE;
}
/** \brief Activate the SPI operation.
 *
 * Start the SPI clock to start its transmission.
 *
 * \param id The return value of spi_open().
 * \return
 * - KAL_TRUE if success.
 * - KAL_FALSE if failure, caller can use spi_get_error_code()
 * to examine what was wrong.
 */
#if defined(SPI_DVT_LOAD)
__attribute__ ((section ("SDRAMCODE"))) 
#endif /*#if defined(SPI_DVT_LOAD) */
kal_bool spi_activate(kal_int32 const id)
{
 #if defined(MT6256)|| defined(MT6255)	
kal_uint32 tmp;
#endif

    if (KAL_FALSE == spi_can_be_used(id))
    {
        spi_error_code = SPI_ERROR_CODE_UNAVAILABLE;
        return KAL_FALSE;
    }
#if defined(MT6238) || defined(MT6239) || defined(MT6268A) || defined(MT6236) || defined(MT6516) || defined(MT6276)|| defined(MT6256)|| defined(MT6255)|| defined(MT6250) || defined(MT6280)
    SPI_COMM_REG |= (1 << SPI_COMM_BIT_ACT);
#elif defined(MT6268)

    SPI_COMM_REG |= ((1 << SPI_COMM_BIT_ACT) | (1 << SPI_COMM_BIT_RESET));
#else
#error;// to  do  in MT6280
#endif
    spi_error_code = SPI_NO_ERROR;
 #if defined(MT6256)|| defined(MT6255)
 tmp = SPI_RX_FIFO_REG;
#endif

    return KAL_TRUE;
}
/** \brief Clear the SPI internal FIFO.
 *
 * This function will clear the SPI FIFO.
 *
 * \param id The return value of spi_open().
 * \param direction Possible values are:
 *  - SPI_TX
 *  - SPI_RX
 * \return
 * - KAL_TRUE if success.
 * - KAL_FALSE if failure, caller can use spi_get_error_code()
 * to examine what was wrong.
 */
kal_bool spi_clear_fifo(kal_int32 const id,
                        SPI_DIRECTION_TYPE const direction)
{
    int i;
    kal_uint32 volatile tmp=0;
    if (KAL_FALSE == spi_can_be_used(id))
    {
        spi_error_code = SPI_ERROR_CODE_UNAVAILABLE;
        return KAL_FALSE;
    }
    for (i = 0; i < (SPI_FIFO_SIZE / 4); ++i)
    {
        switch (direction)
        {
        case SPI_TX:
            SPI_TX_FIFO_REG = 0x0;
            break;
        case SPI_RX:
            tmp|=0;
            tmp = SPI_RX_FIFO_REG;
             break;
           
         
        default:
            spi_error_code = SPI_ERROR_CODE_UNKNOWN_TRANSFER_DIRECTION;
            return KAL_FALSE;
        }
    }

    spi_error_code = SPI_NO_ERROR;
    return KAL_TRUE;
}
/** \brief Push data into the SPI fifo.
 *
 * \param id The return value of spi_open().
 * \param data The data push into the fifo.
 * \return
 * - KAL_TRUE if success.
 * - KAL_FALSE if failure, caller can use spi_get_error_code()
 * to examine what was wrong.
 */
kal_bool spi_fifo_push(kal_int32 const id,
                       kal_uint32 const data)
{
    if (KAL_FALSE == spi_can_be_used(id))
    {
        spi_error_code = SPI_ERROR_CODE_UNAVAILABLE;
        return KAL_FALSE;
    }
    SPI_TX_FIFO_REG = data;
    spi_error_code = SPI_NO_ERROR;
    return KAL_TRUE;
}
/** \brief Pop data from the SPI fifo.
 *
 * \param id The return value of spi_open().
 * \param data If not NULL, it points to the memory space
 * which is stored the data poped from the fifo.
 * \return
 * - KAL_TRUE if success.
 * - KAL_FALSE if failure, caller can use spi_get_error_code()
 * to examine what was wrong.
 */
kal_bool spi_fifo_pop(kal_int32 const id,
                      kal_uint32 * const data)
{
    if (KAL_FALSE == spi_can_be_used(id))
    {
        spi_error_code = SPI_ERROR_CODE_UNAVAILABLE;
        return KAL_FALSE;
    }
    if (data != NULL)
    {
        *data = SPI_RX_FIFO_REG;
    }
    spi_error_code = SPI_NO_ERROR;
    return KAL_TRUE;
}
/** \brief Use this function to setup the SPI controller.
 *
 * \param id The return value of spi_open().
 * \param attr Specify the attributes of the SPI
 * controller.
 * \return
 * - KAL_TRUE if success.
 * - KAL_FALSE if failure, caller can use spi_get_error_code()
 * to examine what was wrong.
 */
#if defined(SPI_DVT_LOAD)
__attribute__ ((section ("SDRAMCODE"))) 
#endif /*#if defined(SPI_DVT_LOAD) */
kal_bool spi_config(kal_int32 const id,
                    spi_attr_t * const attr)
{
    if (KAL_FALSE == spi_can_be_used(id))
    {
        spi_error_code = SPI_ERROR_CODE_UNAVAILABLE;
        return KAL_FALSE;
    }
    if (NULL == attr)
    {
        spi_error_code = SPI_ERROR_CODE_CONFIG_ATTR_CAN_NOT_BE_ZERO;
        return KAL_FALSE;
    }
    SPI_CONF0_REG = 0;
    SPI_CONF1_REG = 0;
    SPI_TX_ADDR_REG = 0;
    SPI_RX_ADDR_REG = 0;
#if defined(MT6238) || defined(MT6239) || defined(MT6268A) || defined(MT6236) || defined(MT6516) || defined(MT6276)|| defined(MT6256)|| defined(MT6255) || defined(MT6250) || defined(MT6280)
    SPI_COMM_REG = 0;
#elif defined(MT6268)
    SPI_COMM_REG = (1 << SPI_COMM_BIT_RESET);
#else
#error;  //to  do  in  mt6280
#endif
    spi_set_time_interval(id, SPI_TIME_HOLD, attr->hold_time);
    spi_set_time_interval(id, SPI_TIME_SETUP, attr->setup_time);
    spi_set_time_interval(id, SPI_TIME_LOW, attr->clk_low);
    spi_set_time_interval(id, SPI_TIME_HIGH, attr->clk_high);
    spi_set_time_interval(id, SPI_TIME_IDLE, attr->idle_time);
    spi_set_interrupt(id, SPI_INT_PAUSE, attr->enable_pause_int);
    spi_set_interrupt(id, SPI_INT_FINISH, attr->enable_finish_int);
    spi_set_msb(id, SPI_TX, attr->tx_mlsb);
    spi_set_msb(id, SPI_RX, attr->rx_mlsb);
    spi_set_clock_polarity(id, attr->clk_polarity);
    spi_set_clock_format(id, attr->clk_fmt);
    spi_set_pause_mode(id, attr->enable_pause_mode);
    spi_set_deassert_mode(id, attr->enable_deassert_mode);
    spi_select_mode(id, SPI_TX, attr->tx_mode);
    spi_select_mode(id, SPI_RX, attr->rx_mode);
    spi_set_get_tick_mode(id, attr->get_tick);
    spi_set_ultra_high(id, attr->enable_ultra_high, attr->ultra_high_thresh);
    spi_slow_down_gmc(id, attr->enable_gmc_slow_down, attr->enable_gmc_split_burst, attr->gmc_slow_down_thresh);
    spi_error_code = SPI_NO_ERROR;
    return KAL_TRUE;
}
#ifdef DRV_SPI_HAL
#if defined(SPI_DVT_LOAD)
__attribute__ ((section ("SDRAMCODE"))) 
#endif /*#if defined(SPI_DVT_LOAD) */
kal_bool spi_set_driving_current(kal_bool bEnableSlewRate, kal_uint32 current)
{
#if defined(__MTK_TARGET__)
#if defined(MT6238) || defined(MT6239)
    return KAL_FALSE;
#elif defined(MT6268A) || defined(MT6268) || defined(MT6516)
    ASSERT(current < 4);
    *(kal_uint32 volatile *) ((CONFIG_base) + 0x7014) &= 0xFFF8;
    *(kal_uint32 volatile *) ((CONFIG_base) + 0x7014) |= current;
    if (bEnableSlewRate)
        *(kal_uint32 volatile *) ((CONFIG_base) + 0x7014) |= 0x4;
    return KAL_TRUE;
#elif defined(MT6236)
    ASSERT(current < 8);
    *(kal_uint32 volatile *) ((CONFIG_base) + 0x0504) &= 0xFFE1FFFF;
    *(kal_uint32 volatile *) ((CONFIG_base) + 0x0504) |= (current<<17)&0xE0000;
    if (bEnableSlewRate)
        *(kal_uint32 volatile *) ((CONFIG_base) + 0x0504) |= 0x100000;
    return KAL_TRUE;
#elif defined(MT6276)
    return KAL_FALSE;
#else
    return KAL_FALSE;
#endif
#endif
}
#if defined(SPI_DVT_LOAD)
__attribute__ ((section ("SDRAMCODE"))) 
#endif /*#if defined(SPI_DVT_LOAD) */
kal_bool spi_get_driving_current(kal_bool* bEnableSlewRate, kal_uint32* current)
{
#if defined(__MTK_TARGET__)
#if defined(MT6238) || defined(MT6239)
    return KAL_FALSE;
#elif defined(MT6268A) || defined(MT6268)
    *current = *(kal_uint32 volatile *) ((CONFIG_base) + 0x7014) & 0x3;
    if ((*(kal_uint32 volatile *) ((CONFIG_base) + 0x7014)) & 0x4)
        *bEnableSlewRate = KAL_TRUE;
    else
        *bEnableSlewRate = KAL_FALSE;
    return KAL_TRUE;
#elif defined(MT6236)
    *current = ((*(kal_uint32 volatile *) ((CONFIG_base) + 0x0504)) & 0xE0000) >> 17;
    if ((*(kal_uint32 volatile *) ((CONFIG_base) + 0x0504)) & 0x100000)
        *bEnableSlewRate = KAL_TRUE;
    else
        *bEnableSlewRate = KAL_FALSE;
    return KAL_TRUE;
#elif defined(MT6276)
    return KAL_FALSE;
#else
    return KAL_FALSE;
#endif
#endif
}
#if defined(SPI_DVT_LOAD)
__attribute__ ((section ("SDRAMCODE"))) 
#endif /*#if defined(SPI_DVT_LOAD) */
void spi_select_port(kal_uint32 port)
{
    // Select port is supported only on MT6276 E2 and later chips.
#if defined(MT6280)

SPI_PAD_MACRO_PDN_REG |=(1<<15);  //PDN_CLR  15 BIT 
#endif

#if defined(DRV_SPI_PAD_MACRO_SELECT)
    SPI_PAD_MACRO_SELECT_REG &= 0;
    SPI_PAD_MACRO_SELECT_REG |= port;
#endif
}
#endif


/** @} */
#endif
