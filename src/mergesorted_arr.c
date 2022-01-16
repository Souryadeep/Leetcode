/*
	program: mergesorted_arr.c
	leetcode: https://leetcode.com/problems/merge-sorted-array/
	Runtime: 8 ms, faster than 16.26% of C online submissions for Merge Sorted Array.
	Memory Usage: 6 MB, less than 99.12% of C online submissions for Merge Sorted Array.	

*/


#include <stdio.h>
#include <stdlib.h>

//other headers or macros go here

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    
    int i = m-1;
    int j = n-1;
    int k = m+n-1;
    
    while(i>=0 && j>=0){
        
        if(nums1[i]>nums2[j]){
            nums1[k--] = nums1[i--];
        }
        else{
            nums1[k--] = nums2[j--];
        }
    }
    while(i>=0)
        nums1[k--] = nums1[i--];
    while(j>=0)
        nums1[k--] = nums2[j--];
    
}
int main(int argc, char *argv[]){

	int len1,len2;
	printf("enter length of array 1 and array 2: ");
	scanf("%d %d",&len1,&len2);
	
	int arr1[len1+len2]; int arr2[len2];
	printf("Enter elements of array 1: ");
	for(int i=0;i<len1+len2;++i){
		if (i<len1)
			scanf(" %d",&arr1[i]);
		else
			  arr1[i]=0;
	}
       	
	printf("Enter elements of array 2: ");
	for(int i=0;i<len2;++i){
		scanf(" %d",&arr2[i]);
	}
	
	merge(arr1,len1,len1,arr2,len2,len2);

	
	for(int i=0;i<len1+len2;++i){
		printf("%d ",arr1[i]);
	}
	printf("\n");

	return 0;
}

