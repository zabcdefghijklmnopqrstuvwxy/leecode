#include<stdio.h>
#include<stdbool.h>
#include<limits.h>

bool containsDuplicate(int* nums, int numsSize)
{
    int nMin = INT_MAX,nMax = INT_MIN;
    int i = 0;
    unsigned long long ulSize = 0;
    
    if(nums == NULL || numsSize == 0)
    {
        return false;
    }

    for(i = 0 ; i < numsSize; i++)
    {
        if(nums[i] < nMin)
        {
            nMin = nums[i];
        }

        if(nums[i] > nMax)
        {
            nMax = nums[i];
        }
    }

    if((nMax - nMin + 1) < numsSize)
    {
        ulSize = numsSize;
    }
    else
    {
        ulSize = nMax - nMin + 1;
    }

    int *hash = (int*)malloc(ulSize*sizeof(int));
    memset(hash,0,ulSize);

    for(i = 0 ; i < numsSize; i++)
    {
        if(0 == hash[nums[i]])
        {
            hash[nums[i]] = 1;
        }
        else
        {
            break;
        }
    }

    if(i >= numsSize)
    {
        return false;
    }

    return true;
}

int main(void)
{
    int nums[] = {1};
    int i = 0;

    printf("nums element is\t");
    for(i = 0; i < sizeof(nums)/sizeof(int); i++)
    {
        printf("%d\t",nums[i]);
    }
    
    if(containsDuplicate(nums, sizeof(nums)/sizeof(int)))
    {
         printf("nums has duplicate element\n");
    }
    else
    {
         printf("nums hasn't duplicate element\n");
    }

    return 0;
}
