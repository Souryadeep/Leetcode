/*
	program: twoSum.c
	leetcode: https://leetcode.com/problems/two-sum/
	Runtime: 92 ms, faster than 42.62% of C online submissions for Two Sum
	Memory Usage: 6.5 MB, less than 52.07% of C online submissions for Two
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    
    int *indices = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;
    
    for(int i=0;i<numsSize;++i){
        
        for(int j=i+1;j<numsSize;++j){
            
            int temp = nums[i] + nums[j];
            if (temp == target){
                indices[0] = i;
                indices[1] = j;
                break;
            }
            
        }
        
    }
    
    return indices;
    
}

int main(int argc,char *argv[]){

	printf("Please enter the size of the array: ");
	int arrsize;
	scanf("%d",&arrsize);

	int array[arrsize];
	printf("Please enter the elements of the array: ");
	for (int i=0;i<arrsize;++i){
		scanf(" %d",&array[i]);
	}

	printf("Please enter the target you wish to compare to: ");
	int target;
	scanf("%d",&target);

	int *returnSize = (int *)malloc(sizeof(int));

	int *indices = twoSum(array,arrsize,target,returnSize);

	for(int i=0;i<*returnSize;++i){
		printf("%d ",indices[i]);
	}
	printf("\n");


	free(indices);
	free(returnSize);

}



