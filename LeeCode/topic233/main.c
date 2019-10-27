#include<stdio.h>


/***
leecode test timeout
*/
#if 0
int countDigitOne(int n)
{
    int nCnt = 0;
    int nIndex = 0;
    int nCalc = 0;

    while(nIndex <= n)
    {
        nCalc = nIndex;

        while(nCalc)
        {
            if(nCalc % 10 == 1)
            {
                nCnt++;
            }
            nCalc = nCalc / 10;
        }

        nIndex++;
    }

    return nCnt;
}
#endif

#if 1
int countDigitOne(int n)
{
    int ones = 0;
    for (long long m = 1; m <= n; m *= 10)
        ones += (n/m + 8) / 10 * m + (n/m % 10 == 1) * (n%m + 1);
    return ones;
}
#endif

int main(void)
{
    int nDigit = 22;
    int nRet = 0;

    nRet = countDigitOne(nDigit);

    printf("intput count one is %d\t,count num is %d\n",nDigit,nRet);

    return 0;
}
