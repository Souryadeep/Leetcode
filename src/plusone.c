//program: plusOne.c
//leetcode: https://leetcode.com/problems/plus-one/
//all mallocs have been freed. valgrind runs clean


#include <stdio.h>
#include <stdlib.h>


int* plusOne(int* digits, int digitsSize, int* returnSize);


int main(int argc, char* argv[]){

	int digits[] = {1,2,3};

	int *retArray;
	int *returnSize = (int *)malloc(sizeof(int));
	*returnSize = -1;

	retArray = plusOne(digits,3,returnSize);

	for (int i=0;i<(*returnSize);i++){
		printf("%d\t",retArray[i]);
	}
	printf("\n");


	free(returnSize);
	free(retArray);
	
	return 0;
}

int* plusOne(int* digits, int digitsSize, int* returnSize){

	  int temp1 = *(digits + digitsSize - 1) + 1;
	  int carrytemp = temp1/10;
	  int flag = 0;
	  if (carrytemp!=0)
	  flag = 1;

	  for (int i = digitsSize - 2; i>=0 ; i--){
	  if (digits[i] != 9){
	    flag = 0;
	    break;
	  }   
	  }

	  int* retArray;

	  if (flag == 0){
	  retArray = (int *)malloc(sizeof(int)*digitsSize);
	  *returnSize = digitsSize;
	  }

	  else{
	  retArray = (int *)malloc(sizeof(int)*(digitsSize+1));
	  *returnSize = digitsSize+1;
	  }

	  int carry = 0;

	  for (int i = digitsSize - 1; i>=0 ; i--){

	  int temp2 = temp1 + carry;
	  if (temp2 > 9){
	    carry = temp2/10;
	    retArray[i+flag] = temp2 % 10;
	  }
	  else{
	    retArray[i+flag] = temp2;
	    carry = 0;
	  }

	  if (i!=0)
	    temp1 = digits[i-1];   
	  }

	  if (carry != 0)
	  *retArray = carry; 

	  return retArray;
}
