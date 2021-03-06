#!/usr/local/bin/perl -w

my %fips_tests = (

# FIPS test definitions

# DSA tests

"PQGGen" => "fips_dssvs pqg",
"KeyPair" => "fips_dssvs keypair",
"SigGen" => "fips_dssvs siggen",
"SigVer" => "fips_dssvs sigver",

# SHA tests

"SHA1LongMsg" => "fips_shatest",
"SHA1Monte" => "fips_shatest",
"SHA1ShortMsg" => "fips_shatest",
"SHA224LongMsg" => "fips_shatest",
"SHA224Monte" => "fips_shatest",
"SHA224ShortMsg" => "fips_shatest",
"SHA256LongMsg" => "fips_shatest",
"SHA256Monte" => "fips_shatest",
"SHA256ShortMsg" => "fips_shatest",
"SHA384LongMsg" => "fips_shatest",
"SHA384Monte" => "fips_shatest",
"SHA384ShortMsg" => "fips_shatest",
"SHA512LongMsg" => "fips_shatest",
"SHA512Monte" => "fips_shatest",
"SHA512ShortMsg" => "fips_shatest",

# HMAC

"HMAC" => "fips_hmactest",

# RAND tests

"ANSI931_AES128MCT" => "fips_rngvs mct",
"ANSI931_AES192MCT" => "fips_rngvs mct",
"ANSI931_AES256MCT" => "fips_rngvs mct",
"ANSI931_AES128VST" => "fips_rngvs vst",
"ANSI931_AES192VST" => "fips_rngvs vst",
"ANSI931_AES256VST" => "fips_rngvs vst",

# RSA tests

"SigGen15" => "fips_rsastest",
"SigVer15" => "fips_rsavtest",
"SigGenPSS" => "fips_rsastest -saltlen SALT",
"SigVerPSS" => "fips_rsavtest -saltlen SALT",
"SigGenRSA" => "fips_rsastest -x931",
"SigVerRSA" => "fips_rsavtest -x931",
"KeyGenRSA" => "fips_rsagtest",

# AES tests

"CBCGFSbox128" => "fips_aesavs -f",
"CBCGFSbox192" => "fips_aesavs -f",
"CBCGFSbox256" => "fips_aesavs -f",
"CBCKeySbox128" => "fips_aesavs -f",
"CBCKeySbox192" => "fips_aesavs -f",
"CBCKeySbox256" => "fips_aesavs -f",
"CBCMCT128" => "fips_aesavs -f",
"CBCMCT192" => "fips_aesavs -f",
"CBCMCT256" => "fips_aesavs -f",
"CBCMMT128" => "fips_aesavs -f",
"CBCMMT192" => "fips_aesavs -f",
"CBCMMT256" => "fips_aesavs -f",
"CBCVarKey128" => "fips_aesavs -f",
"CBCVarKey192" => "fips_aesavs -f",
"CBCVarKey256" => "fips_aesavs -f",
"CBCVarTxt128" => "fips_aesavs -f",
"CBCVarTxt192" => "fips_aesavs -f",
"CBCVarTxt256" => "fips_aesavs -f",
"CFB128GFSbox128" => "fips_aesavs -f",
"CFB128GFSbox192" => "fips_aesavs -f",
"CFB128GFSbox256" => "fips_aesavs -f",
"CFB128KeySbox128" => "fips_aesavs -f",
"CFB128KeySbox192" => "fips_aesavs -f",
"CFB128KeySbox256" => "fips_aesavs -f",
"CFB128MCT128" => "fips_aesavs -f",
"CFB128MCT192" => "fips_aesavs -f",
"CFB128MCT256" => "fips_aesavs -f",
"CFB128MMT128" => "fips_aesavs -f",
"CFB128MMT192" => "fips_aesavs -f",
"CFB128MMT256" => "fips_aesavs -f",
"CFB128VarKey128" => "fips_aesavs -f",
"CFB128VarKey192" => "fips_aesavs -f",
"CFB128VarKey256" => "fips_aesavs -f",
"CFB128VarTxt128" => "fips_aesavs -f",
"CFB128VarTxt192" => "fips_aesavs -f",
"CFB128VarTxt256" => "fips_aesavs -f",
"CFB8GFSbox128" => "fips_aesavs -f",
"CFB8GFSbox192" => "fips_aesavs -f",
"CFB8GFSbox256" => "fips_aesavs -f",
"CFB8KeySbox128" => "fips_aesavs -f",
"CFB8KeySbox192" => "fips_aesavs -f",
"CFB8KeySbox256" => "fips_aesavs -f",
"CFB8MCT128" => "fips_aesavs -f",
"CFB8MCT192" => "fips_aesavs -f",
"CFB8MCT256" => "fips_aesavs -f",
"CFB8MMT128" => "fips_aesavs -f",
"CFB8MMT192" => "fips_aesavs -f",
"CFB8MMT256" => "fips_aesavs -f",
"CFB8VarKey128" => "fips_aesavs -f",
"CFB8VarKey192" => "fips_aesavs -f",
"CFB8VarKey256" => "fips_aesavs -f",
"CFB8VarTxt128" => "fips_aesavs -f",
"CFB8VarTxt192" => "fips_aesavs -f",
"CFB8VarTxt256" => "fips_aesavs -f",
#"CFB1GFSbox128" => "fips_aesavs -f",
#"CFB1GFSbox192" => "fips_aesavs -f",
#"CFB1GFSbox256" => "fips_aesavs -f",
#"CFB1KeySbox128" => "fips_aesavs -f",
#"CFB1KeySbox192" => "fips_aesavs -f",
#"CFB1KeySbox256" => "fips_aesavs -f",
#"CFB1MCT128" => "fips_aesavs -f",
#"CFB1MCT192" => "fips_aesavs -f",
#"CFB1MCT256" => "fips_aesavs -f",
#"CFB1MMT128" => "fips_aesavs -f",
#"CFB1MMT192" => "fips_aesavs -f",
#"CFB1MMT256" => "fips_aesavs -f",
#"CFB1VarKey128" => "fips_aesavs -f",
#"CFB1VarKey192" => "fips_aesavs -f",
#"CFB1VarKey256" => "fips_aesavs -f",
#"CFB1VarTxt128" => "fips_aesavs -f",
#"CFB1VarTxt192" => "fips_aesavs -f",
#"CFB1VarTxt256" => "fips_aesavs -f",
"ECBGFSbox128" => "fips_aesavs -f",
"ECBGFSbox192" => "fips_aesavs -f",
"ECBGFSbox256" => "fips_aesavs -f",
"ECBKeySbox128" => "fips_aesavs -f",
"ECBKeySbox192" => "fips_aesavs -f",
"ECBKeySbox256" => "fips_aesavs -f",
"ECBMCT128" => "fips_aesavs -f",
"ECBMCT192" => "fips_aesavs -f",
"ECBMCT256" => "fips_aesavs -f",
"ECBMMT128" => "fips_aesavs -f",
"ECBMMT192" => "fips_aesavs -f",
"ECBMMT256" => "fips_aesavs -f",
"ECBVarKey128" => "fips_aesavs -f",
"ECBVarKey192" => "fips_aesavs -f",
"ECBVarKey256" => "fips_aesavs -f",
"ECBVarTxt128" => "fips_aesavs -f",
"ECBVarTxt192" => "fips_aesavs -f",
"ECBVarTxt256" => "fips_aesavs -f",
"OFBGFSbox128" => "fips_aesavs -f",
"OFBGFSbox192" => "fips_aesavs -f",
"OFBGFSbox256" => "fips_aesavs -f",
"OFBKeySbox128" => "fips_aesavs -f",
"OFBKeySbox192" => "fips_aesavs -f",
"OFBKeySbox256" => "fips_aesavs -f",
"OFBMCT128" => "fips_aesavs -f",
"OFBMCT192" => "fips_aesavs -f",
"OFBMCT256" => "fips_aesavs -f",
"OFBMMT128" => "fips_aesavs -f",
"OFBMMT192" => "fips_aesavs -f",
"OFBMMT256" => "fips_aesavs -f",
"OFBVarKey128" => "fips_aesavs -f",
"OFBVarKey192" => "fips_aesavs -f",
"OFBVarKey256" => "fips_aesavs -f",
"OFBVarTxt128" => "fips_aesavs -f",
"OFBVarTxt192" => "fips_aesavs -f",
"OFBVarTxt256" => "fips_aesavs -f",

# Triple DES tests

"TCBCinvperm" => "fips_desmovs -f",
"TCBCMMT1" => "fips_desmovs -f",
"TCBCMMT2" => "fips_desmovs -f",
"TCBCMMT3" => "fips_desmovs -f",
"TCBCMonte1" => "fips_desmovs -f",
"TCBCMonte2" => "fips_desmovs -f",
"TCBCMonte3" => "fips_desmovs -f",
"TCBCpermop" => "fips_desmovs -f",
"TCBCsubtab" => "fips_desmovs -f",
"TCBCvarkey" => "fips_desmovs -f",
"TCBCvartext" => "fips_desmovs -f",
"TCFB64invperm" => "fips_desmovs -f",
"TCFB64MMT1" => "fips_desmovs -f",
"TCFB64MMT2" => "fips_desmovs -f",
"TCFB64MMT3" => "fips_desmovs -f",
"TCFB64Monte1" => "fips_desmovs -f",
"TCFB64Monte2" => "fips_desmovs -f",
"TCFB64Monte3" => "fips_desmovs -f",
"TCFB64permop" => "fips_desmovs -f",
"TCFB64subtab" => "fips_desmovs -f",
"TCFB64varkey" => "fips_desmovs -f",
"TCFB64vartext" => "fips_desmovs -f",
"TCFB8invperm" => "fips_desmovs -f",
"TCFB8MMT1" => "fips_desmovs -f",
"TCFB8MMT2" => "fips_desmovs -f",
"TCFB8MMT3" => "fips_desmovs -f",
"TCFB8Monte1" => "fips_desmovs -f",
"TCFB8Monte2" => "fips_desmovs -f",
"TCFB8Monte3" => "fips_desmovs -f",
"TCFB8permop" => "fips_desmovs -f",
"TCFB8subtab" => "fips_desmovs -f",
"TCFB8varkey" => "fips_desmovs -f",
"TCFB8vartext" => "fips_desmovs -f",
"TECBinvperm" => "fips_desmovs -f",
"TECBMMT1" => "fips_desmovs -f",
"TECBMMT2" => "fips_desmovs -f",
"TECBMMT3" => "fips_desmovs -f",
"TECBMonte1" => "fips_desmovs -f",
"TECBMonte2" => "fips_desmovs -f",
"TECBMonte3" => "fips_desmovs -f",
"TECBpermop" => "fips_desmovs -f",
"TECBsubtab" => "fips_desmovs -f",
"TECBvarkey" => "fips_desmovs -f",
"TECBvartext" => "fips_desmovs -f",
"TOFBinvperm" => "fips_desmovs -f",
"TOFBMMT1" => "fips_desmovs -f",
"TOFBMMT2" => "fips_desmovs -f",
"TOFBMMT3" => "fips_desmovs -f",
"TOFBMonte1" => "fips_desmovs -f",
"TOFBMonte2" => "fips_desmovs -f",
"TOFBMonte3" => "fips_desmovs -f",
"TOFBpermop" => "fips_desmovs -f",
"TOFBsubtab" => "fips_desmovs -f",
"TOFBvarkey" => "fips_desmovs -f",
"TOFBvartext" => "fips_desmovs -f",
"TCBCinvperm" => "fips_desmovs -f",
"TCBCMMT1" => "fips_desmovs -f",
"TCBCMMT2" => "fips_desmovs -f",
"TCBCMMT3" => "fips_desmovs -f",
"TCBCMonte1" => "fips_desmovs -f",
"TCBCMonte2" => "fips_desmovs -f",
"TCBCMonte3" => "fips_desmovs -f",
"TCBCpermop" => "fips_desmovs -f",
"TCBCsubtab" => "fips_desmovs -f",
"TCBCvarkey" => "fips_desmovs -f",
"TCBCvartext" => "fips_desmovs -f",
"TCFB64invperm" => "fips_desmovs -f",
"TCFB64MMT1" => "fips_desmovs -f",
"TCFB64MMT2" => "fips_desmovs -f",
"TCFB64MMT3" => "fips_desmovs -f",
"TCFB64Monte1" => "fips_desmovs -f",
"TCFB64Monte2" => "fips_desmovs -f",
"TCFB64Monte3" => "fips_desmovs -f",
"TCFB64permop" => "fips_desmovs -f",
"TCFB64subtab" => "fips_desmovs -f",
"TCFB64varkey" => "fips_desmovs -f",
"TCFB64vartext" => "fips_desmovs -f",
"TCFB8invperm" => "fips_desmovs -f",
"TCFB8MMT1" => "fips_desmovs -f",
"TCFB8MMT2" => "fips_desmovs -f",
"TCFB8MMT3" => "fips_desmovs -f",
"TCFB8Monte1" => "fips_desmovs -f",
"TCFB8Monte2" => "fips_desmovs -f",
"TCFB8Monte3" => "fips_desmovs -f",
"TCFB8permop" => "fips_desmovs -f",
"TCFB8subtab" => "fips_desmovs -f",
"TCFB8varkey" => "fips_desmovs -f",
"TCFB8vartext" => "fips_desmovs -f",
"TECBinvperm" => "fips_desmovs -f",
"TECBMMT1" => "fips_desmovs -f",
"TECBMMT2" => "fips_desmovs -f",
"TECBMMT3" => "fips_desmovs -f",
"TECBMonte1" => "fips_desmovs -f",
"TECBMonte2" => "fips_desmovs -f",
"TECBMonte3" => "fips_desmovs -f",
"TECBpermop" => "fips_desmovs -f",
"TECBsubtab" => "fips_desmovs -f",
"TECBvarkey" => "fips_desmovs -f",
"TECBvartext" => "fips_desmovs -f",
"TOFBinvperm" => "fips_desmovs -f",
"TOFBMMT1" => "fips_desmovs -f",
"TOFBMMT2" => "fips_desmovs -f",
"TOFBMMT3" => "fips_desmovs -f",
"TOFBMonte1" => "fips_desmovs -f",
"TOFBMonte2" => "fips_desmovs -f",
"TOFBMonte3" => "fips_desmovs -f",
"TOFBpermop" => "fips_desmovs -f",
"TOFBsubtab" => "fips_desmovs -f",
"TOFBvarkey" => "fips_desmovs -f",
"TOFBvartext" => "fips_desmovs -f"

);

my $win32 = 0;
my $onedir = 0;
my $filter = "";
my $tvdir;
my $tprefix;
my $shwrap_prefix;
my $debug = 0;
my $quiet = 0;
my $rspdir = "rsp";

foreach (@ARGV)
	{
	if ($_ eq "--win32")
		{
		$win32 = 1;
		}
	elsif ($_ eq "--onedir")
		{
		$onedir = 1;
		}
	elsif ($_ eq "--debug")
		{
		$debug = 1;
		}
	elsif ($_ eq "--quiet")
		{
		$quiet = 1;
		}
	elsif (/--dir=(.*)$/)
		{
		$tvdir = $1;
		}
	elsif (/--rspdir=(.*)$/)
		{
		$rspdir = $1;
		}
	elsif (/--tprefix=(.*)$/)
		{
		$tprefix = $1;
		}
	elsif (/--shwrap_prefix=(.*)$/)
		{
		$shwrap_prefix = $1;
		}
	elsif (/--filter=(.*)$/)
		{
		$filter = $1;
		}
	elsif (/--outfile=(.*)$/)
		{
		$outfile = $1;
		}
	}

$tvdir = "." unless defined $tvdir;

if ($win32)
	{
	if (!defined $tprefix)
		{
		if ($onedir)
			{
			$tprefix = ".\\";
			}
		else
			{
			$tprefix = "..\\out32dll\\";
			}
		}
	$outfile = "fipstests.bat" unless defined $outfile;
	open(OUT, ">$outfile");

	print OUT <<END;
\@echo off
rem Test vector run script
rem Auto generated by mkfipsscr.pl script
rem Do not edit

END

	}
else
	{
	if ($onedir)
		{
		$tprefix = "./" unless defined $tprefix;
		$shwrap_prefix = "./" unless defined $shwrap_prefix;
		}
	else
		{
		$tprefix = "../test/" unless defined $tprefix;
		$shwrap_prefix = "../util/" unless defined $shwrap_prefix;
		}
	$outfile = "fipstests.sh" unless defined $outfile;
	open(OUT, ">$outfile");

	print OUT <<END;
#!/bin/sh

# Test vector run script
# Auto generated by mkfipsscr.pl script
# Do not edit

END

	}
my %fips_found;
foreach (keys %fips_tests)
	{
	$fips_found{$_} = 0;
	}

recurse_test($win32, $tprefix, $filter, $tvdir);

while (($key, $value) = each %fips_found)
	{
	if ($value == 0)
		{
		print STDERR "WARNING: test file $key not found\n" unless $quiet;
		}
	elsif ($value > 1)
		{
		print STDERR "WARNING: test file $key found $value times\n" unless $quiet;
		}
	else 
		{
		print STDERR "Found test file $key\n" if $debug;
		}
	}


sub recurse_test
	{
	my ($win32, $tprefix, $filter, $dir) = @_;
	my $dirh;
	opendir($dirh, $dir);
	while ($_ = readdir($dirh))
		{
		next if ($_ eq "." || $_ eq "..");
		$_ = "$dir/$_";
		if (-f "$_")
			{
			next unless /$filter.*\.req$/i;
			if (/\/([^\/]*)\.req$/ && exists $fips_tests{$1})
				{
				$fips_found{$1}++;
				test_line($win32, $_, $tprefix, $fips_tests{$1});
				}
			elsif (! /SHAmix\.req$/)
				{
				print STDERR "WARNING: unrecognized filename $_\n";
				}
			}	
		elsif (-d "$_")
			{
			if (/$filter.*req$/i)
				{
				test_dir($win32, $_);
				}
			recurse_test($win32, $tprefix, $filter, $_);
			}
		}
	closedir($dirh);
	}

sub test_dir
	{
	my ($win32, $req) = @_;
	my $rsp = $req;
	$rsp =~ s/req$/$rspdir/;
	if ($win32)
		{
		$rsp =~ tr|/|\\|;
		$req =~ tr|/|\\|;
		print OUT <<END;

echo Running tests in $req
if exist "$rsp" rd /s /q "$rsp"
md "$rsp"
END
		}
	else
		{
		print OUT <<END;

echo Running tests in "$req"
rm -rf "$rsp"
mkdir "$rsp"

END
		}
	}

sub test_line
	{
	my ($win32, $req, $tprefix, $tcmd) = @_;
	my $rsp = $req;
	$rsp =~ s/req\/([^\/]*).req$/$rspdir\/$1.rsp/;
	if ($tcmd =~ /-f$/)
		{
		if ($win32)
			{
			$req =~ tr|/|\\|;
			$rsp =~ tr|/|\\|;
			print OUT "$tprefix$tcmd \"$req\" \"$rsp\"\n";
			}
		else
			{
			print OUT <<END;
${shwrap_prefix}shlib_wrap.sh $tprefix$tcmd "$req" "$rsp" || { echo "$req failure" ; exit 1 
}
END
			}
		return;
		}
	if ($tcmd =~ /SALT$/)
		{
		open (IN, $req) || die "Can't Open File $req";
		my $saltlen;
		while (<IN>)
			{
			if (/^\s*#\s*salt\s+len:\s+(\d+)\s+$/i)
				{
				my $sl = $1;
				print STDERR "$req salt length $sl\n" if $debug;
				$tcmd =~ s/SALT$/$sl/;
				last;
				}
			}
		close IN;
		if ($tcmd =~ /SALT$/)
			{
			die "Can't detect salt length for $req";
			}
		}
		
	if ($win32)
		{
		$req =~ tr|/|\\|;
		$rsp =~ tr|/|\\|;
	print OUT "$tprefix$tcmd < \"$req\" > \"$rsp\"\n";
		}
	else
		{
		print OUT <<END;
${shwrap_prefix}shlib_wrap.sh $tprefix$tcmd < "$req" > "$rsp" || { echo "$req failure" ; exit 1; }
END
		}
	}

