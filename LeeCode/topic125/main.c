bool isPalindrome(char * s){
    int str_len = strlen(s);
    char *new_s = (char *)malloc( sizeof(char) * str_len);
    int j = 0;
    
    for (int i =0 ; i < str_len; i++){
        if ( s[i] >= 'A' && s[i] <= 'Z'){
            new_s[j++] =  tolower(s[i]);
        } else if ( s[i] >= 'a' && s[i] <= 'z'){
            new_s[j++] = s[i];
        } else if (s[i] >= '0' && s[i] <= '9'){
            new_s[j++] = s[i];
        } else{
            continue;
        }
    }
    
    for ( int i = 0; i < (j/2); i ++){
        if (new_s[i] != new_s[j-i-1]){
            return false;
        }
    }
    return true;
}