#!/bin/bash
scope()
{
	local lval=1
	gval=2
	echo "local  var in function = $lval"
	echo "global var in function = $gval"
}

scope

echo "local  var = $lval"
echo "global var = $gval"

