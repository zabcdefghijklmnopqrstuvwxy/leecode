bool rotateString(char * A, char * B){
    if(strlen(A) != strlen(B))
    {
        return false;
    }

    char A2[300] = {0};
    strcat(A2,A);
    strcat(A2,A);

    return strstr(A2,B) ? true : false;
}