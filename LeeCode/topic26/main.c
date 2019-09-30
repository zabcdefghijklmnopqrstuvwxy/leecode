#include<stdio.h>
/**
* @brief two point,fast point and slow point 
*/
int removeDuplicates(int* nums, int numsSize)
{
    int nFast = 1;
    int nSlow = 0;
    int nTmp = 0;

    if(numsSize == 0 || nums == NULL)
    {
    	return 0;
    }

    if(numsSize < 2)
    {
        return 1;
    }

    while(nFast < numsSize)
    {
        if(nums[nFast] == nums[nSlow]) 
        {
            nFast++;            
        }
        else
        {
            nSlow++;
            nTmp = nums[nSlow];
            nums[nSlow] = nums[nFast];
            nums[nFast] = nTmp;
            nFast++;
        }
    }

    return (nSlow + 1);
}

int main(void)
{
    int nums[] = {0,0,1,1,1,2,2,3,3,4};
    int nRet = 0;
    int i = 0;

    nRet = removeDuplicates(nums,sizeof(nums)/sizeof(int));

    printf("result is %d\n",nRet);

    for(i = 0; i < sizeof(nums)/sizeof(int); i++)
    {
        printf("%d\t",nums[i]);
    }

    printf("\n");
    
    return 0;
}
