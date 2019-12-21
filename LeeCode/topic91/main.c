#include<stdio.h>


/**
* @brief 动态规划，注意'0'和大于7的组合不合法的情况
*/
int numDecodings(char * s){
    int nWay = 0;
    if (s[0] == '0') 
    {
        return 0;
    }
    int *dp = (int*)malloc((strlen(s) + 1)*sizeof(int));
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 1; i < strlen(s); i++)
    {
        if (s[i] == '0')
        {
            if (s[i - 1] == '1' || s[i - 1] == '2') 
            {
                dp[i+1] = dp[i-1];
            }
            else
            {
                return 0;
            }
        }
        else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6'))
        {
            dp[i+1] = dp[i] + dp[i-1];
        }
        else
        {
            dp[i+1] = dp[i];
        }
    }
    nWay = dp[strlen(s)];
    free(dp);
    return nWay;
}
