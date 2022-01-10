/*
	program: maxprofit.c
	leetcode: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
	Runtime: 272 ms, faster than 6.36% of C online submissions for Best Time to Buy and Sell Stock
	Memory Usage: 13 MB, less than 58.63% of C online submissions for Best Time to Buy and Sell Stock
*/


#include <stdio.h>
#include <stdlib.h>


int maxProfit(int* prices, int pricesSize){
    
    int minprice = 10000;
    int maxprofit = 0;
    
    for(int i=0;i<pricesSize;++i){
        if(prices[i]<minprice)
            minprice = prices[i];
        else if(prices[i] - minprice > maxprofit)
            maxprofit = prices[i] - minprice;
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
