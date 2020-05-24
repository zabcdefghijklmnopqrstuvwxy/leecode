char * addStrings(char * num1, char * num2){
     char* buf = (char*)malloc(sizeof(char) * 5101);
    int i = strlen(num1) - 1, j = strlen(num2) - 1, k = 0, carry = 0;
    
    while(i >= 0 || j >= 0 || carry != 0){
        if(i >= 0) carry += num1[i--] - '0';
        if(j >= 0) carry += num2[j--] - '0';
        buf[k++] = carry % 10 + '0';
        carry /= 10;
    }
    buf[k] = '\0';
    
    i = 0;
    j = k - 1;
    while(i < j){
        char c = buf[i];
        buf[i] = buf[j];
        buf[j] = c;
        i++;
        j--;
    }
    
    return buf;
}