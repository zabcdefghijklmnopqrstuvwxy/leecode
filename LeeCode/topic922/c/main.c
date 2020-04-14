
int* sortArrayByParityII(int* A, int ASize, int* returnSize){
    int nOdd[10240];
    int nEven[10240];
    int nOddIndex = 0;
    int nEventIndex = 0;
    int nIndex = 0;

    for(int i = 0; i < ASize; i++)
    {
        if(A[i] % 2 == 0)
        {
            nEven[nEventIndex++] = A[i];    
        }
        else
        {
            nOdd[nOddIndex++] = A[i];    
        }
    }

    nOddIndex = 0;
    nEventIndex = 0;

    while(nIndex < ASize)
    {
        A[nIndex++] = nEven[nEventIndex++];
        A[nIndex++] = nOdd[nOddIndex++];
    }

    *returnSize = ASize; 
    return A;
}