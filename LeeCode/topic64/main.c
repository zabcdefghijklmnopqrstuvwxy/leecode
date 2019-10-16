#include<stdio.h>

int minPathSum(int** grid, int gridSize, int* gridColSize)
{
    int nRowSize = gridSize / *gridColSize;    
    int i = 0,j = 0;

    for(i = 0; i < nRowSize; i++)
    {
        for(j = 0; j < *gridColSize; j++)
        {
            if(i == 0 && j == 0)
            {
                *((int*)grid + i + j) = *((int*)grid + i + j);
            }
            else if(i == 0 && j != 0)
            {
                *((int*)grid + i + j) =  *((int*)grid + i + j) + *((int*)grid + i + j - 1);   
            }
            else if(i != 0 && j == 0)
            {
                *((int*)grid + nRowSize*i + j) = *((int*)grid + nRowSize*i + j - 1);   
            }
            else
            {
                if(*((int*)grid + nRowSize*(i - 1) + j) > *((int*)grid + nRowSize*i + j - 1)) 
                {
                    *((int*)grid + nRowSize*i + j) =  *((int*)grid + nRowSize*i + j) + *((int*)grid + nRowSize*i + j -1);
                }
                else
                {
                    *((int*)grid + nRowSize*i + j) =  *((int*)grid + nRowSize*i + j) + *((int*)grid + nRowSize*(i - 1) + j);
                }
            }
        }
    }
    
    return *((int*)grid + nRowSize*(i - 1) + j - 1);
}

int main(void)
{
    int grid[3][3] = {{1, 3, 1},{1, 5, 1},{4, 2, 1}};
    int nMinPath = 0;
    int nColSize = 3;
    int i = 0;

    nMinPath = minPathSum(grid, sizeof(grid)/sizeof(int), &nColSize);

    for(i = 0; i < sizeof(grid)/sizeof(int); i++)
    {
        printf("%d\t",*(grid[0] + i));
        if(0 == (i + 1)%nColSize)
        {
            printf("\n");
        }
    }

    printf("\n");

    printf("min path sum is %d\n",nMinPath);

    return 0;
}
