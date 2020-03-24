int numJewelsInStones(char * J, char * S){
    if(NULL == S)
    {
        return 0;
    }

    if(NULL == J && NULL != S)
    {
        return strlen(S);
    }

    int  hash[128] = {0};
    int  nCnt = 0;
    for(int i = 0; i < strlen(S); i++)
    {
        hash[S[i]]++;
    }

    for(int i = 0; i < strlen(J); i++)
    {
        nCnt = nCnt + hash[J[i]];
    }

    return nCnt;
}