#define     min(a,b)    a < b ? a : b
int numSquares(int n){
    int dp[n+1];
    int i,j;
    int val = 0;
    for(i = 0; i <= n; i++)
    {
        dp[i] = 0;
    }

    for(i = 1; i <= n; i++)
    {   
        val = i;
        for(j = 1; i - j*j >= 0; j++)
        {
            val = min(val,dp[i- j*j] + 1);   
        }

        dp[i] = val;
    }
    return dp[n];
}