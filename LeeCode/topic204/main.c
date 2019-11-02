#include<stdio.h>

int countPrimes(int n)
{
    int nCnt = 0;
    int i = 2;
    int j = 0;
    int nNum = 1;
    char *cIndex = (char*)malloc(n);
    memset(cIndex, 1, n);

    if(n <= 1 && n >= 0)
    {
        return 0;
    }

    for(i = 2; i < n; i++)
    {
        if(cIndex[i])
        {
            nNum = 1;
            for(j = 2; j < n; j = i*nNum)
            {
                nNum++;
                if(j > i)
                {
                    cIndex[j] = 0;
                }
            }
        }
    }

    for(i = 2; i < n; i++)
    {
        if(cIndex[i])
        {
            nCnt++;
        }
    }

    return nCnt;
}

int main(void)
{
    int nPrimes = 10;
    int nCnt = 0;

    nCnt = countPrimes(nPrimes);

    printf("input primes is %d\tcount num is %d\n",nPrimes,nCnt);

    return 0;
}
