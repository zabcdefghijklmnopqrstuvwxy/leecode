#include<stdio.h>


/*
* @brief 使用额外空间开销哈希表判重，时间复杂度为O(n)，空间复杂度为O(n)，
* 该方法不符合leecode空间复杂度要求。只能作为参考。
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

/*
* @brief 使用自身数值作为索引，将相应索引数值取反，如果为正则说明
* 重复元素。时间复杂度为O(n)，空间复杂度为O(1)，符合leecode要求。
*/ 
int* findDuplicates(int* nums, int numsSize, int* returnSize){
    if(numsSize < 2)
    {
        *returnSize = 0;
        return NULL;
    }

    int *dup = (int*)malloc(sizeof(int)*numsSize);
    int i = 0;
    int nIndex = 0;
    for(i = 0 ; i < numsSize; i++)
    {      
        nums[abs(nums[i]) - 1] = -1*nums[abs(nums[i]) - 1];
        if(nums[abs(nums[i]) - 1] > 0)
        {
            dup[nIndex++] = abs(nums[i]);
        }
    }

    *returnSize = nIndex;
    return dup;
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
