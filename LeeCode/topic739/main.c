#include<stdio.h>

#if 0
/**
 * @brief 暴力解法，leecode测试超时
 */
int* dailyTemperatures(int* T, int TSize, int* returnSize){
    int *ret = (int*)malloc(sizeof(int) * 30000);
    *returnSize = TSize;
    for(int i = 0; i < TSize; i++) {
        int find = 0;
        for(int j = i+1; j < TSize; j++) {
            if (T[j] > T[i]) {
                find = j;
                break;
            }
        }
        ret[i] = (find - i) > 0 ? (find-i) : 0;
    }
    return ret;
}
#endif

#define STACK_LEN 30002

typedef struct tagStackNode{
    int temper;
    int index;
}StackNode;

void StackPopProc(StackNode *stack, int *top, int index, int T, int *retArray)
{
    while (*top >= 0 && stack[*top].temper < T) {
        retArray[stack[*top].index] = index - stack[*top].index;
        (*top)--;
    }

    stack[++(*top)].temper = T;
    stack[(*top)].index = index;
}

/**
 * @brief 栈单调减处理
 */
int* dailyTemperatures(int* T, int TSize, int* returnSize){
    int *retArray;
    StackNode stack[STACK_LEN];
    int top = -1;
    int i = 0;

    if (TSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    retArray = (int *)malloc(sizeof(int) * TSize);
    memset(retArray, 0, sizeof(int) * TSize);

    stack[++top].temper = T[i];
    stack[top].index = i;

    for (i = 1; i < TSize; i++) {
        if (T[i] <= stack[top].temper) {
            stack[++top].temper = T[i];
            stack[top].index = i;
        }else {
            StackPopProc(stack, &top, i, T[i], retArray);
        }
    }

    *returnSize = TSize;
    return retArray;
}
