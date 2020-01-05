#include<stdio.h>

#define MAX_SIZE 10002

typedef struct{
    int data[MAX_SIZE];
    int top;
}Stack;

Stack stk;

void init()
{
    memset(stk.data, 0, sizeof(int) * MAX_SIZE);
    stk.top = 0;
    return;
}

void push(int x) 
{
    if (stk.top > MAX_SIZE - 1) {
        return;
    }
    stk.data[stk.top] = x;
    stk.top++;
    return;
}

void pop()
{   
    if (stk.top == 0) {
        return;
    }

    stk.top--;
    return;
}

int top()
{
    return stk.data[stk.top - 1];
}

int empty()
{
    if (stk.top == 0) {
        return 1;
    }
    return 0;
}

char * removeKdigits(char * num, int k)
{
    char *res = NULL;
    int len = 0;
    int i;
    int cnt = 0;

    if (num == NULL || k == 0) {
        return num;
    }

    len = strlen(num);
    init();
    res = (char *)malloc(sizeof(char) * (len + 1));
    push(num[0] - '0');
    for (i = 1; i < len; i++) {
        while ((empty() == 0) && ((num[i] - '0') < top()) && (k > 0)) {
            pop();
            k--;
        }
        push(num[i] - '0');
    }

    while (k > 0) {
        pop();
        k--;
    }
   
    for (i = 0; i < stk.top; i++) {
        if ((stk.data[i] == 0) && (cnt == 0)) {
            continue;
        }
        res[cnt] = stk.data[i] + '0';
        cnt++;
    }
    if (cnt == 0) {
        res[0] = '0';
        cnt++;
    }
    res[cnt] = '\0';
    return res;
}
