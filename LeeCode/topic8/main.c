#include<stdio.h>
//#include"limit.h"

int myAtoi(char * str){
    long long num = 0;
    int nIndex = 0;
    int nMinusFlag = 0;
    int nOv = 0;
    if(NULL == str || strlen(str) <= 0)
    {
        return 0;
    }

    while(nIndex < strlen(str))
    {
    if(str[nIndex] != '-' && str[nIndex] != '+' && (str[nIndex] > '9' || str[nIndex] < '0'))
        {
            nIndex++;
            continue;
        }
        else
        {
            if(str[nIndex] <= '9' && str[nIndex] >= '0')
            {
                break;
            }

            if(str[nIndex] == '-' || str[nIndex] == '+')
            {
                nIndex++;
                continue;
            }
        }
    }

    if(nIndex >= strlen(str))
    {
        return 0;
    }
 
    if(nIndex > 0)
    {
        if(str[nIndex - 1] == '-')
        {
            nMinusFlag = 1;
        }
    }

    while(nIndex < strlen(str))
    {
    if(str[nIndex] != '-' && str[nIndex] != '+' && (str[nIndex] > '9' || str[nIndex] < '0'))
        {
            break;
        }

        num = num*10 + str[nIndex] - '0';
        nIndex++;
        if(num > INT_MAX)
        {
            nOv = 1;
            break;
        }

        if(num < INT_MIN)
        {
            nOv = -1;
            break;
        }
    }

    if(1 == nOv)
    {
        return INT_MAX;
    }

    if(-1 == nOv)
    {
        return INT_MIN;
    }

    if(nMinusFlag)
    {
        return -1*num;
    }

    return num;
}

int main(void)
{
    char *str = "word and 987";
    int nNum = 0;
    
    nNum = myAtoi(str);

    printf("atoi interget is %d\n",nNum);

    return 0;
}
