int singleNonDuplicate(int* nums, int numsSize){
    int nValue = 0;
    int i = 0;
    for(i = 0; i < numsSize; i++)
    {
        nValue = nValue ^ nums[i];
    }

    return nValue;
}