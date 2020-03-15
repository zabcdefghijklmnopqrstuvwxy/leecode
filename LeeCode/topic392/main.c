#include<stdio.h>

char findTheDifference(char * s, char * t){
    while (*s && *t) 
    {
        if (*s == *t) 
        {
            s++;
        }
        t++;
    }
    
    if (*s == '\0')
    {
        return true;
    } 
    else 
    {
        return false;
    }
}