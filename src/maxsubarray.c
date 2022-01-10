/*
	program: maxSubArray.c
	leetcode: https://leetcode.com/problems/maximum-subarray/
	Runtime: 195 ms, faster than 10.83% of C online submissions for Maximum Subarray
	Memory Usage: 12.5 MB, less than 38.29% of C online submissions for Maximum Subarray

*/


#include <stdio.h>
#include <stdlib.h>

int maxSubArray(int* nums, int numsSize){

    int max = *nums;
    int curr = *nums;
    
    for (int i=1;i<numsSize;++i){
        
        if (curr<0){
            curr = 0;
        }
        curr = curr + nums[i];
        if(curr > max)
            max = curr;
           
    }
    return max;

}

int main(int argc, char* argv[]){

	if(argc==1){
		printf("usage: ./test <array>\n");
		exit(1);
	}

	int nums[argc-1];
	for (int i=1;i<argc;++i){
		nums[i-1] = atoi(argv[i]);
	}

	int maxVal = maxSubArray(nums,argc-1);

	printf("Maximum value is %d\n",maxVal);


	return 0;
}
