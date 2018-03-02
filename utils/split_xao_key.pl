#!/usr/bin/perl -l
# Usage: split_xao_key.pl <LONG_KEY>
#@MongBoy

$tempStr=$ARGV[0];


my @keys = split / /,(join ' ', unpack '(A64)*', $tempStr);
print ("\nPublic Spend Key: ",$keys[0]);
print ("Public View keys: ",$keys[1]);
print ("Private Spend Key: ",$keys[2]);
print ("Private View Key: ",$keys[3]);
