#include <cstdio>
typedef long long ll;
const int N = (int)1e5+1, mod = (int)1e9+7;
int n, m, f[N];
inline ll read()
{
    ll x = 0; char ch = getchar();
    for(; ch > '9' || ch <'0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}
inline int fib(int x)
{
    if(x == 1 || x == 0) return 1;
    return f[x]? f[x] : f[x] = (fib(x-1)+fib(x-2))%mod;
}
int main()
{
    n = read(); m = read();
    printf("%d",((fib(n)+fib(m)-1)%mod<<1)%mod);
    return 0;
}