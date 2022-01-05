/*
	program: missingnum.c
	leetcode: https://leetcode.com/problems/missing-number/
	Runtime: 38 ms, faster than 19.44% of C online submissions for Missing Number
	Memory Usage: 6.8 MB, less than 41.10% of C online submissions for Missing Number

*/


#include <stdio.h>
#include <stdlib.h>

int missingNumber(int* nums, int numsSize){

	 int result = numsSize;
	 for(int i=0;i<numsSize;++i){
		result = (int)(result ^ i ^ nums[i]); 
	 }
	 return result;
}

int main(int argc, char *argv[]){

	int i;
	int arr[argc-1];
	for(i=1;i<argc;++i){
		arr[i-1] = atoi(argv[i]);
	}

	int result = missingNumber(arr,(argc-1));
	printf("The missing number is: %d\n",result);		
	return 0;
}
