#include<stdio.h>

/**
* @brief排列组合 例如百位不能是0所以可能性是9，十位上去掉百位可能性是9，个位上去掉百和十位数字可能性是8
*/
int countNumbersWithUniqueDigits(int n){
    if(n == 0)
    {
        return 1;
    }

    if(n == 1)
    {
        return 10;
    }

    int dp[n];
    int nSum = 0;
    int i = 0;
    dp[0] = 10;
    dp[1] = 9*9;

    nSum = dp[0] + dp[1];
    for(i = 2; i < n; i++)
    {
        dp[i] = dp[i-1]*(10-i);
        nSum = nSum + dp[i];
    }

    return nSum;
}