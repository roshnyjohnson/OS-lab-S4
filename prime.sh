#!/bin/bash
echo "enter a number"
read n
flag=0
for((i=2;i<=n/2;i++));
do
        if [ $((n%i)) -eq 0 ]; then
        flag=1
        break
        fi
done
if [ "$n" -eq 1 ]; then
echo "not prime"
elif [ "$n" -eq 2 ]; then
echo " prime"
elif [ "$flag" -eq 1 ]; then
echo " not prime"
else
echo "prime "
fi
