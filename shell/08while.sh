#!/bin/bash
sum=0; i=0
while [ $i -lt 100 ]
do
	i=`expr $i + 1`
	sum=`expr $sum + $i`
done
echo $sum
