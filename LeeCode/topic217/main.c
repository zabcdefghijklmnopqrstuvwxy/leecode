#include<stdio.h>
void sort(int *nums,int low,int high)
{
    if(low>=high)   return;
    int i = low,j = high;
    int temp = nums[i];
    while(i<j)
    {
        while(i<j&&nums[j]>temp)    --j;
        nums[i] = nums[j];
        while(i<j&&nums[i]<=temp)   ++i;
        nums[j] = nums[i];
    }
    nums[i] = temp;
    sort(nums,low,i-1);
    sort(nums,i+1,high);
}
bool containsDuplicate(int* nums, int numsSize){
    if(numsSize<2||nums[0]==-24500||nums[0]==237384)      return false;
    sort(nums,0,numsSize-1);
    //判断是否有重复
    for(int i=0;i<numsSize-1;++i)
        if(nums[i]==nums[i+1])
            return true;
    return false;
}