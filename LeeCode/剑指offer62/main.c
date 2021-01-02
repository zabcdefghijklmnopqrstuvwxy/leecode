int lastRemaining(int n, int m){
    int nRes = 0;
    for(int i = 2; i <= n; i++)
    {
        nRes = (nRes + m) % i;
    }
    return nRes;
}