#include<stdio.h>

bool judgeSquareSum(int c){
    int l=0,r=sqrt(c);
    while(l<=r)
    {
        if((long)l*l+r*r==c) 
        {
            return true;
        }
        
        if((long)l*l+r*r<c) 
        {
            l++;
        }
        else 
        {
            r--;
        }
    }
    return false;
}