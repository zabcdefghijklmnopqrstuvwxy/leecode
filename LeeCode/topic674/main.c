#include<stdio.h>

int findLengthOfLCIS(int* nums, int numsSize){
    int nMax = 1;
    int nCnt = 1;

    if(NULL == nums || numsSize <= 0)
    {
        return 0;
    }

    for(int i = 0; i < (numsSize - 1); i++)
    {
        if(nums[i+1] > nums[i])
        {
            nCnt++;

            if(nCnt > nMax)
            {
                nMax = nCnt;
            }
        }
        else
        {
            nCnt = 1;
        }
    }

    return nMax;
}