/*
	program: binarywatch.c
	leetcode: https://leetcode.com/problems/binary-watch/
	Runtime: 0 ms, faster than 100.00% of C online submissions for Binary Watch
	Memory Usage: 5.9 MB, less than 36.84% of C online submissions for Binary Watch
	WARNING: Memory leaks have not been addressed in this program. Functionally, it works

*/

#include <stdio.h>
#include <stdlib.h>

#define HRS 12
#define MINS 60

int hammingWeight(int n) {

	      int ctr=0;
	      while(n!=0){

		  if (n&1)
		      ctr++;
		  n = n >> 1;

	      }
	      return ctr;
}


int factorial(int n){
    
	      int fact = 1;
	      for(int i=1;i<=n;++i)
		  fact = fact*i;
	      return fact;   
}

char ** readBinaryWatch(int turnedOn, int* returnSize){
  
	      char **res;
	      if (turnedOn>=9){
		  *returnSize=0;
		  res = (char **)malloc(sizeof(char*)*(*returnSize));
		  return res;
	      }

	      *returnSize = factorial(10)/(factorial(turnedOn)*factorial(10-turnedOn));
	      res = (char **)malloc(sizeof(char*)*(*returnSize));
	      
	      char **runner = res;
		   
	      int ctr=0;
	      for (int i=0;i<HRS;++i){
		  for (int j=0;j<MINS;++j){
		      
		      int hrs = hammingWeight(i);
		      int mins = hammingWeight(j);
				
		      if (turnedOn == (hrs+mins)){

			  *runner = (char *)malloc(sizeof(char)*6);
			  ctr++;
			  if(j<10){
			      sprintf(*runner, "%d:0%d\0", i,j);
			  }
			  else{
			      sprintf(*runner, "%d:%d\0" , i,j);
			  }
			  
			  runner++;
			  
		      }
		  }
	      }
	      *returnSize = ctr;

	      return res;
}

int main(int argc, char *argv[]){

	if (argc<2){
		printf("usage: ./test <number>\n");
		exit(1);
	}

	int size;
	char** res = readBinaryWatch(atoi(argv[1]),&size);
	
	for(int i=0;i<size;++i){
		printf("%s ",*res);
		res++;
	}	
	printf("\n");

	return 0;
}
