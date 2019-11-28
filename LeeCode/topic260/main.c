#include<stdio.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize)
{
    int nXor = 0;
    int i = 0;
    int a = 0;
    int b = 0;
    int *result = (int*)malloc(2*sizeof(int));

    for(i = 0; i < numsSize; i++)
    {
        nXor = nXor ^ nums[i];
    }

    nXor = nXor & (-nXor);

    for(i = 0; i < numsSize; i++)
    {
        if((nums[i] & nXor) == nXor)
        {
              a = a ^ nums[i];  
        }
        else
        {
              b = b ^ nums[i];  
        }
    }

    result[0] = a;
    result[1] = b;
    
    *returnSize = 2;
    
    return result;
}

int main(void)
{
    int nums[] = {1, 2, 3, 2, 5, 1};
    int *pdata = NULL;
    int nCnt = 0;
    int i = 0;
    pdata = singleNumber(nums, sizeof(nums)/sizeof(int), &nCnt);
    
    for(i = 0; i < nCnt; i++)
    {
        printf("%d\t",pdata[i]);
    }

    printf("\n");

    return 0;
}
