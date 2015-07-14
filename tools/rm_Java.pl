#!/usr/local/bin/perl
# 
# Copyright Statement:
# --------------------
# This software is protected by Copyright and the information contained
# herein is confidential. The software may not be copied and the information
# contained herein may not be used or disclosed except with the written
# permission of MediaTek Inc. (C) 2007
# 
# BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
# THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
# RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
# AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
# NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
# SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
# SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
# THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
# NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
# SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
# 
# BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
# LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
# AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
# OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
# MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
# 
# THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
# WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
# LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
# RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
# THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
# 

use Cwd;

($#ARGV != 5) && &Usage;

my $DEBUG_LOG;

###############################################################
# Get parameters
###############################################################
our $customer = uc($ARGV[0]);
our $project = uc($ARGV[1]);
our $protocol = uc($ARGV[2]); 
our $branch = uc($ARGV[3]);
our $version = uc($ARGV[4]);

if ( (uc($ARGV[5]) ne "RM_JAVA_LIB") && (uc($ARGV[5]) ne "CP_JAVA_SRC") )
{
	warn "Release_type must be RM_JAVA_LIB or CP_JAVA_SRC \n";
	
	&Usage;
}

our $type = uc($ARGV[5]);

###############################################################

my $makeFolder = "..\\make\\";

my $theMF = "${makeFolder}${project}_${protocol}.mak";
my $theMFlog = "${makeFolder}${project}_${protocol}.log";

###############################################################
# Read from Makefile
###############################################################
open (FILE_HANDLE, "<$theMF") or die "cannot open $theMF\n";
while (<FILE_HANDLE>) {
  if (/^(\S+)\s*=\s*(\S+)/) {
    $keyname = lc($1);
    defined($${keyname}) && warn "$1 redefined in $theMF!\n";
    $${keyname} = uc($2);
  }
}
close FILE_HANDLE;
###############################################################

if ($j2me_support eq "NONE")
{
	print "Project $project does not turn on J2ME_SUPPORT. \n";
	print "It is not required to remove Java files. \n";
	
	exit;
}

if (($j2me_support eq "MTK_DUMMYVM") || ($j2me_support eq "MTK_DUMMY_MVM"))
{
	print "MTK_DUMMY_MVM or MTK_DUMMYVM not requir to remove Java files. \n";
	exit;
}

my $java_type;
if ($j2me_support eq "JBLENDIA") {
  $java_vendor = "JBLENDIA";
} elsif ($j2me_support =~ /JBED/i) {
  $java_vendor = "JBED";
} elsif ($j2me_support =~ /IJET/i) {
  $java_vendor = "IJET";
  if (defined $original_flavor) {
    if ($original_flavor ne "NONE") {
      $board_ver = $board_ver."\($original_flavor\)";
    }
  }
} else {
  $java_vendor = "NEMO";
  if (defined $original_flavor) {
    if ($original_flavor ne "NONE") {
      $board_ver = $board_ver."\($original_flavor\)";
    }
  }
}

if(defined $j2me_vm) {
  if ($j2me_support =~ /IJET/i)
  {
    if($j2me_vm eq "HI_VM") {
      $java_type = "j2me_hi";
    } else {
      $java_type = "j2me_11";
    }
  }
  elsif ($j2me_support =~ /JBLENDIA/i)
  {
    $java_type = "jblendia";
  }
  elsif ($j2me_support =~ /JBED/i)
  {
    $java_type = "jbed";
  }
  elsif ($j2me_support =~ /NEMO/i)
  {
  	$java_type = "nemo";
  }
  else
  {
    print "Error: Java Type was not defined!!";
    exit(1);
  }
}

if ($type eq "CP_JAVA_SRC")
{
	print "Copy Java source files from official load...... \n";
	
	# Get Current folder name
	my $dir = getcwd;
	$dir =~ s/\//\\/g;

	# Get relealse folder name
	my @dir = split /\\/, $dir;
	my $official_load_folder = $dir[-3];

	pop @dir;
	my $original_mcu_path = join "\\", @dir;

	# Set Java folder path
	my $srcdir = $official_load_folder . "_Java_src_" . $java_vendor . "_($customer)";
	
	my $src_folder = "..\\..\\..\\$srcdir";
	my $src_mcu_folder = "..\\..\\..\\$srcdir\\mcu";	

	until (-e $src_folder) { mkdir $src_folder, 0755 or warn "cannot create folder $src_folder";}
	until (-e $src_mcu_folder) { mkdir $src_mcu_folder, 0755 or warn "cannot create folder $src_mcu_folder";}

  # copy Java source files
  if (-e "..\\j2me\\")
  {
    if ($java_type eq "jblendia")
    {
      system ("robocopy ..\\j2me\\ $src_mcu_folder\\j2me\\ /XD $original_mcu_path\\j2me\\vm /MIR /NP");
      system ("robocopy ..\\j2me\\vm\\Jblendia\\ $src_mcu_folder\\j2me\\vm\\Jblendia\\ /MIR /NP");
    }
    elsif ($java_type eq "jbed")
    {
      system ("robocopy ..\\j2me\\ $src_mcu_folder\\j2me\\ /XD $original_mcu_path\\j2me\\vm /MIR /NP");
      system ("robocopy ..\\j2me\\vm\\jbed\\ $src_mcu_folder\\j2me\\vm\\jbed\\ /MIR /NP");
    }
    elsif ($java_type eq "nemo")
    {
      system ("robocopy ..\\j2me\\ $src_mcu_folder\\j2me\\ /XD $original_mcu_path\\j2me\\vm /MIR /NP");
      system ("robocopy ..\\j2me\\vm\\NEMO\\ $src_mcu_folder\\j2me\\vm\\NEMO\\ /MIR /NP");
    }
    else
    {
      system ("robocopy ..\\j2me\\ $src_mcu_folder\\j2me\\ /XD $original_mcu_path\\j2me\\vm /MIR /NP");
      system ("robocopy ..\\j2me\\vm\\IJET\\ $src_mcu_folder\\j2me\\vm\\IJET\\ /MIR /NP");
    }
  }
  else
  {
    $DEBUG_LOG .= "(NOT COPY SRC)  ..\\j2me\\ \n";
  }

  if (-e "..\\custom\\j2me\\$java_vendor\\_DEFAULT_BB\\")
  {
    system ("robocopy ..\\custom\\j2me\\$java_vendor\\_DEFAULT_BB\\ $src_mcu_folder\\custom\\j2me\\$java_vendor\\_DEFAULT_BB\\ /MIR /NP");
  }
  else
  {
    $DEBUG_LOG .= "(NOT COPY SRC)  ..\\custom\\j2me\\$java_vendor\\_DEFAULT_BB\\ \n";
  }

  if (-e "..\\custom\\j2me\\$java_vendor\\$board_ver\\")
  {
    system ("robocopy ..\\custom\\j2me\\$java_vendor\\$board_ver\\ $src_mcu_folder\\custom\\j2me\\$java_vendor\\$board_ver\\ /MIR /NP");
  }
  else
  {
    $DEBUG_LOG .= "(NOT COPY SRC)  ..\\custom\\j2me\\$java_vendor\\$board_ver\\ \n";
  }

  if (-e "..\\make\\$java_type\\")
  {
    system ("robocopy ..\\make\\$java_type\\ $src_mcu_folder\\make\\$java_type\\ /MIR /NP");
  }
  else
  {
    $DEBUG_LOG .= "(NOT COPY SRC) ..\\make\\$java_type\\ \n";
  }

  if ($java_type eq "nemo") {
    if (-e "..\\make\\nemo_adp\\")
    {
      system ("robocopy ..\\make\\nemo_adp\\ $src_mcu_folder\\make\\nemo_adp\\ /MIR");
    }
    else
    {
      $DEBUG_LOG .= "(NOT COPY SRC) ..\\make\\nemo_adp\\ \n";
    }
    if (-e "..\\make\\j2me_nemo\\")
    {
      system ("robocopy ..\\make\\j2me_nemo\\ $src_mcu_folder\\make\\j2me_nemo\\ /MIR");
    }
    else
    {
      $DEBUG_LOG .= "(NOT COPY SRC) ..\\make\\j2me_nemo\\ \n";
    }
  }

  # Copy customer project make file for vendor's references.
  print "copy /y $theMF $src_mcu_folder\\make\\$theMFlog\n";
  system ("copy /y $theMF $src_mcu_folder\\make\\$theMFlog");
  
	# Generate release info
	my $RELEASE_LOG = "$src_mcu_folder\\Release.log";
	open (RELEASE_LOG, ">$RELEASE_LOG") or die "cannot open $RELEASE_LOG\n";
	print RELEASE_LOG &Release_Info;
	close RELEASE_LOG;
	
}
elsif ($type eq "RM_JAVA_LIB")
{
	print "Remove Java binary from custom release load...... \n";
	
	# Get Current folder name
	my $dir = getcwd;
	$dir =~ s/\//\\/g;

	# Get relealse folder name
	my @dir = split /\\/, $dir;
	
	my ($release_folder, $original_mcu_path, $libdir, $lib_folder);
	
	if (lc($dir[-2]) eq "mcu")
	{
		$release_folder = $dir[-3];
		pop @dir;
		pop @dir;

		$original_mcu_path = join "\\", @dir;

		# Set Java folder path
		$libdir = $release_folder . "_Java_lib_" . $java_vendor . "_($customer)";

		$lib_folder = "..\\..\\..\\$libdir";
	}
	else
	{
		$release_folder = $dir[-2];
		pop @dir;

		$original_mcu_path = join "\\", @dir;

		# Set Java folder path
		$libdir = $release_folder . "_Java_lib_" . $java_vendor . "_($customer)";

		$lib_folder = "..\\..\\$libdir";
	}

	until (-e $lib_folder) { mkdir $lib_folder, 0755 or die "cannnot create folder $lib_folder";}

	# copy Java lib files
	if (-e "..\\custom\\j2me\\$java_vendor\\")
	{
		system ("robocopy ..\\custom\\j2me\\$java_vendor\\ $lib_folder\\custom\\j2me\\$java_vendor\\ /MIR /NP");
	}
	else
	{
		$DEBUG_LOG .= "(NOT COPY LIB) ..\\custom\\j2me\\$java_vendor\\ \n";
	}

	if (-e "..\\make\\$java_type\\")
	{
		system ("robocopy ..\\make\\$java_type\\ $lib_folder\\make\\$java_type\\ /MIR /NP");
	}
	else
	{
		$DEBUG_LOG .=  "(NOT COPY LIB) ..\\make\\$java_type\\ \n";
	}

  if ($java_type eq "nemo") {
    if (-e "..\\make\\nemo_adp\\")
    {
      system ("robocopy ..\\make\\nemo_adp\\ $lib_folder\\make\\nemo_adp\\ /MIR");
    }
    else
    {
      $DEBUG_LOG .= "(NOT COPY SRC) ..\\make\\nemo_adp\\ \n";
    }
  }

	if (-e "..\\j2me\\")
	{
		if ($java_type eq "jblendia")
		{
			system ("robocopy ..\\j2me\\vm\\Jblendia\\ $lib_folder\\j2me\\vm\\Jblendia\\ /MIR /NP");
		}
		elsif ($java_type eq "jbed")
		{
			system ("robocopy ..\\j2me\\vm\\jbed\\ $lib_folder\\j2me\\vm\\jbed\\ /MIR /NP");
		}
		elsif ($java_type eq "nemo")
		{
			system ("robocopy ..\\j2me\\vm\\NEMO\\ $lib_folder\\j2me\\vm\\NEMO\\ /MIR /NP");
		}
		else
		{
			system ("robocopy ..\\j2me\\vm\\IJET\\ $lib_folder\\j2me\\vm\\IJET\\ /MIR /NP");
		}
	}
	else
	{
		$DEBUG_LOG .=  "(NOT COPY LIB) ..\\j2me\\ \n";
	}

  # Remove Java lib files.
  # For JBLENDIA, do not remove Java lib files.
  if (($java_vendor eq "IJET") || ($java_vendor eq "NEMO")) {
    if (-e "..\\j2me\\vm\\$java_vendor")
    {
      system ("rmdir /s /q ..\\j2me\\vm\\$java_vendor");
    }
    else
    {
      $DEBUG_LOG .=  "(NOT REMOVE LIB) ..\\j2me\\vm\\$java_vendor \n";
    }	
	
    if (-e "..\\j2me\\$java_type.lib")
    {
      system ("del /f /q ..\\j2me\\$java_type.lib");
    }
    else
    {
      $DEBUG_LOG .=  "(NOT REMOVE LIB) ..\\j2me\\$java_type.lib \n";
    }
	
    if (-e "..\\make\\$java_type\\")
    {
      system ("rmdir /s /q ..\\make\\$java_type\\");
    }
    else
    {
      $DEBUG_LOG .=  "(NOT REMOVE LIB) ..\\make\\$java_type\\ \n";
    }
    
    if ($java_vendor eq "NEMO") {
      if (-e "..\\make\\nemo_adp\\")
      {
        system ("rmdir /s /q ..\\make\\nemo_adp\\");
      }
      else
      {
        $DEBUG_LOG .=  "(NOT REMOVE LIB) ..\\make\\nemo_adp\\ \n";
      }
      if (-e "..\\make\\j2me_nemo\\")
      {
        system ("rmdir /s /q ..\\make\\j2me_nemo\\");
      }
      else
      {
        $DEBUG_LOG .=  "(NOT REMOVE LIB) ..\\make\\j2me_nemo\\ \n";
      }
    }

    if (-e "..\\custom\\j2me\\$java_vendor\\")
    {
      system ("rmdir /s /q ..\\custom\\j2me\\$java_vendor\\");
    }
    else
    {
      $DEBUG_LOG .=  "(NOT REMOVE LIB) ..\\custom\\j2me\\$java_vendor\\ \n";
    }

  }

	# Generate release info
	my $RELEASE_LOG = "$lib_folder\\Release.log";
	open (RELEASE_LOG, ">$RELEASE_LOG") or die "cannot open $RELEASE_LOG\n";
	print RELEASE_LOG &Release_Info;
	close RELEASE_LOG;
}

# print warning log
print $DEBUG_LOG;

###############################################################
sub Release_Info
{
	my ($dayOfMonth, $month, $yearOffset) = (localtime(time))[3, 4, 5];

	my $year = 1900 + $yearOffset;
	my $RealMonth = 1 + $month;

	my $date = $year . "/" . $RealMonth . "/" . $dayOfMonth;
	my $full_project = $project. "_" . $protocol;

	my $release_info = << "__END_OF_INFO";
/********************************
Release Info of Java Files

Customer: $customer
Project: $full_project
Branch: $branch
Version: $version

Release Date: $date
*********************************/
__END_OF_INFO

	return $release_info;
}

###############################################################
sub Usage
{
	warn << "__END_OF_USAGE";

<Usage>
remove_java "customer" "project" "modem_type" "branch" "version" "release_type"

<Argument Example>

customer   = ASUS
		  = TCL
		  = EZZE
		  = ...
     
project    = Superman27_05C
		= ARIMA27_06A
		= X320
		= ...

modem_type   = gsm
			 = gprs
			 = ...
     
branch    = 06AW0628MP
		= 05CW0608MP
		= 05BW0540MP
		= 05AW0516MP
		= Custom_FT_08
		= Custom_MP_05
		= Oct04W0506MP
		= Jun04W0504FT
		= ...

version    = V12
		= F1
		= V6_F1
		= ...

release_type   = cp_Java_src  (copy Java related files)
			= rm_Java_lib      (remove Java related files)

<Command Example>

1. To copy Java source from official load

    rm_Java ASUS Superman27_05C gprs 05CW0608MP_1 V73 cp_Java_src

2. To remove Java library from custom release load

    rm_Java ASUS Superman27_05C gprs 05CW0608MP_1 V73 rm_Java_lib

__END_OF_USAGE

	exit 1;
}
