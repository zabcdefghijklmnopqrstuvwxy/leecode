#include<stdio.h>

bool isUgly(int num){
    int nMod = num;

    if(num < 1)
    {
        return false;
    }

    while(1)
    {       
        if(nMod % 2 == 0)
        {
            nMod = nMod / 2; 
        }
        else if(nMod % 3 == 0)
        {
            nMod = nMod / 3; 
        }
        else if(nMod % 5 == 0)
        {
            nMod = nMod / 5; 
        }
        else
        {
            break;
        }  

        if(nMod == 1)
        {
            break;
        }     
    }

    if(nMod != 1)
    {
        return false; 
    }

    return true;
}
