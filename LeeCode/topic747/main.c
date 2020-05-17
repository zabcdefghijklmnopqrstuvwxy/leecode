int dominantIndex(int* nums, int numsSize){
    int nMaxNum = 0;
    int nGreatNum = 0;
    int nIndex = 0;
    int i = 0;

    if(numsSize <= 1)
    {
        return 0;
    }

    for(i = 0; i < numsSize; i++)
    {
        if(nums[i] > nMaxNum)
        {
            nGreatNum = nMaxNum;
            nMaxNum = nums[i];
            nIndex = i;
        }
        else
        {
            if(nums[i] > nGreatNum)
            {
                nGreatNum = nums[i];
            }
        }
    }

    if(nGreatNum*2 <= nMaxNum)
    {
        return nIndex;
    }

    return -1;
}