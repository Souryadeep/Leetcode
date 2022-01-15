#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//other headers or macros go here

bool checkPalinfurther(char* s,char *head, char* tail){
    
    while(head<tail){
        
        if (*head!=*tail){
            return false;
        }
        head++;
        tail--;
    }
    return true;
}

bool validPalindrome(char * s){

    char* head = s;
    char* tail = &s[strlen(s)-1];
    bool result;
    
    while(head<tail){
        
        if (*head!=*tail){
            return checkPalinfurther(s,head+1,tail) || checkPalinfurther(s,head,tail-1);
        }
        head++;
        tail--;
    }
    return true;
        
}

/*
char* strrev(char* s){
    
    char* ret = (char *)malloc(strlen(s)+1);
    int j = 0;
    for(int i=strlen(s)-1;i>=0,j<strlen(s);--i,++j){
        ret[j] = s[i];
    }
    ret[j] = '\0';
    return ret;  
}

bool validPalindrome(char * s){

    if (strlen(s) == 1)
        return true;
    
    char* rev = strrev(s);
    if (!strcmp(s,rev))
        return true;
    
    rev = strrev(s+1);
    if (!strcmp((s+1),rev))
        return true;
    
    char* p2 = s+1;
    
    while(*p2){
        char* temp = (char *)malloc(strlen(s)+1);
        memset (temp, '\0', strlen(s)+1);
        strncpy(temp,s,p2-s);
        if ((p2+1)!=NULL){
             strcat(temp,(p2+1));
        }
        if (!strcmp(temp,strrev(temp)))
            return true;
        free(temp);
        p2++;
    }
    return false;       
}
*/

int main(int argc, char *argv[]){

    if(argc<2){
	printf("usage: ./test <string>\n");
	exit(1);
    }	  
	
    if(validPalindrome(argv[1]))
    	printf("This is a valid pallindrome with at most 1 character removed\n");	
    else
	printf("Cannot be made a valid pallindrome by removing a single character\n");

    return 0;
}

