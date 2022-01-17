/*
	program: searchRange.c
	leetcode: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
	Runtime: 18 ms, faster than 11.19% of C online submissions for Find First and Last Position of Element in Sorted Array
	Memory Usage: 7.4 MB, less than 57.31% of C online submissions for Find First and Last Position of Element in Sorted Array

	NOTE: The approach I have used is naive. Please check leetcode for the solution to solve with O(log n) time complexity
	They have used multiple binary searches
	This solution is accepted nevertheless
*/


#include <stdio.h>
#include <stdlib.h>

//other headers or macros go here

int* searchRange(int* nums, int numsSize, int target, int* returnSize){

    
    *returnSize = 2;
    int* retarr = (int *)malloc(sizeof(int)*2);
    retarr[0] = retarr[1] = -1;
    
    int left = 0; int right = numsSize-1;
    
    while(left<=right){
        
        int mid = left + (right-left)/2;
        if(target<nums[mid])
            right = mid -1;
        else if(target>nums[mid])
            left = mid + 1;
        else{
            int temp = mid;
            while(temp>=0 && nums[temp] == target){
                temp--;
            }
            retarr[0] = temp+1;
            temp = mid;
            while(temp<numsSize && nums[temp] == target){
                temp++;
            }
            retarr[1] = temp-1;
            break;
        }
        
    }  
    return retarr;  
}

int main(int argc, char *argv[]){

	
	if(argc==1){
		fprintf(stderr,"%s\n","usage: ./test <array>");
		exit(1);
	}

	int arr[argc-1];
	for (int i=1;i<argc;++i){
		arr[i-1] = atoi(argv[i]);
	}

	int target;
	printf("Please enter the target: ");
	scanf("%d",&target);
	int *retsize = (int *)malloc(sizeof(int));
	
	//int* res = (int *)malloc(sizeof(int));
	int* res = searchRange(arr,argc-1,target,retsize);

	printf("The position of the elements are: %d and %d\n",res[0],res[1]);

	free(res);
	free(retsize);

	return 0;
}

