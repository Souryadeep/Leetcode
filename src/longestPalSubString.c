/*
	program: longestPalSubString.c
	leetcode: https://leetcode.com/problems/longest-palindromic-substring/
	Runtime: 160 ms, faster than 48.48% of C online submissions for Longest Palindromic Substring
	Memory Usage: 6.4 MB, less than 26.73% of C online submissions for Longest Palindromic Substring

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//other headers or macros go here,

#define max(A,B) ((A)>(B))?(A):(B)


int expandAroundCenter(char* s, int left, int right){
    
    int l = left; int r = right;
    while(l>=0 && r<strlen(s) && s[l] == s[r]){
        l--;r++;
    }
    return r-l-1;
}


char * longestPalindrome(char * s){

    int start = 0, end =0;
    if (s == NULL || strlen(s) < 1) return "";
    for(int i=0;i<strlen(s);++i){
        
        int len1 = expandAroundCenter(s,i,i);   //odd length pallindromes
        int len2 = expandAroundCenter(s,i,i+1); //even length pallindromes
        int len = max(len1,len2);
        
        if(len>(end-start)){
            start = i - (len-1)/2;
            end = i + len/2;
        }
    }
    char *res = (char *)calloc((strlen(s)+1),sizeof(char));
    strncpy(res,s+start,(end-start+1));
    return res;
    
}
int main(int argc, char *argv[]){

	if(argc==1){
		fprintf(stderr,"%s\n","usage: ./test <string>");
		exit(1);
	}

	char* res = longestPalindrome(argv[1]);
	printf("Longest pallindromic substring is: %s\n",res);

	free(res);
		
	return 0;
}

