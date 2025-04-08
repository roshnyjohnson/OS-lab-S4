#!/bin/bash
echo "enter the word"
read word
echo "enter filename"
read file
count=$( grep -o -w "$word" "$file" |wc -l)
if [ $count -gt 0 ] ;then
        echo "word found "$count" times"
else
        echo "not found"
fi
