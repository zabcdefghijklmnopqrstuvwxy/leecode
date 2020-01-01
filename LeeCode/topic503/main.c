#include<stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 
#if 0
/**
* @brief 暴力破解法
*/
int* nextGreaterElements(int* nums, int numsSize, int* returnSize){
    int *nNextMaxArr = (int*)malloc(numsSize*sizeof(int));
    int nSlow = 0;
    int nFast = 0;

    if(!nums)
    {
        *returnSize = 0;
        return nums;
    }

    while(nSlow < numsSize)
    {
        nFast = (nSlow + 1) % numsSize;

        while(nFast != nSlow)
        {
            if(nums[nFast] > nums[nSlow])
            {
                nNextMaxArr[nSlow] = nums[nFast];
                break;
            }
            nFast = (nFast + 1)%numsSize;
        }

        if(nFast == nSlow)
        {
            nNextMaxArr[nSlow] = -1;
        }
        nSlow++;
    }

    *returnSize = numsSize;
    return nNextMaxArr;
}
#endif

/**
* @brief 单调栈
*/
int* nextGreaterElements(int* nums, int numsSize, int* returnSize){

 int *ans = (int *)calloc(1, sizeof(int) * numsSize);
    int *stack = (int *)calloc(1, sizeof(int) * numsSize * 2);
    int top = 0;
    int topIndex, baseIndex;
    int i;
    
    memset(ans, -1, sizeof(int) * numsSize);

    for (i = 0; i < numsSize; i++) 
    {
        while (top != 0)
        {
            topIndex = stack[top - 1];
            /* 维持栈单调不增，这里就是栈单调性的控制点 */
            if (nums[topIndex] >= nums[i]) {
                break;
            }

            /* 如果出现比当前大的数，则出栈更新结果 */
            ans[topIndex] = nums[i];
            top--;
        }
        stack[top++] = i;
    }
    
    if (top != 0) {
        baseIndex = stack[0];
        for (i = 0; i <= baseIndex; i++) {
            while (top != 0) {
                topIndex = stack[top - 1];
                /* 维持栈单调不增，这里就是栈单调性的控制点 */
                if (nums[topIndex] >= nums[i]) {
                    break;
                }

                /* 如果出现比当前大的数，则出栈更新结果 */
                ans[topIndex] = nums[i];
                top--;
            }
            stack[top++] = i;            
        }
    }

    *returnSize = numsSize;
    return ans;
}

int main(void)
{
    int nums[] = {1, 2, 3, 4, 3};
    int nCnt = 0;
    int *pNextMax = NULL;
    int i = 0;

    pNextMax = nextGreaterElements(nums, sizeof(nums)/sizeof(int), &nCnt);
    
    printf("input nums is\n");
    for(i = 0; i < sizeof(nums)/sizeof(int); i++)
    {
        printf("%d\t",nums[i]);
    }
    printf("\n");

    printf("next max value is\n");
    for(i = 0; i < nCnt; i++)
    {
        printf("%d\t",pNextMax[i]);
    }
    printf("\n");

    return 0;
}
