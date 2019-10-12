#include<stdio.h>


#if 0
/**
动态规划，递归查找测试通过，但是leecode会超时
*/
int uniquePaths(int m, int n)
{
    if(m == 1 && n == 1)
    {
        return 1;
    }
    
    if(m < 1 || n < 1)
    {
        return 0;
    }

    return uniquePaths(m - 1,n) + uniquePaths(m, n - 1);
}
#endif

/*
杨辉三角问题
*/

int uniquePaths(int m, int n)
{
    int arr[m][n];
    int i,j;
    memset(arr,0,sizeof(arr));
    for(i=0;i<m;i++)
    {
        arr[i][0]=1;
    }
    for(i=0;i<n;i++)
    {
        arr[0][i]=1;
    }
    for(i=1;i<m;i++)
    {
        for(j=1;j<n;j++)
        {
            arr[i][j]=arr[i-1][j]+arr[i][j-1];
        }
    }
    return arr[m-1][n-1];
}

int main(void)
{
    int nRow = 7;
    int nCol = 3;
    int nRet = 0;

    nRet = uniquePaths(nRow, nCol);

    printf("col is %d,row is %d,total path is %d\n",nCol,nRow,nRet);

    return 0;
}
