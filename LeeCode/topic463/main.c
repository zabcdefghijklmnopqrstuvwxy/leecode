int islandPerimeter(int** grid, int gridSize, int* gridColSize){
    int nSum = 0;
    for (int i=0; i<gridSize; i++){
        for (int j=0; j<*gridColSize; j++){
            if (grid[i][j] == 1){
                if (i-1 < 0 || grid[i-1][j] == 0) nSum++;
                if (i+1 > gridSize-1 || grid[i+1][j] == 0) nSum++;
                if (j-1 < 0 || grid[i][j-1] == 0) nSum++;
                if (j+1 > *gridColSize-1 || grid[i][j+1] == 0) nSum++;
            }
        }
    }
    return nSum;
}