#include<stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElements(int* nums, int numsSize, int* returnSize){
    int *nNextMaxArr = (int*)malloc(numsSize*sizeof(int));
    int nSlow = 0;
    int nFast = 0;

    if(!nums)
    {
        *returnSize = 0;
        return nums;
    }

    while(nSlow < numsSize)
    {
        nFast = (nSlow + 1) % numsSize;

        while(nFast != nSlow)
        {
            if(nums[nFast] > nums[nSlow])
            {
                nNextMaxArr[nSlow] = nums[nFast];
                break;
            }
            nFast = (nFast + 1)%numsSize;
        }

        if(nFast == nSlow)
        {
            nNextMaxArr[nSlow] = -1;
        }
        nSlow++;
    }

    *returnSize = numsSize;
    return nNextMaxArr;
}

int main(void)
{
    int nums[] = {1, 2, 3, 4, 3};
    int nCnt = 0;
    int *pNextMax = NULL;
    int i = 0;

    pNextMax = nextGreaterElements(nums, sizeof(nums)/sizeof(int), &nCnt);
    
    printf("input nums is\n");
    for(i = 0; i < sizeof(nums)/sizeof(int); i++)
    {
        printf("%d\t",nums[i]);
    }
    printf("\n");

    printf("next max value is\n");
    for(i = 0; i < nCnt; i++)
    {
        printf("%d\t",pNextMax[i]);
    }
    printf("\n");

    return 0;
}
