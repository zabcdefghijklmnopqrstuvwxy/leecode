#include<stdio.h>

/**
* @brief 常规解法，穷举解法
*/
int addDigits(int num){
    int nSum = 0;
    int nRes = 0;
    while(num)
    {
        nRes = nRes + (num % 10);
        num = num / 10;
    }

    while(nRes >= 10)
    {
        nSum = nRes;
        nRes = 0;
        while(nSum)
        {
            nRes = nRes + (nSum % 10);
            nSum = nSum / 10;
        }
    }

    return nRes;   
}

/**
* @brief x*100 + y*10 + z = x*99 + y*9 + x + y + z,对9求余为0，剩下的x+y+z
*/
int addDigits(int num){
	return (num - 1) % 9 + 1;
}