#include<stdio.h>

/**
 * @brief 数学法 G(n) = B(n+1) XOR B(n)
 * 若二进制码表示为: B[N-1]B[N-2]...B[2]B[1]B[0];
 * 相应地, 则二进制格雷码表示为: G[N-1]G[N-2]...G[2]G[1]G[0].
 * 其中最高位保留: G[N-1] = B[N-1];
 * 其他各位: G[i] = B[i+1] xor B[i]. (i = 0, 1, 2, ..., n-2)
 * 总结：格雷码的值只需要在原来的二进制的基础上右移一位再加上原来的二进制值即可得到。
 */
int* grayCode(int n, int* returnSize){
    int nLen = pow(2,n);
    int *code = (int*)malloc(nLen*sizeof(int));
    int i = 0;

    code[0] = 0;
    for(i = 1; i < nLen; i++)
    {
        code[i] = (i >> 1) ^ i;
    }

    *returnSize = nLen;

    return code;
}