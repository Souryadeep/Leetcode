/*
	program: poweroffour.c
	leetcode: https://leetcode.com/problems/power-of-four/
	Runtime: 5 ms, faster than 6.62% of C online submissions for Power of Four
	Memory Usage: 5.4 MB, less than 79.47% of C online submissions for Power of Four

*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool isPowerOfFour(int n){

    if(n<=0)
        return false;
    
    return ((n & (-n)) == n && (n & 0xaaaaaaaa)==0);
    
}

int main(int argc, char* argv[]){

	if(argc<2){
		printf("usage: ./test <number>\n");
		exit(1);
	}
	
	if(isPowerOfFour(atoi(argv[1])))
		  printf("%d is a power of 4\n",atoi(argv[1]));
	else
		  printf("%d is not a power of 4\n",atoi(argv[1]));

	return 0;
}
