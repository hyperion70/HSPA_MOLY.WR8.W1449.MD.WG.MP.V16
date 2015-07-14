#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "hif_hal.h"
#include "hif_v2_internal.h"
#include "kal_general_types.h"
#include "reg_base.h"
#include "dcl.h"
#include "dma_sw.h"
#include "us_timer.h"

#if defined(__NAND_FLASH_HARDWARE_TEST__)&& defined(__MAUI_BASIC__)
#if defined(MT6280)

#define HIF_BUFFER_SIZE       (4*1024)
#define HIF_TEST_SIZE         (2*1024)

#if defined(MT6280) 
#define LPCE1B_GPIO_pin		  (27)  
#define LPCE0B_GPIO_pin		  (26)  
#define HIF_NFI_IOCON       		((volatile unsigned int*)(NFI_base+0x0094))
#define HIF_NLI_ARB_SHRPIN_CON      ((volatile unsigned int*)(NLI_ARB_base+0x0020))
#define NFI_TEST_HIF_PORT 1
#define DMA2_HIF0    0x4 
#endif


#if defined(__ARMCC_VERSION)
#pragma arm section rwdata = "NONCACHEDRW", zidata = "NONCACHEDZI"
__align(16) char hif0_tx_buffer[HIF_BUFFER_SIZE]; // 4K
#pragma arm section rwdata, zidata
#elif defined(__GNUC__)
__attribute__((section("NONCACHEDZI"))) char hif0_tx_buffer[HIF_BUFFER_SIZE];
__attribute__((align(16))) char hif0_tx_buffer[HIF_BUFFER_SIZE] ;
#endif


HIF_HANDLE hif0_handle = 0;
static kal_bool icnt = KAL_TRUE;
static kal_bool hif_int_flag = KAL_FALSE;
static kal_bool hif_stop_flag = KAL_FALSE;
kal_bool dma_flag;

void hif0_cb(void);
void hif_test_stop(void);

kal_uint32 hif_engine_id(HIF_HANDLE handle)
{
    HIF_INTERNAL_HANDLE_T* pHandle = (HIF_INTERNAL_HANDLE_T*) handle;
    return (pHandle->engine_id);
}

void hif_test_write(unsigned int size)
{
    hif_int_flag = KAL_FALSE;
    hif_write(hif0_handle, HIF_TYPE_A0H_DMA, (kal_uint32) (hif0_tx_buffer), size, hif0_cb);
}

void hif_test_read(unsigned int size)
{
    hif_int_flag = KAL_TRUE;
    hif_read(hif0_handle, HIF_TYPE_A0L_DMA, (kal_uint32) (hif0_tx_buffer), size, hif0_cb);
}

void hif0_cb(void)
{
    if(hif_int_flag == KAL_FALSE)
    {
        hif_test_read(HIF_TEST_SIZE);
    }
    else
    {
        hif_test_write(HIF_TEST_SIZE);
    }  

}

void hif_test_init(void)
{
    HIF_CONFIG_T ConfigParam;
    kal_uint32 save_irq_mask;
    DCL_HANDLE gpio_handle;
    HIF_REALTIME_CALLBACK_T realtimeCB;
    
    gpio_handle = DclGPIO_Open(DCL_GPIO,LPCE0B_GPIO_pin);  //set LPCE0B mode
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_4, 0);
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_DIR_OUT, 0);
    DclGPIO_Close(gpio_handle);
    
    gpio_handle = DclGPIO_Open(DCL_GPIO,LPCE1B_GPIO_pin);  //set LPCE1B mode 
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_4, 0);
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_DIR_OUT, 0);
    DclGPIO_Close(gpio_handle);
    
    save_irq_mask = SaveAndSetIRQMask();
#if defined(MT6280)
    *HIF_NFI_IOCON |= 0x08; //NFI share control pin enable.
    *HIF_NFI_IOCON = ((*HIF_NFI_IOCON)&0x000f)|0x10; //NFI burst length 1 byte 
    *HIF_NLI_ARB_SHRPIN_CON |= 0x0D; //NREB/LRDB, NWEB/LWRB and NALE/LPA0 pin share.
#endif	
    RestoreIRQMask(save_irq_mask);
	
    hif0_handle = hif_open(NFI_TEST_HIF_PORT);
    ASSERT(hif0_handle);

    hif_power_ctrl(hif0_handle, KAL_TRUE);  
#if defined(MT6280)    
    ConfigParam.hif_base_clk =  80;
    ConfigParam.hif_time_c2ws =0x4;
    ConfigParam.hif_time_c2wh =3;
    ConfigParam.hif_time_wst = 0x18;
    ConfigParam.hif_time_chw = 0xA;
    ConfigParam.hif_time_c2rs =0x4;
    ConfigParam.hif_time_c2rh =0x4;
    ConfigParam.hif_time_rlt = 0x18;
    ConfigParam.hif_bus_width = 16;
#endif      
    hif_config(hif0_handle, &ConfigParam);
    realtimeCB.realtime_callback_en = KAL_TRUE;
	hif_ioctl(hif0_handle,HIF_IOCTL_REALTIME_CALLBACK,&realtimeCB);

}

void hif_test_start(void)
{
    hif_stop_flag = KAL_FALSE;
    if(icnt == KAL_TRUE)
    {
        hif_test_init();
        icnt = KAL_FALSE;
        hif_int_flag = KAL_TRUE;
            
        dma_flag = DMA2_CheckRunStat(DMA2_HIF0);
        if(dma_flag)
        {    
            dbg_print("%s", "HIF DMA didn't stop");
            ASSERT(0);
        }
    
        hif_test_write(HIF_TEST_SIZE);
    }
    
}

void hif_test_stop(void)
{
    hif_stop_flag = KAL_TRUE;
    
    DISABLE_HIF_INTR(hif_engine_id(hif0_handle));
    (*(volatile kal_uint32*)HIF_INTSTA_REG(hif_engine_id(hif0_handle))) = 0;//hif int status,write 0 clear
    hif_wait_for_idle(hif_engine_id(hif0_handle));
    DMA_Stop(DMA_HIF0);
    hif_power_ctrl(hif0_handle, KAL_FALSE);
    hif_close(hif0_handle);
    icnt = KAL_TRUE;
    dma_flag = 0;
}

#endif //if defined(MT6280)
#endif //if defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__)