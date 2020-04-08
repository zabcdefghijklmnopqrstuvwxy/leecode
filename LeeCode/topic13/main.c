#include<stdio.h>

int romanToInt(char * s){
    if(strlen(s) <= 0)
    {
        return 0;
    }

    int cTable[128] = {0};
    int i = 0;
    int nSum = 0;

    cTable['I'] = 1;
    cTable['V'] = 5;
    cTable['X'] = 10;
    cTable['L'] = 50;
    cTable['C'] = 100;
    cTable['D'] = 500;
    cTable['M'] = 1000;

    for(i = 0; i < strlen(s); i++)
    {
        if(((i + 1) < strlen(s)) && (cTable[s[i]] < cTable[s[i+1]]))
        {
            nSum = nSum - cTable[s[i]];
        }
        else
        {
            nSum = nSum + cTable[s[i]];
        }
        
    }

    return nSum;
}


