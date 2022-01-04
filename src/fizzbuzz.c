/*
	program:fizzbuzz.c
	leetcode: https://leetcode.com/problems/fizz-buzz/
	Runtime: 15 ms, faster than 7.23% of C online submissions for Fizz Buzz
	Memory Usage: 7.2 MB, less than 22.98% of C online submissions for Fizz Buzz
	WARNING: Valgrind does not run clean. I tried to free the allocated memory, but there are some leaks. Functionally, the program works

*/


#include <stdio.h>
#include <stdlib.h>

#define FIZZBUZZ 9
#define FIZZ 5
#define BUZZ 5
#define NUM 6       //max digits is 5


char ** fizzBuzz(int n, int* returnSize){
    
	  char **res = (char **)malloc(sizeof(char*)*n);
	  *returnSize = n;


	  for (int i=1;i<=n;++i){

		    if(i%3 ==0 && i%5 == 0){
		    	res[i-1] = (char *)malloc(sizeof(char)*FIZZBUZZ);
		    	res[i-1] = "FizzBuzz";
		    }
		      
		    else if(i%5 == 0){
		    	res[i-1] = (char *)malloc(sizeof(char)*BUZZ);
		    	res[i-1] = "Buzz";
		    }
		      
		    else if(i%3 == 0){
		    	res[i-1] = (char *)malloc(sizeof(char)*FIZZ);
		      	res[i-1] = "Fizz";
		    }
		      
		    else{
		      	res[i-1] = (char *)malloc(sizeof(char)*NUM);
		      	sprintf(res[i-1],"%d",i);
		    }
  
	}

	return res;
    
}


int main(int argc,char *argv[]){

	if(argc<2){
		printf("usage: ./test <num>\n");
		exit(1);
	}

	int num = atoi(argv[1]);
	
	
	int resultSize;
	char **res = fizzBuzz(num,&resultSize);

	for (int i=0;i<resultSize;++i){
		
		printf("%s ",res[i]);
		//free(res[i]);

	}
	printf("\n");

	//free(res);

	return 0;
}
