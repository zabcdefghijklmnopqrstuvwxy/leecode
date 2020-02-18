#include<stdio.h>

/**
* @brief 第一种解法，两次遍历，一次遍历获取0,1,2的频数。二次遍历将0,1,2的频数直接赋值。
*/
void sortColors(int* nums, int numsSize){
    int nZeroCnt = 0;
    int nOneCnt = 0;
    int nTwoCnt = 0;

    for(int i = 0; i < numsSize; i++)
    {
        if(0 == nums[i])
        {
            nZeroCnt++;
        }

        if(1 == nums[i])
        {
            nOneCnt++;
        }

        if(2 == nums[i])
        {
            nTwoCnt++;
        }
    }

    for(int i = 0; i < numsSize; i++)
    {
        if(nZeroCnt)
        {
            nZeroCnt--;
            nums[i] = 0;
        }
        else
        {
            if(nOneCnt)
            {
                nOneCnt--;
                nums[i] = 1;
            }
            else
            {
                nums[i] = 2;
            }
        }
    }
}

/**
* @brief 第二种解法，荷兰棋解法，三个指针，分别是0号指针，2指针，以及当前指针
*/
void sortColors(int* nums, int numsSize){
    int left = 0;
    int right = numsSize - 1;
    int i = 0;
    int temp=0;
    while(i<=right) 
    {
        if(nums[i]==1) 
        {
            i++;
        }
        else if(nums[i]==0) 
        {
            if(left==i) 
            {
                left++;
                i++;
            }
            else 
            {
                temp = nums[i];
                nums[i] = nums[left];
                nums[left] = temp;
                left++;
            }
        }
        else if(nums[i]==2) 
        {
            temp = nums[i];
            nums[i] = nums[right];
            nums[right] = temp;
            right--;
        }
    }
}
