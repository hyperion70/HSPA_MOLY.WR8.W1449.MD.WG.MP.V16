use File::Copy;

my $debug_print = 0;
my $buildFolder = $ARGV[0];
my $databaseFolder = $ARGV[1];

system("del $buildFolder\\*__bin.rar.*");

my @requiredFiles;

for my $eachbin(<$buildFolder\\*.bin>){
  if(-d "$eachbin"){
    for my $eachRom(<$eachbin\\*>){
      if(! -d "$eachRom"){
        push @requiredFiles,"$eachRom";
      }
    }
  }
  else{
    push @requiredFiles,"$eachbin";
  }
}

for my $eachElfFile(<$buildFolder\\*.elf>){
  if(($eachElfFile =~ /_bootloader_/i) || ($eachElfFile =~ /_fota_/i)){
    next;
  }
  push @requiredFiles,"$eachElfFile";
}


for my $eachScatterFile(<$buildFolder\\scat*.txt>){
  push @requiredFiles,"$eachScatterFile";
}

for my $eachCfgFile(<$buildFolder\\*.cfg>){
  push @requiredFiles,"$eachCfgFile";
}

for my $eachDBGinfoFile(<$buildFolder\\dbginfo_*>){
  push @requiredFiles,"$eachDBGinfoFile";
}

for my $eachBPLFile(<$databaseFolder\\BPLGUInfo*>){
  push @requiredFiles,"$eachBPLFile";
}

push @requiredFiles,"$databaseFolder\\mcddll.dll";

my @temprequiredFiles;
for $eachItems(@requiredFiles){
	chomp $eachItems;
  if($eachItems !~ /.sig$/i){
    push @temprequiredFiles,"$eachItems";
  }
}
@requiredFiles = @temprequiredFiles;
for $eachItems(@requiredFiles){
  print $eachItems."\n";
}

#===============================================================================================
# Get rar tool
#===============================================================================================
my $rarPath = "rar.exe";
if (!-e $rarPath)
{
  if (-e "\\\\mbjsap101\\Guardian_Programs\\3rd_party\\rar.exe")
  {
    system("xcopy \\\\mbjsap101\\Guardian_Programs\\3rd_party\\rar.exe .\\");
  }
  elsif (-e "\\\\glbfs14\\sw_releases\\3rd_party\\rar.exe")
  {
    system("xcopy \\\\glbfs14\\sw_releases\\3rd_party\\rar.exe .\\");
  }
  elsif (-e "\\\\mtkrfs01\\Public1\\3rd_party\\rar.exe")
  {
    system("xcopy \\\\mtkrfs01\\Public1\\3rd_party\\rar.exe .\\");
  }
  elsif (-e "\\\\mediatek.inc\\Taiwan\\WCP\\Public\\Public\\3rd_party\\rar.exe")
  {
    system("xocpy \\\\mediatek.inc\\Taiwan\\WCP\\Public\\Public\\3rd_party\\rar.exe .\\");
  }
  else{
    die "Can not find rar.exe\n";
  }
}

if(!-e $rarPath){
	die "No rar.exe in codebase\n";
}

#===============================================================================================
# Compression function
#===============================================================================================
if ($#requiredFiles > -1) {
  # Zip all needed files
  print "Compressing files ......\n";

  if (-e "$buildFolder\\$ENV{\"USERNAME\"}.rar") {
    system "del /q /f $buildFolder\\$ENV{\"USERNAME\"}.rar>nul";
  }

  $fail_num=0;
  foreach $f (@requiredFiles) {
  	next if(!-e "$f");
    print "$rarPath a -r -y -m0 -ep -o+ $buildFolder\\$ENV{\"USERNAME\"}.rar $f\n" if ($debug_print == 1);
    $result = system("$rarPath a -r -y -m0 -ep -o+ $buildFolder\\$ENV{\"USERNAME\"}.rar $f>nul");
    if ($result != 0) {
      $fail_num++;
    }
  }
  print "Compressing was DONE ......\n";
  if ($fail_num>0) {
    print "Some files failed when being compressed.\n" if ($debug_print == 1);
  }
} else {
  print "No file could be compression.\n";
}

my $userName;

if (($ENV{"USERNAME"} =~ /wcxbm/i)&&(-e "username.log")) {
  $userName = getECUserID();
}
else{
  $userName = $ENV{"USERNAME"};
}

my $tttime = time;
my ($sec, $min, $hour, $mday, $mon, $year) = localtime($tttime);
my $rarName = $userName."__bin.rar.".sprintf("%4.4d%2.2d%2.2d%2.2d%2.2d%2.2d", $year+1900, $mon+1, $mday, $hour, $min, $sec);

if (-e "$buildFolder\\$ENV{\"USERNAME\"}.rar") {
  move("$buildFolder\\$ENV{\"USERNAME\"}.rar","$buildFolder\\$rarName") or die "Can not rename rar file\n";
}

print "perl tools\\sender2.pl $buildFolder\\$rarName\n";
print "Send bin\n";
system("perl tools\\sender2.pl $buildFolder\\$rarName") && die "Sender2.pl fail\n";
print "Send bin done\n";

exit 0;

sub getECUserID
{
  my $userID;
  open (FILE_HANDLE, "<username.log") or die "Cannot open username.log\n";
  while (<FILE_HANDLE>) {
  	$line = $_;
  	if($line =~ /^userID=(.+)$/){
  		$userID = $1;
  		chomp $userID;
  		last;
  	}
  }
  close FILE_HANDLE;
  return $userID;
}