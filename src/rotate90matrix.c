/*
	program: rotate90matrix.c
	leetcode: https://leetcode.com/problems/rotate-image/submissions/ 
	Runtime: 4 ms, faster than 81.82% of C online submissions for Rotate Image
	Memory Usage: 6.5 MB, less than 28.57% of C online submissions for Rotate Image
*/

#include <stdio.h>
#include <stdlib.h>

void reverse (int matrix[][4], int matrixSize, int* matrixColSize){
    
    for(int i=0;i<matrixSize;++i){
        for (int j=0;j<(*matrixColSize)/2;++j){  
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][matrixSize-j-1];
            matrix[i][matrixSize-j-1] = temp;
        }
    }
}

void swap (int matrix[][4],int i, int j){
    int temp = matrix[i][j];
    matrix[i][j] = matrix[j][i];
    matrix[j][i] = temp;
}

void rotate(int matrix[][4], int matrixSize, int* matrixColSize){
  
    for (int i=0;i<matrixSize;++i){
        for (int j=i;j<*matrixColSize;++j){  
            if (i==j)
                continue;
            swap(matrix,i,j);
        }
    }
    reverse(matrix,matrixSize,matrixColSize);
}

int main(int argc, char* argv[]){
	
	int matrix[][4] = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
	int matrixSize = 4;
	int matrixColSize[] = {4,4,4,4};

	rotate(matrix,matrixSize,matrixColSize);

	for (int i=0;i<matrixSize;++i){
		for (int j=0;j<matrixSize;++j){
			printf("%3d",matrix[i][j]);
		}
		printf("\n");
	}

	return 0;
}
