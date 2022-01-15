#include <stdio.h>
#include <stdlib.h>

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

