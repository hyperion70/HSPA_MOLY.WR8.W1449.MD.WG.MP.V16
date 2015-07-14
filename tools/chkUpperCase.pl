use strict;
use Cwd;

my $theMF = $ARGV[0];

open (FILE_HANDLE, "<$theMF") or die "Cannot open $theMF. Please check if the file do not exists.\n";

while (<FILE_HANDLE>) {
	if (/^(\w+)\b\s*=/)
	{
	  if (/^(\S+)\s*=\s*(\S+)/) {
	    if ($1 ne uc($1)) {
	      print "\nFeature name $1 should be UPPER cases. please Correct $1 to ".uc($1)."\n\n";
	    }

	    if (($2 ne uc($2)) && ($1 !~ /SECURE_CUSTOM_NAME/i) && ($1 !~ /IPSEC_SUPPORT/i) && ($1 !~ /CUSTOM_CFLAGS/i) && ($1 !~ /RELEASE_PACKAGE/i) && ($1 !~ /COMPLIST/i) && ($1 !~ /COMP_TRACE_DEFS/i) && ($1 !~ /CUSTOM_COMMINC/i) && ($1 !~ /L1_TMD_FILES/i) && ($1 !~ /PARTIAL_TRACE_LIB/i)) {
	      print "\n Feature value ($2) of ".uc($1)." should be UPPER cases. please Correct $2 to ".uc($2)."\n";
	    }
	  }
	}
}
close FILE_HANDLE;