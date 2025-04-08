#!/bin/bash
echo "enter a number"
read num
reverse=$(echo "$num"|rev)
echo "$reverse"
