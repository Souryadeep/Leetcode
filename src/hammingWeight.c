/*
	program: hammingWeight.c
	leetcode: https://leetcode.com/problems/number-of-1-bits/
	Runtime: 0 ms, faster than 100.00% of C online submissions for Number of 1 Bits
	Memory Usage: 5.6 MB, less than 9.67% of C online submissions for Number of 1 Bits
*/


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


int hammingWeight(uint32_t n) {
    
    int ctr=0;
    while(n!=0){
        
        if (n&1)
            ctr++;
        n = n >> 1;
        
    }
    return ctr;
    
}

int main(int argc, char* argv[]){

	if (argc<2){
		printf("usage: ./test <number>\n");
		exit(1);
	}

	uint32_t inp = atoi(argv[1]);

	int result = hammingWeight(inp);

	printf("# of 1's in the number (hamming weight) is: %d\n",result);

	return 0;

}
