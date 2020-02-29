#include<stdio.h>

/**
* @brief 从左到右循环，记录最大值为 max，若 nums[i] < max, 则表明位置 i 需要调整, 循环结束，
* 记录需要调整的最大位置 i 为 high; 同理，从右到左循环，记录最小值为 min, 若 nums[i] > min, 
* 则表明位置 i 需要调整，循环结束，记录需要调整的最小位置 i 为 low.
*/
int findUnsortedSubarray(int* nums, int numsSize){
    if(numsSize <= 1)
    {
       return 0;
    }

    int nHigh = 0, nLow = 0, nMax = nums[0],nMin = nums[numsSize - 1];

    for(int i = 1; i < numsSize; i++)
    {
        nMax = nums[i] > nMax ? nums[i] : nMax;
        nMin = nums[numsSize - i - 1] < nMin ? nums[numsSize -i - 1] : nMin;
        if(nums[i] < nMax)
        {
            nHigh = i;
        }

        if(nums[numsSize - i - 1] > nMin)
        {
            nLow = numsSize - i - 1;
        }
    }

    return nHigh > nLow ? nHigh - nLow + 1 : 0;
}