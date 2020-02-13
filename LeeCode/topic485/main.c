int findMaxConsecutiveOnes(int* nums, int numsSize){
    if(NULL == nums)
    {
        return 0;
    }
    int nCnt = 0;
    int nMax = 0;

    for(int i = 0; i < numsSize; i++)
    {
        if(1 == nums[i])
        {
            nCnt++;
            if(nCnt > nMax)
            {
                nMax = nCnt;
            }
        }
        else
        {
            nCnt = 0;
        }
    }

    return nMax;
}