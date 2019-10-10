#include<stdio.h>
#include<limits.h>

int firstMissingPositive(int* nums, int numsSize)
{
    int *nHash = (int*)malloc(numsSize*sizeof(int));
    int i = 0;
    int nFlag = 0;
    memset(nHash,0,sizeof(int)*numsSize);

    for(i = 0; i < numsSize; i++)
    {
        if(nums[i] == 1)
        {
            nFlag = 1;
        }

        if(nums[i] <= 0 || nums[i] > numsSize)
        {
            nums[i] = 1;
        }
        
        nHash[nums[i] - 1] = 1;
    }

    if(0 == nFlag)
    {
        return 1;
    }

    for(i = 0; i < numsSize; i++)
    {
        if(0 == nHash[i])
        {
            break;
        }
    }
    
    return i + 1;
}

int main(void)
{
    int nRet = 0;
//    int test[] = {3,4,-1,1}; 
//    int test[] = {1,2,0};
//    int test[] = {2,1};
    int test[] = {7,8,9,11,12}; 
    int i = 0;

    nRet = firstMissingPositive(test, sizeof(test)/sizeof(int));

    for(i = 0; i < sizeof(test)/sizeof(int); i++)
    {
        printf("%d\t",test[i]);
    }

    printf("\n min interger is %d\n",nRet);

    return 0;
}
