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
 *   ccci_misc_info_api.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Query function prototype and return value definition
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

#ifndef __CCCI_MISC_INFO_QUERY_H__
#define __CCCI_MISC_INFO_QUERY_H__

#if defined(__MODEM_CCCI_EXIST__) && !defined(__SDIO_DEVICE_CONNECTIVITY__) && defined(CCCI_INIT_HANDSHAKE_MODE1)

#define CCCI_MISC_INFO_DATA_SIZE                (16)
#define CCCI_MISC_INFO_STRUCT_PATTERN           (0x46494343)    /* - ASCII of "CCIF" */
#define CCCI_MISC_INFO_NUMBER_IN_STRUCT         (16)
#define CCCI_MISC_INFO_RET_MASK                 (0x3)

/* each feature uses two bits to represent its support type */
#define CCCI_MISC_INFO_RET_OFF(op_id)           (((op_id) % CCCI_MISC_INFO_NUMBER_IN_STRUCT) * 2)
#define CCCI_MISC_INFO_INDEX_TRANSFORM(op_id)   (op_id % CCCI_MISC_INFO_NUMBER_IN_STRUCT)

/*******************************************************************************
 * Define data structures.
 *******************************************************************************/
typedef struct
{
    kal_uint32 ap_data[CCCI_MISC_INFO_DATA_SIZE  / sizeof(kal_uint32)];
} ccci_misc_info_return_t;

typedef struct
{
    kal_uint32              prefix;
    kal_uint32              support_mask;
    kal_uint32              index;
    kal_uint32              next;
    ccci_misc_info_return_t feature_data[CCCI_MISC_INFO_NUMBER_IN_STRUCT];
    kal_uint32              reserved_2[3];
    kal_uint32              postfix;
} ccci_misc_info_t;


#endif /* __SMART_PHONE_MODEM__ && CCCI_INIT_HANDSHAKE_MODE1 !__SDIO_DEVICE_CONNECTIVITY__ */

#endif /* __CCCI_MISC_INFO_QUERY_H__ */
