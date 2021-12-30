//program: removeelement.c
//leetcode: https://leetcode.com/problems/remove-element/
/*
	runtime: 0ms; faster than 100% of submissions
	memory usage: 6MB; less than 73.33% of submissions
*/

#include <stdio.h>

int removeElement(int* nums, int numsSize, int val){
    
    int i = 0;
    int j = 0;
    int ctr = 0;
    
    while(j<numsSize){
        if (nums[j]==val){
            j++;
            ctr++;
        }
        else{
            nums[i] = nums[j];
            i++;
            j++;
        }
    }  

        
    return (numsSize - ctr);
    
}

int main(int argc,char *argv[]){

	printf("Enter the size of the array: ");
	int size;
	scanf("%d",&size);

	int nums[size];
	printf("Enter the elements of the array: ");
	for (int i=0;i<size;++i){
		scanf(" %d",&nums[i]);
	}

	printf("Enter the value to remove: ");
	int val;
	scanf("%d",&val);
	
	int result = removeElement(nums,size,val);
	for (int i=0;i<result;++i){

		printf("%d ",nums[i]);
	}
	printf("\n");	

	return 0;
}
