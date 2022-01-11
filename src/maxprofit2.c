/*
	program: maxprofit2.c 
	leetcode: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
	Runtime: 14 ms, faster than 7.32% of C online submissions for Best Time to Buy and Sell Stock II
	Memory Usage: 6.9 MB, less than 26.99% of C online submissions for Best Time to Buy and Sell Stock II
*/


#include <stdio.h>
#include <stdlib.h>


int maxProfit(int* prices, int pricesSize){
    
    int maxprofit = 0;
    
    for(int i=1;i<pricesSize;++i){
        if(prices[i]<prices[i-1])
            continue;
        else
            maxprofit += prices[i] - prices[i-1];
    }

    return maxprofit;
}

int main(int argc, char* argv[]){

	if(argc==1){
		printf("usage: ./test <array>\n");
		exit(1);
	}

	int arr[argc-1];
	for(int i=1;i<argc;++i){
		arr[i-1] = atoi(argv[i]);
	}

	int maxP = maxProfit(arr,argc-1);

	printf("Max profit achievable is: %d\n",maxP);

	return 0;
}
