#include<stdio.h>

int strStr(char * haystack, char * needle)
{
    int n = strlen(haystack), m = strlen(needle);
    for(int i = 0; i < n - m + 1; i ++)
    {
        int j = 0;
        for(; j < m; j ++)
        {
            if(haystack[i + j] !=  needle[j])
            //为了保证在这个循环里haystack的索引也跟着needle索引一起向前推进，i的含义设置为起始点，i + j才是haystack的索引
                break;
        }
        if(j == m)
        {
            return i;
        }
    }
    return -1;
}

