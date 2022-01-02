/*
	program: hasAlternatingBits.c
	leetcode: https://leetcode.com/problems/binary-number-with-alternating-bits/
	Runtime: 0 ms, faster than 100.00% of C online submissions for Binary Number with Alternating Bits
	Memory Usage: 5.7 MB, less than 25.00% of C online submissions for Binary Number with Alternating Bits

*/


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool hasAlternatingBits(int n){

    bool res = true;
    while((n>>1)!=0){

        if((n&1) == ((n>>1)&1)){

            res = false;
            break;
        }

        n = n >> 1;
    }
    return res;
}


int main(int argc, char* argv[]){


	if(argc<2){
		printf("usage: ./test <number>\n");
		exit(1);
	}
	bool result = hasAlternatingBits(atoi(argv[1]));
	
	if(result == true)
		  printf("Bits are alternating\n");
	else
		  printf("Bits are not alternating\n");		  

	return 0;
}
