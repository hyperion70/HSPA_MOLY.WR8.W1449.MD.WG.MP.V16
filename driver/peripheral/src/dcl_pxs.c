/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   dcl_pxs.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This Module defines DCL (Driver Common Layer) of the PXS driver.
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


// MMI request, even if there is no PXS device, the interfaces should still exist and return ERROR code
#if !defined(__PXS_ENABLE__)
#include "dcl.h"
DCL_STATUS DclPXS_Initialize(void)
{
	return STATUS_DEVICE_NOT_EXIST;
}
DCL_HANDLE DclPXS_Open(DCL_DEV dev, DCL_FLAGS flags)
{
	return STATUS_DEVICE_NOT_EXIST;
}
DCL_STATUS DclPXS_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options)
{
	return STATUS_DEVICE_NOT_EXIST;
}
DCL_STATUS DclPXS_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options)
{
	return STATUS_DEVICE_NOT_EXIST;
}
DCL_STATUS DclPXS_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
	return STATUS_DEVICE_NOT_EXIST;
}
DCL_STATUS DclPXS_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
	return STATUS_DEVICE_NOT_EXIST;
}
DCL_STATUS DclPXS_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	return STATUS_DEVICE_NOT_EXIST;
}
DCL_STATUS DclPXS_Close(DCL_HANDLE handle)
{
	return STATUS_DEVICE_NOT_EXIST;
}
#endif // #if !defined(__PXS_ENABLE__)

#if defined(__PXS_ENABLE__)
#include "kal_general_types.h"
#include "intrCtrl.h"
#include "dcl.h"



#define GET_DRIVER_SEMAPHORE(x)      x = SaveAndSetIRQMask()
#define RELEASE_DRIVER_SEMAPHORE(x)      RestoreIRQMask(x)

#define PXS_MAX_OPEN_COUNT   1

#define DCL_PXS_DEV_MAGIC_NUM    (0x60000000)
#define DCL_PXS_DEV_MAGIC_NUM_MASK    (0xFFFF0000)

kal_uint32 pxs_open_count;
PXS_CONFIG_T PXSConfig;  // The configuration from PXS users

kal_bool pxs_adv_algo_windowing_flag;
PXS_CTRL_GET_ADV_ALGO_WINDOWING_T pxs_algo_windowing;
kal_bool pxs_adv_algo_thread_flag;
PXS_CTRL_GET_ADV_ALGO_THRESHOLD_T pxs_algo_threshold;
DCL_BOOL pxs_detect_flag = DCL_FALSE;   // DCL_TRUE: Detected; DCL_FALSE: Not detected

kal_bool pxs_exist_flag = KAL_FALSE;


// The callback function registered to HPXS level driver
// PXS driver can decide to have some process or NOT then callback to user registered callback
static void HPXS_Callback(DCL_BOOL fgObjectDetected)
{
	pxs_detect_flag = fgObjectDetected;
	if (PXSConfig.fgNotify == DCL_TRUE)
	{
		if (PXSConfig.NotifyCallback)
		{
			PXSConfig.NotifyCallback(fgObjectDetected);
		}
		else
		{
			ASSERT(0);
		}
	}
}



/*************************************************************************
* FUNCTION
*  DclPXS_Initialize
*
* DESCRIPTION
*  This function is to initialize PXS module
*
* PARAMETERS
*  None
*
* RETURNS
*  STATUS_OK
*
*************************************************************************/
DCL_STATUS DclPXS_Initialize(void)
{

	DCL_CTRL_DATA_T ctrl;
	
	if (STATUS_OK != DclHPXS_Initialize())
	{
		//ASSERT(0);
		return STATUS_FAIL;
	}

	if (STATUS_OK == DclHPXS_Control(DCL_PXS_DEV_MAGIC_NUM, PXS_CMD_GET_ADV_ALGO_WINDOWING, (DCL_CTRL_DATA_T *)(&ctrl)))
	{
		pxs_adv_algo_windowing_flag = KAL_TRUE;
		pxs_algo_windowing.u2Count = ctrl.rPXSAdvAlgoWindowing.u2Count;
	}
	else
	{
		pxs_adv_algo_windowing_flag = KAL_FALSE;
	}

	if (STATUS_OK == DclHPXS_Control(DCL_PXS_DEV_MAGIC_NUM, PXS_CMD_GET_ADV_ALGO_THRESHOLD, (DCL_CTRL_DATA_T *)(&ctrl)))
	{
		pxs_adv_algo_thread_flag = KAL_TRUE;
		pxs_algo_threshold.u2HiThreshold = ctrl.rPXSAdvAlgoThreshold.u2HiThreshold;
		pxs_algo_threshold.u2LoThreshold = ctrl.rPXSAdvAlgoThreshold.u2LoThreshold;
	}
	else
	{
		pxs_adv_algo_thread_flag = KAL_FALSE;
	}

	pxs_open_count = 0;
	pxs_exist_flag = KAL_TRUE;

	return STATUS_OK;
}

/*************************************************************************
* FUNCTION
*  DclPXS_Open
*
* DESCRIPTION
*  This function is to open the PXS module and return a handle
*
* PARAMETERS
*  dev: only valid for DCL_PXS
*  flags: no sepcial flags is needed. Please use FLAGS_NONE
*
* RETURNS
*  DCL_HANDLE_INVALID: Open failed
*  Other value: A valid handle
*
*************************************************************************/
DCL_HANDLE DclPXS_Open(DCL_DEV dev, DCL_FLAGS flags)
{
	kal_uint32 handle;
	kal_uint32 savedMask;

	// Check device type
	if (dev != DCL_PXS){
		//ASSERT(0);
		return DCL_HANDLE_INVALID;		// Incorrecr device ID
	}

	// If device NOT exist, return STATUS_DEVICE_NOT_EXIST
	if (pxs_exist_flag == KAL_FALSE)
	{
		return STATUS_DEVICE_NOT_EXIST;
	}

	// Check allowed open number
	GET_DRIVER_SEMAPHORE(savedMask);
	if (pxs_open_count == PXS_MAX_OPEN_COUNT)
	{
		//ASSERT(0); // Only allow one user
		return DCL_HANDLE_OCCUPIED;
	}
	pxs_open_count ++;
	RELEASE_DRIVER_SEMAPHORE(savedMask);


	handle = (DCL_PXS_DEV_MAGIC_NUM | pxs_open_count);

	
	// After DclPXS_Open(), 
	{
		PXS_CONFIG_T HPXSConfig;
		HPXSConfig.fgNotify = DCL_TRUE;
		HPXSConfig.NotifyCallback = HPXS_Callback;
		DclHPXS_Configure(handle, (DCL_CONFIGURE_T *)(&HPXSConfig));
	}

	return handle;

}

/*************************************************************************
* FUNCTION
*  DclPXS_ReadData
*
* DESCRIPTION
*  This function is not supported for the PXS module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
DCL_STATUS DclPXS_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options)
{
	return STATUS_UNSUPPORTED;
}

/*************************************************************************
* FUNCTION
*  DclPXS_WriteData
*
* DESCRIPTION
*  This function is not supported for the PXS module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
DCL_STATUS DclPXS_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options)
{
	return STATUS_UNSUPPORTED;
}
/*************************************************************************
* FUNCTION
*  DclPXS_Configure
*
* DESCRIPTION
*  This function is to configure the PXS module.
*
* PARAMETERS
*  handle: the returned handle value of DclPXS_Open
*  configure: a structure which include the PXS configuration.
*
* RETURNS
*  STATUS_OK: Successfully configure PXS module.
*  STATUS_INVALID_DCL_HANDLE: It's a invalid handle.
*  STATUS_NOT_OPENED: The module has not been opened.
*  STATUS_INVALID_CONFIGURATION: The configuration is invalid.
*
*************************************************************************/
DCL_STATUS DclPXS_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{

	// Check magic number
	if ((handle & DCL_PXS_DEV_MAGIC_NUM_MASK) != DCL_PXS_DEV_MAGIC_NUM){
	//if ((handle & DCL_PXS_DEV_MAGIC_NUM) != DCL_PXS_DEV_MAGIC_NUM){
		//ASSERT(0);
		return STATUS_INVALID_DCL_HANDLE;
	}

	// If device NOT exist, return STATUS_DEVICE_NOT_EXIST
	if (pxs_exist_flag == KAL_FALSE)
	{
		return STATUS_DEVICE_NOT_EXIST;
	}

	// Error check
	if (pxs_open_count == 0){
		//ASSERT(0);
		return STATUS_NOT_OPENED;
	}

	// Check pointer
	if (configure == NULL)
	{
		//ASSERT(0);
		return STATUS_INVALID_CONFIGURATION;
	}

	{
		PXS_CONFIG_T *prPXSConfig;
		PXS_CONFIG_T HPXSConfig;
		prPXSConfig = (PXS_CONFIG_T *)(configure);

		if (prPXSConfig->fgNotify == DCL_TRUE)
		{
			// Check callback function
			if (prPXSConfig->NotifyCallback == NULL)
			{
				ASSERT(0);
				return STATUS_INVALID_CONFIGURATION;
			}

			PXSConfig.fgNotify = DCL_TRUE;
			PXSConfig.NotifyCallback = prPXSConfig->NotifyCallback;
		}
		else
		{
			PXSConfig.fgNotify = DCL_FALSE;
			PXSConfig.NotifyCallback = NULL;
		}
		//HPXSConfig.fgNotify = PXSConfig.fgNotify;
		HPXSConfig.fgNotify = DCL_TRUE;  // Always ask low level driver to callback
		                                 // Whether to call back to upper layer(MMI), let DCLPXS layer to decide
		HPXSConfig.NotifyCallback = HPXS_Callback;
		return 	DclHPXS_Configure(handle, (DCL_CONFIGURE_T *)(&HPXSConfig));
	}

	// return STATUS_OK;

}

/*************************************************************************
* FUNCTION
*  DclPXS_RegisterCallback
*
* DESCRIPTION
*  This function is to set callback function for the PXS module.
*
* PARAMETERS
*  handle: the returned handle value of DclPXS_Open
*  event: Supported events:
*  callback: the callback function for registered events
*
* RETURNS
*  STATUS_UNSUPPORTED
*
*************************************************************************/
DCL_STATUS DclPXS_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
	return STATUS_UNSUPPORTED;
}

/*************************************************************************
* FUNCTION
*  DclPXS_Control
*
* DESCRIPTION
*  This function is to send command to control the PXS module.
*
* PARAMETERS
*  handle: The handle value returned from DclPXS_Open
*  cmd: A control command for PXS module
*          1. PXS_CMD_ENABLE: to enable/disable PXS function
*          2. PXS_CMD_GET_RAW_DATA: to get PXS sampled raw data
*          3. PXS_CMD_EM_READ: to read EM parameters
*          4. PXS_CMD_EM_WRITE: to write EM parameters
*          5. PXS_CMD_GET_DETECT_STATUS: to get PXS detected status
*  data: The data of the control command
*          1. PXS_CMD_ENABLE: pointer to a PXS_CTRL_ENABLE_T structure
*          2. PXS_CMD_GET_RAW_DATA: pointer to a PXS_CTRL_RAW_DATA_T structure
*          3. PXS_CMD_EM_READ: pointer to a PXS_CTRL_EM_PARAM_T structure
*          4. PXS_CMD_EM_WRITE: pointer to a PXS_CTRL_EM_PARAM_T structure
*          5. PXS_CMD_GET_DETECT_STATUS: pointer to a PXS_CTRL_GET_DETECT_STATUS_T structure
*
* RETURNS
*  STATUS_OK: command is executed successfully.
*  STATUS_FAIL: command is failed.
*  STATUS_INVALID_CMD: It's a invalid command.
*
*************************************************************************/
DCL_STATUS DclPXS_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	// Check magic number
	if ((handle & DCL_PXS_DEV_MAGIC_NUM_MASK) != DCL_PXS_DEV_MAGIC_NUM){
		//ASSERT(0);
		return STATUS_INVALID_DCL_HANDLE;
	}

	// If device NOT exist, return STATUS_DEVICE_NOT_EXIST
	if (pxs_exist_flag == KAL_FALSE)
	{
		return STATUS_DEVICE_NOT_EXIST;
	}

	// Error check
	if (pxs_open_count == 0){
		//ASSERT(0);
		return STATUS_NOT_OPENED;
	}

	// Check pointer
	if (data == NULL)
	{
		//ASSERT(0);
		return STATUS_INVALID_CTRL_DATA;
	}

	switch (cmd)
	{
		case PXS_CMD_ENABLE:
		case PXS_CMD_GET_RAW_DATA:
		case PXS_CMD_EM_READ:
		case PXS_CMD_EM_WRITE:
		case PXS_CMD_SET_DEBOUNCE:
		{
			return DclHPXS_Control(handle, cmd, data);
		}
		case PXS_CMD_MODIFY_CONFIG:
		{
			PXS_CTRL_CONFIG_T *prPXSConfig;
			PXS_CTRL_CONFIG_T HPXSConfig;
			prPXSConfig = (PXS_CTRL_CONFIG_T *)(data);
			if (prPXSConfig->fgNotify == DCL_TRUE)
			{
				// Check callback function
				if (prPXSConfig->NotifyCallback == NULL)
				{
					ASSERT(0);
					return STATUS_INVALID_ARGUMENT;
				}

				PXSConfig.fgNotify = DCL_TRUE;
				PXSConfig.NotifyCallback = prPXSConfig->NotifyCallback;
			}
			else
			{
				PXSConfig.fgNotify = DCL_FALSE;
				PXSConfig.NotifyCallback = NULL;
			}
			HPXSConfig.fgNotify = DCL_TRUE;
			HPXSConfig.NotifyCallback = HPXS_Callback;
			return DclHPXS_Control(handle, cmd, (DCL_CTRL_DATA_T *)&HPXSConfig);
		}
		//break;
		case PXS_CMD_GET_DETECT_STATUS:
		{
			PXS_CTRL_GET_DETECT_STATUS_T *prPXSGetStatus;
			prPXSGetStatus = (PXS_CTRL_GET_DETECT_STATUS_T *)(data);
			prPXSGetStatus->fgDetected = pxs_detect_flag;
			return STATUS_OK;
		}
		default:
		{
			//ASSERT(0);
			return STATUS_INVALID_CMD;
		}
		//break;
	}

	//return STATUS_OK;
}

/*************************************************************************
* FUNCTION
*  DclPXS_Close
*
* DESCRIPTION
*  This function is to close the PXS module.
*
* PARAMETERS
*  handle: the returned handle value of DclPXS_Open
*
* RETURNS
*  STATUS_OK
*
*************************************************************************/
DCL_STATUS DclPXS_Close(DCL_HANDLE handle)
{
	DCL_CTRL_DATA_T data;

	// Check magic number
	if ((handle & DCL_PXS_DEV_MAGIC_NUM_MASK) != DCL_PXS_DEV_MAGIC_NUM){
		//ASSERT(0);
		return STATUS_INVALID_DCL_HANDLE;
	}

	// If device NOT exist, return STATUS_DEVICE_NOT_EXIST
	if (pxs_exist_flag == KAL_FALSE)
	{
		return STATUS_DEVICE_NOT_EXIST;
	}

	// Error check
	if (pxs_open_count == 0){
		//ASSERT(0);
		return STATUS_NOT_OPENED;
	}

	PXSConfig.fgNotify = DCL_FALSE;
	PXSConfig.NotifyCallback = NULL;

	data.rPXSEnable.fgEnable = DCL_FALSE;

	DclHPXS_Control(handle, PXS_CMD_ENABLE, &data);

	pxs_open_count --;

	return STATUS_OK;

}


#endif // #if defined(__PXS_ENABLE__)

