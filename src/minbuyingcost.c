/*
	program: minbuyingcost.c
	leetcode: https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/
	Runtime: 12 ms, faster than 100.00% of C online submissions for Minimum Cost of Buying Candies With Discount
	Memory Usage: 6 MB, less than 100.00% of C online submissions for Minimum Cost of Buying Candies With Discount

*/

#include <stdio.h>
#include <stdlib.h>

//other headers or macros go here

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
  
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
  
        //merge(arr, l, m, r);
    }
}


int minimumCost(int* cost, int costSize){

    if(costSize==1){
        return cost[0];
    }
    if(costSize==2){
        return (cost[1]+cost[0]);
    }
    
   insertionSort(cost,costSize);
    
    int sum = 0;
    int ctr = 0;
    for(int i=costSize-1;i>=0;i--){
        if(ctr!=2)
            sum+=cost[i];
        ctr++;
        if(ctr==3)
            ctr=0;
    }    
    
    return sum;
    
}

int main(int argc, char* argv[]){
	
	int arr[] = {6,5,7,9,2,2};
	int sum = minimumCost(arr,6);

	for(int i=0;i<6;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");

	printf("%d\n",sum);
	return 0;
}

