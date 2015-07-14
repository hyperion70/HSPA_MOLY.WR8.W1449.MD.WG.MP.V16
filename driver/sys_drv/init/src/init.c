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
 *   init.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the HW initialization.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 *
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*******************************************************************************
 * Include header files
 *******************************************************************************/

#include "kal_public_api.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "kal_internal_api.h"
#include "kal_trace.h"
#include "reg_base.h"
#include "config_hw.h"
#include "emi_hw.h"
#include "pll.h"
#include "init.h"
#include "intrCtrl.h"
#include "isrentry.h"
#include "stack_buff_pool.h"
#include "fat_fs.h"
#include "drv_comm.h"
#include "bmt.h"
#include "dcl.h"
#include "wdt_hw_public.h"
#include "wdt_sw.h"
#include "drvpdn.h"
#include <stdio.h>
#include <string.h>
#if defined(__ARMCC_VERSION)
#include <rt_misc.h>   /* for __rt_lib_init() */
#endif
#include <stdlib.h>
#include "br_header_block.h"
#include "cache_sw.h"
#include "cache_sw_int.h"
#include "page.h"
#include "l1_interface.h"
#include "bl_features.h"
#include "bl_common.h"
#include "kbd_table.h"
#include "system_trc.h"
#include "init_trc_api.h"
#include "ex_item.h"
#include "mpu.h" 
#include "br_time_stamp.h"
#include "maui_time_stamp_util.h"
#include "bus_drv.h"
#include "cp15.h"
#include "ccci.h"

#ifdef __MULTI_BOOT__
#include "syscomp_config.h"
#include "multiboot_config.h"
#endif   /* __MULTI_BOOT__ */

#if defined(__DSP_FCORE4__)
#include "mdci.h"
#include "SST_dmdsp_ex.h"
#include "dmdsp_init.h"
#endif /* __DSP_FCORE4__ */

#if defined(__FOTA_DM__)
#include "fue_err.h"
#include "custom_fota.h"
#include "custom_img_config.h"
#include "fue.h"
#include "SSF_fue_support.h"
#endif /* __FOTA_DM__ */

#ifdef __CENTRALIZED_SLEEP_MANAGER__
#include "us_timer.h"
#endif /*__CENTRALIZED_SLEEP_MANAGER__*/


#if !defined(__UBL__) && !defined(__FUE__)
#ifdef __CENTRALIZED_SLEEP_MANAGER__
#include "ostd_public.h"
extern void RM_Init( void );
#endif /* __CENTRALIZED_SLEEP_MANAGER__ */
extern void MCU_RM_UnGateMCUTOPSM( void );
#endif

/*******************************************************************************
 * Define pragma
 *******************************************************************************/

#if defined(KAL_ON_NUCLEUS) && defined(NU_DEBUG)
#define RTOS_DEBUG
#endif	/* KAL_ON_NUCLEUS && NU_DEBUG */

#if defined(KAL_ON_THREADX) && !defined(TX_DISABLE_ERROR_CHECKING)
#define RTOS_DEBUG
#endif	/* KAL_ON_THREADX && !TX_DISABLE_ERROR_CHECKING */

#if defined(KAL_ON_OSCAR)
#define RTOS_DEBUG
#endif  /* KAL_ON_OSCAR */

#if !defined(__BL_ENABLE__)
#ifndef __NO_MDBL_SHARE_INFO__
#define __NO_MDBL_SHARE_INFO__
#endif
#endif

#if defined(_SIMULATION) || defined(__COSIM_SIMPLE_INIT__)
#ifndef __NO_MDBL_SHARE_INFO__
#define __NO_MDBL_SHARE_INFO__
#endif
#endif

/*******************************************************************************
 * Define global data
 *******************************************************************************/
static kal_uint32 init_ev_timestamp = 0;
static kal_uint16 _boot_mode = 0 /* NORMAL Mode */;
static kal_bool _IsBootForUSBAT = KAL_FALSE;
kal_uint32 init_duration;
WDT_CTRL_ENABLE_T wdt_data;
DCL_HANDLE init_dcl_wdt_handle;
DCL_HANDLE init_dcl_handle;
static kal_uint32 g_l_sw_misc_l = 0;

#if !defined(__NO_MDBL_SHARE_INFO__)
__attr_cached_ext_zi BL_Info_Wrapper_st g_pass_info;
#endif /* !__NO_MDBL_SHARE_INFO__ */

__attr_emiinit_zi ECO_VERSION eco_version; /* only used in PLL setup */

/* [BB porting] make sure if BL will enable, if not, check the address is correct
 * Need to use a segment of internal RAM to generate randum number seed.
 * We pick up address 0x40002000 since it won't be modified by other
 * program such as bootloader.
 */

#if defined(MT6280)
static const kal_uint32 RAND_GEN_START_ADDR = 0x9000A000;
#elif defined(MT6575) || defined(MT6577)
static const kal_uint32 RAND_GEN_START_ADDR = 0x50004000;
#elif defined(MT6589) || defined(MT6572) || defined(MT6582) || defined(MT6571) || defined(MT6580) || defined(MT6592)
static const kal_uint32 RAND_GEN_START_ADDR = 0x70002000;
#else
static const kal_uint32 RAND_GEN_START_ADDR = 0x40002000;
#endif

/* g_bl_maui_paired_ver is defined for USB DL 2.0 and will be used by MAUI build process only */
__attr_lead_part const kal_uint32 g_bl_maui_paired_ver = BL_MAUI_PAIRED_VER;


/*******************************************************************************
 * Declare import data
 *******************************************************************************/
extern kal_uint32 WATCHDOG_BASE;
extern kal_uint32 WATCHDOG_RESTART_CMD;
extern boot_mode_type system_boot_mode;
extern kal_uint32 SYS_Stack_Pool[];
extern kal_uint32 rand_num_seed;    /* generate 1st phase random seed */

#if defined(__DSP_BOOT_SEC__)
extern kal_bool sync_status;
#endif  /* __DSP_BOOT_SEC__ */

/*******************************************************************************
 * Declare function prototype
 *******************************************************************************/
static void INT_SetBootMode(void);
static void systemInitialization(void);
static void HWDInitialization(void);
static void systemInitializeResource(void);
void SST_InvokEngine(kal_int32, kal_int32);

/*******************************************************************************
 * Declare import function prototype
 *******************************************************************************/
extern int  mainp(void);
extern void Drv_Init_Phase1(void);
extern void Drv_Init_Phase2(void);
extern void kal_initialize_mem(void);
extern void kal_profile_init(void);
extern void fatal_error_handler(kal_int32, kal_int32);
extern void NFI_Reset(void);
extern kal_char *release_dsp_fw(void);
extern kal_char *release_dsp_ptch(void);
extern kal_char *release_verno(void);
extern kal_char *release_branch(void);
extern kal_char *release_hw_ver(void);

#ifdef __SECURE_DATA_STORAGE__
extern kal_int32 SDS_Init(void);
#endif

#if defined(__BOOT_CERT__)
extern kal_uint32 srd_dl_ctrl_check(void);
extern kal_uint32 srd_dl_ctrl_pre_check(void);
#endif

#ifdef __SV5_ENABLED__
extern kal_uint32 DummyReference(void);
#endif

extern kal_uint32 SLA_Init(void);           /* Controlling SWLA by NVRAM */
/* Enable SWLA by default for easy debug */
#ifdef DEBUG_SWLA
extern kal_uint32 SLA_Enable(void);
#endif

#ifdef IDMA_DOWNLOAD
extern void idma_load(void);
#endif /* IDMA_DOWNLOAD */

#ifdef MTK_SLEEP_ENABLE
extern void L1SM_Init( void );
#ifdef __MTK_UL1_FDD__
extern void UL1SM_Init(void);
#endif
#endif

#ifndef L1_NOT_PRESENT
extern void L1D_SetInitMode( kal_int16 mode );
#ifdef __HW_DIVIDER__
extern void HW_Divider_Initialization(void);
#endif  /* __HW_DIVIDER__ */
#endif /* !L1_NOT_PRESENT */

#if !defined(__MAUI_BASIC__)
extern void Initialize_FDD_tables(void);
extern int Check_NORFlash_Formatted(void);
#endif

#ifdef __USB_ENABLE__
extern void isrCTIRQ1_USBPowerOn(void);
#endif /*__USB_ENABLE__*/

#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)
#if !defined(__NFB_SINGLE_ROM__)
extern kal_bool NFB_SecondaryImageLoaded;
extern void NFB_LoadingSecondaryMAUI(void);
#endif /* __NFB_SINGLE_ROM__ */
extern void NFB_FOTA_Prepare_Bootup(void);
#endif /* _NAND_FLASH_BOOTING_ || __EMMC_BOOTING__ */


#if defined(__NEW_OS_TICK__) && !defined(__MEUT__)
extern void RTOS_EnableOSTick(void);
#endif /* __NEW_OS_TICK__ && !__MEUT__ */


#if defined(__NUCLEUS_VERSION_2__)
extern void TCCT_Schedule(VOID);
extern void **TCCT_Dispatch_LISR(INT, VOID *);
extern void TCCT_Dispatch_Nested_LISR(INT);
extern void **(*ESAL_GE_ISR_OS_Entry)(INT, VOID *);
extern void (*ESAL_GE_ISR_OS_Nested_Entry)(INT);
extern void (*ESAL_GE_STK_Unsol_Switch_OS_Entry)(VOID);
#endif /*__NUCLEUS_VERSION_2__*/

extern UL1D_RepairSRAM(void);
extern tl1_repair_sram(void);

/*__FUE__ compile option is used for FOTA firmware update engine */
/*add this  compile option  to avoid compiling other function*/
#ifndef __FUE__
/*
 * NoteXXX:
 *    Please DO NOT place your code in the execution region EMIINITCODE.
 *    Code in this region is used for EMI/PLL initialization, and will be
 *    OVERWRITTEN after INT_InitRegions.
 */
/* [BB porting] Make sure the flow to set EMI&SFI and the placement of the code */
/*************************************************************************
* FUNCTION
*  INT_SetEMIPLL
*
* DESCRIPTION
*  This function dedicates for PLL setting.
*
* CALLS
*  Non
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
__attr_emiinit_code void INT_SetEMIPLL(void)
{
    custom_setEMI();
    INT_SetPLL(PLL_MODE_MAUI);
}

/*************************************************************************
* FUNCTION
*  INT_SetChipReg
*
* DESCRIPTION
*   This function sets registers on the chip at system initial stage.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void INT_SetChipReg()
{
#if defined(MT6280) && defined(__TRADITIONAL_MODEM_CARD__)
    {
        extern void cp15_arm_wfi_loop();
        if(((*MD_CHIP_STATUS) & 0x8) != 0) {  /* system bonding router mode */
            /* For dongle sw on wifi router chip */
            // For MT6280 DataCard Product:
            // Make ARM9 go into WFI infinite loop and wait for clock disable
            // Step 1. Disable AP WDT while enable MD WDT
            *(volatile kal_uint32*)(AP_RGU_base+0x0000) = 0x00002220;
            // Step 2. Config ARM9 boot slave as WFI Infinite loop
            *(volatile kal_uint32*)(AP_BOOT_SLV_base+0x8888) = 0x00000100;
            *(volatile kal_uint32*)(AP_BOOT_SLV_base+0x0000) = (kal_uint32)cp15_arm_wfi_loop;
            // Step 3. Release ARM9 Reset Signal
            *(volatile kal_uint32*)(AP_RGU_base+0x0018) = 0x00000022;
            // Step 4. Polling ARM9 is in WFI
            while(((*AP_OST_STA) & 0x8000) == 0);
        }
    }
#endif
}

/*************************************************************************
* FUNCTION
*  Application_Initialize
*
* DESCRIPTION
*   This function implements project protocol stack, hardware depedent
* initialization
*
* CALLS
*  Initialize()
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
#if defined(KAL_ON_NUCLEUS)
#if defined(__NUCLEUS_VERSION_2__)
void Application_Initialize(NU_MEMORY_POOL *system_memory, NU_MEMORY_POOL *uncached_memory)
#else
void Application_Initialize (void *first_available_memory)
#endif /* __NUCLEUS_VERSION_2__ */
#elif defined(KAL_ON_THREADX)
void tx_application_define(void *first_unused_memory)
#endif
{
    TS_END(TSID_INIT_ASM);

    TS_BEGIN(TSID_INIT_APPINIT);
    print_bootup_trace(SST_INIT_APPINIT_START);


    CPU_SET_STACK_MPU_PROTECT(MPU_REGION_SP_KERNEL, SYS_Stack_Pool);


    INT_Trace_Enter(INIT_CLIB1, 0);
    clib_basic_init();
    INT_Trace_Exit(INIT_CLIB1, 0);
    
#ifdef __SV5_ENABLED__
    /* Toggle */
    DummyReference();
#endif

    /* Set WDT base for nuclcues usage */
    WATCHDOG_BASE = Get_WATCHDOG_BASE();
    WATCHDOG_RESTART_CMD = Get_WATCHDOG_RESTART_CMD();

    /* For smart phone project, do the handshake with AP processor */
    INT_Trace_Enter(INIT_CCCIHS1, 0);
    ccci_init_handshake_phase1();
    INT_Trace_Exit(INIT_CCCIHS1, 0);
    
#if defined(__DSP_FCORE4__)
    /* For project with Fcore DSP, handshake with DSP */
    INT_Trace_Enter(INIT_MDCIHS1, 0);
    mdci_init_handshake_phase1();
    INT_Trace_Exit(INIT_MDCIHS1, 0);
#endif  /* __DSP_FCORE4__ */

    /*
     * NoteXXX: Not all HW modules are avaiable in the Co-SIM envrionment.
     *          Need to bypass 32K calibration in Co-SIM (via __COSIM_BYPASS_DRV__).
     */
#if !defined(__COSIM_BYPASS_DRV__)
    /* no need to calibrate 32KHz clock if bootloader had done it */
#if !defined(__BL_ENABLE__)
    /* 32K clock calibration */
    HW_TDMA_Start();
    MCU_RM_UnGateMCUTOPSM();
#endif  /* !__BL_ENABLE__ */
#endif    /* !__COSIM_BYPASS_DRV__ */

    INT_Trace_Enter(INIT_BOOTMODE, 1);
    /*
     * print_bootup_trace_duration() can be invoked after TDMA timer is initialized
     */
    INT_SetBootMode();
    INT_Trace_Exit(INIT_BOOTMODE, 1);

    /* Initialize system specific module */
    INT_Trace_Enter(INIT_SYSTEMINIT, 1);
    systemInitialization();
    INT_Trace_Exit(INIT_SYSTEMINIT, 1);
    
    /*
    * NoteXXX: Not all HW modules are avaiable in the Co-SIM envrionment.
    *          Need to bypass hardware initialization in Co-SIM (via __COSIM_BYPASS_DRV__).
    *          But watchdog is still needed to be disabled.
    */

    INT_Trace_Enter(INIT_HWDINIT, 0);
    HWDInitialization();
    INT_Trace_Exit(INIT_HWDINIT, 0);
    
#if defined(_NAND_FLASH_BOOTING_) || defined(__NOR_FLASH_BOOTING__) || defined(__EMMC_BOOTING__)
    #if defined(__FOTA_DM__) && (defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__))
    INT_Trace_Enter(INIT_PREFOTA, 1);
    NFB_FOTA_Prepare_Bootup();
    INT_Trace_Exit(INIT_PREFOTA, 1);
    #endif /* __FOTA_DM__ && (_NAND_FLASH_BOOTING_ || __EMMC_BOOTING__) */
    #if !defined(__NFB_SINGLE_ROM__)
    INT_Trace_Enter(INIT_LOADSECMAUI, 1);
    NFB_LoadingSecondaryMAUI();
    INT_Trace_Exit(INIT_LOADSECMAUI, 1);
    
    /* Initialize demand paging */
    INT_Trace_Enter(INIT_DEMP, 1);
    demp_init();
    INT_Trace_Exit(INIT_DEMP, 1);
    #endif /* !__NFB_SINGLE_ROM__ */
#endif /* _NAND_FLASH_BOOTING_ || __EMMC_BOOTING__ */

#if defined(__BOOT_CERT__)
    srd_dl_ctrl_pre_check();
#endif

    /*
    * NoteXXX: Not all HW modules are avaiable in the Co-SIM envrionment.
        *          Need to bypass DRV INIT in Co-SIM (via __COSIM_BYPASS_DRV__).
    */
#if !defined(__COSIM_BYPASS_DRV__)
    INT_Trace_Enter(INIT_DRV2, 0);
    Drv_Init_Phase2();
    INT_Trace_Exit(INIT_DRV2, 0);
#endif    /* !__COSIM_BYPASS_DRV__ */


#if defined(__BOOT_CERT__)
    srd_dl_ctrl_check();
#endif
    /* Resource initialization */
    INT_Trace_Enter(INIT_RESINIT, 1);
    systemInitializeResource();
    INT_Trace_Exit(INIT_RESINIT, 1);
    
    INT_Trace_Enter(INIT_CLIB2, 1);
    clib_init();
    INT_Trace_Exit(INIT_CLIB2, 1);
    
    /*The following init must be done before mainp() for KTEST need scheduling work*/
#if defined(__NUCLEUS_VERSION_2__)
    /* Set nucleus plus 2.1 scheduling, LISR & Nested LISR function ptr,
      we can change the function ptr when we need. */
    ESAL_GE_STK_Unsol_Switch_OS_Entry = TCCT_Schedule;
    ESAL_GE_ISR_OS_Entry = TCCT_Dispatch_LISR;
    ESAL_GE_ISR_OS_Nested_Entry = TCCT_Dispatch_Nested_LISR;
#endif /* __NUCLEUS_VERSION_2__ */

#if defined(__SV5_ENABLED__) && defined(__SECURE_RO_ENABLE__)
    CBRUtl_InitService();
#endif

#ifdef __SECURE_DATA_STORAGE__
    SDS_Init();
#endif


    /* MAUI protocol stack entry routine */
    mainp();
        
    print_trace(SST_INIT_APPINIT_OK);

    INT_RandomSeedScramble();

    init_ev_timestamp = kal_get_systicks();

    SLA_Init();
#ifdef DEBUG_SWLA
    SLA_Enable(); // enable SWLA by default for easy debug
#endif

#ifdef __PRODUCTION_RELEASE__
#ifdef __MULTI_BOOT__
    if ( system_boot_mode!=FACTORY_BOOT )
#endif  /* __MULTI_BOOT__ */

    {
        /* Enable watch dog */
        wdt_data.fgEnable=KAL_TRUE;
        init_dcl_wdt_handle=DclWDT_Open(DCL_WDT,0);
        DclWDT_Control(init_dcl_wdt_handle,WDT_CMD_ENABLE,(DCL_CTRL_DATA_T*)&wdt_data);
        DclWDT_Close(init_dcl_wdt_handle);
    }
#endif /* __PRODUCTION_RELEASE__ */


    /* handshake to tell AP processor MD boot-up successfully */
    INT_Trace_Enter(INIT_CCCIHS2, 1);
    ccci_init_handshake_phase2(_boot_mode);
    INT_Trace_Exit(INIT_CCCIHS2, 1);
    
#if defined(__DSP_FCORE4__)
    INT_Trace_Enter(INIT_MDCIHS2, 1);
    mdci_init_handshake_phase2(0);
    INT_Trace_Exit(INIT_MDCIHS2, 1);
    
    INT_Trace_Enter(INIT_DMDSP2, 1);
    dmdsp_ex_init();
    INT_Trace_Exit(INIT_DMDSP2, 1);
    #endif  /* __DSP_FCORE4__ */

#if defined(__CPU_USAGE_ON_CATCHER__)
    kal_profile_enable();
#endif /* __CPU_USAGE_ON_CATCHER__ */

    TS_END(TSID_INIT_APPINIT);

#if !defined(_NAND_FLASH_BOOTING_)
    // ready to display 1st screen for NOR booting
    TS_END(TSID_INIT_READY_TO_DISPLAY);
#endif

    TS_END(TSID_INIT_TOTAL);

    // dump time stamp from UART
    TS_DumpTimeStamps();
    INT_backupBootLogs();
}


/*************************************************************************
* FUNCTION
*  INT_SetBootMode
*
* DESCRIPTION
*   This function sets global variables related to boot mode
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*   _boot_mode
*   g_l_sw_misc_l
*   _IsBootForUSBAT
*
*************************************************************************/
static void INT_SetBootMode(void)
{
    /* for SiP TDD SLT, force META bootup */
#if defined(__TDDSYS_SLT_FACTORY_BOOT__)
    *(volatile kal_uint16 *)BOOT_CONFIG_ADDR |= 0x0001;
#endif

    /* Multi-Boot */
#ifdef __MULTI_BOOT__

    _boot_mode = 0x1 & *(volatile kal_uint16 *)BOOT_CONFIG_ADDR;

    g_l_sw_misc_l =  *(volatile kal_uint16 *)BOOT_CONFIG_ADDR;

    if (0x4 & *(volatile kal_uint16 *)BOOT_CONFIG_ADDR) {
        _IsBootForUSBAT = KAL_TRUE;
    }

#ifndef L1_NOT_PRESENT
    /* Set mode for L1 usage */
    L1D_SetInitMode(_boot_mode);
#endif /* L1_NOT_PRESENT */

#endif /* __MULTI_BOOT__ */
}

/*************************************************************************
* FUNCTION
*  systemInitialization
*
* DESCRIPTION
*   This function implements the system specific initialization, including
*   interrupt central controller, FDD and KAL.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
static void systemInitialization(void)
{
    /* initialize the interrupt controller */
    initINTR();  /* initialize the interrupt controller */

    IRQ_LISR_Init();

#if !(defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)) || defined(__NANDFDM_MULTI_INSTANCE__)
    Initialize_FDD_tables();
#endif /* !(_NAND_FLASH_BOOTING_ || __EMMC_BOOTING__) || __NANDFDM_MULTI_INSTANCE__ */

    /* Register display handler */
    kal_register_print_string_function((kal_print_string_func_ptr)stack_print);

    /* Register stack fatal error handler */
    kal_register_fatal_error_handler((kal_error_func_ptr)fatal_error_handler);

    kal_initialize_mem();

    /* Initializing the Buffer Pool Information */
    stack_init_buff_pool_info();

    /* Create buffer pools */
    stack_resources_init();

    /* Initialize KAL resources */
    kal_initialize();

    /* Initialize KAL CPU usage profiling */
    kal_profile_init();

    /* Initialize memory dump switch */
    ex_memory_dump_init();
}


/*************************************************************************
* FUNCTION
*  HWDInitialization
*
* DESCRIPTION
*   This function implements hardware dependent initialization and
*   management
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
static void HWDInitialization(void)
{

#ifdef __USB_ENABLE__
    PW_CTRL_IS_USB_BOOT CtrlVal;
    DCL_HANDLE handle;
#endif

    INT_Trace_Enter(INIT_CHIPREG, 1);
    INT_SetChipReg();
    INT_Trace_Exit(INIT_CHIPREG, 1);

    /* Initialize bus related optimization */
    /* Note Bus_Init() should be invoked after CacheInit() since *
     * prefetch buffer must be enabled after icache is enabled.  */
    INT_Trace_Enter(INIT_BUS, 1);
    Bus_Init();
    INT_Trace_Exit(INIT_BUS, 1);


    /* HSPA, TDDSYS SRAM repair */
#if defined(__UMTS_RAT__) && defined(__UMTS_FDD_MODE__)
    INT_Trace_Enter(INIT_UL1DSRAMREPAIR, 1);
    UL1D_RepairSRAM();
    INT_Trace_Exit(INIT_UL1DSRAMREPAIR, 1);
#endif

#if defined(__UMTS_TDD128_MODE__)
    INT_Trace_Enter(INIT_TL1SRAMREPAIR, 1);
    tl1_repair_sram();
    INT_Trace_Exit(INIT_TL1SRAMREPAIR, 1);
#endif

#ifdef __CENTRALIZED_SLEEP_MANAGER__
    INT_Trace_Enter(INIT_USC, 1);
    USC_Start();
    INT_Trace_Exit(INIT_USC, 1);
    
    /* RM_Init() should be invoked before OSTD_Init() and before 2G and 3G SMM's init() function */
    INT_Trace_Enter(INIT_RM, 1);
    RM_Init();
    INT_Trace_Exit(INIT_RM, 1);
    
    INT_Trace_Enter(INIT_OSTD, 1);
    OSTD_Init();
    INT_Trace_Exit(INIT_OSTD, 1);
    #endif /*__CENTRALIZED_SLEEP_MANAGER__*/

#ifdef MTK_SLEEP_ENABLE
    /* Added by Anthony Chin 03/18/2002. For sleep mode management. */
    INT_Trace_Enter(INIT_L1SM, 1);
    L1SM_Init();
    INT_Trace_Exit(INIT_L1SM, 1);
    
#ifdef __MTK_UL1_FDD__
    /* Be sure OSTD_Is3gEnabled() is called after OSTD_Init() */
    if (OSTD_Is3gEnabled())
    {
       INT_Trace_Enter(INIT_UL1SM, 1);
       UL1SM_Init();
       INT_Trace_Exit(INIT_UL1SM, 1);
    }
#endif
#endif /* MTK_SLEEP_ENABLE */

#ifdef __CENTRALIZED_SLEEP_MANAGER__
    INT_Trace_Enter(INIT_OSTD, 1);
    OSTD_SetFrmDur(4615);
    OSTD_EnOST(KAL_TRUE);
    INT_Trace_Exit(INIT_OSTD, 1);
#endif /*__CENTRALIZED_SLEEP_MANAGER__*/

#ifndef L1_NOT_PRESENT
#ifdef __HW_DIVIDER__
    /* Power on Divider.(PDN_CON2) */
    INT_Trace_Enter(INIT_HWDIVIDER, 1);
    HW_Divider_Initialization();
    INT_Trace_Exit(INIT_HWDIVIDER, 1);
#endif /* __HW_DIVIDER__ */
#endif	/* L1_NOT_PRESENT */

#ifdef IDMA_DOWNLOAD
    /* Load DSP via iDMA. */
    INT_Trace_Enter(INIT_IDMALOAD, 1);
    REG_WRITE(DPRAM_CPU_base, 0);
    idma_load();
    INT_Trace_Exit(INIT_IDMALOAD, 1); 
#endif /* IDMA_DOWNLOAD */

    INT_Trace_Enter(INIT_NFIRESET, 1);
    NFI_Reset();
    INT_Trace_Exit(INIT_NFIRESET, 1);
    
    INT_Trace_Enter(INIT_DRV1, 1);
    Drv_Init_Phase1();
    INT_Trace_Exit(INIT_DRV1, 1);
    
#if defined(__ZIMAGE_SUPPORT__)
    ZImageDecompress();
#endif /* __ZIMAGE_SUPPORT__ */

#if defined(__DCM_WITH_COMPRESSION__) || defined(__DYNAMIC_CODE_MANAGER__)
    DCMGR_Init();
#endif

    /* Restart wdt in production release, while disable it in internal load */
#if defined(__PRODUCTION_RELEASE__)
    {
        init_dcl_wdt_handle=DclWDT_Open(DCL_WDT,0);	
        WDT_CTRL_SET_VALUE_T wdt_value;
        wdt_value.u2Value = 0xFF;
    	DclWDT_Control(init_dcl_wdt_handle,WDT_CMD_SET_VALUE,(DCL_CTRL_DATA_T*)&wdt_value);
    	DclWDT_Close(init_dcl_wdt_handle);
    }
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#ifdef __USB_ENABLE__

    handle = DclPMU_Open(DCL_PMU,FLAGS_NONE);
    DclPW_Control(handle, PW_CMD_IS_USB_BOOT, (DCL_CTRL_DATA_T *)&CtrlVal);

    if (CtrlVal.val) {
#ifndef __NVRAM_IN_USB_MS__
        *(volatile kal_uint16 *)(TDMA_base+0x14) = 0x1000;
#endif /* !__NVRAM_IN_USB_MS__ */

#if defined(__NEW_OS_TICK__) && !defined(__MEUT__)
        RTOS_EnableOSTick();
#endif /* __NEW_OS_TICK__ */
    }

#endif /*__USB_ENABLE__*/
}


/*************************************************************************
* FUNCTION
*   INT_Get_PowerOn_Type
*
* DESCRIPTION
*   This function used to return the power on reason
*
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
PW_CTRL_POWER_ON_REASON INT_Get_PowerOn_Type(void)
{
    PW_CTRL_GET_POWERON_REASON CtrlVal;
    DCL_HANDLE handle;


    handle=DclPW_Open(DCL_PW, FLAGS_NONE);
    DclPW_Control(handle,PW_CMD_GET_POWERON_REASON,(DCL_CTRL_DATA_T *)&CtrlVal);
    DclPW_Close(handle);

    return CtrlVal.powerOnReason;
}



/*************************************************************************
* FUNCTION
*   systemInitializeResource
*
* DESCRIPTION
*   This function aims resource initialization, including audio, image,
*   font etc.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void systemInitializeResource(void)
{
    kal_uint32 rand_seed_num_from_ap;

#if !(defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__))
    DCL_HANDLE handle;
    PW_CTRL_GET_POWERON_REASON poweron_type;
#endif


#if !(defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__))
    poweron_type.powerOnReason = INT_Get_PowerOn_Type();

#if ( defined(__USB_ENABLE__) && !defined(__MAUI_BASIC__) )

    if ( ((poweron_type.powerOnReason != CHRPWRON) && (poweron_type.powerOnReason != PWRKEYPWRON) && (poweron_type.powerOnReason != USBPWRON)) ||
            ((poweron_type.powerOnReason == PWRKEYPWRON) && (Check_NORFlash_Formatted() == 1)) )

#elif ( defined(__MAUI_BASIC__) || defined(_SIMULATION))

    if ( (poweron_type.powerOnReason != CHRPWRON) && (poweron_type.powerOnReason != USBPWRON) )

#else

    if ( ((poweron_type.powerOnReason != CHRPWRON) && (poweron_type.powerOnReason != PWRKEYPWRON)) ||
            ((poweron_type.powerOnReason == PWRKEYPWRON) && (Check_NORFlash_Formatted() == 1)) )

#endif
    {
        handle = DclPW_Open(DCL_PW,FLAGS_NONE);
        DclPW_Control(handle, PW_CMD_POWERON, NULL);
        DclPW_Close(handle);
    }

#endif /* !(_NAND_FLASH_BOOTING_ || __EMMC_BOOTING__) */

#if defined(__MODEM_CCCI_EXIST__)
    //If AP exist, MD will get random seed from AP through CCCI and then override the rand_num_seed
    if (CCCI_MISC_INFO_SUPPORT != ccci_misc_info_feature_support(CCMSG_ID_MISCINFO_RANDOM_SEED_NUM, 4, &rand_seed_num_from_ap))
    {
        INT_Trace_Enter(INIT_GETRANDOMSEED_INTRAM,0);
    }
    else
    {
        rand_num_seed = rand_seed_num_from_ap;
        INT_Trace_Enter(INIT_GETRANDOMSEED_AP,0);
    }
#else
    INT_Trace_Enter(INIT_GETRANDOMSEED_INTRAM,0);
#endif
	
    srand(rand_num_seed);
}

/*************************************************************************
* FUNCTION
*  INT_Config
*
* DESCRIPTION
*   This function implements adjusting Memory Block 0 (EMI_CON0) Wait
*  State's setting
*
* CALLS
*  INT_Decrypt, INT_SetPLL, INT_SetChipReg
*
* PARAMETERS
*
* RETURNS
*  the seed value for random number
*
* GLOBALS AFFECTED
*
*************************************************************************/
extern kal_uint32 dormant_power_on_reset_handler;
void INT_Config(void)
{
#if defined(__MCU_DORMANT_MODE__)
    /* store dormant mode handler address in global variable */
    /* note this option should be non-cacheable since remapping is not enable yet */
    dormant_power_on_reset_handler = *BOOT_SLAVE_ADDR_PTR;
#endif

#if defined(__MULTI_BOOT__) && !defined(L1D_TEST_COSIM)
    /* Check BOOT_CONFIG_ADDR */
    if ( 0 != (0x1 & (*(volatile kal_uint16 *)BOOT_CONFIG_ADDR)) ) {
        /* Enter FT_MODE, delay for waiting UART flush TX buffer */
#if defined(MCU_26M)
        volatile kal_uint32 delay;
        for (delay = 0; delay < 10000; delay++)
            ;   /* nop */
#elif defined(MCU_52M)
        volatile kal_uint32 delay;
        for (delay = 0; delay < 25000; delay++)
            ;   /* nop */
#endif
    }
#endif   /* __MULTI_BOOT__ & !L1D_TEST_COSIM */


#if defined(_SIMULATION)

#if defined(EMI_CON0)
    /*
     * For co-sim load,
     * EMI on both bank 0 and bank 1 are assigned with 0x4102.
     * And Register 0x80010044 (EMI General Control Register) reserves the default value.
     */
    *EMI_CON0 = 0x4102;
    *EMI_CON1 = 0x4102;
#endif

    INT_SetPLL(PLL_MODE_MAUI);

#else /* _SIMULATION */

#if defined(__BL_ENABLE__)
    /*
     * For NFB , UBL or FOTA case , bootloader/FUE already done the
     * custom_setEMI() and INT_SetPLL()
     */

#else

    INT_SetEMIPLL();

#endif /* __BL_ENABLE__ */
#endif /* _SIMULATION */

    /*
     *  Scan serial Flash blocks for leakage recovery
     */
#if defined(__SERIAL_FLASH_EN__) && defined(__MTK_TARGET__)
    {
        extern void ScanSerialFlashBlocks(void);
        ScanSerialFlashBlocks();
    }
#endif // __SERIAL_FLASH_EN__ && __MTK_TARGET__

}

/*************************************************************************
* FUNCTION
*  INT_BootMode
*
* DESCRIPTION
*   This function implements to return boot mode. Remember the routine muse
* be called after Application_Initialize.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint16 INT_BootMode(void)
{
    return _boot_mode;
}

/*************************************************************************
* FUNCTION
*  INT_InvokeSSTEngine
*
*************************************************************************/
void INT_InvokeSSTEngine(kal_int32 err_code, kal_int32 os_err_code)
{
#ifdef __MTK_INTERNAL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    return;
}

/*************************************************************************
* FUNCTION
*  release_bb_chip
*
* DESCRIPTION
*   This function returns the version number of the baseband chip
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_char* release_bb_chip(void)
{
    static kal_char str_return[]="MT62xxx, E00";

#if defined(FPGA)
    strcpy(str_return, "FPGA");
    /* mtk02439: Version register cannot be seen at MD side on MT6575 and MT6577 */
#elif defined(MT6575)
    strcpy(str_return, "MT6575");
#elif defined(MT6577)
    strcpy(str_return, "MT6577");
#elif defined(MT6589)
    strcpy(str_return, "MT6589");    // MT6589 has HW_CODE 6583

#else /* future chips will definitely apply this rule */
    kal_uint16 hw_code;
    kal_uint8 majrev; /* bit 8~11 of HW_VER register */
    kal_uint8 ffix; /* bit 0~3 of HW_VER register */
    kal_uint16 hw_version;
    kal_uint16 temp_num;

    hw_code = *HW_CODE;
    hw_version = *HW_VER;
    majrev = (hw_version >> 8) & 0x000f; /* get MAJREV from HW_VER */
    ffix = hw_version & 0x000f; /* get FFIX from HW_VER */

    /* convert the HW_CODE to natural representation*/
    temp_num = (hw_code & 0x000f);
    hw_code >>= 4;
    temp_num += (hw_code & 0x000f) * 10;
    hw_code >>= 4;
    temp_num += (hw_code & 0x000f) * 100;
    hw_code >>= 4;
    temp_num += (hw_code & 0x000f) * 1000;

    /* construct the string for the chips MTxxxxx, ECOx */
    if (majrev == 0x0a) {   /* directiver A, which often skip the directive */
        sprintf(str_return, "MT%4d, E%02d", temp_num, ffix);
    } else {
        sprintf(str_return, "MT%4d%1X, E%02d", temp_num, majrev, ffix);
    }
#endif

    return str_return;
}

/*************************************************************************
* FUNCTION
*  INT_CheckSystemDriveOnNAND()
*
* DESCRIPTION
*  Query the location of system drive, either NAND-flash or NOR-flash
*
* PARAMETERS
*
* RETURNS
*  KAL_TRUE: NFB or System Drive On NAND
*  KAL_FALSE: otherwise
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool INT_CheckSystemDriveOnNAND(void)
{
#if ( defined(__FS_SYSDRV_ON_NAND__) || defined( _NAND_FLASH_BOOTING_) )

    return KAL_TRUE;

#else

    return KAL_FALSE;

#endif /* __FS_SYSDRV_ON_NAND__ || _NAND_FLASH_BOOTING_ */
}

/*************************************************************************
* FUNCTION
*  INT_IsBootByCodeShadow()
*
* DESCRIPTION
*  Query if system boot via code shadow,
*  On the other word, binary code copy to RAM before execution
*
* PARAMETERS
*
* RETURNS
*  KAL_TRUE: Nand Flash booting
*  KAL_FALSE: otherwise
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool INT_IsBootByCodeShadow(void)
{
#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)

    return KAL_TRUE;

#else

    return KAL_FALSE;

#endif /* _NAND_FLASH_BOOTING_ || __EMMC_BOOTING__ */
}

/*************************************************************************
* FUNCTION
*  INT_IsCodeShadowDone()
*
* DESCRIPTION
*  Query if binary code already ready via code shadow,
*
* PARAMETERS
*
* RETURNS
*  KAL_TRUE: ! Nand Flash Booting , or Secondary Image loaded on NFB
*  KAL_FALSE: otherwise
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool INT_IsCodeShadowDone(void)
{
#if (defined(_NAND_FLASH_BOOTING_) && !defined(__NFB_SINGLE_ROM__)) || defined(__EMMC_BOOTING__)

    return NFB_SecondaryImageLoaded;

#else

    return KAL_TRUE;

#endif /* _NAND_FLASH_BOOTING_ || __EMMC_BOOTING__ */
}


/*************************************************************************
* FUNCTION
*  show_sysinit_msg
*
* DESCRIPTION
*  This function shows system intialization messages. It is called in the
*  entry point of the TST READER task.
*
* PARAMETERS
*  none
*
* RETURNS
*  0
*
*************************************************************************/
kal_int32 show_sysinit_msg(void)
{

#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__)
    /* display the page table usage for ARM9 MMU */
    kal_char buff[40];
    kal_uint32 ret;

    ret = check_cptbl_pool();
    if (ret != 0) {
        system_print("WARNING!!WARNING!!WARNING!!WARNING!!WARNING!!WARNING!!WARNING!!WARNING!!");
        system_print("PAGE TABLE config failure");
        sprintf(buff, "needs %d bytes for %cptbl pool", ret, 'c');
        system_print(buff);
        system_print("WARNING!!WARNING!!WARNING!!WARNING!!WARNING!!WARNING!!WARNING!!WARNING!!");
    }

#if defined(__ARM9_MMU__)
    ret = check_fptbl_pool();
    if (ret != 0) {
        system_print("WARNING!!WARNING!!WARNING!!WARNING!!WARNING!!WARNING!!WARNING!!WARNING!!");
        system_print("PAGE TABLE config failure");
        sprintf(buff, "needs %d bytes for %cptbl pool", ret, 'f');
        system_print(buff);
        system_print("WARNING!!WARNING!!WARNING!!WARNING!!WARNING!!WARNING!!WARNING!!WARNING!!");
    }
#endif	/* __ARM9_MMU__ */

#endif	/* __ARM9_MMU__ || __ARM11_MMU__ */

    return 0;
}

#undef RTOS_DEBUG
/*************************************************************************
* FUNCTION
*  INT_SetCmdToSys
*
* DESCRIPTION
*  This function provide API for user to set necessary command to system
*
* PARAMETERS
*  none
*
* RETURNS
*  random seed
*
*************************************************************************/
void INT_SetCmdToSys(INIT_SYSCMD_CODE cmd_val)
{
#if defined(__MODEM_CARD__)

    // RETN_REG[2]: 1: Enter USBDL
    // RETN_REG[1]: 1: BL download, 0: BROM download

    /* Secure mode */
    // Normal mode: enter bootloader download after reboot
    // Rescue mode: enter BROM download after reboot

    /* Non-secure mode */
    // Enter BROM download after reboot under either mode

    WDT_CLR_RETN_FLAG(0x06);   // 3'b110

    switch (cmd_val) {
#if defined(__MTK_SECURE_PLATFORM__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* __MTK_SECURE_PLATFORM__ */
        /* under non-secure mode, enter BROM download after reboot under either mode */
    case SYS_CMD_SET_BROM_DL:
    case SYS_CMD_SET_BL_DL:   /* this is actually BROM download */
        WDT_SET_RETN_FLAG(0x04);   // 3'b100
        break;
#endif /* __MTK_SECURE_PLATFORM__ */


        // do not enter download mode
    case SYS_CMD_CLR_DL_FLAG:
        break;

    default:
        ASSERT(0);
        break;
    }

    /* Clean Timeout flag */
    WDT_Write_RETN_DAT0(0);

    /* MT6280E2 workaround: flush rgu register to RETN_DAT3 */
#if defined(MT6280)
    *((volatile kal_uint32*)(RGU_base+0x0820)) = 0x4e000000 | \
            (*((volatile kal_uint32*)(RGU_base+0x0820)) & 0x00ffff00) | \
            (*((volatile kal_uint32*)(RGU_base+0x0800)) & 0x000000ff);
#endif

#endif /* __MODEM_CARD__ */

}



/*************************************************************************
* FUNCTION
*  INT_GetSysStaByCmd
*
* DESCRIPTION
*  This function provided for user to query the status of system
*
* PARAMETERS
*  INIT_SYSCMD_CODE cmd_val - command
*  void* data_p - for EMI parameter
*
* RETURNS
*  random seed
*
*************************************************************************/
kal_uint32 INT_GetSysStaByCmd(INIT_SYSCMD_CODE cmd_val, void *data_p)
{
#if !defined(__SMART_PHONE_MODEM__)
    switch (cmd_val) {
    case CHK_USB_META_WO_BAT:
        /* META mode without battery
         * battery is controlled at AP side for smart phone case.
         */
        if (g_l_sw_misc_l & (0x1 << 3)) {
            return KAL_TRUE;
        }

    case CHK_FAST_META:
#if !defined(__NO_MDBL_SHARE_INFO__)
        if (BL_FAST_META_TRIGGERED & (g_pass_info.m_bl_maui_share_data.m_bl_bootup_flag)) {
            return KAL_TRUE;
        }
#endif

    case SYS_CMD_BL_LOGO_DISPLAYED:
        /* FAST_LOGO must be in bootloader */
#if defined(__FAST_LOGO__)
        if (BL_FAST_LOGO_DISPLAYED & (g_pass_info.m_bl_maui_share_data.m_bl_bootup_flag)) {
            return KAL_TRUE;
        }
#endif /* __FAST_LOGO__ */

    case SYS_CMD_GET_PWN_STA:
#if !defined(__NO_MDBL_SHARE_INFO__)
        return (g_pass_info.m_bl_maui_share_data.m_poweron_param);
#endif

    case SYS_CMD_GET_EMI_PARAM:
#if !defined(__NO_MDBL_SHARE_INFO__)
        kal_mem_cpy(data_p,(void *)(g_pass_info.m_bl_maui_share_data.m_emi_param), sizeof(g_pass_info.m_bl_maui_share_data.m_emi_param));

        return KAL_TRUE;
#endif

    case SYS_CMD_BL_BROM_CMD_MODE_DISABLED:
#if !defined(__NO_MDBL_SHARE_INFO__)
        if (BL_BROM_CMD_MODE_DISABLED & (g_pass_info.m_bl_maui_share_data.m_bl_bootup_flag)) {
            return KAL_TRUE;
        }
#endif


        /*
         * The following statements are common for the above cases
         */
        break;

    default:
        ASSERT(0);
        break;
    }
#endif /* !__SMART_PHONE_MODEM */

    return KAL_FALSE;
}



/*************************************************************************
* FUNCTION
*  INT_BackupBLShareinfo
*
* DESCRIPTION
*  This function is used to backup bootloader / maui shared information
*  passed from bootloader
*
* PARAMETERS
*  none
*
* RETURNS
*  random seed
*
*************************************************************************/
kal_int32 INT_BackupBLShareinfo(kal_uint32 backup_addr)
{
#if !defined(__NO_MDBL_SHARE_INFO__)
    kal_uint32 i = 0;
    kal_uint32 cpsz = 0;

    cpsz = sizeof(BL_Info_Wrapper_st);

    for (i = 0; i < ((cpsz+3) >> 2); i++) {
        *((volatile unsigned long *)backup_addr + i )= *((volatile unsigned long *)BL_INFO_ADDR + i );
    }

#ifdef __TIME_STAMP__
    {
        kal_uint32 timestamp_addr = 0;
        kal_uint32 timestamp_size = 0;

        TS_GetContext(&timestamp_addr, &timestamp_size);

        for (i = 0; i < ((timestamp_size+3) >> 2); i++) {
            *((volatile unsigned long *)backup_addr + ((cpsz+3) >> 2) + i ) =  *((volatile unsigned long *)timestamp_addr + i );
        }
    }
#endif

#endif /* !__NO_MDBL_SHARE_INFO__ */

    return KAL_TRUE;

}



/*************************************************************************
* FUNCTION
*  INT_RetrieveBLShareinfo
*
* DESCRIPTION
*  This function is used to retrieved bootloader / maui shared information
*  from backed up region for runtime use
*
* PARAMETERS
*  none
*
* RETURNS
*  random seed
*
*************************************************************************/
kal_int32 INT_RetrieveBLShareinfo(kal_uint32 backup_addr)
{
#if !defined(__NO_MDBL_SHARE_INFO__)
    kal_uint32 i=0;
    kal_uint32 cpsz = 0;

    cpsz = sizeof(BL_Info_Wrapper_st);

    for (i = 0; i < ((cpsz+3) >> 2); i++) {
        *((volatile unsigned long *)&g_pass_info + i )= *((volatile unsigned long *)backup_addr + i );
    }

#ifdef __TIME_STAMP__
    {
        kal_uint32 timestamp_addr = 0;
        kal_uint32 timestamp_size = 0;

        TS_GetContext(&timestamp_addr, &timestamp_size);

        for (i = 0; i < ((timestamp_size+3) >> 2); i++) {
            *((volatile unsigned long *)timestamp_addr + i ) =  *((volatile unsigned long *)backup_addr + ((cpsz+3) >> 2) + i );
        }
    }
#endif

#endif /* !defined(__NO_MDBL_SHARE_INFO__) */

    return KAL_TRUE;

}


/*************************************************************************
* FUNCTION
*  INT_GetBLShareToken
*
* DESCRIPTION
*  This function is used to get the share token passed from bootloader
*
* PARAMETERS
*  none
*
* RETURNS
*  random seed
*
*************************************************************************/
kal_int32 INT_GetBLShareToken(kal_uint32 *token_size, kal_uint32 buff_addr, kal_uint32 buff_len)
{

#if defined(__NO_MDBL_SHARE_INFO__)

    return KAL_TRUE;

#else /* __NO_MDBL_SHARE_INFO__ */

    *token_size = sizeof(((BL_MAUI_ShareData *)0)->m_bl_token);

    if (*token_size > buff_len) {
        return KAL_FALSE;
    } else {
        kal_mem_cpy((char *)buff_addr, (char *)&g_pass_info.m_bl_maui_share_data.m_bl_token[0], *token_size );
    }

    return KAL_TRUE;
#endif /* __NO_MDBL_SHARE_INFO__ */

}

/*************************************************************************
* FUNCTION
*  INT_GetMetaModeSrc
*
* DESCRIPTION
*  Get Random Seed
*
* PARAMETERS
*  none
*
* RETURNS
*  random seed
*
*************************************************************************/
MODE_ENTRY_SRC INT_GetMetaModeSrc(void)
{
    MODE_ENTRY_SRC state = E_BROM;


#if defined(__TOOL_ACCESS_CTRL__)

#if defined(__NO_MDBL_SHARE_INFO__)

#else /* __NO_MDBL_SHARE_INFO__ */
    if ( g_pass_info.m_bl_maui_share_data.m_bl_bootup_flag & BL_INFO_SUSBDL_IN_BL_ENABLED) {  //S-USBDL
        return E_BLSUSB;

    } else if( g_pass_info.m_bl_maui_share_data.m_bl_bootup_flag & BL_INFO_USBDL_IN_BL_CONNECTED   ) { //N_USBDL
        return E_BLNUSB;
    }
#endif /* __NO_MDBL_SHARE_INFO__ */
#endif /* __TOOL_ACCESS_CTRL__ */
    return state;



}


/*************************************************************************
* FUNCTION
*  INT_GetRandomSeed
*
* DESCRIPTION
*  Get Random Seed -- maybed passed from bootloader or use memory region
*  to create
*
* PARAMETERS
*  none
*
* RETURNS
*  random seed
*
*************************************************************************/
kal_int32 INT_GetRandomSeed(void)
{
#if defined(__SSDVT_TEST__)
    return 0;
#else /* __SSDVT_TEST__ */

    kal_uint32 seed;
#if defined(__NO_MDBL_SHARE_INFO__)
    kal_uint32 i;
#endif

#ifdef __TIME_STAMP__

#if defined(__NO_MDBL_SHARE_INFO__)
    HW_wait_32k_start();
#endif

    TS_Init(TRUE);

    TS_BEGIN(TSID_INIT_TOTAL);
    TS_BEGIN(TSID_INIT_READY_TO_DISPLAY);
    TS_BEGIN(TSID_INIT_ASM);

#endif

#if defined(_SIMULATION)

    /* no need to generate a real random number seed in co-sim */

    seed = 0;

#else   /* _SIMULATION */
#if defined(__NO_MDBL_SHARE_INFO__)
    /* generate a random number via reading internal SRAM or 32K-clock calibration */
    for (seed = 0, i = 0; i < (1024 / 4); i++) {
        /* XOR memory data */
        seed = seed ^ *((kal_uint32 *)RAND_GEN_START_ADDR + i);
    }


#else /* __NO_MDBL_SHARE_INFO__ */


    ASSERT(((BL_Info_Wrapper_st*)(BL_INFO_ADDR))->m_bl_maui_share_data.m_bl_magic_head == BL_INFO_V1);
    seed = ((BL_Info_Wrapper_st*)(BL_INFO_ADDR))->m_bl_maui_share_data.m_bl_random_seed;


#endif /* __NO_MDBL_SHARE_INFO__ */

#endif  /* _SIMULATION */

    /*
     * NoteXXX: Seed cannot be store in the global variable rand_num_seed directly.
     *          This is because that RW-data will be initialized later.
     *          Just return the seed.
     */

    return seed;
#endif /* __SSDVT_TEST__ */
}


/*************************************************************************
* FUNCTION
*  INT_IsBootForUSBAT
*
* DESCRIPTION
*  This function is used to for user to query if USBAT is enabled
*
* PARAMETERS
*  none
*
* RETURNS
*  0
*
*************************************************************************/
kal_bool INT_IsBootForUSBAT(void)
{
    return _IsBootForUSBAT;
}

/*************************************************************************
* FUNCTION
*  INT_GetBootloaderFlag
*
* DESCRIPTION
*  Get the flags passed by Bootloader from internal structures
*
* PARAMETERS
*  none
*
* RETURNS
*  Flag for the bootup information
*
*************************************************************************/
kal_uint32 INT_GetBootloaderFlag(void)
{

#if defined(__SV5_ENABLED__) /* __SV5_ENABLED__ */

    return (g_pass_info.m_bl_maui_share_data.m_bl_bootup_flag);

#else /* __SV5_ENABLED__ */

#if defined(__NO_MDBL_SHARE_INFO__)

    return 0; /* Nothing passed by bootloader */

#else /* __NO_MDBL_SHARE_INFO__ */

    return (g_pass_info.m_bl_maui_share_data.m_bl_bootup_flag);

#endif /* __NO_MDBL_SHARE_INFO__ */

#endif /* __SV5_ENABLED__ */

}


/*************************************************************************
* FUNCTION
*  INT_IsPowerLatchedByBL
*
* DESCRIPTION
*  Bootloader may latch the power in some special cases. If it did so, this flag will
*  be raised to notify MAUI init module
*
* PARAMETERS
*  none
*
* RETURNS
*  If the power is latched by Bootloader
*
*************************************************************************/
kal_bool INT_IsPowerLatchedByBL(void)
{
    return (INT_GetBootloaderFlag() & BL_INFO_POWER_LATCHED) ? KAL_TRUE : KAL_FALSE;
}

/*************************************************************************
* FUNCTION
*  INT_IsFirstPowerOnFromBL
*
* DESCRIPTION
*  For power-on sequence, it is necessary to know if it's the first boot up
*  If this information is retrived by Bootloader, this flag will be raised
*
* PARAMETERS
*  Module that giving the information
*
* RETURNS
*  If it's the first time of power-on awared by Bootloader
*
*************************************************************************/
kal_bool INT_IsFirstPowerOnFromBL(BL_FIRST_PWON_INFO_SRC module)
{
    //Currently booltoader only get this information from RTC module
    ASSERT(module == BL_INFO_FROM_RTC);

    return (INT_GetBootloaderFlag() & BL_INFO_FIRST_POWER_ON) ? KAL_TRUE : KAL_FALSE;
}

/*************************************************************************
* FUNCTION
*  INT_RandomSeedScramble
*
* DESCRIPTION
*  This function scrambles the global variable "rand_num_seed" using system tick.
*
* PARAMETERS
*  none
*
* RETURNS
*  none
*
*************************************************************************/
void INT_RandomSeedScramble(void)
{
    kal_uint32 seed = 0;

#define nvram_get_imei()	(0)

#if defined(__MTK_TARGET__)

    DCL_HANDLE rtc_handler;
    RTC_CTRL_GET_TIME_T rtc_time;
    DCL_STATUS_T sts;
    rtc_handler = DclRTC_Open(DCL_RTC,FLAGS_NONE);
    sts = DclRTC_Control(rtc_handler, RTC_CMD_GET_TIME, (DCL_CTRL_DATA_T *)&rtc_time);
      
    if(sts == STATUS_OK)
    {
        seed =  ((rtc_time.u1Day + rtc_time.u1Hour + rtc_time.u1Min + rtc_time.u1Mon +
                rtc_time.u1Sec + rtc_time.u1WDay + rtc_time.u1Year) << 16) | nvram_get_imei();
    }
    else
    {
        seed = INT_GetCurrentTime() | nvram_get_imei();
    }

#else /* __MTK_TARGET__ */

    kal_uint32 ticks = 0;
    kal_uint32 second = 0;
    kal_uint16 milli_sec = 0;

    ticks = kal_get_systicks();

    second = ticks / KAL_TICKS_1_SEC;
    milli_sec = (ticks%KAL_TICKS_1_SEC) * 10 / KAL_TICKS_10_MSEC;

    seed = second * 1000 + milli_sec;
	
#endif /* __MTK_TARGET__ */
	
    rand_num_seed = rand_num_seed ^ seed;	
    srand(rand_num_seed);
	
}


#endif /*__FUE__*/
