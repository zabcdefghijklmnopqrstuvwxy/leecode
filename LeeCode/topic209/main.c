#include<stdio.h>

int minSubArrayLen(int s, int* nums, int numsSize)
{
    int nRight = 0;
    int nLeft = 0;
    int i = 0;
    int nMinLen = numsSize + 1;
    int nSum = 0;

    if(nums == NULL || numsSize  < 1)
    {
        return 0;
    }

    while(nLeft < numsSize)
    {
        if(nRight < numsSize && nSum < s)
        {
            nSum = nSum + nums[nRight++];
        }
        else
        {
            nSum = nSum - nums[nLeft++];
        }
        if(nSum >= s)
        {
            nMinLen = (nRight - nLeft) < nMinLen ? (nRight - nLeft) : nMinLen;
        }
    }

    if(nMinLen == numsSize + 1)
    {
        return 0;
    }

    return nMinLen;
}

int main(void)
{
//    int nums[] = {2, 3, 1, 2, 4, 3};
//    int nums[] = {1, 2, 3, 4, 5};
    int nums[] = {5, 1, 3, 5, 10, 7, 4, 9, 2, 8};
//    int nums[] = {1, 1};
    int s = 15;
    int nMinLen = 0;
    int i = 0;

    nMinLen = minSubArrayLen(s, nums, sizeof(nums)/sizeof(int));
    
    printf("total array is\t");
    for(i = 0; i < sizeof(nums)/sizeof(int); i++)
    {
        printf("%d\t",nums[i]);
    }

    printf("\nmin sub len is %d\n",nMinLen);

    return 0;
}
