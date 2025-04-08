#!/bin/bash
echo "enter a number"
read n
for((i=2;i<n;i++));
do
flag=0
for((j=2;j<=i/2;j++));
do
        if [ $((i%j)) -eq 0 ]; then
        flag=1
        break
        fi
done
#if [ "$n" -eq 1 ]; then
#echo "1"
#if [ "$n" -eq 2 ]; then
#echo " 2"
if [ "$flag" -eq 0 ]; then
echo "$i"
fi
done
