int gcd( int m, int n)
{
    if(m%n==0)
    {
        return n;
    }
    else
    {
        return gcd(n, m%n);
    }
}


/*
* @brief 想象一下镜面没有上面，镜子是无限延伸的，题目中说明了一定会投入到接收器中，所以
* 投入到西面就一定是2号，投入到东面则一定是0和1号，此时判断是不是p对最小公倍数求余是不是
* 奇数还是偶数就可以判断是0还是1号
*/
int mirrorReflection(int p, int q){
    int nGcd = gcd(p,q);
    int nLcm = p*q/nGcd;
    int k = nLcm / q;
    int m = nLcm / p;

    return (!(k&1)) ? 2 : (m&1);
}