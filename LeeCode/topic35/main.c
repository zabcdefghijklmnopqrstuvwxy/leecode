int searchInsert(int* nums, int numsSize, int target){
    int nLeft = 0;
    int nRight = numsSize - 1;
    int nMid = 0;
    int nIndex = 0;    

    if(target <= nums[0])
    {
        return 0;
    }
    
    if(target > nums[nRight])
    {
        return nRight + 1;
    }

    while(nLeft < (nRight - 1))
    {
        nMid = (nLeft + nRight) / 2;
        if(target == nums[nMid])
        {
            return nMid;
        }
        else if(target < nums[nMid])
        {
            nRight = nMid;
        }
        else
        {
            nLeft = nMid;
        }
    }

    return nLeft + 1; 
}