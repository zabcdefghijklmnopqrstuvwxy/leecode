char * longestCommonPrefix(char ** strs, int strsSize){
    if(strsSize <= 0)
    {
        return "";
    }

    int i = 1, j = 0;
    for(i = 1; i < strsSize; i++)
    {
        j = 0;
        while(strs[i][j] != '\0' && strs[i][j] == strs[0][j])
        {
            j++;
        }
        strs[0][j] = '\0';
    }

    return strs[0];
}