//program: nextperm.c
//leetcode problem: https://leetcode.com/problems/next-permutation/
/*
	Runtime: 4 ms, faster than 97.42% of C online submissions for Next Permutation
	Memory Usage: 6.1 MB, less than 83.23% of C online submissions for Next Permutation
*/

#include <stdio.h>

void swap(int *nums,int i,int j){
    
    int temp = nums[j];
    nums[j] = nums[i];
    nums[i] = temp;
    
}

void reverse(int *nums,int numsSize,int k){
    
   
    int j=1;
    for (int i=k;i<numsSize;i++){
        swap(nums,i,numsSize-j);
        j++;
        if (i==((numsSize+k-1)/2))
            break;
    }
    
}

void nextPermutation(int* nums, int numsSize){

    int possible = 0;
    
    int i;
    for (i=numsSize-1;i>0;i--){
        
        if(nums[i-1]<nums[i]){
            
            possible = 1;
            int j = i-1;
            int delta = -100;
            int pos = i-1;
                
            while(j<numsSize){
                
                int temp = nums[i-1] - nums[j];
                if (temp<0 && temp>=delta){
                    delta = temp;
                    pos = j;
                }
                j++;
            }
            
            if (pos!= (i-1)){
                swap(nums,i-1,pos);
                break;
            }
            
        }
        
    }
    
    reverse(nums,numsSize,i);
       
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

         nextPermutation(nums,size);
         for (int i=0;i<size;++i){

                 printf("%d ",nums[i]);
         }
         printf("\n");

         return 0;

}
