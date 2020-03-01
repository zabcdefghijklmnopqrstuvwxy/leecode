#include<stdio.h>

int compare(const void *a, const void *b) {
    char v1 = *(char *)a;
    char v2 = *(char *)b;
    return v2 - v1;
}

int nextGreaterElement(int n){
   char num[32] = {0};
    int idx = 0;
    int s = n;
    int min = -1;

    while (s > 0) {
        num[idx] = s % 10;
        s = s / 10;
        idx++;
    }

    long long r = 0;
    for (int i = 0; i < idx; i++) {
        for (int j = 0; j < i; j++) {
            if (num[i] < num[j]) {
                int temp = num[i];
                num[i] = num[j];
                num[j] = temp;
                //printf("%d %d\n", i, j);
                qsort(num, i, 1, compare);

                idx = idx - 1;
                while (idx >= 0) {
                    r = r * 10 + num[idx];
                    idx--;
                }
                if (r > INT_MAX) {
                    return -1;
                }
                return r;
            } 
        }
    }

    return -1;
}