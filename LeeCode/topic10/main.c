#include<stdio.h>

int isMatch(char * s, char * p)
{
    if(*p == '\0')
    {
        if(*s == '\0')
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }

    if(*(p + 1) != '*')
    {
        if(*p == *s || (*p == '.' && *s != '\0'))
        {
            return isMatch(s+1,p+1);
        }
        else
        {
            return -1;
        }
    }
    else
    {
         while(*p == *s || (*p == '.' &&  *s != '\0'))
         {
            if(0 == isMatch(s,p+2))
            {
                return 0;
            }
            s++;
         }

         return isMatch(s,p+2);
    }

}

int main(void)
{
    char *test = "mississippi";
    char *patten = "miss*is*ip*.";
    int nRet = 0;

    nRet = isMatch(test,patten);
    printf("input is %s,patten is %s,result is %d\n",test,patten,nRet);

    return 0;
}

