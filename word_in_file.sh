#!/bin/bash
echo "enter the word"
read word
echo "enter filename"
read file
if grep -o "$word" "$file" ;then
        echo "word found"
else
        echo "not found"
fi
