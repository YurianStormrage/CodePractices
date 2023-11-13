#include <cstdio>
typedef long long ll;
const int N = (int)2e5+2;
int n, k1, k2, k3;
int map[N];
int f[N], g[N];
int ans;
inline ll read()
{
    ll x = 0; char ch = getchar();
    for(; ch > '9' || ch < '0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}
inline int Min(int a, int b) {return a<b?a:b;}
int main()
{
    k1 = read(); k2 = read(); k3 = read();
    n = k1+k2+k3;
    for(int i = 0; i < k1; ++i) read();
    for(int i = 0; i < k2; ++i) map[read()] = 1;
    for(int i = 0; i < k3; ++i) map[read()] = 2;
    for(int i = 1; i <= n; ++i)
    {
        f[i] = f[i-1]+(map[i]!=0);
        g[i] = Min(g[i-1],f[i-1])+(map[i]!=1);
    }
    ans = Min(f[n], g[n]);
    int tmp = 0;
    for(int i = n; i; --i)
    {
        tmp += map[i]!=2;
        ans = Min(Min(f[i-1],g[i-1])+tmp, ans);
    }
    printf("%d",ans);
    return 0;
}