#include<stdio.h>
#include<limits.h>

int maxProfit(int* prices, int pricesSize)
{
    int nMaxProfit = 0;
    int nMin = INT_MAX;
    int i = 0;

    for(i = 0; i < pricesSize; i++)
    {
    	if(prices[i] < nMin)
	{
		nMin = prices[i];
	}
	else if(prices[i] - nMin > nMaxProfit)
	{
		nMaxProfit = prices[i] - nMin;
	}
    }
	

    return nMaxProfit;
}

int main(void)
{
   // int nPrices[] = {2, 4, 1};
    //int nPrices[] = {5, 4, 3, 2, 1};
    //int nPrices[] = {7, 2, 4, 1};	
   // int nPrices[] = {7, 1, 4, 2, 5, 6, 3};
    int nPrices[] = {3, 2, 6, 5, 0, 3};
    int nMaxProfit = 0;
    int i = 0;

    nMaxProfit = maxProfit(nPrices, sizeof(nPrices)/sizeof(int));

    for(i = 0; i < sizeof(nPrices)/sizeof(int); i++)
    {
    	printf("%d\n",nPrices[i]);
    }

    printf("max profit is %d\n",nMaxProfit);

    return 0;
}

