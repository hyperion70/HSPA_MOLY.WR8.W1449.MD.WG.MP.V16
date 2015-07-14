/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 *   custom_sds_dp.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Implementation of SDS data process callback function.
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
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#if !defined(__SDS_DP_ENABLE__)

//==============================================================================
// dummy function 
//==============================================================================
#include "custom_sds_dp.h"
const SDS_DP_Callback * SDS_DP_GetCallback(SDS_DP_TYPE  type)
{
    return NULL;
}

#else

#include "kal_debug.h"
#include "custom_sds_dp.h"
#include "che_api.h"

//==============================================================================
// customized arguments
//==============================================================================

const SDS_DP_MTK_AES_ARG  g_SDS_DP_MTK_AES_ARG={
    // customized key 
    { 0xDCF32377, 0x212AA47E, 0x4B056594, 0xFC8CD19C },
    // customized iv 
    { 0x31FDAB0D, 0xCD969432, 0x51B582CE, 0x131B05B0 }
};

typedef union SDS_DP_TempVar_U {
    STCHE       m_che_ctx;
    // add customized temp variable from here
} SDS_DP_TempVar_U;

//==============================================================================
// local functions
//==============================================================================
static void        SDS_DP_MTK_AES_GetInitInfo(kal_uint32 actual_src_len, kal_uint32 *p_occupied_src_len);
static kal_int32   SDS_DP_MTK_AES_Init(kal_uint32 attr, const void *p_arg, kal_uint32 *p_block_size);
static void        SDS_DP_MTK_AES_DeInit(kal_uint32 attr);
static kal_int32   SDS_DP_MTK_AES_Decrypt(kal_uint8 *p_dst, kal_uint32 actual_dst_len, kal_uint32 dst_offset, const kal_uint8 *p_src, kal_uint32 len);
static kal_int32   SDS_DP_MTK_AES_Encrypt(const kal_uint8 *p_src, kal_uint32 actual_src_len, kal_uint32 src_offset, kal_uint8 *p_dst, kal_uint32 len);

//==============================================================================
// customized data process callback table 
//==============================================================================

typedef struct SDS_DP_Entry {
    SDS_DP_TYPE             m_type;
    SDS_DP_Callback         m_cb;
} SDS_DP_Entry;

static const SDS_DP_Entry   g_SDS_DP_Table[]={
     { SDS_DP_MTK_AES,   { SDS_DP_MTK_AES_GetInitInfo, SDS_DP_MTK_AES_Init, SDS_DP_MTK_AES_DeInit, SDS_DP_MTK_AES_Decrypt,  SDS_DP_MTK_AES_Encrypt  } }

    // Add customized data processing method here 
    //,{ SDS_DP_MY_METHOD, { SDS_DP_MY_GetInitInfo, SDS_DP_MY_Init, SDS_DP_MY_DeInit, SDS_DP_MY_Read_PostProc, SDS_DP_MY_Write_PreProc } }
};

//==============================================================================
// local variables
//==============================================================================

static SDS_DP_TempVar_U     g_tmp_var_u;
static STCHE * const g_che_context = &(g_tmp_var_u.m_che_ctx);

//==============================================================================
// SDS data process exported APIs
//==============================================================================
const SDS_DP_Callback * SDS_DP_GetCallback(SDS_DP_TYPE  type)
{
    kal_uint32  i;
    for(i=0; i<(sizeof(g_SDS_DP_Table)/sizeof(SDS_DP_Entry)); i++)
    {
        // compare type 
        if( g_SDS_DP_Table[i].m_type == type )
        {
            return &(g_SDS_DP_Table[i].m_cb);
        }
    }
    return NULL;
}

//==============================================================================
// SDS data process (SDS_DP_MTK_AES)
//==============================================================================
void  SDS_DP_MTK_AES_GetInitInfo(kal_uint32 actual_src_len, kal_uint32 *p_occupied_src_len)
{
    kal_uint32  occupied_src_len;
    kal_uint32  remainder;

    // if actual_src_len is not multiple of 16B(128b), extend occupied_src_len to be multiple of 16B 
    remainder = (actual_src_len&(16-1));
    if( 0 != remainder )
    {
        occupied_src_len = (actual_src_len - remainder + 16);
    }
    else
    {
        occupied_src_len = actual_src_len;
    }

    // fill output arguments
    *p_occupied_src_len = occupied_src_len;
}

kal_int32  SDS_DP_MTK_AES_Init(kal_uint32 attr, const void *p_arg, kal_uint32 *p_block_size)
{
    const SDS_DP_MTK_AES_ARG *p_aes_arg=(const SDS_DP_MTK_AES_ARG *)p_arg;    

    // if user argument is NULL, using default arg 
    if( NULL == p_aes_arg )
    {
        p_aes_arg = &g_SDS_DP_MTK_AES_ARG;
    }

    // init 
    che_init(g_che_context, CHE_AES);
    // set key 
    che_key_action(g_che_context, CHE_SET_KEY, (kal_uint8 *)p_aes_arg->m_key, sizeof(p_aes_arg->m_key));
    // set iv
    che_set_iv(g_che_context, (kal_uint8 *)p_aes_arg->m_iv, sizeof(p_aes_arg->m_iv));

    // fill output arguments
    *p_block_size = 16;

    return 0;
}

void  SDS_DP_MTK_AES_DeInit(kal_uint32 attr)
{
    // de-init 
    che_deinit(g_che_context);
}

kal_int32  SDS_DP_MTK_AES_Decrypt(kal_uint8 *p_dst, kal_uint32 actual_dst_len, kal_uint32 dst_offset, const kal_uint8 *p_src, kal_uint32 len)
{
    kal_uint32  tmp_blk[16>>2];
    kal_uint8  *p_data_src;
    kal_uint8  *p_data_dst;
    kal_uint32  data_len;
    kal_uint32  remainder=0;
    kal_int32   ret=0;
    kal_bool    bResult;

    p_data_src = (kal_uint8 *)p_src;
    p_data_dst = (p_dst+dst_offset);
    data_len = len;

    // src and dst address must be 4B aligned due to CHE library requirement 
    if( 0 != (((kal_uint32)p_data_src)&(4-1)) )
    {
        ret = -1;
        goto __end;
    }
    if( 0 != (((kal_uint32)p_data_dst)&(4-1)) )
    {
        ret = -2;
        goto __end;
    }

    // check if last block 
    if( actual_dst_len <= (dst_offset+data_len) )
    {
        data_len = (actual_dst_len - dst_offset);

        // if data_len is not multiple of 16B(128b), record remainder length 
        remainder = (data_len&(16-1));
        if( 0 != remainder )
        {
            data_len = (data_len - remainder);
        }
    }
    else
    {
        // if not last block, process data_len must multiple of 16B 
        if( 0 != (data_len&(16-1)) )
        {
            ret = -3;
            goto __end;
        }
    }

    // decrypt block by block 
    if( 0 < data_len )
    {
        // CHE auto padding is disabled 
        bResult = che_process(g_che_context, CHE_AES, CHE_CBC, CHE_DEC, p_data_src, p_data_dst, data_len, KAL_FALSE);
        if(!bResult)
        {
            ret = -4;
            goto __end;
        }

        // update pointer 
        p_data_src += data_len;
        p_data_dst += data_len;
    }

    // decrypt remainder 
    if( 0 < remainder )
    {
        // CHE auto padding is disabled 
        // decrypt remainder to temp buffer 
        bResult = che_process(g_che_context, CHE_AES, CHE_CBC, CHE_DEC, p_data_src, (kal_uint8 *)tmp_blk, 16, KAL_FALSE);
        if(!bResult)
        {
            ret = -5;
            goto __end;
        }

        // copy remainder from temp buffer to destination 
        memcpy(p_data_dst, tmp_blk, remainder);
    }

__end:

    // assert error case 
    ASSERT( 0 <= ret );

    return ret;
}

kal_int32  SDS_DP_MTK_AES_Encrypt(const kal_uint8 *p_src, kal_uint32 actual_src_len, kal_uint32 src_offset, kal_uint8 *p_dst, kal_uint32 len)
{
    kal_uint8  *p_data_src;
    kal_uint8  *p_data_dst;
    kal_uint32  data_len;
    kal_uint32  remainder=0;
    kal_int32   ret=0;
    kal_bool    bResult;

    p_data_src = (kal_uint8 *)(p_src+src_offset);
    p_data_dst = p_dst;
    data_len = len;

    // src and dst address must be 4B aligned due to CHE library requirement 
    if( 0 != (((kal_uint32)p_data_src)&(4-1)) )
    {
        ret = -1;
        goto __end;
    }
    if( 0 != (((kal_uint32)p_data_dst)&(4-1)) )
    {
        ret = -2;
        goto __end;
    }

    // check if last block 
    if( actual_src_len <= (src_offset+data_len) )
    {
        data_len = (actual_src_len - src_offset);

        // if data_len is not multiple of 16B(128b), make it aligns to 16B 
        remainder = (data_len&(16-1));
        if( 0 != remainder )
        {
            data_len = (data_len - remainder + 16);
        }

        // check if dst has enough space for encryption 
        if( data_len > len )
        {
            ret = -3;
            goto __end;
        }
    }
    else
    {
        // if not last block, process data_len must multiple of 16B 
        if( 0 != (data_len&(16-1)) )
        {
            ret = -4;
            goto __end;
        }
    }

    // encrypt data 
    // CHE auto padding is disabled 
    bResult = che_process(g_che_context, CHE_AES, CHE_CBC, CHE_ENC, p_data_src, p_data_dst, data_len, KAL_FALSE);
    if(!bResult)
    {
        ret = -5;
        goto __end;
    }

__end:

    // assert error case 
    ASSERT( 0 <= ret );

    return ret;
}

#endif // ! __SDS_DP_ENABLE__

#if defined(__MTK_INTERNAL__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__SDS_DP_UT_WITH_CBR__)
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
/* under construction !*/
#endif

