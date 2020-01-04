#include<stdio.h>

/**
* @brief 从[1,2,3...，K]集合查找到最后一个满足条件的即可
*/
int arrangeCoins(int n){
    int nStair = 0;

    while(n > nStair)
    {
        nStair++;
        n = n - nStair;
    }

    return nStair;
}

/**
* @brief 数学公式法，递差数列
*/
int arrangeCoins(int n)
	    return (-1+sqrt(1+8*(long)n))/2;
}