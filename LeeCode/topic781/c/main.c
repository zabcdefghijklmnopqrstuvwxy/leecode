int numRabbits(int* answers, int answersSize){
    int nHash[1000];
    int i = 0;
    int nSum = 0;

    for(i = 0; i < 1000; i++)
    {
        nHash[i] = 0;
    }

    for(i = 0; i < answersSize; i++)
    {
        nHash[answers[i]]++;
    }

    for(i = 0; i < answersSize; i++)
    {
        if(nHash[i])
        {
            nSum = nSum + (nHash[i] + i)/(i + 1)*(i + 1);
        }
    }

    return nSum;
}