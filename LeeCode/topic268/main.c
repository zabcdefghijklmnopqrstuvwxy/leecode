#include<stdio.h>

/**
* @brief 可以利用高斯求和公式 (an1 + ann)*n/2，将其减去传入数组之和即
* 得到缺失的数字。
*/

int missingNumber(int* nums, int numsSize){
    long long lSum = 0;
    long long lGausSum = 0;
    int i = 0;

    if(nums == NULL || numsSize < 1)
    {
        return -1;
    }

    for(i = 0; i < numsSize; i++)
    {
        lSum = nums[i] + lSum;
    }

    lGausSum = (0 + numsSize)*(numsSize + 1)/2;

    return lGausSum - lSum;
}