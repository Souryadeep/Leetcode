/*
leetcode math problem 50. Pow(x,n)
this code hits a segmentation fault for very large n, as stack size increases by a lot!
You will get a segmentation fault if you try to run with the upper bound limits described in the question for power
please submit a pull request if you have a solution to this. I saw there is a fast power recursive algo, still to explore that
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

double myPow(double,int);

void main(){

	double res = myPow(2,2147483647);	//chose value of n wisely, to prevent segmentation fault
	printf("%d\n",INT_MAX);
	printf("Result is: %f\n",res);

}

double myPow(double x, int n){

	if (n)
        return n>0?x*myPow(x,n-1):(1/x)*myPow(x,n+1);
    else
        return 1;

}
