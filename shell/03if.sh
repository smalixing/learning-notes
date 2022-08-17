#!/bin/sh
if test $# -eq 0
then
	echo "using: $0  <file>"
	exit
fi
if [ -f $1 ]
then 
	echo "File $1 exits "
fi
if [ -d $1 ] 
then
	echo "File $1 is a directory"
fi
