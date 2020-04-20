bool recur(char **board, int row, int col, int x, int y, char* word)
{
    bool res;
    if(*word == '\0')
    {
        return true;
    }

    if(x < 0 || x >= row || y < 0 || y >= col || *word != board[x][y])
    {
        return false;
    }
    board[x][y] = '\0';
    res = recur(board,row,col,x -1,y,word + 1) || recur(board,row,col,x+1,y,word + 1) || \
    recur(board,row,col,x,y+1,word + 1) || recur(board,row,col,x,y-1,word + 1);

    board[x][y] = *word;
    return res;
}

bool exist(char** board, int boardSize, int* boardColSize, char * word){
    int i = 0, j = 0;

    for(i = 0; i < boardSize; i++)
    {
        for(j = 0; j < boardColSize[0]; j++)
        {
            if(board[i][j] ==word[0] && recur(board,boardSize,boardColSize[0],i,j,word))
            {
                return true;
            }
        }
    }

    return false;
}