#include<stdio.h>

#define     min(a,b)      a < b ? a : b;

int coinChange(int* coins, int coinsSize, int amount){
    if(NULL == coins || coinsSize <= 0)
    {
        return -1;
    }
   
    int *dp = (int*)malloc((amount+1)*sizeof(int));
    int i = 0, j = 0;
    memset(dp,0,(amount+1));

    dp[0] = 0;
    for(i = 1; i < amount + 1; i++)
    {
        dp[i] = INT_MAX;
        for(j = 0; j < coinsSize; j++)
        {
            if(i >= coins[j])
            {
                dp[i] =  min(dp[i],dp[i-coins[j]] + 1);
            }
        }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
}