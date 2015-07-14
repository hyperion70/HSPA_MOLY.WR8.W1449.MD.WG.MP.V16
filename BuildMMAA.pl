#use strict;
use Tie::File;



my $DEBUG = 0;# 0:Non-debug 1:DEBUG

#$ARGV[0] = "PartNumber_cfg.ini";#########
my $PartNumFile = &ParseCmdlineInput(@ARGV);
my ($CkResult, $BoradVer, $SubBoardVer, $PlatForm, $ChipVer, $CusFile, $Mak_File, $Custom, $Project) = &ChkFlashID($PartNumFile);
print $CkResult,"\n" if ($DEBUG);
if($CkResult eq '0')
{
	print "ckflashid is done!";
	&BuildMMAA($BoradVer, $SubBoardVer, $PlatForm, $ChipVer, $CusFile, $Mak_File, $Custom, $Project, $PartNumFile);
}else
{
	print "ckflashid is failed!!";
	die;
}


sub ParseCmdlineInput
{
	my $partfile = '';
	my @argv = @_;
	($#argv < 0) && &Usage;
	while($#argv!=-1)
	{
		print $argv[0],"\n" if ($DEBUG);
		if(-e $argv[0])	
		{
			$partfile = $argv[0];
		}
		else
		{
			print "The Partnum_cfg file is not existed!";
			die;
		}
		
		last;
	}
	return $partfile;
}

sub Existmakeini
{
	my $custemp = '';
	my $protemp = '';
	my $makeini = "make.ini";
	if(-e "make.ini")
	{
		open (MAKINI, "<$makeini")or return 0;
		while(<MAKINI>)
		{
			if (/^custom\s*=\s*(\w.*)\s*$/)
			{
				print $1,"\n" if ($DEBUG);
				$custemp = $1;
			}
			elsif(/^project\s*=\s*(\w.*)\s*$/)
			{
				print $1,"\n" if ($DEBUG);
				$protemp = $1;
			}
		}
		close MAKINI;
		return ($custemp,$protemp);
	}
	else
	{
		system("pause"),"\n" if ($DEBUG);
		return (0,0);
	}

}


sub ChkFlashID
{
	my ($partfile) = @_;
	my $custom = "";
	my $project = "";
	my $ckresult = "";
	#####################################10.01

	my ($aa,$bb) = Existmakeini;
	print $aa,"\n" if ($DEBUG);
	print $bb,"\n" if ($DEBUG);

	print $ARGV[1],"\n" if ($DEBUG);
	print $ARGV[2],"\n" if ($DEBUG);
	system("pause"),"\n" if ($DEBUG);

	if($ARGV[1]=~ /-force/i)###force to rebuild all
	{
		my $partdir = "build\\";
		opendir Pdir, $partdir or die "$!";
		foreach my $file (readdir Pdir)
		{
			print $file,"\n" if ($DEBUG);
			system("pause"),"\n" if ($DEBUG);
			if($file =~ /^\w+\.\w+/i)
			{
				system("rd /q /s build\\$file");
			}
		}
		closedir Pdir;
		($custom, $project) = ($aa,$bb);
	}
	else
	{
		if(($aa eq 0)&&($bb eq 0))
		{
			if ($#ARGV eq 2)
			{
				system("pause"),"\n" if ($DEBUG);
				($custom, $project) = ($ARGV[1],$ARGV[2]);
				print $custom,"\n" if ($DEBUG);
				print $project,"\n" if ($DEBUG);	
			}
			else
			{
				print "Please enter the custom and project!";
				&usage1;
			}
		}
		else
		{
			($custom, $project) = ($aa,$bb);
		}
	}



	####################################Parse_makefile
	#my ($custom, $project) = &ParseMak(".\\make");
	my $mak_file = $custom."_".$project.".mak";
	my ($boradver, $subboardver, $platform, $chipver) = &ParsePrjMak($mak_file);

	my $cusfile = "custom\\system\\".$boradver."\\custom_memorydevice.h";

	if(-e "tools\\ckFlashID.pl")
	{
		system("pause"),"\n" if ($DEBUG);
		#my $memdevlst = &ParseMemDevLst(".\\tools");
		my $memdevlst = &ParseMemDevLst1;
		print $memdevlst,"\n" if ($DEBUG);
		print $cusfile,"\n" if ($DEBUG);
		$ckresult = system("perl tools\\ckFlashID.pl $partfile tools\\MemoryDeviceList\\$memdevlst $cusfile");
		#$ckresult = 0;
	}
	return ($ckresult, $boradver, $subboardver, $platform, $chipver, $cusfile, $mak_file, $custom, $project);
}

sub BuildMMAA  ########
{
	my ($boradver,$subboardver, $platform, $chipver,$cusfile,$mak_file,$custom, $project, $partfile) = @_;
	open(CUSTFILE, "<$cusfile")or die "$!";
	my $backup = $/;
	undef $/;
	my $readfile = <CUSTFILE>;
	$/ = $backup;
	close CUSTFILE;

	my $backupfile = "custom\\system\\".$boradver.".BAK";
	#my $mak_file = $custom."_".$project.".mak";


	if(-e "$backupfile")
	{
		print "BAK folder existed!\n";
	}
	else
	{
		system("robocopy /E .\\custom\\system\\$boradver .\\custom\\system\\$boradver.BAK /NP");
		print "BAK folder is prepared!\n";
	}
	my $i = 0;
	my @errarray = ();

	###########################backup_prj_mak
	&Backup_modify_prj_mak($mak_file);

	open(PARTFILE, "<$partfile")or die "$!";
	while(<PARTFILE>)
	{
		chomp;
		my $temp = '';
		my $Bfile = $custom.'_'.$subboardver.'_'.$project.'_'.$platform.'_'.$chipver;
		my $builtpath = "build\\$custom.$_";
		my $temp = '';
		if(-e $builtpath)
		{
			opendir Bdir, $builtpath or die "$!";
			foreach my $files (readdir Bdir)
			{
				print $files,"\n" if ($DEBUG);
				if($files =~ /^$Bfile.\w+.bin/i)
				{
					$temp  = 1;
				}
			}
			closedir Bdir;
		}
		else 
		{
			$temp = 0;
		}
		print "build\\$custom.$_\\$Bfile"."\n" if ($DEBUG);

		if($temp eq '1')
		{
			next;
		}
		else
		{
			open(INPUT_CUSTFILE, ">$cusfile")or die "$!";
			chomp;
			my $readfile_update = &Replace($readfile,$_);
			print INPUT_CUSTFILE $readfile_update;
			close INPUT_CUSTFILE;
			#system("pause");

			#&SetENV
			$ENV{MMAA_ENABLE}="TRUE";

			my $errpart = &Build($custom, $_, $boradver, $subboardver, $platform, $chipver, $project);
			if($errpart ne "")
			{
				$errarray[$i++] = $errpart;
			}
			#	system("pause");
			&Restore($custom, $mak_file); 
		}
	}
	close PARTFILE;
	system("if exist make\\${makfile}_MMAA_BAK del make\\${makfile}_MMAA_BAK");

	if ($#errarray >= 0)
	{
		print "Partnums below build error,please check them ASAP!\n";
		print @errarray;
	}
}


####################################Subroutine
sub Replace
{
	(my $readfilesub, my $replace) = @_;
	print $replace;
	if($readfilesub =~ /\#define.*?MEMORY_DEVICE_TYPE .*?(\w+)/)
	{
		#print $1;
		if(($1== NOR_RAM_MCP)||($1== NOR_LPSDRAM_MCP))
		{
			#print $1;
			if($readfilesub =~ /\#define.*?CS0_PART_NUMBER.*?(\w+)/)
	   	  	{
		  		$readfilesub =~ s/$1/$replace/;
		  		#print $1;
		  	}
		  	if($readfilesub =~ /\#define.*?CS1_PART_NUMBER.*?(\w+)/)
	   	  	{
		  		$readfilesub =~ s/$1/$replace/;
		  		#print $1;
		  	}
		}
		elsif($1== LPSDRAM)
		{
			if($readfilesub =~ /\#define.*?CS\d_PART_NUMBER.*?(\w+)/)
	    	{
	  			$readfilesub =~ s/$1/$replace/;
	  			#print $_;
	  		}
		}
	}
	return $readfilesub;
}



sub Usage
{
	print "\nUsage:\n perl Build_MMAA.pl <file> \n";
	print "\nDescription:\n";
	print "   <file> = path\\partnumber_cfg.ini  (1st para:partnumber_cfg.ini)\n";
	print "Example:\n";
	print " perl Build_MMAA.pl partnumber_cfg.ini \n";
	exit 1;
}

sub usage1
{
	print "\nUsage:\n perl Build_MMAA.pl <file>  custom project \n";
	print "\nDescription:\n";
	print "   <file> = path\\partnumber_cfg.ini  (1st para:partnumber_cfg.ini)\n";
	print "   custom \n";
	print "   project\n";
	print "Example:\n";
	print " perl Build_MMAA.pl partnumber_cfg.ini AMBER38_DEMO GPRS\n";
	exit 1;
}

sub ParseMak
{
	my $dir = shift;
	my $custom1 = ''; 
	my $project1 = '';
	opendir DH, $dir or die "$!";
	foreach my $file (readdir DH)
	{
		print $file,"\n" if ($DEBUG);
		if($file =~ /^(.*?)_(L1S|BASIC|GSM|GPRS|UMTS|HSPA).mak$/)
		{
			if($1 =~ /^REL.*?$/)
			{
				next;
			}
			$custom1  = $1;
			$project1 = $2;
		}
	}
	closedir DH;
	return ($custom1, $project1);
}

sub ParsePrjMak
{
	my ($makfile) = @_;
	my $original_dir = Win32::GetCwd();
	my @array = ();
    tie @array, 'Tie::File', "$original_dir\\make\\$makfile" or die $!;
	print $makfile,"\n" if ($DEBUG);
	my $BOARD_VER ='';
	my $SUB_BOARD_VER = '';
	my $PLATFORM = '';
	my $CHIP_VER = '';
	foreach my $element (@array)
	{
		#print $element;
		if($element =~ /^BOARD_VER\b.*?=.*?(\w+).*?#.*?/)
		{
			$BOARD_VER = $1;
		}
		if($element =~ /^SUB_BOARD_VER\b.*?=.*?(\w+).*?#.*?/)
		{
			$SUB_BOARD_VER = $1;
		}
		if($element =~ /^PLATFORM\b.*?=.*?(\w+).*?#.*?/)
		{
			$PLATFORM = $1;
		}
		if($element =~ /^CHIP_VER\b.*?=.*?(\w+).*?#.*?/)
		{
			$CHIP_VER = $1;
		}
	}
	untie @array;
	return ($BOARD_VER, $SUB_BOARD_VER, $PLATFORM, $CHIP_VER);
}

sub ParseMemDevLst
{
	my $memdlst = '';
	my ($tool) = @_;
	my $toolsdir = "$tool\\MemoryDeviceList";
	print $toolsdir,"\n" if ($DEBUG);
	opendir DIR, $toolsdir or die "$!";
	foreach my $xlsfile (readdir DIR)
	{
		print $xlsfile,"\n" if ($DEBUG);
		if($xlsfile =~ /^(MemoryDeviceList_\w+?_.*?_MMAA.*?.xls)$/)
		{
			$memdlst  = $1;
			print $memdlst,"\n" if ($DEBUG);
		}
	}
	closedir DIR;
	return $memdlst;
	 
}
sub ParseMemDevLst1_old
{
	my $opt = "make\\option.mak";
	my $original_dir = Win32::GetCwd();
	my $memdevlist;
	my @optarray = ();
    tie @optarray, 'Tie::File', "$original_dir\\$opt" or die $!;
	foreach my $element (@optarray)
	{
		#print $element;
		if($element =~ /^MEMORY_DEVICE_LST.*?=.*?\\(MemoryDeviceList_Since\w+.xls)$/)
		{
			print $1,"\n" if ($DEBUG);
			$memdevlist = $1;
		}
	}
	untie @array;
	return $memdevlist;
}
sub ParseMemDevLst1
{
  my $opt = "tools\\emiGenV6.pl";
  my $memdevlist;
  open(M, "< $opt") or die "cannot open $MF!\n";
  while(<M>){
    if($_ =~ /MEMORY_DEVICE_LST\s*=\s*\"(MemoryDeviceList_Since\w+\.xls)\"/i){
      $memdevlist = $1;
      print $memdevlist."\n";
    }
  }
  return $memdevlist;
}

sub Backup_modify_prj_mak
{
	########################backup prj_mak###test
	my ($makfile) = @_;
	system("copy /Y make\\$makfile make\\${makfile}_MMAA_BAK");

    ########################change prj_mak
    my $original_dir = Win32::GetCwd();
    print $original_dir;
	my @array = ();
    tie @array, 'Tie::File', "$original_dir\\make\\$makfile" or die $!;
	print $makfile;
	untie @array;
}

sub SetENV
{
	$ENV{MMAA_ENABLE}="TRUE";
}



sub Build
{
	my ($customer, $partnum, $boradv, $subboardv, $platf, $chipve, $prj) = @_;
	my $buildpath = "build\\".$customer."\\";
	system("dir build\\$customer>Filename.txt");
	open(File,"Filename.txt");
	#open(File,"dir build\\$custom | ");
	my $backup = $/;
	undef $/;
	my $filename = <File>;
	$/ = $backup;
	close File;

	my $errorpartnum ='';

	my $binfile = $customer.'_'.$subboardv.'_'.$prj.'_'.$platf.'_'.$chipve;

	if(($filename =~ /$binfile.\w+.bin/i)&&($filename =~ /$binfile.elf/i)&&($filename =~ /$binfile.lis/i))
	#if(($filename =~ /scat.*.txt/)&&($filename =~ /$binfile.\w+.bin/i)&&($filename =~ /$binfile.elf/i)&&($filename =~ /$binfile.lis/i))
	{
	    print "sysgen is begin....\n";
		system("perl make.pl $customer $prj sysgen");
		&BackupBBfolder($customer,$partnum,$boradv);
		print "remake is begin....";
		system("perl make.pl $customer $prj c,r custom init drv");
		system("perl make.pl $customer $prj bootloader");#####10.14
		$errorpartnum = &BackupBinFile($customer,$partnum,$boradv, $subboardv, $platf, $chipve,$prj);
	}
	else
	{
		print "new is begin....\n";
		system("perl make.pl $customer $prj new");####2009.12.28
		&BackupBBfolder($customer,$partnum,$boradv);####2009.12.28
		$errorpartnum = &BackupBinFile($customer,$partnum,$boradv, $subboardv, $platf, $chipve,$prj);
	}
	return $errorpartnum;
}



sub BackupBinFile
{
		my $errorpart = '';
		my ($cust,$partn,$boradv, $subboardv, $platfor, $chipv,$project2) = @_;
		
		system("dir build\\$cust>Fileupdate.txt");
		open(File,"Fileupdate.txt");
		#open(File,"dir build\\$custom | ");
		my $backup = $/;
		undef $/;
		my $file = <File>;
		$/ = $backup;
		close File;
		
		#if(($file =~ /scat.*.txt/)&&($file =~ /\s(\w+).bin/)&&($file =~ /.*?elf/)&&($file =~ /.*?lis/))
		my $Binfile = $cust.'_'.$subboardv.'_'.$project2.'_'.$platfor.'_'.$chipv;
		print $Binfile;
		#if(($file =~ /scat.*.txt/)&&($file =~ /$Binfile.\w+.bin/i)&&($file =~ /$Binfile.elf/i)&&($file =~ /$Binfile.lis/i))
		if(($file =~ /$Binfile.\w+.bin/i)&&($file =~ /$Binfile.elf/i)&&($file =~ /$Binfile.lis/i))
		{
			system("robocopy /S build\\$cust build\\$cust.$partn /XD gprs log /NP");
		}
		else
		{
			print "Build cannot be completed!!";
			system("robocopy /E build\\$cust build\\$cust.$partn /NP");	
			$errorpart = $partn;
		}
#		if(-e build\\$custom\\$custom.$partnum)
#		{
#			system();
#		}
		return $errorpart;
}


sub BackupBBfolder
{
	my ($custom, $partnum,$boradv) = @_;
	#my $bb = $custom.'_BB';
	system("robocopy custom\\system\\$boradv custom\\system\\$boradv.$partnum /NP");
}


sub Restore
{
	my ($custom,$makfile) = @_;
	print $makfile;
	my $bak = $custom.'_BB.BAK';
	my $bb = $custom.'_BB';
	if(-e "custom\\system\\$bak")
	{
		print "BAK folder is restore...";
		system("robocopy custom\\system\\$bak custom\\system\\$bb /NP");
	}

	my $bakfile = "make\\".$makfile."_MMAA_BAK";

	system("copy /Y $bakfile make\\$makfile");
}



