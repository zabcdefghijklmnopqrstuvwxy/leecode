#include<stdio.h>


int lengthOfLastWord(char * s)
{
    int length=strlen(s);//得到数组长度
    int i,count=0;
    while(length>0 && s[length-1]==' ')//去掉空格部分
    length--;
    for(i=length-1;i>-1;i--)
    {
        if(s[i]!=' ')
        count++;
        else
        return count;
    }
    return count;
}