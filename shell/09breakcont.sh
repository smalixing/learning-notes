#!/bin/bash
sum=0; i=0
while [ $i -lt 100 ]
do
	i=`expr $i + 1`
	if [ $i -eq 5 ]
	then
		#break
		continue
	fi
	sum=`expr $sum + $i`
done
echo $sum
