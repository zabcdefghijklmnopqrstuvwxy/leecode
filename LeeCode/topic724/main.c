#include<stdio.h>

/**
* @brief 左求和*2+中心索引值 = 总和
*/
int pivotIndex(int* nums, int numsSize){
    int nSum = 0;
    int n = 0;

    for(int i = 0; i < numsSize; i++)
    {
        nSum = nSum + nums[i];
    }

    for(int i = 0; i < numsSize; i++)
    {
        if(n*2 == nSum - nums[i])
        {
            return i;
        }
        n = n + nums[i];
    }

    return -1;
}