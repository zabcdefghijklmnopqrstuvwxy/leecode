#include<stdio.h>

char * frequencySort(char * s){
    int check[128] = {0};
    int len = strlen(s);
    int i;
    char* ret = (char*)malloc(len+1);
    memset(ret,0,len+1);
    for(i = 0; i < len;i++)
    {
        check[s[i]]++;
    }

    int max = -1;
    int pos = -1;
    int now = 0;
    while(max != 0)
    {
        max = -1;
        pos = -1;
        for(i = 0; i < 128;i++) 
        {
            if(check[i] > max) 
            {
                max = check[i];
                pos = i;
            }
        }
        for(i = 0; i < max; i++)
        {
            ret[now++] = pos;
        }
        check[pos] = 0;
    }
    ret[now] = 0;
    return ret;
}
