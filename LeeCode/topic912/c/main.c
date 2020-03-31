/**
 * @brief 冒泡排序，leecode测试超时
 */
int* sortArray(int* nums, int numsSize, int* returnSize){
    int i = 0, j = 0;
    int nTmp = 0;
    if(NULL == nums || numsSize <= 0)
    {
        return NULL;
    }

    for(i = 0; i < numsSize; i++)
    {
        for(j = 0; j < numsSize - i - 1; j++)
        {
            if(nums[j] > nums[j + 1])
            {
                nTmp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = nTmp;
            }
        }
    }

    *returnSize = numsSize;
    return nums;
}

/**
 * @brief 桶排序，leecode测试通过
 */
int* sortArray(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    if (numsSize < 2)
        return nums;
    int min = nums[0], max = nums[0], i = 0, j = 0;
    for (; i < numsSize; ++i){
        min = min < nums[i] ? min : nums[i];
        max = max > nums[i] ? max : nums[i];
    }
    int value = max - min + 1;
    int result[value];
    for (i = 0; i < value; ++i)
        result[i] = 0;
    for (i = 0; i < numsSize; ++i)
        ++result[nums[i] - min];
    for (i = 0; i < value; ++i)
        while (result[i]--)
            nums[j++] = i + min;
    return nums;
}