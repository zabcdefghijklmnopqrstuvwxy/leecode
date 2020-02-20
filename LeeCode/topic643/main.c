#include<stdio.h>

double findMaxAverage(int* nums, int numsSize, int k){
    int nLeft = 0;
    int nRight = k;
    double dSum = 0;
    double dMax = 0;

    if(NULL == nums || numsSize <= 0)
    {
        return 0.0;
    }

    for(int i = nLeft; i < nRight; i++)
    {
        dSum = dSum + nums[i];
    }

    dMax = dSum;
    
    while(nRight < numsSize)
    {
        dSum = dSum + nums[nRight];
        dSum = dSum - nums[nLeft];
        nLeft++;
        nRight++;

        if(dSum > dMax)
        {
            dMax = dSum;
        }
    }

    return dMax/k;
}