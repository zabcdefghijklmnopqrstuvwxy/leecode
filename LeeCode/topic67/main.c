#include<stdio.h>

char * addBinary(char * a, char * b){
    int i = strlen(a);
    int j = strlen(b);
    
    int len = i > j? i: j;
    char* res = (char*)malloc(sizeof(char) * (len + 2));
    res[++len] = 0;
    
    char carry = '0';
    char pa, pb;
    while(len > 1 || carry == '1') {
        pa = i > 0? a[--i]: '0';
        pb = j > 0? b[--j]: '0';
        res[--len] = pa ^ pb ^ carry; // 当前位
        carry = (pa & carry) | (pb & carry) | (pa & pb); //进位
    }
    return res + len;
}

int main(void)
{
    char *a = "11";
    char *b = "1";
    char *ret = NULL;   
    
    ret = addBinary(a, b);

    printf("%s + %s = %s\n",a,b,ret);

    return 0;
}

