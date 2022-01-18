/*
	NOTE: This is not a very graceful solution. Leave it as an exercise to use a separate func() to take care of repeated computation
	program: findmissingranges.c
	leetcode: https://leetcode.com/problems/missing-ranges/
	Runtime: 0 ms, faster than 100.00% of C online submissions for Missing Ranges
	Memory Usage: 5.8 MB, less than 61.54% of C online submissions for Missing Ranges 

*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAXCHAR 24
//other headers or macros go here

char ** findMissingRanges(int* nums, int numsSize, int lower, int upper, int* returnSize){

    char** res = (char **)malloc(sizeof(char *)*(numsSize+1));
    
    int j=0;
    int i=0;
    
    if (numsSize!=0 && (i==0 && nums[i]!=lower)){
            int diff = nums[i] - lower;
            if(diff>1){
                res[j] = (char *)malloc(sizeof(char)*MAXCHAR);
                sprintf(res[j],"%d",lower);
                sprintf(res[j]+strlen(res[j]),"%s","->");
                sprintf(res[j]+strlen(res[j]),"%d",nums[0]-1);
                j++;
            }
            else if(diff==1){
                res[j] = (char *)malloc(sizeof(char)*MAXCHAR);
                sprintf(res[j],"%d",lower);
                j++;
            }  
    }
    else if(numsSize==0){
        int diff = upper - lower;
        if(diff>0){
                res[j] = (char *)malloc(sizeof(char)*MAXCHAR);
                sprintf(res[j],"%d",lower);
                sprintf(res[j]+strlen(res[j]),"%s","->");
                sprintf(res[j]+strlen(res[j]),"%d",upper);
                j++;
            }
        else if(diff==0){
                res[j] = (char *)malloc(sizeof(char)*MAXCHAR);
                sprintf(res[j],"%d",lower);
                j++;
            }
    }
        
    
    for(i=0;i<numsSize-1;++i){
               
        
        int diff = nums[i+1]-nums[i];
        if(diff>2){
            res[j] = (char *)malloc(sizeof(char)*MAXCHAR);
            sprintf(res[j],"%d",nums[i]+1);
            sprintf(res[j]+strlen(res[j]),"%s","->");
            sprintf(res[j]+strlen(res[j]),"%d",nums[i+1]-1);
            j++;
        }
        else if(diff>1){
            res[j] = (char *)malloc(sizeof(char)*MAXCHAR);
            sprintf(res[j],"%d",nums[i]+1);
            j++;
        }   
    }
       
    if (i==numsSize-1 && nums[i]!=upper){
            int diff = upper - nums[i];
            if(diff>1){
                res[j] = (char *)malloc(sizeof(char)*MAXCHAR);
                sprintf(res[j],"%d",nums[i]+1);
                sprintf(res[j]+strlen(res[j]),"%s","->");
                sprintf(res[j]+strlen(res[j]),"%d",upper);
                j++;
            }
            else if(diff==1){
                res[j] = (char *)malloc(sizeof(char)*MAXCHAR);
                sprintf(res[j],"%d",upper);
                j++;
            }  
        }
    
    *returnSize = j;
    return res;
    
}


int main(int argc, char *argv[]){
	
	if(argc==1){
		fprintf(stderr,"%s\n","usage: ./test <arr> <lower> <upper>");
		exit(1);
	}

	int arr[argc-3];
	int i;
	for(i=1;i<argc-2;++i){
		arr[i-1] = atoi(argv[i]);	
	}
	int lower = atoi(argv[i]);
	int upper = atoi(argv[i+1]);
	
	int *returnSize = (int *)malloc(sizeof(int));
	char** ret = findMissingRanges(arr, argc-3, lower, upper, returnSize);

	for(i=0;i<*returnSize;++i){
		printf("%s ",ret[i]);
	}
	printf("\n");	

	return 0;
}

