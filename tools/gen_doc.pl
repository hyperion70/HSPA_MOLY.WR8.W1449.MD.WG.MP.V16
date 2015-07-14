#!/usr/bin/perl -w
#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2005
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
#
#*****************************************************************************

use strict;
use warnings;

my $i = 0;
my $internal_dox = 0;
my $tmpfile = "";
my @filelist = ();
our $src_path = ".";

while ($#ARGV != -1) 
{
	$tmpfile = shift(@ARGV);
	
  if ($tmpfile !~ /Template6.0.dox/i)
  {
  	# a flag to generate internal doc
    $internal_dox = 1;
    
    $filelist[$i] = $tmpfile;
    $filelist[$i] = "$src_path\\doc\\dom\\config\\" . $filelist[$i];
    print "\nDOM starts\n";
    print "doxfile: $filelist[$i]\n";
    $i++;
  }
  else
  {
  	print "----------------------------------------------------------------\n";
    print "Template6.0.dox is a DOM template file and NOT a valid dox file.\n";
    print "----------------------------------------------------------------\n";
    exit;
  }
}

&Gen_Doc(@filelist);


sub Gen_Doc
{   
  my (@file_list);
  my ($domfile, $output_dir);      
	
	@file_list = @_ ;
	 
	chdir ($src_path); 
	
	# Get configuration file if argument is empty
	if ($#file_list == -1)
	{
	   @file_list = <$src_path\\doc\\dom\\config\\*.dox>;

	   if ($#file_list == -1)
	   {
		    print "\nDOM configuration file (.dox) does not exist !!\n";
	   }
  }

	foreach (@file_list) 
	{   
	   if ((-f $_) && ($_ !~ /Template6.0.dox/i) && (($_ !~ /internal.dox/i) || ($internal_dox == 1)))
	   {
	     print "===========================================\n";   
	     $domfile = $_;
	          
       print "Read the configuration file\n";
      
   	   open (DOMFILE, $domfile) or die "cannot open $domfile\n";
	     while (<DOMFILE>) 
	     {
           if (/^OutputDir\s*=\s*..\\..\\(.*)/)
           {
              $output_dir = uc($1);
              last;
           }       
        }
        close DOMFILE;

        print "\nCreate output_dir: $src_path\\doc\\$output_dir\n";
        
        system("md $src_path\\doc\\$output_dir") if (!-e "$src_path\\doc\\$output_dir");

        system("perl tools\\dom.pl -cfg chm -dox $domfile");

        print "===========================================\n";	      
	   }    
	}
}
