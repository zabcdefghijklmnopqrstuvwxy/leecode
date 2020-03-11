#include<stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
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