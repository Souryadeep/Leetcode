/*
	program: climbStairs.c
	leetcode: https://leetcode.com/problems/climbing-stairs/
	Runtime: 0 ms, faster than 100.00% of C online submissions for Climbing Stairs
	Memory Usage: 5.5 MB, less than 54.34% of C online submissions for Climbing Stairs

*/


#include <stdio.h>
#include <stdlib.h>

int climbStairs(int n,int arr[]){

	  if(n<=1)
		    return 1;
	  else if(arr[n]!=-1)
		    return arr[n];
          else{
		    arr[n] = climbStairs((n-1),arr) + climbStairs((n-2),arr);
	  }
	 
	  return arr[n];
					    
}


int main(int argc, char *argv[]){

	if(argc<2){
		printf("usage: ./test <number>\n");
		exit(1);
	}

	int arr[atoi(argv[1])+1];
	for(int i=0;i<=atoi(argv[1]);++i){
		arr[i] = -1;
	}

	int res = climbStairs(atoi(argv[1]),arr);
	printf("Possible combinations are: %d\n",res);

	return 0;
}
