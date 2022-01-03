/*
	program: countbits.c
	leetcode: https://leetcode.com/problems/counting-bits/
	Runtime: 59 ms, faster than 15.73% of C online submissions for Counting Bit
	Memory Usage: 10.6 MB, less than 22.20% of C online submissions for Counting Bits

*/

#include <stdio.h>
#include <stdlib.h>

int hamming(int n, int *arr){
    
	  int ctr=0;
	  while(n!=0){

		    if(arr[n]!=-1){
			  ctr = ctr + arr[n];
			  break;
		    }
		      
		    if (n&1)
			  ctr++;
		    
		    n = n >> 1;

	  }
	  return ctr;
    
}

int* countBits(int n, int* returnSize){
    
	  *returnSize = n+1;
	  int* ans = (int *)malloc(sizeof(int)*(*returnSize));

	  //initialize all elements to -1
	  for (int i=0;i<n+1;++i){
	  	ans[i] = -1;
	  }

	  //initialize 0 to have 0 1's to avoid the hamming function call
	  ans[0] = 0;

	  for (int i=1;i<n+1;++i){
	  	ans[i] = hamming(i,ans);
	  }

	  return ans;
    
}



int main(int argc, char* argv[]){


	if (argc<2){
		printf("usage: ./test <number>\n");
		exit(1);
	}

	int *returnSize;
	int *result = countBits(atoi(argv[1]),returnSize);

	for (int i=0;i<*returnSize;++i)
		  printf("%d ", result[i]);
	printf("\n");

	free(result);

	return 0;
}
