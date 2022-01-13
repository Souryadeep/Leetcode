/*
	program: isSameAfterReversal.c
	leetcode: https://leetcode.com/problems/a-number-after-a-double-reversal/
	Runtime: 0 ms, faster than 100.00% of C online submissions for A Number After a Double Reversal
	Memory Usage: 5.4 MB, less than 93.96% of C online submissions for A Number After a Double Reversal
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isSameAfterReversals(int num){

    int result = 0;
    int temp = num;
    while (num/10){
        result = result*10 + (num%10);
        num/=10;
    }
    result = result*10 + (num%10);
    
    int result2 = 0;
    
    while (result/10){
        result2 = result2*10 + (result%10);
        result/=10;
    }
    result2 = result2*10 + (result%10);
    
    if (temp == result2)
        return true;
    else
        return false;
        
}

int main(int argc, char* argv[]){

	if(argc<2){
		printf("usage: ./test <num>\n");
		exit(1);
	}
	
	bool result = isSameAfterReversals(atoi(argv[1]));

	if (result)
		  printf("Double reversal is the same \n");
	else
		  printf("Double reversal is not the same \n");


	return 0;
}
