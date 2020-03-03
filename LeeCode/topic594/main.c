#include<stdio.h>

/**
* @brief 先排序后采用双指针获取最长 
*/
int findLHS(int* nums, int numsSize){
    int i = 0, j = 0;
    int nTmp = 0;
    int nMaxLen = 0;
    int nBegin = 0;

    if(numsSize <= 1)
    {
        return 0;
    }

    for(i = 0; i < numsSize; i++)
    {
        for(j = 0; j < numsSize - 1 - i;j++)
        {
            if(nums[j] > nums[j+1])
            {
                nTmp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = nTmp; 
            }
        }
    }

    for(int nEnd = 0;nEnd < numsSize;nEnd++)
    {
        while(nums[nEnd] - nums[nBegin] > 1)
        {
            nBegin++;
        }
        if(nums[nEnd] - nums[nBegin] == 1)
        {
            nMaxLen = nEnd - nBegin + 1 > nMaxLen ? nEnd - nBegin + 1 : nMaxLen;
        }
    }
    return nMaxLen;
}