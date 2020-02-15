#include<stdio.h>
    
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void search(int *nums, int low, int high, int target, int *result) {
    if (low>high)
    { 
        return;
    }
    int mid = (low+high)/2;
    if (nums[mid] == target) 
    {
        if (result[0] == -1 || mid <= result[0]) {
            result[0] = mid;
        }
        if (mid >= result[1]) {
            result[1] = mid;
        }
        search(nums, low, mid-1, target, result);
        search(nums, mid+1, high, target, result);
    } else if (nums[mid] > target) {
        search(nums, low, mid-1, target, result);
    } else {
        search(nums, mid+1, high, target, result);
    }
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    int *result = (int*)malloc(2*sizeof(int));
    result[0] = -1;
    result[1] = -1;
    search(nums, 0, numsSize - 1, target, result);
    *returnSize = 2;
    return result;
}


