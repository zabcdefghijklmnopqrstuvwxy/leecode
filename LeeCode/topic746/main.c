#include<stdio.h>

/**
* @brief 动态规划
*/
int minCostClimbingStairs(int* cost, int costSize){
    if(costSize <= 1)
    {
        return 0;
    }

    int *dp = (int*)malloc((costSize + 1)*sizeof(int));
    int i = 0;
    memset(dp,0,costSize + 1);
    
    dp[0] = 0;
    dp[1] = 0;
    for(i = 2; i <= costSize; i++)
    {
        dp[i] = fmin(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
    }

    return dp[costSize];
}