#include<stdio.h>

bool checkRecord(char * s){
    int nLateCnt = 0;
    int nAbsentCnt = 0;
    int nLateMax = 0;

    if(NULL == s)
    {
        return false;
    }

    for(int i = 0; i < strlen(s); i++)
    {   
        if('A' == s[i])
        {
            nAbsentCnt++;
        }

        if('L' == s[i])
        {
            nLateCnt++;
            if(nLateCnt > nLateMax)
            {
                nLateMax = nLateCnt;
            }
        }
        else
        {
            nLateCnt = 0;
        }
    }

    if(nAbsentCnt > 1 || nLateMax > 2)
    {
        return false;
    }

    return true;
}