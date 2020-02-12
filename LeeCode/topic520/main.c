#include<stdio.h>

bool detectCapitalUse(char * word){
    int nLittle = 0, nBig = 0, nFirst = 0;

    for(int i = 0; i < strlen(word); i++)
    {
        if(word[i] >= 'A' && word[i] <= 'Z')
        {
            nBig++;

            if(0 == i)
            {
                nFirst++;
            }
        }

        if(word[i] >= 'a' && word[i] <= 'z')
        {
            nLittle++;
        }
    }

    if((nBig >= strlen(word)) || (nLittle >= strlen(word)) || (nFirst && (nLittle >= strlen(word) - 1)))
    {
        return true;
    }

    return false;
}