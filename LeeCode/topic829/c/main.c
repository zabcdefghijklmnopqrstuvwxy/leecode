/*
* @brief 假设N由1个数组成即就是其本身，N由2个数组成时即N= x + x + 1，则N -1对2是整除，
* 若N由三个数组成即N=x + x+1 + x+2，则N-1-2对3是整除以此类推 
*/
int consecutiveNumbersSum(int N){
    int nCnt = 0;
    int i =1;

    while(N > 0)
    {
        nCnt += (N % i == 0) ? 1 : 0;
        N -= i;
        i++;  
    }

    return nCnt;
}