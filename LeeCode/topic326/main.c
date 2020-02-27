#include<stdio.h>

/**
* @brief取个巧，C语言中的int的有最大数限制，3的幂次方最大数为1162261467。利用最大幂数求余即可。
*/
bool isPowerOfThree(int n){
    return n > 0 && 1162261467 % n == 0;
}