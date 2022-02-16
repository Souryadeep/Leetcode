/*
	PLEASE NOTE:
	this is not my code, it is taken from https://www.geeksforgeeks.org/merge-sort/
	just uploaded to my github as reference
*/

#include <stdio.h>
#include <stdlib.h>

//other headers or macros go here


void merge(int arr[],int l,int m,int r){


	int i,j,k;
	int n1 = m-l+1;
	int n2 = r-m;

	int L[n1];
	int R[n2];

	for(i=0;i<n1;++i)
		  L[i] = arr[l+i];

	for(j=0;j<n2;++j)
		  R[j] = arr[m+1+j];

	i=j=0; k=l;

	while(i<n1 && j<n2){
		if(L[i] <= R[j]){
			arr[k] = L[i];
			i++;
		}
		else{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	//fill in remaining elements

	while(i<n1){
		arr[k++] = L[i++];
	}

	while(j<n2){
		arr[k++] = R[j++];
	}

}

void mergesort(int arr[],int l,int r){

	if(l<r){

		  int m = l + (r-l)/2;	//prevents overflow, as oposed to l+r/2

		  mergesort(arr,l,m);
		  mergesort(arr,m+1,r);

		  merge(arr,l,m,r);
	}

}


int main(int argc, char *argv[]){
    
	int arr[] = {12, 11, 13, 5, 6, 7};	//test case taken from geeksforgeeks
   
	mergesort(arr,0,5);


	//print sorted array
	for (int i=0;i<6;++i){
		printf("%d ",arr[i]);
	}
	printf("\n");

	return 0;

}

