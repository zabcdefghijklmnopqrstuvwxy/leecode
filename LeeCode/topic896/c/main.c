bool isMonotonic(int* A, int ASize){
    int nUp = 0;
    int nDown = 0;
    
    for(int i = 0; i < ASize - 1; i++)
    {
        if(A[i] < A[i+1])
        {
            nUp = 1;
        }

        if(A[i] > A[i+1])
        {
            nDown = 1;
        }
    }

    return (nUp + nDown) < 2 ? true : false;
}