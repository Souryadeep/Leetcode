/*
	Leetcode hints show multiple ways to make this solution more efficient
	In particular, the rabin karp algo seems most efficient, though I have not implemented it here


*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//other headers or macros go here


//abcdeabc

#define HASHSIZE 2147483647   //from hints, this should suffice

unsigned hash(char *s){

    unsigned hashval;
    for(hashval = 0; *s!='\0'; ++s){
        hashval = *s + 31*hashval;
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
        
        if(hashtable[h]!=NULL)
            return h;
        hashtable[h] = (char *)malloc(l+1);
        memset (temp, '\0', l+1);
        strncpy(temp,s+i,l);
        
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
    return l-1;    
}

int main(int argc, char *argv[]){
    
    char *s = "abcdeabc";
    int res = longestRepeatingSubstring(s);
    return 0;
}

