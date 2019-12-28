#include<stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
    int i = 0;
    int nCnt = 0;
    int *miss = (int*)malloc(numsSize*sizeof(int));

    if(nums == NULL)
    {
        *returnSize = 0;
        return NULL;
    }

    for(i = 0; i < numsSize; i++)
    {
        if(nums[abs(nums[i]) - 1] > 0)
        {
            nums[abs(nums[i]) - 1] = (-1)*nums[abs(nums[i]) - 1];
        }
    }

    for(i = 0 ; i < numsSize; i++)
    {
        if(nums[i] > 0)
        {
            miss[nCnt++] = i + 1;
        }
    }

    *returnSize = nCnt;
    return miss;
}
