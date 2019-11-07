#include<stdio.h>

void reverse(int *nums, int start, int end)
{
    int temp;
    while (start < end) 
    {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

void rotate(int* nums, int numsSize, int k)
{
    if(NULL == nums || numsSize <= 0)
    {
        return;
    }
    
    k %= numsSize;
    reverse(nums, 0, numsSize - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, numsSize - 1); 
}
