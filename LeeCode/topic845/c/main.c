#define         max(x,y)        x>y?x:y


int longestMountain(int *arr, int arrSize)
{
    if(arrSize < 3)
    {
        return 0;
    }

    int nStart = -1;
    int nMaxLen = 0;

    for(int i = 1; i < arrSize; i++)
    {
        if(arr[i - 1] < arr[i])
        {
            if(i == 1 || arr[i - 2] >= arr[i - 1])
            {
                nStart = i - 1;
            }
        }
        else if(arr[i - 1] > arr[i])
        {
            if(nStart != -1)
            {
                nMaxLen = max(nMaxLen, i - nStart + 1);
            }
        }
        else
        {
            nStart = -1;
        }
    }

    return nMaxLen;
}