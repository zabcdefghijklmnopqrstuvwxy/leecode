#include<stdio.h>

#define     max(a,b)     a > b ? a : b

int lengthOfLIS(int* nums, int numsSize){
    if(numsSize < 2)
    {
        return numsSize;
    }
    int i = 0, j = 0;
    int nMax = 0;
    int dp[numsSize];
    for(i = 0; i < numsSize; i++)
    {
        dp[i] = 1;
    }

    for(i = 0; i < numsSize; i++)
    {
        for(j = 0; j < i; j++)
        {
            if(nums[j] < nums[i])
            {
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }

    for(i = 0; i < numsSize; i++)
    {
        if(nMax < dp[i])
        {
            nMax = dp[i];
        }
    }

    return nMax;
}