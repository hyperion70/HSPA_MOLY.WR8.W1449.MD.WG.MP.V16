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
 *   rtfiles.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file contains core functions of file system.
 *
 * Author:
 * -------
 *
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
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
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
 * removed!
 *
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
 *
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/**************************************************************************/
/*                                                                        */
/*  File: RTFILES.C                              Copyright (c) 1998,2002  */
/*  Version: 4.0                                 On Time Informatik GmbH  */
/*                                                                        */
/*                                                                        */
/*                                      On Time        /////////////----- */
/*                                    Informatik GmbH /////////////       */
/* --------------------------------------------------/////////////        */
/*                                  Real-Time and System Software         */
/*                                                                        */
/**************************************************************************/

#include <stdlib.h>
#include <string.h>
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "kal_internal_api.h"
#include "fs_internal_def.h"
#include "fs_gprot.h"
#include "rtfiles.h"
#include "fs_kal.h"
#include "rtfex.h"
#include "rtfbuf.h"
//MSBB remove #include "app_buff_alloc.h"
//#include "Conversions.h"
#include "fs_utility.h"
#include "fs_internal.h"
#include "fs_internal_api.h"
#include "kal_trace.h"
#include "fs_trc.h"             // "stack_config.h" is included by "kal_release.h"
#include "fs_task.h"
#include "wchar.h"
#include "setjmp.h"
#include "SST_sla.h"            // for SWLA hooker

// temoprary release all FS APIs for ULC projects
#if defined(__FS_PROPRIETARY_SET__)
    #undef __FS_PROPRIETARY_SET__
#endif

#ifdef _MSC_VER
   #define INTERN _fastcall
#elif defined __BORLANDC__
   #define INTERN __fastcall
#else
   #define INTERN
#endif

// Trace
#define fs_util_trace_err_noinfo(error_code) fs_util_trace_err_slim(error_code, rtfiles_c, __LINE__)


// Assert
#define fs_assert_local(expr) fs_assert(expr, rtfiles_c)
#define fs_ext_assert_local(expr, e1, e2, e3) fs_ext_assert(expr, rtfiles_c, e1, e2, e3)

#define DIR_COMPACT_SUPPORT   // comment out if you do not need this
#define CHECK_DISK_SUPPORT    // comment out if you do not need this


typedef struct DiskCheckData {
   kal_uint32             Flags;
   RTFDrive             * Drive;
   BYTE                 * S;
   BYTE                 * ClusterMap;
   RTFCheckDiskCallback   ErrorHandler;
   RTFDOSDirEntry         D;
   char                   Path[RTF_MAX_PATH];
} DiskCheckData;


static RTFDrive * DefaultDrive = NULL;
extern RTFMutex * RTFLock;

/***********************************************************************/

#if (defined __FS_SYSDRV_ON_NAND__) && !(defined _NAND_FLASH_BOOTING_) && !(defined __EMMC_BOOTING__)
        /* Treat __FS_SYSDRV_ON_NAND__ equal _NAND_FLASH_BOOTING_ */
#define _NAND_FLASH_BOOTING_
#endif

//---------------------- MT Global Data --------------------------
int DrvMappingOld = 67; //default is C
int DrvMappingNew = 90; //default is Z
int SysLockFAT = 0; /* For USB mode to lock FS, Karen Hsu, 2004/10/19, ADD */
int CardBusyCheck = 0;
char gFS_Export = FS_NOT_EXPORTED;
kal_taskid gFS_ExportOwnerTaskID = KAL_NILTASK_ID;

#if defined(__MTP_ENABLE__)
void *SysLockFATTask = 0;
#endif /* __MTP_ENABLE__ */

int SysBlockFAT = 1; //don't use compile option for easy customization

RTFMutex *MTFMLock = NULL;

RTFMutex *MTXLock = NULL;

RTFMutex *MTMoveLock = NULL;

RTFMutex *MTXdelLock = NULL;

#ifdef __FS_SORT_SUPPORT__
   RTFMutex *MTSortLock = NULL;
#endif

RTTDLL RTFMutex *MTDiskInfoLock = NULL;

extern kal_bool  NorPartition;
extern kal_bool  NandPartition;

#ifdef __FS_QM_SUPPORT__
   WCHAR NvramName[6];
#endif

kal_bool COPYRIGHT_USB_ON = KAL_FALSE; //speedup, don't wrap with compile option flag
#ifdef __P_PROPRIETARY_COPYRIGHT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/* For Virtual File Feature */
const static WCHAR dchar_HexDigits[]= /* 0123456789ABCDEF */
   {0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46};

const static WCHAR dchar_virtual_filename_prefix[]= /* \\.\FMapF\ */
   {0x5C, 0x5C, 0x2E, 0x5C, 0x46, 0x4D, 0x61, 0x70, 0x46, 0x5C, 0x0};

#ifdef __FS_SHADOW_NAND_32M__
   #define NUM_OF_FAT_CLUSTER_NAND 65536    //worst case needs 256KB
#elif defined __FS_SHADOW_NAND_64M__
   #define NUM_OF_FAT_CLUSTER_NAND 131072   //worst case needs 512KB
#elif defined __FS_SHADOW_NAND_128M__
   #define NUM_OF_FAT_CLUSTER_NAND 131072   //worst case needs 512KB
#elif defined __FS_SHADOW_NAND_256M__
   #define NUM_OF_FAT_CLUSTER_NAND 262144   //worst case needs 1MB
#elif defined __FS_SHADOW_NAND_512M__
   #define NUM_OF_FAT_CLUSTER_NAND 262144   //worst case needs 1MB
#elif defined __FS_SHADOW_NAND_1G__
   #define NUM_OF_FAT_CLUSTER_NAND 524288   //worst case needs 2MB
#endif

#ifdef __FS_SHADOW_CARD_32M__
   #define NUM_OF_FAT_CLUSTER_CARD 65536    //worst case needs 256KB
#elif defined __FS_SHADOW_CARD_64M__
   #define NUM_OF_FAT_CLUSTER_CARD 131072   //worst case needs 512KB
#elif defined __FS_SHADOW_CARD_128M__
   #define NUM_OF_FAT_CLUSTER_CARD 131072   //worst case needs 512KB
#elif defined __FS_SHADOW_CARD_256M__
   #define NUM_OF_FAT_CLUSTER_CARD 262144   //worst case needs 1MB
#elif defined __FS_SHADOW_CARD_512M__
   #define NUM_OF_FAT_CLUSTER_CARD 262144   //worst case needs 1MB
#elif defined __FS_SHADOW_CARD_1G__
   #define NUM_OF_FAT_CLUSTER_CARD 524288   //worst case needs 2MB
#endif

#if (defined(__FS_SHADOW_NAND__) || defined(__FS_SHADOW_CARD__))
#pragma arm section zidata = "SHADOW_FAT"

#ifdef __FS_SHADOW_NAND__
#ifndef NUM_OF_FAT_CLUSTER_NAND
#error "Size of NAND, __FS_SHADOW_NAND_xxx__, is not defined!"
#endif
   UINT Shadow_FAT_Array_NAND[NUM_OF_FAT_CLUSTER_NAND];
#endif

#ifdef __FS_SHADOW_CARD__
#ifndef NUM_OF_FAT_CLUSTER_CARD
#error "Size of CARD, __FS_SHADOW_CARD_xxx__, is not defined!"
#endif
   UINT Shadow_FAT_Array_CARD[NUM_OF_FAT_CLUSTER_CARD];
#endif

#pragma arm section zidata
#endif


/* Sub Mark = Sub Watermark, store on FAT32 InfoSector.
 * Design to get faster respone in Free Cluster Search wrost case, especially on Large Disk
 */
#define SUBMARK_ID_SHIFT   (16)
#define SUBMARK_MASKOUT    (0xFFFF0000)
#define SUBMARK_MASK       (0x0000FFFF)
#define SUBMARK_LASTNUM    (119)

/* Directory Associated Cache Value, store run-time cache
 * Design to get faster respone for browsing application, especially on Large Directory case
 */

#define FS_DIRDATA_NUM  (8)
FS_DirDataStruct    _gfs_dir_data[FS_DIRDATA_NUM];

//---------------------- MT Global Static Func --------------------------

#ifdef __FS_QM_SUPPORT__
   static void  GetQuotaEntry(int * Index, RTFile * f);
   static int   QMPermitAllocate(UINT DriveFree, int Index, UINT NeedCluster);
#endif

#if (defined(__FS_SHADOW_NAND__) || defined(__FS_SHADOW_CARD__))
static void InitShadowFAT(RTFDrive *Drive);
static void FlushShadowFAT(void);
#endif

static void INTERN SetupFMapF_FileHandle(RTFile *f);
static int MTChkMapedFH(RTFHANDLE File);
static RTFCluster INTERN FATSearchZeroInBuffer(RTFDrive *Drive, RTFCluster Cluster);
#if !defined(__NOT_SUPPORT_FAT32__)
static void INTERN FATHoistSubMark(RTFDrive *Drive, RTFCluster Begin, RTFCluster End);
static void INTERN FATLowerSubMark(RTFDrive *Drive, RTFCluster Begin, RTFCluster End);
static void INTERN FATInitInfoSectorSubMark(RTFDrive *Drive);
static RTFCluster INTERN FATHintSearchBySubMark(RTFDrive * Drive, RTFCluster Cluster, int MarkFlag);
#endif /* __NOT_SUPPORT_FAT32__ */

//---------------------- MT Global Extern Func --------------------------
extern kal_bool INT_QueryExceptionStatus(void);
extern kal_uint32 INT_GetCurrentTime(void);
extern void *kal_tmp_mem_alloc(kal_uint32 size);
extern void kal_tmp_mem_free(void *mem_ptr);

extern UINT       OpenHintStamp;
#ifdef __FS_OPEN_HINT__
BYTE              gFS_OpenHintStampCeil = 0;
#endif

//static fs_block_type_enum fs_block_type = FS_BLOCK_ENUM; /* Fix multi-access bug, Karen Hsu, 2004/07/08, REM */
extern int        TLSBlockIndex;

BYTE          RTFAPI _rtfLock(BYTE * Lock); // Temp = *Lock;  *Lock = 1; return Temp;
static void   INTERN IncShortName(char * ShortName);


/*******************************************************************//**
 * Check file names validity (check the last filename component only!)
 * This function is similar to kal_wstrncpy(), but append only one NULL in destination string.
 *
 * @Change Log
 * W09.12: Add leading '.' checking (Stanley Chu)
 *
 * @par Category:
 * File System
 *
 * @Remarks
 * In case of "X:\\FolderName\", "FolderName" will NOT be checked.
 **********************************************************************/
int RTFAPI CheckValidVolumeLabel(const WCHAR * Label)
{
    const WCHAR *p = Label;
    int         count;
    int         failed;

    /*------------------------------------
     * Check invalidity of all characters
     *------------------------------------*/

    for (count = 0 ;*p != 0x0; p++, count++)
    {
        if (count >= 11)
        {
            fs_util_trace_info0(TRACE_ERROR, FS_ERR_VOLUMELABEL_TOO_LONG, NULL);

            XRAISE(FS_INVALID_FILENAME);
        }

        failed = 0;

        if (*p < 0x80)  // ASCII
        {
            if (!fs_util_validate_sfn_char(*p))
            {
                failed = 1;
            }
        }
        else    // not ASCII
        {
            if (0xFFFF == fs_util_uni_to_native(*p))
            {
                failed = 1;
            }
        }

        if (failed)
        {
            fs_util_trace_info1(TRACE_ERROR, FS_ERR_FILENAME_INVALID_CHAR, (kal_uint32)*p, NULL);

            XRAISE(FS_INVALID_FILENAME);
        }
    }

    return FS_NO_ERROR;
}

WCHAR* RTFAPI CheckValidFileName2(const WCHAR * FileName, kal_bool bCheckLeading)
{
    int         result = FS_NO_ERROR;
    const WCHAR *p;

    do
    {
        // locate the last '\'
        p = kal_wstrrchr(FileName, 0x005C);

        if (p == NULL)
        {
            p = FileName;
        }
        else
        {
            p++;
        }

        /*--------------------------
         * Check leading characters
         *--------------------------*/

        if (bCheckLeading && ((*p == 0x20) || (*p == 0x2E)))  // check ' ' and '.'
        {
            //fs_util_trace_info0(TRACE_ERROR, FS_ERR_FILENAME_INVALID_LEADING_BLANK, NULL);

            result = FS_INVALID_FILENAME;

            break;
        }

        /*------------------------------------
         * Check invalidity of all characters
         *------------------------------------*/

        for ( ;*p != 0x0; p++)
        {
            if (!fs_util_validate_lfn_char(*p) || *p == 0xFFFF /* UCS2 convert failure mark, WCP_SW, 2005/11/17*/)
            {
                fs_util_trace_info1(TRACE_ERROR, FS_ERR_FILENAME_INVALID_CHAR, (kal_uint32)*p, NULL);

                result = FS_INVALID_FILENAME;

                break;  // leave for-loop
            }
        }

        if (result < FS_NO_ERROR)
        {
            break;  // leave do-loop
        }

        /*--------------------------
         * Check tailing characters
         *--------------------------*/

        // '.' is not allowed in the last char
        p--;

        if (*p == 0x2E)
        {
            //fs_util_trace_info0(TRACE_ERROR, FS_ERR_FILENAME_INVALID_TAILING_DOT, NULL);

            result = FS_INVALID_FILENAME;

            break;
        }

        break;

    } while (1);

    if (result < FS_NO_ERROR)
    {
        fs_util_trace_err_noinfo(result);

        XRAISE(result);
    }

    return (WCHAR*)p;
}

void RTFAPI CheckValidFileName(const WCHAR * FileName)
{
   CheckValidFileName2(FileName, KAL_TRUE);
}

/*-----------------------------------*/
static int INTERN ShutDown(RTFDevice * Dev)
{
   int volatile Result;
   RTFSYSFreeMutex(RTFLock);
   XTRY
      case XCODE:
         CheckMedia(Dev);
         Result = Dev->Driver->ShutDown(Dev->DriverData);
         break;
      default:
         Result = XVALUE;
         XHANDLED;
         break;
      case XFINALLY:
         RTFSYSLockMutex(RTFLock, RTF_INFINITE);
         break;
   XEND
   return Result;
}

/*-----------------------------------*/
static int INTERN DiscardSectors(RTFDevice * Dev, RTFSector Sector, RTFSector Sectors)
{
   int volatile Result;
   RTFSYSFreeMutex(RTFLock);
   XTRY
      case XCODE:
         CheckMedia(Dev);
         if (Dev->DevData.MountState < Initialized)
            Result = RTF_DRIVE_NOT_READY;
         else
            if (Dev->Driver->DiscardSectors)
               Result = Dev->Driver->DiscardSectors(Dev->DriverData, Sector, Sectors);
            else
               Result = RTF_UNSUPPORTED_DRIVER_FUNCTION;
         break;
      default:
         Result = XVALUE;
         XHANDLED;
         break;
      case XFINALLY:
         RTFSYSLockMutex(RTFLock, RTF_INFINITE);
         break;
   XEND
   return Result;
}
/*-----------------------------------*/
static int INTERN LowLevelFormat(RTFDevice * Dev, const char * DeviceName, RTFFormatCallback Progress, kal_uint32 Flags)
// assume NO_RAISE NO_CRITICAL
{
   int volatile Result;
   RTFSYSFreeMutex(RTFLock);
   XTRY
      case XCODE:
         CheckMedia(Dev);
         /* Add for MSDC, Karen Hsu, 2004/02/11, ADD START */
         if (!Dev->Driver->LowLevelFormat)
         {
            Result = RTF_UNSUPPORTED_DRIVER_FUNCTION;
            break;
         }
         /* Add for MSDC, Karen Hsu, 2004/02/11, ADD END */
         if (Dev->DevData.MountState < Initialized)
            Result = RTF_DRIVE_NOT_READY;
         else
            if (Dev->Driver->LowLevelFormat)
               Result = Dev->Driver->LowLevelFormat(Dev->DriverData, DeviceName, Progress, Flags);
            else
               Result = RTF_UNSUPPORTED_DRIVER_FUNCTION;
         break;
      default:
         Result = XVALUE;
         XHANDLED;
         break;
      case XFINALLY:
         RTFSYSLockMutex(RTFLock, RTF_INFINITE);
         break;
   XEND
   return Result;
}

/*-----------------------------------*/
static int INTERN FindDevice(RTFDevice * * D, int DeviceIndex, MountStates State)
{
   RTFDevice * Dev;
   int i;

   fs_init();

   for (i=0; i<=DeviceIndex; i++)
      if (gFS_DeviceList[i].DeviceType == 0)
         return RTF_DRIVE_NOT_FOUND;

   *D = Dev = gFS_DeviceList + DeviceIndex;

   LockDevice(Dev, 0);
   if (Dev->DevData.MountState < State)
   {
      i = rtf_core_mount_device(Dev, NO_RAISE | NO_CRITICAL);
      if ((i < RTF_NO_ERROR) || (Dev->DevData.MountState < State))
      {
         UnlockDevice(Dev);
         return (i < RTF_NO_ERROR) ? i : RTF_INVALID_FILE_SYSTEM;
      }
      else
         return i;
   }
   else
      return RTF_NO_ERROR;
}

/*-----------------------------------*/
int RTFAPI RTFRawLowLevelFormat(int DeviceIndex, const WCHAR * DeviceName, RTFFormatCallback Progress, kal_uint32 Flags)
{
   RTFDevice * Dev = NULL; /* Remove RVCT warning, Karen Hsu, 2004/11/02, MOD */
   int Result = FindDevice(&Dev, DeviceIndex, Initialized);

   if (Result >= RTF_NO_ERROR)
   {
      Result = LowLevelFormat(Dev, (char *)DeviceName, Progress, Flags);
      UnlockDevice(Dev);
   }
   return Result;
}

/*-----------------------------------*/
static RTFile * INTERN ReserveFTSlot(void)
// not protected by any mutex!
{
    int i;
    RTFile * f = gFS_Data.FileTable;

    fs_init();

    /* find a free file table (by checking if f->Lock is 0) */
    for (i = 0; i < FS_MAX_FILES; i++, f++)
    {
        if (_rtfLock(&f->Lock) == 0)
        {
            if (fs_job_register_fh((FS_File*)f) == KAL_FALSE)
            {
                FreeFTSlot(f);

                fs_util_trace_err_noinfo(FS_ABORTED_ERROR);

                XRAISE(FS_ABORTED_ERROR);
            }

            return f;
        }
    }

   /*
    * No file handle is available!
    *
    * If file table is exhausted, use the last file handle for exception log
    * read/write.
    *
    * It is confirmed that NVRAM will use at most 1 file handle in exception mode.
    */
    if (INT_QueryExceptionStatus() == KAL_TRUE)
    {
        f = gFS_Data.FileTable + FS_MAX_FILES - 1;     // get the last file slot
        FreeFTSlot(f);                                 // clear it
        _rtfLock(&f->Lock);                            // set f->Lock

        if (fs_job_register_fh((FS_File*)f) == KAL_FALSE)
        {
            FreeFTSlot(f);

            fs_util_trace_err_noinfo(FS_ABORTED_ERROR);

            XRAISE(FS_ABORTED_ERROR);
        }

        return f;
   }

    fs_util_trace_err_noinfo(RTF_TOO_MANY_FILES);
    i=fs_util_trace_print_file_hanlde_consumer(NULL, TRACE_ERROR); // Get the LR of the top FH consumer
    fs_err_user_fatal(FS_ERR_HANDLE_01, (void*)i);                 // Fatal error 0xA01 with LR

    return NULL;
}

/*-----------------------------------*/
/* Note that this routine is only called by RTFRead and RTFWrite.
    That is, when a file is opened in non-blocking mode, only read/write
    will be affected. Other APIs, like RTFSeek, RTFTruncate, etc., will still be blocking.

    Option: FS_NONBLOCK_MOE: Non-block mode will be used if f->Flags also sets FS_NONBLOCK_MODE
*/
RTFile * RTFAPI ParseFileHandleEx(RTFHANDLE File, kal_uint32 Option)
{
    UINT U = File >> (4 * sizeof(int));
    UINT i = File & ((1 << (4 * sizeof(int))) - 1);
    RTFile *f;
    RTFDevice *Dev;

    if (File <= FS_NO_ERROR)
    {
        XRAISE(FS_INVALID_FILE_HANDLE);
    }

    if (i >= FS_MAX_FILES)
    {
        fs_util_trace_err_noinfo(RTF_INVALID_FILE_HANDLE);
        fs_util_trace_info2(TRACE_ERROR, FS_ERR_NBPARSEFH_OUT_OF_RANGE, i, FS_MAX_FILES, NULL);

        XRAISE(RTF_INVALID_FILE_HANDLE);
    }

    f = gFS_Data.FileTable + i;

    if (f->Lock == 0)
    {
        fs_util_trace_err_noinfo(RTF_INVALID_FILE_HANDLE);
        fs_util_trace_info1(TRACE_ERROR, FS_ERR_NBPARSEFH_UNLOCKED, i, NULL);

        XRAISE(RTF_INVALID_FILE_HANDLE);
    }

    if (f->Unique != U)
    {
        fs_util_trace_err_noinfo(RTF_INVALID_FILE_HANDLE);
        fs_util_trace_info1(TRACE_ERROR, FS_ERR_NBPARSEFH_UNIQUE_NOT_MATCHED, i, NULL);

        XRAISE(RTF_INVALID_FILE_HANDLE);
    }

    Dev = f->Dev;

    if (Dev == NULL)
    {
        fs_util_trace_err_noinfo(RTF_INVALID_FILE_HANDLE);
        fs_util_trace_info1(TRACE_ERROR, FS_ERR_NBPARSEFH_NULL_DEV, i, NULL);

        XRAISE(RTF_INVALID_FILE_HANDLE);
    }

    /* get device and system lock */
    if (Option == FS_NONBLOCK_MODE && f->Flags & FS_NONBLOCK_MODE)
    {
        // use non-blocking mode, if lock failed, exception will be raised.
        LockDevice(Dev, f->Flags);
    }
    else
    {
        // remove FS_NONBLOCK_MODE because non-blocking lock is NOT allowed
        LockDevice(Dev, (f->Flags & ~FS_NONBLOCK_MODE));
    }

    // now we get both device and system lock

    // we have to wait at the lock. If someone closed the file
    // in the mean time, bail out
    if ((f->Lock == 0) || (f->Unique != U) || (Dev != f->Dev))
    {
        UnlockDevice(Dev);

        fs_util_trace_err_noinfo(RTF_INVALID_FILE_HANDLE);
        fs_util_trace_info1(TRACE_ERROR, FS_ERR_NBPARSEFH_INVALID_AFTER_DEV_LOCKED, i, NULL);

        XRAISE(RTF_INVALID_FILE_HANDLE);
    }

    /* Add for usb normal mode access, , 2005/12/01, ADD START */
    /* align and simplify USB & Removable file handle processing, 2006/10/20, MOD START */
    if (f->Valid == FS_FH_EXPORTED)
    {
        fs_util_trace_err_noinfo(MT_DEVICE_EXPORTED_ERROR);
        fs_util_trace_info1(TRACE_ERROR, FS_ERR_NBPARSEFH_EXPORTED, i, NULL);

        FreeFTSlot(f);
        UnlockDevice(Dev);

        XRAISE(MT_DEVICE_EXPORTED_ERROR);
    }

    /* align and simplify USB & Removable file handle processing, 2006/10/20, MOD END */
    /* Add for usb normal mode access, , 2005/12/01, ADD END */
    if (f->Valid == FS_FH_MEDIACHANGED)
    {
        fs_util_trace_err_noinfo(RTF_MEDIA_CHANGED);
        fs_util_trace_info1(TRACE_ERROR, FS_ERR_NBPARSEFH_MEDIA_CHANGED, i, NULL);

        FreeFTSlot(f);
        UnlockDevice(Dev);

        XRAISE(RTF_MEDIA_CHANGED);
    }

    return f;
}

/*-----------------------------------*/
// Count the number of file handle by Device
// note that f->Valid don't care
static int INTERN FileCount(RTFDevice * Dev)
{
   UINT Count = 0;
   UINT i;
   RTFile * f = gFS_Data.FileTable;

   for (i=0; i<FS_MAX_FILES; i++, f++)
      if (f->Drive && (f->Dev == Dev))
         Count++;
   return Count;
}

/*-----------------------------------*/
// Count the number of file handle by Drive
// note it was usd by RTFClose() for Volumn file thus f->Valid do care
static int INTERN FileCountDrive(RTFDrive * Drive)
{
   UINT Count = 0;
   UINT i;
   RTFile * f = gFS_Data.FileTable;

   for (i=0; i<FS_MAX_FILES; i++, f++)
   {
      if (f->Drive == Drive && f->Valid == FS_FH_VALID)
      {
         Count++;
      }
   }
   return Count;
}

/*-----------------------------------*/
RTFile * RTFAPI FindSharing(const WCHAR *filename, RTFDirLocation *pos)
{
   UINT i;
   RTFile * f = gFS_Data.FileTable;

   for (i=0; i<FS_MAX_FILES; i++, f++)   {
        if ((f->Valid) && (f->SpecialKind == NormalFile))   {
           if (kal_wstrcmp(filename, (WCHAR*)f->FullName)==0)  {
                if (f->DirEntry.LongPos.Cluster != 0)   {
                    pos->Cluster = f->DirEntry.LongPos.Cluster;
                    pos->Index = f->DirEntry.LongPos.Index;
                }
                else {
                    pos->Cluster = f->DirEntry.ShortPos.Cluster;
                    pos->Index = f->DirEntry.ShortPos.Index;
                }
                return f;
           }
        }
   }
   return NULL;
}

/*-----------------------------------*/
void RTFAPI CheckSharing(RTFile * File)
//static void INTERN CheckSharing(RTFile * File)
{
   UINT i;
   RTFile * f = gFS_Data.FileTable;

   // check if the same data file is open and either file has write access
   // without sharing
   for (i=0; i<FS_MAX_FILES; i++, f++)
      if ((f != File) &&
          (f->Dev == File->Dev) &&
          ((f->Flags & File->Flags & RTF_READ_ONLY) == 0) &&   // not both read only AND
          ((f->Flags & File->Flags & RTF_OPEN_SHARED) == 0) && // not both opend shared AND
          ((((f->Drive == File->Drive) && /* Fix mis-check on two partition, Karen Hsu, 2005/04/15 */
             (SAME_DIR_ENTRY(f->DirEntry.ShortPos,
              File->DirEntry.ShortPos))) ||         // both are the same file OR
           ((f->SpecialKind == PhysicalDisk) ||                // one of them is a device file OR
            (File->SpecialKind == PhysicalDisk)) ||
           ((f->Drive == File->Drive) &&                       // one volume and both go to the same drive
            ((f->SpecialKind == Volume) ||
             (File->SpecialKind == Volume))))))
      {
         fs_util_trace_err_noinfo(RTF_ACCESS_DENIED);
         fs_util_trace_info2(TRACE_ERROR | MT_TRACE_INFO_TASK, FS_ERR_ACCESS_DENIED, f->OwnerLR, GetFileHandle(f), f);

         XRAISE(RTF_ACCESS_DENIED);
      }
}

/*-----------------------------------*/
void RTFAPI CheckNotOpen2(RTFile * File, RTFile * File2)
{
   UINT i;
   RTFile * f = gFS_Data.FileTable;

   for (i=0; i<FS_MAX_FILES; i++, f++)
      if ((f != File) && (f != File2) &&
          (f->Drive == File->Drive) &&
          (f->SpecialKind == File->SpecialKind) &&
          SAME_DIR_ENTRY(f->DirEntry.ShortPos, File->DirEntry.ShortPos))
      {
         fs_util_trace_err_noinfo(RTF_ACCESS_DENIED);
         fs_util_trace_info2(TRACE_ERROR | MT_TRACE_INFO_TASK, FS_ERR_ACCESS_DENIED, f->OwnerLR, GetFileHandle(f), f);

         XRAISE(RTF_ACCESS_DENIED);
      }
}

void RTFAPI CheckNotOpen(RTFile * File)
{
   CheckNotOpen2(File, NULL);
}

/*-----------------------------------*/
static RTFDrive * INTERN LocateDrive(int DriveIndex, MountStates State, kal_uint32 Flags)
{
   RTFDrive  *Drive;
   /*------------------------------------------------------------------------
    * Flag to indicate if system drive is located.
    * Note it is only valid after drive remapping is done by FS_SanityCheck.
    *------------------------------------------------------------------------*/
   kal_uint8 LocateSysDrv = KAL_FALSE;
   boot_mode_type boot_mode;

   LocateSysDrv = fs_conf_query_if_sys_drv((WCHAR)(DriveIndex + MT_BASE_DRIVE_LETTER), (WCHAR*)&DriveIndex);

   // now DriveIndex is "drive letter", let it become "index"
   DriveIndex = DriveIndex - MT_BASE_DRIVE_LETTER;

   if ((DriveIndex < 0) || (DriveIndex >= FS_MAX_DRIVES))
   {
      fs_util_trace_err_noinfo(RTF_DRIVE_NOT_FOUND);
      fs_util_trace_info1(TRACE_ERROR, FS_ERR_LOCATEDRIVE_DRVIDX_OUT_OF_RANGE, DriveIndex, NULL);

      XRAISE(RTF_DRIVE_NOT_FOUND);
   }

   Drive = gFS_Data.DriveTable + DriveIndex;

   if (Drive->Dev == NULL)
   {
      // some other thread might be initialising, so wait for it
      RTFSYSLockMutex(RTFLock, RTF_INFINITE);
      RTFSYSFreeMutex(RTFLock);
      if (Drive->Dev == NULL)
      {
         fs_util_trace_err_noinfo(RTF_DRIVE_NOT_FOUND);

         XRAISE(RTF_DRIVE_NOT_FOUND);
      }
   }

   if ((Flags & FS_READ_ONLY) && (Drive->Dev->DeviceFlags & RTF_DEVICE_BUSY_READ_ONLY))
   {
      Flags |= FS_NOBUSY_CHECK_MODE;
   }

   LockDevice(Drive->Dev, Flags);

   boot_mode = kal_query_boot_mode();

   if (NORMAL_BOOT == boot_mode || USBMS_BOOT == boot_mode)
   {
      if (((Drive->Dev->DeviceFlags & MT_DEVICE_EXPORTING) == MT_DEVICE_EXPORTING) ||
      	  ((Drive->Dev->DeviceFlags & MT_DEVICE_NO_EXPORT) == 0 && gFS_Export == FS_EXPORTED && LocateSysDrv == 0))
      {
         SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV);

         fs_util_trace_err_noinfo(MT_DEVICE_EXPORTED_ERROR);
         fs_util_trace_info1(TRACE_ERROR, FS_ERR_LOCATEDRIVE_EXPORTED, fs_conf_get_devtype_by_devflag(Drive->Dev->DeviceFlags), NULL);

         XRAISE(MT_DEVICE_EXPORTED_ERROR);
      }

#if defined(__MTP_ENABLE__)
      if (SysLockFATTask)
      {
          kal_taskid TaskId = kal_get_current_thread_ID();
          if(TaskId &&
          	 strcmp(kal_get_task_name_ptr(TaskId), "NVRAM") != 0 &&
             SysLockFATTask != TaskId &&
             LocateSysDrv == KAL_FALSE)
          {
              SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV);

              fs_util_trace_err_noinfo(MT_DEVICE_EXPORTED_ERROR);
              fs_util_trace_info1(TRACE_ERROR, FS_ERR_LOCATEDRIVE_EXPORTED, fs_conf_get_devtype_by_devflag(Drive->Dev->DeviceFlags), NULL);

              XRAISE(MT_DEVICE_EXPORTED_ERROR);
          }
      }
#endif /* __MTP_ENABLE__ */

      /* Add for hot plug in/out issue, Karen Hsu, 2004/02/23, ADD START */
      if((Drive->Dev->DevData.MountState == NotMounted) &&
         (Drive->Dev->DeviceFlags & RTF_DEVICE_REMOVABLE))
      {
         DiscardAllBuffers(Drive->Dev);
         SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV);

         fs_util_trace_err_noinfo(RTF_MEDIA_CHANGED);
         fs_util_trace_info1(TRACE_ERROR, FS_ERR_LOCATEDRIVE_MEDIA_CHANGED, fs_conf_get_devtype_by_devflag(Drive->Dev->DeviceFlags), NULL);

         XRAISE(RTF_MEDIA_CHANGED);
      }
      /* Add for hot plug in/out issue, Karen Hsu, 2004/02/23, ADD END */
   }/* boot_mode() == NORMAL_BOOT */

   /* Remove to use our mechanism instead, Karen Hsu, 2004/03/03, REM START */
   #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif
   /* Remove to use our mechanism instead, Karen Hsu, 2004/03/03, REM END */

   if (Drive->MountState < State)
   XTRY
      case XCODE:
         MountLogicalDrive(Drive, State);
         break;
      default:
         UnlockDevice(Drive->Dev);
         break;
      case XFINALLY:
         break;
   XENDX
   return Drive;
}

/*-----------------------------------*/
static RTFDrive * INTERN FindDefaultDrive(void)
{
   RTFDrive * volatile Result = NULL;

   XTRY
      case XCODE:
         Result = LocateDrive(MT_BASE_DRIVE_INDEX, HasFileSystem, 0);
         break;
      default:
         XHANDLED;
         break;
      case XFINALLY:
         break;
   XENDX
   if (Result == NULL)
      return LocateDrive(0, HasFileSystem, 0);
   else
      return Result;
}

/*-----------------------------------*/
void RTFAPI FreeFTSlotAndDevice(RTFile * f)
{
   if (f)
   {
      RTFDevice * Dev = f->Dev;
      FreeFTSlot(f);
#ifdef __P_PROPRIETARY_COPYRIGHT__
/* under construction !*/
#endif
      if (Dev)  {
         if (Dev->DevData.Lock->rtf_sem_owner != KAL_NILTASK_ID) {
            UnlockDevice(Dev);
         }
      }
   }
}

/*-----------------------------------*/
RTFile * RTFAPI ParseFileName1(const char * FileName, kal_uint32 Flags)
// FileName: [D:][\][Path\]FileName[.Ext]
//           \\.\FMapF\[HexStrings]
//           \\.\PHYSICALDRIVEx
//           \\.\D:
{
   int UL;
   RTFile * f;

   f = ReserveFTSlot();

   /* ignore any spaces ahead of FileName */
   while (compASCII(FileName, 0, ' '))
      FileName += 2;

   UL = kal_dchar_strlen(FileName);

   XTRY
      case XCODE:
         /*---------------------------- drive file ----------------------------*/
         if ((UL == 12) && fs_util_comp_uni_ascii(FileName, "\\\\.\\", 4) && compASCII(FileName, 5, ':'))
         {
            // \\.\X:
            // for floppies, we only need Initialized
            // for partitions, we need Accessible
            memcpy((void*) f->FullName, (void*) FileName, UL);
            f->Drive = LocateDrive(fs_util_toupper(toASCII(FileName, 4)) - MT_BASE_DRIVE_LETTER, Initialized, 0);
            setASCII(f->FullName, 4,  MT_BASE_DRIVE_LETTER + (f->Drive - gFS_Data.DriveTable));
            f->Dev = f->Drive->Dev;

            /* for fixed device, drive file is available. */
            if (f->Dev->DeviceType == FS_DEVICE_FDISK) // we want a drive file
            {
               if (f->Drive->MountState < Accessible)
                  MountLogicalDrive(f->Drive, Accessible);
               f->SpecialKind = Volume;
            }
            /* but for floppy disk, only physical disk file is available. */
            else
            {
               #if !defined(__FS_SLIM_PHYSICAL_DRIVE__)
               f->SpecialKind = PhysicalDisk;
               #else    // __FS_SLIM_PHYSICAL_DRIVE__
               XRAISE(FS_INVALID_FILENAME);
               #endif   // !__FS_SLIM_PHYSICAL_DRIVE__
            }
         }
         /*---------------------------- physical disk file ----------------------------*/
         else if ((UL == 36) && (fs_util_comp_uni_ascii(FileName, "\\\\.\\PHYSICALDRIVE", 17)))
         {
            #if !defined(__FS_SLIM_PHYSICAL_DRIVE__)
            RTFDevice * Dev;
            // some other thread might be initialising, so wait for it
            RTFSYSLockMutex(RTFLock, RTF_INFINITE);
            RTFSYSFreeMutex(RTFLock);
            memcpy((void*) f->FullName, (void*) FileName, UL);

            for (Dev = gFS_DeviceList; Dev->DeviceType; Dev++)
            {
               if ((toASCII(f->FullName, 17) - '0') == Dev->DevData.PhysicalDiskIndex)
               {
                  f->Dev = Dev;
                  break;
               }
            }

            if (f->Dev == NULL)
            {
               fs_util_trace_err_noinfo(RTF_DRIVE_NOT_FOUND);

               XRAISE(RTF_DRIVE_NOT_FOUND);
            }

            LockDevice(f->Dev, (f->Flags & ~FS_NONBLOCK_MODE));

            if (f->Dev->DevData.MountState < Initialized)
               rtf_core_mount_device(f->Dev, Initialized);
            f->SpecialKind = PhysicalDisk;

            #else   // __FS_SLIM_PHYSICAL_DRIVE__

            XRAISE(FS_INVALID_FILENAME);

            #endif  // !__FS_SLIM_PHYSICAL_DRIVE__
         }
         /*---------------------------- virtual file ----------------------------*/
         else if ((UL >= 90) && (fs_util_comp_uni_ascii(FileName, "\\\\.\\FMapF\\", 10)))
         {
            /* it's probably a virtual file */
            f->SpecialKind = FileMapFile;
            memcpy((void*) f->FullName, (void*) FileName, UL);
            SetupFMapF_FileHandle(f);
         }
         /*---------------------------- normal file ----------------------------*/
         else
         {
            if(UL == 0)
            {
               fs_util_trace_err_noinfo(RTF_PARAM_ERROR);

               XRAISE(RTF_PARAM_ERROR);
            }

            /*
             * see if the dir name contains a drive letter
             * Case UL < 2: Name has only 1 char!
             */
            if ((UL < 2) || !compASCII(FileName, 1, ':'))
               if (DefaultDrive == NULL)
                  f->Drive = DefaultDrive = FindDefaultDrive();
               else
                  f->Drive = LocateDrive(DefaultDrive - gFS_Data.DriveTable, HasFileSystem, Flags);
            else
               f->Drive = LocateDrive(fs_util_toupper(toASCII(FileName, 0)) - MT_BASE_DRIVE_LETTER, HasFileSystem, Flags);

            f->Dev = f->Drive->Dev;
            f->SpecialKind = NormalFile;
         }
         break;
      default:
         FreeFTSlotAndDevice(f);
         break;
      case XFINALLY:
         break;
   XENDX
   return f;
}

extern kal_bool gMT_Sanity;

/*-----------------------------------*/
void RTFAPI SetClusterValue(RTFDrive * Drive, RTFCluster Cluster, RTFCluster Value)
{
   RTFSector S1=0;
   RTFSector S2=0;

   if (((Cluster != 1) || (gMT_Sanity != KAL_TRUE)) &&
      ((Cluster < 2l) || (Cluster >= Drive->Clusters)))
   {
      fs_util_trace_err_noinfo(RTF_FAT_ALLOC_ERROR);
      fs_util_trace_info1(TRACE_ERROR, FS_ERR_SETCLUSTERVALUE_INVALID_IN_CLUSTER, Cluster, NULL);

      XRAISE(RTF_FAT_ALLOC_ERROR);
   }
#if defined(DEBUG)
   if ((Value != 0) &&
       (Value < 0x0FFFFFF7) &&
       ((Cluster != 1) || (gMT_Sanity != KAL_TRUE)) &&
       ((Value < 2) || (Value >= Drive->Clusters)))
      fs_err_internal_fatal(FS_ERR_CLUSTER_02, NULL);
   if (Cluster == Value)
   {
      fs_util_trace_err_noinfo(RTF_FAT_ALLOC_ERROR);
      fs_util_trace_info2(TRACE_ERROR, FS_ERR_SETCLUSTERVALUE_INVALID_OUT_CLUSTER, Cluster, Value, NULL);

      XRAISE(RTF_FAT_ALLOC_ERROR);
   }
#endif

/* Add for SHADOW FAT, Karen Hsu, 2005/05/11, ADD START */
#if (defined(__FS_SHADOW_NAND__) || defined(__FS_SHADOW_CARD__))
   if (kal_query_boot_mode() != USBMS_BOOT)
   {
      UINT *ShadowFATptr=NULL;

#ifdef __FS_SHADOW_NAND__
      if (Drive->Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
      {
         ShadowFATptr = Shadow_FAT_Array_NAND;
      }
#endif
#ifdef __FS_SHADOW_CARD__
      if (Drive->Dev->DeviceFlags & RTF_DEVICE_REMOVABLE)
      {
         ShadowFATptr = Shadow_FAT_Array_CARD;
      }
#endif
      if (ShadowFATptr)
      {
         if (Drive->FATType == RTFAT16)
         {
            if (Cluster & 0x01)
                ShadowFATptr[Cluster/2] = (Value << 16) + (ShadowFATptr[Cluster/2] & 0x0000FFFF);
            else
                ShadowFATptr[Cluster/2] = (Value + (ShadowFATptr[Cluster/2] & 0xFFFF0000));
         }
         else
            ShadowFATptr[Cluster] = Value;
         return;
      }
   }
#endif
/* Add for SHADOW FAT, Karen Hsu, 2005/05/11, ADD END */

   switch (Drive->FATType)
   {
      case RTFAT12:
      {
         kal_uint32 Pos, O;
         kal_uint32 cluster_group, cluster_crossed, cluster_hit;
         UINT  B1, B2;
         BYTE  * FATPtr;

         // for used FAT, check sector-crossed cluster again while reseting its value
         // mark all clusters who cross sector boundary as Bad Cluster to avoid using it in the future! (powerloss issue)
         if (Value == 0)
         {
            cluster_hit = 0;

            for (cluster_group = 0; cluster_group < Drive->Clusters; cluster_group += FS_FAT12_CLUSTER_CROSSING_SECTOR_GROUP)
            {
                for (cluster_crossed = cluster_group + FS_FAT12_CLUSTER_CROSSING_SECTOR_OFFSET;
                     cluster_crossed < (cluster_group + FS_FAT12_CLUSTER_CROSSING_SECTOR_GROUP - 1) && cluster_crossed < Drive->Clusters;
                     cluster_crossed += FS_FAT12_CLUSTER_CROSSING_SECTOR_OFFSET)
                {
                    if (Cluster == cluster_crossed)
                    {
                        cluster_hit = 1;
                        break;
                    }
                }

                if (cluster_hit == 1)
                {
                    break;
                }
            }

            if (cluster_hit == 1)
            {
                Value = RTF_BAD_CLUSTER;
            }
         }

         Pos    = Cluster + Cluster / 2;     // 0 1 3 4 6 7 9 10 12 13
         S1     = Drive->FirstFATSector + (Pos >> Drive->Dev->DevData.SectorShift);
         FATPtr = GetBuffer(Drive->Dev, S1, 0);
         O      = Pos & (Drive->Dev->DevData.SectorSize-1);

         if (Cluster & 1)  // odd cluster numbers start in the middle
         {
            B1 = FATPtr[O];
            B1 = (B1 & 0x0F) | (Value << 4);
         }
         else
            B1 = Value;
         FATPtr[O] = B1;

         Pos++;
         S2     = Drive->FirstFATSector + (Pos >> Drive->Dev->DevData.SectorShift);
         if (S1 != S2)
         {
            /* set device's inuse buffer (for S1) as DIRTY */
            SetDirty(Drive->Dev);

            /* hook FATSectorInfo to buffer (indicate this buffer store FAT table) */
            Drive->Dev->DevData.B->FATSectorInfo = Drive;

            /* get buffer for S2 */
            FATPtr = GetBuffer(Drive->Dev, S2, 0);
         }
         O      = Pos & (Drive->Dev->DevData.SectorSize-1);

         if (Cluster & 1)  // odd cluster numbers start in the middle
            B2 = Value >> 4;
         else
         {
            B2 = FATPtr[O];
            B2 = (B2 & 0xF0) | ((Value >> 8) & 0x0F);
         }
         FATPtr[O] = B2;
         break;
      }
      case RTFAT16:
      {
         WORD * FATPtr = GetBuffer(Drive->Dev, Drive->FirstFATSector + (Cluster >> (Drive->Dev->DevData.SectorShift-1)), 0);
         FATPtr[Cluster & ((Drive->Dev->DevData.SectorSize >> 1)-1)] = Value;
         break;
      }
#if !defined(__NOT_SUPPORT_FAT32__)
      case RTFAT32:
      {
         kal_uint32 * FATPtr = GetBuffer(Drive->Dev, Drive->FirstFATSector + (Cluster >> (Drive->Dev->DevData.SectorShift-2)), 0);
         FATPtr += (Cluster & ((Drive->Dev->DevData.SectorSize >> 2)-1));
         *FATPtr = (*FATPtr & 0xF0000000) | Value;
         break;
      }
#endif /* __NOT_SUPPORT_FAT32__ */
      default:
         fs_err_internal_fatal(FS_ERR_CLUSTER_03, (void*)(Drive->FATType));
   }

   /* set device's inuse buffer as DIRTY */
   SetDirty(Drive->Dev);

   /* hook FATSectorInfo to buffer (indicate this buffer store FAT table) */
   Drive->Dev->DevData.B->FATSectorInfo = Drive;

   /* commit buffers to not occupy 2 buffers for SetClusterValue. To keep consistency, both two buffers are committed. */
   if ((Drive->FATType == RTFAT12) && (S1 != S2))
   {
      /* commit buffer of S2 */
      CommitBuffer(Drive->Dev);

      /* get buffer of S1 */
      GetBuffer(Drive->Dev, S1, 0);

      /* commit buffer of S1 */
      CommitBuffer(Drive->Dev);

      /*
       * get buffer of S2 to let CreateNewDirEntry flush whole FAT table
       * just after FAT table is updated                       - W10.32 -
       */
      GetBuffer(Drive->Dev, S2, 0);
   }

   /* discard unused or bad sector */
   if ((Cluster != 1) && ((Value == 0) || (Value == RTF_BAD_CLUSTER)))
   {
      DiscardSectors(Drive->Dev, CLUSTER_TO_SECTOR(Drive, Cluster), Drive->SectorsPerCluster);
   }
}

/*-----------------------------------*/
static RTFCluster INTERN FATClusterChainLength(RTFDrive * Drive, RTFCluster Cluster, RTFCluster * LastCluster)
// follows the chain until the last cluster is found
// return number of clusters in chain
// *LastCluster has the last cluster of the chain
{
   RTFCluster NextCluster;
   RTFCluster i = 0;

   while (1)
   {
      i++;
      NextCluster = GetClusterValue(Drive, Cluster);
      if (NextCluster >= RTF_CLUSTER_CHAIN_END)
      {
         if (LastCluster)
            *LastCluster = Cluster;
         return i;
      }
      Cluster = NextCluster;
   }
}

/*-----------------------------------*/
int RTFAPI UpdateClusterWatermark(RTFDrive * Drive, RTFCluster Watermark, int DeltaFreeClusters)
//static int INTERN UpdateClusterWatermark(RTFDrive * Drive, RTFCluster Watermark, int DeltaFreeClusters)
// returns 1 if flushing is required
{
#ifdef DEBUG
   if (Watermark < 2)
       fs_err_internal_fatal(FS_ERR_WATERMARK_01, NULL);
#endif
   if (Watermark != RTF_INVALID_CLUSTER)
      Drive->ClusterWatermark = (Watermark < Drive->Clusters) ? Watermark : 2;
   if (Drive->FreeClusterCount != RTF_INVALID_CLUSTER)
      Drive->FreeClusterCount += DeltaFreeClusters;

#if !defined(__NOT_SUPPORT_FAT32__)
   if (Drive->InfoSector)
   {
      RTFFAT32InfoSector * IS;
      IS = GetBuffer(Drive->Dev, Drive->InfoSector, 0);
      if ((IS->NextFreeCluster != Drive->ClusterWatermark) || (IS->FreeClusterCount != Drive->FreeClusterCount))
      {
         IS->Signature1 = 0x41615252L;
         IS->Signature2 = 0x61417272L;
         IS->Signature  = 0xAA550000L;
         IS->NextFreeCluster = Drive->ClusterWatermark;
         IS->FreeClusterCount = Drive->FreeClusterCount;
         SetDirty(Drive->Dev);
         return 1;
      }
   }
#endif /* __NOT_SUPPORT_FAT32__ */
   return 0;
}

/*-----------------------------------*/
#define FAT_DELETE_MAX_CLUSTERS 64

RTFCluster RTFAPI SafeFATDelete(RTFDrive * Drive, RTFCluster Cluster, RTFile * f)
{
   RTFCluster volatile Result;

   XTRY
      case XCODE:
         Result = FATDelete(Drive, Cluster, f);
         break;
      default:
         XHANDLED;
         Result = 0;
         break;
      case XFINALLY:
         break;
   XENDX
   return Result;
}

RTFCluster RTFAPI FATDelete(RTFDrive * Drive, RTFCluster Cluster, RTFile * f)
//static RTFCluster INTERN FATDelete(RTFDrive * Drive, RTFCluster Cluster)
// delete a complete cluster chain starting at Cluster
{
   RTFCluster NextCluster;
   RTFCluster ChainEnd = Cluster, ChainStart = Cluster;
   RTFCluster Clusters = 0;
   kal_uint32 start_time = 0, end_time = 0;

   while (Cluster < RTF_CLUSTER_CHAIN_END)
   {
      if(start_time==0)
      {
          start_time=kal_get_systicks();
      }

      NextCluster = GetClusterValue(Drive, Cluster);
      SetClusterValue(Drive, Cluster, 0);
      Clusters++;

      // to avoid occupying the lock for a long period
      if ((Clusters % FAT_DELETE_MAX_CLUSTERS) == 0)
      {
         UnlockDevice(Drive->Dev);

         end_time=kal_get_systicks();
         if((end_time-start_time)>400)  // 2 sec
         {
             kal_sleep_task(20);        // wait for 100 ms.
             start_time = 0;
         }

         LockDevice(Drive->Dev, 0);
      }

      /* Get Segment Range */
      ChainStart = (Cluster < ChainStart) ? Cluster : ChainStart;
      ChainEnd   = (Cluster > ChainEnd  ) ? Cluster : ChainEnd  ;
      Cluster = NextCluster;
   }

#ifdef __P_PROPRIETARY_COPYRIGHT__
/* under construction !*/
/* under construction !*/
#endif
   UpdateClusterWatermark(Drive, ChainStart, Clusters);

/* Multiple Sub Cluster Watermark, MTK_WCP_SW , 2006/02/24, ADD START */
#if !defined(__NOT_SUPPORT_FAT32__)
   FATLowerSubMark(Drive, ChainStart, ChainEnd);
#endif /* __NOT_SUPPORT_FAT32__ */
/* Multiple Sub Cluster Watermark, MTK_WCP_SW , 2006/02/24, ADD END */

   /* Add for quota management, Karen Hsu, 2004/08/10, ADD START */
#ifdef __FS_QM_SUPPORT__
   if (f && (f->Drive->QuotaMgt))
   {
      int quota_idx = -1;

      fs_util_trace_info2(TRACE_INFO, FS_INFO_QUOTA_DELETE, Clusters, f->Drive->FreeClusterCount, NULL);

      if (f->FullName[6] == '@')
      {
         GetQuotaEntry(&quota_idx, f);

         if(quota_idx >= 0)
         {
            if(gFS_IntQuotaSet[quota_idx].Uint >= Clusters)
            {
               gFS_IntQuotaSet[quota_idx].Uint -= Clusters;

               fs_util_trace_info2(TRACE_INFO, FS_INFO_QUOTA_STATUS_NOW_FATDELETE, quota_idx, gFS_IntQuotaSet[quota_idx].Uint, NULL);
            }
            else
               gFS_IntQuotaSet[quota_idx].Uint = 0;
         }
      }
   }
#endif
   /* Add for quota management, Karen Hsu, 2004/08/10, ADD END */
#ifdef __P_PROPRIETARY_COPYRIGHT__
/* under construction !*/
#endif

   return Clusters;
}

/*-----------------------------------*/
static RTFCluster INTERN FATZeros(RTFDrive * Drive, RTFCluster Cluster, RTFCluster MaxClusters)
// determine the number of free consecutive clusters starting at Cluster
{
   RTFCluster i;

   for (i=0; i<MaxClusters; i++)
   {
      /* beyond the number of clusters in this drive */
      if (Cluster == Drive->Clusters)
         return i;

      /* not free cluster */
      if (GetClusterValue(Drive, Cluster) != 0)
         return i;

      Cluster++;
   }
   return MaxClusters;
}

/*-----------------------------------*/
static void INTERN FATMarkSegment(RTFDrive * Drive, RTFCluster Cluster, RTFCluster Clusters)
// chain up a contiguous cluster chain
{
   RTFCluster i;

   for (i=Cluster; i<(Cluster+Clusters-1); i++)
      SetClusterValue(Drive, i, i+1);

   SetClusterValue(Drive, Cluster+Clusters-1, RTF_CHAIN_END_MARK);

   if ((Cluster == Drive->ClusterWatermark) && ((Cluster+Clusters) < Drive->Clusters))
      UpdateClusterWatermark(Drive, Cluster+Clusters, -Clusters);
   else
      UpdateClusterWatermark(Drive, RTF_INVALID_CLUSTER, -Clusters);

/* Multiple Sub Cluster Watermark, MTK_WCP_SW , 2006/02/24, ADD START */
#if !defined(__NOT_SUPPORT_FAT32__)
   FATHoistSubMark(Drive, Cluster, Cluster+Clusters);
#endif /* __NOT_SUPPORT_FAT32__ */
/* Multiple Sub Cluster Watermark, MTK_WCP_SW , 2006/02/24, ADD END */
}

/*******************************************************************//**
 * Check if disk full or quota full
 *
 * @par Category:
 * File System
 **********************************************************************/
static int INTERN AllocateFATSegmentPermit(RTFile * f, RTFCluster MaxClusters, int *quota_idx_ptr)
{
#ifdef __FS_QM_SUPPORT__
   int quota_idx = -1;
#endif /* __FS_QM_SUPPORT__ */

   if(quota_idx_ptr)
   {
       *quota_idx_ptr = -1;
   }

   if(f->Drive->FreeClusterCount == 0)
   {
      fs_util_trace_err_noinfo(RTF_DISK_FULL);
      fs_util_trace_info1(TRACE_ERROR, FS_ERR_ALLOCFATSEGPERMIT_DISK_FULL, fs_conf_get_devtype_by_devflag(f->Drive->Dev->DeviceFlags), NULL);

      return RTF_DISK_FULL;
   }

   if (MaxClusters > 0)
   {
#ifdef __FS_QM_SUPPORT__
      if(f->Drive->QuotaMgt)
      {
         char * fName;

         /* skip "X:\" */
         fName = &f->FullName[6];

         fs_util_trace_info2(TRACE_INFO, FS_INFO_QUOTA_BEFORE_ALLOC, MaxClusters, f->Drive->FreeClusterCount, NULL);

         if(*fName == '@')
         {
            GetQuotaEntry(&quota_idx, f);

            if(quota_idx >= 0)
            {
               if(quota_idx_ptr)
               {
                   *quota_idx_ptr = quota_idx;
               }

               if(QMPermitAllocate(f->Drive->FreeClusterCount, quota_idx, MaxClusters) != RTF_NO_ERROR)
               {
                  fs_util_trace_err_noinfo(MT_TRACE_QM_ERR);
                  fs_util_trace_info1(TRACE_ERROR, FS_ERR_ALLOCFATSEGPERMIT_APP_QERR, quota_idx, NULL);

                  return MT_APP_QUOTA_FULL;
               }
               else
               {
                  return RTF_NO_ERROR;
               }
            }

            // if no quota setting is found for this folder "@xxx", go through to continue the checking (W09.49)
         }

         if (WFNamesMatch(fName, (char*)NvramName) == 0)
         {
            /* if NOT in quota set and NOT NVRAM directory, concern RFS for ALL quota sets */
            if(QMPermitAllocate(f->Drive->FreeClusterCount, -1, MaxClusters) != RTF_NO_ERROR)
            {
                fs_util_trace_err_noinfo(MT_TRACE_QM_ERR);

                return MT_APP_QUOTA_FULL;
            }
         }

         /*
          * NVRAM folder will bypass quota checking because NVRAM will use fixed disk size,
          * and the size is already calculated in build time.
          */
      }
#endif
      return RTF_NO_ERROR;
   }
   return RTF_NO_ERROR; // for case MaxClusters == 0
}

/*******************************************************************//**
 * Allocate a segment anywhere, start searching at Cluster (if valid), with maximum (less is allowed)
 *
 * @par Category:
 * File System
 *
 * @return
 * The number of clusters allocated.
 * Cluster: The starting cluster number of the free cluster chain found in this function.
 **********************************************************************/
static RTFCluster INTERN AllocateFATSegment(RTFDrive * Drive, RTFCluster * Cluster, RTFCluster MaxClusters, RTFile * f)
{
   RTFCluster SegmentLength = 0, C;
   int Try = 0;
   int Result, quota_idx = -1; /* Add for quota management, Karen Hsu, 2004/08/10, ADD */

   C = *Cluster;

   if ((C < 2) || (C >= Drive->Clusters))
      C = Drive->ClusterWatermark;

   if (C == RTF_INVALID_CLUSTER)
   {
      C = 2;
      Try = 1;
   }
   else
   {
      /* check if disk full or quota full */
      Result = AllocateFATSegmentPermit(f, MaxClusters, &quota_idx);

      if (Result < RTF_NO_ERROR)
      {
         *Cluster = 0;
         XRAISE(Result);
      }
   }

   while (1)
   {
      SegmentLength = FATZeros(Drive, C, MaxClusters);

      if (SegmentLength > 0)
      {
         FATMarkSegment(Drive, C, SegmentLength);
         *Cluster = C;

#ifdef __FS_QM_SUPPORT__
         if (quota_idx >= 0)
         {
            gFS_IntQuotaSet[quota_idx].Uint += SegmentLength;

            fs_util_trace_info2(TRACE_ERROR, FS_INFO_QUOTA_STATUS_NOW_ALLOCFATSEG, quota_idx, gFS_IntQuotaSet[quota_idx].Uint, NULL);
         }
#endif
         return SegmentLength;
      }
      else
      {
         C++;

         /* find the next free cluster within a FAT buffer */
         C = FATSearchZeroInBuffer(Drive, C);

#if !defined(__NOT_SUPPORT_FAT32__)

         if ((C & SUBMARK_MASK) == 0x0)
         {
            C = FATHintSearchBySubMark(Drive, C, Try);
         }

#endif /* __NOT_SUPPORT_FAT32__ */

         /* reach the end of this drive */
         if (C >= Drive->Clusters)
         {
            /* if never wrap around, find again from the start of drive */
            if (Try == 0)
            {
               C = 2;
               Try = 1;
            }

            /* otherwise, raise disk full exception */
            else
            {
               *Cluster = 0;

               fs_util_trace_err_noinfo(RTF_DISK_FULL);
               fs_util_trace_info1(TRACE_ERROR, FS_ERR_ALLOCFATSEG_DISK_FULL, fs_conf_get_devtype_by_devflag(Drive->Dev->DeviceFlags), NULL);

               XRAISE(RTF_DISK_FULL);
            }
         }
      } /* END if (SegmentLength) */
   } /* END while (1) */
}


/*-----------------------------------*/
/* copy long file name from LFN entry, and translate to short file name format */
static void INTERN CopyLFN_toShort(char * Name, const LFNDirEntry * LD)
{
   UINT i, index=0;
   WCHAR wide_c;
   WORD U;

   for (i=0; i<13; i++)
   {
      if(i < 5)
      {
         U = LD->Name1[i];
      }
      else if(i < 11)
      {
         U = LD->Name2[i-5];
      }
      else
      {
         U = LD->Name3[i-11];
      }

      if ((U == 0) || (U == 0xFFFF))
         break; // end of string

      wide_c = fs_util_uni_to_native((WCHAR)U);

      /* if native encoding, convert to upper-case */
      wide_c = ( wide_c>=0x61 && wide_c<=0x7a) ? wide_c-(0x61-0x41) : wide_c;

      if ( wide_c&0xff00 )
      {
         Name[index++] = (char)(wide_c>>8);   /* Fix NULL string in multi-language, Karen Hsu, 2005/03/14, MOD */
         Name[index++] = (char)(wide_c&0xff); /* Fix NULL string in multi-language, Karen Hsu, 2005/03/14, MOD */
      }
      else
         Name[index++] = (char)wide_c;
   }

   Name[index] = 0;
}

/*-----------------------------------*/
// for Thai encoding issues: 0xA8 0x00 0xA8 0x00 ...
int MTNativeFileNameLen(char *filename, kal_uint32 encoding_length, kal_uint32 max_byte)
{
   int len = 0;

   while (1)
   {
      if (filename[len] & 0x80)
      {
         if (encoding_length > 1)
            len += 2;
         else  // 8-bit native encoding
            len += 1;
      }
      else if (filename[len] == 0)
      {
         break;
      }
      else
      {
         len++;
      }

      // for corrupted file name, use a bound to avoid memory corruption
      if (len >= max_byte)
         return max_byte;
   }

   return len;
}


/*-----------------------------------*/
void RTFAPI UpdateDirEntry(RTFile * f)
// copy the short dir entry to the buffer cache, commit if required
{
   RTFDOSDirEntry * D;

   if (f->DirEntry.DirCluster == 0) // it's the root
      return;

   D = GetDir(f->Drive, &f->DirEntry.ShortPos);

   if (memcmp((void*)D, (void*) &f->DirEntry.Dir, sizeof(f->DirEntry.Dir)) != 0)
   {
      UINT i;
      RTFile * f1 = gFS_Data.FileTable;

      *D = f->DirEntry.Dir;

      // directories on disk do not have a filesize
      if (D->Attributes & RTF_ATTR_DIR)
         D->FileSize = 0;

      SetDirty(f->Dev);

      if (f->Flags & RTF_COMMITTED)
         CommitBuffer(f->Dev);

      // search for shared files and update their dir entry too
      for (i=0; i<FS_MAX_FILES; i++, f1++)
      {
         if ((f1 != f) && (f1->Dev == f->Dev) && (f1->Drive == f->Drive) && SAME_DIR_ENTRY(f1->DirEntry.ShortPos, f->DirEntry.ShortPos))
         {
            // check the file pointer & file size
            if (f1->Task != f->Task)    // for running file handle, its Task is not set, i.e. 0, therefore all opened file will be checked.
            {
               if(f->DirEntry.Dir.FileSize < f1->FilePointer)
               {
                   fs_err_internal_fatal(FS_ERR_DIRENTRY_01, NULL); // todo: Can SST analyzer do something helpful?
               }
            }
            // force update the f->cluster value in the boundary case ; See Also MoveFilePointerSegment
            if (f1->Cluster == 0 && f1->LastCluster != 0)
            {
               f1->Cluster = GetClusterValue(f1->Drive, f1->LastCluster);
               if (f1->Cluster >= RTF_CLUSTER_CHAIN_END)
                  f1->Cluster = 0;
            }
            // update the f->Cluster value when first cluster value updated ; WCP_SW 2007/10/08
            else if (f1->Cluster == 0 &&
                     FIRST_FILE_CLUSTER(f1->DirEntry.Dir) == 0 &&
                     FIRST_FILE_CLUSTER(f->DirEntry.Dir) != 0
                    )
            {
               f1->Cluster = FIRST_FILE_CLUSTER(f->DirEntry.Dir);
            }
            // update the directory entry then
            f1->DirEntry.Dir = f->DirEntry.Dir;
         }
      }

      /* Associate Cache Value Expiration */

      MTExpireDirCacheValue(f->Drive, f->DirEntry.DirCluster);
   }
}

/*******************************************************************//**
 * Commit SFN diretory entry of a specified file
 *
 * @par Category:
 * File System
 **********************************************************************/
static void INTERN CommitDirEntry(RTFile * f)
// commit the short dir entry
{
   RTFSector Sector;

   if (f->DirEntry.DirCluster == 0) // it's the root
      return;

   Sector = CLUSTER_TO_SECTOR_DIR(f->Drive, f->DirEntry.DirCluster);

   /* commit SFN directory entry only */
   if (SearchBuffer(f->Dev, Sector + (f->DirEntry.ShortPos.Index / DIRS_PER_SECTOR(f->Drive))))
      CommitBuffer(f->Dev);
}



/*-----------------------------------*/
int GenerateVolumeLable(const char * LongName, char * ShortName)
// input is Unicode
// output is combination of ASCII and native code
// ShortName is in DirEntry format
// Validity of ASCII code must be checked, any invalid short file name is coded as '_'
// LossyFlag is used to tracking the necessity to associate an LFN entry
{
   const char * pN = LongName;
   char       * pF = ShortName;
   int          LossyFlag = 0;
   WCHAR        wide_c;
   char         c;
   char         encoding_length;

   encoding_length = fs_util_get_default_encoding_length();

   kal_mem_set(pF, ' ', 8+3);

   // volume label can occupy 11 chars (both file name and extension name)
   while ((pN[0] || pN[1]) && !(compASCII(pN ,0 ,'\\')) && ((pF - ShortName) < 11))
   {
      if (isASCII(pN, 0))
      {
         c = fs_util_get_short_char(pN[0]);

         *pF++ = c;
      }
      else  // non-ASCII
      {
         if ((encoding_length > 1) && (pF-ShortName) >= 10)
         {
            break;
         }

         wide_c = fs_util_uni_to_native(*(kal_uint8 *)(pN) | (*(kal_uint8 *)(pN + 1) << 8));

         #ifndef __FS_NATIVE_ENCODING_TRANSPARENT__

         if (wide_c == 0xFFFF)
         {
            fs_util_trace_err_noinfo(FS_INVALID_FILENAME);

            XRAISE(FS_INVALID_FILENAME);
         }

         if (encoding_length > 1)
         {
            *pF++ = wide_c >> 8;
         }

         #endif /* !__FS_NATIVE_ENCODING_TRANSPARENT__ */

         /*
          * If __FS_NATIVE_ENCODING_TRANSPARENT__ is defined, UnicodetoNative()
          * will return valid ASCII char, thus we only need to append one byte.
          */

         *pF++ = wide_c & 0xff;
      }

      pN += 2;
   }

   // Convert 0xE5 special char (deleted mark) to 0x05
   if (ShortName[0] == 0xE5) ShortName[0] = 0x05;

   return LossyFlag;
}

/*-----------------------------------*/
static void INTERN IncShortName(char * ShortName)
// ShortName is in DirEntry format
// append telda (~) + number
{
   char * p = NULL;
   int    i, j;
   /* Last Revision @ 2008/01/18 */

   // locate last character of major partion
   j = 7;
   while ( ShortName[j]==' ' )
   {
      j--;
   }
   i = j;
   // locate telda(~) position
   while ( j >= 0 )
   {
     if (ShortName[j] == '~')
     {
        /*
         * Case like "~ABCDEFG" and "AB~CDEFG" will be treated as no '~' found here.
         * And we will make "~ABCDE~1" and "AB~CDE~1" for such cases later.
         */
        if (j < 7 && (ShortName[j + 1] < '0' || ShortName[j + 1] > '9'))
        {
           j--;
           continue;
        }

        p = ShortName + j;
        break;
     }
     j--;
   }
   // telda(~) not found , create one
   if (p == NULL)
   {
      if (i < 6)
      {
         ShortName[++i] = '~';
         ShortName[++i] = '1';
      }
      else if ((ShortName[5] & 0x80) && (ShortName[7] == 0x20))
      {
         ShortName[5] = '~';
         ShortName[6] = '1';
      }
      else
      {
         ShortName[6] = '~';
         ShortName[7] = '1';
      }
   }
   // telda(~) found , increment the numeric tail
   else
   {
      // rewind p to tail character of major filename partion
      for ( p=ShortName+i; p>=ShortName; p-- )
      {
         switch (p[0])
         {
            case '~':
               // position at j
               if ( j>2 && p[-2]>0x80 )
               // replace 2 character , copy digits and put space in tail
               {
                  p[-2]='~';
                  p[-1]='1';
                  for ( ; j < 7 ; j++, p++)
                  {
                     p[0] = p[1];
                  }
                  p[0] = ' ';
               }
               else
               {
                  p[0] = '1';
                  if (p > ShortName)
                     p[-1] = '~';
               }
               return;
            case '9':
               // digit must carry in and continue to previous digit
               if ( p[1] == ' ' && p<ShortName+7 )
               // there's space in tail, set it to zero and return
               {
                  p[1] = '0';
                  p[0] = '0';
                  return;
               }
               // set zero, back one digit
               p[0] = '0';
               break;
            default:
               // others, increament and exit
               if ((p[0] >= '0') && (p[0] < '9'))
                  p[0]++;
               else
                  p[0] = '0';
               return;
         }
      } // for (p=ShortName+i ... ShortName)
   } // if ( ShortName contain telda(~) )
}

/*-----------------------------------*/
static void INTERN CreateNewDirEntry(RTFile *f, FS_OpenHintInt *Hint)
// this function assumes that the long name (unicode) is available!
// a short name is created
// FAT is not committed
// DIR is not committed
// slack dir space is committed
// long name is commited
// !NOTE! CreateNewDirEntry requires dir to be searched before! (i.e., f->DirEntry.DirCluster must have value)
{
   const char       *Name = kal_dchar_strrchr(f->FullName, 0x005c);
   RTFDOSDirEntry   *D;
   RTFDirLocation   DSR;
   char             ShortName[14];
   char             ShortName1[26]={0};
   int              NeedDirEntries, FreeDirEntries;
   int              LossyFlag, i;
   int              SpeedupTry_Flag = 0; /* Speed up matching SFN, Karen Hsu, 2005/06/06 */
   int              NeverUsedFlag = 0; // 0 : NeverUsed flag is not met, 1 : NeverUsed flag is met, 2: The free slot contains a NeverUsed entry.
   int              SearchCount = 1;
   kal_uint32       start_time = 0, end_time = 0;
   #ifdef __FS_OPEN_HINT__
   kal_uint8        internal_hint = 0;
   kal_uint8        path_idx      = 0;
   kal_uint8        level         = 0;
   kal_uint8        new_hint      = 0;
   #endif

   #ifdef __FS_OPEN_HINT__
   if (Hint && MTIsInternalHint(Hint))
   {
      internal_hint = 1;
      path_idx = MTHintGetIndex(Hint);
      level    = MTHintGetLevel(Hint);
      new_hint = MTIsNewHint(Hint);
   }
   #endif

   /* Associate Cache Value Expiration */

    // abort check
    if (fs_fh_is_aborted((FS_File*)f) == KAL_TRUE)  // [async]
    {
        fs_util_trace_err_noinfo(FS_ABORTED_ERROR);

        XRAISE(FS_ABORTED_ERROR);
    }

   MTExpireDirCacheValue(f->Drive, f->DirEntry.DirCluster);

   if ( Name==0 )
      Name = f->FullName;  /* backslash '\' is not found in f->FullName, f->FullName may be a relative name */
   else
      Name += 2;  /* backslash is found, ignore it */

   /* long names are limited to 255 characters (not including tailing NULL) */
   if (kal_dchar_strlen(Name) > 510)
   {
      fs_util_trace_err_noinfo(MT_PATH_OVER_LEN_ERROR);

      XRAISE(MT_PATH_OVER_LEN_ERROR);
   }

   #if !defined(__FS_SLIM_VOLUME_LABEL__)
   if((f->DirEntry.Dir.Attributes & ~RTF_ATTR_ARCHIVE) == RTF_ATTR_VOLUME)
   {
       if ((f->PrivateFlags & FS_PRIVATE_FLAG_IGNORE_SFN_GENERATION) == 0)
       {
          GenerateVolumeLable(Name, (char *)f->DirEntry.Dir.FileName);
       }

       // for Volume Label, reset LossyFlag anyway to avoid LFN being generated below
       LossyFlag = 0;
   }
   else
   #endif
   {
       LossyFlag = GenerateShortName(Name, (char *)f->DirEntry.Dir.FileName);
   }

   // make convert failed mark as a valid SFN character
   if (LossyFlag)
   {
      char *ptr;
      ptr = (char*)f->DirEntry.Dir.FileName;

      for (i = 0 ; i < 10 ; i++)
      {
         if (i == 7)
         {
            // skip the end of major name
            continue;
         }

         if (ptr[i] == 0xFF && ptr[i + 1] == 0xFF)
         {
            ptr[i] = '#';
            ptr[i + 1] = '_';
         }
      }
   }

   kal_mem_set(ShortName, 0, sizeof(ShortName));
   MakeShortFileName(&f->DirEntry.Dir, ShortName, 13);

   for (i = 0; i < 26; i += 2)
      ShortName1[i] = ShortName[i >> 1];

   i = kal_dchar_strcmp(Name, ShortName1);

   /*---------------------------------------
    * Windows NT case indication flag support
    *---------------------------------------*/

   /* clean file name case indication flags */
   f->DirEntry.Dir.NTReserved &= ~(MT_ENUM_LOWERCASE_MARK | MT_ENUM_EXT_LOWERCASE_MARK);

   /* short file name case indication */
   if (!LossyFlag && (kal_dchar_strlen(Name) < 26))
   {
      int flag_dot = 0, uflag = 0, lflag = 0, j;
      WCHAR *pName = (WCHAR *)Name;
      BYTE NTReserved = f->DirEntry.Dir.NTReserved;

      for(j = 0; j < 13; j++)
      {
         if (pName[j] == 0)
         {
            break;
         }

         /* a "dot" is encountered, file name portion finished. */
         if (pName[j] == dchar_dot[0])
         {
            flag_dot = 1;
            uflag = lflag = 0;
         }
         /* once a lower-case character is encountered, set lflag. */
         else if ((pName[j] >= 0x61) && (pName[j] <= 0x7A)) // a-z
         {
            lflag = 1;
            if (flag_dot)
            {
              NTReserved |= MT_ENUM_EXT_LOWERCASE_MARK;
            }
            else
            {
              NTReserved |= MT_ENUM_LOWERCASE_MARK;
            }
         }
         /* once a upper-case character is encountered, set uflag. */
         else if ((pName[j] >= 0x41) && (pName[j] <= 0x5A)) // A-Z
         {
            uflag = 1;
         }
         /* if both uflag and lflag are set, which means it's a mixed case filename or extension name. That's not supported by NT! */
         if (uflag && lflag)
         {
            break;
         }
      }

      /* if not a mixed case, store NTReserved flag. */
      if (!uflag || !lflag)
      {
         f->DirEntry.Dir.NTReserved = NTReserved;
         i = 0;
      }
   }

   if ((LossyFlag || (i != 0)) && (RTF_ATTR_VOLUME != f->DirEntry.Dir.Attributes)) // volume label does NOT need LFN
      NeedDirEntries = 1 + (kal_dchar_strlen(Name) - 2) / 26 + 1;       // need long name
   else
      NeedDirEntries = 1;

#ifdef DEBUG
   if (f->DirEntry.DirCluster == 0)
      fs_err_internal_fatal(FS_ERR_DIRENTRY_02, NULL);
#endif

   FreeDirEntries =
   f->DirEntry.ShortPos.Cluster = 0;

   if(!(LossyFlag & INC_SHORT_NAME))
   {
       MakeShortFileName(&f->DirEntry.Dir, ShortName, 13);
       goto SpeedupTry1;
   }

Retry:
   if (LossyFlag)
   {
      IncShortName((char *)f->DirEntry.Dir.FileName);
      MakeShortFileName(&f->DirEntry.Dir, ShortName, 13);
   }
SpeedupTry1:
   LossyFlag = 1;
   if(NeverUsedFlag == 1) NeverUsedFlag = 0;

   /* set the 1st directory entry as start point of searching */
   D = StartDirSearch(f->Drive, f->DirEntry.DirCluster, 0, &DSR);

SpeedupTry2:
   while (1)
   {
      int Kind = EntryType(D);

      SearchCount ++;

      if (start_time == 0)
      {
          start_time=kal_get_systicks();
      }

        if ((SearchCount & 0x1FF) == 0)        // check once every 512 file
        {
            if (fs_fh_is_aborted((FS_File*)f) == KAL_TRUE)  // [async]
            {
                fs_util_trace_err_noinfo(FS_ABORTED_ERROR);

                XRAISE(FS_ABORTED_ERROR);
            }

            end_time=kal_get_systicks();

            if ((end_time-start_time) > 400)  // 2 sec
            {
                kal_sleep_task(20);        // wait for 100 ms.

                start_time = 0;
            }
        }

      // After meeting a NeverUsed flag, the entries after that should be NeverUsed.
      if(Kind == NeverUsed && NeverUsedFlag == 0) NeverUsedFlag = 1;
      if(NeverUsedFlag == 1) Kind = NeverUsed;

      // accumulate free slots as long as we need them
      if ((f->DirEntry.ShortPos.Cluster == 0) && ((Kind == Available) || (Kind == NeverUsed)))
      {
         FreeDirEntries++;

         /* Bingo! requried free space is satisfied! */
         if (FreeDirEntries == NeedDirEntries)
         {
            if(NeverUsedFlag == 1) NeverUsedFlag = 2;

            /* set ShortPos to this place */
            f->DirEntry.ShortPos = DSR;

            if (NeedDirEntries == 1)
               break; // found, no need to check short name clashes
         }

         /* temporarily set LongPos to the first entry in this free directory entry chain */
         if (FreeDirEntries == 1)
            f->DirEntry.LongPos = DSR;
      }
      else
      {
         /* reset FreeDirEntries if non-free entry is found */
         FreeDirEntries = 0;
      }

      if (f->DirEntry.ShortPos.Cluster && (Kind == NeverUsed))
      {
         if (SpeedupTry_Flag)
         {
            SpeedupTry_Flag = 0;
            if(NeverUsedFlag == 1) NeverUsedFlag = 0;
            goto SpeedupTry1;
         }
         else
         {
            break; // done
         }
      }

      // check generated short name clashes
      if (NeedDirEntries > 1)
      {
         // check short name against short name
         if (Kind == InUse)
         {
            char Temp[14];
            kal_mem_set(Temp, 0, sizeof(Temp));
            MakeShortFileName(D, Temp, 13);
            /* Fix 0x5C always match in multi-language, Karen Hsu, 2005/03/14, ADD START */
            {
               int i=0;
               char c1 = 0, c2, c0;
               do
               {
                  c0 = c1;
                  c1 = fs_util_toupper(ShortName[i]);
                  c2 = fs_util_toupper(Temp[i]);
                  i++;
               } while ((c1 || c0) && (c1 == c2)); // for Thai encoding issues: 0xA8 0x00 0xA8 0x00 ...

               if (c1 == c2)
               {
                  /* Speed up matching SFN, Karen Hsu, 2005/06/06, ADD START */
                  if (LossyFlag)
                  {
                     IncShortName((char *)f->DirEntry.Dir.FileName);
                     MakeShortFileName(&f->DirEntry.Dir, ShortName, 13);
                     D = NextDir(f->Drive, &DSR);
                     if (D == NULL)
                     {
                        goto SpeedupTry3;
                     }
                     if (!(NeverUsedFlag == 1) && EntryType(D) == Lfn)
                     {
                        D = NextDir(f->Drive, &DSR);
                        if (D == NULL)
                        {
                           goto SpeedupTry3;
                        }
                     }
                     SpeedupTry_Flag = 1;
                     goto SpeedupTry2; //compare next directly
                  }
                  /* Speed up matching SFN, Karen Hsu, 2005/06/06, ADD END */
                  goto Retry;
               }
            }
            /* Fix 0x5C always match in multi-language, Karen Hsu, 2005/03/14, ADD END */
         }
         /* check if single LFN entry and SFN is matched */
         else if ((Kind == Lfn) && (D->FileName[0] == 0x41))
         {
            char Temp[28];
            const LFNDirEntry * LD = (void*) D;
            kal_mem_set(Temp, 0, sizeof(Temp)); // zero terminate Temp
            CopyLFN_toShort(Temp, LD);
            /* Fix 0x5C always match in multi-language, Karen Hsu, 2005/03/14, ADD START */
            //if (FNamesMatch(ShortName, Temp))
            {
               int i=0;
               char c1 = 0, c2, c0;
               do
               {
                  c0 = c1;
                  c1 = fs_util_toupper(ShortName[i]);
                  c2 = fs_util_toupper(Temp[i]);
                  i++;
               } while ((c1 || c0) && (c1 == c2)); // for Thai encoding issues: 0xA8 0x00 0xA8 0x00 ...

               if (c1 == c2)
                     goto Retry;
            }
            /* Fix 0x5C always match in multi-language, Karen Hsu, 2005/03/14, ADD END */
         }
      }
      D = NextDir(f->Drive, &DSR);

SpeedupTry3: /* Speed up matching SFN, Karen Hsu, 2005/06/06, ADD */

      if (D == NULL) // try to extend directory, if required
      {
         RTFCluster NextCluster;
         RTFSector Sector;
         UINT i;

         if (f->DirEntry.ShortPos.Cluster)
            break; // same as NeverUsed, done

         if (DSR.Cluster == RTF_ROOT_DIR)
         {
            fs_util_trace_err_noinfo(RTF_ROOT_DIR_FULL);

            XRAISE(RTF_ROOT_DIR_FULL);
         }

         // try to find a free cluster. It is better to be continuous with DSR.Cluster
         NextCluster = DSR.Cluster + 1;
         AllocateFATSegment(f->Drive, &NextCluster, 1, f);

         /**
          * Step 1.
          *
          * Clear new cluster (fill-in ZEROs in whole cluster!)
          *
          * After cleaning the new cluster, commit it first to avoid mess folder contents.   - W10.41-
          */

         Sector = CLUSTER_TO_SECTOR(f->Drive, NextCluster);

         // TODO: Use dedicated buffer to enhance the kal_mem_set job!
         for (i = 0; i < f->Drive->SectorsPerCluster; i++)
         {
            void * DTemp = GetBuffer(f->Dev, Sector + i, NO_LOAD);
            kal_mem_set(DTemp, 0, f->Dev->DevData.SectorSize);
            SetDirty(f->Dev);

            // commit cleaned cluster as early as possible to avoid mess folder contents
            CommitBuffer(f->Dev);

            // only keep the 1st sector in buffer
            if (i > 0)
            {
               DiscardBuffer(f->Dev);
            }
         }

         /**
          * Step 2.
          *
          * Update FAT table.
          *
          * Commit FAT table here to ensure that FAT table is flushed before directory entry
          * to avoid cross link!
          */

         SetClusterValue(f->Drive, DSR.Cluster, NextCluster);
         CommitBuffer(f->Dev);

         D = StartDirSearch(f->Drive, NextCluster, 0, &DSR);
      }
   }

   // write the short dir entry
   D = GetDir(f->Drive, &f->DirEntry.ShortPos);
   *D = f->DirEntry.Dir;
   SetDirty(f->Dev);

   if (NeverUsedFlag == 2)
   {
       // After NeverUsedFlag, there should not be an entry that is not empty.
       // If it happens, it may caused by block lost or the interruption of formatting.
       // Reset the entry to solve block lost issue.
       D = StartDirSearch(f->Drive, f->DirEntry.ShortPos.Cluster, f->DirEntry.ShortPos.Index, &DSR);
       D = NextDir(f->Drive, &DSR);
       if(D && D->FileName[0]!=0x00)
       {
           kal_mem_set((char*)D, 0, sizeof(*D));
           SetDirty(f->Dev);
       }
   }

   // write the long file name dir entry
   if (NeedDirEntries > 1)
   {
      BYTE CheckSum        = ShortNameCheckSum((const BYTE*) f->DirEntry.Dir.FileName);
      int LFNIndex         = NeedDirEntries - 1;
      RTFSector SDirSector = f->Dev->DevData.B->Sector;
      LFNDirEntry * LD     = (LFNDirEntry *) StartDirSearch(f->Drive, f->DirEntry.LongPos.Cluster, f->DirEntry.LongPos.Index, &DSR);
      RTFSector LDirSector = f->Dev->DevData.B->Sector;

      while (1)
      {
         UINT i;
         const char * N = Name + (LFNIndex - 1) * 13 * 2;

         kal_mem_set((void*)LD, 0xFF, sizeof(*LD));
         LD->Ord          = LFNIndex | ((LFNIndex == (NeedDirEntries-1)) ? 0x40 : 0);
         LD->Attributes   = RTF_LONGNAME_ATTR;
         LD->Type         = 0;
         LD->CheckSum     = CheckSum;
         LD->FirstCluster = 0;

         for (i=0; i<13; i++)
         {
            if(i < 5)
            {
               LD->Name1[i] = *(WORD *)N;
            }
            else if(i < 11)
            {
               LD->Name2[i-5] = *(WORD *)N;
            }
            else
            {
               LD->Name3[i-11] = *(WORD *)N;
            }

            if ( *(WORD *)N==0 )
               break;
            N+=2;
         }
         SetDirty(f->Dev);
         if (--LFNIndex == 0)
            break;
         LD = (LFNDirEntry *) NextDir(f->Drive, &DSR);
      }
      // must commit long file name?
      // we assume that a long file name will never span more than two sectors
      if ((SDirSector != LDirSector) && SearchBuffer(f->Dev, LDirSector))
         CommitBuffer(f->Dev);
   }
   else
   {
      /* set LongPos.Cluster to 0 if LFN is not required! */
      f->DirEntry.LongPos.Cluster = 0;
   }

   #ifdef __FS_OPEN_HINT__
   // generate a new location for this hint
   if (internal_hint && new_hint)
   {
      MTHintGen((RTFDirLocation*)Hint, &(f->DirEntry.ShortPos), f);
      MTHintNew(path_idx, level, (RTFDirLocation*)Hint, f, (WCHAR*)Name);
   }
   #endif

   f->DirEntry.DirCluster = f->DirEntry.ShortPos.Cluster; /* Fix new entry cross cluster cannot be committed, Karen Hsu, 2004/04/16, ADD */
}


/*-----------------------------------*/
static RTFDOSDirEntry * INTERN DelLongDirEntry(RTFDrive * Drive, RTFDirLocation * LongPos, const RTFDirLocation * Pos)
{
   RTFDOSDirEntry * D = GetDir(Drive, LongPos);

   while (!SAME_DIR_ENTRY(*LongPos, *Pos))
   {
      D->FileName[0] = RTF_DELETED;
      SetDirty(Drive->Dev);
      D = NextDir(Drive, LongPos);
   }
   LongPos->Cluster = 0;
   return D;
}

/*-----------------------------------*/
void RTFAPI DelDirEntry(RTFDrive * Drive, RTFDirLocation * LongPos, const RTFDirLocation * Pos)
//static void INTERN DelDirEntry(RTFDrive * Drive, RTFDirLocation * LongPos, const RTFDirLocation * Pos)
{
   RTFDOSDirEntry * D;

   if (LongPos->Cluster)
      D = DelLongDirEntry(Drive, LongPos, Pos);
   else
      D = GetDir(Drive, Pos);
   D->FileName[0] = RTF_DELETED;
   SetDirty(Drive->Dev);
}

/*-----------------------------------*/
void RTFAPI DeleteDirEntry(RTFile * f)
{
   DelDirEntry(f->Drive, &f->DirEntry.LongPos, &f->DirEntry.ShortPos);
   /* Associate Cache Value Expiration */

   MTExpireDirCacheValue(f->Drive, f->DirEntry.DirCluster);

   /*
    * If target is DIR, expire the dir cache of his FirstCluster for this case:
    * C:\Photos  rename to C:\PhotosA
    * C:\PhotosB rename to C:\Photos   (W10.28)
    */

   if (f->DirEntry.Dir.Attributes & RTF_ATTR_DIR)
   {
      MTExpireDirCacheValue(f->Drive, FIRST_FILE_CLUSTER(f->DirEntry.Dir));
   }

   if (f->Flags & RTF_COMMITTED) // NOTE: LFN entries may not be committed but it is OK because committing SFN entry only is enough.
      CommitBuffer(f->Dev);
}

/*-----------------------------------*/
int RTFAPI RTFCreateDir(const WCHAR * DirName, kal_uint32 attributes)
{
   RTFile *volatile f = NULL;
   RTFDOSDirEntry   *D;
   RTFSector        Sector;
   RTFCluster       ParentDirFirstCluster;
   int              i;
   #ifdef __FS_OPEN_HINT__
   RTFDirLocation *volatile hint = NULL;
   #endif

   XTRY
      case XCODE:
         f = ParseFileName((char *)DirName);

         /* Fix write protect issue, Karen Hsu, 2004/04/07, ADD START */
         if(f->Dev->DeviceFlags & MT_DEVICE_WRITE_PROTECT)
         {
            fs_util_trace_err_noinfo(RTF_WRITE_PROTECTION);

            XRAISE(RTF_WRITE_PROTECTION);
         }
         /* Fix write protect issue, Karen Hsu, 2004/04/07, ADD END */

         if (f->SpecialKind != NormalFile)
         {
            fs_util_trace_err_noinfo(RTF_INVALID_FILENAME);

            XRAISE(RTF_INVALID_FILENAME);
         }

         #ifdef __FS_OPEN_HINT__
         hint = MTHintGet(DirName, MT_HINT_ACTION_OPEN);
         if (SearchFile(f, SEARCH_FILES, (char *)DirName, hint))
         #else
         if (SearchFile(f, SEARCH_FILES, (char *)DirName, NULL))
         #endif /* __FS_OPEN_HINT__ */
         {
            fs_util_trace_err_noinfo(RTF_FILE_EXISTS);

            XRAISE(RTF_FILE_EXISTS);
         }

         CheckValidFileName2((WCHAR *)f->FullName, KAL_FALSE);

         ParentDirFirstCluster = f->DirEntry.DirCluster;

         kal_mem_set((void*)&f->DirEntry.Dir, 0, sizeof(f->DirEntry.Dir));
         f->DirEntry.Dir.Attributes = RTF_ATTR_DIR;
         RTFSYSGetDateTime(&f->DirEntry.Dir.DateTime);
         f->DirEntry.Dir.CreateDateTime = f->DirEntry.Dir.DateTime;

         /* Fix root dir full but disk free space shrink, Karen Hsu, 2005/06/21, MOD START */
         if (f->Drive->FreeClusterCount == RTF_INVALID_CLUSTER)
         {
            f->Drive->FreeClusterCount = 0;
            f->Drive->ClusterWatermark = RTF_INVALID_CLUSTER;

            BatchCountFreeClusters(f->Drive);
         }
         if (f->Drive->FreeClusterCount < 1)
         {
            fs_util_trace_err_noinfo(RTF_DISK_FULL);

            XRAISE(RTF_DISK_FULL);
         }

         /* Dir clusters may be not enough, and needed to be extended: avoid generating a bad directory entry */
         i = AllocateFATSegmentPermit(f, 1, NULL);

         if (i != RTF_NO_ERROR)
         {
            //DeleteDirEntry(f);
            //CommitBuffer(f->Dev);

            fs_util_trace_err_noinfo(i);

            XRAISE(i);
         }

         /*
          * Step 1. Allocate a cluster
          *
          * Commit modified FAT table first to avoid cross link.
          * NOTE: Commit Dev->DevData.B is enough because SetClusterValue will keep only 1 un-flushed sector in FS buffer (Dev->DevData.B).
          *
          * - 10.41 -
          */

         AllocateFATSegment(f->Drive, &f->Cluster, 1, f);
         CommitBuffer(f->Dev);

         /*
          * Step 2. Clear sectors of allocated cluster (except for the first sector)
          */
         Sector = CLUSTER_TO_SECTOR(f->Drive, f->Cluster);  // f->Cluster is exactly the 1st cluster of this folder

         for (i = 1; i < f->Drive->SectorsPerCluster; i++)
         {
            D = GetBuffer(f->Dev, Sector + i, NO_LOAD);
            kal_mem_set((void*)D, 0, f->Dev->DevData.SectorSize);

            SetDirty(f->Dev);
            CommitBuffer(f->Dev);   // commit cleaned cluster contents
            DiscardBuffer(f->Dev);
         }

         /*
          * Step 3. Write the first sector of the directory and leave the buffer in the cache
          */
         D = GetBuffer(f->Dev, Sector, NO_LOAD);
         kal_mem_set((void*)D, 0, f->Dev->DevData.SectorSize);

         D[0] = f->DirEntry.Dir;
         kal_mem_set((char*)D->FileName, ' ', 8+3);
         D->FileName[0] = '.';
         D[1] = D[0];
         D[1].FileName[1] = '.';

         if (((f->Drive->FATType == 32) && (ParentDirFirstCluster == f->Drive->FirstDirSector)) ||
             (f->DirEntry.DirCluster == RTF_ROOT_DIR))
            SET_FIRST_FILE_CLUSTER(D[1], 0); // back link to root are zero
         else
            SET_FIRST_FILE_CLUSTER(D[1], ParentDirFirstCluster);

         SET_FIRST_FILE_CLUSTER(D[0], f->Cluster);

         SetDirty(f->Dev);

         if ((FileCount(f->Dev) <= 1) || ((f->Dev->DeviceFlags & RTF_DEVICE_LAZY_WRITE) == 0))
            FlushAllBuffers(f->Dev);

         /*
          * Step 4. Fill-in FirstCluster (fill-in it before dir entry is created on disk to avoid dangling FirstCluster)
          */

         SET_FIRST_FILE_CLUSTER(f->DirEntry.Dir, f->Cluster);

         // inherit specified attributes
         if (attributes != 0)
         {
            f->DirEntry.Dir.Attributes |= attributes;
         }

         /*
          * Step 5. Create real dir entry in disk
          */

         #ifdef __FS_OPEN_HINT__
         CreateNewDirEntry(f, (FS_OpenHintInt*)hint);
         #else
         CreateNewDirEntry(f, NULL);
         #endif

         f->Flags |= RTF_COMMITTED; // add RTF_COMMITTED flag to let dir entry be flushed to disk in UpdateDirEntry()
         UpdateDirEntry(f);

         break;
      default:
         break;
      case XFINALLY:

         #ifdef __FS_OPEN_HINT__
         MTHintFinish((FS_OpenHintInt*)hint);
         #endif

         if (f) FreeFTSlotAndDevice(f);
         break;
   XEND_API
   return RTF_NO_ERROR;
}

/*-----------------------------------*/
int RTFAPI RTFSetVolumeLabel(const WCHAR * DriveName, const WCHAR * Label)
{
   RTFile *volatile f = NULL;
   RTFile *volatile f_new = NULL;
   RTFDOSDirEntry * D;
   RTFDirLocation   DSR;
   BYTE             CheckSum = 0;
   int              LFNIndex;
   int volatile     rename_state = 0; /* Fix disk full will make both two files gone, Karen Hsu, 2004/10/27, ADD */
   int volatile     result = RTF_NO_ERROR;

   XTRY
      case XCODE:

         f = ParseFileName((char *)DriveName);
         f_new = ParseFileName((char *)DriveName);

         if (f->Drive == NULL)
         {
            fs_util_trace_err_noinfo(RTF_INVALID_FILENAME);

            XRAISE(RTF_INVALID_FILENAME);
         }
         if (f->Drive->MountState < HasFileSystem)
         {
            fs_util_trace_err_noinfo(RTF_INVALID_FILE_SYSTEM);

            XRAISE(RTF_INVALID_FILE_SYSTEM);
         }

         if (Label)
         {
            CheckValidVolumeLabel(Label);
         }
         else
         {
            XRAISE(FS_INVALID_FILENAME);
         }

         // search and delete any old label
         MakePseudoRootDirEntry(f->Drive, &f->DirEntry);
         f->DirEntry.DirCluster = FIRST_FILE_CLUSTER(f->DirEntry.Dir);
         D = StartDirSearch(f->Drive, f->DirEntry.DirCluster, 0, &DSR);

         LFNIndex = -1; // -1 means NO LFN (default value)

         while (D != NULL)
         {
            int Kind = EntryType(D);

            if (Kind == NeverUsed)
               break;
            else if (Kind == Lfn)   /* LFN found!! */
            {
               const LFNDirEntry *LD = (void*) D;

               if (LD->Ord & 0x40)  /* it's the start of an LFN */
               {
                  /* get the number of LFN */
                  LFNIndex = LD->Ord & 0x3F;

                  /* get checksum */
                  CheckSum = LD->CheckSum;
                  f->DirEntry.LongPos = DSR;
               }

               /* ohoh! checksum is not right! get rid of it!*/
               if ((LD->CheckSum != CheckSum) || (LFNIndex != (LD->Ord & 0x3F)) || (LFNIndex <= 0))
                  LFNIndex = -1;
            }
            /* volume label file is found!! */
            else if ((Kind == InUse) && ((D->Attributes & ~RTF_ATTR_ARCHIVE) == RTF_ATTR_VOLUME))
            {
                // preserve old SFN in case restore is required
                f->DirEntry.Dir = *D;
                f->DirEntry.ShortPos = DSR;
                f->PrivateFlags |= FS_PRIVATE_FLAG_IGNORE_SFN_GENERATION;   // to preserve the original name, CreateNewDirEntry do not need to generate SFN again!

                break;
            }

            if (Kind != Lfn)
            {
               LFNIndex = -1;   // reset LFN if this is a SFN

               f->DirEntry.LongPos.Cluster = 0;     // reset LongPos to avoid deleting the file just above the Volume Label if Volume Label only has SFN entry
            }

            D = NextDir(f->Drive, &DSR);
         }

         /*
          * Check if new label can be transformed to SFN correctly by current encoding
          * For failed case, GenerateVolumeLabel will raise exception.
          */
         GenerateVolumeLable((char *)Label, f_new->DirEntry.Dir.FileName);

         // if old Volume Label is found, get rid of it (both SFN and LFN)
         if (f->DirEntry.ShortPos.Cluster)
         {
            DeleteDirEntry(f);
            rename_state = 1;
         }

         // install new one
         if (Label)
         {
            setASCII(f_new->FullName, 0, 'X');
            setASCII(f_new->FullName, 1, ':');
            setASCII(f_new->FullName, 2, '\\');
            kal_dchar_strcat(f_new->FullName, (char *)Label);
            f_new->FullName[0] = MT_BASE_DRIVE_LETTER + f_new->Drive - gFS_Data.DriveTable;

            MakePseudoRootDirEntry(f_new->Drive, &f_new->DirEntry);
            f_new->DirEntry.DirCluster = FIRST_FILE_CLUSTER(f_new->DirEntry.Dir);

            kal_mem_set((void*)&f_new->DirEntry.Dir, 0, sizeof(f_new->DirEntry.Dir));
            f_new->DirEntry.Dir.Attributes = RTF_ATTR_VOLUME;
            RTFSYSGetDateTime(&f_new->DirEntry.Dir.DateTime);
            f_new->DirEntry.Dir.CreateDateTime = f_new->DirEntry.Dir.DateTime;
            CreateNewDirEntry(f_new, NULL);
            rename_state = 2;
         }

         // update boot record
         {
            RTFBootRecord * BR = GetBuffer(f_new->Dev, f_new->Drive->FirstSector, 0);
            RTFExtendedBIOSParameter * EBPB = (f_new->Drive->FATType == 32) ? &BR->BP.E._32.BPB : &BR->BP.E._16.BPB;

            /* copy only 11 characters from Label to PBR */
            memcpy((char*)EBPB->Label, Label ? (char*)f_new->DirEntry.Dir.FileName : "NO NAME    ", 11);
            SetDirty(f_new->Dev);
         }

         if ((FileCount(f_new->Dev) <= 1) || ((f_new->Dev->DeviceFlags & RTF_DEVICE_LAZY_WRITE) == 0))
            FlushAllBuffers(f_new->Dev);

         break;
      default:
      	 result = XVALUE;  // keep the result

         if (f)
         {
            // restore the original volume label if root dir full or disk full
            if(rename_state == 1)
            {
               CreateNewDirEntry(f, NULL);  // this should be successful because we use the original name
               if (((f->Dev->DeviceFlags & RTF_DEVICE_LAZY_WRITE) == 0) || (FileCount(f->Dev) <= 2))
                  FlushAllBuffers(f->Dev);
            }
         }
         break;
      case XFINALLY:
         if (f) FreeFTSlotAndDevice(f);
         if (f_new) FreeFTSlotAndDevice(f_new);
         break;
   XEND_API

   return result;
}

/*-----------------------------------*/
#if 0
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

/*-----------------------------------*/
RTFHANDLE RTFAPI RTFOpen(const WCHAR * FileName, kal_uint32 Flags, kal_uint32 caller_address)
{
   return RTFOpenFile(FileName, Flags, NULL, caller_address);
}

RTFHANDLE RTFAPI RTFOpenHint(const WCHAR * FileName, kal_uint32 Flags, RTFDirLocation * DSR_Hint, kal_uint32 caller_address)
{
   int volatile Result;

   if(DSR_Hint)
   {
       if(Flags & (RTF_CREATE | RTF_CREATE_ALWAYS))
       {
       	 /*
       	  * When creating a file, it not allowed to assign hint, or the file system may
       	  * create the file to an uncertain location.
       	  */
          DSR_Hint->Cluster = 0;
          DSR_Hint->Index = 0;
       }

       Result = RTFOpenFile(FileName, Flags, DSR_Hint, caller_address);

       /*
        * Find again without hint if original hint is invalid.
        *
        * Note: If hint is reset by user befire, then we do not need to find again because
        * the first RTFOpenHint has walked all files. (W10.20)
        */
       if ((Result < RTF_NO_ERROR) && ((DSR_Hint->Cluster != 0) || (DSR_Hint->Index != 0)))
       {
          DSR_Hint->Cluster = 0;
          DSR_Hint->Index   = 0;
          Result = RTFOpenFile(FileName, Flags, DSR_Hint, caller_address);
       }
   }
   else
   {
       Result = RTFOpenFile(FileName, Flags, NULL, caller_address);
   }

   return Result;
}

/*******************************************************************//**
 * Open a file
 *
 * @par Category:
 * File System
 *
 * @Change Log
 * W09.14: Return FS_NO_PROTECTIONMODE if driver does not support protection mode write function. (Stanley Chu)
 **********************************************************************/
RTFHANDLE RTFAPI RTFOpenFile(const WCHAR * FileName, kal_uint32 Flags, RTFDirLocation *DSR_Hint, kal_uint32 caller_address)
{
   int     volatile          Result;
   RTFile* volatile          f              = NULL;
   UINT                      search_option;
   WCHAR                    *fn_tail        = NULL;
   #ifdef __FS_OPEN_HINT__
   RTFDirLocation *volatile  hint = NULL;
   kal_uint8 volatile        internal_hint  = 0;
   kal_uint8 volatile        new_hint       = 0;
   #endif

   if (Flags & RTF_OPEN_DIR)
      Flags &= ~RTF_OPEN_NO_DIR;

   // Find hints from alread opened share files, check only normal files, and skip drive files (X:\)
    if ((Flags & RTF_OPEN_SHARED) && (kal_wstrlen(FileName)>3)) {
        RTFDirLocation hint_temp;

        f=FindSharing(FileName, &hint_temp);

        if (f!=NULL)    {  // The same file had been opened
            FS_HANDLE fh;
            kal_int32 i;
            RTFile* volatile fs;

            // Open the file using exising hint
            fh = RTFOpenFileByHint(FileName[0], hint_temp.Cluster, hint_temp.Index, Flags, caller_address);

            // Copy Filename and starting cluster, to the new handle (fh)
            if (fh>0)    {
                i = fh & ((1 << (4 * sizeof(int))) - 1);
                if (i<FS_MAX_FILES) {
                    fs = gFS_Data.FileTable + i;
                    fs->DirEntry.DirCluster = hint_temp.Cluster;
                    kal_wstrcpy((WCHAR*)fs->FullName, FileName);
                }
            }
            return fh;
        }
    }

   XTRY
      case XCODE:
         // check for invalid flag combinations
         if (Flags & RTF_CREATE_ALWAYS)
         {
            if (Flags & (RTF_READ_ONLY | RTF_ATTR_READ_ONLY))
            {
               fs_util_trace_err_noinfo(MT_READ_ONLY_ERROR);

               XRAISE(MT_READ_ONLY_ERROR);
            }

            if (Flags & (RTF_ATTR_DIR | RTF_ATTR_VOLUME))
            {
               fs_util_trace_err_noinfo(RTF_PARAM_ERROR);

               XRAISE(RTF_PARAM_ERROR);
            }
         }

         // protection mode and non-blocking mode should be exclusive.
         if ((Flags & FS_PROTECTION_MODE) && (Flags & FS_NONBLOCK_MODE))
         {
            fs_util_trace_err_noinfo(RTF_ATTR_CONFLICT);

            XRAISE(RTF_ATTR_CONFLICT);
         }

         if (Flags & RTF_COMMITTED)
            Flags &= ~RTF_LAZY_DATA;

         if (Flags & RTF_LAZY_DATA)
            Flags |= RTF_CACHE_DATA;

         // only RTFReopen will bring a file handle here
         // Pass FS_READ_ONLY flag (if existed) to LockDevice to allow READ-ONLY file be opened on busy device.
         f = ParseFileNameWithFlag((char *)FileName, Flags & FS_READ_ONLY);

         if ((Flags & FS_READ_ONLY) && (f->Dev->DeviceFlags & RTF_DEVICE_BUSY_READ_ONLY))
         {
            Flags |= FS_NOBUSY_CHECK_MODE;
         }

         // check if device supports protection mode write function
         if ((Flags & FS_PROTECTION_MODE) && (f->Dev->Driver->RecoverableWriteSectors == NULL))
         {
            fs_util_trace_err_noinfo(MT_NO_PROTECTIONMODE);

            XRAISE(MT_NO_PROTECTIONMODE);
         }

         if (f->SpecialKind == FileMapFile)
         {
            /* Flags has inherited from LargeFile already
             * ==> Change to force OR RTF_OPEN_SHARED flag, 2006/08/07, MOD
             */
            if ((Flags & (RTF_READ_ONLY) ) != (RTF_READ_ONLY))
            {
               fs_util_trace_err_noinfo(RTF_ACCESS_DENIED);

               XRAISE(RTF_ACCESS_DENIED);
            }

            f->Flags = Flags | RTF_OPEN_SHARED;

            kal_dchar_strcpy(f->FullName, (const char*)FileName);
         }
         else
         {
            f->Flags |= Flags;
         }

         if (f->SpecialKind != NormalFile)
         {
            MTCheckSharingWithSpecialKindFh(f);

            Result = MakeNewFileHandle(f);

            break;
         }
         else  // normal file
         {
            /*------------------------------------------------------------------
             * 1. Check if file name is valid to synchronize exception flow to MoDIS.
             * 2. Bypass leading "." to allow file name with leading ".".
             *------------------------------------------------------------------*/
            fn_tail = CheckValidFileName2(FileName, KAL_FALSE);
         }

         /* Fix write protect issue, Karen Hsu, 2004/04/07, ADD START */
         if ((Flags & RTF_CREATE_ALWAYS) || ((Flags & RTF_READ_ONLY) == 0))
         {
            if(f->Dev->DeviceFlags & MT_DEVICE_WRITE_PROTECT)
            {
               fs_util_trace_err_noinfo(RTF_WRITE_PROTECTION);

               XRAISE(RTF_WRITE_PROTECTION);
            }
         }

         // allow to release lock during search if READ_ONLY
         if (Flags & RTF_READ_ONLY)
            search_option = SEARCH_FILES | SEARCH_RELEASE_LOCK;
         else
            search_option = SEARCH_FILES;

         #ifdef __FS_OPEN_HINT__
         hint = MTHintGet(FileName, MT_HINT_ACTION_OPEN);

         if (hint)
         {
            internal_hint = 1; // must be internal hint
            new_hint = MTIsNewHint(hint);
            //fs_util_trace_info1(TRACE_GROUP_7|TRACE_INFO, FS_TRC_RTF_OPEN_FILE_HINT, KAL_TRUE, NULL);
         }
         else // can't get internal hint slot, use external hint if it exists.
         {
            hint = DSR_Hint;
            //fs_util_trace_info1(TRACE_GROUP_7|TRACE_INFO, FS_TRC_RTF_OPEN_FILE_HINT, KAL_FALSE, NULL);
         }

         if (SearchFile(f, search_option, (char *)FileName, hint))     // it does exist
         #else  /* !__FS_OPEN_HINT__ */
         if (SearchFile(f, search_option, (char *)FileName, DSR_Hint)) // it does exist
         #endif /* __FS_OPEN_HINT__ */
         {
            CheckSharing(f);

            if (Flags & RTF_CREATE_ALWAYS)
            {
               // Read-only, directory and volume file is not allowed to be deleted
               if (f->DirEntry.Dir.Attributes & (RTF_ATTR_READ_ONLY | RTF_ATTR_DIR | RTF_ATTR_VOLUME))
               {
                  fs_util_trace_err_noinfo(MT_READ_ONLY_ERROR);

                  XRAISE(MT_READ_ONLY_ERROR);
               }

               // Opened file is not allowed to be deleted (W09.26)
               CheckNotOpen(f);

               if (FIRST_FILE_CLUSTER(f->DirEntry.Dir) != 0)
               {
                  if (GetClusterValue(f->Drive, FIRST_FILE_CLUSTER(f->DirEntry.Dir)) != 0)   // do not delete FAT chains if it is a dangling FirstCluster
                  {
                      //quota
                      FATDelete(f->Drive, FIRST_FILE_CLUSTER(f->DirEntry.Dir), f);

                      if (Flags & RTF_COMMITTED)
                      {
                         FlushFAT(f->Dev);
                      }
                  }

                  SET_FIRST_FILE_CLUSTER(f->DirEntry.Dir, 0);
               }

               f->DirEntry.Dir.Attributes = Flags & RTF_ATTR_ANY;

               if (f->DirEntry.Dir.FileSize != 0)
               {
                  RTFSYSGetDateTime(&f->DirEntry.Dir.DateTime);
                  f->DirEntry.Dir.FileSize = 0;
               }

               /*
                * Use CREATE_ALWAYS for an existing file does not need to do anything
                * to internal hints because the location of this file is not changed.
                */

               UpdateDirEntry(f);
            }
            else // open an existing file
            {
               if ((f->DirEntry.Dir.Attributes & RTF_ATTR_READ_ONLY) && ((Flags & RTF_READ_ONLY) == 0))
               {
                  fs_util_trace_err_noinfo(MT_READ_ONLY_ERROR);

                  XRAISE(MT_READ_ONLY_ERROR);
               }

               // if this is a folder
               if ((f->DirEntry.Dir.Attributes & RTF_ATTR_DIR) != 0)
               {
                  if ((Flags & RTF_READ_ONLY) == 0) // return FS_READ_ONLY_ERROR if flag FS_READ_ONLY is not set
                  {
                     fs_util_trace_err_noinfo(MT_READ_ONLY_ERROR);

                     XRAISE(MT_READ_ONLY_ERROR);
                  }
                  else if ((Flags & RTF_OPEN_NO_DIR) != 0) // return FS_FILE_NOT_FOUND if flag FS_OPEN_DIR is set
                  {
                     fs_util_trace_err_noinfo(RTF_FILE_NOT_FOUND);

                     XRAISE(RTF_FILE_NOT_FOUND);
                  }
               }
               else // this is a file
               {
                  if ((NULL != fn_tail) && (L'\\' == *fn_tail)) // if FileName's tail is L'\\', always returns FS_INVALID_FILENAME (to sync with MoDIS)
                  {
                      fs_util_trace_err_noinfo(RTF_FILE_EXISTS);

                      XRAISE(RTF_FILE_EXISTS);
                  }

                  if ((Flags & RTF_OPEN_DIR) != 0) // if user want to open a DIR but this is a FILE, return FS_FILE_NOT_FOUND
                  {
                     fs_util_trace_err_noinfo(RTF_FILE_NOT_FOUND);

                     XRAISE(RTF_FILE_NOT_FOUND);
                  }
               }

               CheckDirEntry(f);
               InitFilePointer(f);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
            }
            #ifdef __FS_OPEN_HINT__
            if (internal_hint)
            {
               if (DSR_Hint) // fill-in external hint (otherwise, some feature like MTP will not work!)
               {
                  DSR_Hint->Cluster = hint->Cluster;
                  DSR_Hint->Index   = hint->Index;

                  ((RTFFileOpenHint*)DSR_Hint)->Drive = (UINT)f->Drive;
                  ((RTFFileOpenHint*)DSR_Hint)->SerialNumber = f->Drive->SerialNumber;
                  ((RTFFileOpenHint*)DSR_Hint)->Stamp = OpenHintStamp;
               }
            }
            #endif /* __FS_OPEN_HINT__ */
         }
         else // it does not exist
         {
            if (Flags & (RTF_CREATE_ALWAYS | RTF_CREATE))
            {
               if(f->Dev->DeviceFlags & MT_DEVICE_WRITE_PROTECT)
               {
                  fs_util_trace_err_noinfo(RTF_WRITE_PROTECTION);

                  XRAISE(RTF_WRITE_PROTECTION);
               }

               if (Flags & RTF_READ_ONLY)
               {
                  fs_util_trace_err_noinfo(MT_READ_ONLY_ERROR);

                  XRAISE(MT_READ_ONLY_ERROR);
               }

               MTCheckSharingWithSpecialKindFh(f);

               CheckValidFileName2((WCHAR *)f->FullName, KAL_FALSE);
               kal_mem_set((void*)&f->DirEntry.Dir, 0, sizeof(f->DirEntry.Dir));
               f->DirEntry.Dir.Attributes = Flags & RTF_ATTR_ANY;
               RTFSYSGetDateTime(&f->DirEntry.Dir.DateTime);
               f->DirEntry.Dir.CreateDateTime = f->DirEntry.Dir.DateTime;

               #ifdef __FS_OPEN_HINT__
               CreateNewDirEntry(f, (FS_OpenHintInt*)hint);
               #else
               CreateNewDirEntry(f, NULL);
               #endif /* __FS_OPEN_HINT__ */

               if (Flags & RTF_COMMITTED)
               {
                  CommitDirEntry(f);
                  FlushFAT(f->Dev);
               }

               if (DSR_Hint) // fill-in external hint
               {
                   if(f->DirEntry.LongPos.Cluster)
                   {
                       DSR_Hint->Cluster = f->DirEntry.LongPos.Cluster;
                       DSR_Hint->Index   = f->DirEntry.LongPos.Index;
                   }
                   else
                   {
                       DSR_Hint->Cluster = f->DirEntry.ShortPos.Cluster;
                       DSR_Hint->Index   = f->DirEntry.ShortPos.Index;
                   }

                   ((RTFFileOpenHint*)DSR_Hint)->Drive = (UINT)f->Drive;
                   ((RTFFileOpenHint*)DSR_Hint)->SerialNumber = f->Drive->SerialNumber;
                   ((RTFFileOpenHint*)DSR_Hint)->Stamp = OpenHintStamp;

                   #ifdef __FS_OPEN_HINT__
                   if (hint)
                   {
                      /*
                       * Guide: Check internal_hint and new_hint, if (internal_hint == 1 && new_hint == 0),
                       *        there might be some hints which is not invalidated after file deletion.
                       */
                      if ((DSR_Hint->Cluster != hint->Cluster) || (DSR_Hint->Index != hint->Index))
                      {
                         fs_assert_local(0);
                      }
                   }
                   #endif
               }
            }
            else
            {
               fs_util_trace_err_noinfo(RTF_FILE_NOT_FOUND);

               XRAISE(RTF_FILE_NOT_FOUND);
            }
         }
         InitFilePointer(f);

         Result = MakeNewFileHandle(f);

         break;
      default:
         Result = XVALUE;

         // give hint about invalid VF's parent file
         if (f)
         {
            if (f->SpecialKind == FileMapFile && Result == FS_INVALID_FILE_HANDLE)
            {
                Result = XVALUE = FS_ERR_VF_PARENT_CLOSED;

                fs_util_trace_info0(TRACE_FUNC, FS_TRC_ERR_VF_PARENT_CLOSED, NULL);
            }
         }

         break;
      case XFINALLY:

         #ifdef __FS_OPEN_HINT__
         if (internal_hint && new_hint)
            MTHintFinish((FS_OpenHintInt*)hint);
         #endif

         if (f)
         {
            if (Result < RTF_NO_ERROR)  {
               if (Result==RTF_BAD_DIR_ENTRY || Result==RTF_FAT_ALLOC_ERROR)    {
                    kal_buffer_trace(TRACE_ERROR, FS_INFO_DIR_ENTRY, sizeof(RTFDirEntry), (kal_uint8*)&(f->DirEntry));
               }
               FreeFTSlotAndDevice(f);
            }
            else
            {
               f->OwnerLR=caller_address;

               #if defined(__FS_TRACE_SUPPORT_OPEN_HINT__)

               #if 0
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

               #endif /* __FS_TRACE_SUPPORT_OPEN_HINT__ */

               UnlockDevice(f->Dev);
            }
         }
         break;
   XEND_API
   return Result;
}

/*-----------------------------------*/
/* FIXME: This Function doesn't referenced by any public API */
int RTFAPI RTFMakeTempFileName(const WCHAR * DirName, WCHAR * FileName, UINT MaxLength)
{
   RTFile * volatile f = NULL;
   RTFDirLocation DSR;
   RTFDOSDirEntry * D;
   char ShortName[13];
   kal_uint32 TimeStamp;
   WCHAR tempFileName[]={0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x2e,0x54,0x4d,0x50,0x00};

   XTRY
      case XCODE:
         f = ParseFileName((char *)DirName);
         if (f->SpecialKind != NormalFile)
         {
            fs_util_trace_err_noinfo(RTF_PATH_NOT_FOUND);

            XRAISE(RTF_PATH_NOT_FOUND);
         }

         if (!SearchFile(f, SEARCH_FILES|SEARCH_RELEASE_LOCK, (char *)DirName, NULL)) // it does exist
         {
            fs_util_trace_err_noinfo(RTF_PATH_NOT_FOUND);

            XRAISE(RTF_PATH_NOT_FOUND);
         }

         if ((f->DirEntry.Dir.Attributes & RTF_ATTR_DIR) == 0)
         {
            fs_util_trace_err_noinfo(RTF_PATH_NOT_FOUND);

            XRAISE(RTF_PATH_NOT_FOUND);
         }

         // create a unique name
         GenerateShortName((char *)tempFileName, (char *)f->DirEntry.Dir.FileName); /* Remove RVCT warning, Karen Hsu, 2004/11/02, MOD */
         RTFSYSGetDateTime((void*) &TimeStamp);
Retry:
         fs_util_char_to_hex((char *)f->DirEntry.Dir.FileName, TimeStamp); /* Remove RVCT warning, Karen Hsu, 2004/11/02, MOD */
         MakeShortFileName(&f->DirEntry.Dir, ShortName, 13);

         D = StartDirSearch(f->Drive, FIRST_FILE_CLUSTER(f->DirEntry.Dir), 0, &DSR);
         while (D != NULL)
         {
            int Kind = EntryType(D);
            if (Kind == InUse)
            {
               char Temp[14];
               MakeShortFileName(D, Temp, 13);
               if (FNamesMatch(ShortName, Temp))
               {
                  TimeStamp++;
                  goto Retry;
               }
            }
            else if ((Kind == Lfn) && (D->FileName[0] == 0x41)) // Check LD->Ord to check short name against long name
            {
               char Temp[26];
               const LFNDirEntry * LD = (void*) D;
               kal_mem_set(Temp, 0, sizeof(Temp)); // zero terminate Temp
               CopyLFN_toShort(Temp, LD);
               if (FNamesMatch(ShortName, Temp))
               {
                  TimeStamp++;
                  goto Retry;
               }
            }
            else if (Kind == NeverUsed)
               break;
            D = NextDir(f->Drive, &DSR);
         }

         // when we are here, the name is unique
         if ( (f->FullName[kal_dchar_strlen(f->FullName)-2] != 0x5c) )
            setASCII(f->FullName, (kal_dchar_strlen(f->FullName) >> 1), '\\');
         kal_dchar_strcat(f->FullName, ShortName);

         if (MaxLength <= kal_dchar_strlen(f->FullName))
         {
            fs_util_trace_err_noinfo(RTF_STRING_BUFFER_TOO_SMALL);

            XRAISE(RTF_STRING_BUFFER_TOO_SMALL);
         }

         kal_dchar_strcpy((char *)FileName, f->FullName);

         f->DirEntry.DirCluster = FIRST_FILE_CLUSTER(f->DirEntry.Dir);
         kal_mem_set((void*)&f->DirEntry.Dir, 0, sizeof(f->DirEntry.Dir));
         RTFSYSGetDateTime(&f->DirEntry.Dir.DateTime);
         f->DirEntry.Dir.CreateDateTime = f->DirEntry.Dir.DateTime;
         CreateNewDirEntry(f, NULL);

         if (((f->Dev->DeviceFlags & RTF_DEVICE_LAZY_WRITE) == 0) || (FileCount(f->Dev) <= 1))
            FlushAllBuffers(f->Dev);

         break;
      default:
         break;
      case XFINALLY:
         if (f) FreeFTSlotAndDevice(f);
         break;
   XEND_API
   return RTF_NO_ERROR;
}

/*-----------------------------------*/
int RTFAPI RTFDelete(const WCHAR * FileName)
{
   RTFile *volatile         f = NULL;
   volatile int             start_fat_deletion = 0;
   #ifdef __FS_OPEN_HINT__
   RTFDirLocation *volatile hint = NULL;
   #endif

   XTRY
      case XCODE:

         f = ParseFileName((char *)FileName);

         if(f->Dev->DeviceFlags & MT_DEVICE_WRITE_PROTECT)
         {
            fs_util_trace_err_noinfo(RTF_WRITE_PROTECTION);

            XRAISE(RTF_WRITE_PROTECTION);
         }

         /**
          * 1. Add RTF_OPEN_SHARED flag to prevent ACCESS DENIED issue if SearchFile()
          * stays in some folders too long (W09.28)
          *
          * NOTE. Before delete entry, CheckNotOpen(f) will promise the deleted file
          * is not opened.
          *
          * 2. Add RTF_COMMITTED to ensure deleted dir entry be flushed before FAT table. (W10.37)
          */
         f->Flags = RTF_READ_WRITE | RTF_OPEN_SHARED | RTF_COMMITTED;

         if (f->SpecialKind != NormalFile)
         {
            fs_util_trace_err_noinfo(RTF_INVALID_FILENAME);

            XRAISE(RTF_INVALID_FILENAME);
         }

         #ifdef __FS_OPEN_HINT__
         hint = MTHintGet(FileName, MT_HINT_ACTION_FORCE_NO_NEW);
         if (!SearchFile(f, SEARCH_FILES | SEARCH_RELEASE_LOCK, (char *)FileName, hint))
         #else
         if (!SearchFile(f, SEARCH_FILES | SEARCH_RELEASE_LOCK, (char *)FileName, NULL))
         #endif /* __FS_OPEN_HINT__ */
         {
            fs_util_trace_err_noinfo(RTF_FILE_NOT_FOUND);

            XRAISE(RTF_FILE_NOT_FOUND);
         }

         // After SearchFile() find this file, device lock should not be released to other tasks.
         // Thus RTF_OPEN_SHARED flag does not have to be clear.
         // f->Flags &= ~RTF_OPEN_SHARED;

         CheckNotOpen(f);

         if (f->DirEntry.Dir.Attributes & (RTF_ATTR_DIR | RTF_ATTR_VOLUME))
         {
            fs_util_trace_err_noinfo(MT_READ_ONLY_ERROR);

            XRAISE(MT_READ_ONLY_ERROR);
         }

         DeleteDirEntry(f);   // RTF_COMMITTED flag will ensure deleted SFN entry be flushed here!

         #ifdef __FS_OPEN_HINT__
         /*
          * internal hint does not support relative path currently,
          * invalidate all possible hints if relative path is used.
          */
         if (FileName[1] != L':' || FileName[2] != L'\\')
            MTHintExpireByDrive(f->Drive);
         else
         {
            if (hint)
            {
               #ifdef __FS_TEST__
               fs_assert_local(MTHintGetMatchType(hint) != MT_HINT_MATCH_TARGET_END);
               #endif

               // delete perfect matched hint
               if (MTHintGetMatchType(hint) == MT_HINT_MATCH_PERFECT)
               {
                  MTHintDelete(MTHintGetIndex(hint));
               }
            }
         }
         #endif /* __FS_OPEN_HINT__ */

         if (FIRST_FILE_CLUSTER(f->DirEntry.Dir) != 0)
         //quota
         {
            start_fat_deletion = 1;
            FATDelete(f->Drive, FIRST_FILE_CLUSTER(f->DirEntry.Dir), f);
         }

         if (((f->Dev->DeviceFlags & RTF_DEVICE_LAZY_WRITE) == 0) || (FileCount(f->Dev) <= 1))
            FlushAllBuffers(f->Dev);

         break;
      default:
         if (start_fat_deletion && XVALUE == RTF_FAT_ALLOC_ERROR)
            XHANDLED;
         break;
      case XFINALLY:

         if (f) FreeFTSlotAndDevice(f);

         break;
   XEND_API
   return RTF_NO_ERROR;
}

/*-----------------------------------*/
static int INTERN PathContains(RTFDrive * Drive, RTFCluster StartCluster, const RTFCluster Cluster)
{
   RTFDirLocation DSR;
   const RTFDOSDirEntry * D;

   while (1)
   {
      if (StartCluster == Cluster)
         return 1; // clash
      D = StartDirSearch(Drive, StartCluster, 1, &DSR); // second entry should be ".."
      if ((EntryType(D) == InUse) && (memcmp((char*)D->FileName, ".. ", 3) == 0))
      {
         StartCluster = FIRST_FILE_CLUSTER(*D);
         if (StartCluster == 0)
            return 0;  // back to root
      }
      else
         return 0; // we are in the root
   }
}

/*-----------------------------------*/
static int INTERN MTCheckPathOpen(RTFile * File)
{
   UINT i;
   RTFile * f = gFS_Data.FileTable;

   for (i = 0; i < FS_MAX_FILES; i++, f++)
      if ((f != File) &&
          (f->Drive == File->Drive) &&
          (f->DirEntry.DirCluster != 0) &&  // do not check "X:\" case
          PathContains(f->Drive, f->DirEntry.DirCluster, FIRST_FILE_CLUSTER(File->DirEntry.Dir)))
         return 1;

   return 0;
}

/*-----------------------------------*/
int RTFAPI RTFRename(const WCHAR * FileName, const WCHAR * NewName)
{
   RTFile *volatile         f1           = NULL;
   RTFile *volatile         f2           = NULL;
   kal_bool volatile rename_state_1 = KAL_FALSE;
   kal_bool volatile rename_state_2 = KAL_FALSE;
   int volatile             result       = RTF_NO_ERROR;
   #ifdef __FS_OPEN_HINT__
   RTFDirLocation *volatile hint_int     = NULL;
   #endif

   XTRY
      case XCODE:
         f1 = ParseFileName((char *)FileName);
         UnlockDevice(f1->Dev);

         /* Fix write protect issue, Karen Hsu, 2004/04/07, ADD START */
         if(f1->Dev->DeviceFlags & MT_DEVICE_WRITE_PROTECT)
         {
            fs_util_trace_err_noinfo(RTF_WRITE_PROTECTION);

            XRAISE(RTF_WRITE_PROTECTION);
         }
         /* Fix write protect issue, Karen Hsu, 2004/04/07, ADD END */

         if (f1->SpecialKind != NormalFile)
         {
            fs_util_trace_err_noinfo(RTF_INVALID_FILENAME);

            XRAISE(RTF_INVALID_FILENAME);
         }

         f2 = ParseFileName((char *)NewName);

         if (f2->SpecialKind != NormalFile)
         {
            fs_util_trace_err_noinfo(RTF_INVALID_FILENAME);

            XRAISE(RTF_INVALID_FILENAME);
         }

         if (f1->Drive != f2->Drive)
         {
            fs_util_trace_err_noinfo(RTF_ACCESS_DENIED);
            fs_util_trace_info0(NULL, FS_ERR_RTFRENAME_DRIVE_NOT_THE_SAME, NULL);

            XRAISE(RTF_ACCESS_DENIED);
         }

         #ifdef __FS_OPEN_HINT__
         hint_int = MTHintGet(FileName, MT_HINT_ACTION_FORCE_NO_NEW);
         if (!SearchFile(f1, SEARCH_FILES, (char *)FileName, hint_int))
         #else
         if (!SearchFile(f1, SEARCH_FILES, (char *)FileName, NULL))
         #endif /* __FS_OPEN_HINT__ */
         {
            fs_util_trace_err_noinfo(RTF_FILE_NOT_FOUND);

            XRAISE(RTF_FILE_NOT_FOUND);
         }

         #ifdef __FS_OPEN_HINT__
         // delete hint for original file name
         if (hint_int && (MTHintGetMatchType(hint_int) == MT_HINT_MATCH_PERFECT))
            MTHintDelete(MTHintGetIndex(hint_int));

         // create hint for new file name
         hint_int = MTHintGet(NewName, MT_HINT_ACTION_OPEN);  // NOTE: use the same internal hint
         if (SearchFile(f2, SEARCH_FILES, (char *)NewName, hint_int) != 0)
         #else
         if (SearchFile(f2, SEARCH_FILES, (char *)NewName, NULL) != 0)
         #endif /* __FS_OPEN_HINT__ */
         {

            #ifdef __FS_OPEN_HINT__
            /*
             * If target file is found, cancel hint creating process because the hint is completed (with old name).
             * Otherwise CreateNewDirEntry will append file name to this "completed" hint like
             * C:\folder\target.txt\target.txt
             */
            if (hint_int)
            {
                MTHintDiscard(MTHintGetIndex(hint_int));
                hint_int = NULL;
            }
            #endif // __FS_OPEN_HINT__

            CheckValidFileName2((WCHAR*)f2->FullName, KAL_FALSE); /* Fix ended with dot, Karen Hsu, 2004/05/26, ADD*/

            if (SAME_DIR_ENTRY(f1->DirEntry.ShortPos, f2->DirEntry.ShortPos))
            /* For capital sensitive, Karen Hsu, 2004/07/07, MOD START */
            {
               if(kal_dchar_strcmp((char*)FileName, (char*)NewName) != 0)
               {
                  WCHAR *pFullName;
                  const WCHAR *pNewName;

                  // locate pFullName at <tail - 1>
                  for (pFullName = (WCHAR*)f2->FullName;
                       *pFullName != 0x0000;
                       pFullName++
                      );
                  pFullName--;

                  // locate pNewName at <tail - 1>
                  for (pNewName = NewName;
                       *pNewName != 0x0000;
                       pNewName++
                      );
                  pNewName--;

                  // shift if pNewName contain backslash tail
                  if (*pNewName == 0x005C)
                  {
                     pNewName--;
                  }

                  // copy pNewName to pFullName in reverse order
                  for ( ;
                        (*pFullName != 0x005C) && (*pNewName != 0x005C);
                        pFullName-- , pNewName--
                      )
                  {
                     *pFullName = *pNewName;
                  }

                  // Make sure Name Segment length equalience to NewName
                  if (*pFullName != *pNewName)
                  {
                  // fall through and do nothing
                  }
                  else
                  {
                     CheckNotOpen2(f1, f2);
                     goto RenameContinue;
                  }
               }
               break; // do nothing
            }
            /* For capital sensitive, Karen Hsu, 2004/07/07, MOD END */
            else
            /* Avoid to confuse user, Karen Hsu, 2004/04/22, MOD START */
            {
               fs_util_trace_err_noinfo(RTF_FILE_EXISTS);

               XRAISE(RTF_FILE_EXISTS);
            }
            /* Avoid to confuse user, Karen Hsu, 2004/04/22, MOD END */
         }
         else
         {
            // do not use the field NTReserved of the parent folder
            f2->DirEntry.Dir.NTReserved = 0;
         }

         CheckValidFileName2((WCHAR*)f2->FullName, KAL_FALSE);

         CheckNotOpen(f1);

         if ((f1->DirEntry.Dir.Attributes & RTF_ATTR_DIR) &&
              // do not rename a directory if there is a child file/directory opened
             (MTCheckPathOpen(f1) ||
              // do not move the a component of the current directory
              PathContains(f1->Drive, FIRST_FILE_CLUSTER(f1->Drive->CurrDirEntry.Dir), FIRST_FILE_CLUSTER(f1->DirEntry.Dir)) ||
              // do not move f1 to it's own child
              PathContains(f1->Drive, f2->DirEntry.DirCluster, FIRST_FILE_CLUSTER(f1->DirEntry.Dir))))
         {
            fs_util_trace_err_noinfo(RTF_ACCESS_DENIED);

            XRAISE(RTF_ACCESS_DENIED);
         }

RenameContinue:
         // do it
         DeleteDirEntry(f1);
         rename_state_1 = KAL_TRUE;

         #ifdef __FS_OPEN_HINT__
         CreateNewDirEntry(f2, (FS_OpenHintInt*)hint_int);
         #else
         CreateNewDirEntry(f2, NULL);
         #endif /* __FS_OPEN_HINT__ */
         rename_state_2 = KAL_TRUE;

         // copy directory information except name/ext over
         // reserve NTReserved for file name case indicator
         memcpy((char*)&f2->DirEntry.Dir.CreateTimeTenthSecond,
                (char*)&f1->DirEntry.Dir.CreateTimeTenthSecond,
                        sizeof(f2->DirEntry.Dir) - 8 - 3 - 2);
         f2->DirEntry.Dir.Attributes = f1->DirEntry.Dir.Attributes;

         // commit
         {
            RTFDOSDirEntry * D = GetDir(f2->Drive, &f2->DirEntry.ShortPos);
            *D = f2->DirEntry.Dir;
            SetDirty(f2->Dev);
         }

         // if we moved a dir, then we must adjust the .. entry
         if (f2->DirEntry.Dir.Attributes & RTF_ATTR_DIR)
         {
            RTFDOSDirEntry * D = GetBuffer(f2->Dev, CLUSTER_TO_SECTOR(f2->Drive, FIRST_FILE_CLUSTER(f2->DirEntry.Dir)), 0);
            RTFCluster NewParentCluster = f2->DirEntry.DirCluster;

            if ((NewParentCluster == RTF_ROOT_DIR)
#if !defined(__NOT_SUPPORT_FAT32__)
                || ((f2->Drive->FATType == RTFAT32) &&
                 (NewParentCluster == f2->Drive->FirstDirSector))
#endif /* __NOT_SUPPORT_FAT32__ */
            )
            {
               NewParentCluster = 0;
            }

            if (FIRST_FILE_CLUSTER(D[1]) != NewParentCluster)
            {
               SET_FIRST_FILE_CLUSTER(D[1], NewParentCluster);
               SetDirty(f2->Dev);
            }
         }

         if (((f2->Dev->DeviceFlags & RTF_DEVICE_LAZY_WRITE) == 0) || (FileCount(f2->Dev) <= 2))
            FlushAllBuffers(f2->Dev);
         break;

      default:
         result = XVALUE;

         if (f1)
         {
            /* Fix disk full will make both two files gone, Karen Hsu, 2004/10/27, ADD START */
            if(rename_state_1 && !rename_state_2)
            {
               CreateNewDirEntry(f1, NULL);
               if (((f1->Dev->DeviceFlags & RTF_DEVICE_LAZY_WRITE) == 0) || (FileCount(f1->Dev) <= 2))
                  FlushAllBuffers(f1->Dev);
            }
            /* Fix disk full will make both two files gone, Karen Hsu, 2004/10/27, ADD END */
         }
         break;
      case XFINALLY:
         #ifdef __FS_OPEN_HINT__
         // only "new hint" requires MTHintFinish()
         if (hint_int && MTIsNewHint(hint_int))
            MTHintFinish((FS_OpenHintInt*)hint_int);
         #endif /* __FS_OPEN_HINT__ */

         if (f1) FreeFTSlot(f1); // device is unlocked right after ParseFileName(filename1), see above
         if (f2) FreeFTSlotAndDevice(f2);
         break;
   XEND_API

   return result;
}

/*-----------------------------------*/
int RTFAPI RTFGetAttributes(const WCHAR * FileName)
{
   int volatile               Result;
   RTFile *volatile           f     = NULL;
   #ifdef __FS_OPEN_HINT__
   RTFDirLocation *volatile   hint  = NULL;
   #endif

   XTRY
      case XCODE:
         CheckValidFileName2(FileName, KAL_FALSE);
         f = ParseFileName((char *)FileName);

         // to avoid ACCESS DENIED issue when searching files
         f->Flags |= RTF_READ_ONLY;

         if (f->SpecialKind != NormalFile)
         {
            fs_util_trace_err_noinfo(RTF_INVALID_FILENAME);

            XRAISE(RTF_INVALID_FILENAME);
         }

         #ifdef __FS_OPEN_HINT__
         hint = MTHintGet(FileName, MT_HINT_ACTION_OPEN);
         if (SearchFile(f, SEARCH_FILES|SEARCH_RELEASE_LOCK, (char *)FileName, hint))
         #else
         if (SearchFile(f, SEARCH_FILES|SEARCH_RELEASE_LOCK, (char *)FileName, NULL))
         #endif /* __FS_OPEN_HINT__ */
            Result = f->DirEntry.Dir.Attributes;
         else
         {
            fs_util_trace_err_noinfo(RTF_FILE_NOT_FOUND);

            XRAISE(RTF_FILE_NOT_FOUND);
         }

         break;

      default:
         break;

      case XFINALLY:

         #ifdef __FS_OPEN_HINT__
         if (hint && MTIsNewHint(hint)) MTHintFinish((FS_OpenHintInt*)hint);
         #endif

         if (f) FreeFTSlotAndDevice(f);

         break;
   XEND_API
   return Result;
}

/*-----------------------------------*/
int RTFAPI RTFSetAttributes(const WCHAR * FileName, BYTE Attributes)
{
   RTFile * volatile f = NULL;

   Attributes &= RTF_ATTR_ANY;

   XTRY
      case XCODE:
         f = ParseFileName((char *)FileName);

         /* Fix write protect issue, Karen Hsu, 2004/09/15, ADD START */
         if(f->Dev->DeviceFlags & MT_DEVICE_WRITE_PROTECT)
         {
            fs_util_trace_err_noinfo(RTF_WRITE_PROTECTION);

            XRAISE(RTF_WRITE_PROTECTION);
         }
         /* Fix write protect issue, Karen Hsu, 2004/09/15, ADD END */

         if (f->SpecialKind != NormalFile)
         {
            fs_util_trace_err_noinfo(RTF_INVALID_FILENAME);

            XRAISE(RTF_INVALID_FILENAME);
         }

         if (!SearchFile(f, SEARCH_FILES|SEARCH_RELEASE_LOCK, (char *)FileName, NULL))
         {
            fs_util_trace_err_noinfo(RTF_FILE_NOT_FOUND);

            XRAISE(RTF_FILE_NOT_FOUND);
         }

         if (f->DirEntry.Dir.Attributes != Attributes)
         {
            // if it's a root dir, just return now
            if (f->DirEntry.DirCluster == 0)    // it's a root dir
            {
               fs_util_trace_err_noinfo(RTF_ACCESS_DENIED);

               XRAISE(RTF_ACCESS_DENIED);
            }

            // volume labels are not allowed
            // dir is not allowed
            if ((f->DirEntry.Dir.Attributes ^ Attributes) & (RTF_ATTR_DIR | RTF_ATTR_VOLUME))
            {
               fs_util_trace_err_noinfo(RTF_ACCESS_DENIED);

               XRAISE(RTF_ACCESS_DENIED);
            }

            f->DirEntry.Dir.Attributes = Attributes;

            f->Flags |= RTF_COMMITTED;

            UpdateDirEntry(f);

            if (((f->Dev->DeviceFlags & RTF_DEVICE_LAZY_WRITE) == 0) || (FileCount(f->Dev) <= 1))
            {
                FlushAllBuffers(f->Dev);
            }

         }
         break;
      default:
         break;
      case XFINALLY:
         if (f) FreeFTSlotAndDevice(f);
         break;
   XEND_API
   return RTF_NO_ERROR;
}

/*-----------------------------------*/
int RTFAPI RTFExpandName(WCHAR * FileName, UINT MaxLength)
{
   RTFile * volatile f = NULL;
   const char * pN = (char *)FileName;
   const char * pN2;
   char * pF;
   int l;

   XTRY
      case XCODE:
         f = ParseFileName((char *)FileName);
         pF = f->FullName;

         if ( compASCII(pN, 1, ':') )
            pN += 4;

         kal_dchar_strcpy(pF, f->Drive->CurrDir);

         // if the next char is a "\", we have an abs path
         if ( compASCII(pN, 0, '\\'))
         {
            pN+=2;
            pF+=6;
            setASCII(pF,0,'\0');
         }
         else // it's a relative path
            pF+=kal_dchar_strlen(pF);

         while (pN)
         {
            // skip any "." and multiple "\"
            while ( (WFNamesMatch(pN, (char *)dchar_dot)) || (compASCII(pN,0,'\\')) )
               pN+=2;

            if ( compASCII(pN,0,0) ) //found
               break;

            if ( !compASCII(pF,-1,'\\') )
            {
               setASCII(pF,0,'\\');
               pF++;
            }

            pN2 = kal_dchar_strchr(pN, '\\');
            if ( WFNamesMatch(pN, (char *)dchar_dot_dot))
            {
               setASCII(pF,-1,'\0');
               pF = kal_dchar_strrchr(f->FullName, '\\');
               if (pF == NULL)
               {
                  fs_util_trace_err_noinfo(RTF_PATH_NOT_FOUND);

                  XRAISE(RTF_PATH_NOT_FOUND);
               }
               if ((pF-6) < f->FullName)
                  pF+=2;
               setASCII(pF,0,'\0');
            }
            else
            {
               if (pN2)
                  l = pN2 - pN;
               else
                  l = kal_dchar_strlen(pN);
               memcpy((void*)pF, (void*)pN, l);
               pF += l;
            }
            pN = pN2;
         }

         if (kal_dchar_strlen(f->FullName) < MaxLength)
            kal_dchar_strcpy((char *)FileName, f->FullName);
         else
         {
            fs_util_trace_err_noinfo(RTF_STRING_BUFFER_TOO_SMALL);

            XRAISE(RTF_STRING_BUFFER_TOO_SMALL);
         }
         break;

      default:
         break;
      case XFINALLY:
         if (f) FreeFTSlotAndDevice(f);
         break;
   XEND_API
   return RTF_NO_ERROR;
}

/*-----------------------------------*/
int RTFAPI RTFClose(RTFHANDLE File)
{
   return RTFCloseFile(File, RTFFREESLOT);
}

/*-----------------------------------*/
int RTFAPI RTFCloseFile(RTFHANDLE File, BYTE freeSlot)
{
   RTFile * volatile  f = NULL;
   RTFHANDLE volatile fh = File;
   int volatile       result = RTF_NO_ERROR;

   XTRY
      case XCODE:
         f = ParseFileHandle(File);

         if (FileCount(f->Dev) <= 1)
            FlushAllBuffers(f->Dev);    // always flush all when last file is closed
         else
            if (((f->Dev->DeviceFlags & RTF_DEVICE_LAZY_WRITE) == 0) &&
                ((f->Flags & RTF_READ_ONLY) == 0))
            {
               if (f->Flags & RTF_LAZY_DATA)
                  FlushAllBuffers(f->Dev);
               else
               {
                  CommitDirEntry(f);
                  FlushFAT(f->Dev);

                  /* commit the last write sector (all buffers of this file should be flushed! */
                  if (SearchBuffer(f->Dev, CLUSTER_TO_SECTOR_DIR_OFS(f->Drive, f->Cluster, f->Offset)))
                  {
                     /* commit device's INUSE buffer (set in SearchBuffer) */
                     CommitBuffer(f->Dev);
                     if ((f->Flags & RTF_CACHE_DATA) == 0)
                        DiscardBuffer(f->Dev);
                  }
               }
            }

         // recoverable support
         if ((f->Flags & FS_PROTECTION_MODE) && f->Dev->Driver->ResumeSectorStates)
         {
            int result = f->Dev->Driver->ResumeSectorStates(f->Dev->DriverData);

            if (result < RTF_NO_ERROR)
            {
               fs_util_trace_err_noinfo(result);

               XRAISE(result);
            }
         }

         // if this is the last device or drive file with write access
         // unmount the device or drive
         if ((f->Flags & RTF_READ_ONLY) == 0)
            switch (f->SpecialKind)
            {
               case Volume:
                  if (FileCountDrive(f->Drive) <= 1)
                     f->Drive->MountState = NotMounted;
                  break;
               #if !defined(__FS_SLIM_PHYSICAL_DRIVE__)
               case PhysicalDisk:
                  if (FileCount(f->Dev) <= 1)
                     UnmountDevice(f->Dev, 0);
                  break;
               #endif   // !__FS_SLIM_PHYSICAL_DRIVE__
            }
         break;
      default:
      	 result = XVALUE;
         break;
      case XFINALLY:
      	 /*--------------------------------------------------------
      	  * If f is NULL due to device is busy, try to get f by other
      	  * methods, otherwise file may not be correctly closed.
      	  * Note: In this case, device was NOT locked!
      	  *---------------------------------------------- W09.19 --*/
      	 if (f == NULL && result == MT_DEVICE_BUSY)
      	 {
            /*-----------------------------------------------------
             * If result is MT_DEVICE_BUSY, f should be valid because
             * PraseFileHandle has checked its validity, so just free
             * it directly.
             *------------------------------------------- W09.19 --*/
            if (freeSlot)
            {
               fh = fh & ((1 << (4 * sizeof(int))) - 1);  // get file table index

               if (fh >= 0 && fh < FS_MAX_FILES)  // double check index range to avoid memory corruption
               {
                  f = gFS_Data.FileTable + fh;
                  FreeFTSlot(f);
               }
            }
      	 }
      	 else if (f)
         {
            if (freeSlot)
               FreeFTSlotAndDevice(f);
            else
            {
               if (f->Dev)
                  UnlockDevice(f->Dev);
            }
         }
         break;
   XEND_API

   return RTF_NO_ERROR;
}

/*-----------------------------------*/
int RTFAPI RTFGetFilePosition(FS_HANDLE fh, kal_uint32 *position)
{
    RTFile * volatile f = NULL;

    XTRY
        case XCODE:

            f = ParseFileHandle(fh);

            *position = f->FilePointer;

            if (f->SpecialKind == FileMapFile)
            {
                *position -= f->DirEntry.ShortPos.Index; /* BIAS */
            }

            break;
        default:
            break;
        case XFINALLY:
            if (f)
            {
                UnlockDevice(f->Dev);
            }
        break;
    XEND_API

    return RTF_NO_ERROR;
}

/*-----------------------------------*/
int RTFAPI RTFGetFileSize(RTFHANDLE File, kal_uint32 * Size)
{
   RTFile * volatile f = NULL;

   XTRY
      case XCODE:
         f = ParseFileHandle(File);
         switch (f->SpecialKind)
         {
            case NormalFile:
               *Size = f->DirEntry.Dir.FileSize;
               break;
            case FileMapFile:
               *Size = f->DirEntry.Dir.FileSize - f->DirEntry.ShortPos.Index; /* BIAS */
               break;
            case Volume:
               *Size = f->Drive->Geometry.Sectors << f->Dev->DevData.SectorShift;
               break;
            #if !defined(__FS_SLIM_PHYSICAL_DRIVE__)
            case PhysicalDisk:
               *Size = f->Dev->DevData.Geometry.Sectors << f->Dev->DevData.SectorShift;
               break;
            #endif  // !__FS_SLIM_PHYSICAL_DRIVE__
            default:

               fs_util_trace_err_noinfo(RTF_INVALID_FILE_HANDLE);

               XRAISE(RTF_INVALID_FILE_HANDLE);
               break;
         }
         break;
      default:
         break;
      case XFINALLY:
         if (f) UnlockDevice(f->Dev);
         break;
   XEND_API
   return RTF_NO_ERROR;
}

/*-----------------------------------*/
int RTFAPI RTFSetFileTime(RTFHANDLE File, const RTFDOSDateTime * Time)
{
   RTFile * volatile f = NULL;
   RTFDOSDirEntry * D;

   XTRY
      case XCODE:
         f = ParseFileHandle(File);

         if(f->Dev->DeviceFlags & MT_DEVICE_WRITE_PROTECT)
         {
            fs_util_trace_err_noinfo(RTF_WRITE_PROTECTION);

            XRAISE(RTF_WRITE_PROTECTION);
         }

         if (f->SpecialKind != NormalFile)
         {
            fs_util_trace_err_noinfo(RTF_PARAM_ERROR);

            XRAISE(RTF_PARAM_ERROR);
         }
         f->DirEntry.Dir.DateTime = *Time;
         D = GetDir(f->Drive, &f->DirEntry.ShortPos);
         *D = f->DirEntry.Dir;
         SetDirty(f->Dev);
         if (f->Flags & RTF_COMMITTED)
            CommitBuffer(f->Dev);
         break;
      default:
         break;
      case XFINALLY:
         if (f) UnlockDevice(f->Dev);
         break;
   XEND_API
   return RTF_NO_ERROR;
}

/*-----------------------------------*/
int RTFAPI RTFSetFileCreatedTime(RTFHANDLE File, const RTFDOSDateTime * Time)
{
   RTFile * volatile f = NULL;
   RTFDOSDirEntry * D;

   XTRY
      case XCODE:
         f = ParseFileHandle(File);

         if(f->Dev->DeviceFlags & MT_DEVICE_WRITE_PROTECT)
         {
            fs_util_trace_err_noinfo(RTF_WRITE_PROTECTION);

            XRAISE(RTF_WRITE_PROTECTION);
         }

         if (f->SpecialKind != NormalFile)
         {
            fs_util_trace_err_noinfo(RTF_PARAM_ERROR);

            XRAISE(RTF_PARAM_ERROR);
         }
         f->DirEntry.Dir.CreateDateTime = *Time;
         D = GetDir(f->Drive, &f->DirEntry.ShortPos);
         *D = f->DirEntry.Dir;
         SetDirty(f->Dev);
         if (f->Flags & RTF_COMMITTED)
            CommitBuffer(f->Dev);
         break;
      default:
         break;
      case XFINALLY:
         if (f) UnlockDevice(f->Dev);
         break;
   XEND_API
   return RTF_NO_ERROR;
}

/*-----------------------------------*/

int RTFAPI MTCheckMSCard(RTFHANDLE File, RTFBootRecord *BR)
{
   RTFile * volatile f = NULL;
   int Mega, i;
   int volatile bCorrect = 0, Result = RTF_NO_ERROR;

   XTRY
      case XCODE:
         f = ParseFileHandleEx(File, FS_NONBLOCK_MODE);
         if ((f->Dev->DeviceFlags & MT_DEVICE_MEMORY_STICK) == MT_DEVICE_MEMORY_STICK)
         {
            Mega = BR->BP.TotalSectors / 2048;
            if (Mega > 64)
            {
               i = 16; // 128M
            }
            else if (Mega > 32)
            {
               i = 8;   // 64M
            }
            else if (Mega > 16)
            {
               i = 4;   // 32M
            }
            else if (Mega > 8)
            {
               i = 4;   // 16M
            }
            else   // 8M & 4M
            {
               i = 2;
            }

            if (BR->BP.NumberOfHeads != i)
            {
               BR->BP.NumberOfHeads = (WORD)(i & 0xFFFF);
               if(i<= 4)
                  BR->BP.TotalSectors = 0;
               bCorrect = 1;
            }
         }
         break;
      default:
         break;
      case XFINALLY:
         if (f) UnlockDevice(f->Dev);

         if (bCorrect)
         {
            Result = RTFSeek(File, 0, RTF_FILE_BEGIN);
            if (Result >= RTF_NO_ERROR)
            {
               kal_mem_set( (void *)BR->BP.E._16.BPB.Label, 0, 11);
               Result = RTFWrite(File, (void*)BR, sizeof(RTFBootRecord), NULL);
            }
         }
         break;
   XEND_API
   return Result;
}

/*-----------------------------------*/
int RTFAPI RTFGetFileInfo(RTFHANDLE File, RTFFileInfo * FileInfo, UINT Flags)
{
   RTFile * volatile f = NULL;
   RTFCluster Cluster, LastCluster;

   XTRY
      case XCODE:
         f = ParseFileHandle(File);

         FileInfo->FilePos             = f->FilePointer;
         FileInfo->FullName            = f->FullName;
         FileInfo->ClusterChains       = 0;
         FileInfo->VolumeSerialNumber  = f->Drive ? f->Drive->SerialNumber : 0;
         FileInfo->AllocatedSize       = 0;
         FileInfo->ClusterChains       = 0;

         switch (f->SpecialKind)
         {
            #if !defined(__FS_SLIM_PHYSICAL_DRIVE__)
            case PhysicalDisk:
               FileInfo->VolumeSerialNumber = 0;
               FileInfo->DirEntry = NULL;

               if (Flags & RTF_FI_ALLOCATED_SIZE)
                  FileInfo->AllocatedSize = f->Dev->DevData.Geometry.Sectors << f->Dev->DevData.SectorShift;

               break;
            #endif  // !__FS_SLIM_PHYSICAL_DRIVE__
            case Volume:
               FileInfo->VolumeSerialNumber = f->Drive->SerialNumber;
               FileInfo->DirEntry = NULL;

               if (Flags & RTF_FI_ALLOCATED_SIZE)
                  FileInfo->AllocatedSize = f->Drive->Geometry.Sectors << f->Dev->DevData.SectorShift;

               break;
            case NormalFile:
               FileInfo->VolumeSerialNumber = f->Drive->SerialNumber;
               FileInfo->DirEntry = &f->DirEntry.Dir;

               if (Flags & RTF_FI_ALLOCATED_SIZE)
               {
                  Cluster = FIRST_FILE_CLUSTER(f->DirEntry.Dir);

                  if (Cluster == RTF_ROOT_DIR) // special cluster for root dir
                     FileInfo->AllocatedSize = f->DirEntry.Dir.FileSize;
                  else
                  {
                     FileInfo->AllocatedSize = 0;
                     LastCluster = 0;

                     while ((Cluster != 0) && (Cluster < RTF_CLUSTER_CHAIN_END))
                     {
                        FileInfo->AllocatedSize += f->Drive->ClusterSize;
                        if (Cluster != (LastCluster+1))
                           FileInfo->ClusterChains++;
                        LastCluster = Cluster;
                        Cluster = GetClusterValue(f->Drive, LastCluster);
                     }
                  }
               }

               break;
            case FileMapFile:
               FileInfo->FilePos -= f->DirEntry.ShortPos.Index; // BIAS
               FileInfo->DirEntry = NULL;

               break;
         }
         break;
      default:
         break;
      case XFINALLY:
         if (f) UnlockDevice(f->Dev);
         break;
   XEND_API
   return RTF_NO_ERROR;
}

/*-----------------------------------*/
int RTFAPI RTFMakeFileName(const RTFDOSDirEntry * FileInfo, WCHAR * FileName)
{
   return MakeShortFileName(FileInfo, (char *)FileName, 13);
}

/*-----------------------------------*/
int RTFAPI RTFRead(RTFHANDLE File, void * DataPtr, UINT Length, UINT * Read)
{
   register RTFile * f;
   RTFile * volatile f1 = NULL; // just for cleanup
   UINT l1, l2, l3;
   kal_uint32 volatile InitialFilePointer;
   int volatile Result = RTF_NO_ERROR;
   UINT DummyRead;

   if (Read == NULL)
      Read = &DummyRead;
   *Read = 0;

   XTRY
      case XCODE:
         /* get device and system lock (check file's flag to decide use blocking or non-blocking mode) */
         f1 = f = ParseFileHandleEx(File, FS_NONBLOCK_MODE);

         // SWLA hooker
         fs_util_swla_hook((FS_Device *)f1->Dev, FS_API_READ, SA_start);

         InitialFilePointer = f->FilePointer;

         /* Add to abort in the middle of action, Karen Hsu, 2004/05/03, ADD START */
         if(f->Valid == FS_FH_ABORTED)
         {
            fs_util_trace_err_noinfo(MT_ABORTED_ERROR);

            XRAISE(MT_ABORTED_ERROR);
         }
         /* Add to abort in the middle of action, Karen Hsu, 2004/05/03, ADD END */

         if ((f->SpecialKind == NormalFile) && (f->FilePointer > f->DirEntry.Dir.FileSize))
         {
            fs_util_trace_err_noinfo(RTF_INVALID_FILE_POS);
            fs_util_trace_info2(NULL, FS_ERR_RTFREAD_FPTR_OUT_OF_RANGE, f->FilePointer, f->DirEntry.Dir.FileSize, NULL);

            XRAISE(RTF_INVALID_FILE_POS);
         }

         if ((f->FilePointer + Length) < f->FilePointer)
         {
            fs_util_trace_err_noinfo(RTF_FILE_TOO_LARGE);
            fs_util_trace_info2(NULL, FS_ERR_RTFREAD_FPTR_WRAP_AROUND, f->FilePointer, Length, NULL);

            XRAISE(RTF_FILE_TOO_LARGE);
         }

         if(f->Flags & FS_NONBLOCK_MODE)
            RTFSYSSetTLS(TLSBlockIndex,(_XData*)FS_NON_BLOCK_ENUM);

         if (f->SpecialKind == Volume || f->SpecialKind == PhysicalDisk )
         {
            RTFSector C = Length >> f->Dev->DevData.SectorShift;
            RTFSector S = ((f->SpecialKind == Volume) ? f->Drive->FirstSector : 0)
                        + (f->FilePointer >> f->Dev->DevData.SectorShift);

            if ((Length & (f->Dev->DevData.SectorSize-1)) != 0)
            {
               fs_util_trace_err_noinfo(RTF_PARAM_ERROR);
               fs_util_trace_info1(NULL, FS_ERR_RTFREAD_MUST_READ_SECTOR_ALIGNED, Length, NULL);

               XRAISE(RTF_PARAM_ERROR);
            }

            /* discare buffer range WITH commit */
            DiscardBuffersRange(f->Dev, S, C, 1);
            rtf_core_read_sectors(f->Dev, DataPtr, S, C, 0);
#ifdef __FS_DEBUG__
            BufferStat.UnbufferedReads += C;
#endif

            f->FilePointer += Length;
            *Read          += Length;
            break;
         }
         else if(f->SpecialKind == FileMapFile)
         {
            Result = MTChkMapedFH( f->DirEntry.LongPos.Index ); /* LINK */
            if( Result != RTF_NO_ERROR )
            {
               fs_util_trace_err_noinfo(MT_VF_MAP_ERROR);
               fs_util_trace_info1(NULL, FS_ERR_RTFREAD_INVALID_FMAPED_HANDLE, f->DirEntry.LongPos.Index, NULL);

               XRAISE(MT_VF_MAP_ERROR);
            }
         }

         #ifdef __FS_TRACE_SUPPORT_OPEN_HINT__
         {
            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
         }
         #endif

         Length = fs_min(Length, f->DirEntry.Dir.FileSize - f->FilePointer);

         // make 3 partitions:
         // 1. bytes up to next sector boundary
         // 2. complete sectors
         // 3. to end of area
         // if start and end of area are within the same sector,
         // l3 is used.

         if ((f->FilePointer >> f->Dev->DevData.SectorShift) == ((f->FilePointer+Length) >> f->Dev->DevData.SectorShift))
         {
            l1 = 0;
            l2 = 0;
            l3 = Length;
         }
         else
         {
            l3 = (f->FilePointer+Length) - RTFRoundDown((f->FilePointer+Length), f->Dev->DevData.SectorSize);
            l1 = RTFRoundUp(f->FilePointer, f->Dev->DevData.SectorSize) - f->FilePointer;
            l2 = Length - l1 - l3;
         }

         if (l1 > 0)
         {
            BYTE * Data = GetBuffer(f->Dev, CLUSTER_TO_SECTOR_DIR_OFS(f->Drive, f->Cluster, f->Offset), 0);

            memcpy(DataPtr, Data + SECTOR_OFS(f->Drive, f->Offset), l1);

            // this could be a file with read/write access
            // thus we must always check if we leave a dirty buffer behind
            if ((f->Flags & RTF_LAZY_DATA) == 0)
               CommitBuffer(f->Dev);
            if ((f->Flags & RTF_CACHE_DATA) == 0)
               DiscardBuffer(f->Dev);

            *Read           += l1;
            DataPtr = (BYTE*) DataPtr + l1;
            MoveFilePointer(f, l1);
         }
         while (l2 > 0)
         {
            UINT       n;      // bytes in this segment
            RTFSector  C;      // number of sectors in segment;
            RTFSector  S;      // sector to start writing at

            // abort check
            if (fs_fh_is_aborted((FS_File*)f) == KAL_TRUE)  // [async]
            {
                fs_util_trace_err_noinfo(FS_ABORTED_ERROR);

                XRAISE(FS_ABORTED_ERROR);
            }

            S = CLUSTER_TO_SECTOR_DIR_OFS(f->Drive, f->Cluster, f->Offset);
            n = MoveFilePointerSegment(f, l2);
            C = n >> f->Dev->DevData.SectorShift;

            // can read C sectors starting at S, but have to check
            // for any data in buffers

            DiscardBuffersRange(f->Dev, S, C, 1);  // discard with commit
            rtf_core_read_sectors(f->Dev, DataPtr, S, C, 0);
#ifdef __FS_DEBUG__
            BufferStat.UnbufferedReads += C;
#endif
            *Read           += n;
            DataPtr = (BYTE*)DataPtr + n;
            l2 -= n;
         }
         if (l3 > 0)
         {
            BYTE * Data = GetBuffer(f->Dev, CLUSTER_TO_SECTOR_DIR_OFS(f->Drive, f->Cluster, f->Offset), 0);
            memcpy(DataPtr, Data + SECTOR_OFS(f->Drive, f->Offset), l3);
            MoveFilePointer(f, l3);
            *Read += l3;
         }
         break;
      default:
         Result = XVALUE;

         if (((Result != RTF_FILE_TOO_LARGE) &&
             f1 && ((InitialFilePointer + *Read) != f1->FilePointer))
             || Result == MT_FLASH_ERASE_BUSY)
         XTRY
            case XCODE:
               InitFilePointer(f1);
               MoveFilePointer(f1, InitialFilePointer + *Read);
               break;
            default:
               if (Result == RTF_NO_ERROR)
                   Result = XVALUE;
               XHANDLED;
               break;
            case XFINALLY:
               break;
         XENDX
         break;
      case XFINALLY:

         #ifdef __FS_TRACE_SUPPORT_OPEN_HINT__
         if (f1 && ((InitialFilePointer + *Read) != f1->FilePointer))
             fs_err_internal_fatal(FS_ERR_HANDLE_03, NULL);

         #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
         #endif
         #endif


         // reset to block mode
         if(f1) /* Fix f1 is null case, Karen Hsu, 2004/03/01 */
         {
            if(f1->Flags & FS_NONBLOCK_MODE)
               RTFSYSSetTLS(TLSBlockIndex,(_XData*)FS_BLOCK_ENUM);

            // SWLA hooker
            fs_util_swla_hook((FS_Device *)f1->Dev, FS_API_READ, SA_stop);

            UnlockDevice(f1->Dev);
         }
         break;
   XEND_API

   return Result;
}

/*-----------------------------------*/
void RTFAPI ExtendFile(RTFile * f, kal_uint32 Bytes, kal_uint32 Options)
// extend at most by Bytes bytes, but possibly less
// the extend is one segment
{
   RTFCluster NeedClusters = ((Bytes - 1) >> (f->Drive->ClusterShift)) + 1;

#ifdef DEBUG
   if (f->Cluster != 0)
       fs_err_internal_fatal(FS_ERR_CLUSTER_04, NULL);
#endif

   f->Cluster = f->LastCluster+1; // will be fixed by AllocateFATSegment if invalid
   AllocateFATSegment(f->Drive, &f->Cluster, NeedClusters, f);

   if (f->LastCluster)
   {
      SetClusterValue(f->Drive, f->LastCluster, f->Cluster); // connect the two chains
   }
   else // means there is no cluster chains for this file originally.
   {
      if (Options & FS_COMMITTED)
      {
         FlushFAT(f->Dev);
      }

      SET_FIRST_FILE_CLUSTER(f->DirEntry.Dir, f->Cluster);   // this is the first chain

      UpdateDirEntry(f);

      if (Options & FS_COMMITTED)
      {
         FlushAllBuffersInGeometryOrder(f->Dev);
      }
   }
}

/*-----------------------------------*/
int RTFAPI RTFWrite(RTFHANDLE File, void * DataPtr, UINT Length, UINT * Written)
{
   register RTFile * f;
   RTFile * volatile f1 = NULL;
   kal_uint32        extend_file_options = 0;
   UINT l1, l2, l3;
   kal_uint32 volatile InitialFilePointer;
   int volatile Result = RTF_NO_ERROR;
   UINT DummyWritten;
   int fs_block_type = FS_BLOCK_ENUM; /* Fix multi-access bug, Karen Hsu, 2004/07/08, ADD */

   if (Written == NULL)
      Written = &DummyWritten;
  *Written = 0;

   XTRY
      case XCODE:
         f1 = f = ParseFileHandleEx(File, FS_NONBLOCK_MODE);

         // SWLA hooker
         fs_util_swla_hook((FS_Device *)f1->Dev, FS_API_WRITE, SA_start);

         InitialFilePointer = f->FilePointer;

         if(f->Valid == FS_FH_ABORTED)
         {
            fs_util_trace_err_noinfo(MT_ABORTED_ERROR);

            XRAISE(MT_ABORTED_ERROR);
         }

         /* check RTF_READ_ONLY */
         if (f->Flags & RTF_READ_ONLY)
         {
            fs_util_trace_err_noinfo(MT_READ_ONLY_ERROR);

            XRAISE(MT_READ_ONLY_ERROR);
         }

         /* invalid file pointer, greater than file size */
         if ((f->SpecialKind == NormalFile) && (f->FilePointer > f->DirEntry.Dir.FileSize))
         {
            fs_util_trace_err_noinfo(RTF_INVALID_FILE_POS);
            fs_util_trace_info2(NULL, FS_ERR_RTFWRITE_FPTR_OUT_OF_RANGE, f->FilePointer, f->DirEntry.Dir.FileSize, NULL);

            XRAISE(RTF_INVALID_FILE_POS);
         }

         /* file pointer will wrap around, file is too large */
         if ((f->FilePointer + Length) < f->FilePointer)
         {
            fs_util_trace_err_noinfo(RTF_INVALID_FILE_POS);
            fs_util_trace_info2(NULL, FS_ERR_RTFWRITE_FPTR_WRAP_AROUND, f->FilePointer, Length, NULL);

            XRAISE(RTF_FILE_TOO_LARGE);
         }

         /* Save speical flag to TLS.
            Note. FS_NONBLOCK_MODE will overwrite FS_BLOCK_PROTECTION_ENUM, we don't support
            "non-blocking recoverable write" */

         if(f->Flags & FS_NONBLOCK_MODE)
            RTFSYSSetTLS(TLSBlockIndex,(_XData*)FS_NON_BLOCK_ENUM);
         else if (f->Flags & FS_PROTECTION_MODE)
            RTFSYSSetTLS(TLSBlockIndex,(_XData*)FS_BLOCK_PROTECTION_ENUM);

         if (f->SpecialKind != NormalFile)
         {
            /* C: number of sectors to write */
            RTFSector C = Length >> f->Dev->DevData.SectorShift;

            /* S: start sector */
            RTFSector S = ((f->SpecialKind == Volume) ? f->Drive->FirstSector : 0)
                        + (f->FilePointer >> f->Dev->DevData.SectorShift);

            /* invalid Length: not multiple of SectorSize */
            if ((Length & (f->Dev->DevData.SectorSize-1)) != 0)
            {
               fs_util_trace_err_noinfo(RTF_PARAM_ERROR);
               fs_util_trace_info1(NULL, FS_ERR_RTFWRITE_MUST_READ_SECTOR_ALIGNED, Length, NULL);

               XRAISE(RTF_PARAM_ERROR);
            }

            DiscardBuffersRange(f->Dev, S, C, 0);   // discard without commit
            rtf_core_write_sectors(f->Dev, DataPtr, S, C, 0, RTF_NORMAL_WRITE);
#ifdef __FS_DEBUG__
            BufferStat.UnbufferedWrites += C;
#endif
            f->FilePointer += Length;
            *Written       += Length;

            /* leave XTRY */
            break;
         }

         // this file handle points to a NORMAL file

         // ROBUSTNESS: FAT table will be first flushed to disk for file
         //             without any cluster chain allocated before to avoid
         //             dangling FirstCluster in dir entry.         (W11.28)

         if (FIRST_FILE_CLUSTER(f->DirEntry.Dir) == 0)
         {
            extend_file_options = FS_COMMITTED;
         }

         // make 3 partitions:
         // 1. bytes up to next sector boundary
         // 2. complete sectors
         // 3. to end of area
         // if start and end of area are within the same sector,
         // l3 is used.

         if ((f->Cluster == RTF_ROOT_DIR) && ((f->FilePointer + Length) > f->DirEntry.Dir.FileSize))
         {
            fs_util_trace_err_noinfo(RTF_ROOT_DIR_FULL);

            XRAISE(RTF_ROOT_DIR_FULL);
         }

         #ifdef __FS_TRACE_SUPPORT_OPEN_HINT__
         #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
         #endif
         #endif

         if ((f->FilePointer >> f->Dev->DevData.SectorShift) == ((f->FilePointer+Length) >> f->Dev->DevData.SectorShift))
         {
            l1 = 0;
            l2 = 0;
            l3 = Length;
         }
         else
         {
            l3 = (f->FilePointer+Length) - RTFRoundDown((f->FilePointer+Length), f->Dev->DevData.SectorSize);
            l1 = RTFRoundUp(f->FilePointer, f->Dev->DevData.SectorSize) - f->FilePointer;
            l2 = Length - l1 - l3;
         }

         /* get speical flag from TLS (nonblocking mode or recoverable write) */
         fs_block_type = (int)RTFSYSGetTLS(TLSBlockIndex); /* Remove RVCT warning, Karen Hsu, 2004/11/02, MOD*/

         if (l1 > 0)
         {
            BYTE * Data = GetBuffer(f->Dev, CLUSTER_TO_SECTOR_DIR_OFS(f->Drive, f->Cluster, f->Offset), 0);

            memcpy(Data + SECTOR_OFS(f->Drive, f->Offset), DataPtr, l1);

            SetDirty(f->Dev);
            SetRecoverableFlag(f->Dev, fs_block_type);

            /* if RTF_LAZY_DATA, RTF_CACHE_DATA must be set to keep data in buffer (done in RTFOpenFile) */
            if ((f->Flags & RTF_LAZY_DATA) == 0)
               CommitBuffer(f->Dev);

            if ((f->Flags & RTF_CACHE_DATA) == 0)
               DiscardBuffer(f->Dev); // discard committed buffer

            *Written        += l1;
            DataPtr = (BYTE*) DataPtr + l1;
            MoveFilePointer(f, l1);
         }
         while (l2 > 0)
         {
            UINT       n;      // number of bytes in segment
            RTFSector  S;      // sector to start writing at
            RTFSector  C;      // number of sectors in segment;

            // abort check
            if (fs_fh_is_aborted((FS_File*)f) == KAL_TRUE)  // [async]
            {
                fs_util_trace_err_noinfo(FS_ABORTED_ERROR);

                XRAISE(FS_ABORTED_ERROR);
            }

            if (f->Cluster == 0) // end of file, allocate more
            {
               ExtendFile(f, l2 + l3, extend_file_options);

               extend_file_options = 0; // reset extend_file_options to avoid repeatedly committing FAT tables in ExtendFile()
            }

            S = CLUSTER_TO_SECTOR_DIR_OFS(f->Drive, f->Cluster, f->Offset);
            n = MoveFilePointerSegment(f, l2);
            C = n >> f->Dev->DevData.SectorShift;

            // can write C sectors starting at S, but have to check
            // for any data in buffers

            DiscardBuffersRange(f->Dev, S, C, 0);   // discard without commit

            /* l2 writes will not involve cache */
            if (fs_block_type == FS_BLOCK_PROTECTION_ENUM)
               rtf_core_write_sectors(f->Dev, DataPtr, S, C, 0, RTF_RECOVERABLE_WRITE);
            else
               rtf_core_write_sectors(f->Dev, DataPtr, S, C, 0, RTF_NORMAL_WRITE);
#ifdef __FS_DEBUG__
            BufferStat.UnbufferedWrites += C;
#endif
            *Written        += n;
            DataPtr = (BYTE*) DataPtr + n;
            l2 -= n;
         }
         if (l3 > 0)
         {
            RTFSector S;
            UINT Offset = SECTOR_OFS(f->Drive, f->Offset);
            UINT NeedOldSector = (f->DirEntry.Dir.FileSize > f->FilePointer) || Offset;
            BYTE * Data;

            if (f->Cluster == 0)
            {
               ExtendFile(f, l3, extend_file_options);

               extend_file_options = 0; // reset extend_file_options to avoid repeatedly committing FAT tables in ExtendFile()
            }

            S = CLUSTER_TO_SECTOR_DIR_OFS(f->Drive, f->Cluster, f->Offset);
            MoveFilePointer(f, l3);

            Data = GetBuffer(f->Dev, S, NeedOldSector ? 0 : NO_LOAD);
            memcpy(Data + Offset, DataPtr, l3);
            SetDirty(f->Dev);
            SetRecoverableFlag(f->Dev, fs_block_type);

            *Written += l3;

            if (f->Flags & RTF_COMMITTED)
               CommitBuffer(f->Dev);
         }
         break;
      default:
         Result = XVALUE;
         if (((Result != RTF_FILE_TOO_LARGE) &&
             f1 && ((InitialFilePointer + *Written) != f1->FilePointer))
             || (Result == MT_FLASH_ERASE_BUSY))
         XTRY
            case XCODE:
               InitFilePointer(f1);
               MoveFilePointer(f1, InitialFilePointer + *Written);
               break;
            default:
               XHANDLED;   // ignore further exceptions
               break;
            case XFINALLY:
               break;
         XENDX
         break;
      case XFINALLY:
         if (f1)
         {
            #ifdef __FS_TRACE_SUPPORT_OPEN_HINT__
            if (((InitialFilePointer + *Written) != f1->FilePointer))
                fs_err_internal_fatal(FS_ERR_HANDLE_04, NULL);
            #endif

            if (((f1->DirEntry.Dir.Attributes & RTF_ATTR_DIR) == 0)) // do not update dirs
            {
               if (f1->FilePointer > f1->DirEntry.Dir.FileSize)
               {
                  f1->DirEntry.Dir.FileSize = f1->FilePointer;

                  #ifdef __FS_SMART_FILE_SEEKER__
                  if (f1 && f1->usr_ptr_type == FS_TBL_USR_PTR_MILESTONE && f1->usr_ptr)
                  {
                     MTSH_ReCalHintData(f1);
                  }
                  #endif
               }

               f1->DirEntry.Dir.Attributes |= RTF_ATTR_ARCHIVE;

               #ifdef __FS_TRACE_SUPPORT_OPEN_HINT__
               #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
               #endif
               #endif
            }

            XTRY
               case XCODE:
               	  // update write time
                  RTFSYSGetDateTime(&f1->DirEntry.Dir.DateTime);
                  UpdateDirEntry(f1);

                  // FAT flush is here (update only once after whole RTFWrite is done)
                  if (f1->Flags & RTF_COMMITTED)
                  {
                     FlushFAT(f1->Dev);
                  }

                  break;
               default:
                  if (Result == RTF_NO_ERROR)
                      Result = XVALUE;
                  XHANDLED;
                  break;
               case XFINALLY:
                  // because TLS is task's view, we have to reset TLS to default: blocking mode.
                  if((f1->Flags & FS_NONBLOCK_MODE) || (f1->Flags & FS_PROTECTION_MODE))
                     RTFSYSSetTLS(TLSBlockIndex,(_XData*)FS_BLOCK_ENUM);
                  break;
            XENDX

            // SWLA hooker
            fs_util_swla_hook((FS_Device *)f1->Dev, FS_API_WRITE, SA_stop);

            UnlockDevice(f1->Dev);
         }
         break;
   XEND_API

   return Result;
}

/*-----------------------------------*/
int RTFAPI RTFCommit(RTFHANDLE File, kal_uint32 Flag)
{
   RTFile * volatile f = NULL;

   XTRY
      case XCODE:
         f = ParseFileHandle(File);

         FlushAllBuffersInGeometryOrder(f->Dev);

         // recoverable support
         if ((f->Flags & FS_PROTECTION_MODE) && f->Dev->Driver->ResumeSectorStates && (Flag & FS_COMMIT_RESUMESECTOR))
         {
            int result = f->Dev->Driver->ResumeSectorStates(f->Dev->DriverData);

            if (result < RTF_NO_ERROR)
            {
               fs_util_trace_err_noinfo(result);

               XRAISE(result);
            }
         }
         break;
      default:
         break;
      case XFINALLY:
         if (f) UnlockDevice(f->Dev);
         break;
   XEND_API
   return RTF_NO_ERROR;
}

/*-----------------------------------*/
int RTFAPI RTFTruncate(RTFHANDLE File)
{
   RTFile * volatile f  = NULL;
   RTFile *          f1 = gFS_Data.FileTable;
   RTFCluster StartCluster;
   int        i;

   XTRY
      case XCODE:
         f = ParseFileHandle(File);
         if (f->SpecialKind != NormalFile)
         {
            fs_util_trace_err_noinfo(RTF_PARAM_ERROR);
            fs_util_trace_info0(TRACE_ERROR, FS_ERR_RTFTRUNCATE_NORMAL_FILE_ONLY, NULL);

            XRAISE(RTF_PARAM_ERROR);
         }

         if (f->Flags & RTF_READ_ONLY)
         {
            fs_util_trace_err_noinfo(MT_READ_ONLY_ERROR);

            XRAISE(MT_READ_ONLY_ERROR);
         }

         if (FIRST_FILE_CLUSTER(f->DirEntry.Dir) == RTF_ROOT_DIR) // can't truncate a root dir
         {
            fs_util_trace_err_noinfo(RTF_ACCESS_DENIED);

            XRAISE(RTF_ACCESS_DENIED);
         }

         if ((f->DirEntry.Dir.Attributes & RTF_ATTR_DIR) && (f->FilePointer == 0))
         {
            fs_util_trace_err_noinfo(RTF_ACCESS_DENIED);

            XRAISE(RTF_ACCESS_DENIED);
         }

         if (f->FilePointer > f->DirEntry.Dir.FileSize)
         {
            fs_util_trace_err_noinfo(RTF_INVALID_FILE_POS);
            fs_util_trace_info2(TRACE_ERROR, FS_ERR_RTFTRUNCATE_FPTR_OUT_OF_RANGE, f->FilePointer, f->DirEntry.Dir.FileSize, NULL);

            XRAISE(RTF_INVALID_FILE_POS);
         }

         f->DirEntry.Dir.FileSize = f->FilePointer;

         // check if anyone's FilePointer > updated FileSize, if yes, return FS_ACCESS_DENIED. Otherwise, fatal will happen in UpdateDirEntry()
         for (i = 0; i < FS_MAX_FILES; i++, f1++)
         {
             if ((f1 != f) && (f1->Dev == f->Dev) && (f1->Drive == f->Drive) && SAME_DIR_ENTRY(f1->DirEntry.ShortPos, f->DirEntry.ShortPos))
             {
                 if (f1->Task != f->Task)    // for running file handle, its Task is not set, i.e. 0, therefore all opened file will be checked.
                 {
                     if(f->DirEntry.Dir.FileSize < f1->FilePointer)
                     {
                         XRAISE(FS_ACCESS_DENIED);
                     }
                 }
             }
         }

         UpdateDirEntry(f);

         // if the file pointer is on a cluster boundary, delete its cluster
         // and all following clusters
         // else delete only following clusters

         if (f->Offset == 0)                  // file pointer is on a cluster boundary
            StartCluster = f->Cluster;
         else
            StartCluster = GetClusterValue(f->Drive, f->Cluster);

         if (StartCluster != 0)
         //quota
         {
            FATDelete(f->Drive, StartCluster, f);
            //FATDelete(f->Drive, StartCluster);
         }

         if (f->DirEntry.Dir.FileSize == 0) // no cluster chain at all (Dirs will never haev this value)
         {
            SET_FIRST_FILE_CLUSTER(f->DirEntry.Dir, 0);
            UpdateDirEntry(f);
            f->Cluster = 0;
         }
         else
            // terminate the now open cluster chain
            if (StartCluster == f->Cluster)
            {
               f->Cluster = 0;
               #ifdef DEBUG
               if ((f->LastCluster < 2) || (f->LastCluster > f->Drive->Clusters))
                  fs_err_internal_fatal(FS_ERR_CLUSTER_07, NULL);
               #endif
               SetClusterValue(f->Drive, f->LastCluster, RTF_CHAIN_END_MARK);
               f->Cluster = 0;
            }
            else
               SetClusterValue(f->Drive, f->Cluster, RTF_CHAIN_END_MARK); // no following clusters

         if (f->Flags & RTF_COMMITTED)
            FlushFAT(f->Dev);
         break;
      default:
         break;
      case XFINALLY:

         #ifdef __FS_SMART_FILE_SEEKER__
         if (f && f->usr_ptr_type == FS_TBL_USR_PTR_MILESTONE && f->usr_ptr)
         {
            MTSH_DelHintByOffset(f);
         }
         #endif

         if (f) UnlockDevice(f->Dev);
         break;
   XEND_API
   return RTF_NO_ERROR;
}

#ifdef __FS_SMART_FILE_SEEKER__
void MTSH_ReCalHintData(RTFile *f) // called by APIs that will enlarge file size
{
   FS_SeekHintData *SeekHintData = NULL;
   UINT pre_range = 0;
   int  i;

   fs_assert_local(f && f->usr_ptr_type == FS_TBL_USR_PTR_MILESTONE);
   SeekHintData = (FS_SeekHintData *)f->usr_ptr;
   pre_range = SeekHintData->StaticHintRange;

   SeekHintData->StaticHintRange = f->DirEntry.Dir.FileSize / (SeekHintData->StaticHintCount + 1);

   if (SeekHintData->StaticHintRange < f->Drive->ClusterSize)
       SeekHintData->StaticHintRange = f->Drive->ClusterSize;

   if (pre_range != SeekHintData->StaticHintRange)
   {
      // resolve all hints, set them all as CLASSIC!
      for (i = 0; i < f->HintNum; i++)
      {
         FS_SEEKHINT_SET_CLASSIC(f, i);
      }

      SeekHintData->UsedStaticHintCount = 0;
   }
}

void MTSH_DelHintByOffset(RTFile *f) // called by FS_Truncate
{
   int i, j, first_zero = -1;

   fs_assert_local(f && f->usr_ptr_type == FS_TBL_USR_PTR_MILESTONE);

   for (i = 0; i < f->HintNum; i++)
   {
      if (f->Seek_Hint[i].Cluster == 0 || f->Seek_Hint[i].Index > f->FilePointer)
      {
         f->Seek_Hint[i].Cluster = 0;

         if (FS_SEEKHINT_IS_STATIC(f, i))
            ((FS_SeekHintData *)f->usr_ptr)->UsedStaticHintCount--;

         for (j = i + 1; j < f->HintNum; j++)
         {
            if (f->Seek_Hint[j].Cluster != 0 && f->Seek_Hint[j].Index <= f->FilePointer)
            {
               f->Seek_Hint[i].Cluster  = f->Seek_Hint[j].Cluster;
               f->Seek_Hint[i].Index    = f->Seek_Hint[j].Index;

               break;
            }
         }

         if (f->Seek_Hint[i].Cluster == 0 && first_zero == -1)
            first_zero = i;
      }
   }

   if (first_zero != -1)
      f->HintNum = first_zero;

   MTSH_ReCalHintData(f);
}

int MTSH_SortCompareFunc (const void * a, const void * b)
{
  return ( ((RTFDirLocation*)a)->Index - ((RTFDirLocation*)b)->Index );
}

void MTSH_SortHint(RTFDirLocation *Hint, int Count)
{
   qsort(Hint, Count, sizeof(RTFDirLocation), MTSH_SortCompareFunc);
}

void MTSH_AddSeekHint(RTFile *f, RTFDirLocation *Hint, UINT Type)
{
   int         i, i_min = -1;
   kal_uint32  val, val1;
   int         tmp_free = -1;
   FS_SeekHintData *SeekHintData = NULL;

   fs_assert_local(f && f->usr_ptr_type == FS_TBL_USR_PTR_MILESTONE);

   SeekHintData = (FS_SeekHintData *)f->usr_ptr;

   if (Hint->Cluster == 0 || Hint->Index == 0) return;

   // find the same hint
   for (val = 0xFFFFFFFF, i = 0; i < f->HintNum; i++)
   {
      if ((f->Seek_Hint[i].Index & ~FS_SEEKHINT_TYPE_MASK) == Hint->Index) // the same location is found
      {
         if (Type == FS_SEEKHINT_TYPE_STATIC && !FS_SEEKHINT_IS_STATIC(f, i))
         {
            if (f->Seek_Hint[i].Cluster != Hint->Cluster)
            {
               fs_assert_local(0);
            }

            if (SeekHintData->UsedStaticHintCount < SeekHintData->StaticHintCount)
            {
               FS_SEEKHINT_SET_STATIC(f, i);  // directly let CLASSIC hint become STATIC

               SeekHintData->UsedStaticHintCount++;
            }

            // else means static hint is full and do nothing.
         }

         return;
      }
   }

   // check if free hint is available
   if (f->HintNum < SeekHintData->StaticHintCount)
      i_min = f->HintNum++;

   // there is no free hint
   if (i_min == -1)
   {
      // if #static_hint + #classic_hint is not full, directly replace a dynamic hint
      for (i_min = -1, tmp_free = -1, val = 0, val1 = 0xFFFFFFFF, i = 0; i < f->HintNum; i++)
      {
         if (FS_SEEKHINT_IS_CLASSIC(f, i))
         {
            if (f->Seek_Hint[i].Index >= Hint->Index) // find the minimum
            {
               if (f->Seek_Hint[i].Index < val1)
               {
                  val1 = f->Seek_Hint[i].Index;
                  tmp_free = i;
               }
            }
            else  // f->Seek_Hint[i].Index < Hint->Index (find the maximum)
            {
               if (f->Seek_Hint[i].Index > val)
               {
                  val = f->Seek_Hint[i].Index;
                  i_min = i;
               }
            }
         }
      }

      if (tmp_free != -1)
         i_min = tmp_free;

   }

   // add static hint
   if (i_min != -1)
   {
      f->Seek_Hint[i_min].Cluster = Hint->Cluster;
      f->Seek_Hint[i_min].Index   = Hint->Index;

      //FS_SEEKHINT_SET_STATIC(f, i_min); // ignore static hint mark (0)

      // it must be a free hint
      if (SeekHintData->UsedStaticHintCount < SeekHintData->StaticHintCount)
      {
         SeekHintData->UsedStaticHintCount++;
      }

      MTSH_SortHint(f->Seek_Hint, f->HintNum);
   }
}

RTFCluster MTSH_GetNextStaticMilestone(RTFile *f, kal_uint32 CurrPos)
{
    FS_SeekHintData *SeekHintData = NULL;

    fs_assert_local(f && f->usr_ptr_type == FS_TBL_USR_PTR_MILESTONE);

    SeekHintData = (FS_SeekHintData *)f->usr_ptr;

   if ((SeekHintData->UsedStaticHintCount == SeekHintData->StaticHintCount) ||
       (SeekHintData->StaticHintRange == 0))
      return 0;
   else
   {
      CurrPos = CurrPos / SeekHintData->StaticHintRange;

      CurrPos = SeekHintData->StaticHintRange * (CurrPos + 1);

      if (CurrPos + SeekHintData->StaticHintRange > f->DirEntry.Dir.FileSize)
         CurrPos = 0;

      return CurrPos;
   }
}

int MTSH_SearchHint(RTFile *f, UINT Pos)
{
   int i;

   for (i = f->HintNum - 1; i >= 0; i--)
   {
      if ((f->Seek_Hint[i].Index & ~FS_SEEKHINT_TYPE_MASK) <= Pos)
         return i;
   }

   return -1;
}

#endif // __FS_SMART_FILE_SEEKER__

/*-----------------------------------*/
//long RTFAPI RTFSeek(RTFHANDLE File, long Offset, int Whence)
kal_int64 RTFAPI RTFSeek(RTFHANDLE File, kal_int64 Offset, int Whence)
{
   RTFile *volatile f = NULL;
   kal_uint32       StartPos = 0; /* Remove RVCT warning, Karen Hsu, 2004/11/02, MOD */
   kal_uint32 volatile   NewPos;
   RTFSector        Sector;
   int              Result = RTF_NO_ERROR;
   kal_uint32       extend_file_option = 0;
   #ifdef __FS_SMART_FILE_SEEKER__
   kal_uint32       next_milestone;
   kal_uint32       file_pos = 0;
   RTFDirLocation   seek_hint = {0, 0};
   #endif

   XTRY
      case XCODE:

         f = ParseFileHandle(File);

         if ((f->SpecialKind == NormalFile) && (f->FilePointer > f->DirEntry.Dir.FileSize))
         {
            fs_util_trace_err_noinfo(RTF_INVALID_FILE_POS);
            fs_util_trace_info2(NULL, FS_ERR_RTFSEEK_FPTR_OUT_OF_RANGE, f->FilePointer, f->DirEntry.Dir.FileSize, NULL);

            XRAISE(RTF_INVALID_FILE_POS);
         }

         #ifdef __FS_TRACE_SUPPORT_OPEN_HINT__
         #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
         #endif
         #endif

         #ifdef __FS_SMART_FILE_SEEKER__
         if (f && f->usr_ptr_type == FS_TBL_USR_PTR_MILESTONE && f->usr_ptr)
         {
            file_pos = f->FilePointer;
         }
         #endif

         switch (Whence)
         {
            case RTF_FILE_BEGIN:

               if (f->SpecialKind == FileMapFile)
               {
                  StartPos = f->DirEntry.ShortPos.Index; /* BIAS */
               }
               else
               {
                  StartPos = 0;
               }

               break;
            case RTF_FILE_CURRENT:
               StartPos = f->FilePointer;
               break;
            case RTF_FILE_END:
               StartPos = f->DirEntry.Dir.FileSize;
               break;
            default:
               fs_util_trace_err_noinfo(RTF_INVALID_FILE_POS);
               fs_util_trace_info1(NULL, FS_ERR_RTFSEEK_INVALID_WHENCE, Whence, NULL);

               XRAISE(RTF_PARAM_ERROR);
         }

         Offset = (kal_int64)StartPos + Offset;

         if (Offset < 0 || Offset >= ((kal_int64)2 << 32))  // new offset can't exceed 4 GB (FAT spec)
         {
            fs_util_trace_err_noinfo(RTF_INVALID_FILE_POS);
            fs_util_trace_info4(NULL, FS_ERR_RTFSEEK_FPTR_WRAP_AROUND, StartPos, Offset, NewPos, NULL, NULL);

            XRAISE(RTF_INVALID_FILE_POS);
         }

         NewPos = (kal_uint32)Offset;

         if (f->SpecialKind == Volume || f->SpecialKind == PhysicalDisk)
         {
            if ((NewPos & (f->Dev->DevData.SectorSize-1)) != 0)
            {
               fs_util_trace_err_noinfo(RTF_INVALID_FILE_POS);
               fs_util_trace_info4(NULL, FS_ERR_RTFSEEK_MUST_READ_SECTOR_ALIGNED, StartPos, Offset, NewPos, NULL, NULL);

               XRAISE(RTF_INVALID_FILE_POS);
            }

            f->FilePointer = NewPos;
            break;
         }
         else if(f->SpecialKind == FileMapFile)
         {
            if( RTF_NO_ERROR != MTChkMapedFH( f->DirEntry.LongPos.Index ) ) /* LINK */
            {
               fs_util_trace_err_noinfo(MT_VF_MAP_ERROR);
               fs_util_trace_info1(NULL, FS_ERR_RTFSEEK_INVALID_FMAPED_HANDLE, f->DirEntry.LongPos.Index, NULL);

               XRAISE(MT_VF_MAP_ERROR);
            }
         }

         if (NewPos > f->DirEntry.Dir.FileSize)
         {
            if (f->Flags & RTF_READ_ONLY)
            {
               fs_util_trace_err_noinfo(RTF_INVALID_FILE_POS);
               fs_util_trace_info2(NULL, FS_ERR_RTFSEEK_CANT_EXTEND_READ_ONLY_FILE, NewPos, f->DirEntry.Dir.FileSize, NULL);

               XRAISE(RTF_INVALID_FILE_POS);
            }

            if (FIRST_FILE_CLUSTER(f->DirEntry.Dir) == RTF_ROOT_DIR)
            {
               fs_util_trace_err_noinfo(RTF_INVALID_FILE_POS);
               fs_util_trace_info2(NULL, FS_ERR_RTFSEEK_CANT_EXTEND_ROOT_DIR, NewPos, f->DirEntry.Dir.FileSize, NULL);

               XRAISE(RTF_INVALID_FILE_POS);
            }

            if (FIRST_FILE_CLUSTER(f->DirEntry.Dir) == 0)   // if no cluster allocated for this file, flush FAT and dir entry after allocation
            {
                extend_file_option = FS_COMMITTED;
            }
         }

         Sector = CLUSTER_TO_SECTOR_OFS(f->Drive, f->Cluster, f->Offset);

         /* we need to go back */
         if (NewPos < f->FilePointer)
         {
            /* we need to go back at least one cluster */
            if ((f->FilePointer - NewPos) > f->Offset)
            {
               /*-----------------------------------------------
                * Fixed seek hint support
                *-----------------------------------------------*/

               #ifdef __FS_SMART_FILE_SEEKER__
               if ((f->usr_ptr_type == FS_TBL_USR_PTR_MILESTONE && !f->usr_ptr && f->HintNum && (f->Seek_Hint[0].Index <= NewPos)) ||
                   (f->usr_ptr_type == FS_TBL_USR_PTR_MILESTONE &&  f->usr_ptr && f->HintNum))
               #else
               if (f->HintNum && (f->Seek_Hint[0].Index <= NewPos))
               #endif // __FS_SMART_FILE_SEEKER__
               {
                  int   i;
                  kal_uint32 Ofs;

                  /* find the hint whose index is smaller and closest to NewPos */

                  #ifdef __FS_SMART_FILE_SEEKER__
                  if (f->usr_ptr_type == FS_TBL_USR_PTR_MILESTONE && f->usr_ptr)
                  {
                     i = MTSH_SearchHint(f, NewPos);

                     if (-1 == i)
                        goto SeekNoHint;
                  }
                  else
                  #endif // __FS_SMART_FILE_SEEKER__
                  {
                     for (i = f->HintNum - 1; i >= 0; i--)
                     {
                        if (f->Seek_Hint[i].Index <= NewPos)
                           break;
                     }
                  }

                  f->FilePointer = NewPos;
                  f->Cluster = FIRST_FILE_CLUSTER(f->DirEntry.Dir);

                  if (f->Cluster == RTF_ROOT_DIR)
                  {
                     f->LastCluster = 0;
                     f->FilePointer = NewPos;
                     f->Offset = NewPos;
                     goto SeekContinue;
                  }

                  /* get offset between NewPos and hint, note that hint->Index must be cluster-aligned! */
                  #ifdef __FS_SMART_FILE_SEEKER__
                  Ofs = NewPos - (f->Seek_Hint[i].Index & ~FS_SEEKHINT_TYPE_MASK);
                  #else
                  Ofs = NewPos - f->Seek_Hint[i].Index;
                  #endif

                  /* set f->Cluster to start line of seek: hint->Cluster */
                  f->Cluster = f->Seek_Hint[i].Cluster;

                  #ifdef __FS_SMART_FILE_SEEKER__
                  if (f->usr_ptr_type == FS_TBL_USR_PTR_MILESTONE && f->usr_ptr)
                  {
                     file_pos = (f->Seek_Hint[i].Index & ~FS_SEEKHINT_TYPE_MASK);

                     next_milestone = MTSH_GetNextStaticMilestone(f, file_pos);
                  }
                  else
                  {
                     next_milestone = 0;
                  }
                  #endif

                  /* calculate f->Cluster by looping until offset fits in cluster size */
                  while (Ofs >= f->Drive->ClusterSize)
                  {
                     if ((f->Cluster < 2L) || (f->Cluster >= RTF_CLUSTER_CHAIN_END))
                     {
                        fs_util_trace_err_noinfo(RTF_FAT_ALLOC_ERROR);
                        fs_util_trace_info1(NULL, FS_ERR_RTFSEEK_INVALID_CLUSTER, f->Cluster, NULL);

                        XRAISE(RTF_FAT_ALLOC_ERROR);
                     }

                     #ifdef __FS_SMART_FILE_SEEKER__
                     if (next_milestone)
                     {
                        if ((file_pos >> f->Drive->ClusterShift) == (next_milestone >> f->Drive->ClusterShift))
                        {
                           if (f->Cluster >= RTF_CLUSTER_CHAIN_END)
                              seek_hint.Cluster = f->LastCluster;
                           else
                              seek_hint.Cluster = f->Cluster;

                           seek_hint.Index   = (file_pos >> f->Drive->ClusterShift) << f->Drive->ClusterShift;
                           MTSH_AddSeekHint(f, &seek_hint, FS_SEEKHINT_TYPE_STATIC);

                           next_milestone = MTSH_GetNextStaticMilestone(f, next_milestone);
                        }

                        file_pos += f->Drive->ClusterSize; // step to next cluster first (f->Cluster will be updated below)
                     }
                     #endif

                     Ofs -= f->Drive->ClusterSize;

                     /* get next cluster value */
                     f->LastCluster = f->Cluster;

                     f->Cluster = GetClusterValue(f->Drive, f->LastCluster);
                  }

                  /* set f->Cluster to 0 if it is the end of cluster chain */
                  if (f->Cluster >= RTF_CLUSTER_CHAIN_END)
                     f->Cluster = 0;

                  /* set f->Offset */
                  f->Offset = Ofs;

                  #ifdef __FS_SMART_FILE_SEEKER__
                  if (f->usr_ptr_type == FS_TBL_USR_PTR_MILESTONE && f->usr_ptr)
                  {
                     // check if static hint is required
                     if (next_milestone && f->FilePointer >> f->Drive->ClusterShift == next_milestone >> f->Drive->ClusterShift)
                     {
                        if (f->Cluster)
                           seek_hint.Cluster = f->Cluster;
                        else
                           seek_hint.Cluster = f->LastCluster;

                        seek_hint.Index   = (f->FilePointer >> f->Drive->ClusterShift) << f->Drive->ClusterShift;
                        MTSH_AddSeekHint(f, &seek_hint, FS_SEEKHINT_TYPE_STATIC);
                     }
                  }
                  #endif

                  goto SeekContinue;
               }

#ifdef __FS_SMART_FILE_SEEKER__
SeekNoHint:
#endif
               /*----------------------------------------------------
                * if seek hint is not existed or not applicable
                *----------------------------------------------------*/

               /* clear f->FilePointer, Offset, Cluster and LastCluster */
               InitFilePointer(f);

               /* use traditional method to move file pointer */
               MoveFilePointer(f, NewPos);
            }
            /* go back but still within the same cluster */
            else
            {
               /* everything is simple, just substract f->Offset and FilePointer by offset */
               f->Offset -= f->FilePointer - NewPos;
               f->FilePointer -= f->FilePointer - NewPos;
            }
         }
         else if (NewPos > f->FilePointer)
         {
            kal_uint32 NextClusterBoundary;
            kal_uint32 l;

            /*-----------------------------------------------
             * seek hint support
             *-----------------------------------------------*/

            if(f->HintNum)
            {
               #ifdef __FS_SMART_FILE_SEEKER__
               if(((f->usr_ptr_type == FS_TBL_USR_PTR_MILESTONE && !f->usr_ptr && (f->FilePointer < f->Seek_Hint[f->HintNum-1].Index) && (f->Seek_Hint[0].Index <= NewPos))) ||
                   (f->usr_ptr_type == FS_TBL_USR_PTR_MILESTONE &&  f->usr_ptr))
               #else
               if((f->FilePointer < f->Seek_Hint[f->HintNum-1].Index) && (f->Seek_Hint[0].Index <= NewPos))
               #endif
               {
                  int i;

                  #ifdef __FS_SMART_FILE_SEEKER__
                  if (f->usr_ptr_type == FS_TBL_USR_PTR_MILESTONE && f->usr_ptr)
                  {
                     if ((f->FilePointer >> f->Drive->ClusterShift) != (NewPos >> f->Drive->ClusterShift))
                     {
                        i = MTSH_SearchHint(f, NewPos);

                        if (-1 != i &&
                           ((f->Seek_Hint[i].Index & ~FS_SEEKHINT_TYPE_MASK) > f->FilePointer)) // do not use the hint before current file position
                        {
                           f->FilePointer = (f->Seek_Hint[i].Index & ~FS_SEEKHINT_TYPE_MASK);
                           f->Offset = 0;
                           f->Cluster = f->Seek_Hint[i].Cluster;
                        }
                     }

                     // skip hint search if move within current cluster to enhance performance
                  }
                  else // seekhint_ver == 0
                  #endif
                  {
                     /* find the closest hint, then set start line to that hint to save seek time */
                     for(i = f->HintNum - 1; i >= 0; i--)
                     {
                        if(f->Seek_Hint[i].Index <= NewPos)
                        {
                           if (f->Seek_Hint[i].Index > f->FilePointer)  // do not use the hint before current file position
                           {
                              f->FilePointer = f->Seek_Hint[i].Index;
                              f->Offset = 0;
                              f->Cluster = f->Seek_Hint[i].Cluster;
                           }

                           break;
                        }
                     }
                  }
               }
            }

            NextClusterBoundary = RTFRoundUp(f->FilePointer, f->Drive->ClusterSize);

            // move to the next cluster boundary
            if (NextClusterBoundary > NewPos)
               NextClusterBoundary = NewPos;

            l = NextClusterBoundary - f->FilePointer;

            if (l > 0)
               MoveFilePointer(f, l);

            l = NewPos - f->FilePointer;

            while (l > 0)
            {
                if (f->Cluster == 0)
                {
                    #ifdef __FS_SEEK_NOT_EXTEND_FILE_IF_DISK_FULL__
                    if (RTF_INVALID_CLUSTER == f->Drive->FreeClusterCount)
                    {
                        f->Drive->FreeClusterCount = 0;
                        f->Drive->ClusterWatermark = RTF_INVALID_CLUSTER;
                        BatchCountFreeClusters(f->Drive);
                    }

                    // how many bytes required to be extended
                    NextClusterBoundary = NewPos - f->FilePointer;

                    // number of bytes => number of clusters
                    NextClusterBoundary = ((NextClusterBoundary - 1) >> (f->Drive->ClusterShift)) + 1;

                    // raise RTF_DISK_FULL if no enough free clusters
                    if (NextClusterBoundary > f->Drive->FreeClusterCount)
                    {
                        XRAISE(RTF_DISK_FULL);
                    }
                    #endif // __FS_SEEK_NOT_EXTEND_FILE_IF_DISK_FULL__

                    ExtendFile(f, l, extend_file_option);  // extend_file_option will set FS_COMMITTED to flush FAT and dir entry for 1st cluster allocation of this file

                    extend_file_option= 0;
                }

                MoveFilePointerSegment(f, l);
                l = NewPos - f->FilePointer;
            }

            if (NewPos > f->DirEntry.Dir.FileSize)
            {
               f->DirEntry.Dir.FileSize = NewPos;
               UpdateDirEntry(f);

               if (f->Flags & RTF_COMMITTED)
               {
                  FlushFAT(f->Dev);
               }

               #ifdef __FS_SMART_FILE_SEEKER__
               if (f->usr_ptr_type == FS_TBL_USR_PTR_MILESTONE && f->usr_ptr)
               {
                  MTSH_ReCalHintData(f);
               }
               #endif
            }
         }
SeekContinue: /* Speedup seek, Karen Hsu, 2004/05/14 */

	     /* find the the original sector buffer before seek, commit it if we don't need it */
         if ((Sector != CLUSTER_TO_SECTOR_OFS(f->Drive, f->Cluster, f->Offset)) &&
             ((f->Flags & RTF_LAZY_DATA) == 0) &&
             SearchBuffer(f->Dev, Sector))
         {
            CommitBuffer(f->Dev);
            if ((f->Flags & RTF_CACHE_DATA) == 0)
               DiscardBuffer(f->Dev);
         }
         break;
      default:
         Result = XVALUE;
         if (XVALUE==RTF_DISK_FULL && f->FilePointer > f->DirEntry.Dir.FileSize)
         {
               f->DirEntry.Dir.FileSize = f->FilePointer;
               UpdateDirEntry(f);
               if (f->Flags & RTF_COMMITTED)
                  FlushFAT(f->Dev);

               #ifdef __FS_SMART_FILE_SEEKER__
               if (f->usr_ptr_type == FS_TBL_USR_PTR_MILESTONE && f->usr_ptr)
               {
                  MTSH_ReCalHintData(f);
               }
               #endif
         }
         break;
      case XFINALLY:

         #ifdef __FS_TRACE_SUPPORT_OPEN_HINT__
         #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
         #endif
         #endif

         if (f) UnlockDevice(f->Dev);
         break;
   XEND_API

   if (f->SpecialKind == FileMapFile)
   {
      NewPos -= f->DirEntry.ShortPos.Index; /* BIAS */
   }

   if (Result < RTF_NO_ERROR)
      return (kal_int64)Result;
   else
      return (kal_int64)NewPos;
}

/*-----------------------------------*/
int RTFAPI RTFExtend(RTFHANDLE File, kal_uint32 Length)
{
   RTFile * volatile f = NULL;
   UINT        Try = 0;
   RTFCluster  CurrClusters,
               NewClusters,
               //ClusterStart,
               ChainTo,
               SegmentLength,
               C,
               MaxSegment;
   kal_uint32  TotalBytes;

   int         Result, quota_idx = -1; /* Add for quota management, Karen Hsu, 2004/08/10, ADD */

   XTRY
      case XCODE:
         f = ParseFileHandle(File);
         if ((f->SpecialKind != NormalFile) ||
             (f->Flags & RTF_READ_ONLY) ||
             (FIRST_FILE_CLUSTER(f->DirEntry.Dir) == RTF_ROOT_DIR))
         {
            fs_util_trace_err_noinfo(MT_READ_ONLY_ERROR);

            XRAISE(MT_READ_ONLY_ERROR);
         }

         if (f->FilePointer > f->DirEntry.Dir.FileSize)
         {
            fs_util_trace_err_noinfo(RTF_INVALID_FILE_POS);
            fs_util_trace_info2(NULL, FS_ERR_RTFEXTEND_FPTR_OUT_OF_RANGE, f->FilePointer, f->DirEntry.Dir.FileSize, NULL);

            XRAISE(RTF_INVALID_FILE_POS);
         }

         TotalBytes = f->FilePointer + Length;

         /* file size wrap around */
         if (TotalBytes < f->FilePointer)
         {
            fs_util_trace_err_noinfo(RTF_FILE_TOO_LARGE);
            fs_util_trace_info2(NULL, FS_ERR_RTFEXTEND_FSIZE_WRAP_AROUND, f->FilePointer, Length, NULL);

            XRAISE(RTF_FILE_TOO_LARGE);
         }

         /* Speed Up Extend Algo, MTK_WCP_SW , 2006/05/17, MOD START */
         if (FIRST_FILE_CLUSTER(f->DirEntry.Dir) == 0) // zero file size
         {
            ChainTo = f->Drive->ClusterWatermark;
            CurrClusters = 0;
            C = ChainTo;
         }
         else if (f->Cluster == 0) // file pointer *just* on the boundy, cluster not allocated yet
         {
            fs_assert_local(f->Offset == 0);

            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif

            ChainTo = f->LastCluster;
            TotalBytes = Length;
            CurrClusters = 0;
            C = f->Drive->ClusterWatermark;
         }
         else // file pointer correctly set, calculate partial offset
         {
            TotalBytes = f->Offset + Length;
            CurrClusters = FATClusterChainLength(f->Drive, f->Cluster, &ChainTo);
            C = ChainTo;
         }
         /* Speed Up Extend Algo, MTK_WCP_SW , 2006/05/17, MOD END   */

         if (TotalBytes > 0)
            NewClusters = ((TotalBytes-1) >> f->Drive->ClusterShift) + 1;
         else
            NewClusters = 0;

         if (NewClusters > CurrClusters)
            NewClusters -= CurrClusters;
         else
            break; // nothing to do

         Result = AllocateFATSegmentPermit(f, NewClusters, &quota_idx);

         if(Result < RTF_NO_ERROR)
         {
            XRAISE(Result);
         }

         MaxSegment = 0;

         while (1)
         {
            SegmentLength = FATZeros(f->Drive, C, NewClusters);
            if (SegmentLength >= NewClusters)
            {
               /* Add for quota management, Karen Hsu, 2004/08/10, ADD END */
               FATMarkSegment(f->Drive, C, NewClusters);

#ifdef __FS_QM_SUPPORT__
               if(quota_idx >= 0)
               {
                  gFS_IntQuotaSet[quota_idx].Uint += NewClusters; /* Add for quota management, Karen Hsu, 2004/08/10, ADD */

                  fs_util_trace_info2(TRACE_ERROR, FS_INFO_QUOTA_STATUS_NOW_RTFEXTEND, quota_idx, gFS_IntQuotaSet[quota_idx].Uint, NULL);
               }
#endif

               if (FIRST_FILE_CLUSTER(f->DirEntry.Dir) == 0)
               {
                  FlushFAT(f->Dev); // flush FAT table first to avoid dangling FirstCluster

                  SET_FIRST_FILE_CLUSTER(f->DirEntry.Dir, C);

                  UpdateDirEntry(f);

                  FlushAllBuffersInGeometryOrder(f->Dev);   // flush dir entry for file missing after powerloss issue
               }
               else
                  SetClusterValue(f->Drive, ChainTo, C);
               break;
            }
            else /* if (SegmentLength >= NewClusters) */
            {
               C += SegmentLength + 1;
               if (SegmentLength > MaxSegment)
                  MaxSegment = SegmentLength;
               /* Improve Response Time, MTK_WCP_SW , 2006/02/22, ADD START */
               C = FATSearchZeroInBuffer(f->Drive, C);
               /* Improve Response Time, MTK_WCP_SW , 2006/02/22, ADD END   */
               /* Multiple Sub Cluster Watermark, MTK_WCP_SW , 2006/02/24, ADD START */
#if !defined(__NOT_SUPPORT_FAT32__)
               if ((C & SUBMARK_MASK) == 0x0)
               {
                  C = FATHintSearchBySubMark(f->Drive, C, (Try == 1 && NewClusters == 1));
               }
#endif /* __NOT_SUPPORT_FAT32__ */
               /* Multiple Sub Cluster Watermark, MTK_WCP_SW , 2006/02/24, ADD END   */
               if (C >= f->Drive->Clusters)
               {
                  if ((Try == 0) && (ChainTo > 2))
                  {
                     C = 2;
                     Try = 1;
                  }
                  else
                  {
                     /* Distinguish Disk Full or Disk Fragment, MTK_WCP_SW , 2006/05/17, ADD START */
                     if (MaxSegment > 0)
                     {
                        fs_util_trace_err_noinfo(MT_DISK_FRAGMENT);

                        XRAISE(MT_DISK_FRAGMENT);
                     }
                     /* Distinguish Disk Full or Disk Fragment, MTK_WCP_SW , 2006/05/17, ADD END   */

                     fs_util_trace_err_noinfo(RTF_DISK_FULL);

                     XRAISE(RTF_DISK_FULL);
                  }
               }
            } /* END else (SegmentLength >= NewClusters) */
         }

         if (f->Cluster == 0) // space was allocated, need to update f->Cluster
         {
            kal_uint32 Pos = f->FilePointer;
            InitFilePointer(f);
            MoveFilePointer(f, Pos);
         }

         break;
      default:
         break;
      case XFINALLY:
         if (f) UnlockDevice(f->Dev);
         break;
   XEND_API
   return RTF_NO_ERROR;
}


/*-----------------------------------------------------------------------
 * Extending character string (e.g., short file name) to wdie character string
 *
 * max_length: The maximum number of characters of native name (not including tailed NULL, unit: byte)
 * filename:   Buffer with original native name and it will be used to store extended name.
 *
 * !NOTE! The length of filename buffer should be at least (2 x max_name_length + 2) bytes! (additional 2 bytes are for tailed L'\0')
 *-----------------------------------------------------------------------*/
void RTFAPI FileNameExtendToWCHAR(char *filename, kal_uint32 max_length)
{
   // for Thai encoding issues: 0xA8 0x00 0xA8 0x00 ...
   int         len;
   int         i = 0, j;
   kal_uint32  encoding_length;

   encoding_length = fs_util_get_default_encoding_length();

   if (filename[0] == 0x05) filename[0] = 0xE5;

   j = len = MTNativeFileNameLen(filename, encoding_length, max_length);

   while (filename[i])
   {
      /*------- ASCII: extend to 2 bytes -------*/
      if ((kal_uint8)filename[i] < 0x80 ||
         (encoding_length == 1 && filename[i] & 0x80))
      {
         /* generate new tail */
         filename[j + 2] = '\0';
         filename[j + 1] = '\0';

         /* shift other characters to right by 1 byte */
         while (j > i + 1)
         {
            filename[j] = filename[j - 1];
            j--;
         }

         /* fill 0 in higher byte of this extended ASCII character */
         filename[i + 1] = 0;

         /* increase total string length */
         len++;
         j = len;
      }
      /*--------------------------------------------------------------------------
       * for Non-ASCII char, Skip 2 bytes (Assuming this is a 2-byte non-ASCII char)
       * for ASCII char, it was extended to 2-byte above, also skip 2 bytes
       *--------------------------------------------------------------------------*/
      i += 2;

      // for corrupted file name, use a bound to avoid memory corruption
      if (i >= (max_length * 2))
      {
         i = (max_length * 2);
         filename[i] = 0;
         break;
      }
   }

   /* make sure tailing has 2-byte NULL */
   filename[i + 1]=0;

   if (filename[0] == 0x05 && filename[1] != 0x00)
      filename[0] = 0xE5;
}

/*-----------------------------------*/
/*Both of the arguments are in type of WCHAR * */
int RTFAPI FileNamesMatch(const WCHAR * p, const WCHAR * n)
{
   const WCHAR * LastWild = NULL;
   const WCHAR * LastWildN = NULL;

   while (1)
   {
      while ( p[0] && n[0] )
      {
         WCHAR P = fs_util_wchar_toupper(p[0]);
         WCHAR N = fs_util_wchar_toupper(n[0]);

         /* '*' */
         if (P == 0x2a)
         {
            LastWild = p;

            if (fs_util_wchar_toupper(p[1]) == N)
            {
               LastWildN = n;
               p++;
               P = fs_util_wchar_toupper(p[0]);
            }
         }
         if ((P == N) || (P == 0x3F))  // 0x3F: '?'
            p++, n++;
         else if (P == 0x2A) // '*'
            n++;
         else
            break;
      }

      if ( (n[0]==0) && (p[0]==0 || (p[0]==0x2a && p[1]==0)) )  // 1. both p and n is ended. 2. p has only one "*"
         return 1;

      if (LastWild && LastWildN && LastWildN[1])
      {
         p = LastWild;
         n = ++LastWildN;
      }
      else
         return 0;
   }
}

/*-----------------------------------*/
int  RTFAPI RTFFindClose(RTFHANDLE Handle)
{
   #ifdef __FS_OPEN_HINT__
   MTHintFindClose(Handle);
   #endif

   return RTFClose(Handle);
}

/*-------------------------------------------------------
 * Please note that MaxLength is counted in bytes, *not* characters.
 * It is the caller's responsibility to pass a proper buffer, "FileName".
 * If it is not large enough to hold the whole long file name,
 * the short file name will be returned.
 *
 * If MaxLength has flag MT_HINT_DISABLE, hint mechanism will not be involved. (Internal Use only, added in W10.05)
 *-------------------------------------------------------*/
int RTFAPI RTFFindNextEx(RTFHANDLE Handle, RTFDOSDirEntry * FileInfo, WCHAR * FileName, UINT MaxLength, RTFFileOpenHint *OpenHint)
{
   int                       LFNIndex = -1;
   RTFile *volatile          f = NULL;
   RTFFileOpenHint *volatile hint_ext = OpenHint;
   const char                *NamePattern;
   RTFDirLocation            *Pos;
   BYTE                      *A;
   BYTE                      CheckSum = 0;
   BYTE                      NTReserved = 0;
   #ifdef __FS_OPEN_HINT__
   kal_uint8                 internal_hint = 0;
   RTFDirLocation volatile   hint_local = {0, 0}; // ensure RTFFindNextEx preserve the location of found file if OpenHint is NULL.
   #endif

   XTRY
      case XCODE:
         f = ParseFileHandle(Handle);

         /* Add to abort in the middle of action, Karen Hsu, 2004/05/03, ADD START */
         if(f->Valid == FS_FH_ABORTED)
         {
            fs_util_trace_err_noinfo(MT_ABORTED_ERROR);

            XRAISE(MT_ABORTED_ERROR);
         }
         /* Add to abort in the middle of action, Karen Hsu, 2004/05/03, ADD END */

         if (f->SpecialKind != NormalFile)
         {
            fs_util_trace_err_noinfo(FS_INVALID_FILE_HANDLE);

            XRAISE(FS_INVALID_FILE_HANDLE);
         }

         if ((f->DirEntry.Dir.Attributes & RTF_ATTR_DIR) == 0)
         {
            fs_util_trace_err_noinfo(FS_INVALID_FILE_HANDLE);

            XRAISE(FS_INVALID_FILE_HANDLE);
         }

         NamePattern = kal_dchar_strrchr(f->FullName, '\\')+2;
         A           = (void*) &f->LastCluster;
         Pos         = (void*) &f->Cluster;

         if ((A[0] == 0xFF) && (A[1] == 0xFF))
         {
            fs_util_trace_err_noinfo(FS_NO_MORE_FILES);

            XRAISE(FS_NO_MORE_FILES);
         }

         if ( kal_dchar_strcmp(NamePattern, (char *)dchar_start_dot_star) == 0 )
            NamePattern += 4;

         // reset open hint
         if (hint_ext != NULL)
         {
            #ifdef __FS_OPEN_HINT__
            /*
             * if there is no external hint passed to RTFFindFirstEx(), here hint_ext must come
             * from internal hint (FORCE_NEW).
             *
             * To prevent being overwritten by external hint information, set internal_hint flag to 1.
             */
            if (MTIsInternalHint(hint_ext))
            {
               internal_hint = 1;
            }
            #endif /* __FS_OPEN_HINT__ */

            hint_ext->Cluster = 0;
         }
         #ifdef __FS_OPEN_HINT__
         else
         {
            /*
             * RTFFindFirstEx() needs to know the location of file found by
             * RTFFindNextEx(), therefore, RTFFindFirstEx() will prepare a location
             * space for RTFFindNextEx() to store the location.
             *
             * If hint is not required to involve, remain hint_ext as NULL
             */

            if ((MaxLength & MT_HINT_DISABLE) == 0)
            {
               hint_ext = (RTFFileOpenHint*)&hint_local;
               internal_hint = 1;
            }
         }
         #endif /* __FS_OPEN_HINT__ */

         // restore MaxLength if it is marked some additional flags
         if ((MaxLength & MT_HINT_DISABLE) != 0)
            MaxLength &= ~MT_HINT_DISABLE;

         f->DirEntry.LongPos.Cluster = 0; // reset LongPos

         while (1)
         {
            int Kind;
            const RTFDOSDirEntry * D = NextDir(f->Drive, Pos);

            if (D == NULL)
            {
               fs_util_trace_err_noinfo(FS_NO_MORE_FILES);

               XRAISE(FS_NO_MORE_FILES);
            }

            Kind = EntryType(D);

            if (Kind == NeverUsed)
            {
               fs_util_trace_err_noinfo(FS_NO_MORE_FILES);

               XRAISE(FS_NO_MORE_FILES);
            }
            else if (Kind == Lfn)
            {
               const LFNDirEntry * LD = (void*) D;

#ifdef __P_PROPRIETARY_COPYRIGHT__
/* under construction !*/
#endif

               if (LD->Ord & 0x40) // it's the start of an LFN
               {
                  // see if it fits
                  char * Limit;
                  LFNIndex = LD->Ord & 0x3F;
                  CheckSum = LD->CheckSum;

                  // temporarily set LongPos to the 1st LFN entry
                  f->DirEntry.LongPos = *Pos;

                  /* characters stored in the LFN entry are in 2-byte unicode*/
                  Limit = ( (char *)FileName) + ((LFNIndex-1)*13*2 + 2*LFNCharCount(LD) );
                  if (Limit > ( ((char *)FileName) + MaxLength - 1) || Limit < (char*)FileName) /* not able to hold */
                      LFNIndex = -1;
                  else
                  {
                     Limit[0] = '\0';
                     Limit[1] = '\0';
                  }
               }
               if ((LD->CheckSum != CheckSum) || (LFNIndex != (LD->Ord & 0x3F)) || (LFNIndex <= 0))
                  LFNIndex = -1;
               else
                  CopyLFN((char *)FileName + --LFNIndex * 26, LD);
            }
            else if ((Kind == InUse) && ((D->Attributes & A[1]) == A[0]))
            {
               // we got a new one!
               if (FileInfo != NULL)
                  *FileInfo = *D;

               /* Add LFN/SFN info for upper layer, Karen Hsu, 2004/4/28, MOD START */
               if (FileInfo != NULL)
                  FileInfo->NTReserved = MT_ENUM_FIND_NONE;

               // check against LFN first
               if ((LFNIndex == 0) && (CheckSum== ShortNameCheckSum((BYTE*) D->FileName)) && FileNamesMatch((WCHAR *)NamePattern, FileName))
               {
                  if (FileInfo != NULL)
                     FileInfo->NTReserved = MT_ENUM_FIND_LFN;

                  // fill open hint (for LFN)
                  if (hint_ext != NULL && f->DirEntry.LongPos.Cluster) // f->DirEntry.LongPos.Cluster must be non-zero!
                  {
                     hint_ext->Cluster = f->DirEntry.LongPos.Cluster;
                     hint_ext->Index   = f->DirEntry.LongPos.Index;
                  }

                  #ifdef __P_PROPRIETARY_COPYRIGHT__
/* under construction !*/
/* under construction !*/
                  #endif

                  break;
               }

               /*
                * Try SFN.
                *
                * NOTE 1: If only SFN matches the pattern and LFN is properly saved in FileName, then FileName will have LFN. (W10.43)
                *
                * NOTE 2: We can't skip SFN matching even if LFN is existed (FileName buffer is long enough) and valid but match failed!
                *         The reason is if user uses SFN to do FindFirst, FindNext will be failed if we skip SFN matching.
                */
               if ((MakeShortFileName(D, (char *)FileName, MaxLength) == RTF_NO_ERROR))
               {
                  FileNameExtendToWCHAR((char *)FileName, FS_MAX_SFN_NATIVE_FILE_NAME_LENGTH_B);

                  if ( FileNamesMatch((WCHAR *)NamePattern, FileName) )
                  {
                     #ifdef __P_PROPRIETARY_COPYRIGHT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                     #endif

                     if (FileInfo != NULL && FileInfo->FileName[0] == 0x05)
                        FileInfo->FileName[0] = 0xE5;

                     if (FileInfo != NULL)
                        FileInfo->NTReserved = MT_ENUM_FIND_SFN;

                     NTReserved = D->NTReserved;

                     // fill open hint (for SFN)
                     if (hint_ext != NULL)
                     {
                        if (f->DirEntry.LongPos.Cluster)
                        {
                           hint_ext->Cluster = f->DirEntry.LongPos.Cluster;
                           hint_ext->Index   = f->DirEntry.LongPos.Index;
                        }
                        else
                        {
                           hint_ext->Cluster = Pos->Cluster;
                           hint_ext->Index   = Pos->Index;
                        }
                     }

                     break;
                  }
               }
            }

            // reset LFNIndex if this file does not match pattern
            if (Kind != Lfn)
            {
               LFNIndex = -1;
               f->DirEntry.LongPos.Cluster = 0; // reset LongPos
            }
         }
         MTCheckFileNameCase(FileName, MaxLength, NTReserved);

         // fill open hint (general parts)
         #ifdef __FS_OPEN_HINT__
         if (hint_ext != NULL && internal_hint == 0)
         #else
         if (hint_ext != NULL)
         #endif
         {
            hint_ext->Drive = (UINT)f->Drive;
            hint_ext->SerialNumber = f->Drive->SerialNumber;
            hint_ext->Stamp = OpenHintStamp;
         }

         break;
      default:
         break;
      case XFINALLY:

         #ifdef __FS_OPEN_HINT__
         if (hint_ext != NULL && hint_ext->Cluster && XVALUE == 0)
            MTHintFindNext((RTFDirLocation*)hint_ext, Handle, FileName);
         #endif

         if (f) UnlockDevice(f->Dev);
         break;
   XEND_API
   return RTF_NO_ERROR;
}

/*-----------------------------------*/
RTFHANDLE RTFAPI RTFFindFirstEx(
        const WCHAR * NamePattern, BYTE Attr, BYTE AttrMask,
        RTFDOSDirEntry * FileInfo, WCHAR * FileName,
        UINT MaxLength, RTFFileOpenHint *OpenHint, kal_uint32 caller_address)
// the files must have at least all Attr1 attributes
// the files may not have any of Attr2
{
   int volatile              Result;
   RTFile * volatile         f = NULL;
   RTFDirLocation *          Pos;
   BYTE * volatile           A;
   #ifdef __FS_OPEN_HINT__
   WCHAR * volatile          tail_back_slash = NULL;
   RTFDirLocation *volatile  hint_int        = NULL;
   RTFFileOpenHint *volatile hint_ext        = OpenHint;
   #endif

   XTRY
      case XCODE:
         f = ParseFileName((char *)NamePattern);

         if (f->SpecialKind != NormalFile)
         {
            fs_util_trace_err_noinfo(RTF_INVALID_FILENAME);

            XRAISE(RTF_INVALID_FILENAME);
         }

         f->Flags = RTF_OPEN_DIR | RTF_READ_ONLY | RTF_CACHE_DATA;

         #ifdef __FS_OPEN_HINT__
         /*
          * Truncate any tail L'\\'
          * If not, hint patch X:\\A\\B\\B will be created by NamePattern "X:\\A\\B\\"
          */
         tail_back_slash = TruncateWideBackSlash((WCHAR*)NamePattern);

         if ((MaxLength & MT_HINT_DISABLE) == 0)
         {
            hint_int = MTHintGet(NamePattern, MT_HINT_ACTION_FORCE_NEW);  // forcedly create a new internal hint
         }
         /*
          * else, internal hint should not involve, hint_int remains NULL.
          * In this case, hint_ext(parameter OpenHint) should be NULL as well.
          * Even though there should be no error if hint_ext is not NULL.
          */

         if (SearchFile(f, SEARCH_PARENT | SEARCH_RELEASE_LOCK, (char *)NamePattern, hint_int))  // it's a directory or file
         #else
         if (SearchFile(f, SEARCH_PARENT | SEARCH_RELEASE_LOCK, (char *)NamePattern, NULL))  // it's a directory or file
         #endif /* __FS_OPEN_HINT__ */
         {
            if (f->DirEntry.DirCluster == 0) // there is no up level, it's the root
            {
               MakePseudoRootDirEntry(f->Drive, &f->DirEntry);
               if (FileInfo)
                  *FileInfo = f->DirEntry.Dir;
               setASCII(FileName, 0, '\\');
               setASCII(FileName, 1, 0);
               AttrMask = Attr = 0xFF; // special value for RTFFindNextEx
            }
            else
            {
               SET_FIRST_FILE_CLUSTER(f->DirEntry.Dir, f->DirEntry.DirCluster);
            }
         }
         #ifdef __FS_OPEN_HINT__
         else  // else we found the parent (return 0)
         {
            /*
             * f->DirEntry.Dir now is the parent of target folder/file.
             * Copy its start cluster to f->DirEntry.DirCluster to let
             * MTHintNew() keep DirCluster with new location.
             *
             * Note. RTFFindNextEx will not touch f->DirEntry.DirCluster
             */
            f->DirEntry.DirCluster = FIRST_FILE_CLUSTER(f->DirEntry.Dir);
         }
         #endif /* __FS_OPEN_HINT__ */

         InitFilePointer(f);

         A    = (void*) &f->LastCluster;
         Pos  = (void*) &f->Cluster;
         Pos->Index--;
         A[0] = Attr;
         A[1] = AttrMask | Attr;

         Result = MakeNewFileHandle(f);

         break;
      default:
         Result = XVALUE;
         XHANDLED; // escape X-loop to go through
         break;
      case XFINALLY:

         #ifdef __FS_OPEN_HINT__
         // restore tail back slash to not let user bahave abnormally
         if (tail_back_slash != NULL)
            *((WCHAR*)tail_back_slash) = L'\\';
         #endif /* __FS_OPEN_HINT__ */

         if (f != NULL)
         {
            if (Result < RTF_NO_ERROR)  {
               FreeFTSlotAndDevice(f);
            }
            else    {
               f->OwnerLR=caller_address;
               UnlockDevice(f->Dev);
            }
         }
         break;
   XEND_API

   if ((Result >= RTF_NO_ERROR) && (A[0] != 0xFF)  && (A[1] != 0xFF))
   {
      int R;

      #ifdef __FS_OPEN_HINT__
      /*
       * If OpenHint is NULL, use hint_int to get the location of file found
       * by RTFFindNextEx().
       *
       * If hint is not required to involve, let hint_ext remains NULL
       */

      if ((hint_ext == NULL) && (MaxLength & MT_HINT_DISABLE) == 0)
         hint_ext = (RTFFileOpenHint*)hint_int;

      /*
       * This is the first time call RTFFindNextEx(). Thus f->Flags & FS_FH_INTERNAL_HINT
       * must be 0, and MTHintFindNext() will do nothing inside.
       */

      R = RTFFindNextEx(Result, FileInfo, FileName, MaxLength, (RTFFileOpenHint*)hint_ext);
      #else
      R = RTFFindNextEx(Result, FileInfo, FileName, MaxLength, OpenHint);
      #endif /* __FS_OPEN_HINT__*/

      if (R == RTF_NO_ERROR)
      {
         #ifdef __FS_OPEN_HINT__
         MTHintFindFirst((FS_OpenHintInt*)hint_int, (RTFDirLocation*)hint_ext, f, FileName);
         #endif

         return Result;
      }
      else
      {
         #ifdef __FS_OPEN_HINT__
         MTHintFinish((FS_OpenHintInt*)hint_int);
         #endif

         RTFFindClose(Result);
         return R;
      }
   }
   else
   {
      #ifdef __FS_OPEN_HINT__
      MTHintFinish((FS_OpenHintInt*)hint_int);
      #endif

      return Result;
   }
}

int RTFAPI fs_srv_findnext(FS_HANDLE handle,
                       FS_Pattern_Struct * PatternArray, UINT PatternNum,
                       BYTE ArrayMask,
                       FS_DOSDirEntry * FileInfo, WCHAR * FileName, UINT MaxLength,
                       UINT Flag,
                       FS_FileLocationHint * FilePos)
{
    BYTE CheckSum = 0;
    int LFNIndex = -1;
    BYTE volatile AttrMask, Attr;
    RTFile * volatile f = NULL;
    const char * NamePattern;
    RTFDirLocation * Pos;
    UINT i;
    WCHAR * volatile FindName = NULL;
    UINT FindLength = 0;
    int LastIsLFN = 0;
    BYTE NTReserved = 0;
    kal_int32 volatile result = FS_NO_ERROR;
    BYTE * ptr;
    BYTE FilePosDone = KAL_TRUE;
    BYTE ctrl_buff_used = KAL_FALSE;

    //fs_util_trace_info0(TRACE_GROUP_8 | TRACE_FUNC, FS_TRC_RTF_NEXT, NULL);

    XTRY
    {
        case XCODE:
        {
            f = ParseFileHandle(handle);

            // get open hint
            //if (FileInfo)
            //    OpenHint = FS_GetOpenHintByDOSDirEntry(FileInfo);

            if(f->Valid == FS_FH_ABORTED)
            {
                fs_util_trace_err_noinfo(MT_ABORTED_ERROR);

                XRAISE(MT_ABORTED_ERROR);
            }

            if(f->SpecialKind != NormalFile)
            {
                fs_util_trace_err_noinfo(RTF_INVALID_FILE_HANDLE);

                XRAISE(RTF_INVALID_FILE_HANDLE);
            }

            if((f->DirEntry.Dir.Attributes & RTF_ATTR_DIR) == 0)
            {
                fs_util_trace_err_noinfo(RTF_INVALID_FILE_HANDLE);

                XRAISE(RTF_INVALID_FILE_HANDLE);
            }

            switch (f->usr_ptr_type)
            {
                case FS_TBL_USR_PTR_LISTCONTEXT:
                {
                    if (f->usr_ptr)
                    {
                        Attr =      ((fs_list_cntx_struct *)f->usr_ptr)->attr;
                        AttrMask =  ((fs_list_cntx_struct *)f->usr_ptr)->attr_mask | Attr;
                    }
                    break;
                }
                case FS_TBL_USR_PTR_FINDATTR:
                {
                    ptr = (BYTE *)&f->usr_ptr;

                    Attr = ptr[0];
                    AttrMask = ptr[1];

                    break;
                }
                default:
                {
                    ptr = (BYTE*) &f->LastCluster;

                    Attr = ptr[0];
                    AttrMask = ptr[1];

                    break;
                }
            }

            NamePattern = kal_dchar_strrchr(f->FullName, '\\')+2;
            Pos         = (void*) &f->Cluster;

            if ((Attr == 0xFF) && (AttrMask == 0xFF))
            {
                XRAISE(RTF_NO_MORE_FILES);
            }

            // if "*.*", convert it to "*"
            if(kal_dchar_strcmp(NamePattern, (char *)dchar_start_dot_star) == 0)
                NamePattern += 4;

            // reset open hint
            //if (OpenHint)
            //{
            //    OpenHint->Cluster = 0;
            //}

            if (FilePos)
            {
                FilePos->Cluster = 0;
                FilePosDone = KAL_FALSE;
            }

            /*
             * Allocate memory for LFN
             */
            if (MaxLength >= FS_MAX_FILE_NAME_LENGTH)
            {
                FindName = FileName;
                FindLength = MaxLength;
            }
            else
            {
                FindName = (kal_wchar *)get_ctrl_buffer(FS_MAX_FILE_NAME_LENGTH);

                ctrl_buff_used = KAL_TRUE;

                // no exception handler is required, get_ctrl_buffer will fatal if no memory is available.

                kal_mem_set(FindName, 0, FS_MAX_FILE_NAME_LENGTH);

                FindLength = FS_MAX_PATH;
            }

            while (1)
            {
                int Kind;
                const RTFDOSDirEntry * D = NextDir(f->Drive, Pos);

                if (D == NULL)
                {
                    XRAISE(RTF_NO_MORE_FILES);
                }

                Kind = EntryType(D);

                LastIsLFN--;

                fs_util_trace_info4(TRACE_GROUP_8 | TRACE_INFO, FS_TRC_RTF_NEXT_DIR, Pos->Cluster, Pos->Index, Kind, 0, NULL);

                if (Kind == NeverUsed)
                {
                    XRAISE(RTF_NO_MORE_FILES);
                }
                else if (Kind == Lfn)
                {
                    const LFNDirEntry * LD = (void*) D;

                    if (LD->Ord & 0x40)
                    {
                        char * Limit;
                        LFNIndex = LD->Ord & 0x3F;
                        CheckSum = LD->CheckSum;

                        // temporarily set LongPos to the 1st LFN entry
                        f->DirEntry.LongPos = *Pos; // required?

                        if (FilePosDone == KAL_FALSE)
                        {
                            FilePos->Cluster = Pos->Cluster;
                            FilePos->Index = Pos->Index;
                            FilePosDone = KAL_TRUE;
                        }

                        Limit = ((char *)FindName) + ((LFNIndex-1)*13*2 + 2*LFNCharCount(LD));

                        if(Limit > ( ((char *)FindName) + FindLength - 1))
                        {
                            LFNIndex = -1;
                        }
                        else
                        {
                            Limit[0] = '\0';
                            Limit[1] = '\0';
                        }
                    }

                    if ((LD->CheckSum != CheckSum) || (LFNIndex != (LD->Ord & 0x3F)) || (LFNIndex <= 0))
                    {
                        LFNIndex = -1;
                    }
                    else
                    {
                        CopyLFN((char *)FindName + --LFNIndex * 26, LD);
                    }

                    LastIsLFN = 2;  // LastIsLFN = 2: LFN is existed
                }
                else if ((Kind == InUse) && ((D->Attributes & AttrMask) == Attr))
                {
                    int j;

                    if (D->FileName[0] == 0x2E)  // '.'
                    {
                        if ((D->FileName[1] != 0x20) && (D->FileName[1] != 0x2E))  // ".X"
                        {
                            goto ContinueFindNextN_3;
                        }

                        for (j = 2; j <= 7; j++)
                        {
                            if (D->FileName[j] != 0x20)
                            {
                                goto ContinueFindNextN_3;  // "..XYZ" or ". XYZ"?
                            }
                        }

                        goto ContinueFindNextN_2;   // skip "."
                        /* dot, dot-dot */
                    }

ContinueFindNextN_3:
                    if (FileInfo)
                    {
                        *(RTFDOSDirEntry *)FileInfo = *D;
                        FileInfo->NTReserved = MT_ENUM_FIND_NONE;
                    }

                    if ((LFNIndex == 0) && (CheckSum == ShortNameCheckSum((BYTE*) D->FileName)))
                    {
                        if (PatternNum > 0)
                        {
                            if (D->Attributes & ArrayMask)
                            {
                                if (FileNamesMatch((WCHAR *)NamePattern, FindName)) // compare LFN
                                {
                                    // LFN is matched!
                                    goto FindNext_LFNCopy;
                                }

                                // LFN is not existed or LFN is existed but NOT matched to NamePattern, go compare SFN
                                goto ContinueFindNextN_1;
                            }

                            // ArrayMask is not set, compare PatternArray

                            for (i = 0; i < PatternNum; i++)
                            {
                                if (PatternArray[i].Pattern == NULL)
                                {
                                    fs_util_trace_err_noinfo(RTF_PARAM_ERROR);

                                    XRAISE(RTF_PARAM_ERROR);
                                }

                                if (FileNamesMatch((WCHAR *)PatternArray[i].Pattern, FindName))
                                {
                                    goto FindNext_LFNCopy;
                                }
                            }
                        }
                        else if (FileNamesMatch((WCHAR *)NamePattern, FindName))     // no Pattern Array assigned
                        {
FindNext_LFNCopy:
                            if (Flag != FS_FIND_LFN_TRUNC)  // FS_FIND_DEFAULT
                            {
                                // skip too-long file name if FS_FIND_LFN_TRUNC is NOT set

                                if (kal_wstrlen(FindName) >= MaxLength / 2)
                                {
                                    LastIsLFN = 3;  // LastISLFN = 3: LFN is matched but file name buffer is insufficient, return SFN

                                    goto ContinueFindNextN_1;   // return SFN instead
                                }
                                else
                                {
                                    if (FindName != FileName)
                                    {
                                        // copy LFN to FileName
                                        for(i = 0 ; i < (MaxLength / 2 - 1); i++)
                                        {
                                            if (FindName[i] == '\0')
                                                break;

                                            FileName[i] = FindName[i];
                                        }

                                        FileName[i] = 0x0000;
                                    }
                                    // else, FileName is eaxatly FindName, no copy is required.
                                }
                            }

                            /*
                             * For FS_FIND_LFN_TRUNC, we will
                             *
                             *  1. Keep LFN position to OpenHint.
                             *  2. Fill-in truncated LFN to FileName in SkipFindNextN section.
                             */

                            if (FileInfo)
                                FileInfo->NTReserved = MT_ENUM_FIND_LFN;

                            // fill open hint (for LFN)
                            //if (OpenHint)
                            //{
                            //    OpenHint->Cluster = f->DirEntry.LongPos.Cluster;
                            //    OpenHint->Index   = f->DirEntry.LongPos.Index;
                            //}

                            goto SkipFindNextN;
                        }
                    }
                    else  // LFN is not existed or invalid (checksum error or incompleted), set LastIsLFN = 0 to compare SFN below.
                    {
                        LastIsLFN = 0;
                    }

ContinueFindNextN_1:

                    if (LastIsLFN == 3)  // LFN matched, but MaxLength is not enough, return SFN (NOT required to match SFN!)
                    {
                        if ((MakeShortFileName(D, (char *)FileName, MaxLength) == RTF_NO_ERROR))
                        {
                            FileNameExtendToWCHAR((char *)FileName, FS_MAX_SFN_NATIVE_FILE_NAME_LENGTH_B);

                            if (FileInfo)
                            {
                                if (FileInfo->FileName[0] == 0x05)
                                    FileInfo->FileName[0] = 0xE5;

                                FileInfo->NTReserved = MT_ENUM_FIND_SFN;
                            }

                            NTReserved = D->NTReserved;

                            if (FilePos)    // enforce update FilePos to SFN entry
                            {
                                FilePos->Cluster = Pos->Cluster;
                                FilePos->Index = Pos->Index;
                                FilePosDone = KAL_TRUE;
                            }

                            // fill open hint (for SFN)
                            //if (OpenHint)
                            //{
                            //    OpenHint->Cluster = Pos->Cluster;
                            //    OpenHint->Index   = Pos->Index;
                            //}

                            break;
                        }

                        // MakeShortFileName failed, continue traverse
                        LastIsLFN = 0;

                        goto ContinueFindNextN_2;

                    }
                    /*
                     * Below part is only for file name WITHOUT LFN.
                     * NOTE. LastIsLFN == 1 means this is a SFN entry with LFN entries ahead.
                     */
                    else if ((LastIsLFN != 1) && (MakeShortFileName(D, (char *)FileName, MaxLength) == RTF_NO_ERROR))
                    {
                        UINT i;

                        FileNameExtendToWCHAR((char *)FileName, FS_MAX_SFN_NATIVE_FILE_NAME_LENGTH_B);

                        if (PatternNum > 0)
                        {
                            if (D->Attributes & ArrayMask)
                            {
                                if (FileNamesMatch((WCHAR *)NamePattern, FileName))
                                {
                                    if (FileInfo)
                                    {
                                        if (FileInfo->FileName[0] == 0x05)
                                            FileInfo->FileName[0] = 0xE5;

                                        FileInfo->NTReserved = MT_ENUM_FIND_SFN;
                                    }

                                    NTReserved = D->NTReserved;

                                    if (FilePos)    // enforce update FilePos to SFN entry
                                    {
                                        FilePos->Cluster = Pos->Cluster;
                                        FilePos->Index = Pos->Index;
                                        FilePosDone = KAL_TRUE;
                                    }

                                    // fill open hint (for SFN)
                                    //if (OpenHint)
                                    //{
                                    //    OpenHint->Cluster = Pos->Cluster;
                                    //    OpenHint->Index   = Pos->Index;
                                    //}

                                    break;  // go to SkipFindNextN
                                }

                                FilePosDone = KAL_FALSE;

                                goto ContinueFindNextN_2;   // give up this file and goto the next
                            }

                            for (i = 0; i < PatternNum; i++)
                            {
                                if (PatternArray[i].Pattern == NULL)
                                {
                                    fs_util_trace_err_noinfo(RTF_PARAM_ERROR);

                                    XRAISE(RTF_PARAM_ERROR);
                                }

                                if (FileNamesMatch((WCHAR *)PatternArray[i].Pattern, FileName))
                                {
                                    if (FileInfo)
                                    {
                                        if (FileInfo->FileName[0] == 0x05)
                                            FileInfo->FileName[0] = 0xE5;

                                        FileInfo->NTReserved = MT_ENUM_FIND_SFN;
                                    }

                                    NTReserved = D->NTReserved;

                                    if (FilePos)    // enforce update FilePos to SFN entry
                                    {
                                        FilePos->Cluster = Pos->Cluster;
                                        FilePos->Index = Pos->Index;
                                        FilePosDone = KAL_TRUE;
                                    }

                                    // fill open hint (for SFN)
                                    //if (OpenHint)
                                    //{
                                    //    OpenHint->Cluster = Pos->Cluster;
                                    //    OpenHint->Index   = Pos->Index;
                                    //}

                                    goto SkipFindNextN;
                                }
                            }
                        }
                        else if (FileNamesMatch((WCHAR *)NamePattern, FileName))    // no Pattern Array assigned
                        {
                            if (FileInfo)
                            {
                                if (FileInfo->FileName[0] == 0x05)
                                    FileInfo->FileName[0] = 0xE5;

                                FileInfo->NTReserved = MT_ENUM_FIND_SFN;
                            }

                            NTReserved = D->NTReserved;

                            if (FilePos)    // enforce update FilePos to SFN entry
                            {
                                FilePos->Cluster = Pos->Cluster;
                                FilePos->Index = Pos->Index;
                                FilePosDone = KAL_TRUE;
                            }

                            // fill open hint (for SFN)
                            //if (OpenHint)
                            //{
                            //    OpenHint->Cluster = Pos->Cluster;
                            //    OpenHint->Index   = Pos->Index;
                            //}

                            break;
                        }
                    }
                    if (FilePos)
                        FilePosDone = KAL_FALSE;
                }
                else
                {
                    if (FilePos)
                        FilePosDone = KAL_FALSE;
                }

ContinueFindNextN_2:

                if (Kind != Lfn)
                {
                    LFNIndex = -1;

                    LastIsLFN = 0;

                    f->DirEntry.LongPos.Cluster = 0;    // reset LongPos

                    if (FilePos)
                        FilePosDone = KAL_FALSE;

                    if (FindName)
                        FindName[0] = 0;    // reset LFN
                }
            }

SkipFindNextN:

            if (MaxLength)
            {
                if (Flag == FS_FIND_LFN_TRUNC)
                {
                    if (FindName != FileName)
                    {
                        for (i = 0 ; i < (MaxLength / 2 - 1); i++)
                        {
                            if (FindName[i] == '\0')
                                break;

                            FileName[i] = FindName[i];
                        }

                        FileName[i] = 0x0000;
                    }
                }

                MTCheckFileNameCase(FileName, MaxLength, NTReserved);
            }

            // fill open hint (general parts)
            //if (OpenHint)
            //{
            //    OpenHint->Drive = (UINT)f->Drive;
            //    OpenHint->SerialNumber = f->Drive->SerialNumber;
            //    OpenHint->Stamp = OpenHintStamp;
            //}

             break;
        }
        default:
            result = XVALUE;
            break;

        case XFINALLY:
        {
            if (ctrl_buff_used == KAL_TRUE)
            {
                free_ctrl_buffer(FindName);
            }

            if (f != NULL)
            {
                UnlockDevice(f->Dev);
            }

            break;
        }
    }
    XEND_API

    //if (OpenHint)
    //    fs_util_trace_info4(TRACE_GROUP_8 | TRACE_INFO | MT_TRACE_INFO_WSTR, FS_TRC_RTF_NEXT_E_HINT, FileInfo->Attributes, OpenHint->Cluster, OpenHint->Index, NULL, (void*)FileName);
    //else
    //    fs_util_trace_info1(TRACE_GROUP_8 | TRACE_INFO | MT_TRACE_INFO_WSTR, FS_TRC_RTF_NEXT_E, FileInfo->Attributes, (void*)FileName);

    return result;
}



#if !defined(__FS_PROPRIETARY_SET__) || defined(__FS_FMT_SERVICE__)

/*-----------------------------------*/
kal_int32 RTFAPI RTFFindFirst(fs_list_param_struct *param,
                              FS_DOSDirEntry * FileInfo, WCHAR * FileName, UINT MaxLength,
                              UINT Flag, FS_FileLocationHint *Pos, kal_uint32 caller_address)
{
    RTFile *volatile f = NULL;
    FS_HANDLE volatile handle;
    //FS_FileLocationHint Pos;
    kal_bool volatile hit = KAL_FALSE;

    fs_util_trace_info4(TRACE_GROUP_8 | TRACE_FUNC, FS_TRC_RTF_FIRST_S, param->name_pattern_count, MaxLength, param->index, Flag, NULL);

    XTRY
    {
        case XCODE:
        {
            f = ParseFileName((char *)param->path);

            if (f->SpecialKind != NormalFile)
            {
                fs_util_trace_err_noinfo(RTF_INVALID_FILENAME);

                XRAISE(RTF_INVALID_FILENAME);
            }

            f->Flags = RTF_OPEN_DIR | RTF_READ_ONLY;

            if (param->buff && param->buff_size)
            {
                f->usr_ptr = param->buff;
                f->usr_ptr_type = FS_TBL_USR_PTR_LISTCONTEXT;
            }
            else
            {
                BYTE *ptr = (BYTE *)&f->usr_ptr;

                ptr[0] = param->attr;
                ptr[1] = param->attr | param->attr_mask;

                f->usr_ptr_type = FS_TBL_USR_PTR_FINDATTR;
            }


            if(SearchFile(f, SEARCH_PARENT | SEARCH_RELEASE_LOCK, (char *)param->path, NULL))
            {
                if(f->DirEntry.DirCluster == 0)
                {
                    /* the target entry is in root dir, return immediately */
                    MakePseudoRootDirEntry(f->Drive, &f->DirEntry);
                    if (FileInfo)
                    {
                        * (RTFDOSDirEntry *)FileInfo = f->DirEntry.Dir;
                    }
                    setASCII(FileName, 0, '\\');
                    setASCII(FileName, 1, 0);
                    hit = KAL_TRUE;
                }
                else
                {
                    SET_FIRST_FILE_CLUSTER(f->DirEntry.Dir, f->DirEntry.DirCluster);
                }
            }
        #ifdef __FS_OPEN_HINT__
            else
            {
               /*
                * f->DirEntry.Dir now is the parent of target folder/file.
                * Copy its start cluster to f->DirEntry.DirCluster to let
                * MTHintNew() keep DirCluster with new location.
                *
                * Note. RTFFindNextEx will not touch f->DirEntry.DirCluster
                */
               f->DirEntry.DirCluster = FIRST_FILE_CLUSTER(f->DirEntry.Dir);
            }
        #endif /* __FS_OPEN_HINT__ */

            InitFilePointer(f);

            Pos  = (void*) &f->Cluster;
            Pos->Index--;

            handle = MakeNewFileHandle(f);

            break;
        }

        default:
            handle = XVALUE;
            break;

        case XFINALLY:
        {
            if(f)
            {
                if (handle < RTF_NO_ERROR)
                {
                    FreeFTSlotAndDevice(f);
                }
                else
                {
                    f->OwnerLR = caller_address;
                    UnlockDevice(f->Dev);
                }
            }
            break;
        }
    }
    XEND_API

    fs_util_check_stack();

    if (handle > RTF_NO_ERROR && !hit)
    {

        kal_int32 reval = FS_NO_ERROR;
        kal_uint32 count = 0;

        while ((reval = fs_srv_findnext(handle,
                                      param->name_pattern, param->name_pattern_count,
                                      param->attr_pattern,
                                      FileInfo, FileName, MaxLength,
                                      Flag, Pos)) >= FS_NO_ERROR)
        {

            if (count++ == param->index)
                return handle;

        }

        if (reval < FS_NO_ERROR)
        {
            RTFFindClose(handle);
            handle = reval;
        }

    }
    else
    {
        if (!hit)
        {
            fs_util_trace_err_noinfo(handle);
        }

    }

    return handle;
}


/*-----------------------------------*/
int RTFAPI RTFFindNext(FS_HANDLE handle,
                       FS_Pattern_Struct * PatternArray, UINT PatternNum,
                       BYTE ArrayMask,
                       FS_DOSDirEntry * FileInfo, WCHAR * FileName, UINT MaxLength,
                       UINT Flag)
{
    BYTE CheckSum = 0;
    int LFNIndex = -1;
    BYTE volatile AttrMask = 0;
    BYTE volatile Attr     = 0;
    RTFile * volatile f = NULL;
    const char * NamePattern;
    RTFDirLocation * Pos;
    UINT i;
    WCHAR * volatile FindName = NULL;
    UINT FindLength = 0;
    int LastIsLFN = 0;
    BYTE NTReserved = 0;
    FS_FileOpenHint* volatile OpenHint = NULL;
    kal_int32 volatile result = FS_NO_ERROR;
//    BYTE * ptr;

    fs_util_trace_info0(TRACE_GROUP_8 | TRACE_FUNC, FS_TRC_RTF_NEXT, NULL);

    XTRY
    {
        case XCODE:
        {
            f = ParseFileHandle(handle);

            // get open hint
            if (FileInfo)
                OpenHint = FS_GetOpenHintByDOSDirEntry(FileInfo);

            if(f->Valid == FS_FH_ABORTED)
            {
                fs_util_trace_err_noinfo(MT_ABORTED_ERROR);

                XRAISE(MT_ABORTED_ERROR);
            }

            if(f->SpecialKind != NormalFile)
            {
                fs_util_trace_err_noinfo(RTF_INVALID_FILE_HANDLE);

                XRAISE(RTF_INVALID_FILE_HANDLE);
            }

            if((f->DirEntry.Dir.Attributes & RTF_ATTR_DIR) == 0)
            {
                fs_util_trace_err_noinfo(RTF_INVALID_FILE_HANDLE);

                XRAISE(RTF_INVALID_FILE_HANDLE);
            }

            switch (f->usr_ptr_type)
            {
                case FS_TBL_USR_PTR_LISTCONTEXT:
                {
                    if (f->usr_ptr)
                    {
                        Attr =      ((fs_list_cntx_struct *)f->usr_ptr)->attr;
                        AttrMask =  ((fs_list_cntx_struct *)f->usr_ptr)->attr_mask | Attr;
                    }
                    break;
                }
                case FS_TBL_USR_PTR_FINDATTR:
                {
                    BYTE *ptr = (BYTE *)&f->usr_ptr;

                    Attr = ptr[0];
                    AttrMask = ptr[1];

                    break;
                }
                default:
                {
                    // BYTE *ptr = (BYTE *)&f->usr_ptr;
                }

            }


            NamePattern = kal_dchar_strrchr(f->FullName, '\\')+2;
            Pos         = (void*) &f->Cluster;

            if((Attr == 0xFF) && (AttrMask == 0xFF))
            {
                fs_assert_local(0);
            }

            // if "*.*", convert it to "*"
            if(kal_dchar_strcmp(NamePattern, (char *)dchar_start_dot_star) == 0)
                NamePattern += 4;

            // reset open hint
            if (OpenHint)
                OpenHint->Cluster = 0;

            while (1)
            {
                int Kind;
                const RTFDOSDirEntry * D = NextDir(f->Drive, Pos);

                if (D == NULL)
                {
                    XRAISE(RTF_NO_MORE_FILES);
                }

                Kind = EntryType(D);

                LastIsLFN--;

                fs_util_trace_info4(TRACE_GROUP_8 | TRACE_INFO, FS_TRC_RTF_NEXT_DIR, Pos->Cluster, Pos->Index, Kind, 0, NULL);

                if (Kind == NeverUsed)
                {
                    XRAISE(RTF_NO_MORE_FILES);
                }
                else if (Kind == Lfn)
                {
                    const LFNDirEntry * LD = (void*) D;

                    /*
                     * Allocate memory for LFN
                     * NOTE: Only for file with LFN! File without LFN entry should be properly handled NULL FindName case below!
                     */
                    if (FindName == NULL)
                    {
                        FindName = (kal_wchar *)get_ctrl_buffer(FS_MAX_PATH);

                        if(FindName == NULL)
                        {
                            fs_util_trace_err_noinfo(MT_FAIL_GET_MEM);

                            XRAISE(MT_FAIL_GET_MEM);
                        }

                        kal_mem_set(FindName, 0, FS_MAX_PATH);
                        FindLength = FS_MAX_PATH;
                    }

                    if (LD->Ord & 0x40)
                    {
                        char * Limit;
                        LFNIndex = LD->Ord & 0x3F;
                        CheckSum = LD->CheckSum;

                        // temporarily set LongPos to the 1st LFN entry
                        f->DirEntry.LongPos = *Pos;

                        Limit = ((char *)FindName) + ((LFNIndex-1)*13*2 + 2*LFNCharCount(LD));

                        if(Limit > ( ((char *)FindName) + FindLength - 1))
                        {
                            LFNIndex = -1;
                        }
                        else
                        {
                            Limit[0] = '\0';
                            Limit[1] = '\0';
                        }
                    }

                    if ((LD->CheckSum != CheckSum) || (LFNIndex != (LD->Ord & 0x3F)) || (LFNIndex <= 0))
                    {
                        LFNIndex = -1;
                    }
                    else
                    {
                        CopyLFN((char *)FindName + --LFNIndex * 26, LD);
                    }

                    LastIsLFN = 2;  // LastIsLFN = 2: LFN is existed
                }
                else if ((Kind == InUse) && ((D->Attributes & AttrMask) == Attr))
                {
                    int j;

                    if (D->FileName[0] == 0x2E)  // '.'
                    {
                        if ((D->FileName[1] != 0x20) && (D->FileName[1] != 0x2E))  // ".X"
                        {
                            goto ContinueFindNextN_3;
                        }

                        for (j = 2; j <= 7; j++)
                        {
                            if (D->FileName[j] != 0x20)
                            {
                                goto ContinueFindNextN_3;  // "..XYZ" or ". XYZ"?
                            }
                        }

                        goto ContinueFindNextN_2;   // skip "."
                    /* dot, dot-dot */
                    }

ContinueFindNextN_3:
                    if (FileInfo)
                    {
                        *(RTFDOSDirEntry *)FileInfo = *D;
                        FileInfo->NTReserved = MT_ENUM_FIND_NONE;
                    }

                    if ((LFNIndex == 0) && (NULL != FindName) && (CheckSum == ShortNameCheckSum((BYTE*) D->FileName)))
                    {
                        if (PatternNum > 0)
                        {
                            if (D->Attributes & ArrayMask)
                            {
                                if (FileNamesMatch((WCHAR *)NamePattern, FindName)) // compare LFN
                                {
                                    if (Flag != FS_FIND_LFN_TRUNC)  // FS_FIND_DEFAULT
                                    {
                                        // skip too-long file name if FS_FIND_LFN_TRUNC is NOT set

                                        if (kal_wstrlen(FindName) >= MaxLength / 2)
                                        {
                                            LastIsLFN = 3;  // LastISLFN = 3: LFN is matched but file name buffer is insufficient, return SFN

                                            goto ContinueFindNextN_1;   // return SFN instead
                                        }
                                        else
                                        {
                                            // copy LFN to FileName

                                            for(i = 0 ; i < (MaxLength / 2 - 1); i++)
                                            {
                                                if (FindName[i] == '\0')
                                                    break;

                                                FileName[i] = FindName[i];
                                            }

                                            FileName[i] = 0x0000;
                                        }
                                    }

                                    /*
                                     * For FS_FIND_LFN_TRUNC, we will
                                     *
                                     *  1. Keep LFN position to OpenHint.
                                     *  2. Fill-in truncated LFN to FileName in SkipFindNextN section.
                                     */

                                    if (FileInfo)
                                        FileInfo->NTReserved = MT_ENUM_FIND_LFN;

                                    // fill open hint (for LFN)
                                    if (OpenHint)
                                    {
                                        OpenHint->Cluster = f->DirEntry.LongPos.Cluster;
                                        OpenHint->Index   = f->DirEntry.LongPos.Index;
                                    }

                                    goto SkipFindNextN;
                                }

                                // LFN is not existed or LFN is existed but NOT matched to NamePattern, go compare SFN
                                goto ContinueFindNextN_1;
                            }

                            // ArrayMask is not set, compare PatternArray

                            for (i = 0; i < PatternNum; i++)
                            {
                                if (PatternArray[i].Pattern == NULL)
                                {
                                    fs_util_trace_err_noinfo(RTF_PARAM_ERROR);

                                    XRAISE(RTF_PARAM_ERROR);
                                }

                                if (FileNamesMatch((WCHAR *)PatternArray[i].Pattern, FindName))
                                {
                                    if (Flag != FS_FIND_LFN_TRUNC)  // FS_FIND_DEFAULT
                                    {
                                        // skip too-long file name if FS_FIND_LFN_TRUNC is NOT set

                                        if (kal_wstrlen(FindName) >= MaxLength / 2)
                                        {
                                            LastIsLFN = 3;  // LastISLFN = 3: LFN is matched but file name buffer is insufficient, return SFN

                                            goto ContinueFindNextN_1;   // return SFN instead
                                        }
                                        else
                                        {
                                            // copy LFN to FileName

                                            for(i = 0 ; i < (MaxLength/2 - 1); i++)
                                            {
                                                if (FindName[i] == '\0')
                                                    break;

                                                FileName[i] = FindName[i];
                                            }

                                            FileName[i] = 0x0000;
                                        }
                                    }

                                    /*
                                     * For FS_FIND_LFN_TRUNC, we will
                                     *
                                     *  1. Keep LFN position to OpenHint.
                                     *  2. Fill-in truncated LFN to FileName in SkipFindNextN section.
                                     */

                                    if (FileInfo)
                                        FileInfo->NTReserved = MT_ENUM_FIND_LFN;

                                    // fill open hint (for LFN)
                                    if (OpenHint)
                                    {
                                        OpenHint->Cluster = f->DirEntry.LongPos.Cluster;
                                        OpenHint->Index   = f->DirEntry.LongPos.Index;
                                    }

                                    goto SkipFindNextN;
                                }
                            }
                        }
                        else if (FileNamesMatch((WCHAR *)NamePattern, FindName))     // no Pattern Array assigned
                        {
                            if (Flag != FS_FIND_LFN_TRUNC)  // FS_FIND_DEFAULT
                            {
                                if (kal_wstrlen(FindName) >= MaxLength / 2)
                                {
                                    LastIsLFN = 3;

                                    goto ContinueFindNextN_1;
                                }
                                else
                                {
                                    for(i = 0 ; i < (MaxLength / 2 - 1); i++)
                                    {
                                        if(FindName[i] == '\0')
                                            break;

                                        FileName[i] = FindName[i];
                                    }

                                    FileName[i] = 0x0000;
                                }
                            }

                            if (FileInfo)
                                FileInfo->NTReserved = MT_ENUM_FIND_LFN;

                            // fill open hint (for LFN)
                            if (OpenHint)
                            {
                                OpenHint->Cluster = f->DirEntry.LongPos.Cluster;
                                OpenHint->Index   = f->DirEntry.LongPos.Index;
                            }

                            goto SkipFindNextN;
                        }
                    }
                    else  // LFN is not existed or invalid (checksum error or incompleted), set LastIsLFN = 0 to compare SFN below.
                    {
                        LastIsLFN = 0;
                    }

ContinueFindNextN_1:

                    if (LastIsLFN == 3)  // LFN matched, but MaxLength is not enough, return SFN (NOT required to match SFN!)
                    {
                        if ((MakeShortFileName(D, (char *)FileName, MaxLength) == RTF_NO_ERROR))
                        {
                            FileNameExtendToWCHAR((char *)FileName, FS_MAX_SFN_NATIVE_FILE_NAME_LENGTH_B);

                            if (FileInfo)
                            {
                                if (FileInfo->FileName[0] == 0x05)
                                    FileInfo->FileName[0] = 0xE5;

                                FileInfo->NTReserved = MT_ENUM_FIND_SFN;
                            }

                            NTReserved = D->NTReserved;

                            // fill open hint (for SFN)
                            if (OpenHint)
                            {
                                OpenHint->Cluster = Pos->Cluster;
                                OpenHint->Index   = Pos->Index;
                            }

                            break;
                        }

                        // MakeShortFileName failed, continue traverse
                        LastIsLFN = 0;

                        goto ContinueFindNextN_2;

                    }
                    /*
                     * [Policy] If LFN exists but match fail, don't have to match SFN
                     *
                     * Below part is only for file name WITHOUT LFN.
                     */
                    else if ((LastIsLFN != 1) && (MakeShortFileName(D, (char *)FileName, MaxLength) == RTF_NO_ERROR))
                    {
                        UINT i;

                        FileNameExtendToWCHAR((char *)FileName, FS_MAX_SFN_NATIVE_FILE_NAME_LENGTH_B);

                        if (PatternNum > 0)
                        {
                            if (D->Attributes & ArrayMask)
                            {
                                if (FileNamesMatch((WCHAR *)NamePattern, FileName))
                                {
                                    if (FileInfo)
                                    {
                                        if (FileInfo->FileName[0] == 0x05)
                                            FileInfo->FileName[0] = 0xE5;

                                        FileInfo->NTReserved = MT_ENUM_FIND_SFN;
                                    }

                                    NTReserved = D->NTReserved;

                                    // fill open hint (for SFN)
                                    if (OpenHint)
                                    {
                                        OpenHint->Cluster = Pos->Cluster;
                                        OpenHint->Index   = Pos->Index;
                                    }

                                    break;  // go to SkipFindNextN
                                }

                                goto ContinueFindNextN_2;   // give up this file and goto the next
                            }

                            for (i = 0; i < PatternNum; i++)
                            {
                                if (PatternArray[i].Pattern == NULL)
                                {
                                    fs_util_trace_err_noinfo(RTF_PARAM_ERROR);

                                    XRAISE(RTF_PARAM_ERROR);
                                }

                                if (FileNamesMatch((WCHAR *)PatternArray[i].Pattern, FileName))
                                {
                                    if (FileInfo)
                                    {
                                        if (FileInfo->FileName[0] == 0x05)
                                            FileInfo->FileName[0] = 0xE5;

                                        FileInfo->NTReserved = MT_ENUM_FIND_SFN;
                                    }

                                    NTReserved = D->NTReserved;

                                    // fill open hint (for SFN)
                                    if (OpenHint)
                                    {
                                        OpenHint->Cluster = Pos->Cluster;
                                        OpenHint->Index   = Pos->Index;
                                    }

                                    goto SkipFindNextN;
                                }
                            }
                        }
                        else if (FileNamesMatch((WCHAR *)NamePattern, FileName))    // no Pattern Array assigned
                        {
                            if (FileInfo)
                            {
                                if (FileInfo->FileName[0] == 0x05)
                                    FileInfo->FileName[0] = 0xE5;

                                FileInfo->NTReserved = MT_ENUM_FIND_SFN;
                            }

                            NTReserved = D->NTReserved;

                            // fill open hint (for SFN)
                            if (OpenHint)
                            {
                                OpenHint->Cluster = Pos->Cluster;
                                OpenHint->Index   = Pos->Index;
                            }

                            break;
                        }
                    }
                }

ContinueFindNextN_2:

                if (Kind != Lfn)
                {
                    LFNIndex = -1;

                    LastIsLFN = 0;

                    f->DirEntry.LongPos.Cluster = 0;    // reset LongPos

                    if (FindName)
                        FindName[0] = 0;    // reset LFN
                }
            }

SkipFindNextN:

            if (MaxLength)
            {
                if (Flag == FS_FIND_LFN_TRUNC)
                {
                    if (FindName)
                    {
                        for (i = 0 ; i < (MaxLength / 2 - 1); i++)
                        {
                            if (FindName[i] == '\0')
                                break;

                            FileName[i] = FindName[i];
                        }

                        FileName[i] = 0x0000;
                    }
                }

                MTCheckFileNameCase(FileName, MaxLength, NTReserved);
            }

            // fill open hint (general parts)
            if (OpenHint)
            {
                OpenHint->Drive = (UINT)f->Drive;
                OpenHint->SerialNumber = f->Drive->SerialNumber;
                OpenHint->Stamp = OpenHintStamp;
            }

             break;
        }
        default:
            result = XVALUE;
            break;

        case XFINALLY:
        {

            if(FindName != NULL)
            {
                free_ctrl_buffer(FindName);
            }
            if(f != NULL)
            {
                UnlockDevice(f->Dev);
            }

            break;
        }
    }
    XEND_API

    if (OpenHint)
        fs_util_trace_info4(TRACE_GROUP_8 | TRACE_INFO | MT_TRACE_INFO_WSTR, FS_TRC_RTF_NEXT_E_HINT, FileInfo->Attributes, OpenHint->Cluster, OpenHint->Index, NULL, (void*)FileName);
    else
        fs_util_trace_info1(TRACE_GROUP_8 | TRACE_INFO | MT_TRACE_INFO_WSTR, FS_TRC_RTF_NEXT_E, FileInfo->Attributes, (void*)FileName);

    return result;
}


int RTFGetListEntry(FS_HANDLE handle, kal_wchar *path,
                    kal_wchar *FileName, kal_uint32 MaxLength, FS_DOSDirEntry *FileInfo,
                    kal_int32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    RTFile *volatile f = NULL;
    kal_int32 volatile result = FS_NO_ERROR;
    fs_list_cntx_struct *volatile context = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    XTRY
        case XCODE:
        {
            f = ParseFileHandle(handle);

            break;
        }
        default:
        {
            result = XVALUE;
            break;
        }
        case XFINALLY:
        {

            if (f)
            {
                UnlockDevice(f->Dev);
            }

        break;
        }
    XEND_API

    if (result >= FS_NO_ERROR)
    {
        if (f->usr_ptr_type == FS_TBL_USR_PTR_LISTCONTEXT && f->usr_ptr)
        {
            context = f->usr_ptr;

            if (index >= context->used)
            {
                return FS_PARAM_ERROR;
            }

            result = fs_srv_get_name_by_pos(f, NULL, (RTFDOSDirEntry*)FileInfo, FileName, MaxLength, (RTFDirLocation*)&context->pos_buf[index], FS_FIND_DEFAULT);

            // Fill External Open Hint (hidden in FileName)
            if (FileInfo)   {
                FileInfo->Index=context->pos_buf[index].Index;
                FileInfo->Cluster=context->pos_buf[index].Cluster;
                FileInfo->Drive=(UINT)f->Drive;
                FileInfo->SerialNumber = f->Drive->SerialNumber;
                FileInfo->Stamp = OpenHintStamp;
            }

    #ifdef __FS_OPEN_HINT__
            if (path && result >= FS_NO_ERROR)
            {
                FS_FileLocationHint *hint = (FS_FileLocationHint *)MTHintGet(path, MT_HINT_ACTION_FORCE_NEW);

                if (hint)
                    MTHintNewManual(MTHintGetIndex(hint), path, FileName,
                        (RTFDirLocation *)&context->pos_buf[index], (UINT) f->DirEntry.DirCluster);
            }
    #endif
        }
        else
        {
            fs_assert_local(0);
        }
    }

    if (result < FS_NO_ERROR)
        fs_util_trace_err_noinfo(result);

    return result;
}


#endif /* !__FS_PROPRIETARY_SET__ || __FS_FMT_SERVICE__ */

/*-----------------------------------*/
int RTFAPI RTFGetDiskInfoEx(const WCHAR * FileName, RTFDiskInfo * DiskInfo, int Flags)
{
   RTFile * volatile f = NULL;
   int volatile _Flags;
   RTFDrive * Drive;
   int PrevCardBusyCheck;

   if (FileName == NULL) return RTF_PARAM_ERROR;

   _Flags = Flags & (RTF_DI_BASIC_INFO | RTF_DI_FREE_SPACE | RTF_DI_FAT_STATISTICS | RTF_DI_VOLUME_LABEL | RTF_DI_OPT_READ_PERMITTED);

   XTRY
      case XCODE:
         f = ParseFileName((char *)FileName);
         Drive = f->Drive;
         if (Drive == NULL)
         {
            fs_util_trace_err_noinfo(RTF_INVALID_FILENAME);

            XRAISE(RTF_INVALID_FILENAME);
         }

         if (Drive->MountState < HasFileSystem)
         {
            fs_util_trace_err_noinfo(RTF_INVALID_FILE_SYSTEM);

            XRAISE(RTF_INVALID_FILE_SYSTEM);
         }

         kal_mem_set(DiskInfo, 0, sizeof(RTFDiskInfo));

         /* Add for memory card write protection, Karen Hsu, 2004/04/14, MOD START */
         if(Drive->Dev->DeviceFlags & MT_DEVICE_WRITE_PROTECT)
            DiskInfo->WriteProtect = 1;
         /* Add for memory card write protection, Karen Hsu, 2004/04/14, MOD END */

         if (_Flags & RTF_DI_BASIC_INFO)
         {
            DiskInfo->Label[0] = '\0';
            DiskInfo->DriveLetter = MT_BASE_DRIVE_LETTER + (Drive - gFS_Data.DriveTable);
            DiskInfo->Reserved[0] = '\0';
            DiskInfo->FirstPhysicalSector = Drive->FirstSector;
            DiskInfo->SerialNumber = Drive->SerialNumber;
            DiskInfo->FATType = Drive->FATType;
            DiskInfo->FATCount = Drive->FATCount;
            DiskInfo->MaxDirEntries = Drive->RootDirEntries;
            DiskInfo->BytesPerSector = Drive->Dev->DevData.SectorSize;
            DiskInfo->SectorsPerCluster = Drive->SectorsPerCluster;
            DiskInfo->TotalClusters = Drive->Clusters - 2;
         }

         if (_Flags & RTF_DI_FREE_SPACE)
         {
            if (Drive->FreeClusterCount == RTF_INVALID_CLUSTER)
            /* Adopt BatchCountFreeClusters for faster boot up on large size disk, WCP_SW , 2006/02/08, MOD START */
            {
               // _Flags |= RTF_DI_FAT_STATISTICS;

#ifndef FMT_NOT_PRESENT
               // Only FMT task is allowed to count free clusters
               if ((kal_get_current_task_index() != remap_task_index(INDX_FMT)) &&
                   (kal_get_current_thread_ID() != gFS_ExportOwnerTaskID))  {


                   kal_int32 drive_letter;
                   kal_int32 result;

                   drive_letter = MT_BASE_DRIVE_LETTER + (Drive - gFS_Data.DriveTable);
                   result = FS_GetDevStatus(drive_letter, FS_DEVICE_PRESENCE_ENUM);
                   if (result < 0) XRAISE(result);
                   result = FS_GetDevStatus(drive_letter, FS_EXPORT_STATE_ENUM);
                   if (result < 0) XRAISE(result);
                   result = FS_GetDevStatus(drive_letter, FS_MOUNT_STATE_ENUM);
                   if (result < 0) XRAISE(result);
                   XRAISE(FS_DEVICE_BUSY);  // Only FMT task allowed to calculate the free space
               }
#endif

               if (_Flags & RTF_DI_OPT_READ_PERMITTED)
               {
                   Drive->Dev->DeviceFlags |= RTF_DEVICE_BUSY_READ_ONLY;
               }

               PrevCardBusyCheck = CardBusyCheck;
               CardBusyCheck = 1;

               BatchCountFreeClusters(Drive);

               CardBusyCheck = PrevCardBusyCheck;

               if (_Flags & RTF_DI_OPT_READ_PERMITTED)
               {
                   Drive->Dev->DeviceFlags &= ~RTF_DEVICE_BUSY_READ_ONLY;
               }

               DiskInfo->FreeClusters = Drive->FreeClusterCount;
            }
            /* Adopt BatchCountFreeClusters for faster boot up on large size disk, WCP_SW , 2006/02/08, MOD END */
            else
               DiskInfo->FreeClusters = Drive->FreeClusterCount;

            /* 2 member filled for usage convenience, WCP_SW , 2006/08/24, ADD START */
            DiskInfo->BytesPerSector = Drive->Dev->DevData.SectorSize;
            DiskInfo->SectorsPerCluster = Drive->SectorsPerCluster;
            /* 2 member filled for usage convenience, WCP_SW , 2006/08/24, ADD END */
         }

         #if 0 // [SLim] FAT STATISTICS feature is disabled due to no user
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

         break;

      default:
         break;

      case XFINALLY:
         if (f) FreeFTSlotAndDevice(f);
   XEND_API

   // get the volume label

   if (_Flags & RTF_DI_VOLUME_LABEL)
   {
      RTFHANDLE h;
      WCHAR Label[]={0x58,0x3a,0x5c,0x2a,0};
      RTFDOSDirEntry D;
      Label[0] = (WCHAR)DiskInfo->DriveLetter;
      h = RTFFindFirstEx(Label, RTF_ATTR_VOLUME, RTF_ATTR_DIR | RTF_ATTR_VOLUME, &D, (WCHAR *)DiskInfo->Label, sizeof(DiskInfo->Label), NULL, 0);
      if (h >= RTF_NO_ERROR)
         RTFClose(h);
      else
         DiskInfo->Label[0] = '\0';
   }

   return _Flags;
}

/*-----------------------------------*/
int RTFAPI RTFGetDiskInfo(const WCHAR * FileName, RTFDiskInfo * DiskInfo)
{
   int Result = RTFGetDiskInfoEx(FileName, DiskInfo, RTF_DI_BASIC_INFO | RTF_DI_FREE_SPACE | RTF_DI_FAT_STATISTICS);
   return Result < RTF_NO_ERROR ? Result : RTF_NO_ERROR;
}

/*-----------------------------------*/
int RTFAPI RTFGetPartitionInfo(const WCHAR * DriveName, RTFPartitionInfo * PartitionInfo, kal_uint32 Option)
{
    RTFile * volatile f = NULL;

    XTRY
        case XCODE:

            if (Option == FS_PARTITION_INFO_BASIC)
            {
                kal_mem_set(PartitionInfo, 0, sizeof(RTFPartitionRecord));  // to avoid memory corruption because FS_GetPartitionInfo uses FS_PartitionRecord as parameter.
            }
            else
            {
                kal_mem_set(PartitionInfo, 0, sizeof(RTFPartitionInfo));
            }


            /* try to open a Drive file */
            f = ParseFileName((char *)DriveName);

            /* floppy can't have Drive file */
            #if !defined(__FS_SLIM_PHYSICAL_DRIVE__)
            if (f->SpecialKind == PhysicalDisk)
            {
                PartitionInfo->Partition = f->Dev->DevData.Geometry;
            }
            else
            #endif // !__FS_SLIM_PHYSICAL_DRIVE__
            {
                PartitionInfo->Partition = f->Drive->Geometry;
            }

            if (Option & FS_PARTITION_INFO_ADVANCED)
            {
                PartitionInfo->MediaDescriptor   = f->Dev->DevData.MediaDescriptor;
                PartitionInfo->BytesPerSector    = f->Dev->DevData.SectorSize;
                PartitionInfo->PhysicalDiskIndex = f->Dev->DevData.PhysicalDiskIndex;
                PartitionInfo->DeviceListIndex   = f->Dev - gFS_DeviceList;
            }

            if (f->Dev->DevData.MountState < Mounted)
            {
                fs_util_trace_err_noinfo(RTF_DRIVE_NOT_READY);

                XRAISE(RTF_DRIVE_NOT_READY);
            }

            if (PartitionInfo->Partition.Sectors == 0)
            {
                fs_util_trace_err_noinfo(RTF_UNSUPPORTED_DRIVER_FUNCTION);

                XRAISE(RTF_UNSUPPORTED_DRIVER_FUNCTION);
            }

            break;
        default:
            break;
        case XFINALLY:
            /* free file slot and unlock device */
            if (f) FreeFTSlotAndDevice(f);
    XEND_API

    return RTF_NO_ERROR;
}

int RTFAPI RTFGetCurrentDirByDrive(WCHAR * DirName, UINT MaxLength)
{
   RTFDrive * volatile  Drive = NULL;
   WCHAR                drive_letter;
   kal_uint8 volatile   device_locked = KAL_FALSE;

   XTRY
      case XCODE:

         // parameter check
         if (NULL == DirName || 0 == DirName[0])
         {
            XRAISE(RTF_PARAM_ERROR);
         }

         drive_letter = fs_util_wchar_toupper(DirName[0]);

         if (drive_letter < MT_BASE_DRIVE_LETTER || drive_letter >= (MT_BASE_DRIVE_LETTER + FS_MAX_DRIVES))
         {
            XRAISE(RTF_DRIVE_NOT_FOUND);
         }

         // get drive structure
         Drive = &gFS_Data.DriveTable[drive_letter - MT_BASE_DRIVE_LETTER];

         // lock device
         LockDevice(Drive->Dev, 0);

         device_locked = KAL_TRUE;

         if ((kal_dchar_strlen(Drive->CurrDir) + 2) > MaxLength)
         {
            XRAISE(RTF_STRING_BUFFER_TOO_SMALL);
         }

         // get current dir
         kal_dchar_strcpy((char *)DirName, Drive->CurrDir);
         break;

      default:
         break;

      case XFINALLY:
         if (KAL_TRUE == device_locked)
         {
            UnlockDevice(Drive->Dev);
         }
         break;
   XEND_API

   return RTF_NO_ERROR;
}

/*-----------------------------------*/
int RTFAPI RTFGetCurrentDir(WCHAR * DirName, UINT MaxLength)
{
   RTFDrive * volatile Drive = NULL;

   fs_init();

   XTRY
      case XCODE:
         if (DefaultDrive == NULL)
            DefaultDrive = FindDefaultDrive();

         LockDevice(DefaultDrive->Dev, 0);

         Drive = DefaultDrive;

         if ((kal_dchar_strlen(Drive->CurrDir) + 2) > MaxLength)
         {
            fs_util_trace_err_noinfo(RTF_STRING_BUFFER_TOO_SMALL);

            XRAISE(RTF_STRING_BUFFER_TOO_SMALL);
         }

         kal_dchar_strcpy((char *)DirName, Drive->CurrDir);
         break;

      default:
         break;

      case XFINALLY:
         if (Drive) UnlockDevice(Drive->Dev);
         break;
   XEND_API
   return RTF_NO_ERROR;
}

/*-----------------------------------*/
int RTFAPI RTFSetCurrentDir(const WCHAR * DirName)
{
   RTFile * volatile f = NULL;

   XTRY
      case XCODE:
         f = ParseFileName((char *)DirName);
         if (f->SpecialKind != NormalFile)
         {
            fs_util_trace_err_noinfo(RTF_INVALID_FILENAME);

            XRAISE(RTF_INVALID_FILENAME);
         }

         if ((SearchFile(f, SEARCH_FILES|SEARCH_RELEASE_LOCK, (char *)DirName, NULL)) && (f->DirEntry.Dir.Attributes & RTF_ATTR_DIR))
         {
            DefaultDrive = f->Drive;
            kal_dchar_strcpy(f->Drive->CurrDir, f->FullName);
            f->Drive->CurrDirEntry = f->DirEntry;
         }
         else
         {
            fs_util_trace_err_noinfo(RTF_PATH_NOT_FOUND);

            XRAISE(RTF_PATH_NOT_FOUND);
         }
         break;

      default:
         break;

      case XFINALLY:
         if (f) FreeFTSlotAndDevice(f);
         break;
   XEND_API
   return RTF_NO_ERROR;
}

/*-----------------------------------*/
int RTFAPI RTFRemoveDir(const WCHAR * DirName)
{
   RTFile *volatile         f = NULL;
   RTFDOSDirEntry           *D;
   RTFDirLocation           DSR = {0, 0};
   #ifdef __FS_OPEN_HINT__
   RTFDirLocation *volatile hint = NULL;
   #endif


   XTRY
      case XCODE:
         f = ParseFileName((char *)DirName);

         /* Fix write protect issue, Karen Hsu, 2004/04/07, ADD START */
         if(f->Dev->DeviceFlags & MT_DEVICE_WRITE_PROTECT)
         {
            fs_util_trace_err_noinfo(RTF_WRITE_PROTECTION);

            XRAISE(RTF_WRITE_PROTECTION);
         }
         /* Fix write protect issue, Karen Hsu, 2004/04/07, ADD END */

         if (f->SpecialKind != NormalFile)
         {
            fs_util_trace_err_noinfo(RTF_INVALID_FILENAME);

            XRAISE(RTF_INVALID_FILENAME);
         }

         #ifdef __FS_OPEN_HINT__
         hint = MTHintGet(DirName, MT_HINT_ACTION_FORCE_NO_NEW);
         if (SearchFile(f, SEARCH_FILES | SEARCH_RELEASE_LOCK, (char *)DirName, hint) == 0)
         #else
         if (SearchFile(f, SEARCH_FILES | SEARCH_RELEASE_LOCK, (char *)DirName, NULL) == 0)
         #endif /* __FS_OPEN_HINT__ */
         {
            fs_util_trace_err_noinfo(RTF_PATH_NOT_FOUND);

            XRAISE(RTF_PATH_NOT_FOUND);
         }

         CheckNotOpen(f);

         if ((f->DirEntry.Dir.Attributes & RTF_ATTR_DIR) == 0)
         {
            fs_util_trace_err_noinfo(RTF_PATH_NOT_FOUND);

            XRAISE(RTF_PATH_NOT_FOUND);
         }

         if (f->DirEntry.Dir.Attributes & RTF_ATTR_READ_ONLY)
            /* Change error message for FMT, Karen Hsu, 2004/04/20, MOD START */
         {
            fs_util_trace_err_noinfo(MT_READ_ONLY_ERROR);

            XRAISE(MT_READ_ONLY_ERROR);
            //XRAISE(RTF_ACCESS_DENIED);
         }
            /* Change error message for FMT, Karen Hsu, 2004/04/20, MOD END */


         // do not remove the current directory
         if (SAME_DIR_ENTRY(f->DirEntry.ShortPos, f->Drive->CurrDirEntry.ShortPos))
         {
            fs_util_trace_err_noinfo(RTF_ACCESS_DENIED);

            XRAISE(RTF_ACCESS_DENIED);
         }

         // do not remove the root
         if (kal_dchar_strlen(f->FullName) == 6)
         {
            fs_util_trace_err_noinfo(RTF_ACCESS_DENIED);

            XRAISE(RTF_ACCESS_DENIED);
         }

         // check that the directory is empty
         // skip the first two . and .. entries
         D = StartDirSearch(f->Drive, FIRST_FILE_CLUSTER(f->DirEntry.Dir), 2, &DSR);    // FS_BAD_DIR_ENTRY will raised if FirstCluster is 0

         while (D)
         {
            int Kind = EntryType(D);

            if (Kind == InUse)
            {
                fs_util_trace_err_noinfo(RTF_ACCESS_DENIED);

               XRAISE(RTF_ACCESS_DENIED);
            }
            else if (Kind == NeverUsed)
               break;
            D = NextDir(f->Drive, &DSR);
         }

         // Add RTF_COMMITTED to ensure deleted dir entry (at least SFN entry) be flushed before FAT table. (W10.44)
         f->Flags |= RTF_COMMITTED;

         DeleteDirEntry(f);

         if (FIRST_FILE_CLUSTER(f->DirEntry.Dir) != 0)
         //quota
         {
            FATDelete(f->Drive, FIRST_FILE_CLUSTER(f->DirEntry.Dir), f);
            //FATDelete(f->Drive, FIRST_FILE_CLUSTER(f->DirEntry.Dir));
         }

         if (((f->Dev->DeviceFlags & RTF_DEVICE_LAZY_WRITE) == 0) || (FileCount(f->Dev) <= 1))
            FlushAllBuffers(f->Dev);

         break;
      default:

        /*
         * for bad dir entry (with invalid FirstCluster), delete it anyway (W11.11)
         */
        if (f && XVALUE == FS_BAD_DIR_ENTRY)
        {
            f->Flags |= RTF_COMMITTED;

            DeleteDirEntry(f);

            XVALUE = FS_NO_ERROR;
        }

         break;
      case XFINALLY:

         #ifdef __FS_OPEN_HINT__
         // for safety, invalidate all possible related hints
         if (f) MTHintExpireByDrive(f->Drive);
         #endif

         if (f) FreeFTSlotAndDevice(f);
         break;
   XEND_API
   return RTF_NO_ERROR;
}

/*-----------------------------------*/
int RTFAPI RTFCloseAll(void)
{
   int i;
   int R, Result = RTF_NO_ERROR;
   int Count = 0;
   RTFile * f;

   for (i=0, f = gFS_Data.FileTable; i<FS_MAX_FILES; i++, f++)
      if ((f->Lock != 0) && (f->Dev != NULL))
      {
         Count++;
         R = RTFClose((f->Unique << (4*sizeof(int))) | i);
         if (R < RTF_NO_ERROR)
            Result = R;
      }
   if (Result == RTF_NO_ERROR)
      return Count;
   else
      return Result;
}

/*------------------------------------------*/
/* Unlock all devices bruteforcily for exception cases */
int RTFAPI RTFUnlockAll(void)
{
   int i;
   int Count = 0;
   RTFile * f;

   /*
    * Note the same device may be "UnlockDevice" more than once.
    * Finally Mutex->rtf_lock_count may be a very big (negative) value.
    *
    * In this case, nvram_write_exception() may access FS without getting
    * device lock.
    *
    * Does it imply device lock can be always bypassed in exception mode?
    */

   for (i=0, f = gFS_Data.FileTable; i<FS_MAX_FILES; i++, f++)
      if ((f->Lock != 0) && (f->Dev != NULL))
      {
         Count++;
         UnlockDevice(f->Dev);
      }

   return Count;
}

/*-----------------------------------*/
int RTFAPI RTFCommitAll(const WCHAR * DriveName)
{
   RTFile * volatile f = NULL;
   RTFDevice * volatile Dev = NULL;

   XTRY
      case XCODE:
         if (DriveName != NULL)
         {
            f = ParseFileName((char *)DriveName);
            FlushAllBuffers(f->Dev);
         }
         else
         {
            RTFDevice * D;
            for (D = gFS_DeviceList; D->DeviceType; D++)
               if (D->DevData.MountState >= Mounted)
               {
                  LockDevice(D, 0); Dev = D;
                  FlushAllBuffers(D);
                  UnlockDevice(D); Dev = NULL;
               }
         }
         break;
      default:
         break;
      case XFINALLY:
         if (f)   FreeFTSlotAndDevice(f);
         if (Dev) UnlockDevice(Dev);
         break;
   XEND_API
   return RTF_NO_ERROR;
}

/*-----------------------------------*/
int RTFAPI RTFResetDisk(const WCHAR * DriveName)
{
   RTFile * volatile f = NULL; /* Remove RVCT warning, Karen Hsu, 2004/11/02, ADD */

   fs_init();

   if (DriveName != NULL) // do just one physical drive
   XTRY
      //RTFile * volatile f = NULL; /* Remove RVCT warning, Karen Hsu, 2004/11/02, REM */
      case XCODE:
         f = ParseFileName((char *)DriveName);

         if (FileCount(f->Dev) > 1)
         {
            fs_util_trace_err_noinfo(RTF_ACCESS_DENIED);
            fs_util_trace_info1(MT_TRACE_ERROR, FS_ERR_RTFRESETDISK_FILE_NOT_CLOSED, FileCount(f->Dev), NULL);

            XRAISE(RTF_ACCESS_DENIED);
         }
         else
            UnmountDevice(f->Dev, 0);
         break;
      default:
         break;
      case XFINALLY:
         if (f) FreeFTSlotAndDevice(f);
         break;
   XEND_API
   else // reset all devices
   XTRY
      RTFDevice * Dev;
      RTFDrive  * Drive;
      case XCODE:
         RTFSYSLockMutex(RTFLock, RTF_INFINITE);
         for (Dev = gFS_DeviceList; Dev->DeviceType; Dev++)
            if (Dev->DevData.MountState >= Mounted)
            {
               if (FileCount(Dev) > 0)
               {
                  fs_util_trace_err_noinfo(RTF_ACCESS_DENIED);

                  XRAISE(RTF_ACCESS_DENIED);
               }
               else
                  UnmountDevice(Dev, 0);
            }
         // destroy the device -> drive and drive -> device information
         for (Dev = gFS_DeviceList; Dev->DeviceType; Dev++)
            Dev->DevData.FirstDrive = NULL;
         for (Drive = gFS_Data.DriveTable; Drive < (gFS_Data.DriveTable + FS_MAX_DRIVES); Drive++)
         {
            Drive->Dev = NULL;
            Drive->NextDrive = NULL;
         }
         ScanDevices(); // this will not throw exceptions
         break;
      default:
         break;
      case XFINALLY:
         RTFSYSFreeMutex(RTFLock);
         break;
   XEND_API
   return RTF_NO_ERROR;
}

/*-----------------------------------*/
void RTFAPI RTFShutDown(void)
{
   RTFDevice * Dev;

   if (RTFLock == NULL)
      return;

   /* if shutdown is called from exception writing, we should not flush cache or incur wirtes to flash */
   if (INT_QueryExceptionStatus() == KAL_FALSE)
   {
      gFS_USBMS_PhoneDriveHandle = -2;
      RTFCloseAll();
   }

   /* take system lock twice because ShutDown will release one system lock */
   RTFSYSLockMutex(RTFLock, RTF_INFINITE);
   RTFSYSLockMutex(RTFLock, RTF_INFINITE);

   /* unmount all devices and clean all file table slots */
   for (Dev = gFS_DeviceList; Dev->DeviceType; Dev++)
      if (Dev->DevData.MountState >= Mounted)
      {
         /*
          * Keep file table in exception mode for debug purpose.
          *
          * This is necessary for __TC01__ WISE projects because WISE will use
          * existed file handle to access file system.
          */
         if (INT_QueryExceptionStatus() == KAL_TRUE)
            UnmountDevice(Dev, 0);
         else
            UnmountDevice(Dev, 1);
      }

   Dev--;

   for (; Dev >= gFS_DeviceList; Dev--)
      ShutDown(Dev);

   RTFSYSFreeMutex(RTFLock);
   RTFSYSFreeMutex(RTFLock);
}
#ifdef DIR_COMPACT_SUPPORT
/*-----------------------------------*/
static int INTERN CompactDir(RTFDrive * Drive, RTFCluster Cluster, kal_uint32 Flags)
{
   RTFDirLocation DSR_I;
   RTFDOSDirEntry * D = StartDirSearch(Drive, Cluster, 0, &DSR_I);
   RTFDirLocation DSR_O = DSR_I;
   int i=0, o=0;
   int More = 1;
   RTFCluster LastCluster = 0;

   // copy used entries
   while (D)
   {
      int Kind = EntryType(D);

      if (Kind == NeverUsed)
         break;

      i++;
      if (Kind != Available)
      {
         o++;
         if (!SAME_DIR_ENTRY(DSR_I, DSR_O))
         {
            if ((Flags & RTF_CMPCT_READ_ONLY) == 0)
            {
               RTFDOSDirEntry Temp = *D;
               D = GetDir(Drive, &DSR_O);
               *D = Temp;
               SetDirty(Drive->Dev);
            }
         }
         if ((Kind == InUse) &&
             (D->Attributes & RTF_ATTR_DIR) &&
             (Flags & RTF_CMPCT_RECURSIVE) &&
             (memcmp((char*)D->FileName, ".  ", 3) != 0) &&
             (memcmp((char*)D->FileName, ".. ", 3) != 0))
         {
            i += CompactDir(Drive, FIRST_FILE_CLUSTER(*D), Flags);
         }
         LastCluster = DSR_O.Cluster;
         More = IncDir(Drive, &DSR_O);
      }
      D = NextDir(Drive, &DSR_I);
   }

   if (More)
   {
      // zero out slack
      D = GetDir(Drive, &DSR_O);
      while (D)
      {
         if (LastCluster && (DSR_O.Cluster != LastCluster))
         {
            if ((Flags & RTF_CMPCT_READ_ONLY) == 0)
            {
               SetClusterValue(Drive, LastCluster, RTF_CHAIN_END_MARK);
               //quota
               i += DIRS_PER_SECTOR(Drive) * Drive->SectorsPerCluster * FATDelete(Drive, DSR_O.Cluster, NULL);
               //i += DIRS_PER_SECTOR(Drive) * Drive->SectorsPerCluster * FATDelete(Drive, DSR_O.Cluster, NULL);
            }
            else
            {
               RTFCluster LastCluster;
               i += DIRS_PER_SECTOR(Drive) * Drive->SectorsPerCluster * FATClusterChainLength(Drive, DSR_O.Cluster, &LastCluster);
            }
            break;
         }
         if (D->FileName[0])
         {
            i++;
            if ((Flags & RTF_CMPCT_READ_ONLY) == 0)
            {
               kal_mem_set((void*)D, 0, sizeof(*D));
               SetDirty(Drive->Dev);
            }
         }
         LastCluster = DSR_O.Cluster;
         D = NextDir(Drive, &DSR_O);
      }
   }
   return i-o;
}

/*-----------------------------------*/
int RTFAPI RTFCompactDir(const WCHAR * DirName, kal_uint32 Flags)
{
   RTFile * volatile f = NULL;
   int volatile Result = 0;

   XTRY
      case XCODE:
         f = ParseFileName((char *)DirName);

         if (f->SpecialKind != NormalFile)
         {
            fs_util_trace_err_noinfo(RTF_INVALID_FILENAME);

            XRAISE(RTF_INVALID_FILENAME);
         }

         if ((SearchFile(f, SEARCH_FILES, (char *)DirName, NULL)) && (f->DirEntry.Dir.Attributes & RTF_ATTR_DIR))
         {
            //if (((Flags & RTF_CMPCT_READ_ONLY) == 0) && (FileCountDrive(f->Drive) > 1))
            if (((Flags & RTF_CMPCT_READ_ONLY) == 0) && MTCheckPathOpen(f))
            {
                fs_util_trace_err_noinfo(RTF_ACCESS_DENIED);

               XRAISE(RTF_ACCESS_DENIED);
            }

            Result = CompactDir(f->Drive, FIRST_FILE_CLUSTER(f->DirEntry.Dir), Flags);
         }
         else
         {
            fs_util_trace_err_noinfo(RTF_PATH_NOT_FOUND);

            XRAISE(RTF_PATH_NOT_FOUND);
         }

         FlushAllBuffers(f->Dev);

         // the current dir's dir entry may have moved, find it again using an abs path
         if (((Flags & RTF_CMPCT_READ_ONLY) == 0) && (Result > 0))
         {
            if ((SearchFile(f, SEARCH_FILES, f->Drive->CurrDir, NULL)) && (f->DirEntry.Dir.Attributes & RTF_ATTR_DIR))
               f->Drive->CurrDirEntry = f->DirEntry;
            else
            {
               fs_util_trace_err_noinfo(RTF_PATH_NOT_FOUND);

               XRAISE(RTF_PATH_NOT_FOUND);
            }
         }

         break;
      default:
         break;
      case XFINALLY:

         if (f)
         {
            #ifdef __FS_OPEN_HINT__
            MTHintExpireByDrive(f->Drive);
            #endif

            FreeFTSlotAndDevice(f);
         }

         break;
   XEND_API
   return Result;
}

#endif // DIR_COMPACT_SUPPORT

#ifdef CHECK_DISK_SUPPORT

/*-----------------------------------*/
int RTFAPI RTFCheckDiskBufferSize(const WCHAR * DriveName)
// The buffer will hold a DiskCheckData structure followed by
// a sector buffer followed by
// a cluster bit map.
{
   RTFDiskInfo DI;
   int Result;

   if (DriveName == NULL) return RTF_PARAM_ERROR;

   Result = RTFGetDiskInfoEx(DriveName, &DI, RTF_DI_BASIC_INFO);

   if (Result < RTF_NO_ERROR)
      return Result;

   return sizeof(DiskCheckData) + DI.BytesPerSector + (DI.TotalClusters+3) / 8 + 1;
}

/*-----------------------------------*/
static kal_uint32 RTFAPI DummyChkDskHandler(kal_uint32 Flags)
{
   return Flags;
}

static kal_uint32 RTFAPI MTKChkDskHandler(kal_uint32 Flags,
                                              const char * Path,
                                              const RTFDOSDirEntry * FileInfo,
                                              kal_uint32 N1,
                                              kal_uint32 N2)
{
   if (Flags & RTF_CHK_INVALID_CLUSTER)
     return RTF_CHK_INVALID_CLUSTER_DELETE;

   if (Flags & RTF_CHK_INVALID_DIR)
     return RTF_CHK_INVALID_DIR_DELETE;

   if (Flags & RTF_CHK_CROSSLINK)
     return RTF_CHK_CROSSLINK_DELETE;

   if (Flags & RTF_CHK_FILESIZE_SMALL)
   {
     /*----------------------------------------------------------------------
      * Truncate file if RTF_ATTR_SYSTEM is set (e.g., FOTA downloaded file).
      * Because some standards (e.g., CMCC) do not allow "progress roll-back".
      * So we just truncate it to not let progress reset (because file is deleted)
      * in case of power-loss.
      *------------------------------------------------------------ W09.08 --*/
     if (FileInfo->Attributes & RTF_ATTR_SYSTEM)
     {
     	return RTF_CHK_FILESIZE_SMALL_TRUNC;
     }
     else
     {
        return RTF_CHK_FILESIZE_SMALL_DELETE;
     }
   }

   if (Flags & RTF_CHK_FILESIZE_LARGE)
   {
     if (FileInfo->Attributes & RTF_ATTR_SYSTEM)
     {
        return RTF_CHK_FILESIZE_LARGE_TRUNC;
     }
     else
     {
        return RTF_CHK_FILESIZE_LARGE_DELETE;
     }
   }

   if (Flags & RTF_CHK_LONG_FILENAME)
     return RTF_CHK_LONG_FILENAME_DELETE;

   if (Flags & RTF_CHK_LOST_CLUSTER)
     return RTF_CHK_LOST_CLUSTER_FREE;

   return Flags;
}

/*-----------------------------------*/
static kal_uint32 RTFAPI CallChkDskCallback(DiskCheckData * DCD,
                                       kal_uint32 Mask,
                                       const char * Path,
                                       const RTFDOSDirEntry * FileInfo,
                                       kal_uint32 N1,
                                       kal_uint32 N2)
{
   /* kick watchdog timer */
   fs_util_wdt_restart();

   if (DCD->Flags & Mask)
   {
      kal_uint32 Result;

      RTFSYSFreeMutex(RTFLock);
      Result = DCD->ErrorHandler(DCD->Flags & Mask, Path, FileInfo, N1, N2);
      RTFSYSLockMutex(RTFLock, RTF_INFINITE);
      return Result;
   }
   else
      return 0;
}

/*-----------------------------------*/
#if 0  // [Slim] RTF_CHK_FAT_MISMATCH_MASK is not enabled currently
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
#ifdef __FS_DEBUG__
/* under construction !*/
#endif
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
#endif  // [Slim] RTF_CHK_FAT_MISMATCH_MASK is not enabled currently

/*-----------------------------------*/
static void INTERN ClearClusterMapChain(BYTE * ClusterMap, RTFDrive * Drive, RTFCluster Cluster, RTFCluster Count)
{
   while (Count--)
   {
      CLEAR_CLUSTER_BIT(ClusterMap, Cluster);
      Cluster = GetClusterValue(Drive, Cluster);
   }
}

/*-----------------------------------*/
RTFCluster RTFAPI SafeGetClusterValue(RTFDrive * Drive, RTFCluster Cluster)
//static RTFCluster INTERN SafeGetClusterValue(RTFDrive * Drive, RTFCluster Cluster)
// get a cluster value, but do not throw any exceptions
{
   RTFCluster volatile Result;

   XTRY
      case XCODE:
         Result = fs_srv_get_cluster_value(Drive, Cluster, FS_GET_CLUSTER_DEFAULT, GetBuffer);
         break;
      default:
         XHANDLED;
         Result = 0;
         break;
      case XFINALLY:
         break;
   XENDX
   return Result;
}

 /*----------- Check short filename -------------*/
 int RTFAPI FileNameInvalid(const char * Name)
 //static int INTERN FileNameInvalid(const char * Name)
 {
    int i;

    if ((BYTE)(Name[0]) < (BYTE)' ' && 0x05 != (BYTE)(Name[0]))
       return 1;

    for (i=0; i<11; )
    {
       if (Name[i] & 0x80 || (0 == i && 0x05 == (BYTE)(Name[0])))
       {
          i += 2;
       }
       else
       {
          if (!fs_util_validate_sfn_char(Name[i]) || (Name[i] == '.'))
            return 1;
          i++;
       }
    }
    return 0;
 }

/*-----------------------------------*/
static int INTERN AttrInvalid(BYTE A, int IsInRoot)
{
   if (A & 0xC0) // 0x80 and 0x40 are undefined
      return 1;

   // volume labels outside the root are always invalid
   if (A & RTF_ATTR_VOLUME){
      if (!IsInRoot)
         return 1;
      else
         // if there is a volume label, it must have no other attrs set
         if (A & ~(RTF_ATTR_VOLUME | RTF_ATTR_ARCHIVE))
            return 1;
   }
   return 0;
}

/*-----------------------------------*/
static void INTERN LFNError(DiskCheckData * DCD, RTFDirLocation * LongPos, const RTFDirLocation * Pos)
// remove all dir entry between LongPos and (excluding) Pos
{
   switch (CallChkDskCallback(DCD, RTF_CHK_LONG_FILENAME_MASK, DCD->Path, NULL, 0, 0))
   {
     case RTF_CHK_LONG_FILENAME_REMOVE:
         DelLongDirEntry(DCD->Drive, LongPos, Pos);
         break;
     case RTF_CHK_LONG_FILENAME_DELETE:
         DelDirEntry(DCD->Drive, LongPos, Pos);
         break;
   }
   LongPos->Cluster = 0;
}

/*-----------------------------------*/
static int INTERN CheckDir(DiskCheckData * DCD, RTFDirLocation * LongPos, const RTFDirLocation * Pos, int Level)
// check DCD->D
// check a single directory entry
// level is 0 is for the root pseudo dir entry
{
   RTFCluster Parent, C;
   RTFCluster FATClusters = 0;

   // don't check "." and ".." entries
   if ((Pos->Index < 2) && ((memcmp((char*)DCD->D.FileName, ".          ", 8+3) == 0) ||
                            (memcmp((char*)DCD->D.FileName, "..         ", 8+3) == 0)))
      return RTF_NO_ERROR;

   // check non FAT dependent stuff in the dir entry
   C = FIRST_FILE_CLUSTER(DCD->D);

   if ((DCD->Flags & RTF_CHK_INVALID_DIR_MASK) && (Level > 0) &&
       (FileNameInvalid((char *)DCD->D.FileName)           ||       // valid file names chars /* Remove RVCT warning, Karen Hsu, 2004/11/02, MOD */
        AttrInvalid(DCD->D.Attributes, Level == 1) ||       // valid attribute
        (C == 1L) || (C >= DCD->Drive->Clusters)   ||       // valid start cluster
        ((DCD->D.Attributes & RTF_ATTR_DIR) && (C == 0L)))) // dirs must have a FAT chain
      switch (CallChkDskCallback(DCD, RTF_CHK_INVALID_DIR_MASK, DCD->Path, &DCD->D, 0, 0))
      {
         case RTF_CHK_INVALID_DIR_DELETE:
            DelDirEntry(DCD->Drive, LongPos, Pos);
            return RTF_NO_ERROR; // mo more checks on this entry
      }

   // go through the file's cluster chain
   // check for invalid FAT entries
   // check for crosslinks
   // markup cluster map
   // do not check fat12/16 root directories
   // but do take all files which have a cluster chain
   // this code does not physically free any space in the FAT
   // it merely leaves lost clusters behind
   // use the lost cluster check to recover this space

   Parent = RTF_INVALID_CLUSTER;
   C = FIRST_FILE_CLUSTER(DCD->D);

   if ((C != RTF_ROOT_DIR) && (C != 0))
   {
      do {

         /* kick watchdog timer */
         fs_util_wdt_restart();

         if ((C < 2L) || (C >= DCD->Drive->Clusters))
            switch (CallChkDskCallback(DCD, RTF_CHK_INVALID_CLUSTER_MASK, DCD->Path, &DCD->D, (Parent == RTF_INVALID_CLUSTER) ? 0 : Parent, 0))
            {
               #if !defined(__FS_SLIM_CHECK_DIR__)

               case RTF_CHK_INVALID_CLUSTER_TRUNC:
                  if (Parent != RTF_INVALID_CLUSTER)
                     SetClusterValue(DCD->Drive, Parent, C = RTF_CLUSTER_CHAIN_END);
                  else
                  // fall thru
               #endif // !__FS_SLIM_CHECK_DIR__

               case RTF_CHK_INVALID_CLUSTER_DELETE:
                  {
                     DelDirEntry(DCD->Drive, LongPos, Pos);

                     /*
                      * For case A -> B -> C, while ClusterMap[B] is set, if B contains an invalid cluster value,
                      * then B may not be cleaned in CheckLostClusters() if there is no other error behind which
                      * needs re-try. Therefore we return RTF_CHECKDISK_RETRY here instead of RTF_NO_ERROR to
                      * reset ClusterMap to let Cluster B be deleted in next round.
                      */

                     return RTF_CHECKDISK_RETRY;
                  }
            }

         if ((C < 2L) || (C >= DCD->Drive->Clusters))
            break; // can't do cross link check on invalid cluster

         if (CLUSTER_BIT(DCD->ClusterMap, C))
            switch (CallChkDskCallback(DCD, RTF_CHK_CROSSLINK_MASK, DCD->Path, &DCD->D, C, 0))
            {
               #if !defined(__FS_SLIM_CHECK_DIR__)

               case RTF_CHK_CROSSLINK_TRUNC:
                  if (Parent != RTF_INVALID_CLUSTER)
                     SetClusterValue(DCD->Drive, Parent, C = RTF_CHAIN_END_MARK);
                  else
                  // fall thru

               #endif // !__FS_SLIM_CHECK_DIR__

               case RTF_CHK_CROSSLINK_DELETE:
                  {
                     ClearClusterMapChain(DCD->ClusterMap, DCD->Drive, FIRST_FILE_CLUSTER(DCD->D), FATClusters);
                     DelDirEntry(DCD->Drive, LongPos, Pos);
                     //quota
                     SafeFATDelete(DCD->Drive, FIRST_FILE_CLUSTER(DCD->D), NULL); /* Clear the chain */
                     //FATDelete(DCD->Drive, FIRST_FILE_CLUSTER(DCD->D)); /* Clear the chain */

                     return RTF_CHECKDISK_RETRY;
                  }
            }
         else
            SET_CLUSTER_BIT(DCD->ClusterMap, C);

         if ((C < 2L) || (C >= DCD->Drive->Clusters))
            break; // can't walk invalid cluster chain

         Parent = C;
         FATClusters++;
         C = SafeGetClusterValue(DCD->Drive, Parent);

      } while (C < RTF_CLUSTER_CHAIN_END);
   }

   /*------------------------------------------------------------
    * Check file size:
    * FATClusters: The number of clusters occupied by file cluster chain
    * DirClusters: The number of clusters calculated from directory entry
    *------------------------------------------------------------*/
   if ((DCD->D.Attributes & RTF_ATTR_DIR) == 0) // dirs do not have valid filesize
   {
      RTFCluster DirClusters = (DCD->D.FileSize > 0) ? ((DCD->D.FileSize-1) / DCD->Drive->ClusterSize) + 1 : 0;

      /* kick watchdog timer */
      fs_util_wdt_restart();

      if (FATClusters > DirClusters)
      {
         switch (CallChkDskCallback(DCD, RTF_CHK_FILESIZE_SMALL_MASK, DCD->Path, &DCD->D, DCD->D.FileSize, FATClusters * DCD->Drive->ClusterSize))
         {
            case RTF_CHK_FILESIZE_SMALL_TRUNC:
               /*----------------------------------------------------------
                * Too many FAT clusters, free superfluous clusters.
                * File size is not required to be fixed in this case.
                *----------------------------------------------------------*/
               if (DirClusters > 0)
               {
                  RTFCluster i, Next;

                  /* get start point of FAT-chain traverse */
                  C = FIRST_FILE_CLUSTER(DCD->D);

                  /* start traverse, stop in the DirCluster-th cluster (C is the last cluster number) */
                  for (i = 0; i < DirClusters; i++)
                     C = GetClusterValue(DCD->Drive, C);

                  /* get start point of FAT-chain cleaning */
                  Next = GetClusterValue(DCD->Drive, C);

                  /* set EOC mark in cluster C, remain superfluous clusters as LOST clusters */
                  SetClusterValue(DCD->Drive, C, RTF_CHAIN_END_MARK);

                  /* clean cluster bit map starting from cluster Next */
                  ClearClusterMapChain(DCD->ClusterMap, DCD->Drive, Next, FATClusters - DirClusters);
               }
               /*----------------------------------------------------------------------
                * DirClusters == 0, release all FAT clusters and reset file information.
                * Note. FATClusters must be > 0 here.
                *----------------------------------------------------------------------*/
               else
               {
                  RTFDOSDirEntry *D;

                  /*------ Step 1. Clean superfluous FAT chain ------*/

                  /* get start point of FAT-chain */
                  C = FIRST_FILE_CLUSTER(DCD->D);

                  if (C != 0)
                  {
                     /* clear cluster C, remain superfluous clusters as LOST clusters */
                     SetClusterValue(DCD->Drive, C, 0);

                     /* clean cluster bit map starting from cluster C */
                     ClearClusterMapChain(DCD->ClusterMap, DCD->Drive, C, FATClusters);
                  }

                  /*------ Step 2. Reset DIR.FirstCluster and DIR.FileSize ------*/
                  D = GetDir(DCD->Drive, Pos);
                  D->FirstCluster = D->FirstClusterHi = 0; /* this directory entry must be a FILE */
                  D->FileSize = 0;
                  SetDirty(DCD->Drive->Dev);
               }
               break;
            case RTF_CHK_FILESIZE_SMALL_DELETE:
            {
               DelDirEntry(DCD->Drive, LongPos, Pos);
               ClearClusterMapChain(DCD->ClusterMap, DCD->Drive, FIRST_FILE_CLUSTER(DCD->D), FATClusters);
               SafeFATDelete(DCD->Drive, FIRST_FILE_CLUSTER(DCD->D), NULL); /* Clear the chain */

               return RTF_NO_ERROR;  // no further checks on deleted files
            }
         }
      }
      else if (FATClusters < DirClusters)
      {
         switch (CallChkDskCallback(DCD, RTF_CHK_FILESIZE_LARGE_MASK, DCD->Path, &DCD->D, DCD->D.FileSize, FATClusters * DCD->Drive->ClusterSize))
         {
            case RTF_CHK_FILESIZE_LARGE_TRUNC:
               /* file size in dir entry too large, truncate and fix file size */
               {
                  RTFDOSDirEntry *D = GetDir(DCD->Drive, Pos);
                  D->FileSize = FATClusters * DCD->Drive->ClusterSize;
                  SetDirty(DCD->Drive->Dev);
               }
               break;
            case RTF_CHK_FILESIZE_LARGE_DELETE:
               {
                  DelDirEntry(DCD->Drive, LongPos, Pos);
                  ClearClusterMapChain(DCD->ClusterMap, DCD->Drive, FIRST_FILE_CLUSTER(DCD->D), FATClusters);
                  //quota
                  SafeFATDelete(DCD->Drive, FIRST_FILE_CLUSTER(DCD->D), NULL); /* Clear the chain */
                  //FATDelete(DCD->Drive, FIRST_FILE_CLUSTER(DCD->D)); /* Clear the chain */
                  /* if another file cross-links to the chain will have invalid clusters */
                  return RTF_NO_ERROR;
               }
         }
      }
   }
   else // this is a directory, process its content
   {
      RTFDirLocation DSR;
      RTFDirLocation LDSR;
      RTFDOSDirEntry * D;
      char * pF = DCD->Path + kal_dchar_strlen(DCD->Path);
      BYTE CheckSum = 0; /* Remove RVCT warning, Karen Hsu, 2004/11/02, MOD */
      int LFNIndex;

      int NeverUseFlag = 0;

      if (!compASCII(pF, -1, '\\') )
         setASCII(pF, 0, '\\');
      pF += 2;
      setASCII(pF, 0, '\0');

      /* Do not allow folder too deep, avoid stack overful, 2005/12/12, ADD START*/
      if (Level > MT_CHECKDISK_MAX_DEPTH)
      {
         DelDirEntry(DCD->Drive, LongPos, Pos);
         ClearClusterMapChain(DCD->ClusterMap, DCD->Drive, FIRST_FILE_CLUSTER(DCD->D), FATClusters);
         FATDelete(DCD->Drive, FIRST_FILE_CLUSTER(DCD->D), NULL); /* Clear the chain */
         return RTF_NO_ERROR;
      }
      /* Do not allow folder too deep, avoid stack overful, 2005/12/12, ADD END*/

      CallChkDskCallback(DCD, RTF_CHK_VERBOSE, DCD->Path, NULL, 0, 0);

      D = StartDirSearch(DCD->Drive, FIRST_FILE_CLUSTER(DCD->D), 0, &DSR);
      LFNIndex = -1;
      LDSR.Cluster = 0;
      while (D != NULL)
      {
         int Kind = EntryType(D);

         /* kick watchdog timer */
         fs_util_wdt_restart();

         if (Kind == NeverUsed)
         {
             NeverUseFlag = 1;
         }

         // Any directory entry after NeverUsedFlag should be "0x00".
         if(NeverUseFlag == 1)
         {
             if(D->FileName[0] != 0x00)
             {
                 kal_mem_set((char*)D, 0, sizeof(*D));
                 SetDirty(DCD->Drive->Dev);
                 Kind = EntryType(D);
             }
         }

         if (Kind == Lfn)
         {
            const LFNDirEntry * LD = (void*) D;
            if (LD->Ord & 0x40) // it's the start of an LFN
            {
               // see if it fits
               char * Limit;
               char * L;
               if (LDSR.Cluster)
                  LFNError(DCD, &LDSR, &DSR);
               LFNIndex = LD->Ord & 0x3F;
               CheckSum = LD->CheckSum;
               LDSR = DSR;
               Limit = pF + (LFNIndex-1)*13*2 + 2*LFNCharCount(LD);
               L = (char *)fs_min(Limit, (DCD->Path+RTF_MAX_PATH - 2));
               kal_mem_set(pF, '?', L - pF);
               L[0] ='\0';
               L[1] ='\0';
               if (L < Limit)
                  LFNIndex = -1;
            }
            if ((LD->CheckSum != CheckSum) || (LFNIndex != (LD->Ord & 0x3F)) || (LFNIndex <= 0))
               LFNIndex = -1;
            else
               CopyLFN(pF + --LFNIndex * 26, LD);
         }
         else if (LDSR.Cluster && (LFNIndex == -1))
         {
            LFNError(DCD, &LDSR, &DSR);
         }

         Kind = EntryType(D); /* reget entry type because the entry may be deleted */

         if (Kind == InUse)
         {
            if (LFNIndex != -1)
            {
               if ((LFNIndex != 0) ||
                   (CheckSum != ShortNameCheckSum((const BYTE*) D->FileName)))
               {
                  LFNError(DCD, &LDSR, &DSR);
                  LFNIndex = -1;
               }
            }

            if (LFNIndex == 0)
            {
               const WCHAR *p = (WCHAR *)pF;
               while (p[0])
                  if (!fs_util_validate_lfn_char(*p++))
                  {
                     LFNError(DCD, &LDSR, &DSR);
                     LFNIndex = -1;
                     break;
                  }
            }

            DCD->D = *D;
            if (LFNIndex == -1)
            {
               if (MakeShortFileName(D, pF, DCD->Path + RTF_MAX_PATH - pF) != RTF_NO_ERROR)
               {
                  FileNameExtendToWCHAR((char *)pF, FS_MAX_SFN_NATIVE_FILE_NAME_LENGTH_B);

                  switch (CallChkDskCallback(DCD, RTF_CHK_INVALID_DIR_MASK, DCD->Path, &DCD->D, 0, 0))
                  {
                     case RTF_CHK_INVALID_DIR_DELETE:
                        DelDirEntry(DCD->Drive, &LDSR, &DSR);
                        goto SkipDir;
                  }
               }
               else
               {
                  FileNameExtendToWCHAR((char *)pF, FS_MAX_SFN_NATIVE_FILE_NAME_LENGTH_B);
               }
            }

            if (CheckDir(DCD, &LDSR, &DSR, Level+1) == RTF_CHECKDISK_RETRY)
               return RTF_CHECKDISK_RETRY;
SkipDir:
            pF[0] = '\0';
            LFNIndex = -1;
            LDSR.Cluster = 0;
         }
         D = NextDir(DCD->Drive, &DSR);
      }
   }

   return RTF_NO_ERROR;
}

/*-----------------------------------*/
static void INTERN CheckLostClusters(DiskCheckData * DCD)
{
   RTFCluster i, C, Free;
   UINT State = 1;

   // mark up all free and bad clusters
   // count free clusters
   Free = 0;
   for (i=2; i < DCD->Drive->Clusters; i++)
   {
      if (!CLUSTER_BIT(DCD->ClusterMap, i))
         switch (SafeGetClusterValue(DCD->Drive, i))
         {
            case 0:
               Free++;
               // fall through
            case RTF_BAD_CLUSTER:
               SET_CLUSTER_BIT(DCD->ClusterMap, i);
               break;
         }
   }

   DCD->Drive->FreeClusterCount = Free;
   UpdateClusterWatermark(DCD->Drive, DCD->Drive->ClusterWatermark, 0);

   SET_CLUSTER_BIT(DCD->ClusterMap, DCD->Drive->Clusters); // one more to close the last chain

   // look for unmarked areas
   C = 0;
   for (i=2; i <= DCD->Drive->Clusters ; i++)
   {
      if (State != CLUSTER_BIT(DCD->ClusterMap, i))
      {
         if (State == 0) // end of a lost chain
         {
            switch (CallChkDskCallback(DCD, RTF_CHK_LOST_CLUSTER_MASK, DCD->Path, NULL, i-C, C))
            {
               case RTF_CHK_LOST_CLUSTER_FREE:
               {
                  RTFCluster j;
                  for (j=0; j < C; j++)
                     SetClusterValue(DCD->Drive, j+i-C, 0);
                  UpdateClusterWatermark(DCD->Drive, i, C);
               }
               break;
            }
         }
         State = !State;
         C = 0;
      }
      C++;
   }
}

/*-----------------------------------*/
int RTFAPI RTFCheckDisk(const WCHAR * DriveName,
                        void * Buffer,
                        UINT BufferSize,
                        RTFCheckDiskCallback ErrorHandler,
                        kal_uint32 Flags)
{
   RTFile * volatile f = NULL;
   DiskCheckData * DCD;
   int result = RTF_NO_ERROR;

   if (DriveName == NULL) return RTF_PARAM_ERROR;

   if (ErrorHandler == NULL)
      ErrorHandler = (RTFCheckDiskCallback) DummyChkDskHandler;

   #if !defined(__FS_SLIM_CHECK_DISK__)
   if ((Buffer == NULL) || (BufferSize < RTFCheckDiskBufferSize(DriveName)))
      return MT_FAIL_GET_MEM;
   #endif

   DCD = Buffer;
   DCD->Flags = Flags;
   DCD->S = (void*) (DCD+1);
   DCD->ErrorHandler = ErrorHandler;

   XTRY
      case XCODE:
         f = ParseFileName((char *)DriveName);

         if ((f->Drive == NULL) || (f->SpecialKind == PhysicalDisk))
         {
            fs_util_trace_err_noinfo(RTF_INVALID_FILENAME);

            XRAISE(RTF_INVALID_FILENAME);
         }

         f->Flags = RTF_READ_WRITE;
         f->SpecialKind = Volume;
         CheckSharing(f);

         if (f->Drive->MountState < HasFileSystem)
         {
            fs_util_trace_err_noinfo(RTF_INVALID_FILE_SYSTEM);

            XRAISE(RTF_INVALID_FILE_SYSTEM);
         }

         DCD->Drive = f->Drive;
         DCD->ClusterMap = (void*) (DCD->S + DCD->Drive->Dev->DevData.SectorSize);

         #if 0  // [Slim] RTF_CHK_FAT_MISMATCH_MASK is not enabled currently
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

         if (Flags & (RTF_CHK_FILESIZE_SMALL_MASK | RTF_CHK_FILESIZE_LARGE_MASK | RTF_CHK_INVALID_DIR_MASK | RTF_CHK_LOST_CLUSTER_MASK | RTF_CHK_CROSSLINK_MASK))
         {
            RTFDirEntry Root;

            MakePseudoRootDirEntry(DCD->Drive, &Root);
            DCD->D = Root.Dir;

            DCD->Path[0] = MT_BASE_DRIVE_LETTER + (f->Drive - gFS_Data.DriveTable);
            DCD->Path[1] = 0;
            DCD->Path[2] = ':';
            DCD->Path[3] = 0;
            DCD->Path[4] = '\0';
            DCD->Path[5] = 0;

            kal_mem_set(DCD->ClusterMap, 0, DCD->Drive->Clusters / 8 + 1);

            if (CheckDir(DCD, &Root.LongPos, &Root.ShortPos, 0) == RTF_CHECKDISK_RETRY)
            {
               result = RTF_CHECKDISK_RETRY;
               goto RTFCheckDisk_done;
            }

            if (Flags & RTF_CHK_LOST_CLUSTER_MASK)
            {
               CallChkDskCallback(DCD, RTF_CHK_VERBOSE, "searching lost clusters...", NULL, 0, 0);
               CheckLostClusters(DCD);
            }
         }

RTFCheckDisk_done:
        FlushAllBuffers(DCD->Drive->Dev);

      default:
         break;
      case XFINALLY:
         if (f) FreeFTSlotAndDevice(f);
   XEND_API
   return result;
}

/*-----------------------------------*/
#define CHKFLAGNOTFOUND 0
#define CHKFLAGEXIST 1

/*-----------------------------------*/
static int RTFRecoverFlashDisk(WCHAR *DriveName)
{
   int checkbytes = RTFCheckDiskBufferSize((const WCHAR*) DriveName);
   char* checkbuffer;
   int result = RTF_NO_ERROR;

   checkbuffer = (char*)kal_tmp_mem_alloc(checkbytes);

   if(checkbuffer)
   {
      do {
          result = RTFCheckDisk((const WCHAR*) DriveName, (void *)checkbuffer, checkbytes, MTKChkDskHandler, \
                                   RTF_CHK_INVALID_DIR     | \
                                   RTF_CHK_INVALID_CLUSTER | \
                                   RTF_CHK_CROSSLINK       | \
                                   RTF_CHK_FILESIZE_SMALL  | \
                                   RTF_CHK_FILESIZE_LARGE  | \
                                   RTF_CHK_LONG_FILENAME   | \
                                   RTF_CHK_LOST_CLUSTER      \
                         );

          if (result != RTF_CHECKDISK_RETRY) break;
       } while (1);

       kal_tmp_mem_free(checkbuffer);
   }
   else
   {
       result = RTF_GENERAL_FAILURE;
   }

   return result;
}

/*-----------------------------------*/
int RTFAPI RTFCheckBootUpFlag(void)
{
   int volatile retval =  CHKFLAGNOTFOUND;
   RTFDrive * Drive;
   RTFCluster cvalue;

   XTRY
      case XCODE:
         Drive = LocateDrive((BYTE)DrvMappingOld - MT_BASE_DRIVE_LETTER, HasFileSystem, 0);
         SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Drive->Dev, RTF_INFINITE);
         if (Drive->MountState < HasFileSystem)
         {
            break;
         }

         /* set gMT_Sanity to bypass parameter checking in GetClusterValue */
         gMT_Sanity = KAL_TRUE;
         cvalue = GetClusterValue(Drive, 1);
         gMT_Sanity = KAL_FALSE;
         switch(Drive->FATType)
         {
            case RTFAT12:
               if (cvalue & 0x800)
               {
                  retval = CHKFLAGEXIST;
               }
               break;
            case RTFAT16:
               if (cvalue & 0x8000)
               {
                  retval = CHKFLAGEXIST;
               }
               break;
#if !defined(__NOT_SUPPORT_FAT32__)
            case RTFAT32:
               if (cvalue & 0x08000000)
               {
                  retval = CHKFLAGEXIST;
               }
               break;
#endif /* __NOT_SUPPORT_FAT32__ */
            default:
               break;
         }
         break;
      default:
         break;
      case XFINALLY:
         SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV);
         break;
   XEND_API

   return retval;
}

/*-----------------------------------*/
int RTFAPI RTFSetBootUpFlag(kal_bool bSet)
{
   int Result = RTF_NO_ERROR;
   RTFDrive * Drive;
   RTFCluster ovalue;

   XTRY
      case XCODE:
         Drive = LocateDrive((BYTE)DrvMappingOld - MT_BASE_DRIVE_LETTER, HasFileSystem, 0);  // &gFS_Data.DriveTable[(BYTE)DrvMappingOld - MT_BASE_DRIVE_LETTER];
         SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Drive->Dev, RTF_INFINITE);
         if (Drive->MountState < HasFileSystem)
         {
            break;
         }

         gMT_Sanity = KAL_TRUE;
         FlushAllBuffers(Drive->Dev); // to avoid FAT or file content error
         ovalue = GetClusterValue(Drive, 1);
         if (bSet == KAL_TRUE)
         {
            switch(Drive->FATType)
            {
               case RTFAT12:   ovalue  |=      0x800; break;
               case RTFAT16:   ovalue  |=     0x8000; break;
#if !defined(__NOT_SUPPORT_FAT32__)
               case RTFAT32:   ovalue  |= 0x08000000; break;
#endif /* __NOT_SUPPORT_FAT32__ */
               default:                               break;
            }
         }
         else
         {
            switch(Drive->FATType)
            {
               case RTFAT12:   ovalue  &=     ~0x800; break;
               case RTFAT16:   ovalue  &=    ~0x8000; break;
#if !defined(__NOT_SUPPORT_FAT32__)
               case RTFAT32:   ovalue  &=~0x08000000; break;
#endif /* __NOT_SUPPORT_FAT32__ */
               default:                               break;
            }
         }

         SetClusterValue(Drive, 1, ovalue);
         gMT_Sanity = KAL_FALSE;
         FlushAllBuffers(Drive->Dev);
         break;
      default:
         break;
      case XFINALLY:
         SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV);
         break;
   XEND_API

/* Add for SHADOW FAT, Karen Hsu, 2005/05/11, ADD START */
#if (defined(__FS_SHADOW_NAND__) || defined(__FS_SHADOW_CARD__))
   if(bSet==KAL_FALSE)
   {
      FlushShadowFAT();
   }
#endif
/* Add for SHADOW FAT, Karen Hsu, 2005/05/11, ADD END */

   return Result;
}

/*-----------------------------------*/
int RTFAPI RTFSanityCheck(void)
{
   int result;
   WCHAR drivename[4] =  {'Z', ':', '\\', 0};   // default drive is Z (system drive)

   result = RTFCheckBootUpFlag();

   /* oops! bootup flag is found, the system is not correctly shutdown before! */
   if (result == CHKFLAGEXIST)
   {
     //=== 1. Recover System Drive
     gMT_Sanity = KAL_TRUE;
     result = RTFRecoverFlashDisk(drivename);

     if (result != RTF_NO_ERROR)
     {
        gMT_Sanity = KAL_FALSE;
        return result;
     }

     #if (defined(__NANDFDM_MULTI_INSTANCE__) && defined(__NAND_FDM_50__))
     /*
      * Recover ROOT and Backup disk for customer __TC01__ (W10.31)
      */

     //=== 2. Recover ROOT disk (Must sync with MTGetDrive)

     drivename[0] = L'D';
     result = RTFRecoverFlashDisk(drivename);

     if (result != RTF_NO_ERROR)
     {
        gMT_Sanity = KAL_FALSE;
        return result;
     }

     //=== 3. Recover Backup disk (Must sync with MTGetDrive)

     drivename[0] = L'G'; // Backup disk
     result = RTFRecoverFlashDisk(drivename);

     if (result != RTF_NO_ERROR)
     {
        gMT_Sanity = KAL_FALSE;
        return result;
     }
     #endif // __NANDFDM_MULTI_INSTANCE__ && __NAND_FDM_50__

     gMT_Sanity = KAL_FALSE;
   }
   /* congratulations! disk was correctly shutdown, set boot-up flag. */
   else
   {
      result = RTFSetBootUpFlag(KAL_TRUE);
   }

   /* kick watchdog timer */
   fs_util_wdt_restart();

   return result;
}

#endif // CHECK_DISK_SUPPORT
/*------------------------------------------------------------------ */
int RTFAPI MTMappingDrive(kal_uint32 UpperOldDrv, kal_uint32 UpperNewDrv)
{
   if(RTFLock == NULL)
      return RTF_DRIVE_NOT_READY;

   if((UpperOldDrv < 67) || (UpperOldDrv > (FS_MAX_DRIVES + MT_BASE_DRIVE_LETTER - 1)) ||
      (UpperNewDrv < (FS_MAX_DRIVES + MT_BASE_DRIVE_LETTER)) || (UpperNewDrv > 90) || (UpperNewDrv == 88))
      return RTF_PARAM_ERROR;

   SafeLock(MT_LOCK_RTF, NULL, RTF_INFINITE);
   DrvMappingOld = UpperOldDrv;
   DrvMappingNew = UpperNewDrv;
   SafeUnlock(MT_LOCK_RTF);
   return RTF_NO_ERROR;
}

/*------------------------------------------------------------------ */
#ifdef __FS_TRACE_SUPPORT__

//const char UNKNOWN_TASK_NAME[] = "UND";

/*******************************************************************//**
 * Make and print FS trace
 *
 * @par Category:
 * File System
 *
 * @par Change Log:
 * W09.09: Bug fix - Fix incorrect tail handling for TraceStrBuf when TraceStr is very long. (Stanley Chu)
 **********************************************************************/
void RTFAPI MTTraceFS(kal_uint32 TaskId, kal_uint32 FileCode, kal_uint32 Line, int Code,
                      RTFile * f, BYTE * TraceStr)
{
#if 0
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
}

#endif /* __FS_TRACE_SUPPORT__ */

/* ------------------------------------------------------------------------------- */
#ifdef __FS_QM_SUPPORT__

/* Get the specific quota entry from gFS_IntQuotaSet */
static void GetQuotaEntry(int * Index, RTFile * f)
{
   int i, j, k;

   /*
    * This API can accept f->FullName[0] == 'Z' or f->FullName[0] == DriveMappingOld
    */

   fs_assert_local(f != NULL);

   for(i = FS_MAX_QSET - 1 ; i >= 0 ; i--)
   {
      for(j = 0; j < RTF_MAX_PATH - 2; j++) // !NOTE! Do not over-run Path below
      {
         if ((j & 0x01) && (f->FullName[j] != 0x00)) break; // Quota path can't contain non-ASCII char, that is, high-byte of a WCHAR should be zero.
         else k = j / 2;

         if (gFS_IntQuotaSet[i].Path[k] == 0x00) // Match! Quota path (0) is terminated.
         {
            // because Quota Path must be ended with "\\" (checked by ChkQuotaConfig), therefore this condition must imply f->FullName is belong to this quota folder.
            *Index = i;
            return;
         }

         if (f->FullName[j] == 0x00)
         {
            if (f->FullName[j + 1] == 0x00)
            {
               if (gFS_IntQuotaSet[i].Path[k + 1] == 0x5C) // Match! Both f->FullName (0) and Path ('\\') is terminated.
               {
                  *Index = i;
                  return;
               }

               break;
            }

            // else
            // skip high byte of WCHAR (zero)
         }
         else
         {
            if (gFS_IntQuotaSet[i].Path[k] != 0x00)
            {
               if (k || j)
               {
                  if (gFS_IntQuotaSet[i].Path[k] != f->FullName[j])
                     break;
               }
               else if (gFS_IntQuotaSet[i].Path[k] == (BYTE)DrvMappingNew) // k == 0 && j == 0
               {
                  if((BYTE)DrvMappingOld != f->FullName[j])
                     break;
               }
            }
         }
      }
   }
   *Index = -1; //nothing match
}

#endif

/* ------------------------------------------------------------------------------- */
#ifdef __FS_QM_SUPPORT__

static int QMPermitAllocate(UINT DriveFree, int Index, UINT NeedCluster)
{
   int i, RFS_for_Other = 0, FreeSpace1, FreeSpace2, FreeSpace;

   /* Case 1. quota index is NOT specified, check RFS for ALL quota sets */
   if(Index < 0) //Count all RFS
   {
      for(i = FS_MAX_QSET - 1 ; i >= 0 ; i--)
      {
         if(gFS_IntQuotaSet[i].Qmin > gFS_IntQuotaSet[i].Uint)
            RFS_for_Other += (gFS_IntQuotaSet[i].Qmin - gFS_IntQuotaSet[i].Uint);
      }
      FreeSpace = (DriveFree > RFS_for_Other) ? (DriveFree - RFS_for_Other) : 0;
      goto QMPermitAllocateReturn;
   }

   /* Case 2. quota index is specified */

   /* check Qmax, if NOT enough, raise MT_APP_QUOTA_FULL */
   if(gFS_IntQuotaSet[Index].Qmax)
   {
      if((gFS_IntQuotaSet[Index].Uint + NeedCluster) > gFS_IntQuotaSet[Index].Qmax)
         return MT_APP_QUOTA_FULL;
   }

   /* calculate other quota sets' RFS */
   for(i = FS_MAX_QSET - 1 ; i >= 0 ; i--)
   {
      if(i != Index)
      {
         if(gFS_IntQuotaSet[i].Qmin > gFS_IntQuotaSet[i].Uint)
            RFS_for_Other += (gFS_IntQuotaSet[i].Qmin - gFS_IntQuotaSet[i].Uint);
      }
   }

   /*-----------------------------------------------------------------
    *                     Quota Management Policy
    * If disk free space > RFS for other folders, allocate it.
    * else
    *   1. Apply "first-in-first-satisfy-its-Qmin" policy to users that
    *      do not reach its Qmin yet.
    *   2. If user has reached its Qmin, FS_DISK_FULL will be returned.
    *-------------------------------------------------------- W09.13 -*/

   /* get maximum free space that the specified quota set can use considering RFS for others */
   FreeSpace1 = (DriveFree > RFS_for_Other) ? (DriveFree - RFS_for_Other) : 0;

   if (FreeSpace1 > 0)
   {
      if(gFS_IntQuotaSet[Index].Qmax)
      {
         FreeSpace2 = gFS_IntQuotaSet[Index].Qmax - gFS_IntQuotaSet[Index].Uint;
         FreeSpace = (FreeSpace1 > FreeSpace2) ? FreeSpace2 : FreeSpace1; // min
      }
      else // FS_QMAX_NO_LIMIT
         FreeSpace = FreeSpace1;
   }
   else
   {
      FreeSpace2 = gFS_IntQuotaSet[Index].Qmin - gFS_IntQuotaSet[Index].Uint;

      if (FreeSpace2 <= 0)  // Qnow > Qmin, can't allocate anymore unless disk size > RFS
      	 return RTF_DISK_FULL;

      FreeSpace = (FreeSpace2 < DriveFree) ? FreeSpace2 : DriveFree; // min
   }

#if 0 // old policy, replaced since W09.12
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

QMPermitAllocateReturn:
   if(NeedCluster <= FreeSpace)
      return RTF_NO_ERROR;

   return MT_APP_QUOTA_FULL;
}

#endif

/* ------------------------------------------------------------------------------- */
UINT RTFAPI GetFirstSector(WCHAR * FileName, void * SectorContent, UINT *Sector1, UINT *Sector2)
{
   int volatile Result = RTF_NO_ERROR;
   RTFile * volatile f;
   UINT Cluster, NextCluster;

   XTRY
      case XCODE:
         f = ParseFileName((char *)FileName);

#ifndef __P_PROPRIETARY_COPYRIGHT__
         if (f->SpecialKind != NormalFile)
         {
            XRAISE(RTF_INVALID_FILENAME);
         }

         if (!SearchFile(f, SEARCH_FILES|SEARCH_RELEASE_LOCK, (char *)FileName, NULL))
            XRAISE(RTF_PATH_NOT_FOUND);
#else
/* under construction !*/
#endif

         Cluster = FIRST_FILE_CLUSTER(f->DirEntry.Dir);

         if ((Cluster < 2) || (Cluster == RTF_ROOT_DIR))    {
             fs_util_trace_info0(TRACE_ERROR | MT_TRACE_INFO_WSTR, FS_INFO_DISK_ERROR, FileName);
             XRAISE(FS_BAD_DIR_ENTRY); //maybe empty file or root file
         }

         *Sector1 = CLUSTER_TO_SECTOR(f->Drive, Cluster);
         rtf_core_read_sectors(f->Dev, SectorContent, *Sector1, 1, 0);
         NextCluster = GetClusterValue(f->Drive, Cluster);
         if (NextCluster < RTF_CLUSTER_CHAIN_END)
            *Sector2 = CLUSTER_TO_SECTOR(f->Drive, NextCluster);
         else
            *Sector2 = 0xFFFFFFFF;
         break;
      default:
         Result = XVALUE;
         break;
      case XFINALLY:
         if (f)
            FreeFTSlot(f);
#ifndef __P_PROPRIETARY_COPYRIGHT__  //speedup
         SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV);
#endif
         break;
   XEND_API
   return Result;
}

/* ------------------------------------------------------------------------------- */
int SetCopyrightEntry(RTFDirLocation *lFS_CopyrightLongPos, RTFDirLocation *lFS_CopyrightShortPos,
                       RTFDOSDirEntry *lFS_CopyrightDir)
{
#ifdef __P_PROPRIETARY_COPYRIGHT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
   return RTF_NO_ERROR;
}
/* ------------------------------------------------------------------------------- */
/* For Virtual File Feature */

static void INTERN ToWsHexString(WCHAR * Name, kal_uint32 TimeStamp)
// write 8 hex digits, no zero termination
{
   UINT i;

   for (i=0; i<8; i++)
   {
      Name[7-i] = dchar_HexDigits[TimeStamp & 0xF];
      TimeStamp >>= 4;
   }
}
static int INTERN RestoreWsHexString(WCHAR * Name, kal_uint32 *value) // inverse of ToWsHexString()
{
   UINT v,i;
   WCHAR *p;

   for (i=0, v=0; i<8; i++)
   {
      p = kal_wstrchr( dchar_HexDigits, (int) Name[i] );
      if( p == NULL )
      {
         return KAL_FALSE;
      }
      v += (UINT)(p - dchar_HexDigits);
      if( i<7 ) // not last run
      {
         v <<= 4;
      }
   }
   *value = v;
   return KAL_TRUE;
}

int MTGenVirtualFileName(RTFHANDLE File, WCHAR * VFileNameBuf, UINT BufLength, UINT VFBeginOffset, UINT VFValidLength)
{
   RTFile * volatile f = NULL;
   WCHAR *VFNptr;
   UINT FillStrLength, CheckSum;
   XTRY
      case XCODE:
         f = ParseFileHandle(File);
         /* GenVirtual - 1 : check valid input (type, access, region)*/
         if ((f->SpecialKind != NormalFile) ||
             (FIRST_FILE_CLUSTER(f->DirEntry.Dir) == RTF_ROOT_DIR) ||
             (f->DirEntry.Dir.Attributes & RTF_ATTR_DIR) ||
             (f->DirEntry.Dir.FileSize <= VFBeginOffset) ||
             (f->DirEntry.Dir.FileSize <  VFBeginOffset+VFValidLength) )
         {
            fs_util_trace_err_noinfo(RTF_PARAM_ERROR);

            XRAISE(RTF_PARAM_ERROR);
         }

         if ( (f->Flags & (RTF_READ_ONLY | RTF_OPEN_SHARED) ) != (RTF_READ_ONLY | RTF_OPEN_SHARED) )
         {
            fs_util_trace_err_noinfo(RTF_ACCESS_DENIED);

            XRAISE(RTF_ACCESS_DENIED);
         }


         /* GenVirtual - 2 : Generate FileName and Write Back The Buffer */
         FillStrLength = kal_wstrlen( dchar_virtual_filename_prefix );
         if( BufLength < FillStrLength * sizeof(WCHAR) + ( 9 * sizeof(WCHAR) ) * 4 ) /* 92 */
         {
            fs_util_trace_err_noinfo(RTF_STRING_BUFFER_TOO_SMALL);

            XRAISE(RTF_STRING_BUFFER_TOO_SMALL);
         }

         VFNptr = kal_wstrncpy( VFileNameBuf, dchar_virtual_filename_prefix, FillStrLength );
         /* FillStrLength = kal_wstrlen( VFileNameBuf ); */
         BufLength -= FillStrLength;
         VFNptr += FillStrLength;

         #define VIRTUAL_NAME_BUF_PROCESS_NEXT  VFNptr[8] = 0x5c; VFNptr += 9; BufLength -= 9* sizeof(WCHAR)
         ToWsHexString( VFNptr, (kal_uint32) File);
         VIRTUAL_NAME_BUF_PROCESS_NEXT;

         CheckSum = FIRST_FILE_CLUSTER(f->DirEntry.Dir);
         ToWsHexString( VFNptr, (kal_uint32) CheckSum);
         VIRTUAL_NAME_BUF_PROCESS_NEXT;

         ToWsHexString( VFNptr, (kal_uint32) VFBeginOffset);
         VIRTUAL_NAME_BUF_PROCESS_NEXT;

         ToWsHexString( VFNptr, (kal_uint32) VFValidLength);
         VIRTUAL_NAME_BUF_PROCESS_NEXT;

         VFNptr --; VFNptr[0] = 0x0;
         fs_assert_local( ((int) BufLength) >= 0 ); // if fail, it's logical error inside, not caller's fault

      default:
         break;
      case XFINALLY:
         if (f != NULL)
            UnlockDevice(f->Dev);
         break;
   XEND_API
   return RTF_NO_ERROR;
}

static void INTERN SetupFMapF_FileHandle(RTFile *f)
{
   RTFHANDLE  Identity;
   RTFile *LargeFileTable;
   WCHAR *name_ptr;

   /* SetupFMapF 1 --- Get LargeFileTable and make sure it does exist */
   name_ptr =  (WCHAR*) f->FullName;
   name_ptr += kal_wstrlen( dchar_virtual_filename_prefix );
   if( RestoreWsHexString( name_ptr, (kal_uint32*) &Identity ) != KAL_TRUE )
   {
      goto INVALID_FILENAME_EXIT;
   }
   LargeFileTable = ParseFileHandle( Identity ); /* Lock Device Here */
   f->DirEntry.LongPos.Index = (UINT) Identity;
   // borrow the DirEntry.LongPos.Index as LargeFile RTFile Pointer

   f->Dev = LargeFileTable->Dev;
   f->Drive = LargeFileTable->Drive;

   /* SetupFMapF 2 --- Reterieve Other Parameters,  CheckSum match*/
   name_ptr += 9;
   if( RestoreWsHexString( name_ptr, (kal_uint32*) &Identity ) != KAL_TRUE
    || FIRST_FILE_CLUSTER(LargeFileTable->DirEntry.Dir) != Identity )
   {
      goto INVALID_FILENAME_EXIT;
   }
   f->DirEntry.Dir.Attributes = LargeFileTable->DirEntry.Dir.Attributes;
   SET_FIRST_FILE_CLUSTER(f->DirEntry.Dir, Identity); // setup for InitFilePointer(),

   /* get the Begin Pos */
   name_ptr += 9;
   if( RestoreWsHexString( name_ptr, (kal_uint32*) &Identity ) != KAL_TRUE )
   {
      goto INVALID_FILENAME_EXIT;
   }
   f->DirEntry.ShortPos.Index = Identity;
   // borrow the DirEntry.ShortPos.Index as Begin Position

   /* Setup the FIRST_FILE_CLUSTER and Length */
   name_ptr += 9;
   if( RestoreWsHexString( name_ptr, (kal_uint32*) &Identity ) != KAL_TRUE
    || (name_ptr[8]!=0x0 && name_ptr[8]!=0x2e) /* Allow dot tail for user append extension name*/ )
   {
      goto INVALID_FILENAME_EXIT;
   }

   /* Last, We copy the Parent FileName as Long as Possible For Debug */
   name_ptr = (WCHAR*) f->FullName + kal_wstrlen( (WCHAR*)f->FullName );
   kal_wstrncpy( name_ptr, (WCHAR*)LargeFileTable->FullName, RTF_MAX_PATH/sizeof(WCHAR) - kal_wstrlen( (WCHAR*) f->FullName) - 1 );

   /* SetupFMapF 3 --- Fill File Table members , Search my first cluster first */
   InitFilePointer( f );
   MoveFilePointer( f, f->DirEntry.ShortPos.Index );

   /* Now we have reach the VF Begin */
   f->DirEntry.ShortPos.Index = f->Offset; /* This member is brrowed as the Bias offset */
   SET_FIRST_FILE_CLUSTER(f->DirEntry.Dir, f->Cluster); /* This is the first cluster of VF */
   f->FilePointer = f->Offset; /* Reset FilePointer */
   f->DirEntry.Dir.FileSize = f->Offset + Identity; /* Setup the FileSize (biased) */
   f->LastCluster = 0;

   return;
INVALID_FILENAME_EXIT:

   fs_util_trace_err_noinfo(RTF_INVALID_FILENAME);

   XRAISE(RTF_INVALID_FILENAME);
}

static int MTChkMapedFH(RTFHANDLE File)
{  UINT U = File >> (4*sizeof(int));
   UINT i = File & ((1 << (4*sizeof(int))) - 1);
   RTFile * maped_ft;

   if (i >= FS_MAX_FILES)
   {
      return (MT_VF_MAP_ERROR);
   }
   maped_ft = gFS_Data.FileTable + i;
   if (maped_ft->Lock == 0 || maped_ft->Unique != U || maped_ft->Dev == NULL)
   {
      return (MT_VF_MAP_ERROR);
   }
   return RTF_NO_ERROR;
}


int RTFAPI BatchCountFreeClusters(RTFDrive * Drive)
{
   RTFCluster FreeCount, CurrCluster;
   RTFCluster Watermark=RTF_INVALID_CLUSTER;
   kal_uint32 CurrSector;
   RTFCluster BaseCluster, TillCluster, CurrClusterValue;
   BYTE*      buffer = NULL;
   volatile int i, factor;
   int        sector_cnt_in_buffer;          // the number of sectors in a buffer
   int        buffer_size;
   #ifdef __FS_DEDICATED_BUFFER__
   char       dedicated_buffer_allocated = 0; // indicate if internal buffer is used
   #endif // __FS_DEDICATED_BUFFER__
   #ifdef __FS_NOR_IDLE_SWEEP__
   char       need_discard_sectors = 0;
   #endif // __FS_NOR_IDLE_SWEEP__

   #ifdef __FS_NOR_IDLE_SWEEP__
   if (Drive->Dev->DeviceFlags & FS_DEVICE_NOR_FLASH && Drive->Dev->Driver->DiscardSectors)
   {
      need_discard_sectors= 1;
   }
   #endif // __FS_NOR_IDLE_SWEEP__

   /* FAT12 uses sequential way */
   if (Drive->FATType == 12 || INT_QueryExceptionStatus() == KAL_TRUE)
   {
      /* BatchCountFreeClusters - 1 , FAT12 only 12 Sectors maximum, fallback to non-batch way */
SequentialWay:
      for (FreeCount=0, CurrCluster = 2; CurrCluster < Drive->Clusters; CurrCluster++)
      {
         CurrClusterValue = fs_srv_get_cluster_value(Drive, CurrCluster, FS_GET_CLUSTER_RAW, GetBuffer);

         if (CurrClusterValue == 0)
         {
            FreeCount++;

            if (Watermark == RTF_INVALID_CLUSTER)
            {
               Watermark = CurrCluster;
            }

            #ifdef __FS_NOR_IDLE_SWEEP__
            if (need_discard_sectors)
            {
               DiscardSectors(Drive->Dev, CLUSTER_TO_SECTOR(Drive, CurrCluster), Drive->SectorsPerCluster);
            }
            #endif // __FS_NOR_IDLE_SWEEP__
         } /* if (CurrClusterValue == 0) */

         if (Drive->Dev->DeviceFlags & RTF_DEVICE_BUSY_READ_ONLY)
         {
            UnlockDevice(Drive->Dev);
            LockDevice(Drive->Dev, FS_NOBUSY_CHECK_MODE);
         }

         if (Drive->Dev->DevData.Reserved & FS_DEVICE_ABORT_COUNT_FREE_CLUSTER)
         {
            XRAISE(FS_DEVICE_EXPORTED_ERROR);
         }
      }
      goto BatchExit;
   }

   /*------------------------------------------------------
    * Other FAT types use batch way
    * FAT12 can't use batch way because the number of clusters always can't be aligned
    * to the dedicated buffer. The boundary handling will be very tricky.
    *------------------------------------------------------*/

   /* BatchCountFreeClusters - 2 , Deal Buffer allocation */

   #ifdef __FS_DEDICATED_BUFFER__
   buffer_size = MTBufAlloc(FS_BUFF_SIZE_COUNT_FREE_CLUSTER, &buffer, FS_INT_DBUF_ALLOC_PRECISE);

   if (buffer_size >= FS_BUFF_SIZE_COUNT_FREE_CLUSTER)
   {
      dedicated_buffer_allocated = 1;
   }
   else
   #endif /* __FS_DEDICATED_BUFFER__ */
   {
      buffer_size = FS_DEFAULT_BUFF_SIZE_COUNT_FREE_CLUSTER;
      buffer = (BYTE *)get_ctrl_buffer(buffer_size);  // 2 KB buffer allocated from control buffer
   }

   sector_cnt_in_buffer = buffer_size / Drive->Dev->DevData.SectorSize;

   if (buffer == NULL)
      goto SequentialWay;

   /* FirstFATSector ... > FirstFATSector + SectorsPerFAT */

   /* calculate the number of cluster values in a sector-sized buffer */
   factor = Drive->Dev->DevData.SectorSize * 8 / Drive->FATType;

   for (FreeCount=0, CurrCluster=2, CurrSector=0; CurrSector < Drive->SectorsPerFAT; )
   {
      int result;

      /* BatchCountFreeClusters - 3 , Get buffer-size-aligned page and fill buffer */
      i = sector_cnt_in_buffer - (CurrSector + Drive->FirstFATSector) % sector_cnt_in_buffer;  /* reuse variable int i */
      result = rtf_core_read_sectors(Drive->Dev, buffer, Drive->FirstFATSector + CurrSector, i, NO_RAISE);

      if (result < RTF_NO_ERROR)
      {
         #ifdef __FS_DEDICATED_BUFFER__
         if (dedicated_buffer_allocated)
            MTBufFree(buffer_size, &buffer);
         else
         #endif /* __FS_DEDICATED_BUFFER__ */
            free_ctrl_buffer(buffer);

         XRAISE(result);
      }

      /* BatchCountFreeClusters - 4 , MARK Begin and End Cluster Number */
      BaseCluster = CurrSector * factor;
      CurrSector += i;
      TillCluster = CurrSector * factor;
      TillCluster = (TillCluster > Drive->Clusters) ? Drive->Clusters : TillCluster;

      /* BatchCountFreeClusters - 5 , Traverse The Buffer */
      for (; CurrCluster < TillCluster; CurrCluster++)
      {
         if (Drive->FATType == 16)
         {
            WORD * FATPtr = (WORD *) buffer;
            CurrClusterValue = FATPtr[CurrCluster - BaseCluster];
         }
         else if (Drive->FATType == 32)
         {
            kal_uint32 * FATPtr = (kal_uint32 *) buffer;
            CurrClusterValue = FATPtr[CurrCluster - BaseCluster];
         }
         else
         {
            fs_err_internal_fatal(FS_ERR_CLUSTER_05, NULL);
            break;
         }

         if (CurrClusterValue == 0)
         {
            FreeCount++;

            if (Watermark == RTF_INVALID_CLUSTER)
            {
               Watermark = CurrCluster;
            }

            #ifdef __FS_NOR_IDLE_SWEEP__
            if (need_discard_sectors)
            {
               DiscardSectors(Drive->Dev, CLUSTER_TO_SECTOR(Drive, CurrCluster), Drive->SectorsPerCluster);
            }
            #endif

         } /* if (CurrClusterValue == 0) */
      }

      if (Drive->Dev->DeviceFlags & RTF_DEVICE_BUSY_READ_ONLY)
      {
         UnlockDevice(Drive->Dev);
         LockDevice(Drive->Dev, FS_NOBUSY_CHECK_MODE);
      }

      if (Drive->Dev->DevData.Reserved & FS_DEVICE_ABORT_COUNT_FREE_CLUSTER)
      {
         #ifdef __FS_DEDICATED_BUFFER__
         if (dedicated_buffer_allocated)
            MTBufFree(buffer_size, &buffer);
         else
         #endif /* __FS_DEDICATED_BUFFER__ */
            free_ctrl_buffer(buffer);

         XRAISE(FS_DEVICE_EXPORTED_ERROR);
      }

   } /* For Sector 0 ... SectorsPerFAT */

   /* BatchCountFreeClusters - 6 , Deal Buffer Release */
   #ifdef __FS_DEDICATED_BUFFER__
   if (dedicated_buffer_allocated)
      MTBufFree(buffer_size, &buffer);
   else
   #endif /* __FS_DEDICATED_BUFFER__ */
      free_ctrl_buffer(buffer);

BatchExit:
   Drive->FreeClusterCount = FreeCount;
   Drive->ClusterWatermark = Watermark;

#if !defined(__NOT_SUPPORT_FAT32__)
   FATInitInfoSectorSubMark(Drive);
#endif /* __NOT_SUPPORT_FAT32__ */

   return RTF_NO_ERROR;
}

static RTFCluster INTERN FATSearchZeroInBuffer(RTFDrive *Drive, RTFCluster Cluster)
{
   RTFCluster NextZero;
   RTFCluster Result;

   switch (Drive->FATType)
   {
      case RTFAT12:
      {
         kal_uint32 Pos;
         UINT  B1, B2;
         BYTE  * FATPtr;

         Pos      = Cluster + Cluster / 2;     // 0 1 3 4 6 7 9 10 12 13
         NextZero = (((Pos >> Drive->Dev->DevData.SectorShift) + 1) << Drive->Dev->DevData.SectorShift) * 2 / 3;

         FATPtr   = GetBuffer(Drive->Dev, Drive->FirstFATSector + (Pos >> Drive->Dev->DevData.SectorShift), 0);

         /* Verify Case for 512B sector size : Cluster = 340, 341, 342, 682, 683, 1023, 1024 */
         while(Cluster < NextZero)
         {
            Pos   = Cluster + Cluster / 2;     // 0 1 3 4 6 7 9 10 12 13
            B1    = FATPtr[    Pos & (Drive->Dev->DevData.SectorSize-1)];
            B2    = FATPtr[(++Pos) & (Drive->Dev->DevData.SectorSize-1)];
            Result = (Cluster & 1) ? ((B2 << 4) | (B1 >> 4)) : (((B2 & 0x0F) << 8) | B1);
            if (Result == 0)
            {
               break; /* while (Cluster < NextZero) */
            }
            Cluster++;
         }

         return Cluster;
      }
      case RTFAT16:
      {
         WORD * FATPtr = GetBuffer(Drive->Dev, Drive->FirstFATSector + (Cluster >> (Drive->Dev->DevData.SectorShift-1)), 0);

         NextZero = ((Cluster >> (Drive->Dev->DevData.SectorShift-1)) + 1) << (Drive->Dev->DevData.SectorShift-1);

         while(Cluster < NextZero)
         {
            Result = FATPtr[Cluster & ((Drive->Dev->DevData.SectorSize >> 1)-1)];
            if (Result == 0)
            {
               break; /* while (Cluster < NextZero) */
            }
            Cluster++;
         }

         return Cluster;
      }
#if !defined(__NOT_SUPPORT_FAT32__)
      case RTFAT32:
      {
         kal_uint32 * FATPtr = GetBuffer(Drive->Dev, Drive->FirstFATSector + (Cluster >> (Drive->Dev->DevData.SectorShift-2)), 0);

         NextZero = ((Cluster >> (Drive->Dev->DevData.SectorShift-2)) + 1) << (Drive->Dev->DevData.SectorShift-2);

         while(Cluster < NextZero)
         {
            Result = FATPtr[Cluster & ((Drive->Dev->DevData.SectorSize >> 2)-1)] & 0x0FFFFFFF;
            if (Result == 0)
            {
               break; /* while (Cluster < NextZero) */
            }
            Cluster++;
         }

         return Cluster;
      }
#endif /* __NOT_SUPPORT_FAT32__ */

      default:
         fs_err_internal_fatal(FS_ERR_CLUSTER_06, NULL);
   }

   return Cluster;
}

#if !defined(__NOT_SUPPORT_FAT32__)
static void INTERN FATHoistSubMark(RTFDrive *Drive, RTFCluster Begin, RTFCluster End)
{
   if (Drive->InfoSector)
   {
      RTFFAT32InfoSector * IS = GetBuffer(Drive->Dev, Drive->InfoSector, 0);
      RTFCluster         * Map= (RTFCluster *) IS->Reserved;
      int                  Idx= Begin >> SUBMARK_ID_SHIFT;
      int                  IdxEnd = End >> SUBMARK_ID_SHIFT;

      /* Hoist - 0 : Input range : Begin (include) ~ End (NOT included) , contingous chain */
      IdxEnd = (IdxEnd > SUBMARK_LASTNUM) ? SUBMARK_LASTNUM : IdxEnd;
      Idx    = (Idx    > SUBMARK_LASTNUM) ? SUBMARK_LASTNUM : Idx;

      /* Hoist - 1 : There are 4 cases here
       *    1-A : Begin ~ End , at different segment => set first segment as full mark and
       *                                                check subwatermark of last segment
       *    1-B : Begin ~ End , at the same segment => set subwatermark as End Cluster
       *    1-C : !Begin ~ End, at the same segment => Do-nothing & return
       *    1-D : !Begin ~ End, at different segment => check subwatermark of last segment
       */
      if (Map[Idx] == Begin)
      {
         if (Idx != IdxEnd)
         {
            Map[Idx] = RTF_INVALID_CLUSTER;
            if (Map[IdxEnd] < End) Map[IdxEnd] = End;
         }
         else
            Map[Idx] = End;
      }
      else
      {
         if (Idx == IdxEnd)
            return;
         else if (Map[IdxEnd] < End)
            Map[IdxEnd] = End;
      }
      /* Hoist - 2 : Set full from (last - 1) segment to (first + 1) segment one by one */
      for (IdxEnd--;IdxEnd > Idx;IdxEnd--)
      {
         Map[IdxEnd] = RTF_INVALID_CLUSTER;
      }

      SetDirty(Drive->Dev);
   }
}

static void INTERN FATLowerSubMark(RTFDrive *Drive, RTFCluster Begin, RTFCluster End)
{
   if (Drive->InfoSector)
   {
      RTFFAT32InfoSector * IS = GetBuffer(Drive->Dev, Drive->InfoSector, 0);
      RTFCluster         * Map= (RTFCluster *) IS->Reserved;
      int                  Idx= Begin >> SUBMARK_ID_SHIFT;
      int                  IdxEnd = End >> SUBMARK_ID_SHIFT;

      /* Lower - 0 : Input range : Begin (include) ~ End (included) ; but may not contingus chain */
      IdxEnd = (IdxEnd > SUBMARK_LASTNUM) ? SUBMARK_LASTNUM : IdxEnd;
      Idx    = (Idx    > SUBMARK_LASTNUM) ? SUBMARK_LASTNUM : Idx;

      /* Lower - 1 : Review lowest segment , see if lower watermark required */
      if (Map[Idx] > Begin)
      {
         Map[Idx] = Begin;
      }
      /* Lower - 2 : Review (lowest + 1) ~ (highest) segment , reset watermark as init value */
      for (Idx++;Idx <= IdxEnd;Idx++)
      {
         Map[Idx] = (Idx << SUBMARK_ID_SHIFT) & SUBMARK_MASKOUT;
      }

      SetDirty(Drive->Dev);
   }
}

static void INTERN FATInitInfoSectorSubMark(RTFDrive *Drive)
{
   if (Drive->InfoSector && ((Drive->Dev->DeviceFlags & MT_DEVICE_WRITE_PROTECT) == 0))
   {
      RTFFAT32InfoSector * IS = GetBuffer(Drive->Dev, Drive->InfoSector, 0);
      RTFCluster         * Map= (RTFCluster *) IS->Reserved;
      int                  Idx= 0;
      int                  IdxEnd = Drive->Clusters >> SUBMARK_ID_SHIFT;

      for (; Idx <= SUBMARK_LASTNUM; Idx++)
      {
         if (Idx > IdxEnd)
         {  /* Fill remain submarks as 0x0 in Map */
            Map[Idx] = 0x0;
         }
         else if ((Drive->ClusterWatermark >> SUBMARK_ID_SHIFT) > Idx)
         {  /* Set known full segments submarks as 0xFFFFFFFF in Map */
            Map[Idx] = RTF_INVALID_CLUSTER;
         }
         else if ((Drive->ClusterWatermark >> SUBMARK_ID_SHIFT) == Idx)
         {  /* Set the one segments submarks as ClusterWatermark in Map */
            Map[Idx] = Drive->ClusterWatermark;
         }
         else
         {  /* Set the segments after ClusterWatermark submarks as Init Value in Map */
            Map[Idx] = (Idx << SUBMARK_ID_SHIFT) & SUBMARK_MASKOUT;
         }
      }
      SetDirty(Drive->Dev);
      /* Note: If Disk Full, ClusterWatermark = 0xFFFFFFFF,
       *       and all valid submark will be set to 0xFFFFFFFF, too.
       */
   }
}

static RTFCluster INTERN FATHintSearchBySubMark(RTFDrive * Drive, RTFCluster Cluster, int MarkFlag)
{
   if (Drive->InfoSector)
   {
      RTFFAT32InfoSector * IS = GetBuffer(Drive->Dev, Drive->InfoSector, 0);
      RTFCluster         * Map= (RTFCluster *) IS->Reserved;
      int                  Idx= Cluster >> SUBMARK_ID_SHIFT;

      if (Idx > SUBMARK_LASTNUM)
      {
         /* Oops, out of range */
         return Cluster;
      }

      if (MarkFlag)
      {
         /* True means the previous segment already full, set Full mark */
         fs_assert_local(Idx > 0);
         Map[Idx - 1] = RTF_INVALID_CLUSTER;
         SetDirty(Drive->Dev);
      }

      /* Hint Search loop */
      for (;Idx <= SUBMARK_LASTNUM; Idx++)
      {
         if (Map[Idx] == RTF_INVALID_CLUSTER)
         {  /* This Range alreay occupied */
            Cluster += (1 << SUBMARK_ID_SHIFT);
            continue;
         }
         if ((Map[Idx] >> SUBMARK_ID_SHIFT) == Idx)
         {  /* This watermark is trustable */
            return Map[Idx];
         }
         /* No more hint? back */
         break;
      }
   }
   return Cluster;
}
#endif /* __NOT_SUPPORT_FAT32__ */

void * RTFAPI MTProxyGetBuffer (RTFDevice * Dev, RTFSector Sector)
{
   return GetBuffer(Dev, Sector, 0);
}

kal_int32 MTSearchDirData(RTFDrive * drive, RTFCluster dir_cluster)
{
    kal_int32 i;

    for (i = 0; i < FS_DIRDATA_NUM; i++)
    {
        if (_gfs_dir_data[i].Drive == drive && _gfs_dir_data[i].Cluster == dir_cluster)

        return i;
    }

    return -1;
}

void RTFAPI MTExpireDirCacheByDrive(RTFDrive* drive)
{
    kal_int32   i;

    for (i = 0; i < FS_DIRDATA_NUM; i++)
    {
        if (_gfs_dir_data[i].Drive == drive)
        {
            _gfs_dir_data[i].Status |= FS_DIRDATA_MASK_EXPIRED; // set expire flag

            _gfs_dir_data[i].Status &= ~FS_DIRDATA_MASK_LOCKED; // clear lock flag because file handle will be set as MEDIA_CHANGED thus user can't unlock them by FS_DirCtrl.

            fs_util_trace_info4(TRACE_GROUP_6, FS_TRC_DIRCACHE_EXPIRE, i, (kal_uint32)drive, (kal_uint32)_gfs_dir_data[i].Cluster, _gfs_dir_data[i].Value, NULL);
        }
    }
}

kal_int32 RTFAPI MTExpireDirCacheValue(RTFDrive * drive, RTFCluster dir_cluster)
{
    kal_int32   i;

    i = MTSearchDirData(drive, dir_cluster);

    if (i >= 0)
    {
        _gfs_dir_data[i].Status |= FS_DIRDATA_MASK_EXPIRED;  // expire

        fs_util_trace_info4(TRACE_GROUP_6, FS_TRC_DIRCACHE_EXPIRE, i, (kal_uint32)drive, (kal_uint32)dir_cluster, _gfs_dir_data[i].Value, NULL);
    }

    #ifdef __FS_OPEN_HINT__
    OpenHintStamp = (OpenHintStamp + 1) & 0x7FFFFFFF; // The highest bit indicates if the hint is internal or external hint
    #else
    OpenHintStamp++;
    #endif /* __FS_OPEN_HINT__ */

    return i;
}

kal_int32 RTFAPI MTSetDirCacheValue(RTFDrive * drive, RTFCluster dir_cluster, kal_uint32 value)
{
    kal_int32   i, i_victim, i_hit, i_free;
    kal_uint32  time, time_min;
    kal_uint32  pre_locked = 0;

    for (i = 0, i_victim = -1, i_free = -1, i_hit = -1, time_min = FS_DIRDATA_MASK_TIME; i < FS_DIRDATA_NUM; i++)
    {
        if (i_free != -1 && _gfs_dir_data[i].Drive == 0)    // free entry is found
        {
            i_free = i;
        }

        if (_gfs_dir_data[i].Drive == drive && _gfs_dir_data[i].Cluster == dir_cluster) // entry is already existed
        {
            i_hit = i;

            if (_gfs_dir_data[i].Status & FS_DIRDATA_MASK_LOCKED)   // target is locked (it can't be replaced but its value can be changed). Keep lock status even if new value is set
            {
                pre_locked = 1;
            }

            break;
        }

        if ((_gfs_dir_data[i].Status & FS_DIRDATA_MASK_LOCKED) == 0)    // bypass locked entry
        {
            time = _gfs_dir_data[i].Status & FS_DIRDATA_MASK_TIME;      // get time stamp

            if (time < time_min)
            {
                i_victim = i;

                time_min = time;
            }
        }
    }

    if (i_hit != -1)     // set new value to existed entry
    {
        i_victim = i_hit;
    }
    else                // not hit
    {
        if (i_free != -1)   // free entry is found
        {
            i_victim = i_free;
        }

        // else, fall through to see if replacement victim is found
    }

    if (i_victim == -1) // no free entry or all entries are locked
    {
        fs_util_trace_err_noinfo(FS_ERR_DIRDATA_LOCKED);

        XRAISE(FS_ERR_DIRDATA_LOCKED);
    }
    else
    {
        time=kal_get_systicks();

        time = time & FS_DIRDATA_MASK_TIME;

        //time = kal_get_systicks() & FS_DIRDATA_MASK_TIME;   // get time stamp (W11.05)

        _gfs_dir_data[i_victim].Drive   = drive;
        _gfs_dir_data[i_victim].Cluster = dir_cluster;
        _gfs_dir_data[i_victim].Value   = value;
        _gfs_dir_data[i_victim].Status  = time; // reset expired flag

        if (pre_locked)
        {
            _gfs_dir_data[i_victim].Status |= FS_DIRDATA_MASK_LOCKED; // keep lock status
        }
    }

    fs_util_trace_info4(TRACE_FUNC, FS_TRC_DIRCACHE_SET, i_victim, (kal_uint32)_gfs_dir_data[i_victim].Drive, (kal_uint32)_gfs_dir_data[i_victim].Cluster, _gfs_dir_data[i_victim].Value, NULL);

    return i_victim;
}

kal_int32 RTFAPI MTGetDirCacheValue(RTFDrive * drive, RTFCluster dir_cluster, kal_uint32 * data)
{
    int i;

    i = MTSearchDirData(drive, dir_cluster);

    if (i >= 0 && ((_gfs_dir_data[i].Status & FS_DIRDATA_MASK_EXPIRED) == 0))   // hit && valid
    {
        *data = _gfs_dir_data[i].Value;

        fs_util_trace_info4(TRACE_FUNC, FS_TRC_DIRCACHE_GET, i, (kal_uint32)drive, (kal_uint32)dir_cluster, *data, NULL);
    }
    else
    {
        fs_util_trace_err_noinfo(FS_DIRCACHE_EXPIRED);

        XRAISE(FS_DIRCACHE_EXPIRED);
    }

    return i;
}

static int INTERN CopySectors(RTFDevice * Dev, RTFSector FromSector, RTFSector ToSector, UINT Sectors, kal_uint32 Flags)
{
   int volatile Result;

   RTFSYSFreeMutex(RTFLock);
   XTRY
      case XCODE:
         CheckMedia(Dev);

         if (Dev->DevData.ErrorCondition < RTF_NO_ERROR)
         {
            fs_util_trace_err_noinfo(Dev->DevData.ErrorCondition);
            fs_util_trace_info4(MT_TRACE_ERROR, FS_ERR_COPYSECTORS_DEV_ERROR, FromSector, ToSector, Sectors, NULL, NULL);

            XRAISE(Dev->DevData.ErrorCondition);
         }

         if (Dev->DevData.MountState < Mounted)
         {
            fs_util_trace_err_noinfo(RTF_DRIVE_NOT_READY);
            fs_util_trace_info4(MT_TRACE_ERROR, FS_ERR_COPYSECTORS_DEV_NOT_MOUNTED, FromSector, ToSector, Sectors, NULL, NULL);

            XRAISE(RTF_DRIVE_NOT_READY);
         }

         Result = Dev->Driver->CopySectors(Dev->DriverData, FromSector, ToSector, Sectors);

         /* Error Handling */
         if (Result < RTF_NO_ERROR)
         {
            fs_util_trace_err_noinfo(Result);
            fs_util_trace_info4(MT_TRACE_ERROR, FS_ERR_COPYSECTORS_DRIVER_FAILED, FromSector, ToSector, Sectors, NULL, NULL);

            XRAISE(Result);
         }
         break;
      default:
         if (((Flags & NO_CRITICAL) == 0) &&
             (HandleCriticalError(Dev, XVALUE) == RTFRetry))
         {
            XHANDLED;
            XREEXECUTE;
         }
         if (Flags & NO_RAISE)
         {
            Result = XVALUE;
            Dev->DevData.ErrorCondition = RTF_NO_ERROR;
            XHANDLED;
         }
         break;
      case XFINALLY:
         RTFSYSLockMutex(RTFLock, RTF_INFINITE);
         break;
   XEND
   return Result;
}

int MTCopyFileByClusterChain(RTFHANDLE FileDst, RTFCluster *ClustersArray, UINT ClusterNum)
{
   RTFile * volatile f = NULL;
   int written=0;
   UINT l;

   XTRY
      case XCODE:
         f = ParseFileHandle(FileDst);
         l = ClusterNum << (f->Drive->ClusterShift);
         while (l > 0)
         {
            UINT       n;      // number of bytes in segment
            RTFSector  S;      // sector to start writing at
            RTFSector  C;      // number of sectors in segment;
            RTFSector  R;      // sector to start copy from

            if (f->Cluster == 0) // end of file, allocate more
               ExtendFile(f, l, 0);

            S = CLUSTER_TO_SECTOR_DIR_OFS(f->Drive, f->Cluster, f->Offset);
            R = CLUSTER_TO_SECTOR_DIR_OFS(f->Drive, ClustersArray[written], 0);
            n = MoveFilePointerSegment(f, l);
            C = n >> f->Dev->DevData.SectorShift;

            // can write C sectors starting at S, but have to check
            // for any data in buffers

            DiscardBuffersRange(f->Dev, S, C, 0);   // discard without commit

            // issue Drive operation
            CopySectors(f->Dev, R, S, C, 0);

            // update iteration value
            written += n >> (f->Drive->ClusterShift);
            l -= n;
         }
         break;
      default:
         break;
      case XFINALLY:
         if (f != NULL)
         {
            if (f->FilePointer > f->DirEntry.Dir.FileSize)
            {
               f->DirEntry.Dir.FileSize = f->FilePointer;
            }
            RTFSYSGetDateTime(&f->DirEntry.Dir.DateTime);
            UpdateDirEntry(f);
            if (f->Flags & RTF_COMMITTED) FlushFAT(f->Dev);
            UnlockDevice(f->Dev);
         }
         break;
   XEND_API
   return written;
}

/**************************************************
 *  discard sector piece by piece
 **************************************************/
int RTFAPI CleanUpDataSectors(RTFDrive * Drive, RTFCluster *Start, int MaxClusters)
{
   RTFCluster MaxCN = *Start + MaxClusters;

   XTRY
      case XCODE:
         for (; *Start < MaxCN ; (*Start)++)
         {
            if (GetClusterValue(Drive, (*Start)) == 0)
            {
               DiscardSectors(Drive->Dev, CLUSTER_TO_SECTOR(Drive, (*Start)), Drive->SectorsPerCluster);
            }
         }
         break;
      default:
         break;
      case XFINALLY:
         break;
   XEND_API
   return RTF_NO_ERROR;
}

/*-----------------------------------*/
/* See also : CheckSharing() */
void RTFAPI MTCheckSharingWithSpecialKindFh(RTFile * File)
{
   UINT i;
   RTFile * f = gFS_Data.FileTable;

   // check if the special kind file is open and the access scope overlap without sharing
   for (i=0; i<FS_MAX_FILES; i++, f++)
   {
      if ((f != File) &&
          (f->Dev == File->Dev) &&
          (f->Valid == FS_FH_VALID) &&
          ((f->Flags & File->Flags & RTF_READ_ONLY) == 0) &&   // not both read only AND
          ((f->Flags & File->Flags & RTF_OPEN_SHARED) == 0) && // not both opend shared AND
          (((f->SpecialKind == PhysicalDisk) ||                // one of them is a device file OR
            (File->SpecialKind == PhysicalDisk)) ||
           ((f->Drive == File->Drive) &&                       // one volume and both go to the same drive
            ((f->SpecialKind == Volume) || (File->SpecialKind == Volume)))))
      {
         fs_util_trace_err_noinfo(RTF_ACCESS_DENIED);
         fs_util_trace_info2(TRACE_ERROR | MT_TRACE_INFO_TASK, FS_ERR_ACCESS_DENIED, f->OwnerLR, GetFileHandle(f), f);

         XRAISE(RTF_ACCESS_DENIED);
      }
   }
}

/*-----------------------------------*/
void RTFAPI MTToLowerString(WCHAR *FileName, UINT MaxLength)
{
   UINT i;

   for(i = 0 ; i < (MaxLength/2 - 1); i++)
   {
      if(FileName[i] == 0)
         break;
      if((FileName[i] >= 0x41) && (FileName[i] <= 0x5A))
      {
         FileName[i] = FileName[i] + (0x61 - 0x41);
      }
   }
}

/*-----------------------------------*/
void RTFAPI MTCheckFileNameCase(WCHAR *FileName, UINT MaxLength, BYTE NTReserved)
{
   UINT i;

   MaxLength /= 2;
   // check primary file name
   for(i = 0 ; i < (MaxLength - 1); i++)
   {
      if((FileName[i] == 0) || (FileName[i] == dchar_dot[0]))
         break;
   }
   if (NTReserved & MT_ENUM_LOWERCASE_MARK)
   {
      MTToLowerString(FileName, (i + 1) * 2);
   }

   // check extension file name
   if (( i < (MaxLength - 1)) && (FileName[i] == dchar_dot[0]))
   {
      if (NTReserved & MT_ENUM_EXT_LOWERCASE_MARK)
      {
         MTToLowerString(FileName + i + 1, (MaxLength - i - 1) * 2);
      }
   }
}

/* ------------------------------------------------------------------------------- */
WCHAR* RTFAPI TruncateWideBackSlash(WCHAR *path)
{
   WCHAR *back_slash_location = NULL;

   // go to the last WCHAR
   while (*path)
      path++;

   // now path points to the end of path (NULL)

   // truncate tailing L'\\'
   while (*(--path) == L'\\')
   {
      if (*(path - 1) != L':')
      {
         *path = 0;

         if (back_slash_location == NULL)
            back_slash_location = path;
      }
      else // path lefts "X:\\" only, leave
         break;
   }

   return back_slash_location;
}

/* ------------------------------------------------------------------------------- */
WCHAR * RTFAPI TruncateWideWhiteSpacesAndPeriods(const WCHAR *pSrcBuf)
{
   int i, j;
   WCHAR *pBuf = (WCHAR *)pSrcBuf;

   if (pBuf)
   {
      // remove leading white spaces
      while((pBuf[0] != 0) && (pBuf[0] == 0x0020))
      {
         pBuf++;
      }
      // remove trailing whtie spaces and periods
      for (i=0 , j=-1; pBuf[i] != 0x0; i++)
      {
         if (pBuf[i] == 0x005C /* backslash */) j=i;
      }

      // now j is the last '\', i is the tailing NULL

      if ((j == (i - 1) && pBuf[j + 1] == 0x002E) ||
          (j == (i - 2) && pBuf[j + 1] == 0x002E && pBuf[j + 2] == 0x002E ))
      {
         // skip truncate period if  \\. \\..
         j = 0;
      }

      // if case like "x:\folder_name\", set i to the last '\'
      if(j>0 && j==(i-1))
      {
          i = j;
      }

      if ((i && (pBuf[i - 1] == 0x0020 /* space */ ))
        ||(j && (pBuf[i - 1] == 0x002E /* period */)))
      {
         i--;
         while(((i >= 0) && (pBuf[i] == 0x0020 /* space */))
             ||( j       && (pBuf[i] == 0x002E /* period */)))
         {
            i--;
         }
         pBuf[i + 1] = 0;
      }
   }

   return pBuf;
}

/*******************************************************************//**
 * Get RTFDrive structure from drive name string (wide characters)
 *
 * @par Category:
 * File System
 *
 * @par Change Log:
 * W09.19: Add this function to solve: Drive disappears after formatted by File Manager in some projects
 *
 * @param[in]  DriveName   Drive name (wide characters)
 **********************************************************************/
RTFDrive* RTFAPI MTGetRTFDriveByDriveFileName(const WCHAR *DriveName)
{
   int i;

   i = kal_dchar_strlen((char*)DriveName);    // get DriveName length

   if ((i == 12) && !kal_dchar_strncmp((char*)DriveName, (char*)L"\\\\.\\", 4) && DriveName[5] == L':')
   {
      // get drive index
      i = fs_conf_get_native_drive_letter(DriveName[4]) - MT_BASE_DRIVE_LETTER;

      // check range to avoid memory corruption
      if (i < 0 || i >= FS_MAX_DRIVES)
         return NULL;

      // return drive structure
      return gFS_Data.DriveTable + i;
   }

   return NULL;
}

void MTClearFileTableByDrive(RTFDrive* drive)
{
   RTFile *f;
   int     i;

   for (i = 0, f = gFS_Data.FileTable; i < FS_MAX_FILES; i++, f++)
   {
      if ((f->Lock != 0) && (f->Drive == drive))
      {
         FreeFTSlot(f);
      }
   }
}

#ifdef __FS_OPEN_HINT__

void MTHintClearAndSetInfo(FS_OpenHintInt* hint, BYTE path_idx, BYTE level, RTFOpenHintMatchTypeEnum match_type, BYTE new_hint)
{
   hint->Flag       = MT_HINT_INTERNAL | ((new_hint) ? MT_HINT_NEW : 0);
   hint->Level      = level;
   hint->PathIndex  = path_idx;
   hint->MatchType  = match_type;
}

int MTHintCheckFileName(WCHAR* filename)
{
   if (filename[0] == L'.')
   {
      if (filename[1] == 0 || filename[1] == '.') // "." || "..*"
         return 0;
      else return 1; // ".* is allowed"
   }

   return 1;
}

void MTHintAlloc()
{
   kal_uint8 i;

   #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif

   for (i = 0; i < FS_MAX_OPEN_HINT_PATH; i++)
   {
      gFS_OpenHintPath[i].Location = (FS_OpenHintLocation*)(gFS_OpenHintLocationData + (i * FS_MAX_OPEN_HINT_LOCATION_PER_HINT * sizeof(FS_OpenHintLocation)));
   }
}

void MTHintHit(kal_uint8 PathIndex)
{
   kal_uint8 i;

   /*
    * It's a new hint (Status < FS_HINT_STABLE) or
    * it's not a new hint, but global ceil is needed to level up
    */
   if (gFS_OpenHintPath[PathIndex].Status < FS_HINT_STABLE ||
   	   gFS_OpenHintPath[PathIndex].HitStamp != gFS_OpenHintStampCeil)
   {
      gFS_OpenHintStampCeil = (gFS_OpenHintStampCeil + 1) & 0xFF;

      /*
       * If ceil wraps around, all hit stamps needs to be normalized
       * to MT_HINT_STAMP_NORMALIZE_LEVEL levels: 0 ~ to (MT_HINT_STAMP_NORMALIZE_LEVEL - 1)
       */
      if (gFS_OpenHintStampCeil == 0)
      {
         for (i = 0; i < FS_MAX_OPEN_HINT_PATH; i++)
         {
            gFS_OpenHintPath[i].HitStamp = gFS_OpenHintPath[i].HitStamp / MT_HINT_STAMP_NORMALIZE_BASE;
         }

         gFS_OpenHintStampCeil = MT_HINT_STAMP_NORMALIZE_LEVEL;
      }

      gFS_OpenHintPath[PathIndex].HitStamp = gFS_OpenHintStampCeil;
   }

   // if hint is FS_HINT_STABLE and HitStamp == gFS_OpenHintStampCeil, just keep its HitStamp
}

/**
 * @brief Copy path string and delete continuous backslash in the target path
 */
void MTHintInitPath(kal_uint8 PathIndex, const WCHAR *Path)
{
   WCHAR *from = (WCHAR*)Path;
   WCHAR *to   = gFS_OpenHintPath[PathIndex].Path;

   gFS_OpenHintPath[PathIndex].Status       = FS_HINT_ALLOCATED;
   gFS_OpenHintPath[PathIndex].FirstLevel   = 0;
   gFS_OpenHintPath[PathIndex].HintNum      = 0;
   gFS_OpenHintPath[PathIndex].FirstHint    = 0;
   gFS_OpenHintPath[PathIndex].Flag         = 0;
   gFS_OpenHintPath[PathIndex].HitStamp     = 0;

   // copy "X:\\" to HintPath
   *to++ = fs_conf_get_native_drive_letter(*from++);
   *to++ = *from++;
   *to++ = *from;
   *to   = 0;

   gFS_OpenHintPath[PathIndex].PathLength   = 3;
   gFS_OpenHintPath[PathIndex].Drive        = NULL;
   gFS_OpenHintPath[PathIndex].SerialNumber = 0;
}

int MTHintNew(kal_uint8 PathIndex, kal_uint8 Level, RTFDirLocation *Location, RTFile *f, WCHAR *FileName)
{
   kal_uint16 len;
   kal_uint16 loc, loc_tail;
   #ifdef __FS_TRACE_SUPPORT_OPEN_HINT__
   WCHAR      *filename = FileName;
   #endif

   if (MTHintCheckFileName(FileName) == 0)
   {
      gFS_OpenHintPath[PathIndex].Flag = MT_HINT_FLAG_OBSOLETE;
      return 0;
   }

   /*
    * Check if hint is still valid.
    * Hint may be expired during establish process because device lock
    * may be released temporarily in SearchFile()
    *
    * FS_HINT_FREE                                  : This hint is available
    * FS_HINT_ALLOCATED (HintNum = 0, HintStamp = 0): This hint is allocated and no hint location is created for this hint yet
    * FS_HINT_CREATING  (HintNum > 0, HintStamp = 0): This hint is allocated and some hint locations are created for this hint
    * FS_HINT_STABLE    (HintStamp > 0)             : This hint is finished and stable.
    */
   if (gFS_OpenHintPath[PathIndex].Status == FS_HINT_FREE ||
   	  ((gFS_OpenHintPath[PathIndex].Status > FS_HINT_ALLOCATED) &&
   	   (gFS_OpenHintPath[PathIndex].Drive != (FS_Drive*)f->Drive ||
   	    gFS_OpenHintPath[PathIndex].SerialNumber != f->Drive->SerialNumber)))
      return 0;

   // append '\\' to the tail of Path
   len = gFS_OpenHintPath[PathIndex].PathLength;

   if (gFS_OpenHintPath[PathIndex].Path[len - 1] != L'\\')
      gFS_OpenHintPath[PathIndex].Path[len++] = L'\\';

   // append FileName to Path
   while (*FileName && *FileName != L'\\')
   {
      if (((RTF_MAX_PATH / 2) - 1) <= len) // This is the last WCHAR in path, should not fill any WCHAR except for NULL
      {
         gFS_OpenHintPath[PathIndex].Status = FS_HINT_FREE;
         return 0;
      }

      gFS_OpenHintPath[PathIndex].Path[len++] = *FileName++;
   }

   gFS_OpenHintPath[PathIndex].Path[len] = 0;
   gFS_OpenHintPath[PathIndex].PathLength = len;

   // get the first hint index
   loc = gFS_OpenHintPath[PathIndex].FirstHint;

   if (gFS_OpenHintPath[PathIndex].HintNum == 0)
   {
      // here loc must be 0
      gFS_OpenHintPath[PathIndex].FirstLevel   = Level;
      gFS_OpenHintPath[PathIndex].HintNum++;
      gFS_OpenHintPath[PathIndex].Drive        = (FS_Drive*)f->Drive;
      gFS_OpenHintPath[PathIndex].SerialNumber = f->Drive->SerialNumber;
      gFS_OpenHintPath[PathIndex].Status       = FS_HINT_CREATING;
   }
   else
   {
      // get tail index
      loc_tail = loc + gFS_OpenHintPath[PathIndex].HintNum - 1;

      if (loc_tail >= FS_MAX_OPEN_HINT_LOCATION_PER_HINT)
         loc_tail -= FS_MAX_OPEN_HINT_LOCATION_PER_HINT;

      // new location is allowed for this path
      if (gFS_OpenHintPath[PathIndex].HintNum < FS_MAX_OPEN_HINT_LOCATION_PER_HINT)
      {
         // use loc_tail's next slot to store new location
         loc = loc_tail + 1;

         if (loc == FS_MAX_OPEN_HINT_LOCATION_PER_HINT) loc = 0;

         gFS_OpenHintPath[PathIndex].HintNum++; // increase the length of location chain
      }
      else // Maximum location is reached! Replace the first one (loc). (Level should be continuous, ignore Level here)
      {
         gFS_OpenHintPath[PathIndex].FirstLevel++;

         // the first location becomes the last location
         loc = gFS_OpenHintPath[PathIndex].FirstHint;

         gFS_OpenHintPath[PathIndex].FirstHint++;
         if (gFS_OpenHintPath[PathIndex].FirstHint == FS_MAX_OPEN_HINT_LOCATION_PER_HINT)
            gFS_OpenHintPath[PathIndex].FirstHint = 0;
      }
   }

   gFS_OpenHintPath[PathIndex].Location[loc].Cluster    = Location->Cluster;
   gFS_OpenHintPath[PathIndex].Location[loc].Index      = Location->Index;
   gFS_OpenHintPath[PathIndex].Location[loc].DirCluster = f->DirEntry.DirCluster;

   #ifdef __FS_TRACE_SUPPORT_OPEN_HINT__
   #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif
   #endif

   return 1;
}

/**
 * @brief Compare until wchar unmatched or any '\' is meet or any path is end
 *
 * @return level
 *
 * @Remarks
 * Compare from HintPath[3]!
 */
kal_uint8 MTHintMatch(const WCHAR *TargetPath, kal_uint8 PathIndex, RTFOpenHintMatchTypeEnum *MatchType)
{
   kal_uint16   level = 0;
   WCHAR        c1, c2, *p1, *p2;

   p1 = gFS_OpenHintPath[PathIndex].Path + 2;
   p2 = (WCHAR*)TargetPath + 2;
   *MatchType = MT_HINT_MATCH_NONE;

   if (gFS_OpenHintPath[PathIndex].HintNum == 0)
      return 0;

MTHintMatch_NextLevel:

   do
   {
      p1++;
      c1 = isWASCII(*p1) ? fs_util_wchar_toupper(*p1) : *p1;
      if (c1 == L'\\') c1 = 0;

      p2++;
      c2 = isWASCII(*p2) ? fs_util_wchar_toupper(*p2) : *p2;
      if (c2 == L'\\')
      {
          // Skip L"\\.\\" and multiple L'\\' (HintPath is not required because it is clear by SearchFile() + MTHintNew())
          while ((*(p2 + 1) == L'.' && *(p2 + 2) == L'\\') || (*(p2 + 1) == L'\\'))
             p2++;

         c2 = 0;
      }
   } while (c1 && (c1 == c2));

   if (c1 == c2)
   {
      level++;

      c1 = *p1;
      c2 = *p2;

      if (c1 && c2) // c1 == c2 == '\\'
      {
         // if level is beyond the maximum level of PathIndex, skip matching
         if (level >= gFS_OpenHintPath[PathIndex].FirstLevel + gFS_OpenHintPath[PathIndex].HintNum - 1)
         {
            *MatchType = MT_HINT_MATCH_OTHER;
            return (gFS_OpenHintPath[PathIndex].FirstLevel + gFS_OpenHintPath[PathIndex].HintNum - 1);
         }
         else
            goto MTHintMatch_NextLevel;
      }
      else if (c1) // c2 == 0
         *MatchType = MT_HINT_MATCH_TARGET_END;
      else if (c2) // c1 == 0
         *MatchType = MT_HINT_MATCH_HINT_END;
      else         // c1 == c2 == 0
         *MatchType = MT_HINT_MATCH_PERFECT;
   }
   else
      *MatchType = MT_HINT_MATCH_OTHER;

   if (level < gFS_OpenHintPath[PathIndex].FirstLevel)
      return 0;
   else
      return level;
}

void MTHintGetLocation(kal_int8 PathIndex, kal_uint8 Level, FS_OpenHintInt *Hint)
{
   kal_uint8  index;
   kal_uint8  level;

   level = Level - gFS_OpenHintPath[PathIndex].FirstLevel;
   index = gFS_OpenHintPath[PathIndex].FirstHint + level;

   while (index >= FS_MAX_OPEN_HINT_LOCATION_PER_HINT)
      index -= FS_MAX_OPEN_HINT_LOCATION_PER_HINT;

   Hint->Cluster    = gFS_OpenHintPath[PathIndex].Location[index].Cluster;
   Hint->Index      = gFS_OpenHintPath[PathIndex].Location[index].Index;
   Hint->DirCluster = gFS_OpenHintPath[PathIndex].Location[index].DirCluster;
}

void MTHintDiscard(kal_uint8 path_idx)
{
    gFS_OpenHintPath[path_idx].Status = FS_HINT_FREE;
}

void MTHintDelete(kal_uint8 path_idx)
{
   kal_uint8                i;
   RTFOpenHintMatchTypeEnum match_type = MT_HINT_MATCH_NONE;

   // delete duplicated hints
   for (i = 0; i < FS_MAX_OPEN_HINT_PATH; i++)
   {
      if (i != path_idx)
      {
         MTHintMatch(gFS_OpenHintPath[path_idx].Path, i, &match_type);

         if (match_type == MT_HINT_MATCH_PERFECT)
         {
            if (gFS_OpenHintPath[i].Status <= FS_HINT_STABLE)
                gFS_OpenHintPath[i].Status = FS_HINT_FREE;
            else // FS_HINT_STABLE_LOCKED
                gFS_OpenHintPath[i].Status = FS_HINT_DELETED_LOCKED;

            #ifdef __FS_TRACE_SUPPORT_OPEN_HINT__
            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
            #endif
         }
      }
   }

   if (gFS_OpenHintPath[path_idx].Status <= FS_HINT_STABLE)
      gFS_OpenHintPath[path_idx].Status = FS_HINT_FREE;
   else // FS_HINT_STABLE_LOCKED
      gFS_OpenHintPath[path_idx].Status = FS_HINT_DELETED_LOCKED;

   #ifdef __FS_TRACE_SUPPORT_OPEN_HINT__
   #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif
   #endif
}

void MTHintExpireByDrive(RTFDrive *Drive)
{
   kal_uint8 i;

   for (i = 0; i < FS_MAX_OPEN_HINT_PATH; i++)
   {
      if (gFS_OpenHintPath[i].Drive == (FS_Drive*)Drive)
      {
         // MTHintDelete(i);

         gFS_OpenHintPath[i].Status = FS_HINT_FREE;

         #ifdef __FS_TRACE_SUPPORT_OPEN_HINT__
         #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
         #endif
         #endif
      }
   }
}

kal_uint32 MTHintCompare(kal_uint8 Target1, kal_uint8 Target2)
{
   kal_uint16 loc1, loc2;
   kal_uint16 i;

   if (gFS_OpenHintPath[Target1].Drive == gFS_OpenHintPath[Target2].Drive &&
       gFS_OpenHintPath[Target1].SerialNumber == gFS_OpenHintPath[Target2].SerialNumber &&
       gFS_OpenHintPath[Target1].HintNum == gFS_OpenHintPath[Target2].HintNum &&
       gFS_OpenHintPath[Target1].FirstLevel == gFS_OpenHintPath[Target2].FirstLevel)
   {
      loc1 = gFS_OpenHintPath[Target1].FirstHint;
      loc2 = gFS_OpenHintPath[Target2].FirstHint;

      // MT_HINT_LOC_UNDEFILED is not required to consider because STABLE hint should have location(s).
      for (i = 0; i < gFS_OpenHintPath[Target1].HintNum; i++)
      {
         if (gFS_OpenHintPath[Target1].Location[loc1].Cluster != gFS_OpenHintPath[Target2].Location[loc2].Cluster ||
             gFS_OpenHintPath[Target1].Location[loc1].Index   != gFS_OpenHintPath[Target2].Location[loc2].Index)
            return 1;

         loc1++;
         loc2++;

         if (loc1 >= FS_MAX_OPEN_HINT_LOCATION_PER_HINT) loc1 = 0;
         if (loc2 >= FS_MAX_OPEN_HINT_LOCATION_PER_HINT) loc2 = 0;
      }

      return 0;
   }
   else
      return 1;
}

void MTHintFinish(FS_OpenHintInt *hint)
{
   kal_uint8 i;
   kal_uint8 path_idx;
   kal_uint8 duplicated = 0;

   if (hint == NULL) return;

   path_idx = MTHintGetIndex(hint);

   // no location is added for this path, or is expired or failed during creation process, abandon it
   if (gFS_OpenHintPath[path_idx].Status <= FS_HINT_ALLOCATED ||
   	   gFS_OpenHintPath[path_idx].Flag == MT_HINT_FLAG_OBSOLETE)
   {

      #ifdef __FS_TRACE_SUPPORT_OPEN_HINT__
      #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
      #endif
      #endif

      gFS_OpenHintPath[path_idx].Status = FS_HINT_FREE;
   }
   else // set this path as valid
   {
      // find if a duplicated hint
      for (i = 0; i < FS_MAX_OPEN_HINT_PATH; i++)
      {
         if ((gFS_OpenHintPath[i].Status >= FS_HINT_STABLE && gFS_OpenHintPath[i].Status <= FS_HINT_STABLE_LOCKED) &&
             MTHintCompare(i, path_idx) == 0)
         {
            duplicated = 1;
            MTHintHit(i);  // update hint stamp of this new hint
            break;
         }
      }

      if (duplicated == 0)
      {
         MTHintHit(path_idx);  // update hint stamp of this new hint
         gFS_OpenHintPath[path_idx].Status = FS_HINT_STABLE;

         #ifdef __FS_TRACE_SUPPORT_OPEN_HINT__
         #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
         #endif
         #endif
      }
      else
      {
         #ifdef __FS_TRACE_SUPPORT_OPEN_HINT__
         #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
         #endif
         #endif

         gFS_OpenHintPath[path_idx].Status = FS_HINT_FREE;
      }
   }
}

kal_uint8 MTHintSelectVictim()
{
   kal_int8   i;
   kal_uint8  min_i     = FS_MAX_OPEN_HINT_PATH;
   kal_uint16 min_stamp = 0xFFFF;

   for (i = FS_MAX_OPEN_HINT_PATH - 1; i >= 0; i--)
   {
      if (gFS_OpenHintPath[i].Status == FS_HINT_FREE)
      {
         return i;
      }
      else if (gFS_OpenHintPath[i].Status == FS_HINT_STABLE)
      {
         if (gFS_OpenHintPath[i].HitStamp < min_stamp)
         {
            min_i = i;
            min_stamp = gFS_OpenHintPath[i].HitStamp;
         }
      }
   }

   if (min_i < FS_MAX_OPEN_HINT_PATH)
   {
      gFS_OpenHintPath[min_i].Status = FS_HINT_FREE; // invalid it here
   }

   return min_i;
}

// "X://" should be copied before
WORD MTHintCopyPath(WCHAR *To, WCHAR *From, kal_uint8 Level)
{
   kal_uint8  level = 0;
   WCHAR      *base = To;

   To = To + 3;
   From = From + 3;

   // copy other part until level == (Level - 1) is satisfied (starting from From[3] because "X:\\" was copied in MTHintInitPath())
   while (1)
   {
      *To = *From;

      if (*From == L'\\' || *From == 0)
         level++;

      if (level >= (Level - 1))
         break;

      To++;
      From++;
   };

   *To = 0; // remove the last '\\'

   return (To - base);
}

void MTHintNewManual(kal_int8 PathIndex, const WCHAR *Path, WCHAR *FileName, RTFDirLocation *Location, UINT DirCluster)
{
   kal_uint8 level = 1;
   WCHAR     *p, *pFileName;
   RTFDrive  *drive;

   // check validatity (hint status)
   if (gFS_OpenHintPath[PathIndex].Status != FS_HINT_ALLOCATED)
   {
      #ifdef __FS_TRACE_SUPPORT_OPEN_HINT__
      #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
      #endif
      #endif

      return;
   }

   // check validatity (Path must start with "X:\\")
   if (Path[1] != L':' || Path[2] != L'\\')
   {
      #ifdef __FS_TRACE_SUPPORT_OPEN_HINT__
      #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
      #endif
      #endif

      return;
   }

   // check validatity (FileName)
   if (FileName == NULL || FileName[0] == L'\0')
   {
      #ifdef __FS_TRACE_SUPPORT_OPEN_HINT__
      #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
      #endif
      #endif

      return;
   }

   // copy path
   Path += 3; // skip "X:\\"

   while (*Path == L'\\') Path++; // skip all continuous "\\"

   p = pFileName = gFS_OpenHintPath[PathIndex].Path + 3;

   while (*Path != L'\0' && *Path != L'*')
   {
      *p++ = *Path;

      // new level is finished
      if (*Path == L'\\')
      {
         level++;

         while (*Path == L'\\') Path++; // skip all continuous "\\"

         pFileName = p; // remember start position of this level

         if (*Path == L'\0' || *Path == L'*')
         {
            break;
         }
         else
         {
            continue;   // bypass "Path++" below because Path now is already the first char after '\\'
         }
      }

      Path++;
   }

   // get Path limit
   p = gFS_OpenHintPath[PathIndex].Path + (FS_MAX_PATH / 2) - 1;

   // append file name
   while (*FileName != L'\0')
   {
      if (pFileName >= p)  // out of range, reset this hint and do nothing
      {
         gFS_OpenHintPath[PathIndex].Status = FS_HINT_FREE;
         return;
      }

      *pFileName++ = *FileName++;
   }

   *pFileName = L'\0'; // terminate path

   // fill-in location and DirCluster
   gFS_OpenHintPath[PathIndex].Location[0].Cluster    = Location->Cluster;
   gFS_OpenHintPath[PathIndex].Location[0].Index      = Location->Index;
   gFS_OpenHintPath[PathIndex].Location[0].DirCluster = DirCluster;
   gFS_OpenHintPath[PathIndex].HintNum                = 1;
   gFS_OpenHintPath[PathIndex].FirstHint              = 0;
   gFS_OpenHintPath[PathIndex].FirstLevel             = level;
   gFS_OpenHintPath[PathIndex].PathLength = pFileName - gFS_OpenHintPath[PathIndex].Path;

   // finish this hint
   drive = gFS_Data.DriveTable + (gFS_OpenHintPath[PathIndex].Path[0] - MT_BASE_DRIVE_LETTER);
   gFS_OpenHintPath[PathIndex].Drive                  = (FS_Drive*)drive;
   gFS_OpenHintPath[PathIndex].SerialNumber           = drive->SerialNumber;
   gFS_OpenHintPath[PathIndex].Status                 = FS_HINT_STABLE;

   #ifdef __FS_TRACE_SUPPORT_OPEN_HINT__
   #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif
   #endif

   MTHintHit(PathIndex);  // update hint stamp of this new hint
}

RTFDirLocation* MTHintGet(const WCHAR *Path, RTFOpenHintActionEnum Action)
{
   kal_uint8                i, max_i, free_i;
   RTFOpenHintMatchTypeEnum match_type = MT_HINT_MATCH_NONE;
   kal_uint16               level, max_level;
   kal_int8                 hint_index;
   kal_uint16               drive_letter;

   if (Path[1] != L':' || Path[2] != L'\\')
      return NULL;

   max_level = max_i = 0;
   free_i = MT_HINT_PATH_FREE_SLOT_UNAVAILABLE;
   hint_index = RTFSYSGetTaskIndex();
   drive_letter = fs_conf_get_native_drive_letter(Path[0]);
   gFS_OpenHint[hint_index].Cluster = 0; // reset hint

   // if forcedly new a hint, go create a new hint directly
   if (Action == MT_HINT_ACTION_FORCE_NEW)
   {
      goto MTHintGet_NewHint;
   }

   for (i = 0; i < FS_MAX_OPEN_HINT_PATH; i++)
   {
      if (gFS_OpenHintPath[i].Status >= FS_HINT_STABLE && gFS_OpenHintPath[i].Status <= FS_HINT_STABLE_LOCKED)
      {
         if (gFS_OpenHintPath[i].Path[0] == drive_letter)
         {
            level = MTHintMatch(Path, i, &match_type);

            if (level > max_level)
            {
               max_level = level;
               max_i     = i;

               // get location (only when deeper level is found)
               MTHintGetLocation(max_i, max_level, &gFS_OpenHint[hint_index]);

               if (match_type == MT_HINT_MATCH_PERFECT ||
                   match_type == MT_HINT_MATCH_TARGET_END)
                  break;
            }
         }
      }
      else if (gFS_OpenHintPath[i].Status == FS_HINT_FREE)
      {
         free_i = i;
      }
   }

   // partial or complete path is matched, try to get hint by level
   if (max_level != 0)
   {
      // perfect match! we have hint for the deepest foler or file in target path
      if (match_type == MT_HINT_MATCH_PERFECT || match_type == MT_HINT_MATCH_TARGET_END)
      {
         /*
          * For creating file or folder case, if match_type is PERFECT or TARGET_END,
          * later FS must can't create the file or folder because they are already
          * existed. Therefore we don't need to create a new hint.
          */

         MTHintClearAndSetInfo(&(gFS_OpenHint[hint_index]), max_i, max_level, match_type, 0);
         MTHintHit(max_i);  // hint an existed hint

         goto MTHintGet_Return;
      }
   }

   /*
    * max_level == 0: No file and folder hints matched
    * max_level != 0 && !PERFECT_MATCH && !TARGET_END
    * For these 2 cases, create a new hints except Action is NO_NEW
    */

   if (Action != MT_HINT_ACTION_FORCE_NO_NEW)
   {
      /*
       * max_level == 0: Create a brand new hint
       * max_level != 0 && !PERFECT_MATCH && !TARGET_END: Create a new hint
       * which inherit the deepest matched folder
       */
      goto MTHintGet_NewHint;
   }
   else // MT_HINT_ACTION_FORCE_NO_NEW
   {
      /*
       * New hint is not required, return directly
       */

      MTHintClearAndSetInfo(&(gFS_OpenHint[hint_index]), max_i, max_level, match_type, 0);
      goto MTHintGet_Return;
   }

MTHintGet_NewHint:

   if (free_i == (kal_uint8)MT_HINT_PATH_FREE_SLOT_UNAVAILABLE)
      free_i = MTHintSelectVictim();

   if (free_i == FS_MAX_OPEN_HINT_PATH) // invalid hint
      return NULL;

   MTHintInitPath(free_i, Path);

   /*
    * Create a new hint starting from the deepest matched folder
    * Note: free_i may equal to max_i if it is selected as the victim for replacement!
    *       In this case, max_i will be cleared by MTHintSelectVictim(), just treat it
    *       as a free hint and do nothing.
    */
   if (max_level != 0 && free_i != max_i)
   {
      if (max_level > 1)
      {
         gFS_OpenHintPath[free_i].PathLength = MTHintCopyPath(gFS_OpenHintPath[free_i].Path, gFS_OpenHintPath[max_i].Path, max_level);
      }

      /*
       * If (max_level == 1) only "X:\\" is required to copy to
       * gFS_OpenHintPath[free_i].Path. It was done in MTHintInitPath()
       */

      MTHintClearAndSetInfo(&(gFS_OpenHint[hint_index]), free_i, max_level, match_type, 1);

      /*
       * Here gFS_OpenHint[hint_index] should have location of the deepest matched
       * folder by MTHintGetLocation() above.
       */
   }
   else // create a brand new hint
   {
      MTHintClearAndSetInfo(&(gFS_OpenHint[hint_index]), free_i, 1, match_type, 1);

      // set hint as invalid hint
      gFS_OpenHint[hint_index].Cluster = 0;
   }

MTHintGet_Return:

   #ifdef __FS_TRACE_SUPPORT_OPEN_HINT__
   #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif
   #endif

   return (RTFDirLocation*)&gFS_OpenHint[hint_index];
}

void MTHintFindClose(RTFHANDLE fh)
{
   RTFile    *f;
   kal_uint8 path_idx;

   // locate base hint and change its state
   fh = FS_GetFileTableIdx(fh);

   if (fh >= 0 && fh < FS_MAX_FILES)
      f = gFS_Data.FileTable + fh;
   else
   	  return;

   // if this file handle does not processed by MTHintFindFirst successfully, skipped.
   if ((f->Flags & FS_FH_INTERNAL_HINT) == 0) return;

   path_idx = f->FilePointer;

   if (path_idx != FS_MAX_OPEN_HINT_PATH)
   {
      if (gFS_OpenHintPath[path_idx].Status == FS_HINT_STABLE_LOCKED)
         gFS_OpenHintPath[path_idx].Status = FS_HINT_STABLE;
      else
         gFS_OpenHintPath[path_idx].Status = FS_HINT_FREE; // DELETED_LOCKED => FREE
   }

   f->Flags &= ~FS_FH_INTERNAL_HINT;
}

void MTHintFindNext(RTFDirLocation* location, RTFHANDLE fh, WCHAR* filename)
{
   RTFile          *f;
   WCHAR           *from, *to;
   kal_uint8       path_idx_base, path_idx_cur, level;

   if (MTHintCheckFileName(filename) == 0)
      return;

   fh = FS_GetFileTableIdx(fh);

   if (fh >= 0 && fh < FS_MAX_FILES)
      f = gFS_Data.FileTable + fh;
   else
   	  return;

   // if this file handle does not processed by MTHintFindFirst successfully, skipped.
   if ((f->Flags & FS_FH_INTERNAL_HINT) == 0) return;

   path_idx_base = f->FilePointer;

   if (gFS_OpenHintPath[path_idx_base].Status < FS_HINT_STABLE_LOCKED ||
   	   gFS_OpenHintPath[path_idx_base].Drive != (FS_Drive*)f->Drive ||
   	   gFS_OpenHintPath[path_idx_base].SerialNumber != f->Drive->SerialNumber)
      return;

   #ifdef __FS_TEST__
   fs_assert_local(gFS_OpenHintPath[path_idx_base].Path[0] == fs_conf_get_native_drive_letter((WCHAR)f->FullName[0]));
   #endif

   if ((path_idx_cur = MTHintSelectVictim()) == FS_MAX_OPEN_HINT_PATH)
      return;

   /*
    * To minimize overhead, we create only one location for the new hint.
    */

   // initialize hint
   MTHintInitPath(path_idx_cur, (WCHAR*)(f->FullName));

   // copy path
   from = gFS_OpenHintPath[path_idx_base].Path;
   to   = gFS_OpenHintPath[path_idx_cur].Path;

   // copy the whole path first
   while (*from) *to++ = *from++;

   // get tail level of base hint
   level = gFS_OpenHintPath[path_idx_base].FirstLevel + gFS_OpenHintPath[path_idx_base].HintNum - 1;

   // if base hint includes both parent and last file found, delete the file name and leave parent path only
   if (gFS_OpenHintPath[path_idx_base].Flag & MT_HINT_FLAG_FIND_FILE)
   {
      // locate the last L'\\'
      for (to = to - 1; *to != L'\\'; to--);

      // delete the last L'\\'
      *to = 0;

      // remain the level
   }
   else
   {
      /*
       * Base hint only have parent path and level just point to the last parent folder.
       * In this case, filename should add in level = (level + 1)
       */
      level += 1;
   }

   // compute PathLength
   gFS_OpenHintPath[path_idx_cur].PathLength = to - gFS_OpenHintPath[path_idx_cur].Path;

   // create a location for found filename
   MTHintNew(path_idx_cur, level, location, f, filename);

   // this base hint surely have filename
   gFS_OpenHintPath[path_idx_cur].Flag |= MT_HINT_FLAG_FIND_FILE;

   MTHintHit(path_idx_cur);

   if (gFS_OpenHintPath[path_idx_base].Status == FS_HINT_STABLE_LOCKED)
      gFS_OpenHintPath[path_idx_base].Status = FS_HINT_STABLE;
   else
      gFS_OpenHintPath[path_idx_base].Status = FS_HINT_FREE; // DELETED_LOCKED => FREE

   gFS_OpenHintPath[path_idx_cur].Status = FS_HINT_STABLE_LOCKED;

   // now base hint is changed to path_idx_cur
   f->FilePointer = path_idx_cur;

}

void MTHintFindFirst(FS_OpenHintInt *hint, RTFDirLocation* location, RTFile *f, WCHAR* filename)
{
   kal_uint8                path_idx;
   kal_uint8                level;

   if (hint == NULL) return;

   path_idx   = MTHintGetIndex(hint);
   level      = MTHintGetLevel(hint);

   // if hint creation process is failed, abandon this hint
   if (gFS_OpenHintPath[path_idx].Flag == MT_HINT_FLAG_OBSOLETE)
   {
      gFS_OpenHintPath[path_idx].Status = FS_HINT_FREE;
      return;
   }

   /*
    * Add location for the first found file.
    *
    * Note. Hint is set to FORCE_NEW for FS_FindFirst/FS_FindNext.
    * New hint must be allowed here.
    */

   #ifdef __FS_TEST__
   fs_assert_local(MTIsNewHint(hint) != 0);
   #endif

   if (MTHintNew(path_idx, level, location, f, filename))
   {
      gFS_OpenHintPath[path_idx].Flag |= MT_HINT_FLAG_FIND_FILE;
   }
   else
   {
      /*
       * else: Create location failed, for example, "." and ".." will let MTHintNew()
       * failed. In such cases, base hint only have parents.
       *
       * Note. If case "." or "..", MTHintNew will mark hint->Flag |= MT_HINT_FLAG_OBSOLETE.
       * But this is OK because MTHintFindNext will not see this flag.
       */
   }

   // preserve parent path's index
   f->Flags |= FS_FH_INTERNAL_HINT;
   f->FilePointer = path_idx;

   // update hint stamp of this new hint
   MTHintHit(path_idx);

   gFS_OpenHintPath[path_idx].Status = FS_HINT_STABLE_LOCKED;
}
#endif /* __FS_OPEN_HINT__ */

/*-----------------------------------*/
RTFHANDLE RTFAPI RTFOpenFileByHint(WCHAR DriveLetter, UINT DirCluster, UINT DirIndex, kal_uint32 Flags, kal_uint32 caller_address)
{
   int volatile Result;
   RTFile * volatile f = NULL;
   RTFDirLocation DSR;
   WCHAR FileName[4] = { 0 };
   const RTFDOSDirEntry * D;

   BYTE CheckSum = 0; /* Remove RVCT warning, Karen Hsu, 2004/11/02, MOD */
   int LFNIndex = -1;

   if (Flags & RTF_OPEN_DIR)
      Flags &= ~RTF_OPEN_NO_DIR;

   XTRY
      case XCODE:
         // check for invalid flag combinations
         if (Flags & RTF_CREATE_ALWAYS)
         {
            fs_util_trace_err_noinfo(RTF_PARAM_ERROR);

            XRAISE(RTF_PARAM_ERROR);
         }

         if ((Flags & FS_PROTECTION_MODE) && (Flags & FS_NONBLOCK_MODE))
         {
            fs_util_trace_err_noinfo(RTF_ATTR_CONFLICT);

            XRAISE(RTF_ATTR_CONFLICT); // Can't specify FS_PROTECTION_MODE and FS_NONBLOCK_MODE
         }

         if (Flags & RTF_COMMITTED)
            Flags &= ~RTF_LAZY_DATA;

         if (Flags & RTF_LAZY_DATA)
            Flags |= RTF_CACHE_DATA;

         kal_dchar_strcpy((char*)FileName, (char*)L"X:\\");
         FileName[0] = DriveLetter;
         f = ParseFileName((char *)FileName);

         f->Flags = Flags;

         if ((Flags & RTF_READ_ONLY) == 0)
         {
            if(f->Dev->DeviceFlags & MT_DEVICE_WRITE_PROTECT)
            {
               fs_util_trace_err_noinfo(RTF_WRITE_PROTECTION);

               XRAISE(RTF_WRITE_PROTECTION);
            }
         }

         D = StartDirSearch(f->Drive, DirCluster, DirIndex, &DSR);

         if (NULL == D)
            XRAISE(RTF_FILE_NOT_FOUND);

         if(EntryType(D)==Lfn)
         {
             const LFNDirEntry * LD = (void*) D;

             if (LD->Ord & 0x40) // it's the start of an LFN
             {
                 LFNIndex = LD->Ord & 0x3F;
                 CheckSum = LD->CheckSum;
                 f->DirEntry.LongPos.Cluster = DirCluster;
                 f->DirEntry.LongPos.Index = DirIndex;
                 LFNIndex--;
             }
             else
             {
                 XRAISE(RTF_PATH_NOT_FOUND);
             }

             while((D = NextDir(f->Drive, &DSR)) != NULL  && EntryType(D) != InUse)
             {
                LD = (LFNDirEntry *)D;
                if ((LD->CheckSum != CheckSum) || (LFNIndex != (LD->Ord & 0x3F)))
                {
                    XRAISE(RTF_PATH_NOT_FOUND);
                }
                else
                {
                    LFNIndex--;
                }
             }

             if(LFNIndex!=0)
             {
                XRAISE(RTF_PATH_NOT_FOUND);
             }
         }

         if(D==0 || EntryType(D)==NeverUsed)
         {
            XRAISE(RTF_PATH_NOT_FOUND);
         }

         if(EntryType(D)==InUse)
         {
             if((LFNIndex == 0) && (CheckSum != ShortNameCheckSum((const BYTE*) D->FileName)))
             {
                 XRAISE(RTF_PATH_NOT_FOUND);
             }
             f->DirEntry.ShortPos.Cluster = DSR.Cluster;
             f->DirEntry.ShortPos.Index = DSR.Index;
             f->DirEntry.Dir = *D;
         }
         else
         {
             XRAISE(RTF_PATH_NOT_FOUND);
         }

         CheckSharing(f);
         if ((f->DirEntry.Dir.Attributes & RTF_ATTR_READ_ONLY) && ((Flags & RTF_READ_ONLY) == 0))
         {
            fs_util_trace_err_noinfo(MT_READ_ONLY_ERROR);

            XRAISE(MT_READ_ONLY_ERROR);
         }
          /* Change error message for FMT, Karen Hsu, 2004/04/20, MOD END */

         if ((f->DirEntry.Dir.Attributes & RTF_ATTR_DIR) && ((Flags & RTF_OPEN_NO_DIR) || ((Flags & RTF_READ_ONLY) == 0)))
          /* Change error message for FMT, Karen Hsu, 2004/04/20, MOD START */
         {
            fs_util_trace_err_noinfo(MT_READ_ONLY_ERROR);

            XRAISE(MT_READ_ONLY_ERROR);
         }

         InitFilePointer(f);

         if (f->DirEntry.Dir.Attributes & RTF_ATTR_DIR)
         {
            if (f->Cluster == RTF_ROOT_DIR)
               f->DirEntry.Dir.FileSize = f->Drive->RootDirEntries * sizeof(RTFDOSDirEntry);
            else
               f->DirEntry.Dir.FileSize = FATClusterChainLength(f->Drive, f->Cluster, NULL) << f->Drive->ClusterShift;
         }
         Result = MakeNewFileHandle(f);

         break;
      default:
         Result = XVALUE;
         break;
      case XFINALLY:
         if (f)
         {
            f->OwnerLR=caller_address;

            if (Result < RTF_NO_ERROR)
               FreeFTSlotAndDevice(f);
            else
               UnlockDevice(f->Dev);
         }
         break;
   XEND_API
   return Result;
}

#if defined(__MTP_ENABLE__)

static int GetFileInfoByHint(RTFDrive *Drive, RTFDOSDirEntry * FileInfo, WCHAR * FileName,
                 UINT MaxLength, RTFDirLocation * Pos)
{
   int volatile Result = RTF_NO_ERROR;
   RTFDOSDirEntry * D;
   LFNDirEntry * LD;
   int Kind, LFNIndex = -1;
   RTFDirLocation Pos_Copy;

   Pos_Copy.Cluster = Pos->Cluster;
   Pos_Copy.Index = Pos->Index;

   XTRY //exception handler for GetDir
      case XCODE:
         D = GetDir(Drive, &Pos_Copy); //check for current dir entry

         if(D == NULL)
         {
            fs_util_trace_err_noinfo(RTF_NO_MORE_FILES);

            return RTF_NO_MORE_FILES;
         }

         Kind = EntryType(D);

         if(Kind != InUse) //try to make LFN
         {
            WCHAR * FindName = NULL;
            UINT FindLength;

            if(Kind == Lfn)
            {
                FindName = FileName;
                FindLength = MaxLength;
            }

            while(Kind == Lfn)
            {
               LD = (void*) D;

               if (LD->Ord & 0x40) // it's the start of an LFN
               {
                  char * Limit;
                  LFNIndex = LD->Ord & 0x3F;

                  Limit = ((char *)FindName) + ((LFNIndex-1)*13*2 + 2*LFNCharCount(LD));
                  if (Limit > (((char *)FindName) + FindLength - 1))
                      LFNIndex = -1;
                  else
                  {
                     Limit[0] = '\0';
                     Limit[1] = '\0';
                  }
               }
               if (LFNIndex != (LD->Ord & 0x3F) || (LFNIndex <= 0))
                  LFNIndex = -1;
               else
                  CopyLFN((char *)FindName + --LFNIndex * 26, LD);

               D = NextDir(Drive, &Pos_Copy);
               Kind = EntryType(D);
            }
            if (LFNIndex == 0) //forget checksum to speedup
            {
               if(FileInfo)
               {
                  *FileInfo = *D;
                  FileInfo->NTReserved = MT_ENUM_FIND_LFN;
               }
               break;
            }
         }

         if(Kind == InUse)
         {
             if((MakeShortFileName(D, (char *)FileName, MaxLength) == RTF_NO_ERROR))
             {
                FileNameExtendToWCHAR((char *)FileName, FS_MAX_SFN_NATIVE_FILE_NAME_LENGTH_B);

                if(FileInfo)
                {
                   *FileInfo = *D;

                   // handle 0xE5 case
                   if (FileInfo->FileName[0] == 0x05)
                      FileInfo->FileName[0] = 0xE5;

                   FileInfo->NTReserved = MT_ENUM_FIND_SFN;
                }
                MTCheckFileNameCase(FileName, MaxLength, D->NTReserved);
                break;
             }
             else  // make short file name failed...
             {
                fs_util_trace_err_noinfo(RTF_NO_MORE_FILES);

                XRAISE(RTF_NO_MORE_FILES);
             }
         }
         else  // it's messed up, InUse does not follows LFN entries
         {
             fs_util_trace_err_noinfo(RTF_FILE_NOT_FOUND);

             XRAISE(RTF_FILE_NOT_FOUND);
         }
         break;
      default:
         Result = XVALUE; //API dose not need XHANDLED
         break;
      case XFINALLY:
         break;
   XENDX

   return Result;
}

int RTFAPI RTFMakeFilePathByHint(WCHAR DriveLetter, UINT DirCluster, UINT DirIndex, WCHAR * FileName, UINT MaxLength)
{
   int volatile Result = RTF_NO_ERROR;
   RTFDrive * Drive;
   RTFDOSDirEntry FileInfo;
   RTFDirLocation DSR, LfnDSR;
   const RTFDOSDirEntry *D;
   LFNDirEntry *LD;
   UINT  StartCluster, PrevStartCluster = 0, TargetCluster, NameLen, BufferLeft = MaxLength;
   int   SearchInRoot = 0;
   int   Kind;
   int   LFNIndex     = -1;
   BYTE  CheckSum     = 0;
   BYTE  TargetFound  = 0;
   BYTE  *TempName    = NULL;
   WCHAR *pPath = (FileName + (MaxLength >> 1) - 1);

   *pPath = 0;  // fill the tail

   XTRY
   case XCODE:
       Drive = LocateDrive(fs_util_wchar_toupper(DriveLetter) - MT_BASE_DRIVE_LETTER, HasFileSystem, NULL);

       SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Drive->Dev, RTF_INFINITE);

       TempName = (BYTE *)get_ctrl_buffer(RTF_MAX_PATH);

       if(DirCluster==0 && DirIndex==0)
       {
           goto add_root_info;
       }

       DSR.Cluster = DirCluster;
       DSR.Index = DirIndex;

       Result = GetFileInfoByHint(Drive, &FileInfo, (WCHAR*)TempName, RTF_MAX_PATH / 2, &DSR);

       if(Result < RTF_NO_ERROR ||
          !(FileInfo.Attributes & RTF_ATTR_DIR) ||
          FileInfo.Attributes & RTF_ATTR_VOLUME)
       {
          fs_util_trace_err_noinfo(RTF_PATH_NOT_FOUND);

          XRAISE(RTF_PATH_NOT_FOUND);
       }
       TargetCluster = StartCluster = FIRST_FILE_CLUSTER(FileInfo);

       // get ".." entry
       D = StartDirSearch(Drive, StartCluster, 1, &DSR);

       // start with the first cluster number of this level
       StartCluster = FIRST_FILE_CLUSTER(*D);

       // if this level is root directory
       if(StartCluster == 0)
       {
           if(Drive->FATType == 32)
           {
               StartCluster = Drive->FirstDirSector;
           }
           else
           {
               StartCluster = RTF_ROOT_DIR;
           }
       }

       while (1)
       {
          /*--------------------------------------------------------------
           * Because root directory does not have "." and ".." entries,
           * StartCluster will not be updated (remain RTF_ROOT_DIR or FirstDirSector)
           * in the while-loop below. If StartCluster is in root directory the
           * second time, that means we were done in root directory.
           *--------------------------------------------------------------*/
          if((StartCluster == RTF_ROOT_DIR && (Drive->FATType == 12 || Drive->FATType == 16)) ||
             (StartCluster == Drive->FirstDirSector && Drive->FATType == 32))
          {
             if(SearchInRoot)
             {
                break;
             }
             SearchInRoot++;
          }

          D = StartDirSearch(Drive, StartCluster, 0, &DSR);
          LFNIndex = -1;    // reset LFNIndex for each level
          TargetFound = 0;  // reset TargetFound for each level

          while (D)
          {
              Kind = EntryType(D);

              if (Kind == NeverUsed)
              {
                 break;
              }
              else if (Kind == Lfn)
              {
                 LD = (void*)D;

                 if (LD->Ord & 0x40) // it's the start of an LFN
                 {
                    LfnDSR = DSR;    // remember the 1st LFN entry's location
                    LFNIndex = LD->Ord & 0x3F;
                    CheckSum = LD->CheckSum;
                 }

                 if((LD->CheckSum != CheckSum) || (LFNIndex != (LD->Ord & 0x3F)) || (LFNIndex <= 0))
                    LFNIndex = -1;
                 else
                 	LFNIndex--;
              }
              else if (Kind == InUse)
              {
                  if (memcmp((char*)D->FileName, ".. ", 3) == 0)
                  {
                      PrevStartCluster = StartCluster;
                      StartCluster = FIRST_FILE_CLUSTER(*D);

                      if (StartCluster == 0)
                         StartCluster = (Drive->FATType == RTFAT32) ? Drive->FirstDirSector : RTF_ROOT_DIR;
                  }
                  else if (FIRST_FILE_CLUSTER(*D) == TargetCluster)
                  { // found

                     TargetFound = 1;

                     /* Get the Dir Name */
                     if ((LFNIndex == 0) && (CheckSum == ShortNameCheckSum((const BYTE*) D->FileName)))
                        Result = GetFileInfoByHint(Drive, &FileInfo, (WCHAR*)TempName, RTF_MAX_PATH / 2, &LfnDSR);
                     else
                        Result = GetFileInfoByHint(Drive, &FileInfo, (WCHAR*)TempName, RTF_MAX_PATH / 2, &DSR);

                     if (Result < RTF_NO_ERROR)
                     {
                        fs_util_trace_err_noinfo(RTF_PATH_NOT_FOUND);

                        XRAISE(RTF_PATH_NOT_FOUND);
                     }

                     /* copy the name to the path buffer */
                     NameLen = (kal_dchar_strlen((char*)TempName) >> 1);
                     pPath -= (NameLen + 1);

                     if(pPath < FileName)
                     {
                        fs_util_trace_err_noinfo(RTF_OUT_OF_BUFFERS);

                        XRAISE(RTF_OUT_OF_BUFFERS);
                     }

                     kal_dchar_strcpy((char*)pPath, (char*)TempName);
                     pPath[NameLen] = '\\';

                     BufferLeft -= ((NameLen + 1) * sizeof(WCHAR));  // "xxxxxx\"

                     // goto upper directory
                     break;
                  }
              }

              if (Kind != Lfn)
                 LFNIndex = -1;

              D = NextDir(Drive, &DSR);  // check if the next entry is the target directory
          }

          // parent is not found || ".." is not found in this level
          if((!TargetFound) || (SearchInRoot == 0 && PrevStartCluster == TargetCluster))
          {
              fs_util_trace_err_noinfo(RTF_PATH_NOT_FOUND);

              XRAISE(RTF_PATH_NOT_FOUND);
          }

          TargetCluster = PrevStartCluster;  // update TargetCluster as the 1st cluster of this level
       }
add_root_info:
       // Add drive information
       pPath -= 3;

       if(pPath < FileName)
       {
          fs_util_trace_err_noinfo(RTF_OUT_OF_BUFFERS);

          XRAISE(RTF_OUT_OF_BUFFERS);
       }

       pPath[0] = DriveLetter;
       pPath[1] = ':';
       pPath[2] = '\\';

       kal_dchar_strcpy((char*)FileName, (char*)pPath);
       break;

   default:
      Result = XVALUE;
      break;
   case XFINALLY:
   	  if (TempName != NULL)
         free_ctrl_buffer(TempName);

      SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV);
      break;
   XEND_API

   fs_util_check_stack();

   return Result;
}

/*-----------------------------------*/
int RTFAPI RTFDeleteByHint(WCHAR DriveLetter, UINT DirCluster, UINT DirIndex)
{
   volatile int start_fat_deletion = 0;
   int volatile Result = RTF_NO_ERROR;
   RTFDirLocation DSR;
   const RTFDOSDirEntry * D;
   RTFile * volatile f = NULL;
   WCHAR FileName[4] = { 0 };
   BYTE CheckSum = 0; /* Remove RVCT warning, Karen Hsu, 2004/11/02, MOD */
   int LFNIndex = -1;

   XTRY
   case XCODE:
         kal_dchar_strcpy((char*)FileName, (char*)L"X:\\");
         FileName[0] = DriveLetter;
         f = ParseFileName((char *)FileName);

         D = StartDirSearch(f->Drive, DirCluster, DirIndex, &DSR);

         if (NULL == D)
            XRAISE(RTF_PATH_NOT_FOUND);

         if (EntryType(D)==Lfn)
         {
             const LFNDirEntry * LD = (void*) D;

             if (LD->Ord & 0x40) // it's the start of an LFN
             {
                 LFNIndex = LD->Ord & 0x3F;
                 CheckSum = LD->CheckSum;
                 f->DirEntry.LongPos.Cluster = DirCluster;
                 f->DirEntry.LongPos.Index = DirIndex;
                 LFNIndex--;
             }
             else
             {
                 XRAISE(RTF_PATH_NOT_FOUND);
             }

             while((D = NextDir(f->Drive, &DSR)) != NULL && EntryType(D) != InUse)
             {
                LD = (LFNDirEntry *)D;
                if ((LD->CheckSum != CheckSum) || (LFNIndex != (LD->Ord & 0x3F)))
                {
                    XRAISE(RTF_PATH_NOT_FOUND);
                }
                else
                {
                    LFNIndex--;
                }
             }

             if(LFNIndex!=0)
             {
                XRAISE(RTF_PATH_NOT_FOUND);
             }
         }

         if(D==0 || EntryType(D)==NeverUsed)
         {
            XRAISE(RTF_PATH_NOT_FOUND);
         }

         if(EntryType(D)==InUse)
         {
             if((LFNIndex == 0) && (CheckSum != ShortNameCheckSum((const BYTE*) D->FileName)))
             {
                 XRAISE(RTF_PATH_NOT_FOUND);
             }
             f->DirEntry.ShortPos.Cluster = DSR.Cluster;
             f->DirEntry.ShortPos.Index = DSR.Index;
             f->DirEntry.Dir = *D;
         }
         else
         {
             XRAISE(RTF_PATH_NOT_FOUND);
         }

         CheckNotOpen(f);

         if (f->DirEntry.Dir.Attributes & (RTF_ATTR_DIR | RTF_ATTR_VOLUME))
            /* Change error message for FMT, Karen Hsu, 2004/04/20, MOD START */
         {
            fs_util_trace_err_noinfo(MT_READ_ONLY_ERROR);

            XRAISE(MT_READ_ONLY_ERROR);
         }
            /* Change error message for FMT, Karen Hsu, 2004/04/20, MOD END */

         DeleteDirEntry(f);

         if (FIRST_FILE_CLUSTER(f->DirEntry.Dir) != 0)
         //quota
         {
            start_fat_deletion = 1;
            FATDelete(f->Drive, FIRST_FILE_CLUSTER(f->DirEntry.Dir), f);
         }

         if (((f->Dev->DeviceFlags & RTF_DEVICE_LAZY_WRITE) == 0) || (FileCount(f->Dev) <= 1))
            FlushAllBuffers(f->Dev);

         break;
      default:
         if(start_fat_deletion && XVALUE == RTF_FAT_ALLOC_ERROR)
            XHANDLED;
         Result = XVALUE;
         break;
      case XFINALLY:
         if (f)
         {
            #ifdef __FS_OPEN_HINT__
            /*
             * Expire all hints
             * Better solution: Delete hint with the same drive and location.
             */
            MTHintExpireByDrive(f->Drive);
            #endif

            FreeFTSlotAndDevice(f);
         }
         break;
   XEND_API

   return RTF_NO_ERROR;
}

/*-----------------------------------*/
int RTFAPI RTFGetAttributesByHint(WCHAR DriveLetter, UINT DirCluster, UINT DirIndex)
{
   int volatile Result = RTF_NO_ERROR;
   RTFDrive * Drive;
   WCHAR TempName[13];
   RTFDOSDirEntry FileInfo;
   RTFDirLocation DSR;

   XTRY
   case XCODE:
         Drive = LocateDrive(fs_util_wchar_toupper(DriveLetter) - MT_BASE_DRIVE_LETTER, HasFileSystem, NULL);

         SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Drive->Dev, RTF_INFINITE);

         DSR.Cluster = DirCluster;
         DSR.Index = DirIndex;

         Result = GetFileInfoByHint(Drive, &FileInfo, (WCHAR*)TempName, sizeof(TempName), &DSR);
         if(Result<RTF_NO_ERROR)
         {
            fs_util_trace_err_noinfo(Result);

            XRAISE(Result);
         }
         break;
      default:
         Result = XVALUE;
         break;
      case XFINALLY:
         SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV);
         break;
   XEND_API

   if(Result>=RTF_NO_ERROR)
       Result = FileInfo.Attributes;

   return Result;
}

/*-----------------------------------*/
int RTFAPI RTFSetAttributesByHint(WCHAR DriveLetter, UINT DirCluster, UINT DirIndex, BYTE Attributes)
{
   int volatile Result = RTF_NO_ERROR;
   RTFDrive * Drive;
   RTFDirLocation DSR;
   RTFDOSDirEntry * D;

   Attributes &= RTF_ATTR_ANY;

   XTRY
      case XCODE:
         Drive = LocateDrive(fs_util_wchar_toupper(DriveLetter) - MT_BASE_DRIVE_LETTER, HasFileSystem, NULL);

         SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Drive->Dev, RTF_INFINITE);
         D = StartDirSearch(Drive, DirCluster, DirIndex, &DSR);

         while(D && EntryType(D)!=NeverUsed)
         {
             if (EntryType(D) == InUse)
             {
                  // volume labels are not allowed
                  // dir is not allowed
                  if ((D->Attributes ^ Attributes) & (RTF_ATTR_DIR | RTF_ATTR_VOLUME))
                  {
                      fs_util_trace_err_noinfo(RTF_ACCESS_DENIED);

                      XRAISE(RTF_ACCESS_DENIED);
                  }

                  D->Attributes = Attributes;
                  SetDirty(Drive->Dev);
                  break;
             }
             // check if the next entry is the target directory
             D = NextDir(Drive, &DSR);
         }

         if (((Drive->Dev->DeviceFlags & RTF_DEVICE_LAZY_WRITE) == 0) || (FileCount(Drive->Dev) <= 1))
               FlushAllBuffers(Drive->Dev);
         break;
      default:
         Result = XVALUE;
         break;
      case XFINALLY:
         SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV);
         break;
   XEND_API
   return RTF_NO_ERROR;
}

int RTFAPI RTFHintGetParent(WCHAR DriveLetter, UINT DirCluster, UINT DirIndex, UINT *ParentCluster, UINT *ParentIndex)
{
   int volatile Result = RTF_NO_ERROR;
   RTFDrive * Drive;
   RTFDOSDirEntry FileInfo;
   RTFDirLocation DSR;
   const RTFDOSDirEntry * D;
   UINT StartCluster, PrevStartCluster = 0, TargetCluster, Level = 0;
   int TargetFound   = 0;
   int Kind;
   RTFDirLocation LongPos = {0};
   BYTE CheckSum     = 0; /* Remove RVCT warning, Karen Hsu, 2004/11/02, MOD */
   BYTE SearchInRoot = 0;
   int LFNIndex      = -1;

   WCHAR TempName[13];

   XTRY
   case XCODE:
       Drive = LocateDrive(fs_util_wchar_toupper(DriveLetter) - MT_BASE_DRIVE_LETTER, HasFileSystem, NULL);

       SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Drive->Dev, RTF_INFINITE);

       if(DirCluster == RTF_ROOT_DIR && (Drive->FATType == 12 || Drive->FATType == 16))
       {
           *ParentCluster = 0;
           *ParentIndex = 0;
           break;
       }

       DSR.Cluster = DirCluster;
       DSR.Index = DirIndex;

       Result = GetFileInfoByHint(Drive, &FileInfo, (WCHAR*)TempName, sizeof(TempName), &DSR);

       if(Result < RTF_NO_ERROR ||
          !(FileInfo.Attributes & RTF_ATTR_DIR) ||
          FileInfo.Attributes & (RTF_ATTR_VOLUME))
       {
          fs_util_trace_err_noinfo(RTF_PATH_NOT_FOUND);

          XRAISE(RTF_PATH_NOT_FOUND);
       }

       TargetCluster = StartCluster = FIRST_FILE_CLUSTER(FileInfo);

       /* Get the second directory entry of this folder, it should be ".." */
       D = StartDirSearch(Drive, StartCluster, 1, &DSR);

       /* check its integrity */
       if(memcmp((char*)D->FileName, ".. ", 3) != 0)
       {
          fs_util_trace_err_noinfo(RTF_PATH_NOT_FOUND);

          XRAISE(RTF_PATH_NOT_FOUND);
       }

       /* get the first cluster number of this level */
       StartCluster = FIRST_FILE_CLUSTER(*D);

       /* If this level is exactly the root, return (Cluster, Index) = (0, 0) */
       if(StartCluster == 0 ||
          (StartCluster==Drive->FirstDirSector && Drive->FATType==32))
       {
          *ParentCluster = 0;
          *ParentIndex = 0;
          break;
       }

       /*---------------------------------------------------------------
        * For unknown reason, we found some ".." entries' first cluster value
        * is not 0 even if their parents is in root directory.
        * Thus we provide a tolerance here to cover this exceptional case. (W09.24)
        *---------------------------------------------------------------*/
       D = StartDirSearch(Drive, StartCluster, 0, &DSR);

       // if this level do not have ".", it should be root directory, return (0, 0)
       if(memcmp((char*)D->FileName, ". ", 2) != 0)
       {
          *ParentCluster = 0;
          *ParentIndex = 0;
          break;
       }

       while (1)
       {
          if((StartCluster == RTF_ROOT_DIR && (Drive->FATType == 12 || Drive->FATType == 16)) ||
             (StartCluster == Drive->FirstDirSector && Drive->FATType == 32))
          {
             SearchInRoot++;
          }

          LFNIndex = -1;     // reset LFNIndex for each level
          TargetFound = 0;   // reset TargetFound for each level

          while(D)
          {
              Kind = EntryType(D);

              if (Kind == NeverUsed)
              {
                 break;
              }
              else if (Kind == InUse)
              {
                  if (memcmp((char*)D->FileName, ".. ", 3) == 0)
                  {
                      /* find the ".." entry, save the information */
                      PrevStartCluster = StartCluster;
                      StartCluster = FIRST_FILE_CLUSTER(*D);

                      if(StartCluster == 0)
                        StartCluster = (Drive->FATType == RTFAT32) ? Drive->FirstDirSector : RTF_ROOT_DIR;
                  }
                  else if (FIRST_FILE_CLUSTER(*D) == TargetCluster)
                  { // found

                      TargetFound = 1;
                      Level++;

                      /* Level == 1 means that the directory entry of (DirCluster, DirIndex) is found. */
                      /* Level == 2 means that the parent directory entry of (DirCluster, DirIndex) is found. */
                      if (Level == 2)
                      {
                        if ((LFNIndex == 0) && (CheckSum == ShortNameCheckSum((const BYTE*) D->FileName)))
                        {
                            *ParentCluster = LongPos.Cluster;
                            *ParentIndex = LongPos.Index;
                        }
                        else
                        {
                            *ParentCluster = DSR.Cluster;
                            *ParentIndex = DSR.Index;
                        }
                      }
                      break;
                  }
              }
              else if (Kind == Lfn)
              {
                  const LFNDirEntry * LD = (void*) D;

                  if (LD->Ord & 0x40) // it's the start of an LFN
                  {
                      /* Save the long file name information */
                      LFNIndex = LD->Ord & 0x3F;
                      CheckSum = LD->CheckSum;
                      LongPos = DSR;
                  }

                  if ((LD->CheckSum != CheckSum) || (LFNIndex != (LD->Ord & 0x3F)) || (LFNIndex <= 0))
                      LFNIndex = -1;
                  else
                      LFNIndex--;
              }

              // reset LFN if a new other-type entry is found (to prevent returning wrong parent location)
              if (Kind != Lfn)
                 LFNIndex = -1;

              // check if the next entry is the target directory
              D = NextDir(Drive, &DSR);
          }

          // parent is not found || ".." is not found in this level (NOTE that root directory does not have ".."!)
          if((!TargetFound) || (SearchInRoot == 0 && PrevStartCluster == TargetCluster))
          {
              fs_util_trace_err_noinfo(RTF_PATH_NOT_FOUND);

              XRAISE(RTF_PATH_NOT_FOUND);
          }

          /* To get the parent, search two level folder is enough */
          if(Level >= 2)
          {
              break;
          }

          TargetCluster = PrevStartCluster;

          D = StartDirSearch(Drive, StartCluster, 0, &DSR);
       }

       /* If the level is larger than 2, it is not valid parent. */
       if(Level != 2)
       {
          fs_util_trace_err_noinfo(RTF_PATH_NOT_FOUND);

          XRAISE(RTF_PATH_NOT_FOUND);
       }
       break;

   default:
      Result = XVALUE;
      break;
   case XFINALLY:
      SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV);
      break;
   XEND_API

   fs_util_check_stack();

   return Result;
}

#endif /* __MTP_ENABLE__ */


