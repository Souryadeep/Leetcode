/*
	program: searchInsert.c
	leetcode: https://leetcode.com/problems/search-insert-position/
	Runtime: 14 ms, faster than 6.07% of C online submissions for Search Insert Position
	Memory Usage: 6.2 MB, less than 41.03% of C online submissions for Search Insert Position

*/

#include <stdio.h>
#include <stdlib.h>


int searchInsert(int* nums, int numsSize, int target){

	int low, mid, high;
	
	low = 0;
	high = numsSize - 1;

	while(low<=high){

		mid = (low+high)/2;
		if(target<nums[mid])
			  high = mid - 1;
		else if(target>nums[mid])
			  low = mid + 1;
		else
			  return mid;
	}

	return high+1;
	
}

int main(int argc, char* argv[]){

	
	if(argc==1){
		printf("usage: ./test <array>\n");
		exit(1);
	}
	
	int arr[argc-1];
	for(int i=1;i<argc;++i){
		arr[i-1] = atoi(argv[i]);
	}
	int find;
	printf("Enter the element to search for: ");
	scanf("%d",&find);

	int pos = searchInsert(arr,argc-1,find);

	printf("Position is: %d\n",pos);

	return 0;
}
