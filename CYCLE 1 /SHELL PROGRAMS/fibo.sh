#!/bin/bash

echo "Enter the value of n:"
read n

# Initialize variables
a=0
b=1
i=1

echo "The first $n Fibonacci numbers are:"

# Loop through the first n numbers in the series and print each one
while [ $i -le $n ]
do
  # Print the current number
  echo -n "$a "
  # Calculate the next number in the series
  c=$((a + b))
  # Update the variables for the next iteration
  a=$b
  b=$c
  i=$((i + 1))
done

echo ""

#OUTPUT
#Enter the value of n:
#8
#The first 8 Fibonacci numbers are:
#0 1 1 2 3 5 8 13 


