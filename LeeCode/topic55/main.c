#include<stdio.h>


bool canJump(int* nums, int numsSize){
	 int nFast = numsSize - 1;
    int nSlow = numsSize - 1;
    bool nRet = false;

    if(numsSize <= 1)
    {
        return true;
    }

    while(nFast > 0)
    {
        nFast--;
        if(nums[nFast] >= (nSlow - nFast))
        {
            nSlow = nFast;
            nRet = true;
        }
        else
        {
            nRet = false;
        }
    }

    return nRet;
}