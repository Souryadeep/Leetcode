/*
	program: lengthoflongestsubstr.c 
	leetcode: https://leetcode.com/problems/longest-substring-without-repeating-characters/
	Runtime: 1601 ms, faster than 5.02% of C online submissions for Longest Substring Without Repeating Characters.
	Memory Usage: 6.2 MB, less than 12.67% of C online submissions for Longest Substring Without Repeating Characters

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//other headers or macros go here


void initarr(char *t,int len){
    
    for(int i=0;i<len;++i){
        t[i] = 0;
    }
}

int lengthOfLongestSubstring(char * s){

    char t[strlen(s)+1];
    int len = strlen(s)+1;
    
    initarr(t,len);
    int i,j,k;
    i=j=k=0;
    //i is slow pointer, j is fast pointer, k indexes into t array
    int maxlen = 0;
    while(s[j]!='\0'){
        
        if(strchr(t,s[j])!=NULL){
                if(k>=maxlen){
                    maxlen = k;
                }
                k=0;
                initarr(t,len);
                i++;
                j=i;
            }
        
        t[k] = s[j];
        k++;
        j++;
        
    }
    if(k>=maxlen)
        maxlen = k;
    return maxlen;
}



/*
int lengthOfLongestSubstring(char * s){

    char t[strlen(s)+1];
    int len = strlen(s)+1;
    
    initarr(t,len);
    int i = 0;
    int maxlen = 0;
    while(*s){
        
        if(strchr(t,*s)){
            if(i>=maxlen){
                maxlen = i;
                i=0;
                initarr(t,len);
            }
        }
        t[i] = *s;
        i++;
        s++;
    }
    if(i>=maxlen)
        maxlen = i;
    return maxlen;
}
*/

int main(int argc, char *argv[]){
		
	if(argc<2){
		printf("usage: ./test <string>\n");
		exit(1);
	}

	char *p = argv[1];
	int len = lengthOfLongestSubstring(p);

	printf("length of longest substring without repitition is: %d\n",len);
	return 0;
}

