/*
	program: myAtoi.c
	leetcode: https://leetcode.com/problems/string-to-integer-atoi/
	Runtime: 0 ms, faster than 100.00% of C online submissions for String to Integer (atoi)
	Memory Usage: 5.6 MB, less than 89.30% of C online submissions for String to Integer (atoi)

*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>

int myAtoi(char * s){

    int i,n,sign;
    
    for (i=0; isspace(s[i]);i++);    
    
    sign = (s[i]=='-')? -1:1;
    
    if(s[i]=='+' || s[i]=='-')
		i++;
    
    for (n=0;isdigit(s[i]);i++){
        
        if (n > INT_MAX/10 && sign == 1){
            n = INT_MAX;
            return sign*n;
        }
        else if (n == INT_MAX/10 && (s[i]-'0') >=8 && sign == 1){
            n = INT_MAX;
            return sign*n;
        }
        else if (n > (INT_MAX/10) && sign == -1){
            n = INT_MIN;
            return n;
        }
        else if (n == (INT_MAX/10) && (s[i]-'0') >= 8 && sign == -1){
            n = INT_MIN;
            return n;
        }
        else
            n = 10*n + (s[i]-'0');
    }
	return sign*n;
}


int main(int argc, char* argv[]){

	if (argc<2){
		printf("usage: ./test <string num>\n");
		exit(1);
	}

	int result = myAtoi(argv[1]);

	printf("%d\n",result);

	return 0;
}
