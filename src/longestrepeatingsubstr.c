/*
	Leetcode hints show multiple ways to make this solution more efficient
	In particular, the rabin karp algo seems most efficient, though I have not implemented it here
	
	The solution below is not being accepted by leetcode
	Implementing the hash function is proving to be a challenge in C without hash collisions

	For small strings, this solution works

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//other headers or macros go here


//abcdeabc

#define HASHSIZE 26000   //if all char are z in 2000 chars, largest repeating string is 1000 z's. The hashval will be 26*1000

unsigned hash(char *s){

    unsigned hashval;
    for(hashval = 0; *s!='\0'; ++s){
        hashval = (*s) - 97 + 31*hashval;
    }
    return hashval%HASHSIZE;

}

int search(int l, int strl, char* s){
    
    char* hashtable[HASHSIZE];
    for(int i=0;i<strl-l+1;++i){
        
        char* temp = (char *)malloc(l+1);
        memset (temp, '\0', l+1);
        strncpy(temp,s+i,l);
        
        unsigned h = hash(temp);
        
        if(hashtable[h]!=NULL){
            printf("found: %s\n",hashtable[h]);
	    return h;
	}
        hashtable[h] = (char *)malloc(l+1);
        memset (temp, '\0', l+1);
        strncpy(hashtable[h],s+i,l);
        
        printf("%s\n",hashtable[h]);

        free(temp);        
    }
    return -1;
}

int longestRepeatingSubstring(char * s){

    int l;
    int left = 1;
    int right = strlen(s);
    
    while(left<=right){
        l = left + (right-left)/2;
        if(search(l,strlen(s),s)!=-1)
            left = l+1;
        else
            right = l-1;
    }
    return left-1;    
}

int main(int argc, char *argv[]){
    
    char *s = "abcdeabc";
    int res = longestRepeatingSubstring(s);
    
    printf("longest substring is: %d\n",res);


    return 0;
}

