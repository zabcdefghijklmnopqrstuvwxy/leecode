#include<stdio.h>

int removeElement(int* nums, int numsSize, int val)
{
    int i = 0,j = 0;

    if(nums == NULL || numsSize <= 0)
    {
    	return 0;
    }

    for(j = 0; j < numsSize; j++)
    {
    	if(nums[j] != val)
	{
 	    nums[i] = nums[j];
	    i++;
	}
    }	    

    return i;
}

int main(void)
{
    int nums[] = {2, 3, 3, 2};
    int nTarget = 2;
    int i = 0;
    int nNum = 0;

    printf("remove element before\n");

    for(i = 0; i < sizeof(nums)/sizeof(int); i++)
    {
    	printf("%d\t",nums[i]);
    }


    printf("remove element after\n");

    nNum = removeElement(nums, sizeof(nums)/sizeof(int), nTarget);

    for(i = 0; i < sizeof(nums)/sizeof(int); i++)
    {
    	printf("%d\t",nums[i]);
    }

    printf("\nresidue element num is %d\n",nNum);
    return 0;
}

