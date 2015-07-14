
#ifndef __BGSNG_H__
#define __BGSNG_H__

#define BGSND_RB_DEFAULT_THRESHOLD    1024


int32 BGSND_GetFreeSpace(void);
void BGSND_WriteData(kal_uint8 *srcBuf, kal_int32 bufLen);

void BGSND_ConfigULMixer(kal_bool bULSPHFlag, kal_int8 ULSNDGain );
void BGSND_ConfigDLMixer(kal_bool bDLSPHFlag, kal_int8 DLSNDGain );
void BGSND_Start(void (*bgSnd_hisrHandler)(void), void (*bgSnd_offHandler)(void), kal_uint8 ULGainLevel , kal_uint8 DLGainLevel);
void BGSND_Stop(void);
void BGSND_Close(void);
void BGSND_INIT(void);

#endif //__BGSNG_H__