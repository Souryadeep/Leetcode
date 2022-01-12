/*
	program: strstr.c
	leetcode: https://leetcode.com/problems/implement-strstr/
	Runtime: 1554 ms, faster than 23.74% of C online submissions for Implement strStr()
	Memory Usage: 6.3 MB, less than 18.83% of C online submissions for Implement strStr()

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int strStr(char * haystack, char * needle){

    int res = -1;
    
    if(strlen(needle)==0)
        return 0;
    if (strlen(haystack)<strlen(needle))
        return -1;
    
    for (int i=0;i<strlen(haystack);++i){
        
        if(strlen(&haystack[i])<strlen(needle))
            break;
        
        if(haystack[i] == needle[0]){
            
            int k;
            for(k=1;k<strlen(needle);++k){
                if(haystack[i+k]!=needle[k])
                    break;
            }
            if(k==strlen(needle)){
                return i;
            }
        }
    }
    return res;


}

int main(int argc, char *argv[]){

	if (argc<3){
		printf("usage: ./test <string1> <string2>\n");
		exit(1);
	}
	char *haystack = argv[1];
	char *needle = argv[2];

	int res = strStr(haystack,needle);

	if (res == -1){
		printf("No occurence is found\n");
	}
	else if (res)
		  printf("First occurence @: %d\n ",res);


	return 0;
}
