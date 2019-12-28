#include<stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDuplicates(int* nums, int numsSize, int* returnSize){
    int i = 0;
    int nCnt = 0;
    int *dup = (int*)malloc(numsSize*sizeof(int) + 4);
    memset(dup, 0, numsSize);

    if(nums == NULL ||numsSize < 2)
    {
        return NULL;
    }

    for(i = 0; i < numsSize; i++)
    {
        if(dup[nums[i]])
        {
            nums[nCnt++] = nums[i]; 
        }
        else
        {
            dup[nums[i]] = 1;
        }
    }

    free(dup);
    *returnSize = nCnt;
    return nums;
}

int main(void)
{
    int nums[] = {4, 3, 2, 7, 8, 2, 3, 1};
    int nCnt = 0;
    int *pDup = NULL;

    pDup = findDuplicates(nums, sizeof(nums)/sizeof(int), &nCnt);

    printf("print duplicat element:\t");
    for(int i = 0; i < nCnt; i++)
    {
        printf("%d\t",pDup[i]);
    }
    printf("\n");

    return 0;
}
