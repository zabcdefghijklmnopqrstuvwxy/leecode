#include<stdio.h>


/*
* tesk ok leecode but timeout 
*/
#if 0
int climbStairs(int n)
{
    if(n == 1 || n == 2)
    {
        return n;
    }
    
    if(n == 0)
    {
        return 0;
    }

    return climbStairs(n-1) + climbStairs(n-2); 
}
#endif

/**
f(n) = f(n-1) + f(n-2)
c = f(n)
*/
int climbStairs(int n)
{
    int a = 0, b = 1, c = 0;
    while (n--)
    {
        c = a + b;
        a = b;
        b = c;
    }

    return c;
}

int main(void)
{
    int nClimb = 2;
    int nRet = 0;

    nRet = climbStairs(nClimb);

    printf("total climb stairs is %d,result is %d\n",nClimb,nRet);

    return 0;
}
