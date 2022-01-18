/*
	program: isSubsequence.c
	leetcode: https://leetcode.com/problems/is-subsequence/
	Runtime: 0 ms, faster than 100.00% of C online submissions for Is Subsequence
	Memory Usage: 5.7 MB, less than 28.00% of C online submissions for Is Subsequence

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//other headers or macros go here

bool isSubsequence(char * s, char * t){

    char* p1 = s;
    char* p2 = t;
    
    if(strlen(s)==0)
        return true;
    
    while(*p1 && *p2){
        
        if(*p1 == *p2){
            p1++;
        }
        p2++;
    }
    
    return (p1-s) == strlen(s);
}


int main(int argc, char *argv[]){

	if(argc==1){
		fprintf(stderr,"%s\n","usage: ./test <string1> <string2>");
		exit(1);
	}

	char* str1; char* str2;

	str1 = argv[1];
	str2 = argv[2];

	bool res = isSubsequence(str1,str2);

	if(res)
		printf("is a subsequence \n");
	else
		printf("is not a subsequence \n");
	
	return 0;
}

