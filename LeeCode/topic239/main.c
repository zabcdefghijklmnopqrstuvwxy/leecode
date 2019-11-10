#include<stdio.h>
#include<limits.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize)
{
    int *max = (int*)malloc(sizeof(int)*(numsSize - k + 1));
    int nSlow = 0;
    int nFast = 0;
    int nMax = INT_MIN;
    int nCnt = 0;
    int nNum = 0;

    if(nums == NULL || numsSize < 1)
    {
        return NULL;
    }

    while(nFast <= numsSize)
    {
        if(nNum == k)
        {
            nNum = 0;
            max[nCnt++] = nMax;
            nMax = INT_MIN;
            nSlow++;
            nFast = nSlow;
        }
        else
        {
            if(nums[nFast] > nMax)
            {
                nMax = nums[nFast];
            }
            nFast++;
            nNum++;
        }
    }
    
    *returnSize = nCnt;
    return max;
}

int main(void)
{
    int *pmax = NULL;
    //int nums[] = {-1, 2, 3, -1, 4, 2, 3, 6, 2, 1};
    int nums[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    int nSize = 0;
    int i = 0;

    pmax = maxSlidingWindow(nums, sizeof(nums)/sizeof(int), k, &nSize);
    
    printf("input nums is ");
    for(i = 0; i < sizeof(nums)/sizeof(int); i++)
    {
        printf("%d\t",nums[i]);
    }

    printf("\nmax sliding window value is\t");
    for(i = 0; i < nSize; i++)
    {
        printf("%d\t",pmax[i]);
    }

    return 0;
}
