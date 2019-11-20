#include<stdio.h>

/**
* @brief 第一种做法迭代交换首尾两个元素，第二种可以使用递归的方式
交换两个元素。
*/

void reverseString(char* s, int sSize){
    char tmp = 0;
    int i = 0;

    if(s == NULL || sSize < 1)
    {
        return;
    }

    for(i = 0; i < sSize / 2; i++)
    {
        tmp = s[i];
        s[i] = s[sSize - 1 - i];
        s[sSize - 1 - i] = tmp;
    }
}


#if 0
/**
* @brief 递归
*/
void reverseString(char* s, int sSize) 
{
        swap(0, sSize-1, s);
}
    
void swap(int start, int end, char* s) {
        if(start >= end){
            return;
        }
        
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        swap(start+1, end-1, s);
    }

#endif