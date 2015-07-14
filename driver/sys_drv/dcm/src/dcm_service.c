
#ifdef __MTK_TARGET__
#include "cp15.h"
#include "dcm.h"
#include "dcm_sw.h"
#include "pll.h"
#include "bus_drv.h"

#if defined(_MSC_VER) && (_MSC_VER >= 1500)
#define __SECTION__(name)
#else //#if defined(_MSC_VER) && (_MSC_VER >= 1500)
#if defined (__SECTION__)
#undef __SECTION__
#endif  //#if defined (__SECTION__)
#define __SECTION__(name) __attribute__ ((section (#name)))
#endif //#if defined(_MSC_VER) && (_MSC_VER >= 1500)


#if defined (__GNUC__)
#define __nop() do { asm volatile ("nop"); } while(0)
#endif //#if defined (__GNUC__)

//#pragma arm section code = "INTSRAM_ROCODE"
kal_int32 arm_enter_standby_mode(kal_int32 mode) __SECTION__(INTSRAM_ROCODE);

kal_int32 arm_enter_standby_mode(kal_int32 mode)
{

#if defined(MT6280)
    // if 0x8000001c[13]=1, arm clock force on
    if (*(volatile kal_uint32*)(0x8000001c) & (1<<13))
        *MDMCU_DCM_CON_0 |= (1<<26);
    else 
        *MDMCU_DCM_CON_0 &= ~(1<<26);
        
#endif 

#if defined(MT6572) || defined(MT6582) || defined(MT6592) || defined(MT6571) || defined(MT6580)
#if defined (DCM_ENABLE)
/**
 * workaround: to disable prefecth buffer that is affected while TOP MDMCU DCM gating MDMCU clock.
 * TOP MDMCU DCM will gating mcu_clock, thus make prefecth buffer broken out.
 **/
	Bus_PFB_Disable();
#endif //#if defined (DCM_ENABLE)
#endif //#if defined(MT6572) || defined(MT6582) || defined(MT6592) || defined(MT6571) || defined(MT6580)

    cp15_enter_low_pwr_state();

#if defined(MT6572) || defined(MT6582) || defined(MT6592) || defined(MT6571) || defined(MT6580)
#if defined (DCM_ENABLE)
	Bus_PFB_Enable();
#endif //#if defined (DCM_ENABLE)
#endif //#if defined(MT6572) || defined(MT6582) || defined(MT6592) || defined(MT6571) || defined(MT6580)

	return 0;
}
//#pragma arm section code


void DCM_Prerequisite(void)
{
#if defined (MT6280)	
	kal_uint32 pll_fdiv0, rg_apmcu_fsel=3, hsapbus_fsel=0x10;
	pll_fdiv0 = (*PLL_CLKSW_FDIV0 & 0x0f00) >> 8;

#if defined(__TRADITIONAL_MODEM_CARD__)  || defined (__SDIO_DEVICE_CONNECTIVITY__) || defined (__MAUI_BASIC__)
	if (pll_fdiv0 == 3) {
		rg_apmcu_fsel = 3;
		hsapbus_fsel = 0x10;
	}
	if (pll_fdiv0 == 0x0c) {
		rg_apmcu_fsel = 0;
		hsapbus_fsel = 0x10;
	}
	
	*APMCU_DCM_CON_0 = reg_aor(*APMCU_DCM_CON_0, ~((0x1f<<0)), (rg_apmcu_fsel << 0));
	*APMCU_DCM_CON_1 = 0x08;   //to set RG_APMCU_FSEL bit
	*APMCU_DCM_CON_1 = reg_or(*APMCU_DCM_CON_1, 1<<5);       // toggle 1
	*APMCU_DCM_CON_1 = reg_and(*APMCU_DCM_CON_1, ~(1<<5));   // toggle 0

	*AP_DCM_CON_1 = reg_aor(*AP_DCM_CON_1, ~((0x1F << 8) | (0x1F << 24)), ((hsapbus_fsel << 8)|(1 << 24)));    
#endif //#if defined (__MAUI_BASIC__)
#endif //#if defined (MT6280)	

#if defined (MT6589)
	{
		/** This patch is to activate 'AP resource ready ack' mode for MDMCU transaction,
		 * otherwise MD1 hang randomly after dormant restore.
		 * That comes from AP changeing infra-bus suspend mode, 
		 * and introduceing longer latency of AP wakeup time.
		 */
		*MD_AP_RES_ACK |= (1<<25);
	}

#elif defined (MT6572) || defined (MT6582) || defined (MT6592) || defined(MT6571) || defined(MT6580)
	{
		/** This patch is to activate 'AP resource ready ack' mode for MDMCU transaction,
		 * otherwise MD1 hang randomly after dormant restore.
		 * That comes from AP changeing infra-bus suspend mode, 
		 * and introduceing longer latency of AP wakeup time.
		 */
		*MD_AP_RES_ACK |= (1<<27);
	}

#endif //#if defined (MT6589)

}

void DCM_EMI2AXI_DCM_OFF(kal_uint32 off) __attribute__((weak, alias ("DCM_MCUBUS_DCM_OFF")));
volatile kal_uint32 dcm_mcubus_dcm_off = 0;

#if defined (MT6280)
/** the low level opertation to switch mcu_bus dcm on/off.
 * 1. should be protected between idle task(?) and user callers.
 * 2. however, please be noticed, the real critical is DCM functionaility, instead of register operation here.
 **/
void _mcubus_dcm_off(void) 
{
	*PWR_DCM_DEBUG_CON1 = reg_aor(*PWR_DCM_DEBUG_CON1, ~(1<<7), (0 != dcm_mcubus_dcm_off) ? (1<<7) : 0);
}

/** to workaround WHQA_00012220, "may not update way_en while disabling prefetch buffer",
 * here provides an API to switch MCUBUS DCM dynamically.
 */
void DCM_MCUBUS_DCM_OFF(kal_uint32 off)
{
#if defined (REENTRY_SUPPORT)        
    kal_uint32 _savedMask;
    _savedMask = SaveAndSetIRQMask();
    if (0 != off) {
        dcm_mcubus_dcm_off++;
    }
    else {
        if (dcm_mcubus_dcm_off>0) 
            dcm_mcubus_dcm_off--;
    }
    RestoreIRQMask(_savedMask);
#else //#if defined (REENTRY_SUPPORT)        

    if (0 != off) {
        dcm_mcubus_dcm_off++;
    }
    else {
        if (dcm_mcubus_dcm_off>0) 
            dcm_mcubus_dcm_off--;
    }

#endif //#if defined (REENTRY_SUPPORT)        

#if defined (DCM_ENABLE)
    *PWR_DCM_DEBUG_CON1 = reg_aor(*PWR_DCM_DEBUG_CON1, ~(1<<7), (0 != dcm_mcubus_dcm_off) ? (1<<7) : 0);
#endif //#if defined (DCM_ENABLE)

}
#elif defined(MT6589) || defined (MT6572) || defined (MT6582) || defined(MT6592) || defined(MT6571) || defined(MT6580) //#if defined (MT6280)
void _mcubus_dcm_off(kal_uint32 off) 
{
	kal_uint32 dcm_on = 0;
	if ((off == 0) && (0 == dcm_mcubus_dcm_off))
		dcm_on = 1;

    *MD_GLOBAL_CON1 = reg_aor(*MD_GLOBAL_CON1, ~(1<<25), dcm_on<<25);
}

void DCM_MCUBUS_DCM_OFF(kal_uint32 off)
{
    kal_uint32 _savedMask;
    _savedMask = SaveAndSetIRQMask();
    if (0 != off) {
        dcm_mcubus_dcm_off++;
    }
    else {
        if (dcm_mcubus_dcm_off>0) 
            dcm_mcubus_dcm_off--;
    }
#if defined (DCM_ENABLE)
    *MD_GLOBAL_CON1 = reg_aor(*MD_GLOBAL_CON1, ~(1<<25), (0 != dcm_mcubus_dcm_off) ? 0 : (1<<25));
#endif //#if defined (DCM_ENABLE)
    RestoreIRQMask(_savedMask);
}

#else //#if defined (MT6280)
void DCM_MCUBUS_DCM_OFF(kal_uint32 off) {}
#endif //#if defined (MT6280)


/****************************************************
 * to provide APIs for log timestamp in/out DCM.
 ****************************************************/
//#define DCM_TS_DEBUG
#if defined (DCM_TS_DEBUG) /// debug purpose, timestamp loging
#include "us_timer.h"

#define DCM_TS_LOG_SIZE (4)
struct _log_data {
	unsigned int sn;
	unsigned int usc;
} dcm_ts_log_data[DCM_TS_LOG_SIZE] __SECTION__(INTSRAM_ZI);

__SECTION__(INTSRAM_ROCODE) unsigned int dcm_ts_log(int idx) 
{
	static unsigned int gsn;
	unsigned int usc;

	if (idx==0) 
		gsn++;

	if (gsn != dcm_ts_log_data[idx].sn) {
		usc = ust_get_current_time();
		dcm_ts_log_data[idx].usc = usc;
		dcm_ts_log_data[idx].sn = gsn;
		return usc;
	}
	return (unsigned int)-1;
}

unsigned int dcm_ts_get_usc(int idx)
{
	return dcm_ts_log_data[idx].usc;
}

unsigned int dcm_ts_log_duration(int prev, int late)
{
	unsigned int p = dcm_ts_log_data[prev].usc;
	unsigned int l = dcm_ts_log_data[late].usc;

	if (l>p) 
		return l-p;
	else
		return USCNT_WRAP - p + l;
}
#else // nullify APIs.
unsigned int dcm_ts_get_usc(int idx) {}
unsigned int dcm_ts_log_duration(int prev, int late) {}
unsigned int dcm_ts_log(int idx) {}
#endif //#if defined (DCM_TS_DEBUG) /// debug purpose, timestamp loging

#endif //__MTK_TARGET__
