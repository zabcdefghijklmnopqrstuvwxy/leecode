#include<stdio.h>
#include<limits.h>

int maxSubArray(int* nums, int numsSize)
{
    int nMaxSum = 0;
    int nSum = 0;
    int i = 0;

    if(nums == NULL || numsSize < 1)
    {
        return 0;
    }

    nMaxSum = nums[0];

    for(i = 0; i < numsSize; i++)
    {
        if(nSum > 0)
        {
            nSum = nSum + nums[i];
        }
        else
        {
            nSum = nums[i];
        }
        
        if(nSum > nMaxSum)
        {
            nMaxSum = nSum;
        }
    }

    return nMaxSum;
}

int main(void)
{
    int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
//    int nums[] = {-2, -1, 4, 2, -5, 6, -8};
    int nMaxSubSum = 0;
    int i = 0;

    nMaxSubSum = maxSubArray(nums, sizeof(nums)/sizeof(int));

    printf("sub array is\t");
    for(i = 0; i < sizeof(nums)/sizeof(int); i++)
    {
        printf("%d\t",nums[i]);
    }

    printf("\nmax sub sum is %d\n",nMaxSubSum);

    return 0;
}
