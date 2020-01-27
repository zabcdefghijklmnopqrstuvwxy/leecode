#include<stdio.h>

int singleNumber(int* nums, int numsSize)
{
    int one = 0, two = 0;
    int i = 0;

    for(i = 0; i < numsSize; i++)
    {
        one = one ^ nums[i] & ~two;
        two = two ^ nums[i] & ~one;
    }

    return one;
}

int main(void)
{
	int nums[] = {2, 2, 3, 2};
	int i = 0;
	int nSingle = 0;
	
	for(i = 0; i < sizeof(nums)/sizeof(int); i++)
	{
		printf("%d\t",nums[i]);
	}
	printf("\n");
	
	nSingle = singleNumber(nums, sizeof(nums)/sizeof(int));
	
	printf("single nums is %d\n",nSingle);
	
	return 0;
}
