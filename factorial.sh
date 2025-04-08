#!/bin/bash
echo "enter a number"
read n
fact=1
i=1
while [ $i -le $n ]
do
fact=$((fact*i))
((i++))
done
echo "$fact"
