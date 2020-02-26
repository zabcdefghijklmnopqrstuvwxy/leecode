#include<stdio.h>

/**
* @brief num = 4^n = (3+1)^n。多项式展开发现num 对3求余必然会是1。
* 4的幂转化成二进制是类似于100的结构
*/
bool isPowerOfFour(int num){
    if(num < 0 || num & (num-1))
    {
        return false;
    }

    return (num % 3 == 1);
}