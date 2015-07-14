


#if !defined(__SMART_PHONE_MODEM__)

#include "kal_public_api.h"
#include "kal_general_types.h"
#include "reg_base.h"

#include "dcl.h"

#define WriteREG(_addr, _value) (*(volatile kal_uint32 *)(_addr) = (_value))


// ----------------------------------------------------------------------------
// Register Definition
// ----------------------------------------------------------------------------

#if defined(MT6589)

// #define AP_AUDSYS_BASE   0xA2070000

#define AUDIO_TOP_CON0                  (AP_AUDSYS_base + 0x0000)
#define AUDIO_TOP_CON3                  (AP_AUDSYS_base + 0x000c)
#define AFE_DAC_CON0                    (AP_AUDSYS_base + 0x0010)
#define AFE_DAC_CON1                    (AP_AUDSYS_base + 0x0014)
#define AFE_I2S_CON                     (AP_AUDSYS_base + 0x0018)
#define AFE_DAIBT_CON0                  (AP_AUDSYS_base + 0x001c)
                                        
#define AFE_CONN0                       (AP_AUDSYS_base + 0x0020)
#define AFE_CONN1                       (AP_AUDSYS_base + 0x0024)
#define AFE_CONN2                       (AP_AUDSYS_base + 0x0028)
#define AFE_CONN3                       (AP_AUDSYS_base + 0x002c)
#define AFE_CONN4                       (AP_AUDSYS_base + 0x0030)

#define AFE_I2S_CON1                    (AP_AUDSYS_base + 0x0034)
#define AFE_I2S_CON2                    (AP_AUDSYS_base + 0x0038)
#define AFE_MRGIF_CON                   (AP_AUDSYS_base + 0x003c)

#define AFE_SIDDETONE_DEBUG             (AP_AUDSYS_base + 0x01D0)
#define AFE_SIDDETONE_MON               (AP_AUDSYS_base + 0x01D4)
#define AFE_SIDDETONE_CON0              (AP_AUDSYS_base + 0x01E0)
#define AFE_SIDDETONE_COEFF             (AP_AUDSYS_base + 0x01E4)
#define AFE_SIDDETONE_CON1              (AP_AUDSYS_base + 0x01E8)
#define AFE_SIDDETONE_GAIN              (AP_AUDSYS_base + 0x01EC)
#define AFE_SGEN_CON0                   (AP_AUDSYS_base + 0x01F0)
                                        
#define AFE_TOP_CON0                    (AP_AUDSYS_base + 0x0200)


#define AFE_GAIN2_CON0                  (AP_AUDSYS_base + 0x0428)
#define AFE_GAIN2_CON                   (AP_AUDSYS_base + 0x0438)
#define AFE_GAIN2_CON2                  (AP_AUDSYS_base + 0x0440)

#define PCM_INTF_CON1                   (AP_AUDSYS_base + 0x0530)
#define PCM_INTF_CON2                   (AP_AUDSYS_base + 0x0538)
#define PCM_INTF_CON                    (AP_AUDSYS_base + 0x053C)
#define FOC_ROM_SIG                     (AP_AUDSYS_base + 0x0630)

#elif defined(MT6572) || defined(MT6582) || defined(MT6592) || defined(MT6571)|| defined(MT6580)

#define AUDIO_TOP_CON0                  (AP_AUDSYS_base + 0x0000)
#define AFE_DAC_CON0                    (AP_AUDSYS_base + 0x0010)
#define AFE_SGEN_CON0                   (AP_AUDSYS_base + 0x01F0)
#define AFE_CONN0                       (AP_AUDSYS_base + 0x0020)
#define AFE_CONN1                       (AP_AUDSYS_base + 0x0024)
#define AFE_CONN2                       (AP_AUDSYS_base + 0x0028)
#define AFE_CONN3                       (AP_AUDSYS_base + 0x002c)
#define AFE_CONN4                       (AP_AUDSYS_base + 0x0030)

#define AFE_I2S_CON1                    (AP_AUDSYS_base + 0x0034)

#define AFE_ADDA_DL_SRC2_CON0           (AP_AUDSYS_base + 0x0108)
#define AFE_ADDA_DL_SRC2_CON1           (AP_AUDSYS_base + 0x010C)
#define AFE_ADDA_UL_SRC_CON0            (AP_AUDSYS_base + 0x0114)
#define AFE_ADDA_UL_SRC_CON1            (AP_AUDSYS_base + 0x0118)
#define AFE_ADDA_TOP_CON0               (AP_AUDSYS_base + 0x0120)
#define AFE_ADDA_UL_DL_CON0             (AP_AUDSYS_base + 0x0124)

#define AFE_ADDA_NEWIF_CFG0             (AP_AUDSYS_base + 0x0138)
#define AFE_ADDA_NEWIF_CFG1             (AP_AUDSYS_base + 0x013C)


#define AFE_SIDDETONE_CON1              (AP_AUDSYS_base + 0x01E8)

#define AFE_TOP_CON0                    (AP_AUDSYS_base + 0x0200)

#define PCM_INTF_CON                    (AP_AUDSYS_base + 0x053C)

#endif // defined(MT6589)

// ----------------------------------------------------------------------------
// Register Setting for different scenario 
// ----------------------------------------------------------------------------


#if defined(MT6572) || defined(MT6582) || defined(MT6592) || defined(MT6571)||defined(MT6580)
void PMIC_AudioConfig(void)
{
	kal_uint32 addr;
	kal_uint16 data;
	DCL_HANDLE handle;
	PMU_CTRL_MISC_SET_REGISTER_VALUE setVal;
	PMU_CTRL_MISC_GET_REGISTER_VALUE getVal;
	
	setVal.offset = (0<<31) | addr; 
	setVal.value = data; 

	handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);

	// 	0x0102 bit[0] to be 1, eable clock source	
	getVal.offset = ((0<<31) | 0x0102); 
	DclPMU_Control(handle, MISC_GET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&getVal);
	setVal.value = (getVal.value | 0x0001);
	setVal.offset = ((0<<31) | 0x0102); 
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

	// 	0x010C 0x0100 0x0100 Turn on clock, [OK]
	getVal.offset = ((0<<31) | 0x010C); 
	DclPMU_Control(handle, MISC_GET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&getVal);
	setVal.value = (getVal.value | 0x0100);
	setVal.offset = ((0<<31) | 0x010C); 
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

	// 	0x4024 0xffff 0x3330	DL Sampline rate config [check]
	setVal.offset = ((0<<31) | 0x4024); 
	setVal.value = (0x3330);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

	// 0x4028 0xffff 0x342F UL Sampline rate config	[check]	
	setVal.offset = ((0<<31) | 0x4028); 
	setVal.value = (0x342F);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
	
	// 0x4002	0xffff 0x0004 may need to check for dl 16K UL 16K [check]
	setVal.offset = ((0<<31) | 0x4002); 
	setVal.value = (0x0004);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

	// 0x4016 	triger dl 1 read it out then write back 
	getVal.offset = ((0<<31) | 0x4016); 
	DclPMU_Control(handle, MISC_GET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&getVal);
	setVal.value = ((~((getVal.value)<< 8)) & 0x0300);
	setVal.offset = ((0<<31) | 0x4016); 
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
	
	// 	0x4000 0xffff 0x0003 this is for turn on	
	setVal.offset = ((0<<31) | 0x4000); 
	setVal.value = (0x0003);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

	// 	0x0700 0xffff 0x79B0 MIC 0	
	setVal.offset = ((0<<31) | 0x0700); 
	setVal.value = (0x79B0);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

	// 	0x0702 0xffff 0x0210 MIC 1	[ok]
	setVal.offset = ((0<<31) | 0x0702); 
	setVal.value = (0x0210);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

	// 	0x0704 0xffff 0x00F3 UL	
	setVal.offset = ((0<<31) | 0x0704); 
	setVal.value = (0x00F3);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

	setVal.offset = ((0<<31) | 0x0710);  // add
	setVal.value = (0x0208);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
	
	// 0x070E 0xffff 0x2400 DL turn on
	setVal.offset = ((0<<31) | 0x070E); 
	setVal.value = (0x2400);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
	
	// 0x0708 0xffff 0x0014 DL turn on // add
	setVal.offset = ((0<<31) | 0x0708); 
	setVal.value = (0x007C);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

	// 0x0708 0xffff 0x0014 DL turn on // add
	setVal.offset = ((0<<31) | 0x070A); 
	setVal.value = (0x2214);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

	// 0x070C	0xffff 0xB7F6 DL turn on // check
	setVal.offset = ((0<<31) | 0x070C); 
	setVal.value = (0xF5BA);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

	// 0x070E 0xffff 0x2500 DL turn on
	setVal.offset = ((0<<31) | 0x070E); 
	setVal.value = (0x2500);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

	// 0x070E 0xffff 0x25B0 DL turn on
	setVal.offset = ((0<<31) | 0x070E); 
	setVal.value = (0x25B0);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

	setVal.offset = ((0<<31) | 0x402c);  // loopback
	setVal.value = (0x4000);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
	
	DclPMU_Close(handle);
}


void PMIC_AudioConfig_Loopback(void)
{
	kal_uint32 addr;
	kal_uint16 data;
	DCL_HANDLE handle;
	PMU_CTRL_MISC_SET_REGISTER_VALUE setVal;
	PMU_CTRL_MISC_GET_REGISTER_VALUE getVal;
	
	setVal.offset = (0<<31) | addr; 
	setVal.value = data; 

	handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);

	// 	0x0102 bit[0] to be 1, eable clock source	
	/*
	getVal.offset = ((0<<31) | 0x0102); 
	DclPMU_Control(handle, MISC_GET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&getVal);
	setVal.value = (getVal.value | 0x0001);
	setVal.offset = ((0<<31) | 0x0102); 
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
	*/
	
	// 	0x010C 0x0100 0x0100 Turn on clock
	getVal.offset = ((0<<31) | 0x010C); 
	DclPMU_Control(handle, MISC_GET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&getVal);
	setVal.value = (getVal.value | 0x0100);
	setVal.offset = ((0<<31) | 0x010C); 
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

	// 	0x010C 0x0100 0x0100 Turn on clock
	#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif 
	//setVal.offset = ((0<<31) | 0x402C); 
	//setVal.value = (0x0000);	
	//DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

   
   setVal.offset = ((0<<31) | 0x0116); 
	setVal.value = (0x0004);	
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

   setVal.offset = ((0<<31) | 0x0118); 
	setVal.value = (0x0004);	
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
	setVal.offset = ((0<<31) | 0x4024); 
	setVal.value = (0x3330);	// 16k : 0x3330, 8k : 0x0330
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

	setVal.offset = ((0<<31) | 0x4028); 
	setVal.value = (0x342f);	
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

	setVal.offset = ((0<<31) | 0x4002); 
	setVal.value = (0x0004);    // 16k : 0x0004, 8k : 0x0000
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);


	 //sine tone generation
	//setVal.offset = ((0<<31) | 0x4004); 
	//setVal.value = (0x0022); // loopback 	
	//DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

	/*
	setVal.offset = ((0<<31) | 0x4010); 
	setVal.value = (0x9010);	
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
	*/
	// sine tone generation 
	
	setVal.offset = ((0<<31) | 0x4016); 
	setVal.value = (0x0300);	
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

   setVal.offset = ((0<<31) | 0x400a); 
	setVal.value = (0x0028);	
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
	setVal.offset = ((0<<31) | 0x4000); 
	setVal.value = (0x0003);	
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

	setVal.offset = ((0<<31) | 0x0700); 
	setVal.value = (0x79A0);	
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

	setVal.offset = ((0<<31) | 0x0702); 
	setVal.value = (0x0200);	
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

	setVal.offset = ((0<<31) | 0x0704); 
	setVal.value = (0x00F3);	
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

	setVal.offset = ((0<<31) | 0x0706); 
	setVal.value = (0x0000);	
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
	
	setVal.offset = ((0<<31) | 0x0710); 
	setVal.value = (0x0208);	
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

	setVal.offset = ((0<<31) | 0x0708); 
	setVal.value = (0x0010);	//setVal.value = (0x007c);	
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

	setVal.offset = ((0<<31) | 0x070A); 
	setVal.value = (0x2214);	
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

	setVal.offset = ((0<<31) | 0x070C); 
	setVal.value = (0xF5BA);	
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

	setVal.offset = ((0<<31) | 0x070E); 
	setVal.value = (0x25B0);	
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

}



#endif

// void l1sp_configApAfeHwForBt(void)
void ApAudSys_config_forBt(void)
{
#if defined(MT6589)

	// GPIO set to external
	/*
	WriteREG(0xA00050D0, 0x5000 ); // GPIO_DIR13 
	WriteREG(0xA00050E0, 0x0001 ); // GPIO_DIR14
	WriteREG(0xA0005EC0, 0x1248 ); // GPIO_MODE2C, 
	*/
	
	// MAIN setting for interconnection
	WriteREG(AUDIO_TOP_CON0, 0x00004000);
	WriteREG(AFE_TOP_CON0, 0x00000000);
	WriteREG(AFE_DAC_CON0, 0x00000001);

	WriteREG(AFE_CONN1, 0x00000000); 
	WriteREG(AFE_CONN2, 0x00000000); 	
	WriteREG(AFE_CONN3, 0x00400000); // i14, o2 
	WriteREG(AFE_CONN4, 0x00000000); 

	WriteREG(AFE_GAIN2_CON0, 0x0000c801);
	WriteREG(AFE_GAIN2_CON, 0x01040000); // MD1
	WriteREG(AFE_GAIN2_CON2, 0x000000C0);

	
	WriteREG(AFE_DAIBT_CON0, 0x105F);
	WriteREG(AFE_MRGIF_CON, 0x00900001);
	
	// MD2
	WriteREG(PCM_INTF_CON1, 0x0000006F);
	// WriteREG(PCM_INTF_CON2, 0x00000000);
	// MD1
	WriteREG(PCM_INTF_CON, 0x0000000F);
#elif defined(MT6572)
// TODO:
#elif defined(MT6582)
// TODO:
#endif
}

void ApAudSys_config(void)
{
	
#if defined(IC_MODULE_TEST)
	// For SLT test, these register settings would affect the AFE test case.
#else   // Normal usage, IC_MODULE_TEST

#if defined(MT6589)
	// for second modem with slave mode
	// vSetASRC
	// WriteREG(AFE_ASRC_CON1, 0x00000cb2);
	// WriteREG(AFE_ASRC_CON2, 0x00400000);
	// WriteREG(AFE_ASRC_CON3, 0x00400000);
	// WriteREG(AFE_ASRC_CON4, 0x00000cb2);
	// WriteREG(AFE_ASRC_CON7, 0x00000659);
	
	// vASRCEnable
	// WriteREG(AFE_ASRC_CON6, 0x00000000);
	// WriteREG(AFE_ASRC_CON0, 0x06003030);

	// MAIN setting for interconnection
	WriteREG(AUDIO_TOP_CON0, 0x00004000);
	WriteREG(AFE_TOP_CON0, 0x00000000);
	WriteREG(AFE_DAC_CON0, 0x00000001);
	WriteREG(AFE_CONN1, 0x02000000); // MD2
	WriteREG(AFE_CONN2, 0x24000200); // MD2	
	WriteREG(AFE_CONN3, 0x08000000); // MD1
	WriteREG(AFE_CONN4, 0x00012001); // MD1

	// sidetone
	WriteREG(AFE_SIDDETONE_CON1, 0x00000000);
	

	// MD2
	WriteREG(PCM_INTF_CON1, 0x0000006F);
	// WriteREG(PCM_INTF_CON2, 0x00000000);
	// MD1
	WriteREG(PCM_INTF_CON, 0x0000000F);

	// i2s to external dac
	WriteREG(AFE_I2S_CON1, 0x00000409); //dac 16k
	WriteREG(AFE_I2S_CON2, 0x00000409); //adc 16k


#elif defined(MT6572) || defined(MT6582) || defined(MT6592) || defined(MT6571)||defined(MT6580)


	WriteREG(AUDIO_TOP_CON0, 0x60004000);
	WriteREG(AFE_TOP_CON0, 0x00000000);
	
	// MAIN setting for interconnection
	WriteREG(AFE_CONN3, 0x08000000); // MD1, i14->o3
	WriteREG(AFE_CONN4, 0x00012001); // MD1, i4->o18, i3->o17, i14->o4

	// sidetone
	WriteREG(AFE_SIDDETONE_CON1, 0x00000000);

	// MD1
	WriteREG(PCM_INTF_CON, 0x0000000F); 

	// new interface with SRC	
	WriteREG(AFE_ADDA_NEWIF_CFG0, 0x03F87201);
	WriteREG(AFE_ADDA_NEWIF_CFG1, 0x03117580);

	WriteREG(AFE_ADDA_DL_SRC2_CON0, 0x33001823); // DL 16k : 0x33001823, DL 8k : 0x03001823
	WriteREG(AFE_ADDA_DL_SRC2_CON1, 0xFFFF0000);
		
	WriteREG(AFE_ADDA_UL_SRC_CON0, 0x000A0001); // UL 16k : 0x000A0001, UL 8k : 0x00000001
	WriteREG(AFE_ADDA_UL_SRC_CON1, 0x00000000);
	
	WriteREG(AFE_ADDA_TOP_CON0, 0x00000000);
	WriteREG(AFE_I2S_CON1, 0x0000040B); //I2S out, 要和ADDA一起開,位置在0x0034
	WriteREG(AFE_ADDA_UL_DL_CON0, 0x00000001);
	WriteREG(AFE_DAC_CON0, 0x00000001); // keep in last, confirm by Andrew

	// PMIC_AudioConfig(); 
	PMIC_AudioConfig_Loopback();
	
#endif // chip base define

#endif  // IC_MODULE_TEST

	
}
#endif // !defined(__SMART_PHONE_MODEM__)


