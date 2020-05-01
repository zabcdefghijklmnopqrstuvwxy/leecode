char * toLowerCase(char * str){
    if(strlen(str) <= 0)
    {
        return str;
    }

    char *p = (char*)malloc(strlen(str) + 1);
    int i = 0;

    for(i = 0; i < strlen(str); i++)
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            p[i] = str[i] + 32;
        }
        else
        {
            p[i] = str[i];
        }
    }
    p[i] = '\0';
    
    return p;
}