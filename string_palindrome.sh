#!/bin/bash
echo "enter a string"
read s
reverse=$(echo "$s" | rev)
echo "$reverse"
if [ "$reverse" == "$s" ]; then
echo "palindrome"
else
echo "not palindrome"
fi
