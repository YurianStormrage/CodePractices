#include <cstdio>
const int mod = (int)1e9+7;
int n, m;
inline int read()
{
    int x = 0; char ch = getchar();
    for(; ch > '9' || ch < '0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}
int main()
{
    n = read(); m = read();
    int ans = 1, k = 2;
    while(m)
    {
        if(m&1) ans = (long long)ans*k%mod;
        k = (long long)k*k%mod;
        m >>= 1;
    }
    k = ans - 1; ans = 1;
    while(n)
    {
        if(n&1) ans = (long long)ans*k%mod;
        k = (long long)k*k%mod;
        n >>= 1;
    }
    printf("%d",ans);
    return 0;
}