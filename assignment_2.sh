#!/bin/sh

: '
NAME: Sky Monts																					
Serial	Number: 20
CS 4350 – Unix Systems Programming
Assignment Number: 2
Due Date: 9 / 25 / 2019
'
echo

printf "The function of this script is to:\n
1. The integer arguments that are entered.
2. Sum of the 3 integer arguments.
3. Product of the 3 integer arguments.
4. Average of the 3 integer arguments.
5. Square of each integer argument.
6. Determine that each integer argument is positive, negative or zero.
7. Determine that each integer argument is odd, or even
8. Find the all odd and even numbers between 1 and the second integer argument.
9. Find the factorial of the first integer argument.
10.Determine whether or not the third integer argument is a prime number.\n"
 

num1=$1
num2=$2
num3=$3
echo 

echo

echo "1) The numbers are $num1 $num2 $num3"

echo

echo "2) $num1 + $num2 + $num3 = $(( $num1+$num2+$num3 ))"


echo

echo "3) $num1 * $num2 * $num3 = $(( $num1*$num2*$num3 ))"


echo 

echo "4) ($num1 + $num2 + $num3)/3 = $(( ($num1+$num2+$num3)/3)) "

echo

echo "5) $num1*$num1 = $(($num1*$num1)) , $num2*$num2 = $(($num2*$num2)) , $num3*$num3 = $(($num3*$num3))"

if [ $num1 -lt 0 ]
then
	temp1="negative"
else
	temp1="positive"
fi

if [ $num2 -lt 0 ]
then
	temp2="negative"
else
	temp2="positive"
fi

if [ $num3 -lt 0 ]
then
	temp3="negative"
else
	temp3="positive"
fi

echo

echo "6) $num1 is $temp1 , $num2 is $temp2 , $num3 is $temp3"

if [ $(( $num1 % 2 )) -eq 0 ]
then
 temp1="even"
else
 temp1="odd"
fi

if [ $(( $num2 % 2 )) -eq 0 ]
then
 temp2="even"
else
 temp2="odd"
fi

if [ $(( $num3 % 2 )) -eq 0 ]
then
 temp3="even"
else
 temp3="odd"
fi

echo

echo "7) $num1 is $temp1 , $num2 is $temp2 , $num3 is $temp3"

echo

echo "8) All odd numbers between 1 and $num2 are: "

echo

for (( i = 2; i < $num2; i++ )); do
	if [ $(( i % 2)) -ne 0 ]
	then
		printf '%s' " " "$i"
	fi
done

echo

echo

echo "9) All even numbers between 1 and $num2 are: "

echo

for (( i = 1; i < $num2; i++ )); do
	if [ $(( i % 2)) -eq 0 ]
		then
		printf '%s' " " "$i"
	fi
done

echo

echo

fact=$num1

for (( i = $num1-1; i > 0; i-- )); do
	let fact=$fact*$i
done

echo "10) Factorial of $num1 is: $fact"

echo

count=0
 
for (( i = 1; i <= $num3; i++ )); do
	if [ $(( $num3 % i )) -eq 0 ]
	then
		let "count++"
	fi
done

if [[ $count -gt 2 ]]; then
	echo "11) $num3 is not prime"
else
	echo "11) $num3 is prime"
fi

echo
echo

echo "End of script"

echo

echo "Implemented by Sky Monts - 9 – 25 - 2019"

echo
