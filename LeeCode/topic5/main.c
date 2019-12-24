#include<stdio.h>

int expandaroundcenter(char *s, int left, int right)
{
    int L = left, R = right;
    while (L >= 0 && R < strlen(s) && s[L] == s[R]) 
    {
        L--;
        R++;
    }
    return R - L - 1;
}

/**
* @brief 中心扩散法寻找回文中心位置，以此位置进行扩散寻找最长的回文串
*/

char * longestPalindrome(char * s){
    if (strlen(s) == 0) return "";
    int start = 0, end = 0;
    for (int i = 0; i < strlen(s); i++) 
    {
        int len1 = expandaroundcenter(s, i, i);
        int len2 = expandaroundcenter(s, i, i+1);
        int len = len1 > len2 ? len1 : len2;
        if (len > end - start) 
        {
            start = i - ((len - 1)>>1);
            end = i + (len>>1);
        }
    }
    char *p = malloc(sizeof(char) * (end - start + 2));
    strncpy(p, s + start, end - start + 1);
    p[end - start + 1] = '\0';
    return p;
}

int main(void)
{
    char *test = "c";
    char *pdata = NULL;

    pdata = longestPalindrome(test);

    printf("longest string is %s\n",pdata);

    return 0;
}
