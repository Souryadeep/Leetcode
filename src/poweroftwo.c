/*
	program: poweroftwo.c
	leetcode: https://leetcode.com/problems/power-of-two/
	Runtime: 3 ms, faster than 50.58% of C online submissions for Power of Two
	Memory Usage: 5.4 MB, less than 98.42% of C online submissions for Power of Two

*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isPowerofTwo(int n){

	if(n<=0)
		  return false;
	return  (n & (-n)) == n;
}


int main(int argc,char* argv[]){

	if(argc<2){
		printf("usage: ./test <number>\n");
		exit(1);
	}
	if(isPowerofTwo(atoi(argv[1])))
		  printf("%d is a power of two\n",atoi(argv[1]));
	else
		  printf("%d is not a power of two\n",atoi(argv[1]));

	return 0;
}
