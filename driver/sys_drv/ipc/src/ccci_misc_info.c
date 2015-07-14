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
 *   ccci_misc_inf.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Functons used to query information in misc info runtime data.
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
 *
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

#include "kal_public_api.h"
#include "ccci.h"
#include "ccci_misc_info.h"

#if defined(__MODEM_CCCI_EXIST__) && !defined(__SDIO_DEVICE_CONNECTIVITY__) && defined(CCCI_INIT_HANDSHAKE_MODE1)

/**************************************************************************
* FUNCTION
*  ccci_misc_info_feature_support
*
* DESCRIPTION
*  This function returns wheteher a feature in CCCI misc info is supported,
*  and copy the output data if required.
*
* PARAMETERS
*  op_id        -    Feature ID.
*  len          -    Length of output data
*  pReturn      -    Pointer to output.
*
* RETURNS
*  CCCI_INVALID_PARAM         - Invalid input parameter
*  CCCI_MISC_INFO_NOT_EXIST   - Feature doesn't exist on AP side.
*  CCCI_MISC_INFO_NOT_SUPPORT - Feature exists, but not supported.
*  CCCI_MISC_INFO_EXIST       - Feature is supported.
*
**************************************************************************/
kal_int32 ccci_misc_info_feature_support(kal_uint32 op_id, kal_uint32 len, void *pReturn)
{
    kal_uint32       ret;
    ccci_misc_info_t *ptr;


    if(op_id >= CCCI_MISC_INFO_QUERY_END || len >= CCCI_MISC_INFO_DATA_SIZE)
        return CCCI_INVALID_PARAM;

    /* If caller request to copy data to a NULL pointer, return fail */
    if(len != 0 && !pReturn)
        return CCCI_INVALID_PARAM;


    /* Get corresponding misc info structure */
    ptr = (ccci_misc_info_t *)(ap_md_share_data.MiscInfoBase) + (op_id / CCCI_MISC_INFO_NUMBER_IN_STRUCT);

    /* AP doesn't fill the prefix, meaning this misc_info_t is not valid */
    if(ptr->prefix != CCCI_MISC_INFO_STRUCT_PATTERN)
        return CCCI_MISC_INFO_NOT_EXIST;


    /* get return value from shared memory */
    ret = (ptr->support_mask >> (CCCI_MISC_INFO_RET_OFF(op_id))) & CCCI_MISC_INFO_RET_MASK;

    /* copy output parameter */
    if(len != 0 && CCCI_MISC_INFO_SUPPORT == ret)
    {
        kal_mem_cpy(pReturn, &ptr->feature_data[CCCI_MISC_INFO_INDEX_TRANSFORM(op_id)].ap_data, len);
    }

    return (kal_int32)ret;
}

#endif    /* CCCI_INIT_HANDSHAKE_MODE1 */
