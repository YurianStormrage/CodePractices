#include <cstdio>
#include <cstring>
typedef long long ll;
int n, m;
int a[11], f[11][11];
int ans;
inline int max(int a, int b) {return a > b ? a : b;}
inline ll rea()
{
    ll x = 0; char ch = getchar();
    for(; ch > '9' || ch < '0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}
int main()
{
    int q = rea();
    for(int Case = 1; Case <= q; ++Case)
    {
        m = rea(); n = rea();
        for(int i = 1; i <= m; ++i) a[i] = rea();
        memset(f, 0, sizeof(f));
        for(int i = 1; i <= m; ++i) f[1][a[i]] = 1;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                for(int k = max(a[j] - 2, 1); k <= a[j] + 2 && k <= 9; ++k)
                    f[i][a[j]] += f[i-1][k];
        ans = 0;
        for(int i = 1; i <= m; ++i) ans += f[n][a[i]];
        printf("Case %d: %d\n", Case, ans);
    }
    return 0;
}