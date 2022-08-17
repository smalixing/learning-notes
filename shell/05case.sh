#!/bin/sh
if [ $# -eq 0 ]
then 
	read d1 op d2
else
	d1=$1
	op=$2
 	d2=$3
fi

case $op in
	+)
	echo -n "$d1 + $d2 = "
	echo `expr $d1 + $d2`
	;;
	-)
	echo -n "$d1 - $d2 = "
	echo `expr $d1 - $d2`
	;;
	\*)
	echo -n "$d1 * $d2 = "
	echo `expr $d1 \* $d2`
	;;
	/)
	if [ $d2 -eq 0  ]
	then
		echo "$d2 could not be zero"
	else
		echo -n "$d1 / $d2 = "
		echo `expr $d1 / $d2`
	fi
	;;
	*)
	echo  "no such operator"
	;;
esac
