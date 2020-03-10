#include<stdio.h>

/**
* @brief 假设N位为从高到低为 n,n-1,n-2, ... 1, 0,0为个位，1为十位依次类推,
* 先比较低1，0比较，如果符合条件则进一步比较2，1否则自减直至1，0符合。往复
* 循环，最终得到结果即可
*/
int monotoneIncreasingDigits(int N){
    int nNum = N;
    int nCoef = 1;
    while(nNum / nCoef)
    {
        int n = nNum / nCoef % 100;   //取两位
        nCoef = nCoef*10; 

        while(n/10 > n%10)  //如果高位大于低位则自减直至高位小于低位
        {
            nNum = nNum / nCoef * nCoef - 1;
            n = nNum % 100;
        }
    }
   
    return nNum;
}