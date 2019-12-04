#include<stdio.h>

char findTheDifference(char * s, char * t){
    int nSum = 0;
    int i = 0;
    for(i = 0; i < strlen(t); i++)
    {
        nSum = nSum + t[i];
        if(i < strlen(s))
        {
            nSum = nSum - s[i];
        }
    }

    return nSum;
}