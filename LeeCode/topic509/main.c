#include<stdio.h>


/**
* @brief 递归解法
*/
int fib(int N){
    if(0 == N || 1 == N)
    {
        return N;
    }

   return fib(N - 1) + fib(N - 2);

}

/**
* @brief 动态规划
*/
int fib(int N){
    if(0 == N || 1 == N)
    {
        return N;
    }

    int *dp = (int*)malloc((N+1)*sizeof(int));

    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= N; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[N];
}



/**
* @brief 矩阵求幂 [
*   [f(n)] 	 = [1 1][f(n-1)]
*   [f(n-1)]   [1 0][f(n-2)]
*/
void multiply(int A[][2], int B[][2]) {
	int x = A[0][0] * B[0][0] + A[0][1] * B[1][0];
	int y = A[0][0] * B[0][1] + A[0][1] * B[1][1];
	int z = A[1][0] * B[0][0] + A[1][1] * B[1][0];
	int w = A[1][0] * B[0][1] + A[1][1] * B[1][1];

	A[0][0] = x;
	A[0][1] = y;
	A[1][0] = z;
	A[1][1] = w;
}

void matrixPower(int A[][2], int N) {
	if (N <= 1) {
	  return;
	}
	matrixPower(A, N/2);
	multiply(A, A);

	int B[2][2] = {{1, 1}, {1, 0}};
	if (N%2 != 0) {
		multiply(A, B);
	}
}

int fib(int N)
{
	if (N <= 1) {
	  return N;
	}
	int A[2][2] = {{1, 1}, {1, 0}};
	matrixPower(A, N-1);

	return A[0][0];
}