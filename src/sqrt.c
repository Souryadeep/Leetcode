/*
Leetcode math problem
Q: Given a non-negative integer x, compute and return the square root of x.
Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.
Note: You are not allowed to use any built-in exponent function or operator, such as pow(x, 0.5) or x ** 0.5.

Submission:
Runtime: 45 ms, faster than 5.09% of C online submissions for Sqrt(x).
Memory Usage: 5.5 MB, less than 61.58% of C online submissions for Sqrt(x).
*/

#include <stdio.h>
#include <stdlib.h>

int mySqrt(int);

void main(int argc, char *argv[]){


	int number = atoi(argv[1]);
	int sqrt = mySqrt(number);
	printf("The square root of %d is %d\n",number,sqrt);

}

int mySqrt(int x){

	int i=1;
	while((i*i)<=x)
			i++;
	if (i*i==x)
		return i;
	else
		return (i-1);

}

