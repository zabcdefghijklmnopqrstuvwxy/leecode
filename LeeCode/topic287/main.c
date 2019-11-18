#include<stdio.h>

/**
* @brief 线性序列1-N中存在重复元素时则意味着必定存在
* 环形结构，找到入口点即意味着找到了重复元素
*/

int findDuplicate(int* nums, int numsSize){
    int tortoise = nums[0];
    int hare = nums[0];
    do{
        tortoise = nums[tortoise];
        hare = nums[nums[hare]];
    }while (tortoise != hare);
    
    int ptr1 = nums[0];
    int ptr2 = tortoise;
    while (ptr1 != ptr2) {
        ptr1 = nums[ptr1];
        ptr2 = nums[ptr2];
    }

    return ptr1;
}