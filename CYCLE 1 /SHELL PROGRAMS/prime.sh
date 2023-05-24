#!/bin/bash

echo "Enter a number to check for prime:"
read n

if [ $n -lt 2 ]; then
  echo "$n is not prime"
  exit 0
fi

is_prime=true

for (( i=2; i<=n/2; i++ ))
do
  if [ $((n%i)) -eq 0 ]; then
    is_prime=false
    break
  fi
done

if $is_prime; then
  echo "$n is prime"
else
  echo "$n is not prime"
fi
#OUTPUT
#Enter a number to check for prime:
#12
#12 is not prime

#Test case 2
#Enter a number to check for prime:
#2
#2 is prime

