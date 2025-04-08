#!/bin/bash
echo "enter the number"
read n
temp="$n"
sum=0
while [ "$temp" -gt 0 ]
do
d=$(( temp%10 ))
sum=$(( sum + d*d*d ))
temp=$((temp/10))
done

if [  $sum -eq $n ] ;then
echo "armstrong"
else
echo "not armstrong"
fi
