#include<stdio.h>

/**
* @brief 数学公式法，1 + 3 + 5 + 7 + ... + 2*n - 1 = n*n
*/
int mySqrt(int x){
    int n = 0;
    long long nSum = 0;
    while(nSum < x)
    {
        nSum = nSum + (2*n + 1); 
        n++;
    }

    if(nSum == x)
    {
        return n;
    }

    return n - 1;
}

