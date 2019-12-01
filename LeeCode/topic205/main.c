#include<stdio.h>

/**
* 使用哈希表进行映射，两两映射确保一对一
*/
bool isIsomorphic(char * s, char * t){
    char *ascii = (char*)malloc(128);
    int i = 0;
    memset(ascii,0,128);
    if((s == NULL) || (t == NULL) || (strlen(s) != strlen(t)))
    {
        free(ascii);
        return false;
    }

    for(i = 0; i < strlen(s); i++)
    {
        if(ascii[s[i]] == 0)
        {
            ascii[s[i]] = t[i];
        }
        else
        {
            if(ascii[s[i]] != t[i])
            {
                break;
            }
        }
    }

    if(i < strlen(s))
    {
        free(ascii);
        return false;
    }

    memset(ascii,0,128);
    for(i = 0; i < strlen(t); i++)
    {
        if(ascii[t[i]] == 0)
        {
            ascii[t[i]] = s[i];
        }
        else
        {
            if(ascii[t[i]] != s[i])
            {
                break;
            }
        }
    }

    if(i < strlen(s))
    {
        free(ascii);
        return false;
    }

    free(ascii);

    return true;
}