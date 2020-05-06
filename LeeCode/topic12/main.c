char * intToRoman(int num){
    char* c[4][10] = {
            {"","I","II","III","IV","V","VI","VII","VIII","IX"},
            {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
            {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
            {"","M","MM","MMM"}
        };

    char *rome = (char*)malloc(64);
    int i = 0;

    for(i = 0; i < 64; i++)
    {
        rome[i] = 0;
    }

    strcat(rome,c[3][num/1000]);
    strcat(rome,c[2][num/100%10]);
    strcat(rome,c[1][num/10%10]);
    strcat(rome,c[0][num%10]);  
   
    return rome;
}