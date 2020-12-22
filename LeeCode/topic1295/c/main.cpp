int findNumbers(int* nums, int numsSize){
    int i = 0;
    int nCnt = 0;
    for(i = 0; i < numsSize; i++)
    {
        if((nums[i] >= 10 && nums[i] < 100) || (nums[i] >=1000 && nums[i] < 10000) || nums[i] == 100000)
        {
            nCnt++;
        }
    }

    return nCnt;
}