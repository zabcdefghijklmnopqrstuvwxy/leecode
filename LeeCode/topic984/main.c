char * strWithout3a3b(int A, int B){
    char *arr = (char*)malloc(200);
    int nFlag = A > B ? 1 : 0;
    int nIndex = 0;

    while(A > 0 || B > 0)
    {
        if(nFlag)
        {
            if(A > 0)
            {
                A--;
                arr[nIndex++] = 'a';
            }

            if(A > B)
            {
                A--;
                arr[nIndex++] = 'a';
            }

            if(B > 0)
            {
                B--;
                arr[nIndex++] = 'b';
            }
        }
        else
        {
            if(B > 0)
            {
                B--;
                arr[nIndex++] = 'b';
            }

            if(B > A)
            {
                B--;
                arr[nIndex++] = 'b';
            }

            if(A > 0)
            {
                A--;
                arr[nIndex++] = 'a';
            }
        }
    }

    arr[nIndex] = '\0';
    
    return arr;
}