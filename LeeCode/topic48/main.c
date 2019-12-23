#include<stdio.h>

/**
* @brief 先矩阵转置然后镜像即可
*/
void rotate(int** matrix, int matrixSize, int* matrixColSize)
{
    int n = matrixSize;
    int tmp = 0;
    *matrixColSize = n;

     for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        int tmp = matrix[j][i];
        matrix[j][i] = matrix[i][j];
        matrix[i][j] = tmp;
      }
    }
    // reverse each row
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n / 2; j++) {
        int tmp = matrix[i][j];
        matrix[i][j] = matrix[i][n - j - 1];
        matrix[i][n - j - 1] = tmp;
      }
    }

}

