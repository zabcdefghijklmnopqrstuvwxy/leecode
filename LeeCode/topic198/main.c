#include<stdio.h>

#define     max(a,b)       a > b ? a : b

int rob(int* nums, int numsSize){
    if(numsSize <= 1)
    {
        return numsSize == 0 ? 0 : nums[0];
    }

    int *dp = (int*)malloc(sizeof(int)*(numsSize));
    int i = 0;
    memset(dp,0,numsSize);
    dp[0] = nums[0];
    dp[1] = max(nums[0],nums[1]);

    for(i = 2; i < numsSize; i++)
    {
        dp[i] = max(dp[i - 2] + nums[i],dp[i-1]);
    }

    return dp[numsSize - 1];
}
