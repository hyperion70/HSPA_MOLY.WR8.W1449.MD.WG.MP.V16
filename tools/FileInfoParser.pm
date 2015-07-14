#!/usr/bin/perl
#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2006
#
#  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
#  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
#  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
#  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
#  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
#  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
#  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
#  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
#  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
#  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
#  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
#  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
#
#  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
#  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
#  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
#  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
#  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
#
#  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
#  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
#  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
#  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
#  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
#
#*****************************************************************************
#*
#* Filename:
#* ---------
#*   FileInfoParser.pm
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This module collects the subroutines for common utility. 
#*       
#*
#* Author:
#* -------
#*   Qmei Yang (mtk03726)
#*
#****************************************************************************/
use strict;
#use warnings;
BEGIN { push @INC, './tools/' }  # add additional library path
use sysGenUtility;               #pm file name without case sensitivity
use CommonUtility;
package FileInfo;
#****************************************************************************
# Constants
#****************************************************************************
my $FILEINFOPARSER_VERNO     = " m0.10";
                               # m0.10 , 2012/11/16, Support is_MAIN_CODE_NEED_GFH
                               # m0.09 , 2013/03/22, Support parsing informake.log
                               # m0.08 , 2012/01/14, Support basic query functions more flexible
                               # m0.07 , 2012/10/19, Support is_XBOOTING, is_HostedDongle, is_RNDISDongle
                               # m0.06 , 2012/09/18, Fix MakeFile mode parsing
                               # m0.05 , 2012/08/17, Support GetChip()
                               # m0.04 , 2012/08/06, Add more common functions and ParseDefinition()
                               # m0.03 , 2012/07/26, Support is_NonSPNOR()
                               # m0.02 , 2012/05/28, Support path and filename case sensitive on Linux
                               # v0.07 , 2012/05/13, Move is_NOR from sysgenUtility to here and support general query
                               # m0.01 , 2012/05/09, Provide GetCompiler()
                               # v0.06 , 2012/05/08, Copy parseFeatureOptionCondition 
                               #                     and EvaluateFeatureOptionCondition from objListHelper.pm to here
                               # v0.05 , 2012/05/08,  Query is_SmartPhone
                               # v0.04 , 2012/01/30,  To provide CUSTOMER and MODE in %MAKEFILE_OPTIONS
                               # v0.03 , 2011/12/17,  Fix parsing MakeFile
                               # v0.02 , 2011/11/01,  Remove $$ to support Perl v5.12.*
                               # v0.01 , 2011/09/21,  Initial revision

#****************************************************************************
# Global variable
#****************************************************************************
my $g_MAKEFILE_href = undef;
#****************************************************************************
# oo >>>  Finished
#****************************************************************************
return 1;

#****************************************************************************
# subroutine:  Parse_MAKEFILE
# input:    1. MAKEFILE path
#           2. a Hash to contain MAKEFILE information.
# output:   1=Parse successfully, 0 or die= Parse failed.
# sample code: my %MAKEFILE_OPTIONS;
#              &FileInfo::Parse_MAKEFILE($MAKEFILE_Path, \%MAKEFILE_OPTIONS);   
#****************************************************************************

sub Parse_MAKEFILE
{
    my ($strMAKEFILE_Path, $Info_href) = @_;
    my $bResult = 0;
    if(-e $strMAKEFILE_Path)
    {
        open (FILE_HANDLE, $strMAKEFILE_Path) or &FileInfoParser_die("Cannot open $strMAKEFILE_Path\n", __FILE__, __LINE__);
        while (<FILE_HANDLE>) 
        {
            if ((/^([^\#]*)\#?.*/) && ($1 =~ /^(\w+)\s*=\s*(.*\S)\s*$/))
            {
                my $keyname = lc($1);
                #defined($Info_href->{$keyname}) && warn "$1 redefined in $strMAKEFILE_Path!\n";
                $Info_href->{$keyname} = uc($2);
                $keyname = uc($1);
                #defined($Info_href->{$keyname}) && warn "$1 redefined in $strMAKEFILE_Path!\n";
                $Info_href->{$keyname} = uc($2);
                $bResult = 1;
            }
        }
        close FILE_HANDLE;
        if ($strMAKEFILE_Path =~ /\/(\w+)_(\w+)\((\w+)\).mak/i) 
        {
            $Info_href->{'CUSTOMER'} = uc($3);
            $Info_href->{'customer'} = uc($3);
            $Info_href->{'MODE'} = uc($2);
            $Info_href->{'mode'} = uc($2);
        }
        $g_MAKEFILE_href = $Info_href;
    }
    else
    {
        &FileInfoParser_die("$strMAKEFILE_Path: NOT exist!", __FILE__, __LINE__);
    }
    return $bResult;
}

sub GetMakeFileRef
{
    my ($strMAKEFILE_Path) = @_;
    if(!defined $g_MAKEFILE_href)
    {
        my %MakeFileOption;
        &Parse_MAKEFILE($strMAKEFILE_Path, \%MakeFileOption);
    }
    return $g_MAKEFILE_href;    
}
sub is
{
    my ($strKey, $strValue, $MakeFile_ref) = @_;
    $MakeFile_ref = $g_MAKEFILE_href if (!defined $MakeFile_ref);
    &NoMakeFile_die($MakeFile_ref, __FILE__, __LINE__);
    my $bEqual = 0;
    if(exists $MakeFile_ref->{uc($strKey)} and uc($MakeFile_ref->{uc($strKey)}) eq uc($strValue))
    {
        $bEqual = 1;
    }
    return $bEqual;
}
sub find
{
    my ($strKey, $strValue, $MakeFile_ref) = @_;
    $MakeFile_ref = $g_MAKEFILE_href if (!defined $MakeFile_ref);
    &NoMakeFile_die($MakeFile_ref, __FILE__, __LINE__);
    my $bFound = 0;
    if(exists $MakeFile_ref->{uc($strKey)} and $MakeFile_ref->{uc($strKey)} =~ /$strValue/)
    {
        $bFound = 1;
    }
    return $bFound;
}
sub isnot
{
    my ($strKey, $strValue, $MakeFile_ref) = @_;
    $MakeFile_ref = $g_MAKEFILE_href if (!defined $MakeFile_ref);
    &NoMakeFile_die($MakeFile_ref, __FILE__, __LINE__);
    my $bNotEqual = 0;
    if(exists $MakeFile_ref->{uc($strKey)} and uc($MakeFile_ref->{uc($strKey)}) ne uc($strValue))
    {   #exist but not equal
        $bNotEqual = 1;
    }
    return $bNotEqual;
}
sub get
{
    my ($strKey, $MakeFile_ref) = @_;
    $MakeFile_ref = $g_MAKEFILE_href if (!defined $MakeFile_ref);
    &NoMakeFile_die($MakeFile_ref, __FILE__, __LINE__);
    my $Value = undef;
    if(exists $MakeFile_ref->{uc($strKey)})
    {
        $Value = $MakeFile_ref->{uc($strKey)};
    }
    return $Value;
}
sub ParseDefinition
{
    my ($strFilePath, $Hash_ref, $bAllowDuplicated) = @_;
    my $content = &CommonUtil::GetFileContent($strFilePath);
    #strip comments
    $content =~ s/\/\/(.+)//g;
    $content =~s#/\*[^*]*\*+([^/*][^*]*\*+)*/|([^/"']*("[^"\\]*(\\[\d\D][^"\\]*)*"[^/"']*|'[^'\\]*(\\[\d\D][^'\\]*)*'[^/"']*|/+[^*/][^/"']*)*)#$2#g;

    my @lines = split(/\n|\r/, $content);
    my $nDuplicatedIndex=0;
    foreach my $line (@lines)
    {
        if ($line =~ /#define\s+(\w+)\s+\((.*)\)\s*$/ || $line =~ /#define\s+(\w+)\s+(\S*)\s*$/)
        {
            my $option = $1;
            my $value  = $2;
            &FileInfoParser_die("$strFilePath: $option redefined in $strFilePath!", __FILE__, __LINE__) 
                if (!$bAllowDuplicated and defined($Hash_ref->{$option}));
            if (!defined $value)
            {
                $Hash_ref->{$option} = 'TRUE';
                $Hash_ref->{uc($option)} = 'TRUE';
                $Hash_ref->{lc($option)} = 'TRUE';
            }
            else
            {
                $Hash_ref->{$option} = $value;
                $Hash_ref->{uc($option)} = $value;
                $Hash_ref->{lc($option)} = $value;
            }
        }
    }
    close (FILE_HANDLE);
}


#****************************************************************************
# subroutine: is_SmartPhone - Query if it belongs smart phone project
# Input:      x
# Output:     1=it's SmartPhone, others=not SmartPhone
#****************************************************************************
sub is_SmartPhone
{
    my ($MakeFile_ref) = @_;
    $MakeFile_ref = $g_MAKEFILE_href if (!defined $MakeFile_ref);
    &NoMakeFile_die($MakeFile_ref, __FILE__, __LINE__);
    my $bIsSmartPhone = 0;
    if( exists $MakeFile_ref->{SMART_PHONE_CORE} and $MakeFile_ref->{SMART_PHONE_CORE} ne "NONE" ) #NONE = feature phone
    {
        $bIsSmartPhone = 1;
    }
    return $bIsSmartPhone;
}


#****************************************************************************
# subroutine: is_NOR - Query if it's NOR flash
# Input:      \%MAKEFILE_OPTION
# Output:     0=not NOR, 1=NOR
#****************************************************************************
sub is_NOR
{
    my ($MAKEFILE_ref) = @_;
    $MAKEFILE_ref = $g_MAKEFILE_href if (!defined $MAKEFILE_ref);
    &NoMakeFile_die($MAKEFILE_ref, __FILE__, __LINE__);
    my $bNOR = 1; # 0=not NOR, 1= NOR
    if((exists $MAKEFILE_ref->{'nand_flash_booting'} and $MAKEFILE_ref->{'nand_flash_booting'} ne 'NONE') 
    or (exists $MAKEFILE_ref->{'emmc_booting'} and $MAKEFILE_ref->{'emmc_booting'} ne 'NONE'))
    {
        $bNOR = 0;
    }
    return $bNOR;
}
#****************************************************************************
# subroutine: is_NonSPNOR - Query if it's not nand flash and not smart_phone project
# Input:      \%MAKEFILE_OPTION
# Output:     0=not NOR, 1=NOR
#****************************************************************************
sub is_NonSPNOR
{
    my ($MAKEFILE_ref) = @_;
    return (&is_NOR($MAKEFILE_ref) and !&is_SmartPhone($MAKEFILE_ref));
}

#****************************************************************************
# subroutine: is_FOTA - Query if it's fota
# Input:      \%MAKEFILE_OPTION
# Output:     0=not FOTA, 1=FOTA
#****************************************************************************
sub is_FOTA
{
    my ($MAKEFILE_ref) = @_;
    $MAKEFILE_ref = $g_MAKEFILE_href if (!defined $MAKEFILE_ref);
    &NoMakeFile_die($MAKEFILE_ref, __FILE__, __LINE__);
    my $bFOTA = 0;
    $bFOTA = 1 if(&is("fota_enable", "FOTA_DM"));
    return $bFOTA;
}

#****************************************************************************
# subroutine: is_MAIN_CODE_NEED_GFH - Query if it's MAIN_CODE_NEED_GFH:
#             SMART_PHONE_CORE != NONE && X_BOOTING==NONE => MAIN_CODE_NEED_GFH = FALSE
# Input:      \%MAKEFILE_OPTION
# Output:     0=no GFH, 1=having GFH
#****************************************************************************
sub is_MAIN_CODE_NEED_GFH
{
    my ($bb, $MAKEFILE_ref) = @_;
    $MAKEFILE_ref = $g_MAKEFILE_href if (!defined $MAKEFILE_ref);
    &NoMakeFile_die($MAKEFILE_ref, __FILE__, __LINE__);
    my $bNEED_GFH = 0;
    if(&sysUtil::is_sv5($bb))
    {
        $bNEED_GFH = 1;
        if(&is_SmartPhone($MAKEFILE_ref) && &is("X_BOOTING", "NONE", $MAKEFILE_ref) )
        {
            $bNEED_GFH = 0;
        }
    }
    return $bNEED_GFH;
}

#****************************************************************************
# subroutine: is_XBOOTING - Query if it's X_BOOTING: X_BOOTING != NONE
# Input:      \%MAKEFILE_OPTION
# Output:     0=not X BOOTING, 1=X BOOTING
#****************************************************************************
sub is_XBOOTING
{
    my ($MAKEFILE_ref) = @_;
    $MAKEFILE_ref = $g_MAKEFILE_href if (!defined $MAKEFILE_ref);
    &NoMakeFile_die($MAKEFILE_ref, __FILE__, __LINE__);
    my $bX = 0;
    $bX = 1 if(&isnot("X_BOOTING", "NONE"));
    return $bX;
}

#****************************************************************************
# subroutine: is_HostedDongle - Query if it's HostedDongle
#             SMART_PHONE_CORE=MODEM_HOST and X_BOOTING=NONE
# Input:      \%MAKEFILE_OPTION
# Output:     0=not Hosted dongle, 1=Hosted dongle
#****************************************************************************
sub is_HostedDongle
{
    my ($MAKEFILE_ref) = @_;
    $MAKEFILE_ref = $g_MAKEFILE_href if (!defined $MAKEFILE_ref);
    &NoMakeFile_die($MAKEFILE_ref, __FILE__, __LINE__);
    my $bX = 0;
    $bX = 1 if(&is("SMART_PHONE_CORE", "MODEM_HOST") and !&is_XBOOTING());
    return $bX;
}


#****************************************************************************
# subroutine: is_RNDISDongle - Query if it's RNDIS Dongle
#             (is smartphone but SMART_PHONE_CORE != MODEM_HOST) and X_BOOTING=NONE
# Input:      \%MAKEFILE_OPTION
# Output:     0=not RNDIS, 1=RNDIS
#****************************************************************************
sub is_RNDISDongle
{  
    my ($MAKEFILE_ref) = @_;
    $MAKEFILE_ref = $g_MAKEFILE_href if (!defined $MAKEFILE_ref);
    &NoMakeFile_die($MAKEFILE_ref, __FILE__, __LINE__);
    my $bX = 0;
    $bX = 1 if(&is_SmartPhone() and !&is_XBOOTING() and !is_HostedDongle());
    return $bX;
}

#****************************************************************************
# subroutine: GetCompiler()
# Input:      \%MAKEFILE_OPTION
# Output:     Should be "GCC" or "RVCT" in string
#****************************************************************************
sub GetCompiler
{
    my ($MakeFile_ref) = @_;
    $MakeFile_ref = $g_MAKEFILE_href if (!defined $MakeFile_ref);
    &NoMakeFile_die($MakeFile_ref, __FILE__, __LINE__);
    my $strCompiler = undef;
    $strCompiler = uc($MakeFile_ref->{COMPILER}) if(exists $MakeFile_ref->{COMPILER});
    &FileInfoParser_die("Unsupported ToolChain!\n", __FILE__, __LINE__) if(($strCompiler ne "GCC") and ($strCompiler ne "RVCT"));
    return $strCompiler;
}
#****************************************************************************
# subroutine: GetChip()
# Input:      \%MAKEFILE_OPTION
# Output:     string (e.g. MT6280 or MT6280_XX)
#****************************************************************************
sub GetChip
{
    my ($MakeFile_ref) = @_;
    $MakeFile_ref = $g_MAKEFILE_href if (!defined $MakeFile_ref);
    &NoMakeFile_die($MakeFile_ref, __FILE__, __LINE__);
    my $strChip = undef;
    $strChip = uc($MakeFile_ref->{PLATFORM}) if(exists $MakeFile_ref->{PLATFORM});
    $strChip .= "_".uc($MakeFile_ref->{MDSYS}) if(exists $MakeFile_ref->{MDSYS} and $MakeFile_ref->{MDSYS} !~/none/i);
    return $strChip;
}



#****************************************************************************
# subroutine:  EvaluateFeatureOptionCondition
# description: Evaluate the feature option condition.
# input:       Feature option condition(string), makefile options hash ref
# output:      1: true, 0: false
# need init:   No
#****************************************************************************
sub EvaluateFeatureOptionCondition
{
   my $condition = shift;
   my $makefileOptionsRef = shift;

   my @expressionTree;
   my @stack;

   # Transform the condition to expression tree in postfix form
   &parseFeatureOptionCondition($condition,  \@expressionTree);

   # Evaluate the expression tree
   foreach my $token (@expressionTree)
   {
      if ($token eq "&&" or $token eq "||")
      {
         my $second = pop(@stack);
         my $first = pop(@stack);
         push (@stack, eval "$first $token $second");
      }
      elsif ($token eq "=")
      {
         my $second = pop(@stack);
         my $first = pop(@stack);
         my $value = $makefileOptionsRef->{$first};
         $value = "" unless defined $value;
         if ($value eq $second)
         {
            push (@stack, 1);
         }
         else
         {
            push (@stack, 0);
         }
      }
      elsif ($token eq "!")
      {
         my $first = pop(@stack);
         if ($first == 1)
         {
            push (@stack, 0);
         }
         else
         {
            push (@stack, 1);
         }
      }
      else
      {
         push @stack, $token;
      }
   }
   &FileInfoParser_die("Incorrect syntax of feature option condition \"$condition\"", __FILE__, __LINE__)
      unless (1 == @stack);

   return $stack[0];
}

#****************************************************************************
# subroutine:  parseFeatureOptionCondition
# description: Parse the feature option condition to postfix form.
# input:       Feature option condition, expression tree ref
# output:      Expression tree
# need init:   No
#****************************************************************************
sub parseFeatureOptionCondition
{
   my $condition = shift;
   my $expressionTreeRef = shift;
   my $conditionNoSpace = $condition;
   $conditionNoSpace =~ s/ //g;

   my @tokens = split(/(=|\(|\)|&&|\|\||!)/, $conditionNoSpace);
   my @stack;

   # For error checking
   my $parenthesis = 0;
   my $operand = 0;
   my $operator = 0;

   foreach my $token (@tokens)
   {
      if ($token eq "")
      {
         # Skip empty token
         next;
      }
      elsif ($token eq "(")
      {
         push @stack, $token;
         ++$parenthesis;
      }
      elsif ($token eq ")")
      {
         &FileInfoParser_die("Incorrect syntax of feature option condition \"$condition\"", __FILE__, __LINE__)
            unless (0 < $parenthesis);
         my $temp = pop(@stack);

         &FileInfoParser_die("Incorrect syntax of feature option condition \"$condition\"", __FILE__, __LINE__)
            if ($temp eq "(");

         do
         {
            push @$expressionTreeRef, $temp;
            $temp = pop(@stack);
         } while ($temp ne "(");

         --$parenthesis;
      }
      elsif ($token eq "=" or $token eq "&&" or $token eq "||" or $token eq "!")
      {
         my $needLoop = 0;

         do
         {
            if (0 == scalar(@stack) or $stack[-1] eq "(")
            {
               # Stack is empty or stack top eqals to (
               push @stack, $token;
               $needLoop = 0;
            }
            elsif (0 < compareFeatureOptionOperator($stack[-1], $token))
            {
               # Stack top has higher priority than current token
               push @stack, $token;
               $needLoop = 0;
            }
            else
            {
               push @$expressionTreeRef, pop(@stack);
               $needLoop = 1;
            }
         } while ($needLoop);

         $operator += 1 unless ($token eq "!");
      }
      elsif ($token =~ /\w+/)
      {
         # Operand
         push @$expressionTreeRef, $token;
         $operand += 1;
      }
      else
      {
         &FileInfoParser_die("Incorrect syntax of feature option condition \"$condition\"",  __FILE__, __LINE__);
      }
   }

   &FileInfoParser_die("Incorrect syntax of feature option condition \"$condition\"", __FILE__, __LINE__)
      unless ($operator == ($operand - 1) and 0 == $parenthesis);

   push @$expressionTreeRef, reverse(@stack);
}

sub compareFeatureOptionOperator
{
   my $first = shift;
   my $second = shift;
   my %operatorToNumber = ("=" => 0, "!" => 1, "&&" => 2, "||" => 2);

   return $operatorToNumber{$first} <=> $operatorToNumber{$second};
}

#****************************************************************************
# subroutine:  FileInfoParser_die
# sample code: (message, __FILE__, __LINE__)
# input:       $error_msg, $file, $line_no
#****************************************************************************
sub FileInfoParser_die
{
    my ($error_msg, $file, $line_no) = @_;
    &sysUtil::error_handler($error_msg, $file, $line_no, 'ProjectMakeFileParser');    
}
sub NoMakeFile_die
{
    my ($MAKEFILE_ref, $file, $line_no) = @_;
    &FileInfoParser_die("Please parse project makefile by FileInfo::Parse_MAKEFILE() before using it.", $file, $line_no) 
        if(!defined $MAKEFILE_ref);
}

#--------------------------------------------------------------------------------------------------------------
package BuildOPT;
#****************************************************************************
# Constant
#****************************************************************************
use constant CMPL         => 0;
use constant REL          => 1;

package BuildInfo;
#****************************************************************************
# Global variable
#****************************************************************************
my $g_CmplOpt_href = undef; # compiler option
my $g_RelInfo_href = undef; # release info
#****************************************************************************
# Subroutine
#****************************************************************************
#****************************************************************************
# subroutine:  Parse_InfoMakeLog
# input:    1. Infomake.log path
#           2. a Hash reference to contain CompilerOption information.
#           3. a Hash reference to contain Release information.
# output:   1=Parse successfully, 0 or die= Parse failed.
# sample code: my %CmplOption;
#              my %RelOption;
#              BuildInfo::Parse_InfoMakeLog($infomake_path, \%CmplOption, \%RelOption);
#****************************************************************************
sub Parse_InfoMakeLog
{
    my ($strInfomake_Path, $CmplOpt_href, $RelInfo_href) = @_;
    my $bResult = 0;
    if(-e $strInfomake_Path)
    {
        open (FILE_HANDLE, $strInfomake_Path) or BuildInfo_die("Cannot open $strInfomake_Path\n", __FILE__, __LINE__);
        while (<FILE_HANDLE>) 
        {
            if(/^(\S+)\s*\=\s*(.*)/)
            {
                my $key = $1;
                my $value = $2;
                if($key =~ /COM_DEFS/)
                {
                    _ParseCMPLOpt($value, $CmplOpt_href);
                }
                else
                {
                    $RelInfo_href->{$1} = $2;
                    $RelInfo_href->{lc($1)} = $2;
                }
            }
        }
        close FILE_HANDLE;
        $g_CmplOpt_href = $CmplOpt_href;
        $g_RelInfo_href = $RelInfo_href;
        $bResult = 1;
    }
    else
    {
        BuildInfo_die("$strInfomake_Path: NOT exist!", __FILE__, __LINE__);
    }
    return $bResult;
}

sub _ParseCMPLOpt
{
    my ($strOptions, $CmplOpt_href) = @_;
    my @ComlOpt = split(/\s/,$strOptions);
    foreach my $Opt(@ComlOpt)
    {
        $Opt =~ s/\s\n\r//;
        next if($Opt eq "");
        my $strkey = $Opt;
        my $strvalue = undef;
        if($Opt =~ /(.*)=(.*)/)
        {
            $strkey = $1;
            $strvalue = $2;
        }
        $CmplOpt_href->{$strkey} = $strvalue;
        $CmplOpt_href->{lc($strkey)} = $strvalue;
    }
}
sub GetCmplOptRef
{
    my ($strInfoMake_Path) = @_;
    if(!defined $g_CmplOpt_href)
    {
        my %CmplOption;
        my %RelOption;
        &Parse_InfoMakeLog($strInfoMake_Path, \%CmplOption, \%RelOption);
    }
    return $g_CmplOpt_href; 
}
sub GetRelOptRef
{
    my ($strInfoMake_Path) = @_;
    if(!defined $g_RelInfo_href)
    {
        my %CmplOption;
        my %RelOption;
        &Parse_InfoMakeLog($strInfoMake_Path, \%CmplOption, \%RelOption);
    }
    return $g_RelInfo_href;
}
#****************************************************************************
# subroutine: exist
# Input:      $nOption: BuildOPT::CMPL or BuildOPT::REL
# Output:     In compiler option, if $strKey exists in compiler option, it will return 1,
#                                 otherwises returns 0
#             In release information, it's usually meaningless to see if $strKey exists 
#****************************************************************************
sub exist
{
    my ($nOption, $strKey, $href) = @_;
    if (!defined $href)
    {
        $href = $g_CmplOpt_href if($nOption == BuildOPT::CMPL);
        $href = $g_RelInfo_href if($nOption == BuildOPT::REL);  
    }
    &NoInfoMake_die($href, __FILE__, __LINE__);
    my $bExist = 0;
    if(exists $href->{$strKey})
    {
        $bExist = 1;
    }
    return $bExist;
}
#****************************************************************************
# subroutine: get
# Input:      $nOption: BuildOPT::CMPL or BuildOPT::REL
# Output:     In compiler option, if it's ooo=xxx, it returns xxx
#                                 otherwises, it returns undef
#             In release information, it returns value directly
#****************************************************************************
sub get
{
    my ($nOption, $strKey, $href) = @_;
    if (!defined $href)
    {
        $href = $g_CmplOpt_href if($nOption == BuildOPT::CMPL);
        $href = $g_RelInfo_href  if($nOption == BuildOPT::REL);  
    }
    &NoInfoMake_die($href, __FILE__, __LINE__);
    my $strValue = undef;
    if(exists $href->{$strKey})
    {
        $strValue = $href->{$strKey};
    }
    return $strValue;
}
#****************************************************************************
# subroutine: is
# Input:      $nOption: BuildOPT::CMPL or BuildOPT::REL
# Output:     1=$href->{$strKey} equals to $strValue, 0=not equal
#****************************************************************************
sub is
{
    my ($nOption, $strKey, $strValue, $href) = @_;
    if (!defined $href)
    {
        $href = $g_CmplOpt_href if($nOption == BuildOPT::CMPL);
        $href = $g_RelInfo_href  if($nOption == BuildOPT::REL);  
    }
    &NoInfoMake_die($href, __FILE__, __LINE__);
    my $bResult = 0;
    if(exists $href->{$strKey})
    {
        $bResult =1 if(lc($strValue) eq lc($href->{$strKey}));
    }
    return $bResult;
}
#****************************************************************************
# subroutine:  BuildInfo_die
# sample code: (message, __FILE__, __LINE__)
# input:       $error_msg, $file, $line_no
#****************************************************************************
sub BuildInfo_die
{
    my ($error_msg, $file, $line_no) = @_;
    &sysUtil::error_handler($error_msg, $file, $line_no, 'BuildInfoParser');    
}

sub NoInfoMake_die
{
    my ($temp_ref, $file, $line_no) = @_;
    &BuildInfo_die("Please parse infomake.log by BuildInfo::ParseInfoMakeLog() before using it.", $file, $line_no) 
        if(!defined $temp_ref);
}
