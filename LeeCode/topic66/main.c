#include<stdio.h>

/**
 * @brief 进位加法
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int *sum = (int*)malloc((digitsSize + 1)*sizeof(int));
    int nOv = 1;

    if(NULL == digits || digitsSize <= 0)
    {
        *returnSize = 0;
        return NULL;
    }

    for(int i = digitsSize - 1; i >= 0; i--)
    {
        if(nOv)
        {
             if(digits[i] + 1 >= 10)
             {
                nOv = 1;
                sum[i + 1]= 0;
             }
             else
             {
                nOv = 0;
                sum[i + 1] = digits[i] + 1;
             }
        }
        else
        {
            sum[i + 1] = digits[i];
        }
    }

    if(nOv)
    {
        *returnSize = digitsSize + 1;
        sum[0] = 1;
        return sum;
    }
    
    *returnSize = digitsSize;
    return &sum[1];
}