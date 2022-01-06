/*
	program:sumoftwoints.c
	leetcode: https://leetcode.com/problems/sum-of-two-integers/
	Runtime: 2 ms, faster than 11.70% of C online submissions for Sum of Two Integers
	Memory Usage: 5.6 MB, less than 24.47% of C online submissions for Sum of Two Integers
	Solution is based on tips provided on leetcode

*/


#include <stdio.h>
#include <stdlib.h>


int getSum(int a, int b){
        
    	      int x = abs(a); int y = abs(b);
    
	      if(x<y) 
		  return getSum(b,a);
	      
	      int sign = a>0?1:-1;
	      
	      int sum = 0;
	      
	      if(a*b>=0){
		  while(y!=0){
		      sum = x^y;
		      y = (x&y)<<1;
		      x = sum;
		  }
	      }
	      else{
		  while(y!=0){
		      sum = x^y;
		      y = ((~x)&y)<<1;
		      x = sum;
		  }
	      }
	      
	      return sum*sign;
    
}

int main(int argc, char* argv[]){

	if(argc<3){
		printf("usage: ./test <num1> <num2>\n");
		exit(1);
	}

	int a = atoi(argv[1]);
	int b = atoi(argv[2]);

	int result = getSum(a,b);

	printf("The sum is %d\n",result); 

	return 0;
}
