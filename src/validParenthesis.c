#include <stdio.h>
#include <stdbool.h>

#define STACKSIZE 10000

bool isValid(char * s){
        
    char stack[STACKSIZE];
    int stackptr = STACKSIZE-1;
    bool result = true;
    
    while(*s){
        
        if (*s == '(' || *s == '[' || *s == '{')
            stack[stackptr--] = *s;
        else if(*s == ')'){
            if (stackptr!=STACKSIZE-1 && stack[stackptr+1] != '('){
                result = false;
                break;
            }
            else{
                if (stackptr==STACKSIZE-1){
                    result = false;
                    break;
                }else{
                    stackptr++;
                }
            }
        }
        else if(*s == ']'){
            if (stackptr!=STACKSIZE-1 && stack[stackptr+1] != '['){
                result = false;
                break;
            }
            else{
                if (stackptr==STACKSIZE-1){
                    result = false;
                    break;
                }else{
                    stackptr++;
                }
            }
        }
        else if(*s == '}'){
            if (stackptr!=STACKSIZE-1 && stack[stackptr+1] != '{'){
                result = false;
                break;
            }
            else{
                if (stackptr==STACKSIZE-1){
                    result = false;
                    break;
                }else{
                    stackptr++;
                }
            }
        }
        
        s++;
    }
    
    if (stackptr==STACKSIZE-1)
        return result;
    else
        return false;
}



int main(int argc, char* argv[]){

	if (argc!=2){
		printf("usage: %s\n","./test <string>");
	}
	else{
		bool result = isValid(argv[1]);
		if (result==true)
			printf("This is a valid string\n");

		else
			printf("This is not a valid string\n");
	}
		

}
