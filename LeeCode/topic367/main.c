#include<stdio.h>

/**
* @brief 数学法，1 + 3 + 5.... + 2*n+1 = n*n
*/
bool isPerfectSquare(int num){
    int i = 0;
    int sum = 0;
    while(sum <= num)
    {
        sum = 2*i + 1;
        num = num - sum;
        i++;
    }

    return num == 0;  
}

/**
* @brief 牛顿迭代法
*/
bool isPerfectSquare(int num){
    if(1 == num)
	{eturn true;
    int i = num / 2;
        while((double)i * i > num){
            i = (i + num / i) / 2;
        }
        return i * i == num;
}