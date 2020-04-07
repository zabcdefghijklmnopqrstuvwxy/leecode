char * reverseOnlyLetters(char * S){
    if(strlen(S) <= 1)
    {
        return S;
    }
    
    int nStart = 0;
    int nEnd = strlen(S) - 1;
    char cTmp = 0;

    while(nStart < nEnd)
    {
        if(!((S[nStart] >= 'a' && S[nStart] <= 'z') || (S[nStart] >= 'A' && S[nStart] <= 'Z')))
        {
            nStart++;
            continue;
        }

        if(!((S[nEnd] >= 'a' && S[nEnd] <= 'z') || (S[nEnd] >= 'A' && S[nEnd] <= 'Z')))
        {
            nEnd--;
            continue;
        }

        cTmp = S[nStart];
        S[nStart] = S[nEnd];
        S[nEnd] = cTmp;

        nStart++;
        nEnd--; 
    }

    return S;
}