int findComplement(int num){
    long tmp = 1;
    while(num >= tmp)
    {
        tmp <<= 1;
    }

    return tmp - 1 - num;
}