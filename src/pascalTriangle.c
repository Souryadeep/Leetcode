/*
	program: pascalTriangle.c
	leetcode: https://leetcode.com/problems/pascals-triangle/
	Runtime: 3 ms, faster than 28.89% of C online submissions for Pascal's Triangle
	Memory Usage: 5.9 MB, less than 53.02% of C online submissions for Pascal's Triangle

*/


#include <stdio.h>
#include <stdlib.h>

int** generate(int numRows, int* returnSize, int** returnColumnSizes){

    int** pascal = (int **)malloc(sizeof(int *)*numRows);
    *returnSize = numRows; 
    
    *returnColumnSizes = (int *)malloc(sizeof(int)*numRows);
        
    for(int i=0;i<numRows;++i){        
        pascal[i] = (int *)malloc(sizeof(int)*(i+1));
        
        (*returnColumnSizes)[i] = i+1;
        
        for(int j=0;j<i+1;++j){
            if (j==0 || j == i)
                pascal[i][j] = 1;
            else
                pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
        }
    }

    return pascal;
}

int main(int argc, char* argv[]){

	if(argc<2){
		printf("usage: ./test <num>\n");
		exit(1);
	}
	
	int **returnColumnSizes = (int **)malloc(sizeof(int *)*atoi(argv[1]));

	int *returnSize;

	int **pascal = generate(atoi(argv[1]),returnSize,returnColumnSizes);

	for(int i=0;i<*returnSize;++i){
		for(int j=0;j<returnColumnSizes[0][i];++j){
			printf("%d ",pascal[i][j]);	
		}
		printf("\n");
	}

	return 0;
}
