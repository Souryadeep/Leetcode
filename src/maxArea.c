#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

int maxArea(int* height, int heightSize){

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

int main(int argc, char* argv[]){
	
	if(argc==1){
		printf("usage: ./test <array>\n");
		exit(1);
	}
	int height[argc-1];
	for(int i=1;i<argc;++i){
		height[i-1] = atoi(argv[i]);
	}
	int area = maxArea(height,argc-1);

	printf("Max water held = %d\n",area);

	return 0;
}
