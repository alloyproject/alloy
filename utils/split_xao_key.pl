#!/usr/bin/perl -l
# Usage: split_xao_key.pl <LONG_KEY>
#@MongBoy

print ("You didn't provide a GUI Wallet key to split. Use --help for command info.") && exit 1 if (!$tempStr);
if ($tempStr eq '--help') {
        print ("Usage: split_xao_key.pl <LONG_KEY>");
        exit 0;
}
my @keys = split / /,(join ' ', unpack '(A64)*', $tempStr);
print ("\nPublic Spend Key: ",$keys[0]);
print ("Public View keys: ",$keys[1]);
print ("Private Spend Key: ",$keys[2]);
print ("Private View Key: ",$keys[3]);