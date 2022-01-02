/*
	program: addBinary.c
	leetcode: https://leetcode.com/problems/add-binary/
	Runtime: 6 ms, faster than 5.46% of C online submissions for Add Binary.
	Memory Usage: 5.8 MB, less than 41.53% of C online submissions for Add Binary

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(X, Y) (((X) > (Y)) ? (X) : (Y))

char * addBinary(char * a, char * b){


	  int len = max(strlen(a),strlen(b));

	  //extra element padding for NULL character and addition of two numbers results in result being max(len(a),len(b))+1
	  char *sum = (char *)malloc(len+2);
	  sum[len+1] = '\0';//terminate with NULL character


	  int ctra = strlen(a)-1;
	  int ctrb = strlen(b)-1;
	  int ctrs = len;
	  char carry = '0';

	  //run through both arrays
	  while(ctra>=0 && ctrb>=0){
	  	sum[ctrs] = (char) (a[ctra] ^ b[ctrb] ^ carry);
	  	carry = (char) ((a[ctra] & b[ctrb]) | (a[ctra] & carry) | (b[ctrb] & carry));
	 	ctra--;ctrb--;ctrs--;
	  }

	  //complete running through array a
	  if(ctra>=0){
	  while(ctra>=0){
	  	sum[ctrs] = (char) (a[ctra] ^ carry ^ '0');
	 	carry = (char) (a[ctra] & carry);
	 	ctra--;ctrs--;
	  	}
	  }

	  //complete running through array b
	  if(ctrb>=0){
	  while(ctrb>=0){
	    	sum[ctrs] = (char) (b[ctrb] ^ carry ^ '0');
	    	carry = (char) (b[ctrb] & carry);
	   	ctrb--;ctrs--;
	  	}
	  }

	  //record the overflow
	  if(carry=='1'){
	  	sum[ctrs] = carry;
	  	ctrs--;
	  }


	  //check for overflow case and return accordingly
	  if (ctrs<0){ 
	  	return sum;
	  }
	  else{
	  	return (sum+1);
	  }
        
}

int main(int argc, char *argv[]){

	printf("Enter the length of the first binary number to add: ");
	int len_a;
	scanf(" %d",&len_a);


	printf("Enter the length of the second binary number to add: ");
	int len_b;
	scanf(" %d",&len_b);

	char a[len_a];
	char b[len_b];

	printf("Enter the first binary number: ");
        
	for (int i=0;i<len_a;++i){
                scanf(" %c", &a[i]);
        }
	
	printf("Enter the second binary number: ");

        for (int i=0;i<len_b;++i){
                scanf(" %c", &b[i]);
        }

	char *result = addBinary(a,b);
	printf("result: %s\n",result);

	return 0;

}
