int peakIndexInMountainArray(int* A, int ASize){
    int i = 0;
    while(A[i] < A[i+1])
    {
        i++;
    }
    return i;
}