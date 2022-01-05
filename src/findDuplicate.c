/*
	program: findDuplicate.c
	leetcode: https://leetcode.com/problems/find-the-duplicate-number/
	Runtime: 80 ms, faster than 98.42% of C online submissions for Find the Duplicate Number.
	Memory Usage: 12.3 MB, less than 35.79% of C online submissions for Find the Duplicate Number

	solutions:
	1. Negative marking
	2. Bit manipulation

*/


#include <stdio.h>
#include <stdlib.h>


int findDuplicate1(int* nums, int numsSize){

	  int i;

	  for (i=0;i<numsSize;++i){
		
	  	int curr = abs(nums[i]);
	  	if(nums[curr]<0)
	    		break;
	  	nums[curr] = - nums[curr];

	  }
	  for (int j=0;j<numsSize;++j){
	  	nums[j] =  abs(nums[j]);
	  }
	  return abs(nums[i]);
}


int findDuplicate2(int *nums, int numsSize){
	
	

}

int main(int argc, char* argv[]){

	printf("Enter 1 for 'Negative Marking algo', 2 for 'Bit manipulation algo': ");
	
	int i;
	scanf(" %d",&i);

	int k;
	printf("Enter the size of the array: ");
	scanf(" %d",&k);

	int arr[k];
	printf("Enter the elements of the array: ");
	for (int j=0;j<k;++j)
		scanf(" %d",&arr[j]);
	
	for (int j=0;j<k;++j){
		printf("%d ",arr[j]);
	}
	printf("\n");

	int duplicate =	i==1?findDuplicate1(arr,k):findDuplicate2(arr,k);
	printf("The duplicate number is: %d\n",duplicate);

}
