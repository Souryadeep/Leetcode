/*
	program: isPallindrome.c
	leetcode: https://leetcode.com/problems/valid-palindrome/
	Runtime: 4 ms, faster than 70.20% of C online submissions for Valid Palindrome
	Memory Usage: 6.9 MB, less than 8.75% of C online submissions for Valid Palindrome

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

//other headers or macros go here

char* strrev(char *s){
    
    char* ret = (char *)malloc(strlen(s)+1);
    int j = 0;
    for(int i=strlen(s)-1;i>=0,j<strlen(s);--i,++j){
        ret[j] = s[i];
    }
    ret[j] = '\0';
    return ret;
    
}

bool isPalindrome(char * s){
    
    char *p = s;
    
    char *s2 = (char *)malloc(strlen(s)+1);
    int i=0;
    
    while(*p){
        
        if(!isalnum(*p)){
            p++;
        }
        else{
            if (*p < 97)
                *p = *p + 32;
            s2[i] = *p;
            p++;
            i++;
        }
            
    }
    s2[i]='\0';

    char* rev = strrev(s2);
    
    if(strcmp(s2,rev))
        return false;
    else
        return true;   
}


int main(int argc, char *argv[]){
    
    if(argc<2){
	printf("usage: ./test <string>\n");
	exit(1);
    }
	
    if(isPalindrome(argv[1]))
	      printf("Is a pallindrome\n");
    else
	      printf("Is not a pallindrome\n");

    return 0;
}

