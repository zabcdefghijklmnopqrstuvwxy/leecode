
int findPeakElement(int* nums, int numsSize){
    int nLeft = 0;
    int nRight = numsSize - 1;
    int nMid = 0;
    if(numsSize==1)
    {
        return 0;
    }

    while(nLeft <= nRight)
    {
        nMid = (nLeft + nRight) / 2;
        if((nMid == 0) && (nums[1] < nums[nMid]))
        {
            return nMid;
        }
        else if((nMid == numsSize - 1) && (nums[nMid] > nums[nMid - 1]))
        {
            return nMid;
        }
        else if(nums[nMid] > nums[nMid + 1] && nums[nMid] > nums[nMid - 1])
        {
            return nMid;
        }  
        else if(nums[nMid] < nums[nMid + 1])
        {
            nLeft = nMid + 1;
        }
        else
        {
            nRight = nMid - 1;
        }
    }

    return 1;
}