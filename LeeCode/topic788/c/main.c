#include<stdio.h>
#include<stdlib.h>
int rotatedDigits(int N){
    int nCnt = 0;
    int i = 0;
    char *str = NULL;

    for(i = 1; i <= N; i++)
    {
        str = l64a(i);
        if(strstr(str,"3") || strstr(str,"4") || strstr(str,"7"))
        {
            continue;
        }

        if(strstr(str,"2") || strstr(str,"5") || strstr(str,"6") || strstr(str,"9"))
        {
            nCnt++;
        }
    }

    return nCnt;
}