#include<stdio.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int num, int* returnSize)
{
    int *ans = (int*)malloc((num+1)*sizeof(int));
    ans[0] = 0;
    
    for (int i = 1; i <= num; ++i)
    {
        ans[i] = ans[i >> 1] + (i & 1); // x / 2 is x >> 1 and x % 2 is x & 1
    }
    
    *returnSize = num + 1; 

    return ans;
}