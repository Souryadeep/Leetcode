/*
	program:reversebits.c
	leetcode: https://leetcode.com/problems/reverse-bits/submissions/
	Runtime: 0 ms, faster than 100.00% of C online submissions for Reverse Bits
	Memory Usage: 5.3 MB, less than 72.22% of C online submissions for Reverse Bits.

*/


#include <stdio.h>
#include <stdint.h>

uint32_t reverseBits(uint32_t n) {
    
    uint32_t result = 0;
    uint32_t power = 31;
    
    while(n!=0){
        
        result += (n&1) << power;
        n = n >> 1;
        power--;
          
    }
    return result;
    
}

int main(int argc, char* argv[]){

	uint32_t num = 43261596;	//this is the test case number that leetcode used
	uint32_t result = reverseBits(num);
	printf("%d\n",result);
	return 0;
}
