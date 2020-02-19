#include<stdio.h>

int min(int i2,int i3,int i5)
{
    int nMin = 0;

    if(i2 > i3)
    {
        nMin = i3;
    } 
    else
    {
        nMin = i2;
    }

    return nMin < i5 ? nMin : i5;
}

/**
* @brief 动态规划，三指针法。
*/
int nthUglyNumber(int n){
    int *dp = (int*)malloc(n*sizeof(int));
    int nI2 = 0, nI3 = 0, nI5 = 0;
    int nMin = 0;
    dp[0] = 1;

    for(int i = 1;i < n; i++)
    {
        nMin = min(dp[nI2]*2,dp[nI3]*3,dp[nI5]*5);
        if(nMin == dp[nI2]*2)
        {
            nI2++;
        }

        if(nMin == dp[nI3]*3)
        {
            nI3++;
        }

        if(nMin == dp[nI5]*5)
        {
            nI5++;
        }

        dp[i] = nMin;
    }

    return dp[n-1];
}