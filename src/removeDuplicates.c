/*
	program: removeDuplicates.c
	leetcode: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
	Runtime: 25 ms, faster than 17.49% of C online submissions for Remove Duplicates from Sorted Array
	Memory Usage: 7.5 MB, less than 56.25% of C online submissions for Remove Duplicates from Sorted Array

*/

#include <stdio.h>
#include <stdlib.h>


int removeDuplicates(int* nums,int numsSize){

    if (numsSize==0)
        return 0;
    
    int i=0;
    for (int j=1;j<numsSize;++j){
        if(nums[i]!=nums[j]){
            i++;
            nums[i]=nums[j];
        }
    }
    return i+1;

}

int main(int argc, char* argv[]){

	if (argc == 1){
		printf("usage: ./test <array>\n");
		exit(1);
	}
	
	int arr[argc-1];
	for(int i=1;i<argc;i++){
		arr[i-1] = atoi(argv[i]);
	}

	int len = removeDuplicates(arr,argc-1);

	for (int i=0;i<len;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	
	return 0;
}
