/*
	program: guessNumber.c
	leetcode: https://leetcode.com/problems/guess-number-higher-or-lower/
	Runtime: 0 ms, faster than 100.00% of C online submissions for Guess Number Higher or Lower.
	Memory Usage: 5.4 MB, less than 68.75% of C online submissions for Guess Number Higher or Lower.

	NOTE: main is not implemented here as this is an interactive API and guess() API is a blackbox

*/


#include <stdio.h>
#include <stdlib.h>

//other headers or macros go here

int guessNumber(int n){
	
    int left = 1;
    int right = n;
    
    int mid;
    while(left<=right){
         mid = left + (right-left)/2;
        
        if(guess(mid)==-1)
            right = mid - 1;
        else if(guess(mid)==1)
            left = mid + 1;
        else
            break;
    }
    return mid;
    
}

int main(int argc, char *argv[]){
    return 0;
}

