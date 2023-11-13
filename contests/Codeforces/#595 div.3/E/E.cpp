#include <cstdio>
#define Min(a, b) ((a)<(b)? (a):(b))
typedef long long ll;
const int N = (int)2e5+2;
int n, c;
int a[N];
int f[N], g[N];
inline ll read()
{
    ll x = 0; char ch = getchar();
    for(; ch > '9' || ch <'0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}
int main()
{
    n = read(); c = read();
    for(int i = 1; i < n; ++i) a[i] = read();
    g[1] = c;
    for(int i = 1; i < n; ++i)
    {
        int b = read();
        f[i+1] = Min(f[i]+a[i], g[i]+a[i]);
        g[i+1] = Min(f[i]+c+b, g[i]+b);
    } 
    for(int i = 1; i <= n; ++i) printf("%d ",Min(f[i], g[i]));
    return 0;
}