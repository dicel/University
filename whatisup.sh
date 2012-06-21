#!/bin/bash
#By Christoph@cDietzel.de
#Script for checking if any lab pc is online and not switched of by one of these monkeys

pcname=icm-2010-

for (( i = 1; i<=22; i++))
do
	#echo $pcname$i:
	if [ `ping $pcname$i -c 2 -q -W 2 | grep time | awk '{print $4}'` -gt 1 ];
	  then
	   echo $pcname$i: up YEAH
	  else
	   echo $pcname$i: down \(a monkey was here\)
	fi
done
