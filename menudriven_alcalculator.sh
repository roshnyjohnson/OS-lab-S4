#!/bin/bash
echo "enter first number"
read a
echo "enter second number"
read b

while true
do
        echo "1.addition"
        echo "2.subtraction"
        echo "3.multiplication"
        echo "4.division"
        echo "5.modulo"
        echo "6.and"
        echo "7.or"
        echo "8.not"

        read ch
        case $ch in

        1) result=$(( a+b ))
        echo "$result"
        ;;

        2) result=$(( a-b ))
        echo "$result"
        ;;

        3) result=$(( a*b ))
        echo "$result"
        ;;

        4) result=$(( a/b ))
        echo "$result"
        ;;


        5) result=$(( a%b ))
        echo "$result"
        ;;
        6) result=$(( a&b ))
        echo "$result"

        ;;
        7) result=$(( a|b ))
        echo "$result"
        ;;
        8) result=$(( ~a ))
        res=$(( ~b ))
        echo "$result"
        echo "$res"
        ;;
        *) echo "invalid choice"
        ;;
        esac
done

