/*
	program: pallindromepermutation.c
	leetcode: https://leetcode.com/problems/palindrome-permutation/
	Runtime: 2 ms, faster than 6.25% of C online submissions for Palindrome Permutation.
	Memory Usage: 5.5 MB, less than 68.75% of C online submissions for Palindrome Permutation

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXCHARS 26
#define MINCHARVAL 97

bool canPermutePalindrome(char * s){

    
    int arr[MAXCHARS] = {0};
    int ctr = strlen(s);
    bool result = true;

    while(*s){
        
        arr[*s-MINCHARVAL]++;
        s++;
    }
    
    int ctr2=0;
    for(int i=0;i<MAXCHARS;++i){
        
        if(ctr%2==0 && arr[i]%2!=0){
            result = false;
            break;
        }
        else if(ctr%2!=0 && arr[i]%2!=0){
            ctr2++;
            if (ctr2>1){
                result = false;
                break;
            }
        }
    }
    
    return result;
    
}


int main(int argc, char* argv[]){

	if (argc<2){
		printf("usage: ./test <string>\n");
		exit(1);
	}	

	bool result = canPermutePalindrome(argv[1]);
	if(result)
		printf("Pallindrome possible\n");
	else
		printf("Pallindrome not possible\n");
	return 0;
}
