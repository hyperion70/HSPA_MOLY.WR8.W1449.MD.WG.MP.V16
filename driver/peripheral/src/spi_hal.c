#include "spi_hal.h"
#include "spi.h"
#include "spi_internal.h"
#include "drv_features.h"
#include "spi_define.h"
#include "cache_sw.h"

//////////////////RHR ADD//////////////////////////
#include "kal_public_defs.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "string.h"
///////////////////////////////////////////////////
//#pragma O0

//////////////////RHR-REMOVE//////////////////////
//#include "kal_release.h"
//#include "spi_internal.h"
//#include "spi_define.h"
//////////////////////////////////////////////////

#if defined(DRV_SPI_SUPPORT) && defined(DRV_SPI_HAL)

//#define INTERAL_SYSRAM_MAX_SIZE_FOR_SPI (0x800)

#if defined(MT6276)
#include "mm_intmem.h"
kal_uint32 spi_buffer_in_sysram;
kal_uint32 size_insysram;
extern volatile kal_uint32 spi_on_mt6276e2;

SPI_RESULT spi_read_wa_for_GMC(SPI_HANDLE handle, void* pBuffer,kal_uint32 length, kal_uint32 count,SPI_CALLBACK fCB);
SPI_RESULT spi_write_wa_for_GMC(SPI_HANDLE handle, void* pBuffer,kal_uint32 length, kal_uint32 count,SPI_CALLBACK fCB);
SPI_RESULT spi_readwrite_wa_for_GMC(SPI_HANDLE handle, unsigned char *pOutBuffer,unsigned char *pInBuffer, kal_uint32 length, kal_uint32 count,SPI_CALLBACK fCB);

#endif 

typedef struct
{
    kal_uint32 id;
    kal_uint32 port;
    kal_taskid owner;
    SPI_CONFIG_PARAM_T config;
} SPI_INTERNAL_HANDLE_T;

struct
{
    kal_uint32 pause_mode_count;
    kal_bool   deassert_mode;
    kal_bool   pause_mode;
    kal_bool   ultra_high_mode;
    kal_uint32 ultra_high_thresh;
    kal_bool   slow_down_mode;
    kal_bool   split_burst_enable;
    kal_uint32 slow_down_thresh;
    kal_uint32 get_tick_mode;
} spi_internal_state ;

SPI_INTERNAL_HANDLE_T spi_internal_handle[SPI_MAX_PORT_NUM];
extern volatile kal_semid spi_sem_id;

SPI_HANDLE spi_open(kal_uint32 port)
{
    kal_int32 local_id;
    kal_bool result;
    #if defined(MT6276)
    if (spi_on_mt6276e2)
    {
        result = mm_intmem_get(MM_SCEN__ISDBT, MM_INTMEM_SEG__ISDBT, &spi_buffer_in_sysram, &size_insysram);
        if (result == KAL_FALSE)
        {
        ASSERT(0);
        }
    }
    #endif 
    result = SPI_OPEN(&local_id);

    if (result == KAL_TRUE)
    {
        kal_take_sem(spi_sem_id, KAL_INFINITE_WAIT);
        ASSERT(port < SPI_MAX_PORT_NUM);
        ASSERT(spi_internal_handle[port].id == NULL);
        spi_internal_handle[port].id = local_id;
        spi_internal_handle[port].port = port;
        spi_internal_handle[port].owner = kal_get_current_thread_ID();
        spi_select_port(port);
        kal_give_sem(spi_sem_id);

        return (SPI_HANDLE)(&spi_internal_handle[port]);
    }
    else
        return (SPI_HANDLE) 0;
}

SPI_RESULT spi_close(SPI_HANDLE handle)
{
    SPI_RESULT result=SPI_RESULT_OK;
    SPI_INTERNAL_HANDLE_T* pHandle = (SPI_INTERNAL_HANDLE_T*) handle;
    ASSERT(pHandle);
    #if defined(MT6276)
      if (spi_on_mt6276e2)
      {
          result = mm_intmem_free(MM_SCEN__ISDBT, MM_INTMEM_SEG__ISDBT);
          if (result == KAL_FALSE)
          {
          ASSERT(0);
          }
      }
    #endif 
   
    result = SPI_CLOSE(pHandle->id);
    memset(pHandle, 0, sizeof(SPI_INTERNAL_HANDLE_T));
    if (result == KAL_TRUE)
        return SPI_RESULT_OK;
    else
        return SPI_RESULT_ERROR;
}

SPI_RESULT spi_configure(SPI_HANDLE handle, SPI_CONFIG_PARAM_T* pConfigParam)
{
    spi_attr_t spi_attr;
    SPI_RESULT result=SPI_RESULT_OK;
    SPI_INTERNAL_HANDLE_T* pHandle = (SPI_INTERNAL_HANDLE_T*) handle;
    ASSERT(pHandle);
    pHandle->config = *pConfigParam;
    memset(&spi_attr, 0, sizeof(spi_attr_t));
    spi_attr.setup_time = (kal_uint8) pHandle->config.cs_setup_time;
    spi_attr.hold_time = (kal_uint8) pHandle->config.cs_hold_time;
    spi_attr.clk_low = (kal_uint8) pHandle->config.clk_low_time;
    spi_attr.clk_high = (kal_uint8) pHandle->config.clk_high_time;
    spi_attr.idle_time = (kal_uint8) pHandle->config.cs_idle_time;
    spi_attr.tx_mlsb = pHandle->config.tx_msbf;
    spi_attr.rx_mlsb = pHandle->config.rx_msbf;
    spi_attr.clk_polarity = pHandle->config.clk_polarity;
    spi_attr.clk_fmt = pHandle->config.clk_fmt;
    spi_attr.get_tick = SPI_NO_GET_TICK_MODE;
    result = spi_config(pHandle->id, &spi_attr);
    if (pHandle->config.tx_endian == SPI_ENDIAN_LITTLE)
        result = (result && spi_set_endian_reverse(pHandle->id, SPI_TX, KAL_FALSE));
    else if (pHandle->config.tx_endian == SPI_ENDIAN_BIG)
        result = (result && spi_set_endian_reverse(pHandle->id, SPI_TX, KAL_TRUE));
    else
        result = KAL_FALSE;
    if (pHandle->config.rx_endian == SPI_ENDIAN_LITTLE)
        result = (result && spi_set_endian_reverse(pHandle->id, SPI_RX, KAL_FALSE));
    else if (pHandle->config.rx_endian == SPI_ENDIAN_BIG)
        result = (result && spi_set_endian_reverse(pHandle->id, SPI_RX, KAL_TRUE));
    else
        result = KAL_FALSE;
    if (result == KAL_FALSE)
        return SPI_RESULT_ERROR;
    else
        return SPI_RESULT_OK;
}

void spi_transfer_internal(SPI_INTERNAL_HANDLE_T* pHandle, SPI_CALLBACK fCB)
{
    kal_bool bInPauseMode;
    // Set interrupt and callback
    if (fCB)
    {
        spi_set_interrupt(pHandle->id, SPI_INT_PAUSE, SPI_ENABLE);
        spi_set_interrupt(pHandle->id, SPI_INT_FINISH, SPI_ENABLE);
        spi_set_cb(pHandle->id, SPI_INT_PAUSE, fCB, NULL);
        spi_set_cb(pHandle->id, SPI_INT_FINISH, fCB, NULL);
    }
    else
    {
        spi_set_interrupt(pHandle->id, SPI_INT_PAUSE, SPI_DISABLE);
        spi_set_interrupt(pHandle->id, SPI_INT_FINISH, SPI_DISABLE);
        spi_set_cb(pHandle->id, (SPI_INT_TYPE)NULL, fCB, NULL);
        spi_set_cb(pHandle->id, (SPI_INT_TYPE)NULL, fCB, NULL);
    }
    // Start SPI. Check pause mode count. If count > 0, use resume. If count = 0, use activate and disable pause mode.
    bInPauseMode = spi_is_in_pause_mode();
    if ((spi_internal_state.pause_mode_count > 0) && (spi_internal_state.pause_mode == KAL_TRUE) && (bInPauseMode == KAL_TRUE))
    {
        // Use resume
        spi_internal_state.pause_mode_count--;
        if (spi_internal_state.pause_mode_count == 0)
        {
            spi_internal_state.pause_mode = KAL_FALSE;
            spi_set_pause_mode(pHandle->id, KAL_FALSE);
        }
        spi_resume(pHandle->id);
    }
    else if (bInPauseMode == KAL_FALSE)
    {
        if ((spi_internal_state.pause_mode_count > 1) && (spi_internal_state.pause_mode == KAL_TRUE))
            spi_set_pause_mode(pHandle->id, KAL_TRUE);
        if (spi_internal_state.pause_mode_count > 0)
            spi_internal_state.pause_mode_count--;
        if (spi_internal_state.pause_mode_count == 0)
            spi_internal_state.pause_mode = KAL_FALSE;
        // Use activate
        spi_activate(pHandle->id);
    }
    else
        ASSERT(0);
    if (fCB == NULL)
        spi_wait_not_busy(pHandle->id);
}

SPI_RESULT spi_write(SPI_HANDLE handle, void* pBuffer, kal_uint32 length, kal_uint32 count, SPI_CALLBACK fCB)
{
    SPI_RESULT result=SPI_RESULT_OK;
    SPI_INTERNAL_HANDLE_T* pHandle = (SPI_INTERNAL_HANDLE_T*) handle;
    #if defined(MT6276)
    if (spi_on_mt6276e2)
    {
        result=spi_write_wa_for_GMC(handle, pBuffer,length, count,fCB);
        return result;
    }
    #endif
    ASSERT(pHandle);
    // Set addresses
    spi_set_rwaddr(pHandle->id, SPI_TX, pBuffer);
    // Set DMA mode and FIFO mode
    spi_select_mode(pHandle->id, SPI_TX, SPI_MODE_DMA);
    spi_select_mode(pHandle->id, SPI_RX, SPI_MODE_FIFO);
    spi_clear_fifo(pHandle->id, SPI_RX);
    // Set transfer size
    spi_set_desired_size(pHandle->id, length, (kal_uint16) count);
    #if defined(__MTK_TARGET__)
    #if defined(SPI_MAUI_LOAD)
      /* ensure non-cachable DMA address. */
      {
          if (INT_QueryIsNonCachedRAM(pBuffer, length * count) != 1)
          {
            //ASSERT(0);
            return SPI_RESULT_INVALID_ARGUMENT;
          }
      }
    #endif
    #endif

    // Transfer
    spi_transfer_internal(pHandle, fCB);
    
    return SPI_RESULT_OK;
}

SPI_RESULT spi_read(SPI_HANDLE handle, void* pBuffer, kal_uint32 length, kal_uint32 count, SPI_CALLBACK fCB)
{
    SPI_RESULT result=SPI_RESULT_OK;
    SPI_INTERNAL_HANDLE_T* pHandle = (SPI_INTERNAL_HANDLE_T*) handle;
    #if defined(MT6276)
    if (spi_on_mt6276e2)
    {
        result=spi_read_wa_for_GMC(handle, pBuffer,length, count,fCB);
        return result;
    }
    #endif

    ASSERT(pHandle);
    // Set addresses
    spi_set_rwaddr(pHandle->id, SPI_RX, pBuffer);
    // Set DMA mode and FIFO mode
    spi_select_mode(pHandle->id, SPI_RX, SPI_MODE_DMA);
    spi_select_mode(pHandle->id, SPI_TX, SPI_MODE_FIFO);
    spi_clear_fifo(pHandle->id, SPI_TX);
    // Set transfer size
    spi_set_desired_size(pHandle->id, length, (kal_uint16) count);
    #if defined(__MTK_TARGET__)
    #if defined(SPI_MAUI_LOAD)
      // ensure non-cachable DMA address. 
      {
          if (INT_QueryIsNonCachedRAM(pBuffer, length * count) != 1)
          {
            //ASSERT(0);
            return SPI_RESULT_INVALID_ARGUMENT;
          }
      }
    #endif
    #endif

    // Transfer
    spi_transfer_internal(pHandle, fCB);
    
    return SPI_RESULT_OK;
}

SPI_RESULT spi_readwrite(SPI_HANDLE handle, void* pOutBuffer, void* pInBuffer, kal_uint32 length, kal_uint32 count, SPI_CALLBACK fCB)
{
    SPI_RESULT result=SPI_RESULT_OK;
    SPI_INTERNAL_HANDLE_T* pHandle = (SPI_INTERNAL_HANDLE_T*) handle;
    #if defined(MT6276)
    if (spi_on_mt6276e2)
    {
        result=spi_readwrite_wa_for_GMC(handle,pOutBuffer,pInBuffer, length, count, fCB);
        return result;
    }
    #endif
    ASSERT(pHandle);
    // Set addresses
    spi_set_rwaddr(pHandle->id, SPI_TX, pOutBuffer);
    spi_set_rwaddr(pHandle->id, SPI_RX, pInBuffer);
    // Set DMA mode and FIFO mode
    spi_select_mode(pHandle->id, SPI_RX, SPI_MODE_DMA);
    spi_select_mode(pHandle->id, SPI_TX, SPI_MODE_DMA);
    // Set transfer size
    spi_set_desired_size(pHandle->id, length, (kal_uint16) count);
    #if defined(__MTK_TARGET__)
    #if defined(SPI_MAUI_LOAD)
      // ensure non-cachable DMA address. 
      {
          if ((INT_QueryIsNonCachedRAM(pOutBuffer, length * count) != 1)||(INT_QueryIsNonCachedRAM(pInBuffer, length * count) != 1))
          {
            //ASSERT(0);
            return SPI_RESULT_INVALID_ARGUMENT;
          }
      }
    #endif
    #endif
    
    // Transfer
    spi_transfer_internal(pHandle, fCB);
    
    return SPI_RESULT_OK;
}

SPI_RESULT spi_power_ctrl(SPI_HANDLE handle, kal_bool bPowerOn)
{
    return SPI_RESULT_OK;
}

SPI_RESULT spi_ioctl(SPI_HANDLE handle, SPI_IOCTL_CODE code, void* pParam)
{
    SPI_RESULT result = SPI_RESULT_OK;
    SPI_INTERNAL_HANDLE_T* pHandle = (SPI_INTERNAL_HANDLE_T*) handle;
    ASSERT(pHandle);
    switch (code)
    {
    case SPI_IOCTL_GET_PARAM:
        {
            SPI_CONFIG_PARAM_T* pConfigParam = (SPI_CONFIG_PARAM_T*) pParam;
            ASSERT(pConfigParam);
            *pConfigParam = pHandle->config;
        }
        break;
    case SPI_IOCTL_QUERY_CAPABILITY:
        {
            SPI_CAPABILITY_T* pCapabilityParam = (SPI_CAPABILITY_T*) pParam;
            ASSERT(pCapabilityParam);
            pCapabilityParam->cs_setup_time_min = 0;
            pCapabilityParam->cs_setup_time_max = 255;
            pCapabilityParam->cs_hold_time_min = 0;
            pCapabilityParam->cs_hold_time_max = 255;
            pCapabilityParam->cs_idle_time_min = 0;
            pCapabilityParam->cs_idle_time_max = 255;
            pCapabilityParam->clk_low_time_min = 0;
            pCapabilityParam->clk_low_time_max = 255;
            pCapabilityParam->clk_high_time_min = 0;
            pCapabilityParam->clk_high_time_max = 255;
            pCapabilityParam->transfer_length_min = 0;
            pCapabilityParam->transfer_count_min = 0;
            pCapabilityParam->transfer_length_max = 1024;
#if defined(MT6276)
            if (spi_on_mt6276e2)
                pCapabilityParam->transfer_count_max = 65535;
            else
                pCapabilityParam->transfer_count_max = 255;
#else
            pCapabilityParam->transfer_count_max = 255;
#endif
            pCapabilityParam->slow_down_thresh_min = 0;
            pCapabilityParam->slow_down_thresh_max = 65535;
            pCapabilityParam->ultra_high_thresh_min = 0;
            pCapabilityParam->ultra_high_thresh_max = 65535;
#if defined(MT6268A) || defined(MT6268)
            pCapabilityParam->driving_current_min = 0;
            pCapabilityParam->driving_current_max = 3;
#elif defined(MT6236)
            pCapabilityParam->driving_current_min = 0;
            pCapabilityParam->driving_current_max = 7;
#else
            pCapabilityParam->driving_current_min = 0;
            pCapabilityParam->driving_current_max = 0;
#endif
        }
        break;
    case SPI_IOCTL_QUERY_MODE_SUPPORT:
        {
            SPI_QUERY_MODE_T* pQueryMode = (SPI_QUERY_MODE_T*) pParam;
            ASSERT(pQueryMode);
            pQueryMode->bSupport = KAL_FALSE;
            switch (pQueryMode->mode)
            {
            #if defined(MT6238) || defined(MT6239)
                case SPI_MODE_DEASSERT:
                case SPI_MODE_PAUSE:
                    pQueryMode->bSupport = KAL_TRUE;
                    break;
            #elif defined(MT6268)
                case SPI_MODE_DEASSERT:
                case SPI_MODE_PAUSE:
                case SPI_MODE_GET_TICK:
                    pQueryMode->bSupport = KAL_TRUE;
                    break;
            #else  //if defined(MT6236) || defined(MT6256) || defined(MT6276)// MT6236 and later chips.
                case SPI_MODE_DEASSERT:
                case SPI_MODE_PAUSE:
                case SPI_MODE_GET_TICK:
                case SPI_MODE_ULTRA_HIGH:
                case SPI_MODE_SLOW_DOWN:
                    pQueryMode->bSupport = KAL_TRUE;
                    break;
            #endif
                default:
                    pQueryMode->bSupport = KAL_FALSE;
                    break;
            }
        }
        break;
    case SPI_IOCTL_QUERY_CLOCK:
        {
            SPI_QUERY_CLOCK_T* pQueryClock = (SPI_QUERY_CLOCK_T*) pParam;
            ASSERT(pQueryClock);
            #if defined(MT6238) || defined(MT6239)
            pQueryClock->clock = 104;
            #elif defined(MT6268)
            pQueryClock->clock = 123;
            #elif defined(MT6236)
            pQueryClock->clock = 104;
            #else
            #endif
        }
        break;
    case SPI_IOCTL_SET_MODE:
        {
            SPI_MODE_T* pSetMode = (SPI_MODE_T*) pParam;
            ASSERT(pSetMode);
            switch (pSetMode->mode)
            {
            case SPI_MODE_DEASSERT:
                // deassert mode is conflict with pause mode.
                if (pSetMode->bEnable)
                {
                    ASSERT(spi_internal_state.pause_mode == KAL_FALSE);
                    // Enable deassert mode.
                    spi_internal_state.deassert_mode = KAL_TRUE;
                    spi_set_deassert_mode(pHandle->id, KAL_TRUE);
                }
                else
                {
                    spi_set_deassert_mode(pHandle->id, KAL_FALSE);
                    spi_internal_state.deassert_mode = KAL_FALSE;
                }
                break;
            case SPI_MODE_PAUSE:
                // pause mode is conflict with deassert mode.
                if (pSetMode->bEnable)
                {
                    ASSERT(spi_internal_state.deassert_mode == KAL_FALSE);
                    spi_internal_state.pause_mode_count = pSetMode->Param;
                    spi_internal_state.pause_mode = KAL_TRUE;
                }
                else
                {
                    // Normally pause mode will be disabled automatically.
                    spi_internal_state.pause_mode_count = 1;
                }
                break;
            case SPI_MODE_GET_TICK:
                if (pSetMode->bEnable)
                {
                    spi_set_get_tick_mode(pHandle->id, SPI_NO_GET_TICK_MODE);
                    spi_internal_state.get_tick_mode = pSetMode->Param;
                    if (pSetMode->Param == SPI_GET_TICK_DELAY1)
                    {
                        spi_set_get_tick_mode(pHandle->id, SPI_GET_TICK_MODE_DELAY_1);
                    }
                    else if (pSetMode->Param == SPI_GET_TICK_DELAY2)
                    {
                        spi_set_get_tick_mode(pHandle->id, SPI_GET_TICK_MODE_DELAY_2);
                    }
                }
                else
                {
                    spi_set_get_tick_mode(pHandle->id, SPI_NO_GET_TICK_MODE);
                    spi_internal_state.get_tick_mode = 0;
                }
                break;
            case SPI_MODE_ULTRA_HIGH:
                if (pSetMode->bEnable)
                {
                    kal_uint32 thresh = pSetMode->Param;
                    ASSERT(thresh < 65536);
                    spi_set_ultra_high(pHandle->id, KAL_TRUE, (kal_uint16)thresh);
                    spi_internal_state.ultra_high_thresh = (kal_uint16)thresh;
                    spi_internal_state.ultra_high_mode = KAL_TRUE;
                }
                else
                {
                    spi_set_ultra_high(pHandle->id, KAL_FALSE, 0);
                    spi_internal_state.ultra_high_thresh = 0;
                    spi_internal_state.ultra_high_mode = KAL_FALSE;
                }
                break;
            case SPI_MODE_SLOW_DOWN:
                if (pSetMode->bEnable)
                {
                    SPI_SLOWDOWN_PARAM_T *pSlowdownParam = (SPI_SLOWDOWN_PARAM_T*) pSetMode->Param;
                    ASSERT(pSlowdownParam);
                    ASSERT(pSlowdownParam->slow_down_thresh < 65536);
                    spi_slow_down_gmc(pHandle->id, KAL_TRUE, pSlowdownParam->split_burst_enable, (kal_uint16)(pSlowdownParam->slow_down_thresh));
                    spi_internal_state.split_burst_enable = pSlowdownParam->split_burst_enable;
                    spi_internal_state.slow_down_thresh = pSlowdownParam->slow_down_thresh;
                    spi_internal_state.slow_down_mode = KAL_TRUE;
                }
                else
                {
                    spi_slow_down_gmc(pHandle->id, KAL_FALSE, KAL_FALSE, 0);
                    spi_internal_state.split_burst_enable = KAL_FALSE;
                    spi_internal_state.slow_down_thresh = 0;
                    spi_internal_state.slow_down_mode = KAL_FALSE;
                }
                break;
            default:
                ASSERT(0);
                break;
            }
        }
        break;
    case SPI_IOCTL_GET_MODE:
        {
            SPI_MODE_T *pGetMode = (SPI_MODE_T*) pParam;
            ASSERT(pGetMode);
            switch (pGetMode->mode)
            {
            case SPI_MODE_DEASSERT:
                pGetMode->bEnable = spi_internal_state.deassert_mode;
                pGetMode->Param = 0;
                break;
            case SPI_MODE_PAUSE:
                pGetMode->bEnable = spi_internal_state.pause_mode;
                pGetMode->Param = spi_internal_state.pause_mode_count;
                break;
            case SPI_MODE_GET_TICK:
                pGetMode->bEnable = (spi_internal_state.get_tick_mode != 0);
                pGetMode->Param = spi_internal_state.get_tick_mode;
                break;
            case SPI_MODE_ULTRA_HIGH:
                pGetMode->bEnable = spi_internal_state.ultra_high_mode;
                pGetMode->Param = spi_internal_state.ultra_high_thresh;
                break;
            case SPI_MODE_SLOW_DOWN:
                {
                    SPI_SLOWDOWN_PARAM_T *pSlowdownParam = (SPI_SLOWDOWN_PARAM_T*) pGetMode->Param;
                    ASSERT(pSlowdownParam);
                    pGetMode->bEnable = spi_internal_state.slow_down_mode;
                    pSlowdownParam->split_burst_enable = spi_internal_state.split_burst_enable;
                    pSlowdownParam->slow_down_thresh = spi_internal_state.slow_down_thresh;
                }
                break;
            default:
                ASSERT(0);
                break;
            }
        }
        break;
    case SPI_IOCTL_GET_DRIVING_CURRENT:
        {
            SPI_DRIVING_CURRENT_T *pDrivingCurrent = (SPI_DRIVING_CURRENT_T*) pParam;
            ASSERT(pDrivingCurrent);
            spi_get_driving_current(&(pDrivingCurrent->bEnableSlewRate), &(pDrivingCurrent->driving_current));
        }
        break;
    case SPI_IOCTL_SET_DRIVING_CURRENT:
        {
            SPI_DRIVING_CURRENT_T *pDrivingCurrent = (SPI_DRIVING_CURRENT_T*) pParam;
            ASSERT(pDrivingCurrent);
            spi_set_driving_current(pDrivingCurrent->bEnableSlewRate, pDrivingCurrent->driving_current);
        }
        break;
    default:
        ASSERT(0);
        break;
    }
    return result;
}

/** \brief  SPI workaround(spi_read_wa_for_GMC,spi_write_wa_for_GMC,spi_readwrite_wa_for_GMC),to support GMC 2.0.
 * if want to transfer data from external memory to external device,
 * <1>SPI would read data from EMI,
 * <2>write data to working buffer(internal SRAM),
 * <3>start SPI to transfer,with pause mode,
 * <4>after transfer,SPI state will be pause idle
 * <5>repeat step<1>~<2>,then resume SPI
 * the max size of DMA mode is 64K byte, ((PACKET_LENGTH + 1) * (PACKET_LOOP_CNT + 1))
 * pBuffer is the address in memory
 * \return The error code of the SPI interface
 */
#if defined(MT6276)

SPI_RESULT spi_read_wa_for_GMC(SPI_HANDLE handle, void* pBuffer,kal_uint32 length, kal_uint32 count,SPI_CALLBACK fCB)
{
    SPI_RESULT result=SPI_RESULT_OK;
    kal_int32 i;
    kal_uint32 event_group;
    kal_uint32 *base_addr_in=(kal_uint32 *)pBuffer;
    kal_uint32 *addr_insysram_for_RX=(kal_uint32 *)spi_buffer_in_sysram;  
    kal_uint32 transfer_amount = 0;
    kal_uint32 transfer_count = 0;
    kal_uint32 transfer_modulo = 0;
    kal_uint32 length_per_transfer=1024;
    SPI_INTERNAL_HANDLE_T* pHandle = (SPI_INTERNAL_HANDLE_T*) handle;

    if(count==1)
    {
      transfer_amount = length;
    }
    else if(count>1)
    {
      transfer_amount = length*count;
    }
    else
    {
      return SPI_RESULT_INVALID_ARGUMENT;
    }
    transfer_count = (transfer_amount-1) / 1024+1;
    transfer_modulo = transfer_amount % 1024; 
    ASSERT(pHandle);
    // Set DMA mode and FIFO mode
    spi_select_mode(pHandle->id, SPI_RX, SPI_MODE_DMA);
    spi_select_mode(pHandle->id, SPI_TX, SPI_MODE_FIFO);
    #if defined(__MTK_TARGET__)
    #if defined(SPI_MAUI_LOAD)
          /* ensure non-cachable DMA address. */
    {
      if (INT_QueryIsNonCachedRAM(base_addr_in, length * count) != 1)
      {
        return SPI_RESULT_INVALID_ARGUMENT;
      }
    }
    #endif
    #endif
    spi_set_interrupt(pHandle->id, SPI_INT_PAUSE, SPI_ENABLE);
    spi_set_interrupt(pHandle->id, SPI_INT_FINISH, SPI_ENABLE);
    spi_set_cb(pHandle->id, SPI_INT_PAUSE, NULL, NULL);
    spi_set_cb(pHandle->id, SPI_INT_FINISH, NULL, NULL);

    if(transfer_count == 1) // single transfer, no pause mode involved
    {
      //first transfer for transfer amount>1024
      //transfer 1k first
      spi_set_desired_size(pHandle->id, transfer_amount, 1);
      spi_set_rwaddr(pHandle->id, SPI_RX, addr_insysram_for_RX);
      kal_set_eg_events(spi_event_id, 0, KAL_AND);
      spi_activate(pHandle->id);
      kal_retrieve_eg_events(spi_event_id, SPI_EVENT_TRANSFER_COMPLETE,KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
      //spi_wait_not_busy(pHandle->id);
      kal_mem_cpy(base_addr_in,addr_insysram_for_RX,transfer_amount);    
    }
    else // multiple transfers, pause mode invovled and resume required
    {
      spi_set_pause_mode(pHandle->id, KAL_TRUE);
      for (i=0; i<(transfer_count-1); i++)
      {
        //transfer 1k first
        spi_set_desired_size(pHandle->id, length_per_transfer, 1);
        spi_set_rwaddr(pHandle->id, SPI_RX, addr_insysram_for_RX);
        kal_set_eg_events(spi_event_id, 0, KAL_AND);
        if(i==0)
        {
          spi_activate(pHandle->id);
        }
        else
        {
          spi_resume(pHandle->id);
        }
        kal_retrieve_eg_events(spi_event_id, SPI_EVENT_TRANSFER_COMPLETE,KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
        //spi_wait_not_busy(pHandle->id);
        kal_mem_cpy(base_addr_in,addr_insysram_for_RX,length_per_transfer);  
        base_addr_in = (kal_uint32*)((kal_uint32)(base_addr_in) +length_per_transfer );
      }
      spi_set_pause_mode(pHandle->id, KAL_FALSE);
      if(transfer_modulo==0)
      {
        spi_set_desired_size(pHandle->id, length_per_transfer, 1);
      }
      else
      {
        spi_set_desired_size(pHandle->id, transfer_modulo, 1);
      }
      spi_set_rwaddr(pHandle->id, SPI_RX, addr_insysram_for_RX);
      kal_set_eg_events(spi_event_id, 0, KAL_AND);
      spi_resume(pHandle->id);
      kal_retrieve_eg_events(spi_event_id, SPI_EVENT_TRANSFER_COMPLETE,KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
    //spi_wait_not_busy(pHandle->id);
      if(transfer_modulo==0)
      {
        kal_mem_cpy(base_addr_in,addr_insysram_for_RX,length_per_transfer);
      }
      else
      {
        kal_mem_cpy(base_addr_in,addr_insysram_for_RX,transfer_modulo);
      }
    } // end of multiple transfers
    if (fCB)
    {
      fCB();
    }
    return SPI_RESULT_OK;
} //end of spi_read_wa_for_GMC


SPI_RESULT spi_write_wa_for_GMC(SPI_HANDLE handle, void* pBuffer,kal_uint32 length, kal_uint32 count,SPI_CALLBACK fCB)
{
    SPI_RESULT result=SPI_RESULT_OK;
    kal_int32 i;
    kal_uint32 event_group;
    kal_uint32 *base_addr_out=(kal_uint32 *)pBuffer;
    kal_uint32 *addr_insysram_for_TX=(kal_uint32 *)spi_buffer_in_sysram;  
    kal_uint32 transfer_amount = 0;
    kal_uint32 transfer_count = 0;
    kal_uint32 transfer_modulo = 0;
    kal_uint32 length_per_transfer=1024;
    SPI_INTERNAL_HANDLE_T* pHandle = (SPI_INTERNAL_HANDLE_T*) handle;

    if(count==1)
    {
      transfer_amount = length;
    }
    else if(count>1)
    {
      transfer_amount = length*count;
    }
    else
    {
      return SPI_RESULT_INVALID_ARGUMENT;
    }
    transfer_count = (transfer_amount-1) / 1024+1;
    transfer_modulo = transfer_amount % 1024; 
    ASSERT(pHandle);
    // Set DMA mode and FIFO mode
    spi_select_mode(pHandle->id, SPI_RX, SPI_MODE_FIFO);
    spi_select_mode(pHandle->id, SPI_TX, SPI_MODE_DMA);
    #if defined(__MTK_TARGET__)
    #if defined(SPI_MAUI_LOAD)
      /* ensure non-cachable DMA address. */
    {
      if (INT_QueryIsNonCachedRAM(base_addr_out, length * count) != 1)
      {
        return SPI_RESULT_INVALID_ARGUMENT;
      }
    }
    #endif
    #endif
    spi_set_interrupt(pHandle->id, SPI_INT_PAUSE, SPI_ENABLE);
    spi_set_interrupt(pHandle->id, SPI_INT_FINISH, SPI_ENABLE);
    spi_set_cb(pHandle->id, SPI_INT_PAUSE, NULL, NULL);
    spi_set_cb(pHandle->id, SPI_INT_FINISH, NULL, NULL);

    if(transfer_count == 1) // single transfer, no pause mode involved
    {
      //first transfer for transfer amount>1024
      spi_set_desired_size(pHandle->id, transfer_amount, 1);
      spi_set_rwaddr(pHandle->id, SPI_TX, addr_insysram_for_TX);
      kal_mem_cpy(addr_insysram_for_TX, base_addr_out, transfer_amount);
      kal_set_eg_events(spi_event_id, 0, KAL_AND);
      spi_activate(pHandle->id);
      kal_retrieve_eg_events(spi_event_id, SPI_EVENT_TRANSFER_COMPLETE,KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
      //spi_wait_not_busy(pHandle->id);
    }
    else // multiple transfers, pause mode invovled and resume required
    {
      spi_set_pause_mode(pHandle->id, KAL_TRUE);
      for (i=0; i<(transfer_count-1); i++)
      {
        //transfer 1k first
        spi_set_desired_size(pHandle->id, length_per_transfer, 1);
        spi_set_rwaddr(pHandle->id, SPI_TX, addr_insysram_for_TX);
        kal_mem_cpy(addr_insysram_for_TX, base_addr_out, length_per_transfer);
          kal_set_eg_events(spi_event_id, 0, KAL_AND);
        if(i==0)
        {
          spi_activate(pHandle->id);
        }
        else
        {
          spi_resume(pHandle->id);
        }
        kal_retrieve_eg_events(spi_event_id, SPI_EVENT_TRANSFER_COMPLETE,KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
        //spi_wait_not_busy(pHandle->id);
        base_addr_out = (kal_uint32*)((kal_uint32)(base_addr_out) +length_per_transfer );
      }
      spi_set_pause_mode(pHandle->id, KAL_FALSE);
      if(transfer_modulo==0)
      {
        spi_set_desired_size(pHandle->id, length_per_transfer, 1);
      }
      else
      {
        spi_set_desired_size(pHandle->id, transfer_modulo, 1);
      }
      spi_set_rwaddr(pHandle->id, SPI_TX, addr_insysram_for_TX);
      if(transfer_modulo==0)
      {
        kal_mem_cpy(addr_insysram_for_TX, base_addr_out, length_per_transfer);
      }
      else
      {
        kal_mem_cpy(addr_insysram_for_TX, base_addr_out, transfer_modulo);
      }
      kal_set_eg_events(spi_event_id, 0, KAL_AND);
      spi_resume(pHandle->id);
      kal_retrieve_eg_events(spi_event_id, SPI_EVENT_TRANSFER_COMPLETE,KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
      //spi_wait_not_busy(pHandle->id);
    } // end of multiple transfers
    if (fCB)
    {
      fCB();
    }
    return SPI_RESULT_OK;
}  // end of spi_write_wa_for_GMC

/*
two cases:
case1 for normal mode,spi driver use pause mode on MT6276 ;
case2 for pause mode,SPI user set pause mode and SPI driver also use pause mode,
*/
SPI_RESULT spi_readwrite_wa_for_GMC(SPI_HANDLE handle, unsigned char *pOutBuffer,unsigned char *pInBuffer, kal_uint32 length, kal_uint32 count,SPI_CALLBACK fCB)
{
    SPI_RESULT result=SPI_RESULT_OK;
    kal_bool bInPauseMode;
    kal_int32 i;
    kal_uint32 event_group;
    kal_uint32 *base_addr_out=(kal_uint32 *)pOutBuffer;
    kal_uint32 *base_addr_in=(kal_uint32 *)pInBuffer;
    kal_uint32 *addr_insysram_for_TX=(kal_uint32 *)spi_buffer_in_sysram;  
    kal_uint32 *addr_insysram_for_RX=(kal_uint32 *)(spi_buffer_in_sysram+size_insysram/2);  
    kal_uint32 transfer_amount = 0;
    kal_uint32 transfer_count = 0;
    kal_uint32 transfer_modulo = 0;
    kal_uint32 length_per_transfer=1024;
    SPI_INTERNAL_HANDLE_T* pHandle = (SPI_INTERNAL_HANDLE_T*) handle;
    if(count==1)
      transfer_amount = length;
    else if(count>1)
      transfer_amount = length*count;
    else
      return SPI_RESULT_INVALID_ARGUMENT;
    transfer_count = (transfer_amount-1) / 1024+1;
    transfer_modulo = transfer_amount % 1024; 
    ASSERT(pHandle);
    // Set DMA mode and FIFO mode
    spi_select_mode(pHandle->id, SPI_RX, SPI_MODE_DMA);
    spi_select_mode(pHandle->id, SPI_TX, SPI_MODE_DMA);
    #if defined(__MTK_TARGET__)
    #if defined(SPI_MAUI_LOAD)
      /* ensure non-cachable DMA address. */
    {
      if ((INT_QueryIsNonCachedRAM(pOutBuffer, length * count) != 1)||(INT_QueryIsNonCachedRAM(pInBuffer, length * count) != 1))
      {
        return SPI_RESULT_INVALID_ARGUMENT;
      }
    }
    #endif
    #endif
    spi_set_interrupt(pHandle->id, SPI_INT_PAUSE, SPI_ENABLE);
    spi_set_interrupt(pHandle->id, SPI_INT_FINISH, SPI_ENABLE);
    spi_set_cb(pHandle->id, SPI_INT_PAUSE, NULL, NULL);
    spi_set_cb(pHandle->id, SPI_INT_FINISH, NULL, NULL);
    if(transfer_count == 1)// single transfer, no pause mode involved
    {
      //transfer 1k first
      spi_set_desired_size(pHandle->id, transfer_amount, 1);
      spi_set_rwaddr(pHandle->id, SPI_TX, addr_insysram_for_TX);
      spi_set_rwaddr(pHandle->id, SPI_RX, addr_insysram_for_RX);
      kal_mem_cpy(addr_insysram_for_TX, base_addr_out, transfer_amount);
      kal_set_eg_events(spi_event_id, 0, KAL_AND);
      spi_activate(pHandle->id);
      kal_retrieve_eg_events(spi_event_id, SPI_EVENT_TRANSFER_COMPLETE,KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
      kal_mem_cpy(base_addr_in,addr_insysram_for_RX,transfer_amount);    

      //spi_wait_not_busy(pHandle->id);
    }
    else   // multiple transfers, pause mode invovled and resume required
    {
      spi_set_pause_mode(pHandle->id, KAL_TRUE);
      for (i=0; i<(transfer_count-1); i++)
      {
        //transfer 1k first
        spi_set_desired_size(pHandle->id, length_per_transfer, 1);
        spi_set_rwaddr(pHandle->id, SPI_TX, addr_insysram_for_TX);
        spi_set_rwaddr(pHandle->id, SPI_RX, addr_insysram_for_RX);
        kal_mem_cpy(addr_insysram_for_TX, base_addr_out, length_per_transfer);
        kal_set_eg_events(spi_event_id, 0, KAL_AND);
        if(i==0)
          spi_activate(pHandle->id);
        else
          spi_resume(pHandle->id);
        kal_retrieve_eg_events(spi_event_id, SPI_EVENT_TRANSFER_COMPLETE,KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
        kal_mem_cpy(base_addr_in,addr_insysram_for_RX,length_per_transfer);  
        base_addr_out = (kal_uint32*)((kal_uint32)(base_addr_out) +length_per_transfer );
        base_addr_in = (kal_uint32*)((kal_uint32)(base_addr_in) +length_per_transfer );
      }
      spi_set_pause_mode(pHandle->id, KAL_FALSE);
      if(transfer_modulo==0)
        spi_set_desired_size(pHandle->id, length_per_transfer, 1);
      else
        spi_set_desired_size(pHandle->id, transfer_modulo, 1);
      spi_set_rwaddr(pHandle->id, SPI_TX, addr_insysram_for_TX);
      spi_set_rwaddr(pHandle->id, SPI_RX, addr_insysram_for_RX);
      if(transfer_modulo==0)
        kal_mem_cpy(addr_insysram_for_TX, base_addr_out, length_per_transfer);
      else
        kal_mem_cpy(addr_insysram_for_TX, base_addr_out, transfer_modulo);
      kal_set_eg_events(spi_event_id, 0, KAL_AND);
      spi_resume(pHandle->id);
      kal_retrieve_eg_events(spi_event_id, SPI_EVENT_TRANSFER_COMPLETE,KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
      if(transfer_modulo==0)
        kal_mem_cpy(base_addr_in,addr_insysram_for_RX,length_per_transfer);
      else
        kal_mem_cpy(base_addr_in,addr_insysram_for_RX,transfer_modulo);
    }// end of multiple transfers
    if (fCB)
    {
      fCB();
    }
    return SPI_RESULT_OK;
}
#endif

#endif
