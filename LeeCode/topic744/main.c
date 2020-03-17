#include<stdio.h>

char nextGreatestLetter(char* letters, int lettersSize, char target){
    char n = target;
    if((strlen(letters) <= 0) || (NULL == letters))
    {
        return 'a';
    }

    char *hash = (char*)malloc(128);
    memset(hash,0,128);

    for(int i = 0; i < lettersSize; i++)
    {
        hash[letters[i]] = 1;
    }

    while(n < 'z')
    {
        if(hash[++n])
        {
            return n;
        }
    }

    return letters[0];
}
