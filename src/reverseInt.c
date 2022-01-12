/*
	program: reverseInt.c
	leetcode: https://leetcode.com/problems/reverse-integer/submissions/
	Runtime: 4 ms, faster than 58.59% of C online submissions for Reverse Integer
	Memory Usage: 5.4 MB, less than 92.73% of C online submissions for Reverse Integer

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int reverse(int x){

    int sign;
    sign = (x<0)? -1:1;
    //x = sign*x;
    int result = 0;
    
    while(x/10){
        result = result*10 + (x%10);
        x/=10;
    }
    
    if (result > INT_MAX/10 && sign == 1){
            return 0;
    }
    else if (result == INT_MAX/10 && x%10 >=8 && sign == 1){
            return 0;
    }
    else if (result < (INT_MIN/10) && sign == -1){
            return 0;
    }
    else if (result == (INT_MIN/10) && x%10 >= 8 && sign == -1){
            return 0;
    }
    else{
            result = result*10 + (x%10);
            return result; 
    }
        
}

int main(int argc, char* argv[]){

	if(argc<2){
		printf("usage: ./test <integer>\n");
		exit(1);
	}

	int res = reverse(atoi(argv[1]));

	printf("Reversed integer is: %d\n",res);

	return 0;
}
