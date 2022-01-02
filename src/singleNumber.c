/*
	program: singleNumber.c
	leetcode: https://leetcode.com/problems/single-number/
	Runtime: 28 ms, faster than 26.50% of C online submissions for Single Number
	Memory Usage: 7.3 MB, less than 38.43% of C online submissions for Single Number

*/



#include <stdio.h>


int singleNumber(int *nums, int numsSize){

	  int res = 0;
	  for (int i=0;i<numsSize;++i){
	  	res = res ^ nums[i];
	  }
	  return res;

}

int main(int argc, char* argv[]){

	printf("Enter length of array: ");
	int len;
	scanf(" %d",&len);

	int arr[len];
	printf("Enter elements of the array: ");
	
	for (int i=0;i<len;++i){
		scanf(" %d",&arr[i]);
	}

	int result = singleNumber(arr,len);
	
	printf("Single number is: %d\n",result);


	return 0;

}
