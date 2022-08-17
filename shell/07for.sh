#!/bin/sh
if [ $# -eq 0 ]
then
	file='./'
else
	file=$1
fi

echo $file
if [ ! -e $file ]
then
	exit
fi

if [ ! -d $HOME/backup ] 
then
	mkdir $HOME/backup
fi

cd $file
for f1 in  `ls`
do
	if [ -d $f1 ]
	then 
		cp -fr $f1 $HOME/backup
	else
		cp $f1 $HOME/backup
	fi
done	
