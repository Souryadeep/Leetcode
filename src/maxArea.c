/*
	program: maxArea.c
	leetcode: https://leetcode.com/problems/container-with-most-water/
	
	Brute force approach:
	Runtime out and not accepted by leetcode for all test cases. Functionally correct solution

	2 pointer approach:
	Runtime: 185 ms, faster than 12.76% of C online submissions for Container With Most Water.
	Memory Usage: 11.9 MB, less than 23.65% of C online submissions for Container With Most Water


*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

int maxArea_brute(int* height, int heightSize){

    int maxarea = 0;
    int ret=0;
    
    for (int i=0;i<heightSize-1;i++){
                
        for (int j=i+1;j<heightSize;j++){
                       
            int area = (height[i]<height[j]?height[i]:height[j])*(j-i);
            maxarea=maxarea>area?maxarea:area;
            
        }
    }
    return maxarea;
}

int maxArea_twoPointer(int* height, int heightSize){

    int maxarea = 0;
    int l = 0;
    int r = heightSize - 1;
    
    while(l<r){
        int area = min(height[l],height[r])*(r-l);
        if(area>maxarea){
            maxarea = area;
        }
        
        if(height[l]<height[r])
            l++;
        else
            r--;
    }
    
    return maxarea;
	
}

int main(int argc, char* argv[]){
	
	if(argc==1){
		printf("usage: ./test <array>\n");
		exit(1);
	}
	int height[argc-1];
	for(int i=1;i<argc;++i){
		height[i-1] = atoi(argv[i]);
	}
	printf("Enter 1 for brute force method, 2 for two pointer method: ");
	int type;
	scanf("%d",&type);

	int area;
	if (type==1)
		area = maxArea_brute(height,argc-1);
	else
		area = maxArea_twoPointer(height,argc-1);

	printf("Max water held = %d\n",area);

	return 0;
}
