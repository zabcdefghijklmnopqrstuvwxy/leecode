#include<stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
*/
int* majorityElement(int* nums, int numsSize, int* returnSize)
{
    int nVoteA = 1;
    int nCntA = 0;
    int nVoteB = 2;
    int nCntB = 0;
    int i = 0;

    if(nums == NULL || numsSize == 0)
    {
        *returnSize = 0;
        return nums;
    }
    
    nVoteA = nums[0];

    for(i = 1; i < numsSize; i++)
    {
        if(nVoteA != nums[i])
        {
            nVoteB = nums[i];
            break;
        }
    }

    for(i = 0; i < numsSize; i++)
    {
        if(nums[i] == nVoteA && nums[i] != nVoteB)
        {
            nCntA++;
        }
        else if(nums[i] != nVoteA && nums[i] == nVoteB)
        {
            nCntB++;        
        }
        else if(nums[i] != nVoteA && nums[i] != nVoteB)
        {
            if(nCntA > 0 && nCntB > 0)
            {
                nCntA--;
                nCntB--;
            }
            else if(nCntA == 0 && nCntB > 0)
            {
                nVoteA = nums[i];
                nCntA++;
            }
            else if(nCntA > 0 && nCntB == 0)
            {
                nVoteB = nums[i];
                nCntB++;
            }
            else
            {
                nVoteA = nums[i];
                nCntA++;
            }
        }
        else
        {
            
        }
    }
    
    nCntA = 0;
    nCntB = 0;

    for(i = 0; i < numsSize; i++)
    {
        if(nVoteA != nVoteB)
        {
            if(nums[i] == nVoteA)
            {
                nCntA++;    
            }

            if(nums[i] == nVoteB)
            {
                nCntB++;    
            }
        }
        else
        {
            if(nums[i] == nVoteA)
            {
                nCntA++;    
            }
        }
    }

    i = 0;

    if(nCntA >= (numsSize/3 + 1))
    {
        nums[0] = nVoteA;
        ++i;
    }

    if(nCntB >= (numsSize/3 + 1))
    {
        if(i)
        {
            nums[1] = nVoteB;
        }
        else
        {
            nums[0] = nVoteB;
        }
        ++i;
    }
    
    *returnSize = i;
    return nums;
}

int main(void)
{
    int nums[] = {1, 2, 1, 1, 1, 3, 3, 4, 3, 3, 3, 4, 4, 4};
//    int nums[] = {2, 2, 2};
    int nCnt = 0;
    int *pdata = NULL;
    int i = 0;

    printf("input element is\t");
    for(i = 0; i < sizeof(nums)/sizeof(int); i++)
    {
        printf("%d\t",nums[i]);
    }

    pdata = majorityElement(nums, sizeof(nums)/sizeof(int), &nCnt);

    printf("major cnt is %d\telement is\t",nCnt);
    if(pdata)
    {
        for(i = 0; i < nCnt; i++)
        {
            printf("%d\t",pdata[i]);
        }
    }

    return 0;
}
