#include<stdio.h>

/**
* @brief 折半
*/
double myPow(double x, int n){
    double dRes = 1.0;

    for(int i = n; i != 0; i /=2)
    {
        if(i % 2 != 0)
        {
            dRes = dRes*x;
        }
        x*=x;
    }
    
    return n > 0 ? dRes : 1/dRes;
}
