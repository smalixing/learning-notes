#!/bin/bash
#mysum()
function mysum()
{
	temp=`expr $1 + $2`
	return $temp
}

mysum 15 20
temp=$?
echo $temp
