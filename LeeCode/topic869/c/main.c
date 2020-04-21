bool reorderedPowerOf2(int N){
    int nN[10];
    int nR[10];
    int i = 0, j = 0;
    int nPow = 0;

    for(j = 0; j < 10; j++)
    {
        nN[j] = 0;
    }

    while(N)
    {
        nN[N % 10]++;
        N = N / 10;
    }

    for(i = 0; i < 31; i++)
    {
        for(j = 0; j < 10; j++)
        {
            nR[j] = 0;
        }

        nPow = 1 << i;

        while(nPow)
        {
            nR[nPow % 10]++;
            nPow = nPow / 10;
        }

        for(j = 0; j < 10; j++)
        {
            if(nN[j] != nR[j])
            {
                break;
            }
        }

        if(j >= 10)
        {
            return true;
        }
    }

    return false;
}