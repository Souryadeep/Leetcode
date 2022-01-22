/*
	program: firstUniqChar.c
	leetcode: https://leetcode.com/problems/first-unique-character-in-a-string/
	Runtime: 417 ms, faster than 5.16% of C online submissions for First Unique Character in a String.
	Memory Usage: 7.2 MB, less than 17.73% of C online submissions for First Unique Character in a String. 

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//other headers or macros go here

struct uniquechar{
    int ctr;
};

int firstUniqChar(char * s){

    int pos = -1;
    struct uniquechar w[26] = {0};
    for(int i=0;i<strlen(s);++i){
        int temp = s[i] - 'a';
        w[temp].ctr++;
    }
    
    for(int i=0;i<strlen(s);++i){
        int temp = s[i] - 'a';
        if(w[temp].ctr == 1){
            pos = i;
            break;
        }
        
    }
    return pos; 
}

int main(int argc, char *argv[]){

	if(argc!=2){
		fprintf(stderr,"%s\n","usage: ./test <string>");
		exit(1);
	}	
	int res;

	if ((res = firstUniqChar(argv[1]))!=-1)
		printf("First unique at : %d\n",res);
	else
		printf("No unique char\n");

	return 0;
}

